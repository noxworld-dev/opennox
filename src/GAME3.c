#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "proto.h"

extern int g_fullscreen;
extern float draw_gamma;
extern float input_sensitivity;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;
extern int nox_win_depth_1;
extern int nox_win_depth_2;

extern int default_win_width;
extern int default_win_height;

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;
extern obj_5D4594_3799572_t obj_5D4594_3800716;

FILE* nox_file_9 = 0;

nox_window* nox_win_main_menu = 0;
nox_window* nox_win_main_bg = 0;

//----- (004A19D0) --------------------------------------------------------
int sub_4A19D0()
{
    int result; // eax

    result = sub_43DDD0(0);
    *(_DWORD*)& byte_5D4594[815132] = 0;
    return result;
}

//----- (004A19F0) --------------------------------------------------------
int __cdecl sub_4A19F0(char* a1)
{
    _DWORD* v1; // esi
    wchar_t* v2; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307292], 152);
    v2 = loadString_sub_40F1D0(a1, 0, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 171);
    return nox_window_call_field_94((int)v1, 16385, (int)v2, -1);
}

//----- (004A1A40) --------------------------------------------------------
int __cdecl sub_4A1A40(int a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307292], 151);
    return sub_46ABB0((int)v1, a1);
}

//----- (004A1A60) --------------------------------------------------------
int sub_4A1A60()
{
    _DWORD* v0; // eax

    v0 = nox_new_window_from_file("OptsBack.wnd", sub_4A1AA0);
    *(_DWORD*)& byte_5D4594[1307292] = v0;
    if (!v0)
        return 0;
    sub_46B300((int)v0, sub_4A18E0);
    return 1;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A1AA0) --------------------------------------------------------
int __cdecl sub_4A1AA0(int a1, int a2, int* a3, int a4)
{
    int v3; // eax
    wchar_t* v4; // eax
    wchar_t* v6; // [esp-10h] [ebp-10h]

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
    }
    else
    {
        if (a2 != 16391)
            return 0;
        if (sub_43BE30() != 2 && sub_43BE30() != 3 || sub_4D6F30())
        {
            v3 = sub_46B0A0(a3) - 151;
            if (v3)
            {
                if (v3 == 1)
                {
                    if (sub_43BE10() == 100)
                    {
                        v6 = loadString_sub_40F1D0((char*)& byte_587000[168732], 0, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 142);
                        v4 = loadString_sub_40F1D0((char*)& byte_587000[168800], 0, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 141);
                        sub_449A10(*(int*)& byte_5D4594[1307292], (int)v4, (int)v6, 56, sub_4A19D0, 0);
                    }
                    else
                    {
                        if (sub_4D6F30())
                            sub_4D6F90(2);
                        if (sub_43BE10() == 700)
                            sub_4A7A60(1);
                        sub_43C1E0();
                    }
                }
            }
            else
            {
                if (sub_43BE10() == 700)
                    sub_4A7A60(0);
                sub_43C220();
            }
            sub_452D80(921, 100);
            return 0;
        }
    }
    return 1;
}

//----- (004A1BD0) --------------------------------------------------------
int sub_4A1BD0()
{
    return sub_46C4E0(*(_DWORD * *)& byte_5D4594[1307292]);
}

//----- (004A1BE0) --------------------------------------------------------
int __cdecl sub_4A1BE0(int a1)
{
    return sub_46ABB0(*(int*)& byte_5D4594[1307292], a1);
}

//----- (004A1C00) --------------------------------------------------------
int sub_4A1C00()
{
    int result; // eax
    _DWORD* v1; // esi
    _DWORD* v2; // esi
    _DWORD* v3; // eax

    sub_4D6F40(0);
    sub_4D6F90(0);
    sub_43BDD0(100);
    result = nox_new_window_from_file("MainMenu.wnd", sub_4A1DC0);
    nox_win_main_menu = result;
    if (result)
    {
        sub_46B300(result, sub_4A18E0);
        v1 = sub_46B0C0(nox_win_main_menu, 110);
        sub_46B2C0((int)v1, sub_4A1DC0);
        result = sub_43C5B0(v1, 0, 0, 0, -270, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[1307308] = result;
        if (result)
        {
            *(_DWORD*)result = 100;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 48) = sub_4A1D40;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 56) = sub_4A1D80;
            v2 = sub_46B0C0(nox_win_main_menu, 120);
            sub_46B2C0((int)v2, sub_4A1DC0);
            result = sub_43C5B0(v2, 0, 270, 0, 510, 0, -20, 0, 40);
            *(_DWORD*)& byte_5D4594[1307304] = result;
            if (result)
            {
                sub_4A19F0((char*)& byte_587000[169196]);
                sub_4D1650();
                sub_578CD0();
                sub_43D9B0(25, 100);
                if (sub_40A5C0(0x2000000))
                {
                    v3 = sub_46B0C0(nox_win_main_menu, 112);
                    nox_window_call_field_94(nox_win_main_menu, 16391, (int)v3, 0);
                }
                result = 1;
            }
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A1D40) --------------------------------------------------------
int sub_4A1D40()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307308] + 64) = 2;
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307304] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004A1D80) --------------------------------------------------------
int sub_4A1D80()
{
    int (*v0)(void); // esi

    v0 = *(int (**)(void))(*(_DWORD*)& byte_5D4594[1307308] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1307308]);
    sub_43C570(*(LPVOID*)& byte_5D4594[1307304]);
    sub_46C4E0(nox_win_main_menu);
    v0();
    return 1;
}

//----- (004A1DC0) --------------------------------------------------------
int __cdecl sub_4A1DC0(int a1, int a2, int* a3, int a4)
{
    int v4; // eax
    wchar_t* v5; // eax
    int v6; // eax
    wchar_t* v7; // eax
    int v8; // eax
    wchar_t* v9; // [esp-10h] [ebp-94h]
    char v10[128]; // [esp+4h] [ebp-80h]

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
    }
    else
    {
        if (a2 != 16391)
            return 0;
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1307308] + 64) && !sub_40A5C0(0x2000000))
        {
        LABEL_32:
            sub_452D80(921, 100);
        }
        else
        {
            switch (sub_46B0A0(a3))
            {
            case 111:
                if (sub_40ABD0() && sub_413840())
                {
                    sub_40A4D0(2048);
                    sub_40A540(0x2000);
                    sub_40A540(0x10000);
                    sub_501AC0(0);
                    v4 = *(_DWORD*)& byte_5D4594[2650636];
                    LOBYTE(v4) = byte_5D4594[2650636] & 0xCF;
                    *(_DWORD*)& byte_5D4594[2650636] = v4;
                    sub_4D6F40(0);
                    sub_4D6F90(0);
                    sub_4D6F60(0);
                    sub_4D6F80(0);
                    sub_470AA0(0);
                    sub_461440(0);
                    sub_4A1D40();
                    sub_472520(1110);
                    if (!sub_4D1630())
                    {
                        sub_43DDD0(0);
                        *(_DWORD*)& byte_5D4594[815132] = 0;
                        return 0;
                    }
                    if (sub_4DC550())
                    {
                        sub_4A7A70(1);
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 52) = sub_4A4DB0;
                    }
                    else
                    {
                        sub_4A7A70(0);
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 52) = sub_4A4840;
                    }
                    sub_452D80(921, 100);
                }
                else
                {
                    v9 = loadString_sub_40F1D0((char*)& byte_587000[169256], 0, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 341);
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[169304], 0, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 341);
                    sub_449A10(nox_win_main_menu, (int)v5, (int)v9, 33, 0, 0);
                    sub_44A360(1);
                    sub_44A4B0();
                    sub_452D80(921, 100);
                }
                return 1;
            case 112:
                sub_4A1D40();
                *(_DWORD*)& byte_5D4594[2650636] = *(_DWORD*)& byte_5D4594[2650636] & 0xFFFFFFDF | 0x10;
                sub_40A4D0(0x2000);
                sub_40A4D0(0x10000);
                sub_40A540(2048);
                sub_461440(0);
                sub_4D6F40(0);
                sub_4D6F90(0);
                sub_4D6F60(0);
                sub_4D6F80(0);
                if (!sub_473670())
                    sub_473610();
                sub_470AA0(0);
                sub_472520(2300);
                if (sub_4D1630())
                    goto LABEL_26;
                sub_43DDD0(0);
                *(_DWORD*)& byte_5D4594[815132] = 0;
                return 0;
            case 121:
                if (!sub_4CB230("Intro.vqa", v10))
                    goto LABEL_32;
                sub_4A1D40();
                sub_4B0300(v10);
                sub_4B0640(sub_43C0A0);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 52) = sub_4A2200;
                sub_452D80(921, 100);
                return 1;
            case 122:
                if (sub_44E560())
                {
                    sub_450160(255, 1, 0);
                    sub_4A2530();
                }
                v8 = a3[9];
                LOBYTE(v8) = v8 & 0xFD;
                a3[9] = v8;
                goto LABEL_32;
            case 131:
                LOBYTE(v6) = sub_4D7700();
                if (!v6)
                {
                    v7 = loadString_sub_40F1D0((char*)& byte_587000[169352], 0, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 416);
                    sub_449A10(nox_win_main_menu, 0, (int)v7, 33, 0, 0);
                    sub_44A360(0);
                    sub_44A4B0();
                    sub_452D80(921, 100);
                    return 1;
                }
                sub_4A1D40();
                *(_DWORD*)& byte_5D4594[2650636] = *(_DWORD*)& byte_5D4594[2650636] & 0xFFFFFFDF | 0x10;
                sub_40A4D0(0x2000);
                sub_40A4D0(0x10000);
                sub_40A540(2048);
                sub_4D6F40(1);
                sub_4D6F90(1);
                sub_4E3CD0(0);
                sub_4D7440(0);
                sub_472520(2300);
                if (!sub_473670())
                    sub_473610();
                sub_461440(0);
                if (!sub_4D1630())
                {
                    sub_43DDD0(0);
                    *(_DWORD*)& byte_5D4594[815132] = 0;
                    return 0;
                }
            LABEL_26:
#ifdef __EMSCRIPTEN__
                sub_4AA450();
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 52) = sub_4379F0;
                sub_43AF50(0);
#else
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1307308] + 52) = sub_4AA270;
#endif
                sub_452D80(921, 100);
                break;
            default:
                goto LABEL_32;
            }
        }
    }
    return 1;
}
// 4A203B: variable 'v6' is possibly undefined

//----- (004A2200) --------------------------------------------------------
int sub_4A2200()
{
    return sub_4B0340(0);
}

//----- (004A2210) --------------------------------------------------------
int sub_4A2210()
{
    int result; // eax
    _DWORD* v1; // esi
    const char* v2; // eax
    unsigned __int8* v3; // esi

    *(_DWORD*)& byte_5D4594[815132] = 1;
    nox_win_main_bg = nox_new_window_from_file("MainBG.wnd", sub_4A2490);
    result = sub_4A1A60();
    if (result)
    {
        v1 = sub_46B0C0(nox_win_main_bg, 98);
        sub_46B300((int)v1, sub_4A18E0);
        sub_46B340((int)v1, sub_4A22A0);
        v2 = *(const char**)& byte_587000[168832];
        if (*(_DWORD*)& byte_587000[168832])
        {
            v3 = &byte_587000[168832];
            do
            {
                *((_DWORD*)v3 + 1) = sub_42F970(v2);
                v2 = (const char*) * ((_DWORD*)v3 + 12);
                v3 += 48;
            } while (v2);
        }
        sub_46B500(nox_win_main_bg);
        result = 1;
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A22A0) --------------------------------------------------------
int __cdecl sub_4A22A0(int a1, int* a2)
{
    int v2; // edx
    int v3; // ecx
    unsigned __int8* v4; // esi
    int v5; // eax
    int v6; // eax
    bool v7; // zf
    int v8; // eax
    int v9; // eax
    unsigned __int8* v10; // esi
    int v11; // eax
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_430B40_get_mouse_prev_seq();
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (a2[5] != 0x80000000)
        {
            sub_434460(a2[5]);
            sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        }
    }
    else
    {
        v2 = *(_DWORD*)(a1 + 100);
        xLeft += *(_DWORD*)(a1 + 96);
        v3 = v2 + yTop;
        LOBYTE(v2) = *(_BYTE*)(a1 + 36);
        yTop = v3;
        if (v2 & 2)
            sub_47D2C0(a2[10], xLeft, v3);
        else
            sub_47D2C0(a2[6], xLeft, v3);
    }
    if (*(_DWORD*)& byte_587000[168836])
    {
        v4 = &byte_587000[168868];
        do
        {
            v5 = *((_DWORD*)v4 + 2);
            if (v5)
                * ((_DWORD*)v4 + 2) = v5 - 1;
            v6 = *((_DWORD*)v4 + 1);
            if (v6)
            {
                *((_DWORD*)v4 + 1) = v6 - 1;
                *((_DWORD*)v4 + 2) = sub_415FF0(60, 120, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 180);
            }
            v7 = (*(_DWORD*)v4)-- == 1;
            v8 = *((_DWORD*)v4 - 5);
            if (v7)
            {
                if (v8)
                {
                    *((_DWORD*)v4 - 5) = 0;
                    *(_DWORD*)v4 = sub_415FF0(*((_DWORD*)v4 - 4), *((_DWORD*)v4 - 3), "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 211);
                    *((_DWORD*)v4 + 2) = sub_415FF0(60, 90, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 214);
                }
                else
                {
                    *((_DWORD*)v4 - 5) = 1;
                    *(_DWORD*)v4 = sub_415FF0(*((_DWORD*)v4 - 2), *((_DWORD*)v4 - 1), "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 199);
                }
            }
            else if (!v8
                && !*((_DWORD*)v4 + 2)
                && !*((_DWORD*)v4 + 1)
                && sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 228) > 75)
            {
                *((_DWORD*)v4 + 1) = sub_415FF0(4, 8, "C:\\NoxPost\\src\\Client\\shell\\mainmenu.c", 229);
            }
            v9 = *((_DWORD*)v4 + 4);
            v4 += 48;
        } while (v9);
    }
    if (*(_DWORD*)& byte_587000[168832])
    {
        v10 = &byte_587000[168872];
        do
        {
            if (!*((_DWORD*)v10 - 6) && !*(_DWORD*)v10)
                sub_47D2C0(*((_DWORD*)v10 - 9), *((_DWORD*)v10 - 8), *((_DWORD*)v10 - 7));
            v11 = *((_DWORD*)v10 + 2);
            v10 += 48;
        } while (v11);
    }
    return 1;
}

//----- (004A2490) --------------------------------------------------------
BOOL __cdecl sub_4A2490(int a1, int a2, int a3, int a4)
{
    return a2 == 23;
}

//----- (004A24A0) --------------------------------------------------------
int sub_4A24A0()
{
    sub_4A1BD0();
    sub_46C5D0();
    *(_DWORD*)& byte_5D4594[815132] = 0;
    return 1;
}

//----- (004A24C0) --------------------------------------------------------
int __cdecl sub_4A24C0(int a1)
{
    _DWORD* v1; // eax
    int result; // eax

    v1 = sub_46B0C0(nox_win_main_bg, 99);
    result = nox_window_set_hidden((int)v1, a1);
    if (!a1)
        result = sub_43E8C0(1);
    return result;
}

//----- (004A24F0) --------------------------------------------------------
int sub_4A24F0()
{
    return sub_46B500(nox_win_main_bg);
}

//----- (004A2500) --------------------------------------------------------
int sub_4A2500()
{
    sub_43DDE0(1);
    nox_window_set_hidden(nox_win_main_bg, 0);
    nox_window_set_hidden(nox_win_main_menu, 0);
    return sub_4A24F0();
}

//----- (004A2530) --------------------------------------------------------
int sub_4A2530()
{
    sub_43DDE0(0);
    nox_window_set_hidden(nox_win_main_bg, 1);
    return nox_window_set_hidden(nox_win_main_menu, 1);
}

//----- (004A2560) --------------------------------------------------------
BOOL __cdecl sub_4A2560(_DWORD* a1, int a2)
{
    double v2; // st7
    double v3; // st6

    v2 = (double)(*(__int16*)(a2 + 44) - *a1);
    v3 = (double)(*(__int16*)(a2 + 46) - a1[1]);
    return sqrt(v3 * v3 + v2 * v2) <= *(double*)& byte_581450[9720];
}

//----- (004A25C0) --------------------------------------------------------
int __cdecl sub_4A25C0(_DWORD* a1, int* a2)
{
    int v2; // edi
    int* v3; // esi

    v2 = 0;
    v3 = sub_425890(a2);
    if (!v3)
        return 0;
    do
    {
        if (sub_4A2560(a1, (int)v3))
            ++v2;
        v3 = sub_4258A0(v3);
    } while (v3);
    return v2;
}

//----- (004A2610) --------------------------------------------------------
int __cdecl sub_4A2610(int a1, _DWORD* a2, int* a3)
{
    int* i; // esi
    int v4; // eax
    _DWORD* v5; // esi
    _DWORD* v6; // ebx
    _DWORD* v7; // edi
    _DWORD* v8; // ebp
    char* v9; // eax
    int v10; // ebx
    unsigned __int8* v11; // esi
    _DWORD* v13; // [esp+Ch] [ebp-150h]
    char* v14; // [esp+10h] [ebp-14Ch]
    int v15[2]; // [esp+14h] [ebp-148h]
    char v16[64]; // [esp+1Ch] [ebp-140h]
    wchar_t v17[128]; // [esp+5Ch] [ebp-100h]

    *(_DWORD*)& byte_5D4594[1307720] = 0;
    for (i = sub_425890(a3); i; i = sub_4258A0(i))
    {
        if (sub_4A2560(a2, (int)i))
        {
            v4 = *(_DWORD*)& byte_5D4594[1307720];
            *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1307720] + 1307316] = i;
            *(_DWORD*)& byte_5D4594[1307720] = v4 + 1;
        }
    }
    if (*(_DWORD*)& byte_5D4594[1307720] > 0)
    {
        *(_DWORD*)& byte_5D4594[1307716] = nox_new_window_from_file("proxlist.wnd", *(_DWORD*)(a1 + 376));
        sub_4A2830(*a2 + 216, a2[1] + 27, v15);
        sub_46A9B0(*(_DWORD * *)& byte_5D4594[1307716], v15[0], v15[1]);
        sub_46B280(*(int*)& byte_5D4594[1307716], a1);
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307716], 10064);
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307716], 10062);
        v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307716], 10063);
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307716], 10061);
        v8 = (_DWORD*)v7[8];
        v14 = sub_42F970("UISlider");
        v9 = sub_42F970("UISliderLit");
        sub_4B5700((int)v5, 0, 0, (int)v14, (int)v9, (int)v9);
        sub_46B280((int)v5, (int)v7);
        sub_46B280((int)v6, (int)v7);
        sub_46B280((int)v13, (int)v7);
        v8[9] = v5;
        v8[7] = v6;
        v8[8] = v13;
        *(_DWORD*)(v5[100] + 8) = 16;
        *(_DWORD*)(v5[100] + 12) = 10;
        v10 = 0;
        if (*(_DWORD*)& byte_5D4594[1307720] > 0)
        {
            v11 = &byte_5D4594[1307316];
            do
            {
                if (*(_BYTE*)(*(_DWORD*)v11 + 120))
                {
                    strncpy(v16, (const char*)(*(_DWORD*)v11 + 120), 0xFu);
                    v16[15] = 0;
                }
                else
                {
                    sub_43BC80(*(_DWORD*)v11 + 12, *(_WORD*)(*(_DWORD*)v11 + 109), v16);
                }
                nox_swprintf(v17, L"%S   %dms", v16, *(_DWORD*)(*(_DWORD*)v11 + 96));
                nox_window_call_field_94((int)v7, 16397, (int)v17, -1);
                ++v10;
                v11 += 4;
            } while (v10 < *(int*)& byte_5D4594[1307720]);
        }
    }
    return *(_DWORD*)& byte_5D4594[1307716];
}

//----- (004A2830) --------------------------------------------------------
_DWORD* __cdecl sub_4A2830(int a1, int a2, _DWORD* a3)
{
    _DWORD* result; // eax

    result = a3;
    *a3 = a1 - 100;
    a3[1] = a2 - 20;
    if (a1 - 100 + 200 > 600)
        * a3 = 400;
    if (a2 - 20 + 200 > 451)
        a3[1] = 251;
    if (a3[1] < 27)
        a3[1] = 27;
    if ((int)* a3 < 216)
        * a3 = 216;
    return result;
}

//----- (004A2890) --------------------------------------------------------
int sub_4A2890()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1307716];
    if (*(_DWORD*)& byte_5D4594[1307716])
    {
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1307716]);
        *(_DWORD*)& byte_5D4594[1307716] = 0;
    }
    return result;
}

//----- (004A28B0) --------------------------------------------------------
BOOL sub_4A28B0()
{
    return *(_DWORD*)& byte_5D4594[1307716] != 0;
}

//----- (004A28C0) --------------------------------------------------------
int __cdecl sub_4A28C0(int a1)
{
    int result; // eax

    if (a1 < *(int*)& byte_5D4594[1307720])
        result = *(_DWORD*)& byte_5D4594[4 * a1 + 1307316];
    else
        result = 0;
    return result;
}

//----- (004A28E0) --------------------------------------------------------
int __cdecl sub_4A28E0(_DWORD* a1, int a2, unsigned int a3, int a4)
{
    _DWORD* v4; // edi
    int v5; // esi
    int result; // eax
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // edx
    int v11; // eax
    unsigned int v12; // ebx
    unsigned int v13; // ebx
    int v14; // eax
    int v15; // ecx
    int v16; // eax
    unsigned int v17; // eax
    unsigned int v18; // ebx
    int v19; // eax
    int v20; // ecx
    int v21; // eax
    int v22; // eax

    v4 = a1;
    v5 = a1[8];
    switch (a2)
    {
    case 5:
    case 17:
    case 18:
        return 1;
    case 6:
    case 7:
        v12 = a3;
        a3 = *(_DWORD*)(v5 + 48);
        v13 = v12 >> 16;
        sub_46AA60(a1, &a1, &a4);
        if (*((_WORD*)v4 + 54))
        {
            v14 = sub_43F320(v4[59]);
            a4 += v14 + 1;
        }
        v15 = 0;
        *(_DWORD*)(v5 + 48) = -2;
        v16 = 0;
        while (2)
        {
            if (v16 > 0 && *(int*)(v16 + *(_DWORD*)(v5 + 24) - 524) > * (__int16*)(v5 + 52) + *(__int16*)(v5 + 54)
                || v15 == *(__int16*)(v5 + 44))
            {
                *(_DWORD*)(v5 + 48) = -1;
            }
            else if (*(int*)(v16 + *(_DWORD*)(v5 + 24)) <= (int)(v13 + *(__int16*)(v5 + 54) - a4))
            {
                ++v15;
                v16 += 524;
                continue;
            }
            break;
        }
        v17 = a3;
        if (v15 == a3 && !*(_DWORD*)(v5 + 20))
            * (_DWORD*)(v5 + 48) = -1;
        if (*(int*)(v5 + 48) == -2 && v15 < *(__int16*)(v5 + 44))
            * (_DWORD*)(v5 + 48) = v15;
        if (*(int*)(v5 + 48) < 0)
        {
            if (*(_DWORD*)(v5 + 20))
                * (_DWORD*)(v5 + 48) = v17;
        }
        nox_window_call_field_94(v4[13], 16400, (int)v4, *(_DWORD*)(v5 + 48));
        return 1;
    case 8:
        v22 = a1[11];
        if (v22 & 0x100)
            nox_window_call_field_94(a1[13], 0x4000, (int)a1, 0);
        return 1;
    case 10:
    case 11:
        v18 = a3 >> 16;
        sub_46AA60(a1, &a3, &a4);
        if (*((_WORD*)v4 + 54))
        {
            v19 = sub_43F320(v4[59]);
            a4 += v19 + 1;
        }
        v20 = 0;
        v21 = 0;
        break;
    case 19:
    LABEL_9:
        v8 = *(_DWORD*)(v5 + 48);
        if (v8 == -1)
        {
            *(_DWORD*)(v5 + 48) = 0;
            sub_4A2D10((int)v4, 0, 1);
        }
        else if (v8 > 0)
        {
            v11 = v8 - 1;
            *(_DWORD*)(v5 + 48) = v11;
            if (*(_DWORD*)(*(_DWORD*)(v5 + 24) + 524 * v11) < *(__int16*)(v5 + 54))
                sub_4A2D10((int)v4, -1, 1);
        }
        goto LABEL_21;
    case 20:
    LABEL_6:
        v7 = *(_DWORD*)(v5 + 48);
        if (v7 == -1)
        {
            *(_DWORD*)(v5 + 48) = 0;
            sub_4A2D10((int)v4, 0, 1);
        }
        else if (v7 < *(__int16*)(v5 + 44) - 1)
        {
            v9 = v7 + 1;
            v10 = *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54);
            *(_DWORD*)(v5 + 48) = v9;
            if (*(_DWORD*)(*(_DWORD*)(v5 + 24) + 524 * v9) > v10)
                sub_4A2D10((int)v4, 1, 1);
        }
    LABEL_21:
        nox_window_call_field_94(v4[13], 16400, (int)v4, *(_DWORD*)(v5 + 48));
        return 1;
    case 21:
        switch (a3)
        {
        case 0xFu:
        case 0xCDu:
            if (a4 != 2)
                return 1;
            sub_46A8A0();
            result = 1;
            break;
        case 0x1Cu:
        case 0x39u:
            if (a4 != 1)
                return 1;
            nox_window_call_field_94(a1[13], 16400, (int)a1, *(_DWORD*)(v5 + 48));
            result = 1;
            break;
        case 0xC8u:
            if (a4 == 2)
                goto LABEL_9;
            return 1;
        case 0xCBu:
            if (a4 != 2)
                return 1;
            sub_46A8B0();
            result = 1;
            break;
        case 0xD0u:
            if (a4 == 2)
                goto LABEL_6;
            return 1;
        default:
            return 0;
        }
        return result;
    default:
        return 0;
    }
    while ((v21 <= 0 || *(_DWORD*)(v21 + *(_DWORD*)(v5 + 24) - 524) <= *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54))
        && v20 != *(__int16*)(v5 + 44))
    {
        if (*(_DWORD*)(v21 + *(_DWORD*)(v5 + 24)) > (int)(v18 + *(__int16*)(v5 + 54) - a4))
            goto LABEL_50;
        ++v20;
        v21 += 524;
    }
    v20 = -1;
LABEL_50:
    nox_window_call_field_94(v4[13], 16401, (int)v4, v20);
    return 1;
}

//----- (004A2D10) --------------------------------------------------------
int __cdecl sub_4A2D10(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // eax
    int v5; // ecx
    int result; // eax
    int v7; // ecx

    v3 = *(_DWORD*)(a1 + 32);
    v4 = a2 + sub_4A4800(*(_DWORD*)(a1 + 32));
    if (v4 >= 0)
    {
        v5 = *(__int16*)(v3 + 44);
        if (v4 >= v5)
            v4 = v5 - 1;
    }
    else
    {
        v4 = 0;
    }
    if (a3)
    {
        if (v4 <= 0)
            * (_WORD*)(v3 + 54) = 0;
        else
            *(_WORD*)(v3 + 54) = *(_WORD*)(*(_DWORD*)(v3 + 24) + 524 * v4 - 524) + 1;
    }
    result = *(_DWORD*)(v3 + 36);
    if (result)
    {
        result = *(_DWORD*)(result + 32);
        v7 = *(_DWORD*)(v3 + 40) - *(__int16*)(v3 + 52) + 3;
        *(_DWORD*)(result + 4) = v7;
        if (v7 < 0)
            * (_DWORD*)(result + 4) = 0;
        *(float*)(result + 8) = (double)(int)(*(_DWORD*)(*(_DWORD*)(v3 + 36) + 12)
            - *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v3 + 36) + 400) + 12))
            / (double) * (int*)(result + 4);
        if (a3)
            result = nox_window_call_field_94(*(_DWORD*)(v3 + 36), 16394, *(_DWORD*)(result + 4) - *(__int16*)(v3 + 54), 0);
    }
    return result;
}

//----- (004A2DE0) --------------------------------------------------------
int __cdecl sub_4A2DE0(int a1, int a2, unsigned int a3, int a4)
{
    int v4; // ebp
    int v5; // esi
    int result; // eax
    unsigned int v7; // edi
    int v8; // eax
    unsigned int v9; // ecx
    int v10; // ebx
    int v11; // eax
    int* v12; // edi
    int v13; // ecx
    int v14; // eax
    int v15; // edx
    unsigned int v16; // edi
    int v17; // eax
    unsigned int v18; // edx
    int v19; // ecx
    int v20; // eax
    int v21; // eax

    v4 = a1;
    v5 = *(_DWORD*)(a1 + 32);
    switch (a2)
    {
    case 5:
    case 17:
    case 18:
        return 1;
    case 6:
    case 7:
        v7 = a3 >> 16;
        sub_46AA60((_DWORD*)a1, &a2, &a3);
        if (*(_WORD*)(a1 + 108))
        {
            v8 = sub_43F320(*(_DWORD*)(a1 + 236));
            v9 = a3 + v8 + 1;
            a3 += v8 + 1;
        }
        else
        {
            v9 = a3;
        }
        v10 = 0;
        v11 = 0;
        while (2)
        {
            if (v11 <= 0)
                goto LABEL_12;
            if (*(_DWORD*)(v11 + *(_DWORD*)(v5 + 24) - 524) > * (__int16*)(v5 + 52) + *(__int16*)(v5 + 54))
            {
                v10 = -1;
            LABEL_16:
                v4 = a1;
                goto LABEL_17;
            }
            v4 = a1;
        LABEL_12:
            if (v10 != *(__int16*)(v5 + 44))
            {
                if (*(_DWORD*)(v11 + *(_DWORD*)(v5 + 24)) <= (int)(v7 + *(__int16*)(v5 + 54) - v9))
                {
                    v4 = a1;
                    ++v10;
                    v11 += 524;
                    continue;
                }
                goto LABEL_16;
            }
            break;
        }
        v10 = -1;
    LABEL_17:
        v12 = *(int**)(v5 + 48);
        v13 = 0;
        v14 = *v12;
        if ((int)* v12 < 0)
        {
        LABEL_24:
            v12[v13] = v10;
            *(_DWORD*)(*(_DWORD*)(v5 + 48) + 4 * v13 + 4) = -1;
            nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16400, v4, v10);
            result = 1;
        }
        else
        {
            v15 = *(_DWORD*)(v5 + 48);
            while (v14 != v10)
            {
                v14 = *(_DWORD*)(v15 + 4);
                v15 += 4;
                ++v13;
                if (v14 < 0)
                    goto LABEL_24;
            }
            sub_4A3090((__int16*)v5, v13);
            nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16400, v4, v10);
            result = 1;
        }
        return result;
    case 8:
        v21 = *(_DWORD*)(a1 + 44);
        if (v21 & 0x100)
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, 0);
        return 1;
    case 10:
    case 11:
        v16 = a3 >> 16;
        sub_46AA60((_DWORD*)a1, &a2, &a3);
        if (*(_WORD*)(a1 + 108))
        {
            v17 = sub_43F320(*(_DWORD*)(a1 + 236));
            v18 = a3 + v17 + 1;
            a3 += v17 + 1;
        }
        else
        {
            v18 = a3;
        }
        v19 = 0;
        v20 = 0;
        while (2)
        {
            if (v20 <= 0)
                goto LABEL_32;
            if (*(_DWORD*)(v20 + *(_DWORD*)(v5 + 24) - 524) > * (__int16*)(v5 + 52) + *(__int16*)(v5 + 54))
            {
                v19 = -1;
            LABEL_36:
                nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16401, a1, v19);
                return 1;
            }
            v4 = a1;
        LABEL_32:
            if (v19 != *(__int16*)(v5 + 44))
            {
                if (*(_DWORD*)(v20 + *(_DWORD*)(v5 + 24)) <= (int)(v16 + *(__int16*)(v5 + 54) - v18))
                {
                    v4 = a1;
                    ++v19;
                    v20 += 524;
                    continue;
                }
                goto LABEL_36;
            }
            break;
        }
        nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16401, v4, -1);
        return 1;
    case 19:
        if (!*(_DWORD*)(v5 + 28) || *(short*)(v5 + 54) <= 0)
            return 1;
        sub_4A2D10(a1, -1, 1);
        return 1;
    case 20:
        if (!*(_DWORD*)(v5 + 32) || *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54) > * (int*)(v5 + 40))
            return 1;
        sub_4A2D10(a1, 1, 1);
        return 1;
    case 21:
        if (a3 != 15)
            return 0;
        if (a4 != 2)
            return 1;
        sub_46A8A0();
        return 1;
    default:
        return 0;
    }
}

//----- (004A3090) --------------------------------------------------------
__int16* __cdecl sub_4A3090(__int16* a1, int a2)
{
    __int16* result; // eax

    result = a1;
    qmemcpy((void*)(*((_DWORD*)a1 + 12) + 4 * a2), (const void*)(*((_DWORD*)a1 + 12) + 4 * a2 + 4), 4 * (*a1 - a2));
    *(_DWORD*)(*((_DWORD*)a1 + 12) + 4 * *a1 - 4) = -1;
    return result;
}

//----- (004A30D0) --------------------------------------------------------
int __cdecl sub_4A30D0(int a1, unsigned int a2, wchar_t* a3, int a4)
{
    _DWORD* v4; // ebp
    __int16* v5; // ebx
    int v6; // eax
    int v7; // eax
    int result; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // eax
    int v12; // eax
    __int16 v13; // ax
    _DWORD* v14; // eax
    int v15; // esi
    wchar_t* v16; // ecx
    wchar_t* v17; // eax
    __int16 v18; // cx
    __int16 v19; // ax
    int v20; // eax
    int v21; // edx
    int v22; // esi
    int v23; // eax
    int v24; // edx
    int v25; // esi
    _DWORD* v26; // eax
    int v27; // ecx
    int v28; // edx
    __int16 v29; // cx
    __int16 v30; // ax
    int v31; // esi
    __int16 v32; // ax
    wchar_t** v33; // esi
    int v34; // edx
    wchar_t* v35; // eax
    int v36; // ecx
    int v37; // esi
    int v38; // ecx
    __int16 v39; // di
    int v40; // eax
    _DWORD* v41; // eax
    int v42; // esi
    int v43; // ecx
    int v44; // eax
    __int16 v45; // ax
    int v46; // edx

    v4 = (_DWORD*)a1;
    v5 = *(__int16**)(a1 + 32);
    if (a2 > 0x4012)
    {
        switch (a2)
        {
        case 0x4013u:
            if ((int)a3 < 0)
            {
                if (*((_DWORD*)v5 + 4))
                    goto LABEL_117;
                *((_DWORD*)v5 + 12) = -1;
                return 0;
            }
            v37 = *((_DWORD*)v5 + 6) + 524 * (_DWORD)a3;
            if (!*(_WORD*)(v37 + 4))
                return 0;
            if (*((_DWORD*)v5 + 4))
            {
                **((_DWORD * *)v5 + 12) = a3;
                *(_DWORD*)(*((_DWORD*)v5 + 12) + 4) = -1;
                return 0;
            }
            v38 = v5[27];
            *((_DWORD*)v5 + 12) = a3;
            if (*(_DWORD*)v37 < v38)
            {
                nox_window_call_field_94(a1, 16412, (int)a3, 0);
                return 0;
            }
            v39 = v5[26];
            if (*(_DWORD*)v37 > v38 + v39)
            {
                if ((int)a3 <= 0)
                    v5[27] = 0;
                else
                    v5[27] = *(_WORD*)v37 - v39;
                sub_4A2D10(a1, 0, 1);
                return 0;
            }
            return 0;
        case 0x4014u:
            return *((_DWORD*)v5 + 12);
        case 0x4015u:
            if ((int)a3 >= 0)
            {
                if (!*(_WORD*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3 + 4) || !*((_DWORD*)v5 + 4))
                    return 0;
                v33 = (wchar_t**) * ((_DWORD*)v5 + 12);
                v34 = 0;
                v35 = *v33;
                if ((int)* v33 < 0)
                {
                LABEL_113:
                    v33[v34] = a3;
                    *(_DWORD*)(*((_DWORD*)v5 + 12) + 4 * v34 + 4) = -1;
                    return 0;
                }
                v36 = *((_DWORD*)v5 + 12);
                while (v35 != a3)
                {
                    v35 = *(wchar_t**)(v36 + 4);
                    v36 += 4;
                    ++v34;
                    if ((int)v35 < 0)
                        goto LABEL_113;
                }
                sub_4A3090(v5, v34);
                result = 0;
            }
            else
            {
                if (!*((_DWORD*)v5 + 4))
                    return 0;
            LABEL_117:
                memset(*((void**)v5 + 12), 0xFFu, 4 * *v5);
                result = 0;
            }
            break;
        case 0x4016u:
            return *((_DWORD*)v5 + 6) + 524 * (_DWORD)a3 + 4;
        case 0x4017u:
            nox_wcsncpy((wchar_t*)(*((_DWORD*)v5 + 6) + 524 * a4 + 4), a3, 0xFFu);
            *(_WORD*)(*((_DWORD*)v5 + 6) + 2 * (nox_wcslen(a3) + 262 * a4) + 4) = 0;
            return 0;
        case 0x4018u:
            *((_DWORD*)v5 + 7) = a3;
            return 0;
        case 0x4019u:
            *((_DWORD*)v5 + 8) = a3;
            return 0;
        case 0x401Au:
            *((_DWORD*)v5 + 9) = a3;
            return 0;
        case 0x401Bu:
            v40 = v5[22];
            if (v40 < (int)a3)
                return 0;
            memmove(
                *((void**)v5 + 6),
                (const void*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3),
                4 * ((unsigned int)(524 * (v40 - (_DWORD)a3)) >> 2));
            v5[22] -= (__int16)a3;
            v5[23] = v5[22];
            if (*((_DWORD*)v5 + 4))
            {
                v41 = (_DWORD*) * ((_DWORD*)v5 + 12);
                v42 = 0;
                if ((int)* v41 >= 0)
                {
                    do
                    {
                        v43 = v41[v42];
                        if ((int)a3 < v43)
                            sub_4A3090(v5, v42--);
                        else
                            v41[v42] = v43 - (_DWORD)a3;
                        v41 = (_DWORD*) * ((_DWORD*)v5 + 12);
                        ++v42;
                    } while ((int)v41[v42] >= 0);
                }
            }
            else
            {
                v44 = *((_DWORD*)v5 + 12);
                if (v44 > 0)
                    * ((_DWORD*)v5 + 12) = v44 - (_DWORD)a3;
            }
            if (v5[27] > 0)
                sub_4A2D10(a1, -(int)a3, 1);
            sub_4A3A70(a1);
            return 1;
        case 0x401Cu:
            if (a3)
                v5[27] = *(_WORD*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3 - 524) + 1;
            else
                v5[27] = 0;
            v45 = v5[26];
            v46 = *((_DWORD*)v5 + 10);
            if (v5[27] + v45 >= v46)
                v5[27] = v46 - v45;
            sub_4A2D10(a1, 0, 1);
            return 0;
        default:
            return 0;
        }
        return result;
    }
    if (a2 == 16402)
    {
        if ((int)a3 >= 0)
        {
            v32 = v5[22];
            if ((int)a3 <= v32)
                v5[23] = (__int16)a3;
            else
                v5[23] = v32;
            result = 0;
        }
        else
        {
            v5[23] = 0;
            result = 0;
        }
        return result;
    }
    if (a2 > 0x4007)
    {
        switch (a2)
        {
        case 0x4009u:
            v29 = v5[26];
            v30 = *(_WORD*)(*(_DWORD*)(*((_DWORD*)v5 + 9) + 32) + 4) - a4;
            v31 = *((_DWORD*)v5 + 10) - v29 + 1;
            v5[27] = v30;
            if (v30 > v31)
                v5[27] = v5[20] - v29 + 1;
            if ((int)v5[27] < 0)
                v5[27] = 0;
            sub_4A2D10(a1, 0, 0);
            return 0;
        case 0x400Du:
            v18 = v5[23];
            v19 = v5[22];
            if (v18 != v19)
            {
                if (v19 < *v5)
                {
                    v20 = v19 - 1;
                    if (v20 < v18)
                    {
                    LABEL_66:
                        sub_4A3AC0(a3, a4, v4);
                        goto LABEL_67;
                    }
                    v21 = 524 * v20;
                    do
                    {
                        --v20;
                        v22 = *((_DWORD*)v5 + 6) + v21;
                        v21 -= 524;
                        qmemcpy((void*)(v22 + 524), (const void*)v22, 0x20Cu);
                    } while (v20 >= v5[23]);
                LABEL_65:
                    v4 = (_DWORD*)a1;
                    goto LABEL_66;
                }
                if (*((_DWORD*)v5 + 2))
                {
                    nox_window_call_field_94(a1, 16411, 1, 0);
                    v23 = v5[22] - 1;
                    if (v23 < v5[23])
                        goto LABEL_66;
                    v24 = 524 * v23;
                    do
                    {
                        --v23;
                        v25 = *((_DWORD*)v5 + 6) + v24;
                        v24 -= 524;
                        qmemcpy((void*)(v25 + 524), (const void*)v25, 0x20Cu);
                    } while (v23 >= v5[23]);
                    goto LABEL_65;
                }
                return 0;
            }
            if (v18 >= *v5)
            {
                if (!*((_DWORD*)v5 + 2))
                    return 0;
                nox_window_call_field_94(a1, 16411, 1, 0);
                sub_4A3AC0(a3, a4, (_DWORD*)a1);
            }
            else
            {
                sub_4A3AC0(a3, a4, (_DWORD*)a1);
            }
        LABEL_67:
            if (*((_DWORD*)v5 + 1))
            {
                while (*(_DWORD*)(*((_DWORD*)v5 + 6) + 524 * v5[23] - 524) >= v5[27] + v5[26])
                    sub_4A2D10((int)v4, 1, 1);
            }
            v26 = (_DWORD*) * ((_DWORD*)v5 + 12);
            if (*((_DWORD*)v5 + 4))
            {
                if ((int)* v26 >= 0)
                {
                    v27 = 0;
                    do
                    {
                        v28 = v26[v27];
                        if (v5[23] < v28)
                            v26[v27] = v28 + 1;
                        v26 = (_DWORD*) * ((_DWORD*)v5 + 12);
                        ++v27;
                    } while ((int)v26[v27] >= 0);
                    return 1;
                }
            }
            else if (v5[23] < (int)v26)
            {
                *((_DWORD*)v5 + 12) = (char*)v26 + 1;
            }
            return 1;
        case 0x400Eu:
            v12 = v5[22];
            if (v12 <= (int)a3)
                return 0;
            qmemcpy(
                (void*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3),
                (const void*)(*((_DWORD*)v5 + 6) + 524 * ((_DWORD)a3 + 1)),
                4 * ((unsigned int)(524 * (v12 - (_DWORD)a3 - 1)) >> 2));
            v13 = --v5[22];
            v5[23] = v13;
            *(_WORD*)(*((_DWORD*)v5 + 6) + 524 * v13 + 4) = 0;
            if (*((_DWORD*)v5 + 4))
            {
                v14 = (_DWORD*) * ((_DWORD*)v5 + 12);
                v15 = 0;
                if ((int)* v14 >= 0)
                {
                    do
                    {
                        v16 = (wchar_t*)v14[v15];
                        if ((int)a3 >= (int)v16)
                        {
                            if (a3 == v16)
                                sub_4A3090(v5, v15--);
                        }
                        else
                        {
                            v14[v15] = (char*)v16 - 1;
                        }
                        v14 = (_DWORD*) * ((_DWORD*)v5 + 12);
                        ++v15;
                    } while ((int)v14[v15] >= 0);
                    sub_4A3A70(a1);
                    return 0;
                }
            }
            else
            {
                v17 = (wchar_t*) * ((_DWORD*)v5 + 12);
                if ((int)a3 < (int)v17)
                {
                    *((_DWORD*)v5 + 12) = (char*)v17 - 1;
                    sub_4A3A70(a1);
                    return 0;
                }
                if (a3 == v17)
                    * ((_DWORD*)v5 + 12) = -1;
            }
            sub_4A3A70(a1);
            return 0;
        case 0x400Fu:
            memset(*((void**)v5 + 6), 0, 524 * *v5);
            if (a3 != (wchar_t*)1)
                v5[27] = 0;
            if (*((_DWORD*)v5 + 4))
                memset(*((void**)v5 + 12), 0xFFu, 4 * *v5);
            else
                *((_DWORD*)v5 + 12) = -1;
            v5[23] = 0;
            v5[22] = 0;
            *((_DWORD*)v5 + 10) = 0;
            sub_4A2D10(a1, 0, 1);
            return 0;
        default:
            return 0;
        }
    }
    if (a2 == 16391)
    {
        if (a3 == *((wchar_t**)v5 + 7))
        {
            if (v5[27] > 0)
            {
                sub_4A2D10(a1, -1, 1);
                return 0;
            }
        }
        else if (a3 == *((wchar_t**)v5 + 8) && v5[26] + v5[27] <= *((_DWORD*)v5 + 10))
        {
            sub_4A2D10(a1, 1, 1);
            return 0;
        }
        return 0;
    }
    if (a2 > 0x4000)
    {
        if (a2 == 16385)
        {
            nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
            *(_WORD*)(a1 + 2 * nox_wcslen(a3) + 108) = 0;
            return 0;
        }
        if (a2 == 16388)
        {
            v9 = (_DWORD*) * ((_DWORD*)v5 + 7);
            if (v9)
                sub_46A9B0(v9, (int)a3 - v9[2], 0);
            v10 = (_DWORD*) * ((_DWORD*)v5 + 8);
            if (v10)
                sub_46A9B0(v10, (int)a3 - v10[2], a4 - v10[3]);
            v11 = (_DWORD*) * ((_DWORD*)v5 + 9);
            if (v11)
            {
                sub_46A9B0(v11, (int)a3 - v11[2], *(_DWORD*)(*((_DWORD*)v5 + 7) + 12));
                sub_46AB20(
                    *((_DWORD * *)v5 + 9),
                    *(_DWORD*)(*((_DWORD*)v5 + 9) + 8),
                    a4 - 2 * *(_DWORD*)(*(_DWORD*)(*((_DWORD*)v5 + 9) + 400) + 12));
            }
            v5[26] = a4;
            if (*(_WORD*)(a1 + 108))
            {
                v5[26] -= sub_43F320(*(_DWORD*)(a1 + 236));
                return 0;
            }
        }
        return 0;
    }
    if (a2 == 0x4000)
    {
        if (a3 == *((wchar_t**)v5 + 7))
        {
            if (v5[27] > 0)
            {
                sub_4A2D10(a1, -1, 1);
                return 0;
            }
        }
        else if (a3 == *((wchar_t**)v5 + 8) && v5[26] + v5[27] <= *((_DWORD*)v5 + 10))
        {
            sub_4A2D10(a1, 1, 1);
            return 0;
        }
        return 0;
    }
    if (a2 != 2)
    {
        if (a2 == 23)
        {
            v6 = *(_DWORD*)(a1 + 36);
            if (a3)
                LOBYTE(v6) = v6 | 2;
            else
                LOBYTE(v6) = v6 & 0xFD;
            *(_DWORD*)(a1 + 36) = v6;
            v7 = sub_46B0A0((int*)a1);
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v7);
            return 1;
        }
        return 0;
    }
    free(*((LPVOID*)v5 + 6));
    if (*((_DWORD*)v5 + 4))
        free(*((LPVOID*)v5 + 12));
    free(v5);
    return 0;
}

//----- (004A3A70) --------------------------------------------------------
int __cdecl sub_4A3A70(int a1)
{
    int v1; // edi
    int v2; // eax
    int v3; // ecx
    int v4; // ebp
    int v5; // esi

    v1 = 0;
    v2 = 0;
    v3 = *(_DWORD*)(a1 + 32);
    if (*(_WORD*)(v3 + 44) > 0)
    {
        v4 = 0;
        do
        {
            v5 = v4 + *(_DWORD*)(v3 + 24);
            ++v1;
            v4 += 524;
            v2 += *(unsigned __int8*)(v5 + 520) + 1;
            *(_DWORD*)v5 = v2;
        } while (v1 < *(__int16*)(v3 + 44));
    }
    *(_DWORD*)(v3 + 40) = v2;
    return sub_4A2D10(a1, 0, 1);
}

//----- (004A3AC0) --------------------------------------------------------
int __cdecl sub_4A3AC0(wchar_t* a1, int a2, _DWORD* a3)
{
    _DWORD* v3; // ebx
    int v4; // esi
    int v5; // ebp
    wchar_t* v6; // edi
    wchar_t* v7; // eax

    v3 = a3;
    v4 = a3[8];
    v5 = a3[2] - 7;
    if (*(_DWORD*)(v4 + 12))
        v5 = a3[2] - 17;
    if (a2 >= 17 || a2 < 0)
        * (_DWORD*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 516) = a3[26];
    else
        *(_DWORD*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 516) = **(_DWORD * *)& byte_5D4594[4 * a2 + 2649836];
    v6 = (wchar_t*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 4);
    if (a1)
    {
        nox_wcsncpy(v6, a1, 0xFFu);
        v6[255] = 0;
        v7 = &v6[nox_wcslen(v6) - 1];
        if (*v7 == 10)
            * v7 = 0;
    }
    else
    {
        *v6 = 32;
        v6[1] = 0;
    }
    if ((v3[1] & 0x4000) == 0x4000)
    {
        *(_BYTE*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 520) = sub_43F320(v3[59]);
    }
    else
    {
        sub_43F840(v3[59], v6, 0, &a3, v5);
        *(_BYTE*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 520) = (_BYTE)a3;
    }
    ++* (_WORD*)(v4 + 46);
    ++* (_WORD*)(v4 + 44);
    return sub_4A3A70((int)v3);
}

//----- (004A3C00) --------------------------------------------------------
void __cdecl sub_4A3C00(int a1, int a2)
{
    if (a1)
    {
        if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
            sub_46B340(a1, sub_4A3C50);
        else
            sub_46B340(a1, sub_4A3FC0);
        if (*(_DWORD*)(a2 + 16))
            sub_46B300(a1, sub_4A2DE0);
        else
            sub_46B300(a1, sub_4A28E0);
    }
}

//----- (004A3C50) --------------------------------------------------------
int __cdecl sub_4A3C50(_DWORD* a1, int a2)
{
    int v2; // ebp
    int v3; // edi
    int v4; // ebx
    int v5; // eax
    int v6; // edi
    int v7; // edx
    int v8; // edi
    int v9; // ebx
    int v10; // eax
    int v11; // ecx
    int v12; // edi
    int* v13; // ecx
    int v14; // eax
    __int16* v15; // edi
    int v16; // ebx
    int v17; // ecx
    int v19; // [esp-4h] [ebp-234h]
    int v20; // [esp+10h] [ebp-220h]
    int v21; // [esp+10h] [ebp-220h]
    int v22; // [esp+14h] [ebp-21Ch]
    int v23; // [esp+18h] [ebp-218h]
    int v24; // [esp+18h] [ebp-218h]
    int yTop; // [esp+1Ch] [ebp-214h]
    int xLeft; // [esp+20h] [ebp-210h]
    int v27; // [esp+24h] [ebp-20Ch]
    int i; // [esp+28h] [ebp-208h]
    int v29; // [esp+2Ch] [ebp-204h]
    __int16 v30[256]; // [esp+30h] [ebp-200h]

    v2 = a1[8];
    v20 = *(_DWORD*)(a2 + 28);
    v23 = *(_DWORD*)(a2 + 20);
    sub_46AA60(a1, &xLeft, &yTop);
    v3 = sub_43F320(*(_DWORD*)(a2 + 200));
    v4 = a1[3];
    v22 = a1[2];
    if ((a1[1] & 0x2000) == 0x2000)
        sub_43F670(1);
    sub_49F7F0();
    if (*(_DWORD*)(v2 + 12))
        v22 -= 10;
    if (*(_WORD*)(a2 + 72))
    {
        sub_434390(*(_DWORD*)(a2 + 68));
        sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(a2 + 72), xLeft + 1, yTop, v22, v3);
        v4 += -1 - v3;
        yTop += v3 + 1;
    }
    if (a1[1] & 8)
    {
        if (*(_BYTE*)a2 & 2)
        {
            v6 = *(_DWORD*)(a2 + 36);
            v5 = v23;
            goto LABEL_13;
        }
        v5 = v23;
    }
    else
    {
        v5 = *(_DWORD*)(a2 + 44);
    }
    v6 = v20;
LABEL_13:
    if (v5 != 0x80000000)
    {
        sub_434460(v5);
        sub_49CE30(xLeft, yTop, v22, v4);
    }
    if (v6 != 0x80000000)
    {
        sub_434460(v6);
        sub_49CC70(xLeft, yTop, v22, v4);
    }
    sub_49F6F0(xLeft, yTop, v22, v4);
    v7 = *(__int16*)(v2 + 54);
    v8 = yTop - v7;
    v21 = yTop - v7;
    if (*(_DWORD*)(a2 + 68) != 0x80000000)
    {
        v9 = 0;
        v24 = 0;
        for (i = 0; ; i = v9)
        {
            if (v9 > 0 && *(_DWORD*)(*(_DWORD*)(v2 + 24) + v9 - 524) > * (__int16*)(v2 + 54) + *(__int16*)(v2 + 52)
                || v24 == *(__int16*)(v2 + 44))
            {
                break;
            }
            v10 = *(_DWORD*)(v2 + 24) + v9;
            if (*(_DWORD*)v10 < *(__int16*)(v2 + 54))
            {
                v21 = v8 + *(unsigned __int8*)(v10 + 520) + 1;
                goto LABEL_38;
            }
            v11 = *(unsigned __int8*)(v10 + 520);
            v19 = *(_DWORD*)(v10 + 516);
            v12 = v11 + 1;
            v27 = v11 + 1;
            sub_434390(v19);
            if (*(_DWORD*)(v2 + 16))
            {
                v13 = *(int**)(v2 + 48);
                v14 = *v13;
                if ((int)* v13 >= 0)
                {
                    while (v24 != v14)
                    {
                        v14 = v13[1];
                        ++v13;
                        if (v14 < 0)
                            goto LABEL_32;
                    }
                LABEL_30:
                    if (*(_DWORD*)(a2 + 52) != 0x80000000)
                    {
                        sub_434460(*(_DWORD*)(a2 + 52));
                        sub_49CE30(xLeft, v21, v22, v12);
                    }
                    goto LABEL_32;
                }
            }
            else if (v24 == *(_DWORD*)(v2 + 48))
            {
                goto LABEL_30;
            }
        LABEL_32:
            sub_434390(*(_DWORD*)(*(_DWORD*)(v2 + 24) + v9 + 516));
            if ((a1[1] & 0x4000) == 0x4000)
            {
                nox_wcscpy((wchar_t*)v30, (const wchar_t*)(*(_DWORD*)(v2 + 24) + v9 + 4));
                v15 = &v30[nox_wcslen((const wchar_t*)v30)];
                v16 = v22 - 7;
                do
                {
                    v17 = *(_DWORD*)(a2 + 200);
                    *v15 = 0;
                    --v15;
                    sub_43F840(v17, (unsigned __int16*)v30, &v29, 0, 0);
                } while (v29 > v16);
                sub_43FAF0(*(_DWORD*)(a2 + 200), v30, xLeft + 5, v21 + 2, v16, v27);
                v9 = i;
                v12 = v27;
            }
            else
            {
                sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(*(_DWORD*)(v2 + 24) + v9 + 4), xLeft + 5, v21 + 2, v22 - 7, v12);
            }
            v21 += v12;
        LABEL_38:
            v8 = v21;
            v9 += 524;
            ++v24;
        }
    }
    sub_49F860();
    sub_43F670(0);
    return 1;
}
// 4A3C50: using guessed type wchar_t var_200[256];

//----- (004A3FC0) --------------------------------------------------------
int __cdecl sub_4A3FC0(_DWORD* a1, int a2)
{
    int v2; // ecx
    int v3; // ebp
    int v4; // esi
    int v5; // eax
    int v6; // eax
    int v7; // edx
    int v8; // eax
    int v9; // esi
    int v10; // ebx
    int v11; // eax
    int v12; // ecx
    int v13; // esi
    int* v14; // ecx
    int v15; // eax
    __int16* v16; // esi
    int v17; // ebx
    int v18; // ecx
    int v20; // [esp-24h] [ebp-254h]
    int v21; // [esp-4h] [ebp-234h]
    int v22; // [esp+10h] [ebp-220h]
    int yTop; // [esp+14h] [ebp-21Ch]
    int xLeft; // [esp+18h] [ebp-218h]
    int v25; // [esp+1Ch] [ebp-214h]
    int v26; // [esp+20h] [ebp-210h]
    int i; // [esp+24h] [ebp-20Ch]
    int v28; // [esp+28h] [ebp-208h]
    int v29; // [esp+2Ch] [ebp-204h]
    __int16 v30[256]; // [esp+30h] [ebp-200h]

    v2 = *(_DWORD*)(a2 + 24);
    v3 = a1[8];
    v28 = *(_DWORD*)(a2 + 28);
    i = v2;
    sub_46AA60(a1, &xLeft, &yTop);
    v4 = a1[3];
    v22 = a1[2];
    if ((a1[1] & 0x2000) == 0x2000)
        sub_43F670(1);
    sub_49F7F0();
    if (*(_DWORD*)(v3 + 12))
        v22 -= 10;
    if (a1[1] & 8)
        v5 = i;
    else
        v5 = *(_DWORD*)(a2 + 48);
    if (v5)
        sub_47D2C0(v5, xLeft, yTop);
    if (*(_WORD*)(a2 + 72))
    {
        sub_434390(*(_DWORD*)(a2 + 68));
        sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(a2 + 72), xLeft + 1, yTop, v22, 0);
        v6 = sub_43F320(*(_DWORD*)(a2 + 200));
        v20 = *(_DWORD*)(a2 + 200);
        yTop += v6 + 1;
        v4 += -1 - sub_43F320(v20);
    }
    if (v28 != 0x80000000)
    {
        sub_434460(v28);
        sub_49CC70(xLeft, yTop, v22, v4);
    }
    sub_49F6F0(xLeft, yTop, v22, v4);
    v7 = *(__int16*)(v3 + 54);
    v8 = *(_DWORD*)(a2 + 68);
    v9 = yTop - v7;
    v25 = yTop - v7;
    if (v8 != 0x80000000)
    {
        v10 = 0;
        v26 = 0;
        for (i = 0; ; i = v10)
        {
            if (v10 > 0 && *(_DWORD*)(*(_DWORD*)(v3 + 24) + v10 - 524) > * (__int16*)(v3 + 54) + *(__int16*)(v3 + 52)
                || v26 == *(__int16*)(v3 + 44))
            {
                break;
            }
            v11 = v10 + *(_DWORD*)(v3 + 24);
            if (*(_DWORD*)v11 < *(__int16*)(v3 + 54))
            {
                v25 = v9 + *(unsigned __int8*)(v11 + 520) + 1;
                goto LABEL_35;
            }
            v12 = *(unsigned __int8*)(v11 + 520);
            v21 = *(_DWORD*)(v11 + 516);
            v13 = v12 + 1;
            v28 = v12 + 1;
            sub_434390(v21);
            if (*(_DWORD*)(v3 + 16))
            {
                v14 = *(int**)(v3 + 48);
                v15 = *v14;
                if ((int)* v14 >= 0)
                {
                    while (v26 != v15)
                    {
                        v15 = v14[1];
                        ++v14;
                        if (v15 < 0)
                            goto LABEL_29;
                    }
                LABEL_27:
                    if (*(_DWORD*)(a2 + 52) != 0x80000000)
                    {
                        sub_434460(*(_DWORD*)(a2 + 52));
                        sub_49CE30(xLeft, v25, v22, v13);
                    }
                    goto LABEL_29;
                }
            }
            else if (v26 == *(_DWORD*)(v3 + 48))
            {
                goto LABEL_27;
            }
        LABEL_29:
            sub_434390(*(_DWORD*)(v10 + *(_DWORD*)(v3 + 24) + 516));
            if ((a1[1] & 0x4000) == 0x4000)
            {
                nox_wcscpy((wchar_t*)v30, (const wchar_t*)(v10 + *(_DWORD*)(v3 + 24) + 4));
                v16 = &v30[nox_wcslen((const wchar_t*)v30)];
                v17 = v22 - 7;
                do
                {
                    v18 = *(_DWORD*)(a2 + 200);
                    *v16 = 0;
                    --v16;
                    sub_43F840(v18, (unsigned __int16*)v30, &v29, 0, 0);
                } while (v29 > v17);
                sub_43FAF0(*(_DWORD*)(a2 + 200), v30, xLeft + 5, v25 + 2, v17, v28);
                v10 = i;
                v13 = v28;
            }
            else
            {
                sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(v10 + *(_DWORD*)(v3 + 24) + 4), xLeft + 5, v25 + 2, v22 - 7, v13);
            }
            v25 += v13;
        LABEL_35:
            v9 = v25;
            v10 += 524;
            ++v26;
        }
    }
    sub_49F860();
    sub_43F670(0);
    return 1;
}
// 4A3FC0: using guessed type wchar_t var_200[256];

//----- (004A4310) --------------------------------------------------------
_DWORD* __cdecl sub_4A4310(int a1, int a2, int a3, int a4, int a5, int a6, int a7, __int16* a8)
{
    _DWORD* v8; // ebp
    void* v9; // edi
    int v10; // edi
    int v11; // ecx
    void* v12; // eax
    int v14; // ecx
    int v15; // eax
    wchar_t* v16; // eax
    int v17; // ebx
    wchar_t* v18; // eax
    int v19; // eax
    __int16* v20; // eax
    int v21; // [esp+10h] [ebp-168h]
    int v22; // [esp+10h] [ebp-168h]
    int v23; // [esp+14h] [ebp-164h]
    int v24[4]; // [esp+1Ch] [ebp-15Ch]
    char v25[332]; // [esp+2Ch] [ebp-14Ch]
    unsigned int v26; // [esp+180h] [ebp+8h]

    v21 = 0;
    if (a8[1] < sub_43F320(*(_DWORD*)(a7 + 200)))
        a8[1] = sub_43F320(*(_DWORD*)(a7 + 200));
    if (*(_WORD*)(a7 + 72))
        v21 = 1;
    if (!(*(_BYTE*)(a7 + 8) & 0x20))
        return 0;
    v8 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A30D0);
    sub_4A3C00((int)v8, (int)a8);
    if (v8)
    {
        if (!*(_DWORD*)(a7 + 16))
            * (_DWORD*)(a7 + 16) = v8;
        sub_46AF80_copy_window_part((int)v8, (const void*)a7);
        v9 = nox_malloc(524 * *a8);
        *((_DWORD*)a8 + 6) = v9;
        if (!v9)
            return 0;
        memset(v9, 0, 524 * *a8);
        v10 = a6;
        a8[26] = a6;
        if (v21)
            a8[26] -= sub_43F320(*(_DWORD*)(a7 + 200));
        v11 = *((_DWORD*)a8 + 4);
        a8[27] = 0;
        *((_DWORD*)a8 + 12) = -1;
        a8[23] = 0;
        a8[22] = 0;
        *((_DWORD*)a8 + 10) = 0;
        if (v11)
        {
            v12 = nox_malloc(4 * *a8);
            *((_DWORD*)a8 + 12) = v12;
            if (!v12)
            {
                free(*((LPVOID*)a8 + 6));
                return 0;
            }
            memset(v12, 0xFFu, 4 * *a8);
            v10 = a6;
        }
        if (*((_DWORD*)a8 + 3))
        {
            v24[0] = 0;
            v14 = *(_DWORD*)(a7 + 200);
            v24[1] = 0;
            v24[2] = 0;
            v24[3] = 0;
            v26 = a2 & 0xFFFFEFEF;
            v15 = sub_43F320(v14);
            if (v21)
            {
                v22 = v15 + 1;
                v10 = v10 - v15 - 1;
            }
            else
            {
                v22 = 0;
            }
            memset(v25, 0, sizeof(v25));
            if ((signed char) * ((_BYTE*)v8 + 4) >= 0)
            {
                *(_DWORD*)& v25[20] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[44] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[28] = *(_DWORD*)& byte_5D4594[2614256];
                *(_DWORD*)& v25[36] = *(_DWORD*)& byte_5D4594[2523948];
                *(_DWORD*)& v25[52] = *(_DWORD*)& byte_5D4594[2589772];
                *(_DWORD*)& v25[68] = *(_DWORD*)& byte_5D4594[2614256];
                v16 = loadString_sub_40F1D0((char*)& byte_587000[169844], 0, "C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c", 1483);
                nox_wcscpy((wchar_t*)& v25[72], v16);
                v23 = 10;
            }
            else
            {
                *(_DWORD*)& v25[24] = sub_42F970("DefaultLBUpButton");
                *(_DWORD*)& v25[40] = sub_42F970("DefaultLBUpButtonLit");
                *(_DWORD*)& v25[48] = sub_42F970("DefaultLBUpButtonDis");
                *(_DWORD*)& v25[56] = sub_42F970("DefaultLBUpButtonLit");
                *(_DWORD*)& v25[32] = 0;
                v23 = 13;
            }
            v17 = v26 | 9;
            *(_DWORD*)& v25[16] = v8;
            *(_DWORD*)& v25[8] = 1;
            *((_DWORD*)a8 + 7) = sub_4A91A0((int)v8, v26 | 9, a5 - 10, v22, 10, v23, v25);
            memset(v25, 0, sizeof(v25));
            if ((signed char) * ((_BYTE*)v8 + 4) >= 0)
            {
                *(_DWORD*)& v25[20] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[44] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[28] = *(_DWORD*)& byte_5D4594[2614256];
                *(_DWORD*)& v25[36] = *(_DWORD*)& byte_5D4594[2523948];
                *(_DWORD*)& v25[52] = *(_DWORD*)& byte_5D4594[2589772];
                *(_DWORD*)& v25[68] = *(_DWORD*)& byte_5D4594[2614256];
                v18 = loadString_sub_40F1D0((char*)& byte_587000[169996], 0, "C:\\NoxPost\\src\\Client\\Gui\\Gadgets\\listbox.c", 1519);
                nox_wcscpy((wchar_t*)& v25[72], v18);
            }
            else
            {
                *(_DWORD*)& v25[24] = sub_42F970("DefaultLBDownButton");
                *(_DWORD*)& v25[40] = sub_42F970("DefaultLBDownButtonLit");
                *(_DWORD*)& v25[48] = sub_42F970("DefaultLBDownButtonDis");
                *(_DWORD*)& v25[56] = sub_42F970("DefaultLBDownButtonLit");
                *(_DWORD*)& v25[32] = 0;
            }
            *(_DWORD*)& v25[8] = 1;
            *(_DWORD*)& v25[16] = v8;
            *((_DWORD*)a8 + 8) = sub_4A91A0((int)v8, v17, a5 - 10, v22 + v10 - v23, 10, v23, v25);
            memset(v25, 0, sizeof(v25));
            if ((signed char) * ((_BYTE*)v8 + 4) >= 0)
            {
                *(_DWORD*)& v25[20] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[44] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[36] = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)& v25[28] = *(_DWORD*)& byte_5D4594[2614256];
                *(_DWORD*)& v25[52] = *(_DWORD*)& byte_5D4594[2614256];
                v19 = 10;
            }
            else
            {
                *(_DWORD*)& v25[24] = sub_42F970("DefaultSliderThumb");
                *(_DWORD*)& v25[40] = sub_42F970("DefaultSliderThumbLit");
                *(_DWORD*)& v25[48] = sub_42F970("DefaultSliderThumbDis");
                *(_DWORD*)& v25[56] = sub_42F970("DefaultSliderThumbLit");
                *(_DWORD*)& v25[32] = 0;
                v19 = 9;
            }
            v24[0] = 0;
            v24[1] = 0;
            v24[2] = 0;
            *(_DWORD*)& v25[8] = 8;
            v24[3] = 0;
            *(_DWORD*)& v25[16] = v8;
            *((_DWORD*)a8 + 9) = sub_4B4EE0((int)v8, v17, a5 - v19, v22 + v23, v19, v10 - 2 * v23, v25, (float*)v24);
        }
        v20 = (__int16*)nox_malloc(0x38u);
        qmemcpy(v20, a8, 0x38u);
        v8[8] = v20;
    }
    return v8;
}

//----- (004A4800) --------------------------------------------------------
int __cdecl sub_4A4800(int a1)
{
    int result; // eax
    _DWORD* v2; // ecx
    int v3; // esi
    int v4; // edi

    result = 0;
    v2 = *(_DWORD * *)(a1 + 24);
    v3 = *(__int16*)(a1 + 54);
    if (*v2 <= v3)
    {
        while (result < *(__int16*)(a1 + 44))
        {
            v4 = v2[131];
            v2 += 131;
            ++result;
            if (v4 > v3)
                return result;
        }
        result = 0;
    }
    return result;
}

//----- (004A4840) --------------------------------------------------------
int sub_4A4840()
{
    int result; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax

    sub_5007E0((char*)& byte_587000[170168]);
    sub_4A1BE0(1);
    *(_DWORD*)& byte_5D4594[1307724] = sub_431770();
    sub_43BDD0(600);
    result = nox_new_window_from_file("SelClass.wnd", sub_4A4A20);
    *(_DWORD*)& byte_5D4594[1307736] = result;
    if (result)
    {
        sub_46B300(result, sub_4A18E0);
        result = sub_43C5B0(*(_DWORD * *)& byte_5D4594[1307736], 0, 0, 0, -460, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[1307732] = result;
        if (result)
        {
            *(_DWORD*)result = 600;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307732] + 48) = sub_4A4970;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307732] + 56) = sub_4A49A0;
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307736], 601);
            sub_46B340((int)v1, sub_4A49D0);
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307736], 603);
            sub_46B340((int)v2, sub_4A49D0);
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307736], 602);
            sub_46B340((int)v3, sub_4A49D0);
            *(_DWORD*)& byte_5D4594[1307728] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307736], 610);
            sub_46A8A0();
            *(_DWORD*)& byte_5D4594[1307740] = 0;
            sub_4A19F0((char*)& byte_587000[170188]);
            sub_4602F0();
            result = 1;
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A4970) --------------------------------------------------------
int sub_4A4970()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307732] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004A49A0) --------------------------------------------------------
int sub_4A49A0()
{
    int (*v0)(void); // esi

    v0 = *(int (**)(void))(*(_DWORD*)& byte_5D4594[1307732] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1307732]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1307736]);
    v0();
    return 1;
}

//----- (004A49D0) --------------------------------------------------------
int __cdecl sub_4A49D0(int yTop, int a2)
{
    _DWORD* v1; // esi
    int xLeft; // [esp+4h] [ebp-4h]

    v1 = (_DWORD*)yTop;
    if (*(_DWORD*)& byte_5D4594[1307740] != *(_DWORD*)yTop)
    {
        sub_46AA60((_DWORD*)yTop, &xLeft, &yTop);
        sub_49CF10(xLeft, yTop, v1[6] - v1[4], v1[7] - v1[5]);
    }
    return 1;
}

//----- (004A4A20) --------------------------------------------------------
int __cdecl sub_4A4A20(int a1, int a2, int* a3, int a4)
{
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // ebx
    _DWORD* v8; // esi
    wchar_t* v9; // eax

    if (a2 != 16389)
    {
        if (a2 != 16391)
            return 0;
        v4 = sub_46B0A0(a3);
        if (v4 >= 601)
        {
            if (v4 <= 603)
                return 1;
            if (v4 == 610)
            {
                if (sub_40A5C0(0x2000) && !sub_40A5C0(4096))
                {
                    if (sub_4D6F50() || (v5 = sub_4D6F70()) != 0)
                        v5 = 1;
                    sub_4A4B70(v5);
                }
                sub_4A4970();
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307732] + 52) = sub_4A5D00;
            }
        }
        sub_452D80(921, 100);
        return 1;
    }
    v6 = sub_46B0A0(a3);
    v7 = v6;
    if (v6 >= 601 && v6 <= 603)
    {
        sub_46ABB0(*(int*)& byte_5D4594[1307728], 1);
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307736], 605);
        *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307724] + 66) = v7 - 89;
        v9 = loadString_sub_40F1D0(
            *(char**)& byte_587000[4 * (unsigned __int8)(v7 - 89) + 170208],
            0,
            "C:\\NoxPost\\src\\client\\shell\\SelClass.c",
            279);
        nox_window_call_field_94((int)v8, 16385, (int)v9, 0);
        *(_DWORD*)& byte_5D4594[1307740] = v7;
    }
    sub_452D80(920, 100);
    return 1;
}

//----- (004A4B70) --------------------------------------------------------
void* __cdecl sub_4A4B70(int a1)
{
    unsigned __int8 v1; // dl
    void* result; // eax
    _BYTE* v3; // edi
    int v4; // esi
    int v5; // ebp
    int v6; // esi
    int v7; // ebp
    bool v8; // zf
    unsigned __int8 v9; // [esp+10h] [ebp-Ch]
    int v10; // [esp+14h] [ebp-8h]
    int v11; // [esp+18h] [ebp-4h]

    v1 = 0;
    result = (void*) * (unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307724] + 66);
    v3 = *(_BYTE * *)& byte_587000[4 * (_DWORD)result + 170156];
    if (*v3)
    {
        do
            result = (void*)++v1;
        while (v3[4 * v1 + v1]);
        if (v1)
        {
            v4 = 0;
            v9 = sub_415FF0(0, v1 - 1, "C:\\NoxPost\\src\\client\\shell\\SelClass.c", 195);
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1307724] + 66))
            {
                v10 = 0;
                v11 = 5;
                do
                {
                    sub_45E110(v10);
                    v6 = 0;
                    v7 = 5;
                    do
                    {
                        if (a1 == 1)
                            sub_45DBE0((void*)2, 0, v6);
                        else
                            sub_45DBE0((void*)2, (unsigned __int8)v3[4 * v9 + v6 + v9], v6);
                        ++v6;
                        --v7;
                    } while (v7);
                    v8 = v11 == 1;
                    ++v10;
                    --v11;
                } while (!v8);
                result = (void*)sub_45E110(0);
            }
            else
            {
                sub_45E110(0);
                v5 = 5;
                do
                {
                    if (a1 == 1)
                        result = sub_45DBE0((void*)3, 0, v4);
                    else
                        result = sub_45DBE0((void*)3, (unsigned __int8)v3[4 * v9 + v4 + v9], v4);
                    ++v4;
                    --v5;
                } while (v5);
            }
        }
    }
    return result;
}

//----- (004A4CB0) --------------------------------------------------------
int __cdecl sub_4A4CB0(const void* a1, const void* a2)
{
    if (*((_WORD*)a1 + 594) != *((_WORD*)a2 + 594))
        return *((unsigned __int16*)a2 + 594) - *((unsigned __int16*)a1 + 594);
    if (*((_WORD*)a1 + 595) != *((_WORD*)a2 + 595))
        return *((unsigned __int16*)a2 + 595) - *((unsigned __int16*)a1 + 595);
    if (*((_WORD*)a1 + 597) != *((_WORD*)a2 + 597))
        return *((unsigned __int16*)a2 + 597) - *((unsigned __int16*)a1 + 597);
    if (*((_WORD*)a1 + 598) != *((_WORD*)a2 + 598))
        return *((unsigned __int16*)a2 + 598) - *((unsigned __int16*)a1 + 598);
    if (*((_WORD*)a1 + 599) != *((_WORD*)a2 + 599))
        return *((unsigned __int16*)a2 + 599) - *((unsigned __int16*)a1 + 599);
    if (*((_WORD*)a1 + 600) != *((_WORD*)a2 + 600))
        return *((unsigned __int16*)a2 + 600) - *((unsigned __int16*)a1 + 600);
    if (*((_WORD*)a1 + 601) == *((_WORD*)a2 + 601))
        return 0;
    return *((unsigned __int16*)a2 + 601) - *((unsigned __int16*)a1 + 601);
}

//----- (004A4DB0) --------------------------------------------------------
int sub_4A4DB0()
{
    int result; // eax
    _DWORD* v1; // esi
    _DWORD* v2; // esi
    _DWORD* v3; // esi
    wchar_t* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // esi
    wchar_t* v8; // eax
    _DWORD* v9; // eax

    sub_477610(0);
    if (sub_4D6F30())
        sub_4D6F90(1);
    sub_43BDD0(500);
    sub_4A1BE0(1);
    result = nox_new_window_from_file("SelChar.wnd", sub_4A5710);
    *(_DWORD*)& byte_5D4594[1307764] = result;
    if (result)
    {
        sub_46B300(result, sub_4A18E0);
        result = sub_43C5B0(*(_DWORD * *)& byte_5D4594[1307764], 0, 0, 0, -440, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[1307748] = result;
        if (result)
        {
            *(_DWORD*)result = 500;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307748] + 48) = sub_4A50A0;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307748] + 56) = sub_4A50D0;
            *(_DWORD*)& byte_5D4594[1307744] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 510);
            *(_DWORD*)& byte_5D4594[1307776] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 511);
            *(_DWORD*)& byte_5D4594[1307768] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 512);
            sub_46B2C0(*(int*)& byte_5D4594[1307744], sub_4A5710);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1307776], *(int*)& byte_5D4594[1307744]);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1307768], *(int*)& byte_5D4594[1307744]);
            if (sub_40A5C0(2048))
            {
                v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 504);
                nox_window_set_hidden((int)v5, 1);
                v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 505);
                nox_window_set_hidden((int)v6, 1);
                v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 509);
                v8 = loadString_sub_40F1D0((char*)& byte_587000[170436], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 746);
                sub_46AEE0((int)v7, (int)v8);
            }
            else
            {
                v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 504);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307744], 16408, (int)v1, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 16408, (int)v1, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 16408, (int)v1, 0);
                v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 505);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307744], 16409, (int)v2, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 16409, (int)v2, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 16409, (int)v2, 0);
                v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 509);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[170380], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 735);
                sub_46AEE0((int)v3, (int)v4);
            }
            sub_4A5150();
            sub_4A19F0((char*)& byte_587000[170448]);
            sub_46A8A0();
            if (sub_40A5C0(0x2000))
                sub_4A5700();
            else
                sub_4A56E0();
            if (sub_40A5C0(0x2000000))
            {
                v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 502);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307764], 16391, (int)v9, 0);
            }
            result = 1;
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A50A0) --------------------------------------------------------
int sub_4A50A0()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307748] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004A50D0) --------------------------------------------------------
int sub_4A50D0()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[1307748] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1307748]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1307764]);
    if (v0)
    {
        v0();
        return 1;
    }
    sub_431510();
    mainloop_draw();
    if (sub_40A5C0(0x2000))
    {
        if (!sub_43AF70())
        {
            sub_43B4D0();
            return 1;
        }
        if (sub_43AF70() == 1)
        {
            sub_43B670();
            return 1;
        }
    }
    else
    {
        sub_4A24A0();
    }
    return 1;
}

//----- (004A5150) --------------------------------------------------------
int sub_4A5150()
{
    size_t v0; // ebp
    _DWORD* v1; // eax
    char* v2; // edi
    int result; // eax
    HANDLE v7; // eax
    void* v8; // esi
    size_t v9; // ebp
    HANDLE v10; // edi
    int v11; // esi
    int v12; // esi
    size_t v13; // ebx
    wchar_t* v14; // eax
    unsigned int v15; // edi
    wchar_t* v16; // eax
    char* v17; // eax
    _DWORD* v18; // eax
    _DWORD* v19; // eax
    _DWORD* v20; // esi
    _DWORD* v21; // eax
    _DWORD* v22; // eax
    _DWORD* v23; // eax
    int v24; // [esp-Ch] [ebp-C18h]
    wchar_t* v25; // [esp-Ch] [ebp-C18h]
    wchar_t* v26; // [esp-8h] [ebp-C14h]
    struct _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-C00h]
    char v28[64]; // [esp+14Ch] [ebp-AC0h]
    wchar_t v29[64]; // [esp+18Ch] [ebp-A80h]
    wchar_t v30[256]; // [esp+20Ch] [ebp-A00h]
    char PathName[1024]; // [esp+40Ch] [ebp-800h]
    char v32[1024]; // [esp+80Ch] [ebp-400h]

    v0 = 0;
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 501);
    sub_46ABB0((int)v1, 1);
    v2 = sub_409E10();
    strcpy(PathName, v2);
    strcat(PathName, "\\Save\\");
    CreateDirectoryA(PathName, 0);
    if (sub_40A5C0(2048))
    {
        *(_DWORD*)& byte_5D4594[1307780] = nox_calloc(0xEu, 0x4FEu);
        result = sub_46CE40(
            *(int*)& byte_5D4594[1307744],
            *(int*)& byte_5D4594[1307776],
            *(int*)& byte_5D4594[1307768],
            *(_BYTE * *)& byte_5D4594[1307780]);
    }
    else
    {
        SetCurrentDirectoryA(PathName);
        strcpy(v32, PathName);
        v7 = FindFirstFileA("*.plr", &FindFileData);
        v8 = v7;
        if (v7 != (HANDLE)-1)
        {
            if (!(FindFileData.dwFileAttributes & 0x10))
                v0 = 1;
            if (FindNextFileA(v7, &FindFileData))
            {
                do
                {
                    if (!(FindFileData.dwFileAttributes & 0x10))
                        ++v0;
                } while (FindNextFileA(v8, &FindFileData));
            }
            FindClose(v8);
        }
        *(_DWORD*)& byte_5D4594[1307780] = nox_calloc(v0, 0x4FEu);
        v9 = 0;
        v10 = FindFirstFileA("*.plr", &FindFileData);
        if (v10 != (HANDLE)-1)
        {
            if (!(FindFileData.dwFileAttributes & 0x10))
            {
                nox_sprintf(PathName, "%s%s", v32, FindFileData.cFileName);
                sub_41A000(PathName, *(_BYTE * *)& byte_5D4594[1307780]);
                if (sub_4A5690(*(_BYTE * *)& byte_5D4594[1307780]) == 1)
                    v9 = 1;
            }
            if (FindNextFileA(v10, &FindFileData))
            {
                v11 = 1278 * v9;
                do
                {
                    if (!(FindFileData.dwFileAttributes & 0x10))
                    {
                        nox_sprintf(PathName, "%s%s", v32, FindFileData.cFileName);
                        sub_41A000(PathName, (_BYTE*)(v11 + *(_DWORD*)& byte_5D4594[1307780]));
                        if (sub_4A5690((_BYTE*)(v11 + *(_DWORD*)& byte_5D4594[1307780])) == 1)
                        {
                            ++v9;
                            v11 += 1278;
                        }
                    }
                } while (FindNextFileA(v10, &FindFileData));
            }
            FindClose(v10);
        }
        qsort(*(void**)& byte_5D4594[1307780], v9, 0x4FEu, sub_4A4CB0);
        if (v9)
        {
            v12 = 0;
            v13 = v9;
            do
            {
                nox_sprintf(
                    v28,
                    "nox.str:%s",
                    *(_DWORD*)& byte_587000[4 * *(unsigned __int8*)(v12 + *(_DWORD*)& byte_5D4594[1307780] + 1274) + 29456]);
                v26 = loadString_sub_40F1D0(v28, 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 285);
                v24 = v12 + *(_DWORD*)& byte_5D4594[1307780] + 1224;
                v14 = loadString_sub_40F1D0((char*)& byte_587000[170600], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 283);
                nox_swprintf(v30, v14, v24, v26);
                if (*(_BYTE*)(v12 + *(_DWORD*)& byte_5D4594[1307780]) & 4)
                {
                    v15 = *(unsigned __int8*)(v12 + *(_DWORD*)& byte_5D4594[1307780] + 1277);
                    if (v15 < 1)
                        v15 = 1;
                    nox_wcscat(v30, L" - ");
                    v16 = loadString_sub_40F1D0((char*)& byte_587000[170680], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 298);
                    nox_wcscat(v30, v16);
                    nox_swprintf(v29, L" %d", v15);
                    nox_wcscat(v30, v29);
                }
                nox_window_call_field_94(*(int*)& byte_5D4594[1307744], 16397, (int)& byte_587000[170708], 14);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 16397, (int)v30, 14);
                if (*(_BYTE*)(v12 + *(_DWORD*)& byte_5D4594[1307780]) & 4)
                    v25 = loadString_sub_40F1D0((char*)& byte_587000[170752], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 316);
                else
                    v25 = loadString_sub_40F1D0((char*)& byte_587000[170812], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 325);
                nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 16397, (int)v25, 14);
                v12 += 1278;
                --v13;
            } while (v13);
        }
        v17 = sub_409E10();
        SetCurrentDirectoryA(v17);
        if (v9)
        {
            v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 503);
            sub_46ABB0((int)v18, 1);
            v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 502);
            sub_46ABB0((int)v19, 1);
            v20 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 501);
            if ((sub_4D6F50() || sub_4D6F70()) && sub_4DC7D0() >= 14)
                sub_46ABB0((int)v20, 0);
            else
                sub_46ABB0((int)v20, 1);
        }
        else
        {
            v21 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 503);
            sub_46ABB0((int)v21, 0);
            v22 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 502);
            sub_46ABB0((int)v22, 0);
            v23 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307764], 501);
            sub_46ABB0((int)v23, 1);
        }
        result = *(_DWORD*)& byte_5D4594[1307776];
        if (*(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1307776] + 32) + 46))
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 16403, 0, 0);
            result = nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 16403, 0, 0);
        }
    }
    return result;
}
// 4A5150: using guessed type CHAR PathName[1024];

//----- (004A5690) --------------------------------------------------------
int __cdecl sub_4A5690(_BYTE* a1)
{
    int result; // eax

    if (!(*a1 & 4))
    {
        if (!sub_4D6F50() && !sub_4D6F70())
            return 1;
        if (!(*a1 & 4))
            goto LABEL_12;
    }
    if (sub_4D6F50() || sub_4D6F70())
        result = 1;
    else
        LABEL_12:
    result = 0;
    return result;
}

//----- (004A56E0) --------------------------------------------------------
void* sub_4A56E0()
{
    int v0; // eax

    v0 = *(_DWORD*)& byte_5D4594[2650636];
    LOBYTE(v0) = byte_5D4594[2650636] & 0xEF;
    *(_DWORD*)& byte_5D4594[2650636] = v0;
    return sub_4602F0();
}

//----- (004A5700) --------------------------------------------------------
int sub_4A5700()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[2650636];
    LOBYTE(result) = byte_5D4594[2650636] | 0x10;
    *(_DWORD*)& byte_5D4594[2650636] = result;
    return result;
}

//----- (004A5710) --------------------------------------------------------
int __cdecl sub_4A5710(int a1, unsigned int a2, int* a3, int a4)
{
    int v5; // eax
    wchar_t* v6; // eax
    int v7; // ebx
    int v8; // eax
    bool v9; // zf
    int v10; // eax
    char* v11; // eax
    char* v12; // eax
    int v13; // eax
    int v14; // eax
    wchar_t* v15; // [esp-18h] [ebp-938h]
    int v16; // [esp-14h] [ebp-934h]
    int (*v17)(); // [esp-10h] [ebp-930h]
    int v18; // [esp-10h] [ebp-930h]
    int v19; // [esp-Ch] [ebp-92Ch]
    char v20[12]; // [esp+4h] [ebp-91Ch]
    char v21[16]; // [esp+10h] [ebp-910h]
    char v22[1024]; // [esp+20h] [ebp-900h]
    char v23[1278]; // [esp+420h] [ebp-500h]

    if (a2 <= 0x4007)
    {
        if (a2 != 16391)
        {
            if (a2 == 2)
            {
                if (sub_46B0A0(a3) == 500)
                {
                    free(*(LPVOID*)& byte_5D4594[1307780]);
                    return 0;
                }
            }
            else if (a2 == 16389)
            {
                sub_452D80(920, 100);
                return 1;
            }
            return 0;
        }
        switch (sub_46B0A0(a3))
        {
        case 501:
            sub_4E3C60(1000000000);
            sub_4A50A0();
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307748] + 52) = sub_4A4840;
            goto LABEL_40;
        case 502:
            v7 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307776] + 32);
            v8 = *(_DWORD*)(v7 + 48);
            if (v8 != -1)
            {
                if (!strlen((const char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * v8 + 4)))
                    goto LABEL_38;
                sub_4DC970((char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * v8 + 4), v20);
                if ((!sub_40A5C0(2048) || sub_4DC100((int)v20, (int)& byte_587000[171268]))
                    && sub_41A000((char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)(v7 + 48) + 4), v23))
                {
                    qmemcpy(&byte_5D4594[2660684], v23, 0x4FCu);
                    *(_WORD*)& byte_5D4594[2661960] = *(_WORD*)& v23[1276];
                    sub_43BDC0();
                    if (byte_5D4594[2661958])
                    {
                        if (byte_5D4594[2661958] == 1)
                        {
                            sub_409D70((char*)& byte_587000[171288]);
                        }
                        else if (byte_5D4594[2661958] == 2)
                        {
                            sub_409D70((char*)& byte_587000[171300]);
                        }
                    }
                    else
                    {
                        sub_409D70((char*)& byte_587000[171276]);
                    }
                    if (sub_40A5C0(2048))
                    {
                        sub_4DB220(1);
                        sub_4DB230(1);
                        nox_sprintf(
                            v21,
                            "%s.map",
                            *(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)(v7 + 48) + 1156);
                        v9 = sub_4DB2A0(v21) == 0;
                        v10 = *(_DWORD*)(v7 + 48);
                        v19 = *(_DWORD*)& byte_5D4594[1307780] + 1278 * v10 + 1156;
                        v18 = *(_DWORD*)& byte_5D4594[1307780] + 1278 * v10 + 1156;
                        if (v9)
                        {
                            v12 = sub_409E10();
                            nox_sprintf(v22, "%s\\Maps\\%s\\%s.map", v12, v18, v19);
                        }
                        else
                        {
                            v11 = sub_409E10();
                            nox_sprintf(v22, "%s\\Save\\%s\\%s\\%s.map", v11, &byte_587000[171320], v18, v19);
                        }
                        sub_4DB270(v22);
                        sub_409D70(v21);
                        sub_4DCC70(1);
                        v13 = sub_41D090((char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)(v7 + 48) + 4));
                        sub_4E3C60(v13);
                    }
                    else if (sub_4D6F30())
                    {
                        sub_4DCE60(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)(v7 + 48) + 1277));
                        sub_4DCE80((const char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)(v7 + 48) + 1156));
                        v14 = sub_41D090((char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)(v7 + 48) + 4));
                        sub_4E3C60(v14);
                    }
                    sub_4A24C0(0);
                    sub_4A50A0();
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307748] + 52) = 0;
                }
            }
            goto LABEL_40;
        case 503:
            v5 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1307776] + 32) + 48);
            if (v5 == -1)
                goto LABEL_40;
            *(_DWORD*)& byte_5D4594[1307772] = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1307776] + 32) + 48);
            sub_4DC970((char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * v5 + 4), (char*)& byte_5D4594[1307752]);
            if (sub_40A5C0(2048) && !strcmp((const char*)& byte_5D4594[1307752], "AUTOSAVE"))
            {
                sub_452D80(925, 100);
                v17 = 0;
                v16 = 33;
                v15 = loadString_sub_40F1D0((char*)& byte_587000[170876], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 466);
                v6 = loadString_sub_40F1D0((char*)& byte_587000[170952], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 465);
            }
            else
            {
                if (!strlen((const char*)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)& byte_5D4594[1307772] + 4)))
                {
                LABEL_38:
                    sub_452D80(925, 100);
                    goto LABEL_40;
                }
                v17 = sub_4A5C70;
                v16 = 56;
                if (sub_40A5C0(2048))
                {
                    v15 = loadString_sub_40F1D0((char*)& byte_587000[171024], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 480);
                    v6 = loadString_sub_40F1D0((char*)& byte_587000[171092], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 479);
                }
                else
                {
                    v15 = loadString_sub_40F1D0((char*)& byte_587000[171160], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 488);
                    v6 = loadString_sub_40F1D0((char*)& byte_587000[171236], 0, "C:\\NoxPost\\src\\client\\shell\\selchar.c", 487);
                }
            }
            sub_449A10(0, (int)v6, (int)v15, v16, v17, 0);
        LABEL_40:
            sub_452D80(921, 100);
            return 1;
        case 504:
        case 505:
            nox_window_call_field_94(*(int*)& byte_5D4594[1307744], 0x4000, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 0x4000, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 0x4000, (int)a3, 0);
            goto LABEL_40;
        default:
            goto LABEL_40;
        }
    }
    if (a2 == 16400)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[1307744], 16403, a4, 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 16403, a4, 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 16403, a4, 0);
    }
    return 0;
}

//----- (004A5C70) --------------------------------------------------------
int sub_4A5C70()
{
    if (sub_40A5C0(2048))
        sub_4DBE10((int)& byte_5D4594[1307752], 1);
    else
        DeleteFileA((LPCSTR)(*(_DWORD*)& byte_5D4594[1307780] + 1278 * *(_DWORD*)& byte_5D4594[1307772] + 4));
    nox_window_call_field_94(*(int*)& byte_5D4594[1307744], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1307776], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1307768], 16399, 0, 0);
    return sub_4A5150();
}

//----- (004A5D00) --------------------------------------------------------
int sub_4A5D00()
{
    char* v0; // eax
    int result; // eax
    int i; // esi
    _DWORD* v3; // eax
    int j; // esi
    _DWORD* v5; // edi
    wchar_t* v6; // eax
    _DWORD* v7; // eax

    sub_43BDD0(700);
    v0 = sub_431770();
    *(_DWORD*)& byte_5D4594[1307784] = v0;
    v0[67] = 0;
    result = nox_new_window_from_file("SelColor.wnd", sub_4A7330);
    *(_DWORD*)& byte_5D4594[1308084] = result;
    if (result)
    {
        sub_46B300(result, sub_4A18E0);
        result = sub_43C5B0(*(_DWORD * *)& byte_5D4594[1308084], 0, 0, 0, -440, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[1308092] = result;
        if (result)
        {
            *(_DWORD*)result = 700;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308092] + 48) = sub_4A6890;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308092] + 56) = sub_4A6C90;
            sub_4A5E90();
            for (i = 720; i <= 729; ++i)
            {
                v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], i);
                sub_46B340((int)v3, sub_4A6D20);
            }
            for (j = 761; j <= 792; ++j)
            {
                v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], j);
                sub_46B340((int)v5, sub_4A6D20);
            }
            if (*(_DWORD*)& byte_587000[171388])
            {
                v6 = loadString_sub_40F1D0((char*)& byte_587000[171448], 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 1138);
                nox_window_call_field_94(*(int*)& byte_5D4594[1308152], 16414, (int)v6, 0);
            }
            sub_46A8A0();
            *(_DWORD*)& byte_5D4594[1308088] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 760);
            sub_46B2C0(*(int*)& byte_5D4594[1308088], sub_4A7330);
            sub_46B300(*(int*)& byte_5D4594[1308088], sub_4A7270);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1308088], 0);
            sub_4BFAD0();
            v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 740);
            sub_46B340((int)v7, sub_4A6DC0);
            result = 1;
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A5E90) --------------------------------------------------------
int sub_4A5E90()
{
    const char** i; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    int result; // eax

    if (*(_DWORD*)& byte_587000[171384])
        sub_4A62B0();
    for (i = (const char**)sub_413390(); i; i = (const char**)sub_4133A0((int)i))
    {
        if (!strcmp(*i, "StreetPants"))
        {
            *(_DWORD*)& byte_5D4594[1308156] = i;
        }
        else if (!strcmp(*i, "StreetShirt"))
        {
            *(_DWORD*)& byte_5D4594[1308160] = i;
        }
        else if (!strcmp(*i, "StreetSneakers"))
        {
            *(_DWORD*)& byte_5D4594[1308164] = i;
        }
    }
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 720);
    *(_DWORD*)& byte_5D4594[1308096] = v1;
    v1[8] = 131074;
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 721);
    *(_DWORD*)& byte_5D4594[1308100] = v2;
    v2[8] = 589825;
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 722);
    *(_DWORD*)& byte_5D4594[1308104] = v3;
    v3[8] = 589825;
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 723);
    *(_DWORD*)& byte_5D4594[1308108] = v4;
    v4[8] = 589825;
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 724);
    *(_DWORD*)& byte_5D4594[1308112] = v5;
    v5[8] = 589825;
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 725);
    *(_DWORD*)& byte_5D4594[1308116] = v6;
    v6[8] = *(unsigned __int16*)& byte_587000[171372] << 16;
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 726);
    *(_DWORD*)& byte_5D4594[1308120] = v7;
    v7[8] = *(unsigned __int16*)& byte_587000[171374] << 16;
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 727);
    *(_DWORD*)& byte_5D4594[1308124] = v8;
    v8[8] = *(unsigned __int16*)& byte_587000[171376] << 16;
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 728);
    *(_DWORD*)& byte_5D4594[1308128] = v9;
    v9[8] = *(unsigned __int16*)& byte_587000[171378] << 16;
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 729);
    *(_DWORD*)& byte_5D4594[1308132] = v10;
    v10[8] = *(unsigned __int16*)& byte_587000[171380] << 16;
    *(_DWORD*)& byte_5D4594[1308136] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 711);
    *(_DWORD*)& byte_5D4594[1308140] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 712);
    *(_DWORD*)& byte_5D4594[1308144] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 713);
    *(_DWORD*)& byte_5D4594[1308148] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 714);
    *(_DWORD*)& byte_5D4594[1308152] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], 751);
    result = *(_DWORD*)& byte_587000[171388];
    if (!*(_DWORD*)& byte_587000[171388])
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[1308152], 16414, *(int*)& byte_5D4594[1307784], 0);
        sub_4A61E0(*(_DWORD * *)& byte_5D4594[1308096], 2, (_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 71));
        sub_4A61E0(*(_DWORD * *)& byte_5D4594[1308100], 1, (_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 68));
        sub_4A61E0(*(_DWORD * *)& byte_5D4594[1308104], 1, (_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 74));
        sub_4A61E0(*(_DWORD * *)& byte_5D4594[1308108], 1, (_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 77));
        sub_4A61E0(*(_DWORD * *)& byte_5D4594[1308112], 1, (_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 80));
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308116] + 32) = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 83) << 16;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308120] + 32) = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 84) << 16;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308124] + 32) = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 85) << 16;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308128] + 32) = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 86) << 16;
        result = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 87) << 16;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308132] + 32) = result;
    }
    return result;
}

//----- (004A61E0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4A61E0(_DWORD* a1, int a2, unsigned __int8* a3)
{
    unsigned int v3; // esi
    unsigned __int8* result; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax

    v3 = 0;
    result = &byte_5D4594[96 * a2 + 1307797];
    while (*(result - 1) != *a3 || *result != a3[1] || result[1] != a3[2])
    {
        ++v3;
        result += 3;
        if (v3 >= 0x20)
            goto LABEL_9;
    }
    if (a2 == 1)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], *a1 - 10);
        sub_46ABB0((int)v5, 1);
        result = (unsigned __int8*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], *a1 + 10);
        *((_DWORD*)result + 9) |= 6u;
    }
LABEL_9:
    if (v3 == 32 && a2 == 1)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], *a1 - 10);
        result = (unsigned __int8*)sub_46ABB0((int)v6, 0);
        LOWORD(v3) = 9;
    }
    a1[8] = (unsigned __int16)a2 | ((unsigned __int16)v3 << 16);
    return result;
}

//----- (004A62B0) --------------------------------------------------------
char sub_4A62B0()
{
    unsigned __int8* v0; // esi
    int v1; // eax
    int v3; // ebp
    char result; // al
    unsigned __int8* v5; // [esp+10h] [ebp-18h]
    int v6; // [esp+14h] [ebp-14h]
    char v7[16]; // [esp+18h] [ebp-10h]

    v0 = &byte_5D4594[1307796];
    v1 = 0;
    v5 = &byte_5D4594[1307796];
    do
    {
        *v0 = 0;
        v6 = v1 + 1;
        v0[1] = 0;
        v0[2] = 0;
        nox_sprintf(v7, "UserColor%d", v1 + 1);
        obj_412ae0_t* v2 = sub_4133B0(2);
        if (v2)
        {
            while (strcmp(v7, v2->field_0))
            {
                v2 = sub_4133C0(v2);
                if (!v2)
                    goto LABEL_7;
            }
            v3 = (int)(&v2->field_6);
            *(_WORD*)v5 = *(_WORD*)v3;
            v5[2] = *(_BYTE*)(v3 + 2);
        LABEL_7:
            v0 = v5;
        }
        v1 = v6;
        v0 += 3;
        v5 = v0;
    } while ((int)v0 < (int)& byte_5D4594[1307892]);
    byte_5D4594[1307989] = -34;
    byte_5D4594[1307991] = -34;
    byte_5D4594[1307995] = -102;
    byte_5D4594[1308000] = -102;
    byte_5D4594[1308038] = -102;
    byte_5D4594[1307988] = -23;
    byte_5D4594[1307990] = -51;
    byte_5D4594[1307992] = -74;
    byte_5D4594[1307993] = -88;
    byte_5D4594[1307994] = -38;
    byte_5D4594[1307996] = 110;
    byte_5D4594[1307997] = -20;
    byte_5D4594[1307998] = -54;
    byte_5D4594[1307999] = -78;
    byte_5D4594[1308001] = -125;
    byte_5D4594[1308002] = 105;
    byte_5D4594[1308003] = 117;
    byte_5D4594[1308004] = 95;
    byte_5D4594[1308005] = 74;
    byte_5D4594[1308006] = -17;
    byte_5D4594[1308007] = -23;
    byte_5D4594[1308008] = -63;
    byte_5D4594[1308009] = -28;
    byte_5D4594[1308010] = -28;
    byte_5D4594[1308011] = -63;
    byte_5D4594[1308012] = -53;
    byte_5D4594[1308013] = -71;
    byte_5D4594[1308014] = -100;
    byte_5D4594[1308015] = -56;
    byte_5D4594[1308016] = -92;
    byte_5D4594[1308017] = 110;
    byte_5D4594[1308018] = -87;
    byte_5D4594[1308019] = -125;
    byte_5D4594[1308020] = 79;
    byte_5D4594[1308021] = -13;
    byte_5D4594[1308022] = -98;
    byte_5D4594[1308023] = 119;
    byte_5D4594[1308024] = 115;
    byte_5D4594[1308025] = 77;
    byte_5D4594[1308026] = 34;
    byte_5D4594[1308027] = 91;
    byte_5D4594[1308028] = 55;
    byte_5D4594[1308029] = 20;
    byte_5D4594[1308030] = -7;
    byte_5D4594[1308031] = -51;
    byte_5D4594[1308032] = -118;
    byte_5D4594[1308033] = -16;
    byte_5D4594[1308034] = -21;
    byte_5D4594[1308035] = -85;
    byte_5D4594[1308036] = -122;
    byte_5D4594[1308037] = -113;
    byte_5D4594[1308039] = -121;
    byte_5D4594[1308040] = 102;
    byte_5D4594[1308041] = 67;
    byte_5D4594[1308042] = 115;
    byte_5D4594[1308043] = 80;
    byte_5D4594[1308044] = 46;
    byte_5D4594[1308045] = -91;
    byte_5D4594[1308046] = 93;
    byte_5D4594[1308047] = 70;
    byte_5D4594[1308048] = 99;
    byte_5D4594[1308049] = 65;
    byte_5D4594[1308050] = 37;
    byte_5D4594[1308051] = 83;
    byte_5D4594[1308052] = 52;
    byte_5D4594[1308053] = 29;
    byte_5D4594[1308054] = -88;
    byte_5D4594[1308055] = 127;
    byte_5D4594[1308056] = 84;
    byte_5D4594[1308057] = -85;
    byte_5D4594[1308058] = -96;
    byte_5D4594[1308059] = 96;
    byte_5D4594[1308060] = -115;
    byte_5D4594[1308061] = -120;
    byte_5D4594[1308062] = 118;
    byte_5D4594[1308063] = 127;
    byte_5D4594[1308065] = 82;
    byte_5D4594[1308064] = 116;
    byte_5D4594[1308080] = 116;
    byte_5D4594[1308082] = 116;
    byte_5D4594[1307898] = -1;
    byte_5D4594[1307904] = -1;
    byte_5D4594[1308066] = 96;
    byte_5D4594[1307908] = 68;
    byte_5D4594[1307909] = 68;
    byte_5D4594[1307926] = 68;
    byte_5D4594[1307936] = 68;
    byte_5D4594[1308067] = 84;
    byte_5D4594[1307937] = -42;
    byte_5D4594[1307938] = -42;
    byte_5D4594[1307939] = -42;
    byte_5D4594[1308068] = 51;
    byte_5D4594[1308069] = -94;
    byte_5D4594[1308070] = -127;
    byte_5D4594[1308071] = 100;
    byte_5D4594[1308072] = 78;
    byte_5D4594[1308073] = 64;
    byte_5D4594[1308074] = 46;
    byte_5D4594[1308075] = 65;
    byte_5D4594[1308076] = 50;
    byte_5D4594[1308077] = 45;
    byte_5D4594[1308078] = -85;
    byte_5D4594[1308079] = -98;
    byte_5D4594[1308081] = -81;
    byte_5D4594[1308083] = -125;
    byte_5D4594[1307892] = -13;
    byte_5D4594[1307893] = -73;
    byte_5D4594[1307894] = -97;
    byte_5D4594[1307895] = -57;
    byte_5D4594[1307896] = -124;
    byte_5D4594[1307897] = 58;
    byte_5D4594[1307899] = -86;
    byte_5D4594[1307900] = 86;
    byte_5D4594[1307901] = -110;
    byte_5D4594[1307902] = 121;
    byte_5D4594[1307903] = 106;
    byte_5D4594[1307905] = -5;
    byte_5D4594[1307906] = -70;
    byte_5D4594[1307907] = -9;
    byte_5D4594[1307910] = 63;
    byte_5D4594[1307911] = -69;
    byte_5D4594[1307912] = -17;
    byte_5D4594[1307913] = -60;
    byte_5D4594[1307914] = -62;
    byte_5D4594[1307915] = -79;
    byte_5D4594[1307916] = -3;
    byte_5D4594[1307917] = -10;
    byte_5D4594[1307918] = 102;
    byte_5D4594[1307919] = 115;
    byte_5D4594[1307920] = 77;
    byte_5D4594[1307921] = 34;
    byte_5D4594[1307922] = -27;
    byte_5D4594[1307923] = 121;
    byte_5D4594[1307924] = 25;
    byte_5D4594[1307925] = 82;
    byte_5D4594[1307927] = 60;
    byte_5D4594[1307928] = -21;
    byte_5D4594[1307929] = -27;
    byte_5D4594[1307930] = -119;
    byte_5D4594[1307931] = -109;
    byte_5D4594[1307932] = 0;
    byte_5D4594[1307933] = 0;
    byte_5D4594[1307934] = 0;
    byte_5D4594[1307935] = 37;
    byte_5D4594[1307940] = -107;
    byte_5D4594[1307941] = 108;
    byte_5D4594[1307942] = 43;
    byte_5D4594[1307943] = 52;
    byte_5D4594[1307944] = 25;
    byte_5D4594[1307945] = 0;
    byte_5D4594[1307946] = -106;
    byte_5D4594[1307947] = 55;
    byte_5D4594[1307952] = -106;
    byte_5D4594[1307955] = -125;
    byte_5D4594[1307956] = 104;
    byte_5D4594[1307961] = 117;
    byte_5D4594[1307962] = 117;
    byte_5D4594[1307963] = 117;
    byte_5D4594[1307981] = 104;
    result = 53;
    byte_5D4594[1307948] = 0;
    byte_5D4594[1307950] = 0;
    byte_5D4594[1307984] = 0;
    *(_DWORD*)& byte_587000[171384] = 0;
    byte_5D4594[1307949] = 9;
    byte_5D4594[1307951] = 12;
    byte_5D4594[1307953] = -110;
    byte_5D4594[1307954] = 81;
    byte_5D4594[1307957] = -77;
    byte_5D4594[1307958] = 121;
    byte_5D4594[1307959] = -91;
    byte_5D4594[1307960] = 66;
    byte_5D4594[1307964] = 100;
    byte_5D4594[1307965] = -126;
    byte_5D4594[1307966] = 125;
    byte_5D4594[1307967] = 56;
    byte_5D4594[1307968] = 48;
    byte_5D4594[1307969] = 40;
    byte_5D4594[1307970] = 108;
    byte_5D4594[1307971] = 81;
    byte_5D4594[1307972] = 58;
    byte_5D4594[1307973] = 52;
    byte_5D4594[1307974] = 40;
    byte_5D4594[1307975] = 39;
    byte_5D4594[1307976] = -113;
    byte_5D4594[1307977] = -114;
    byte_5D4594[1307978] = 124;
    byte_5D4594[1307979] = 56;
    byte_5D4594[1307980] = 29;
    byte_5D4594[1307982] = 15;
    byte_5D4594[1307983] = 88;
    byte_5D4594[1307985] = 87;
    byte_5D4594[1307986] = 53;
    byte_5D4594[1307987] = 53;
    return result;
}

//----- (004A6890) --------------------------------------------------------
int sub_4A6890()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1308092] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    sub_4A68C0();
    return 1;
}

//----- (004A68C0) --------------------------------------------------------
wchar_t* sub_4A68C0()
{
    wchar_t* v0; // esi
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    unsigned __int8* v3; // edx
    int v4; // eax
    int v5; // ecx
    int v6; // eax
    unsigned __int8* v7; // eax
    int v8; // ecx
    int v9; // ecx
    int v10; // eax
    int v11; // ecx
    unsigned __int8* v12; // eax
    int v13; // ecx
    int v14; // eax
    int v15; // ecx
    unsigned __int8* v16; // eax
    int v17; // edx
    int v18; // eax
    int v19; // ecx
    unsigned __int8* v20; // eax
    wchar_t* result; // eax

    v0 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1308152], 16413, 0, 0);
    if (!*v0)
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[171552], 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 225);
        nox_wcscpy(v0, v1);
    }
    nox_wcscpy(*(wchar_t**)& byte_5D4594[1307784], v0);
    if (!sub_4A6B50(*(wchar_t**)& byte_5D4594[1307784]))
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[171604], 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 232);
        nox_wcscpy(*(wchar_t**)& byte_5D4594[1307784], v2);
    }
    v3 = &byte_5D4594[3
        * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308096] + 32) >> 16)
            + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308096] + 32))
        + 1307796];
    v4 = *(_DWORD*)& byte_5D4594[1307784] + 71;
    *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 71) = *(_WORD*)v3;
    *(_BYTE*)(v4 + 2) = v3[2];
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308136] + 4) & 8)
    {
        v7 = &byte_5D4594[3
            * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308100] + 32) >> 16)
                + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308100] + 32))
            + 1307796];
        v8 = *(_DWORD*)& byte_5D4594[1307784] + 68;
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 68) = *(_WORD*)v7;
        *(_BYTE*)(v8 + 2) = v7[2];
    }
    else
    {
        v5 = *(_DWORD*)& byte_5D4594[1307784] + 71;
        v6 = *(_DWORD*)& byte_5D4594[1307784] + 68;
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 68) = *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 71);
        *(_BYTE*)(v6 + 2) = *(_BYTE*)(v5 + 2);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308140] + 4) & 8)
    {
        v11 = *(_DWORD*)& byte_5D4594[1307784] + 74;
        v12 = &byte_5D4594[3
            * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308104] + 32) >> 16)
                + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308104] + 32))
            + 1307796];
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 74) = *(_WORD*)v12;
        *(_BYTE*)(v11 + 2) = v12[2];
    }
    else
    {
        v9 = *(_DWORD*)& byte_5D4594[1307784] + 71;
        v10 = *(_DWORD*)& byte_5D4594[1307784] + 74;
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 74) = *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 71);
        *(_BYTE*)(v10 + 2) = *(_BYTE*)(v9 + 2);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308144] + 4) & 8)
    {
        v15 = *(_DWORD*)& byte_5D4594[1307784] + 77;
        v16 = &byte_5D4594[3
            * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308108] + 32) >> 16)
                + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308108] + 32))
            + 1307796];
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 77) = *(_WORD*)v16;
        *(_BYTE*)(v15 + 2) = v16[2];
    }
    else
    {
        v13 = *(_DWORD*)& byte_5D4594[1307784] + 71;
        v14 = *(_DWORD*)& byte_5D4594[1307784] + 77;
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 77) = *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 71);
        *(_BYTE*)(v14 + 2) = *(_BYTE*)(v13 + 2);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308148] + 4) & 8)
    {
        v19 = *(_DWORD*)& byte_5D4594[1307784] + 80;
        v20 = &byte_5D4594[3
            * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308112] + 32) >> 16)
                + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308112] + 32))
            + 1307796];
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 80) = *(_WORD*)v20;
        *(_BYTE*)(v19 + 2) = v20[2];
    }
    else
    {
        v17 = *(_DWORD*)& byte_5D4594[1307784] + 71;
        v18 = *(_DWORD*)& byte_5D4594[1307784] + 80;
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 80) = *(_WORD*)(*(_DWORD*)& byte_5D4594[1307784] + 71);
        *(_BYTE*)(v18 + 2) = *(_BYTE*)(v17 + 2);
    }
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 83) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308116] + 32) >> 16;
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 84) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308120] + 32) >> 16;
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 85) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308124] + 32) >> 16;
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 86) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308128] + 32) >> 16;
    result = *(wchar_t**)& byte_5D4594[1307784];
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 87) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308132] + 32) >> 16;
    return result;
}

//----- (004A6B50) --------------------------------------------------------
int __cdecl sub_4A6B50(wchar_t* a1)
{
    wchar_t* v1; // esi
    int v2; // ebp
    int v3; // ebx
    signed int v4; // eax
    __int16* v5; // edi
    wchar_t v6; // ax
    signed int v7; // esi
    WCHAR* i; // edi
    int v10; // [esp+10h] [ebp-3Ch]
    signed int v11; // [esp+14h] [ebp-38h]
    __int16 v12[26]; // [esp+18h] [ebp-34h]

    v1 = a1;
    v2 = 0;
    v3 = 1;
    v10 = 0;
    v4 = nox_wcslen(a1);
    if (v4 >= 1)
    {
        v5 = v12;
        v11 = v4;
        do
        {
            if (iswspace(*v1))
            {
                if (!v3)
                {
                    *v5 = *v1;
                    ++v5;
                    ++v10;
                }
            }
            else
            {
                if (v3 == 1)
                {
                    v6 = *v1;
                    if (*v1 == 42
                        || v6 == 63
                        || v6 == 60
                        || v6 == 62
                        || v6 == 92
                        || v6 == 47
                        || v6 == 58
                        || v6 == 34
                        || v6 == 124)
                    {
                        *v1 = 45;
                    }
                }
                *v5 = *v1;
                ++v5;
                ++v10;
                v3 = 0;
                v2 = 1;
            }
            ++v1;
            --v11;
        } while (v11);
        v12[v10] = 0;
        if (v2)
        {
            nox_wcscpy(a1, (const wchar_t*)v12);
            v7 = nox_wcslen((const wchar_t*)v12) - 1;
            if ((int)v7 >= 0)
            {
                for (i = &a1[v7]; iswspace(*i); --i)
                {
                    if (--v7 < 0)
                        return v2;
                }
                a1[v7 + 1] = 0;
            }
        }
    }
    return v2;
}
// 4A6B50: using guessed type wchar_t var_34[26];

//----- (004A6C90) --------------------------------------------------------
int sub_4A6C90()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[1308092] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1308092]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1308084]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1308088]);
    if (v0)
    {
        v0();
    }
    else
    {
        sub_431510();
        mainloop_draw();
        if (!sub_40A5C0(0x2000))
        {
            sub_4A24A0();
            return 1;
        }
        if (!sub_43AF70())
        {
            sub_43B4D0();
            return 1;
        }
        if (sub_43AF70() == 1)
        {
            sub_43B670();
            return 1;
        }
    }
    return 1;
}

//----- (004A6D20) --------------------------------------------------------
int __cdecl sub_4A6D20(int a1, int a2)
{
    int v1; // esi
    unsigned __int16 v2; // di
    int v3; // ebx
    int v4; // ecx
    int v5; // edx
    int v6; // edi
    int v7; // ebp
    int v8; // eax
    int v10; // [esp-10h] [ebp-28h]
    int yTop; // [esp+10h] [ebp-8h]
    int xLeft; // [esp+14h] [ebp-4h]
    int v13; // [esp+1Ch] [ebp+4h]

    v1 = a1;
    v2 = *(_WORD*)(a1 + 32);
    v3 = *(_DWORD*)(a1 + 32) >> 16;
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    v4 = *(_DWORD*)(a1 + 20);
    v5 = *(_DWORD*)(a1 + 16);
    v6 = (unsigned __int16)v3 + 32 * v2;
    v13 = *(_DWORD*)(a1 + 28) - v4;
    v7 = *(_DWORD*)(v1 + 24) - v5;
    LOBYTE(v5) = byte_5D4594[3 * v6 + 1307798];
    LOBYTE(v4) = byte_5D4594[3 * v6 + 1307797];
    v10 = v5;
    LOBYTE(v5) = byte_5D4594[3 * v6 + 1307796];
    v8 = sub_4344A0(v5, v4, v10);
    sub_434460(v8);
    sub_49CE30(xLeft, yTop, v7, v13);
    return 1;
}

//----- (004A6DC0) --------------------------------------------------------
int __cdecl sub_4A6DC0(_DWORD* a1, int a2)
{
    int v1; // eax
    int v2; // ecx
    int v3; // edx
    int v4; // esi
    int v5; // eax
    int v6; // ecx
    int v7; // edx
    int v8; // eax
    int v9; // edx
    int v10; // eax
    int v11; // ecx
    int v12; // eax
    int v13; // edx
    int v14; // ecx
    int v15; // eax
    int v16; // eax
    int v17; // edx
    int v18; // ecx
    int v19; // eax
    int v20; // eax
    int v21; // ebx
    int v22; // eax
    int v23; // edx
    int* v24; // ebp
    int v25; // ecx
    int v26; // eax
    int v27; // edi
    int i; // esi
    int v29; // eax
    int v30; // eax
    int v31; // ecx
    int v32; // eax
    int v33; // edi
    int j; // esi
    int v35; // eax
    int v36; // eax
    int v37; // ecx
    int v38; // eax
    int v39; // eax
    int v40; // ecx
    int v41; // edx
    int v42; // edi
    int k; // esi
    int v44; // eax
    int v45; // eax
    int v46; // ecx
    int v47; // eax
    int v48; // eax
    int v49; // ecx
    int v50; // edx
    int v52; // [esp-24h] [ebp-3Ch]
    int v53; // [esp-24h] [ebp-3Ch]
    int v54; // [esp+10h] [ebp-8h]
    int v55; // [esp+14h] [ebp-4h]

    sub_46AA60(a1, &v54, &v55);
    v1 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308096] + 32) >> 16))
        + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308096] + 32);
    v2 = byte_5D4594[3 * v1 + 1307798];
    LOBYTE(v3) = byte_5D4594[3 * v1 + 1307797];
    LOBYTE(v1) = byte_5D4594[3 * v1 + 1307796];
    v4 = sub_4344A0(v1, v3, v2);
    sub_4341D0(6, v4);
    v5 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308100] + 32) >> 16))
        + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308100] + 32);
    v6 = byte_5D4594[3 * v5 + 1307798];
    LOBYTE(v7) = byte_5D4594[3 * v5 + 1307797];
    LOBYTE(v5) = byte_5D4594[3 * v5 + 1307796];
    v8 = sub_4344A0(v5, v7, v6);
    sub_4341D0(1, v8);
    v9 = *(_DWORD*)& byte_5D4594[1308144];
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308144] + 4) & 8)
    {
        v10 = (unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308108] + 32) >> 16);
        v11 = v10 + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308108] + 32);
        LOBYTE(v9) = byte_5D4594[3 * v11 + 1307797];
        v12 = sub_4344A0(
            byte_5D4594[3 * v11 + 1307796],
            v9,
            byte_5D4594[3 * (v10 + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308108] + 32)) + 1307798]);
        sub_4341D0(2, v12);
    }
    else
    {
        sub_4341D0(2, v4);
    }
    sub_4341D0(3, v4);
    v13 = *(_DWORD*)& byte_5D4594[1308148];
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308148] + 4) & 8)
    {
        v14 = (unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308112] + 32) >> 16);
        v15 = v14 + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308112] + 32);
        LOBYTE(v13) = byte_5D4594[3 * v15 + 1307797];
        LOBYTE(v15) = byte_5D4594[3 * v15 + 1307796];
        v16 = sub_4344A0(
            v15,
            v13,
            byte_5D4594[3 * (v14 + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308112] + 32)) + 1307798]);
        sub_4341D0(4, v16);
    }
    else
    {
        sub_4341D0(4, v4);
    }
    v17 = *(_DWORD*)& byte_5D4594[1308140];
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308140] + 4) & 8)
    {
        v18 = (unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308104] + 32) >> 16);
        v19 = v18 + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308104] + 32);
        LOBYTE(v17) = byte_5D4594[3 * v19 + 1307797];
        LOBYTE(v19) = byte_5D4594[3 * v19 + 1307796];
        v20 = sub_4344A0(
            v19,
            v17,
            byte_5D4594[3 * (v18 + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308104] + 32)) + 1307798]);
        sub_4341D0(5, v20);
    }
    else
    {
        sub_4341D0(5, v4);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308136] + 4) & 8)
        sub_47D2C0(
            *(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 67) + 3798172],
            v54,
            v55);
    else
        sub_47D2C0(
            *(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 67) + 3798180],
            v54,
            v55);
    v21 = 0;
    v22 = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1307784] + 67);
    v23 = 3 * v22;
    v24 = (int*)& byte_5D4594[104 * v22 + 3798188];
    do
    {
        v25 = v21;
        v26 = 1 << v21;
        if (1 << v21 == 4)
        {
            v27 = 1;
            for (i = 3; i < 21; i += 3)
            {
                v29 = *(_DWORD*)& byte_5D4594[1308156];
                LOBYTE(v25) = *(_BYTE*)(i + *(_DWORD*)& byte_5D4594[1308156] + 14);
                LOBYTE(v23) = *(_BYTE*)(i + *(_DWORD*)& byte_5D4594[1308156] + 13);
                LOBYTE(v29) = *(_BYTE*)(i + *(_DWORD*)& byte_5D4594[1308156] + 12);
                sub_4340A0(v27++, v29, v23, v25);
            }
            v30 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308116] + 32) >> 16))
                + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308116] + 32);
            v31 = byte_5D4594[3 * v30 + 1307798];
            LOBYTE(v23) = byte_5D4594[3 * v30 + 1307797];
            LOBYTE(v30) = byte_5D4594[3 * v30 + 1307796];
            v32 = sub_4344A0(v30, v23, v31);
            sub_4341D0(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308156] + 40), v32);
        }
        else if (v26 == 1024)
        {
            v33 = 1;
            for (j = 3; j < 21; j += 3)
            {
                v35 = *(_DWORD*)& byte_5D4594[1308160];
                LOBYTE(v25) = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1308160] + j + 14);
                LOBYTE(v23) = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1308160] + j + 13);
                LOBYTE(v35) = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1308160] + j + 12);
                sub_4340A0(v33++, v35, v23, v25);
            }
            v36 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308120] + 32) >> 16))
                + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308120] + 32);
            v37 = byte_5D4594[3 * v36 + 1307798];
            LOBYTE(v23) = byte_5D4594[3 * v36 + 1307797];
            LOBYTE(v36) = byte_5D4594[3 * v36 + 1307796];
            v38 = sub_4344A0(v36, v23, v37);
            sub_4341D0(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308160] + 40), v38);
            v39 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308124] + 32) >> 16))
                + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308124] + 32);
            v40 = byte_5D4594[3 * v39 + 1307798];
            LOBYTE(v41) = byte_5D4594[3 * v39 + 1307797];
            LOBYTE(v39) = byte_5D4594[3 * v39 + 1307796];
            v52 = sub_4344A0(v39, v41, v40);
            sub_4341D0(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308160] + 44), v52);
        }
        else
        {
            if (v26 != 1)
                goto LABEL_27;
            v42 = 1;
            for (k = 3; k < 21; k += 3)
            {
                v44 = *(_DWORD*)& byte_5D4594[1308164];
                LOBYTE(v25) = *(_BYTE*)(k + *(_DWORD*)& byte_5D4594[1308164] + 14);
                LOBYTE(v23) = *(_BYTE*)(k + *(_DWORD*)& byte_5D4594[1308164] + 13);
                LOBYTE(v44) = *(_BYTE*)(k + *(_DWORD*)& byte_5D4594[1308164] + 12);
                sub_4340A0(v42++, v44, v23, v25);
            }
            v45 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308128] + 32) >> 16))
                + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308128] + 32);
            v46 = byte_5D4594[3 * v45 + 1307798];
            LOBYTE(v23) = byte_5D4594[3 * v45 + 1307797];
            LOBYTE(v45) = byte_5D4594[3 * v45 + 1307796];
            v47 = sub_4344A0(v45, v23, v46);
            sub_4341D0(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308164] + 40), v47);
            v48 = ((unsigned __int16)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308132] + 32) >> 16))
                + 32 * *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[1308132] + 32);
            v49 = byte_5D4594[3 * v48 + 1307798];
            LOBYTE(v50) = byte_5D4594[3 * v48 + 1307797];
            LOBYTE(v48) = byte_5D4594[3 * v48 + 1307796];
            v53 = sub_4344A0(v48, v50, v49);
            sub_4341D0(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308164] + 36), v53);
        }
        sub_47D2C0(*v24, v54, v55);
    LABEL_27:
        ++v21;
        ++v24;
    } while (v21 < 26);
    return 1;
}
// 4A6E13: variable 'v3' is possibly undefined
// 4A6E5A: variable 'v7' is possibly undefined
// 4A7032: variable 'v23' is possibly undefined
// 4A7032: variable 'v25' is possibly undefined
// 4A7158: variable 'v41' is possibly undefined
// 4A7227: variable 'v50' is possibly undefined

//----- (004A7270) --------------------------------------------------------
int __cdecl sub_4A7270(int a1, int a2, unsigned int a3, int a4)
{
    int v3; // eax
    int2 v5; // [esp+0h] [ebp-8h]

    if (a2 != 5)
        return 0;
    v5.field_4 = a3 >> 16;
    v5.field_0 = (unsigned __int16)a3;
    v3 = sub_4281F0(&v5, (int4*)(a1 + 16));
    if (v3)
        return 0;
    sub_4A72D0(0xDEADu);
    return 1;
}
// 4A72AA: variable 'v3' is possibly undefined

//----- (004A72D0) --------------------------------------------------------
_DWORD* __cdecl sub_4A72D0(unsigned __int16 a1)
{
    _DWORD* result; // eax

    sub_46C6E0(*(int*)& byte_5D4594[1308088]);
    result = (_DWORD*)nox_window_set_hidden(*(int*)& byte_5D4594[1308088], 1);
    if (a1 < 0x20u)
    {
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308088], *(int*)& byte_5D4594[1307792]);
        if (result)
            result[8] = *(unsigned __int16*)& byte_5D4594[1307788] | (a1 << 16);
    }
    return result;
}

//----- (004A7330) --------------------------------------------------------
int __cdecl sub_4A7330(int a1, int a2, int* a3, unsigned int a4)
{
    int result; // eax
    int v5; // edi
    int v6; // eax
    _DWORD* v7; // eax

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        result = 1;
    }
    else if (a2 == 16391)
    {
        v5 = a4 >> 16;
        v6 = sub_46B0A0(a3);
        switch (v6)
        {
        case 720:
            *(_DWORD*)& byte_5D4594[1307792] = v6;
            sub_4A7530(2u);
            sub_4A7580((unsigned __int16)a4, v5);
            break;
        case 721:
        case 722:
        case 723:
        case 724:
            *(_DWORD*)& byte_5D4594[1307792] = v6;
            sub_4A7530(1u);
            sub_4A7580((unsigned __int16)a4, v5);
            break;
        case 725:
        case 726:
        case 727:
        case 728:
        case 729:
            *(_DWORD*)& byte_5D4594[1307792] = v6;
            sub_4A7530(0);
            sub_4A7580((unsigned __int16)a4, v5);
            break;
        case 731:
        case 732:
        case 733:
        case 734:
            v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308084], v6 - 20);
            if (v7)
                sub_46ABB0((int)v7, ((unsigned int)~v7[1] >> 3) & 1);
            break;
        case 761:
        case 762:
        case 763:
        case 764:
        case 765:
        case 766:
        case 767:
        case 768:
        case 769:
        case 770:
        case 771:
        case 772:
        case 773:
        case 774:
        case 775:
        case 776:
        case 777:
        case 778:
        case 779:
        case 780:
        case 781:
        case 782:
        case 783:
        case 784:
        case 785:
        case 786:
        case 787:
        case 788:
        case 789:
        case 790:
        case 791:
        case 792:
            sub_4A72D0(v6 - 761);
            break;
        case 799:
            if (*(_DWORD*)& byte_5D4594[1308168] == 1)
                sub_43BDC0();
            sub_43BDC0();
            sub_43BDC0();
            *(_DWORD*)& byte_587000[171388] = 1;
            if (sub_4A75C0())
            {
                if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 66))
                {
                    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 66) == 1)
                    {
                        sub_409D70((char*)& byte_587000[171628]);
                    }
                    else if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 66) == 2)
                    {
                        sub_409D70((char*)& byte_587000[171640]);
                    }
                }
                else
                {
                    sub_409D70((char*)& byte_587000[171616]);
                }
                sub_4A24C0(0);
                sub_4A6890();
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308092] + 52) = 0;
            }
            break;
        default:
            break;
        }
        sub_452D80(921, 100);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004A7530) --------------------------------------------------------
_DWORD* __cdecl sub_4A7530(unsigned __int16 a1)
{
    int v1; // esi
    _DWORD* result; // eax

    v1 = 761;
    *(_DWORD*)& byte_5D4594[1307788] = a1;
    do
    {
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1308088], v1);
        if (result)
            result[8] = a1 | ((unsigned __int16)(v1 - 761) << 16);
        ++v1;
    } while (v1 <= 792);
    return result;
}

//----- (004A7580) --------------------------------------------------------
int __cdecl sub_4A7580(int a1, int a2)
{
    sub_46A8C0(*(int*)& byte_5D4594[1308088]);
    sub_46C690(*(int*)& byte_5D4594[1308088]);
    return sub_46A9B0(
        *(_DWORD * *)& byte_5D4594[1308088],
        a1 - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308088] + 8),
        a2 - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308088] + 12) / 2);
}

//----- (004A75C0) --------------------------------------------------------
int sub_4A75C0()
{
    wchar_t* v0; // esi
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    char v3; // dl
    unsigned __int8* v4; // edx
    __int16 v5; // si
    __int16 v6; // cx
    unsigned __int8 v7; // dl
    int v8; // ecx
    char v9; // dl
    unsigned __int8* v10; // eax
    int v11; // eax
    unsigned __int8* v12; // ecx
    char* v13; // edi
    __int16 v14; // dx
    unsigned __int8 v15; // al
    char* v16; // edi
    int v17; // edx
    char* v18; // edi
    int i; // esi
    FILE* v20; // eax
    char* v21; // eax
    char v23; // [esp+2h] [ebp-512h]
    char v24[16]; // [esp+4h] [ebp-510h]
    char v25[1278]; // [esp+14h] [ebp-500h]

    if (sub_40A5C0(2048))
        sub_4DBE10((int)& byte_587000[171652], 0);
    memset(v25, 0, 0x4FCu);
    *(_WORD*)& v25[1276] = 0;
    v0 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1308152], 16413, 0, 0);
    if (!*v0)
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[171700], 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 605);
        nox_wcscpy(v0, v1);
    }
    nox_wcscpy((wchar_t*)& v25[1224], v0);
    if (!sub_4A6B50((wchar_t*)& v25[1224]))
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[171752], 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 612);
        nox_wcscpy((wchar_t*)& v25[1224], v2);
    }
    v3 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307784] + 66);
    v25[1276] = 1;
    v25[1274] = v3;
    v4 = &byte_5D4594[3
        * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308096] + 32) >> 16)
            + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308096] + 32))
        + 1307796];
    *(_WORD*)& v25[1204] = *(_WORD*)v4;
    v5 = *(_WORD*)v4;
    v25[1206] = v4[2];
    v23 = v4[2];
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308136] + 4) & 8)
    {
        v8 = (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308100] + 32) >> 16)
            + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308100] + 32);
        *(_WORD*)& v25[1207] = *(_WORD*)& byte_5D4594[3 * v8 + 1307796];
        v7 = byte_5D4594[3 * v8 + 1307798];
    }
    else
    {
        v6 = *(_WORD*)v4;
        v7 = v4[2];
        *(_WORD*)& v25[1207] = v6;
    }
    v25[1209] = v7;
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308140] + 4) & 8)
    {
        v10 = &byte_5D4594[3
            * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308104] + 32) >> 16)
                + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308104] + 32))
            + 1307796];
        *(_WORD*)& v25[1210] = *(_WORD*)v10;
        v25[1212] = v10[2];
        v9 = v23;
    }
    else
    {
        v9 = v23;
        *(_WORD*)& v25[1210] = v5;
        v25[1212] = v23;
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308144] + 4) & 8)
    {
        v11 = (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308108] + 32) >> 16)
            + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308108] + 32);
        *(_WORD*)& v25[1213] = *(_WORD*)& byte_5D4594[3 * v11 + 1307796];
        v25[1215] = byte_5D4594[3 * v11 + 1307798];
    }
    else
    {
        *(_WORD*)& v25[1213] = v5;
        v25[1215] = v9;
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1308148] + 4) & 8)
    {
        v12 = &byte_5D4594[3
            * ((*(_DWORD*)(*(_DWORD*)& byte_5D4594[1308112] + 32) >> 16)
                + 32 * (unsigned __int16) * (_DWORD*)(*(_DWORD*)& byte_5D4594[1308112] + 32))
            + 1307796];
        *(_WORD*)& v25[1216] = *(_WORD*)v12;
        v25[1218] = v12[2];
    }
    else
    {
        *(_WORD*)& v25[1216] = v5;
        v25[1218] = v9;
    }
    v25[1219] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308116] + 32) >> 16;
    v25[1220] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308120] + 32) >> 16;
    v25[1221] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308124] + 32) >> 16;
    v25[1222] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308128] + 32) >> 16;
    v25[1223] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1308132] + 32) >> 16;
    v13 = sub_409E10();
    v14 = *(_WORD*)& byte_587000[171768];
    strcpy(&v25[4], v13);
    v15 = byte_587000[171770];
    v16 = &v25[strlen(&v25[4]) + 4];
    *(_DWORD*)v16 = *(_DWORD*)& byte_587000[171764];
    *((_WORD*)v16 + 2) = v14;
    v16[6] = v15;
    if (sub_40A5C0(2048))
    {
        v17 = *(_DWORD*)& byte_587000[171776];
        v18 = &v25[strlen(&v25[4]) + 4];
        *(_DWORD*)v18 = *(_DWORD*)& byte_587000[171772];
        *((_DWORD*)v18 + 1) = v17;
        *(_WORD*)& v25[strlen(&v25[4]) + 4] = *(_WORD*)& byte_587000[171780];
    }
    CreateDirectoryA(&v25[4], 0);
    SetCurrentDirectoryA(&v25[4]);
    i = 0;
    if (sub_40A5C0(2048))
    {
        strcpy(v24, "Player.plr");
    }
    else
    {
        for (i = 0; i < 100; ++i)
        {
            nox_sprintf(v24, "%.6s%2.2d.plr", &v25[1224], i);
            v20 = fopen(v24, "rb");
            if (!v20)
                break;
            fclose(v20);
        }
    }
    v21 = sub_409E10();
    SetCurrentDirectoryA(v21);
    if (i > 99)
        return 0;
    strcat(&v25[4], v24);
    if (sub_40A5C0(2048))
    {
        if (v25[1274])
        {
            if (v25[1274] == 1)
            {
                sub_409D70((char*)& byte_587000[171828]);
            }
            else if (v25[1274] == 2)
            {
                sub_409D70((char*)& byte_587000[171840]);
            }
        }
        else
        {
            sub_409D70((char*)& byte_587000[171816]);
        }
    }
    return sub_41CEE0((int)v25, 1);
}

//----- (004A7A60) --------------------------------------------------------
int __cdecl sub_4A7A60(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[171388] = a1;
    return result;
}

//----- (004A7A70) --------------------------------------------------------
int __cdecl sub_4A7A70(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1308168] = a1;
    return result;
}

//----- (004A7A80) --------------------------------------------------------
int __cdecl sub_4A7A80(const char* a1)
{
    int result; // eax
    unsigned int v2; // ecx
    char v3; // al
    unsigned __int8* v4; // edi
    const char* v5; // esi

    if (!a1)
        return 0;
    v2 = strlen(a1) + 1;
    v3 = v2;
    v2 >>= 2;
    qmemcpy(&byte_5D4594[1308644], a1, 4 * v2);
    v5 = &a1[4 * v2];
    v4 = &byte_5D4594[4 * v2 + 1308644];
    LOBYTE(v2) = v3;
    result = 1;
    qmemcpy(v4, v5, v2 & 3);
    return result;
}

//----- (004A7AC0) --------------------------------------------------------
int __cdecl sub_4A7AC0(const char* a1)
{
    int result; // eax
    unsigned int v2; // ecx
    char v3; // al
    unsigned __int8* v4; // edi
    const char* v5; // esi

    if (!a1)
        return 0;
    v2 = strlen(a1) + 1;
    v3 = v2;
    v2 >>= 2;
    qmemcpy(&byte_5D4594[1308172], a1, 4 * v2);
    v5 = &a1[4 * v2];
    v4 = &byte_5D4594[4 * v2 + 1308172];
    LOBYTE(v2) = v3;
    result = 1;
    qmemcpy(v4, v5, v2 & 3);
    return result;
}

//----- (004A7B00) --------------------------------------------------------
int __cdecl sub_4A7B00(const char* a1)
{
    int result; // eax
    unsigned int v2; // ecx
    char v3; // al
    unsigned __int8* v4; // edi
    const char* v5; // esi

    if (!a1)
        return 0;
    v2 = strlen(a1) + 1;
    v3 = v2;
    v2 >>= 2;
    qmemcpy(&byte_5D4594[1308352], a1, 4 * v2);
    v5 = &a1[4 * v2];
    v4 = &byte_5D4594[4 * v2 + 1308352];
    LOBYTE(v2) = v3;
    result = 1;
    qmemcpy(v4, v5, v2 & 3);
    return result;
}

//----- (004A7B40) --------------------------------------------------------
int __cdecl sub_4A7B40(char* a1)
{
    const char* v2; // eax
    int v3; // edi
    unsigned __int8* v4; // esi

    if (!a1)
        return 0;
    v2 = *(const char**)& byte_587000[171856];
    v3 = 0;
    if (*(_DWORD*)& byte_587000[171856])
    {
        v4 = &byte_587000[171856];
        while (_strcmpi(v2, a1))
        {
            v2 = (const char*) * ((_DWORD*)v4 + 2);
            v4 += 8;
            ++v3;
            if (!v2)
                return 1;
        }
        *(_DWORD*)& byte_5D4594[1308184] = *(_DWORD*)& byte_587000[8 * v3 + 171860];
    }
    return 1;
}

//----- (004A7BA0) --------------------------------------------------------
int __cdecl sub_4A7BA0(char* a1)
{
    int result; // eax

    result = (int)a1;
    if (a1)
    {
        *(_DWORD*)& byte_5D4594[1308740] = atoi(a1);
        result = 1;
    }
    return result;
}

//----- (004A7BC0) --------------------------------------------------------
int __cdecl sub_4A7BC0(const char* a1)
{
    int result; // eax
    unsigned int v2; // ecx
    char v3; // al
    unsigned __int8* v4; // edi
    const char* v5; // esi

    if (!a1)
        return 0;
    v2 = strlen(a1) + 1;
    v3 = v2;
    v2 >>= 2;
    qmemcpy(&byte_5D4594[1308324], a1, 4 * v2);
    v5 = &a1[4 * v2];
    v4 = &byte_5D4594[4 * v2 + 1308324];
    LOBYTE(v2) = v3;
    result = 1;
    qmemcpy(v4, v5, v2 & 3);
    return result;
}

//----- (004A7C00) --------------------------------------------------------
int __cdecl sub_4A7C00(const char* a1)
{
    int result; // eax
    unsigned int v2; // ecx
    char v3; // al
    unsigned __int8* v4; // edi
    const char* v5; // esi

    if (!a1)
        return 0;
    v2 = strlen(a1) + 1;
    v3 = v2;
    v2 >>= 2;
    qmemcpy(&byte_5D4594[1308364], a1, 4 * v2);
    v5 = &a1[4 * v2];
    v4 = &byte_5D4594[4 * v2 + 1308364];
    LOBYTE(v2) = v3;
    result = 1;
    qmemcpy(v4, v5, v2 & 3);
    return result;
}

//----- (004A7C40) --------------------------------------------------------
int __cdecl sub_4A7C40(char* a1)
{
    int result; // eax

    result = (int)a1;
    if (a1)
    {
        *(_DWORD*)& byte_5D4594[1308188] = atoi(a1);
        result = 1;
    }
    return result;
}

//----- (004A7C60) --------------------------------------------------------
int __cdecl sub_4A7C60(char* a1)
{
    char* v1; // eax
    char* v2; // eax
    int result; // eax

    if (!a1)
        goto LABEL_12;
    *(_DWORD*)& byte_5D4594[1308736] = 0;
    *(_DWORD*)& byte_5D4594[1308732] = 0;
    v1 = strtok(a1, ",\t\r\n");
    if (v1)
        * (_DWORD*)& byte_5D4594[1308732] = atoi(v1);
    v2 = strtok(0, " \t\r\n");
    if (v2)
        * (_DWORD*)& byte_5D4594[1308736] = atoi(v2);
    if (*(_DWORD*)& byte_5D4594[1308732] && *(_DWORD*)& byte_5D4594[1308736])
        result = 1;
    else
        LABEL_12:
    result = 0;
    return result;
}

//----- (004A7CE0) --------------------------------------------------------
int __cdecl sub_4A7CE0(char* a1)
{
    int result; // eax

    result = (int)a1;
    if (a1)
    {
        *(_DWORD*)& byte_5D4594[1308728] = atoi(a1);
        result = 1;
    }
    return result;
}

//----- (004A7D00) --------------------------------------------------------
int __cdecl sub_4A7D00(const char* a1)
{
    int result; // eax
    unsigned int v2; // ecx
    char v3; // al
    unsigned __int8* v4; // edi
    const char* v5; // esi

    if (!a1)
        return 0;
    result = 0;
    if (strlen(a1) <= 0x80)
    {
        v2 = strlen(a1) + 1;
        v3 = v2;
        v2 >>= 2;
        qmemcpy(&byte_5D4594[1308192], a1, 4 * v2);
        v5 = &a1[4 * v2];
        v4 = &byte_5D4594[4 * v2 + 1308192];
        LOBYTE(v2) = v3;
        result = 1;
        qmemcpy(v4, v5, v2 & 3);
    }
    return result;
}

//----- (004A7D50) --------------------------------------------------------
int __cdecl sub_4A7D50(char* a1)
{
    int result; // eax

    result = (int)a1;
    if (a1)
    {
        *(_DWORD*)& byte_5D4594[1308348] = atoi(a1);
        result = 1;
    }
    return result;
}

//----- (004A7D70) --------------------------------------------------------
int __cdecl sub_4A7D70(char* a1)
{
    int result; // eax
    FILE* v2; // eax
    FILE* v3; // esi

    result = (int)a1;
    if (a1)
    {
        v2 = fopen(a1, "r");
        v3 = v2;
        if (!v2)
            return 0;
        fgets((char*)& byte_5D4594[1308388], 256, v2);
        if (!feof(v3))
        {
            while (sub_4A7DF0((char*)& byte_5D4594[1308388]))
            {
                fgets((char*)& byte_5D4594[1308388], 256, v3);
                if (feof(v3))
                    break;
            }
            return 0;
        }
        fclose(v3);
        result = 1;
    }
    return result;
}

//----- (004A7DF0) --------------------------------------------------------
int __cdecl sub_4A7DF0(char* a1)
{
    char* v1; // ebx
    int v2; // edi
    const char* v3; // esi
    char* v5; // eax

    v1 = strtok(a1, " \t\r\n");
    if (!v1)
        return 0;
    v2 = 0;
    v3 = "MAP";
    while (_strcmpi(v1, v3) || !strtok(0, " \t\r\n"))
    {
        v3 += 20;
        ++v2;
        if ((int)v3 >= (int)& byte_587000[172172])
            return 0;
    }
    v5 = strtok(0, "\t\r\n");
    (*(void(__cdecl * *)(const char*)) & byte_587000[20 * v2 + 171928])(v5);
    return 1;
}

//----- (004A7E70) --------------------------------------------------------
char* sub_4A7E70()
{
    return (char*)& byte_5D4594[1308644];
}

//----- (004A7E80) --------------------------------------------------------
char* sub_4A7E80()
{
    return (char*)& byte_5D4594[1308172];
}

//----- (004A7E90) --------------------------------------------------------
char* sub_4A7E90()
{
    return (char*)& byte_5D4594[1308352];
}

//----- (004A7EA0) --------------------------------------------------------
int sub_4A7EA0()
{
    return *(_DWORD*)& byte_5D4594[1308184];
}

//----- (004A7EB0) --------------------------------------------------------
int sub_4A7EB0()
{
    return *(_DWORD*)& byte_5D4594[1308740];
}

//----- (004A7EC0) --------------------------------------------------------
char* sub_4A7EC0()
{
    return (char*)& byte_5D4594[1308324];
}

//----- (004A7ED0) --------------------------------------------------------
char* sub_4A7ED0()
{
    return (char*)& byte_5D4594[1308364];
}

//----- (004A7EE0) --------------------------------------------------------
int sub_4A7EE0()
{
    return *(_DWORD*)& byte_5D4594[1308188];
}

//----- (004A7EF0) --------------------------------------------------------
char* sub_4A7EF0()
{
    return (char*)& byte_5D4594[1308732];
}

//----- (004A7F00) --------------------------------------------------------
int sub_4A7F00()
{
    return *(_DWORD*)& byte_5D4594[1308728];
}

//----- (004A7F10) --------------------------------------------------------
char* sub_4A7F10()
{
    return (char*)& byte_5D4594[1308192];
}

//----- (004A7F20) --------------------------------------------------------
int sub_4A7F20()
{
    return *(_DWORD*)& byte_5D4594[1308348];
}

//----- (004A7F30) --------------------------------------------------------
int sub_4A7F30()
{
    return *(_DWORD*)& byte_5D4594[1308744];
}

//----- (004A7F40) --------------------------------------------------------
int __cdecl sub_4A7F40(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1308744] = a1;
    return result;
}

//----- (004A7F50) --------------------------------------------------------
int __cdecl sub_4A7F50(_DWORD* a1, int a2, int a3, int a4)
{
    int v4; // eax
    int v5; // eax
    int result; // eax
    int v7; // eax
    int v8; // eax
    int v9; // eax
    _DWORD* v10; // esi
    int v11; // eax
    int v12; // [esp-10h] [ebp-14h]

    switch (a2)
    {
    case 5:
    LABEL_9:
        a1[9] |= 4u;
        return 1;
    case 6:
    case 7:
        v10 = a1;
        if (!(a1[9] & 4))
            goto LABEL_22;
        nox_window_call_field_94(a1[13], 16391, (int)a1, a3);
        goto LABEL_16;
    case 8:
        nox_window_call_field_94(a1[13], 0x4000, (int)a1, a3);
        return 1;
    case 17:
        v4 = a1[11];
        if (!(v4 & 0x100))
            goto LABEL_21;
        v5 = a1[13];
        a1[9] |= 2u;
        nox_window_call_field_94(v5, 16389, (int)a1, a3);
        sub_46B500((int)a1);
        result = 1;
        break;
    case 18:
        v7 = a1[11];
        if (v7 & 0x100)
        {
            v8 = a1[9];
            LOBYTE(v8) = v8 & 0xFD;
            v12 = a1[13];
            a1[9] = v8;
            nox_window_call_field_94(v12, 16390, (int)a1, a3);
        }
        v9 = a1[9];
        if (v9 & 4)
        {
            LOBYTE(v9) = v9 & 0xFB;
            a1[9] = v9;
            result = 1;
        }
        else
        {
        LABEL_21:
            result = 1;
        }
        break;
    case 21:
        switch (a3)
        {
        case 15:
        case 205:
        case 208:
            if (a4 != 2)
                goto LABEL_21;
            sub_46A8A0();
            return 1;
        case 28:
        case 57:
            if (a4 != 1)
                goto LABEL_9;
            v10 = a1;
            if (!(a1[9] & 4))
                goto LABEL_21;
            nox_window_call_field_94(a1[13], 16391, (int)a1, 0);
            break;
        case 200:
        case 203:
            if (a4 == 2)
                sub_46A8B0();
            goto LABEL_21;
        default:
            goto LABEL_22;
        }
    LABEL_16:
        v11 = v10[9];
        LOBYTE(v11) = v11 & 0xFB;
        v10[9] = v11;
        result = 1;
        break;
    default:
    LABEL_22:
        result = 0;
        break;
    }
    return result;
}

//----- (004A81D0) --------------------------------------------------------
int __cdecl sub_4A81D0(int a1, int a2)
{
    int v2; // esi
    int v3; // ebx
    int v4; // edi
    int v5; // edi
    int v6; // ebx
    int v7; // eax
    int v9; // [esp-8h] [ebp-20h]
    int xLeft; // [esp+10h] [ebp-8h]
    int yTop; // [esp+14h] [ebp-4h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 28);
    v4 = *(_DWORD*)(a2 + 20);
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if (*(_BYTE*)(a1 + 4) & 8)
    {
        if (*(_DWORD*)v2 & 4)
        {
            v4 = *(_DWORD*)(v2 + 52);
        }
        else if (*(_DWORD*)v2 & 2)
        {
            v3 = *(_DWORD*)(v2 + 36);
        }
    }
    else
    {
        v4 = *(_DWORD*)(v2 + 44);
    }
    if (v3 != 0x80000000)
    {
        sub_434460(v3);
        sub_49CC70(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    if (v4 != 0x80000000)
    {
        sub_434460(v4);
        sub_49CE30(xLeft + 1, yTop + 1, *(_DWORD*)(a1 + 8) - 2, *(_DWORD*)(a1 + 12) - 2);
    }
    if (*(_WORD*)(v2 + 72))
    {
        v5 = xLeft + *(_DWORD*)(a1 + 8) / 2;
        v6 = yTop + *(_DWORD*)(a1 + 12) / 2;
        if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
            sub_43F670(1);
        sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), &a2, 0, 0);
        if (*(_DWORD*)(v2 + 68) != 0x80000000)
        {
            sub_434390(*(_DWORD*)(v2 + 68));
            v9 = *(_DWORD*)(a1 + 8);
            v7 = sub_43F320(*(_DWORD*)(v2 + 200));
            sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v5 - a2 / 2, v6 - v7 / 2, v9, 0);
        }
        sub_43F670(0);
    }
    return 1;
}

//----- (004A8340) --------------------------------------------------------
int __cdecl sub_4A8340(int a1)
{
    int result; // eax

    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
        result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A7F50, sub_4A81D0, 0);
    else
        result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A7F50, sub_4A8380, 0);
    return result;
}

//----- (004A8380) --------------------------------------------------------
int __cdecl sub_4A8380(_DWORD* a1, int a2)
{
    int v2; // esi
    _DWORD* v3; // edi
    int v4; // ebx
    int v5; // ebp
    int v6; // kr04_4
    int v7; // eax
    int v8; // eax
    int v10; // [esp-8h] [ebp-1Ch]
    int v11; // [esp+10h] [ebp-4h]

    v2 = a2;
    v3 = a1;
    v4 = *(_DWORD*)(a2 + 32);
    v5 = *(_DWORD*)(a2 + 24);
    sub_46AA60(a1, &a1, &a2);
    if (v3[1] & 8)
    {
        if (*(_DWORD*)v2 & 4)
        {
            v4 = *(_DWORD*)(v2 + 56);
        }
        else if (*(_DWORD*)v2 & 2)
        {
            v4 = *(_DWORD*)(v2 + 40);
        }
    }
    else
    {
        v5 = *(_DWORD*)(v2 + 48);
    }
    if (v5)
        sub_47D2C0(v5, (int)a1 + v3[24], a2 + v3[25]);
    if (v4)
        sub_47D2C0(v4, (int)a1 + v3[24], a2 + v3[25]);
    if (*(_WORD*)(v2 + 72))
    {
        v6 = v3[3];
        a1 = (_DWORD*)((char*)a1 + v3[2] / 2);
        v7 = v3[1] & 0x2000;
        a2 += v6 / 2;
        if (v7 == 0x2000)
            sub_43F670(1);
        sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), &v11, 0, 0);
        if (*(_DWORD*)(v2 + 68) != 0x80000000)
        {
            sub_434390(*(_DWORD*)(v2 + 68));
            v10 = v3[2];
            v8 = sub_43F320(*(_DWORD*)(v2 + 200));
            sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), (int)a1 - v11 / 2, a2 - v8 / 2, v10, 0);
        }
        sub_43F670(0);
    }
    return 1;
}

//----- (004A84E0) --------------------------------------------------------
int __cdecl sub_4A84E0(_DWORD* a1, int a2, int a3, int a4)
{
    int v4; // eax
    int v5; // eax
    int result; // eax
    int v7; // ecx
    int v8; // edx
    int v9; // eax
    int v10; // edi
    _DWORD* i; // eax
    int v12; // eax
    int v13; // edi
    _DWORD* j; // eax

    switch (a2)
    {
    case 5:
        goto LABEL_31;
    case 6:
    case 7:
        v9 = a1[9];
        v10 = a1[99];
        if (v9 & 4)
        {
            if (v9 & 2)
                LABEL_31:
            result = 1;
            else
                LABEL_16:
            result = 0;
        }
        else
        {
            nox_window_call_field_94(a1[13], 16391, (int)a1, a3);
            if (v10)
            {
                for (i = *(_DWORD * *)(v10 + 400); i; i = (_DWORD*)i[97])
                {
                    if (i != a1 && i[10] == a1[10])
                        i[9] &= 0xFFFFFFFB;
                }
            }
            v12 = a1[9];
            LOBYTE(v12) = v12 | 4;
            a1[9] = v12;
            result = 1;
        }
        break;
    case 8:
        nox_window_call_field_94(a1[13], 0x4000, (int)a1, a3);
        return 1;
    case 17:
        v4 = a1[11];
        if (!(v4 & 0x100))
            goto LABEL_31;
        v5 = a1[9];
        LOBYTE(v5) = v5 | 2;
        a1[9] = v5;
        nox_window_call_field_94(a1[13], 16389, (int)a1, a3);
        sub_46B500((int)a1);
        result = 1;
        break;
    case 18:
        v7 = a1[11];
        if (!(v7 & 0x100))
            goto LABEL_31;
        v8 = a1[13];
        a1[9] &= 0xFFFFFFFD;
        nox_window_call_field_94(v8, 16390, (int)a1, a3);
        result = 1;
        break;
    case 21:
        switch (a3)
        {
        case 15:
        case 205:
        case 208:
            if (a4 != 2)
                goto LABEL_31;
            sub_46A8A0();
            result = 1;
            break;
        case 28:
        case 57:
            if (a4 != 2)
                goto LABEL_31;
            v13 = a1[99];
            if (a1[9] & 4)
                goto LABEL_31;
            nox_window_call_field_94(a1[13], 16391, (int)a1, 0);
            if (v13)
            {
                for (j = *(_DWORD * *)(v13 + 400); j; j = (_DWORD*)j[97])
                {
                    if (j != a1 && j[10] == a1[10])
                        j[9] &= 0xFFFFFFFB;
                }
            }
            a1[9] ^= 4u;
            result = 1;
            break;
        case 200:
        case 203:
            if (a4 == 2)
                sub_46A8B0();
            goto LABEL_31;
        default:
            goto LABEL_16;
        }
        return result;
    default:
        goto LABEL_16;
    }
    return result;
}

//----- (004A87E0) --------------------------------------------------------
int __cdecl sub_4A87E0(int a1)
{
    int result; // eax

    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
        result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A84E0, sub_4A8820, 0);
    else
        result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A84E0, sub_4A8A20, 0);
    return result;
}

//----- (004A8820) --------------------------------------------------------
int __cdecl sub_4A8820(int a1, int a2)
{
    int v2; // esi
    int v3; // ebx
    int v4; // ebp
    int v5; // edi
    int v6; // eax
    int v7; // edi
    int v8; // eax
    int v9; // eax
    int v11; // [esp-8h] [ebp-28h]
    int v12; // [esp+10h] [ebp-10h]
    int v13; // [esp+14h] [ebp-Ch]
    int v14; // [esp+18h] [ebp-8h]
    int v15; // [esp+1Ch] [ebp-4h]

    v2 = a2;
    v3 = a1;
    v12 = *(_DWORD*)(a2 + 28);
    a2 = *(_DWORD*)(a2 + 20);
    sub_46AA60((_DWORD*)a1, &v14, &v15);
    if (*(_BYTE*)(v3 + 4) & 8)
    {
        if (*(_BYTE*)v2 & 2)
            v12 = *(_DWORD*)(v2 + 36);
    }
    else
    {
        a2 = *(_DWORD*)(v2 + 44);
    }
    v4 = v14 + 4;
    v5 = *(_DWORD*)(v3 + 12) / 2 + v15 - 5;
    v13 = sub_43F320(*(_DWORD*)(v2 + 200));
    if (a2 != 0x80000000)
    {
        sub_434460(a2);
        sub_49CE30(v4, v5, 10, 10);
    }
    if (v12 != 0x80000000)
    {
        sub_434460(v12);
        sub_49CC70(v4, v5, 10, 10);
    }
    if (*(_BYTE*)v2 & 4 && *(_DWORD*)(v2 + 52) != 0x80000000)
    {
        sub_434460(*(_DWORD*)(v2 + 52));
        sub_49CE30(v4 + 1, v5 + 1, 8, 8);
    }
    if ((*(_DWORD*)(v3 + 4) & 0x2000) == 0x2000)
        sub_43F670(1);
    if (**(_DWORD * *)(v3 + 32))
    {
        v6 = *(_DWORD*)(v3 + 12);
        v14 += *(_DWORD*)(v3 + 8) / 2;
        v7 = v6 / 2 + v15;
        v8 = *(_DWORD*)(v2 + 200);
        v15 = v7;
        sub_43F840(v8, (unsigned __int16*)(v2 + 72), &a1, 0, 0);
        if (*(_DWORD*)(v2 + 68) != 0x80000000)
        {
            sub_434390(*(_DWORD*)(v2 + 68));
            v11 = *(_DWORD*)(v3 + 8);
            v9 = sub_43F320(*(_DWORD*)(v2 + 200));
            sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v14 - a1 / 2, v15 - v9 / 2, v11, 0);
        }
    }
    else if (*(_DWORD*)(v2 + 68) != 0x80000000)
    {
        sub_434390(*(_DWORD*)(v2 + 68));
        sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v4 + 14, v5 - v13 / 2 + 5, *(_DWORD*)(v3 + 8), 0);
    }
    sub_43F670(0);
    return 1;
}

//----- (004A8A20) --------------------------------------------------------
int __cdecl sub_4A8A20(int a1, int a2)
{
    int v2; // esi
    int v3; // ebp
    int v4; // ebx
    int v5; // eax
    int v6; // kr00_4
    int v7; // edx
    int v8; // eax
    int v9; // kr10_4
    int v10; // eax
    int v12; // [esp-8h] [ebp-20h]
    int v13; // [esp+10h] [ebp-8h]
    int v14; // [esp+14h] [ebp-4h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 32);
    v4 = *(_DWORD*)(a2 + 24);
    sub_46AA60((_DWORD*)a1, &v13, &v14);
    if (*(_BYTE*)(a1 + 4) & 8)
    {
        if (*(_BYTE*)v2 & 2)
            v3 = *(_DWORD*)(v2 + 40);
    }
    else
    {
        v4 = *(_DWORD*)(v2 + 48);
    }
    if (v4)
        sub_47D2C0(v4, v13 + *(_DWORD*)(v2 + 60), v14 + *(_DWORD*)(v2 + 64));
    if (*(_BYTE*)v2 & 4)
    {
        v5 = *(_DWORD*)(v2 + 56);
        if (v5)
            sub_47D2C0(v5, v13 + *(_DWORD*)(v2 + 60), v14 + *(_DWORD*)(v2 + 64));
    }
    else if (v3)
    {
        sub_47D2C0(v3, v13 + *(_DWORD*)(v2 + 60), v14 + *(_DWORD*)(v2 + 64));
    }
    if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
        sub_43F670(1);
    if (**(_DWORD * *)(a1 + 32))
    {
        v6 = *(_DWORD*)(a1 + 8);
        v7 = *(_DWORD*)(v2 + 200);
        v14 += *(_DWORD*)(a1 + 12) / 2;
        v13 += v6 / 2;
        sub_43F840(v7, (unsigned __int16*)(v2 + 72), &a2, 0, 0);
        if (*(_DWORD*)(v2 + 68) != 0x80000000)
        {
            sub_434390(*(_DWORD*)(v2 + 68));
            v12 = *(_DWORD*)(a1 + 8);
            v8 = sub_43F320(*(_DWORD*)(v2 + 200));
            sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v13 - a2 / 2, v14 - v8 / 2, v12, 0);
        }
    }
    else
    {
        v9 = *(_DWORD*)(a1 + 12) - sub_43F320(*(_DWORD*)(v2 + 200));
        v10 = *(_DWORD*)(v2 + 68);
        v14 += v9 / 2;
        v13 += 28;
        if (v10 != 0x80000000)
        {
            sub_434390(v10);
            sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v13, v14, *(_DWORD*)(a1 + 8), 0);
        }
    }
    sub_43F670(0);
    return 1;
}

//----- (004A8C00) --------------------------------------------------------
int __cdecl sub_4A8C00(int a1, int a2, int a3, int a4)
{
    int v4; // eax
    int v5; // eax
    int result; // eax
    int v7; // ecx
    int v8; // esi
    int v9; // [esp-10h] [ebp-14h]

    switch (a2)
    {
    case 5:
        goto LABEL_17;
    case 6:
    case 7:
        v8 = a1;
        if (!(*(_BYTE*)(a1 + 36) & 2))
            goto LABEL_18;
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16391, a1, a3);
    LABEL_9:
        *(_DWORD*)(v8 + 36) ^= 4u;
        result = 1;
        break;
    case 8:
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, a3);
        return 1;
    case 17:
        v4 = *(_DWORD*)(a1 + 44);
        if (!(v4 & 0x100))
            goto LABEL_17;
        v5 = *(_DWORD*)(a1 + 52);
        *(_DWORD*)(a1 + 36) |= 2u;
        nox_window_call_field_94(v5, 16389, a1, a3);
        sub_46B500(a1);
        result = 1;
        break;
    case 18:
        v7 = *(_DWORD*)(a1 + 44);
        if (v7 & 0x100)
        {
            v9 = *(_DWORD*)(a1 + 52);
            *(_DWORD*)(a1 + 36) &= 0xFFFFFFFD;
            nox_window_call_field_94(v9, 16390, a1, a3);
            result = 1;
        }
        else
        {
        LABEL_17:
            result = 1;
        }
        break;
    case 21:
        switch (a3)
        {
        case 15:
        case 205:
        case 208:
            if (a4 != 2)
                goto LABEL_17;
            sub_46A8A0();
            return 1;
        case 28:
        case 57:
            if (a4 != 2)
                goto LABEL_17;
            v8 = a1;
            nox_window_call_field_94(*(_DWORD*)(v8 + 52), 16391, v8, 0);
            goto LABEL_9;
        case 200:
        case 203:
            if (a4 == 2)
                sub_46A8B0();
            goto LABEL_17;
        default:
            goto LABEL_18;
        }
    default:
    LABEL_18:
        result = 0;
        break;
    }
    return result;
}

//----- (004A8E60) --------------------------------------------------------
int __cdecl sub_4A8E60(int a1)
{
    int result; // eax

    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
        result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A8C00, sub_4A8EA0, 0);
    else
        result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A8C00, sub_4A9050, 0);
    return result;
}

//----- (004A8EA0) --------------------------------------------------------
int __cdecl sub_4A8EA0(int a1, int a2)
{
    int v2; // esi
    int v3; // ebp
    int v4; // edi
    int v5; // ebx
    int v6; // edi
    int v7; // ebx
    int v9; // [esp+10h] [ebp-Ch]
    int xLeft; // [esp+14h] [ebp-8h]
    int yTop; // [esp+18h] [ebp-4h]
    int v12; // [esp+24h] [ebp+8h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 28);
    v12 = *(_DWORD*)(a2 + 20);
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if (*(_BYTE*)(a1 + 4) & 8)
    {
        if (*(_BYTE*)v2 & 2)
            v3 = *(_DWORD*)(v2 + 36);
    }
    else
    {
        v12 = *(_DWORD*)(v2 + 44);
    }
    v4 = yTop + *(_DWORD*)(a1 + 12) / 2 - 5;
    v5 = xLeft + 4;
    if (v12 != 0x80000000)
    {
        sub_434460(v12);
        sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    if (v3 != 0x80000000)
    {
        sub_434460(v3);
        sub_49CC70(v5, v4, 10, 10);
    }
    if (*(_BYTE*)v2 & 4)
    {
        if (*(_DWORD*)(v2 + 52) != 0x80000000)
        {
            sub_434460(*(_DWORD*)(v2 + 52));
            sub_49CE30(v5 + 1, v4 + 1, 8, 8);
            if (v3 != 0x80000000)
            {
                sub_434460(v3);
                sub_49F500(v5, v4);
                sub_49F570(9, 9);
                sub_49E4B0();
                sub_49F500(v5, v4 + 9);
                sub_49F570(9, -9);
                sub_49E4B0();
            }
        }
    }
    v6 = 5 - sub_43F320(*(_DWORD*)(v2 + 200)) / 2 + v4;
    v7 = v5 + 14;
    sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), &v9, 0, 0);
    if (*(_DWORD*)(v2 + 68) != 0x80000000)
    {
        if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
            sub_43F670(1);
        sub_434390(*(_DWORD*)(v2 + 68));
        sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v7, v6, *(_DWORD*)(a1 + 8), 0);
        sub_43F670(0);
    }
    return 1;
}

//----- (004A9050) --------------------------------------------------------
int __cdecl sub_4A9050(_DWORD* a1, int a2)
{
    int v2; // esi
    _DWORD* v3; // ebx
    int v4; // edi
    int v5; // edi
    int v6; // ebp
    int v7; // eax
    int v8; // edi
    int v9; // ebp
    int v11; // [esp+10h] [ebp-Ch]
    int v12; // [esp+14h] [ebp-8h]
    int v13; // [esp+18h] [ebp-4h]

    v2 = a2;
    v3 = a1;
    v11 = *(_DWORD*)(a2 + 32);
    a2 = *(_DWORD*)(a2 + 24);
    sub_46AA60(a1, &v12, &v13);
    v4 = v13 + v3[3] / 2;
    if (v3[1] & 8)
    {
        if (*(_BYTE*)v2 & 2)
            v11 = *(_DWORD*)(v2 + 40);
    }
    else
    {
        a2 = *(_DWORD*)(v2 + 48);
    }
    v5 = v4 - 5;
    v6 = v12 + 4;
    if (a2)
        sub_47D2C0(a2, v6 + v3[24], v5 + v3[25]);
    if (*(_BYTE*)v2 & 4)
    {
        v7 = *(_DWORD*)(v2 + 56);
        if (!v7)
            goto LABEL_12;
    }
    else
    {
        v7 = v11;
        if (!v11)
            goto LABEL_12;
    }
    sub_47D2C0(v7, v6 + v3[24], v5 + v3[25]);
LABEL_12:
    v8 = 5 - sub_43F320(*(_DWORD*)(v2 + 200)) / 2 + v5;
    v9 = v6 + 16;
    sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), (int*)& a1, 0, 0);
    if (*(_DWORD*)(v2 + 68) != 0x80000000)
    {
        if ((v3[1] & 0x2000) == 0x2000)
            sub_43F670(1);
        sub_434390(*(_DWORD*)(v2 + 68));
        sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v9, v8, v3[2], 0);
        sub_43F670(0);
    }
    return 1;
}

//----- (004A91A0) --------------------------------------------------------
int __cdecl sub_4A91A0(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7)
{
    int v7; // eax
    _DWORD* v8; // eax
    int v9; // esi
    _DWORD* v10; // eax

    v7 = a7[2];
    if (v7 & 1)
    {
        v8 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A9250);
        v9 = (int)v8;
        if (v8)
        {
            sub_4A8340((int)v8);
        LABEL_7:
            if (!a7[4])
                a7[4] = v9;
            sub_46AF80_copy_window_part(v9, a7);
            return v9;
        }
        return v9;
    }
    if (v7 & 4)
    {
        v10 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A92C0);
        v9 = (int)v10;
        if (v10)
        {
            sub_4A8E60((int)v10);
            goto LABEL_7;
        }
        return v9;
    }
    return 0;
}

//----- (004A9250) --------------------------------------------------------
int __cdecl sub_4A9250(int a1, int a2, wchar_t* a3, int a4)
{
    int result; // eax
    int v4; // eax
    int v5; // eax

    if (a2 == 23)
    {
        if (!a3)
        {
            v4 = *(_DWORD*)(a1 + 36);
            LOBYTE(v4) = v4 & 0xFD;
            *(_DWORD*)(a1 + 36) = v4;
        }
        v5 = sub_46B0A0((int*)a1);
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v5);
        result = 1;
    }
    else
    {
        if (a2 == 16385)
        {
            nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
            *(_WORD*)(a1 + 234) = 0;
        }
        result = 0;
    }
    return result;
}

//----- (004A92C0) --------------------------------------------------------
int __cdecl sub_4A92C0(int a1, int a2, wchar_t* a3, int a4)
{
    int result; // eax
    int v4; // eax
    int v5; // eax

    if (a2 == 23)
    {
        if (!a3)
        {
            v4 = *(_DWORD*)(a1 + 36);
            LOBYTE(v4) = v4 & 0xFD;
            *(_DWORD*)(a1 + 36) = v4;
        }
        v5 = sub_46B0A0((int*)a1);
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v5);
        result = 1;
    }
    else
    {
        if (a2 == 16385)
        {
            nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
            *(_WORD*)(a1 + 234) = 0;
        }
        result = 0;
    }
    return result;
}

//----- (004A9330) --------------------------------------------------------
int __cdecl sub_4A9330(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD* a8)
{
    _DWORD* v8; // eax
    int v9; // esi
    _DWORD* v10; // eax

    if (!(*(_BYTE*)(a7 + 8) & 2))
        return 0;
    v8 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A93C0);
    v9 = (int)v8;
    if (v8)
    {
        sub_4A87E0((int)v8);
        if (!*(_DWORD*)(a7 + 16))
            * (_DWORD*)(a7 + 16) = v9;
        v10 = nox_malloc(4u);
        *v10 = 0;
        if (a8)
            * v10 = *a8;
        *(_DWORD*)(v9 + 32) = v10;
        sub_46AF80_copy_window_part(v9, (const void*)a7);
    }
    return v9;
}

//----- (004A93C0) --------------------------------------------------------
int __cdecl sub_4A93C0(int a1, int a2, wchar_t* a3, int a4)
{
    int v3; // edi
    _DWORD* i; // eax
    int v5; // eax
    int v7; // eax
    int v8; // eax

    if (a2 != 23)
    {
        if (a2 == 16385)
        {
            nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
            *(_WORD*)(a1 + 234) = 0;
        }
        else if (a2 == 16392)
        {
            v3 = *(_DWORD*)(a1 + 396);
            if (!(*(_BYTE*)(a1 + 36) & 4))
            {
                if (a3 == (wchar_t*)1)
                    nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16391, a1, 0);
                if (v3)
                {
                    for (i = *(_DWORD * *)(v3 + 400); i; i = (_DWORD*)i[97])
                    {
                        if (i != (_DWORD*)a1 && i[10] == *(_DWORD*)(a1 + 40))
                            i[9] &= 0xFFFFFFFB;
                    }
                }
                v5 = *(_DWORD*)(a1 + 36);
                LOBYTE(v5) = v5 | 4;
                *(_DWORD*)(a1 + 36) = v5;
                return 0;
            }
        }
        return 0;
    }
    if (!a3)
    {
        v7 = *(_DWORD*)(a1 + 36);
        LOBYTE(v7) = v7 & 0xFD;
        *(_DWORD*)(a1 + 36) = v7;
    }
    v8 = sub_46B0A0((int*)a1);
    nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v8);
    return 1;
}

//----- (004A94A0) --------------------------------------------------------
int sub_4A94A0()
{
    *(_DWORD*)& byte_5D4594[2650656] = sub_4344A0(0, 0, 0);
    *(_DWORD*)& byte_5D4594[2614248] = sub_4344A0(8, 8, 8);
    *(_DWORD*)& byte_5D4594[2650660] = sub_4344A0(115, 115, 115);
    *(_DWORD*)& byte_5D4594[2597996] = sub_4344A0(212, 212, 212);
    *(_DWORD*)& byte_5D4594[2523948] = sub_4344A0(255, 255, 255);
    *(_DWORD*)& byte_5D4594[2598268] = sub_4344A0(100, 0, 0);
    *(_DWORD*)& byte_5D4594[2650644] = sub_4344A0(255, 0, 0);
    *(_DWORD*)& byte_5D4594[2589776] = sub_4344A0(255, 128, 128);
    *(_DWORD*)& byte_5D4594[2650688] = sub_4344A0(0, 100, 0);
    *(_DWORD*)& byte_5D4594[2618904] = sub_4344A0(0, 255, 0);
    *(_DWORD*)& byte_5D4594[2614268] = sub_4344A0(128, 255, 128);
    *(_DWORD*)& byte_5D4594[2650648] = sub_4344A0(0, 0, 140);
    *(_DWORD*)& byte_5D4594[2649820] = sub_4344A0(0, 0, 255);
    *(_DWORD*)& byte_5D4594[2650684] = sub_4344A0(0, 160, 255);
    *(_DWORD*)& byte_5D4594[2614256] = sub_4344A0(240, 180, 42);
    *(_DWORD*)& byte_5D4594[2589772] = sub_4344A0(255, 255, 0);
    *(_DWORD*)& byte_5D4594[2614244] = sub_4344A0(255, 255, 128);
    *(_DWORD*)& byte_5D4594[2649836] = &byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[2649840] = &byte_5D4594[2614248];
    *(_DWORD*)& byte_5D4594[2649844] = &byte_5D4594[2650660];
    *(_DWORD*)& byte_5D4594[2649848] = &byte_5D4594[2597996];
    *(_DWORD*)& byte_5D4594[2649852] = &byte_5D4594[2523948];
    *(_DWORD*)& byte_5D4594[2649856] = &byte_5D4594[2598268];
    *(_DWORD*)& byte_5D4594[2649860] = &byte_5D4594[2650644];
    *(_DWORD*)& byte_5D4594[2649864] = &byte_5D4594[2589776];
    *(_DWORD*)& byte_5D4594[2649868] = &byte_5D4594[2650688];
    *(_DWORD*)& byte_5D4594[2649872] = &byte_5D4594[2618904];
    *(_DWORD*)& byte_5D4594[2649876] = &byte_5D4594[2614268];
    *(_DWORD*)& byte_5D4594[2649880] = &byte_5D4594[2650648];
    *(_DWORD*)& byte_5D4594[2649884] = &byte_5D4594[2649820];
    *(_DWORD*)& byte_5D4594[2649888] = &byte_5D4594[2650684];
    *(_DWORD*)& byte_5D4594[2649892] = &byte_5D4594[2614256];
    *(_DWORD*)& byte_5D4594[2649896] = &byte_5D4594[2589772];
    *(_DWORD*)& byte_5D4594[2649900] = &byte_5D4594[2614244];
    return 1;
}

//----- (004A96C0) --------------------------------------------------------
FILE* __cdecl sub_4A96C0(char* a1)
{
    FILE* result; // eax
    FILE* v2; // ebp
    char v3[8]; // [esp+Ch] [ebp-40h]
    char v4[12]; // [esp+14h] [ebp-38h]
    char v5[12]; // [esp+20h] [ebp-2Ch]
    char v6[32]; // [esp+2Ch] [ebp-20h]

    strcpy(v4, "SHADEMAP");
    strcpy(v5, "TRANSMAP");
    strcpy(v3, "PALETTE");
    if (*(_DWORD*)& byte_5D4594[3801780] != 1)
    {
        result = fopen(a1, "rb");
        v2 = result;
        if (!result)
            return result;
        if (sub_40ADD0_fread(v6, 1u, strlen(v3), result) != strlen(v3))
        {
            fclose(v2);
            return 0;
        }
        v6[strlen(v3)] = 0;
        if (strcmp(v6, v3))
        {
            fclose(v2);
            return 0;
        }
        if (sub_40ADD0_fread((char*)& byte_5D4594[1308748], 1u, 0x300u, v2) != 768)
        {
            fclose(v2);
            return 0;
        }
        sub_4347F0((char*)& byte_5D4594[1308748], 256);
        sub_4348C0();
        if (!sub_42FFF0(v2))
        {
            fclose(v2);
            return 0;
        }
        if (sub_40ADD0_fread(v6, 1u, strlen(v4), v2) != strlen(v4))
        {
            fclose(v2);
            return 0;
        }
        v6[strlen(v4)] = 0;
        if (strcmp(v6, v4))
        {
            fclose(v2);
            return 0;
        }
        if (sub_40ADD0_fread((char*)& byte_5D4594[2589804], 1u, 0x2000u, v2) != 0x2000)
        {
            fclose(v2);
            return 0;
        }
        sub_434610((int)& byte_5D4594[2589804]);
        if (sub_40ADD0_fread(v6, 1u, strlen(v5), v2) != strlen(v5))
        {
            fclose(v2);
            return 0;
        }
        v6[strlen(v5)] = 0;
        if (strcmp(v6, v5))
        {
            fclose(v2);
            return 0;
        }
        if (sub_40ADD0_fread((char*)& byte_5D4594[2524236], 1u, 0x10000u, v2) != 0x10000)
        {
            fclose(v2);
            return 0;
        }
        sub_434620((int)& byte_5D4594[2524236]);
        fclose(v2);
    }
    sub_4A94A0();
    sub_4A9A10();
    return (FILE*)1;
}
// 4A96C0: using guessed type char var_20[32];

//----- (004A9A10) --------------------------------------------------------
int sub_4A9A10()
{
    int i; // esi

    for (i = 0; i < 6; ++i)
        sub_4341D0(i, *(int*)& byte_5D4594[2523948]);
    return 1;
}

//----- (004A9A30) --------------------------------------------------------
int __cdecl sub_4A9A30(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)
{
    int result; // eax
    int v4; // ebp
    unsigned __int8* v5; // edi
    int v6; // edx
    int v7; // ebx
    unsigned __int8 v8; // [esp+10h] [ebp-10h]
    unsigned __int8 v9; // [esp+14h] [ebp-Ch]
    unsigned __int8 v10; // [esp+18h] [ebp-8h]
    int v11; // [esp+1Ch] [ebp-4h]

    result = 0;
    v4 = 0x1000000;
    v11 = 0;
    v5 = &byte_5D4594[1308749];
    while (*(v5 - 1) != a1 || *v5 != a2 || v5[1] != a3)
    {
        v6 = *(v5 - 1);
        if ((int)v6 - (int)a1 >= 0)
            v10 = v6 - a1;
        else
            v10 = a1 - v6;
        if ((int)* v5 - (int)a2 >= 0)
            v9 = *v5 - a2;
        else
            v9 = a2 - *v5;
        if ((int)v5[1] - (int)a3 >= 0)
            v8 = v5[1] - a3;
        else
            v8 = a3 - v5[1];
        v7 = v9 * v9;
        if (v8 * v8 + v7 + v10 * v10 < v4)
        {
            v4 = v8 * v8 + v7 + v10 * v10;
            v11 = result;
        }
        v5 += 3;
        ++result;
        if ((int)v5 >= (int)& byte_5D4594[1309517])
            return v11;
    }
    return result;
}

//----- (004A9B20) --------------------------------------------------------
__int16 __cdecl sub_4A9B20(int a1)
{
    int v1; // eax

    if (*(_DWORD*)& byte_5D4594[3801780] == 1)
        LOWORD(v1) = 0;
    else
        v1 = (byte_5D4594[3 * a1 + 1308750] >> 3) | (4
            * (byte_5D4594[3 * a1 + 1308749] & 0xF8 | (32
                * (byte_5D4594[3 * a1 + 1308748] & 0xF8))));
    return v1;
}

//----- (004A9B70) --------------------------------------------------------
__int16 __cdecl sub_4A9B70(__int16* a1)
{
    int v1; // eax

    if (*(_DWORD*)& byte_5D4594[3801780])
    {
        if (*(_DWORD*)& byte_5D4594[3799624] == 2)
            v1 = *a1 & 0x1F | (*a1 >> 1) & 0x7FE0;
        else
            LOWORD(v1) = *a1;
    }
    else
    {
        LOWORD(v1) = sub_4A9B20(*(unsigned __int8*)a1);
    }
    return v1;
}

//----- (004A9BC0) --------------------------------------------------------
int __cdecl sub_4A9BC0(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)
{
    if (*(_DWORD*)& byte_5D4594[3801780] != 1)
        return sub_4A9A30(a1, a2, a3);
    if (*(_DWORD*)& byte_5D4594[3799624] == 1)
        return (a3 >> 3) | (4 * (a2 & 0xF8 | (32 * (a1 & 0xF8))));
    return (a3 >> 3) | (8 * (a2 & 0xFC | (32 * (a1 & 0xF8))));
}

//----- (004A9C50) --------------------------------------------------------
int __cdecl sub_4A9C50(int a1)
{
    unsigned __int16 v1; // cx

    HIBYTE(v1) = byte_5D4594[3 * a1 + 1308750];
    LOBYTE(v1) = byte_5D4594[3 * a1 + 1308749];
    return byte_5D4594[3 * a1 + 1308748] | (v1 << 8);
}

//----- (004A9C80) --------------------------------------------------------
int sub_4A9C80()
{
    int v0; // edi
    unsigned __int8* v1; // esi
    int v2; // edi
    unsigned __int8* v3; // esi
    char v5[64]; // [esp+8h] [ebp-40h]

    *(_DWORD*)& byte_5D4594[1309664] = 0;
    v0 = 0;
    v1 = &byte_5D4594[1309644];
    do
    {
        nox_sprintf(v5, "Compass%d", ++v0);
        *(_DWORD*)v1 = sub_42F970(v5);
        v1 += 4;
    } while ((int)v1 < (int)& byte_5D4594[1309660]);
    v2 = 0;
    v3 = &byte_5D4594[1309516];
    do
    {
        nox_sprintf(v5, "CompassMainArrow%d", ++v2);
        *(_DWORD*)v3 = sub_42F970(v5);
        v3 += 4;
    } while ((int)v3 < (int)& byte_5D4594[1309644]);
    return 1;
}

//----- (004A9D00) --------------------------------------------------------
__int16 __cdecl sub_4A9D00(unsigned __int8* a1)
{
    unsigned __int8* v1; // ebx
    int v2; // eax
    int v3; // edi
    int v4; // esi
    wchar_t* v5; // eax
    int v6; // kr00_4
    int v7; // esi

    v1 = a1;
    v2 = *(unsigned __int16*)(a1 + 1);
    if ((unsigned __int16)v2 == *(_DWORD*)& byte_5D4594[1309668])
        return v2;
    *(_DWORD*)& byte_5D4594[1309668] = *(unsigned __int16*)(a1 + 1);
    sub_452D80(897, 50);
    sub_430B50(0, 0, nox_win_width - 1, nox_win_height - 1);
    sub_440900();
    v3 = nox_win_height / 2 - 120;
    v4 = nox_win_width / 2 - 160;
    sub_47D2C0(*(_DWORD*)& byte_5D4594[4 * (*(_DWORD*)& byte_5D4594[1309672] % 4) + 1309644], v4, v3);
    sub_47D2C0(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1309672] + 1309516], v4, v3);
    switch (*v1)
    {
    case 0x9Bu:
        v5 = loadString_sub_40F1D0((char*)& byte_587000[172368], 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c", 89);
        goto LABEL_8;
    case 0x9Cu:
        v5 = loadString_sub_40F1D0((char*)& byte_587000[172416], 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c", 92);
        goto LABEL_8;
    case 0x9Du:
        v5 = loadString_sub_40F1D0((char*)& byte_587000[172464], 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c", 95);
    LABEL_8:
        *(_DWORD*)& byte_5D4594[1309660] = v5;
        break;
    }
    sub_43F840(0, *(unsigned __int16**)& byte_5D4594[1309660], (int*)& a1, 0, 0);
    v6 = nox_win_width - (_DWORD)a1;
    v7 = nox_win_height / 2 - (2 * sub_43F320(0) + 70);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_4343E0(*(int*)& byte_5D4594[2614248]);
    sub_43F730(0, *(__int16**)& byte_5D4594[1309660], v6 / 2, v7);
    if (++ * (_DWORD*)& byte_5D4594[1309672] >= 32)
        * (_DWORD*)& byte_5D4594[1309672] = 0;
    sub_48A220();
    sub_4AD170_call_copy_backbuffer();
    sub_48A290_call_present();
    return v2;
}
// 4AD170: using guessed type int sub_4AD170_call_copy_backbuffer(void);

//----- (004A9E90) --------------------------------------------------------
__int16 __cdecl sub_4A9E90(int a1, int a2, int a3, int a4)
{
    int v4; // eax
    int v5; // esi
    int v6; // ebp
    int v7; // edi
    int v8; // ebx
    int v9; // edi
    int v10; // esi
    int v11; // eax
    int v12; // esi
    //bool v13; // zf
    //bool v14; // of
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
    if (v5 <= v7)
    {
        do
        {
            sub_47D2C0(*(int*)& byte_5D4594[1309692], v5, v6);
            sub_47D2C0(*(int*)& byte_5D4594[1309692], v5, v8);
            v5 += 20;
        } while (v5 <= v7);
        v4 = v19;
    }
    v9 = v4 - 10;
    if (v4 - 10 - v5 >= 10)
    {
        sub_47D2C0(*(int*)& byte_5D4594[1309696], v5, v6);
        sub_47D2C0(*(int*)& byte_5D4594[1309696], v5, v8);
        v5 += 10;
    }
    if (v5 < v9)
    {
        v10 = v5 + ((v9 - v5 + 1) & 0xFFFFFFFE) - 10;
        sub_47D2C0(*(int*)& byte_5D4594[1309696], v10, v6);
        sub_47D2C0(*(int*)& byte_5D4594[1309696], v10, v8);
    }
    v11 = a2 + a4 - 30;
    v12 = a2 + 10;
    //v14 = __OFSUB__(a2 + 10, v11);
    //v13 = a2 + 10 == v11;
    v15 = v18 - 10;
    v20 = a2 + a4 - 30;
    //if ( (10 - (a4 - 30) < 0) ^ v14 | v13 )
    while (v12 <= v20)
    {
        sub_47D2C0(*(int*)& byte_5D4594[1309700], v15, v12);
        sub_47D2C0(*(int*)& byte_5D4594[1309700], v9, v12);
        v12 += 20;
    }
    if (v8 - v12 >= 10)
    {
        sub_47D2C0(*(int*)& byte_5D4594[1309704], v15, v12);
        sub_47D2C0(*(int*)& byte_5D4594[1309704], v9, v12);
        v12 += 10;
    }
    if (v12 < v8)
    {
        v16 = v12 + ((v8 - v12 + 1) & 0xFFFFFFFE) - 10;
        sub_47D2C0(*(int*)& byte_5D4594[1309704], v15, v16);
        sub_47D2C0(*(int*)& byte_5D4594[1309704], v9, v16);
    }
    sub_47D2C0(*(int*)& byte_5D4594[1309676], v15, v21);
    sub_47D2C0(*(int*)& byte_5D4594[1309680], v9, v21);
    sub_47D2C0(*(int*)& byte_5D4594[1309684], v15, v8);
    return sub_47D2C0(*(int*)& byte_5D4594[1309688], v9, v8);
}

//----- (004AA030) --------------------------------------------------------
__int16 __cdecl sub_4AA030(_DWORD* a1, int a2)
{
    _DWORD* v2; // esi
    int v3; // edi
    int v4; // eax
    unsigned int v5; // ebx
    int v6; // edx
    int v7; // ecx
    int v8; // eax
    _DWORD* v9; // eax
    int v10; // ebp
    bool v11; // zf
    int v12; // ebx
    _DWORD* v13; // edi
    __int16 v14; // cx
    int v16; // [esp+10h] [ebp-10h]
    unsigned int v17; // [esp+14h] [ebp-Ch]
    int v18; // [esp+18h] [ebp-8h]
    int v19; // [esp+1Ch] [ebp-4h]

    v2 = a1;
    v3 = 0;
    LOWORD(v4) = sub_46AA60(a1, &a1, &v16);
    v5 = 0;
    v17 = 0;
    while (!v3)
    {
        v4 = (1 << v5) & v2[11];
        if (v4)
        {
            if (v4 <= 32)
            {
                if (v4 != 32)
                {
                    switch (--v4)
                    {
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
                if (*(_DWORD*)(v6 + 12))
                    v7 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v6 + 36) + 400) + 12);
                if (*((_WORD*)v2 + 54))
                    v8 = 4;
                LOWORD(v4) = sub_4A9E90((int)a1 - 3, v16 - v8 - 3, v2[2] - v7 + 3, v2[3] + 6);
                goto LABEL_25;
            }
            if (v4 > 4096)
            {
                if (v4 == 0x2000)
                    goto LABEL_24;
            }
            else
            {
                switch (v4)
                {
                case 4096:
                    goto LABEL_24;
                case 128:
                    v9 = a1;
                    v10 = v2[8];
                    v11 = *(_WORD*)(a2 + 72) == 0;
                    v12 = v2[2];
                    v19 = v16;
                    v13 = a1;
                    if (!v11)
                    {
                        sub_43F840(*(_DWORD*)(a2 + 200), (unsigned __int16*)(a2 + 72), &v18, 0, 0);
                        v13 = (_DWORD*)((char*)v13 + v18 + 6);
                        v9 = a1;
                        v12 += -6 - v18;
                    }
                    v14 = *(_WORD*)(v10 + 1042);
                    if (v14 > 0 && v12 > v14)
                    {
                        v12 = v14;
                        v13 = (_DWORD*)((char*)v9 + v2[2] - v14);
                    }
                    LOWORD(v4) = sub_4A9E90((int)v13, v19, v12, v2[3]);
                    v5 = v17;
                    v3 = 1;
                    break;
                case 2048:
                LABEL_24:
                    LOWORD(v4) = sub_4A9E90((int)a1, v16, v2[2], v2[3]);
                LABEL_25:
                    v3 = 1;
                    break;
                }
            }
        }
    LABEL_26:
        v17 = ++v5;
        if (v5 >= 0x20)
            return v4;
    }
    return v4;
}

//----- (004AA1F0) --------------------------------------------------------
char* sub_4AA1F0()
{
    char* result; // eax

    *(_DWORD*)& byte_5D4594[1309676] = sub_42F970("BorderCornerUL");
    *(_DWORD*)& byte_5D4594[1309680] = sub_42F970("BorderCornerUR");
    *(_DWORD*)& byte_5D4594[1309684] = sub_42F970("BorderCornerLL");
    *(_DWORD*)& byte_5D4594[1309688] = sub_42F970("BorderCornerLR");
    *(_DWORD*)& byte_5D4594[1309692] = sub_42F970("BorderHorizontal");
    *(_DWORD*)& byte_5D4594[1309696] = sub_42F970("BorderHorizontalShort");
    *(_DWORD*)& byte_5D4594[1309700] = sub_42F970("BorderVertical");
    result = sub_42F970("BorderVerticalShort");
    *(_DWORD*)& byte_5D4594[1309704] = result;
    return result;
}

//----- (004AA270) --------------------------------------------------------
int sub_4AA270()
{
    int result; // eax
    _DWORD* v1; // esi
    _DWORD* v2; // esi
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    int v6; // esi
    _DWORD* v7; // eax

    sub_44A400();
    sub_43BDD0(400);
    sub_4A1A40(1);
    if (sub_40E0C0() && sub_43AF70() == 1)
        sub_41D4C0();
    sub_43AF50(2);
    result = nox_new_window_from_file("ArnaMain.wnd", sub_4AA4D0);
    *(_DWORD*)& byte_5D4594[1309716] = result;
    if (result)
    {
        sub_46B300(result, sub_4A18E0);
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309716], 410);
        sub_46B2C0((int)v1, sub_4AA4D0);
        result = sub_43C5B0(v1, 0, 0, 0, -240, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[1309708] = result;
        if (result)
        {
            *(_DWORD*)result = 400;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309708] + 48) = sub_4AA450;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309708] + 56) = sub_4AA490;
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309716], 420);
            sub_46B2C0((int)v2, sub_4AA4D0);
            result = sub_43C5B0(v2, 0, 240, 0, 480, 0, -20, 0, 40);
            *(_DWORD*)& byte_5D4594[1309712] = result;
            if (result)
            {
                sub_4A19F0((char*)& byte_587000[172636]);
                sub_46A8A0();
                if (sub_40A5C0(0x2000000))
                {
                    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309716], 411);
                    nox_window_call_field_94(*(int*)& byte_5D4594[1309716], 16391, (int)v3, 0);
                    result = 1;
                }
                else if (sub_4D6FA0() == 1)
                {
                    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309716], 421);
                    nox_window_call_field_94(*(int*)& byte_5D4594[1309716], 16391, (int)v4, 0);
                    result = 1;
                }
                else
                {
                    if (sub_4D6FA0() == 2)
                    {
                        v5 = sub_46B0C0(0, 150);
                        v6 = (int)v5;
                        v7 = sub_46B0C0(v5, 152);
                        nox_window_call_field_94(v6, 16391, (int)v7, 0);
                    }
                    result = 1;
                }
            }
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004AA450) --------------------------------------------------------
int sub_4AA450()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1309708] + 64) = 2;
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1309712] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004AA490) --------------------------------------------------------
int sub_4AA490()
{
    int (*v0)(void); // esi

    v0 = *(int (**)(void))(*(_DWORD*)& byte_5D4594[1309708] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1309708]);
    sub_43C570(*(LPVOID*)& byte_5D4594[1309712]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309716]);
    v0();
    return 1;
}

//----- (004AA4D0) --------------------------------------------------------
int __cdecl sub_4AA4D0(int a1, unsigned int a2, int* a3, int a4)
{
    int v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    wchar_t* v7; // [esp-10h] [ebp-10h]
    wchar_t* v8; // [esp-10h] [ebp-10h]

    if (a2 != 16389)
    {
        if (a2 != 16391)
            return 0;
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1309708] + 64) && !sub_40A5C0(0x2000000) && !sub_4D6F30())
            goto LABEL_17;
        v4 = sub_46B0A0(a3) - 411;
        if (v4)
        {
            if (v4 != 10)
            {
            LABEL_17:
                sub_452D80(921, 100);
                return 1;
            }
            sub_4AA450();
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309708] + 52) = sub_4379F0;
            sub_43AF50(0);
        }
        else
        {
            if (!sub_41D440())
            {
                v7 = loadString_sub_40F1D0((char*)& byte_587000[172696], 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 100);
                v5 = loadString_sub_40F1D0((char*)& byte_587000[172756], 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 100);
                sub_449A10(*(int*)& byte_5D4594[1309716], (int)v5, (int)v7, 33, 0, 0);
                return 0;
            }
            if (sub_40D5B0((int)& a2) && a2 < 0x10009)
            {
                sub_41D4C0();
                v8 = loadString_sub_40F1D0((char*)& byte_587000[172804], 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 111);
                v6 = loadString_sub_40F1D0((char*)& byte_587000[172864], 0, "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 111);
                sub_449A10(*(int*)& byte_5D4594[1309716], (int)v6, (int)v8, 33, 0, 0);
                return 0;
            }
            sub_4A1A40(0);
            sub_4AA450();
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309708] + 52) = sub_44A560;
        }
        sub_40A540(0x1000000);
        goto LABEL_17;
    }
    sub_452D80(920, 100);
    return 1;
}

//----- (004AA650) --------------------------------------------------------
void sub_4AA650()
{
    char* v2; // ecx
    void* v3; // [esp+0h] [ebp-4h]

    if (!sub_44D930())
    {
        v2 = *(char**)& byte_587000[4 * (*(_DWORD*)& byte_5D4594[1309744])++ + 172892];
        loadString_sub_40F1D0(v2, &v3, "C:\\NoxPost\\src\\client\\shell\\Options.c", 131);
        *(_DWORD*)& byte_5D4594[1309744] %= 3;
        if (v3)
            /*(void*)*/sub_44D900((int)v3, 100);
    }
}

//----- (004AA6B0) --------------------------------------------------------
int sub_4AA6B0()
{
    int result; // eax
    _DWORD* v1; // esi
    char* v2; // eax
    int v3; // eax
    int v4; // ecx
    unsigned int v5; // ecx
    _DWORD* v6; // esi
    char* v7; // eax
    int v8; // eax
    int v9; // ecx
    unsigned int v10; // ecx
    _DWORD* v11; // esi
    char* v12; // eax
    int v13; // eax
    int v14; // ecx
    unsigned int v15; // ecx
    char* v16; // [esp-Ch] [ebp-Ch]
    char* v17; // [esp-Ch] [ebp-Ch]
    char* v18; // [esp-Ch] [ebp-Ch]
    char* v19; // [esp-8h] [ebp-8h]
    char* v20; // [esp-8h] [ebp-8h]
    char* v21; // [esp-8h] [ebp-8h]

    sub_43BDD0(300);
    result = nox_new_window_from_file("Options.wnd", sub_4AABE0);
    *(_DWORD*)& byte_5D4594[1309720] = result;
    if (result)
    {
        result = sub_4CB590(result);
        if (result)
        {
            sub_46B300(*(int*)& byte_5D4594[1309720], sub_4A18E0);
            sub_43FE20(15);
            result = sub_43C5B0(*(_DWORD * *)& byte_5D4594[1309720], 0, 0, 0, -480, 0, 20, 0, -40);
            *(_DWORD*)& byte_5D4594[1309740] = result;
            if (result)
            {
                *(_DWORD*)result = 300;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309740] + 48) = sub_4AA9C0;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309740] + 56) = sub_4AAA10;
                v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 351);
                *(_DWORD*)(v1[100] + 8) = 24;
                *(_DWORD*)(v1[100] + 12) = 20;
                v19 = sub_42F970("OptionsVolumeSliderLit");
                v16 = sub_42F970("OptionsVolumeSliderLit");
                v2 = sub_42F970("OptionsVolumeSlider");
                sub_4B5700((int)v1, 0, 0, (int)v2, (int)v16, (int)v19);
                nox_window_call_field_94((int)v1, 16395, 0, 0x4000);
                nox_window_call_field_94((int)v1, 16394, *(_DWORD*)(*(_DWORD*)& byte_587000[127004] + 4) >> 16, 0);
                *(_DWORD*)& byte_5D4594[1309728] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 361);
                v3 = sub_453070();
                v4 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309728] + 36);
                if (v3 == 1)
                    v5 = v4 | 4;
                else
                    v5 = v4 & 0xFFFFFFFB;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309728] + 36) = v5;
                v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 352);
                *(_DWORD*)(v6[100] + 8) = 24;
                *(_DWORD*)(v6[100] + 12) = 20;
                v20 = sub_42F970("OptionsVolumeSliderLit");
                v17 = sub_42F970("OptionsVolumeSliderLit");
                v7 = sub_42F970("OptionsVolumeSlider");
                sub_4B5700((int)v6, 0, 0, (int)v7, (int)v17, (int)v20);
                nox_window_call_field_94((int)v6, 16395, 0, 0x4000);
                nox_window_call_field_94((int)v6, 16394, *(_DWORD*)(*(_DWORD*)& byte_587000[122852] + 4) >> 16, 0);
                *(_DWORD*)& byte_5D4594[1309732] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 362);
                v8 = sub_44D990();
                v9 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309732] + 36);
                if (v8 == 1)
                    v10 = v9 | 4;
                else
                    v10 = v9 & 0xFFFFFFFB;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309732] + 36) = v10;
                v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 353);
                *(_DWORD*)(v11[100] + 8) = 24;
                *(_DWORD*)(v11[100] + 12) = 20;
                v21 = sub_42F970("OptionsVolumeSliderLit");
                v18 = sub_42F970("OptionsVolumeSliderLit");
                v12 = sub_42F970("OptionsVolumeSlider");
                sub_4B5700((int)v11, 0, 0, (int)v12, (int)v18, (int)v21);
                nox_window_call_field_94((int)v11, 16395, 0, 0x4000);
                nox_window_call_field_94((int)v11, 16394, *(_DWORD*)(*(_DWORD*)& byte_587000[93164] + 4) >> 16, 0);
                *(_DWORD*)& byte_5D4594[1309736] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 363);
                v13 = sub_43DC30();
                v14 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309736] + 36);
                if (v13 == 1)
                    v15 = v14 | 4;
                else
                    v15 = v14 & 0xFFFFFFFB;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309736] + 36) = v15;
                sub_46A8A0();
                sub_4A19F0((char*)& byte_587000[173236]);
                sub_4A1A40(0);
                sub_4AAA70();
                result = 1;
            }
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004AA9C0) --------------------------------------------------------
int sub_4AA9C0()
{
    sub_44D8F0();
    sub_43BEF0_set_video_mode(*(int*)& byte_587000[172876], *(int*)& byte_587000[172872], *(int*)& byte_587000[172880]);
    sub_433290((char*)& byte_587000[173256]);
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1309740] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004AAA10) --------------------------------------------------------
int sub_4AAA10()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[1309740] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1309740]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309720]);
    sub_4A1A40(1);
    if (nox_win_depth_1 == nox_win_depth_2)
    {
        v0();
    }
    else
    {
        nox_win_depth_2 = nox_win_depth_1;
        *(_DWORD*)& byte_5D4594[805872] = 1;
    }
    return 1;
}

//----- (004AAA70) --------------------------------------------------------
_DWORD* sub_4AAA70()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax
    int v4; // eax
    _DWORD* result; // eax
    int v6; // [esp-4h] [ebp-10h]
    int v7; // [esp-4h] [ebp-10h]
    int v8; // [esp+0h] [ebp-Ch]
    int v9; // [esp+4h] [ebp-8h]
    int v10; // [esp+8h] [ebp-4h]

    sub_43BEB0_get_video_mode(&v8, &v10, &v9);
    v9 = *(_DWORD*)& byte_587000[172880];
    if (v10 == 480)
        v6 = 321;
    else if (v10 == 576)
        v6 = 322;
    else
        v6 = 323;
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], v6);
    nox_window_call_field_94((int)v0, 16392, 1, 0);
    if (v9 == 8)
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 331);
    }
    else
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 332);
    }
    nox_window_call_field_94((int)v1, 16392, 1, 0);
    if (g_fullscreen)
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 333);
    else
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 334);
    nox_window_call_field_94((int)v1, 16392, 1, 0);
    nox_window_call_field_94(sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 316), 16394, (draw_gamma - 0.5f) * 50, 0);
    nox_window_call_field_94(sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 318), 16394, (log10f(input_sensitivity) + 1.0f) * 50, 0);
#if 0
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    if (!sub_4300D0(0))
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 331);
        sub_46AD80((int)v2, 8);
    }
    if (!sub_4300D0(1))
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 332);
        sub_46AD80((int)v3, 8);
    }
#endif
    v4 = sub_4766D0();
    *(_DWORD*)& byte_587000[172884] = v4;
    if (v4 > 69)
    {
        if (v4 <= 79)
        {
            result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 312);
            goto LABEL_22;
        }
        if (v4 <= 89)
        {
            result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], 313);
            goto LABEL_22;
        }
        v7 = 314;
    }
    else
    {
        v7 = 311;
    }
    result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309720], v7);
LABEL_22:
    if (result)
        result = (_DWORD*)nox_window_call_field_94((int)result, 16392, 1, 0);
    return result;
}

//----- (004AABE0) --------------------------------------------------------
int __cdecl sub_4AABE0(int a1, int a2, int* a3, int a4)
{
    int v4; // eax
    int v5; // eax
    int result; // eax
    int v7; // edi
    int v8; // esi
    void(__cdecl * v9)(_DWORD, int, int, int); // eax
    void(__cdecl * v10)(_DWORD, int, int, int); // eax
    void(__cdecl * v11)(_DWORD, int, int, int); // eax
    void* v12; // ecx
    void(__cdecl * v13)(void*, int, int, int); // eax
    void(__cdecl * v14)(_DWORD, int, int, int); // eax
    int v15; // ecx
    void(__cdecl * v16)(int, int, int, int); // eax
    int v17; // eax
    void(__cdecl * v18)(_DWORD, int, int, int); // eax
    void(__cdecl * v19)(_DWORD, int, int, int); // eax

    switch (a2)
    {
    case 16389:
        sub_452D80(920, 100);
        result = 1;
        break;
    case 16391:
        v4 = sub_46B0A0(a3);
        if (v4 > 341)
        {
            if (v4 > 363)
            {
                if (v4 == 2099)
                    sub_4AAA70();
            }
            else if (v4 == 363)
            {
                if (sub_43DC30() == 1)
                {
                    sub_43DC00();
                }
                else
                {
                    sub_43DC10();
                    sub_486320(*(_DWORD * *)& byte_587000[93164], *(_DWORD*)(*(_DWORD*)& byte_587000[93164] + 4) >> 16);
                }
            }
            else
            {
                v5 = v4 - 361;
                if (v5)
                {
                    if (v5 == 1)
                    {
                        if (sub_44D990() == 1)
                            sub_44D960();
                        else
                            sub_44D970();
                    }
                }
                else if (sub_453070() == 1)
                {
                    sub_453050();
                }
                else
                {
                    sub_453060();
                }
            }
        }
        else if (v4 == 341)
        {
            sub_4AA9C0();
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309740] + 56) = sub_4AB0C0;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309740] + 52) = sub_4CB880;
        }
        else
        {
            switch (v4)
            {
            case 311:
                sub_4766A0(65);
                break;
            case 312:
                sub_4766A0(75);
                break;
            case 313:
                sub_4766A0(85);
                break;
            case 314:
                sub_4766A0(100);
                break;
            case 321:
                *(_DWORD*)& byte_587000[172876] = 848;
                *(_DWORD*)& byte_587000[172872] = 480;
                break;
            case 322:
                *(_DWORD*)& byte_587000[172876] = 1024;
                *(_DWORD*)& byte_587000[172872] = 576;
                break;
            case 323:
                *(_DWORD*)& byte_587000[172876] = 1024;
                *(_DWORD*)& byte_587000[172872] = 768;
                break;
            case 332:
                *(_DWORD*)& byte_587000[172880] = 16;
            case 333:
                g_fullscreen = 1;
                break;
            case 331:
                *(_DWORD*)& byte_587000[172880] = 8;
            case 334:
                g_fullscreen = 0;
                break;
            default:
                break;
            }
        }
        sub_452D80(921, 100);
        result = 1;
        break;
    case 16393:
        v7 = sub_46B0A0(a3);
        v8 = sub_46C720();
        switch (v7)
        {
        case 351:
            sub_486320(*(_DWORD * *)& byte_587000[127004], a4);
            if (v8 && *(int**)(v8 + 396) == a3)
                goto LABEL_76;
            if (a4)
            {
                if (sub_453070())
                    goto LABEL_75;
                v15 = *(_DWORD*)& byte_5D4594[1309728];
                v16 = *(void(__cdecl * *)(int, int, int, int))(*(_DWORD*)& byte_5D4594[1309728] + 372);
                if (!v16)
                    goto LABEL_75;
                goto LABEL_74;
            }
            if (sub_453070() != 1)
                goto LABEL_76;
            v14 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309728] + 372);
            if (!v14)
                goto LABEL_76;
            v14(*(_DWORD*)& byte_5D4594[1309728], 21, 28, 2);
            result = 0;
            break;
        case 352:
            sub_486320(*(_DWORD * *)& byte_587000[122852], a4);
            if (a4)
            {
                if (sub_44D990())
                    goto LABEL_49;
                v12 = *(void**)& byte_5D4594[1309732];
                v13 = *(void(__cdecl * *)(void*, int, int, int))(*(_DWORD*)& byte_5D4594[1309732] + 372);
                if (!v13)
                    goto LABEL_49;
                goto LABEL_48;
            }
            if (sub_44D990() != 1)
                goto LABEL_76;
            v11 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309732] + 372);
            if (!v11)
                goto LABEL_76;
            v11(*(_DWORD*)& byte_5D4594[1309732], 21, 28, 2);
            result = 0;
            break;
        case 353:
            sub_486320(*(_DWORD * *)& byte_587000[93164], a4);
            if (a4)
            {
                if (sub_43DC30())
                    goto LABEL_76;
                v10 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309736] + 372);
                if (!v10)
                    goto LABEL_76;
                v10(*(_DWORD*)& byte_5D4594[1309736], 21, 28, 2);
                result = 0;
            }
            else
            {
                if (sub_43DC30() != 1)
                    goto LABEL_76;
                v9 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309736] + 372);
                if (!v9)
                    goto LABEL_76;
                v9(*(_DWORD*)& byte_5D4594[1309736], 21, 28, 2);
                result = 0;
            }
            break;
        case 316: // gamma slider
            draw_gamma = 0.5 + a4 / 50.0f;
            break;
        case 318: // input sensitivity slider
            input_sensitivity = powf(10.0, a4 / 50.0f - 1.0);
            break;
        default:
            goto LABEL_76;
        }
        break;
    case 16396:
        v17 = sub_46B0A0(a3) - 351;
        if (v17)
        {
            if (v17 != 1)
                goto LABEL_76;
            sub_486320(*(_DWORD * *)& byte_587000[122852], a4);
            if (a4)
            {
                if (!sub_44D990())
                {
                    v12 = *(void**)& byte_5D4594[1309732];
                    v13 = *(void(__cdecl * *)(void*, int, int, int))(*(_DWORD*)& byte_5D4594[1309732] + 372);
                    if (v13)
                        LABEL_48:
                    v13(v12, 21, 28, 2);
                }
            LABEL_49:
                sub_4AA650();
                result = 0;
            }
            else
            {
                if (sub_44D990() != 1)
                    goto LABEL_76;
                v18 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309732] + 372);
                if (!v18)
                    goto LABEL_76;
                v18(*(_DWORD*)& byte_5D4594[1309732], 21, 28, 2);
                result = 0;
            }
        }
        else
        {
            sub_486320(*(_DWORD * *)& byte_587000[127004], a4);
            if (a4)
            {
                if (!sub_453070())
                {
                    v15 = *(_DWORD*)& byte_5D4594[1309728];
                    v16 = *(void(__cdecl * *)(int, int, int, int))(*(_DWORD*)& byte_5D4594[1309728] + 372);
                    if (v16)
                        LABEL_74:
                    v16(v15, 21, 28, 2);
                }
            LABEL_75:
                sub_452D80(768, 100);
                goto LABEL_76;
            }
            if (sub_453070() != 1)
                goto LABEL_76;
            v19 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309728] + 372);
            if (!v19)
                goto LABEL_76;
            v19(*(_DWORD*)& byte_5D4594[1309728], 21, 28, 2);
            result = 0;
        }
        break;
    default:
    LABEL_76:
        result = 0;
        break;
    }
    return result;
}
// 4AAEC8: variable 'v12' is possibly undefined

//----- (004AB0C0) --------------------------------------------------------
int sub_4AB0C0()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[1309740] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1309740]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309720]);
    v0();
    return 1;
}

//----- (004AB0F0) --------------------------------------------------------
int sub_4AB0F0()
{
    int result; // eax
    char v1[128]; // [esp+0h] [ebp-80h]

    if (sub_40A5C0(0x2000000) || !sub_4CB230("NoxLogo.vqa", v1))
    {
        if (!sub_4CC4E0())
        {
            sub_43DDD0(0);
            *(_DWORD*)& byte_5D4594[815132] = 0;
        }
        result = 1;
    }
    else
    {
        sub_4B0300(v1);
        sub_4B0640(sub_4CC4E0);
        sub_4B0340(0);
        result = 1;
    }
    return result;
}

//----- (004AB170) --------------------------------------------------------
int sub_4AB170()
{
    unsigned __int8 v0; // al
    int result; // eax
    char v2[128]; // [esp+0h] [ebp-80h]

    if ((sub_578DF0() & 0x80u) != 0 || sub_40A5C0(0x2000000) || !sub_4CB230("Intro.vqa", v2))
    {
        sub_4AB0F0();
        result = 1;
    }
    else
    {
        sub_4B0300(v2);
        sub_4B0640(sub_4AB0F0);
        sub_4B0340(1);
        v0 = sub_578DF0();
        sub_578DE0(v0 | 0x80);
        result = 1;
    }
    return result;
}

//----- (004AB1F0) --------------------------------------------------------
int sub_4AB1F0()
{
    int result; // eax
    char v1[128]; // [esp+0h] [ebp-80h]

    sub_43BDC0();
    if (sub_40A5C0(0x2000000) || !sub_4CB230("WWLogo.vqa", v1))
    {
        sub_4AB170();
        result = 1;
    }
    else
    {
        sub_4B0300(v1);
        sub_4B0640(sub_4AB170);
        sub_4B0340(0);
        result = 1;
    }
    return result;
}

//----- (004AB260) --------------------------------------------------------
int sub_4AB260()
{
    *(_DWORD*)& byte_5D4594[1309752] = sub_42F970("DisconnectIcon");
    *(_DWORD*)& byte_5D4594[1309756] = nox_window_new(
        0,
        136,
        nox_win_width - 50,
        nox_win_height / 2 + 3,
        50,
        50,
        0);
    sub_46AE60(*(int*)& byte_5D4594[1309756], *(int*)& byte_5D4594[1309752]);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1309756], 0, sub_4AB420, 0);
    *(_DWORD*)& byte_5D4594[1309748] = nox_new_window_from_file("discon.wnd", sub_4AB390);
    sub_46B300(*(int*)& byte_5D4594[1309748], sub_4AB340);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1309748], 0);
    sub_46A9B0(
        *(_DWORD * *)& byte_5D4594[1309748],
        nox_win_width / 2 - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309748] + 24) / 2,
        nox_win_height / 2 - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309748] + 28) / 2);
    return 1;
}

//----- (004AB340) --------------------------------------------------------
int __cdecl sub_4AB340(int a1, int a2, int a3, int a4)
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

//----- (004AB390) --------------------------------------------------------
int __cdecl sub_4AB390(int a1, int a2, int* a3, int a4)
{
    int v3; // eax
    int result; // eax

    if (a2 == 23)
        return 1;
    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3) - 576;
    if (!v3)
    {
        sub_43CF40();
        return 0;
    }
    if (v3 != 1)
        return 0;
    sub_446380();
    if (*(_DWORD*)& byte_5D4594[2650652] && sub_41E2F0() == 9)
    {
        sub_41F4B0();
        sub_41EC30();
        sub_446490(0);
        sub_44B000();
        sub_4AB4D0(0);
        result = 0;
    }
    else
    {
        sub_43B750();
        sub_4AB4D0(0);
        result = 0;
    }
    return result;
}

//----- (004AB420) --------------------------------------------------------
int __cdecl sub_4AB420(int* a1)
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

//----- (004AB470) --------------------------------------------------------
int sub_4AB470()
{
    int result; // eax

    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309748]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309756]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1309756] = 0;
    *(_DWORD*)& byte_5D4594[1309748] = 0;
    return result;
}

//----- (004AB4A0) --------------------------------------------------------
int __cdecl sub_4AB4A0(int a1)
{
    int result; // eax

    if (a1)
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1309756], 0);
    else
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1309756], 1);
    return result;
}

//----- (004AB4D0) --------------------------------------------------------
int __cdecl sub_4AB4D0(int a1)
{
    int result; // eax

    if (a1)
    {
        sub_44E040();
        nox_window_set_hidden(*(int*)& byte_5D4594[1309748], 0);
        sub_46A8C0(*(int*)& byte_5D4594[1309748]);
        sub_46C690(*(int*)& byte_5D4594[1309748]);
        sub_46B500(*(int*)& byte_5D4594[1309748]);
        result = sub_46ABB0(*(int*)& byte_5D4594[1309748], 1);
    }
    else
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1309748], 1);
        sub_46C6E0(*(int*)& byte_5D4594[1309748]);
        sub_46B500(0);
        result = sub_46ABB0(*(int*)& byte_5D4594[1309748], 0);
    }
    return result;
}

//----- (004AB560) --------------------------------------------------------
int __cdecl sub_4AB560(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[173328] = a1;
    return result;
}

//----- (004AB570) --------------------------------------------------------
int __cdecl sub_4AB570(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[173332] = a1;
    return result;
}

//----- (004AB580) --------------------------------------------------------
LPCSTR sub_4AB580()
{
    LPCSTR result; // eax

    if (nox_file_9)
        fclose(nox_file_9);
    result = *(LPCSTR*)& byte_5D4594[1309776];
    nox_file_9 = 0;
    *(_DWORD*)& byte_5D4594[1309764] = 0;
    *(_DWORD*)& byte_5D4594[1309784] = 0;
    *(_DWORD*)& byte_5D4594[1309780] = 0;
    *(_DWORD*)& byte_5D4594[1309772] = 0;
    *(_DWORD*)& byte_5D4594[1309768] = 0;
    *(_DWORD*)& byte_587000[173336] = 1;
    if (*(_DWORD*)& byte_5D4594[1309776])
        free(*(LPVOID*)& byte_5D4594[1309776]);
    return result;
}

//----- (004AB5E0) --------------------------------------------------------
int sub_4AB5E0()
{
    int v0; // esi
    unsigned __int8* v1; // eax
    int result; // eax
    int v3; // [esp+4h] [ebp-Ch]
    int v4; // [esp+8h] [ebp-8h]
    int v5; // [esp+Ch] [ebp-4h]

    v0 = 0;
    sub_467DF0(1);
    sub_4CC770();
    *(_DWORD*)& byte_587000[173328] = 1;
    *(_DWORD*)& byte_587000[173332] = 1;
    do
    {
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
        if (!v0)
        {
            sub_43CA50();
            v0 = 1;
        }
        if (*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu)
            sub_43CA20();
        mainloop_draw();
        sub_477830();
        sub_48A220();
        sub_4AD170_call_copy_backbuffer();
        sub_48A290_call_present();
        while (!sub_416CD0())
            ;
    } while (*(_DWORD*)& byte_587000[173328]);
    sub_4CC930();
    result = *(_DWORD*)& byte_587000[173332];
    if (*(_DWORD*)& byte_587000[173332])
    {
        sub_43BEB0_get_video_mode(&v3, &v5, &v4);
        if (!v3)
            sub_43BEF0_set_video_mode(default_win_width, default_win_height, v4);
        result = *(_DWORD*)& byte_587000[173332];
    }
    return result;
}
// 4AD170: using guessed type int sub_4AD170_call_copy_backbuffer(void);

//----- (004AB720) --------------------------------------------------------
int sub_4AB720()
{
    int v0; // esi
    int v1; // edi

    fclose(nox_file_9);
    _unlink(*(LPCSTR*)& byte_5D4594[1309776]);
    v0 = *(_DWORD*)& byte_5D4594[1309780];
    nox_file_9 = 0;
    *(_DWORD*)& byte_5D4594[1309764] = 0;
    *(_DWORD*)& byte_587000[173336] = 1;
    *(_DWORD*)& byte_5D4594[1309772] = 0;
    *(_DWORD*)& byte_5D4594[1309768] = 0;
    if (*(_DWORD*)& byte_5D4594[1309780])
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 12);
            free(*(LPVOID*)(v0 + 4));
            free((LPVOID)v0);
            v0 = v1;
        } while (v1);
    }
    if (*(_DWORD*)& byte_5D4594[1309776])
        free(*(LPVOID*)& byte_5D4594[1309776]);
    *(_DWORD*)& byte_5D4594[1309784] = 0;
    *(_DWORD*)& byte_5D4594[1309780] = 0;
    sub_4AB560(0);
    return sub_4AB570(1);
}

//----- (004AB7C0) --------------------------------------------------------
void __cdecl sub_4AB7C0(unsigned __int16 a1, void* a2, size_t a3)
{
    _DWORD* v3; // ebx
    void* v4; // eax
    unsigned __int16* v5; // esi
    int v6; // eax
    int v7; // eax

    //fprintf(stderr, "a1=%d, a2=%d, a3=%d, expected=%d\n", a1, a2, a3, *(_DWORD *)&byte_587000[173336]);

    if (a2 && a3)
    {
        if (a1 == *(_DWORD*)& byte_587000[173336])
        {
            fwrite(a2, a3, 1u, nox_file_9);
            *(_DWORD*)& byte_5D4594[1309768] += a3;
            ++* (_DWORD*)& byte_587000[173336];
        }
        else
        {
            v3 = nox_malloc(0x14u);
            if (v3)
            {
                v4 = nox_malloc(a3);
                v3[1] = v4;
                if (v4)
                {
                    qmemcpy(v4, a2, a3);
                    *(_WORD*)v3 = a1;
                    v3[2] = a3;
                    v3[3] = 0;
                    v3[4] = *(_DWORD*)& byte_5D4594[1309784];
                    if (*(_DWORD*)& byte_5D4594[1309784])
                        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1309784] + 12) = v3;
                    *(_DWORD*)& byte_5D4594[1309784] = v3;
                    if (!*(_DWORD*)& byte_5D4594[1309780])
                        * (_DWORD*)& byte_5D4594[1309780] = v3;
                }
            }
        }
        v5 = *(unsigned __int16**)& byte_5D4594[1309780];
        if (*(_DWORD*)& byte_5D4594[1309780])
        {
            do
            {
                if (*(_DWORD*)& byte_587000[173336] == *v5)
                {
                    fwrite(*((void**)v5 + 1), *((_DWORD*)v5 + 2), 1u, nox_file_9);
                    *(_DWORD*)& byte_5D4594[1309768] += *((_DWORD*)v5 + 2);
                    ++* (_DWORD*)& byte_587000[173336];
                    v6 = *((_DWORD*)v5 + 4);
                    if (v6)
                        * (_DWORD*)(v6 + 12) = *((_DWORD*)v5 + 3);
                    else
                        *(_DWORD*)& byte_5D4594[1309780] = *((_DWORD*)v5 + 3);
                    v7 = *((_DWORD*)v5 + 3);
                    if (v7)
                        * (_DWORD*)(v7 + 16) = *((_DWORD*)v5 + 4);
                    else
                        *(_DWORD*)& byte_5D4594[1309784] = *((_DWORD*)v5 + 4);
                    free(*((LPVOID*)v5 + 1));
                    free(v5);
                }
                v5 = (unsigned __int16*) * ((_DWORD*)v5 + 3);
            } while (v5);
        }
        //fprintf(stderr, "foo %d %d %d\n", *(_DWORD *)&byte_5D4594[1309764], *(_DWORD *)&byte_5D4594[1309768], *(_DWORD *)&byte_5D4594[1309772]);
        if (*(_DWORD*)& byte_5D4594[1309764] && *(unsigned int*)& byte_5D4594[1309768] >= *(unsigned int*)& byte_5D4594[1309772])
        {
            sub_4AB580();
            sub_4AB560(0);
            sub_4AB570(1);
            sub_4CC900(0x64u);
            sub_43CA80();
        }
        else
        {
            sub_4CC900((__int64)((double) * (unsigned int*)& byte_5D4594[1309768] / (double) * (int*)& byte_5D4594[1309772] * 100.0));
        }
    }
}

//----- (004AB9B0) --------------------------------------------------------
int __cdecl sub_4AB9B0(char* a1)
{
    int result; // eax
    CHAR FileName[256]; // [esp+8h] [ebp-100h]

    if (strchr(a1, 92))
    {
        strcpy(FileName, a1);
    }
    else
    {
        strcpy(FileName, "maps\\");
        strncat(FileName, a1, strlen(a1) - 4);
        *(_WORD*)& FileName[strlen(FileName)] = *(_WORD*)& byte_587000[173348];
        strcat(FileName, a1);
    }
    result = _access(FileName, 0);
    if (result != -1)
        result = DeleteFileA(FileName);
    return result;
}

//----- (004ABA90) --------------------------------------------------------
LPCSTR sub_4ABA90()
{
    LPCSTR result; // eax

    result = *(LPCSTR*)& byte_5D4594[1309764];
    if (*(_DWORD*)& byte_5D4594[1309764])
    {
        sub_43CAB0();
        if (nox_file_9)
            fclose(nox_file_9);
        sub_4AB9B0(*(char**)& byte_5D4594[1309776]);
        result = sub_4AB580();
    }
    return result;
}

//----- (004ABAD0) --------------------------------------------------------
int __cdecl sub_4ABAD0(char* a1, unsigned int a2)
{
    CHAR* v2; // edi
    unsigned __int8 v3; // cl
    char* v4; // ebx
    char* v5; // eax
    CHAR* v6; // edi
    unsigned __int8 v7; // cl
    char* v8; // edx
    int result; // eax
    int v10; // [esp+10h] [ebp-204h]
    CHAR v11[256]; // [esp+14h] [ebp-200h]
    CHAR PathName[256]; // [esp+114h] [ebp-100h]

    if (!a1 || a2 <= 0)
        return 0;
    *(_DWORD*)& byte_5D4594[1309764] = 1;
    *(_DWORD*)& byte_587000[173336] = 1;
    *(_DWORD*)& byte_5D4594[1309772] = a2;
    *(_DWORD*)& byte_5D4594[1309768] = 0;
    *(_DWORD*)& byte_5D4594[1309780] = 0;
    *(_DWORD*)& byte_5D4594[1309784] = 0;
    if (strchr(a1, 92))
    {
        strcpy(v11, "maps\\");
        v4 = strrchr(a1, 92) + 1;
        v5 = strrchr(a1, 46);
        if (!v4 || !v5)
            return 0;
        v10 = v5 - v4;
        strncat(v11, v4, v5 - v4);
        *(_WORD*)& v11[strlen(v11)] = *(_WORD*)& byte_587000[173380];
        strcpy(PathName, v11);
        strncat(v11, v4, v10);
        v6 = &v11[strlen(v11) + 1];
        v7 = byte_587000[173388];
        *(_DWORD*)--v6 = *(_DWORD*)& byte_587000[173384];
        v6[4] = v7;
        sub_409D70(v4);
    }
    else
    {
        sub_409D70(a1);
        strcpy(v11, "maps\\");
        strcat(v11, sub_409B40());
        *(_WORD*)& v11[strlen(v11)] = *(_WORD*)& byte_587000[173360];
        strcpy(PathName, v11);
        strcat(v11, sub_409B40());
        v2 = &v11[strlen(v11) + 1];
        v3 = byte_587000[173368];
        *(_DWORD*)--v2 = *(_DWORD*)& byte_587000[173364];
        v2[4] = v3;
    }
    sub_4AB9B0(a1);
    if (_access((LPCSTR)& byte_587000[173392], 0) == -1)
        CreateDirectoryA((LPCSTR)& byte_587000[173400], 0);
    if (_access(PathName, 0) == -1)
        CreateDirectoryA(PathName, 0);
    v8 = (char*)nox_malloc(strlen(v11) + 1);
    *(_DWORD*)& byte_5D4594[1309776] = v8;
    if (v8)
    {
        strcpy(v8, v11);
        nox_file_9 = fopen(*(const char**)& byte_5D4594[1309776], "wb");
        if (nox_file_9)
        {
            result = 1;
            *(_DWORD*)& byte_587000[173336] = 1;
            return result;
        }
    }
    return 0;
}

//----- (004ABDA0) --------------------------------------------------------
int __cdecl sub_4ABDA0(int a1, __int16 a2, __int16 a3, _DWORD* a4)
{
    int v4; // edi
    int result; // eax
    int v6; // esi
    unsigned int v7; // edx
    int v8; // eax
    float v9; // [esp-14h] [ebp-148h]
    char v10; // [esp+Fh] [ebp-125h]
    float v11; // [esp+10h] [ebp-124h]
    int v12; // [esp+14h] [ebp-120h]
    int v13[2]; // [esp+18h] [ebp-11Ch]
    float v14; // [esp+20h] [ebp-114h]
    int v15; // [esp+24h] [ebp-110h]
    int v16; // [esp+28h] [ebp-10Ch]
    float v17; // [esp+2Ch] [ebp-108h]
    int v18; // [esp+30h] [ebp-104h]
    char v19[256]; // [esp+34h] [ebp-100h]

    sub_426AC0(&v15, 4u);
    *a4 += 4;
    sub_426AC0(&v16, 4u);
    *a4 += 4;
    if (a3 < 40 || a2 < 4)
    {
        sub_426AC0(v13, 8u);
        *a4 += 8;
    }
    else
    {
        sub_426AC0(&v11, 4u);
        *a4 += 4;
        sub_426AC0(&v17, 4u);
        v9 = v11;
        *a4 += 4;
        v13[0] = sub_419A70(v9);
        v13[1] = sub_419A70(v17);
    }
    if (a3 >= 10)
    {
        sub_426AC0(&v12, 1u);
        ++* a4;
        sub_426AC0(v19, (unsigned __int8)v12);
        *a4 += (unsigned __int8)v12;
    }
    if (a3 >= 20)
    {
        sub_426AC0(&v10, 1u);
        ++* a4;
    }
    if (a3 >= 30)
    {
        sub_426AC0(&v12, 1u);
        ++* a4;
    }
    if (a3 >= 40)
    {
        sub_426AA0(4);
        *a4 += 4;
        if (a2 >= 2)
        {
            if (a2 < 5)
            {
                sub_426AC0(&v14, 4u);
                *a4 += 4;
                v11 = v14;
            }
            else
            {
                sub_426AC0(&v11, 2u);
                *a4 += 2;
            }
            v4 = (unsigned __int16)(4 * LOWORD(v11));
            sub_426AA0(v4);
            *a4 += v4;
        }
        if (a2 >= 3)
        {
            sub_426AC0(&v18, 4u);
            *a4 += 4;
        }
    }
    result = sub_45A360(a1, v13[0], v13[1]);
    v6 = result;
    if (result)
    {
        v7 = *(_DWORD*)(result + 120) & 0xEEBF7E9D;
        *(_DWORD*)(result + 120) = v7;
        *(_DWORD*)(result + 120) = v16 | v7;
        v8 = *(_DWORD*)(result + 280);
        LOBYTE(v8) = v8 & 0xA1;
        *(_DWORD*)(v6 + 280) = v8;
        *(_DWORD*)(v6 + 280) = v18 | v8;
        *(_DWORD*)(v6 + 128) = v15;
        *(_BYTE*)(v6 + 28) = v10;
        if (!sub_40A5C0(1) && *(_BYTE*)(v6 + 28) && (!(*(_DWORD*)(v6 + 112) & 0x10000000) || !sub_40A5C0(128)))
            sub_4191D0(*(_BYTE*)(v6 + 28), v6 + 24, 0, *(_DWORD*)(v6 + 128), 0);
        result = v6;
    }
    return result;
}

//----- (004AC020) --------------------------------------------------------
int __cdecl sub_4AC020(int a1, __int16 a2, _DWORD* a3)
{
    _DWORD* v3; // esi
    __int16 v4; // di
    __int16 v5; // ax
    bool v6; // cc
    int v7; // eax
    int result; // eax
    int v9; // edi
    bool v10; // zf
    int v11; // ecx
    int v12; // ebx
    char v13; // dl
    int v14; // ebx
    int v15; // ecx
    int v16; // eax
    int v17; // eax
    unsigned __int8 v18; // cl
    int v19; // [esp-30h] [ebp-60h]
    float v20; // [esp-24h] [ebp-54h]
    int v21; // [esp-14h] [ebp-44h]
    int v22; // [esp-4h] [ebp-34h]
    int v23; // [esp+Ch] [ebp-24h]
    int v24; // [esp+10h] [ebp-20h]
    int v25; // [esp+14h] [ebp-1Ch]
    int v26; // [esp+18h] [ebp-18h]
    int v27; // [esp+1Ch] [ebp-14h]
    int v28; // [esp+20h] [ebp-10h]
    int v29; // [esp+24h] [ebp-Ch]
    float v30; // [esp+28h] [ebp-8h]
    float v31; // [esp+2Ch] [ebp-4h]

    v3 = a3;
    v4 = a2;
    v5 = 1;
    v23 = 1;
    if (a2 < 40)
        return sub_4ABDA0(a1, v5, v4, v3);
    sub_426AC0(&v23, 2u);
    v5 = v23;
    v6 = (__int16)v23 < 61;
    *v3 += 2;
    if (v6)
        return sub_4ABDA0(a1, v5, v4, v3);
    sub_426AC0(&v25, 4u);
    *v3 += 4;
    sub_426AC0(&v29, 4u);
    *v3 += 4;
    sub_426AC0(&v30, 4u);
    *v3 += 4;
    sub_426AC0(&v31, 4u);
    v20 = v31;
    *v3 += 4;
    v22 = sub_419A70(v20);
    v7 = sub_419A70(v30);
    result = sub_45A360(a1, v7, v22);
    v9 = result;
    if (result)
    {
        *(_DWORD*)(result + 128) = v25;
        sub_426AC0(&a2, 1u);
        v10 = (_BYTE)a2 == 0;
        ++* v3;
        if (!v10)
        {
            sub_426AC0(&v26, 4u);
            v11 = v26;
            *v3 += 4;
            *(_DWORD*)(v9 + 120) = v11 | *(_DWORD*)(v9 + 120) & 0xEEBF7E9D;
            sub_426AC0(&a3, 1u);
            v12 = (unsigned __int8)a3;
            v21 = (unsigned __int8)a3;
            ++* v3;
            sub_426AA0(v21);
            *v3 += v12;
            sub_426AC0(&a1, 1u);
            v13 = a1;
            ++* v3;
            *(_BYTE*)(v9 + 28) = v13;
            sub_426AC0(&a3, 1u);
            ++* v3;
            sub_426AC0(&v27, 2u);
            v14 = 4 * (unsigned __int16)v27;
            v19 = 4 * (unsigned __int16)v27;
            *v3 += 2;
            sub_426AA0(v19);
            *v3 += v14;
            sub_426AC0(&v28, 4u);
            v15 = v28;
            *v3 += 4;
            v16 = *(_DWORD*)(v9 + 280);
            LOBYTE(v16) = v16 & 0xA1;
            *(_DWORD*)(v9 + 280) = v15 | v16;
            if ((__int16)v23 >= 63)
            {
                sub_426AA0(2);
                *v3 += 2;
                sub_426AC0(&v24, 4u);
                *v3 += 4;
                sub_426AA0(v24);
                *v3 += v24;
                sub_426AA0(4);
                *v3 += 4;
            }
            if ((__int16)v23 >= 64)
            {
                sub_426AA0(4);
                *v3 += 4;
            }
        }
        if (!sub_40A5C0(1))
        {
            v17 = *(_DWORD*)& byte_5D4594[1309788];
            if (!*(_DWORD*)& byte_5D4594[1309788])
            {
                v17 = sub_44CFC0((CHAR*)& byte_587000[173444]);
                *(_DWORD*)& byte_5D4594[1309788] = v17;
            }
            v18 = *(_BYTE*)(v9 + 28);
            if (v18)
            {
                if (*(_DWORD*)(v9 + 108) != v17)
                    sub_4191D0(v18, v9 + 24, 0, *(_DWORD*)(v9 + 128), 0);
            }
        }
        result = v9;
    }
    return result;
}

//----- (004AC2B0) --------------------------------------------------------
char* __cdecl sub_4AC2B0(char* a1)
{
    char* result; // eax
    char* v2; // eax
    int v3; // [esp+Ch] [ebp-628h]
    int v4; // [esp+10h] [ebp-624h]
    int v5; // [esp+14h] [ebp-620h]
    int v6; // [esp+18h] [ebp-61Ch]
    int v7; // [esp+1Ch] [ebp-618h]
    int v8; // [esp+20h] [ebp-614h]
    int v9[2]; // [esp+24h] [ebp-610h]
    char v11[256]; // [esp+2Ch] [ebp-608h]
    char v12[256]; // [esp+12Ch] [ebp-508h]
    char v13[256]; // [esp+22Ch] [ebp-408h]
    char FileName[260]; // [esp+32Ch] [ebp-308h]
    char v15[260]; // [esp+430h] [ebp-204h]
    char v16[256]; // [esp+534h] [ebp-100h]

    result = a1;
    v7 = 0;
    if (a1)
    {
        _splitpath(a1, &v3, v11, v13, v16);
        if (!strlen(v11))
        {
            strcpy(v11, *(const char**)& byte_587000[173412]);
            strcat(v11, *(const char**)& byte_587000[173420]);
            strcat(v11, v13);
        }
        _makepath(FileName, &v3, v11, v13, v16);
        if (_access(FileName, 0) == -1)
        {
            _makepath(v15, &v3, v11, v13, ".nxz");
            if (_access(v15, 0) == -1)
                return 0;
            result = (char*)sub_57BC50(v15, FileName);
            if (!result)
                return result;
        }
        result = (char*)sub_426910(FileName, 1, 19);
        if (!result)
            return result;
        sub_426AC0(&v5, 4u);
        if (v5 != -86065425)
        {
            if (v5 != -86050098)
            {
                sub_4269F0();
                return 0;
            }
            sub_426C20(&v7, 4u);
        }
        sub_426AC0(&v9[0], 4u);
        sub_426AC0(&v9[1], 4u);
        sub_426A80(v9);
        while (1)
        {
            sub_426AC0(&v6, 1u);
            if (!(_BYTE)v6)
                break;
            sub_426AC0(v12, (unsigned __int8)v6);
            sub_426C20(&v8, 4u);
            v4 = 0;
            if (!strcmp(v12, "ObjectData"))
            {
                sub_426F40(0, v12, &v4, (int(__cdecl*)(int))sub_4AC610);
            }
            else if (sub_40A5C0(1))
            {
                sub_426AA0(v8);
            }
            else
            {
                sub_426EA0(0, v12, &v4);
            }
            if (v4 == 1)
                return 0;
        }
        sub_4269F0();
        sub_4BAB30();
        nullsub_20();
        sub_4B64C0();
        sub_45AC40();
        sub_4C4FD0();
        sub_451100();
        sub_445FF0();
        sub_470680();
        sub_461520();
        sub_486060();
        v2 = sub_417040(*(int*)& byte_5D4594[2616328]);
        sub_422140((int)v2);
        sub_4DB230(0);
        if (*(int*)& byte_5D4594[3803228] < 0)
        {
            if (sub_461450() == 1)
            {
                sub_461400();
                sub_461440(0);
            }
            sub_470AA0(0);
        }
        result = (char*)1;
    }
    return result;
}
// 4BB9C0: using guessed type void nullsub_20(void);

//----- (004AC610) --------------------------------------------------------
int sub_4AC610()
{
    unsigned __int16 v1; // ax
    unsigned __int16 v2; // si
    int v3; // eax
    int v4; // [esp+4h] [ebp-Ch]
    int v5; // [esp+8h] [ebp-8h]
    int v6; // [esp+Ch] [ebp-4h]

    v6 = 1;
    sub_426AC0(&v6, 2u);
    if ((__int16)v6 > 1)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[3803300])
        return 0;
    sub_426AC0(&v4, 2u);
    if ((_WORD)v4)
    {
        while (1)
        {
            sub_426C20(&v5, 4u);
            v1 = sub_42C2B0(v4);
            v2 = v1;
            if (!v1)
                break;
            if (sub_44D090(v1))
            {
                v3 = sub_4AC6E0(v2);
                v5 -= v3;
            }
            if (v5 > 0)
                sub_426AA0(v5);
            sub_426AC0(&v4, 2u);
            if (!(_WORD)v4)
                return 1;
        }
        return 0;
    }
    return 1;
}

//----- (004AC6E0) --------------------------------------------------------
int __cdecl sub_4AC6E0(unsigned __int16 a1)
{
    if (!*(_DWORD*)& byte_5D4594[1309792])
    {
        *(_DWORD*)& byte_5D4594[1309792] = sub_44CFC0((CHAR*)& byte_587000[173476]);
        *(_DWORD*)& byte_5D4594[1309796] = sub_44CFC0((CHAR*)& byte_587000[173488]);
        *(_DWORD*)& byte_5D4594[1309800] = sub_44CFC0((CHAR*)& byte_587000[173508]);
        *(_DWORD*)& byte_5D4594[1309804] = sub_44CFC0((CHAR*)& byte_587000[173520]);
    }
    if (a1 == *(_DWORD*)& byte_5D4594[1309792] || a1 == *(_DWORD*)& byte_5D4594[1309796])
        return sub_4AC980(a1);
    if (a1 == *(_DWORD*)& byte_5D4594[1309800])
        return sub_4ACE00(a1);
    if (a1 == *(_DWORD*)& byte_5D4594[1309804])
        return sub_4ACEF0(a1);
    if (sub_44D060(a1))
        return sub_4AD040(a1);
    if (sub_44D040(a1))
        return sub_4AC7B0(a1);
    return 0;
}

//----- (004AC7B0) --------------------------------------------------------
int __cdecl sub_4AC7B0(int a1)
{
    int v1; // eax
    int v2; // esi
    int result; // eax
    int v4; // eax
    char v5; // al
    float v6; // edi
    int v7; // ecx
    double v9; // st7
    double v10; // st7
    int v11; // [esp+4h] [ebp-10h]
    int v12; // [esp+8h] [ebp-Ch]
    float v13; // [esp+Ch] [ebp-8h]
    int v14; // [esp+10h] [ebp-4h]

    sub_426AC0(&v12, 2u);
    v11 = 2;
    v1 = sub_4AC020(a1, v12, &v11);
    v2 = v1;
    if (v1)
    {
        v4 = *(_DWORD*)(v1 + 112);
        if ((v4 & 0x80u) == 0)
        {
            if (v4 & 0x200)
            {
                sub_426AC0(&a1, 4u);
                sub_426AC0(&v14, 4u);
                v9 = (double)a1;
                v11 += 8;
                v13 = v9;
                *(float*)(v2 + 56) = v9;
                v10 = (double)v14;
                *(float*)(v2 + 60) = v10;
                if (v13 > 60.0)
                    * (_DWORD*)(v2 + 56) = 1114636288;
                if (v10 > 60.0)
                    * (_DWORD*)(v2 + 60) = 1114636288;
                sub_428270((shape*)(v2 + 44));
            }
        }
        else
        {
            sub_426AC0(&v13, 4u);
            v11 += 4;
            sub_426AC0(&v14, 4u);
            v5 = v14;
            v11 += 4;
            *(_BYTE*)(v2 + 433) = v14;
            *(_BYTE*)(v2 + 432) = 0;
            if (v5)
                * (_BYTE*)(v2 + 432) = 1;
            v6 = v13;
            a1 = LODWORD(v13);
            if ((__int16)v12 >= 41)
            {
                sub_426AC0(&a1, 4u);
                v6 = *(float*)& a1;
                v11 += 4;
            }
            *(_BYTE*)(v2 + 299) = LOBYTE(v13);
            v7 = *(_DWORD*)(v2 + 12) + *(int*)& byte_587000[8 * LODWORD(v6) + 196184] / 2;
            sub_410390(
                v2,
                v7 / 23,
                (*(_DWORD*)(v2 + 16) + *(int*)& byte_587000[8 * LODWORD(v6) + 196188] / 2) / 23);
        }
        *(_DWORD*)(v2 + 288) = 0;
        sub_45A990(v2);
        result = v11;
    }
    else
    {
        sub_4356E0();
        result = 0;
    }
    return result;
}

//----- (004AC980) --------------------------------------------------------
int __cdecl sub_4AC980(int a1)
{
    int v1; // eax
    int v2; // esi
    unsigned __int16* v4; // edi
    _BYTE* v5; // eax
    _BYTE* v6; // ecx
    int v7; // [esp+Ch] [ebp-8h]
    int v8; // [esp+10h] [ebp-4h]

    sub_426AC0(&v8, 2u);
    v7 = 2;
    v1 = sub_4AC020(a1, v8, &v7);
    v2 = v1;
    if (!v1)
    {
        sub_4356E0();
        return 0;
    }
    if ((__int16)v8 >= 2)
    {
        sub_426AC0((_BYTE*)(v1 + 136), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 140), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 144), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 148), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 152), 0xCu);
        v4 = (unsigned __int16*)(v2 + 164);
        v7 += 12;
        sub_426AC0((_BYTE*)(v2 + 164), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 166), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 168), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 176), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 178), 0x30u);
        v7 += 48;
        sub_426AC0((_BYTE*)(v2 + 226), 0x10u);
        v7 += 16;
        sub_426AC0((_BYTE*)(v2 + 242), 0x10u);
        v7 += 16;
        sub_426AC0((_BYTE*)(v2 + 258), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 260), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 262), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 264), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 270), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 272), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 274), 1u);
        ++v7;
        if ((__int16)v8 > 40)
        {
            if ((__int16)v8 >= 42)
            {
                sub_426AC0((_BYTE*)(v2 + 172), 4u);
                v7 += 4;
            }
            else
            {
                sub_426AC0(&a1, 1u);
                ++v7;
                *(_DWORD*)(v2 + 172) = (unsigned __int8)a1;
            }
        }
    }
    else
    {
        sub_426AC0((_BYTE*)(v1 + 136), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 140), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 144), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 148), 4u);
        v7 += 4;
        sub_426AC0((_BYTE*)(v2 + 152), 0xCu);
        v4 = (unsigned __int16*)(v2 + 164);
        v7 += 12;
        sub_426AC0((_BYTE*)(v2 + 164), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 166), 2u);
        v7 += 2;
        sub_426AC0((_BYTE*)(v2 + 168), 4u);
        v7 += 4;
        *(_WORD*)(v2 + 176) = 0;
        *(_WORD*)(v2 + 258) = 0;
        *(_WORD*)(v2 + 260) = 0;
        *(_WORD*)(v2 + 262) = 0;
        *(_DWORD*)(v2 + 264) = 0;
        *(_WORD*)(v2 + 270) = 0;
        *(_BYTE*)(v2 + 274) = -128;
        if (*(_DWORD*)& byte_5D4594[3803300] != 1)
            goto LABEL_24;
        if (*(float*)(v2 + 140) <= 63.0
            && (double) * (int*)(v2 + 148) * *(double*)& byte_581450[9752] <= *(double*)& byte_581450[9744])
        {
        LABEL_13:
            *(_BYTE*)(v2 + 432) = 0;
            *(_BYTE*)(v2 + 433) = 0;
            *(_BYTE*)(v2 + 434) = 0;
            v5 = (_BYTE*)(v2 + 242);
            v6 = (_BYTE*)(v2 + 179);
            do
            {
                if (*(v6 - 1) || *v6 || v6[1])
                    ++* (_BYTE*)(v2 + 432);
                if (*(v5 - 16))
                    ++* (_BYTE*)(v2 + 433);
                if (*v5)
                    ++* (_BYTE*)(v2 + 434);
                v6 += 3;
                ++v5;
            } while ((int)& v5[-242 - v2] < 16);
            a1 = *v4;
            *(_WORD*)(v2 + 268) = (__int64)((double)a1 * *(double*)& byte_581450[9752] * *(double*)& byte_581450[9736]);
            goto LABEL_24;
        }
        sub_484CE0(v2 + 136, 63.0);
    }
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        goto LABEL_13;
LABEL_24:
    *(_DWORD*)(v2 + 288) = 0;
    sub_45A990(v2);
    return v7;
}

//----- (004ACE00) --------------------------------------------------------
int __cdecl sub_4ACE00(int a1)
{
    int v1; // eax
    int v2; // esi
    int result; // eax
    int i; // edi
    int v5; // eax
    int v6; // [esp+Ch] [ebp-10Ch]
    int v7; // [esp+10h] [ebp-108h]
    int v8; // [esp+14h] [ebp-104h]
    char v9[256]; // [esp+18h] [ebp-100h]

    sub_426AC0(&v8, 2u);
    v6 = 2;
    v1 = sub_4AC020(a1, v8, &v6);
    v2 = v1;
    if (v1)
    {
        *(_DWORD*)(v1 + 288) = 0;
        sub_45A990(v1);
        for (i = 0; i < 16; i += 4)
        {
            sub_426AC0(&v7, 1u);
            ++v6;
            sub_426AC0(v9, (unsigned __int8)v7);
            v6 += (unsigned __int8)v7;
            v9[(unsigned __int8)v7] = 0;
            v5 = sub_413290(v9);
            *(_DWORD*)(i + v2 + 432) = sub_413330(v5);
            *(_WORD*)(v2 + 448) = -1;
            *(_WORD*)(v2 + 450) = -1;
        }
        result = v6;
    }
    else
    {
        sub_4356E0();
        result = 0;
    }
    return result;
}
// 4ACE00: using guessed type char var_100[256];

//----- (004ACEF0) --------------------------------------------------------
int __cdecl sub_4ACEF0(int a1)
{
    int v1; // eax
    int v2; // edi
    int result; // eax
    _BYTE* v4; // esi
    int v5; // [esp+Ch] [ebp-10h]
    int v6; // [esp+10h] [ebp-Ch]
    int v7; // [esp+14h] [ebp-8h]
    _BYTE* v8; // [esp+18h] [ebp-4h]

    sub_426AC0(&v7, 2u);
    v5 = 2;
    v1 = sub_4AC020(a1, v7, &v5);
    v2 = v1;
    if (v1)
    {
        v4 = (_BYTE*)(v1 + 432);
        *(_DWORD*)(v1 + 288) = 0;
        sub_45A990(v1);
        sub_426AC0(&v6, 4u);
        *(float*)(v2 + 56) = (double)v6;
        v5 += 4;
        sub_426AC0(&v6, 4u);
        *(float*)(v2 + 60) = (double)v6;
        v5 += 4;
        sub_428270((shape*)(v2 + 44));
        v4[4] = 10;
        *v4 = 90;
        v4[1] = 90;
        v4[2] = 90;
        v4[3] = 10;
        v4[5] = 10;
        v8 = v4 + 5;
        if ((__int16)v7 >= 41)
        {
            sub_426AC0(v4, 1u);
            ++v5;
            sub_426AC0(v4 + 1, 1u);
            ++v5;
            sub_426AC0(v4 + 2, 1u);
            ++v5;
            sub_426AC0(v4 + 3, 1u);
            ++v5;
            sub_426AC0(v4 + 4, 1u);
            ++v5;
            sub_426AC0(v8, 1u);
            ++v5;
        }
        result = v5;
    }
    else
    {
        sub_4356E0();
        result = 0;
    }
    return result;
}

//----- (004AD040) --------------------------------------------------------
int __cdecl sub_4AD040(int a1)
{
    int v1; // esi
    int result; // eax
    int v3; // [esp+4h] [ebp-Ch]
    int v4; // [esp+8h] [ebp-8h]
    int v5; // [esp+Ch] [ebp-4h]

    sub_426AC0(&v4, 2u);
    v3 = 2;
    v1 = sub_4AC020(a1, v4, &v3);
    if (v1)
    {
        if ((__int16)v4 >= 61)
        {
            LOBYTE(a1) = 0;
            sub_426AC0(&v5, 4u);
            v3 += 4;
            sub_426AC0(&a1, 1u);
            ++v3;
            if ((_BYTE)a1 == 1)
                sub_459DD0(v1, 1);
        }
        *(_DWORD*)(v1 + 288) = 0;
        sub_45A990(v1);
        result = v3;
    }
    else
    {
        sub_4356E0();
        result = 0;
    }
    return result;
}

//----- (004AD320) --------------------------------------------------------
int __cdecl sub_4AD320(int a1)
{
    int v1; // esi
    _DWORD* v3; // eax
    _DWORD* v4; // esi
    _DWORD* v5; // esi
    _DWORD* v6; // edi
    char** v7; // esi
    wchar_t* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax

    v1 = *(_DWORD*)& byte_587000[26048];
    if (sub_43F320(0) > 10)
        v1 = 2;
    if (*(_DWORD*)& byte_5D4594[1309812])
        return 0;
    if (sub_43AF70() == 1)
        v3 = nox_new_window_from_file(*(const char**)& byte_587000[4 * v1 + 173596], sub_4AD5D0);
    else
        v3 = nox_new_window_from_file(*(const char**)& byte_587000[4 * v1 + 173556], sub_4AD5D0);
    *(_DWORD*)& byte_5D4594[1309812] = v3;
    sub_46B120(v3, a1);
    sub_46B340(*(int*)& byte_5D4594[1309812], sub_4AD570);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10306);
    if (sub_40A5C0(1056))
        sub_46ABB0((int)v4, 0);
    sub_46A8A0();
    sub_4AD840();
    if (sub_43AF70() == 1)
    {
        sub_4AD4B0();
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10310);
        sub_46B280((int)v5, *(int*)& byte_5D4594[1309812]);
        sub_46B2C0((int)v5, sub_4AD5D0);
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10317);
        v7 = (char**)& byte_587000[173540];
        do
        {
            v8 = loadString_sub_40F1D0(*v7, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c", 308);
            nox_window_call_field_94((int)v6, 16397, (int)v8, -1);
            ++v7;
        } while ((int)v7 < (int)& byte_587000[173556]);
    }
    else
    {
        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10319);
        nox_window_set_hidden((int)v9, 1);
    }
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
    {
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10304);
        sub_46ABB0((int)v10, 0);
    }
    return *(_DWORD*)& byte_5D4594[1309812];
}

//----- (004AD4B0) --------------------------------------------------------
int sub_4AD4B0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi
    int v2; // eax
    int v3; // edi
    char** v4; // ebx
    unsigned __int16* v5; // eax
    int result; // eax
    int v7; // edi
    int v8; // ecx
    int v9; // [esp+Ch] [ebp-4h]

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10317);
    v1 = v0;
    v2 = sub_43F320(v0[59]) + 1;
    v3 = 0;
    v4 = (char**)& byte_587000[173540];
    v1[7] = v1[5] + 4 * v2 + 2;
    v1[3] = 4 * v2 + 2;
    do
    {
        v5 = loadString_sub_40F1D0(*v4, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c", 92);
        sub_43F840(v1[59], v5, &v9, 0, 0);
        if (v9 > v3)
            v3 = v9;
        ++v4;
    } while ((int)v4 < (int)& byte_587000[173556]);
    result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10316)[2];
    v7 = v3 + 7;
    if (v7 <= result)
        v7 = result;
    v8 = v1[6];
    v1[2] = v7;
    v1[4] = v8 - v7;
    return result;
}

//----- (004AD570) --------------------------------------------------------
int sub_4AD570()
{
    int2* v0; // edi
    _DWORD* v1; // esi

    v0 = sub_4309F0();
    if (sub_43AF70() == 1)
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10317);
        if (!wndIsShown_sub_46ACC0((int)v1) && !sub_46AAB0(v1, v0->field_0, v0->field_4))
        {
            sub_46ADE0((int)v1);
            nox_window_set_hidden((int)v1, 1);
        }
    }
    return 1;
}

//----- (004AD5D0) --------------------------------------------------------
int __cdecl sub_4AD5D0(int a1, int a2, int* a3, int a4)
{
    _DWORD* v4; // ebx
    int v5; // eax
    int v6; // esi
    int v7; // eax
    int v8; // eax
    int v9; // esi
    _DWORD* v10; // eax
    int result; // eax
    int v12; // esi
    _DWORD* v13; // esi

    if (a2 == 16391)
    {
        v12 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        switch (v12)
        {
        case 10301:
            if (sub_40A5F0())
                sub_40A5E0(0);
            else
                sub_40A5E0(1);
            result = 0;
            break;
        case 10302:
            *(_DWORD*)& byte_587000[108752] ^= 1u;
            result = 0;
            break;
        case 10304:
            if (sub_4D0D70())
                sub_4D0D90(0);
            else
                sub_4D0D90(1);
            result = 0;
            break;
        case 10305:
            sub_409EF0(2);
            result = 0;
            break;
        case 10306:
            sub_409EF0(0x2000);
            if (sub_409F40(0x2000))
                goto LABEL_24;
            sub_4D7EA0();
            result = 0;
            break;
        case 10316:
            v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10317);
            nox_window_set_hidden((int)v13, 0);
            sub_46A8C0((int)v13);
            sub_46ADC0((int)v13);
            result = 0;
            break;
        case 10319:
            sub_4BDFD0();
            goto LABEL_24;
        default:
            goto LABEL_24;
        }
    }
    else if (a2 == 16393)
    {
        sub_40A6D0(4 - a4);
        result = 0;
    }
    else if (a2 != 16400
        || sub_46B0A0(a3) != 10317
        || (v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10316),
            v5 = nox_window_call_field_94((int)a3, 16404, 0, 0),
            v6 = v5,
            v5 < 0)
        || v5 >= *(__int16*)(a3[8] + 44))
    {
    LABEL_24:
        result = 0;
    }
    else
    {
        v7 = nox_window_call_field_94((int)a3, 16406, a4, 0);
        nox_window_call_field_94((int)v4, 16385, v7, -1);
        *(_DWORD*)& byte_5D4594[3596] = v6 + 1;
        v8 = sub_40A710(v6 + 1);
        sub_40A6D0(v8);
        v9 = 4 - sub_40A6C0();
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10312);
        nox_window_call_field_94((int)v10, 16394, v9, 0);
        nox_window_set_hidden((int)a3, 1);
        sub_46ADE0((int)a3);
        result = 0;
    }
    return result;
}

//----- (004AD820) --------------------------------------------------------
int sub_4AD820()
{
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309812]);
    *(_DWORD*)& byte_5D4594[1309812] = 0;
    return sub_4BE610();
}

//----- (004AD840) --------------------------------------------------------
int sub_4AD840()
{
    int result; // eax
    _DWORD* v1; // esi
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // esi
    wchar_t* v7; // eax
    _DWORD* v8; // esi
    int v9; // eax

    result = *(_DWORD*)& byte_5D4594[1309812];
    if (*(_DWORD*)& byte_5D4594[1309812])
    {
        if (sub_40A5F0())
        {
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10301);
            v1[9] |= 4u;
            if (sub_40A5C0(1024))
                sub_46ABB0((int)v1, 0);
        }
        if (*(_DWORD*)& byte_587000[108752])
        {
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10302);
            v2[9] |= 4u;
        }
        if (sub_4D0D70())
        {
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10304);
            v3[9] |= 4u;
        }
        if (sub_409F40(2))
        {
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10305);
            v4[9] |= 4u;
        }
        if (sub_409F40(0x2000))
        {
            v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10306);
            v5[9] |= 4u;
        }
        result = sub_43AF70();
        if (result == 1)
        {
            v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10316);
            v7 = loadString_sub_40F1D0(
                *(char**)& byte_587000[4 * *(_DWORD*)& byte_5D4594[3596] + 173536],
                0,
                "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\general.c",
                391);
            nox_window_call_field_94((int)v6, 16385, (int)v7, -1);
            v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309812], 10312);
            v9 = sub_40A6C0();
            result = nox_window_call_field_94((int)v8, 16394, 4 - v9, 0);
        }
    }
    return result;
}

//----- (004AD9B0) --------------------------------------------------------
int __cdecl sub_4AD9B0(int a1)
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1309820]))
        return 0;
    sub_413A00(0);
    sub_44D8F0();
    if (a1)
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1309820], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1309824], 1);
    }
    else
    {
        sub_433290((char*)& byte_587000[174124]);
        nox_window_set_hidden(*(int*)& byte_5D4594[1309820], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1309824], 1);
        sub_445C40();
    }
    return 1;
}

//----- (004ADA40) --------------------------------------------------------
int sub_4ADA40()
{
    int v0; // eax
    _DWORD* v1; // eax
    int v3; // [esp-4h] [ebp-4h]

    sub_413A00(1);
    sub_46A8C0(*(int*)& byte_5D4594[1309820]);
    sub_46A8C0(*(int*)& byte_5D4594[1309824]);
    sub_4CB330();
    v0 = sub_4766D0();
    if (v0 > 69)
    {
        if (v0 <= 79)
        {
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 312);
            goto LABEL_9;
        }
        if (v0 <= 89)
        {
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 313);
            goto LABEL_9;
        }
        v3 = 314;
    }
    else
    {
        v3 = 311;
    }
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], v3);
LABEL_9:
    if (v1)
        nox_window_call_field_94((int)v1, 16392, 0, 0);
    return sub_43FE20(15);
}

//----- (004ADAD0) --------------------------------------------------------
int sub_4ADAD0()
{
    int result; // eax
    _DWORD* v1; // esi
    char* v2; // eax
    int v3; // eax
    int v4; // ecx
    unsigned int v5; // ecx
    _DWORD* v6; // esi
    char* v7; // eax
    int v8; // eax
    int v9; // ecx
    unsigned int v10; // ecx
    _DWORD* v11; // esi
    char* v12; // eax
    int v13; // eax
    int v14; // ecx
    unsigned int v15; // ecx
    _DWORD* v16; // eax
    _DWORD* v17; // eax
    int i; // esi
    _DWORD* v19; // eax
    int v20; // eax
    int* v21; // esi
    _DWORD* v22; // eax
    int v23; // kr00_4
    _DWORD* v24; // eax
    char* v25; // [esp-Ch] [ebp-18h]
    char* v26; // [esp-Ch] [ebp-18h]
    char* v27; // [esp-Ch] [ebp-18h]
    char* v28; // [esp-8h] [ebp-14h]
    char* v29; // [esp-8h] [ebp-14h]
    char* v30; // [esp-8h] [ebp-14h]
    int v31; // [esp-8h] [ebp-14h]
    int v32; // [esp+0h] [ebp-Ch]
    int v33; // [esp+4h] [ebp-8h]
    int v34; // [esp+8h] [ebp-4h]

    result = nox_new_window_from_file("Options.wnd", sub_4ADF30);
    *(_DWORD*)& byte_5D4594[1309820] = result;
    if (result)
    {
        result = sub_4CB590(result);
        if (result)
        {
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 351);
            *(_DWORD*)(v1[100] + 8) = 24;
            *(_DWORD*)(v1[100] + 12) = 20;
            v28 = sub_42F970("OptionsVolumeSliderLit");
            v25 = sub_42F970("OptionsVolumeSliderLit");
            v2 = sub_42F970("OptionsVolumeSlider");
            sub_4B5700((int)v1, 0, 0, (int)v2, (int)v25, (int)v28);
            nox_window_call_field_94((int)v1, 16395, 0, 0x4000);
            nox_window_call_field_94((int)v1, 16394, *(_DWORD*)(*(_DWORD*)& byte_587000[127004] + 4) >> 16, 0);
            *(_DWORD*)& byte_5D4594[1309828] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 361);
            v3 = sub_453070();
            v4 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309828] + 36);
            if (v3 == 1)
                v5 = v4 | 4;
            else
                v5 = v4 & 0xFFFFFFFB;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309828] + 36) = v5;
            v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 352);
            *(_DWORD*)(v6[100] + 8) = 24;
            *(_DWORD*)(v6[100] + 12) = 20;
            v29 = sub_42F970("OptionsVolumeSliderLit");
            v26 = sub_42F970("OptionsVolumeSliderLit");
            v7 = sub_42F970("OptionsVolumeSlider");
            sub_4B5700((int)v6, 0, 0, (int)v7, (int)v26, (int)v29);
            nox_window_call_field_94((int)v6, 16395, 0, 0x4000);
            nox_window_call_field_94((int)v6, 16394, *(_DWORD*)(*(_DWORD*)& byte_587000[122852] + 4) >> 16, 0);
            *(_DWORD*)& byte_5D4594[1309836] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 362);
            v8 = sub_44D990();
            v9 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309836] + 36);
            if (v8 == 1)
                v10 = v9 | 4;
            else
                v10 = v9 & 0xFFFFFFFB;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309836] + 36) = v10;
            v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 353);
            *(_DWORD*)(v11[100] + 8) = 24;
            *(_DWORD*)(v11[100] + 12) = 20;
            v30 = sub_42F970("OptionsVolumeSliderLit");
            v27 = sub_42F970("OptionsVolumeSliderLit");
            v12 = sub_42F970("OptionsVolumeSlider");
            sub_4B5700((int)v11, 0, 0, (int)v12, (int)v27, (int)v30);
            nox_window_call_field_94((int)v11, 16395, 0, 0x4000);
            nox_window_call_field_94((int)v11, 16394, *(_DWORD*)(*(_DWORD*)& byte_587000[93164] + 4) >> 16, 0);
            *(_DWORD*)& byte_5D4594[1309832] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 363);
            v13 = sub_43DC30();
            v14 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309832] + 36);
            if (v13 == 1)
                v15 = v14 | 4;
            else
                v15 = v14 & 0xFFFFFFFB;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309832] + 36) = v15;
            sub_43BEB0_get_video_mode(&v32, &v34, &v33);
            if (v34 == 480)
                v31 = 321;
            else if (v34 == 576)
                v31 = 322;
            else
                v31 = 323;
            v16 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], v31);
            nox_window_call_field_94((int)v16, 16392, 1, 0);
            if (g_fullscreen)
                v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 333);
            else
                v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 334);
            nox_window_call_field_94((int)v17, 16392, 1, 0);
            nox_window_call_field_94(sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 316), 16394, (draw_gamma - 0.5f) * 50, 0);
            nox_window_call_field_94(sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 318), 16394, (log10f(input_sensitivity) + 1.0f) * 50, 0);
            for (i = 320; i <= 332; ++i)
            {
                v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], i);
                if (v19 && !(v19[9] & 4))
                    sub_46AD80((int)v19, 8);
            }
            *(_DWORD*)& byte_5D4594[1309824] = nox_window_new(0, 32, 0, 0, 1, 1, 0);
            v20 = *(_DWORD*)& byte_587000[174072];
            if (*(int*)& byte_587000[174072] != -1)
            {
                v21 = (int*)& byte_587000[174080];
                do
                {
                    v22 = nox_window_new(*(int*)& byte_5D4594[1309824], 0, v20, *(v21 - 1), *v21, v21[1], 0);
                    sub_46B340((int)v22, sub_4ADEF0);
                    v20 = v21[2];
                    v21 += 4;
                } while (v20 != -1);
            }
            v23 = nox_win_width - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1309820] + 8);
            sub_46A9B0(*(_DWORD * *)& byte_5D4594[1309820], v23 / 2, 0);
            sub_46A9B0(*(_DWORD * *)& byte_5D4594[1309824], v23 / 2, 0);
            v24 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1309820], 371);
            nox_window_set_hidden((int)v24, 0);
            nox_window_set_hidden(*(int*)& byte_5D4594[1309820], 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1309824], 1);
            result = 1;
        }
    }
    return result;
}

//----- (004ADEF0) --------------------------------------------------------
int __cdecl sub_4ADEF0(_DWORD* a1, int a2)
{
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60(a1, &xLeft, &yTop);
    sub_49CF10(xLeft, yTop, a1[2], a1[3]);
    return 1;
}

//----- (004ADF30) --------------------------------------------------------
int __cdecl sub_4ADF30(int a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // edi
    int v6; // esi
    void(__cdecl * v7)(_DWORD, int, int, int); // eax
    void(__cdecl * v8)(_DWORD, int, int, int); // eax
    void(__cdecl * v9)(_DWORD, int, int, int); // eax
    void* v10; // ecx
    void(__cdecl * v11)(void*, int, int, int); // eax
    void(__cdecl * v12)(_DWORD, int, int, int); // eax
    int v13; // ecx
    void(__cdecl * v14)(int, int, int, int); // eax
    int v15; // eax
    void(__cdecl * v16)(_DWORD, int, int, int); // eax
    void(__cdecl * v17)(_DWORD, int, int, int); // eax

    switch (a2)
    {
    case 16389:
        sub_452D80(920, 100);
        result = 1;
        break;
    case 16391:
        switch (sub_46B0A0(a3))
        {
        case 311:
            sub_476700(65, 0);
            break;
        case 312:
            sub_476700(75, 0);
            break;
        case 313:
            sub_476700(85, 0);
            break;
        case 314:
            sub_476700(100, 0);
            break;
        case 341:
            sub_4AD9B0(0);
            sub_445C40();
            sub_4C4260();
            break;
        case 361:
            if (sub_453070() == 1)
                sub_453050();
            else
                sub_453060();
            break;
        case 362:
            if (sub_44D990() == 1)
                sub_44D960();
            else
                sub_44D970();
            break;
        case 363:
            if (sub_43DC30() == 1)
            {
                sub_43DC00();
            }
            else
            {
                sub_43DC10();
                sub_486320(*(_DWORD * *)& byte_587000[93164], *(_DWORD*)(*(_DWORD*)& byte_587000[93164] + 4) >> 16);
            }
            break;
        case 371:
            sub_4AD9B0(0);
            break;
        default:
            break;
        }
        sub_452D80(921, 100);
        result = 1;
        break;
    case 16393:
        v5 = sub_46B0A0(a3);
        v6 = sub_46C720();
        switch (v5)
        {
        case 351:
            sub_486320(*(_DWORD * *)& byte_587000[127004], a4);
            if (v6 && *(int**)(v6 + 396) == a3)
                goto LABEL_64;
            if (a4)
            {
                if (sub_453070())
                    goto LABEL_63;
                v13 = *(_DWORD*)& byte_5D4594[1309828];
                v14 = *(void(__cdecl * *)(int, int, int, int))(*(_DWORD*)& byte_5D4594[1309828] + 372);
                if (!v14)
                    goto LABEL_63;
                goto LABEL_62;
            }
            if (sub_453070() != 1)
                goto LABEL_64;
            v12 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309828] + 372);
            if (!v12)
                goto LABEL_64;
            v12(*(_DWORD*)& byte_5D4594[1309828], 21, 28, 2);
            result = 0;
            break;
        case 352:
            sub_486320(*(_DWORD * *)& byte_587000[122852], a4);
            if (a4)
            {
                if (sub_44D990())
                    goto LABEL_37;
                v10 = *(void**)& byte_5D4594[1309836];
                v11 = *(void(__cdecl * *)(void*, int, int, int))(*(_DWORD*)& byte_5D4594[1309836] + 372);
                if (!v11)
                    goto LABEL_37;
                goto LABEL_36;
            }
            if (sub_44D990() != 1)
                goto LABEL_64;
            v9 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309836] + 372);
            if (!v9)
                goto LABEL_64;
            v9(*(_DWORD*)& byte_5D4594[1309836], 21, 28, 2);
            result = 0;
            break;
        case 353:
            sub_486320(*(_DWORD * *)& byte_587000[93164], a4);
            if (a4)
            {
                if (sub_43DC30())
                    goto LABEL_64;
                v8 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309832] + 372);
                if (!v8)
                    goto LABEL_64;
                v8(*(_DWORD*)& byte_5D4594[1309832], 21, 28, 2);
                result = 0;
            }
            else
            {
                if (sub_43DC30() != 1)
                    goto LABEL_64;
                v7 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309832] + 372);
                if (!v7)
                    goto LABEL_64;
                v7(*(_DWORD*)& byte_5D4594[1309832], 21, 28, 2);
                result = 0;
            }
            break;
        case 316: // gamma slider
            draw_gamma = 0.5 + a4 / 50.0f;
            break;
        case 318: // input sensitivity slider
            input_sensitivity = powf(10.0, a4 / 50.0f - 1.0);
            break;
        default:
            goto LABEL_64;
        }
        break;
    case 16396:
        v15 = sub_46B0A0(a3) - 351;
        if (v15)
        {
            if (v15 != 1)
                goto LABEL_64;
            sub_486320(*(_DWORD * *)& byte_587000[122852], a4);
            if (a4)
            {
                if (!sub_44D990())
                {
                    v10 = *(void**)& byte_5D4594[1309836];
                    v11 = *(void(__cdecl * *)(void*, int, int, int))(*(_DWORD*)& byte_5D4594[1309836] + 372);
                    if (v11)
                        LABEL_36:
                    v11(v10, 21, 28, 2);
                }
            LABEL_37:
                sub_4AA650();
                result = 0;
            }
            else
            {
                if (sub_44D990() != 1)
                    goto LABEL_64;
                v16 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309836] + 372);
                if (!v16)
                    goto LABEL_64;
                v16(*(_DWORD*)& byte_5D4594[1309836], 21, 28, 2);
                result = 0;
            }
        }
        else
        {
            sub_486320(*(_DWORD * *)& byte_587000[127004], a4);
            if (a4)
            {
                if (!sub_453070())
                {
                    v13 = *(_DWORD*)& byte_5D4594[1309828];
                    v14 = *(void(__cdecl * *)(int, int, int, int))(*(_DWORD*)& byte_5D4594[1309828] + 372);
                    if (v14)
                        LABEL_62:
                    v14(v13, 21, 28, 2);
                }
            LABEL_63:
                sub_452D80(768, 100);
                goto LABEL_64;
            }
            if (sub_453070() != 1)
                goto LABEL_64;
            v17 = *(void(__cdecl * *)(_DWORD, int, int, int))(*(_DWORD*)& byte_5D4594[1309828] + 372);
            if (!v17)
                goto LABEL_64;
            v17(*(_DWORD*)& byte_5D4594[1309828], 21, 28, 2);
            result = 0;
        }
        break;
    default:
    LABEL_64:
        result = 0;
        break;
    }
    return result;
}
// 4AE184: variable 'v10' is possibly undefined

//----- (004AE3B0) --------------------------------------------------------
int sub_4AE3B0()
{
    int result; // eax

    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1309820]);
    *(_DWORD*)& byte_5D4594[1309820] = 0;
    return result;
}

//----- (004AE3D0) --------------------------------------------------------
BOOL sub_4AE3D0()
{
    BOOL result; // eax

    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1309820]))
        result = sub_4C4280();
    else
        result = 1;
    return result;
}

//----- (004AE400) --------------------------------------------------------
int sub_4AE400()
{
    return 1;
}

//----- (004AE420) --------------------------------------------------------
int sub_4AE420()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[3798692] >= 3)
        sub_49F500(
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] - 24),
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] - 20));
    result = (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(1);
    if (result)
    {
        result = (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(1);
        if (result)
            result = (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(0);
    }
    return result;
}

//----- (004AE470) --------------------------------------------------------
int sub_4AE470()
{
    int result; // eax
    int v1; // edx
    unsigned __int16* v2; // eax
    unsigned __int16* v3; // ecx

    sub_4AEBD0();
    if (*(_DWORD*)& byte_5D4594[3798692] >= 3)
        sub_49F500(
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] - 24),
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] - 20));
    result = sub_4AEC20(1, 0);
    if (result)
    {
        result = sub_4AEC20(1, 0);
        if (result)
        {
            result = sub_4AEC20(0, 1);
            if (result)
            {
                v1 = *(_DWORD*)& byte_5D4594[3798636];
                for (result = *(_DWORD*)& byte_5D4594[3798640];
                    v1 <= *(int*)& byte_5D4594[3798640];
                    *(_DWORD*)& byte_5D4594[3798636] = v1)
                {
                    v2 = *(unsigned __int16**)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v1);
                    v3 = (unsigned __int16*) * ((_DWORD*)v2 + 1);
                    if (*((_DWORD*)v3 + 1))
                    {
                        (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(*v2, v1, *v3);
                        v1 = *(_DWORD*)& byte_5D4594[3798636];
                    }
                    result = *(_DWORD*)& byte_5D4594[3798640];
                    ++v1;
                }
            }
        }
    }
    return result;
}

//----- (004AE520) --------------------------------------------------------
int sub_4AE520()
{
    int result; // eax

    result = sub_4AEDF0();
    if (result)
    {
        sub_4AEE30();
        result = 1;
    }
    return result;
}

//----- (004AE540) --------------------------------------------------------
void sub_4AE540()
{
    if (*(_DWORD*)& byte_5D4594[3798632])
    {
        free(*(LPVOID*)& byte_5D4594[3798632]);
        *(_DWORD*)& byte_5D4594[3798632] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[3798644])
    {
        free(*(LPVOID*)& byte_5D4594[3798644]);
        *(_DWORD*)& byte_5D4594[3798644] = 0;
    }
}

//----- (004AE580) --------------------------------------------------------
int __cdecl sub_4AE580(int a1)
{
    if (*(_DWORD*)& byte_5D4594[3798692] >= a1)
        sub_49F500(
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * (*(_DWORD*)& byte_5D4594[3798692] - a1)),
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * (*(_DWORD*)& byte_5D4594[3798692] - a1) + 4));
    return sub_49E510(a1);
}

//----- (004AE5C0) --------------------------------------------------------
int __cdecl sub_4AE5C0(int a1)
{
    int v1; // edx
    int result; // eax
    int v3; // edi
    int v4; // eax
    char* v5; // ecx
    char* v6; // esi
    unsigned int v7; // edi
    unsigned __int16 v8; // ax
    unsigned __int16 v9; // cx
    char v10[16]; // [esp+0h] [ebp-10h]

    sub_4AE5E0(a1, 1);
    v1 = *(_DWORD*)& byte_5D4594[3798636];
    for (result = *(_DWORD*)& byte_5D4594[3798640];
        v1 <= *(int*)& byte_5D4594[3798640];
        *(_DWORD*)& byte_5D4594[3798636] = v1)
    {
        v3 = 0;
        v4 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v1);
        if (v4)
        {
            v5 = v10;
            do
            {
                ++v3;
                *(_WORD*)v5 = *(_WORD*)v4;
                v4 = *(_DWORD*)(v4 + 4);
                v5 += 2;
            } while (v4);
            if (v3 >= 2)
            {
                sub_48C5B0((__int16*)v10, v3);
                v6 = v10;
                v7 = (unsigned int)v3 >> 1;
                do
                {
                    v8 = *(_WORD*)v6;
                    v9 = *((_WORD*)v6 + 1);
                    v6 += 4;
                    (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(v8, *(_DWORD*)& byte_5D4594[3798636], v9);
                    --v7;
                } while (v7);
                v1 = *(_DWORD*)& byte_5D4594[3798636];
            }
        }
        result = *(_DWORD*)& byte_5D4594[3798640];
        ++v1;
    }
    return result;
}

//----- (004AE5E0) --------------------------------------------------------
BOOL __cdecl sub_4AE5E0(int a1, int a2)
{
    int v2; // esi

    v2 = a1;
    if (*(_DWORD*)& byte_5D4594[3798692] >= a1)
        sub_49F500(
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * (*(_DWORD*)& byte_5D4594[3798692] - a1)),
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * (*(_DWORD*)& byte_5D4594[3798692] - a1) + 4));
    if (a2)
        sub_4AEBD0();
    if (a1 <= 1)
        return sub_4AEC20(0, 1) != 0;
    while (sub_4AEC20(1, 0))
    {
        if (--v2 <= 1)
            return sub_4AEC20(0, 1) != 0;
    }
    return 0;
}

//----- (004AE6F0) --------------------------------------------------------
int __cdecl sub_4AE6F0(int a1, int a2, int a3, int a4, int a5)
{
    int result; // eax
    int v6; // ecx
    int v7; // ebp
    int v8; // edi
    int v9; // ebx
    void(__cdecl * v10)(int, int, int); // edi
    int v11; // ebp
    int v12; // edx
    int v13; // esi
    unsigned __int16* v14; // ebx
    unsigned __int16* v15; // ecx
    unsigned __int16 v16; // ax
    unsigned __int16* v17; // ebx
    unsigned __int16* v18; // ecx
    unsigned __int16 v19; // ax
    unsigned __int16* v20; // ebx
    unsigned __int16* v21; // ecx
    unsigned __int16 v22; // ax
    int v23; // eax
    unsigned __int16* v24; // ebx
    unsigned __int16* v25; // ecx
    unsigned __int16 v26; // ax
    bool v27; // cc
    int v28; // [esp-14h] [ebp-38h]
    int v29; // [esp-10h] [ebp-34h]
    int v30; // [esp+4h] [ebp-20h]
    int v31; // [esp+8h] [ebp-1Ch]
    int v32; // [esp+Ch] [ebp-18h]
    int v33; // [esp+10h] [ebp-14h]
    int v34; // [esp+14h] [ebp-10h]
    int v35; // [esp+18h] [ebp-Ch]
    int v36; // [esp+1Ch] [ebp-8h]
    int v37; // [esp+20h] [ebp-4h]
    int v38; // [esp+2Ch] [ebp+8h]
    int v39; // [esp+30h] [ebp+Ch]
    int v40; // [esp+34h] [ebp+10h]
    int v41; // [esp+38h] [ebp+14h]

    v31 = 1 - a3;
    v35 = 0;
    v37 = a3;
    v34 = 3;
    v32 = 5 - 2 * a3;
    result = sub_434460(a5);
    v6 = a4;
    if (a4 < 0)
    {
        v6 = 0;
    LABEL_4:
        v7 = (a3 * *(int*)& byte_5D4594[4 * (256 - v6) + 1310096]) >> 16;
        v30 = (a3 * *(int*)& byte_5D4594[4 * (256 - v6) + 1310096]) >> 16;
        v8 = (a3 * *(int*)& byte_5D4594[4 * (256 - v6) + 1309840]) >> 16;
        sub_4AEBD0();
        v9 = a2;
        v41 = a2 - a3;
        sub_49F500(a1, a2 - a3);
        sub_49F500(a1, a2);
        sub_4AEC20(0, 0);
        sub_49F500(a1, a2);
        sub_49F500(a1 + v7, a2 + v8);
        sub_4AEC20(0, 1);
        v10 = *(void(__cdecl * *)(int, int, int)) & byte_5D4594[3798708];
        if (!ptr_5D4594_3799572->data[13])
            v10 = *(void(__cdecl * *)(int, int, int)) & byte_5D4594[3798720];
        v11 = a2 + a3;
        v12 = a2 - a3;
        v38 = 0;
        v39 = v9;
        v40 = v9;
        v36 = 4 * v9;
        v33 = 4 * v41;
        v13 = a1 - v9;
        while (1)
        {
            if (v38)
            {
                if (v12 < *(int*)& byte_5D4594[3798636] || v12 > * (int*)& byte_5D4594[3798640])
                {
                    if (v30 <= 0)
                        v10(v13 + v40, v12, v13 + v39);
                }
                else
                {
                    v14 = *(unsigned __int16**)(v33 + *(_DWORD*)& byte_5D4594[3798632]);
                    v15 = (unsigned __int16*) * ((_DWORD*)v14 + 1);
                    if (v15)
                    {
                        if (*v14 > * v15)
                        {
                            v16 = *v14;
                            *v14 = *v15;
                            *v15 = v16;
                        }
                        if (v30 > 0)
                        {
                            v10(*v14, v41, **((unsigned __int16**)v14 + 1));
                        }
                        else
                        {
                            v10(v13 + v40, v41, *v14);
                            v10(**((unsigned __int16**)v14 + 1), v41, v13 + v39);
                        }
                    }
                    else
                    {
                        v10(*v14, v12, v13 + v39);
                    }
                }
            }
            if (v35)
            {
                if (v40 < *(int*)& byte_5D4594[3798636] || v40 >= *(int*)& byte_5D4594[3798640])
                {
                    if (v30 <= 0)
                        v10(v13 + v41, v40, v13 + v11);
                }
                else
                {
                    v17 = *(unsigned __int16**)(v36 + *(_DWORD*)& byte_5D4594[3798632]);
                    v18 = (unsigned __int16*) * ((_DWORD*)v17 + 1);
                    if (v18)
                    {
                        if (*v17 > * v18)
                        {
                            v19 = *v17;
                            *v17 = *v18;
                            *v18 = v19;
                        }
                        if (v30 > 0)
                        {
                            v10(*v17, v40, **((unsigned __int16**)v17 + 1));
                        }
                        else
                        {
                            v10(v13 + v41, v40, *v17);
                            v10(**((unsigned __int16**)v17 + 1), v40, v13 + v11);
                        }
                    }
                    else
                    {
                        v10(*v17, v40, v13 + v11);
                    }
                }
            }
            if (v39 >= *(int*)& byte_5D4594[3798636] && v39 < *(int*)& byte_5D4594[3798640])
                break;
            if (v30 <= 0)
            {
                v29 = v13 + v11;
                v28 = v39;
                v23 = v13 + v41;
            LABEL_42:
                v10(v23, v28, v29);
            }
        LABEL_43:
            if (v38)
            {
                if (v11 < *(int*)& byte_5D4594[3798636] || v11 > * (int*)& byte_5D4594[3798640])
                {
                    if (v30 <= 0)
                        v10(v13 + v40, v11, v13 + v39);
                }
                else
                {
                    v24 = *(unsigned __int16**)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v11);
                    v25 = (unsigned __int16*) * ((_DWORD*)v24 + 1);
                    if (v25)
                    {
                        if (*v24 > * v25)
                        {
                            v26 = *v24;
                            *v24 = *v25;
                            *v25 = v26;
                        }
                        if (v30 > 0)
                        {
                            v10(*v24, v11, **((unsigned __int16**)v24 + 1));
                        }
                        else
                        {
                            v10(v13 + v40, v11, *v24);
                            v10(**((unsigned __int16**)v24 + 1), v11, v13 + v39);
                        }
                    }
                    else
                    {
                        v10(*v24, v11, v13 + v39);
                    }
                }
            }
            if ((int)v31 >= 0)
            {
                v31 += v32;
                v33 += 4;
                v12 = v41 + 1;
                v32 += 4;
                v38 = 1;
                --v37;
                ++v41;
                --v11;
            }
            else
            {
                v31 += v34;
                v12 = v41;
                v32 += 2;
                v38 = 0;
            }
            v34 += 2;
            result = v35 + 1;
            ++v39;
            v36 -= 4;
            v27 = v37 < ++v35;
            --v40;
            if (v27)
                return result;
        }
        v20 = *(unsigned __int16**)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v39);
        v21 = (unsigned __int16*) * ((_DWORD*)v20 + 1);
        if (v21)
        {
            if (*v20 > * v21)
            {
                v22 = *v20;
                *v20 = *v21;
                *v21 = v22;
            }
            if (v30 > 0)
            {
                v10(*v20, v39, **((unsigned __int16**)v20 + 1));
            }
            else
            {
                v10(v13 + v41, v39, *v20);
                v10(**((unsigned __int16**)v20 + 1), v39, v13 + v11);
            }
            goto LABEL_43;
        }
        v29 = v13 + v11;
        v28 = v39;
        v23 = *v20;
        goto LABEL_42;
    }
    if (a4 < 256)
        goto LABEL_4;
    return result;
}

//----- (004AEBD0) --------------------------------------------------------
int sub_4AEBD0()
{
    int v0; // eax
    int result; // eax

    *(_DWORD*)& byte_5D4594[3798648] = *(_DWORD*)& byte_5D4594[3798644];
    v0 = 0;
    *(_DWORD*)& byte_5D4594[3798640] = 0;
    for (*(_DWORD*)& byte_5D4594[3798636] = 0;
        *(_DWORD*)& byte_5D4594[3798636] < nox_backbuffer_height;
        ++ * (_DWORD*)& byte_5D4594[3798636])
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v0) = 0;
        v0 = *(_DWORD*)& byte_5D4594[3798636] + 1;
    }
    result = v0 - 1;
    *(_DWORD*)& byte_5D4594[3798636] = result;
    return result;
}

//----- (004AEC20) --------------------------------------------------------
int __cdecl sub_4AEC20(int a1, int a2)
{
    int result; // eax
    int v3; // eax
    int v4; // ecx
    int v5; // eax
    int v6; // ebx
    int v7; // esi
    int v8; // edi
    int v9; // edx
    int v10; // [esp+0h] [ebp-10h]
    int v11; // [esp+4h] [ebp-Ch]
    int v12; // [esp+8h] [ebp-8h]
    int v13; // [esp+Ch] [ebp-4h]

    result = sub_49F5B0(&v12, &v13, 0);
    if (result)
    {
        result = sub_49F5B0(&v10, &v11, a1);
        if (result)
        {
            if (sub_49FC20(&v10, &v11, &v12, &v13))
            {
                v3 = v12 - v10;
                v10 <<= 16;
                v4 = v11;
                v5 = v3 << 16;
                if (v11 > v13)
                {
                    v6 = -1;
                    v7 = v11 - v13;
                    v5 /= v11 - v13;
                    if (v13 < *(int*)& byte_5D4594[3798636])
                        * (_DWORD*)& byte_5D4594[3798636] = v13;
                    if (v11 > * (int*)& byte_5D4594[3798640])
                        * (_DWORD*)& byte_5D4594[3798640] = v11;
                }
                else
                {
                    v6 = 1;
                    v7 = v13 - v11;
                    if (v13 != v11)
                        v5 /= v7;
                    if (v11 < *(int*)& byte_5D4594[3798636])
                        * (_DWORD*)& byte_5D4594[3798636] = v11;
                    if (v13 > * (int*)& byte_5D4594[3798640])
                        * (_DWORD*)& byte_5D4594[3798640] = v13;
                }
                if (v7 > 0)
                {
                    do
                    {
                        v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v4);
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v4) = *(_DWORD*)& byte_5D4594[3798648];
                        **(_WORD * *)& byte_5D4594[3798648] = HIWORD(v10);
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798648] + 4) = v8;
                        *(_DWORD*)& byte_5D4594[3798648] += 8;
                        v4 = v6 + v11;
                        --v7;
                        v10 += v5;
                        v11 += v6;
                    } while (v7);
                }
                if (a2)
                {
                    v9 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v4);
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798632] + 4 * v4) = *(_DWORD*)& byte_5D4594[3798648];
                    **(_WORD * *)& byte_5D4594[3798648] = v12;
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798648] + 4) = v9;
                    *(_DWORD*)& byte_5D4594[3798648] += 8;
                }
                result = 1;
            }
            else
            {
                result = 1;
            }
        }
    }
    return result;
}

//----- (004AEDA0) --------------------------------------------------------
int __cdecl sub_4AEDA0(int* a1, int* a2, int a3, int a4)
{
    int result; // eax

    result = a3;
    if (a3 >= 0)
    {
        if (a3 > 256)
            result = 256;
    }
    else
    {
        result = 0;
    }
    if (a1)
        * a1 = (a4 * *(int*)& byte_5D4594[4 * result + 1310096]) >> 16;
    if (a2)
    {
        result = (a4 * *(int*)& byte_5D4594[4 * result + 1309840]) >> 16;
        *a2 = result;
    }
    return result;
}

//----- (004AEDF0) --------------------------------------------------------
void* sub_4AEDF0()
{
    void* result; // eax

    result = nox_malloc(4 * nox_backbuffer_height);
    *(_DWORD*)& byte_5D4594[3798632] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[3798644] = nox_malloc(nox_backbuffer_height << 6);
        result = (void*)(*(_DWORD*)& byte_5D4594[3798644] != 0);
    }
    return result;
}

//----- (004AEE30) --------------------------------------------------------
__int64 sub_4AEE30()
{
    int v0; // edi
    unsigned __int8* v1; // esi
    __int64 result; // rax

    v0 = 0;
    v1 = &byte_5D4594[1309840];
    do
    {
        result = (__int64)(sin((double)(v0 + 192) * *(double*)& byte_581450[9768] * *(double*)& byte_581450[9760])
            * *(double*)& byte_581450[9552]);
        *(_DWORD*)v1 = result;
        v1 += 4;
        ++v0;
    } while ((int)v1 < (int)& byte_5D4594[1311120]);
    return result;
}

//----- (004AEE80) --------------------------------------------------------
int sub_4AEE80()
{
    return 1;
}

//----- (004AEEA0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AEEA0(unsigned __int8** a1)
{
    unsigned __int8* result; // eax

    sub_4AF8C0(a1);
    result = a1[1];
    if (result)
    {
        sub_4AF890(a1);
        result = (unsigned __int8*)sub_4AF690(a1, (void(__cdecl*)(_DWORD*, _DWORD*, int))sub_4AEED0);
    }
    return result;
}

//----- (004AEED0) --------------------------------------------------------
char* __cdecl sub_4AEED0(int* a1, int a2, int a3)
{
    int v3; // eax
    int* v4; // edi
    int v5; // esi
    int v6; // eax
    char* result; // eax
    char* v8; // esi
    int v9; // eax

    sub_433F10(0xFFu, 0x80u, 0x20u);
    v3 = sub_48C5E0(2, 3);
    sub_434080(v3);
    v4 = sub_4B0680(0, 0xFFu);
    v5 = sub_48C5E0(0, 40);
    v6 = sub_48C5E0(0, a1[7]);
    result = sub_4AF990(a2, a3 + v5, v5, v6);
    v8 = result;
    if (result)
    {
        sub_4AFB00((int)result, (int)v4);
        sub_4AFB10((int)v8, *a1);
        sub_4AFB90((int)v8, 50);
        LOWORD(v9) = sub_48C610();
        sub_4AFBD0((int)v8, v9);
        sub_4AFC50((int)v8, -32768);
        result = (char*)sub_4AFC60((int)v8, 45875, 1);
    }
    return result;
}
// 4AEF5A: variable 'v9' is possibly undefined

//----- (004AEF80) --------------------------------------------------------
int __cdecl sub_4AEF80(int* a1)
{
    int* v1; // edi
    int v2; // ebp
    int v3; // ecx
    int result; // eax
    char* v5; // esi
    int v6; // eax
    int v7; // eax
    int v8; // [esp+8h] [ebp-4h]
    int v9; // [esp+10h] [ebp+4h]

    v1 = a1;
    v2 = *(_DWORD*)(*a1 + 12);
    v8 = *(_DWORD*)(*a1 + 16);
    sub_434430(255, 255, 255);
    v3 = a1[5];
    result = v3 - 1;
    if (v3)
    {
        v9 = a1[5];
        do
        {
            v5 = sub_4AF990(v2, v8, 0, 128);
            if (v5)
            {
                *((_DWORD*)v5 + 17) = sub_48C5E0(-256, 256);
                *((_DWORD*)v5 + 18) = 0;
                *((_DWORD*)v5 + 19) = 0;
                sub_4AFB10((int)v5, *v1);
                v6 = sub_48C5E0(0, 128);
                sub_4AFB90((int)v5, v6);
                sub_4AFB50((int)v5, 2);
                LOWORD(v7) = sub_48C610();
                sub_4AFBE0((int)v5, -16384 - (v7 >> 2));
                sub_4AFB60((int)v5, sub_4AF060);
            }
            result = --v9;
        } while (v9);
    }
    return result;
}
// 4AF01E: variable 'v7' is possibly undefined

//----- (004AF060) --------------------------------------------------------
int __cdecl sub_4AF060(int a1)
{
    int result; // eax
    int v2; // edi
    int v3; // ecx
    int v4; // ebx
    int v5; // ebp
    int v6; // ecx
    int v7; // ecx
    int v8; // edx
    int v9; // edx
    int v10; // ecx
    int v11; // esi
    int v12; // ecx

    result = a1;
    v2 = *(_DWORD*)(a1 + 48);
    if (v2 >= 0)
    {
        v3 = *(_DWORD*)(a1 + 44);
        ++* (_DWORD*)(a1 + 40);
        if (v3)
        {
            *(_DWORD*)(a1 + 44) = v3 - 1;
        }
        else
        {
            v4 = *(_DWORD*)(a1 + 84);
            v5 = *(_DWORD*)(a1 + 96);
            v6 = *(_DWORD*)(a1 + 72);
            if ((int) * (_DWORD*)(a1 + 68) >= 0)
                v7 = v6 - 4;
            else
                v7 = v6 + 4;
            v8 = *(_DWORD*)(a1 + 68);
            *(_DWORD*)(a1 + 72) = v7;
            v9 = v7 + v8;
            *(_DWORD*)(a1 + 68) = v9;
            v10 = v9 * *(_DWORD*)(a1 + 76);
            v11 = *(_DWORD*)(a1 + 28);
            *(_DWORD*)(a1 + 76) += 256;
            v12 = (v11 << 16) + (v10 >> 2);
            *(_DWORD*)(a1 + 48) = v2 - 1;
            if (v2 - 1 >= 0)
            {
                *(_DWORD*)(a1 + 84) = v4 + v5;
                *(_DWORD*)(a1 + 80) = v12;
            }
            else
            {
                result = (*(int(__cdecl * *)(int))(a1 + 132))(a1);
            }
        }
    }
    return result;
}

//----- (004AF0F0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AF0F0(unsigned __int8** a1)
{
    unsigned __int8** v1; // ebp
    unsigned __int8* result; // eax
    unsigned __int8** v3; // ecx
    __int64 v4; // rax
    int v5; // kr00_4
    unsigned __int8* v6; // ecx
    int v7; // ebx
    int v8; // eax
    int v9; // eax
    char* v10; // eax
    int v11; // esi
    char* v12; // [esp-10h] [ebp-28h]
    int v13; // [esp-8h] [ebp-20h]
    unsigned __int8* v14; // [esp+Ch] [ebp-Ch]
    int v15; // [esp+10h] [ebp-8h]
    int v16; // [esp+14h] [ebp-4h]

    v1 = a1;
    sub_4AF8C0(a1);
    result = v1[1];
    if (result)
    {
        sub_4AF890(v1);
        v3 = (unsigned __int8**)v1[4];
        v14 = v1[3];
        a1 = v3;
        sub_47D5C0((int)v1[1], &v14, &a1, &v15, &v16);
        v4 = v15;
        v5 = v4;
        result = (unsigned __int8*)(v4 - HIDWORD(v4));
        v6 = v1[5];
        v7 = (int)(v6 - 1);
        if (v6)
        {
            do
            {
                if (v7 & 1)
                    sub_434460(*(int*)& byte_5D4594[2523948]);
                else
                    sub_434460(*(int*)& byte_5D4594[2589772]);
                v13 = (int)v1[7];
                v8 = sub_48C5E0(-8, -2);
                v12 = (char*)a1 + v8;
                v9 = sub_48C5E0((int)& v14[v5 / 2], (int)& v14[v15]);
                v10 = sub_4AF990(v9, (int)v12, 0, v13);
                v11 = (int)v10;
                if (v10)
                {
                    sub_4AFB50((int)v10, 2);
                    sub_4AFB10(v11, (int)* v1);
                    *(_DWORD*)(v11 + 68) = sub_48C5E0(v5 / -2, v5 / 2);
                    *(_DWORD*)(v11 + 72) = 0;
                    sub_4AFB60(v11, sub_4AF200);
                }
                result = (unsigned __int8*)v7--;
            } while (result);
        }
    }
    return result;
}

//----- (004AF200) --------------------------------------------------------
int __cdecl sub_4AF200(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // ecx
    _DWORD* v4; // ecx
    int v5; // edx
    int v6; // ecx
    int v7; // ecx
    int v8; // edi
    int v9; // edi
    int v10; // edx

    result = a1;
    v2 = *(_DWORD*)(a1 + 48);
    if (v2 >= 0)
    {
        v3 = *(_DWORD*)(a1 + 44);
        ++* (_DWORD*)(a1 + 40);
        if (v3)
        {
            *(_DWORD*)(a1 + 44) = v3 - 1;
        }
        else
        {
            if (*(_BYTE*)(a1 + 56) & 4)
            {
                v4 = *(_DWORD * *)(a1 + 8);
                if (v4)
                {
                    v5 = v4[4] - v4[9];
                    *(_DWORD*)(a1 + 28) += v4[3] - v4[8];
                    *(_DWORD*)(a1 + 32) += v5;
                }
            }
            v6 = *(_DWORD*)(a1 + 72);
            if ((int) * (_DWORD*)(a1 + 68) >= 0)
                v7 = v6 - 1;
            else
                v7 = v6 + 1;
            v8 = *(_DWORD*)(a1 + 68);
            *(_DWORD*)(a1 + 72) = v7;
            v9 = v7 + v8;
            *(_DWORD*)(a1 + 68) = v9;
            *(_DWORD*)(a1 + 48) = v2 - 1;
            if (v2 - 1 >= 0)
            {
                v10 = *(_DWORD*)(a1 + 32) << 16;
                *(_DWORD*)(a1 + 80) = (v9 + *(_DWORD*)(a1 + 28)) << 16;
                *(_DWORD*)(a1 + 84) = v10;
            }
            else
            {
                result = (*(int(__cdecl * *)(int))(a1 + 132))(a1);
            }
        }
    }
    return result;
}

//----- (004AF2A0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AF2A0(unsigned __int8** a1)
{
    unsigned __int8* result; // eax

    sub_4AF8C0(a1);
    result = a1[1];
    if (result)
    {
        sub_4AF890(a1);
        result = (unsigned __int8*)sub_4AF690(a1, (void(__cdecl*)(_DWORD*, _DWORD*, int))sub_4AF2D0);
    }
    return result;
}

//----- (004AF2D0) --------------------------------------------------------
void __cdecl sub_4AF2D0(int* a1, int a2, int a3)
{
    int v3; // eax
    int* v4; // ebx
    int v5; // eax
    char* v7; // esi
    int v8; // [esp+0h] [ebp-8h]
    int v9; // [esp+4h] [ebp-4h]

    if (!*(_DWORD*)& byte_5D4594[1311132])
    {
        *(_DWORD*)& byte_5D4594[1311124] = sub_4344A0(64, 200, 64);
        *(_DWORD*)& byte_5D4594[1311128] = sub_4344A0(64, 64, 255);
        *(_DWORD*)& byte_5D4594[1311132] = 1;
    }
    sub_434040(*(_DWORD*)& byte_5D4594[4 * a1[6] + 1311124]);
    v3 = sub_48C5E0(2, 5);
    sub_434080(v3);
    v4 = sub_4B0680(0, 0xFFu);
    v9 = a2;
    v8 = a3;
    sub_48C650(0, 256, 120, &v9, &v8);
    v5 = sub_48C5E0(1, a1[7]);
    v7 = sub_4AF990(v9, v8, 0, v5);
    if (v7)
    {
        sub_4AFE20(v7, *(CHAR * *)& byte_5D4594[3798628]);
        sub_4AFB10((int)v7, *a1);
        sub_4AFB00((int)v7, (int)v4);
        sub_4AFC90(v7, a2, a3, 0);
    }
}

//----- (004AF3D0) --------------------------------------------------------
_DWORD* __cdecl sub_4AF3D0(_DWORD* a1)
{
    sub_434430(255, 255, 255);
    return sub_4AF690(a1, (void(__cdecl*)(_DWORD*, _DWORD*, int))sub_4AF400);
}

//----- (004AF400) --------------------------------------------------------
int __cdecl sub_4AF400(int a1, int a2, int a3)
{
    int v3; // eax
    char* v4; // esi
    int v5; // eax
    int v6; // eax

    v3 = sub_48C5E0(0, 100);
    v4 = sub_4AF990(a2, a3, 0, v3);
    sub_4AFB50((int)v4, 1);
    v5 = sub_48C5E0(0, 64);
    sub_4AFB90((int)v4, v5);
    LOWORD(v6) = sub_48C610();
    return sub_4AFBE0((int)v4, v6 - 6553);
}
// 4AF444: variable 'v6' is possibly undefined

//----- (004AF450) --------------------------------------------------------
char* __cdecl sub_4AF450(int* a1)
{
    int* v1; // edi
    char* result; // eax
    char* v3; // esi

    sub_433F10(0x32u, 0x32u, 0x32u);
    sub_434080(10);
    v1 = sub_4B0680(0, 0xFFu);
    result = sub_4AF990(0, 0, 0, 0x7FFFFFFF);
    v3 = result;
    if (result)
    {
        sub_4AFB10((int)result, *a1);
        sub_4AFB00((int)v3, (int)v1);
        result = (char*)sub_4AFCF0(sub_4AF4C0, (int)v3, 1, a1[7]);
    }
    return result;
}

//----- (004AF4C0) --------------------------------------------------------
int __cdecl sub_4AF4C0(int a1)
{
    int v1; // eax
    int v2; // esi
    int v3; // edi
    int v4; // eax
    char* v5; // eax
    int v6; // esi
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v11; // [esp-Ch] [ebp-18h]

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 20) + 8);
    v2 = *(_DWORD*)(v1 + 12);
    v3 = *(_DWORD*)(v1 + 16);
    sub_434460(*(int*)& byte_5D4594[2589772]);
    v11 = sub_48C5E0(v3 - 2, v3 + 2);
    v4 = sub_48C5E0(v2 - 2, v2 + 2);
    v5 = sub_4AF990(v4, v11, 2, 10);
    v6 = (int)v5;
    if (!v5)
        return 0;
    sub_4AFE20(v5, *(CHAR * *)& byte_5D4594[3798628]);
    sub_4AFB00(v6, *(_DWORD*)(*(_DWORD*)(a1 + 20) + 4));
    sub_4AFB50(v6, 1);
    sub_4AFC50(v6, -32768);
    sub_4AFC60(v6, 45875, 1);
    LOWORD(v7) = sub_48C610();
    sub_4AFBD0(v6, v7);
    LOWORD(v8) = sub_48C610();
    sub_4AFBE0(v6, v8);
    LOWORD(v9) = sub_48C610();
    sub_4AFBF0(v6, v9);
    return 1;
}
// 4AF55B: variable 'v7' is possibly undefined
// 4AF56E: variable 'v8' is possibly undefined
// 4AF57E: variable 'v9' is possibly undefined

//----- (004AF5A0) --------------------------------------------------------
char* __cdecl sub_4AF5A0(int* a1)
{
    char* result; // eax
    char* v2; // esi

    result = sub_4AF990(0, 0, 0, 0x7FFFFFFF);
    v2 = result;
    if (result)
    {
        sub_4AFB40((int)result, a1[2]);
        sub_4AFB10((int)v2, *a1);
        sub_4AFB60((int)v2, 0);
        sub_4AFB70((int)v2, 0);
        result = (char*)sub_4AFCF0(sub_4AF600, (int)v2, 1, 500);
    }
    return result;
}

int __cdecl sub_4AF650(int* a1)
{
    sub_434560(1);
    sub_434580(255 * a1[12] / a1[13]);
    sub_4AFEB0(a1);
    return sub_434560(0);
}

//----- (004AF600) --------------------------------------------------------
int __cdecl sub_4AF600(int a1)
{
    char* v1; // esi

    v1 = sub_4AF990(0, 0, 0, 5);
    if (!v1)
        return 0;
    sub_4AFB40((int)v1, *(_DWORD*)(*(_DWORD*)(a1 + 20) + 16));
    sub_4AFB10((int)v1, *(_DWORD*)(*(_DWORD*)(a1 + 20) + 12));
    sub_4AFB70((int)v1, sub_4AF650);
    return 1;
}

//----- (004AF690) --------------------------------------------------------
_DWORD* __cdecl sub_4AF690(_DWORD* a1, void(__cdecl* a2)(_DWORD*, _DWORD*, int))
{
    _DWORD* result; // eax
    int v3; // edx
    int v4; // ebx
    int* v5; // edi
    int v6; // ebp
    int v7; // edi
    int v8; // esi
    int v9; // ebp
    _BYTE* v10; // ecx
    int v11; // ebx
    int v12; // eax
    int v13; // edx
    int v14; // esi
    _BYTE* v15; // ecx
    void(__cdecl * v16)(_DWORD*, _DWORD*, int); // ebx
    _DWORD* v17; // edi
    int v18; // edx
    int v19; // eax
    _DWORD* v20; // [esp+10h] [ebp-20h]
    int v21; // [esp+10h] [ebp-20h]
    int v22; // [esp+14h] [ebp-1Ch]
    int v23; // [esp+18h] [ebp-18h]
    int v24; // [esp+18h] [ebp-18h]
    int v25; // [esp+18h] [ebp-18h]
    int v26; // [esp+1Ch] [ebp-14h]
    int v27; // [esp+20h] [ebp-10h]
    int v28; // [esp+20h] [ebp-10h]
    _DWORD* v29; // [esp+24h] [ebp-Ch]
    int v30; // [esp+28h] [ebp-8h]
    int v31; // [esp+2Ch] [ebp-4h]
    _BYTE* v32; // [esp+38h] [ebp+8h]

    result = (_DWORD*)(*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3799492])(a1[1]);
    if (result)
    {
        v3 = *result;
        v4 = result[1];
        v5 = result + 3;
        result = (_DWORD*)(result[2] + a1[3]);
        v22 = a1[5];
        v30 = v3;
        v6 = *v5;
        v7 = (int)v5 + 5;
        v8 = v6 + a1[4];
        v9 = 0;
        v27 = v4;
        v29 = result;
        v10 = (_BYTE*)v7;
        if (v4)
        {
            v23 = v4;
            do
            {
                v20 = result;
                v11 = v3;
                if (v3 > 0)
                {
                    do
                    {
                        v12 = (unsigned __int8)v10[1];
                        v13 = *v10 & 0xF;
                        v10 += 2;
                        switch (v13)
                        {
                        case 1:
                            v20 = (_DWORD*)((char*)v20 + v12);
                            break;
                        case 2:
                        case 5:
                        case 6:
                            v9 += v12;
                            v10 += 2 * v12;
                            break;
                        case 4:
                            v9 += v12;
                            v10 += v12;
                            break;
                        default:
                            break;
                        }
                        v11 -= v12;
                    } while (v11 > 0);
                    result = v29;
                    v3 = v30;
                }
                --v23;
            } while (v23);
            v4 = v27;
        }
        v21 = v8;
        v14 = a1[5];
        v15 = (_BYTE*)v7;
        if (v4)
        {
            v31 = v4;
            v16 = a2;
            do
            {
                v17 = result;
                v28 = v3;
                if (v3 > 0)
                {
                    do
                    {
                        v18 = (unsigned __int8)v15[1];
                        v19 = *v15 & 0xF;
                        v15 += 2;
                        v26 = v18;
                        v32 = v15;
                        switch (v19)
                        {
                        case 1:
                            v17 = (_DWORD*)((char*)v17 + v18);
                            break;
                        case 2:
                        case 5:
                        case 6:
                            if (v18 > 0)
                            {
                                v25 = v18;
                                do
                                {
                                    v14 += v22;
                                    if (v14 >= v9)
                                    {
                                        v14 -= v9;
                                        if (v16)
                                        {
                                            v16(a1, v17, v21);
                                            v15 = v32;
                                            v18 = v26;
                                        }
                                    }
                                    v17 = (_DWORD*)((char*)v17 + 1);
                                    --v25;
                                } while (v25);
                            }
                            v15 += 2 * v18;
                            break;
                        case 4:
                            if (v18 > 0)
                            {
                                v24 = v18;
                                do
                                {
                                    v14 += v22;
                                    if (v14 >= v9)
                                    {
                                        v14 -= v9;
                                        if (v16)
                                        {
                                            v16(a1, v17, v21);
                                            v15 = v32;
                                            v18 = v26;
                                        }
                                    }
                                    v17 = (_DWORD*)((char*)v17 + 1);
                                    --v24;
                                } while (v24);
                            }
                            v15 += v18;
                            break;
                        default:
                            break;
                        }
                        v28 -= v18;
                    } while (v28 > 0);
                    result = v29;
                    v3 = v30;
                }
                ++v21;
                --v31;
            } while (v31);
        }
    }
    return result;
}

//----- (004AF890) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AF890(unsigned __int8** a1)
{
    unsigned __int8* result; // eax

    result = *a1;
    a1[3] = (unsigned __int8*)(*((_DWORD*)* a1 + 3) - **a1);
    a1[4] = (unsigned __int8*)(*((_DWORD*)result + 4) - *((__int16*)result + 53) - *((__int16*)result + 52) - result[1]);
    return result;
}

//----- (004AF8C0) --------------------------------------------------------
int __cdecl sub_4AF8C0(_DWORD* a1)
{
    int result; // eax

    result = *(_DWORD*)(*a1 + 8);
    a1[1] = result;
    return result;
}

//----- (004AF8D0) --------------------------------------------------------
int sub_4AF8D0()
{
    unsigned __int8* v1; // eax

    *(_DWORD*)& byte_5D4594[3798628] = &byte_587000[174348];
    *(_DWORD*)& byte_5D4594[1311148] = 512;
    *(_DWORD*)& byte_5D4594[1311140] = nox_calloc(0x200u, 0x88u);
    if (!*(_DWORD*)& byte_5D4594[1311140])
        return 0;
    *(_DWORD*)& byte_5D4594[1311144] = nox_calloc(0x200u, 1u);
    if (!*(_DWORD*)& byte_5D4594[1311144])
        return 0;
    v1 = &byte_5D4594[1311160];
    do
    {
        *((_DWORD*)v1 - 1) = 0;
        *(_DWORD*)v1 = 0;
        *((_DWORD*)v1 + 1) = 0;
        *((_DWORD*)v1 + 2) = 0;
        v1 += 24;
    } while ((int)v1 < (int)& byte_5D4594[1311928]);
    return 1;
}

//----- (004AF950) --------------------------------------------------------
void sub_4AF950()
{
    if (*(_DWORD*)& byte_5D4594[1311140])
    {
        free(*(LPVOID*)& byte_5D4594[1311140]);
        *(_DWORD*)& byte_5D4594[1311140] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1311144])
    {
        free(*(LPVOID*)& byte_5D4594[1311144]);
        *(_DWORD*)& byte_5D4594[1311144] = 0;
    }
    *(_DWORD*)& byte_5D4594[1311148] = 0;
}

//----- (004AF990) --------------------------------------------------------
char* __cdecl sub_4AF990(int a1, int a2, int a3, int a4)
{
    char* result; // eax

    result = sub_4B01B0();
    if (result)
    {
        *(_DWORD*)result = 0;
        *((_DWORD*)result + 1) = 0;
        *((_DWORD*)result + 4) = 0;
        *((_DWORD*)result + 3) = 0;
        *((_DWORD*)result + 5) = 0;
        *((_DWORD*)result + 6) = ptr_5D4594_3799572->data[61];
        *((_DWORD*)result + 7) = a1;
        *((_DWORD*)result + 8) = a2;
        *((_DWORD*)result + 9) = a3;
        *((_DWORD*)result + 22) = a3 << 16;
        *((_DWORD*)result + 21) = a2 << 16;
        *((_DWORD*)result + 12) = a4;
        *((_DWORD*)result + 13) = a4;
        *((_DWORD*)result + 10) = 0;
        *((_DWORD*)result + 11) = 0;
        *((_DWORD*)result + 14) = 0;
        *((_DWORD*)result + 20) = a1 << 16;
        *((_DWORD*)result + 23) = 0;
        *((_DWORD*)result + 24) = 0;
        *((_DWORD*)result + 25) = 0;
        *((_DWORD*)result + 26) = 0;
        *((_DWORD*)result + 27) = 0;
        *((_DWORD*)result + 28) = 0;
        *((_DWORD*)result + 29) = 0;
        *((_DWORD*)result + 30) = 0;
        *((_DWORD*)result + 16) = 0;
        *((_DWORD*)result + 32) = sub_4B0020;
        *((_DWORD*)result + 31) = sub_4AFEB0;
        *((_DWORD*)result + 33) = sub_4B01A0;
    }
    return result;
}

//----- (004AFA40) --------------------------------------------------------
void __cdecl sub_4AFA40(int a1)
{
    int v1; // eax
    _DWORD* v2; // eax

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 60);
        if (v1 >= 0 && v1 < *(int*)& byte_5D4594[1311148])
        {
            *(_BYTE*)(*(_DWORD*)& byte_5D4594[1311144] + v1) = 0;
            v2 = *(_DWORD * *)(a1 + 20);
            if (v2)
                * v2 = 0;
        }
    }
}

//----- (004AFA70) --------------------------------------------------------
char* __cdecl sub_4AFA70(int a1)
{
    char* result; // eax
    char* i; // edi
    int v3; // esi

    result = (char*)memchr(*(const void**)& byte_5D4594[1311144], 255, *(size_t*)& byte_5D4594[1311148]);
    for (i = result; result; i = result)
    {
        v3 = (int)& i[-*(_DWORD*)& byte_5D4594[1311144]];
        if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1311140] + 136 * (_DWORD)& i[-*(_DWORD*)& byte_5D4594[1311144]] + 8) == a1)
            sub_4AFA40(*(_DWORD*)& byte_5D4594[1311140] + 136 * (_DWORD)& i[-*(_DWORD*)& byte_5D4594[1311144]]);
        result = (char*)(*(_DWORD*)& byte_5D4594[1311148] - v3 - 1);
        if (*(_DWORD*)& byte_5D4594[1311148] - v3 == 1)
            break;
        result = (char*)memchr(i + 1, 255, *(_DWORD*)& byte_5D4594[1311148] - v3 - 1);
    }
    return result;
}

//----- (004AFAF0) --------------------------------------------------------
int __cdecl sub_4AFAF0(_DWORD* a1, int a2)
{
    int result; // eax

    result = a2;
    *a1 = a2;
    return result;
}

//----- (004AFB00) --------------------------------------------------------
int __cdecl sub_4AFB00(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 4) = a2;
    return result;
}

//----- (004AFB10) --------------------------------------------------------
int __cdecl sub_4AFB10(int a1, int a2)
{
    int result; // eax
    int v3; // edx
    unsigned int v4; // edx

    result = a1;
    v3 = *(_DWORD*)(a1 + 56);
    if (a2)
    {
        v4 = v3 | 4;
        *(_DWORD*)(a1 + 8) = a2;
    }
    else
    {
        v4 = v3 & 0xFFFFFFFB;
        *(_DWORD*)(a1 + 8) = 0;
    }
    *(_DWORD*)(a1 + 56) = v4;
    return result;
}

//----- (004AFB40) --------------------------------------------------------
int __cdecl sub_4AFB40(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 16) = a2;
    return result;
}

//----- (004AFB50) --------------------------------------------------------
int __cdecl sub_4AFB50(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 64) = a2;
    return result;
}

//----- (004AFB60) --------------------------------------------------------
int __cdecl sub_4AFB60(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 128) = a2;
    return result;
}

//----- (004AFB70) --------------------------------------------------------
int __cdecl sub_4AFB70(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 124) = a2;
    return result;
}

//----- (004AFB80) --------------------------------------------------------
int __cdecl sub_4AFB80(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 132) = a2;
    return result;
}

//----- (004AFB90) --------------------------------------------------------
int __cdecl sub_4AFB90(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 44) = a2;
    return result;
}

//----- (004AFBA0) --------------------------------------------------------
int __cdecl sub_4AFBA0(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 48) = a2;
    *(_DWORD*)(a1 + 52) = a2;
    return result;
}

//----- (004AFBB0) --------------------------------------------------------
_DWORD* __cdecl sub_4AFBB0(_DWORD* a1, int a2, int a3, int a4)
{
    _DWORD* result; // eax

    result = a1;
    a1[23] = a2;
    a1[24] = a3;
    a1[25] = a4;
    return result;
}

//----- (004AFBD0) --------------------------------------------------------
int __cdecl sub_4AFBD0(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 92) = a2;
    return result;
}

//----- (004AFBE0) --------------------------------------------------------
int __cdecl sub_4AFBE0(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 96) = a2;
    return result;
}

//----- (004AFBF0) --------------------------------------------------------
int __cdecl sub_4AFBF0(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 100) = a2;
    return result;
}

//----- (004AFC00) --------------------------------------------------------
_DWORD* __cdecl sub_4AFC00(_DWORD* a1, int a2, int a3, int a4)
{
    _DWORD* result; // eax

    result = a1;
    a1[26] = a2;
    a1[27] = a3;
    a1[28] = a4;
    return result;
}

//----- (004AFC20) --------------------------------------------------------
int __cdecl sub_4AFC20(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 104) = a2;
    return result;
}

//----- (004AFC30) --------------------------------------------------------
int __cdecl sub_4AFC30(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 108) = a2;
    return result;
}

//----- (004AFC40) --------------------------------------------------------
int __cdecl sub_4AFC40(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 112) = a2;
    return result;
}

//----- (004AFC50) --------------------------------------------------------
int __cdecl sub_4AFC50(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 116) = a2;
    return result;
}

//----- (004AFC60) --------------------------------------------------------
int __cdecl sub_4AFC60(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // ecx

    result = a1;
    v4 = *(_DWORD*)(a1 + 56);
    if (a3)
        * (_DWORD*)(a1 + 56) = v4 | 2;
    else
        *(_DWORD*)(a1 + 56) = v4 & 0xFFFFFFFD;
    *(_DWORD*)(a1 + 120) = a2;
    return result;
}

//----- (004AFC90) --------------------------------------------------------
void __cdecl sub_4AFC90(_DWORD* a1, int a2, int a3, int a4)
{
    int v4; // ecx
    int v5; // edx

    v4 = a4;
    if (!a4)
        v4 = a1[13];
    if (v4)
    {
        v5 = a1[8];
        a1[23] = ((a2 - a1[7]) << 16) / v4;
        a1[24] = ((a3 - v5) << 16) / v4;
    }
}

//----- (004AFCD0) --------------------------------------------------------
_DWORD* __cdecl sub_4AFCD0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // edx
    int v3; // ecx

    result = a1;
    v2 = a1[21];
    a1[7] = a1[20] >> 16;
    v3 = a1[22] >> 16;
    a1[8] = v2 >> 16;
    a1[9] = v3;
    return result;
}

//----- (004AFCF0) --------------------------------------------------------
int __cdecl sub_4AFCF0(int a1, int a2, int a3, int a4)
{
    unsigned __int8* v4; // eax
    int v5; // ecx

    v4 = &byte_5D4594[1311156];
    v5 = 0;
    while (*(_DWORD*)v4)
    {
        v4 += 24;
        if (++v5 >= 32)
            return 0;
    }
    *(_DWORD*)v4 = a1;
    *((_DWORD*)v4 + 5) = a2;
    *(_DWORD*)(a2 + 20) = v4;
    *((_DWORD*)v4 + 2) = a3;
    *((_DWORD*)v4 + 1) = a3;
    *((_DWORD*)v4 + 3) = 0;
    *((_DWORD*)v4 + 4) = a4;
    return 1;
}

//----- (004AFD40) --------------------------------------------------------
void sub_4AFD40()
{
    char* i; // ebp
    int v1; // esi
    int v2; // edi
    void(__cdecl * v3)(int); // eax
    void(__cdecl * v4)(int); // eax
    unsigned __int8* v5; // esi
    int v6; // ebx
    int(__cdecl * *v7)(int); // edi
    int v8; // eax
    int v9; // ecx
    int v10; // eax
    int v11; // edx

    for (i = (char*)memchr(*(const void**)& byte_5D4594[1311144], 255, *(size_t*)& byte_5D4594[1311148]);
        i;
        i = (char*)memchr(i + 1, 255, *(_DWORD*)& byte_5D4594[1311148] - v1 - 1))
    {
        v1 = (int)& i[-*(_DWORD*)& byte_5D4594[1311144]];
        v2 = *(_DWORD*)& byte_5D4594[1311140] + 136 * (_DWORD)& i[-*(_DWORD*)& byte_5D4594[1311144]];
        if (!(*(_BYTE*)(v2 + 56) & 8))
        {
            v3 = *(void(__cdecl * *)(int))(v2 + 124);
            if (v3)
                v3(*(_DWORD*)& byte_5D4594[1311140] + 136 * (_DWORD)& i[-*(_DWORD*)& byte_5D4594[1311144]]);
        }
        v4 = *(void(__cdecl * *)(int))(v2 + 128);
        if (v4)
            v4(v2);
        if (*(_DWORD*)& byte_5D4594[1311148] - v1 == 1)
            break;
    }
    v5 = &byte_5D4594[1311168];
    v6 = 32;
    do
    {
        v7 = (int(__cdecl * *)(int))(v5 - 12);
        if (*((_DWORD*)v5 - 3))
        {
            v8 = *((_DWORD*)v5 - 2);
            if (v8)
            {
                if (v8 == 1)
                {
                    v9 = *((_DWORD*)v5 + 1);
                    v10 = *(_DWORD*)v5 + 1;
                    *(_DWORD*)v5 = v10;
                    if (v10 <= v9 && (*v7)((int)(v5 - 12)))
                    {
                        *((_DWORD*)v5 - 2) = *((_DWORD*)v5 - 1);
                    }
                    else
                    {
                        v11 = *((_DWORD*)v5 + 2);
                        *v7 = 0;
                        sub_4AFA40(v11);
                    }
                }
            }
        }
        v5 += 24;
        --v6;
    } while (v6);
}

//----- (004AFE20) --------------------------------------------------------
int __cdecl sub_4AFE20(_DWORD* a1, CHAR* a2)
{
    int v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // edi
    int result; // eax

    v2 = sub_44CFC0(a2);
    v3 = (_DWORD*)sub_45A360(v2, a1[20] >> 16, a1[21] >> 16);
    v4 = v3;
    if (v3)
    {
        a1[3] = v3;
        v3[108] = a1;
        sub_49B950(v3, a1[13]);
        sub_45A110(v4);
    }
    result = a1[14];
    LOBYTE(result) = result | 8;
    a1[14] = result;
    return result;
}

//----- (004AFE80) --------------------------------------------------------
int __cdecl nox_thing_particle_draw(int a1, _DWORD* a2)
{
    _DWORD* v2; // eax
    void(__cdecl * v3)(_DWORD*); // ecx

    v2 = (_DWORD*)a2[108];
    a2[3] = v2[20] >> 16;
    a2[4] = v2[21] >> 16;
    v3 = (void(__cdecl*)(_DWORD*))v2[31];
    if (v3)
        v3(v2);
    return 1;
}

//----- (004AFEB0) --------------------------------------------------------
int __cdecl sub_4AFEB0(int* a1)
{
    int* v1; // esi
    int v2; // ecx
    int v3; // edx
    int v4; // edi
    int v5; // ebx
    int v6; // eax
    int v7; // eax
    int v8; // ebp
    int result; // eax
    int v10; // ebx
    int2 a1a; // [esp+10h] [ebp-10h]
    int2 a2; // [esp+18h] [ebp-8h]
    int v13; // [esp+24h] [ebp+4h]

    v1 = a1;
    v2 = a1[22] >> 16;
    v3 = a1[21] >> 16;
    a1a.field_0 = a1[20] >> 16;
    a1a.field_4 = v3 - v2;
    sub_4739A0(&a1a, &a2);
    v4 = a2.field_0;
    v5 = a2.field_4;
    if (*a1)
        sub_47D2C0(*a1, a2.field_0, a2.field_4);
    v6 = a1[1];
    if (v6)
        sub_4B0820(v6, v4, v5);
    v7 = a1[3];
    if (v7 && a1[4])
    {
        v8 = *(_DWORD*)(v7 + 12);
        v13 = *(_DWORD*)(v7 + 16);
        *(_DWORD*)(v7 + 12) = a1a.field_0;
        *(_DWORD*)(v1[3] + 16) = a1a.field_4;
        (*(void(__cdecl * *)(int, int))(v1[3] + 300))(v1[4], v1[3]);
        *(_DWORD*)(v1[3] + 12) = v8;
        *(_DWORD*)(v1[3] + 16) = v13;
    }
    result = v1[16];
    if (result)
    {
        sub_434460(v1[6]);
        switch (v1[16])
        {
        case 1:
            result = sub_49EFA0(v4, v5);
            break;
        case 2:
            sub_49EFA0(v4, v5);
            sub_49EFA0(v4 + 1, v5);
            v10 = v5 + 1;
            sub_49EFA0(v4, v10);
            result = sub_49EFA0(v4 + 1, v10);
            break;
        case 3:
            sub_49EFA0(v4 + 1, v5);
            sub_49EFA0(v4, v5 + 1);
            sub_49EFA0(v4 + 1, v5 + 1);
            sub_49EFA0(v4 + 2, v5 + 1);
            result = sub_49EFA0(v4 + 1, v5 + 2);
            break;
        default:
            result = sub_4B0BC0(v4, v5, v1[16] / 2);
            break;
        }
    }
    return result;
}

//----- (004B0020) --------------------------------------------------------
int __cdecl sub_4B0020(_DWORD* a1)
{
    _DWORD* v1; // esi
    int result; // eax
    int v3; // eax
    int v4; // edx
    int v5; // ecx
    _DWORD* v6; // eax
    int v7; // eax
    int v8; // ebp
    int v9; // ebx
    int v10; // edi
    bool v11; // sf
    int v12; // edx
    int v13; // eax
    int v14; // edx
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // edi
    int v19; // eax
    int v20; // [esp+10h] [ebp-Ch]
    int v21; // [esp+10h] [ebp-Ch]
    int v22; // [esp+14h] [ebp-8h]
    int nNumerator; // [esp+18h] [ebp-4h]
    int v24; // [esp+20h] [ebp+4h]
    int v25; // [esp+20h] [ebp+4h]

    v1 = a1;
    result = a1[12];
    if (result >= 0)
    {
        v3 = a1[20];
        v4 = a1[22];
        ++a1[10];
        v20 = a1[21];
        v5 = a1[14];
        v24 = v3;
        if (v5 & 4)
        {
            v6 = (_DWORD*)v1[2];
            if (v6)
            {
                v24 += (v6[3] - v6[8]) << 16;
                v20 += (v6[4] - v6[9]) << 16;
            }
        }
        v7 = v1[11];
        if (v7)
        {
            result = v7 - 1;
            v1[11] = result;
        }
        else
        {
            v8 = v1[23];
            v9 = v1[24];
            v10 = v1[25];
            v25 = v8 + v24;
            v11 = v10 + v4 < 0;
            v12 = v10 + v4;
            v21 = v9 + v20;
            v22 = v12;
            if (v11)
            {
                if (v5 & 2)
                {
                    v13 = v1[30];
                    v14 = v12 - v10;
                    v10 = -v10;
                    v22 = v14;
                    nNumerator = v13;
                    if (v13)
                    {
                        v8 = MulDiv(v8, v13, 0x10000);
                        v9 = MulDiv(v9, nNumerator, 0x10000);
                        v10 = MulDiv(v10, nNumerator, 0x10000);
                    }
                }
                else
                {
                    v10 = 0;
                    v22 = 0;
                }
            }
            v15 = v1[26];
            if (v15)
                v8 = MulDiv(v8, v15, 0x10000);
            v16 = v1[27];
            if (v16)
                v9 = MulDiv(v9, v16, 0x10000);
            v17 = v1[28];
            if (v17)
                v10 = MulDiv(v10, v17, 0x10000);
            v18 = v1[29] + v10;
            v19 = v1[12] - 1;
            v1[12] = v19;
            if (v19 >= 0)
            {
                result = v22;
                v1[25] = v18;
                v1[20] = v25;
                v1[21] = v21;
                v1[22] = v22;
                v1[23] = v8;
                v1[24] = v9;
            }
            else
            {
                result = ((int(__cdecl*)(_DWORD*))v1[33])(v1);
            }
        }
    }
    return result;
}

//----- (004B01A0) --------------------------------------------------------
void __cdecl sub_4B01A0(int a1)
{
    sub_4AFA40(a1);
}

//----- (004B01B0) --------------------------------------------------------
char* sub_4B01B0()
{
    char* v0; // eax
    char* result; // eax
    int v2; // ecx

    v0 = (char*)memchr(*(const void**)& byte_5D4594[1311144], 0, *(size_t*)& byte_5D4594[1311148]);
    if (!v0)
    {
        result = (char*)sub_4B0220(*(_DWORD*)& byte_5D4594[1311148] + 512);
        if (!result)
            return result;
        v0 = (char*)memchr(*(const void**)& byte_5D4594[1311144], 0, *(size_t*)& byte_5D4594[1311148]);
    }
    v2 = (int)& v0[-*(_DWORD*)& byte_5D4594[1311144]];
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1311144] + v2) = -1;
    result = (char*)(*(_DWORD*)& byte_5D4594[1311140] + 136 * v2);
    *((_DWORD*)result + 15) = v2;
    return result;
}

//----- (004B0220) --------------------------------------------------------
int __cdecl sub_4B0220(size_t a1)
{
    unsigned int v1; // esi
    int result; // eax

    v1 = a1 - *(_DWORD*)& byte_5D4594[1311148];
    result = realloc(*(LPVOID*)& byte_5D4594[1311140], 136 * a1);
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1311140] = result;
        memset((void*)(result + 136 * *(_DWORD*)& byte_5D4594[1311148]), 0, 136 * v1);
        result = realloc(*(LPVOID*)& byte_5D4594[1311144], a1);
        if (result)
        {
            *(_DWORD*)& byte_5D4594[1311144] = result;
            memset((void*)(*(_DWORD*)& byte_5D4594[1311148] + result), 0, v1);
            *(_DWORD*)& byte_5D4594[1311148] = a1;
            result = 1;
        }
    }
    return result;
}

//----- (004B02D0) --------------------------------------------------------
int sub_4B02D0()
{
    *(_DWORD*)& byte_5D4594[1311936] = 0;
    *(_DWORD*)& byte_5D4594[1311924] = 0;
    *(_DWORD*)& byte_5D4594[1311928] = 0;
    *(_DWORD*)& byte_5D4594[1311932] = 0;
    return 1;
}

//----- (004B0610) --------------------------------------------------------
void __cdecl sub_4B0610(int a1)
{
    if (*(_DWORD*)& byte_5D4594[1311936] && (!*(_DWORD*)& byte_5D4594[1311932] || a1 == 1))
    {
        sub_555500(1);
    }
}

//----- (004B0650) --------------------------------------------------------
int sub_4B0650()
{
    *(_DWORD*)& byte_5D4594[1312460] = 0;
    return 1;
}

//----- (004B0660) --------------------------------------------------------
void sub_4B0660()
{
    void* result; // eax
    for (result = *(void**)& byte_5D4594[1312460]; *(_DWORD*)& byte_5D4594[1312460]; result = *(void**)& byte_5D4594[1312460])
        sub_4B07D0(result);
}

//----- (004B0680) --------------------------------------------------------
int* __cdecl sub_4B0680(unsigned __int8 a1, unsigned __int8 a2)
{
    int* result; // eax
    unsigned __int8 v3; // bl
    int v4; // edi
    int* v5; // esi
    size_t v6; // eax
    int* v7; // [esp+14h] [ebp+4h]

    result = *(int**)& byte_5D4594[1312460];
    v3 = a1;
    v4 = ptr_5D4594_3799572->data[262];
    if (*(_DWORD*)& byte_5D4594[1312460])
    {
        while (1)
        {
            v7 = result;
            if (*result == v4
                && result[1] == v3
                && result[2] == a2
                && result[12] == ptr_5D4594_3799572->data[54]
                && result[13] == ptr_5D4594_3799572->data[55]
                && result[14] == ptr_5D4594_3799572->data[56])
            {
                break;
            }
            result = (int*)result[18];
            if (!result)
            {
                v5 = (int*)nox_calloc(1u, 0x50u);
                v7[18] = (int)v5;
                v5[17] = (int)v7;
                goto LABEL_11;
            }
        }
        ++result[4];
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1312460] = nox_calloc(1u, 0x50u);
        v5 = *(int**)& byte_5D4594[1312460];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1312460] + 68) = 0;
    LABEL_11:
        *v5 = v4;
        v5[1] = v3;
        v5[2] = a2;
        v5[4] = 0;
        v6 = 2 * (22 * v4 * (v4 + 1) / 7 + 6 * v4) + 17;
        v5[3] = v6;
        v5[12] = ptr_5D4594_3799572->data[54];
        v5[13] = ptr_5D4594_3799572->data[55];
        v5[14] = ptr_5D4594_3799572->data[56];
        v5[16] = (int)nox_calloc(1u, v6);
        v5[18] = 0;
        sub_4B0870(v5);
        result = v5;
    }
    return result;
}

//----- (004B07D0) --------------------------------------------------------
int __cdecl sub_4B07D0(LPVOID lpMem)
{
    int result; // eax
    int v2; // eax
    int v3; // eax

    result = *((_DWORD*)lpMem + 4) - 1;
    *((_DWORD*)lpMem + 4) = result;
    if (result < 0)
    {
        v2 = *((_DWORD*)lpMem + 17);
        if (v2)
            * (_DWORD*)(v2 + 72) = *((_DWORD*)lpMem + 18);
        v3 = *((_DWORD*)lpMem + 18);
        if (v3)
            * (_DWORD*)(v3 + 68) = *((_DWORD*)lpMem + 17);
        if (lpMem == *(LPVOID*)& byte_5D4594[1312460])
            * (_DWORD*)& byte_5D4594[1312460] = *((_DWORD*)lpMem + 18);
        free(*((LPVOID*)lpMem + 16));
        free(lpMem);
    }
    return result;
}

//----- (004B0820) --------------------------------------------------------
int(__cdecl* __cdecl sub_4B0820(int a1, int a2, int a3))(_DWORD)
{
    int(__cdecl * v3)(_DWORD); // esi
    char v5[12]; // [esp+4h] [ebp-Ch]

    v5[10] = 8;
    *(_DWORD*)v5 = *(_DWORD*)(a1 + 64);
    v3 = sub_47D5B0(sub_4B0B20);
    sub_47D2C0((int)v5, a2, a3);
    return sub_47D5B0((int)v3);
}

//----- (004B0870) --------------------------------------------------------
int __cdecl sub_4B0870(int* a1)
{
    int v1; // ebx
    _DWORD* v2; // esi
    int v3; // ebp
    int v4; // eax
    int v5; // edx
    _BYTE* v6; // esi
    int v7; // ebp
    int result; // eax
    int v9; // ecx
    _BYTE* v10; // esi
    _BYTE* v11; // esi
    int v12; // edi
    int v13; // ebp
    int v14; // edx
    _BYTE* v15; // esi
    int v16; // eax
    bool v17; // zf
    int v18; // [esp+10h] [ebp-44h]
    int v19; // [esp+14h] [ebp-40h]
    int v20; // [esp+18h] [ebp-3Ch]
    int v21; // [esp+20h] [ebp-34h]
    int v22; // [esp+24h] [ebp-30h]
    int v23; // [esp+28h] [ebp-2Ch]
    int v24; // [esp+28h] [ebp-2Ch]
    unsigned __int8 v25; // [esp+2Ch] [ebp-28h]
    int v26; // [esp+2Ch] [ebp-28h]
    int v27; // [esp+30h] [ebp-24h]
    int v28; // [esp+34h] [ebp-20h]
    unsigned __int8 v29; // [esp+38h] [ebp-1Ch]
    int v30; // [esp+38h] [ebp-1Ch]
    int v31; // [esp+3Ch] [ebp-18h]
    unsigned __int8 v32; // [esp+40h] [ebp-14h]
    int v33; // [esp+40h] [ebp-14h]
    int v34; // [esp+48h] [ebp-Ch]
    int v35; // [esp+4Ch] [ebp-8h]
    int v36; // [esp+50h] [ebp-4h]
    int v37; // [esp+58h] [ebp+4h]

    v1 = *a1;
    v2 = (_DWORD*)a1[16];
    v3 = a1[1];
    v4 = a1[2];
    *v2 = 2 * *a1;
    ++v2;
    *v2 = 2 * v1;
    ++v2;
    *v2 = -*a1;
    ++v2;
    *v2 = -*a1;
    v32 = (unsigned __int16)(v3 * a1[12]) >> 8;
    v5 = a1[13];
    v23 = a1[14];
    v29 = (unsigned __int16)(v3 * v5) >> 8;
    v25 = (unsigned __int16)(v3 * v23) >> 8;
    v6 = (char*)v2 + 5;
    v34 = v32 << 16;
    v18 = v32 << 16;
    v7 = -v1;
    v31 = -v1;
    v27 = (int)(((((unsigned int)(v4 * a1[12]) >> 8) & 0xFF) - v32) << 16) / v1;
    v35 = v29 << 16;
    v19 = v29 << 16;
    v28 = (int)(((((unsigned int)(v4 * v5) >> 8) & 0xFF) - v29) << 16) / v1;
    v36 = v25 << 16;
    v20 = v25 << 16;
    v30 = (int)(((((unsigned int)(v4 * v23) >> 8) & 0xFF) - v25) << 16) / v1;
    result = 2 * v1;
    if (2 * v1)
    {
        v33 = 2 * v1;
        do
        {
            v9 = (__int64)sqrt((double)(v1 * v1 - v7 * v7));
            if (v9 < v1)
            {
                *v6 = 1;
                v10 = v6 + 1;
                *v10 = v1 - v9;
                v6 = v10 + 1;
            }
            v26 = 2 * v9;
            if (2 * v9)
            {
                *v6 = 7;
                v11 = v6 + 1;
                v12 = v34;
                v13 = v35;
                *v11 = 2 * v9;
                v6 = v11 + 1;
                v37 = v36;
                v21 = v18 / v9;
                v22 = v19 / v9;
                v14 = -v9;
                v24 = v20 / v9;
                do
                {
                    *(_WORD*)v6 = (v37 >> 19) & 0x1F | (8 * (BYTE2(v13) & 0xFC | (32 * (HIWORD(v12) & 0xFFF8))));
                    if (v14 >= 0)
                    {
                        v12 -= v21;
                        v13 -= v22;
                        v37 -= v24;
                    }
                    else
                    {
                        v12 += v21;
                        v13 += v22;
                        v37 += v24;
                    }
                    ++v14;
                    v6 += 2;
                    --v26;
                } while (v26);
                v7 = v31;
            }
            if (v9 < v1)
            {
                *v6 = 1;
                v15 = v6 + 1;
                *v15 = v1 - v9;
                v6 = v15 + 1;
            }
            if (v7 >= 0)
            {
                v19 -= v28;
                v18 -= v27;
                v16 = v20 - v30;
            }
            else
            {
                v19 += v28;
                v18 += v27;
                v16 = v30 + v20;
            }
            v20 = v16;
            ++v7;
            result = v33 - 1;
            v17 = v33 == 1;
            v31 = v7;
            --v33;
        } while (!v17);
    }
    return result;
}

//----- (004B0B20) --------------------------------------------------------
int __cdecl sub_4B0B20(int a1)
{
    return *(_DWORD*)a1;
}

//----- (004B0B30) --------------------------------------------------------
int sub_4B0B30()
{
    if (*(_DWORD*)& byte_5D4594[3801780])
    {
        if (*(_DWORD*)& byte_5D4594[3801780] == 1)
        {
            *(_DWORD*)& byte_5D4594[1312468] = sub_4B1380;
            *(_DWORD*)& byte_5D4594[1312464] = sub_4B2480;
            return 1;
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1312468] = sub_4B0D30;
        *(_DWORD*)& byte_5D4594[1312464] = sub_4B1A60;
    }
    return 1;
}

//----- (004B0B90) --------------------------------------------------------
int __cdecl sub_4B0B90(int a1, int a2, int a3)
{
    int result; // eax

    if (ptr_5D4594_3799572->data[13])
        result = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[1312464])(a1, a2, a3);
    else
        result = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[1312468])(a1, a2, a3);
    return result;
}

//----- (004B0BC0) --------------------------------------------------------
int __cdecl sub_4B0BC0(int a1, int a2, int a3)
{
    int v3; // ebp
    int(__cdecl * v4)(int, int, int); // esi
    int v5; // edi
    int v6; // ebx
    int result; // eax
    int v8; // ebp
    int v9; // edi
    int v10; // [esp+10h] [ebp-10h]
    int v11; // [esp+14h] [ebp-Ch]
    int v12; // [esp+18h] [ebp-8h]
    int v13; // [esp+1Ch] [ebp-4h]
    int v14; // [esp+24h] [ebp+4h]
    int v15; // [esp+28h] [ebp+8h]
    int v16; // [esp+2Ch] [ebp+Ch]

    v3 = a3;
    v16 = 1 - a3;
    v4 = *(int(__cdecl * *)(int, int, int)) & byte_5D4594[3798708];
    v10 = 5 - 2 * v3;
    v12 = 0;
    v13 = v3;
    v11 = 3;
    if (!ptr_5D4594_3799572->data[13])
        v4 = *(int(__cdecl * *)(int, int, int)) & byte_5D4594[3798720];
    v5 = a2;
    v6 = a1;
    v4(a1, a2 + v3, a1);
    v14 = a1 + v3;
    v15 = v6 - v3;
    v4(v6 - v3, v5, v6 + v3);
    v4(v6 - v3, v5, v14);
    result = v4(v6, v5 - v3, v6);
    if (v3 > 0)
    {
        v8 = v6;
        v9 = v5 - v6;
        do
        {
            if (v16 >= 0)
            {
                v16 += v10;
                v10 += 4;
                --v13;
                --v14;
                ++v15;
            }
            else
            {
                v16 += v11;
                v10 += 2;
            }
            ++v6;
            ++v12;
            --v8;
            v11 += 2;
            v4(v8, v9 + v14, v6);
            v4(v15, v9 + v6, v14);
            v4(v15, v9 + v8, v14);
            v4(v8, v9 + v15, v6);
            result = v13;
        } while (v13 > v12);
    }
    return result;
}

//----- (004B0D30) --------------------------------------------------------
char __cdecl sub_4B0D30(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // edi
    char result; // al
    int v6; // ecx
    int v7; // edx
    int v8; // edi
    int v9; // [esp+10h] [ebp-10h]
    int v10; // [esp+14h] [ebp-Ch]
    int v11; // [esp+18h] [ebp-8h]
    int v12; // [esp+1Ch] [ebp-4h]
    int v13; // [esp+24h] [ebp+4h]
    int v14; // [esp+28h] [ebp+8h]
    int v15; // [esp+2Ch] [ebp+Ch]

    v3 = a1;
    v4 = a3;
    if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
        return sub_4B0F50(a1, a2, a3);
    v6 = 0;
    v9 = 1 - a3;
    v15 = 5 - 2 * a3;
    result = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
    v13 = 4 * (v4 + a2);
    v7 = v4;
    v10 = 3;
    *(_BYTE*)(*(_DWORD*)(v13 + *(_DWORD*)& byte_5D4594[3798784]) + v3) = result;
    *(_BYTE*)(v3 + *(_DWORD*)(4 * a2 + *(_DWORD*)& byte_5D4594[3798784]) + v4) = result;
    *(_BYTE*)(v4 + v3 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = result;
    v12 = 4 * (a2 - v4);
    *(_BYTE*)(v3 + *(_DWORD*)(v12 + *(_DWORD*)& byte_5D4594[3798784])) = result;
    *(_BYTE*)(*(_DWORD*)(v12 + *(_DWORD*)& byte_5D4594[3798784]) + v3) = result;
    *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) - v4 + v3) = result;
    *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) - v4 + v3) = result;
    *(_BYTE*)(v3 + *(_DWORD*)(v13 + *(_DWORD*)& byte_5D4594[3798784])) = result;
    if (v4 > 0)
    {
        v8 = 4 * a2;
        v14 = 4 * a2;
        v11 = v12;
        do
        {
            if (v9 >= 0)
            {
                v9 += v15;
                --v7;
                v15 += 4;
                v13 -= 4;
                v11 += 4;
            }
            else
            {
                v9 += v10;
                v15 += 2;
            }
            v8 += 4;
            ++v6;
            v10 += 2;
            v14 -= 4;
            *(_BYTE*)(v6 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v13) + v3) = result;
            *(_BYTE*)(v7 + *(_DWORD*)(v8 + *(_DWORD*)& byte_5D4594[3798784]) + v3) = result;
            *(_BYTE*)(v7 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v14) + v3) = result;
            *(_BYTE*)(v3 + v6 + *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784])) = result;
            *(_BYTE*)(*(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]) - v6 + v3) = result;
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v14) - v7 + v3) = result;
            *(_BYTE*)(*(_DWORD*)(v8 + *(_DWORD*)& byte_5D4594[3798784]) - v7 + v3) = result;
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v13) - v6 + v3) = result;
        } while (v7 > v6);
    }
    return result;
}

//----- (004B0F50) --------------------------------------------------------
int __cdecl sub_4B0F50(int a1, int a2, int a3)
{
    int v3; // esi
    char v4; // bl
    int v5; // edx
    int result; // eax
    int v7; // edi
    int v8; // ebp
    int v9; // edi
    int v10; // esi
    int v11; // ebx
    int v12; // ebp
    int v13; // edx
    int v14; // ecx
    int v15; // [esp+10h] [ebp-30h]
    int v16; // [esp+14h] [ebp-2Ch]
    int v17; // [esp+18h] [ebp-28h]
    int v18; // [esp+1Ch] [ebp-24h]
    int v19; // [esp+20h] [ebp-20h]
    int v20; // [esp+24h] [ebp-1Ch]
    int v21; // [esp+24h] [ebp-1Ch]
    int v22; // [esp+28h] [ebp-18h]
    int v23; // [esp+2Ch] [ebp-14h]
    int v24; // [esp+30h] [ebp-10h]
    int v25; // [esp+30h] [ebp-10h]
    int v26; // [esp+34h] [ebp-Ch]
    int v27; // [esp+38h] [ebp-8h]
    int v28; // [esp+3Ch] [ebp-4h]
    int v29; // [esp+44h] [ebp+4h]
    int v30; // [esp+48h] [ebp+8h]
    char v31; // [esp+4Ch] [ebp+Ch]

    v3 = a3;
    v28 = 0;
    v20 = 1 - a3;
    v19 = 5 - 2 * a3;
    v27 = a3;
    v26 = 3;
    v4 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
    v17 = ptr_5D4594_3799572->data[1];
    v5 = a2;
    v15 = ptr_5D4594_3799572->data[4];
    v31 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
    result = a2 + v27;
    v16 = ptr_5D4594_3799572->data[3];
    v18 = ptr_5D4594_3799572->data[2];
    v24 = a2 + v27;
    if (a1 >= v17
        && a1 < ptr_5D4594_3799572->data[3]
        && result >= ptr_5D4594_3799572->data[2]
        && result < v15)
    {
        *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * result) + a1) = v4;
    }
    v7 = a1 + v3;
    v30 = a1 + v3;
    if (a1 + v3 >= v17)
    {
        if (v7 < v16 && v5 >= v18 && v5 < v15)
        {
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v5) + v30) = v4;
            v7 = a1 + v3;
        }
        if (v7 >= v17 && v7 < v16 && v5 >= v18 && v5 < v15)
            * (_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v5) + v30) = v4;
    }
    v8 = v5 - v3;
    if (a1 >= v17)
    {
        if (a1 < v16 && v8 >= v18 && v8 < v15)
            * (_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v8) + a1) = v4;
        if (a1 >= v17 && a1 < v16 && v8 >= v18 && v8 < v15)
            * (_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v8) + a1) = v4;
    }
    v9 = a1 - v3;
    if (a1 - v3 >= v17)
    {
        if (v9 < v16 && v5 >= v18 && v5 < v15)
        {
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v5) + v9) = v31;
            result = v24;
        }
        if (v9 >= v17 && v9 < v16 && v5 >= v18 && v5 < v15)
        {
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v5) + v9) = v31;
            result = v24;
        }
    }
    if (a1 >= v17 && a1 < v16 && result >= v18 && result < v15)
    {
        *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * result) + a1) = v31;
        result = v24;
    }
    if (v3 > 0)
    {
        v10 = a1;
        v23 = 4 * v5;
        v22 = 4 * v5;
        v25 = 4 * result;
        v11 = 4 * v8;
        v12 = v18;
        result = a1;
        v13 = v5 - a1;
        v14 = v20;
        v29 = v11;
        while (1)
        {
            if (v14 >= 0)
            {
                v21 = v19 + v14;
                v19 += 4;
                --v27;
                --v30;
                ++v9;
                v29 += 4;
                v25 -= 4;
            }
            else
            {
                v21 = v26 + v14;
                v19 += 2;
            }
            v26 += 2;
            ++v10;
            ++v28;
            v23 += 4;
            --result;
            v22 -= 4;
            if (v10 >= v17 && v10 < v16 && v13 + v30 >= v12 && v13 + v30 < v15)
                * (_BYTE*)(*(_DWORD*)(v25 + *(_DWORD*)& byte_5D4594[3798784]) + v10) = v31;
            if (v30 >= v17)
            {
                if (v30 < v16 && v13 + v10 >= v12 && v13 + v10 < v15)
                {
                    *(_BYTE*)(*(_DWORD*)(v23 + *(_DWORD*)& byte_5D4594[3798784]) + v30) = v31;
                    v12 = v18;
                }
                if (v30 < v16 && v13 + result >= v12 && v13 + result < v15)
                {
                    *(_BYTE*)(*(_DWORD*)(v22 + *(_DWORD*)& byte_5D4594[3798784]) + v30) = v31;
                    v12 = v18;
                }
            }
            if (v10 >= v17 && v10 < v16 && v13 + v9 >= v12 && v13 + v9 < v15)
                * (_BYTE*)(*(_DWORD*)(v29 + *(_DWORD*)& byte_5D4594[3798784]) + v10) = v31;
            if (result >= v17 && result < v16 && v13 + v9 >= v12 && v13 + v9 < v15)
                * (_BYTE*)(*(_DWORD*)(v29 + *(_DWORD*)& byte_5D4594[3798784]) + result) = v31;
            if (v9 >= v17 && v9 < v16)
            {
                if (v13 + result >= v12 && v13 + result < v15)
                    * (_BYTE*)(*(_DWORD*)(v22 + *(_DWORD*)& byte_5D4594[3798784]) + v9) = v31;
                if (v9 < v16 && v13 + v10 >= v12 && v13 + v10 < v15)
                    * (_BYTE*)(*(_DWORD*)(v23 + *(_DWORD*)& byte_5D4594[3798784]) + v9) = v31;
            }
            if (result >= v17 && result < v16 && v13 + v30 >= v12 && v13 + v30 < v15)
                * (_BYTE*)(*(_DWORD*)(v25 + *(_DWORD*)& byte_5D4594[3798784]) + result) = v31;
            if (v27 <= v28)
                break;
            v14 = v21;
        }
    }
    return result;
}

//----- (004B1380) --------------------------------------------------------
__int16 __cdecl sub_4B1380(int a1, int a2, int a3)
{
    int v3; // ebx
    int v4; // esi
    __int16 result; // ax
    int v6; // ecx
    int v7; // edi
    int v8; // ecx
    int v9; // ecx
    int v10; // edx
    int v11; // ebx
    int v12; // esi
    int v13; // edi
    int v14; // ebp
    int v15; // [esp+10h] [ebp-18h]
    int v16; // [esp+14h] [ebp-14h]
    int v17; // [esp+18h] [ebp-10h]
    int v18; // [esp+1Ch] [ebp-Ch]
    int v19; // [esp+1Ch] [ebp-Ch]
    int v20; // [esp+20h] [ebp-8h]
    int v21; // [esp+24h] [ebp-4h]
    int v22; // [esp+2Ch] [ebp+4h]
    int v23; // [esp+30h] [ebp+8h]
    int v24; // [esp+30h] [ebp+8h]
    int v25; // [esp+34h] [ebp+Ch]

    v3 = a2;
    v4 = a3;
    if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
        return sub_4B15E0(a1, a2, a3);
    v15 = 1 - a3;
    v25 = 5 - 2 * a3;
    result = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
    v6 = 2 * a1;
    v7 = 4 * (a2 + v4);
    v18 = v6;
    v20 = 0;
    v21 = v4;
    v16 = 3;
    *(_WORD*)(*(_DWORD*)(v7 + *(_DWORD*)& byte_5D4594[3798784]) + v6) = result;
    v23 = 4 * a2;
    v8 = 2 * (v4 + a1);
    v17 = v8;
    *(_WORD*)(*(_DWORD*)(4 * v3 + *(_DWORD*)& byte_5D4594[3798784]) + v8) = result;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v3) + v8) = result;
    v9 = 4 * (v3 - v4);
    *(_WORD*)(*(_DWORD*)(v9 + *(_DWORD*)& byte_5D4594[3798784]) + v18) = result;
    *(_WORD*)(*(_DWORD*)(v9 + *(_DWORD*)& byte_5D4594[3798784]) + 2 * a1) = result;
    v10 = 2 * (a1 - v4);
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v3) + v10) = result;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v3) + v10) = result;
    *(_WORD*)(*(_DWORD*)(v7 + *(_DWORD*)& byte_5D4594[3798784]) + 2 * a1) = result;
    if (v4 > 0)
    {
        v11 = 4 * v3;
        v12 = v18;
        v22 = v7;
        v13 = v18;
        v19 = v10;
        v14 = v23;
        v24 = v9;
        do
        {
            if (v15 >= 0)
            {
                v15 += v25;
                v22 -= 4;
                v24 += 4;
                v25 += 4;
                --v21;
                v17 -= 2;
                v19 += 2;
            }
            else
            {
                v15 += v16;
                v25 += 2;
            }
            v12 += 2;
            v13 -= 2;
            v16 += 2;
            v11 += 4;
            v14 -= 4;
            ++v20;
            *(_WORD*)(*(_DWORD*)(v22 + *(_DWORD*)& byte_5D4594[3798784]) + v12) = result;
            *(_WORD*)(*(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]) + v17) = result;
            *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v14) + v17) = result;
            *(_WORD*)(*(_DWORD*)(v24 + *(_DWORD*)& byte_5D4594[3798784]) + v12) = result;
            *(_WORD*)(*(_DWORD*)(v24 + *(_DWORD*)& byte_5D4594[3798784]) + v13) = result;
            *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v14) + v19) = result;
            *(_WORD*)(*(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]) + v19) = result;
            *(_WORD*)(*(_DWORD*)(v22 + *(_DWORD*)& byte_5D4594[3798784]) + v13) = result;
        } while (v21 > v20);
    }
    return result;
}

//----- (004B15E0) --------------------------------------------------------
int __cdecl sub_4B15E0(int a1, int a2, int a3)
{
    int v3; // esi
    __int16 v4; // bp
    int v5; // edi
    int v6; // ecx
    int result; // eax
    int v8; // ebx
    int v9; // edx
    int v10; // edi
    int v11; // edx
    int v12; // ebp
    int v13; // edi
    int v14; // edx
    int v15; // esi
    int v16; // ecx
    int v17; // edx
    int v18; // [esp+10h] [ebp-44h]
    int v19; // [esp+14h] [ebp-40h]
    int v20; // [esp+18h] [ebp-3Ch]
    int v21; // [esp+1Ch] [ebp-38h]
    int v22; // [esp+20h] [ebp-34h]
    int v23; // [esp+24h] [ebp-30h]
    __int16 v24; // [esp+28h] [ebp-2Ch]
    int v25; // [esp+2Ch] [ebp-28h]
    int v26; // [esp+30h] [ebp-24h]
    int v27; // [esp+34h] [ebp-20h]
    int v28; // [esp+38h] [ebp-1Ch]
    int v29; // [esp+3Ch] [ebp-18h]
    int v30; // [esp+40h] [ebp-14h]
    int v31; // [esp+44h] [ebp-10h]
    int v32; // [esp+48h] [ebp-Ch]
    int v33; // [esp+4Ch] [ebp-8h]
    int v34; // [esp+4Ch] [ebp-8h]
    int v35; // [esp+58h] [ebp+4h]
    int v36; // [esp+5Ch] [ebp+8h]
    int v37; // [esp+5Ch] [ebp+8h]
    int v38; // [esp+60h] [ebp+Ch]

    v3 = a3;
    v32 = 0;
    v21 = 1 - a3;
    v31 = a3;
    v22 = 5 - 2 * a3;
    v30 = 3;
    v4 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
    v5 = ptr_5D4594_3799572->data[1];
    v38 = ptr_5D4594_3799572->data[2];
    v6 = a2;
    v18 = ptr_5D4594_3799572->data[4];
    result = a1;
    v24 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
    v8 = a2 + v31;
    v20 = ptr_5D4594_3799572->data[1];
    v19 = ptr_5D4594_3799572->data[3];
    v36 = a2 + v31;
    if (a1 >= v5 && a1 < ptr_5D4594_3799572->data[3] && v8 >= v38 && v8 < v18)
        * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v8) + 2 * a1) = v4;
    v9 = a1 + v3;
    v33 = a1 + v3;
    if (a1 + v3 >= v5)
    {
        if (v9 < v19 && v6 >= v38 && v6 < v18)
            * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v6) + 2 * v9) = v4;
        if (v9 >= v20 && v9 < v19 && v6 >= v38 && v6 < v18)
            * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v6) + 2 * v9) = v4;
    }
    v10 = v6 - v3;
    if (a1 >= v20)
    {
        if (a1 < v19 && v10 >= v38 && v10 < v18)
            * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v10) + 2 * a1) = v4;
        if (a1 >= v20 && a1 < v19 && v10 >= v38 && v10 < v18)
            * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v10) + 2 * a1) = v4;
    }
    v11 = a1 - v3;
    if (a1 - v3 >= v20)
    {
        if (v11 < v19 && v6 >= v38 && v6 < v18)
        {
            *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v6) + 2 * v11) = v4;
            v8 = v36;
        }
        if (v11 >= v20 && v11 < v19 && v6 >= v38 && v6 < v18)
        {
            *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v6) + 2 * v11) = v4;
            v8 = v36;
        }
    }
    if (a1 >= v20 && a1 < v19 && v8 >= v38 && v8 < v18)
    {
        *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v8) + 2 * a1) = v4;
        v8 = v36;
    }
    if (v3 > 0)
    {
        v35 = a1 - v3;
        v28 = 2 * v11;
        v27 = 4 * v6;
        v23 = v8;
        v25 = 4 * v10;
        v37 = 2 * result;
        v12 = result - v3;
        v26 = v6 - result;
        v13 = 2 * v33;
        v29 = 2 * result;
        v34 = result - v6;
        v14 = v8;
        v15 = v6;
        do
        {
            if (v21 >= 0)
            {
                v13 -= 2;
                v21 += v22;
                v22 += 4;
                --v31;
                v25 += 4;
                --v14;
                v28 += 2;
                v35 = v12 + 1;
                v23 = v14;
            }
            else
            {
                v21 += v30;
                v22 += 2;
            }
            v30 += 2;
            ++v32;
            ++v15;
            v37 += 2;
            v27 -= 4;
            v29 -= 2;
            v16 = v15 + v34;
            --result;
            if (v15 + v34 >= v20 && v16 < v19 && v14 >= v38 && v14 < v18)
            {
                *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v14) + v37) = v24;
                v14 = v23;
            }
            v17 = v34 + v14;
            if (v17 >= v20)
            {
                if (v17 < v19 && v15 >= v38 && v15 < v18)
                    * (_WORD*)(v13 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v15)) = v24;
                if (v17 >= v20 && v17 < v19 && result + v26 >= v38 && result + v26 < v18)
                    * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v27) + v13) = v24;
            }
            if (v16 < v20 || v16 >= v19)
            {
                v12 = v35;
            }
            else
            {
                v12 = v35;
                if (v35 + v26 >= v38 && v35 + v26 < v18)
                    * (_WORD*)(*(_DWORD*)(v25 + *(_DWORD*)& byte_5D4594[3798784]) + v37) = v24;
            }
            if (result >= v20 && result < v19 && v26 + v12 >= v38 && v26 + v12 < v18)
                * (_WORD*)(*(_DWORD*)(v25 + *(_DWORD*)& byte_5D4594[3798784]) + v29) = v24;
            if (v12 >= v20 && v12 < v19)
            {
                if (result + v26 >= v38 && result + v26 < v18)
                    * (_WORD*)(*(_DWORD*)(v27 + *(_DWORD*)& byte_5D4594[3798784]) + v28) = v24;
                if (v12 < v19 && v15 >= v38 && v15 < v18)
                    * (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v15) + v28) = v24;
            }
            if (result < v20 || result >= v19)
            {
                v14 = v23;
            }
            else
            {
                v14 = v23;
                if (v23 >= v38 && v23 < v18)
                {
                    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v23) + v29) = v24;
                    v12 = v35;
                }
            }
        } while (v31 > v32);
    }
    return result;
}

//----- (004B1A60) --------------------------------------------------------
int __cdecl sub_4B1A60(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // edi
    int v5; // esi
    int v6; // ecx
    int v7; // ebp
    int v8; // eax
    _BYTE* v9; // edx
    _BYTE* v10; // edx
    _BYTE* v11; // edx
    _BYTE* v12; // edx
    int v13; // [esp+10h] [ebp-14h]
    int v14; // [esp+14h] [ebp-10h]
    int v15; // [esp+18h] [ebp-Ch]
    int v16; // [esp+1Ch] [ebp-8h]
    int v17; // [esp+20h] [ebp-4h]
    int v18; // [esp+28h] [ebp+4h]
    int v19; // [esp+2Ch] [ebp+8h]
    int v20; // [esp+30h] [ebp+Ch]

    result = *(_DWORD*)& byte_5D4594[810632];
    if (*(_DWORD*)& byte_5D4594[810632])
    {
        v4 = a3;
        v5 = a1;
        if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
        {
            result = sub_4B1E30(a1, a2, a3);
        }
        else
        {
            v6 = 0;
            v18 = 1 - a3;
            v7 = a3;
            v13 = 5 - 2 * a3;
            v16 = 3;
            v8 = 4 * (a2 + a3);
            v15 = v8;
            v9 = (_BYTE*)(v5 + *(_DWORD*)(v8 + *(_DWORD*)& byte_5D4594[3798784]));
            result = *(unsigned __int8*)(&ptr_5D4594_3799572->data[61]);
            *v9 = *(_BYTE*)(result + ((unsigned __int8)* v9 << 8) + *(_DWORD*)& byte_5D4594[810632]);
            v14 = 4 * a2;
            v10 = (_BYTE*)(a3 + v5 + *(_DWORD*)(4 * a2 + *(_DWORD*)& byte_5D4594[3798784]));
            *v10 = *(_BYTE*)(result + ((unsigned __int8)* v10 << 8) + *(_DWORD*)& byte_5D4594[810632]);
            v11 = (_BYTE*)(a3 + v5 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2));
            *v11 = *(_BYTE*)(result + ((unsigned __int8)* v11 << 8) + *(_DWORD*)& byte_5D4594[810632]);
            v17 = 4 * (a2 - a3);
            *(_BYTE*)(v5 + *(_DWORD*)(v17 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                + (*(unsigned __int8*)(*(_DWORD*)(v17 + *(_DWORD*)& byte_5D4594[3798784]) + v5) << 8)
                + *(_DWORD*)& byte_5D4594[810632]);
            *(_BYTE*)(v5 + *(_DWORD*)(v17 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                + (*(unsigned __int8*)(v5 + *(_DWORD*)(v17 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                + *(_DWORD*)& byte_5D4594[810632]);
            v12 = (_BYTE*)(v5 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) - a3);
            *v12 = *(_BYTE*)(result + ((unsigned __int8)* v12 << 8) + *(_DWORD*)& byte_5D4594[810632]);
            *(_BYTE*)(v5 + *(_DWORD*)(4 * a2 + *(_DWORD*)& byte_5D4594[3798784]) - a3) = *(_BYTE*)(result
                + (*(unsigned __int8*)(v5 + *(_DWORD*)(4 * a2 + *(_DWORD*)& byte_5D4594[3798784]) - a3) << 8)
                + *(_DWORD*)& byte_5D4594[810632]);
            *(_BYTE*)(v5 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                + (*(unsigned __int8*)(*(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784]) + v5) << 8)
                + *(_DWORD*)& byte_5D4594[810632]);
            if (a3 > 0)
            {
                v20 = 4 * a2;
                v19 = 4 * (a2 - v4);
                do
                {
                    if (v18 >= 0)
                    {
                        v18 += v13;
                        v13 += 4;
                        --v7;
                        v15 -= 4;
                        v19 += 4;
                    }
                    else
                    {
                        v18 += v16;
                        v13 += 2;
                    }
                    v16 += 2;
                    v20 -= 4;
                    ++v6;
                    v14 += 4;
                    *(_BYTE*)(v5 + v6 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + v6 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + v7 + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + v7 + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + v7 + *(_DWORD*)(v20 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + v7 + *(_DWORD*)(v20 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + v6 + *(_DWORD*)(v19 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + v6 + *(_DWORD*)(v19 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + *(_DWORD*)(v19 + *(_DWORD*)& byte_5D4594[3798784]) - v6) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + *(_DWORD*)(v19 + *(_DWORD*)& byte_5D4594[3798784]) - v6) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + *(_DWORD*)(v20 + *(_DWORD*)& byte_5D4594[3798784]) - v7) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + *(_DWORD*)(v20 + *(_DWORD*)& byte_5D4594[3798784]) - v7) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784]) - v7) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784]) - v7) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    *(_BYTE*)(v5 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784]) - v6) = *(_BYTE*)(result
                        + (*(unsigned __int8*)(v5 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784]) - v6) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                } while (v7 > v6);
            }
        }
    }
    return result;
}

//----- (004B1E30) --------------------------------------------------------
int __cdecl sub_4B1E30(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // edi
    int v5; // ebp
    int v6; // edx
    bool v7; // cc
    unsigned __int8 v8; // dl
    int v9; // esi
    int v10; // ebx
    int v11; // ebx
    int v12; // esi
    int v13; // esi
    int v14; // ebp
    int v15; // edi
    int v16; // ecx
    int v17; // esi
    int v18; // [esp+10h] [ebp-3Ch]
    int v19; // [esp+14h] [ebp-38h]
    int v20; // [esp+18h] [ebp-34h]
    int v21; // [esp+1Ch] [ebp-30h]
    int v22; // [esp+20h] [ebp-2Ch]
    unsigned __int8 v23; // [esp+24h] [ebp-28h]
    int v24; // [esp+24h] [ebp-28h]
    int v25; // [esp+28h] [ebp-24h]
    int v26; // [esp+2Ch] [ebp-20h]
    int v27; // [esp+30h] [ebp-1Ch]
    int v28; // [esp+34h] [ebp-18h]
    int v29; // [esp+38h] [ebp-14h]
    int v30; // [esp+3Ch] [ebp-10h]
    int v31; // [esp+3Ch] [ebp-10h]
    int v32; // [esp+40h] [ebp-Ch]
    int v33; // [esp+44h] [ebp-8h]
    int v34; // [esp+48h] [ebp-4h]
    int i; // [esp+50h] [ebp+4h]
    int v36; // [esp+58h] [ebp+Ch]

    result = *(_DWORD*)& byte_5D4594[810632];
    if (*(_DWORD*)& byte_5D4594[810632])
    {
        v4 = a3;
        v32 = 0;
        v22 = 1 - a3;
        v25 = 5 - 2 * a3;
        v33 = a3;
        v29 = 3;
        v5 = ptr_5D4594_3799572->data[3];
        v23 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
        v6 = ptr_5D4594_3799572->data[1];
        v18 = ptr_5D4594_3799572->data[4];
        result = a2;
        v21 = v6;
        v7 = a1 < v6;
        v8 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
        v9 = a2 + a3;
        v19 = ptr_5D4594_3799572->data[3];
        v20 = ptr_5D4594_3799572->data[2];
        v30 = a2 + a3;
        if (!v7 && a1 < v5 && v9 >= ptr_5D4594_3799572->data[2] && v9 < v18)
        {
            v5 = ptr_5D4594_3799572->data[3];
            *(_BYTE*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * (a2 + a3))) = *(_BYTE*)(v23
                + (*(unsigned __int8*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * (a2 + a3))) << 8)
                + *(_DWORD*)& byte_5D4594[810632]);
        }
        v10 = a1 + a3;
        if (a1 + a3 >= v21)
        {
            if (v10 < v5 && a2 >= v20 && a2 < v18)
            {
                v5 = v19;
                *(_BYTE*)(a1 + a3 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = *(_BYTE*)(v23
                    + (*(unsigned __int8*)(a1 + a3 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
                v10 = a1 + a3;
            }
            if (v10 >= v21 && v10 < v5 && a2 >= v20 && a2 < v18)
            {
                v5 = v19;
                *(_BYTE*)(v10 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = *(_BYTE*)(v23
                    + (*(unsigned __int8*)(v10 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
            }
        }
        v11 = a2 - a3;
        if (a1 >= v21)
        {
            if (a1 < v5 && v11 >= v20 && v11 < v18)
            {
                v5 = v19;
                *(_BYTE*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * (a2 - a3))) = *(_BYTE*)(v23
                    + (*(unsigned __int8*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * (a2 - a3))) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
                v11 = a2 - a3;
            }
            if (a1 >= v21 && a1 < v5 && v11 >= v20 && v11 < v18)
            {
                *(_BYTE*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v11)) = *(_BYTE*)(v23
                    + (*(unsigned __int8*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v11)) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
                v11 = a2 - a3;
            }
        }
        v12 = a1 - a3;
        if (a1 - a3 >= v21)
        {
            if (v12 < v19 && a2 >= v20 && a2 < v18)
            {
                *(_BYTE*)(v12 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = *(_BYTE*)(v23
                    + (*(unsigned __int8*)(v12 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
                v8 = v23;
                v11 = a2 - a3;
            }
            if (v12 >= v21 && v12 < v19 && a2 >= v20 && a2 < v18)
            {
                *(_BYTE*)(v12 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = *(_BYTE*)(v8
                    + (*(unsigned __int8*)(v12 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
                v8 = v23;
                v11 = a2 - a3;
            }
        }
        if (a1 >= v21 && a1 < v19)
        {
            if (v30 >= v20 && v30 < v18)
            {
                *(_BYTE*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v30)) = *(_BYTE*)(v8
                    + (*(unsigned __int8*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v30)) << 8)
                    + *(_DWORD*)& byte_5D4594[810632]);
                v8 = v23;
            }
            v11 = a2 - a3;
        }
        if (a3 > 0)
        {
            v36 = a1 - a3;
            v31 = 4 * v30;
            v28 = a1 + v4;
            v24 = 4 * v11;
            v34 = a1 - a2;
            v13 = a2 - a1;
            result = v36;
            v14 = a1;
            v27 = 4 * a2;
            v26 = 4 * a2;
            for (i = a2 - a1; ; v13 = i)
            {
                if (v22 >= 0)
                {
                    v22 += v25;
                    v25 += 4;
                    --v33;
                    v31 -= 4;
                    v15 = v28 - 1;
                    ++result;
                    --v28;
                    v24 += 4;
                    v36 = result;
                }
                else
                {
                    v22 += v29;
                    v15 = v28;
                    v25 += 2;
                }
                v29 += 2;
                ++v14;
                ++v32;
                v26 -= 4;
                --a2;
                v27 += 4;
                if (v14 < v21 || v14 >= v19)
                    goto LABEL_54;
                v16 = v13 + v15;
                v17 = v20;
                if (v16 >= v20 && v16 < v18)
                    break;
            LABEL_55:
                if (v15 >= v21 && v15 < v19)
                {
                    if (v14 + i >= v17 && v14 + i < v18)
                    {
                        v17 = v20;
                        *(_BYTE*)(v15 + *(_DWORD*)(v27 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                            + (*(unsigned __int8*)(*(_DWORD*)(v27 + *(_DWORD*)& byte_5D4594[3798784]) + v15) << 8)
                            + *(_DWORD*)& byte_5D4594[810632]);
                        result = v36;
                    }
                    if (v15 < v19 && a2 >= v17 && a2 < v18)
                    {
                        *(_BYTE*)(v15 + *(_DWORD*)(v26 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                            + (*(unsigned __int8*)(*(_DWORD*)(v26 + *(_DWORD*)& byte_5D4594[3798784]) + v15) << 8)
                            + *(_DWORD*)& byte_5D4594[810632]);
                        result = v36;
                    }
                }
                if (v14 >= v21 && v14 < v19 && result + i >= v17 && result + i < v18)
                {
                    *(_BYTE*)(v14 + *(_DWORD*)(v24 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                        + (*(unsigned __int8*)(*(_DWORD*)(v24 + *(_DWORD*)& byte_5D4594[3798784]) + v14) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    result = v36;
                }
                if (v34 + a2 >= v21 && v34 + a2 < v19 && result + i >= v17 && result + i < v18)
                {
                    *(_BYTE*)(v34 + a2 + *(_DWORD*)(v24 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                        + (*(unsigned __int8*)(*(_DWORD*)(v24 + *(_DWORD*)& byte_5D4594[3798784]) + v34 + a2) << 8)
                        + *(_DWORD*)& byte_5D4594[810632]);
                    result = v36;
                }
                if (result >= v21 && result < v19)
                {
                    if (a2 >= v17 && a2 < v18)
                    {
                        *(_BYTE*)(result + *(_DWORD*)(v26 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                            + (*(unsigned __int8*)(result + *(_DWORD*)(v26 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                            + *(_DWORD*)& byte_5D4594[810632]);
                        result = v36;
                    }
                    if (result < v19 && v14 + i >= v17 && v14 + i < v18)
                        * (_BYTE*)(result + *(_DWORD*)(v27 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                            + (*(unsigned __int8*)(result + *(_DWORD*)(v27 + *(_DWORD*)& byte_5D4594[3798784])) << 8)
                            + *(_DWORD*)& byte_5D4594[810632]);
                }
                if (v33 <= v32)
                    return result;
            }
            *(_BYTE*)(v14 + *(_DWORD*)(v31 + *(_DWORD*)& byte_5D4594[3798784])) = *(_BYTE*)(v8
                + (*(unsigned __int8*)(*(_DWORD*)(v31 + *(_DWORD*)& byte_5D4594[3798784]) + v14) << 8)
                + *(_DWORD*)& byte_5D4594[810632]);
            result = v36;
        LABEL_54:
            v17 = v20;
            goto LABEL_55;
        }
    }
    return result;
}

//----- (004B2480) --------------------------------------------------------
_WORD* __cdecl sub_4B2480(int a1, int a2, int a3)
{
    _WORD* result; // eax
    unsigned int v4; // esi
    int v5; // ecx
    _WORD* v6; // ecx
    int v7; // ebp
    int v8; // esi
    int v9; // edi
    _WORD* v10; // ecx
    _WORD* v11; // eax
    int v12; // eax
    _WORD* v13; // eax
    _WORD* v14; // eax
    _WORD* v15; // eax
    _WORD* v16; // eax
    _WORD* v17; // eax
    int v19; // ecx
    _WORD* v20; // eax
    _WORD* v21; // eax
    _WORD* v22; // eax
    _WORD* v23; // eax
    _WORD* v24; // eax
    _WORD* v25; // eax
    _WORD* v26; // eax
    _WORD* v27; // eax
    int v44; // [esp+20h] [ebp-30h]
    int v45; // [esp+24h] [ebp-2Ch]
    int v46; // [esp+28h] [ebp-28h]
    int v47; // [esp+28h] [ebp-28h]
    int v48; // [esp+2Ch] [ebp-24h]
    int v49; // [esp+30h] [ebp-20h]
    int v50; // [esp+30h] [ebp-20h]
    int v51; // [esp+34h] [ebp-1Ch]
    int v52; // [esp+34h] [ebp-1Ch]
    int v53; // [esp+38h] [ebp-18h]
    int v54; // [esp+38h] [ebp-18h]
    int v55; // [esp+3Ch] [ebp-14h]
    _WORD* v56; // [esp+40h] [ebp-10h]
    int v57; // [esp+44h] [ebp-Ch]
    unsigned __int8 v58; // [esp+48h] [ebp-8h]
    int v59; // [esp+48h] [ebp-8h]
    unsigned __int8 v60; // [esp+4Ch] [ebp-4h]
    int v61; // [esp+4Ch] [ebp-4h]
    int v62; // [esp+54h] [ebp+4h]
    int v63; // [esp+54h] [ebp+4h]
    int v64; // [esp+58h] [ebp+8h]

    if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
        return (_WORD*)sub_4B3450(a1, a2, a3);
    v57 = 0;
    v56 = (_WORD*)a3;
    v4 = *(unsigned __int16*)(&ptr_5D4594_3799572->data[61]);
    v55 = 3;
    v58 = (*(_DWORD*)& byte_5D4594[3804368] & v4) >> byte_5D4594[3804380];
    v44 = 1 - a3;
    v60 = ((unsigned __int8) *(_WORD*)(&ptr_5D4594_3799572->data[61]) & byte_5D4594[3804372]) << byte_5D4594[3804384];
    v45 = 5 - 2 * a3;
    v5 = 4 * (a3 + a2);
    v53 = v5;
    v46 = 2 * a1;
    v6 = 2 * a1 + *(_DWORD*)(v5 + *(_DWORD*)& byte_5D4594[3798784]);
    v7 = (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v4) >> byte_5D4594[3804376]);
    v8 = v60;
    v9 = v58;
    *v6 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v6 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v60
                - (unsigned __int8)(((unsigned __int8)v6 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v6) >> byte_5D4594[3804380]) + ((v58 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v6) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376])) >> 2)));
    v49 = 4 * a2;
    v10 = 2 * (a1 + a3) + *(_DWORD*)(4 * a2 + *(_DWORD*)& byte_5D4594[3798784]);
    v59 = 2 * (a1 + a3);
    *v10 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v10 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v60
                - (unsigned __int8)(((unsigned __int8)v10 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v10) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v10) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v10) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v10) >> byte_5D4594[3804376])) >> 2)));
    v11 = v59 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    *v11 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v11 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v60
                - (unsigned __int8)(((unsigned __int8)v11 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v11) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v11) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v11) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v11) >> byte_5D4594[3804376])) >> 2)));
    v12 = 4 * (a2 - a3);
    v61 = v12;
    v13 = 2 * a1 + *(_DWORD*)(v12 + *(_DWORD*)& byte_5D4594[3798784]);
    *v13 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v13 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v8
                - (unsigned __int8)(((unsigned __int8)v13 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v13) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v13) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v13) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v13) >> byte_5D4594[3804376])) >> 2)));
    v51 = 2 * a1;
    v14 = 2 * a1 + *(_DWORD*)(v61 + *(_DWORD*)& byte_5D4594[3798784]);
    *v14 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v14 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v8
                - (unsigned __int8)(((unsigned __int8)v14 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v14) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v14) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v14) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v14) >> byte_5D4594[3804376])) >> 2)));
    v62 = 2 * (a1 - a3);
    v15 = v62 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    *v15 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v15 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v8
                - (unsigned __int8)(((unsigned __int8)v15 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v15) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v15) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v15) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v15) >> byte_5D4594[3804376])) >> 2)));
    v16 = v62 + *(_DWORD*)(4 * a2 + *(_DWORD*)& byte_5D4594[3798784]);
    *v16 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v16 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v8
                - (unsigned __int8)(((unsigned __int8)v16 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v16) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v16) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v16) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v16) >> byte_5D4594[3804376])) >> 2)));
    v17 = v51 + *(_DWORD*)(v53 + *(_DWORD*)& byte_5D4594[3798784]);
    *v17 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
        + 2
        * (unsigned __int8)((((unsigned __int8)v17 & byte_5D4594[3804372]) << byte_5D4594[3804384])
            + ((v8
                - (unsigned __int8)(((unsigned __int8)v17 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v17) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v17) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v17) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v17) >> byte_5D4594[3804376])) >> 2)));
    result = v17;
    if (a3 > 0)
    {
        v52 = v53;
        v19 = v46;
        v64 = v59;
        v48 = v49;
        v47 = v49;
        v50 = v62;
        v54 = v19;
        v63 = v61;
        while (1)
        {
            if (v44 >= 0)
            {
                v44 += v45;
                v45 += 4;
                v56 = (_WORD*)((char*)v56 - 1);
                v64 -= 2;
                v52 -= 4;
                v63 += 4;
                v50 += 2;
            }
            else
            {
                v44 += v55;
                v45 += 2;
            }
            v55 += 2;
            ++v57;
            v48 += 4;
            v47 -= 4;
            v54 -= 2;
            v20 = v19 + 2 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v52);
            *v20 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v20 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v20 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v20) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v20) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v20) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v20) >> byte_5D4594[3804376])) >> 2)));
            v21 = v64 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v48);
            *v21 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v21 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v21 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v21) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v21) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v21) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v21) >> byte_5D4594[3804376])) >> 2)));
            v22 = v64 + *(_DWORD*)(v47 + *(_DWORD*)& byte_5D4594[3798784]);
            *v22 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v22 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v22 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v22) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v22) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v22) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v22) >> byte_5D4594[3804376])) >> 2)));
            v23 = v19 + 2 + *(_DWORD*)(v63 + *(_DWORD*)& byte_5D4594[3798784]);
            *v23 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v23 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v23 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v23) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v23) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v23) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v23) >> byte_5D4594[3804376])) >> 2)));
            v24 = v54 + *(_DWORD*)(v63 + *(_DWORD*)& byte_5D4594[3798784]);
            *v24 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v24 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v24 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v24) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v24) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v24) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v24) >> byte_5D4594[3804376])) >> 2)));
            v25 = v50 + *(_DWORD*)(v47 + *(_DWORD*)& byte_5D4594[3798784]);
            *v25 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v25 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v25 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v25) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v25) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v25) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v25) >> byte_5D4594[3804376])) >> 2)));
            v26 = v50 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v48);
            *v26 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v26 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v26 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v26) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v26) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v26) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v26) >> byte_5D4594[3804376])) >> 2)));
            v27 = v54 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v52);
            *v27 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)((((unsigned __int8)v27 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((v8
                        - (unsigned __int8)(((unsigned __int8)v27 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v27) >> byte_5D4594[3804380]) + ((v9 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v27) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v27) >> byte_5D4594[3804376]) + ((v7 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v27) >> byte_5D4594[3804376])) >> 2)));
            result = v56;
            if ((int)v56 <= v57)
                break;
            v19 += 2;
        }
    }
    return result;
}

//----- (004B3450) --------------------------------------------------------
int __cdecl sub_4B3450(int a1, int a2, int a3)
{
    __int16 v3; // ax
    unsigned __int8 v4; // bp
    unsigned __int8 v5; // dl
    unsigned __int8 v6; // di
    char v7; // bl
    unsigned __int8 v8; // al
    unsigned __int8 v9; // si
    int v10; // ecx
    int v11; // ecx
    int v12; // ecx
    int v13; // ecx
    int result; // eax
    int v15; // eax
    int v16; // ebx
    int v17; // edx
    int v18; // ecx
    int v19; // edx
    int v20; // eax
    int v21; // eax
    _WORD* v22; // eax
    unsigned int v23; // ebx
    int v24; // ecx
    _WORD* v25; // eax
    unsigned int v26; // ebx
    _WORD* v27; // eax
    unsigned int v28; // ebx
    _WORD* v29; // eax
    unsigned int v30; // ebx
    _WORD* v31; // eax
    unsigned int v32; // ebx
    _WORD* v33; // eax
    unsigned int v34; // ebx
    _WORD* v35; // eax
    unsigned int v36; // ebx
    _WORD* v37; // eax
    unsigned int v38; // ebx
    _WORD* v39; // [esp+1Ch] [ebp-54h]
    _WORD* v40; // [esp+1Ch] [ebp-54h]
    _WORD* v41; // [esp+1Ch] [ebp-54h]
    _WORD* v42; // [esp+1Ch] [ebp-54h]
    _WORD* v43; // [esp+1Ch] [ebp-54h]
    _WORD* v44; // [esp+1Ch] [ebp-54h]
    _WORD* v45; // [esp+1Ch] [ebp-54h]
    _WORD* v46; // [esp+1Ch] [ebp-54h]
    int v47; // [esp+1Ch] [ebp-54h]
    int v48; // [esp+20h] [ebp-50h]
    int v49; // [esp+24h] [ebp-4Ch]
    int v50; // [esp+28h] [ebp-48h]
    unsigned int v51; // [esp+2Ch] [ebp-44h]
    unsigned int v52; // [esp+2Ch] [ebp-44h]
    unsigned int v53; // [esp+2Ch] [ebp-44h]
    unsigned int v54; // [esp+2Ch] [ebp-44h]
    unsigned int v55; // [esp+2Ch] [ebp-44h]
    unsigned int v56; // [esp+2Ch] [ebp-44h]
    unsigned int v57; // [esp+2Ch] [ebp-44h]
    unsigned int v58; // [esp+2Ch] [ebp-44h]
    int v59; // [esp+2Ch] [ebp-44h]
    int v60; // [esp+30h] [ebp-40h]
    int v61; // [esp+34h] [ebp-3Ch]
    int v62; // [esp+34h] [ebp-3Ch]
    int v63; // [esp+38h] [ebp-38h]
    int v64; // [esp+38h] [ebp-38h]
    int v65; // [esp+3Ch] [ebp-34h]
    int v66; // [esp+40h] [ebp-30h]
    int v67; // [esp+44h] [ebp-2Ch]
    int v68; // [esp+44h] [ebp-2Ch]
    int v69; // [esp+48h] [ebp-28h]
    int v70; // [esp+4Ch] [ebp-24h]
    unsigned __int8 v71; // [esp+50h] [ebp-20h]
    int v72; // [esp+50h] [ebp-20h]
    int v73; // [esp+54h] [ebp-1Ch]
    int v74; // [esp+54h] [ebp-1Ch]
    int v75; // [esp+58h] [ebp-18h]
    unsigned __int8 v76; // [esp+5Ch] [ebp-14h]
    int v77; // [esp+5Ch] [ebp-14h]
    int v78; // [esp+60h] [ebp-10h]
    int v79; // [esp+64h] [ebp-Ch]
    unsigned __int8 v80; // [esp+68h] [ebp-8h]
    int i; // [esp+68h] [ebp-8h]
    int v82; // [esp+78h] [ebp+8h]
    int v83; // [esp+7Ch] [ebp+Ch]

    v79 = a3;
    v65 = 1 - a3;
    v66 = 5 - 2 * a3;
    v60 = ptr_5D4594_3799572->data[1];
    v48 = ptr_5D4594_3799572->data[3];
    v3 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
    v49 = ptr_5D4594_3799572->data[2];
    v50 = ptr_5D4594_3799572->data[4];
    v78 = 0;
    v75 = 3;
    v71 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v3) >> byte_5D4594[3804376];
    v4 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v3) >> byte_5D4594[3804376];
    v76 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v3) >> byte_5D4594[3804380];
    v5 = byte_5D4594[3804372];
    v6 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v3) >> byte_5D4594[3804380];
    v7 = v3 & byte_5D4594[3804372];
    v8 = byte_5D4594[3804384];
    v73 = a3 + a2;
    v80 = v7 << byte_5D4594[3804384];
    v9 = v7 << byte_5D4594[3804384];
    if (a1 >= v60 && a1 < v48 && v73 >= v49 && v73 < v50)
    {
        v39 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v73) + 2 * a1);
        v51 = (unsigned __int16)* v39;
        *v39 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
            + 2
            * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v51) >> byte_5D4594[3804376])
                + ((v71
                    - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v51) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v51) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v51) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v39 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v80 - (unsigned __int8)((*(_BYTE*)v39 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
        v8 = byte_5D4594[3804384];
        v5 = byte_5D4594[3804372];
    }
    v10 = a3 + a1;
    v63 = a3 + a1;
    if (a3 + a1 < v60)
        goto LABEL_17;
    if (v10 < v48)
    {
        if (a2 >= v49 && a2 < v50)
        {
            v40 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) + 2 * v63);
            v52 = (unsigned __int16)* v40;
            *v40 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v52) >> byte_5D4594[3804376])
                    + ((v71
                        - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v52) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v52) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v52) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v40 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v40 & v5) << v8)) >> 2)));
            v8 = byte_5D4594[3804384];
            v5 = byte_5D4594[3804372];
        }
        v10 = a3 + a1;
    }
    if (v10 < v60 || v10 >= v48)
        goto LABEL_17;
    v11 = a2;
    if (a2 >= v49 && a2 < v50)
    {
        v41 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) + 2 * v63);
        v53 = (unsigned __int16)* v41;
        *v41 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
            + 2
            * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v53) >> byte_5D4594[3804376])
                + ((v71
                    - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v53) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v53) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v53) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v41 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v41 & v5) << v8)) >> 2)));
        v8 = byte_5D4594[3804384];
        v5 = byte_5D4594[3804372];
    LABEL_17:
        v11 = a2;
    }
    v67 = v11 - a3;
    if (a1 >= v60 && a1 < v48 && v67 >= v49 && v67 < v50)
    {
        v42 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v67) + 2 * a1);
        v54 = (unsigned __int16)* v42;
        *v42 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
            + 2
            * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v54) >> byte_5D4594[3804376])
                + ((v71
                    - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v54) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v54) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v54) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v42 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v42 & v5) << v8)) >> 2)));
        v8 = byte_5D4594[3804384];
        v5 = byte_5D4594[3804372];
    }
    if (a1 >= v60 && a1 < v48 && v67 >= v49 && v67 < v50)
    {
        v43 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v67) + 2 * a1);
        v55 = (unsigned __int16)* v43;
        *v43 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
            + 2
            * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v55) >> byte_5D4594[3804376])
                + ((v71
                    - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v55) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v55) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v55) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v43 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v43 & v5) << v8)) >> 2)));
        v8 = byte_5D4594[3804384];
        v5 = byte_5D4594[3804372];
    }
    v12 = a1 - a3;
    v61 = a1 - a3;
    if (a1 - a3 >= v60)
    {
        if (v12 < v48)
        {
            if (a2 >= v49 && a2 < v50)
            {
                v44 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) + 2 * v61);
                v56 = (unsigned __int16)* v44;
                *v44 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                    + 2
                    * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v56) >> byte_5D4594[3804376])
                        + ((v71
                            - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v56) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v56) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v56) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v44 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v44 & v5) << v8)) >> 2)));
                v8 = byte_5D4594[3804384];
                v5 = byte_5D4594[3804372];
            }
            v12 = a1 - a3;
        }
        if (v12 >= v60 && v12 < v48 && a2 >= v49 && a2 < v50)
        {
            v45 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) + 2 * v61);
            v57 = (unsigned __int16)* v45;
            *v45 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v57) >> byte_5D4594[3804376])
                    + ((v71
                        - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v57) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v57) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v57) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v45 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v45 & v5) << v8)) >> 2)));
            v8 = byte_5D4594[3804384];
            v5 = byte_5D4594[3804372];
        }
    }
    v13 = a1;
    if (a1 >= v60 && a1 < v48)
    {
        if (v73 >= v49 && v73 < v50)
        {
            v46 = (_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v73) + 2 * a1);
            v58 = (unsigned __int16)* v46;
            *v46 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v58) >> byte_5D4594[3804376])
                    + ((v71
                        - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v58) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v58) >> byte_5D4594[3804380]) + ((v76 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v58) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v46 & v5) << v8) + ((v80 - (unsigned __int8)((*(_BYTE*)v46 & v5) << v8)) >> 2)));
        }
        v13 = a1;
    }
    result = a3;
    if (a3 > 0)
    {
        v59 = a3 + a2;
        v15 = a2;
        v82 = a1 - a3;
        v72 = 2 * v61;
        v69 = 4 * v15;
        v83 = v13;
        v62 = 2 * v13;
        v47 = 4 * v67;
        v64 = 2 * v63;
        v16 = 2 * v13;
        v17 = v15 - v13;
        v18 = v13 - v15;
        v70 = v15;
        v74 = v16;
        v68 = v17;
        for (i = v18; ; v18 = i)
        {
            if (v65 >= 0)
            {
                v65 += v66;
                v66 += 4;
                --v79;
                v64 -= 2;
                v47 += 4;
                v72 += 2;
                ++v82;
                v19 = --v59;
            }
            else
            {
                v65 += v75;
                v19 = v59;
                v66 += 2;
            }
            v75 += 2;
            ++v78;
            v62 += 2;
            v69 -= 4;
            v20 = v70 + 1;
            v70 = v20;
            v74 -= 2;
            v21 = v18 + v20;
            --v83;
            v77 = v21;
            if (v21 >= v60 && v21 < v48 && v19 >= v49 && v19 < v50)
            {
                v22 = (_WORD*)(v62 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v19));
                v23 = (unsigned __int16)* v22;
                *v22 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                    + 2
                    * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v23) >> byte_5D4594[3804376])
                        + ((v4
                            - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v23) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v23) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v23) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v22 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v22 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
                v21 = v77;
            }
            v24 = v59 + i;
            if (v59 + i >= v60)
            {
                if (v24 < v48 && v70 >= v49 && v70 < v50)
                {
                    v25 = (_WORD*)(v64 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v70));
                    v26 = (unsigned __int16)* v25;
                    v24 = v59 + i;
                    *v25 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                        + 2
                        * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v26) >> byte_5D4594[3804376])
                            + ((v4
                                - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v26) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v26) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v26) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v25 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v25 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
                    v21 = v77;
                }
                if (v24 >= v60 && v24 < v48 && v68 + v83 >= v49 && v68 + v83 < v50)
                {
                    v27 = (_WORD*)(v64 + *(_DWORD*)(v69 + *(_DWORD*)& byte_5D4594[3798784]));
                    v28 = (unsigned __int16)* v27;
                    *v27 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                        + 2
                        * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v28) >> byte_5D4594[3804376])
                            + ((v4
                                - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v28) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v28) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v28) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v27 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v27 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
                    v21 = v77;
                }
            }
            if (v21 >= v60 && v21 < v48 && v68 + v82 >= v49 && v68 + v82 < v50)
            {
                v29 = (_WORD*)(v62 + *(_DWORD*)(v47 + *(_DWORD*)& byte_5D4594[3798784]));
                v30 = (unsigned __int16)* v29;
                *v29 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                    + 2
                    * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v30) >> byte_5D4594[3804376])
                        + ((v4
                            - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v30) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v30) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v30) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v29 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v29 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
            }
            if (v83 >= v60 && v83 < v48 && v68 + v82 >= v49 && v68 + v82 < v50)
            {
                v31 = (_WORD*)(v74 + *(_DWORD*)(v47 + *(_DWORD*)& byte_5D4594[3798784]));
                v32 = (unsigned __int16)* v31;
                *v31 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                    + 2
                    * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v32) >> byte_5D4594[3804376])
                        + ((v4
                            - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v32) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v32) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v32) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v31 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v31 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
            }
            if (v82 >= v60)
            {
                if (v82 < v48 && v68 + v83 >= v49 && v68 + v83 < v50)
                {
                    v33 = (_WORD*)(v72 + *(_DWORD*)(v69 + *(_DWORD*)& byte_5D4594[3798784]));
                    v34 = (unsigned __int16)* v33;
                    *v33 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                        + 2
                        * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v34) >> byte_5D4594[3804376])
                            + ((v4
                                - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v34) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v34) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v34) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v33 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v33 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
                }
                if (v82 < v48 && v70 >= v49 && v70 < v50)
                {
                    v35 = (_WORD*)(v72 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v70));
                    v36 = (unsigned __int16)* v35;
                    *v35 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                        + 2
                        * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v36) >> byte_5D4594[3804376])
                            + ((v4
                                - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v36) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v36) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v36) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v35 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v35 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
                }
            }
            if (v83 >= v60 && v83 < v48 && v59 >= v49 && v59 < v50)
            {
                v37 = (_WORD*)(v74 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v59));
                v38 = (unsigned __int16)* v37;
                *v37 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                    + 2
                    * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v38) >> byte_5D4594[3804376])
                        + ((v4
                            - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v38) >> byte_5D4594[3804376])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v38) >> byte_5D4594[3804380]) + ((v6 - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v38) >> byte_5D4594[3804380])) >> 2))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)((((unsigned __int8)* v37 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((v9 - (unsigned __int8)(((unsigned __int8)* v37 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 2)));
            }
            result = v79;
            if (v79 <= v78)
                break;
        }
    }
    return result;
}

//----- (004B4860) --------------------------------------------------------
int __cdecl sub_4B4860(int a1, int a2, int a3, int a4)
{
    int v4; // edi
    int v5; // eax
    int result; // eax
    int v7; // eax
    int v8; // eax
    int v9; // ebx
    int v10; // edi
    int v11; // eax
    int v12; // eax
    int v13; // eax
    int v14; // eax

    v4 = *(_DWORD*)(a1 + 32);
    switch (a2)
    {
    case 5:
        goto LABEL_22;
    case 6:
    case 7:
        v9 = a3;
        v10 = (unsigned __int16)a3;
        sub_46AA60((_DWORD*)a1, &a4, &a3);
        if (v10 > * (int*)(a1 + 8) + a4 - 10)
            v10 = *(_DWORD*)(a1 + 8) + a4 - 10;
        sub_46A9B0(*(_DWORD * *)(a1 + 400), v10 - a4 - 5, 0);
        nox_window_call_field_94(a1, 0x4000, 0, v9);
        return 1;
    case 8:
        v8 = *(_DWORD*)(a1 + 44);
        if (!(v8 & 0x100))
            goto LABEL_22;
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, 0);
        result = 1;
        break;
    case 17:
        v5 = *(_DWORD*)(a1 + 44);
        if (!(v5 & 0x100))
            goto LABEL_22;
        sub_46AFE0(a1, *(_DWORD*)(a1 + 72));
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16389, a1, 0);
        sub_46B500(a1);
        result = 1;
        break;
    case 18:
        v7 = *(_DWORD*)(a1 + 44);
        if (v7 & 0x100)
        {
            sub_46AFE0(a1, *(_DWORD*)(a1 + 64));
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16390, a1, 0);
            result = 1;
        }
        else
        {
        LABEL_22:
            result = 1;
        }
        break;
    case 21:
        switch (a3)
        {
        case 15:
        case 208:
            if (a4 != 2)
                goto LABEL_22;
            sub_46A8A0();
            result = 1;
            break;
        case 200:
            if (a4 == 2)
                sub_46A8B0();
            goto LABEL_22;
        case 203:
            if (a4 != 2)
                goto LABEL_22;
            v13 = *(_DWORD*)(v4 + 12);
            if (v13 >= *(int*)(v4 + 4) - 1)
                goto LABEL_22;
            v14 = v13 + 2;
            *(_DWORD*)(v4 + 12) = v14;
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v14);
            sub_46A9B0(
                *(_DWORD * *)(a1 + 400),
                (__int64)((double)(int)(*(_DWORD*)(v4 + 12) - *(_DWORD*)v4) * *(float*)(v4 + 8)),
                0);
            result = 1;
            break;
        case 205:
            if (a4 != 2)
                goto LABEL_22;
            v11 = *(_DWORD*)(v4 + 12);
            if (v11 <= *(int*)v4 + 1)
                goto LABEL_22;
            v12 = v11 - 2;
            *(_DWORD*)(v4 + 12) = v12;
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v12);
            sub_46A9B0(
                *(_DWORD * *)(a1 + 400),
                (__int64)((double)(int)(*(_DWORD*)(v4 + 12) - *(_DWORD*)v4) * *(float*)(v4 + 8)),
                0);
            result = 1;
            break;
        default:
            goto LABEL_23;
        }
        break;
    default:
    LABEL_23:
        result = 0;
        break;
    }
    return result;
}

//----- (004B4BA0) --------------------------------------------------------
int __cdecl sub_4B4BA0(int a1, int a2, unsigned int a3, int a4)
{
    int v4; // edi
    int v5; // eax
    int result; // eax
    int v7; // eax
    int v8; // eax
    int v9; // ebx
    signed int v10; // edi
    int v11; // eax
    int v12; // eax
    int v13; // eax
    int v14; // eax

    v4 = *(_DWORD*)(a1 + 32);
    switch (a2)
    {
    case 5:
        goto LABEL_22;
    case 6:
    case 7:
        v9 = a3;
        v10 = a3 >> 16;
        sub_46AA60((_DWORD*)a1, &a3, &a4);
        if (v10 > * (int*)(a1 + 12) + a4 - 10)
            v10 = *(_DWORD*)(a1 + 12) + a4 - 10;
        sub_46A9B0(*(_DWORD * *)(a1 + 400), 0, v10 - a4 - 5);
        nox_window_call_field_94(a1, 0x4000, 0, v9);
        return 1;
    case 8:
        v8 = *(_DWORD*)(a1 + 44);
        if (!(v8 & 0x100))
            goto LABEL_22;
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, 0);
        result = 1;
        break;
    case 17:
        v5 = *(_DWORD*)(a1 + 44);
        if (!(v5 & 0x100))
            goto LABEL_22;
        sub_46AFE0(a1, *(_DWORD*)(a1 + 72));
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16389, a1, 0);
        sub_46B500(a1);
        result = 1;
        break;
    case 18:
        v7 = *(_DWORD*)(a1 + 44);
        if (v7 & 0x100)
        {
            sub_46AFE0(a1, *(_DWORD*)(a1 + 64));
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16390, a1, 0);
            result = 1;
        }
        else
        {
        LABEL_22:
            result = 1;
        }
        break;
    case 21:
        switch (a3)
        {
        case 0xFu:
        case 0xCDu:
            if (a4 != 2)
                goto LABEL_22;
            sub_46A8A0();
            result = 1;
            break;
        case 0xC8u:
            if (a4 != 2)
                goto LABEL_22;
            v11 = *(_DWORD*)(v4 + 12);
            if (v11 >= *(int*)(v4 + 4) - 1)
                goto LABEL_22;
            v12 = v11 + 2;
            *(_DWORD*)(v4 + 12) = v12;
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v12);
            sub_46A9B0(
                *(_DWORD * *)(a1 + 400),
                0,
                (__int64)((double)(int)(*(_DWORD*)(v4 + 4) - *(_DWORD*)(v4 + 12)) * *(float*)(v4 + 8)));
            result = 1;
            break;
        case 0xCBu:
            if (a4 == 2)
                sub_46A8B0();
            goto LABEL_22;
        case 0xD0u:
            if (a4 != 2)
                goto LABEL_22;
            v13 = *(_DWORD*)(v4 + 12);
            if (v13 <= *(int*)v4 + 1)
                goto LABEL_22;
            v14 = v13 - 2;
            *(_DWORD*)(v4 + 12) = v14;
            nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v14);
            sub_46A9B0(
                *(_DWORD * *)(a1 + 400),
                0,
                (__int64)((double)(int)(*(_DWORD*)(v4 + 4) - *(_DWORD*)(v4 + 12)) * *(float*)(v4 + 8)));
            result = 1;
            break;
        default:
            goto LABEL_23;
        }
        break;
    default:
    LABEL_23:
        result = 0;
        break;
    }
    return result;
}

//----- (004B4EE0) --------------------------------------------------------
_DWORD* __cdecl sub_4B4EE0(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7, float* a8)
{
    int v8; // eax
    int v9; // ebp
    _DWORD* v10; // edi
    int v11; // eax
    double v12; // st7
    float* v13; // edx

    v8 = a7[2];
    if (v8 & 0x10)
    {
        v9 = a6;
        v10 = nox_window_new(a1, a2 | 0x100, a3, a4, a5, a6, sub_4B5010);
        sub_4B51A0((int)v10);
    }
    else
    {
        if (!(v8 & 8))
            return 0;
        v9 = a6;
        v10 = nox_window_new(a1, a2 | 0x100, a3, a4, a5, a6, sub_4B5320);
        sub_4B5500((int)v10);
    }
    if (v10)
    {
        if (!a7[4])
            a7[4] = v10;
        sub_46AF80_copy_window_part((int)v10, a7);
        sub_4B5640((int)v10, a2 | 0x100, (int)a7);
        v11 = *(_DWORD*)a8;
        if (*((_DWORD*)a8 + 1) == *(_DWORD*)a8)
            * ((_DWORD*)a8 + 1) = v11 + 1;
        if (a7[2] & 0x10)
            v12 = (double)(a5 - 10) / (double)(int)(*((_DWORD*)a8 + 1) - v11);
        else
            v12 = (double)(v9 - 10) / (double)(int)(*((_DWORD*)a8 + 1) - v11);
        a8[2] = v12;
        v13 = (float*)nox_malloc(0x10u);
        *v13 = *a8;
        v13[1] = a8[1];
        v13[2] = a8[2];
        v13[3] = a8[3];
        v10[8] = v13;
    }
    return v10;
}

//----- (004B5010) --------------------------------------------------------
int __cdecl sub_4B5010(int a1, unsigned int a2, int a3, int a4)
{
    int v4; // edi
    int v5; // esi
    int v6; // esi
    int v7; // eax
    int v8; // eax
    int v10; // ebx
    int v11; // ecx
    int v12; // eax
    __int64 v13; // rax
    int v14; // ecx
    int v15; // eax
    int v16; // edx
    double v17; // st7
    int* v18; // [esp-4h] [ebp-Ch]

    v4 = a1;
    v5 = *(_DWORD*)(a1 + 32);
    if (a2 > 0x4000)
    {
        if (a2 == 16394)
        {
            if (a3 >= *(int*)v5 && a3 <= *(int*)(v5 + 4))
            {
                v17 = (double)a3;
                *(_DWORD*)(v5 + 12) = a3;
                sub_46A9B0(*(_DWORD * *)(v4 + 400), (__int64)(v17 * *(float*)(v5 + 8)), 0);
            }
        }
        else if (a2 == 16395)
        {
            v14 = a3;
            v15 = a4;
            *(_DWORD*)v5 = a3;
            *(_DWORD*)(v5 + 4) = v15;
            v16 = *(_DWORD*)(v4 + 8) - 10;
            *(_DWORD*)(v5 + 12) = v14;
            a3 = v15 - v14;
            *(float*)(v5 + 8) = (double)v16 / (double)(v15 - v14);
            sub_46A9B0(*(_DWORD * *)(v4 + 400), 0, 0);
            return 0;
        }
        return 0;
    }
    if (a2 == 0x4000)
    {
        v10 = (unsigned __int16)a4;
        sub_46AA60((_DWORD*)a1, &a3, &a1);
        if (v10 < a3)
        {
            sub_46A9B0(*(_DWORD * *)(v4 + 400), 0, 0);
            v11 = *(_DWORD*)v5;
        LABEL_15:
            *(_DWORD*)(v5 + 12) = v11;
            goto LABEL_16;
        }
        v12 = *(_DWORD*)(v4 + 8);
        if (v10 < v12 + a3)
        {
            a4 = v10 - a3;
            v13 = (__int64)((double)(v10 - a3) / *(float*)(v5 + 8));
            v11 = *(_DWORD*)(v5 + 4);
            *(_DWORD*)(v5 + 12) = v13;
            if ((int)v13 > v11)
                goto LABEL_15;
        }
        else
        {
            sub_46A9B0(*(_DWORD * *)(v4 + 400), v12 - *(_DWORD*)(*(_DWORD*)(v4 + 400) + 8), 0);
            *(_DWORD*)(v5 + 12) = *(_DWORD*)(v5 + 4);
        }
    LABEL_16:
        nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16393, v4, *(_DWORD*)(v5 + 12));
        return 0;
    }
    if (a2 == 2)
    {
        free(*(LPVOID*)(a1 + 32));
        return 0;
    }
    if (a2 != 23)
        return 0;
    v6 = a3;
    v7 = *(_DWORD*)(a1 + 36);
    if (a3)
        LOBYTE(v7) = v7 | 2;
    else
        LOBYTE(v7) = v7 & 0xFD;
    v18 = (int*)a1;
    *(_DWORD*)(a1 + 36) = v7;
    v8 = sub_46B0A0(v18);
    nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16387, v6, v8);
    return 1;
}

//----- (004B51A0) --------------------------------------------------------
int __cdecl sub_4B51A0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
            result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4860, sub_4B51E0, 0);
        else
            result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4860, sub_4B52C0, 0);
    }
    return result;
}

//----- (004B51E0) --------------------------------------------------------
int __cdecl sub_4B51E0(int a1, int a2)
{
    int v2; // ebp
    int v3; // ebx
    int v4; // edi
    int xLeft; // [esp+10h] [ebp-8h]
    int yTop; // [esp+14h] [ebp-4h]

    v2 = *(_DWORD*)(a2 + 28);
    v3 = *(_DWORD*)(a2 + 20);
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if (*(_BYTE*)(a1 + 4) & 8)
    {
        if (*(_BYTE*)a2 & 2 && *(_DWORD*)(a2 + 36) != 0x80000000)
        {
            sub_434460(*(_DWORD*)(a2 + 36));
            sub_49CC70(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        }
    }
    else
    {
        v3 = *(_DWORD*)(a2 + 44);
    }
    if (v3 != 0x80000000)
    {
        sub_434460(v3);
        sub_49CE30(xLeft + 1, yTop + 1, *(_DWORD*)(a1 + 8) - 2, *(_DWORD*)(a1 + 12) - 2);
    }
    v4 = yTop + *(_DWORD*)(a1 + 12) / 2;
    if (v2 != 0x80000000)
    {
        sub_434460(v2);
        sub_49CE30(xLeft, v4 - 1, *(_DWORD*)(a1 + 8), 3);
    }
    return 1;
}

//----- (004B52C0) --------------------------------------------------------
int __cdecl sub_4B52C0(int a1, int a2)
{
    int v2; // esi
    int v4; // [esp+Ch] [ebp-8h]
    int v5; // [esp+10h] [ebp-4h]

    v2 = *(_DWORD*)(a2 + 24);
    sub_46AA60((_DWORD*)a1, &v4, &v5);
    if (!(*(_BYTE*)(a1 + 4) & 8))
        v2 = *(_DWORD*)(a2 + 48);
    if (v2)
        sub_47D2C0(v2, v4, v5);
    return 1;
}

//----- (004B5320) --------------------------------------------------------
int __cdecl sub_4B5320(int a1, unsigned int a2, int a3, unsigned int a4)
{
    int v4; // edi
    int v5; // esi
    signed int v6; // ebx
    int v7; // eax
    __int64 v8; // rax
    int v9; // ecx
    int v11; // esi
    int v12; // eax
    int v13; // eax
    unsigned int v14; // eax
    int v15; // ecx
    int v16; // eax
    double v17; // st7
    int v18; // eax
    int v19; // eax
    int* v20; // [esp-4h] [ebp-Ch]

    v4 = a1;
    v5 = *(_DWORD*)(a1 + 32);
    if (a2 > 0x4007)
    {
        if (a2 == 16394)
        {
            if (a3 >= *(int*)v5)
            {
                v18 = *(_DWORD*)(v5 + 4);
                if (a3 <= v18)
                {
                    v19 = v18 - a3;
                    *(_DWORD*)(v5 + 12) = a3;
                    a3 = v19;
                    sub_46A9B0(*(_DWORD * *)(v4 + 400), 0, (__int64)((double)v19 * *(float*)(v5 + 8)));
                }
            }
        }
        else if (a2 == 16395)
        {
            v14 = a4;
            v15 = a3;
            *(_DWORD*)(v5 + 4) = a4;
            *(_DWORD*)v5 = v15;
            a3 = v14 - v15;
            v16 = *(_DWORD*)(v4 + 12);
            *(_DWORD*)(v5 + 12) = v15;
            v17 = (double)a3;
            a3 = v16 - 10;
            *(float*)(v5 + 8) = (double)(v16 - 10) / v17;
            sub_46A9B0(*(_DWORD * *)(v4 + 400), 0, (__int64)(v17 * *(float*)(v5 + 8)));
            return 0;
        }
        return 0;
    }
    switch (a2)
    {
    case 0x4007u:
        nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16396, a1, *(_DWORD*)(v5 + 12));
        return 0;
    case 2u:
        free(*(LPVOID*)(a1 + 32));
        return 0;
    case 0x17u:
        v11 = a3;
        v12 = *(_DWORD*)(a1 + 36);
        if (a3)
            LOBYTE(v12) = v12 | 2;
        else
            LOBYTE(v12) = v12 & 0xFD;
        v20 = (int*)a1;
        *(_DWORD*)(a1 + 36) = v12;
        v13 = sub_46B0A0(v20);
        nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16387, v11, v13);
        return 1;
    }
    if (a2 != 0x4000)
        return 0;
    v6 = a4 >> 16;
    sub_46AA60((_DWORD*)a1, &a1, &a3);
    if (v6 >= a3)
    {
        v7 = *(_DWORD*)(v4 + 12);
        if (v6 < v7 + a3)
        {
            a4 = v6 - a3;
            v8 = (__int64)((double)(v6 - a3) / *(float*)(v5 + 8));
            v9 = *(_DWORD*)(v5 + 4);
            *(_DWORD*)(v5 + 12) = v8;
            if ((int)v8 > v9)
                * (_DWORD*)(v5 + 12) = v9;
            *(_DWORD*)(v5 + 12) = v9 - *(_DWORD*)(v5 + 12);
        }
        else
        {
            sub_46A9B0(*(_DWORD * *)(v4 + 400), 0, v7 - *(_DWORD*)(*(_DWORD*)(v4 + 400) + 12));
            *(_DWORD*)(v5 + 12) = *(_DWORD*)v5;
        }
    }
    else
    {
        sub_46A9B0(*(_DWORD * *)(v4 + 400), 0, 0);
        *(_DWORD*)(v5 + 12) = *(_DWORD*)(v5 + 4);
    }
    nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16393, v4, *(_DWORD*)(v5 + 12));
    return 0;
}

//----- (004B5500) --------------------------------------------------------
int __cdecl sub_4B5500(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
            result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4BA0, sub_4B5540, 0);
        else
            result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4BA0, sub_4B5620, 0);
    }
    return result;
}

//----- (004B5540) --------------------------------------------------------
int __cdecl sub_4B5540(int a1, int a2)
{
    int v2; // ebx
    int v3; // ebp
    int v4; // edi
    int xLeft; // [esp+10h] [ebp-8h]
    int yTop; // [esp+14h] [ebp-4h]

    v2 = *(_DWORD*)(a2 + 28);
    v3 = *(_DWORD*)(a2 + 20);
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if (*(_BYTE*)(a1 + 4) & 8)
    {
        if (*(_BYTE*)a2 & 2)
        {
            v2 = *(_DWORD*)(a2 + 52);
            if (*(_DWORD*)(a2 + 36) != 0x80000000)
            {
                sub_434460(*(_DWORD*)(a2 + 36));
                sub_49CC70(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
            }
        }
    }
    else
    {
        v3 = *(_DWORD*)(a2 + 44);
    }
    if (v3 != 0x80000000)
    {
        sub_434460(v3);
        sub_49CE30(xLeft + 1, yTop + 1, *(_DWORD*)(a1 + 8) - 2, *(_DWORD*)(a1 + 12) - 2);
    }
    v4 = xLeft + *(_DWORD*)(a1 + 8) / 2;
    if (v2 != 0x80000000)
    {
        sub_434460(v2);
        sub_49CE30(v4 - 1, yTop + 4, 3, *(_DWORD*)(a1 + 12) - 8);
    }
    return 1;
}

//----- (004B5620) --------------------------------------------------------
int __cdecl sub_4B5620(_DWORD* a1, int a2)
{
    int v2; // [esp+0h] [ebp-8h]
    int v3; // [esp+4h] [ebp-4h]

    sub_46AA60(a1, &v2, &v3);
    return 1;
}

//----- (004B5640) --------------------------------------------------------
int __cdecl sub_4B5640(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // eax
    int result; // eax
    char v6[332]; // [esp+Ch] [ebp-14Ch]

    v3 = *(_DWORD*)(a3 + 68);
    *(_DWORD*)v6 = 0;
    memset(&v6[4], 0, 0x148u);
    v4 = a2;
    *(_DWORD*)& v6[16] = a1;
    LOBYTE(v4) = a2 & 0xEF | 0xC;
    *(_DWORD*)& v6[8] = 1;
    *(_DWORD*)& v6[68] = v3;
    if ((v4 & 0x80u) == 0)
    {
        *(_DWORD*)& v6[52] = *(_DWORD*)(a3 + 52);
        *(_DWORD*)& v6[28] = *(_DWORD*)(a3 + 20);
        *(_DWORD*)& v6[20] = *(_DWORD*)(a3 + 28);
    }
    else
    {
        *(_DWORD*)& v6[32] = *(_DWORD*)(a3 + 32);
        *(_DWORD*)& v6[48] = *(_DWORD*)(a3 + 48);
        *(_DWORD*)& v6[56] = *(_DWORD*)(a3 + 56);
        *(_DWORD*)& v6[24] = *(_DWORD*)(a3 + 24);
        *(_DWORD*)& v6[40] = *(_DWORD*)(a3 + 40);
    }
    if (*(_BYTE*)(a3 + 8) & 0x10)
        result = sub_4A91A0(a1, v4, 0, 0, 10, *(_DWORD*)(a1 + 12), v6);
    else
        result = sub_4A91A0(a1, v4, 0, 0, *(_DWORD*)(a1 + 8), 10, v6);
    return result;
}

//----- (004B5700) --------------------------------------------------------
void __cdecl sub_4B5700(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v6; // eax
    int v7; // edx

    if (a1)
    {
        v6 = *(_DWORD*)(a1 + 400);
        v7 = *(_DWORD*)(v6 + 4);
        LOBYTE(v7) = v7 | 0x80;
        *(_DWORD*)(v6 + 4) = v7;
        sub_4A8340(*(_DWORD*)(a1 + 400));
        *(_DWORD*)(*(_DWORD*)(a1 + 400) + 60) = a2;
        *(_DWORD*)(*(_DWORD*)(a1 + 400) + 68) = a4;
        *(_DWORD*)(*(_DWORD*)(a1 + 400) + 84) = a3;
        *(_DWORD*)(*(_DWORD*)(a1 + 400) + 92) = a5;
        *(_DWORD*)(*(_DWORD*)(a1 + 400) + 76) = a6;
    }
}

//----- (004B5770) --------------------------------------------------------
int __cdecl sub_4B5770(int a1)
{
    int i; // esi
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    _DWORD* v4; // esi
    _DWORD* v5; // ebx
    _DWORD* v6; // ebp
    _DWORD* v7; // edi
    char* v8; // eax
    char* v10; // [esp+14h] [ebp+4h]

    *(_DWORD*)& byte_5D4594[1312488] = a1;
    *(_DWORD*)& byte_5D4594[1312480] = nox_new_window_from_file("locale.wnd", sub_4B5AB0);
    sub_46A9B0(
        *(_DWORD * *)& byte_5D4594[1312480],
        nox_win_width / 2 - 75,
        nox_win_height / 2 - 77);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1312480], 0);
    sub_46A8C0(*(int*)& byte_5D4594[1312480]);
    sub_46C690(*(int*)& byte_5D4594[1312480]);
    sub_46B500(*(int*)& byte_5D4594[1312480]);
    *(_DWORD*)& byte_5D4594[1312484] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1312480], 1981);
    sub_4B5990();
    for (i = 0; i < *(int*)& byte_5D4594[1312472]; ++i)
        nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16397, *(_DWORD*)(*(_DWORD*)& byte_5D4594[1312476] + 4 * i), -1);
    v2 = loadString_sub_40F1D0((char*)& byte_587000[174848], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 213);
    nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16397, (int)v2, -1);
    nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16403, 0, 0);
    v3 = loadString_sub_40F1D0((char*)& byte_587000[174900], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 216);
    nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16397, (int)v3, -1);
    nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16403, 0, 0);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1312480], 1982);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1312480], 1983);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1312480], 1984);
    v7 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[1312484] + 32);
    v10 = sub_42F970("UISlider");
    v8 = sub_42F970("UISliderLit");
    sub_4B5700((int)v4, 0, 0, (int)v10, (int)v8, (int)v8);
    sub_46B280((int)v4, *(int*)& byte_5D4594[1312484]);
    sub_46B280((int)v5, *(int*)& byte_5D4594[1312484]);
    sub_46B280((int)v6, *(int*)& byte_5D4594[1312484]);
    v7[9] = v4;
    v7[7] = v5;
    v7[8] = v6;
    *(_DWORD*)(v4[100] + 8) = 16;
    *(_DWORD*)(v4[100] + 12) = 10;
    return 1;
}

//----- (004B5990) --------------------------------------------------------
void* sub_4B5990()
{
    int v0; // esi
    int v1; // ecx
    unsigned __int8* v2; // eax
    int v3; // edx
    void* result; // eax
    __int16* v5; // ecx
    __int16 v6[16]; // [esp+8h] [ebp-20h]

    v0 = 0;
    v6[0] = 0;
    memset(&v6[1], 0, 0x1Cu);
    v6[15] = 0;
    v1 = 0;
    *(_DWORD*)& byte_5D4594[1312472] = 0;
    if (!*(_DWORD*)& byte_587000[174360])
        return *(void**)& byte_5D4594[1312476];
    v2 = &byte_587000[174360];
    do
    {
        v3 = *((_DWORD*)v2 + 2);
        v2 += 8;
        ++v1;
    } while (v3);
    *(_DWORD*)& byte_5D4594[1312472] = v1;
    if (v1 <= 0)
        return *(void**)& byte_5D4594[1312476];
    result = nox_malloc(4 * v1);
    *(_DWORD*)& byte_5D4594[1312476] = result;
    v5 = v6;
    if (*(_DWORD*)& byte_5D4594[1312472] > 0)
    {
        do
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1312476] + 4 * v0) = sub_4B5A30((wchar_t*)v5);
            result = *(void**)& byte_5D4594[1312476];
            v5 = *(__int16**)(*(_DWORD*)& byte_5D4594[1312476] + 4 * v0++);
        } while (v0 < *(int*)& byte_5D4594[1312472]);
    }
    return result;
}

//----- (004B5A30) --------------------------------------------------------
wchar_t* __cdecl sub_4B5A30(wchar_t* a1)
{
    int v1; // ebp
    __int16* v2; // edi
    char** v3; // ebx
    wchar_t* v4; // esi
    __int16 v6[16]; // [esp+8h] [ebp-20h]

    v1 = 0;
    memset(v6, 0xFFu, sizeof(v6));
    v2 = v6;
    if (*(int*)& byte_5D4594[1312472] <= 0)
        return (wchar_t*)v6;
    v3 = (char**)& byte_587000[174360];
    do
    {
        v4 = loadString_sub_40F1D0(*v3, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 101);
        if (nox_wcscmp(v4, (const wchar_t*)v2) < 0 && nox_wcscmp(v4, a1) > 0)
            v2 = (__int16*)v4;
        ++v1;
        v3 += 2;
    } while (v1 < *(int*)& byte_5D4594[1312472]);
    return (wchar_t*)v2;
}

//----- (004B5AB0) --------------------------------------------------------
int __cdecl sub_4B5AB0(int a1, int a2, int* a3, int a4)
{
    int* v4; // edi
    int v5; // eax
    wchar_t* v6; // eax
    int v7; // esi
    int v8; // eax
    int v9; // eax

    if (a2 != 16391)
        return 0;
    v4 = a3;
    if (sub_46B0A0(a3) != 1985)
        return 0;
    a2 = 0;
    v5 = nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16404, 0, 0);
    v6 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1312484], 16406, v5, 0);
    v7 = sub_4B5B70(v6);
    v8 = sub_41FC40();
    sub_40DB50(v8 + 1, (int)& a2);
    if (v7 != a2)
    {
        v9 = sub_41FC40();
        sub_40DB80(v9 + 1, v7);
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[1312488], 16391, (int)v4, a4);
    sub_4B5BF0();
    return 0;
}

//----- (004B5B70) --------------------------------------------------------
int __cdecl sub_4B5B70(wchar_t* a1)
{
    int v1; // edi
    char** v2; // esi
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    int result; // eax

    v1 = 0;
    if (*(int*)& byte_5D4594[1312472] <= 0)
    {
    LABEL_5:
        v4 = loadString_sub_40F1D0((char*)& byte_587000[175064], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 78);
        result = nox_wcscmp(a1, v4) != 0;
    }
    else
    {
        v2 = (char**)& byte_587000[174360];
        while (1)
        {
            v3 = loadString_sub_40F1D0(*v2, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 71);
            if (!nox_wcscmp(a1, v3))
                break;
            ++v1;
            v2 += 2;
            if (v1 >= *(int*)& byte_5D4594[1312472])
                goto LABEL_5;
        }
        result = *(_DWORD*)& byte_587000[8 * v1 + 174364];
    }
    return result;
}

//----- (004B5BF0) --------------------------------------------------------
void sub_4B5BF0()
{
    sub_46C6E0(*(int*)& byte_5D4594[1312480]);
    sub_46ADE0(*(int*)& byte_5D4594[1312480]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1312480]);
    *(_DWORD*)& byte_5D4594[1312480] = 0;
    *(_DWORD*)& byte_5D4594[1312488] = 0;
    *(_DWORD*)& byte_5D4594[1312484] = 0;
    free(*(LPVOID*)& byte_5D4594[1312476]);
    *(_DWORD*)& byte_5D4594[1312472] = 0;
}

//----- (004B5C40) --------------------------------------------------------
int __cdecl nox_parse_thing_client_update(int a1, int a2, char* a3)
{
    char* v3; // eax
    const char* v4; // ecx
    int v5; // ebp
    unsigned __int8* v6; // edi

    v3 = strtok(a3, " \t\n\r");
    v4 = *(const char**)& byte_587000[175072];
    v5 = 0;
    if (*(_DWORD*)& byte_587000[175072])
    {
        v6 = &byte_587000[175072];
        do
        {
            if (!strcmp(v4, v3))
                break;
            v4 = (const char*) * ((_DWORD*)v6 + 2);
            v6 += 8;
            ++v5;
        } while (v4);
    }
    if (!*(_DWORD*)& byte_587000[8 * v5 + 175072])
        return 0;
    *(_DWORD*)(a1 + 100) = *(_DWORD*)& byte_587000[8 * v5 + 175076];
    return 1;
}

//----- (004B5CD0) --------------------------------------------------------
int sub_4B5CD0()
{
    char v0; // si
    unsigned __int8* v1; // edi
    int v2; // edi
    unsigned __int8* v3; // esi
    int v4; // eax
    int v5; // edx
    int v6; // esi
    unsigned __int8* v7; // edi
    int v8; // esi
    unsigned __int8* v9; // edi
    int result; // eax
    int v12; // [esp+8h] [ebp-4h]

    v0 = 0;
    v1 = &byte_5D4594[1312500];
    do
    {
        LOBYTE(v12) = v0 / 63;
        *(_DWORD*)v1 = sub_4344A0((unsigned __int8)(v0 / 63) / 3, 3 * (unsigned __int8)(v0 / 63) / 5, v12);
        v1 += 4;
        --v0;
    } while ((int)v1 < (int)& byte_5D4594[1312756]);
    v2 = 0;
    v3 = &byte_5D4594[1312756];
    do
    {
        LOBYTE(v12) = v2 / 32;
        v4 = sub_4344A0(v12, v12, 0);
        LOBYTE(v5) = -1 - v12;
        *(_DWORD*)v3 = v4;
        *((_DWORD*)v3 + 32) = sub_4344A0(255, v5, 0);
        v3 += 4;
        v2 += 255;
    } while ((int)v3 < (int)& byte_5D4594[1312884]);
    v6 = 0;
    v7 = &byte_5D4594[1313012];
    do
    {
        LOBYTE(v12) = v6 / 63;
        *(_DWORD*)v7 = sub_4344A0(v12, v12, v12);
        v7 += 4;
        v6 += 255;
    } while ((int)v7 < (int)& byte_5D4594[1313268]);
    v8 = 0;
    v9 = &byte_5D4594[1313268];
    do
    {
        result = sub_4344A0(v8 / 63, 50, 50);
        *(_DWORD*)v9 = result;
        v9 += 4;
        v8 += 255;
    } while ((int)v9 < (int)& byte_5D4594[1313524]);
    return result;
}
// 4B5D21: variable 'v12' is possibly undefined
// 4B5D71: variable 'v5' is possibly undefined

//----- (004B5E10) --------------------------------------------------------
int __cdecl nox_thing_magic_tail_link_draw(_DWORD* a1, int a2)
{
    int v2; // ecx
    int v3; // edi
    int v4; // esi
    int v5; // eax
    bool v6; // zf
    int v7; // eax
    unsigned int v8; // ett
    int v9; // ebp
    int v10; // ebx
    float v12; // [esp+0h] [ebp-24h]
    int v13; // [esp+14h] [ebp-10h]
    int v14; // [esp+18h] [ebp-Ch]
    int v15; // [esp+2Ch] [ebp+8h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
    v4 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v13 = *a1 - a1[4] + *(_DWORD*)(a2 + 432);
    v5 = *(_DWORD*)(a2 + 356) - *(_DWORD*)& byte_5D4594[2598000];
    v6 = *(_DWORD*)(a2 + 356) == *(_DWORD*)& byte_5D4594[2598000];
    v14 = a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5] + *(_DWORD*)(a2 + 436);
    v15 = v5;
    if (v5 >= 0 && !v6)
    {
        v8 = v5 << 6;
        v7 = (unsigned int)(v5 << 6) / *(_DWORD*)& byte_5D4594[2649704];
        if ((int)(v8 / *(_DWORD*)& byte_5D4594[2649704]) >= 64)
            v7 = 63;
        v9 = *(_DWORD*)& byte_5D4594[4 * v7 + 1312500];
        v10 = v2 + 136;
        sub_484BE0((_DWORD*)(v2 + 136), 128, 128, 255);
        v12 = (double)v15 * 20.0 / (double) * (int*)& byte_5D4594[2649704];
        sub_484D70(v10, v12);
        sub_434460(v9);
        sub_434560(1);
        sub_434580(0x80u);
        sub_49F500(v3, v4);
        sub_49F500(v13, v14);
        sub_49E4B0();
        sub_434560(0);
    }
    return 1;
}

//----- (004B5F30) --------------------------------------------------------
int __cdecl nox_thing_magic_missle_tail_link_draw(_DWORD* a1, int a2)
{
    int v2; // ecx
    int v3; // edi
    int v4; // esi
    int v5; // ebx
    int v6; // eax
    int v7; // ebp
    int v8; // ebx
    float v10; // [esp+0h] [ebp-1Ch]
    int v11; // [esp+14h] [ebp-8h]
    int v12; // [esp+18h] [ebp-4h]
    signed int v13; // [esp+20h] [ebp+4h]
    int v14; // [esp+24h] [ebp+8h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
    v4 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v12 = a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5] + *(_DWORD*)(a2 + 436);
    v5 = *(_DWORD*)(a2 + 356) - *(_DWORD*)& byte_5D4594[2598000];
    v11 = *a1 - a1[4] + *(_DWORD*)(a2 + 432);
    v14 = v5;
    if (v5 > 0)
    {
        v6 = (v5 << 6) / (int)(*(_DWORD*)& byte_5D4594[2649704] / 3u);
        v13 = *(_DWORD*)& byte_5D4594[2649704] / 3u;
        if (v6 >= 64)
            v6 = 63;
        v7 = *(_DWORD*)& byte_5D4594[4 * v6 + 1312756];
        v8 = v2 + 136;
        sub_484BE0((_DWORD*)(v2 + 136), 255, 128, 50);
        v10 = (double)v14 * 20.0 / (double)v13;
        sub_484D70(v8, v10);
        sub_434460(v7);
        sub_434560(1);
        sub_434580(0x80u);
        sub_49F500(v3, v4);
        sub_49F500(v11, v12);
        sub_49E4B0();
        sub_434560(0);
    }
    return 1;
}

//----- (004B6050) --------------------------------------------------------
int __cdecl nox_thing_arrow_tail_link_draw(_DWORD* a1, int a2)
{
    int v2; // ebp
    int v3; // edi
    int v4; // esi
    int v5; // ebx
    int v6; // ebp
    int v7; // eax

    v2 = *(_DWORD*)(a2 + 16);
    v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
    v4 = v2 + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v5 = *(_DWORD*)(a2 + 436) - v2;
    v6 = *(_DWORD*)(a2 + 432) + *a1 - a1[4];
    if (*(_DWORD*)(a2 + 356) - *(_DWORD*)& byte_5D4594[2598000] > 0)
    {
        v7 = ((*(_DWORD*)(a2 + 356) - *(_DWORD*)& byte_5D4594[2598000]) << 6)
            / (int)(*(_DWORD*)& byte_5D4594[2649704] / 3u);
        if (v7 >= 64)
            v7 = 63;
        sub_434460(*(_DWORD*)& byte_5D4594[4 * v7 + 1313012]);
        sub_434560(1);
        sub_434580(0x80u);
        sub_49F500(v3, v4 - 4);
        sub_49F500(v6, v5 + v4 - 4);
        sub_49E4B0();
        sub_434560(0);
    }
    return 1;
}

//----- (004B6120) --------------------------------------------------------
int __cdecl nox_thing_weak_arrow_tail_link_draw(_DWORD* a1, int a2)
{
    int v2; // ebp
    int v3; // edi
    int v4; // esi
    int v5; // ebx
    int v6; // ebp
    int v7; // eax

    v2 = *(_DWORD*)(a2 + 16);
    v3 = *(_DWORD*)(a2 + 12) + *a1 - a1[4];
    v4 = v2 + a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v5 = *(_DWORD*)(a2 + 436) - v2;
    v6 = *(_DWORD*)(a2 + 432) + *a1 - a1[4];
    if (*(_DWORD*)(a2 + 356) - *(_DWORD*)& byte_5D4594[2598000] > 0)
    {
        v7 = ((*(_DWORD*)(a2 + 356) - *(_DWORD*)& byte_5D4594[2598000]) << 6)
            / (int)(*(_DWORD*)& byte_5D4594[2649704] / 3u);
        if (v7 >= 64)
            v7 = 63;
        sub_434460(*(_DWORD*)& byte_5D4594[4 * v7 + 1313268]);
        sub_434560(1);
        sub_434580(0x80u);
        sub_49F500(v3, v4 - 4);
        sub_49F500(v6, v5 + v4 - 4);
        sub_49E4B0();
        sub_434560(0);
    }
    return 1;
}

//----- (004B61F0) --------------------------------------------------------
int __cdecl nox_thing_harpoon_rope_draw(int* a1, int a2)
{
    int v2; // ecx
    int v3; // edx
    unsigned __int16 v4; // bx
    int v5; // edi
    int v6; // eax
    int v7; // ebx
    int v8; // ecx
    _DWORD* v9; // eax
    _DWORD* v10; // edi
    _DWORD* v11; // eax
    int v12; // ebx
    int v13; // ebp
    int v14; // ecx
    int2 a1a; // [esp+Ch] [ebp-10h]
    int2 a2a; // [esp+14h] [ebp-8h]
    int v18; // [esp+20h] [ebp+4h]

    if (!*(_BYTE*)(a2 + 432))
    {
        v2 = a1[4];
        v3 = *a1;
        v4 = *(_WORD*)(a2 + 439);
        a1a.field_0 = *a1 + *(unsigned __int16*)(a2 + 437) - v2;
        v5 = a1[5];
        v6 = a1[1];
        a1a.field_4 = v4 - v5 + v6 - 20;
        v7 = *(unsigned __int16*)(a2 + 441) - v2;
        v8 = *(unsigned __int16*)(a2 + 443) - v5;
        a2a.field_0 = v3 + v7;
        a2a.field_4 = v8 + v6 - 20;
    LABEL_12:
        *(_DWORD*)& byte_5D4594[1312492] = sub_4344A0(144, 104, 64);
        *(_DWORD*)& byte_5D4594[1312496] = sub_4344A0(24, 16, 0);
        sub_4B63B0(&a1a, &a2a);
        return 1;
    }
    if (sub_578B70(*(_DWORD*)(a2 + 437)))
        v9 = sub_45A720(*(_DWORD*)(a2 + 437));
    else
        v9 = sub_45A6F0(*(_DWORD*)(a2 + 437));
    v10 = v9;
    if (sub_578B70(*(_DWORD*)(a2 + 441)))
        v11 = sub_45A720(*(_DWORD*)(a2 + 441));
    else
        v11 = sub_45A6F0(*(_DWORD*)(a2 + 441));
    if (v10 && v11)
    {
        v12 = a1[4];
        v13 = *a1;
        v14 = a1[1];
        v18 = a1[5];
        a1a.field_0 = v13 + v10[3] - v12;
        a1a.field_4 = v14 + v10[4] - v18;
        a2a.field_0 = v13 + v11[3] - v12;
        a2a.field_4 = v14 + v11[4] - *((__int16*)v11 + 53) - *((__int16*)v11 + 52) - v18;
        a1a.field_0 += *(_DWORD*)& byte_587000[8 * *((unsigned __int8*)v10 + 297) + 175864];
        a1a.field_4 += *(_DWORD*)& byte_587000[8 * *((unsigned __int8*)v10 + 297) + 175868];
        a2a.field_4 -= 8;
        goto LABEL_12;
    }
    return 1;
}

//----- (004B63B0) --------------------------------------------------------
int __cdecl sub_4B63B0(int2* a1, int2* a2)
{
    int v2; // ebx
    int v3; // ebp

    sub_434460(*(int*)& byte_5D4594[1312492]);
    sub_49F500(a1->field_0, a1->field_4);
    sub_49F500(a2->field_0, a2->field_4);
    sub_49E4B0();
    v2 = a2->field_0 - a1->field_0;
    v3 = a2->field_4 - a1->field_4;
    sub_434460(*(int*)& byte_5D4594[1312496]);
    if (v2 < 0)
        v2 = -v2;
    if (v3 < 0)
        v3 = -v3;
    if (v2 <= v3)
    {
        sub_49F500(a1->field_0 - 1, a1->field_4);
        sub_49F500(a2->field_0 - 1, a2->field_4);
        sub_49E4B0();
        sub_49F500(a1->field_0 + 1, a1->field_4);
        sub_49F500(a2->field_0 + 1, a2->field_4);
    }
    else
    {
        sub_49F500(a1->field_0, a1->field_4 - 1);
        sub_49F500(a2->field_0, a2->field_4 - 1);
        sub_49E4B0();
        sub_49F500(a1->field_0, a1->field_4 + 1);
        sub_49F500(a2->field_0, a2->field_4 + 1);
    }
    return sub_49E4B0();
}

//----- (004B64A0) --------------------------------------------------------
int __cdecl nox_thing_harpoon_draw(int* a1, int a2)
{
    return nox_thing_slave_draw(a1, a2);
}

//----- (004B64C0) --------------------------------------------------------
int sub_4B64C0()
{
    unsigned __int8 v0; // bl
    unsigned __int8* v1; // esi
    int v2; // ebp
    int v3; // edi
    int v5; // [esp+10h] [ebp-10h]
    int v6; // [esp+14h] [ebp-Ch]
    int v7; // [esp+18h] [ebp-8h]
    int v8; // [esp+1Ch] [ebp-4h]

    *(_DWORD*)& byte_5D4594[1313524] = sub_4344A0(255, 255, 0);
    *(_DWORD*)& byte_5D4594[1313528] = sub_4344A0(255, 100, 0);
    *(_DWORD*)& byte_5D4594[1313532] = sub_4344A0(255, 255, 0);
    *(_DWORD*)& byte_5D4594[1313536] = sub_4344A0(0, 0, 255);
    *(_DWORD*)& byte_5D4594[1313540] = sub_4344A0(0, 200, 255);
    *(_DWORD*)& byte_5D4594[1313544] = sub_4344A0(0, 200, 200);
    *(_DWORD*)& byte_5D4594[1313548] = sub_4344A0(50, 255, 255);
    *(_DWORD*)& byte_5D4594[1313552] = sub_4344A0(255, 0, 255);
    *(_DWORD*)& byte_5D4594[1313556] = sub_4344A0(255, 200, 255);
    *(_DWORD*)& byte_5D4594[1313560] = sub_4344A0(255, 200, 0);
    *(_DWORD*)& byte_5D4594[1313564] = sub_4344A0(255, 255, 100);
    *(_DWORD*)& byte_5D4594[1313568] = sub_4344A0(100, 255, 50);
    *(_DWORD*)& byte_5D4594[1313572] = sub_4344A0(150, 255, 150);
    *(_DWORD*)& byte_5D4594[1313576] = sub_4344A0(255, 255, 0);
    *(_DWORD*)& byte_5D4594[1313580] = sub_4344A0(0, 220, 0);
    *(_DWORD*)& byte_5D4594[1313584] = sub_4344A0(150, 255, 150);
    *(_DWORD*)& byte_5D4594[1313588] = sub_4344A0(200, 200, 200);
    *(_DWORD*)& byte_5D4594[1313592] = sub_4344A0(255, 255, 255);
    LOBYTE(v8) = -1;
    LOBYTE(v7) = -1;
    LOBYTE(v6) = -1;
    v0 = 0;
    v1 = &byte_5D4594[1313656];
    v2 = 1085;
    v5 = 600;
    v3 = 765;
    do
    {
        if (v0 > 3u)
        {
            if (v0 > 7u)
                LOBYTE(v8) = v2 / 9 - 1;
            else
                LOBYTE(v7) = v5 / 4 - 1;
        }
        else
        {
            LOBYTE(v6) = v3 / 3;
        }
        *(_DWORD*)v1 = sub_4344A0(v8, v7, v6);
        ++v0;
        v3 -= 255;
        v2 -= 155;
        v1 -= 4;
        v5 -= 200;
    } while (v0 < 0x10u);
    return sub_4B5CD0();
}
// 4B66DF: variable 'v8' is possibly undefined
// 4B66DF: variable 'v7' is possibly undefined
// 4B66DF: variable 'v6' is possibly undefined

//----- (004B6720) --------------------------------------------------------
void __cdecl sub_4B6720(int2* a1, int a2, int a3, char a4)
{
    int* v4; // eax

    if (*(_DWORD*)& byte_5D4594[805852])
    {
        sub_434040(a2);
        sub_434080(a3 + 4);
        v4 = sub_4B0680(0, 32 * a4);
        sub_4B0820((int)v4, a1->field_0, a1->field_4);
    }
}

//----- (004B6770) --------------------------------------------------------
int __cdecl sub_4B6770(int* a1, int a2, int a3, int a4)
{
    int v4; // edx
    int v5; // ebx
    int v6; // ecx
    int v7; // eax
    int result; // eax
    int v9; // edi
    int v10; // ebx
    int v11; // ecx
    int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // esi
    int v16; // [esp+Ch] [ebp-Ch]
    int2 xLeft; // [esp+10h] [ebp-8h]
    int v18; // [esp+20h] [ebp+8h]

    v4 = a2;
    v5 = *(_DWORD*)(a2 + 444);
    v6 = *(_DWORD*)(a2 + 448) - v5;
    v7 = *(_DWORD*)(a2 + 448) - *(_DWORD*)& byte_5D4594[2598000];
    v16 = *(_DWORD*)(a2 + 448) - v5;
    v18 = v7;
    if (v7 == v6)
        v18 = --v7;
    if (v7 > 0)
    {
        v9 = *a1;
        v10 = a1[1];
        v11 = *a1 + *(_DWORD*)(v4 + 12) - a1[4];
        v12 = *(_DWORD*)(v4 + 16) - *(__int16*)(v4 + 106) - *(__int16*)(v4 + 104) - a1[5];
        xLeft.field_0 = v11;
        v13 = v10 + v12;
        xLeft.field_4 = v13;
        if (v11 - 10 >= v9 && v13 - 10 >= v10 && v11 + 10 < a1[2] && v13 + 10 < a1[3])
        {
            v14 = v18 * sub_415FF0(0, 4, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 213) / v16;
            v15 = v14;
            if (v14)
            {
                sub_4B6720(&xLeft, a4, 2 * v14 + 1, v14 + 1);
                sub_434460(a3);
                sub_499B70(xLeft.field_0, xLeft.field_4, v15);
            }
        }
        result = 1;
    }
    else
    {
        sub_45A4E0(v4);
        result = 0;
    }
    return result;
}

//----- (004B6880) --------------------------------------------------------
int __cdecl sub_4B6880(_DWORD* a1, int a2, int a3, int a4)
{
    int v4; // edx
    int v5; // ebx
    int v6; // eax
    int result; // eax
    int v8; // ecx
    int v9; // eax
    int v10; // edx
    int v11; // eax
    bool v12; // cc
    int v13; // esi
    int2 xLeft; // [esp+Ch] [ebp-8h]
    int v15; // [esp+1Ch] [ebp+8h]

    v4 = a2;
    v5 = *(_DWORD*)(a2 + 448) - *(_DWORD*)(a2 + 444);
    v15 = *(_DWORD*)(a2 + 448) - *(_DWORD*)& byte_5D4594[2598000];
    v6 = v15;
    if (v15 == v5)
        v6 = --v15;
    if (v6 > 0)
    {
        v8 = *a1 + *(_DWORD*)(v4 + 12) - a1[4];
        v9 = *(_DWORD*)(v4 + 16) - *(__int16*)(v4 + 106) - *(__int16*)(v4 + 104) - a1[5];
        v10 = a1[1];
        v11 = v10 + v9;
        v12 = v8 - 10 < *a1;
        xLeft.field_0 = v8;
        xLeft.field_4 = v11;
        if (!v12 && v11 - 10 >= v10 && v8 + 10 < a1[2] && v11 + 10 < a1[3])
        {
            v13 = 4 * v15 / v5;
            sub_4B6720(&xLeft, a4, 2 * v13 + 1, 5 * v15 / v5);
            sub_434460(a3);
            sub_499B70(xLeft.field_0, xLeft.field_4, v13);
        }
        result = 1;
    }
    else
    {
        sub_45A4E0(v4);
        result = 0;
    }
    return result;
}

//----- (004B6970) --------------------------------------------------------
int __cdecl sub_4B6970(_DWORD* a1, int a2, int a3, int a4)
{
    int v4; // eax
    int v5; // eax

    v4 = *(_DWORD*)(a2 + 440);
    *(_DWORD*)(a2 + 432) += v4 * *(int*)& byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192088];
    v5 = v4 * *(int*)& byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192092] + *(_DWORD*)(a2 + 436);
    *(_DWORD*)(a2 + 436) = v5;
    sub_49AA90((_DWORD*)a2, *(_DWORD*)(a2 + 432) >> 12, v5 >> 12);
    sub_4B69F0(a2);
    return sub_4B6880(a1, a2, a3, a4);
}

//----- (004B69F0) --------------------------------------------------------
__int16 __cdecl sub_4B69F0(int a1)
{
    char v1; // cl
    __int16 result; // ax
    int v3; // edx

    v1 = *(_BYTE*)(a1 + 296);
    *(_WORD*)(a1 + 104) += v1;
    result = *(_WORD*)(a1 + 104);
    if (result >= 0)
    {
        if (byte_5D4594[2598000] & 1)
            * (_BYTE*)(a1 + 296) = v1 - 1;
    }
    else
    {
        *(_WORD*)(a1 + 104) = -result;
        result = 26209 * v1;
        v3 = -9 * v1 / 10;
        *(_BYTE*)(a1 + 296) = v3;
        if ((char)v3 < 2)
        {
            *(_WORD*)(a1 + 104) = 0;
            *(_BYTE*)(a1 + 296) = 0;
        }
    }
    return result;
}

//----- (004B6A60) --------------------------------------------------------
int __cdecl nox_thing_red_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313532], *(int*)& byte_5D4594[1313528]);
}

//----- (004B6A80) --------------------------------------------------------
int __cdecl nox_thing_blue_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313540], *(int*)& byte_5D4594[1313536]);
}

//----- (004B6AA0) --------------------------------------------------------
int __cdecl nox_thing_cyan_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313548], *(int*)& byte_5D4594[1313544]);
}

//----- (004B6AC0) --------------------------------------------------------
int __cdecl nox_thing_green_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313584], *(int*)& byte_5D4594[1313580]);
}

//----- (004B6AE0) --------------------------------------------------------
int __cdecl nox_thing_yellow_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313532], *(int*)& byte_5D4594[1313576]);
}

//----- (004B6B00) --------------------------------------------------------
int __cdecl nox_thing_magic_sparkle_draw(int* a1, int a2)
{
    int result; // eax

    if (sub_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 317) >= 5)
        result = sub_4B6770(a1, a2, *(int*)& byte_5D4594[2523948], *(int*)& byte_5D4594[1313540]);
    else
        result = sub_4B6770(a1, a2, *(int*)& byte_5D4594[1313540], *(int*)& byte_5D4594[1313536]);
    return result;
}

//----- (004B6B60) --------------------------------------------------------
int __cdecl nox_thing_glow_orb_draw(int* a1, int a2)
{
    return sub_4B6B80(a1, a2, 0);
}

//----- (004B6B80) --------------------------------------------------------
int __cdecl sub_4B6B80(int* a1, int a2, int a3)
{
    int v3; // esi
    int v4; // eax
    int v5; // ecx
    int v6; // edi
    int v7; // ebx
    int v8; // eax
    int v10; // edi
    int v11; // ebp
    int v12; // edx
    int v13; // edx
    int v14; // edi
    int v15; // ebx
    char v16; // al
    char v17; // cl
    char v18; // al
    int v19; // [esp+10h] [ebp-Ch]
    int2 xLeft; // [esp+14h] [ebp-8h]
    int v21; // [esp+24h] [ebp+8h]

    v3 = a2;
    if (!*(_DWORD*)& byte_5D4594[1313660])
    {
        *(_DWORD*)& byte_5D4594[1313660] = sub_44CFC0((CHAR*)& byte_587000[176016]);
        *(_DWORD*)& byte_5D4594[1313664] = sub_44CFC0((CHAR*)& byte_587000[176032]);
        *(_DWORD*)& byte_5D4594[1313668] = sub_44CFC0((CHAR*)& byte_587000[176040]);
        *(_DWORD*)& byte_5D4594[1313672] = sub_44CFC0((CHAR*)& byte_587000[176052]);
        *(_DWORD*)& byte_5D4594[1313676] = sub_44CFC0((CHAR*)& byte_587000[176064]);
        *(_DWORD*)& byte_5D4594[1313680] = sub_44CFC0((CHAR*)& byte_587000[176076]);
        *(_DWORD*)& byte_5D4594[1313684] = sub_44CFC0((CHAR*)& byte_587000[176092]);
    }
    v4 = *(_DWORD*)(a2 + 108);
    if (v4 == *(_DWORD*)& byte_5D4594[1313660] || v4 == *(_DWORD*)& byte_5D4594[1313684])
    {
        v5 = *(_DWORD*)& byte_5D4594[1313540];
        v21 = *(_DWORD*)& byte_5D4594[1313536];
        goto LABEL_13;
    }
    if (v4 == *(_DWORD*)& byte_5D4594[1313668])
    {
        v5 = *(_DWORD*)& byte_5D4594[1313584];
        v21 = *(_DWORD*)& byte_5D4594[1313580];
    LABEL_13:
        v19 = v5;
        goto LABEL_14;
    }
    if (v4 == *(_DWORD*)& byte_5D4594[1313672]
        || v4 == *(_DWORD*)& byte_5D4594[1313676]
        || v4 == *(_DWORD*)& byte_5D4594[1313680])
    {
        v21 = *(_DWORD*)& byte_5D4594[1313588];
        v19 = *(_DWORD*)& byte_5D4594[1313592];
    }
    else
    {
        v21 = *(_DWORD*)& byte_5D4594[1313528];
        v19 = *(_DWORD*)& byte_5D4594[1313532];
    }
LABEL_14:
    if (a3)
    {
        v6 = *(unsigned __int16*)(v3 + 432) - *(_DWORD*)(v3 + 12);
        v7 = *(unsigned __int16*)(v3 + 434) - *(_DWORD*)(v3 + 16);
        v8 = sub_48C6B0(v6, v7);
        if (v8 + 1 <= 10)
        {
            sub_45A4E0(v3);
            return 0;
        }
        sub_49AA90(
            (_DWORD*)v3,
            *(_DWORD*)(v3 + 12) + v6 * *(unsigned __int8*)(v3 + 443) / (v8 + 1),
            *(_DWORD*)(v3 + 16) + v7 * *(unsigned __int8*)(v3 + 443) / (v8 + 1));
    }
    v10 = *a1;
    v11 = a1[1];
    v12 = *(_DWORD*)(v3 + 16) - a1[5];
    xLeft.field_0 = *(_DWORD*)(v3 + 12) + *a1 - a1[4];
    xLeft.field_4 = v12 + v11 - 22;
    v13 = *(unsigned __int8*)(v3 + 444);
    if (xLeft.field_0 - v13 < v10)
        return 1;
    if (xLeft.field_4 - v13 < v11)
        return 1;
    if (v13 + xLeft.field_0 >= a1[2])
        return 1;
    if (v13 + xLeft.field_4 >= a1[3])
        return 1;
    sub_4B6720(&xLeft, v21, v13, 5);
    sub_434460(v19);
    sub_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(v3 + 444) >> 1);
    v14 = *(_DWORD*)(v3 + 32) - *(_DWORD*)(v3 + 12);
    v15 = *(_DWORD*)(v3 + 36) - *(_DWORD*)(v3 + 16);
    sub_434460(v19);
    sub_49F500(xLeft.field_0, xLeft.field_4);
    sub_49F570(v14, v15);
    sub_49E4B0();
    v16 = *(_BYTE*)(v3 + 445);
    if (!v16)
        return 1;
    v17 = *(_BYTE*)(v3 + 446) - 1;
    *(_BYTE*)(v3 + 446) = v17;
    if (v17)
        return 1;
    *(_BYTE*)(v3 + 446) = v16;
    v18 = *(_BYTE*)(v3 + 444) - 1;
    *(_BYTE*)(v3 + 444) = v18;
    if (v18)
        return 1;
    sub_45A4E0(v3);
    return 0;
}
// 4B6CB4: variable 'v8' is possibly undefined

//----- (004B6E20) --------------------------------------------------------
int __cdecl nox_thing_glow_orb_move_draw(int* a1, int a2)
{
    return sub_4B6B80(a1, a2, 1);
}

//----- (004B6E40) --------------------------------------------------------
int __cdecl nox_thing_violet_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313556], *(int*)& byte_5D4594[1313552]);
}

//----- (004B6E60) --------------------------------------------------------
int __cdecl nox_thing_death_ball_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[1313572], *(int*)& byte_5D4594[1313568]);
}

//----- (004B6E80) --------------------------------------------------------
int __cdecl nox_thing_pixie_draw(int* a1, int a2)
{
    bool v2; // cc
    __int16 v3; // ax
    __int16 v4; // ax
    int v5; // edx
    int v6; // edi
    int v7; // ecx
    int v8; // eax
    int v9; // edi
    int v10; // esi
    int v11; // ebx
    int v12; // ebp
    __int64 v13; // rax
    int2 v15; // [esp+10h] [ebp-8h]

    v2 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 503) < 50;
    v3 = *(_WORD*)(a2 + 104);
    if (v2)
    {
        if (v3 > 0)
        {
            v4 = v3 - 1;
        LABEL_6:
            *(_WORD*)(a2 + 104) = v4;
            goto LABEL_7;
        }
    }
    else if (v3 < 35)
    {
        v4 = v3 + 1;
        goto LABEL_6;
    }
LABEL_7:
    v5 = *a1;
    v6 = a1[1];
    v7 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v8 = v6 + *(_DWORD*)(a2 + 16) - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v15.field_0 = v7;
    v15.field_4 = v8;
    if (v7 - 10 >= v5 && v8 - 10 >= v6 && v7 + 10 < a1[2] && v8 + 10 < a1[3])
    {
        sub_4B6720(&v15, *(int*)& byte_5D4594[1313560], 10, 4);
        v9 = *a1 + *(_DWORD*)(a2 + 32) - a1[4];
        v10 = a1[1] + *(_DWORD*)(a2 + 36) - *(__int16*)(a2 + 104) - a1[5];
        v11 = v15.field_0 - v9;
        v12 = v15.field_4 - v10;
        if (v11 * v11 + v12 * v12 > 400)
        {
            v13 = (__int64)sqrt((double)(v11 * v11 + v12 * v12));
            v9 = v15.field_0 - 20 * v11 / (int)v13;
            v10 = v15.field_4 - 20 * v12 / (int)v13;
        }
        sub_434460(*(int*)& byte_5D4594[1313564]);
        sub_49F500(v15.field_0, v15.field_4);
        sub_49F500(v9, v10);
        sub_49E4B0();
    }
    return 1;
}

//----- (004B6FE0) --------------------------------------------------------
int __cdecl nox_thing_pixie_dust_draw(int* a1, int a2)
{
    int result; // eax

    if (sub_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 554) >= 5)
        result = sub_4B6770(a1, a2, *(int*)& byte_5D4594[2523948], *(int*)& byte_5D4594[1313564]);
    else
        result = sub_4B6770(a1, a2, *(int*)& byte_5D4594[1313564], *(int*)& byte_5D4594[1313560]);
    return result;
}

//----- (004B7040) --------------------------------------------------------
int __cdecl nox_thing_white_spark_draw(_DWORD* a1, int a2)
{
    return sub_4B6970(a1, a2, *(int*)& byte_5D4594[2523948], *(int*)& byte_5D4594[1313540]);
}

//----- (004B7060) --------------------------------------------------------
int __cdecl nox_thing_blue_rain_spark_draw(_DWORD* a1, int a2)
{
    int result; // eax
    int v3; // eax
    int v4; // eax
    int v5; // edi

    result = sub_4B6970(a1, a2, *(int*)& byte_5D4594[2523948], *(int*)& byte_5D4594[1313540]);
    if (result == 1 && *(_BYTE*)(a2 + 296) >= 5)
    {
        v3 = *(_DWORD*)& byte_5D4594[1313688];
        if (!*(_DWORD*)& byte_5D4594[1313688])
        {
            v3 = sub_44CFC0((CHAR*)& byte_587000[176184]);
            *(_DWORD*)& byte_5D4594[1313688] = v3;
        }
        v4 = sub_45A360(v3, *(_DWORD*)(a2 + 12), *(_DWORD*)(a2 + 16));
        v5 = v4;
        if (v4)
        {
            if (v4 != -432)
            {
                *(_DWORD*)(v4 + 432) = *(_DWORD*)(a2 + 12) << 12;
                *(_DWORD*)(v4 + 436) = *(_DWORD*)(a2 + 16) << 12;
                *(_BYTE*)(v4 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 605);
                *(_DWORD*)(v5 + 440) = sub_415FF0(1, 1611, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 608);
                *(_DWORD*)(v5 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                    + sub_415FF0(10, 96, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 611);
                *(_DWORD*)(v5 + 444) = *(_DWORD*)& byte_5D4594[2598000];
            }
            *(_WORD*)(v5 + 104) = sub_415FF0(5, 15, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 618);
            *(_WORD*)(v5 + 106) = 0;
            *(_BYTE*)(v5 + 296) = sub_415FF0(0, 8, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 620);
            sub_45A110((_DWORD*)v5);
        }
        sub_45A4E0(a2);
        result = 0;
    }
    return result;
}

//----- (004B71A0) --------------------------------------------------------
int __cdecl sub_4B71A0(_DWORD* a1, int a2)
{
    int v2; // edx
    int v3; // ecx
    int v4; // ebx
    int v5; // ebx
    int v6; // edi
    int result; // eax
    int v8; // eax
    int v9; // esi
    int v10; // ebp
    int2 v11; // [esp+10h] [ebp-8h]
    int v12; // [esp+20h] [ebp+8h]

    v2 = *(_DWORD*)(a2 + 16);
    v3 = *(__int16*)(a2 + 106);
    v11.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v11.field_4 = a1[1] + v2 - v3 - *(__int16*)(a2 + 104) - a1[5];
    *(_DWORD*)(a2 + 432) += *(_DWORD*)(a2 + 440) * *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192088];
    v4 = *(_DWORD*)(a2 + 440) * *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192092]
        + *(_DWORD*)(a2 + 436);
    *(_DWORD*)(a2 + 436) = v4;
    sub_49AA90((_DWORD*)a2, *(_DWORD*)(a2 + 432) >> 12, v4 >> 12);
    v5 = *(_DWORD*)(a2 + 444) - *(_DWORD*)(a2 + 448);
    v6 = *(_DWORD*)(a2 + 444) - *(_DWORD*)& byte_5D4594[2598000];
    if (v6 == v5)
        --v6;
    if (v6 > 0)
    {
        if (v11.field_0 - 10 >= *a1 && v11.field_4 - 10 >= a1[1] && v11.field_0 + 10 < a1[2] && v11.field_4 + 10 < a1[3])
        {
            sub_4B69F0(a2);
            v8 = 4 * (16 * v6 / v5);
            v12 = *(_DWORD*)& byte_5D4594[v8 + 1313596];
            v9 = v8 / 16;
            v10 = (v8 / 16) >> 1;
            sub_4B6720(&v11, *(_DWORD*)& byte_5D4594[v8 + 1313596], 2 * (v8 / 16) + 1, 5 * v6 / v5);
            sub_434460(v12);
            sub_49CE30(v11.field_0 - v10, v11.field_4 - v10, v9, v9);
        }
        result = 1;
    }
    else
    {
        sub_45A4E0(a2);
        result = 0;
    }
    return result;
}

//----- (004B7310) --------------------------------------------------------
int __cdecl nox_thing_rain_orb_draw(_DWORD* a1, int a2)
{
    int* v2; // esi
    __int16 v3; // cx
    int v4; // edi
    int v5; // eax
    __int16 v6; // bp
    int v7; // ebx
    __int16 v8; // ax
    double v9; // st7
    __int16 v10; // ax
    int v11; // edi
    char v12; // al
    int result; // eax
    int v14; // ebx
    int v15; // edi
    int v16; // edx
    int v17; // ebx
    int v18; // eax
    int v19; // edi
    float v20; // [esp+0h] [ebp-2Ch]
    float v21; // [esp+0h] [ebp-2Ch]
    int2 xLeft; // [esp+14h] [ebp-18h]
    __int16 v23[4]; // [esp+1Ch] [ebp-10h]
    float2 v24; // [esp+24h] [ebp-8h]
    int v25; // [esp+34h] [ebp+8h]

    v2 = (_DWORD*)a2;
    if (!*(_DWORD*)& byte_5D4594[1313692])
    {
        *(_DWORD*)& byte_5D4594[1313692] = sub_44CFC0((CHAR*)& byte_587000[176396]);
        *(_DWORD*)& byte_5D4594[1313696] = sub_44CFC0((CHAR*)& byte_587000[176412]);
    }
    v3 = *(_WORD*)(a2 + 104);
    if (v3 > 0)
    {
        v14 = a1[5];
        v15 = *(_DWORD*)(a2 + 16);
        xLeft.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
        v16 = a1[1] - v14;
        v17 = *(_DWORD*)& byte_5D4594[1313588];
        v18 = *(_DWORD*)(a2 + 108);
        xLeft.field_4 = v15 + v16 - v3;
        if (v18 != *(_DWORD*)& byte_5D4594[1313692])
            v17 = *(_DWORD*)& byte_5D4594[1313536];
        sub_4B6720(&xLeft, v17, *(unsigned __int8*)(a2 + 442), 5);
        v19 = *(__int16*)(a2 + 104) - *(__int16*)(a2 + 440);
        sub_434460(v17);
        sub_49F500(xLeft.field_0, xLeft.field_4);
        sub_49F570(0, v19);
        sub_49E4B0();
        *(_WORD*)(a2 + 440) = *(_WORD*)(a2 + 104);
        *(_WORD*)(a2 + 104) += *(char*)(a2 + 296);
        sub_434460(*(int*)& byte_5D4594[1313592]);
        sub_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(a2 + 442) / 3);
        result = 1;
    }
    else
    {
        if (!*(_DWORD*)& byte_5D4594[1313700])
        {
            *(_DWORD*)& byte_5D4594[1313700] = sub_44CFC0((CHAR*)& byte_587000[176424]);
            *(_DWORD*)& byte_5D4594[1313704] = sub_44CFC0((CHAR*)& byte_587000[176440]);
        }
        v4 = *(_DWORD*)(a2 + 12);
        v5 = *(_DWORD*)(a2 + 16);
        v6 = v5 + 20;
        v25 = v5 - *(_DWORD*)(a2 + 436);
        v24.field_0 = (double)(v2[3] - v2[108]);
        v24.field_4 = (double)v25;
        v7 = sub_509ED0(&v24);
        v23[2] = v4;
        v23[3] = v6;
        v20 = *(float*)& byte_587000[8 * v7 + 194136] * 150.0 + (double)(int)v2[108];
        v8 = sub_419A70(v20);
        v9 = *(float*)& byte_587000[8 * v7 + 194140] * 150.0;
        v23[0] = v8;
        v21 = v9 + (double)(int)v2[109];
        v10 = sub_419A70(v21);
        v11 = *(_DWORD*)& byte_5D4594[1313700];
        v23[1] = v10;
        if (v2[27] != *(_DWORD*)& byte_5D4594[1313692])
            v11 = *(_DWORD*)& byte_5D4594[1313704];
        v12 = sub_415FF0(6, 8, "C:\\NoxPost\\src\\Client\\Draw\\Glowdraw.c", 793);
        sub_499490(v11, v23, 0, 0, v12, 1);
        sub_45A4E0((int)v2);
        result = 0;
    }
    return result;
}

//----- (004B7540) --------------------------------------------------------
int __cdecl nox_thing_bubble_draw(_DWORD* a1, int a2)
{
    unsigned int v2; // eax
    int v4; // edx
    int v5; // eax
    char v6; // al
    char v7; // al
    char v8; // al
    unsigned __int8 v9; // al
    char v10; // al
    char v11; // al
    char v12; // dl
    bool v13; // zf
    char v14; // al
    char v15; // al
    char v16; // al
    int2 xLeft; // [esp+8h] [ebp-8h]

    if (*(_BYTE*)(a2 + 441) == 3)
        goto LABEL_29;
    v2 = *(_DWORD*)(a2 + 356);
    if (v2 && v2 <= *(int*)& byte_5D4594[2598000])
    {
        *(_BYTE*)(a2 + 441) = 3;
        *(_BYTE*)(a2 + 442) = 4;
        *(_BYTE*)(a2 + 443) = 4;
        sub_49B950((_DWORD*)a2, *(int*)& byte_5D4594[2649704]);
    }
    if (*(_BYTE*)(a2 + 441) == 3)
    {
    LABEL_29:
        if (!*(_BYTE*)(a2 + 440))
        {
            sub_45A4E0(a2);
            return 0;
        }
    }
    v4 = a1[1];
    xLeft.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v5 = *(unsigned __int8*)(a2 + 440);
    xLeft.field_4 = *(_DWORD*)(a2 + 16) + v4 - a1[5] - *(__int16*)(a2 + 104);
    sub_4B6720(&xLeft, *(_DWORD*)(a2 + 432), v5, v5 + 3);
    sub_434460(*(_DWORD*)(a2 + 436));
    sub_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(a2 + 440) >> 1);
    if (byte_5D4594[2598000] & 3)
        * (_WORD*)(a2 + 104) += *(char*)(a2 + 446);
    v6 = *(_BYTE*)(a2 + 442);
    if (v6)
    {
        v7 = v6 - 1;
        *(_BYTE*)(a2 + 442) = v7;
        if (!v7)
        {
            v8 = *(_BYTE*)(a2 + 441);
            if (v8 == 1)
            {
                v9 = *(_BYTE*)(a2 + 440) + 1;
                *(_BYTE*)(a2 + 440) = v9;
                if (v9 >= 5u)
                    * (_BYTE*)(a2 + 441) = 2;
            }
            else
            {
                v13 = v8 == 2;
                v14 = *(_BYTE*)(a2 + 440);
                if (v13)
                {
                    v15 = v14 - 1;
                    *(_BYTE*)(a2 + 440) = v15;
                    if (!v15)
                        * (_BYTE*)(a2 + 441) = 1;
                }
                else
                {
                    v16 = v14 - 1;
                    *(_BYTE*)(a2 + 440) = v16;
                    if (!v16)
                    {
                        sub_45A4E0(a2);
                        return 0;
                    }
                }
            }
            *(_BYTE*)(a2 + 442) = *(_BYTE*)(a2 + 443);
        }
    }
    v10 = *(_BYTE*)(a2 + 445);
    if (v10)
    {
        v11 = v10 - 1;
        *(_BYTE*)(a2 + 445) = v11;
        if (!v11)
        {
            v12 = *(_BYTE*)(a2 + 444);
            *(_BYTE*)(a2 + 446) = -*(_BYTE*)(a2 + 446);
            *(_BYTE*)(a2 + 445) = v12;
        }
    }
    if ((short) * (_WORD*)(a2 + 104) >= 0)
        return 1;
    sub_45A4E0(a2);
    return 0;
}

//----- (004B7700) --------------------------------------------------------
int __cdecl nox_thing_levelup_draw(int a1, int a2)
{
    int v2; // eax

    v2 = *(_DWORD*)& byte_5D4594[1313708];
    if (!*(_DWORD*)& byte_5D4594[1313708])
    {
        v2 = sub_44CFC0((CHAR*)& byte_587000[176492]);
        *(_DWORD*)& byte_5D4594[1313708] = v2;
    }
    sub_4B7740(v2, a1, a2);
    return 1;
}

//----- (004B7740) --------------------------------------------------------
_DWORD* __cdecl sub_4B7740(int a1, int a2, int a3)
{
    int2* v3; // edi
    int v4; // ebp
    int v5; // eax
    int v6; // esi
    char v7; // al
    _DWORD* result; // eax
    int2 a2a; // [esp+10h] [ebp-8h]

    v3 = (int2*)(a3 + 12);
    v4 = 2;
    do
    {
        a2a.field_0 = v3->field_0 + sub_415FF0(-15, 15, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 35);
        v5 = *(_DWORD*)(a3 + 16) + sub_415FF0(-15, 15, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 36);
        a2a.field_4 = v5;
        v6 = v5 - *(_DWORD*)(a2 + 20);
        v7 = sub_415FF0(8, 12, "C:\\NoxPost\\src\\client\\Draw\\LvUpDraw.c", 40);
        result = (_DWORD*)sub_499950(a1, &a2a, v3, v6, -v7);
        --v4;
    } while (v4);
    return result;
}

//----- (004B77D0) --------------------------------------------------------
int __cdecl nox_thing_oblivion_up_draw(int a1, int a2)
{
    int v2; // eax

    v2 = *(_DWORD*)& byte_5D4594[1313712];
    if (!*(_DWORD*)& byte_5D4594[1313712])
    {
        v2 = sub_44CFC0((CHAR*)& byte_587000[176628]);
        *(_DWORD*)& byte_5D4594[1313712] = v2;
    }
    sub_4B7740(v2, a1, a2);
    return 1;
}

//----- (004B7810) --------------------------------------------------------
int __cdecl nox_thing_blue_rain_draw(int a1, int a2)
{
    int v3; // ebx
    int v4; // ebp
    int v5; // eax
    int v6; // edi
    int v7; // eax
    int v8; // esi
    int v9; // [esp+8h] [ebp+8h]

    if (sub_40A5C0(0x200000))
        return 1;
    if (!*(_DWORD*)& byte_5D4594[1313716])
        * (_DWORD*)& byte_5D4594[1313716] = sub_44CFC0((CHAR*)& byte_587000[176640]);
    v3 = a2;
    v9 = 2;
    do
    {
        v4 = *(_DWORD*)(v3 + 12) + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 42);
        v5 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 43);
        v6 = *(_DWORD*)(v3 + 16) + v5;
        v7 = sub_45A360(*(int*)& byte_5D4594[1313716], v4, v6);
        v8 = v7;
        if (v7)
        {
            *(_DWORD*)(v7 + 432) = v4 << 12;
            *(_DWORD*)(v7 + 436) = v6 << 12;
            *(_BYTE*)(v7 + 299) = 0;
            *(_DWORD*)(v7 + 440) = 0;
            *(_DWORD*)(v7 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                + sub_415FF0(90, 120, "C:\\NoxPost\\src\\client\\Draw\\PartRain.c", 63);
            *(_DWORD*)(v8 + 444) = *(_DWORD*)& byte_5D4594[2598000];
            *(_WORD*)(v8 + 106) = 0;
            *(_BYTE*)(v8 + 296) = -5;
            *(_WORD*)(v8 + 104) = v6 - *(_WORD*)(a1 + 20);
            sub_45A110((_DWORD*)v8);
        }
        --v9;
    } while (v9);
    return 1;
}

//----- (004B7920) --------------------------------------------------------
int __cdecl nox_thing_arrow_draw(int* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // edi
    _DWORD* v4; // edi
    int v5; // eax

    v2 = *(_DWORD*)& byte_5D4594[1313720];
    if (!*(_DWORD*)& byte_5D4594[1313720])
    {
        v2 = sub_44CFC0((CHAR*)& byte_587000[176776]);
        *(_DWORD*)& byte_5D4594[1313720] = v2;
    }
    v3 = a2[81];
    if ((a2[3] - v3) * (a2[3] - v3) + (a2[4] - a2[82]) * (a2[4] - a2[82]) > 200)
    {
        v4 = (_DWORD*)sub_45A360(v2, v3, a2[82]);
        v4[108] = a2[3];
        v4[109] = a2[4];
        sub_45A110(v4);
        v5 = a2[4];
        a2[81] = a2[3];
        a2[82] = v5;
        sub_49B950(v4, *(_DWORD*)& byte_5D4594[2649704] / 3u);
    }
    return nox_thing_slave_draw(a1, (int)a2);
}

//----- (004B79D0) --------------------------------------------------------
int __cdecl nox_thing_weak_arrow_draw(int* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // edi
    _DWORD* v4; // edi
    int v5; // eax

    v2 = *(_DWORD*)& byte_5D4594[1313724];
    if (!*(_DWORD*)& byte_5D4594[1313724])
    {
        v2 = sub_44CFC0((CHAR*)& byte_587000[176792]);
        *(_DWORD*)& byte_5D4594[1313724] = v2;
    }
    v3 = a2[81];
    if ((a2[3] - v3) * (a2[3] - v3) + (a2[4] - a2[82]) * (a2[4] - a2[82]) > 200)
    {
        v4 = (_DWORD*)sub_45A360(v2, v3, a2[82]);
        v4[108] = a2[3];
        v4[109] = a2[4];
        sub_45A110(v4);
        v5 = a2[4];
        a2[81] = a2[3];
        a2[82] = v5;
        sub_49B950(v4, *(_DWORD*)& byte_5D4594[2649704] / 3u);
    }
    return nox_thing_slave_draw(a1, (int)a2);
}

//----- (004B7A80) --------------------------------------------------------
int __cdecl nox_thing_undead_killer_draw(int* a1, int a2)
{
    int result; // eax
    __int16 v3; // dx
    int v4; // eax
    int v5; // ecx
    int v6; // ebx
    int v7; // edi
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // [esp-18h] [ebp-28h]
    int v12; // [esp-14h] [ebp-24h]
    char v13; // [esp-Ch] [ebp-1Ch]
    __int16 v14[4]; // [esp+0h] [ebp-10h]
    int2 v15; // [esp+8h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1313728])
    {
        *(_DWORD*)& byte_5D4594[1313736] = sub_44CFC0((CHAR*)& byte_587000[176812]);
        *(_DWORD*)& byte_5D4594[1313732] = sub_4344A0(100, 100, 255);
        *(_DWORD*)& byte_5D4594[1313728] = 1;
    }
    if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 316)) <= 0x46)
    {
        if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 54) > 85)
        {
            v3 = *(_WORD*)(a2 + 328);
            v14[0] = *(_WORD*)(a2 + 324);
            v14[1] = v3;
            v14[2] = *(_WORD*)(a2 + 12) + sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 60);
            v14[3] = *(_WORD*)(a2 + 16) + sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 61);
            v13 = sub_415FF0(6, 10, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 66);
            v4 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Draw\\UDedDraw.c", 65);
            sub_499490(*(int*)& byte_5D4594[1313736], v14, 0, v4, v13, 0);
        }
        v5 = *(_DWORD*)(a2 + 12);
        v6 = a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104);
        v7 = a1[5];
        v8 = *(_DWORD*)(a2 + 328);
        v15.field_0 = v5 + *a1 - a1[4];
        v12 = *(_DWORD*)(a2 + 324);
        v11 = *(_DWORD*)(a2 + 16);
        v15.field_4 = *(_DWORD*)(a2 + 16) + v6 - v7;
        v9 = sub_48C690(v5, v11, v12, v8);
        v10 = 8 - v9 / 40;
        if (v10 < 0)
            v10 = 1;
        sub_4B6720(&v15, *(int*)& byte_5D4594[1313732], v10, 12);
        result = 1;
    }
    else
    {
        sub_45A4E0(a2);
        result = 0;
    }
    return result;
}
// 4B7BE5: variable 'v9' is possibly undefined

//----- (004B7C20) --------------------------------------------------------
int __cdecl nox_thing_released_soul_draw(int* a1, int a2)
{
    return nox_thing_vector_animate_draw(a1, a2);
}

//----- (004B7C40) --------------------------------------------------------
_DWORD* __cdecl sub_4B7C40(__int16 a1, unsigned __int16* a2, unsigned __int16 a3, unsigned __int8 a4, __int16 a5)
{
    int v5; // eax
    _DWORD* result; // eax
    _DWORD* v7; // edi
    _DWORD* v8; // esi
    int v9; // [esp-8h] [ebp-1Ch]
    int v10; // [esp-4h] [ebp-18h]
    int v11; // [esp+10h] [ebp-4h]

    v10 = a2[1];
    v9 = *a2;
    v5 = sub_44CFC0((CHAR*)& byte_587000[177024]);
    result = (_DWORD*)sub_45A360(v5, v9, v10);
    v7 = result;
    if (result)
    {
        result = sub_45A240(a3);
        v8 = result;
        if (result)
        {
            result[3] = *a2;
            result[4] = a2[1];
            *((_BYTE*)result + 297) = sub_509EA0(a4);
            HIWORD(v11) = a1;
            LOWORD(v11) = a5;
            v8[69] = 8;
            v7[108] = v8;
            v7[109] = v11;
            result = *(_DWORD * *)& byte_5D4594[2598000];
            v7[79] = *(_DWORD*)& byte_5D4594[2598000];
        }
    }
    return result;
}

//----- (004B7D00) --------------------------------------------------------
int __cdecl nox_thing_summon_effect_draw(int* a1, _DWORD* a2)
{
    _DWORD* v2; // esi
    int v3; // ecx
    int v4; // edx
    int v5; // ebx
    int v6; // eax
    int v7; // ecx
    int v8; // edx
    int result; // eax
    unsigned int v10; // ebp
    unsigned __int8* v11; // edi
    unsigned int v12; // eax
    int v13; // ecx
    int v14; // eax
    int v15; // [esp+Ch] [ebp-8h]
    __int64 v16; // [esp+Ch] [ebp-8h]
    int v17; // [esp+10h] [ebp-4h]
    int v18; // [esp+1Ch] [ebp+8h]

    v2 = a2;
    v3 = a2[3];
    v4 = a2[4];
    v5 = a2[76];
    v18 = a2[77];
    v6 = *(_DWORD*)& byte_5D4594[1313740];
    v15 = v3;
    v17 = v4;
    if (!*(_DWORD*)& byte_5D4594[1313740])
    {
        v6 = sub_44CFC0((CHAR*)& byte_587000[177040]);
        *(_DWORD*)& byte_5D4594[1313740] = v6;
    }
    v7 = *(_DWORD*)& byte_5D4594[2598000] - v2[79];
    v8 = *((unsigned __int16*)v2 + 218);
    if (v7 < (unsigned int)(unsigned __int16)v8)
    {
        if (v7 >= v8 - 1)
            sub_499610(v6, 50, 1000, 30, v2[3], v2[4]);
        nox_thing_animate_draw(a1, (int)v2);
        v10 = 0;
        v11 = &byte_587000[192092];
        do
        {
            if (v10 >= *(unsigned __int8*)(v5 + 8))
                v10 = 0;
            v12 = (v10 + *(_DWORD*)& byte_5D4594[2598000] + v2[32]) / ((unsigned int) * (unsigned __int8*)(v5 + 9) + 1);
            v2[77] = v12;
            if (v12 >= *(unsigned __int8*)(v5 + 8))
                v2[77] = v12 % *(unsigned __int8*)(v5 + 8);
            *(_DWORD*)(v5 + 12) = 5;
            v13 = v15 + 2 * *((_DWORD*)v11 - 1);
            v2[3] = v13;
            v14 = v17 + 2 * *(_DWORD*)v11;
            v2[4] = v14;
            if (v13 >= 0 && v13 < 5888 && v14 >= 0 && v14 < 5888)
                nox_thing_animate_draw(a1, (int)v2);
            v11 += 80;
            ++v10;
        } while ((int)v11 < (int)& byte_587000[194140]);
        v2[3] = v15;
        v2[4] = v17;
        v2[77] = v18;
        *(_DWORD*)(v5 + 12) = 2;
        sub_434560(1);
        v16 = *(unsigned int*)& byte_5D4594[2598000];
        LODWORD(v16) = v2[79];
        sub_434580((__int64)(((double) * (unsigned int*)& byte_5D4594[2598000] - (double)v16)
            / (double) * ((unsigned __int16*)v2 + 218)
            * 255.0));
        (*(void(__cdecl * *)(int*, _DWORD))(v2[108] + 300))(a1, v2[108]);
        sub_434560(0);
        result = 1;
    }
    else
    {
        sub_45A4B0((_QWORD*)v2[108]);
        sub_45A4E0((int)v2);
        result = 0;
    }
    return result;
}

//----- (004B7EE0) --------------------------------------------------------
int __cdecl sub_4B7EE0(__int16 a1)
{
    int result; // eax
    int v2; // esi

    if (!*(_DWORD*)& byte_5D4594[1313744])
        * (_DWORD*)& byte_5D4594[1313744] = sub_44CFC0((CHAR*)& byte_587000[177052]);
    if (!*(_DWORD*)& byte_5D4594[1313740])
        * (_DWORD*)& byte_5D4594[1313740] = sub_44CFC0((CHAR*)& byte_587000[177068]);
    result = sub_45A060();
    v2 = result;
    if (result)
    {
        while (*(_DWORD*)(v2 + 108) != *(_DWORD*)& byte_5D4594[1313744] || *(_WORD*)(v2 + 438) != a1)
        {
            result = sub_45A070(v2);
            v2 = result;
            if (!result)
                return result;
        }
        sub_499610(*(int*)& byte_5D4594[1313740], 50, 1000, 30, *(_DWORD*)(v2 + 12), *(_DWORD*)(v2 + 16));
        sub_45A4B0(*(_QWORD * *)(v2 + 432));
        result = sub_45A4E0(v2);
    }
    return result;
}

//----- (004B7F90) --------------------------------------------------------
int sub_4B7F90()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1313748] = sub_44CFC0((CHAR*)& byte_587000[177080]);
    *(_DWORD*)& byte_5D4594[1313752] = sub_44CFC0((CHAR*)& byte_587000[177100]);
    *(_DWORD*)& byte_5D4594[1313756] = sub_44CFC0((CHAR*)& byte_587000[177120]);
    *(_DWORD*)& byte_5D4594[1313760] = sub_44CFC0((CHAR*)& byte_587000[177140]);
    *(_DWORD*)& byte_5D4594[1313768] = sub_44CFC0((CHAR*)& byte_587000[177160]);
    *(_DWORD*)& byte_5D4594[1313772] = sub_44CFC0((CHAR*)& byte_587000[177180]);
    *(_DWORD*)& byte_5D4594[1313776] = sub_44CFC0((CHAR*)& byte_587000[177200]);
    result = sub_44CFC0((CHAR*)& byte_587000[177220]);
    *(_DWORD*)& byte_5D4594[1313780] = result;
    *(_DWORD*)& byte_5D4594[1313764] = 0;
    *(_DWORD*)& byte_5D4594[1313784] = 1;
    return result;
}

//----- (004B8020) --------------------------------------------------------
int __cdecl nox_thing_spherical_shield_draw(int* a1, _DWORD* a2)
{
    int v2; // esi
    int v3; // eax
    _DWORD* v4; // eax
    int v5; // eax
    int result; // eax

    v2 = a2[108];
    if (sub_578B70(a2[108]))
    {
        v3 = sub_578B30(v2);
        v4 = sub_45A720(v3);
    }
    else
    {
        v5 = sub_578B30(v2);
        v4 = sub_45A6F0(v5);
    }
    if (v4)
    {
        sub_49AA90(a2, v4[3], v4[4] + 3);
        result = nox_thing_animate_draw(a1, (int)a2);
    }
    else
    {
        sub_45A4E0((int)a2);
        result = 0;
    }
    return result;
}
// 4B8040: variable 'v3' is possibly undefined
// 4B804D: variable 'v5' is possibly undefined

//----- (004B8090) --------------------------------------------------------
_DWORD* __cdecl sub_4B8090(unsigned int a1, int a2)
{
    int v2; // edi
    int v3; // eax
    _DWORD* result; // eax
    int v5; // eax
    _DWORD* v6; // esi
    int4 v7; // [esp+0h] [ebp-10h]

    if (!*(_DWORD*)& byte_5D4594[1313784])
        sub_4B7F90();
    v2 = a2;
    switch (a2)
    {
    case 0:
        sub_44CFC0((CHAR*)& byte_587000[177380]);
        break;
    case 1:
        sub_44CFC0((CHAR*)& byte_587000[177240]);
        break;
    case 2:
        sub_44CFC0((CHAR*)& byte_587000[177260]);
        break;
    case 3:
        sub_44CFC0((CHAR*)& byte_587000[177360]);
        break;
    case 5:
        sub_44CFC0((CHAR*)& byte_587000[177280]);
        break;
    case 6:
        sub_44CFC0((CHAR*)& byte_587000[177340]);
        break;
    case 7:
        sub_44CFC0((CHAR*)& byte_587000[177320]);
        break;
    case 8:
        sub_44CFC0((CHAR*)& byte_587000[177300]);
        break;
    default:
        break;
    }
    if (sub_578B70(a1))
    {
        v3 = sub_578B30(a1);
        result = sub_45A720(v3);
    }
    else
    {
        v5 = sub_578B30(a1);
        result = sub_45A6F0(v5);
    }
    v6 = result;
    if (result)
    {
        v7.field_0 = result[3] - 10;
        v7.field_4 = result[4] - 10;
        v7.field_8 = result[3] + 10;
        v7.field_C = result[4] + 10;
        *(_DWORD*)& byte_5D4594[1313788] = 0;
        sub_49AB00(&v7, sub_4B81E0, (int)& a1);
        result = *(_DWORD * *)& byte_5D4594[1313788];
        if (*(_DWORD*)& byte_5D4594[1313788] != 1)
        {
            result = (_DWORD*)sub_45A360(*(_DWORD*)& byte_5D4594[4 * v2 + 1313748], v6[3], v6[4] + 3);
            if (result)
                result[108] = a1;
        }
    }
    return result;
}
// 4B810D: variable 'v3' is possibly undefined
// 4B811F: variable 'v5' is possibly undefined

//----- (004B81E0) --------------------------------------------------------
void __cdecl sub_4B81E0(int a1, int a2)
{
    unsigned __int8* v2; // eax

    v2 = &byte_5D4594[1313748];
    do
    {
        if (*(_DWORD*)(a1 + 108) == *(_DWORD*)v2 && *(_DWORD*)(a1 + 432) == *(_DWORD*)a2)
            * (_DWORD*)& byte_5D4594[1313788] = 1;
        v2 += 4;
    } while ((int)v2 < (int)& byte_5D4594[1313784]);
}

//----- (004B8220) --------------------------------------------------------
int sub_4B8220()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1313792])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[1313792]);
    *(_DWORD*)& byte_5D4594[1313792] = 0;
    if (*(_DWORD*)& byte_5D4594[1313796])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[1313796]);
    result = *(_DWORD*)& byte_5D4594[1313800];
    if (*(_DWORD*)& byte_5D4594[1313800])
        result = sub_45A4B0(*(_QWORD * *)& byte_5D4594[1313800]);
    *(_DWORD*)& byte_5D4594[1313796] = 0;
    *(_DWORD*)& byte_5D4594[1313800] = 0;
    return result;
}

//----- (004B8270) --------------------------------------------------------
int __cdecl nox_thing_player_draw(int a1, int a2)
{
    int v2; // ebx
    char* v3; // esi
    _DWORD* v4; // eax
    char* v5; // eax
    _DWORD* v6; // edi
    _DWORD* v7; // eax
    _DWORD* v8; // ebp
    unsigned __int8 v9; // al
    int* v10; // ebp
    _DWORD* v11; // eax
    int v12; // edi
    int v13; // eax
    int v14; // ecx
    _DWORD* v15; // edx
    int v16; // eax
    int* v17; // edi
    int v18; // eax
    char v20; // al
    __int16* v21; // edi
    int v22; // esi
    int* v23; // eax
    int v24; // eax
    int v25; // eax
    int v26; // [esp-4h] [ebp-6Ch]
    int v27; // [esp+10h] [ebp-58h]
    int v28; // [esp+14h] [ebp-54h]
    char* v29; // [esp+18h] [ebp-50h]
    int v30; // [esp+1Ch] [ebp-4Ch]
    int v31; // [esp+20h] [ebp-48h]
    char* v32; // [esp+24h] [ebp-44h]
    int v33; // [esp+28h] [ebp-40h]
    int v34; // [esp+2Ch] [ebp-3Ch]
    BOOL v35; // [esp+30h] [ebp-38h]
    int v36[13]; // [esp+34h] [ebp-34h]

    v2 = a2;
    v26 = *(_DWORD*)(a2 + 128);
    v31 = 0;
    v30 = 0;
    v29 = 0;
    v3 = sub_417040(v26);
    v32 = v3;
    if (!v3)
        return 1;
    if (*(_DWORD*)& byte_5D4594[2618908] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 1)
        v30 = 1;
    if (*(_DWORD*)& byte_5D4594[2616328] == *(_DWORD*)(v2 + 128))
    {
        v4 = sub_418C80(*(int*)& byte_5D4594[2616328]);
        if (!v4)
            goto LABEL_15;
        v5 = sub_418AB0(*((unsigned __int8*)v4 + 4));
        goto LABEL_14;
    }
    if (v3[3680] & 1)
        return 1;
    v6 = sub_418C80(*(int*)& byte_5D4594[2616328]);
    if (v6)
    {
        v7 = sub_418C80(*(_DWORD*)(v2 + 128));
        v8 = v7;
        if (v7)
        {
            if (sub_419150((int)v6, (int)v7))
                v31 = 1;
            v5 = sub_418AB0(*((unsigned __int8*)v8 + 4));
        LABEL_14:
            v29 = v5;
            goto LABEL_15;
        }
    }
LABEL_15:
    v9 = sub_417DD0();
    v10 = (int*)a1;
    v35 = v9 != 0;
    if (!(v3[4] & 1))
    {
    LABEL_24:
        v12 = 0;
        goto LABEL_25;
    }
    v36[2] = nox_win_width;
    v36[8] = nox_win_width;
    v11 = *(_DWORD * *)& byte_5D4594[1313792];
    v12 = 0;
    v36[0] = 0;
    v36[1] = 0;
    v36[3] = nox_win_height;
    v36[9] = nox_win_height;
    v36[4] = 0;
    v36[5] = 0;
    if (*(_DWORD*)& byte_5D4594[1313792]
        || (v13 = sub_44CFC0((CHAR*)& byte_587000[177400]),
            v11 = sub_45A240(v13),
            (*(_DWORD*)& byte_5D4594[1313792] = v11) != 0))
    {
        v14 = 0;
        v15 = v3 + 2324;
        while (*v15 != 1)
        {
            ++v14;
            v15 += 6;
            if (v14 >= 27)
                goto LABEL_23;
        }
        qmemcpy(v11 + 108, &v3[24 * v14 + 2328], 0x14u);
        v11 = *(_DWORD * *)& byte_5D4594[1313792];
        v3 = v32;
    LABEL_23:
        v11[3] = *(_DWORD*)(v2 + 12) - v10[4] + *v10 + 15;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313792] + 16) = v10[1] - v10[5] + *(_DWORD*)(v2 + 16) - 25;
        (*(void(__cdecl * *)(int*, _DWORD))(*(_DWORD*)& byte_5D4594[1313792] + 300))(v36, *(_DWORD*)& byte_5D4594[1313792]);
        goto LABEL_24;
    }
LABEL_25:
    if (!sub_4356C0(v2, 23))
    {
        if (!sub_4356C0(v2, 25))
        {
            *(_DWORD*)& byte_5D4594[3798668] = *((_DWORD*)v3 + 574);
            *(_DWORD*)& byte_5D4594[3798672] = *((_DWORD*)v3 + 576);
            *(_DWORD*)& byte_5D4594[3798676] = *((_DWORD*)v3 + 578);
            *(_DWORD*)& byte_5D4594[3798680] = *((_DWORD*)v3 + 577);
            *(_DWORD*)& byte_5D4594[3798684] = *((_DWORD*)v3 + 575);
            *(_DWORD*)& byte_5D4594[3798688] = *((_DWORD*)v3 + 573);
            v16 = *((_DWORD*)v3 + 920);
            if (v16 & 0x400)
            {
                v17 = (int*)& byte_5D4594[3798668];
                do
                {
                    sub_434480(*v17, (int)& v33, (int)& a2, (int)& a1);
                    if ((unsigned __int8)a2 >= 0x9Bu)
                        LOBYTE(a2) = -1;
                    else
                        LOBYTE(a2) = a2 + 100;
                    *v17 = sub_4344A0(v33, a2, a1);
                    ++v17;
                } while ((int)v17 < (int)& byte_5D4594[3798692]);
                v12 = 0;
            }
            goto LABEL_37;
        }
        goto LABEL_29;
    }
    if (!(byte_5D4594[2598000] & 1))
    {
    LABEL_29:
        *(_DWORD*)& byte_5D4594[3798668] = *(_DWORD*)& byte_5D4594[2650684];
        *(_DWORD*)& byte_5D4594[3798672] = *(_DWORD*)& byte_5D4594[2650684];
        *(_DWORD*)& byte_5D4594[3798676] = *(_DWORD*)& byte_5D4594[2650684];
        *(_DWORD*)& byte_5D4594[3798680] = *(_DWORD*)& byte_5D4594[2650684];
        *(_DWORD*)& byte_5D4594[3798684] = *(_DWORD*)& byte_5D4594[2650684];
        *(_DWORD*)& byte_5D4594[3798688] = *(_DWORD*)& byte_5D4594[2650684];
        goto LABEL_37;
    }
    *(_DWORD*)& byte_5D4594[3798668] = *(_DWORD*)& byte_5D4594[2523948];
    *(_DWORD*)& byte_5D4594[3798672] = *(_DWORD*)& byte_5D4594[2523948];
    *(_DWORD*)& byte_5D4594[3798676] = *(_DWORD*)& byte_5D4594[2523948];
    *(_DWORD*)& byte_5D4594[3798680] = *(_DWORD*)& byte_5D4594[2523948];
    *(_DWORD*)& byte_5D4594[3798684] = *(_DWORD*)& byte_5D4594[2523948];
    *(_DWORD*)& byte_5D4594[3798688] = *(_DWORD*)& byte_5D4594[2523948];
LABEL_37:
    sub_4341D0(1, *(int*)& byte_5D4594[3798668]);
    sub_4341D0(2, *(int*)& byte_5D4594[3798672]);
    sub_4341D0(3, *(int*)& byte_5D4594[3798676]);
    sub_4341D0(4, *(int*)& byte_5D4594[3798680]);
    sub_4341D0(5, *(int*)& byte_5D4594[3798684]);
    sub_4341D0(6, *(int*)& byte_5D4594[3798688]);
    v18 = sub_4B8FA0(v2, &v28, &v27);
    if (!v18)
        return 0;
    sub_4C4770(v10, (unsigned __int8*)v2, v18);

    // A player in Nox has a 32-bit integer field that contains bits for each
    // type of armor / weapon. sub_4B8D40 is responsible for iterating over
    // each type and drawing it to the screen.
    //
    // To add support for drawing the quiver, we must modify sub_4B8D40 to
    // iterate from 1 instead of 2 (i.e. bit 1 indicates quiver equipped). We
    // must also modify how sub_4B8D40 is called because of Z ordering.
    //
    // The Z ordering is simple to understand. Usually Nox will draw the player
    // body, and then the armor / weapon on top (or vice versa depending on
    // rotation). The quiver is unique because it is on the player's back, e.g.
    // it must be drawn first, then the body, then the rest of the armor.
    v20 = *(_BYTE*)(v2 + 297);
    if (v20 != 1 && v20 && v20 != 2 && v20 != 3 && v20 != 6 || *(_DWORD*)(v2 + 276) == 37)
    {
        sub_4B8D40(v10, v2, *((_DWORD*)v3 + 1) & 2, (_DWORD*)v3 + 581, v28, v27);
        sub_4B8960(v10, v2, *(_DWORD*)v3, (_DWORD*)v3 + 743, v28, v27);
        sub_4B8D40(v10, v2, *((_DWORD*)v3 + 1) & ~2, (_DWORD*)v3 + 581, v28, v27);
    }
    else
    {
        sub_4B8D40(v10, v2, *((_DWORD*)v3 + 1) & ~2, (_DWORD*)v3 + 581, v28, v27);
        sub_4B8960(v10, v2, *(_DWORD*)v3, (_DWORD*)v3 + 743, v28, v27);
        sub_4B8D40(v10, v2, *((_DWORD*)v3 + 1) & 2, (_DWORD*)v3 + 581, v28, v27);
    }

    if (v30
        || !sub_4356C0(v2, 0)
        || *(_DWORD*)(v2 + 128) == *(_DWORD*)& byte_5D4594[2616328]
        || *(_DWORD*)& byte_5D4594[2614252] && (sub_4356C0(*(int*)& byte_5D4594[2614252], 21) || v31))
    {
        a1 = sub_4344A0(155, 155, 155);
        if (!sub_48D830(v2) && !sub_40A5C0(2048))
        {
            v21 = (__int16*)(v3 + 4704);
            sub_43F840(0, (unsigned __int16*)v3 + 2352, &v34, 0, 0);
            v22 = *v10 + *(_DWORD*)(v2 + 12) + v34 / -2 - v10[4];
            a2 = v10[1] - v10[5] + *(_DWORD*)(v2 + 16) - 64;
            sub_434390(*(int*)& byte_5D4594[2614248]);
            sub_43F6E0(0, v21, v22 + 1, a2 + 1);
            sub_434390(a1);
            if (v35)
            {
                if (v29)
                {
                    v23 = (int*)sub_418D50((int)v29);
                    if (v23)
                        sub_434390(*v23);
                }
            }
            sub_43F6E0(0, v21, v22, a2);
            v3 = v32;
            v12 = 0;
        }
        if (sub_4356C0(v2, 16))
        {
            v36[2] = nox_win_width;
            v36[8] = nox_win_width;
            v36[0] = 0;
            v36[1] = 0;
            v36[3] = nox_win_height;
            v36[9] = nox_win_height;
            v36[4] = 0;
            v36[5] = 0;
            if (!*(_DWORD*)& byte_5D4594[1313796])
            {
                v24 = sub_44CFC0((CHAR*)& byte_587000[177408]);
                *(_DWORD*)& byte_5D4594[1313796] = sub_45A240(v24);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313796] + 120) |= 0x1000000u;
            }
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313796] + 12) = *v10 + *(_DWORD*)(v2 + 12) - v10[4];
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313796] + 16) = v10[1] - v10[5] + *(_DWORD*)(v2 + 16) - 50;
            (*(void(__cdecl * *)(int*, _DWORD))(*(_DWORD*)& byte_5D4594[1313796] + 300))(
                v36,
                *(_DWORD*)& byte_5D4594[1313796]);
        }
        if (sub_4356C0(v2, 30))
        {
            v36[2] = nox_win_width;
            v36[8] = nox_win_width;
            v36[0] = 0;
            v36[1] = 0;
            v36[3] = nox_win_height;
            v36[9] = nox_win_height;
            v36[4] = 0;
            v36[5] = 0;
            if (!*(_DWORD*)& byte_5D4594[1313800])
            {
                v25 = sub_44CFC0((CHAR*)& byte_587000[177424]);
                *(_DWORD*)& byte_5D4594[1313800] = sub_45A240(v25);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313800] + 120) |= 0x1000000u;
            }
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313800] + 12) = *v10 + *(_DWORD*)(v2 + 12) - v10[4];
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313800] + 16) = v10[1] - v10[5] + *(_DWORD*)(v2 + 16) - 50;
            (*(void(__cdecl * *)(int*, _DWORD))(*(_DWORD*)& byte_5D4594[1313800] + 300))(
                v36,
                *(_DWORD*)& byte_5D4594[1313800]);
        }
        do
            sub_4341D0(v12++, *(int*)& byte_5D4594[2523948]);
        while (v12 < 6);
        if (v2 != *(_DWORD*)& byte_5D4594[2614252] && sub_470A90())
        {
            if (sub_40A5C0(4096))
                sub_4B8EB0(v10, v2, (unsigned __int8)v3[2282], (*((_DWORD*)v3 + 920) >> 10) & 1);
        }
    }
    return 1;
}

//----- (004B8960) --------------------------------------------------------
__int16 __cdecl sub_4B8960(int* a1, int a2, int a3, _DWORD* a4, int a5, int a6)
{
    unsigned __int8* v6; // esi
    int v7; // ecx
    int v8; // edx
    char v9; // al
    int v10; // eax
    int v11; // edi
    int i; // esi
    int v13; // ebp
    int v14; // eax
    int v15; // ebx
    unsigned __int8 v16; // cl
    int v17; // edi
    int j; // esi
    int v19; // ecx
    int v20; // edi
    int k; // esi
    int v22; // eax
    int v23; // ecx
    int v24; // edi
    int l; // esi
    int v27; // [esp+8h] [ebp-18h]
    BOOL v28; // [esp+Ch] [ebp-14h]
    int* v29; // [esp+10h] [ebp-10h]
    int v30; // [esp+14h] [ebp-Ch]
    int v31; // [esp+18h] [ebp-8h]

    v6 = (unsigned __int8*)a2;
    v28 = sub_4356C0(a2, 23);
    v7 = 0;
    v30 = 0;
    v31 = 0;
    if (byte_5D4594[2598000] & 1)
        v27 = *(_DWORD*)& byte_5D4594[2523948];
    else
        v27 = *(_DWORD*)& byte_5D4594[2650684];
    v8 = a3;
    if (a3 & 2)
    {
        v9 = *(_BYTE*)(a2 + 297);
        if (v9 == 6 || v9 == 7 || v9 == 8)
        {
            v10 = *(_DWORD*)(a2 + 276);
            if (v10 != 6 && v10 != 35 && v10 != 39 && v10 != 40)
            {
                while (!((1 << v7) & 2))
                {
                    if (++v7 >= 26)
                        goto LABEL_22;
                }
                v11 = *(_DWORD*)(a5 + 4 * v7 + 52);
                if (v11)
                {
                    if (v28)
                    {
                        for (i = 1; i < 7; ++i)
                            sub_4341D0(i, v27);
                        v6 = (unsigned __int8*)a2;
                    }
                    else
                    {
                        sub_4B8CA0(a4, (char*)2);
                    }
                    sub_4C4770(a1, v6, *(_DWORD*)(*(_DWORD*)(v11 + 4 * v6[297] + 4) + 4 * a6));
                    v8 = a3;
                    v30 = 1;
                }
            }
        }
    }
LABEL_22:
    v13 = 0;
    v29 = (int*)(a5 + 52);
    do
    {
        v14 = 1 << v13;
        if (!((1 << v13) & 2))
        {
            v15 = v14 & 0x3000000;
            if (!(v14 & 0x3000000) || (v16 = v6[297], v16 != 3) && v16 && v16 != 6 && v16 != 7)
            {
                if (v14 & v8 && (!(v14 & 0xC00) || !(v8 & 0x4000)))
                {
                    v17 = *v29;
                    if (*v29)
                    {
                        if (v28)
                        {
                            for (j = 1; j < 7; ++j)
                                sub_4341D0(j, v27);
                            v6 = (unsigned __int8*)a2;
                        }
                        else
                        {
                            sub_4B8CA0(a4, (char*)(1 << v13));
                        }
                        sub_4C4770(a1, v6, *(_DWORD*)(*(_DWORD*)(v17 + 4 * v6[297] + 4) + 4 * a6));
                        if (v15)
                            v31 = 1;
                        v8 = a3;
                    }
                }
            }
        }
        ++v13;
        ++v29;
    } while (v13 < 26);
    if (a3 & 2 && !v30)
    {
        v19 = 0;
        while (!((1 << v19) & 2))
        {
            if (++v19 >= 26)
                goto LABEL_55;
        }
        v20 = *(_DWORD*)(a5 + 4 * v19 + 52);
        if (v20)
        {
            if (v28)
            {
                for (k = 1; k < 7; ++k)
                    sub_4341D0(k, v27);
                v6 = (unsigned __int8*)a2;
            }
            else
            {
                sub_4B8CA0(a4, (char*)2);
            }
            sub_4C4770(a1, v6, *(_DWORD*)(*(_DWORD*)(v20 + 4 * v6[297] + 4) + 4 * a6));
            v8 = a3;
        }
    }
LABEL_55:
    LOWORD(v22) = v31;
    if (!v31 && v8 & 0x3000000)
    {
        v23 = 0;
        v22 = (v8 & 0x1000000) != 0 ? 0x1000000 : 0x2000000;
        while (!((1 << v23) & v22))
        {
            if (++v23 >= 26)
                return v22;
        }
        v24 = *(_DWORD*)(a5 + 4 * v23 + 52);
        if (v24)
        {
            if (v28)
            {
                for (l = 1; l < 7; ++l)
                    sub_4341D0(l, v27);
                v6 = (unsigned __int8*)a2;
            }
            else
            {
                sub_4B8CA0(a4, (char*)v22);
            }
            LOWORD(v22) = sub_4C4770(a1, v6, *(_DWORD*)(*(_DWORD*)(v24 + 4 * v6[297] + 4) + 4 * a6));
        }
    }
    return v22;
}

//----- (004B8CA0) --------------------------------------------------------
_DWORD* __cdecl sub_4B8CA0(_DWORD* a1, char* a2)
{
    _DWORD* result; // eax
    int v3; // ebx
    int v4; // eax
    int v5; // edx
    int v6; // ecx
    _DWORD* v7; // ebp
    int v8; // edi
    _BYTE* v9; // esi
    _DWORD* v10; // ecx
    int v11; // eax
    int* v12; // edi
    int v13; // ebx
    _DWORD** v14; // esi
    int v15; // [esp-Ch] [ebp-14h]

    result = a1;
    v3 = 0;
    while ((char*)* result != a2)
    {
        ++v3;
        result += 6;
        if (v3 >= 26)
            return result;
    }
    v4 = sub_415CD0(a2);
    result = sub_413270(v4);
    v7 = result;
    if (result)
    {
        v8 = 1;
        v9 = result + 4;
        do
        {
            LOBYTE(result) = v9[1];
            LOBYTE(v6) = *v9;
            LOBYTE(v5) = *(v9 - 1);
            sub_4340A0(v8++, v5, v6, (int)result);
            v9 += 3;
        } while (v8 < 7);
        v10 = a1;
        v11 = 3 * v3;
        v12 = v7 + 9;
        v13 = 4;
        v14 = (_DWORD * *)& a1[2 * v11 + 1];
        do
        {
            result = *v14;
            if (*v14)
            {
                LOBYTE(v5) = *((_BYTE*)result + 26);
                LOBYTE(v10) = *((_BYTE*)result + 25);
                v15 = v5;
                LOBYTE(v5) = *((_BYTE*)result + 24);
                sub_4340A0(*v12, v5, (int)v10, v15);
            }
            ++v14;
            ++v12;
            --v13;
        } while (v13);
    }
    return result;
}
// 4B8CE7: variable 'v5' is possibly undefined
// 4B8CE7: variable 'v6' is possibly undefined
// 4B8D20: variable 'v10' is possibly undefined

//----- (004B8D40) --------------------------------------------------------
__int16 __cdecl sub_4B8D40(int* a1, int a2, int a3, _DWORD* a4, int a5, int a6)
{
    unsigned __int8* v6; // esi
    int v7; // ebx
    int* v8; // ebp
    int v9; // eax
    int v10; // edi
    int i; // esi
    int v13; // [esp+10h] [ebp-8h]
    BOOL v14; // [esp+14h] [ebp-4h]

    v6 = (unsigned __int8*)a2;
    v14 = sub_4356C0(a2, 25);
    if (byte_5D4594[2598000] & 1)
        v13 = *(_DWORD*)& byte_5D4594[2523948];
    else
        v13 = *(_DWORD*)& byte_5D4594[2650684];
    v7 = 1;
    v8 = (int*)(a5 + 160);
    do
    {
        v9 = 1 << v7;
        if ((1 << v7) & a3)
        {
            v10 = *v8;
            if (*v8)
            {
                if (v14)
                {
                    for (i = 1; i < 7; ++i)
                        sub_4341D0(i, v13);
                    v6 = (unsigned __int8*)a2;
                }
                else
                {
                    sub_4B8E10(a4, (char*)(1 << v7));
                }
                LOWORD(v9) = sub_4C4770(a1, v6, *(_DWORD*)(*(_DWORD*)(v10 + 4 * v6[297] + 4) + 4 * a6));
            }
        }
        ++v7;
        ++v8;
    } while (v7 < 27);
    return v9;
}

//----- (004B8E10) --------------------------------------------------------
_DWORD* __cdecl sub_4B8E10(_DWORD* a1, char* a2)
{
    _DWORD* result; // eax
    int v3; // ebx
    int v4; // eax
    int v5; // edx
    int v6; // ecx
    _DWORD* v7; // ebp
    int v8; // edi
    _BYTE* v9; // esi
    _DWORD* v10; // ecx
    int v11; // eax
    int* v12; // edi
    int v13; // ebx
    _DWORD** v14; // esi
    int v15; // [esp-Ch] [ebp-14h]

    result = a1;
    v3 = 0;
    while ((char*)* result != a2)
    {
        ++v3;
        result += 6;
        if (v3 >= 27)
            return result;
    }
    v4 = sub_415840(a2);
    result = sub_413250(v4);
    v7 = result;
    if (result)
    {
        v8 = 1;
        v9 = result + 4;
        do
        {
            LOBYTE(result) = v9[1];
            LOBYTE(v6) = *v9;
            LOBYTE(v5) = *(v9 - 1);
            sub_4340A0(v8++, v5, v6, (int)result);
            v9 += 3;
        } while (v8 < 7);
        v10 = a1;
        v11 = 3 * v3;
        v12 = v7 + 9;
        v13 = 4;
        v14 = (_DWORD * *)& a1[2 * v11 + 1];
        do
        {
            result = *v14;
            if (*v14)
            {
                LOBYTE(v5) = *((_BYTE*)result + 26);
                LOBYTE(v10) = *((_BYTE*)result + 25);
                v15 = v5;
                LOBYTE(v5) = *((_BYTE*)result + 24);
                sub_4340A0(*v12, v5, (int)v10, v15);
            }
            ++v14;
            ++v12;
            --v13;
        } while (v13);
    }
    return result;
}
// 4B8E57: variable 'v5' is possibly undefined
// 4B8E57: variable 'v6' is possibly undefined
// 4B8E90: variable 'v10' is possibly undefined

//----- (004B8EB0) --------------------------------------------------------
void __cdecl sub_4B8EB0(_DWORD* a1, int a2, unsigned __int16 a3, char a4)
{
    int v4; // esi
    int v5; // esi
    int v6; // edi
    float v7; // [esp+0h] [ebp-14h]

    if (a2)
    {
        v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
        v7 = *(float*)(a2 + 48) + *(float*)(a2 + 48);
        v5 = sub_419A70(v7) + v4;
        v6 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 104) - a1[5] - 48;
        sub_434460(*(int*)& byte_5D4594[2650656]);
        sub_49CE30(v5, v6, 2, 48);
        if (a4)
            sub_434460(*(int*)& byte_5D4594[2618904]);
        else
            sub_434460(*(int*)& byte_5D4594[2650644]);
        sub_49CE30(v5, v6 - 48 * a3 / 100 + 48, 2, 48 * a3 / 100);
        if (a4)
            sub_434460(*(int*)& byte_5D4594[2650688]);
        else
            sub_434460(*(int*)& byte_5D4594[2598268]);
        sub_49CC70(v5 - 1, v6 - 1, 4, 50);
    }
}

//----- (004B8FA0) --------------------------------------------------------
int __cdecl sub_4B8FA0(int a1, int* a2, int* a3)
{
    int v3; // esi
    int v4; // eax
    bool v5; // zf
    int v6; // esi
    int v8; // eax
    int v9; // ecx

    v3 = *(_DWORD*)(a1 + 304);
    if (*(_DWORD*)(a1 + 276) || !sub_48D830(a1))
    {
        if (*(_DWORD*)(a1 + 276) != 4 || (v5 = !sub_4356C0(a1, 31), v4 = 53, v5))
            v4 = *(_DWORD*)(a1 + 276);
    }
    else
    {
        v4 = 19;
    }
    v5 = *(_WORD*)(v3 + 264 * v4 + 44) == 0;
    v6 = v3 + 264 * v4 + 4;
    if (v5)
        return 0;
    v8 = sub_4BC5D0((_DWORD*)a1, v6);
    if (v8 < 0)
        return 0;
    v9 = *(__int16*)(v6 + 40);
    if (v8 >= v9)
        v8 = v9 - 1;
    if (a2)
        * a2 = v6;
    if (a3)
        * a3 = v8;
    return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v6 + 48) + 4 * *(unsigned __int8*)(a1 + 297) + 4) + 4 * v8);
}

//----- (004B9050) --------------------------------------------------------
int __cdecl nox_thing_npc_draw(int* a1, int a2)
{
    int v2; // eax
    int v4; // edi
    int* v5; // ebp
    int v6; // eax
    int v7; // esi
    int v8; // eax
    int v9; // esi
    int v10; // eax
    int v11; // esi
    int v12; // esi
    int* v13; // ebx
    int v14; // eax
    int v15; // eax
    int* v16; // ebx
    int v17; // esi
    int v18; // eax
    int v19; // ebp
    int v20; // ebx
    int* v21; // esi
    char v22; // al
    int v23; // eax
    void(__cdecl * *v24)(char*, int); // ebx
    char* v25; // eax
    int v26; // eax
    void(__cdecl * *v27)(char*, int); // ebx
    char* v28; // eax
    int i; // esi
    int v30; // [esp-4h] [ebp-24h]
    int v31; // [esp-4h] [ebp-24h]
    int v32; // [esp-4h] [ebp-24h]
    int* v33; // [esp+10h] [ebp-10h]
    int v34; // [esp+14h] [ebp-Ch]
    int v35; // [esp+18h] [ebp-8h]
    int v36; // [esp+1Ch] [ebp-4h]

    if (sub_40A5C0(0x200000))
    {
        v2 = *(_DWORD*)(sub_44D330((CHAR*)& byte_587000[177440]) + 92) + 4;
        if (*(_WORD*)(v2 + 40))
        {
            sub_4C4770(
                a1,
                (unsigned __int8*)a2,
                **(_DWORD * *)(*(_DWORD*)(v2 + 48) + 4 * *(unsigned __int8*)(a2 + 297) + 4));
            return 1;
        }
    }
    else
    {
        v4 = a2;
        v30 = *(_DWORD*)(a2 + 128);
        v36 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 304);
        v5 = (int*)nox_npc_by_id(v30);
        v33 = v5;
        if (v5)
        {
            if (sub_4356C0(v4, 23))
            {
                if (byte_5D4594[2598000] & 1)
                {
                    v6 = 0;
                    do
                    {
                        v7 = v6 + 1;
                        sub_4341D0(v6 + 1, *(int*)& byte_5D4594[2523948]);
                        v6 = v7;
                    } while (v7 < 6);
                }
                else
                {
                    v8 = 0;
                    do
                    {
                        v9 = v8 + 1;
                        sub_4341D0(v8 + 1, *(int*)& byte_5D4594[2650684]);
                        v8 = v9;
                    } while (v9 < 6);
                }
            }
            else if (sub_4356C0(v4, 25))
            {
                v10 = 0;
                do
                {
                    v11 = v10 + 1;
                    sub_4341D0(v10 + 1, *(int*)& byte_5D4594[2650684]);
                    v10 = v11;
                } while (v11 < 6);
            }
            else if (v5[328] == 1)
            {
                v12 = 0;
                v13 = v5 + 2;
                do
                {
                    sub_434480(*v13, (int)& v35, (int)& a2, (int)& v34);
                    if ((unsigned __int8)a2 >= 0x9Bu)
                        LOBYTE(a2) = -1;
                    else
                        LOBYTE(a2) = a2 + 100;
                    ++v12;
                    v14 = sub_4344A0(v35, a2, v34);
                    sub_4341D0(v12, v14);
                    ++v13;
                } while (v12 < 6);
            }
            else
            {
                v15 = 0;
                v16 = v5 + 2;
                do
                {
                    v17 = v15 + 1;
                    sub_4341D0(v15 + 1, *v16);
                    v15 = v17;
                    ++v16;
                } while (v17 < 6);
            }
            v18 = sub_49A4B0((_DWORD*)v4, v5[326], v5[327]);
            v19 = v36 + 264 * v18 + 4;
            if (*(_WORD*)(v36 + 264 * v18 + 44))
            {
                v20 = sub_4BC5D0((_DWORD*)v4, v36 + 264 * v18 + 4);
                if (v20 < 0)
                    return 0;
                v21 = a1;
                sub_4C4770(
                    a1,
                    (unsigned __int8*)v4,
                    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v19 + 48) + 4 * *(unsigned __int8*)(v4 + 297) + 4) + 4 * v20));
                v22 = *(_BYTE*)(v4 + 297);
                if (v22 != 1 && v22 && v22 != 2 && v22 != 3 && v22 != 6 || *(_DWORD*)(v4 + 276) == 37)
                {
                    sub_4B8960(v21, v4, v33[327], v33 + 170, v19, v20);
                    sub_4B8D40(v21, v4, v33[326], v33 + 8, v19, v20);
                }
                else
                {
                    sub_4B8D40(v21, v4, v33[326], v33 + 8, v19, v20);
                    sub_4B8960(v21, v4, v33[327], v33 + 170, v19, v20);
                }
                if (sub_4356C0(v4, 16))
                {
                    if (!*(_DWORD*)& byte_5D4594[1313796])
                    {
                        v23 = sub_44CFC0((CHAR*)& byte_587000[177452]);
                        *(_DWORD*)& byte_5D4594[1313796] = sub_45A240(v23);
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313796] + 120) |= 0x1000000u;
                    }
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313796] + 12) = *v21 + *(_DWORD*)(v4 + 12) - v21[4];
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313796] + 16) = v21[1] - v21[5] + *(_DWORD*)(v4 + 16) - 50;
                    v31 = *(_DWORD*)& byte_5D4594[1313796];
                    v24 = (void(__cdecl * *)(char*, int))(*(_DWORD*)& byte_5D4594[1313796] + 300);
                    v25 = sub_437250();
                    (*v24)(v25, v31);
                }
                if (sub_4356C0(v4, 30))
                {
                    if (!*(_DWORD*)& byte_5D4594[1313800])
                    {
                        v26 = sub_44CFC0((CHAR*)& byte_587000[177468]);
                        *(_DWORD*)& byte_5D4594[1313800] = sub_45A240(v26);
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313800] + 120) |= 0x1000000u;
                    }
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313800] + 12) = *v21 + *(_DWORD*)(v4 + 12) - v21[4];
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1313800] + 16) = v21[1] - v21[5] + *(_DWORD*)(v4 + 16) - 50;
                    v32 = *(_DWORD*)& byte_5D4594[1313800];
                    v27 = (void(__cdecl * *)(char*, int))(*(_DWORD*)& byte_5D4594[1313800] + 300);
                    v28 = sub_437250();
                    (*v27)(v28, v32);
                }
                if (sub_4951F0(*(_DWORD*)(v4 + 128)))
                {
                    v33 = 0;
                    a1 = 0;
                    LOBYTE(a2) = 0;
                    sub_495180(*(_DWORD*)(v4 + 128), &v33, &a1, &a2);
                    sub_4BC080(v21, v4, (unsigned __int16)v33, (unsigned __int16)a1, a2);
                }
                for (i = 0; i < 6; ++i)
                    sub_4341D0(i, *(int*)& byte_5D4594[2523948]);
            }
        }
    }
    return 1;
}

//----- (004B9470) --------------------------------------------------------
int __cdecl sub_4B9470(const char** a1)
{
    const char* v1; // esi
    int v2; // edx
    unsigned __int8* v3; // edi

    if (!a1)
        return 0;
    v1 = *(const char**)& byte_587000[177488];
    v2 = 0;
    if (!*(_DWORD*)& byte_587000[177488])
        return 0;
    v3 = &byte_587000[177488];
    while (strcmp(*a1, v1))
    {
        v1 = (const char*) * ((_DWORD*)v3 + 2);
        v3 += 8;
        ++v2;
        if (!v1)
            return 0;
    }
    return *(_DWORD*)& byte_587000[8 * v2 + 177492];
}

//----- (004B94E0) --------------------------------------------------------
int __cdecl sub_4B94E0(int a1)
{
    int result; // eax

    if (*(_DWORD*)(a1 + 112) & 0x10000000)
        result = sub_4B9470(*(const char***)(a1 + 436));
    else
        result = 0;
    return result;
}

//----- (004B9500) --------------------------------------------------------
int __cdecl nox_thing_flag_draw(int* a1, int a2)
{
    int v2; // ebx
    int v3; // edi
    int v4; // esi
    int v5; // eax
    unsigned __int16* v6; // ebx

    v2 = a2;
    nox_thing_weapon_animate_draw(a1, a2);
    if (sub_40A5C0(128))
    {
        if (*(_DWORD*)(v2 + 120) & 0x1000000)
        {
            v3 = *a1 + *(_DWORD*)(v2 + 12) - a1[4];
            v4 = *(_DWORD*)(v2 + 16)
                + a1[1]
                - *(__int16*)(v2 + 104)
                - (unsigned __int64)(__int64) * (float*)(v2 + 100)
                - a1[5];
            v5 = sub_4B94E0(v2);
            v6 = (unsigned __int16*)sub_418A80(v5);
            if (v6)
            {
                sub_434390(*(int*)& byte_5D4594[2618904]);
                sub_43F840(0, v6, &a2, 0, 0);
                sub_43F6E0(0, (__int16*)v6, a2 / -2 + v3, v4);
            }
        }
    }
    return 1;
}

//----- (004B95B0) --------------------------------------------------------
int __cdecl nox_thing_base_draw(int* a1, int a2)
{
    nox_thing_weapon_draw(a1, a2);
    return 1;
}

//----- (004B95D0) --------------------------------------------------------
_DWORD* __cdecl sub_4B95D0(int a1)
{
    _DWORD* result; // eax
    int v2; // edx
    int v3; // ecx
    _DWORD* v4; // ebx
    int v5; // edi
    _BYTE* v6; // esi
    int* v7; // edi
    _DWORD** v8; // esi
    int v9; // ebx

    result = sub_413250(*(_DWORD*)(a1 + 108));
    v4 = result;
    if (result)
    {
        v5 = 1;
        v6 = result + 4;
        do
        {
            LOBYTE(v3) = v6[1];
            LOBYTE(v2) = *v6;
            LOBYTE(result) = *(v6 - 1);
            sub_4340A0(v5++, (int)result, v2, v3);
            v6 += 3;
        } while (v5 < 7);
        v7 = v4 + 9;
        v8 = (_DWORD * *)(a1 + 432);
        v9 = 4;
        do
        {
            result = *v8;
            if (*v8)
            {
                LOBYTE(v3) = *((_BYTE*)result + 26);
                LOBYTE(v2) = *((_BYTE*)result + 25);
                LOBYTE(result) = *((_BYTE*)result + 24);
                sub_4340A0(*v7, (int)result, v2, v3);
            }
            ++v8;
            ++v7;
            --v9;
        } while (v9);
    }
    return result;
}
// 4B9604: variable 'v2' is possibly undefined
// 4B9604: variable 'v3' is possibly undefined

//----- (004B9650) --------------------------------------------------------
_DWORD* __cdecl sub_4B9650(int a1)
{
    _DWORD* result; // eax
    int v2; // edx
    int v3; // ecx
    int v4; // edi
    _BYTE* v5; // esi

    result = sub_413250(a1);
    if (result)
    {
        v4 = 1;
        v5 = result + 4;
        do
        {
            LOBYTE(v3) = v5[1];
            LOBYTE(v2) = *v5;
            LOBYTE(result) = *(v5 - 1);
            sub_4340A0(v4++, (int)result, v2, v3);
            v5 += 3;
        } while (v4 < 7);
    }
    return result;
}
// 4B9677: variable 'v2' is possibly undefined
// 4B9677: variable 'v3' is possibly undefined

//----- (004B9690) --------------------------------------------------------
int __cdecl nox_thing_weapon_draw(int* a1, int a2)
{
    sub_4B95D0(a2);
    return nox_thing_static_draw(a1, a2);
}

//----- (004B96B0) --------------------------------------------------------
int __cdecl nox_thing_weapon_animate_draw(int* a1, int a2)
{
    sub_4B95D0(a2);
    return nox_thing_animate_draw(a1, a2);
}

//----- (004B96D0) --------------------------------------------------------
int __cdecl nox_thing_armor_draw(int* a1, int a2)
{
    sub_4B96F0(a2);
    return nox_thing_static_draw(a1, a2);
}

//----- (004B96F0) --------------------------------------------------------
_DWORD* __cdecl sub_4B96F0(int a1)
{
    _DWORD* result; // eax
    int v2; // edx
    int v3; // ecx
    _DWORD* v4; // ebx
    int v5; // edi
    _BYTE* v6; // esi
    int* v7; // edi
    _DWORD** v8; // esi
    int v9; // ebx

    result = sub_413270(*(_DWORD*)(a1 + 108));
    v4 = result;
    if (result)
    {
        v5 = 1;
        v6 = result + 4;
        do
        {
            LOBYTE(v3) = v6[1];
            LOBYTE(v2) = *v6;
            LOBYTE(result) = *(v6 - 1);
            sub_4340A0(v5++, (int)result, v2, v3);
            v6 += 3;
        } while (v5 < 7);
        v7 = v4 + 9;
        v8 = (_DWORD * *)(a1 + 432);
        v9 = 4;
        do
        {
            result = *v8;
            if (*v8)
            {
                LOBYTE(v3) = *((_BYTE*)result + 26);
                LOBYTE(v2) = *((_BYTE*)result + 25);
                LOBYTE(result) = *((_BYTE*)result + 24);
                sub_4340A0(*v7, (int)result, v2, v3);
            }
            ++v8;
            ++v7;
            --v9;
        } while (v9);
    }
    return result;
}
// 4B9724: variable 'v2' is possibly undefined
// 4B9724: variable 'v3' is possibly undefined

//----- (004B9770) --------------------------------------------------------
int __cdecl nox_thing_armor_animate_draw(int* a1, int a2)
{
    sub_4B96F0(a2);
    return nox_thing_animate_draw(a1, a2);
}

//----- (004B9790) --------------------------------------------------------
int __cdecl nox_thing_player_waypoint_draw(int a1, int a2)
{
    int v2; // esi
    int v3; // ebp
    int v4; // ebx
    int v5; // edi
    int v7; // [esp+14h] [ebp+4h]

    v2 = *(_DWORD*)& byte_5D4594[2650644];
    sub_4C32A0(
        *(_DWORD*)(a2 + 12) - *(_DWORD*)(a1 + 16),
        *(_DWORD*)(a2 + 16) - *(_DWORD*)(a1 + 20),
        10,
        *(int*)& byte_5D4594[2650644]);
    v3 = *(_DWORD*)(a2 + 16) - *(_DWORD*)(a1 + 20);
    v4 = *(_DWORD*)(a2 + 12) - *(_DWORD*)(a1 + 16);
    v5 = (unsigned __int8)(2 * byte_5D4594[2598000]);
    sub_434560(1);
    sub_434460(v2);
    v7 = 5;
    do
    {
        sub_49F500(
            v4 + 10 * *(int*)& byte_587000[8 * v5 + 192088] / 16,
            v3 + 10 * *(int*)& byte_587000[8 * v5 + 192092] / 16);
        sub_49F500(
            v4 + 10 * *(int*)& byte_587000[8 * ((v5 + 102) % 256) + 192088] / 16,
            v3 + 10 * *(int*)& byte_587000[8 * ((v5 + 102) % 256) + 192092] / 16);
        sub_49E4B0();
        v5 = (v5 + 102) % 256;
        --v7;
    } while (v7);
    sub_434560(0);
    return 1;
}

//----- (004B98A0) --------------------------------------------------------
int __cdecl nox_thing_magic_draw(int* a1, int a2)
{
    int v2; // esi
    int v3; // edi
    int v4; // ecx
    int v5; // eax
    int v6; // eax
    int v7; // edi
    float v9; // [esp+0h] [ebp-1Ch]
    int2 v10; // [esp+14h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1313804])
    {
        *(_DWORD*)& byte_5D4594[1313808] = sub_4344A0(0, 200, 255);
        *(_DWORD*)& byte_5D4594[1313812] = sub_4344A0(255, 255, 50);
        *(_DWORD*)& byte_5D4594[1313804] = 1;
    }
    v2 = *a1;
    v3 = a1[1];
    v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v5 = *(_DWORD*)(a2 + 16) - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v10.field_0 = v4;
    v6 = v3 + v5;
    v10.field_4 = v6;
    if (v4 - 10 >= v2 && v6 - 10 >= v3 && v4 + 10 < a1[2] && v6 + 10 < a1[3])
    {
        v7 = sub_415FF0(1, 4, "C:\\NoxPost\\src\\Client\\Draw\\magicdrw.c", 48);
        sub_4B6720(&v10, *(int*)& byte_5D4594[1313808], 2 * v7 + 1, (v7 >> 1) + 3);
        sub_434460(*(int*)& byte_5D4594[2523948]);
        sub_49CE30(v10.field_0 - (v7 >> 1), v10.field_4 - (v7 >> 1), v7, v7);
        sub_484BE0((_DWORD*)(a2 + 136), 200, 200, 255);
        v9 = sub_416090(0.0, 100.0);
        sub_484D70(a2 + 136, v9);
    }
    return 1;
}

//----- (004B99F0) --------------------------------------------------------
int __cdecl nox_thing_magic_missle_draw(int* a1, int a2)
{
    int v2; // esi
    int v3; // edi
    int v4; // ecx
    int v5; // eax
    int v6; // eax
    int v7; // edi
    float v9; // [esp+0h] [ebp-1Ch]
    int2 v10; // [esp+14h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1313804])
    {
        *(_DWORD*)& byte_5D4594[1313808] = sub_4344A0(0, 200, 255);
        *(_DWORD*)& byte_5D4594[1313812] = sub_4344A0(255, 255, 50);
        *(_DWORD*)& byte_5D4594[1313804] = 1;
    }
    v2 = *a1;
    v3 = a1[1];
    v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v5 = *(_DWORD*)(a2 + 16) - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5];
    v10.field_0 = v4;
    v6 = v3 + v5;
    v10.field_4 = v6;
    if (v4 - 10 >= v2 && v6 - 10 >= v3 && v4 + 10 < a1[2] && v6 + 10 < a1[3])
    {
        v7 = sub_415FF0(1, 4, "C:\\NoxPost\\src\\Client\\Draw\\magicdrw.c", 91);
        sub_4B6720(&v10, *(int*)& byte_5D4594[1313812], 2 * v7 + 1, (v7 >> 1) + 3);
        sub_434460(*(int*)& byte_5D4594[2523948]);
        sub_49CE30(v10.field_0 - (v7 >> 1), v10.field_4 - (v7 >> 1), v7, v7);
        sub_484BE0((_DWORD*)(a2 + 136), 255, 180, 50);
        v9 = sub_416090(0.0, 100.0);
        sub_484D70(a2 + 136, v9);
    }
    return 1;
}

//----- (004B9B40) --------------------------------------------------------
int nox_thing_drain_mana_draw()
{
    return 1;
}

//----- (004B9B50) --------------------------------------------------------
int __cdecl nox_thing_boulder_draw(int* a1, int a2)
{
    int v2; // edi
    int v3; // ecx
    int v4; // edx
    unsigned int v5; // ecx
    int v6; // ecx

    v2 = *(_DWORD*)(a2 + 304);
    if (!*(_DWORD*)(a2 + 432) && !*(_DWORD*)(a2 + 436))
    {
        *(_DWORD*)(a2 + 432) = *(_DWORD*)(a2 + 12);
        *(_DWORD*)(a2 + 436) = *(_DWORD*)(a2 + 16);
    }
    v3 = *(_DWORD*)(a2 + 12) - *(_DWORD*)(a2 + 432);
    v4 = *(_DWORD*)(a2 + 16) - *(_DWORD*)(a2 + 436);
    if (v3 * v3 + v4 * v4 >= 100)
    {
        if (v3 <= 0)
        {
            if (v4 > 0)
            {
                *(_DWORD*)(a2 + 444) = 0;
            LABEL_8:
                v5 = *(_DWORD*)(a2 + 440) + 1;
                *(_DWORD*)(a2 + 440) = v5;
                if (v5 >= 0x10)
                    * (_DWORD*)(a2 + 440) = 0;
                goto LABEL_17;
            }
            *(_DWORD*)(a2 + 444) = 16;
        }
        else
        {
            if (v4 > 0)
            {
                *(_DWORD*)(a2 + 444) = 16;
                goto LABEL_8;
            }
            *(_DWORD*)(a2 + 444) = 0;
        }
        v6 = *(_DWORD*)(a2 + 440);
        if (v6)
            * (_DWORD*)(a2 + 440) = v6 - 1;
        else
            *(_DWORD*)(a2 + 440) = 15;
    LABEL_17:
        *(_DWORD*)(a2 + 432) = *(_DWORD*)(a2 + 12);
        *(_DWORD*)(a2 + 436) = *(_DWORD*)(a2 + 16);
    }
    sub_4C4770(
        a1,
        (unsigned __int8*)a2,
        *(_DWORD*)(*(_DWORD*)(v2 + 4) + 4 * (*(_DWORD*)(a2 + 440) + *(_DWORD*)(a2 + 444))));
    return 1;
}

//----- (004B9C70) --------------------------------------------------------
int __cdecl nox_thing_glyph_draw(int* a1, _DWORD* a2)
{
    _DWORD* v2; // esi
    char v3; // cl
    int v4; // ecx
    int v5; // eax
    int v6; // eax
    int v7; // esi

    v2 = a2;
    if (!sub_40A5C0(2) || !*(_DWORD*)& byte_5D4594[2614252])
        goto LABEL_10;
    if (a2[30] & 0x40000000)
    {
        LOBYTE(a2) = -1;
    LABEL_10:
        sub_434560(1);
        sub_434580((unsigned __int8)a2);
        v7 = nox_thing_animate_draw(a1, (int)v2);
        sub_434560(0);
        sub_434600(0);
        return v7;
    }
    if (sub_4356C0(*(int*)& byte_5D4594[2614252], 21))
    {
        sub_434600(1);
        sub_433E40(*(int*)& byte_5D4594[2618904]);
        v3 = nox_backbuffer_depth >= 16 ? -1 : -128;
    LABEL_9:
        LOBYTE(a2) = v3;
        goto LABEL_10;
    }
    v4 = a2[3] - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 12);
    v5 = a2[4] - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 16);
    v6 = v4 * v4 + v5 * v5;
    if (v6 < 22500)
    {
        v3 = -56 - 200 * v6 / 22500;
        goto LABEL_9;
    }
    return 1;
}

//----- (004B9D70) --------------------------------------------------------
int __cdecl nox_thing_spider_spit_draw(_DWORD* a1, int a2)
{
    _DWORD* v2; // eax
    int v3; // edi
    int v4; // ebp
    int v5; // edx
    int v6; // ecx
    int v7; // esi
    int v8; // ebp
    int v9; // ebx
    int v10; // edi
    int v12; // [esp+14h] [ebp-Ch]
    int v13; // [esp+18h] [ebp-8h]
    int v14; // [esp+1Ch] [ebp-4h]
    int v15; // [esp+24h] [ebp+4h]
    int v16; // [esp+28h] [ebp+8h]
    int v17; // [esp+28h] [ebp+8h]

    v2 = (_DWORD*)a2;
    v3 = a1[4];
    v4 = *(__int16*)(a2 + 104);
    v16 = a1[1];
    v13 = v2[4];
    v5 = v2[3];
    v12 = v4;
    v6 = v2[8];
    v7 = v16 + v13 - a1[5] - v4;
    v14 = v2[9];
    v8 = *a1 + v6 - v3;
    v9 = v5 + *a1 - v3;
    v10 = v16 + v14 - a1[5] - v12;
    if (v5 - v6 >= 0)
        v15 = v5 - v6;
    else
        v15 = v6 - v5;
    if (v13 - v14 >= 0)
        v17 = v13 - v14;
    else
        v17 = v14 - v13;
    sub_434460(*(int*)& byte_5D4594[2650660]);
    if (v15 <= v17)
    {
        sub_49F500(v9 + 1, v7);
        sub_49F500(v8 - 1, v10);
        sub_49E4B0();
        sub_49F500(v9 - 1, v7);
        sub_49F500(v8 - 1, v10);
    }
    else
    {
        sub_49F500(v9, v7 + 1);
        sub_49F500(v8, v10 + 1);
        sub_49E4B0();
        sub_49F500(v9, v7 + 1);
        sub_49F500(v8, v10 - 1);
    }
    sub_49E4B0();
    sub_49CE30(v9 - 1, v7 - 1, 4, 4);
    sub_434460(*(int*)& byte_5D4594[2523948]);
    sub_49F500(v9, v7);
    sub_49F500(v8, v10);
    sub_49E4B0();
    sub_49CE30(v9, v7, 2, 2);
    return 1;
}

//----- (004B9ED0) --------------------------------------------------------
int __cdecl nox_thing_black_powder_draw(_DWORD* a1, int a2)
{
    int v2; // esi
    int v3; // edi

    v2 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v3 = *(_DWORD*)(a2 + 16) + a1[1] - a1[5];
    sub_434460(*(int*)& byte_5D4594[2650660]);
    sub_49CE30(v2 - 1, v3 - 1, 3, 3);
    sub_49CE30(v2 - 5, v3, 1, 1);
    sub_49CE30(v2, v3 + 7, 1, 1);
    sub_49CE30(v2 + 8, v3 - 2, 1, 1);
    return 1;
}

//----- (004B9F50) --------------------------------------------------------
int __cdecl nox_thing_vortex_draw(int* a1, int a2)
{
    int v2; // ecx
    int v3; // edi
    int v4; // eax
    bool v5; // cc
    char v6; // al
    int v7; // ecx
    int v8; // edi
    int v9; // eax
    int result; // eax
    float v11; // [esp+0h] [ebp-28h]
    int2 xLeft; // [esp+10h] [ebp-18h]
    int2 a2a; // [esp+18h] [ebp-10h]
    int2 a3; // [esp+20h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1313820])
    {
        *(_DWORD*)& byte_5D4594[1313816] = sub_4344A0(170, 170, 170);
        *(_DWORD*)& byte_5D4594[1313820] = 1;
    }
    v2 = 8 * *(unsigned __int8*)(a2 + 448);
    v3 = *(unsigned __int8*)(a2 + 450);
    a2a.field_0 = *(_DWORD*)(a2 + 440) + v3 * *(int*)& byte_587000[v2 + 192088] / 16;
    a2a.field_4 = *(_DWORD*)(a2 + 444) + v3 * *(int*)& byte_587000[v2 + 192092] / 16;
    sub_4739E0(a1, &a2a, &xLeft);
    v4 = xLeft.field_4 - *(__int16*)(a2 + 104);
    v5 = xLeft.field_0 <= *a1;
    xLeft.field_4 -= *(__int16*)(a2 + 104);
    if (v5 || xLeft.field_0 >= a1[2] || v4 <= a1[1] || v4 >= a1[3])
        goto LABEL_22;
    if (a2a.field_4 >= *(int*)(a2 + 444))
    {
        sub_4B6720(&xLeft, *(_DWORD*)(a2 + 432), 3, 5);
        sub_434460(*(_DWORD*)(a2 + 436));
        sub_499B70(xLeft.field_0, xLeft.field_4, 3);
    }
    else
    {
        sub_4B6720(&xLeft, *(int*)& byte_5D4594[1313816], 2, 4);
        sub_434460(*(int*)& byte_5D4594[1313816]);
        sub_499B70(xLeft.field_0, xLeft.field_4, 2);
    }
    sub_49F500(xLeft.field_0, xLeft.field_4);
    v6 = *(_BYTE*)(a2 + 449);
    v7 = *(unsigned __int8*)(a2 + 448) - 2 * v6;
    if (v6 > 0)
    {
        v7 += v7 < 0 ? 0x100 : 0;
    }
    else if (v7 >= 256)
    {
        v7 -= 256;
    }
    v8 = *(unsigned __int8*)(a2 + 450);
    a2a.field_0 = *(_DWORD*)(a2 + 440) + v8 * *(_DWORD*)& byte_587000[8 * v7 + 192088] / 16;
    a2a.field_4 = *(_DWORD*)(a2 + 444) + v8 * *(_DWORD*)& byte_587000[8 * v7 + 192092] / 16;
    sub_4739E0(a1, &a2a, &xLeft);
    xLeft.field_4 -= *(__int16*)(a2 + 104);
    sub_49F500(xLeft.field_0, xLeft.field_4);
    if (a2a.field_4 >= *(int*)(a2 + 444))
        sub_434460(*(_DWORD*)(a2 + 436));
    else
        sub_434460(*(int*)& byte_5D4594[1313816]);
    sub_49E4B0();
    *(_BYTE*)(a2 + 448) += *(_BYTE*)(a2 + 449);
    *(_WORD*)(a2 + 104) += *(unsigned __int8*)(a2 + 451);
    sub_4739E0(a1, (int2*)(a2 + 12), &a3);
    v11 = (double) * (__int16*)(a2 + 104) * 0.0024999999 * 50.0;
    v9 = sub_419A70(v11);
    if (50 - v9 <= 0)
    {
    LABEL_22:
        sub_45A4E0(a2);
        result = 0;
    }
    else
    {
        *(_BYTE*)(a2 + 450) = 50 - v9;
        result = 1;
    }
    return result;
}

//----- (004BA230) --------------------------------------------------------
int __cdecl sub_4BA230(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // ebx
    unsigned __int8* v6; // eax
    int v7; // ecx
    int i; // ebp
    int result; // eax
    int v10; // edi
    int v11; // esi
    int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // eax
    int j; // edi
    unsigned __int8* v17; // esi
    int v18; // eax
    int v19; // edx
    int v20; // eax
    int v21; // ecx
    int v22; // eax
    int v23; // edx
    double v24; // st7
    int v25; // eax
    int v26; // eax
    int v27; // edx
    float v28; // [esp+0h] [ebp-30h]
    float v29; // [esp+0h] [ebp-30h]
    float v30; // [esp+0h] [ebp-30h]
    float v31; // [esp+0h] [ebp-30h]
    int2 a4a; // [esp+10h] [ebp-20h]
    int2 a3a; // [esp+18h] [ebp-18h]
    int2 a2a; // [esp+20h] [ebp-10h]
    int2 a1a; // [esp+28h] [ebp-8h]
    int v36; // [esp+34h] [ebp+4h]
    float v37; // [esp+34h] [ebp+4h]

    v5 = 0;
    if (!*(_DWORD*)& byte_5D4594[1316404])
    {
        *(_DWORD*)& byte_5D4594[1313828] = sub_4344A0(40, 180, 255);
        *(_DWORD*)& byte_5D4594[1313832] = sub_4344A0(255, 255, 255);
        *(_DWORD*)& byte_5D4594[1313836] = sub_4344A0(40, 180, 255);
        *(_DWORD*)& byte_5D4594[1313844] = 8;
        *(_DWORD*)& byte_5D4594[1313852] = 8;
        *(_DWORD*)& byte_5D4594[1313856] = 0;
        *(_DWORD*)& byte_5D4594[1313860] = 0;
        byte_5D4594[1313840] = 16;
        byte_5D4594[1313842] = 16;
        *(_DWORD*)& byte_5D4594[1313848] = 12;
        byte_5D4594[1313841] = 24;
        v6 = &byte_5D4594[1313900];
        *(_DWORD*)& byte_5D4594[1313864] = 0;
        do
        {
            v7 = 30;
            do
            {
                *((_DWORD*)v6 - 1) = 0;
                *(_DWORD*)v6 = 0;
                *((_DWORD*)v6 + 1) = 0;
                *((_DWORD*)v6 + 2) = 0;
                *((_DWORD*)v6 - 2) = 0;
                v6 += 28;
                --v7;
            } while (v7);
        } while ((int)v6 < (int)& byte_5D4594[1316420]);
        *(_DWORD*)& byte_5D4594[1316404] = 1;
    }
    sub_4BA670(a1, a2, a3, a4, a5);
    for (i = 0; i < 3; ++i)
    {
        result = *(_DWORD*)& byte_5D4594[1316408];
        v10 = 0;
        if (*(int*)& byte_5D4594[1316408] + 1 <= 0)
            continue;
        do
        {
            v11 = 28 * (30 * i + v10);
            v12 = *(_DWORD*)& byte_5D4594[v11 + 1313900] + *(_DWORD*)& byte_5D4594[v11 + 1313896];
            *(_DWORD*)& byte_5D4594[v11 + 1313896] = v12;
            if (v12 < 256)
            {
                if (v12 >= 0)
                    goto LABEL_14;
                v13 = v12 + 255;
            }
            else
            {
                v13 = v12 - 256;
            }
            *(_DWORD*)& byte_5D4594[v11 + 1313896] = v13;
        LABEL_14:
            if (!v10)
                * (_DWORD*)& byte_5D4594[840 * i + 1313896] = a1;
            v14 = *(_DWORD*)& byte_5D4594[v11 + 1313904] + *(_DWORD*)& byte_5D4594[v11 + 1313900];
            *(_DWORD*)& byte_5D4594[v11 + 1313900] = v14;
            if (i == 1)
            {
                if (v14 <= 10)
                {
                    if (v14 < -10)
                        * (_DWORD*)& byte_5D4594[28 * v10 + 1314740] = -10;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[28 * v10 + 1314740] = 10;
                }
            }
            else if (v14 <= 25)
            {
                if (v14 < -25)
                    * (_DWORD*)& byte_5D4594[v11 + 1313900] = -25;
            }
            else
            {
                *(_DWORD*)& byte_5D4594[v11 + 1313900] = 25;
            }
            v15 = *(_DWORD*)& byte_5D4594[v11 + 1313908] - 1;
            *(_DWORD*)& byte_5D4594[v11 + 1313908] = v15;
            if (v15 <= 0)
            {
                *(_DWORD*)& byte_5D4594[v11 + 1313908] = sub_415FF0(10, 90, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 378);
                *(_DWORD*)& byte_5D4594[v11 + 1313904] = sub_415FF0(4, 8, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 382);
                if (sub_415FF0(0, 1, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 385))
                    * (_DWORD*)& byte_5D4594[v11 + 1313904] = -*(_DWORD*)& byte_5D4594[v11 + 1313904];
                if (i == 1)
                {
                    *(_DWORD*)& byte_5D4594[28 * v10 + 1314732] = sub_415FF0(40, 50, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 392);
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[v11 + 1313892] = sub_415FF0(80, 110, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 395);
                    if (v10 < 4 && sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 402) > 90)
                    {
                        *(_DWORD*)& byte_5D4594[v11 + 1313892] = sub_415FF0(150, 200, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 407);
                        *(_DWORD*)& byte_5D4594[v11 + 1313908] *= 2;
                    }
                }
            }
            result = *(_DWORD*)& byte_5D4594[1316408];
            ++v10;
        } while (v10 < *(int*)& byte_5D4594[1316408] + 1);
        v5 = 0;
    }
    for (j = 0; j < 3; ++j)
    {
        if (result > 0)
        {
            v17 = &byte_5D4594[840 * j + 1313896];
            do
            {
                v36 = *((_DWORD*)v17 - 1);
                v18 = *(_DWORD*)v17;
                v19 = *((_DWORD*)v17 - 2);
                a1a.field_0 = *((_DWORD*)v17 - 3);
                a1a.field_4 = v19;
                v37 = (double)v36;
                v28 = v37 * *(float*)& byte_587000[8 * v18 + 194136];
                v20 = sub_419A70(v28);
                v21 = *(_DWORD*)v17;
                a3a.field_0 = v20;
                v29 = v37 * *(float*)& byte_587000[8 * v21 + 194140];
                v22 = sub_419A70(v29);
                v23 = *((_DWORD*)v17 + 4);
                v24 = v37 * *(float*)& byte_587000[8 * *((_DWORD*)v17 + 7) + 194136];
                a3a.field_4 = v22;
                v25 = *((_DWORD*)v17 + 5);
                a2a.field_0 = v23;
                a2a.field_4 = v25;
                v30 = v24;
                v26 = sub_419A70(v30);
                v27 = *((_DWORD*)v17 + 7);
                a4a.field_0 = v26;
                v31 = v37 * *(float*)& byte_587000[8 * v27 + 194140];
                a4a.field_4 = sub_419A70(v31);
                sub_4BE800(*(_DWORD*)& byte_5D4594[4 * j + 1313828]);
                sub_4BE810(
                    1,
                    *(_DWORD*)& byte_5D4594[4 * j + 1313828],
                    *(_DWORD*)& byte_5D4594[4 * j + 1313844],
                    byte_5D4594[j + 1313840]);
                if (j == 1)
                    sub_4BEAD0(&a1a, &a2a, &a3a, &a4a, 8, 1);
                else
                    sub_4BEAD0(&a1a, &a2a, &a3a, &a4a, 8, 0);
                result = *(_DWORD*)& byte_5D4594[1316408];
                ++v5;
                v17 += 28;
            } while (v5 < *(int*)& byte_5D4594[1316408]);
            v5 = 0;
        }
    }
    return result;
}

//----- (004BA670) --------------------------------------------------------
void __cdecl sub_4BA670(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // ebx
    int v6; // edi
    int v7; // esi
    int v8; // eax
    double v9; // st7
    double v10; // st6
    double v11; // st5
    double v12; // st4
    double v13; // st5
    double v14; // st5
    double v15; // rt0
    int v16; // eax
    int v17; // ecx
    int v18; // esi
    int v19; // edx
    unsigned __int8* v20; // eax
    float v21; // [esp-Ch] [ebp-44h]
    int2 a4a; // [esp+18h] [ebp-20h]
    int2 a3a; // [esp+20h] [ebp-18h]
    int2 a2a; // [esp+28h] [ebp-10h]
    int2 a1a; // [esp+30h] [ebp-8h]
    float v26; // [esp+40h] [ebp+8h]

    v5 = a5;
    v6 = a4 - a2;
    v7 = a5 - a3;
    v8 = sub_48C6B0(a4 - a2, a5 - a3);
    *(_DWORD*)& byte_5D4594[1316408] = v8 / 40 + 1;
    if (v8 / 40 + 2 >= 30)
        * (_DWORD*)& byte_5D4594[1316408] = 28;
    a1a.field_0 = a2;
    v9 = *(float*)& byte_587000[8 * a1 + 194136];
    v10 = *(float*)& byte_587000[8 * a1 + 194140];
    v11 = (double)(a4 - a2);
    v12 = (double)v7;
    a1a.field_4 = a3;
    a2a.field_0 = a4;
    a2a.field_4 = v5;
    *(float*)& byte_5D4594[1313880] = v12;
    v26 = sqrt(v12 * *(float*)& byte_5D4594[1313880] + v11 * v11) + 0.0099999998;
    *(float*)& byte_5D4594[1313876] = v11 / v26;
    v13 = *(float*)& byte_5D4594[1313880] / v26;
    *(float*)& byte_5D4594[1313880] = v13;
    v14 = v13 * v10 + *(float*)& byte_5D4594[1313876] * v9;
    if (v14 < 0.0)
        v14 = v14 * 0.2;
    v15 = (1.0 - v14) * (double)v8 * 2.3;
    *(float*)& byte_5D4594[1313868] = v9 * v15;
    *(float*)& byte_5D4594[1313872] = v10 * v15;
    a3a.field_0 = sub_419A70(*(float*)& byte_5D4594[1313868]);
    v16 = sub_419A70(*(float*)& byte_5D4594[1313872]);
    a4a.field_0 = v6;
    v17 = 0;
    a3a.field_4 = v16;
    a4a.field_4 = v7;
    a5 = 0;
    do
    {
        if (v17)
            * (float*)& byte_5D4594[4 * v17 + 1313856] = *(float*)& byte_5D4594[4 * v17 + 1313856] + 0.25;
        else
            *(float*)& byte_5D4594[1313856] = *(float*)& byte_5D4594[1313856] + 0.2;
        v18 = *(_DWORD*)& byte_5D4594[1316408];
        if (*(float*)& byte_5D4594[4 * v17 + 1313856] >= 1.0)
        {
            v19 = *(_DWORD*)& byte_5D4594[1316408] + 1;
            if (*(_DWORD*)& byte_5D4594[1316408] + 1 > 0)
            {
                v20 = &byte_5D4594[28 * (v19 + 30 * v17) + 1313872];
                do
                {
                    *((_DWORD*)v20 + 6) = *((_DWORD*)v20 - 1);
                    *((_DWORD*)v20 + 7) = *(_DWORD*)v20;
                    *((_DWORD*)v20 + 8) = *((_DWORD*)v20 + 1);
                    *((_DWORD*)v20 + 9) = *((_DWORD*)v20 + 2);
                    *((_DWORD*)v20 + 5) = *((_DWORD*)v20 - 2);
                    v20 -= 28;
                    --v19;
                } while (v19);
            }
            *(_DWORD*)& byte_5D4594[4 * v17 + 1313856] = 0;
            *(_DWORD*)& byte_5D4594[840 * v17 + 1313908] = 0;
        }
        v21 = *(float*)& byte_5D4594[4 * v17 + 1313856];
        *(_DWORD*)& byte_5D4594[1316412] = 0;
        sub_4BEDE0(&a1a, &a2a, &a3a, &a4a, v18, v21, sub_4BA8B0, (int)& a5);
        v17 = ++a5;
    } while (a5 < 3);
}
// 4BA6B4: variable 'v8' is possibly undefined

//----- (004BA8B0) --------------------------------------------------------
char __cdecl sub_4BA8B0(int* a1, int* a2, int* a3)
{
    int v3; // esi
    char* v4; // edi
    int v5; // edx
    int v6; // eax

    v3 = *a3;
    v4 = sub_437250();
    if (!*(_DWORD*)& byte_5D4594[1316416])
        * (_DWORD*)& byte_5D4594[1316416] = sub_44CFC0((CHAR*)& byte_587000[178156]);
    v6 = 28 * (*(_DWORD*)& byte_5D4594[1316412] + 30 * v3);
    v5 = *(_DWORD*)& byte_5D4594[1316412] + 1;
    *(_DWORD*)& byte_5D4594[v6 + 1313884] = *a1;
    *(_DWORD*)& byte_5D4594[v6 + 1313888] = a1[1];
    *(_DWORD*)& byte_5D4594[v6 + 1313912] = *a2;
    *(_DWORD*)& byte_5D4594[v6 + 1313916] = a2[1];
    LOBYTE(v6) = byte_5D4594[2598000];
    *(_DWORD*)& byte_5D4594[1316412] = v5;
    if (byte_5D4594[2598000] & 4)
    {
        v6 = sub_415FF0(0, 10, "C:\\NoxPost\\src\\client\\Draw\\Plasma.c", 135);
        if (v6 > 5)
            LOBYTE(v6) = sub_499710(
                *a2 + *((_DWORD*)v4 + 4) - *(_DWORD*)v4,
                a2[1] + *((_DWORD*)v4 + 5) - *((_DWORD*)v4 + 1),
                8,
                *(int*)& byte_5D4594[1316416]);
    }
    return v6;
}

//----- (004BA980) --------------------------------------------------------
int __cdecl nox_thing_plasma_draw(int* a1, int a2)
{
    int v3; // ebx
    unsigned __int16 v4; // di
    int v5; // ebp
    int v6; // ecx
    int v7; // edx
    int v8; // eax
    int v9; // esi
    int* v10; // edi
    int* v11; // ebx
    int v12; // eax
    _DWORD* v13; // eax
    int v14; // eax
    _DWORD* v15; // edi
    int v16; // eax
    _DWORD* v17; // eax
    int v18; // eax
    _DWORD* v19; // ebp
    int v20; // eax
    int v21; // edx
    int v22; // ebx
    int v23; // ecx
    int2* v24; // [esp+0h] [ebp-Ch]
    float2 v25; // [esp+4h] [ebp-8h]
    unsigned __int8 v26; // [esp+14h] [ebp+8h]

    v24 = sub_4309F0();
    v3 = a2;
    if (*(_BYTE*)(a2 + 432))
    {
        if (sub_578B70(*(_DWORD*)(a2 + 437)))
        {
            v12 = sub_578B30(*(_DWORD*)(a2 + 437));
            v13 = sub_45A720(v12);
        }
        else
        {
            v14 = sub_578B30(*(_DWORD*)(a2 + 437));
            v13 = sub_45A6F0(v14);
        }
        v15 = v13;
        if (sub_578B70(*(_DWORD*)(a2 + 441)))
        {
            v16 = sub_578B30(*(_DWORD*)(a2 + 441));
            v17 = sub_45A720(v16);
        }
        else
        {
            v18 = sub_578B30(*(_DWORD*)(a2 + 441));
            v17 = sub_45A6F0(v18);
        }
        v19 = v17;
        if (v15 && v17)
        {
            v20 = a1[5];
            v21 = a1[4];
            v22 = *a1;
            v23 = a1[1];
            v9 = *a1 + v15[3] - v21;
            a2 = *a1 + v15[3] - v21;
            a1 = (int*)(v15[4] - v20 + v23 - 20);
            v10 = (int*)(v22 + v19[3] - v21);
            v11 = (int*)(v19[4] - v20 + v23 - 20);
        }
        else
        {
            v9 = a2;
            v10 = a1;
            v11 = a1;
        }
        v25.field_0 = (double)v24->field_0 - (double)a2;
        v25.field_4 = (double)v24->field_4 - (double)(int)a1;
        v26 = sub_509ED0(&v25);
    }
    else
    {
        v4 = *(_WORD*)(a2 + 439);
        v26 = *(_BYTE*)(a2 + 433);
        v5 = a1[5];
        v6 = a1[4];
        v7 = *a1;
        v8 = a1[1];
        v9 = *a1 + *(unsigned __int16*)(v3 + 437) - v6;
        a1 = (int*)(v4 - v5 + v8 - 20);
        v10 = (int*)(v7 + *(unsigned __int16*)(v3 + 441) - v6);
        v11 = (int*)(*(unsigned __int16*)(v3 + 443) - v5 + v8 - 20);
    }
    sub_4BA230(v26, v9, (int)a1, (int)v10, (int)v11);
    return 1;
}
// 4BAA32: variable 'v12' is possibly undefined
// 4BAA46: variable 'v14' is possibly undefined
// 4BAA70: variable 'v16' is possibly undefined
// 4BAA84: variable 'v18' is possibly undefined

//----- (004BAB30) --------------------------------------------------------
int sub_4BAB30()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1316464] = sub_4344A0(255, 255, 255);
    *(_DWORD*)& byte_5D4594[1316488] = sub_4344A0(128, 128, 255);
    *(_DWORD*)& byte_5D4594[1316424] = sub_4344A0(128, 128, 255);
    *(_DWORD*)& byte_5D4594[1316428] = sub_4344A0(64, 64, 255);
    *(_DWORD*)& byte_5D4594[1316516] = sub_4344A0(200, 200, 255);
    *(_DWORD*)& byte_5D4594[1316512] = sub_4344A0(128, 128, 255);
    *(_DWORD*)& byte_5D4594[1316496] = sub_4344A0(255, 255, 255);
    *(_DWORD*)& byte_5D4594[1316468] = sub_4344A0(255, 255, 0);
    *(_DWORD*)& byte_5D4594[1316460] = sub_4344A0(30, 160, 30);
    *(_DWORD*)& byte_5D4594[1316444] = sub_4344A0(60, 140, 60);
    *(_DWORD*)& byte_5D4594[1316504] = sub_4344A0(40, 225, 40);
    *(_DWORD*)& byte_5D4594[1316480] = sub_4344A0(150, 220, 150);
    *(_DWORD*)& byte_5D4594[1316520] = sub_44CFC0((CHAR*)& byte_587000[178220]);
    *(_DWORD*)& byte_5D4594[1316524] = sub_44CFC0((CHAR*)& byte_587000[178232]);
    result = sub_44CFC0((CHAR*)& byte_587000[178244]);
    *(_DWORD*)& byte_5D4594[1316528] = result;
    return result;
}

//----- (004BAC80) --------------------------------------------------------
int __cdecl nox_thing_lightning_draw(int* a1, int a2)
{
    int v2; // ebx
    int v3; // edi
    int v4; // ebp
    int v5; // ecx
    unsigned __int16 v6; // ax
    _DWORD* v7; // eax
    _DWORD* v8; // edi
    _DWORD* v9; // eax
    int v10; // esi
    int v11; // ecx
    int v12; // ebx
    int v13; // edx
    int2 a2a; // [esp+10h] [ebp-20h]
    int2 a1a; // [esp+18h] [ebp-18h]
    int2 a3; // [esp+20h] [ebp-10h]
    int2 v18; // [esp+28h] [ebp-8h]
    int v19; // [esp+34h] [ebp+4h]

    if (!*(_BYTE*)(a2 + 432))
    {
        v2 = *a1;
        v3 = a1[4];
        v4 = a1[5];
        v5 = *a1;
        v19 = a1[1];
        v18.field_0 = *(unsigned __int16*)(a2 + 437);
        a1a.field_0 = v18.field_0 + v5 - v3;
        v6 = *(_WORD*)(a2 + 441);
        v18.field_4 = *(unsigned __int16*)(a2 + 439);
        a1a.field_4 = v19 - v4 + v18.field_4 - 20;
        a3.field_0 = v6;
        a2a.field_0 = v2 + v6 - v3;
        a3.field_4 = *(unsigned __int16*)(a2 + 443);
        a2a.field_4 = a3.field_4 - v4 + v19 - 20;
        goto LABEL_12;
    }
    if (sub_578B70(*(_DWORD*)(a2 + 437)))
        v7 = sub_45A720(*(_DWORD*)(a2 + 437));
    else
        v7 = sub_45A6F0(*(_DWORD*)(a2 + 437));
    v8 = v7;
    if (sub_578B70(*(_DWORD*)(a2 + 441)))
        v9 = sub_45A720(*(_DWORD*)(a2 + 441));
    else
        v9 = sub_45A6F0(*(_DWORD*)(a2 + 441));
    if (v8 && v9)
    {
        v10 = a1[4];
        v11 = *a1 - v10;
        a1a.field_0 = *a1 + v8[3] - v10;
        v12 = a1[5];
        v13 = a1[1];
        a1a.field_4 = v13 + v8[4] - v12 - 20;
        v18 = *(int2*)(v8 + 3);
        a2a.field_0 = v9[3] + v11;
        a2a.field_4 = v9[4] - v12 + v13 - 20;
        a3 = *(int2*)(v9 + 3);
    LABEL_12:
        *(_DWORD*)& byte_5D4594[1316452] = *(_DWORD*)& byte_5D4594[1316428];
        *(_DWORD*)& byte_5D4594[1316436] = *(_DWORD*)& byte_5D4594[1316464];
        *(_DWORD*)& byte_5D4594[1316456] = *(_DWORD*)& byte_5D4594[1316424];
        *(_DWORD*)& byte_5D4594[1316484] = *(_DWORD*)& byte_5D4594[1316488];
        byte_5D4594[1316420] = 1;
        sub_4BAE60(&a1a, &a2a, 2, 0, 1, 1, 1);
        if (!sub_413A50())
            sub_4999D0(*(int*)& byte_5D4594[1316520], &v18, &a3);
    }
    return 1;
}

//----- (004BAE60) --------------------------------------------------------
int __cdecl sub_4BAE60(int2* a1, int2* a2, int a3, __int16* a4, int a5, int a6, int a7)
{
    int2* v7; // ebx
    int2* v8; // ebp
    int v9; // esi
    int v10; // eax
    int v11; // eax
    __int64 v12; // rax
    int v13; // eax
    int v14; // edi
    int v15; // ebx
    int v16; // eax
    int v17; // edx
    int v18; // esi
    int v19; // ecx
    int result; // eax
    int2* v21; // [esp+14h] [ebp+4h]
    int2* v22; // [esp+18h] [ebp+8h]

    v7 = a2;
    v8 = a1;
    if (a1->field_0 - a2->field_0 >= 0)
        v9 = a1->field_0 - a2->field_0;
    else
        v9 = a2->field_0 - a1->field_0;
    v10 = a2->field_4;
    if (a1->field_4 - v10 >= 0)
        v11 = a1->field_4 - v10;
    else
        v11 = v10 - a1->field_4;
    v12 = (__int64)sqrt((double)(v9 * v9 + v11 * v11));
    if ((int)v12 >= 512)
    {
        *(_DWORD*)& byte_5D4594[1316476] = *(_DWORD*)& byte_587000[178204];
        *(_DWORD*)& byte_5D4594[1316448] = *(_DWORD*)& byte_587000[178216];
        goto LABEL_19;
    }
    *(_DWORD*)& byte_5D4594[1316476] = *(_DWORD*)& byte_587000[178208]
        + (int)v12
        * (*(_DWORD*)& byte_587000[178204] - *(_DWORD*)& byte_587000[178208])
        / 512;
    if ((int)v12 >= 64)
    {
        if ((int)v12 >= 128)
        {
            if ((int)v12 >= 256)
            {
                v13 = *(_DWORD*)& byte_587000[178216];
                goto LABEL_17;
            }
            v13 = *(_DWORD*)& byte_587000[178216] - 1;
        }
        else
        {
            v13 = *(_DWORD*)& byte_587000[178216] - 2;
        }
    }
    else
    {
        v13 = *(_DWORD*)& byte_587000[178216] - 3;
    }
    if (v13 >= 1)
    {
    LABEL_17:
        *(_DWORD*)& byte_5D4594[1316448] = v13;
        goto LABEL_19;
    }
    *(_DWORD*)& byte_5D4594[1316448] = 1;
LABEL_19:
    *(_DWORD*)& byte_5D4594[1316532] = a3;
    if (a3 == 1 || a3 == 3)
    {
        *(_WORD*)& byte_5D4594[1316432] = *a4;
        *(_WORD*)& byte_5D4594[1316434] = a4[2];
        v14 = a1->field_0;
        v15 = a2->field_0;
        v16 = a1->field_0 - a2->field_0;
        if (v16 < 0)
            v16 = v15 - v14;
        v17 = a1->field_4;
        v18 = a2->field_4;
        v19 = a1->field_4 - v18;
        if (v19 < 0)
            v19 = v18 - v17;
        if (v16 <= v19)
            * (_DWORD*)& byte_5D4594[1316500] = (v17 >= v18) + 2;
        else
            *(_DWORD*)& byte_5D4594[1316500] = v14 >= v15;
        v7 = a2;
    }
    LOWORD(v22) = a1->field_0;
    LOWORD(v21) = v7->field_0;
    HIWORD(v22) = v8->field_4;
    HIWORD(v21) = v7->field_4;
    if (a6)
    {
        *(_DWORD*)& byte_5D4594[1316492] = 1;
        *(_DWORD*)& byte_5D4594[1316472] = *(_DWORD*)& byte_5D4594[1316456];
        *(_DWORD*)& byte_5D4594[1316508] = 0;
        sub_4BB070((int)v22, (int)v21);
        *(_DWORD*)& byte_5D4594[1316492] = 1;
        *(_DWORD*)& byte_5D4594[1316472] = *(_DWORD*)& byte_5D4594[1316452];
        sub_4BB070((int)v22, (int)v21);
    }
    result = a7;
    if (a7)
    {
        *(_DWORD*)& byte_5D4594[1316492] = 1;
        *(_DWORD*)& byte_5D4594[1316472] = *(_DWORD*)& byte_5D4594[1316436];
        *(_DWORD*)& byte_5D4594[1316440] = *(_DWORD*)& byte_5D4594[1316484];
        *(_DWORD*)& byte_5D4594[1316508] = 1;
        result = sub_4BB070((int)v22, (int)v21);
    }
    return result;
}

//----- (004BB070) --------------------------------------------------------
int __cdecl sub_4BB070(int a1, int a2)
{
    int v2; // eax
    bool v3; // zf
    int v4; // esi
    int v5; // edi
    int v6; // ebx
    int v7; // ebp
    unsigned __int8 v8; // al
    int v9; // ecx
    int v10; // eax
    int v11; // ecx
    int v12; // eax
    int v14; // edi
    int v15; // esi
    int v16; // eax
    int v17; // [esp+10h] [ebp-14h]
    int v18; // [esp+10h] [ebp-14h]
    int v19; // [esp+14h] [ebp-10h]
    int v20; // [esp+14h] [ebp-10h]
    int v21; // [esp+18h] [ebp-Ch]
    int v22; // [esp+18h] [ebp-Ch]
    int v23; // [esp+20h] [ebp-4h]
    int v24; // [esp+20h] [ebp-4h]
    int v25; // [esp+28h] [ebp+4h]
    int v26; // [esp+28h] [ebp+4h]
    int v27; // [esp+2Ch] [ebp+8h]
    int v28; // [esp+2Ch] [ebp+8h]

    v2 = *(_DWORD*)& byte_5D4594[1316492] + 1;
    v3 = *(_DWORD*)& byte_5D4594[1316492] + 1 == *(_DWORD*)& byte_5D4594[1316448];
    v23 = 0;
    ++* (_DWORD*)& byte_5D4594[1316492];
    if (!v3)
    {
        v14 = 1;
        v15 = 1;
        if (v2 > 1)
        {
            v16 = v2 - 1;
            do
            {
                v14 *= *(_DWORD*)& byte_587000[178212] + 9;
                v15 *= 10;
                --v16;
            } while (v16);
        }
        LOWORD(v24) = v15
            * sub_415FF0(
                -*(_DWORD*)& byte_5D4594[1316476],
                *(int*)& byte_5D4594[1316476],
                "C:\\NoxPost\\src\\Client\\Draw\\Litning.c",
                193)
            / v14
            + (((__int16)a1 + (__int16)a2) >> 1);
        HIWORD(v24) = v15
            * sub_415FF0(
                -*(_DWORD*)& byte_5D4594[1316476],
                *(int*)& byte_5D4594[1316476],
                "C:\\NoxPost\\src\\Client\\Draw\\Litning.c",
                196)
            / v14
            + ((SHIWORD(a1) + SHIWORD(a2)) >> 1);
        sub_4BB070(a1, v24);
        sub_4BB070(v24, a2);
        return -- * (_DWORD*)& byte_5D4594[1316492];
    }
    if (*(_DWORD*)& byte_5D4594[1316508])
    {
        LOBYTE(v23) = byte_5D4594[1316420] + 48;
        sub_434040(*(int*)& byte_5D4594[1316440]);
        sub_434080(12);
        v4 = SHIWORD(a1);
        v5 = (__int16)a1;
        sub_49F500((__int16)a1, SHIWORD(a1));
        v6 = SHIWORD(a2);
        v7 = (__int16)a2;
        sub_49F500((__int16)a2, SHIWORD(a2));
        sub_49E4F0(v23);
        v23 = 1;
    }
    else
    {
        sub_434040(*(int*)& byte_5D4594[1316472]);
        sub_434080(3);
        v4 = SHIWORD(a1);
        v5 = (__int16)a1;
        sub_49F500((__int16)a1, SHIWORD(a1));
        v6 = SHIWORD(a2);
        v7 = (__int16)a2;
        sub_49F500((__int16)a2, SHIWORD(a2));
        sub_49E4F0(32);
    }
    sub_434460(*(int*)& byte_5D4594[1316472]);
    sub_49F500(v5, v4);
    sub_49F500(v7, v6);
    sub_49E4B0();
    if (!v23)
        return -- * (_DWORD*)& byte_5D4594[1316492];
    v8 = byte_5D4594[1316420];
    v25 = 1;
    if ((byte_5D4594[1316420] & 0xFEu) > 2)
    {
        v19 = v7 + 1;
        v21 = v5 + 1;
        v17 = v4 + 1;
        v27 = v6 + 1;
        do
        {
            sub_49F5A0();
            v9 = v5 - v7;
            if (v5 - v7 < 0)
                v9 = v7 - v5;
            v10 = v4 - v6;
            if (v4 - v6 < 0)
                v10 = v6 - v4;
            if (v9 <= v10)
            {
                sub_49F500(v19, v6);
                sub_49F500(v21, v4);
            }
            else
            {
                sub_49F500(v7, v27);
                sub_49F500(v5, v17);
            }
            sub_49E4B0();
            ++v27;
            ++v17;
            ++v21;
            v8 = byte_5D4594[1316420];
            ++v19;
            ++v25;
        } while (v25 < byte_5D4594[1316420] >> 1);
    }
    v26 = 1;
    if ((v8 & 0xFEu) <= 2)
        return -- * (_DWORD*)& byte_5D4594[1316492];
    v20 = v7 - 1;
    v18 = v5 - 1;
    v22 = v4 - 1;
    v28 = v6 - 1;
    do
    {
        sub_49F5A0();
        v11 = v5 - v7;
        if (v5 - v7 < 0)
            v11 = v7 - v5;
        v12 = v4 - v6;
        if (v4 - v6 < 0)
            v12 = v6 - v4;
        if (v11 <= v12)
        {
            sub_49F500(v20, v6);
            sub_49F500(v18, v4);
        }
        else
        {
            sub_49F500(v7, v28);
            sub_49F500(v5, v22);
        }
        sub_49E4B0();
        --v28;
        --v22;
        --v18;
        ++v26;
        --v20;
    } while (v26 < byte_5D4594[1316420] >> 1);
    return -- * (_DWORD*)& byte_5D4594[1316492];
}

//----- (004BB3F0) --------------------------------------------------------
int __cdecl nox_thing_chain_lightning_bolt_draw(int* a1, int a2)
{
    unsigned __int16 v2; // ax
    int v3; // ebx
    int v4; // edi
    int v5; // ebp
    int v6; // edx
    int v7; // ecx
    unsigned __int16 v8; // ax
    _DWORD* v9; // eax
    _DWORD* v10; // edi
    _DWORD* v11; // eax
    int v12; // esi
    int v13; // ecx
    int v14; // ebx
    int v15; // edx
    int2 a2a; // [esp+10h] [ebp-20h]
    int2 a1a; // [esp+18h] [ebp-18h]
    int2 v19; // [esp+20h] [ebp-10h]
    int2 a3; // [esp+28h] [ebp-8h]

    if (!*(_BYTE*)(a2 + 432))
    {
        v2 = *(_WORD*)(a2 + 437);
        v3 = *a1;
        v4 = a1[4];
        v5 = a1[5];
        v6 = a1[1];
        v7 = v2 + *a1 - v4;
        v19.field_0 = v2;
        a1a.field_0 = v7;
        LOWORD(v7) = *(_WORD*)(a2 + 439);
        a2a.field_0 = v3 + *(unsigned __int16*)(a2 + 441) - v4;
        v19.field_4 = (unsigned __int16)v7;
        v8 = *(_WORD*)(a2 + 443);
        a1a.field_4 = v6 - v5 + (unsigned __int16)v7 - 20;
        a3.field_0 = v8;
        a2a.field_4 = v8 - v5 + v6 - 20;
        goto LABEL_12;
    }
    if (sub_578B70(*(_DWORD*)(a2 + 437)))
        v9 = sub_45A720(*(_DWORD*)(a2 + 437));
    else
        v9 = sub_45A6F0(*(_DWORD*)(a2 + 437));
    v10 = v9;
    if (sub_578B70(*(_DWORD*)(a2 + 441)))
        v11 = sub_45A720(*(_DWORD*)(a2 + 441));
    else
        v11 = sub_45A6F0(*(_DWORD*)(a2 + 441));
    if (v10 && v11)
    {
        v12 = a1[4];
        v13 = *a1 - v12;
        a1a.field_0 = *a1 + v10[3] - v12;
        v14 = a1[5];
        v15 = a1[1];
        a1a.field_4 = v15 + v10[4] - v14 - 20;
        v19 = *(int2*)(v10 + 3);
        a2a.field_0 = v11[3] + v13;
        a2a.field_4 = v11[4] - v14 + v15 - 20;
        a3 = *(int2*)(v11 + 3);
    LABEL_12:
        *(_DWORD*)& byte_5D4594[1316452] = *(_DWORD*)& byte_5D4594[1316428];
        *(_DWORD*)& byte_5D4594[1316436] = *(_DWORD*)& byte_5D4594[1316464];
        *(_DWORD*)& byte_5D4594[1316456] = *(_DWORD*)& byte_5D4594[1316424];
        *(_DWORD*)& byte_5D4594[1316484] = *(_DWORD*)& byte_5D4594[1316488];
        byte_5D4594[1316420] = 1;
        sub_4BAE60(&a1a, &a2a, 2, 0, 1, 1, 1);
        if (!sub_413A50())
            sub_4999D0(*(int*)& byte_5D4594[1316520], &v19, &a3);
    }
    return 1;
}

//----- (004BB5D0) --------------------------------------------------------
int __cdecl nox_thing_energy_bolt_draw(int* a1, int a2)
{
    int v2; // esi
    bool v3; // zf
    int v4; // ebp
    int v5; // edi
    int v6; // ebx
    int v7; // ecx
    unsigned __int16 v8; // ax
    _DWORD* v9; // eax
    _DWORD* v10; // edi
    _DWORD* v11; // eax
    int v12; // esi
    int v13; // edx
    int v14; // ebp
    int v15; // ecx
    int2 a2a; // [esp+10h] [ebp-20h]
    int2 a1a; // [esp+18h] [ebp-18h]
    int2 a3; // [esp+20h] [ebp-10h]
    int2 v20; // [esp+28h] [ebp-8h]
    int v21; // [esp+34h] [ebp+4h]
    char v22; // [esp+38h] [ebp+8h]

    v2 = a2;
    v3 = *(_BYTE*)(a2 + 432) == 0;
    v22 = *(_BYTE*)(a2 + 433);
    if (v3)
    {
        v4 = *a1;
        v5 = a1[4];
        v6 = a1[5];
        v7 = *a1;
        v21 = a1[1];
        v20.field_0 = *(unsigned __int16*)(v2 + 437);
        a1a.field_0 = v20.field_0 + v7 - v5;
        v8 = *(_WORD*)(v2 + 441);
        v20.field_4 = *(unsigned __int16*)(v2 + 439);
        a1a.field_4 = v21 - v6 + v20.field_4 - 20;
        a3.field_0 = v8;
        a2a.field_0 = v4 + v8 - v5;
        a3.field_4 = *(unsigned __int16*)(v2 + 443);
        a2a.field_4 = a3.field_4 - v6 + v21 - 20;
        goto LABEL_12;
    }
    if (sub_578B70(*(_DWORD*)(v2 + 437)))
        v9 = sub_45A720(*(_DWORD*)(v2 + 437));
    else
        v9 = sub_45A6F0(*(_DWORD*)(v2 + 437));
    v10 = v9;
    if (sub_578B70(*(_DWORD*)(v2 + 441)))
        v11 = sub_45A720(*(_DWORD*)(v2 + 441));
    else
        v11 = sub_45A6F0(*(_DWORD*)(v2 + 441));
    if (v10 && v11)
    {
        v12 = *a1;
        v13 = a1[4];
        v14 = a1[5];
        v15 = a1[1];
        a1a.field_0 = v10[3] + *a1 - v13;
        a1a.field_4 = v10[4] - v14 + v15 - 20;
        v20 = *(int2*)(v10 + 3);
        a2a.field_0 = v12 + v11[3] - v13;
        a2a.field_4 = v11[4] - v14 + v15 - 20;
        a3 = *(int2*)(v11 + 3);
    LABEL_12:
        byte_5D4594[1316420] = 2 * (v22 + 127);
        *(_DWORD*)& byte_5D4594[1316436] = *(_DWORD*)& byte_5D4594[1316496];
        *(_DWORD*)& byte_5D4594[1316484] = *(_DWORD*)& byte_5D4594[1316468];
        sub_4BAE60(&a1a, &a2a, 2, 0, 0, 0, 1);
        if (!sub_413A50())
            sub_4999D0(*(int*)& byte_5D4594[1316524], &v20, &a3);
    }
    return 1;
}

//----- (004BB7B0) --------------------------------------------------------
int __cdecl nox_thing_green_bolt_draw(int* a1, int a2)
{
    int v2; // eax
    int v3; // eax
    int v5; // ebx
    int v6; // edi
    int v7; // ebp
    int v8; // ecx
    unsigned __int16 v9; // ax
    _DWORD* v10; // eax
    _DWORD* v11; // edi
    _DWORD* v12; // eax
    int v13; // esi
    int v14; // edx
    int v15; // ebx
    int v16; // ecx
    int2 a2a; // [esp+10h] [ebp-20h]
    int2 a1a; // [esp+18h] [ebp-18h]
    int2 a3; // [esp+20h] [ebp-10h]
    int2 v20; // [esp+28h] [ebp-8h]
    int v21; // [esp+34h] [ebp+4h]

    if (*(_BYTE*)(a2 + 432))
    {
        if (sub_578B70(*(_DWORD*)(a2 + 437)))
            v10 = sub_45A720(*(_DWORD*)(a2 + 437));
        else
            v10 = sub_45A6F0(*(_DWORD*)(a2 + 437));
        v11 = v10;
        if (sub_578B70(*(_DWORD*)(a2 + 441)))
            v12 = sub_45A720(*(_DWORD*)(a2 + 441));
        else
            v12 = sub_45A6F0(*(_DWORD*)(a2 + 441));
        if (!v11 || !v12)
            return 1;
        v13 = *a1;
        v14 = a1[4];
        a1a.field_0 = v11[3] + *a1 - v14;
        v15 = a1[5];
        v16 = a1[1];
        a1a.field_4 = v16 + v11[4] - v15 - 20;
        v20 = *(int2*)(v11 + 3);
        a2a.field_0 = v13 + v12[3] - v14;
        a2a.field_4 = v12[4] - v15 + v16 - 20;
        a3 = *(int2*)(v12 + 3);
    }
    else
    {
        v2 = *(_DWORD*)(a2 + 433);
        if (v2)
        {
            v3 = v2 - 1;
            *(_DWORD*)(a2 + 433) = v3;
            if (!v3)
            {
                sub_45A4E0(a2);
                return 0;
            }
        }
        v5 = *a1;
        v6 = a1[4];
        v7 = a1[5];
        v8 = *a1;
        v21 = a1[1];
        v20.field_0 = *(unsigned __int16*)(a2 + 437);
        a1a.field_0 = v20.field_0 + v8 - v6;
        v9 = *(_WORD*)(a2 + 441);
        v20.field_4 = *(unsigned __int16*)(a2 + 439);
        a1a.field_4 = v21 - v7 + v20.field_4 - 20;
        a3.field_0 = v9;
        a2a.field_0 = v5 + v9 - v6;
        a3.field_4 = *(unsigned __int16*)(a2 + 443);
        a2a.field_4 = a3.field_4 - v7 + v21 - 20;
    }
    *(_DWORD*)& byte_5D4594[1316452] = *(_DWORD*)& byte_5D4594[1316444];
    *(_DWORD*)& byte_5D4594[1316436] = *(_DWORD*)& byte_5D4594[1316504];
    *(_DWORD*)& byte_5D4594[1316456] = *(_DWORD*)& byte_5D4594[1316460];
    *(_DWORD*)& byte_5D4594[1316484] = *(_DWORD*)& byte_5D4594[1316480];
    byte_5D4594[1316420] = 1;
    sub_4BAE60(&a1a, &a2a, 2, 0, 1, 1, 1);
    if (!sub_413A50())
        sub_4999D0(*(int*)& byte_5D4594[1316528], &v20, &a3);
    return 1;
}

//----- (004BB9D0) --------------------------------------------------------
int __cdecl nox_thing_trigger_draw(_DWORD* a1, int a2)
{
    int v2; // edi
    int v3; // ebx
    int v4; // ebp
    int v5; // edi
    int v7; // [esp+10h] [ebp-20h]
    int v8; // [esp+14h] [ebp-1Ch]
    int v9; // [esp+18h] [ebp-18h]
    int v10; // [esp+1Ch] [ebp-14h]
    int v11; // [esp+20h] [ebp-10h]
    int v12; // [esp+2Ch] [ebp-4h]

    v2 = *a1 - a1[4];
    v3 = a1[1] - a1[5];
    v4 = *(_DWORD*)(a2 + 12) + v2 + sub_419A70(*(float*)(a2 + 64));
    v12 = *(_DWORD*)(a2 + 16) + v3 + sub_419A70(*(float*)(a2 + 68));
    v7 = *(_DWORD*)(a2 + 12) + v2 + sub_419A70(*(float*)(a2 + 88));
    v8 = *(_DWORD*)(a2 + 16) + v3 + sub_419A70(*(float*)(a2 + 92));
    v9 = *(_DWORD*)(a2 + 12) + v2 + sub_419A70(*(float*)(a2 + 72));
    v10 = *(_DWORD*)(a2 + 16) + v3 + sub_419A70(*(float*)(a2 + 76));
    v11 = *(_DWORD*)(a2 + 12) + v2 + sub_419A70(*(float*)(a2 + 80));
    v5 = *(_DWORD*)(a2 + 16) + v3 + sub_419A70(*(float*)(a2 + 84));
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_434560(1);
    sub_49F500(v4, v12);
    sub_49F500(v11, v5);
    sub_49E4B0();
    sub_49F500(v7, v8);
    sub_49F500(v11, v5);
    sub_49E4B0();
    sub_49F500(v4, v12);
    sub_49F500(v9, v10);
    sub_49E4B0();
    sub_49F500(v7, v8);
    sub_49F500(v9, v10);
    sub_49E4B0();
    sub_434560(0);
    return 1;
}

//----- (004BBB30) --------------------------------------------------------
int __cdecl nox_thing_pressure_plate_draw(_DWORD* a1, int a2)
{
    int v2; // esi
    int v4; // ebp
    int v5; // edi
    int v6; // ebx
    int v7; // ebp
    int v8; // eax
    int v9; // edx
    int v10; // ecx
    int v11; // eax
    int v12; // edi
    float v13; // [esp-10h] [ebp-34h]
    int v14; // [esp+4h] [ebp-20h]
    int v15; // [esp+8h] [ebp-1Ch]
    int v16; // [esp+Ch] [ebp-18h]
    int v17; // [esp+10h] [ebp-14h]
    int v18; // [esp+14h] [ebp-10h]
    int v19; // [esp+1Ch] [ebp-8h]
    int v20; // [esp+2Ch] [ebp+8h]

    v2 = a2;
    if (!*(_BYTE*)(a2 + 432)
        && !*(_BYTE*)(a2 + 433)
        && !*(_BYTE*)(a2 + 434)
        && !*(_BYTE*)(a2 + 435)
        && !*(_BYTE*)(a2 + 436)
        && !*(_BYTE*)(a2 + 437))
    {
        return 1;
    }
    v4 = a1[1] - a1[5];
    v13 = *(float*)(a2 + 64);
    v5 = *a1 - a1[4];
    v20 = a1[1] - a1[5];
    v18 = *(_DWORD*)(v2 + 12) + v5 + sub_419A70(v13);
    v6 = *(_DWORD*)(v2 + 16) + v4 + sub_419A70(*(float*)(v2 + 68));
    v19 = *(_DWORD*)(v2 + 12) + v5 + sub_419A70(*(float*)(v2 + 88));
    v7 = *(_DWORD*)(v2 + 16) + v20 + sub_419A70(*(float*)(v2 + 92));
    v16 = *(_DWORD*)(v2 + 12) + v5 + sub_419A70(*(float*)(v2 + 72));
    v17 = *(_DWORD*)(v2 + 16) + v20 + sub_419A70(*(float*)(v2 + 76));
    v14 = *(_DWORD*)(v2 + 12) + v5 + sub_419A70(*(float*)(v2 + 80));
    v8 = sub_419A70(*(float*)(v2 + 84));
    v9 = v20;
    v10 = *(_DWORD*)(v2 + 16);
    v11 = v10 + v20 + v8;
    v12 = 0;
    v15 = v11;
    do
    {
        if (v12)
        {
            LOBYTE(v9) = *(_BYTE*)(v2 + 437);
            LOBYTE(v11) = *(_BYTE*)(v2 + 436);
            LOBYTE(v10) = *(_BYTE*)(v2 + 435);
        }
        else
        {
            LOBYTE(v9) = *(_BYTE*)(v2 + 434);
            LOBYTE(v11) = *(_BYTE*)(v2 + 433);
            LOBYTE(v10) = *(_BYTE*)(v2 + 432);
        }
        sub_434430(v10, v11, v9);
        sub_49F500(v12 + v18, v6);
        sub_49F500(v12 + v14, v15);
        sub_49E4B0();
        sub_49F500(v12 + v19, v7);
        sub_49F500(v12 + v14, v15);
        sub_49E4B0();
        sub_49F500(v12 + v18, v6);
        sub_49F500(v12 + v16, v17);
        sub_49E4B0();
        sub_49F500(v12 + v19, v7);
        sub_49F500(v12 + v16, v17);
        v11 = sub_49E4B0();
        ++v12;
    } while (v12 < 2);
    return 1;
}
// 4BBC74: variable 'v10' is possibly undefined
// 4BBC74: variable 'v9' is possibly undefined

//----- (004BBD30) --------------------------------------------------------
int __cdecl nox_thing_slave_draw(int* a1, int a2)
{
    sub_4C4770(a1, (unsigned __int8*)a2, *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a2 + 304) + 4) + 4 * *(_DWORD*)(a2 + 308)));
    if (nox_thing_slave_draw == nox_thing_static_random_draw) // AntiICFoptimization
    {
        return 0;
    }
    return 1;
}

//----- (004BBD60) --------------------------------------------------------
int __cdecl nox_thing_animate_draw(int* a1, int a2)
{
    int v2; // edi
    int v3; // esi
    int v4; // ecx
    int result; // eax
    int v6; // ebx
    int v7; // eax

    v2 = *(_DWORD*)(a2 + 304);
    switch (*(_DWORD*)(v2 + 12))
    {
    case 0:
        v3 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 316)) / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
        v7 = *(unsigned __int8*)(v2 + 8);
        if (v3 >= v7)
            v3 = v7 - 1;
        goto LABEL_12;
    case 1:
        v3 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 316)) / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
        if (v3 < *(unsigned __int8*)(v2 + 8))
            goto LABEL_12;
        sub_45A4E0(a2);
        return 0;
    case 2:
        if (*(_DWORD*)(a2 + 120) & 0x1000000)
            goto LABEL_9;
        if (!(*(_DWORD*)(a2 + 112) & 0x10000000))
            goto LABEL_8;
        if (sub_40A5C0(32))
        {
        LABEL_9:
            v3 = (*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(a2 + 128))
                / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
            goto LABEL_10;
        }
        if (*(_DWORD*)(a2 + 112) & 0x10000000)
            goto LABEL_14;
    LABEL_8:
        v3 = 0;
        goto LABEL_12;
    case 3:
        v6 = 2 * *(unsigned __int8*)(v2 + 8);
        sub_434560(1);
        v3 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 316)) / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
        if (v3 < v6)
        {
            sub_434580(-56 - 200 * v3 / v6);
        LABEL_10:
            v4 = *(unsigned __int8*)(v2 + 8);
            if (v3 >= v4)
                v3 %= v4;
        LABEL_12:
            sub_4C4770(a1, (unsigned __int8*)a2, *(_DWORD*)(*(_DWORD*)(v2 + 4) + 4 * v3));
            if (*(_DWORD*)(v2 + 12) == 3)
                sub_434560(0);
        LABEL_14:
            result = 1;
        }
        else
        {
            sub_45A4E0(a2);
            result = 0;
        }
        return result;
    case 4:
        v3 = sub_415FF0(0, *(unsigned __int8*)(v2 + 8) - 1, "C:\\NoxPost\\src\\Client\\Draw\\animdraw.c", 24);
        goto LABEL_12;
    case 5:
        v3 = *(_DWORD*)(a2 + 308);
        goto LABEL_12;
    default:
        goto LABEL_14;
    }
}

//----- (004BBF10) --------------------------------------------------------
int __cdecl nox_thing_animate_state_draw(int* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // edx
    int v4; // eax
    int v5; // eax
    int result; // eax

    v2 = a2[70];
    v3 = a2[76];
    if (v2 & 2)
    {
        a2[79] = *(_DWORD*)& byte_5D4594[2598000];
        v4 = 0;
    }
    else if (v2 & 4)
    {
        v4 = 1;
    }
    else
    {
        v4 = ((unsigned __int8)v2 >> 2) & 2;
    }
    v5 = 48 * v4 + v3 + 4;
    if (*(_DWORD*)(v5 + 44) == 2)
        a2[79] = *(_DWORD*)& byte_5D4594[2598000];
    if (*(_WORD*)(v5 + 40))
        result = sub_4BC6B0(a1, (int)a2, v5);
    else
        result = 1;
    return result;
}

//----- (004BBF90) --------------------------------------------------------
int __cdecl nox_thing_maiden_draw(int* a1, int a2)
{
    int v2; // eax
    int v3; // edx
    int v5; // ecx
    int v6; // eax
    _BYTE* v7; // esi
    int v8; // edi
    char* v9; // eax
    int v10; // ecx
    int* v11; // edi
    int v12; // esi

    if (!sub_40A5C0(0x200000))
    {
        v9 = nox_npc_by_id(*(_DWORD*)(a2 + 128));
        if (!v9)
            return 1;
        v10 = 0;
        v11 = (int*)(v9 + 8);
        do
        {
            v12 = v10 + 1;
            sub_4341D0(v10 + 1, *v11);
            v10 = v12;
            ++v11;
        } while (v12 < 6);
        return nox_thing_monster_draw(a1, a2);
    }
    v2 = sub_4DA790();
    if (!v2)
        return nox_thing_monster_draw(a1, a2);
    while (1)
    {
        v3 = *(_DWORD*)(v2 + 40);
        if (*(_DWORD*)(a2 + 128) == v3)
            break;
        v2 = sub_4DA7A0(v2);
        if (!v2)
            return nox_thing_monster_draw(a1, a2);
    }
    v5 = *(_DWORD*)(v2 + 748);
    v6 = 0;
    v7 = (_BYTE*)(v5 + 2077);
    do
    {
        LOBYTE(v3) = v7[1];
        LOBYTE(v5) = *(v7 - 1);
        v8 = v6 + 1;
        LOBYTE(v6) = *v7;
        sub_4340A0(v8, v5, v6, v3);
        v6 = v8;
        v7 += 3;
    } while (v8 < 6);
    return nox_thing_monster_draw(a1, a2);
}
// 4BC002: variable 'v5' is possibly undefined
// 4BC002: variable 'v3' is possibly undefined

//----- (004BC080) --------------------------------------------------------
void __cdecl sub_4BC080(_DWORD* a1, int a2, unsigned __int16 a3, unsigned __int16 a4, char a5)
{
    int v5; // edi
    int v6; // edi
    int v7; // ebp
    int v8; // ebx
    int v9; // esi
    float v10; // [esp+0h] [ebp-14h]
    float v11; // [esp+0h] [ebp-14h]
    float v12; // [esp+0h] [ebp-14h]

    if (a2)
    {
        v5 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
        v10 = *(float*)(a2 + 48) + *(float*)(a2 + 48);
        v6 = sub_419A70(v10) + v5;
        v7 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 104) - a1[5];
        v11 = *(float*)(a2 + 100) - *(float*)(a2 + 96);
        v8 = sub_419A70(v11);
        if (v8 < 30)
            v8 = 30;
        v12 = *(float*)(a2 + 96) + *(float*)(a2 + 100);
        v9 = v7 + sub_419A70(v12) / -2 - v8 / 2;
        if (a4)
        {
            sub_434460(*(int*)& byte_5D4594[2650656]);
            sub_49CE30(v6, v9, 2, v8);
            if (a5)
                sub_434460(*(int*)& byte_5D4594[2618904]);
            else
                sub_434460(*(int*)& byte_5D4594[2650644]);
            sub_49CE30(v6, v8 + v9 - v8 * a3 / a4, 2, v8 * a3 / a4);
        }
    }
}

//----- (004BC180) --------------------------------------------------------
int __cdecl nox_thing_monster_draw(int* a1, int a2)
{
    int v2; // esi
    int v3; // edi
    char v4; // cl
    int v5; // eax
    int v6; // eax
    int v7; // ecx
    int v8; // ebx
    int v10; // edi
    int v11; // ebp
    int* v12; // edi
    char* v13; // eax
    int v14; // eax
    int v15; // eax
    int v16; // ebp
    char* v17; // ebx
    int* v18; // ebx
    int v19; // ebp
    int v20; // edi
    int v21; // [esp+Ch] [ebp-Ch]
    int v22; // [esp+10h] [ebp-8h]
    int v23; // [esp+14h] [ebp-4h]

    v2 = a2;
    v23 = 1;
    v3 = *(_DWORD*)(a2 + 304);
    if (!sub_40A5C0(0x200000))
    {
        v4 = *(_BYTE*)(v2 + 432);
        if (*(_BYTE*)(v2 + 297) != v4)
        {
            v5 = *(_DWORD*)(v2 + 276);
            if (v5 != 1 && v5 != 3 && v5 != 5)
            {
                if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v2 + 436)) >= *(int*)& byte_5D4594[2649704] >> 2)
                {
                    *(_DWORD*)(v2 + 436) = *(_DWORD*)& byte_5D4594[2598000];
                    *(_BYTE*)(v2 + 432) = *(_BYTE*)(v2 + 297);
                }
                else
                {
                    *(_BYTE*)(v2 + 297) = v4;
                }
            }
        }
    }
    v6 = *(_DWORD*)& byte_5D4594[1316536];
    if (!*(_DWORD*)& byte_5D4594[1316536])
    {
        v6 = sub_44CFC0((CHAR*)& byte_587000[178376]);
        *(_DWORD*)& byte_5D4594[1316536] = v6;
    }
    v7 = 48 * *(_DWORD*)(v2 + 276);
    v8 = v7 + v3 + 4;
    if (!*(_WORD*)(v7 + v3 + 44))
        return 1;
    if (*(_DWORD*)(v2 + 108) != v6)
        goto LABEL_22;
    if (sub_40A5C0(0x200000))
    {
        v10 = 0;
        v11 = 0;
    }
    else
    {
        v10 = *(_DWORD*)(v2 + 12) - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 12);
        v11 = *(_DWORD*)(v2 + 16) - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 16);
    }
    if (*(_DWORD*)& byte_5D4594[2614252] && sub_4356C0(*(int*)& byte_5D4594[2614252], 21))
    {
        sub_434600(1);
        sub_433E40(*(int*)& byte_5D4594[2618904]);
        LOBYTE(a2) = nox_backbuffer_depth >= 16 ? -1 : -128;
    LABEL_21:
        sub_434560(1);
        sub_434580(a2);
    LABEL_22:
        sub_4BC490(v2);
        v12 = a1;
        v23 = sub_4BC6B0(a1, v2, v8);
        sub_434600(0);
        goto LABEL_24;
    }
    if (v10 * v10 + v11 * v11 < 40000)
        goto LABEL_21;
    v12 = a1;
LABEL_24:
    if (sub_4951F0(*(_DWORD*)(v2 + 128)))
    {
        v22 = 0;
        v21 = 0;
        LOBYTE(a2) = 0;
        sub_495180(*(_DWORD*)(v2 + 128), &v22, &v21, &a2);
        sub_4BC080(v12, v2, v22, v21, a2);
    }
    if (!sub_417DA0(4) && (!*(_DWORD*)& byte_5D4594[2614252] || !sub_419130(*(_DWORD*)& byte_5D4594[2614252] + 24)))
        goto LABEL_45;
    if (!sub_40A5C0(1))
    {
        v15 = *(_DWORD*)& byte_5D4594[2614252] + 24;
    LABEL_34:
        if (v15)
        {
            v16 = 0;
            v17 = sub_418AB0(*(unsigned __int8*)(v15 + 4));
            if (v17 && sub_495A80(*(_DWORD*)(v2 + 128)))
                v16 = 1;
            if ((!sub_40A5C0(4096) || !(*(_BYTE*)(v2 + 112) & 2) || !(*(_BYTE*)(v2 + 116) & 8)) && v16)
            {
                v18 = (int*)sub_418D50((int)v17);
                v19 = *v12 + *(_DWORD*)(v2 + 12) - v12[4];
                v20 = *(_DWORD*)(v2 + 16) + v12[1] - *(__int16*)(v2 + 104) - a1[5] - 2 * sub_419A70(*(float*)(v2 + 100));
                if (v18)
                    sub_434460(*v18);
                sub_4B0BC0(v19, v20, 3);
            }
        }
        goto LABEL_45;
    }
    v13 = sub_417090(31);
    if (v13)
    {
        v14 = *((_DWORD*)v13 + 514);
        if (v14)
        {
            v15 = v14 + 48;
            goto LABEL_34;
        }
    }
LABEL_45:
    sub_434560(0);
    return v23;
}

//----- (004BC490) --------------------------------------------------------
char __cdecl sub_4BC490(int a1)
{
    int v1; // eax
    unsigned int v2; // ecx
    int v3; // eax
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax

    LOBYTE(v1) = byte_5D4594[2598000];
    if (!(byte_5D4594[2598000] & 3) && *(_DWORD*)(a1 + 276) == 8 && *(_DWORD*)(a1 + 116) & 0x40000)
    {
        v2 = *(_DWORD*)(a1 + 308);
        v3 = *(_DWORD*)(a1 + 308);
        if (v3)
        {
            v4 = v3 - 2;
            if (v4)
            {
                if (v4 == 2)
                {
                    v1 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\mondraw.c", 74);
                    if (v1 < 15)
                    {
                        v5 = *(_DWORD*)(a1 + 308);
                        *(_BYTE*)(a1 + 299) = 0;
                        v1 = v5 - 1;
                        *(_DWORD*)(a1 + 308) = v1;
                    }
                }
                else
                {
                    LOBYTE(v1) = *(_BYTE*)(a1 + 299);
                    switch ((_BYTE)v1)
                    {
                    case 0:
                        if (v2 < 2)
                        {
                            *(_DWORD*)(a1 + 308) = v2 + 1;
                            return v1;
                        }
                    LABEL_11:
                        *(_DWORD*)(a1 + 308) = v2 - 1;
                        return v1;
                    case 1:
                        goto LABEL_11;
                    case 2:
                        *(_DWORD*)(a1 + 308) = v2 + 1;
                        break;
                    default:
                        *(_DWORD*)(a1 + 308) = 2;
                        *(_BYTE*)(a1 + 299) = 0;
                        break;
                    }
                }
            }
            else
            {
                v1 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\mondraw.c", 52);
                if (v1 >= 5)
                {
                    if (v1 < 10)
                    {
                        v7 = *(_DWORD*)(a1 + 308);
                        *(_BYTE*)(a1 + 299) = 2;
                        v1 = v7 + 1;
                        *(_DWORD*)(a1 + 308) = v1;
                    }
                }
                else
                {
                    v6 = *(_DWORD*)(a1 + 308);
                    *(_BYTE*)(a1 + 299) = 1;
                    v1 = v6 - 1;
                    *(_DWORD*)(a1 + 308) = v1;
                }
            }
        }
        else
        {
            v1 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\mondraw.c", 66);
            if (v1 < 15)
            {
                v8 = *(_DWORD*)(a1 + 308);
                *(_BYTE*)(a1 + 299) = 0;
                v1 = v8 + 1;
                *(_DWORD*)(a1 + 308) = v1;
            }
        }
    }
    return v1;
}

//----- (004BC5D0) --------------------------------------------------------
int __cdecl sub_4BC5D0(_DWORD* a1, int a2)
{
    int result; // eax
    int v3; // ecx
    int v4; // ecx

    switch (*(_DWORD*)(a2 + 44))
    {
    case 0:
        result = (*(_DWORD*)& byte_5D4594[2598000] - a1[79]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
        v4 = *(__int16*)(a2 + 40);
        if (result >= v4)
            result = v4 - 1;
        break;
    case 1:
        result = (*(_DWORD*)& byte_5D4594[2598000] - a1[79]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
        if (result >= *(__int16*)(a2 + 40))
        {
            sub_45A4E0((int)a1);
            result = -1;
        }
        break;
    case 2:
        result = (*(_DWORD*)& byte_5D4594[2598000] + a1[32]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
        v3 = *(__int16*)(a2 + 40);
        if (result >= v3)
            result %= v3;
        break;
    case 4:
        result = sub_415FF0(0, *(__int16*)(a2 + 40) - 1, "C:\\NoxPost\\src\\Client\\Draw\\vectdraw.c", 19);
        break;
    case 5:
        result = a1[77];
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (004BC6B0) --------------------------------------------------------
int __cdecl sub_4BC6B0(int* a1, int a2, int a3)
{
    int v3; // eax

    v3 = sub_4BC5D0((_DWORD*)a2, a3);
    if (v3 < 0)
        return 0;
    sub_4C4770(a1, (unsigned __int8*)a2, *(_DWORD*)(*(_DWORD*)(a3 + 4 * *(unsigned __int8*)(a2 + 297) + 4) + 4 * v3));
    return 1;
}

//----- (004BC700) --------------------------------------------------------
int __cdecl nox_thing_vector_animate_draw(int* a1, int a2)
{
    return sub_4BC6B0(a1, a2, *(_DWORD*)(a2 + 304));
}

//----- (004BC720) --------------------------------------------------------
int __cdecl sub_4BC720(int a1)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 304);
    *(_DWORD*)(a1 + 432) = *(unsigned __int8*)(result + 27) * (*(unsigned __int8*)(result + 32) + 1);
    return result;
}

//----- (004BC750) --------------------------------------------------------
int __cdecl nox_thing_monster_gen_draw(int* a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int v4; // edi
    int v5; // eax
    int v6; // ebx
    int v7; // eax
    int v8; // ecx
    unsigned int v9; // ecx
    int v10; // ebp
    int v11; // ebp
    int v12; // ecx
    int v13; // eax
    signed int v14; // ecx
    signed int v15; // eax
    int v16; // eax
    int v17; // eax
    int result; // eax
    unsigned __int8* v19; // [esp+10h] [ebp-8h]
    int v20; // [esp+14h] [ebp-4h]
    unsigned __int8* v21; // [esp+20h] [ebp+8h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 280);
    v4 = *(_DWORD*)(a2 + 304);
    if (v3 & 0x100)
    {
        v5 = 1;
    }
    else if (v3 & 0x200)
    {
        v5 = 2;
    }
    else
    {
        v5 = (*(_DWORD*)(a2 + 280) & 0xC00) != 0 ? 3 : 0;
    }
    v6 = *(unsigned __int8*)(v5 + v4 + 24);
    v19 = (unsigned __int8*)(v5 + v4 + 24);
    v21 = (unsigned __int8*)(v5 + v4 + 29);
    v20 = *(_DWORD*)(v4 + 4 * v5 + 4);
    switch (*(_DWORD*)(v4 + 4 * v5 + 36))
    {
    case 0:
        v7 = v5 + v4 + 29;
        goto LABEL_12;
    case 2:
        v7 = (*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(v2 + 128))
            / ((unsigned int) * (unsigned __int8*)(v5 + v4 + 29) + 1);
        if (v7 >= v6)
            v7 %= v6;
        goto LABEL_12;
    case 4:
        v7 = sub_415FF0(0, v6, "C:\\NoxPost\\src\\client\\Draw\\MGenDraw.c", 86);
        goto LABEL_12;
    case 5:
        v7 = *(_DWORD*)(v2 + 308);
    LABEL_12:
        v8 = *(_DWORD*)(v2 + 280);
        if (v8 & 0x800)
        {
            v9 = *(_DWORD*)(v2 + 120) & 0xDFFFFFFF;
            v7 = v6 - 1;
            *(_DWORD*)(v2 + 112) &= 0xFFF7FFFF;
            *(_DWORD*)(v2 + 120) = v9;
        }
        v10 = *(_DWORD*)(v2 + 432);
        if (v10)
        {
            v7 = ((*v21 + 1) * (unsigned int)* v19 - v10) / ((unsigned int)* v21 + 1);
            if (v7 >= v6)
                v7 = v6 - 1;
            if (v7 < 0)
                v7 = 0;
            v11 = v10 - 1;
            *(_DWORD*)(v2 + 432) = v11;
            if (!v11)
            {
                v12 = *(_DWORD*)(v2 + 280);
                BYTE1(v12) = BYTE1(v12) & 0xFB | 8;
                *(_DWORD*)(v2 + 280) = v12;
            }
        }
        sub_4C4770(a1, (unsigned __int8*)v2, *(_DWORD*)(v20 + 4 * v7));
        v13 = *(_DWORD*)(v2 + 280);
        if (!(v13 & 0xC00))
        {
            v14 = *(unsigned __int8*)(v4 + 28);
            v15 = (*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(v2 + 128))
                / ((unsigned int) * (unsigned __int8*)(v4 + 33) + 1);
            if (v15 >= v14)
                v15 %= v14;
            sub_4C4770(a1, (unsigned __int8*)v2, *(_DWORD*)(*(_DWORD*)(v4 + 20) + 4 * v15));
        }
        v16 = *(_DWORD*)(v2 + 280);
        if (v16 & 0x800)
        {
            v17 = *(_DWORD*)(v2 + 120);
            LOBYTE(v17) = v17 | 1;
            *(_DWORD*)(v2 + 120) = v17;
        }
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (004BC920) --------------------------------------------------------
int sub_4BC920()
{
    return 1;
}

//----- (004BC930) --------------------------------------------------------
int __cdecl nox_thing_cond_animate_draw(int* a1, int a2)
{
    int v2; // eax
    int v3; // edi
    int v4; // ecx
    int v5; // esi
    int v6; // edx
    int v7; // edx
    int v8; // edx
    signed int v10; // eax

    v2 = *(_DWORD*)(a2 + 304);
    if (*(_DWORD*)(a2 + 120) & 0x1000000)
    {
        v3 = *(_DWORD*)(v2 + 4);
        v4 = *(unsigned __int8*)(v2 + 24);
        v5 = *(unsigned __int8*)(v2 + 29);
        v6 = *(_DWORD*)(v2 + 36);
    }
    else
    {
        v3 = *(_DWORD*)(v2 + 8);
        v4 = *(unsigned __int8*)(v2 + 25);
        v5 = *(unsigned __int8*)(v2 + 30);
        v6 = *(_DWORD*)(v2 + 40);
    }
    v7 = v6 - 2;
    if (v7)
    {
        v8 = v7 - 2;
        if (v8)
        {
            if (v8 != 1)
                return 0;
            v10 = *(_DWORD*)(a2 + 308);
        }
        else
        {
            v10 = sub_415FF0(0, v4, "C:\\NoxPost\\src\\client\\Draw\\CAniDraw.c", 57);
        }
    }
    else
    {
        v10 = (*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(a2 + 128)) / (unsigned int)(v5 + 1);
        if (v10 >= v4)
            v10 %= v4;
    }
    sub_4C4770(a1, (unsigned __int8*)a2, *(_DWORD*)(v3 + 4 * v10));
    return 1;
}

//----- (004BC9E0) --------------------------------------------------------
int __cdecl nox_thing_door_draw(int* a1, int a2)
{
    _BYTE* v2; // edi
    int v3; // eax
    int v4; // edx
    int v5; // ecx
    char v6; // al
    char v7; // dl
    char v9; // dl
    char v10; // dl
    char v11; // dl
    int v12; // [esp-4h] [ebp-18h]
    int v13; // [esp-4h] [ebp-18h]
    int v14; // [esp-4h] [ebp-18h]
    int v15; // [esp-4h] [ebp-18h]
    int2 a3; // [esp+Ch] [ebp-8h]

    sub_4C4770(
        a1,
        (unsigned __int8*)a2,
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a2 + 304) + 4) + 4 * *(unsigned __int8*)(a2 + 299)));
    if (!sub_40A5C0(4096) || *(_BYTE*)(a2 + 432) != 1)
        return 1;
    if (!*(_DWORD*)(a2 + 436))
    {
        *(_DWORD*)(a2 + 440) = sub_42F970("DoorLockSilverSW");
        *(_DWORD*)(a2 + 436) = sub_42F970("DoorLockSilverSE");
        *(_DWORD*)(a2 + 444) = sub_42F970("DoorLockGoldSW");
        *(_DWORD*)(a2 + 448) = sub_42F970("DoorLockGoldSE");
    }
    sub_4739E0(a1, (int2*)(a2 + 12), &a3);
    a3.field_0 -= 64;
    a3.field_4 -= 79;
    v2 = (_BYTE*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])((int2*)(a2 + 12));
    v3 = sub_4345F0(1);
    LOBYTE(v4) = v2[8];
    LOBYTE(v3) = v2[4];
    LOBYTE(v5) = *v2;
    sub_433CD0(v5, v3, v4);
    v6 = *(_BYTE*)(a2 + 299);
    if (!v6)
    {
        v7 = *(_BYTE*)(a2 + 433);
        v12 = a3.field_4 - 20;
        a3.field_0 -= 15;
        a3.field_4 -= 20;
        if (v7 == 1)
            sub_47D2C0(*(_DWORD*)(a2 + 440), a3.field_0, v12);
        else
            sub_47D2C0(*(_DWORD*)(a2 + 444), a3.field_0, v12);
        return 1;
    }
    if (v6 == 8)
    {
        v9 = *(_BYTE*)(a2 + 433);
        v13 = a3.field_4 - 20;
        a3.field_0 += 15;
        a3.field_4 -= 20;
        if (v9 == 1)
            sub_47D2C0(*(_DWORD*)(a2 + 436), a3.field_0, v13);
        else
            sub_47D2C0(*(_DWORD*)(a2 + 448), a3.field_0, v13);
        return 1;
    }
    if (v6 != 16)
    {
        v11 = *(_BYTE*)(a2 + 433);
        v15 = a3.field_4 + 2;
        a3.field_0 -= 8;
        a3.field_4 += 2;
        if (v11 == 1)
        {
            sub_47D2C0(*(_DWORD*)(a2 + 436), a3.field_0, v15);
            return 1;
        }
        sub_47D2C0(*(_DWORD*)(a2 + 448), a3.field_0, v15);
        return 1;
    }
    v10 = *(_BYTE*)(a2 + 433);
    v14 = a3.field_4 + 2;
    a3.field_0 += 8;
    a3.field_4 += 2;
    if (v10 == 1)
        sub_47D2C0(*(_DWORD*)(a2 + 440), a3.field_0, v14);
    else
        sub_47D2C0(*(_DWORD*)(a2 + 444), a3.field_0, v14);
    return 1;
}
// 4BCABD: variable 'v5' is possibly undefined
// 4BCABD: variable 'v4' is possibly undefined

//----- (004BCC20) --------------------------------------------------------
int __cdecl nox_thing_static_draw(int* a1, int a2)
{
    if (!(*(_DWORD*)(a2 + 112) & 0x40000) || *(_DWORD*)(a2 + 120) & 0x1000000)
        sub_4C4770(a1, (unsigned __int8*)a2, *(_DWORD*)(*(_DWORD*)(a2 + 304) + 4));
    return 1;
}

//----- (004BCC60) --------------------------------------------------------
int __cdecl nox_thing_static_random_draw(int* a1, int a2)
{
    sub_4C4770(a1, (unsigned __int8*)a2, *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a2 + 304) + 4) + 4 * *(_DWORD*)(a2 + 308)));
    return 1;
}

//----- (004BCC90) --------------------------------------------------------
int __cdecl nox_thing_debug_draw(_DWORD* a1, int a2)
{
    int v2; // edi
    int v3; // ebx
    int v4; // eax
    int v5; // ecx
    int v6; // edx
    int v7; // eax
    int v8; // edi
    int v9; // ebx
    int v10; // eax
    int v11; // ebp
    int v12; // eax
    int v13; // eax
    int v14; // eax
    float v16; // [esp-8h] [ebp-38h]
    int2 a2a; // [esp+10h] [ebp-20h]
    int v18; // [esp+1Ch] [ebp-14h]
    int v19; // [esp+20h] [ebp-10h]
    int v20; // [esp+28h] [ebp-8h]

    v2 = *(_DWORD*)& byte_5D4594[2618904];
    if (*(_DWORD*)(a2 + 288) >= *(int*)& byte_5D4594[2598000])
        v2 = *(_DWORD*)& byte_5D4594[2589772];
    sub_434460(v2);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v3 = *(_DWORD*)(a2 + 16);
    v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    v5 = *(_DWORD*)(a2 + 112);
    v6 = a1[1] - a1[5];
    a2a.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
    a2a.field_4 = v3 + v6;
    if ((v5 & 0x80u) == 0)
    {
        if (v5 & 2)
        {
            sub_4BD010(a2, &a2a, v2);
            sub_49F500(a2a.field_0, a2a.field_4);
            sub_49F570(
                *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 179880],
                *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 179884]);
            sub_49E4B0();
            nox_swprintf((wchar_t*)& byte_5D4594[1316540], L"%d", *(_DWORD*)(a2 + 128));
            sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4 - 10);
            v12 = nox_get_thing_name(*(_DWORD*)(a2 + 108));
            nox_swprintf((wchar_t*)& byte_5D4594[1316540], L"%S", v12);
            sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4);
            nox_swprintf(
                (wchar_t*)& byte_5D4594[1316540],
                L"%S",
                *(_DWORD*)& byte_587000[4 * *(_DWORD*)(a2 + 276) + 178920]);
            sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4 + 10);
        }
        else if (v5 & 4)
        {
            sub_4BD010(a2, &a2a, v2);
            sub_49F500(a2a.field_0, a2a.field_4);
            sub_49F570(
                *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 179880],
                *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 179884]);
            sub_49E4B0();
            nox_swprintf((wchar_t*)& byte_5D4594[1316540], L"%d", *(_DWORD*)(a2 + 128));
            sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4 - 10);
            v13 = nox_get_thing_name(*(_DWORD*)(a2 + 108));
            nox_swprintf((wchar_t*)& byte_5D4594[1316540], L"%S", v13);
            sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4);
            nox_swprintf(
                (wchar_t*)& byte_5D4594[1316540],
                L"%S",
                *(_DWORD*)& byte_587000[4 * *(_DWORD*)(a2 + 276) + 178696]);
            sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4 + 10);
        }
        else
        {
            sub_4BD010(a2, &a2a, v2);
        }
    }
    else
    {
        v20 = v4;
        v7 = sub_419A70(*(float*)(a2 + 100));
        v16 = *(float*)(a2 + 96);
        v8 = a2a.field_4 - v7;
        v19 = a2a.field_0;
        v9 = a2a.field_4 - sub_419A70(v16);
        v10 = 8 * *(unsigned __int8*)(a2 + 299);
        v11 = *(int*)& byte_587000[v10 + 196184];
        v18 = *(int*)& byte_587000[v10 + 196188];
        sub_49F500(a2a.field_0, v9);
        sub_49F570(v11, v18);
        sub_49E4B0();
        sub_49F500(v20, v8);
        sub_49F570(v11, v18);
        sub_49E4B0();
        sub_49F500(a2a.field_0, v9);
        sub_49F500(v20, v8);
        sub_49E4B0();
        sub_49F500(a2a.field_0 + v11, v9 + v18);
        sub_49F500(v20 + v11, v8 + v18);
        sub_49E4B0();
    }
    nox_swprintf((wchar_t*)& byte_5D4594[1316540], L"%d", *(_DWORD*)(a2 + 128));
    sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4 - 10);
    v14 = nox_get_thing_name(*(_DWORD*)(a2 + 108));
    nox_swprintf((wchar_t*)& byte_5D4594[1316540], L"%S", v14);
    sub_43F6E0(0, (__int16*)& byte_5D4594[1316540], a2a.field_0, a2a.field_4);
    return 1;
}

//----- (004BD010) --------------------------------------------------------
int __cdecl sub_4BD010(int a1, int2* a2, int a3)
{
    int v3; // esi
    int result; // eax
    int2* v5; // edi
    int v6; // eax
    int v7; // edx
    int v8; // eax
    int v9; // ebx
    int v10; // ebp
    int v11; // esi
    float v12; // [esp+0h] [ebp-24h]
    float v13; // [esp+0h] [ebp-24h]
    int v14; // [esp+4h] [ebp-20h]
    float v15; // [esp+4h] [ebp-20h]
    float v16; // [esp+4h] [ebp-20h]
    int2 v17; // [esp+14h] [ebp-10h]
    int2 v18; // [esp+1Ch] [ebp-8h]
    int v19; // [esp+28h] [ebp+4h]
    int2* a2a; // [esp+2Ch] [ebp+8h]

    v3 = a1;
    if (*(_DWORD*)(a1 + 44) == 2)
    {
        v9 = (__int64) * (float*)(a1 + 48);
        v12 = *(float*)(a1 + 100) - (double) * (__int16*)(a1 + 104);
        v10 = a2->field_4 - sub_419A70(v12);
        v19 = a2->field_4;
        v13 = *(float*)(v3 + 96) - (double) * (__int16*)(v3 + 104);
        v11 = v19 - sub_419A70(v13);
        if (v11 > 0)
            sub_4C3270(a2->field_0, v19, v9, *(int*)& byte_5D4594[2650644]);
        sub_4C3270(a2->field_0, v11, v9, a3);
        sub_4C3270(a2->field_0, v10, v9, a3);
        sub_434460(a3);
        sub_49F500(a2->field_0 - v9, v11);
        sub_49F500(a2->field_0 - v9, v10);
        sub_49E4B0();
        sub_49F500(v9 + a2->field_0, v11);
        sub_49F500(v9 + a2->field_0, v10);
        result = sub_49E4B0();
    }
    else
    {
        result = *(_DWORD*)(a1 + 44) - 3;
        if (*(_DWORD*)(a1 + 44) == 3)
        {
            v5 = a2;
            v14 = *(__int16*)(a1 + 104);
            v18.field_0 = a2->field_0;
            v15 = *(float*)(a1 + 100) - (double)v14;
            v6 = sub_419A70(v15);
            a2a = (int2*) * (__int16*)(a1 + 104);
            v7 = v5->field_4 - v6;
            v8 = v5->field_0;
            v18.field_4 = v7;
            v17.field_0 = v8;
            v16 = *(float*)(a1 + 96) - (double)(int)a2a;
            v17.field_4 = v5->field_4 - sub_419A70(v16);
            if (v17.field_4 > 0)
                sub_4CEA90((float*)(a1 + 64), v5, *(int*)& byte_5D4594[2650644]);
            sub_4CEA90((float*)(a1 + 64), &v17, a3);
            sub_4CEA90((float*)(a1 + 64), &v18, a3);
            sub_434460(a3);
            sub_49F500(
                v17.field_0 + (unsigned __int64)(__int64) * (float*)(a1 + 72),
                v17.field_4 + (unsigned __int64)(__int64) * (float*)(a1 + 76));
            sub_49F500(
                v18.field_0 + (unsigned __int64)(__int64) * (float*)(a1 + 72),
                v18.field_4 + (unsigned __int64)(__int64) * (float*)(a1 + 76));
            sub_49E4B0();
            sub_49F500(
                v17.field_0 + (unsigned __int64)(__int64) * (float*)(a1 + 80),
                v17.field_4 + (unsigned __int64)(__int64) * (float*)(a1 + 84));
            sub_49F500(
                v18.field_0 + (unsigned __int64)(__int64) * (float*)(a1 + 80),
                v18.field_4 + (unsigned __int64)(__int64) * (float*)(a1 + 84));
            sub_49E4B0();
            sub_49F500(
                v17.field_0 + (unsigned __int64)(__int64) * (float*)(a1 + 88),
                v17.field_4 + (unsigned __int64)(__int64) * (float*)(a1 + 92));
            sub_49F500(
                v18.field_0 + (unsigned __int64)(__int64) * (float*)(a1 + 88),
                v18.field_4 + (unsigned __int64)(__int64) * (float*)(a1 + 92));
            result = sub_49E4B0();
        }
    }
    return result;
}

//----- (004BD280) --------------------------------------------------------
_DWORD* __cdecl sub_4BD280(int a1, int a2)
{
    int v2; // esi
    _DWORD* result; // eax
    _DWORD* v4; // ecx
    int v5; // edi

    v2 = a2 + 4;
    result = nox_malloc(a1 * (a2 + 4) + 4);
    if (result)
    {
        v4 = result + 1;
        *result = result + 1;
        if (a1 != 1)
        {
            v5 = a1 - 1;
            do
            {
                --v5;
                *v4 = (char*)v4 + v2;
                v4 = (_DWORD*)((char*)v4 + v2);
            } while (v5);
        }
        *v4 = 0;
    }
    return result;
}

//----- (004BD2D0) --------------------------------------------------------
void __cdecl sub_4BD2D0(LPVOID lpMem)
{
    free(lpMem);
}

//----- (004BD2E0) --------------------------------------------------------
_DWORD* __cdecl sub_4BD2E0(_DWORD** a1)
{
    _DWORD* result; // eax
    _DWORD* v2; // edx

    result = *a1;
    if (*a1)
    {
        v2 = (_DWORD*)* result;
        ++result;
        *a1 = v2;
    }
    return result;
}

//----- (004BD300) --------------------------------------------------------
int __cdecl sub_4BD300(_DWORD* a1, int a2)
{
    int result; // eax

    result = a2 - 4;
    *(_DWORD*)(a2 - 4) = *a1;
    *a1 = a2 - 4;
    return result;
}

//----- (004BD320) --------------------------------------------------------
int __cdecl sub_4BD320(_DWORD** a1)
{
    int result; // eax
    _DWORD* i; // ecx

    result = 0;
    for (i = *a1; i; ++result)
        i = (_DWORD*)* i;
    return result;
}

//----- (004BD340) --------------------------------------------------------
_DWORD* __cdecl sub_4BD340(int a1, int a2, int a3, int a4)
{
    _DWORD* v4; // esi

    v4 = nox_malloc(0x1Cu);
    memset(v4, 0, 0x1Cu);
    *v4 = a1;
    v4[6] = a4;
    v4[1] = sub_4BD280(a2 / (a4 + 24), a4 + 24);
    v4[2] = sub_4BD280(a3, 84);
    sub_425760(v4 + 3);
    if (v4[1] && v4[2])
        return v4;
    sub_4BD3C0(v4);
    return 0;
}

//----- (004BD3C0) --------------------------------------------------------
void __cdecl sub_4BD3C0(LPVOID lpMem)
{
    int i; // eax

    for (i = sub_425940((int*)lpMem + 3); i; i = sub_425940((int*)lpMem + 3))
        sub_4BD690(i);
    if (*((_DWORD*)lpMem + 1))
        sub_4BD2D0(*((LPVOID*)lpMem + 1));
    if (*((_DWORD*)lpMem + 2))
        sub_4BD2D0(*((LPVOID*)lpMem + 2));
    free(lpMem);
}

//----- (004BD420) --------------------------------------------------------
_DWORD* __cdecl sub_4BD420(int a1, int a2)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)(a1 + 12);
    if (result == (_DWORD*)(a1 + 12))
        return 0;
    while (result[4] != a2 || !result[5])
    {
        result = (_DWORD*)* result;
        if (result == (_DWORD*)(a1 + 12))
            return 0;
    }
    return result;
}

//----- (004BD450) --------------------------------------------------------
_DWORD* __cdecl sub_4BD450(int a1)
{
    _DWORD* result; // eax

    for (result = *(_DWORD * *)(a1 + 12); result != (_DWORD*)(a1 + 12); result = (_DWORD*)* result)
        result[5] = 0;
    return result;
}

//----- (004BD470) --------------------------------------------------------
_DWORD* __cdecl sub_4BD470(_DWORD** a1, int a2)
{
    _DWORD* v2; // eax
    _DWORD* v3; // edi
    _DWORD* v5; // ebx
    _DWORD* v6; // eax
    _DWORD* v7; // ebp
    char* v8; // edi
    signed int v9; // eax
    _DWORD* v10; // [esp+18h] [ebp+8h]

    v2 = sub_4BD420((int)a1, a2);
    v3 = v2;
    if (v2)
    {
        sub_425920((_DWORD * *)v2);
        sub_425900(a1 + 3, v3);
        return v3;
    }
    if (sub_486B60((int)* a1, a2))
    {
        v5 = sub_4BD2E0((_DWORD * *)a1[2]);
        if (!v5)
        {
            sub_4BD600((int)a1);
            v5 = sub_4BD2E0((_DWORD * *)a1[2]);
            if (!v5)
            {
                sub_486E00((int)* a1);
                return 0;
            }
        }
        v5[4] = a2;
        v5[13] = a1;
        sub_425770(v5);
        v5[3] = 0;
        sub_487C30(v5 + 6);
        nullsub_10(v5 + 14);
        v5[11] = v5 + 14;
        v6 = (_DWORD*)(*a1)[71];
        v10 = (_DWORD*)(*a1)[71];
        if (!v6)
        {
        LABEL_19:
            sub_486AA0(*a1, v5[4], v5 + 14);
            sub_425900(a1 + 3, v5);
            v5[5] = 1;
            sub_486E00((int)* a1);
            return v5;
        }
        while (1)
        {
            v7 = a1[6];
            if ((int)v7 > (int)v6)
                v7 = v6;
            v8 = (char*)sub_4BD2E0((_DWORD * *)a1[1]);
            if (!v8)
                break;
        LABEL_17:
            sub_487D30(v8, (int)(v8 + 24), (int)v7);
            sub_487C50((int)(v5 + 6), v8);
            v9 = sub_486DB0((int)* a1, v8 + 24, (signed int)v7);
            if ((_DWORD*)v9 != v7)
                goto LABEL_20;
            v10 = (_DWORD*)((char*)v10 - v9);
            if (!v10)
                goto LABEL_19;
            v6 = v10;
        }
        while (sub_4BD600((int)a1))
        {
            v8 = (char*)sub_4BD2E0((_DWORD * *)a1[1]);
            if (v8)
                goto LABEL_17;
        }
    LABEL_20:
        sub_4BD690((int)v5);
    }
    return 0;
}
// 487CF0: using guessed type void __cdecl nullsub_10(_DWORD);

//----- (004BD600) --------------------------------------------------------
int __cdecl sub_4BD600(int a1)
{
    int v1; // esi

    v1 = sub_425960(a1 + 12);
    if (!v1)
        return 0;
    while (sub_4BD680(v1))
    {
        v1 = sub_425960(v1);
        if (!v1)
            return 0;
    }
    sub_4BD690(v1);
    return 1;
}

//----- (004BD650) --------------------------------------------------------
int __cdecl sub_4BD650(int a1)
{
    int result; // eax

    result = a1;
    ++* (_DWORD*)(a1 + 12);
    return result;
}

//----- (004BD660) --------------------------------------------------------
int __cdecl sub_4BD660(int a1)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 12) - 1;
    *(_DWORD*)(a1 + 12) = result;
    if (result < 0)
        * (_DWORD*)(a1 + 12) = 0;
    return result;
}

//----- (004BD680) --------------------------------------------------------
int __cdecl sub_4BD680(int a1)
{
    return *(_DWORD*)(a1 + 12);
}

//----- (004BD690) --------------------------------------------------------
int __cdecl sub_4BD690(int a1)
{
    _DWORD** i; // esi

    if (*(_DWORD*)(a1 + 4) != a1)
        sub_425920((_DWORD * *)a1);
    for (i = (_DWORD * *)sub_425940((int*)(a1 + 32)); i; i = (_DWORD * *)sub_425940((int*)(a1 + 32)))
    {
        sub_425920(i);
        sub_487D60((int)i);
        sub_4BD300(*(_DWORD * *)(*(_DWORD*)(a1 + 52) + 4), (int)i);
    }
    nullsub_9(a1 + 24);
    return sub_4BD300(*(_DWORD * *)(*(_DWORD*)(a1 + 52) + 8), a1);
}
// 487CA0: using guessed type void __cdecl nullsub_9(_DWORD);

//----- (004BD700) --------------------------------------------------------
int __cdecl sub_4BD700(int a1)
{
    return *(int*)(a1 + 16);
}

//----- (004BD710) --------------------------------------------------------
int __cdecl sub_4BD710(int a1)
{
    return a1 + 24;
}

//----- (004BD720) --------------------------------------------------------
_DWORD* __cdecl sub_4BD720(int a1)
{
    _DWORD* v1; // esi

    v1 = nox_malloc(0x138u);
    memset(v1, 0, 0x138u);
    sub_425770(v1);
    sub_4BDC00((int)(v1 + 30));
    sub_4864A0(v1 + 44);
    sub_4BD7C0(v1);
    v1[33] = a1;
    v1[43] = *(_DWORD*)(a1 + 256);
    if (!(*(int(__cdecl * *)(_DWORD*))(*(_DWORD*)(a1 + 256) + 4))(v1))
        return v1;
    if (v1)
        sub_4BD7A0(v1);
    return 0;
}

//----- (004BD7A0) --------------------------------------------------------
void __cdecl sub_4BD7A0(LPVOID lpMem)
{
    (*(void(__cdecl * *)(LPVOID))(*((_DWORD*)lpMem + 43) + 8))(lpMem);
    free(lpMem);
}

//----- (004BD7C0) --------------------------------------------------------
_DWORD* __cdecl sub_4BD7C0(_DWORD* a1)
{
    _DWORD* result; // eax

    a1[69] = sub_4BD8C0;
    a1[70] = sub_4BD940;
    a1[71] = sub_4BD9B0;
    a1[34] = 0;
    a1[35] = 0;
    a1[36] = 0;
    a1[38] = 0;
    a1[3] = 1;
    sub_4BDC00((int)(a1 + 30));
    a1[30] = 0;
    a1[29] = *(_DWORD*)& byte_5D4594[1193340];
    a1[28] = 0;
    result = sub_4864A0(a1 + 4);
    a1[72] = 0;
    return result;
}

//----- (004BD840) --------------------------------------------------------
int __cdecl sub_4BD840(int a3)
{
    int v1; // ebp
    unsigned int* v2; // edi
    _DWORD* v3; // esi
    int result; // eax

    v1 = *(_DWORD*)(a3 + 132);
    v2 = (unsigned int*)(a3 + 176);
    sub_4864A0((_DWORD*)(a3 + 176));
    sub_486570((unsigned int*)(a3 + 176), (_DWORD*)(a3 + 16));
    sub_486620((_DWORD*)(a3 + 16));
    if (*(_DWORD*)(a3 + 112))
    {
        sub_486570(v2, *(_DWORD * *)(a3 + 112));
        sub_486620(*(_DWORD * *)(a3 + 112));
    }
    v3 = *(_DWORD * *)(a3 + 116);
    if (v3)
        sub_486570(v2, v3);
    sub_486570(v2, (_DWORD*)(v1 + 88));
    result = *(_DWORD*)(v1 + 184);
    if (result)
        result = sub_486570(v2, *(_DWORD * *)(v1 + 184));
    return result;
}

//----- (004BD8C0) --------------------------------------------------------
int __cdecl sub_4BD8C0(int a1)
{
    int(__cdecl * v1)(int); // eax
    int result; // eax
    int v3; // eax
    int v4; // eax

    v1 = *(int(__cdecl * *)(int))(a1 + 136);
    if (v1)
    {
        result = v1(a1);
        if (result)
        {
            *(_DWORD*)(a1 + 300) = 0;
            *(_DWORD*)(a1 + 304) = 0;
            *(_DWORD*)(a1 + 296) = 0;
            return result;
        }
    }
    else
    {
        if (*(_DWORD*)(a1 + 292))
        {
            v3 = sub_425940(*(int**)(a1 + 292));
            *(_DWORD*)(a1 + 292) = v3;
            if (v3)
            {
                *(_DWORD*)(a1 + 296) = *(_DWORD*)(v3 + 12);
                v4 = *(_DWORD*)(v3 + 16);
                *(_DWORD*)(a1 + 300) = v4;
                *(_DWORD*)(a1 + 304) = v4;
                return 0;
            }
        }
        *(_DWORD*)(a1 + 300) = 0;
    }
    return 0;
}

//----- (004BD940) --------------------------------------------------------
int __cdecl sub_4BD940(int a1)
{
    void(__cdecl * v1)(int); // eax

    if (*(_DWORD*)(a1 + 128))
    {
        if (*(int*)(a1 + 128) != -1)
            --* (_DWORD*)(a1 + 128);
        sub_4BDB90((_DWORD*)a1, *(_DWORD * *)(a1 + 288));
    }
    else
    {
        sub_4BDB90((_DWORD*)a1, 0);
    }
    v1 = *(void(__cdecl * *)(int))(a1 + 140);
    if (v1)
        v1(a1);
    if (*(_DWORD*)(a1 + 288))
        (*(void(__cdecl * *)(int))(*(_DWORD*)(a1 + 172) + 36))(a1);
    return 0;
}

//----- (004BD9B0) --------------------------------------------------------
int __cdecl sub_4BD9B0(_DWORD* a2)
{
    int v1; // eax
    int(__cdecl * v2)(_DWORD*); // eax
    int result; // eax

    a2[72] = 0;
    v1 = a2[31];
    LOBYTE(v1) = v1 & 0xFA;
    a2[31] = v1;
    a2[32] = 0;
    sub_4864A0(a2 + 4);
    v2 = (int(__cdecl*)(_DWORD*))a2[36];
    if (v2)
        result = v2(a2);
    else
        result = 0;
    return result;
}

//----- (004BDA00) --------------------------------------------------------
int __cdecl sub_4BDA00(int a1)
{
    return *(_DWORD*)(a1 + 124) & 8;
}

//----- (004BDA10) --------------------------------------------------------
int __cdecl sub_4BDA10(int a1, int a2)
{
    *(_DWORD*)(a1 + 12) = a2;
    *(_DWORD*)(a1 + 124) |= 8u;
    return sub_4BDA80(a1);
}

//----- (004BDA30) --------------------------------------------------------
_DWORD* __cdecl sub_4BDA30(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    if (a1[31] & 8)
    {
        a1[31] &= 0xFFFFFFF7;
        a1[3] = 1;
        result = sub_4BD7C0(a1);
    }
    return result;
}

//----- (004BDA60) --------------------------------------------------------
void __cdecl sub_4BDA60(LPVOID lpMem)
{
    sub_4BDA80((int)lpMem);
    sub_486E90((int)lpMem);
    sub_4BD7A0(lpMem);
}

//----- (004BDA80) --------------------------------------------------------
int __cdecl sub_4BDA80(int a1)
{
    int result = 0; // eax
    int(__cdecl * result2)(int); // eax

    if (*(_BYTE*)(a1 + 124) & 5)
        (*(void(__cdecl * *)(int))(*(_DWORD*)(a1 + 172) + 16))(a1);
    result2 = *(int(__cdecl * *)(int))(a1 + 148);
    if (result2)
        result = (int)result2(a1);
    *(_DWORD*)(a1 + 288) = 0;
    return result;
}

//----- (004BDAC0) --------------------------------------------------------
void __cdecl sub_4BDAC0(int a1)
{
    int v1; // eax

    if (*(_BYTE*)(a1 + 124) & 1)
    {
        v1 = *(_DWORD*)(a1 + 124);
        LOBYTE(v1) = v1 & 0xFE;
        *(_DWORD*)(a1 + 124) = v1;
        (*(int(__cdecl * *)(int))(*(_DWORD*)(a1 + 172) + 20))(a1);
        *(_DWORD*)(a1 + 124) |= 4u;
    }
}

//----- (004BDAF0) --------------------------------------------------------
void __cdecl sub_4BDAF0(int a1)
{
    if (*(_BYTE*)(a1 + 124) & 4)
    {
        (*(int(__cdecl * *)(int))(*(_DWORD*)(a1 + 172) + 24))(a1);
        *(_DWORD*)(a1 + 124) &= 0xFFFFFFFB;
        *(_DWORD*)(a1 + 124) |= 1u;
    }
}

//----- (004BDB20) --------------------------------------------------------
int __cdecl sub_4BDB20(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 124) |= 0x10u;
    return result;
}

//----- (004BDB30) --------------------------------------------------------
int __cdecl sub_4BDB30(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 124) &= 0xFFFFFFEF;
    return result;
}

//----- (004BDB40) --------------------------------------------------------
int __cdecl sub_4BDB40(int a2)
{
    int result; // eax

    if (*(_BYTE*)(a2 + 124) & 5)
        return -2146500608;
    if (!*(_DWORD*)(a2 + 288))
        return -2147024896;
    sub_486520((unsigned int*)(a2 + 16));
    sub_4BD840(a2);
    result = (*(int(__cdecl * *)(int))(*(_DWORD*)(a2 + 172) + 12))(a2);
    if (!result)
        * (_DWORD*)(a2 + 124) |= 1u;
    return result;
}

//----- (004BDB90) --------------------------------------------------------
void __cdecl sub_4BDB90(_DWORD* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // eax
    _DWORD* v4; // eax
    int v5; // eax

    a1[72] = a2;
    if (a2)
    {
        v2 = sub_487C80((int)a2);
        a1[73] = v2;
        if (v2)
        {
            a1[74] = *(_DWORD*)(v2 + 12);
            v3 = *(_DWORD*)(v2 + 16);
            a1[75] = v3;
            a1[76] = v3;
            *a2 = 0;
        }
        else
        {
            v4 = (_DWORD*)a1[72];
            a1[74] = *v4;
            v5 = v4[1];
            a1[75] = v5;
            a1[76] = v5;
        }
    }
}

//----- (004BDC00) --------------------------------------------------------
int __cdecl sub_4BDC00(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 8) = 0;
    *(_DWORD*)(a1 + 4) = 0;
    return result;
}

//----- (004BDC10) --------------------------------------------------------
int __cdecl sub_4BDC10(int* a1)
{
    *(_DWORD*)& byte_5D4594[1316708] = nox_new_window_from_file("advanced.wnd", sub_4BDDB0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1316708], 0);
    sub_46C690(*(int*)& byte_5D4594[1316708]);
    sub_46A8C0(*(int*)& byte_5D4594[1316708]);
    sub_46B300(*(int*)& byte_5D4594[1316708], sub_4BDDA0);
    sub_46B500(*(int*)& byte_5D4594[1316708]);
    return sub_4BDC70(a1);
}

//----- (004BDC70) --------------------------------------------------------
int __cdecl sub_4BDC70(int* a1)
{
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax

    if (sub_40A5C0(1))
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316708], 10167);
        v1[9] |= 4u;
        *(_DWORD*)& byte_5D4594[1316704] = 0;
    }
    else
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316708], 10164);
        v2[9] |= 4u;
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316708], 10167);
        sub_46ABB0((int)v3, 0);
        *(_DWORD*)& byte_5D4594[1316704] = 1;
    }
    sub_453F70(a1 + 6);
    sub_4535E0(a1 + 11);
    sub_4535F0(a1[12]);
    return sub_4BDD10();
}

//----- (004BDD10) --------------------------------------------------------
int sub_4BDD10()
{
    int v1; // eax
    char* v2; // eax

    switch (*(_DWORD*)& byte_5D4594[1316704])
    {
    case 0:
        v2 = sub_4165B0();
        v1 = sub_4CEBA0(*(int*)& byte_5D4594[1316708], v2);
        goto LABEL_6;
    case 1:
        *(_DWORD*)& byte_5D4594[1316712] = sub_453850(*(int*)& byte_5D4594[1316708]);
        return sub_46B500(*(int*)& byte_5D4594[1316712]);
    case 2:
        v1 = sub_4530C0(*(int*)& byte_5D4594[1316708], 0x1000000);
        goto LABEL_6;
    case 3:
        v1 = sub_4530C0(*(int*)& byte_5D4594[1316708], 0x2000000);
    LABEL_6:
        *(_DWORD*)& byte_5D4594[1316712] = v1;
        break;
    default:
        return sub_46B500(*(int*)& byte_5D4594[1316712]);
    }
    return sub_46B500(*(int*)& byte_5D4594[1316712]);
}

//----- (004BDDA0) --------------------------------------------------------
int sub_4BDDA0()
{
    return 1;
}

//----- (004BDDB0) --------------------------------------------------------
int __cdecl sub_4BDDB0(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int result; // eax
    char* v5; // ebx

    if (a2 == 23)
        return 1;
    if (a2 != 16391)
        return 1;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v3)
    {
    case 10148:
        v5 = sub_4165B0();
        qmemcpy(v5 + 24, sub_453F90(), 0x14u);
        *((_DWORD*)v5 + 11) = *(_DWORD*)sub_453600();
        *((_DWORD*)v5 + 12) = sub_453610();
        sub_4BDF30();
        return 1;
    case 10164:
        if (*(_DWORD*)& byte_5D4594[1316712])
        {
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[1316712]);
            *(_DWORD*)& byte_5D4594[1316712] = 0;
        }
        *(_DWORD*)& byte_5D4594[1316704] = 1;
        sub_4BDD10();
        result = 1;
        break;
    case 10165:
        if (*(_DWORD*)& byte_5D4594[1316712])
        {
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[1316712]);
            *(_DWORD*)& byte_5D4594[1316712] = 0;
        }
        *(_DWORD*)& byte_5D4594[1316704] = 2;
        sub_4BDD10();
        result = 1;
        break;
    case 10166:
        if (*(_DWORD*)& byte_5D4594[1316712])
        {
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[1316712]);
            *(_DWORD*)& byte_5D4594[1316712] = 0;
        }
        *(_DWORD*)& byte_5D4594[1316704] = 3;
        sub_4BDD10();
        result = 1;
        break;
    case 10167:
        if (*(_DWORD*)& byte_5D4594[1316712])
        {
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[1316712]);
            *(_DWORD*)& byte_5D4594[1316712] = 0;
        }
        *(_DWORD*)& byte_5D4594[1316704] = 0;
        sub_4BDD10();
        result = 1;
        break;
    default:
        return 1;
    }
    return result;
}

//----- (004BDF30) --------------------------------------------------------
int sub_4BDF30()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1316708];
    if (*(_DWORD*)& byte_5D4594[1316708])
    {
        sub_46C6E0(*(int*)& byte_5D4594[1316708]);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1316708]);
        *(_DWORD*)& byte_5D4594[1316708] = 0;
        *(_DWORD*)& byte_5D4594[1316712] = 0;
        result = sub_46B500(0);
    }
    return result;
}

//----- (004BDF70) --------------------------------------------------------
int __cdecl sub_4BDF70(int* a1)
{
    int result; // eax

    result = *(int*) & byte_5D4594[1316708];
    if (*(_DWORD*)& byte_5D4594[1316708])
        result = sub_4BDF90(a1);
    return result;
}

//----- (004BDF90) --------------------------------------------------------
int __cdecl sub_4BDF90(int* a1)
{
    int result = 0; // eax
    int (*result2)(void); // eax

    sub_453F70(a1 + 6);
    sub_4535E0(a1 + 11);
    sub_4535F0(a1[12]);
    result2 = *(int (**)(void)) & byte_587000[4 * *(_DWORD*)& byte_5D4594[1316704] + 180016];
    if (result2)
        result = result2();
    return result;
}

//----- (004BDFD0) --------------------------------------------------------
int sub_4BDFD0()
{
    char* v0; // eax
    int v1; // esi
    int v2; // edi
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    int v5; // eax
    _DWORD* v6; // esi
    _DWORD* v7; // eax
    int v9; // [esp+8h] [ebp-8h]
    int v10; // [esp+Ch] [ebp-4h]

    v0 = sub_416640();
    v1 = *(_DWORD*)& byte_587000[26048];
    v2 = (int)v0;
    if (sub_43F320(0) > 10)
        v1 = 2;
    if (sub_43AF70() == 1)
        v3 = nox_new_window_from_file(*(const char**)& byte_587000[4 * v1 + 180088], sub_4BE330);
    else
        v3 = nox_new_window_from_file(*(const char**)& byte_587000[4 * v1 + 180048], sub_4BE330);
    *(_DWORD*)& byte_5D4594[1316972] = v3;
    sub_46B120(v3, 0);
    sub_46C690(*(int*)& byte_5D4594[1316972]);
    sub_46A8C0(*(int*)& byte_5D4594[1316972]);
    sub_46B500(*(int*)& byte_5D4594[1316972]);
    sub_46B300(*(int*)& byte_5D4594[1316972], sub_4BE320);
    v4 = sub_46B0C0(0, 10100);
    sub_46AA20((int)v4, &v10, &v9);
    if (sub_43AF70() == 1)
        v5 = v9 + 55;
    else
        v5 = v9 + 80;
    sub_46A9B0(*(_DWORD * *)& byte_5D4594[1316972], v10 + 15, v5);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2104);
    sub_46B280((int)v6, *(int*)& byte_5D4594[1316972]);
    sub_46B2C0((int)v6, sub_4BE330);
    if (sub_43AF70() == 1)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2119);
        sub_46B280((int)v7, *(int*)& byte_5D4594[1316972]);
    }
    return sub_4BE120(v2);
}

//----- (004BE120) --------------------------------------------------------
int __cdecl sub_4BE120(int a1)
{
    _DWORD* v1; // eax
    int v2; // ecx
    unsigned int v3; // ecx
    _DWORD* v4; // eax
    int v5; // ecx
    unsigned int v6; // ecx
    _DWORD* v7; // esi
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // eax
    _DWORD* v12; // eax
    int result; // eax
    _DWORD* v14; // eax
    int v15; // [esp-14h] [ebp-40h]
    wchar_t v16[16]; // [esp+Ch] [ebp-20h]

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2102);
    v2 = v1[9];
    if (*(_DWORD*)(a1 + 58))
        v3 = v2 | 4;
    else
        v3 = v2 & 0xFFFFFFFB;
    v1[9] = v3;
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2103);
    v5 = v4[9];
    if (*(_DWORD*)(a1 + 62))
        v6 = v5 | 4;
    else
        v6 = v5 & 0xFFFFFFFB;
    v4[9] = v6;
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
    nox_swprintf(v16, L"%d", *(_DWORD*)(a1 + 70));
    nox_window_call_field_94((int)v7, 16414, (int)v16, -1);
    switch (*(_DWORD*)(a1 + 66))
    {
    case 0:
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v8, 0);
        v15 = 2106;
        goto LABEL_12;
    case 1:
        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v9, 0);
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2107);
        goto LABEL_13;
    case 2:
        v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v11, 0);
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2108);
        goto LABEL_13;
    case 3:
        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v12, 1);
        v15 = 2109;
    LABEL_12:
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], v15);
    LABEL_13:
        v10[9] |= 4u;
        break;
    default:
        break;
    }
    result = sub_43AF70();
    if (result == 1)
    {
        v14 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2119);
        nox_window_call_field_94((int)v14, 16394, *(_DWORD*)(a1 + 74), 0);
        result = sub_4BE2C0(*(_DWORD*)(a1 + 74));
    }
    return result;
}

//----- (004BE2C0) --------------------------------------------------------
int __cdecl sub_4BE2C0(int a1)
{
    wchar_t* v1; // eax
    _DWORD* v2; // eax

    *(_DWORD*)(sub_416640() + 74) = a1;
    v1 = loadString_sub_40F1D0((char*)& byte_587000[180448], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\advserv.c", 71);
    nox_swprintf((wchar_t*)& byte_5D4594[1316716], v1, a1);
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2120);
    return nox_window_call_field_94((int)v2, 16385, (int)& byte_5D4594[1316716], -1);
}

//----- (004BE320) --------------------------------------------------------
int sub_4BE320()
{
    return 1;
}

//----- (004BE330) --------------------------------------------------------
int __cdecl sub_4BE330(int a1, unsigned int a2, int* a3, int a4)
{
    _DWORD* v4; // esi
    char* v5; // edi
    int result; // eax
    const wchar_t* v7; // eax
    int v8; // eax
    int v9; // esi
    char* v10; // eax
    char* v11; // eax
    char* v12; // esi
    _DWORD* v13; // eax
    char* v14; // esi
    _DWORD* v15; // eax
    char* v16; // esi
    _DWORD* v17; // eax
    char* v18; // esi
    _DWORD* v19; // eax
    char* v20; // edi
    const wchar_t* v21; // eax
    int v22; // esi

    if (a2 > 0x4007)
    {
        if (a2 == 16393)
        {
            sub_4BE2C0(a4);
            sub_501AC0(a4);
        }
        else if (a2 == 16415)
        {
            v20 = sub_416640();
            v21 = (const wchar_t*)nox_window_call_field_94((int)a3, 16413, 0, 0);
            if (v21)
            {
                if (*v21)
                {
                    v22 = nox_wcstol(v21, 0, 10);
                    if (v22 < 0)
                        v22 = 0;
                    if (sub_46B0A0(a3) == 2110)
                    {
                        *(_DWORD*)(v20 + 70) = v22;
                        return 1;
                    }
                }
            }
        }
        return 1;
    }
    if (a2 != 16391)
    {
        if (a2 != 23 && a2 == 16387)
        {
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], a4);
            v5 = sub_416640();
            if (!v4)
                return 0;
            if ((unsigned __int16)a3 == 1)
                return 0;
            v7 = (const wchar_t*)nox_window_call_field_94((int)v4, 16413, 0, 0);
            if (v7 && *v7)
            {
                v8 = nox_wcstol(v7, 0, 10);
                if (v8 < 0)
                    v8 = 0;
                if (a4 == 2110)
                {
                    *(_DWORD*)(v5 + 70) = v8;
                    return 1;
                }
            }
        }
        return 1;
    }
    v9 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v9)
    {
    case 2102:
        v10 = sub_416640();
        *(_DWORD*)(v10 + 58) ^= 1u;
        result = 1;
        break;
    case 2103:
        v11 = sub_416640();
        *(_DWORD*)(v11 + 62) ^= 1u;
        result = 1;
        break;
    case 2106:
        v12 = sub_416640();
        v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v13, 0);
        *(_DWORD*)(v12 + 66) = 0;
        sub_40A6A0(1);
        result = 1;
        break;
    case 2107:
        v14 = sub_416640();
        v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v15, 0);
        *(_DWORD*)(v14 + 66) = 1;
        sub_40A6A0(1);
        result = 1;
        break;
    case 2108:
        v16 = sub_416640();
        v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v17, 0);
        *(_DWORD*)(v16 + 66) = 2;
        sub_40A6A0(1);
        result = 1;
        break;
    case 2109:
        v18 = sub_416640();
        v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1316972], 2110);
        sub_46ABB0((int)v19, 1);
        *(_DWORD*)(v18 + 66) = 3;
        sub_40A6A0(1);
        result = 1;
        break;
    case 2130:
        sub_4BE610();
        result = 1;
        break;
    default:
        return 1;
    }
    return result;
}

//----- (004BE610) --------------------------------------------------------
int sub_4BE610()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1316972];
    if (*(_DWORD*)& byte_5D4594[1316972])
    {
        sub_46C6E0(*(int*)& byte_5D4594[1316972]);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1316972]);
        *(_DWORD*)& byte_5D4594[1316972] = 0;
        result = sub_46B500(0);
    }
    return result;
}

//----- (004BE640) --------------------------------------------------------
int __cdecl sub_4BE640(int a1, int a2)
{
    unsigned int v2; // ecx
    int result; // eax
    int v4; // esi
    signed int v5; // edi

    v2 = sub_430B40_get_mouse_prev_seq() + a2;
    if (!a1)
        return 0;
    v4 = *(_DWORD*)(a1 + 96);
    if (*(_BYTE*)(v4 + 10))
    {
        if (*(_BYTE*)(v4 + 10) == 2)
            result = *(_DWORD*)(*(_DWORD*)(v4 + 4)
                + 4
                * ((int)(v2 / ((unsigned int) * (unsigned __int8*)(v4 + 9) + 1)) % *(unsigned __int8*)(v4 + 8)));
        else
            result = 0;
    }
    else
    {
        v5 = (v2 - *(_DWORD*)(v4 + 12)) / ((unsigned int) * (unsigned __int8*)(v4 + 9) + 1);
        if (v5 >= *(unsigned __int8*)(v4 + 8) - 1)
        {
            v5 = *(unsigned __int8*)(v4 + 8) - 1;
            if (*(_DWORD*)v4)
                (*(void(__cdecl * *)(int))v4)(a1);
        }
        result = *(_DWORD*)(*(_DWORD*)(v4 + 4) + 4 * v5);
    }
    return result;
}

//----- (004BE6D0) --------------------------------------------------------
__int16 __cdecl sub_4BE6D0(int a1, int a2, int a3)
{
    int v3; // eax

    v3 = sub_4BE640(a1, 0);
    if (v3)
    {
        if (*(_DWORD*)& byte_5D4594[3798728])
            LOWORD(v3) = sub_48B3F0(v3, a2, a3);
        else
            LOWORD(v3) = sub_47D2C0(v3, a2, a3);
    }
    return v3;
}

//----- (004BE710) --------------------------------------------------------
__int16 __cdecl sub_4BE710(int a1, int a2, int a3, int a4)
{
    __int16 result; // ax
    int v5; // [esp-Ch] [ebp-Ch]

    v5 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 96) + 4) + 4 * a4);
    if (*(_DWORD*)& byte_5D4594[3798728])
        result = sub_48B3F0(v5, a2, a3);
    else
        result = sub_47D2C0(v5, a2, a3);
    return result;
}

//----- (004BE750) --------------------------------------------------------
__int16 __cdecl sub_4BE750(int a1, int a2, int a3)
{
    int v3; // eax
    int v4; // esi
    int v6; // [esp+4h] [ebp-4h]

    v3 = sub_4BE640(a1, 0);
    v4 = v3;
    if (v3)
    {
        sub_47D5C0(v3, 0, 0, &v6, &a1);
        LOWORD(v3) = sub_47D2C0(v4, a2 - v6 / 2, a3 - a1 / 2);
    }
    return v3;
}

//----- (004BE7B0) --------------------------------------------------------
int __cdecl sub_4BE7B0(int a1)
{
    int result; // eax

    if (sub_477620() == 10)
    {
        ++* (_DWORD*)& byte_5D4594[1316976];
        result = sub_4BE640(a1, *(int*)& byte_5D4594[1316976]);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1316976] = 0;
        result = sub_4BE640(a1, 0);
    }
    return result;
}

//----- (004BE800) --------------------------------------------------------
int __cdecl sub_4BE800(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1316980] = a1;
    return result;
}

//----- (004BE810) --------------------------------------------------------
char __cdecl sub_4BE810(int a1, int a2, int a3, char a4)
{
    char result; // al

    *(_DWORD*)& byte_5D4594[1316988] = a1;
    result = a4;
    *(_DWORD*)& byte_5D4594[1316984] = a2;
    *(_DWORD*)& byte_5D4594[1316992] = a3;
    byte_5D4594[1316996] = a4;
    return result;
}

//----- (004BE840) --------------------------------------------------------
int __cdecl sub_4BE840(int* a1, int* a2, int* a3, int* a4, int a5)
{
    int v5; // eax
    double v6; // st7
    int* v7; // edx
    unsigned __int8* v8; // ecx
    int v9; // esi
    int v10; // ebx
    int v11; // eax
    int v12; // edx
    int v13; // ebp
    unsigned __int8* v14; // eax
    int v15; // ecx
    double v16; // st7
    double v17; // st7
    double v18; // st6
    double v19; // st5
    double v20; // st4
    double v21; // st3
    double v22; // st2
    double v23; // st1
    double v24; // st0
    int result; // eax
    int v26; // esi
    int v27; // edi
    int v28; // ecx
    bool v29; // zf
    int v30; // [esp+4h] [ebp-38h]
    int v31; // [esp+8h] [ebp-34h]
    int v32; // [esp+Ch] [ebp-30h]
    int v33; // [esp+14h] [ebp-28h]
    int v34; // [esp+18h] [ebp-24h]
    int v35[4];
    int v39[4];
    int v43; // [esp+40h] [ebp+4h]
    float v44; // [esp+40h] [ebp+4h]
    int v45; // [esp+44h] [ebp+8h]
    int v46; // [esp+48h] [ebp+Ch]
    float v47; // [esp+48h] [ebp+Ch]
    int v48; // [esp+4Ch] [ebp+10h]

    v31 = *a1;
    v34 = a1[1];
    v5 = a3[1];
    v30 = *a3;
    v6 = 1.0 / (double)a5;
    v46 = *a4;
    v7 = a2;
    v45 = a4[1];
    v48 = *v7;
    v33 = v7[1];
    v32 = v5;
    v8 = &byte_581450[9812];
    v43 = 0;
    do
    {
        v9 = *((_DWORD*)v8 - 1);
        v10 = v31;
        v11 = v32 * *((_DWORD*)v8 + 1) + v45 * *((_DWORD*)v8 + 2);
        v12 = v33 * *(_DWORD*)v8;
        v39[v43] = v31 * *((_DWORD*)v8 - 1)
            + v30 * *((_DWORD*)v8 + 1)
            + v48 * *(_DWORD*)v8
            + v46 * *((_DWORD*)v8 + 2);
        v13 = v34;
        v8 += 16;
        v35[v43] = v34 * v9 + v12 + v11;
        v43++;
    } while ((int)v8 < (int)& byte_581450[9876]);
    *(float*)& byte_587000[180484] = v6;
    v14 = &byte_587000[180468];
    v15 = 0;
    *(float*)& byte_587000[180480] = v6 * v6;
    *(float*)& byte_587000[180476] = v6 * v6 * v6;
    *(float*)& byte_587000[180496] = *(float*)& byte_587000[180480] + *(float*)& byte_587000[180480];
    v16 = *(float*)& byte_587000[180476] * 6.0;
    *(float*)& byte_587000[180492] = v16;
    *(float*)& byte_587000[180508] = v16;
    v17 = (double)v39[3];
    v18 = (double)v39[2];
    v19 = (double)v39[1];
    v20 = (double)v39[0];
    v21 = (double)v35[3];
    v22 = (double)v35[2];
    v47 = (double)v35[1];
    v44 = (double)v35[0];
    do
    {
        v23 = v20 * *((float*)v14 - 2);
        v24 = v19 * *((float*)v14 - 1);
        v14 += 16;
        *(float*)((char*)& v35 + v15) = v23 + v24 + v18 * *((float*)v14 - 4) + v17 * *((float*)v14 - 3);
        *(float*)((char*)& v39 + v15) = v44 * *((float*)v14 - 6)
            + v47 * *((float*)v14 - 5)
            + v22 * *((float*)v14 - 4)
            + v21 * *((float*)v14 - 3);
        v15 += 4;
    } while ((int)v14 < (int)& byte_587000[180532]);
    result = a5;
    if (a5 > 0)
    {
        do
        {
            *(float*)v35 = *(float*)v35 + *(float*)& v35[1];
            *(float*)& v35[1] = *(float*)& v35[2] + *(float*)& v35[1];
            *(float*)& v35[2] = *(float*)& v35[3] + *(float*)& v35[2];
            *(float*)v39 = *(float*)v39 + *(float*)& v39[1];
            *(float*)& v39[1] = *(float*)& v39[2] + *(float*)& v39[1];
            *(float*)& v39[2] = *(float*)& v39[3] + *(float*)& v39[2];
            v26 = sub_419A70(v35[0]);
            v27 = sub_419A70(v39[0]);
            sub_49F500(v10, v13);
            sub_49F500(v26, v27);
            sub_434460(*(int*)& byte_5D4594[1316980]);
            sub_49E4B0();
            if (*(_DWORD*)& byte_5D4594[1316988])
            {
                sub_49F500(v10, v13);
                sub_49F500(v26, v27);
                sub_434040(*(int*)& byte_5D4594[1316984]);
                sub_434080(*(int*)& byte_5D4594[1316992]);
                LOBYTE(v28) = byte_5D4594[1316996];
                sub_49E4F0(v28);
            }
            v10 = v26;
            result = a5 - 1;
            v29 = a5 == 1;
            v13 = v27;
            --a5;
        } while (!v29);
    }
    return result;
}
// 4BEAA0: variable 'v28' is possibly undefined

//----- (004BEAD0) --------------------------------------------------------
void __cdecl sub_4BEAD0(int2* a1, int2* a2, int2* a3, int2* a4, int a5, int a6)
{
    int v6; // eax
    double v7; // st7
    unsigned __int8* v8; // ecx
    int v9; // edi
    int v10; // eax
    int v11; // esi
    int v12; // ebx
    int v13; // edi
    int v14; // edx
    int v15; // ebx
    unsigned __int8* v16; // eax
    int v17; // ecx
    double v18; // st7
    double v19; // st7
    double v20; // st6
    double v21; // st5
    double v22; // st4
    double v23; // st3
    double v24; // st2
    double v25; // st1
    double v26; // st0
    int v27; // ebp
    int v28; // ebx
    int i; // eax
    int v30; // esi
    int v31; // ecx
    int v32; // eax
    bool v33; // zf
    int v34; // [esp+4h] [ebp-38h]
    int v35; // [esp+8h] [ebp-34h]
    int v36; // [esp+Ch] [ebp-30h]
    int v37; // [esp+10h] [ebp-2Ch]
    int v38; // [esp+14h] [ebp-28h]
    int v39; // [esp+18h] [ebp-24h]
    int v40[8]; // [esp+1Ch] [ebp-20h]
    int v41; // [esp+40h] [ebp+4h]
    int v42; // [esp+44h] [ebp+8h]
    float v43; // [esp+44h] [ebp+8h]
    int v44; // [esp+48h] [ebp+Ch]
    int v45; // [esp+4Ch] [ebp+10h]
    float v46; // [esp+4Ch] [ebp+10h]
    int v47; // [esp+4Ch] [ebp+10h]
    int v48; // [esp+50h] [ebp+14h]

    v36 = a1->field_0;
    v41 = a1->field_4;
    v6 = a4->field_4;
    v34 = a4->field_0;
    v7 = 1.0 / (double)a5;
    v35 = a2->field_0;
    v39 = a2->field_4;
    v42 = a3->field_0;
    v38 = a3->field_4;
    v44 = v6;
    v8 = &byte_581450[9876];
    v45 = 0;
    do
    {
        v9 = *((_DWORD*)v8 + 1);
        v10 = *((_DWORD*)v8 + 2);
        v37 = v9;
        v11 = v39 * *(_DWORD*)v8;
        v12 = v35 * *(_DWORD*)v8 + v34 * v10 + v42 * v9;
        v13 = v36;
        v14 = v41 * *((_DWORD*)v8 - 1);
        v15 = v36 * *((_DWORD*)v8 - 1) + v12;
        v8 += 16;
        v40[v45 + 4] = v15;
        *(int*)((char*)& v40[0] + v45 * 4) = v14 + v11 + v38 * v37 + v44 * v10;
        ++v45;
    } while ((int)v8 < (int)& byte_581450[9940]);
    *(float*)& byte_587000[180484] = v7;
    v16 = &byte_587000[180468];
    v17 = 0;
    *(float*)& byte_587000[180480] = v7 * v7;
    *(float*)& byte_587000[180476] = v7 * v7 * v7;
    *(float*)& byte_587000[180496] = *(float*)& byte_587000[180480] + *(float*)& byte_587000[180480];
    v18 = *(float*)& byte_587000[180476] * 6.0;
    *(float*)& byte_587000[180492] = v18;
    *(float*)& byte_587000[180508] = v18;
    v19 = (double)v40[7];
    v20 = (double)v40[6];
    v21 = (double)v40[5];
    v22 = (double)v40[4];
    v23 = (double)v40[3];
    v24 = (double)v40[2];
    v43 = (double)v40[1];
    v46 = (double)v40[0];
    do
    {
        v25 = v22 * *((float*)v16 - 2);
        v26 = v21 * *((float*)v16 - 1);
        v16 += 16;
        *(float*)((char*)& v40[0] + v17 * 4) = v25 + v26 + v20 * *((float*)v16 - 4) + v19 * *((float*)v16 - 3);
        ++v17;
        *(float*)& v40[v17 + 3] = v46 * *((float*)v16 - 6)
            + v43 * *((float*)v16 - 5)
            + v24 * *((float*)v16 - 4)
            + v23 * *((float*)v16 - 3);
    } while ((int)v16 < (int)& byte_587000[180532]);
    if (a5 > 0)
    {
        v47 = a5;
        do
        {
            *(float*)v40 = *(float*)v40 + *(float*)& v40[1];
            *(float*)& v40[1] = *(float*)& v40[2] + *(float*)& v40[1];
            *(float*)& v40[2] = *(float*)& v40[3] + *(float*)& v40[2];
            *(float*)& v40[4] = *(float*)& v40[4] + *(float*)& v40[5];
            *(float*)& v40[5] = *(float*)& v40[6] + *(float*)& v40[5];
            *(float*)& v40[6] = *(float*)& v40[7] + *(float*)& v40[6];
            v27 = sub_419A70(*(float*)v40);
            v28 = sub_419A70(*(float*)& v40[4]);
            sub_49F500(v13, v41);
            sub_49F500(v27, v28);
            sub_434460(*(int*)& byte_5D4594[1316980]);
            sub_49E4B0();
            if (a6)
            {
                v48 = 0;
                for (i = v13 - v28; ; i = v13 - v28)
                {
                    v30 = v48 != 0 ? 1 : -1;
                    if (i >= 0)
                        v31 = i;
                    else
                        v31 = v28 - v13;
                    if (i < 0)
                        i = v28 - v13;
                    if (v31 <= i)
                    {
                        sub_49F500(v30 + v27, v28);
                        sub_49F500(v13 + v30, v41);
                    }
                    else
                    {
                        sub_49F500(v27, v30 + v28);
                        sub_49F500(v13, v41 + v30);
                    }
                    sub_49E4B0();
                    if (++v48 >= 2)
                        break;
                }
            }
            if (*(_DWORD*)& byte_5D4594[1316988])
            {
                sub_49F500(v13, v41);
                sub_49F500(v27, v28);
                sub_434040(*(int*)& byte_5D4594[1316984]);
                v32 = sub_434080(*(int*)& byte_5D4594[1316992]);
                LOBYTE(v32) = byte_5D4594[1316996];
                sub_49E4F0(v32);
            }
            v13 = v27;
            v33 = v47 == 1;
            v41 = v28;
            --v47;
        } while (!v33);
    }
}

//----- (004BEDE0) --------------------------------------------------------
void __cdecl sub_4BEDE0(int2* a1, int2* a2, int2* a3, int2* a4, int a5, float a6, int a7, int a8)
{
    int v8; // ecx
    double v9; // st7
    unsigned __int8* v10; // ecx
    int v11; // esi
    int v12; // eax
    int v13; // ebx
    int v14; // eax
    int v15; // esi
    double v16; // st6
    double v17; // st7
    double v18; // st7
    float v19; // [esp+0h] [ebp-54h]
    float v20; // [esp+0h] [ebp-54h]
    float v21; // [esp+10h] [ebp-44h]
    float v22; // [esp+10h] [ebp-44h]
    int v23; // [esp+14h] [ebp-40h]
    float v24; // [esp+14h] [ebp-40h]
    int v25; // [esp+18h] [ebp-3Ch]
    float v26; // [esp+18h] [ebp-3Ch]
    int v27; // [esp+1Ch] [ebp-38h]
    float v28; // [esp+1Ch] [ebp-38h]
    int v29; // [esp+20h] [ebp-34h]
    float v30; // [esp+20h] [ebp-34h]
    int v31; // [esp+24h] [ebp-30h]
    float v32; // [esp+24h] [ebp-30h]
    int v33; // [esp+28h] [ebp-2Ch]
    float v34; // [esp+28h] [ebp-2Ch]
    int2 v35[5]; // [esp+2Ch] [ebp-28h]
    int2* v36; // [esp+58h] [ebp+4h]
    float v37; // [esp+58h] [ebp+4h]
    int2* v38; // [esp+5Ch] [ebp+8h]
    float v39; // [esp+5Ch] [ebp+8h]
    int v40; // [esp+60h] [ebp+Ch]
    float v41; // [esp+60h] [ebp+Ch]
    int v42; // [esp+64h] [ebp+10h]
    float v43; // [esp+64h] [ebp+10h]
    float v44; // [esp+68h] [ebp+14h]
    float v45; // [esp+6Ch] [ebp+18h]

    v8 = a1->field_0;
    v33 = a1->field_4;
    v35[2].field_4 = a1->field_4;
    v25 = v8;
    v35[2].field_0 = v8;
    v27 = a2->field_0;
    v9 = 1.0 / (double)a5;
    v23 = a3->field_0;
    v29 = a3->field_4;
    v21 = 0.0;
    v40 = a4->field_0;
    v31 = a2->field_4;
    v42 = a4->field_4;
    v10 = &byte_581450[9876];
    v38 = 0;
    do
    {
        v11 = *((_DWORD*)v10 + 1);
        v12 = *((_DWORD*)v10 + 2);
        v36 = (int2*) * ((_DWORD*)v10 - 1);
        v13 = v27 * *(_DWORD*)v10 + v25 * (_DWORD)v36 + v23 * v11 + v40 * v12;
        v14 = v33 * (_DWORD)v36 + v31 * *(_DWORD*)v10 + v29 * v11 + v42 * v12;
        v10 += 16;
        *(int*)((char*)& v35[0].field_0 + (_DWORD)v38) = v13;
        *(int*)((char*)& v35[3].field_0 + (_DWORD)v38) = v14;
        v38 = (int2*)((char*)v38 + 4);
    } while ((int)v10 < (int)& byte_581450[9940]);
    v15 = a5;
    if (a5 > 0)
    {
        v16 = v9 * a6;
        v41 = v16 + v9;
        v45 = (double)v35[0].field_0;
        v43 = (double)v35[0].field_4;
        v34 = (double)v35[1].field_0;
        v32 = (double)v35[1].field_4;
        v28 = (double)v35[3].field_0;
        v30 = (double)v35[3].field_4;
        v26 = (double)v35[4].field_0;
        v24 = (double)v35[4].field_4;
        do
        {
            v17 = v41 + v21;
            v22 = v17;
            if (v17 > 1.0)
                v22 = 1.0;
            v18 = v22 * v22;
            v44 = v18;
            v37 = v18 * v22;
            v19 = v43 * v44 + v45 * v37 + v34 * v22 + v32;
            v35[0].field_0 = sub_419A70(v19);
            v20 = v30 * v44 + v28 * v37 + v26 * v22 + v24;
            v35[0].field_4 = sub_419A70(v20);
            v39 = v16;
            v21 = v22 - v39;
            ((void(__cdecl*)(int2*, int2*, int))a7)(&v35[2], v35, a8);
            --v15;
            v35[2].field_0 = v35[0].field_0;
            v35[2].field_4 = v35[0].field_4;
        } while (v15);
    }
}

//----- (004BF000) --------------------------------------------------------
void sub_4BF000()
{
    nox_srand(0x15EA1u);
}

//----- (004BF010) --------------------------------------------------------
int __cdecl sub_4BF010(int a1)
{
    int v1; // ecx
    char v3[3]; // [esp+0h] [ebp-4h]
    char v4; // [esp+3h] [ebp-1h]

    v4 = HIBYTE(v1);
    v3[0] = -32;
    *(_WORD*)& v3[1] = sub_578B00(a1);
    return sub_4E53C0(31, v3, 3, 0, 1);
}

//----- (004BF040) --------------------------------------------------------
void sub_4BF040()
{
    nox_srand(0x15EABu);
}

//----- (004BF050) --------------------------------------------------------
wchar_t* __cdecl sub_4BF050(wchar_t* a1)
{
    int* v1; // esi
    int v2; // eax
    const wchar_t* v3; // ebx
    _DWORD* v4; // eax
    wchar_t* v5; // eax
    wchar_t* result; // eax
    int v7; // edx
    int v8; // ecx
    const wchar_t* v9; // ecx
    int v10; // ecx
    wchar_t* v11; // ecx
    const wchar_t* v12; // edi
    int v13; // eax
    wchar_t* v14; // eax
    int v15; // esi
    wchar_t* v16; // esi
    wchar_t* v17; // esi
    int v18; // eax
    int v19; // eax
    const wchar_t* v20; // eax
    wchar_t* v21; // eax
    wchar_t* v22; // eax
    const wchar_t* v23; // eax
    int v24; // eax
    int v25; // eax
    wchar_t* v26; // eax
    wchar_t* v27; // eax
    const wchar_t* v28; // eax
    int v29; // eax
    const wchar_t* v30; // eax
    wchar_t* v31; // eax
    const wchar_t* v32; // eax
    int v33; // [esp-4h] [ebp-18h]
    wchar_t* v34; // [esp+Ch] [ebp-8h]
    wchar_t* v35; // [esp+10h] [ebp-4h]

    *(_WORD*)& byte_5D4594[1317000] = 0;
    nox_wcscpy((wchar_t*)& byte_5D4594[1317000], (const wchar_t*)& byte_5D4594[1319048]);
    v1 = (int*)a1;
    if (!a1)
        return (wchar_t*)& byte_5D4594[1317000];
    v2 = *((_DWORD*)a1 + 28);
    if (!(v2 & 0x13001000))
    {
        if (!(v2 & 0x100))
        {
            result = (wchar_t*)nox_get_thing_field_4(*((_DWORD*)a1 + 27));
            if (result)
                return result;
            return (wchar_t*)& byte_5D4594[1317000];
        }
        v18 = *((_DWORD*)a1 + 29);
        LOBYTE(a1) = -13;
        if (v18 & 1)
        {
            v19 = v1[108];
            if (!v19)
            {
                LOBYTE(a1) = -30;
                *(_WORD*)((char*)& a1 + 1) = sub_578B00((int)v1);
                HIBYTE(a1) = 1;
                v1[108] = 137;
                goto LABEL_93;
            }
            if (v19 != 137)
            {
                if (*(_DWORD*)& byte_587000[26048] != 6)
                {
                    v22 = loadString_sub_40F1D0((char*)& byte_587000[180736], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 292);
                    nox_swprintf((wchar_t*)& byte_5D4594[1317000], L"%s ", v22);
                    v23 = (const wchar_t*)sub_424930(v1[108]);
                    nox_wcscat((wchar_t*)& byte_5D4594[1317000], v23);
                    goto LABEL_93;
                }
                v20 = (const wchar_t*)sub_424930(v1[108]);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v20);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                v21 = loadString_sub_40F1D0((char*)& byte_587000[180692], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 288);
                goto LABEL_90;
            }
            return (wchar_t*)& byte_5D4594[1317000];
        }
        if (v18 & 2)
        {
            v24 = v1[108];
            if (!v24)
            {
                LOBYTE(a1) = -30;
                *(_WORD*)((char*)& a1 + 1) = sub_578B00((int)v1);
                HIBYTE(a1) = 2;
                v1[108] = 41;
                goto LABEL_93;
            }
            if (v24 == 41)
                return (wchar_t*)& byte_5D4594[1317000];
            if (*(_DWORD*)& byte_587000[26048] == 3 || *(_DWORD*)& byte_587000[26048] == 5)
            {
                v27 = loadString_sub_40F1D0((char*)& byte_587000[180788], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 313);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v27);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                v28 = (const wchar_t*)sub_427240(v1[108]);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v28);
            }
            else
            {
                v25 = sub_427240(v1[108]);
                nox_swprintf((wchar_t*)& byte_5D4594[1317000], L"%s ", v25);
                v26 = loadString_sub_40F1D0((char*)& byte_587000[180848], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 320);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v26);
            }
        }
        else if (v18 & 4)
        {
            v29 = v1[108];
            if (!v29)
            {
                LOBYTE(a1) = -30;
                *(_WORD*)((char*)& a1 + 1) = sub_578B00((int)v1);
                HIBYTE(a1) = 4;
                v1[108] = 6;
                goto LABEL_93;
            }
            if (v29 == 6)
                return (wchar_t*)& byte_5D4594[1317000];
            if (*(_DWORD*)& byte_587000[26048] == 6)
            {
                v30 = (const wchar_t*)sub_425260(v1[108]);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v30);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                v21 = loadString_sub_40F1D0((char*)& byte_587000[180900], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 342);
            LABEL_90:
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v21);
                goto LABEL_93;
            }
            v31 = loadString_sub_40F1D0((char*)& byte_587000[180944], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 346);
            nox_swprintf((wchar_t*)& byte_5D4594[1317000], L"%s ", v31);
            v32 = (const wchar_t*)sub_425260(v1[108]);
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v32);
        }
        else
        {
            result = (wchar_t*)nox_get_thing_field_4(v1[27]);
            if (result)
                return result;
        }
    LABEL_93:
        if ((_BYTE)a1 != (_BYTE)-13)
        {
            sub_4E53C0(31, &a1, 4, 0, 1);
            return (wchar_t*)& byte_5D4594[1317000];
        }
        return (wchar_t*)& byte_5D4594[1317000];
    }
    v3 = 0;
    v34 = 0;
    v35 = 0;
    a1 = 0;
    if (v2 & 0x11001000)
        v4 = sub_413250(v1[27]);
    else
        v4 = sub_413270(v1[27]);
    if (v4)
    {
        v7 = v1[28] & 0x1000000;
        if (!v7 || v7 == 0x1000000 && !(v1[29] & 0x7800000))
        {
            v8 = v1[108];
            if (v8)
            {
                v9 = *(const wchar_t**)(v8 + 8);
                if (v9)
                    v3 = v9;
            }
            v10 = v1[109];
            if (v10)
            {
                v11 = *(wchar_t**)(v10 + 8);
                if (v11)
                    v34 = v11;
            }
        }
        v12 = (const wchar_t*)v4[2];
        if (!v7 || !(v1[29] & 0x7800000))
        {
            v13 = v1[110];
            if (v13)
            {
                v14 = *(wchar_t**)(v13 + 8);
                if (v14)
                    v35 = v14;
            }
            v15 = v1[111];
            if (v15)
            {
                v16 = *(wchar_t**)(v15 + 12);
                if (v16)
                    a1 = v16;
            }
        }
        switch (*(_DWORD*)& byte_587000[26048])
        {
        case 2:
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v12);
            if (v35)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v35);
            }
            v17 = a1;
            if (a1)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v17);
            }
            if (v34)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v34);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            if (!v3)
                return (wchar_t*)& byte_5D4594[1317000];
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v3);
            result = (wchar_t*)& byte_5D4594[1317000];
            break;
        case 3:
            if (v3)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v3);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v12);
            if (v34)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v34);
            }
            if (v35)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v35);
            }
            if (!a1)
                return (wchar_t*)& byte_5D4594[1317000];
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            goto LABEL_67;
        case 5:
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v12);
            if (v34)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v34);
            }
            if (v3)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v3);
            }
            if (v35)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v35);
            }
            if (!a1)
                return (wchar_t*)& byte_5D4594[1317000];
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], a1);
            result = (wchar_t*)& byte_5D4594[1317000];
            break;
        case 6:
            if (v3)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v3);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            if (v35)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v35);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            if (a1)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], a1);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            if (v34)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v34);
            }
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v12);
            result = (wchar_t*)& byte_5D4594[1317000];
            break;
        default:
            if (v3)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v3);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            if (v34)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v34);
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
            }
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], v12);
            if (v35)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
                nox_wcscat((wchar_t*)& byte_5D4594[1317000], v35);
            }
            if (!a1)
                return (wchar_t*)& byte_5D4594[1317000];
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], L" ");
        LABEL_67:
            nox_wcscat((wchar_t*)& byte_5D4594[1317000], a1);
            result = (wchar_t*)& byte_5D4594[1317000];
            break;
        }
    }
    else
    {
        v33 = nox_get_thing_name(v1[27]);
        v5 = loadString_sub_40F1D0((char*)& byte_587000[180560], 0, "C:\\NoxPost\\src\\client\\Gui\\ToolTip.c", 53);
        nox_swprintf((wchar_t*)& byte_5D4594[1317000], v5, v33);
        result = (wchar_t*)& byte_5D4594[1317000];
    }
    return result;
}

//----- (004BF7E0) --------------------------------------------------------
__int16 __cdecl sub_4BF7E0(_DWORD* a1)
{
    int v1; // esi
    int v2; // ebp
    int v3; // eax
    int v4; // edi
    int v5; // ebx
    int v6; // eax
    int v7; // eax
    int v8; // ebx
    int v9; // eax
    int v10; // ebx
    int v11; // eax
    int v13; // [esp+10h] [ebp-4h]
    unsigned __int8* v14; // [esp+18h] [ebp+4h]
    unsigned __int8* v15; // [esp+18h] [ebp+4h]

    v1 = a1[1] + 15;
    v2 = *a1 + 11;
    v13 = a1[1] + 15;
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_49CE30(v2, v1, 200, 200);
    LOWORD(v3) = *(_WORD*)& byte_5D4594[2614252];
    if (*(_DWORD*)& byte_5D4594[2614252])
    {
        v4 = *(_DWORD*)& byte_5D4594[2618908];
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            sub_4341D0(1, *(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 2296));
            sub_4341D0(2, *(_DWORD*)(v4 + 2304));
            sub_4341D0(3, *(_DWORD*)(v4 + 2312));
            sub_4341D0(4, *(_DWORD*)(v4 + 2308));
            sub_4341D0(5, *(_DWORD*)(v4 + 2300));
            sub_4341D0(6, *(_DWORD*)(v4 + 2292));
            if (*(_DWORD*)(v4 + 2292) == *(_DWORD*)(v4 + 2296))
                sub_47D2C0(*(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(v4 + 2252) + 3798180], v2, v1);
            else
                sub_47D2C0(*(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(v4 + 2252) + 3798172], v2, v1);
            v5 = 0;
            v14 = &byte_5D4594[104 * *(unsigned __int8*)(v4 + 2252) + 3798188];
            do
            {
                if (*(_DWORD*)v4 & (1 << v5) && !((1 << v5) & 0x3000000))
                {
                    v6 = sub_415CD0((char*)(1 << v5));
                    sub_4BF9F0(1 << v5, v6, v2, v13, (int)v14, v5, 0);
                }
                ++v5;
            } while (v5 < 26);
            if (*(_BYTE*)v4 & 2)
            {
                v7 = sub_415CD0((char*)2);
                sub_4BF9F0(2, v7, v2, v13, (int)v14, 0, 1);
            }
            v8 = 0;
            do
            {
                if (*(_DWORD*)v4 & (1 << v8) && (1 << v8) & 0x3000000)
                {
                    v9 = sub_415CD0((char*)(1 << v8));
                    sub_4BF9F0(1 << v8, v9, v2, v13, (int)v14, v8, 0);
                }
                ++v8;
            } while (v8 < 26);
            v10 = 0;
            v15 = &byte_5D4594[108 * *(unsigned __int8*)(v4 + 2252) + 3798412];
            do
            {
                v3 = *(_DWORD*)(v4 + 4);
                if (v3 & (1 << v10))
                {
                    v11 = sub_415840((char*)(1 << v10));
                    LOWORD(v3) = sub_4BF9F0(1 << v10, v11, v2, v13, (int)v15, v10, 0);
                }
                ++v10;
            } while (v10 < 27);
        }
    }
    return v3;
}

//----- (004BF9F0) --------------------------------------------------------
__int16 __cdecl sub_4BF9F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v7; // eax
    int v8; // esi
    _DWORD* v9; // eax
    int v10; // edx
    int v11; // ecx
    _DWORD* v12; // ebx
    int v13; // ebp
    int v14; // edi
    _BYTE* v15; // esi
    int* v16; // edi
    _BYTE** v17; // esi
    int v18; // ebx
    _BYTE* v19; // eax

    v7 = sub_461600(a2);
    v8 = v7;
    if (v7)
    {
        if (*(_DWORD*)(v7 + 112) & 0x2000000)
            v9 = sub_413270(*(_DWORD*)(v7 + 108));
        else
            v9 = sub_413250(*(_DWORD*)(v7 + 108));
        v12 = v9;
        if (v9)
        {
            v13 = v8 + 432;
            v14 = 1;
            v15 = v9 + 4;
            do
            {
                LOBYTE(v9) = v15[1];
                LOBYTE(v11) = *v15;
                LOBYTE(v10) = *(v15 - 1);
                sub_4340A0(v14++, v10, v11, (int)v9);
                v15 += 3;
            } while (v14 < 7);
            v16 = v12 + 9;
            v17 = (_BYTE * *)v13;
            v18 = 4;
            do
            {
                v19 = *v17;
                if (*v17)
                {
                    LOBYTE(v11) = v19[26];
                    LOBYTE(v10) = v19[25];
                    LOBYTE(v19) = v19[24];
                    sub_4340A0(*v16, (int)v19, v10, v11);
                }
                ++v17;
                ++v16;
                --v18;
            } while (v18);
        }
        if (a7)
            LOWORD(v7) = sub_47D2C0(*(int*)& byte_5D4594[1319052], a3, a4);
        else
            LOWORD(v7) = sub_47D2C0(*(_DWORD*)(a5 + 4 * a6), a3, a4);
    }
    return v7;
}
// 4BFA4C: variable 'v10' is possibly undefined
// 4BFA4C: variable 'v11' is possibly undefined

//----- (004BFAD0) --------------------------------------------------------
int sub_4BFAD0()
{
    int v0; // esi
    int v1; // ebx
    int i; // edi
    char* v3; // eax
    const char* v4; // ecx
    int v5; // ebp
    int v6; // ebp

    v0 = 0;
    v1 = 0;
    for (i = 0; i < 8; i += 4)
    {
        v3 = sub_42F970(*(const char**)& byte_587000[i + 180960]);
        v4 = *(const char**)& byte_587000[i + 180968];
        *(_DWORD*)& byte_5D4594[i + 3798172] = v3;
        *(_DWORD*)& byte_5D4594[i + 3798180] = sub_42F970(v4);
        v5 = 26;
        do
        {
            *(_DWORD*)& byte_5D4594[v1 + 3798188] = sub_42F970(*(const char**)& byte_587000[v1 + 180976]);
            v1 += 4;
            --v5;
        } while (v5);
        v6 = 27;
        do
        {
            *(_DWORD*)& byte_5D4594[v0 + 3798412] = sub_42F970(*(const char**)& byte_587000[v0 + 181184]);
            v0 += 4;
            --v6;
        } while (v6);
    }
    *(_DWORD*)& byte_5D4594[1319052] = sub_42F970("MaleMedievalCloakTop");
    return 1;
}

//----- (004BFB70) --------------------------------------------------------
_DWORD* __cdecl sub_4BFB70(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1319056];
    if (*(_DWORD*)& byte_5D4594[1319056])
    {
        result = (_DWORD*)a1;
        *(_DWORD*)& byte_5D4594[1319056] = a1;
    }
    else
    {
        if (a1 == 1)
            result = sub_452D80(1022, 100);
        *(_DWORD*)& byte_5D4594[1319056] = a1;
    }
    return result;
}

//----- (004BFBB0) --------------------------------------------------------
_DWORD* __cdecl sub_4BFBB0(_DWORD* a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1319056];
    if (*(_DWORD*)& byte_5D4594[1319056])
    {
        if (*(_DWORD*)& byte_5D4594[1319056] == 1)
        {
            result = a1;
            if (!a1)
            {
                sub_4BFC70();
                result = sub_4BFB70(0);
            }
        }
    }
    else if (a1 == (_DWORD*)1)
    {
        sub_4BFBF0();
        result = sub_4BFB70(1);
    }
    return result;
}

//----- (004BFBF0) --------------------------------------------------------
int sub_4BFBF0()
{
    int result; // eax
    int v1; // [esp+0h] [ebp-8h]
    int v2; // [esp+4h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1319060];
    if (*(_DWORD*)& byte_5D4594[1319060])
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1319060], 0);
        sub_46ABB0(*(int*)& byte_5D4594[1319060], 1);
        nox_window_get_size(*(int*)& byte_5D4594[1319060], &v2, &v1);
        sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1319060],
            nox_win_width / 2 - v2 / 2,
            nox_win_height / 2 - v1 / 2);
        result = sub_46B500(0);
    }
    return result;
}

//----- (004BFC70) --------------------------------------------------------
int sub_4BFC70()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1319060];
    if (*(_DWORD*)& byte_5D4594[1319060])
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1319060], 1);
        result = sub_46B500(0);
    }
    return result;
}

//----- (004BFC90) --------------------------------------------------------
int sub_4BFC90()
{
    int result; // eax

    result = nox_new_window_from_file("SKey.wnd", sub_4BFCD0);
    *(_DWORD*)& byte_5D4594[1319060] = result;
    if (result)
    {
        sub_4BFB70(0);
        sub_4BFC70();
        result = 1;
    }
    return result;
}

//----- (004BFCD0) --------------------------------------------------------
int __cdecl sub_4BFCD0(int a1, int a2, int* a3, int a4)
{
    int v3; // esi

    if (a2 == 16391)
    {
        v3 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        if (v3 == 10803)
            sub_4BFC70();
    }
    return 0;
}

//----- (004BFD10) --------------------------------------------------------
_DWORD* sub_4BFD10()
{
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1319060]);
    *(_DWORD*)& byte_5D4594[1319060] = 0;
    return sub_4BFB70(0);
}

//----- (004BFD30) --------------------------------------------------------
int sub_4BFD30()
{
    return *(_DWORD*)& byte_5D4594[1319056];
}

//----- (004BFD40) --------------------------------------------------------
int sub_4BFD40()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1319268] == 1)
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1319228], 1);
        sub_46ABB0(*(int*)& byte_5D4594[1319228], 0);
        sub_46C6E0(*(int*)& byte_5D4594[1319228]);
        result = *(_DWORD*)& byte_5D4594[1319256];
        if (*(_DWORD*)& byte_5D4594[1319256])
            result = sub_45A4B0(*(_QWORD * *)& byte_5D4594[1319256]);
        *(_DWORD*)& byte_5D4594[1319256] = 0;
        *(_DWORD*)& byte_5D4594[1319268] = 0;
    }
    else
    {
        sub_46ABB0(*(int*)& byte_5D4594[1319228], 1);
        sub_46C690(*(int*)& byte_5D4594[1319228]);
        result = sub_46A8C0(*(int*)& byte_5D4594[1319228]);
        *(_DWORD*)& byte_5D4594[1319268] = 1;
    }
    return result;
}

//----- (004BFDD0) --------------------------------------------------------
int __cdecl sub_4BFDD0(_DWORD* a1, int a2, unsigned int a3)
{
    int result; // eax

    switch (a2)
    {
    case 5:
    case 9:
    case 13:
        if (!sub_46AAB0(a1, (unsigned __int16)a3, a3 >> 16))
            sub_4BFE40();
        goto LABEL_4;
    case 6:
    case 7:
    case 10:
    case 11:
    case 14:
    case 15:
    LABEL_4:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (004BFE40) --------------------------------------------------------
int sub_4BFE40()
{
    const wchar_t* v0; // eax
    unsigned int v1; // esi
    int v3; // [esp+0h] [ebp-10h]
    int v4; // [esp+4h] [ebp-Ch]
    int2 v5; // [esp+8h] [ebp-8h]

    if (*(_DWORD*)& byte_5D4594[1319268] != 1)
        return 0;
    v0 = (const wchar_t*)sub_46AF00(*(int*)& byte_5D4594[1319232]);
    v1 = nox_wcstol(v0, 0, 10);
    if (v1 > * (int*)& byte_5D4594[1319248])
        v1 = *(_DWORD*)& byte_5D4594[1319248];
    sub_46AA20(*(int*)& byte_5D4594[1319228], &v3, &v4);
    v5.field_0 = v3 + *(_DWORD*)& byte_587000[183456];
    v5.field_4 = v4 + *(_DWORD*)& byte_587000[183460];
    if (*(_DWORD*)& byte_5D4594[1319100])
        (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1319100])(
            &v5,
            *(_DWORD*)& byte_5D4594[1319244],
            *(_DWORD*)& byte_5D4594[1319240],
            v1,
            *(_DWORD*)& byte_5D4594[1319252]);
    sub_4BFD40();
    return 1;
}

//----- (004BFEF0) --------------------------------------------------------
int sub_4BFEF0()
{
    _DWORD* v0; // eax

    *(_DWORD*)& byte_5D4594[1319264] = 0;
    v0 = nox_new_window_from_file("MultMove.wnd", sub_4C01C0);
    *(_DWORD*)& byte_5D4594[1319228] = v0;
    if (!v0)
        return 0;
    nox_window_set_all_funcs(v0, sub_4BFDD0, sub_4C0030, 0);
    *(_DWORD*)& byte_5D4594[1319232] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3601);
    *(_DWORD*)& byte_5D4594[1319236] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3607);
    nox_window_set_hidden(*(int*)& byte_5D4594[1319228], 1);
    sub_46ABB0(*(int*)& byte_5D4594[1319228], 0);
    *(_DWORD*)& byte_5D4594[1319108] = 0;
    *(_DWORD*)& byte_5D4594[1319112] = 0;
    *(_DWORD*)& byte_5D4594[1319116] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1319120] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1319140] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1319144] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1319124] = 0;
    *(_DWORD*)& byte_5D4594[1319128] = 0;
    *(_DWORD*)& byte_5D4594[1319196] = sub_42F970("MultiMoveBase");
    *(_DWORD*)& byte_5D4594[1319200] = sub_42F970("MultiMoveUpLit");
    *(_DWORD*)& byte_5D4594[1319204] = sub_42F970("MultiMoveDownLit");
    *(_DWORD*)& byte_5D4594[1319208] = sub_42F970("MultiMoveYesPressed");
    *(_DWORD*)& byte_5D4594[1319212] = sub_42F970("MultiMoveNoPressed");
    *(_DWORD*)& byte_5D4594[1319216] = sub_42F970("MultiMoveBaseNoTag");
    *(_DWORD*)& byte_5D4594[1319220] = sub_42F970("MultiMoveYesPressedNoTag");
    *(_DWORD*)& byte_5D4594[1319224] = sub_42F970("MultiMoveNoPressedNoTag");
    return 1;
}

//----- (004C0030) --------------------------------------------------------
int __cdecl sub_4C0030(int a1)
{
    int v1; // ecx
    int v2; // ecx
    int v3; // edx
    int v5; // [esp+0h] [ebp-8h]
    int v6; // [esp+4h] [ebp-4h]

    sub_49CF10(0, 0, nox_win_width, nox_win_height);
    sub_46AA20(a1, &v5, &v6);
    v1 = *(_DWORD*)& byte_5D4594[1319196];
    if (!*(_DWORD*)& byte_5D4594[1319264])
        v1 = *(_DWORD*)& byte_5D4594[1319216];
    sub_47D2C0(v1, v5, v6);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1319256] + 12) = v5 + *(_DWORD*)& byte_587000[183456];
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1319256] + 16) = v6 + *(_DWORD*)& byte_587000[183460];
    (*(void(__cdecl * *)(unsigned __int8*, _DWORD))(*(_DWORD*)& byte_5D4594[1319256] + 300))(
        &byte_5D4594[1319108],
        *(_DWORD*)& byte_5D4594[1319256]);
    if (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3603)[9] & 4)
        sub_47D2C0(*(int*)& byte_5D4594[1319204], v5, v6);
    if (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3602)[9] & 4)
        sub_47D2C0(*(int*)& byte_5D4594[1319200], v5, v6);
    if (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3604)[9] & 4)
    {
        v2 = *(_DWORD*)& byte_5D4594[1319208];
        if (!*(_DWORD*)& byte_5D4594[1319264])
            v2 = *(_DWORD*)& byte_5D4594[1319220];
        sub_47D2C0(v2, v5, v6);
    }
    if (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3605)[9] & 4)
    {
        v3 = *(_DWORD*)& byte_5D4594[1319212];
        if (!*(_DWORD*)& byte_5D4594[1319264])
            v3 = *(_DWORD*)& byte_5D4594[1319224];
        sub_47D2C0(v3, v5, v6);
    }
    return 1;
}

//----- (004C01C0) --------------------------------------------------------
int __cdecl sub_4C01C0(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int result; // eax
    const wchar_t* v5; // eax
    unsigned int v6; // esi
    const wchar_t* v7; // eax
    unsigned int v8; // esi
    const wchar_t* v9; // eax
    int v10; // eax
    int v11; // esi
    int v12; // [esp+4h] [ebp-10h]
    int v13; // [esp+8h] [ebp-Ch]
    int2 v14; // [esp+Ch] [ebp-8h]

    if (a2 != 16391 || *(_DWORD*)& byte_5D4594[1319268] != 1)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v3)
    {
    case 3602:
        v7 = (const wchar_t*)sub_46AF00(*(int*)& byte_5D4594[1319232]);
        v8 = nox_wcstol(v7, 0, 10) + 1;
        if (v8 > * (int*)& byte_5D4594[1319248])
            return 0;
        nox_swprintf((wchar_t*)& byte_5D4594[1319164], L"%d", v8);
        sub_46AEE0(*(int*)& byte_5D4594[1319232], (int)& byte_5D4594[1319164]);
        if (!*(_DWORD*)& byte_5D4594[1319264])
            return 0;
        nox_swprintf(
            (wchar_t*)& byte_5D4594[1319068],
            L"%d",
            *(_DWORD*)& byte_5D4594[1319260] * v8);
        sub_46AEE0(*(int*)& byte_5D4594[1319236], (int)& byte_5D4594[1319068]);
        result = 0;
        break;
    case 3603:
        v9 = (const wchar_t*)sub_46AF00(*(int*)& byte_5D4594[1319232]);
        v10 = nox_wcstol(v9, 0, 10);
        v11 = v10;
        if (v10 > 1)
        {
            nox_swprintf((wchar_t*)& byte_5D4594[1319164], L"%d", v10 - 1);
            sub_46AEE0(*(int*)& byte_5D4594[1319232], (int)& byte_5D4594[1319164]);
            if (*(_DWORD*)& byte_5D4594[1319264])
            {
                nox_swprintf(
                    (wchar_t*)& byte_5D4594[1319068],
                    L"%d",
                    *(_DWORD*)& byte_5D4594[1319260] * (v11 - 1));
                sub_46AEE0(*(int*)& byte_5D4594[1319236], (int)& byte_5D4594[1319068]);
            }
        }
        return 0;
    case 3604:
    case 3606:
        v5 = (const wchar_t*)sub_46AF00(*(int*)& byte_5D4594[1319232]);
        v6 = nox_wcstol(v5, 0, 10);
        if (v6 > * (int*)& byte_5D4594[1319248])
            v6 = *(_DWORD*)& byte_5D4594[1319248];
        sub_46AA20(*(int*)& byte_5D4594[1319228], &v12, &v13);
        v14.field_0 = v12 + *(_DWORD*)& byte_587000[183456];
        v14.field_4 = v13 + *(_DWORD*)& byte_587000[183460];
        if (*(_DWORD*)& byte_5D4594[1319160])
            (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1319160])(
                &v14,
                *(_DWORD*)& byte_5D4594[1319244],
                *(_DWORD*)& byte_5D4594[1319240],
                v6,
                *(_DWORD*)& byte_5D4594[1319252]);
        sub_4BFD40();
        result = 0;
        break;
    case 3605:
        sub_4BFE40();
        result = 0;
        break;
    default:
        return 0;
    }
    return result;
}

//----- (004C03E0) --------------------------------------------------------
int sub_4C03E0()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1319256])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[1319256]);
    *(_DWORD*)& byte_5D4594[1319256] = 0;
    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1319228]);
    *(_DWORD*)& byte_5D4594[1319228] = 0;
    *(_DWORD*)& byte_5D4594[1319232] = 0;
    *(_DWORD*)& byte_5D4594[1319236] = 0;
    *(_DWORD*)& byte_5D4594[1319264] = 0;
    return result;
}

//----- (004C0430) --------------------------------------------------------
int __cdecl sub_4C0430(int a1, int a2, int a3, int a4, int a5, const void* a6, int a7, int a8, int a9, int a10)
{
    _DWORD* v10; // eax
    int result; // eax

    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1319228], 3606);
    sub_46AEE0((int)v10, a1);
    *(_DWORD*)& byte_5D4594[1319256] = sub_45A240(a5);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1319256] + 120) |= 0x40000000u;
    if (a6)
        qmemcpy((void*)(*(_DWORD*)& byte_5D4594[1319256] + 432), a6, 0x14u);
    *(_DWORD*)& byte_5D4594[1319160] = a9;
    *(_DWORD*)& byte_5D4594[1319100] = a10;
    *(_DWORD*)& byte_5D4594[1319240] = a5;
    *(_DWORD*)& byte_5D4594[1319244] = a4;
    *(_DWORD*)& byte_5D4594[1319248] = a7;
    *(_DWORD*)& byte_5D4594[1319252] = a8;
    sub_4BFD40();
    sub_4C0560(a2, a3);
    nox_swprintf((wchar_t*)& byte_5D4594[1319164], L"%d", 1);
    sub_46AEE0(*(int*)& byte_5D4594[1319232], (int)& byte_5D4594[1319164]);
    if (*(_DWORD*)& byte_5D4594[1319264])
    {
        nox_swprintf((wchar_t*)& byte_5D4594[1319068], L"%d", *(_DWORD*)& byte_5D4594[1319260]);
        result = sub_46AEE0(*(int*)& byte_5D4594[1319236], (int)& byte_5D4594[1319068]);
    }
    else
    {
        nox_swprintf((wchar_t*)& byte_5D4594[1319068], (const wchar_t*)& byte_5D4594[1319272]);
        result = sub_46AEE0(*(int*)& byte_5D4594[1319236], (int)& byte_5D4594[1319068]);
    }
    return result;
}

//----- (004C0560) --------------------------------------------------------
int __cdecl sub_4C0560(int a1, int a2)
{
    int v2; // ecx
    int v3; // eax
    int v5; // [esp+8h] [ebp-8h]
    int v6; // [esp+Ch] [ebp-4h]

    nox_window_get_size(*(int*)& byte_5D4594[1319228], &v5, &v6);
    v2 = a1 - *(_DWORD*)& byte_587000[183456];
    v3 = a2 - *(_DWORD*)& byte_587000[183460];
    if (a1 - *(int*)& byte_587000[183456] < 0)
        v2 = 0;
    if (v3 < 0)
        v3 = 0;
    if (v2 + v5 >= nox_win_width)
        v2 = nox_win_width - v5;
    if (v3 + v6 >= nox_win_height)
        v3 = nox_win_height - v6;
    return sub_46A9B0(*(_DWORD * *)& byte_5D4594[1319228], v2, v3);
}

//----- (004C05F0) --------------------------------------------------------
int __cdecl sub_4C05F0(int a1, int a2)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1319264] = a1;
    *(_DWORD*)& byte_5D4594[1319260] = a2;
    return result;
}

//----- (004C0610) --------------------------------------------------------
int sub_4C0610()
{
    char v1[2]; // [esp+0h] [ebp-2h]

    v1[0] = -55;
    v1[1] = 14;
    return sub_40EBC0(31, 0, v1, 2);
}

//----- (004C0630) --------------------------------------------------------
int __cdecl sub_4C0630(int a1, unsigned int a2, unsigned int a3)
{
    int v3; // eax
    _DWORD* v4; // ecx
    _DWORD* v5; // eax
    int v6; // esi
    int v7; // edi
    _DWORD* v8; // eax
    int v9; // esi
    int v10; // edi
    _DWORD* v12; // eax
    _DWORD* v13; // eax
    _DWORD* v14; // esi
    int v15; // eax
    int2 a1a; // [esp+4h] [ebp-8h]

    a1a.field_4 = a3 >> 16;
    a1a.field_0 = (unsigned __int16)a3;
    if (a2 == 5)
    {
        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
        if (sub_46AAB0(v12, a1a.field_0, a1a.field_4))
        {
            LOBYTE(v13) = sub_4C0910(&a1a);
            v14 = v13;
            if (v13[1])
            {
                sub_46ADC0(*(int*)& byte_5D4594[1320940]);
                sub_4160D0(2);
                *(int2*)& byte_5D4594[1319276] = a1a;
                *(_DWORD*)& byte_5D4594[1320968] = *v14;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1320968] + 128) = v14[v14[1] + 1];
                v14[v14[1] + 1] = 0;
                sub_477690(*(int*)& byte_5D4594[1320968]);
                v15 = v14[1] - 1;
                v14[1] = v15;
                if (!v15)
                    * v14 = 0;
                *(_DWORD*)& byte_5D4594[1320972] = v14;
                *(_DWORD*)& byte_5D4594[1320304] = 0;
                sub_452D80(791, 100);
            }
        }
        return 1;
    }
    if (a2 <= 5 || a2 > 7)
        return 0;
    v3 = sub_46AE00();
    v4 = *(_DWORD * *)& byte_5D4594[1320940];
    if (v3 == *(_DWORD*)& byte_5D4594[1320940])
    {
        sub_46ADE0(*(int*)& byte_5D4594[1320940]);
        v4 = *(_DWORD * *)& byte_5D4594[1320940];
    }
    if (!*(_DWORD*)& byte_5D4594[1320968])
        return 1;
    if (*(_DWORD*)& byte_5D4594[1320304])
    {
        if (*(_DWORD*)& byte_5D4594[1320304] == 1)
        {
            v8 = sub_46B0C0(v4, 3705);
            if (!sub_46AAB0(v8, a1a.field_0, a1a.field_4)
                || (v9 = *(_DWORD*)& byte_5D4594[1319276] - a1a.field_0,
                    v10 = *(_DWORD*)& byte_5D4594[1319280] - a1a.field_4,
                    !sub_4160F0(3u, *(_DWORD*)& byte_5D4594[2649704] / 3u))
                && v9 * v9 + v10 * v10 < 100)
            {
                sub_4C08E0(*(int*)& byte_5D4594[1320968]);
            }
        }
    }
    else
    {
        v5 = sub_46B0C0(v4, 3704);
        if (sub_46AAB0(v5, a1a.field_0, a1a.field_4))
        {
            v6 = *(_DWORD*)& byte_5D4594[1319276] - a1a.field_0;
            v7 = *(_DWORD*)& byte_5D4594[1319280] - a1a.field_4;
            if (!sub_4160F0(2u, *(_DWORD*)& byte_5D4594[2649704] / 3u) && v6 * v6 + v7 * v7 < 100)
                sub_4C08E0(*(int*)& byte_5D4594[1320968]);
        }
        else
        {
            sub_4C08E0(*(int*)& byte_5D4594[1320968]);
        }
    }
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1320972] + 4 * (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1320972] + 4))++ + 8) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1320968] + 128);
    if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1320972] + 4) == 1)
        ** (_DWORD * *)& byte_5D4594[1320972] = *(_DWORD*)& byte_5D4594[1320968];
    sub_4776A0();
    *(_DWORD*)& byte_5D4594[1320968] = 0;
    *(_DWORD*)& byte_5D4594[1320972] = 0;
    return 1;
}
// 4C0836: variable 'v13' is possibly undefined

//----- (004C08E0) --------------------------------------------------------
int __cdecl sub_4C08E0(int a1)
{
    char v2[4]; // [esp+0h] [ebp-4h]

    v2[0] = -55;
    v2[1] = 16;
    *(_WORD*)& v2[2] = sub_578B00(a1);
    return sub_40EBC0(31, 0, v2, 4);
}

//----- (004C0910) --------------------------------------------------------
char __cdecl sub_4C0910(int2* a1)
{
    _DWORD* v1; // eax
    int v2; // edi
    int v3; // ebx
    int i; // esi
    int v5; // eax
    int v7; // [esp+10h] [ebp-1Ch]
    int v8; // [esp+14h] [ebp-18h]
    int v9; // [esp+18h] [ebp-14h]
    int4 v10; // [esp+1Ch] [ebp-10h]

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
    sub_46AA60(v1, &v8, &v9);
    v2 = 0;
    v7 = 0;
    while (2)
    {
        v3 = 0;
        for (i = 0; i < 100; i += 50)
        {
            v10.field_0 = i + v8;
            v10.field_8 = i + v8 + 50;
            v10.field_4 = v2 + v9;
            v10.field_C = v2 + v9 + 50;
            v5 = sub_4281F0(a1, &v10);
            if (v5)
                return (char)& byte_5D4594[140 * (v7 + 2 * v3) + 1319284];
            ++v3;
        }
        v2 += 50;
        ++v7;
        if (v2 < 100)
            continue;
        break;
    }
    return v5;
}
// 4C097E: variable 'v5' is possibly undefined

//----- (004C09D0) --------------------------------------------------------
int sub_4C09D0()
{
    _DWORD* v0; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // esi
    wchar_t* v4; // eax
    wchar_t* v5; // esi
    wchar_t* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    wchar_t* v9; // esi
    wchar_t* v10; // eax
    wchar_t* v11; // esi
    wchar_t* v12; // eax
    wchar_t* v13; // esi
    wchar_t* v14; // eax
    unsigned __int8* v15; // edx
    unsigned __int8* v16; // eax
    int v17; // ecx
    unsigned __int8* v18; // edx
    unsigned __int8* v19; // eax
    int v20; // ecx
    wchar_t* v21; // eax

    v0 = nox_new_window_from_file("Trade.wnd", sub_4C0C90);
    *(_DWORD*)& byte_5D4594[1320940] = v0;
    if (!v0)
        return 0;
    nox_window_set_all_funcs(v0, sub_4C0630, sub_4C0D00, 0);
    v2 = loadString_sub_40F1D0((char*)& byte_587000[183764], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 692);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1320940] + 36), v2);
    v3 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3702);
    v4 = loadString_sub_40F1D0((char*)& byte_587000[183816], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 695);
    sub_46B000(v3 + 18, v4);
    v5 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3703);
    v6 = loadString_sub_40F1D0((char*)& byte_587000[183872], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 698);
    sub_46B000(v5 + 18, v6);
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
    sub_46B070((int)v7, sub_4C1120);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3705);
    sub_46B070((int)v8, sub_4C1120);
    v9 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3708);
    v10 = loadString_sub_40F1D0((char*)& byte_587000[183928], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 709);
    sub_46B000(v9 + 18, v10);
    v11 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3709);
    v12 = loadString_sub_40F1D0((char*)& byte_587000[183988], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 712);
    sub_46B000(v11 + 18, v12);
    v13 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3710);
    v14 = loadString_sub_40F1D0((char*)& byte_587000[184048], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 715);
    sub_46B000(v13 + 18, v14);
    nox_window_set_hidden(*(int*)& byte_5D4594[1320940], 1);
    sub_46ABB0(*(int*)& byte_5D4594[1320940], 0);
    v15 = &byte_5D4594[1319288];
    do
    {
        v16 = v15;
        v17 = 2;
        do
        {
            *((_DWORD*)v16 - 1) = 0;
            *(_DWORD*)v16 = 0;
            v16 += 280;
            --v17;
        } while (v17);
        v15 += 140;
    } while ((int)v15 < (int)& byte_5D4594[1319568]);
    v18 = &byte_5D4594[1320312];
    do
    {
        v19 = v18;
        v20 = 2;
        do
        {
            *((_DWORD*)v19 - 1) = 0;
            *(_DWORD*)v19 = 0;
            v19 += 280;
            --v20;
        } while (v20);
        v18 += 140;
    } while ((int)v18 < (int)& byte_5D4594[1320592]);
    v21 = loadString_sub_40F1D0((char*)& byte_587000[184100], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 749);
    nox_wcscpy((wchar_t*)& byte_5D4594[1319972], v21);
    *(_DWORD*)& byte_5D4594[1320188] = 0;
    *(_DWORD*)& byte_5D4594[1320192] = 0;
    *(_DWORD*)& byte_5D4594[1320196] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1320200] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1320220] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1320224] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1320204] = 0;
    *(_DWORD*)& byte_5D4594[1320208] = 0;
    *(_DWORD*)& byte_5D4594[1320164] = sub_42F970("TradeBase");
    *(_DWORD*)& byte_5D4594[1320168] = sub_42F970("TradeLeftAcceptPushed");
    *(_DWORD*)& byte_5D4594[1320172] = sub_42F970("TradeLeftAcceptLit");
    *(_DWORD*)& byte_5D4594[1320176] = sub_42F970("TradeRightAcceptLit");
    *(_DWORD*)& byte_5D4594[1320180] = sub_42F970("TradeCancelLit");
    *(_DWORD*)& byte_5D4594[1320184] = sub_42F970("TradeGold");
    return 1;
}

//----- (004C0C90) --------------------------------------------------------
int __cdecl sub_4C0C90(int a1, int a2, int* a3, int a4)
{
    int v3; // esi

    if (a2 == 16391)
    {
        v3 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        if (v3 == 3708)
        {
            sub_4C0CE0();
        }
        else if (v3 == 3710)
        {
            sub_4C0610();
            return 0;
        }
    }
    return 0;
}

//----- (004C0CE0) --------------------------------------------------------
int sub_4C0CE0()
{
    char v1[2]; // [esp+0h] [ebp-2h]

    v1[0] = -55;
    v1[1] = 17;
    return sub_40EBC0(31, 0, v1, 2);
}

//----- (004C0D00) --------------------------------------------------------
int sub_4C0D00()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    unsigned __int8* v6; // esi
    int v7; // ebp
    int v8; // ebx
    int v9; // edi
    _DWORD* v10; // eax
    unsigned __int8* v11; // esi
    int v12; // ebp
    int v13; // ebx
    int v14; // edi
    unsigned __int8* v16; // [esp+10h] [ebp-58h]
    unsigned __int8* v17; // [esp+10h] [ebp-58h]
    int v18; // [esp+14h] [ebp-54h]
    int v19; // [esp+18h] [ebp-50h]
    int v20; // [esp+1Ch] [ebp-4Ch]
    int v21; // [esp+20h] [ebp-48h]
    int v22; // [esp+24h] [ebp-44h]
    wchar_t v23[32]; // [esp+28h] [ebp-40h]

    sub_46AA20(*(int*)& byte_5D4594[1320940], &v21, &v22);
    nox_window_get_size(*(int*)& byte_5D4594[1320940], &v20, &v19);
    sub_47D2C0(*(int*)& byte_5D4594[1320164], v21, v22);
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3711);
    nox_window_call_field_94((int)v0, 16385, (int)& byte_5D4594[1320240], 0);
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3712);
    nox_window_call_field_94((int)v1, 16385, (int)& byte_5D4594[1320868], 0);
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3713);
    nox_window_call_field_94((int)v2, 16385, (int)& byte_5D4594[1320100], 0);
    sub_47D2C0(
        *(int*)& byte_5D4594[1320184],
        v21 + *(_DWORD*)& byte_587000[183696] - 64,
        v22 + *(_DWORD*)& byte_587000[183700] - 64);
    sub_47D2C0(
        *(int*)& byte_5D4594[1320184],
        v21 + *(_DWORD*)& byte_587000[183704] - 64,
        v22 + *(_DWORD*)& byte_587000[183708] - 64);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3708);
    if (*(_DWORD*)& byte_5D4594[1320944])
    {
        sub_47D2C0(*(int*)& byte_5D4594[1320172], v21, v22);
    }
    else if (v3[9] & 4)
    {
        sub_47D2C0(*(int*)& byte_5D4594[1320168], v21, v22);
    }
    if (*(_DWORD*)& byte_5D4594[1320948])
        sub_47D2C0(*(int*)& byte_5D4594[1320176], v21, v22);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3710);
    if (*(_DWORD*)& byte_5D4594[1320960] || v4[9] & 4)
        sub_47D2C0(*(int*)& byte_5D4594[1320180], v21, v22);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
    sub_46AA60(v5, &v21, &v22);
    v6 = &byte_5D4594[1319284];
    v18 = sub_43F320(0);
    v7 = 0;
    v16 = &byte_5D4594[1319284];
    do
    {
        v8 = 0;
        do
        {
            if (*((_DWORD*)v6 + 1))
            {
                *(_DWORD*)(*(_DWORD*)v6 + 12) = v8 + v21 + 25;
                *(_DWORD*)(*(_DWORD*)v6 + 16) = v22 + v7 + 25;
                (*(void(__cdecl * *)(unsigned __int8*, _DWORD))(*(_DWORD*)v6 + 300))(&byte_5D4594[1320188], *(_DWORD*)v6);
                nox_swprintf(v23, L"%d", *((_DWORD*)v6 + 1));
                sub_434390(*(int*)& byte_5D4594[2523948]);
                sub_43F6E0(0, (__int16*)v23, v8 + v21 + 5, v22 + v7 + 5);
                v9 = v22 + v7 + 50;
                nox_swprintf(v23, L"%d", *((_DWORD*)v6 + 34));
                sub_434390(*(int*)& byte_5D4594[2589772]);
                sub_43F6E0(0, (__int16*)v23, v8 + v21 + 5, v9 - v18 - 5);
            }
            v8 += 50;
            v6 += 280;
        } while (v8 < 100);
        v7 += 50;
        v6 = v16 + 140;
        v16 += 140;
    } while ((int)v16 < (int)& byte_5D4594[1319564]);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3705);
    sub_46AA60(v10, &v21, &v22);
    v11 = &byte_5D4594[1320308];
    v12 = 0;
    v17 = &byte_5D4594[1320308];
    do
    {
        v13 = 0;
        do
        {
            if (*((_DWORD*)v11 + 1))
            {
                *(_DWORD*)(*(_DWORD*)v11 + 12) = v13 + v21 + 25;
                *(_DWORD*)(*(_DWORD*)v11 + 16) = v22 + v12 + 25;
                (*(void(__cdecl * *)(unsigned __int8*, _DWORD))(*(_DWORD*)v11 + 300))(&byte_5D4594[1320188], *(_DWORD*)v11);
                nox_swprintf(v23, L"%d", *((_DWORD*)v11 + 1));
                sub_434390(*(int*)& byte_5D4594[2523948]);
                sub_43F6E0(0, (__int16*)v23, v13 + v21 + 5, v22 + v12 + 5);
                v14 = v22 + v12 + 50;
                nox_swprintf(v23, L"%d", *((_DWORD*)v11 + 34));
                sub_434390(*(int*)& byte_5D4594[2589772]);
                sub_43F6E0(0, (__int16*)v23, v13 + v21 + 5, v14 - v18 - 5);
            }
            v13 += 50;
            v11 += 280;
        } while (v13 < 100);
        v12 += 50;
        v11 = v17 + 140;
        v17 += 140;
    } while ((int)v17 < (int)& byte_5D4594[1320588]);
    return 1;
}

//----- (004C1120) --------------------------------------------------------
int __cdecl sub_4C1120(int a1, int a2, wchar_t** a3)
{
    _DWORD* v3; // eax
    wchar_t** v4; // eax
    _DWORD* v5; // eax
    wchar_t* v6; // eax
    int2 a1a; // [esp+0h] [ebp-8h]

    a1a.field_0 = (unsigned __int16)a3;
    a1a.field_4 = (unsigned int)a3 >> 16;
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
    if (sub_46AAB0(v3, (unsigned __int16)a3, (unsigned int)a3 >> 16))
    {
        LOBYTE(v4) = sub_4C0910(&a1a);
    }
    else
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3705);
        if (sub_46AAB0(v5, a1a.field_0, a1a.field_4))
            LOBYTE(v4) = sub_4C11E0(&a1a);
        else
            v4 = a3;
    }
    if (*v4)
    {
        *((_DWORD*)* v4 + 32) = v4[2];
        v6 = sub_4BF050(*v4);
        sub_4776B0(v6);
    }
    return 1;
}
// 4C11AC: variable 'v4' is possibly undefined

//----- (004C11E0) --------------------------------------------------------
char __cdecl sub_4C11E0(_DWORD* a1)
{
    _DWORD* v1; // eax
    int v2; // edi
    int v3; // ebx
    int i; // esi
    int v5; // eax
    int v7; // [esp+10h] [ebp-1Ch]
    int v8; // [esp+14h] [ebp-18h]
    int v9; // [esp+18h] [ebp-14h]
    int4 v10; // [esp+1Ch] [ebp-10h]

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3705);
    sub_46AA60(v1, &v8, &v9);
    v2 = 0;
    v7 = 0;
    while (2)
    {
        v3 = 0;
        for (i = 0; i < 100; i += 50)
        {
            v10.field_0 = i + v8;
            v10.field_8 = i + v8 + 50;
            v10.field_4 = v2 + v9;
            v10.field_C = v2 + v9 + 50;
            v5 = sub_4281F0((int2*)a1, &v10);
            if (v5)
                return (char)& byte_5D4594[140 * (v7 + 2 * v3) + 1320308];
            ++v3;
        }
        v2 += 50;
        ++v7;
        if (v2 < 100)
            continue;
        break;
    }
    return v5;
}
// 4C124E: variable 'v5' is possibly undefined

//----- (004C12A0) --------------------------------------------------------
int sub_4C12A0()
{
    int result; // eax

    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1320940]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1320940] = 0;
    *(_DWORD*)& byte_5D4594[1320964] = 0;
    return result;
}

//----- (004C12C0) --------------------------------------------------------
int sub_4C12C0()
{
    return *(_DWORD*)& byte_5D4594[1320964];
}

//----- (004C12D0) --------------------------------------------------------
int sub_4C12D0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1320964];
    if (*(_DWORD*)& byte_5D4594[1320964])
        result = sub_46A8C0(*(int*)& byte_5D4594[1320940]);
    return result;
}

//----- (004C12F0) --------------------------------------------------------
BOOL __cdecl sub_4C12F0(int* a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
    return sub_46AAB0(v1, *a1, a1[1]);
}

//----- (004C1320) --------------------------------------------------------
int __cdecl sub_4C1320(int a1)
{
    int v1; // esi
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    int v5; // [esp+4h] [ebp-8h]
    int v6; // [esp+8h] [ebp-4h]

    v1 = *(_DWORD*)& byte_5D4594[2618908];
    if (!*(_DWORD*)& byte_5D4594[2618908])
        return 0;
    if (*(_DWORD*)& byte_5D4594[1320964] == 1)
        return 0;
    *(_DWORD*)& byte_5D4594[1320964] = 1;
    sub_4C1410();
    nox_wcscpy((wchar_t*)& byte_5D4594[1319844], (const wchar_t*)(a1 + 2));
    sub_46ABB0(*(int*)& byte_5D4594[1320940], 1);
    sub_4C12D0();
    nox_window_get_size(*(int*)& byte_5D4594[1320940], &v6, &v5);
    sub_46A9B0(*(_DWORD * *)& byte_5D4594[1320940], 198, 193);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3702);
    nox_window_call_field_94((int)v3, 16385, v1 + 4704, 0);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3703);
    nox_window_call_field_94((int)v4, 16385, (int)& byte_5D4594[1319844], 0);
    sub_467BB0();
    return 1;
}

//----- (004C1410) --------------------------------------------------------
int sub_4C1410()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax
    unsigned __int8* v2; // ebp
    unsigned __int8* v3; // esi
    int v4; // ebx
    unsigned __int8* v5; // ebp
    unsigned __int8* v6; // esi
    int v7; // ebx
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    int result; // eax
    wchar_t v12[64]; // [esp+10h] [ebp-80h]

    *(_WORD*)& byte_5D4594[1320240] = 0;
    *(_WORD*)& byte_5D4594[1320868] = 0;
    *(_WORD*)& byte_5D4594[1320100] = 0;
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3702);
    nox_window_call_field_94((int)v0, 16385, (int)& byte_5D4594[1320976], 0);
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3703);
    nox_window_call_field_94((int)v1, 16385, (int)& byte_5D4594[1320980], 0);
    v2 = &byte_5D4594[1319284];
    do
    {
        v3 = v2;
        v4 = 2;
        do
        {
            if (*(_DWORD*)v3)
                sub_45A4B0(*(_QWORD * *)v3);
            *(_DWORD*)v3 = 0;
            *((_DWORD*)v3 + 1) = 0;
            v3 += 280;
            --v4;
        } while (v4);
        v2 += 140;
    } while ((int)v2 < (int)& byte_5D4594[1319564]);
    v5 = &byte_5D4594[1320308];
    do
    {
        v6 = v5;
        v7 = 2;
        do
        {
            if (*(_DWORD*)v6)
                sub_45A4B0(*(_QWORD * *)v6);
            *(_DWORD*)v6 = 0;
            *((_DWORD*)v6 + 1) = 0;
            v6 += 280;
            --v7;
        } while (v7);
        v5 += 140;
    } while ((int)v5 < (int)& byte_5D4594[1320588]);
    nox_swprintf(v12, (const wchar_t*)& byte_5D4594[1319972], 0);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3711);
    nox_window_call_field_94((int)v8, 16385, (int)v12, 0);
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3712);
    nox_window_call_field_94((int)v9, 16385, (int)v12, 0);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3713);
    result = nox_window_call_field_94((int)v10, 16385, (int)v12, 0);
    *(_DWORD*)& byte_5D4594[1320944] = 0;
    *(_DWORD*)& byte_5D4594[1320948] = 0;
    *(_DWORD*)& byte_5D4594[1320968] = 0;
    *(_DWORD*)& byte_5D4594[1320972] = 0;
    *(_DWORD*)& byte_5D4594[1320932] = 0;
    *(_DWORD*)& byte_5D4594[1320936] = 0;
    return result;
}

//----- (004C1590) --------------------------------------------------------
int sub_4C1590()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1320964];
    if (*(_DWORD*)& byte_5D4594[1320964])
    {
        sub_4C1410();
        nox_window_set_hidden(*(int*)& byte_5D4594[1320940], 1);
        sub_46ABB0(*(int*)& byte_5D4594[1320940], 0);
        *(_DWORD*)& byte_5D4594[1320964] = 0;
        result = sub_467C10();
    }
    return result;
}

//----- (004C15D0) --------------------------------------------------------
int __cdecl sub_4C15D0(int a1)
{
    int result; // eax
    int v2; // ebp
    unsigned __int8* v3; // ebx
    int v4; // esi
    int v5; // edi
    unsigned __int8* v6; // esi
    int v7; // ebp
    unsigned __int8* v8; // ebx
    int v9; // esi
    int v10; // edi
    wchar_t* v11; // eax
    unsigned __int8* v12; // [esp+8h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1320964];
    v2 = 0;
    v12 = 0;
    if (*(_DWORD*)& byte_5D4594[1320964])
    {
        v3 = &byte_5D4594[1319284];
        while (2)
        {
            v4 = 0;
            v5 = (int)v3;
            do
            {
                if (sub_4C1760(v5, *(unsigned __int16*)(a1 + 2)))
                {
                    v6 = &byte_5D4594[140 * (v2 + 2 * v4) + 1319284];
                    goto LABEL_18;
                }
                ++v4;
                v5 += 280;
            } while (v4 < 2);
            v3 += 140;
            ++v2;
            if ((int)v3 < (int)& byte_5D4594[1319564])
                continue;
            break;
        }
        v7 = 0;
        v8 = &byte_5D4594[1320308];
        while (2)
        {
            v9 = 0;
            v10 = (int)v8;
            do
            {
                if (sub_4C1760(v10, *(unsigned __int16*)(a1 + 2)))
                {
                    v12 = &byte_5D4594[140 * (v7 + 2 * v9) + 1320308];
                    goto LABEL_17;
                }
                ++v9;
                v10 += 280;
            } while (v9 < 2);
            v8 += 140;
            ++v7;
            if ((int)v8 < (int)& byte_5D4594[1320588])
                continue;
            break;
        }
        v11 = loadString_sub_40F1D0((char*)& byte_587000[184292], 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 1141);
        sub_445490(v11);
    LABEL_17:
        v6 = v12;
    LABEL_18:
        *((_DWORD*)v6 + 34) -= *((_DWORD*)v6 + 34) / *((_DWORD*)v6 + 1);
        sub_4C1710((int)v6, *(unsigned __int16*)(a1 + 2));
        result = *((_DWORD*)v6 + 1) - 1;
        *((_DWORD*)v6 + 1) = result;
        if (!result)
        {
            result = sub_45A4B0(*(_QWORD * *)v6);
            *(_DWORD*)v6 = 0;
        }
    }
    return result;
}

//----- (004C1710) --------------------------------------------------------
int __cdecl sub_4C1710(int a1, int a2)
{
    int result; // eax
    _DWORD* i; // ecx
    _DWORD* v4; // ecx
    int v5; // edx

    result = 0;
    for (i = (_DWORD*)(a1 + 8); *i != a2; ++i)
    {
        if (++result >= 32)
            return result;
    }
    if (result < 31)
    {
        v4 = (_DWORD*)(a1 + 4 * result + 8);
        v5 = 31 - result;
        do
        {
            result = v4[1];
            *v4 = result;
            ++v4;
            --v5;
        } while (v5);
    }
    *(_DWORD*)(a1 + 132) = 0;
    return result;
}

//----- (004C1760) --------------------------------------------------------
int __cdecl sub_4C1760(int a1, int a2)
{
    int v2; // eax
    _DWORD* i; // ecx

    if (!*(_DWORD*)(a1 + 4))
        return 0;
    v2 = 0;
    for (i = (_DWORD*)(a1 + 8); *i != a2; ++i)
    {
        if (++v2 >= 32)
            return 0;
    }
    return 1;
}

//----- (004C1790) --------------------------------------------------------
char* __cdecl sub_4C1790(int a1)
{
    char* result; // eax
    int v2; // ebp
    char* v3; // esi
    _DWORD* v4; // eax
    int v5; // ecx
    int* v6; // ebx
    _BYTE* v7; // edi
    int v8; // eax
    int v9; // eax
    int v10; // [esp+10h] [ebp+4h]

    result = *(char**)& byte_5D4594[1320964];
    if (!*(_DWORD*)& byte_5D4594[1320964])
        return result;
    v2 = a1;
    *(_DWORD*)& byte_5D4594[1320944] = 0;
    *(_DWORD*)& byte_5D4594[1320948] = 0;
    if (*(_BYTE*)(a1 + 2) == 1)
    {
        v3 = *(char**)& byte_5D4594[1320932];
        if (*(_DWORD*)& byte_5D4594[1320932])
        {
            result = (char*)sub_4C18E0(*(unsigned __int16*)(a1 + 3), *(_DWORD * *)& byte_5D4594[1320932]);
            if (result)
                goto LABEL_12;
            result = sub_4C1910(*(unsigned __int16*)(a1 + 3));
        }
        else
        {
            result = sub_4C1910(*(unsigned __int16*)(a1 + 3));
        }
    }
    else
    {
        v3 = *(char**)& byte_5D4594[1320936];
        if (*(_DWORD*)& byte_5D4594[1320936])
        {
            result = (char*)sub_4C18E0(*(unsigned __int16*)(a1 + 3), *(_DWORD * *)& byte_5D4594[1320936]);
            if (result)
                goto LABEL_12;
            result = sub_4C19C0(*(unsigned __int16*)(a1 + 3));
        }
        else
        {
            result = sub_4C19C0(*(unsigned __int16*)(a1 + 3));
        }
    }
    v3 = result;
LABEL_12:
    if (v3)
    {
        if (!*(_DWORD*)v3)
        {
            v4 = sub_45A240(*(unsigned __int16*)(a1 + 3));
            *(_DWORD*)v3 = v4;
            if (v4[28] & 0x13001000)
            {
                v5 = -11 - a1;
                v6 = v4 + 108;
                v7 = (_BYTE*)(a1 + 11);
                v10 = -11 - a1;
                do
                {
                    if (*v7 == -1)
                    {
                        *v6 = 0;
                    }
                    else
                    {
                        v8 = sub_413330((unsigned __int8)* v7);
                        v5 = v10;
                        *v6 = v8;
                    }
                    ++v7;
                    ++v6;
                } while ((int)& v7[v5] < 4);
            }
            *((_DWORD*)v3 + 1) = 0;
            *((_DWORD*)v3 + 34) = 0;
        }
        *(_DWORD*)& v3[4 * *((_DWORD*)v3 + 1) + 8] = *(unsigned __int16*)(v2 + 5);
        v9 = *((_DWORD*)v3 + 34);
        ++* ((_DWORD*)v3 + 1);
        result = (char*)(*(_DWORD*)(v2 + 7) + v9);
        *((_DWORD*)v3 + 34) = result;
        *(_DWORD*)& byte_5D4594[1320932] = 0;
        *(_DWORD*)& byte_5D4594[1320936] = 0;
    }
    return result;
}

//----- (004C18E0) --------------------------------------------------------
int __cdecl sub_4C18E0(int a1, _DWORD* a2)
{
    if (!a2[1])
        return 1;
    if (*(_DWORD*)(*a2 + 108) != a1 || *(_DWORD*)(*a2 + 112) & 0x13001000)
        return 0;
    return 1;
}

//----- (004C1910) --------------------------------------------------------
char* __cdecl sub_4C1910(int a1)
{
    int v1; // edi
    unsigned __int8* v2; // esi
    int v3; // ecx
    unsigned __int8* v4; // edx
    int v5; // eax
    int v6; // esi
    unsigned __int8* v7; // edx
    int v8; // eax
    unsigned __int8* v9; // ecx

    v1 = 0;
    v2 = &byte_5D4594[1319284];
    while (2)
    {
        v3 = 0;
        v4 = v2;
        do
        {
            v5 = *(_DWORD*)v4;
            if (*(_DWORD*)v4 && *(_DWORD*)(v5 + 108) == a1 && !(*(_DWORD*)(v5 + 112) & 0x13001000))
                return (char*)& byte_5D4594[140 * (v1 + 2 * v3) + 1319284];
            ++v3;
            v4 += 280;
        } while (v3 < 2);
        v2 += 140;
        ++v1;
        if ((int)v2 < (int)& byte_5D4594[1319564])
            continue;
        break;
    }
    v6 = 0;
    v7 = &byte_5D4594[1319284];
    while (2)
    {
        v8 = 0;
        v9 = v7;
        do
        {
            if (!*(_DWORD*)v9)
                return (char*)& byte_5D4594[140 * (v6 + 2 * v8) + 1319284];
            ++v8;
            v9 += 280;
        } while (v8 < 2);
        v7 += 140;
        ++v6;
        if ((int)v7 < (int)& byte_5D4594[1319564])
            continue;
        break;
    }
    return 0;
}

//----- (004C19C0) --------------------------------------------------------
char* __cdecl sub_4C19C0(int a1)
{
    int v1; // edi
    unsigned __int8* v2; // esi
    int v3; // ecx
    unsigned __int8* v4; // edx
    int v5; // eax
    int v6; // esi
    unsigned __int8* v7; // edx
    int v8; // eax
    unsigned __int8* v9; // ecx

    v1 = 0;
    v2 = &byte_5D4594[1320308];
    while (2)
    {
        v3 = 0;
        v4 = v2;
        do
        {
            v5 = *(_DWORD*)v4;
            if (*(_DWORD*)v4 && *(_DWORD*)(v5 + 108) == a1 && !(*(_DWORD*)(v5 + 112) & 0x13001000))
                return (char*)& byte_5D4594[140 * (v1 + 2 * v3) + 1320308];
            ++v3;
            v4 += 280;
        } while (v3 < 2);
        v2 += 140;
        ++v1;
        if ((int)v2 < (int)& byte_5D4594[1320588])
            continue;
        break;
    }
    v6 = 0;
    v7 = &byte_5D4594[1320308];
    while (2)
    {
        v8 = 0;
        v9 = v7;
        do
        {
            if (!*(_DWORD*)v9)
                return (char*)& byte_5D4594[140 * (v6 + 2 * v8) + 1320308];
            ++v8;
            v9 += 280;
        } while (v8 < 2);
        v7 += 140;
        ++v6;
        if ((int)v7 < (int)& byte_5D4594[1320588])
            continue;
        break;
    }
    return 0;
}

//----- (004C1A70) --------------------------------------------------------
char* __cdecl sub_4C1A70(int a1, int* a2)
{
    _DWORD* v2; // eax
    int v3; // ecx
    _DWORD* v4; // eax
    _DWORD* v5; // edi
    char* v6; // eax
    char* result; // eax
    char v8[4]; // [esp+0h] [ebp-14h]
    int2 a1a; // [esp+4h] [ebp-10h]
    int v10; // [esp+Ch] [ebp-8h]
    int v11; // [esp+10h] [ebp-4h]

    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3704);
    sub_46AA60(v2, &v10, &v11);
    v3 = v11 + 25;
    if (a2)
    {
        v3 = a2[1];
        a1a.field_0 = *a2;
    }
    else
    {
        a1a.field_0 = v10 + 25;
    }
    a1a.field_4 = v3;
    LOBYTE(v4) = sub_4C0910(&a1a);
    v5 = v4;
    if (sub_4C18E0(*(_DWORD*)(a1 + 108), v4))
    {
        *(_DWORD*)& byte_5D4594[1320932] = v5;
        v6 = sub_4C1910(*(_DWORD*)(a1 + 108));
        if (v6)
        {
            if (*((_DWORD*)v6 + 1))
                * (_DWORD*)& byte_5D4594[1320932] = v6;
        }
    }
    else
    {
        result = sub_4C1910(*(_DWORD*)(a1 + 108));
        *(_DWORD*)& byte_5D4594[1320932] = result;
        if (!result)
            return result;
    }
    v8[0] = -55;
    v8[1] = 15;
    *(_WORD*)& v8[2] = sub_578B00(a1);
    return (char*)sub_40EBC0(31, 0, v8, 4);
}
// 4C1ACF: variable 'v4' is possibly undefined

//----- (004C1B50) --------------------------------------------------------
int __cdecl sub_4C1B50(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1320964];
    if (*(_DWORD*)& byte_5D4594[1320964])
    {
        nox_swprintf((wchar_t*)& byte_5D4594[1320240], L"%d", *(_DWORD*)(a1 + 2));
        if (*(_DWORD*)(a1 + 6))
            nox_swprintf((wchar_t*)& byte_5D4594[1320868], L"(%d)", *(_DWORD*)(a1 + 6));
        else
            nox_wcscpy((wchar_t*)& byte_5D4594[1320868], (const wchar_t*)& byte_5D4594[1320984]);
        result = nox_swprintf((wchar_t*)& byte_5D4594[1320100], L"%d", *(_DWORD*)(a1 + 10));
    }
    return result;
}

//----- (004C1BC0) --------------------------------------------------------
int __cdecl sub_4C1BC0(int a1)
{
    unsigned int v1; // edx
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1320964];
    if (*(_DWORD*)& byte_5D4594[1320964])
    {
        result = a1;
        *(_DWORD*)& byte_5D4594[1320944] = *(_BYTE*)(a1 + 2) & 1;
        LOBYTE(v1) = *(_BYTE*)(a1 + 2);
        *(_DWORD*)& byte_5D4594[1320948] = (v1 >> 1) & 1;
    }
    return result;
}
// 4C1BDC: variable 'v1' is possibly undefined

//----- (004C1BF0) --------------------------------------------------------
int sub_4C1BF0()
{
    int result; // eax
    int v1; // esi
    _DWORD* v2; // eax
    _DWORD* v3; // eax

    result = *(_DWORD*)& byte_5D4594[1320964];
    v1 = *(_DWORD*)& byte_5D4594[2618908];
    if (*(_DWORD*)& byte_5D4594[1320964])
    {
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            sub_4C1410();
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3702);
            nox_window_call_field_94((int)v2, 16385, v1 + 4704, 0);
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1320940], 3703);
            result = nox_window_call_field_94((int)v3, 16385, (int)& byte_5D4594[1319844], 0);
        }
    }
    return result;
}

//----- (004C1C60) --------------------------------------------------------
int __fastcall sub_4C1C60(int a1, int a2)
{
    return (unsigned __int64)(a2 * (__int64)a1) >> 16;
}

//----- (004C1C70) --------------------------------------------------------
int __fastcall sub_4C1C70(int a1, int a2)
{
    return ((__int64)a1 << 16) / a2;
}

//----- (004C1C80) --------------------------------------------------------
int __cdecl sub_4C1C80(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[184444] = a1;
    return result;
}

//----- (004C1C90) --------------------------------------------------------
int sub_4C1C90()
{
    return *(_DWORD*)& byte_587000[184444];
}

//----- (004C1CA0) --------------------------------------------------------
int __cdecl sub_4C1CA0(int a1)
{
    int result; // eax

    *(_DWORD*)& byte_587000[184448] = a1;
    if (a1 == 3)
    {
        sub_46AE60(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321020]);
        sub_46AEC0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321016]);
        result = sub_46AEA0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321016]);
    }
    else if (a1 == 4)
    {
        sub_46AE60(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321028]);
        sub_46AEC0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321024]);
        result = sub_46AEA0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321024]);
    }
    else
    {
        result = a1 - 5;
        if (a1 == 5)
        {
            sub_46AE60(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321012]);
            sub_46AEC0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321008]);
            result = sub_46AEA0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321008]);
        }
    }
    return result;
}

//----- (004C1D70) --------------------------------------------------------
int sub_4C1D70()
{
    return *(_DWORD*)& byte_587000[184448];
}

//----- (004C1D80) --------------------------------------------------------
int sub_4C1D80()
{
    wchar_t* v0; // eax
    _DWORD* v1; // esi
    char* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    int v5; // edx
    unsigned __int8* v6; // eax

    *(_DWORD*)& byte_5D4594[1321004] = 0;
    *(_DWORD*)& byte_5D4594[1321000] = -145;
    *(_DWORD*)& byte_5D4594[1320988] = nox_win_width - 95;
    *(_DWORD*)& byte_5D4594[1320992] = -145;
    *(_DWORD*)& byte_5D4594[1321032] = nox_window_new(0, 8, nox_win_width - 95, -145, 87, 115, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1321032], sub_4C2BD0, sub_4C24A0, 0);
    *(_DWORD*)& byte_5D4594[1321036] = nox_window_new(*(int*)& byte_5D4594[1321032], 136, 5, 38, 76, 76, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1321036], sub_4C2B10, sub_4C1FE0, sub_4C2C20);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[184592], 0, "C:\\NoxPost\\src\\Client\\Gui\\guisumn.c", 818);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1321036] + 36), v0);
    *(_DWORD*)& byte_5D4594[1320996] = sub_42F970("CreatureCageBottom");
    v1 = nox_window_new(*(int*)& byte_5D4594[1321036], 160, 0, 0, 1, 1, 0);
    v2 = sub_42F970("CreatureCageTop");
    sub_46AE60((int)v1, (int)v2);
    sub_46AE40((int)v1, -5, -38);
    v3 = nox_window_new(*(int*)& byte_5D4594[1321032], 8, 19, 0, 48, 39, 0);
    nox_window_set_all_funcs(v3, sub_4C2BE0, sub_4C24A0, 0);
    *(_DWORD*)& byte_5D4594[1321008] = sub_42F970("CreatureCageHuntButtonLit");
    *(_DWORD*)& byte_5D4594[1321012] = sub_42F970("CreatureCageHuntButton");
    *(_DWORD*)& byte_5D4594[1321016] = sub_42F970("CreatureCageGuardButtonLit");
    *(_DWORD*)& byte_5D4594[1321020] = sub_42F970("CreatureCageGuardButton");
    *(_DWORD*)& byte_5D4594[1321024] = sub_42F970("CreatureCageEscortButtonLit");
    *(_DWORD*)& byte_5D4594[1321028] = sub_42F970("CreatureCageEscortButton");
    v4 = nox_window_new(0, 168, *(_DWORD*)& byte_5D4594[1320988] + 27, *(_DWORD*)& byte_5D4594[1320992] + 12, 34, 34, 0);
    *(_DWORD*)& byte_5D4594[1321040] = v4;
    v5 = v4[11];
    BYTE1(v5) |= 1u;
    v4[11] = v5;
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1321040], sub_4C24B0, 0, sub_4C2CE0);
    sub_46AE60(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321028]);
    sub_46AEC0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321024]);
    sub_46AEA0(*(int*)& byte_5D4594[1321040], *(int*)& byte_5D4594[1321024]);
    sub_46AE40(*(int*)& byte_5D4594[1321040], -27, -12);
    byte_5D4594[1321200] = 0;
    nox_window_set_hidden(*(int*)& byte_5D4594[1321032], 1);
    nox_window_set_hidden(*(int*)& byte_5D4594[1321040], 1);
    v6 = &byte_5D4594[1321060];
    do
    {
        *(_DWORD*)v6 = 0;
        v6 += 32;
    } while ((int)v6 < (int)& byte_5D4594[1321188]);
    sub_4C2BF0();
    *(_DWORD*)& byte_5D4594[1321044] = 0;
    *(_DWORD*)& byte_5D4594[1321204] = 0;
    *(_DWORD*)& byte_5D4594[1321196] = 0;
    return 1;
}

//----- (004C1FE0) --------------------------------------------------------
int __cdecl sub_4C1FE0(_DWORD* a1)
{
    int2* v1; // ebp
    unsigned __int8* v2; // ebx
    int v3; // ebp
    int v4; // eax
    int v5; // esi
    int v6; // eax
    int v7; // edi
    int v8; // ebp
    int v9; // edi
    BOOL v10; // edi
    int v11; // ecx
    int v13; // ebx
    int* v14; // esi
    _DWORD* v15; // eax
    int v17; // [esp-18h] [ebp-4Ch]
    int v18; // [esp-14h] [ebp-48h]
    char v19; // [esp+7h] [ebp-2Dh]
    int v20; // [esp+8h] [ebp-2Ch]
    int v21; // [esp+Ch] [ebp-28h]
    int v22; // [esp+10h] [ebp-24h]
    int v23; // [esp+14h] [ebp-20h]
    int2* v24; // [esp+18h] [ebp-1Ch]
    int2 a1a; // [esp+1Ch] [ebp-18h]
    int v26; // [esp+24h] [ebp-10h]
    int v27; // [esp+28h] [ebp-Ch]
    int v28; // [esp+2Ch] [ebp-8h]
    int v29; // [esp+30h] [ebp-4h]

    v1 = sub_4309F0();
    v24 = v1;
    if (byte_5D4594[1321200] == 1)
    {
        *(_DWORD*)& byte_5D4594[1320992] += 20;
        if (*(_DWORD*)& byte_5D4594[1320992] >= *(int*)& byte_5D4594[1321004])
        {
            *(_DWORD*)& byte_5D4594[1320992] = *(_DWORD*)& byte_5D4594[1321004];
            byte_5D4594[1321200] = 2;
        }
    }
    else if (byte_5D4594[1321200] == 3)
    {
        *(_DWORD*)& byte_5D4594[1320992] -= 20;
        if (*(_DWORD*)& byte_5D4594[1320992] <= *(int*)& byte_5D4594[1321000])
        {
            *(_DWORD*)& byte_5D4594[1320992] = *(_DWORD*)& byte_5D4594[1321000];
            byte_5D4594[1321200] = 0;
            nox_window_set_hidden(*(int*)& byte_5D4594[1321032], 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1321040], 1);
        }
    }
    sub_46A9B0(*(_DWORD * *)& byte_5D4594[1321032], *(int*)& byte_5D4594[1320988], *(int*)& byte_5D4594[1320992]);
    sub_46A9B0(
        *(_DWORD * *)& byte_5D4594[1321040],
        *(_DWORD*)& byte_5D4594[1320988] + 27,
        *(_DWORD*)& byte_5D4594[1320992] + 12);
    sub_46AA60(a1, &v28, &v29);
    nox_window_get_size((int)a1, &v21, &v20);
    sub_43F320(0);
    if (*(_DWORD*)& byte_5D4594[1320996])
        sub_47D2C0(*(int*)& byte_5D4594[1320996], *(int*)& byte_5D4594[1320988], *(int*)& byte_5D4594[1320992]);
    v2 = &byte_5D4594[1321064];
    do
    {
        if (*((_DWORD*)v2 - 1))
        {
            switch (v2[8])
            {
            case 1u:
                v22 = 1;
                v23 = 1;
                break;
            case 2u:
                v22 = 1;
                v23 = 2;
                break;
            case 4u:
                v22 = 2;
                v23 = 2;
                break;
            }
            v3 = v28 + 38 * *(_DWORD*)v2 + 2;
            v4 = *((_DWORD*)v2 + 1);
            a1a.field_0 = v28 + 38 * *(_DWORD*)v2 + 2;
            v5 = v29 + 38 * v4 + 2;
            v21 = 38 * v22 - 4;
            v20 = 38 * v23 - 4;
            if (*((_DWORD*)v2 + 4))
            {
                sub_434460(*(int*)& byte_5D4594[2589772]);
                v18 = v20;
                v17 = v21;
                *((_DWORD*)v2 + 4) = 0;
                sub_49CE30(v3, v5, v17, v18);
            }
            else
            {
                v6 = sub_4C2440(*((_DWORD*)v2 - 2));
                if (v6)
                {
                    sub_47D2C0(v6, v3, v5);
                }
                else
                {
                    v7 = v3 + v21 / 2;
                    v8 = v5 + v20 / 2;
                    sub_434460(*(int*)& byte_5D4594[2650660]);
                    sub_4B0BC0(v7, v8, 9);
                    sub_4C3270(v7, v8, 9, *(int*)& byte_5D4594[2614248]);
                    v3 = a1a.field_0;
                }
            }
            if (sub_495180(*((_DWORD*)v2 - 3), &v27, &v26, &v19))
            {
                if ((_WORD)v26)
                    v9 = v20 * (unsigned __int16)v27 / (unsigned __int16)v26;
                else
                    v9 = 0;
                if (v19)
                    sub_434460(*(int*)& byte_5D4594[2650688]);
                else
                    sub_434460(*(int*)& byte_5D4594[2598268]);
                sub_49CE30(v21 + v3 - 2, v5, 2, v20);
                if (v19)
                    sub_434460(*(int*)& byte_5D4594[2618904]);
                else
                    sub_434460(*(int*)& byte_5D4594[2650644]);
                sub_49CE30(v21 + v3 - 2, v20 + v5 - v9, 2, v9);
            }
            v1 = v24;
        }
        v2 += 32;
    } while ((int)v2 < (int)& byte_5D4594[1321192]);
    v10 = sub_46AAB0(*(_DWORD * *)& byte_5D4594[1321040], v1->field_0, v1->field_4);
    if (sub_46AAB0(a1, v1->field_0, v1->field_4) || v10 || *(_DWORD*)& byte_5D4594[1321212] == 1)
    {
        v11 = v1->field_4;
        a1a.field_0 = (v1->field_0 - v28) / 38;
        a1a.field_4 = (v11 - v29) / 38;
        v13 = sub_4C2410(&a1a);
        *(_DWORD*)& byte_5D4594[1321212] = 0;
        v14 = (int*)sub_4C2D60();
        if (v14)
        {
            do
            {
                v15 = sub_45A6F0(*v14);
                if (v15)
                {
                    if (v14 == (int*)v13 || v10)
                    {
                        v15[30] |= 0x40000000u;
                        *(_DWORD*)& byte_5D4594[1321212] = 1;
                    }
                    else
                    {
                        v15[30] &= 0xBFFFFFFF;
                    }
                }
                v14 = (int*)sub_4C2D90((int)v14);
            } while (v14);
            v1 = v24;
        }
    }
    if (*(_DWORD*)& byte_5D4594[1321044] && !sub_46AAB0(*(_DWORD * *)& byte_5D4594[1321044], v1->field_0, v1->field_4))
        sub_4C2470();
    return 1;
}

//----- (004C2410) --------------------------------------------------------
int __cdecl sub_4C2410(int2* a1)
{
    int result; // eax
    int v2; // edx
    int v3; // ecx

    result = 0;
    if (a1)
    {
        v2 = a1->field_0;
        if (a1->field_0 >= 0 && v2 < 2)
        {
            v3 = a1->field_4;
            if (v3 >= 0 && v3 < 2)
                result = *(_DWORD*)& byte_5D4594[4 * (v3 + 2 * v2) + 1321180];
        }
    }
    return result;
}

//----- (004C2440) --------------------------------------------------------
int __cdecl sub_4C2440(int a1)
{
    const char* v1; // eax
    int v2; // eax

    v1 = (const char*)nox_get_thing_name(a1);
    if (!v1)
        return 0;
    v2 = sub_427010(v1);
    return sub_427430(v2);
}

//----- (004C2470) --------------------------------------------------------
int sub_4C2470()
{
    int result; // eax

    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1321044]);
    *(_DWORD*)& byte_5D4594[1321044] = 0;
    *(_DWORD*)& byte_5D4594[1321204] = 0;
    sub_452D80(920, 100);
    result = *(_DWORD*)& byte_5D4594[1321040];
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321040] + 36) &= 0xFFFFFFFD;
    return result;
}

//----- (004C24A0) --------------------------------------------------------
int sub_4C24A0()
{
    return 1;
}

//----- (004C24B0) --------------------------------------------------------
int __cdecl sub_4C24B0(int a1, int a2, unsigned int a3)
{
    int2 a1a; // [esp+0h] [ebp-8h]

    switch (a2)
    {
    case 5:
    case 6:
        return 1;
    case 7:
        *(_DWORD*)& byte_5D4594[1321204] = 0;
        a1a.field_4 = a3 >> 16;
        a1a.field_0 = (unsigned __int16)a3;
        sub_4C2560(&a1a);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321040] + 36) |= 2u;
        return 1;
    case 17:
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321040] + 36) |= 2u;
        return 0;
    case 18:
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321040] + 36) &= 0xFFFFFFFD;
        return 0;
    default:
        return 0;
    }
}

//----- (004C2560) --------------------------------------------------------
_DWORD* __cdecl sub_4C2560(int2* a1)
{
    char** v1; // esi
    unsigned __int16* v2; // eax
    int v3; // esi
    bool v4; // sf
    int v5; // ecx
    int v6; // edi
    int v7; // eax
    int v8; // edi
    int i; // ebp
    _DWORD* v10; // ebx
    int v12; // [esp+10h] [ebp-8h]
    int v13; // [esp+14h] [ebp-4h]

    *(_DWORD*)& byte_587000[184452] = 0;
    v1 = (char**)& byte_587000[184344];
    do
    {
        if (v1 != (char**)& byte_587000[184352])
        {
            v2 = loadString_sub_40F1D0(*v1, 0, "C:\\NoxPost\\src\\Client\\Gui\\guisumn.c", 588);
            sub_43F840(0, v2, &v12, &v13, nox_win_width);
            if (*(_DWORD*)& byte_587000[184452] < v12)
                * (_DWORD*)& byte_587000[184452] = v12;
        }
        ++v1;
    } while ((int)v1 < (int)& byte_587000[184368]);
    *(_DWORD*)& byte_587000[184452] += 8;
    v3 = sub_43F320(0) + 2;
    v5 = a1->field_0 - *(_DWORD*)& byte_587000[184452] / 2;
    v4 = v5 < 0;
    v12 = a1->field_0 - *(_DWORD*)& byte_587000[184452] / 2;
    v6 = 5 * v3 + 12;
    if (v4)
    {
        v5 = 0;
    }
    else
    {
        if (*(_DWORD*)& byte_587000[184452] + v5 < nox_win_width)
            goto LABEL_11;
        v5 = nox_win_width - *(_DWORD*)& byte_587000[184452] - 1;
    }
    v12 = v5;
LABEL_11:
    v7 = a1->field_4 - v6 / 2;
    v13 = v7;
    if (v7 < 0)
    {
        v7 = 0;
    LABEL_15:
        v13 = v7;
        goto LABEL_16;
    }
    if (v6 + v7 >= nox_win_height)
    {
        v7 = nox_win_width - v6 - 1;
        goto LABEL_15;
    }
LABEL_16:
    *(_DWORD*)& byte_5D4594[1321044] = nox_window_new(0, 40, v5, v7, *(int*)& byte_587000[184452], 5 * v3 + 12, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1321044], 0, sub_4C26F0, 0);
    sub_46A8C0(*(int*)& byte_5D4594[1321044]);
    v8 = 0;
    for (i = 0; i < 6; ++i)
    {
        if (i != 2)
        {
            v10 = nox_window_new(*(int*)& byte_5D4594[1321044], 8, 0, v8, *(int*)& byte_587000[184452], v3 + 1, 0);
            nox_window_set_all_funcs(v10, sub_4C2A60, sub_4C27F0, 0);
            v10[8] = i;
            v8 += v3 + 2;
        }
    }
    return sub_452D80(791, 100);
}

//----- (004C26F0) --------------------------------------------------------
int __cdecl sub_4C26F0(int yTop)
{
    int v1; // esi
    int result; // eax
    int xLeft; // [esp+4h] [ebp-Ch]
    int v4; // [esp+8h] [ebp-8h]
    int v5; // [esp+Ch] [ebp-4h]

    v1 = yTop;
    sub_46AA60((_DWORD*)yTop, &xLeft, &yTop);
    nox_window_get_size(v1, &v4, &v5);
    sub_49CF10(xLeft, yTop, v4, v5);
    sub_434460(*(int*)& byte_5D4594[2650648]);
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
    result = 1;
    *(_DWORD*)& byte_5D4594[3799524] = 1;
    return result;
}

//----- (004C27F0) --------------------------------------------------------
int __cdecl sub_4C27F0(_DWORD* a1)
{
    int result; // eax
    unsigned __int16* v2; // edi
    int2* v3; // ebp
    int v4; // esi
    int v5; // ebx
    int v6; // edx
    int v7; // ebx
    int v8; // [esp-18h] [ebp-24h]
    __int16* v9; // [esp-14h] [ebp-20h]
    int v10; // [esp+0h] [ebp-Ch]
    int v11; // [esp+4h] [ebp-8h]
    int v12; // [esp+8h] [ebp-4h]

    if (!*(_DWORD*)& byte_5D4594[1321208])
        * (_DWORD*)& byte_5D4594[1321208] = sub_4E3AA0((CHAR*)& byte_587000[184840]);
    if (*(_DWORD*)& byte_5D4594[1321204] || (result = 1, a1[8] != 1))
    {
        v2 = loadString_sub_40F1D0(*(char**)& byte_587000[4 * a1[8] + 184344], 0, "C:\\NoxPost\\src\\Client\\Gui\\guisumn.c", 446);
        sub_46AA60(a1, &v11, &v10);
        sub_43F840(0, v2, &v12, 0, 0);
        v3 = sub_4309F0();
        sub_43F320(0);
        v4 = (*(_DWORD*)& byte_587000[184452] - v12) / 2 + 1;
        if (sub_46AAB0(a1, v3->field_0, v3->field_4))
        {
            sub_4C2A00(v11 + v4, v10 + 3, *(int*)& byte_5D4594[2589772], *(int*)& byte_5D4594[2650656], (__int16*)v2);
            if (a1[8] != *(_DWORD*)& byte_587000[184552])
            {
                *(_DWORD*)& byte_587000[184552] = a1[8];
                sub_452D80(920, 100);
                return 1;
            }
            return 1;
        }
        if (*(_DWORD*)& byte_5D4594[1321204])
        {
            if (sub_4C2DD0(*(int*)& byte_5D4594[1321204]))
            {
                sub_4C2A00(v11 + v4, v10 + 3, *(int*)& byte_5D4594[2523948], *(int*)& byte_5D4594[2650656], (__int16*)v2);
                return 1;
            }
            v5 = a1[8];
            if (v5 != 4 && v5 != 5)
            {
                sub_4C2A00(v11 + v4, v10 + 3, *(int*)& byte_5D4594[2523948], *(int*)& byte_5D4594[2650656], (__int16*)v2);
                return 1;
            }
            v6 = *(_DWORD*)& byte_5D4594[2650660];
            v9 = (__int16*)v2;
            v8 = *(_DWORD*)& byte_5D4594[2650656];
        }
        else
        {
            v7 = a1[8];
            if (v7 != 4 && v7 != 5)
            {
                sub_4C2A00(v11 + v4, v10 + 3, *(int*)& byte_5D4594[2650684], *(int*)& byte_5D4594[2650656], (__int16*)v2);
                return 1;
            }
            v9 = (__int16*)v2;
            if (!sub_4C2E00())
            {
                sub_4C2A00(v11 + v4, v10 + 3, *(int*)& byte_5D4594[2650660], *(int*)& byte_5D4594[2650656], (__int16*)v2);
                return 1;
            }
            v6 = *(_DWORD*)& byte_5D4594[2650684];
            v8 = *(_DWORD*)& byte_5D4594[2650656];
        }
        sub_4C2A00(v11 + v4, v10 + 3, v6, v8, v9);
        return 1;
    }
    return result;
}

//----- (004C2A00) --------------------------------------------------------
int __cdecl sub_4C2A00(int a1, int a2, int a3, int a4, __int16* a5)
{
    unsigned __int8* v5; // esi

    sub_434390(a4);
    v5 = &byte_587000[184520];
    do
    {
        sub_43F6E0(0, a5, a1 + *(_DWORD*)v5, a2 + *((_DWORD*)v5 + 1));
        v5 += 8;
    } while ((int)v5 < (int)& byte_587000[184552]);
    sub_434390(a3);
    return sub_43F6E0(0, a5, a1, a2);
}

//----- (004C2A60) --------------------------------------------------------
int __cdecl sub_4C2A60(int a1, unsigned int a2)
{
    int result; // eax

    if (a2 >= 5)
    {
        if (a2 <= 6)
            return 1;
        if (a2 == 7)
        {
            LOBYTE(a2) = 120;
            result = *(_DWORD*)(a1 + 32);
            if (result == 2)
                return 1;
            if (*(_DWORD*)& byte_5D4594[1321204])
            {
                *(_WORD*)((char*)& a2 + 1) = **(_WORD * *)& byte_5D4594[1321204];
            }
            else
            {
                if (result == 1)
                    return result;
                *(_WORD*)((char*)& a2 + 1) = 0;
            }
            HIBYTE(a2) = *(_BYTE*)(a1 + 32);
            sub_40EBC0(31, 0, &a2, 4);
            sub_4C2470();
            if (!*(_DWORD*)(a1 + 32))
            {
                sub_452D80(777, 100);
                return 1;
            }
            sub_452D80(898, 100);
            return 1;
        }
    }
    return 0;
}

//----- (004C2B10) --------------------------------------------------------
int __cdecl sub_4C2B10(_DWORD* a1, unsigned int a2, unsigned int a3)
{
    int2 v5; // [esp+0h] [ebp-10h]
    int2 a1a; // [esp+8h] [ebp-8h]

    if (a2 >= 5)
    {
        if (a2 <= 6)
            return 1;
        if (a2 == 7)
        {
            v5.field_4 = a3 >> 16;
            v5.field_0 = (unsigned __int16)a3;
            sub_46AA60(a1, &a2, &a3);
            a1a.field_0 = (v5.field_0 - (int)a2) / 38;
            a1a.field_4 = (v5.field_4 - (int)a3) / 38;
            *(_DWORD*)& byte_5D4594[1321204] = sub_4C2410(&a1a);
            if (*(_DWORD*)& byte_5D4594[1321204])
                sub_4C2560(&v5);
            return 1;
        }
    }
    return 0;
}

//----- (004C2BD0) --------------------------------------------------------
int sub_4C2BD0()
{
    return 0;
}

//----- (004C2BE0) --------------------------------------------------------
int sub_4C2BE0()
{
    return 1;
}

//----- (004C2BF0) --------------------------------------------------------
int* sub_4C2BF0()
{
    int* v0; // edx
    int* result; // eax
    int v2; // ecx

    v0 = (int*)& byte_5D4594[1321180];
    do
    {
        result = v0;
        v2 = 2;
        do
        {
            *result = 0;
            result += 2;
            --v2;
        } while (v2);
        ++v0;
    } while ((int)v0 < (int)& byte_5D4594[1321188]);
    return result;
}

//----- (004C2C20) --------------------------------------------------------
int __cdecl sub_4C2C20(_DWORD* a1, int a2, unsigned int a3)
{
    wchar_t* v3; // eax
    int2 a2a; // [esp+0h] [ebp-8h]

    a2a.field_4 = a3 >> 16;
    a2a.field_0 = (unsigned __int16)a3;
    v3 = (wchar_t*)sub_4C2C60(a1, &a2a);
    sub_4776B0(v3);
    return 1;
}

//----- (004C2C60) --------------------------------------------------------
int __cdecl sub_4C2C60(_DWORD* a1, int2* a2)
{
    int v4; // eax
    int result; // eax
    int v6; // [esp+4h] [ebp-Ch]
    int2 a1a; // [esp+8h] [ebp-8h]

    sub_46AA60(a1, &a1, &v6);
    a1a.field_0 = (a2->field_0 - (int)a1) / 38;
    a1a.field_4 = (a2->field_4 - (int)v6) / 38;
    v4 = sub_4C2410(&a1a);
    if (v4)
        result = nox_get_thing_field_4(*(_DWORD*)(v4 + 4));
    else
        result = 0;
    return result;
}

//----- (004C2CE0) --------------------------------------------------------
int sub_4C2CE0()
{
    wchar_t* v0; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // eax

    switch (*(_DWORD*)& byte_587000[184448])
    {
    case 3:
        v3 = loadString_sub_40F1D0((char*)& byte_587000[184980], 0, "C:\\NoxPost\\src\\Client\\Gui\\guisumn.c", 785);
        sub_4776B0(v3);
        break;
    case 4:
        v2 = loadString_sub_40F1D0((char*)& byte_587000[184932], 0, "C:\\NoxPost\\src\\Client\\Gui\\guisumn.c", 782);
        sub_4776B0(v2);
        return 1;
    case 5:
        v0 = loadString_sub_40F1D0((char*)& byte_587000[185028], 0, "C:\\NoxPost\\src\\Client\\Gui\\guisumn.c", 788);
        sub_4776B0(v0);
        return 1;
    }
    return 1;
}

//----- (004C2D60) --------------------------------------------------------
char* sub_4C2D60()
{
    int v0; // eax
    unsigned __int8* v1; // ecx

    v0 = 0;
    v1 = &byte_5D4594[1321060];
    while (!*(_DWORD*)v1)
    {
        v1 += 32;
        ++v0;
        if ((int)v1 >= (int)& byte_5D4594[1321188])
            return 0;
    }
    return (char*)& byte_5D4594[32 * v0 + 1321052];
}

//----- (004C2D90) --------------------------------------------------------
char* __cdecl sub_4C2D90(int a1)
{
    int v1; // eax
    unsigned __int8* v2; // ecx

    v1 = *(_DWORD*)(a1 + 24) + 1;
    if (v1 >= 4)
        return 0;
    v2 = &byte_5D4594[32 * v1 + 1321060];
    while (!*(_DWORD*)v2)
    {
        v2 += 32;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[1321188])
            return 0;
    }
    return (char*)& byte_5D4594[32 * v1 + 1321052];
}

//----- (004C2DD0) --------------------------------------------------------
BOOL __cdecl sub_4C2DD0(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)& byte_5D4594[1321208];
    if (!*(_DWORD*)& byte_5D4594[1321208])
    {
        v1 = sub_4E3AA0((CHAR*)& byte_587000[185040]);
        *(_DWORD*)& byte_5D4594[1321208] = v1;
    }
    return *(_DWORD*)(a1 + 4) != v1;
}

//----- (004C2E00) --------------------------------------------------------
int sub_4C2E00()
{
    char* v0; // esi

    if (!*(_DWORD*)& byte_5D4594[1321208])
        * (_DWORD*)& byte_5D4594[1321208] = sub_4E3AA0((CHAR*)& byte_587000[185060]);
    v0 = sub_4C2D60();
    if (!v0)
        return 0;
    while (!sub_4C2DD0((int)v0))
    {
        v0 = sub_4C2D90((int)v0);
        if (!v0)
            return 0;
    }
    return 1;
}

//----- (004C2E50) --------------------------------------------------------
char __cdecl sub_4C2E50(int a1, int a2, int a3)
{
    char* v3; // eax

    v3 = sub_4C2D60();
    if (v3)
    {
        while (*(_DWORD*)v3 != a1 || *((_DWORD*)v3 + 1) != a2)
        {
            v3 = sub_4C2D90((int)v3);
            if (!v3)
                goto LABEL_5;
        }
    }
    else
    {
    LABEL_5:
        v3 = sub_4C2F20();
        if (v3)
        {
            *(_DWORD*)v3 = a1;
            *((_DWORD*)v3 + 1) = a2;
            v3[20] = sub_4C2EF0(a2);
            sub_4C2F70();
            LOBYTE(v3) = byte_5D4594[1321200];
            if (!byte_5D4594[1321200] || byte_5D4594[1321200] == 3)
            {
                if (!a3)
                    sub_452D80(801, 100);
                byte_5D4594[1321200] = 1;
                nox_window_set_hidden(*(int*)& byte_5D4594[1321032], 0);
                LOBYTE(v3) = nox_window_set_hidden(*(int*)& byte_5D4594[1321040], 0);
            }
            ++* (_DWORD*)& byte_5D4594[1321196];
        }
    }
    return (char)v3;
}

//----- (004C2EF0) --------------------------------------------------------
int __cdecl sub_4C2EF0(int a1)
{
    int v1; // eax
    int v3; // eax

    v1 = *(_DWORD*)(nox_get_thing(a1) + 36);
    if (v1 & 1)
        return 1;
    v3 = -((v1 & 2) != 0);
    LOBYTE(v3) = v3 & 0xFE;
    return v3 + 4;
}

//----- (004C2F20) --------------------------------------------------------
char* sub_4C2F20()
{
    int v0; // esi
    unsigned __int8* v1; // eax
    char* result; // eax

    v0 = 0;
    v1 = &byte_5D4594[1321060];
    while (*(_DWORD*)v1)
    {
        v1 += 32;
        ++v0;
        if ((int)v1 >= (int)& byte_5D4594[1321188])
            return 0;
    }
    memset(&byte_5D4594[32 * v0 + 1321052], 0, 0x20u);
    *(_DWORD*)& byte_5D4594[32 * v0 + 1321060] = 1;
    result = (char*)& byte_5D4594[32 * v0 + 1321052];
    *(_DWORD*)& byte_5D4594[32 * v0 + 1321076] = v0;
    return result;
}

//----- (004C2F70) --------------------------------------------------------
char* sub_4C2F70()
{
    int i; // edi
    char* result; // eax
    char* j; // esi

    sub_4C2BF0();
    for (i = 1; ; i = 4)
    {
        while (1)
        {
            result = sub_4C2D60();
            for (j = result; result; j = result)
            {
                if ((unsigned __int8)j[20] == i)
                    sub_4C2FD0((int)j);
                result = sub_4C2D90((int)j);
            }
            if (i != 1)
                break;
            i = 2;
        }
        if (i != 2)
            break;
    }
    return result;
}

//----- (004C2FD0) --------------------------------------------------------
int __cdecl sub_4C2FD0(int a1)
{
    int v1; // esi
    int* v2; // edi
    int v3; // edx
    int result; // eax

    v1 = 0;
    v2 = (int*)(a1 + 12);
    while (1)
    {
        v3 = *(unsigned __int8*)(a1 + 20);
        *v2 = *(_DWORD*)& byte_587000[8 * v1 + 184456];
        *(_DWORD*)(a1 + 16) = *(_DWORD*)& byte_587000[8 * v1 + 184460];
        if (sub_4C30C0(v2, v3))
            break;
        result = *(unsigned __int8*)(a1 + 20);
        v1 += result;
        if (v1 >= 4)
            return result;
    }
    return sub_4C3030((int*)(a1 + 12), *(unsigned __int8*)(a1 + 20), a1);
}

//----- (004C3030) --------------------------------------------------------
int __cdecl sub_4C3030(int* a1, int a2, int a3)
{
    int v3; // esi
    int result; // eax
    int v5; // ebx
    int v6; // eax
    unsigned __int8* v7; // ecx

    if (a2 == 1)
    {
        v3 = 1;
        a2 = 1;
    }
    else if (a2 == 2)
    {
        v3 = 1;
        a2 = 2;
    }
    else
    {
        v3 = 2;
        if (a2 == 4)
            a2 = 2;
        else
            v3 = a2;
    }
    result = a2;
    v5 = a1[1];
    if (v5 < v5 + a2)
    {
        do
        {
            v6 = *a1;
            if (*a1 < *a1 + v3)
            {
                v7 = &byte_5D4594[4 * (v5 + 2 * v6) + 1321180];
                do
                {
                    *(_DWORD*)v7 = a3;
                    ++v6;
                    v7 += 8;
                } while (v6 < v3 + *a1);
            }
            ++v5;
            result = a1[1] + a2;
        } while (v5 < result);
    }
    return result;
}

//----- (004C30C0) --------------------------------------------------------
int __cdecl sub_4C30C0(int* a1, int a2)
{
    int v2; // ecx
    int v3; // eax
    int v4; // esi
    int v5; // ebx
    int v6; // edi
    int v7; // edx
    int v8; // eax
    unsigned __int8* v9; // ecx

    switch (a2)
    {
    case 1:
        v2 = 1;
        v3 = 1;
        break;
    case 2:
        v2 = 1;
        v3 = 2;
        break;
    case 4:
        v2 = 2;
        v3 = 2;
        break;
    default:
        v2 = a2;
        v3 = a2;
        break;
    }
    v4 = a1[1];
    v5 = v4 + v3;
    if (v4 >= v4 + v3)
        return 1;
    v6 = *a1;
    v7 = *a1 + v2;
    while (1)
    {
        v8 = *a1;
        if (v6 < v7)
            break;
    LABEL_14:
        if (++v4 >= v5)
            return 1;
    }
    v9 = &byte_5D4594[4 * (v4 + 2 * v6) + 1321180];
    while (!*(_DWORD*)v9)
    {
        ++v8;
        v9 += 8;
        if (v8 >= v7)
            goto LABEL_14;
    }
    return 0;
}

//----- (004C3140) --------------------------------------------------------
int* __cdecl sub_4C3140(int a1, void* a2)
{
    int* result; // eax
    int* v3; // esi
    _DWORD* v4; // eax

    result = (int*)sub_4C31D0(a1);
    v3 = result;
    if (result)
    {
        if (result == *(int**)& byte_5D4594[1321204])
            sub_4C2470();
        v4 = sub_45A6F0(a1);
        if (v4)
            v4[30] &= 0xBFFFFFFF;
        sub_4C3030(v3 + 3, *((unsigned __int8*)v3 + 20), 0);
        sub_4C3210((int)v3);
        sub_4C2F70();
        result = (int*)-- * (_DWORD*)& byte_5D4594[1321196];
        if (!*(_DWORD*)& byte_5D4594[1321196])
        {
            result = (int*)a2;
            if (!a2)
                result = sub_452D80(802, 100);
            byte_5D4594[1321200] = 3;
        }
    }
    return result;
}

//----- (004C31D0) --------------------------------------------------------
char* __cdecl sub_4C31D0(int a1)
{
    int v1; // eax
    unsigned __int8* v2; // ecx

    v1 = 0;
    v2 = &byte_5D4594[1321052];
    while (!*((_DWORD*)v2 + 2) || *(_DWORD*)v2 != a1)
    {
        v2 += 32;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[1321180])
            return 0;
    }
    return (char*)& byte_5D4594[32 * v1 + 1321052];
}

//----- (004C3210) --------------------------------------------------------
int __cdecl sub_4C3210(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 8) = 0;
    return result;
}

//----- (004C3220) --------------------------------------------------------
BOOL __cdecl sub_4C3220(int a1)
{
    return sub_4C31D0(*(_DWORD*)(a1 + 128)) != 0;
}

//----- (004C3240) --------------------------------------------------------
BOOL __cdecl sub_4C3240(int a1)
{
    return sub_4C31D0(a1) != 0;
}

//----- (004C3260) --------------------------------------------------------
BOOL sub_4C3260()
{
    return sub_4C2D60() != 0;
}

//----- (004C3270) --------------------------------------------------------
int __cdecl sub_4C3270(int a1, int a2, int a3, int a4)
{
    sub_434460(a4);
    return sub_4B0B90(a1, a2, a3);
}

//----- (004C32A0) --------------------------------------------------------
int __cdecl sub_4C32A0(int a1, int a2, int a3, int a4)
{
    unsigned __int8* v4; // ebx
    int v5; // esi
    int v6; // edi
    int v8; // [esp+10h] [ebp-8h]
    int v9; // [esp+14h] [ebp-4h]

    v8 = (a3 * *(_DWORD*)& byte_587000[192088]) >> 4;
    v9 = (a3 * *(_DWORD*)& byte_587000[192092]) >> 4;
    sub_434460(a4);
    sub_434560(1);
    v4 = &byte_587000[192220];
    do
    {
        v5 = (a3 * *((_DWORD*)v4 - 1)) >> 4;
        v6 = (*(_DWORD*)v4 * a3) >> 4;
        sub_49F500(a1 + v8, a2 + v9);
        sub_49F500(v5 + a1, v6 + a2);
        sub_49E4B0();
        v4 += 128;
        v8 = v5;
        v9 = v6;
    } while ((int)v4 < (int)& byte_587000[194140]);
    sub_49F500(a1 + ((a3 * *(_DWORD*)& byte_587000[192088]) >> 4), a2 + ((a3 * *(_DWORD*)& byte_587000[192092]) >> 4));
    sub_49F500(a1 + v5, a2 + v6);
    sub_49E4B0();
    return sub_434560(0);
}

//----- (004C3390) --------------------------------------------------------
int sub_4C3390()
{
    *(_DWORD*)& byte_5D4594[1321220] = sub_42F970("VoteInProgress");
    *(_DWORD*)& byte_5D4594[1321216] = nox_window_new(
        0,
        136,
        nox_win_width - 50,
        nox_win_height / 2 - 100,
        50,
        50,
        0);
    sub_46AE60(*(int*)& byte_5D4594[1321216], *(int*)& byte_5D4594[1321220]);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1321216], 0, sub_4C3410, 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[1321216], 1);
    return 1;
}

//----- (004C3410) --------------------------------------------------------
int __cdecl sub_4C3410(int* a1)
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

//----- (004C3460) --------------------------------------------------------
int __cdecl sub_4C3460(int a1)
{
    return nox_window_set_hidden(*(int*)& byte_5D4594[1321216], a1);
}

//----- (004C3480) --------------------------------------------------------
BOOL sub_4C3480()
{
    return *(_DWORD*)& byte_5D4594[1321216] && !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1321216]);
}

//----- (004C34A0) --------------------------------------------------------
int sub_4C34A0()
{
    int result; // eax

    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1321216]);
    *(_DWORD*)& byte_5D4594[1321216] = 0;
    return result;
}

//----- (004C34C0) --------------------------------------------------------
void __cdecl sub_4C34C0(int a1)
{
    _DWORD* v1; // eax

    if (*(_DWORD*)& byte_5D4594[1321224])
    {
        if (a1)
        {
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321224], 8901);
            nox_window_call_field_94((int)v1, 16385, a1, 0);
        }
    }
}

//----- (004C3500) --------------------------------------------------------
int sub_4C3500()
{
    _DWORD* v0; // ecx

    v0 = nox_new_window_from_file("yesno.wnd", 0);
    *(_DWORD*)& byte_5D4594[1321224] = v0;
    if (v0)
    {
        sub_46A9B0(v0, (nox_win_width - 320) / 2, (nox_win_height - 240) / 2);
        v0 = *(_DWORD * *)& byte_5D4594[1321224];
    }
    nox_window_set_hidden((int)v0, 1);
    return *(_DWORD*)& byte_5D4594[1321224];
}

//----- (004C3560) --------------------------------------------------------
int sub_4C3560()
{
    sub_46A8C0(*(int*)& byte_5D4594[1321224]);
    return *(_DWORD*)& byte_5D4594[1321224];
}

//----- (004C3580) --------------------------------------------------------
int sub_4C3580()
{
    return nox_window_set_hidden(*(int*)& byte_5D4594[1321224], 1);
}

//----- (004C35B0) --------------------------------------------------------
int __cdecl sub_4C35B0(int a1)
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1321228]))
        return 0;
    sub_413A00(0);
    if (a1)
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1321228], 1);
    }
    else
    {
        sub_4C3620();
        sub_433290((char*)& byte_587000[185108]);
        nox_window_set_hidden(*(int*)& byte_5D4594[1321228], 1);
        sub_472280();
        sub_4ADA40();
    }
    return 1;
}

//----- (004C3620) --------------------------------------------------------
char* sub_4C3620()
{
    int v0; // ebp
    int i; // esi
    wchar_t* v2; // eax
    int v3; // edi
    wchar_t* v4; // eax
    char* v5; // ebx
    wchar_t* v6; // eax
    char* v7; // eax
    wchar_t* v8; // eax
    int v9; // esi
    wchar_t* v10; // eax
    char* result; // eax
    char v12[256]; // [esp+8h] [ebp-100h]

    v0 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321240] + 32);
    sub_42CD90();
    for (i = 0; i < *(__int16*)(v0 + 44); ++i)
    {
        v2 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16406, i, 0);
        v3 = sub_42EA40(v2);
        v4 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16406, i, 0);
        v5 = sub_42E960(v4);
        v6 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16406, i, 0);
        v7 = sub_42E960(v6);
        if (v7)
        {
            nox_sprintf(v12, "%s = %s", v7, v3);
            sub_42CF50(v12);
        }
        if (v5)
        {
            nox_sprintf(v12, "%s = %s", v5, v3);
            sub_42CF50(v12);
        }
    }
    v8 = loadString_sub_40F1D0((char*)& byte_587000[185172], 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 191);
    v9 = sub_42EA40(v8);
    v10 = loadString_sub_40F1D0((char*)& byte_587000[185240], 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 192);
    result = sub_42E960(v10);
    if (result)
    {
        nox_sprintf(v12, "%s = %s", result, v9);
        result = (char*)sub_42CF50(v12);
    }
    return result;
}

//----- (004C3760) --------------------------------------------------------
int sub_4C3760()
{
    int result; // eax
    _DWORD** v1; // eax
    _DWORD* v2; // esi
    _DWORD* v3; // esi
    int v4; // esi
    int v5; // edi
    _DWORD* v6; // eax
    int v7; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // esi
    wchar_t* v11; // eax

    result = nox_new_window_from_file("InputCfg.wnd", sub_4C3A90);
    *(_DWORD*)& byte_5D4594[1321228] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1321236] = sub_46B0C0((_DWORD*)result, 910);
        *(_DWORD*)& byte_5D4594[1321240] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 911);
        *(_DWORD*)& byte_5D4594[1321244] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 912);
        *(_DWORD*)& byte_5D4594[1321248] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 913);
        result = *(_DWORD*)& byte_5D4594[1321236];
        if (*(_DWORD*)& byte_5D4594[1321236])
        {
            v1 = *(_DWORD * **)(*(_DWORD*)& byte_5D4594[1321236] + 32);
            *v1[7] = 921;
            *v1[8] = 922;
            *v1[9] = 920;
            sub_46B2C0(*(int*)& byte_5D4594[1321236], sub_4C3CD0);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1321240], *(int*)& byte_5D4594[1321236]);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1321244], *(int*)& byte_5D4594[1321236]);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1321248], *(int*)& byte_5D4594[1321236]);
            sub_46B300(*(int*)& byte_5D4594[1321244], sub_4C3A60);
            sub_46B300(*(int*)& byte_5D4594[1321248], sub_4C3A60);
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 921);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16408, (int)v2, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16408, (int)v2, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16408, (int)v2, 0);
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 922);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16409, (int)v3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16409, (int)v3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16409, (int)v3, 0);
            v4 = 971;
            v5 = sub_47DBC0() + 971;
            if (v5 > 971)
            {
                do
                {
                    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], v4);
                    sub_46ABB0((int)v6, 1);
                    ++v4;
                } while (v4 < v5);
            }
            v7 = sub_430AF0();
            v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], v7 + 971);
            nox_window_call_field_94((int)v8, 16392, 1, 0);
            sub_46A9B0(
                *(_DWORD * *)& byte_5D4594[1321228],
                (nox_win_width - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321228] + 8)) / 2,
                0);
            *(_DWORD*)& byte_5D4594[1321232] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 980);
            sub_46B120(*(_DWORD * *)& byte_5D4594[1321232], 0);
            sub_46B2C0(*(int*)& byte_5D4594[1321232], sub_4C3A90);
            sub_46B300(*(int*)& byte_5D4594[1321232], sub_4C3EB0);
            nox_window_set_hidden(*(int*)& byte_5D4594[1321232], 1);
            sub_46A9B0(
                *(_DWORD * *)& byte_5D4594[1321232],
                (nox_win_width - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321232] + 8)) / 2,
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321232] + 20));
            v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321232], 981);
            sub_46AEE0((int)v9, (int)& byte_5D4594[1321256]);
            v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 932);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[185316], 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 603);
            sub_46AEE0((int)v10, (int)v11);
            sub_46ABB0((int)v10, 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1321228], 1);
            result = 1;
        }
    }
    return result;
}

//----- (004C3A60) --------------------------------------------------------
int __cdecl sub_4C3A60(_DWORD* a1, unsigned int a2, unsigned int a3, int a4)
{
    int result; // eax

    if (a2 < 0x13 || a2 > 0x14)
        result = sub_4A28E0(a1, a2, a3, a4);
    else
        result = 0;
    return result;
}

//----- (004C3A90) --------------------------------------------------------
int __cdecl sub_4C3A90(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int result; // eax

    if (a2 == 23)
        return 1;
    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(921, 100);
    switch (v3)
    {
    case 931:
        sub_42CD90();
        sub_4317B0((char*)& byte_587000[185332], 1);
        sub_4C3B70();
        result = 0;
        break;
    case 932:
        sub_4C35B0(0);
        result = 0;
        break;
    case 933:
        sub_4C3CB0();
        result = 0;
        break;
    case 971:
    case 972:
    case 973:
        sub_430AA0(v3 - 971);
        return 0;
    default:
        return 0;
    }
    return result;
}

//----- (004C3B70) --------------------------------------------------------
char* sub_4C3B70()
{
    char* result; // eax
    int* v1; // esi
    char* v2; // edi
    char* v3; // ebx

    nox_window_call_field_94(*(int*)& byte_5D4594[1321236], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16399, 0, 0);
    result = *(char**)& byte_587000[75892];
    if (*(_DWORD*)& byte_587000[75892])
    {
        v1 = (int*)& byte_587000[75896];
        do
        {
            if (*v1 != 44)
            {
                nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16397, v1[1], -1);
                nox_window_call_field_94(*(int*)& byte_5D4594[1321236], 16397, (int)& byte_587000[185340], -1);
                v2 = sub_42E8E0(*v1, 1);
                v3 = sub_42E8E0(*v1, 2);
                if (v2 && *(_WORD*)v2)
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16397, (int)v2, -1);
                else
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16397, (int)& byte_587000[185344], -1);
                if (v3 && *(_WORD*)v3 && v2 != v3)
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16397, (int)v3, -1);
                else
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16397, (int)& byte_587000[185348], -1);
            }
            result = (char*)v1[2];
            v1 += 3;
        } while (result);
    }
    return result;
}

//----- (004C3CB0) --------------------------------------------------------
char* sub_4C3CB0()
{
    sub_42CD90();
    sub_4317B0((char*)& byte_587000[185352], 1);
    return sub_4C3B70();
}

//----- (004C3CD0) --------------------------------------------------------
int __cdecl sub_4C3CD0(int a1, unsigned int a2, int a3, int a4)
{
    int v5; // eax
    wchar_t* v6; // eax
    int v7; // esi
    int v8; // esi
    int v9; // [esp-4h] [ebp-10h]

    if (a2 > 0x4007)
    {
        if (a2 == 16393)
        {
            v7 = *(_DWORD*)(a1 + 32);
            sub_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
            v8 = sub_4A4800(v7);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16412, v8, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16412, v8, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16412, v8, 0);
        }
        else if (a2 == 16400)
        {
            v5 = *(_DWORD*)(a3 + 32);
            if ((int) * (_DWORD*)(v5 + 48) >= 0)
            {
                *(_DWORD*)& byte_5D4594[1321252] = a3;
                v9 = nox_window_call_field_94(*(int*)& byte_5D4594[1321240], 16406, *(_DWORD*)(v5 + 48), 0);
                v6 = loadString_sub_40F1D0((char*)& byte_587000[185404], 0, "C:\\NoxPost\\src\\client\\Gui\\GuiInput.c", 436);
                nox_swprintf((wchar_t*)& byte_5D4594[1321256], L"%s\n'%s'", v6, v9);
                sub_46A8C0(*(int*)& byte_5D4594[1321232]);
                sub_46B500(*(int*)& byte_5D4594[1321232]);
                sub_46C690(*(int*)& byte_5D4594[1321232]);
                return sub_4A30D0(a1, 0x4010u, (wchar_t*)a3, a4);
            }
        }
    }
    else
    {
        if (a2 != 16391)
        {
            if (a2 == 23)
                return 1;
            if (a2 != 0x4000)
                return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
        }
        if ((_DWORD*)a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 921)
            || (_DWORD*)a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1321228], 922))
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1321240], a2, a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321244], a2, a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1321248], a2, a3, 0);
            return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
        }
    }
    return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
}

//----- (004C3EB0) --------------------------------------------------------
int __cdecl sub_4C3EB0(int a1, int a2, char* a3, int a4)
{
    int result; // eax

    switch (a2)
    {
    case 6:
    case 7:
        goto LABEL_10;
    case 10:
    case 11:
        sub_4C4100((char*)0x10002);
        goto LABEL_15;
    case 14:
    case 15:
        sub_4C4100((char*)0x10001);
        goto LABEL_15;
    case 19:
        sub_4C4100((char*)0x10003);
        goto LABEL_15;
    case 20:
        sub_4C4100((char*)0x10004);
        goto LABEL_15;
    case 21:
        if (a3 == (char*)1)
        {
            if (a4 == 2)
            {
                sub_46B500(0);
                sub_46C6E0(*(int*)& byte_5D4594[1321232]);
                nox_window_set_hidden(*(int*)& byte_5D4594[1321232], 1);
                if (*(_DWORD*)& byte_5D4594[1321252])
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321252], 16403, -1, 0);
            }
            result = 1;
        }
        else if (a4 == 1 && sub_4C3FC0(a3))
        {
        LABEL_10:
            sub_4C4100((char*)0x10000);
        LABEL_15:
            sub_46B500(0);
            sub_46C6E0(*(int*)& byte_5D4594[1321232]);
            nox_window_set_hidden(*(int*)& byte_5D4594[1321232], 1);
            result = 1;
        }
        else
        {
        LABEL_5:
            result = 0;
        }
        return result;
    default:
        goto LABEL_5;
    }
}

//----- (004C3FC0) --------------------------------------------------------
int __cdecl sub_4C3FC0(char* a1)
{
    int v1; // ecx
    unsigned __int8* v2; // eax
    int v3; // esi
    int v4; // ecx
    const wchar_t* v6; // edi
    int v7; // esi
    int v8; // ebx
    const wchar_t* v9; // eax
    int v10; // esi
    int v11; // ebx
    const wchar_t* v12; // eax

    v1 = 0;
    if (*(_DWORD*)& byte_587000[73672])
    {
        v2 = &byte_587000[73672];
        do
        {
            if (*((char**)v2 + 1) == a1)
                break;
            v3 = *((_DWORD*)v2 + 4);
            v2 += 16;
            ++v1;
        } while (v3);
    }
    v4 = 16 * v1;
    if (!*(_DWORD*)& byte_587000[v4 + 73672])
        return 0;
    v6 = *(const wchar_t**)& byte_587000[v4 + 73684];
    if (*(_DWORD*)& byte_5D4594[1321252])
    {
        v7 = 0;
        v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321244] + 32);
        if (*(_WORD*)(v8 + 44) > 0)
        {
            do
            {
                v9 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16406, v7, 0);
                if (!nox_wcscmp(v9, v6))
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16407, (int)& byte_587000[185444], v7);
                ++v7;
            } while (v7 < *(__int16*)(v8 + 44));
        }
        v10 = 0;
        v11 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321248] + 32);
        if (*(_WORD*)(v11 + 44) > 0)
        {
            do
            {
                v12 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16406, v10, 0);
                if (!nox_wcscmp(v12, v6))
                    nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16407, (int)& byte_587000[185448], v10);
                ++v10;
            } while (v10 < *(__int16*)(v11 + 44));
        }
        nox_window_call_field_94(
            *(int*)& byte_5D4594[1321252],
            16407,
            (int)v6,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1321252] + 32) + 48));
        nox_window_call_field_94(*(int*)& byte_5D4594[1321252], 16403, -1, 0);
        *(_DWORD*)& byte_5D4594[1321252] = 0;
    }
    return 1;
}

//----- (004C4100) --------------------------------------------------------
int __cdecl sub_4C4100(char* a1)
{
    char* v1; // edi
    int v2; // esi
    int v3; // ebx
    const wchar_t* v4; // eax
    int v5; // esi
    int v6; // ebx
    const wchar_t* v7; // eax

    v1 = sub_42EA00(a1);
    if (!*(_DWORD*)& byte_5D4594[1321252])
        return 1;
    v2 = 0;
    v3 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321244] + 32);
    if (*(_WORD*)(v3 + 44) > 0)
    {
        do
        {
            v4 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16406, v2, 0);
            if (!nox_wcscmp(v4, (const wchar_t*)v1))
                nox_window_call_field_94(*(int*)& byte_5D4594[1321244], 16407, (int)& byte_587000[185452], v2);
            ++v2;
        } while (v2 < *(__int16*)(v3 + 44));
    }
    v5 = 0;
    v6 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1321248] + 32);
    if (*(_WORD*)(v6 + 44) > 0)
    {
        do
        {
            v7 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16406, v5, 0);
            if (!nox_wcscmp(v7, (const wchar_t*)v1))
                nox_window_call_field_94(*(int*)& byte_5D4594[1321248], 16407, (int)& byte_587000[185456], v5);
            ++v5;
        } while (v5 < *(__int16*)(v6 + 44));
    }
    nox_window_call_field_94(
        *(int*)& byte_5D4594[1321252],
        16407,
        (int)v1,
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1321252] + 32) + 48));
    nox_window_call_field_94(*(int*)& byte_5D4594[1321252], 16403, -1, 0);
    *(_DWORD*)& byte_5D4594[1321252] = 0;
    return 1;
}

//----- (004C4220) --------------------------------------------------------
int sub_4C4220()
{
    int result; // eax

    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1321228]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1321232]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1321228] = 0;
    *(_DWORD*)& byte_5D4594[1321232] = 0;
    *(_DWORD*)& byte_5D4594[1321236] = 0;
    *(_DWORD*)& byte_5D4594[1321240] = 0;
    *(_DWORD*)& byte_5D4594[1321244] = 0;
    *(_DWORD*)& byte_5D4594[1321248] = 0;
    return result;
}

//----- (004C4260) --------------------------------------------------------
int sub_4C4260()
{
    sub_4C3B70();
    sub_46A8C0(*(int*)& byte_5D4594[1321228]);
    return sub_413A00(1);
}

//----- (004C4280) --------------------------------------------------------
BOOL sub_4C4280()
{
    return wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1321228]) == 0;
}

//----- (004C42A0) --------------------------------------------------------
int __cdecl sub_4C42A0(int2* a1, int2* a2, int* a3, int* a4)
{
    int v4; // ecx
    int v5; // eax
    int result; // eax
    double v7; // st7
    double v8; // st7
    int v9; // esi
    int v10; // edx
    int* v11; // ecx
    int v12; // ebx
    int v13; // edi
    double v14; // st7
    int v15; // esi
    int v16; // edi
    double v17; // st7
    int v18; // ebp
    int v19; // eax
    int v20; // eax
    int v21; // eax
    double v22; // st7
    int v23; // edi
    int v24; // edx
    int v25; // ebx
    unsigned __int8* v26; // ecx
    int v27; // eax
    int v28; // esi
    int v29; // ebp
    bool v30; // zf
    bool v31; // cc
    unsigned __int8* v32; // edi
    int v33; // ecx
    unsigned __int8* v34; // edx
    int v35; // eax
    int v36; // eax
    unsigned __int8* v37; // ebx
    unsigned __int8* v38; // esi
    int v39; // ecx
    unsigned __int8* v40; // edx
    int v41; // eax
    float v42; // [esp+0h] [ebp-24h]
    float v43; // [esp+14h] [ebp-10h]
    float v44; // [esp+14h] [ebp-10h]
    unsigned __int8* v45; // [esp+14h] [ebp-10h]
    int v46; // [esp+18h] [ebp-Ch]
    int v47; // [esp+1Ch] [ebp-8h]
    int v48; // [esp+1Ch] [ebp-8h]
    float v49; // [esp+1Ch] [ebp-8h]
    int v50; // [esp+20h] [ebp-4h]
    float v51; // [esp+28h] [ebp+4h]
    float v52; // [esp+28h] [ebp+4h]
    float v53; // [esp+28h] [ebp+4h]
    int2* v54; // [esp+2Ch] [ebp+8h]
    int2* v55; // [esp+2Ch] [ebp+8h]
    int2* v56; // [esp+2Ch] [ebp+8h]
    int2* v57; // [esp+2Ch] [ebp+8h]
    int2* v58; // [esp+2Ch] [ebp+8h]
    int2* v59; // [esp+2Ch] [ebp+8h]
    int2* v60; // [esp+2Ch] [ebp+8h]

    v4 = a1->field_4;
    v5 = a2->field_4;
    if (v4 == v5)
    {
        if (!*(_DWORD*)& byte_5D4594[4 * v4 + 3679340])
            return 0;
        v47 = a1->field_0;
        v54 = (int2*)a2->field_0;
        if (a1->field_0 > (int)v54)
        {
            v51 = (double)(int)v54;
            v7 = (double)v47;
        }
        else
        {
            v51 = (double)v47;
            v7 = (double)(int)v54;
        }
        v43 = v7;
        if (v4 < 0)
            return 0;
        if (v4 >= nox_win_height)
            v4 = nox_win_height - 1;
        if (v51 < 0.0)
            v51 = 0.0;
        v8 = (double) nox_win_width;
        if (v51 > v8)
            v51 = v8;
        v9 = *(_DWORD*)& byte_5D4594[4 * v4 + 3679340];
        v10 = 0;
        if (v9 <= 0)
        {
        LABEL_22:
            *a4 = 0;
            result = 1;
        }
        else
        {
            v11 = (int*)& byte_5D4594[128 * v4 + 3682960];
            while (1)
            {
                v12 = *(v11 - 1);
                v13 = *v11;
                v55 = (int2*)* v11;
                if ((double) * (v11 - 1) > v51)
                {
                    if (*a3 < v12)
                        * a3 = v12;
                    if ((double)(int)v55 < v43 && *a4 > v13)
                    {
                        *a4 = v13;
                        return 1;
                    }
                    return 1;
                }
                v14 = (double)(int)v55;
                if (v51 <= v14 && v43 > v14)
                    break;
                if (v43 <= v14)
                    return 1;
                v10 += 2;
                v11 += 2;
                if (v10 >= v9)
                    goto LABEL_22;
            }
            if (*a4 <= v13)
                return 1;
            *a4 = v13;
            result = 1;
        }
        return result;
    }
    v48 = a1->field_0;
    v56 = (int2*)a2->field_0;
    if (a1->field_0 > (int)v56)
    {
        v15 = v5;
        v16 = a1->field_4;
        v50 = v5;
        v52 = (double)(int)v56;
        v17 = (double)v48;
    }
    else
    {
        v15 = a1->field_4;
        v16 = v5;
        v50 = a1->field_4;
        v52 = (double)v48;
        v17 = (double)(int)v56;
    }
    v44 = v17;
    v18 = v16 - v15;
    v57 = (int2*)(v16 - v15);
    if (v16 - v15 >= 0)
    {
        v46 = 1;
    }
    else
    {
        v18 = v15 - v16;
        v57 = (int2*)(v15 - v16);
        v46 = -1;
    }
    v49 = (v44 - v52) / (double)(int)v57;
    if (v15 >= 0)
    {
        v19 = nox_win_height;
        if (v15 < nox_win_height)
            goto LABEL_44;
        if (v16 >= nox_win_height)
            return 0;
        v58 = (int2*)(v15 - nox_win_height + 1);
        v15 = nox_win_height - 1;
        v52 = (double)(int)v58 * v49 + v52;
        v20 = sub_419A70(v52);
        if (*a3 < v20)
            * a3 = v20;
    }
    else
    {
        v15 = 0;
        v52 = v52 - (double)v50 * v49;
    }
    v19 = nox_win_height;
LABEL_44:
    if (v16 >= 0)
    {
        if (v16 >= v19)
        {
            v59 = (int2*)(v19 - v16 + v18 - 1);
            v44 = (double)(int)v59 * v49 + v52;
            v21 = sub_419A70(v44);
            if (*a4 > v21)
                * a4 = v21;
            v18 = (int)v59;
        }
    }
    else
    {
        v18 += v16;
    }
    if (v52 < 0.0)
    {
        v52 = 0.0;
        v15 -= sub_419A70(0.0);
    }
    v22 = (double) nox_win_width;
    if (v44 > v22)
    {
        v42 = v44 - v22;
        v18 -= sub_419A70(v42);
    }
    v23 = *(_DWORD*)& byte_5D4594[4 * v15 + 3679340];
    v24 = 0;
    v25 = 1;
    if (v23 > 0)
    {
        v26 = &byte_5D4594[128 * v15 + 3682960];
        while ((double) * ((int*)v26 - 1) > v52 || (double)(int)(*(_DWORD*)v26 + 2) < v52)
        {
            v24 += 2;
            v26 += 8;
            if (v24 >= v23)
                goto LABEL_61;
        }
        v25 = 0;
    }
LABEL_61:
    v27 = v46;
    v28 = v46 + v15;
    v29 = v18 - 1;
    v60 = (int2*)v29;
    v53 = v49 + v52;
    if (v25)
    {
        v30 = v29 == 0;
        v31 = v29 <= 0;
        if (v29 <= 0)
        {
        LABEL_71:
            if (v30)
                return 0;
            goto LABEL_77;
        }
        v45 = &byte_5D4594[4 * v28 + 3679340];
        v32 = &byte_5D4594[128 * v28 + 3682960];
        while (1)
        {
            v33 = 0;
            if (*(_DWORD*)v45 > 0)
                break;
        LABEL_69:
            v28 += v46;
            v35 = (int)& v60[-1].field_4 + 3;
            v32 += 128 * v46;
            v53 = v49 + v53;
            v60 = (int2*)v35;
            v45 += 4 * v46;
            if (v35 <= 0)
            {
                v29 = v35;
                v27 = v46;
                v30 = v29 == 0;
                v31 = v29 <= 0;
                goto LABEL_71;
            }
        }
        v34 = v32;
        while ((double) * ((int*)v34 - 1) > v53 || (double)(int)(*(_DWORD*)v34 + 2) < v53)
        {
            v33 += 2;
            v34 += 8;
            if (v33 >= *(int*)v45)
                goto LABEL_69;
        }
        v36 = sub_419A70(v53) - 1;
        if (*a3 < v36)
            * a3 = v36;
        v29 = (int)v60;
        v27 = v46;
    }
    v31 = v29 <= 0;
LABEL_77:
    if (!v31)
    {
        v37 = &byte_5D4594[4 * v28 + 3679340];
        v38 = &byte_5D4594[128 * v28 + 3682960];
        while (1)
        {
            v39 = 0;
            if (*(int*)v37 <= 0)
                break;
            v40 = v38;
            while ((double) * ((int*)v40 - 1) > v53 || (double)(int)(*(_DWORD*)v40 + 2) < v53)
            {
                v39 += 2;
                v40 += 8;
                if (v39 >= *(int*)v37)
                    goto LABEL_87;
            }
            --v29;
            v38 += 128 * v27;
            v37 += 4 * v27;
            v53 = v49 + v53;
            if (v29 <= 0)
                return 1;
        }
    LABEL_87:
        v41 = sub_419A70(v53);
        if (*a4 > v41)
            * a4 = v41;
    }
    return 1;
}

//----- (004C4770) --------------------------------------------------------
__int16 __cdecl sub_4C4770(int* a1, unsigned __int8* a2, int a3)
{
    unsigned __int8* v3; // esi
    char* v4; // eax
    _DWORD* v5; // edi
    _DWORD* v6; // eax
    int v7; // ecx
    int v8; // edi
    int v9; // ecx
    int v10; // ebp
    int v11; // edx
    int v12; // eax
    int v13; // ebx
    int v14; // edx
    int v15; // ebx
    int v16; // edi
    int v17; // ebx
    unsigned __int8 v18; // al
    unsigned __int8 v19; // cl
    int v20; // ecx
    int v21; // edx
    int v22; // ecx
    int v23; // edi
    int v24; // ebx
    int v25; // ebx
    int v26; // edi
    int v27; // ecx
    unsigned __int8* v28; // edi
    __int16 v29; // ax
    int v30; // ebp
    int v31; // edx
    int v32; // eax
    int v33; // eax
    int v34; // edx
    int v35; // ecx
    double v36; // st7
    double v37; // st7
    unsigned __int8 v38; // bl
    unsigned __int8 v39; // al
    int v40; // edx
    int v41; // ecx
    int v42; // edi
    int v43; // ebx
    int v44; // eax
    int v45; // eax
    int v46; // eax
    int v47; // ebp
    int v48; // eax
    int v49; // eax
    int v50; // eax
    int v51; // ebx
    int v53; // [esp+18h] [ebp-30h]
    int v54; // [esp+1Ch] [ebp-2Ch]
    int2 a1a; // [esp+20h] [ebp-28h]
    int2 a2a; // [esp+28h] [ebp-20h]
    int a4; // [esp+30h] [ebp-18h]
    int a3a; // [esp+34h] [ebp-14h]
    __int64 v59; // [esp+38h] [ebp-10h]
    __int64 v60; // [esp+40h] [ebp-8h]
    unsigned __int8 v61; // [esp+4Ch] [ebp+4h]
    unsigned __int8 v62; // [esp+4Ch] [ebp+4h]
    unsigned __int8 v63; // [esp+50h] [ebp+8h]
    unsigned __int8 v64; // [esp+50h] [ebp+8h]

    v53 = 0;
    v54 = 0;
    if (!*(_DWORD*)& byte_5D4594[1321520])
        * (_DWORD*)& byte_5D4594[1321520] = sub_44CFC0((CHAR*)& byte_587000[185484]);
    v3 = a2;
    if (a2[112] & 4)
    {
        v4 = sub_417040(*((_DWORD*)a2 + 32));
        if (*(_DWORD*)& byte_5D4594[2616328] == *((_DWORD*)a2 + 32))
        {
            if (v4 && v4[3680] & 1)
                v54 = 1;
        }
        else if (v4 && v4[3680] & 1)
        {
            return (__int16)v4;
        }
        v5 = sub_418C80(*(int*)& byte_5D4594[2616328]);
        if (v5)
        {
            v6 = sub_418C80(*((_DWORD*)a2 + 32));
            if (v6)
            {
                if (*(_DWORD*)& byte_5D4594[2616328] == *((_DWORD*)a2 + 32) || sub_419150((int)v5, (int)v6))
                    v53 = 1;
            }
        }
    }
    v7 = *((_DWORD*)a2 + 3);
    a3a = 0;
    v8 = *a1;
    v9 = v7 - a1[4];
    v10 = a1[1];
    v11 = *((__int16*)a2 + 53);
    LODWORD(v59) = v9 + *a1 - *a2;
    v12 = *((_DWORD*)a2 + 4);
    v13 = *((_DWORD*)a2 + 4) - v11 - a2[1] - *((__int16*)a2 + 52);
    v14 = a1[5];
    HIDWORD(v59) = v10 + v13 - v14;
    a4 = nox_win_width;
    if (*(_DWORD*)& byte_587000[80808])
    {
        v15 = *((_DWORD*)a2 + 30);
        if (!(v15 & 0x40000000) && !(v15 & 1) && (a2[112] & 0x80u) != 0)
        {
            v16 = v9 + v8;
            a1a.field_0 = v16;
            v17 = v10 + v12 - v14;
            v18 = a2[299];
            v19 = a2[299];
            a1a.field_4 = v17;
            v20 = 8 * v19;
            v21 = v16 + *(int*)& byte_587000[v20 + 196184];
            v22 = v17 + *(int*)& byte_587000[v20 + 196188];
            a2a.field_0 = v21;
            a2a.field_4 = v22;
            if (v18 < 0x18u && v18 && (v18 < 8u || v18 > 0x10u))
            {
                v23 = (v21 + v16) >> 1;
                v24 = (v22 + v17) >> 1;
                if (sub_4C5630(v23 - 5, v23 - 5, v24))
                {
                    a1a.field_0 -= 2;
                    a2a.field_0 -= 2;
                }
                else if (sub_4C5630(v23 + 5, v23 + 5, v24))
                {
                    a1a.field_0 += 2;
                    a2a.field_0 += 2;
                }
            }
            else
            {
                v25 = (v22 + v17) >> 1;
                v26 = (v21 + v16) >> 1;
                if (sub_4C5630(v26, v26, v25 - 5))
                {
                    v27 = a2a.field_4 - 2;
                    a1a.field_4 -= 2;
                }
                else
                {
                    if (!sub_4C5630(v26, v26, v25 + 5))
                        goto LABEL_32;
                    v27 = a2a.field_4 + 2;
                    a1a.field_4 += 2;
                }
                a2a.field_4 = v27;
            }
        LABEL_32:
            v4 = (char*)sub_4C42A0(&a1a, &a2a, &a3a, &a4);
            if (!v4)
                return (__int16)v4;
            goto LABEL_33;
        }
    }
LABEL_33:
    if (*((_DWORD*)a2 + 28) & 0x80000 && *((_DWORD*)a2 + 30) & 0x1000000 || *((_DWORD*)a2 + 30) & 0x40000000)
        v28 = &byte_587000[185472];
    else
        v28 = (unsigned __int8*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])((int2*)(a2 + 12));
    v29 = *((_WORD*)a2 + 52);
    a2a.field_0 = 0;
    if (v29 >= 0)
    {
        v30 = 0;
    }
    else
    {
        if (*(int*)& byte_5D4594[1321512] < 0 && a2 == *(unsigned __int8**)& byte_5D4594[1321516])
            a2a.field_0 = 1;
        v30 = -v29;
    }
    *(_DWORD*)& byte_5D4594[1321516] = a2;
    v31 = *((__int16*)a2 + 52);
    a1a.field_0 = v30;
    *(_DWORD*)& byte_5D4594[1321512] = v31;
    if (sub_4356C0((int)a2, 25))
    {
        sub_434600(1);
        sub_433E40(*(int*)& byte_5D4594[2650684]);
    }
    else if (a2[112] & 2 && (v32 = *((_DWORD*)a2 + 30), v32 & 0x40000000) && !(v32 & 0x8020))
    {
        sub_434600(1);
        sub_433E40(*(int*)& byte_5D4594[2650684]);
    }
    else
    {
        v33 = sub_4345F0(1);
        LOBYTE(v34) = v28[8];
        LOBYTE(v33) = v28[4];
        LOBYTE(v35) = *v28;
        sub_433CD0(v35, v33, v34);
    }
    if (*((_DWORD*)a2 + 120))
    {
        v60 = (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *((_DWORD*)a2 + 85));
        v36 = (double)v60;
        v60 = *(unsigned int*)& byte_5D4594[2649704];
        v37 = 1.0 - v36 / (double) * (int*)& byte_5D4594[2649704];
        if (v37 < 0.0)
            v37 = 0.001;
        v38 = (__int64)(v37 * 255.0);
        v63 = (__int64)(v37 * 255.0);
        if (*((_DWORD*)v3 + 27) == *(_DWORD*)& byte_5D4594[1321520])
        {
            v39 = sub_4C4EC0(a1, (int)v3);
            if (v39 < v38)
            {
                v64 = v39;
                sub_434560(1);
                sub_434580(v64);
                goto LABEL_64;
            }
        }
        else if (*((_DWORD*)v3 + 30) & 0x4000000)
        {
            v63 = v38 >> 1;
        }
        sub_434560(1);
        sub_434580(v63);
        goto LABEL_64;
    }
    if (*((_DWORD*)a2 + 27) == *(_DWORD*)& byte_5D4594[1321520])
    {
        v61 = sub_4C4EC0(a1, (int)a2);
        sub_434560(1);
        sub_434580(v61);
    }
    else if (*((_DWORD*)a2 + 30) & 0x4000000)
    {
        sub_434560(1);
        sub_434580(0x80u);
    }
LABEL_64:
    if (!sub_4356C0((int)v3, 0)
        && !v54
        && (*((_DWORD*)v3 + 27) != *(_DWORD*)& byte_5D4594[1321520]
            || !*(_DWORD*)& byte_5D4594[2614252]
            || !sub_4356C0(*(int*)& byte_5D4594[2614252], 21)))
    {
        goto LABEL_105;
    }
    if (*(_DWORD*)& byte_5D4594[2618908] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 1)
    {
        sub_434560(1);
        sub_434580(0x80u);
        goto LABEL_105;
    }
    v40 = *((_DWORD*)v3 + 8);
    v41 = *((_DWORD*)v3 + 9);
    v42 = *((_DWORD*)v3 + 3) - v40;
    v43 = *((_DWORD*)v3 + 4) - v41;
    v44 = *((_DWORD*)v3 + 3) - v40;
    if (v42 < 0)
        v44 = v40 - *((_DWORD*)v3 + 3);
    if (v44 < 4)
    {
        v45 = *((_DWORD*)v3 + 4) - v41;
        if (v43 < 0)
            v45 = v41 - *((_DWORD*)v3 + 4);
        if (v45 < 4)
        {
            v46 = *(_DWORD*)& byte_5D4594[2614252];
            if (!*(_DWORD*)& byte_5D4594[2614252])
                goto LABEL_82;
            if (!sub_4356C0(*(int*)& byte_5D4594[2614252], 21))
            {
                LOWORD(v4) = v53;
                if (!v53)
                    return (__int16)v4;
            }
        }
    }
    v46 = *(_DWORD*)& byte_5D4594[2614252];
LABEL_82:
    if (v42 || v43)
    {
        v47 = *((_DWORD*)v3 + 5) - *((_DWORD*)v3 + 10);
        if (!v47)
            v47 = 1;
        v48 = sub_419B10(sqrt((double)(v42 * v42 + v43 * v43))) / v47;
        v30 = a1a.field_0;
        v42 = v48;
        v46 = *(_DWORD*)& byte_5D4594[2614252];
    }
    if (!v46)
        goto LABEL_123;
    if (v54)
        goto LABEL_95;
    if (v53 || !sub_4356C0(v46, 21))
    {
    LABEL_123:
        if (v42 < 8)
        {
            v49 = (v42 << 7) / 8;
            v62 = v49;
            if ((_BYTE)v49)
                goto LABEL_97;
            LOBYTE(v49) = 1;
        LABEL_96:
            v62 = v49;
        LABEL_97:
            if (v53 && (unsigned __int8)v49 <= 1u)
            {
                if ((v50 = *((_DWORD*)v3 + 28), v50 & 2) && *((_DWORD*)v3 + 69) == 8 || v50 & 4 && !*((_DWORD*)v3 + 69))
                {
                    sub_434600(1);
                    sub_433E40(*(int*)& byte_5D4594[2618904]);
                    v62 = -128;
                }
            }
            goto LABEL_104;
        }
    LABEL_95:
        LOBYTE(v49) = -128;
        goto LABEL_96;
    }
    sub_434600(1);
    sub_433E40(*(int*)& byte_5D4594[2618904]);
    v62 = nox_backbuffer_depth >= 16 ? -1 : -128;
LABEL_104:
    sub_434560(1);
    sub_434580(v62);
LABEL_105:
    if (!(v3[112] & 4) && sub_4356C0((int)v3, 23) && !sub_40A5C0(2048))
    {
        sub_434600(1);
        if (byte_5D4594[2598000] & 1)
            sub_433E40(*(int*)& byte_5D4594[2523948]);
        else
            sub_433E40(*(int*)& byte_5D4594[2650684]);
    }
    if (!sub_4356C0((int)v3, 23) && sub_4356C0((int)v3, 11))
    {
        sub_434600(1);
        sub_433E40(*(int*)& byte_5D4594[2650660]);
    }
    v51 = a2a.field_0;
    if (a2a.field_0)
    {
        sub_49F7F0();
        sub_49F7C0(*(int*)& byte_5D4594[3799476]);
    }
    else
    {
        sub_47D370(v30);
    }
    sub_47D2C0(a3, v59, SHIDWORD(v59));
    sub_4345F0(0);
    sub_434560(0);
    sub_434600(0);
    if (v51)
        sub_49F860();
    *((_WORD*)v3 + 1) = 1;
    LOWORD(v4) = *(_WORD*)& byte_5D4594[3799516];
    *((_WORD*)v3 + 2) = *(_WORD*)& byte_5D4594[3799516];
    *((_WORD*)v3 + 3) = *(_WORD*)& byte_5D4594[3799504];
    *((_DWORD*)v3 + 2) = a3;
    return (__int16)v4;
}
// 4C4AD0: variable 'v35' is possibly undefined
// 4C4AD0: variable 'v34' is possibly undefined

//----- (004C4EC0) --------------------------------------------------------
char __cdecl sub_4C4EC0(_DWORD* a1, int a2)
{
    int v3; // ecx
    int v4; // eax
    int v5; // ecx

    if (*(_DWORD*)& byte_5D4594[2614252] && sub_4356C0(*(int*)& byte_5D4594[2614252], 21))
        return -1;
    v3 = *(_DWORD*)(a2 + 12) - a1[8] / 2 - a1[4];
    v4 = *(_DWORD*)(a2 + 16) - a1[9] / 2 - a1[5];
    v5 = 128 - ((v3 * v3 + v4 * v4) << 7) / *(_DWORD*)& byte_587000[185464];
    if (v5 < 0)
        return 0;
    if (v5 > 128)
        LOBYTE(v5) = -128;
    return v5;
}

//----- (004C4F40) --------------------------------------------------------
__int16 __cdecl sub_4C4F40(_DWORD* a1, int a2)
{
    char* v2; // eax
    int v3; // edi
    signed int v4; // esi
    unsigned int v5; // eax
    signed int v6; // edx

    v2 = *(char**)& byte_5D4594[1321524];
    if (!*(_DWORD*)& byte_5D4594[1321524])
    {
        v2 = sub_42FA20("ShinySpot");
        *(_DWORD*)& byte_5D4594[1321524] = v2;
    }
    v3 = *((_DWORD*)v2 + 24);
    v4 = *(unsigned __int8*)(v3 + 8);
    v5 = (*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(a2 + 128)) / (unsigned int)(8 * v4);
    v6 = ((*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(a2 + 128)) % (unsigned int)(8 * v4)) >> 1;
    if (v6 < v4)
        LOWORD(v5) = sub_47D2C0(
            *(_DWORD*)(*(_DWORD*)(v3 + 4) + 4 * v6),
            *(_DWORD*)(a2 + 12) - a1[4] + *a1 - 64,
            a1[1] - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - a1[5] + *(_DWORD*)(a2 + 16) - 64);
    return v5;
}

//----- (004C4FD0) --------------------------------------------------------
int sub_4C4FD0()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1321536] = sub_4344A0(255, 200, 255);
    *(_DWORD*)& byte_5D4594[1321796] = sub_4344A0(255, 0, 255);
    result = sub_4344A0(100, 40, 100);
    *(_DWORD*)& byte_5D4594[1321532] = result;
    return result;
}

//----- (004C5020) --------------------------------------------------------
int __cdecl sub_4C5020(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1321800];
    if (*(int*)& byte_5D4594[1321800] < 32)
    {
        result = *(_DWORD*)& byte_5D4594[1321800] + 1;
        *(_DWORD*)& byte_5D4594[8 * result + 1321532] = *(_DWORD*)(a1 + 1);
        *(_DWORD*)& byte_5D4594[8 * result + 1321536] = *(_DWORD*)(a1 + 5);
        *(_DWORD*)& byte_5D4594[1321800] = result;
    }
    return result;
}

//----- (004C5050) --------------------------------------------------------
void sub_4C5050()
{
    *(_DWORD*)& byte_5D4594[1321800] = 0;
}

//----- (004C5060) --------------------------------------------------------
int __cdecl sub_4C5060(_DWORD* a1)
{
    int result; // eax
    unsigned __int16* v2; // ebp
    int v3; // esi
    int v4; // edi
    int v5; // ebx
    int v6; // ecx
    int v7; // edi
    int v8; // esi
    int v10; // [esp+0h] [ebp-24h]
    int2 a1a; // [esp+4h] [ebp-20h]
    int2 v12; // [esp+Ch] [ebp-18h]
    int2 a2; // [esp+14h] [ebp-10h]
    int2 v14; // [esp+1Ch] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[2614252];
    if (*(_DWORD*)& byte_5D4594[2614252])
    {
        result = *(_DWORD*)& byte_5D4594[1321800];
        v10 = 0;
        if (*(_DWORD*)& byte_5D4594[1321800] > 0)
        {
            v2 = (unsigned __int16*)& byte_5D4594[1321540];
            do
            {
                v3 = *a1 + *v2 - a1[4];
                v4 = a1[1] + v2[1] - a1[5];
                v5 = sub_4992B0(v3, v4);
                v6 = v2[3] - v2[1];
                if (v3 <= 0 || v3 >= a1[8] - 1 || v4 <= 0 || v4 >= a1[9] - 1)
                    v5 = 0;
                v14.field_0 = v3 + v2[2] - *v2;
                v14.field_4 = v4 + v6;
                v12.field_0 = v3;
                v12.field_4 = v4;
                v7 = sub_498C20(&v12, &v14, (int)a1);
                if (v7)
                {
                    v8 = 0;
                    for (a1a = v12; v8 < v7; v5 = 1 - v5)
                    {
                        *(_QWORD*)& a2 = sub_499290(v8);
                        if (v5)
                            sub_4C51D0(&a1a, &a2);
                        a1a = a2;
                        ++v8;
                    }
                    if (v5)
                        sub_4C51D0(&a1a, &v14);
                }
                else if (v5)
                {
                    sub_4C51D0(&v12, &v14);
                }
                result = v10 + 1;
                v2 += 4;
                ++v10;
            } while (v10 < *(int*)& byte_5D4594[1321800]);
        }
    }
    return result;
}
// 4C5151: variable 'v9' is possibly undefined

//----- (004C51D0) --------------------------------------------------------
int __cdecl sub_4C51D0(int2* a1, int2* a2)
{
    int v2; // esi
    int v3; // edi
    int v4; // ebx
    int v5; // ebp
    int v6; // esi
    int v7; // ecx
    int v8; // eax
    int v9; // ebx
    int v11; // ebp

    v2 = a1->field_4;
    v3 = a1->field_0;
    v4 = a2->field_0 - a1->field_0;
    v5 = a2->field_4 - v2;
    sub_434460(*(int*)& byte_5D4594[1321532]);
    sub_434560(1);
    sub_49F500(v3, v2);
    sub_49F570(v4, v5);
    sub_49E4B0();
    sub_434560(0);
    v6 = v2 - 22;
    sub_434460(*(int*)& byte_5D4594[1321536]);
    sub_49F500(v3, v6);
    sub_49F570(v4, v5);
    sub_49E4B0();
    sub_434460(*(int*)& byte_5D4594[1321796]);
    v7 = v4;
    if (v4 < 0)
        v7 = -v4;
    v8 = v5;
    if (v5 < 0)
        v8 = -v5;
    if (v7 <= v8)
    {
        sub_49F500(v3 - 1, v6);
        v11 = v6 + v5;
        sub_49F500(v4 + v3 - 1, v11);
        sub_49E4B0();
        sub_49F500(v3 + 1, v6);
        sub_49F500(v4 + v3 + 1, v11);
    }
    else
    {
        sub_49F500(v3, v6 - 1);
        v9 = v3 + v4;
        sub_49F500(v9, v6 + v5 - 1);
        sub_49E4B0();
        sub_49F500(v3, v6 + 1);
        sub_49F500(v9, v6 + v5 + 1);
    }
    return sub_49E4B0();
}

//----- (004C52E0) --------------------------------------------------------
int __cdecl sub_4C52E0(int* a1, int a2)
{
    int v2; // edx
    int result; // eax
    int v4; // esi
    int* v5; // edx
    int* v6; // ecx
    int v7; // ebx
    int v8; // eax
    int v9; // edi
    int v10; // esi
    int v11; // ebp
    int v12; // edx
    int v13; // ebx
    int v14; // edi
    int v15; // esi
    bool v16; // cc
    int v17; // [esp+8h] [ebp-14h]
    int v18; // [esp+Ch] [ebp-10h]
    int* v19; // [esp+10h] [ebp-Ch]
    int v20; // [esp+14h] [ebp-8h]
    int v21; // [esp+18h] [ebp-4h]

    v2 = nox_win_height;
    memset(&byte_5D4594[3679340], 0, 4 * nox_win_height);
    result = a2;
    v4 = 0;
    *(_DWORD*)& byte_5D4594[3679320] = v2;
    *(_DWORD*)& byte_5D4594[3798156] = 0;
    v21 = 0;
    if (a2 > 0)
    {
        v5 = a1;
        v6 = a1 + 1;
        v19 = a1 + 1;
        while (1)
        {
            v7 = *(v6 - 1);
            if (v4 == result - 1)
            {
                v8 = *v5;
                v9 = *v6;
                v10 = v5[1];
            }
            else
            {
                v8 = v6[1];
                v9 = *v6;
                v10 = v6[2];
            }
            if (v9 != v10)
            {
                if (v7 == v8)
                {
                    if (v10 <= v9)
                    {
                        if (v10 >= v9)
                            goto LABEL_26;
                        do
                            sub_4C5430(v7, v10++);
                        while (v10 < v9);
                    }
                    else
                    {
                        do
                            sub_4C5430(v7, v9++);
                        while (v9 < v10);
                    }
                    goto LABEL_25;
                }
                if (v9 <= v10)
                {
                    v17 = *(v6 - 1);
                    v11 = v9;
                    v18 = v10;
                    v12 = v8 <= v7 ? -1 : 1;
                }
                else
                {
                    v17 = v8;
                    v11 = v10;
                    v18 = v9;
                    v12 = v8 <= v7 ? 1 : -1;
                }
                v20 = v12;
                if (v8 - v7 >= 0)
                    v13 = v8 - v7;
                else
                    v13 = v7 - v8;
                v14 = v18 - v11;
                v15 = 0;
                if (v11 < v18)
                {
                    do
                    {
                        sub_4C5430(v17, v11);
                        v15 += v13;
                        ++v11;
                        for (; v15 >= v14; v17 += v20)
                            v15 -= v14;
                    } while (v11 < v18);
                LABEL_25:
                    v6 = v19;
                    goto LABEL_26;
                }
            }
        LABEL_26:
            result = a2;
            v4 = v21 + 1;
            v6 += 2;
            v16 = ++v21 < a2;
            v19 = v6;
            if (!v16)
                return result;
            v5 = a1;
        }
    }
    return result;
}

//----- (004C5430) --------------------------------------------------------
void __cdecl sub_4C5430(int a1, int a2)
{
    int v2; // esi
    int v3; // ecx
    unsigned __int8* v4; // eax
    int v5; // eax
    unsigned __int8* v6; // edx

    v2 = *(_DWORD*)& byte_5D4594[4 * a2 + 3679340];
    if (v2 < 32)
    {
        v3 = 0;
        if (v2 > 0)
        {
            v4 = &byte_5D4594[128 * a2 + 3682956];
            do
            {
                if (a1 < *(int*)v4)
                    break;
                ++v3;
                v4 += 4;
            } while (v3 < v2);
        }
        if (v3 != v2 && v2 - 1 >= v3)
        {
            v5 = v2 - v3;
            v6 = &byte_5D4594[4 * (v2 - 1 + 32 * a2) + 3682960];
            do
            {
                *(_DWORD*)v6 = *((_DWORD*)v6 - 1);
                v6 -= 4;
                --v5;
            } while (v5);
        }
        *(_DWORD*)& byte_5D4594[4 * a2 + 3679340] = v2 + 1;
        *(_DWORD*)& byte_5D4594[4 * (v3 + 32 * a2) + 3682956] = a1;
        if (a2 < *(int*)& byte_5D4594[3679320])
            * (_DWORD*)& byte_5D4594[3679320] = a2;
        if (a2 > * (int*)& byte_5D4594[3798156])
            * (_DWORD*)& byte_5D4594[3798156] = a2;
    }
}

//----- (004C54D0) --------------------------------------------------------
void sub_4C54D0()
{
    ++* (_DWORD*)& byte_587000[185504];
}

//----- (004C54E0) --------------------------------------------------------
int sub_4C54E0()
{
    int result; // eax

    result = -- * (_DWORD*)& byte_587000[185504];
    if (*(int*)& byte_587000[185504] <= 0)
        * (_DWORD*)& byte_587000[185504] = 1;
    return result;
}

//----- (004C5500) --------------------------------------------------------
int __cdecl sub_4C5500(int* a1)
{
    int* v1; // ebx
    int v2; // ebp
    int v3; // esi
    int v4; // edi
    int v5; // eax
    unsigned __int8* v6; // ebx
    int* v7; // esi
    int v8; // eax
    int v9; // ecx
    unsigned int v10; // ebp
    int v11; // ecx
    int result; // eax
    unsigned __int8* v13; // [esp+10h] [ebp-14h]
    int v14; // [esp+18h] [ebp-Ch]
    int v15; // [esp+1Ch] [ebp-8h]
    int v16; // [esp+20h] [ebp-4h]

    v1 = a1;
    v2 = *a1;
    v3 = a1[1];
    v14 = *a1;
    v15 = a1[1];
    v16 = sub_49F6D0(0);
    sub_434460(*(int*)& byte_5D4594[2650656]);
    v4 = *(_DWORD*)& byte_5D4594[3679320];
    if (*(_DWORD*)& byte_5D4594[3679320] > v3)
    {
        sub_49CE30(v2, v3, a1[8], *(_DWORD*)& byte_5D4594[3679320] - v3);
        v4 = *(_DWORD*)& byte_5D4594[3679320];
    }
    v5 = *(_DWORD*)& byte_5D4594[3798156];
    if (v4 < *(int*)& byte_5D4594[3798156])
    {
        v13 = &byte_5D4594[4 * v4 + 3679340];
        v6 = &byte_5D4594[128 * v4 + 3682956];
        do
        {
            v7 = (int*)(v6 + 4);
            v8 = v2;
            v9 = *(_DWORD*)v6;
            if (*(_DWORD*)v13 > 0)
            {
                v10 = (unsigned int)(*(_DWORD*)v13 + 1) >> 1;
                do
                {
                    (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(v8, v4, v9);
                    v8 = *v7;
                    v9 = v7[1];
                    v7 += 2;
                    --v10;
                } while (v10);
                v2 = v14;
            }
            (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(v8, v4, v2 + a1[8]);
            v5 = *(_DWORD*)& byte_5D4594[3798156];
            ++v4;
            v6 += 128;
            v13 += 4;
        } while (v4 < *(int*)& byte_5D4594[3798156]);
        v3 = v15;
        v1 = a1;
    }
    v11 = v1[9];
    if (v5 < v11 + v3)
        sub_49CE30(v2, v5, v1[8], v3 + v11 - v5);
    sub_49F6D0(v16);
    result = *(_DWORD*)& byte_5D4594[2650636];
    if (result & 0x400)
        result = sub_498AE0();
    return result;
}

//----- (004C5630) --------------------------------------------------------
int __cdecl sub_4C5630(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    unsigned __int8* i; // eax

    v3 = 0;
    v4 = *(_DWORD*)& byte_5D4594[4 * a3 + 3679340];
    if (v4 <= 0)
        return 0;
    for (i = &byte_5D4594[128 * a3 + 3682956]; a1 > * ((_DWORD*)i + 1) || a2 < *(int*)i; i += 8)
    {
        v3 += 2;
        if (v3 >= v4)
            return 0;
    }
    return 1;
}

//----- (004C5680) --------------------------------------------------------
int __cdecl sub_4C5680(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    unsigned __int8* i; // eax

    v3 = 0;
    v4 = *(_DWORD*)& byte_5D4594[4 * a3 + 3679340];
    if (v4 <= 0)
        return 0;
    for (i = &byte_5D4594[128 * a3 + 3682960]; a1 < *((_DWORD*)i - 1) || a2 >= *(int*)i; i += 8)
    {
        v3 += 2;
        if (v3 >= v4)
            return 0;
    }
    return 1;
}

//----- (004C56D0) --------------------------------------------------------
int __cdecl sub_4C56D0(_DWORD* a1)
{
    int v1; // eax
    int v2; // ebp
    int v3; // ecx
    int v4; // edx
    int result; // eax
    int v6; // ecx
    int v7; // ebx
    int v8; // edx
    int v9; // esi
    bool v10; // cc
    unsigned __int8* v11; // edx
    int v12; // eax
    unsigned __int8* v13; // edi
    int v14; // ebp
    unsigned int v15; // ecx

    v1 = a1[5];
    if (v1 >= 0)
    {
        if (v1 >= 46)
            v2 = 0;
        else
            v2 = 46 - v1;
    }
    else
    {
        v2 = 46 - v1;
    }
    *(_DWORD*)& byte_5D4594[3679320] = v2;
    v3 = a1[9];
    v4 = a1[5];
    result = nox_win_height;
    if (v3 + v4 > 5865)
        result = nox_win_height - v3 - v4 + 5865;
    *(_DWORD*)& byte_5D4594[3798156] = result;
    if (result < 0)
    {
        result = 0;
        *(_DWORD*)& byte_5D4594[3798156] = 0;
    }
    v6 = a1[4];
    if (v6 >= 0)
    {
        if (v6 >= 46)
            v7 = 0;
        else
            v7 = 46 - v6;
    }
    else
    {
        v7 = 46 - v6;
    }
    v8 = a1[8];
    v9 = nox_win_width;
    if (v8 + v6 > 5865)
        v9 = nox_win_width - v8 - v6 + 5865;
    if (v9 < 0)
        v9 = 0;
    if (v7 > v9)
        v7 = v9;
    v10 = v2 < result;
    if (v2 > result)
    {
        v2 = result;
        *(_DWORD*)& byte_5D4594[3679320] = result;
        v10 = 0;
    }
    if (v10)
    {
        v11 = &byte_5D4594[128 * v2 + 3682960];
        v12 = result - v2;
        v13 = &byte_5D4594[4 * v2 + 3679340];
        v14 = v12;
        v15 = v12;
        result = 2;
        memset32(v13, 2, v15);
        do
        {
            *((_DWORD*)v11 - 1) = v7;
            *(_DWORD*)v11 = v9;
            v11 += 128;
            --v14;
        } while (v14);
    }
    return result;
}

//----- (004C57C0) --------------------------------------------------------
int __cdecl sub_4C57C0(FILE* a1, int a2, _DWORD* a3, _DWORD* a4)
{
    int result; // eax

    if (!a1)
        return 0;
    result = sub_4C5850(a1);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[1322572])
        {
            result = sub_4C5A60(a1, a2);
            if (!result)
                return result;
        }
        else if (!sub_4C5CB0(a1) || !sub_4C5D20(a1, a2))
        {
            return 0;
        }
        fclose(a1);
        *a3 = *(_DWORD*)& byte_5D4594[3679312];
        *a4 = *(_DWORD*)& byte_5D4594[3679316];
        result = 1;
    }
    return result;
}

//----- (004C5850) --------------------------------------------------------
BOOL __cdecl sub_4C5850(FILE* a1)
{
    FILE* v1; // esi
    int v3; // [esp+4h] [ebp-4h]

    v1 = a1;
    if (fscanf(a1, "%c", &a1) != 1)
        return 0;
    if ((_BYTE)a1 != 10)
        return 0;
    if (fscanf(v1, "%c", &a1) != 1)
        return 0;
    if ((_BYTE)a1 != 5)
        return 0;
    if (fscanf(v1, "%c", &a1) != 1)
        return 0;
    if ((_BYTE)a1 != 1)
        return 0;
    if (fscanf(v1, "%c", &a1) != 1)
        return 0;
    if ((_BYTE)a1 != 8)
        return 0;
    if (fscanf(v1, "%2c", &v3) != 1)
        return 0;
    if ((_WORD)v3)
        return 0;
    if (fscanf(v1, "%2c", &v3) != 1)
        return 0;
    if ((_WORD)v3)
        return 0;
    if (fscanf(v1, "%2c", &v3) != 1)
        return 0;
    *(_DWORD*)& byte_5D4594[3679312] = (unsigned __int16)v3;
    if (fscanf(v1, "%2c", &v3) != 1)
        return 0;
    *(_DWORD*)& byte_5D4594[3679316] = (unsigned __int16)v3;
    if (*(_DWORD*)& byte_5D4594[3679312] > 639)
        return 0;
    if ((int)(unsigned __int16)v3 > 639)
        return 0;
    ++* (_DWORD*)& byte_5D4594[3679312];
    *(_DWORD*)& byte_5D4594[3679316] = (unsigned __int16)v3 + 1;
    fseek(v1, 65, 0);
    if (fscanf(v1, "%c", &a1) != 1)
        return 0;
    if ((_BYTE)a1 == 1)
    {
        *(_DWORD*)& byte_5D4594[1322572] = 0;
    }
    else
    {
        if ((_BYTE)a1 != 3)
            return 0;
        *(_DWORD*)& byte_5D4594[1322572] = 1;
    }
    if (fscanf(v1, "%2c", &v3) == 1)
    {
        *(_DWORD*)& byte_5D4594[3679308] = (unsigned __int16)v3;
        return fscanf(v1, "%2c", &v3) == 1;
    }
    return 0;
}

//----- (004C5A60) --------------------------------------------------------
int __cdecl sub_4C5A60(FILE* a1, int a2)
{
    int v2; // ebx
    int v3; // ebp
    int v4; // eax
    int v5; // esi
    char v6; // dl
    int v7; // eax
    int v8; // ecx
    bool v9; // cc
    int v11; // [esp+10h] [ebp-10h]
    int v12; // [esp+14h] [ebp-Ch]
    int v13; // [esp+18h] [ebp-8h]
    int v14; // [esp+1Ch] [ebp-4h]
    int i; // [esp+28h] [ebp+8h]

    HIWORD(v2) = 0;
    LOBYTE(v12) = 0;
    LOBYTE(v11) = 0;
    fseek(a1, 128, 0);
    v13 = 0;
    if (*(_DWORD*)& byte_5D4594[3679316] > 0)
    {
        v3 = a2;
        v4 = *(_DWORD*)& byte_5D4594[3679308];
        v14 = a2;
        while (2)
        {
            for (i = 0; i < 3; ++i)
            {
                v5 = 0;
                if (v4 > 0)
                {
                    while (sub_4C5B80(a1, v5, &v11, &v12))
                    {
                        LOBYTE(v2) = v12;
                        v6 = v11;
                        BYTE1(v2) = v12;
                        v7 = v2 << 16;
                        LOWORD(v7) = v2;
                        v8 = (unsigned __int8)v11 >> 2;
                        memset32((void*)(v5 + v3), v7, v8);
                        memset((void*)(v5 + v3 + 4 * v8), v2, v6 & 3);
                        v5 += (unsigned __int8)v11;
                        v4 = *(_DWORD*)& byte_5D4594[3679308];
                        if (v5 >= *(int*)& byte_5D4594[3679308])
                            goto LABEL_7;
                    }
                    return 0;
                }
            LABEL_7:
                v3 += 409600;
            }
            v3 = v14 + 640;
            v9 = ++v13 < *(int*)& byte_5D4594[3679316];
            v14 += 640;
            if (v9)
                continue;
            break;
        }
    }
    sub_4C5B80(a1, 0, &v11, &v12);
    return 1;
}

//----- (004C5B80) --------------------------------------------------------
int __cdecl sub_4C5B80(FILE* a1, int a2, _BYTE* a3, _BYTE* a4)
{
    int v4; // eax
    int v5; // ecx
    int result; // eax
    _BYTE* v7; // ecx
    FILE* v8; // esi
    char v9; // bl
    int v10; // ebx
    unsigned __int8 v11; // al
    _BYTE* v12; // eax
    char v13; // cl
    _BYTE* v14; // eax

    if (*(_DWORD*)& byte_5D4594[1322576])
    {
        v4 = a2;
        if (*(_DWORD*)& byte_5D4594[1322576] + a2 <= *(int*)& byte_5D4594[3679308])
        {
            v7 = a4;
            *a3 = byte_5D4594[1322576];
            *(_DWORD*)& byte_5D4594[1322576] = 0;
            *v7 = byte_5D4594[1322580];
            result = 1;
        }
        else
        {
            *a3 = byte_5D4594[3679308] - a2;
            v5 = v4 - *(_DWORD*)& byte_5D4594[3679308] + *(_DWORD*)& byte_5D4594[1322576];
            result = 1;
            *(_DWORD*)& byte_5D4594[1322576] = v5;
        }
    }
    else
    {
        v8 = a1;
        if (fscanf(a1, "%c", &a1) == 1)
        {
            v9 = (char)a1;
            if (((unsigned __int8)a1 & 0xC0) == 0xC0)
            {
                v10 = (unsigned __int8)a1 & 0x3F;
                if (fscanf(v8, "%c", &a1) == 1)
                {
                    if (v10 + a2 <= *(int*)& byte_5D4594[3679308])
                    {
                        v12 = a4;
                        v13 = (char)a1;
                        *a3 = v10;
                        *v12 = v13;
                    }
                    else
                    {
                        v11 = byte_5D4594[3679308] - a2;
                        *a3 = byte_5D4594[3679308] - a2;
                        *(_DWORD*)& byte_5D4594[1322576] = v10 - v11;
                        *(_DWORD*)& byte_5D4594[1322580] = (unsigned __int8)a1;
                        *a4 = (_BYTE)a1;
                    }
                    result = 1;
                }
                else
                {
                    result = 0;
                }
            }
            else
            {
                v14 = a4;
                *a3 = 1;
                *v14 = v9;
                result = 1;
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (004C5CB0) --------------------------------------------------------
BOOL __cdecl sub_4C5CB0(FILE* a1)
{
    FILE* v1; // esi

    v1 = a1;
    if (fseek(a1, -769, 2))
        return 0;
    if (fread(&a1, 1u, 1u, v1) != 1)
        return 0;
    if ((_BYTE)a1 == 12)
        return fread(&byte_5D4594[1321804], 1u, 0x300u, v1) == 768;
    return 0;
}

//----- (004C5D20) --------------------------------------------------------
int __cdecl sub_4C5D20(FILE* a1, int a2)
{
    int v2; // ebx
    int v3; // eax
    int v4; // ebp
    int v5; // esi
    char* v6; // edi
    char v7; // dl
    int v8; // eax
    int v9; // ecx
    char* v10; // edi
    char v11; // dl
    int v12; // eax
    int v13; // ecx
    char v14; // dl
    int v15; // eax
    int v16; // ecx
    int result; // eax
    int v18; // [esp+10h] [ebp-Ch]
    int v19; // [esp+14h] [ebp-8h]
    int v20; // [esp+18h] [ebp-4h]

    HIWORD(v2) = 0;
    LOBYTE(v19) = 0;
    LOBYTE(v18) = 0;
    fseek(a1, 128, 0);
    v20 = 0;
    if (*(int*)& byte_5D4594[3679316] <= 0)
    {
    LABEL_7:
        sub_4C5B80(a1, 0, &v18, &v19);
        result = 1;
    }
    else
    {
        v3 = *(_DWORD*)& byte_5D4594[3679308];
        v4 = a2 + 819200;
        while (1)
        {
            v5 = 0;
            if (v3 > 0)
                break;
        LABEL_6:
            v4 += 640;
            if (++v20 >= *(int*)& byte_5D4594[3679316])
                goto LABEL_7;
        }
        while (sub_4C5B80(a1, v5, &v18, &v19))
        {
            v6 = (char*)(v5 + v4 - 819200);
            v7 = v18;
            LOBYTE(v2) = byte_5D4594[3 * (unsigned __int8)v19 + 1321804];
            BYTE1(v2) = byte_5D4594[3 * (unsigned __int8)v19 + 1321804];
            v8 = v2 << 16;
            LOWORD(v8) = v2;
            v9 = (unsigned __int8)v18 >> 2;
            memset32(v6, v8, v9);
            memset(&v6[4 * v9], v2, v7 & 3);
            v10 = (char*)(v5 + v4 - 409600);
            v11 = v18;
            LOBYTE(v2) = byte_5D4594[3 * (unsigned __int8)v19 + 1321805];
            BYTE1(v2) = byte_5D4594[3 * (unsigned __int8)v19 + 1321805];
            v12 = v2 << 16;
            LOWORD(v12) = v2;
            v13 = (unsigned __int8)v18 >> 2;
            memset32(v10, v12, v13);
            memset(&v10[4 * v13], v2, v11 & 3);
            v14 = v18;
            LOBYTE(v2) = byte_5D4594[3 * (unsigned __int8)v19 + 1321806];
            BYTE1(v2) = byte_5D4594[3 * (unsigned __int8)v19 + 1321806];
            v15 = v2 << 16;
            LOWORD(v15) = v2;
            v16 = (unsigned __int8)v18 >> 2;
            memset32((void*)(v5 + v4), v15, v16);
            memset((void*)(v5 + v4 + 4 * v16), v2, v14 & 3);
            v5 += (unsigned __int8)v18;
            v3 = *(_DWORD*)& byte_5D4594[3679308];
            if (v5 >= *(int*)& byte_5D4594[3679308])
                goto LABEL_6;
        }
        result = 0;
    }
    return result;
}

//----- (004C5EB0) --------------------------------------------------------
void __cdecl sub_4C5EB0(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // eax

    if (a1)
    {
        switch (*(_BYTE*)(a1 + 10) & 0x3F)
        {
        case 2:
        case 7:
            *(_DWORD*)& byte_5D4594[3799536] = sub_4C69A0;
            sub_4C60D0(a1, a2, a3);
            return;
        case 3:
        case 4:
        case 5:
        case 6:
            *(_DWORD*)& byte_5D4594[3799544] = sub_4C7110;
            *(_DWORD*)& byte_5D4594[3799488] = sub_4C6E40;
            if (!ptr_5D4594_3799572->data[13])
            {
                if (ptr_5D4594_3799572->data[14])
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C6BA0;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C7060;
                    sub_4C6260(a1, a2, a3);
                    return;
                }
                goto LABEL_21;
            }
            *(_DWORD*)& byte_5D4594[3799544] = sub_4C7240;
            if (ptr_5D4594_3799572->data[14])
            {
                v3 = ptr_5D4594_3799572->data[259];
                if (v3 == 255)
                {
                    if (!ptr_5D4594_3799572->data[16])
                    {
                        *(_DWORD*)& byte_5D4594[3799536] = sub_4C6BA0;
                        *(_DWORD*)& byte_5D4594[3799432] = sub_4C7060;
                        sub_4C6260(a1, a2, a3);
                        return;
                    }
                    goto LABEL_21;
                }
                if (v3 == 128)
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C6BF0;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C6FD0;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C6E40;
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C6C60;
                }
                sub_4C6260(a1, a2, a3);
            }
            else
            {
                v4 = ptr_5D4594_3799572->data[259];
                if (v4 == 255)
                {
                LABEL_21:
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C69A0;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C6DE0;
                    sub_4C6260(a1, a2, a3);
                    return;
                }
                if (v4 == 128)
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C6B50;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C6FD0;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C6E40;
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C6A00;
                }
                sub_4C6260(a1, a2, a3);
            }
            break;
        case 8:
            *(_DWORD*)& byte_5D4594[3799536] = sub_4C73A0;
            sub_4C6260(a1, a2, a3);
            return;
        default:
            return;
        }
    }
}

//----- (004C60D0) --------------------------------------------------------
void __cdecl sub_4C60D0(int a1, int a2, int a3)
{
    int4* result; // eax
    int v4; // esi
    int* v5; // eax
    int4* v6; // ecx
    int v7; // ebx
    int v8; // edx
    int v9; // edi
    int v10; // ebp
    int v11; // eax
    int v12; // edx
    int v13; // esi
    int v14; // ecx
    int v15; // ebx
    int v16; // ebp
    int4 a1a; // [esp+10h] [ebp-20h]
    RECT rc; // [esp+20h] [ebp-10h]
    int v19; // [esp+3Ch] [ebp+Ch]

    result = (int4*)(*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3799492])(a1);
    *(_DWORD*)& byte_5D4594[3799444] = result;
    if (result)
    {
        v4 = result->field_0;
        v5 = &result->field_4;
        *(_DWORD*)& byte_5D4594[3799444] = v5;
        v6 = (int4*)* v5;
        ++v5;
        v7 = v4;
        *(_DWORD*)& byte_5D4594[3799444] = v5;
        v8 = *v5;
        ++v5;
        *(_DWORD*)& byte_5D4594[3799560] = v8;
        v9 = v8 + a2;
        *(_DWORD*)& byte_5D4594[3799444] = v5;
        *(_DWORD*)& byte_5D4594[3799556] = *v5;
        v10 = *(_DWORD*)& byte_5D4594[3799556] + a3;
        result = (int4*)(v5 + 1);
        v19 = *(_DWORD*)& byte_5D4594[3799556] + a3;
        *(_DWORD*)& byte_5D4594[3799444] = result;
        if (*(_DWORD*)& byte_5D4594[3799484])
        {
            v6 = (int4*)((char*)v6 - *(_DWORD*)& byte_5D4594[3799484]);
            if ((int)v6 <= 0)
                return;
            *(_DWORD*)& byte_5D4594[3799476] = (char*)v6 + v10;
        }
        *(_DWORD*)& byte_5D4594[3799520] = v8 + a2;
        *(_DWORD*)& byte_5D4594[3799444] = (char*)result + 1;
        *(_DWORD*)& byte_5D4594[3799512] = v10;
        *(_DWORD*)& byte_5D4594[3799516] = v4;
        *(_DWORD*)& byte_5D4594[3799504] = v6;
        if (ptr_5D4594_3799572->data[0])
        {
            SetRect(&rc, v9, v10, v4 + v9, (int)v6 + v10);
            result = sub_49F930(&a1a, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
            if (!result)
                return;
            v11 = a1a.field_0 - rc.left;
            v12 = a1a.field_4 - rc.top;
            v7 = a1a.field_8 - a1a.field_0;
            v6 = (int4*)(a1a.field_C - a1a.field_4);
            if (a1a.field_0 != rc.left || v12)
            {
                v9 += v11;
                v7 = a1a.field_8 - a1a.field_0;
                *(_DWORD*)& byte_5D4594[3799444] += v11 + v4 * v12;
                v10 = v12 + v19;
            }
            else
            {
                v10 = v19;
            }
        }
        v13 = v4 - v7;
        result = v6;
        v14 = (int)& v6[-1].field_C + 3;
        *(_DWORD*)& byte_5D4594[3799456] = v7;
        if (result)
        {
            v15 = 4 * v10;
            v16 = v14 + 1;
            do
            {
                v15 += 4;
                *(_DWORD*)& byte_5D4594[3799540] = v9 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784] - 4);
                (*(void (**)(void)) & byte_5D4594[3799536])();
                --v16;
                *(_DWORD*)& byte_5D4594[3799444] += v13;
            } while (v16);
        }
    }
}

//----- (004C6260) --------------------------------------------------------
int __cdecl sub_4C6260(int a1, int a2, int a3)
{
    int result; // eax
    signed int v4; // ebx
    int v5; // edi
    int* v6; // ecx
    int v7; // eax
    int v8; // ebp
    int v9; // eax
    int v10; // esi
    int v11; // ecx
    int v12; // ecx
    int4* v13; // edi
    int v14; // edx
    signed int v15; // esi
    void* v16; // eax
    int v17; // edx
    RECT rc; // [esp+10h] [ebp-20h]
    int4 a1a; // [esp+20h] [ebp-10h]
    int v20; // [esp+34h] [ebp+4h]
    int v21; // [esp+38h] [ebp+8h]
    int4* v22; // [esp+3Ch] [ebp+Ch]

    result = (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3799492])(a1);
    *(_DWORD*)& byte_5D4594[3799444] = result;
    if (result)
    {
        v4 = *(_DWORD*)result;
        *(_DWORD*)& byte_5D4594[3799444] = result + 4;
        v5 = *(_DWORD*)(result + 4);
        v6 = (int*)(result + 8);
        *(_DWORD*)& byte_5D4594[3799444] = v6;
        v7 = *(_DWORD*)(result + 8);
        ++v6;
        *(_DWORD*)& byte_5D4594[3799560] = v7;
        v8 = v7 + a2;
        *(_DWORD*)& byte_5D4594[3799444] = v6;
        v9 = *v6;
        *(_DWORD*)& byte_5D4594[3799556] = v9;
        v10 = v9 + a3;
        result = *(_DWORD*)& byte_5D4594[3799484];
        v11 = (int)(v6 + 1);
        *(_DWORD*)& byte_5D4594[3799444] = v11;
        if (*(_DWORD*)& byte_5D4594[3799484])
        {
            v5 -= *(_DWORD*)& byte_5D4594[3799484];
            if (v5 <= 0)
                return result;
            *(_DWORD*)& byte_5D4594[3799476] = v5 + v10;
        }
        *(_DWORD*)& byte_5D4594[3799444] = v11 + 1;
        *(_DWORD*)& byte_5D4594[3799520] = v8;
        *(_DWORD*)& byte_5D4594[3799512] = v10;
        *(_DWORD*)& byte_5D4594[3799516] = v4;
        *(_DWORD*)& byte_5D4594[3799504] = v5;
        if (!ptr_5D4594_3799572->data[0])
            goto LABEL_30;
        SetRect(&rc, v8, v10, v4 + v8, v5 + v10);
        result = sub_49F930(&a1a, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
        if (!result)
            return result;
        if (rc.left != a1a.field_0 || rc.right != a1a.field_8 || rc.top != a1a.field_4 || rc.bottom != a1a.field_C)
        {
            result = sub_4C64E0(v8, v10, v4, &a1a.field_0);
        }
        else
        {
        LABEL_30:
            result = v10 & 1;
            v20 = 0;
            *(_DWORD*)& byte_5D4594[3799508] ^= result;
            v12 = v5;
            v13 = (int4*)(v5 - 1);
            v22 = v13;
            if (v12)
            {
                v14 = 4 * v10;
                v21 = 4 * v10;
                do
                {
                    v15 = v4;
                    v16 = (void*)(*(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784]) + v8);
                    *(_DWORD*)& byte_5D4594[3799540] = *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784]) + v8;
                    if (*(_DWORD*)& byte_5D4594[3799552] && (*(_DWORD*)& byte_5D4594[3799508] ^= 1u) != 0)
                    {
                        if (v20)
                        {
                            qmemcpy(v16, (const void*)(v8 + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784] - 4)), v4);
                            v13 = v22;
                        }
                        sub_4C6900(v4, 1);
                    }
                    else if (v4 > 0)
                    {
                        while (2)
                        {
                            *(_DWORD*)& byte_5D4594[3799428] = (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444];
                            ++* (_DWORD*)& byte_5D4594[3799444];
                            v17 = (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444];
                            result = (byte_5D4594[3799428] & 0xF) - 1;
                            *(_DWORD*)& byte_5D4594[3799456] = (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444];
                            ++* (_DWORD*)& byte_5D4594[3799444];
                            switch (byte_5D4594[3799428] & 0xF)
                            {
                            case 1:
                                *(_DWORD*)& byte_5D4594[3799540] += v17;
                                goto LABEL_26;
                            case 2:
                            case 7:
                                (*(void (**)(void)) & byte_5D4594[3799536])();
                                goto LABEL_26;
                            case 4:
                                (*(void (**)(void)) & byte_5D4594[3799432])();
                                goto LABEL_26;
                            case 5:
                                (*(void (**)(void)) & byte_5D4594[3799544])();
                                goto LABEL_26;
                            case 6:
                                (*(void (**)(void)) & byte_5D4594[3799488])();
                            LABEL_26:
                                v15 -= *(_DWORD*)& byte_5D4594[3799456];
                                if (v15 <= 0)
                                    break;
                                continue;
                            default:
                                return result;
                            }
                        }
                    }
                    v14 = v21 + 4;
                    result = (int)v13;
                    v13 = (int4*)((char*)v13 - 1);
                    ++v20;
                    v21 += 4;
                    v22 = v13;
                } while (result);
            }
        }
    }
    return result;
}

//----- (004C64E0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4C64E0(int a1, int a2, int a3, int* a4)
{
    int v4; // ebp
    int v5; // ebx
    unsigned __int8* result; // eax
    int v7; // edi
    int v8; // ecx
    unsigned __int8* v9; // esi
    int v10; // esi
    int v11; // edi
    int v12; // edx
    int v13; // esi
    unsigned int v14; // ecx
    char* v15; // esi
    char* v16; // eax
    char v17; // dl
    unsigned int v18; // ecx
    char* v19; // edi
    char* v20; // esi
    int v21; // edx
    int v22; // ecx
    unsigned __int8* v23; // eax
    int v24; // ecx
    int v25; // edi
    int v26; // ecx
    int v27; // edx
    int v28; // edi
    int v29; // ecx
    int v30; // edi
    int v31; // ecx
    int v32; // edi
    int v33; // ecx
    int v34; // edi
    int v35; // ecx
    bool v36; // zf
    unsigned __int8* v37; // [esp+10h] [ebp-18h]
    int v38; // [esp+14h] [ebp-14h]
    int v39; // [esp+18h] [ebp-10h]
    int v40; // [esp+1Ch] [ebp-Ch]
    int v41; // [esp+20h] [ebp-8h]
    int v42; // [esp+24h] [ebp-4h]
    int v43; // [esp+30h] [ebp+8h]
    int v44; // [esp+38h] [ebp+10h]

    v4 = *a4;
    v5 = a4[2];
    result = *(unsigned __int8**)& byte_5D4594[3799484];
    v7 = a2;
    v8 = a4[1] - a2;
    v9 = (unsigned __int8*)(a4[3] - a4[1]);
    v44 = a4[2];
    if (*(_DWORD*)& byte_5D4594[3799484])
    {
        v9 -= *(_DWORD*)& byte_5D4594[3799484];
        if ((int)v9 <= 0)
            return result;
        *(_DWORD*)& byte_5D4594[3799476] = &v9[a2];
    }
    if (v8)
    {
        v7 = v8 + a2;
        sub_4C6900(a3, v8);
    }
    v39 = 0;
    *(_DWORD*)& byte_5D4594[3799508] ^= v7 & 1;
    result = v9;
    v10 = (int)(v9 - 1);
    if (result)
    {
        result = *(unsigned __int8**)& byte_5D4594[3799444];
        v11 = 4 * v7;
        v40 = v11;
        v42 = v10 + 1;
        do
        {
            v12 = a3;
            v13 = a1;
            v41 = a3;
            if (!*(_DWORD*)& byte_5D4594[3799552] || (*(_DWORD*)& byte_5D4594[3799508] ^= 1u) == 0)
            {
                v21 = a1 + *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]);
                *(_DWORD*)& byte_5D4594[3799540] = a1 + *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]);
                if (a3 <= 0)
                    goto LABEL_85;
                while (1)
                {
                    v38 = v21;
                    v22 = *result;
                    v23 = result + 1;
                    *(_DWORD*)& byte_5D4594[3799428] = v22;
                    *(_DWORD*)& byte_5D4594[3799444] = v23;
                    v24 = *v23;
                    result = v23 + 1;
                    *(_DWORD*)& byte_5D4594[3799456] = v24;
                    *(_DWORD*)& byte_5D4594[3799444] = result;
                    v37 = result;
                    v43 = v24;
                    switch (byte_5D4594[3799428] & 0xF)
                    {
                    case 1:
                        v21 += v24;
                        *(_DWORD*)& byte_5D4594[3799540] = v21;
                        goto LABEL_82;
                    case 2:
                        v25 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v44;
                            if (v25 > v4)
                            {
                                if (v25 <= v44)
                                    v26 = v13 - v4 + v24;
                                else
                                    v26 = v44 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v26;
                                *(_DWORD*)& byte_5D4594[3799444] = &result[v4 - v13];
                                *(_DWORD*)& byte_5D4594[3799540] = v4 - v13 + v21;
                                goto LABEL_28;
                            }
                        }
                        else
                        {
                            v5 = v44;
                            if (v25 <= v44)
                                goto LABEL_28;
                        }
                        if (v13 < v5 && v25 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_28:
                            (*(void (**)(void)) & byte_5D4594[3799536])();
                        }
                        v27 = v43;
                        result = &v37[v43];
                    LABEL_80:
                        *(_DWORD*)& byte_5D4594[3799444] = result;
                        v21 = v38 + v27;
                        *(_DWORD*)& byte_5D4594[3799540] = v21;
                    LABEL_83:
                        v13 += v43;
                        v41 -= v43;
                        if (v41 <= 0)
                        {
                            v11 = v40;
                            goto LABEL_85;
                        }
                        break;
                    case 4:
                        v30 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v44;
                            if (v30 > v4)
                            {
                                if (v30 <= v44)
                                    v31 = v13 - v4 + v24;
                                else
                                    v31 = v44 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v31;
                                *(_DWORD*)& byte_5D4594[3799444] = &result[v4 - v13];
                                *(_DWORD*)& byte_5D4594[3799540] = v4 - v13 + v21;
                                goto LABEL_52;
                            }
                        }
                        else
                        {
                            v5 = v44;
                            if (v30 <= v44)
                                goto LABEL_52;
                        }
                        if (v13 < v5 && v30 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_52:
                            (*(void (**)(void)) & byte_5D4594[3799432])();
                        }
                        v27 = v43;
                        result = &v37[v43];
                        goto LABEL_80;
                    case 5:
                        v32 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v44;
                            if (v32 > v4)
                            {
                                if (v32 <= v44)
                                    v33 = v13 - v4 + v24;
                                else
                                    v33 = v44 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v33;
                                *(_DWORD*)& byte_5D4594[3799540] = v4 - v13 + v21;
                                *(_DWORD*)& byte_5D4594[3799444] = &result[2 * (v4 - v13)];
                                goto LABEL_65;
                            }
                        }
                        else
                        {
                            v5 = v44;
                            if (v32 <= v44)
                                goto LABEL_65;
                        }
                        if (v13 < v5 && v32 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_65:
                            (*(void (**)(void)) & byte_5D4594[3799544])();
                        }
                        result = &v37[2 * v43];
                        v21 = v38 + v43;
                        *(_DWORD*)& byte_5D4594[3799444] = &v37[2 * v43];
                        *(_DWORD*)& byte_5D4594[3799540] = v38 + v43;
                        goto LABEL_83;
                    case 6:
                        v34 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v44;
                            if (v34 > v4)
                            {
                                if (v34 <= v44)
                                    v35 = v13 - v4 + v24;
                                else
                                    v35 = v44 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v35;
                                *(_DWORD*)& byte_5D4594[3799540] = v4 - v13 + v21;
                                *(_DWORD*)& byte_5D4594[3799444] = &result[2 * (v4 - v13)];
                                goto LABEL_78;
                            }
                        }
                        else
                        {
                            v5 = v44;
                            if (v34 <= v44)
                                goto LABEL_78;
                        }
                        if (v13 < v5 && v34 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_78:
                            (*(void (**)(void)) & byte_5D4594[3799488])();
                        }
                    LABEL_79:
                        v27 = v43;
                        result = &v37[2 * v43];
                        goto LABEL_80;
                    case 7:
                        v28 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v44;
                            if (v28 > v4)
                            {
                                if (v28 <= v44)
                                    v29 = v13 - v4 + v24;
                                else
                                    v29 = v44 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v29;
                                *(_DWORD*)& byte_5D4594[3799540] = v4 - v13 + v21;
                                *(_DWORD*)& byte_5D4594[3799444] = &result[2 * (v4 - v13)];
                                (*(void (**)(void)) & byte_5D4594[3799536])();
                                goto LABEL_79;
                            }
                        }
                        else
                        {
                            v5 = v44;
                            if (v28 <= v44)
                            {
                                (*(void (**)(void)) & byte_5D4594[3799536])();
                                goto LABEL_79;
                            }
                        }
                        if (v13 < v5 && v28 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                            (*(void (**)(void)) & byte_5D4594[3799536])();
                        }
                        goto LABEL_79;
                    default:
                    LABEL_82:
                        v5 = v44;
                        goto LABEL_83;
                    }
                }
            }
            if (v39)
            {
                v14 = v5 - v4;
                v15 = (char*)(v4 + *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784] - 4));
                v16 = (char*)(v4 + *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]));
                if (v5 - v4 > a3)
                    v14 = a3;
                v17 = v14;
                v18 = v14 >> 2;
                qmemcpy(v16, v15, 4 * v18);
                v20 = &v15[4 * v18];
                v19 = &v16[4 * v18];
                LOBYTE(v18) = v17;
                v12 = a3;
                qmemcpy(v19, v20, v18 & 3);
                v11 = v40;
            }
            sub_4C6900(v12, 1);
            result = *(unsigned __int8**)& byte_5D4594[3799444];
        LABEL_85:
            v11 += 4;
            v36 = v42 == 1;
            ++v39;
            v40 = v11;
            --v42;
        } while (!v36);
    }
    return result;
}

//----- (004C6900) --------------------------------------------------------
char* __cdecl sub_4C6900(int a1, int a2)
{
    char* result; // eax
    int v3; // ebp
    int i; // esi
    char v5; // cl
    char* v6; // eax
    unsigned __int8 v7; // dl

    result = (char*)(a2 - 1);
    if (a2)
    {
        v3 = a2;
        result = *(char**)& byte_5D4594[3799444];
        do
        {
            for (i = a1; i > 0; i -= v7)
            {
                v5 = *result;
                v6 = result + 1;
                *(_DWORD*)& byte_5D4594[3799444] = v6;
                v7 = *v6;
                result = v6 + 1;
                *(_DWORD*)& byte_5D4594[3799444] = result;
                switch (v5 & 0xF)
                {
                case 2:
                case 4:
                    result += v7;
                    goto LABEL_7;
                case 5:
                case 6:
                case 7:
                    result += 2 * v7;
                LABEL_7:
                    *(_DWORD*)& byte_5D4594[3799444] = result;
                    break;
                default:
                    continue;
                }
            }
            --v3;
        } while (v3);
    }
    return result;
}

//----- (004C69A0) --------------------------------------------------------
void sub_4C69A0()
{
    _BYTE* v0; // esi
    _BYTE* v1; // edi
    unsigned __int8 v2; // dl
    int v3; // ecx
    int v4; // eax
    int v6; // edx
    int v7; // edx

    v0 = *(_BYTE * *)& byte_5D4594[3799444];
    v1 = *(_BYTE * *)& byte_5D4594[3799540];
    v2 = byte_5D4594[3799456];
    v3 = *(_DWORD*)& byte_5D4594[3799456] >> 2;
    if (*(_DWORD*)& byte_5D4594[3799456] >> 2)
    {
        do
        {
            v4 = *(_DWORD*)v0;
            v0 += 4;
            *(_DWORD*)v1 = v4;
            v1 += 4;
        } while (v3-- > 1);
    }
    v6 = v2 & 3;
    if (v6)
    {
        LOBYTE(v4) = *v0++;
        *v1++ = v4;
        v7 = v6 - 1;
        if (v7)
        {
            LOBYTE(v4) = *v0++;
            *v1++ = v4;
            if (v7 != 1)
            {
                LOBYTE(v4) = *v0++;
                *v1++ = v4;
            }
        }
    }
    *(_DWORD*)& byte_5D4594[3799444] = v0;
    *(_DWORD*)& byte_5D4594[3799540] = v1;
}

//----- (004C6A00) --------------------------------------------------------
void sub_4C6A00()
{
    int result; // eax
    __int16 v1; // si
    _BYTE* v2; // edi
    int v3; // eax
    unsigned __int8 v4; // cl
    int v5; // eax
    bool v6; // zf
    unsigned __int8 v7; // [esp+0h] [ebp-20h]
    int v8; // [esp+4h] [ebp-1Ch]
    unsigned __int8 v9; // [esp+14h] [ebp-Ch]
    unsigned __int8 v10; // [esp+1Ch] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[259]);
        v2 = *(_BYTE * *)& byte_5D4594[3799540];
        v8 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v7 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            v3 = 4 * v7;
            v4 = byte_5D4594[v3 + 3803308];
            v10 = byte_5D4594[v3 + 3803310];
            v9 = byte_5D4594[v3 + 3803309];
            v5 = 4 * (unsigned __int8)* v2;
            *v2 = *(_BYTE*)((((unsigned __int8)(byte_5D4594[v5 + 3803310]
                + ((unsigned __int16)(v1 * (v10 - byte_5D4594[v5 + 3803310])) >> 8)) >> 3) | (4 * ((byte_5D4594[v5 + 3803309] + ((unsigned __int16)(v1 * (v9 - byte_5D4594[v5 + 3803309])) >> 8)) & 0xF8 | (32 * ((byte_5D4594[v5 + 3803308] + ((unsigned __int16)(v1 * (v4 - byte_5D4594[v5 + 3803308])) >> 8)) & 0xF8)))))
                + *(_DWORD*)& byte_5D4594[810640]);
            v2 = (_BYTE*)(*(_DWORD*)& byte_5D4594[3799540] + 1);
            result = v8 - 1;
            v6 = v8 == 1;
            ++* (_DWORD*)& byte_5D4594[3799540];
            --v8;
        } while (!v6);
    }
}

//----- (004C6B50) --------------------------------------------------------
void sub_4C6B50()
{
    int v0; // ecx
    unsigned __int8* v1; // esi
    unsigned __int8* v2; // edi
    int v3; // ebx
    int v4; // eax
    int v5; // eax
    bool v7; // cc

    v0 = *(_DWORD*)& byte_5D4594[3799456];
    v1 = *(unsigned __int8**)& byte_5D4594[3799444];
    v2 = *(unsigned __int8**)& byte_5D4594[3799540];
    v3 = *(_DWORD*)& byte_5D4594[810632];
    if (*(_DWORD*)& byte_5D4594[810632])
    {
        do
        {
            v4 = *v1++ << 8;
            v5 = *v2++ + v4;
            *(v2 - 1) = *(_BYTE*)(v3 + v5);
            v7 = v0-- <= 1;
        } while (!v7);
        *(_DWORD*)& byte_5D4594[3799444] = v1;
        *(_DWORD*)& byte_5D4594[3799540] = v2;
    }
}

//----- (004C6BA0) --------------------------------------------------------
void sub_4C6BA0()
{
    int v0; // ecx
    unsigned __int8* v1; // esi
    _BYTE* v2; // edi
    int v3; // ebx
    int v4; // eax
    int result; // eax

    v0 = *(_DWORD*)& byte_5D4594[3799456];
    v1 = *(unsigned __int8**)& byte_5D4594[3799444];
    v2 = *(_BYTE * *)& byte_5D4594[3799540];
    v3 = (*(_DWORD*)& byte_5D4594[3801748] >> 3) + *(_DWORD*)& byte_5D4594[810636];
    do
    {
        v4 = *v1++;
        result = 32 * v4;
        *v2++ = *(_BYTE*)(v3 + result);
    } while (v0-- > 1);
    *(_DWORD*)& byte_5D4594[3799444] = v1;
    *(_DWORD*)& byte_5D4594[3799540] = v2;
}

//----- (004C6BF0) --------------------------------------------------------
void sub_4C6BF0()
{
    unsigned __int8* v0; // esi
    unsigned __int8* v1; // edi
    int v2; // ebx
    int v3; // ecx
    int v4; // eax
    unsigned __int8 result; // al
    int v7; // [esp+Ch] [ebp-4h]

    v0 = *(unsigned __int8**)& byte_5D4594[3799444];
    v1 = *(unsigned __int8**)& byte_5D4594[3799540];
    v7 = *(_DWORD*)& byte_5D4594[3799456];
    v2 = (*(_DWORD*)& byte_5D4594[3801748] >> 3) + *(_DWORD*)& byte_5D4594[810636];
    v3 = *(_DWORD*)& byte_5D4594[810632];
    do
    {
        v4 = (*(unsigned __int8*)(v2 + 32 * *v0++) << 8) + *v1;
        result = *(_BYTE*)(v3 + v4);
        *v1++ = result;
    } while (v7-- > 1);
    *(_DWORD*)& byte_5D4594[3799444] = v0;
    *(_DWORD*)& byte_5D4594[3799540] = v1;
}

//----- (004C6C60) --------------------------------------------------------
void sub_4C6C60()
{
    int result; // eax
    int v1; // ecx
    _BYTE* v2; // edi
    unsigned __int8 v3; // dl
    int v4; // eax
    unsigned __int8 v5; // cl
    int v6; // eax
    bool v7; // zf
    unsigned __int8 v8; // [esp+0h] [ebp-24h]
    unsigned __int8 v9; // [esp+4h] [ebp-20h]
    int v10; // [esp+4h] [ebp-20h]
    int v11; // [esp+8h] [ebp-1Ch]
    unsigned __int8 v12; // [esp+18h] [ebp-Ch]
    unsigned __int8 v13; // [esp+20h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    v9 = *(_DWORD*)& byte_5D4594[3801748] >> 3;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = v9;
        v8 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
        v2 = *(_BYTE * *)& byte_5D4594[3799540];
        v11 = v9;
        v10 = *(_DWORD*)& byte_5D4594[3799456];
        while (1)
        {
            v3 = *(_BYTE*)(v1 + 32 * (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444] + *(_DWORD*)& byte_5D4594[810636]);
            ++* (_DWORD*)& byte_5D4594[3799444];
            v4 = 4 * v3;
            v5 = byte_5D4594[v4 + 3803308];
            v13 = byte_5D4594[v4 + 3803310];
            v12 = byte_5D4594[v4 + 3803309];
            v6 = 4 * (unsigned __int8)* v2;
            *v2 = *(_BYTE*)((((unsigned __int8)(byte_5D4594[v6 + 3803310]
                + ((unsigned __int16)(v8 * (v13 - byte_5D4594[v6 + 3803310])) >> 8)) >> 3) | (4 * ((byte_5D4594[v6 + 3803309] + ((unsigned __int16)(v8 * (v12 - byte_5D4594[v6 + 3803309])) >> 8)) & 0xF8 | (32 * ((byte_5D4594[v6 + 3803308] + ((unsigned __int16)(v8 * (v5 - byte_5D4594[v6 + 3803308])) >> 8)) & 0xF8)))))
                + *(_DWORD*)& byte_5D4594[810640]);
            v2 = (_BYTE*)(*(_DWORD*)& byte_5D4594[3799540] + 1);
            result = v10 - 1;
            v7 = v10 == 1;
            ++* (_DWORD*)& byte_5D4594[3799540];
            --v10;
            if (v7)
                break;
            v1 = v11;
        }
    }
}

//----- (004C6DE0) --------------------------------------------------------
void sub_4C6DE0()
{
    int v0; // ecx
    _BYTE* v1; // esi
    _BYTE* v2; // edi
    int v3; // ebx
    int v4; // eax

    v0 = *(_DWORD*)& byte_5D4594[3799456];
    v1 = *(_BYTE * *)& byte_5D4594[3799444];
    v2 = *(_BYTE * *)& byte_5D4594[3799540];
    v3 = 32 * byte_5D4594[48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + 3801020] + *(_DWORD*)& byte_5D4594[810636];
    v4 = 0;
    do
    {
        LOBYTE(v4) = *v1++;
        *v2++ = *(_BYTE*)(v3 + v4);
    } while (v0-- > 1);
    *(_DWORD*)& byte_5D4594[3799444] = v1;
    *(_DWORD*)& byte_5D4594[3799540] = v2;
}

//----- (004C6E40) --------------------------------------------------------
void sub_4C6E40()
{
    int result; // eax
    int v1; // ecx
    _BYTE* v2; // edi
    unsigned __int8 v3; // dl
    int v4; // eax
    unsigned __int8 v5; // cl
    int v6; // eax
    bool v7; // zf
    unsigned __int8 v8; // [esp+0h] [ebp-24h]
    unsigned __int8 v9; // [esp+4h] [ebp-20h]
    int v10; // [esp+4h] [ebp-20h]
    int v11; // [esp+8h] [ebp-1Ch]
    unsigned __int8 v12; // [esp+18h] [ebp-Ch]
    unsigned __int8 v13; // [esp+20h] [ebp-4h]

    result = ptr_5D4594_3799572;
    LOBYTE(result) = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
    v9 = *(_BYTE*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[76]));
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = 32 * v9;
        v8 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
        v2 = *(_BYTE * *)& byte_5D4594[3799540];
        v11 = 32 * v9;
        v10 = *(_DWORD*)& byte_5D4594[3799456];
        while (1)
        {
            v3 = *(_BYTE*)(v1 + (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444] + *(_DWORD*)& byte_5D4594[810636]);
            ++* (_DWORD*)& byte_5D4594[3799444];
            v4 = 4 * v3;
            v5 = byte_5D4594[v4 + 3803308];
            v13 = byte_5D4594[v4 + 3803310];
            v12 = byte_5D4594[v4 + 3803309];
            v6 = 4 * (unsigned __int8)* v2;
            *v2 = *(_BYTE*)((((unsigned __int8)(byte_5D4594[v6 + 3803310]
                + ((unsigned __int16)(v8 * (v13 - byte_5D4594[v6 + 3803310])) >> 8)) >> 3) | (4 * ((byte_5D4594[v6 + 3803309] + ((unsigned __int16)(v8 * (v12 - byte_5D4594[v6 + 3803309])) >> 8)) & 0xF8 | (32 * ((byte_5D4594[v6 + 3803308] + ((unsigned __int16)(v8 * (v5 - byte_5D4594[v6 + 3803308])) >> 8)) & 0xF8)))))
                + *(_DWORD*)& byte_5D4594[810640]);
            v2 = (_BYTE*)(*(_DWORD*)& byte_5D4594[3799540] + 1);
            result = v10 - 1;
            v7 = v10 == 1;
            ++* (_DWORD*)& byte_5D4594[3799540];
            --v10;
            if (v7)
                break;
            v1 = v11;
        }
    }
}

//----- (004C6FD0) --------------------------------------------------------
void sub_4C6FD0()
{
    _BYTE* result; // eax
    int v1; // esi
    unsigned __int8 v2; // [esp+0h] [ebp-4h]

    result = (_BYTE*)(*(_DWORD*)& byte_5D4594[3799456] - 1);
    v2 = *(_BYTE*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[76]));
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(_DWORD*)& byte_5D4594[3799456];
        result = *(_BYTE * *)& byte_5D4594[3799540];
        do
        {
            *result = *(_BYTE*)(((unsigned __int8)* result << 8)
                + *(unsigned __int8*)(32 * v2
                    + (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444]
                    + *(_DWORD*)& byte_5D4594[810636])
                + *(_DWORD*)& byte_5D4594[810632]);
            result = (_BYTE*)(*(_DWORD*)& byte_5D4594[3799540] + 1);
            --v1;
            ++* (_DWORD*)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799540];
        } while (v1);
    }
}

//----- (004C7060) --------------------------------------------------------
void sub_4C7060()
{
    int result; // eax
    int v1; // edi
    int v2; // ebp
    unsigned __int8 v3; // dl

    result = *(_DWORD*)& byte_5D4594[3799428] >> 4;
    LOBYTE(result) = *(_BYTE*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[76]));
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        result = 32
            * *(unsigned __int8*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[76]));
        v1 = (unsigned __int8)(*(_DWORD*)& byte_5D4594[3801748] >> 3);
        v2 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v3 = *(_BYTE*)(result + (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444] + *(_DWORD*)& byte_5D4594[810636]);
            ++* (_DWORD*)& byte_5D4594[3799444];
            **(_BYTE * *)& byte_5D4594[3799540] = *(_BYTE*)(v1 + 32 * v3 + *(_DWORD*)& byte_5D4594[810636]);
            --v2;
            ++* (_DWORD*)& byte_5D4594[3799540];
        } while (v2);
    }
}

//----- (004C7110) --------------------------------------------------------
unsigned int sub_4C7110()
{
    unsigned int result; // eax
    _BYTE* v1; // edi
    int v2; // ecx
    unsigned __int8 v3; // bl
    unsigned __int8 v4; // [esp+0h] [ebp-18h]
    unsigned int v5; // [esp+4h] [ebp-14h]
    unsigned __int8 v6; // [esp+Ch] [ebp-Ch]
    unsigned __int8 v7; // [esp+10h] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        HIWORD(result) = *(_WORD*)& byte_5D4594[3799458];
        v1 = *(_BYTE * *)& byte_5D4594[3799540];
        v5 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            LOWORD(result) = **(_WORD * *)& byte_5D4594[3799444];
            v2 = 4 * (unsigned __int8)* v1;
            v6 = 16 * **(_WORD * *)& byte_5D4594[3799444];
            v3 = byte_5D4594[v2 + 3803309];
            v7 = byte_5D4594[v2 + 3803308];
            v4 = byte_5D4594[v2 + 3803310];
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            *v1 = *(_BYTE*)((((unsigned __int8)(v4 + ((unsigned __int16)(v6 * ((result & 0xF0) - v4)) >> 8)) >> 3) | (unsigned __int16)(4 * ((v3 + ((unsigned __int16)(v6 * (((result >> 4) & 0xF0) - v3)) >> 8)) & 0xF8 | (32 * ((v7 + ((unsigned __int16)(v6 * ((BYTE1(result) & 0xF0) - v7)) >> 8)) & 0xF8)))))
                + *(_DWORD*)& byte_5D4594[810640]);
            v1 = (_BYTE*)(*(_DWORD*)& byte_5D4594[3799540] + 1);
            result = v5 - 1;
            ++* (_DWORD*)& byte_5D4594[3799540];
            v5 = result;
        } while (result);
    }
    return result;
}

//----- (004C7240) --------------------------------------------------------
unsigned int sub_4C7240()
{
    unsigned int result; // eax
    int v1; // ecx
    unsigned __int8* v2; // edi
    int v3; // edx
    unsigned __int8 v4; // cl
    int v5; // ecx
    unsigned __int8 v6; // [esp+4h] [ebp-18h]
    unsigned int v7; // [esp+4h] [ebp-18h]
    int v8; // [esp+8h] [ebp-14h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    v6 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = v6;
        HIWORD(result) = *(_WORD*)& byte_5D4594[3799458];
        v2 = *(unsigned __int8**)& byte_5D4594[3799540];
        v8 = v6;
        v7 = *(_DWORD*)& byte_5D4594[3799456];
        while (1)
        {
            LOWORD(result) = **(_WORD * *)& byte_5D4594[3799444];
            v3 = v1 * 16 * (**(_WORD * *)& byte_5D4594[3799444] & 0xF);
            v4 = *v2;
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            v5 = 4 * v4;
            *v2 = *(_BYTE*)((((unsigned __int8)(byte_5D4594[v5 + 3803310]
                + ((unsigned __int16)(BYTE1(v3) * ((result & 0xF0) - byte_5D4594[v5 + 3803310])) >> 8)) >> 3) | (unsigned __int16)(4 * ((byte_5D4594[v5 + 3803309] + ((unsigned __int16)(BYTE1(v3) * (((result >> 4) & 0xF0) - byte_5D4594[v5 + 3803309])) >> 8)) & 0xF8 | (32 * ((byte_5D4594[v5 + 3803308] + ((unsigned __int16)(BYTE1(v3) * ((BYTE1(result) & 0xF0) - byte_5D4594[v5 + 3803308])) >> 8)) & 0xF8)))))
                + *(_DWORD*)& byte_5D4594[810640]);
            v2 = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[3799540] + 1);
            result = v7 - 1;
            ++* (_DWORD*)& byte_5D4594[3799540];
            v7 = result;
            if (!result)
                break;
            v1 = v8;
        }
    }
    return result;
}

//----- (004C73A0) --------------------------------------------------------
unsigned __int8 sub_4C73A0()
{
    __int16* v0; // esi
    unsigned __int8* v1; // edi
    unsigned __int8* v2; // edx
    __int16 v3; // cx
    int v4; // eax
    unsigned __int8 result; // al
    int v7; // [esp+Ch] [ebp-4h]

    v0 = *(__int16**)& byte_5D4594[3799444];
    v1 = *(unsigned __int8**)& byte_5D4594[3799540];
    v7 = *(_DWORD*)& byte_5D4594[3799456];
    do
    {
        v2 = &byte_5D4594[4 * *v1 + 3803308];
        v3 = *v0;
        v4 = (unsigned __int16)(*v0 & 0x7C00) >> 7;
        ++v0;
        //result = *(_BYTE *)(*(_DWORD *)&byte_5D4594[810640]
        //                  + (((unsigned __int8)(__CFADD__(v2[2], 8 * (v3 & 0x1F)) ? -1 : (unsigned __int8)(byte_5D4594[4 * *v1 + 3803310] + 8 * (v3 & 0x1F))) >> 3) | (4 * (((unsigned __int8)-__CFADD__(v2[1], (unsigned __int16)(v3 & 0x3E0) >> 2) | (unsigned __int8)(v2[1] + ((unsigned __int16)(v3 & 0x3E0) >> 2))) & 0xF8)) | ((((unsigned __int8)-__CFADD__(*v2, (_BYTE)v4) | (unsigned __int8)(*v2 + v4)) & 0xF8) << 7)));
        result = *(_BYTE*)(*(_DWORD*)& byte_5D4594[810640] + (SADD8(v2[2], 8 * (v3 & 0x1F)) >> 3) | (4 * (SADD8(v2[1], (unsigned __int16)(v3 & 0x3E0) >> 2) & 0xF8) | (SADD8(*v2, (_BYTE)v4) & 0xF8) << 7));
        *v1++ = result;
    } while (v7-- > 1);
    *(_DWORD*)& byte_5D4594[3799444] = v0;
    *(_DWORD*)& byte_5D4594[3799540] = v1;
    return result;
}

//----- (004C7440) --------------------------------------------------------
void __cdecl sub_4C7440(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // eax
    int v5; // ecx
#if 0
    if (*(_BYTE*)(a1 + 10) != 8)
    {
        dprintf("%x %x %x", a1, a2, a3);
        dprintf("\t%d", *(_BYTE*)(a1 + 10));
    }
#endif
    if (a1)
    {
        switch (*(_BYTE*)(a1 + 10) & 0x3F)
        {
        case 2:
        case 7:
            *(_DWORD*)& byte_5D4594[3799536] = sub_4C80E0;
            sub_4C7860(a1, a2, a3);
            return;
        case 3:
        case 4:
        case 5:
        case 6:
            *(_DWORD*)& byte_5D4594[3799544] = sub_4C96A0;
            *(_DWORD*)& byte_5D4594[3799488] = nullsub_7;
            if (!ptr_5D4594_3799572->data[13])
            {
                if (ptr_5D4594_3799572->data[14])
                {
                    *(_DWORD*)& byte_5D4594[3799544] = sub_4C9970;
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C86B0;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C91C0;
                    sub_4C79F0(a1, a2, a3);
                    return;
                }
                v5 = ptr_5D4594_3799572->data[17];
                *(_DWORD*)& byte_5D4594[3799536] = sub_4C8D60;
                if (v5)
                    goto LABEL_23;
                goto LABEL_22;
            }
            *(_DWORD*)& byte_5D4594[3799544] = sub_4C97F0;
            if (ptr_5D4594_3799572->data[14])
            {
                v3 = ptr_5D4594_3799572->data[259];
                if (v3 == 255)
                {
                    if (!ptr_5D4594_3799572->data[16])
                    {
                        *(_DWORD*)& byte_5D4594[3799536] = sub_4C86B0;
                        *(_DWORD*)& byte_5D4594[3799432] = sub_4C91C0;
                        sub_4C79F0(a1, a2, a3);
                        return;
                    }
                    goto LABEL_22;
                }
                if (v3 == 128)
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8A30;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C94D0;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8850;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C92F0;
                }
                sub_4C79F0(a1, a2, a3);
            }
            else
            {
                v4 = ptr_5D4594_3799572->data[259];
                if (v4 == 255)
                {
                LABEL_22:
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C80E0;
                LABEL_23:
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C8DF0;
                    sub_4C79F0(a1, a2, a3);
                    return;
                }
                if (v4 == 128)
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8410;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C9050;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8130;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C8EC0;
                }
                sub_4C79F0(a1, a2, a3);
            }
            break;
        case 8:
            *(_DWORD*)& byte_5D4594[3799536] = sub_4C9B20;
            sub_4C79F0(a1, a2, a3);
            return;
        default:
            return;
        }
    }
}
// 47D640: using guessed type void nullsub_7();
#if 1
//----- (004C7670) --------------------------------------------------------
void __cdecl sub_4C7670(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // ecx
    int v5; // eax
    int v6; // ecx

    v3 = 0;
    if (a1)
    {
        switch (*(_BYTE*)(a1 + 10) & 0x3F)
        {
        case 2:
        case 7:
            *(_DWORD*)& byte_5D4594[3799536] = sub_4C80E0;
            sub_4C7860(a1, a2, a3);
            return;
        case 3:
        case 4:
        case 5:
        case 6:
            *(_DWORD*)& byte_5D4594[3799544] = sub_4C96A0;
            *(_DWORD*)& byte_5D4594[3799488] = nullsub_7;
            if (!ptr_5D4594_3799572->data[13])
            {
                if (ptr_5D4594_3799572->data[14])
                {
                    *(_DWORD*)& byte_5D4594[3799544] = sub_4C9970;
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8760;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C91C0;
                    v3 = 1;
                    goto LABEL_23;
                }
                v6 = ptr_5D4594_3799572->data[17];
                *(_DWORD*)& byte_5D4594[3799536] = sub_4C8D60;
                if (v6)
                    goto LABEL_22;
                goto LABEL_21;
            }
            *(_DWORD*)& byte_5D4594[3799544] = sub_4C97F0;
            if (ptr_5D4594_3799572->data[14])
            {
                v4 = ptr_5D4594_3799572->data[259];
                if (v4 == 255)
                {
                    if (!ptr_5D4594_3799572->data[16])
                    {
                        *(_DWORD*)& byte_5D4594[3799536] = sub_4C8760;
                        *(_DWORD*)& byte_5D4594[3799432] = sub_4C91C0;
                        v3 = 1;
                        goto LABEL_23;
                    }
                    goto LABEL_21;
                }
                if (v4 == 128)
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8C00;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C94D0;
                    v3 = 1;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8850;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C92F0;
                }
            }
            else
            {
                v5 = ptr_5D4594_3799572->data[259];
                if (v5 == 255)
                {
                LABEL_21:
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C80E0;
                LABEL_22:
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C8DF0;
                    goto LABEL_23;
                }
                if (v5 == 128)
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C8570;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C9050;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[3799536] = sub_4C82C0;
                    *(_DWORD*)& byte_5D4594[3799432] = sub_4C8EC0;
                }
                v3 = 1;
            }
        LABEL_23:
            sub_4C79F0(a1, a2, a3);
#if 0
            if (v3)
                _m_femms();
#endif
            break;
        case 8:
            *(_DWORD*)& byte_5D4594[3799536] = sub_4C9B20;
            sub_4C79F0(a1, a2, a3);
            return;
        default:
            return;
        }
    }
}
// 47D640: using guessed type void nullsub_7();
#endif
//----- (004C7860) --------------------------------------------------------
void __cdecl sub_4C7860(int a1, int a2, int a3)
{
    int4* result; // eax
    int v4; // esi
    int* v5; // eax
    int4* v6; // ecx
    int v7; // edx
    int v8; // edi
    int v9; // ebx
    int v10; // ebp
    int v11; // eax
    int v12; // edi
    int v13; // ebx
    int v14; // esi
    int v15; // ecx
    int v16; // ebp
    int v17; // edi
    int4 a1a; // [esp+10h] [ebp-20h]
    RECT rc; // [esp+20h] [ebp-10h]
    int v20; // [esp+3Ch] [ebp+Ch]

    result = (int4*)(*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3799492])(a1);
    *(_DWORD*)& byte_5D4594[3799444] = result;
    if (result)
    {
        v4 = result->field_0;
        v5 = &result->field_4;
        *(_DWORD*)& byte_5D4594[3799444] = v5;
        v6 = (int4*)* v5;
        ++v5;
        v7 = v4;
        *(_DWORD*)& byte_5D4594[3799444] = v5;
        v8 = *v5;
        ++v5;
        *(_DWORD*)& byte_5D4594[3799560] = v8;
        v9 = v8 + a2;
        *(_DWORD*)& byte_5D4594[3799444] = v5;
        *(_DWORD*)& byte_5D4594[3799556] = *v5;
        v10 = *(_DWORD*)& byte_5D4594[3799556] + a3;
        result = (int4*)(v5 + 1);
        v20 = *(_DWORD*)& byte_5D4594[3799556] + a3;
        *(_DWORD*)& byte_5D4594[3799444] = result;
        if (*(_DWORD*)& byte_5D4594[3799484])
        {
            v6 = (int4*)((char*)v6 - *(_DWORD*)& byte_5D4594[3799484]);
            if ((int)v6 <= 0)
                return;
            *(_DWORD*)& byte_5D4594[3799476] = (char*)v6 + v10;
        }
        *(_DWORD*)& byte_5D4594[3799520] = v8 + a2;
        *(_DWORD*)& byte_5D4594[3799444] = (char*)result + 1;
        *(_DWORD*)& byte_5D4594[3799512] = v10;
        *(_DWORD*)& byte_5D4594[3799516] = v4;
        *(_DWORD*)& byte_5D4594[3799504] = v6;
        if (ptr_5D4594_3799572->data[0])
        {
            SetRect(&rc, v9, v10, v4 + v9, (int)v6 + v10);
            result = sub_49F930(&a1a, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
            if (!result)
                return;
            v11 = a1a.field_0 - rc.left;
            v12 = a1a.field_4 - rc.top;
            v7 = a1a.field_8 - a1a.field_0;
            v6 = (int4*)(a1a.field_C - a1a.field_4);
            if (a1a.field_0 != rc.left || v12)
            {
                v9 += v11;
                *(_DWORD*)& byte_5D4594[3799444] += v4 * v12 + 2 * v11;
                v10 = v12 + v20;
            }
            else
            {
                v10 = v20;
            }
        }
        v13 = 2 * v9;
        v14 = 2 * (v4 - v7);
        result = v6;
        v15 = (int)& v6[-1].field_C + 3;
        *(_DWORD*)& byte_5D4594[3799456] = v7;
        if (result)
        {
            v16 = 4 * v10;
            v17 = v15 + 1;
            do
            {
                v16 += 4;
                *(_DWORD*)& byte_5D4594[3799540] = v13 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v16 - 4);
                (*(void (**)(void)) & byte_5D4594[3799536])();
                --v17;
                *(_DWORD*)& byte_5D4594[3799444] += v14;
            } while (v17);
        }
    }
}

//----- (004C79F0) --------------------------------------------------------
int __cdecl sub_4C79F0(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // ebp
    int v5; // esi
    int* v6; // ecx
    int v7; // eax
    int v8; // ebx
    int v9; // eax
    int v10; // edi
    int v11; // ecx
    int v12; // ecx
    int v13; // esi
    int v14; // eax
    int v15; // ebx
    int v16; // esi
    char* v17; // edx
    int v18; // ecx
    bool v19; // zf
    RECT rc; // [esp+10h] [ebp-20h]
    int4 a1a; // [esp+20h] [ebp-10h]
    int v22; // [esp+34h] [ebp+4h]
    int v23; // [esp+38h] [ebp+8h]
    int v24; // [esp+3Ch] [ebp+Ch]

    result = (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3799492])(a1);
    *(_DWORD*)& byte_5D4594[3799444] = result;
    if (result)
    {
        v4 = *(_DWORD*)result;
        *(_DWORD*)& byte_5D4594[3799444] = result + 4;
        v5 = *(_DWORD*)(result + 4);
        v6 = (int*)(result + 8);
        *(_DWORD*)& byte_5D4594[3799444] = v6;
        v7 = *(_DWORD*)(result + 8);
        ++v6;
        *(_DWORD*)& byte_5D4594[3799560] = v7;
        v8 = v7 + a2;
        *(_DWORD*)& byte_5D4594[3799444] = v6;
        v9 = *v6;
        *(_DWORD*)& byte_5D4594[3799556] = v9;
        v10 = v9 + a3;
        result = *(_DWORD*)& byte_5D4594[3799484];
        v11 = (int)(v6 + 1);
        *(_DWORD*)& byte_5D4594[3799444] = v11;
        if (*(_DWORD*)& byte_5D4594[3799484])
        {
            v5 -= *(_DWORD*)& byte_5D4594[3799484];
            if (v5 <= 0)
                return result;
            *(_DWORD*)& byte_5D4594[3799476] = v5 + v10;
        }
        *(_DWORD*)& byte_5D4594[3799444] = v11 + 1;
        *(_DWORD*)& byte_5D4594[3799520] = v8;
        *(_DWORD*)& byte_5D4594[3799512] = v10;
        *(_DWORD*)& byte_5D4594[3799516] = v4;
        *(_DWORD*)& byte_5D4594[3799504] = v5;
        if (!ptr_5D4594_3799572->data[0])
            goto LABEL_33;
        SetRect(&rc, v8, v10, v8 + v4, v5 + v10);
        result = sub_49F930(&a1a, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
        if (!result)
            return result;
        if (rc.left != a1a.field_0 || rc.right != a1a.field_8 || rc.top != a1a.field_4 || rc.bottom != a1a.field_C)
        {
            result = sub_4C7C80(v8, v10, v4, &a1a.field_0);
        }
        else
        {
        LABEL_33:
            result = v10 & 1;
            v22 = 0;
            *(_DWORD*)& byte_5D4594[3799508] ^= result;
            v12 = v5;
            v13 = v5 - 1;
            if (v12)
            {
                v14 = 2 * v8;
                v24 = 2 * v8;
                v15 = 4 * v10;
                v23 = v13 + 1;
                while (1)
                {
                    v16 = v4;
                    v17 = (char*)(v14 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784]));
                    *(_DWORD*)& byte_5D4594[3799540] = v14 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784]);
                    if (*(_DWORD*)& byte_5D4594[3799552] && (*(_DWORD*)& byte_5D4594[3799508] ^= 1u) != 0)
                    {
                        if (v22)
                            qmemcpy(v17, (const void*)(v14 + *(_DWORD*)(v15 + *(_DWORD*)& byte_5D4594[3798784] - 4)), 2 * v4);
                        sub_4C8040(v4, 1);
                    }
                    else if (v4 > 0)
                    {
                        while (1)
                        {
                            *(_DWORD*)& byte_5D4594[3799428] = (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444];
                            ++* (_DWORD*)& byte_5D4594[3799444];
                            v18 = (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444];
                            *(_DWORD*)& byte_5D4594[3799456] = (unsigned __int8) * *(_BYTE * *)& byte_5D4594[3799444];
                            ++* (_DWORD*)& byte_5D4594[3799444];
                            switch (byte_5D4594[3799428] & 0xF)
                            {
                            case 1:
                                *(_DWORD*)& byte_5D4594[3799540] = &v17[2 * v18];
                                break;
                            case 2:
                            case 7:
                                (*(void (**)(void)) & byte_5D4594[3799536])();
                                break;
                            case 4:
                                (*(void (**)(void)) & byte_5D4594[3799432])();
                                break;
                            case 5:
                                (*(void (**)(void)) & byte_5D4594[3799544])();
                                break;
                            case 6:
                                (*(void (**)(void)) & byte_5D4594[3799488])();
                                break;
                            default:
                                break;
                            }
                            v16 -= *(_DWORD*)& byte_5D4594[3799456];
                            if (v16 <= 0)
                                break;
                            v17 = *(char**)& byte_5D4594[3799540];
                        }
                    }
                    v15 += 4;
                    result = v23 - 1;
                    v19 = v23 == 1;
                    ++v22;
                    --v23;
                    if (v19)
                        break;
                    v14 = v24;
                }
            }
        }
    }
    return result;
}

//----- (004C7C80) --------------------------------------------------------
unsigned __int8* __cdecl sub_4C7C80(int a1, int a2, int a3, int* a4)
{
    int v4; // ebp
    int v5; // ebx
    unsigned __int8* result; // eax
    int v7; // edi
    int v8; // ecx
    unsigned __int8* v9; // esi
    int v10; // esi
    int v11; // edi
    int v12; // edx
    int v13; // esi
    char* v14; // esi
    char* v15; // eax
    int v16; // ecx
    unsigned int v17; // ecx
    char v18; // dl
    char* v19; // edi
    char* v20; // esi
    int v21; // edx
    int v22; // ecx
    unsigned __int8* v23; // eax
    int v24; // ecx
    int v25; // edi
    int v26; // ecx
    int v27; // ecx
    int v28; // edi
    int v29; // ecx
    int v30; // ecx
    int v31; // edi
    int v32; // ecx
    int v33; // ecx
    int v34; // edi
    int v35; // ecx
    int v36; // ecx
    bool v37; // zf
    unsigned __int8* v38; // [esp+10h] [ebp-18h]
    int v39; // [esp+14h] [ebp-14h]
    int v40; // [esp+18h] [ebp-10h]
    int v41; // [esp+1Ch] [ebp-Ch]
    int v42; // [esp+20h] [ebp-8h]
    int v43; // [esp+24h] [ebp-4h]
    int v44; // [esp+30h] [ebp+8h]
    int v45; // [esp+38h] [ebp+10h]

    v4 = *a4;
    v5 = a4[2];
    result = *(unsigned __int8**)& byte_5D4594[3799484];
    v7 = a2;
    v8 = a4[1] - a2;
    v9 = (unsigned __int8*)(a4[3] - a4[1]);
    v45 = a4[2];
    if (*(_DWORD*)& byte_5D4594[3799484])
    {
        v9 -= *(_DWORD*)& byte_5D4594[3799484];
        if ((int)v9 <= 0)
            return result;
        *(_DWORD*)& byte_5D4594[3799476] = &v9[a2];
    }
    if (v8)
    {
        v7 = v8 + a2;
        sub_4C8040(a3, v8);
    }
    v40 = 0;
    *(_DWORD*)& byte_5D4594[3799508] ^= v7 & 1;
    result = v9;
    v10 = (int)(v9 - 1);
    if (result)
    {
        result = *(unsigned __int8**)& byte_5D4594[3799444];
        v11 = 4 * v7;
        v41 = v11;
        v43 = v10 + 1;
        do
        {
            v12 = a3;
            v13 = a1;
            v42 = a3;
            if (!*(_DWORD*)& byte_5D4594[3799552] || (*(_DWORD*)& byte_5D4594[3799508] ^= 1u) == 0)
            {
                v21 = *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]) + 2 * a1;
                *(_DWORD*)& byte_5D4594[3799540] = *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]) + 2 * a1;
                if (a3 <= 0)
                    goto LABEL_72;
                while (1)
                {
                    v39 = v21;
                    v22 = *result;
                    v23 = result + 1;
                    *(_DWORD*)& byte_5D4594[3799428] = v22;
                    *(_DWORD*)& byte_5D4594[3799444] = v23;
                    v24 = *v23;
                    result = v23 + 1;
                    *(_DWORD*)& byte_5D4594[3799456] = v24;
                    *(_DWORD*)& byte_5D4594[3799444] = result;
                    v38 = result;
                    v44 = v24;
                    switch (byte_5D4594[3799428] & 0xF)
                    {
                    case 1:
                        v21 += 2 * v24;
                        *(_DWORD*)& byte_5D4594[3799540] = v21;
                        goto LABEL_69;
                    case 2:
                    case 7:
                        v25 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v45;
                            if (v25 > v4)
                            {
                                if (v25 <= v45)
                                    v26 = v13 - v4 + v24;
                                else
                                    v26 = v45 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v26;
                                v27 = 2 * (v4 - v13);
                                *(_DWORD*)& byte_5D4594[3799444] = &result[v27];
                                *(_DWORD*)& byte_5D4594[3799540] = v27 + v21;
                                (*(void (**)(void)) & byte_5D4594[3799536])();
                                goto LABEL_66;
                            }
                        }
                        else
                        {
                            v5 = v45;
                            if (v25 <= v45)
                            {
                                (*(void (**)(void)) & byte_5D4594[3799536])();
                                goto LABEL_66;
                            }
                        }
                        if (v13 < v5 && v25 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                            (*(void (**)(void)) & byte_5D4594[3799536])();
                        }
                        goto LABEL_66;
                    case 4:
                        v28 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v45;
                            if (v28 > v4)
                            {
                                if (v28 <= v45)
                                    v29 = v13 - v4 + v24;
                                else
                                    v29 = v45 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v29;
                                *(_DWORD*)& byte_5D4594[3799444] = &result[v4 - v13];
                                *(_DWORD*)& byte_5D4594[3799540] = v21 + 2 * (v4 - v13);
                                goto LABEL_39;
                            }
                        }
                        else
                        {
                            v5 = v45;
                            if (v28 <= v45)
                                goto LABEL_39;
                        }
                        if (v13 < v5 && v28 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_39:
                            (*(void (**)(void)) & byte_5D4594[3799432])();
                        }
                        v30 = v44;
                        result = &v38[v44];
                    LABEL_67:
                        *(_DWORD*)& byte_5D4594[3799444] = result;
                        v21 = v39 + 2 * v30;
                        *(_DWORD*)& byte_5D4594[3799540] = v39 + 2 * v30;
                    LABEL_70:
                        v13 += v44;
                        v42 -= v44;
                        if (v42 <= 0)
                        {
                            v11 = v41;
                            goto LABEL_72;
                        }
                        break;
                    case 5:
                        v31 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v45;
                            if (v31 > v4)
                            {
                                if (v31 <= v45)
                                    v32 = v13 - v4 + v24;
                                else
                                    v32 = v45 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v32;
                                v33 = 2 * (v4 - v13);
                                *(_DWORD*)& byte_5D4594[3799444] = &result[v33];
                                *(_DWORD*)& byte_5D4594[3799540] = v33 + v21;
                                goto LABEL_52;
                            }
                        }
                        else
                        {
                            v5 = v45;
                            if (v31 <= v45)
                                goto LABEL_52;
                        }
                        if (v13 < v5 && v31 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_52:
                            (*(void (**)(void)) & byte_5D4594[3799544])();
                        }
                        result = &v38[2 * v44];
                        v21 = v39 + 2 * v44;
                        *(_DWORD*)& byte_5D4594[3799444] = &v38[2 * v44];
                        *(_DWORD*)& byte_5D4594[3799540] = v39 + 2 * v44;
                        goto LABEL_70;
                    case 6:
                        v34 = v24 + v13;
                        if (v13 < v4)
                        {
                            v5 = v45;
                            if (v34 > v4)
                            {
                                if (v34 <= v45)
                                    v35 = v13 - v4 + v24;
                                else
                                    v35 = v45 - v4;
                                *(_DWORD*)& byte_5D4594[3799456] = v35;
                                v36 = 2 * (v4 - v13);
                                *(_DWORD*)& byte_5D4594[3799444] = &result[v36];
                                *(_DWORD*)& byte_5D4594[3799540] = v36 + v21;
                                goto LABEL_65;
                            }
                        }
                        else
                        {
                            v5 = v45;
                            if (v34 <= v45)
                                goto LABEL_65;
                        }
                        if (v13 < v5 && v34 > v5)
                        {
                            *(_DWORD*)& byte_5D4594[3799456] = v5 - v13;
                        LABEL_65:
                            (*(void (**)(void)) & byte_5D4594[3799488])();
                        }
                    LABEL_66:
                        v30 = v44;
                        result = &v38[2 * v44];
                        goto LABEL_67;
                    default:
                    LABEL_69:
                        v5 = v45;
                        goto LABEL_70;
                    }
                }
            }
            if (v40)
            {
                v14 = (char*)(2 * v4 + *(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784] - 4));
                v15 = (char*)(*(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[3798784]) + 2 * v4);
                v16 = v5 - v4;
                if (v5 - v4 > a3)
                    v16 = a3;
                v17 = 2 * v16;
                v18 = v17;
                v17 >>= 2;
                qmemcpy(v15, v14, 4 * v17);
                v20 = &v14[4 * v17];
                v19 = &v15[4 * v17];
                LOBYTE(v17) = v18;
                v12 = a3;
                qmemcpy(v19, v20, v17 & 3);
                v11 = v41;
            }
            sub_4C8040(v12, 1);
            result = *(unsigned __int8**)& byte_5D4594[3799444];
        LABEL_72:
            v11 += 4;
            v37 = v43 == 1;
            ++v40;
            v41 = v11;
            --v43;
        } while (!v37);
    }
    return result;
}

//----- (004C8040) --------------------------------------------------------
char* __cdecl sub_4C8040(int a1, int a2)
{
    char* result; // eax
    int v3; // ebp
    int i; // esi
    char v5; // cl
    char* v6; // eax
    unsigned __int8 v7; // dl

    result = (char*)(a2 - 1);
    if (a2)
    {
        v3 = a2;
        result = *(char**)& byte_5D4594[3799444];
        do
        {
            for (i = a1; i > 0; i -= v7)
            {
                v5 = *result;
                v6 = result + 1;
                *(_DWORD*)& byte_5D4594[3799444] = v6;
                v7 = *v6;
                result = v6 + 1;
                *(_DWORD*)& byte_5D4594[3799444] = result;
                switch (v5 & 0xF)
                {
                case 2:
                case 5:
                case 6:
                case 7:
                    result += 2 * v7;
                    goto LABEL_7;
                case 4:
                    result += v7;
                LABEL_7:
                    *(_DWORD*)& byte_5D4594[3799444] = result;
                    break;
                default:
                    continue;
                }
            }
            --v3;
        } while (v3);
    }
    return result;
}

//----- (004C80E0) --------------------------------------------------------
void sub_4C80E0()
{
    memcpy(*(WORD * *)& byte_5D4594[3799540], *(WORD * *)& byte_5D4594[3799444], *(_DWORD*)& byte_5D4594[3799456] << 1);
    *(_DWORD*)& byte_5D4594[3799444] += *(_DWORD*)& byte_5D4594[3799456] << 1;
    *(_DWORD*)& byte_5D4594[3799540] += *(_DWORD*)& byte_5D4594[3799456] << 1;
}

//----- (004C8130) --------------------------------------------------------
void sub_4C8130()
{
    int result; // eax
    __int16 v1; // si
    _WORD* v2; // edi
    int v3; // [esp+0h] [ebp-1Ch]
    unsigned __int8 v4; // [esp+Ch] [ebp-10h]
    unsigned __int8 v5; // [esp+14h] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[259]);
        v2 = *(_WORD * *)& byte_5D4594[3799540];
        v3 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v5 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v2) >> byte_5D4594[3804376];
            v4 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v2) >> byte_5D4594[3804380];
            *v2 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(v5
                    + ((unsigned __int16)(v1
                        * ((unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & **(_WORD * *)& byte_5D4594[3799444]) >> byte_5D4594[3804376])
                            - v5)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656]
                                + 2
                                * (unsigned __int8)(v4 + ((unsigned __int16)(v1 * ((unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & **(_WORD * *)& byte_5D4594[3799444]) >> byte_5D4594[3804380]) - v4)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((unsigned __int16)(v1 * ((unsigned __int8)(((unsigned __int8) * *(_WORD * *)& byte_5D4594[3799444] & byte_5D4594[3804372]) << byte_5D4594[3804384]) - (unsigned __int8)((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384]))) >> 8)));
            v2 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v3 - 1;
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v3 = result;
        } while (result);
    }
}

__int16 sub_4C82C0()
{
    DebugBreak();
    return 0;
}

#if 0
//----- (004C82C0) --------------------------------------------------------
__int16 sub_4C82C0()
{
    int v0; // ecx
    __m64* v1; // esi
    __m64* v2; // edi
    __m64 v3; // mm7
    __m64 v4; // mm0
    __m64 v5; // mm1
    __m64 v6; // mm2
    __m64 v7; // mm0
    bool v8; // cc
    __int16 result; // ax
    int v10; // ecx
    __m64 v11; // [esp+Ch] [ebp-8h]

    v0 = *(_DWORD*)& byte_5D4594[3799456];
    v1 = *(__m64 * *) & byte_5D4594[3799444];
    v2 = *(__m64 * *) & byte_5D4594[3799540];
    v3 = *(__m64*)(&ptr_5D4594_3799572->data[260]);
    while (1)
    {
        v4 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
        v5 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
        v6 = _m_psllw(_m_pand((__m64)v2->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
        v7 = _m_por(
            _m_por(
                _m_pand(
                    _m_psrlw(
                        _m_paddw(
                            _m_psllwi(v4, 8u),
                            _m_pmullw(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                        *(__m64*) & byte_5D4594[3804444]),
                                    v4),
                                v3)),
                        *(__m64*) & byte_5D4594[3804468]),
                    *(__m64*) & byte_5D4594[3804396]),
                _m_pand(
                    _m_psrlw(
                        _m_paddw(
                            _m_psllwi(v5, 8u),
                            _m_pmullw(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                        *(__m64*) & byte_5D4594[3804452]),
                                    v5),
                                v3)),
                        *(__m64*) & byte_5D4594[3804476]),
                    *(__m64*) & byte_5D4594[3804404])),
            _m_psrlw(
                _m_paddw(
                    _m_psllwi(v6, 8u),
                    _m_pmullw(
                        _m_psubw(
                            _m_psllw(
                                _m_pand((__m64)v1->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                                *(__m64*) & byte_5D4594[3804460]),
                            v6),
                        v3)),
                *(__m64*) & byte_5D4594[3804484]));
        v8 = v0 < 4;
        v0 -= 4;
        if (v8)
            break;
        v2->m64_u64 = (unsigned __int64)v7;
        ++v1;
        ++v2;
        if (v8)
            goto LABEL_8;
    }
    v11 = v7;
    result = v11.m64_i16[0];
    LOWORD(v2->m64_i32[0]) = v11.m64_i16[0];
    v1 = (__m64*)((char*)v1 + 2);
    v2 = (__m64*)((char*)v2 + 2);
    v10 = v0 + 3;
    if (v10)
    {
        result = v11.m64_i16[1];
        LOWORD(v2->m64_i32[0]) = v11.m64_i16[1];
        v1 = (__m64*)((char*)v1 + 2);
        v2 = (__m64*)((char*)v2 + 2);
        if (v10 != 1)
        {
            result = v11.m64_i16[2];
            LOWORD(v2->m64_i32[0]) = v11.m64_i16[2];
            v1 = (__m64*)((char*)v1 + 2);
            v2 = (__m64*)((char*)v2 + 2);
        }
    }
LABEL_8:
    *(_DWORD*)& byte_5D4594[3799444] = v1;
    *(_DWORD*)& byte_5D4594[3799540] = v2;
    return result;
}
#endif

//----- (004C8410) --------------------------------------------------------
void sub_4C8410()
{
    int result; // eax
    _WORD* v1; // esi
    int v2; // [esp+0h] [ebp-1Ch]
    unsigned __int8 v3; // [esp+Ch] [ebp-10h]
    unsigned __int8 v4; // [esp+14h] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(_WORD * *)& byte_5D4594[3799540];
        v2 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v3 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v1) >> byte_5D4594[3804380];
            v4 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376];
            *v1 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(v4
                    + (((unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & **(_WORD * *)& byte_5D4594[3799444]) >> byte_5D4594[3804376])
                        - v4) >> 1))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656]
                            + 2
                            * (unsigned __int8)(v3
                                + (((unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & **(_WORD * *)& byte_5D4594[3799444]) >> byte_5D4594[3804380])
                                    - v3) >> 1))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + (((unsigned __int8)(((unsigned __int8) * *(_WORD * *)& byte_5D4594[3799444] & byte_5D4594[3804372]) << byte_5D4594[3804384]) - (unsigned __int8)((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 1)));
            v1 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v2 - 1;
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v2 = result;
        } while (result);
    }
}

__int16 sub_4C8570()
{
    DebugBreak();
    return 0;
}

#if 0
//----- (004C8570) --------------------------------------------------------
__int16 sub_4C8570()
{
    int v0; // ecx
    __m64* v1; // esi
    __m64* v2; // edi
    __m64 v3; // mm0
    __m64 v4; // mm1
    __m64 v5; // mm2
    __m64 v6; // mm0
    bool v7; // cc
    __int16 result; // ax
    int v9; // ecx
    __m64 v10; // [esp+Ch] [ebp-8h]

    v0 = *(_DWORD*)& byte_5D4594[3799456];
    v1 = *(__m64 * *) & byte_5D4594[3799444];
    v2 = *(__m64 * *) & byte_5D4594[3799540];
    while (1)
    {
        v3 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
        v4 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
        v5 = _m_psllw(_m_pand((__m64)v2->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
        v6 = _m_por(
            _m_por(
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v3,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                        *(__m64*) & byte_5D4594[3804444]),
                                    v3),
                                1u)),
                        *(__m64*) & byte_5D4594[3804444]),
                    *(__m64*) & byte_5D4594[3804396]),
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v4,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                        *(__m64*) & byte_5D4594[3804452]),
                                    v4),
                                1u)),
                        *(__m64*) & byte_5D4594[3804452]),
                    *(__m64*) & byte_5D4594[3804404])),
            _m_psrlw(
                _m_paddw(
                    v5,
                    _m_psrlwi(
                        _m_psubw(
                            _m_psllw(
                                _m_pand((__m64)v1->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                                *(__m64*) & byte_5D4594[3804460]),
                            v5),
                        1u)),
                *(__m64*) & byte_5D4594[3804460]));
        v7 = v0 < 4;
        v0 -= 4;
        if (v7)
            break;
        v2->m64_u64 = (unsigned __int64)v6;
        ++v1;
        ++v2;
        if (v7)
            goto LABEL_8;
    }
    v10 = v6;
    result = v10.m64_i16[0];
    LOWORD(v2->m64_i32[0]) = v10.m64_i16[0];
    v1 = (__m64*)((char*)v1 + 2);
    v2 = (__m64*)((char*)v2 + 2);
    v9 = v0 + 3;
    if (v9)
    {
        result = v10.m64_i16[1];
        LOWORD(v2->m64_i32[0]) = v10.m64_i16[1];
        v1 = (__m64*)((char*)v1 + 2);
        v2 = (__m64*)((char*)v2 + 2);
        if (v9 != 1)
        {
            result = v10.m64_i16[2];
            LOWORD(v2->m64_i32[0]) = v10.m64_i16[2];
            v1 = (__m64*)((char*)v1 + 2);
            v2 = (__m64*)((char*)v2 + 2);
        }
    }
LABEL_8:
    *(_DWORD*)& byte_5D4594[3799444] = v1;
    *(_DWORD*)& byte_5D4594[3799540] = v2;
    return result;
}
#endif

//----- (004C86B0) --------------------------------------------------------
void sub_4C86B0()
{
    __int16* v0; // esi
    _WORD* v1; // edi
    __int16 v2; // ax
    int result; // eax
    int v5; // [esp-4h] [ebp-10h]

    v0 = *(__int16**)& byte_5D4594[3799444];
    v1 = *(_WORD * *)& byte_5D4594[3799540];
    v5 = *(_DWORD*)& byte_5D4594[3799456];
    do
    {
        v2 = *v0;
        ++v0;
        result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804672]
            + 2
            * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[24])
                * ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v2) >> byte_5D4594[3804376])) >> 8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[25]) * ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v2) >> byte_5D4594[3804380])) >> 8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[26]) * ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & v2) << byte_5D4594[3804384])) >> 8));
        *v1 = result;
        ++v1;
    } while ((*(_DWORD*)& byte_5D4594[3799456])-- > 1);
    *(_DWORD*)& byte_5D4594[3799456] = v5;
    *(_DWORD*)& byte_5D4594[3799444] = v0;
    *(_DWORD*)& byte_5D4594[3799540] = v1;
}

__int32 sub_4C8760()
{
    DebugBreak();
    return 0;
}

#if 0
//----- (004C8760) --------------------------------------------------------
__int32 sub_4C8760()
{
    __m64 v0; // mm6
    __m64 v1; // mm5
    __m64 v2; // mm4
    __m64 v3; // mm3
    __m64* v4; // edi
    __m64* v5; // esi
    int v6; // ecx
    bool v7; // cc
    __m64 v8; // mm0
    __int32 result; // eax
    int v10; // ecx
    __m64 v11; // [esp+Ch] [ebp-8h]

    v0 = *(__m64*) & byte_5D4594[3804404];
    v1 = *(__m64*) & byte_5D4594[3804396];
    v2 = *(__m64*) & byte_5D4594[3804452];
    v3 = *(__m64*) & byte_5D4594[3804444];
    v4 = *(__m64 * *) & byte_5D4594[3799540];
    v5 = *(__m64 * *) & byte_5D4594[3799444];
    v6 = *(_DWORD*)& byte_5D4594[3799456];
    while (1)
    {
        v7 = v6 < 4;
        v6 -= 4;
        v8 = _m_por(
            _m_por(
                _m_pand(
                    _m_psrlw(
                        _m_pmullw(_m_psrlw(_m_pand((__m64)v5->m64_u64, v1), v3), *(__m64*)(&obj_5D4594_3800716.data[18])),
                        *(__m64*) & byte_5D4594[3804468]),
                    v1),
                _m_psrlw(
                    _m_pmullw(
                        _m_psllw(_m_pand((__m64)v5->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]),
                        *(__m64*)(&obj_5D4594_3800716.data[22])),
                    *(__m64*) & byte_5D4594[3804484])),
            _m_pand(
                _m_psrlw(
                    _m_pmullw(_m_psrlw(_m_pand((__m64)v5->m64_u64, v0), v2), *(__m64*)(&obj_5D4594_3800716.data[20])),
                    *(__m64*) & byte_5D4594[3804476]),
                v0));
        if (v7)
            break;
        ++v5;
        v4->m64_u64 = (unsigned __int64)v8;
        ++v4;
        if (v7)
            goto LABEL_8;
    }
    v11 = v8;
    result = v11.m64_i32[0];
    LOWORD(v4->m64_i32[0]) = v11.m64_i16[0];
    v5 = (__m64*)((char*)v5 + 2);
    v4 = (__m64*)((char*)v4 + 2);
    v10 = v6 + 3;
    if (v10)
    {
        result = *(__int32*)((char*)v11.m64_i32 + 2);
        LOWORD(v4->m64_i32[0]) = v11.m64_i16[1];
        v5 = (__m64*)((char*)v5 + 2);
        v4 = (__m64*)((char*)v4 + 2);
        if (v10 != 1)
        {
            result = v11.m64_i32[1];
            v5 = (__m64*)((char*)v5 + 2);
            LOWORD(v4->m64_i32[0]) = v11.m64_i16[2];
            v4 = (__m64*)((char*)v4 + 2);
        }
    }
LABEL_8:
    *(_DWORD*)& byte_5D4594[3799444] = v5;
    *(_DWORD*)& byte_5D4594[3799540] = v4;
    return result;
}
#endif

//----- (004C8850) --------------------------------------------------------
void sub_4C8850()
{
    int result; // eax
    _WORD* v1; // edi
    unsigned __int8 v2; // al
    bool v3; // zf
    int v4; // [esp+0h] [ebp-28h]
    unsigned __int8 v5; // [esp+4h] [ebp-24h]
    unsigned __int8 v6; // [esp+8h] [ebp-20h]
    unsigned __int8 v7; // [esp+Ch] [ebp-1Ch]
    int v8; // [esp+14h] [ebp-14h]
    unsigned __int8 v9; // [esp+18h] [ebp-10h]
    int v10; // [esp+20h] [ebp-8h]

    v7 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
    v6 = *(_BYTE*)(&ptr_5D4594_3799572->data[24]);
    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v10 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[26]);
        v8 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[25]);
        v1 = *(_WORD * *)& byte_5D4594[3799540];
        v4 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v5 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376];
            v2 = (*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384];
            v9 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v1) >> byte_5D4594[3804380];
            *v1 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)(v2
                    + ((unsigned __int16)(v7
                        * (((v10
                            * (unsigned __int8)(((unsigned __int8) * *(_WORD * *)& byte_5D4594[3799444] & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 8)
                            - v2)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656]
                                + 2
                                * (unsigned __int8)(v9 + ((unsigned __int16)(v7 * (((v8 * (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & **(_WORD * *)& byte_5D4594[3799444]) >> byte_5D4594[3804380])) >> 8) - v9)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(v5 + ((unsigned __int16)(v7 * (((v6 * (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & **(_WORD * *)& byte_5D4594[3799444]) >> byte_5D4594[3804376])) >> 8) - v5)) >> 8)));
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            v1 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v4 - 1;
            v3 = v4 == 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            --v4;
        } while (!v3);
    }
}

//----- (004C8A30) --------------------------------------------------------
void sub_4C8A30()
{
    WORD* v1; // esi
    int v5; // [esp+0h] [ebp-28h]
    unsigned __int8 v6; // [esp+4h] [ebp-24h]
    unsigned __int8 v7; // [esp+8h] [ebp-20h]
    __int16 v8; // [esp+Ch] [ebp-1Ch]

    unsigned int rshift = *(DWORD*)& byte_5D4594[3804384];
    unsigned int gshift = *(DWORD*)& byte_5D4594[3804380];
    unsigned int bshift = *(DWORD*)& byte_5D4594[3804376];

    unsigned int rmask = *(DWORD*)& byte_5D4594[3804372];
    unsigned int gmask = *(DWORD*)& byte_5D4594[3804368];
    unsigned int bmask = *(DWORD*)& byte_5D4594[3804364];

    WORD* add1 = *(_DWORD*)& byte_5D4594[3804672];
    WORD* add2 = *(_DWORD*)& byte_5D4594[3804664];
    WORD* add3 = *(_DWORD*)& byte_5D4594[3804656];

    WORD* px = *(_WORD * *)& byte_5D4594[3799444];

    v7 = *(_BYTE*)(&ptr_5D4594_3799572->data[26]);
    v6 = *(_BYTE*)(&ptr_5D4594_3799572->data[25]);
    v8 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[24]);
    v1 = *(WORD * *)& byte_5D4594[3799540];
    for (v5 = *(_DWORD*)& byte_5D4594[3799456]; v5 > 0; --v5)
    {
        BYTE v3; // eax
        BYTE v9; // [esp+18h] [ebp-10h]
        BYTE v10; // [esp+20h] [ebp-8h]
        WORD v2 = *v1; // old color
        WORD x = *px; // color to draw

        // XXX This code is incorrect in the original Nox binary, but is correct
        //     in the MMX version of this function. The color multiply (v8,v6,v7)
        //     is supposed to be applied to the new color, not to the old color.
        //     The old color already had it applied earlier.
        v3 = (v7 * ((rmask & x) << rshift)) >> 8;
        v9 = (v6 * ((gmask & x) >> gshift)) >> 8;
        v10 = (v8 * ((bmask & x) >> bshift)) >> 8;
        *v1 = add1[v10 + (((bmask & v2) >> bshift) - v10) / 2] | add3[v9 + (((gmask & v2) >> gshift) - v9) / 2] | add2[v3 + (((rmask & v2) << rshift) - v3) / 2];
        v1++;
        px++;
    }
    *(WORD * *)& byte_5D4594[3799444] = px;
    *(WORD * *)& byte_5D4594[3799540] = v1;
}

__int16 sub_4C8C00()
{
    DebugBreak();
    return 0;
}

#if 0
//----- (004C8C00) --------------------------------------------------------
__int16 sub_4C8C00()
{
    int v0; // ecx
    __m64 v1; // mm5
    __m64 v2; // mm6
    __m64 v3; // mm7
    __m64* v4; // esi
    __m64* v5; // edi
    bool v6; // cc
    __m64 v7; // mm0
    __m64 v8; // mm1
    __m64 v9; // mm2
    __m64 v10; // mm0
    __int16 result; // ax
    int v12; // ecx
    __m64 v13; // [esp+Ch] [ebp-8h]

    v0 = *(_DWORD*)& byte_5D4594[3799456];
    v1 = *(__m64*)(&ptr_5D4594_3799572->data[18]);
    v2 = *(__m64*)(&ptr_5D4594_3799572->data[20]);
    v3 = *(__m64*)(&ptr_5D4594_3799572->data[22]);
    v4 = *(__m64 * *) & byte_5D4594[3799444];
    v5 = *(__m64 * *) & byte_5D4594[3799540];
    while (1)
    {
        v6 = v0 < 4;
        v0 -= 4;
        v7 = _m_psrlw(_m_pand((__m64)v5->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
        v8 = _m_psrlw(_m_pand((__m64)v5->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
        v9 = _m_psllw(_m_pand((__m64)v5->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
        v10 = _m_por(
            _m_por(
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v7,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlwi(
                                        _m_pmullw(
                                            _m_psrlw(
                                                _m_pand((__m64)v4->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                                *(__m64*) & byte_5D4594[3804444]),
                                            v1),
                                        8u),
                                    v7),
                                1u)),
                        *(__m64*) & byte_5D4594[3804444]),
                    *(__m64*) & byte_5D4594[3804396]),
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v8,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlwi(
                                        _m_pmullw(
                                            _m_psrlw(
                                                _m_pand((__m64)v4->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                                *(__m64*) & byte_5D4594[3804452]),
                                            v2),
                                        8u),
                                    v8),
                                1u)),
                        *(__m64*) & byte_5D4594[3804452]),
                    *(__m64*) & byte_5D4594[3804404])),
            _m_pand(
                _m_psrlw(
                    _m_paddw(
                        v9,
                        _m_psrlwi(
                            _m_psubw(
                                _m_psrlwi(
                                    _m_pmullw(
                                        _m_psllw(
                                            _m_pand((__m64)v4->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                                            *(__m64*) & byte_5D4594[3804460]),
                                        v3),
                                    8u),
                                v9),
                            1u)),
                    *(__m64*) & byte_5D4594[3804460]),
                *(__m64*) & byte_5D4594[3804412]));
        if (v6)
            break;
        v5->m64_u64 = (unsigned __int64)v10;
        ++v4;
        ++v5;
        if (v6)
            goto LABEL_8;
    }
    v13 = v10;
    result = v13.m64_i16[0];
    LOWORD(v5->m64_i32[0]) = v13.m64_i16[0];
    v4 = (__m64*)((char*)v4 + 2);
    v5 = (__m64*)((char*)v5 + 2);
    v12 = v0 + 3;
    if (v12)
    {
        result = v13.m64_i16[1];
        LOWORD(v5->m64_i32[0]) = v13.m64_i16[1];
        v4 = (__m64*)((char*)v4 + 2);
        v5 = (__m64*)((char*)v5 + 2);
        if (v12 != 1)
        {
            result = v13.m64_i16[2];
            v4 = (__m64*)((char*)v4 + 2);
            LOWORD(v5->m64_i32[0]) = v13.m64_i16[2];
            v5 = (__m64*)((char*)v5 + 2);
        }
    }
LABEL_8:
    *(_DWORD*)& byte_5D4594[3799444] = v4;
    *(_DWORD*)& byte_5D4594[3799540] = v5;
    return result;
}
#endif

//----- (004C8D60) --------------------------------------------------------
void sub_4C8D60()
{
    unsigned __int16* v0; // esi
    _WORD* v1; // edi
    unsigned __int16 v2; // ax
    int v3; // eax
    int result; // eax
    int v6; // [esp-4h] [ebp-10h]

    v0 = *(unsigned __int16**)& byte_5D4594[3799444];
    v1 = *(_WORD * *)& byte_5D4594[3799540];
    v6 = *(_DWORD*)& byte_5D4594[3799456];
    do
    {
        v2 = *v0;
        ++v0;
        v3 = (unsigned __int8) * (_DWORD*)(*(_DWORD*)& byte_5D4594[3804668] + v2);
        result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804672]
            + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[24]) * v3) >> 8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[25]) * v3) >> 8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[26]) * v3) >> 8));
        *v1 = result;
        ++v1;
    } while ((*(_DWORD*)& byte_5D4594[3799456])-- > 1);
    *(_DWORD*)& byte_5D4594[3799456] = v6;
    *(_DWORD*)& byte_5D4594[3799444] = v0;
    *(_DWORD*)& byte_5D4594[3799540] = v1;
}

//----- (004C8DF0) --------------------------------------------------------
void sub_4C8DF0()
{
    int result; // eax
    int v1; // ecx
    int v2; // esi
    int v3; // edi
    bool v4; // zf
    int v5; // [esp+8h] [ebp-30h]
    unsigned __int8 v6; // [esp+Ch] [ebp-2Ch]
    char v7[40]; // [esp+10h] [ebp-28h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    qmemcpy(
        v7,
        (const void*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[66])),
        sizeof(v7));
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(_DWORD*)& v7[32];
        v2 = *(_DWORD*)& v7[28];
        v3 = *(_DWORD*)& v7[24];
        v5 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v6 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            **(_WORD * *)& byte_5D4594[3799540] = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2 * ((v3 * (unsigned int)v6) >> 8)) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * ((v2 * (unsigned int)v6) >> 8)) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * ((v1 * (unsigned int)v6) >> 8));
            result = v5 - 1;
            v4 = v5 == 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            --v5;
        } while (!v4);
    }
}

//----- (004C8EC0) --------------------------------------------------------
void sub_4C8EC0()
{
    int result; // eax
    _WORD* v1; // esi
    __int16 v2; // di
    unsigned __int8 v3; // [esp+8h] [ebp-3Ch]
    int v4; // [esp+8h] [ebp-3Ch]
    unsigned __int8 v5; // [esp+Ch] [ebp-38h]
    unsigned __int8 v6; // [esp+14h] [ebp-30h]
    char v7[40]; // [esp+1Ch] [ebp-28h]

    v3 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
    qmemcpy(
        v7,
        (const void*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[66])),
        sizeof(v7));
    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(_WORD * *)& byte_5D4594[3799540];
        v2 = v3;
        v4 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v5 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            v6 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v1) >> byte_5D4594[3804380];
            **(_WORD * *)& byte_5D4594[3799540] = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376])
                    + ((unsigned __int16)(v2
                        * ((unsigned __int8)((unsigned __int16)(*(_WORD*)& v7[24] * v5) >> 8)
                            - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376]))) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(v6 + ((unsigned __int16)(v2 * ((unsigned __int8)((unsigned __int16)(*(_WORD*)& v7[28] * v5) >> 8) - v6)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((unsigned __int16)(v2 * ((unsigned __int8)((unsigned __int16)(*(_WORD*)& v7[32] * v5) >> 8) - (unsigned __int8)((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384]))) >> 8)));
            v1 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v4 - 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v4 = result;
        } while (result);
    }
}

//----- (004C9050) --------------------------------------------------------
void sub_4C9050()
{
    int result; // eax
    _WORD* v1; // edi
    unsigned __int8 v2; // cl
    unsigned int v3; // edx
    int v4; // [esp+8h] [ebp-3Ch]
    char v5[40]; // [esp+1Ch] [ebp-28h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    qmemcpy(
        v5,
        (const void*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[66])),
        sizeof(v5));
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(_WORD * *)& byte_5D4594[3799540];
        v4 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v2 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            v3 = (unsigned __int16)* v1;
            *v1 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v3) >> byte_5D4594[3804376])
                    + ((int)((((*(_DWORD*)& v5[24] * (unsigned int)v2) >> 8) & 0xFF)
                        - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v3) >> byte_5D4594[3804376])) >> 1))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v3) >> byte_5D4594[3804380]) + ((int)((((*(_DWORD*)& v5[28] * (unsigned int)v2) >> 8) & 0xFF) - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v3) >> byte_5D4594[3804380])) >> 1))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((int)((((*(_DWORD*)& v5[32] * (unsigned int)v2) >> 8) & 0xFF) - (unsigned __int8)((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 1)));
            v1 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v4 - 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v4 = result;
        } while (result);
    }
}

//----- (004C91C0) --------------------------------------------------------
void sub_4C91C0()
{
    int result; // eax
    int v1; // ecx
    int v2; // edi
    bool v3; // zf
    unsigned __int8 v4; // [esp+8h] [ebp-34h]
    int v5; // [esp+8h] [ebp-34h]
    unsigned __int8 v6; // [esp+Ch] [ebp-30h]
    unsigned __int8 v7; // [esp+10h] [ebp-2Ch]
    unsigned __int8 v8; // [esp+10h] [ebp-2Ch]
    char v9[40]; // [esp+14h] [ebp-28h]

    v7 = *(_BYTE*)(&ptr_5D4594_3799572->data[24]);
    v6 = *(_BYTE*)(&ptr_5D4594_3799572->data[25]);
    v4 = *(_BYTE*)(&ptr_5D4594_3799572->data[26]);
    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    qmemcpy(
        v9,
        (const void*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[66])),
        sizeof(v9));
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = v4;
        v2 = v7;
        v5 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v8 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            **(_WORD * *)& byte_5D4594[3799540] = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (((int)(v1 * (((*(_DWORD*)& v9[32] * (unsigned int)v8) >> 8) & 0xFF)) >> 8) & 0xFF)) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (((int)(v6 * (((*(_DWORD*)& v9[28] * (unsigned int)v8) >> 8) & 0xFF)) >> 8) & 0xFF)) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (((int)(v2 * (((*(_DWORD*)& v9[24] * (unsigned int)v8) >> 8) & 0xFF)) >> 8) & 0xFF));
            result = v5 - 1;
            v3 = v5 == 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            --v5;
        } while (!v3);
    }
}

//----- (004C92F0) --------------------------------------------------------
void sub_4C92F0()
{
    int result; // eax
    _WORD* v1; // esi
    unsigned __int8 v2; // dl
    int v3; // eax
    bool v4; // zf
    unsigned __int8 v5; // [esp+8h] [ebp-48h]
    int v6; // [esp+8h] [ebp-48h]
    unsigned __int8 v7; // [esp+Ch] [ebp-44h]
    unsigned __int8 v8; // [esp+10h] [ebp-40h]
    unsigned __int8 v9; // [esp+14h] [ebp-3Ch]
    unsigned __int8 v10; // [esp+1Ch] [ebp-34h]
    int v11; // [esp+20h] [ebp-30h]
    char v12[40]; // [esp+28h] [ebp-28h]

    v9 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
    v8 = *(_BYTE*)(&ptr_5D4594_3799572->data[24]);
    v7 = *(_BYTE*)(&ptr_5D4594_3799572->data[25]);
    v5 = *(_BYTE*)(&ptr_5D4594_3799572->data[26]);
    qmemcpy(
        v12,
        (const void*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[66])),
        sizeof(v12));
    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(_WORD * *)& byte_5D4594[3799540];
        v11 = v5;
        v6 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v2 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            v3 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376];
            v10 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v1) >> byte_5D4594[3804380];
            **(_WORD * *)& byte_5D4594[3799540] = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)(((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((unsigned __int16)(v9
                        * (((int)(v11
                            * (((*(_DWORD*)& v12[32] * (unsigned int)v2) >> 8) & 0xFF)) >> 8)
                            - (unsigned __int8)((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384]))) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(v10 + ((unsigned __int16)(v9 * (((int)(v7 * (((*(_DWORD*)& v12[28] * (unsigned int)v2) >> 8) & 0xFF)) >> 8) - v10)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(v3 + ((unsigned __int16)(v9 * (((int)(v8 * (((*(_DWORD*)& v12[24] * (unsigned int)v2) >> 8) & 0xFF)) >> 8) - (unsigned __int8)v3)) >> 8)));
            v1 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v6 - 1;
            v4 = v6 == 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            --v6;
        } while (!v4);
    }
}

//----- (004C94D0) --------------------------------------------------------
void sub_4C94D0()
{
    unsigned __int8 v0; // dl
    int result; // eax
    _WORD* v2; // edi
    int v3; // eax
    int v4; // [esp+8h] [ebp-48h]
    unsigned __int8 v5; // [esp+Ch] [ebp-44h]
    unsigned __int8 v6; // [esp+10h] [ebp-40h]
    int v7; // [esp+14h] [ebp-3Ch]
    int v8; // [esp+1Ch] [ebp-34h]
    char v9[40]; // [esp+28h] [ebp-28h]

    v0 = *(_BYTE*)(&ptr_5D4594_3799572->data[24]);
    qmemcpy(
        v9,
        (const void*)(48 * (*(_DWORD*)& byte_5D4594[3799428] >> 4) + (_DWORD)(&ptr_5D4594_3799572->data[66])),
        sizeof(v9));
    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v2 = *(_WORD * *)& byte_5D4594[3799540];
        v8 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[26]);
        v7 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[25]);
        v4 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            v6 = **(_BYTE * *)& byte_5D4594[3799444];
            ++* (_DWORD*)& byte_5D4594[3799444];
            v3 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v2) >> byte_5D4594[3804376];
            v5 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v2) >> byte_5D4594[3804380];
            *v2 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672]
                + 2
                * (((v0
                    * (unsigned __int8)(v3
                        + ((int)((((*(_DWORD*)& v9[24] * (unsigned int)v6) >> 8) & 0xFF)
                            - (unsigned __int8)v3) >> 1))) >> 8) & 0xFF)) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (((v8 * (unsigned __int8)(((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384]) + ((int)((((*(_DWORD*)& v9[32] * (unsigned int)v6) >> 8) & 0xFF) - (unsigned __int8)((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384])) >> 1))) >> 8) & 0xFF)) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (((v7 * (unsigned __int8)(v5 + ((int)((((*(_DWORD*)& v9[28] * (unsigned int)v6) >> 8) & 0xFF) - v5) >> 1))) >> 8) & 0xFF));
            v2 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v4 - 1;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v4 = result;
        } while (result);
    }
}

//----- (004C96A0) --------------------------------------------------------
void sub_4C96A0()
{
    unsigned int result; // eax
    _WORD* v1; // edi
    __int16 v2; // si
    unsigned __int8 v3; // [esp+0h] [ebp-14h]
    unsigned int v4; // [esp+8h] [ebp-Ch]
    unsigned __int8 v5; // [esp+10h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        HIWORD(result) = *(_WORD*)& byte_5D4594[3799458];
        v1 = *(_WORD * *)& byte_5D4594[3799540];
        v4 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            LOWORD(result) = **(_WORD * *)& byte_5D4594[3799444];
            v2 = (unsigned __int8)(16 * **(_WORD * *)& byte_5D4594[3799444]);
            v5 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376];
            v3 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v1) >> byte_5D4594[3804380];
            *v1 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)(((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((unsigned __int16)(v2
                        * ((**(_WORD * *)& byte_5D4594[3799444] & 0xF0)
                            - (unsigned __int8)((*(_BYTE*)v1 & byte_5D4594[3804372]) << byte_5D4594[3804384]))) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(v5 + ((unsigned __int16)(v2 * (((**(_WORD * *)& byte_5D4594[3799444] >> 8) & 0xF0) - v5)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(v3 + ((unsigned __int16)(v2 * (((result >> 4) & 0xF0) - v3)) >> 8)));
            v1 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v4 - 1;
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v4 = result;
        } while (result);
    }
}

//----- (004C97F0) --------------------------------------------------------
void sub_4C97F0()
{
    int result; // eax
    int v1; // ecx
    _WORD* v2; // edi
    unsigned int v3; // eax
    unsigned int v4; // ebx
    int v5; // edx
    unsigned __int8 v6; // [esp+8h] [ebp-10h]
    int v7; // [esp+8h] [ebp-10h]
    int v8; // [esp+Ch] [ebp-Ch]

    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    v6 = *(_BYTE*)(&ptr_5D4594_3799572->data[259]);
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = v6;
        v2 = *(_WORD * *)& byte_5D4594[3799540];
        v8 = v6;
        v7 = *(_DWORD*)& byte_5D4594[3799456];
        while (1)
        {
            HIWORD(v3) = *(_WORD*)& byte_5D4594[3799446];
            v4 = (unsigned __int16)* v2;
            LOWORD(v3) = **(_WORD * *)& byte_5D4594[3799444];
            v5 = v1 * 16 * (**(_WORD * *)& byte_5D4594[3799444] & 0xF);
            *v2 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)(((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((unsigned __int16)(BYTE1(v5)
                        * ((**(_WORD * *)& byte_5D4594[3799444] & 0xF0)
                            - (unsigned __int8)((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384]))) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804364] & v4) >> byte_5D4594[3804376]) + ((unsigned __int16)(BYTE1(v5) * (((**(_WORD * *)& byte_5D4594[3799444] >> 8) & 0xF0) - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804364] & v4) >> byte_5D4594[3804376]))) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((*(_DWORD*)& byte_5D4594[3804368] & v4) >> byte_5D4594[3804380]) + ((unsigned __int16)(BYTE1(v5) * (((v3 >> 4) & 0xF0) - (unsigned __int8)((*(_DWORD*)& byte_5D4594[3804368] & v4) >> byte_5D4594[3804380]))) >> 8)));
            v2 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v7 - 1;
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v7 = result;
            if (!result)
                break;
            v1 = v8;
        }
    }
}

//----- (004C9970) --------------------------------------------------------
void sub_4C9970()
{
    unsigned int result; // eax
    int v1; // ebp
    _WORD* v2; // edi
    __int16 v3; // si
    unsigned __int8 v4; // [esp+0h] [ebp-1Ch]
    unsigned __int8 v5; // [esp+4h] [ebp-18h]
    unsigned int v6; // [esp+8h] [ebp-14h]
    unsigned __int8 v7; // [esp+14h] [ebp-8h]
    int v8; // [esp+18h] [ebp-4h]

    v5 = *(_BYTE*)(&ptr_5D4594_3799572->data[24]);
    result = *(_DWORD*)& byte_5D4594[3799456] - 1;
    if (*(_DWORD*)& byte_5D4594[3799456])
    {
        v1 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[25]);
        HIWORD(result) = *(_WORD*)& byte_5D4594[3799458];
        v2 = *(_WORD * *)& byte_5D4594[3799540];
        v8 = *(unsigned __int8*)(&ptr_5D4594_3799572->data[26]);
        v6 = *(_DWORD*)& byte_5D4594[3799456];
        do
        {
            LOWORD(result) = **(_WORD * *)& byte_5D4594[3799444];
            v7 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v2) >> byte_5D4594[3804376];
            v3 = (unsigned __int8)(16 * **(_WORD * *)& byte_5D4594[3799444]);
            v4 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v2) >> byte_5D4594[3804380];
            *v2 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                + 2
                * (unsigned __int8)(((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384])
                    + ((unsigned __int16)(v3
                        * (((v8 * (**(_WORD * *)& byte_5D4594[3799444] & 0xF0)) >> 8)
                            - (unsigned __int8)((*(_BYTE*)v2 & byte_5D4594[3804372]) << byte_5D4594[3804384]))) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(v4 + ((unsigned __int16)(v3 * (((int)(v1 * ((result >> 4) & 0xF0)) >> 8) - v4)) >> 8))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(v7 + ((unsigned __int16)(v3 * (((v5 * ((**(_WORD * *)& byte_5D4594[3799444] >> 8) & 0xF0)) >> 8) - v7)) >> 8)));
            v2 = (_WORD*)(*(_DWORD*)& byte_5D4594[3799540] + 2);
            result = v6 - 1;
            *(_DWORD*)& byte_5D4594[3799444] += 2;
            *(_DWORD*)& byte_5D4594[3799540] += 2;
            v6 = result;
        } while (result);
    }
}

//----- (004C9B20) --------------------------------------------------------
void sub_4C9B20()
{
    unsigned __int16* v0; // esi
    _WORD* v1; // edi
    unsigned int v2; // edx
    int v3; // eax
    unsigned int v4; // ebx
    int v5; // edx
    unsigned __int16 v6; // cx
    int result; // eax
    int v9; // [esp-4h] [ebp-10h]

    v0 = *(unsigned __int16**)& byte_5D4594[3799444];
    v1 = *(_WORD * *)& byte_5D4594[3799540];
    v9 = *(_DWORD*)& byte_5D4594[3799456];
    do
    {
        v2 = (unsigned __int16)* v1;
        v3 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v1) >> byte_5D4594[3804376];
        v4 = (*(_DWORD*)& byte_5D4594[3804368] & v2) >> byte_5D4594[3804380];
        v5 = (*(_DWORD*)& byte_5D4594[3804372] & v2) << byte_5D4594[3804384];
        v6 = *v0;
        ++v0;
        LOBYTE(v3) = SADD8(HIBYTE(v6) & 0xF8 | 7, (_BYTE)v3);
        LOBYTE(v5) = SADD8((8 * v6) & 0xF8 | 7, (_BYTE)v5);
        LOBYTE(v4) = SADD8((v6 >> 3) & 0xFC | 3, (_BYTE)v4);
        result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * v5) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804656]
            + 2 * v4) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * v3);
        *v1 = result;
        ++v1;
    } while ((*(_DWORD*)& byte_5D4594[3799456])-- > 1);
    *(_DWORD*)& byte_5D4594[3799456] = v9;
    *(_DWORD*)& byte_5D4594[3799444] = v0;
    *(_DWORD*)& byte_5D4594[3799540] = v1;
}

//----- (004C9BF0) --------------------------------------------------------
int __cdecl sub_4C9BF0(int a1)
{
    int result; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    char* v7; // eax
    wchar_t* v8; // eax
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    wchar_t* v12; // eax
    char* v13; // eax
    wchar_t* v14; // eax
    char* v15; // eax
    wchar_t* v16; // eax
    wchar_t* v17; // eax
    char* v18; // edi
    wchar_t* v19; // eax
    char* v20; // edi
    wchar_t* v21; // eax
    char* v22; // edi
    wchar_t* v23; // eax
    char* v24; // eax
    wchar_t* v25; // eax
    char* v26; // eax
    wchar_t* v27; // eax
    wchar_t* v28; // eax
    wchar_t* v29; // eax
    char* v30; // edi
    char* v31; // eax
    wchar_t* v32; // eax
    wchar_t* v33; // eax
    char* v34; // edi
    char* v35; // eax
    wchar_t* v36; // eax
    wchar_t* v37; // eax
    char* v38; // edi
    char* v39; // eax
    wchar_t* v40; // eax
    wchar_t* v41; // eax
    unsigned int v42; // kr04_4
    wchar_t* v43; // eax
    wchar_t* v44; // eax
    wchar_t* v45; // [esp-10h] [ebp-418h]
    int v46; // [esp-8h] [ebp-410h]
    wchar_t* v47; // [esp-8h] [ebp-410h]
    int v48; // [esp-4h] [ebp-40Ch]
    wchar_t* v49; // [esp-4h] [ebp-40Ch]
    int v50; // [esp-4h] [ebp-40Ch]
    int v51; // [esp-4h] [ebp-40Ch]
    int v52; // [esp-4h] [ebp-40Ch]
    wchar_t* v53; // [esp-4h] [ebp-40Ch]
    wchar_t* v54; // [esp-4h] [ebp-40Ch]
    wchar_t* v55; // [esp-4h] [ebp-40Ch]
    wchar_t* v56; // [esp-4h] [ebp-40Ch]
    int v57; // [esp-4h] [ebp-40Ch]
    int v58; // [esp-4h] [ebp-40Ch]
    int v59; // [esp-4h] [ebp-40Ch]
    char* v60; // [esp-4h] [ebp-40Ch]
    char* v61; // [esp-4h] [ebp-40Ch]
    wchar_t v62[256]; // [esp+8h] [ebp-400h]
    wchar_t v63[256]; // [esp+208h] [ebp-200h]

    result = 0;
    switch (*(unsigned __int8*)(a1 + 1))
    {
    case 0u:
        sub_4FB0B0(*(_DWORD*)(a1 + 2));
        return 6;
    case 1u:
        v50 = sub_424930(*(_DWORD*)(a1 + 2));
        v10 = loadString_sub_40F1D0((char*)& byte_587000[186124], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 117);
        nox_swprintf(v62, v10, v50);
        sub_445490(v62);
        return 6;
    case 2u:
        sub_4FB960(*(_DWORD*)(a1 + 2));
        return 6;
    case 3u:
        v13 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v13)
            return 6;
        v51 = (int)(v13 + 4704);
        v14 = loadString_sub_40F1D0((char*)& byte_587000[186320], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 147);
        nox_swprintf(v62, v14, v51);
        sub_445490(v62);
        return 6;
    case 4u:
        v15 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v15)
            return 6;
        v52 = (int)(v15 + 4704);
        v16 = loadString_sub_40F1D0((char*)& byte_587000[186384], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 164);
        nox_swprintf(v62, v16, v52);
        goto LABEL_22;
    case 5u:
        v18 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v18)
            return 10;
        v54 = sub_418C20(*(_DWORD*)(a1 + 6));
        v19 = loadString_sub_40F1D0((char*)& byte_587000[186524], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 196);
        nox_swprintf(v62, v19, v18 + 4704, v54);
        sub_445490(v62);
        sub_452D80(306, 100);
        return 10;
    case 6u:
        v20 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v20)
            return 10;
        v55 = sub_418C20(*(_DWORD*)(a1 + 6));
        v21 = loadString_sub_40F1D0((char*)& byte_587000[186592], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 213);
        nox_swprintf(v62, v21, v20 + 4704, v55);
        sub_445490(v62);
        sub_452D80(303, 100);
        return 10;
    case 7u:
        v22 = sub_417040(*(_DWORD*)(a1 + 2));
        if (v22)
        {
            v56 = sub_418C20(*(_DWORD*)(a1 + 6));
            v23 = loadString_sub_40F1D0((char*)& byte_587000[186660], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 230);
            nox_swprintf(v62, v23, v22 + 4704, v56);
            sub_445490(v62);
            sub_452D80(304, 100);
        }
        return 10;
    case 8u:
        v53 = sub_418C20(*(_DWORD*)(a1 + 2));
        v17 = loadString_sub_40F1D0((char*)& byte_587000[186456], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 179);
        nox_swprintf(v62, v17, v53);
    LABEL_22:
        sub_445490(v62);
        sub_452D80(305, 100);
        return 6;
    case 9u:
        v38 = sub_418AB0(*(_DWORD*)(a1 + 6));
        v39 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v39)
        {
            if (v38)
            {
                v41 = loadString_sub_40F1D0((char*)& byte_587000[187308], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 374);
                nox_swprintf(v62, v41, v38);
                sub_445490(v62);
            }
            return 10;
        }
        if (!v38)
            return 10;
        v46 = (int)(v39 + 4704);
        v40 = loadString_sub_40F1D0((char*)& byte_587000[187240], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 365);
        nox_swprintf(v62, v40, v46, v38);
        sub_445490(v62);
        return 10;
    case 0xAu:
        v34 = sub_417040(*(_DWORD*)(a1 + 2));
        v35 = sub_418AB0(*(_DWORD*)(a1 + 6));
        if (v35)
        {
            if (!v34)
                return 10;
            v61 = v35;
            v36 = loadString_sub_40F1D0((char*)& byte_587000[187108], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 334);
            nox_swprintf(v62, v36, v34 + 4704, v61);
            sub_445490(v62);
            result = 10;
        }
        else
        {
            if (!v34)
                return 10;
            v37 = loadString_sub_40F1D0((char*)& byte_587000[187176], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 343);
            nox_swprintf(v62, v37, v34 + 4704);
            sub_445490(v62);
            result = 10;
        }
        return result;
    case 0xBu:
        v30 = sub_417040(*(_DWORD*)(a1 + 2));
        v31 = sub_418AB0(*(_DWORD*)(a1 + 6));
        if (v31)
        {
            if (v30)
            {
                v60 = v31;
                v32 = loadString_sub_40F1D0((char*)& byte_587000[186984], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 303);
                nox_swprintf(v62, v32, v30 + 4704, v60);
                sub_445490(v62);
                return 10;
            }
        }
        else if (v30)
        {
            v33 = loadString_sub_40F1D0((char*)& byte_587000[187048], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 312);
            nox_swprintf(v62, v33, v30 + 4704);
            sub_445490(v62);
            return 10;
        }
        return 10;
    case 0xCu:
        v11 = loadString_sub_40F1D0((char*)& byte_587000[186192], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 128);
        sub_445490(v11);
        if (!*(_DWORD*)(a1 + 2))
            return 6;
        v12 = loadString_sub_40F1D0((char*)& byte_587000[186260], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 132);
        sub_445490(v12);
        return 6;
    case 0xDu:
        switch (*(_DWORD*)(a1 + 2))
        {
        case 0:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[185600], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 27);
            sub_445490(v2);
            result = 6;
            break;
        case 1:
            v3 = loadString_sub_40F1D0((char*)& byte_587000[185668], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 31);
            sub_445490(v3);
            result = 6;
            break;
        case 2:
            v4 = loadString_sub_40F1D0((char*)& byte_587000[185736], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 35);
            sub_445490(v4);
            result = 6;
            break;
        case 3:
            v5 = loadString_sub_40F1D0((char*)& byte_587000[185804], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 39);
            sub_445490(v5);
            result = 6;
            break;
        default:
            return 6;
        }
        return result;
    case 0xEu:
        sub_495210(a1);
        return 11;
    case 0xFu:
        v42 = strlen((const char*)(a1 + 3)) + 1;
        if (sub_4356B0() != 3)
            goto LABEL_57;
        if (*(_BYTE*)(a1 + 2))
        {
            v47 = loadString_sub_40F1D0((char*)(a1 + 3), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 397);
            v43 = loadString_sub_40F1D0((char*)& byte_587000[187420], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 396);
            nox_swprintf(v63, v43, v47);
            sub_445490(v63);
            result = v42 + 3;
        }
        else
        {
            v44 = loadString_sub_40F1D0((char*)(a1 + 3), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 402);
            sub_445490(v44);
        LABEL_57:
            result = v42 + 3;
        }
        return result;
    case 0x10u:
        v49 = sub_418C20(*(_DWORD*)(a1 + 2));
        v9 = loadString_sub_40F1D0((char*)& byte_587000[186064], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 105);
        nox_swprintf(v62, v9, v49);
        sub_445490(v62);
        return 6;
    case 0x11u:
        v45 = loadString_sub_40F1D0((char*)& byte_587000[185864], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 51);
        v6 = loadString_sub_40F1D0((char*)& byte_587000[185932], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 50);
        sub_449A10(0, (int)v6, (int)v45, 33, 0, 0);
        return 2;
    case 0x12u:
        v24 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v24)
            return 6;
        v57 = (int)(v24 + 4704);
        v25 = loadString_sub_40F1D0((char*)& byte_587000[186724], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 247);
        nox_swprintf(v62, v25, v57);
        sub_445490(v62);
        return 6;
    case 0x13u:
        v26 = sub_417040(*(_DWORD*)(a1 + 2));
        if (v26)
        {
            v58 = (int)(v26 + 4704);
            v27 = loadString_sub_40F1D0((char*)& byte_587000[186788], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 265);
            nox_swprintf(v62, v27, v58);
            sub_445490(v62);
        }
        return 6;
    case 0x14u:
        v7 = sub_417040(*(_DWORD*)(a1 + 2));
        if (!v7)
            return 6;
        v48 = (int)(v7 + 4704);
        v8 = loadString_sub_40F1D0((char*)& byte_587000[185992], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 90);
        nox_swprintf(v62, v8, v48);
        sub_445490(v62);
        return 6;
    case 0x15u:
        v59 = *(_DWORD*)(a1 + 2);
        v28 = loadString_sub_40F1D0((char*)& byte_587000[186856], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 281);
        nox_swprintf(v62, v28, v59);
        v29 = loadString_sub_40F1D0((char*)& byte_587000[186928], 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 282);
        nox_swprintf(v63, v29, v62);
        sub_445490(v63);
        return 6;
    default:
        return result;
    }
}

//----- (004CA540) --------------------------------------------------------
int __cdecl sub_4CA540(_DWORD* a1, int a2)
{
    _DWORD* v2; // esi
    double v3; // st7
    double v4; // st6
    double v5; // st5
    double v6; // st4
    int v7; // eax
    int v8; // edi
    int v9; // eax
    float v11; // [esp+0h] [ebp-14h]
    float v12; // [esp+0h] [ebp-14h]
    float v13; // [esp+10h] [ebp-4h]
    float v14; // [esp+1Ch] [ebp+8h]

    v2 = (_DWORD*)a2;
    v3 = 0.0;
    v4 = *(float*)(a2 + 468);
    v5 = *(float*)(a2 + 472);
    v6 = 0.0;
    v7 = *(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 316) + 1;
    do
    {
        --v7;
        v13 = -(v5 * *(float*)(a2 + 476));
        v4 = v4 - v4 * *(float*)(a2 + 476);
        v5 = v5 + v13;
        v3 = v3 + v4;
        v6 = v6 + v5;
    } while (v7);
    v14 = v6;
    v11 = (double)(int)v2[81] + v3;
    v8 = sub_419A70(v11);
    v12 = (double)(int)v2[82] + v14;
    v9 = sub_419A70(v12);
    if (v8 > 0 && v9 > 0 && v8 < 5888 && v9 < 5888)
    {
        sub_49AA90(v2, v8, v9);
        if (sub_4992B0(*a1 + v2[3] - a1[4], v2[4] + a1[1] - a1[5]))
            return 1;
    }
    sub_45A4E0((int)v2);
    return 0;
}

//----- (004CA650) --------------------------------------------------------
int __cdecl sub_4CA650(int a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int v4; // ebx
    int v5; // edi
    int v6; // eax
    int v7; // ecx
    int v8; // eax
    int v9; // ebp
    int v10; // eax
    int v11; // edi
    unsigned __int16 v12; // dx
    int v13; // ebp
    int v14; // eax
    int result; // eax
    int v16; // [esp+10h] [ebp-10h]
    int v17; // [esp+28h] [ebp+8h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 16);
    v4 = *(unsigned __int16*)(a2 + 434) - v3;
    v5 = *(unsigned __int16*)(a2 + 432) - *(_DWORD*)(a2 + 12);
    v6 = sub_48C6B0(v5, v4);
    v7 = v6;
    v8 = *(unsigned __int8*)(a2 + 443);
    v17 = v8;
    ++v7;
    v9 = *(_DWORD*)(v2 + 12);
    v10 = v5 * v8 / v7;
    v11 = *(_DWORD*)(v2 + 16);
    v16 = v9 + v10;
    v12 = *(_WORD*)(v2 + 432);
    v13 = v9 - v12;
    v14 = v11 + v4 * v17 / v7;
    if (v7 <= 10
        || v13 * (v16 - v12) + (v11 - *(unsigned __int16*)(v2 + 434)) * (v14 - *(unsigned __int16*)(v2 + 434)) < 0)
    {
        sub_45A4E0(v2);
        result = 0;
    }
    else
    {
        sub_49AA90((_DWORD*)v2, v16, v14);
        result = 1;
    }
    return result;
}
// 4CA67E: variable 'v6' is possibly undefined

//----- (004CA720) --------------------------------------------------------
int __cdecl sub_4CA720(int a1, int a2)
{
    int v2; // ebx
    int v3; // ebp
    int v4; // ecx
    int v5; // edx
    int v6; // ebx
    int v7; // kr00_4
    int v8; // ebx
    int result; // eax

    v2 = *(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 316);
    if (v2 >= 60
        || (v3 = *(unsigned __int16*)(a2 + 432), abs32(*(_DWORD*)(a2 + 12) - (unsigned __int16)v3) < 10)
        && abs32(*(_DWORD*)(a2 + 16) - *(unsigned __int16*)(a2 + 434)) < 10)
    {
        sub_45A4E0(a2);
        result = 0;
    }
    else
    {
        v4 = *(__int16*)(a2 + 440) - v2 * *(__int16*)(a2 + 440) / 60;
        v5 = (v2 << 8) / 120;
        if (*(_BYTE*)(a2 + 443))
            v6 = v5 + *(unsigned __int8*)(a2 + 442);
        else
            v6 = *(unsigned __int8*)(a2 + 442) - v5;
        if (v6 < 0)
            v6 += (unsigned int)(255 - v6) >> 8 << 8;
        if (v6 >= 256)
            v6 += -256 * ((unsigned int)v6 >> 8);
        v7 = v4 * *(int*)& byte_587000[8 * v6 + 192088];
        v8 = *(unsigned __int16*)(a2 + 434) + v4 * *(_DWORD*)& byte_587000[8 * v6 + 192092] / 16;
        sub_49AA90((_DWORD*)a2, v3 + v7 / 16, v8);
        *(_DWORD*)(a2 + 32) = v3 + v7 / 16;
        *(_DWORD*)(a2 + 36) = v8;
        result = 1;
    }
    return result;
}

//----- (004CA860) --------------------------------------------------------
int sub_4CA860()
{
    unsigned __int8* v0; // esi
    __int64 v1; // rax
    int v3; // [esp+4h] [ebp-4h]

    v3 = 0;
    v0 = &byte_5D4594[1322584];
    do
    {
        v1 = (__int64)(atan2((double)v3 * *(double*)& byte_581450[9960], 1.0) * *(double*)& byte_581450[9952]
            + *(double*)& byte_581450[9544]);
        *(_WORD*)v0 = v1;
        v0 += 2;
        ++v3;
    } while ((int)v0 < (int)& byte_5D4594[1522584]);
    return v1;
}

//----- (004CA8B0) --------------------------------------------------------
int __cdecl sub_4CA8B0(int a1, int a2)
{
    int v2; // ecx
    int result; // eax
    int v4; // eax
    int v5; // eax
    char v6; // [esp+4h] [ebp+4h]

    v2 = a2;
    if (!a2)
        return a1 <= 0 ? 56250 : 18750;
    v4 = a1;
    if (a2 >= 0)
    {
        if (a1 >= 0)
        {
            v6 = 1;
        }
        else
        {
            v6 = 4;
            v4 = -v4;
        }
    }
    else
    {
        if (a1 >= 0)
        {
            v6 = 2;
        }
        else
        {
            v4 = -a1;
            v6 = 3;
        }
        v2 = -a2;
    }
    v5 = 1000 * v4 / v2;
    if (v5 >= 100000)
        v5 = 99999;
    result = *(__int16*)& byte_5D4594[2 * v5 + 1322584];
    switch (v6)
    {
    case 2:
        return 37500 - result;
    case 3:
        result += 37500;
        break;
    case 4:
        result = 75000 - result;
        break;
    }
    return result;
}

//----- (004CA960) --------------------------------------------------------
void __cdecl sub_4CA960(_DWORD* a1, char a2, float4* a3, float2* a4)
{
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // [esp-8h] [ebp-10h]
    int2 a1a; // [esp+0h] [ebp-8h]

    v4 = a1[1];
    a1a.field_0 = 23 * *a1;
    a1a.field_4 = 23 * v4;
    switch (a2)
    {
    case 1:
        v6 = sub_419A70(11.5);
        sub_4CAA90(&a1a, a3, a4, v6, 23);
        break;
    case 2:
        v5 = sub_419A70(11.5);
        sub_4CAC30(&a1a, a3, a4, 0, v5);
        break;
    case 4:
        v8 = sub_419A70(11.5);
        sub_4CAC30(&a1a, a3, a4, v8, 23);
        break;
    case 6:
        sub_4CAC30(&a1a, a3, a4, 0, 23);
        break;
    case 8:
        v7 = sub_419A70(11.5);
        sub_4CAA90(&a1a, a3, a4, 0, v7);
        break;
    case 9:
        sub_4CAA90(&a1a, a3, a4, 0, 23);
        break;
    default:
        return;
    }
}

//----- (004CAA90) --------------------------------------------------------
void __cdecl sub_4CAA90(int2* a1, float4* a2, float2* a3, int a4, int a5)
{
    int v5; // eax
    int v6; // edx
    double v7; // st6
    int v8; // eax
    double v9; // st7
    double v11; // st7
    double v13; // st7
    double v14; // st5
    double v15; // st7
    double v16; // st7
    double v17; // st7
    float v18; // [esp+8h] [ebp-24h]
    float v19; // [esp+Ch] [ebp-20h]
    float v20; // [esp+10h] [ebp-1Ch]
    double v21; // [esp+14h] [ebp-18h]
    float v22; // [esp+1Ch] [ebp-10h]
    float v23; // [esp+24h] [ebp-8h]

    v5 = a5 + a1->field_0;
    v6 = a1->field_4 - a5 + 22;
    v22 = (double)(a1->field_0 + a4);
    v7 = (double)v5;
    v23 = v7;
    v18 = v7 + (double)v6;
    v8 = sub_419A70(v18);
    if (a2->field_8 == a2->field_0)
    {
        v9 = a2->field_8;
        a3->field_0 = a2->field_8;
        a3->field_4 = (double)v8 - v9;
    }
    else
    {
        v11 = a2->field_C;
        if (v11 == a2->field_4)
        {
            a3->field_4 = a2->field_C;
            a3->field_0 = (double)v8 - v11;
        }
        else
        {
            v13 = (v11 - a2->field_4) / (a2->field_8 - a2->field_0);
            if (v13 == -1.0)
                v13 = -0.99000001;
            v14 = (double)v8;
            v20 = v14;
            v15 = sub_419AF0((v14 - (a2->field_4 - v13 * a2->field_0)) / (v13 + *(double*)& byte_581450[9512]));
            v16 = modf(v15, &v21);
            v19 = sub_419AF0(v16);
            v17 = sub_419AF0(v21);
            a3->field_0 = v17;
            if (v19 <= *(double*)& byte_581450[9544])
            {
                if (v19 < *(double*)& byte_581450[9968])
                    a3->field_0 = v17 - 1.0;
            }
            else
            {
                a3->field_0 = v17 + 1.0;
            }
            if (a3->field_0 >= (double)v22)
            {
                if (a3->field_0 > (double)v23)
                    a3->field_0 = v23;
                a3->field_4 = v20 - a3->field_0;
            }
            else
            {
                a3->field_0 = v22;
                a3->field_4 = v20 - a3->field_0;
            }
        }
    }
}

//----- (004CAC30) --------------------------------------------------------
void __cdecl sub_4CAC30(int2* a1, float4* a2, float2* a3, int a4, int a5)
{
    int v5; // ecx
    int v6; // eax
    int v7; // eax
    double v8; // st7
    double v9; // st5
    double v10; // st7
    double v11; // st7
    double v12; // st7
    float v13; // [esp+8h] [ebp-2Ch]
    float v14; // [esp+14h] [ebp-20h]
    float v15; // [esp+18h] [ebp-1Ch]
    double v16; // [esp+1Ch] [ebp-18h]
    float v17; // [esp+24h] [ebp-10h]
    float v18; // [esp+2Ch] [ebp-8h]

    v5 = a4 + a1->field_4;
    v6 = a5 + a1->field_0;
    v17 = (double)(a1->field_0 + a4);
    v18 = (double)v6;
    v13 = (double)v5 - v17;
    v7 = sub_419A70(v13);
    if (a2->field_8 == a2->field_0)
    {
        a3->field_0 = a2->field_8;
        a3->field_4 = (double)v7 + a2->field_8;
    }
    else if (a2->field_C == a2->field_4)
    {
        a3->field_0 = a2->field_C - (double)v7;
        a3->field_4 = a2->field_C;
    }
    else
    {
        v8 = (a2->field_C - a2->field_4) / (a2->field_8 - a2->field_0);
        if (v8 == 1.0)
            v8 = 0.99000001;
        v9 = (double)v7;
        v15 = v9;
        v10 = sub_419AF0((v9 - (a2->field_4 - v8 * a2->field_0)) / (v8 - *(double*)& byte_581450[9512]));
        v11 = modf(v10, &v16);
        v14 = sub_419AF0(v11);
        v12 = sub_419AF0(v16);
        a3->field_0 = v12;
        if (v14 <= *(double*)& byte_581450[9544])
        {
            if (v14 < *(double*)& byte_581450[9968])
                a3->field_0 = v12 - 1.0;
        }
        else
        {
            a3->field_0 = v12 + 1.0;
        }
        if (a3->field_0 >= (double)v17)
        {
            if (a3->field_0 > (double)v18)
                a3->field_0 = v18;
            a3->field_4 = v15 + a3->field_0;
        }
        else
        {
            a3->field_0 = v17;
            a3->field_4 = v15 + a3->field_0;
        }
    }
}

//----- (004CADD0) --------------------------------------------------------
int sub_4CADD0()
{
    int result; // eax
    int v1; // esi
    _DWORD* v2; // eax

    result = *(_DWORD*)& byte_5D4594[1522584];
    if (!*(_DWORD*)& byte_5D4594[1522584])
    {
        v1 = 0;
        do
        {
            v2 = nox_calloc(1u, 0x3Cu);
            if (!v2)
                nox_exit(-1);
            ++v1;
            v2[4] = *(_DWORD*)& byte_5D4594[1522584];
            *(_DWORD*)& byte_5D4594[1522584] = v2;
            v2[2] = *(_DWORD*)& byte_5D4594[1522592];
            *(_DWORD*)& byte_5D4594[1522592] = v2;
        } while (v1 < 10);
        *(_DWORD*)& byte_5D4594[1522588] += 10;
        result = *(_DWORD*)& byte_5D4594[1522584];
    }
    *(_DWORD*)& byte_5D4594[1522584] = *(_DWORD*)(result + 16);
    return result;
}

//----- (004CAE40) --------------------------------------------------------
int __cdecl sub_4CAE40(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 16) = *(_DWORD*)& byte_5D4594[1522584];
    *(_DWORD*)& byte_5D4594[1522584] = a1;
    return result;
}

//----- (004CAE60) --------------------------------------------------------
int sub_4CAE60()
{
    int result; // eax
    int v1; // ecx

    result = *(_DWORD*)& byte_5D4594[1522592];
    v1 = 0;
    for (*(_DWORD*)& byte_5D4594[1522584] = 0; result; result = *(_DWORD*)(result + 8))
    {
        *(_DWORD*)(result + 16) = v1;
        v1 = result;
        *(_DWORD*)& byte_5D4594[1522584] = result;
    }
    return result;
}

//----- (004CAE90) --------------------------------------------------------
int __cdecl sub_4CAE90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 12) = *(_DWORD*)& byte_5D4594[1522596];
    *(_DWORD*)& byte_5D4594[1522596] = a1;
    return result;
}

//----- (004CAEB0) --------------------------------------------------------
int sub_4CAEB0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1522596];
    if (*(_DWORD*)& byte_5D4594[1522596])
        * (_DWORD*)& byte_5D4594[1522596] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522596] + 12);
    return result;
}

//----- (004CAED0) --------------------------------------------------------
int __cdecl sub_4CAED0(int a1)
{
    int result; // eax

    result = sub_4CADD0();
    *(_DWORD*)(result + 24) = *(_DWORD*)(a1 + 24);
    *(_DWORD*)(result + 28) = *(_DWORD*)(a1 + 28);
    *(_DWORD*)(result + 32) = *(_DWORD*)(a1 + 32);
    *(_BYTE*)(result + 36) = *(_BYTE*)(a1 + 36);
    *(_DWORD*)(result + 40) = *(_DWORD*)(a1 + 40);
    *(_DWORD*)(result + 44) = *(_DWORD*)(a1 + 44);
    *(_BYTE*)(result + 48) = *(_BYTE*)(a1 + 48);
    *(_BYTE*)(result + 56) = *(_BYTE*)(a1 + 56);
    *(_DWORD*)(result + 20) = *(_DWORD*)(a1 + 20);
    return result;
}

//----- (004CAF10) --------------------------------------------------------
_DWORD* __cdecl sub_4CAF10(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7)
{
    int v7; // eax
    _DWORD* v8; // esi

    v7 = a7[2];
    if (!(v7 & 0x1000))
        return 0;
    v8 = nox_window_new(a1, a2 & 0xFFFFFFF7, a3, a4, a5, a6, sub_4CAF80);
    sub_4CAFB0((int)v8);
    if (v8)
    {
        if (!a7[4])
            a7[4] = v8;
        sub_46AF80_copy_window_part((int)v8, a7);
    }
    return v8;
}

//----- (004CAF80) --------------------------------------------------------
int __cdecl sub_4CAF80(int a1, int a2, int a3, int a4)
{
    if (a2 == 16416 && a3 >= 0 && a3 <= 100)
        * (_DWORD*)(a1 + 32) = a3;
    return 0;
}

//----- (004CAFB0) --------------------------------------------------------
int __cdecl sub_4CAFB0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
            result = nox_window_set_all_funcs((_DWORD*)a1, 0, sub_4CAFF0, 0);
        else
            result = nox_window_set_all_funcs((_DWORD*)a1, 0, sub_4CB1A0, 0);
    }
    return result;
}

//----- (004CAFF0) --------------------------------------------------------
int __cdecl sub_4CAFF0(_DWORD* a1, _DWORD* a2)
{
    int v2; // ecx
    int v3; // ebp
    int v4; // edi
    int v5; // edi
    int v6; // edi
    int v7; // ebp
    int xLeft; // [esp+10h] [ebp-98h]
    int yTop; // [esp+14h] [ebp-94h]
    int v11; // [esp+18h] [ebp-90h]
    int v12; // [esp+1Ch] [ebp-8Ch]
    int v13; // [esp+20h] [ebp-88h]
    int v14; // [esp+24h] [ebp-84h]
    wchar_t v15[64]; // [esp+28h] [ebp-80h]

    v2 = a2[17];
    v3 = a2[9];
    v14 = a2[7];
    v4 = a2[5];
    v11 = v2;
    sub_46AA60(a1, &xLeft, &yTop);
    if (v4 != 0x80000000)
    {
        sub_434460(v4);
        sub_49CE30(xLeft, yTop, a1[2], a1[3]);
    }
    if (v3 != 0x80000000)
    {
        v5 = a1[2] * a1[8] / 100;
        sub_434460(v3);
        sub_49CE30(xLeft, yTop, v5, a1[3]);
    }
    if (v11 != 0x80000000)
    {
        if ((a1[1] & 0x2000) == 0x2000)
            sub_43F670(1);
        nox_swprintf(v15, L"%i%%", a1[8]);
        sub_43F840(a2[50], v15, &v13, &v12, 64);
        v6 = xLeft + a1[2] / 2 - v13 / 2;
        v7 = a1[3] / 2 - v12 / 2 + yTop + 1;
        sub_434390(v11);
        sub_43FAF0(a2[50], v15, v6, v7, a1[2], 0);
        sub_43F670(0);
    }
    if (v14 != 0x80000000)
    {
        sub_434460(v14);
        sub_49CC70(xLeft, yTop, a1[2], a1[3]);
    }
    return 1;
}

//----- (004CB1A0) --------------------------------------------------------
int __cdecl sub_4CB1A0(_DWORD* a1, int a2)
{
    int v2; // ebx
    _DWORD* v3; // esi
    int v4; // edi
    int xLeft; // [esp+Ch] [ebp-8h]
    int yTop; // [esp+10h] [ebp-4h]

    v2 = *(_DWORD*)(a2 + 24);
    v3 = a1;
    sub_46AA60(a1, &xLeft, &yTop);
    sub_49F7F0();
    v4 = v3[2] * v3[8] / 100;
    sub_49F6F0(xLeft, yTop, v4, v3[3]);
    if (v2 && v4 > 0)
        sub_47D2C0(v2, xLeft, yTop);
    sub_49F860();
    return 1;
}

//----- (004CB230) --------------------------------------------------------
BOOL __cdecl sub_4CB230(const char* a1, char* lpFileName)
{
    char* v3; // eax
    struct _stat v4; // [esp+10h] [ebp-24h]

    strcpy(lpFileName, "movies\\");
    strcat(lpFileName, a1);
    if (!_stat(lpFileName, (int)& v4))
        return 1;
    v3 = sub_413890();
    if (!v3)
        return 0;
    strcpy(lpFileName, v3);
    strcat(lpFileName, "movies\\");
    strcat(lpFileName, a1);
    return _stat(lpFileName, (int)& v4) == 0;
}

//----- (004CB330) --------------------------------------------------------
_DWORD* sub_4CB330()
{
    _DWORD* v0; // eax
    int v1; // ecx
    unsigned int v2; // ecx
    _DWORD* v3; // eax
    int v4; // ecx
    unsigned int v5; // ecx
    _DWORD* v6; // eax
    int v7; // ecx
    unsigned int v8; // ecx
    _DWORD* v9; // eax
    int v10; // ecx
    unsigned int v11; // ecx
    _DWORD* v12; // eax
    int v13; // ecx
    unsigned int v14; // ecx
    _DWORD* v15; // eax
    int v16; // ecx
    unsigned int v17; // ecx
    _DWORD* v18; // eax
    int v19; // ecx
    unsigned int v20; // ecx
    _DWORD* v21; // eax
    int v22; // ecx
    unsigned int v23; // ecx
    _DWORD* v24; // eax
    int v25; // ecx
    unsigned int v26; // ecx
    _DWORD* v27; // eax
    int v28; // ecx
    unsigned int v29; // ecx
    _DWORD* v30; // eax
    int v31; // ecx
    unsigned int v32; // ecx
    _DWORD* v33; // eax
    int v34; // ecx
    unsigned int v35; // ecx
    _DWORD* v36; // eax
    int v37; // ecx
    unsigned int v38; // ecx
    _DWORD* result; // eax
    int v40; // ecx

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2010);
    v1 = v0[9];
    if (*(_DWORD*)& byte_5D4594[805868])
        v2 = v1 | 4;
    else
        v2 = v1 & 0xFFFFFFFB;
    v0[9] = v2;
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2012);
    v4 = v3[9];
    if (byte_5D4594[2650637] & 4)
        v5 = v4 | 4;
    else
        v5 = v4 & 0xFFFFFFFB;
    v3[9] = v5;
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2020);
    v7 = v6[9];
    if (*(_DWORD*)& byte_587000[80812])
        v8 = v7 | 4;
    else
        v8 = v7 & 0xFFFFFFFB;
    v6[9] = v8;
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2021);
    v10 = v9[9];
    if (*(_DWORD*)& byte_5D4594[805844])
        v11 = v10 | 4;
    else
        v11 = v10 & 0xFFFFFFFB;
    v9[9] = v11;
    v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2022);
    v13 = v12[9];
    if (*(_DWORD*)& byte_587000[80820])
        v14 = v13 | 4;
    else
        v14 = v13 & 0xFFFFFFFB;
    v12[9] = v14;
    v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2031);
    v16 = v15[9];
    if (*(_DWORD*)& byte_587000[154952])
        v17 = v16 | 4;
    else
        v17 = v16 & 0xFFFFFFFB;
    v15[9] = v17;
    v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2032);
    v19 = v18[9];
    if (*(_DWORD*)& byte_5D4594[1193152])
        v20 = v19 | 4;
    else
        v20 = v19 & 0xFFFFFFFB;
    v18[9] = v20;
    v21 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2014);
    v22 = v21[9];
    if (*(_DWORD*)& byte_587000[80824])
        v23 = v22 | 4;
    else
        v23 = v22 & 0xFFFFFFFB;
    v21[9] = v23;
    v24 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2015);
    v25 = v24[9];
    if (*(_DWORD*)& byte_5D4594[805852])
        v26 = v25 | 4;
    else
        v26 = v25 & 0xFFFFFFFB;
    v24[9] = v26;
    v27 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2040);
    v28 = v27[9];
    if (*(_DWORD*)& byte_587000[80828])
        v29 = v28 | 4;
    else
        v29 = v28 & 0xFFFFFFFB;
    v27[9] = v29;
    v30 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2016);
    v31 = v30[9];
    if (*(_DWORD*)& byte_587000[80836])
        v32 = v31 | 4;
    else
        v32 = v31 & 0xFFFFFFFB;
    v30[9] = v32;
    v33 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2017);
    v34 = v33[9];
    if (*(_DWORD*)& byte_587000[80840])
        v35 = v34 | 4;
    else
        v35 = v34 & 0xFFFFFFFB;
    v33[9] = v35;
    v36 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2041);
    v37 = v36[9];
    if (*(_DWORD*)& byte_587000[80844])
        v38 = v37 | 4;
    else
        v38 = v37 & 0xFFFFFFFB;
    v36[9] = v38;
    result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522600], 2033);
    v40 = result[9];
    if (*(_DWORD*)& byte_587000[154960])
        result[9] = v40 | 4;
    else
        result[9] = v40 & 0xFFFFFFFB;
    return result;
}

//----- (004CB590) --------------------------------------------------------
int __cdecl sub_4CB590(int a1)
{
    *(_DWORD*)& byte_5D4594[1522600] = nox_new_window_from_file("advidopt.wnd", sub_4CB5D0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1522600], a1);
    sub_46A8A0();
    sub_4CB330();
    return 1;
}

//----- (004CB5D0) --------------------------------------------------------
int __cdecl sub_4CB5D0(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int v4; // eax
    int result; // eax
    int v6; // ecx
    unsigned int v7; // ecx
    int v8; // eax

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        result = 1;
    }
    else if (a2 == 16391)
    {
        v3 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        switch (v3)
        {
        case 2010:
            *(_DWORD*)& byte_5D4594[805868] = sub_48A1D0(1 - *(_DWORD*)& byte_5D4594[805868]);
            v6 = *(_DWORD*)(a1 + 36);
            if (*(_DWORD*)& byte_5D4594[805868])
                v7 = v6 | 4;
            else
                v7 = v6 & 0xFFFFFFFB;
            *(_DWORD*)(a1 + 36) = v7;
            result = 0;
            break;
        case 2012:
            *(_DWORD*)& byte_5D4594[2650636] ^= 0x400u;
            result = 0;
            break;
        case 2014:
            *(_DWORD*)& byte_587000[80824] = 1 - *(_DWORD*)& byte_587000[80824];
            result = 0;
            break;
        case 2015:
            result = 0;
            *(_DWORD*)& byte_5D4594[805852] = 1 - *(_DWORD*)& byte_5D4594[805852];
            break;
        case 2016:
            result = 0;
            *(_DWORD*)& byte_587000[80836] = 1 - *(_DWORD*)& byte_587000[80836];
            break;
        case 2017:
            *(_DWORD*)& byte_587000[80840] = 1 - *(_DWORD*)& byte_587000[80840];
            result = 0;
            break;
        case 2020:
            *(_DWORD*)& byte_587000[80812] = 1 - *(_DWORD*)& byte_587000[80812];
            sub_49B3C0();
            result = 0;
            break;
        case 2021:
            result = 0;
            *(_DWORD*)& byte_5D4594[805844] = 1 - *(_DWORD*)& byte_5D4594[805844];
            break;
        case 2022:
            *(_DWORD*)& byte_587000[80820] = 1 - *(_DWORD*)& byte_587000[80820];
            result = 0;
            break;
        case 2031:
            result = 0;
            *(_DWORD*)& byte_587000[154952] = 1 - *(_DWORD*)& byte_587000[154952];
            break;
        case 2032:
            result = 0;
            *(_DWORD*)& byte_5D4594[1193152] = 1 - *(_DWORD*)& byte_5D4594[1193152];
            break;
        case 2033:
            *(_DWORD*)& byte_587000[154960] = 1 - *(_DWORD*)& byte_587000[154960];
            *(_DWORD*)& byte_587000[154956] = *(_DWORD*)& byte_587000[154960];
            sub_481420();
            *(_DWORD*)& byte_5D4594[1193156] = 0;
            result = 0;
            break;
        case 2040:
            v8 = 1 - *(_DWORD*)& byte_587000[80828];
            *(_DWORD*)& byte_587000[80828] = v8;
            *(_DWORD*)& byte_587000[80832] = v8;
            result = 0;
            break;
        case 2041:
            *(_DWORD*)& byte_587000[80844] = 1 - *(_DWORD*)& byte_587000[80844];
            goto LABEL_23;
        case 2099:
            sub_4445C0();
            sub_4CB330();
            v4 = *(_DWORD*)(a1 + 396);
            if (!v4)
                goto LABEL_23;
            nox_window_call_field_94(v4, 16391, (int)a3, 0);
            result = 0;
            break;
        default:
            goto LABEL_23;
        }
    }
    else
    {
    LABEL_23:
        result = 0;
    }
    return result;
}

//----- (004CB880) --------------------------------------------------------
int sub_4CB880()
{
    int result; // eax
    _DWORD** v1; // eax
    _DWORD* v2; // esi
    _DWORD* v3; // esi
    int v4; // esi
    int v5; // edi
    _DWORD* v6; // eax
    int v7; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax

    sub_43BDD0(900);
    result = nox_new_window_from_file("InputCfg.wnd", sub_4CBE70);
    *(_DWORD*)& byte_5D4594[1522604] = result;
    if (result)
    {
        sub_46B300(result, sub_4A18E0);
        result = sub_43C5B0(*(_DWORD * *)& byte_5D4594[1522604], 0, 0, 0, -480, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[1522608] = result;
        if (result)
        {
            *(_DWORD*)result = 900;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522608] + 48) = sub_4CBB70;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522608] + 56) = sub_4CBBB0;
            *(_DWORD*)& byte_5D4594[1522616] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 910);
            *(_DWORD*)& byte_5D4594[1522620] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 911);
            *(_DWORD*)& byte_5D4594[1522624] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 912);
            *(_DWORD*)& byte_5D4594[1522628] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 913);
            result = *(_DWORD*)& byte_5D4594[1522616];
            if (*(_DWORD*)& byte_5D4594[1522616])
            {
                v1 = *(_DWORD * **)(*(_DWORD*)& byte_5D4594[1522616] + 32);
                *v1[7] = 921;
                *v1[8] = 922;
                *v1[9] = 920;
                sub_46B2C0(*(int*)& byte_5D4594[1522616], sub_4CBF60);
                sub_46B120(*(_DWORD * *)& byte_5D4594[1522620], *(int*)& byte_5D4594[1522616]);
                sub_46B120(*(_DWORD * *)& byte_5D4594[1522624], *(int*)& byte_5D4594[1522616]);
                sub_46B120(*(_DWORD * *)& byte_5D4594[1522628], *(int*)& byte_5D4594[1522616]);
                sub_46B300(*(int*)& byte_5D4594[1522624], sub_4CC140);
                sub_46B300(*(int*)& byte_5D4594[1522628], sub_4CC140);
                v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 921);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16408, (int)v2, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16408, (int)v2, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16408, (int)v2, 0);
                v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 922);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16409, (int)v3, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16409, (int)v3, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16409, (int)v3, 0);
                sub_4CBBF0();
                v4 = 971;
                v5 = sub_47DBC0() + 971;
                if (v5 > 971)
                {
                    do
                    {
                        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], v4);
                        sub_46ABB0((int)v6, 1);
                        ++v4;
                    } while (v4 < v5);
                }
                v7 = sub_430AF0();
                v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], v7 + 971);
                nox_window_call_field_94((int)v8, 16392, 1, 0);
                *(_DWORD*)& byte_5D4594[1522612] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 980);
                sub_46B120(*(_DWORD * *)& byte_5D4594[1522612], 0);
                sub_46B2C0(*(int*)& byte_5D4594[1522612], sub_4CBE70);
                sub_46B300(*(int*)& byte_5D4594[1522612], sub_4CC170);
                nox_window_set_hidden(*(int*)& byte_5D4594[1522612], 1);
                v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522612], 981);
                sub_46AEE0((int)v9, (int)& byte_5D4594[1522636]);
                result = 1;
            }
        }
    }
    return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004CBB70) --------------------------------------------------------
int sub_4CBB70()
{
    sub_4CBD30();
    sub_433290((char*)& byte_587000[187536]);
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[1522608] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004CBBB0) --------------------------------------------------------
int sub_4CBBB0()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[1522608] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[1522608]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1522604]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1522612]);
    v0();
    return 1;
}

//----- (004CBBF0) --------------------------------------------------------
char* sub_4CBBF0()
{
    char* result; // eax
    int* v1; // esi
    char* v2; // edi
    char* v3; // ebx

    nox_window_call_field_94(*(int*)& byte_5D4594[1522616], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16399, 0, 0);
    result = *(char**)& byte_587000[75892];
    if (*(_DWORD*)& byte_587000[75892])
    {
        v1 = (int*)& byte_587000[75896];
        do
        {
            if (*v1 != 44)
            {
                nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16397, v1[1], -1);
                nox_window_call_field_94(*(int*)& byte_5D4594[1522616], 16397, (int)& byte_587000[187544], -1);
                v2 = sub_42E8E0(*v1, 1);
                v3 = sub_42E8E0(*v1, 2);
                if (v2 && *(_WORD*)v2)
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16397, (int)v2, -1);
                else
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16397, (int)& byte_587000[187548], -1);
                if (v3 && *(_WORD*)v3 && v2 != v3)
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16397, (int)v3, -1);
                else
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16397, (int)& byte_587000[187552], -1);
            }
            result = (char*)v1[2];
            v1 += 3;
        } while (result);
    }
    return result;
}

//----- (004CBD30) --------------------------------------------------------
char* sub_4CBD30()
{
    int v0; // ebp
    int i; // esi
    wchar_t* v2; // eax
    int v3; // edi
    wchar_t* v4; // eax
    char* v5; // ebx
    wchar_t* v6; // eax
    char* v7; // eax
    wchar_t* v8; // eax
    int v9; // esi
    wchar_t* v10; // eax
    char* result; // eax
    char v12[256]; // [esp+8h] [ebp-100h]

    v0 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522620] + 32);
    sub_42CD90();
    for (i = 0; i < *(__int16*)(v0 + 44); ++i)
    {
        v2 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16406, i, 0);
        v3 = sub_42EA40(v2);
        v4 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16406, i, 0);
        v5 = sub_42E960(v4);
        v6 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16406, i, 0);
        v7 = sub_42E960(v6);
        if (v7)
        {
            nox_sprintf(v12, "%s = %s", v7, v3);
            sub_42CF50(v12);
        }
        if (v5)
        {
            nox_sprintf(v12, "%s = %s", v5, v3);
            sub_42CF50(v12);
        }
    }
    v8 = loadString_sub_40F1D0((char*)& byte_587000[187620], 0, "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 192);
    v9 = sub_42EA40(v8);
    v10 = loadString_sub_40F1D0((char*)& byte_587000[187696], 0, "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 193);
    result = sub_42E960(v10);
    if (result)
    {
        nox_sprintf(v12, "%s = %s", result, v9);
        result = (char*)sub_42CF50(v12);
    }
    return result;
}

//----- (004CBE70) --------------------------------------------------------
int __cdecl sub_4CBE70(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int result; // eax

    if (a2 == 23)
        return 1;
    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(921, 100);
    switch (v3)
    {
    case 931:
        sub_42CD90();
        sub_4317B0((char*)& byte_587000[187716], 1);
        sub_4CBBF0();
        result = 0;
        break;
    case 932:
        sub_4CBD30();
        result = 0;
        break;
    case 933:
        sub_4CBF40();
        result = 0;
        break;
    case 971:
    case 972:
    case 973:
        sub_430AA0(v3 - 971);
        return 0;
    default:
        return 0;
    }
    return result;
}

//----- (004CBF40) --------------------------------------------------------
char* sub_4CBF40()
{
    sub_42CD90();
    sub_4317B0((char*)& byte_587000[187724], 1);
    return sub_4CBBF0();
}

//----- (004CBF60) --------------------------------------------------------
int __cdecl sub_4CBF60(int a1, unsigned int a2, int a3, int a4)
{
    int v5; // eax
    wchar_t* v6; // eax
    int v7; // esi
    int v8; // esi
    int v9; // [esp-4h] [ebp-10h]

    if (a2 > 0x4007)
    {
        if (a2 == 16393)
        {
            v7 = *(_DWORD*)(a1 + 32);
            sub_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
            v8 = sub_4A4800(v7);
            nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16412, v8, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16412, v8, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16412, v8, 0);
        }
        else if (a2 == 16400)
        {
            v5 = *(_DWORD*)(a3 + 32);
            if ((int) * (_DWORD*)(v5 + 48) >= 0)
            {
                *(_DWORD*)& byte_5D4594[1522632] = a3;
                v9 = nox_window_call_field_94(*(int*)& byte_5D4594[1522620], 16406, *(_DWORD*)(v5 + 48), 0);
                v6 = loadString_sub_40F1D0((char*)& byte_587000[187784], 0, "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 424);
                nox_swprintf((wchar_t*)& byte_5D4594[1522636], L"%s\n'%s'", v6, v9);
                sub_46A8C0(*(int*)& byte_5D4594[1522612]);
                sub_46B500(*(int*)& byte_5D4594[1522612]);
                sub_46C690(*(int*)& byte_5D4594[1522612]);
                return sub_4A30D0(a1, 0x4010u, (wchar_t*)a3, a4);
            }
        }
    }
    else
    {
        if (a2 != 16391)
        {
            if (a2 == 23)
                return 1;
            if (a2 != 0x4000)
                return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
        }
        if ((_DWORD*)a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 921)
            || (_DWORD*)a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522604], 922))
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1522620], a2, a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1522624], a2, a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1522628], a2, a3, 0);
            return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
        }
    }
    return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
}

//----- (004CC140) --------------------------------------------------------
int __cdecl sub_4CC140(_DWORD* a1, unsigned int a2, unsigned int a3, int a4)
{
    int result; // eax

    if (a2 < 0x13 || a2 > 0x14)
        result = sub_4A28E0(a1, a2, a3, a4);
    else
        result = 0;
    return result;
}

//----- (004CC170) --------------------------------------------------------
int __cdecl sub_4CC170(int a1, int a2, char* a3, int a4)
{
    int result; // eax

    switch (a2)
    {
    case 6:
    case 7:
        goto LABEL_10;
    case 10:
    case 11:
        sub_4CC3C0((char*)0x10002);
        goto LABEL_15;
    case 14:
    case 15:
        sub_4CC3C0((char*)0x10001);
        goto LABEL_15;
    case 19:
        sub_4CC3C0((char*)0x10003);
        goto LABEL_15;
    case 20:
        sub_4CC3C0((char*)0x10004);
        goto LABEL_15;
    case 21:
        if (a3 == (char*)1)
        {
            if (a4 == 2)
            {
                sub_46B500(0);
                sub_46C6E0(*(int*)& byte_5D4594[1522612]);
                nox_window_set_hidden(*(int*)& byte_5D4594[1522612], 1);
                if (*(_DWORD*)& byte_5D4594[1522632])
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522632], 16403, -1, 0);
            }
            result = 1;
        }
        else if (a4 == 1 && sub_4CC280(a3))
        {
        LABEL_10:
            sub_4CC3C0((char*)0x10000);
        LABEL_15:
            sub_46B500(0);
            sub_46C6E0(*(int*)& byte_5D4594[1522612]);
            nox_window_set_hidden(*(int*)& byte_5D4594[1522612], 1);
            result = 1;
        }
        else
        {
        LABEL_5:
            result = 0;
        }
        return result;
    default:
        goto LABEL_5;
    }
}

//----- (004CC280) --------------------------------------------------------
int __cdecl sub_4CC280(char* a1)
{
    int v1; // ecx
    unsigned __int8* v2; // eax
    int v3; // esi
    int v4; // ecx
    const wchar_t* v6; // edi
    int v7; // esi
    int v8; // ebx
    const wchar_t* v9; // eax
    int v10; // esi
    int v11; // ebx
    const wchar_t* v12; // eax

    v1 = 0;
    if (*(_DWORD*)& byte_587000[73672])
    {
        v2 = &byte_587000[73672];
        do
        {
            if (*((char**)v2 + 1) == a1)
                break;
            v3 = *((_DWORD*)v2 + 4);
            v2 += 16;
            ++v1;
        } while (v3);
    }
    v4 = 16 * v1;
    if (!*(_DWORD*)& byte_587000[v4 + 73672])
        return 0;
    v6 = *(const wchar_t**)& byte_587000[v4 + 73684];
    if (*(_DWORD*)& byte_5D4594[1522632])
    {
        v7 = 0;
        v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522624] + 32);
        if (*(_WORD*)(v8 + 44) > 0)
        {
            do
            {
                v9 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16406, v7, 0);
                if (!nox_wcscmp(v9, v6))
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16407, (int)& byte_587000[187824], v7);
                ++v7;
            } while (v7 < *(__int16*)(v8 + 44));
        }
        v10 = 0;
        v11 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522628] + 32);
        if (*(_WORD*)(v11 + 44) > 0)
        {
            do
            {
                v12 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16406, v10, 0);
                if (!nox_wcscmp(v12, v6))
                    nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16407, (int)& byte_587000[187828], v10);
                ++v10;
            } while (v10 < *(__int16*)(v11 + 44));
        }
        nox_window_call_field_94(
            *(int*)& byte_5D4594[1522632],
            16407,
            (int)v6,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1522632] + 32) + 48));
        nox_window_call_field_94(*(int*)& byte_5D4594[1522632], 16403, -1, 0);
        *(_DWORD*)& byte_5D4594[1522632] = 0;
    }
    return 1;
}

//----- (004CC3C0) --------------------------------------------------------
int __cdecl sub_4CC3C0(char* a1)
{
    char* v1; // edi
    int v2; // esi
    int v3; // ebx
    const wchar_t* v4; // eax
    int v5; // esi
    int v6; // ebx
    const wchar_t* v7; // eax

    v1 = sub_42EA00(a1);
    if (!*(_DWORD*)& byte_5D4594[1522632])
        return 1;
    v2 = 0;
    v3 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522624] + 32);
    if (*(_WORD*)(v3 + 44) > 0)
    {
        do
        {
            v4 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16406, v2, 0);
            if (!nox_wcscmp(v4, (const wchar_t*)v1))
                nox_window_call_field_94(*(int*)& byte_5D4594[1522624], 16407, (int)& byte_587000[187832], v2);
            ++v2;
        } while (v2 < *(__int16*)(v3 + 44));
    }
    v5 = 0;
    v6 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1522628] + 32);
    if (*(_WORD*)(v6 + 44) > 0)
    {
        do
        {
            v7 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16406, v5, 0);
            if (!nox_wcscmp(v7, (const wchar_t*)v1))
                nox_window_call_field_94(*(int*)& byte_5D4594[1522628], 16407, (int)& byte_587000[187836], v5);
            ++v5;
        } while (v5 < *(__int16*)(v6 + 44));
    }
    nox_window_call_field_94(
        *(int*)& byte_5D4594[1522632],
        16407,
        (int)v1,
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1522632] + 32) + 48));
    nox_window_call_field_94(*(int*)& byte_5D4594[1522632], 16403, -1, 0);
    *(_DWORD*)& byte_5D4594[1522632] = 0;
    return 1;
}

//----- (004CC4E0) --------------------------------------------------------
int sub_4CC4E0()
{
    _DWORD* v0; // esi
    int v1; // eax
    _DWORD* v2; // esi
    wchar_t* v3; // eax
    _DWORD* v4; // esi
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    unsigned __int16* v8; // [esp-10h] [ebp-28h]
    int v9; // [esp+4h] [ebp-14h]
    char v10[16]; // [esp+8h] [ebp-10h]

    *(_DWORD*)& byte_5D4594[1522892] = nox_new_window_from_file("legal.wnd", sub_4CC6A0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1522892], sub_4CC660, 0, 0);
    sub_46A8C0(*(int*)& byte_5D4594[1522892]);
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522892], 9980);
    v8 = (unsigned __int16*)sub_46AF00((int)v0);
    v1 = sub_46AF40((int)v0);
    sub_43F840(v1, v8, 0, &v9, 640);
    sub_46A9B0(v0, 0, 477 - v9);
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522892], 9999);
    v3 = sub_401020();
    nox_window_call_field_94((int)v2, 16385, (int)v3, 0);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522892], 9998);
    if (!sub_4145F0(v10))
        v10[0] = 0;
    nox_swprintf((wchar_t*)& byte_5D4594[1522896], L"%S", v10);
    nox_window_call_field_94((int)v4, 16385, (int)& byte_5D4594[1522896], 0);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522892], 9970);
    sub_46B340((int)v5, sub_4CC6F0);
    *(_WORD*)& byte_5D4594[1522928] = 300;
    sub_46A8A0();
    if (sub_40A5C0(0x2000000))
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522892], 9901);
        nox_window_call_field_94(*(int*)& byte_5D4594[1522892], 16391, (int)v6, 0);
    }
    sub_43D9B0(14, 100);
    return 1;
}

//----- (004CC660) --------------------------------------------------------
int __cdecl sub_4CC660(_DWORD* a1, int a2, int a3, int a4)
{
    if (*(_WORD*)& byte_5D4594[1522928] <= 270)
    {
        if (a2 != 21)
            return 0;
        if (a4 == 2)
        {
            sub_46C4E0(a1);
            sub_4A1C00();
        }
    }
    return 1;
}

//----- (004CC6A0) --------------------------------------------------------
int __cdecl sub_4CC6A0(_DWORD* a1, int a2, int* a3, int a4)
{
    if (*(_WORD*)& byte_5D4594[1522928] <= 270)
    {
        if (a2 != 16391)
            return 0;
        if (sub_46B0A0(a3) == 9901)
        {
            sub_46C4E0(a1);
            sub_4A1C00();
        }
    }
    return 1;
}

//----- (004CC6F0) --------------------------------------------------------
int sub_4CC6F0(int a1, int a2)
{
    _DWORD* v0; // eax

    if (-- * (short*)& byte_5D4594[1522928] < 0)
    {
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1522892]);
        sub_4A1C00();
    }
    if (*(short*)& byte_5D4594[1522928] < 270)
    {
        v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522892], 9910);
        nox_window_set_hidden((int)v0, 0);
    }
    sub_4343B0(150, 150, 150);
    sub_43F6E0(0, (__int16*)& byte_587000[187860], 500, 150);
    return 1;
}

//----- (004CC770) --------------------------------------------------------
int sub_4CC770()
{
    int v0; // ecx
    int v1; // eax
    int v3; // [esp+0h] [ebp-14h]
    int v4; // [esp+4h] [ebp-10h]
    int v5; // [esp+8h] [ebp-Ch]
    int v6; // [esp+Ch] [ebp-8h]
    int v7; // [esp+10h] [ebp-4h]

    *(_DWORD*)& byte_5D4594[1522932] = nox_new_window_from_file("mapdnld.wnd", sub_4CC890);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1522932], sub_4CC830, 0, 0);
    sub_43BEB0_get_video_mode(&v3, &v4, &v7);
    sub_430C50_get_video_max(&v5, &v6);
    v0 = v3;
    if (v3 > v5)
    {
        v0 = v5;
        v3 = v5;
    }
    v1 = v4;
    if (v4 > v6)
    {
        v1 = v6;
        v4 = v6;
    }
    sub_46A9B0(*(_DWORD * *)& byte_5D4594[1522932], (v0 - 1024) / 2, (v1 - 768) / 2);
    sub_46A8C0(*(int*)& byte_5D4594[1522932]);
    sub_46A8A0();
    return 1;
}

//----- (004CC830) --------------------------------------------------------
int __cdecl sub_4CC830(int a1, int a2, int a3, int a4)
{
    if (a2 != 21)
        return 0;
    if (a3 != 1)
        return 0;
    if (a4 == 2)
    {
        sub_452D80(231, 100);
        sub_4CC930();
        sub_409D70((char*)& byte_5D4594[1522936]);
        sub_4ABA90();
        sub_4AB560(0);
        sub_4AB570(0);
        sub_40A540(9437184);
    }
    return 1;
}

//----- (004CC890) --------------------------------------------------------
int __cdecl sub_4CC890(int a1, int a2, int* a3, int a4)
{
    int v3; // esi

    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    if (v3 != 1601)
        return 0;
    sub_4CC930();
    sub_4ABA90();
    sub_409D70((char*)& byte_5D4594[1522940]);
    sub_4AB560(0);
    sub_4AB570(0);
    sub_40A540(9437184);
    return 1;
}

//----- (004CC900) --------------------------------------------------------
int __cdecl sub_4CC900(unsigned __int8 a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1522932], 1603);
    return nox_window_call_field_94((int)v1, 16416, a1, 0);
}

//----- (004CC930) --------------------------------------------------------
int sub_4CC930()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1522932];
    if (*(_DWORD*)& byte_5D4594[1522932])
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1522932]);
    *(_DWORD*)& byte_5D4594[1522932] = 0;
    return result;
}

//----- (004CC950) --------------------------------------------------------
int __cdecl sub_4CC950(int a1, int a2)
{
    int v2; // ebp
    int v3; // esi
    int v4; // eax
    char v5; // bl
    int v6; // eax
    int v7; // esi
    int v9; // [esp+0h] [ebp-4h]

    if (!*(_DWORD*)& byte_5D4594[1522952])
    {
        *(_DWORD*)& byte_5D4594[1522952] = sub_44CFC0((CHAR*)& byte_587000[187880]);
        *(_DWORD*)& byte_5D4594[1522944] = sub_4344A0(200, 200, 200);
        *(_DWORD*)& byte_5D4594[1522948] = sub_4344A0(255, 255, 255);
    }
    v2 = *(_DWORD*)& byte_5D4594[1522944];
    v3 = *(_DWORD*)& byte_5D4594[1522952];
    v9 = *(_DWORD*)& byte_5D4594[1522948];
    v4 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 54);
    v5 = v4;
    v6 = sub_45A360(
        v3,
        *(_DWORD*)(a2 + 12) + 50 * *(int*)& byte_587000[8 * v4 + 192088] / 16,
        *(_DWORD*)(a2 + 16) + 50 * *(int*)& byte_587000[8 * v4 + 192092] / 16);
    v7 = v6;
    if (v6)
    {
        *(_BYTE*)(v6 + 448) = v5;
        *(_WORD*)(a2 + 104) = 0;
        *(_BYTE*)(v6 + 449) = sub_415FF0(2, 3, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 74);
        if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\VortexUp.c", 75) > 50)
            * (_BYTE*)(v7 + 449) = -*(_BYTE*)(v7 + 449);
        *(_BYTE*)(v7 + 451) = 1;
        *(_BYTE*)(v7 + 450) = 50;
        *(_DWORD*)(v7 + 440) = *(_DWORD*)(a2 + 12);
        *(_DWORD*)(v7 + 444) = *(_DWORD*)(a2 + 16);
        *(_DWORD*)(v7 + 432) = v2;
        *(_DWORD*)(v7 + 436) = v9;
        sub_45A110((_DWORD*)v7);
        sub_49BAB0((_DWORD*)v7);
    }
    return 1;
}

//----- (004CCAC0) --------------------------------------------------------
int __cdecl sub_4CCAC0(int a1, _DWORD* a2)
{
    unsigned int v2; // ebx
    _DWORD* v3; // ebp
    int v4; // edi
    int v5; // esi
    int v6; // eax
    int v7; // eax
    int v8; // esi
    __int16 v9; // cx
    unsigned int v10; // edi
    unsigned __int8* v11; // esi
    __int16 v12; // cx
    float v14; // [esp+0h] [ebp-20h]
    int i; // [esp+14h] [ebp-Ch]
    __int16 v16; // [esp+18h] [ebp-8h]
    __int16 v17; // [esp+1Ah] [ebp-6h]
    unsigned int v18; // [esp+1Ch] [ebp-4h]
    int v19; // [esp+28h] [ebp+8h]

    v14 = sub_419D40(&byte_587000[188052]);
    v2 = sub_419A70(v14);
    if (!*(_DWORD*)& byte_5D4594[1522956])
    {
        *(_DWORD*)& byte_5D4594[1522956] = sub_44CFC0((CHAR*)& byte_587000[188072]);
        *(_DWORD*)& byte_5D4594[1522960] = sub_44CFC0((CHAR*)& byte_587000[188084]);
    }
    v3 = a2;
    v19 = 20;
    v4 = v2 >> 2;
    v18 = v2 >> 4;
    for (i = v2 >> 2; ; v4 = i)
    {
        v5 = v4 + sub_415FF0(0, v2, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 63);
        if (v5 > (int)v2)
            v5 = v2;
        v6 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 68);
        v7 = sub_45A360(
            *(int*)& byte_5D4594[1522960],
            v3[3] + v5 * *(int*)& byte_587000[8 * v6 + 192088] / 16,
            v3[4] + v5 * *(int*)& byte_587000[8 * v6 + 192092] / 16);
        v8 = v7;
        if (v7)
        {
            *(_DWORD*)(v7 + 432) = *(_DWORD*)(v7 + 12) << 12;
            *(_DWORD*)(v7 + 436) = *(_DWORD*)(v7 + 16) << 12;
            *(_BYTE*)(v7 + 299) = 0;
            *(_DWORD*)(v7 + 440) = 0;
            *(_DWORD*)(v7 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                + sub_415FF0(10, 30, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 88);
            *(_DWORD*)(v8 + 444) = *(_DWORD*)& byte_5D4594[2598000];
            *(_WORD*)(v8 + 104) = 0;
            *(_BYTE*)(v8 + 296) = sub_415FF0(2, 8, "C:\\NoxPost\\src\\client\\Drawable\\Update\\ManaBomb.c", 94);
            sub_45A110((_DWORD*)v8);
        }
        if (!--v19)
            break;
    }
    if (byte_5D4594[2598000] & 1)
    {
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - v3[80]) < 0xA)
        {
            v9 = *((_WORD*)v3 + 8);
            LOWORD(i) = *((_WORD*)v3 + 6);
            HIWORD(i) = v9;
            v10 = *(_DWORD*)& byte_5D4594[2598000] % 0x33u;
            if ((int)(*(_DWORD*)& byte_5D4594[2598000] % 0x33u) < 256)
            {
                v11 = &byte_587000[8 * v10 + 192092];
                do
                {
                    v12 = v18 * *(_WORD*)v11;
                    v16 = i + v18 * *((_WORD*)v11 - 2);
                    v17 = HIWORD(i) + v12;
                    sub_499520(*(int*)& byte_5D4594[1522956], (unsigned __int16*)& i, v10, 0, 0);
                    sub_499520(*(int*)& byte_5D4594[1522956], (unsigned __int16*)& i, v10, 1, 0);
                    v11 += 408;
                    LOWORD(v10) = v10 + 51;
                } while ((int)v11 < (int)& byte_587000[194140]);
            }
        }
    }
    return 1;
}

//----- (004CCCF0) --------------------------------------------------------
int sub_4CCCF0()
{
    return 1;
}

//----- (004CCD00) --------------------------------------------------------
int __cdecl sub_4CCD00(int a1, int a2)
{
    unsigned int i; // ecx

    for (i = *(_DWORD*)(a2 + 432); i < *(int*)& byte_5D4594[2598000]; ++i)
    {
        if (*(float*)(a2 + 436) > 0.0)
        {
            *(float*)(a2 + 436) = *(float*)(a2 + 440) + *(float*)(a2 + 436);
            *(float*)(a2 + 440) = *(float*)(a2 + 440) - 1.0;
        }
        if (*(float*)(a2 + 436) <= 0.0)
        {
            *(_DWORD*)(a2 + 436) = 0;
            *(_DWORD*)(a2 + 440) = 0;
        }
    }
    *(_WORD*)(a2 + 104) = (__int64) * (float*)(a2 + 436);
    *(_BYTE*)(a2 + 296) = (__int64) * (float*)(a2 + 440);
    *(_DWORD*)(a2 + 432) = *(_DWORD*)& byte_5D4594[2598000];
    return 1;
}

//----- (004CCDB0) --------------------------------------------------------
int __cdecl sub_4CCDB0(int a1, int a2)
{
    unsigned int i; // edx
    double v3; // st7
    double v4; // st7
    double v5; // st7

    for (i = *(_DWORD*)(a2 + 432); i < *(int*)& byte_5D4594[2598000]; ++i)
    {
        v3 = *(float*)(a2 + 436) + *(float*)(a2 + 440);
        *(float*)(a2 + 436) = v3;
        if (v3 >= 0.0)
        {
            *(float*)(a2 + 440) = *(float*)(a2 + 440) - 0.5;
        }
        else
        {
            v4 = -*(float*)(a2 + 440) * *(float*)(a2 + 444);
            *(_DWORD*)(a2 + 436) = 0;
            v5 = v4 * 0.1;
            *(float*)(a2 + 440) = v5;
            if (v5 < 2.0)
            {
                *(_DWORD*)(a2 + 436) = 0;
                *(_DWORD*)(a2 + 440) = 0;
            }
        }
    }
    *(_WORD*)(a2 + 104) = (__int64) * (float*)(a2 + 436);
    *(_BYTE*)(a2 + 296) = (__int64) * (float*)(a2 + 440);
    *(_DWORD*)(a2 + 432) = *(_DWORD*)& byte_5D4594[2598000];
    return 1;
}

//----- (004CCE70) --------------------------------------------------------
int __cdecl sub_4CCE70(int a1, _DWORD* a2)
{
    if (!a2[120] && !sub_413A50())
        sub_4CCEA0(a2, 5);
    return 1;
}

//----- (004CCEA0) --------------------------------------------------------
void __cdecl sub_4CCEA0(_DWORD* a1, int a2)
{
    _DWORD* v2; // ebp
    int v3; // ebx
    int v4; // esi
    int v5; // eax
    int v6; // ecx
    int v8; // eax
    int v9; // edi
    int v11; // ebx
    int v12; // esi
    int v13; // ebx
    int v14; // ebx
    int v15; // [esp+0h] [ebp-14h]
    int v16; // [esp+4h] [ebp-10h]
    float2 v17; // [esp+Ch] [ebp-8h]
    int v18; // [esp+18h] [ebp+4h]

    if (!*(_DWORD*)& byte_5D4594[1522964])
        * (_DWORD*)& byte_5D4594[1522964] = sub_44CFC0((CHAR*)& byte_587000[188304]);
    v2 = a1;
    v3 = a1[4] - a1[9];
    v4 = a1[3] - a1[8];
    v5 = a1[4] - a1[9];
    v18 = v4;
    v15 = v3;
    v6 = abs32(v4) + abs32(v5);
    if (v6 / 7 > 0)
    {
        v16 = v6 / 7;
        while (1)
        {
            v8 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 46);
            v9 = v2[8] + v4 * v8 / 100;
            v11 = v2[9] + (v3 * v8) / 100;
            v12 = sub_45A360(*(int*)& byte_5D4594[1522964], v9, v11);
            if (v12)
            {
                *(_DWORD*)(v12 + 432) = v9 << 12;
                *(_DWORD*)(v12 + 436) = v11 << 12;
                v17.field_0 = (double)-v18;
                v17.field_4 = (double)-v15;
                v13 = sub_415FF0(-25, 25, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 63);
                v14 = sub_509ED0(&v17) + v13;
                if (v14 < 0)
                    v14 += (unsigned int)(255 - v14) >> 8 << 8;
                *(_BYTE*)(v12 + 299) = v14;
                *(_DWORD*)(v12 + 440) = a2 * sub_415FF0(100, 300, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 74);
                *(_DWORD*)(v12 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                    + sub_415FF0(30, 45, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 77);
                *(_DWORD*)(v12 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                *(_WORD*)(v12 + 104) = 28;
                *(_WORD*)(v12 + 106) = 0;
                *(_BYTE*)(v12 + 296) = sub_415FF0(-2, 4, "C:\\NoxPost\\src\\client\\Drawable\\Update\\Fireball.c", 84);
                sub_45A110((_DWORD*)v12);
            }
            --v16;
            if (!v16)
                break;
            v3 = v15;
            v4 = v18;
        }
    }
}

//----- (004CD090) --------------------------------------------------------
int __cdecl sub_4CD090(int a1, _DWORD* a2)
{
    if (!a2[120] && !sub_413A50())
        sub_4CCEA0(a2, 4);
    return 1;
}

//----- (004CD0C0) --------------------------------------------------------
int __cdecl sub_4CD0C0(int a1, _DWORD* a2)
{
    if (!a2[120] && !sub_413A50())
        sub_4CCEA0(a2, 3);
    return 1;
}

//----- (004CD0F0) --------------------------------------------------------
int __cdecl sub_4CD0F0(int a1, _DWORD* a2)
{
    if (!a2[120] && !sub_413A50())
        sub_4CCEA0(a2, 2);
    return 1;
}

//----- (004CD120) --------------------------------------------------------
int __cdecl sub_4CD120(int a1, _DWORD* a2)
{
    if (!a2[120] && !sub_413A50())
        sub_4CCEA0(a2, 1);
    return 1;
}

//----- (004CD150) --------------------------------------------------------
void __cdecl sub_4CD150(int a1, _DWORD* a2, int a3, int a4)
{
    int v4; // eax
    int v5; // esi
    int v6; // eax
    int v7; // ebx
    int v8; // eax
    int v9; // ecx
    int v10; // eax
    int v11; // eax
    _DWORD* v12; // eax
    int v13; // eax
    _DWORD* v14; // ebp
    int v15; // eax
    int v16; // eax
    int v17; // edi
    int v18; // eax
    int v19; // eax
    int v20; // edx
    int v21; // ecx
    int v22; // esi
    char v23; // al
    int v25; // [esp+14h] [ebp-4h]
    int v26; // [esp+24h] [ebp+Ch]
    int v27; // [esp+28h] [ebp+10h]

    v4 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 16);
    if (v4 >= 50)
        return;
    LOBYTE(v4) = *(_BYTE*)(a3 + 432);
    if (!(_BYTE)v4)
    {
        if (a3 == -432)
            return;
        if (a4)
        {
            v5 = *(unsigned __int16*)(a3 + 441) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 28);
            v6 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 29);
            LOWORD(v7) = *(_WORD*)(a3 + 437);
            v8 = *(unsigned __int16*)(a3 + 443) + v6;
            LOWORD(v9) = *(_WORD*)(a3 + 439);
        }
        else
        {
            v5 = *(unsigned __int16*)(a3 + 437) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 36);
            v10 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 37);
            LOWORD(v7) = *(_WORD*)(a3 + 441);
            v8 = *(unsigned __int16*)(a3 + 439) + v10;
            LOWORD(v9) = *(_WORD*)(a3 + 443);
        }
        goto LABEL_19;
    }
    if (a3 == -432)
        return;
    if (sub_578B70(*(_DWORD*)(a3 + 437)))
    {
        v11 = sub_578B30(*(_DWORD*)(a3 + 437));
        v12 = sub_45A720(v11);
    }
    else
    {
        v13 = sub_578B30(*(_DWORD*)(a3 + 437));
        v12 = sub_45A6F0(v13);
    }
    v14 = v12;
    if (sub_578B70(*(_DWORD*)(a3 + 441)))
    {
        v15 = sub_578B30(*(_DWORD*)(a3 + 441));
        v4 = sub_45A720(v15);
    }
    else
    {
        v16 = sub_578B30(*(_DWORD*)(a3 + 441));
        v4 = sub_45A6F0(v16);
    }
    v17 = v4;
    if (!v14 || !v4)
        return;
    if (!a4)
    {
        v5 = v14[3] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 80);
        v19 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 81);
        v7 = *(_DWORD*)(v17 + 12);
        v8 = v14[4] + v19;
        v9 = *(_DWORD*)(v17 + 16);
    LABEL_19:
        LOWORD(v25) = v9;
        goto LABEL_20;
    }
    v5 = *(_DWORD*)(v4 + 12) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 70);
    v18 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 71);
    v7 = v14[3];
    v8 = *(_DWORD*)(v17 + 16) + v18;
    v25 = v14[4];
LABEL_20:
    v20 = v5 + *a2 - a2[4];
    v27 = *(__int16*)(a3 + 104);
    v26 = a2[5];
    v21 = v8 + a2[1] - v26 - v27;
    if (v20 < 0)
        v5 = a2[4] + *a2 + 1;
    if (v21 < 0)
        v8 = a2[1] + v26 - v27 + 1;
    if (v20 >= a2[8])
        v5 = a2[2] + a2[4] - 1;
    if (v21 >= a2[9])
        v8 = a2[3] - v27 + v26 - 1;
    v4 = sub_45A360(a1, v5, v8);
    v22 = v4;
    if (v4)
    {
        v23 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 112);
        *(_WORD*)(v22 + 432) = v7;
        *(_WORD*)(v22 + 434) = v25;
        *(_BYTE*)(v22 + 443) = v23;
        LOBYTE(v4) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 119);
        *(_BYTE*)(v22 + 444) = v4;
    }
    return;
}
// 4CD249: variable 'v11' is possibly undefined
// 4CD25A: variable 'v13' is possibly undefined
// 4CD27E: variable 'v15' is possibly undefined
// 4CD28F: variable 'v16' is possibly undefined

//----- (004CD400) --------------------------------------------------------
int __cdecl sub_4CD400(_DWORD* a1, int a2)
{
    int v2; // eax

    v2 = *(_DWORD*)& byte_5D4594[1522968];
    if (!*(_DWORD*)& byte_5D4594[1522968])
    {
        v2 = sub_44CFC0((CHAR*)& byte_587000[189100]);
        *(_DWORD*)& byte_5D4594[1522968] = v2;
    }
    sub_4CD150(v2, a1, a2, 1);
    sub_4CD150(*(int*)& byte_5D4594[1522968], a1, a2, 0);
    return 1;
}

//----- (004CD450) --------------------------------------------------------
int __cdecl sub_4CD450(_DWORD* a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int v4; // ecx
    int v5; // eax
    _DWORD* v6; // eax
    int v7; // eax
    _DWORD* v8; // ebx
    int v9; // eax
    _DWORD* v10; // eax
    int v11; // eax
    _DWORD* v12; // edi
    _DWORD* v13; // edi
    int v14; // ebx
    int v15; // edx
    int v16; // ebp
    int v17; // edx
    int v18; // ecx
    int v19; // esi
    char v20; // al
    int v22; // [esp+0h] [ebp-8h]
    __int16 v23; // [esp+4h] [ebp-4h]
    int v24; // [esp+Ch] [ebp+4h]

    if (!*(_DWORD*)& byte_5D4594[1522972])
        * (_DWORD*)& byte_5D4594[1522972] = sub_44CFC0((CHAR*)& byte_587000[189112]);
    if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 20) < 50)
    {
        if (*(_BYTE*)(a2 + 432))
        {
            if (a2 == -432)
                return 1;
            if (sub_578B70(*(_DWORD*)(a2 + 437)))
            {
                v5 = sub_578B30(*(_DWORD*)(a2 + 437));
                v6 = sub_45A720(v5);
            }
            else
            {
                v7 = sub_578B30(*(_DWORD*)(a2 + 437));
                v6 = sub_45A6F0(v7);
            }
            v8 = v6;
            if (sub_578B70(*(_DWORD*)(a2 + 441)))
            {
                v9 = sub_578B30(*(_DWORD*)(a2 + 441));
                v10 = sub_45A720(v9);
            }
            else
            {
                v11 = sub_578B30(*(_DWORD*)(a2 + 441));
                v10 = sub_45A6F0(v11);
            }
            v12 = v10;
            if (!v8 || !v10)
                return 1;
            v2 = v10[3] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 61);
            v3 = v12[4] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 62);
            v4 = v8[4];
            v22 = v8[3];
        }
        else
        {
            if (a2 == -432)
                return 1;
            v2 = *(unsigned __int16*)(a2 + 441) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 31);
            v3 = *(unsigned __int16*)(a2 + 443) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 32);
            LOWORD(v22) = *(_WORD*)(a2 + 437);
            LOWORD(v4) = *(_WORD*)(a2 + 439);
        }
        v13 = a1;
        v23 = v4;
        v14 = *a1;
        v15 = *a1 - a1[4];
        v16 = a1[5];
        v24 = *(__int16*)(a2 + 104);
        v17 = v2 + v15;
        v18 = v3 + v13[1] - v16 - v24;
        if (v17 < 0)
            v2 = v13[4] + v14 + 1;
        if (v18 < 0)
            v3 = v16 - v24 + v13[1] + 1;
        if (v17 >= v13[8])
            v2 = v13[2] + v13[4] - 1;
        if (v18 >= v13[9])
            v3 = v13[3] - v24 + v16 - 1;
        v19 = sub_45A360(*(int*)& byte_5D4594[1522972], v2, v3);
        if (v19)
        {
            v20 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 92);
            *(_WORD*)(v19 + 432) = v22;
            *(_WORD*)(v19 + 434) = v23;
            *(_BYTE*)(v19 + 443) = v20;
            *(_BYTE*)(v19 + 444) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Drawable\\Update\\healup.c", 99);
        }
    }
    return 1;
}
// 4CD516: variable 'v5' is possibly undefined
// 4CD527: variable 'v7' is possibly undefined
// 4CD54B: variable 'v9' is possibly undefined
// 4CD55C: variable 'v11' is possibly undefined
