#include "ctrlevnt.h"

#include "../gui/guicon.h"
#include "../gui/guisave.h"
#include "../gui/guispell.h"
#include "../gui/servopts/guiserv.h"
#include "../../proto.h"

extern int nox_win_width;
extern int nox_win_height;

//----- (0042EAE0) --------------------------------------------------------
char* sub_42EAE0()
{
    unsigned __int8* v0; // esi
    int v1; // eax
    char* result; // eax
    unsigned __int8* v3; // esi
    char v4[256]; // [esp+4h] [ebp-100h]

    if (*(_DWORD*)& byte_587000[73672])
    {
        v0 = &byte_587000[73684];
        do
        {
            *(_DWORD*)v0 = loadString_sub_40F1D0(*((char**)v0 - 1), 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2092);
            v1 = *((_DWORD*)v0 + 1);
            v0 += 16;
        } while (v1);
    }
    *(_DWORD*)& byte_587000[75888] = loadString_sub_40F1D0((char*)& byte_587000[80484], 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2095);
    result = *(char**)& byte_587000[75892];
    if (*(_DWORD*)& byte_587000[75892])
    {
        v3 = &byte_587000[75892];
        do
        {
            nox_sprintf(v4, "bindevent:%s", result);
            *((_DWORD*)v3 + 2) = loadString_sub_40F1D0(v4, 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2100);
            result = (char*) * ((_DWORD*)v3 + 3);
            v3 += 12;
        } while (result);
    }
    return result;
}

