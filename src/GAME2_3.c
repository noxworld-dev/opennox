#include "client/draw/animdraw.h"
#include "client/drawable/drawable.h"
#include "client/gui/guimsg.h"
#include "proto.h"

extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

const int nox_max_npcs = 1024;
nox_npc* npc_array;

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;
extern obj_5D4594_3799572_t obj_5D4594_3800716;

nox_drawable*** nox_drawable_2d_index = 0;
int nox_drawable_2d_index_size = 0;
const int nox_drawable_2d_index_cap = 47;

//----- (0048C4D0) --------------------------------------------------------
int sub_48C4D0()
{
    unsigned __int16* v0; // esi
    _WORD* v1; // edi
    unsigned __int16 v2; // ax
    int v3; // eax
    int result; // eax
    int v6; // [esp-4h] [ebp-10h]

    v0 = *(unsigned __int16**)& byte_5D4594[1193516];
    v1 = *(_WORD * *)& byte_5D4594[1193584];
    v6 = *(_DWORD*)& byte_5D4594[1193520];
    do
    {
        v2 = *v0;
        ++v0;
        v3 = (unsigned __int8) * (_DWORD*)(*(_DWORD*)& byte_5D4594[3804668] + v2);
        result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804672]
                            + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[34]) * v3) >> 8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[35]) * v3) >> 8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[36]) * v3) >> 8));
        *v1 = result;
        ++v1;
    } while ((*(_DWORD*)& byte_5D4594[1193520])-- > 1);
    *(_DWORD*)& byte_5D4594[1193520] = v6;
    *(_DWORD*)& byte_5D4594[1193516] = v0;
    *(_DWORD*)& byte_5D4594[1193584] = v1;
    return result;
}

//----- (0048C560) --------------------------------------------------------
int sub_48C560()
{
    return 1;
}

//----- (0048C580) --------------------------------------------------------
void __cdecl sub_48C580(pixel8888* a1, int num)
{
    unsigned __int32* pix = (unsigned __int32*)a1;
    for (int i = num-1; i >= 0; i--)
    {
        unsigned __int32 result = *pix;
        for (unsigned __int32* it = & pix[i]; it > pix; --it)
        {
            if (result > *it) {
                result = InterlockedExchange((volatile signed __int32*)it, result);
            }
        }
        *pix = result;
        ++pix;
    }
}

//----- (0048C5B0) --------------------------------------------------------
__int16 __cdecl sub_48C5B0(__int16* a1, int a2)
{
    __int16* v2; // edi
    int v3; // ecx
    __int16* v4; // ebx
    __int16 result; // ax
    __int16 v6; // t0

    v2 = a1;
    v3 = a2;
    do
    {
        v4 = &v2[v3];
        result = *v2;
        do
        {
            --v4;
            if (result > * v4)
            {
                v6 = result;
                result = *v4;
                *v4 = v6;
            }
        } while (v4 != v2);
        *v2 = result;
        ++v2;
        --v3;
    } while (v3);
    return result;
}

//----- (0048C5E0) --------------------------------------------------------
int __cdecl sub_48C5E0(int a1, int a2)
{
    unsigned int v2; // eax
    int v3; // ecx
    bool v4; // tt

    v2 = *(_DWORD*)& byte_587000[156212];
    v3 = 32;
    do
    {
        v4 = __CFSHL__(v2, 1);
        v2 = __ROL4__(v2, 1);
        if (v4)
            v2 ^= 0xA0Au;
        --v3;
    } while (v3);
    *(_DWORD*)& byte_587000[156212] = v2;
    return a1 + (((unsigned int)(a2 - a1) * (unsigned __int64)v2) >> 32);
}

//----- (0048C610) --------------------------------------------------------
__int16 sub_48C610()
{
    int v0; // eax
    int v1; // ecx
    bool v2; // tt

    v0 = *(_DWORD*)& byte_587000[156216];
    v1 = 16;
    do
    {
        v2 = __CFSHL__(v0, 1);
        LOWORD(v0) = __ROL2__(v0, 1);
        if (v2)
            v0 ^= 0xAu;
        --v1;
    } while (v1);
    *(_DWORD*)& byte_587000[156216] = v0;
    return v0;
}

//----- (0048C650) --------------------------------------------------------
_DWORD* __cdecl sub_48C650(int a1, int a2, int a3, _DWORD* a4, _DWORD* a5)
{
    int v5; // eax
    _DWORD* result; // eax

    v5 = sub_48C5E0(a1, a2);
    sub_4AEDA0(&a2, &a1, v5, a3);
    *a4 += a2;
    result = a5;
    *a5 += a1;
    return result;
}

//----- (0048C690) --------------------------------------------------------
unsigned int __cdecl sub_48C690(int a1, int a2, int a3, int a4)
{
    return sub_48C730((a3 - a1) * (a3 - a1) + (a4 - a2) * (a4 - a2));
}

//----- (0048C6B0) --------------------------------------------------------
unsigned int __cdecl sub_48C6B0(int a1, int a2)
{
    return sub_48C730(a2 * a2 + a1 * a1);
}

//----- (0048C6D0) --------------------------------------------------------
double __cdecl sub_48C6D0(float a1, float a2, float a3, float a4)
{
    return (double)sub_48C730((__int64)((a3 - a1) * (a3 - a1) + (a4 - a2) * (a4 - a2)));
}
// 48C6F6: variable 'v4' is possibly undefined

//----- (0048C700) --------------------------------------------------------
double __cdecl sub_48C700(float a1, float a2)
{
    return (double)sub_48C730((__int64)(a1 * a1 + a2 * a2));
}
// 48C722: variable 'v2' is possibly undefined

//----- (0048C730) --------------------------------------------------------
unsigned __fastcall sub_48C730(unsigned int a1)
{
    int result; // eax

    if (a1 < 0x10000)
    {
        if (a1 < 0x100)
        {
            if (a1 < 0x10)
            {
                if (a1 < 4)
                {
                    result = byte_587000[155956 + 64 * a1] >> 7;
                }
                else
                {
                    result = byte_587000[155956 + 16 * a1] >> 6;
                }
            }
            else if (a1 < 0x40)
            {
                result = byte_587000[155956 + 4 * a1] >> 5;
            }
            else
            {
                result = byte_587000[155956 + a1] >> 4;
            }
        }
        else if (a1 < 0x1000)
        {
            if (a1 < 0x400)
            {
                result = byte_587000[155956 + (a1 >> 2)] >> 3;
            }
            else
            {
                result = byte_587000[155956 + (a1 >> 4)] >> 2;
            }
        }
        else if (a1 < 0x4000)
        {
            result = byte_587000[155956 + (a1 >> 6)] >> 1;
        }
        else
        {
            result = byte_587000[155956 + (a1 >> 8)];
        }
    }
    else if (a1 < 0x1000000)
    {
        if (a1 < 0x100000)
        {
            if (a1 < 0x40000)
            {
                result = byte_587000[155956 + (a1 >> 10)] << 1;
            }
            else
            {
                result = byte_587000[155956 + (a1 >> 12)] << 2;
            }
        }
        else if (a1 < 0x400000)
        {
            result = byte_587000[155956 + (a1 >> 14)] << 3;
        }
        else
        {
            result = byte_587000[155956 + (a1 >> 16)] << 4;
        }
    }
    else if (a1 < 0x10000000)
    {
        if (a1 < 0x4000000)
        {
            result = byte_587000[155956 + (a1 >> 18)] << 5;
        }
        else
        {
            result = byte_587000[155956 + (a1 >> 20)] << 6;
        }
    }
    else if (a1 < 0x40000000)
    {
        result = byte_587000[155956 + (a1 >> 22)] << 7;
    }
    else
    {
        result = (unsigned __int8)byte_587000[155956 + (a1 >> 24)] << 8;
    }
    return result;
}

//----- (0048C870) --------------------------------------------------------
int __cdecl sub_48C870(LPSTR a1)
{
    int v1; // esi
    unsigned __int8* v2; // ebx
    struct _OSVERSIONINFOA VersionInformation; // [esp+Ch] [ebp-94h]

    memset(&VersionInformation, 0, sizeof(VersionInformation));
    v1 = 0;
    v2 = &byte_587000[156220];
    VersionInformation.dwOSVersionInfoSize = 148;
    if (GetVersionExA(&VersionInformation))
    {
        if (VersionInformation.dwPlatformId)
        {
            if (VersionInformation.dwPlatformId == 1)
            {
                if (VersionInformation.dwMajorVersion > 4
                    || VersionInformation.dwMajorVersion == 4 && VersionInformation.dwMinorVersion)
                {
                    v1 = 4;
                    v2 = &byte_587000[156240];
                }
                else if (LOWORD(VersionInformation.dwBuildNumber) <= 0x3E8u)
                {
                    v1 = 2;
                    v2 = &byte_587000[156268];
                }
                else
                {
                    v1 = 3;
                    v2 = &byte_587000[156252];
                }
            }
            else if (VersionInformation.dwPlatformId == 2)
            {
                v1 = 5;
                v2 = &byte_587000[156280];
            }
        }
        else
        {
            v1 = 1;
            v2 = &byte_587000[156228];
        }
    }
    if (a1)
        nox_wsprintfA(
                a1,
                (LPCSTR)& byte_587000[156292],
                VersionInformation.dwMajorVersion,
                VersionInformation.dwMinorVersion,
                LOWORD(VersionInformation.dwBuildNumber),
                v2);
    return v1;
}

//----- (0048C980) --------------------------------------------------------
int sub_48C980()
{
    *(_DWORD*)& byte_5D4594[1193716] = sub_42F970("ObserverIcon");
    *(_DWORD*)& byte_5D4594[1193712] = nox_window_new(
            0,
            136,
            nox_win_width - 50,
            nox_win_height / 2 - 100,
            50,
            50,
            0);
    sub_46AE60(*(int*)& byte_5D4594[1193712], *(int*)& byte_5D4594[1193716]);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1193712], 0, sub_48C9F0, 0);
    return 1;
}

//----- (0048C9F0) --------------------------------------------------------
int __cdecl sub_48C9F0(int* a1)
{
    int* v1; // esi
    wchar_t* v2; // eax
    int v4; // [esp+4h] [ebp-4h]

    v1 = a1;
    sub_46AA60(a1, &v4, &a1);
    v4 += v1[24];
    a1 = (int*)((char*)a1 + v1[25]);
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[156384], 0, "C:\\NoxPost\\src\\client\\Gui\\guiobs.c", 41);
        sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1193712] + 36), v2);
        sub_47D2C0(v1[15], v4, (int)a1);
    }
    return 1;
}

//----- (0048CA70) --------------------------------------------------------
int __cdecl sub_48CA70(int a1)
{
    return nox_window_set_hidden(*(int*)& byte_5D4594[1193712], a1);
}

//----- (0048CA90) --------------------------------------------------------
BOOL sub_48CA90()
{
    return *(_DWORD*)& byte_5D4594[1193712] && !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1193712]);
}

//----- (0048CAB0) --------------------------------------------------------
int sub_48CAB0()
{
    int result; // eax

    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1193712]);
    *(_DWORD*)& byte_5D4594[1193712] = 0;
    return result;
}

//----- (0048CAD0) --------------------------------------------------------
int sub_48CAD0()
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1197312]))
        return 0;
    sub_46C6E0(*(int*)& byte_5D4594[1197312]);
    nox_window_set_hidden(*(int*)& byte_5D4594[1197312], 1);
    return 1;
}

//----- (0048CB10) --------------------------------------------------------
_DWORD* __cdecl sub_48CB10(int a1)
{
    _DWORD* result; // eax
    wchar_t* v2; // eax
    _DWORD* v3; // esi
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    _DWORD* v9; // esi
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    wchar_t* v12; // eax
    _DWORD* v13; // esi
    wchar_t* v14; // eax
    _DWORD* v15; // eax
    char* v16; // ebx
    char* i; // ebp
    _DWORD* v18; // eax
    int v19; // esi
    const wchar_t* v20; // ebx
    char* j; // ebp
    int v22; // esi
    const wchar_t* v23; // edi
    wchar_t* v24; // [esp-10h] [ebp-228h]
    int v25; // [esp+10h] [ebp-208h]
    char* v26; // [esp+14h] [ebp-204h]
    wchar_t v27[256]; // [esp+18h] [ebp-200h]

    v25 = 0;
    nox_window_call_field_94(*(int*)& byte_5D4594[1197316], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16399, 0, 0);
    result = (_DWORD*)a1;
    *(_DWORD*)& byte_5D4594[1197308] = a1;
    switch (a1)
    {
        case 4:
            if (*(_DWORD*)& byte_5D4594[2618908] && !*(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 4792))
            {
                v24 = loadString_sub_40F1D0((char*)& byte_587000[156516], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 452);
                v2 = loadString_sub_40F1D0((char*)& byte_587000[156580], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 451);
                return sub_449A10(0, (int)v2, (int)v24, 33, 0, 0);
            }
            nox_window_set_hidden(*(int*)& byte_5D4594[1197316], 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1197320], 0);
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1197312], 4301);
            v4 = loadString_sub_40F1D0((char*)& byte_587000[156632], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 465);
            sub_46AEE0((int)v3, (int)v4);
            v5 = loadString_sub_40F1D0((char*)& byte_587000[156684], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 468);
            nox_wcscpy(v27, v5);
            nox_wcscat(v27, L" ");
            v6 = loadString_sub_40F1D0((char*)& byte_587000[156740], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 470);
            nox_wcscat(v27, v6);
            nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16397, (int)v27, 4);
            v7 = loadString_sub_40F1D0((char*)& byte_587000[156792], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 474);
            nox_wcscpy(v27, v7);
            nox_wcscat(v27, L" ");
            v8 = loadString_sub_40F1D0((char*)& byte_587000[156848], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 476);
            nox_wcscat(v27, v8);
            nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16397, (int)v27, 4);
            return (_DWORD*)sub_46A8C0(*(int*)& byte_5D4594[1197312]);
        case 2:
            nox_window_set_hidden(*(int*)& byte_5D4594[1197316], 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1197320], 0);
            v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1197312], 4301);
            v10 = loadString_sub_40F1D0((char*)& byte_587000[156900], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 491);
            sub_46AEE0((int)v9, (int)v10);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[156952], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 495);
            nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16397, (int)v11, 4);
            v12 = loadString_sub_40F1D0((char*)& byte_587000[157004], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 498);
            nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16397, (int)v12, 4);
            if (*(_DWORD*)& byte_5D4594[1197332] == 1)
                nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16403, 0, 0);
            else
                nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16403, 1, 0);
            return (_DWORD*)sub_46A8C0(*(int*)& byte_5D4594[1197312]);
        case 0:
        case 1:
        case 3:
            nox_window_set_hidden(*(int*)& byte_5D4594[1197316], 0);
            nox_window_set_hidden(*(int*)& byte_5D4594[1197320], 1);
            v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1197312], 4301);
            v14 = loadString_sub_40F1D0((char*)& byte_587000[157056], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 520);
            sub_46AEE0((int)v13, (int)v14);
            if (sub_417DD0())
            {
                v15 = sub_418C80(*(int*)& byte_5D4594[2616328]);
                v16 = sub_418AB0(*((unsigned __int8*)v15 + 4));
                v26 = v16;
                if (v16)
                {
                    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
                    {
                        if (i != *(char**)& byte_5D4594[2618908])
                        {
                            v18 = sub_418C80(*((_DWORD*)i + 515));
                            if (v18)
                            {
                                if (sub_419180((int)v18, v16[57]))
                                {
                                    nox_window_call_field_94(
                                            *(int*)& byte_5D4594[1197316],
                                            16397,
                                            (int)(i + 4704),
                                            *(_DWORD*)& byte_587000[8 * ((unsigned __int8)v16[57] % 10) + 156400]);
                                    v19 = 0;
                                    if (*(_DWORD*)& byte_5D4594[1197324] > 0)
                                    {
                                        v20 = (const wchar_t*)& byte_5D4594[1193720];
                                        do
                                        {
                                            if (!nox_wcscmp(v20, (const wchar_t*)i + 2352))
                                                nox_window_call_field_94(*(int*)& byte_5D4594[1197316], 16405, v25, 0);
                                            ++v19;
                                            v20 += 28;
                                        } while (v19 < *(int*)& byte_5D4594[1197324]);
                                        v16 = v26;
                                    }
                                    ++v25;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
                {
                    if (j != *(char**)& byte_5D4594[2618908])
                    {
                        nox_window_call_field_94(*(int*)& byte_5D4594[1197316], 16397, (int)(j + 4704), 4);
                        v22 = 0;
                        if (*(_DWORD*)& byte_5D4594[1197324] > 0)
                        {
                            v23 = (const wchar_t*)& byte_5D4594[1193720];
                            do
                            {
                                if (!nox_wcscmp(v23, (const wchar_t*)j + 2352))
                                    nox_window_call_field_94(*(int*)& byte_5D4594[1197316], 16405, v25, 0);
                                ++v22;
                                v23 += 28;
                            } while (v22 < *(int*)& byte_5D4594[1197324]);
                        }
                        ++v25;
                    }
                }
            }
            return (_DWORD*)sub_46A8C0(*(int*)& byte_5D4594[1197312]);
    }
    return result;
}

//----- (0048D000) --------------------------------------------------------
int sub_48D000()
{
    _DWORD* v0; // eax

    v0 = nox_new_window_from_file("GuiKick.wnd", sub_48D0A0);
    *(_DWORD*)& byte_5D4594[1197312] = v0;
    if (!v0)
        return 0;
    *(_DWORD*)& byte_5D4594[1197316] = sub_46B0C0(v0, 4320);
    *(_DWORD*)& byte_5D4594[1197320] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1197312], 4321);
    sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1197312],
            (nox_win_width - *(int*)(*(_DWORD*)& byte_5D4594[1197312] + 8)) / 2,
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1197312] + 20));
    nox_window_set_hidden(*(int*)& byte_5D4594[1197312], 1);
    *(_DWORD*)& byte_5D4594[1197324] = 0;
    *(_DWORD*)& byte_5D4594[1197328] = 0;
    *(_DWORD*)& byte_5D4594[1197332] = 0;
    *(_DWORD*)& byte_5D4594[1197336] = 0;
    return 1;
}

//----- (0048D0A0) --------------------------------------------------------
int __cdecl sub_48D0A0(int a1, int a2, int* a3, int a4)
{
    int v4; // eax

    if (a2 != 16391)
        return 0;
    v4 = sub_46B0A0(a3) - 4311;
    if (v4)
    {
        if (v4 == 1)
        {
            LABEL_14:
            sub_48CAD0();
            goto LABEL_15;
        }
    }
    else
    {
        if (*(_DWORD*)& byte_5D4594[1197308] != 4)
        {
            if (*(_DWORD*)& byte_5D4594[1197308] == 2)
            {
                sub_48D340();
            }
            else
            {
                if (*(_DWORD*)& byte_5D4594[1197308]
                    && *(_DWORD*)& byte_5D4594[1197308] != 1
                    && *(_DWORD*)& byte_5D4594[1197308] != 3)
                {
                    goto LABEL_15;
                }
                sub_48D120();
            }
            goto LABEL_14;
        }
        sub_48D410();
    }
    LABEL_15:
    sub_452D80(921, 100);
    return 1;
}

//----- (0048D120) --------------------------------------------------------
int sub_48D120()
{
    int v0; // ebp
    int* v1; // eax
    int* v2; // esi
    int i; // eax
    const wchar_t* v4; // eax
    wchar_t* v5; // ebx
    int v6; // esi
    const wchar_t* v7; // edi
    int result; // eax
    int v9; // ebp
    wchar_t* v10; // ebx
    int v11; // esi
    const wchar_t* v12; // edi

    v0 = 0;
    *(_DWORD*)& byte_5D4594[1197328] = *(_DWORD*)& byte_5D4594[1197324];
    qmemcpy(&byte_5D4594[1195512], &byte_5D4594[1193720], 0x700u);
    *(_DWORD*)& byte_5D4594[1197324] = 0;
    v1 = (int*)nox_window_call_field_94(*(int*)& byte_5D4594[1197316], 16404, 0, 0);
    v2 = v1;
    for (i = *v1; i != -1; ++v2)
    {
        v4 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1197316], 16406, i, 0);
        if (v4)
        {
            nox_wcscpy((wchar_t*)& byte_5D4594[56 * *(_DWORD*)& byte_5D4594[1197324] + 1193720], v4);
            ++* (_DWORD*)& byte_5D4594[1197324];
        }
        i = v2[1];
    }
    if (*(int*)& byte_5D4594[1197328] > 0)
    {
        v5 = (wchar_t*)& byte_5D4594[1195512];
        do
        {
            v6 = 0;
            if (*(int*)& byte_5D4594[1197324] <= 0)
            {
                LABEL_11:
                sub_48D260(v5);
            }
            else
            {
                v7 = (const wchar_t*)& byte_5D4594[1193720];
                while (nox_wcscmp(v5, v7))
                {
                    ++v6;
                    v7 += 28;
                    if (v6 >= *(int*)& byte_5D4594[1197324])
                        goto LABEL_11;
                }
            }
            ++v0;
            v5 += 28;
        } while (v0 < *(int*)& byte_5D4594[1197328]);
    }
    result = *(_DWORD*)& byte_5D4594[1197324];
    v9 = 0;
    if (*(int*)& byte_5D4594[1197324] > 0)
    {
        v10 = (wchar_t*)& byte_5D4594[1193720];
        do
        {
            v11 = 0;
            if (*(int*)& byte_5D4594[1197328] <= 0)
            {
                LABEL_19:
                sub_48D2D0(v10);
            }
            else
            {
                v12 = (const wchar_t*)& byte_5D4594[1195512];
                while (nox_wcscmp(v10, v12))
                {
                    ++v11;
                    v12 += 28;
                    if (v11 >= *(int*)& byte_5D4594[1197328])
                        goto LABEL_19;
                }
            }
            result = *(_DWORD*)& byte_5D4594[1197324];
            ++v9;
            v10 += 28;
        } while (v9 < *(int*)& byte_5D4594[1197324]);
    }
    return result;
}

//----- (0048D260) --------------------------------------------------------
char* __cdecl sub_48D260(wchar_t* a1)
{
    char* result; // eax
    int v2; // esi
    char v3[52]; // [esp+8h] [ebp-34h]

    result = sub_416EA0();
    v2 = (int)result;
    if (result)
    {
        while (nox_wcscmp((const wchar_t*)(v2 + 4704), a1))
        {
            result = sub_416EE0(v2);
            v2 = (int)result;
            if (!result)
                return result;
        }
        *(_WORD*)v3 = 750;
        nox_wcscpy((wchar_t*)& v3[2], a1);
        result = (char*)sub_40EBC0(31, 0, v3, 52);
    }
    return result;
}

//----- (0048D2D0) --------------------------------------------------------
char* __cdecl sub_48D2D0(wchar_t* a1)
{
    char* result; // eax
    int v2; // esi
    char v3[52]; // [esp+8h] [ebp-34h]

    result = sub_416EA0();
    v2 = (int)result;
    if (result)
    {
        while (nox_wcscmp((const wchar_t*)(v2 + 4704), a1))
        {
            result = sub_416EE0(v2);
            v2 = (int)result;
            if (!result)
                return result;
        }
        *(_WORD*)v3 = 238;
        nox_wcscpy((wchar_t*)& v3[2], a1);
        result = (char*)sub_40EBC0(31, 0, v3, 52);
    }
    return result;
}

//----- (0048D340) --------------------------------------------------------
int sub_48D340()
{
    int result; // eax

    if (nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16404, 0, 0))
    {
        result = 0;
        *(_DWORD*)& byte_5D4594[1197332] = 0;
        if (*(_DWORD*)& byte_5D4594[1197336] == 1)
        {
            result = sub_48D3E0();
            *(_DWORD*)& byte_5D4594[1197336] = *(_DWORD*)& byte_5D4594[1197332];
            return result;
        }
    }
    else
    {
        result = 1;
        *(_DWORD*)& byte_5D4594[1197332] = 1;
        if (!*(_DWORD*)& byte_5D4594[1197336])
        {
            result = sub_48D3B0();
            *(_DWORD*)& byte_5D4594[1197336] = *(_DWORD*)& byte_5D4594[1197332];
            return result;
        }
    }
    *(_DWORD*)& byte_5D4594[1197336] = result;
    return result;
}

//----- (0048D3B0) --------------------------------------------------------
int sub_48D3B0()
{
    char v1[2]; // [esp+0h] [ebp-2h]

    v1[0] = -18;
    v1[1] = 4;
    return sub_4E53C0(31, v1, 2, 0, 1);
}

//----- (0048D3E0) --------------------------------------------------------
int sub_48D3E0()
{
    char v1[2]; // [esp+0h] [ebp-2h]

    v1[0] = -18;
    v1[1] = 5;
    return sub_4E53C0(31, v1, 2, 0, 1);
}

//----- (0048D410) --------------------------------------------------------
_DWORD* sub_48D410()
{
    _DWORD* result; // eax

    result = (_DWORD*)nox_window_call_field_94(*(int*)& byte_5D4594[1197320], 16404, 0, 0);
    if (!result)
        return sub_48CB10(2);
    if (result == (_DWORD*)1)
        result = sub_48CB10(3);
    return result;
}

//----- (0048D450) --------------------------------------------------------
int sub_48D450()
{
    int result; // eax

    sub_46C6E0(*(int*)& byte_5D4594[1197312]);
    sub_46ADE0(*(int*)& byte_5D4594[1197312]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1197312]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1197312] = 0;
    *(_DWORD*)& byte_5D4594[1197316] = 0;
    *(_DWORD*)& byte_5D4594[1197320] = 0;
    *(_DWORD*)& byte_5D4594[1197324] = 0;
    *(_DWORD*)& byte_5D4594[1197328] = 0;
    *(_DWORD*)& byte_5D4594[1197332] = 0;
    *(_DWORD*)& byte_5D4594[1197336] = 0;
    return result;
}

//----- (0048D4A0) --------------------------------------------------------
int sub_48D4A0()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[1197332] = 0;
    *(_DWORD*)& byte_5D4594[1197336] = 0;
    return result;
}

//----- (0048D4B0) --------------------------------------------------------
int __cdecl sub_48D4B0(int a1)
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1197304] = a1;
    if (a1 == 1)
        result = sub_4C3460(0);
    else
        result = sub_4C3460(1);
    return result;
}

//----- (0048D4E0) --------------------------------------------------------
int sub_48D4E0()
{
    return *(_DWORD*)& byte_5D4594[1197304];
}

//----- (0048D4F0) --------------------------------------------------------
BOOL __cdecl sub_48D4F0(unsigned __int16 a1, unsigned __int16 a2)
{
    unsigned __int16 v2; // cx

    v2 = 10000;
    if (a1 - 10000 < 0)
    {
        if (a2 >= 0xFFFF - (unsigned __int16)(10000 - a1))
            return 1;
        v2 = a1;
    }
    return a2 < a1 && a2 >= a1 - v2;
}

//----- (0048D560) --------------------------------------------------------
int __cdecl sub_48D560(unsigned __int16 a1)
{
    int* v1; // eax

    v1 = sub_425890((int*)& byte_5D4594[1197340]);
    if (!v1)
        return 0;
    while (v1[2] != a1)
    {
        v1 = sub_4258A0(v1);
        if (!v1)
            return 0;
    }
    return 1;
}

//----- (0048D5A0) --------------------------------------------------------
_DWORD* __cdecl sub_48D5A0(int a1)
{
    _DWORD* result; // eax
    _DWORD* v2; // ebx

    result = (_DWORD*)sub_48D4F0(*(unsigned __int16*)& byte_5D4594[1197360], *(_WORD*)(a1 + 1));
    if (!result)
    {
        result = (_DWORD*)sub_48D560(*(_WORD*)(a1 + 1));
        if (!result)
        {
            result = nox_calloc(*(unsigned __int8*)(a1 + 3) + 32, 1u);
            v2 = result;
            if (result)
            {
                sub_425770(result);
                v2[2] = *(unsigned __int16*)(a1 + 1);
                *((_WORD*)v2 + 12) = *(unsigned __int8*)(a1 + 3);
                *((_QWORD*)v2 + 2) = sub_416BB0();
                qmemcpy(v2 + 8, (const void*)(a1 + 4), *(unsigned __int8*)(a1 + 3));
                if (*(_WORD*)& byte_5D4594[1197360] == *(_WORD*)(a1 + 1))
                    * (_DWORD*)& byte_5D4594[1197352] = v2;
                result = (_DWORD*)sub_425790((int*)& byte_5D4594[1197340], v2);
            }
        }
    }
    return result;
}

//----- (0048D660) --------------------------------------------------------
int sub_48D660()
{
    unsigned __int64 v0; // rax
    int* v1; // esi
    int* v2; // edi

    LODWORD(v0) = *(_DWORD*)& byte_5D4594[1197352];
    if (!*(_DWORD*)& byte_5D4594[1197352])
    {
        if (*(_DWORD*)& byte_5D4594[1197356])
        {
            v0 = sub_416BB0() - *(_QWORD*)(*(_DWORD*)& byte_5D4594[1197356] + 16);
            if (v0 > 0x7530)
            {
                *(_WORD*)& byte_5D4594[1197360] = *(_WORD*)(*(_DWORD*)& byte_5D4594[1197356] + 8);
                *(_DWORD*)& byte_5D4594[1197352] = *(_DWORD*)& byte_5D4594[1197356];
                LODWORD(v0) = sub_4258A0(*(int**)& byte_5D4594[1197356]);
                *(_DWORD*)& byte_5D4594[1197356] = v0;
            }
        }
    }
    v1 = *(int**)& byte_5D4594[1197352];
    if (*(_DWORD*)& byte_5D4594[1197352])
    {
        do
        {
            LODWORD(v0) = v1[2];
            if ((_DWORD)v0 != *(unsigned __int16*)& byte_5D4594[1197360])
                break;
            v2 = sub_4258A0(v1);
            if (!v2)
            {
                v2 = sub_425890((int*)& byte_5D4594[1197340]);
                if (v2 == v1)
                    v2 = 0;
            }
            sub_48EA70(31, (unsigned int)(v1 + 8), *((unsigned __int16*)v1 + 12));
            ++* (_WORD*)& byte_5D4594[1197360];
            sub_425920((_DWORD * *)v1);
            free(v1);
            v1 = v2;
        } while (v2);
    }
    *(_DWORD*)& byte_5D4594[1197356] = v1;
    *(_DWORD*)& byte_5D4594[1197352] = 0;
    return v0;
}

//----- (0048D740) --------------------------------------------------------
int sub_48D740()
{
    int result; // eax

    sub_425760(&byte_5D4594[1197340]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1197352] = 0;
    *(_DWORD*)& byte_5D4594[1197356] = 0;
    *(_WORD*)& byte_5D4594[1197360] = 0;
    return result;
}

//----- (0048D760) --------------------------------------------------------
_DWORD* sub_48D760()
{
    int* v0; // esi
    int* v1; // edi
    _DWORD* result; // eax

    v0 = sub_425890((int*)& byte_5D4594[1197340]);
    if (v0)
    {
        do
        {
            v1 = sub_4258A0(v0);
            sub_425920((_DWORD * *)v0);
            free(v0);
            v0 = v1;
        } while (v1);
    }
    result = sub_425760(&byte_5D4594[1197340]);
    *(_WORD*)& byte_5D4594[1197360] = 0;
    return result;
}

//----- (0048D7B0) --------------------------------------------------------
int* sub_48D7B0()
{
    int* result; // eax

    for (result = sub_425890((int*)& byte_5D4594[1197340]); result; result = sub_4258A0(result))
        ;
    return result;
}

//----- (0048D7D0) --------------------------------------------------------
BOOL sub_48D7D0()
{
    *(_DWORD*)& byte_5D4594[1197364] = nox_new_alloc_class("Chat", 692, 64);
    return *(_DWORD*)& byte_5D4594[1197364] != 0;
}

//----- (0048D800) --------------------------------------------------------
int sub_48D800()
{
    if (*(_DWORD*)& byte_5D4594[1197364])
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1197364]);
    *(_DWORD*)& byte_5D4594[1197364] = 0;
    *(_DWORD*)& byte_5D4594[1197368] = 0;
    return 1;
}

//----- (0048D830) --------------------------------------------------------
BOOL __cdecl sub_48D830(int a1)
{
    return sub_48D850(*(_DWORD*)(a1 + 128)) != 0;
}

//----- (0048D850) --------------------------------------------------------
int __cdecl sub_48D850(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1197368];
    if (!*(_DWORD*)& byte_5D4594[1197368])
        return 0;
    while (*(_DWORD*)(result + 656) != a1)
    {
        result = *(_DWORD*)(result + 684);
        if (!result)
            return 0;
    }
    return result;
}

//----- (0048D880) --------------------------------------------------------
wchar_t* __cdecl sub_48D880(int a1, wchar_t* a2)
{
    wchar_t* v2; // esi
    int v3; // ebx
    wchar_t* result; // eax
    int v5; // eax
    int v6; // eax

    v2 = (wchar_t*)sub_48D850(*(unsigned __int16*)(a1 + 1));
    if (v2)
    {
        v3 = 0;
    }
    else
    {
        result = (wchar_t*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1197364]);
        v2 = result;
        if (!result)
            return result;
        v3 = 1;
    }
    nox_wcscpy(v2, a2);
    *((_DWORD*)v2 + 159) = *(unsigned __int8*)(a1 + 8);
    *((_DWORD*)v2 + 161) = *(_DWORD*)(a1 + 4);
    *((_DWORD*)v2 + 164) = *(unsigned __int16*)(a1 + 1);
    if (*(_WORD*)(a1 + 9))
    {
        v6 = *(unsigned __int16*)(a1 + 9);
    }
    else
    {
        v5 = *((_DWORD*)v2 + 159) / 8;
        if (v5 >= 8)
            v5 = 8;
        v6 = *(_DWORD*)& byte_5D4594[2649704] * (v5 + 2);
    }
    result = (wchar_t*)(*(_DWORD*)& byte_5D4594[2598000] + v6);
    *((_DWORD*)v2 + 160) = result;
    if (v3)
    {
        result = *(wchar_t**)& byte_5D4594[1197368];
        if (*(_DWORD*)& byte_5D4594[1197368])
        {
            result = *(wchar_t**)& byte_5D4594[1197372];
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1197372] + 684) = v2;
            *((_DWORD*)v2 + 172) = *(_DWORD*)& byte_5D4594[1197372];
            *((_DWORD*)v2 + 171) = 0;
            *(_DWORD*)& byte_5D4594[1197372] = v2;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1197368] = v2;
            *(_DWORD*)& byte_5D4594[1197372] = v2;
            *((_DWORD*)v2 + 172) = 0;
            *((_DWORD*)v2 + 171) = 0;
        }
    }
    return result;
}

//----- (0048D990) --------------------------------------------------------
int4* __cdecl sub_48D990(_DWORD* a1)
{
    int v1; // ebx
    _DWORD* v2; // esi
    int v3; // eax
    _DWORD* v4; // edi
    char* v5; // eax
    char* v6; // eax
    int* v7; // eax
    int v8; // edi
    int v9; // eax
    int v10; // eax
    int v11; // ebp
    int v12; // ebp
    int v13; // esi
    int v14; // ebp
    int v15; // esi
    int v16; // ebp
    int v18; // [esp+Ch] [ebp-28h]
    int i; // [esp+10h] [ebp-24h]
    _WORD* v20; // [esp+14h] [ebp-20h]
    int v21; // [esp+18h] [ebp-1Ch]
    int v22; // [esp+1Ch] [ebp-18h]
    int v23; // [esp+20h] [ebp-14h]
    int v24; // [esp+24h] [ebp-10h]
    int v25; // [esp+24h] [ebp-10h]
    int v26; // [esp+24h] [ebp-10h]
    int v27; // [esp+28h] [ebp-Ch]
    int v28; // [esp+28h] [ebp-Ch]
    int v29; // [esp+2Ch] [ebp-8h]
    int v30; // [esp+38h] [ebp+4h]

    v22 = sub_43F320(0);
    v1 = v22 / 2;
    sub_437260();
    sub_48DCF0(a1);
    v2 = *(_DWORD * *)& byte_5D4594[1197368];
    v30 = *(_DWORD*)& byte_5D4594[1197368];
    if (*(_DWORD*)& byte_5D4594[1197368])
    {
        while (1)
        {
            if (v2[165])
            {
                v3 = v2[167];
                v21 = *(_DWORD*)& byte_5D4594[2523948];
                v20 = 0;
                if (v3 && *(_BYTE*)(v3 + 112) & 4)
                {
                    v4 = sub_418C80(*(_DWORD*)(v3 + 128));
                    v5 = sub_417040(v2[164]);
                    if (v5)
                        v20 = v5 + 4704;
                    if (v4)
                    {
                        v6 = sub_418AB0(*((unsigned __int8*)v4 + 4));
                        if (v6)
                        {
                            v7 = (int*)sub_418D50((int)v6);
                            if (v7)
                                v21 = *v7;
                        }
                    }
                }
                v8 = v2[162];
                v18 = v2[163];
                for (i = 0; i < 2; ++i)
                {
                    if (i)
                    {
                        v9 = *(_DWORD*)& byte_5D4594[2650660];
                        --v8;
                        --v18;
                    }
                    else
                    {
                        v9 = *(_DWORD*)& byte_5D4594[2614248];
                    }
                    sub_434460(v9);
                    v23 = v8 - v1;
                    sub_49F500(v8, v18 - v1);
                    sub_49F500(v8 - v1, v18);
                    sub_49E4B0();
                    v10 = *(_DWORD*)(v30 + 672);
                    v11 = v10 + v8;
                    v24 = v10 + v8;
                    sub_49F500(v8, v18 - v1);
                    sub_49F500(v11, v18 - v1);
                    sub_49E4B0();
                    v12 = v1 + v11;
                    sub_49F500(v12, v18);
                    sub_49F500(v24, v18 - v1);
                    sub_49E4B0();
                    v25 = v12;
                    v27 = v18 + *(_DWORD*)(v30 + 676);
                    sub_49F500(v12, v18);
                    sub_49F500(v12, v27);
                    sub_49E4B0();
                    v13 = v1 + v27;
                    v14 = v12 - v1;
                    sub_49F500(v14, v1 + v27);
                    sub_49F500(v25, v27);
                    sub_49E4B0();
                    if (*(_DWORD*)(v30 + 664))
                    {
                        v28 = v1 + v27;
                        v26 = v1 + v8 + *(int*)(v30 + 672) / 2;
                        sub_49F500(v14, v13);
                        sub_49F500(v26, v13);
                        sub_49E4B0();
                        v15 = v22 + v13;
                        v29 = v8 + *(int*)(v30 + 672) / 2;
                        sub_49F500(v29, v15);
                        sub_49F500(v26, v28);
                        sub_49E4B0();
                        v16 = v8 + *(int*)(v30 + 672) / 2 - v1;
                        sub_49F500(v29, v15);
                        v13 = v28;
                        sub_49F500(v16, v28);
                        sub_49E4B0();
                        sub_49F500(v8, v28);
                        sub_49F500(v16, v28);
                    }
                    else
                    {
                        sub_49F500(v8, v13);
                        sub_49F500(v14, v13);
                    }
                    sub_49E4B0();
                    sub_49F500(v8, v13);
                    sub_49F500(v23, v13 - v1);
                    sub_49E4B0();
                    sub_49F500(v23, v13 - v1 - *(_DWORD*)(v30 + 676));
                    sub_49F500(v23, v13 - v1);
                    sub_49E4B0();
                }
                sub_434390(*(int*)& byte_5D4594[2523948]);
                sub_4343E0(*(int*)& byte_5D4594[2614248]);
                sub_43FD00(0, (_WORD*)v30, v8, v18, 128, 0);
                if (v20)
                {
                    sub_434390(v21);
                    sub_43FD00(0, v20, v8, v18 - v22 - 1, 128, 0);
                }
                v2 = (_DWORD*)v30;
            }
            v30 = v2[171];
            if (!v30)
                break;
            v2 = (_DWORD*)v2[171];
        }
    }
    return sub_437290();
}

//----- (0048DCF0) --------------------------------------------------------
void __cdecl sub_48DCF0(_DWORD* a1)
{
    int v1; // eax
    int v2; // esi
    _DWORD* v3; // ebx
    int v4; // eax
    unsigned int v5; // edx
    int v6; // ecx
    int v7; // eax
    _DWORD* v8; // eax
    int v9; // eax
    unsigned __int16 v10; // dx
    int* v11; // ebp
    int v12; // edx
    _DWORD* v13; // edi
    int v14; // eax
    int v15; // eax
    int v16; // eax
    int v17; // ecx
    int v18; // eax
    int v19; // eax
    int v20; // ecx
    int v21; // eax
    int v22; // eax
    int v23; // eax
    int v24; // [esp+8h] [ebp-18h]
    int v25; // [esp+Ch] [ebp-14h]
    int4 a1a; // [esp+10h] [ebp-10h]
    int v27; // [esp+24h] [ebp+4h]

    v1 = sub_43F320(0);
    v2 = *(_DWORD*)& byte_5D4594[1197368];
    v3 = a1;
    v24 = v1;
    v4 = 0;
    if (*(_DWORD*)& byte_5D4594[1197368])
    {
        while (1)
        {
            v5 = *(_DWORD*)(v2 + 656);
            v6 = *(_DWORD*)(v2 + 684);
            *(_DWORD*)(v2 + 680) = v4;
            v25 = v6;
            v27 = v4 + 1;
            *(_DWORD*)(v2 + 668) = 0;
            if (sub_578B70(v5))
            {
                v7 = sub_578B30(*(_DWORD*)(v2 + 656));
                v8 = sub_45A720(v7);
            }
            else
            {
                v9 = sub_578B30(*(_DWORD*)(v2 + 656));
                v8 = sub_45A6F0(v9);
            }
            *(_DWORD*)(v2 + 668) = v8;
            if (v8)
            {
                *(_WORD*)(v2 + 644) = *((_WORD*)v8 + 6);
                *(_WORD*)(v2 + 646) = *((_WORD*)v8 + 8);
            }
            v10 = *(_WORD*)(v2 + 646);
            v11 = (_DWORD*)(v2 + 672);
            *(_DWORD*)(v2 + 648) = *v3 + *(unsigned __int16*)(v2 + 644) - v3[4];
            *(_DWORD*)(v2 + 652) = v3[1] + v10 - v3[5];
            sub_43F840(0, (unsigned __int16*)v2, (int*)(v2 + 672), (_DWORD*)(v2 + 676), 128);
            if (*(_DWORD*)(v2 + 672) > 128)
                * v11 = 128;
            v12 = *(_DWORD*)(v2 + 676);
            *(_DWORD*)(v2 + 648) += *v11 / -2;
            v13 = (_DWORD*)(v2 + 664);
            *(_DWORD*)(v2 + 652) += -64 - v12;
            *(_DWORD*)(v2 + 660) = 1;
            *(_DWORD*)(v2 + 664) = 1;
            if (sub_40A5C0(2048))
            {
                v14 = *(_DWORD*)(v2 + 648);
                if (v14 < *v3 || v14 > v3[2] || (v15 = *(_DWORD*)(v2 + 652) - 64, v15 < v3[1]) || v15 > v3[3])
                {
                    *(_DWORD*)(v2 + 660) = 0;
                    *v13 = 0;
                }
            }
            if (*(_DWORD*)(v2 + 660))
                break;
            LABEL_27:
            if (*(_DWORD*)& byte_5D4594[2598000] > * (int*)(v2 + 640))
            {
                v22 = *(_DWORD*)(v2 + 688);
                if (v22)
                    * (_DWORD*)(v22 + 684) = *(_DWORD*)(v2 + 684);
                else
                    *(_DWORD*)& byte_5D4594[1197368] = *(_DWORD*)(v2 + 684);
                v23 = *(_DWORD*)(v2 + 684);
                if (v23)
                    * (_DWORD*)(v23 + 688) = *(_DWORD*)(v2 + 688);
                else
                    *(_DWORD*)& byte_5D4594[1197372] = *(_DWORD*)(v2 + 688);
                sub_414330(*(unsigned int**)& byte_5D4594[1197364], (_QWORD*)v2);
            }
            v2 = v25;
            if (!v25)
            {
                v2 = *(_DWORD*)& byte_5D4594[1197368];
                goto LABEL_37;
            }
            v4 = v27;
        }
        v16 = *v3 + v24;
        v17 = *(_DWORD*)(v2 + 648);
        if (v17 >= v16)
        {
            v18 = v3[2];
            if (v24 + v17 + *v11 <= v18)
                goto LABEL_22;
            v16 = v18 - *v11 - v24;
        }
        *(_DWORD*)(v2 + 648) = v16;
        *v13 = 0;
        LABEL_22:
        v19 = v3[1] + 2 * v24 + 2;
        v20 = *(_DWORD*)(v2 + 652);
        if (v20 >= v19)
        {
            v21 = v3[3];
            if (v24 + *(_DWORD*)(v2 + 676) + v20 <= v21)
            {
                LABEL_26:
                a1a.field_0 = *(_DWORD*)(v2 + 648);
                a1a.field_4 = *(_DWORD*)(v2 + 652);
                a1a.field_8 = *(_DWORD*)(v2 + 648) + *v11;
                a1a.field_C = *(_DWORD*)(v2 + 676) + *(_DWORD*)(v2 + 652);
                sub_48E000(&a1a, (_DWORD*)(v2 + 664));
                *(_DWORD*)(v2 + 648) = a1a.field_0;
                *(_DWORD*)(v2 + 652) = a1a.field_4;
                goto LABEL_27;
            }
            v19 = v21 - *(_DWORD*)(v2 + 676) - v24;
        }
        *(_DWORD*)(v2 + 652) = v19;
        *v13 = 0;
        goto LABEL_26;
    }
    LABEL_37:
    while (v2)
    {
        sub_48E240((int)v3, (_DWORD*)v2);
        v2 = *(_DWORD*)(v2 + 684);
    }
}
// 48DD5E: variable 'v7' is possibly undefined
// 48DD72: variable 'v9' is possibly undefined

//----- (0048E000) --------------------------------------------------------
bool __cdecl sub_48E000(int4* a1, _DWORD* a2)
{
    int v2; // ebx
    BOOL v3; // eax
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int4 v11; // [esp+10h] [ebp-10h]

    if (a1->field_0 < 0
        || a1->field_4 < 0
        || a1->field_8 > nox_win_width
        || a1->field_C > nox_win_height)
    {
        *a2 = 0;
    }
    v11.field_0 = 0;
    v11.field_4 = 0;
    v11.field_8 = 563;
    if (sub_467C80())
    {
        v2 = 279;
        v11.field_C = 279;
        v3 = sub_4281F0((int2*)a1, &v11);
        if (v3 || (v3 = sub_4281F0((int2*)& a1->field_8, &v11), v3))
        {
            LABEL_12:
            a1->field_4 = v2;
            *a2 = 0;
            goto LABEL_13;
        }
    }
    else
    {
        v2 = 55;
        v11.field_C = 55;
        v3 = sub_4281F0((int2*)a1, &v11);
        if (v3)
            goto LABEL_12;
        v3 = sub_4281F0((int2*)& a1->field_8, &v11);
        if (v3)
            goto LABEL_12;
    }
    LABEL_13:
    if (*(_DWORD*)& byte_587000[80828])
    {
        v11.field_0 = 0;
        v11.field_C = nox_win_height;
        v11.field_8 = 111;
        v11.field_4 = nox_win_height - 127;
        v4 = sub_4281F0((int2*)a1, &v11);
        if (v4 || (v5 = sub_4281F0((int2*)& a1->field_8, &v11), v5))
        {
            a1->field_4 += v11.field_4 - a1->field_C;
            *a2 = 0;
        }
        v11.field_4 = nox_win_height - 74;
        v11.field_0 = nox_win_width / 2 - 160;
        v11.field_8 = v11.field_0 + 320;
        v11.field_C = nox_win_height;
        v6 = sub_4281F0((int2*)a1, &v11);
        if (v6 || (v7 = sub_4281F0((int2*)& a1->field_8, &v11), v7))
        {
            a1->field_4 += v11.field_4 - a1->field_C;
            *a2 = 0;
        }
        v11.field_8 = nox_win_width;
        v11.field_0 = nox_win_width - 91;
        v11.field_C = nox_win_height;
        v11.field_4 = nox_win_height - 201;
        v8 = sub_4281F0((int2*)a1, &v11);
        if (v8 || (v9 = sub_4281F0((int2*)& a1->field_8, &v11), v9))
        {
            a1->field_4 += v11.field_4 - a1->field_C;
            *a2 = 0;
        }
        v3 = sub_4C3260();
        if (v3)
        {
            v11.field_0 = nox_win_width - 87;
            v11.field_4 = 0;
            v11.field_8 = nox_win_width;
            v11.field_C = 145;
            v3 = sub_4281F0((int2*)a1, &v11);
            if (v3 || (v3 = sub_4281F0((int2*)& a1->field_8, &v11), v3))
            {
                a1->field_4 = 145;
                *a2 = 0;
            }
        }
    }
    return v3;
}
// 48E069: variable 'v3' is possibly undefined
// 48E0EF: variable 'v4' is possibly undefined
// 48E104: variable 'v5' is possibly undefined
// 48E156: variable 'v6' is possibly undefined
// 48E16B: variable 'v7' is possibly undefined
// 48E1B4: variable 'v8' is possibly undefined
// 48E1C9: variable 'v9' is possibly undefined

//----- (0048E240) --------------------------------------------------------
char __cdecl sub_48E240(int a1, _DWORD* a2)
{
    int v2; // eax
    _DWORD* v3; // esi
    int v4; // edi
    _DWORD* v5; // ebp
    char v6; // bl
    int v7; // edi
    int v8; // edx
    int v9; // edi
    int v10; // edx
    int v12; // [esp+Ch] [ebp-Ch]
    int v13; // [esp+10h] [ebp-8h]
    int v14; // [esp+14h] [ebp-4h]
    char v15; // [esp+20h] [ebp+8h]

    LOBYTE(v2) = byte_5D4594[1197368];
    v3 = a2;
    if (a2 != *(_DWORD * *)& byte_5D4594[1197368])
    {
        v4 = 0;
        v5 = *(_DWORD * *)& byte_5D4594[1197368];
        if (*(_DWORD*)& byte_5D4594[1197368])
        {
            while (1)
            {
                v2 = v5[165];
                if (v2)
                {
                    v2 = v5[170];
                    if (v2 >= a2[170])
                        goto LABEL_9;
                    v2 = sub_48E480(a2, v5);
                    if (v2)
                        break;
                }
                v5 = (_DWORD*)v5[171];
                if (!v5)
                    return v2;
            }
            v4 = 1;
            LABEL_9:
            if (v5 && v4)
            {
                v6 = 0;
                v15 = 0;
                switch (sub_48E530(v3[162] + v3[168] / 2, v3[163] + v3[169] / 2))
                {
                    case 17:
                        v6 = -96;
                        v15 = 8;
                        break;
                    case 18:
                        v6 = 48;
                        v15 = -118;
                        break;
                    case 20:
                        v6 = -112;
                        v15 = 2;
                        break;
                    case 33:
                        v6 = -64;
                        v15 = 44;
                        break;
                    case 34:
                        v6 = -16;
                        v15 = 15;
                        break;
                    case 36:
                        v6 = -64;
                        v15 = 19;
                        break;
                    case 65:
                        v6 = 96;
                        v15 = 4;
                        break;
                    case 66:
                        v6 = 48;
                        v15 = 69;
                        break;
                    case 68:
                        v6 = 80;
                        v15 = 1;
                        break;
                    default:
                        break;
                }
                v7 = 0;
                while (1)
                {
                    LOBYTE(v2) = 1 << v7;
                    LOBYTE(v14) = 1 << v7;
                    if ((unsigned __int8)(1 << v7) & (unsigned __int8)v6)
                    {
                        sub_48E6A0(v14, v3, v5, &v12, &v13);
                        v2 = sub_48E5C0(v3, v12, v13);
                        if (v2)
                            break;
                    }
                    if (++v7 >= 8)
                        goto LABEL_27;
                }
                v8 = v13;
                v3[162] = v12;
                v3[163] = v8;
                LABEL_27:
                if (v7 == 8)
                {
                    v9 = 0;
                    while (1)
                    {
                        LOBYTE(v2) = 1 << v9;
                        LOBYTE(v14) = 1 << v9;
                        if ((unsigned __int8)(1 << v9) & (unsigned __int8)v15)
                        {
                            sub_48E6A0(v14, v3, v5, &v12, &v13);
                            v2 = sub_48E5C0(v3, v12, v13);
                            if (v2)
                                break;
                        }
                        if (++v9 >= 8)
                            return v2;
                    }
                    v10 = v13;
                    v3[162] = v12;
                    v3[163] = v10;
                }
            }
        }
    }
    return v2;
}

//----- (0048E480) --------------------------------------------------------
BOOL __cdecl sub_48E480(_DWORD* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // esi
    int v4; // edx
    int v5; // ebx
    int v7; // [esp+24h] [ebp-Ch]
    int v8; // [esp+34h] [ebp+4h]

    v2 = sub_43F320(0);
    v3 = a1[162];
    v7 = a1[163] - v2;
    v4 = v2 + v3 + a1[168];
    v5 = v2 + a1[163] + a1[169];
    v8 = a2[163];
    return v3 - v2 < v2 + a2[162] + a2[168] && v4 > a2[162] - v2 && v7 < v2 + v8 + a2[169] && v5 > v8 - v2;
}

//----- (0048E530) --------------------------------------------------------
int __cdecl sub_48E530(int a1, int a2)
{
    int v2; // edi
    int v3; // eax

    if (a1 >= nox_win_width / 3)
    {
        v3 = (a1 >= 2 * nox_win_width / 3) - 1;
        LOBYTE(v3) = v3 & 0xE0;
        v2 = v3 + 64;
    }
    else
    {
        v2 = 16;
    }
    if (a2 < nox_win_height / 3)
        return v2 | 1;
    if (a2 >= 2 * nox_win_height / 3)
        return v2 | 4;
    return v2 | 2;
}

//----- (0048E5C0) --------------------------------------------------------
int __cdecl sub_48E5C0(_DWORD* a1, int a2, int a3)
{
    int v3; // edx
    int v4; // eax
    _DWORD* v6; // edi
    int v7; // ebx
    int v8; // ebp
    BOOL v9; // eax
    BOOL a2a; // [esp+10h] [ebp-14h]
    int4 a1a; // [esp+14h] [ebp-10h]

    a2a = 1;
    sub_43F320(0);
    a1a.field_0 = a2;
    v3 = a1[168];
    a1a.field_4 = a3;
    v4 = a3 + a1[169];
    a1a.field_8 = a2 + v3;
    a1a.field_C = v4;
    sub_48E000(&a1a, &a2a);
    if (!a2a)
        return 0;
    v6 = *(_DWORD * *)& byte_5D4594[1197368];
    if (*(_DWORD*)& byte_5D4594[1197368])
    {
        while (1)
        {
            if (a1[165])
            {
                if (v6[170] >= a1[170])
                    return 1;
                v7 = a1[162];
                v8 = a1[163];
                a1[162] = a2;
                a1[163] = a3;
                v9 = sub_48E480(a1, v6);
                a2a = v9;
                a1[162] = v7;
                a1[163] = v8;
                if (v9)
                    break;
            }
            v6 = (_DWORD*)v6[171];
            if (!v6)
                return 1;
        }
        return 0;
    }
    return 1;
}

//----- (0048E6A0) --------------------------------------------------------
int* __cdecl sub_48E6A0(char a1, _DWORD* a2, _DWORD* a3, int* a4, int* a5)
{
    int* result; // eax
    int v6; // ecx
    _DWORD* v7; // ecx
    int v8; // edx
    char* v9; // edx
    int v10; // edx

    result = (int*)(2 * sub_43F320(0));
    switch (a1)
    {
        case 1:
            *a4 = a3[162] - a2[168] - (_DWORD)result;
            *a5 = a3[163] - a2[169] - (_DWORD)result;
            return result;
        case 2:
            *a4 = (int)result + a3[162] + a3[168];
            v6 = a3[163] - a2[169] - (_DWORD)result;
            result = a5;
            *a5 = v6;
            return result;
        case 4:
            v7 = a3;
            *a4 = a3[162] - a2[168] - (_DWORD)result;
            goto LABEL_8;
        case 8:
            v7 = a3;
            *a4 = (int)result + a3[162] + a3[168];
            goto LABEL_8;
        case 0x10:
            *a4 = a2[162];
            v8 = a3[163] - a2[169] - (_DWORD)result;
            result = a5;
            *a5 = v8;
            return result;
        case 0x20:
            *a4 = a2[162];
            v7 = a3;
        LABEL_8:
            v9 = (char*)result + v7[163] + v7[169];
            result = a5;
            *a5 = (int)v9;
            break;
        case 0x40:
            v10 = a3[162] - a2[168] - (_DWORD)result;
            result = a4;
            *a4 = v10;
            *a5 = a2[163];
            break;
        case 0x80:
            *a4 = (int)result + a3[162] + a3[168];
            result = a5;
            *a5 = a2[163];
            break;
        default:
            return result;
    }
    return result;
}

//----- (0048E8E0) --------------------------------------------------------
void __cdecl sub_48E8E0(int a1)
{
    int v1; // eax
    int v2; // ecx
    int v3; // ecx

    v1 = sub_48D850(a1);
    if (v1)
    {
        v2 = *(_DWORD*)(v1 + 688);
        if (v2)
            * (_DWORD*)(v2 + 684) = *(_DWORD*)(v1 + 684);
        else
            *(_DWORD*)& byte_5D4594[1197368] = *(_DWORD*)(v1 + 684);
        v3 = *(_DWORD*)(v1 + 684);
        if (v3)
            * (_DWORD*)(v3 + 688) = *(_DWORD*)(v1 + 688);
        sub_414330(*(unsigned int**)& byte_5D4594[1197364], (_QWORD*)v1);
    }
}

//----- (0048E940) --------------------------------------------------------
void sub_48E940()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1197364]);
    *(_DWORD*)& byte_5D4594[1197368] = 0;
}

//----- (0048E960) --------------------------------------------------------
void sub_48E960()
{
    nox_srand(0xA32u);
}

//----- (0048E970) --------------------------------------------------------
_DWORD* __cdecl sub_48E970(int a1, unsigned int a2, int a3, int a4)
{
    int v4; // eax
    int v5; // ebx
    _DWORD* v6; // eax
    _DWORD* v7; // esi
    int v8; // eax
    int v10; // [esp-4h] [ebp-10h]

    v4 = sub_578B30(a2);
    v5 = v4;
    v10 = v4;
    if (sub_578B70(a2))
        v6 = sub_45A720(v10);
    else
        v6 = sub_45A6F0(v10);
    v7 = v6;
    if (v6)
    {
        sub_49AA90(v6, a3, a4);
    }
    else
    {
        if (!*(_DWORD*)& byte_5D4594[1200836])
            * (_DWORD*)& byte_5D4594[1200836] = sub_44CFC0((CHAR*)& byte_587000[157096]);
        if (!*(_DWORD*)& byte_5D4594[1200840])
            * (_DWORD*)& byte_5D4594[1200840] = sub_44CFC0((CHAR*)& byte_587000[157104]);
        v8 = sub_45A360_drawable(a1, a3, a4);
        v7 = (_DWORD*)v8;
        if (!v8)
        {
            sub_4356E0();
            return 0;
        }
        *(_DWORD*)(v8 + 128) = v5;
        if (a1 == *(_DWORD*)& byte_5D4594[1200836]
            || a1 == *(_DWORD*)& byte_5D4594[1200840]
            || *(_DWORD*)(v8 + 112) & 0x10000000)
        {
            sub_459DD0(v8, 1);
        }
    }
    sub_45A990_drawable((int)v7);
    sub_49BA10(v7);
    v7[80] = *(_DWORD*)& byte_5D4594[2598000];
    v7[122] = 0;
    return v7;
}
// 48E97E: variable 'v4' is possibly undefined

//----- (0048EA70) --------------------------------------------------------
int __cdecl sub_48EA70(int a1, unsigned int a2, int a3)
{
    unsigned int v3; // ebp
    unsigned int v4; // ebx
    __int64 v5; // rax
    int k; // ecx
    char v7; // cl
    int v8; // esi
    int v9; // edi
    int v10; // ebx
    unsigned __int16 v11; // ax
    unsigned int v12; // esi
    int v13; // eax
    int v14; // esi
    unsigned __int8* v15; // ebp
    int v16; // eax
    int v17; // esi
    int v18; // eax
    int v19; // esi
    int v20; // eax
    int v21; // esi
    int v22; // esi
    int v24; // eax
    int v25; // esi
    int v26; // esi
    _DWORD* v27; // esi
    unsigned __int8 v28; // al
    int v29; // esi
    unsigned __int8 v30; // bl
    unsigned int v31; // eax
    int v32; // ecx
    int v33; // eax
    unsigned int v34; // esi
    char* v35; // ebx
    char* j; // esi
    char* v37; // ebx
    wchar_t* v38; // eax
    char* v39; // eax
    unsigned int v40; // edx
    wchar_t* v41; // eax
    int v42; // eax
    char* v43; // eax
    int v44; // eax
    int v45; // esi
    int v46; // esi
    int v47; // eax
    unsigned int v48; // eax
    int v49; // eax
    int v50; // esi
    int v51; // esi
    int v52; // eax
    unsigned int v53; // eax
    int v54; // eax
    int v55; // esi
    int v56; // eax
    int v57; // eax
    int v58; // esi
    int v59; // eax
    int v60; // esi
    int v61; // esi
    int v62; // eax
    int v63; // esi
    int v64; // eax
    int v65; // esi
    char v66; // cl
    int v67; // eax
    int v68; // eax
    int v69; // eax
    int v70; // esi
    int v71; // eax
    int v72; // esi
    _DWORD* v73; // esi
    int v74; // eax
    int v75; // eax
    unsigned int v76; // eax
    int v77; // eax
    int v78; // esi
    int v79; // edi
    int v80; // esi
    int* v81; // ebx
    int v82; // eax
    int v83; // esi
    int v84; // eax
    int v85; // esi
    int v86; // esi
    char v87; // al
    int v88; // eax
    int v89; // esi
    int v90; // eax
    int v91; // esi
    int v92; // eax
    int v93; // esi
    int v94; // eax
    int v95; // esi
    int v96; // eax
    int v97; // esi
    int v98; // eax
    int v99; // esi
    int v100; // ebx
    int v101; // eax
    int v102; // esi
    int v103; // eax
    int v104; // esi
    int v105; // eax
    int v106; // edi
    int v107; // esi
    char* v108; // ebx
    int v109; // eax
    int v110; // esi
    _DWORD* v111; // esi
    _DWORD* v112; // eax
    int v113; // ecx
    _DWORD* v114; // ebx
    int v115; // eax
    int v116; // edx
    unsigned int v117; // ecx
    unsigned __int16 v118; // ax
    char* v119; // esi
    int v120; // eax
    int v121; // esi
    int v122; // eax
    int v123; // esi
    int v124; // eax
    int v125; // esi
    char* v126; // ebx
    char* v127; // esi
    wchar_t* v128; // eax
    unsigned int v129; // eax
    int v130; // esi
    int v132; // eax
    int v133; // esi
    int v134; // esi
    int v135; // ebx
    int v137; // eax
    int v138; // esi
    int v139; // esi
    int v140; // eax
    int v141; // esi
    char* v142; // esi
    wchar_t* v143; // eax
    char* v144; // esi
    _DWORD* v145; // eax
    wchar_t* v146; // eax
    int v147; // eax
    wchar_t* v148; // eax
    wchar_t* v149; // eax
    int v150; // esi
    wchar_t* v151; // eax
    int v152; // eax
    int v153; // edi
    char* v154; // ebx
    wchar_t* v155; // eax
    wchar_t* v156; // eax
    wchar_t* v157; // eax
    wchar_t* v158; // eax
    wchar_t* v159; // eax
    char* v160; // ebx
    wchar_t* v161; // eax
    _DWORD* v162; // esi
    wchar_t* v163; // eax
    int v164; // esi
    wchar_t* v165; // eax
    wchar_t* v166; // eax
    wchar_t* v167; // eax
    wchar_t* v168; // eax
    wchar_t* v169; // eax
    wchar_t* v170; // eax
    wchar_t* v171; // eax
    char* v172; // ebx
    wchar_t* v173; // eax
    _DWORD* v174; // esi
    wchar_t* v175; // eax
    int v176; // esi
    wchar_t* v177; // eax
    int v178; // eax
    int v179; // esi
    int v180; // eax
    int v181; // esi
    int v182; // eax
    int v183; // esi
    unsigned int v184; // eax
    unsigned int v185; // esi
    unsigned __int16 v186; // ax
    unsigned __int16 v187; // cx
    _DWORD* v188; // eax
    int v189; // eax
    int v190; // esi
    unsigned __int16 v191; // ax
    unsigned __int16 v192; // cx
    unsigned int v193; // eax
    unsigned int v194; // esi
    _DWORD* v195; // eax
    int v196; // eax
    int v197; // esi
    int v198; // eax
    int v199; // ebx
    int v200; // eax
    wchar_t* v201; // eax
    int v202; // edi
    wchar_t* v203; // eax
    wchar_t* v204; // eax
    wchar_t* v205; // eax
    char* v206; // eax
    char* v207; // esi
    int v208; // eax
    int v209; // eax
    int v210; // esi
    char* v211; // ebx
    wchar_t* v212; // ebx
    wchar_t* v213; // eax
    int v214; // eax
    int v215; // esi
    char* v216; // ebx
    wchar_t* v217; // eax
    _DWORD* v218; // eax
    int v219; // edi
    wchar_t* v220; // eax
    unsigned int v221; // eax
    int v222; // eax
    int v223; // esi
    int v224; // eax
    int v225; // eax
    int v226; // eax
    int v227; // esi
    int v228; // ebx
    int v229; // ecx
    int v230; // edi
    int v231; // ebx
    _DWORD* v232; // esi
    char v233; // al
    int v234; // esi
    int v235; // eax
    int v236; // eax
    int v237; // esi
    _DWORD* v238; // eax
    int v239; // ebx
    int v240; // edi
    int v241; // esi
    int v242; // edi
    int v243; // edi
    int v244; // ebx
    int v245; // eax
    _DWORD* v246; // esi
    char v247; // al
    __int16 v248; // ax
    int v249; // esi
    bool v250; // zf
    int v251; // ecx
    unsigned int v252; // ebx
    int v253; // edi
    int v254; // esi
    int v255; // eax
    int v256; // esi
    int v257; // eax
    int v258; // ecx
    int v259; // eax
    int v260; // edi
    int v261; // eax
    int v262; // esi
    int v263; // eax
    int v264; // eax
    int v265; // eax
    int v266; // eax
    int v267; // eax
    int v268; // eax
    int v269; // eax
    int v270; // eax
    wchar_t* v271; // eax
    char* v272; // esi
    _DWORD* v273; // edi
    unsigned int v274; // eax
    unsigned int v275; // esi
    int v276; // ebx
    int v277; // esi
    _DWORD* v278; // ebx
    int v279; // esi
    wchar_t* v280; // esi
    unsigned int v281; // eax
    unsigned int v282; // esi
    int v283; // eax
    int v284; // eax
    unsigned __int16 v285; // ax
    unsigned __int16 v286; // bx
    int v287; // ebx
    char* v288; // edi
    _BYTE* v289; // esi
    wchar_t* v290; // eax
    int v291; // eax
    int v292; // esi
    int v293; // eax
    int v294; // eax
    int v295; // esi
    int v296; // esi
    int v297; // eax
    int v298; // esi
    char* v299; // esi
    char* v300; // eax
    int v301; // eax
    _DWORD* v302; // eax
    char* v303; // esi
    wchar_t* v304; // eax
    wchar_t* v305; // eax
    char* v306; // esi
    wchar_t* v307; // eax
    wchar_t* v308; // eax
    char* v309; // esi
    wchar_t* v310; // eax
    wchar_t* v311; // eax
    wchar_t* v312; // eax
    wchar_t* v314; // [esp-Ch] [ebp-175Ch]
    char v315; // [esp-8h] [ebp-1758h]
    unsigned __int8 v316; // [esp-8h] [ebp-1758h]
    int v317; // [esp-4h] [ebp-1754h]
    int v318; // [esp-4h] [ebp-1754h]
    unsigned __int16 v319; // [esp-4h] [ebp-1754h]
    int v320; // [esp+0h] [ebp-1750h]
    int v321; // [esp+0h] [ebp-1750h]
    int v322; // [esp+0h] [ebp-1750h]
    char v323; // [esp+0h] [ebp-1750h]
    size_t v324; // [esp+0h] [ebp-1750h]
    char v325; // [esp+0h] [ebp-1750h]
    char v326; // [esp+0h] [ebp-1750h]
    int v327; // [esp+0h] [ebp-1750h]
    float v328; // [esp+4h] [ebp-174Ch]
    int v329; // [esp+4h] [ebp-174Ch]
    int v330; // [esp+4h] [ebp-174Ch]
    int v331; // [esp+4h] [ebp-174Ch]
    float v332; // [esp+4h] [ebp-174Ch]
    int v333; // [esp+4h] [ebp-174Ch]
    wchar_t* v334; // [esp+4h] [ebp-174Ch]
    wchar_t* v335; // [esp+4h] [ebp-174Ch]
    wchar_t* v336; // [esp+4h] [ebp-174Ch]
    int v337; // [esp+4h] [ebp-174Ch]
    int v338; // [esp+4h] [ebp-174Ch]
    int v339; // [esp+4h] [ebp-174Ch]
    float v340; // [esp+4h] [ebp-174Ch]
    int v341; // [esp+4h] [ebp-174Ch]
    char v342; // [esp+4h] [ebp-174Ch]
    char* v343; // [esp+4h] [ebp-174Ch]
    size_t v344; // [esp+4h] [ebp-174Ch]
    int v345; // [esp+4h] [ebp-174Ch]
    char v346; // [esp+4h] [ebp-174Ch]
    char v347; // [esp+4h] [ebp-174Ch]
    int v348; // [esp+4h] [ebp-174Ch]
    int v349; // [esp+4h] [ebp-174Ch]
    int v350; // [esp+4h] [ebp-174Ch]
    int v351; // [esp+4h] [ebp-174Ch]
    int v352; // [esp+4h] [ebp-174Ch]
    int v353; // [esp+4h] [ebp-174Ch]
    wchar_t* v354; // [esp+4h] [ebp-174Ch]
    BOOL v355; // [esp+18h] [ebp-1738h]
    unsigned int v356; // [esp+18h] [ebp-1738h]
    int v357; // [esp+18h] [ebp-1738h]
    int* v358; // [esp+18h] [ebp-1738h]
    char v359; // [esp+1Fh] [ebp-1731h]
    int v360; // [esp+20h] [ebp-1730h]
    int i; // [esp+24h] [ebp-172Ch]
    int v362; // [esp+28h] [ebp-1728h]
    int v363; // [esp+2Ch] [ebp-1724h]
    unsigned int v364; // [esp+30h] [ebp-1720h]
    char v365[6]; // [esp+34h] [ebp-171Ch]
    char v366[5]; // [esp+3Ch] [ebp-1714h]
    int v367; // [esp+44h] [ebp-170Ch]
    int v368; // [esp+48h] [ebp-1708h]
    unsigned int v369; // [esp+4Ch] [ebp-1704h]
    int v370; // [esp+50h] [ebp-1700h]
    int v371; // [esp+54h] [ebp-16FCh]
    int v372; // [esp+58h] [ebp-16F8h]
    unsigned int v373; // [esp+5Ch] [ebp-16F4h]
    int v374; // [esp+60h] [ebp-16F0h]
    int v375; // [esp+64h] [ebp-16ECh]
    int v376; // [esp+68h] [ebp-16E8h]
    int2 v377; // [esp+6Ch] [ebp-16E4h]
    int2 v378; // [esp+74h] [ebp-16DCh]
    int2 v379; // [esp+7Ch] [ebp-16D4h]
    int2 v380; // [esp+84h] [ebp-16CCh]
    unsigned __int8 v381[20]; // [esp+8Ch] [ebp-16C4h]
    int v382[8]; // [esp+A0h] [ebp-16B0h]
    int v383[5]; // [esp+C0h] [ebp-1690h]
    int v384[2]; // [esp+D4h] [ebp-167Ch]
    char v385[20]; // [esp+DCh] [ebp-1674h]
    wchar_t v386[20]; // [esp+F0h] [ebp-1660h]
    wchar_t v387[20]; // [esp+118h] [ebp-1638h]
    wchar_t v388[64]; // [esp+140h] [ebp-1610h]
    wchar_t v389[128]; // [esp+1C0h] [ebp-1590h]
    wchar_t v390[128]; // [esp+2C0h] [ebp-1490h]
    wchar_t v391[128]; // [esp+3C0h] [ebp-1390h]
    wchar_t v392[128]; // [esp+4C0h] [ebp-1290h]
    wchar_t v393[128]; // [esp+5C0h] [ebp-1190h]
    wchar_t v394[128]; // [esp+6C0h] [ebp-1090h]
    wchar_t v395[64]; // [esp+7C0h] [ebp-F90h]
    wchar_t v396[64]; // [esp+840h] [ebp-F10h]
    wchar_t v397[100]; // [esp+8C0h] [ebp-E90h]
    wchar_t v398[128]; // [esp+988h] [ebp-DC8h]
    wchar_t v399[100]; // [esp+A88h] [ebp-CC8h]
    wchar_t v400[256]; // [esp+B50h] [ebp-C00h]
    wchar_t v401[128]; // [esp+D50h] [ebp-A00h]
    wchar_t v402[128]; // [esp+E50h] [ebp-900h]
    wchar_t v403[256]; // [esp+F50h] [ebp-800h]
    wchar_t v404[256]; // [esp+1150h] [ebp-600h]
    wchar_t v405[256]; // [esp+1350h] [ebp-400h]
    wchar_t v406[256]; // [esp+1550h] [ebp-200h]

    if (a3)
    {
        //dhexdump((_BYTE*)a2, a3);
    }

    v3 = a2;
    v4 = a3 + a2;
    v364 = 0;
    v369 = a3 + a2;
    sub_470A80();
    if (a2 >= a3 + a2)
        return 1;
    while (1)
    {
        v7 = *(_BYTE*)v3;
        LOBYTE(v375) = *(_BYTE*)v3;
        v8 = (unsigned __int8)v375;
        switch ((unsigned __int8)v375)
        {
            case 0x21u:
                break;
            case 0x27u:
            case 0x28u:
            case 0x2Au:
                v9 = 1;
                if (v7 == 40)
                {
                    *(_DWORD*)& byte_5D4594[2598000] = *(_DWORD*)(v3 + 1);
                    *(_DWORD*)& byte_5D4594[1200800] = *(_DWORD*)& byte_5D4594[2598000];
                    v364 = *(_DWORD*)& byte_5D4594[2598000];
                    *(_DWORD*)& byte_5D4594[1200808] = *(unsigned __int16*)& byte_5D4594[2598000] >> 14;
                    if (*(_DWORD*)& byte_5D4594[2618908])
                        sub_417530(*(int*)& byte_5D4594[2618908], 64);
                    sub_43C650();
                    v3 += 5;
                    break;
                }
                else if (v7 != 39)
                {
                    v14 = *(unsigned __int16*)(v373 + 1);
                    if ((unsigned __int16)v14 < (unsigned int)(*(_DWORD*)& byte_5D4594[1200800] + sub_43C790()))
                        * (_DWORD*)& byte_5D4594[2598000] = v14;
                    v3 += 5;
                    break;
                }
                v373 = v3;
                if (*(_DWORD*)& byte_5D4594[2618908] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 0x40)
                    return 1;
                v10 = *(_DWORD*)& byte_5D4594[2598000];
                v11 = *(_WORD*)(v3 + 1);
                v12 = v11 + (*(_DWORD*)& byte_5D4594[2598000] & 0xFFFF0000);
                v13 = v11 >> 14;
                if (v13 != *(_DWORD*)& byte_5D4594[1200808])
                {
                    if (v13 == ((byte_5D4594[1200808] + 1) & 3))
                    {
                        *(_DWORD*)& byte_5D4594[1200808] = v13;
                        if (!v13)
                            v12 += 0x10000;
                    }
                    else
                    {
                        v9 = 0;
                    }
                }
                if (v12 < *(int*)& byte_5D4594[2598000])
                    v9 = 0;
                if (!sub_40A5C0(1) && v9 == 1)
                {
                    *(_DWORD*)& byte_5D4594[2598000] = v12;
                    *(_DWORD*)& byte_5D4594[1200800] = v12;
                }
                v364 = v12;
                if (!sub_40A5C0(1) && !v9)
                {
                    --* (_DWORD*)& byte_5D4594[2618900];
                    ++* (_DWORD*)& byte_5D4594[2649824];
                    return 1;
                }
                if (*(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(v10 + 1))
                    * (_DWORD*)& byte_5D4594[2618900] += *(_DWORD*)& byte_5D4594[2598000] - v10;
                sub_43C650();
                v3 += 3;
                break;
            case 0x2Bu:
                k = *(_DWORD*)& byte_5D4594[1200804];
                if (*(_DWORD*)(v3 + 37) > * (int*)& byte_5D4594[1200804])
                {
                    sub_40A360(*(_DWORD*)(v3 + 37));
                    sub_467DF0(1);
                    sub_409D70((char*)(v3 + 1));
                    sub_409B10(*(_DWORD*)(v3 + 33));
                    if (!sub_40A5C0(1))
                    {
                        sub_40A540(8);
                        if (*(_DWORD*)& byte_5D4594[2650652])
                            sub_41D6C0();
                    }
                    sub_40A4D0(0x800000);
                    *(_DWORD*)& byte_5D4594[1200804] = *(_DWORD*)& byte_5D4594[2598000];
                    sub_43C720(0);
                    sub_49C7A0();
                    sub_4597E0(0);
                    sub_44A400();
                    sub_413850();
                }
                v3 += 41;
                break;
            case 0x2Cu:
                v42 = sub_578B30(*(_WORD*)(v3 + 1));
                *(_DWORD*)& byte_5D4594[2616328] = v42;
                v43 = sub_416F60(v42);
                if (v43)
                {
                    *((_DWORD*)v43 + 517) = *(_DWORD*)(v3 + 3);
                    *(_DWORD*)& byte_5D4594[2618908] = v43;
                }
                if (!sub_40A5C0(1))
                    sub_57B920(&byte_5D4594[1198020]);
                *(_DWORD*)& byte_5D4594[1200804] = 0;
                v3 += 7;
                *(_DWORD*)& byte_5D4594[2618900] = 0;
                *(_DWORD*)& byte_5D4594[2649824] = 0;
                *(_DWORD*)& byte_5D4594[2614264] = 0;
                *(_DWORD*)& byte_5D4594[1200832] = 0;
                sub_4169D0(0);
                break;
            case 0x2Du:
                v209 = sub_578B30(*(_WORD*)(v3 + 1));
                v210 = v209;
                v360 = v209;
                v211 = sub_416F60(v209);
                if (v211)
                {
                    if (!sub_40A5C0(1))
                    {
                        *((_DWORD*)v211 + 515) = v210;
                        *((_DWORD*)v211 + 534) = *(__int16*)(v3 + 100);
                        *((_DWORD*)v211 + 535) = *(unsigned __int16*)(v3 + 102);
                        *(_DWORD*)v211 = *(_DWORD*)(v3 + 104);
                        *((_DWORD*)v211 + 1) = *(_DWORD*)(v3 + 108);
                        *((_DWORD*)v211 + 538) = *(unsigned __int8*)(v3 + 116);
                        *((_DWORD*)v211 + 539) = *(unsigned __int8*)(v3 + 117);
                        strcpy(v211 + 2096, (const char*)(v3 + 119));
                        *((_DWORD*)v211 + 920) |= *(_DWORD*)(v3 + 112);
                        qmemcpy(v211 + 2185, (const void*)(v3 + 3), 0x61u);
                        nox_swprintf((wchar_t*)v211 + 2352, L"%s%s", v211 + 2185, v211 + 2274);
                        if (*(_DWORD*)& byte_5D4594[2650652])
                        {
                            *((_DWORD*)v211 + 527) = 0;
                            sub_41D670((int)(v211 + 2096));
                        }
                        sub_461460((int)v211);
                        v210 = v360;
                    }
                    v212 = (wchar_t*)(v211 + 4704);
                    sub_457140(v210, v212);
                    sub_455920((int)v212);
                    v213 = loadString_sub_40F1D0((char*)& byte_587000[159072], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4661);
                    nox_swprintf(v399, v213, v212);
                    if (sub_4356B0() == 3)
                        sub_445490(v399);
                    if (v210 == *(_DWORD*)& byte_5D4594[2616328] && nox_wcscmp((const wchar_t*)& byte_5D4594[2661908], v212))
                        * (_DWORD*)& byte_5D4594[1200832] = 1;
                    OnLibraryNotice(263, v211);
                }
                v3 += 129;
                break;
            case 0x2Eu:
                if (sub_43C700())
                {
                    v214 = sub_578B30(*(_WORD*)(v3 + 1));
                    v215 = v214;
                    v216 = sub_417040(v214);
                    if (v216)
                    {
                        sub_456DF0(v215);
                        sub_455950((wchar_t*)v216 + 2352);
                        v217 = loadString_sub_40F1D0((char*)& byte_587000[159128], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4744);
                        nox_swprintf(v397, v217, v216 + 4704);
                        *((_DWORD*)v216 + 523) = 0;
                        v218 = sub_418C80(v215);
                        v219 = (int)v218;
                        OnLibraryNotice(264, v216 + 4704);
                        if (v218 && sub_419130((int)v218))
                            sub_419570(v219, v215);
                    }
                    else
                    {
                        v220 = loadString_sub_40F1D0((char*)& byte_587000[159180], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4757);
                        nox_swprintf(v397, v220);
                    }
                    if (sub_4356B0() == 3)
                        sub_445490(v397);
                }
                v3 += 3;
                break;
            case 0x2Fu:
                sub_578B30(*(_WORD*)(v3 + 1));
                if (sub_43C700())
                {
                    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000000)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    LODWORD(v5) = sub_48E970(
                            *(unsigned __int16*)(v3 + 3),
                            *(unsigned __int16*)(v3 + 1),
                            *(unsigned __int16*)(v3 + 5),
                            *(unsigned __int16*)(v3 + 7));
                    if ((_DWORD)v5)
                    {
                        k = *(_DWORD*)& byte_5D4594[2598000];
                        *(_DWORD*)(v5 + 288) = *(_DWORD*)& byte_5D4594[2598000];
                    }
                }
                v3 += 9;
                break;
            case 0x30u:
                sub_578B30(*(_WORD*)(v3 + 1));
                if (!sub_43C700())
                {
                    v3 += 11;
                    break;
                }
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000000)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (*(_WORD*)(v3 + 3) || *(_WORD*)(v3 + 1))
                {
                    LODWORD(v5) = sub_48E970(
                            *(unsigned __int16*)(v3 + 3),
                            *(unsigned __int16*)(v3 + 1),
                            *(unsigned __int16*)(v3 + 5),
                            *(unsigned __int16*)(v3 + 7));
                    v29 = v5;
                    if ((_DWORD)v5)
                    {
                        *(_DWORD*)(v5 + 288) = *(_DWORD*)& byte_5D4594[2598000];
                        sub_45AB80(v5, *(unsigned __int8*)(v3 + 10));
                        LOBYTE(v5) = (*(_BYTE*)(v3 + 9) >> 4) & 7;
                        *(_BYTE*)(v29 + 297) = v5;
                        if ((unsigned __int8)v5 > 3u)
                            * (_BYTE*)(v29 + 297) = v5 + 1;
                        v30 = *(_BYTE*)(v3 + 9) & 0xF;
                        *(_BYTE*)(v3 + 9) = v30;
                        if (*(_DWORD*)(v29 + 276) != v30)
                        {
                            *(_DWORD*)(v29 + 316) = *(_DWORD*)& byte_5D4594[2598000];
                            HIDWORD(v5) = *(unsigned __int8*)(v3 + 9);
                            *(_DWORD*)(v29 + 276) = HIDWORD(v5);
                        }
                    }
                    k = *(_DWORD*)& byte_5D4594[2616328];
                    if (*(unsigned __int16*)(v3 + 1) == *(_DWORD*)& byte_5D4594[2616328] && sub_416120(9u))
                        sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
                }
                else
                {
                    sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
                    sub_4160D0(9);
                }
                v3 += 11;
                break;
            case 0x31u:
                v44 = sub_578B30(*(_WORD*)(v3 + 1));
                v45 = v44;
                if (!sub_43C700())
                {
                    v3 += 3;
                    break;
                }
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000000)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v45) : sub_45A6F0(v45);
                v46 = v5;
                if (!(_DWORD)v5)
                {
                    v3 += 3;
                    break;
                }
                if (*(int(__cdecl * *)(int*, int))(v5 + 300) == nox_thing_animate_draw)
                {
                    v47 = *(_DWORD*)(v5 + 304);
                    if (v47)
                    {
                        if (*(_DWORD*)(v47 + 12) == 1)
                        {
                            v3 += 3;
                            break;
                        }
                    }
                }
                v48 = sub_578B70(*(unsigned __int16*)(v3 + 1));
                v331 = v46;
                if (!v48)
                    goto LABEL_210;
                sub_45A9A0(v46);
                v3 += 3;
                break;
            case 0x32u:
                v49 = sub_578B30(*(_WORD*)(v3 + 1));
                v50 = v49;
                if (!sub_43C700())
                {
                    v3 += 3;
                    break;
                }
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000000)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v50) : sub_45A6F0(v50);
                v51 = v5;
                if (!(_DWORD)v5)
                {
                    v3 += 3;
                    break;
                }
                if (*(int(__cdecl * *)(int*, int))(v5 + 300) == nox_thing_animate_draw)
                {
                    v52 = *(_DWORD*)(v5 + 304);
                    if (v52)
                    {
                        if (*(_DWORD*)(v52 + 12) == 1)
                        {
                            v3 += 3;
                            break;
                        }
                    }
                }
                if (v51 == *(_DWORD*)& byte_5D4594[2614252])
                {
                    v3 += 3;
                    break;
                }
                v53 = sub_578B70(*(unsigned __int16*)(v3 + 1));
                goto LABEL_208;
            case 0x33u:
                v54 = sub_578B30(*(_WORD*)(v3 + 1));
                v55 = v54;
                if (!sub_43C700())
                {
                    v3 += 3;
                    break;
                }
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v55) : sub_45A6F0(v55);
                v51 = v5;
                if (!(_DWORD)v5)
                {
                    v3 += 3;
                    break;
                }
                k = 1;
                *(_DWORD*)(v5 + 484) = 1;
                *(_DWORD*)(v5 + 480) = 1;
                *(_DWORD*)(v5 + 488) = 1;
                if (*(_DWORD*)& byte_587000[80836])
                {
                    if ((_DWORD)v5 != *(_DWORD*)& byte_5D4594[2614252])
                        sub_49B950((_DWORD*)v5, *(int*)& byte_5D4594[2649704]);
                }
                else if (*(int(__cdecl * *)(int*, int))(v5 + 300) != nox_thing_animate_draw
                         || (v56 = *(_DWORD*)(v5 + 304)) == 0
                         || *(_DWORD*)(v56 + 12) != 1)
                {
                    if (v51 != *(_DWORD*)& byte_5D4594[2614252])
                    {
                        v53 = sub_578B70(*(unsigned __int16*)(v3 + 1));
                        LABEL_208:
                        v331 = v51;
                        if (v53)
                            sub_45A9A0(v51);
                        else
                            LABEL_210:
                            sub_45A4E0_drawable(v331);
                    }
                }
                v3 += 3;
                break;
            case 0x34u:
                v57 = sub_578B30(*(_WORD*)(v3 + 1));
                v58 = v57;
                if (sub_43C700())
                    sub_4959F0(v58);
                v3 += 3;
                break;
            case 0x35u:
                v59 = sub_578B30(*(_WORD*)(v3 + 1));
                v60 = v59;
                if (sub_43C700())
                    sub_495A20(v60);
                v3 += 3;
                break;
            case 0x36u:
                if (sub_43C700())
                    sub_4959B0();
                ++v3;
                break;
            case 0x37u:
                v62 = sub_578B30(*(_WORD*)(v3 + 1));
                v63 = v62;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                        LODWORD(v5) = sub_45A720(v63);
                    else
                        LODWORD(v5) = sub_45A6F0(v63);
                    if ((_DWORD)v5)
                        * (_DWORD*)(v5 + 120) |= 0x1000000u;
                }
                v3 += 3;
                break;
            case 0x38u:
                v64 = sub_578B30(*(_WORD*)(v3 + 1));
                v65 = v64;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                        LODWORD(v5) = sub_45A720(v65);
                    else
                        LODWORD(v5) = sub_45A6F0(v65);
                    if ((_DWORD)v5)
                    {
                        if (*(_DWORD*)(v5 + 112) & 0x40000)
                            * (_DWORD*)(v5 + 300) = 0;
                        *(_DWORD*)(v5 + 120) &= 0xFEFFFFFF;
                    }
                }
                v3 += 3;
                break;
            case 0x39u:
                v16 = sub_578B30(*(_WORD*)(v3 + 1));
                v17 = v16;
                if (!sub_43C700())
                    goto LABEL_764;
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v17) : sub_45A6F0(v17);
                if (!(_DWORD)v5)
                    goto LABEL_764;
                sub_45AB80(v5, *(unsigned __int8*)(v3 + 3));
                v3 += 4;
                break;
            case 0x3Au:
                if (sub_43C700() && !sub_40A5C0(1))
                    sub_410520(*(_WORD*)(v3 + 1));
                v3 += 3;
                break;
            case 0x3Bu:
                if (sub_43C700())
                {
                    if (!sub_40A5C0(1))
                    {
                        LODWORD(v5) = sub_410550(*(_WORD*)(v3 + 1));
                        if ((_DWORD)v5)
                        {
                            if (*(_BYTE*)(v5 + 4) & 4)
                            {
                                v67 = *(_DWORD*)(v5 + 28);
                                *(_BYTE*)(v67 + 22) = 23;
                                *(_BYTE*)(v67 + 21) = 3;
                            }
                        }
                    }
                }
                v3 += 3;
                break;
            case 0x3Cu:
                if (sub_43C700())
                {
                    if (!sub_40A5C0(1))
                    {
                        LODWORD(v5) = sub_410550(*(_WORD*)(v3 + 1));
                        if ((_DWORD)v5)
                        {
                            if (*(_BYTE*)(v5 + 4) & 4)
                            {
                                v68 = *(_DWORD*)(v5 + 28);
                                if (v68)
                                {
                                    *(_BYTE*)(v68 + 22) = 0;
                                    *(_BYTE*)(v68 + 21) = 1;
                                }
                            }
                        }
                    }
                }
                v3 += 3;
                break;
            case 0x3Du:
                if (!sub_43C700())
                    goto LABEL_916;
                LODWORD(v5) = sub_410580(*(unsigned __int8*)(v3 + 4), *(unsigned __int8*)(v3 + 5));
                if (!(_DWORD)v5)
                {
                    LODWORD(v5) = sub_410250(*(unsigned __int8*)(v3 + 4), *(unsigned __int8*)(v3 + 5));
                    if (!(_DWORD)v5)
                        goto LABEL_916;
                }
                v66 = *(_BYTE*)(v3 + 1);
                v3 += 6;
                *(_BYTE*)(v5 + 1) = v66;
                *(_BYTE*)v5 = *(_BYTE*)(v3 - 4);
                *(_BYTE*)(v5 + 2) = *(_BYTE*)(v3 - 3);
                break;
            case 0x3Eu:
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_410580(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
                    if ((_DWORD)v5)
                        sub_410430(*(unsigned __int8*)(v5 + 5), *(unsigned __int8*)(v5 + 6));
                }
                v3 += 3;
                break;
            case 0x41u:
                sub_578B30(*(_WORD*)(v3 + 1));
                if (!sub_43C700())
                    goto LABEL_764;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (!sub_4951F0(*(unsigned __int16*)(v3 + 1)))
                    goto LABEL_764;
                sub_495150(*(unsigned __int16*)(v3 + 1), 2 * *(unsigned __int8*)(v3 + 3));
                v3 += 4;
                break;
            case 0x42u:
                sub_578B30(*(_WORD*)(v3 + 1));
                if (sub_43C700() && (byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                sub_49A650(*(unsigned __int16*)(v3 + 1), *(_WORD*)(v3 + 3));
                v3 += 5;
                break;
            case 0x43u:
                if (sub_43C700())
                    sub_470CB0(*(__int16*)(v3 + 1));
                v3 += 3;
                break;
            case 0x44u:
                v92 = sub_578B30(*(_WORD*)(v3 + 1));
                v93 = v92;
                if (!sub_43C700())
                    goto LABEL_1149;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                sub_4675E0(v93, *(_WORD*)(v3 + 3), *(_WORD*)(v3 + 5));
                v3 += 7;
                break;
            case 0x45u:
                v96 = sub_578B30(*(_WORD*)(v3 + 1));
                v97 = v96;
                if (!sub_43C700())
                    goto LABEL_1163;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (v97 != *(_DWORD*)& byte_5D4594[2616328])
                    goto LABEL_1163;
                sub_470D10(*(unsigned __int16*)(v3 + 3));
                v3 += 5;
                break;
            case 0x47u:
                if (!sub_43C700())
                    goto LABEL_966;
                sub_470D20(*(unsigned __int8*)(v3 + 1), *(int*)& byte_587000[157092]);
                v3 += 2;
                break;
            case 0x48u:
                v98 = sub_578B30(*(_WORD*)(v3 + 1));
                v99 = *(_DWORD*)& byte_5D4594[2618908];
                v100 = v98;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    if (v100 == *(_DWORD*)& byte_5D4594[2616328])
                    {
                        v101 = sub_40A5C0(1);
                        if (!v101 && v99)
                        {
                            *(_DWORD*)(v99 + 2247) = *(unsigned __int16*)(v3 + 3);
                            *(_DWORD*)(v99 + 2243) = *(unsigned __int16*)(v3 + 5);
                            LOWORD(v101) = *(_WORD*)(v3 + 9);
                            v332 = (double)v101;
                            *(_DWORD*)(v99 + 2235) = nox_float2int(v332);
                            *(_DWORD*)(v99 + 2239) = *(unsigned __int16*)(v3 + 11);
                            *(_WORD*)(v99 + 3652) = *(_WORD*)(v3 + 7);
                            *(_BYTE*)(v99 + 3684) = *(_BYTE*)(v3 + 13);
                        }
                        sub_467460();
                    }
                }
                v3 += 14;
                break;
            case 0x49u:
                if (!sub_43C700())
                    goto LABEL_1163;
                sub_467450(*(_DWORD*)(v3 + 1));
                v3 += 5;
                break;
            case 0x4Au:
                v102 = *(_DWORD*)(v3 + 1);
                if (!sub_43C700())
                    goto LABEL_1163;
                sub_467490(v102);
                v3 += 5;
                break;
            case 0x4Bu:
                v103 = sub_578B30(*(_WORD*)(v3 + 1));
                v104 = v103;
                if (!sub_43C700())
                    goto LABEL_1163;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                *(_DWORD*)v381 = 0;
                *(_WORD*)& v381[16] = -1;
                *(_DWORD*)& v381[4] = 0;
                *(_WORD*)& v381[18] = -1;
                *(_DWORD*)& v381[8] = 0;
                *(_DWORD*)& v381[12] = 0;
                if (sub_461660(v104, *(unsigned __int16*)(v3 + 3), v381))
                    goto LABEL_1163;
                sub_461630(v104);
                v3 += 5;
                break;
            case 0x4Cu:
                v105 = sub_578B30(*(_WORD*)(v3 + 1));
                v106 = v105;
                if (!sub_43C700())
                    goto LABEL_735;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                v107 = 0;
                v108 = v385;
                do
                {
                    *(_DWORD*)v108 = sub_413330(*(unsigned __int8*)(v107++ + v3 + 5));
                    v108 += 4;
                } while (v107 < 4);
                *(_WORD*)& v385[16] = -1;
                *(_WORD*)& v385[18] = -1;
                if (sub_461660(v106, *(unsigned __int16*)(v3 + 3), v385))
                    goto LABEL_735;
                sub_461630(v106);
                v3 += 9;
                break;
            case 0x4Du:
                v109 = sub_578B30(*(_WORD*)(v3 + 1));
                v110 = v109;
                if (!sub_43C700())
                    goto LABEL_1163;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                sub_461A80(v110);
                v3 += 5;
                break;
            case 0x4Eu:
                v124 = sub_578B30(*(_WORD*)(v3 + 1));
                v125 = v124;
                v126 = sub_416590(0);
                if (sub_43C700())
                {
                    v127 = sub_417040(v125);
                    if (v127)
                    {
                        if (!sub_40A5C0(1))
                        {
                            *((_DWORD*)v127 + 534) = *(_DWORD*)(v3 + 3);
                            *((_DWORD*)v127 + 535) = *(_DWORD*)(v3 + 7);
                            *((_DWORD*)v127 + 536) = *(_DWORD*)& byte_5D4594[2598000];
                        }
                        if (sub_40A5C0(1024))
                        {
                            k = *(_DWORD*)(v3 + 7);
                            if (k >= *((unsigned __int16*)v126 + 27))
                            {
                                v128 = loadString_sub_40F1D0((char*)& byte_587000[157264], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3452);
                                nox_swprintf(v395, v128, v127 + 4704);
                                sub_452D80(312, 100);
                                sub_445490(v395);
                            }
                        }
                    }
                }
                v3 += 11;
                break;
            case 0x4Fu:
            case 0x50u:
                LODWORD(v5) = sub_43C700();
                if (!(_DWORD)v5)
                    goto LABEL_442;
                LOWORD(v5) = *(_WORD*)(v3 + 1);
                v367 = -1;
                *(_WORD*)(v3 + 1) = v5 & 0x7FFF;
                if ((((unsigned int)v5 >> 15) & 1) == 1)
                {
                    sub_417AA0(*(_BYTE*)v3, *(unsigned __int16*)(v3 + 1), *(_DWORD*)(v3 + 3), (int)& v367);
                    v3 += 7;
                }
                else
                {
                    sub_49A3D0(*(_BYTE*)v3, *(unsigned __int16*)(v3 + 1), *(_DWORD*)(v3 + 3), (int)& v367);
                    LABEL_442:
                    v3 += 7;
                }
                break;
            case 0x51u:
            case 0x52u:
                LODWORD(v5) = sub_43C700();
                if (!(_DWORD)v5)
                    goto LABEL_437;
                LOWORD(v5) = *(_WORD*)(v3 + 1);
                v116 = *(_DWORD*)(v3 + 3);
                v117 = v5;
                v118 = v5 & 0x7FFF;
                *(_WORD*)(v3 + 1) = v118;
                v333 = v3 + 7;
                if (((v117 >> 15) & 1) == 1)
                {
                    sub_417AA0(*(_BYTE*)v3, v118, v116, v333);
                    v3 += 11;
                }
                else
                {
                    sub_49A3D0(*(_BYTE*)v3, v118, v116, v333);
                    LABEL_437:
                    v3 += 11;
                }
                break;
            case 0x53u:
            case 0x54u:
                if (!sub_43C700())
                    goto LABEL_1149;
                sub_417B80(*(_BYTE*)v3, *(unsigned __int16*)(v3 + 1), *(_DWORD*)(v3 + 3));
                v3 += 7;
                break;
            case 0x55u:
                v140 = sub_578B30(*(_WORD*)(v3 + 1));
                v141 = v140;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    v142 = sub_417040(v141);
                    if (v142)
                    {
                        if (!sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2598000] > * ((_DWORD*)v142 + 540))
                        {
                            HIWORD(v5) = 0;
                            *((_DWORD*)v142 + 538) = *(unsigned __int16*)(v3 + 3);
                            WORD2(v5) = *(_WORD*)(v3 + 5);
                            *((_DWORD*)v142 + 539) = WORD2(v5);
                            *((_DWORD*)v142 + 540) = *(_DWORD*)& byte_5D4594[2598000];
                        }
                        k = *((_DWORD*)v142 + 539) - 1;
                        if (*((_DWORD*)v142 + 538) == k)
                        {
                            v143 = loadString_sub_40F1D0((char*)& byte_587000[157316], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3729);
                            nox_swprintf(v406, v143, v142 + 4704);
                            sub_445490(v406);
                        }
                    }
                }
                v3 += 7;
                break;
            case 0x56u:
                v144 = sub_418AB0(*(unsigned __int16*)(v3 + 1));
                if (!sub_43C700())
                    goto LABEL_602;
                HIDWORD(v5) = *(_DWORD*)(v3 + 4);
                if (HIDWORD(v5) <= *(int*)& byte_5D4594[1200804])
                    goto LABEL_602;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                sub_452D80(309, 100);
                if (!sub_40A5C0(1))
                    sub_40A4D0(8);
                sub_435570();
                if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                    sub_470510();
                v145 = sub_418C80(*(int*)& byte_5D4594[2616328]);
                if (v145 && sub_419180((int)v145, *(_BYTE*)(v3 + 1)))
                {
                    v146 = loadString_sub_40F1D0((char*)& byte_587000[157372], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3776);
                    nox_swprintf(v400, v146);
                    v147 = 0;
                }
                else
                {
                    v148 = loadString_sub_40F1D0((char*)& byte_587000[157420], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3781);
                    nox_swprintf(v400, v148, v144);
                    v149 = loadString_sub_40F1D0((char*)& byte_587000[157472], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3782);
                    nox_swprintf(v400, v149, v400);
                    v147 = 1;
                }
                sub_435700(v400, v147);
                sub_4597E0(0);
                v3 += 8;
                break;
            case 0x57u:
                v172 = sub_418AB0(*(unsigned __int16*)(v3 + 1));
                if (!sub_43C700())
                    goto LABEL_602;
                k = *(_DWORD*)& byte_5D4594[1200804];
                if (*(_DWORD*)(v3 + 4) <= *(int*)& byte_5D4594[1200804])
                    goto LABEL_602;
                v393[0] = 0;
                if (*(_BYTE*)(v3 + 3) == 1)
                {
                    v173 = loadString_sub_40F1D0((char*)& byte_587000[158612], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4055);
                    nox_swprintf(v393, v173);
                }
                sub_452D80(309, 100);
                if (!sub_40A5C0(1))
                    sub_40A4D0(8);
                sub_435570();
                if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                    sub_470510();
                v174 = sub_418C80(*(int*)& byte_5D4594[2616328]);
                if (v172)
                {
                    v175 = loadString_sub_40F1D0((char*)& byte_587000[158672], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4071);
                    nox_swprintf(v398, v175, v172);
                    if (!v174 || !sub_419180((int)v174, v172[57]))
                    {
                        v176 = 1;
                        goto LABEL_600;
                    }
                }
                else
                {
                    v177 = loadString_sub_40F1D0((char*)& byte_587000[158724], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4083);
                    nox_swprintf(v398, v177);
                }
                v176 = 0;
            LABEL_600:
                nox_wcscat(v393, v398);
                sub_435700(v393, v176);
                goto LABEL_601;
            case 0x58u:
                v150 = 1;
                v389[0] = 0;
                v392[0] = 0;
                v391[0] = 0;
                if (!sub_43C700())
                    goto LABEL_602;
                HIDWORD(v5) = *(_DWORD*)(v3 + 4);
                if (HIDWORD(v5) <= *(int*)& byte_5D4594[1200804])
                    goto LABEL_602;
                v391[0] = 0;
                if (*(_BYTE*)(v3 + 3) == 1)
                {
                    v151 = loadString_sub_40F1D0((char*)& byte_587000[157524], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3823);
                    nox_swprintf(v391, v151);
                }
                sub_452D80(309, 100);
                if (!sub_40A5C0(1))
                    sub_40A4D0(8);
                if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                    sub_470510();
                sub_435570();
                if (*(_WORD*)(v3 + 1))
                {
                    v152 = sub_578B30(*(_WORD*)(v3 + 1));
                    v372 = v152;
                }
                v153 = v372;
                v154 = sub_417040(v372);
                if (!sub_40A5C0(1024))
                {
                    if (*(_WORD*)(v3 + 1))
                    {
                        if (!v154)
                            goto LABEL_559;
                        if (!*(_BYTE*)(v3 + 3))
                            sub_4947E0((int)v154);
                        if (v153 != *(_DWORD*)& byte_5D4594[2616328])
                        {
                            v159 = loadString_sub_40F1D0((char*)& byte_587000[157884], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3899);
                            nox_swprintf(v389, v159, v154 + 4704);
                            v150 = 1;
                            goto LABEL_559;
                        }
                        if (!v154[2252])
                        {
                            v314 = loadString_sub_40F1D0((char*)& byte_587000[157932], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3905);
                            nox_swprintf(v389, v314);
                            goto LABEL_558;
                        }
                        v155 = loadString_sub_40F1D0((char*)& byte_587000[157988], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3907);
                    }
                    else
                    {
                        v155 = loadString_sub_40F1D0((char*)& byte_587000[157836], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3884);
                    }
                    LABEL_557:
                    nox_swprintf(v389, v155);
                    goto LABEL_558;
                }
                if (!*(_WORD*)(v3 + 1))
                {
                    v155 = loadString_sub_40F1D0((char*)& byte_587000[157584], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3847);
                    goto LABEL_557;
                }
                v156 = loadString_sub_40F1D0((char*)& byte_587000[157632], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3852);
                nox_swprintf(v389, v156);
                if (v153 == *(_DWORD*)& byte_5D4594[2616328])
                {
                    v334 = loadString_sub_40F1D0((char*)& byte_587000[157684], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3855);
                    v157 = loadString_sub_40F1D0((char*)& byte_587000[157732], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3855);
                    nox_swprintf(v392, v157, v334);
                    nox_wcscat(v389, v392);
                    LABEL_558:
                    v150 = 0;
                    goto LABEL_559;
                }
                if (v154)
                {
                    v158 = loadString_sub_40F1D0((char*)& byte_587000[157784], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3863);
                    nox_swprintf(v392, v158, v154 + 4704);
                    if (!*(_BYTE*)(v3 + 3))
                        sub_4947E0((int)v154);
                }
                nox_wcscat(v389, v392);
                v150 = 1;
            LABEL_559:
                nox_wcscat(v391, v389);
                sub_435700(v391, v150);
            LABEL_601:
                sub_4597E0(0);
            LABEL_602:
                v3 += 8;
                break;
            case 0x59u:
                v160 = sub_418AB0(*(unsigned __int16*)(v3 + 1));
                if (!sub_43C700())
                    goto LABEL_602;
                k = *(_DWORD*)& byte_5D4594[1200804];
                if (*(_DWORD*)(v3 + 4) <= *(int*)& byte_5D4594[1200804])
                    goto LABEL_602;
                v394[0] = 0;
                if (*(_BYTE*)(v3 + 3) == 1)
                {
                    v161 = loadString_sub_40F1D0((char*)& byte_587000[158048], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3945);
                    nox_swprintf(v394, v161);
                }
                sub_452D80(309, 100);
                if (!sub_40A5C0(1))
                    sub_40A4D0(8);
                sub_435570();
                if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                    sub_470510();
                v162 = sub_418C80(*(int*)& byte_5D4594[2616328]);
                if (sub_40A5C0(1024))
                {
                    if (!v160)
                    {
                        v163 = loadString_sub_40F1D0((char*)& byte_587000[158108], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3964);
                        nox_swprintf(v390, v163);
                        v164 = 0;
                        goto LABEL_585;
                    }
                    v165 = loadString_sub_40F1D0((char*)& byte_587000[158156], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3969);
                    nox_swprintf(v390, v165);
                    if (v162 && sub_419180((int)v162, v160[57]))
                    {
                        v335 = loadString_sub_40F1D0((char*)& byte_587000[158208], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3973);
                        v166 = loadString_sub_40F1D0((char*)& byte_587000[158260], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3973);
                        nox_swprintf(v388, v166, v335);
                        nox_wcscat(v390, v388);
                        v164 = 0;
                    }
                    else
                    {
                        v336 = loadString_sub_40F1D0((char*)& byte_587000[158312], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3980);
                        v167 = loadString_sub_40F1D0((char*)& byte_587000[158360], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3980);
                        nox_swprintf(v388, v167, v336);
                        nox_swprintf(v396, v388, v160);
                        nox_wcscat(v390, v396);
                        v164 = 1;
                    }
                    if (!*(_BYTE*)(v3 + 3))
                        goto LABEL_584;
                }
                else
                {
                    if (!v160)
                    {
                        v168 = loadString_sub_40F1D0((char*)& byte_587000[158412], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3999);
                        nox_swprintf(v390, v168);
                        v164 = 0;
                        goto LABEL_585;
                    }
                    if (v162 && sub_419180((int)v162, v160[57]))
                    {
                        v169 = loadString_sub_40F1D0((char*)& byte_587000[158460], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4006);
                        nox_swprintf(v390, v169);
                        v164 = 0;
                    }
                    else
                    {
                        v170 = loadString_sub_40F1D0((char*)& byte_587000[158516], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4011);
                        nox_swprintf(v388, v170, v160);
                        v171 = loadString_sub_40F1D0((char*)& byte_587000[158564], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4012);
                        nox_swprintf(v390, v171, v388);
                        v164 = 1;
                    }
                    if (!*(_BYTE*)(v3 + 3))
                    {
                        LABEL_584:
                        sub_4948B0((int)v160);
                        goto LABEL_585;
                    }
                }
            LABEL_585:
                nox_wcscat(v394, v390);
                sub_435700(v394, v164);
                goto LABEL_601;
            case 0x5Au:
                v132 = sub_578B30(*(_WORD*)(v3 + 1));
                v133 = v132;
                if (!sub_43C700())
                    goto LABEL_1149;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v133) : sub_45A6F0(v133);
                v134 = v5;
                if (!(_DWORD)v5)
                    goto LABEL_1149;
                LODWORD(v5) = sub_4356C0(v5, 15);
                HIDWORD(v5) = *(_DWORD*)(v3 + 3);
                v135 = v5;
                *(_DWORD*)(v134 + 124) = HIDWORD(v5);
                if (v134 == *(_DWORD*)& byte_5D4594[2614252])
                    sub_467410(*(_DWORD*)(v3 + 3));
                if (v135 != 1 || sub_4356C0(v134, 15) || v134 == *(_DWORD*)& byte_5D4594[2614252] && sub_467430() & 8)
                    goto LABEL_1149;
                nox_thing* v136 = nox_get_thing(*(_DWORD*)(v134 + 108));
                sub_484D70_light_intensity(v134 + 136, v136->light_intensity);
                v3 += 7;
                break;
            case 0x5Bu:
                if (sub_43C700())
                {
                    LOBYTE(v129) = sub_467430();
                    v130 = (v129 >> 3) & 1;
                    sub_467420(*(_BYTE*)(v3 + 1));
                    if (v130 == 1
                        && !(sub_467430() & 8)
                        && *(_DWORD*)& byte_5D4594[2614252]
                        && !sub_4356C0(*(int*)& byte_5D4594[2614252], 15))
                    {
                        nox_thing* v131 = nox_get_thing(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 108));
                        sub_484D70_light_intensity(*(_DWORD*)& byte_5D4594[2614252] + 136, v131->light_intensity);
                    }
                }
                v3 += 2;
                break;
            case 0x5Cu:
                v88 = sub_578B30(*(_WORD*)(v3 + 1));
                v89 = v88;
                if (!sub_43C700())
                    goto LABEL_902;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v89) : sub_45A6F0(v89);
                if ((_DWORD)v5)
                {
                    sub_484BE0(
                            (_DWORD*)(v5 + 136),
                            *(unsigned __int8*)(v3 + 3),
                            *(unsigned __int8*)(v3 + 4),
                            *(unsigned __int8*)(v3 + 5));
                    v3 += 6;
                }
                else
                {
                    LABEL_902:
                    v3 += 6;
                }
                break;
            case 0x5Du:
                v84 = sub_578B30(*(_WORD*)(v3 + 1));
                v85 = v84;
                if (!sub_43C700())
                    goto LABEL_948;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v85) : sub_45A6F0(v85);
                if (!(_DWORD)v5)
                    goto LABEL_948;
                sub_484D70_light_intensity(v5 + 136, *(float*)(v3 + 3));
                v3 += 7;
                break;
            case 0x5Eu:
                v178 = sub_578B30(*(_WORD*)(v3 + 1));
                v179 = v178;
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v179) : sub_45A6F0(v179);
                    if ((_DWORD)v5)
                    {
                        WORD2(v5) = *(unsigned __int8*)(v3 + 3);
                        *(_WORD*)(v5 + 104) = WORD2(v5);
                    }
                }
                v3 += 4;
                break;
            case 0x5Fu:
                v180 = sub_578B30(*(_WORD*)(v3 + 1));
                v181 = v180;
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v181) : sub_45A6F0(v181);
                    if ((_DWORD)v5)
                    {
                        WORD2(v5) = *(unsigned __int8*)(v3 + 3);
                        HIDWORD(v5) = -HIDWORD(v5);
                        *(_WORD*)(v5 + 104) = WORD2(v5);
                    }
                }
                v3 += 4;
                break;
            case 0x60u:
                v120 = sub_578B30(*(_WORD*)(v3 + 1));
                v121 = v120;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    sub_462040(v121);
                }
                v3 += 3;
                break;
            case 0x61u:
                v122 = sub_578B30(*(_WORD*)(v3 + 1));
                v123 = v122;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    sub_4624D0(v123);
                }
                v3 += 3;
                break;
            case 0x64u:
                v182 = sub_578B30(*(_WORD*)(v3 + 1));
                v183 = v182;
                if (!sub_43C700())
                    goto LABEL_638;
                sub_467930(v183, *(unsigned __int8*)(v3 + 3), *(unsigned __int8*)(v3 + 4));
                v3 += 5;
                break;
            case 0x65u:
                v71 = sub_578B30(*(_WORD*)(v3 + 1));
                v72 = v71;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                        LODWORD(v5) = sub_45A720(v72);
                    else
                        LODWORD(v5) = sub_45A6F0(v72);
                    v73 = (_DWORD*)v5;
                    if ((_DWORD)v5)
                    {
                        v74 = *(_DWORD*)(v5 + 280);
                        v73[70] = *(_DWORD*)(v3 + 3);
                        k = v73[28];
                        if (k & 0x20000)
                        {
                            if (!(v74 & 0x400))
                            {
                                HIDWORD(v5) = v73[70] & 0x400;
                                if (HIDWORD(v5) == 1024)
                                    sub_4BC720((int)v73);
                            }
                            v75 = v73[70];
                            if (v75 & 0x800)
                            {
                                k = v73[28] & 0xFFF7FFFF;
                                v76 = v73[30] & 0xDFFFFFFF;
                                v73[28] = k;
                                v73[30] = v76;
                            }
                        }
                    }
                }
                v3 += 7;
                break;
            case 0x66u:
                if (sub_43C700() && *(_DWORD*)& byte_5D4594[2614252])
                {
                    HIDWORD(v5) = *(_DWORD*)(v3 + 1);
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 120) = HIDWORD(v5);
                }
                v3 += 5;
                break;
            case 0x67u:
                v77 = sub_578B30(*(_WORD*)(v3 + 1));
                v78 = v77;
                if (sub_43C700())
                {
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*(unsigned __int16*)(v3 + 1));
                    if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                        LODWORD(v5) = sub_45A720(v78);
                    else
                        LODWORD(v5) = sub_45A6F0(v78);
                    if ((_DWORD)v5)
                    {
                        v79 = v5 + 432;
                        if ((_DWORD)v5 != (_DWORD)-432)
                        {
                            v80 = 0;
                            v81 = (int*)(v5 + 432);
                            do
                            {
                                *v81 = sub_413330(*(unsigned __int8*)(v80++ + v3 + 3));
                                ++v81;
                            } while (v80 < 4);
                            *(_WORD*)(v79 + 16) = -1;
                            *(_WORD*)(v79 + 18) = -1;
                        }
                    }
                }
                v3 += 7;
                break;
            case 0x68u:
                v82 = sub_578B30(*(_WORD*)(v3 + 1));
                v83 = v82;
                if (!sub_43C700())
                    goto LABEL_1057;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (v83 == *(_DWORD*)& byte_5D4594[2616328])
                {
                    LOBYTE(k) = *(_BYTE*)(v3 + 7);
                    sub_467470(k, *(float*)(v3 + 3));
                    v3 += 8;
                }
                else
                {
                    LABEL_1057:
                    v3 += 8;
                }
                break;
            case 0x69u:
                if (sub_43C700())
                {
                    v285 = *(_WORD*)(v3 + 1);
                    v286 = v285;
                    v285 &= 0x7FFFu;
                    *(_WORD*)(v3 + 1) = v285;
                    v287 = v286 >> 15;
                    v288 = nox_npc_by_id(v285);
                    if (v288)
                    {
                        LODWORD(v5) = nox_init_npc(v288, *(unsigned __int16 *) (v3 + 1));
                    }
                    else
                    {
                        LODWORD(v5) = nox_new_npc(*(unsigned __int16*)(v3 + 1));
                        v288 = (char*)v5;
                    }
                    if (v288)
                    {
                        k = (int)(v288 + 8);
                        v289 = (_BYTE*)(v3 + 4);
                        v358 = (int*)(v288 + 8);
                        v360 = 6;
                        do
                        {
                            BYTE4(v5) = v289[1];
                            LOBYTE(v5) = *v289;
                            LOBYTE(k) = *(v289 - 1);
                            v289 += 3;
                            *v358 = sub_4344A0(k, v5, SHIDWORD(v5));
                            k = (int)(v358 + 1);
                            LODWORD(v5) = v360 - 1;
                            v250 = v360 == 1;
                            ++v358;
                            --v360;
                        } while (!v250);
                        *((_DWORD*)v288 + 328) = v287;
                    }
                }
                v3 += 21;
                break;
            case 0x6Au:
                v119 = sub_417040(*(unsigned __int16*)(v3 + 1));
                if (!v119)
                    goto LABEL_1070;
                if (!sub_40A5C0(1))
                {
                    sub_417530((int)v119, 1059);
                    sub_4174F0((int)v119, *(_DWORD*)(v3 + 3) & 0x423);
                }
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000
                    || (HIDWORD(v5) = *(unsigned __int16*)(v3 + 1), WORD2(v5) != *(_DWORD*)& byte_5D4594[2616328]))
                {
                    LABEL_1070:
                    v3 += 7;
                }
                else
                {
                    if (v119[3680] & 1)
                    {
                        *(_DWORD*)& byte_587000[80828] = 0;
                    }
                    else if (*(_DWORD*)& byte_587000[80832] == 1)
                    {
                        *(_DWORD*)& byte_587000[80828] = 1;
                    }
                    sub_470C40((*((_DWORD*)v119 + 920) >> 10) & 1);
                    v3 += 7;
                }
                break;
            case 0x6Bu:
                v69 = sub_578B30(*(_WORD*)(v3 + 1));
                v70 = v69;
                if (!sub_43C700())
                    goto LABEL_948;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v70) : sub_45A6F0(v70);
                if (!(_DWORD)v5)
                    goto LABEL_948;
                sub_45AB80(v5, *(_DWORD*)(v3 + 3));
                v3 += 7;
                break;
            case 0x6Cu:
                v184 = sub_578B30(*(_WORD*)(v3 + 1));
                v185 = v184;
                if (!sub_43C700())
                    goto LABEL_638;
                v186 = *(_WORD*)(v3 + 3);
                v187 = v186;
                v186 &= 0x7FFFu;
                *(_WORD*)(v3 + 3) = v186;
                sub_4C2E50(*(unsigned __int16*)(v3 + 1), v186, v187 & 0x8000);
                if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                    v188 = sub_45A720(v185);
                else
                    v188 = sub_45A6F0(v185);
                if (v188 || (v188 = sub_48E970(*(unsigned __int16*)(v3 + 3), v185, 0, 0)) != 0)
                    sub_459DD0((int)v188, 1);
                sub_495060(*(unsigned __int16*)(v3 + 1), 0, 0);
                v3 += 5;
                break;
            case 0x6Du:
                v189 = sub_578B30(*(_WORD*)(v3 + 1));
                v190 = v189;
                if (!sub_43C700())
                {
                    v3 += 3;
                    break;
                }
                v191 = *(_WORD*)(v3 + 1);
                v192 = v191;
                v191 &= 0x7FFFu;
                *(_WORD*)(v3 + 1) = v191;
                sub_4C3140(v191, (void*)(v192 & 0x8000));
                sub_4950C0(*(unsigned __int16*)(v3 + 1));
                v337 = v190;
                if (!sub_578B70(*(unsigned __int16*)(v3 + 1)))
                    goto LABEL_642;
                LODWORD(v5) = sub_45A720(v190);
                goto LABEL_643;
            case 0x6Eu:
                if (!sub_43C700())
                    goto LABEL_1163;
                sub_467440(*(_DWORD*)(v3 + 1));
                v3 += 5;
                break;
            case 0x6Fu:
                v139 = 0;
                if (sub_43C700())
                {
                    if (*(_BYTE*)(v3 + 3) & 0x80)
                        v139 = 1;
                    sub_45CFE0(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2), *(_BYTE*)(v3 + 3) & 0x7F, v139);
                }
                v3 += 4;
                break;
            case 0x70u:
                sub_49BB80(*(_BYTE*)(v3 + 1));
                v3 += 2;
                break;
            case 0x71u:
                sub_467CA0();
                ++v3;
                break;
            case 0x7Cu:
                v236 = sub_578B30(*(_WORD*)(v3 + 8));
                v237 = v236;
                if (sub_43C700())
                {
                    if (sub_578B70(*(unsigned __int16*)(v3 + 8)))
                        v238 = sub_45A720(v237);
                    else
                        v238 = sub_45A6F0(v237);
                    HIWORD(k) = 0;
                    v382[0] = (int)v238;
                    LOWORD(k) = *(_WORD*)(v3 + 2);
                    HIWORD(v5) = 0;
                    v382[5] = (unsigned __int16)k;
                    WORD2(v5) = *(_WORD*)(v3 + 4);
                    v382[6] = WORD2(v5);
                    v382[7] = *(unsigned __int16*)(v3 + 6);
                    switch (*(unsigned __int8*)(v3 + 1))
                    {
                        case 0u:
                            sub_4AEEA0((unsigned __int8**)v382);
                            break;
                        case 1u:
                            sub_4AEF80(v382);
                            break;
                        case 2u:
                            sub_4AF0F0((unsigned __int8**)v382);
                            break;
                        case 3u:
                            sub_4AF2A0((unsigned __int8**)v382);
                            break;
                        case 4u:
                            sub_4AF3D0(v382);
                            break;
                        case 5u:
                            sub_4AF450(v382);
                            break;
                        case 6u:
                            sub_4AF5A0(v382);
                            break;
                    }
                }
                v3 += 14;
                break;
            case 0x7Du:
            case 0x8Cu:
            case 0x8Du:
            case 0x8Eu:
                if (!sub_43C700())
                    goto LABEL_732;
                sub_49BDD0((unsigned __int8*)v3);
                HIWORD(k) = 0;
                v379.field_0 = *(unsigned __int16*)(v3 + 1);
                v379.field_4 = *(unsigned __int16*)(v3 + 3);
                LOWORD(k) = *(_WORD*)(v3 + 5);
                HIWORD(v5) = 0;
                v377.field_0 = (unsigned __int16)k;
                WORD2(v5) = *(_WORD*)(v3 + 7);
                v377.field_4 = WORD2(v5);
                LOBYTE(v5) = *(_BYTE*)v3;
                if (*(_BYTE*)v3 == (_BYTE)-116 || (_BYTE)v5 == (_BYTE)-114)
                {
                    sub_4999D0(*(int*)& byte_5D4594[1200776], &v379, &v377);
                }
                else if ((_BYTE)v5 == 125)
                {
                    sub_499710(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7), 10, *(int*)& byte_5D4594[1200776]);
                    v3 += 9;
                    break;
                }
            LABEL_732:
                v3 += 9;
                break;
            case 0x7Eu:
                if (sub_43C700())
                {
                    sub_4B7C40(
                            *(_WORD*)(v3 + 5),
                            (unsigned __int16*)(v3 + 1),
                            *(_WORD*)(v3 + 7),
                            *(_BYTE*)(v3 + 9),
                            *(_WORD*)(v3 + 10));
                    v3 += 12;
                }
                else
                {
                    LABEL_1130:
                    v3 += 12;
                }
                break;
            case 0x7Fu:
                if (sub_43C700())
                    sub_4B7EE0(*(_WORD*)(v3 + 1));
                v3 += 3;
                break;
            case 0x80u:
                if (sub_43C700())
                    sub_4B8090(*(unsigned __int16*)(v3 + 1), *(unsigned __int8*)(v3 + 3));
                goto LABEL_764;
            case 0x81u:
                if (!sub_43C700())
                    goto LABEL_797;
                sub_499610(*(int*)& byte_5D4594[1200776], 50, 1000, 30, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
                v3 += 5;
                break;
            case 0x82u:
                if (!sub_43C700())
                    goto LABEL_797;
                sub_499610(*(int*)& byte_5D4594[1200780], 25, 500, 25, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
                v3 += 5;
                break;
            case 0x83u:
                if (!sub_43C700())
                    goto LABEL_797;
                sub_499610(*(int*)& byte_5D4594[1200784], 25, 500, 25, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
                v3 += 5;
                break;
            case 0x84u:
                if (sub_43C700())
                    sub_499610(*(int*)& byte_5D4594[1200796], 25, 500, 25, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
            LABEL_797:
                v3 += 5;
                break;
            case 0x85u:
            case 0x86u:
            case 0x87u:
            case 0x88u:
            case 0x89u:
            case 0x8Au:
            case 0x8Bu:
            case 0xA3u:
                if (sub_43C700())
                {
                    k = 0;
                    switch (v8)
                    {
                        case 133:
                            v257 = *(_DWORD*)& byte_5D4594[1200872];
                            if (!*(_DWORD*)& byte_5D4594[1200872])
                            {
                                v257 = sub_44CFC0((CHAR*)& byte_587000[160152]);
                                *(_DWORD*)& byte_5D4594[1200872] = v257;
                            }
                            v258 = *(__int16*)(v3 + 3);
                            goto LABEL_858;
                        case 134:
                            v257 = *(_DWORD*)& byte_5D4594[1200876];
                            if (!*(_DWORD*)& byte_5D4594[1200876])
                            {
                                v257 = sub_44CFC0((CHAR*)& byte_587000[160164]);
                                *(_DWORD*)& byte_5D4594[1200876] = v257;
                            }
                            v258 = *(__int16*)(v3 + 3);
                            goto LABEL_858;
                        case 135:
                            v257 = *(_DWORD*)& byte_5D4594[1200880];
                            if (!*(_DWORD*)& byte_5D4594[1200880])
                            {
                                v257 = sub_44CFC0((CHAR*)& byte_587000[160180]);
                                *(_DWORD*)& byte_5D4594[1200880] = v257;
                            }
                            v258 = *(__int16*)(v3 + 3);
                            goto LABEL_858;
                        case 136:
                            v257 = *(_DWORD*)& byte_5D4594[1200884];
                            if (!*(_DWORD*)& byte_5D4594[1200884])
                            {
                                v257 = sub_44CFC0((CHAR*)& byte_587000[160200]);
                                *(_DWORD*)& byte_5D4594[1200884] = v257;
                            }
                            v258 = *(__int16*)(v3 + 3);
                            goto LABEL_858;
                        case 137:
                            v257 = *(_DWORD*)& byte_5D4594[1200888];
                            if (!*(_DWORD*)& byte_5D4594[1200888])
                            {
                                v257 = sub_44CFC0((CHAR*)& byte_587000[160216]);
                                *(_DWORD*)& byte_5D4594[1200888] = v257;
                            }
                            goto LABEL_857;
                        case 138:
                            if (!*(_DWORD*)& byte_5D4594[1200900])
                            {
                                *(_DWORD*)& byte_5D4594[1200900] = sub_44CFC0((CHAR*)& byte_587000[160244]);
                                *(_DWORD*)& byte_5D4594[1200896] = sub_44CFC0((CHAR*)& byte_587000[160252]);
                            }
                            v259 = sub_45A360_drawable(*(int*)& byte_5D4594[1200900], *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
                            if (v259)
                            {
                                *(_WORD*)(v259 + 104) = 20;
                                sub_45A110_drawable((_DWORD*)v259);
                            }
                            v260 = 6;
                            do
                            {
                                v341 = *(__int16*)(v3 + 3) + sub_415FF0(-15, 15, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5711);
                                v261 = sub_415FF0(-15, 15, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5710);
                                v262 = sub_45A360_drawable(*(int*)& byte_5D4594[1200896], *(__int16*)(v3 + 1) + v261, v341);
                                if (v262)
                                {
                                    *(_WORD*)(v262 + 104) = sub_415FF0(5, 25, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5712);
                                    sub_45A110_drawable((_DWORD*)v262);
                                }
                                --v260;
                            } while (v260);
                            goto LABEL_868;
                        case 139:
                            v257 = *(_DWORD*)& byte_5D4594[1200892];
                            if (!*(_DWORD*)& byte_5D4594[1200892])
                            {
                                v257 = sub_44CFC0((CHAR*)& byte_587000[160232]);
                                *(_DWORD*)& byte_5D4594[1200892] = v257;
                            }
                        LABEL_857:
                            v258 = *(__int16*)(v3 + 3) + 2;
                        LABEL_858:
                            LODWORD(v5) = sub_45A360_drawable(v257, *(__int16*)(v3 + 1), v258);
                            if (!(_DWORD)v5)
                                goto LABEL_868;
                            sub_45A110_drawable((_DWORD*)v5);
                            v3 += 5;
                            break;
                        case 163:
                            v340 = sub_419D40(&byte_587000[159972]);
                            v252 = nox_float2int(v340);
                            v357 = 150;
                            v253 = v252 >> 2;
                            for (i = v252 >> 2; ; v253 = i)
                            {
                                v254 = v253 + sub_415FF0(0, v252, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5536);
                                if (v254 > (int)v252)
                                    v254 = v252;
                                v255 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5541);
                                LODWORD(v5) = sub_45A360_drawable(
                                        *(int*)& byte_5D4594[1200784],
                                        *(__int16*)(v3 + 1) + v254 * *(int*)& byte_587000[8 * v255 + 192088] / 16,
                                        *(__int16*)(v3 + 3) + v254 * *(int*)& byte_587000[8 * v255 + 192092] / 16);
                                v256 = v5;
                                if ((_DWORD)v5)
                                {
                                    *(_DWORD*)(v5 + 432) = *(_DWORD*)(v5 + 12) << 12;
                                    *(_DWORD*)(v5 + 436) = *(_DWORD*)(v5 + 16) << 12;
                                    *(_BYTE*)(v5 + 299) = 0;
                                    *(_DWORD*)(v5 + 440) = 0;
                                    *(_DWORD*)(v5 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                                           + sub_415FF0(30, 40, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5562);
                                    *(_DWORD*)(v256 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                                    *(_WORD*)(v256 + 104) = 0;
                                    *(_BYTE*)(v256 + 296) = sub_415FF0(4, 10, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5568);
                                    sub_45A110_drawable((_DWORD*)v256);
                                }
                                if (!--v357)
                                    break;
                            }
                            v3 += 5;
                            break;
                        default:
                            goto LABEL_868;
                    }
                }
                else
                {
                    LABEL_868:
                    v3 += 5;
                }
                break;
            case 0x8Fu:
            case 0x90u:
            case 0x91u:
                if (sub_43C700())
                    sub_49BDD0((unsigned __int8*)v3);
            LABEL_735:
                v3 += 9;
                break;
            case 0x93u:
                if (!*(_DWORD*)& byte_5D4594[1200852])
                {
                    *(_DWORD*)& byte_5D4594[1200852] = sub_44CFC0((CHAR*)& byte_587000[159532]);
                    *(_DWORD*)& byte_5D4594[1200856] = sub_44CFC0((CHAR*)& byte_587000[159540]);
                    *(_DWORD*)& byte_5D4594[1197380] = sub_44CFC0((CHAR*)& byte_587000[159556]);
                }
                if (!sub_43C700())
                    goto LABEL_916;
                v378.field_0 = *(__int16*)(v3 + 1);
                v378.field_4 = *(__int16*)(v3 + 3);
                sub_49A150(&v378, *(int*)& byte_5D4594[1200852], *(_BYTE*)(v3 + 5));
                v235 = *(_DWORD*)& byte_5D4594[1197380];
                if (*(_BYTE*)(v3 + 5) <= 0xAAu)
                    v235 = *(_DWORD*)& byte_5D4594[1200856];
                LODWORD(v5) = sub_45A360_drawable(v235, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
                goto LABEL_829;
            case 0x94u:
                if (sub_43C700())
                {
                    v241 = *(unsigned __int16*)(v3 + 5) - *(unsigned __int16*)(v3 + 1);
                    v242 = *(unsigned __int16*)(v3 + 7) - *(unsigned __int16*)(v3 + 3);
                    LODWORD(v5) = nox_double2int(sqrt((double)(v241 * v241 + v242 * v242))) + 1;
                    v371 = v5;
                    if ((int)v5 >= 0)
                    {
                        v360 = 0;
                        v363 = 0;
                        i = 2 * v242;
                        v374 = 2 * v241;
                        v356 = (unsigned int)(v5 + 2) >> 1;
                        do
                        {
                            v243 = *(unsigned __int16*)(v3 + 1) + v363 / v371;
                            v244 = *(unsigned __int16*)(v3 + 3) + v360 / v371;
                            v245 = sub_45A360_drawable(*(int*)& byte_5D4594[1200796], v243, v244);
                            v362 = v245;
                            if (v245)
                            {
                                v246 = (_DWORD*)(v245 + 432);
                                if (v245 != -432)
                                {
                                    *(_DWORD*)(v245 + 432) = v243 << 12;
                                    *(_DWORD*)(v245 + 436) = v244 << 12;
                                    v247 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5393);
                                    *(_BYTE*)(v362 + 299) = v247;
                                    v246[2] = sub_415FF0(1, 200, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5396);
                                    v246[4] = *(_DWORD*)& byte_5D4594[2598000]
                                              + sub_415FF0(20, 40, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5399);
                                    v246[3] = *(_DWORD*)& byte_5D4594[2598000];
                                }
                                v248 = sub_415FF0(15, 30, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5405);
                                v249 = v362;
                                *(_WORD*)(v362 + 104) = v248;
                                *(_BYTE*)(v249 + 296) = sub_415FF0(-4, 4, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5406);
                                sub_45A110_drawable((_DWORD*)v249);
                            }
                            k = i;
                            HIDWORD(v5) = i + v360;
                            v250 = v356 == 1;
                            v363 += v374;
                            v360 += i;
                            --v356;
                        } while (!v250);
                    }
                }
                v3 += 9;
                break;
            case 0x95u:
                if (sub_43C700())
                {
                    sub_4C5020(v3);
                    if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4987) < 25)
                    {
                        if (*(_DWORD*)& byte_5D4594[2614252])
                        {
                            v225 = *(unsigned __int16*)(v3 + 5) - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 12);
                            v226 = nox_double2int(sqrt((double)(v225 * v225
                                                            + (*(unsigned __int16*)(v3 + 7)
                                                               - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 16))
                                                              * (*(unsigned __int16*)(v3 + 7)
                                                                 - *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 16)))));
                            if (v226 < 600)
                                sub_452D80(297, 100 * (600 - v226) / 600);
                        }
                    }
                    if (!sub_413A50())
                    {
                        v227 = *(unsigned __int16*)(v3 + 5) - *(unsigned __int16*)(v3 + 1);
                        v228 = *(unsigned __int16*)(v3 + 7) - *(unsigned __int16*)(v3 + 3);
                        v229 = nox_double2int(sqrt((double)(v227 * v227 + v228 * v228)));
                        if (!v229)
                            v229 = 1;
                        v230 = *(unsigned __int16*)(v3 + 5) - 4 * v227 / v229;
                        v231 = *(unsigned __int16*)(v3 + 7) - 4 * v228 / v229;
                        LODWORD(v5) = sub_45A360_drawable(*(int*)& byte_5D4594[1200796], v230, v231);
                        v362 = v5;
                        if ((_DWORD)v5)
                        {
                            v232 = (_DWORD*)(v5 + 432);
                            if ((_DWORD)v5 != (_DWORD)-432)
                            {
                                *(_DWORD*)(v5 + 432) = v230 << 12;
                                *(_DWORD*)(v5 + 436) = v231 << 12;
                                v233 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5024);
                                *(_BYTE*)(v362 + 299) = v233;
                                v232[2] = sub_415FF0(1, 1500, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5027);
                                v232[4] = *(_DWORD*)& byte_5D4594[2598000] + sub_415FF0(5, 20, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5030);
                                v232[3] = *(_DWORD*)& byte_5D4594[2598000];
                            }
                            v234 = v362;
                            *(_WORD*)(v362 + 104) = 22;
                            *(_BYTE*)(v234 + 296) = sub_415FF0(-4, 4, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5037);
                            sub_45A110_drawable((_DWORD*)v234);
                        }
                    }
                }
                v3 += 9;
                break;
            case 0x96u:
                if (sub_43C700())
                {
                    if (!*(_DWORD*)& byte_5D4594[1200860])
                        * (_DWORD*)& byte_5D4594[1200860] = sub_44CFC0((CHAR*)& byte_587000[159568]);
                    v239 = 5;
                    do
                    {
                        LODWORD(v5) = sub_45A360_drawable(*(int*)& byte_5D4594[1200860], *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
                        v240 = v5;
                        if ((_DWORD)v5)
                        {
                            if ((_DWORD)v5 != (_DWORD)-432)
                            {
                                *(_DWORD*)(v5 + 432) = *(_DWORD*)(v5 + 12) << 12;
                                *(_DWORD*)(v5 + 436) = *(_DWORD*)(v5 + 16) << 12;
                                *(_BYTE*)(v5 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5338);
                                *(_DWORD*)(v240 + 440) = sub_415FF0(1333, 4000, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5341);
                                *(_DWORD*)(v240 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                                         + sub_415FF0(5, 20, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5344);
                                *(_DWORD*)(v240 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                            }
                            *(_WORD*)(v240 + 104) = 20;
                            *(_BYTE*)(v240 + 296) = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5351);
                            sub_45A110_drawable((_DWORD*)v240);
                        }
                        --v239;
                    } while (v239);
                }
                v3 += 5;
                break;
            case 0x97u:
                if (sub_43C700())
                    sub_4355B0(*(unsigned __int8*)(v3 + 1) / 3);
                v3 += 2;
                break;
            case 0x98u:
                if (!*(_DWORD*)& byte_5D4594[1200844])
                    * (_DWORD*)& byte_5D4594[1200844] = sub_44CFC0((CHAR*)& byte_587000[159192]);
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_45A360_drawable(
                            *(int*)& byte_5D4594[1200844],
                            *(unsigned __int16*)(v3 + 1)
                            + (*(unsigned __int16*)(v3 + 5) - *(unsigned __int16*)(v3 + 1)) / 2,
                            *(unsigned __int16*)(v3 + 3)
                            + (*(unsigned __int16*)(v3 + 7) - *(unsigned __int16*)(v3 + 3)) / 2)
                                  + 432;
                    *(_BYTE*)v5 = 0;
                    *(_DWORD*)(v5 + 5) = *(_DWORD*)(v3 + 1);
                    HIDWORD(v5) = *(_DWORD*)(v3 + 5);
                    *(_DWORD*)(v5 + 9) = HIDWORD(v5);
                    k = *(unsigned __int16*)(v3 + 9);
                    *(_DWORD*)(v5 + 1) = k;
                }
                v3 += 11;
                break;
            case 0x9Au:
                if (sub_43C700())
                    sub_473920();
                v3 += 5;
                break;
            case 0x9Bu:
            case 0x9Cu:
            case 0x9Du:
                if (sub_43C700())
                    sub_4A9D00((unsigned __int8*)v3);
                v3 += 3;
                break;
            case 0x9Eu:
                LOBYTE(v376) = *(_BYTE*)(v3 + 1);
                switch ((unsigned __int8)v376)
                {
                    case 1u:
                    case 2u:
                    case 3u:
                    case 4u:
                    case 5u:
                    case 6u:
                    case 7u:
                        if (sub_43C700())
                            sub_49C160(v3);
                        goto LABEL_1070;
                    case 8u:
                    case 9u:
                    case 0xAu:
                    case 0xBu:
                    case 0xCu:
                    case 0xDu:
                    case 0xEu:
                        if (!sub_43C700())
                            goto LABEL_1070;
                        sub_49C450(v3);
                        v3 += 7;
                        break;
                    default:
                        return 0;
                }
                break;
            case 0x9Fu:
                v297 = sub_578B30(*(_WORD*)(v3 + 1));
                v298 = v297;
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v298) : sub_45A6F0(v298);
                    if ((_DWORD)v5)
                    {
                        LODWORD(v5) = v5 + 432;
                        *(_DWORD*)v5 = *(_DWORD*)& byte_5D4594[2598000];
                        i = *(char*)(v3 + 4);
                        *(float*)(v5 + 8) = (double)i;
                        k = *(unsigned __int8*)(v3 + 3);
                        i = *(unsigned __int8*)(v3 + 3);
                        *(float*)(v5 + 4) = (double)i;
                        HIDWORD(v5) = *(unsigned __int8*)(v3 + 5);
                        i = *(unsigned __int8*)(v3 + 5);
                        *(float*)(v5 + 12) = (double)i;
                    }
                }
                v3 += 6;
                break;
            case 0xA0u:
                if (!sub_43C700())
                    goto LABEL_1163;
                sub_499880((__int16*)(v3 + 1));
                v3 += 5;
                break;
            case 0xA1u:
                if (!sub_43C700())
                    goto LABEL_916;
                if (!*(_DWORD*)& byte_5D4594[1200864])
                {
                    *(_DWORD*)& byte_5D4594[1200864] = sub_44CFC0((CHAR*)& byte_587000[159940]);
                    *(_DWORD*)& byte_5D4594[1200868] = sub_44CFC0((CHAR*)& byte_587000[159956]);
                }
                v251 = *(__int16*)(v3 + 1);
                v339 = *(__int16*)(v3 + 3);
                if (*(_BYTE*)(v3 + 5) == 1)
                {
                    LODWORD(v5) = sub_45A360_drawable(*(int*)& byte_5D4594[1200864], v251 + 15, v339);
                    if ((_DWORD)v5)
                    {
                        sub_45A110_drawable((_DWORD*)v5);
                        v3 += 6;
                        break;
                    }
                }
                else
                {
                    LODWORD(v5) = sub_45A360_drawable(*(int*)& byte_5D4594[1200868], v251 - 3, v339);
                    LABEL_829:
                    if ((_DWORD)v5)
                    {
                        sub_45A110_drawable((_DWORD*)v5);
                        v3 += 6;
                        break;
                    }
                }
            LABEL_916:
                v3 += 6;
                break;
            case 0xA2u:
                if (sub_43C700())
                {
                    if (!*(_DWORD*)& byte_5D4594[1200848])
                        * (_DWORD*)& byte_5D4594[1200848] = sub_44CFC0((CHAR*)& byte_587000[159204]);
                    v221 = *(unsigned __int16*)(v3 + 9);
                    k = v221 & 0xFFFC;
                    if (k <= 28)
                        v222 = v221 >> 2;
                    else
                        v222 = 7;
                    v223 = v222 + 1;
                    if (v222 + 1 > 0)
                    {
                        do
                        {
                            LOBYTE(v368) = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4957);
                            v323 = v368;
                            v318 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4961);
                            v224 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4960);
                            sub_499490(*(int*)& byte_5D4594[1200848], (_WORD*)(v3 + 1), v224, v318, v323, 0);
                            --v223;
                        } while (v223);
                    }
                }
                v3 += 11;
                break;
            case 0xA4u:
                v15 = (unsigned __int8*)(sub_494A60((unsigned __int8*)(v3 + 1), a1, v384) + v3 + 1);
                if ((unsigned int)v15 >= v4)
                    return 1;
                while (1)
                {
                    LODWORD(v5) = sub_494C30(v15, a1, v384);
                    if ((int)v5 <= 0)
                        break;
                    v15 += v5;
                    if ((unsigned int)v15 >= v4)
                        return 1;
                }
                if ((int)v5 < 0)
                    LODWORD(v5) = -(int)v5;
                v3 = (unsigned int)& v15[v5];
                break;
            case 0xA6u:
            case 0xA7u:
                if (!sub_43C700())
                    goto LABEL_651;
                v338 = *(char*)(v3 + 1);
                v321 = (*(unsigned __int16*)(v3 + 2) >> 9) & 0x7E;
                v317 = *(_WORD*)(v3 + 2) & 0x3FF;
                if (*(char*)v3 == -89)
                {
                    sub_452E10(v317, v321, v338);
                    v3 += 4;
                }
                else
                {
                    sub_452DC0(v317, v321, v338);
                    LABEL_651:
                    v3 += 4;
                }
                break;
            case 0xA8u:
                v198 = sub_578B30(*(_WORD*)(v3 + 1));
                v199 = v198;
                memset(&byte_5D4594[1197384], 0, 0x27Cu);
                v200 = *(unsigned __int8*)(v3 + 3);
                if (v200 & 8)
                {
                    v201 = loadString_sub_40F1D0((char*)(v3 + 11), 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4486);
                    nox_wcscpy((wchar_t*)& byte_5D4594[1197384], v201);
                    v202 = 1;
                }
                else if (v200 & 2)
                {
                    if (v200 & 1)
                    {
                        v203 = loadString_sub_40F1D0((char*)& byte_587000[158812], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4493);
                        nox_swprintf((wchar_t*)& byte_5D4594[1197384], L"%s: %S", v203, v3 + 11);
                    }
                    else
                    {
                        nox_swprintf((wchar_t*)& byte_5D4594[1197384], L"%S", v3 + 11);
                    }
                    v202 = 1;
                }
                else
                {
                    if (v200 & 1)
                    {
                        v204 = loadString_sub_40F1D0((char*)& byte_587000[158892], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4506);
                        nox_swprintf((wchar_t*)& byte_5D4594[1197384], L"%s: %s", v204, v3 + 11);
                    }
                    else
                    {
                        nox_wcscpy((wchar_t*)& byte_5D4594[1197384], (const wchar_t*)(v3 + 11));
                    }
                    v202 = 2;
                }
                if (!sub_43C700())
                    goto LABEL_693;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (*(_BYTE*)(v3 + 3) & 0x10)
                {
                    if (sub_4356B0() == 3)
                    {
                        nox_wcscpy((wchar_t*)& byte_5D4594[1200068], (const wchar_t*)& byte_5D4594[1197384]);
                        v205 = loadString_sub_40F1D0((char*)& byte_587000[158964], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4536);
                        sub_449A10(0, (int)v205, (int)& byte_5D4594[1200068], 33, 0, 0);
                        k = v202 * *(unsigned __int8*)(v3 + 8);
                        v3 += k + 11;
                        break;
                    }
                }
                else if (*(_WORD*)(v3 + 1))
                {
                    if (sub_4356B0() == 3)
                    {
                        v206 = sub_417040(*(unsigned __int16*)(v3 + 1));
                        v207 = v206;
                        if (v206)
                        {
                            if (!sub_57A160((int)v206))
                            {
                                sub_450C00(0xFu, (wchar_t*)& byte_587000[158984], v207 + 4704, &byte_5D4594[1197384]);
                                sub_48D880(v3, (wchar_t*)& byte_5D4594[1197384]);
                                k = v202 * *(unsigned __int8*)(v3 + 8);
                                v3 += k + 11;
                                break;
                            }
                        }
                        else
                        {
                            sub_48D880(v3, (wchar_t*)& byte_5D4594[1197384]);
                            if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                                LODWORD(v5) = sub_45A720(v199);
                            else
                                LODWORD(v5) = sub_45A6F0(v199);
                            if ((_DWORD)v5)
                            {
                                v322 = *(unsigned __int16*)(v3 + 1);
                                v208 = nox_get_thing_pretty_name(*(_DWORD*)(v5 + 108));
                                sub_450C00(6u, (wchar_t*)& byte_587000[159000], v208, v322, &byte_5D4594[1197384]);
                            }
                        }
                    }
                }
                else if (sub_4356B0() == 3)
                {
                    sub_445490((wchar_t*)& byte_5D4594[1197384]);
                    k = v202 * *(unsigned __int8*)(v3 + 8);
                    v3 += k + 11;
                    break;
                }
            LABEL_693:
                k = v202 * *(unsigned __int8*)(v3 + 8);
                v3 += k + 11;
                break;
            case 0xA9u:
                v3 += sub_4C9BF0(v3);
                break;
            case 0xAAu:
                v61 = sub_40A5C0(1) ? 5 : 1;
                if (sub_43C700())
                {
                    v366[0] = -85;
                    if (sub_40A5C0(1))
                        * (_DWORD*)& v366[1] = *(_DWORD*)(v3 + 1);
                    else
                        *(_DWORD*)& v366[1] = v364;
                    sub_40EBC0(a1, 0, v366, 5);
                }
                v3 += v61;
                break;
            case 0xABu:
                if (sub_43C700())
                {
                    sub_4E55A0(a1, *(_DWORD*)(v3 + 1));
                }
                v3 += 5;
                break;
            case 0xAEu:
                v3 += 3;
                break;
            case 0xAFu:
                *(_DWORD*)& byte_5D4594[1200768] = 0;
                v34 = *(_DWORD*)(v3 + 1);
                if (sub_40A350() < v34)
                {
                    sub_40A340(v34);
                    sub_40A5C0(1024);
                    v355 = sub_40A5C0(32);
                    v360 = sub_40A5C0(32);
                    v363 = sub_40A5C0(4096);
                    if (!sub_40A5C0(1))
                    {
                        sub_40A540(524272);
                        sub_40A4D0(*(_DWORD*)(v3 + 9));
                        sub_409E40(*(_DWORD*)(v3 + 13));
                        sub_409AE0(*(_DWORD*)(v3 + 5));
                        sub_409F80(*(unsigned __int8*)(v3 + 17));
                        v35 = sub_416590(0);
                        if (v35[56] != *(_BYTE*)(v3 + 19) || *((_WORD*)v35 + 27) != *(unsigned __int8*)(v3 + 18))
                            * (_DWORD*)& byte_5D4594[1200768] = 1;
                        *((_WORD*)v35 + 27) = *(unsigned __int8*)(v3 + 18);
                        v35[56] = *(_BYTE*)(v3 + 19);
                        if ((signed char) * (_BYTE*)(v3 + 9) >= 0)
                        {
                            *((_WORD*)v35 + 26) = *(_WORD*)(v3 + 9);
                            strcpy(v35, sub_409B40());
                        }
                        if (v355 || !sub_40A5C0(32))
                        {
                            if (!sub_40A5C0(32))
                                sub_455C10();
                        }
                        else
                        {
                            sub_455A50(2);
                        }
                        if (v360 || !sub_40A5C0(64))
                        {
                            if (!sub_40A5C0(64))
                                sub_456050();
                        }
                        else
                        {
                            sub_455F60();
                        }
                        if (v363 == 1 && !sub_40A5C0(4096))
                        {
                            for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
                                sub_417680((int)j, 255);
                        }
                        if (!sub_40A5C0(0x20000) && sub_4356B0() == 3)
                        {
                            sub_43DDD0(0);
                            sub_43DE60();
                        }
                    }
                }
                v3 += 20;
                break;
            case 0xB0u:
                if (!sub_40A5C0(1))
                {
                    v37 = sub_416590(0);
                    strncpy(v37 + 9, (const char*)(v3 + 1), 0xFu);
                    if (memcmp(&byte_5D4594[1200732], (const void*)(v3 + 17), 0x14u))
                        * (_DWORD*)& byte_5D4594[1200768] = 1;
                    if (*(_DWORD*)& byte_5D4594[1200752] != *(_DWORD*)(v3 + 37)
                        || *(_DWORD*)& byte_5D4594[1200756] != *(_DWORD*)(v3 + 41))
                    {
                        *(_DWORD*)& byte_5D4594[1200768] = 1;
                    }
                    qmemcpy(v37 + 24, (const void*)(v3 + 17), 0x14u);
                    sub_4540E0((int)(v37 + 24));
                    *((_DWORD*)v37 + 11) = *(_DWORD*)(v3 + 37);
                    *((_DWORD*)v37 + 12) = *(_DWORD*)(v3 + 41);
                    if (*(_DWORD*)(v3 + 45))
                    {
                        sub_40A1F0(1);
                        sub_40A310(*(_DWORD*)(v3 + 45));
                    }
                    else
                    {
                        sub_40A1F0(0);
                    }
                    qmemcpy(&byte_5D4594[1200708], v37, 0x3Au);
                    if (sub_43C700() && *(_DWORD*)& byte_5D4594[1200768])
                    {
                        v38 = loadString_sub_40F1D0((char*)& byte_587000[157156], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 1429);
                        sub_445490(v38);
                        sub_452D80(310, 100);
                    }
                }
                v3 += 49;
                break;
            case 0xB1u:
                v39 = sub_416590(*(unsigned __int8*)(v3 + 1));
                LOBYTE(v40) = v39[52];
                LOBYTE(v4) = *(_BYTE*)(v3 + 54);
                qmemcpy(v39, (const void*)(v3 + 2), 0x3Au);
                if (((v40 >> 5) & 1) != ((v4 >> 5) & 1))
                    sub_4573A0();
                if (!sub_4169C0())
                {
                    if (!sub_459DA0())
                    {
                        if (*(_BYTE*)(v3 + 1) == 1)
                            sub_4165F0(1, 0);
                        if (sub_40A5C0(128))
                        {
                            if (*(_DWORD*)& byte_5D4594[1200832])
                            {
                                v330 = *(_DWORD*)& byte_5D4594[2618908] + 4704;
                                v41 = loadString_sub_40F1D0((char*)& byte_587000[157212], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 1470);
                                nox_swprintf(v401, v41, v330);
                                sub_445490(v401);
                                *(_DWORD*)& byte_5D4594[1200832] = 0;
                            }
                            if (*(_DWORD*)& byte_587000[54276])
                                sub_49C560();
                        }
                    }
                    sub_4169D0(1);
                }
                sub_459C30();
                v3 += 60;
                break;
            case 0xB2u:
                v18 = sub_578B30(*(_WORD*)(v3 + 1));
                v19 = v18;
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v19) : sub_45A6F0(v19);
                    if ((_DWORD)v5)
                        * (_BYTE*)(v5 + 299) = *(_BYTE*)(v3 + 3);
                }
                v3 += 4;
                break;
            case 0xB3u:
                v20 = sub_578B30(*(_WORD*)(v3 + 1));
                v21 = v20;
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v21) : sub_45A6F0(v21);
                    v22 = v5;
                    if ((_DWORD)v5)
                    {
                        sub_45A990_drawable(v5);
                        v328 = (double)(16 * *(unsigned __int8*)(v3 + 3) / 10);
                        sub_484D70_light_intensity(v22 + 136, v328);
                        sub_45AB80(v22, 8 * *(unsigned __int8*)(v3 + 3) / 50);
                        if (*(_DWORD*)(v22 + 308) == 8)
                            * (_DWORD*)(v22 + 308) = 7;
                    }
                }
                v3 += 4;
                break;
            case 0xB4u:
                v24 = sub_578B30(*(_WORD*)(v3 + 1));
                v25 = v24;
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v25) : sub_45A6F0(v25);
                    v26 = v5;
                    if ((_DWORD)v5)
                    {
                        if (*(_BYTE*)(v3 + 3))
                        {
                            *(_DWORD*)(v5 + 112) |= 0x80000u;
                            sub_484D70_light_intensity(v5 + 136, 41.958);
                        }
                        else
                        {
                            *(_DWORD*)(v5 + 112) &= 0xFFF7FFFF;
                            sub_484D70_light_intensity(v5 + 136, 0.0);
                        }
                        sub_45AB80(v26, *(unsigned __int8*)(v3 + 3));
                        *(_DWORD*)(v26 + 288) = *(_DWORD*)& byte_5D4594[2598000];
                    }
                }
                v3 += 4;
                break;
            case 0xB5u:
                if (sub_43C700()
                    && (v329 = *(unsigned __int16*)(v3 + 7),
                        v320 = *(unsigned __int16*)(v3 + 5),
                        v31 = sub_578B30(*(_WORD*)(v3 + 1)),
                        LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 3), v31, v320, v329),
                        (_DWORD)v5))
                {
                    *(_WORD*)(v5 + 508) = *(_WORD*)(v3 + 9);
                    *(float*)(v5 + 468) = (double) * (char*)(v3 + 12) * 0.0625;
                    *(float*)(v5 + 472) = (double) * (char*)(v3 + 13) * 0.0625;
                    *(float*)(v5 + 476) = (double) * (char*)(v3 + 11) * 0.0625;
                    *(_DWORD*)(v5 + 316) = *(_DWORD*)& byte_5D4594[2598000];
                    *(_DWORD*)(v5 + 324) = *(unsigned __int16*)(v3 + 5);
                    v32 = *(unsigned __int16*)(v3 + 7);
                    *(_DWORD*)(v5 + 460) = sub_4CA540;
                    *(_DWORD*)(v5 + 328) = v32;
                    sub_49BC80_drawable((_DWORD*)v5);
                }
                v3 += 14;
                break;
            case 0xB8u:
                if (!sub_4ABAD0((char*)(v3 + 8), *(_DWORD*)(v3 + 4)))
                {
                    sub_43CAB0();
                    sub_4AB560(0);
                    sub_4AB570(0);
                }
                v3 += 88;
                break;
            case 0xB9u:
                sub_4AB7C0(*(_WORD*)(v3 + 2), (void*)(v3 + 6), *(unsigned __int16*)(v3 + 4));
                k = *(unsigned __int16*)(v3 + 4);
                v3 += k + 6;
                break;
            case 0xBAu:
                sub_4AB720();
                sub_4AB560(0);
                sub_4AB570(0);
                v3 += 2;
                break;
            case 0xBDu:
                if (sub_43C700())
                {
                    if (*(_BYTE*)(v3 + 1) == 1)
                        v290 = loadString_sub_40F1D0((char*)& byte_587000[160420], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 6351);
                    else
                        v290 = loadString_sub_40F1D0((char*)& byte_587000[160472], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 6356);
                    sub_450C00(6u, v290);
                }
                v3 += 2;
                break;
            case 0xC2u:
                v263 = *(unsigned __int8*)(v3 + 1);
                switch (v263)
                {
                    case 0:
                        v342 = *(_BYTE*)(v3 + 136);
                        v324 = *(_DWORD*)(v3 + 4);
                        v315 = *(_BYTE*)(v3 + 2);
                        v264 = sub_43C750();
                        sub_40B5D0(v264, v315, (const char*)(v3 + 8), v324, v342);
                        v3 += 140;
                        break;
                    case 1:
                        BYTE4(v5) = *(_BYTE*)(v3 + 3);
                        v343 = (char*)HIDWORD(v5);
                        v325 = *(_BYTE*)(v3 + 2);
                        v265 = sub_43C750();
                        sub_40BFF0(v265, v325, v343);
                        v3 += 4;
                        break;
                    case 2:
                        v365[0] = -62;
                        v365[1] = 3;
                        v365[2] = *(_BYTE*)(v3 + 2);
                        *(_WORD*)& v365[4] = *(_WORD*)(v3 + 4);
                        v266 = sub_43C750();
                        sub_552640(v266, v365, 6, 3);
                        v344 = *(unsigned __int16*)(v3 + 6);
                        v319 = *(_WORD*)(v3 + 4);
                        v316 = *(_BYTE*)(v3 + 2);
                        v267 = sub_43C750();
                        sub_40B250(v267, v316, v319, (const void*)(v3 + 8), v344);
                        HIDWORD(v5) = *(unsigned __int16*)(v3 + 6);
                        v3 += WORD2(v5) + 8;
                        break;
                    case 3:
                        v345 = *(unsigned __int16*)(v3 + 4);
                        v326 = *(_BYTE*)(v3 + 2);
                        v268 = sub_43C750();
                        sub_40BF60(v268, v326, v345);
                        v3 += 6;
                        break;
                    case 4:
                        v346 = *(_BYTE*)(v3 + 2);
                        v269 = sub_43C750();
                        sub_40C030(v269, v346);
                        v3 += 3;
                        break;
                    case 5:
                        LOBYTE(k) = *(_BYTE*)(v3 + 3);
                        sub_40B720(k, *(_BYTE*)(v3 + 2));
                        v3 += 4;
                        break;
                    case 6:
                        LOBYTE(v263) = *(_BYTE*)(v3 + 3);
                        v347 = *(_BYTE*)(v3 + 2);
                        v327 = v263;
                        v270 = sub_43C750();
                        sub_40C070(v270, v327, v347);
                        v3 += 4;
                        break;
                    default:
                        return 0;
                }
                break;
            case 0xC3u:
                sub_578B30(*(_WORD*)(v3 + 1));
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000000)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (*(_WORD*)(v3 + 3) || *(_WORD*)(v3 + 1))
                {
                    v27 = sub_48E970(
                            *(unsigned __int16*)(v3 + 3),
                            *(unsigned __int16*)(v3 + 1),
                            *(unsigned __int16*)(v3 + 5),
                            *(unsigned __int16*)(v3 + 7));
                    if (v27)
                    {
                        v27[72] = *(_DWORD*)& byte_5D4594[2598000];
                        sub_45AB80((int)v27, *(unsigned __int8*)(v3 + 10));
                        v28 = (*(_BYTE*)(v3 + 9) >> 4) & 7;
                        *((_BYTE*)v27 + 297) = v28;
                        if (v28 > 3u)
                            * ((_BYTE*)v27 + 297) = v28 + 1;
                        if (v27[69] != *(unsigned __int8*)(v3 + 11))
                        {
                            v27[79] = *(_DWORD*)& byte_5D4594[2598000];
                            k = *(unsigned __int8*)(v3 + 11);
                            v27[69] = k;
                        }
                    }
                    HIDWORD(v5) = *(unsigned __int16*)(v3 + 1);
                    if (WORD2(v5) == *(_DWORD*)& byte_5D4594[2616328] && sub_416120(8u))
                        sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
                    v3 += 12;
                }
                else
                {
                    sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
                    sub_4160D0(8);
                    v3 += 12;
                }
                break;
            case 0xC4u:
                switch (*(unsigned __int8*)(v3 + 1))
                {
                    case 0u:
                        if (!sub_43C700())
                            goto LABEL_888;
                        qmemcpy(v386, (const void*)(v3 + 18), 2 * *(unsigned __int8*)(v3 + 15));
                        v386[*(unsigned __int8*)(v3 + 15)] = 0;
                        if (*(_BYTE*)(v3 + 17))
                        {
                            v271 = sub_418C20(*(unsigned __int8*)(v3 + 16));
                            nox_swprintf(v386, v271);
                        }
                        v272 = sub_418AB0(*(_DWORD*)(v3 + 2));
                        if (!v272)
                        {
                            v272 = sub_4186D0(*(_BYTE*)(v3 + 2));
                            if (!v272)
                                goto LABEL_888;
                        }
                        sub_418800((wchar_t*)v272, v386, 0);
                        sub_418830((int)v272, *(_DWORD*)(v3 + 6));
                        sub_419090((int)v272, *(_DWORD*)(v3 + 10));
                        v272[56] = *(_BYTE*)(v3 + 16);
                        sub_457230(v386);
                        if (!(*(_BYTE*)(v3 + 14) & 1))
                            goto LABEL_888;
                        v273 = sub_418C80(*(int*)& byte_5D4594[2616328]);
                        if (!v273)
                            goto LABEL_888;
                        if (sub_40A5C0(1))
                        {
                            sub_4191D0(v272[57], (int)v273, 1, *(int*)& byte_5D4594[2616328], 1);
                            HIDWORD(v5) = *(unsigned __int8*)(v3 + 15);
                            v3 += 2 * HIDWORD(v5) + 18;
                        }
                        else
                        {
                            sub_419900((int)v272, (int)v273, *(__int16*)& byte_5D4594[2616328]);
                            LABEL_888:
                            HIDWORD(v5) = *(unsigned __int8*)(v3 + 15);
                            v3 += 2 * HIDWORD(v5) + 18;
                        }
                        break;
                    case 1u:
                        v274 = sub_578B30(*(_WORD*)(v3 + 6));
                        v275 = v274;
                        if (sub_43C700())
                        {
                            if (sub_578B70(*(unsigned __int16*)(v3 + 6)))
                                LODWORD(v5) = sub_45A720(v275);
                            else
                                LODWORD(v5) = sub_45A6F0(v275);
                            if (!(_DWORD)v5)
                                LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 8), v275, 0, 0);
                            v276 = v5 + 24;
                            if ((_DWORD)v5 != (_DWORD)-24)
                            {
                                LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
                                v277 = v5;
                                if ((_DWORD)v5)
                                {
                                    sub_4191D0(*(_BYTE*)(v5 + 57), v276, 0, *(unsigned __int16*)(v3 + 6), 0);
                                    sub_4571A0(*(unsigned __int16*)(v3 + 6), *(unsigned __int8*)(v277 + 57));
                                }
                            }
                        }
                        v3 += 10;
                        break;
                    case 2u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_418C80(*(_DWORD*)(v3 + 2));
                            if ((_DWORD)v5)
                            {
                                sub_419570(v5, *(_DWORD*)(v3 + 2));
                                sub_4571A0(*(_DWORD*)(v3 + 2), 0);
                            }
                        }
                        goto LABEL_902;
                    case 3u:
                        if (sub_43C700())
                        {
                            v278 = sub_418C80(*(unsigned __int16*)(v3 + 6));
                            if (v278)
                            {
                                LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
                                v279 = v5;
                                if ((_DWORD)v5)
                                {
                                    if (sub_4196D0((int)v278, v5, *(unsigned __int16*)(v3 + 6), 0))
                                        sub_4571A0(*(unsigned __int16*)(v3 + 6), *(unsigned __int8*)(v279 + 57));
                                }
                            }
                        }
                        goto LABEL_908;
                    case 4u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
                            if ((_DWORD)v5)
                                sub_418CD0((wchar_t*)v5, (wchar_t*)(v3 + 6));
                        }
                        v3 += 46;
                        break;
                    case 5u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
                            if ((_DWORD)v5)
                                sub_418D80(v5);
                        }
                        goto LABEL_916;
                    case 6u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
                            v280 = (wchar_t*)v5;
                            if ((_DWORD)v5)
                            {
                                nox_wcscpy(v387, (const wchar_t*)v5);
                                sub_418F20(v280, 0);
                                sub_456EA0(v387);
                            }
                        }
                        goto LABEL_920;
                    case 7u:
                        if (sub_43C700())
                        {
                            sub_419030(0);
                            sub_456FA0();
                        }
                        v3 += 2;
                        break;
                    case 8u:
                        if (sub_43C700() && (LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2)), (_DWORD)v5))
                        {
                            sub_419090(v5, *(_DWORD*)(v3 + 6));
                            v3 += 10;
                        }
                        else
                        {
                            LABEL_908:
                            v3 += 10;
                        }
                        break;
                    case 9u:
                        if (sub_43C700())
                            sub_417D00();
                        v3 += 2;
                        break;
                    case 0xCu:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 2));
                            if ((_DWORD)v5)
                                * (_BYTE*)(v5 + 2282) = *(_BYTE*)(v3 + 4);
                        }
                        v3 += 5;
                        break;
                }
                break;
            case 0xC5u:
                sub_43B6E0();
                ++v3;
                break;
            case 0xC6u:
                sub_43B750();
                ++v3;
                break;
            case 0xC7u:
                v359 = -56;
                v33 = sub_43C750();
                sub_552640(v33, &v359, 1, 2);
                sub_446380();
                ++v3;
                break;
            case 0xC9u:
                switch (*(unsigned __int8*)(v3 + 1))
                {
                    case 1u:
                        if (sub_43C700())
                            sub_4C1590();
                        v3 += 2;
                        break;
                    case 2u:
                        if (sub_43C700())
                            sub_479280();
                        v3 += 2;
                        break;
                    case 3u:
                        if (sub_43C700())
                            sub_4C1BC0(v3);
                        v3 += 3;
                        break;
                    case 4u:
                        if (sub_43C700())
                            sub_4C1790(v3);
                        v3 += 15;
                        break;
                    case 5u:
                        if (!sub_43C700())
                            goto LABEL_1133;
                        sub_4C15D0(v3);
                        v3 += 4;
                        break;
                    case 6u:
                        if (!sub_43C700())
                        {
                            v3 += 14;
                            break;
                        }
                        sub_4C1B50(v3);
                        v3 += 14;
                        break;
                    case 7u:
                        if (sub_43C700())
                            sub_4C1BF0();
                        v3 += 2;
                        break;
                    case 8u:
                        if (sub_43C700())
                            sub_479300(
                                    *(unsigned __int16*)(v3 + 2),
                                    *(unsigned __int16*)(v3 + 4),
                                    *(_DWORD*)(v3 + 6),
                                    *(_DWORD*)(v3 + 10),
                                    v3 + 14);
                        v3 += 18;
                        break;
                    case 9u:
                        if (!sub_43C700())
                            goto LABEL_1133;
                        sub_479480(*(unsigned __int16*)(v3 + 2));
                        v3 += 4;
                        break;
                    case 0xCu:
                        if (sub_43C700())
                            sub_4C1320(v3);
                        v3 += 52;
                        break;
                    case 0xDu:
                        if (sub_43C700())
                            sub_478FD0((const wchar_t*)(v3 + 4), (char*)(v3 + 54), *(unsigned __int16*)(v3 + 2));
                        v3 += 86;
                        break;
                    case 0x1Bu:
                        if (!sub_43C700())
                            goto LABEL_1133;
                        sub_479520(*(unsigned __int16*)(v3 + 2));
                        v3 += 4;
                        break;
                    case 0x1Du:
                        if (sub_43C700())
                            sub_4795E0(*(unsigned __int16*)(v3 + 2), *(_DWORD*)(v3 + 4));
                        goto LABEL_1057;
                    case 0x1Fu:
                        if (!sub_43C700())
                            goto LABEL_1057;
                        sub_479740(*(unsigned __int16*)(v3 + 2), *(_DWORD*)(v3 + 4));
                        v3 += 8;
                        break;
                    default:
                        return 0;
                }
                break;
            case 0xCAu:
                if (sub_43C700())
                {
                    if (*(short*)(v3 + 1) == -8531)
                        sub_48E940();
                    else
                        sub_48E8E0(*(unsigned __int16*)(v3 + 1));
                }
                v3 += 3;
                break;
            case 0xCBu:
                if (sub_43C700())
                    sub_445450();
                ++v3;
                break;
            case 0xCCu:
                if (sub_43C700())
                    sub_48D5A0(v3);
                k = *(unsigned __int8*)(v3 + 3);
                v3 += k + 4;
                break;
            case 0xCDu:
                v86 = 0;
                if (sub_43C700())
                {
                    v87 = *(_BYTE*)(v3 + 2);
                    LOBYTE(v370) = *(_BYTE*)(v3 + 2) & 0x7F;
                    if (v87 < 0)
                        v86 = 1;
                    sub_4611E0(*(unsigned __int8*)(v3 + 1), (unsigned __int8)v370, (char*)v86);
                }
                v3 += 3;
                break;
            case 0xCEu:
                if (sub_43C700())
                    sub_461090(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
                v3 += 3;
                break;
            case 0xCFu:
                if (sub_43C700())
                    sub_461120(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
                v3 += 3;
                break;
            case 0xD0u:
                if (*(_BYTE*)(v3 + 1) == 3)
                {
                    if (sub_43C700())
                    {
                        sub_479D30(
                                (wchar_t*)(v3 + 34),
                                *(_DWORD*)(v3 + 98),
                                (char*)(v3 + 2),
                                (const char*)(v3 + 102),
                                *(_BYTE*)(v3 + 134));
                        if (*(_DWORD*)& byte_5D4594[2618908])
                            sub_4174F0(*(int*)& byte_5D4594[2618908], 512);
                    }
                    v3 += 135;
                }
                else if (*(_BYTE*)(v3 + 1) == 4)
                {
                    if (sub_43C700())
                    {
                        sub_47A1F0();
                        if (*(_DWORD*)& byte_5D4594[2618908])
                            sub_417530(*(int*)& byte_5D4594[2618908], 512);
                    }
                    LABEL_966:
                    v3 += 2;
                }
                break;
            case 0xD1u:
                if (sub_43C700())
                    sub_45D140(*(unsigned __int8*)(v3 + 1), *(_BYTE*)(v3 + 2) & 0x7F);
                v3 += 3;
                break;
            case 0xD2u:
                v281 = sub_578B30(*(_WORD*)(v3 + 1));
                v282 = v281;
                if (!sub_43C700())
                    goto LABEL_948;
                if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                {
                    v283 = sub_578B30(*(_WORD*)(v3 + 1));
                    LODWORD(v5) = sub_45A720(v283);
                }
                else
                {
                    v284 = sub_578B30(*(_WORD*)(v3 + 1));
                    LODWORD(v5) = sub_45A6F0(v284);
                }
                if (*(_BYTE*)(v3 + 5) == 1)
                {
                    if ((_DWORD)v5 || (LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 3), v282, 0, 0), (_DWORD)v5))
                    {
                        sub_459DD0(v5, *(_BYTE*)(v3 + 6));
                        v3 += 7;
                        break;
                    }
                }
                else if ((_DWORD)v5)
                {
                    sub_459E30(v5, *(_BYTE*)(v3 + 6));
                }
            LABEL_948:
                v3 += 7;
                break;
            case 0xD3u:
                if (!sub_43C700())
                    goto LABEL_112;
                if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v3 + 9)) >= 0x1E)
                {
                    v359 = -44;
                    sub_4E53C0(31, &v359, 1, 0, 1);
                    LABEL_112:
                    v3 += 13;
                }
                else
                {
                    if (*(_DWORD*)(v3 + 1))
                    {
                        sub_40A1F0(1);
                        v5 = sub_40A310(*(_DWORD*)(v3 + 5));
                    }
                    else
                    {
                        sub_40A1F0(0);
                    }
                    v3 += 13;
                }
                break;
            case 0xD5u:
                v296 = *(_DWORD*)& byte_5D4594[2618908];
                switch (*(_BYTE*)(v3 + 1))
                {
                    case 1:
                        if (sub_43C700())
                        {
                            if (v296)
                                sub_427490(v296, (char*)(v3 + 2), *(_WORD*)(v3 + 66));
                            sub_469BC0();
                        }
                        v3 += 68;
                        break;
                    case 2:
                        if (sub_43C700())
                        {
                            if (v296)
                                sub_427590(v296, (const char*)(v3 + 2));
                            sub_469BC0();
                        }
                        v3 += 68;
                        break;
                    case 3:
                        if (sub_43C700() && v296)
                            sub_4276B0(v296, (const char*)(v3 + 2), *(_WORD*)(v3 + 66));
                        v3 += 68;
                        break;
                }
                break;
            case 0xD6u:
                if (sub_43C700())
                    sub_450160(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2), 0);
                v3 += 3;
                break;
            case 0xD7u:
                LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 1));
                if ((_DWORD)v5)
                {
                    LOWORD(k) = *(_WORD*)(v3 + 3);
                    *(_WORD*)(v5 + 2148) = k;
                }
                v3 += 5;
                break;
            case 0xD8u:
                if (sub_43C700())
                {
                    sub_455D80(*(_BYTE*)(v3 + 2), *(_BYTE*)(v3 + 1));
                    sub_4705F0(*(_BYTE*)(v3 + 1), *(_BYTE*)(v3 + 3), *(_WORD*)(v3 + 4));
                    v3 += 6;
                }
                else
                {
                    LABEL_920:
                    v3 += 6;
                }
                break;
            case 0xD9u:
                if (sub_43C700())
                {
                    sub_456140(*(_BYTE*)(v3 + 1));
                    sub_470650(*(_BYTE*)(v3 + 1), *(_WORD*)(v3 + 2));
                }
                v3 += 4;
                break;
            case 0xDAu:
                v137 = sub_578B30(*(_WORD*)(v3 + 1));
                v138 = v137;
                if (sub_43C700())
                {
                    if (sub_4951F0(v138))
                        sub_4950F0(v138, *(_BYTE*)(v3 + 3));
                    nox_npc_set_328(v138, *(unsigned __int8*)(v3 + 3));
                    v3 += 4;
                }
                else
                {
                    LABEL_764:
                    v3 += 4;
                }
                break;
            case 0xDBu:
                v193 = sub_578B30(*(_WORD*)(v3 + 1));
                v194 = v193;
                if (sub_43C700())
                {
                    if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                        v195 = sub_45A720(v194);
                    else
                        v195 = sub_45A6F0(v194);
                    if (v195 || (v195 = sub_48E970(*(unsigned __int16*)(v3 + 3), v194, 0, 0)) != 0)
                        sub_459DD0((int)v195, 1);
                    sub_495060(v194, 0, 0);
                }
            LABEL_638:
                v3 += 5;
                break;
            case 0xDCu:
                v196 = sub_578B30(*(_WORD*)(v3 + 1));
                v197 = v196;
                if (!sub_43C700())
                {
                    v3 += 3;
                    break;
                }
                sub_4950C0(*(unsigned __int16*)(v3 + 1));
                v337 = v197;
                if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
                    LODWORD(v5) = sub_45A720(v197);
                else
                    LABEL_642:
                    LODWORD(v5) = sub_45A6F0(v337);
            LABEL_643:
                if ((_DWORD)v5)
                    sub_459E30(v5, 1);
                v3 += 3;
                break;
            case 0xDDu:
                v90 = sub_578B30(*(_WORD*)(v3 + 1));
                v91 = v90;
                if (!sub_43C700())
                    goto LABEL_1149;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (v91 == *(_DWORD*)& byte_5D4594[2616328])
                {
                    sub_470C80(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 5));
                    v3 += 7;
                }
                else if (sub_4951F0(*(unsigned __int16*)(v3 + 1)))
                {
                    sub_495120(*(unsigned __int16*)(v3 + 1), *(_WORD*)(v3 + 3), *(_WORD*)(v3 + 5));
                    v3 += 7;
                }
                else
                {
                    LABEL_1149:
                    v3 += 7;
                }
                break;
            case 0xDEu:
                v94 = sub_578B30(*(_WORD*)(v3 + 1));
                v95 = v94;
                if (!sub_43C700())
                    goto LABEL_948;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (v95 != *(_DWORD*)& byte_5D4594[2616328])
                    goto LABEL_948;
                sub_470CE0(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 5));
                v3 += 7;
                break;
            case 0xDFu:
                sub_460EB0(*(_DWORD*)(v3 + 1), *(_BYTE*)(v3 + 5));
                v3 += 6;
                break;
            case 0xE0u:
                v291 = sub_578B30(*(_WORD*)(v3 + 1));
                v292 = v291;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                if (*(_WORD*)(v3 + 1))
                    sub_467750(v292, *(_BYTE*)(v3 + 3));
                else
                    sub_467750(0, *(_BYTE*)(v3 + 3));
                v3 += 4;
                break;
            case 0xE1u:
                v293 = sub_578B30(*(_WORD*)(v3 + 1));
                sub_467740(v293);
                v3 += 3;
                break;
            case 0xE2u:
                v294 = sub_578B30(*(_WORD*)(v3 + 1));
                v295 = v294;
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v3 + 1));
                LODWORD(v5) = sub_478080(v295);
                if ((_DWORD)v5
                    || (LODWORD(v5) = sub_4676D0(v295), (_DWORD)v5)
                    || (!sub_578B70(*(unsigned __int16*)(v3 + 1)) ? (LODWORD(v5) = sub_45A6F0(v295)) : (LODWORD(v5) = sub_45A720(v295)),
                        (_DWORD)v5))
                {
                    k = *(unsigned __int8*)(v3 + 3);
                    *(_DWORD*)(v5 + 432) = k;
                }
                v3 += 4;
                break;
            case 0xE4u:
                if (sub_43C700())
                {
                    if (*(_BYTE*)(v3 + 1) == 1)
                    {
                        if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                        {
                            *(_DWORD*)& byte_5D4594[2650672] = 0;
                            sub_42EE00();
                            sub_413A00(1);
                            sub_44DB30(25, *(_BYTE*)(v3 + 2) == 1, sub_44E020);
                        }
                    }
                    else if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                    {
                        sub_44DAB0(25, *(_BYTE*)(v3 + 2) == 1, sub_44E000);
                    }
                }
                v3 += 3;
                break;
            case 0xE5u:
                if (sub_43C700())
                    sub_43D9B0(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
                v3 += 3;
                break;
            case 0xE6u:
                if (sub_43C700())
                    sub_43DA80();
                v3 += 3;
                break;
            case 0xE7u:
                if (sub_43C700())
                    sub_43DAD0();
                v3 += 3;
                break;
            case 0xE8u:
                if (sub_43C700())
                {
                    LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 1));
                    v111 = (_DWORD*)v5;
                    if ((_DWORD)v5)
                    {
                        if ((_DWORD)v5 == *(_DWORD*)& byte_5D4594[2618908])
                        {
                            sub_4BFE40();
                            sub_478000();
                        }
                        v112 = sub_45A6F0(*(unsigned __int16*)(v3 + 1));
                        if (v112)
                            sub_459E30((int)v112, 3);
                        if (!sub_40A5C0(4096))
                        {
                            v111[1] = 0;
                            LODWORD(v5) = v111 + 582;
                            v113 = 27;
                            do
                            {
                                v114 = (_DWORD*)v5;
                                LODWORD(v5) = v5 + 24;
                                *(_DWORD*)(v5 - 4) = 0;
                                v5 = (unsigned int)v5;
                                *v114 = 0;
                                --v113;
                                v114[1] = 0;
                                v114[2] = 0;
                                v114[3] = 0;
                            } while (v113);
                            for (k = 0; k < 624; k += 24)
                            {
                                v115 = *(_DWORD*)((char*)v111 + k + 2972);
                                if (!(v115 & 0xC0D))
                                {
                                    HIDWORD(v5) = ~v115 & *v111;
                                    *v111 = HIDWORD(v5);
                                    *(_DWORD*)((char*)v111 + k + 2972) = 0;
                                    *(_DWORD*)((char*)v111 + k + 2976) = 0;
                                    *(_DWORD*)((char*)v111 + k + 2980) = 0;
                                    *(_DWORD*)((char*)v111 + k + 2984) = 0;
                                    *(_DWORD*)((char*)v111 + k + 2988) = 0;
                                }
                            }
                        }
                    }
                }
                v3 += 3;
                break;
            case 0xE9u:
                if (sub_43C700())
                {
                    if (sub_40A5C0(0x2000))
                    {
                        k = *(unsigned __int16*)(v3 + 1);
                        if ((unsigned __int16)k == *(_DWORD*)& byte_5D4594[2616328])
                            sub_45A670(*(_DWORD*)(v3 + 3));
                    }
                    if (*(_BYTE*)(v3 + 8) & 1)
                    {
                        LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 1));
                        if ((_DWORD)v5)
                            sub_417680(v5, *(_BYTE*)(v3 + 7));
                    }
                }
                v3 += 9;
                break;
            case 0xEAu:
                if (sub_40A5C0(0x2000))
                {
                    sub_45A670(*(_DWORD*)(v3 + 1));
                    v3 += 5;
                }
                else
                {
                    LABEL_1163:
                    v3 += 5;
                }
                break;
            case 0xEBu:
                if (!sub_43C700())
                {
                    v3 += 2;
                    break;
                }
                sub_4610D0(*(_BYTE*)(v3 + 1));
                v3 += 2;
                break;
            case 0xECu:
                if (sub_43C700())
                {
                    sub_43C7A0(*(unsigned __int8*)(v3 + 1));
                }
                v3 += 2;
                break;
            case 0xEDu:
                if (sub_43C700())
                {
                    sub_4C1CA0(*(unsigned __int8*)(v3 + 1));
                }
                v3 += 2;
                break;
            case 0xEEu:
                if (*(_BYTE*)(v3 + 1) == 6)
                {
                    sub_48D4B0(*(unsigned __int8*)(v3 + 2));
                    v3 += 3;
                    break;
                }
                else if (*(_BYTE*)(v3 + 1) == 7)
                {
                    sub_48D4A0();
                    v3 += 2;
                    break;
                }
                return 0;
            case 0xEFu:
                if (byte_5D4594[2661958])
                {
                    if (byte_5D4594[2661958] == 1)
                    {
                        *(_DWORD*)& byte_587000[312816] = *(_DWORD*)(v3 + 1);
                        *(_DWORD*)& byte_587000[312820] = *(_DWORD*)(v3 + 5);
                        *(_DWORD*)& byte_587000[312824] = *(_DWORD*)(v3 + 9);
                        *(_DWORD*)& byte_587000[312828] = *(_DWORD*)(v3 + 13);
                        sub_57B200();
                        v3 += 17;
                        break;
                    }
                    else if (byte_5D4594[2661958] == 2)
                    {
                        *(_DWORD*)& byte_587000[312800] = *(_DWORD*)(v3 + 1);
                        *(_DWORD*)& byte_587000[312804] = *(_DWORD*)(v3 + 5);
                        *(_DWORD*)& byte_587000[312808] = *(_DWORD*)(v3 + 9);
                        *(_DWORD*)& byte_587000[312812] = *(_DWORD*)(v3 + 13);
                        sub_57B200();
                        v3 += 17;
                        break;
                    }
                }
                else
                {
                    *(_DWORD*)& byte_587000[312784] = *(_DWORD*)(v3 + 1);
                    *(_DWORD*)& byte_587000[312788] = *(_DWORD*)(v3 + 5);
                    *(_DWORD*)& byte_587000[312792] = *(_DWORD*)(v3 + 9);
                    *(_DWORD*)& byte_587000[312796] = *(_DWORD*)(v3 + 13);
                }
                sub_57B200();
                v3 += 17;
                break;
            case 0xF0u:
                switch (*(unsigned __int8*)(v3 + 1))
                {
                    case 0u:
                        if (sub_43C700() == 1)
                        {
                            if (sub_40A5C0(1))
                            {
                                sub_460380();
                                sub_460E60();
                                sub_41CC00((char*)& byte_5D4594[2660688]);
                                sub_41A480((char*)& byte_5D4594[2660688]);
                            }
                            sub_470AA0(1);
                            sub_48D4A0();
                            sub_4721D0();
                            sub_4705B0();
                        }
                        goto LABEL_1085;
                    case 1u:
                        if (sub_43C700() == 1)
                        {
                            sub_452D80(1008, 100);
                            v299 = sub_417040(*(unsigned __int16*)(v3 + 2));
                            if (v299)
                            {
                                if (!sub_40A5C0(1))
                                    * ((_DWORD*)v299 + 1198) = 1;
                            }
                        }
                        v3 += 4;
                        break;
                    case 2u:
                        if (sub_43C700() == 1)
                            sub_49B4B0((unsigned __int16*)v3);
                        v3 += 14;
                        break;
                    case 4u:
                        if (sub_43C700())
                        {
                            v300 = sub_417040(*(unsigned __int16*)(v3 + 3));
                            if (v300)
                                v300[4816] = *(_BYTE*)(v3 + 2);
                            HIDWORD(v5) = *(unsigned __int16*)(v3 + 3);
                            if (WORD2(v5) == *(_DWORD*)& byte_5D4594[2616328])
                                sub_463420(*(unsigned __int8*)(v3 + 2));
                        }
                        v3 += 5;
                        break;
                    case 5u:
                    case 6u:
                    case 7u:
                    case 8u:
                    case 9u:
                    case 0xAu:
                        sub_43C700();
                        v3 += 4;
                        break;
                    case 0xBu:
                        sub_43C700();
                        v3 += 16;
                        break;
                    case 0xCu:
                        if (sub_43C700())
                            sub_450770(v3);
                        *(_DWORD*)& byte_5D4594[1556112] = 0;
                        v3 += 90;
                        break;
                    case 0xDu:
                        if (sub_43C700())
                            sub_450980(v3, *(_BYTE*)(v3 + 4) & 1);
                        goto LABEL_1119;
                    case 0xEu:
                        if (sub_43C700())
                            sub_450A30(v3, 1);
                    LABEL_1119:
                        *(_DWORD*)& byte_5D4594[1556112] = 0;
                        v3 += 69;
                        break;
                    case 0xFu:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_45A720(*(unsigned __int16*)(v3 + 2));
                            if ((_DWORD)v5)
                                * (_BYTE*)(v5 + 432) = 0;
                        }
                        v3 += 4;
                        break;
                    case 0x10u:
                        if (!*(_DWORD*)& byte_5D4594[1200904])
                            * (_DWORD*)& byte_5D4594[1200904] = sub_44CFC0((CHAR*)& byte_587000[160484]);
                        if (sub_43C700())
                        {
                            v301 = sub_45A360_drawable(
                                    *(int*)& byte_5D4594[1200904],
                                    *(unsigned __int16*)(v3 + 6),
                                    *(unsigned __int16*)(v3 + 8));
                            *(_BYTE*)(v301 + 432) = 0;
                            *(_DWORD*)(v301 + 437) = *(_DWORD*)(v3 + 2);
                            *(_DWORD*)(v301 + 441) = *(_DWORD*)(v3 + 6);
                            *(_DWORD*)(v301 + 433) = *(unsigned __int16*)(v3 + 10);
                            sub_49B950((_DWORD*)v301, *(unsigned __int16*)(v3 + 10));
                        }
                        goto LABEL_1130;
                    case 0x11u:
                        if (sub_43C700())
                            sub_45D320(*(unsigned __int16*)(v3 + 2));
                        goto LABEL_1133;
                    case 0x12u:
                        if (!sub_43C700())
                            goto LABEL_1133;
                        sub_45D4A0(*(unsigned __int16*)(v3 + 2));
                        v3 += 4;
                        break;
                    case 0x13u:
                        if (!sub_43C700())
                            goto LABEL_1133;
                        sub_45D400(*(unsigned __int16*)(v3 + 2));
                        v3 += 4;
                        break;
                    case 0x14u:
                        if (sub_43C700() != 1 || sub_470580())
                        {
                            LABEL_1085:
                            v3 += 2;
                        }
                        else
                        {
                            sub_4705B0();
                            v3 += 2;
                        }
                        break;
                    case 0x15u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 6));
                            if ((_DWORD)v5)
                            {
                                HIDWORD(v5) = *(_DWORD*)(v3 + 2);
                                *(_DWORD*)(v5 + 4820) = HIDWORD(v5);
                            }
                        }
                        v3 += 8;
                        break;
                    case 0x16u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 3));
                            if ((_DWORD)v5)
                                * (_BYTE*)(v5 + 4824) = *(_BYTE*)(v3 + 2);
                        }
                        v3 += 5;
                        break;
                    case 0x17u:
                        if (sub_43C700())
                        {
                            LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 3));
                            if ((_DWORD)v5)
                                * (_BYTE*)(v5 + 4825) = *(_BYTE*)(v3 + 2);
                        }
                        v3 += 5;
                        break;
                    case 0x18u:
                        if (sub_43C700() == 1)
                            sub_4BFBB0((_DWORD*) * (unsigned __int8*)(v3 + 2));
                        v3 += 3;
                        break;
                    case 0x19u:
                        if (!*(_DWORD*)& byte_5D4594[1200908])
                        {
                            *(_DWORD*)& byte_5D4594[1200908] = sub_44CFC0((CHAR*)& byte_587000[160496]);
                            *(_DWORD*)& byte_5D4594[1200912] = sub_44CFC0((CHAR*)& byte_587000[160508]);
                        }
                        v302 = (_DWORD*)sub_45A360_drawable(*(int*)& byte_5D4594[1200912], *(__int16*)(v3 + 2), *(__int16*)(v3 + 4));
                        if (v302)
                            sub_45A110_drawable(v302);
                        if (sub_43C700())
                        {
                            v380.field_0 = *(__int16*)(v3 + 2);
                            v380.field_4 = *(__int16*)(v3 + 4);
                            sub_49A150(&v380, *(int*)& byte_5D4594[1200908], *(_BYTE*)(v3 + 6));
                        }
                        goto LABEL_1149;
                    case 0x1Au:
                        if (sub_43C700())
                            sub_499610(*(int*)& byte_5D4594[1200788], 25, 500, 25, *(__int16*)(v3 + 2), *(__int16*)(v3 + 4));
                        v3 += 6;
                        break;
                    case 0x1Cu:
                        if (sub_43C700())
                            sub_41D1A0(*(unsigned __int8*)(v3 + 2));
                        v3 += 3;
                        break;
                    case 0x1Du:
                        if (sub_43C700())
                        {
                            sub_465DE0(*(unsigned __int16*)(v3 + 2));
                            v3 += 4;
                        }
                        else
                        {
                            LABEL_1133:
                            v3 += 4;
                        }
                        break;
                    case 0x1Eu:
                        v303 = sub_417040(*(unsigned __int16*)(v3 + 3));
                        if (sub_43C700() && v303)
                        {
                            if (v303 == *(char**)& byte_5D4594[2618908])
                            {
                                v348 = sub_424930(*(unsigned __int8*)(v3 + 2));
                                v304 = loadString_sub_40F1D0((char*)& byte_587000[160560], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8112);
                                nox_swprintf(v405, v304, v348);
                            }
                            else
                            {
                                v349 = sub_424930(*(unsigned __int8*)(v3 + 2));
                                v305 = loadString_sub_40F1D0((char*)& byte_587000[160624], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8115);
                                nox_swprintf(v405, v305, v303 + 4704, v349);
                            }
                            sub_445490(v405);
                        }
                        goto LABEL_1163;
                    case 0x1Fu:
                        v306 = sub_417040(*(unsigned __int16*)(v3 + 3));
                        if (!sub_43C700() || !v306)
                            goto LABEL_1163;
                        if (v306 == *(char**)& byte_5D4594[2618908])
                        {
                            v350 = sub_427240(*(unsigned __int8*)(v3 + 2));
                            v307 = loadString_sub_40F1D0((char*)& byte_587000[160696], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8145);
                            nox_swprintf(v403, v307, v350);
                        }
                        else
                        {
                            v351 = sub_427240(*(unsigned __int8*)(v3 + 2));
                            v308 = loadString_sub_40F1D0((char*)& byte_587000[160760], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8148);
                            nox_swprintf(v403, v308, v306 + 4704, v351);
                        }
                        sub_445490(v403);
                        v3 += 5;
                        break;
                    case 0x20u:
                        v309 = sub_417040(*(unsigned __int16*)(v3 + 3));
                        if (!sub_43C700() || !v309)
                            goto LABEL_1163;
                        if (v309 == *(char**)& byte_5D4594[2618908])
                        {
                            v352 = sub_425260(*(unsigned __int8*)(v3 + 2));
                            v310 = loadString_sub_40F1D0((char*)& byte_587000[160832], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8178);
                            nox_swprintf(v404, v310, v352);
                        }
                        else
                        {
                            v353 = sub_425260(*(unsigned __int8*)(v3 + 2));
                            v311 = loadString_sub_40F1D0((char*)& byte_587000[160896], 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8181);
                            nox_swprintf(v404, v311, v309 + 4704, v353);
                        }
                        sub_445490(v404);
                        v3 += 5;
                        break;
                    case 0x21u:
                        if (sub_43C700())
                        {
                            v383[0] = (int)& byte_587000[160948];
                            v383[1] = (int)& byte_587000[160988];
                            v383[2] = (int)& byte_587000[161028];
                            v383[3] = (int)& byte_587000[161068];
                            v383[4] = (int)& byte_587000[161112];
                            v354 = loadString_sub_40F1D0(
                                    (char*)v383[*(unsigned __int8*)(v3 + 51)],
                                    0,
                                    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
                                    8217);
                            v312 = loadString_sub_40F1D0((char*)(v3 + 2), 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8216);
                            nox_swprintf(v402, v312, v354);
                            sub_445490(v402);
                        }
                        v3 += 52;
                        break;
                    default:
                        return 0;
                }
                break;
            default:
                return 0;
        }
        v4 = v369;
        if (v3 >= v369)
            return 1;
    }
}
// 48EC64: variable 'v16' is possibly undefined
// 48ECC4: variable 'v18' is possibly undefined
// 48ED16: variable 'v20' is possibly undefined
// 48EDD6: variable 'v24' is possibly undefined
// 48F160: variable 'v31' is possibly undefined
// 48F596: variable 'v40' is possibly undefined
// 48F671: variable 'v42' is possibly undefined
// 48F6EB: variable 'v44' is possibly undefined
// 48F793: variable 'v49' is possibly undefined
// 48F831: variable 'v54' is possibly undefined
// 48F929: variable 'v57' is possibly undefined
// 48F952: variable 'v59' is possibly undefined
// 48FAB0: variable 'v62' is possibly undefined
// 48FB1E: variable 'v64' is possibly undefined
// 48FD0B: variable 'v69' is possibly undefined
// 48FDA2: variable 'v71' is possibly undefined
// 48FE68: variable 'v77' is possibly undefined
// 48FEFD: variable 'v82' is possibly undefined
// 48FF39: variable 'k' is possibly undefined
// 48FF58: variable 'v84' is possibly undefined
// 49008E: variable 'v88' is possibly undefined
// 490118: variable 'v90' is possibly undefined
// 490281: variable 'v92' is possibly undefined
// 4902D3: variable 'v94' is possibly undefined
// 490334: variable 'v96' is possibly undefined
// 490394: variable 'v98' is possibly undefined
// 4904D6: variable 'v103' is possibly undefined
// 49056F: variable 'v105' is possibly undefined
// 49060D: variable 'v109' is possibly undefined
// 49096A: variable 'v120' is possibly undefined
// 4909AC: variable 'v122' is possibly undefined
// 4909ED: variable 'v124' is possibly undefined
// 490AC3: variable 'v129' is possibly undefined
// 490B3C: variable 'v132' is possibly undefined
// 490C1D: variable 'v137' is possibly undefined
// 490CFC: variable 'v140' is possibly undefined
// 490FE2: variable 'v152' is possibly undefined
// 491687: variable 'v178' is possibly undefined
// 4916D9: variable 'v180' is possibly undefined
// 491710: variable 'v5' is possibly undefined
// 49172D: variable 'v182' is possibly undefined
// 491768: variable 'v184' is possibly undefined
// 49180F: variable 'v189' is possibly undefined
// 49187C: variable 'v193' is possibly undefined
// 4918F3: variable 'v196' is possibly undefined
// 491AA8: variable 'v198' is possibly undefined
// 491D48: variable 'v209' is possibly undefined
// 491EEA: variable 'v214' is possibly undefined
// 49252B: variable 'v236' is possibly undefined
// 49308F: variable 'v274' is possibly undefined
// 493335: variable 'v281' is possibly undefined
// 493364: variable 'v283' is possibly undefined
// 493378: variable 'v284' is possibly undefined
// 493639: variable 'v291' is possibly undefined
// 493696: variable 'v293' is possibly undefined
// 4936AF: variable 'v294' is possibly undefined
// 4939A7: variable 'v297' is possibly undefined
// 467460: using guessed type int sub_467460(void);

//----- (004947E0) --------------------------------------------------------
char* __cdecl sub_4947E0(int a1)
{
    __int16 v1; // ax
    int v2; // edi
    char* result; // eax
    int i; // esi

    if (sub_40A5C0(1))
    {
        v1 = sub_40A5B0();
        v2 = (unsigned __int16)sub_40A020(v1);
    }
    else
    {
        v2 = *((unsigned __int16*)sub_416590(0) + 27);
    }
    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        if (!(*(_BYTE*)(i + 3680) & 1))
        {
            if (i == a1)
            {
                if (sub_40A5C0(1024))
                {
                    if (*(_DWORD*)(i + 2140) >= v2)
                        * (_DWORD*)(i + 2140) = v2 - 1;
                }
                else
                {
                    *(_DWORD*)(i + 2136) = v2;
                }
            }
            else if (sub_40A5C0(1024))
            {
                if (*(_DWORD*)(i + 2140) < v2)
                    * (_DWORD*)(i + 2140) = v2;
            }
            else if (*(_DWORD*)(i + 2136) >= v2)
            {
                *(_DWORD*)(i + 2136) = v2 - 1;
            }
        }
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004948B0) --------------------------------------------------------
int __cdecl sub_4948B0(int a1)
{
    __int16 v1; // ax
    int v2; // edi
    char* i; // esi
    int result; // eax
    int j; // ebp
    char* v6; // eax
    char* v7; // esi
    int k; // ebp
    char* v9; // eax
    char* v10; // esi

    if (sub_40A5C0(1))
    {
        v1 = sub_40A5B0();
        v2 = (unsigned __int16)sub_40A020(v1);
    }
    else
    {
        v2 = *((unsigned __int16*)sub_416590(0) + 27);
    }
    for (i = sub_418B10(); i; i = sub_418B60((int)i))
    {
        if (i == (char*)a1)
        {
            if (!sub_40A5C0(1024))
                * ((_DWORD*)i + 13) = v2;
        }
        else if (!sub_40A5C0(1024) && *((_DWORD*)i + 13) >= v2)
        {
            *((_DWORD*)i + 13) = v2 - 1;
        }
    }
    if (sub_40A5C0(1))
    {
        result = sub_4DA7C0();
        for (j = result; result; j = result)
        {
            if (!sub_419180(j + 48, *(_BYTE*)(a1 + 57)))
            {
                v6 = sub_417040(*(_DWORD*)(j + 36));
                v7 = v6;
                if (v6)
                {
                    if (!(v6[3680] & 1))
                    {
                        if (sub_40A5C0(1024))
                        {
                            if (*((_DWORD*)v7 + 535) < v2)
                                * ((_DWORD*)v7 + 535) = v2;
                        }
                        else if (*((_DWORD*)v7 + 534) >= v2)
                        {
                            *((_DWORD*)v7 + 534) = v2 - 1;
                        }
                    }
                }
            }
            result = sub_4DA7F0(j);
        }
    }
    else
    {
        result = sub_45A000();
        for (k = result; result; k = result)
        {
            if (!sub_419180(k + 24, *(_BYTE*)(a1 + 57)))
            {
                v9 = sub_417040(*(_DWORD*)(k + 128));
                v10 = v9;
                if (v9)
                {
                    if (!(v9[3680] & 1))
                    {
                        if (sub_40A5C0(1024))
                        {
                            if (*((_DWORD*)v10 + 535) < v2)
                                * ((_DWORD*)v10 + 535) = v2;
                        }
                        else if (*((_DWORD*)v10 + 534) >= v2)
                        {
                            *((_DWORD*)v10 + 534) = v2 - 1;
                        }
                    }
                }
            }
            result = sub_45A010(k);
        }
    }
    return result;
}

//----- (00494A60) --------------------------------------------------------
int __cdecl sub_494A60(unsigned __int8* a1, int a2, _DWORD* a3)
{
    unsigned __int16 v3; // di
    unsigned __int16 v4; // bp
    unsigned __int8* v5; // esi
    int v6; // ebx
    int v7; // eax
    unsigned __int16 v8; // ax
    unsigned __int16 v9; // cx
    unsigned __int8* v10; // esi
    unsigned __int8 v11; // bl
    unsigned __int8* v12; // esi
    unsigned __int8 v13; // dl
    unsigned __int8 v14; // dl
    int v15; // esi
    _DWORD* v16; // eax
    unsigned __int8 v17; // cl
    int v18; // edx
    unsigned __int16 v20; // [esp+10h] [ebp-18h]
    unsigned __int16 v21; // [esp+14h] [ebp-14h]
    unsigned __int8* v22; // [esp+18h] [ebp-10h]
    char v23[10]; // [esp+1Ch] [ebp-Ch]
    unsigned __int8 v24; // [esp+2Ch] [ebp+4h]
    unsigned __int8 v25; // [esp+2Ch] [ebp+4h]
    unsigned __int8 v26; // [esp+30h] [ebp+8h]

    v22 = a1;
    if (*a1 == 0xFFu)
    {
        v3 = *(_WORD*)(a1 + 1);
        v4 = *(_WORD*)(a1 + 3);
        v5 = a1 + 5;
        v6 = *(unsigned __int16*)(a1 + 3);
        v24 = sub_57B9A0((int)& byte_5D4594[1198020], v3, v6, *(unsigned int*)& byte_5D4594[2598000]);
        if (v24 != -1)
        {
            sub_57BA10((int)& byte_5D4594[8 * v24 + 1198020], v3, v6, -1);
            v23[0] = -91;
            *(_WORD*)& v23[2] = v3;
            *(_WORD*)& v23[4] = v4;
            v23[1] = v24;
            *(_DWORD*)& v23[6] = -1;
            sub_40EBC0(a2, 0, v23, 10);
        }
    }
    else
    {
        v7 = 8 * *a1;
        v5 = a1 + 1;
        v3 = *(_WORD*)& byte_5D4594[v7 + 1198020];
        v4 = *(_WORD*)& byte_5D4594[v7 + 1198022];
    }
    v8 = *(_WORD*)v5;
    v9 = *((_WORD*)v5 + 1);
    v20 = *(_WORD*)v5;
    v10 = v5 + 4;
    v21 = v9;
    v11 = *v10;
    v12 = v10 + 1;
    if ((v11 & 0x80u) == 0)
    {
        v25 = 0;
    }
    else
    {
        v13 = *v12++;
        v25 = v13;
    }
    v14 = *v12;
    v15 = (int)(v12 + 1);
    v26 = v14;
    if (v3 || v4)
    {
        v16 = sub_48E970(v4, v3, v8, v9);
        if (v16)
        {
            v16[72] = *(_DWORD*)& byte_5D4594[2598000];
            v17 = (v11 >> 4) & 7;
            *((_BYTE*)v16 + 297) = v17;
            if (v17 > 3u)
                * ((_BYTE*)v16 + 297) = v17 + 1;
            if (v16[69] != v26)
            {
                v18 = *(_DWORD*)& byte_5D4594[2598000];
                v16[69] = v26;
                v16[79] = v18;
            }
            sub_45AB80((int)v16, v25);
        }
    }
    *a3 = v20;
    a3[1] = v21;
    sub_435600(v20, v21);
    return v15 - (_DWORD)v22;
}

//----- (00494C30) --------------------------------------------------------
unsigned __int8* __cdecl sub_494C30(unsigned __int8* a1, int a2, int* a3)
{
    unsigned __int8* v3; // esi
    unsigned __int8 v4; // al
    unsigned __int16 v6; // di
    _WORD* v7; // esi
    unsigned __int16 v8; // bp
    unsigned __int16 v9; // bx
    __int16* v10; // esi
    int v11; // eax
    int v12; // ecx
    int* v13; // ebx
    int v14; // esi
    int v15; // eax
    int v16; // ecx
    int v17; // eax
    _DWORD* v18; // eax
    int v19; // edi
    char v20; // cl
    unsigned __int8 v21; // al
    unsigned __int8 v22; // dl
    int v23; // ecx
    unsigned __int8 v24; // [esp+10h] [ebp-18h]
    int v25; // [esp+14h] [ebp-14h]
    char v26[10]; // [esp+1Ch] [ebp-Ch]
    char v27; // [esp+34h] [ebp+Ch]
    unsigned __int8 v28; // [esp+34h] [ebp+Ch]

    v3 = a1;
    v4 = *a1;
    v25 = 0;
    if (!*a1)
    {
        v4 = a1[1];
        v3 = a1 + 1;
        if (!v4 && !a1[2])
            return (unsigned __int8*)-3;
        v25 = 1;
    }
    if (v4 == 0xFFu)
    {
        v6 = *(_WORD*)(v3 + 1);
        v7 = v3 + 3;
        v8 = *v7;
        v9 = *v7;
        v10 = v7 + 1;
        v24 = sub_57B9A0((int)& byte_5D4594[1198020], v6, v9, *(unsigned int*)& byte_5D4594[2598000]);
        if (v24 != -1)
        {
            sub_57BA10((int)& byte_5D4594[8 * v24 + 1198020], v6, v9, *(_DWORD*)& byte_5D4594[2598000] + 60);
            v26[1] = v24;
            v26[0] = -91;
            *(_WORD*)& v26[2] = v6;
            *(_WORD*)& v26[4] = v8;
            *(_DWORD*)& v26[6] = *(_DWORD*)& byte_5D4594[2598000] + 60;
            sub_40EBC0(a2, 0, v26, 10);
        }
    }
    else
    {
        v11 = 8 * v4;
        v10 = (__int16*)(v3 + 1);
        v6 = *(_WORD*)& byte_5D4594[v11 + 1198020];
        v8 = *(_WORD*)& byte_5D4594[v11 + 1198022];
    }
    if (v25)
    {
        v12 = *v10;
        v13 = a3;
        v14 = (int)(v10 + 2);
        *a3 = v12;
        a3[1] = *(__int16*)(v14 - 2);
    }
    else
    {
        v13 = a3;
        v15 = *(char*)v10;
        v14 = (int)(v10 + 1);
        *a3 += v15;
        a3[1] += *(char*)(v14 - 1);
    }
    v16 = *v13;
    if ((int)* v13 < 0)
        return &a1[-v14];
    if (v16 > 6000)
        return &a1[-v14];
    v17 = v13[1];
    if (v17 < 0)
        return &a1[-v14];
    if (v17 > 6000)
        return &a1[-v14];
    v18 = sub_48E970(v8, v6, v16, v13[1]);
    v19 = (int)v18;
    if (!v18)
        return &a1[-v14];
    if (v18[28] & 0x200000)
    {
        v18[72] = *(_DWORD*)& byte_5D4594[2598000];
        v27 = *(_BYTE*)v14;
        v20 = *(_BYTE*)v14;
        v21 = (*(_BYTE*)v14 >> 4) & 7;
        *(_BYTE*)(v19 + 297) = v21;
        if (v21 > 3u)
            * (_BYTE*)(v19 + 297) = v21 + 1;
        if (v20 < 0)
        {
            sub_45AB80(v19, *(unsigned __int8*)++v14);
            v20 = v27;
        }
        if (*(_BYTE*)(v19 + 112) & 4)
        {
            v22 = *(_BYTE*)++v14;
            v28 = v22;
        }
        else
        {
            v28 = v20 & 0xF;
        }
        if (*(_DWORD*)(v19 + 276) != v28)
        {
            v23 = *(_DWORD*)& byte_5D4594[2598000];
            *(_DWORD*)(v19 + 276) = v28;
            *(_DWORD*)(v19 + 316) = v23;
        }
        ++v14;
    }
    else
    {
        v18[72] = *(_DWORD*)& byte_5D4594[2598000];
        sub_49AA00_drawable(v18);
    }
    *v13 = *(_DWORD*)(v19 + 12);
    v13[1] = *(_DWORD*)(v19 + 16);
    return (unsigned __int8*)(v14 - (_DWORD)a1);
}

//----- (00494E90) --------------------------------------------------------
int __cdecl sub_494E90(int a1)
{
    int v1; // esi
    unsigned __int8* v2; // eax
    int v3; // edi
    unsigned __int8* v4; // eax
    int v5; // esi

    v1 = a1;
    v2 = sub_40F120(a1, &a1);
    if (v2)
        v3 = sub_48EA70(v1, (unsigned int)v2, a1);
    else
        v3 = a1;
    v4 = sub_40ED60(v1, 1u, &a1);
    if (!v4)
        return v3;
    v5 = sub_48EA70(v1, (unsigned int)v4, a1);
    if (v5)
        sub_48D660();
    return v5;
}

//----- (00494F00) --------------------------------------------------------
int sub_494F00()
{
    int result; // eax
    int v1; // esi
    int v2; // eax

    *(_DWORD*)& byte_5D4594[1200772] = sub_44CFC0((CHAR*)& byte_587000[161236]);
    if (!*(_DWORD*)& byte_5D4594[1200772])
        return 0;
    result = sub_44CFC0((CHAR*)& byte_587000[161244]);
    *(_DWORD*)& byte_5D4594[1200776] = result;
    if (result)
    {
        result = sub_44CFC0((CHAR*)& byte_587000[161256]);
        *(_DWORD*)& byte_5D4594[1200780] = result;
        if (result)
        {
            result = sub_44CFC0((CHAR*)& byte_587000[161268]);
            *(_DWORD*)& byte_5D4594[1200784] = result;
            if (result)
            {
                result = sub_44CFC0((CHAR*)& byte_587000[161280]);
                *(_DWORD*)& byte_5D4594[1200788] = result;
                if (result)
                {
                    result = sub_44CFC0((CHAR*)& byte_587000[161292]);
                    *(_DWORD*)& byte_5D4594[1200792] = result;
                    if (result)
                    {
                        v1 = 0;
                        while (1)
                        {
                            v2 = sub_44CFC0(*(CHAR * *)& byte_587000[v1 + 161216]);
                            *(_DWORD*)& byte_5D4594[v1 + 1200812] = v2;
                            if (!v2)
                                break;
                            v1 += 4;
                            if (v1 >= 20)
                            {
                                *(_DWORD*)& byte_5D4594[1200796] = sub_44CFC0((CHAR*)& byte_587000[161376]);
                                return *(_DWORD*)& byte_5D4594[1200796] != 0;
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return result;
}

//----- (00494FE0) --------------------------------------------------------
void sub_494FE0()
{
    nox_srand(0xA33u);
}

//----- (00494FF0) --------------------------------------------------------
char* sub_494FF0()
{
    int v0; // eax
    unsigned __int8* v1; // ecx

    v0 = 0;
    v1 = &byte_5D4594[1200928];
    while (*(_DWORD*)v1)
    {
        v1 += 16;
        ++v0;
        if ((int)v1 >= (int)& byte_5D4594[1201440])
            return 0;
    }
    return (char*)& byte_5D4594[16 * v0 + 1200916];
}

//----- (00495020) --------------------------------------------------------
char* __cdecl sub_495020(int a1)
{
    int v1; // eax
    unsigned __int8* v2; // ecx

    v1 = 0;
    v2 = &byte_5D4594[1200916];
    while (!*((_DWORD*)v2 + 3) || *(_DWORD*)v2 != a1)
    {
        v2 += 16;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[1201428])
            return 0;
    }
    return (char*)& byte_5D4594[16 * v1 + 1200916];
}

//----- (00495060) --------------------------------------------------------
int __cdecl sub_495060(int a1, __int16 a2, __int16 a3)
{
    unsigned __int8* v3; // eax
    char* v4; // eax

    v3 = &byte_5D4594[1200916];
    do
    {
        if (*((_DWORD*)v3 + 3) == 1 && *(_DWORD*)v3 == a1)
            return 1;
        v3 += 16;
    } while ((int)v3 < (int)& byte_5D4594[1201428]);
    v4 = sub_494FF0();
    if (v4)
    {
        *((_WORD*)v4 + 3) = a2;
        *((_WORD*)v4 + 4) = a3;
        *((_DWORD*)v4 + 3) = 1;
        v4[4] = 0;
        *(_DWORD*)v4 = a1;
        return 1;
    }
    return 0;
}

//----- (004950C0) --------------------------------------------------------
int __cdecl sub_4950C0(int a1)
{
    char* v1; // eax

    v1 = sub_495020(a1);
    if (!v1)
        return 0;
    *((_DWORD*)v1 + 3) = 0;
    return 1;
}

//----- (004950F0) --------------------------------------------------------
int __cdecl sub_4950F0(int a1, char a2)
{
    char* v2; // eax

    v2 = sub_495020(a1);
    if (!v2)
        return 0;
    v2[4] = a2;
    return 1;
}

//----- (00495120) --------------------------------------------------------
int __cdecl sub_495120(int a1, __int16 a2, __int16 a3)
{
    char* v3; // eax

    v3 = sub_495020(a1);
    if (!v3)
        return 0;
    *((_WORD*)v3 + 3) = a2;
    *((_WORD*)v3 + 4) = a3;
    return 1;
}

//----- (00495150) --------------------------------------------------------
int __cdecl sub_495150(int a1, __int16 a2)
{
    char* v2; // eax

    v2 = sub_495020(a1);
    if (!v2)
        return 0;
    *((_WORD*)v2 + 3) = a2;
    return 1;
}

//----- (00495180) --------------------------------------------------------
int __cdecl sub_495180(int a1, _WORD* a2, _WORD* a3, _BYTE* a4)
{
    char* v4; // eax

    v4 = sub_495020(a1);
    if (!v4)
        return 0;
    *a2 = *((_WORD*)v4 + 3);
    *a3 = *((_WORD*)v4 + 4);
    *a4 = v4[4];
    return 1;
}

//----- (004951C0) --------------------------------------------------------
char* sub_4951C0()
{
    char* result; // eax

    result = (char*)& byte_5D4594[1200922];
    do
    {
        *(_DWORD*)(result + 6) = 0;
        *(_WORD*)result = 0;
        *((_WORD*)result + 1) = 0;
        *(result - 2) = 0;
        *(_DWORD*)(result - 6) = 0;
        result += 16;
    } while ((int)result < (int)& byte_5D4594[1201434]);
    return result;
}

//----- (004951F0) --------------------------------------------------------
BOOL __cdecl sub_4951F0(int a1)
{
    return sub_495020(a1) != 0;
}

//----- (00495210) --------------------------------------------------------
int __cdecl sub_495210(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // eax

    v1 = *(_DWORD*)& byte_5D4594[1203836];
    if ((*(_DWORD*)& byte_5D4594[1203836] + 1) % 100 == *(_DWORD*)& byte_5D4594[1203840])
        * (_DWORD*)& byte_5D4594[1203840] = (*(_DWORD*)& byte_5D4594[1203840] + 1) % 100;
    if (*(_BYTE*)(a1 + 10) == 1)
    {
        v2 = *(unsigned __int16*)(a1 + 8);
        if ((unsigned __int16)v2 == *(_DWORD*)& byte_5D4594[1203844])
        {
            *(_WORD*)(a1 + 8) = *(_WORD*)& byte_5D4594[1203856];
            LABEL_8:
            v1 = *(_DWORD*)& byte_5D4594[1203836];
            goto LABEL_9;
        }
        if (v2 == *(_DWORD*)& byte_5D4594[1203848])
        {
            *(_WORD*)(a1 + 8) = *(_WORD*)& byte_5D4594[1203852];
            goto LABEL_8;
        }
    }
    LABEL_9:
    v3 = 24 * v1;
    *(_DWORD*)& byte_5D4594[v3 + 1201428] = *(unsigned __int16*)(a1 + 2);
    *(_DWORD*)& byte_5D4594[v3 + 1201432] = *(unsigned __int16*)(a1 + 4);
    *(_DWORD*)& byte_5D4594[v3 + 1201436] = *(unsigned __int16*)(a1 + 6);
    *(_DWORD*)& byte_5D4594[v3 + 1201440] = *(unsigned __int16*)(a1 + 8);
    *(_DWORD*)& byte_5D4594[v3 + 1201444] = *(unsigned __int8*)(a1 + 10);
    *(_DWORD*)& byte_5D4594[v3 + 1201448] = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)& byte_5D4594[1203836] = (v1 + 1) % 100;
    return sub_4952E0((_WORD*)a1);
}

//----- (004952E0) --------------------------------------------------------
int __cdecl sub_4952E0(_WORD* a1)
{
    char* v1; // eax
    wchar_t* v2; // eax
    char* v3; // eax
    wchar_t* v4; // eax
    char* v5; // eax
    wchar_t* v6; // eax
    int v8; // [esp-4h] [ebp-108h]
    wchar_t* v9; // [esp-4h] [ebp-108h]
    int v10; // [esp+0h] [ebp-104h]
    wchar_t v11[32]; // [esp+4h] [ebp-100h]
    wchar_t v12[32]; // [esp+44h] [ebp-C0h]
    wchar_t v13[64]; // [esp+84h] [ebp-80h]

    if (a1[1] && (v1 = sub_417040((unsigned __int16)a1[1])) != 0)
    {
        v8 = (int)(v1 + 4704);
        v2 = loadString_sub_40F1D0((char*)& byte_587000[161432], 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c", 48);
        nox_swprintf(v13, v2, v8);
        if (a1[2])
        {
            v3 = sub_417040((unsigned __int16)a1[2]);
            if (v3)
            {
                nox_swprintf(v12, L" + %s", v3 + 4704);
                nox_wcscat(v13, v12);
            }
        }
    }
    else
    {
        v9 = loadString_sub_40F1D0((char*)& byte_587000[161512], 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c", 65);
        v4 = loadString_sub_40F1D0((char*)& byte_587000[161576], 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c", 64);
        nox_swprintf(v13, v4, v9);
    }
    if (a1[3])
    {
        v5 = sub_417040((unsigned __int16)a1[3]);
        if (v5)
        {
            v10 = (int)(v5 + 4704);
            v6 = loadString_sub_40F1D0((char*)& byte_587000[161644], 0, "C:\\NoxPost\\src\\client\\Network\\deathmsg.c", 72);
            nox_swprintf(v11, v6, v10);
        }
    }
    return sub_450C00(4u, (wchar_t*)& byte_587000[161668], v11, v13);
}

//----- (00495430) --------------------------------------------------------
int sub_495430()
{
    int v0; // ecx
    int v1; // esi
    int result; // eax
    int i; // edi
    __int64 v4; // rtt

    *(_DWORD*)& byte_5D4594[1203832] = 0;
    sub_434560(0);
    sub_4345F0(0);
    sub_434600(0);
    v0 = *(_DWORD*)& byte_5D4594[1203840];
    v1 = *(_DWORD*)& byte_5D4594[1203840];
    result = *(_DWORD*)& byte_5D4594[1203836];
    for (i = nox_win_height / 4 / 36; v1 != *(_DWORD*)& byte_5D4594[1203836]; v1 = (v1 + 1) % 100)
    {
        if (*(_DWORD*)& byte_5D4594[1203832] > i)
            break;
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[24 * v0 + 1201448]) <= 0x5A)
        {
            sub_495500((int*)& byte_5D4594[24 * v1 + 1201428]);
            v0 = *(_DWORD*)& byte_5D4594[1203840];
            ++* (_DWORD*)& byte_5D4594[1203832];
        }
        else
        {
            v4 = v0 + 1;
            v0 = (v0 + 1) % 100;
            *(_DWORD*)& byte_5D4594[1203840] = v4 % 100;
        }
        result = *(_DWORD*)& byte_5D4594[1203836];
    }
    return result;
}

//----- (00495500) --------------------------------------------------------
int* __cdecl sub_495500(int* a1)
{
    int v1; // edi
    int v2; // eax
    int v3; // ebp
    bool v4; // zf
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    int v8; // ebp
    int v11; // esi
    int v12; // esi
    int v13; // ecx
    int v14; // kr04_4
    int v15; // esi
    int v16; // edi
    int v17; // ebx
    int v18; // esi
    int* result; // eax
    int v20; // esi
    int v21; // [esp+10h] [ebp-DCh]
    int v22; // [esp+14h] [ebp-D8h]
    int v23; // [esp+18h] [ebp-D4h]
    int v24; // [esp+1Ch] [ebp-D0h]
    int v25; // [esp+20h] [ebp-CCh]
    int v26; // [esp+24h] [ebp-C8h]
    int v27; // [esp+28h] [ebp-C4h]
    wchar_t v28[32]; // [esp+2Ch] [ebp-C0h]
    wchar_t v29[32]; // [esp+6Ch] [ebp-80h]
    wchar_t v30[32]; // [esp+ACh] [ebp-40h]

    v1 = sub_43F360((char*)& byte_587000[161680]);
    v2 = *a1;
    v3 = 0;
    v4 = *a1 == 0;
    v24 = v1;
    v29[0] = 0;
    v28[0] = 0;
    v30[0] = 0;
    v23 = 0;
    v25 = 0;
    v27 = 0;
    v26 = 0;
    if (!v4)
    {
        v5 = sub_417040(v2);
        if (v5)
        {
            v3 = 1;
            nox_swprintf(v29, (const wchar_t*)v5 + 2352);
        }
    }
    if (a1[1])
    {
        v6 = sub_417040(a1[1]);
        if (v6)
        {
            if (v3)
                nox_swprintf(v28, L"+%s", v6 + 4704);
            else
                nox_swprintf(v28, (const wchar_t*)v6 + 2352);
        }
    }
    if (a1[2])
    {
        v7 = sub_417040(a1[2]);
        if (v7)
            nox_swprintf(v30, (const wchar_t*)v7 + 2352);
    }
    if (a1[4] != 1)
    {
        if (a1[4] == 2)
        {
            switch (a1[3])
            {
                case 1:
                case 12:
                    v8 = sub_424A90(5);
                    goto LABEL_26;
                case 2:
                    v8 = sub_425310(1, 0);
                    goto LABEL_26;
                case 4:
                    v8 = sub_424A90(130);
                    goto LABEL_26;
                case 5:
                    v8 = sub_424A90(60);
                    goto LABEL_26;
                case 9:
                case 17:
                    v8 = sub_424A90(43);
                    goto LABEL_26;
                case 15:
                    v8 = sub_424A90(56);
                    goto LABEL_26;
                case 16:
                    v8 = sub_424A90(16);
                    goto LABEL_26;
                default:
                    break;
            }
        }
        LABEL_27:
        v8 = *(_DWORD*)& byte_5D4594[1203828];
        goto LABEL_28;
    }
    nox_thing* t9 = nox_get_thing(a1[3]);
    if (!t9)
        goto LABEL_27;
    if (t9->pri_class & 0x1001000)
        sub_4B9650(a1[3]);
    v8 = t9->pretty_image;
    LABEL_26:
    if (!v8)
        goto LABEL_27;
    LABEL_28:
    sub_47D5C0(v8, &v27, &v26, &v23, &v25);
    sub_43F840(v1, v29, &v21, &v22, 0);
    v11 = v21;
    sub_43F840(v1, v28, &v21, &v22, 0);
    v12 = v21 + v11;
    sub_43F840(v1, v30, &v21, &v22, 0);
    v13 = v12 + v23 + v21 + 20;
    v14 = nox_win_width - (v12 + v23 + v21 + 10);
    v15 = v14 / 2;
    v16 = 36 * *(_DWORD*)& byte_5D4594[1203832];
    sub_49CF10(v14 / 2 - 5, 36 * *(_DWORD*)& byte_5D4594[1203832], v13, 36);
    v17 = v16 + (36 - v22) / 2;
    if (*a1)
    {
        sub_434390(*(int*)& byte_5D4594[2597996]);
        if (*a1 == *(_DWORD*)& byte_5D4594[2616328])
            sub_434390(*(int*)& byte_5D4594[2618904]);
        v15 = sub_43F6E0(v24, (__int16*)v29, v14 / 2, v17);
    }
    if (a1[1])
    {
        sub_434390(*(int*)& byte_5D4594[2597996]);
        if (a1[1] == *(_DWORD*)& byte_5D4594[2616328])
            sub_434390(*(int*)& byte_5D4594[2618904]);
        v15 = sub_43F6E0(v24, (__int16*)v28, v15, v17);
    }
    v18 = v15 + 5;
    if (v8)
        sub_47D2C0(v8, v18 - v27, v16 + (36 - v25) / 2 - v26);
    result = a1;
    v20 = v18 + v23 + 5;
    if (a1[2])
    {
        sub_434390(*(int*)& byte_5D4594[2597996]);
        if (a1[2] == *(_DWORD*)& byte_5D4594[2616328])
            sub_434390(*(int*)& byte_5D4594[2618904]);
        result = (int*)sub_43F6E0(v24, (__int16*)v30, v20, v17);
    }
    return result;
}

//----- (004958F0) --------------------------------------------------------
int sub_4958F0()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1203840] = 0;
    *(_DWORD*)& byte_5D4594[1203836] = 0;
    if (!*(_DWORD*)& byte_5D4594[1203844])
        * (_DWORD*)& byte_5D4594[1203844] = sub_44CFC0((CHAR*)& byte_587000[161696]);
    if (!*(_DWORD*)& byte_5D4594[1203848])
        * (_DWORD*)& byte_5D4594[1203848] = sub_44CFC0((CHAR*)& byte_587000[161708]);
    if (!*(_DWORD*)& byte_5D4594[1203852])
        * (_DWORD*)& byte_5D4594[1203852] = sub_44CFC0((CHAR*)& byte_587000[161720]);
    if (!*(_DWORD*)& byte_5D4594[1203856])
        * (_DWORD*)& byte_5D4594[1203856] = sub_44CFC0((CHAR*)& byte_587000[161724]);
    result = sub_424A90(15);
    *(_DWORD*)& byte_5D4594[1203828] = result;
    return result;
}

//----- (00495980) --------------------------------------------------------
BOOL sub_495980()
{
    *(_DWORD*)& byte_5D4594[1203860] = nox_new_alloc_class("FriendListClass", 8, 128);
    return *(_DWORD*)& byte_5D4594[1203860] != 0;
}

//----- (004959B0) --------------------------------------------------------
void sub_4959B0()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1203860]);
    *(_DWORD*)& byte_5D4594[1203864] = 0;
}

//----- (004959D0) --------------------------------------------------------
int sub_4959D0()
{
    int result; // eax

    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1203860]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1203860] = 0;
    *(_DWORD*)& byte_5D4594[1203864] = 0;
    return result;
}

//----- (004959F0) --------------------------------------------------------
_DWORD* __cdecl sub_4959F0(int a1)
{
    _DWORD* result; // eax

    result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1203860]);
    if (result)
    {
        *result = a1;
        result[1] = *(_DWORD*)& byte_5D4594[1203864];
        *(_DWORD*)& byte_5D4594[1203864] = result;
    }
    return result;
}

//----- (00495A20) --------------------------------------------------------
void __cdecl sub_495A20(int a1)
{
    int v1; // eax
    int v2; // ecx

    v1 = *(_DWORD*)& byte_5D4594[1203864];
    v2 = 0;
    if (*(_DWORD*)& byte_5D4594[1203864])
    {
        while (*(_DWORD*)v1 != a1)
        {
            v2 = v1;
            v1 = *(_DWORD*)(v1 + 4);
            if (!v1)
                return;
        }
        if (v2)
            * (_DWORD*)(v2 + 4) = *(_DWORD*)(v1 + 4);
        else
            *(_DWORD*)& byte_5D4594[1203864] = *(_DWORD*)(v1 + 4);
        sub_414330(*(unsigned int**)& byte_5D4594[1203860], (_QWORD*)v1);
    }
}

//----- (00495A80) --------------------------------------------------------
int __cdecl sub_495A80(int a1)
{
    _DWORD* v1; // eax

    v1 = *(_DWORD * *)& byte_5D4594[1203864];
    if (!*(_DWORD*)& byte_5D4594[1203864])
        return 0;
    while (*v1 != a1)
    {
        v1 = (_DWORD*)v1[1];
        if (!v1)
            return 0;
    }
    return 1;
}

//----- (00495AB0) --------------------------------------------------------
int sub_495AB0()
{
    int result; // eax

    result = nox_new_alloc_class("DrawableFX", 80, 128);
    *(_DWORD*)& byte_5D4594[1203868] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1203872] = 0;
        result = 1;
    }
    return result;
}

//----- (00495AE0) --------------------------------------------------------
int sub_495AE0()
{
    int result; // eax

    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1203868]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1203868] = 0;
    *(_DWORD*)& byte_5D4594[1203872] = 0;
    return result;
}

//----- (00495B00) --------------------------------------------------------
void __cdecl sub_495B00(int a1)
{
    _DWORD* v1; // esi
    _DWORD* v2; // edi

    v1 = *(_DWORD * *)(a1 + 456);
    if (v1)
    {
        do
        {
            v2 = (_DWORD*)v1[16];
            sub_495B50(v1);
            sub_414330(*(unsigned int**)& byte_5D4594[1203868], v1);
            v1 = v2;
        } while (v2);
        *(_DWORD*)(a1 + 456) = 0;
    }
    else
    {
        *(_DWORD*)(a1 + 456) = 0;
    }
}

//----- (00495B50) --------------------------------------------------------
_DWORD* __cdecl sub_495B50(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx
    int v4; // ecx
    int v5; // edx
    int v6; // ecx

    result = a1;
    if (a1)
    {
        v2 = a1[18];
        if (v2)
            * (_DWORD*)(v2 + 76) = a1[19];
        v3 = a1[19];
        if (v3)
            * (_DWORD*)(v3 + 72) = a1[18];
        else
            *(_DWORD*)& byte_5D4594[1203872] = a1[18];
        v4 = a1[16];
        v5 = a1[15];
        if (v4)
            * (_DWORD*)(v4 + 68) = a1[17];
        v6 = a1[17];
        if (v6)
        {
            *(_DWORD*)(v6 + 64) = a1[16];
        }
        else
        {
            result = (_DWORD*)a1[16];
            *(_DWORD*)(v5 + 456) = result;
        }
    }
    return result;
}

//----- (00495BB0) --------------------------------------------------------
_DWORD* __cdecl sub_495BB0(_DWORD* a1, _DWORD* a2)
{
    _DWORD* result; // eax
    _DWORD* v3; // esi

    result = (_DWORD*)a1[114];
    if (result)
    {
        do
        {
            v3 = (_DWORD*)result[16];
            if (*result == 1)
            {
                sub_495BF0((int)a1, (int)result, (int)a2);
            }
            else if (*result == 2)
            {
                sub_495D00(a1, (int)result, a2);
            }
            result = v3;
        } while (v3);
    }
    return result;
}

//----- (00495BF0) --------------------------------------------------------
int __cdecl sub_495BF0(int a1, int a2, int a3)
{
    int v3; // ecx
    int result; // eax
    _DWORD* v5; // edx
    int v6; // edx
    int v7; // edi
    int v8; // ebx
    _DWORD* v9; // edi
    int v10; // ecx
    _DWORD* v11; // eax
    char v12; // al
    unsigned __int8 v13; // [esp+10h] [ebp-Ch]
    int v14; // [esp+14h] [ebp-8h]
    int v15; // [esp+18h] [ebp-4h]

    v3 = 0;
    result = *(unsigned __int8*)(a2 + 56);
    v13 = -1;
    if (result <= 0)
    {
        LABEL_6:
        if (*(_DWORD*)(a1 + 12) == *(_DWORD*)(a1 + 32) && *(_DWORD*)(a1 + 16) == *(_DWORD*)(a1 + 36))
        {
            *(_BYTE*)(a2 + 56) = 0;
            return result;
        }
    }
    else
    {
        v5 = (_DWORD*)(a2 + 8);
        while (*v5 == v5[2] || v5[1] == v5[3])
        {
            ++v3;
            v5 += 2;
            if (v3 >= result)
                goto LABEL_6;
        }
    }
    v6 = *(_DWORD*)(a1 + 12);
    v7 = *(_DWORD*)(a1 + 16);
    v8 = 0;
    v14 = *(_DWORD*)(a1 + 12);
    v15 = *(_DWORD*)(a1 + 16);
    if (result > 0)
    {
        v9 = (_DWORD*)(a2 + 8);
        do
        {
            v13 -= 42;
            sub_434560(1);
            sub_434580(v13);
            *(_DWORD*)(a1 + 12) = *v9;
            *(_DWORD*)(a1 + 16) = v9[1];
            (*(void(__cdecl * *)(int, int))(a1 + 300))(a3, a1);
            ++v8;
            v9 += 2;
        } while (v8 < *(unsigned __int8*)(a2 + 56));
        v7 = v15;
        v6 = v14;
    }
    v10 = *(unsigned __int8*)(a2 + 56);
    if (v10 > 0)
    {
        v11 = (_DWORD*)(a2 + 8 * v10);
        do
        {
            v11[2] = *v11;
            v11[3] = v11[1];
            v11 -= 2;
            --v10;
        } while (v10);
    }
    *(_DWORD*)(a1 + 12) = v6;
    *(_DWORD*)(a1 + 16) = v7;
    v12 = *(_BYTE*)(a2 + 56);
    *(_DWORD*)(a2 + 8) = v6;
    *(_DWORD*)(a2 + 12) = v7;
    if (v12 != 5)
        * (_BYTE*)(a2 + 56) = v12 + 1;
    return sub_434560(0);
}

//----- (00495D00) --------------------------------------------------------
int __cdecl sub_495D00(_DWORD* a1, int a2, _DWORD* a3)
{
    int v3; // eax
    int v4; // ecx
    _DWORD* v5; // edx
    _DWORD* v6; // ebp
    int result; // eax
    _DWORD* v8; // edi
    int v9; // ebx
    int v10; // esi
    int v11; // ebx
    int v12; // ecx
    int v13; // esi
    int v14; // ebp
    int v15; // esi
    int v16; // ebp
    int v17; // eax
    bool v18; // cc
    int v19; // edx
    _DWORD* v20; // eax
    char v21; // al
    float v22; // [esp+0h] [ebp-2Ch]
    float v23; // [esp+0h] [ebp-2Ch]
    float v24; // [esp+0h] [ebp-2Ch]
    float v25; // [esp+0h] [ebp-2Ch]
    unsigned __int8 v26; // [esp+14h] [ebp-18h]
    int v27; // [esp+18h] [ebp-14h]
    float* v28; // [esp+1Ch] [ebp-10h]
    float* v29; // [esp+20h] [ebp-Ch]
    int v30; // [esp+28h] [ebp-4h]
    int v31; // [esp+28h] [ebp-4h]
    _DWORD* v32; // [esp+38h] [ebp+Ch]

    v3 = 0;
    v4 = *(unsigned __int8*)(a2 + 56);
    v26 = -1;
    if (v4 <= 0)
    {
        LABEL_6:
        v6 = a1;
        if (a1[3] == a1[8])
        {
            result = a1[9];
            if (a1[4] == result)
            {
                *(_BYTE*)(a2 + 56) = 0;
                return result;
            }
        }
    }
    else
    {
        v5 = (_DWORD*)(a2 + 8);
        while (*v5 == v5[2] || v5[1] == v5[3])
        {
            ++v3;
            v5 += 2;
            if (v3 >= v4)
                goto LABEL_6;
        }
        v6 = a1;
    }
    v8 = a3;
    v9 = v6[3] + *a3 - a3[4];
    v10 = 8 * v6[77];
    v30 = v6[4] - *((__int16*)v6 + 52) - *((__int16*)v6 + 53) - a3[5] + a3[1] - 10;
    v28 = (float*)& byte_587000[64 * v6[77] + 194136];
    v22 = *(float*)& byte_587000[64 * v6[77] + 194136] * -12.0;
    v11 = nox_float2int(v22) + v9;
    v29 = (float*)& byte_587000[8 * v10 + 194140];
    v23 = *(float*)& byte_587000[8 * v10 + 194140] * -12.0;
    v27 = 0;
    v31 = nox_float2int(v23) + v30;
    v12 = a2;
    if (*(_BYTE*)(a2 + 56))
    {
        v32 = (_DWORD*)(a2 + 12);
        do
        {
            v26 -= 63;
            sub_434560(1);
            sub_434580(v26);
            v13 = *v8 + *(v32 - 1) - v8[4];
            v14 = *v32 - *((__int16*)v6 + 52) - *((__int16*)v6 + 53) - v8[5] + v8[1] - 10;
            v24 = *v28 * -12.0;
            v15 = nox_float2int(v24) + v13;
            v25 = *v29 * -12.0;
            v16 = nox_float2int(v25) + v14;
            v17 = sub_4344A0(200, 200, 200);
            sub_434460(v17);
            sub_49F500(v11, v31);
            sub_49F500(v15, v16);
            sub_49E4B0();
            v12 = a2;
            v32 += 2;
            v31 = v16;
            v6 = a1;
            v18 = v27 + 1 < *(unsigned __int8*)(a2 + 56);
            v11 = v15;
            ++v27;
        } while (v18);
    }
    v19 = *(unsigned __int8*)(v12 + 56);
    if (v19 > 0)
    {
        v20 = (_DWORD*)(v12 + 8 * v19);
        do
        {
            v20[2] = *v20;
            v20[3] = v20[1];
            v20 -= 2;
            --v19;
        } while (v19);
    }
    *(_DWORD*)(v12 + 8) = v6[3];
    *(_DWORD*)(v12 + 12) = v6[4];
    v21 = *(_BYTE*)(v12 + 56);
    if (v21 != 5)
        * (_BYTE*)(v12 + 56) = v21 + 1;
    return sub_434560(0);
}

//----- (00495F30) --------------------------------------------------------
void __cdecl sub_495F30(int a1, int a2)
{
    _DWORD* v2; // esi

    v2 = *(_DWORD * *)(a1 + 456);
    if (v2)
    {
        while (*v2 != a2)
        {
            v2 = (_DWORD*)v2[16];
            if (!v2)
                return;
        }
        sub_495B50(v2);
        sub_414330(*(unsigned int**)& byte_5D4594[1203868], v2);
    }
}

//----- (00495F70) --------------------------------------------------------
void __cdecl sub_495F70(int a1)
{
    _DWORD* v1; // eax

    if (a1 && sub_496020(a1, 1) != 1)
    {
        v1 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1203868]);
        if (v1)
        {
            *v1 = 1;
            v1[1] = 0;
            sub_495FC0(v1, a1);
        }
    }
}

//----- (00495FC0) --------------------------------------------------------
_DWORD* __cdecl sub_495FC0(_DWORD* a1, int a2)
{
    _DWORD* result; // eax
    int v3; // edx

    result = a1;
    if (a1 && a2)
    {
        a1[15] = a2;
        a1[18] = *(_DWORD*)& byte_5D4594[1203872];
        a1[19] = 0;
        if (*(_DWORD*)& byte_5D4594[1203872])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1203872] + 76) = a1;
        *(_DWORD*)& byte_5D4594[1203872] = a1;
        a1[16] = *(_DWORD*)(a2 + 456);
        a1[17] = 0;
        v3 = *(_DWORD*)(a2 + 456);
        if (v3)
            * (_DWORD*)(v3 + 68) = a1;
        *(_DWORD*)(a2 + 456) = a1;
    }
    return result;
}

//----- (00496020) --------------------------------------------------------
int __cdecl sub_496020(int a1, int a2)
{
    _DWORD* v2; // eax

    v2 = *(_DWORD * *)(a1 + 456);
    if (!v2)
        return 0;
    while (*v2 != a2)
    {
        v2 = (_DWORD*)v2[16];
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (00496050) --------------------------------------------------------
void __cdecl sub_496050(int a1)
{
    _DWORD* v1; // eax
    int v2; // ecx

    if (a1 && sub_496020(a1, 2) != 1)
    {
        v1 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1203868]);
        if (v1)
        {
            *v1 = 2;
            v2 = *((unsigned __int8*)v1 + 56);
            v1[1] = 0;
            v1[2 * v2 + 2] = *(_DWORD*)(a1 + 12);
            v1[2 * v2 + 3] = *(_DWORD*)(a1 + 16);
            ++* ((_BYTE*)v1 + 56);
            sub_495FC0(v1, a1);
        }
    }
}

//----- (004960B0) --------------------------------------------------------
int sub_4960B0()
{
    int result; // eax

    result = (int)nox_malloc(4 * (4 * nox_win_width / 23 * (nox_win_height / 23) / 2));
    *(_DWORD*)& byte_5D4594[1217456] = result;
    if (result)
    {
        sub_4CA860();
        result = 1;
    }
    return result;
}

//----- (00496120) --------------------------------------------------------
int sub_496120()
{
    if (*(_DWORD*)& byte_5D4594[1217456])
    {
        free(*(LPVOID*)& byte_5D4594[1217456]);
        *(_DWORD*)& byte_5D4594[1217456] = 0;
    }
    return 1;
}

//----- (00496150) --------------------------------------------------------
int __cdecl sub_496150(int* a1)
{
    int v1; // esi
    int v2; // ecx
    int v3; // ebx
    int v4; // ebp
    int v5; // ebx
    int v6; // esi
    int v7; // eax
    int v8; // ebp
    unsigned __int8* v9; // esi
    unsigned __int8 v10; // dl
    int v11; // ecx
    unsigned __int8 v12; // al
    unsigned __int8 v13; // al
    int v14; // edx
    unsigned __int8 v15; // al
    unsigned __int8* v16; // esi
    bool v17; // zf
    int v18; // ebp
    int v19; // esi
    int v20; // ebx
    int v21; // ebp
    int v22; // eax
    int v23; // ecx
    char v24; // al
    int v25; // ebp
    int v26; // edx
    int v27; // ecx
    int v28; // ebp
    int v29; // eax
    int v30; // ebp
    int v31; // edx
    int v32; // ecx
    int v33; // ecx
    int v34; // ebp
    double v35; // st7
    int v36; // ebx
    int v37; // ebx
    int v38; // ecx
    int v39; // ebp
    int v40; // ebx
    int v41; // ebx
    int v42; // ebx
    double v43; // st7
    double v44; // st7
    int v45; // ebx
    int v46; // ebx
    int v47; // ebx
    int v48; // edx
    int v49; // ecx
    int v50; // edx
    int v51; // ebx
    int v52; // ebx
    int v53; // esi
    int v54; // eax
    unsigned __int8 v55; // cl
    unsigned __int8 v56; // dl
    int v57; // ecx
    int v58; // edi
    int v59; // ebp
    int v60; // ecx
    int v61; // ecx
    int v62; // ecx
    int v63; // ecx
    int v64; // ebp
    int v65; // ecx
    int v66; // ecx
    int v68; // [esp+4h] [ebp-8Ch]
    int v69; // [esp+18h] [ebp-78h]
    int v70; // [esp+1Ch] [ebp-74h]
    int v71; // [esp+20h] [ebp-70h]
    int v72; // [esp+20h] [ebp-70h]
    unsigned int v73; // [esp+28h] [ebp-68h]
    int v74; // [esp+2Ch] [ebp-64h]
    int v75; // [esp+30h] [ebp-60h]
    int v76; // [esp+34h] [ebp-5Ch]
    float2 a4; // [esp+38h] [ebp-58h]
    float2 v78; // [esp+40h] [ebp-50h]
    int v79; // [esp+48h] [ebp-48h]
    int v80; // [esp+4Ch] [ebp-44h]
    int2 a1a; // [esp+50h] [ebp-40h]
    int2 a2; // [esp+58h] [ebp-38h]
    float4 v83; // [esp+60h] [ebp-30h]
    float4 a3; // [esp+70h] [ebp-20h]
    float4 v86; // [esp+80h] [ebp-10h]

    sub_4CAE60();
    *(_DWORD*)& byte_5D4594[1217464] = 0;
    *(_DWORD*)& byte_5D4594[1217460] = 0;
    v1 = a1[4];
    v2 = a1[5];
    v3 = a1[8];
    v79 = v1 / 23;
    v80 = v2 / 23;
    v74 = (v3 + v1) / 23 - v1 / 23;
    v4 = (a1[9] + v2) / 23 - v2 / 23;
    *(_DWORD*)& byte_5D4594[1217444] = v1 + v3 / 2;
    *(_DWORD*)& byte_5D4594[1217448] = a1[5] + a1[12] + a1[9] / 2;
    sub_498030(a1);
    sub_497260(a1);
    if (v4 < 0)
        goto LABEL_32;
    v5 = v80;
    v6 = v74;
    v71 = v80;
    v70 = 23 * v80;
    v75 = v4 + 1;
    do
    {
        v7 = ((_BYTE)v5 + (_BYTE)v79) & 1;
        if (v7 > v6)
            goto LABEL_31;
        v8 = v7 + v79;
        v69 = 23 * (v7 + v79);
        v73 = (unsigned int)(v6 - v7 + 2) >> 1;
        do
        {
            v9 = (unsigned __int8*)sub_410580(v8, v5);
            if (v9)
            {
                v10 = (unsigned char)sub_57B500(v8, v5, 64);
                if (v10 != 255)
                {
                    v11 = v9[1];
                    v12 = v9[4];
                    if (byte_5D4594[12332 * v11 + 2692780] & 1)
                    {
                        if (v12 & 0x40)
                        {
                            if ((*(int*)& byte_5D4594[1217444] - v69 - 11) * (*(int*)& byte_5D4594[1217444] - v69 - 11)
                                + (*(int*)& byte_5D4594[1217448] - v70 - 11) * (*(int*)& byte_5D4594[1217448] - v70 - 11) < 3600)
                            {
                                v5 = v71;
                                v9[4] = v12 | 1;
                                goto LABEL_29;
                            }
                            v5 = v71;
                        }
                        if (v10)
                        {
                            if (v10 == 1)
                            {
                                sub_497C40(v8, v5, 6);
                            }
                            else
                            {
                                v16 = &byte_587000[v10 + 161764];
                                if (byte_587000[v10 + 161764] & 2)
                                    sub_497C40(v8, v5, 2);
                                if (*v16 & 1)
                                    sub_497C40(v8, v5, 1);
                                if (*v16 & 8)
                                    sub_497C40(v8, v5, 8);
                                if (*v16 & 4)
                                    sub_497C40(v8, v5, 4);
                            }
                        }
                        else
                        {
                            sub_497C40(v8, v5, 9);
                        }
                    }
                    else
                    {
                        v13 = v12 | 1;
                        v14 = v9[6];
                        v9[4] = v13;
                        if (23 * v14 <= *(int*)& byte_5D4594[1217448])
                            v15 = v13 & 0xFD;
                        else
                            v15 = v13 | 2;
                        v9[4] = v15;
                        if (byte_5D4594[12332 * v11 + 2692780] & 4)
                            sub_4754C0((int)v9);
                    }
                }
            }
            LABEL_29:
            v8 += 2;
            v17 = v73 == 1;
            v69 += 46;
            --v73;
        } while (!v17);
        v6 = v74;
        LABEL_31:
        ++v5;
        v17 = v75 == 1;
        v70 += 23;
        v71 = v5;
        --v75;
    } while (!v17);
    LABEL_32:
    sub_498110();
    v72 = 0;
    a3.field_0 = (double) * (int*)& byte_5D4594[1217444];
    a3.field_4 = (double) * (int*)& byte_5D4594[1217448];
    if (*(int*)& byte_5D4594[1217460] <= 0)
    {
        v51 = *(_DWORD*)& byte_5D4594[1217464];
    }
    else
    {
        do
        {
            v18 = 0;
            v19 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * v72);
            switch (*(unsigned __int8*)(v19 + 56))
            {
                case 0u:
                    v20 = 25736 * *(int*)(v19 + 40) / 75000;
                    a3.field_8 = (double)(int)(*(_DWORD*)& byte_5D4594[1217444] + sub_414BD0(6434 - v20));
                    a3.field_C = (double)(int)(*(_DWORD*)& byte_5D4594[1217448] + sub_414BD0(v20));
                    sub_4CA960((_DWORD*)(v19 + 24), *(_BYTE*)(v19 + 36), &a3, &a4);
                    v21 = 25736 * *(int*)(v19 + 44) / 75000;
                    a3.field_8 = (double)(int)(*(_DWORD*)& byte_5D4594[1217444] + sub_414BD0(6434 - v21));
                    a3.field_C = (double)(int)(*(_DWORD*)& byte_5D4594[1217448] + sub_414BD0(v21));
                    sub_4CA960((_DWORD*)(v19 + 24), *(_BYTE*)(v19 + 36), &a3, &v78);
                    v22 = sub_410580(*(_DWORD*)(v19 + 24), *(_DWORD*)(v19 + 28));
                    v23 = v22;
                    LOBYTE(v22) = *(_BYTE*)(v22 + 4);
                    *(_DWORD*)(v23 + 12) = 1;
                    v24 = v22 | 1;
                    *(_BYTE*)(v23 + 4) = v24;
                    if (v78.field_0 < (double)a4.field_0)
                        * (_BYTE*)(v23 + 4) = v24 | 2;
                    *(_BYTE*)(v23 + 3) |= *(_BYTE*)(v19 + 36);
                    v18 = *(_DWORD*)(v19 + 24) + (*(_DWORD*)(v19 + 28) << 8);
                    break;
                case 1u:
                    a4.field_0 = (double)(*(int*)& byte_5D4594[1217444]
                                          + sub_414C50(25736 * *(int*)(v19 + 40) / 75000 - 19302) * (a1[9] / 2) / 4096);
                    a4.field_4 = (double)a1[5];
                    v18 = 0;
                    v78.field_0 = (double)(*(int*)& byte_5D4594[1217444]
                                           + sub_414C50(25736 * *(int*)(v19 + 44) / 75000 - 19302) * (a1[9] / 2) / 4096);
                    v78.field_4 = (double)a1[5];
                    break;
                case 2u:
                    v25 = a1[9];
                    v26 = *(_DWORD*)& byte_5D4594[1217444]
                          - sub_414C50(25736 * *(int*)(v19 + 40) / 75000 - 6434) * (v25 / 2) / 4096;
                    v27 = a1[5] + v25 - 1;
                    v28 = a1[9];
                    a4.field_0 = (double)v26;
                    a4.field_4 = (double)v27;
                    v29 = sub_414C50(25736 * *(int*)(v19 + 44) / 75000 - 6434);
                    v76 = a1[5] + v28 - 1;
                    v78.field_0 = (double)(*(int*)& byte_5D4594[1217444] - v29 * (v28 / 2) / 4096);
                    v78.field_4 = (double)v76;
                    v18 = 0;
                    break;
                case 3u:
                    v32 = 25736 * *(_DWORD*)(v19 + 40);
                    a4.field_0 = (double)a1[4];
                    a4.field_4 = (double)(*(int*)& byte_5D4594[1217448] - sub_414C50(v32 / 75000 - 12868) * (a1[8] / 2) / 4096);
                    v33 = 25736 * *(_DWORD*)(v19 + 44);
                    v78.field_0 = (double)a1[4];
                    v18 = 0;
                    v78.field_4 = (double)(*(int*)& byte_5D4594[1217448] - sub_414C50(v33 / 75000 - 12868) * (a1[8] / 2) / 4096);
                    break;
                case 4u:
                    v30 = a1[8];
                    v68 = 25736 * *(int*)(v19 + 40) / 75000;
                    a4.field_0 = (double)(int)(a1[8] + a1[4] - 1);
                    a4.field_4 = (double)(int)(*(_DWORD*)& byte_5D4594[1217448] + sub_414C50(v68) * (v30 / 2) / 4096);
                    v31 = 25736 * *(int*)(v19 + 44) / 75000;
                    v78.field_0 = (double)(int)(a1[4] + v30 - 1);
                    v78.field_4 = (double)(int)(*(_DWORD*)& byte_5D4594[1217448] + sub_414C50(v31) * (a1[8] / 2) / 4096);
                    v18 = 0;
                    break;
                case 6u:
                    v34 = *(_DWORD*)(v19 + 20);
                    v35 = (double) * (int*)(v34 + 12);
                    *(_DWORD*)(v34 + 132) = 1;
                    v86.field_0 = v35;
                    v86.field_4 = (double) * (int*)(v34 + 16);
                    v86.field_8 = (double)(*(int*)(v34 + 12)
                                           + *(int*)& byte_587000[8 * *(unsigned __int8*)(v34 + 299) + 196184]);
                    v86.field_C = (double)(*(int*)(v34 + 16)
                                           + *(int*)& byte_587000[8 * *(unsigned __int8*)(v34 + 299) + 196188]);
                    v36 = 25736 * *(int*)(v19 + 40) / 75000;
                    a3.field_8 = (double)(*(int*)& byte_5D4594[1217444] + sub_414BD0(6434 - v36));
                    a3.field_C = (double)(*(int*)& byte_5D4594[1217448] + sub_414BD0(v36));
                    if (!sub_497180(&a3.field_0, &v86.field_0, &a4.field_0))
                        a4 = *(float2*)& v86.field_0;
                    v37 = 25736 * *(int*)(v19 + 44) / 75000;
                    a3.field_8 = (double)(*(int*)& byte_5D4594[1217444] + sub_414BD0(6434 - v37));
                    a3.field_C = (double)(*(int*)& byte_5D4594[1217448] + sub_414BD0(v37));
                    if (!sub_497180(&a3.field_0, &v86.field_0, &v78.field_0))
                        v78 = *(float2*)& v86.field_8;
                    v18 = *(_DWORD*)(v34 + 128);
                    break;
                case 7u:
                    *(_DWORD*)(*(_DWORD*)(v19 + 20) + 132) = 1;
                    v38 = *(_DWORD*)(v19 + 20);
                    v39 = *(_DWORD*)& byte_5D4594[1217444] - *(_DWORD*)(v38 + 12);
                    v40 = *(_DWORD*)(v38 + 16) - *(_DWORD*)& byte_5D4594[1217448];
                    nox_double2int(sqrt((double) * (int*)(v19 + 32)));
                    v83.field_0 = (double)(int)(v40 + *(int*)(*(_DWORD*)(v19 + 20) + 12));
                    v83.field_4 = (double)(int)(v39 + *(int*)(*(_DWORD*)(v19 + 20) + 16));
                    v83.field_8 = (double)(int)(*(int*)(*(_DWORD*)(v19 + 20) + 12) - v40);
                    v83.field_C = (double)(int)(*(int*)(*(_DWORD*)(v19 + 20) + 16) - v39);
                    v41 = 25736 * *(int*)(v19 + 40) / 75000;
                    a3.field_8 = (double)(int)(*(int*)& byte_5D4594[1217444] + sub_414BD0(6434 - v41));
                    a3.field_C = (double)(int)(*(int*)& byte_5D4594[1217448] + sub_414BD0(v41));
                    if (!sub_497180(&a3.field_0, &v83.field_0, &a4.field_0))
                        a4 = *(float2*)& v83;
                    v42 = 25736 * *(int*)(v19 + 44) / 75000;
                    a3.field_8 = (double)(int)(*(int*)& byte_5D4594[1217444] + sub_414BD0(6434 - v42));
                    a3.field_C = (double)(int)(*(int*)& byte_5D4594[1217448] + sub_414BD0(v42));
                    if (sub_497180(&a3.field_0, &v83.field_0, &v78.field_0))
                        goto LABEL_63;
                    goto LABEL_62;
                case 8u:
                case 9u:
                case 0xAu:
                case 0xBu:
                case 0xDu:
                case 0xEu:
                    *(_DWORD*)(*(_DWORD*)(v19 + 20) + 132) = 1;
                    switch (*(unsigned __int8*)(v19 + 56))
                    {
                        case 8u:
                            v83.field_0 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 64);
                            v83.field_4 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 68);
                            v83.field_8 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 72);
                            v43 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 76);
                            goto LABEL_58;
                        case 9u:
                            v83.field_0 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 64);
                            v44 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 68);
                            goto LABEL_57;
                        case 0xAu:
                            v83.field_0 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 88);
                            v83.field_4 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 92);
                            v83.field_8 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 72);
                            v43 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 76);
                            goto LABEL_58;
                        case 0xBu:
                            v83.field_0 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 88);
                            v44 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 92);
                            goto LABEL_57;
                        case 0xDu:
                            v83.field_0 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 64);
                            v83.field_4 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 68);
                            v83.field_8 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 88);
                            v43 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 92);
                            goto LABEL_58;
                        case 0xEu:
                            v83.field_0 = (double) * (int*)(*(_DWORD*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 72);
                            v44 = (double) * (int*)(*(_DWORD*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 76);
                        LABEL_57:
                            v83.field_4 = v44;
                            v83.field_8 = (double) * (int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 80);
                            v43 = (double) * (int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 84);
                        LABEL_58:
                            v83.field_C = v43;
                            break;
                        default:
                            break;
                    }
                    v45 = 25736 * *(int*)(v19 + 40) / 75000;
                    a3.field_8 = (double)(int)(*(int*)& byte_5D4594[1217444] + sub_414BD0(6434 - v45));
                    a3.field_C = (double)(int)(*(int*)& byte_5D4594[1217448] + sub_414BD0(v45));
                    if (!sub_497180(&a3.field_0, &v83.field_0, &a4.field_0))
                        a4 = *(float2*)& v83.field_0;
                    v46 = 25736 * *(int*)(v19 + 44) / 75000;
                    a3.field_8 = (double)(int)(*(int*)& byte_5D4594[1217444] + sub_414BD0(6434 - v46));
                    a3.field_C = (double)(int)(*(int*)& byte_5D4594[1217448] + sub_414BD0(v46));
                    if (!sub_497180(&a3.field_0, &v83.field_0, &v78.field_0))
                        LABEL_62:
                        v78 = *(float2*)& v83.field_8;
                LABEL_63:
                    v18 = *(_DWORD*)(*(_DWORD*)(v19 + 20) + 128);
                    break;
                default:
                    break;
            }
            a1a.field_0 = *a1 - a1[4] + nox_float2int(a4.field_0);
            a1a.field_4 = a1[1] - a1[5] + nox_float2int(a4.field_4);
            a2.field_0 = *a1 - a1[4] + nox_float2int(v78.field_0);
            a2.field_4 = a1[1] - a1[5] + nox_float2int(v78.field_4);
            //dprintf("%d\t%d\t%d %d %d %d", v72, *(unsigned __int8 *)(v19 + 56), a1a.field_0, a1a.field_4, a2.field_0, a2.field_4);
            if (sub_57BA30(&a1a, &a2, (int4*)a1))
            {
                v47 = *(_DWORD*)& byte_5D4594[1217464];
                v48 = a1a.field_4;
                *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[1217464] + 1203876] = a1a.field_0;
                v49 = a2.field_0;
                *(_DWORD*)& byte_5D4594[8 * v47 + 1203880] = v48;
                v50 = a2.field_4;
                *(_DWORD*)& byte_5D4594[4 * v47 + 1213348] = v18;
                byte_5D4594[v47++ + 1212324] = *(_BYTE*)(v19 + 56);
                *(_DWORD*)& byte_5D4594[1217464] = v47;
                *(_DWORD*)& byte_5D4594[8 * v47 + 1203876] = v49;
                *(_DWORD*)& byte_5D4594[8 * v47 + 1203880] = v50;
                *(_DWORD*)& byte_5D4594[4 * v47 + 1213348] = v18;
                byte_5D4594[v47 + 1212324] = *(_BYTE*)(v19 + 56);
                v51 = v47 + 1;
                *(_DWORD*)& byte_5D4594[1217464] = v51;
            }
            else
            {
                v51 = *(_DWORD*)& byte_5D4594[1217464];
            }
            ++v72;
        } while (v72 < *(int*)& byte_5D4594[1217460]);
    }
    v52 = v51 - 1;
    v53 = 0;
    *(_DWORD*)& byte_5D4594[1217464] = v52;
    v54 = v52 - 1;
    while (v53 < v52)
    {
        v55 = byte_5D4594[v54 + 1212324];
        if (v55)
        {
            v56 = byte_5D4594[v53 + 1212324];
            if (!v56)
                goto LABEL_89;
            if (v56 != v55)
                goto LABEL_99;
            if (*(_DWORD*)& byte_5D4594[4 * v53 + 1213348] != *(_DWORD*)& byte_5D4594[4 * v54 + 1213348])
            {
                v57 = *(_DWORD*)& byte_5D4594[8 * v54 + 1203876];
                v58 = *(_DWORD*)& byte_5D4594[8 * v53 + 1203876] - v57;
                if (v58 < 0)
                {
                    v59 = v57 - *(_DWORD*)& byte_5D4594[8 * v53 + 1203876];
                    LABEL_83:
                    v61 = *(_DWORD*)& byte_5D4594[8 * v54 + 1203880];
                    if (*(int*)& byte_5D4594[8 * v53 + 1203880] - v61 >= 0)
                        v62 = *(_DWORD*)& byte_5D4594[8 * v53 + 1203880] - v61;
                    else
                        v62 = v61 - *(_DWORD*)& byte_5D4594[8 * v53 + 1203880];
                    if (v59 <= 4 && v62 <= 4)
                        goto LABEL_100;
                    LABEL_99:
                    byte_5D4594[v54 + 1212324] = 12;
                    goto LABEL_100;
                }
                LABEL_82:
                v59 = v58;
                goto LABEL_83;
            }
        }
        else
        {
            if (byte_5D4594[v53 + 1212324])
            {
                LABEL_89:
                if (v55 == 6 || byte_5D4594[v53 + 1212324] == 6)
                {
                    v63 = *(_DWORD*)& byte_5D4594[8 * v54 + 1203876];
                    v64 = *(int*)& byte_5D4594[8 * v53 + 1203876] - v63 >= 0 ? *(_DWORD*)& byte_5D4594[8 * v53 + 1203876] - v63 : v63 - *(_DWORD*)& byte_5D4594[8 * v53 + 1203876];
                    v65 = *(_DWORD*)& byte_5D4594[8 * v54 + 1203880];
                    v66 = *(int*)& byte_5D4594[8 * v53 + 1203880] - v65 >= 0 ? *(_DWORD*)& byte_5D4594[8 * v53 + 1203880] - v65 : v65 - *(_DWORD*)& byte_5D4594[8 * v53 + 1203880];
                    if (v64 <= 4 && v66 <= 4)
                        goto LABEL_100;
                }
                goto LABEL_99;
            }
            if (*(_DWORD*)& byte_5D4594[4 * v54 + 1213348] != *(_DWORD*)& byte_5D4594[4 * v53 + 1213348])
            {
                v60 = *(_DWORD*)& byte_5D4594[8 * v54 + 1203876];
                v58 = *(_DWORD*)& byte_5D4594[8 * v53 + 1203876] - v60;
                if (v58 < 0)
                {
                    v59 = v60 - *(_DWORD*)& byte_5D4594[8 * v53 + 1203876];
                    goto LABEL_83;
                }
                goto LABEL_82;
            }
        }
        LABEL_100:
        v54 = v53++;
    }
    sub_4989A0();
    return sub_4C52E0((int*)& byte_5D4594[1203876], *(int*)& byte_5D4594[1217464]);
}

//----- (00497180) --------------------------------------------------------
int __cdecl sub_497180(float* a1, float* a2, float* a3)
{
    double v3; // st7
    double v4; // st6
    float v5; // ecx
    double v6; // st5
    float v7; // eax
    float v8; // eax
    int result; // eax
    float v10; // [esp+4h] [ebp-1Ch]
    float v11; // [esp+8h] [ebp-18h]
    float v12; // [esp+14h] [ebp-Ch]

    if (*a1 >= (double)a1[2])
    {
        v3 = a1[2];
        v4 = *a1;
    }
    else
    {
        v3 = *a1;
        v4 = a1[2];
    }
    if (a1[1] >= (double)a1[3])
    {
        v5 = a1[1];
        v12 = a1[3];
    }
    else
    {
        v5 = a1[3];
        v12 = a1[1];
    }
    if (*a2 >= (double)a2[2])
    {
        v6 = a2[2];
        v7 = *a2;
    }
    else
    {
        v6 = *a2;
        v7 = a2[2];
    }
    v11 = v7;
    if (a2[1] >= (double)a2[3])
    {
        v10 = a2[3];
        v8 = a2[1];
    }
    else
    {
        v10 = a2[1];
        v8 = a2[3];
    }
    if (v6 > v4 || v11 < v3 || v10 >(double)v5 || v8 < (double)v12)
        result = 0;
    else
        result = sub_4278B0(a1, a2, a3);
    return result;
}

//----- (00497260) --------------------------------------------------------
int __cdecl sub_497260(int* a1)
{
    int result; // eax
    int v2; // esi
    int* v3; // edi
    double v4; // st7
    double v5; // st6
    int v6; // eax
    double v7; // st7
    double v8; // st6
    double v9; // st7
    double v10; // st6
    float v11; // [esp+Ch] [ebp-Ch]
    float v12; // [esp+Ch] [ebp-Ch]
    float v13; // [esp+Ch] [ebp-Ch]
    float v14; // [esp+10h] [ebp-8h]
    float v15; // [esp+10h] [ebp-8h]
    float v16; // [esp+10h] [ebp-8h]
    float v17; // [esp+14h] [ebp-4h]
    float v18; // [esp+14h] [ebp-4h]
    float v19; // [esp+14h] [ebp-4h]
    float v20; // [esp+1Ch] [ebp+4h]
    float v21; // [esp+1Ch] [ebp+4h]
    float v22; // [esp+1Ch] [ebp+4h]

    result = sub_45A030();
    v2 = result;
    if (result)
    {
        v3 = a1;
        do
        {
            *(_DWORD*)(v2 + 132) = 0;
            if (!sub_4356C0(v2, 0))
            {
                if (*(char*)(v2 + 112) >= 0)
                {
                    v6 = *(_DWORD*)(v2 + 44);
                    if (v6 == 2)
                    {
                        v7 = (double) * (int*)(v2 + 12);
                        v8 = (double) * (int*)(v2 + 16);
                        if (v7 - *(float*)(v2 + 48) < (double)(v3[4] + v3[8]))
                        {
                            v21 = v7;
                            v15 = v21 + *(float*)(v2 + 48);
                            if ((double)v3[4] < v15)
                            {
                                v12 = v8 - *(float*)(v2 + 48);
                                if ((double)(v3[5] + v3[9]) > v12)
                                {
                                    v18 = v8 + *(float*)(v2 + 48);
                                    if ((double)v3[5] < v18)
                                        sub_497650(*(float*)& v2);
                                }
                            }
                        }
                    }
                    else if (v6 == 3)
                    {
                        v9 = (double) * (int*)(v2 + 12);
                        v10 = (double) * (int*)(v2 + 16);
                        if (v9 + *(float*)(v2 + 72) < (double)(v3[4] + v3[8]))
                        {
                            v22 = v9;
                            v16 = v22 + *(float*)(v2 + 80);
                            if ((double)v3[4] < v16)
                            {
                                v13 = v10 + *(float*)(v2 + 68);
                                if ((double)(v3[5] + v3[9]) > v13)
                                {
                                    v19 = v10 + *(float*)(v2 + 92);
                                    if ((double)v3[5] < v19)
                                        sub_4977C0(v2);
                                }
                            }
                        }
                    }
                }
                else
                {
                    v4 = (double) * (int*)(v2 + 12);
                    v5 = (double) * (int*)(v2 + 16);
                    if (v4 - 32.0 < (double)(v3[4] + v3[8]))
                    {
                        v20 = v4;
                        v14 = v20 + 32.0;
                        if ((double)v3[4] < v14)
                        {
                            v11 = v5 - 32.0;
                            if ((double)(v3[5] + v3[9]) > v11)
                            {
                                v17 = v5 + 32.0;
                                if ((double)v3[5] < v17)
                                    sub_4974B0(v2);
                            }
                        }
                    }
                }
            }
            result = sub_45A040(v2);
            v2 = result;
        } while (result);
    }
    return result;
}

//----- (004974B0) --------------------------------------------------------
void __cdecl sub_4974B0(int a1)
{
    int v1; // edi
    int v2; // esi
    int v3; // ecx
    double v4; // st7
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // eax
    int v12; // ecx
    int v13; // eax
    float v14; // [esp+0h] [ebp-14h]
    int v15; // [esp+18h] [ebp+4h]

    v1 = a1;
    if (!(*(_BYTE*)(a1 + 116) & 4))
    {
        v2 = sub_4CADD0();
        *(_BYTE*)(v2 + 48) = 1;
        *(_BYTE*)(v2 + 56) = 6;
        *(_DWORD*)(v2 + 20) = a1;
        v3 = 8 * *(unsigned __int8*)(a1 + 299);
        v4 = (double)(int)(*(_DWORD*)& byte_5D4594[1217444] - *(int*)& byte_587000[v3 + 196184] / 2 - *(_DWORD*)(a1 + 12));
        v15 = *(_DWORD*)& byte_5D4594[1217448] - *(int*)& byte_587000[v3 + 196188] / 2 - *(_DWORD*)(a1 + 16);
        v14 = (double)v15 * (double)v15 + v4 * v4;
        *(_DWORD*)(v2 + 32) = nox_float2int(v14);
        v5 = sub_4CA8B0(
                *(_DWORD*)(v1 + 16) - *(_DWORD*)& byte_5D4594[1217448],
                *(_DWORD*)(v1 + 12) - *(_DWORD*)& byte_5D4594[1217444]);
        *(_DWORD*)(v2 + 40) = v5;
        if (v5 < 0)
        {
            do
            {
                v6 = *(_DWORD*)(v2 + 40);
                *(_DWORD*)(v2 + 40) = v6 + 75000;
            } while (v6 + 75000 < 0);
        }
        if (*(int*)(v2 + 40) >= 75000)
        {
            do
            {
                v7 = *(_DWORD*)(v2 + 40) - 75000;
                *(_DWORD*)(v2 + 40) = v7;
            } while (v7 >= 75000);
        }
        v8 = sub_4CA8B0(
                *(_DWORD*)(v1 + 16)
                + *(int*)& byte_587000[8 * *(unsigned __int8*)(v1 + 299) + 196188]
                - *(_DWORD*)& byte_5D4594[1217448],
                *(_DWORD*)(v1 + 12)
                + *(int*)& byte_587000[8 * *(unsigned __int8*)(v1 + 299) + 196184]
                - *(_DWORD*)& byte_5D4594[1217444]);
        *(_DWORD*)(v2 + 44) = v8;
        if (v8 < 0)
        {
            do
            {
                v9 = *(_DWORD*)(v2 + 44);
                *(_DWORD*)(v2 + 44) = v9 + 75000;
            } while (v9 + 75000 < 0);
        }
        if (*(int*)(v2 + 44) >= 75000)
        {
            do
            {
                v10 = *(_DWORD*)(v2 + 44) - 75000;
                *(_DWORD*)(v2 + 44) = v10;
            } while (v10 >= 75000);
        }
        v11 = *(_DWORD*)(v2 + 44);
        v12 = *(_DWORD*)(v2 + 40);
        if (v11 < v12)
        {
            *(_DWORD*)(v2 + 40) = v11;
            *(_DWORD*)(v2 + 44) = v12;
        }
        if ((double)(int)(*(_DWORD*)(v2 + 44) - *(_DWORD*)(v2 + 40)) >= 37500.0)
        {
            v13 = sub_4CAED0(v2);
            *(_DWORD*)(v13 + 40) = 0;
            *(_DWORD*)(v13 + 44) = *(_DWORD*)(v2 + 40);
            *(_DWORD*)(v2 + 40) = *(_DWORD*)(v2 + 44);
            *(_DWORD*)(v2 + 44) = 74999;
            sub_4CAE90(v13);
        }
        sub_4CAE90(v2);
    }
}

//----- (00497650) --------------------------------------------------------
int __cdecl sub_497650(float a1)
{
    int v1; // eax
    float v2; // edi
    _DWORD* v3; // esi
    int v4; // ecx
    double v5; // st7
    int v6; // eax
    int v7; // ebx
    int v8; // eax
    int v9; // ebp
    int v10; // eax
    int v11; // eax
    int v12; // ecx
    int v13; // edi
    int v14; // ebp
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // ecx
    int v19; // eax
    float v21; // [esp+0h] [ebp-1Ch]
    int v22; // [esp+0h] [ebp-1Ch]
    float v23; // [esp+14h] [ebp-8h]
    float v24; // [esp+20h] [ebp+4h]

    v1 = sub_4CADD0();
    v2 = a1;
    v3 = (_DWORD*)v1;
    *(_BYTE*)(v1 + 48) = 1;
    *(_BYTE*)(v1 + 56) = 7;
    *(float*)(v1 + 20) = a1;
    v4 = *(_DWORD*)(LODWORD(a1) + 16);
    v24 = (double)(int)(*(_DWORD*)(LODWORD(a1) + 12) - *(_DWORD*)& byte_5D4594[1217444]);
    v5 = (double)(int)(v4 - *(_DWORD*)& byte_5D4594[1217448]);
    v23 = v5;
    v21 = v5 * v23 + v24 * v24;
    v6 = nox_float2int(v21);
    v3[8] = v6;
    v7 = (__int64)sqrt((double)v6);
    v22 = nox_float2int(v24);
    v8 = nox_float2int(v23);
    v9 = sub_4CA8B0(v8, v22);
    v10 = nox_float2int(*(float*)(LODWORD(v2) + 48));
    v11 = sub_4CA8B0(v10, v7);
    v3[10] = v11 + v9;
    if (v11 + v9 < 0)
    {
        do
        {
            v12 = v3[10];
            v3[10] = v12 + 75000;
        } while (v12 + 75000 < 0);
    }
    if (v3[10] >= 75000)
    {
        do
        {
            v13 = v3[10] - 75000;
            v3[10] = v13;
        } while (v13 >= 75000);
    }
    v14 = v9 - v11;
    v3[11] = v14;
    if (v14 < 0)
    {
        do
        {
            v15 = v3[11];
            v3[11] = v15 + 75000;
        } while (v15 + 75000 < 0);
    }
    if (v3[11] >= 75000)
    {
        do
        {
            v16 = v3[11] - 75000;
            v3[11] = v16;
        } while (v16 >= 75000);
    }
    v17 = v3[11];
    v18 = v3[10];
    if (v17 < v18)
    {
        v3[10] = v17;
        v3[11] = v18;
    }
    if ((double)(v3[11] - v3[10]) >= 37500.0)
    {
        v19 = sub_4CAED0((int)v3);
        *(_DWORD*)(v19 + 40) = 0;
        *(_DWORD*)(v19 + 44) = v3[10];
        v3[10] = v3[11];
        v3[11] = 74999;
        sub_4CAE90(v19);
    }
    return sub_4CAE90((int)v3);
}

//----- (004977C0) --------------------------------------------------------
int __cdecl sub_4977C0(int a1)
{
    int v1; // esi
    double v2; // st7
    double v3; // st6
    int v4; // eax
    int v5; // edi
    int v6; // eax
    int v7; // ebp
    int v8; // eax
    int v9; // ebx
    int v10; // eax
    int result; // eax
    double v12; // st7
    int v13; // eax
    double v14; // st7
    int v15; // eax
    double v16; // st7
    int v17; // eax
    double v18; // st7
    int v19; // eax
    double v20; // st7
    int v21; // eax
    double v22; // st7
    int v23; // eax
    float v24; // [esp+0h] [ebp-40h]
    float v25; // [esp+0h] [ebp-40h]
    float v26; // [esp+0h] [ebp-40h]
    float v27; // [esp+0h] [ebp-40h]
    float v28; // [esp+0h] [ebp-40h]
    float v29; // [esp+0h] [ebp-40h]
    int v30; // [esp+4h] [ebp-3Ch]
    int v31; // [esp+4h] [ebp-3Ch]
    int v32; // [esp+4h] [ebp-3Ch]
    int v33; // [esp+4h] [ebp-3Ch]
    float v34; // [esp+1Ch] [ebp-24h]
    float v35; // [esp+1Ch] [ebp-24h]
    float v36; // [esp+1Ch] [ebp-24h]
    float v37; // [esp+1Ch] [ebp-24h]
    float v38[8]; // [esp+20h] [ebp-20h]
    float v39; // [esp+44h] [ebp+4h]
    int v40; // [esp+44h] [ebp+4h]

    v1 = a1;
    v2 = (double) * (int*)(a1 + 12);
    v38[0] = v2 + *(float*)(a1 + 64);
    v3 = (double) * (int*)(a1 + 16);
    v39 = v3;
    v38[1] = v3 + *(float*)(v1 + 68);
    v38[2] = v2 + *(float*)(v1 + 72);
    v38[3] = v39 + *(float*)(v1 + 76);
    v38[4] = v2 + *(float*)(v1 + 80);
    v38[5] = v39 + *(float*)(v1 + 84);
    v38[6] = v2 + *(float*)(v1 + 88);
    v38[7] = v39 + *(float*)(v1 + 92);
    v30 = nox_float2int(v38[0]) - *(_DWORD*)& byte_5D4594[1217444];
    v4 = nox_float2int(v38[1]);
    v5 = sub_4CA8B0(v4 - *(_DWORD*)& byte_5D4594[1217448], v30);
    v31 = nox_float2int(v38[2]) - *(_DWORD*)& byte_5D4594[1217444];
    v6 = nox_float2int(v38[3]);
    v7 = sub_4CA8B0(v6 - *(_DWORD*)& byte_5D4594[1217448], v31);
    v32 = nox_float2int(v38[4]) - *(_DWORD*)& byte_5D4594[1217444];
    v8 = nox_float2int(v38[5]);
    v9 = sub_4CA8B0(v8 - *(_DWORD*)& byte_5D4594[1217448], v32);
    v33 = nox_float2int(v38[6]) - *(_DWORD*)& byte_5D4594[1217444];
    v10 = nox_float2int(v38[7]);
    v40 = sub_4CA8B0(v10 - *(_DWORD*)& byte_5D4594[1217448], v33);
    result = (unsigned __int8)sub_497B80(v38, (int*)& byte_5D4594[1217444]) - 1;
    switch (result)
    {
        case 0:
            v35 = (v38[5] + v38[1]) * 0.5;
            v14 = (v38[4] + v38[0]) * 0.5 - (double) * (int*)& byte_5D4594[1217444];
            v25 = (v35 - (double) * (int*)& byte_5D4594[1217448]) * (v35 - (double) * (int*)& byte_5D4594[1217448]) + v14 * v14;
            v15 = nox_float2int(v25);
            result = sub_497F60(v5, v9, 9, v15, v1);
            break;
        case 1:
            v37 = (v38[7] + v38[3]) * 0.5;
            v18 = (v38[6] + v38[2]) * 0.5 - (double) * (int*)& byte_5D4594[1217444];
            v27 = (v37 - (double) * (int*)& byte_5D4594[1217448]) * (v37 - (double) * (int*)& byte_5D4594[1217448]) + v18 * v18;
            v19 = nox_float2int(v27);
            result = sub_497F60(v40, v7, 10, v19, v1);
            break;
        case 3:
            v34 = (v38[3] + v38[1]) * 0.5;
            v12 = (v38[2] + v38[0]) * 0.5 - (double) * (int*)& byte_5D4594[1217444];
            v24 = (v34 - (double) * (int*)& byte_5D4594[1217448]) * (v34 - (double) * (int*)& byte_5D4594[1217448]) + v12 * v12;
            v13 = nox_float2int(v24);
            result = sub_497F60(v5, v7, 8, v13, v1);
            break;
        case 4:
        case 9:
            v22 = (double)(int)(*(_DWORD*)(v1 + 12) - *(_DWORD*)& byte_5D4594[1217444]);
            v29 = (double)(int)(*(_DWORD*)(v1 + 16) - *(_DWORD*)& byte_5D4594[1217448])
                  * (double)(int)(*(_DWORD*)(v1 + 16) - *(_DWORD*)& byte_5D4594[1217448])
                  + v22 * v22;
            v23 = nox_float2int(v29);
            result = sub_497F60(v7, v9, 14, v23, v1);
            break;
        case 5:
        case 8:
            v20 = (double)(int)(*(_DWORD*)(v1 + 12) - *(_DWORD*)& byte_5D4594[1217444]);
            v28 = (double)(int)(*(_DWORD*)(v1 + 16) - *(_DWORD*)& byte_5D4594[1217448])
                  * (double)(int)(*(_DWORD*)(v1 + 16) - *(_DWORD*)& byte_5D4594[1217448])
                  + v20 * v20;
            v21 = nox_float2int(v28);
            result = sub_497F60(v5, v40, 13, v21, v1);
            break;
        case 7:
            v36 = (v38[7] + v38[5]) * 0.5;
            v16 = (v38[6] + v38[4]) * 0.5 - (double) * (int*)& byte_5D4594[1217444];
            v26 = (v36 - (double) * (int*)& byte_5D4594[1217448]) * (v36 - (double) * (int*)& byte_5D4594[1217448]) + v16 * v16;
            v17 = nox_float2int(v26);
            result = sub_497F60(v40, v9, 11, v17, v1);
            break;
        default:
            return result;
    }
    return result;
}

//----- (00497B80) --------------------------------------------------------
char __cdecl sub_497B80(float* a1, int* a2)
{
    int* v2; // eax
    float* v3; // ecx
    char v4; // dl
    double v5; // st7
    float v7; // [esp+0h] [ebp-4h]
    float v8; // [esp+8h] [ebp+4h]
    float v9; // [esp+Ch] [ebp+8h]

    v2 = a2;
    v3 = a1;
    v4 = 0;
    v9 = (double)* a2;
    v7 = (double)v2[1];
    v5 = (a1[5] + a1[4] - v9 - v7) * 0.70709997;
    v8 = (a1[1] + *a1 - v9 - v7) * 0.70709997;
    if ((v3[1] - *v3 + v9 - v7) * 0.70709997 <= 0.0)
    {
        if ((v3[3] - v3[2] + v9 - v7) * 0.70709997 < 0.0)
            v4 = 2;
    }
    else
    {
        v4 = 1;
    }
    if (v5 < 0.0)
        return v4 | 8;
    if (v8 > 0.0)
        v4 |= 4u;
    return v4;
}

//----- (00497C40) --------------------------------------------------------
int __cdecl sub_497C40(int a1, int a2, char a3)
{
    int v3; // edi
    int v4; // ebp
    int v5; // ebx
    int v6; // esi
    int v7; // ecx
    int v8; // eax
    int v9; // edi
    int v10; // ecx
    int v11; // eax
    int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // ecx
    int v19; // eax
    int v21; // [esp+10h] [ebp-10h]
    int v22; // [esp+14h] [ebp-Ch]
    int v23; // [esp+18h] [ebp-8h]
    int v24; // [esp+1Ch] [ebp-4h]

    v21 = 23 * a1;
    v22 = 23 * a2;
    v3 = 23 * a1 + nox_float2int(11.5);
    v4 = 23 * a2 + nox_float2int(11.5);
    v5 = sub_4CADD0();
    *(_DWORD*)(v5 + 24) = a1;
    *(_BYTE*)(v5 + 36) = a3;
    *(_DWORD*)(v5 + 28) = a2;
    *(_BYTE*)(v5 + 48) = 1;
    *(_BYTE*)(v5 + 56) = 0;
    switch (a3)
    {
        case 1:
            v6 = v3 - *(_DWORD*)& byte_5D4594[1217444] + nox_float2int(5.75);
            v7 = v4 - *(_DWORD*)& byte_5D4594[1217448] - nox_float2int(5.75);
            v8 = v3;
            v9 = 23 * a2;
            v23 = v21 + 23;
            break;
        case 2:
            v6 = v3 - *(_DWORD*)& byte_5D4594[1217444] - nox_float2int(5.75);
            v7 = v4 - *(_DWORD*)& byte_5D4594[1217448] - nox_float2int(5.75);
            v8 = v3;
            v9 = 23 * a2;
            v23 = 23 * a1;
            break;
        case 4:
            v6 = v3 - *(_DWORD*)& byte_5D4594[1217444] + nox_float2int(5.75);
            v10 = nox_float2int(5.75);
            v8 = v3;
            v7 = v4 - *(_DWORD*)& byte_5D4594[1217448] + v10;
            v23 = v21 + 23;
            v9 = v22 + 23;
            break;
        case 6:
            v8 = 23 * a1;
            v7 = v4 - *(_DWORD*)& byte_5D4594[1217448];
            v4 = 23 * a2;
            v6 = v3 - *(_DWORD*)& byte_5D4594[1217444];
            v23 = v21 + 23;
            v9 = v22 + 23;
            break;
        case 8:
            v6 = v3 - *(_DWORD*)& byte_5D4594[1217444] - nox_float2int(5.75);
            v23 = 23 * a1;
            v7 = v4 - *(_DWORD*)& byte_5D4594[1217448] + nox_float2int(5.75);
            v8 = v3;
            v9 = v22 + 23;
            break;
        case 9:
            v6 = v3 - *(_DWORD*)& byte_5D4594[1217444];
            v7 = v4 - *(_DWORD*)& byte_5D4594[1217448];
            v4 = 23 * a2;
            v8 = v21 + 23;
            v23 = 23 * a1;
            v9 = v22 + 23;
            break;
        default:
            v6 = a1;
            v7 = a1;
            v4 = v24;
            v8 = v23;
            v9 = v24;
            break;
    }
    *(_DWORD*)(v5 + 32) = v6 * v6 + v7 * v7;
    v11 = sub_4CA8B0(v4 - *(_DWORD*)& byte_5D4594[1217448], v8 - *(_DWORD*)& byte_5D4594[1217444]);
    *(_DWORD*)(v5 + 40) = v11;
    if (v11 < 0)
    {
        do
        {
            v12 = *(_DWORD*)(v5 + 40);
            *(_DWORD*)(v5 + 40) = v12 + 75000;
        } while (v12 + 75000 < 0);
    }
    if (*(_DWORD*)(v5 + 40) >= 75000)
    {
        do
        {
            v13 = *(_DWORD*)(v5 + 40) - 75000;
            *(_DWORD*)(v5 + 40) = v13;
        } while (v13 >= 75000);
    }
    v14 = sub_4CA8B0(v9 - *(_DWORD*)& byte_5D4594[1217448], v23 - *(_DWORD*)& byte_5D4594[1217444]);
    *(_DWORD*)(v5 + 44) = v14;
    if (v14 < 0)
    {
        do
        {
            v15 = *(_DWORD*)(v5 + 44);
            *(_DWORD*)(v5 + 44) = v15 + 75000;
        } while (v15 + 75000 < 0);
    }
    if (*(_DWORD*)(v5 + 44) >= 75000)
    {
        do
        {
            v16 = *(_DWORD*)(v5 + 44) - 75000;
            *(_DWORD*)(v5 + 44) = v16;
        } while (v16 >= 75000);
    }
    v17 = *(_DWORD*)(v5 + 44);
    v18 = *(_DWORD*)(v5 + 40);
    if (v17 < v18)
    {
        *(_DWORD*)(v5 + 40) = v17;
        *(_DWORD*)(v5 + 44) = v18;
    }
    if (*(_DWORD*)(v5 + 44) - *(_DWORD*)(v5 + 40) >= 37500)
    {
        v19 = sub_4CAED0(v5);
        *(_DWORD*)(v19 + 40) = 0;
        *(_DWORD*)(v19 + 44) = *(_DWORD*)(v5 + 40);
        *(_DWORD*)(v5 + 40) = *(_DWORD*)(v5 + 44);
        *(_DWORD*)(v5 + 44) = 74999;
        sub_4CAE90(v19);
    }
    return sub_4CAE90(v5);
}
// 497E2E: variable 'v24' is possibly undefined
// 497E32: variable 'v23' is possibly undefined

//----- (00497F60) --------------------------------------------------------
int __cdecl sub_497F60(int a1, int a2, char a3, int a4, int a5)
{
    int v5; // esi
    int v6; // ecx
    int v7; // edx
    int v8; // edx
    int v9; // edx
    int v10; // eax

    v5 = sub_4CADD0();
    *(_BYTE*)(v5 + 56) = a3;
    *(_DWORD*)(v5 + 32) = a4;
    *(_BYTE*)(v5 + 48) = 1;
    *(_DWORD*)(v5 + 20) = a5;
    if (a2 >= a1)
    {
        *(_DWORD*)(v5 + 40) = a1;
        *(_DWORD*)(v5 + 44) = a2;
    }
    else
    {
        *(_DWORD*)(v5 + 40) = a2;
        *(_DWORD*)(v5 + 44) = a1;
    }
    if (*(int*)(v5 + 40) < 0)
    {
        do
        {
            v6 = *(_DWORD*)(v5 + 40);
            *(_DWORD*)(v5 + 40) = v6 + 75000;
        } while (v6 + 75000 < 0);
    }
    if (*(_DWORD*)(v5 + 40) >= 75000)
    {
        do
        {
            v7 = *(_DWORD*)(v5 + 40) - 75000;
            *(_DWORD*)(v5 + 40) = v7;
        } while (v7 >= 75000);
    }
    if (*(int*)(v5 + 44) < 0)
    {
        do
        {
            v8 = *(_DWORD*)(v5 + 44);
            *(_DWORD*)(v5 + 44) = v8 + 75000;
        } while (v8 + 75000 < 0);
    }
    if (*(_DWORD*)(v5 + 44) >= 75000)
    {
        do
        {
            v9 = *(_DWORD*)(v5 + 44) - 75000;
            *(_DWORD*)(v5 + 44) = v9;
        } while (v9 >= 75000);
    }
    if (*(int*)(v5 + 44) - *(int*)(v5 + 40) >= 37500)
    {
        v10 = sub_4CAED0(v5);
        *(_DWORD*)(v10 + 40) = 0;
        *(_DWORD*)(v10 + 44) = *(_DWORD*)(v5 + 40);
        *(_DWORD*)(v5 + 40) = *(_DWORD*)(v5 + 44);
        *(_DWORD*)(v5 + 44) = 74999;
        sub_4CAE90(v10);
    }
    return sub_4CAE90(v5);
}

//----- (00498030) --------------------------------------------------------
int __cdecl sub_498030(_DWORD* a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // ebx
    int v4; // ebp
    int v5; // edi
    int v6; // ebx
    int v7; // esi
    int v9; // [esp+14h] [ebp+4h]

    v1 = a1[4];
    v2 = a1[5];
    v3 = a1[8] + v1;
    v4 = a1[9] + v2;
    v9 = sub_4CA8B0(v2 - *(_DWORD*)& byte_5D4594[1217448], v1 - *(_DWORD*)& byte_5D4594[1217444]);
    v5 = sub_4CA8B0(v2 - *(_DWORD*)& byte_5D4594[1217448], v3 - *(_DWORD*)& byte_5D4594[1217444]);
    v6 = sub_4CA8B0(v4 - *(_DWORD*)& byte_5D4594[1217448], v3 - *(_DWORD*)& byte_5D4594[1217444]);
    v7 = sub_4CA8B0(v4 - *(_DWORD*)& byte_5D4594[1217448], v1 - *(_DWORD*)& byte_5D4594[1217444]);
    sub_497F60(v9, v5, 1, 0x7FFFFFFF, 0);
    sub_497F60(v5, v6, 4, 0x7FFFFFFF, 0);
    sub_497F60(v6, v7, 2, 0x7FFFFFFF, 0);
    return sub_497F60(v7, v9, 3, 0x7FFFFFFF, 0);
}

//----- (00498110) --------------------------------------------------------
int sub_498110()
{
    int result; // eax

    for (result = sub_4CAEB0(); result; result = sub_4CAEB0())
    {
        sub_498130(result);
    }
    return result;
}

//----- (00498130) --------------------------------------------------------
int __cdecl sub_498130(int a1)
{
    int i; // ebx
    int v2; // esi

    for (i = sub_498290(a1); i < *(int*)& byte_5D4594[1217460]; ++i)
    {
        v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * i);
        if (*(int*)(v2 + 40) > * (int*)(a1 + 44))
            break;
        sub_498380(a1, *(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * i));
        if (!*(_BYTE*)(a1 + 48) || *(int*)(a1 + 44) - *(int*)(a1 + 40) < 0)
            return sub_4CAE40(a1);
        if (!*(_BYTE*)(v2 + 48) || *(int*)(v2 + 44) - *(int*)(v2 + 40) < 0)
        {
            if (sub_4982E0(v2) <= i)
                --i;
            sub_4CAE40(v2);
        }
    }
    return sub_4981D0(a1);
}

//----- (004981D0) --------------------------------------------------------
int __cdecl sub_4981D0(int a1)
{
    int v1; // ecx
    int v2; // esi
    int v3; // eax

    v1 = *(_DWORD*)& byte_5D4594[1217460] - 1;
    v2 = 0;
    while (v2 <= v1)
    {
        v3 = (v1 + v2) / 2;
        if (*(int*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * v3) + 40) >= *(int*)(a1 + 40))
            v1 = v3 - 1;
        else
            v2 = v3 + 1;
    }
    return sub_498220(a1, v2);
}

//----- (00498220) --------------------------------------------------------
int __cdecl sub_498220(int a1, int a2)
{
    if (a2 < *(int*)& byte_5D4594[1217460])
        memmove(
                *(_DWORD*)& byte_5D4594[1217456] + 4 * a2 + 4,
                (_BYTE*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * a2),
                4 * (*(_DWORD*)& byte_5D4594[1217460] + 0x3FFFFFFF * a2));
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * a2) = a1;
    return ++ * (_DWORD*)& byte_5D4594[1217460];
}

//----- (00498290) --------------------------------------------------------
int __cdecl sub_498290(int a1)
{
    int v1; // esi
    int v2; // ecx
    int v3; // eax
    int result; // eax

    v1 = 0;
    v2 = *(_DWORD*)& byte_5D4594[1217460] - 1;
    if (*(int*)& byte_5D4594[1217460] - 1 < 0)
        goto LABEL_11;
    do
    {
        v3 = (v2 + v1) / 2;
        if (*(int*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * v3) + 44) >= *(int*)(a1 + 40))
            v2 = v3 - 1;
        else
            v1 = v3 + 1;
    } while (v1 <= v2);
    if (v2 >= 0)
        result = v2;
    else
        LABEL_11:
        result = 0;
    return result;
}

//----- (004982E0) --------------------------------------------------------
int __cdecl sub_4982E0(int a1)
{
    int v1; // esi

    v1 = sub_498330(a1);
    memmove(
            *(_DWORD*)& byte_5D4594[1217456] + 4 * v1,
            (_BYTE*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * (v1 + 1)),
            4 * (*(_DWORD*)& byte_5D4594[1217460] + 0x3FFFFFFF * (v1 + 1)));
    --* (_DWORD*)& byte_5D4594[1217460];
    return v1;
}

//----- (00498330) --------------------------------------------------------
int __cdecl sub_498330(int a1)
{
    int v1; // ebx
    int v2; // edi
    int v3; // esi
    int result; // eax
    int v5; // ecx

    v1 = *(_DWORD*)(a1 + 40);
    v2 = 0;
    v3 = *(_DWORD*)& byte_5D4594[1217460] - 1;
    while (1)
    {
        result = (v3 + v2) / 2;
        v5 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1217456] + 4 * result) + 40);
        if (v5 == v1)
            break;
        if (v5 >= v1)
            v3 = (v3 + v2) / 2;
        else
            v2 = result + 1;
        if (v2 > v3)
            nox_exit(-1);
    }
    return result;
}

//----- (00498380) --------------------------------------------------------
void __cdecl sub_498380(int a1, int a2)
{
    int v2; // ebx
    int v3; // edx
    int v4; // ecx
    int v5; // eax
    int v6; // ecx
    int v7; // eax
    int v8; // ebx
    int v9; // ecx
    int v10; // ecx
    int v11; // esi
    bool v12; // cc
    int v13; // edx
    int v14; // eax
    int v15; // ebx
    int v16; // ecx
    int v17; // ecx
    int v18; // edi
    int v19; // ecx
    int v20; // eax
    int v21; // eax
    int v22; // ecx

    v2 = *(_DWORD*)(a1 + 40);
    v3 = *(_DWORD*)(a2 + 44);
    if (v3 < v2)
        return;
    v4 = *(_DWORD*)(a2 + 40);
    v5 = *(_DWORD*)(a1 + 44);
    if (v4 > v5)
        return;
    if (v4 < v2)
    {
        if (v3 <= v5)
        {
            if (*(int*)(a1 + 32) >= *(int*)(a2 + 32))
            {
                v6 = *(_DWORD*)(a1 + 44);
                *(_DWORD*)(a1 + 40) = v3 + 1;
                if (v3 + 1 > v6)
                    * (_BYTE*)(a1 + 48) = 0;
            }
            else
            {
                *(_DWORD*)(a2 + 44) = v2 - 1;
            }
            return;
        }
        if (*(int*)(a1 + 32) < *(int*)(a2 + 32))
        {
            v7 = sub_4CAED0(a2);
            v8 = *(_DWORD*)(v7 + 44);
            v9 = *(_DWORD*)(a1 + 44) + 1;
            *(_DWORD*)(v7 + 40) = v9;
            if (v9 > v8)
                * (_BYTE*)(v7 + 48) = 0;
            v10 = *(_DWORD*)(a1 + 40) - 1;
            v11 = *(_DWORD*)(a2 + 40);
            *(_DWORD*)(a2 + 44) = v10;
            if (v11 > v10)
                * (_BYTE*)(a2 + 48) = 0;
            sub_4CAE90(v7);
            return;
        }
        LABEL_27:
        *(_BYTE*)(a1 + 48) = 0;
        return;
    }
    v12 = v3 <= v5;
    v13 = *(_DWORD*)(a1 + 32);
    if (v12)
    {
        if (v13 >= *(int*)(a2 + 32))
        {
            v14 = sub_4CAED0(a1);
            v15 = *(_DWORD*)(v14 + 44);
            v16 = *(_DWORD*)(a2 + 44) + 1;
            *(_DWORD*)(v14 + 40) = v16;
            if (v16 > v15)
                * (_BYTE*)(v14 + 48) = 0;
            v17 = *(_DWORD*)(a2 + 40) - 1;
            v18 = *(_DWORD*)(a1 + 40);
            *(_DWORD*)(a1 + 44) = v17;
            if (v18 > v17)
                * (_BYTE*)(a1 + 48) = 0;
            sub_4CAE90(v14);
        }
        else
        {
            *(_BYTE*)(a2 + 48) = 0;
        }
    }
    else
    {
        if (v13 >= *(int*)(a2 + 32))
        {
            v21 = v4 - 1;
            v22 = *(_DWORD*)(a1 + 40);
            *(_DWORD*)(a1 + 44) = v21;
            if (v22 <= v21)
                return;
            goto LABEL_27;
        }
        v19 = *(_DWORD*)(a2 + 44);
        v20 = v5 + 1;
        *(_DWORD*)(a2 + 40) = v20;
        if (v20 > v19)
            * (_BYTE*)(a2 + 48) = 0;
    }
}

//----- (004984B0) --------------------------------------------------------
int __cdecl sub_4984B0_drawable(int a1)
{
    int v1; // edi
    int v3; // ebx
    int v4; // ecx
    int v5; // kr0C_4
    int v6; // ebp
    int v7; // esi
    int v8; // ebx
    int v9; // ecx
    int v10; // edx
    int v11; // eax
    int v12; // eax
    int v13; // ebp
    int v14; // esi
    int v15; // ebx
    int v16; // ecx
    int v17; // esi
    int v18; // eax
    int v19; // ebp
    int v20; // ecx
    int v21; // edx
    int* v22; // esi
    int v23; // edi
    int v24; // ebx
    int v25; // ecx
    int v26; // edx
    int v27; // ebp
    int* v28; // esi
    int v29; // edi
    int v30; // ebx
    int v31; // [esp+10h] [ebp-58h]
    int v32; // [esp+10h] [ebp-58h]
    char* v33; // [esp+14h] [ebp-54h]
    int v34; // [esp+18h] [ebp-50h]
    int v35; // [esp+18h] [ebp-50h]
    int v36; // [esp+18h] [ebp-50h]
    int v37; // [esp+1Ch] [ebp-4Ch]
    int v38; // [esp+1Ch] [ebp-4Ch]
    int v39; // [esp+20h] [ebp-48h]
    int v40; // [esp+20h] [ebp-48h]
    int v41; // [esp+24h] [ebp-44h]
    int v42; // [esp+28h] [ebp-40h]
    int v43; // [esp+2Ch] [ebp-3Ch]
    int v44; // [esp+30h] [ebp-38h]
    int v45; // [esp+34h] [ebp-34h]
    int4 a1a; // [esp+38h] [ebp-30h]
    int4 a2; // [esp+48h] [ebp-20h]
    int4 v48; // [esp+58h] [ebp-10h]
    int* i; // [esp+6Ch] [ebp+4h]
    int v50; // [esp+6Ch] [ebp+4h]
    int v51; // [esp+6Ch] [ebp+4h]

    v1 = a1;
    if (!*(_DWORD*)(a1 + 300))
        return 0;
    if (a1 == *(_DWORD*)& byte_5D4594[2614252])
        return 1;
    if ((signed char) * (_BYTE*)(a1 + 112) >= 0)
    {
        v42 = *(_DWORD*)(a1 + 12);
        v43 = *(_DWORD*)(a1 + 16);
        v6 = *(_DWORD*)(a1 + 12);
    }
    else
    {
        if (!(*(_BYTE*)(a1 + 116) & 4))
            return *(_DWORD*)(a1 + 132);
        v3 = *(_DWORD*)(a1 + 12);
        v4 = 8 * *(unsigned __int8*)(a1 + 299);
        v5 = *(int*)& byte_587000[v4 + 196184];
        v6 = v3 + v5 / 2;
        v42 = v3 + v5 / 2;
        v43 = *(_DWORD*)(a1 + 16) + *(int*)& byte_587000[v4 + 196188] / 2;
    }
    if (*(_DWORD*)(a1 + 120) & 0x10000)
        return *(_DWORD*)(a1 + 132);
    v31 = 0;
    v33 = sub_437250();
    v7 = *((_DWORD*)v33 + 4) - *(_DWORD*)v33;
    v44 = v7;
    v8 = *((_DWORD*)v33 + 5) - *((_DWORD*)v33 + 1);
    v45 = v8;
    a1a.field_0 = *(_DWORD*)v33 + *((int*)v33 + 8) / 2;
    a1a.field_4 = *((_DWORD*)v33 + 1) + *((_DWORD*)v33 + 12) + *((int*)v33 + 9) / 2;
    v37 = v6 - v7;
    a1a.field_8 = v6 - v7;
    a1a.field_C = v43 - v8;
    v9 = *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[1217464] + 1203868];
    v10 = *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[1217464] + 1203872];
    if (*(int*)& byte_5D4594[1217464] <= 0)
        return 1;
    for (i = (int*)& byte_5D4594[1203880]; ; i += 2)
    {
        a2.field_4 = v10;
        a2.field_0 = v9;
        v34 = *(i - 1);
        v11 = *i;
        a2.field_8 = *(i - 1);
        v39 = v11;
        a2.field_C = v11;
        if (sub_427C80(&a1a, &a2))
            break;
        v9 = v34;
        v10 = v39;
        if (++v31 >= *(int*)& byte_5D4594[1217464])
            return 1;
    }
    if (*(_DWORD*)(v1 + 44) == 2)
    {
        v12 = nox_float2int(*(float*)(v1 + 48));
        v50 = v12;
        if (*(_WORD*)(v1 + 2))
        {
            v35 = *(unsigned __int16*)(v1 + 6);
            v13 = v6 - (*(unsigned __int16*)(v1 + 4) >> 1) - v7;
            v14 = v43 + v12 + *(__int16*)(v1 + 104) - v35 - v8 - nox_float2int(*(float*)(v1 + 96));
            v15 = v13 + *(unsigned __int16*)(v1 + 4);
            v16 = v14 + v35;
        }
        else
        {
            v13 = v6 - v12 - v7;
            v14 = v43 - v12 - v8 - nox_float2int(*(float*)(v1 + 100));
            v15 = v42 + v50 - v44;
            v16 = v43 + v50 + *(__int16*)(v1 + 104) - v45 - nox_float2int(*(float*)(v1 + 96));
        }
    }
    else if (*(_WORD*)(v1 + 2))
    {
        v13 = v6 - (*(unsigned __int16*)(v1 + 4) >> 1) - v7;
        v16 = nox_float2int(*(float*)(v1 + 92)) + v43 + *(__int16*)(v1 + 104) - v8;
        v14 = v16 - *(unsigned __int16*)(v1 + 6);
        v15 = v13 + *(unsigned __int16*)(v1 + 4);
    }
    else
    {
        v13 = v37 + nox_float2int(*(float*)(v1 + 72));
        v17 = v43 - v8 - nox_float2int(*(float*)(v1 + 100));
        v14 = nox_float2int(*(float*)(v1 + 68)) + v17;
        v15 = v37 + nox_float2int(*(float*)(v1 + 80));
        v16 = nox_float2int(*(float*)(v1 + 92)) + v43 + *(__int16*)(v1 + 104) - v45;
    }
    v32 = 0;
    v51 = 0;
    v41 = v13;
    v38 = v14;
    v40 = v15;
    v36 = v16;
    if (v13 < *(int*)v33 || v13 > * ((_DWORD*)v33 + 2))
        v32 = 1;
    else
        v51 = 1;
    if (v14 < *((_DWORD*)v33 + 1) || v14 > * ((_DWORD*)v33 + 3))
        ++v32;
    else
        ++v51;
    if (v15 < *(int*)v33 || v15 > * ((_DWORD*)v33 + 2))
        ++v32;
    else
        ++v51;
    if (v16 < *((_DWORD*)v33 + 1) || v16 > * ((_DWORD*)v33 + 3))
        ++v32;
    else
        ++v51;
    if (*(_WORD*)(v1 + 2))
    {
        if (v15 - v13 > 6)
        {
            v13 += 3;
            v15 -= 3;
        }
        if (v16 - v14 >= 22)
        {
            v14 += 11;
            v16 -= 11;
        }
    }
    if (!v51 || !v32)
        return 0;
    v48.field_0 = a1a.field_0;
    v48.field_4 = a1a.field_4;
    if (v41 >= *(int*)v33)
    {
        if (v40 <= *((_DWORD*)v33 + 2))
            goto LABEL_50;
        v48.field_8 = v13;
        a1a.field_8 = v13;
    }
    else
    {
        v48.field_8 = v15;
        a1a.field_8 = v15;
    }
    a1a.field_C = v14;
    v48.field_C = v16;
    LABEL_50:
    if (v38 >= *((_DWORD*)v33 + 1))
    {
        if (v36 <= *((_DWORD*)v33 + 3))
            goto LABEL_55;
        a1a.field_8 = v13;
        v48.field_C = v14;
        a1a.field_C = v14;
    }
    else
    {
        a1a.field_8 = v13;
        v48.field_C = v16;
        a1a.field_C = v16;
    }
    v48.field_8 = v15;
    LABEL_55:
    v18 = *(_DWORD*)& byte_5D4594[1217464];
    v19 = 0;
    v20 = *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[1217464] + 1203868];
    v21 = *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[1217464] + 1203872];
    if (*(int*)& byte_5D4594[1217464] <= 0)
    {
        LABEL_59:
        v25 = *(_DWORD*)& byte_5D4594[8 * v18 + 1203868];
        v26 = *(_DWORD*)& byte_5D4594[8 * v18 + 1203872];
        v27 = 0;
        if (v18 <= 0)
            return 1;
        v28 = (int*)& byte_5D4594[1203880];
        while (1)
        {
            v29 = *(v28 - 1);
            v30 = *v28;
            a2.field_0 = v25;
            a2.field_4 = v26;
            a2.field_8 = v29;
            a2.field_C = v30;
            if (sub_427C80(&v48, &a2))
                break;
            ++v27;
            v28 += 2;
            v25 = v29;
            v26 = v30;
            if (v27 >= *(int*)& byte_5D4594[1217464])
                return 1;
        }
    }
    else
    {
        v22 = (int*)& byte_5D4594[1203880];
        while (1)
        {
            v23 = *(v22 - 1);
            v24 = *v22;
            a2.field_4 = v21;
            a2.field_0 = v20;
            a2.field_8 = v23;
            a2.field_C = v24;
            if (sub_427C80(&a1a, &a2))
                break;
            v18 = *(_DWORD*)& byte_5D4594[1217464];
            ++v19;
            v22 += 2;
            v20 = v23;
            v21 = v24;
            if (v19 >= *(int*)& byte_5D4594[1217464])
                goto LABEL_59;
        }
    }
    return 0;
}

//----- (004989A0) --------------------------------------------------------
void __cdecl sub_4989A0()
{
    int v0; // ebp
    unsigned __int8* v1; // edx
    int v2; // eax
    int v3; // ecx
    int v4; // esi
    int v5; // edi
    int v6; // ebx
    int v7; // [esp+0h] [ebp-24h]
    unsigned __int8* v8; // [esp+4h] [ebp-20h]
    unsigned __int8* v9; // [esp+8h] [ebp-1Ch]
    int v10; // [esp+Ch] [ebp-18h]
    unsigned __int8* v11; // [esp+10h] [ebp-14h]
    int v12; // [esp+14h] [ebp-10h]
    int v13; // [esp+18h] [ebp-Ch]
    unsigned __int8* i; // [esp+1Ch] [ebp-8h]
    unsigned __int8 v15; // [esp+20h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[1217464] > 2)
    {
        v0 = 2;
        v1 = &byte_5D4594[1203896];
        v12 = *(_DWORD*)& byte_5D4594[1203876];
        v2 = *(_DWORD*)& byte_5D4594[1203884];
        v13 = *(_DWORD*)& byte_5D4594[1203880];
        v3 = *(_DWORD*)& byte_5D4594[1203888];
        v10 = 2;
        v7 = 1;
        v9 = &byte_5D4594[1213352];
        v8 = &byte_5D4594[1203888];
        v11 = &byte_5D4594[1213356];
        for (i = &byte_5D4594[1203896]; ; i += 8)
        {
            v4 = *((_DWORD*)v1 - 1);
            v5 = *(_DWORD*)v1;
            v15 = byte_5D4594[v0 + 1212324];
            if ((v12 - v2) * (*(_DWORD*)v1 - v3) != (v13 - v3) * (v4 - v2))
                break;
            v6 = v7;
            if (byte_5D4594[v10 + 1212324] != byte_5D4594[v7 + 1212324])
                goto LABEL_7;
            LABEL_8:
            v0 = v10 + 1;
            *((_DWORD*)v8 - 1) = v4;
            *(_DWORD*)v8 = v5;
            v10 = v0;
            byte_5D4594[v6 + 1212324] = v15;
            *(_DWORD*)v9 = *(_DWORD*)v11;
            v3 = v5;
            v2 = v4;
            v1 = i + 8;
            v11 += 4;
            if (v0 >= *(int*)& byte_5D4594[1217464])
            {
                *(_DWORD*)& byte_5D4594[1217464] = v6 + 1;
                return;
            }
        }
        v6 = v7;
        LABEL_7:
        v7 = ++v6;
        v8 += 8;
        v12 = v2;
        v9 += 4;
        v13 = v3;
        goto LABEL_8;
    }
}

//----- (00498AE0) --------------------------------------------------------
int sub_498AE0()
{
    int v0; // ecx
    int v1; // esi
    int i; // eax

    sub_434560(1);
    sub_434430(0, 0, 0);
    v0 = *(_DWORD*)& byte_5D4594[1217464];
    v1 = 0;
    for (i = *(_DWORD*)& byte_5D4594[1217464] - 1; v1 < v0; ++v1)
    {
        if (byte_5D4594[i + 1212324] == 12)
        {
            sub_498B50(
                    *(_DWORD*)& byte_5D4594[8 * i + 1203876],
                    *(_DWORD*)& byte_5D4594[8 * i + 1203880],
                    *(_DWORD*)& byte_5D4594[8 * v1 + 1203876],
                    *(_DWORD*)& byte_5D4594[8 * v1 + 1203880]);
            v0 = *(_DWORD*)& byte_5D4594[1217464];
        }
        i = v1;
    }
    return sub_434560(0);
}

//----- (00498B50) --------------------------------------------------------
int __cdecl sub_498B50(int a1, int a2, int a3, int a4)
{
    int v4; // ebp
    int v5; // esi
    int v6; // edi
    int v7; // ecx
    int v8; // eax
    int v9; // ebx
    int v10; // edx
    int v11; // eax
    int v12; // ebx
    int v13; // ebp
    int result; // eax
    unsigned __int8 v15; // [esp+14h] [ebp+4h]
    int v16; // [esp+18h] [ebp+8h]
    int v17; // [esp+1Ch] [ebp+Ch]
    int v18; // [esp+20h] [ebp+10h]

    v4 = a3;
    v5 = a1;
    v6 = a2;
    v7 = a2 - a4;
    v8 = a1 - a3;
    v9 = a1 - a3;
    v10 = a4 - a2;
    if (a1 - a3 < 0)
        v8 = a3 - a1;
    if (v7 < 0)
        v7 = a4 - a2;
    if (v8 <= v7)
    {
        v16 = 0;
        v17 = v10 < 0 ? 1 : -1;
    }
    else
    {
        v17 = 0;
        v11 = (v9 < 0) - 1;
        LOBYTE(v11) = v11 & 0xFE;
        v16 = v11 + 1;
    }
    v15 = -48;
    v12 = a4 - v6;
    v13 = v4 - v5;
    v18 = 10;
    do
    {
        sub_434580(v15);
        v15 -= 20;
        sub_49F500(v5, v6);
        sub_49F500(v5 + v13, v12 + v6);
        sub_49E4B0();
        v5 += v17;
        v6 += v16;
        result = --v18;
    } while (v18);
    return result;
}

//----- (00498C20) --------------------------------------------------------
int __cdecl sub_498C20(int2* a1, int2* a2, int a3)
{
    int2* v3; // edi
    int2* v4; // ebp
    char v5; // al
    char v6; // bl
    int v7; // eax
    int v8; // edx
    int* v9; // ecx
    int v10; // eax
    int v11; // ebp
    int v12; // edx
    int v13; // ebp
    int v14; // edx
    int v15; // eax
    int v16; // esi
    int v17; // eax
    int v18; // ecx
    bool v19; // cc
    float v21; // [esp+0h] [ebp-44h]
    float v22; // [esp+0h] [ebp-44h]
    float v23; // [esp+0h] [ebp-44h]
    float v24; // [esp+0h] [ebp-44h]
    float v25; // [esp+0h] [ebp-44h]
    float v26; // [esp+0h] [ebp-44h]
    float v27; // [esp+4h] [ebp-40h]
    float v28; // [esp+14h] [ebp-30h]
    float v29; // [esp+18h] [ebp-2Ch]
    float v30; // [esp+1Ch] [ebp-28h]
    int v31; // [esp+20h] [ebp-24h]
    int v32; // [esp+24h] [ebp-20h]
    unsigned __int8* v33; // [esp+28h] [ebp-1Ch]
    int2 a1a; // [esp+2Ch] [ebp-18h]
    int2 a2a; // [esp+34h] [ebp-10h]
    int2 a3a; // [esp+3Ch] [ebp-8h]
    char v37; // [esp+48h] [ebp+4h]
    char v38; // [esp+50h] [ebp+Ch]
    float v39; // [esp+50h] [ebp+Ch]

    v3 = a1;
    if (!a1)
        return 0;
    v4 = a2;
    if (!a2)
        return 0;
    if (!a3)
        return 0;
    *(_DWORD*)& byte_5D4594[1217452] = 0;
    v5 = sub_4990D0(a1, a2);
    v6 = v5;
    v37 = v5;
    if (!v5)
        return 0;
    if (v5 != 4 && v5 != 8)
    {
        v29 = (double)(a2->field_4 - v3->field_4) / (double)(a2->field_0 - v3->field_0);
        v27 = (double)v3->field_0 * v29;
        v31 = v3->field_4 - nox_float2int(v27);
    }
    v7 = *(_DWORD*)& byte_5D4594[1217464];
    v8 = 0;
    v32 = 0;
    if (*(_DWORD*)& byte_5D4594[1217464] > 0)
    {
        v9 = (int*)& byte_5D4594[1203884];
        v33 = &byte_5D4594[1203884];
        while (1)
        {
            a2a = *((int2*)v9 - 1);
            if (v8 == v7 - 1)
            {
                a3a = *(int2*)& byte_5D4594[1203876];
            }
            else
            {
                v10 = v9[1];
                a3a.field_0 = *v9;
                a3a.field_4 = v10;
            }
            v38 = sub_4990D0(&a2a, &a3a);
            if (v38
                && (!(v6 & 1)
                    || a2a.field_0 <= v3->field_0
                    || a2a.field_0 <= v4->field_0
                    || a3a.field_0 <= v3->field_0
                    || a3a.field_0 <= v4->field_0)
                && (!(v37 & 2) || a2a.field_0 >= v3->field_0 || a2a.field_0 >= v4->field_0 || a3a.field_0 >= v3->field_0))
            {
                if (!(v37 & 4)
                    || (v11 = v3->field_4, a2a.field_4 <= v11)
                    || (v12 = a2->field_4, a2a.field_4 <= v12)
                    || a3a.field_4 <= v11
                    || a3a.field_4 <= v12)
                {
                    if (!(v37 & 8)
                        || (v13 = v3->field_4, a2a.field_4 >= v13)
                        || (v14 = a2->field_4, a2a.field_4 >= v14)
                        || a3a.field_4 >= v13
                        || a3a.field_4 >= v14)
                    {
                        if (a2a.field_0 == a3a.field_0)
                        {
                            if (v37 == 4 || v37 == 8)
                                goto LABEL_65;
                            if (v37 != 1 && v37 != 2)
                            {
                                a1a.field_0 = a2a.field_0;
                                v26 = (double)a2a.field_0 * v29;
                                a1a.field_4 = v31 + nox_float2int(v26);
                                LABEL_59:
                                if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
                                    sub_499130(&a1a.field_0);
                                goto LABEL_65;
                            }
                            a1a.field_4 = v3->field_0;
                            a1a.field_0 = a2a.field_0;
                            if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
                            {
                                LABEL_64:
                                sub_499130(&a1a.field_0);
                                goto LABEL_65;
                            }
                        }
                        else
                        {
                            v28 = (double)(a3a.field_4 - a2a.field_4) / (double)(a3a.field_0 - a2a.field_0);
                            v21 = (double)a2a.field_0 * v28;
                            v15 = nox_float2int(v21);
                            v16 = a2a.field_4 - v15;
                            if (v37 == 4 || v37 == 8)
                            {
                                if (v38 == 1 || v38 == 2)
                                {
                                    a1a.field_0 = v3->field_0;
                                    a1a.field_4 = a2a.field_0;
                                    if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
                                        sub_499130(&a1a.field_0);
                                }
                                else
                                {
                                    a1a.field_0 = v3->field_0;
                                    v22 = (double)a1a.field_0 * v28;
                                    a1a.field_4 = v16 + nox_float2int(v22);
                                    if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
                                        sub_499130(&a1a.field_0);
                                }
                            }
                            if (v37 == 1 || v37 == 2)
                            {
                                if (v38 == 1 || v38 == 2)
                                    goto LABEL_65;
                                v25 = (double)(v31 - v16) / v28;
                                v17 = nox_float2int(v25);
                                v18 = v3->field_4;
                                a1a.field_0 = v17;
                                a1a.field_4 = v18;
                                goto LABEL_59;
                            }
                            if (v29 != v28)
                            {
                                v39 = (double)(v31 - v16);
                                v30 = v28 - v29;
                                v23 = v39 / v30;
                                a1a.field_0 = nox_float2int(v23);
                                v24 = v39 * v28 / v30;
                                a1a.field_4 = v16 + nox_float2int(v24);
                                if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
                                    goto LABEL_64;
                            }
                        }
                    }
                }
            }
            LABEL_65:
            v7 = *(_DWORD*)& byte_5D4594[1217464];
            v8 = v32 + 1;
            v9 = (int*)(v33 + 8);
            v19 = ++v32 < *(int*)& byte_5D4594[1217464];
            v33 += 8;
            if (!v19)
                break;
            v6 = v37;
            v4 = a2;
        }
    }
    sub_4991E0(v3);
    return *(_DWORD*)& byte_5D4594[1217452];
}
// 498EE0: variable 'v29' is possibly undefined
// 498EFA: variable 'v31' is possibly undefined

//----- (004990D0) --------------------------------------------------------
char __cdecl sub_4990D0(_DWORD* a1, _DWORD* a2)
{
    int v2; // ecx
    int v3; // edx
    char result; // al
    int v5; // ecx
    int v6; // edx
    int v7; // ecx
    int v8; // edx

    if (*a1 <= *a2)
    {
        if (*a1 >= *a2)
        {
            v7 = a1[1];
            v8 = a2[1];
            if (v7 <= v8)
            {
                if (v7 >= v8)
                    result = 0;
                else
                    result = 8;
            }
            else
            {
                result = 4;
            }
        }
        else
        {
            v5 = a1[1];
            v6 = a2[1];
            result = 2;
            if (v5 <= v6)
            {
                if (v5 < v6)
                    result = 10;
            }
            else
            {
                result = 6;
            }
        }
    }
    else
    {
        v2 = a1[1];
        v3 = a2[1];
        result = 1;
        if (v2 <= v3)
        {
            if (v2 < v3)
                result = 9;
        }
        else
        {
            result = 5;
        }
    }
    return result;
}

//----- (00499130) --------------------------------------------------------
int __cdecl sub_499130(int* a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1217452];
    if (*(int*)& byte_5D4594[1217452] < 32)
    {
        result = *(_DWORD*)& byte_5D4594[1217452] + 1;
        *(_DWORD*)& byte_5D4594[8 * result + 1212060] = *a1;
        *(_DWORD*)& byte_5D4594[8 * result + 1212064] = a1[1];
        *(_DWORD*)& byte_5D4594[1217452] = result;
    }
    return result;
}

//----- (00499160) --------------------------------------------------------
BOOL __cdecl sub_499160(int2* a1, int2* a2, int2* a3)
{
    int v3; // edi
    int v4; // esi
    int v5; // eax
    int v6; // edx
    int v7; // ecx
    BOOL result; // eax

    v3 = a3->field_0;
    if (a3->field_0 > a2->field_0)
    {
        v4 = a3->field_4;
        if (v4 > a2->field_4)
        {
            v3 = a3->field_0;
            v6 = a2->field_0;
            v4 = a2->field_4;
            v5 = a3->field_4;
        }
        else
        {
            v6 = a2->field_0;
            v5 = a2->field_4;
        }
    }
    else
    {
        v4 = a2->field_4;
        if (a3->field_4 > v4)
        {
            v6 = a3->field_0;
            v3 = a2->field_0;
            v5 = a3->field_4;
        }
        else
        {
            v5 = a2->field_4;
            v6 = a3->field_0;
            v4 = a3->field_4;
            v3 = a2->field_0;
        }
    }
    result = 0;
    if (a1->field_0 >= v6 && a1->field_0 <= v3)
    {
        v7 = a1->field_4;
        if (v7 >= v4 && v7 <= v5)
            result = 1;
    }
    return result;
}

//----- (004991E0) --------------------------------------------------------
void __cdecl sub_4991E0(_DWORD* a1)
{
    int v1; // ebp
    _DWORD* v2; // ebx
    int v3; // esi
    unsigned __int8* v4; // edx
    int v5; // edi
    int v6; // edi
    _DWORD* v7; // ecx
    int v8; // eax
    int v9; // eax
    int v10; // esi
    int v11; // eax
    int v12; // [esp+4h] [ebp-4h]
    int v13; // [esp+Ch] [ebp+4h]

    v1 = *(_DWORD*)& byte_5D4594[1217452];
    if (*(_DWORD*)& byte_5D4594[1217452] > 0)
    {
        v2 = a1;
        v3 = 1;
        v12 = 1;
        v4 = &byte_5D4594[1212068];
        do
        {
            v5 = *((_DWORD*)v4 + 1) - v2[1];
            v6 = (*(_DWORD*)v4 - *v2) * (*(_DWORD*)v4 - *v2) + v5 * v5;
            if (v3 < v1)
            {
                v7 = v4 + 8;
                v13 = v1 - v3;
                do
                {
                    v8 = v7[1] - v2[1];
                    v9 = (*v7 - *v2) * (*v7 - *v2) + v8 * v8;
                    if (v9 < v6)
                    {
                        v10 = *((_DWORD*)v4 + 1);
                        v6 = v9;
                        v11 = *(_DWORD*)v4;
                        *(_DWORD*)v4 = *v7;
                        *((_DWORD*)v4 + 1) = v7[1];
                        *v7 = v11;
                        v7[1] = v10;
                    }
                    v7 += 2;
                    --v13;
                } while (v13);
                v1 = *(_DWORD*)& byte_5D4594[1217452];
                v3 = v12;
            }
            ++v3;
            v4 += 8;
            v12 = v3;
        } while (v3 - 1 < v1);
    }
}

//----- (00499290) --------------------------------------------------------
_QWORD __cdecl sub_499290(int a1)
{
    __int64 result; // rax

    LODWORD(result) = *(_DWORD*)& byte_5D4594[8 * a1 + 1212068];
    HIDWORD(result) = *(_DWORD*)& byte_5D4594[8 * a1 + 1212072];
    return result;
}

//----- (004992B0) --------------------------------------------------------
BOOL __cdecl sub_4992B0(int a1, int a2)
{
    BOOL result; // eax
    int v3; // ecx
    int v4; // ebp
    int v5; // ecx
    int v6; // edx
    BOOL v7; // [esp+0h] [ebp-8h]
    int v8; // [esp+4h] [ebp-4h]

    result = 0;
    v7 = 0;
    v8 = 0;
    if (*(int*)& byte_5D4594[1217464] > 0)
    {
        v3 = 8 * *(int*)& byte_5D4594[1217464] - 8;
        do
        {
            v4 = *(int*)& byte_5D4594[v3 + 1203876];
            v5 = *(int*)& byte_5D4594[v3 + 1203880];
            v6 = *(int*)& byte_5D4594[8 * v8 + 1203880];
            if (v6 > a2)
            {
                if (v5 > a2)
                    goto LABEL_11;
            }
            else if (a2 < v5)
            {
                goto LABEL_8;
            }
            if (a2 < v6)
            {
                LABEL_8:
                if (a1 >= *(int*)& byte_5D4594[8 * v8 + 1203876]
                          + (a2 - v6) * (v4 - *(int*)& byte_5D4594[8 * v8 + 1203876]) / (v5 - v6))
                {
                    result = v7;
                }
                else
                {
                    result = !v7;
                    v7 = !v7;
                }
            }
            LABEL_11:
            v3 = 8 * v8++;
        } while (v8 < *(int*)& byte_5D4594[1217464]);
    }
    return result;
}

//----- (00499360) --------------------------------------------------------
int sub_499360()
{
    int v0; // eax
    int v1; // eax
    int v2; // eax
    int v3; // eax
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    unsigned __int8* v8; // eax

    v0 = sub_44CFC0((CHAR*)& byte_587000[161848]);
    *(_DWORD*)& byte_5D4594[1217468] = nox_new_drawable_for_thing(v0);
    v1 = sub_44CFC0((CHAR*)& byte_587000[161868]);
    *(_DWORD*)& byte_5D4594[1217472] = nox_new_drawable_for_thing(v1);
    v2 = sub_44CFC0((CHAR*)& byte_587000[161888]);
    *(_DWORD*)& byte_5D4594[1217476] = nox_new_drawable_for_thing(v2);
    v3 = sub_44CFC0((CHAR*)& byte_587000[161908]);
    *(_DWORD*)& byte_5D4594[1217480] = nox_new_drawable_for_thing(v3);
    *(_DWORD*)& byte_5D4594[1217484] = 0;
    v4 = sub_44CFC0((CHAR*)& byte_587000[161928]);
    *(_DWORD*)& byte_5D4594[1217488] = nox_new_drawable_for_thing(v4);
    v5 = sub_44CFC0((CHAR*)& byte_587000[161948]);
    *(_DWORD*)& byte_5D4594[1217492] = nox_new_drawable_for_thing(v5);
    v6 = sub_44CFC0((CHAR*)& byte_587000[161968]);
    *(_DWORD*)& byte_5D4594[1217496] = nox_new_drawable_for_thing(v6);
    v7 = sub_44CFC0((CHAR*)& byte_587000[161988]);
    *(_DWORD*)& byte_5D4594[1217500] = nox_new_drawable_for_thing(v7);
    v8 = &byte_5D4594[1217468];
    while (v8 == &byte_5D4594[1217484])
    {
        LABEL_5:
        v8 += 4;
        if ((int)v8 >= (int)& byte_5D4594[1217504])
        {
            *(_DWORD*)& byte_5D4594[1217504] = 0;
            return 1;
        }
    }
    if (*(_DWORD*)v8)
    {
        *(_DWORD*)(*(_DWORD*)v8 + 120) |= 0x1000000u;
        goto LABEL_5;
    }
    return 0;
}

//----- (00499450) --------------------------------------------------------
int sub_499450()
{
    unsigned __int8* v0; // esi
    int result; // eax

    v0 = &byte_5D4594[1217468];
    do
    {
        result = *(_DWORD*)v0;
        if (*(_DWORD*)v0)
            result = sub_45A4B0(*(_QWORD * *)v0);
        *(_DWORD*)v0 = 0;
        v0 += 4;
    } while ((int)v0 < (int)& byte_5D4594[1217504]);
    *(_DWORD*)& byte_5D4594[1217504] = 0;
    return result;
}

//----- (00499490) --------------------------------------------------------
_DWORD* __cdecl sub_499490(int a1, _WORD* a2, int a3, int a4, char a5, char a6)
{
    _DWORD* result; // eax
    _DWORD* v7; // esi

    result = (_DWORD*)sub_45A360_drawable(a1, a3 + (unsigned __int16)a2[2], a4 + (unsigned __int16)a2[3]);
    v7 = result;
    if (result)
    {
        *((_WORD*)result + 216) = *a2;
        *((_WORD*)result + 217) = a2[1];
        *((_BYTE*)result + 443) = a5;
        *((_BYTE*)result + 444) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 138);
        *((_BYTE*)v7 + 446) = a6;
        *((_BYTE*)v7 + 445) = a6;
        result = sub_45A110_drawable(v7);
    }
    return result;
}

//----- (00499520) --------------------------------------------------------
_DWORD* __cdecl sub_499520(int a1, unsigned __int16* a2, __int16 a3, char a4, char a5)
{
    int v5; // ebp
    int v6; // edi
    _DWORD* result; // eax
    _DWORD* v8; // esi

    v5 = a2[3];
    v6 = a2[2];
    result = (_DWORD*)sub_45A360_drawable(a1, v6, (unsigned __int16)v5);
    v8 = result;
    if (result)
    {
        *((_WORD*)result + 216) = *a2;
        *((_WORD*)result + 217) = a2[1];
        *((_WORD*)result + 218) = v6;
        *((_WORD*)result + 219) = v5;
        *((_BYTE*)result + 442) = a3;
        *((_WORD*)result + 220) = (__int64)sqrt((double)((v6 - *a2) * (v6 - *a2) + (v5 - a2[1]) * (v5 - a2[1])));
        *((_BYTE*)result + 443) = a4;
        *((_BYTE*)result + 444) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 182);
        *((_BYTE*)v8 + 446) = a5;
        *((_BYTE*)v8 + 445) = a5;
        v8[116] = sub_4CA720;
        *((_WORD*)v8 + 254) = a3;
        result = sub_45A110_drawable(v8);
    }
    return result;
}

//----- (00499610) --------------------------------------------------------
int __cdecl sub_499610(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int result; // eax
    int v7; // eax
    int v8; // esi

    result = a2;
    if (a2 > 0)
    {
        do
        {
            v7 = sub_45A360_drawable(a1, a5, a6);
            v8 = v7;
            if (v7)
            {
                *(_DWORD*)(v7 + 432) = *(_DWORD*)(v7 + 12) << 12;
                *(_DWORD*)(v7 + 436) = *(_DWORD*)(v7 + 16) << 12;
                *(_BYTE*)(v7 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 227);
                *(_DWORD*)(v8 + 440) = sub_415FF0(1, a3, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 230);
                *(_DWORD*)(v8 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                       + sub_415FF0(a4, 64, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 233);
                *(_DWORD*)(v8 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                *(_WORD*)(v8 + 104) = 0;
                *(_BYTE*)(v8 + 296) = sub_415FF0(2, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 239);
                sub_45A110_drawable((_DWORD*)v8);
            }
            result = --a2;
        } while (a2);
    }
    return result;
}

//----- (00499710) --------------------------------------------------------
int __cdecl sub_499710(int a1, int a2, __int16 a3, int a4)
{
    int v4; // eax
    int v5; // esi
    int result; // eax
    int v7; // [esp+10h] [ebp-4h]

    v7 = 2;
    do
    {
        v4 = sub_45A360_drawable(a4, a1, a2);
        v5 = v4;
        if (v4)
        {
            *(_DWORD*)(v4 + 432) = a1 << 12;
            *(_DWORD*)(v4 + 436) = a2 << 12;
            *(_BYTE*)(v4 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 268);
            *(_DWORD*)(v5 + 440) = sub_415FF0(1, 3000, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 271);
            *(_DWORD*)(v5 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                   + sub_415FF0(5, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 274);
            *(_DWORD*)(v5 + 444) = *(_DWORD*)& byte_5D4594[2598000];
            *(_WORD*)(v5 + 104) = a3 + sub_415FF0(0, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 279);
            *(_BYTE*)(v5 + 296) = sub_415FF0(0, 4, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 280);
            sub_45A110_drawable((_DWORD*)v5);
        }
        result = --v7;
    } while (v7);
    return result;
}

//----- (00499810) --------------------------------------------------------
int __cdecl sub_499810(int a1, int a2)
{
    int v3; // [esp-4h] [ebp-8h]

    *(_DWORD*)(*(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(a2 + 297) + 1217468] + 12) = *(_DWORD*)(a2 + 12)
                                                                                            + *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 161776];
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(a2 + 297) + 1217468] + 16) = *(_DWORD*)(a2 + 16)
                                                                                            + *(__int16*)(a2 + 104)
                                                                                            + *(_DWORD*)& byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 161780];
    v3 = *(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(a2 + 297) + 1217468];
    (*(void(__cdecl * *)(int, int))(v3 + 300))(a1, v3);
    return 0;
}

//----- (00499880) --------------------------------------------------------
_DWORD* __cdecl sub_499880(__int16* a1)
{
    int i; // ebx
    _DWORD* result; // eax
    _DWORD* v3; // esi
    int v4; // eax
    double v5; // st7

    if (!*(_DWORD*)& byte_5D4594[1217508])
        * (_DWORD*)& byte_5D4594[1217508] = sub_44CFC0((CHAR*)& byte_587000[162360]);
    for (i = 0; i < 256; i += 6)
    {
        result = (_DWORD*)sub_45A360_drawable(*(int*)& byte_5D4594[1217508], *a1, a1[1]);
        v3 = result;
        if (result)
        {
            v4 = 8 * (__int16)i;
            *((_WORD*)v3 + 254) = i;
            *((float*)v3 + 117) = *(float*)& byte_587000[v4 + 194136] * 4.0;
            v5 = *(float*)& byte_587000[v4 + 194140] * 4.0;
            v3[119] = 0;
            *((float*)v3 + 118) = v5;
            v3[79] = *(_DWORD*)& byte_5D4594[2598000];
            v3[81] = *a1;
            v3[82] = a1[1];
            v3[115] = sub_4CA540;
            sub_49BC80_drawable(v3);
            result = sub_49BAB0_drawable(v3);
        }
    }
    return result;
}

//----- (00499950) --------------------------------------------------------
int __cdecl sub_499950(int a1, int2* a2, int2* a3, unsigned __int16 a4, char a5)
{
    int result; // eax
    int v6; // esi

    result = sub_45A360_drawable(a1, a2->field_0, a2->field_4);
    v6 = result;
    if (result)
    {
        *(_DWORD*)(result + 104) = a4;
        *(_BYTE*)(result + 296) = a5;
        *(_WORD*)(result + 440) = a4;
        *(_BYTE*)(result + 442) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 406);
        *(int2*)(v6 + 432) = *a3;
        result = sub_45A110_drawable((_DWORD*)v6);
    }
    return result;
}

//----- (004999D0) --------------------------------------------------------
int __cdecl sub_4999D0(int a1, int2* a2, int2* a3)
{
    int2* v3; // ebp
    int v4; // esi
    int v5; // edi
    __int64 v6; // rax
    int v7; // ebx
    int v8; // ecx
    int v9; // esi
    int v10; // edi
    int v11; // eax
    int v12; // ebp
    int v14; // [esp+10h] [ebp-Ch]
    int v15; // [esp+14h] [ebp-8h]
    int v16; // [esp+18h] [ebp-4h]
    int2* v17; // [esp+28h] [ebp+Ch]

    v3 = a2;
    v4 = a3->field_0 - a2->field_0;
    v5 = a3->field_4 - a2->field_4;
    v14 = a3->field_0 - a2->field_0;
    v15 = v5;
    v6 = (__int64)sqrt((double)(v4 * v4 + v5 * v5));
    v7 = v6;
    v16 = v6;
    if ((int)v6 > 0)
    {
        LODWORD(v6) = sub_415FF0(0, v6, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 437);
        v8 = v6;
        v17 = (int2*)v6;
        if ((int)v6 <= v7)
        {
            while (1)
            {
                v9 = v3->field_0 + v4 * v8 / v7;
                v10 = v3->field_4 + v5 * v8 / v7;
                v11 = sub_45A360_drawable(a1, v9, v10);
                v12 = v11;
                if (v11)
                {
                    if (v11 != -432)
                    {
                        *(_DWORD*)(v11 + 432) = v9 << 12;
                        *(_DWORD*)(v11 + 436) = v10 << 12;
                        *(_BYTE*)(v11 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 458);
                        *(_DWORD*)(v12 + 440) = sub_415FF0(1, 3000, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 461);
                        *(_DWORD*)(v12 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                                + sub_415FF0(5, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 464);
                        *(_DWORD*)(v12 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                    }
                    *(_WORD*)(v12 + 104) = sub_415FF0(15, 30, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 471);
                    *(_BYTE*)(v12 + 296) = sub_415FF0(-4, 4, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 472);
                    sub_45A110_drawable((_DWORD*)v12);
                    v7 = v16;
                }
                LODWORD(v6) = sub_415FF0(8, 100, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 439);
                v17 = (int2*)((char*)v17 + v6);
                if ((int)v17 > v7)
                    break;
                v3 = a2;
                v4 = v14;
                v5 = v15;
                v8 = (int)v17;
            }
        }
    }
    return v6;
}

//----- (00499B70) --------------------------------------------------------
void __cdecl sub_499B70(int xLeft, int yTop, int a3)
{
    switch (a3)
    {
        case 0:
        case 1:
            sub_49EFA0(xLeft, yTop);
            break;
        case 2:
            sub_49CE30(xLeft, yTop, 2, 2);
            break;
        case 3:
            sub_49EFA0(xLeft, yTop - 1);
            sub_49CE30(xLeft - 1, yTop, 3, 1);
            sub_49EFA0(xLeft, yTop + 1);
            break;
        case 4:
            sub_49CE30(xLeft, yTop - 1, 2, 1);
            sub_49CE30(xLeft - 1, yTop, 4, 2);
            sub_49CE30(xLeft, yTop + 2, 2, 1);
            break;
        case 5:
            sub_49CE30(xLeft - 1, yTop - 2, 3, 1);
            sub_49CE30(xLeft - 2, yTop - 1, 5, 3);
            sub_49CE30(xLeft - 1, yTop + 2, 3, 1);
            break;
        case 6:
            sub_49CE30(xLeft, yTop - 2, 2, 1);
            sub_49CE30(xLeft - 1, yTop - 1, 4, 1);
            sub_49CE30(xLeft - 2, yTop, 6, 2);
            sub_49CE30(xLeft - 1, yTop + 2, 4, 1);
            sub_49CE30(xLeft, yTop + 3, 2, 1);
            break;
        default:
            sub_4B0BC0(xLeft, yTop, a3 >> 1);
            break;
    }
}

//----- (00499CF0) --------------------------------------------------------
unsigned int __cdecl sub_499CF0(int* a1, int a2, int a3)
{
    unsigned int result; // eax
    int v4; // esi
    int2 a3a; // [esp+8h] [ebp-8h]

    sub_437250();
    if (!sub_40A5C0(2048) || (result = sub_430B40_get_mouse_prev_seq() - *(_DWORD*)& byte_5D4594[1217504], result >= 2))
    {
        *(_DWORD*)& byte_5D4594[1217504] = sub_430B40_get_mouse_prev_seq();
        if (a1 == (int*)2)
            v4 = 0;
        else
            v4 = (a1 == (int*)3) + 2;
        a3a.field_0 = 5;
        a3a.field_4 = nox_win_height / 3;
        sub_45D200(a1, a2, &a3a);
        sub_499E70(v4, a3a.field_0, a3a.field_4, 271, 166, 1, 1);
        sub_499E70(v4, a3a.field_0, a3a.field_4, 135, 166, 2, 1);
        sub_499E70(v4, a3a.field_0, a3a.field_4 + 166, 135, 166, 2, 1);
        sub_499E70(v4, a3a.field_0 + 271, a3a.field_4, 271, 166, 1, 2);
        sub_499E70(v4, a3a.field_0 + 135, a3a.field_4, 135, 166, 2, 2);
        result = sub_499E70(v4, a3a.field_0 + 135, a3a.field_4 + 166, 135, 166, 2, 2);
        if (a1 != (int*)4 && a3 == 1)
            result = sub_45D570((int)a1, a2);
    }
    return result;
}

//----- (00499E70) --------------------------------------------------------
int __cdecl sub_499E70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v7; // edi
    int v8; // esi
    char v9; // bl
    int v10; // ebp
    int v11; // eax
    int result; // eax
    int v13; // [esp+10h] [ebp-4h]

    v13 = 100;
    do
    {
        if (a6 == 2)
        {
            v7 = a3;
            v8 = a2 + sub_415FF0(0, a4, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 555);
        }
        else
        {
            v8 = a2;
            v7 = a3 + sub_415FF0(0, a5, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 563);
        }
        v9 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 568);
        v10 = sub_415FF0(-40, -20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 571);
        if (a7 == 1)
            v11 = sub_415FF0(-20, 0, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 573);
        else
            v11 = sub_415FF0(0, 20, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 575);
        sub_431540(a1, v8, v7, v11, v10, 1, v9, 0, 0, 1);
        result = --v13;
    } while (v13);
    return result;
}

//----- (00499F60) --------------------------------------------------------
_DWORD* __cdecl sub_499F60(int a1, int a2, int a3, __int16 a4, char a5, char a6, char a7, char a8, char a9, int a10)
{
    _DWORD* result; // eax
    int v11; // edx
    int v12; // ecx
    _DWORD* v13; // esi
    int v14; // eax

    if (!*(_DWORD*)& byte_5D4594[1217512])
    {
        *(_DWORD*)& byte_5D4594[1217512] = sub_44CFC0((CHAR*)& byte_587000[162824]);
        *(_DWORD*)& byte_5D4594[1217516] = sub_44CFC0((CHAR*)& byte_587000[162844]);
        *(_DWORD*)& byte_5D4594[1217520] = sub_44CFC0((CHAR*)& byte_587000[162864]);
        *(_DWORD*)& byte_5D4594[1217524] = sub_44CFC0((CHAR*)& byte_587000[162888]);
        *(_DWORD*)& byte_5D4594[1217528] = sub_44CFC0((CHAR*)& byte_587000[162912]);
        *(_DWORD*)& byte_5D4594[1217532] = sub_44CFC0((CHAR*)& byte_587000[162932]);
        *(_DWORD*)& byte_5D4594[1217536] = sub_44CFC0((CHAR*)& byte_587000[162956]);
        *(_DWORD*)& byte_5D4594[1217540] = sub_44CFC0((CHAR*)& byte_587000[162984]);
    }
    result = (_DWORD*)sub_45A360_drawable(a1, a2, a3);
    v13 = result;
    if (result)
    {
        BYTE1(v11) = HIBYTE(a4);
        LOBYTE(result) = *((_BYTE*)result + 160);
        LOBYTE(v12) = *((_BYTE*)v13 + 156);
        *((_WORD*)v13 + 52) = a4;
        LOBYTE(v11) = *((_BYTE*)v13 + 152);
        v13[108] = sub_4344A0(v11, v12, (int)result);
        if (a1 == *(_DWORD*)& byte_5D4594[1217512])
        {
            v14 = sub_4344A0(255, 128, 128);
        }
        else if (a1 == *(_DWORD*)& byte_5D4594[1217516])
        {
            v14 = sub_4344A0(255, 255, 255);
        }
        else if (a1 == *(_DWORD*)& byte_5D4594[1217524])
        {
            v14 = sub_4344A0(255, 100, 50);
        }
        else if (a1 == *(_DWORD*)& byte_5D4594[1217528])
        {
            v14 = sub_4344A0(64, 255, 64);
        }
        else if (a1 == *(_DWORD*)& byte_5D4594[1217532])
        {
            v14 = sub_4344A0(255, 100, 255);
        }
        else if (a1 == *(_DWORD*)& byte_5D4594[1217536])
        {
            v14 = sub_4344A0(255, 200, 255);
        }
        else if (a1 == *(_DWORD*)& byte_5D4594[1217540])
        {
            v14 = sub_4344A0(255, 255, 200);
        }
        else
        {
            v14 = sub_4344A0(200, 200, 255);
        }
        v13[109] = v14;
        *((_BYTE*)v13 + 440) = a5;
        *((_BYTE*)v13 + 443) = a6;
        *((_BYTE*)v13 + 442) = a6;
        *((_BYTE*)v13 + 441) = 1;
        *((_BYTE*)v13 + 444) = a8;
        *((_BYTE*)v13 + 445) = a9;
        *((_BYTE*)v13 + 446) = a7;
        sub_49BAB0_drawable(v13);
        sub_49B950(v13, a10);
        result = sub_45A110_drawable(v13);
    }
    return result;
}
// 49A025: variable 'v11' is possibly undefined
// 49A025: variable 'v12' is possibly undefined

//----- (0049A150) --------------------------------------------------------
int __cdecl sub_49A150(int2* a1, int a2, unsigned __int8 a3)
{
    int v3; // ebx
    int result; // eax
    int v5; // ebp
    int v6; // eax
    int v7; // esi
    int v8; // [esp+1Ch] [ebp+Ch]

    v3 = 2400 * a3 / 255 + 200;
    result = 84215050 * a3;
    v5 = 10 * a3 / 255 + 5;
    if (180 * a3 / 255 + 10 > 0)
    {
        v8 = 180 * a3 / 255 + 10;
        do
        {
            v6 = sub_45A360_drawable(a2, a1->field_0, a1->field_4);
            v7 = v6;
            if (v6)
            {
                if (v6 != -432)
                {
                    *(_DWORD*)(v6 + 432) = *(_DWORD*)(v6 + 12) << 12;
                    *(_DWORD*)(v6 + 436) = *(_DWORD*)(v6 + 16) << 12;
                    *(_BYTE*)(v6 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 822);
                    *(_DWORD*)(v7 + 440) = sub_415FF0(1, v3, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 825);
                    *(_DWORD*)(v7 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                           + sub_415FF0(v5, 96, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 828);
                    *(_DWORD*)(v7 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                }
                *(_WORD*)(v7 + 104) = sub_415FF0(5, 15, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 834);
                *(_WORD*)(v7 + 106) = 0;
                *(_BYTE*)(v7 + 296) = sub_415FF0(0, 8, "C:\\NoxPost\\src\\client\\Draw\\Fx.c", 836);
                sub_45A110_drawable((_DWORD*)v7);
            }
            result = --v8;
        } while (v8);
    }
    return result;
}

//----- (0049A2C0) --------------------------------------------------------
void nox_alloc_npcs()
{
    npc_array = nox_calloc(nox_max_npcs, sizeof(nox_npc));
}

//----- (0049A300) --------------------------------------------------------
nox_npc* __cdecl nox_new_npc(int id)
{
    int n = 0;
    nox_npc* cur = npc_array;
    while (cur->live)
    {
        cur++;
        n++;
        if (n >= nox_max_npcs)
            return 0;
    }
    nox_init_npc(cur, id);
    return cur;
}

//----- (0049A340) --------------------------------------------------------
nox_npc* __cdecl nox_npc_by_id(int id)
{
    int n = 0;
    nox_npc* cur = npc_array;
    while (cur->id != id || !cur->live)
    {
        cur++;
        n++;
        if (n >= nox_max_npcs)
            return 0;
    }
    return cur;
}

//----- (0049A380) --------------------------------------------------------
int __cdecl nox_init_npc(nox_npc* ptr, int id)
{
    memset(ptr, 0, 524); // TODO: why only part of it?
    ptr->live = 1;
    ptr->id = id;
    return id;
}

//----- (0049A3B0) --------------------------------------------------------
nox_npc* __cdecl nox_npc_set_328(int id, int a2)
{
    nox_npc* p = nox_npc_by_id(id);
    if (p)
        p->data8[326] = a2;
    return p;
}

//----- (0049A3D0) --------------------------------------------------------
char* __cdecl sub_49A3D0(char a1, int a2, int a3, int a4)
{
    char* npc; // eax
    _DWORD* k; // edx
    char* v7; // ecx
    char** v8; // edi
    int l; // esi
    _DWORD* i; // edx
    char* v12; // ecx
    char** v13; // edi
    int j; // esi

    npc = nox_npc_by_id(a2);
    if (!npc)
        return 0;
    if (a1 == 81 || a1 == 80)
    {
        int v10 = 0;
        for (i = npc + 32; *i; i += 6)
        {
            if (++v10 >= 27)
                return npc;
        }
        v12 = &npc[24 * v10];
        *((_DWORD*)v12 + 8) = a3;
        v13 = (char**)(v12 + 36);
        *((_DWORD*)npc + 326) |= a3;
        for (j = 0; j < 4; ++j)
        {
            npc = (char*)sub_413330(*(unsigned __int8*)(j + a4));
            *v13 = npc;
            ++v13;
        }
    } else {
        int v5 = 0;
        for (k = npc + 680; *k; k += 6)
        {
            if (++v5 >= 26)
                return npc;
        }
        v7 = &npc[24 * v5];
        *((_DWORD*)v7 + 170) = a3;
        v8 = (char**)(v7 + 684);
        *((_DWORD*)npc + 327) |= a3;
        for (l = 0; l < 4; ++l)
        {
            npc = (char*)sub_413330(*(unsigned __int8*)(l + a4));
            *v8 = npc;
            ++v8;
        }
    }
    return npc;
}

//----- (0049A4B0) --------------------------------------------------------
int __cdecl sub_49A4B0(_DWORD* a1, int a2, int a3)
{
    int result; // eax
    int v4; // ecx

    result = a1[108];
    v4 = a1[69] - 1;
    a1[108] = 0;
    switch (v4)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            if (!(a2 & 0xFFFFFFFC))
            {
                if (!result || !a1[77])
                    result = sub_415FF0(23, 24, "C:\\NoxPost\\src\\client\\System\\NPCInfo.c", 286);
                goto LABEL_12;
            }
            result = sub_4FA280(a2 & 0xFFFFFFFC);
            break;
        case 4:
        case 5:
            if (a2 & 0x400)
            {
                if (result && a1[77])
                {
                    LABEL_12:
                    a1[108] = result;
                }
                else
                {
                    result = sub_415FF0(47, 49, "C:\\NoxPost\\src\\client\\System\\NPCInfo.c", 314);
                    a1[108] = result;
                }
            }
            else if (a2 & 0x7FF8000)
            {
                result = 30;
            }
            else
            {
                if (!(a3 & 0x3000000))
                    goto LABEL_22;
                result = 40;
            }
            break;
        case 6:
            result = 21;
            break;
        case 7:
        LABEL_22:
            result = (a2 & 0x400) != 0 ? 0x26 : 0;
            break;
        case 8:
            result = 1;
            break;
        case 9:
            result = 2;
            break;
        case 11:
            result = 4;
            break;
        case 12:
            result = 6;
            break;
        case 13:
            result = 50;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

//----- (0049A5F0) --------------------------------------------------------
int sub_49A5F0()
{
    int result; // eax

    result = nox_new_alloc_class("HealthChange", 20, 32);
    *(_DWORD*)& byte_5D4594[1301772] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1301780] = sub_43F360((char*)& byte_587000[163264]);
        result = 1;
    }
    return result;
}

//----- (0049A630) --------------------------------------------------------
void sub_49A630()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1301772]);
    *(_DWORD*)& byte_5D4594[1301776] = 0;
}

//----- (0049A650) --------------------------------------------------------
_WORD* __cdecl sub_49A650(int a1, __int16 a2)
{
    _WORD* result; // eax
    _WORD* v3; // esi

    result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1301772]);
    v3 = result;
    if (result)
    {
        *(_DWORD*)result = a1;
        result[2] = a2;
        *((_DWORD*)result + 2) = sub_430B40_get_mouse_prev_seq();
        *((_DWORD*)v3 + 3) = *(_DWORD*)& byte_5D4594[1301776];
        *((_DWORD*)v3 + 4) = 0;
        result = *(_WORD * *)& byte_5D4594[1301776];
        if (*(_DWORD*)& byte_5D4594[1301776])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1301776] + 16) = v3;
        *(_DWORD*)& byte_5D4594[1301776] = v3;
    }
    return result;
}

//----- (0049A6A0) --------------------------------------------------------
void __cdecl sub_49A6A0(_DWORD* a1, int a2)
{
    _DWORD* v2; // eax
    int v3; // esi
    _DWORD* v4; // edi
    int v5; // edi
    int v6; // esi
    int v7; // edi
    _DWORD* v8; // [esp+4h] [ebp-C0h]
    int v9; // [esp+Ch] [ebp-B8h]
    int v10; // [esp+10h] [ebp-B4h]
    _DWORD* v11; // [esp+1Ch] [ebp-A8h]
    int v12; // [esp+20h] [ebp-A4h]
    wchar_t v13[80]; // [esp+24h] [ebp-A0h]

    v10 = sub_430B40_get_mouse_prev_seq();
    if (a2 == *(_DWORD*)& byte_5D4594[2614252])
        v9 = *(_DWORD*)& byte_5D4594[2650644];
    else
        v9 = *(_DWORD*)& byte_5D4594[2589772];
    v2 = *(_DWORD * *)& byte_5D4594[1301776];
    v8 = *(_DWORD * *)& byte_5D4594[1301776];
    if (*(_DWORD*)& byte_5D4594[1301776])
    {
        while (1)
        {
            v3 = v2[2];
            v4 = (_DWORD*)v2[3];
            v11 = (_DWORD*)v2[3];
            if ((unsigned int)(v10 - v3) <= 0x1E)
            {
                if (*v2 == *(_DWORD*)(a2 + 128))
                {
                    v5 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
                    v6 = *(_DWORD*)(a2 + 16)
                         + a1[1]
                         + 2 * (v3 - v10)
                         - *(__int16*)(a2 + 104)
                         - (unsigned __int64)(__int64) * (float*)(a2 + 100)
                         - a1[5];
                    nox_swprintf(v13, L"%d", abs32(*((__int16*)v8 + 2)));
                    sub_43F840(*(int*)& byte_5D4594[1301780], v13, &v12, 0, 0);
                    v7 = v12 / -2 + v5;
                    sub_434390(*(int*)& byte_5D4594[2650656]);
                    sub_43F6E0(*(int*)& byte_5D4594[1301780], (__int16*)v13, v7 - 1, v6 - 1);
                    sub_43F6E0(*(int*)& byte_5D4594[1301780], (__int16*)v13, v7 - 1, v6 + 1);
                    sub_43F6E0(*(int*)& byte_5D4594[1301780], (__int16*)v13, v7 + 1, v6 - 1);
                    sub_43F6E0(*(int*)& byte_5D4594[1301780], (__int16*)v13, v7 + 1, v6 + 1);
                    if (*((short*)v8 + 2) <= 0)
                        sub_434390(v9);
                    else
                        sub_434390(*(int*)& byte_5D4594[2618904]);
                    sub_43F6E0(*(int*)& byte_5D4594[1301780], (__int16*)v13, v7, v6);
                    v4 = v11;
                }
            }
            else
            {
                sub_49A880((int)v2);
            }
            v8 = v4;
            if (!v4)
                break;
            v2 = v4;
        }
    }
}

//----- (0049A880) --------------------------------------------------------
void __cdecl sub_49A880(int a1)
{
    int v1; // ecx
    int v2; // ecx

    v1 = *(_DWORD*)(a1 + 16);
    if (v1)
        * (_DWORD*)(v1 + 12) = *(_DWORD*)(a1 + 12);
    else
        *(_DWORD*)& byte_5D4594[1301776] = *(_DWORD*)(a1 + 12);
    v2 = *(_DWORD*)(a1 + 12);
    if (v2)
        * (_DWORD*)(v2 + 16) = *(_DWORD*)(a1 + 16);
    sub_414330(*(unsigned int**)& byte_5D4594[1301772], (_QWORD*)a1);
}

//----- (0049A8C0) --------------------------------------------------------
int sub_49A8C0()
{
    int result; // eax

    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1301772]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1301772] = 0;
    *(_DWORD*)& byte_5D4594[1301776] = 0;
    *(_DWORD*)& byte_5D4594[1301780] = 0;
    return result;
}

//----- (0049A8E0) --------------------------------------------------------
int sub_49A8E0_init()
{
    nox_drawable_2d_index_size = nox_drawable_2d_index_cap;
    nox_drawable_2d_index = nox_malloc(nox_drawable_2d_index_size * sizeof(void*));
    if (!nox_drawable_2d_index)
        return 0;

    if (nox_drawable_2d_index_size <= 0)
        return 1;

    for (int i = 0; i < nox_drawable_2d_index_size; i++)
    {
        nox_drawable_2d_index[i] = nox_calloc(nox_drawable_2d_index_size, sizeof(void*));
        if (!nox_drawable_2d_index[i])
            return 0;
    }
    return 1;
}

//----- (0049A950) --------------------------------------------------------
int sub_49A950_free()
{
    if (!nox_drawable_2d_index)
        return 1;
    for (int i = 0; i < nox_drawable_2d_index_size; i++) {
        free(nox_drawable_2d_index[i]);
    }
    free(nox_drawable_2d_index);
    nox_drawable_2d_index = 0;
    return 1;
}

//----- (0049A9B0) --------------------------------------------------------
int __cdecl sub_49A9B0_drawable(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    v2 = *(_DWORD*)(a1 + 404);
    if (v2)
        * (_DWORD*)(v2 + 400) = *(_DWORD*)(a1 + 400);
    else
        **(_DWORD * *)(a1 + 396) = *(_DWORD*)(a1 + 400);
    v3 = *(_DWORD*)(a1 + 400);
    if (v3)
        * (_DWORD*)(v3 + 404) = *(_DWORD*)(a1 + 404);
    *(_DWORD*)(a1 + 396) = 0;
    return result;
}

//----- (0049AA00) --------------------------------------------------------
void __cdecl sub_49AA00_drawable(nox_drawable* dr)
{
    int i = dr->field_3 / 128;
    int j = dr->field_4 / 128;

    if (dr->field_99)
        sub_49A9B0_drawable(dr);

    dr->field_101 = 0;

    nox_drawable* v4 = nox_drawable_2d_index[i][j];
    dr->field_100 = v4;
    if (v4)
        v4->field_101 = dr;
    nox_drawable_2d_index[i][j] = dr;

    dr->field_99 = &nox_drawable_2d_index[i][j];
}

//----- (0049AA90) --------------------------------------------------------
void __cdecl sub_49AA90(_DWORD* a1, int a2, int a3)
{
    int v3; // ebx
    int v4; // ecx
    int v5; // edi
    int v6; // edx

    v3 = a2;
    v4 = a1[4];
    a1[8] = a1[3];
    a1[9] = v4;
    if (a2 < 0 || a2 >= 5888 || (v5 = a3, a3 < 0) || a3 >= 5888)
    {
        v3 = 50;
        v5 = 50;
        if (!(a1[30] & 0x400000))
            sub_45A110_drawable(a1);
    }
    v6 = a1[5];
    a1[3] = v3;
    a1[10] = v6;
    a1[4] = v5;
    a1[5] = *(_DWORD*)& byte_5D4594[2598000];
    sub_49AA00_drawable(a1);
}

//----- (0049AB00) --------------------------------------------------------
void __cdecl sub_49AB00(int4* a1, void(__cdecl* draw_fnc)(nox_drawable*, int), int a3)
{
    if (!draw_fnc)
        return;

    int v3; // edi
    int v4; // esi
    int v5; // ecx
    int v6; // ebp
    int v7; // esi
    int v8; // [esp+10h] [ebp-10h]
    int v9; // [esp+14h] [ebp-Ch]
    int v10; // [esp+18h] [ebp-8h]

    v3 = a1->field_0 / 128;
    v4 = a1->field_4 / 128;
    v5 = a1->field_C / 128;
    v10 = a1->field_0 / 128;
    v8 = a1->field_8 / 128;
    v9 = a1->field_C / 128;
    if (v3 < 0)
    {
        v10 = 0;
        v3 = 0;
    }
    if (a1->field_8 / 128 >= nox_drawable_2d_index_size)
        v8 = nox_drawable_2d_index_size - 1;
    if (v4 < 0)
        v4 = 0;
    if (v5 >= nox_drawable_2d_index_size)
    {
        v9 = nox_drawable_2d_index_size - 1;
        v5 = nox_drawable_2d_index_size - 1;
    }
    v6 = v4;
    if (v4 <= v5)
    {
        while (1)
        {
            if (v10 <= v8)
            {
                do
                {
                    nox_drawable* cur = nox_drawable_2d_index[v3][v6];
                    if (cur) {
                        do
                        {
                            draw_fnc(cur, a3);
                            cur = cur->field_100;
                        } while (cur);
                        v5 = v9;
                    }
                    ++v3;
                } while (v3 <= v8);
            }
            if (++v6 > v5)
                break;
            v3 = v10;
        }
    }
}

//----- (0049ABF0) --------------------------------------------------------
_DWORD* __cdecl sub_49ABF0(_DWORD* a1, int a2)
{
    int v2; // ecx
    _DWORD* v3; // edi
    int v4; // ebx
    int v5; // esi
    int v6; // ebp
    int v7; // esi
    int v8; // eax
    int v9; // edx
    int v10; // ebp
    _DWORD* v11; // esi
    int v12; // eax
    int v13; // eax
    _DWORD* v15; // [esp+10h] [ebp-10h]
    int v16; // [esp+14h] [ebp-Ch]
    int i; // [esp+18h] [ebp-8h]
    int v18; // [esp+1Ch] [ebp-4h]
    int v19; // [esp+24h] [ebp+4h]
    int v20; // [esp+24h] [ebp+4h]
    int v21; // [esp+28h] [ebp+8h]

    v2 = a2;
    v3 = a1;
    v18 = a2 * a2;
    v4 = 999999999;
    v5 = *a1;
    v15 = 0;
    v16 = (*a1 - a2) / 128;
    if (v16 < 0)
        v16 = 0;
    v19 = a1[1];
    v6 = (v19 - a2) / 128;
    if (v6 < 0)
        v6 = 0;
    v7 = (v5 + a2) / 128;
    v21 = v7;
    if (v7 >= nox_drawable_2d_index_size)
    {
        v21 = nox_drawable_2d_index_size - 1;
        v7 = nox_drawable_2d_index_size - 1;
    }
    v8 = (v2 + v19) / 128;
    v20 = v8;
    if (v8 >= nox_drawable_2d_index_size)
    {
        v20 = nox_drawable_2d_index_size - 1;
        v8 = nox_drawable_2d_index_size - 1;
    }
    v9 = v6;
    for (i = v6; v9 <= v8; i = v9)
    {
        v10 = v16;
        if (v16 <= v7)
        {
            do
            {
                v11 = nox_drawable_2d_index[v10][v9];
                if (v11)
                {
                    do
                    {
                        if (sub_4984B0_drawable((int)v11))
                        {
                            v12 = v3[1] - v11[4];
                            v13 = (*v3 - v11[3]) * (*v3 - v11[3]) + v12 * v12;
                            if (v13 < v4 && v13 < v18)
                            {
                                v4 = v13;
                                v15 = v11;
                            }
                        }
                        v11 = (_DWORD*)v11[100];
                    } while (v11);
                    v8 = v20;
                    v9 = i;
                }
                ++v10;
            } while (v10 <= v21);
            v7 = v21;
        }
        ++v9;
    }
    return v15;
}

//----- (0049AD20) --------------------------------------------------------
int __cdecl sub_49AD20(_DWORD* a1, int a2)
{
    int v2; // ecx
    int v3; // eax
    int v4; // ebp
    int v5; // ecx
    int v6; // ebx
    int v7; // edi
    _DWORD* v8; // esi
    int result; // eax
    int v10; // [esp+14h] [ebp+4h]

    v2 = *a1 / 128;
    v3 = a1[1] / 128;
    v4 = (v2 - 1) & ((v2 - 1 < 0) - 1);
    v5 = v2 + 1;
    if (v5 >= nox_drawable_2d_index_size - 1)
        v5 = nox_drawable_2d_index_size - 1;
    v10 = v3 + 1;
    if (v3 + 1 >= nox_drawable_2d_index_size - 1)
        v10 = nox_drawable_2d_index_size - 1;
    v6 = v3 - 1 < 0 ? 0 : v3 - 1;
    if (v6 > v10)
        return 0;
    while (1)
    {
        v7 = v4;
        if (v4 <= v5)
            break;
        LABEL_12:
        if (++v6 > v10)
            return 0;
    }
    v8 = &nox_drawable_2d_index[v4];
    while (1)
    {
        result = *(_DWORD*)(*v8 + 4 * v6);
        if (result)
            break;
        LABEL_11:
        ++v7;
        ++v8;
        if (v7 > v5)
            goto LABEL_12;
    }
    while (*(_DWORD*)(result + 128) != a2)
    {
        result = *(_DWORD*)(result + 400);
        if (!result)
            goto LABEL_11;
    }
    return result;
}

//----- (0049ADD0) --------------------------------------------------------
int __cdecl sub_49ADD0(int a1)
{
    _DWORD* v2; // eax
    int v3; // ecx

    *(_DWORD*)& byte_5D4594[1301844] = 0;
    *(_DWORD*)& byte_5D4594[1301848] = 0;
    *(_DWORD*)& byte_5D4594[1301824] = 0;
    *(_DWORD*)& byte_5D4594[1301832] = 0;
    *(_DWORD*)& byte_5D4594[1301800] = 0;
    *(_DWORD*)& byte_5D4594[1301828] = 0;
    *(_DWORD*)& byte_5D4594[1301840] = 0;
    *(_DWORD*)& byte_5D4594[1301792] = 0;
    *(_DWORD*)& byte_5D4594[1301836] = 0;
    *(_DWORD*)& byte_5D4594[1301812] = 0;
    *(_DWORD*)& byte_5D4594[1301804] = 0;
    *(_DWORD*)& byte_5D4594[1301816] = 0;
    *(_DWORD*)& byte_5D4594[1301808] = 0;
    *(_DWORD*)& byte_5D4594[1301796] = 0;
    *(_DWORD*)& byte_5D4594[1301820] = a1;
    *(_DWORD*)& byte_5D4594[1301844] = nox_new_alloc_class("PixelSpan", 12, a1);
    if (!*(_DWORD*)& byte_5D4594[1301844])
        return 0;
    *(_DWORD*)& byte_5D4594[1301824] = nox_win_height;
    v2 = nox_malloc(4 * nox_win_height);
    *(_DWORD*)& byte_5D4594[1301848] = v2;
    if (!v2)
        return 0;
    v3 = 0;
    if (*(_DWORD*)& byte_5D4594[1301824] > 0)
    {
        while (1)
        {
            v2[v3++] = 0;
            if (v3 >= *(int*)& byte_5D4594[1301824])
                break;
            v2 = *(_DWORD * *)& byte_5D4594[1301848];
        }
    }
    return 1;
}

//----- (0049AEA0) --------------------------------------------------------
int sub_49AEA0()
{
    if (*(_DWORD*)& byte_5D4594[1301844])
    {
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1301844]);
        *(_DWORD*)& byte_5D4594[1301844] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1301848])
    {
        free(*(LPVOID*)& byte_5D4594[1301848]);
        *(_DWORD*)& byte_5D4594[1301848] = 0;
    }
    return 1;
}

//----- (0049AEE0) --------------------------------------------------------
void sub_49AEE0()
{
    int v0; // edx
    unsigned int v1; // ecx
    int v2; // eax

    v0 = 0;
    *(_DWORD*)& byte_5D4594[1301792] = 0;
    *(_DWORD*)& byte_5D4594[1301812] = 0;
    *(_DWORD*)& byte_5D4594[1301816] = 0;
    *(_DWORD*)& byte_5D4594[1301796] = 0;
    if (*(_DWORD*)& byte_5D4594[1301824] > 0)
    {
        do
        {
            v1 = 0;
            *(_DWORD*)& byte_5D4594[1301808] = 0;
            v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * v0);
            if (v2)
            {
                do
                {
                    *(_DWORD*)& byte_5D4594[1301808] = ++v1;
                    v2 = *(_DWORD*)(v2 + 8);
                } while (v2);
                if (v1 > * (int*)& byte_5D4594[1301816])
                {
                    *(_DWORD*)& byte_5D4594[1301816] = v1;
                    *(_DWORD*)& byte_5D4594[1301796] = v0;
                }
            }
            ++v0;
            *(_DWORD*)& byte_5D4594[1301812] += v1;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * v0 - 4) = 0;
        } while (v0 < *(int*)& byte_5D4594[1301824]);
        if (*(_DWORD*)& byte_5D4594[1301812] > * (int*)& byte_5D4594[1301804])
            * (_DWORD*)& byte_5D4594[1301804] = *(_DWORD*)& byte_5D4594[1301812];
    }
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1301844]);
}

//----- (0049AF80) --------------------------------------------------------
int* __cdecl sub_49AF80(int a1, int a2, int a3)
{
    int* result; // eax
    int v4; // edx
    int* v5; // esi

    *(_DWORD*)& byte_5D4594[1301836] = a1;
    if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * a1))
    {
        result = *(int**)& byte_5D4594[1301800];
        if (*(_DWORD*)& byte_5D4594[1301832])
        {
            if (*(_DWORD*)& byte_5D4594[1301832] != *(_DWORD*)& byte_5D4594[1301800])
            {
                if (*(_DWORD*)& byte_5D4594[1301800])
                    v4 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301800] + 4);
                else
                    v4 = a3;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301832] + 4) = v4;
                result = (int*)sub_49B1D0(*(int*)& byte_5D4594[1301832], *(int*)& byte_5D4594[1301840]);
            }
        }
        else if (*(_DWORD*)& byte_5D4594[1301800])
        {
            **(_DWORD * *)& byte_5D4594[1301800] = a2;
            result = (int*)sub_49B1D0(*(int*)& byte_5D4594[1301828], *(int*)& byte_5D4594[1301800]);
        }
        else
        {
            result = (int*)nox_alloc_class_new_obj(*(_DWORD * *)& byte_5D4594[1301844]);
            v5 = result;
            if (result)
            {
                *result = a2;
                result[1] = a3;
                sub_49B1D0(*(int*)& byte_5D4594[1301828], *(int*)& byte_5D4594[1301840]);
                result = *(int**)& byte_5D4594[1301828];
                if (*(_DWORD*)& byte_5D4594[1301828])
                {
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301828] + 8) = v5;
                }
                else
                {
                    result = *(int**)& byte_5D4594[1301848];
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]) = v5;
                }
                v5[2] = *(_DWORD*)& byte_5D4594[1301840];
            }
        }
    }
    else
    {
        result = (int*)nox_alloc_class_new_obj(*(_DWORD * *)& byte_5D4594[1301844]);
        if (result)
        {
            *result = a2;
            result[1] = a3;
            result[2] = 0;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]) = result;
        }
    }
    return result;
}

//----- (0049B0A0) --------------------------------------------------------
int __cdecl sub_49B0A0(int a1, int a2, int a3)
{
    int* v3; // eax
    int* v5; // ecx
    int* v6; // eax

    if (*(_DWORD*)& byte_5D4594[1301792])
    {
        sub_49B1A0(*(int*)& byte_5D4594[1301792]);
        *(_DWORD*)& byte_5D4594[1301792] = 0;
    }
    *(_DWORD*)& byte_5D4594[1301836] = a1;
    v3 = (int*)nox_alloc_class_new_obj(*(_DWORD * *)& byte_5D4594[1301844]);
    *(_DWORD*)& byte_5D4594[1301792] = v3;
    if (!v3)
        return 0;
    *v3 = a2;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301792] + 4) = a3;
    v5 = 0;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301792] + 8) = 0;
    *(_DWORD*)& byte_5D4594[1301832] = 0;
    *(_DWORD*)& byte_5D4594[1301828] = 0;
    v6 = *(int**)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]);
    if (!v6)
        goto LABEL_22;
    do
    {
        if (*v6 > a2)
            break;
        if (v6[1] + 1 >= a2)
        {
            *(_DWORD*)& byte_5D4594[1301832] = v6;
            goto LABEL_13;
        }
        v5 = v6;
        *(_DWORD*)& byte_5D4594[1301828] = v6;
        v6 = (int*)v6[2];
    } while (v6);
    v6 = v5;
    if (!v5)
        LABEL_22:
        v6 = *(int**)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]);
    LABEL_13:
    *(_DWORD*)& byte_5D4594[1301800] = 0;
    *(_DWORD*)& byte_5D4594[1301840] = 0;
    if (v6)
    {
        while (*v6 - 1 <= a3)
        {
            if (v6[1] >= a3)
            {
                *(_DWORD*)& byte_5D4594[1301800] = v6;
                v6 = (int*)v6[2];
                break;
            }
            v6 = (int*)v6[2];
            if (!v6)
            {
                *(_DWORD*)& byte_5D4594[1301840] = 0;
                return sub_49B260();
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1301840] = v6;
    return sub_49B260();
}

//----- (0049B1A0) --------------------------------------------------------
int __cdecl sub_49B1A0(int a1)
{
    int result; // eax
    int v2; // esi

    result = a1;
    if (a1)
    {
        do
        {
            v2 = *(_DWORD*)(result + 8);
            sub_414330(*(unsigned int**)& byte_5D4594[1301844], (_QWORD*)result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (0049B1D0) --------------------------------------------------------
int __cdecl sub_49B1D0(int a1, int a2)
{
    int* v2; // ecx
    int result; // eax

    if (a1)
    {
        for (result = *(_DWORD*)(a1 + 8); result; result = *(_DWORD*)(a1 + 8))
        {
            if (result == a2)
                break;
            *(_DWORD*)(a1 + 8) = *(_DWORD*)(result + 8);
            sub_414330(*(unsigned int**)& byte_5D4594[1301844], (_QWORD*)result);
        }
    }
    else
    {
        v2 = (int*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]);
        for (result = *v2; result; v2 = (int*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]))
        {
            if (result == a2)
                break;
            *v2 = *(_DWORD*)(result + 8);
            sub_414330(*(unsigned int**)& byte_5D4594[1301844], (_QWORD*)result);
            result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]);
        }
    }
    return result;
}

//----- (0049B260) --------------------------------------------------------
int sub_49B260()
{
    int* v0; // edi
    int* v1; // ebx
    int* v3; // esi
    int v4; // ebp
    int* v5; // eax
    int v6; // edx

    if (*(_DWORD*)& byte_5D4594[1301832])
    {
        if (*(_DWORD*)& byte_5D4594[1301832] == *(_DWORD*)& byte_5D4594[1301800])
            return 0;
        **(_DWORD * *)& byte_5D4594[1301792] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301832] + 4) + 1;
        v0 = *(int**)(*(_DWORD*)& byte_5D4594[1301832] + 8);
        if (*(_DWORD*)& byte_5D4594[1301800])
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301792] + 4) = **(_DWORD * *)& byte_5D4594[1301800] - 1;
            v1 = *(int**)& byte_5D4594[1301800];
            goto LABEL_11;
        }
        LABEL_10:
        v1 = *(int**)& byte_5D4594[1301840];
        goto LABEL_11;
    }
    v0 = *(int**)& byte_5D4594[1301828];
    if (!*(_DWORD*)& byte_5D4594[1301828])
        v0 = *(int**)(*(_DWORD*)& byte_5D4594[1301848] + 4 * *(_DWORD*)& byte_5D4594[1301836]);
    if (!*(_DWORD*)& byte_5D4594[1301800])
        goto LABEL_10;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301792] + 4) = **(_DWORD * *)& byte_5D4594[1301800] - 1;
    v1 = *(int**)& byte_5D4594[1301800];
    LABEL_11:
    v3 = *(int**)& byte_5D4594[1301792];
    v4 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1301792] + 4);
    if (v0 != v1)
    {
        while (*v0 <= v4)
        {
            if (*v0 >= *v3)
            {
                v5 = (int*)nox_alloc_class_new_obj(*(_DWORD * *)& byte_5D4594[1301844]);
                if (!v5)
                {
                    sub_49B1A0(*(int*)& byte_5D4594[1301792]);
                    *(_DWORD*)& byte_5D4594[1301792] = 0;
                    return 0;
                }
                *v5 = v0[1] + 1;
                v5[1] = v3[1];
                v5[2] = 0;
                v6 = *v0;
                v3[2] = (int)v5;
                v3[1] = v6 - 1;
                v3 = v5;
            }
            v0 = (int*)v0[2];
            if (v0 == v1)
                return *(_DWORD*)& byte_5D4594[1301792];
        }
    }
    return *(_DWORD*)& byte_5D4594[1301792];
}

//----- (0049B370) --------------------------------------------------------
int sub_49B370()
{
    return *(_DWORD*)& byte_5D4594[1301796];
}

//----- (0049B380) --------------------------------------------------------
int sub_49B380()
{
    return *(_DWORD*)& byte_5D4594[1301816];
}

//----- (0049B3A0) --------------------------------------------------------
int sub_49B3A0()
{
    return *(_DWORD*)& byte_5D4594[1301812];
}

//----- (0049B3B0) --------------------------------------------------------
int sub_49B3B0()
{
    return *(_DWORD*)& byte_5D4594[1301820];
}

//----- (0049B3C0) --------------------------------------------------------
int sub_49B3C0()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[1301812] = 0;
    *(_DWORD*)& byte_5D4594[1301816] = 0;
    *(_DWORD*)& byte_5D4594[1301808] = 0;
    *(_DWORD*)& byte_5D4594[1301796] = 0;
    return result;
}

//----- (0049B3E0) --------------------------------------------------------
int sub_49B3E0()
{
    int result; // eax

    result = nox_new_window_from_file("GGOver.wnd", sub_49B420);
    *(_DWORD*)& byte_5D4594[1303452] = result;
    if (result)
    {
        nox_window_set_hidden(result, 1);
        sub_46ABB0(*(int*)& byte_5D4594[1303452], 0);
        result = 1;
    }
    return result;
}

//----- (0049B420) --------------------------------------------------------
int __cdecl sub_49B420(int a1, int a2, int* a3, int a4)
{
    int v3; // esi

    if (a2 == 16391)
    {
        v3 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        if (v3 == 10701)
        {
            sub_4460C0();
            sub_49B6B0();
        }
        else if (v3 == 10702)
        {
            LOWORD(a2) = 1008;
            sub_4E53C0(31, &a2, 2, 0, 1);
            sub_49B6B0();
            return 0;
        }
    }
    return 0;
}

//----- (0049B490) --------------------------------------------------------
int sub_49B490()
{
    int result; // eax

    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1303452]);
    *(_DWORD*)& byte_5D4594[1303452] = 0;
    return result;
}

//----- (0049B4B0) --------------------------------------------------------
int __cdecl sub_49B4B0(unsigned __int16* a1)
{
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    int result; // eax
    int v11; // [esp-4h] [ebp-10h]
    int v12; // [esp-4h] [ebp-10h]
    int v13; // [esp-4h] [ebp-10h]
    int v14; // [esp+4h] [ebp-8h]
    int v15; // [esp+8h] [ebp-4h]

    nox_window_set_hidden(*(int*)& byte_5D4594[1303452], 0);
    sub_46ABB0(*(int*)& byte_5D4594[1303452], 1);
    sub_452D80(1007, 100);
    nox_window_get_size(*(int*)& byte_5D4594[1303452], &v15, &v14);
    sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1303452],
            nox_win_width / 2 - v15 / 2,
            nox_win_height / 2 - v14 / 2);
    v11 = a1[1];
    v1 = loadString_sub_40F1D0((char*)& byte_587000[163344], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 178);
    nox_swprintf((wchar_t*)& byte_5D4594[1302172], v1, v11);
    v12 = a1[2];
    v2 = loadString_sub_40F1D0((char*)& byte_587000[163416], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 181);
    nox_swprintf((wchar_t*)& byte_5D4594[1301916], v2, v12);
    v13 = a1[3];
    v3 = loadString_sub_40F1D0((char*)& byte_587000[163484], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 183);
    nox_swprintf((wchar_t*)& byte_5D4594[1302428], v3, v13);
    nox_swprintf((wchar_t*)& byte_5D4594[1303196], (const wchar_t*)& byte_5D4594[1303460]);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10710);
    sub_46AEE0((int)v4, (int)& byte_5D4594[1302172]);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10705);
    sub_46AEE0((int)v5, (int)& byte_5D4594[1302940]);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10706);
    sub_46AEE0((int)v6, (int)& byte_5D4594[1302684]);
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10707);
    sub_46AEE0((int)v7, (int)& byte_5D4594[1301916]);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10708);
    sub_46AEE0((int)v8, (int)& byte_5D4594[1302428]);
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10711);
    sub_46AEE0((int)v9, (int)& byte_5D4594[1303196]);
    result = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)& byte_5D4594[1303456] = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (0049B6B0) --------------------------------------------------------
int sub_49B6B0()
{
    nox_window_set_hidden(*(int*)& byte_5D4594[1303452], 1);
    sub_46ABB0(*(int*)& byte_5D4594[1303452], 0);
    return sub_46B500(0);
}

//----- (0049B6E0) --------------------------------------------------------
int sub_49B6E0()
{
    int result; // eax
    int v1; // eax
    wchar_t* v2; // eax
    _DWORD* v3; // eax
    int v4; // [esp-4h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1303452];
    if (*(_DWORD*)& byte_5D4594[1303452])
    {
        result = wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1303452]);
        if (!result)
        {
            v1 = *(_DWORD*)& byte_5D4594[1303456] + 30 * *(_DWORD*)& byte_5D4594[2649704] - *(_DWORD*)& byte_5D4594[2598000];
            if (v1 < 0)
                v1 = 0;
            if (*(_DWORD*)& byte_5D4594[2618908] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2064) == 31)
            {
                nox_wcscpy((wchar_t*)& byte_5D4594[1301852], (const wchar_t*)& byte_5D4594[1303464]);
            }
            else
            {
                v4 = (unsigned int)v1 / *(_DWORD*)& byte_5D4594[2649704];
                v2 = loadString_sub_40F1D0((char*)& byte_587000[163544], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIGGOvr.c", 265);
                nox_swprintf((wchar_t*)& byte_5D4594[1301852], L"%s - %d", v2, v4);
            }
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1303452], 10712);
            result = sub_46AEE0((int)v3, (int)& byte_5D4594[1301852]);
        }
    }
    return result;
}

//----- (0049B7A0) --------------------------------------------------------
void sub_49B7A0()
{
    int v0; // esi

    v0 = 0;
    if (!sub_477600() && !sub_44E0D0())
    {
        if (sub_460660())
            v0 = 1;
        if (!sub_46A6A0() && v0 != 1)
        {
            if (sub_45D9B0() == 1)
            {
                sub_45D870();
            }
            else
            {
                if (sub_4BFE40())
                    v0 = 1;
                if (sub_4606B0())
                    v0 = 1;
                if (sub_462740())
                    v0 = 1;
                if (!sub_44A4E0() && v0 != 1)
                {
                    if (sub_479590() == 2)
                    {
                        sub_4795A0(1);
                    }
                    else if (sub_479590() == 3)
                    {
                        sub_4795A0(1);
                    }
                    else if (sub_479590() == 4)
                    {
                        sub_4795A0(1);
                    }
                    else if (!sub_478040() && !sub_479950())
                    {
                        if (sub_467C10())
                            v0 = 1;
                        if (sub_45ACA0(0))
                            v0 = 1;
                        if (sub_4512B0())
                            v0 = 1;
                        if (sub_446780())
                            v0 = 1;
                        if (sub_4574D0())
                            v0 = 1;
                        if (sub_48CAD0())
                            v0 = 1;
                        if (sub_4AD9B0(1))
                            v0 = 1;
                        if (sub_4C35B0(1))
                            v0 = 1;
                        if (!sub_46D6F0() && v0 != 1)
                        {
                            if (sub_4DCCB0())
                                sub_445C40();
                            else
                                sub_452D80(231, 100);
                        }
                    }
                }
            }
        }
    }
}
// 49B874: variable 'v1' is possibly undefined
// 49B881: variable 'v2' is possibly undefined

//----- (0049B950) --------------------------------------------------------
_DWORD* __cdecl sub_49B950(_DWORD* a1, int a2)
{
    unsigned int v2; // edx
    _DWORD* result; // eax
    _DWORD* v4; // ecx
    int v5; // ecx

    if (a1[89])
        sub_49BA10(a1);
    v2 = *(_DWORD*)& byte_5D4594[2598000] + a2;
    a1[89] = *(_DWORD*)& byte_5D4594[2598000] + a2;
    result = *(_DWORD * *)& byte_5D4594[1303468];
    if (*(_DWORD*)& byte_5D4594[1303468])
    {
        v4 = 0;
        while (result[89] < v2)
        {
            v4 = result;
            result = (_DWORD*)result[87];
            if (!result)
                goto LABEL_10;
        }
        if (!result)
        {
            LABEL_10:
            v4[87] = a1;
            a1[87] = 0;
            a1[88] = v4;
            return result;
        }
        a1[87] = result;
        a1[88] = result[88];
        v5 = result[88];
        if (v5)
            * (_DWORD*)(v5 + 348) = a1;
        else
            *(_DWORD*)& byte_5D4594[1303468] = a1;
        result[88] = a1;
    }
    else
    {
        a1[87] = *(_DWORD*)& byte_5D4594[1303468];
        a1[88] = result;
        *(_DWORD*)& byte_5D4594[1303468] = a1;
    }
    return result;
}

//----- (0049BA10) --------------------------------------------------------
_DWORD* __cdecl sub_49BA10(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    if (a1[89])
    {
        v2 = a1[88];
        if (v2)
            * (_DWORD*)(v2 + 348) = a1[87];
        else
            *(_DWORD*)& byte_5D4594[1303468] = a1[87];
        v3 = a1[87];
        if (v3)
            * (_DWORD*)(v3 + 352) = a1[88];
        a1[89] = 0;
    }
    return result;
}

//----- (0049BA70) --------------------------------------------------------
int sub_49BA70()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[1303468];
    if (*(_DWORD*)& byte_5D4594[1303468])
    {
        do
        {
            v1 = *(_DWORD*)(result + 348);
            if (*(_DWORD*)(result + 356) > * (int*)& byte_5D4594[2598000])
                break;
            sub_45A4E0_drawable(result);
            result = v1;
        } while (v1);
    }
    return result;
}

//----- (0049BAB0) --------------------------------------------------------
_DWORD* __cdecl sub_49BAB0_drawable(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    a1[84] = 0;
    a1[83] = *(_DWORD*)& byte_5D4594[1303472];
    if (*(_DWORD*)& byte_5D4594[1303472])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1303472] + 336) = a1;
    *(_DWORD*)& byte_5D4594[1303472] = a1;
    a1[30] |= 0x200000u;
    return result;
}

//----- (0049BAF0) --------------------------------------------------------
_DWORD* __cdecl sub_49BAF0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    if (a1[30] & 0x200000)
    {
        v2 = a1[84];
        if (v2)
            * (_DWORD*)(v2 + 332) = a1[83];
        else
            *(_DWORD*)& byte_5D4594[1303472] = a1[83];
        v3 = a1[83];
        if (v3)
            * (_DWORD*)(v3 + 336) = a1[84];
        a1[30] &= 0xFFDFFFFF;
    }
    return result;
}

//----- (0049BB40) --------------------------------------------------------
void sub_49BB40()
{
    int v0; // esi
    int v1; // edi

    v0 = *(_DWORD*)& byte_5D4594[1303472];
    if (*(_DWORD*)& byte_5D4594[1303472])
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 332);
            if (*(_DWORD*)(v0 + 340) < (unsigned int)sub_435590())
                sub_45A4E0_drawable(v0);
            v0 = v1;
        } while (v1);
    }
}

//----- (0049BB80) --------------------------------------------------------
void* __cdecl sub_49BB80(char a1)
{
    void* result; // eax

    byte_5D4594[1303504] = a1;
    byte_5D4594[1303512] = 0;
    *(_DWORD*)& byte_5D4594[1303516] = *(_DWORD*)& byte_5D4594[2598000];
    result = sub_424820();
    *(_DWORD*)& byte_5D4594[1303508] = result;
    return result;
}

//----- (0049BBB0) --------------------------------------------------------
void sub_49BBB0()
{
    byte_5D4594[1303504] = 0;
}

//----- (0049BBC0) --------------------------------------------------------
void sub_49BBC0()
{
    int v0; // eax
    unsigned __int8 v1; // [esp+0h] [ebp-4h]

    if (byte_5D4594[1303504])
    {
        v1 = sub_424A20(byte_5D4594[1303504])[byte_5D4594[1303512]];
        if (*(_DWORD*)& byte_5D4594[2598000] >= *(int*)& byte_5D4594[1303516])
        {
            v0 = sub_4FE1C0(*(int*)& byte_5D4594[2616328], v1);
            sub_452D80(v0, 100);
            sub_476E00(*(_DWORD*)& byte_587000[4 * v1 + 163576]);
            *(_DWORD*)& byte_5D4594[1303516] = *(_DWORD*)& byte_5D4594[2598000] + 3;
            *(_DWORD*)& byte_5D4594[1303508] = sub_424830(*(int*)& byte_5D4594[1303508], v1);
            ++byte_5D4594[1303512];
        }
        if (**(_DWORD * *)& byte_5D4594[1303508] == byte_5D4594[1303504])
            sub_49BBB0();
    }
}

//----- (0049BC80) --------------------------------------------------------
_DWORD* __cdecl sub_49BC80_drawable(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    if (!a1[96])
    {
        a1[95] = 0;
        a1[94] = *(_DWORD*)& byte_5D4594[1303536];
        if (*(_DWORD*)& byte_5D4594[1303536])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1303536] + 380) = a1;
        *(_DWORD*)& byte_5D4594[1303536] = a1;
        a1[96] = 1;
    }
    return result;
}

//----- (0049BCD0) --------------------------------------------------------
_DWORD* __cdecl sub_49BCD0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx
    int v4; // ecx

    result = a1;
    if (a1[96])
    {
        v2 = a1[95];
        if (v2)
        {
            *(_DWORD*)(v2 + 376) = a1[94];
            v3 = a1[94];
            if (v3)
            {
                *(_DWORD*)(v3 + 380) = a1[95];
                a1[96] = 0;
                return result;
            }
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1303536] = a1[94];
            v4 = a1[94];
            if (v4)
                * (_DWORD*)(v4 + 380) = 0;
        }
        a1[96] = 0;
    }
    return result;
}

//----- (0049BD40) --------------------------------------------------------
int sub_49BD40()
{
    return *(_DWORD*)& byte_5D4594[1303536];
}

//----- (0049BD50) --------------------------------------------------------
int __cdecl sub_49BD50(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 376);
    else
        result = 0;
    return result;
}

//----- (0049BD70) --------------------------------------------------------
int(__cdecl* __cdecl sub_49BD70(int a1))(int, int)
{
    int result; // eax
    int(__cdecl * result2)(int, int); // eax
    int v2; // esi
    int v3; // edi
    int(__cdecl * v4)(int, _DWORD); // eax

    result = sub_413A50();
    if (result != 1)
    {
        result = sub_49BD40();
        v2 = result;
        if (result)
        {
            do
            {
                v3 = sub_49BD50(v2);
                v4 = (int(__cdecl*)(int, _DWORD)) * ((_DWORD*)v2 + 116);
                if (!v4 || (result = v4(a1, v2)) != 0)
                {
                    result2 = (int(__cdecl*)(int, int)) * ((_DWORD*)v2 + 115);
                    if (result2)
                        result = result2(a1, (int)v2);
                    else
                        result = 0;
                }
                v2 = v3;
            } while (v3);
        }
    }
    return result;
}

//----- (0049BDD0) --------------------------------------------------------
int __cdecl sub_49BDD0(unsigned __int8* a1)
{
    int result; // eax
    unsigned __int8* v2; // esi
    unsigned __int8* v3; // edi
    int v4; // ebx
    int v5; // ebp
    int v6; // eax
    int v7; // ecx
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // ecx
    int v12; // [esp-Ch] [ebp-28h]
    int v13; // [esp-Ch] [ebp-28h]
    int v14; // [esp-Ch] [ebp-28h]
    int v15; // [esp-Ch] [ebp-28h]
    char v16; // [esp+10h] [ebp-Ch]
    char v17; // [esp+10h] [ebp-Ch]
    char v18; // [esp+10h] [ebp-Ch]
    WORD v19[4]; // [esp+14h] [ebp-8h]
    int v20; // [esp+20h] [ebp+4h]

    result = *(_DWORD*)& byte_5D4594[1304308];
    if (*(int*)& byte_5D4594[1304308] < 96)
    {
        if (!*(_DWORD*)& byte_5D4594[1304316])
        {
            *(_DWORD*)& byte_5D4594[1304316] = sub_44CFC0((CHAR*)& byte_587000[163612]);
            *(_DWORD*)& byte_5D4594[1304320] = sub_44CFC0((CHAR*)& byte_587000[163632]);
            *(_DWORD*)& byte_5D4594[1304324] = sub_44CFC0((CHAR*)& byte_587000[163656]);
            *(_DWORD*)& byte_5D4594[1304348] = sub_44CFC0((CHAR*)& byte_587000[163676]);
            *(_DWORD*)& byte_5D4594[1304328] = sub_44CFC0((CHAR*)& byte_587000[163688]);
            *(_DWORD*)& byte_5D4594[1304332] = sub_44CFC0((CHAR*)& byte_587000[163696]);
            *(_DWORD*)& byte_5D4594[1304336] = sub_44CFC0((CHAR*)& byte_587000[163708]);
            *(_DWORD*)& byte_5D4594[1304340] = sub_44CFC0((CHAR*)& byte_587000[163724]);
            *(_DWORD*)& byte_5D4594[1304344] = sub_44CFC0((CHAR*)& byte_587000[163732]);
        }
        v2 = a1;
        v3 = a1 + 1;
        v4 = *(unsigned __int16*)(a1 + 1) + (*(unsigned __int16*)(a1 + 5) - *(unsigned __int16*)(a1 + 1)) / 2;
        result = *a1 - 125;
        v5 = *(unsigned __int16*)(a1 + 3) + (*(unsigned __int16*)(a1 + 7) - *(unsigned __int16*)(a1 + 3)) / 2;
        switch (*a1)
        {
            case 0x7Du:
                v20 = *(_DWORD*)& byte_5D4594[1304332];
                goto LABEL_17;
            case 0x8Cu:
                v20 = *(_DWORD*)& byte_5D4594[1304316];
                goto LABEL_17;
            case 0x8Du:
                v20 = *(_DWORD*)& byte_5D4594[1304324];
                goto LABEL_17;
            case 0x8Eu:
                v20 = *(_DWORD*)& byte_5D4594[1304320];
                goto LABEL_17;
            case 0x8Fu:
                v18 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 137);
                v20 = *(_DWORD*)& byte_5D4594[1304328];
                if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 140) < 50)
                {
                    v15 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 143);
                    v10 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 142);
                    sub_499490(*(int*)& byte_5D4594[1304336], v3, v10, v15, v18, 0);
                }
                goto LABEL_17;
            case 0x90u:
                v16 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 101);
                v20 = *(_DWORD*)& byte_5D4594[1304328];
                if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 104) < 50)
                {
                    v12 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 107);
                    v6 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 106);
                    sub_499490(*(int*)& byte_5D4594[1304344], v3, v6, v12, v16, 0);
                }
                v7 = *(_DWORD*)v3;
                *(_DWORD*)v19 = *(_DWORD*)(v2 + 5);
                *(_DWORD*)& v19[2] = v7;
                if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 112) < 50)
                {
                    v13 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 115);
                    v8 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 114);
                    sub_499490(*(int*)& byte_5D4594[1304344], v19, v8, v13, v16, 0);
                }
                goto LABEL_17;
            case 0x91u:
                v17 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 123);
                v20 = *(_DWORD*)& byte_5D4594[1304328];
                if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 126) < 50)
                {
                    v14 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 129);
                    v9 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 128);
                    sub_499490(*(int*)& byte_5D4594[1304340], v3, v9, v14, v17, 0);
                }
            LABEL_17:
                result = sub_45A360_drawable(v20, v4, v5);
                if (result)
                {
                    *(_BYTE*)(result + 432) = 0;
                    *(_DWORD*)(result + 437) = *(_DWORD*)v3;
                    *(_DWORD*)(result + 441) = *((_DWORD*)v3 + 1);
                    v11 = *(_DWORD*)& byte_5D4594[1304308];
                    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1304308] + 1303540] = result;
                    *(_DWORD*)& byte_5D4594[1304308] = v11 + 1;
                }
                break;
            default:
                return result;
        }
    }
    return result;
}

//----- (0049C160) --------------------------------------------------------
_DWORD* __cdecl sub_49C160(int a1)
{
    _DWORD* result; // eax
    int v2; // eax
    int v3; // esi
    int v4; // eax
    int v5; // ebx
    _DWORD* v6; // eax
    _DWORD* v7; // edi
    int v8; // esi
    int v9; // edi
    int v10; // kr00_4
    int v11; // ecx
    int v12; // edx
    int v13; // edx
    unsigned __int8* v14; // ecx

    result = *(_DWORD * *)& byte_5D4594[1304312];
    if (*(int*)& byte_5D4594[1304312] < 96)
    {
        if (!*(_DWORD*)& byte_5D4594[1304352])
        {
            *(_DWORD*)& byte_5D4594[1304352] = sub_44CFC0((CHAR*)& byte_587000[164344]);
            *(_DWORD*)& byte_5D4594[1304356] = sub_44CFC0((CHAR*)& byte_587000[164364]);
            *(_DWORD*)& byte_5D4594[1304360] = sub_44CFC0((CHAR*)& byte_587000[164388]);
            *(_DWORD*)& byte_5D4594[1304364] = sub_44CFC0((CHAR*)& byte_587000[164408]);
            *(_DWORD*)& byte_5D4594[1304368] = sub_44CFC0((CHAR*)& byte_587000[164416]);
            *(_DWORD*)& byte_5D4594[1304372] = sub_44CFC0((CHAR*)& byte_587000[164428]);
            *(_DWORD*)& byte_5D4594[1304376] = sub_44CFC0((CHAR*)& byte_587000[164444]);
            *(_DWORD*)& byte_5D4594[1304380] = sub_44CFC0((CHAR*)& byte_587000[164452]);
            *(_DWORD*)& byte_5D4594[1304384] = sub_44CFC0((CHAR*)& byte_587000[164464]);
            *(_DWORD*)& byte_5D4594[1304388] = sub_44CFC0((CHAR*)& byte_587000[164480]);
            *(_DWORD*)& byte_5D4594[1304392] = sub_44CFC0((CHAR*)& byte_587000[164488]);
            *(_DWORD*)& byte_5D4594[1304396] = sub_44CFC0((CHAR*)& byte_587000[164500]);
        }
        v2 = sub_578B30(*(_WORD*)(a1 + 3));
        v3 = v2;
        v4 = sub_578B30(*(_WORD*)(a1 + 5));
        v5 = v4;
        v6 = sub_578B70(*(unsigned __int16*)(a1 + 3)) ? sub_45A720(v3) : sub_45A6F0(v3);
        v7 = v6;
        result = sub_578B70(*(unsigned __int16*)(a1 + 5)) ? sub_45A720(v5) : sub_45A6F0(v5);
        if (v7 && result)
        {
            v8 = v7[3];
            v9 = v7[4];
            v10 = result[4] - v9;
            v11 = v8 + ((int)result[3] - v8) / 2;
            result = (_DWORD*)(v9 + v10 / 2);
            switch (*(unsigned __int8*)(a1 + 1))
            {
                case 1u:
                    v12 = *(_DWORD*)& byte_5D4594[1304368];
                    goto LABEL_21;
                case 2u:
                    v12 = *(_DWORD*)& byte_5D4594[1304380];
                    goto LABEL_21;
                case 3u:
                    v12 = *(_DWORD*)& byte_5D4594[1304356];
                    goto LABEL_21;
                case 4u:
                    v12 = *(_DWORD*)& byte_5D4594[1304360];
                    goto LABEL_21;
                case 5u:
                    v12 = *(_DWORD*)& byte_5D4594[1304372];
                    goto LABEL_21;
                case 6u:
                    v12 = *(_DWORD*)& byte_5D4594[1304376];
                    goto LABEL_21;
                case 7u:
                    v12 = *(_DWORD*)& byte_5D4594[1304396];
                    goto LABEL_21;
                case 0x8Cu:
                    v12 = *(_DWORD*)& byte_5D4594[1304352];
                LABEL_21:
                    result = (_DWORD*)sub_45A360_drawable(v12, v11, v9 + v10 / 2);
                    if (!result)
                        return result;
                    *((_BYTE*)result + 432) = 1;
                    *(_DWORD*)((char*)result + 437) = *(unsigned __int16*)(a1 + 3);
                    *(_DWORD*)((char*)result + 441) = *(unsigned __int16*)(a1 + 5);
                    v13 = 0;
                    *(_DWORD*)((char*)result + 433) = *(unsigned __int8*)(a1 + 2);
                    v14 = &byte_5D4594[1303924];
                    break;
                default:
                    return result;
            }
            while (*(_DWORD*)v14)
            {
                v14 += 4;
                ++v13;
                if ((int)v14 >= (int)& byte_5D4594[1304308])
                    return result;
            }
            *(_DWORD*)& byte_5D4594[4 * v13 + 1303924] = result;
        }
    }
    return result;
}
// 49C248: variable 'v2' is possibly undefined
// 49C256: variable 'v4' is possibly undefined

//----- (0049C450) --------------------------------------------------------
void __cdecl sub_49C450(int a1)
{
    int v1; // esi
    int* v2; // ecx

    v1 = 0;
    v2 = (int*)& byte_5D4594[1303924];
    while (1)
    {
        int result = *v2;
        if (*v2)
        {
            if (*(unsigned __int16*)(a1 + 3) == *(_DWORD*)(result + 437)
                && *(unsigned __int16*)(a1 + 5) == *(_DWORD*)(result + 441))
            {
                break;
            }
        }
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[1304308])
            return;
    }
    sub_45A4E0_drawable(*v2);
    *(_DWORD*)& byte_5D4594[4 * v1 + 1303924] = 0;
}

//----- (0049C4B0) --------------------------------------------------------
void sub_49C4B0()
{
    int v0; // esi
    int* v1; // edi

    v0 = 0;
    if (*(_DWORD*)& byte_5D4594[1304308] > 0)
    {
        v1 = (int*)& byte_5D4594[1303540];
        do
        {
            sub_45A4E0_drawable(*v1);
            ++v0;
            ++v1;
        } while (v0 < *(int*)& byte_5D4594[1304308]);
    }
    *(_DWORD*)& byte_5D4594[1304308] = 0;
    sub_4C5050();
}

//----- (0049C4F0) --------------------------------------------------------
void sub_49C4F0()
{
    int* v0 = (int*)& byte_5D4594[1303924];
    do
    {
        if (*v0)
        {
            sub_45A4E0_drawable(*v0);
            *v0 = 0;
        }
        ++v0;
    } while ((int)v0 < (int)& byte_5D4594[1304308]);
}

//----- (0049C520) --------------------------------------------------------
int __cdecl sub_49C520(int a1)
{
    unsigned __int8* v1; // eax
    int v2; // eax
    unsigned __int8* i; // ecx

    v1 = &byte_5D4594[1303924];
    while (a1 != *(_DWORD*)v1)
    {
        v1 += 4;
        if ((int)v1 >= (int)& byte_5D4594[1304308])
        {
            v2 = 0;
            if (*(int*)& byte_5D4594[1304308] <= 0)
                return 0;
            for (i = &byte_5D4594[1303540]; a1 != *(_DWORD*)i; i += 4)
            {
                if (++v2 >= *(int*)& byte_5D4594[1304308])
                    return 0;
            }
            return 1;
        }
    }
    return 1;
}

//----- (0049C560) --------------------------------------------------------
_DWORD* sub_49C560()
{
    int v0; // esi
    _DWORD* result; // eax
    _DWORD* v2; // esi
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    char* v6; // [esp-4h] [ebp-8h]
    char* v7; // [esp-4h] [ebp-8h]
    char* v8; // [esp-4h] [ebp-8h]

    v0 = *(_DWORD*)& byte_587000[26048];
    if (sub_43F320(0) > 10)
        v0 = 2;
    result = nox_new_window_from_file(*(const char**)& byte_587000[4 * v0 + 164512], sub_49C760);
    *(_DWORD*)& byte_5D4594[1305680] = result;
    if (result)
    {
        sub_46B120(result, 0);
        sub_46A8C0(*(int*)& byte_5D4594[1305680]);
        sub_46C690(*(int*)& byte_5D4594[1305680]);
        sub_46B500(*(int*)& byte_5D4594[1305680]);
        sub_46A9B0(
                *(_DWORD * *)& byte_5D4594[1305680],
                (nox_win_width - *(int*)(*(_DWORD*)& byte_5D4594[1305680] + 8)) / 2,
                (nox_win_height - *(int*)(*(_DWORD*)& byte_5D4594[1305680] + 12)) / 2);
        if (sub_40A5C0(1))
        {
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305680], 4102);
            v6 = sub_42E8E0(45, 1);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[164712], 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 85);
            nox_swprintf((wchar_t*)& byte_5D4594[1304656], v3, v6);
            nox_wcscat((wchar_t*)& byte_5D4594[1304656], L" ");
            v7 = sub_42E8E0(8, 1);
            v4 = loadString_sub_40F1D0((char*)& byte_587000[164776], 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 87);
        }
        else
        {
            v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305680], 4102);
            v8 = sub_42E8E0(45, 1);
            v5 = loadString_sub_40F1D0((char*)& byte_587000[164836], 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 94);
            nox_swprintf((wchar_t*)& byte_5D4594[1304656], v5, v8);
            nox_wcscat((wchar_t*)& byte_5D4594[1304656], L" ");
            v7 = sub_42E8E0(8, 1);
            v4 = loadString_sub_40F1D0((char*)& byte_587000[164904], 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 96);
        }
        nox_swprintf((wchar_t*)& byte_5D4594[1304400], v4, v7);
        nox_wcscat((wchar_t*)& byte_5D4594[1304656], (const wchar_t*)& byte_5D4594[1304400]);
        nox_window_call_field_94((int)v2, 16385, (int)& byte_5D4594[1304656], 0);
        if (sub_40A5C0(1))
        {
            if (!sub_459DA0())
                sub_457500();
            sub_459D80(1);
        }
        if (sub_40A5C0(4096) || (result = (_DWORD*)sub_4D6F50()) != 0)
            result = (_DWORD*)sub_49C7A0();
    }
    return result;
}

//----- (0049C760) --------------------------------------------------------
int __cdecl sub_49C760(int a1, int a2, int* a3, int a4)
{
    int v3; // esi

    if (a2 == 16391)
    {
        v3 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        if (v3 == 4103)
            sub_49C7A0();
    }
    return 1;
}

//----- (0049C7A0) --------------------------------------------------------
int sub_49C7A0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1305680];
    if (*(_DWORD*)& byte_5D4594[1305680])
    {
        *(_DWORD*)& byte_587000[54276] = ((unsigned int)~sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305680], 4104)[9] >> 2) & 1;
        sub_46C6E0(*(int*)& byte_5D4594[1305680]);
        sub_46ADE0(*(int*)& byte_5D4594[1305680]);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1305680]);
        *(_DWORD*)& byte_5D4594[1305680] = 0;
        sub_46B500(0);
        result = sub_40A5C0(1);
        if (result)
            result = sub_459D80(0);
    }
    return result;
}

//----- (0049C810) --------------------------------------------------------
BOOL sub_49C810()
{
    return *(_DWORD*)& byte_5D4594[1305680] != 0;
}

//----- (0049C820) --------------------------------------------------------
int sub_49C820()
{
    _DWORD* v0; // edi
    char** v1; // esi
    wchar_t* v2; // eax

    *(_DWORD*)& byte_5D4594[1305684] = nox_new_window_from_file("conntype.wnd", sub_49CA60);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1305684], 0);
    sub_46A8C0(*(int*)& byte_5D4594[1305684]);
    sub_46C690(*(int*)& byte_5D4594[1305684]);
    sub_46B500(*(int*)& byte_5D4594[1305684]);
    sub_49C910();
    sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1305684],
            nox_win_width / 2 - *(int*)(*(_DWORD*)& byte_5D4594[1305684] + 8) / 2,
            nox_win_height / 2 - *(int*)(*(_DWORD*)& byte_5D4594[1305684] + 12) / 2);
    sub_457500();
    sub_459D80(1);
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305684], 10352);
    v1 = (char**)& byte_587000[164928];
    do
    {
        v2 = loadString_sub_40F1D0(*v1, 0, "C:\\NoxPost\\src\\client\\Gui\\conntype.c", 158);
        nox_window_call_field_94((int)v0, 16397, (int)v2, -1);
        ++v1;
    } while ((int)v1 < (int)& byte_587000[164944]);
    return nox_window_call_field_94((int)v0, 16403, 0, 0);
}

//----- (0049C910) --------------------------------------------------------
_DWORD* sub_49C910()
{
    unsigned __int16* v0; // eax
    unsigned __int16* v1; // esi
    char** v2; // ebx
    int v3; // eax
    int v4; // edi
    unsigned __int16* v5; // eax
    int v6; // edi
    int v7; // eax
    _DWORD* result; // eax
    int v9; // ecx
    int v10; // edi
    int v11; // [esp+Ch] [ebp-8h]
    int v12; // [esp+10h] [ebp-4h]

    v0 = (unsigned __int16*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305684], 10352);
    v1 = v0;
    v2 = (char**)& byte_587000[164928];
    v3 = 5 * (sub_43F320(*((_DWORD*)v0 + 59)) + 1);
    *((_DWORD*)v1 + 7) = *((_DWORD*)v1 + 5) + v3 + 2;
    *((_DWORD*)v1 + 3) = v3 + 2;
    v4 = 0;
    do
    {
        v5 = loadString_sub_40F1D0(*v2, 0, "C:\\NoxPost\\src\\client\\Gui\\conntype.c", 53);
        sub_43F840(*((_DWORD*)v1 + 59), v5, &v11, 0, 0);
        if (v11 > v4)
            v4 = v11;
        ++v2;
    } while ((int)v2 < (int)& byte_587000[164944]);
    v6 = v4 + 7;
    sub_43F840(*((_DWORD*)v1 + 59), v1 + 54, &v12, 0, 0);
    if (v6 <= v12)
        v6 = v12;
    v7 = *((_DWORD*)v1 + 4);
    *((_DWORD*)v1 + 2) = v6;
    *((_DWORD*)v1 + 6) = v7 + v6;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305684] + 16) = v7 - 40;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305684] + 20) = *((_DWORD*)v1 + 5) - 40;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305684] + 24) = *((_DWORD*)v1 + 6) + 40;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305684] + 28) = *((_DWORD*)v1 + 7) + 40;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305684] + 8) = *((_DWORD*)v1 + 2) + 80;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305684] + 12) = *((_DWORD*)v1 + 3) + 80;
    result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305684], 10353);
    result[5] = *((_DWORD*)v1 + 7) + 10;
    v9 = result[2];
    v10 = result[5];
    result[4] = *((_DWORD*)v1 + 6) - v9;
    result[7] = v10 + result[3];
    result[6] = v9 + result[4];
    return result;
}

//----- (0049CA60) --------------------------------------------------------
int __cdecl sub_49CA60(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    _DWORD* v4; // eax
    int v5; // eax
    int v6; // eax

    if (a2 == 16391)
    {
        v3 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        if (v3 == 10353)
        {
            sub_46C6E0(*(int*)& byte_5D4594[1305684]);
            sub_46ADE0(*(int*)& byte_5D4594[1305684]);
            if (sub_40A5C0(128) && *(_DWORD*)& byte_587000[54276])
                sub_49C560();
            else
                sub_459D80(0);
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1305684], 10352);
            v5 = nox_window_call_field_94((int)v4, 16404, 0, 0);
            *(_DWORD*)& byte_5D4594[3596] = v5 + 1;
            v6 = sub_40A710(v5 + 1);
            sub_40A6D0(v6);
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[1305684]);
            *(_DWORD*)& byte_5D4594[1305684] = 0;
            sub_46B500(0);
        }
    }
    return 1;
}

//----- (0049CB40) --------------------------------------------------------
BOOL sub_49CB40()
{
    return *(_DWORD*)& byte_5D4594[1305684] != 0;
}

//----- (0049CB50) --------------------------------------------------------
int sub_49CB50()
{
    if (!*(_DWORD*)& byte_5D4594[3801780])
    {
        *(_DWORD*)& byte_5D4594[1305704] = sub_49D1E0;
        *(_DWORD*)& byte_5D4594[1305712] = sub_49D680;
        *(_DWORD*)& byte_5D4594[1305720] = sub_49D880;
        *(_DWORD*)& byte_5D4594[1305700] = sub_49DA90;
        *(_DWORD*)& byte_5D4594[1305716] = sub_49DB20;
        *(_DWORD*)& byte_5D4594[1305696] = sub_49DD60;
        *(_DWORD*)& byte_5D4594[1305708] = sub_49E380;
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[3801780] != 1)
        return 1;
    *(_DWORD*)& byte_5D4594[1305704] = sub_49D270;
    if (*(_DWORD*)& byte_5D4594[3801804])
    {
        *(_DWORD*)& byte_5D4594[1305692] = sub_49D540;
        *(_DWORD*)& byte_5D4594[1305712] = sub_49D770;
        *(_DWORD*)& byte_5D4594[1305720] = sub_49D770;
        *(_DWORD*)& byte_5D4594[1305700] = sub_49D9A0;
        *(_DWORD*)& byte_5D4594[1305716] = sub_49DC70;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1305692] = sub_49D370;
        *(_DWORD*)& byte_5D4594[1305712] = sub_49D6F0;
        *(_DWORD*)& byte_5D4594[1305720] = sub_49D6F0;
        *(_DWORD*)& byte_5D4594[1305700] = sub_49D8E0;
        *(_DWORD*)& byte_5D4594[1305716] = sub_49DBB0;
    }
    *(_DWORD*)& byte_5D4594[1305696] = sub_49E060;
    *(_DWORD*)& byte_5D4594[1305708] = sub_49E3C0;
    return 1;
}

//----- (0049CC70) --------------------------------------------------------
void __cdecl sub_49CC70(int xLeft, int yTop, int a3, int a4)
{
    int v4; // ebx
    int v5; // ebp
    RECT rc; // [esp+10h] [ebp-10h]

    if (a3)
    {
        if (a4)
        {
            if (!ptr_5D4594_3799572->data[0]
                || (SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4),
                    sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]))))
            {
                v4 = xLeft + a3 - 1;
                (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(xLeft, yTop, v4);
                v5 = yTop + a4 - 1;
                (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798712])(v4, yTop + 1, v5);
                (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(xLeft, v5, xLeft + a3 - 2);
                (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798712])(xLeft, yTop + 1, yTop + a4 - 2);
            }
        }
    }
}

//----- (0049CD30) --------------------------------------------------------
void __cdecl sub_49CD30(int xLeft, int yTop, int a3, int a4, int a5, int a6)
{
    RECT rc; // [esp+10h] [ebp-10h]

    if (a3)
    {
        if (a4)
        {
            if (!ptr_5D4594_3799572->data[0]
                || (SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4),
                    sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]))))
            {
                sub_434040(a5);
                sub_434080(a6);
                sub_49F500(xLeft, yTop);
                sub_49F500(xLeft + a3 - 1, yTop);
                sub_49E4F0(64);
                sub_49F500(xLeft + a3, yTop);
                sub_49F500(xLeft + a3, yTop + a4 - 1);
                sub_49E4F0(64);
                sub_49F500(xLeft + a3, yTop + a4);
                sub_49F500(xLeft, yTop + a4);
                sub_49E4F0(64);
                sub_49F500(xLeft, yTop + a4 - 1);
                sub_49F500(xLeft, yTop + 1);
                sub_49E4F0(64);
            }
        }
    }
}

//----- (0049CE30) --------------------------------------------------------
void __cdecl sub_49CE30(int xLeft, int yTop, int a3, int a4)
{
    int v4; // ecx
    int v5; // eax
    obj_5D4594_3799572_t* v6;
    int v7; // edx
    LONG v8; // esi
    int v9; // esi
    RECT rc; // [esp+8h] [ebp-10h]

    v4 = a3;
    if (a3)
    {
        v5 = a4;
        if (a4)
        {
            v6 = ptr_5D4594_3799572;
            v7 = yTop;
            if (ptr_5D4594_3799572->data[0])
            {
                SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
                if (!sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1])))
                    return;
                v7 = rc.top;
                v6 = ptr_5D4594_3799572;
                v8 = rc.left;
                v4 = rc.right - rc.left;
                v5 = rc.bottom - rc.top;
            }
            else
            {
                v8 = xLeft;
            }
            if (v8 || v7 || v4 != nox_backbuffer_width || v5 != nox_backbuffer_height)
            {
                (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305704])(v8, v7, v4, v5);
            }
            else
            {
                v9 = v6->data[58];
                v6->data[58] = v6->data[61];
                sub_440900();
                ptr_5D4594_3799572->data[58] = v9;
            }
        }
    }
}

//----- (0049CF10) --------------------------------------------------------
int4* __cdecl sub_49CF10(int xLeft, int yTop, int a3, int a4)
{
    int4* result; // eax
    RECT rc; // [esp+4h] [ebp-10h]

    if (!ptr_5D4594_3799572->data[0])
        return (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305712])(xLeft, yTop, a3, a4);
    SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
    result = sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
    if (result)
        result = (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305712])(
                rc.left,
                rc.top,
                rc.right - rc.left,
                rc.bottom - rc.top);
    return result;
}

//----- (0049CFB0) --------------------------------------------------------
int4* __cdecl sub_49CFB0(int xLeft, int yTop, int a3, int a4)
{
    int4* result; // eax
    RECT rc; // [esp+4h] [ebp-10h]

    if (!ptr_5D4594_3799572->data[0])
        return (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305720])(xLeft, yTop, a3, a4);
    SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
    result = sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
    if (result)
        result = (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305720])(
                rc.left,
                rc.top,
                rc.right - rc.left,
                rc.bottom - rc.top);
    return result;
}

//----- (0049D050) --------------------------------------------------------
int4* __cdecl sub_49D050(int xLeft, int yTop, int a3, int a4)
{
    int4* result; // eax
    RECT rc; // [esp+4h] [ebp-10h]

    if (!ptr_5D4594_3799572->data[0])
        return (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305700])(xLeft, yTop, a3, a4);
    SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
    result = sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
    if (result)
        result = (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305700])(
                rc.left,
                rc.top,
                rc.right - rc.left,
                rc.bottom - rc.top);
    return result;
}

//----- (0049D0F0) --------------------------------------------------------
int4* __cdecl sub_49D0F0(int xLeft, int yTop, int a3, int a4)
{
    int4* result; // eax
    RECT rc; // [esp+4h] [ebp-10h]

    if (!ptr_5D4594_3799572->data[0])
        return (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305716])(xLeft, yTop, a3, a4);
    SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
    result = sub_49F930((int4*)& rc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1]));
    if (result)
        result = (int4*)(*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305716])(
                rc.left,
                rc.top,
                rc.right - rc.left,
                rc.bottom - rc.top);
    return result;
}

//----- (0049D190) --------------------------------------------------------
int __cdecl sub_49D190(int a1, int a2, int a3, int a4, int a5)
{
    return (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305696])(a1, a2, a3, a4, a5);
}

//----- (0049D1C0) --------------------------------------------------------
int __cdecl sub_49D1C0(int a1, int a2, int a3)
{
    return (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[1305708])(a1, a2, a3);
}

//----- (0049D1E0) --------------------------------------------------------
void __cdecl sub_49D1E0(int a1, int a2, unsigned int a3, int a4)
{
    int result; // eax
    _DWORD* v5; // esi
    char* v6; // edi
    char* v7; // edi

    result = ptr_5D4594_3799572;
    if (ptr_5D4594_3799572->data[13])
    {
        sub_49D2F0(a1, a2, a3, a4);
        return;
    }
    if (a4 > 0 && (int)a3 > 0)
    {
        result = ptr_5D4594_3799572->data[61];
        v5 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
        do
        {
            v6 = (char*)(a1 + *v5);
            memset32(v6, result, a3 >> 2);
            v7 = &v6[4 * (a3 >> 2)];
            if (a3 & 3)
            {
                *v7 = result;
                if ((a3 & 3) != 1)
                {
                    v7[1] = result;
                    if ((a3 & 3) != 2)
                        v7[2] = result;
                }
            }
            ++v5;
        } while (a4-- > 1);
    }
}

//----- (0049D270) --------------------------------------------------------
void __cdecl sub_49D270(int a1, int a2, unsigned int a3, int a4)
{
    int result; // eax
    int v5; // edx
    _DWORD* v6; // esi
    char* v7; // edi
    char* v8; // edi

    result = ptr_5D4594_3799572;
    if (ptr_5D4594_3799572->data[13])
    {
        (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305692])(a1, a2, a3, a4);
        return;
    }
    v5 = a4;
    if (a4 > 0 && (int)a3 > 0)
    {
        result = ptr_5D4594_3799572->data[61];
        v6 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
        do
        {
            v7 = (char*)(2 * a1 + *v6);
            memset32(v7, result, a3 >> 1);
            v8 = &v7[4 * (a3 >> 1)];
            if (a3 & 1)
                * (_WORD*)v8 = result;
            ++v6;
        } while (v5-- > 1);
    }
}

//----- (0049D2F0) --------------------------------------------------------
int __cdecl sub_49D2F0(int a1, int a2, int a3, int a4)
{
    int result; // eax
    int v5; // edi
    int v6; // eax
    unsigned __int8* v7; // eax
    int v8; // esi
    int v9; // edx
    unsigned __int8 v10; // [esp+0h] [ebp-4h]

    result = a4 - 1;
    v10 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
    if (a4)
    {
        v5 = 4 * a2;
        do
        {
            v6 = *(_DWORD*)(v5 + *(_DWORD*)& byte_5D4594[3798784]);
            v5 += 4;
            v7 = (unsigned __int8*)(a1 + v6);
            if (a3)
            {
                v8 = a3;
                do
                {
                    v9 = v10 + (*v7++ << 8);
                    --v8;
                    *(v7 - 1) = *(_BYTE*)(v9 + *(_DWORD*)& byte_5D4594[810632]);
                } while (v8);
            }
            result = --a4;
        } while (a4);
    }
    return result;
}

//----- (0049D370) --------------------------------------------------------
void __cdecl sub_49D370(int a1, int a2, int a3, int a4)
{
    int v4; // eax
    unsigned __int8 v5; // bl
    int result; // eax
    int v7; // ecx
    int v8; // edx
    int v9; // esi
    __int16* v10; // esi
    int v11; // ebp
    __int16 v12; // cx
    bool v13; // zf
    unsigned __int8 v14; // [esp+Ch] [ebp-28h]
    unsigned __int8 v15; // [esp+10h] [ebp-24h]
    unsigned __int8 v16; // [esp+14h] [ebp-20h]
    int v17; // [esp+38h] [ebp+4h]
    int v18; // [esp+3Ch] [ebp+8h]
    int v19; // [esp+44h] [ebp+10h]

    v4 = ptr_5D4594_3799572->data[61] & 0xFFFF;
    v17 = 2 * a1;
    v5 = byte_5D4594[3804372];
    v16 = (*(_DWORD*)& byte_5D4594[3804364] & (unsigned int)v4) >> byte_5D4594[3804376];
    v15 = (*(_DWORD*)& byte_5D4594[3804368] & (unsigned int)v4) >> byte_5D4594[3804380];
    v14 = ((unsigned __int8) ptr_5D4594_3799572->data[61] & byte_5D4594[3804372]) << byte_5D4594[3804384];
    result = a4 - 1;
    if (a4)
    {
        v7 = a3;
        v8 = 4 * a2;
        v18 = a4;
        do
        {
            v9 = *(_DWORD*)(v8 + *(_DWORD*)& byte_5D4594[3798784]);
            v8 += 4;
            v10 = (__int16*)(v17 + v9);
            if (v7)
            {
                v11 = v16;
                v19 = v7;
                while (1)
                {
                    v12 = *v10;
                    ++v10;
                    v13 = v19 == 1;
                    *(v10 - 1) = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                                           + 2
                                             * (unsigned __int8)((((unsigned __int8)v12 & v5) << byte_5D4594[3804384])
                                                                 + ((v14
                                                                     - (unsigned __int8)(((unsigned __int8)v12 & v5) << byte_5D4594[3804384])) >> 1))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v12) >> byte_5D4594[3804380]) + ((v15 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v12) >> byte_5D4594[3804380])) >> 1))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v12) >> byte_5D4594[3804376]) + ((v11 - (unsigned __int8)((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v12) >> byte_5D4594[3804376])) >> 1)));
                    v5 = byte_5D4594[3804372];
                    --v19;
                    if (v13)
                        break;
                    v11 = v16;
                }
                v7 = a3;
            }
            result = --v18;
        } while (v18);
    }
}


int __cdecl sub_49D540(int a1, int a2, int a3, int a4)
{
    DebugBreak();
    return 0;
}

#if 0
//----- (0049D540) --------------------------------------------------------
int __cdecl sub_49D540(int a1, int a2, int a3, int a4)
{
    __m64 v4; // mm0
    __m64 v5; // mm1
    __m64 v6; // mm2
    int* v7; // esi
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    __m64 v13; // mm4
    __m64 v14; // mm5
    __m64 v15; // mm3
    bool v16; // cc
    int v17; // ecx
    __m64 v18; // [esp+Ch] [ebp-8h]
    __m64 v19; // [esp+Ch] [ebp-8h]

    v18.m64_i32[0] = *(_DWORD*)(&obj_5D4594_3800716.data[61]);
    v18.m64_i32[1] = *(_DWORD*)(&obj_5D4594_3800716.data[61]);
    v4 = _m_psrlw(_m_pand(v18, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
    v5 = _m_psrlw(_m_pand(v18, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
    v6 = _m_psllw(_m_pand(v18, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
    v7 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v7;
        ++v7;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_psrlw(_m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
            v13 = _m_psrlw(_m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
            v14 = _m_psllw(_m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
            v15 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(_m_paddw(v12, _m_psrlwi(_m_psubw(v4, v12), 1u)), *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(_m_paddw(v13, _m_psrlwi(_m_psubw(v5, v13), 1u)), *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(_m_paddw(v14, _m_psrlwi(_m_psubw(v6, v14), 1u)), *(__m64*) & byte_5D4594[3804460]));
            v16 = v9 < 4;
            v9 -= 4;
            if (v16)
                break;
            v11->m64_u64 = (unsigned __int64)v15;
            ++v11;
            if (v16)
            {
                v16 = a4-- <= 1;
                if (!v16)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v19 = v15;
        LOWORD(v11->m64_i32[0]) = v19.m64_i16[0];
        v17 = v9 + 3;
        if (v17)
        {
            HIWORD(v11->m64_i32[0]) = v19.m64_i16[1];
            if (v17 != 1)
                LOWORD(v11->m64_i32[1]) = v19.m64_i16[2];
        }
        v16 = a4-- <= 1;
        if (!v16)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}
#endif

//----- (0049D680) --------------------------------------------------------
int __cdecl sub_49D680(int a1, int a2, int a3, int a4)
{
    int result; // eax
    int v5; // ecx
    unsigned __int8* v6; // eax
    int v7; // esi
    int v8; // edx

    result = a4 - 1;
    if (a4)
    {
        v5 = 4 * a2;
        do
        {
            v5 += 4;
            v6 = (unsigned __int8*)(a1 + *(_DWORD*)(v5 + *(_DWORD*)& byte_5D4594[3798784] - 4));
            if (a3)
            {
                v7 = a3;
                do
                {
                    v8 = *v6++ << 8;
                    --v7;
                    *(v6 - 1) = *(_BYTE*)(v8 + *(_DWORD*)& byte_5D4594[810632]);
                } while (v7);
            }
            result = --a4;
        } while (a4);
    }
    return result;
}

//----- (0049D6F0) --------------------------------------------------------
__int16 __cdecl sub_49D6F0(int a1, int a2, unsigned int a3, int a4)
{
    unsigned int v4; // eax
    _DWORD* v5; // esi
    int v6; // edx
    int v7; // ebx
    char v8; // cf
    //char v9; // of
    char v10; // cc
    int v11; // ecx
    unsigned int* v12; // edi
    int v13; // ecx
    unsigned int* v14; // edi
    unsigned int v16; // [esp+1Ch] [ebp+10h]

    if (a4 > 0)
    {
        LOWORD(v4) = a2;
        v5 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
        v6 = *(_DWORD*)& byte_5D4594[3804388];
        v7 = 2 * a1;
        v8 = a3 & 1;
        //v10 = (((a3 >> 1) & 0x80000000) != 0) ^ v9 | (a3 >> 1 == 0);
        v16 = a3 >> 1;
        if (v16)
        {
            if (v8)
            {
                do
                {
                    v13 = v16;
                    v14 = (unsigned int*)(v7 + *v5);
                    do
                    {
                        *v14 = (v6 & *v14) >> 1;
                        ++v14;
                        v10 = v13-- <= 1;
                    } while (!v10);
                    LOWORD(v4) = (unsigned __int16)(v6 & *(_WORD*)v14) >> 1;
                    *(_WORD*)v14 = v4;
                    ++v5;
                    v10 = a4-- <= 1;
                } while (!v10);
            }
            else
            {
                do
                {
                    v11 = v16;
                    v12 = (unsigned int*)(v7 + *v5);
                    do
                    {
                        v4 = (v6 & *v12) >> 1;
                        *v12 = v4;
                        ++v12;
                        v10 = v11-- <= 1;
                    } while (!v10);
                    ++v5;
                    v10 = a4-- <= 1;
                } while (!v10);
            }
        }
    }
    return v4;
}

void __cdecl sub_49D770(int a1, int a2, unsigned int a3, int a4)
{
    DebugBreak();
    return;
}

#if 0
//----- (0049D770) --------------------------------------------------------
void __cdecl sub_49D770(int a1, int a2, unsigned int a3, int a4)
{
    _DWORD* v4; // esi
    __m64 v5; // mm1
    int v6; // edx
    int v7; // ebx
    unsigned int v8; // eax
    signed int v9; // ecx
    __m64* v10; // edi
    bool v11; // cc
    signed int v12; // ecx
    __m64* v13; // edi
    signed int v14; // ecx
    __m64* v15; // edi
    signed int v16; // ecx
    __m64* v17; // edi

    if (a4 > 0 && (int)a3 > 0)
    {
        v4 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
        v5 = *(__m64*) & byte_5D4594[3804516];
        v6 = _mm_cvtsi64_si32(*(__m64*) & byte_5D4594[3804516]);
        v7 = 2 * a1;
        v8 = a3 >> 1;
        if (a3 & 1)
        {
            if (v8 & 1)
            {
                do
                {
                    v14 = a3 >> 2;
                    v15 = (__m64*)(v7 + *v4);
                    do
                    {
                        v15->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v15->m64_u64, v5), 1u);
                        ++v15;
                        v11 = v14-- <= 1;
                    } while (!v11);
                    v15->m64_i32[0] = ((unsigned int)v6 & v15->m64_i32[0]) >> 1;
                    HIWORD(v15->m64_i32[0]) = (unsigned __int16)(v6 & HIWORD(v15->m64_i32[0])) >> 1;
                    ++v4;
                    v11 = a4-- <= 1;
                } while (!v11);
            }
            else
            {
                do
                {
                    v12 = a3 >> 2;
                    v13 = (__m64*)(v7 + *v4);
                    do
                    {
                        v13->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v13->m64_u64, v5), 1u);
                        ++v13;
                        v11 = v12-- <= 1;
                    } while (!v11);
                    LOWORD(v13->m64_i32[0]) = (unsigned __int16)(v6 & LOWORD(v13->m64_i32[0])) >> 1;
                    ++v4;
                    v11 = a4-- <= 1;
                } while (!v11);
            }
        }
        else if (v8 & 1)
        {
            do
            {
                v9 = a3 >> 2;
                v10 = (__m64*)(v7 + *v4);
                do
                {
                    v10->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v10->m64_u64, v5), 1u);
                    ++v10;
                    v11 = v9-- <= 1;
                } while (!v11);
                v10->m64_i32[0] = ((unsigned int)v6 & v10->m64_i32[0]) >> 1;
                ++v4;
                v11 = a4-- <= 1;
            } while (!v11);
        }
        else
        {
            do
            {
                v16 = a3 >> 2;
                v17 = (__m64*)(v7 + *v4);
                do
                {
                    v17->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v17->m64_u64, v5), 1u);
                    ++v17;
                    v11 = v16-- <= 1;
                } while (!v11);
                ++v4;
                v11 = a4-- <= 1;
            } while (!v11);
        }
        _m_femms();
    }
}
#endif

//----- (0049D880) --------------------------------------------------------
void __cdecl sub_49D880(int a1, int a2, int a3, int a4)
{
    _DWORD* v4; // esi
    int v5; // ebx
    int v6; // ecx
    unsigned __int8* v7; // edi
    bool v9; // cc

    if (a4 > 0 && a3 > 0)
    {
        v4 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
        v5 = (*(_DWORD*)(&obj_5D4594_3800716.data[258]) >> 3) + *(_DWORD*)& byte_5D4594[810636];
        do
        {
            v6 = a3;
            v7 = (unsigned __int8*)(a1 + *v4);
            do
            {
                *v7++ = *(_BYTE*)(v5 + 32 * *v7);
                v9 = v6-- <= 1;
            } while (!v9);
            ++v4;
            v9 = a4-- <= 1;
        } while (!v9);
    }
}

//----- (0049D8E0) --------------------------------------------------------
int __cdecl sub_49D8E0(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    int v5; // edi
    _WORD* v6; // edi
    unsigned int v7; // edx
    int v8; // eax
    unsigned int v9; // ebx
    int v10; // edx
    int result; // eax
    bool v12; // cc
    int v13; // [esp+Ch] [ebp-4h]

    v4 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    do
    {
        v13 = a3;
        v5 = *v4;
        ++v4;
        v6 = (_WORD*)(a1 + a1 + v5);
        do
        {
            v7 = (unsigned __int16)* v6;
            v8 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376];
            LOBYTE(v8) = SADD8(obj_5D4594_3800716.data[54], v8);//__CFADD__(obj_5D4594_3800716.data[54], (_BYTE)v8) ? -1 : (unsigned __int8)(obj_5D4594_3800716.data[54] + v8);
            v9 = (*(_DWORD*)& byte_5D4594[3804368] & v7) >> byte_5D4594[3804380];
            LOBYTE(v9) = SADD8(obj_5D4594_3800716.data[55], v9);//__CFADD__(obj_5D4594_3800716.data[55], (_BYTE)v9) ? -1 : (unsigned __int8)(obj_5D4594_3800716.data[55] + v9);
            v10 = (*(_DWORD*)& byte_5D4594[3804372] & v7) << byte_5D4594[3804384];
            LOBYTE(v10) = SADD8(obj_5D4594_3800716.data[56], v10);//__CFADD__(obj_5D4594_3800716.data[56], (_BYTE)v10) ? -1 : (unsigned __int8)(obj_5D4594_3800716.data[56] + v10);
            result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * v10) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804656]
                                                                                         + 2 * v9) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * v8);
            *v6 = result;
            ++v6;
            v12 = v13-- <= 1;
        } while (!v12);
        v12 = a4-- <= 1;
    } while (!v12);
    return result;
}


int __cdecl sub_49D9A0(int a1, int a2, int a3, int a4)
{
    DebugBreak();
    return 0;
}

#if 0
//----- (0049D9A0) --------------------------------------------------------
int __cdecl sub_49D9A0(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    __m64 v5; // mm0
    __m64 v6; // mm1
    __m64 v7; // mm2
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    bool v13; // cc
    int v14; // ecx
    __m64 v15; // [esp+Ch] [ebp-8h]

    v4 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    v5 = *(__m64*)(&obj_5D4594_3800716.data[48]);
    v6 = *(__m64*)(&obj_5D4594_3800716.data[50]);
    v7 = *(__m64*)(&obj_5D4594_3800716.data[52]);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v4;
        ++v4;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(
                            _m_paddusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                    *(__m64*) & byte_5D4594[3804444]),
                                v5),
                            *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(
                            _m_paddusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                    *(__m64*) & byte_5D4594[3804452]),
                                v6),
                            *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(
                    _m_paddusb(
                        _m_psllw(
                            _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                            *(__m64*) & byte_5D4594[3804460]),
                        v7),
                    *(__m64*) & byte_5D4594[3804460]));
            v13 = v9 < 4;
            v9 -= 4;
            if (v13)
                break;
            v11->m64_u64 = (unsigned __int64)v12;
            ++v11;
            if (v13)
            {
                v13 = a4-- <= 1;
                if (!v13)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v15 = v12;
        LOWORD(v11->m64_i32[0]) = v15.m64_i16[0];
        v14 = v9 + 3;
        if (v14)
        {
            HIWORD(v11->m64_i32[0]) = v15.m64_i16[1];
            if (v14 != 1)
                LOWORD(v11->m64_i32[1]) = v15.m64_i16[2];
        }
        v13 = a4-- <= 1;
        if (!v13)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}

#endif

//----- (0049DA90) --------------------------------------------------------
unsigned __int8 __cdecl sub_49DA90(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    int v5; // ecx
    int v6; // edi
    unsigned __int8* v7; // edi
    int v8; // eax
    char v9; // bl
    char v10; // bh
    int v11; // eax
    unsigned __int8 result; // al
    bool v13; // cc

    v4 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    do
    {
        v5 = a3;
        v6 = *v4;
        ++v4;
        v7 = (unsigned __int8*)(a1 + v6);
        do
        {
            v8 = *v7;
            //v9 = (unsigned __int8)(__CFADD__(obj_5D4594_3800716.data[56], byte_5D4594[4 * v8 + 3803310]) ? -1 : (unsigned __int8)(obj_5D4594_3800716.data[56] + byte_5D4594[4 * v8 + 3803310])) >> 3;
            v9 = SADD8(obj_5D4594_3800716.data[56], byte_5D4594[4 * v8 + 3803310]) >> 3;
            //v10 = (__CFADD__(obj_5D4594_3800716.data[55], byte_5D4594[4 * v8 + 3803309]) ? -1 : (unsigned __int8)(obj_5D4594_3800716.data[55] + byte_5D4594[4 * v8 + 3803309])) & 0xF8;
            v10 = SADD8(obj_5D4594_3800716.data[55], byte_5D4594[4 * v8 + 3803309]) & 0xF8;
            //v11 = 32
            //    * (((unsigned __int8)-__CFADD__(obj_5D4594_3800716.data[54], byte_5D4594[4 * v8 + 3803308]) | (unsigned __int8)(obj_5D4594_3800716.data[54] + byte_5D4594[4 * v8 + 3803308])) & 0xF8);
            v11 = 32 * (SADD8(obj_5D4594_3800716.data[54], byte_5D4594[4 * v8 + 3803308]) & 0xF8);
            LOBYTE(v11) = v10;
            v11 *= 4;
            LOBYTE(v11) = v9 | v11;
            result = *(_BYTE*)(*(_DWORD*)& byte_5D4594[810640] + v11);
            *v7++ = result;
            v13 = v5-- <= 1;
        } while (!v13);
        v13 = a4-- <= 1;
    } while (!v13);
    return result;
}

//----- (0049DB20) --------------------------------------------------------
unsigned __int8 __cdecl sub_49DB20(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    int v5; // ecx
    int v6; // edi
    unsigned __int8* v7; // edi
    int v8; // eax
    char v9; // bl
    char v10; // bh
    int v11; // eax
    unsigned __int8 result; // al
    bool v13; // cc

    v4 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    do
    {
        v5 = a3;
        v6 = *v4;
        ++v4;
        v7 = (unsigned __int8*)(a1 + v6);
        do
        {
            v8 = *v7;
            v9 = (unsigned __int8)(byte_5D4594[4 * v8 + 3803310] < obj_5D4594_3800716.data[56] ? 0 : (unsigned __int8)(byte_5D4594[4 * v8 + 3803310] - obj_5D4594_3800716.data[56])) >> 3;
            v10 = (byte_5D4594[4 * v8 + 3803309] < obj_5D4594_3800716.data[55] ? 0 : (unsigned __int8)(byte_5D4594[4 * v8 + 3803309]
                                                                                                       - obj_5D4594_3800716.data[55])) & 0xF8;
            v11 = 32
                  * ((unsigned __int8)((byte_5D4594[4 * v8 + 3803308] < obj_5D4594_3800716.data[54]) - 1) & (unsigned __int8)(byte_5D4594[4 * v8 + 3803308] - obj_5D4594_3800716.data[54]) & 0xF8);
            LOBYTE(v11) = v10;
            v11 *= 4;
            LOBYTE(v11) = v9 | v11;
            result = *(_BYTE*)(*(_DWORD*)& byte_5D4594[810640] + v11);
            *v7++ = result;
            v13 = v5-- <= 1;
        } while (!v13);
        v13 = a4-- <= 1;
    } while (!v13);
    return result;
}

//----- (0049DBB0) --------------------------------------------------------
int __cdecl sub_49DBB0(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    int v5; // edi
    _WORD* v6; // edi
    unsigned __int64 v7; // kr00_8
    unsigned __int64 v8; // kr08_8
    int result; // eax
    bool v10; // cc
    int v11; // [esp+Ch] [ebp-4h]

    v4 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    do
    {
        v11 = a3;
        v5 = *v4;
        ++v4;
        v6 = (_WORD*)(a1 + a1 + v5);
        do
        {
            v7 = ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *v6) >> byte_5D4594[3804380])
                 - (unsigned __int64) * (unsigned int*)& obj_5D4594_3800716.data[55];
            v8 = ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & *v6) << byte_5D4594[3804384])
                 - (unsigned __int64) * (unsigned int*)& obj_5D4594_3800716.data[56];
            result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (~HIDWORD(v8) & v8)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * (~HIDWORD(v7) & v7)) | *(_DWORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (~((__PAIR64__(*(unsigned int*)& byte_5D4594[3804376], (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376]) - __PAIR64__(*(unsigned int*)& byte_5D4594[3804376], *(unsigned int*)& obj_5D4594_3800716.data[54])) >> 32) & (((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376]) - *(_DWORD*)(&obj_5D4594_3800716.data[54]))));
            *v6 = result;
            ++v6;
            v10 = v11-- <= 1;
        } while (!v10);
        v10 = a4-- <= 1;
    } while (!v10);
    return result;
}


int __cdecl sub_49DC70(int a1, int a2, int a3, int a4)
{
    DebugBreak();
    return 0;
}

#if 0
//----- (0049DC70) --------------------------------------------------------
int __cdecl sub_49DC70(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    __m64 v5; // mm0
    __m64 v6; // mm1
    __m64 v7; // mm2
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    bool v13; // cc
    int v14; // ecx
    __m64 v15; // [esp+Ch] [ebp-8h]

    v4 = (int*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2);
    v5 = *(__m64*)(&obj_5D4594_3800716.data[48]);
    v6 = *(__m64*)(&obj_5D4594_3800716.data[50]);
    v7 = *(__m64*)(&obj_5D4594_3800716.data[52]);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v4;
        ++v4;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(
                            _m_psubusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                    *(__m64*) & byte_5D4594[3804444]),
                                v5),
                            *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(
                            _m_psubusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                    *(__m64*) & byte_5D4594[3804452]),
                                v6),
                            *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(
                    _m_psubusb(
                        _m_psllw(
                            _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                            *(__m64*) & byte_5D4594[3804460]),
                        v7),
                    *(__m64*) & byte_5D4594[3804460]));
            v13 = v9 < 4;
            v9 -= 4;
            if (v13)
                break;
            v11->m64_u64 = (unsigned __int64)v12;
            ++v11;
            if (v13)
            {
                v13 = a4-- <= 1;
                if (!v13)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v15 = v12;
        LOWORD(v11->m64_i32[0]) = v15.m64_i16[0];
        v14 = v9 + 3;
        if (v14)
        {
            HIWORD(v11->m64_i32[0]) = v15.m64_i16[1];
            if (v14 != 1)
                LOWORD(v11->m64_i32[1]) = v15.m64_i16[2];
        }
        v13 = a4-- <= 1;
        if (!v13)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}
#endif
//----- (0049DD60) --------------------------------------------------------
int4* __cdecl sub_49DD60(unsigned __int8 a1, int a2, int a3, int a4, int a5)
{
    int4* result; // eax
    int v6; // ebp
    int v7; // esi
    int4* v8; // ecx
    unsigned __int8 v9; // dl
    int v10; // eax
    int v11; // ebx
    int v12; // ecx
    int v13; // edi
    _BYTE* v14; // eax
    _BYTE* v15; // ecx
    _BYTE* v16; // esi
    int v17; // edi
    int v18; // ebp
    int v19; // ebx
    int v20; // edx
    unsigned __int8* v21; // eax
    int v22; // esi
    int v23; // ecx
    int v24; // ecx
    int v25; // eax
    int v26; // edx
    char v27; // al
    int* v28; // eax
    int v29; // ecx
    int v30; // esi
    bool v31; // zf
    int v32; // [esp+Ch] [ebp-6Ch]
    int v33; // [esp+10h] [ebp-68h]
    int v34; // [esp+18h] [ebp-60h]
    int v35; // [esp+1Ch] [ebp-5Ch]
    int v36; // [esp+20h] [ebp-58h]
    int4 a3a; // [esp+24h] [ebp-54h]
    int4 a2a; // [esp+34h] [ebp-44h]
    int4 a1a; // [esp+44h] [ebp-34h]
    _BYTE* v40[9]; // [esp+54h] [ebp-24h]
    int v41; // [esp+84h] [ebp+Ch]

    if (ptr_5D4594_3799572->data[0])
    {
        a2a.field_0 = a2;
        a2a.field_8 = a4 + a2;
        a2a.field_4 = a3;
        a2a.field_C = a5 + a3;
        a3a.field_4 = 1;
        a3a.field_0 = 1;
        a3a.field_8 = nox_backbuffer_width - 1;
        a3a.field_C = nox_backbuffer_height - 1;
        result = sub_49F930(&a1a, &a2a, &a3a);
        if (!result)
            return result;
        v6 = a1a.field_0;
        a2 = a1a.field_0;
        v7 = a1a.field_4;
        a4 = a1a.field_8 - a1a.field_0;
        v8 = (int4*)(a1a.field_C - a1a.field_4);
    }
    else
    {
        v8 = (int4*)a5;
        v7 = a3;
        v6 = a2;
    }
    v9 = a1;
    v10 = 4 * a1;
    v34 = byte_5D4594[v10 + 3803308];
    v35 = byte_5D4594[v10 + 3803309];
    v11 = byte_5D4594[v10 + 3803310];
    result = v8;
    v12 = (int)& v8[-1].field_C + 3;
    v36 = v11;
    if (result)
    {
        v13 = 4 * v7;
        v41 = 4 * v7;
        v33 = v12 + 1;
        while (1)
        {
            v14 = (_BYTE*)(v6 + *(_DWORD*)(v13 + *(_DWORD*)& byte_5D4594[3798784] - 4));
            v40[1] = v14;
            v40[0] = v14 - 1;
            v40[2] = v14 + 1;
            v15 = (_BYTE*)(v6 + *(_DWORD*)(v13 + *(_DWORD*)& byte_5D4594[3798784]));
            v16 = (_BYTE*)(v6 + *(_DWORD*)(v13 + *(_DWORD*)& byte_5D4594[3798784] + 4));
            v40[4] = v15;
            v40[7] = v16;
            v40[3] = v15 - 1;
            v40[5] = v15 + 1;
            v40[6] = v16 - 1;
            v40[8] = v16 + 1;
            if (a4 > 0)
            {
                v32 = a4;
                while (1)
                {
                    if (*v40[0] == v9
                        || *v14 == v9
                        || *v40[2] == v9
                        || *v40[3] == v9
                        || *v15 == v9
                        || *v40[5] == v9
                        || *v40[6] == v9
                        || *v16 == v9
                        || *v40[8] == v9)
                    {
                        v17 = 0;
                        v18 = 0;
                        v19 = 0;
                        v20 = 0;
                        do
                        {
                            v21 = v40[v20];
                            v22 = *(_DWORD*)& byte_581450[v20 * 4 + 9680];
                            ++v20;
                            v23 = 4 * *v21;
                            v17 += v22 * byte_5D4594[v23 + 3803308];
                            v18 += v22 * byte_5D4594[v23 + 3803309];
                            v19 += v22 * byte_5D4594[v23 + 3803310];
                        } while (v20 < 9);
                        v24 = v17 / 12;
                        v25 = v19 / 12;
                        if (v17 / 12 > v34)
                            LOBYTE(v24) = v34;
                        v26 = v18 / 12;
                        if (v18 / 12 > v35)
                            LOBYTE(v26) = v35;
                        if (v25 > v36)
                            v25 = v36;
                        v6 = a2;
                        v13 = v41;
                        v27 = *(_BYTE*)(((v25 >> 3) & 0xFFFF | (unsigned __int16)(4 * (v26 & 0xF8 | (32 * (v24 & 0xF8)))))
                                        + *(_DWORD*)& byte_5D4594[810640]);
                        v9 = a1;
                        *v40[4] = v27;
                    }
                    v28 = (int*)v40;
                    v29 = 9;
                    do
                    {
                        v30 = *v28;
                        ++v28;
                        --v29;
                        *(v28 - 1) = v30 + 1;
                    } while (v29);
                    if (!--v32)
                        break;
                    v16 = v40[7];
                    v14 = v40[1];
                    v15 = v40[4];
                }
            }
            result = (int4*)(v33 - 1);
            v31 = v33 == 1;
            v41 = v13 + 4;
            --v33;
            if (v31)
                break;
            v13 += 4;
        }
    }
    return result;
}

//----- (0049E060) --------------------------------------------------------
int4* __cdecl sub_49E060(__int16 a1, int a2, int a3, int a4, int a5)
{
    int4* result; // eax
    int v6; // ebx
    int v7; // ebp
    int4* v8; // edx
    __int16 v9; // di
    int v10; // edx
    int v11; // ebx
    int v12; // esi
    _WORD* v13; // eax
    _WORD* v14; // ecx
    _WORD* v15; // edx
    int v16; // esi
    int v17; // eax
    int v18; // ebx
    unsigned __int16* v19; // edx
    int v20; // edi
    unsigned int v21; // edx
    int v22; // ecx
    int v23; // edi
    int v24; // eax
    __int16 v25; // ax
    int* v26; // eax
    int v27; // ecx
    bool v29; // zf
    int v30; // [esp+10h] [ebp-68h]
    int v31; // [esp+14h] [ebp-64h]
    int v32; // [esp+18h] [ebp-60h]
    int v33; // [esp+1Ch] [ebp-5Ch]
    int v34; // [esp+20h] [ebp-58h]
    int4 a3a; // [esp+24h] [ebp-54h]
    int4 a2a; // [esp+34h] [ebp-44h]
    int4 a1a; // [esp+44h] [ebp-34h]
    _WORD* v38[9];
    int v47; // [esp+80h] [ebp+8h]
    int v48; // [esp+84h] [ebp+Ch]
    int v49; // [esp+8Ch] [ebp+14h]

    if (ptr_5D4594_3799572->data[0])
    {
        a2a.field_0 = a2;
        a2a.field_8 = a4 + a2;
        a2a.field_4 = a3;
        a2a.field_C = a5 + a3;
        a3a.field_4 = 1;
        a3a.field_0 = 1;
        a3a.field_8 = nox_backbuffer_width - 1;
        a3a.field_C = nox_backbuffer_height - 1;
        result = sub_49F930(&a1a, &a2a, &a3a);
        if (!result)
            return result;
        v6 = a1a.field_0;
        v7 = a1a.field_4;
        a4 = a1a.field_8 - a1a.field_0;
        v8 = (int4*)(a1a.field_C - a1a.field_4);
    }
    else
    {
        v8 = (int4*)a5;
        v7 = a3;
        v6 = a2;
    }
    v9 = a1;
    v31 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & a1) >> byte_5D4594[3804376];
    v32 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & a1) >> byte_5D4594[3804380];
    v33 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & a1) << byte_5D4594[3804384];
    result = v8;
    v10 = (int)& v8[-1].field_C + 3;
    if (result)
    {
        v11 = 2 * v6;
        v12 = 4 * v7;
        v34 = v11;
        v47 = 4 * v7;
        v30 = v10 + 1;
        do
        {
            v13 = (_WORD*)(v11 + *(_DWORD*)(v12 + *(_DWORD*)& byte_5D4594[3798784] - 4));
            v38[1] = v13;
            v38[0] = v13 - 1;
            v38[2] = v13 + 1;
            v14 = (_WORD*)(v11 + *(_DWORD*)(v12 + *(_DWORD*)& byte_5D4594[3798784]));
            v15 = (_WORD*)(v11 + *(_DWORD*)(v12 + *(_DWORD*)& byte_5D4594[3798784] + 4));
            v38[4] = v14;
            v38[7] = v15;
            v38[3] = v14 - 1;
            v38[5] = v14 + 1;
            v38[6] = v15 - 1;
            v38[8] = v15 + 1;
            if (a4 > 0)
            {
                v48 = a4;
                while (1)
                {
                    if (*v38[0] == v9
                        || *v13 == v9
                        || *v38[2] == v9
                        || *v38[3] == v9
                        || *v14 == v9
                        || *v38[5] == v9
                        || *v38[6] == v9
                        || *v15 == v9
                        || *v38[8] == v9)
                    {
                        v16 = 0;
                        v17 = 0;
                        v18 = 0;
                        v49 = 0;
                        do
                        {
                            v19 = v38[v16];
                            v20 = *(_DWORD*)& byte_581450[v16 * 4 + 9680];
                            ++v16;
                            v21 = *v19;
                            v17 += v20 * ((*(_DWORD*)& byte_5D4594[3804364] & v21) >> byte_5D4594[3804376]);
                            v18 += v20 * ((*(_DWORD*)& byte_5D4594[3804368] & v21) >> byte_5D4594[3804380]);
                            v49 += v20 * ((*(_DWORD*)& byte_5D4594[3804372] & v21) << byte_5D4594[3804384]);
                        } while (v16 < 9);
                        v22 = v17 / 12;
                        v23 = v18 / 12;
                        v24 = v49 / 12;
                        if (v22 > v31)
                            v22 = v31;
                        if (v23 > v32)
                            v23 = v32;
                        if (v24 > v33)
                            v24 = v33;
                        v11 = v34;
                        v12 = v47;
                        v25 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656] + 2 * v23) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664]
                                                                                                + 2 * v24);
                        v9 = a1;
                        *v38[4] = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * v22) | v25;
                    }
                    v26 = (int*)v38;
                    for (v27 = 0; v27 < 9; v27++)
                    {
                        v26[v27] += 2;
                    }
                    if (!--v48)
                        break;
                    v15 = v38[7];
                    v14 = v38[4];
                    v13 = v38[1];
                }
            }
            v12 += 4;
            result = (int4*)(v30 - 1);
            v29 = v30 == 1;
            v47 = v12;
            --v30;
        } while (!v29);
    }
    return result;
}

//----- (0049E380) --------------------------------------------------------
void __cdecl sub_49E380(int a1, int a2, unsigned int a3)
{
    int v3; // edi
    signed int v4; // ecx

    if ((int)a3 > 0)
    {
        v3 = a1;
        v4 = a3 >> 2;
        if (a3 >> 2)
        {
            do
            {
                *(_DWORD*)v3 = a2;
                v3 += 4;
            } while (v4-- > 1);
        }
        if (a3 & 3)
        {
            *(_BYTE*)v3 = a2;
            if ((a3 & 3) != 1)
            {
                *(_BYTE*)(v3 + 1) = a2;
                if ((a3 & 3) != 2)
                    * (_BYTE*)(v3 + 2) = a2;
            }
        }
    }
}

//----- (0049E3C0) --------------------------------------------------------
void __cdecl sub_49E3C0(_DWORD* a1, int a2, unsigned int a3)
{
    _DWORD* v3; // edi
    signed int v4; // ecx

    if ((int)a3 > 0)
    {
        v3 = a1;
        v4 = a3 >> 2;
        if (a3 >> 2)
        {
            do
            {
                *v3 = a2;
                ++v3;
            } while (v4-- > 1);
        }
        if ((int)(a3 & 3) >= 2)
            * (_WORD*)v3 = a2;
    }
}

//----- (0049E3F0) --------------------------------------------------------
int sub_49E3F0()
{
    if (!*(_DWORD*)& byte_5D4594[3801780])
    {
        *(_DWORD*)& byte_5D4594[3798716] = sub_49E540;
        *(_DWORD*)& byte_5D4594[3798700] = sub_49EFC0;
        *(_DWORD*)& byte_5D4594[3798704] = sub_49ED80;
        *(_DWORD*)& byte_5D4594[3798720] = sub_49F060;
        *(_DWORD*)& byte_5D4594[3798708] = sub_49F0F0;
        *(_DWORD*)& byte_5D4594[3798712] = sub_49F3A0;
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[3801780] != 1)
        return 1;
    *(_DWORD*)& byte_5D4594[3798720] = sub_49F180;
    *(_DWORD*)& byte_5D4594[3798708] = sub_49F210;
    if (!*(_DWORD*)& byte_5D4594[3801804])
        * (_DWORD*)& byte_5D4594[3798708] = sub_49F180;
    *(_DWORD*)& byte_5D4594[3798712] = sub_49F420;
    *(_DWORD*)& byte_5D4594[3798716] = sub_49E930;
    *(_DWORD*)& byte_5D4594[3798700] = sub_49F010;
    *(_DWORD*)& byte_5D4594[3798704] = sub_49ED80;
    return 1;
}

//----- (0049E4B0) --------------------------------------------------------
int sub_49E4B0()
{
    return (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(0);
}

//----- (0049E4C0) --------------------------------------------------------
int __cdecl sub_49E4C0(int a1, int a2, int a3, int a4)
{
    sub_49F500(a1, a2);
    sub_49F500(a3, a4);
    return (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(0);
}

//----- (0049E4F0) --------------------------------------------------------
int __cdecl sub_49E4F0(int a1)
{
    return (*(int(__cdecl * *)(_DWORD, _DWORD)) & byte_5D4594[3798704])(a1, 0);
}

//----- (0049E510) --------------------------------------------------------
int __cdecl sub_49E510(int a1)
{
    int i; // esi

    for (i = a1 - 1; i > 0; --i)
    {
        if (!(*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(1))
            break;
    }
    return (*(int(__cdecl * *)(_DWORD)) & byte_5D4594[3798716])(0);
}

//----- (0049E540) --------------------------------------------------------
int __cdecl sub_49E540(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // eax
    int v4; // ecx
    int v5; // ebx
    int v6; // edi
    int v7; // edx
    int v8; // edi
    int v9; // edi
    int v10; // edx
    unsigned __int8 v11; // bl
    unsigned __int8* i; // edi
    bool v13; // cc
    int v14; // edi
    int v15; // ebx
    unsigned __int8 v16; // dl
    int v17; // [esp+Ch] [ebp-24h]
    int v18; // [esp+10h] [ebp-20h]
    int v19; // [esp+14h] [ebp-1Ch]
    int v20; // [esp+18h] [ebp-18h]
    int v21; // [esp+1Ch] [ebp-14h]
    int v22; // [esp+1Ch] [ebp-14h]
    int v23; // [esp+20h] [ebp-10h]
    int v24; // [esp+24h] [ebp-Ch]
    int v25; // [esp+28h] [ebp-8h]
    int v26; // [esp+2Ch] [ebp-4h]
    int v27; // [esp+38h] [ebp+8h]
    int v28; // [esp+38h] [ebp+8h]

    if (ptr_5D4594_3799572->data[13])
        return sub_49E6C0(a1);
    result = sub_49F5B0(&v25, &v23, 0);
    if (result)
    {
        result = sub_49F5B0(&v26, &v24, a1);
        if (result)
        {
            if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v26, &v24, &v25, &v23))
            {
                v2 = *(_DWORD*)& byte_5D4594[3798784];
                v3 = v26;
                v4 = v24;
                if (v26 == v25)
                {
                    (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798712])(v26, v24, v23);
                }
                else if (v24 == v23)
                {
                    (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(v26, v24, v25);
                }
                else
                {
                    v5 = v25 - v26;
                    v6 = 1;
                    if (v25 < v26)
                    {
                        v6 = -1;
                        v5 = v26 - v25;
                    }
                    v17 = v6;
                    v18 = v5;
                    v7 = v23 - v24;
                    v8 = 1;
                    if (v23 < v24)
                    {
                        v8 = -1;
                        v7 = v24 - v23;
                    }
                    v19 = v8;
                    v20 = v7;
                    if (v5 < v7)
                    {
                        v14 = v5;
                        v22 = 2 * v5;
                        v15 = 2 * v5 - v7;
                        v28 = 2 * (v14 - v7);
                        v16 = obj_5D4594_3800716.data[61];
                        while (1)
                        {
                            *(_BYTE*)(v3 + *(_DWORD*)(v2 + 4 * v4)) = v16;
                            v13 = v20-- < 1;
                            if (v13)
                                break;
                            v4 += v19;
                            if (v15 >= 0)
                            {
                                v15 += v28;
                                v3 += v17;
                            }
                            else
                            {
                                v15 += v22;
                            }
                        }
                    }
                    else
                    {
                        v9 = v7;
                        v21 = 2 * v7;
                        v10 = 2 * v7 - v5;
                        v27 = 2 * (v9 - v5);
                        v11 = obj_5D4594_3800716.data[61];
                        LABEL_18:
                        for (i = (unsigned __int8*)(v3 + *(_DWORD*)(v2 + 4 * v4)); ; i += v17)
                        {
                            *i = v11;
                            v13 = v18-- < 1;
                            if (v13)
                                break;
                            v3 += v17;
                            if (v10 >= 0)
                            {
                                v10 += v27;
                                v4 += v19;
                                goto LABEL_18;
                            }
                            v10 += v21;
                        }
                    }
                }
            }
            result = 1;
        }
    }
    return result;
}

//----- (0049E6C0) --------------------------------------------------------
int __cdecl sub_49E6C0(int a1)
{
    int result; // eax
    unsigned __int8* v2; // ecx
    int v3; // esi
    int v4; // ebx
    int v5; // edi
    int v6; // edx
    int v7; // edi
    int v8; // edi
    int v9; // edx
    _BYTE* i; // edi
    unsigned __int8* v11; // ecx
    bool v12; // cc
    int v13; // edi
    int v14; // ebx
    _BYTE* v15; // edi
    unsigned __int8* v16; // ecx
    __int16 v17; // [esp+0h] [ebp-38h]
    __int16 v18; // [esp+4h] [ebp-34h]
    int v19; // [esp+8h] [ebp-30h]
    int v20; // [esp+Ch] [ebp-2Ch]
    int v21; // [esp+10h] [ebp-28h]
    int v22; // [esp+14h] [ebp-24h]
    int v23; // [esp+18h] [ebp-20h]
    int v24; // [esp+1Ch] [ebp-1Ch]
    int v25; // [esp+1Ch] [ebp-1Ch]
    int v26; // [esp+20h] [ebp-18h]
    int v27; // [esp+20h] [ebp-18h]
    int v28; // [esp+28h] [ebp-10h]
    int v29; // [esp+2Ch] [ebp-Ch]
    int v30; // [esp+30h] [ebp-8h]
    int v31; // [esp+34h] [ebp-4h]

    result = sub_49F5B0(&v29, &v28, 0);
    if (result)
    {
        result = sub_49F5B0(&v30, &v31, a1);
        if (result)
        {
            if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v30, &v31, &v29, &v28))
            {
                v2 = &byte_5D4594[4 * obj_5D4594_3800716.data[61] + 3803308];
                v3 = *(_DWORD*)& byte_5D4594[3798784];
                v17 = *v2;
                v18 = v2[1];
                v19 = v2[2];
                v4 = v29 - v30;
                v5 = 1;
                if (v29 < v30)
                {
                    v5 = -1;
                    v4 = v30 - v29;
                }
                v20 = v5;
                v6 = v28 - v31;
                v21 = v4;
                v7 = 1;
                if (v28 < v31)
                {
                    v7 = -1;
                    v6 = v31 - v28;
                }
                v22 = v7;
                v23 = v6;
                if (v4 < v6)
                {
                    v13 = v4;
                    v25 = 2 * v4;
                    v14 = 2 * v4 - v6;
                    v27 = 2 * (v13 - v6);
                    while (1)
                    {
                        v15 = (_BYTE*)(v30 + *(_DWORD*)(v3 + 4 * v31));
                        v16 = &byte_5D4594[4 * (unsigned __int8)* v15 + 3803308];
                        *v15 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[810640]
                                         + (unsigned __int16)((4
                                                               * ((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) * (v18 - v16[1])) >> 8)
                                                                   + v16[1]) & 0xF8)) | (((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259])
                                                                                                               * (v17 - *v16)) >> 8)
                                                                                           + *v16) & 0xF8) << 7) | ((((*(_DWORD*)(&obj_5D4594_3800716.data[259])
                                                                                                                       * (v19 - (unsigned int)v16[2])) >> 8)
                                                                                                                     + v16[2]) >> 3)));
                        v12 = v23-- < 1;
                        if (v12)
                            break;
                        v31 += v22;
                        if (v14 >= 0)
                        {
                            v14 += v27;
                            v30 += v20;
                        }
                        else
                        {
                            v14 += v25;
                        }
                    }
                }
                else
                {
                    v8 = v6;
                    v24 = 2 * v6;
                    v9 = 2 * v6 - v4;
                    v26 = 2 * (v8 - v4);
                    LABEL_15:
                    for (i = (_BYTE*)(v30 + *(_DWORD*)(v3 + 4 * v31)); ; i += v20)
                    {
                        v11 = &byte_5D4594[4 * (unsigned __int8)* i + 3803308];
                        *i = *(_BYTE*)(*(_DWORD*)& byte_5D4594[810640]
                                       + (unsigned __int16)((4
                                                             * ((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) * (v18 - v11[1])) >> 8)
                                                                 + v11[1]) & 0xF8)) | (((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259])
                                                                                                             * (v17 - *v11)) >> 8)
                                                                                         + *v11) & 0xF8) << 7) | ((((*(_DWORD*)(&obj_5D4594_3800716.data[259])
                                                                                                                     * (v19
                                                                                                                        - (unsigned int)v11[2])) >> 8)
                                                                                                                   + v11[2]) >> 3)));
                        v12 = v21-- < 1;
                        if (v12)
                            break;
                        v30 += v20;
                        if (v9 >= 0)
                        {
                            v9 += v26;
                            v31 += v22;
                            goto LABEL_15;
                        }
                        v9 += v24;
                    }
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

//----- (0049E930) --------------------------------------------------------
int __cdecl sub_49E930(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // ecx
    int v4; // ebx
    int v5; // edi
    int v6; // edx
    int v7; // edi
    int v8; // eax
    int v9; // edi
    int v10; // edx
    __int16 v11; // bx
    _WORD* i; // edi
    bool v13; // cc
    int v14; // edi
    int v15; // ebx
    __int16 v16; // dx
    int v17; // [esp+Ch] [ebp-24h]
    int v18; // [esp+10h] [ebp-20h]
    int v19; // [esp+14h] [ebp-1Ch]
    int v20; // [esp+18h] [ebp-18h]
    int v21; // [esp+1Ch] [ebp-14h]
    int v22; // [esp+1Ch] [ebp-14h]
    int v23; // [esp+20h] [ebp-10h]
    int v24; // [esp+24h] [ebp-Ch]
    int v25; // [esp+28h] [ebp-8h]
    int v26; // [esp+2Ch] [ebp-4h]
    int v27; // [esp+38h] [ebp+8h]
    int v28; // [esp+38h] [ebp+8h]

    if (ptr_5D4594_3799572->data[13])
        return sub_49EAB0(a1);
    result = sub_49F5B0(&v25, &v23, 0);
    if (result)
    {
        result = sub_49F5B0(&v26, &v24, a1);
        if (result)
        {
            if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v26, &v24, &v25, &v23))
            {
                v2 = *(_DWORD*)& byte_5D4594[3798784];
                v3 = v24;
                if (v26 == v25)
                {
                    (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798712])(v26, v24, v23);
                }
                else if (v24 == v23)
                {
                    (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[3798720])(v26, v24, v25);
                }
                else
                {
                    v4 = v25 - v26;
                    v5 = 2;
                    if (v25 < v26)
                    {
                        v5 = -2;
                        v4 = v26 - v25;
                    }
                    v17 = v5;
                    v18 = v4;
                    v6 = v23 - v24;
                    v7 = 1;
                    if (v23 < v24)
                    {
                        v7 = -1;
                        v6 = v24 - v23;
                    }
                    v19 = v7;
                    v20 = v6;
                    v8 = 2 * v26;
                    if (v4 < v6)
                    {
                        v14 = v4;
                        v22 = 2 * v4;
                        v15 = 2 * v4 - v6;
                        v28 = 2 * (v14 - v6);
                        v16 = *(_WORD*)(&obj_5D4594_3800716.data[61]);
                        while (1)
                        {
                            *(_WORD*)(v8 + *(_DWORD*)(v2 + 4 * v3)) = v16;
                            v13 = v20-- < 1;
                            if (v13)
                                break;
                            v3 += v19;
                            if (v15 >= 0)
                            {
                                v15 += v28;
                                v8 += v17;
                            }
                            else
                            {
                                v15 += v22;
                            }
                        }
                    }
                    else
                    {
                        v9 = v6;
                        v21 = 2 * v6;
                        v10 = 2 * v6 - v4;
                        v27 = 2 * (v9 - v4);
                        v11 = *(_WORD*)(&obj_5D4594_3800716.data[61]);
                        LABEL_18:
                        for (i = (_WORD*)(v8 + *(_DWORD*)(v2 + 4 * v3)); ; i = (_WORD*)((char*)i + v17))
                        {
                            *i = v11;
                            v13 = v18-- < 1;
                            if (v13)
                                break;
                            v8 += v17;
                            if (v10 >= 0)
                            {
                                v10 += v27;
                                v3 += v19;
                                goto LABEL_18;
                            }
                            v10 += v21;
                        }
                    }
                }
            }
            result = 1;
        }
    }
    return result;
}

//----- (0049EAB0) --------------------------------------------------------
int __cdecl sub_49EAB0(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // ebx
    int v4; // edi
    int v5; // edx
    int v6; // edi
    int v7; // edi
    int v8; // edx
    __int16* i; // edi
    __int16 v10; // ax
    bool v11; // cc
    int v12; // edi
    int v13; // ebx
    __int16* v14; // edi
    __int16 v15; // ax
    int v16; // [esp+0h] [ebp-38h]
    int v17; // [esp+4h] [ebp-34h]
    int v18; // [esp+8h] [ebp-30h]
    int v19; // [esp+Ch] [ebp-2Ch]
    int v20; // [esp+10h] [ebp-28h]
    int v21; // [esp+14h] [ebp-24h]
    int v22; // [esp+18h] [ebp-20h]
    int v23; // [esp+1Ch] [ebp-1Ch]
    int v24; // [esp+1Ch] [ebp-1Ch]
    int v25; // [esp+20h] [ebp-18h]
    int v26; // [esp+20h] [ebp-18h]
    int v27; // [esp+28h] [ebp-10h]
    int v28; // [esp+2Ch] [ebp-Ch]
    int v29; // [esp+30h] [ebp-8h]
    int v30; // [esp+34h] [ebp-4h]

    result = sub_49F5B0(&v28, &v27, 0);
    if (result)
    {
        result = sub_49F5B0(&v29, &v30, a1);
        if (result)
        {
            if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v29, &v30, &v28, &v27))
            {
                v16 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & *(_WORD*)(&obj_5D4594_3800716.data[61])) >> byte_5D4594[3804376];
                v17 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & *(_WORD*)(&obj_5D4594_3800716.data[61])) >> byte_5D4594[3804380];
                v18 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & *(_WORD*)(&obj_5D4594_3800716.data[61])) << byte_5D4594[3804384];
                v2 = *(_DWORD*)& byte_5D4594[3798784];
                v3 = v28 - v29;
                v4 = 2;
                if (v28 < v29)
                {
                    v4 = -2;
                    v3 = v29 - v28;
                }
                v19 = v4;
                v5 = v27 - v30;
                v20 = v3;
                v6 = 1;
                if (v27 < v30)
                {
                    v6 = -1;
                    v5 = v30 - v27;
                }
                v21 = v6;
                v22 = v5;
                v29 *= 2;
                if (v3 < v5)
                {
                    v12 = v3;
                    v24 = 2 * v3;
                    v13 = 2 * v3 - v5;
                    v26 = 2 * (v12 - v5);
                    while (1)
                    {
                        v14 = (__int16*)(v29 + *(_DWORD*)(v2 + 4 * v30));
                        v15 = *v14;
                        *v14 = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656]
                                         + 2
                                           * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259])
                                                                                   * (v17
                                                                                      - ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v15) >> byte_5D4594[3804380]))) >> 8)
                                                               + ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v15) >> byte_5D4594[3804380]))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) * (v16 - ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v15) >> byte_5D4594[3804376]))) >> 8) + ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v15) >> byte_5D4594[3804376]))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) * (v18 - ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & v15) << byte_5D4594[3804384]))) >> 8) + ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & v15) << byte_5D4594[3804384])));
                        v11 = v22-- < 1;
                        if (v11)
                            break;
                        v30 += v21;
                        if (v13 >= 0)
                        {
                            v13 += v26;
                            v29 += v19;
                        }
                        else
                        {
                            v13 += v24;
                        }
                    }
                }
                else
                {
                    v7 = v5;
                    v23 = 2 * v5;
                    v8 = 2 * v5 - v3;
                    v25 = 2 * (v7 - v3);
                    LABEL_15:
                    for (i = (__int16*)(v29 + *(_DWORD*)(v2 + 4 * v30)); ; i = (__int16*)((char*)i + v19))
                    {
                        v10 = *i;
                        *i = *(_WORD*)(*(_DWORD*)& byte_5D4594[3804656]
                                       + 2
                                         * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259])
                                                                                 * (v17
                                                                                    - ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v10) >> byte_5D4594[3804380]))) >> 8)
                                                             + ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & v10) >> byte_5D4594[3804380]))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804672] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) * (v16 - ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v10) >> byte_5D4594[3804376]))) >> 8) + ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & v10) >> byte_5D4594[3804376]))) | *(_WORD*)(*(_DWORD*)& byte_5D4594[3804664] + 2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) * (v18 - ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & v10) << byte_5D4594[3804384]))) >> 8) + ((unsigned __int16)(*(_WORD*)& byte_5D4594[3804372] & v10) << byte_5D4594[3804384])));
                        v11 = v20-- < 1;
                        if (v11)
                            break;
                        v29 += v19;
                        if (v8 >= 0)
                        {
                            v8 += v25;
                            v30 += v21;
                            goto LABEL_15;
                        }
                        v8 += v23;
                    }
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

//----- (0049ED80) --------------------------------------------------------
int __cdecl sub_49ED80(unsigned __int8 a1, int a2)
{
    int result; // eax
    int v3; // edi
    int v4; // esi
    int* v5; // ebp
    int v6; // esi
    int v7; // ebx
    int v8; // ecx
    int v9; // edi
    int v10; // edi
    int v11; // ecx
    int v12; // edi
    int v13; // ebx
    int v14; // eax
    int v15; // esi
    int v16; // esi
    int v17; // ecx
    int v18; // [esp+0h] [ebp-1Ch]
    int v19; // [esp+4h] [ebp-18h]
    int v20; // [esp+8h] [ebp-14h]
    int v21; // [esp+Ch] [ebp-10h]
    int v22; // [esp+10h] [ebp-Ch]
    int v23; // [esp+14h] [ebp-8h]
    int v24; // [esp+18h] [ebp-4h]
    int v25; // [esp+20h] [ebp+4h]
    int v26; // [esp+20h] [ebp+4h]
    int v27; // [esp+24h] [ebp+8h]

    if (ptr_5D4594_3799572->data[13])
        return sub_49EAB0(a2);
    result = sub_49F5B0(&v22, &v23, 0);
    if (result)
    {
        result = sub_49F5B0(&v19, &v18, a2);
        if (result)
        {
            if (ptr_5D4594_3799572->data[0] && !sub_49F990(&v19, &v18, &v22, &v23))
                return 1;
            v3 = v22 - v19;
            v4 = v23 - v18;
            if (v19 <= v22)
            {
                v21 = v19 != v22;
            }
            else
            {
                v21 = -1;
                v3 = v19 - v22;
            }
            if (v18 <= v23)
            {
                v20 = v18 != v23;
            }
            else
            {
                v20 = -1;
                v4 = v18 - v23;
            }
            v5 = sub_4B0680(0, a1);
            v27 = 0;
            v24 = *v5 >> 2;
            if (v3 <= v4)
            {
                v26 = 2 * v3;
                v12 = 2 * (v3 - v4);
                v13 = v26 - v4;
                sub_4B0820((int)v5, v19, v18);
                v14 = v4;
                v15 = v4 - 1;
                if (v14)
                {
                    v16 = v15 + 1;
                    do
                    {
                        v17 = v20 + v18;
                        v18 += v20;
                        if (v13 >= 0)
                        {
                            v13 += v12;
                            v19 += v21;
                        }
                        else
                        {
                            v13 += v26;
                        }
                        if (++v27 >= v24)
                        {
                            sub_4B0820((int)v5, v19, v17);
                            v27 = 0;
                        }
                        --v16;
                    } while (v16);
                }
            }
            else
            {
                v25 = 2 * v4;
                v6 = 2 * (v4 - v3);
                v7 = v25 - v3;
                sub_4B0820((int)v5, v19, v18);
                v8 = v3;
                v9 = v3 - 1;
                if (v8)
                {
                    v10 = v9 + 1;
                    do
                    {
                        v11 = v21 + v19;
                        v19 += v21;
                        if (v7 >= 0)
                        {
                            v7 += v6;
                            v18 += v20;
                        }
                        else
                        {
                            v7 += v25;
                        }
                        if (++v27 >= v24)
                        {
                            sub_4B0820((int)v5, v11, v18);
                            v27 = 0;
                        }
                        --v10;
                    } while (v10);
                    return 1;
                }
            }
            return 1;
        }
    }
    return result;
}

//----- (0049EFA0) --------------------------------------------------------
int __cdecl sub_49EFA0(int a1, int a2)
{
    return (*(int(__cdecl * *)(_DWORD, _DWORD)) & byte_5D4594[3798700])(a1, a2);
}

//----- (0049EFC0) --------------------------------------------------------
int __cdecl sub_49EFC0(int a1, int a2)
{
    int result; // eax

    result = a1;
    if (!ptr_5D4594_3799572->data[0]
        || a1 <= ptr_5D4594_3799572->data[7]
           && a1 >= ptr_5D4594_3799572->data[5]
           && a2 >= ptr_5D4594_3799572->data[6]
           && a2 <= ptr_5D4594_3799572->data[8])
    {
        *(_BYTE*)(a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = ptr_5D4594_3799572->data[61];
    }
    return result;
}

//----- (0049F010) --------------------------------------------------------
int __cdecl sub_49F010(int a1, int a2)
{
    int result; // eax

    result = a1;
    if (!ptr_5D4594_3799572->data[0]
        || a1 <= ptr_5D4594_3799572->data[7]
           && a1 >= ptr_5D4594_3799572->data[5]
           && a2 >= ptr_5D4594_3799572->data[6]
           && a2 <= ptr_5D4594_3799572->data[8])
    {
        *(_WORD*)(a1 + a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2)) = ptr_5D4594_3799572->data[61];
    }
    return result;
}

//----- (0049F060) --------------------------------------------------------
void __cdecl sub_49F060(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // edi
    int v6; // esi
    int v7; // ecx
    unsigned int v9; // ecx
    int v10; // eax
    char* v11; // edi
    char v12; // bl
    unsigned int v13; // ecx
    char* v14; // edi
    int v15; // ebx
    int v16; // ebx

    v3 = a3;
    v4 = a1;
    if (a1 > a3)
    {
        v4 = a3;
        v3 = a1;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v5 = ptr_5D4594_3799572->data[7];
        if (v4 > v5)
            return;
        v6 = ptr_5D4594_3799572->data[5];
        if (v3 < v6
            || a2 < ptr_5D4594_3799572->data[6]
            || a2 > ptr_5D4594_3799572->data[8])
        {
            return;
        }
        if (v4 < v6)
            v4 = ptr_5D4594_3799572->data[5];
        if (v3 > v5)
            v3 = ptr_5D4594_3799572->data[7];
    }
    v7 = v3 - v4;
    v9 = v7 + 1;
    if ((int)v9 > 0)
    {
        v10 = ptr_5D4594_3799572->data[61];
        v11 = (char*)(v4 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2));
        v12 = v9;
        v13 = v9 >> 2;
        memset32(v11, v10, v13);
        v14 = &v11[4 * v13];
        v15 = v12 & 3;
        if (v15)
        {
            *v14 = v10;
            v16 = v15 - 1;
            if (v16)
            {
                v14[1] = v10;
                if (v16 != 1)
                    v14[2] = v10;
            }
        }
    }
}

//----- (0049F0F0) --------------------------------------------------------
unsigned __int8* __cdecl sub_49F0F0(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // esi
    int v5; // edx
    unsigned __int8* result; // eax
    int v7; // edx
    int v8; // ecx
    int v9; // esi
    int v10; // ecx
    unsigned __int8 v11; // [esp+10h] [ebp+4h]

    v3 = a1;
    v4 = a3;
    if (a1 > a3)
    {
        v3 = a3;
        v4 = a1;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v5 = ptr_5D4594_3799572->data[7];
        result = *(unsigned __int8**)(&ptr_5D4594_3799572->data[5]);
        if (v3 > v5
            || v4 < (int)result
            || a2 < ptr_5D4594_3799572->data[6]
            || a2 > ptr_5D4594_3799572->data[8])
        {
            return result;
        }
        if (v3 < (int)result)
            v3 = ptr_5D4594_3799572->data[5];
        if (v4 > v5)
            v4 = ptr_5D4594_3799572->data[7];
    }
    v7 = v3;
    result = (unsigned __int8*)(v3 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2));
    v8 = v3 + 1;
    if (v7 <= v4)
    {
        v11 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
        v9 = v4 - v8 + 2;
        do
        {
            v10 = *result++ << 8;
            --v9;
            *(result - 1) = *(_BYTE*)(v11 + v10 + *(_DWORD*)& byte_5D4594[810632]);
        } while (v9);
    }
    return result;
}

//----- (0049F180) --------------------------------------------------------
void __cdecl sub_49F180(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // edi
    int v6; // esi
    int v7; // ecx
    char v8; // cc
    unsigned int v9; // ecx
    int v10; // eax
    int v11; // edi
    char v12; // cf
    int v13; // ecx

    v3 = a3;
    v4 = a1;
    if (a1 > a3)
    {
        v4 = a3;
        v3 = a1;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v5 = ptr_5D4594_3799572->data[7];
        if (v4 > v5)
            return;
        v6 = ptr_5D4594_3799572->data[5];
        if (v3 < v6
            || a2 < ptr_5D4594_3799572->data[6]
            || a2 > ptr_5D4594_3799572->data[8])
        {
            return;
        }
        if (v4 < v6)
            v4 = ptr_5D4594_3799572->data[5];
        if (v3 > v5)
            v3 = ptr_5D4594_3799572->data[7];
    }
    v7 = v3 - v4;
    v9 = v7 + 1;
    if ((int)v9 > 0)
    {
        v10 = ptr_5D4594_3799572->data[61];
        v11 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) + 2 * v4;
        if (!(v11 & 2) || (*(_WORD*)v11 = v10, v11 += 2, --v9, v9))
        {
            v12 = v9 & 1;
            v13 = v9 >> 1;
            if (v13)
            {
                do
                {
                    *(_DWORD*)v11 = v10;
                    v11 += 4;
                    v8 = v13-- <= 1;
                } while (!v8);
            }
            if (v12)
                * (_WORD*)v11 = v10;
        }
    }
}

__int16 __cdecl sub_49F210(int a1, int a2, int a3)
{
    DebugBreak();
    return 0;
}
#if 0
//----- (0049F210) --------------------------------------------------------
__int16 __cdecl sub_49F210(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // eax
    int v6; // edi
    int v7; // esi
    int v8; // ecx
    int v9; // ecx
    __m64 v10; // mm4
    __m64 v11; // mm4
    __m64 v12; // mm5
    __m64 v13; // mm6
    __m64* v14; // edi
    __m64 v15; // mm4
    __m64 v16; // mm0
    __m64 v17; // mm1
    __m64 v18; // mm2
    __m64 v19; // mm0
    char v20; // cc
    _WORD* v21; // edi
    int v22; // ecx
    _WORD* v23; // edi
    __m64 v25; // [esp+Ch] [ebp-8h]

    v3 = a3;
    v4 = a1;
    if (a1 > a3)
    {
        LOWORD(v5) = a1;
        v4 = a3;
        v3 = a1;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v6 = ptr_5D4594_3799572->data[7];
        if (v4 > v6)
            return v5;
        v7 = ptr_5D4594_3799572->data[5];
        if (v3 < v7)
            return v5;
        v5 = ptr_5D4594_3799572->data[6];
        if (a2 < v5)
            return v5;
        v5 = ptr_5D4594_3799572->data[8];
        if (a2 > v5)
            return v5;
        if (v4 < v7)
            v4 = ptr_5D4594_3799572->data[5];
        if (v3 > v6)
            v3 = ptr_5D4594_3799572->data[7];
    }
    v8 = v3 - v4;
    v20 = (v8 + 1 < 0) ^ __OFADD__(1, v8) | (v8 == -1);
    v9 = v8 + 1;
    if (!v20)
    {
        v10 = _mm_cvtsi32_si64(ptr_5D4594_3799572->data[61]);
        v11 = _m_por(_m_psllqi(v10, 0x20u), v10);
        v12 = _m_psrlw(_m_pand(v11, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
        v13 = _m_psllw(_m_pand(v11, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
        v14 = (__m64*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * a2) + 2 * v4);
        v15 = _m_psrlw(_m_pand(v11, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
        while (1)
        {
            v16 = _m_psrlw(_m_pand((__m64)v14->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
            v17 = _m_psrlw(_m_pand((__m64)v14->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
            v18 = _m_psllw(_m_pand((__m64)v14->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
            v19 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(_m_paddw(v16, _m_psrlwi(_m_psubw(v15, v16), 1u)), *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(_m_paddw(v17, _m_psrlwi(_m_psubw(v12, v17), 1u)), *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(_m_paddw(v18, _m_psrlwi(_m_psubw(v13, v18), 1u)), *(__m64*) & byte_5D4594[3804460]));
            v20 = v9 < 4;
            v9 -= 4;
            if (v20)
                break;
            v14->m64_u64 = (unsigned __int64)v19;
            ++v14;
            if (v20)
                goto LABEL_20;
        }
        v25 = v19;
        LOWORD(v5) = v25.m64_i16[0];
        LOWORD(v14->m64_i32[0]) = v25.m64_i16[0];
        v21 = (_WORD*)((char*)v14->m64_i32 + 2);
        v22 = v9 + 3;
        if (v22)
        {
            LOWORD(v5) = v25.m64_i16[1];
            *v21 = v25.m64_i16[1];
            v23 = v21 + 1;
            if (v22 != 1)
            {
                LOWORD(v5) = v25.m64_i16[2];
                *v23 = v25.m64_i16[2];
            }
        }
    }
LABEL_20:
    _m_femms();
    return v5;
}
#endif
//----- (0049F3A0) --------------------------------------------------------
void __cdecl sub_49F3A0(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // edi
    int v6; // esi
    int v7; // ecx
    char v8; // cc
    int v9; // ecx
    char v10; // al
    _DWORD* v11; // esi
    _BYTE* v12; // edi

    v3 = a3;
    v4 = a2;
    if (a2 > a3)
    {
        v4 = a3;
        v3 = a2;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v5 = ptr_5D4594_3799572->data[8];
        if (v4 > v5)
            return;
        v6 = ptr_5D4594_3799572->data[6];
        if (v3 < v6
            || a1 < ptr_5D4594_3799572->data[5]
            || a1 > ptr_5D4594_3799572->data[7])
        {
            return;
        }
        if (v4 < v6)
            v4 = ptr_5D4594_3799572->data[6];
        if (v3 > v5)
            v3 = ptr_5D4594_3799572->data[8];
    }
    v7 = v3 - v4;
    v9 = v7 + 1;
    if ((int)v9 > 0)
    {
        v10 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
        v11 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v4);
        do
        {
            v12 = (_BYTE*)(a1 + *v11);
            ++v11;
            *v12 = v10;
            v8 = v9-- <= 1;
        } while (!v8);
    }
}

//----- (0049F420) --------------------------------------------------------
void __cdecl sub_49F420(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // edi
    int v6; // esi
    int v7; // ecx
    char v8; // cc
    int v9; // ecx
    __int16 v10; // ax
    _DWORD* v11; // esi
    _WORD* v12; // edi

    v3 = a3;
    v4 = a2;
    if (a2 > a3)
    {
        v4 = a3;
        v3 = a2;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v5 = ptr_5D4594_3799572->data[8];
        if (v4 > v5)
            return;
        v6 = ptr_5D4594_3799572->data[6];
        if (v3 < v6
            || a1 < ptr_5D4594_3799572->data[5]
            || a1 > ptr_5D4594_3799572->data[7])
        {
            return;
        }
        if (v4 < v6)
            v4 = ptr_5D4594_3799572->data[6];
        if (v3 > v5)
            v3 = ptr_5D4594_3799572->data[8];
    }
    v7 = v3 - v4;
    v9 = v7 + 1;
    if ((int)v9 > 0)
    {
        v10 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
        v11 = (_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v4);
        do
        {
            v12 = (_WORD*)(2 * a1 + *v11);
            ++v11;
            *v12 = v10;
            v8 = v9-- <= 1;
        } while (!v8);
    }
}

//----- (0049F4A0) --------------------------------------------------------
BOOL sub_49F4A0()
{
    *(_DWORD*)& byte_5D4594[1305724] = 32;
    *(_DWORD*)& byte_5D4594[3798692] = 0;
    *(_DWORD*)& byte_5D4594[3798696] = nox_calloc(0x20u, 8u);
    return *(_DWORD*)& byte_5D4594[3798696] != 0;
}

//----- (0049F4D0) --------------------------------------------------------
void sub_49F4D0()
{
    if (*(_DWORD*)& byte_5D4594[3798696])
    {
        free(*(LPVOID*)& byte_5D4594[3798696]);
        *(_DWORD*)& byte_5D4594[3798696] = 0;
        *(_DWORD*)& byte_5D4594[3798692] = 0;
    }
}

//----- (0049F500) --------------------------------------------------------
int __cdecl sub_49F500(int a1, int a2)
{
    if (*(_DWORD*)& byte_5D4594[3798692] >= *(int*)& byte_5D4594[1305724])
    {
        *(_DWORD*)& byte_5D4594[1305724] += 16;
        *(_DWORD*)& byte_5D4594[3798696] = realloc(*(LPVOID*)& byte_5D4594[3798696], 8 * *(_DWORD*)& byte_5D4594[1305724]);
    }
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692]) = a1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] + 4) = a2;
    return ++ * (_DWORD*)& byte_5D4594[3798692];
}

//----- (0049F570) --------------------------------------------------------
int __cdecl sub_49F570(int a1, int a2)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[3798692];
    if (*(_DWORD*)& byte_5D4594[3798692])
        result = sub_49F500(
                a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] - 8),
                a2 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] - 4));
    return result;
}

//----- (0049F5A0) --------------------------------------------------------
void sub_49F5A0()
{
    *(_DWORD*)& byte_5D4594[3798692] = 0;
}

//----- (0049F5B0) --------------------------------------------------------
int __cdecl sub_49F5B0(_DWORD* a1, _DWORD* a2, int a3)
{
    int v3; // ecx

    if (*(int*)& byte_5D4594[3798692] <= 0)
        return 0;
    v3 = -- * (_DWORD*)& byte_5D4594[3798692];
    if (a1)
        * a1 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * v3);
    if (a2)
        * a2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798696] + 8 * *(_DWORD*)& byte_5D4594[3798692] + 4);
    if (a3)
        ++* (_DWORD*)& byte_5D4594[3798692];
    return 1;
}

//----- (0049F610) --------------------------------------------------------
int sub_49F610()
{
    ptr_5D4594_3799572->data[0] = 0;
    ptr_5D4594_3799572->data[9] = 0;
    ptr_5D4594_3799572->data[1] = 0;
    ptr_5D4594_3799572->data[10] = 0;
    ptr_5D4594_3799572->data[2] = 0;
    ptr_5D4594_3799572->data[11] = nox_backbuffer_width;
    ptr_5D4594_3799572->data[3] = nox_backbuffer_width;
    ptr_5D4594_3799572->data[12] = nox_backbuffer_height;
    ptr_5D4594_3799572->data[4] = nox_backbuffer_height;
    ptr_5D4594_3799572->data[5] = 0;
    ptr_5D4594_3799572->data[6] = 0;
    ptr_5D4594_3799572->data[7] = nox_backbuffer_width - 1;
    ptr_5D4594_3799572->data[8] = nox_backbuffer_height - 1;
    *(_DWORD*)& byte_5D4594[1305748] = 0;
    return 1;
}

//----- (0049F6D0) --------------------------------------------------------
int __cdecl sub_49F6D0(int a1)
{
    int result; // eax

    result = ptr_5D4594_3799572->data[0];
    ptr_5D4594_3799572->data[0] = a1;
    return result;
}

//----- (0049F6E0) --------------------------------------------------------
int sub_49F6E0()
{
    return ptr_5D4594_3799572->data[0];
}

//----- (0049F6F0) --------------------------------------------------------
int4* __cdecl sub_49F6F0(int xLeft, int yTop, int a3, int a4)
{
    int4* result; // eax
    RECT rcSrc; // [esp+0h] [ebp-20h]
    RECT rc; // [esp+10h] [ebp-10h]

    SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
    result = sub_49F930((int4*)& rcSrc, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[9]));
    if (result)
    {
        CopyRect((LPRECT)(&ptr_5D4594_3799572->data[1]), &rcSrc);
        --rcSrc.right;
        --rcSrc.bottom;
        result = (int4*)CopyRect((LPRECT)(&ptr_5D4594_3799572->data[5]), &rcSrc);
    }
    return result;
}

//----- (0049F780) --------------------------------------------------------
int4* __cdecl sub_49F780(int xLeft, int a2)
{
    int v2; // esi
    int v3; // eax

    v2 = xLeft;
    if (xLeft < ptr_5D4594_3799572->data[1])
        v2 = ptr_5D4594_3799572->data[1];
    v3 = a2;
    if (a2 > ptr_5D4594_3799572->data[3])
        v3 = ptr_5D4594_3799572->data[3];
    return sub_49F6F0(
            v2,
            ptr_5D4594_3799572->data[2],
            v3 - v2,
            ptr_5D4594_3799572->data[4] - ptr_5D4594_3799572->data[2]);
}

//----- (0049F7C0) --------------------------------------------------------
int4* __cdecl sub_49F7C0(int a1)
{
    int v1; // eax

    v1 = a1;
    if (a1 > ptr_5D4594_3799572->data[4])
        v1 = ptr_5D4594_3799572->data[4];
    return sub_49F6F0(
            ptr_5D4594_3799572->data[1],
            ptr_5D4594_3799572->data[2],
            ptr_5D4594_3799572->data[3] - ptr_5D4594_3799572->data[1],
            v1 - ptr_5D4594_3799572->data[2]);
}

//----- (0049F7F0) --------------------------------------------------------
int sub_49F7F0()
{
    int result; // eax
    int v1; // edx

    result = *(_DWORD*)& byte_5D4594[1305748];
    if (!*(_DWORD*)& byte_5D4594[1305748])
    {
        *(_DWORD*)& byte_5D4594[1305772] = ptr_5D4594_3799572->data[0];
        result = (_DWORD)(&ptr_5D4594_3799572->data[5]);
        *(_DWORD*)& byte_5D4594[1305756] = ptr_5D4594_3799572->data[1];
        *(_DWORD*)& byte_5D4594[1305760] = ptr_5D4594_3799572->data[2];
        *(_DWORD*)& byte_5D4594[1305764] = ptr_5D4594_3799572->data[3];
        *(_DWORD*)& byte_5D4594[1305768] = ptr_5D4594_3799572->data[4];
        *(_DWORD*)& byte_5D4594[1305732] = ptr_5D4594_3799572->data[5];
        *(_DWORD*)& byte_5D4594[1305736] = ptr_5D4594_3799572->data[6];
        *(_DWORD*)& byte_5D4594[1305740] = ptr_5D4594_3799572->data[7];
        v1 = ptr_5D4594_3799572->data[8];
        *(_DWORD*)& byte_5D4594[1305748] = 1;
        *(_DWORD*)& byte_5D4594[1305744] = v1;
    }
    return result;
}

//----- (0049F860) --------------------------------------------------------
int sub_49F860()
{
    int result; // eax
    _DWORD* v1; // edx
    _DWORD* v2; // edx

    result = *(_DWORD*)& byte_5D4594[1305748];
    if (*(_DWORD*)& byte_5D4594[1305748])
    {
        ptr_5D4594_3799572->data[0] = *(_DWORD*)& byte_5D4594[1305772];
        v1 = &ptr_5D4594_3799572->data[1];
        ptr_5D4594_3799572->data[1] = *(_DWORD*)& byte_5D4594[1305756];
        v1[1] = *(_DWORD*)& byte_5D4594[1305760];
        v1[2] = *(_DWORD*)& byte_5D4594[1305764];
        v1[3] = *(_DWORD*)& byte_5D4594[1305768];
        v2 = &ptr_5D4594_3799572->data[5];
        ptr_5D4594_3799572->data[5] = *(_DWORD*)& byte_5D4594[1305732];
        v2[1] = *(_DWORD*)& byte_5D4594[1305736];
        result = *(_DWORD*)& byte_5D4594[1305740];
        v2[2] = *(_DWORD*)& byte_5D4594[1305740];
        v2[3] = *(_DWORD*)& byte_5D4594[1305744];
        *(_DWORD*)& byte_5D4594[1305748] = 0;
    }
    return result;
}

//----- (0049F8E0) --------------------------------------------------------
BOOL __cdecl sub_49F8E0(int a1, int a2, int a3)
{
    return a1 - a3 < ptr_5D4594_3799572->data[1]
           || a3 + a1 >= ptr_5D4594_3799572->data[3]
           || a2 - a3 < ptr_5D4594_3799572->data[2]
           || a3 + a2 >= ptr_5D4594_3799572->data[4];
}

//----- (0049F930) --------------------------------------------------------
int4* __cdecl sub_49F930(int4* a1, int4* a2, int4* a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // ebx
    int v6; // edi
    int4* result; // eax

    v3 = a3->field_0;
    if (a2->field_0 >= a3->field_0)
        v3 = a2->field_0;
    v4 = a3->field_8;
    if (a2->field_8 <= v4)
        v4 = a2->field_8;
    if (v3 >= v4)
        return 0;
    v5 = a3->field_4;
    if (a2->field_4 >= v5)
        v5 = a2->field_4;
    v6 = a3->field_C;
    if (a2->field_C <= v6)
        v6 = a2->field_C;
    if (v5 >= v6)
        return 0;
    result = a1;
    a1->field_0 = v3;
    a1->field_4 = v5;
    a1->field_8 = v4;
    a1->field_C = v6;
    return result;
}

//----- (0049F990) --------------------------------------------------------
int __cdecl sub_49F990(int* a1, int* a2, int* a3, int* a4)
{
    int v4; // ebx
    int v5; // edi
    int v6; // esi
    int v7; // ecx
    int v8; // ebp
    int v9; // eax
    int v10; // edx
    int v12; // eax
    int v13; // eax
    int v14; // edx
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // edx
    int v19; // eax
    int v20; // [esp+10h] [ebp-14h]
    int v21; // [esp+10h] [ebp-14h]
    int v22; // [esp+14h] [ebp-10h]
    int v23; // [esp+18h] [ebp-Ch]
    int v24; // [esp+1Ch] [ebp-8h]
    int v25; // [esp+20h] [ebp-4h]

    v4 = ptr_5D4594_3799572->data[5];
    v24 = ptr_5D4594_3799572->data[8];
    v23 = ptr_5D4594_3799572->data[6];
    v5 = *a2;
    v25 = ptr_5D4594_3799572->data[7];
    v6 = *a3;
    v7 = *a1;
    v8 = *a4;
    v9 = 0;
    if (*a1 >= v4)
    {
        if (v7 > ptr_5D4594_3799572->data[7])
            v9 = 2;
    }
    else
    {
        v9 = 1;
    }
    if (v5 >= v23)
    {
        if (v5 > v24)
            LOBYTE(v9) = v9 | 4;
    }
    else
    {
        LOBYTE(v9) = v9 | 8;
    }
    v22 = 0;
    if (v6 >= v4)
    {
        if (v6 > v25)
            v22 = 2;
    }
    else
    {
        v22 = 1;
    }
    if (v8 >= v23)
    {
        if (v8 <= v24)
            goto LABEL_18;
        v10 = v22 | 4;
    }
    else
    {
        v10 = v22 | 8;
    }
    v22 = v10;
    LABEL_18:
    if (!(v9 | v22))
        return 1;
    if (v9 & v22)
        return 0;
    if (v9)
    {
        if (v9 & 8)
        {
            if (v8 == v5)
                return 0;
            v12 = (v23 - v5) * (v6 - v7) / (v8 - v5);
            v5 = ptr_5D4594_3799572->data[6];
            v7 += v12;
        }
        else if (v9 & 4)
        {
            if (v8 == v5)
                return 0;
            v13 = (v24 - v5) * (v6 - v7) / (v8 - v5);
            v5 = ptr_5D4594_3799572->data[8];
            v7 += v13;
        }
        if (v7 <= v25)
        {
            if (v7 < v4)
            {
                if (v6 == v7)
                    return 0;
                v15 = (v4 - v7) * (v8 - v5) / (v6 - v7);
                v7 = ptr_5D4594_3799572->data[5];
                v5 += v15;
            }
        }
        else
        {
            v20 = v6 - v7;
            if (v6 == v7)
                return 0;
            v14 = v25 - v7;
            v7 = ptr_5D4594_3799572->data[7];
            v5 += v14 * (v8 - v5) / v20;
        }
    }
    if (v22)
    {
        if (v22 & 8)
        {
            if (v8 == v5)
                return 0;
            v16 = (v6 - v7) * (v23 - v8) / (v8 - v5);
            v8 = ptr_5D4594_3799572->data[6];
            v6 += v16;
        }
        else if (v22 & 4)
        {
            if (v8 == v5)
                return 0;
            v17 = (v6 - v7) * (v24 - v8) / (v8 - v5);
            v8 = ptr_5D4594_3799572->data[8];
            v6 += v17;
        }
        if (v6 <= v25)
        {
            if (v6 < v4)
            {
                if (v6 == v7)
                    return 0;
                v19 = (v4 - v6) * (v8 - v5) / (v6 - v7);
                v6 = ptr_5D4594_3799572->data[5];
                v8 += v19;
            }
        }
        else
        {
            v21 = v6 - v7;
            if (v6 == v7)
                return 0;
            v18 = v25 - v6;
            v6 = ptr_5D4594_3799572->data[7];
            v8 += v18 * (v8 - v5) / v21;
        }
    }
    *a1 = v7;
    *a2 = v5;
    *a3 = v6;
    *a4 = v8;
    if (v7 >= v4 && v7 <= v25 && v5 >= v23 && v5 <= v24 && v6 >= v4 && v6 <= v25 && v8 >= v23 && v8 <= v24)
        return 1;
    return 0;
}

//----- (0049FC20) --------------------------------------------------------
int __cdecl sub_49FC20(int* a1, int* a2, int* a3, int* a4)
{
    int v4; // ebx
    int v5; // eax
    int v6; // ebp
    int v7; // edi
    int v8; // ecx
    int v9; // esi
    int v11; // eax
    int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // [esp+10h] [ebp-Ch]
    int v16; // [esp+14h] [ebp-8h]
    int v17; // [esp+18h] [ebp-4h]

    if (ptr_5D4594_3799572->data[0])
    {
        v4 = ptr_5D4594_3799572->data[6];
        v5 = ptr_5D4594_3799572->data[8];
        v15 = ptr_5D4594_3799572->data[8];
    }
    else
    {
        v4 = 0;
        v5 = nox_backbuffer_height - 1;
        v15 = nox_backbuffer_height - 1;
    }
    v16 = 0;
    v6 = *a1;
    v7 = *a3;
    v8 = *a2;
    v9 = *a4;
    if (*a2 >= v4)
    {
        if (v8 > v5)
            v16 = 4;
    }
    else
    {
        v16 = 8;
    }
    v17 = 0;
    if (v9 >= v4)
    {
        if (v9 > v5)
            v17 = 4;
    }
    else
    {
        v17 = 8;
    }
    if (v17 & v16)
        return 0;
    if (v16)
    {
        if (v16 & 8)
        {
            if (v9 == v8)
                return 0;
            v11 = (v4 - v8) * (v7 - v6) / (v9 - v8);
            v8 = v4;
            v6 += v11;
        }
        else if (v16 & 4)
        {
            if (v9 == v8)
                return 0;
            v12 = (v15 - v8) * (v7 - v6) / (v9 - v8);
            v8 = v15;
            v6 += v12;
        }
    }
    if (v17)
    {
        if (v17 & 8)
        {
            if (v9 == v8)
                return 0;
            v13 = (v7 - v6) * (v4 - v9) / (v9 - v8);
            v9 = v4;
            v7 += v13;
        }
        else if (v17 & 4)
        {
            if (v9 == v8)
                return 0;
            v14 = (v7 - v6) * (v15 - v9) / (v9 - v8);
            v9 = v15;
            v7 += v14;
        }
    }
    *a1 = v6;
    *a2 = v8;
    *a3 = v7;
    *a4 = v9;
    return 1;
}

//----- (0049FDB0) --------------------------------------------------------
void __cdecl sub_49FDB0(int a1)
{
    unsigned __int8* v1; // ebx
    int j; // esi
    int v3; // eax
    unsigned __int8* v4; // ebx
    int i; // esi
    int v6; // eax
    int v7; // [esp+0h] [ebp-90h]
    char v8[140]; // [esp+4h] [ebp-8Ch]

    if (!*(_DWORD*)& byte_5D4594[1305788])
    {
        if (sub_43AF70())
        {
            v7 = 0;
            if (*(_DWORD*)& byte_587000[4 * a1 + 166016] > 0)
            {
                v4 = &byte_587000[80 * a1 + 166032];
                do
                {
                    for (i = 0; i < (char)* v4; ++i)
                    {
                        v6 = 8 * (12 * a1 + (char)v4[i + 1]);
                        sub_420DA0(*(float*)& byte_587000[v6 + 165360], *(float*)& byte_587000[v6 + 165364]);
                    }
                    strcpy(&v8[4], *((const char**)v4 + 3));
                    sub_4211D0((int)v8);
                    sub_4214D0();
                    v4 += 16;
                    ++v7;
                } while (v7 < *(int*)& byte_587000[4 * a1 + 166016]);
            }
        }
        else
        {
            v1 = &byte_587000[165744];
            do
            {
                for (j = 0; j < (char)* v1; ++j)
                {
                    v3 = 8 * (char)v1[j + 1];
                    sub_420DA0(*(float*)& byte_587000[v3 + 165104], *(float*)& byte_587000[v3 + 165108]);
                }
                strcpy(&v8[4], *((const char**)v1 + 3));
                sub_4211D0((int)v8);
                sub_4214D0();
                v1 += 16;
            } while ((int)v1 < (int)& byte_587000[166016]);
        }
        *(_DWORD*)& byte_5D4594[1305788] = 1;
    }
}

//----- (0049FF20) --------------------------------------------------------
_DWORD* sub_49FF20()
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1305788];
    if (*(_DWORD*)& byte_5D4594[1305788])
    {
        result = sub_421B10();
        *(_DWORD*)& byte_5D4594[1305788] = 0;
    }
    return result;
}

//----- (0049FF40) --------------------------------------------------------
char* __cdecl sub_49FF40(__int16* a1)
{
    int v1; // edx
    struc_19* v2; // eax
    char* result; // eax
    int2 v4; // [esp+0h] [ebp-8h]

    v1 = a1[1] + 10;
    v4.field_0 = *a1 + 10;
    v4.field_4 = v1;
    v2 = sub_4217B0(&v4, 0);
    if (v2 || (v2 = (struc_19*)sub_421990(&v4, 100.0, 0)) != 0)
        result = (char*)& v2->field_0[1];
    else
        result = *(char**)& byte_587000[165756];
    return result;
}

//----- (0049FFA0) --------------------------------------------------------
int* __cdecl sub_49FFA0(int a1)
{
    int* result; // eax
    int* v2; // esi
    int* v3; // edi

    if (!*(_DWORD*)& byte_5D4594[1305808])
        sub_425760(&byte_5D4594[1305796]);
    result = sub_425890((int*)& byte_5D4594[1305796]);
    v2 = result;
    if (result)
    {
        do
        {
            v3 = sub_4258A0(v2);
            sub_425920((_DWORD * *)v2);
            if (a1)
                sub_46C4E0((_DWORD*)v2[7]);
            free(v2);
            v2 = v3;
        } while (v3);
        *(_DWORD*)& byte_5D4594[1305808] = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1305808] = 1;
    }
    return result;
}

//----- (004A0020) --------------------------------------------------------
char* sub_4A0020()
{
    return (char*)& byte_5D4594[1305796];
}

//----- (004A0030) --------------------------------------------------------
int __cdecl sub_4A0030(const void* a1)
{
    _DWORD* v1; // ebx
    int v2; // esi
    int* v3; // edi
    int v5; // ecx
    wchar_t* v6; // ebp
    wchar_t* v7; // eax
    wchar_t* v8; // ebp
    wchar_t* v9; // eax

    v1 = nox_calloc(1u, 0xA9u);
    qmemcpy(v1, a1, 0xA9u);
    v2 = 0;
    switch (*(_DWORD*)& byte_587000[166704])
    {
        case 0:
            if (*(unsigned __int8**)& byte_5D4594[1305800] == &byte_5D4594[1305796])
                return sub_425790((int*)& byte_5D4594[1305796], v1);
            v3 = sub_425890((int*)& byte_5D4594[1305796]);
            if (!v3)
                goto LABEL_6;
            do
            {
                if (_strcmpi((const char*)v1 + 120, (const char*)v3 + 120) <= 0)
                    goto LABEL_24;
                ++v2;
                v3 = sub_4258A0(v3);
            } while (v3);
            goto LABEL_6;
        case 1:
            if (*(unsigned __int8**)& byte_5D4594[1305800] == &byte_5D4594[1305796])
                return sub_425790((int*)& byte_5D4594[1305796], v1);
            v3 = sub_425890((int*)& byte_5D4594[1305796]);
            if (!v3)
                goto LABEL_6;
            while (_strcmpi((const char*)v1 + 120, (const char*)v3 + 120) < 0)
            {
                ++v2;
                v3 = sub_4258A0(v3);
                if (!v3)
                    goto LABEL_6;
            }
            goto LABEL_24;
        case 2:
            v5 = *((unsigned __int8*)v1 + 103);
            goto LABEL_29;
        case 3:
            v1[2] = 32 - *((unsigned __int8*)v1 + 103);
            return sub_425790((int*)& byte_5D4594[1305796], v1);
        case 4:
            if (*(unsigned __int8**)& byte_5D4594[1305800] == &byte_5D4594[1305796])
                return sub_425790((int*)& byte_5D4594[1305796], v1);
            v6 = sub_43BCB0(*(_WORD*)((char*)v1 + 163));
            v3 = sub_425890((int*)& byte_5D4594[1305796]);
            if (!v3)
                goto LABEL_6;
            while (1)
            {
                v7 = sub_43BCB0(*(_WORD*)((char*)v3 + 163));
                if (nox_wcscmp(v6, v7) <= 0)
                    goto LABEL_24;
                ++v2;
                v3 = sub_4258A0(v3);
                if (!v3)
                    goto LABEL_6;
            }
        case 5:
            if (*(unsigned __int8**)& byte_5D4594[1305800] == &byte_5D4594[1305796])
                return sub_425790((int*)& byte_5D4594[1305796], v1);
            v8 = sub_43BCB0(*(_WORD*)((char*)v1 + 163));
            v3 = sub_425890((int*)& byte_5D4594[1305796]);
            if (!v3)
                goto LABEL_6;
            break;
        case 6:
            v5 = v1[24];
            goto LABEL_29;
        case 7:
            v1[2] = 1000 - v1[24];
            return sub_425790((int*)& byte_5D4594[1305796], v1);
        case 8:
            v5 = v1[25] & 0x30;
        LABEL_29:
            v1[2] = v5;
            return sub_425790((int*)& byte_5D4594[1305796], v1);
        case 9:
            v1[2] = 48 - (v1[25] & 0x30);
            return sub_425790((int*)& byte_5D4594[1305796], v1);
        default:
            return 0;
    }
    while (1)
    {
        v9 = sub_43BCB0(*(_WORD*)((char*)v3 + 163));
        if (nox_wcscmp(v8, v9) >= 0)
            break;
        ++v2;
        v3 = sub_4258A0(v3);
        if (!v3)
        {
            LABEL_6:
            sub_4258E0((int)& byte_5D4594[1305796], v1);
            return v2;
        }
    }
    LABEL_24:
    sub_4258E0((int)v3, v1);
    return v2;
}

//----- (004A0290) --------------------------------------------------------
int __cdecl sub_4A0290(int a1)
{
    int result; // eax

    result = a1 - 10047;
    switch (a1)
    {
        case 10047:
            result = *(_DWORD*)& byte_587000[166704];
            *(_DWORD*)& byte_587000[166704] = *(_DWORD*)& byte_587000[166704] == 0;
            break;
        case 10048:
            *(_DWORD*)& byte_587000[166704] = (*(_DWORD*)& byte_587000[166704] == 2) + 2;
            break;
        case 10049:
            result = (*(_DWORD*)& byte_587000[166704] == 4) + 4;
            *(_DWORD*)& byte_587000[166704] = (*(_DWORD*)& byte_587000[166704] == 4) + 4;
            break;
        case 10050:
            *(_DWORD*)& byte_587000[166704] = (*(_DWORD*)& byte_587000[166704] == 6) + 6;
            break;
        case 10051:
            *(_DWORD*)& byte_587000[166704] = (*(_DWORD*)& byte_587000[166704] == 8) + 8;
            break;
        default:
            return result;
    }
    return result;
}

//----- (004A0330) --------------------------------------------------------
int __cdecl sub_4A0330(int* a1)
{
    int v1; // esi
    int* i; // eax

    v1 = 0;
    for (i = sub_425890((int*)& byte_5D4594[1305796]); i; i = sub_4258A0(i))
    {
        if (i == a1)
            break;
        ++v1;
    }
    return v1;
}

//----- (004A0360) --------------------------------------------------------
int* sub_4A0360()
{
    int* result; // eax
    int* i; // esi

    result = sub_425890((int*)& byte_5D4594[1305796]);
    for (i = result; result; i = result)
    {
        sub_43B7C0((int)i);
        result = sub_4258A0(i);
    }
    return result;
}

//----- (004A0390) --------------------------------------------------------
int* sub_4A0390()
{
    _DWORD* v0; // ecx
    int* v1; // esi
    int* v2; // edi
    int v4[3]; // [esp+0h] [ebp-Ch]
    _DWORD* v5; // [esp+4h] [ebp-8h]

    sub_425760(&v4);
    v0 = *(_DWORD * *)& byte_5D4594[1305800];
    v4[0] = *(_DWORD*)& byte_5D4594[1305796];
    v5 = *(_DWORD * *)& byte_5D4594[1305800];
    if (*(_DWORD*)& byte_5D4594[1305796])
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1305796] + 4) = &v4;
        v0 = v5;
    }
    if (v0)
        * v0 = &v4;
    sub_425760(&byte_5D4594[1305796]);
    v1 = sub_425890(&v4);
    if (v1)
    {
        do
        {
            v2 = sub_4258A0(v1);
            sub_4A0030(v1);
            v1 = v2;
        } while (v2);
    }
    return sub_4A0360();
}

//----- (004A0410) --------------------------------------------------------
int __cdecl sub_4A0410(const char* a1, __int16 a2)
{
    int* v2; // edi

    v2 = sub_425890((int*)& byte_5D4594[1305796]);
    if (!v2)
        return 1;
    while (strcmp(a1, (const char*)v2 + 12) || a2 != *(_WORD*)((char*)v2 + 109))
    {
        v2 = sub_4258A0(v2);
        if (!v2)
            return 1;
    }
    return 0;
}

//----- (004A0490) --------------------------------------------------------
int* __cdecl sub_4A0490(int a1)
{
    int* result; // eax

    result = sub_425890((int*)& byte_5D4594[1305796]);
    if (!result)
        return 0;
    while (result[9] != a1)
    {
        result = sub_4258A0(result);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004A04C0) --------------------------------------------------------
int* __cdecl sub_4A04C0(int a1)
{
    int v1; // esi
    int* result; // eax

    v1 = 0;
    result = sub_425890((int*)& byte_5D4594[1305796]);
    if (!result)
        return 0;
    while (a1 != v1)
    {
        ++v1;
        result = sub_4258A0(result);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004A04F0) --------------------------------------------------------
int* __cdecl sub_4A04F0(char* a1)
{
    int* v1; // esi

    v1 = sub_425890((int*)& byte_5D4594[1305796]);
    if (!v1)
        return 0;
    while (_strcmpi((const char*)(v1[8] + 52), a1))
    {
        v1 = sub_4258A0(v1);
        if (!v1)
            return 0;
    }
    return v1;
}

//----- (004A0540) --------------------------------------------------------
void __cdecl sub_4A0540(LPVOID lpMem)
{
    sub_425920((_DWORD * *)lpMem);
    sub_46C4E0(*((_DWORD * *)lpMem + 7));
    free(lpMem);
}

//----- (004A0560) --------------------------------------------------------
int sub_4A0560()
{
    return *(_DWORD*)& byte_587000[166704];
}

//----- (004A0570) --------------------------------------------------------
int __cdecl sub_4A0570(int* a1, char* a2)
{
    char* v2; // eax
    char* v3; // eax
    char* v4; // eax
    int v6; // [esp+0h] [ebp-8h]
    int v7; // [esp+4h] [ebp-4h]
    int v8;

    v2 = strtok(a2, " \t\n\r");
    v7 = atoi(v2);
    v3 = strtok(0, " \t\n\r");
    v6 = atoi(v3);
    v4 = strtok(0, " \t\n\r");
    v8 = atoi(v4);
    *a1 = sub_4344A0(v7, v6, (int)v8);
    return 1;
}
// 4A05C7: variable 'v7' is possibly undefined
// 4A05C7: variable 'v6' is possibly undefined

//----- (004A05E0) --------------------------------------------------------
int __cdecl sub_4A05E0(int* a1, FILE* a2, char* a3)
{
    int result; // eax

    fscanf(a2, "%*s");
    sub_57BBC0(a2, (int)a3, 256);
    if (!strcmp(a3, "TRANSPARENT"))
    {
        result = 1;
        *a1 = 0x80000000;
    }
    else
    {
        sub_4A0570(a1, a3);
        result = 1;
    }
    return result;
}

//----- (004A0650) --------------------------------------------------------
int __cdecl sub_4A0650(int a1, char* a2)
{
    if (strcmp(a2, "TRANSPARENT"))
        return sub_4A0570((int*)(a1 + 20), a2);
    *(_DWORD*)(a1 + 20) = 0x80000000;
    return 1;
}

//----- (004A0690) --------------------------------------------------------
int __cdecl sub_4A0690(int a1, char* a2)
{
    if (strcmp(a2, "TRANSPARENT"))
        return sub_4A0570((int*)(a1 + 28), a2);
    *(_DWORD*)(a1 + 28) = 0x80000000;
    return 1;
}

//----- (004A06D0) --------------------------------------------------------
int __cdecl sub_4A06D0(int a1, char* a2)
{
    if (strcmp(a2, "TRANSPARENT"))
        return sub_4A0570((int*)(a1 + 44), a2);
    *(_DWORD*)(a1 + 44) = 0x80000000;
    return 1;
}

//----- (004A0710) --------------------------------------------------------
int __cdecl sub_4A0710(int a1, char* a2)
{
    if (strcmp(a2, "TRANSPARENT"))
        return sub_4A0570((int*)(a1 + 36), a2);
    *(_DWORD*)(a1 + 36) = 0x80000000;
    return 1;
}

//----- (004A0750) --------------------------------------------------------
int __cdecl sub_4A0750(int a1, char* a2)
{
    if (strcmp(a2, "TRANSPARENT"))
        return sub_4A0570((int*)(a1 + 52), a2);
    *(_DWORD*)(a1 + 52) = 0x80000000;
    return 1;
}

//----- (004A0790) --------------------------------------------------------
int __cdecl sub_4A0790(int a1, char* a2)
{
    if (strcmp(a2, "TRANSPARENT"))
        return sub_4A0570((int*)(a1 + 68), a2);
    *(_DWORD*)(a1 + 68) = 0x80000000;
    return 1;
}

//----- (004A07D0) --------------------------------------------------------
int __cdecl sub_4A07D0(int a1, char* a2)
{
    int v2; // eax

    v2 = sub_43F360(a2);
    if (!v2)
        return 0;
    *(_DWORD*)(a1 + 200) = v2;
    return 1;
}

//----- (004A0800) --------------------------------------------------------
int __cdecl sub_4A0800(wchar_t* a1, char* a2)
{
    wchar_t* v2; // eax

    v2 = loadString_sub_40F1D0(a2, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 267);
    sub_46B000(a1, v2);
    return 1;
}

//----- (004A0830) --------------------------------------------------------
int __cdecl sub_4A0830(int a1, char* a2)
{
    char* v2; // eax
    char* v3; // eax

    v2 = strtok(a2, " \t\n\r");
    *(_DWORD*)(a1 + 60) = atoi(v2);
    v3 = strtok(0, " \t\n\r");
    *(_DWORD*)(a1 + 64) = atoi(v3);
    return 1;
}

//----- (004A0870) --------------------------------------------------------
int __cdecl sub_4A0870(int a1, char* a2)
{
    char* v2; // eax

    v2 = strtok(a2, "\t\n\r");
    if (!strcmp(v2, "NULL"))
        * (_DWORD*)(a1 + 24) = 0;
    else
        *(_DWORD*)(a1 + 24) = sub_42F970(v2);
    return 1;
}

//----- (004A08C0) --------------------------------------------------------
int __cdecl sub_4A08C0(int a1, char* a2)
{
    char* v2; // eax

    v2 = strtok(a2, "\t\n\r");
    if (!strcmp(v2, "NULL"))
        * (_DWORD*)(a1 + 32) = 0;
    else
        *(_DWORD*)(a1 + 32) = sub_42F970(v2);
    return 1;
}

//----- (004A0910) --------------------------------------------------------
int __cdecl sub_4A0910(int a1, char* a2)
{
    char* v2; // eax

    v2 = strtok(a2, "\t\n\r");
    if (!strcmp(v2, "NULL"))
        * (_DWORD*)(a1 + 48) = 0;
    else
        *(_DWORD*)(a1 + 48) = sub_42F970(v2);
    return 1;
}

//----- (004A0960) --------------------------------------------------------
int __cdecl sub_4A0960(int a1, char* a2)
{
    char* v2; // eax

    v2 = strtok(a2, "\t\n\r");
    if (!strcmp(v2, "NULL"))
        * (_DWORD*)(a1 + 56) = 0;
    else
        *(_DWORD*)(a1 + 56) = sub_42F970(v2);
    return 1;
}

//----- (004A09B0) --------------------------------------------------------
int __cdecl sub_4A09B0(int a1, char* a2)
{
    char* v2; // eax

    v2 = strtok(a2, "\t\n\r");
    if (!strcmp(v2, "NULL"))
        * (_DWORD*)(a1 + 40) = 0;
    else
        *(_DWORD*)(a1 + 40) = sub_42F970(v2);
    return 1;
}

//----- (004A0A00) --------------------------------------------------------
int __cdecl sub_4A0A00(int a1, const char* a2)
{
    *(_DWORD*)(a1 + 12) = 0;
    sub_423930(a2, (_DWORD*)(a1 + 12), (const char**)& byte_587000[166712]);
    return 1;
}

//----- (004A0A30) --------------------------------------------------------
int __cdecl sub_4A0A30(int a1, const char* a2)
{
    *(_DWORD*)(a1 + 8) = 0;
    sub_423930(a2, (_DWORD*)(a1 + 8), (const char**)& byte_587000[166780]);
    return 1;
}

//----- (004A0A60) --------------------------------------------------------
int __cdecl sub_4A0A60(int a1, char* a2)
{
    char* v2; // eax

    v2 = strtok(a2, "\t\n\r");
    *(_DWORD*)(a1 + 4) = atoi(v2);
    return 1;
}

//----- (004A0A90) --------------------------------------------------------
int __cdecl sub_4A0A90(int a1, char* a2)
{
    wchar_t* v2; // eax

    if (!strcmp(a2, "Options.wnd:8BitColor"))
    {
        v2 = L"\tWindowed";
    }
    else if (!strcmp(a2, "Options.wnd:16BitColor"))
    {
        v2 = L"\tFullscreen";
    }
    else
    {
        v2 = loadString_sub_40F1D0(a2, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 424);
    }
    nox_wcsncpy((wchar_t*)(a1 + 72), v2, 0x3Fu);
    *(_WORD*)(a1 + 196) = 0;
    return 1;
}

//----- (004A0AD0) --------------------------------------------------------
nox_window* __cdecl nox_new_window_from_file(const char* name, int (*a2)(int, int, int, int))
{
    char path[256];
    strcpy(path, "window\\");
    memset(&path[8], 0, 0xF8u);
    sub_4A0CF0();
    sub_4A0D10();
    strcat(path, name);

    FILE* f = fopen(path, "r");
    if (!f)
        return 0;

    int v3;
    while (fscanf(f, "%s", &byte_5D4594[1306948]) != -1
           && strcmp((const char*)& byte_5D4594[1306948], "END"))
    {
        if (!strcmp((const char*)& byte_5D4594[1306948], "ENABLEDCOLOR"))
        {
            v3 = sub_4A05E0((int*)& byte_5D4594[1307264], f, (char*)& byte_5D4594[1306948]);
            if (!v3)
                break;
        }
        else
        {
            if (!strcmp((const char*)& byte_5D4594[1306948], "DISABLEDCOLOR"))
            {
                v3 = sub_4A05E0((int*)& byte_5D4594[1307268], f, (char*)& byte_5D4594[1306948]);
                if (!v3)
                    break;
            }
            if (!strcmp((const char*)& byte_5D4594[1306948], "HILITECOLOR"))
            {
                v3 = sub_4A05E0((int*)& byte_5D4594[1307276], f, (char*)& byte_5D4594[1306948]);
                if (!v3)
                    break;
            }
            if (!strcmp((const char*)& byte_5D4594[1306948], "SELECTEDCOLOR"))
            {
                v3 = sub_4A05E0((int*)& byte_5D4594[1307280], f, (char*)& byte_5D4594[1306948]);
                if (!v3)
                    break;
            }
            if (!strcmp((const char*)& byte_5D4594[1306948], "TEXTCOLOR"))
            {
                v3 = sub_4A05E0((int*)& byte_5D4594[1307284], f, (char*)& byte_5D4594[1306948]);
                if (!v3)
                    break;
            }
            if (!strcmp((const char*)& byte_5D4594[1306948], "BACKGROUNDCOLOR"))
            {
                v3 = sub_4A05E0((int*)& byte_5D4594[1307272], f, (char*)& byte_5D4594[1306948]);
                if (!v3)
                    break;
            }
            if (!strcmp((const char*)& byte_5D4594[1306948], "FONT"))
            {
                if (!sub_4A0D40((int*)& byte_5D4594[1307288], f, (char*)& byte_5D4594[1306948]))
                    break;
            }
            else if (!strcmp((const char*)& byte_5D4594[1306948], "WINDOW"))
            {
                nox_window* win = sub_4A0D80_parse_window(f, (char*)& byte_5D4594[1306948], a2);
                fclose(f);
                return win;
            }
        }
    }
    fclose(f);
    return 0;
}

//----- (004A0CF0) --------------------------------------------------------
int sub_4A0CF0()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[1307208], 0, 0x28u);
    *(_DWORD*)& byte_5D4594[1307204] = &byte_5D4594[1307208];
    return result;
}

//----- (004A0D10) --------------------------------------------------------
int sub_4A0D10()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[1307288] = 0;
    *(_DWORD*)& byte_5D4594[1307264] = *(_DWORD*)& byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[1307268] = *(_DWORD*)& byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[1307272] = *(_DWORD*)& byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[1307276] = *(_DWORD*)& byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[1307280] = *(_DWORD*)& byte_5D4594[2650656];
    *(_DWORD*)& byte_5D4594[1307284] = *(_DWORD*)& byte_5D4594[2650656];
    return result;
}

//----- (004A0D40) --------------------------------------------------------
BOOL __cdecl sub_4A0D40(int* a1, FILE* a2, char* a3)
{
    int v3; // eax

    fscanf(a2, "%*s");
    sub_57BBC0(a2, (int)a3, 256);
    v3 = sub_43F360(a3);
    *a1 = v3;
    return v3 != 0;
}

//----- (004A0D80) --------------------------------------------------------
_DWORD* __cdecl sub_4A0D80_parse_window(FILE* a1, char* a2, int (*a3)(int, int, int, int))
{
    int v3; // eax
    char* v4; // eax
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    char* v8; // eax
    char* v9; // eax
    unsigned __int8* v10; // edi
    int v11; // eax
    float* v15; // [esp+14h] [ebp-1A4h]
    int v16; // [esp+18h] [ebp-1A0h]
    wchar_t* v17; // [esp+1Ch] [ebp-19Ch]
    int v18; // [esp+20h] [ebp-198h]
    int v19; // [esp+24h] [ebp-194h]
    int v20; // [esp+28h] [ebp-190h]
    char v21[64]; // [esp+2Ch] [ebp-18Ch]
    char v22[332]; // [esp+6Ch] [ebp-14Ch], same as nox_window->field_9 ?

    *(_DWORD*)v22 = 0;
    memset(&v22[4], 0, 0x148u);
    *(_DWORD*)& v22[28] = *(_DWORD*)& byte_5D4594[1307264];
    *(_DWORD*)& v22[36] = *(_DWORD*)& byte_5D4594[1307276];
    v3 = *(_DWORD*)& byte_5D4594[1307288];
    *(_DWORD*)& v22[44] = *(_DWORD*)& byte_5D4594[1307268];
    *(_DWORD*)& v22[20] = *(_DWORD*)& byte_5D4594[1307272];
    v15 = 0;
    *(_DWORD*)& v22[52] = *(_DWORD*)& byte_5D4594[1307280];
    *(_DWORD*)& v22[68] = *(_DWORD*)& byte_5D4594[1307284];
    if (!*(_DWORD*)& byte_5D4594[1307288])
    {
        if (*(_DWORD*)& byte_5D4594[815132])
            v3 = sub_43F360((char*)& byte_587000[167936]);
        else
            v3 = sub_43F360((char*)& byte_587000[167944]);
    }
    *(_DWORD*)& v22[200] = v3;
    sub_57BBC0(a1, (int)a2, 256);
    //OutputDebugStringA(a2);
    //OutputDebugStringA("\n");
    v4 = strtok(a2, " \t\n\r");
    v18 = atoi(v4);
    v5 = strtok(0, " \t\n\r");
    v17 = (wchar_t*)atoi(v5);
    v6 = strtok(0, " \t\n\r");
    v16 = atoi(v6);
    v7 = strtok(0, " \t\n\r");
    v20 = atoi(v7);
    v8 = strtok(0, " \t\n\r");
    v19 = atoi(v8);
    v9 = strtok(0, " \t\n\r");
    strncpy(v21, v9, 0x3Fu);

    nox_window* win = 0;
    while (1)
    {
        while (1)
        {
            do
            {
                fscanf(a1, "%s", a2);
                //OutputDebugStringA(a2);
                //OutputDebugStringA("\n");
                v10 = &byte_587000[166840];
                if (*(_DWORD*)& byte_587000[166844])
                {
                    while (strcmp(a2, *(const char**)v10))
                    {
                        v11 = *((_DWORD*)v10 + 3);
                        v10 += 8;
                        if (!v11)
                            goto LABEL_11;
                    }
                    fscanf(a1, "%*s");
                    sub_57BBC0(a1, (int)a2, 256);
                    //OutputDebugStringA(a2);
                    //OutputDebugStringA("\n");
                    if (!(*((int(__cdecl * *)(char*, char*))v10 + 1))(v22, a2))
                        return 0;
                }
                LABEL_11:
                ;
            } while (*((_DWORD*)v10 + 1));
            if (strcmp(a2, "DATA"))
                break;
            fscanf(a1, "%*s");
            sub_57BBC0(a1, (int)a2, 256);
            //OutputDebugStringA(a2);
            //OutputDebugStringA("\n");
            if (!sub_4A10A0(&v15, v21, a2))
                return 0;
        }
        if (!strcmp(a2, "END"))
            break;
        if (!strcmp(a2, "CHILD"))
        {
            win = sub_4A1440_parse_window(v21, v18, *(int*)& v22[12], v17, v16, v20, v19, v22, v15, a3);
            if (!win || !sub_4A1780(win, a1, a2))
                return 0;
        }
        else
        {
            sub_57BBC0(a1, (int)a2, 256);
            //OutputDebugStringA(a2);
            //OutputDebugStringA("\n");
        }
    }
    if (!win)
        win = sub_4A1440_parse_window(v21, v18, *(int*)& v22[12], v17, v16, v20, v19, v22, v15, a3);
    return win;
}

//----- (004A10A0) --------------------------------------------------------
int __cdecl sub_4A10A0(_DWORD* a1, const char* a2, char* a3)
{
    char* v3; // eax
    char* v4; // eax
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    char* v8; // eax
    char* v9; // eax
    int result; // eax
    char* v11; // eax
    char* v12; // eax
    char* v13; // eax
    char* v14; // eax
    const char* v15; // esi
    char* v16; // eax
    char* v17; // eax
    char* v18; // eax
    char* v19; // eax
    char* v20; // eax
    char* v21; // eax

    if (!strcmp(a2, "VERTSLIDER") || !strcmp(a2, "HORZSLIDER"))
    {
        *(_DWORD*)& byte_5D4594[1305820] = 0;
        *(_DWORD*)& byte_5D4594[1305824] = 0;
        *(_DWORD*)& byte_5D4594[1305828] = 0;
        *(_DWORD*)& byte_5D4594[1305832] = 0;
        v20 = strtok(a3, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1305820] = atoi(v20);
        v21 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1305824] = atoi(v21);
        result = 1;
        *a1 = &byte_5D4594[1305820];
    }
    else if (!strcmp(a2, "SCROLLLISTBOX"))
    {
        memset(&byte_5D4594[1306892], 0, 0x38u);
        v3 = strtok(a3, " \t\n\r");
        *(_WORD*)& byte_5D4594[1306892] = atoi(v3);
        v4 = strtok(0, " \t\n\r");
        *(_WORD*)& byte_5D4594[1306894] = atoi(v4);
        v5 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306896] = atoi(v5);
        v6 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306900] = atoi(v6);
        v7 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306904] = atoi(v7);
        v8 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306908] = atoi(v8);
        v9 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306912] = atoi(v9);
        result = 1;
        *a1 = &byte_5D4594[1306892];
    }
    else if (!strcmp(a2, "ENTRYFIELD"))
    {
        memset(&byte_5D4594[1305836], 0, 0x420u);
        v11 = strtok(a3, " \t\n\r");
        *(_WORD*)& byte_5D4594[1306876] = atoi(v11);
        v12 = strtok(0, " \t\n\r");
        if (v12)
            * (_WORD*)& byte_5D4594[1306878] = atoi(v12);
        else
            *(_WORD*)& byte_5D4594[1306878] = -1;
        v13 = strtok(0, " \t\n\r");
        if (v13)
        {
            *(_DWORD*)& byte_5D4594[1306860] = atoi(v13);
            *(_DWORD*)& byte_5D4594[1306860] = *(_DWORD*)& byte_5D4594[1306860] != 0;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1306860] = 0;
        }
        v14 = strtok(0, " \t\n\r");
        v15 = v14;
        if (v14)
        {
            *(_DWORD*)& byte_5D4594[1306864] = atoi(v14) == 1;
            *(_DWORD*)& byte_5D4594[1306868] = atoi(v15) == 2;
            *(_DWORD*)& byte_5D4594[1306872] = atoi(v15) == 3;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1306864] = 0;
            *(_DWORD*)& byte_5D4594[1306868] = 0;
            *(_DWORD*)& byte_5D4594[1306872] = 0;
        }
        *a1 = &byte_5D4594[1305836];
        result = 1;
    }
    else if (!strcmp(a2, "STATICTEXT"))
    {
        v16 = strtok(a3, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1307256] = atoi(v16);
        *(_DWORD*)& byte_5D4594[1307256] = *(_DWORD*)& byte_5D4594[1307256] != 0;
        v17 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1307260] = atoi(v17);
        *(_DWORD*)& byte_5D4594[1307260] = *(_DWORD*)& byte_5D4594[1307260] != 0;
        v18 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1307252] = loadString_sub_40F1D0(v18, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 542);
        result = 1;
        *a1 = &byte_5D4594[1307252];
    }
    else if (!strcmp(a2, "RADIOBUTTON"))
    {
        v19 = strtok(a3, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1305812] = atoi(v19);
        *(_DWORD*)& byte_5D4594[1307256] = *(_DWORD*)& byte_5D4594[1307256] != 0;
        result = 1;
        *a1 = &byte_5D4594[1305812];
    }
    else
    {
        result = 1;
        *a1 = 0;
    }
    return result;
}

//----- (004A1440) --------------------------------------------------------
nox_window* __cdecl sub_4A1440_parse_window(const char* a1, int a2, int a3, wchar_t* a4, int a5, int a6, int a7, _DWORD* a8, float* a9, int (*a10)(int, int, int, int))
{
    int v10; // ebx
    int v12; // edx

    v10 = sub_4A14F0();

    nox_window* win;
    if (!strcmp(a1, "USER"))
    {
        win = nox_window_new(v10, a3, (int)a4, a5, a6, a7, a10);
        v12 = a8[2];
        BYTE1(v12) |= 0x20u;
        a8[2] = v12;
        sub_46AF80_copy_window_part(win, a8);
    }
    else
    {
        win = sub_4A1510_parse_window(a1, v10, a3, a4, a5, a6, a7, a8, a9);
    }
    sub_46B080(win, a2);
    if (v10)
        (*(int(__cdecl * *)(int, int, int, _DWORD))(v10 + 376))(v10, 22, a2, 0);
    return win;
}

//----- (004A14F0) --------------------------------------------------------
int sub_4A14F0()
{
    int result; // eax

    if (*(unsigned __int8**)& byte_5D4594[1307204] == &byte_5D4594[1307208])
        result = 0;
    else
        result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307204] - 4);
    return result;
}

//----- (004A1510) --------------------------------------------------------
nox_window* __cdecl sub_4A1510_parse_window(const char* a1, int a2, int a3, wchar_t* a4, int a5, int a6, int a7, _DWORD* a8, float* a9)
{
    _DWORD* result; // eax
    int v10; // ebx
    int v11; // ebx
    int v12; // ebx
    int v13; // ebx

    a8[4] = a2;
    if (!strcmp(a1, "PUSHBUTTON"))
    {
        a8[2] |= 1u;
        return (_DWORD*)sub_4A91A0(a2, a3, (int)a4, a5, a6, a7, a8);
    }
    if (!strcmp(a1, "RADIOBUTTON"))
    {
        a8[2] |= 2u;
        return (_DWORD*)sub_4A9330(a2, a3, (int)a4, a5, a6, a7, (int)a8, a9);
    }
    if (!strcmp(a1, "CHECKBOX"))
    {
        a8[2] |= 4u;
        return (_DWORD*)sub_4A91A0(a2, a3, (int)a4, a5, a6, a7, a8);
    }
    if (!strcmp(a1, "VERTSLIDER"))
    {
        v10 = a8[2] | 8;
        LABEL_9:
        a8[2] = v10;
        return sub_4B4EE0(a2, a3, (int)a4, a5, a6, a7, a8, a9);
    }
    if (!strcmp(a1, "HORZSLIDER"))
    {
        v10 = a8[2] | 0x10;
        goto LABEL_9;
    }
    if (!strcmp(a1, "SCROLLLISTBOX"))
    {
        a8[2] |= 0x20u;
        result = sub_4A4310(a2, a3, (int)a4, a5, a6, a7, (int)a8, (__int16*)a9);
    }
    else if (!strcmp(a1, "ENTRYFIELD"))
    {
        v11 = a8[2];
        LOBYTE(v11) = v11 | 0x80;
        a8[2] = v11;
        result = sub_488500(a2, a3, (int)a4, a5, a6, a7, (int)a8, (wchar_t*)a9);
    }
    else if (!strcmp(a1, "STATICTEXT"))
    {
        v12 = a8[2];
        BYTE1(v12) |= 8u;
        a8[2] = v12;
        result = sub_489300(a2, a3, (int)a4, a5, a6, a7, a8, a9);
    }
    else if (!strcmp(a1, "PROGRESSBAR"))
    {
        v13 = a8[2];
        BYTE1(v13) |= 0x10u;
        a8[2] = v13;
        result = sub_4CAF10(a2, a3, (int)a4, a5, a6, a7, a8);
    }
    else
    {
        result = (_DWORD*)a7;
    }
    return result;
}

//----- (004A1780) --------------------------------------------------------
BOOL __cdecl sub_4A1780(int a1, FILE* a2, char* a3)
{
    _DWORD* v3; // eax

    sub_4A18C0(a1);
    while (fscanf(a2, "%s", a3) != -1 && strcmp(a3, "END"))
    {
        if (!strcmp(a3, "ENABLEDCOLOR"))
        {
            v3 = (_DWORD*)sub_4A05E0((int*)& byte_5D4594[1307264], a2, a3);
            LABEL_14:
            if (!v3)
                return 0;
        }
        else
        {
            if (!strcmp(a3, "DISABLEDCOLOR"))
            {
                v3 = (_DWORD*)sub_4A05E0((int*)& byte_5D4594[1307268], a2, a3);
                goto LABEL_14;
            }
            if (!strcmp(a3, "HILITECOLOR"))
            {
                v3 = (_DWORD*)sub_4A05E0((int*)& byte_5D4594[1307276], a2, a3);
                goto LABEL_14;
            }
            if (!strcmp(a3, "SELECTEDCOLOR"))
            {
                v3 = (_DWORD*)sub_4A05E0((int*)& byte_5D4594[1307280], a2, a3);
                goto LABEL_14;
            }
            if (!strcmp(a3, "TEXTCOLOR"))
            {
                v3 = (_DWORD*)sub_4A05E0((int*)& byte_5D4594[1307284], a2, a3);
                goto LABEL_14;
            }
            if (!strcmp(a3, "WINDOW"))
            {
                v3 = sub_4A0D80_parse_window(a2, a3, 0);
                goto LABEL_14;
            }
        }
    }
    return sub_4A18A0() == a1;
}

//----- (004A18A0) --------------------------------------------------------
int sub_4A18A0()
{
    if (*(unsigned __int8**)& byte_5D4594[1307204] == &byte_5D4594[1307208])
        return 0;
    *(_DWORD*)& byte_5D4594[1307204] -= 4;
    return **(_DWORD * *)& byte_5D4594[1307204];
}

//----- (004A18C0) --------------------------------------------------------
int __cdecl sub_4A18C0(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1307204];
    if (*(unsigned __int8**)& byte_5D4594[1307204] != &byte_5D4594[1307244])
    {
        **(_DWORD * *)& byte_5D4594[1307204] = a1;
        result = *(_DWORD*)& byte_5D4594[1307204] + 4;
        *(_DWORD*)& byte_5D4594[1307204] += 4;
    }
    return result;
}

//----- (004A18E0) --------------------------------------------------------
int __cdecl sub_4A18E0(int a1, int a2, int a3, int a4)
{
    wchar_t* v5; // eax
    wchar_t* v6; // [esp-10h] [ebp-10h]

    if (sub_450560())
        return 1;
    if (a2 == 21 && a3 == 1)
    {
        if (a4 != 2)
            return 1;
        if (sub_43BE30())
        {
            LABEL_15:
            if (sub_4D6F30())
                sub_4D6F90(2);
            return 1;
        }
        if (!sub_44A4A0())
        {
            if (sub_43BE10() == 10000)
            {
                sub_4373A0();
            }
            else if (sub_43BE10() == 100)
            {
                v6 = loadString_sub_40F1D0((char*)& byte_587000[168540], 0, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 65);
                v5 = loadString_sub_40F1D0((char*)& byte_587000[168608], 0, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 64);
                sub_449A10(*(int*)& byte_5D4594[1307292], (int)v5, (int)v6, 56, sub_4A19D0, 0);
            }
            else
            {
                if (sub_43BE10() == 700)
                    sub_4A7A60(1);
                sub_43C1E0();
            }
            goto LABEL_15;
        }
    }
    return 0;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);
