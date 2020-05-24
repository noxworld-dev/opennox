#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "common/system/settings.h"
#include "client/io/console.h"
#include "client/draw/animdraw.h"
#include "client/draw/canidraw.h"
#include "client/gui/chaticon.h"
#include "client/gui/guimsg.h"
#include "client/shell/wolapi/locale.h"
#include "client/shell/wolapi/wolchat.h"
#include "client/shell/wolapi/wollogin.h"
#include "client/shell/wolapi/woldlgs.h"

#include "proto.h"

extern nox_memfile* nox_loaded_thing_bin;

extern int default_win_width;
extern int default_win_height;
extern int default_win_depth;

extern int nox_win_width;
extern int nox_win_height;

extern int nox_win_width_1;
extern int nox_win_height_1;
extern int nox_win_depth_1;

extern int nox_win_width_2;
extern int nox_win_height_2;
extern int nox_win_depth_2;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;
extern int nox_backbuffer_width32;

extern nox_video_mode nox_video_modes[];
extern int nox_video_modes_cnt;

extern nox_parse_thing_draw_funcs_t nox_parse_thing_draw_funcs[];
extern int nox_parse_thing_draw_funcs_cnt;

int (*nox_draw_unk1)(void) = 0;

void (*mainloop_enter)(void*);
void* mainloop_enter_args;
void (*mainloop_exit)();

void map_download_start();

nox_thing* nox_things_head = 0;
nox_thing** nox_things_array = 0;
int nox_things_count = 0;

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;
obj_5D4594_3799572_t obj_5D4594_3799660 = {0};
obj_5D4594_3799572_t obj_5D4594_3800716 = {0};

//----- (0043B510) --------------------------------------------------------
char* sub_43B510()
{
    __int16 v0; // ax
    char* result; // eax
    char* v2; // edi
    unsigned __int8 v3; // cl
    bool v4; // zf
    __int16 v5; // cx
    int v6; // [esp+0h] [ebp-54h]
    char v7[80]; // [esp+4h] [ebp-50h]

    *(_DWORD*)& byte_5D4594[815132] = 0;
    sub_40A4D0(5);
    sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    v6 = *(_DWORD*)& byte_5D4594[814916];
    if (*(_DWORD*)& byte_587000[87404] == 1)
    {
        v0 = *(_WORD*)& byte_5D4594[814916] - *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87528];
        HIWORD(v6) -= *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87530];
        LOWORD(v6) = v0;
    }
    strcpy(v7, sub_49FF40((__int16*)& v6));
    result = strchr(v7, 46);
    if (!result)
    {
        sub_409B50(v7);
        v2 = &v7[strlen(v7) + 1];
        v3 = byte_587000[90860];
        *(_DWORD*)--v2 = *(_DWORD*)& byte_587000[90856];
        v4 = (*(_DWORD*)& byte_5D4594[2650636] & 0x600000) == 0;
        v2[4] = v3;
        if (v4)
            sub_409D70(v7);
        sub_40A540(55280);
        sub_40A4D0(128);
        result = sub_4165D0(0);
        v5 = *((_WORD*)result + 26) & 0x280F;
        LOBYTE(v5) = result[52] & 0xF | 0x80;
        *((_WORD*)result + 26) = v5;
    }
    return result;
}
// 43B510: using guessed type char var_50[80];

//----- (0043B630) --------------------------------------------------------
_DWORD* sub_43B630()
{
    wchar_t* v0; // eax

    sub_46C6E0(*(int*)& byte_5D4594[815000]);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[90904], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1284);
    return sub_449A10(*(int*)& byte_5D4594[814980], 0, (int)v0, 34, 0, 0);
}

//----- (0043B670) --------------------------------------------------------
_DWORD* sub_43B670()
{
    char* v0; // esi

    v0 = sub_416640();
    if (*(_DWORD*)& byte_5D4594[815048])
    {
        sub_44A400();
        sub_43B510();
        sub_43A9D0();
        sub_4A24A0();
        sub_501AC0(*(_DWORD*)(v0 + 74));
    }
    else
    {
        sub_43B630();
        sub_40D350(*(_DWORD*)(*(_DWORD*)& byte_5D4594[814624] + 32));
    }
    return sub_49FF20();
}

//----- (0043B6D0) --------------------------------------------------------
int sub_43B6D0()
{
    return *(_DWORD*)& byte_5D4594[815044];
}

//----- (0043B6E0) --------------------------------------------------------
void sub_43B6E0()
{
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]
    if (*(_DWORD*)& byte_5D4594[814980])
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[90960], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[91008], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
        sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
        sub_44A360(1);
        *(_DWORD*)& byte_5D4594[815096] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[815096] = 1;
    }
}

//----- (0043B750) --------------------------------------------------------
void sub_43B750()
{
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]

    if (*(_DWORD*)& byte_5D4594[814980])
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[91064], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[91112], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
        sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
        sub_44A360(1);
        *(_DWORD*)& byte_5D4594[815100] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[815100] = 1;
    }
}

//----- (0043B7C0) --------------------------------------------------------
_DWORD* __cdecl sub_43B7C0(int a1)
{
    int v1; // eax
    __int16 v2; // cx
    _DWORD* v3; // eax
    int v4; // eax
    _DWORD* result; // eax
    wchar_t* v6; // eax
    int v7; // eax
    char v8; // al
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // [esp-14h] [ebp-208h]
    WCHAR WideCharStr[64]; // [esp+8h] [ebp-1ECh]
    char v13[32]; // [esp+88h] [ebp-16Ch]
    char v14[332]; // [esp+A8h] [ebp-14Ch]

    if (*(_DWORD*)& byte_587000[87408])
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16397, (int)& byte_587000[91164], 4);
        strncpy(v14, (const char*)(a1 + 120), 0xFu);
        v14[15] = 0;
        if (!memcmp(v14, &byte_5D4594[815120], 1u))
            sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v14);
        nox_swprintf(WideCharStr, L"%S", v14);
        sub_43BC10(WideCharStr, 0x64u);
        nox_window_call_field_94(*(int*)& byte_5D4594[815016], 16397, (int)WideCharStr, 4);
        nox_swprintf(
                WideCharStr,
                L"%d/%d",
                *(unsigned __int8*)(a1 + 103),
                *(unsigned __int8*)(a1 + 104));
        nox_window_call_field_94(*(int*)& byte_5D4594[815020], 16397, (int)WideCharStr, 4);
        v6 = sub_43BCB0(*(_WORD*)(a1 + 163));
        if (*(_BYTE*)(a1 + 164) & 0x10)
        {
            nox_swprintf(
                    (wchar_t*)& byte_5D4594[814772],
                    L"%s %d",
                    v6,
                    *(unsigned __int16*)(a1 + 165));
            nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16397, (int)& byte_5D4594[814772], 4);
        }
        else
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16397, (int)v6, 4);
        }
        v7 = *(_DWORD*)(a1 + 96);
        if (v7 == 9999)
            nox_swprintf(WideCharStr, L"--");
        else
            _itow(v7, WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16397, (int)WideCharStr, 4);
        v8 = *(_BYTE*)(a1 + 100);
        WideCharStr[0] = 0;
        if (v8 & 0x20)
        {
            v9 = loadString_sub_40F1D0((char*)& byte_587000[91248], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3486);
            nox_wcscat(WideCharStr, v9);
        }
        if (*(_BYTE*)(a1 + 100) & 0x10)
        {
            if (WideCharStr[0])
                nox_wcscat(WideCharStr, L"+");
            v10 = loadString_sub_40F1D0((char*)& byte_587000[91316], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3494);
            nox_wcscat(WideCharStr, v10);
        }
        if (!WideCharStr[0])
        {
            if (*(_BYTE*)(a1 + 103) < *(_BYTE*)(a1 + 104))
                v11 = loadString_sub_40F1D0((char*)& byte_587000[91424], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3505);
            else
                v11 = loadString_sub_40F1D0((char*)& byte_587000[91376], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3501);
            nox_wcscat(WideCharStr, v11);
        }
        result = (_DWORD*)nox_window_call_field_94(*(int*)& byte_5D4594[815032], 16397, (int)WideCharStr, 4);
    }
    else
    {
        memset(v14, 0, sizeof(v14));
        *(_DWORD*)& v14[8] = 257;
        *(_DWORD*)& v14[16] = *(_DWORD*)& byte_5D4594[814980];
        if (*(int*)& byte_587000[87412] == -1)
        {
            v1 = sub_437860(*(__int16*)(a1 + 44), *(__int16*)(a1 + 46));
            v2 = *(_WORD*)& byte_587000[8 * v1 + 87528];
            v1 += 10054;
            *(_WORD*)(a1 + 44) -= v2;
            *(_WORD*)(a1 + 46) -= *(_WORD*)& byte_587000[8 * v1 + 7098];
            *(_WORD*)(a1 + 44) >>= 1;
            *(_WORD*)(a1 + 46) >>= 1;
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814988], v1);
            v4 = sub_4A91A0((int)v3, 1185, *(__int16*)(a1 + 44) - 5, *(__int16*)(a1 + 46) - 5, 10, 10, v14);
        }
        else
        {
            *(_WORD*)(a1 + 44) -= *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87528];
            *(_WORD*)(a1 + 46) -= *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87530];
            v4 = sub_4A91A0(
                    *(int*)& byte_5D4594[814984],
                    1192,
                    *(__int16*)(a1 + 44) - 10,
                    *(__int16*)(a1 + 46) - 10,
                    20,
                    20,
                    v14);
        }
        *(_DWORD*)(a1 + 28) = v4;
        sub_437320(a1);
        if (*(_BYTE*)(a1 + 120))
        {
            strncpy(v13, (const char*)(a1 + 120), 0xFu);
            v13[15] = 0;
        }
        else
        {
            sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v13);
        }
        if (*(_DWORD*)(a1 + 96) == 9999)
            nox_swprintf(WideCharStr, L"%S -- ms", v13);
        else
            nox_swprintf(WideCharStr, L"%S %dms", v13, *(_DWORD*)(a1 + 96));
        sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 28) + 36), WideCharStr);
        sub_46B2C0(*(_DWORD*)(a1 + 28), sub_439E70);
        result = *(_DWORD * *)(a1 + 28);
        *result = *(_DWORD*)(a1 + 36) + 10070;
    }
    return result;
}

//----- (0043BC10) --------------------------------------------------------
unsigned __int16* __cdecl sub_43BC10(wchar_t* a1, unsigned __int8 a2)
{
    unsigned __int16* v2; // esi
    size_t v3; // edi
    int v4; // ebx
    unsigned __int16* v5; // edi

    v2 = a1;
    v3 = nox_wcslen(a1);
    sub_43F840(0, v2, (int*)& a1, 0, 0);
    v4 = a2;
    if ((int)(a1 + 5) > a2)
    {
        v5 = &v2[v3];
        do
        {
            *v5 = 0;
            --v5;
            sub_43F840(0, v2, (int*)& a1, 0, 0);
        } while ((int)(a1 + 5) > v4);
    }
    return v2;
}

//----- (0043BC80) --------------------------------------------------------
int __cdecl sub_43BC80(int a1, unsigned __int16 a2, char* a3)
{
    return nox_sprintf(a3, "%s:%d", a1, a2);
}

//----- (0043BCB0) --------------------------------------------------------
wchar_t* __cdecl sub_43BCB0(__int16 a1)
{
    if (a1 & 0x1000)
        return loadString_sub_40F1D0((char*)& byte_587000[91480], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3534);
    if (a1 & 0x20)
        return loadString_sub_40F1D0((char*)& byte_587000[91528], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3541);
    if (a1 & 0x400)
        return loadString_sub_40F1D0((char*)& byte_587000[91572], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3545);
    if (a1 & 0x10)
        return loadString_sub_40F1D0((char*)& byte_587000[91624], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3550);
    if (a1 & 0x40)
        return loadString_sub_40F1D0((char*)& byte_587000[91672], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3555);
    if ((a1 & 0x80u) == 0)
        return loadString_sub_40F1D0((char*)& byte_587000[91772], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3563);
    return loadString_sub_40F1D0((char*)& byte_587000[91724], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3559);
}

//----- (0043BD90) --------------------------------------------------------
int __cdecl sub_43BD90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[815092] |= a1;
    return result;
}

//----- (0043BDB0) --------------------------------------------------------
int sub_43BDB0()
{
    return *(_DWORD*)& byte_5D4594[815092];
}

//----- (0043BDC0) --------------------------------------------------------
void sub_43BDC0()
{
    --byte_5D4594[815208];
}

//----- (0043BDD0) --------------------------------------------------------
int __cdecl sub_43BDD0(int a1)
{
    int result; // eax

    result = a1;
    if (*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] != a1)
    {
        ++byte_5D4594[815208];
        *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] = a1;
    }
    return result;
}

//----- (0043BE10) --------------------------------------------------------
int sub_43BE10()
{
    return *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140];
}

//----- (0043BE30) --------------------------------------------------------
int sub_43BE30()
{
    return *(_DWORD*)& byte_5D4594[815204];
}

//----- (0043BE40) --------------------------------------------------------
int __cdecl sub_43BE40(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[815204] = a1;
    return result;
}

//----- (0043BE50) --------------------------------------------------------
int sub_43BE50_get_video_mode_id()
{
    for (int i = 0; i < nox_video_modes_cnt; i++)
    {
        nox_video_mode* m = &nox_video_modes[i];
        if (m->width == nox_win_width_1)
            return m->id;
    }
    return nox_video_modes_cnt;
}

//----- (0043BE80) --------------------------------------------------------
nox_video_mode* __cdecl sub_43BE80_video_mode_by_id(int a1)
{
    for (int i = 0; i < nox_video_modes_cnt; i++)
    {
        nox_video_mode* m = &nox_video_modes[i];
        if (m->id == a1)
            return m;
    }
    return 0;
}

//----- (0043BEB0) --------------------------------------------------------
void __cdecl sub_43BEB0_get_video_mode(int* w, int* h, int* d)
{
    if (w)
        * w = nox_win_width_1;
    if (h)
        * h = nox_win_height_1;
    if (d)
        * d = nox_win_depth_1;
}

//----- (0043BEF0) --------------------------------------------------------
void __cdecl sub_43BEF0_set_video_mode(int w, int h, int d)
{
    d = 16; // 8 bit not supported
    nox_win_width_1 = w;
    nox_win_height_1 = h;
    nox_win_depth_1 = d;

    change_windowed_fullscreen();
}

//----- (0043BF10) --------------------------------------------------------
int __cdecl sub_43BF10(int a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // ebx
    int result; // eax

    if (a1 == 1)
    {
        v1 = nox_win_width_2;
        v2 = nox_win_height_2;
        v3 = nox_win_depth_2;
    }
    else
    {
        v1 = nox_win_width_1;
        v2 = nox_win_height_1;
        v3 = nox_win_depth_1;
    }
    sub_430BE0(v1, v2, v3);
    *(_DWORD*)& byte_5D4594[805872] = 0;
    if (v1 == nox_backbuffer_width && v2 == nox_backbuffer_height && v3 == nox_backbuffer_depth)
    {
        return 1;
    }
    sub_48BE50(1);
    if (v3 == nox_backbuffer_depth || (result = sub_42F370(*(int*)& byte_5D4594[3804680])) != 0)
    {
        result = sub_430BA0();
        if (result)
        {
            sub_4A96C0("default.pal");
            sub_461520();
            sub_430A70_set_mouse_bounds(0, v1 - 1, 0, v2 - 1);
            sub_48BE50(0);
            return 1;
        }
    }
    return result;
}

//----- (0043BFE0) --------------------------------------------------------
int sub_43BFE0()
{
    int result; // eax

    sub_43DDF0(sub_43C020);
    nox_set_draw_unk1(0);
    if (*(_DWORD*)& byte_587000[91840])
    {
        *(_DWORD*)& byte_587000[91840] = 0;
        *(_DWORD*)& byte_5D4594[815132] = 1;
        return 1;
    }
    result = sub_43C0A0();
    if (!result)
        return 0;

    *(_DWORD*)& byte_5D4594[815132] = 1;
    return 1;
}

//----- (0043C020) --------------------------------------------------------
int sub_43C020()
{
    ++* (_DWORD*)& byte_5D4594[2598000];
    if (*(_DWORD*)& byte_5D4594[815132])
        return 1;
    sub_434350(*(int*)& byte_5D4594[2650656]);
    sub_440900();
    return 0;
}

//----- (0043C060) --------------------------------------------------------
BOOL sub_43C060()
{
    sub_4A96C0((char*)& byte_587000[91856]);
    sub_4AA1F0();
    sub_4A2210();
    sub_477610(0);
    sub_48B3E0(1);
    sub_44E040();
    sub_43E8C0(0);
    return sub_4A9C80() != 0;
}

//----- (0043C0A0) --------------------------------------------------------
int sub_43C0A0()
{
    unsigned int v0; // eax
    int result; // eax
    int v2; // eax

    if (!byte_5D4594[815208])
        return 1;
    v0 = *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140];
    if (v0 > 0x258)
    {
        if (v0 > 0x76C)
        {
            if (v0 != 1915)
            {
                if (v0 != 10000)
                    return 1;
                if (sub_43AF70() == 1 && !sub_40E0B0())
                {
                    sub_41E300(9);
                    sub_41F4B0();
                    sub_41EC30();
                    sub_446490(0);
                    sub_44B000();
                    sub_44A400();
                    return 1;
                }
            }
            result = sub_4379F0();
            if (!result)
                return result;
            return 1;
        }
        if (v0 == 1900)
        {
            result = sub_447620_wol_chat();
            if (!result)
                return result;
            return 1;
        }
        if (v0 == 700)
        {
            result = sub_4A5D00();
            if (!result)
                return result;
            return 1;
        }
        if (v0 != 1700)
            return 1;
        result = sub_44A560_wol_login();
        if (result)
            return 1;
    }
    else
    {
        if (v0 == 600)
        {
            result = sub_4A4840();
            if (!result)
                return result;
            return 1;
        }
        if (v0 <= 0x12C)
        {
            switch (v0)
            {
                case 0x12Cu:
                    result = sub_4AA6B0();
                    if (!result)
                        return result;
                    break;
                case 0xAu:
                    result = sub_4AB1F0();
                    if (!result)
                        return result;
                    break;
                case 0x64u:
                    result = sub_4A1C00();
                    if (!result)
                        return result;
                    break;
            }
            return 1;
        }
        v2 = v0 - 400;
        if (!v2)
        {
            result = sub_4AA270();
            if (!result)
                return result;
            return 1;
        }
        if (v2 != 100)
            return 1;
        sub_4A7A70(1);
        result = sub_4A4DB0();
        if (result)
            return 1;
    }
    return result;
}

//----- (0043C1E0) --------------------------------------------------------
void sub_43C1E0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi

    if (byte_5D4594[815208])
    {
        v0 = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = v0;
        if (v0)
        {
            ((int (*)(void))v0[12])();
            v1[13] = sub_43C0A0;
            sub_43BDC0();
        }
    }
}

//----- (0043C220) --------------------------------------------------------
_DWORD* sub_43C220()
{
    _DWORD* result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD * *)& byte_5D4594[815208];
    if (byte_5D4594[815208])
    {
        result = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = result;
        if (result)
        {
            result = (_DWORD*)((int (*)(void))result[12])();
            v1[13] = sub_4AA6B0;
        }
    }
    return result;
}

//----- (0043C260) --------------------------------------------------------
int sub_43C260()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[815208];
    if (byte_5D4594[815208])
    {
        result = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = result;
        if (result)
        {
            if (*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] == 1700)
            {
                result = sub_44A560_wol_login();
            }
            else
            {
                result = (*(int (**)(void))(result + 48))();
                *(_DWORD*)(v1 + 52) = sub_44A560_wol_login;
            }
        }
        for (; *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] != 1700; result = byte_5D4594[815208])
            sub_43BDC0();
    }
    return result;
}

//----- (0043C2F0) --------------------------------------------------------
int sub_43C2F0()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[815208];
    if (byte_5D4594[815208])
    {
        result = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = result;
        if (result)
        {
            if (*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] == 100)
            {
                result = sub_4A1C00();
            }
            else
            {
                result = (*(int (**)(void))(result + 48))();
                *(_DWORD*)(v1 + 52) = sub_4A1C00;
            }
        }
        for (; *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] != 100; result = byte_5D4594[815208])
            sub_43BDC0();
    }
    return result;
}

//----- (0043C380) --------------------------------------------------------
void sub_43C380()
{
    int v0; // esi
    int v1; // edi
    char v2; // bl
    int v3; // eax
    int v4; // ecx
    int v5; // edx
    int v6; // edx
    void (*v7)(void); // eax
    int v8; // eax
    int v9; // ecx
    int v10; // edx
    int v11; // edx
    int (*v12)(void); // eax
    int v13; // [esp+4h] [ebp-8h]
    int v14; // [esp+8h] [ebp-4h]

    v0 = *(_DWORD*)& byte_5D4594[815212];
    if (*(_DWORD*)& byte_5D4594[815212])
    {
        while (1)
        {
            v1 = *(_DWORD*)(v0 + 40);
            v2 = 0;
            if (*(_BYTE*)(v0 + 64) == 2)
            {
                sub_46AA20(*(_DWORD*)(v0 + 4), &v13, &v14);
                v8 = *(_DWORD*)(v0 + 24) + v13;
                v13 += *(_DWORD*)(v0 + 24);
                v9 = *(_DWORD*)(v0 + 28) + v14;
                v14 += *(_DWORD*)(v0 + 28);
                v10 = *(_DWORD*)(v0 + 8);
                if ((int) * (_DWORD*)(v0 + 24) >= 0)
                {
                    if (v8 >= v10) {
                        v8 = *(_DWORD*)(v0 + 8);
                        v2 = 1;
                        v13 = *(_DWORD*)(v0 + 8);
                    }
                }
                else if (v8 <= v10)
                {
                    v8 = *(_DWORD*)(v0 + 8);
                    v2 = 1;
                    v13 = *(_DWORD*)(v0 + 8);
                }
                v11 = *(_DWORD*)(v0 + 12);
                if ((int) * (_DWORD*)(v0 + 28) >= 0)
                {
                    if (v9 >= v11) {
                        v9 = *(_DWORD*)(v0 + 12);
                        ++v2;
                        v14 = *(_DWORD*)(v0 + 12);
                    }
                }
                else if (v9 <= v11)
                {
                    v9 = *(_DWORD*)(v0 + 12);
                    ++v2;
                    v14 = *(_DWORD*)(v0 + 12);
                }
                sub_46A9B0(*(_DWORD * *)(v0 + 4), v8, v9);
                if (v2 == 2)
                {
                    *(_BYTE*)(v0 + 64) = 1;
                    sub_43BE40(1);
                    v12 = *(int (**)(void))(v0 + 56);
                    if (v12)
                        v12();
                }
                goto LABEL_31;
            }
            if (*(_BYTE*)(v0 + 64) == 3)
                break;
            LABEL_31:
            v0 = v1;
            if (!v1)
                return;
        }
        sub_46AA20(*(_DWORD*)(v0 + 4), &v13, &v14);
        v3 = *(_DWORD*)(v0 + 32) + v13;
        v13 += *(_DWORD*)(v0 + 32);
        v4 = *(_DWORD*)(v0 + 36) + v14;
        v14 += *(_DWORD*)(v0 + 36);
        v5 = *(_DWORD*)(v0 + 16);
        if ((int) * (_DWORD*)(v0 + 32) >= 0)
        {
            if (v3 < v5)
                goto LABEL_9;
        }
        else if (v3 > v5)
        {
            goto LABEL_9;
        }
        v3 = *(_DWORD*)(v0 + 16);
        v2 = 1;
        v13 = *(_DWORD*)(v0 + 16);
        LABEL_9:
        v6 = *(_DWORD*)(v0 + 20);
        if ((int) * (_DWORD*)(v0 + 36) >= 0)
        {
            if (v4 < v6)
                goto LABEL_14;
        }
        else if (v4 > v6)
        {
            goto LABEL_14;
        }
        v4 = *(_DWORD*)(v0 + 20);
        ++v2;
        v14 = *(_DWORD*)(v0 + 20);
        LABEL_14:
        sub_46A9B0(*(_DWORD * *)(v0 + 4), v3, v4);
        if (v2 == 2)
        {
            *(_BYTE*)(v0 + 64) = 0;
            sub_43BE40(0);
            v7 = *(void (**)(void))(v0 + 60);
            if (v7)
                v7();
            sub_4A24F0();
        }
        goto LABEL_31;
    }
}

//----- (0043C500) --------------------------------------------------------
int sub_43C500()
{
    return *(_DWORD*)& byte_5D4594[815212];
}

//----- (0043C510) --------------------------------------------------------
int __cdecl sub_43C510(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 40);
    else
        result = 0;
    return result;
}

//----- (0043C520) --------------------------------------------------------
_DWORD* __cdecl sub_43C520(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[815212];
    if (!*(_DWORD*)& byte_5D4594[815212])
        return 0;
    while (*result != a1)
    {
        result = (_DWORD*)result[10];
        if (!result)
            return 0;
    }
    return result;
}

//----- (0043C540) --------------------------------------------------------
_DWORD* sub_43C540()
{
    _DWORD* result; // eax

    result = nox_calloc(1u, 0x44u);
    if (result)
    {
        result[10] = *(_DWORD*)& byte_5D4594[815212];
        if (*(_DWORD*)& byte_5D4594[815212])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[815212] + 44) = result;
        *(_DWORD*)& byte_5D4594[815212] = result;
    }
    return result;
}

//----- (0043C570) --------------------------------------------------------
void __cdecl sub_43C570(LPVOID lpMem)
{
    int v1; // ecx
    int v2; // ecx

    v1 = *((_DWORD*)lpMem + 10);
    if (v1)
        * (_DWORD*)(v1 + 44) = *((_DWORD*)lpMem + 11);
    v2 = *((_DWORD*)lpMem + 11);
    if (v2)
        * (_DWORD*)(v2 + 40) = *((_DWORD*)lpMem + 10);
    else
        *(_DWORD*)& byte_5D4594[815212] = *((_DWORD*)lpMem + 10);
    free(lpMem);
}

//----- (0043C5B0) --------------------------------------------------------
_DWORD* __cdecl sub_43C5B0(_DWORD* a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    _DWORD* v9; // esi

    v9 = sub_43C540();
    if (!v9)
        return 0;
    sub_46A9B0(a1, a4, a5);
    v9[4] = a2;
    v9[5] = a3;
    v9[8] = a6;
    v9[1] = a1;
    v9[2] = a4;
    v9[3] = a5;
    v9[9] = a7;
    v9[6] = a8;
    v9[7] = a9;
    *((_BYTE*)v9 + 64) = 3;
    sub_43BE40(3);
    sub_452D80(922, 100);
    v9[12] = 0;
    v9[14] = 0;
    v9[15] = 0;
    return v9;
}

//----- (0043C640) --------------------------------------------------------
void sub_43C640()
{
    nox_srand(0x2710u);
}

//----- (0043C650) --------------------------------------------------------
int sub_43C650()
{
    __int64 v0; // kr00_8
    unsigned int v1; // eax
    int v2; // ett
    int result; // eax

    v0 = sub_416BB0();
    v1 = *(_DWORD*)& byte_5D4594[815756];
    if (*(_QWORD*)& byte_5D4594[815740])
    {
        v2 = ((unsigned int)v0 < *(int*)& byte_5D4594[815740]) + *(_DWORD*)& byte_5D4594[815744];
        *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[815756] + 815220] = v0 - *(_DWORD*)& byte_5D4594[815740];
        *(_DWORD*)& byte_5D4594[8 * v1 + 815224] = HIDWORD(v0) - v2;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[815756] + 815220] = v0;
        *(_DWORD*)& byte_5D4594[8 * v1 + 815224] = HIDWORD(v0);
    }
    *(_QWORD*)& byte_5D4594[815756] = (__PAIR64__(*(unsigned int*)& byte_5D4594[815760], v1) + 1) % 0x3C;
    result = *(_DWORD*)& byte_5D4594[815748] + 1;
    *(_QWORD*)& byte_5D4594[815740] = v0;
    ++* (_DWORD*)& byte_5D4594[815748];
    return result;
}

//----- (0043C6E0) --------------------------------------------------------
BOOL sub_43C6E0()
{
    return !*(_DWORD*)& byte_5D4594[815704] && !*(_DWORD*)& byte_5D4594[815708];
}

//----- (0043C700) --------------------------------------------------------
int sub_43C700()
{
    return *(_DWORD*)& byte_5D4594[815764];
}

//----- (0043C710) --------------------------------------------------------
BOOL sub_43C710()
{
    return sub_40A5C0(0x10000000);
}

//----- (0043C720) --------------------------------------------------------
int __cdecl sub_43C720(int a1)
{
    int result; // eax
    bool v2; // zf

    result = a1;
    v2 = *(_DWORD*)& byte_5D4594[815764] == a1;
    *(_DWORD*)& byte_5D4594[815764] = a1;
    if (!v2 && !a1)
    {
        sub_4597E0(0);
        result = sub_4169D0(0);
    }
    return result;
}

//----- (0043C750) --------------------------------------------------------
int sub_43C750()
{
    return *(_DWORD*)& byte_5D4594[815700];
}

//----- (0043C760) --------------------------------------------------------
int sub_43C760()
{
    int v0; // esi

    if (!sub_40A5C0(1))
        return *(_DWORD*)& byte_5D4594[815712];
    v0 = sub_40E9F0(31, 1);
    return v0 + sub_40F0D0(31);
}

//----- (0043C790) --------------------------------------------------------
int sub_43C790()
{
    return *(_DWORD*)& byte_587000[91876];
}

//----- (0043C7A0) --------------------------------------------------------
int __cdecl sub_43C7A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[91876] = a1;
    return result;
}

//----- (0043C7B0) --------------------------------------------------------
int __cdecl sub_43C7B0(char* cp, int hostshort, int a3, signed int* a4)
{
    int v4; // eax
    int v5; // eax
    char v7[40]; // [esp+8h] [ebp-28h]

    memset(v7, 0, sizeof(v7));
    *(_DWORD*)& byte_5D4594[815704] = 0;
    *(_DWORD*)& byte_5D4594[815708] = 0;
    *(_DWORD*)& v7[20] = 2048;
    *(_DWORD*)& v7[8] = hostshort;
    sub_5520B0(200, 1024);
    *(_DWORD*)& v7[36] = sub_43C860;
    v4 = sub_5546F0((size_t*)v7);
    *(_DWORD*)& byte_5D4594[815700] = v4;
    v5 = sub_554760(v4, cp, hostshort, a3, 153);
    OnLibraryNotice(258, 0);
    if (!sub_40A5C0(1))
        * (_DWORD*)& byte_5D4594[2649712] |= 0x80000000;
    return 1;
}

//----- (0043C860) --------------------------------------------------------
int __cdecl sub_43C860(int a1, unsigned __int8* a2, int a3)
{
    unsigned __int8 v3; // cl
    int v4; // ecx

    v3 = *a2;
    *(_DWORD*)& byte_5D4594[815712] = a3;
    if (v3 < 0x27u)
    {
        v4 = *a2;
        if (v4 == 33)
        {
            sub_446380();
        }
        else if (v4 == 36)
        {
            *(_DWORD*)& byte_5D4594[2614264] = *(_DWORD*)(a2 + 1);
        }
    }
    else
    {
        sub_48EA70(31, (unsigned int)a2, a3);
        if (sub_43C700())
            sub_48D660();
    }
    *(_QWORD*)& byte_5D4594[815716] = sub_416BB0();
    if (*(_DWORD*)& byte_5D4594[815704] == 1)
    {
        sub_4AB4A0(0);
        *(_DWORD*)& byte_5D4594[815704] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[815708] == 1)
        sub_43CF40();
    return 1;
}

//----- (0043C8F0) --------------------------------------------------------
int __cdecl sub_43C8F0(int a1, int a2, int a3)
{
    int v3; // ebx
    char* v4; // edi
    int result; // eax
    int v6; // eax
    char v7; // [esp+Fh] [ebp-Dh]
    int v8; // [esp+10h] [ebp-Ch]
    char v9[5]; // [esp+14h] [ebp-8h]

    v3 = sub_476F80();
    v4 = sub_42CD50(&v8);
    if (!(_BYTE)v8)
        return 1;
    v7 = 63;
    result = sub_40EBC0(a1, 0, &v7, 1);
    if (result)
    {
        result = sub_40EBC0(a1, 0, &v8, 1);
        if (result)
        {
            result = sub_40EBC0(a1, 0, v4, (unsigned __int8)v8);
            if (result)
            {
                v6 = v3 ? *(_DWORD*)(v3 + 16) : a3;
                if (a2 == *(unsigned __int16*)& byte_5D4594[815768] && v6 == *(unsigned __int16*)& byte_5D4594[815770])
                    return 1;
                *(_WORD*)& byte_5D4594[815770] = v6;
                *(_WORD*)& v9[3] = v6;
                *(_WORD*)& byte_5D4594[815768] = a2;
                v9[0] = -84;
                *(_WORD*)& v9[1] = a2;
                result = sub_40EBC0(a1, 0, v9, 5);
                if (result)
                    return 1;
            }
        }
    }
    return result;
}

//----- (0043C9F0) --------------------------------------------------------
int sub_43C9F0()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -64;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 3);
    return 1;
}

//----- (0043CA20) --------------------------------------------------------
int sub_43CA20()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -66;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 2);
    return 1;
}

//----- (0043CA50) --------------------------------------------------------
int sub_43CA50()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -74;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 3);
    return 1;
}

//----- (0043CA80) --------------------------------------------------------
int sub_43CA80()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -65;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 3);
    return 1;
}

//----- (0043CAB0) --------------------------------------------------------
int sub_43CAB0()
{
    char v0; // al
    char v2; // [esp+1h] [ebp-1h]

    v2 = -73;
    v0 = sub_552640(*(unsigned int*)& byte_5D4594[815700], &v2, 1, 3);
    if (sub_5525B0(*(unsigned int*)& byte_5D4594[815700], v0, 20, 6))
        return 0;
    sub_40ED10(31, 0);
    return 1;
}

//----- (0043CB00) --------------------------------------------------------
int sub_43CB00()
{
    char v0; // al
    char v2; // [esp+1h] [ebp-1h]

    v2 = -83;
    v0 = sub_552640(*(unsigned int*)& byte_5D4594[815700], &v2, 1, 3);
    if (sub_5525B0(*(unsigned int*)& byte_5D4594[815700], v0, 20, 6))
        return 0;
    sub_40ED10(31, 0);
    return 1;
}

//----- (0043CB50) --------------------------------------------------------
int sub_43CB50()
{
    char v0; // al
    char v2; // [esp+1h] [ebp-1h]

    v2 = -82;
    v0 = sub_552640(*(unsigned int*)& byte_5D4594[815700], &v2, 1, 3);
    if (sub_5525B0(*(unsigned int*)& byte_5D4594[815700], v0, 20, 6))
        return 0;
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 3);
    sub_40ED10(31, 0);
    return 1;
}

//----- (0043CBB0) --------------------------------------------------------
int sub_43CBB0()
{
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
    if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[815724]) >= 0x7D0)
    {
        *(_QWORD*)& byte_5D4594[815724] = sub_416BB0();
        sub_552E70(*(unsigned int*)& byte_5D4594[815700]);
    }
    sub_552460();
    if (!*(_DWORD*)& byte_5D4594[815720] && !*(_DWORD*)& byte_5D4594[815716]
        || (unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[815716]) <= 0x4E20)
    {
        return 1;
    }
    sub_43B750();
    return 0;
}

//----- (0043CC60) --------------------------------------------------------
BOOL __cdecl sub_43CC60(int a1)
{
    BOOL result; // eax

    result = a1 == 0;
    *(_DWORD*)& byte_587000[91872] = a1 == 0;
    return result;
}

//----- (0043CC80) --------------------------------------------------------
int sub_43CC80()
{
    int result; // eax

    result = sub_5549F0(*(unsigned int*)& byte_5D4594[815700]);
    *(_DWORD*)& byte_5D4594[2649712] = 0;
    return result;
}

//----- (0043CCA0) --------------------------------------------------------
int sub_43CCA0()
{
    int v0; // esi
    int v1; // esi
    unsigned __int64 v2; // rdi
    unsigned __int64 v3; // rax
    unsigned __int64 v4; // rax
    unsigned __int64 v5; // rax
    char v7[8]; // [esp+8h] [ebp-8h]

    sub_49C4B0();
    v0 = *(_DWORD*)& byte_5D4594[2598000];
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
    if (v0 != *(_DWORD*)& byte_5D4594[2598000] && *(_DWORD*)& byte_5D4594[2650652] == 1 && !sub_40A5C0(1))
    {
        v1 = sub_40A710(1);
        if (sub_43C790() > v1)
        {
            sub_43CEB0();
            v2 = *(_QWORD*)& byte_5D4594[815740] + *(_QWORD*)& byte_587000[91880] / (unsigned __int64)sub_43C790();
            if (sub_416BB0() >= v2)
            {
                v7[0] = 40;
                *(_DWORD*)& v7[1] = *(_DWORD*)& byte_5D4594[2598000] + 1;
                sub_48EA70(31, (unsigned int)v7, 5);
            }
        }
    }
    v3 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815724];
    *(_DWORD*)& v7[4] = HIDWORD(v3);
    if (v3 >= 0x7D0)
    {
        *(_QWORD*)& byte_5D4594[815724] = sub_416BB0();
        sub_552E70(*(unsigned int*)& byte_5D4594[815700]);
    }
    if (!sub_40A5C0(1))
        sub_4E5770(0x1Fu, 0);
    sub_40EE10(*(unsigned int*)& byte_5D4594[815700], 31, 0);
    sub_40ED10(31, 0);
    sub_552460();
    if (*(_DWORD*)& byte_5D4594[815720] || (LODWORD(v4) = *(_DWORD*)& byte_5D4594[815716]) != 0)
    {
        v5 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815716];
        *(_DWORD*)& v7[4] = HIDWORD(v5);
        if (v5 > 0x7D0 && !*(_DWORD*)& byte_5D4594[815704])
        {
            *(_DWORD*)& byte_5D4594[815704] = 1;
            sub_4AB4A0(1);
            *(_QWORD*)& byte_5D4594[815732] = sub_416BB0();
        }
        if (*(_DWORD*)& byte_5D4594[815720] || (LODWORD(v4) = *(_DWORD*)& byte_5D4594[815716]) != 0)
        {
            v4 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815716];
            *(_DWORD*)& v7[4] = HIDWORD(v4);
            if (v4 > 0x4E20)
            {
                LODWORD(v4) = *(_DWORD*)& byte_5D4594[815708];
                if (!*(_DWORD*)& byte_5D4594[815708])
                {
                    v4 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815732];
                    *(_DWORD*)& v7[4] = HIDWORD(v4);
                    if (v4 > 0x4E20)
                        LODWORD(v4) = sub_43CF70();
                }
            }
        }
    }
    return v4;
}

//----- (0043CEB0) --------------------------------------------------------
int sub_43CEB0()
{
    unsigned __int64 v0; // rax
    unsigned int v1; // esi
    unsigned int v2; // edi
    unsigned int v3; // ebx
    unsigned __int64 v4; // rax
    unsigned int v5; // ecx
    int v6; // kr00_4
    unsigned int v7; // kr08_4
    unsigned int v9; // [esp+0h] [ebp-8h]

    LODWORD(v0) = *(_DWORD*)& byte_5D4594[815748];
    if (*(int*)& byte_5D4594[815748] >= 60)
        LODWORD(v0) = 60;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    if ((_DWORD)v0 && (int)v0 > 10)
    {
        v0 = (int)v0;
        v5 = 0;
        v9 = v0;
        do
        {
            do
            {
                v6 = *(_DWORD*)& byte_5D4594[8 * v5 + 815220] + v2;
                v3 = (__PAIR64__(*(_DWORD*)& byte_5D4594[8 * v5 + 815224], *(_DWORD*)& byte_5D4594[8 * v5 + 815220])
                      + __PAIR64__(v3, v2)) >> 32;
                v2 += *(_DWORD*)& byte_5D4594[8 * v5 + 815220];
                v7 = v5 + 1;
                v1 = (__PAIR64__(v1, v5++) + 1) >> 32;
            } while (v1 < HIDWORD(v4));
            LODWORD(v4) = v9;
        } while (v1 <= HIDWORD(v4) && v7 < v9);
        v0 = __PAIR64__(v3, v6) / v4;
        *(_QWORD*)& byte_587000[91880] = v0;
    }
    else
    {
        *(_DWORD*)& byte_587000[91884] = 0;
        *(_DWORD*)& byte_587000[91880] = 33;
    }
    return v0;
}

//----- (0043CF40) --------------------------------------------------------
int sub_43CF40()
{
    *(_QWORD*)& byte_5D4594[815732] = sub_416BB0();
    *(_DWORD*)& byte_5D4594[815708] = 0;
    return sub_4AB4D0(0);
}

//----- (0043CF70) --------------------------------------------------------
int sub_43CF70()
{
    int result; // eax
    char v2; // [esp+1h] [ebp-1h]

    result = *(_DWORD*)& byte_5D4594[815708];
    if (!*(_DWORD*)& byte_5D4594[815708])
    {
        sub_4AB4D0(1);
        *(_DWORD*)& byte_5D4594[815708] = 1;
        result = *(_DWORD*)& byte_5D4594[2618908];
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            sub_4174F0(*(int*)& byte_5D4594[2618908], 64);
            v2 = 41;
            result = sub_4E53C0(31, &v2, 1, 0, 1);
        }
    }
    return result;
}
// 43CFA0: variable 'v1' is possibly undefined

//----- (0043CFD0) --------------------------------------------------------
BOOL sub_43CFD0()
{
    return sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1) != -1;
}

//----- (0043CFF0) --------------------------------------------------------
int sub_43CFF0()
{
    __int64 v0; // kr00_8

    v0 = sub_416BB0();
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
    sub_40EE10(*(unsigned int*)& byte_5D4594[815700], 31, 0);
    sub_40ED10(31, 0);
    sub_552460();
    if (sub_40A370())
        return 1;
    while ((unsigned __int64)(sub_416BB0() - v0) < 0x2710)
    {
        sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
        sub_40EE10(*(unsigned int*)& byte_5D4594[815700], 31, 0);
        sub_40ED10(31, 0);
        sub_552460();
        if (sub_40A370())
            return 1;
    }
    return 0;
}

//----- (0043D0A0) --------------------------------------------------------
void __cdecl sub_43D0A0(int a1)
{
    wchar_t* v1; // esi
    wchar_t* v2; // eax

    v1 = loadString_sub_40F1D0((char*)& byte_587000[91932], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 702);
    switch (a1 + 23)
    {
        case 0:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92656], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 762);
            break;
        case 1:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92596], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 757);
            break;
        case 2:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92540], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 752);
            break;
        case 3:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92304], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 732);
            break;
        case 4:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92252], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 727);
            break;
        case 5:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92124], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 718);
            break;
        case 8:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92484], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 747);
            break;
        case 10:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92056], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 713);
            break;
        case 11:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[91992], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 708);
            break;
        case 17:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92192], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 722);
            break;
        case 19:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92424], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 742);
            break;
        case 20:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92364], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 737);
            break;
        default:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92720], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 767);
            break;
    }
    sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
    sub_44A360(1);
}

//----- (0043D260) --------------------------------------------------------
void __cdecl sub_43D260(int a1, int a2)
{
    wchar_t* v2; // eax
    wchar_t v3[256]; // [esp+8h] [ebp-200h]

    if (a1)
    {
        if (a2)
        {
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92784], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 784);
            nox_swprintf(v3, v2, a1, a2);
            sub_445490(v3);
        }
    }
}

//----- (0043D2C0) --------------------------------------------------------
void sub_43D2C0()
{
    nox_srand(0x2711u);
}

//----- (0043D2D0) --------------------------------------------------------
void sub_43D2D0()
{
    int v1; // esi

    if (*(_DWORD*)& byte_5D4594[816340])
    {
        if (*(_DWORD*)& byte_5D4594[816364])
        {
            sub_486520((unsigned int*)& byte_5D4594[816244]);
            sub_486520((unsigned int*)& byte_5D4594[816148]);
            v1 = *(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 4) >> 16;
            if (v1 == *(_DWORD*)& byte_587000[93168])
            {
                if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[816380]) > 0x32)
                {
                    **(_DWORD * *)& byte_587000[81128] &= 0xFFFFFFFD;
                    *(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 32) &= 0xFFFFFFFD;
                    *(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 64) &= 0xFFFFFFFD;
                }
            }
            else
            {
                *(_QWORD*)& byte_5D4594[816380] = sub_416BB0();
                *(_DWORD*)& byte_587000[93168] = v1;
            }
            if (*(_DWORD*)& byte_5D4594[816364])
            {
                if (**(_BYTE * *)& byte_587000[81128] & 2 || byte_5D4594[816148] & 2 || byte_5D4594[816244] & 2)
                    sub_43D3C0(*(int*)& byte_5D4594[816364], *(int*)& byte_5D4594[816096]);
            }
        }
    }
}

//----- (0043D3C0) --------------------------------------------------------
void __cdecl sub_43D3C0(int a1, int a2)
{
    unsigned int v2; // eax

    if (a1)
    {
        v2 = (*(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 4) >> 16)
             * ((*(unsigned __int16*)& byte_5D4594[816154]
                 * ((a2 * (unsigned int) * (unsigned __int16*)& byte_5D4594[816250]) >> 14)) >> 14);
        *(_DWORD*)& byte_5D4594[816148] &= 0xFFFFFFFD;
        *(_DWORD*)& byte_5D4594[816244] &= 0xFFFFFFFD;
        AIL_set_stream_volume(a1, (int)(127 * (v2 >> 14)) / 100);
    }
}
// 581430: using guessed type int __stdcall AIL_set_stream_volume(_DWORD, _DWORD);

//----- (0043D440) --------------------------------------------------------
int sub_43D440()
{
    int* v0; // esi
    int result; // eax

    v0 = (int*)& byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
    result = *(_DWORD*)& byte_5D4594[816340];
    if (*(_DWORD*)& byte_5D4594[816340])
    {
        result = *(_DWORD*)& byte_5D4594[816348];
        switch (*(_DWORD*)& byte_5D4594[816348])
        {
            case 0:
                if (*(_DWORD*)& byte_5D4594[816356] && (result = *(_DWORD*)& byte_587000[93156]) != 0)
                {
                    *(_DWORD*)& byte_5D4594[816348] = 3;
                }
                else
                {
                    result = *v0;
                    if (*v0)
                    {
                        result = *(_DWORD*)& byte_587000[93156];
                        if (*(_DWORD*)& byte_587000[93156])
                        {
                            sub_486320(&byte_5D4594[816148], 0x4000);
                            result = sub_43D6C0(v0);
                            if (result)
                            {
                                result = 1;
                                *(_DWORD*)& byte_5D4594[816348] = 1;
                                v0[4] = 1;
                            }
                            else
                            {
                                *v0 = 0;
                            }
                        }
                    }
                }
                break;
            case 1:
                if (*(_DWORD*)& byte_587000[93156]
                    && *v0 == *(_DWORD*)& byte_5D4594[816092]
                    && *(_DWORD*)& byte_5D4594[816364]
                    && AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]) != 2)
                {
                    result = *(_DWORD*)& byte_5D4594[816356];
                    if (*(_DWORD*)& byte_5D4594[816356])
                    {
                        *(_DWORD*)& byte_5D4594[816348] = 4;
                        result = sub_486350((int)& byte_5D4594[816148], 0);
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[816348] = 2;
                    result = sub_486350((int)& byte_5D4594[816148], 0);
                }
                break;
            case 2:
                if (!*(_DWORD*)& byte_5D4594[816364]) {
                    result = sub_43D650();
                    *(_DWORD*)& byte_5D4594[816348] = 0;
                } else {
                    result = AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]);
                    if (result == 2 || !(*(_DWORD*)& byte_5D4594[816152] & 0xFFFF0000)) {
                        result = sub_43D650();
                        *(_DWORD*)& byte_5D4594[816348] = 0;
                    }
                }
                break;
            case 3:
                if (!*(_DWORD*)& byte_5D4594[816356] || (result = *(_DWORD*)& byte_587000[93156]) == 0)
                {
                    if (!*(_DWORD*)& byte_587000[93156]
                        || *v0 != *(_DWORD*)& byte_5D4594[816092]
                        || !*(_DWORD*)& byte_5D4594[816364]
                        || AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]) == 2)
                    {
                        result = sub_43D650();
                        *(_DWORD*)& byte_5D4594[816348] = 0;
                    } else {
                        sub_486350((int)& byte_5D4594[816148], 0x4000);
                        result = sub_43D6A0();
                        *(_DWORD*)& byte_5D4594[816348] = 1;
                    }
                }
                break;
            case 4:
                if (*(_DWORD*)& byte_5D4594[816364]
                    && (result = AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]), result != 2))
                {
                    if (!(*(_DWORD*)& byte_5D4594[816152] & 0xFFFF0000))
                    {
                        result = sub_43D680();
                        *(_DWORD*)& byte_5D4594[816348] = 3;
                    }
                }
                else
                {
                    result = sub_43D650();
                    *(_DWORD*)& byte_5D4594[816348] = 0;
                }
                break;
            default:
                return result;
        }
    }
    return result;
}
// 58141C: using guessed type int __stdcall AIL_stream_status(_DWORD);

//----- (0043D650) --------------------------------------------------------
int sub_43D650()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
    {
        *(_DWORD*)& byte_5D4594[816364] = 0;
        AIL_close_stream(result);
    }
    *(_DWORD*)& byte_5D4594[816092] = 0;
    return result;
}
// 581418: using guessed type int __stdcall AIL_close_stream(_DWORD);

//----- (0043D680) --------------------------------------------------------
int sub_43D680()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
        AIL_pause_stream(*(_DWORD*)& byte_5D4594[816364], 1);
    return result;
}
// 581414: using guessed type int __stdcall AIL_pause_stream(_DWORD, _DWORD);

//----- (0043D6A0) --------------------------------------------------------
int sub_43D6A0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
        AIL_pause_stream(*(_DWORD*)& byte_5D4594[816364], 0);
    return result;
}
// 581414: using guessed type int __stdcall AIL_pause_stream(_DWORD, _DWORD);

//----- (0043D6C0) --------------------------------------------------------
int __cdecl sub_43D6C0(int* a1)
{
    const char* v1; // edi
    unsigned __int8 v2; // dl
    char* v3; // edi
    int v4; // esi
    char* v5; // eax
    unsigned int v6; // kr08_4
    char v8[540]; // [esp+10h] [ebp-21Ch]

    v1 = *(const char**)& byte_587000[4 * *a1 + 92792];
    sub_43D650();
    *(_DWORD*)& byte_587000[93160] = 0;
    if (!*(_DWORD*)& byte_5D4594[816376])
        return 0;
    strcpy(v8, "music\\");
    strcat(v8, v1);
    if (!strchr(v8, 46))
    {
        v2 = byte_587000[93184];
        v3 = &v8[strlen(v8)];
        *(_DWORD*)v3 = *(_DWORD*)& byte_587000[93180];
        v3[4] = v2;
    }
    v4 = AIL_open_stream(*(_DWORD*)& byte_5D4594[816376], v8, 204800);
    if (!v4)
    {
        if (*(_DWORD*)& byte_587000[122856] && sub_44D930())
            return 0;
        v5 = sub_413890();
        if (!v5)
            return 0;
        *(_DWORD*)& byte_587000[93160] = 1;
        strncpy(&v8[40], v5, 0x1F4u);
        v8[539] = 0;
        v6 = strlen(&v8[40]) + 1;
        if (v6 != 1 && v8[v6 + 38] != 92)
            * (_WORD*)& v8[strlen(&v8[40]) + 40] = *(_WORD*)& byte_587000[93188];
        strcat(&v8[40], v8);
        v4 = AIL_open_stream(*(_DWORD*)& byte_5D4594[816376], &v8[40], 204800);
        if (!v4)
            return 0;
    }
    AIL_set_stream_position(v4, a1[2]);
    sub_486320(&byte_5D4594[816148], 0);
    sub_486350((int)& byte_5D4594[816148], 0x4000);
    sub_43D3C0(v4, a1[1]);
    AIL_start_stream(v4);
    *(_DWORD*)& byte_5D4594[816092] = *a1;
    *(_DWORD*)& byte_5D4594[816096] = a1[1];
    *(_DWORD*)& byte_5D4594[816100] = a1[2];
    *(_DWORD*)& byte_5D4594[816104] = a1[3];
    a1[2] = 0;
    *(_DWORD*)& byte_5D4594[816364] = v4;
    return 1;
}
// 581408: using guessed type int __stdcall AIL_open_stream(_DWORD, _DWORD, _DWORD);
// 58140C: using guessed type int __stdcall AIL_set_stream_position(_DWORD, _DWORD);
// 581410: using guessed type int __stdcall AIL_start_stream(_DWORD);

//----- (0043D8E0) --------------------------------------------------------
int sub_43D8E0()
{
    int result; // eax
    int v1; // eax

    if (*(_DWORD*)& byte_5D4594[816340])
        return 1;
    v1 = sub_43F130();
    *(_DWORD*)& byte_5D4594[816376] = v1;
    *(_DWORD*)& byte_587000[93156] = v1 != 0;
    sub_4864A0(&byte_5D4594[816148]);
    sub_486380(&byte_5D4594[816148], 0x3E8u, 0, 0x4000);
    *(_DWORD*)& byte_5D4594[816348] = 0;
    *(_DWORD*)& byte_5D4594[816092] = 0;
    *(_DWORD*)& byte_5D4594[816352] = 0;
    *(_DWORD*)& byte_5D4594[816108] = 0;
    *(_DWORD*)& byte_5D4594[816356] = 0;
    *(_DWORD*)& byte_5D4594[816372] = 0;
    *(_DWORD*)& byte_5D4594[816368] = 0;
    *(_DWORD*)& byte_5D4594[816364] = 0;
    result = 1;
    *(_DWORD*)& byte_5D4594[816340] = 1;
    return result;
}

//----- (0043D970) --------------------------------------------------------
int sub_43D970()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816340];
    if (*(_DWORD*)& byte_5D4594[816340])
    {
        result = sub_43DCC0();
        *(_DWORD*)& byte_5D4594[816340] = 0;
    }
    return result;
}

//----- (0043D990) --------------------------------------------------------
void sub_43D990()
{
    int4 v1; // [esp+0h] [ebp-10h]

    v1.field_0 = 0;
    sub_43D9E0(&v1);
}

//----- (0043D9B0) --------------------------------------------------------
void __cdecl sub_43D9B0(int a1, int a2)
{
    int4 v3; // [esp+0h] [ebp-10h]

    v3.field_0 = a1;
    v3.field_C = 0;
    v3.field_8 = 0;
    v3.field_4 = a2;
    sub_43D9E0(&v3);
}

//----- (0043D9E0) --------------------------------------------------------
void __cdecl sub_43D9E0(int4* a1)
{
    int4* v1; // edx
    int v2; // ecx

    v1 = (int4*)& byte_5D4594[20 * (*(_DWORD*)& byte_5D4594[816352] ^ 1) + 816108];
    v2 = a1->field_4;
    if (v2 <= 100)
    {
        if (v2 < 0)
            a1->field_4 = 0;
    }
    else
    {
        a1->field_4 = 100;
    }
    if (*(_DWORD*)& byte_5D4594[816344])
    {
        *(int4*)& byte_5D4594[816060] = *a1;
    }
    else
    {
        *v1 = *a1;
        v1[1].field_0 = 0;
        *(_DWORD*)& byte_5D4594[816352] ^= 1u;
    }
}

//----- (0043DA80) --------------------------------------------------------
int sub_43DA80()
{
    int result; // eax

    if (*(int*)& byte_5D4594[816368] < 6)
    {
        sub_43DD10((int*)& byte_5D4594[16 * (*(_DWORD*)& byte_5D4594[816368] + 6 * *(_DWORD*)& byte_5D4594[816372]) + 815772]);
        ++* (_DWORD*)& byte_5D4594[816368];
        result = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816368] = 6;
        result = 0;
    }
    return result;
}

//----- (0043DAD0) --------------------------------------------------------
void sub_43DAD0()
{
    if (*(_DWORD*)& byte_5D4594[816368] > 0)
        sub_43D9E0((int4*)& byte_5D4594[16
                                        * (-- * (_DWORD*)& byte_5D4594[816368] + 6 * *(_DWORD*)& byte_5D4594[816372])
                                        + 815772]);
    *(_DWORD*)& byte_5D4594[816368] = 0;
}

//----- (0043DB10) --------------------------------------------------------
void sub_43DB10()
{
    sub_43D990();
    *(_DWORD*)& byte_5D4594[816368] = 0;
}

//----- (0043DB20) --------------------------------------------------------
int sub_43DB20()
{
    return *(_DWORD*)& byte_5D4594[816368];
}

//----- (0043DB30) --------------------------------------------------------
int __cdecl sub_43DB30(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[816368] = a1;
    return result;
}

//----- (0043DB40) --------------------------------------------------------
char* __cdecl sub_43DB40(int a1)
{
    return (char*)& byte_5D4594[16 * (a1 + 6 * *(_DWORD*)& byte_5D4594[816372]) + 815772];
}

//----- (0043DB60) --------------------------------------------------------
int sub_43DB60()
{
    int result; // eax
    int v1; // eax
    int v2; // ecx

    result = 3;
    if (*(int*)& byte_5D4594[816372] < 3)
    {
        sub_43DA80();
        v1 = *(_DWORD*)& byte_5D4594[816372];
        v2 = *(_DWORD*)& byte_5D4594[816368];
        *(_DWORD*)& byte_5D4594[816368] = 0;
        *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[816372] + 816076] = v2;
        result = v1 + 1;
        *(_DWORD*)& byte_5D4594[816372] = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816372] = 3;
    }
    return result;
}

//----- (0043DBA0) --------------------------------------------------------
void sub_43DBA0()
{
    int v1; // eax
    if (*(_DWORD*)& byte_5D4594[816372] > 0)
    {
        v1 = *(_DWORD*)& byte_5D4594[816372] - 1;
        *(_DWORD*)& byte_5D4594[816372] = v1;
        *(_DWORD*)& byte_5D4594[816368] = *(_DWORD*)& byte_5D4594[4 * v1 + 816076];
        sub_43DAD0();
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816372] = 0;
    }
}

//----- (0043DBD0) --------------------------------------------------------
int sub_43DBD0()
{
    ++* (_DWORD*)& byte_5D4594[816356];
    return sub_43D440();
}

//----- (0043DBE0) --------------------------------------------------------
int sub_43DBE0()
{
    if (-- * (int*)& byte_5D4594[816356] < 0)
        * (_DWORD*)& byte_5D4594[816356] = 0;
    return sub_43D440();
}

//----- (0043DC00) --------------------------------------------------------
void sub_43DC00()
{
    *(_DWORD*)& byte_587000[93156] = 0;
}

//----- (0043DC10) --------------------------------------------------------
int sub_43DC10()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816376];
    if (*(_DWORD*)& byte_5D4594[816376])
        * (_DWORD*)& byte_587000[93156] = 1;
    return result;
}

//----- (0043DC30) --------------------------------------------------------
int sub_43DC30()
{
    return *(_DWORD*)& byte_587000[93156];
}

//----- (0043DC40) --------------------------------------------------------
int sub_43DC40()
{
    int result; // eax

    if (!*(_DWORD*)& byte_5D4594[816340]
        || (result = 1, *(_DWORD*)& byte_5D4594[816348] != 1)
           && *(_DWORD*)& byte_5D4594[816348] != 4
           && *(_DWORD*)& byte_5D4594[816348] != 2)
    {
        result = 0;
    }
    return result;
}

//----- (0043DC80) --------------------------------------------------------
int sub_43DC80()
{
    unsigned __int8* v0; // eax

    if (*(_DWORD*)& byte_587000[93156] && *(_DWORD*)& byte_5D4594[816340])
    {
        while (1)
        {
            v0 = &byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
            if (*(_DWORD*)v0)
            {
                if (*((_DWORD*)v0 + 4))
                    break;
            }
            sub_4312C0();
        }
    }
    return 1;
}

//----- (0043DCC0) --------------------------------------------------------
int sub_43DCC0()
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[93156];
    if (*(_DWORD*)& byte_587000[93156])
    {
        result = *(_DWORD*)& byte_5D4594[816340];
        if (*(_DWORD*)& byte_5D4594[816340])
        {
            sub_43D990();
            for (result = *(_DWORD*)& byte_5D4594[816348];
                 *(_DWORD*)& byte_5D4594[816348];
                 result = *(_DWORD*)& byte_5D4594[816348])
            {
                if (*(_DWORD*)& byte_5D4594[816348] == 3)
                {
                    sub_43D650();
                    *(_DWORD*)& byte_5D4594[816348] = 0;
                }
                sub_4312C0();
#ifdef __EMSCRIPTEN__
                nox_sleep(0x32u);
#endif // __EMSCRIPTEN__
            }
        }
    }
    return result;
}

//----- (0043DD10) --------------------------------------------------------
int __cdecl sub_43DD10(int* a1)
{
    unsigned __int8* v1; // ecx
    int result; // eax

    v1 = &byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
    *a1 = *(_DWORD*)& byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
    a1[1] = *((_DWORD*)v1 + 1);
    a1[2] = *((_DWORD*)v1 + 2);
    a1[3] = *((_DWORD*)v1 + 3);
    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
    {
        result = *a1;
        if (*(_DWORD*)& byte_5D4594[816092] == *a1)
        {
            result = AIL_stream_position(*(_DWORD*)& byte_5D4594[816364]);
            a1[2] = result;
        }
    }
    return result;
}
// 581404: using guessed type int __stdcall AIL_stream_position(_DWORD);

//----- (0043DD70) --------------------------------------------------------
void __cdecl sub_43DD70(int a1, int a2)
{
    sub_43DD10((int*)& byte_5D4594[816060]);
    sub_43D9B0(a1, a2);
    *(_DWORD*)& byte_5D4594[816344] = 1;
}

//----- (0043DDA0) --------------------------------------------------------
void sub_43DDA0()
{
    *(_DWORD*)& byte_5D4594[816344] = 0;
    sub_43D9E0((int4*)& byte_5D4594[816060]);
}

//----- (0043DDC0) --------------------------------------------------------
void sub_43DDC0()
{
    nox_srand(0x1E77u);
}

//----- (0043DDD0) --------------------------------------------------------
int __cdecl sub_43DDD0(int a1)
{
    *(_DWORD*)& byte_587000[93200] = a1;
    return a1;
}

//----- (0043DDE0) --------------------------------------------------------
int __cdecl sub_43DDE0(int a1)
{
    *(_DWORD*)& byte_587000[93192] = a1;
    return a1;
}

//----- (0043DDF0) --------------------------------------------------------
int __cdecl sub_43DDF0(int (*a1)(void))
{
    *(_DWORD*)& byte_5D4594[816388] = a1;
    if (!a1)
        * (_DWORD*)& byte_5D4594[816388] = sub_43DE10;
    return 1;
}

//----- (0043DE10) --------------------------------------------------------
int sub_43DE10()
{
    return 1;
}

//----- (0043DE20) --------------------------------------------------------
int __cdecl nox_set_draw_unk1(int (*fnc)(void))
{
    nox_draw_unk1 = fnc;
    if (!fnc)
        nox_draw_unk1 = sub_43DE10;
    return 1;
}

//----- (0043DE40) --------------------------------------------------------
int __cdecl sub_43DE40(int (*a1)(void))
{
    *(_DWORD*)& byte_5D4594[816392] = a1;
    if (!a1)
        * (_DWORD*)& byte_5D4594[816392] = sub_43DE10;
    return 1;
}

//----- (0043DE60) --------------------------------------------------------
int sub_43DE60()
{
    int result; // eax

    *(_DWORD*)& byte_587000[93196] = 0;
    sub_43C720(0);
    result = sub_43AF70();
    if (result == 1)
    {
        result = sub_40A5C0(0x2000000);
        if (!result)
            result = sub_40D380();
    }
    return result;
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
int map_download_loop(int first)
{
    unsigned __int8* v1; // eax

    sub_416C70(30);
    sub_4453A0_poll_events();
    sub_4308A0(1);
    sub_46B740();
    if (sub_43AF70() == 1)
    {
        sub_40D250();
        sub_40DF90();
    }
    v1 = (unsigned __int8*)sub_430940();
    for (*(_DWORD*)& byte_5D4594[2618912] = v1; *v1; *(_DWORD*)& byte_5D4594[2618912] = v1)
    {
        sub_46B6B0(v1);
        v1 = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618912] + 8);
    }
    sub_43CCA0();
    if (first)
        sub_43CA50();
    if (*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu)
        sub_43CA20();

    if (!*(_DWORD*)& byte_587000[173328])
        return map_download_finish();

    mainloop_draw();
    sub_477830();
    sub_48A220();
    sub_4AD170_call_copy_backbuffer();
    sub_48A290_call_present();

    if (!*(_DWORD*)& byte_587000[173328])
        return map_download_finish();
    return -1;
}
void map_download_start()
{
    sub_467DF0(1);
    sub_4CC770();
    *(_DWORD*)& byte_587000[173328] = 1;
    *(_DWORD*)& byte_587000[173332] = 1;
    map_download_loop(1);
}

//----- (0043E1A0) --------------------------------------------------------
_DWORD* __cdecl sub_43E1A0(int a1)
{
    _DWORD* result; // eax

    if (a1)
    {
        result = nox_window_new(0, 552, 0, 0, nox_win_width, nox_win_height, 0);
        *(_DWORD*)& byte_5D4594[816412] = result;
        result[14] = *(_DWORD*)& byte_5D4594[2650656];
    }
    else
    {
        result = *(_DWORD * *)& byte_5D4594[816412];
        if (*(_DWORD*)& byte_5D4594[816412])
        {
            result = (_DWORD*)sub_46C4E0(*(_DWORD * *)& byte_5D4594[816412]);
            *(_DWORD*)& byte_5D4594[816412] = 0;
        }
    }
    return result;
}

//----- (0043E200) --------------------------------------------------------
int sub_43E200()
{
    sub_477530(0);
    sub_43E1A0(0);
    sub_43DDD0(0);
    sub_43DE60();
    return sub_44A400();
}

//----- (0043E230) --------------------------------------------------------
int sub_43E230()
{
    char* v0; // eax
    char* v2; // eax

    sub_477530(0);
    v0 = sub_409B90();
    if (_chmod(v0, 128) == -1)
        return sub_43E200();
    v2 = sub_409C70();
    if (_chmod(v2, 128) == -1)
        return sub_43E200();
    sub_40A4D0(0x100000);
    return sub_44A400();
}

//-------------------------------------------------------------------------
void mainloop_stop()
{
    if (*(_DWORD*)& byte_5D4594[805872])
    {
        *(_DWORD*)& byte_587000[93200] = 1;
        mainloop_exit();
        return;
    }

    // "exit the loop" ?
    if (*(_DWORD*)& byte_587000[93196])
    {
        return;
    }
    mainloop_exit();
}
//-------------------------------------------------------------------------
void mainloop_wait_and_exit(int flags)
{
    if (!(flags & 0x40000000))
    {
        while (!sub_416CD0()) {}
        mainloop_stop();
        return;
    }
    int ms = sub_416D00();
    *(_DWORD*)& byte_5D4594[816404] = ms;
    if (ms > 0)
        nox_sleep(ms);
    mainloop_stop();
}
//----- (0043E290) --------------------------------------------------------
void mainloop()
{
    unsigned __int8* v0; // eax
    int2* v1; // edi
    int v2; // ebp
    int v3; // ebx
    int v4; // esi
    int v5; // eax
    int v6; // eax
    int v7; // esi
    int v9; // edi
    int v10; // eax
    int v11; // ebx
    int v12; // esi
    int v13; // eax
    int v14; // kr00_4
    int v15; // esi
    char v16; // al
    int v21; // [esp-10h] [ebp-68h]
    char v22; // [esp-8h] [ebp-60h]
    char v23; // [esp-4h] [ebp-5Ch]
    char v24; // [esp-4h] [ebp-5Ch]
    int* v25; // [esp+4h] [ebp-54h]
    int v26; // [esp+18h] [ebp-40h]
    int2* v27; // [esp+20h] [ebp-38h]
    int v28[10]; // [esp+24h] [ebp-34h]

    if (mainloop_enter)
    {
        mainloop_enter(mainloop_enter_args);
        return;
    }

#ifdef __EMSCRIPTEN__
    DWORD cur_tick;
    static DWORD last_tick;

    // rate limit to < 40 fps
    cur_tick = nox_get_ticks();
    if (cur_tick - last_tick < 1000 / 40)
        return;
    last_tick = cur_tick;
#endif

    if (*(_DWORD*)& byte_587000[173328])
    {
        int ret = map_download_loop(0);
        if (ret == -1)
        {
            return;
        }
        else if (ret == 0)
        {
            // map error
            *(_DWORD*)& byte_587000[93196] = 0;
            *(_DWORD*)& byte_587000[93200] = 0;
            mainloop_exit();
            return;
        }
    }
    else
    {
        _control87(0x300u, 0x300u);
        if (!sub_43DEB0())
        {
            // XXX
            if (*(_DWORD*)& byte_587000[173328])
                return;
            *(_DWORD*)& byte_587000[93196] = 0;
            *(_DWORD*)& byte_587000[93200] = 0;
            mainloop_exit();
            return;
        }
    }
    if (sub_43AF70() == 1)
    {
        sub_40D250();
        sub_40DF90();
    }
    sub_416C70(30);
    sub_4453A0_poll_events();
    sub_413520();
    sub_435770();
    if (!(*(int (**)(void)) & byte_5D4594[816388])())
    {
        mainloop_exit();
        return;
    }
    sub_435780();
    sub_435740();
    sub_430880(1);
    sub_4308A0(1);
    sub_46B740();
    v0 = (unsigned __int8*)sub_430940();
    for (*(_DWORD*)& byte_5D4594[2618912] = v0; *v0; *(_DWORD*)& byte_5D4594[2618912] = v0)
    {
        sub_46B6B0(v0);
        v0 = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618912] + 8);
    }
    if (!nox_draw_unk1())
    {
        mainloop_exit();
        return;
    }
    sub_430880(0);
    if (!(*(int (**)(void)) & byte_5D4594[816392])())
    {
        mainloop_exit();
        return;
    }
    sub_4519C0();
    sub_4312C0();
    sub_495430();
    if (sub_40A5C0(1) && *(_DWORD*)& byte_587000[93200] == 1)
    {
        if (*(_DWORD*)& byte_5D4594[815132])
            goto LABEL_24;
        if (sub_40A5C0(0x2000))
        {
            if (sub_40A680())
            {
                sub_4DEF00();
                sub_40A690();
            }
            else if (sub_459D60() && !sub_40A5C0(9437184))
            {
                if (sub_459DA0())
                    sub_4DF020();
                sub_459D50(0);
            }
            if (*(int*)& byte_5D4594[2598000] >= *(int*)& byte_5D4594[816400])
            {
                sub_4161E0();
                sub_416690();
                *(_DWORD*)& byte_5D4594[816400] = *(_DWORD*)& byte_5D4594[2598000] + 60 * *(_DWORD*)& byte_5D4594[2649704];
            }
        }
    }
    if (*(_DWORD*)& byte_5D4594[815132])
    {
        LABEL_24:
        sub_43C380();
        *(_DWORD*)& byte_5D4594[2650636] &= 0x7FFFFFFFu;
        if (!*(_DWORD*)& byte_5D4594[816408])
        {
            v1 = sub_4309F0();
            v27 = v1;
            v2 = v1->field_0 - *(_DWORD*)& byte_5D4594[816420];
            v3 = v1->field_4 - *(_DWORD*)& byte_5D4594[816424];
            v4 = v2 * v2 + v3 * v3;
            if (*(_DWORD*)& byte_5D4594[816428])
            {
                v5 = nox_double2int(sqrt((double)(v2 * v2 + v3 * v3))) / 4;
                if (v5 > 0)
                {
                    v26 = v5;
                    do
                    {
                        v6 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 570);
                        v7 = *(_DWORD*)& byte_5D4594[816420] + v2 * v6 / 100;
                        v9 = *(_DWORD*)& byte_5D4594[816424] + v3 * v6 / 100;
                        v23 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 582);
                        v22 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 581);
                        v21 = sub_415FF0(-7, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 579);
                        v10 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 578);
                        sub_431540(4, v7, v9, v10, v21, 1, v22, v23, 2, 1);
                        --v26;
                    } while (v26);
                    v4 = v2 * v2 + v3 * v3;
                    v1 = v27;
                }
                if (v4 < 10)
                    * (_DWORD*)& byte_5D4594[816428] = 0;
                *(_DWORD*)& byte_5D4594[816420] = v1->field_0;
                *(_DWORD*)& byte_5D4594[816424] = v1->field_4;
            }
            else if (v4 > 64)
            {
                *(_DWORD*)& byte_5D4594[816428] = 1;
            }
            if (v1[2].field_4 == 1)
            {
                sub_415FF0(0, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 608);
                if (!*(_DWORD*)& byte_5D4594[816416])
                {
                    *(_DWORD*)& byte_5D4594[816416] = 1;
                    sub_452D80(924, 100);
                    v11 = 75;
                    do
                    {
                        v12 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 620);
                        v13 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 621);
                        v14 = v13 * *(int*)& byte_587000[8 * v12 + 192088];
                        v15 = v13 * *(int*)& byte_587000[8 * v12 + 192092] / 16 - 6;
                        v24 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 633);
                        v16 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 632);
                        sub_431540(4, v14 / 16 + v27->field_0, v27->field_4 + v15, v14 / 16, v15, 1, v16, v24, 2, 1);
                        --v11;
                    } while (v11);
                }
            }
            else
            {
                *(_DWORD*)& byte_5D4594[816416] = 0;
            }
        }
    }
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x80000000))
    {
        sub_437180();
        if (!*(_DWORD*)& byte_5D4594[1556112])
            mainloop_draw();
        if (*(_DWORD*)& byte_5D4594[815132])
        {
            v28[0] = 0;
            v28[1] = 0;
            v28[2] = nox_win_width;
            v28[3] = nox_win_height;
            v28[8] = nox_win_width;
            v28[9] = nox_win_height;
            sub_431720(v28);
        }
        else
        {
            v25 = (int*)sub_437250();
            sub_431720(v25);
        }
        if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000) || byte_5D4594[2650637] & 1 || *(_DWORD*)& byte_5D4594[815132])
            sub_477830();
        sub_44D9F0(1);
        if (!sub_409F40(4096))
            sub_46D830();
        if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000) || byte_5D4594[2650637] & 1 || *(_DWORD*)& byte_5D4594[815132])
        {
            sub_48A220();
            sub_4AD170_call_copy_backbuffer();
            sub_48A290_call_present();
        }
    }
    sub_435750();
    if (!*(_DWORD*)& byte_587000[93192])
    {
        mainloop_stop();
        return;
    }
    int v17 = *(_DWORD*)& byte_5D4594[2650636];
    if (!sub_40A5C0(1) || !sub_40A5C0(2))
    {
        mainloop_wait_and_exit(v17);
        return;
    }
    if (!(v17 & 0x40000))
    {
        if (sub_40A5C0(0x10000000))
        {
            if (!(v17 & 0x80000000))
                sub_416DD0();
            mainloop_stop();
            return;
        }
    }
    mainloop_wait_and_exit(v17);
    return;
}
void sub_43E290()
{
    *(_DWORD*)& byte_587000[93196] = 1;
    *(_DWORD*)& byte_587000[93200] = 1;
    *(_DWORD*)& byte_5D4594[816400] = 60 * *(_DWORD*)& byte_5D4594[2649704];

    // XXX
    sub_4AB560(0);

    mainloop_enter = NULL;
#ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    emscripten_set_main_loop(mainloop, 0, 0);
    //emscripten_set_main_loop_timing(EM_TIMING_RAF, 2);
    return;
    // never get here
#else
    while (*(_DWORD*)& byte_587000[93196])
        mainloop();
#endif
}
// 43E815: variable 'v18' is possibly undefined
// 4AD170: using guessed type int sub_4AD170_call_copy_backbuffer(void);

//----- (0043E8B0) --------------------------------------------------------
int sub_43E8B0()
{
    return *(_DWORD*)& byte_5D4594[816404];
}

//----- (0043E8C0) --------------------------------------------------------
int __cdecl sub_43E8C0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[816408] = a1;
    return result;
}

//----- (0043E8D0) --------------------------------------------------------
void sub_43E8D0()
{
    nox_srand(0x1E76u);
}

//----- (0043E8E0) --------------------------------------------------------
void sub_43E8E0(int a1)
{
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        if (!*(_DWORD*)& byte_5D4594[816436])
        {
            *(_DWORD*)& byte_5D4594[816436] = 1;
            AIL_digital_handle_release(*(_DWORD*)& byte_5D4594[816432]);
        }
    }
}
// 581400: using guessed type int __stdcall AIL_digital_handle_release(_DWORD);

//----- (0043E910) --------------------------------------------------------
void sub_43E910(int a1)
{
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        if (*(_DWORD*)& byte_5D4594[816436])
        {
            AIL_digital_handle_reacquire(*(_DWORD*)& byte_5D4594[816432]);
            *(_DWORD*)& byte_5D4594[816436] = 0;
        }
    }
}
// 5813FC: using guessed type int __stdcall AIL_digital_handle_reacquire(_DWORD);

//----- (0043E940) --------------------------------------------------------
int __cdecl sub_43E940(int a1)
{
    int v1; // eax
    int result; // eax

    _onexit(sub_43E9C0);
    AIL_startup();
    v1 = AIL_register_timer(sub_43E9D0);
    *(_DWORD*)& byte_587000[93944] = v1;
    if (v1 == -1)
        return -2147221504;
    AIL_set_timer_frequency(v1, 30);
    AIL_start_timer(*(_DWORD*)& byte_587000[93944]);
    sub_42EBB0(1u, sub_43E910, 0, "Audio");
    sub_42EBB0(2u, sub_43E8E0, 0, "Audio");
    result = 0;
    *(_DWORD*)(a1 + 20) = 1;
    return result;
}
// 581398: using guessed type int __stdcall AIL_set_timer_frequency(_DWORD, _DWORD);
// 5813F8: using guessed type int __stdcall AIL_start_timer(_DWORD);
// 581420: using guessed type _DWORD __stdcall AIL_startup();
// 581424: using guessed type int __stdcall AIL_register_timer(_DWORD);

//----- (0043E9C0) --------------------------------------------------------
int __cdecl sub_43E9C0()
{
    sub_43E9F0();
    return 0;
}

//----- (0043E9D0) --------------------------------------------------------
_DWORD* __stdcall sub_43E9D0(int a1)
{
    sub_486EF0();
    sub_43D2D0();
    return sub_486620(*(_DWORD * *)& byte_587000[127004]);
}

//----- (0043E9F0) --------------------------------------------------------
void sub_43E9F0()
{
    if (*(int*)& byte_587000[93944] != -1)
    {
        AIL_stop_timer(*(_DWORD*)& byte_587000[93944]);
        AIL_release_timer_handle(*(_DWORD*)& byte_587000[93944]);
        *(_DWORD*)& byte_587000[93944] = -1;
    }
    AIL_shutdown();
}
// 5813D0: using guessed type int __stdcall AIL_release_timer_handle(_DWORD);
// 5813D4: using guessed type int __stdcall AIL_stop_timer(_DWORD);
// 5813F4: using guessed type _DWORD __stdcall AIL_shutdown();

//----- (0043EA20) --------------------------------------------------------
int __cdecl sub_43EA20(int a1)
{
    char v2[16]; // [esp+4h] [ebp-10h]

    sub_43EA90((int)v2, a1 + 60);
    AIL_set_preference(35, 125);
    *(_DWORD*)& byte_5D4594[816432] = sub_43EAD0((int)v2);
    if (!*(_DWORD*)& byte_5D4594[816432])
        return -2147221504;
    *(_DWORD*)& byte_587000[93948] = AIL_get_preference(42);
    *(_DWORD*)(a1 + 196) = 24;
    return 0;
}
// 5813BC: using guessed type int __stdcall AIL_get_preference(_DWORD);
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);

//----- (0043EA90) --------------------------------------------------------
int __cdecl sub_43EA90(int a1, int a2)
{
    int result; // eax

    result = a1;
    *(_WORD*)a1 = 1;
    *(_WORD*)(a1 + 2) = *(_WORD*)(a2 + 12);
    *(_DWORD*)(a1 + 4) = *(_DWORD*)(a2 + 8);
    *(_DWORD*)(a1 + 8) = *(_DWORD*)(a2 + 20);
    *(_WORD*)(a1 + 12) = *(_WORD*)(a2 + 16) * *(_WORD*)(a2 + 12);
    *(_WORD*)(a1 + 14) = 8 * *(_WORD*)(a2 + 16);
    return result;
}

//----- (0043EAD0) --------------------------------------------------------
int __cdecl sub_43EAD0(int a1)
{
    int v1; // eax
    unsigned int v2; // eax
    int v3; // ecx
    int v5; // [esp+10h] [ebp-88h]
    int v6; // [esp+14h] [ebp-84h]
    char v7[128]; // [esp+18h] [ebp-80h]

    v6 = *(_DWORD*)(a1 + 4);
    AIL_set_preference(15, 0);
    AIL_set_preference(33, 1);
    if (*(_DWORD*)(a1 + 4) < 0x2B11u)
        return 0;
    while (1)
    {
        while (1)
        {
            v1 = AIL_get_preference(15);
            if (!AIL_waveOutOpen(&v5, 0, -(v1 != 0), a1))
                break;
            AIL_last_error();
            if (!AIL_get_preference(15))
            {
                AIL_set_preference(15, 1);
                goto LABEL_11;
            }
            v2 = *(_DWORD*)(a1 + 4) >> 1;
            *(_DWORD*)(a1 + 4) = v2;
            if (v2 < 0x2B11)
            {
                if (*(_WORD*)(a1 + 14) == 8)
                {
                    v3 = v6;
                    *(_WORD*)(a1 + 14) = 8;
                    *(_DWORD*)(a1 + 4) = v3;
                }
                goto LABEL_11;
            }
        }
        strcpy(v7, "Device: ");
        AIL_digital_configuration(v5, 0, 0, &v7[strlen(v7)]);
        if (AIL_get_preference(15) || !strstr(v7, "Emulated"))
            return v5;
        AIL_waveOutClose(v5);
        AIL_set_preference(15, 1);
        AIL_set_preference(15, 1);
        LABEL_11:
        if (*(_DWORD*)(a1 + 4) < 0x2B11u)
            return 0;
    }
}
// 581390: using guessed type int __stdcall AIL_waveOutClose(_DWORD);
// 581394: using guessed type int __stdcall AIL_digital_configuration(_DWORD, _DWORD, _DWORD, _DWORD);
// 5813A4: using guessed type _DWORD __stdcall AIL_last_error();
// 5813BC: using guessed type int __stdcall AIL_get_preference(_DWORD);
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
// 581434: using guessed type int __stdcall AIL_waveOutOpen(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (0043EC10) --------------------------------------------------------
int sub_43EC10()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816432];
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        AIL_waveOutClose(*(_DWORD*)& byte_5D4594[816432]);
        *(_DWORD*)& byte_5D4594[816432] = 0;
    }
    return result;
}
// 581390: using guessed type int __stdcall AIL_waveOutClose(_DWORD);

//----- (0043EC30) --------------------------------------------------------
int __cdecl sub_43EC30(int a1)
{
    _DWORD* v1; // esi
    int v2; // eax

    v1 = nox_malloc(0x20u);
    memset(v1, 0, 0x20u);
    *(_DWORD*)(a1 + 272) = v1;
    v1[1] = a1;
    *v1 = *(_DWORD*)& byte_5D4594[816432];
    v1[5] = nox_malloc(0x4000u);
    v1[6] = nox_malloc(0x4000u);
    v2 = AIL_allocate_sample_handle(*(_DWORD*)& byte_5D4594[816432]);
    v1[2] = v2;
    if (!v2 || !v1[5] || !v1[6])
        return -2147221504;
    AIL_set_sample_user_data(v2, 0, v1);
    return 0;
}
// 58139C: using guessed type int __stdcall AIL_set_sample_user_data(_DWORD, _DWORD, _DWORD);
// 5813A0: using guessed type int __stdcall AIL_allocate_sample_handle(_DWORD);

//----- (0043ECB0) --------------------------------------------------------
int __cdecl sub_43ECB0(int a1)
{
    int v1; // esi

    v1 = *(_DWORD*)(a1 + 272);
    if (*(_DWORD*)(v1 + 8))
        AIL_release_sample_handle(*(_DWORD*)(v1 + 8));
    if (*(_DWORD*)(v1 + 20))
        free(*(LPVOID*)(v1 + 20));
    if (*(_DWORD*)(v1 + 24))
        free(*(LPVOID*)(v1 + 24));
    free((LPVOID)v1);
    return 0;
}
// 581438: using guessed type int __stdcall AIL_release_sample_handle(_DWORD);

//----- (0043ED00) --------------------------------------------------------
int __cdecl sub_43ED00(_DWORD* a1)
{
    _DWORD* v1; // esi
    int v2; // eax
    int v3; // eax
    int v4; // eax
    int v5; // ecx

    v1 = (_DWORD*)a1[68];
    AIL_init_sample(v1[2]);
    v2 = *(_DWORD*)(a1[72] + 20);
    v1[4] = v2;
    if (!v2)
        v1[4] = a1[33] + 60;
    v3 = sub_43F0E0((_DWORD*)v1[4]);
    AIL_set_sample_type(v1[2], v3, 0);
    v4 = v1[4];
    if (*(_DWORD*)(v4 + 4) == 2)
        AIL_set_sample_adpcm_block_size(v1[2], *(_DWORD*)(v4 + 24));
    sub_43F060(a1);
    v5 = v1[2];
    v1[7] = 0;
    v1[3] = 0;
    AIL_register_EOB_callback(v5, sub_43EDE0);
    AIL_register_EOS_callback(v1[2], sub_43EDB0);
    sub_43EE00((int)v1);
    return 0;
}
// 5813AC: using guessed type int __stdcall AIL_register_EOS_callback(_DWORD, _DWORD);
// 5813B0: using guessed type int __stdcall AIL_register_EOB_callback(_DWORD, _DWORD);
// 5813B4: using guessed type int __stdcall AIL_set_sample_adpcm_block_size(_DWORD, _DWORD);
// 5813B8: using guessed type int __stdcall AIL_set_sample_type(_DWORD, _DWORD, _DWORD);
// 5813F0: using guessed type int __stdcall AIL_init_sample(_DWORD);

//----- (0043EDB0) --------------------------------------------------------
int __stdcall sub_43EDB0(int a1)
{
    int v1; // eax
    int v2; // esi
    int result; // eax

    v1 = AIL_sample_user_data(a1, 0);
    v2 = v1;
    result = *(_DWORD*)(v1 + 28);
    if (!result)
    {
        result = (*(int(__cdecl * *)(_DWORD))(*(_DWORD*)(v2 + 4) + 284))(*(_DWORD*)(v2 + 4));
        *(_DWORD*)(v2 + 28) = 1;
    }
    return result;
}
// 5813A8: using guessed type int __stdcall AIL_sample_user_data(_DWORD, _DWORD);

//----- (0043EDE0) --------------------------------------------------------
int __stdcall sub_43EDE0(int a1)
{
    int v1; // eax

    v1 = AIL_sample_user_data(a1, 0);
    return sub_43EE00(v1);
}
// 5813A8: using guessed type int __stdcall AIL_sample_user_data(_DWORD, _DWORD);

//----- (0043EE00) --------------------------------------------------------
int __cdecl sub_43EE00(int a1)
{
    int v1; // esi
    int result; // eax
    int v3; // ebx
    int v4; // edi
    char* v5; // ebp
    unsigned int v6; // ecx
    signed int v7; // esi
    signed int v8; // eax
    char* v9; // esi
    char v10; // bp
    unsigned int v11; // ecx
    char* v12; // edi
    char* v13; // esi
    int v14; // ecx
    int v15; // edx
    int v16; // eax
    char* v17; // [esp+4h] [ebp-18h]
    signed int v18; // [esp+8h] [ebp-14h]
    char* v19; // [esp+Ch] [ebp-10h]
    int v20; // [esp+10h] [ebp-Ch]
    int v21; // [esp+14h] [ebp-8h]
    char* v22; // [esp+18h] [ebp-4h]

    v1 = a1;
    result = AIL_sample_buffer_ready(*(_DWORD*)(a1 + 8));
    v20 = result;
    if (result != -1)
    {
        while (1)
        {
            v3 = *(_DWORD*)(v1 + 4);
            v4 = 0;
            v5 = 0;
            v17 = *(char**)(v1 + 4 * v20 + 20);
            v6 = 0;
            v7 = 0;
            v21 = 0;
            v19 = 0;
            v18 = 0;
            if (!*(_DWORD*)(a1 + 12))
                break;
            LABEL_27:
            AIL_load_sample_buffer(*(_DWORD*)(a1 + 8), v20, v19, v4);
            result = AIL_sample_buffer_ready(*(_DWORD*)(a1 + 8));
            v20 = result;
            if (result == -1)
                return result;
            v1 = a1;
        }
        while (1)
        {
            if (v4 >= 0x4000)
                goto LABEL_27;
            v8 = *(_DWORD*)(v3 + 300);
            if (!v8)
            {
                (*(void(__cdecl * *)(int))(v3 + 276))(v3);
                v8 = *(_DWORD*)(v3 + 300);
                if (!v8)
                {
                    (*(void(__cdecl * *)(int))(v3 + 280))(v3);
                    v8 = *(_DWORD*)(v3 + 300);
                    if (!v8)
                    {
                        *(_DWORD*)(a1 + 12) = 1;
                        goto LABEL_27;
                    }
                }
                v6 = v18;
            }
            if (v4)
                break;
            v19 = *(char**)(v3 + 296);
            if (v8 < 0x4000 || v5)
                break;
            v7 = v8;
            LABEL_24:
            v15 = *(_DWORD*)(v3 + 304) - v7;
            *(_DWORD*)(v3 + 300) -= v7;
            v16 = v7 + *(_DWORD*)(v3 + 296);
            *(_DWORD*)(v3 + 304) = v15;
            *(_DWORD*)(v3 + 296) = v16;
            v4 += v7;
            v21 = v4;
            if (*(_DWORD*)(a1 + 12))
                goto LABEL_27;
        }
        if (v8 + v4 > 0x4000)
            v8 = 0x4000 - v4;
        if (!v8)
            goto LABEL_24;
        if (v5)
        {
            if (v6)
            {
                v9 = v5;
                v10 = v6;
                v11 = v6 >> 2;
                qmemcpy(v22, v9, 4 * v11);
                v13 = &v9[4 * v11];
                v12 = &v22[4 * v11];
                v19 = v22;
                v14 = v10 & 3;
                v5 = 0;
                qmemcpy(v12, v13, v14);
            }
        }
        else if (!v6)
        {
            v5 = *(char**)(v3 + 296);
            v22 = v17;
            v18 = v8;
            LABEL_23:
            v7 = v8;
            v17 += v8;
            v6 = v18;
            goto LABEL_24;
        }
        qmemcpy(v17, *(const void**)(v3 + 296), v8);
        v4 = v21;
        goto LABEL_23;
    }
    return result;
}
// 43EF03: variable 'v22' is possibly undefined
// 5813C4: using guessed type int __stdcall AIL_load_sample_buffer(_DWORD, _DWORD, _DWORD, _DWORD);
// 5813C8: using guessed type int __stdcall AIL_sample_buffer_ready(_DWORD);

//----- (0043EFD0) --------------------------------------------------------
int __cdecl sub_43EFD0(int a1)
{
    _DWORD* v1; // esi

    v1 = *(_DWORD * *)(a1 + 272);
    AIL_end_sample(v1[2]);
    if (!v1[7])
    {
        (*(void(__cdecl * *)(_DWORD))(v1[1] + 284))(v1[1]);
        v1[7] = 1;
    }
    return 0;
}
// 5813CC: using guessed type int __stdcall AIL_end_sample(_DWORD);

//----- (0043F010) --------------------------------------------------------
int __cdecl sub_43F010(int a1)
{
    AIL_stop_sample(*(_DWORD*)(*(_DWORD*)(a1 + 272) + 8));
    return 0;
}
// 581428: using guessed type int __stdcall AIL_stop_sample(_DWORD);

//----- (0043F030) --------------------------------------------------------
int __cdecl sub_43F030(int a1)
{
    AIL_resume_sample(*(_DWORD*)(*(_DWORD*)(a1 + 272) + 8));
    return 0;
}
// 58142C: using guessed type int __stdcall AIL_resume_sample(_DWORD);

//----- (0043F050) --------------------------------------------------------
int sub_43F050()
{
    return 0;
}

//----- (0043F060) --------------------------------------------------------
int __cdecl sub_43F060(_DWORD* a1)
{
    int v1; // esi
    int v2; // eax

    v1 = a1[68];
    AIL_set_sample_volume(*(_DWORD*)(v1 + 8), (unsigned int)(127 * (a1[45] >> 16)) >> 14);
    AIL_set_sample_pan(*(_DWORD*)(v1 + 8), (unsigned int)(127 * (a1[61] >> 16)) >> 14);
    v2 = sub_486640((int)(a1 + 44), *(_DWORD*)(*(_DWORD*)(v1 + 16) + 8));
    AIL_set_sample_playback_rate(*(_DWORD*)(v1 + 8), v2);
    return 0;
}
// 5813D8: using guessed type int __stdcall AIL_set_sample_playback_rate(_DWORD, _DWORD);
// 5813DC: using guessed type int __stdcall AIL_set_sample_pan(_DWORD, _DWORD);
// 5813E0: using guessed type int __stdcall AIL_set_sample_volume(_DWORD, _DWORD);

//----- (0043F0D0) --------------------------------------------------------
int sub_43F0D0()
{
    return 0;
}

//----- (0043F0E0) --------------------------------------------------------
int __cdecl sub_43F0E0(_DWORD* a1)
{
    int v1; // ecx
    int result; // eax
    int v3; // eax

    v1 = a1[1];
    if (v1)
    {
        if (v1 == 2)
        {
            v3 = -(a1[3] != 2);
            LOBYTE(v3) = v3 & 0xFE;
            result = v3 + 7;
        }
        else
        {
            result = 0;
        }
    }
    else if (a1[3] == 2)
    {
        result = (a1[4] == 2) + 2;
    }
    else
    {
        result = a1[4] == 2;
    }
    return result;
}

//----- (0043F130) --------------------------------------------------------
int sub_43F130()
{
    return *(_DWORD*)& byte_5D4594[816432];
}

//----- (0043F140) --------------------------------------------------------
void __cdecl sub_43F140(int a1)
{
    int result; // eax
    int v2; // esi

    if (*(_DWORD*)& byte_5D4594[816432])
    {
        result = AIL_get_preference(34);
        if (result)
        {
            v2 = a1 / result;
            if (a1 / result > 0)
            {
                if (v2 > AIL_get_preference(35))
                    v2 = AIL_get_preference(35);
                AIL_set_preference(42, v2);
                AIL_serve();
            }
            else
            {
                AIL_set_preference(42, *(_DWORD*)& byte_587000[93948]);
                AIL_serve();
            }
        }
    }
}
// 5813BC: using guessed type int __stdcall AIL_get_preference(_DWORD);
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
// 5813E4: using guessed type _DWORD __stdcall AIL_serve();

//----- (0043F1A0) --------------------------------------------------------
int sub_43F1A0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816432];
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        AIL_set_preference(42, *(_DWORD*)& byte_587000[93948]);
        AIL_serve();
    }
    return result;
}
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
// 5813E4: using guessed type _DWORD __stdcall AIL_serve();

//----- (0043F1C0) --------------------------------------------------------
int sub_43F1C0()
{
    int v0; // esi
    unsigned __int8* v1; // eax
    unsigned __int8* v2; // eax
    int v3; // ebp
    int v4; // edi
    int v5; // ebx

    v0 = 0;
    if (*(_DWORD*)& byte_5D4594[3801780])
    {
        if (*(_DWORD*)& byte_5D4594[3801780] == 1)
            * (_DWORD*)& byte_5D4594[816448] = sub_43FE90;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816448] = sub_440360;
    }
    *(_DWORD*)& byte_5D4594[816456] = 64;
    *(_DWORD*)& byte_5D4594[816484] = 1;
    *(_DWORD*)& byte_5D4594[816440] = 1;
    *(_DWORD*)& byte_5D4594[816460] = 0;
    *(_DWORD*)& byte_5D4594[816452] = 0;
    v1 = &byte_5D4594[816484];
    *(_DWORD*)& byte_5D4594[816444] = 0;
    do
    {
        v1 -= 4;
        *(_DWORD*)v1 = 0;
    } while (v1 != &byte_5D4594[816464]);
    if (*(_DWORD*)& byte_587000[26048] == 6 || (v2 = &byte_587000[94112], *(_DWORD*)& byte_587000[26048] == 8))
        v2 = &byte_587000[94176];
    *(_DWORD*)& byte_5D4594[816488] = v2;
    v3 = 0;
    do
    {
        if (*(_DWORD*)& v2[v0 + 4])
        {
            v4 = 0;
            if (v0 > 0)
            {
                v5 = 0;
                while (_strcmpi(*(const char**)& v2[v0 + 4], *(const char**)& v2[v5 + 4]))
                {
                    v2 = *(unsigned __int8**)& byte_5D4594[816488];
                    ++v4;
                    v5 += 12;
                    if (v4 >= v3)
                        goto LABEL_18;
                }
                *(_DWORD*)(v0 + *(_DWORD*)& byte_5D4594[816488] + 8) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[816488] + 12 * v4 + 8);
                v2 = *(unsigned __int8**)& byte_5D4594[816488];
            }
            LABEL_18:
            if (*(_DWORD*)& v2[v0 + 4] && !*(_DWORD*)& v2[v0 + 8])
            {
                *(_DWORD*)(v0 + *(_DWORD*)& byte_5D4594[816488] + 8) = sub_43F3B0(*(char**)& v2[v0 + 4]);
                v2 = *(unsigned __int8**)& byte_5D4594[816488];
            }
        }
        v0 += 12;
        ++v3;
    } while (v0 < 60);
    *(_DWORD*)& byte_5D4594[816492] = *((_DWORD*)v2 + 2);
    return 1;
}

//----- (0043F2E0) --------------------------------------------------------
void sub_43F2E0()
{
    int v0; // edi
    void** v1; // esi
    void* result; // eax
    bool v3; // zf

    v0 = 0;
    v1 = (void**)& byte_5D4594[816464];
    do
    {
        result = *v1;
        v3 = *v1 == 0;
        *(_DWORD*)(v0 + *(_DWORD*)& byte_5D4594[816488] + 8) = 0;
        if (!v3)
        {
            *v1 = 0;
            sub_440840(result);
        }
        ++v1;
        v0 += 12;
    } while ((int)v1 < (int)& byte_5D4594[816484]);
}

//----- (0043F320) --------------------------------------------------------
int __cdecl sub_43F320(int a1)
{
    int v1; // ecx
    int result; // eax

    v1 = a1;
    result = 0;
    if (a1 || (v1 = *(_DWORD*)& byte_5D4594[816492]) != 0)
        result = *(_DWORD*)(v1 + 28);
    return result;
}

//----- (0043F340) --------------------------------------------------------
int __cdecl sub_43F340(int* a1)
{
    int* v1; // ecx
    int result; // eax

    v1 = a1;
    result = 0;
    if (a1 || (v1 = *(int**)& byte_5D4594[816492]) != 0)
        result = *v1;
    return result;
}

//----- (0043F360) --------------------------------------------------------
int __cdecl sub_43F360(char* a1)
{
    int v1; // edi
    int v2; // esi
    const char* v3; // eax

    if (!*(_DWORD*)& byte_5D4594[816488])
        return 0;
    v1 = 0;
    v2 = 0;
    while (1)
    {
        v3 = *(const char**)(v2 + *(_DWORD*)& byte_5D4594[816488]);
        if (v3)
        {
            if (!_strcmpi(v3, a1))
                break;
        }
        v2 += 12;
        ++v1;
        if (v2 >= 60)
            return 0;
    }
    return *(_DWORD*)(*(_DWORD*)& byte_5D4594[816488] + 12 * v1 + 8);
}

//----- (0043F3B0) --------------------------------------------------------
_DWORD* __cdecl sub_43F3B0(char* a1)
{
    _DWORD* v1; // ebx
    FILE* v3; // ebp
    char* v4; // eax
    unsigned __int16 v5; // cx
    unsigned __int16 v6; // dx
    int v7; // eax
    unsigned __int8* v8; // eax
    size_t v9; // esi
    char* v10; // eax
    int v11; // ecx
    unsigned __int8* v12; // eax
    int v13; // eax
    _BYTE* v14; // eax
    _BYTE* v15; // esi
    _BYTE* v16; // eax
    int v17[7]; // [esp+4h] [ebp-68h]
    unsigned __int8 v18[76]; // [esp+20h] [ebp-4Ch]

    v1 = 0;
    if (*(int*)& byte_5D4594[816444] >= 5)
        return 0;
    v3 = fopen(a1, "rb");
    if (v3)
    {
        v1 = nox_malloc(0x20u);
        if (v1)
        {
            memset(v1, 0, 0x20u);
            if (sub_40ADD0_fread((char*)v17, 0x1Cu, 1u, v3) != 1)
                goto LABEL_15;
            if (v17[0] == 1181699700)
            {
                v1[2] = v17[4];
                v1[1] = v17[3];
                *v1 = v17[2];
                v1[5] = v17[6];
                v1[3] = v17[5];
                v4 = (char*)nox_malloc(8 * v17[5]);
                v1[4] = v4;
                if (!v4 || sub_40ADD0_fread(v4, 8 * v1[3], 1u, v3) != 1)
                    goto LABEL_15;
            }
            else
            {
                fseek(v3, 0, 0);
                if (sub_40ADD0_fread((char*)v18, 0x4Cu, 1u, v3) != 1)
                    goto LABEL_15;
                v5 = *(_WORD*)& v18[2];
                v6 = *(_WORD*)v18;
                v1[2] = *(unsigned __int16*)& v18[4];
                v1[5] = *(_DWORD*)& v18[72];
                v7 = *(unsigned __int16*)& v18[6];
                v1[1] = v5;
                *v1 = v6;
                v1[3] = v7;
                v8 = (unsigned __int8*)nox_malloc(8 * v7);
                v1[4] = v8;
                if (!v8)
                    goto LABEL_15;
                qmemcpy(v8, &v18[8], 8 * v1[3]);
            }
            v1[7] = v1[2];
            v9 = v1[5] * sub_440870((int)v1);
            v10 = (char*)nox_malloc(v9);
            v1[6] = v10;
            if (!v10 || sub_40ADD0_fread(v10, v9, 1u, v3) != 1)
            {
                LABEL_15:
                sub_440840(v1);
                fclose(v3);
                return 0;
            }
            v11 = 0;
            v12 = &byte_5D4594[816464];
            while (*(_DWORD*)v12)
            {
                v12 += 4;
                ++v11;
                if ((int)v12 >= (int)& byte_5D4594[816484])
                    goto LABEL_21;
            }
            v13 = *(_DWORD*)& byte_5D4594[816444];
            *(_DWORD*)& byte_5D4594[4 * v11 + 816464] = v1;
            *(_DWORD*)& byte_5D4594[816444] = v13 + 1;
            LABEL_21:
            if (*(unsigned __int8**)& byte_5D4594[816488] == &byte_587000[94176])
            {
                ++v1[7];
                v14 = (_BYTE*)sub_43FE30((int)v1, 0x20u);
                v15 = v14;
                if (v14 && *(_DWORD*)& byte_587000[26048] == 8)
                    ++* v14;
                if (*(_DWORD*)& byte_587000[26048] == 6)
                {
                    v16 = (_BYTE*)sub_43FE30((int)v1, 0x3000u);
                    if (v16)
                    {
                        if (v15)
                        {
                            *v16 = 2 * *v15;
                            fclose(v3);
                            return v1;
                        }
                        *v16 = *(_BYTE*)v1;
                    }
                }
            }
        }
        fclose(v3);
    }
    return v1;
}

//----- (0043F620) --------------------------------------------------------
int __cdecl sub_43F620(LPVOID lpMem)
{
    int v1; // ecx
    LPVOID* v2; // eax

    if (!lpMem)
        return 0;
    v1 = 0;
    v2 = (LPVOID*)& byte_5D4594[816464];
    while (*v2 != lpMem)
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[816484])
            return 0;
    }
    *(_DWORD*)& byte_5D4594[4 * v1 + 816464] = 0;
    sub_440840(lpMem);
    --* (_DWORD*)& byte_5D4594[816444];
    return 1;
}

//----- (0043F670) --------------------------------------------------------
int __cdecl sub_43F670(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816452];
    *(_DWORD*)& byte_5D4594[816452] = a1;
    return result;
}

//----- (0043F680) --------------------------------------------------------
int __cdecl sub_43F680(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816484];
    *(_DWORD*)& byte_5D4594[816484] = a1;
    return result;
}

//----- (0043F690) --------------------------------------------------------
int __cdecl sub_43F690(int a1, int a2, int a3, int a4)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    result = a1;
    if (a1 || (result = *(_DWORD*)& byte_5D4594[816492]) != 0)
    {
        *(_DWORD*)& byte_5D4594[816460] = a3;
        result = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(result, a2, a3, a4);
    }
    return result;
}

//----- (0043F6E0) --------------------------------------------------------
int __cdecl sub_43F6E0(int a1, __int16* a2, int a3, int a4)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    result = a1;
    if (a1 || (result = *(_DWORD*)& byte_5D4594[816492]) != 0)
    {
        *(_DWORD*)& byte_5D4594[816460] = a3;
        result = sub_4407F0(result, a2, a3, a4);
    }
    return result;
}

//----- (0043F730) --------------------------------------------------------
int __cdecl sub_43F730(int a1, __int16* a2, int a3, int a4)
{
    int v5; // edi
    int v6; // ebx

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    v5 = a1;
    if (!a1)
    {
        v5 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    *(_DWORD*)& byte_5D4594[816460] = a3;
    v6 = ptr_5D4594_3799572->data[59];
    sub_434390(ptr_5D4594_3799572->data[60]);
    sub_4407F0(v5, a2, a3 + 1, a4 + 1);
    sub_434390(v6);
    return sub_4407F0(v5, a2, a3, a4);
}

//----- (0043F7B0) --------------------------------------------------------
int __cdecl sub_43F7B0(int a1, __int16* a2, int a3, int a4)
{
    int result; // eax
    int v5; // esi

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    v5 = a1;
    if (!a1)
    {
        v5 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    *(_DWORD*)& byte_5D4594[816460] = a3;
    if (!*(_DWORD*)& byte_5D4594[816484])
        return sub_4407F0(v5, a2, a3, a4);
    *(_DWORD*)& byte_5D4594[816440] = 2;
    sub_4407F0(v5, a2, a3, a4);
    result = sub_4407F0(v5, a2, a3 + 1, a4);
    *(_DWORD*)& byte_5D4594[816440] = 1;
    return result;
}

//----- (0043F840) --------------------------------------------------------
int __cdecl sub_43F840(int a1, unsigned __int16* a2, int* a3, _DWORD* a4, int a5)
{
    unsigned __int16 v5; // cx
    unsigned __int16 v6; // bp
    int v7; // ebx
    int v8; // esi
    unsigned __int16* v9; // edi
    unsigned __int8* v10; // eax
    int v11; // eax
    int v12; // esi
    int result; // eax
    unsigned __int16* i; // [esp+4h] [ebp-8h]
    int v15; // [esp+8h] [ebp-4h]
    int v16; // [esp+14h] [ebp+8h]

    v5 = 0;
    if ((a1 || (a1 = *(_DWORD*)& byte_5D4594[816492]) != 0) && a2)
    {
        v6 = *a2;
        v7 = 0;
        v8 = 0;
        v9 = a2 + 1;
        v16 = *(_DWORD*)(a1 + 28);
        for (i = 0; v6; ++v9)
        {
            switch (v6)
            {
                case 9u:
                    v8 = *(_DWORD*)& byte_5D4594[816456]
                         + v8
                         - (*(_DWORD*)& byte_5D4594[816456] + v8) % *(_DWORD*)& byte_5D4594[816456];
                    break;
                case 0xAu:
                case 0xDu:
                    if (v5 != 13)
                        goto LABEL_7;
                    break;
                case 0x20u:
                    v15 = v7;
                    i = v9;
                    goto LABEL_10;
                default:
                LABEL_10:
                    v10 = (unsigned __int8*)sub_43FE30(a1, v6);
                    if (v10 || (v10 = (unsigned __int8*)sub_43FE30(a1, 0x3Fu)) != 0)
                    {
                        v11 = *v10;
                        v8 += v11 + *(_DWORD*)& byte_5D4594[816440];
                        if (a5 && v8 > a5)
                        {
                            if (i)
                            {
                                v7 = v15;
                                v9 = i;
                                i = 0;
                            }
                            else
                            {
                                --v9;
                                v12 = v8 - (*(_DWORD*)& byte_5D4594[816440] + v11);
                                if (v12 > v7)
                                    v7 = v12;
                            }
                            LABEL_7:
                            v8 = 0;
                            v16 += *(_DWORD*)(a1 + 28);
                        }
                        else if (v8 > v7)
                        {
                            v7 = v8;
                        }
                    }
                    break;
            }
            v5 = v6;
            v6 = *v9;
        }
        if (a3)
            * a3 = v7;
        if (a4)
            * a4 = v16;
        result = 1;
    }
    else
    {
        if (a4)
            * a4 = 0;
        if (a3)
            * a3 = 0;
        result = 0;
    }
    return result;
}
// 43F936: variable 'v15' is possibly undefined

//----- (0043F9E0) --------------------------------------------------------
int __cdecl sub_43F9E0(int a1, unsigned __int16* a2, int a3)
{
    int v3; // ebx
    int v4; // ebp
    int v5; // edi
    unsigned __int16 v6; // cx
    unsigned __int16* i; // esi
    unsigned __int8* v8; // eax

    v3 = a1;
    v4 = 0;
    v5 = 0;
    if (!a1)
    {
        v3 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    if (!a2)
        return 0;
    v6 = *a2;
    for (i = a2 + 1; v6; ++i)
    {
        if (v6 == 9)
        {
            v5 = *(_DWORD*)& byte_5D4594[816456]
                 + v5
                 - (*(_DWORD*)& byte_5D4594[816456] + v5) % *(_DWORD*)& byte_5D4594[816456];
        }
        else if (v6 != 10 && v6 != 13)
        {
            v8 = (unsigned __int8*)sub_43FE30(v3, v6);
            if (v8 || (v8 = (unsigned __int8*)sub_43FE30(v3, 0x3Fu)) != 0)
                v5 += *(_DWORD*)& byte_5D4594[816440] + *v8;
        }
        if (v5 > a3)
            break;
        v6 = *i;
        ++v4;
    }
    return v4;
}

//----- (0043FA80) --------------------------------------------------------
int __cdecl sub_43FA80(int a1, unsigned __int16* a2, int* a3, _DWORD* a4, int a5)
{
    int result; // eax

    if (!*(_DWORD*)& byte_5D4594[816484])
        return sub_43F840(a1, a2, a3, a4, a5);
    *(_DWORD*)& byte_5D4594[816440] = 2;
    result = sub_43F840(a1, a2, a3, a4, a5);
    *(_DWORD*)& byte_5D4594[816440] = 1;
    return result;
}

//----- (0043FAF0) --------------------------------------------------------
int __cdecl sub_43FAF0(int a1, _WORD* a2, int a3, int a4, int a5, int a6)
{
    int v7; // ebx
    int v8; // ecx
    _WORD* v9; // edi
    int v10; // eax
    int v11; // ebp
    bool v12; // zf
    _WORD* v13; // esi
    int v14; // eax
    int i; // eax
    int v16; // ebp
    int v17; // ecx
    int j; // eax
    int v19; // eax
    _WORD* v20; // [esp+10h] [ebp-4h]
    int v21; // [esp+18h] [ebp+4h]
    int v22; // [esp+1Ch] [ebp+8h]

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    v7 = a1;
    v8 = 0;
    if (!a1)
    {
        v7 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    v9 = a2;
    if (!a2)
        return 0;
    HIWORD(v10) = HIWORD(a3);
    v11 = 0;
    *(_DWORD*)& byte_5D4594[816460] = a3;
    LOWORD(v10) = *a2;
    v12 = *a2 == 0;
    v21 = 0;
    v13 = a2;
    v20 = 0;
    v22 = v10;
    if (!v12)
    {
        while (2)
        {
            v14 = (unsigned __int16)v22 - 9;
            switch ((unsigned __int16)v22)
            {
                case 9u:
                    v16 = *(_DWORD*)& byte_5D4594[816456] + v11;
                    v14 = v16 / *(_DWORD*)& byte_5D4594[816456];
                    v11 = v16 - v16 % *(_DWORD*)& byte_5D4594[816456];
                    goto LABEL_31;
                case 0xAu:
                case 0xDu:
                    if ((_WORD)v8 == 13)
                        goto LABEL_14;
                    for (i = a3;
                         v13 < v9;
                         i = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(v7, v8, i, a4))
                    {
                        LOWORD(v8) = *v13;
                        ++v13;
                    }
                    v14 = *(_DWORD*)(v7 + 28);
                    v11 = 0;
                    v21 += v14;
                    if (a6 && v21 >= a6)
                        return 1;
                    a4 += v14;
                LABEL_14:
                    ++v13;
                    goto LABEL_31;
                case 0x20u:
                    v20 = v9;
                    goto LABEL_17;
                default:
                LABEL_17:
                    v14 = sub_43FE30(v7, v22);
                    if (!v14)
                    {
                        v14 = sub_43FE30(v7, 0x3Fu);
                        if (!v14)
                            goto LABEL_31;
                    }
                    v17 = *(_DWORD*)& byte_5D4594[816440] + *(unsigned __int8*)v14;
                    HIWORD(v14) = HIWORD(a5);
                    v11 += v17;
                    if (!a5 || v11 <= a5)
                        goto LABEL_31;
                    if (v20)
                        v9 = v20;
                    else
                        --v9;
                    for (j = a3;
                         v13 < v9;
                         j = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(v7, v17, j, a4))
                    {
                        LOWORD(v17) = *v13;
                        ++v13;
                    }
                    if (v20)
                    {
                        v20 = 0;
                        ++v13;
                    }
                    v14 = *(_DWORD*)(v7 + 28);
                    v11 = 0;
                    v21 += v14;
                    if (a6 && v21 >= a6)
                        return 1;
                    a4 += v14;
                LABEL_31:
                    LOWORD(v14) = v9[1];
                    v8 = v22;
                    ++v9;
                    v22 = v14;
                    if ((_WORD)v14)
                        continue;
                    if (v13 < v9)
                    {
                        v19 = a3;
                        do
                        {
                            LOWORD(v8) = *v13;
                            ++v13;
                            v19 = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(v7, v8, v19, a4);
                        } while (v13 < v9);
                    }
                    break;
            }
            break;
        }
    }
    return 1;
}
// 43FB91: variable 'v8' is possibly undefined
// 43FC42: variable 'v17' is possibly undefined

//----- (0043FD00) --------------------------------------------------------
int __cdecl sub_43FD00(int a1, _WORD* a2, int a3, int a4, int a5, int a6)
{
    int v7; // edi

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    *(_DWORD*)& byte_5D4594[816460] = a3;
    v7 = ptr_5D4594_3799572->data[59];
    sub_434390(ptr_5D4594_3799572->data[60]);
    sub_43FAF0(a1, a2, a3 + 1, a4 + 1, a5, a6);
    sub_434390(v7);
    return sub_43FAF0(a1, a2, a3, a4, a5, a6);
}

//----- (0043FD80) --------------------------------------------------------
int __cdecl sub_43FD80(int a1, _WORD* a2, int a3, int a4, int a5, int a6)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    *(_DWORD*)& byte_5D4594[816460] = a3;
    if (!*(_DWORD*)& byte_5D4594[816484])
        return sub_43FAF0(a1, a2, a3, a4, a5, a6);
    *(_DWORD*)& byte_5D4594[816440] = 2;
    sub_43FAF0(a1, a2, a3, a4, a5, a6);
    result = sub_43FAF0(a1, a2, a3 + 1, a4, a5, a6);
    *(_DWORD*)& byte_5D4594[816440] = 1;
    return result;
}

//----- (0043FE20) --------------------------------------------------------
int __cdecl sub_43FE20(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816456];
    *(_DWORD*)& byte_5D4594[816456] = a1;
    return result;
}

//----- (0043FE30) --------------------------------------------------------
int __cdecl sub_43FE30(int a1, unsigned __int16 a2)
{
    int v2; // edx
    int result; // eax
    int v4; // esi

    v2 = *(_DWORD*)(a1 + 16);
    result = 0;
    v4 = 0;
    if ((int) * (unsigned __int16*)(a1 + 12) > 0)
    {
        while (a2 < *(_WORD*)(v2 + 4) || a2 > * (_WORD*)(v2 + 6))
        {
            v2 += 8;
            if (++v4 >= *(unsigned __int16*)(a1 + 12))
                return result;
        }
        result = *(_DWORD*)(a1 + 24) + *(_DWORD*)(a1 + 20) * (*(_DWORD*)v2 + a2 - *(unsigned __int16*)(v2 + 4));
    }
    return result;
}

//----- (0043FE90) --------------------------------------------------------
int __cdecl sub_43FE90(int a1, __int16 a2, int xLeft, int yTop)
{
    int v4; // edx
    int v5; // ebp
    int v7; // edi
    unsigned __int8* v8; // eax
    __int16 v9; // ax
    int v10; // esi
    int v11; // ebx
    int v12; // ebp
    int v13; // edi
    int v14; // ebx
    int v15; // edx
    int v16; // ebp
    int v17; // esi
    _WORD* v18; // eax
    char* v19; // ebp
    int v20; // ecx
    char v21; // dl
    _WORD* v22; // eax
    int v23; // ecx
    int v24; // esi
    _WORD* v25; // eax
    int v26; // ecx
    int v27; // esi
    _WORD* v28; // eax
    int v29; // ecx
    int v30; // esi
    _WORD* v31; // eax
    int v32; // ecx
    int v33; // esi
    _WORD* v34; // eax
    int v35; // ecx
    int v36; // esi
    _WORD* v37; // eax
    int v38; // ecx
    int v39; // esi
    _WORD* v40; // eax
    int v41; // ecx
    int v42; // esi
    bool v43; // zf
    int v44; // eax
    int v45; // esi
    int v46; // edi
    char* v47; // esi
    _WORD* v48; // eax
    int v49; // ecx
    char v50; // dl
    _WORD* v51; // eax
    int v52; // ecx
    _WORD* v53; // eax
    int v54; // ecx
    _WORD* v55; // eax
    int v56; // ecx
    _WORD* v57; // eax
    int v58; // ecx
    _WORD* v59; // eax
    int v60; // ecx
    _WORD* v61; // eax
    int v62; // ecx
    _WORD* v63; // eax
    int v64; // ecx
    int v65; // [esp+10h] [ebp-38h]
    int v66; // [esp+10h] [ebp-38h]
    int v67; // [esp+14h] [ebp-34h]
    int v68; // [esp+18h] [ebp-30h]
    int v69; // [esp+18h] [ebp-30h]
    int v70; // [esp+1Ch] [ebp-2Ch]
    int v71; // [esp+24h] [ebp-24h]
    int4 v72; // [esp+28h] [ebp-20h]
    RECT rc; // [esp+38h] [ebp-10h]

    v5 = yTop;
    v71 = yTop;
    if (a2 == 9)
        return *(_DWORD*)& byte_5D4594[816456]
               + xLeft
               - (*(_DWORD*)& byte_5D4594[816456] + xLeft - *(_DWORD*)& byte_5D4594[816460]) % *(_DWORD*)& byte_5D4594[816456];
    v7 = a1;
    LOWORD(v4) = *(_WORD*)(&ptr_5D4594_3799572->data[59]);
    yTop = v4;
    v8 = (unsigned __int8*)sub_43FE30(a1, a2);
    if (!v8)
    {
        v9 = sub_4408A0(&yTop);
        a2 = v9;
        v8 = (unsigned __int8*)sub_43FE30(a1, v9);
        if (!v8)
            return xLeft;
    }
    v10 = *(_DWORD*)(a1 + 8);
    v11 = xLeft;
    v65 = (int)(v8 + 1);
    v67 = *v8;
    if (!ptr_5D4594_3799572->data[0])
        goto LABEL_102;
    SetRect(&rc, xLeft, v5, xLeft + *v8, v10 + v5);
    if (!sub_49F930(&v72, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1])))
        return v11 + *(_DWORD*)& byte_5D4594[816440] + v67;
    if (rc.left == v72.field_0 && rc.right == v72.field_8 && rc.top == v72.field_4 && rc.bottom == v72.field_C)
    {
        LABEL_102:
        v44 = v10;
        v45 = v10 - 1;
        if (v44)
        {
            v46 = 4 * v5;
            v69 = v45 + 1;
            while (1)
            {
                v47 = (char*)v65;
                v48 = (_WORD*)(2 * v11 + *(_DWORD*)(v46 + *(_DWORD*)& byte_5D4594[3798784]));
                v49 = v67;
                v46 += 4;
                while (1)
                {
                    v50 = *v47++;
                    if (v50)
                        break;
                    v48 += 8;
                    v49 -= 8;
                    LABEL_92:
                    if (v49 <= 0)
                        goto LABEL_95;
                }
                if (v50 < 0)
                    * v48 = yTop;
                v51 = v48 + 1;
                v52 = v49 - 1;
                if (v52 > 0)
                {
                    if (v50 & 0x40)
                        * v51 = yTop;
                    v53 = v51 + 1;
                    v54 = v52 - 1;
                    if (v54 > 0)
                    {
                        if (v50 & 0x20)
                            * v53 = yTop;
                        v55 = v53 + 1;
                        v56 = v54 - 1;
                        if (v56 > 0)
                        {
                            if (v50 & 0x10)
                                * v55 = yTop;
                            v57 = v55 + 1;
                            v58 = v56 - 1;
                            if (v58 > 0)
                            {
                                if (v50 & 8)
                                    * v57 = yTop;
                                v59 = v57 + 1;
                                v60 = v58 - 1;
                                if (v60 > 0)
                                {
                                    if (v50 & 4)
                                        * v59 = yTop;
                                    v61 = v59 + 1;
                                    v62 = v60 - 1;
                                    if (v62 > 0)
                                    {
                                        if (v50 & 2)
                                            * v61 = yTop;
                                        v63 = v61 + 1;
                                        v64 = v62 - 1;
                                        if (v64 > 0)
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }
                v11 = xLeft;
                LABEL_95:
                v43 = v69 == 1;
                v65 += *(_DWORD*)(a1 + 4);
                --v69;
                if (v43)
                {
                    v7 = a1;
                    goto LABEL_97;
                }
            }
            if (v50 & 1)
                * v63 = yTop;
            v11 = xLeft;
            v48 = v63 + 1;
            v49 = v64 - 1;
            goto LABEL_92;
        }
        LABEL_97:
        if (*(_DWORD*)& byte_5D4594[816452])
        {
            sub_49D190(ptr_5D4594_3799572->data[59], v11, v5, v67, *(_DWORD*)(v7 + 8));
            *(_DWORD*)& byte_5D4594[816452] = 0;
            sub_43FE90(v7, a2, v11, v5);
            *(_DWORD*)& byte_5D4594[816452] = 1;
        }
        return v11 + *(_DWORD*)& byte_5D4594[816440] + v67;
    }
    v12 = v72.field_4 - rc.top + v5;
    v66 = *(_DWORD*)(a1 + 4) * (v72.field_4 - rc.top) + v65;
    v13 = ptr_5D4594_3799572->data[1];
    v14 = ptr_5D4594_3799572->data[3];
    if (v72.field_C == v72.field_4)
        goto LABEL_60;
    v15 = xLeft;
    v16 = 4 * v12;
    v68 = v72.field_C - v72.field_4;
    while (2)
    {
        v17 = v67;
        v18 = (_WORD*)(2 * v15 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v16));
        v70 = v16 + 4;
        v19 = (char*)v66;
        v20 = v15;
        while (1)
        {
            v21 = *v19++;
            if (v21)
                break;
            v18 += 8;
            v17 -= 8;
            v20 += 8;
            LABEL_58:
            if (v17 <= 0)
                goto LABEL_59;
        }
        if (v20 >= v13 && v20 < v14 && v21 < 0)
            * v18 = yTop;
        v22 = v18 + 1;
        v23 = v20 + 1;
        v24 = v17 - 1;
        if (v24 > 0)
        {
            if (v23 >= v13 && v23 < v14 && v21 & 0x40)
                * v22 = yTop;
            v25 = v22 + 1;
            v26 = v23 + 1;
            v27 = v24 - 1;
            if (v27 > 0)
            {
                if (v26 >= v13 && v26 < v14 && v21 & 0x20)
                    * v25 = yTop;
                v28 = v25 + 1;
                v29 = v26 + 1;
                v30 = v27 - 1;
                if (v30 > 0)
                {
                    if (v29 >= v13 && v29 < v14 && v21 & 0x10)
                        * v28 = yTop;
                    v31 = v28 + 1;
                    v32 = v29 + 1;
                    v33 = v30 - 1;
                    if (v33 > 0)
                    {
                        if (v32 >= v13 && v32 < v14 && v21 & 8)
                            * v31 = yTop;
                        v34 = v31 + 1;
                        v35 = v32 + 1;
                        v36 = v33 - 1;
                        if (v36 > 0)
                        {
                            if (v35 >= v13 && v35 < v14 && v21 & 4)
                                * v34 = yTop;
                            v37 = v34 + 1;
                            v38 = v35 + 1;
                            v39 = v36 - 1;
                            if (v39 > 0)
                            {
                                if (v38 >= v13 && v38 < v14 && v21 & 2)
                                    * v37 = yTop;
                                v40 = v37 + 1;
                                v41 = v38 + 1;
                                v42 = v39 - 1;
                                if (v42 > 0)
                                {
                                    if (v41 >= v13 && v41 < v14 && v21 & 1)
                                        * v40 = yTop;
                                    v18 = v40 + 1;
                                    v20 = v41 + 1;
                                    v17 = v42 - 1;
                                    goto LABEL_58;
                                }
                            }
                        }
                    }
                }
            }
        }
        LABEL_59:
        v43 = v68 == 1;
        v66 += *(_DWORD*)(a1 + 4);
        --v68;
        if (!v43)
        {
            v15 = xLeft;
            v16 = v70;
            continue;
        }
        break;
    }
    LABEL_60:
    if (*(_DWORD*)& byte_5D4594[816452])
    {
        sub_49D190(ptr_5D4594_3799572->data[59], xLeft, v71, v67, v72.field_C - v72.field_4);
        *(_DWORD*)& byte_5D4594[816452] = 0;
        sub_43FE90(a1, a2, xLeft, v71);
        *(_DWORD*)& byte_5D4594[816452] = 1;
    }
    return xLeft + *(_DWORD*)& byte_5D4594[816440] + v67;
}
// 43FEE1: variable 'v4' is possibly undefined

//----- (00440360) --------------------------------------------------------
int __cdecl sub_440360(int a1, int a2, int xLeft, int yTop)
{
    unsigned __int8* v5; // eax
    int v6; // eax
    int v7; // esi
    int v8; // ebx
    int v9; // ecx
    int v10; // eax
    int v11; // edi
    int v12; // ebp
    int v13; // ebx
    int v14; // edi
    int v15; // esi
    int v16; // ecx
    _BYTE* v17; // eax
    char* v18; // edi
    char v19; // dl
    _BYTE* v20; // eax
    int v21; // ecx
    int v22; // esi
    _BYTE* v23; // eax
    int v24; // ecx
    int v25; // esi
    _BYTE* v26; // eax
    int v27; // ecx
    int v28; // esi
    _BYTE* v29; // eax
    int v30; // ecx
    int v31; // esi
    _BYTE* v32; // eax
    int v33; // ecx
    int v34; // esi
    _BYTE* v35; // eax
    int v36; // ecx
    int v37; // esi
    _BYTE* v38; // eax
    int v39; // ecx
    int v40; // esi
    bool v41; // zf
    int v42; // edi
    int v43; // eax
    int v44; // esi
    int v45; // ebp
    int v46; // esi
    char* v47; // edi
    int v48; // ecx
    _BYTE* v49; // eax
    char v50; // dl
    _BYTE* v51; // eax
    int v52; // ecx
    _BYTE* v53; // eax
    int v54; // ecx
    _BYTE* v55; // eax
    int v56; // ecx
    _BYTE* v57; // eax
    int v58; // ecx
    _BYTE* v59; // eax
    int v60; // ecx
    _BYTE* v61; // eax
    int v62; // ecx
    _BYTE* v63; // eax
    int v64; // ecx
    char v65; // [esp+13h] [ebp-35h]
    char* v66; // [esp+14h] [ebp-34h]
    int v67; // [esp+18h] [ebp-30h]
    int v68; // [esp+1Ch] [ebp-2Ch]
    int v69; // [esp+20h] [ebp-28h]
    int v70; // [esp+24h] [ebp-24h]
    int4 v71; // [esp+28h] [ebp-20h]
    RECT rc; // [esp+38h] [ebp-10h]
    int yTopa; // [esp+58h] [ebp+10h]

    v70 = yTop;
    if ((_WORD)a2 == 9)
        return *(_DWORD*)& byte_5D4594[816456]
               + xLeft
               - (*(_DWORD*)& byte_5D4594[816456] + xLeft - *(_DWORD*)& byte_5D4594[816460]) % *(_DWORD*)& byte_5D4594[816456];
    v65 = *(_BYTE*)(&ptr_5D4594_3799572->data[59]);
    v5 = (unsigned __int8*)sub_43FE30(a1, a2);
    if (!v5)
    {
        LOWORD(v6) = sub_4408C0(&v65);
        a2 = v6;
        v5 = (unsigned __int8*)sub_43FE30(a1, v6);
        if (!v5)
            return xLeft;
    }
    v7 = *(_DWORD*)(a1 + 8);
    v8 = *v5;
    v9 = (int)(v5 + 1);
    v10 = ptr_5D4594_3799572->data[0];
    v66 = (char*)v9;
    v67 = v8;
    if (!v10)
        goto LABEL_100;
    SetRect(&rc, xLeft, yTop, v8 + xLeft, v7 + yTop);
    if (!sub_49F930(&v71, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1])))
        return xLeft + v8 + *(_DWORD*)& byte_5D4594[816440];
    if (rc.left == v71.field_0 && rc.right == v71.field_8 && rc.top == v71.field_4 && rc.bottom == v71.field_C)
    {
        LABEL_100:
        v43 = v7;
        v44 = v7 - 1;
        if (!v43)
        {
            LABEL_95:
            if (*(_DWORD*)& byte_5D4594[816452])
            {
                sub_49D190(ptr_5D4594_3799572->data[59], xLeft, yTop, v67, *(_DWORD*)(a1 + 8));
                *(_DWORD*)& byte_5D4594[816452] = 0;
                sub_440360(a1, a2, xLeft, yTop);
                *(_DWORD*)& byte_5D4594[816452] = 1;
            }
            return xLeft + *(_DWORD*)& byte_5D4594[816440] + v67;
        }
        v45 = 4 * yTop;
        v46 = v44 + 1;
        LABEL_66:
        v47 = v66;
        v48 = v67;
        v49 = (_BYTE*)(xLeft + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v45));
        v45 += 4;
        while (1)
        {
            v50 = *v47++;
            if (v50)
            {
                if (v50 < 0)
                    * v49 = v65;
                v51 = v49 + 1;
                v52 = v48 - 1;
                if (v52 <= 0)
                    goto LABEL_94;
                if (v50 & 0x40)
                    * v51 = v65;
                v53 = v51 + 1;
                v54 = v52 - 1;
                if (v54 <= 0)
                    goto LABEL_94;
                if (v50 & 0x20)
                    * v53 = v65;
                v55 = v53 + 1;
                v56 = v54 - 1;
                if (v56 <= 0)
                    goto LABEL_94;
                if (v50 & 0x10)
                    * v55 = v65;
                v57 = v55 + 1;
                v58 = v56 - 1;
                if (v58 <= 0)
                    goto LABEL_94;
                if (v50 & 8)
                    * v57 = v65;
                v59 = v57 + 1;
                v60 = v58 - 1;
                if (v60 <= 0)
                    goto LABEL_94;
                if (v50 & 4)
                    * v59 = v65;
                v61 = v59 + 1;
                v62 = v60 - 1;
                if (v62 <= 0)
                    goto LABEL_94;
                if (v50 & 2)
                    * v61 = v65;
                v63 = v61 + 1;
                v64 = v62 - 1;
                if (v64 <= 0)
                {
                    LABEL_94:
                    --v46;
                    v66 += *(_DWORD*)(a1 + 4);
                    if (!v46)
                        goto LABEL_95;
                    goto LABEL_66;
                }
                if (v50 & 1)
                    * v63 = v65;
                v49 = v63 + 1;
                v48 = v64 - 1;
            }
            else
            {
                v49 += 8;
                v48 -= 8;
            }
            if (v48 <= 0)
                goto LABEL_94;
        }
    }
    v11 = v71.field_4 - rc.top + yTop;
    v66 += *(_DWORD*)(a1 + 4) * (v71.field_4 - rc.top);
    v12 = ptr_5D4594_3799572->data[1];
    v13 = ptr_5D4594_3799572->data[3];
    yTopa = ptr_5D4594_3799572->data[3];
    if (v71.field_C == v71.field_4)
        goto LABEL_61;
    v14 = 4 * v11;
    v68 = v71.field_C - v71.field_4;
    while (2)
    {
        v15 = v67;
        v16 = xLeft;
        v17 = (_BYTE*)(xLeft + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784]));
        v69 = v14 + 4;
        v18 = v66;
        while (1)
        {
            v19 = *v18++;
            if (v19)
                break;
            v17 += 8;
            v15 -= 8;
            v16 += 8;
            LABEL_59:
            if (v15 <= 0)
                goto LABEL_60;
        }
        if (v16 >= v12 && v16 < v13 && v19 < 0)
        {
            *v17 = v65;
            v13 = yTopa;
        }
        v20 = v17 + 1;
        v21 = v16 + 1;
        v22 = v15 - 1;
        if (v22 > 0)
        {
            if (v21 >= v12 && v21 < v13 && v19 & 0x40)
            {
                *v20 = v65;
                v13 = yTopa;
            }
            v23 = v20 + 1;
            v24 = v21 + 1;
            v25 = v22 - 1;
            if (v25 > 0)
            {
                if (v24 >= v12 && v24 < v13 && v19 & 0x20)
                {
                    *v23 = v65;
                    v13 = yTopa;
                }
                v26 = v23 + 1;
                v27 = v24 + 1;
                v28 = v25 - 1;
                if (v28 > 0)
                {
                    if (v27 >= v12 && v27 < v13 && v19 & 0x10)
                    {
                        *v26 = v65;
                        v13 = yTopa;
                    }
                    v29 = v26 + 1;
                    v30 = v27 + 1;
                    v31 = v28 - 1;
                    if (v31 > 0)
                    {
                        if (v30 >= v12 && v30 < v13 && v19 & 8)
                        {
                            *v29 = v65;
                            v13 = yTopa;
                        }
                        v32 = v29 + 1;
                        v33 = v30 + 1;
                        v34 = v31 - 1;
                        if (v34 > 0)
                        {
                            if (v33 >= v12 && v33 < v13 && v19 & 4)
                            {
                                *v32 = v65;
                                v13 = yTopa;
                            }
                            v35 = v32 + 1;
                            v36 = v33 + 1;
                            v37 = v34 - 1;
                            if (v37 > 0)
                            {
                                if (v36 >= v12 && v36 < v13 && v19 & 2)
                                {
                                    *v35 = v65;
                                    v13 = yTopa;
                                }
                                v38 = v35 + 1;
                                v39 = v36 + 1;
                                v40 = v37 - 1;
                                if (v40 > 0)
                                {
                                    if (v39 >= v12 && v39 < v13 && v19 & 1)
                                        * v38 = v65;
                                    v17 = v38 + 1;
                                    v16 = v39 + 1;
                                    v15 = v40 - 1;
                                    goto LABEL_59;
                                }
                            }
                        }
                    }
                }
            }
        }
        LABEL_60:
        v41 = v68 == 1;
        v66 += *(_DWORD*)(a1 + 4);
        --v68;
        if (!v41)
        {
            v14 = v69;
            continue;
        }
        break;
    }
    LABEL_61:
    if (*(_DWORD*)& byte_5D4594[816452])
    {
        v42 = v70;
        sub_49D190(ptr_5D4594_3799572->data[59], xLeft, v70, v67, v71.field_C - v71.field_4);
        *(_DWORD*)& byte_5D4594[816452] = 0;
        sub_440360(a1, a2, xLeft, v42);
        *(_DWORD*)& byte_5D4594[816452] = 1;
    }
    return xLeft + *(_DWORD*)& byte_5D4594[816440] + v67;
}
// 4403CC: variable 'v6' is possibly undefined

//----- (004407F0) --------------------------------------------------------
int __cdecl sub_4407F0(int a1, __int16* a2, int a3, int a4)
{
    __int16 v4; // cx
    __int16* v5; // esi
    int result; // eax

    v4 = *a2;
    v5 = a2 + 1;
    if (!*a2)
        return a3;
    result = a3;
    do
    {
        if (v4 != 13 && v4 != 10)
            result = (*(int(__cdecl * *)(_DWORD, _WORD, _DWORD, _DWORD)) & byte_5D4594[816448])(a1, v4, result, a4);
        v4 = *v5;
        ++v5;
    } while (v4);
    return result;
}

//----- (00440840) --------------------------------------------------------
void __cdecl sub_440840(LPVOID lpMem)
{
    if (*((_DWORD*)lpMem + 4))
        free(*((LPVOID*)lpMem + 4));
    if (*((_DWORD*)lpMem + 6))
        free(*((LPVOID*)lpMem + 6));
    free(lpMem);
}

//----- (00440870) --------------------------------------------------------
int __cdecl sub_440870(int a1)
{
    int result; // eax
    int v2; // edx
    unsigned __int16* v3; // ecx
    int v4; // esi

    result = 0;
    v2 = *(_DWORD*)(a1 + 12);
    if (v2 > 0)
    {
        v3 = (unsigned __int16*)(*(_DWORD*)(a1 + 16) + 4);
        do
        {
            v4 = v3[1] - *v3;
            v3 += 4;
            --v2;
            result += v4 + 1;
        } while (v2);
    }
    return result;
}

//----- (004408A0) --------------------------------------------------------
__int16 __cdecl sub_4408A0(_WORD* a1)
{
    if (byte_5D4594[3798652] & 8)
        * a1 ^= 0x5555u;
    return 63;
}

//----- (004408C0) --------------------------------------------------------
__int16 __cdecl sub_4408C0(_BYTE* a1)
{
    if (byte_5D4594[3798652] & 8)
        * a1 ^= 0x55u;
    return 63;
}

//----- (004408E0) --------------------------------------------------------
int sub_4408E0()
{
    return 1;
}

//----- (00440900) --------------------------------------------------------
void sub_440900()
{
    _DWORD** dst = *(_DWORD * **)& byte_5D4594[3798784];
    int val = ptr_5D4594_3799572->data[58];
    for (int y = 0; y < nox_backbuffer_height; y++)
    {
        _DWORD* row = *dst;
        for (int x = 0; x < nox_backbuffer_width32; x++)
        {
            for (int i = 0; i < 8; i++)
                row[i] = val;
            row += 8;
        }
        ++dst;
    }
}

//----- (00440950) --------------------------------------------------------
int __cdecl sub_440950(char a1, wchar_t* a2)
{
    char v3[516]; // [esp+4h] [ebp-204h]

    v3[0] = -69;
    v3[1] = a1;
    *(_WORD*)& v3[2] = *(_WORD*)& byte_5D4594[2616328];
    v3[4] = 0;
    *(_WORD*)& v3[5] = 0;
    if (a2)
    {
        v3[4] = nox_wcslen(a2) + 1;
        nox_wcscpy((wchar_t*)& v3[5], a2);
    }
    return sub_4E53C0(31, v3, 2 * (unsigned __int8)v3[4] + 7, 0, 1);
}

//----- (004409D0) --------------------------------------------------------
int __cdecl sub_4409D0(wchar_t* a1)
{
    char v2[21]; // [esp+0h] [ebp-18h]

    v2[0] = -68;
    nox_wcsncpy((wchar_t*)& v2[1], a1, 8u);
    *(_WORD*)& v2[17] = 0;
    *(_WORD*)& v2[19] = *(_WORD*)& byte_5D4594[2616328];
    return sub_4E53C0(31, v2, 21, 0, 1);
}

//----- (00440A20) --------------------------------------------------------
void sub_440A20(wchar_t* a1, ...)
{
    va_list va; // [esp+8h] [ebp+8h]

    va_start(va, a1);
    nox_vswprintf((wchar_t*)& byte_5D4594[822660], a1, va);
    sub_445490((wchar_t*)& byte_5D4594[822660]);
}

//----- (00440A50) --------------------------------------------------------
int __cdecl sub_440A50(int a1, char a2, int a3)
{
    int v3; // esi

    if (a2 != 3)
        return 0;
    if (nox_wcslen(*(const wchar_t**)(a3 + 4)) >= 0x20)
        return 0;
    v3 = sub_440AC0(*(wchar_t**)(a3 + 4));
    if (v3 == -1 || nox_wcslen(*(const wchar_t**)(a3 + 8)) >= 0x80)
        return 0;
    nox_wcscpy((wchar_t*)& byte_587000[76 * v3 + 94516], *(const wchar_t**)(a3 + 8));
    return 1;
}

//----- (00440AC0) --------------------------------------------------------
int __cdecl sub_440AC0(wchar_t* a1)
{
    int v1; // edi
    const wchar_t** v2; // esi

    v1 = 0;
    v2 = (const wchar_t**)& byte_587000[94504];
    while (_nox_wcsicmp(a1, *v2))
    {
        v2 += 19;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[95416])
            return -1;
    }
    return v1;
}

//----- (00440B00) --------------------------------------------------------
int __cdecl sub_440B00(int a1, char a2, int a3)
{
    int v3; // eax

    if (a2 != 2)
        return 0;
    if (nox_wcslen(*(const wchar_t**)(a3 + 4)) >= 0x20)
        return 0;
    v3 = sub_440AC0(*(wchar_t**)(a3 + 4));
    if (v3 == -1)
        return 0;
    *(_WORD*)& byte_587000[76 * v3 + 94516] = 0;
    return 1;
}

//----- (00440B50) --------------------------------------------------------
int __cdecl sub_440B50(int a1, unsigned __int8 a2, int a3)
{
    int result; // eax
    wchar_t v4[128]; // [esp+0h] [ebp-100h]

    if (a2 == 1)
        return 0;
    result = sub_440BC0(a1, a2, a3);
    if (result)
    {
        nox_swprintf(v4, L"%S", result);
        sub_440950(5, v4);
        result = 1;
    }
    return result;
}

//----- (00440BC0) --------------------------------------------------------
char* __cdecl sub_440BC0(int a1, unsigned __int8 a2, int a3)
{
    int v3; // ebx
    unsigned int v5; // edx
    unsigned __int8* v6; // edi
    unsigned __int8* v7; // edi
    char* v8; // esi
    char v9; // cl
    int v10; // edx
    _DWORD* v11; // [esp+8h] [ebp-84h]
    char v12[128]; // [esp+Ch] [ebp-80h]

    v3 = a1;
    if (a1 == a2)
        return 0;
    byte_5D4594[818100] = 0;
    if (a1 < a2)
    {
        v11 = (_DWORD*)(a3 + 4 * a1);
        do
        {
            nox_sprintf(v12, "%S", *v11);
            v5 = strlen(v12) + 1;
            v6 = &byte_5D4594[strlen((const char*)& byte_5D4594[818100]) + 818100];
            qmemcpy(v6, v12, 4 * (v5 >> 2));
            v8 = &v12[4 * (v5 >> 2)];
            v7 = &v6[4 * (v5 >> 2)];
            v9 = v5;
            v10 = v3 + 1;
            qmemcpy(v7, v8, v9 & 3);
            if (v3 + 1 < a2)
                * (_WORD*)& byte_5D4594[strlen((const char*)& byte_5D4594[818100]) + 818100] = *(_WORD*)& byte_587000[101624];
            ++v3;
            ++v11;
        } while (v10 < a2);
    }
    return (char*)& byte_5D4594[818100];
}
// 440BC0: using guessed type char var_80[128];

//----- (00440C90) --------------------------------------------------------
int __cdecl sub_440C90(int a1, char a2)
{
    if (a2 == 1)
        return 0;
    sub_46A4B0((wchar_t*)(*(_DWORD*)& byte_5D4594[823700] + 8), 0);
    return 1;
}

//----- (00440CC0) --------------------------------------------------------
int __cdecl sub_440CC0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_4185B0();
    return 1;
}

//----- (00440CE0) --------------------------------------------------------
int __cdecl sub_440CE0(int a1, char a2, int a3)
{
    int result; // eax
    char* v4; // ebx
    const wchar_t* v5; // eax
    int v6; // edi
    unsigned __int8* v7; // esi

    if (a2 != 3)
        return 0;
    result = (int)& byte_5D4594[822660];
    if (true) // TODO: byte_5D4594 != (unsigned __int8*)-822660
    {
        v4 = sub_416590(1);
        v5 = *(const wchar_t**)& byte_587000[94400];
        v6 = 0;
        if (*(_DWORD*)& byte_587000[94400])
        {
            v7 = &byte_587000[94400];
            while (_nox_wcsicmp(v5, *(const wchar_t**)(a3 + 4 * a1)))
            {
                v5 = (const wchar_t*) * ((_DWORD*)v7 + 2);
                v7 += 8;
                ++v6;
                if (!v5)
                    return 1;
            }
            *((_WORD*)v4 + 26) &= 0xE80Fu;
            *((_WORD*)v4 + 26) |= *(_WORD*)& byte_587000[8 * v6 + 94404];
        }
        result = 1;
    }
    return result;
}

//----- (00440D70) --------------------------------------------------------
int sub_440D70()
{
    *(_DWORD*)& byte_587000[94464] = 0;
    return 1;
}

//----- (00440D80) --------------------------------------------------------
int __cdecl sub_440D80(int a1, char a2, int a3)
{
    wchar_t* v4; // eax

    if (a2 != 2)
        return 0;
    sub_450B20(*(wchar_t**)(a3 + 4));
    sub_450B70();
    v4 = loadString_sub_40F1D0((char*)& byte_587000[101668], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1329);
    sub_450C00(4u, v4);
    return 1;
}

//----- (00440DD0) --------------------------------------------------------
int __cdecl sub_440DD0(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 1)
        return 0;
    sub_450B50();
    v3 = loadString_sub_40F1D0((char*)& byte_587000[101724], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1340);
    sub_450C00(4u, v3);
    return 1;
}

//----- (00440E10) --------------------------------------------------------
int __cdecl sub_440E10(int a1, char a2, int a3)
{
    wchar_t* v4; // eax

    if (a2 != 3)
        return 0;
    sub_40A610(*(wchar_t**)(a3 + 4 * a1));
    v4 = loadString_sub_40F1D0((char*)& byte_587000[101780], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1352);
    sub_450C00(6u, v4);
    return 1;
}

//----- (00440E60) --------------------------------------------------------
int __cdecl sub_440E60(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 2)
        return 0;
    if (!sub_40A5C0(2048))
    {
        sub_579830();
        v3 = loadString_sub_40F1D0((char*)& byte_587000[101840], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1368);
        sub_450C00(6u, v3);
    }
    return 1;
}

//----- (00440EB0) --------------------------------------------------------
int __cdecl sub_440EB0(int a1, unsigned __int8 a2, int a3)
{
    unsigned __int16 v4; // ax
    wchar_t* v5; // eax
    int v6; // [esp-4h] [ebp-8h]

    if (a2 < 2u || a2 > 3u)
        return 0;
    if (sub_40A5C0(2048))
        return 1;
    if (a2 == 2)
    {
        sub_5797F0(0);
    }
    else
    {
        v4 = nox_wcstol(*(const wchar_t**)(a3 + 4 * a2 - 4), 0, 10);
        sub_5797F0(v4);
    }
    v6 = sub_579850();
    v5 = loadString_sub_40F1D0((char*)& byte_587000[101892], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1388);
    sub_450C00(6u, v5, v6);
    return 1;
}

//----- (00440F50) --------------------------------------------------------
int __cdecl sub_440F50(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 2)
        return 0;
    *(_DWORD*)& byte_587000[95416] = 1;
    v3 = loadString_sub_40F1D0((char*)& byte_587000[101944], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1400);
    sub_450C00(6u, v3);
    return 1;
}

//----- (00440F90) --------------------------------------------------------
int __cdecl sub_440F90(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 2)
        return 0;
    *(_DWORD*)& byte_587000[95416] = 0;
    v3 = loadString_sub_40F1D0((char*)& byte_587000[101996], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1411);
    sub_450C00(6u, v3);
    return 1;
}

//----- (00440FD0) --------------------------------------------------------
int __cdecl sub_440FD0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_43DDE0(1);
    return 1;
}

//----- (00440FF0) --------------------------------------------------------
int __cdecl sub_440FF0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_43DDE0(0);
    return 1;
}

//----- (00441010) --------------------------------------------------------
int __cdecl sub_441010(int a1, char a2)
{
    int v3; // eax

    if (a2 != 2)
        return 0;
    v3 = *(_DWORD*)& byte_5D4594[2650636];
    BYTE1(v3) |= 0x80u;
    *(_DWORD*)& byte_5D4594[2650636] = v3;
    return 1;
}

//----- (00441030) --------------------------------------------------------
int __cdecl sub_441030(int a1, char a2)
{
    int v3; // eax

    if (a2 != 2)
        return 0;
    v3 = *(_DWORD*)& byte_5D4594[2650636];
    BYTE1(v3) &= 0x7Fu;
    *(_DWORD*)& byte_5D4594[2650636] = v3;
    return 1;
}

//----- (00441050) --------------------------------------------------------
int sub_441050()
{
    wchar_t* v0; // ebx
    wchar_t* v1; // ebp
    char** v2; // edi
    int v3; // eax
    int v4; // esi
    wchar_t* v5; // eax
    int v7; // [esp-Ch] [ebp-18h]
    wchar_t* v8; // [esp-8h] [ebp-14h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102048], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1460);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102096], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1461);
    v2 = (char**)sub_4E3B30();
    if (!v2)
        return 1;
    do
    {
        if ((unsigned int)v2[6] & 0x1000000)
        {
            v3 = sub_415910(v2[1]);
            v4 = sub_4159F0(v3);
            if (v4)
            {
                if (sub_4E3BA0(*(unsigned __int16*)v2))
                {
                    v8 = v0;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102148], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1475);
                }
                else
                {
                    v8 = v1;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102200], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1477);
                }
                sub_450C00(6u, v5, v7, v8);
            }
        }
        v2 = (char**)sub_4E3B40((int)v2);
    } while (v2);
    return 1;
}

//----- (00441130) --------------------------------------------------------
int sub_441130()
{
    wchar_t* v0; // ebx
    wchar_t* v1; // ebp
    char** v2; // edi
    int v3; // eax
    int v4; // esi
    wchar_t* v5; // eax
    int v7; // [esp-Ch] [ebp-18h]
    wchar_t* v8; // [esp-8h] [ebp-14h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102252], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1492);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102300], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1493);
    v2 = (char**)sub_4E3B30();
    if (!v2)
        return 1;
    do
    {
        if ((unsigned int)v2[6] & 0x2000000)
        {
            v3 = sub_415DF0(v2[1]);
            v4 = sub_415E80(v3);
            if (v4)
            {
                if (sub_4E3BA0(*(unsigned __int16*)v2))
                {
                    v8 = v0;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102352], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1508);
                }
                else
                {
                    v8 = v1;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102404], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1510);
                }
                sub_450C00(6u, v5, v7, v8);
            }
        }
        v2 = (char**)sub_4E3B40((int)v2);
    } while (v2);
    return 1;
}

//----- (00441210) --------------------------------------------------------
int sub_441210()
{
    wchar_t* v0; // edi
    wchar_t* v1; // ebx
    int v2; // esi
    wchar_t* v3; // eax
    int v5; // [esp-Ch] [ebp-18h]
    int v6; // [esp-8h] [ebp-14h]
    wchar_t* v7; // [esp-4h] [ebp-10h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102456], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1524);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102504], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1525);
    v2 = 1;
    do
    {
        if (sub_424B50(v2))
        {
            if (sub_424B70(v2))
            {
                v7 = v0;
                v6 = sub_4249A0(v2, 1);
                v5 = sub_424930(v2);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[102556], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1531);
            }
            else
            {
                v7 = v1;
                v6 = sub_4249A0(v2, 1);
                v5 = sub_424930(v2);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[102608], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1533);
            }
            sub_450C00(6u, v3, v5, v6, v7);
        }
        ++v2;
    } while (v2 < 137);
    return 1;
}

//----- (004412E0) --------------------------------------------------------
int sub_4412E0()
{
    wchar_t* v0; // ebx
    wchar_t* v1; // ebp
    unsigned __int16* v2; // edi
    int v3; // eax
    int v4; // eax
    int v5; // esi
    wchar_t* v6; // eax
    int v8; // [esp-Ch] [ebp-18h]
    wchar_t* v9; // [esp-8h] [ebp-14h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102660], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1588);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102708], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1589);
    v2 = (unsigned __int16*)sub_4E3B30();
    if (!v2)
        return 1;
    do
    {
        v3 = *((_DWORD*)v2 + 6);
        if (v3 & 0x1000)
        {
            v4 = sub_415910(*((char**)v2 + 1));
            v5 = sub_4159F0(v4);
            if (v5)
            {
                if (sub_4E3BA0(*v2))
                {
                    v9 = v0;
                    v8 = v5;
                    v6 = loadString_sub_40F1D0((char*)& byte_587000[102760], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1604);
                }
                else
                {
                    v9 = v1;
                    v8 = v5;
                    v6 = loadString_sub_40F1D0((char*)& byte_587000[102812], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1606);
                }
                sub_450C00(6u, v6, v8, v9);
            }
        }
        v2 = (unsigned __int16*)sub_4E3B40((int)v2);
    } while (v2);
    return 1;
}

//----- (004413C0) --------------------------------------------------------
int __cdecl sub_4413C0(int a1, char a2)
{
    unsigned __int8* v3; // esi
    wchar_t* v4; // eax

    if (a2 != 2)
        return 0;
    v3 = &byte_587000[94516];
    do
    {
        if (*(_WORD*)v3)
            sub_450C00(4u, (wchar_t*)& byte_587000[102824], *((_DWORD*)v3 - 2), v3);
        v3 += 76;
    } while ((int)v3 < (int)& byte_587000[95428]);
    if (*(_DWORD*)& byte_587000[95416])
        v4 = loadString_sub_40F1D0((char*)& byte_587000[102880], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1630);
    else
        v4 = loadString_sub_40F1D0((char*)& byte_587000[102932], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1632);
    sub_450C00(4u, v4);
    return 1;
}

//----- (00441440) --------------------------------------------------------
int sub_441440()
{
    *(_DWORD*)& byte_5D4594[2650636] ^= 8u;
    return 1;
}

//----- (00441460) --------------------------------------------------------
int sub_441460()
{
    int v0; // eax

    v0 = *(_DWORD*)& byte_587000[80828] ^ 1;
    *(_DWORD*)& byte_587000[80828] = v0;
    *(_DWORD*)& byte_587000[80832] = v0;
    return 1;
}

//----- (00441480) --------------------------------------------------------
int sub_441480()
{
    sub_452D80(921, 100);
    *(_DWORD*)& byte_5D4594[2650636] ^= 2u;
    return 1;
}

//----- (004414B0) --------------------------------------------------------
int sub_4414B0()
{
    sub_452D80(921, 100);
    sub_435F40();
    return 1;
}

//----- (004414D0) --------------------------------------------------------
int sub_4414D0()
{
    sub_470A60();
    return 1;
}

//----- (004414E0) --------------------------------------------------------
int sub_4414E0()
{
    sub_452D80(921, 100);
    sub_435F60();
    return 1;
}

//----- (00441500) --------------------------------------------------------
int sub_441500()
{
    sub_409B30();
    sub_413E30();
    return 1;
}

//----- (00441530) --------------------------------------------------------
int sub_441530()
{
    if (sub_40A5C0(0x2000))
        sub_4703F0();
    return 1;
}

//----- (00441550) --------------------------------------------------------
int __cdecl sub_441550(int a1, char a2)
{
    char* v2; // esi
    int v4; // edi
    int v5; // eax
    wchar_t* v6; // eax
    __int16 v7; // ax
    wchar_t* v8; // eax
    wchar_t* v9; // eax
    struct in_addr v10; // eax
    char* v11; // eax
    char* v12; // [esp-18h] [ebp-5Ch]
    int v13; // [esp-10h] [ebp-54h]
    int v14; // [esp-Ch] [ebp-50h]
    char* v15; // [esp-8h] [ebp-4Ch]
    int v16; // [esp-8h] [ebp-4Ch]
    int v17; // [esp-8h] [ebp-4Ch]
    wchar_t v18[32]; // [esp+4h] [ebp-40h]

    v2 = sub_4165B0();
    if (a2 != 2)
        return 0;
    v4 = sub_416F40();
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
        --v4;
    v5 = sub_409AC0();
    sub_450C00(6u, (wchar_t*)& byte_587000[102952], &byte_587000[102944], v5);
    if (sub_40A5C0(0x2000))
    {
        v15 = sub_40A4C0();
        v6 = loadString_sub_40F1D0((char*)& byte_587000[103020], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1801);
        sub_450C00(6u, (wchar_t*)& byte_587000[103028], v6, v15);
        v7 = sub_40A5B0();
        v16 = sub_4573C0(v7);
        v8 = loadString_sub_40F1D0((char*)& byte_587000[103080], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1802);
        sub_450C00(6u, (wchar_t*)& byte_587000[103088], v8, v16);
        v17 = sub_40A180(*((_WORD*)v2 + 26));
        v14 = (unsigned __int16)sub_40A020(*((_WORD*)v2 + 26));
        v13 = sub_409FA0();
        v12 = sub_409B30();
        v9 = loadString_sub_40F1D0((char*)& byte_587000[103140], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1803);
        sub_450C00(6u, v9, v12, v4, v13, v14, v17);
        v10.S_un.S_addr = sub_554200(0);
        v11 = inet_ntoa(v10);
        nox_swprintf(v18, L"%S", v11);
        sub_450C00(6u, (wchar_t*)& byte_587000[103160], v18);
    }
    return 1;
}

//----- (004416B0) --------------------------------------------------------
int __cdecl sub_4416B0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_4467F0();
    return 1;
}

//----- (004416D0) --------------------------------------------------------
int __cdecl sub_4416D0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_48D7B0();
    return 1;
}

//----- (004416F0) --------------------------------------------------------
int sub_4416F0()
{
    wchar_t* v0; // eax

    if (*(_DWORD*)& byte_5D4594[805836])
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103208], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1869);
    else
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103260], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1871);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00441740) --------------------------------------------------------
int sub_441740()
{
    int* v0; // esi
    int i; // edi
    bool v2; // zf
    signed int v3; // edi

    memset(&byte_5D4594[822404], 0, 0x100u);
    v0 = sub_4D09B0();
    for (i = 1; v0; ++i)
    {
        sub_4417E0((wchar_t*)& byte_5D4594[822404], (const char*)v0 + 12);
        if (!(i % 4))
        {
            sub_450C00(6u, (wchar_t*)& byte_587000[103276], &byte_5D4594[822404]);
            *(_WORD*)& byte_5D4594[822404] = 0;
        }
        v0 = sub_4D09C0(v0);
    }
    v3 = (i - 1) & 0x80000003;
    v2 = v3 == 0;
    if (v3 < 0)
        v2 = (((_BYTE)v3 - 1) | 0xFFFFFFFC) == (unsigned int)-1;
    if (!v2)
        sub_450C00(6u, (wchar_t*)& byte_587000[103284], &byte_5D4594[822404]);
    return 1;
}

//----- (004417E0) --------------------------------------------------------
void __cdecl sub_4417E0(wchar_t* a1, const char* a2)
{
    unsigned __int8 v2; // dl
    char* v3; // edi
    char v4[64]; // [esp+4h] [ebp-C0h]
    wchar_t v5[64]; // [esp+44h] [ebp-80h]

    if (a2)
    {
        strcpy(v4, a2);
        v2 = byte_587000[103296];
        v3 = &v4[strlen(v4)];
        *(_DWORD*)v3 = *(_DWORD*)& byte_587000[103292];
        v3[4] = v2;
        nox_swprintf(v5, L"%-20.20S\t\t", v4);
        nox_wcscat(a1, v5);
    }
}
// 4417E0: using guessed type char var_C0[64];

//----- (00441870) --------------------------------------------------------
int __cdecl sub_441870(int a1, char a2, int a3)
{
    int result; // eax
    char v4[256]; // [esp+0h] [ebp-100h]

    result = 0;
    if (a2 == 3)
    {
        if (*(_DWORD*)(a3 + 8))
        {
            *(_DWORD*)& byte_5D4594[2650636] |= 0x800000;
            nox_sprintf(v4, "%S", *(_DWORD*)(a3 + 8));
            result = sub_413A80(v4);
        }
    }
    return result;
}

//----- (004418D0) --------------------------------------------------------
int __cdecl sub_4418D0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    *(_DWORD*)& byte_5D4594[2650636] |= 0x1000000u;
    return 1;
}

//----- (004418F0) --------------------------------------------------------
int __cdecl sub_4418F0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_413C00();
    return 1;
}

//----- (00441910) --------------------------------------------------------
int __cdecl sub_441910(int a1, char a2, int a3)
{
    int v4; // eax
    int v5; // ebx
    wchar_t* v6; // eax
    unsigned int v7; // kr04_4
    char* v8; // ebx
    wchar_t* v9; // eax
    char* v10; // [esp-4h] [ebp-234h]
    char v11[260]; // [esp+8h] [ebp-228h]
    struct _stat v12; // [esp+10Ch] [ebp-124h]
    CHAR FileName[256]; // [esp+130h] [ebp-100h]

    if (sub_40A5C0(4096))
        return 1;
    if (a2 != 2)
        return 0;
    nox_sprintf(&v11[4], "%S", *(_DWORD*)(a3 + 4));
    if (v11[4] != 35 && !sub_4CFE10(&v11[4]))
        return 1;
    v4 = sub_4CFFA0((int)& byte_5D4594[3801836]);
    v5 = v4;
    if (sub_40A5C0(0x2000))
    {
        if (v5 && !(v5 & 0x200))
        {
            if (sub_40A5C0(128))
            {
                if (v5 & 0x60 && sub_417DD0() != 2)
                    sub_4185B0();
            }
            else if (!(sub_40A5B0() & v5))
            {
                v6 = loadString_sub_40F1D0((char*)& byte_587000[103372], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2005);
                sub_440A20(v6);
                return 1;
            }
            goto LABEL_16;
        }
    }
    else if (v5 & 0x200)
    {
        LABEL_16:
        v7 = strlen(&v11[4]) + 1;
        if ((int)(v7 - 1) <= 4 || _strcmpi(&v11[v7 - 1], ".map"))
        {
            strcpy((char*)& byte_5D4594[822324], &v11[4]);
            v8 = (char*)& byte_5D4594[822324];
            strcat((char*)& byte_5D4594[822324], ".map");
        }
        else
        {
            v8 = &v11[4];
        }
        if (!v8
            || *v8 != 35
               && (strcpy(FileName, "maps\\"),
                strncat(FileName, v8, strlen(v8) - 4),
                *(_WORD*)& FileName[strlen(FileName)] = *(_WORD*)& byte_587000[103416],
                strcat(FileName, v8),
                _stat(FileName, (int)& v12)))
        {
            v10 = v8;
            v9 = loadString_sub_40F1D0((char*)& byte_587000[103512], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2076);
        }
        else
        {
            sub_4DCC70(1);
            sub_4D2450(v8);
            sub_41D650();
            v10 = v8;
            v9 = loadString_sub_40F1D0((char*)& byte_587000[103460], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2072);
        }
        sub_440A20(v9, v10);
        return 1;
    }
    return 1;
}
// 44198D: variable 'v4' is possibly undefined

//----- (00441B90) --------------------------------------------------------
char** __cdecl sub_441B90(_DWORD* a1)
{
    char** result; // eax
    char** v2; // esi
    wchar_t* v3; // eax

    result = (char**)a1;
    if (a1 && *a1)
    {
        v2 = (char**)(a1 + 2);
        do
        {
            if (!((_BYTE)result[3] & 4) && (!*(_DWORD*)& byte_587000[94464] || !((_BYTE)v2[1] & 0x10)))
            {
                v3 = loadString_sub_40F1D0(*v2, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2097);
                sub_450C00(6u, (wchar_t*)& byte_587000[103568], *(v2 - 1), v3);
            }
            v2 += 6;
            result = v2 - 2;
        } while (*(v2 - 2));
    }
    return result;
}

//----- (00441BF0) --------------------------------------------------------
int __cdecl sub_441BF0(int a1, int a2, int a3, const wchar_t** a4)
{
    int result; // eax
    int v5; // edi
    const wchar_t** v6; // eax
    const wchar_t** v7; // esi
    char v8; // al
    const wchar_t* v9; // ecx
    const wchar_t** v10; // eax
    const wchar_t** v11; // esi
    wchar_t* v12; // eax

    result = 0;
    if (*(_DWORD*)(a3 + 4 * a1))
    {
        if (a4)
        {
            v5 = 0;
            if (*a4)
            {
                v6 = a4;
                v7 = a4;
                while (1)
                {
                    if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *v6))
                    {
                        v8 = *((_BYTE*)v7 + 12);
                        if (!(v8 & 4) && (!*(_DWORD*)& byte_587000[94464] || !(v8 & 0x10)))
                            break;
                    }
                    v9 = v7[6];
                    v7 += 6;
                    ++v5;
                    v6 = v7;
                    if (!v9)
                        return 0;
                }
                v10 = (const wchar_t**)a4[6 * v5 + 4];
                v11 = &a4[6 * v5];
                if (v10)
                {
                    if ((unsigned __int8)a2 <= a1 + 1 || (result = sub_441BF0(a1 + 1, a2, a3, v10)) == 0)
                    {
                        sub_441B90(v11[4]);
                        result = 1;
                    }
                }
                else
                {
                    v12 = loadString_sub_40F1D0((char*)v11[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2135);
                    sub_450C00(6u, v12);
                    result = 1;
                }
            }
        }
    }
    return result;
}

//----- (00441CE0) --------------------------------------------------------
int __cdecl sub_441CE0(int a1, int a2, int a3)
{
    if ((unsigned __int8)a2 != 1)
        return sub_441BF0(1, a2, a3, (const wchar_t**)& byte_587000[97368]);
    sub_441B90(&byte_587000[97368]);
    return 1;
}

//----- (00441D20) --------------------------------------------------------
int sub_441D20()
{
    return 1;
}

//----- (00441D30) --------------------------------------------------------
int sub_441D30()
{
    char* i; // esi

    if (!sub_40A5C0(0x2000))
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            if (*((_DWORD*)i + 514))
                sub_4FC180(*((_DWORD*)i + 514));
        }
    }
    return 1;
}

//----- (00441D80) --------------------------------------------------------
int __cdecl sub_441D80(int a1, unsigned __int8 a2, int a3)
{
    const char* v4; // edi
    char* v5; // esi
    int v6; // eax
    char* v7; // eax
    char* v8; // esi
    double v9; // st7
    int v10; // eax
    float2 v11; // [esp+8h] [ebp-54h]
    char v12[76]; // [esp+10h] [ebp-4Ch]

    if (sub_40A5C0(0x2000))
        return 1;
    if (a2 >= 4u)
    {
        v7 = sub_417040(*(int*)& byte_5D4594[2616328]);
        v8 = v7;
        if (!v7 || !*((_DWORD*)v7 + 514))
            return 0;
        nox_sprintf(v12, "%S", *(_DWORD*)(a3 + 8));
        v9 = atof(v12);
        v10 = *(_DWORD*)(a3 + 12);
        v11.field_0 = v9;
        nox_sprintf(v12, "%S", v10);
        v11.field_4 = atof(v12);
        sub_4E7010(*((_DWORD*)v8 + 514), &v11);
        return 1;
    }
    if (a2 < 3u)
        return 0;
    nox_sprintf(v12, "%S", *(_DWORD*)(a3 + 8));
    v4 = sub_579E30(v12);
    if (!v4)
        return 1;
    v5 = sub_416EA0();
    if (!v5)
        return 1;
    do
    {
        v6 = *((_DWORD*)v5 + 514);
        if (v6)
            sub_4E7010(v6, (float2*)v4 + 1);
        v5 = sub_416EE0((int)v5);
    } while (v5);
    return 1;
}

//----- (00441EB0) --------------------------------------------------------
int sub_441EB0()
{
    char* i; // esi

    if (!sub_40A5C0(0x2000))
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            if (*((_DWORD*)i + 514))
                sub_4EE6F0(*((_DWORD*)i + 514));
        }
    }
    return 1;
}

//----- (00441F00) --------------------------------------------------------
int sub_441F00()
{
    char* i; // esi
    int v1; // eax

    if (!sub_40A5C0(0x2000))
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v1 = *((_DWORD*)i + 514);
            if (v1)
                sub_4EEB80(v1, 2000);
        }
    }
    return 1;
}

//----- (00441F50) --------------------------------------------------------
int __cdecl sub_441F50(int a1, unsigned __int8 a2, int a3)
{
    char* i; // esi
    unsigned __int8 v5; // al

    if (!sub_40A5C0(0x2000))
    {
        if (a2 < 3u)
            return 0;
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            if (*((_DWORD*)i + 514))
            {
                v5 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
                sub_4EF410(*((_DWORD*)i + 514), v5);
            }
        }
    }
    return 1;
}

//----- (00441FC0) --------------------------------------------------------
int __cdecl sub_441FC0(int a1, unsigned __int8 a2, int a3)
{
    int v4; // eax
    int v5; // edi
    char* i; // ebp
    int v7; // esi
    int* v8; // ebx

    if (!sub_40A5C0(0x2000))
    {
        if (a2 < 3u)
            return 0;
        v4 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
        v5 = v4;
        if (v4 > 0)
        {
            if (v4 > 5)
                v5 = 5;
        }
        else
        {
            v5 = 1;
        }
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v7 = 0;
            v8 = (int*)(i + 3696);
            do
            {
                *v8 = v5;
                sub_56FCE0(*((_DWORD*)i + 1159), v7, v5);
                *v8 = v5;
                sub_56FCE0(*((_DWORD*)i + 1159), v7++, v5);
                ++v8;
            } while (v7 < 137);
        }
    }
    return 1;
}

//----- (00442070) --------------------------------------------------------
int __cdecl sub_442070(int a1, unsigned __int8 a2, int a3)
{
    int v4; // edi
    char* i; // esi
    int v6; // eax

    if (!sub_40A5C0(0x2000))
    {
        if (a2 < 3u)
            return 0;
        v4 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v6 = *((_DWORD*)i + 514);
            if (v6)
            {
                if (v4 < 0)
                    sub_4FA5D0(v6, v4);
                else
                    sub_4FA590(v6, v4);
            }
        }
    }
    return 1;
}

//----- (004420F0) --------------------------------------------------------
int sub_4420F0()
{
    if (!sub_40A5C0(0x2000))
        sub_40AA60(1);
    return 1;
}

//----- (00442120) --------------------------------------------------------
int sub_442120()
{
    sub_46DB00();
    return 1;
}

//----- (00442130) --------------------------------------------------------
int sub_442130()
{
    sub_4460C0();
    return 1;
}

//----- (00442140) --------------------------------------------------------
int sub_442140()
{
    if (sub_40A5C0(4096) && sub_40A5C0(1))
        sub_4D6B10(0);
    if (sub_40A5C0(0x2000000))
        sub_4460C0();
    sub_43DDD0(0);
    sub_43DE60();
    return 1;
}

//----- (004421A0) --------------------------------------------------------
int sub_4421A0()
{
    wchar_t* v0; // eax
    char* v2; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[103680], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2440);
    sub_450C00(6u, v0);
    if (sub_40A5C0(1))
    {
        v2 = sub_417040(*(int*)& byte_5D4594[2616328]);
        sub_443E90((int)v2, 0, *(wchar_t**)& byte_5D4594[823700]);
    }
    else
    {
        sub_440950(0, *(wchar_t**)& byte_5D4594[823700]);
    }
    return 1;
}

//----- (00442210) --------------------------------------------------------
int __cdecl sub_442210(int a1, unsigned __int8 a2, int a3)
{
    int result; // eax
    char* v4; // eax
    wchar_t v5[128]; // [esp+4h] [ebp-100h]

    result = sub_440BC0(a1, a2, a3);
    if (result)
    {
        nox_swprintf(v5, L"%S", result);
        if (sub_40A5C0(1))
        {
            v4 = sub_417040(*(int*)& byte_5D4594[2616328]);
            if (a2 <= 1u)
                sub_443E90((int)v4, 4, (wchar_t*)& byte_5D4594[823768]);
            else
                sub_443E90((int)v4, 4, v5);
            result = 1;
        }
        else
        {
            if (a2 <= 1u)
                sub_440950(4, (wchar_t*)& byte_5D4594[823764]);
            else
                sub_440950(4, v5);
            result = 1;
        }
    }
    return result;
}

//----- (004422D0) --------------------------------------------------------
int __cdecl sub_4422D0(int a1, unsigned __int8 a2, int a3)
{
    const wchar_t* v3; // eax
    int v4; // esi
    int v5; // esi
    int v6; // eax
    int v8; // [esp-14h] [ebp-14h]

    if (a2 <= 1u)
        return 1;
    v3 = *(const wchar_t**)(a3 + 4 * a1);
    if (*v3 == 43)
    {
        v4 = nox_wcstol(v3, 0, 10);
        v8 = sub_434B00() + v4;
        sub_434B30(v8);
    }
    else
    {
        if (*v3 == 45)
        {
            v5 = nox_wcstol(v3, 0, 10);
            v6 = sub_434B00() - v5;
        }
        else
        {
            v6 = nox_wcstol(v3, 0, 10);
        }
        sub_434B30(v6);
    }
    sub_434B60();
    return 1;
}

//----- (00442340) --------------------------------------------------------
int __cdecl sub_442340(int a1, unsigned __int8 a2, int a3)
{
    const wchar_t* v3; // eax
    int v4; // eax
    int v6; // eax

    if (a2 > 1u)
    {
        v3 = *(const wchar_t**)(a3 + 4 * a1);
        if (*v3 != 43 && *v3 != 45)
        {
            v4 = nox_wcstol(v3, 0, 10);
            sub_476700(v4, 0);
            return 1;
        }
        v6 = nox_wcstol(v3, 0, 10);
        sub_476700(0, v6);
    }
    return 1;
}

//----- (004423A0) --------------------------------------------------------
int sub_4423A0()
{
    if (sub_4D6F50() && !sub_40A5C0(4096))
        sub_4D7080();
    return 1;
}

//----- (004423D0) --------------------------------------------------------
int sub_4423D0()
{
    wchar_t* v0; // eax

    *(_DWORD*)& byte_5D4594[2650636] |= 0x8000000u;
    v0 = loadString_sub_40F1D0((char*)& byte_587000[103744], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2541);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00442410) --------------------------------------------------------
int sub_442410()
{
    wchar_t* v0; // eax

    if (!sub_40A5C0(4096))
    {
        sub_4EF500(1);
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103800], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2557);
        sub_450C00(6u, v0);
    }
    return 1;
}

//----- (00442450) --------------------------------------------------------
int sub_442450()
{
    wchar_t* v0; // eax

    sub_4EF500(0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[103848], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2568);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00442480) --------------------------------------------------------
int sub_442480()
{
    wchar_t* v0; // eax

    if (!sub_40A5C0(4096))
    {
        nullsub_26(1);
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103900], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2585);
        sub_450C00(6u, v0);
    }
    return 1;
}
// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);

//----- (004424C0) --------------------------------------------------------
int sub_4424C0()
{
    wchar_t* v0; // eax

    nullsub_26(0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[103948], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2597);
    sub_450C00(6u, v0);
    return 1;
}
// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);

//----- (004424F0) --------------------------------------------------------
int __cdecl sub_4424F0(int a1, char a2, int a3)
{
    wchar_t* v3; // eax

    if (a2 == 3)
    {
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
        {
            sub_4D0D90(1);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104000], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2614);
            LABEL_6:
            sub_450C00(6u, v3);
            sub_4AD840();
            return 1;
        }
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
        {
            sub_4D0D90(0);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104052], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2621);
            goto LABEL_6;
        }
    }
    return 0;
}

//----- (00442590) --------------------------------------------------------
int __cdecl sub_442590(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-Ch]

    if (a2 == 3)
    {
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
        {
            sub_409E70(1);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104104], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2644);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104160], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2645);
            LABEL_6:
            sub_450C00(6u, v3, v5);
            return 1;
        }
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
        {
            sub_409EC0(1);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104208], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2652);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104264], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2653);
            goto LABEL_6;
        }
    }
    return 0;
}

//----- (00442670) --------------------------------------------------------
int __cdecl sub_442670(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-Ch]

    if (a2 == 3)
    {
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
        {
            sub_409E70(16);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104312], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2674);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104368], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2675);
            LABEL_6:
            sub_450C00(6u, v3, v5);
            return 1;
        }
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
        {
            sub_409EC0(16);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104416], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2682);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104472], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2683);
            goto LABEL_6;
        }
    }
    return 0;
}

//----- (00442750) --------------------------------------------------------
int sub_442750()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(4);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 4;
    sub_4AD840();
    return 1;
}

//----- (00442780) --------------------------------------------------------
int sub_442780()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(3);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 3;
    sub_4AD840();
    return 1;
}

//----- (004427B0) --------------------------------------------------------
int sub_4427B0()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(2);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 2;
    sub_4AD840();
    return 1;
}

//----- (004427E0) --------------------------------------------------------
int sub_4427E0()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(1);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 1;
    sub_4AD840();
    return 1;
}

//----- (00442810) --------------------------------------------------------
int sub_442810()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 0;
    v0 = sub_40A710(1);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 1;
    sub_4AD840();
    return 1;
}

//----- (00442840) --------------------------------------------------------
int __cdecl sub_442840(int a1, unsigned __int8 a2, int a3)
{
    int v3; // ebx
    unsigned int v5; // edx
    char* v6; // edi
    char* v7; // edi
    char* v8; // esi
    char v9; // cl
    int v10; // edx
    wchar_t* v11; // eax
    _DWORD* v12; // [esp+4h] [ebp-104h]
    char v13[128]; // [esp+8h] [ebp-100h]
    char v14[128]; // [esp+88h] [ebp-80h]

    v3 = a1;
    if (a2 < 3u)
        return 0;
    v13[0] = 0;
    if (a1 < a2)
    {
        v12 = (_DWORD*)(a3 + 4 * a1);
        do
        {
            nox_sprintf(v14, "%S", *v12);
            v5 = strlen(v14) + 1;
            v6 = &v13[strlen(v13)];
            qmemcpy(v6, v14, 4 * (v5 >> 2));
            v8 = &v14[4 * (v5 >> 2)];
            v7 = &v6[4 * (v5 >> 2)];
            v9 = v5;
            v10 = v3 + 1;
            qmemcpy(v7, v8, v9 & 3);
            if (v3 + 1 < a2)
                * (_WORD*)& v13[strlen(v13)] = *(_WORD*)& byte_587000[104484];
            ++v3;
            ++v12;
        } while (v10 < a2);
        if (v13[0])
        {
            sub_40A440(v13);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[104528], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2766);
            sub_450C00(6u, v11, v13);
        }
    }
    return 1;
}
// 442840: using guessed type char var_100[128];
// 442840: using guessed type char var_80[128];

//----- (00442950) --------------------------------------------------------
int __cdecl sub_442950(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-10h]

    if (a2 == 3 || a2 == 4)
    {
        if (_nox_wcsicmp(*(const wchar_t**)(a3 + 8), *(const wchar_t**)& byte_587000[94492]))
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_409E70(4);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104804], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2810);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104860], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2811);
                goto LABEL_13;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_409EC0(4);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104912], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2818);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104968], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2819);
                goto LABEL_13;
            }
        }
        else if (a2 != 3)
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_409E70(8);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104580], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2788);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104636], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2789);
                LABEL_13:
                sub_450C00(6u, v3, v5);
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_409E70(8);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104692], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2796);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104748], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2797);
                goto LABEL_13;
            }
        }
    }
    return 0;
}

//----- (00442B00) --------------------------------------------------------
int __cdecl sub_442B00(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    int v4; // esi
    char* v5; // ebx
    wchar_t* v7; // eax
    int v8; // [esp-4h] [ebp-74h]
    int v9; // [esp-4h] [ebp-74h]
    char v10[100]; // [esp+Ch] [ebp-64h]

    if (a2 == 4)
    {
        if (sub_40A5C0(128))
        {
            v8 = *(_DWORD*)(a3 + 8);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[105020], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3293);
            goto LABEL_16;
        }
        v4 = sub_424960(*(wchar_t**)(a3 + 8));
        if (v4 || (nox_sprintf(v10, "%S", *(_DWORD*)(a3 + 8)), (v4 = sub_4243F0(v10)) != 0))
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                v5 = sub_4165B0();
                if ((sub_40A5C0(64) || v5[52] & 0x40) && v4 == 132)
                    return 1;
                if (sub_424B70(v4))
                    return 1;
                sub_424B90(v4);
                sub_40A670();
                v8 = *(_DWORD*)(a3 + 8);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[105076], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3324);
                goto LABEL_16;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                if (!sub_424B70(v4))
                    return 1;
                sub_424BB0(v4);
                sub_40A670();
                v8 = *(_DWORD*)(a3 + 8);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[105132], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3333);
                LABEL_16:
                sub_450C00(6u, v3, v8);
                return 1;
            }
        }
        else
        {
            v9 = *(_DWORD*)(a3 + 8);
            v7 = loadString_sub_40F1D0((char*)& byte_587000[105188], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3342);
            sub_450C00(6u, v7, v9);
        }
    }
    return 0;
}

//----- (00442C90) --------------------------------------------------------
int __cdecl sub_442C90(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    unsigned __int16* v6; // esi
    wchar_t* v7; // eax
    int v8; // [esp-4h] [ebp-70h]
    int v9; // [esp-4h] [ebp-70h]
    int v10; // [esp-4h] [ebp-70h]
    char v11[100]; // [esp+8h] [ebp-64h]

    if (a2 == 4)
    {
        if (sub_40A5C0(128))
        {
            v8 = *(_DWORD*)(a3 + 8);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[105244], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3361);
            goto LABEL_19;
        }
        if (_nox_wcsicmp(*(const wchar_t**)(a3 + 8), *(const wchar_t**)& byte_587000[94492]))
        {
            v6 = (unsigned __int16*)sub_415A60(*(wchar_t**)(a3 + 8));
            if (v6
                || (nox_sprintf(v11, "%S", *(_DWORD*)(a3 + 8)),
                    (v6 = (unsigned __int16*)sub_415A30(v11)) != 0))
            {
                if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
                {
                    if (sub_4E3BA0(*v6))
                        return 1;
                    sub_4E3BF0((int)v6);
                    sub_40A670();
                    v8 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105412], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3401);
                    LABEL_19:
                    sub_450C00(6u, v3, v8);
                    return 1;
                }
                if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
                {
                    if (!sub_4E3BA0(*v6) || sub_415880((char*)* v6) == 1)
                        return 1;
                    sub_4E3BC0((int)v6);
                    sub_4E5DB0(*v6);
                    sub_40A670();
                    v8 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105468], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3414);
                    goto LABEL_19;
                }
            }
            else
            {
                v10 = *(_DWORD*)(a3 + 8);
                v7 = loadString_sub_40F1D0((char*)& byte_587000[105524], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3423);
                sub_450C00(6u, v7, v10);
            }
        }
        else
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_409E70(2);
                v9 = *(_DWORD*)(a3 + 12);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105296], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3370);
                LABEL_9:
                sub_450C00(6u, v4, v9);
                sub_4AD840();
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_409E70(2);
                v9 = *(_DWORD*)(a3 + 12);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105352], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3377);
                goto LABEL_9;
            }
        }
    }
    return 0;
}

//----- (00442ED0) --------------------------------------------------------
int __cdecl sub_442ED0(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    unsigned __int16* v4; // esi
    wchar_t* v6; // eax
    int v7; // [esp-4h] [ebp-70h]
    int v8; // [esp-4h] [ebp-70h]
    char v9[100]; // [esp+8h] [ebp-64h]

    if (a2 == 4)
    {
        if (sub_40A5C0(128))
        {
            v7 = *(_DWORD*)(a3 + 8);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[105580], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3442);
            LABEL_12:
            sub_450C00(6u, v3, v7);
            return 1;
        }
        v4 = (unsigned __int16*)sub_415EF0(*(wchar_t**)(a3 + 8));
        if (v4
            || (nox_sprintf(v9, "%S", *(_DWORD*)(a3 + 8)),
                (v4 = (unsigned __int16*)sub_415EC0(v9)) != 0))
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                if (!sub_4E3BA0(*v4))
                {
                    sub_4E3BF0((int)v4);
                    sub_40A670();
                    v7 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105636], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3462);
                    goto LABEL_12;
                }
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                if (sub_4E3BA0(*v4))
                {
                    sub_4E3BC0((int)v4);
                    sub_4E5DB0(*v4);
                    sub_40A670();
                    v7 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105692], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3473);
                    goto LABEL_12;
                }
                return 1;
            }
        }
        else
        {
            v8 = *(_DWORD*)(a3 + 8);
            v6 = loadString_sub_40F1D0((char*)& byte_587000[105748], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3481);
            sub_450C00(6u, v6, v8);
        }
    }
    return 0;
}

//----- (00443050) --------------------------------------------------------
int __cdecl sub_443050(int a1, char a2, int a3)
{
    int v3; // edi
    wchar_t* v4; // eax
    wchar_t* v6; // eax
    int v7; // [esp-4h] [ebp-8Ch]
    int v8; // [esp-4h] [ebp-8Ch]
    char v9[128]; // [esp+8h] [ebp-80h]

    if (a2 == 4)
    {
        nox_sprintf(v9, "%S", *(_DWORD*)(a3 + 8));
        v3 = sub_4E3B60(v9);
        if (v3)
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_4E3BF0(v3);
                v7 = *(_DWORD*)(a3 + 8);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105808], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3535);
                LABEL_7:
                sub_450C00(6u, v4, v7);
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_4E3BC0(v3);
                v7 = *(_DWORD*)(a3 + 8);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105864], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3541);
                goto LABEL_7;
            }
        }
        else
        {
            v8 = *(_DWORD*)(a3 + 8);
            v6 = loadString_sub_40F1D0((char*)& byte_587000[105920], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3548);
            sub_450C00(6u, v6, v8);
        }
    }
    return 0;
}

//----- (00443160) --------------------------------------------------------
int __cdecl sub_443160(int a1, char a2, int a3)
{
    wchar_t* v4; // edi
    char* v5; // eax
    char* v6; // esi
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    int v9; // [esp-Ch] [ebp-Ch]

    if (a2 != 2)
        return 0;
    v4 = *(wchar_t**)(a3 + 4 * a1);
    v5 = sub_4170D0(*(wchar_t**)(a3 + 4 * a1));
    v6 = v5;
    if (v5)
    {
        if (v5[2064] == 31)
        {
            v8 = loadString_sub_40F1D0((char*)& byte_587000[106024], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3580);
            sub_440A20(v8);
            return 1;
        }
        if (sub_40A5C0(4096))
            sub_4DCFB0(*((_DWORD*)v6 + 514));
        else
            sub_4DEB00((unsigned __int8)v6[2064]);
        sub_416770(0, v4, v6 + 2112);
        v9 = (int)(v6 + 4704);
        v7 = loadString_sub_40F1D0((char*)& byte_587000[105976], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3577);
    }
    else
    {
        sub_416770(0, v4, 0);
        v9 = (int)v4;
        v7 = loadString_sub_40F1D0((char*)& byte_587000[106080], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3585);
    }
    sub_440A20(v7, v9);
    return 1;
}

//----- (00443250) --------------------------------------------------------
int sub_443250()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106132], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3698);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00443280) --------------------------------------------------------
int sub_443280()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106192], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3704);
    sub_450C00(6u, v0);
    return 1;
}

//----- (004432B0) --------------------------------------------------------
int __cdecl sub_4432B0(int a1, char a2, int a3)
{
    char* v4; // eax
    char* v5; // esi
    wchar_t* v6; // eax
    wchar_t* v7; // eax

    if (a2 != 2)
        return 0;
    v4 = sub_4170D0(*(wchar_t**)(a3 + 4 * a1));
    v5 = v4;
    if (!v4)
        return 1;
    if (v4[2064] == 31)
    {
        v7 = loadString_sub_40F1D0((char*)& byte_587000[106300], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3745);
        sub_440A20(v7);
        return 1;
    }
    if (sub_40A5C0(4096))
    {
        sub_4DCFB0(*((_DWORD*)v5 + 514));
    }
    else
    {
        sub_4DEAB0((unsigned __int8)v5[2064], 4);
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106252], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3739);
        sub_440A20(v6, v5 + 4704);
    }
    return 1;
}

//----- (00443380) --------------------------------------------------------
int __cdecl sub_443380(int a1, char a2, int a3)
{
    int v3; // esi
    const wchar_t* v5; // eax
    int v6; // eax
    wchar_t* v7; // eax

    v3 = 0;
    if (a2 != 3)
        return 0;
    v5 = *(const wchar_t**)(a3 + 8);
    if (v5)
    {
        v6 = nox_wcstol(v5, 0, 10);
        v3 = v6;
        if (v6 >= 0)
        {
            if (v6 > 999)
                v3 = 999;
        }
        else
        {
            v3 = 0;
        }
        if (sub_409FA0() == v3)
            return 1;
        sub_409F80(v3);
        sub_455800();
    }
    v7 = loadString_sub_40F1D0((char*)& byte_587000[106360], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3779);
    sub_440A20(v7, v3);
    return 1;
}

//----- (00443400) --------------------------------------------------------
int __cdecl sub_443400(int a1, char a2, int a3)
{
    char* v4; // esi
    const wchar_t* v5; // eax
    unsigned __int8 v6; // al

    if (a2 != 3)
        return 0;
    v4 = sub_4165B0();
    v5 = *(const wchar_t**)(a3 + 8);
    if (v5)
    {
        v6 = nox_wcstol(v5, 0, 10);
        sub_40A040_settings(*((_WORD*)v4 + 26), v6);
    }
    return 1;
}

//----- (00443440) --------------------------------------------------------
int __cdecl sub_443440(int a1, char a2, int a3)
{
    const wchar_t* v4; // esi
    char* v5; // edi
    unsigned __int16 v6; // ax

    if (a2 != 3)
        return 0;
    v4 = *(const wchar_t**)(a3 + 8);
    v5 = sub_4165B0();
    if (v4)
    {
        v6 = nox_wcstol(v4, 0, 10);
        sub_409FB0_settings(*((_WORD*)v5 + 26), v6);
    }
    return 1;
}

//----- (00443480) --------------------------------------------------------
int sub_443480()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106412], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3830);
    sub_450C00(6u, v0);
    return 1;
}

//----- (004434B0) --------------------------------------------------------
int sub_4434B0()
{
    wchar_t* v0; // eax
    char* i; // esi
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    wchar_t v5[128]; // [esp+4h] [ebp-100h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106472], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3839);
    sub_450C00(6u, v0);
    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        v5[0] = 0;
        nox_wcscat(v5, (const wchar_t*)i + 2352);
        if (*(_DWORD*)& byte_5D4594[823684] && i[3680] & 4)
        {
            nox_wcscat(v5, L", ");
            v2 = loadString_sub_40F1D0((char*)& byte_587000[106532], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3851);
            nox_wcscat(v5, v2);
        }
        if (i[3680] & 8)
        {
            nox_wcscat(v5, L", ");
            v3 = loadString_sub_40F1D0((char*)& byte_587000[106592], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3857);
            nox_wcscat(v5, v3);
        }
        sub_450C00(6u, (wchar_t*)& byte_587000[106604], v5);
    }
    return 1;
}

//----- (004435C0) --------------------------------------------------------
int sub_4435C0()
{
    sub_450B70();
    return 1;
}

//----- (004435D0) --------------------------------------------------------
int sub_4435D0()
{
    if (!sub_40A5C0(8) && sub_40A5C0(0x2000))
        sub_457500();
    return 1;
}

//----- (00443600) --------------------------------------------------------
int sub_443600()
{
    sub_4ADA40();
    return 1;
}

//----- (00443610) --------------------------------------------------------
int __cdecl sub_443610(int a1, unsigned __int8 a2, int a3)
{
    wchar_t** v3; // esi
    int v4; // eax
    int v5; // eax
    wchar_t* v6; // eax
    wchar_t* v8; // [esp-4h] [ebp-14h]

    if (a2 < 2u || a2 > 3u)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[823684])
    {
        v3 = (wchar_t**)(a3 + 4 * a1);
        goto LABEL_8;
    }
    v3 = (wchar_t**)(a3 + 4 * a1);
    if (_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94496]))
    {
        LABEL_8:
        v5 = sub_57A0F0(*v3);
        goto LABEL_9;
    }
    v4 = a1 + 1;
    if (a1 + 1 != a2 - 1)
        return 0;
    v3 = (wchar_t**)(a3 + 4 * v4);
    v5 = sub_57A130(*(wchar_t**)(a3 + 4 * v4));
    LABEL_9:
    v8 = *v3;
    if (v5)
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106708], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3923);
    else
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106652], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3921);
    sub_450C00(6u, v6, v8);
    return 1;
}

//----- (004436E0) --------------------------------------------------------
int __cdecl sub_4436E0(int a1, unsigned __int8 a2, int a3)
{
    wchar_t** v3; // esi
    int v4; // eax
    int v5; // eax
    wchar_t* v6; // eax
    wchar_t* v8; // [esp-4h] [ebp-14h]

    if (a2 < 2u || a2 > 3u)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[823684])
    {
        v3 = (wchar_t**)(a3 + 4 * a1);
        goto LABEL_8;
    }
    v3 = (wchar_t**)(a3 + 4 * a1);
    if (_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94496]))
    {
        LABEL_8:
        v5 = sub_57A080(*v3);
        goto LABEL_9;
    }
    v4 = a1 + 1;
    if (a1 + 1 != a2 - 1)
        return 0;
    v3 = (wchar_t**)(a3 + 4 * v4);
    v5 = sub_57A0C0(*(wchar_t**)(a3 + 4 * v4));
    LABEL_9:
    v8 = *v3;
    if (v5)
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106812], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3961);
    else
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106756], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3959);
    sub_450C00(6u, v6, v8);
    return 1;
}

//----- (004437B0) --------------------------------------------------------
int __cdecl sub_4437B0(int a1, char a2)
{
    wchar_t* v3; // eax
    int v4; // [esp-4h] [ebp-4h]

    if (a2 != 2)
        return 0;
    if (!sub_40A5C0(1))
    {
        v4 = *(_DWORD*)& byte_5D4594[823700];
        v3 = loadString_sub_40F1D0((char*)& byte_587000[106860], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3979);
        sub_450C00(6u, v3, v4);
    }
    sub_440950(1, *(wchar_t**)& byte_5D4594[823700]);
    return 1;
}

//----- (00443810) --------------------------------------------------------
int __cdecl sub_443810(int a1, char a2, int a3)
{
    wchar_t* v4; // eax
    wchar_t v5[128]; // [esp+0h] [ebp-100h]

    if (a2 != 2)
        return 0;
    nox_wcscpy(v5, *(const wchar_t**)(a3 + 4));
    if (!nox_wcschr(v5, 0x2Eu))
        nox_wcscat(v5, L".rul");
    v4 = loadString_sub_40F1D0((char*)& byte_587000[106924], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4002);
    sub_450C00(6u, v4, v5);
    sub_4438A0((int)v5);
    return 1;
}

//----- (004438A0) --------------------------------------------------------
int __cdecl sub_4438A0(int a1)
{
    FILE* v1; // eax
    FILE* v2; // esi
    char* v3; // eax
    char v5[256]; // [esp+8h] [ebp-400h]
    char v6[256]; // [esp+108h] [ebp-300h]
    wchar_t v7[128]; // [esp+208h] [ebp-200h]

    if (!a1)
        return 0;
    v6[0] = 0;
    nox_sprintf(v6, "%S", a1);
    v1 = fopen(v6, "r");
    v2 = v1;
    if (!v1)
        return 0;
    if (!feof(v1))
    {
        do
        {
            memset(v5, 0, 0xFCu);
            *(_WORD*)& v5[252] = 0;
            v5[254] = 0;
            fgets(v5, 255, v2);
            v3 = strchr(v5, 10);
            if (v3)
                * v3 = 0;
            if (v5[0])
            {
                nox_swprintf(v7, L"%S", v5);
                sub_450C00(4u, (wchar_t*)& byte_587000[106956], v7);
                sub_443C80(v7, 1);
            }
        } while (!feof(v2));
    }
    fclose(v2);
    return 1;
}

//----- (004439B0) --------------------------------------------------------
int __cdecl sub_4439B0(int a1, unsigned __int8 a2)
{
    wchar_t* v2; // eax
    int result; // eax
    wchar_t* v4; // eax

    if (a2 == 1)
    {
        *(_DWORD*)& byte_5D4594[823696] = 1;
        v2 = loadString_sub_40F1D0((char*)& byte_587000[107008], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4014);
        sub_450C00(6u, v2);
        result = 1;
    }
    else
    {
        if (a2 > 1u && *(_DWORD*)& byte_5D4594[823688])
        {
            v4 = nox_wcsstr(*(const wchar_t**)& byte_5D4594[823700], L" ");
            if (v4)
                sub_440950(2, v4);
        }
        result = 1;
    }
    return result;
}

//----- (00443A20) --------------------------------------------------------
int __cdecl sub_443A20(int a1, int a2, int a3, const wchar_t** a4, int a5)
{
    int v5; // eax
    int v6; // ecx
    int v7; // edi
    const wchar_t** v8; // ebp
    const wchar_t** v9; // esi
    const wchar_t* v10; // eax
    const wchar_t** v12; // esi
    char v13; // al
    wchar_t* v14; // eax
    const wchar_t** v15; // ecx
    int v16; // eax
    wchar_t* v17; // eax
    int v18; // [esp+10h] [ebp-44h]
    wchar_t v19[256]; // [esp+14h] [ebp-40h]

    v5 = a3;
    v6 = a1;
    v7 = 0;
    v18 = 0;
    if (!*(_DWORD*)(a3 + 4 * a1) || !a4 || !*a4)
        return v18;
    v8 = a4;
    v9 = a4;
    while (1)
    {
        if ((_BYTE)v8[3] & 0x40)
            sub_443BF0(*(unsigned __int16**)(v5 + 4 * v6), (char*)v19);
        else
            nox_wcscpy(v19, *(const wchar_t**)(v5 + 4 * v6));
        if (!_nox_wcsicmp(v19, *v8))
            break;
        v10 = v9[6];
        v9 += 6;
        ++v7;
        v8 = v9;
        if (!v10)
            return 0;
        v6 = a1;
        v5 = a3;
    }
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000) && *(_DWORD*)& byte_587000[94464] && (int)a4[6 * v7 + 3] & 0x10)
        return 0;
    if (*(_DWORD*)& byte_5D4594[823684])
    {
        v12 = &a4[6 * v7];
        v13 = (char)a4[6 * v7 + 3];
        if (!(v13 & 1))
        {
            v14 = loadString_sub_40F1D0((char*)& byte_587000[107068], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4091);
            LABEL_21:
            sub_450C00(6u, v14);
            return 1;
        }
    }
    else
    {
        v13 = (char)a4[6 * v7 + 3];
        v12 = &a4[6 * v7];
        if (!(v13 & 2))
        {
            v14 = loadString_sub_40F1D0((char*)& byte_587000[107120], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4097);
            goto LABEL_21;
        }
    }
    if (v13 & 0x20 && !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
        return 1;
    v15 = (const wchar_t**)v12[4];
    if (v15)
    {
        if ((unsigned __int8)a2 <= a1 + 1)
        {
            LABEL_30:
            v17 = loadString_sub_40F1D0((char*)v12[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4125);
            sub_450C00(6u, v17);
            return 1;
        }
        v16 = sub_443A20(a1 + 1, a2, a3, v15, a5);
    }
    else
    {
        v16 = ((int(__cdecl*)(int, int, int))v12[5])(a1 + 1, a2, a3);
    }
    v18 = v16;
    if (!v16)
        goto LABEL_30;
    return v18;
}

//----- (00443BF0) --------------------------------------------------------
void __cdecl sub_443BF0(unsigned __int16* a1, char* a2)
{
    int v2; // esi
    signed int v3; // ebp
    unsigned __int16 v4; // ax
    unsigned __int16* v5; // ecx
    int v6; // edx

    v2 = 0;
    if (a1)
    {
        if (a2 && (v3 = nox_wcslen(*(const wchar_t**)& byte_587000[98256]), (v4 = *a1) != 0))
        {
            v5 = a1;
            do
            {
                ++v5;
                v6 = (unsigned __int8)(v2++ * (v4 - 1) % v3);
                *(unsigned __int16*)((char*)v5 - (char*)a1 + a2 - 2) = *(_WORD*)(*(_DWORD*)& byte_587000[98256] + 2 * v6);
                v4 = *v5;
            } while (*v5);
            *(_WORD*)& a2[2 * v2] = 0;
        }
        else
        {
            *(_WORD*)a2 = 0;
        }
    }
    else
    {
        *(_WORD*)a2 = 0;
    }
}

//----- (00443C80) --------------------------------------------------------
int __cdecl sub_443C80(wchar_t* a1, int a2)
{
    int v2; // ebp
    char v3; // bl
    int result; // eax
    wchar_t* v5; // esi
    int v6; // eax
    int v7; // ecx
    wchar_t* v8; // eax
    wchar_t* v9; // eax
    int v10; // [esp+10h] [ebp-88h]
    int v11; // [esp+14h] [ebp-84h]
    int v12[32]; // [esp+18h] [ebp-80h]

    v2 = 0;
    v3 = 0;
    v11 = 0;
    LOBYTE(v10) = 0;
    if (a1)
    {
        *(_DWORD*)& byte_5D4594[823700] = a1;
        memset(&byte_5D4594[820276], 0, 0x800u);
        if (sub_40A5C0(1))
        {
            *(_DWORD*)& byte_5D4594[823684] = 1;
            *(_DWORD*)& byte_5D4594[823688] = 0;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[823684] = 0;
            *(_DWORD*)& byte_5D4594[823688] = 1;
        }
        if (*(_DWORD*)& byte_5D4594[823696])
        {
            sub_4409D0(a1);
            result = 1;
            *(_DWORD*)& byte_5D4594[823696] = 0;
            return result;
        }
        nox_wcscpy((wchar_t*)& byte_5D4594[820276], a1);
        if (*(_WORD*)& byte_5D4594[820276] == 34)
        {
            v5 = nox_wcstok((wchar_t*)& byte_5D4594[820278], L"\"\n\r");
            v2 = 1;
        }
        else
        {
            v5 = nox_wcstok((wchar_t*)& byte_5D4594[820276], L" ");
        }
        if (v5)
        {
            do
            {
                v6 = (int)v5;
                if (!v2)
                {
                    v6 = sub_443E40(v5);
                    if (!v6)
                        v6 = (int)v5;
                }
                v7 = (unsigned __int8)v10;
                LOBYTE(v10) = ++v3;
                v12[v7] = v6;
                v8 = &v5[nox_wcslen(v5) + 1];
                if (v2)
                    ++v8;
                if (*v8 == 34)
                {
                    v5 = nox_wcstok(v8 + 1, L"\"\n\r");
                    v2 = 1;
                }
                else
                {
                    v5 = nox_wcstok(0, L" ");
                    v2 = 0;
                }
            } while (v5);
            if (v3)
            {
                v11 = sub_443A20(0, v10, (int)v12, (const wchar_t**)& byte_587000[97368], a2);
                if (!v11)
                {
                    v9 = loadString_sub_40F1D0((char*)& byte_587000[107236], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4226);
                    sub_450C00(6u, v9);
                }
            }
        }
    }
    result = v11;
    *(_DWORD*)& byte_5D4594[823700] = 0;
    return result;
}
// 443DEE: variable 'v10' is possibly undefined
// 443C80: using guessed type int var_80[32];

//----- (00443E40) --------------------------------------------------------
int __cdecl sub_443E40(wchar_t* a1)
{
    int v1; // esi
    const wchar_t** i; // edi

    v1 = 0;
    if (*(int*)& byte_5D4594[823708] <= 0)
        return 0;
    for (i = (const wchar_t**)& byte_5D4594[816504]; _nox_wcsicmp(a1, *i); i += 2)
    {
        if (++v1 >= *(int*)& byte_5D4594[823708])
            return 0;
    }
    return *(_DWORD*)& byte_5D4594[8 * v1 + 816500];
}

//----- (00443E90) --------------------------------------------------------
int __cdecl sub_443E90(int a1, char a2, wchar_t* a3)
{
    int v3; // ecx
    int result; // eax
    BOOL v5; // edi
    wchar_t* v6; // ebx
    int v7; // eax
    int v8; // eax
    wchar_t* v9; // eax
    wchar_t* v10; // esi
    int v11; // edi
    wchar_t* v12; // eax
    wchar_t* v13; // eax
    char* v14; // esi
    int v15; // eax
    wchar_t* v16; // eax
    char* v17; // esi
    wchar_t* v18; // eax
    int v19; // [esp-8h] [ebp-94h]
    int v20; // [esp-8h] [ebp-94h]
    wchar_t* v21; // [esp-4h] [ebp-90h]
    char v22[128]; // [esp+Ch] [ebp-80h]

    if (!a1 || !*(_DWORD*)(a1 + 2056))
        return 0;
    if (a3)
        nox_wcscpy((wchar_t*)& byte_5D4594[818228], a3);
    else
        *(_WORD*)& byte_5D4594[818228] = 0;
    v3 = a1;
    *(_DWORD*)& byte_5D4594[823692] = a1;
    if (a2 != 4 && a2 != 5 && a2)
    {
        if (sub_40A5C0(49152))
            return 1;
        v3 = *(_DWORD*)& byte_5D4594[823692];
    }
    switch (a2)
    {
        case 0:
            if (sub_40A5C0(8) || sub_40A5C0(4096) || *(_BYTE*)(a1 + 3680) & 1)
                goto LABEL_61;
            v5 = *(short*)& byte_5D4594[818228] == -4083
                 && *(short*)& byte_5D4594[818230] == -3923
                 && !*(_WORD*)& byte_5D4594[818232];
            if (sub_4E6860(a1, v5, 0) != 1)
                goto LABEL_61;
            v6 = loadString_sub_40F1D0((char*)& byte_587000[107288], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4287);
            v7 = sub_40A8A0();
            if (v7)
            {
                if (!v5)
                    sub_4174F0(a1, 256);
                if (sub_40A5C0(1024) && sub_40A770() == 1)
                    sub_5095E0();
            }
            v8 = *(_DWORD*)(a1 + 2056);
            if (v8)
                sub_419570(v8 + 48, *(_DWORD*)(a1 + 2060));
            v21 = v6;
            v9 = loadString_sub_40F1D0((char*)& byte_587000[107332], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4308);
            goto LABEL_38;
        case 1:
            if (!sub_4D12A0(*(unsigned __int8*)(a1 + 2064))
                && *(unsigned __int8*)(a1 + 2064) != *(_DWORD*)& byte_5D4594[2616328]
                && !sub_40A5C0(2048))
            {
                goto LABEL_61;
            }
            nox_wcstok((wchar_t*)& byte_5D4594[818228], L" ");
            v10 = nox_wcstok(0, L" ");
            nox_sprintf(v22, "%S", v10);
            v11 = sub_5071D0(v22);
            if (v11 != -1 && *(_DWORD*)& byte_5D4594[823692])
            {
                v12 = loadString_sub_40F1D0((char*)& byte_587000[107456], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4332);
                sub_450C00(6u, v12, v10);
                sub_507310(
                        v11,
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[823692] + 2056),
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[823692] + 2056));
                *(_DWORD*)& byte_5D4594[823692] = 0;
                result = 1;
            }
            else
            {
                v21 = v10;
                v9 = loadString_sub_40F1D0((char*)& byte_587000[107400], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4329);
                LABEL_38:
                sub_450C00(6u, v9, v21);
                *(_DWORD*)& byte_5D4594[823692] = 0;
                result = 1;
            }
            return result;
        case 2:
            if (!sub_4D12A0(*(unsigned __int8*)(a1 + 2064))
                && *(unsigned __int8*)(a1 + 2064) != *(_DWORD*)& byte_5D4594[2616328]
                && !sub_40A5C0(2048))
            {
                goto LABEL_61;
            }
            v19 = *(_DWORD*)& byte_5D4594[823692] + 4704;
            v13 = loadString_sub_40F1D0((char*)& byte_587000[107516], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4345);
            sub_450C00(6u, v13, v19, a3);
            sub_443C80(a3, 0);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            return 1;
        case 3:
            sub_4D9FD0(0, a3);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            return 1;
        case 4:
            if (!(*(_BYTE*)(v3 + 3680) & 1) && !(*(_DWORD*)& byte_5D4594[2650636] & 0x400000))
            {
                if (sub_40A5C0(1))
                {
                    v16 = loadString_sub_40F1D0((char*)& byte_587000[107568], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4392);
                    sub_450C00(6u, v16);
                    *(_DWORD*)& byte_5D4594[823692] = 0;
                    return 1;
                }
                LABEL_61:
                *(_DWORD*)& byte_5D4594[823692] = 0;
                return 1;
            }
            if (!*a3)
            {
                sub_4E6040(*(_DWORD*)(v3 + 2056));
                *(_DWORD*)& byte_5D4594[823692] = 0;
                return 1;
            }
            v17 = sub_416EA0();
            if (!v17)
                goto LABEL_61;
            do
            {
                if (!_nox_wcsicmp(a3, (const wchar_t*)v17 + 2352))
                    sub_4E6060(*(_DWORD*)(*(_DWORD*)& byte_5D4594[823692] + 2056), *((_DWORD*)v17 + 514));
                v17 = sub_416EE0((int)v17);
            } while (v17);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            result = 1;
            break;
        case 5:
            sub_4D9FD0(16, a3);
            v14 = sub_416EA0();
            if (!v14)
                goto LABEL_61;
            do
            {
                v15 = *((_DWORD*)v14 + 514);
                if (v15)
                    sub_501960(902, v15, 0, 0);
                v14 = sub_416EE0((int)v14);
            } while (v14);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            return 1;
        default:
            v20 = v3 + 4704;
            v18 = loadString_sub_40F1D0((char*)& byte_587000[107624], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4400);
            sub_450C00(6u, v18, v20, a3);
            goto LABEL_61;
    }
    return result;
}
// 443FC8: variable 'v7' is possibly undefined

//----- (004443B0) --------------------------------------------------------
void __cdecl sub_4443B0(unsigned __int8 a1)
{
    char* v1; // eax
    wchar_t* v2; // esi

    if (a1 >= 0x3Bu && a1 <= 0x58u)
    {
        if (*(_DWORD*)& byte_587000[95416])
        {
            v1 = sub_444410(a1);
            v2 = (wchar_t*)v1;
            if (v1)
            {
                if (*(_WORD*)v1)
                {
                    sub_450C00(4u, (wchar_t*)& byte_587000[107640], v1);
                    sub_443C80(v2, 0);
                    sub_4309B0(a1, 1);
                }
            }
        }
    }
}

//----- (00444410) --------------------------------------------------------
char* __cdecl sub_444410(int a1)
{
    char* result; // eax
    int v2; // edx
    unsigned __int8* v3; // ecx

    result = 0;
    v2 = 0;
    v3 = &byte_587000[94512];
    while (a1 != *(_DWORD*)v3)
    {
        v3 += 76;
        ++v2;
        if ((int)v3 >= (int)& byte_587000[95424])
            return result;
    }
    return (char*)& byte_587000[76 * v2 + 94516];
}

//----- (00444440) --------------------------------------------------------
void __cdecl sub_444440(int* a1)
{
    int* v1; // edi
    int* v2; // ebx
    wchar_t* v3; // esi
    int v4; // eax
    char v5[64]; // [esp+4h] [ebp-40h]

    v1 = a1;
    if (*a1)
    {
        v2 = a1;
        do
        {
            nox_sprintf(v5, "cmd_token:%S", *v1);
            v3 = loadString_sub_40F1D0(v5, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4441);
            v1[1] = (int)v3;
            sub_4444C0(*v1, (int)v3);
            if (nox_wcslen(v3) < 0x20)
            {
                if (v2[4])
                    sub_444440((int*)v2[4]);
            }
            v4 = v2[6];
            v2 += 6;
            v1 = v2;
        } while (v4);
    }
}

//----- (004444C0) --------------------------------------------------------
int __cdecl sub_4444C0(int a1, int a2)
{
    int v2; // eax
    int result; // eax

    v2 = *(_DWORD*)& byte_5D4594[823708];
    *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[823708] + 816500] = a1;
    *(_DWORD*)& byte_5D4594[8 * v2 + 816504] = a2;
    result = v2 + 1;
    *(_DWORD*)& byte_5D4594[823708] = result;
    return result;
}

//----- (004444F0) --------------------------------------------------------
int sub_4444F0()
{
    int* v0; // esi
    wchar_t* v1; // eax
    char v3[80]; // [esp+4h] [ebp-50h]

    sub_444560();
    v0 = (int*)& byte_587000[94468];
    do
    {
        nox_sprintf(v3, "cmd_token:%S", *v0);
        v1 = loadString_sub_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4476);
        sub_4444C0(*v0, (int)v1);
        ++v0;
    } while ((int)v0 < (int)& byte_587000[94500]);
    *(_DWORD*)& byte_5D4594[823696] = 0;
    sub_444440((int*)& byte_587000[97368]);
    return sub_444570();
}

//----- (00444560) --------------------------------------------------------
void sub_444560()
{
    *(_DWORD*)& byte_5D4594[823708] = 0;
}

//----- (00444570) --------------------------------------------------------
int sub_444570()
{
    int* v0; // esi
    wchar_t* v1; // eax
    int result; // eax
    char v3[80]; // [esp+4h] [ebp-50h]

    v0 = (int*)& byte_587000[94504];
    do
    {
        nox_sprintf(v3, "keybind:%S", *v0);
        v1 = loadString_sub_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 874);
        v0[1] = (int)v1;
        result = sub_4444C0(*v0, (int)v1);
        v0 += 19;
    } while ((int)v0 < (int)& byte_587000[95416]);
    return result;
}

//----- (004445C0) --------------------------------------------------------
void sub_4445C0()
{
    int v0; // ebx
    int v4; // ebx
    int v5; // ebp
    int v6; // eax
    int v7; // eax
    int result; // eax
    int v9; // [esp+10h] [ebp-Ch]
    int v10; // [esp+14h] [ebp-8h]
    int v11; // [esp+18h] [ebp-4h]

#if 0
    signed int v1; // eax
    int v2; // esi
    int v3; // eax
    if (sub_444D90())
    {
        v1 = sub_444DD0();
        v2 = v1;
        if (v1)
        {
            v3 = v1 + 5;
            if (v2 + 5 <= 450)
            {
                if (v3 <= 300)
                {
                    if (v3 <= 266)
                        v0 = v3 <= 200 ? 0 : 0xC8;
                    else
                        v0 = 266;
                }
                else
                {
                    v0 = 300;
                }
            }
            else
            {
                v0 = 450;
            }
        }
        else
        {
            v0 = 0;
        }
        if (!sub_444830() && v2 < 550)
            v0 = 200;
    }
    else
#endif
    {
        v0 = 0;
    }
    *(_DWORD*)& byte_587000[80808] = 1;
    *(_DWORD*)& byte_587000[80816] = 1;
    *(_DWORD*)& byte_587000[80840] = 1;
    *(_DWORD*)& byte_587000[80828] = 1;
    *(_DWORD*)& byte_587000[80832] = 1;
    if (v0 <= 266)
    {
        if (v0 != 266)
        {
            if (!v0)
            {
                v4 = 8;
                v5 = 75;
                *(_DWORD*)& byte_587000[80812] = 0;
                goto LABEL_21;
            }
            if (v0 == 200)
            {
                v4 = 8;
                v5 = 85;
                *(_DWORD*)& byte_587000[80812] = 1;
                LABEL_21:
                v6 = *(_DWORD*)& byte_5D4594[2650636];
                *(_DWORD*)& byte_5D4594[805844] = 0;
                BYTE1(v6) &= 0xFBu;
                *(_DWORD*)& byte_587000[80820] = 0;
                *(_DWORD*)& byte_587000[154952] = 0;
                *(_DWORD*)& byte_5D4594[1193152] = 0;
                *(_DWORD*)& byte_587000[154956] = 1;
                *(_DWORD*)& byte_587000[80824] = 0;
                *(_DWORD*)& byte_5D4594[805852] = 0;
                *(_DWORD*)& byte_587000[80836] = 0;
                *(_DWORD*)& byte_5D4594[2650636] = v6;
                *(_DWORD*)& byte_587000[80844] = 0;
                goto LABEL_30;
            }
            goto LABEL_29;
        }
        v4 = 8;
        goto LABEL_27;
    }
    if (v0 == 300)
    {
        v4 = 16;
        LABEL_27:
        v5 = 100;
        *(_DWORD*)& byte_587000[80812] = 1;
        *(_DWORD*)& byte_5D4594[805844] = 1;
        *(_DWORD*)& byte_587000[80820] = 1;
        *(_DWORD*)& byte_587000[154952] = 1;
        *(_DWORD*)& byte_5D4594[1193152] = 0;
        *(_DWORD*)& byte_587000[154956] = 1;
        *(_DWORD*)& byte_587000[80824] = 0;
        goto LABEL_28;
    }
    if (v0 == 450)
    {
        v4 = 16;
        v5 = 100;
        *(_DWORD*)& byte_587000[80812] = 1;
        *(_DWORD*)& byte_5D4594[805844] = 1;
        *(_DWORD*)& byte_587000[80820] = 1;
        *(_DWORD*)& byte_587000[154952] = 1;
        *(_DWORD*)& byte_5D4594[1193152] = 1;
        *(_DWORD*)& byte_587000[154956] = 1;
        *(_DWORD*)& byte_587000[80824] = 1;
        LABEL_28:
        v7 = *(_DWORD*)& byte_5D4594[2650636];
        *(_DWORD*)& byte_5D4594[805852] = 1;
        BYTE1(v7) |= 4u;
        *(_DWORD*)& byte_587000[80836] = 1;
        *(_DWORD*)& byte_5D4594[2650636] = v7;
        *(_DWORD*)& byte_587000[80844] = 1;
        goto LABEL_30;
    }
    LABEL_29:
    v4 = v9;
    v5 = v9;
    LABEL_30:
    sub_43BEB0_get_video_mode(&v11, &v10, &v9);
    v4 = 16; // 8 bit not supported
    sub_481420();
    if (!(byte_5D4594[2650637] & 2))
        sub_43BEF0_set_video_mode(default_win_width, default_win_height, v4);
    sub_4766A0(v5);
    if (sub_40A5C0(0x10000000))
        sub_476700(v5, 0);
    *(_DWORD*)& byte_5D4594[805856] = 1;
}
BOOL sub_444830()
{
    DebugBreak();
    return 0;
}
#if 0
//----- (00444830) --------------------------------------------------------
BOOL sub_444830()
{
    unsigned __int8 v11[40]; // [esp+Ch] [ebp-28h]

    _EAX = 0;
    __asm { cpuid }
    _EAX = 0;
    __asm { cpuid }
    return strcmp("GenuineIntel", (const char*)v11) == 0;
}
#endif

//----- (004449D0) --------------------------------------------------------
int __cdecl sub_4449D0(HWND wnd, int w, int h, int depth, int flags)
{
    int result; // eax

    result = sub_444AC0(wnd, w, h, depth, flags);
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_47D200();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_486090();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4B0B30();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4408E0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_49F610();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4338D0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AD100();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_48B1F0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_44D9A0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4B0650();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_49E3F0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_48C560();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4B02D0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AF8D0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AEE80();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AE520();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_49CB50();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_43F1C0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AE400();
    printf("%s: %d\n", __FUNCTION__, result);
    if (result)
        result = sub_49F4A0();
    printf("%s: %d\n", __FUNCTION__, result);
    return result;
}

// 4408F0: using guessed type void nullsub_3(void);
// 47D2B0: using guessed type void nullsub_6(void);
// 48C570: using guessed type void nullsub_11(void);
// 49CC60: using guessed type void nullsub_12(void);
// 49E4A0: using guessed type void nullsub_13(void);
// 49F6C0: using guessed type void nullsub_14(void);
// 4AD140: using guessed type void nullsub_15(void);
// 4AE410: using guessed type void nullsub_16(void);
// 4AEE90: using guessed type void nullsub_17(void);
// 4B02F0: using guessed type void nullsub_18(void);
// 4B0B80: using guessed type void nullsub_19(void);

//----- (00444D00) --------------------------------------------------------
void sub_444D00()
{
    EnterCriticalSection((LPCRITICAL_SECTION)& byte_5D4594[3799596]);
    sub_48A190();
    sub_4AD150();
    LeaveCriticalSection((LPCRITICAL_SECTION)& byte_5D4594[3799596]);
}

//----- (00444D30) --------------------------------------------------------
void sub_444D30()
{
    qmemcpy(ptr_5D4594_3799572, &obj_5D4594_3799660, sizeof(obj_5D4594_3799572_t));
}

//----- (00444D50) --------------------------------------------------------
void __cdecl sub_444D50(obj_5D4594_3799572_t* a1)
{
    qmemcpy(a1, ptr_5D4594_3799572, sizeof(obj_5D4594_3799572_t));
}

//----- (00444D70) --------------------------------------------------------
void __cdecl sub_444D70(obj_5D4594_3799572_t* a1)
{
    qmemcpy(ptr_5D4594_3799572, a1, sizeof(obj_5D4594_3799572_t));
}

#if 0
//----- (00444D90) --------------------------------------------------------
BOOL sub_444D90()
{
    unsigned int v0; // edx
    unsigned int v1; // et0
    unsigned int v2; // ebx
    unsigned int v3; // et0

    v0 = 0;
    v1 = __readeflags();
    v2 = v1;
    __writeeflags(v1 ^ 0x200000);
    v3 = __readeflags();
    if (v3 != v2)
    {
        _EAX = 0;
        __asm { cpuid }
        v0 = 0;
        if (BYTE1(_EAX) != 5)
        {
            if (_EAX)
            {
                _EAX = 1;
                __asm { cpuid }
                v0 = 0x800000 & _EDX;
            }
        }
    }
    return v0 != 0;
}

//----- (00444DD0) --------------------------------------------------------
signed int sub_444DD0()
{
    int v0; // ecx
    int v1; // eax
    unsigned int v2; // ebx
    unsigned __int64 v3; // rax
    unsigned __int64 v4; // rax
    unsigned int v5; // esi
    DWORD v6; // edi
    int v7; // eax
    unsigned int v8; // ecx
    signed int result; // eax
    LARGE_INTEGER Frequency; // [esp+4h] [ebp-30h]
    LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-28h]
    LARGE_INTEGER v12; // [esp+14h] [ebp-20h]
    int v13; // [esp+1Ch] [ebp-18h]
    int v14; // [esp+20h] [ebp-14h]
    int v15; // [esp+24h] [ebp-10h]
    unsigned int v16; // [esp+28h] [ebp-Ch]
    int v17; // [esp+2Ch] [ebp-8h]
    int v18; // [esp+30h] [ebp-4h]

    if (!QueryPerformanceFrequency(&Frequency))
        return 0;
    v0 = 0;
    v1 = 0;
    v2 = 0;
    v16 = 0;
    v18 = 0;
    while (1)
    {
        v17 = v0;
        ++v18;
        v15 = v1;
        QueryPerformanceCounter(&PerformanceCount);
        v12 = PerformanceCount;
        do
            QueryPerformanceCounter(&v12);
        while (v12.LowPart - PerformanceCount.LowPart < 0x32);
        v3 = __rdtsc();
        v13 = v3;
        PerformanceCount = v12;
        do
            QueryPerformanceCounter(&v12);
        while (v12.LowPart - PerformanceCount.LowPart < 0x3E8);
        v4 = __rdtsc();
        v14 = v4;
        v5 = v4 - v13;
        v2 += v4 - v13;
        v6 = (100000 * v12.LowPart - 100000 * PerformanceCount.LowPart) / (Frequency.LowPart / 0xA);
        v16 += v6;
        if (v6 % Frequency.LowPart > Frequency.LowPart >> 1)
            ++v6;
        v0 = v5 / v6;
        if (v5 % v6 > v6 >> 1)
            ++v0;
        v7 = v0 + v15 + v17;
        if (v18 >= 3
            && (v18 >= 20
                || (unsigned int)(3 * v0 - v7) <= 3 && (unsigned int)(3 * v17 - v7) <= 3 && (unsigned int)(3 * v15 - v7) <= 3))
        {
            break;
        }
        v1 = v17;
    }
    v8 = 10 * v2 / v16;
    if (100 * v2 / v16 - 10 * v8 >= 6)
        ++v8;
    result = v2 / v16;
    if (v8 - 10 * (v2 / v16) >= 6)
        ++result;
    if (result < 0)
        result = 0;
    return result;
}
#endif

//----- (00445440) --------------------------------------------------------
int sub_445440()
{
    return 1;
}

//----- (00445450) --------------------------------------------------------
wchar_t* sub_445450()
{
    unsigned __int8* v0; // esi
    wchar_t* result; // eax

    v0 = &byte_5D4594[824440];
    do
    {
        result = nox_wcscpy((wchar_t*)v0 - 318, (const wchar_t*)& byte_5D4594[825740]);
        *(_DWORD*)v0 = 0;
        v0[4] = 0;
        v0 += 644;
    } while ((int)v0 < (int)& byte_5D4594[826372]);
    *(_DWORD*)& byte_5D4594[825736] = 0;
    return result;
}

//----- (00445530) --------------------------------------------------------
int sub_445530()
{
    char* v0; // eax
    int v1; // ebp
    int v2; // eax
    int v3; // ebx
    int result; // eax
    int v5; // ebx
    unsigned __int16* v6; // ebx
    int v7; // kr00_4
    unsigned __int8* v8; // esi
    int v9; // edi
    int v10; // esi
    int v11; // ecx
    int i; // [esp+10h] [ebp-Ch]
    int v13; // [esp+14h] [ebp-8h]
    int v14; // [esp+18h] [ebp-4h]

    v13 = 0;
    v0 = sub_437250();
    v1 = 3 * *((_DWORD*)v0 + 9) / 4 + *((_DWORD*)v0 + 1) - 15;
    v2 = *(_DWORD*)& byte_5D4594[825736];
    for (i = *(_DWORD*)& byte_5D4594[825736]; ; v2 = i)
    {
        v3 = 161 * v2;
        result = *(_DWORD*)& byte_5D4594[2598000];
        v5 = 4 * v3;
        if (*(_DWORD*)& byte_5D4594[v5 + 824440] < *(int*)& byte_5D4594[2598000])
            break;
        sub_434390(*(int*)& byte_5D4594[2650656]);
        v6 = (unsigned __int16*)& byte_5D4594[v5 + 823804];
        sub_43F840(0, v6, &v14, 0, 0);
        v7 = nox_win_width - v14;
        v8 = &byte_587000[107848];
        v9 = (nox_win_width - v14) / 2;
        do
        {
            sub_43F6E0(0, (__int16*)v6, v9 + *(_DWORD*)v8, v1 + *((_DWORD*)v8 + 1));
            v8 += 8;
        } while ((int)v8 < (int)& byte_587000[107880]);
        v10 = v13;
        if (v13)
            sub_434390(*(int*)& byte_5D4594[2597996]);
        else
            sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43F6E0(0, (__int16*)v6, v7 / 2, v1);
        v11 = -4 - sub_43F320(0);
        result = i;
        v1 += v11;
        if (i)
            --i;
        else
            i = 2;
        ++v13;
        if (v10 + 1 >= 3)
            break;
    }
    return result;
}

//----- (004456E0) --------------------------------------------------------
int __cdecl sub_4456E0(int* a1)
{
    int* v1; // esi
    int v2; // edx
    int v4; // [esp+4h] [ebp-4h]

    v1 = a1;
    sub_46AA60(a1, &a1, &v4);
    v2 = v1[25];
    a1 = (int*)((char*)a1 + v1[24]);
    sub_47D2C0(v1[15], (int)a1, v2 + v4);
    return 1;
}

//----- (00445730) --------------------------------------------------------
int __cdecl sub_445730(int a1)
{
    return nox_window_set_hidden(*(int*)& byte_5D4594[825744], a1);
}

//----- (00445750) --------------------------------------------------------
BOOL sub_445750()
{
    return *(_DWORD*)& byte_5D4594[825744] && !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[825744]);
}

//----- (00445770) --------------------------------------------------------
int sub_445770()
{
    int result; // eax

    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[825744]);
    *(_DWORD*)& byte_5D4594[825744] = 0;
    return result;
}

//----- (00445790) --------------------------------------------------------
int sub_445790()
{
    int result; // eax
    wchar_t* v1; // eax

    result = nox_new_window_from_file("QuitMenu.wnd", sub_445840);
    *(_DWORD*)& byte_5D4594[825760] = result;
    if (result)
    {
        nox_window_set_all_funcs((_DWORD*)result, sub_445BB0, sub_445BC0, 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 56) = *(_DWORD*)& byte_5D4594[2650656];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 16) = (nox_win_width
                                                            - *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 8))
                                                           / 2;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 8)
                                                           + *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 16);
        sub_445C40();
        *(_DWORD*)& byte_5D4594[825752] = 0;
        *(_DWORD*)& byte_5D4594[825768] = 0;
        v1 = loadString_sub_40F1D0((char*)& byte_587000[108044], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 309);
        nox_swprintf((wchar_t*)& byte_5D4594[825772], L"%s", v1);
        result = 1;
    }
    return result;
}

//----- (00445840) --------------------------------------------------------
int __cdecl sub_445840(_DWORD* a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int v4; // eax
    int result; // eax
    int v6; // eax
    int v7; // eax
    char* v8; // eax
    int v9; // eax
    int v10; // eax
    int v12; // eax
    wchar_t* v13; // eax
    int v14; // eax
    wchar_t* v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // ecx
    _DWORD* v19; // eax
    int v20; // eax
    int v21; // eax
    wchar_t* v22; // [esp-18h] [ebp-18h]
    wchar_t* v23; // [esp-18h] [ebp-18h]

    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v3)
    {
        case 9001:
            sub_445C40();
            sub_413A00(1);
            if (!sub_40A5C0(2048) || sub_4372B0())
            {
                sub_445B40();
                v17 = a3[9];
                LOBYTE(v17) = v17 & 0xFD;
                a3[9] = v17;
                result = 0;
            }
            else
            {
                v23 = loadString_sub_40F1D0((char*)& byte_587000[108224], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 199);
                v15 = loadString_sub_40F1D0((char*)& byte_587000[108288], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 198);
                sub_449A10(0, (int)v15, (int)v23, 56, (int (*)(void))sub_445B40, sub_445BA0);
                v16 = a3[9];
                LOBYTE(v16) = v16 & 0xFD;
                a3[9] = v16;
                result = 0;
            }
            break;
        case 9002:
            v18 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 120);
            if ((v18 & 0x8000) == 0)
            {
                sub_445C40();
                if (sub_40A5C0(2048))
                {
                    sub_4DB130("AUTOSAVE");
                    sub_4DB170(1, 0, 0);
                }
                goto LABEL_27;
            }
            v19 = sub_46B0C0(a1, v3);
            sub_46ABB0((int)v19, 0);
            v20 = a3[9];
            LOBYTE(v20) = v20 & 0xFD;
            a3[9] = v20;
            result = 0;
            break;
        case 9003:
            sub_445C40();
            if (sub_40A5C0(2048))
                sub_46D580();
            else
                sub_41CE00();
            if (sub_43C6E0())
                goto LABEL_27;
            sub_43CF70();
            v12 = a3[9];
            LOBYTE(v12) = v12 & 0xFD;
            a3[9] = v12;
            result = 0;
            break;
        case 9004:
            sub_46ADE0(*(int*)& byte_5D4594[825760]);
            v22 = loadString_sub_40F1D0((char*)& byte_587000[108096], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 185);
            v13 = loadString_sub_40F1D0((char*)& byte_587000[108160], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 184);
            sub_449A10(*(int*)& byte_5D4594[825760], (int)v13, (int)v22, 56, sub_445B20, sub_445B30);
            v14 = a3[9];
            LOBYTE(v14) = v14 & 0xFD;
            a3[9] = v14;
            result = 0;
            break;
        case 9005:
            sub_445C40();
            sub_4ADA40();
            v4 = a3[9];
            LOBYTE(v4) = v4 & 0xFD;
            a3[9] = v4;
            result = 0;
            break;
        case 9006:
            goto LABEL_11;
        case 9007:
            if (sub_40A5C0(1))
            {
                v8 = sub_417040(*(int*)& byte_5D4594[2616328]);
                sub_443E90((int)v8, 0, 0);
                LABEL_11:
                sub_445C40();
                v9 = a3[9];
                LOBYTE(v9) = v9 & 0xFD;
                a3[9] = v9;
                result = 0;
            }
            else
            {
                sub_440950(0, 0);
                sub_445C40();
                v7 = a3[9];
                LOBYTE(v7) = v7 & 0xFD;
                a3[9] = v7;
                result = 0;
            }
            break;
        case 9008:
            sub_445C40();
            sub_457500();
            v10 = a3[9];
            LOBYTE(v10) = v10 & 0xFD;
            a3[9] = v10;
            result = 0;
            break;
        case 9009:
            sub_445C40();
            if (sub_40A5C0(4096))
                sub_48CB10(4);
            else
                sub_48CB10(0);
            v6 = a3[9];
            LOBYTE(v6) = v6 & 0xFD;
            a3[9] = v6;
            result = 0;
            break;
        default:
        LABEL_27:
            v21 = a3[9];
            LOBYTE(v21) = v21 & 0xFD;
            a3[9] = v21;
            result = 0;
            break;
    }
    return result;
}
// 445B20: using guessed type int sub_445B20();

//----- (00445B20) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
int sub_445B20()
{
    sub_4460C0();
    return sub_445C40();
}
// 445B20: using guessed type int sub_445B20();

//----- (00445B30) --------------------------------------------------------
int sub_445B30()
{
    return sub_46ADC0(*(int*)& byte_5D4594[825760]);
}

//----- (00445B40) --------------------------------------------------------
void* sub_445B40()
{
    void* result; // eax
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]

    sub_413A00(0);
    result = sub_4DB790("AUTOSAVE");
    if (!result)
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[108368], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 88);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[108432], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 87);
        result = sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
    }
    return result;
}

//----- (00445BA0) --------------------------------------------------------
int sub_445BA0()
{
    return sub_413A00(0);
}

//----- (00445BB0) --------------------------------------------------------
int sub_445BB0()
{
    return 1;
}

//----- (00445BC0) --------------------------------------------------------
int __cdecl sub_445BC0(_DWORD* a1)
{
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60(a1, &xLeft, &yTop);
    sub_49CF10(xLeft, yTop, a1[2], a1[3]);
    return 1;
}

//----- (00445C00) --------------------------------------------------------
int sub_445C00()
{
    int result; // eax

    result = sub_46ADA0(*(int*)& byte_5D4594[825760]);
    if (result & 0x10)
        result = sub_445C40();
    return result;
}

//----- (00445C20) --------------------------------------------------------
int sub_445C20()
{
    int result; // eax

    result = sub_46ADA0(*(int*)& byte_5D4594[825760]);
    if (!(result & 0x10))
        result = sub_445C40();
    return result;
}

//----- (00445C40) --------------------------------------------------------
int sub_445C40()
{
    int result; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // esi
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // esi
    _DWORD* v12; // eax
    _DWORD* v13; // esi
    _DWORD* v14; // eax
    _DWORD* v15; // eax
    _DWORD* v16; // eax
    _DWORD* v17; // eax
    _DWORD* v18; // eax
    _DWORD* v19; // eax
    wchar_t* v20; // [esp-4h] [ebp-8h]
    wchar_t* v21; // [esp-4h] [ebp-8h]

    if (sub_46ADA0(*(int*)& byte_5D4594[825760]) & 0x10)
    {
        if (!*(_DWORD*)& byte_5D4594[2614252]
            || !sub_40A5C0(2048)
            || (result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 276), result != 2) && result != 1 && result != 51)
        {
            result = sub_45D9B0();
            if (result != 1)
            {
                result = sub_413A50();
                if (result != 1)
                {
                    sub_452D80(921, 100);
                    sub_46A8C0(*(int*)& byte_5D4594[825760]);
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 4) |= 8u;
                    sub_46ADC0(*(int*)& byte_5D4594[825760]);
                    if (sub_40A5C0(2048))
                    {
                        v20 = loadString_sub_40F1D0((char*)& byte_587000[108496], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 396);
                        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                        sub_46AEE0((int)v1, (int)v20);
                        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9001);
                        nox_window_set_hidden((int)v2, 0);
                        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9002);
                        nox_window_set_hidden((int)v3, 0);
                        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                        nox_window_set_hidden((int)v4, 1);
                        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9008);
                        nox_window_set_hidden((int)v5, 1);
                        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9009);
                        nox_window_set_hidden((int)v6, 1);
                        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9004);
                        sub_46A9B0(v7, v6[4], v6[5]);
                        sub_413A00(1);
                        result = sub_46AB20(*(_DWORD * *)& byte_5D4594[825760], 220, 285);
                    }
                    else
                    {
                        v21 = loadString_sub_40F1D0((char*)& byte_587000[108548], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 427);
                        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                        sub_46AEE0((int)v8, (int)v21);
                        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9001);
                        nox_window_set_hidden((int)v9, 1);
                        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9002);
                        nox_window_set_hidden((int)v10, 1);
                        v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                        nox_window_set_hidden((int)v11, 0);
                        sub_46ABB0((int)v11, 1);
                        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9008);
                        nox_window_set_hidden((int)v12, 0);
                        v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9009);
                        nox_window_set_hidden((int)v13, 0);
                        sub_46AEE0((int)v13, (int)& byte_5D4594[825772]);
                        if (sub_40A5C0(49152) || !sub_417DD0())
                            sub_46ABB0((int)v13, 0);
                        else
                            sub_46ABB0((int)v13, 1);
                        v14 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9004);
                        sub_46A9B0(v14, v13[4], v13[5] + 45);
                        sub_46AB20(*(_DWORD * *)& byte_5D4594[825760], 220, 330);
                        result = sub_40A5C0(4096);
                        if (result)
                        {
                            v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                            sub_46ABB0((int)v15, 0);
                            v16 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                            result = sub_46ABB0((int)v16, 0);
                        }
                        if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                        {
                            v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                            sub_46ABB0((int)v17, 0);
                            v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9005);
                            sub_46ABB0((int)v18, 0);
                            v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                            result = sub_46ABB0((int)v19, 0);
                        }
                    }
                }
            }
        }
    }
    else
    {
        sub_46B500(0);
        sub_46ADE0(*(int*)& byte_5D4594[825760]);
        nox_window_set_hidden(*(int*)& byte_5D4594[825760], 1);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 4) &= 0xFFFFFFF7;
        result = sub_413A00(0);
    }
    return result;
}

//----- (00445FF0) --------------------------------------------------------
_DWORD* sub_445FF0()
{
    int i; // esi
    _DWORD* result; // eax

    if (*(_DWORD*)& byte_5D4594[825760])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 56) = *(_DWORD*)& byte_5D4594[2650656];
    for (i = 9001; i <= 9006; ++i)
    {
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], i);
        if (result)
            result[26] = *(_DWORD*)& byte_5D4594[2614256];
    }
    return result;
}

//----- (00446030) --------------------------------------------------------
BOOL sub_446030()
{
    return *(_DWORD*)& byte_5D4594[825768] != 0;
}

//----- (00446050) --------------------------------------------------------
int sub_446050()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)& byte_5D4594[825768] = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (00446060) --------------------------------------------------------
void sub_446060()
{
    *(_DWORD*)& byte_5D4594[825768] = 0;
}

//----- (00446070) --------------------------------------------------------
void sub_446070()
{
    if (!-- * (_DWORD*)& byte_5D4594[825752])
        sub_446380();
}

//----- (00446090) --------------------------------------------------------
BOOL sub_446090()
{
    return *(_DWORD*)& byte_5D4594[825752] == 0;
}

//----- (004460A0) --------------------------------------------------------
int __cdecl sub_4460A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[825756] = a1;
    return result;
}

//----- (004460B0) --------------------------------------------------------
int sub_4460B0()
{
    return *(_DWORD*)& byte_5D4594[825756];
}

//----- (004460C0) --------------------------------------------------------
int sub_4460C0()
{
    int result; // eax

    if (sub_40A5C0(4096))
    {
        if (sub_40A5C0(1))
        {
            result = sub_4DCD40();
        }
        else if (sub_4460B0())
        {
            sub_4460A0(0);
            result = sub_446140();
        }
        else
        {
            sub_41CE00();
            result = sub_4460A0(1);
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[825764] = 1;
        result = sub_40A5C0(4096);
        if (result)
        {
            result = sub_40A5C0(1);
            if (result)
                result = sub_4D6B10(0);
        }
    }
    return result;
}

//----- (00446140) --------------------------------------------------------
int sub_446140()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[825764] = 1;
    result = sub_40A5C0(4096);
    if (result)
    {
        result = sub_40A5C0(1);
        if (result)
            result = sub_4D6B10(0);
    }
    return result;
}

//----- (00446180) --------------------------------------------------------
int sub_446180()
{
    return *(_DWORD*)& byte_5D4594[825764];
}

//----- (00446190) --------------------------------------------------------
void sub_446190()
{
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // [esp-12h] [ebp-14h]
    char v4; // [esp+1h] [ebp-1h]

    *(_DWORD*)& byte_5D4594[825764] = 0;
    if (sub_40A5C0(1))
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[108608], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 667);
        sub_413D30((char*)& byte_587000[108632], v1);
    }
    if (sub_40A5C0(0x2000000))
    {
        sub_43C260();
        sub_41E300(9);
        sub_44B000();
    }
    else if (sub_4D6F50())
    {
        if (sub_4D6F30())
            sub_43C2F0();
        sub_4D70B0();
        sub_4D6F40(0);
        sub_4D6F90(0);
    }
    if (!*(_DWORD*)& byte_5D4594[825768])
    {
        *(_DWORD*)& byte_5D4594[825752] = 0;
        *(_DWORD*)& byte_5D4594[825768] = *(_DWORD*)& byte_5D4594[2598000];
        if (sub_40A5C0(1))
        {
            if (sub_43AF70() == 1 && sub_40A5C0(49152))
                sub_416150(15, 0);
            sub_509CB0();
        }
        if (sub_40A5C0(1))
        {
            *(_DWORD*)& byte_5D4594[825752] = sub_416F40() - 1;
            sub_467440(0);
            if (*(_DWORD*)& byte_5D4594[825752] > 0)
            {
                v4 = -57;
                sub_4E5420(159, &v4, 1, 0, 1);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[108672], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 737);
                v2 = loadString_sub_40F1D0((char*)& byte_587000[108724], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 736);
                sub_449A10(0, (int)v2, (int)v3, 0, 0, 0);
                sub_44A360(1);
                goto LABEL_20;
            }
        }
        else if (!sub_40A5C0(0x2000))
        {
            goto LABEL_20;
        }
        sub_446380();
    }
    LABEL_20:
    if (*(_DWORD*)& byte_5D4594[2650652])
    {
        if (sub_41E2F0() == 9)
        {
            sub_41F4B0();
            sub_41EC30();
            sub_446490(0);
            sub_44B000();
        }
    }
}

//----- (00446360) --------------------------------------------------------
unsigned int sub_446360()
{
    unsigned int result; // eax

    if (*(_DWORD*)& byte_5D4594[825760])
        result = ((unsigned int)~sub_46ADA0(*(int*)& byte_5D4594[825760]) >> 4) & 1;
    else
        result = 0;
    return result;
}

//----- (00446380) --------------------------------------------------------
void sub_446380()
{
    sub_44A400();
    if (sub_40A5C0(0x2000) && !sub_40A5C0(4096) && !sub_4D6F30())
        sub_41CEE0((int)& byte_5D4594[2660684], 1);
    sub_4597E0(1);
    sub_43DDD0(0);
    sub_43DE60();
    sub_446060();
}

//----- (004463E0) --------------------------------------------------------
int __cdecl sub_4463E0(int a1)
{
    FILE* result; // eax
    FILE* v2; // edi
    char* v3; // eax
    int result2 = 0;

    *(_DWORD*)& byte_5D4594[826036] = 0;
    *(_DWORD*)& byte_5D4594[4 * a1 + 826040] = 0;
    result = fopen("motd.txt", "rb");
    v2 = result;
    if (result)
    {
        fseek(result, 0, 2);
        *(_DWORD*)& byte_5D4594[4 * a1 + 826040] = ftell(v2);
        fseek(v2, 0, 0);
        v3 = (char*)nox_calloc(*(_DWORD*)& byte_5D4594[4 * a1 + 826040] + 1, 1u);
        *(_DWORD*)& byte_5D4594[826036] = v3;
        if (v3)
        {
            sub_40ADD0_fread(v3, *(_DWORD*)& byte_5D4594[4 * a1 + 826040], 1u, v2);
            v3 = *(char**)& byte_5D4594[826036];
        }
        v3[(*(_DWORD*)& byte_5D4594[4 * a1 + 826040])++] = 0;
        result2 = fclose(v2);
    }
    return result2;
}

//----- (00446490) --------------------------------------------------------
LPVOID __cdecl sub_446490(void* a1)
{
    LPVOID result; // eax

    result = *(LPVOID*)& byte_5D4594[826036];
    if (*(_DWORD*)& byte_5D4594[826036])
    {
        free(*(LPVOID*)& byte_5D4594[826036]);
        result = a1;
    }
    *(_DWORD*)& byte_5D4594[826036] = 0;
    *(_DWORD*)& byte_5D4594[4 * (_DWORD)a1 + 826040] = 0;
    return result;
}

//----- (004464D0) --------------------------------------------------------
LPVOID __cdecl sub_4464D0(int a1, _DWORD* a2)
{
    *a2 = *(_DWORD*)& byte_5D4594[4 * a1 + 826040];
    return *(LPVOID*)& byte_5D4594[826036];
}

//----- (004464F0) --------------------------------------------------------
int __cdecl sub_4464F0(int a1, _DWORD* a2)
{
    if (!*(_DWORD*)& byte_5D4594[4 * a1 + 826056])
        return 0;
    *a2 = *(_DWORD*)& byte_5D4594[4 * a1 + 826048];
    return *(_DWORD*)& byte_5D4594[4 * a1 + 826056];
}

//----- (00446520) --------------------------------------------------------
void __cdecl sub_446520(int a1, const void* a2, int a3)
{
    void* v3; // edi

    if (a2)
    {
        if (a3 > 0)
        {
            v3 = nox_calloc(a3, 1u);
            *(_DWORD*)& byte_5D4594[4 * a1 + 826056] = v3;
            qmemcpy(v3, a2, a3);
            *(_DWORD*)& byte_5D4594[4 * a1 + 826048] = a3;
            *(_DWORD*)& byte_5D4594[4 * a1 + 826064] = 1;
        }
    }
}

//----- (00446580) --------------------------------------------------------
int __cdecl sub_446580(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[4 * a1 + 826056];
    if (result)
    {
        free(*(LPVOID*)& byte_5D4594[4 * a1 + 826056]);
        *(_DWORD*)& byte_5D4594[4 * a1 + 826056] = 0;
        *(_DWORD*)& byte_5D4594[4 * a1 + 826048] = 0;
        *(_DWORD*)& byte_5D4594[4 * a1 + 826064] = 0;
    }
    return result;
}

//----- (004465C0) --------------------------------------------------------
int sub_4465C0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // edi
    char* v3; // ebx
    _DWORD* v4; // esi
    _DWORD* v5; // ebp
    char* v7; // [esp+10h] [ebp-8h]
    _DWORD* v8; // [esp+14h] [ebp-4h]

    v0 = nox_new_window_from_file("motd.wnd", sub_4466C0);
    *(_DWORD*)& byte_5D4594[826028] = v0;
    v1 = sub_46B0C0(v0, 4203);
    *(_DWORD*)& byte_5D4594[826032] = v1;
    v2 = (_DWORD*)v1[8];
    v7 = sub_42F970("UISlider");
    v3 = sub_42F970("UISliderLit");
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4204);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4205);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4206);
    *(_DWORD*)(v4[100] + 8) = 16;
    *(_DWORD*)(v4[100] + 12) = 10;
    sub_4B5700((int)v4, 0, 0, (int)v7, (int)v3, (int)v3);
    sub_46B280((int)v4, *(int*)& byte_5D4594[826032]);
    sub_46B280((int)v5, *(int*)& byte_5D4594[826032]);
    sub_46B280((int)v8, *(int*)& byte_5D4594[826032]);
    v2[9] = v4;
    v2[7] = v5;
    v2[8] = v8;
    return *(_DWORD*)& byte_5D4594[826028];
}

//----- (004466C0) --------------------------------------------------------
int __cdecl sub_4466C0(int a1, int a2, int a3, int a4)
{
    if (a2 == 16391)
    {
        sub_452D80(766, 100);
        sub_446780();
    }
    return 0;
}

//----- (004466F0) --------------------------------------------------------
char* __cdecl sub_4466F0(char* a1, _BYTE* a2)
{
    char* v2; // edx
    char* v3; // eax
    char v4; // cl
    char* result; // eax

    v2 = a2;
    v3 = a1;
    *a2 = 0;
    if (!*a1)
        return 0;
    while (1)
    {
        v4 = *v3;
        if (!*v3)
        {
            *v2 = 0;
            return 0;
        }
        if (v4 == 10)
        {
            *v2 = 0;
            return v3 + 1;
        }
        if (v4 == 13)
            break;
        *v2++ = v4;
        ++v3;
    }
    result = v3 + 1;
    *v2 = 0;
    if (*result == 10)
        ++result;
    return result;
}

//----- (00446730) --------------------------------------------------------
_BYTE* __cdecl sub_446730(_BYTE* a1)
{
    _BYTE* result; // eax
    wchar_t v2[256]; // [esp+0h] [ebp-200h]

    result = a1;
    if (*a1)
    {
        nox_swprintf(v2, L"%S", a1);
        result = (_BYTE*)nox_window_call_field_94(*(int*)& byte_5D4594[826032], 16397, (int)v2, -1);
    }
    return result;
}

//----- (00446780) --------------------------------------------------------
int sub_446780()
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[826028]))
        return 0;
    sub_46B500(0);
    nox_window_set_hidden(*(int*)& byte_5D4594[826028], 1);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[826028] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[826032] + 4) &= 0xFFFFFFF7;
    nox_window_call_field_94(*(int*)& byte_5D4594[826032], 16399, 0, 0);
    return 1;
}

//----- (004467F0) --------------------------------------------------------
void sub_4467F0()
{
    unsigned int result; // eax
    _DWORD* v1; // eax
    char* v2; // esi
    _DWORD* v3; // eax
    char v4[256]; // [esp+0h] [ebp-100h]

    result = sub_446360();
    if (!result)
    {
        result = sub_4D6F50();
        if (!result || (result = sub_40A5C0(128)) == 0)
        {
            if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
            {
                result = sub_46ADA0(*(int*)& byte_5D4594[826028]);
                if (result & 0x10)
                {
                    result = sub_44A4A0();
                    if (!result)
                    {
                        result = sub_49C810();
                        if (!result)
                        {
                            result = sub_49CB40();
                            if (!result)
                            {
                                sub_46A8C0(*(int*)& byte_5D4594[826028]);
                                v1 = sub_46B0C0(0, 4100);
                                if (v1)
                                    sub_46A8C0((int)v1);
                                *(_DWORD*)(*(_DWORD*)& byte_5D4594[826028] + 4) |= 8u;
                                *(_DWORD*)(*(_DWORD*)& byte_5D4594[826032] + 4) |= 8u;
                                v2 = *(char**)& byte_5D4594[826060];
                                if (*(_DWORD*)& byte_5D4594[826060])
                                {
                                    while (1)
                                    {
                                        v2 = sub_4466F0(v2, v4);
                                        if (!v2)
                                            break;
                                        if (!v4[0])
                                            strcpy(v4, " ");
                                        sub_446730(v4);
                                    }
                                    if (v4[0])
                                        sub_446730(v4);
                                }
                                v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4202);
                                sub_46B500((int)v3);
                            }
                        }
                    }
                }
            }
            *(_DWORD*)& byte_5D4594[826068] = 0;
        }
    }
}

//----- (00446940) --------------------------------------------------------
int __cdecl sub_446940(int a1)
{
    return *(_DWORD*)& byte_5D4594[4 * a1 + 826064];
}

//----- (00446950) --------------------------------------------------------
BOOL sub_446950()
{
    return *(_DWORD*)& byte_5D4594[826028] && !(sub_46ADA0(*(int*)& byte_5D4594[826028]) & 0x10);
}

//----- (004469D0) --------------------------------------------------------
wchar_t* __cdecl sub_4469D0(int a1)
{
    if (a1 / *(_DWORD*)& byte_5D4594[826092] + 1 <= 1)
        return *(wchar_t**)& byte_587000[8 * a1 + 108848];
    nox_swprintf(
            (wchar_t*)& byte_5D4594[827140],
            L"%s %d",
            *(_DWORD*)& byte_587000[8 * (a1 % *(_DWORD*)& byte_5D4594[826092]) + 108848],
            a1 / *(_DWORD*)& byte_5D4594[826092] + 1);
    return (wchar_t*)& byte_5D4594[827140];
}

//----- (00446A90) --------------------------------------------------------
int sub_446A90()
{
    int result; // eax

    *(_BYTE*)(*(_DWORD*)& byte_5D4594[829520] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    result = 1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[829520] + 52) = sub_4379F0;
    return result;
}

//----- (00446AD0) --------------------------------------------------------
int __cdecl sub_446AD0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[829520] + 52) = a1;
    return result;
}

//----- (00446BC0) --------------------------------------------------------
char* __cdecl sub_446BC0(int a1)
{
    int v1; // eax
    char* result; // eax

    v1 = nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16406, a1, 0);
    nox_sprintf((char*)& byte_5D4594[826072], "%S", v1);
    result = (char*)& byte_5D4594[826072];
    if (byte_5D4594[826072] == 64 || byte_5D4594[826072] == 32) // TODO: byte_5D4594 != (unsigned __int8*)-826072 && ...
        result = (char*)& byte_5D4594[826073];
    return result;
}

//----- (00446C10) --------------------------------------------------------
int __cdecl sub_446C10(int a1, int a2)
{
    int v2; // ecx
    int result; // eax

    v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[829488] + 32);
    result = a1;
    if (a1 < *(__int16*)(v2 + 44))
    {
        result = 131 * a1;
        if (a2)
            * (_DWORD*)(*(_DWORD*)(v2 + 24) + 524 * a1 + 516) = **(_DWORD * *)& byte_5D4594[2649844];
        else
            *(_DWORD*)(*(_DWORD*)(v2 + 24) + 524 * a1 + 516) = **(_DWORD * *)& byte_5D4594[2649892];
    }
    return result;
}

//----- (00446C70) --------------------------------------------------------
int sub_446C70()
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16404, 0, 0);
}

//----- (00446C90) --------------------------------------------------------
BOOL sub_446C90()
{
    return *(int*)nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16404, 0, 0) != -1;
}

//----- (00446CC0) --------------------------------------------------------
wchar_t* __cdecl sub_446CC0(int a1)
{
    wchar_t* result; // eax
    char* v2; // eax
    char* v3; // eax

    result = (wchar_t*)sub_41E2F0();
    if (result == (wchar_t*)7)
    {
        if (a1)
        {
            v2 = sub_41FA40();
            nox_swprintf((wchar_t*)& byte_5D4594[829224], *(const wchar_t**)& byte_5D4594[829528], v2, a1);
        }
        else
        {
            result = *(wchar_t**)& byte_5D4594[829532];
            if (!*(_DWORD*)& byte_5D4594[829532])
                return result;
            v3 = sub_41FA40();
            nox_swprintf((wchar_t*)& byte_5D4594[829224], *(const wchar_t**)& byte_5D4594[829532], v3);
            nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16403, -1, 0);
        }
        result = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829496], 16385, (int)& byte_5D4594[829224], 0);
    }
    return result;
}

//----- (00446D50) --------------------------------------------------------
void sub_446D50()
{
    char* v0; // eax
    int v1; // [esp+0h] [ebp-4h]

    v1 = 0;
    v0 = (char*)sub_4464F0(0, &v1);
    sub_446D80(v0);
}

//----- (00446D80) --------------------------------------------------------
void __cdecl sub_446D80(char* a1)
{
    char* v1; // esi
    char v2[256]; // [esp+4h] [ebp-300h]
    wchar_t v3[256]; // [esp+104h] [ebp-200h]

    v1 = a1;
    if (a1)
    {
        while (1)
        {
            v1 = sub_446E20(v1, v2);
            if (!v1)
                break;
            if (!v2[0])
                strcpy(v2, " ");
            nox_swprintf(v3, L"%S", v2);
            sub_447310(0, (int)v3);
        }
        if (v2[0])
        {
            nox_swprintf(v3, L"%S", v2);
            sub_447310(0, (int)v3);
        }
    }
}

//----- (00446E20) --------------------------------------------------------
char* __cdecl sub_446E20(char* a1, _BYTE* a2)
{
    char* v2; // edx
    char* v3; // eax
    char v4; // cl
    char* result; // eax

    v2 = a2;
    v3 = a1;
    *a2 = 0;
    if (!*a1)
        return 0;
    while (1)
    {
        v4 = *v3;
        if (!*v3)
        {
            *v2 = 0;
            return 0;
        }
        if (v4 == 10)
        {
            *v2 = 0;
            return v3 + 1;
        }
        if (v4 == 13)
            break;
        *v2++ = v4;
        ++v3;
    }
    result = v3 + 1;
    *v2 = 0;
    if (*result == 10)
        ++result;
    return result;
}

//----- (00446E60) --------------------------------------------------------
wchar_t* sub_446E60()
{
    wchar_t* result; // eax

    nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16399, 0, 0);
    for (result = sub_41F0A0(); result; result = sub_41F070())
        nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16397, (int)result, 14);
    return result;
}

//----- (00446EB0) --------------------------------------------------------
char* sub_446EB0()
{
    char* result; // eax
    const char* i; // esi
    wchar_t v2[256]; // [esp+4h] [ebp-200h]

    nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16399, 0, 0);
    result = sub_41F780();
    for (i = result; result; i = result)
    {
        nox_swprintf(v2, L"%S", i);
        if (sub_427880(i))
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v2, 2);
        else
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v2, 14);
        result = sub_41F710();
    }
    return result;
}

//----- (00446F40) --------------------------------------------------------
char* __cdecl sub_446F40(int a1)
{
    int v1; // eax

    if (a1 == -1)
        return 0;
    v1 = nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16406, a1, 0);
    nox_sprintf((char*)& byte_5D4594[827120], "%S", v1);
    return (char*)& byte_5D4594[827120];
}

//----- (004471A0) --------------------------------------------------------
const wchar_t* __cdecl sub_4471A0(const char* a1, int a2, int a3, int a4)
{
    const wchar_t* result; // eax

    result = (const wchar_t*)sub_427880(a1);
    if (!result)
    {
        result = *(const wchar_t**)& byte_5D4594[829492];
        if (*(_DWORD*)& byte_5D4594[829492])
        {
            result = *(const wchar_t**)& byte_5D4594[829544];
            if (*(_DWORD*)& byte_5D4594[829544])
            {
                if (a2)
                {
                    if (a3)
                    {
                        if (a4 == 1)
                        {
                            nox_swprintf((wchar_t*)& byte_5D4594[827176], *(const wchar_t**)& byte_5D4594[829552], a1, a2);
                            return (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 7);
                        }
                        result = *(const wchar_t**)& byte_5D4594[829548];
                    }
                    nox_swprintf((wchar_t*)& byte_5D4594[827176], result, a1, a2);
                    result = (const wchar_t*)nox_window_call_field_94(
                            *(int*)& byte_5D4594[829492],
                            16397,
                            (int)& byte_5D4594[827176],
                            (a3 != 0) + 6);
                }
            }
        }
    }
    return result;
}

//----- (00447250) --------------------------------------------------------
const wchar_t* __cdecl sub_447250(const char* a1, int a2, int a3, int a4)
{
    const wchar_t* result; // eax
    const wchar_t* v5; // esi
    char* v6; // eax

    result = (const wchar_t*)sub_427880(a1);
    if (!result)
    {
        result = *(const wchar_t**)& byte_5D4594[829492];
        if (*(_DWORD*)& byte_5D4594[829492])
        {
            if (*(_DWORD*)& byte_5D4594[829556])
            {
                result = *(const wchar_t**)& byte_5D4594[829560];
                if (*(_DWORD*)& byte_5D4594[829560])
                {
                    if (a2)
                    {
                        if (a3)
                        {
                            if (a4 == 1)
                            {
                                v5 = *(const wchar_t**)& byte_5D4594[829564];
                                v6 = sub_41FA40();
                                nox_swprintf((wchar_t*)& byte_5D4594[827176], v5, a1, v6, a2);
                                return (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 13);
                            }
                        }
                        else
                        {
                            result = *(const wchar_t**)& byte_5D4594[829556];
                        }
                        nox_swprintf((wchar_t*)& byte_5D4594[827176], result, a1, a2);
                        result = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 13);
                    }
                }
            }
        }
    }
    return result;
}

//----- (00447310) --------------------------------------------------------
int __cdecl sub_447310(int a1, int a2)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[829492];
    if (*(_DWORD*)& byte_5D4594[829492])
    {
        if (*(_DWORD*)& byte_5D4594[829536])
        {
            result = a2;
            if (a2)
            {
                if (a1)
                    nox_swprintf((wchar_t*)& byte_5D4594[827176], *(const wchar_t**)& byte_5D4594[829536], a1, a2);
                else
                    nox_swprintf((wchar_t*)& byte_5D4594[827176], L"%s", a2);
                result = nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 9);
            }
        }
    }
    return result;
}

//----- (00447380) --------------------------------------------------------
wchar_t* __cdecl sub_447380(const char* a1, char* a2)
{
    wchar_t* result; // eax
    const wchar_t* v3; // edi

    result = (wchar_t*)sub_427880(a1);
    if (!result)
    {
        result = *(wchar_t**)& byte_5D4594[829492];
        if (*(_DWORD*)& byte_5D4594[829492])
        {
            result = *(wchar_t**)& byte_5D4594[829544];
            if (*(_DWORD*)& byte_5D4594[829544])
            {
                if (a2)
                {
                    v3 = *(const wchar_t**)& byte_5D4594[829540];
                    sub_447410(a2);
                    if (a1)
                        nox_swprintf((wchar_t*)& byte_5D4594[827176], v3, a1, a2);
                    else
                        nox_swprintf((wchar_t*)& byte_5D4594[827176], L"%S", a2);
                    nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 4);
                    result = (wchar_t*)sub_452D80(226, 100);
                }
            }
        }
    }
    return result;
}

//----- (00447410) --------------------------------------------------------
unsigned int __cdecl sub_447410(char* a1)
{
    int v1; // edx
    char* v2; // ecx
    char v3; // al
    unsigned int result; // eax

    v1 = 0;
    v2 = a1;
    if (*a1)
    {
        do
        {
            if ((unsigned __int8)* v2 < 0x80u)
                byte_5D4594[v1++ + 826096] = *v2;
            v3 = *++v2;
        } while (v3);
    }
    byte_5D4594[v1 + 826096] = 0;
    result = strlen((const char*)& byte_5D4594[826096]) + 1;
    qmemcpy(a1, &byte_5D4594[826096], result);
    return result;
}

//----- (004475E0) --------------------------------------------------------
int sub_4475E0()
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16399, 0, 0);
}

//----- (00447600) --------------------------------------------------------
void sub_447600()
{
    if (!sub_44A4A0())
        sub_46B500(*(int*)& byte_5D4594[829500]);
}

//----- (00447BD0) --------------------------------------------------------
int sub_447BD0()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[829520] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[829520]);
    sub_448490();
    v0();
    return 1;
}

//----- (00447BF0) --------------------------------------------------------
int __cdecl sub_447BF0(_DWORD* a1, int a2, unsigned int a3, int a4)
{
    int result; // eax

    if (a2 == 19)
    {
        nox_window_call_field_94((int)a1, 16391, *(_DWORD*)(a1[8] + 28), 0);
        result = 0;
    }
    else if (a2 == 20)
    {
        nox_window_call_field_94((int)a1, 16391, *(_DWORD*)(a1[8] + 32), 0);
        result = 0;
    }
    else if (*(_DWORD*)(a1[8] + 16))
    {
        result = sub_4A2DE0((int)a1, a2, a3, a4);
    }
    else
    {
        result = sub_4A28E0(a1, a2, a3, a4);
    }
    return result;
}

//----- (00447C70) --------------------------------------------------------
int __cdecl sub_447C70(int a1, int a2, int a3, int a4)
{
    int v5; // eax

    if (a2 != 21)
        return 0;
    if (a3 != 1)
        return 0;
    if (a4 == 2 && sub_41E2F0() == 7)
    {
        sub_41E300(9);
        v5 = sub_41E2F0();
        sub_41DA70(v5, 8);
        sub_44A400();
        sub_43C260();
    }
    return 1;
}

//----- (00447CC0) --------------------------------------------------------
int __cdecl sub_447CC0(int a1, unsigned int a2, int* a3, int a4)
{
    int result; // eax
    const wchar_t* v5; // edi
    const wchar_t* v6; // eax
    wchar_t* v7; // esi
    int2* v8; // eax
    int v9; // ebx
    int v10; // esi
    int v11; // edi
    _DWORD* v12; // esi
    int* v13; // esi
    wchar_t* v14; // eax
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // eax
    int v19; // eax
    wchar_t* v20; // eax
    int* v21; // [esp+8h] [ebp-104h]
    CHAR File[256]; // [esp+Ch] [ebp-100h]

    if (a2 > 0x4006)
    {
        switch (a2)
        {
            case 0x4007u:
                switch (sub_46B0A0(a3))
                {
                    case 1902:
                        sub_448730_wol_dialogs();
                        break;
                    case 1903:
                        v16 = sub_41E2F0();
                        sub_41DA70(v16, 12);
                        v17 = sub_41E2F0();
                        sub_41DA70(v17, 13);
                        break;
                    case 1904:
                        sub_449280();
                        break;
                    case 1905:
                        sub_40D380();
                        sub_41E300(8);
                        sub_4207F0(5);
                        break;
                    case 1906:
                        sub_41E300(9);
                        v15 = sub_41E2F0();
                        sub_41DA70(v15, 8);
                        sub_43C260();
                        break;
                    case 1913:
                        v20 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829500], 16413, 0, 0);
                        sub_447090_wol_chat(v20);
                        nox_window_call_field_94(*(int*)& byte_5D4594[829500], 16414, (int)& byte_5D4594[829580], 0);
                        break;
                    case 1914:
                        sub_449530();
                        break;
                    case 1926:
                        v18 = sub_4200F0();
                        nox_sprintf(File, "http://battleclans.westwood.com/nox/index_%d.html", v18);
                        ShellExecuteA(0, 0, File, 0, (LPCSTR)& byte_587000[111564], 3);
                        break;
                    case 1927:
                        v19 = sub_4200F0();
                        nox_sprintf(File, "http://www.westwood.com/westwoodonline/tournaments/nox/rankindex_%d.html", v19);
                        ShellExecuteA(0, 0, File, 0, (LPCSTR)& byte_587000[111644], 3);
                        break;
                    default:
                        break;
                }
                sub_452D80(921, 100);
                return 1;
            case 0x4010u:
                if (sub_46B0A0(a3) != 1908)
                    return 0;
                if (!*(_WORD*)nox_window_call_field_94((int)a3, 16406, a4, 0))
                    goto LABEL_23;
                v5 = (const wchar_t*)sub_41EC00();
                v6 = (const wchar_t*)sub_41F1E0(a4);
                v7 = (wchar_t*)v6;
                if (!v6)
                    goto LABEL_23;
                if (v5)
                {
                    if (nox_wcscmp(v6, v5))
                    {
                        sub_40D380();
                        sub_446A20_wol_chat(v7);
                    }
                    LABEL_23:
                    sub_447600();
                    result = 0;
                }
                else
                {
                    sub_446A20_wol_chat(0);
                    sub_447600();
                    result = 0;
                }
                break;
            case 0x4011u:
                if (sub_46B0A0(a3) != 1909)
                    return 0;
                if (a4 == -1 || *(_DWORD*)& byte_5D4594[829504])
                {
                    *(_DWORD*)& byte_587000[109280] = -1;
                    result = 0;
                }
                else
                {
                    v8 = sub_4309F0();
                    *(_DWORD*)& byte_587000[109280] = a4;
                    v9 = v8->field_0;
                    v10 = v8->field_4;
                    v11 = sub_43F320(0);
                    *(_DWORD*)& byte_5D4594[829504] = nox_window_new(0, 40, v9 - 40, v10 - (v11 + 4) / 2, 80, v11 + 4, 0);
                    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[829504], 0, sub_448140, 0);
                    sub_46A8C0(*(int*)& byte_5D4594[829504]);
                    v12 = nox_window_new(*(int*)& byte_5D4594[829504], 8, 0, v11 / 2, 80, v11 + 2, 0);
                    nox_window_set_all_funcs(v12, sub_448340, sub_448240, 0);
                    v12[8] = 0;
                    result = 0;
                }
                return result;
            case 0x401Fu:
                v13 = a3;
                sub_46B0A0(a3);
                goto LABEL_31;
            default:
                return 0;
        }
        return result;
    }
    if (a2 == 16390)
    {
        if (*(_DWORD*)& byte_5D4594[830112])
            return 0;
        sub_41E2F0();
        return 0;
    }
    if (a2 > 0x4003)
    {
        if (a2 != 16389)
            return 0;
        sub_452D80(920, 100);
        return 1;
    }
    if (a2 == 16387)
    {
        if (!sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], a4))
            return 0;
        return 0;
    }
    if (a2 == 23)
        return 1;
    if (a2 != 1910)
        return 0;
    v13 = v21;
    LABEL_31:
    v14 = (wchar_t*)nox_window_call_field_94((int)v13, 16413, 0, 0);
    sub_446F80_wol_chat(v14);
    nox_window_call_field_94((int)v13, 16414, (int)& byte_5D4594[829576], 0);
    return 0;
}
// 447F24: variable 'v21' is possibly undefined

//----- (00448140) --------------------------------------------------------
int __cdecl sub_448140(int yTop)
{
    int v1; // esi
    int xLeft; // [esp+4h] [ebp-Ch]
    int v4; // [esp+8h] [ebp-8h]
    int v5; // [esp+Ch] [ebp-4h]

    v1 = yTop;
    sub_46AA60((_DWORD*)yTop, &xLeft, &yTop);
    nox_window_get_size(v1, &v4, &v5);
    sub_49CF10(xLeft, yTop, v4, v5);
    sub_434460(*(int*)& byte_5D4594[2523948]);
    sub_49F500(xLeft + 1, yTop);
    sub_49F570(v4 - 2, 0);
    sub_49E4B0();
    sub_49F500(xLeft + 1, yTop + v5);
    sub_49F570(v4 - 2, 0);
    sub_49E4B0();
    sub_49F500(xLeft, yTop + 1);
    sub_49F570(0, v5 - 2);
    sub_49E4B0();
    sub_49F500(xLeft + v4, yTop + 1);
    sub_49F570(0, v5 - 2);
    sub_49E4B0();
    return 1;
}

//----- (00448240) --------------------------------------------------------
int __cdecl sub_448240(_DWORD* a1, _BYTE* a2)
{
    unsigned __int16* v2; // esi
    int v3; // ecx
    int v5; // [esp+4h] [ebp-8h]
    int v6; // [esp+8h] [ebp-4h]

    v2 = *(unsigned __int16**)& byte_587000[12 * a1[8] + 108824];
    sub_46AA60(a1, &v6, &a1);
    sub_43F840(0, v2, &v5, 0, 0);
    v3 = *(_DWORD*)& byte_5D4594[2589772];
    if (!(*a2 & 2))
        v3 = *(_DWORD*)& byte_5D4594[2523948];
    sub_4482D0((80 - v5) / 2 + v6 + 1, (int)a1, v3, *(int*)& byte_5D4594[2650656], v2);
    return 1;
}

//----- (004482D0) --------------------------------------------------------
int __cdecl sub_4482D0(int a1, int a2, int a3, int a4, _WORD* a5)
{
    unsigned __int8* v5; // esi

    sub_434390(a4);
    v5 = &byte_587000[109288];
    do
    {
        sub_43FAF0(0, a5, a1 + *(_DWORD*)v5, a2 + *((_DWORD*)v5 + 1), 320, 0);
        v5 += 8;
    } while ((int)v5 < (int)& byte_587000[109320]);
    sub_434390(a3);
    return sub_43FAF0(0, a5, a1, a2, 320, 0);
}

//----- (00448340) --------------------------------------------------------
int __cdecl sub_448340(int a1, unsigned int a2)
{
    if (a2 == 5)
        return 1;
    if (a2 > 5 && a2 <= 7)
    {
        sub_448380();
        (*(void(__cdecl * *)(int)) & byte_587000[12 * *(_DWORD*)(a1 + 32) + 108832])(*(int*)& byte_587000[109280]);
        return 1;
    }
    return 0;
}

//----- (00448380) --------------------------------------------------------
void sub_448380()
{
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[829504]);
    *(_DWORD*)& byte_5D4594[829504] = 0;
    sub_447600();
}

//----- (004483A0) --------------------------------------------------------
int __cdecl sub_4483A0(int a1, int a2)
{
    int2* v2; // eax
    int result; // eax
    int xLeft; // [esp+0h] [ebp-8h]
    int yTop; // [esp+4h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[829504])
    {
        v2 = sub_4309F0();
        if (!sub_46AAB0(*(_DWORD * *)& byte_5D4594[829504], v2->field_0, v2->field_4))
            sub_448380();
    }
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        result = 1;
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
        result = 1;
    }
    return result;
}

//----- (00448450) --------------------------------------------------------
int sub_448450()
{
    int result; // eax
    _DWORD* v1; // eax

    result = sub_40A5C0(0x2000000);
    if (result)
    {
        sub_446970_wol_chat();
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1905);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[829480], 16391, (int)v1, 0);
    }
    return result;
}

//----- (00448490) --------------------------------------------------------
int sub_448490()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[829480];
    if (*(_DWORD*)& byte_5D4594[829480])
    {
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[829480]);
        *(_DWORD*)& byte_5D4594[829480] = 0;
        *(_DWORD*)& byte_5D4594[829484] = 0;
        *(_DWORD*)& byte_5D4594[829488] = 0;
        *(_DWORD*)& byte_5D4594[829492] = 0;
        *(_DWORD*)& byte_5D4594[829500] = 0;
    }
    return result;
}

//----- (004484D0) --------------------------------------------------------
void __cdecl sub_4484D0(wchar_t* a1, int a2, int a3)
{
    wchar_t* v3; // eax
    const wchar_t* v4; // eax

    if (a1)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16402, a3, 0);
        v3 = sub_41F330((int)a1, a2);
        nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16397, (int)v3, 14);
        v4 = (const wchar_t*)sub_41EC00();
        if (v4)
        {
            if (!nox_wcscmp(v4, a1))
                nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16403, a3, 0);
        }
    }
}

//----- (00448550) --------------------------------------------------------
int __cdecl sub_448550(int a1)
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16398, a1, 0);
}

//----- (00448570) --------------------------------------------------------
void __cdecl sub_448570(const char* a1, char a2, int a3)
{
    char* v3; // eax
    wchar_t v4[256]; // [esp+4h] [ebp-200h]

    if (a1)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16402, a3, 0);
        v3 = sub_41F740((int)a1, a2);
        nox_swprintf(v4, L"%S", v3);
        if (sub_427880(a1))
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v4, 2);
        else
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v4, 14);
    }
}

//----- (00448620) --------------------------------------------------------
int __cdecl sub_448620(int a1)
{
    int result; // eax

    result = a1;
    if (a1 >= 0)
        result = nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16398, a1, 0);
    return result;
}

//----- (00448650) --------------------------------------------------------
int __cdecl sub_448650(_BYTE* a1, wchar_t* a2)
{
    int result; // eax

    if (*a1 == -16)
        result = sub_425680(a1 + 1, a2);
    else
        result = nox_swprintf(a2, L"%S", a1);
    return result;
}

//----- (00448680) --------------------------------------------------------
int __cdecl sub_448680(wchar_t* a1, char* a2)
{
    int result; // eax
    size_t v3; // eax
    char v4[2048]; // [esp+4h] [ebp-800h]

    if (sub_4100F0((__int16*)a1))
        return nox_sprintf(a2, "%S", a1);
    memset(v4, 0, sizeof(v4));
    memset(a2, 0, 0x800u);
    v3 = nox_wcslen(a1);
    sub_425550(a1, v4, 16 * (v3 + 1));
    result = 0;
    *a2 = -16;
    qmemcpy(a2 + 1, v4, strlen(v4));
    return result;
}

//----- (00448F00) --------------------------------------------------------
int __cdecl sub_448F00(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 != 21 || a3 != 28)
        return sub_487D70(a1, a2, a3, a4);
    if (a4 == 2)
    {
        if (*(_DWORD*)& byte_587000[111668] == 1)
        {
            if (*(_DWORD*)& byte_5D4594[830204] != 1)
            {
                sub_448CF0_wol_dialogs();
                return 1;
            }
        }
        else if (*(_DWORD*)& byte_5D4594[830208] != 1)
        {
            sub_448CF0_wol_dialogs();
        }
    }
    return 1;
}

//----- (00448F60) --------------------------------------------------------
int __cdecl sub_448F60(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 != 21 || a3 != 28)
        return sub_487D70(a1, a2, a3, a4);
    if (a4 == 2)
    {
        if (*(_DWORD*)& byte_587000[111668] == 1)
        {
            if (*(_DWORD*)& byte_5D4594[830204] != 1)
            {
                sub_448CF0_wol_dialogs();
                return 1;
            }
        }
        else if (*(_DWORD*)& byte_5D4594[830208] != 1)
        {
            sub_448CF0_wol_dialogs();
        }
    }
    return 1;
}

//----- (00448FC0) --------------------------------------------------------
int __cdecl sub_448FC0(int a1, int a2)
{
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
        {
            sub_434460(*(int*)& byte_5D4594[2650656]);
            sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        }
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
    }
    if (*(_DWORD*)& byte_587000[111668])
    {
        if (*(_DWORD*)& byte_5D4594[830204] && sub_4160F0(0x12u, 10 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            sub_46ABB0(*(int*)& byte_5D4594[830148], 1);
            *(_DWORD*)& byte_5D4594[830204] = 0;
            return 1;
        }
    }
    else if (*(_DWORD*)& byte_5D4594[830208] && sub_4160F0(0x13u, 10 * *(_DWORD*)& byte_5D4594[2649704]))
    {
        sub_46ABB0(*(int*)& byte_5D4594[830148], 1);
        *(_DWORD*)& byte_5D4594[830208] = 0;
    }
    return 1;
}

//----- (00449280) --------------------------------------------------------
int sub_449280()
{
    int result; // eax
    int v1; // eax
    int v2; // ecx
    unsigned int v3; // ecx
    int v4; // eax
    int v5; // ecx
    unsigned int v6; // ecx
    int v7; // eax
    int v8; // ecx
    unsigned int v9; // ecx

    if (*(_DWORD*)& byte_5D4594[830112])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830116])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830120])
        return 0;
    result = nox_new_window_from_file("wolopt.wnd", sub_4493D0);
    *(_DWORD*)& byte_5D4594[830104] = result;
    if (result)
    {
        *(_DWORD*)(result + 56) = *(_DWORD*)& byte_5D4594[2650656];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 16) = (nox_win_width
                                                            - *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 8))
                                                           / 2;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 8)
                                                           + *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 16);
        *(_DWORD*)& byte_5D4594[830192] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830104], 1991);
        *(_DWORD*)& byte_5D4594[830196] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830104], 1992);
        *(_DWORD*)& byte_5D4594[830200] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830104], 1993);
        v1 = sub_41FF60();
        v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830192] + 36);
        if (v1)
            v3 = v2 | 4;
        else
            v3 = v2 & 0xFFFFFFFB;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830192] + 36) = v3;
        v4 = sub_41FF90();
        v5 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830196] + 36);
        if (v4)
            v6 = v5 | 4;
        else
            v6 = v5 & 0xFFFFFFFB;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830196] + 36) = v6;
        v7 = sub_41FFC0();
        v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830200] + 36);
        if (v7)
            v9 = v8 | 4;
        else
            v9 = v8 & 0xFFFFFFFB;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830200] + 36) = v9;
        *(_DWORD*)& byte_5D4594[830120] = 1;
        sub_46B120(*(_DWORD * *)& byte_5D4594[830104], 0);
        sub_46A8C0(*(int*)& byte_5D4594[830104]);
        sub_46C690(*(int*)& byte_5D4594[830104]);
        sub_46B500(*(int*)& byte_5D4594[830104]);
        result = 1;
    }
    return result;
}

//----- (004493D0) --------------------------------------------------------
int __cdecl sub_4493D0(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int result; // eax
    int v5; // eax

    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v3)
    {
        case 1985:
            v5 = sub_41FC40();
            sub_40DB50(v5 + 1, (int)& a2);
            sub_40D670(a2);
            return 0;
        case 1994:
            sub_4494A0();
            result = 0;
            break;
        case 1995:
            sub_46C6E0(*(int*)& byte_5D4594[830104]);
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[830104]);
            sub_447600();
            *(_DWORD*)& byte_5D4594[830120] = 0;
            result = 0;
            break;
        case 1996:
            sub_4B5770_wol_locale(*(int*)& byte_5D4594[830104]);
            result = 0;
            break;
        default:
            return 0;
    }
    return result;
}

//----- (004494A0) --------------------------------------------------------
void sub_4494A0()
{
    sub_41FF70((*(_BYTE*)(*(_DWORD*)& byte_5D4594[830192] + 36) & 4) == 4);
    sub_41FFA0((*(_BYTE*)(*(_DWORD*)& byte_5D4594[830196] + 36) & 4) == 4);
    sub_41FFD0((*(_BYTE*)(*(_DWORD*)& byte_5D4594[830200] + 36) & 4) == 4);
    sub_46C6E0(*(int*)& byte_5D4594[830104]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[830104]);
    *(_DWORD*)& byte_5D4594[830120] = 0;
    sub_447600();
}

//----- (00449530) --------------------------------------------------------
int sub_449530()
{
    const char* v0; // edi
    int v1; // ebp
    int result; // eax
    _DWORD* v3; // ebx
    int v4; // eax
    const char* i; // esi
    char* v6; // eax
    wchar_t* v7; // eax
    int v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // esi
    _DWORD* v11; // ebp
    _DWORD* v12; // eax
    _DWORD* v13; // edi
    char* v14; // eax
    _DWORD* v15; // eax
    char* v16; // [esp+8h] [ebp-94h]
    int v17; // [esp+Ch] [ebp-90h]
    char* v18; // [esp+10h] [ebp-8Ch]
    int v19; // [esp+14h] [ebp-88h]
    wchar_t v20[66]; // [esp+18h] [ebp-84h]

    v0 = 0;
    v16 = 0;
    v17 = -1;
    v1 = 0;
    result = nox_new_window_from_file("servlist.wnd", sub_4497D0_wol_dialogs);
    *(_DWORD*)& byte_5D4594[830108] = result;
    if (result)
    {
        *(_DWORD*)(result + 56) = *(_DWORD*)& byte_5D4594[2650656];
        sub_46B120(*(_DWORD * *)& byte_5D4594[830108], 0);
        sub_46A8C0(*(int*)& byte_5D4594[830108]);
        sub_46C690(*(int*)& byte_5D4594[830108]);
        sub_46B500(*(int*)& byte_5D4594[830108]);
        if (sub_40A5C0(0x2000000))
        {
            v16 = sub_4A7F10();
            v0 = v16;
        }
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1961);
        v4 = sub_4200F0();
        for (i = sub_4205B0(v4); i; i = (const char*)sub_4206B0((int)i))
        {
            if (sub_40A5C0(0x2000000))
            {
                v6 = strchr(i + 24, 58);
                if (v6)
                {
                    if (v0 && !_strcmpi(v0, v6 + 1))
                        v17 = v1;
                }
            }
            nox_swprintf(v20, L"%S", i + 24);
            v7 = nox_wcschr(v20, 0x3Au);
            if (v7)
                nox_window_call_field_94((int)v3, 16397, (int)(v7 + 1), -1);
            ++v1;
        }
        v8 = sub_4200F0();
        if (sub_4207A0(v8) <= 0)
        {
            v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1962);
            sub_46ABB0((int)v9, 0);
        }
        else
        {
            nox_window_call_field_94((int)v3, 16403, 0, 0);
        }
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1964);
        v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1965);
        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1966);
        v13 = (_DWORD*)v3[8];
        v19 = (int)v12;
        v18 = sub_42F970("UISlider");
        v14 = sub_42F970("UISliderLit");
        sub_4B5700((int)v10, 0, 0, (int)v18, (int)v14, (int)v14);
        sub_46B280((int)v10, (int)v3);
        sub_46B280((int)v11, (int)v3);
        sub_46B280(v19, (int)v3);
        v13[9] = v10;
        v13[7] = v11;
        v13[8] = v19;
        *(_DWORD*)(v10[100] + 8) = 16;
        *(_DWORD*)(v10[100] + 12) = 10;
        if (sub_40A5C0(0x2000000) && v16 && v17 != -1)
        {
            *(_DWORD*)(sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1961)[8] + 48) = v17;
            v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1962);
            nox_window_call_field_94(*(int*)& byte_5D4594[830108], 16391, (int)v15, 0);
        }
        result = 1;
    }
    return result;
}

//----- (00449A10) --------------------------------------------------------
_DWORD* __cdecl sub_449A10(int a1, int a2, int a3, int a4, int (*a5)(void), int (*a6)(void))
{
    int v6; // esi
    _DWORD* result; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // eax

    v6 = *(_DWORD*)& byte_587000[26048];
    if (*(_DWORD*)& byte_5D4594[830224] && *(_DWORD*)& byte_5D4594[830216])
        (*(void (**)(void)) & byte_5D4594[830216])();
    *(_DWORD*)& byte_5D4594[830228] = a1;
    *(_DWORD*)& byte_5D4594[830232] = 0;
    *(_DWORD*)& byte_5D4594[830220] = a5;
    *(_DWORD*)& byte_5D4594[830216] = a6;
    if (*(_DWORD*)& byte_5D4594[830224])
    {
        sub_449EA0(a4);
        if (a2)
            sub_449E00(a2);
        result = (_DWORD*)a3;
        if (a3)
            result = (_DWORD*)sub_449E30(a3);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[830240] = 0;
        if (sub_43F320(0) > 10)
            v6 = 2;
        result = nox_new_window_from_file(*(const char**)& byte_587000[4 * v6 + 112976], sub_449CA0);
        *(_DWORD*)& byte_5D4594[830224] = result;
        if (result)
        {
            sub_46B300((int)result, sub_449BE0);
            v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
            sub_46B300((int)v8, sub_449C30);
            v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
            sub_46B300((int)v9, sub_449C30);
            if (a2)
            {
                v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4005);
                nox_window_call_field_94((int)v10, 16385, a2, -1);
            }
            if (a3)
            {
                v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
                nox_window_call_field_94((int)v11, 16385, a3, -1);
            }
            sub_46B120(*(_DWORD * *)& byte_5D4594[830224], 0);
            sub_46A8C0(*(int*)& byte_5D4594[830224]);
            sub_46C690(*(int*)& byte_5D4594[830224]);
            sub_46A9B0(
                    *(_DWORD * *)& byte_5D4594[830224],
                    (nox_win_width - *(int*)(*(_DWORD*)& byte_5D4594[830224] + 8)) / 2,
                    (nox_win_height - *(int*)(*(_DWORD*)& byte_5D4594[830224] + 12)) / 2);
            sub_449EA0(a4);
            result = (_DWORD*)sub_46AE00();
            *(_DWORD*)& byte_5D4594[830236] = result;
            if (result)
                result = (_DWORD*)sub_46ADE0((int)result);
        }
    }
    return result;
}

//----- (00449BE0) --------------------------------------------------------
int __cdecl sub_449BE0(int a1, int a2, int a3, int a4)
{
    int2* v4; // eax

    if (a2 != 21)
        return 0;
    if (a3 == 1)
        return 1;
    if (a3 == 57)
    {
        v4 = sub_4309F0();
        nox_window_call_field_93(a1, 5, v4->field_0 | (v4->field_4 << 16), 0);
    }
    return 0;
}

//----- (00449C30) --------------------------------------------------------
int __cdecl sub_449C30(_DWORD* a1, int a2, int a3, int a4)
{
    _DWORD* v4; // eax
    int v5; // esi

    if (a2 == 21 && a3 == 28)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        v5 = (int)v4;
        if (v4[1] & 8)
        {
            if (!wndIsShown_sub_46ACC0((int)v4))
                nox_window_call_field_94(*(int*)& byte_5D4594[830224], 16391, v5, 0);
        }
    }
    return sub_487D70(a1, a2, a3, a4);
}

//----- (00449CA0) --------------------------------------------------------
int __cdecl sub_449CA0(int a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // eax

    if (a2 == 23)
        return 1;
    if (a2 != 16391)
        return 0;
    switch (sub_46B0A0(a3))
    {
        case 4001:
        case 4007:
            if (byte_5D4594[830240] & 0x20)
                sub_46C6E0(*(int*)& byte_5D4594[830224]);
            nox_window_call_field_94(*(int*)& byte_5D4594[830228], 16391, (int)a3, a4);
            if (*(_DWORD*)& byte_5D4594[830220])
                (*(void (**)(void)) & byte_5D4594[830220])();
            if (!(byte_5D4594[830240] & 0x20))
                return 0;
            sub_44A400();
            result = 0;
            break;
        case 4002:
        case 4006:
            if (byte_5D4594[830240] & 0x20)
                sub_46C6E0(*(int*)& byte_5D4594[830224]);
            nox_window_call_field_94(*(int*)& byte_5D4594[830228], 16391, (int)a3, a4);
            if (*(_DWORD*)& byte_5D4594[830216])
                (*(void (**)(void)) & byte_5D4594[830216])();
            if (!(byte_5D4594[830240] & 0x20))
                return 0;
            sub_44A400();
            result = 0;
            break;
        case 4009:
            sub_41E300(9);
            v5 = sub_41E2F0();
            sub_41DA70(v5, 8);
            sub_43C260();
            sub_44A200(256);
            sub_44A400();
            return 0;
        case 4010:
            nox_window_call_field_94(*(int*)& byte_5D4594[830228], 16391, (int)a3, a4);
            result = 0;
            break;
        default:
            return 0;
    }
    return result;
}

//----- (00449E00) --------------------------------------------------------
int __cdecl sub_449E00(int a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4005);
    return nox_window_call_field_94((int)v1, 16385, a1, -1);
}

//----- (00449E30) --------------------------------------------------------
int __cdecl sub_449E30(int a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
    return nox_window_call_field_94((int)v1, 16385, a1, -1);
}

//----- (00449E60) --------------------------------------------------------
int __cdecl sub_449E60(char a1)
{
    _DWORD* v1; // eax

    if (a1 >= 0)
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
    else
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
    return nox_window_call_field_94((int)v1, 16413, 0, 0);
}

//----- (00449EA0) --------------------------------------------------------
void __cdecl sub_449EA0(int a1)
{
    __int16 v1; // bx
    _DWORD* v2; // esi
    _DWORD* v3; // esi
    _DWORD* v4; // esi
    _DWORD* v5; // esi
    _DWORD* v6; // esi
    _DWORD* v7; // esi
    _DWORD* v8; // esi
    _DWORD* v9; // esi
    int result; // eax
    int v11; // [esp-4h] [ebp-Ch]
    int v12; // [esp-4h] [ebp-Ch]
    int v13; // [esp-4h] [ebp-Ch]
    int v14; // [esp-4h] [ebp-Ch]
    int v15; // [esp-4h] [ebp-Ch]
    int v16; // [esp-4h] [ebp-Ch]
    int v17; // [esp-4h] [ebp-Ch]
    int v18; // [esp-4h] [ebp-Ch]

    v1 = a1 ^ *(_WORD*)& byte_5D4594[830240];
    if (((unsigned __int8)a1 ^ byte_5D4594[830240]) & 1)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        v11 = wndIsShown_sub_46ACC0((int)v2) == 0;
        nox_window_set_hidden((int)v2, v11);
    }
    if (v1 & 2)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
        v12 = wndIsShown_sub_46ACC0((int)v3) == 0;
        nox_window_set_hidden((int)v3, v12);
    }
    if (v1 & 0x100)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4009);
        v13 = wndIsShown_sub_46ACC0((int)v4) == 0;
        nox_window_set_hidden((int)v4, v13);
    }
    if (v1 & 0x200)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4010);
        v14 = wndIsShown_sub_46ACC0((int)v5) == 0;
        nox_window_set_hidden((int)v5, v14);
    }
    if (v1 & 8)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4007);
        v15 = wndIsShown_sub_46ACC0((int)v6) == 0;
        nox_window_set_hidden((int)v6, v15);
    }
    if (v1 & 0x10)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4006);
        v16 = wndIsShown_sub_46ACC0((int)v7) == 0;
        nox_window_set_hidden((int)v7, v16);
    }
    if (v1 & 4)
    {
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
        v17 = wndIsShown_sub_46ACC0((int)v8) == 0;
        nox_window_set_hidden((int)v8, v17);
    }
    if ((v1 & 0x80u) != 0)
    {
        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
        v18 = wndIsShown_sub_46ACC0((int)v9) == 0;
        nox_window_set_hidden((int)v9, v18);
    }
    if (a1 & 0x40)
        sub_430A70_set_mouse_bounds(
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 16),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 24),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 20),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 28));
    else
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    *(_DWORD*)& byte_5D4594[830240] = a1;
}

//----- (0044A0B0) --------------------------------------------------------
int __cdecl sub_44A0B0(int a1)
{
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    int result; // eax

    if (a1 & 1)
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        nox_window_set_hidden((int)v1, 0);
    }
    if (a1 & 2)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
        nox_window_set_hidden((int)v2, 0);
    }
    if (a1 & 0x100)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4009);
        nox_window_set_hidden((int)v3, 0);
    }
    if (a1 & 0x200)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4010);
        nox_window_set_hidden((int)v4, 0);
    }
    if (a1 & 8)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4007);
        nox_window_set_hidden((int)v5, 0);
    }
    if (a1 & 0x10)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4006);
        nox_window_set_hidden((int)v6, 0);
    }
    if (a1 & 4)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
        nox_window_set_hidden((int)v7, 0);
    }
    if ((a1 & 0x80u) != 0)
    {
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
        nox_window_set_hidden((int)v8, 0);
    }
    if (a1 & 0x40)
        sub_430A70_set_mouse_bounds(
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 16),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 20),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 24),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 28));
    else
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    result = a1 | *(_DWORD*)& byte_5D4594[830240];
    *(_DWORD*)& byte_5D4594[830240] |= a1;
    return result;
}

//----- (0044A200) --------------------------------------------------------
int __cdecl sub_44A200(int a1)
{
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    int result; // eax

    if (a1 & 1)
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        nox_window_set_hidden((int)v1, 1);
    }
    if (a1 & 2)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
        nox_window_set_hidden((int)v2, 1);
    }
    if (a1 & 0x100)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4009);
        nox_window_set_hidden((int)v3, 1);
    }
    if (a1 & 0x200)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4010);
        nox_window_set_hidden((int)v4, 1);
    }
    if (a1 & 8)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4007);
        nox_window_set_hidden((int)v5, 1);
    }
    if (a1 & 0x10)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4006);
        nox_window_set_hidden((int)v6, 1);
    }
    if (a1 & 4)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
        nox_window_set_hidden((int)v7, 1);
    }
    if ((a1 & 0x80u) != 0)
    {
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
        nox_window_set_hidden((int)v8, 1);
    }
    if (a1 & 0x40)
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    result = ~a1 & *(_DWORD*)& byte_5D4594[830240];
    *(_DWORD*)& byte_5D4594[830240] &= ~a1;
    return result;
}

//----- (0044A340) --------------------------------------------------------
int __cdecl sub_44A340(int a1, int a2)
{
    return sub_46A9B0(*(_DWORD * *)& byte_5D4594[830224], a1, a2);
}

//----- (0044A360) --------------------------------------------------------
void __cdecl sub_44A360(int a1)
{
    _DWORD* v1; // esi
    _DWORD* v2; // esi
    int result; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4005);
    if (a1 == 1)
    {
        v1[59] = sub_43F360((char*)& byte_587000[113100]);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
        result = sub_43F360((char*)& byte_587000[113108]);
    }
    else
    {
        v1[59] = sub_43F360((char*)& byte_587000[113116]);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
        result = sub_43F360((char*)& byte_587000[113124]);
    }
    v2[59] = result;
}

//----- (0044A400) --------------------------------------------------------
int sub_44A400()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[830224];
    if (*(_DWORD*)& byte_5D4594[830224])
    {
        if (*(_DWORD*)& byte_5D4594[830236])
        {
            sub_46ADC0(*(int*)& byte_5D4594[830236]);
            *(_DWORD*)& byte_5D4594[830236] = 0;
        }
        sub_46C6E0(*(int*)& byte_5D4594[830224]);
        sub_46ADE0(*(int*)& byte_5D4594[830224]);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[830224]);
        if (*(_DWORD*)& byte_5D4594[830232])
            sub_46B500(*(int*)& byte_5D4594[830232]);
        *(_DWORD*)& byte_5D4594[830224] = 0;
        *(_DWORD*)& byte_5D4594[830228] = 0;
        sub_477610(0);
        result = sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    }
    return result;
}

//----- (0044A4A0) --------------------------------------------------------
BOOL sub_44A4A0()
{
    return *(_DWORD*)& byte_5D4594[830224] != 0;
}

//----- (0044A4B0) --------------------------------------------------------
int sub_44A4B0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[830224];
    if (*(_DWORD*)& byte_5D4594[830224])
        result = sub_46A8C0(*(int*)& byte_5D4594[830224]);
    return result;
}

//----- (0044A4D0) --------------------------------------------------------
int __cdecl sub_44A4D0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[830232] = a1;
    return result;
}

//----- (0044A4E0) --------------------------------------------------------
int sub_44A4E0()
{
    _DWORD* v0; // eax

    if (!sub_44A4A0())
        return 0;
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
    nox_window_call_field_94(*(int*)& byte_5D4594[830224], 16391, (int)v0, 0);
    return 1;
}

//----- (0044A520) --------------------------------------------------------
char* __cdecl sub_44A520(int a1)
{
    int v1; // eax
    int v2; // edx
    unsigned __int8* v3; // ecx

    v1 = *(_DWORD*)& byte_587000[113136];
    v2 = 0;
    if (!*(_DWORD*)& byte_587000[113136])
        return *(char**)& byte_587000[113140];
    v3 = &byte_587000[113136];
    while (v1 != a1)
    {
        v1 = *((_DWORD*)v3 + 2);
        v3 += 8;
        ++v2;
        if (!v1)
            return *(char**)& byte_587000[113140];
    }
    return *(char**)& byte_587000[8 * v2 + 113140];
}

//----- (0044AA40) --------------------------------------------------------
int sub_44AA40()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[830244] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    sub_4207F0(1);
    return 1;
}

//----- (0044AA70) --------------------------------------------------------
int sub_44AA70()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[830244] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[830244]);
    if (*(_DWORD*)& byte_5D4594[830248])
    {
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[830248]);
        *(_DWORD*)& byte_5D4594[830248] = 0;
    }
    sub_43BE40(1);
    v0();
    return 1;
}

//----- (0044AAC0) --------------------------------------------------------
int sub_44AAC0()
{
    return 0;
}

//----- (0044AAD0) --------------------------------------------------------
int __cdecl sub_44AAD0(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 == 21)
    {
        if (*(_DWORD*)& byte_5D4594[830268])
        {
            nox_window_call_field_94((int)a1, 16414, (int)& byte_5D4594[830284], 0);
            sub_41FAE0((const char*)& byte_5D4594[830288]);
        }
        *(_DWORD*)& byte_5D4594[830268] = 0;
    }
    return sub_487D70(a1, a2, a3, a4);
}

//----- (0044AB30) --------------------------------------------------------
int __cdecl sub_44AB30(int a1, unsigned int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // eax
    int v6; // esi
    int v7; // eax
    int v8; // eax
    int v9; // esi
    int v10; // esi
    int v11; // eax
    int v12; // eax
    int v13; // eax
    char* v14; // eax
    int v15; // eax
    int v16; // [esp-4h] [ebp-210h]
    _BYTE* v17; // [esp+4h] [ebp-208h]
    int v18; // [esp+8h] [ebp-204h]
    wchar_t File[128]; // [esp+Ch] [ebp-200h]
    char v20[256]; // [esp+10Ch] [ebp-100h]

    if (a2 > 0x4005)
    {
        if (a2 != 16391)
        {
            if (a2 == 16400)
            {
                v6 = sub_46B0A0(a3);
                sub_452D80(766, 100);
                if (v6 == 1708 && a4 >= 0 && a4 < 128)
                {
                    sub_41FC20(a4);
                    sub_41FB90(a4, &v18, &v17);
                    if (v18)
                    {
                        nox_swprintf(File, L"%S", v18);
                        nox_window_call_field_94(*(int*)& byte_5D4594[830256], 16414, (int)File, 0);
                    }
                    if (v17)
                    {
                        nox_swprintf(File, L"%S", v17);
                        nox_window_call_field_94(*(int*)& byte_5D4594[830260], 16414, (int)File, 0);
                        if (v17)
                        {
                            if (*v17)
                            {
                                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830252] + 36) |= 4u;
                                *(_DWORD*)& byte_5D4594[830276] = 1;
                                return 0;
                            }
                        }
                    }
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[830252] + 36) &= 0xFFFFFFFB;
                    *(_DWORD*)& byte_5D4594[830276] = 0;
                }
            }
            return 0;
        }
        v7 = sub_46B0A0(a3);
        if (v7 > 1706)
        {
            if (v7 != 1985)
            {
                if (v7 == 4010)
                {
                    v16 = sub_4200F0();
                    v14 = sub_44A520(*(int*)& byte_5D4594[830280]);
                    nox_sprintf((char*)File, "%s%d.html", v14, v16);
                    ShellExecuteA(0, 0, (LPCSTR)File, 0, (LPCSTR)& byte_587000[113732], 3);
                }
                goto LABEL_42;
            }
        }
        else
        {
            if (v7 != 1706)
            {
                v8 = v7 - 1703;
                if (v8)
                {
                    if (v8 == 2)
                    {
                        sub_41E300(6);
                        sub_4207F0(6);
                        sub_46ABB0(*(int*)& byte_5D4594[830248], 0);
                        sub_40E090();
                        sub_4A1BE0(0);
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[830276] ^= 1u;
                    if (*(_DWORD*)& byte_5D4594[830276])
                    {
                        v10 = sub_41F9A0();
                        nox_window_call_field_94(*(int*)& byte_5D4594[830264], 16403, v10, 0);
                        sub_41FC20(v10);
                    }
                    else
                    {
                        v9 = sub_41FB60();
                        sub_41FC20(128);
                        sub_41FB70(v9);
                    }
                }
                goto LABEL_42;
            }
            v17 = 0;
            if (!*(_DWORD*)& byte_5D4594[830276])
                sub_41FC20(128);
            v11 = nox_window_call_field_94(*(int*)& byte_5D4594[830256], 16413, 0, 0);
            nox_sprintf(v20, "%S", v11);
            sub_41FA80(v20);
            v12 = nox_window_call_field_94(*(int*)& byte_5D4594[830260], 16413, 0, 0);
            nox_sprintf(v20, "%S", v12);
            sub_41FAE0(v20);
            sub_41FC50();
            v13 = sub_41FC40();
            sub_40DB50(v13 + 1, (int)& v17);
            if (!v17)
            {
                sub_4B5770_wol_locale(*(int*)& byte_5D4594[830248]);
                LABEL_42:
                sub_452D80(921, 100);
                return 1;
            }
        }
        *(_DWORD*)& byte_5D4594[830276] = (unsigned __int8)(*(_BYTE*)(*(_DWORD*)& byte_5D4594[830252] + 36) & 4) >> 2;
        sub_41E300(2);
        v15 = sub_41E2F0();
        sub_41DA70(v15, 0);
        sub_4207F0(2);
        sub_40E090();
        sub_46ABB0(*(int*)& byte_5D4594[830248], 0);
        sub_4A1BE0(0);
        goto LABEL_42;
    }
    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        return 1;
    }
    if (a2 == 2)
    {
        *(_DWORD*)& byte_5D4594[830248] = 0;
        return 0;
    }
    if (a2 != 16387)
        return 0;
    result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], a4);
    if (!result)
        return result;
    if ((unsigned __int16)a3 != 1)
        return 0;
    if (a4 == 1702)
    {
        v5 = nox_window_call_field_94(result, 16413, 0, 0);
        nox_sprintf(v20, "%S", v5);
        if (v20[0])
            * (_DWORD*)& byte_5D4594[830268] = 1;
    }
    return 0;
}

//----- (0044AF70) --------------------------------------------------------
int sub_44AF70()
{
    int result; // eax

    *(_BYTE*)(*(_DWORD*)& byte_5D4594[830244] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    result = 1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[830244] + 52) = sub_447620_wol_chat;
    *(_DWORD*)& byte_5D4594[830248] = 0;
    return result;
}

//----- (0044AFB0) --------------------------------------------------------
_DWORD* __cdecl sub_44AFB0(int a1, int a2, int a3)
{
    _DWORD* result; // eax

    if (a3 < -2147221388 || a3 > -2147221386)
        result = sub_449A10(*(int*)& byte_5D4594[830248], a1, a2, 33, 0, 0);
    else
        result = sub_449A10(*(int*)& byte_5D4594[830248], a1, a2, 545, 0, 0);
    *(_DWORD*)& byte_5D4594[830280] = a3;
    return result;
}

//----- (0044B000) --------------------------------------------------------
void sub_44B000()
{
    *(_DWORD*)& byte_5D4594[830272] = 1;
}

//----- (0044B010) --------------------------------------------------------
void sub_44B010()
{
    wchar_t* v0; // eax
    wchar_t* v1; // eax

    sub_43C260();
    sub_41E300(9);
    sub_44E040();
    if (sub_40A5C0(0x2000000))
    {
        v0 = loadString_sub_40F1D0((char*)& byte_587000[113772], 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 75);
        sub_413D30((char*)& byte_587000[113788], v0);
        if (sub_43C710())
            sub_41E400();
        else
            sub_4460C0();
    }
    else if (sub_40A5C0(1))
    {
        *(_DWORD*)& byte_5D4594[830292] = nox_new_window_from_file("woldisc.wnd", sub_44B0F0);
        sub_46A9B0(
                *(_DWORD * *)& byte_5D4594[830292],
                nox_win_width / 2 - *(int*)(*(_DWORD*)& byte_5D4594[830292] + 24) / 2,
                nox_win_height / 2 - *(int*)(*(_DWORD*)& byte_5D4594[830292] + 28) / 2);
    }
    else
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[113840], 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 100);
        sub_445490(v1);
    }
}

//----- (0044B0F0) --------------------------------------------------------
int __cdecl sub_44B0F0(int a1, int a2, int* a3, int a4)
{
    int v3; // eax

    if (a2 != 23)
    {
        if (a2 == 16391)
        {
            v3 = sub_46B0A0(a3) - 581;
            if (!v3)
            {
                sub_44B000();
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830292]);
                goto LABEL_7;
            }
            if (v3 == 1)
            {
                sub_4460C0();
                sub_44A400();
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830292]);
                LABEL_7:
                *(_DWORD*)& byte_5D4594[830292] = 0;
                return 0;
            }
        }
        return 0;
    }
    return 1;
}

//----- (0044B160) --------------------------------------------------------
bool __cdecl nox_parse_thing_flags(nox_thing* obj, nox_memfile* f, const char* a3)
{
    obj->flags = 0;
    sub_423930(a3, &obj->flags, (const char**)& byte_587000[114076]);
    return 1;
}

//----- (0044B190) --------------------------------------------------------
bool __cdecl nox_parse_thing_class(nox_thing* obj, nox_memfile* f, const char* a3)
{
    obj->pri_class = 0;
    sub_423930(a3, &obj->pri_class, (const char**)& byte_587000[114208]);
    return 1;
}

//----- (0044B1C0) --------------------------------------------------------
bool __cdecl nox_parse_thing_subclass(nox_thing* obj, nox_memfile* f, const char* a3)
{
    obj->sub_class = 0;
    sub_423A10(a3, &obj->sub_class);
    return 1;
}

//----- (0044B1F0) --------------------------------------------------------
bool __cdecl nox_parse_thing_extent(nox_thing* obj, nox_memfile* f, char* a3)
{
    nox_shape s;
    bool res = nox_parse_shape(&s, a3);
    obj->shape_kind = s.kind;
    obj->shape_r = s.circle_r;
    obj->shape_w = s.box_w;
    obj->shape_h = s.box_h;
    return res;
}

//----- (0044B230) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_intensity(nox_thing* obj, nox_memfile* f, char* a3)
{
    sscanf(a3, "%f", &obj->light_intensity);
    return 1;
}

//----- (0044B250) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_color(nox_thing* obj, nox_memfile* f, char* a3)
{
    int r;
    int g;
    int b;
    if (sscanf(a3, "%d %d %d", &r, &g, &b) != 3)
        return 0;
    obj->field_f = 2;
    obj->light_color_r = (r <= 255 ? r : 255);
    obj->light_color_g = (g <= 255 ? g : 255);
    obj->light_color_b = (b <= 255 ? b : 255);
    return 1;
}

//----- (0044B2D0) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_dir(nox_thing* obj, nox_memfile* f, char* a3)
{
    int deg = 0;
    if (sscanf(a3, "%d", &deg) != 1)
        return 0;
    if (deg < 0 || deg >= 360)
        return 0;
    obj->light_dir = (__int64)((double)deg * *(double*)& byte_581450[9560] * *(double*)& byte_581450[9552] + *(double*)& byte_581450[9544]);
    obj->field_10 = 0;
    return 1;
}

//----- (0044B330) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_penumbra(nox_thing* obj, nox_memfile* f, char* a3)
{
    int deg = 0;
    if (sscanf(a3, "%d", &deg) != 1)
        return 0;
    if (deg < 0 || deg >= 180)
        return 0;
    obj->light_penumbra = (__int64)((double)deg * *(double*)& byte_581450[9560] * *(double*)& byte_581450[9552] + *(double*)& byte_581450[9544]);
    return 1;
}

//----- (0044B390) --------------------------------------------------------
bool __cdecl nox_things_animate_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    _DWORD* v3; // eax
    _DWORD* v5; // edi
    _BYTE* v6; // ebx
    char v8; // cl
    char v10; // cl
    int result; // eax
    int v13; // ebp
    int v15; // ecx
    char v17; // cl
    const char* v19; // [esp+14h] [ebp-4h]
    unsigned __int8 v20; // [esp+20h] [ebp+8h]
    unsigned __int8 v21; // [esp+20h] [ebp+8h]
    int v22; // [esp+24h] [ebp+Ch]

    v3 = nox_calloc(1u, 0x10u);
    v5 = v3;
    v6 = a3;
    *v3 = 16;
    v8 = nox_memfile_read_u8(f);
    *((_BYTE*)v5 + 8) = v8;
    v10 = nox_memfile_read_u8(f);
    *((_BYTE*)v5 + 9) = v10;
    v20 = nox_memfile_read_u8(f);
    nox_memfile_read(a3, 1u, v20, f);
    a3[v20] = 0;
    v5[3] = sub_44B4C0(a3);
    result = (int)nox_malloc(4 * *((unsigned __int8*)v5 + 8));
    v5[1] = result;
    if (!result)
        return 0;

    v13 = 0;
    v22 = 0;
    if (*((_BYTE*)v5 + 8))
    {
        do
        {
            v15 = nox_memfile_read_u32(f);
            *v6 = byte_5D4594[830832];
            if (v15 == -1)
            {
                v17 = nox_memfile_read_u8(f);
                LOBYTE(v19) = v17;
                v21 = nox_memfile_read_u8(f);
                nox_memfile_read(v6, 1u, v21, f);
                v15 = -1;
                v6[v21] = 0;
                v13 = v22;
            }
            *(_DWORD*)(v5[1] + 4 * v13++) = sub_42FAA0(v15, v19, v6);
            v22 = v13;
        } while (v13 < *((unsigned __int8*)v5 + 8));
    }
    obj->field_5c = v5;
    obj->draw_func = &nox_thing_animate_draw;
    return 1;
}
// 44B47F: variable 'v19' is possibly undefined

//----- (0044B4C0) --------------------------------------------------------
int __cdecl sub_44B4C0(const char* a1)
{
    if (!strcmp(a1, "OneShot"))
        return 0;
    if (!strcmp(a1, "OneShotRemove"))
        return 1;
    if (!strcmp(a1, "Loop"))
        return 2;
    if (!strcmp(a1, "LoopAndFade"))
        return 3;
    if (!strcmp(a1, "Random"))
        return 4;
    return strcmp(a1, "Slave") != 0 ? 0 : 5;
}

//----- (0044B560) --------------------------------------------------------
bool __cdecl nox_things_cond_animate_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    _DWORD* v3; // eax
    unsigned __int8* v5; // ecx
    _BYTE* v6; // edi
    unsigned __int8* v7; // ebp
    unsigned __int8* v8; // eax
    unsigned __int8 v9; // cl
    unsigned __int8* v10; // eax
    unsigned __int8 v11; // cl
    unsigned __int8* v12; // eax
    _DWORD* v13; // ebx
    void* v14; // eax
    int* v15; // eax
    int v16; // ecx
    char* v17; // eax
    char v18; // cl
    int result; // eax
    _DWORD* v20; // [esp+10h] [ebp-18h]
    const char* v21; // [esp+18h] [ebp-10h]
    int v22; // [esp+1Ch] [ebp-Ch]
    int v23; // [esp+20h] [ebp-8h]
    _DWORD* v24; // [esp+24h] [ebp-4h]
    unsigned __int8 v25; // [esp+30h] [ebp+8h]
    unsigned __int8 v26; // [esp+30h] [ebp+8h]
    unsigned __int8 v27; // [esp+30h] [ebp+8h]
    int v28; // [esp+34h] [ebp+Ch]

    v3 = nox_calloc(1u, 0x38u);
    *v3 = 16;
    v24 = v3;
    v25 = nox_memfile_read_u8(f);
    v23 = v25;
    if ((int)v25 <= 0) {
        obj->field_5c = v3;
        obj->draw_func = &nox_thing_cond_animate_draw;
        obj->field_60 = 0;
        return 1;
    }
    v6 = a3;
    v20 = v3 + 1;
    v7 = (unsigned __int8*)(v3 + 6);
    v22 = -24 - (_DWORD)v3;
    while (1)
    {
        v9 = nox_memfile_read_u8(f);
        *v7 = v9;
        v11 = nox_memfile_read_u8(f);
        v7[5] = v11;
        v26 = nox_memfile_read_u8(f);
        nox_memfile_read(v6, 1u, v26, f);
        v6[v26] = 0;
        v13 = v20;
        v20[8] = sub_44B4C0(v6);
        v14 = nox_malloc(4 * *v7);
        *v20 = v14;
        if (!v14)
            break;
        v28 = 0;
        if (*v7)
        {
            do
            {
                v16 = nox_memfile_read_u32(f);
                *v6 = byte_5D4594[830836];
                if (v16 == -1)
                {
                    v18 = nox_memfile_read_u8(f);
                    LOBYTE(v21) = v18;
                    v27 = nox_memfile_read_u8(f);
                    nox_memfile_read(v6, 1u, v27, f);
                    v16 = -1;
                    v6[v27] = 0;
                    v13 = v20;
                }
                *(_DWORD*)(*v13 + 4 * v28++) = sub_42FAA0(v16, v21, v6);
            } while (v28 < *v7);
        }
        ++v7;
        v20 = v13 + 1;
        if ((int)& v7[v22] >= v23)
        {
            v3 = v24;
            obj->field_5c = v3;
            obj->draw_func = &nox_thing_cond_animate_draw;
            obj->field_60 = 0;
            return 1;
        }
    }
    return 0;
}
// 44B68C: variable 'v21' is possibly undefined

//----- (0044B700) --------------------------------------------------------
bool __cdecl nox_things_player_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    _DWORD* v3; // eax
    _DWORD* v5; // ebx
    int v7; // ecx
    int v10; // eax
    int v11; // ebx
    int v13; // ecx
    _DWORD* v14; // eax
    int v15; // ecx
    int v16; // eax
    int v17; // esi
    _DWORD* v18; // eax
    int v19; // esi
    _DWORD* v20; // eax
    _DWORD* v21; // [esp+10h] [ebp-4h]
    unsigned __int8 v22; // [esp+1Ch] [ebp+8h]
    unsigned __int8 v23; // [esp+1Ch] [ebp+8h]

    v3 = nox_calloc(1u, 14524);
    v5 = v3;
    v21 = v3;
    *v3 = 14524;
    v7 = nox_memfile_read_u32(f);
    if (v7 == 1162757152)
        return 0;
    LABEL_3:
    v22 = nox_memfile_read_u8(f);
    nox_memfile_read(a3, 1u, v22, f);
    *((_BYTE*)a3 + v22) = 0;
    v10 = sub_44BB20((const char*)a3);
    if (v10 < 0)
        return 0;
    v11 = (int)& v5[66 * v10 + 1];
    if (!sub_44B8B0(v11, f))
        return 0;
    while (1)
    {
        v13 = nox_memfile_read_u32(f);
        if (v13 == 1162757152)
            break;
        if (v13 == 1398030676)
        {
            v5 = v21;
            goto LABEL_3;
        }
        v23 = nox_memfile_read_u8(f);
        nox_memfile_read(a3, 1u, v23, f);
        *((_BYTE*)a3 + v23) = 0;
        if (!strcmp("NAKED", (const char*)a3))
        {
            v14 = nox_calloc(1u, 0x28u);
            v15 = *(__int16*)(v11 + 40);
            *(_DWORD*)(v11 + 48) = v14;
            v16 = sub_44B940(v14, v15, f);
        }
        else
        {
            v17 = sub_44BA60((const char*)a3);
            if (v17 < 0)
            {
                v19 = sub_44BAC0((const char*)a3);
                if (v19 < 0)
                    return 0;
                v20 = nox_calloc(1u, 0x28u);
                *(_DWORD*)(v11 + 4 * v19 + 156) = v20;
                v16 = sub_44B940(v20, *(__int16*)(v11 + 40), f);
            }
            else
            {
                v18 = nox_calloc(1u, 0x28u);
                *(_DWORD*)(v11 + 4 * v17 + 52) = v18;
                v16 = sub_44B940(v18, *(__int16*)(v11 + 40), f);
            }
        }
        if (!v16)
            return 0;
    }
    obj->draw_func = &nox_thing_player_draw;
    obj->field_5c = v21;
    return 1;
}

//----- (0044B8B0) --------------------------------------------------------
int __cdecl sub_44B8B0(int a1, int a2)
{
    unsigned __int8* v2; // ecx
    unsigned __int8 v3; // dl
    unsigned __int8* v4; // ecx
    unsigned __int8 v5; // dl
    unsigned __int8* v6; // ecx
    unsigned __int8 v8; // [esp+8h] [ebp-104h]
    char v9[256]; // [esp+Ch] [ebp-100h]

    v2 = *(unsigned __int8**)(a2 + 8);
    v3 = *v2;
    *(_DWORD*)(a2 + 8) = v2 + 1;
    *(_WORD*)(a1 + 40) = v3;
    v4 = *(unsigned __int8**)(a2 + 8);
    v5 = *v4;
    *(_DWORD*)(a2 + 8) = v4 + 1;
    *(_WORD*)(a1 + 42) = v5;
    v6 = *(unsigned __int8**)(a2 + 8);
    v8 = *v6;
    *(_DWORD*)(a2 + 8) = v6 + 1;
    nox_memfile_read(v9, 1u, v8, a2);
    v9[v8] = 0;
    *(_DWORD*)(a1 + 44) = sub_44B4C0(v9);
    return 1;
}
// 44B8B0: using guessed type char var_100[256];

//----- (0044B940) --------------------------------------------------------
int __cdecl sub_44B940(_DWORD* a1, int a2, int a3)
{
    int v3; // esi
    int v4; // ebx
    void* v5; // eax
    int v6; // ebp
    int* v7; // eax
    int v8; // ebx
    char* v9; // eax
    char v10; // cl
    unsigned __int8* v11; // eax
    int v13; // [esp+10h] [ebp-90h]
    int v14; // [esp+14h] [ebp-8Ch]
    unsigned __int8 v15; // [esp+18h] [ebp-88h]
    const char* v16; // [esp+1Ch] [ebp-84h]
    char v17[128]; // [esp+20h] [ebp-80h]

    v3 = a2;
    v4 = 0;
    *a1 = 40;
    v14 = 0;
    while (1)
    {
        v13 = v4 >= 16 ? v4 + 4 : v4;
        v5 = nox_malloc(4 * v3);
        *(_DWORD*)((char*)a1 + v13 + 4) = v5;
        if (!v5)
            break;
        v6 = 0;
        if (v3 > 0)
        {
            do
            {
                v7 = *(int**)(a3 + 8);
                v8 = *v7;
                v9 = (char*)(v7 + 1);
                *(_DWORD*)(a3 + 8) = v9;
                v17[0] = byte_5D4594[830840];
                if (v8 == -1)
                {
                    v10 = *v9;
                    v11 = (unsigned __int8*)(v9 + 1);
                    *(_DWORD*)(a3 + 8) = v11;
                    v15 = *v11;
                    *(_DWORD*)(a3 + 8) = v11 + 1;
                    LOBYTE(v16) = v10;
                    nox_memfile_read(v17, 1u, v15, a3);
                    v17[v15] = 0;
                    v3 = a2;
                }
                *(_DWORD*)(*(_DWORD*)((char*)a1 + v13 + 4) + 4 * ++v6 - 4) = sub_42FAA0(v8, v16, v17);
            } while (v6 < v3);
            v4 = v14;
        }
        v4 += 4;
        v14 = v4;
        if (v4 >= 32)
            return 1;
    }
    return 0;
}
// 44BA0E: variable 'v16' is possibly undefined
// 44B940: using guessed type char var_80[128];

//----- (0044BA60) --------------------------------------------------------
int __cdecl sub_44BA60(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[113856];
    while (strcmp(*v2, a1))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[113960])
            return -1;
    }
    return v1;
}

//----- (0044BAC0) --------------------------------------------------------
int __cdecl sub_44BAC0(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[113964];
    while (strcmp(*v2, a1))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[114072])
            return -1;
    }
    return v1;
}

//----- (0044BB20) --------------------------------------------------------
int __cdecl sub_44BB20(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[115688];
    while (strcmp(a1, *v2))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[115908])
            return -1;
    }
    return v1;
}

//----- (0044BB80) --------------------------------------------------------
bool __cdecl nox_things_monster_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    _DWORD* v2; // ebx
    int v4; // ecx
    unsigned __int8 v6; // cl
    unsigned __int8* v8; // eax
    int v9; // edi

    v2 = nox_calloc(1u, 0x304u);
    *v2 = 772;
    while (1)
    {
        v4 = nox_memfile_read_u32(f);
        if (v4 == 1162757152)
            break;
        v6 = nox_memfile_read_u8(f);
        if (v6 < 0x10u)
        {
            unsigned __int8* v7 = f->cur;
            v8 = &v7[*v7 + 1];
            f->cur = v8;
            f->cur += *v8 + 1;
            v9 = (int)& v2[12 * v6 + 1];
            if (sub_44B8B0(v9, f))
            {
                if (sub_44BC50(v9, f))
                    continue;
            }
        }
        return 0;
    }
    obj->draw_func = nox_thing_monster_draw;
    obj->field_5c = v2;
    return 1;
}

//----- (0044BC50) --------------------------------------------------------
int __cdecl sub_44BC50(int a1, int a2)
{
    int v2; // ebp
    int v3; // esi
    void* v4; // eax
    int v5; // ebx
    int* v6; // eax
    int v7; // ebp
    _BYTE* v8; // eax
    char v9; // dl
    unsigned __int8* v10; // eax
    int v11; // esi
    int v13; // [esp+10h] [ebp-90h]
    int v14; // [esp+14h] [ebp-8Ch]
    const char* v15; // [esp+1Ch] [ebp-84h]
    char v16[128]; // [esp+20h] [ebp-80h]

    v2 = 0;
    v14 = 0;
    while (1)
    {
        v13 = v2 >= 16 ? v2 + 4 : v2;
        v3 = a1;
        v4 = nox_malloc(4 * *(__int16*)(a1 + 40));
        *(_DWORD*)(v13 + a1 + 4) = v4;
        if (!v4)
            break;
        v5 = 0;
        if (*(_WORD*)(a1 + 40) > 0)
        {
            do
            {
                v6 = *(int**)(a2 + 8);
                v7 = *v6;
                v8 = v6 + 1;
                *(_DWORD*)(a2 + 8) = v8;
                v16[0] = byte_5D4594[830844];
                if (v7 == -1)
                {
                    v9 = *v8;
                    v10 = v8 + 1;
                    *(_DWORD*)(a2 + 8) = v10;
                    LOBYTE(v15) = v9;
                    v11 = *v10;
                    *(_DWORD*)(a2 + 8) = v10 + 1;
                    nox_memfile_read(v16, 1u, v11, a2);
                    v16[v11] = 0;
                    v3 = a1;
                }
                *(_DWORD*)(*(_DWORD*)(v13 + v3 + 4) + 4 * ++v5 - 4) = sub_42FAA0(v7, v15, v16);
            } while (v5 < *(__int16*)(v3 + 40));
            v2 = v14;
        }
        v2 += 4;
        v14 = v2;
        if (v2 >= 32)
            return 1;
    }
    return 0;
}
// 44BD0C: variable 'v15' is possibly undefined
// 44BC50: using guessed type char var_80[128];

//----- (0044BD60) --------------------------------------------------------
bool __cdecl nox_things_maiden_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    int result = nox_things_monster_draw_parse(obj, f, a3);
    obj->draw_func = &nox_thing_maiden_draw;
    return result;
}

//----- (0044BD90) --------------------------------------------------------
bool __cdecl nox_things_animate_state_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    _DWORD* v2; // ebp
    int v4; // ecx
    int v6; // ecx
    unsigned __int8* v8; // eax
    int v9; // edi
    unsigned __int8 v11; // [esp+Ch] [ebp-4h]

    v2 = nox_calloc(1u, 0x94u);
    *v2 = 148;
    while (1)
    {
        v4 = nox_memfile_read_u32(f);
        if (v4 == 0x454E4420) // "END "
            break;
        v6 = nox_memfile_read_u32(f);
        if (v6 & 0xE)
        {
            unsigned __int8* v7 = f->cur;
            v8 = &v7[*v7 + 1];
            f->cur = v8;
            f->cur += *v8 + 1;
            if (v6 & 2)
            {
                v11 = 0;
            }
            else if (v6 & 4)
            {
                v11 = 1;
            }
            else if (v6 & 8)
            {
                v11 = 2;
            }
            v9 = (int)& v2[12 * v11 + 1];
            if (sub_44B8B0(v9, f))
            {
                if (sub_44BE90(v9, f))
                    continue;
            }
        }
        return 0;
    }
    obj->field_54 = 2;
    obj->draw_func = &nox_thing_animate_state_draw;
    obj->field_5c = v2;
    return 1;
}
// 44BE2F: variable 'v11' is possibly undefined

//----- (0044BE90) --------------------------------------------------------
int __cdecl sub_44BE90(int a1, int a2)
{
    int v2; // esi
    int result; // eax
    int v4; // ebx
    int* v5; // eax
    int v6; // ebp
    _BYTE* v7; // eax
    char v8; // dl
    unsigned __int8* v9; // eax
    int v10; // esi
    const char* v11; // [esp+4h] [ebp-88h]
    char v12[128]; // [esp+Ch] [ebp-80h]

    v2 = a1;
    result = (int)nox_malloc(4 * *(__int16*)(a1 + 40));
    *(_DWORD*)(a1 + 4) = result;
    if (result)
    {
        v4 = 0;
        if (*(_WORD*)(a1 + 40) > 0)
        {
            do
            {
                v5 = *(int**)(a2 + 8);
                v6 = *v5;
                v7 = v5 + 1;
                *(_DWORD*)(a2 + 8) = v7;
                v12[0] = byte_5D4594[830848];
                if (v6 == -1)
                {
                    v8 = *v7;
                    v9 = v7 + 1;
                    *(_DWORD*)(a2 + 8) = v9;
                    LOBYTE(v11) = v8;
                    v10 = *v9;
                    *(_DWORD*)(a2 + 8) = v9 + 1;
                    nox_memfile_read(v12, 1u, v10, a2);
                    v12[v10] = 0;
                    v2 = a1;
                }
                *(_DWORD*)(*(_DWORD*)(v2 + 4) + 4 * v4++) = sub_42FAA0(v6, v11, v12);
            } while (v4 < *(__int16*)(v2 + 40));
        }
        result = 1;
    }
    return result;
}
// 44BF33: variable 'v11' is possibly undefined
// 44BE90: using guessed type char var_80[128];

//----- (0044BF60) --------------------------------------------------------
bool __cdecl nox_things_vector_animate_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    _DWORD* v2; // eax
    _DWORD* v3; // esi
    int result; // eax

    v2 = nox_calloc(1u, 0x30u);
    v3 = v2;
    *v2 = 48;
    result = sub_44BFA0((int)v2, f);
    if (result)
    {
        obj->draw_func = nox_thing_vector_animate_draw;
        obj->field_5c = v3;
        result = 1;
    }
    return result;
}

//----- (0044BFA0) --------------------------------------------------------
int __cdecl sub_44BFA0(int a1, int a2)
{
    int result; // eax

    result = sub_44B8B0(a1, a2);
    if (result)
        result = sub_44BC50(a1, a2);
    return result;
}

//----- (0044BFD0) --------------------------------------------------------
bool __cdecl nox_things_static_random_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    obj->draw_func = nox_thing_static_random_draw;
    void* v3 = sub_44C000(a3, f);
    obj->field_5c = v3;
    return v3 != 0;
}

//----- (0044C000) --------------------------------------------------------
void* __cdecl sub_44C000(_BYTE* a1, int a2)
{
    _DWORD* v2; // eax
    int v3; // esi
    _DWORD* v4; // ebp
    unsigned __int8* v5; // eax
    void* result; // eax
    int v7; // edi
    _BYTE* v8; // ebx
    int* v9; // eax
    int v10; // ecx
    char* v11; // eax
    char v12; // cl
    const char* v13; // [esp+Ch] [ebp-4h]
    unsigned __int8 v14; // [esp+14h] [ebp+4h]
    unsigned __int8 v15; // [esp+18h] [ebp+8h]
    int v16; // [esp+18h] [ebp+8h]

    v2 = nox_calloc(1u, 0xCu);
    v3 = a2;
    v4 = v2;
    *v2 = 12;
    v5 = *(unsigned __int8**)(a2 + 8);
    v15 = *v5;
    *(_DWORD*)(v3 + 8) = v5 + 1;
    *((_BYTE*)v4 + 8) = v15;
    result = nox_malloc(4 * v15);
    v4[1] = result;
    if (result)
    {
        v7 = 0;
        v16 = 0;
        if (*((_BYTE*)v4 + 8))
        {
            v8 = a1;
            do
            {
                v9 = *(int**)(v3 + 8);
                v10 = *v9;
                *(_DWORD*)(v3 + 8) = v9 + 1;
                *v8 = byte_5D4594[830852];
                if (v10 == -1)
                {
                    v11 = *(char**)(v3 + 8);
                    v12 = *v11++;
                    *(_DWORD*)(v3 + 8) = v11;
                    LOBYTE(v13) = v12;
                    v14 = *v11;
                    *(_DWORD*)(v3 + 8) = v11 + 1;
                    nox_memfile_read(v8, 1u, v14, v3);
                    v10 = -1;
                    v8[v14] = 0;
                    v7 = v16;
                }
                *(_DWORD*)(v4[1] + 4 * v7++) = sub_42FAA0(v10, v13, v8);
                v16 = v7;
            } while (v7 < *((unsigned __int8*)v4 + 8));
        }
        result = v4;
    }
    return result;
}
// 44C0BD: variable 'v13' is possibly undefined

//----- (0044C0F0) --------------------------------------------------------
bool __cdecl nox_things_door_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    obj->draw_func = &nox_thing_door_draw;
    void* v3 = sub_44C000(a3, f);
    obj->field_5c = v3;
    return v3 != 0;
}

//----- (0044C120) --------------------------------------------------------
bool __cdecl nox_things_slave_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    obj->draw_func = nox_thing_slave_draw;
    void* v3 = sub_44C000(a3, f);
    obj->field_5c = v3;
    obj->field_60 = 0;
    return v3 != 0;
}

//----- (0044C160) --------------------------------------------------------
bool __cdecl nox_things_static_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3)
{
    char* v6; // edi
    int v8; // ebx
    unsigned __int8 v11; // [esp+Ch] [ebp+8h]

    _DWORD* data = nox_calloc(1u, 8u);
    if (!data)
        return 0;

    data[0] = 8;
    v6 = a3;
    v8 = nox_memfile_read_u32(f);
    *a3 = byte_5D4594[830856];
    if (v8 == -1) {
        LOBYTE(a3) = nox_memfile_read_u8(f);
        v11 = nox_memfile_read_u8(f);
        nox_memfile_read(v6, 1u, v11, f);
        v6[v11] = 0;
    }
    data[1] = sub_42FAA0(v8, a3, v6);
    obj->draw_func = &nox_thing_static_draw;
    obj->field_5c = data;
    return 1;
}

//----- (0044C200) --------------------------------------------------------
bool __cdecl nox_parse_thing_draw(nox_thing* obj, nox_memfile* f, char* a3)
{
    unsigned __int8 v4; // cl
    int v5; // esi
    int result; // eax
    int v11; // [esp+10h] [ebp-104h]
    char v12[256]; // [esp+14h] [ebp-100h]

    v4 = nox_memfile_read_u8(f);
    LOBYTE(v11) = v4;
    v5 = v4;
    nox_memfile_read(v12, 1u, v4, f);
    v12[v5] = 0;
    sub_40AD60((char*)& v11, 4, 1, f);

    if (!*(_DWORD*)nox_parse_thing_draw_funcs)
        return 1;

    nox_parse_thing_draw_funcs_t* item = NULL;
    for (int i=0; i < nox_parse_thing_draw_funcs_cnt; i++) {
        nox_parse_thing_draw_funcs_t* cur = &nox_parse_thing_draw_funcs[i];
        if (!strcmp(cur->name, v12)) {
            item = cur;
            break;
        }
    }
    if (!item) {
        return 1;
    }
    if (item->parse_fnc)
        result = item->parse_fnc(obj, f, a3);
    obj->draw_func = item->draw;
    return 1;
}
// 44C200: using guessed type char var_100[256];

//----- (0044C2F0) --------------------------------------------------------
bool __cdecl nox_parse_thing_z(nox_thing* obj, nox_memfile* f, char* a3)
{
    int z = 0;
    sscanf(a3, "%d", &z);
    obj->z = z;
    return 1;
}

//----- (0044C320) --------------------------------------------------------
bool __cdecl nox_parse_thing_zsize(nox_thing* obj, nox_memfile* f, char* a3)
{
    int min = 0;
    int max = 0;
    sscanf(a3, "%d %d", &min, &max);
    if (max < min)
        max = min;
    obj->zsize_min = (double)min;
    obj->zsize_max = (double)max;
    return 1;
}

//----- (0044C370) --------------------------------------------------------
bool __cdecl nox_parse_thing_size(nox_thing* obj, nox_memfile* f, char* a3)
{
    int w = 0;
    int h = 0;
    sscanf(a3, "%d %d", &w, &h);
    obj->hwidth = w / 2;
    obj->hheight = h / 2;
    return 1;
}

//----- (0044C3B0) --------------------------------------------------------
bool __cdecl nox_parse_thing_menu_icon(nox_thing* obj, nox_memfile* f, char* a3)
{
    obj->menuicon = nox_memfile_read_u32(f);
    if (obj->menuicon == -1) {
        unsigned __int8* p = (unsigned __int8*)(f->cur + 1);
        f->cur = p;
        int sz = *p;
        f->cur = &p[sz + 1];
    }
    return 1;
}

//----- (0044C3F0) --------------------------------------------------------
bool __cdecl nox_parse_thing_audio_loop(nox_thing* obj, nox_memfile* f, char* a3)
{
    obj->audio_loop = sub_40AF50(a3);
    return 1;
}

//----- (0044C410) --------------------------------------------------------
bool __cdecl nox_parse_thing_lifetime(nox_thing* obj, nox_memfile* f, char* a3)
{
    int v = 0;
    sscanf(a3, "%d", &v);
    obj->lifetime = v;
    return 1;
}

//----- (0044C440) --------------------------------------------------------
bool __cdecl nox_parse_thing_weight(nox_thing* obj, nox_memfile* f, char* a3)
{
    int v = 0;
    sscanf(a3, "%d", &v);
    obj->weight = (_BYTE)v;
    obj->pri_class |= 0x80000000;
    return 1;
}

//----- (0044C480) --------------------------------------------------------
bool __cdecl nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* a3)
{
    obj->pretty_name = loadString_sub_40F1D0(a3, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1396);
    return 1;
}

//----- (0044C4B0) --------------------------------------------------------
bool __cdecl nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* a3)
{
    obj->desc = loadString_sub_40F1D0(a3, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1403);
    return 1;
}

//----- (0044C4E0) --------------------------------------------------------
bool __cdecl nox_parse_thing_health(nox_thing* obj, nox_memfile* f, char* a3)
{
    obj->health = atoi(a3);
    return 1;
}

//----- (0044C500) --------------------------------------------------------
bool __cdecl nox_parse_thing_pretty_image(nox_thing* obj, nox_memfile* f, char* a3)
{
    int v8 = 0;
    char v10[128];

    int v3 = nox_memfile_read_u32(f);
    if (v3 == -1)
    {
        v8 = nox_memfile_read_u8(f);
        int n = nox_memfile_read_u8(f);
        nox_memfile_read(v10, 1u, n, f);
    }
    obj->pretty_image = sub_42FAA0(v3, v8, v10);
    return 1;
}

//----- (0044C580) --------------------------------------------------------
void sub_44C580_free()
{
    if (nox_things_head) {
        nox_thing* cur = nox_things_head;
        while(cur) {
            if (cur->name)
                free(cur->name);
            if (cur->field_5c)
                sub_44C650_free(cur->field_5c, cur->draw_func);
            nox_thing* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    nox_things_head = NULL;
    if (nox_things_array)
    {
        free(nox_things_array);
        nox_things_array = NULL;
    }
    nox_things_count = 0;
    sub_44C620();
    if (!sub_40A5C0(1))
        sub_42BF80();
}

//----- (0044C620) --------------------------------------------------------
void sub_44C620()
{
    LPVOID* v0; // esi

    v0 = (LPVOID*)& byte_5D4594[830296];
    do
    {
        if (*v0)
            free(*v0);
        *v0 = 0;
        ++v0;
    } while ((int)v0 < (int)& byte_5D4594[830404]);
}

//----- (0044C650) --------------------------------------------------------
void __cdecl sub_44C650_free(LPVOID lpMem, void* draw)
{
    int kind = 0;
    if (*(_DWORD*)nox_parse_thing_draw_funcs)
    {
        nox_parse_thing_draw_funcs_t* item = NULL;
        for (int i = 0; i < nox_parse_thing_draw_funcs_cnt; i++) {
            nox_parse_thing_draw_funcs_t* cur = &nox_parse_thing_draw_funcs[i];
            if (!cur->name)
                break;
            if (cur->draw == draw) {
                item = cur;
                break;
            }
        }
        if (item) {
            kind = item->kind;
        }
    }
    LPVOID* v7 = 0;
    int v8 = 0;
    char* v9 = 0;
    int v10 = 0;
    char* v11 = 0;
    int v12 = 0;

    switch (kind) {
        case 2:
        case 3:
            if (*((_DWORD*)lpMem + 1)) {
                free(*((LPVOID*)lpMem + 1));
            }
            free(lpMem);
            break;
        case 4:
            v7 = (LPVOID*)((char*)lpMem + 4);
            v8 = 5;
            do {
                if (*v7)
                    free(*v7);
                ++v7;
                --v8;
            } while (v8);
            free(lpMem);
            break;
        case 5:
            sub_44C780((int)lpMem + 4);
            free(lpMem);
            break;
        case 6:
            sub_44C7B0((int)lpMem);
            free(lpMem);
            break;
        case 7:
            v9 = (char*)lpMem + 8;
            v10 = 16;
            do {
                sub_44C780((int)v9);
                v9 += 48;
                --v10;
            } while (v10);
            free(lpMem);
            break;
        case 8:
            v11 = (char*)lpMem + 8;
            v12 = 3;
            do {
                sub_44C780((int)v11);
                v11 += 48;
                --v12;
            } while (v12);
            free(lpMem);
            break;
        default:
            free(lpMem);
            break;
    }
}

//----- (0044C780) --------------------------------------------------------
void* __cdecl sub_44C780(int a1)
{
    int i; // esi
    int v2; // eax
    void* result; // eax

    for (i = 0; i < 32; i += 4)
    {
        v2 = i;
        if (i >= 16)
            v2 = i + 4;
        result = *(void**)(v2 + a1);
        if (result)
            free(result);
    }
    return result;
}

//----- (0044C7B0) --------------------------------------------------------
LPVOID __cdecl sub_44C7B0(int a1)
{
    LPVOID* v1; // ebx
    int v2; // ebp
    LPVOID* v3; // esi
    int v4; // edi
    LPVOID* v5; // esi
    int v6; // edi
    LPVOID result; // eax

    v1 = (LPVOID*)(a1 + 52);
    v2 = 55;
    do
    {
        if (*v1)
        {
            sub_44C780((int)* v1 + 4);
            free(*v1);
        }
        v3 = v1 + 1;
        v4 = 26;
        do
        {
            if (*v3)
            {
                sub_44C780((int)* v3 + 4);
                free(*v3);
            }
            ++v3;
            --v4;
        } while (v4);
        v5 = v1 + 27;
        v6 = 27;
        do
        {
            result = *v5;
            if (*v5)
            {
                sub_44C780((int)result + 4);
                free(*v5);
            }
            ++v5;
            --v6;
        } while (v6);
        v1 += 66;
        --v2;
    } while (v2);
    return result;
}

//----- (0044C840) --------------------------------------------------------
void* __cdecl sub_44C840_read_things(void)
{
    char* v1; // ebx
    int v6; // eax
    CHAR* v9; // esi
    unsigned int v10; // edx
    unsigned __int8* v11; // edi
    unsigned __int8* v12; // edi
    CHAR* v13; // esi
    char v14; // cl
    unsigned __int8* v15; // edi
    int v16; // ecx
    unsigned __int8 v17; // al
    CHAR* v18; // esi
    unsigned int v19; // edx
    unsigned __int8* v20; // edi
    unsigned __int8* v21; // edi
    CHAR* v22; // esi
    char v23; // cl
    int v24; // edx
    unsigned __int8* v25; // edi
    int v26; // ecx
    int i; // [esp+10h] [ebp-4h]
    unsigned __int8 v28; // [esp+18h] [ebp+4h]

    v1 = (char*)nox_malloc(256*1024);
    sub_44CCA0();
    sub_44C580_free();
    nox_things_count = 1;
    sub_485CF0();
    sub_485F30();
    sub_46A360();

    nox_memfile* things = nox_open_thing_bin();
    if (!things)
        return 0;
    sub_40AD10(things, 0, 0);
    while (nox_memfile_read(&i, 4u, 1, things))
    {
        switch (i)
        {
            case 0x5350454C: // "SPEL"
                sub_415100_read_spells(things);
                break;
            case 0x4142494C: // "ABIL"
                sub_415320(things);
                break;
            case 0x41554420: // "AUD "
                sub_414D40(things);
                break;
            case 0x41564E54: // "AVNT"
                sub_452B00(things);
                break;
            case 0x57414C4C: // "WALL"
                if (!sub_46A010(things, v1))
                    return 0;
                break;
            case 0x464C4F52: // "FLOR"
                if (!sub_485B30(things, v1))
                    return 0;
                break;
            case 0x45444745: // "EDGE"
                if (!sub_485D40(things, v1))
                    return 0;
                break;
            case 0x494D4147: // "IMAG"
                sub_415240(things);
                break;
            case 0x54484E47: // "THNG"
                ;
                nox_thing* obj = (nox_thing*)nox_calloc(1, sizeof(nox_thing));
                if (!obj)
                    return 0;
                v28 = *(unsigned __int8*)things->cur;
                things->cur++;
                nox_memfile_read(v1, 1u, v28, things);
                v1[v28] = 0;
                obj->name = nox_clone_str(v1);
                obj->menuicon = -1;
                obj->field_1c = nox_things_count++;
                obj->flags |= 0x1000000;
                *((_BYTE*)obj + 15) = 0;
                obj->field_10 = 0xFFFF;
                obj->audio_loop = 0;
                obj->draw_func = nox_thing_debug_draw;
                obj->zsize_min = 0;
                obj->zsize_max = 30.0f;
                if (!nox_parse_thing(things, v1, obj))
                    return 0;
                obj->next = nox_things_head;
                nox_things_head = obj;
                sub_44CD10(obj->name);
                break;
        }
    }
    *(_DWORD*)& byte_5D4594[2649708] = 1;
    if (nox_loaded_thing_bin)
    {
        if (sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2650664])
        {
            nox_free_thing_bin();
        }
    }
    else
    {
        nox_memfile_free(things);
    }
    void* result = nox_malloc(4 * nox_things_count);
    nox_things_array = result;
    if (result)
    {
        sub_44CCD0();
        v6 = nox_things_count;
        nox_thing* cur = nox_things_head;
        for (int i = 1; i < nox_things_count; i++)
        {
            nox_things_array[v6 - i] = cur;
            sub_44CD60(cur, nox_things_count - i);
            if (*((_BYTE*)cur + 0xe))
            {
                if (!cur->pretty_name)
                {
                    strcpy((char*)& byte_5D4594[830404], "thing.db:");
                    v9 = cur->name;
                    v10 = strlen(cur->name) + 1;
                    v11 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830404];
                    qmemcpy(v11, cur->name, 4 * (v10 >> 2));
                    v13 = &v9[4 * (v10 >> 2)];
                    v12 = &v11[4 * (v10 >> 2)];
                    v14 = v10;
                    LOWORD(v10) = *(_WORD*)& byte_587000[122728];
                    qmemcpy(v12, v13, v14 & 3);
                    v15 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830405];
                    v16 = *(_DWORD*)& byte_587000[122724];
                    *(_DWORD*)--v15 = *(_DWORD*)& byte_587000[122720];
                    v17 = byte_587000[122730];
                    *((_DWORD*)v15 + 1) = v16;
                    *((_WORD*)v15 + 4) = v10;
                    v15[10] = v17;
                    cur->pretty_name = loadString_sub_40F1D0((char*)& byte_5D4594[830404], 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1926);
                }
                if (!cur->desc)
                {
                    strcpy((char*)& byte_5D4594[830404], "thing.db:");
                    v18 = cur->name;
                    v19 = strlen(cur->name) + 1;
                    v20 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830404];
                    qmemcpy(v20, cur->name, 4 * (v19 >> 2));
                    v22 = &v18[4 * (v19 >> 2)];
                    v21 = &v20[4 * (v19 >> 2)];
                    v23 = v19;
                    v24 = *(_DWORD*)& byte_587000[122792];
                    qmemcpy(v21, v22, v23 & 3);
                    v25 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830405];
                    v26 = *(_DWORD*)& byte_587000[122788];
                    *(_DWORD*)--v25 = *(_DWORD*)& byte_587000[122784];
                    *((_DWORD*)v25 + 1) = v26;
                    *((_DWORD*)v25 + 2) = v24;
                    cur->desc = loadString_sub_40F1D0((char*)& byte_5D4594[830404], 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1933);
                }
            }
            v6 = nox_things_count;
            cur = cur->next;
        }
        sub_44CDB0();
        free(v1);
        sub_4131A0();
        sub_415AB0();
        sub_4157C0();
        result = (void*)(sub_42BF10() != 0);
    }
    return result;
}
