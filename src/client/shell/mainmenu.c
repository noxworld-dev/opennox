#include "mainmenu.h"

#include "selchar.h"
#include "noxworld.h"
#include "../../proto.h"

extern nox_window* nox_win_main_menu;

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