//----- (0042D6B0) --------------------------------------------------------
int __cdecl sub_42D6B0(_DWORD* a3, int a4)
{
    int v2; // ebp
    int i; // edi
    int j; // esi
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // eax
    int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // eax
    _DWORD* v16; // esi
    int v17; // ecx
    __int64 v18; // rax
    int v19; // eax
    int v20; // ebp
    int v21; // ebx
    unsigned __int8* v22; // edx
    int v23; // edx
    int k; // edi
    int v25; // ecx
    unsigned __int8* v26; // eax
    int v27; // ebp
    int v28; // ebx
    int v29; // edx
    unsigned __int8* v30; // esi
    int v31; // eax
    unsigned __int8* v32; // ecx
    int result; // eax
    int v34; // ecx
    int l; // ebp
    int v36; // esi
    int v37; // eax
    int v38; // eax
    int v39; // eax
    wchar_t* v40; // eax
    wchar_t* v41; // [esp-20h] [ebp-28h]
    char v42[2]; // [esp+2h] [ebp-6h]
    int v43; // [esp+4h] [ebp-4h]

    *(_QWORD*)& byte_5D4594[747876] = sub_416BB0();
    if (sub_40A5C0(1) && sub_40A5C0(0x2000))
        * (_QWORD*)& byte_5D4594[747876] += sub_42E630();
    v2 = *(_DWORD*)& byte_5D4594[2618908];
    if (!sub_40A5C0(1))
        * (_DWORD*)& byte_5D4594[754036] = 0;
    for (i = a4; i; i = *(_DWORD*)(i + 84))
    {
        for (j = 0; j < *(int*)(i + 68); ++j)
        {
            switch (*(_DWORD*)(i + 4 * j + 36))
            {
            case 1:
                v9 = sub_477620();
                switch (v9)
                {
                case 3:
                    v10 = sub_476F90();
                    sub_42E850(v10);
                    break;
                case 4:
                    v11 = sub_476F90();
                    if (*(_BYTE*)(v11 + 280) & 0x10)
                        sub_42E7B0(v11);
                    break;
                case 13:
                    v12 = sub_476F90();
                    sub_42E810(v12);
                    break;
                default:
                    sub_42E670(6, 0);
                    break;
                }
                break;
            case 2:
                if (nox_SDL_GetEventState(SDL_MOUSEBUTTONDOWN))
                {
                    v5 = 1;
                    if (byte_5D4594[754064] & 8)
                        v5 = 3;
                    sub_42E670(2, v5);
                }
                break;
            case 3:
                v6 = (byte_5D4594[754064] & 1) != 0;
                if (byte_5D4594[754064] & 8)
                    LOBYTE(v6) = v6 | 2;
                sub_42E670(3, v6);
                break;
            case 4:
                v7 = (byte_5D4594[754064] & 1) != 0;
                if (byte_5D4594[754064] & 8)
                    LOBYTE(v7) = v7 | 2;
                sub_42E670(4, v7);
                break;
            case 5:
                v8 = (byte_5D4594[754064] & 1) != 0;
                if (byte_5D4594[754064] & 8)
                    LOBYTE(v8) = v8 | 2;
                sub_42E670(5, v8);
                break;
            case 6:
                sub_42E670(7, 0);
                break;
            case 7:
                sub_42E670(19, 0);
                break;
            case 8:
                sub_42E670(8, 0);
                break;
            case 9:
                if (!(*(_BYTE*)(v2 + 3680) & 1))
                    sub_42E670(9, 0);
                break;
            case 0xA:
                sub_42E670(10, 0);
                break;
            case 0xB:
                sub_42E670(11, 0);
                break;
            case 0xC:
                if (!sub_413A50())
                    sub_42E670(12, 0);
                break;
            case 0xD:
                if (!sub_413A50())
                    sub_42E670(13, 0);
                break;
            case 0xE:
                sub_42E670(14, 0);
                break;
            case 0xF:
                sub_42E670(15, 0);
                break;
            case 0x10:
                sub_42E670(18, 0);
                break;
            case 0x11:
                if (!sub_45D9C0())
                {
                    v13 = sub_476F40();
                    sub_42E780(29, v13);
                }
                break;
            case 0x12:
                if (!sub_45D9C0())
                    sub_42E780(20, 0);
                break;
            case 0x13:
                if (!sub_45D9C0())
                    sub_42E780(21, 0);
                break;
            case 0x14:
                if (!sub_45D9C0())
                    sub_42E780(22, 0);
                break;
            case 0x15:
                if (!sub_45D9C0())
                    sub_42E780(23, 0);
                break;
            case 0x16:
                if (!sub_45D9C0())
                    sub_42E780(24, 0);
                break;
            case 0x17:
                if (!sub_45D9C0())
                    sub_42E780(25, 0);
                break;
            case 0x18:
                if (!sub_45D9C0())
                    sub_42E780(26, 0);
                break;
            case 0x19:
                if (!sub_45D9C0())
                    sub_42E780(27, 0);
                break;
            case 0x1A:
                if (!sub_45D9C0())
                    sub_42E780(28, 0);
                break;
            case 0x1B:
                if (!sub_45D9C0())
                {
                    v14 = sub_476F40();
                    sub_42E780(30, v14);
                }
                break;
            case 0x1C:
                sub_42E780(31, 0);
                break;
            case 0x1D:
                sub_42E780(32, 0);
                break;
            case 0x1E:
                sub_42E780(33, 0);
                break;
            case 0x1F:
                sub_42E780(34, 0);
                break;
            case 0x20:
                sub_42E780(35, 0);
                break;
            case 0x21:
                sub_42E670(36, 0);
                break;
            case 0x22:
                sub_42E670(37, 0);
                break;
            case 0x23:
                sub_42E780(38, 0);
                break;
            case 0x24:
                sub_42E780(39, 0);
                break;
            case 0x25:
                sub_42E780(40, 0);
                break;
            case 0x26:
                sub_42E780(41, 0);
                break;
            case 0x27:
                sub_42E780(42, 0);
                break;
            case 0x28:
                sub_42E780(43, 0);
                break;
            case 0x29:
                sub_42E780(44, 0);
                break;
            case 0x2A:
                sub_42E780(45, 0);
                break;
            case 0x2B:
                sub_42E670(16, 0);
                break;
            case 0x2C:
                sub_42E670(17, 0);
                break;
            case 0x2D:
                sub_42E670(46, 0);
                break;
            case 0x2E:
                if (sub_40A5C0(0x2000) && sub_4160F0(0x15u, *(unsigned int*)& byte_5D4594[2649704]))
                {
                    sub_4160D0(21);
                    sub_42E670(47, 0);
                }
                break;
            case 0x2F:
                if (sub_40A5C0(0x2000) && sub_4160F0(0x14u, 2 * *(_DWORD*)& byte_5D4594[2649704]))
                {
                    sub_4160D0(20);
                    sub_42E670(48, 0);
                }
                break;
            case 0x30:
                if (sub_40A5C0(0x2000) && sub_4160F0(0x16u, *(unsigned int*)& byte_5D4594[2649704]))
                {
                    sub_4160D0(22);
                    sub_42E670(49, 0);
                }
                break;
            case 0x31:
                sub_42E670(50, 0);
                break;
            case 0x32:
                if (sub_40A5C0(0x2000))
                    sub_42E670(51, 0);
                break;
            case 0x33:
                if (!sub_413A50())
                    sub_42E670(52, 0);
                break;
            case 0x34:
                sub_42E670(53, 0);
                break;
            case 0x35:
                if (sub_40A5C0(2048) && !sub_477600())
                    sub_42E670(54, 0);
                break;
            case 0x36:
                if (sub_40A5C0(2048) && !sub_477600())
                    sub_42E670(55, 0);
                break;
            case 0x37:
                sub_42E670(56, 0);
                break;
            default:
                continue;
            }
        }
    }
#ifdef __EMSCRIPTEN__
    if (!nox_SDL_GetEventState(SDL_MOUSEBUTTONDOWN))
    {
        sub_42E670(1, orientation);
        if (move_speed)
            sub_42E670(2, 3);
        if (jump)
        {
            sub_42E670(2, 3);
            sub_42E670(7, 0);
            jump = 0;
        }
    }
    else
#endif
    {
        if (byte_5D4594[747848] != 2 && *(_DWORD*)& byte_5D4594[747868] == 4)
        {
            v15 = sub_476F80();
            v16 = a3;
            if (v15)
                v17 = sub_4739D0(*(_DWORD*)(v15 + 16));
            else
                v17 = a3[1];
            a4 = *v16 - nox_win_width / 2;
            v18 = (__int64)((atan2((double)(v17 - nox_win_height / 2), (double)a4) + 6.2831855) * 40.743664 + 0.5);
            *(_DWORD*)& byte_5D4594[754060] = v18;
            if ((int)v18 < 0)
            {
                LODWORD(v18) = ((unsigned int)(255 - v18) >> 8 << 8) + v18;
                *(_DWORD*)& byte_5D4594[754060] = v18;
            }
            if ((int)v18 >= 256)
            {
                LODWORD(v18) = -256 * ((unsigned int)v18 >> 8) + v18;
                *(_DWORD*)& byte_5D4594[754060] = v18;
            }
            sub_42E670(1, v18);
        }
        sub_42E670(1, *(int*)& byte_5D4594[754060]);
    }
    if (byte_5D4594[2661958])
        sub_45DBB0();
    if (byte_5D4594[754064] & 4)
        sub_42E670(28, 0);
    if (sub_40A5C0(1))
    {
        v19 = *(_DWORD*)& byte_5D4594[754048];
        v20 = *(_DWORD*)& byte_5D4594[754040];
        v21 = 0;
        if (*(_DWORD*)& byte_5D4594[754048] == *(_DWORD*)& byte_5D4594[754040])
            goto LABEL_226;
        v22 = &byte_5D4594[750964];
        do
        {
            qmemcpy(v22, &byte_5D4594[24 * v19 + 747884], 0x18u);
            v19 = (v19 + 1) % 128;
            ++v21;
            v22 += 24;
        } while (v19 != v20);
        if (v21 <= 0)
        {
        LABEL_226:
            v23 = *(_DWORD*)& byte_5D4594[754044];
        }
        else
        {
            v23 = v21;
            *(_DWORD*)& byte_5D4594[754048] = v20;
            *(_DWORD*)& byte_5D4594[754044] = v21;
        }
        for (k = v20; k != *(_DWORD*)& byte_5D4594[754036]; k = (k + 1) % 128)
        {
            v25 = 0;
            if (v23 > 0)
            {
                v26 = &byte_5D4594[750972];
                while (*(_DWORD*)& byte_5D4594[24 * k + 747892] != *(_DWORD*)v26)
                {
                    ++v25;
                    v26 += 24;
                    if (v25 >= v23)
                        goto LABEL_137;
                }
                if (sub_42D4B0(*(_DWORD*)& byte_5D4594[24 * k + 747892]))
                    * (_DWORD*)& byte_5D4594[24 * k + 747900] = 0;
                v23 = *(_DWORD*)& byte_5D4594[754044];
            }
        LABEL_137:
            ;
        }
    }
    else
    {
        v27 = *(_DWORD*)& byte_5D4594[754036];
        v28 = 0;
        if (*(_DWORD*)& byte_5D4594[754036] > 0)
        {
            v29 = *(_DWORD*)& byte_5D4594[754044];
            v30 = &byte_5D4594[747900];
            do
            {
                v31 = 0;
                *(_DWORD*)v30 = 1;
                if (v29 > 0)
                {
                    v32 = &byte_5D4594[750972];
                    while (*((_DWORD*)v30 - 2) != *(_DWORD*)v32)
                    {
                        ++v31;
                        v32 += 24;
                        if (v31 >= v29)
                            goto LABEL_149;
                    }
                    if (sub_42D4B0(*((_DWORD*)v30 - 2)))
                        * (_DWORD*)v30 = 0;
                    v27 = *(_DWORD*)& byte_5D4594[754036];
                    v29 = *(_DWORD*)& byte_5D4594[754044];
                }
            LABEL_149:
                ++v28;
                v30 += 24;
            } while (v28 < v27);
            if (v27 > 0)
                qmemcpy(&byte_5D4594[750964], &byte_5D4594[747884], 4 * ((unsigned int)(24 * v27) >> 2));
        }
        *(_DWORD*)& byte_5D4594[754044] = v27;
    }
    *(_DWORD*)& byte_5D4594[754064] = 0;
    if (sub_40A5C0(1))
    {
        result = *(_DWORD*)& byte_5D4594[754040];
        v34 = *(_DWORD*)& byte_5D4594[754036];
        if (*(_DWORD*)& byte_5D4594[754036] < *(int*)& byte_5D4594[754040])
            v34 = *(_DWORD*)& byte_5D4594[754036] + 128;
    }
    else
    {
        v34 = *(_DWORD*)& byte_5D4594[754036];
        result = 0;
    }
    v43 = v34;
    for (l = result; l < v43; ++l)
    {
        v36 = 24 * (l % 128);
        if (*(_DWORD*)& byte_5D4594[24 * (l % 128) + 747900])
        {
            switch (*(_DWORD*)& byte_5D4594[24 * (l % 128) + 747892])
            {
            case 0x14:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(186, 100);
                    sub_476E00(1);
                }
                break;
            case 0x15:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(190, 100);
                    sub_476E00(6);
                }
                break;
            case 0x16:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(192, 100);
                    sub_476E00(3);
                }
                break;
            case 0x17:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(188, 100);
                    sub_476E00(4);
                }
                break;
            case 0x18:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(187, 100);
                    sub_476E00(2);
                }
                break;
            case 0x19:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(193, 100);
                    sub_476E00(0);
                }
                break;
            case 0x1A:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(189, 100);
                    sub_476E00(7);
                }
                break;
            case 0x1B:
                if (!sub_40A5C0(128))
                {
                    sub_452D80(191, 100);
                    sub_476E00(5);
                }
                break;
            default:
                break;
            }
            v37 = *(_DWORD*)& byte_5D4594[v36 + 747892];
            switch (v37)
            {
            case 8:
                sub_46A430(0);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 9:
                sub_46A430(1);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 10:
                sub_45AC70();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 11:
                sub_451350();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 12:
                sub_452D80(921, 100);
                sub_4766E0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 13:
                sub_452D80(921, 100);
                sub_4766F0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 14:
                sub_452D80(921, 100);
                v38 = sub_434B00();
                sub_434B30(v38 + 1);
                updateGamma(1);
                sub_434B60();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 15:
                sub_452D80(921, 100);
                v39 = sub_434B00();
                sub_434B30(v39 - 1);
                updateGamma(-1);
                sub_434B60();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 16:
                sub_4460C0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 17:
                if (sub_450560())
                    sub_46D580();
                else
                    sub_42EB90(1);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 18:
                sub_473610();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 19:
                sub_467C60();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
                sub_45DA50(v37 - 31);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 36:
                sub_4724E0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 37:
                sub_472500();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 38:
                sub_4672C0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 39:
                sub_472220();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 40:
                sub_472240();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 41:
                sub_472260();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 42:
                sub_4604F0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 43:
                sub_460540();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 44:
                sub_460590();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 45:
                sub_45E040();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 46:
                if (sub_40A5C0(8) || !sub_40A5C0(0x2000))
                    goto LABEL_211;
                sub_457500();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 47:
                LOWORD(a4) = 739;
                sub_4E53C0(31, &a4, 2, 0, 1);
                break;
            case 48:
                LOWORD(a3) = 483;
                sub_4E53C0(31, &a3, 2, 0, 1);
                break;
            case 49:
                v42[0] = -29;
                v42[1] = 4;
                sub_4E53C0(31, v42, 2, 0, 1);
                break;
            case 50:
                sub_460630();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 51:
                sub_452D80(921, 100);
                sub_4703F0();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 52:
                sub_470A60();
                sub_452D80(921, 100);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 53:
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                    goto LABEL_211;
                *(_DWORD*)& byte_587000[80828] ^= 1u;
                *(_DWORD*)& byte_587000[80832] = *(_DWORD*)& byte_587000[80828];
                sub_452D80(921, 100);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 54:
                if (!sub_40A5C0(2048))
                    goto LABEL_211;
                if (!sub_4DCCB0())
                    goto LABEL_210;
                sub_452D80(921, 100);
                sub_4DB130("AUTOSAVE");
                sub_4DB170(1, 0, 0);
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            case 55:
                if (!sub_40A5C0(2048))
                    goto LABEL_211;
                if (sub_4DCCB0())
                {
                    sub_452D80(921, 100);
                    sub_413A00(1);
                    v41 = loadString_sub_40F1D0((char*)& byte_587000[80304], 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 1867);
                    v40 = loadString_sub_40F1D0((char*)& byte_587000[80372], 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 1866);
                    sub_449A10(0, (int)v40, (int)v41, 56, (int (*)(void))sub_42E600, sub_42E620);
                    *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                }
                else
                {
                LABEL_210:
                    sub_452D80(231, 100);
                LABEL_211:
                    *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                }
                break;
            case 56:
                sub_46DB00();
                *(_DWORD*)& byte_5D4594[v36 + 747900] = 0;
                break;
            default:
                break;
            }
        }
        result = v43;
    }
    return result;
}

