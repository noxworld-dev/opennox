#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "proto.h"

extern int nox_win_width;
extern int nox_win_height;

//----- (004CD690) --------------------------------------------------------
int __cdecl sub_4CD690(_DWORD* a1, int a2)
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
    int* v13; // edi
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

    if (!*(_DWORD*)& byte_5D4594[1522976])
        * (_DWORD*)& byte_5D4594[1522976] = sub_44CFC0((CHAR*)& byte_587000[189456]);
    if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 20) < 50)
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
            v2 = v10[3] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 61);
            v3 = v12[4] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 62);
            v4 = v8[4];
            v22 = v8[3];
        }
        else
        {
            if (a2 == -432)
                return 1;
            v2 = *(unsigned __int16*)(a2 + 441) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 31);
            v3 = *(unsigned __int16*)(a2 + 443) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 32);
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
        v19 = sub_45A360(*(int*)& byte_5D4594[1522976], v2, v3);
        if (v19)
        {
            v20 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 93);
            *(_WORD*)(v19 + 432) = v22;
            *(_WORD*)(v19 + 434) = v23;
            *(_BYTE*)(v19 + 443) = v20;
            *(_BYTE*)(v19 + 444) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Drawable\\Update\\drainup.c", 100);
        }
    }
    return 1;
}
// 4CD756: variable 'v5' is possibly undefined
// 4CD767: variable 'v7' is possibly undefined
// 4CD78B: variable 'v9' is possibly undefined
// 4CD79C: variable 'v11' is possibly undefined

//----- (004CD8D0) --------------------------------------------------------
int __cdecl sub_4CD8D0(int a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int v4; // eax
    int v5; // esi

    if (!*(_DWORD*)& byte_5D4594[1522980])
        * (_DWORD*)& byte_5D4594[1522980] = sub_44CFC0((CHAR*)& byte_587000[189808]);
    v2 = *(_DWORD*)(a2 + 12) + sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 32);
    v3 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 33);
    v4 = sub_45A360(*(int*)& byte_5D4594[1522980], v2, *(_DWORD*)(a2 + 16) + v3);
    v5 = v4;
    if (v4)
    {
        *(_DWORD*)(v4 + 432) = *(_DWORD*)(v4 + 12) << 12;
        *(_DWORD*)(v4 + 436) = *(_DWORD*)(v4 + 16) << 12;
        *(_BYTE*)(v4 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 43);
        *(_DWORD*)(v5 + 440) = sub_415FF0(1, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 46);
        *(_DWORD*)(v5 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                               + sub_415FF0(10, 32, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 49);
        *(_DWORD*)(v5 + 444) = *(_DWORD*)& byte_5D4594[2598000];
        *(_WORD*)(v5 + 104) = 0;
        *(_BYTE*)(v5 + 296) = sub_415FF0(3, 8, "C:\\NoxPost\\src\\client\\Drawable\\Update\\telwake.c", 55);
        sub_45A110((_DWORD*)v5);
    }
    return 1;
}

//----- (004CD9E0) --------------------------------------------------------
int __cdecl sub_4CD9E0(int a1, _DWORD* a2)
{
    _DWORD* v2; // ebp
    int v3; // esi
    int v4; // edi
    int v5; // ebx
    int v6; // edi
    int v8; // ebx
    int v9; // eax
    int v10; // esi
    int v11; // edx
    _DWORD* v12; // esi
    int v14; // [esp+8h] [ebp-8h]
    int v15; // [esp+Ch] [ebp-4h]
    int v16; // [esp+18h] [ebp+8h]

    v2 = a2;
    if (!*(_DWORD*)& byte_5D4594[1522984])
    {
        *(_DWORD*)& byte_5D4594[1522984] = sub_44CFC0((CHAR*)& byte_587000[190112]);
        *(_DWORD*)& byte_5D4594[1522988] = sub_44CFC0((CHAR*)& byte_587000[190120]);
        *(_DWORD*)& byte_5D4594[1522992] = sub_44CFC0((CHAR*)& byte_587000[190128]);
    }
    v3 = a2[3] - a2[8];
    v15 = a2[4] - a2[9];
    v14 = a2[3] - a2[8];
    v16 = 0;
    if (*(_DWORD*)& byte_587000[190108] > 0)
    {
        while (1)
        {
            v4 = v2[8];
            v5 = v2[9];
            v6 = v3 * sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 40) / 100 + v4;
            v8 = (v15 * sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 41)) / 100 + v5;
            v9 = sub_45A360(*(int*)& byte_5D4594[1522984], v6, v8);
            v10 = v9;
            if (v9)
            {
                *(_DWORD*)(v9 + 432) = v6 << 12;
                *(_DWORD*)(v9 + 436) = v8 << 12;
                *(_BYTE*)(v9 + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 52);
                *(_DWORD*)(v10 + 440) = 0;
                *(_DWORD*)(v10 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                        + sub_415FF0(3, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 59);
                *(_DWORD*)(v10 + 444) = *(_DWORD*)& byte_5D4594[2598000];
                *(_WORD*)(v10 + 104) = 20;
                *(_BYTE*)(v10 + 296) = sub_415FF0(0, 6, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mmislup.c", 65);
                sub_45A110((_DWORD*)v10);
            }
            if (++v16 >= *(int*)& byte_587000[190108])
                break;
            v3 = v14;
        }
    }
    v11 = v2[108];
    if ((v2[3] - v11) * (v2[3] - v11) + (v2[4] - v2[109]) * (v2[4] - v2[109]) > 200)
    {
        v12 = (_DWORD*)sub_45A360(*(int*)& byte_5D4594[1522992], v11, v2[109]);
        v12[108] = v2[3];
        v12[109] = v2[4];
        sub_45A110(v12);
        v2[108] = v2[3];
        v2[109] = v2[4];
        sub_49B950(v12, *(_DWORD*)& byte_5D4594[2649704] / 3u);
    }
    return 1;
}

//----- (004CDBF0) --------------------------------------------------------
int __cdecl sub_4CDBF0(int a1, _DWORD* a2)
{
    _DWORD* v2; // ebx
    int v3; // edi
    int v4; // ebp
    int v5; // esi
    bool v6; // zf
    int v8; // [esp+10h] [ebp-10h]
    int v9; // [esp+14h] [ebp-Ch]
    int v10; // [esp+18h] [ebp-8h]
    int v11; // [esp+1Ch] [ebp-4h]
    int v12; // [esp+28h] [ebp+8h]

    v2 = a2;
    v10 = a2[3] - a2[8];
    v11 = a2[4] - a2[9];
    if (!*(_DWORD*)& byte_5D4594[1522996])
        * (_DWORD*)& byte_5D4594[1522996] = sub_44CFC0((CHAR*)& byte_587000[190392]);
    v8 = 0;
    v12 = 0;
    v9 = 5;
    do
    {
        v3 = v2[8] + v12 / 5 + sub_415FF0(-3, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 28);
        v4 = v2[9]
             + sub_415FF0(-3, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 29)
             + v8 / 5;
        v5 = sub_45A360(*(int*)& byte_5D4594[1522996], v3, v4);
        if (v5)
        {
            *(_DWORD*)(v5 + 300) = nox_thing_pixie_dust_draw;
            sub_484BE0((_DWORD*)(v5 + 136), 255, 200, 75);
            *(_DWORD*)(v5 + 432) = v3 << 12;
            *(_DWORD*)(v5 + 436) = v4 << 12;
            *(_BYTE*)(v5 + 299) = 0;
            *(_DWORD*)(v5 + 440) = 0;
            *(_DWORD*)(v5 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                   + sub_415FF0(2, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\sparklup.c", 51);
            *(_DWORD*)(v5 + 444) = *(_DWORD*)& byte_5D4594[2598000];
            *(_WORD*)(v5 + 104) = *((_WORD*)v2 + 52);
            *(_WORD*)(v5 + 106) = *((_WORD*)v2 + 53);
            *(_BYTE*)(v5 + 296) = 0;
            sub_45A110((_DWORD*)v5);
        }
        v12 += v10;
        v6 = v9 == 1;
        v8 += v11;
        --v9;
    } while (!v6);
    return 1;
}

//----- (004CDD80) --------------------------------------------------------
void __cdecl sub_4CDD80(int a1, _DWORD* a2)
{
    _DWORD* v2; // edi
    int v3; // eax
    int v4; // eax
    _DWORD* v5; // esi
    int v6; // ebx
    int v7; // ebp
    int v8; // esi
    int v9; // eax
    int v10; // eax
    int v11; // esi
    int v13; // [esp+10h] [ebp-8h]
    int v14; // [esp+14h] [ebp-4h]
    int v15; // [esp+20h] [ebp+8h]

    v2 = a2;
    v3 = a2[3] - a2[108];
    if (v3 * v3 + (a2[4] - a2[109]) * (a2[4] - a2[109]) > 200)
    {
        v4 = *(_DWORD*)& byte_5D4594[1523000];
        if (!*(_DWORD*)& byte_5D4594[1523000])
        {
            v4 = sub_44CFC0((CHAR*)& byte_587000[190560]);
            *(_DWORD*)& byte_5D4594[1523000] = v4;
        }
        v5 = (_DWORD*)sub_45A360(v4, a2[108], a2[109]);
        v5[108] = a2[3];
        v5[109] = a2[4];
        sub_45A110(v5);
        a2[108] = a2[3];
        a2[109] = a2[4];
        sub_49B950(v5, *(int*)& byte_5D4594[2649704]);
    }
    v13 = a2[3] - a2[8];
    v14 = a2[4] - a2[9];
    if (!*(_DWORD*)& byte_5D4594[1523004])
        * (_DWORD*)& byte_5D4594[1523004] = sub_44CFC0((CHAR*)& byte_587000[190576]);
    v6 = 0;
    v7 = 0;
    v15 = 4;
    do
    {
        v8 = v2[8] + v7 / 4 + sub_415FF0(-8, 8, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mtailup.c", 66);
        v9 = sub_415FF0(-8, 8, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mtailup.c", 68);
        v10 = sub_45A360(*(int*)& byte_5D4594[1523004], v8, v2[9] + v6 / 4 + v9);
        v11 = v10;
        if (v10)
        {
            *(_DWORD*)(v10 + 300) = nox_thing_magic_sparkle_draw;
            sub_484BE0((_DWORD*)(v10 + 136), 128, 128, 255);
            *(_DWORD*)(v11 + 432) = v2[3] << 12;
            *(_DWORD*)(v11 + 436) = v2[4] << 12;
            *(_BYTE*)(v11 + 299) = 0;
            *(_DWORD*)(v11 + 440) = 0;
            *(_DWORD*)(v11 + 448) = *(_DWORD*)& byte_5D4594[2598000]
                                    + sub_415FF0(10, 20, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\mtailup.c", 90);
            *(_DWORD*)(v11 + 444) = *(_DWORD*)& byte_5D4594[2598000];
            *(_WORD*)(v11 + 104) = *((_WORD*)v2 + 52);
            *(_WORD*)(v11 + 106) = *((_WORD*)v2 + 53);
            *(_BYTE*)(v11 + 296) = 0;
            sub_45A110((_DWORD*)v11);
        }
        v7 += v13;
        v6 += v14;
        v15--;
    } while (v15);
}

//----- (004CDF80) --------------------------------------------------------
int __cdecl sub_4CDF80(int a1, int a2)
{
    sub_4CDFA0(a2, (_DWORD*)3);
    return 1;
}

//----- (004CDFA0) --------------------------------------------------------
_DWORD* __cdecl sub_4CDFA0(int a1, _DWORD* a2)
{
    _DWORD* result; // eax
    _DWORD* v3; // ebp
    _DWORD* v4; // esi

    if (!*(_DWORD*)& byte_5D4594[1523008])
        * (_DWORD*)& byte_5D4594[1523008] = sub_44CFC0((CHAR*)& byte_587000[190732]);
    result = a2;
    if ((int)a2 > 0)
    {
        v3 = a2;
        do
        {
            result = (_DWORD*)sub_45A360(*(int*)& byte_5D4594[1523008], *(_DWORD*)(a1 + 12), *(_DWORD*)(a1 + 16));
            v4 = result;
            if (result)
            {
                result[108] = *(_DWORD*)(a1 + 12) << 12;
                result[109] = *(_DWORD*)(a1 + 16) << 12;
                *((_BYTE*)result + 299) = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 37);
                v4[110] = sub_415FF0(1000, 3000, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 40);
                v4[112] = *(_DWORD*)& byte_5D4594[2598000] + sub_415FF0(10, 40, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 43);
                v4[111] = *(_DWORD*)& byte_5D4594[2598000];
                *((_WORD*)v4 + 52) = 22;
                *((_BYTE*)v4 + 296) = sub_415FF0(0, 4, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 49);
                result = sub_45A110(v4);
            }
            v3 = (_DWORD*)((char*)v3 - 1);
        } while (v3);
    }
    return result;
}

//----- (004CE0A0) --------------------------------------------------------
int __cdecl sub_4CE0A0(int a1, int a2)
{
    sub_4CDFA0(a2, (_DWORD*)1);
    return 1;
}

//----- (004CE0C0) --------------------------------------------------------
int __cdecl sub_4CE0C0(int a1, int a2)
{
    int v2; // ebx
    __int16 v3; // cx
    int v4; // esi
    __int16 v5; // ax
    __int16 v6; // cx
    int v7; // eax
    int v9; // [esp-18h] [ebp-20h]
    char v10; // [esp-14h] [ebp-1Ch]
    __int16 v11[4]; // [esp+0h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1523012])
        * (_DWORD*)& byte_5D4594[1523012] = sub_44CFC0((CHAR*)& byte_587000[190940]);
    v2 = 10;
    v3 = *(_WORD*)(a2 + 16);
    v11[0] = *(_WORD*)(a2 + 12);
    v11[1] = v3;
    do
    {
        v4 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 102);
        v5 = sub_415FF0(2, 8, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 105);
        v6 = *(_WORD*)(a2 + 16) + v5 * *(short*)& byte_587000[8 * v4 + 192092];
        v11[2] = *(_WORD*)(a2 + 12) + v5 * *(short*)& byte_587000[8 * v4 + 192088];
        v11[3] = v6;
        if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 112) < 50)
        {
            v10 = sub_415FF0(6, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 116);
            v9 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 115);
            v7 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\dball.c", 114);
            sub_499490(*(int*)& byte_5D4594[1523012], v11, v7, v9, v10, 0);
        }
        --v2;
    } while (v2);
    return 1;
}

//----- (004CE1D0) --------------------------------------------------------
int __cdecl sub_4CE1D0(int a1, int a2)
{
    if (byte_5D4594[2598000] & 1)
        sub_4CE200(a1, a2, 1, 75);
    return 1;
}

//----- (004CE200) --------------------------------------------------------
int __cdecl sub_4CE200(int a1, int a2, int a3, int a4)
{
    int result; // eax
    int v5; // edi
    int v6; // eax
    int v7; // esi
    int v8; // edi
    bool v9; // cc
    int v10; // eax
    int v11; // eax
    int v12; // esi
    int v13; // eax

    if (!*(_DWORD*)& byte_5D4594[1523016])
    {
        *(_DWORD*)& byte_5D4594[1523016] = sub_44CFC0((CHAR*)& byte_587000[191240]);
        *(_DWORD*)& byte_5D4594[1523020] = sub_44CFC0((CHAR*)& byte_587000[191252]);
    }
    result = a3;
    if (a3 > 0)
    {
        do
        {
            v5 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 40);
            v6 = sub_415FF0(0, a4, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 41);
            v7 = *(_DWORD*)(a2 + 12) + v6 * *(int*)& byte_587000[8 * v5 + 192088] / 16;
            v8 = *(_DWORD*)(a2 + 16) + v6 * *(int*)& byte_587000[8 * v5 + 192092] / 16;
            v9 = sub_415FF0(0, 10, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 46) < 3;
            v10 = *(_DWORD*)& byte_5D4594[1523020];
            if (!v9)
                v10 = *(_DWORD*)& byte_5D4594[1523016];
            v11 = sub_45A360(v10, v7, v8);
            v12 = v11;
            if (v11)
            {
                *(_WORD*)(v11 + 104) = 0;
                sub_45A110((_DWORD*)v11);
                *(_BYTE*)(v12 + 432) = sub_415FF0(1, 3, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 57);
                *(_DWORD*)(v12 + 460) = sub_4CE340;
                v13 = sub_415FF0(10, 32, "C:\\NoxPost\\src\\Client\\Drawable\\Update\\cloud.c", 61);
                sub_49B950((_DWORD*)v12, v13);
                sub_49BC80((_DWORD*)v12);
                sub_49BAB0((_DWORD*)v12);
            }
            result = --a3;
        } while (a3);
    }
    return result;
}

//----- (004CE340) --------------------------------------------------------
int __cdecl sub_4CE340(int a1, int a2)
{
    *(_WORD*)(a2 + 104) += *(unsigned __int8*)(a2 + 432);
    return 1;
}

//----- (004CE360) --------------------------------------------------------
int __cdecl sub_4CE360(int a1, int a2)
{
    if (byte_5D4594[2598000] & 1)
        sub_4CE200(a1, a2, 1, 35);
    return 1;
}

//----- (004CE390) --------------------------------------------------------
int __cdecl sub_4CE390(_DWORD* a1, int a2)
{
    int result; // eax
    int v3; // edx
    int v4; // ecx
    int v5; // ecx
    int v6; // edx

    if (*(_BYTE*)(a2 + 432) || *(_BYTE*)(a2 + 433) || *(_BYTE*)(a2 + 434))
    {
        v3 = *(_DWORD*)(a2 + 12);
        v4 = a1[4];
        if (v3 >= v4 - 100 && v3 <= a1[8] + v4 + 100)
        {
            v5 = a1[5];
            v6 = *(_DWORD*)(a2 + 16);
            if (v6 >= v5 - 100 && v6 <= a1[9] + v5 + 100 && !sub_40A5C0(0x200000))
            {
                sub_4CE440(a2);
                sub_4CE610(a2);
                sub_4CE760(a2);
                sub_4CE960(a2);
                sub_4CE8C0(a2);
            }
        }
        result = 1;
    }
    else
    {
        sub_49BCD0((_DWORD*)a2);
        result = 1;
    }
    return result;
}

//----- (004CE440) --------------------------------------------------------
void __cdecl sub_4CE440(int a1)
{
    int v1; // esi
    char v2; // bl
    double v3; // st7
    __int64 v4; // rax
    double v5; // st7
    double v6; // st7
    char v7; // bl
    char v8; // bl
    int v9; // eax
    double v10; // st7
    int v11; // ecx
    char v12; // [esp+Fh] [ebp-15h]
    float v13; // [esp+10h] [ebp-14h]
    int v14; // [esp+18h] [ebp-Ch]
    char v15; // [esp+28h] [ebp+4h]

    v1 = a1;
    v2 = *(_BYTE*)(a1 + 432);
    v12 = *(_BYTE*)(a1 + 432);
    if (v2 > 1 && *(_WORD*)(a1 + 258))
    {
        v3 = (double) * (unsigned int*)& byte_5D4594[2598000] / (double)(*(unsigned __int16*)(a1 + 258) * v2);
        v4 = (__int64)v3;
        v5 = v3 - (double)(int)(__int64)v3;
        if (*(_BYTE*)(a1 + 176) & 1)
        {
            v6 = v5 * (double)v2;
            v15 = (__int64)v6;
            v7 = v15 + 1;
            if ((char)(v15 + 1) >= v12)
                v7 = 0;
        }
        else
        {
            v6 = v5 * (double)v2;
            if (v4 & 1)
            {
                v8 = v2 - (unsigned __int64)(__int64)v6 - 1;
                v15 = v8;
                v7 = v8 - 1;
                if (v7 < 0)
                    v7 = 0;
            }
            else
            {
                v15 = (__int64)v6;
                v7 = v15 + 1;
                if ((char)(v15 + 1) >= v12)
                    v7 = v12 - 1;
            }
        }
        v13 = (double) * (unsigned __int16*)(v1 + 258);
        v9 = v7;
        v10 = (double)(unsigned __int8)(__int64)((v6 - (double)(int)(__int64)v6) * v13);
        v11 = v1 + 2 * v15 + v15;
        v14 = *(unsigned __int8*)(v15 + v1 + 2 * v15 + 120 + 60);
        sub_484BE0(
                (_DWORD*)(v1 + 136),
                (__int64)((double)(*(unsigned __int8*)(v9 + v1 + 2 * v9 + 178) - *(unsigned __int8*)(v11 + 178)) / v13 * v10
                          + (double) * (unsigned __int8*)(v11 + 178)),
                (__int64)((double)(*(unsigned __int8*)(v9 + v1 + 2 * v9 + 179) - *(unsigned __int8*)(v11 + 179)) / v13 * v10
                          + (double) * (unsigned __int8*)(v11 + 179)),
                (__int64)((double)(*(unsigned __int8*)(v9 + v1 + 2 * v9 + 120 + 60) - v14) / v13 * v10 + (double)v14));
    }
}

//----- (004CE610) --------------------------------------------------------
void __cdecl sub_4CE610(int a1)
{
    int v1; // esi
    double v2; // st7
    __int64 v3; // rax
    double v4; // st7
    double v5; // st7
    __int64 v6; // rax
    char v7; // bl
    float v8; // [esp+0h] [ebp-20h]
    char v9; // [esp+24h] [ebp+4h]
    float v10; // [esp+24h] [ebp+4h]

    v1 = a1;
    v9 = *(_BYTE*)(a1 + 433);
    if (v9 > 1 && *(_WORD*)(v1 + 260))
    {
        v2 = (double) * (unsigned int*)& byte_5D4594[2598000] / (double)(*(unsigned __int16*)(v1 + 260) * v9);
        v3 = (__int64)v2;
        v4 = v2 - (double)(int)(__int64)v2;
        if (*(_BYTE*)(v1 + 176) & 4)
        {
            v5 = v4 * (double)v9;
            v6 = (__int64)v5;
            v7 = (unsigned __int64)(__int64)v5 + 1;
            if (v7 >= v9)
                v7 = 0;
        }
        else
        {
            v5 = v4 * (double)v9;
            if (v3 & 1)
            {
                LOBYTE(v6) = v9 - (unsigned __int64)(__int64)v5 - 1;
                v7 = v9 - (unsigned __int64)(__int64)v5 - 2;
                if (v7 < 0)
                    v7 = 0;
            }
            else
            {
                v6 = (__int64)v5;
                v7 = (unsigned __int64)(__int64)v5 + 1;
                if (v7 >= v9)
                    v7 = v9 - 1;
            }
        }
        v10 = (double) * (unsigned __int16*)(v1 + 260);
        v8 = (double)(unsigned __int8)(__int64)((v5 - (double)(int)(__int64)v5) * v10)
             * ((double)(*(unsigned __int8*)(v7 + v1 + 226) - *(unsigned __int8*)((char)v6 + v1 + 226))
                / v10)
             + (double) * (unsigned __int8*)((char)v6 + v1 + 226);
        sub_484D70(v1 + 136, v8);
    }
}

//----- (004CE760) --------------------------------------------------------
int __cdecl sub_4CE760(int a1)
{
    int v1; // esi
    int result; // eax
    char v3; // bl
    double v4; // st7
    __int64 v5; // rax
    double v6; // st7
    double v7; // st7
    __int64 v8; // rax
    char v9; // bl
    char v10; // bl
    char v11; // [esp+20h] [ebp+4h]
    float v12; // [esp+20h] [ebp+4h]

    v1 = a1;
    result = *(_DWORD*)(a1 + 168);
    v3 = *(_BYTE*)(a1 + 434);
    v11 = *(_BYTE*)(a1 + 434);
    if (!result && *(_WORD*)(v1 + 262) > 0u && v3 > 1)
    {
        v4 = (double) * (unsigned int*)& byte_5D4594[2598000] / (double)(*(unsigned __int16*)(v1 + 262) * v3);
        v5 = (__int64)v4;
        v6 = v4 - (double)(int)(__int64)v4;
        if (*(_BYTE*)(v1 + 176) & 0x10)
        {
            v7 = v6 * (double)v3;
            v8 = (__int64)v7;
            v9 = (unsigned __int64)(__int64)v7 + 1;
            if (v9 >= v11)
                v9 = 0;
        }
        else
        {
            v7 = v6 * (double)v3;
            if (v5 & 1)
            {
                v10 = v3 - (unsigned __int64)(__int64)v7 - 1;
                LOBYTE(v8) = v10;
                v9 = v10 - 1;
                if (v9 < 0)
                    v9 = 0;
            }
            else
            {
                v8 = (__int64)v7;
                v9 = (unsigned __int64)(__int64)v7 + 1;
                if (v9 >= v11)
                    v9 = v11 - 1;
            }
        }
        v12 = (double) * (unsigned __int16*)(v1 + 262);
        result = sub_484C30(
                v1 + 136,
                (__int64)((double)(unsigned __int8)(__int64)((v7 - (double)(int)(__int64)v7) * v12)
                          * ((double)(*(unsigned __int8*)(v9 + v1 + 242) - *(unsigned __int8*)((char)v8 + v1 + 242))
                             / v12)
                          + (double) * (unsigned __int8*)((char)v8 + v1 + 242)));
    }
    return result;
}

//----- (004CE8C0) --------------------------------------------------------
void __cdecl sub_4CE8C0(int a1)
{
    _DWORD* v1; // eax
    int v2; // esi
    double v3; // st7
    int v4; // [esp+10h] [ebp-8h]

    if (*(_BYTE*)(a1 + 176) & 0x40)
    {
        v1 = sub_45A720(*(_DWORD*)(a1 + 264));
        if (v1)
        {
            v2 = v1[4] - *(_DWORD*)(a1 + 16);
            v4 = v1[3] - *(_DWORD*)(a1 + 12);
            v3 = sub_419AF0(acos((double)v4 / sqrt((double)(v4 * v4 + v2 * v2)))) * 57.295776;
            if (v2 < 0)
                v3 = 360.0 - v3;
            sub_484C00(a1 + 136, (__int64)v3);
        }
    }
}

//----- (004CE960) --------------------------------------------------------
__int16 __cdecl sub_4CE960(int a1)
{
    int v1; // eax
    __int16 v2; // cx
    double v3; // st7
    double v4; // st6
    double v5; // st5
    __int64 v6; // rax

    v1 = *(_DWORD*)(a1 + 168);
    if (!v1)
    {
        v2 = *(_WORD*)(a1 + 176);
        if ((v2 & 0x80u) != 0)
        {
            LOWORD(v1) = *(_WORD*)(a1 + 270);
            if ((_WORD)v1)
            {
                if ((v2 & 0x100) == 256)
                    v5 = (double)(*(unsigned __int16*)(a1 + 272) - *(unsigned __int16*)(a1 + 268));
                else
                    v5 = 360.0;
                v4 = (double) * (unsigned int*)& byte_5D4594[2649704];
                v3 = (double)(__int16)v1;
                v6 = (__int64)(((double) * (unsigned int*)& byte_5D4594[2598000] / (v5 / v3 * v4)
                                - (double)(int)(__int64)((double) * (unsigned int*)& byte_5D4594[2598000] / (v5 / v3 * v4)))
                               * (v5
                                  / v3
                                  * v4)
                               * (v3
                                  / v4)
                               + (double) * (unsigned __int16*)(a1 + 268));
                if ((int)v6 >= 0)
                {
                    if ((int)v6 >= 360)
                        LODWORD(v6) = v6 - 360;
                }
                else
                {
                    LODWORD(v6) = v6 + 360;
                }
                LOWORD(v1) = sub_484C00(a1 + 136, v6);
            }
        }
    }
    return v1;
}

//----- (004CEA90) --------------------------------------------------------
int __cdecl sub_4CEA90(float* a1, int2* a2, int a3)
{
    int v3; // ebx
    int v4; // ebp
    int v5; // esi
    int v7; // [esp+10h] [ebp-18h]
    int v8; // [esp+14h] [ebp-14h]
    int v9; // [esp+18h] [ebp-10h]
    int v10; // [esp+1Ch] [ebp-Ch]
    int v11; // [esp+20h] [ebp-8h]

    v3 = a2->field_0 + sub_419A70(*a1);
    v4 = a2->field_4 + sub_419A70(a1[1]);
    v9 = a2->field_0 + sub_419A70(a1[2]);
    v10 = a2->field_4 + sub_419A70(a1[3]);
    v7 = a2->field_0 + sub_419A70(a1[4]);
    v8 = a2->field_4 + sub_419A70(a1[5]);
    v11 = a2->field_0 + sub_419A70(a1[6]);
    v5 = a2->field_4 + sub_419A70(a1[7]);
    sub_434460(a3);
    sub_49F500(v3, v4);
    sub_49F500(v7, v8);
    sub_49E4B0();
    sub_49F500(v11, v5);
    sub_49F500(v7, v8);
    sub_49E4B0();
    sub_49F500(v3, v4);
    sub_49F500(v9, v10);
    sub_49E4B0();
    sub_49F500(v11, v5);
    sub_49F500(v9, v10);
    return sub_49E4B0();
}

//----- (004CEBA0) --------------------------------------------------------
int __cdecl sub_4CEBA0(int a1, char* a2)
{
    _DWORD* v2; // eax
    _DWORD* v3; // edi
    char* v4; // ebx
    _DWORD* v5; // esi
    _DWORD* v6; // ebp
    _DWORD* v8; // [esp+10h] [ebp-4h]
    char* v9; // [esp+18h] [ebp+4h]

    *(_DWORD*)& byte_5D4594[1523024] = nox_new_window_from_file("rulelist.wnd", sub_4CF060);
    *(_DWORD*)& byte_5D4594[1523028] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10170);
    *(_DWORD*)& byte_5D4594[1523032] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10171);
    *(_DWORD*)& byte_5D4594[1523036] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10172);
    *(_DWORD*)& byte_5D4594[1523040] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10173);
    *(_DWORD*)& byte_5D4594[1523044] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10174);
    *(_DWORD*)& byte_5D4594[1523048] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10175);
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10176);
    sub_46B340((int)v2, sub_4CEED0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1523024], a1);
    v3 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[1523028] + 32);
    v9 = sub_42F970("UISlider");
    v4 = sub_42F970("UISliderLit");
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10179);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10177);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], 10178);
    *(_DWORD*)(v5[100] + 8) = 16;
    *(_DWORD*)(v5[100] + 12) = 10;
    sub_4B5700((int)v5, 0, 0, (int)v9, (int)v4, (int)v4);
    sub_46B280((int)v5, *(int*)& byte_5D4594[1523028]);
    sub_46B280((int)v6, *(int*)& byte_5D4594[1523028]);
    sub_46B280((int)v8, *(int*)& byte_5D4594[1523028]);
    v3[9] = v5;
    v3[7] = v6;
    v3[8] = v8;
    sub_4CED40(a2);
    return *(_DWORD*)& byte_5D4594[1523024];
}

//----- (004CED40) --------------------------------------------------------
HANDLE __cdecl sub_4CED40(char* a1)
{
    HANDLE result; // eax
    HANDLE v2; // ebp
    struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-248h]
    CHAR FileName[64]; // [esp+148h] [ebp-108h]
    wchar_t v5[100]; // [esp+188h] [ebp-C8h]

    nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16399, 0, 0);
    nox_sprintf(FileName, "maps\\%s\\*.rul", a1);
    result = FindFirstFileA(FileName, &FindFileData);
    v2 = result;
    if (result != (HANDLE)-1)
    {
        FindFileData.cFileName[strlen(FindFileData.cAlternateFileName) + 256] = 0;
        if (_strcmpi(a1, FindFileData.cAlternateFileName)
            && _strcmpi("user", FindFileData.cAlternateFileName))
        {
            nox_swprintf(v5, L"%S", FindFileData.cAlternateFileName);
            nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16397, (int)v5, -1);
        }
        while (FindNextFileA(v2, &FindFileData))
        {
            FindFileData.cFileName[strlen(FindFileData.cAlternateFileName) + 256] = 0;
            if (_strcmpi(a1, FindFileData.cAlternateFileName))
            {
                if (_strcmpi("user", FindFileData.cAlternateFileName))
                {
                    nox_swprintf(v5, L"%S", FindFileData.cAlternateFileName);
                    nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16397, (int)v5, -1);
                }
            }
        }
        result = (HANDLE)FindClose(v2);
    }
    return result;
}

//----- (004CEED0) --------------------------------------------------------
int __cdecl sub_4CEED0(int a1, int a2)
{
    int v2; // eax
    char v3; // cl
    _WORD* v4; // esi
    _DWORD* v5; // eax
    int xLeft; // [esp+8h] [ebp-8h]
    int yTop; // [esp+Ch] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
    }
    v2 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16404, 0, 0);
    v3 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1523040] + 4);
    if (v2 < 0)
    {
        if (v3 & 8)
            sub_46ABB0(*(int*)& byte_5D4594[1523040], 0);
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1523044] + 4) & 8)
            sub_46ABB0(*(int*)& byte_5D4594[1523044], 0);
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1523048] + 4) & 8)
            sub_46ABB0(*(int*)& byte_5D4594[1523048], 0);
    }
    else
    {
        if (!(v3 & 8))
            sub_46ABB0(*(int*)& byte_5D4594[1523040], 1);
        if (!(*(_BYTE*)(*(_DWORD*)& byte_5D4594[1523044] + 4) & 8) && !sub_40A5C0(49152))
            sub_46ABB0(*(int*)& byte_5D4594[1523044], 1);
        if (!(*(_BYTE*)(*(_DWORD*)& byte_5D4594[1523048] + 4) & 8))
            sub_46ABB0(*(int*)& byte_5D4594[1523048], 1);
    }
    v4 = (_WORD*)nox_window_call_field_94(*(int*)& byte_5D4594[1523032], 16413, 0, 0);
    v5 = (_DWORD*)sub_46B4F0();
    if (v5 && *v5 == 10171)
    {
        if (v4 && *v4)
        {
            if (!(*(_BYTE*)(*(_DWORD*)& byte_5D4594[1523036] + 4) & 8))
            {
                sub_46ABB0(*(int*)& byte_5D4594[1523036], 1);
                return 1;
            }
        }
        else if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1523036] + 4) & 8)
        {
            sub_46ABB0(*(int*)& byte_5D4594[1523036], 0);
        }
    }
    return 1;
}

//----- (004CF060) --------------------------------------------------------
int __cdecl sub_4CF060(int a1, unsigned int a2, int* a3, int a4)
{
    _DWORD* v4; // esi
    const char* v6; // eax
    const char* v7; // esi
    char* v8; // eax
    int v9; // esi
    int v10; // eax
    int v11; // eax
    char* v12; // eax
    char* v13; // eax
    char* v14; // esi
    int v15; // eax
    int v16; // eax
    char* v17; // eax
    char* v18; // edi
    int v19; // eax
    int v20; // esi
    int v21; // eax
    const wchar_t* v22; // edi
    char* v23; // eax
    char* v24; // eax
    int v25; // esi
    int v26; // ebx
    const wchar_t* v27; // eax
    char v28[16]; // [esp+Ch] [ebp-10h]

    if (a2 > 0x4007)
    {
        if (a2 == 16400)
            sub_46B0A0(a3);
        return 1;
    }
    if (a2 != 16391)
    {
        if (a2 != 23 && a2 == 16387)
        {
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1523024], a4);
            sub_416630();
            sub_416640();
            if (!v4)
                return 0;
            if ((unsigned __int16)a3 == 1)
                return 0;
            v6 = (const char*)nox_window_call_field_94((int)v4, 16413, 0, 0);
            v7 = v6;
            if (v6)
            {
                if (*v6)
                {
                    atoi(v6);
                    if (a4 == 10171)
                    {
                        v8 = sub_4165B0();
                        if (!_strcmpi(v7, v8) || !_strcmpi(v7, "user"))
                        {
                            sub_46ABB0(*(int*)& byte_5D4594[1523036], 0);
                            return 1;
                        }
                    }
                }
            }
        }
        return 1;
    }
    v9 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v9)
    {
        case 10172:
            sub_416580();
            v22 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1523032], 16413, 0, 0);
            nox_sprintf(v28, "%S%s", v22, &byte_587000[191640]);
            v23 = sub_4165B0();
            sub_459AA0((int)v23);
            v24 = sub_4165B0();
            sub_57AAA0(v28, v24, 0);
            v25 = 0;
            v26 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1523028] + 32);
            if (*(short*)(v26 + 44) <= 0)
                goto LABEL_22;
            break;
        case 10173:
            sub_416580();
            v10 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16404, 0, 0);
            v11 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16406, v10, 0);
            nox_sprintf(v28, "%S%s", v11, &byte_587000[191592]);
            v12 = sub_4165B0();
            sub_459AA0((int)v12);
            v13 = sub_4165B0();
            sub_57AAA0(v28, v13, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16403, -1, 0);
            return 1;
        case 10174:
            sub_416580();
            v14 = sub_4165B0();
            v15 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16404, 0, 0);
            v16 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16406, v15, 0);
            nox_sprintf(v28, "%S%s", v16, &byte_587000[191608]);
            sub_57A1E0((int*)v14, v28, 0, 7, *((_WORD*)v14 + 26));
            sub_453F70(v14 + 24);
            sub_4535E0((int*)v14 + 11);
            sub_4535F0(*((_DWORD*)v14 + 12));
            v17 = sub_4165B0();
            sub_459880((int)v17);
            nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16403, -1, 0);
            sub_459D50(1);
            return 1;
        case 10175:
            v18 = sub_4165B0();
            v19 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16404, 0, 0);
            v20 = v19;
            v21 = nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16406, v19, 0);
            nox_sprintf(v28, "%S%s", v21, &byte_587000[191624]);
            sub_57A9F0(v18, v28);
            nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16398, v20, 0);
            return 1;
        default:
            return 1;
    }
    while (1)
    {
        v27 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16406, v25, 0);
        if (!_nox_wcsicmp(v22, v27))
            break;
        if (++v25 >= *(__int16*)(v26 + 44))
        {
            LABEL_22:
            nox_window_call_field_94(*(int*)& byte_5D4594[1523028], 16397, (int)v22, -1);
            nox_window_call_field_94(*(int*)& byte_5D4594[1523032], 16414, (int)& byte_5D4594[1523056], 0);
            sub_46ABB0(*(int*)& byte_5D4594[1523036], 0);
            return 1;
        }
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[1523032], 16414, (int)& byte_5D4594[1523052], 0);
    return 1;
}

//----- (004CF460) --------------------------------------------------------
void sub_4CF460()
{
    nox_srand(0x7D2u);
}

//----- (004CF470) --------------------------------------------------------
int __cdecl sub_4CF470(char* a1, int a2)
{
    int v2; // ebx
    int v4; // [esp+8h] [ebp-408h]
    int v5; // [esp+Ch] [ebp-404h]
    CHAR FileName[1024]; // [esp+10h] [ebp-400h]

    v2 = 0;
    if (!a2)
        return 6;
    if (a1)
    {
        if (strchr(a1, 92))
        {
            strcpy(FileName, a1);
        }
        else
        {
            strcpy(FileName, "maps\\");
            strncat(FileName, a1, strlen(a1) - 4);
            *(_WORD*)& FileName[strlen(FileName)] = *(_WORD*)& byte_587000[191672];
            strcat(FileName, a1);
        }
        if (_access(FileName, 0) != -1)
        {
            v4 = 0;
            if (_access(FileName, 2) == -1)
                v2 = 1;
            if (sub_426910(FileName, 1, 19))
            {
                v2 |= 2u;
                sub_426AC0(&v5, 4u);
                if (v5 != -86065425 && v5 == -86050098)
                {
                    sub_426C20(&v4, 4u);
                    if (v4 == a2)
                        v2 |= 4u;
                }
                sub_4269F0();
            }
        }
    }
    return v2;
}

//----- (004CF5F0) --------------------------------------------------------
int __cdecl sub_4CF5F0(char* a1, int a2)
{
    char* v2; // ebx
    char* v3; // eax
    char* v4; // eax
    int result; // eax
    char* v6; // eax
    int v7; // esi
    char* v8; // eax
    int v9; // eax
    int v10; // [esp+Ch] [ebp-65Ch]
    int v11; // [esp+10h] [ebp-658h]
    char v12[20]; // [esp+14h] [ebp-654h]
    char v13[64]; // [esp+28h] [ebp-640h]
    CHAR FileName[1024]; // [esp+68h] [ebp-600h]
    CHAR v15[256]; // [esp+468h] [ebp-200h]
    char v16[256]; // [esp+568h] [ebp-100h]

    sub_481410();
    sub_4DAC00();
    sub_5799C0();
    v2 = a1;
    if (!a1)
        return 0;
    if (_strcmpi("#return", a1))
    {
        if (*a1 == 35)
        {
            v3 = sub_409E10();
            sub_4D39F0(v3);
            strcpy(v13, a1 + 1);
            v4 = strchr(v13, 46);
            if (v4)
                * v4 = 0;
            sub_4D42E0(v13);
            nox_sprintf(v12, "$%s.map", v13);
            sub_409D70(v12);
            if (!sub_4D4320())
            {
                sub_4D12E0(1);
                return 0;
            }
            sub_4D3C30();
            v2 = v12;
        }
    }
    else
    {
        v2 = (char*)& byte_5D4594[1523080];
    }
    if (strchr(v2, 92))
    {
        strcpy(FileName, v2);
    }
    else
    {
        strcpy(FileName, "maps\\");
        strncat(FileName, v2, strlen(v2) - 4);
        *(_WORD*)& FileName[strlen(FileName)] = *(_WORD*)& byte_587000[191700];
        strcat(FileName, v2);
    }
    if (_access(FileName, 0) == -1)
    {
        v6 = strchr(FileName, 46);
        if (v6)
        {
            v7 = v6 - FileName;
            strncpy(v16, FileName, v6 - FileName);
            v16[v7] = 0;
            nox_sprintf(v15, "%s%s", v16, &byte_587000[191704]);
            if (_access(v15, 0) == -1)
                return 0;
            if (!sub_57BC50(v15, FileName))
                return 0;
        }
    }
    v8 = sub_409B40();
    sub_4CFE10(v8);
    if (a2)
        v9 = sub_426910(FileName, 1, -1);
    else
        v9 = sub_426910(FileName, 1, 19);
    if (!v9)
        return 0;
    sub_426AC0(&v10, 4u);
    if (v10 == -86065425)
    {
        sub_409B10(0);
    }
    else
    {
        if (v10 != -86050098)
        {
            sub_4269F0();
            return 0;
        }
        sub_426C20(&v11, 4u);
        sub_409B10(v11);
    }
    if (!sub_4CFCE0())
        return 0;
    sub_507290();
    sub_4269F0();
    if (!sub_40A5C0(0x200000))
    {
        sub_4CF990();
        nullsub_21();
        if (sub_43AF70() == 1)
            sub_416690();
        sub_40A540(0x4000000);
        sub_470680();
        sub_4D0550(FileName);
        sub_4161E0();
        if (!sub_40A5C0(128))
            sub_4165F0(0, 1);
    }
    result = 1;
    strcpy((char*)& byte_5D4594[1523080], v2);
    return result;
}
// 4CF980: using guessed type void nullsub_21(void);
// 4CF5F0: using guessed type char var_100[256];

//----- (004CF990) --------------------------------------------------------
char sub_4CF990()
{
    char* v0; // esi
    char* v1; // eax
    unsigned __int16 v2; // ax
    int v3; // eax
    BOOL v4; // esi
    __int16 v5; // ax

    v0 = sub_4165B0();
    if (sub_40A5C0(1024) && (*(int*)& byte_5D4594[3803228] < 0 || !(v0[53] & 4)))
        sub_40A5E0(0);
    sub_455C10();
    sub_456050();
    if (sub_40A5C0(4096) && *(int*)& byte_5D4594[3803228] < 0)
    {
        sub_4D6B10(1);
        sub_419030(1);
    }
    v1 = sub_409B40();
    if (sub_4CFE10(v1))
    {
        v2 = sub_4CFFA0((int)& byte_5D4594[3801836]);
        if (byte_5D4594[3803228] & 1)
        {
            sub_40A540(6128);
            sub_417E10();
            LOBYTE(v3) = sub_40A4D0(2048);
        }
        else if (byte_5D4594[3803228] & 2)
        {
            v4 = sub_40A5C0(128);
            sub_40A540(6128);
            LOBYTE(v3) = sub_40A4D0(4096);
            if (v4)
                LOBYTE(v3) = sub_4D6C70();
        }
        else if ((int) * (_DWORD*)& byte_5D4594[3803228] >= 0)
        {
            if (!(*((_WORD*)v0 + 26) & v2))
                * ((_WORD*)v0 + 26) = sub_4CFC90((int)& byte_5D4594[3801836]) | *((_WORD*)v0 + 26) & 0xE80F;
            if (!(v0[52] & 0x10))
                sub_4CFC30();
            v5 = *((_WORD*)v0 + 26);
            if (v5 & 0x20)
            {
                v3 = sub_417EA0();
                if (v3)
                {
                    sub_40A540(6128);
                    LOBYTE(v3) = sub_40A4D0(32);
                }
            }
            else if (v5 & 0x40)
            {
                LOBYTE(v3) = sub_417F30();
                if (v3)
                {
                    sub_40A540(6128);
                    sub_40A4D0(64);
                    LOBYTE(v3) = sub_424BB0(132);
                }
            }
            else if (v5 & 0x10)
            {
                v3 = sub_4180D0();
                if (v3)
                {
                    sub_40A540(6128);
                    LOBYTE(v3) = sub_40A4D0(16);
                }
            }
            else if (v5 & 0x400)
            {
                if (!sub_40A5C0(1024))
                    sub_40A5E0(1);
                sub_40A540(6128);
                LOBYTE(v3) = sub_40A4D0(1024);
            }
            else
            {
                sub_40A540(6128);
                LOBYTE(v3) = sub_40A4D0(256);
            }
        }
        else
        {
            sub_40A1F0(0);
            sub_40A540(6128);
            sub_40A4D0(128);
            LOBYTE(v3) = sub_417DD0();
            if ((_BYTE)v3)
            {
                sub_418640();
                v3 = sub_417DA0(2);
                if (!v3)
                {
                    v3 = sub_40A5C0(0x8000);
                    if (!v3)
                        LOBYTE(v3) = (unsigned int)sub_418690(1);
                }
            }
        }
    }
    else
    {
        v3 = sub_40A5C0(512);
        if (!v3)
        {
            sub_40A540(6128);
            sub_40A4D0(256);
            LOBYTE(v3) = sub_4D0D90(1);
        }
    }
    return v3;
}
// 4CFAF1: variable 'v2' is possibly undefined
// 4CFB53: variable 'v3' is possibly undefined

//----- (004CFC30) --------------------------------------------------------
void sub_4CFC30()
{
    int v0; // esi
    int v1; // edi

    if (!*(_DWORD*)& byte_5D4594[1523076])
        * (_DWORD*)& byte_5D4594[1523076] = sub_4E3AA0((CHAR*)& byte_587000[191720]);
    v0 = sub_4DA790();
    if (v0)
    {
        do
        {
            v1 = sub_4DA7A0(v0);
            if (*(unsigned __int16*)(v0 + 4) == *(_DWORD*)& byte_5D4594[1523076])
            {
                sub_4E5CC0(v0);
                sub_4EC6A0(v0);
            }
            v0 = v1;
        } while (v1);
    }
}

//----- (004CFC90) --------------------------------------------------------
int __cdecl sub_4CFC90(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)(a1 + 1392);
    if (v1 & 4)
        return 256;
    if (v1 & 0x20)
        return 1024;
    if (v1 & 8)
        return 32;
    if (v1 & 0x10)
        return 16;
    if (v1 & 0x40)
        return 64;
    return (v1 & 2) != 0 ? 4096 : 128;
}

//----- (004CFCE0) --------------------------------------------------------
int sub_4CFCE0()
{
    _DWORD* v0; // eax
    int v1; // esi
    int v3; // [esp+4h] [ebp-114h]
    int v4; // [esp+8h] [ebp-110h]
    int v5[2];
    int v7; // [esp+14h] [ebp-104h]
    char v8[256]; // [esp+18h] [ebp-100h]

    sub_426AC0(&v5[0], 4u);
    sub_426AC0(&v5[1], 4u);
    sub_426A80(&v5);
    while (1)
    {
        LOBYTE(v3) = 0;
        sub_426AC0(&v3, 1u);
        if (!(_BYTE)v3)
            break;
        sub_426AC0(v8, (unsigned __int8)v3);
        sub_426C20(&v7, 4u);
        if (!sub_426EA0(0, v8, &v4))
        {
            if (v4 == 1)
                return 0;
            v0 = sub_4E3810(v8);
            v1 = (int)v0;
            if (!v0 || !((int(__cdecl*)(_DWORD*, _DWORD))v0[176])(v0, 0))
                goto LABEL_9;
            sub_4F3F50(v1, 0, 0);
        }
    }
    if (!sub_579CA0())
    {
        LABEL_9:
        sub_4269F0();
        return 0;
    }
    sub_4DAF10();
    if (sub_40A5C0(1))
    {
        sub_5799C0();
        sub_4DAC00();
    }
    sub_4DB090();
    return 1;
}

//----- (004CFDF0) --------------------------------------------------------
int __cdecl sub_4CFDF0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1523072] = a1;
    return result;
}

//----- (004CFE00) --------------------------------------------------------
int sub_4CFE00()
{
    return *(_DWORD*)& byte_5D4594[1523072];
}

//----- (004CFE10) --------------------------------------------------------
int __cdecl sub_4CFE10(const char* a1)
{
    char* v1; // edi
    unsigned __int8 v2; // cl
    int result; // eax
    int v4; // [esp+10h] [ebp-108h]
    int v5; // [esp+14h] [ebp-104h]
    char v6[256]; // [esp+18h] [ebp-100h]

    strcpy(v6, "maps\\");
    strcat(v6, a1);
    *(_WORD*)& v6[strlen(v6)] = *(_WORD*)& byte_587000[191736];
    strcat(v6, a1);
    v1 = &v6[strlen(v6)];
    v2 = byte_587000[191744];
    strcat(v1, ".map");
    v1[4] = v2;
    result = sub_426910(v6, 1, 19);
    if (result)
    {
        sub_426AC0(&v4, 4u);
        if (v4 != -86065425)
        {
            if (v4 != -86050098)
            {
                sub_4269F0();
                return 0;
            }
            sub_426C20(&v5, 4u);
        }
        sub_426AC0(v6, 0x20u);
        if (sub_42A6E0())
        {
            sub_4269F0();
            result = 1;
        }
        else
        {
            sub_4269F0();
            result = 0;
        }
    }
    return result;
}

//----- (004CFF50) --------------------------------------------------------
int __cdecl sub_4CFF50(int a1)
{
    int result; // eax

    result = 0;
    if (a1 & 1)
        result = 512;
    if (a1 & 2)
        BYTE1(result) |= 0x10u;
    if (a1 & 4)
        BYTE1(result) |= 1u;
    if (a1 & 0x20)
        BYTE1(result) |= 4u;
    if (a1 & 8)
        LOBYTE(result) = result | 0x20;
    if (a1 & 0x10)
        LOBYTE(result) = result | 0x10;
    if (a1 & 0x40)
        LOBYTE(result) = result | 0x40;
    if (a1 < 0)
        LOBYTE(result) = result | 0x80;
    return result;
}

//----- (004CFFA0) --------------------------------------------------------
int __cdecl sub_4CFFA0(int a1)
{
    return sub_4CFF50(*(_DWORD*)(a1 + 1392));
}

//----- (004CFFC0) --------------------------------------------------------
int __cdecl sub_4CFFC0(int a1)
{
    return sub_4CFF50(*(_DWORD*)(a1 + 28));
}

//----- (004CFFE0) --------------------------------------------------------
int __cdecl sub_4CFFE0(int a1)
{
    int result; // eax

    result = sub_4DA870();
    if (!result)
        return 0;
    while (*(_DWORD*)(result + 44) != a1)
    {
        result = sub_4DA880(result);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004D0010) --------------------------------------------------------
int __cdecl sub_4D0010(_DWORD* a1, int a2)
{
    int i; // eax
    _DWORD* v3; // edi
    CHAR* v4; // eax
    int(__cdecl * v5)(int); // eax
    int v6; // esi
    int v7; // eax
    int v8; // ecx
    int v9; // eax
    int v10; // ecx
    int v11; // esi
    int v12; // eax
    int v13; // ecx
    int v14; // esi
    char* v15; // eax
    int v16; // ecx
    int v17; // esi
    char* v18; // eax
    int v19; // esi
    _DWORD* v20; // eax
    int v21; // eax
    int v22; // esi
    char* v23; // eax

    for (i = sub_4DA870(); i; i = sub_4DA880(i))
    {
        *(_DWORD*)(i + 44) = *(_DWORD*)(i + 40);
        *(_DWORD*)(i + 40) = a2++;
    }
    v3 = (_DWORD*)sub_4DA870();
    if (v3)
    {
        while (1)
        {
            v4 = (CHAR*)sub_4E39D0((int)v3);
            v5 = *(int(__cdecl * *)(int))(sub_4E3B60(v4) + 212);
            if (v5 != sub_4F53D0)
                break;
            v6 = v3[187];
            v7 = sub_4CFFE0(*(_DWORD*)(v6 + 8));
            if (!v7)
                goto LABEL_7;
            v8 = *(_DWORD*)(v7 + 40);
            *(_DWORD*)(v6 + 4) = v7;
            *(_DWORD*)(v6 + 8) = v8;
            LABEL_28:
            v3 = (_DWORD*)sub_4DA880((int)v3);
            if (!v3)
                return a2;
        }
        if (v5 != sub_4F54A0)
        {
            if (v5 == sub_4F5300)
            {
                v11 = v3[187];
                v12 = sub_4CFFE0(*(_DWORD*)(v11 + 16));
                if (v12)
                {
                    v13 = *(_DWORD*)(v12 + 40);
                    *(_DWORD*)(v11 + 12) = v12;
                    *(_DWORD*)(v11 + 16) = v13;
                }
                else
                {
                    *(_DWORD*)(v11 + 16) = 0;
                    *(_DWORD*)(v11 + 12) = 0;
                }
            }
            else if (v5 == sub_4F51D0)
            {
                v14 = v3[175];
                v15 = sub_426A70();
                v16 = *(_DWORD*)(v14 + 12);
                *(_DWORD*)(v14 + 8) += *a1 - 23 * *(_DWORD*)v15;
                *(_DWORD*)(v14 + 12) = a1[1] - 23 * *((_DWORD*)v15 + 1) + v16;
            }
            else if (v5 == sub_4F4B90)
            {
                v17 = v3[175];
                v18 = sub_426A70();
                *(float*)(v17 + 80) = (double)(int)(*a1 - 23 * *(_DWORD*)v18) + *(float*)(v17 + 80);
                *(float*)(v17 + 84) = (double)(int)(a1[1] - 23 * *((_DWORD*)v18 + 1)) + *(float*)(v17 + 84);
            }
            else if (v5 == sub_4F5730)
            {
                v19 = v3[187];
                v20 = (_DWORD*)sub_579C60(*(_DWORD*)(v19 + 8));
                if (v20)
                    * (_DWORD*)(v19 + 8) = *v20;
                else
                    *(_DWORD*)(v19 + 8) = 0;
                v21 = sub_4CFFE0(*(_DWORD*)(v19 + 32));
                if (v21)
                    * (_DWORD*)(v19 + 32) = *(_DWORD*)(v21 + 40);
                else
                    *(_DWORD*)(v19 + 32) = 0;
            }
            else if (v5 == sub_4F5890)
            {
                v22 = v3[173];
                v23 = sub_426A70();
                *(float*)(v22 + 28) = (double)(int)(*a1 - 23 * *(_DWORD*)v23) + *(float*)(v22 + 28);
                *(float*)(v22 + 32) = (double)(int)(a1[1] - 23 * *((_DWORD*)v23 + 1)) + *(float*)(v22 + 32);
            }
            goto LABEL_28;
        }
        v6 = v3[187];
        v9 = sub_4CFFE0(*(_DWORD*)(v6 + 8));
        if (v9)
        {
            v10 = *(_DWORD*)(v9 + 40);
            *(_DWORD*)(v6 + 4) = v9;
            *(_DWORD*)(v6 + 8) = v10;
            goto LABEL_28;
        }
        LABEL_7:
        *(_DWORD*)(v6 + 8) = 0;
        *(_DWORD*)(v6 + 4) = 0;
        goto LABEL_28;
    }
    return a2;
}

//----- (004D0250) --------------------------------------------------------
int __cdecl sub_4D0250(char* a1, char* a2, int a3, int a4)
{
    int result; // eax
    FILE* v5; // esi
    _DWORD* v6; // edi
    int v7; // ebp
    _DWORD* v8; // esi
    int i; // eax
    int j; // eax
    int v11; // esi
    int k; // eax
    int l; // eax
    int v14; // [esp+10h] [ebp-148h]
    int v15; // [esp+14h] [ebp-144h]
    int v16; // [esp+18h] [ebp-140h]
    int v17[2]; // [esp+1Ch] [ebp-13Ch]
    int v19; // [esp+24h] [ebp-134h]
    int v20; // [esp+28h] [ebp-130h]
    int v21; // [esp+2Ch] [ebp-12Ch]
    int v22; // [esp+30h] [ebp-128h]
    int v23; // [esp+34h] [ebp-124h]
    int v24; // [esp+38h] [ebp-120h]
    int v25; // [esp+3Ch] [ebp-11Ch]
    int v26; // [esp+40h] [ebp-118h]
    int v27; // [esp+44h] [ebp-114h]
    int4 v28; // [esp+48h] [ebp-110h]
    char v29[256]; // [esp+58h] [ebp-100h]

    if (a3 <= 0)
        return 0;
    result = sub_426910(a1, 1, -1);
    if (result)
    {
        v5 = sub_426A60();
        fread(&v16, 4u, 1u, v5);
        if (v16 == a4)
        {
            fread(&v17[0], 4u, 1u, v5);
            fread(&v17[1], 4u, 1u, v5);
            sub_426A80(v17);
            fread(&v19, 4u, 1u, v5);
            fread(&v20, 4u, 1u, v5);
            fread(&v25, 4u, 1u, v5);
            fread(&v26, 4u, 1u, v5);
            fread(&v21, 4u, 1u, v5);
            fread(&v22, 4u, 1u, v5);
            fread(&v23, 4u, 1u, v5);
            fread(&v24, 4u, 1u, v5);
            v6 = a2;
            if (!a2)
                v6 = &v19;
            sub_428170(v6, &v28);
            v7 = sub_426A30();
            sub_426A20(5);
            sub_426A50(1);
            while (1)
            {
                sub_426AC0(&v15, 1u);
                if (!(_BYTE)v15)
                    break;
                sub_426AC0(v29, (unsigned __int8)v15);
                sub_426AC0(&v27, 4u);
                if (!sub_426EA0((int)v6, v29, &v14))
                {
                    if (v14 == 1)
                        goto LABEL_20;
                    v8 = sub_4E3810(v29);
                    if (!v8)
                    {
                        sub_426A50(0);
                        return 0;
                    }
                    if (!((int(__cdecl*)(_DWORD*, int4*))v8[176])(v8, &v28))
                    {
                        sub_426A20(v7);
                        sub_4E38A0((int)v8);
                        sub_4269F0();
                        return 0;
                    }
                    sub_4F3F50((int)v8, 0, &v28.field_0);
                }
            }
            for (i = sub_4DA870(); i; i = sub_4DA880(i))
                * (_DWORD*)(i + 16) |= 0x80000000;
            sub_426A50(0);
            sub_426A20(v7);
            sub_4269F0();
            if (!sub_579D20())
            {
                LABEL_20:
                sub_426A20(v7);
                sub_4269F0();
                return 0;
            }
            for (j = sub_579890(); j; j = sub_5798A0(j))
                * (_DWORD*)(j + 480) |= 0x80000000;
            v11 = sub_4D0010(&v28, a3);
            for (k = sub_579890(); k; k = sub_5798A0(k))
                * (_DWORD*)(k + 4) = 0;
            for (l = sub_4DA870(); l; l = sub_4DA880(l))
                * (_DWORD*)(l + 44) = 0;
            sub_5799C0();
            sub_4DB030();
            result = v11;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (004D0550) --------------------------------------------------------
int __cdecl sub_4D0550(char* a1)
{
    int result; // eax
    unsigned int v2; // kr08_4
    char v3; // cl
    int v4; // edx
    unsigned __int8 v5; // al
    char* v6; // edi
    char* v7; // edi
    unsigned __int8 v8; // cl
    unsigned __int8 v9; // [esp+4h] [ebp-104h]
    char v10[256]; // [esp+8h] [ebp-100h]

    result = 0;
    if (a1)
    {
        v10[0] = 0;
        strncat(v10, a1, strlen(a1));
        v2 = strlen(v10) + 1;
        v3 = v2 - 1;
        v9 = v2 - 1;
        if ((_BYTE)v2 != 1)
        {
            while (v10[v9] != 92)
            {
                v9 = --v3;
                if (!v3)
                    goto LABEL_7;
            }
            v10[v9 + 1] = 0;
        }
        LABEL_7:
        v4 = *(_DWORD*)& byte_587000[191752];
        v5 = byte_587000[191756];
        v6 = &v10[strlen(v10)];
        *(_DWORD*)v6 = *(_DWORD*)& byte_587000[191748];
        *((_DWORD*)v6 + 1) = v4;
        v6[8] = v5;
        if (!sub_4D0670(v10))
        {
            v10[0] = 0;
            strncat(v10, a1, strlen(a1) - 4);
            v7 = &v10[strlen(v10) + 1];
            v8 = byte_587000[191764];
            *(_DWORD*)--v7 = *(_DWORD*)& byte_587000[191760];
            v7[4] = v8;
            sub_4D0670(v10);
        }
        if (sub_43AF70() == 1)
            sub_4D0670((char*)& byte_587000[191768]);
        result = 1;
    }
    return result;
}

//----- (004D0670) --------------------------------------------------------
int __cdecl sub_4D0670(char* a1)
{
    int v1; // ebp
    FILE* v2; // eax
    FILE* v3; // esi
    char* v4; // eax
    int v5; // eax
    char v7[255]; // [esp+Ch] [ebp-300h]
    wchar_t v8[256]; // [esp+10Ch] [ebp-200h]

    v1 = 6128;
    v2 = fopen(a1, "r");
    v3 = v2;
    if (!v2)
        return 0;
    if (!feof(v3))
    {
        do
        {
            memset(v7, 0, 0xFCu);
            *(_WORD*)& v7[252] = 0;
            v7[254] = 0;
            fgets(v7, 255, v3);
            v4 = strchr(v7, 10);
            if (v4)
                * v4 = 0;
            if (v7[0])
            {
                nox_swprintf(v8, L"%S", v7);
                v5 = sub_57AE30(v7);
                if (v5)
                {
                    v1 = v5;
                }
                else if (sub_40A5C0(v1))
                {
                    sub_443C80(v8, 1);
                }
            }
        } while (!feof(v3));
    }
    fclose(v3);
    return 1;
}

//----- (004D0760) --------------------------------------------------------
_DWORD* __cdecl sub_4D0760(int a1)
{
    int* v1; // edi

    v1 = sub_425890((int*)& byte_5D4594[1523060]);
    if (!v1)
        return sub_4258E0((int)& byte_5D4594[1523060], (_DWORD*)a1);
    while (strcmp((const char*)(a1 + 12), (const char*)v1 + 12) > 0)
    {
        v1 = sub_4258A0(v1);
        if (!v1)
            return sub_4258E0((int)& byte_5D4594[1523060], (_DWORD*)a1);
    }
    return sub_4258E0((int)v1, (_DWORD*)a1);
}

//----- (004D07F0) --------------------------------------------------------
HANDLE sub_4D07F0()
{
    HANDLE result; // eax
    HANDLE v1; // ebp
    char* v2; // ebp
    HANDLE v3; // [esp+4h] [ebp-150h]
    char v4[12]; // [esp+8h] [ebp-14Ch]
    struct _WIN32_FIND_DATAA FindFileData; // [esp+14h] [ebp-140h]

    sub_425760(&byte_5D4594[1523060]);
    result = FindFirstFileA((LPCSTR)& byte_587000[191796], &FindFileData);
    v1 = result;
    v3 = result;
    if (result != (HANDLE)-1)
    {
        do
        {
            if (FindFileData.dwFileAttributes & 0x10
                && (_strnicmp(FindFileData.cFileName, "wiz", 3u)
                    && _strnicmp(FindFileData.cFileName, "war", 3u)
                    && _strnicmp(FindFileData.cFileName, "con", 3u)
                    || FindFileData.cFileName[3] < 48
                    || FindFileData.cFileName[3] > 57)
                && strcmp(FindFileData.cFileName, ".")
                && strcmp(FindFileData.cFileName, ".."))
            {
                strncpy(v4, FindFileData.cFileName, 8u);
                v4[8] = 0;
                if (sub_4CFE10(v4))
                {
                    v2 = (char*)nox_malloc(0x24u);
                    sub_425770(v2);
                    strcpy(v2 + 12, v4);
                    *((_DWORD*)v2 + 6) = 1;
                    *((_DWORD*)v2 + 7) = *(_DWORD*)& byte_5D4594[3803228];
                    v2[33] = byte_5D4594[3803233];
                    v2[32] = byte_5D4594[3803232];
                    sub_4D0760((int)v2);
                    v1 = v3;
                }
            }
        } while (FindNextFileA(v1, &FindFileData));
        result = (HANDLE)FindClose(v1);
    }
    return result;
}

//----- (004D0970) --------------------------------------------------------
void sub_4D0970()
{
    int* result; // eax
    int* v1; // esi
    int* v2; // edi

    result = sub_425890((int*)& byte_5D4594[1523060]);
    v1 = result;
    if (result)
    {
        do
        {
            v2 = sub_4258A0(v1);
            sub_425920((_DWORD * *)v1);
            free(v1);
            v1 = v2;
        } while (v2);
    }
}

//----- (004D09B0) --------------------------------------------------------
int* sub_4D09B0()
{
    return sub_425890((int*)& byte_5D4594[1523060]);
}

//----- (004D09C0) --------------------------------------------------------
int* __cdecl sub_4D09C0(int* a1)
{
    return sub_4258A0(a1);
}

//----- (004D09D0) --------------------------------------------------------
int* __cdecl sub_4D09D0(char* a1)
{
    int* v1; // esi

    v1 = sub_4D09B0();
    if (!v1)
        return 0;
    while (_strcmpi(a1, (const char*)v1 + 12) || !v1[6])
    {
        v1 = sub_4D09C0(v1);
        if (!v1)
            return 0;
    }
    return v1;
}

//----- (004D0A20) --------------------------------------------------------
void sub_4D0A20()
{
    nox_srand(0x7D3u);
}

//----- (004D0A30) --------------------------------------------------------
FILE* sub_4D0A30()
{
    int v0; // ebp
    FILE* result; // eax
    FILE* v7; // ebx
    int v8; // eax
    int v9; // edx
    int v10; // eax
    int v11; // ebx
    char* v12; // eax
    int v13; // eax
    int v14; // ebx
    FILE* v15; // [esp+10h] [ebp-108h]
    char v16[128]; // [esp+18h] [ebp-100h]
    char v17[128]; // [esp+98h] [ebp-80h]

    v0 = 1;
    memset(&byte_5D4594[1548428], 0, 0x18u);
    strcpy((char*)& byte_5D4594[1524108], sub_409E10());
    strcat((char*)& byte_5D4594[1524108], "\\mapcycle.txt");
    result = fopen((const char*)& byte_5D4594[1524108], "r");
    v7 = result;
    v15 = result;
    if (result)
    {
        if (fgets(v16, 127, result))
        {
            sub_4D0CC0(v16);
            v8 = sub_4D0C80(v16);
            if (v8 < 0)
            {
                v9 = *(_DWORD*)& byte_5D4594[1548432];
                strcpy((char*)& byte_5D4594[128 * *(_DWORD*)& byte_5D4594[1548432] + 1532428], v16);
                *(_DWORD*)& byte_5D4594[1548432] = v9 + 1;
            }
            else
            {
                v0 = v8;
            }
        }
        while (!feof(v7))
        {
            if (fgets(v16, 127, v7))
            {
                sub_4D0CC0(v16);
                v10 = sub_4D0C80(v16);
                if (v10 < 0)
                {
                    if (*(int*)& byte_5D4594[4 * v0 + 1548428] < 25 && v16[0])
                    {
                        v11 = sub_4D0C70(v0);
                        strcpy(v17, v16);
                        v12 = strtok(v17, ".\n");
                        if (sub_4CFE10(v12))
                        {
                            v13 = sub_4CFFA0((int)& byte_5D4594[3801836]);
                            if (v13 & v11)
                            {
                                v14 = *(_DWORD*)& byte_5D4594[4 * v0 + 1548428];
                                strcpy((char*)& byte_5D4594[128 * (v14 + 20 * v0 + 5 * v0) + 1529228], v16);
                                *(_DWORD*)& byte_5D4594[4 * v0 + 1548428] = v14 + 1;
                            }
                        }
                        v7 = v15;
                    }
                }
                else
                {
                    v0 = v10;
                }
            }
        }
        result = (FILE*)fclose(v7);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1548484] = 0;
    }
    return result;
}
// 4D0BF1: variable 'v13' is possibly undefined

//----- (004D0C70) --------------------------------------------------------
int __cdecl sub_4D0C70(int a1)
{
    return *(_DWORD*)& byte_587000[8 * a1 + 191836];
}

//----- (004D0C80) --------------------------------------------------------
int __cdecl sub_4D0C80(char* a1)
{
    int v1; // edi
    const char** v2; // esi

    v1 = 0;
    v2 = (const char**)& byte_587000[191832];
    while (_strcmpi(*v2, a1))
    {
        v2 += 2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[191880])
            return -1;
    }
    return v1;
}

//----- (004D0CC0) --------------------------------------------------------
void __cdecl sub_4D0CC0(char* a1)
{
    char* v1; // eax
    char* v2; // eax

    if (a1)
    {
        v1 = strchr(a1, 13);
        if (v1)
            * v1 = 0;
        v2 = strchr(a1, 10);
        if (v2)
            * v2 = 0;
    }
}

//----- (004D0CF0) --------------------------------------------------------
char* sub_4D0CF0()
{
    int v0; // eax
    int v1; // eax
    int v2; // edi
    int v4; // esi

    v0 = sub_40A5B0();
    v1 = sub_4D0D50(v0);
    v2 = *(_DWORD*)& byte_5D4594[4 * v1 + 1548428];
    if (!v2)
        return 0;
    v4 = *(_DWORD*)& byte_5D4594[4 * v1 + 1548452];
    if (v4 > v2)
    {
        *(_DWORD*)& byte_5D4594[4 * v1 + 1548452] = 0;
        v4 = 0;
    }
    *(_DWORD*)& byte_5D4594[4 * v1 + 1548452] = (*(_DWORD*)& byte_5D4594[4 * v1 + 1548452] + 1) % v2;
    return (char*)& byte_5D4594[128 * (v4 + 20 * v1 + 5 * v1) + 1529228];
}

//----- (004D0D50) --------------------------------------------------------
int __cdecl sub_4D0D50(int a1)
{
    int result; // eax
    unsigned __int8* v2; // ecx

    result = 0;
    v2 = &byte_587000[191836];
    while (!(a1 & *(_DWORD*)v2))
    {
        v2 += 8;
        ++result;
        if ((int)v2 >= (int)& byte_587000[191884])
            return 0;
    }
    return result;
}

//----- (004D0D70) --------------------------------------------------------
BOOL sub_4D0D70()
{
    return *(_DWORD*)& byte_5D4594[1548484] || *(_DWORD*)& byte_5D4594[2650636] & 0x40000;
}

//----- (004D0D90) --------------------------------------------------------
int __cdecl sub_4D0D90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1548484] = a1;
    return result;
}

//----- (004D0DA0) --------------------------------------------------------
void sub_4D0DA0()
{
    memset(&byte_5D4594[1548452], 0, 0x18u);
    memset(&byte_5D4594[1548428], 0, 0x18u);
}

//----- (004D0DC0) --------------------------------------------------------
int __cdecl sub_4D0DC0(int a1, int a2)
{
    int result; // eax

    result = sub_4D0D50(a1);
    *(_DWORD*)& byte_5D4594[4 * result + 1548452] = a2;
    return result;
}

//----- (004D0DE0) --------------------------------------------------------
int __cdecl sub_4D0DE0(int a1)
{
    return *(_DWORD*)& byte_5D4594[4 * sub_4D0D50(a1) + 1548452];
}

//----- (004D0E00) --------------------------------------------------------
int sub_4D0E00()
{
    int* i; // ebp
    int v3; // edx
    unsigned __int8 v4; // al
    unsigned __int8* v5; // edi
    int v6; // eax
    int result; // eax
    int v8; // ecx
    int v9; // ebp
    unsigned __int8* v10; // ebx
    int v11; // edi
    int v12; // esi
    int v13; // [esp+10h] [ebp-4h]

    nox_srand_time();
    *(_DWORD*)& byte_5D4594[1548476] = 0;
    for (i = sub_4D09B0(); i; i = sub_4D09C0(i))
    {
        if (i[6])
        {
            if (sub_4CFFC0((int)i) & 0x1000)
            {
                if (*(int*)& byte_5D4594[1548476] < 128)
                {
                    v3 = 32 * *(_DWORD*)& byte_5D4594[1548476];
                    strcpy((char*)& byte_5D4594[32 * *(_DWORD*)& byte_5D4594[1548476] + 1525136], (const char*)i + 12);
                    v4 = byte_587000[192004];
                    v5 = &byte_5D4594[v3 + 1525136 + strlen((const char*)& byte_5D4594[v3 + 1525136])];
                    *(_DWORD*)v5 = *(_DWORD*)& byte_587000[192000];
                    v5[4] = v4;
                    v6 = *(_DWORD*)& byte_5D4594[1548476] + 1;
                    *(_DWORD*)& byte_5D4594[v3 + 1525132] = 0;
                    *(_DWORD*)& byte_5D4594[1548476] = v6;
                }
            }
        }
    }
    result = *(_DWORD*)& byte_5D4594[1548476];
    v8 = 1;
    if (*(_DWORD*)& byte_5D4594[1548476] > 0)
    {
        v9 = 1;
        v10 = &byte_5D4594[1525132];
        do
        {
            if (!*(_DWORD*)v10)
            {
                *(_DWORD*)v10 = v8++;
                v13 = v8;
                v11 = v9;
                if (v9 < result)
                {
                    v12 = (int)(v10 + 32);
                    do
                    {
                        if (!_strnicmp((const char*)v10 + 4, (const char*)(v12 + 4), 6u))
                            * (_DWORD*)v12 = *(_DWORD*)v10;
                        result = *(_DWORD*)& byte_5D4594[1548476];
                        ++v11;
                        v12 += 32;
                    } while (v11 < *(int*)& byte_5D4594[1548476]);
                    v8 = v13;
                }
            }
            ++v9;
            v10 += 32;
        } while (v9 - 1 < result);
    }
    return result;
}
// 4D0E3E: variable 'v2' is possibly undefined

//----- (004D0F30) --------------------------------------------------------
void sub_4D0F30()
{
    int v0; // ecx
    unsigned __int8* v1; // eax

    v0 = *(_DWORD*)& byte_5D4594[1548476];
    *(_DWORD*)& byte_5D4594[1548480] = 1000;
    if (*(_DWORD*)& byte_5D4594[1548476] > 0)
    {
        v1 = &byte_5D4594[1525160];
        do
        {
            *((_DWORD*)v1 - 1) = 0;
            *(_DWORD*)v1 = 0;
            v1 += 32;
            --v0;
        } while (v0);
    }
}

//----- (004D0F60) --------------------------------------------------------
char* sub_4D0F60()
{
    int v1; // esi
    unsigned __int8* v2; // ecx
    int v3; // edx
    int v4; // ebx
    unsigned __int8* v5; // esi
    int v6; // ebp
    unsigned __int8* v7; // eax
    int v8; // ecx
    int v9; // edx
    int v10; // ecx
    unsigned __int8* v11; // eax
    int v12; // eax
    int v13; // edi
    int v14; // edx
    unsigned __int8* i; // ecx
    int v16; // [esp+4h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1548476])
        return 0;
    if (*(_DWORD*)& byte_5D4594[1548476] == 1)
        return (char*)& byte_5D4594[1525136];
    v1 = 0;
    v16 = 0;
    if (*(int*)& byte_5D4594[1548476] <= 0)
        return (char*)& byte_5D4594[32 * sub_415FA0(0, *(_DWORD*)& byte_5D4594[1548476] - 1) + 1525136];
    v2 = &byte_5D4594[1525156];
    v3 = *(_DWORD*)& byte_5D4594[1548476];
    do
    {
        if (*(_DWORD*)v2 > v1)
        {
            v16 = *(_DWORD*)v2;
            v1 = *(_DWORD*)v2;
        }
        v2 += 32;
        --v3;
    } while (v3);
    if (!v1)
        return (char*)& byte_5D4594[32 * sub_415FA0(0, *(_DWORD*)& byte_5D4594[1548476] - 1) + 1525136];
    v4 = 1;
    v5 = &byte_5D4594[1525156];
    v6 = *(_DWORD*)& byte_5D4594[1548476];
    do
    {
        if (*(_DWORD*)& byte_5D4594[1548476] > 1)
        {
            v7 = &byte_5D4594[1525188];
            v8 = *(_DWORD*)& byte_5D4594[1548476] - 1;
            do
            {
                if (*(_DWORD*)v5 != *(_DWORD*)v7)
                    v4 = 0;
                v7 += 32;
                --v8;
            } while (v8);
        }
        v5 += 32;
        --v6;
    } while (v6);
    if (v4 == 1)
        ++v16;
    v9 = 0;
    v10 = 0;
    v11 = &byte_5D4594[1525132];
    do
    {
        if (*((_DWORD*)v11 + 6) < v16
            && v10 != *(_DWORD*)& byte_587000[191880]
            && *(_DWORD*)v11 != *(_DWORD*)& byte_5D4594[32 * *(_DWORD*)& byte_587000[191880] + 1525132]
            && *(_DWORD*)& byte_5D4594[1548480] - *((_DWORD*)v11 + 7) > 4)
        {
            ++v9;
        }
        ++v10;
        v11 += 32;
    } while (v10 < *(int*)& byte_5D4594[1548476]);
    v12 = sub_415FA0(0, v9 - 1);
    v13 = 0;
    v14 = 0;
    if (*(int*)& byte_5D4594[1548476] <= 0)
        return (char*)& byte_5D4594[32 * v12 + 1525136];
    for (i = &byte_5D4594[1525132]; ; i += 32)
    {
        if (*((_DWORD*)i + 6) >= v16
            || v14 == *(_DWORD*)& byte_587000[191880]
            || *(_DWORD*)i == *(_DWORD*)& byte_5D4594[32 * *(_DWORD*)& byte_587000[191880] + 1525132]
            || *(_DWORD*)& byte_5D4594[1548480] - *((_DWORD*)i + 7) <= 4)
        {
            goto LABEL_36;
        }
        if (v13 == v12)
            break;
        ++v13;
        LABEL_36:
        if (++v14 >= *(int*)& byte_5D4594[1548476])
            return (char*)& byte_5D4594[32 * v12 + 1525136];
    }
    return (char*)& byte_5D4594[32 * v14 + 1525136];
}

//----- (004D10F0) --------------------------------------------------------
void __cdecl sub_4D10F0(char* a1)
{
    int v1; // esi
    const char* i; // edi
    int v3; // edi
    int v4; // eax
    int v5; // ebx
    int v6; // edx
    unsigned __int8* v7; // ecx

    if (a1)
    {
        v1 = 0;
        if (*(_DWORD*)& byte_5D4594[1548476] > 0)
        {
            for (i = (const char*)& byte_5D4594[1525136]; _strcmpi(i, a1); i += 32)
            {
                if (++v1 >= *(int*)& byte_5D4594[1548476])
                    return;
            }
            v3 = *(_DWORD*)& byte_5D4594[1548476];
            v4 = 32 * v1;
            v5 = *(_DWORD*)& byte_5D4594[1548480];
            *(_DWORD*)& byte_587000[191880] = v1;
            *(_DWORD*)& byte_5D4594[v4 + 1525156] = *(_DWORD*)& byte_5D4594[32 * v1 + 1525156] + 1;
            v6 = 0;
            *(_DWORD*)& byte_5D4594[v4 + 1525160] = v5;
            if (v3 > 0)
            {
                v7 = &byte_5D4594[1525156];
                do
                {
                    if (*((_DWORD*)v7 - 6) == *(_DWORD*)& byte_5D4594[32 * v1 + 1525132] && v1 != v6)
                    {
                        ++* (_DWORD*)v7;
                        *((_DWORD*)v7 + 1) = v5;
                    }
                    ++v6;
                    v7 += 32;
                } while (v6 < v3);
            }
            *(_DWORD*)& byte_5D4594[1548480] = v5 + 1;
        }
    }
}

//----- (004D11A0) --------------------------------------------------------
_DWORD* sub_4D11A0()
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1548504];
    if (!*(_DWORD*)& byte_5D4594[1548504])
    {
        result = sub_425760(&byte_5D4594[1548492]);
        *(_DWORD*)& byte_5D4594[1548504] = 1;
    }
    return result;
}

//----- (004D11D0) --------------------------------------------------------
void sub_4D11D0()
{
    int* result; // eax
    int* v1; // esi
    int* v2; // edi

    result = sub_425890((int*)& byte_5D4594[1548492]);
    v1 = result;
    if (result)
    {
        do
        {
            v2 = sub_4258A0(v1);
            sub_425920((_DWORD * *)v1);
            free(v1);
            v1 = v2;
        } while (v2);
    }
}

//----- (004D1210) --------------------------------------------------------
void* __cdecl sub_4D1210(int a1)
{
    void* result; // eax
    void* v2; // esi
    _DWORD* v3; // eax

    result = (void*)sub_4D12A0(a1);
    if (!result)
    {
        result = sub_417090(a1);
        v2 = result;
        if (result)
        {
            v3 = nox_malloc(0x10u);
            v3[3] = v2;
            result = sub_4258E0((int)& byte_5D4594[1548492], v3);
        }
    }
    return result;
}

//----- (004D1250) --------------------------------------------------------
int* __cdecl sub_4D1250(int a1)
{
    int* result; // eax
    int* v2; // esi

    result = sub_425890((int*)& byte_5D4594[1548492]);
    v2 = result;
    if (result)
    {
        while (*(unsigned __int8*)(v2[3] + 2064) != a1)
        {
            result = sub_4258A0(v2);
            v2 = result;
            if (!result)
                return result;
        }
        sub_425920((_DWORD * *)v2);
        free(v2);
    }
    return result;
}

//----- (004D12A0) --------------------------------------------------------
int __cdecl sub_4D12A0(int a1)
{
    int* v1; // eax

    v1 = sub_425890((int*)& byte_5D4594[1548492]);
    if (!v1)
        return 0;
    while (*(unsigned __int8*)(v1[3] + 2064) != a1)
    {
        v1 = sub_4258A0(v1);
        if (!v1)
            return 0;
    }
    return 1;
}

//----- (004D12E0) --------------------------------------------------------
void __cdecl sub_4D12E0(int a1)
{
    int v1; // edi
    int v2; // esi
    int v3; // edi
    _DWORD* v4; // eax
    int v5; // esi
    _DWORD* v6; // eax
    int i; // esi
    int j; // edi
    int k; // esi
    int v11[3]; // [esp+0h] [ebp-Ch]

    v11[0] = 25;
    v11[1] = 25;
    v11[2] = 25;
    sub_40A4D0(0x80000);
    sub_516F30();
    sub_421B10();
    sub_469B90(v11);
    if (sub_40A5C0(2))
        sub_4349C0(v11);
    sub_511E60();
    if (sub_40A5C0(2048))
    {
        v1 = a1;
        sub_4FCEB0(a1);
    }
    else
    {
        sub_4FCEB0(0);
        v1 = a1;
    }
    sub_4FF790();
    v2 = sub_4DA7C0();
    if (v2)
    {
        do
        {
            v3 = *(_DWORD*)(v2 + 748);
            sub_4F7950(v2);
            *(_DWORD*)(v3 + 296) = 0;
            sub_4E7A60(v2, 1);
            v4 = *(_DWORD * *)(v3 + 280);
            *(_WORD*)(v3 + 160) = 0;
            if (v4)
                sub_510DC0(v4);
            *(_DWORD*)(v3 + 280) = 0;
            if (*(int(__cdecl * *)(_DWORD*))(v2 + 744) == sub_4FAB20)
                sub_4FA700(v2);
            v2 = sub_4DA7F0(v2);
        } while (v2);
        v1 = a1;
    }
    do
    {
        sub_4DAC00();
        sub_4E5BF0(v1);
        sub_4FEEF0();
        sub_4E5EC0();
    } while (sub_4DA870());
    v5 = sub_4DA790();
    if (v5)
    {
        do
        {
            *(_DWORD*)(v5 + 520) = 0;
            if (sub_4E5B50(v5) && *(_BYTE*)(v5 + 8) & 2)
            {
                v6 = *(_DWORD * *)(v5 + 748);
                v6[309] = -1;
                v6[307] = -1;
                v6[317] = -1;
                v6[311] = -1;
                v6[313] = -1;
                v6[315] = -1;
                v6[319] = -1;
                v6[321] = -1;
                v6[323] = -1;
                v6[325] = -1;
                v6[98] = 0;
                v6[101] = 0;
            }
            v5 = sub_4DA7A0(v5);
        } while (v5);
        v1 = a1;
    }
    sub_50D1C0();
    for (i = sub_4DA840(); i; i = sub_4DA850(i))
    {
        if (sub_4E5B80(i))
            sub_4E81D0(i);
    }
    sub_4ECFE0();
    sub_511E20();
    sub_410160();
    if (v1)
        sub_4FCAC0(v1, 1);
    else
        sub_4FCAC0(0, 0);
    for (j = 0; j < 5632; j += 44)
    {
        for (k = 0; k < 512; k += 4)
        {
            *(_BYTE*)(*(_DWORD*)(k + *(_DWORD*)& byte_5D4594[2650668]) + j) = 0;
            *(_DWORD*)(*(_DWORD*)(k + *(_DWORD*)& byte_5D4594[2650668]) + j + 4) = 255;
            *(_DWORD*)(*(_DWORD*)(k + *(_DWORD*)& byte_5D4594[2650668]) + j + 24) = 255;
            sub_422200(*(_DWORD*)(k + *(_DWORD*)& byte_5D4594[2650668]) + j + 4);
            sub_422200(*(_DWORD*)(k + *(_DWORD*)& byte_5D4594[2650668]) + j + 24);
        }
    }
    sub_410730();
    sub_410810();
    sub_579DD0();
    sub_511840();
    sub_5117B0();
    sub_5112F0();
    sub_57C440();
    sub_57C000();
    sub_510E50();
    sub_4D1610();
    sub_4EC5B0();
    sub_50E360();
    sub_50D7E0();
    sub_4E4F80();
    sub_40A540(0x80000);
}
// 511840: using guessed type int sub_511840(void);

//----- (004D15B0) --------------------------------------------------------
void sub_4D15B0()
{
    *(_DWORD*)& byte_5D4594[1548508] = 1;
}

//----- (004D15C0) --------------------------------------------------------
void sub_4D15C0()
{
    *(_DWORD*)& byte_5D4594[1548508] = 0;
}

//----- (004D15D0) --------------------------------------------------------
int sub_4D15D0()
{
    return *(_DWORD*)& byte_5D4594[1548508];
}

//----- (004D15E0) --------------------------------------------------------
void sub_4D15E0()
{
    nox_srand(0x141Eu);
}

//----- (004D15F0) --------------------------------------------------------
void sub_4D15F0()
{
    *(_DWORD*)& byte_5D4594[1548520] = 1;
}

//----- (004D1600) --------------------------------------------------------
int sub_4D1600()
{
    return *(_DWORD*)& byte_5D4594[1548528];
}

//----- (004D1610) --------------------------------------------------------
void sub_4D1610()
{
    *(_DWORD*)& byte_5D4594[1548528] = 0;
}

//----- (004D1620) --------------------------------------------------------
int sub_4D1620()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1548532])
        result = *(_DWORD*)& byte_5D4594[1548532] + 56;
    else
        result = 0;
    return result;
}

//----- (004D1630) --------------------------------------------------------
int sub_4D1630()
{
    int result; // eax

    result = sub_419B30();
    if (result)
    {
        sub_424DF0();
        sub_57B200();
        result = sub_517010() != 0;
    }
    return result;
}

//----- (004D1650) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
_DWORD* sub_4D1650()
{
    sub_419DB0();
    return sub_5174F0();
}

//----- (004D1660) --------------------------------------------------------
int sub_4D1660()
{
    int result; // eax
    int v1; // eax

    sub_4D15C0();
    *(_DWORD*)& byte_5D4594[2649712] = 2147483648;
    *(_DWORD*)& byte_5D4594[3843628] = 0;
    sub_4D7B40();
    sub_41E4B0(0);
    sub_4E3C70();
    sub_56F1C0();
    sub_416E30();
    sub_40EE60();
    sub_4E4EF0();
    sub_4E4ED0();
    result = sub_501860();
    if (result)
    {
        result = sub_4E2B60((char*)& byte_587000[196440]);
        if (result)
        {
            sub_4463E0(1);
            sub_417C60();
            sub_4259C0();
            sub_4D7C60();
            sub_4E3320();
            result = sub_518770();
            if (result)
            {
                sub_40A5C0(0x200000);
                result = sub_4E3360(0x1388u);
                if (result)
                {
                    result = sub_517AE0();
                    if (result)
                    {
                        result = sub_50AB90();
                        if (result)
                        {
                            result = sub_4FC9B0();
                            if (result)
                            {
                                result = sub_5112C0();
                                if (result)
                                {
                                    result = sub_57C410();
                                    if (result)
                                    {
                                        result = sub_57BFB0();
                                        if (result)
                                        {
                                            result = sub_4ECA60();
                                            if (result)
                                            {
                                                result = sub_50E2A0();
                                                if (result)
                                                {
                                                    result = sub_50D780();
                                                    if (result)
                                                    {
                                                        result = sub_5066D0();
                                                        if (result)
                                                        {
                                                            result = sub_4FF730();
                                                            if (result)
                                                            {
                                                                result = sub_517520();
                                                                if (result)
                                                                {
                                                                    sub_416920();
                                                                    if (!sub_40A5C0(2048))
                                                                    {
                                                                        v1 = sub_40A430();
                                                                        *(_DWORD*)& byte_5D4594[1548516] = sub_4DEBC0(v1);
                                                                        if (!sub_40A5C0(0x2000000))
                                                                            sub_413CC0();
                                                                    }
                                                                    sub_4FB990();
                                                                    result = sub_516EE0();
                                                                    if (result)
                                                                    {
                                                                        sub_421B10();
                                                                        sub_4DB0A0();
                                                                        sub_4D0F30();
                                                                        result = 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (004D17F0) --------------------------------------------------------
int sub_4D17F0()
{
    int result; // eax

    sub_4E79B0(0);
    if (!memcmp(sub_409B30(), &byte_5D4594[1548720], 1u))
        sub_409D70((char*)& byte_587000[196452]);
    sub_519870();
    result = sub_4D1860();
    if (result)
    {
        sub_43DDF0(sub_4D2580);
        sub_40EE90(1);
        sub_40A4D0(0x20000);
        sub_4DEF00();
        sub_40A690();
        result = 1;
    }
    return result;
}

//----- (004D1860) --------------------------------------------------------
int sub_4D1860()
{
    int v0; // esi
    int v1; // edi
    char* v2; // eax
    int i; // eax
    int j; // eax
    char* v5; // eax
    int v6; // esi
    char* v7; // ebx
    int* v8; // eax
    int* v9; // eax
    char* v10; // eax
    int v11; // eax
    __int16 v12; // ax
    int v13; // eax
    int* v14; // eax
    int k; // esi
    char* v17; // eax
    int v18; // eax
    int v19; // esi
    int v20; // edi
    int v21; // ebx
    int v22; // eax
    int v23; // ecx
    wchar_t* v24; // eax
    int l; // ebx
    char* v27; // eax
    int v28; // eax
    int v29; // esi
    char* v30; // eax
    int v31; // eax
    int v32; // eax
    char* v33; // eax
    int v34; // eax
    int v35; // eax
    float* v36; // esi
    char* v37; // eax
    double v38; // st7
    char* v39; // eax
    double v40; // st7
    char* v41; // eax
    int v42; // eax
    const char* v43; // edi
    int v44; // esi
    float2* v45; // edi
    int m; // ebx
    int n; // esi
    int v48; // edi
    int* v49; // eax
    int ii; // eax
    int jj; // eax
    int v52; // eax
    int v53; // eax
    int v54; // eax
    char* v55; // eax
    unsigned int v56; // esi
    char v57; // al
    int* v58; // [esp-1Ch] [ebp-68h]
    __int16 v59; // [esp-14h] [ebp-60h]
    __int16 v60; // [esp-14h] [ebp-60h]
    float2 v61; // [esp+0h] [ebp-4Ch]
    __int64 v62; // [esp+8h] [ebp-44h]
    int v63[15]; // [esp+10h] [ebp-3Ch]

    if (sub_40A5C0(2))
        sub_477610(10);
    sub_4D22B0();
    sub_4D9800(0, 1);
    v0 = 0;
    if (*(_DWORD*)& byte_5D4594[1599640] > 0)
    {
        v1 = 0;
        do
        {
            if (!strncmp("MapExit", *(const char**)(v1 + *(_DWORD*)& byte_5D4594[1599636]), 7u))
                sub_507310(v0, 0, 0);
            ++v0;
            v1 += 48;
        } while (v0 < *(int*)& byte_5D4594[1599640]);
    }
    v2 = sub_409B40();
    sub_500510(v2);
    sub_4D12E0(1);
    for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
        * (_DWORD*)(i + 16) |= 0x80000000;
    for (j = sub_4DA840(); j; j = sub_4DA850(j))
        * (_DWORD*)(j + 16) |= 0x80000000;
    if (sub_40A5C0(2048))
    {
        sub_424BD0();
        sub_4537F0();
    }
    if (sub_4DB240())
    {
        v5 = sub_4DB260();
        v6 = sub_4CF5F0(v5, 0);
    }
    else
    {
        v7 = sub_4165B0();
        if (sub_40A5C0(0x2000))
        {
            if (!v7[57])
            {
                strcpy((char*)v63, v7);
                v59 = *((_WORD*)v7 + 26);
                v8 = (int*)sub_459870();
                sub_57A1E0(v63, "user.rul", v8, 3, v59);
                v9 = (int*)sub_459870();
                sub_57AAA0("user.rul", v7, v9);
            }
            sub_424BD0();
            sub_4537F0();
        }
        v10 = sub_409B30();
        v6 = sub_4CF5F0(v10, 0);
        if (sub_40A5C0(0x2000) && !sub_40A5C0(128))
        {
            v11 = sub_40A8A0();
            v13 = 0;
            if (v11)
            {
                v12 = sub_40A5B0();
                if (sub_40A180(v12))
                    v13 = 1;
            }
            sub_40A1F0(v13);
            sub_40A250();
            v60 = sub_40A5B0();
            v58 = (int*)sub_459870();
            v14 = (int*)sub_416590(0);
            sub_57A1E0(v14, "user.rul", v58, 3, v60);
            sub_4D2230();
        }
    }
    if (!v6)
    {
        sub_4D15F0();
        return 0;
    }
    if (!sub_40A5C0(2048))
        sub_519EB0();
    sub_4DAC00();
    for (k = sub_4DA7C0(); k; k = sub_4DA7F0(k))
    {
        sub_4EF660(k);
        sub_4F7AB0(&v61, k);
        if (sub_40A5C0(128))
        {
            if (sub_417DD0())
            {
                if (!sub_417DA0(2) && !sub_40A5C0(0x8000))
                {
                    v17 = sub_418AB0(*(unsigned __int8*)(k + 52));
                    if (v17)
                        sub_4ED970(50.0, (float2*)(*((_DWORD*)v17 + 18) + 56), &v61);
                }
            }
        }
        sub_4E7010(k, &v61);
        if (!sub_40A5C0(512))
        {
            v18 = *(_DWORD*)(k + 748);
            *(_DWORD*)(*(_DWORD*)(v18 + 276) + 2136) = 0;
            *(_DWORD*)(*(_DWORD*)(v18 + 276) + 2140) = 0;
            *(_DWORD*)(*(_DWORD*)(v18 + 276) + 2144) = *(_DWORD*)& byte_5D4594[2598000];
            sub_4D8EF0(k);
        }
    }
    sub_50AFA0();
    sub_50B520();
    v19 = 0;
    v20 = 0;
    v21 = 0;
    *(_DWORD*)& byte_5D4594[1548528] = 0;
    *(_DWORD*)& byte_5D4594[1548532] = 0;
    if (!*(_DWORD*)& byte_5D4594[1548708])
        * (_DWORD*)& byte_5D4594[1548708] = sub_4E3AA0((CHAR*)& byte_587000[196512]);
    if (!*(_DWORD*)& byte_5D4594[1548712])
        * (_DWORD*)& byte_5D4594[1548712] = sub_4E3AA0((CHAR*)& byte_587000[196524]);
    v22 = sub_4DA790();
    if (!v22)
        goto LABEL_120;
    do
    {
        if (*(_DWORD*)(v22 + 8) & 0x10000000)
        {
            *(_DWORD*)(v22 + 136) = 0;
            *(_DWORD*)& byte_5D4594[1548532] = v22;
            ++v19;
        }
        v23 = *(unsigned __int16*)(v22 + 4);
        if ((unsigned __int16)v23 == *(_DWORD*)& byte_5D4594[1548712])
            ++v21;
        if (v23 == *(_DWORD*)& byte_5D4594[1548708])
            ++v20;
        v22 = sub_4DA7A0(v22);
    } while (v22);
    if (!v20)
    {
        LABEL_120:
        v24 = loadString_sub_40F1D0((char*)& byte_587000[196580], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 792);
        LABEL_61:
        sub_4D9FD0(0, v24);
        return 0;
    }
    if (sub_40A5C0(96) && v19 < 2)
    {
        v24 = loadString_sub_40F1D0((char*)& byte_587000[196644], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 799);
        goto LABEL_61;
    }
    if (sub_40A5C0(64) && v21 < 1)
    {
        v24 = loadString_sub_40F1D0((char*)& byte_587000[196700], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 806);
        goto LABEL_61;
    }
    if (sub_417DA0(4) || sub_40A5C0(0x8000))
        sub_417D00();
    for (l = sub_57C3E0(); l; l = sub_57C3F0(l))
    {
        if (!strcmp((const char*)l, "spring"))
        {
            v27 = strtok((char*)(l + 80), " ");
            v28 = atoi(v27);
            v29 = sub_4ED020(v28);
            v30 = strtok(0, " ");
            v31 = atoi(v30);
            v32 = sub_4ED020(v31);
            if (v29 && v32)
                sub_511590(v29, v32);
        }
        else if (!strcmp((const char*)l, "SentryGlobe"))
        {
            v33 = strtok((char*)(l + 80), " ");
            v34 = atoi(v33);
            v35 = sub_4ED020(v34);
            if (v35)
            {
                v36 = *(float**)(v35 + 748);
                v37 = strtok(0, " ");
                v38 = atof(v37) * *(double*)& byte_581450[10008];
                v36[1] = v38;
                *v36 = v38;
                v39 = strtok(0, " ");
                v40 = atof(v39);
                v62 = *(unsigned int*)& byte_5D4594[2649704];
                v36[2] = v40 * *(double*)& byte_581450[10000] / (double) * (unsigned int*)& byte_5D4594[2649704];
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1548524] = 0;
    v41 = sub_409B40();
    sub_500510(v41);
    if (!sub_4DB240())
        sub_4FC570(1);
    sub_40A4D0(0x8000000);
    sub_43F140(500);
    v42 = sub_4DB240();
    sub_4DBA30(v42);
    sub_43F1A0();
    sub_40A540(0x8000000);
    sub_4FC580(1);
    if (*(_DWORD*)& byte_5D4594[1548664])
    {
        v43 = sub_579E30((const char*)& byte_5D4594[1548536]);
        if (v43)
        {
            v44 = sub_4DA7C0();
            if (v44)
            {
                v45 = (float2*)(v43 + 8);
                do
                {
                    sub_4E7010(v44, v45);
                    v44 = sub_4DA7F0(v44);
                } while (v44);
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1548664] = 0;
    if (sub_4DCC00() == 1)
    {
        for (m = sub_4DA7C0(); m; m = sub_4DA7F0(m))
        {
            for (n = *(_DWORD*)(m + 516); n; n = *(_DWORD*)(n + 512))
            {
                if (sub_4E5B50(n))
                {
                    v48 = *(_DWORD*)(n + 748);
                    sub_4ED970(50.0, (float2*)(m + 56), &v61);
                    sub_4E7010(n, &v61);
                    *(_DWORD*)(v48 + 388) = 0;
                    sub_50A3A0(n);
                    *(_DWORD*)(n + 520) = 0;
                    *(_DWORD*)(v48 + 1196) = 0;
                    *(_DWORD*)(v48 + 1216) = 0;
                    *(_BYTE*)(v48 + 1129) = 0;
                    *(_DWORD*)v48 = -559023410;
                    v49 = sub_50A260(n, 3);
                    if (v49)
                    {
                        v49[1] = *(_DWORD*)(m + 56);
                        v49[2] = *(_DWORD*)(m + 60);
                        v49[3] = m;
                    }
                    if (*(_BYTE*)(n + 8) & 2 && *(_BYTE*)(n + 12) & 0x30)
                        sub_4E4A90(n, 0, *(_DWORD*)(n + 748) + 2076);
                }
                else if (*(_BYTE*)(m + 8) & 1 && sub_4E5B80(m))
                {
                    sub_4E81D0(m);
                }
            }
        }
        sub_4DCBF0(0);
    }
    for (ii = sub_4DA790(); ii; ii = sub_4DA7A0(ii))
        * (_DWORD*)(ii + 16) &= 0x7FFFFFFFu;
    for (jj = sub_4DA840(); jj; jj = sub_4DA850(jj))
        * (_DWORD*)(jj + 16) &= 0x7FFFFFFFu;
    if (sub_40A5C0(16) && sub_417DA0(4))
        sub_4D2160();
    if (sub_40A5C0(4096))
    {
        sub_51A930();
        v52 = sub_415FA0(0, 2);
        sub_51A920(v52);
        v53 = sub_4E3CC0();
        sub_4E3CD0(v53 + 1);
        v54 = sub_51A930();
        sub_51A1F0(v54);
        sub_4E3D50();
        sub_4E3DD0();
        sub_4F1F20();
        v55 = sub_409B30();
        sub_4D10F0(v55);
        sub_4D7520(1);
        v56 = (__int64)sub_419D40(&byte_587000[196800]);
        if (sub_4E3CC0() >= v56)
            sub_4D7520(0);
    }
    if (sub_40A5C0(2048) && !sub_4DCC80())
    {
        sub_4DB130("AUTOSAVE");
        sub_4DB170(1, 0, 30);
    }
    sub_4DCC70(0);
    if (sub_40A5C0(2048))
        sub_413980(30);
    if (sub_40A5C0(4096))
        sub_4D7140(*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)& byte_5D4594[2649704]);
    else
        sub_4D7140(0);
    sub_416D40();
    sub_40A970();
    *(_DWORD*)& byte_5D4594[1548704] = 0;
    if (sub_40A5C0(4096))
    {
        sub_4D71E0(0);
        if (sub_4D72C0() == 1)
        {
            sub_4D72B0(0);
            v57 = sub_4D72C0();
            sub_4D7280(255, v57);
        }
    }
    sub_413850();
    return 1;
}
// 4D1A17: variable 'v11' is possibly undefined
// 4D1CBA: variable 'v25' is possibly undefined

//----- (004D2160) --------------------------------------------------------
char* sub_4D2160()
{
    char* result; // eax
    char* i; // ebp
    int v2; // edi
    char* j; // esi
    int v4; // eax
    int v5; // [esp+4h] [ebp-4h]

    v5 = sub_416F40();
    result = sub_418B10();
    for (i = result; result; i = result)
    {
        if (!*(_DWORD*)(*((_DWORD*)i + 19) + 492) && sub_418BC0((int)i))
        {
            do
            {
                v2 = sub_415FA0(0, v5 - 1);
                for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
                {
                    if (!v2)
                        break;
                    --v2;
                }
                v4 = *((_DWORD*)j + 514);
            } while (!v4 || !sub_419180(v4 + 48, i[57]));
            sub_4F3400(*((_DWORD*)j + 514), *((_DWORD*)i + 19), 1);
        }
        result = sub_418B60((int)i);
    }
    return result;
}

//----- (004D2230) --------------------------------------------------------
void sub_4D2230()
{
    __int16 v0; // ax
    __int16 v1; // ax
    __int16 v2; // ax

    if (sub_40A5C0(49152))
    {
        v0 = sub_40A5B0();
        if (!sub_40A020(v0))
        {
            v1 = sub_40A5B0();
            if (!sub_40A180(v1))
            {
                v2 = sub_40A5B0();
                sub_409FB0(v2, 0xFu);
            }
        }
    }
    else if (sub_40A5C0(1024) && !sub_40A020(1024))
    {
        sub_409FB0(1024, 0xFu);
    }
}

//----- (004D22B0) --------------------------------------------------------
char* sub_4D22B0()
{
    char* result; // eax
    int i; // esi
    int v2; // eax
    int v3; // edi
    int v4; // ecx
    int v5; // eax
    int v6; // [esp-8h] [ebp-10h]

    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        v2 = *(_DWORD*)(i + 2056);
        if (v2)
        {
            v3 = *(_DWORD*)(v2 + 748);
            if (*(_DWORD*)(v3 + 280))
                sub_510DC0(*(_DWORD * *)(v3 + 280));
            *(_DWORD*)(v3 + 280) = 0;
            sub_51AC30(*(unsigned __int8*)(i + 2064));
            if (sub_40A5C0(4096))
            {
                v4 = *(_DWORD*)(i + 4676);
                *(_DWORD*)(i + 4676) = 0;
                *(_DWORD*)(i + 4680) = v4;
            }
            if (!sub_4FA020(*(_DWORD * *)(i + 2056), 13) || !sub_40A5C0(512))
            {
                *(_DWORD*)(i + 4700) = 0;
                v6 = ((unsigned int)sub_4CFE00() >> 1) & 1;
                v5 = sub_4DB240();
                sub_4EF7D0(*(_DWORD*)(i + 2056), v5 == 0, v6);
            }
            if (*(_BYTE*)(i + 3680) & 0x20)
            {
                sub_4E6AA0(i);
                sub_4E6040(*(_DWORD*)(i + 2056));
            }
            *(_DWORD*)(*(_DWORD*)(i + 2056) + 136) = *(_DWORD*)& byte_5D4594[2598000];
        }
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004D23C0) --------------------------------------------------------
int sub_4D23C0()
{
    char* i; // esi
    int v2; // [esp-Ch] [ebp-14h]

    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        if (*((_DWORD*)i + 514))
        {
            *(_DWORD*)& byte_5D4594[2649712] &= ~(1 << i[2064]);
            v2 = *((_DWORD*)i + 514);
            i[3676] = 2;
            sub_4EF7D0(v2, 1, 0);
            *((_DWORD*)i + 535) = 0;
            *((_DWORD*)i + 534) = 0;
        }
    }
    sub_51A100();
    sub_40A540(0x20000);
    sub_4DEF00();
    sub_40A690();
    return 1;
}

//----- (004D2450) --------------------------------------------------------
char* __cdecl sub_4D2450(char* a1)
{
    char* v1; // eax
    char v3[1024]; // [esp+4h] [ebp-DB8h]
    char v4[1024]; // [esp+404h] [ebp-9B8h]
    char v5[1464]; // [esp+804h] [ebp-5B8h]

    qmemcpy(v5, &byte_5D4594[3801836], sizeof(v5));
    strncpy(v4, a1, strlen(a1) - 4);
    v4[strlen(a1) - 4] = 0;
    sub_4CFE10(v4);
    sub_4CFDF0(*(int*)& byte_5D4594[3803228]);
    qmemcpy(&byte_5D4594[3801836], v5, 0x5B8u);
    *(_DWORD*)& byte_5D4594[1548524] = 1;
    strcpy(v3, a1);
    v1 = strchr(v3, 58);
    if (v1)
    {
        *v1 = 0;
        strcpy((char*)& byte_5D4594[1548536], v1 + 1);
        *(_DWORD*)& byte_5D4594[1548664] = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1548664] = 0;
    }
    if (sub_51A130())
        sub_5198B0(0);
    return sub_409D70(v3);
}

//----- (004D2580) --------------------------------------------------------
int sub_4D2580()
{
    __int64 v0; // rax
    unsigned int v1; // edi
    int v2; // ebx
    unsigned int v3; // ebp
    unsigned int v4; // esi
    _DWORD* i; // esi
    char* v7; // ebp
    char* v8; // edi
    unsigned __int8 v9; // dl
    char* v10; // edi
    char* v11; // esi
    char* v12; // eax
    int v13; // esi
    wchar_t* v14; // eax
    wchar_t* v15; // eax
    char* v17; // eax
    int v18; // eax
    char* v20; // eax
    char* v21; // esi
    int v22; // ebx
    int v23; // ebp
    int v24; // edi
    int v25; // esi
    unsigned __int8* v26; // eax
    wchar_t* v27; // eax
    int v28; // eax
    int v29; // esi
    char* v30; // ebp
    const char* v31; // edi
    char* v33; // eax
    int v34; // eax
    wchar_t* v35; // [esp-10h] [ebp-50h]
    wchar_t* v36; // [esp-8h] [ebp-48h]
    char* v37; // [esp-4h] [ebp-44h]
    char v38[16]; // [esp+10h] [ebp-30h]
    char v39[32]; // [esp+20h] [ebp-20h]

    v0 = sub_416BB0();
    v1 = v0;
    v2 = 0;
    v3 = HIDWORD(v0);
    if (!*(_DWORD*)& byte_5D4594[2650652])
        goto LABEL_115;
    v4 = sub_40A6C0();
    if (sub_416650() && sub_41E2F0() == 8)
        v2 = 1;
    if (v4 == 1 || sub_40A5C0(8) || *(_DWORD*)& byte_5D4594[2598000] % v4 == 1)
        LABEL_115:
        sub_40EE90(1);
    sub_502100();
    sub_5524C0();
    sub_552460();
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
        sub_4D3580(1);
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x20000000)
    {
        *(_DWORD*)& v38[4] = (__PAIR64__(v3, v1) - *(_QWORD*)& byte_5D4594[1548684]) >> 32;
        if (__PAIR64__(v3, v1) - *(_QWORD*)& byte_5D4594[1548684] > 0x3E8)
        {
            sub_4D3130();
            *(_DWORD*)& byte_5D4594[1548684] = v1;
            *(_DWORD*)& byte_5D4594[1548688] = v3;
        }
    }
    if (!sub_40A5C0(2048))
        sub_578FC0();
    if (sub_40A5C0(8))
    {
        if (!*(_QWORD*)& byte_5D4594[1548676])
        {
            *(_QWORD*)& byte_5D4594[1548676] = sub_416BB0() + 10000;
            sub_4597E0(0);
            if (sub_43AF70() == 1)
            {
                if (!sub_40A5C0(128))
                {
                    sub_4263C0();
                    sub_40DF90();
                    sub_4264D0();
                }
                if (!sub_4165B0()[57])
                    sub_41D650();
            }
            sub_413D30((char*)& byte_587000[196872]);
            sub_46DCB0();
        }
        sub_4DEB30();
        sub_4DEB50();
        if ((unsigned __int64)sub_416BB0() > * (_QWORD*)& byte_5D4594[1548676] && !v2)
        {
            *(_DWORD*)& byte_5D4594[1548676] = 0;
            *(_DWORD*)& byte_5D4594[1548680] = 0;
            *(_DWORD*)& byte_5D4594[1548524] = 1;
            sub_416170(12);
            sub_40A540(8);
            for (i = (_DWORD*)sub_4DA7C0(); i; i = (_DWORD*)sub_4DA7F0((int)i))
            {
                sub_4EDA40(i);
                sub_4EF7D0((int)i, 1, 0);
            }
            sub_4DAC00();
            if (!sub_40A5C0(512))
            {
                v7 = sub_416590(0);
                if (v7[57])
                {
                    v38[0] = 0;
                    *(_DWORD*)& v38[1] = 0;
                    *(_DWORD*)& v38[5] = 0;
                    *(_DWORD*)& v38[9] = 0;
                    v8 = sub_409B80();
                    v9 = byte_587000[196884];
                    strcpy(v38, v8);
                    v10 = &v38[strlen(v38)];
                    *(_DWORD*)v10 = *(_DWORD*)& byte_587000[196880];
                    v10[4] = v9;
                    sub_409D70(v38);
                    v7[57] = 0;
                }
                else if (sub_4D0D70())
                {
                    sub_4D0A30();
                    v11 = sub_4D0CF0();
                    if (v11)
                    {
                        v12 = sub_409B30();
                        if (!_strcmpi(v11, v12))
                            v11 = sub_4D0CF0();
                        if (v11)
                            sub_409D70(v11);
                    }
                }
            }
        }
        goto LABEL_72;
    }
    if (*(_DWORD*)& byte_5D4594[1548524])
    {
        if (!sub_43AF70() || !v2)
        {
            sub_4EDD70();
            sub_417160();
            sub_4573B0();
            if (sub_417DA0(2) && !sub_40A5C0(49152) && sub_417DA0(4) && !sub_40A5C0(128))
                sub_4181F0(1);
            if (sub_40A5C0(4096) && sub_43AF70() == 1 && !sub_40A5C0(128))
                sub_4264D0();
            sub_40A4D0(0x8000000);
            sub_43F140(500);
            v13 = sub_4D1860();
            sub_43F1A0();
            sub_40A540(0x8000000);
            if (!v13)
            {
                v37 = sub_409B40();
                v14 = loadString_sub_40F1D0((char*)& byte_587000[196928], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1702);
                sub_4D9FD0(0, v14, v37);
                v36 = loadString_sub_40F1D0((char*)& byte_587000[196984], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1703);
                v15 = loadString_sub_40F1D0((char*)& byte_587000[197032], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1703);
                nullsub_4(0, v15, v36, 1);
                sub_43DDD0(0);
                return 0;
            }
            v17 = sub_409B40();
            nox_sprintf(v39, "%s.map", v17);
            v18 = sub_409B00();
            sub_4DEE00(v39, v18);
            if (sub_43AF70() == 1)
            {
                sub_416690();
                if (sub_40A5C0(128))
                {
                    if (sub_40A5C0(0x8000))
                        sub_419030(1);
                    sub_40A540(49152);
                    sub_4597E0(0);
                    goto LABEL_72;
                }
                sub_426060();
                sub_41D6C0();
                sub_4160D0(15);
            }
            sub_4597E0(0);
        }
        LABEL_72:
        if (*(_DWORD*)& byte_5D4594[2650636] & 0x600000)
            sub_4E76C0();
        if (sub_4DB1B0())
        {
            v20 = sub_417090(31);
            v21 = v20;
            if (v20)
            {
                if (*((_DWORD*)v20 + 514) && sub_4DCC10(*((_DWORD*)v20 + 514)) == 1)
                {
                    v22 = *((_DWORD*)v21 + 514);
                    v23 = 0;
                    v24 = (*(_DWORD*)(v22 + 16) >> 15) & 1;
                    if (!v24)
                    {
                        if (*(_DWORD*)& byte_5D4594[1599640] > 0)
                        {
                            v25 = 0;
                            do
                            {
                                if (!strncmp(
                                        "MapShutdown",
                                        *(const char**)(v25 + *(_DWORD*)& byte_5D4594[1599636]),
                                        0xBu))
                                    sub_507310(v23, 0, 0);
                                ++v23;
                                v25 += 48;
                            } while (v23 < *(int*)& byte_5D4594[1599640]);
                        }
                        sub_40A4D0(0x8000000);
                        v26 = sub_4DB160();
                        v23 = sub_4DB370((const char*)v26);
                        sub_40A540(0x8000000);
                        if (!v23 && sub_40A5C0(2))
                        {
                            v35 = loadString_sub_40F1D0((char*)& byte_587000[197104], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1931);
                            v27 = loadString_sub_40F1D0((char*)& byte_587000[197172], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1930);
                            sub_449A10(0, (int)v27, (int)v35, 33, 0, 0);
                        }
                    }
                    v28 = sub_4DB1C0();
                    v29 = v28;
                    if (v24 || v23 != 1)
                    {
                        if (v28 && !v23)
                            sub_4E7010(v22, (float2*)(*(_DWORD*)(v28 + 700) + 80));
                    }
                    else if (v28)
                    {
                        v30 = *(char**)(v28 + 700);
                        v31 = (const char*)sub_4DB2A0(*(const char**)(v28 + 700));
                        if (v31)
                        {
                            sub_4DB220(1);
                            sub_4DB230(1);
                            sub_4DB270(v31);
                        }
                        sub_4D2450(v30);
                    }
                    sub_4DB170(0, v29, 0);
                }
            }
        }
        sub_4139C0();
        if (sub_446180())
            sub_446190();
        if (sub_446030()
            && *(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(5 * *(_DWORD*)& byte_5D4594[2649704] + sub_446040()))
        {
            sub_446380();
        }
        if (!sub_413A50())
            ++* (_DWORD*)& byte_5D4594[2598000];
        sub_56F5C0();
        sub_4FC6D0();
        sub_4FC590();
        sub_4FC600();
        sub_4FC680();
        v33 = sub_417090(31);
        if (v33)
        {
            v34 = *((_DWORD*)v33 + 514);
            if (v34)
                sub_5003B0(v34);
        }
        if (sub_57AF20() && sub_57B140())
            sub_57B0A0();
        if (sub_4D6F50())
        {
            sub_4D6FD0();
            sub_4DCF20();
        }
        return 1;
    }
    sub_4D2DA0(__SPAIR64__(v3, v1));
    sub_4DEB30();
    sub_4DEB50();
    if (!sub_43DEA0())
    {
        if (!(byte_5D4594[2598000] & 1))
            sub_519990();
        sub_40B970();
        sub_40B790();
        if (!sub_413A50())
        {
            sub_51B100();
            sub_4EC720();
            if (sub_40A5C0(4096))
            {
                sub_50D890();
                sub_4E4170();
            }
            sub_4FCB70();
            sub_4FBEE0();
            sub_51ADF0();
            sub_506F30();
            sub_4E5E20();
        }
        sub_4DEC80();
        sub_4DAC00();
        if (sub_4160F0(0x10u, 10 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            sub_4E3C20();
            sub_4160D0(16);
        }
        if (sub_40A5C0(0x2000)
            && sub_43AF70() == 1
            && !sub_40A5C0(128)
            && sub_4160F0(0xFu, 60 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            sub_4263C0();
            sub_4160D0(15);
        }
        goto LABEL_72;
    }
    return 1;
}
// 4D26F3: variable 'v5' is possibly undefined
// 4D2A52: variable 'v19' is possibly undefined
// 4D2CEB: variable 'v32' is possibly undefined
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);
// 46DCB0: using guessed type int sub_46DCB0(void);

//----- (004D2DA0) --------------------------------------------------------
int __cdecl sub_4D2DA0(__int64 a1)
{
    int result; // eax
    char* v2; // eax
    int v3; // ebx
    char* v4; // esi
    double v5; // st7
    int v6; // esi
    int v7; // eax
    char* v8; // eax
    float v9; // [esp+0h] [ebp-10h]
    unsigned __int8* v10; // [esp+4h] [ebp-Ch]

    if (*(_DWORD*)& byte_5D4594[528252] == 1 && *(_DWORD*)& byte_5D4594[2598000] == *(_DWORD*)& byte_5D4594[528260])
        sub_41E390();
    sub_5096F0();
    result = sub_40A5C0(8);
    if (!result)
    {
        if (sub_40A5C0(0x2000))
        {
            sub_416720();
            if (!sub_40A5C0(128))
            {
                if (sub_409F40(0x2000))
                    sub_4D7CC0();
            }
        }
        if (!sub_40A5C0(1024))
            goto LABEL_31;
        if (sub_40AA00())
        {
            if (!*(_DWORD*)& byte_5D4594[1548704])
                sub_4D2FF0();
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1548704] = 0;
        }
        if (sub_40A5C0(0x4000000))
            goto LABEL_31;
        if (sub_40A300())
            goto LABEL_31;
        v2 = sub_416EA0();
        if (!v2)
            goto LABEL_31;
        while (*((int*)v2 + 535) <= 0)
        {
            v2 = sub_416EE0((int)v2);
            if (!v2)
                goto LABEL_31;
        }
        if (!sub_40AA00())
            goto LABEL_31;
        if (sub_417DA0(4))
        {
            v3 = sub_417DD0();
            if (v3 >= sub_40AA40())
                goto LABEL_31;
            v4 = sub_418B10();
            if (!v4)
                goto LABEL_31;
            while (sub_40A830((int)v4) != 1)
            {
                v4 = sub_418B60((int)v4);
                if (!v4)
                    goto LABEL_31;
            }
            v10 = &byte_587000[197200];
            v5 = sub_419D40(&byte_587000[197232]);
        }
        else
        {
            v6 = sub_40A770();
            if (v6 >= sub_40AA40())
            {
                LABEL_31:
                if (sub_40A6B0())
                {
                    v8 = sub_416640();
                    sub_4D9700(*(_DWORD*)(v8 + 66));
                    sub_40A6A0(0);
                }
                if ((unsigned __int64)(a1 - *(_QWORD*)& byte_5D4594[1548692]) > 0x1F4)
                {
                    sub_4D3050();
                    *(_QWORD*)& byte_5D4594[1548692] = a1;
                }
                if (sub_40A5C0(128) && !sub_40A740() && sub_417DD0() && !sub_417DA0(2))
                    sub_4183C0();
                result = sub_40A5C0(4096);
                if (result)
                {
                    sub_4D7150();
                    sub_4D71F0();
                    sub_4D7600();
                    sub_4DCE00();
                    result = sub_4D7A80();
                }
                return result;
            }
            v10 = &byte_587000[197256];
            v5 = sub_419D40(&byte_587000[197288]);
        }
        v9 = v5;
        v7 = sub_419A70(v9);
        sub_40A2A0(v7, (const char*)v10);
        goto LABEL_31;
    }
    return result;
}

//----- (004D2FF0) --------------------------------------------------------
char* sub_4D2FF0()
{
    char* result; // eax
    int v1; // esi

    result = (char*)sub_40AA70(0);
    if (result || (result = sub_416EA0(), (v1 = (int)result) == 0))
    {
        *(_DWORD*)& byte_5D4594[1548704] = 1;
    }
    else
    {
        do
        {
            if (*(_BYTE*)(v1 + 3680) & 1)
                sub_4174F0(v1, 256);
            result = sub_416EE0(v1);
            v1 = (int)result;
        } while (result);
        *(_DWORD*)& byte_5D4594[1548704] = 1;
    }
    return result;
}

//----- (004D3050) --------------------------------------------------------
char* sub_4D3050()
{
    char* result; // eax
    bool v1; // zf
    int i; // esi
    char v3[5]; // [esp+0h] [ebp-8h]

    v3[0] = -41;
    if (!*(_DWORD*)& byte_5D4594[1548700]
        || (result = sub_416EE0(*(int*)& byte_5D4594[1548700]), (*(_DWORD*)& byte_5D4594[1548700] = result) == 0))
    {
        result = sub_416EA0();
        *(_DWORD*)& byte_5D4594[1548700] = result;
    }
    if (result)
    {
        while (result[2064] != 31)
        {
            v1 = sub_554240((unsigned __int8)result[2064]) == 0;
            result = *(char**)& byte_5D4594[1548700];
            if (!v1)
                break;
            result = sub_416EE0(*(int*)& byte_5D4594[1548700]);
            *(_DWORD*)& byte_5D4594[1548700] = result;
            if (!result)
            {
                result = sub_416EA0();
                *(_DWORD*)& byte_5D4594[1548700] = result;
            }
        }
        if (result)
        {
            *(_WORD*)& v3[1] = *((_WORD*)result + 1030);
            *(_WORD*)& v3[3] = sub_554240((unsigned __int8)result[2064]);
            result = sub_416EA0();
            for (i = (int)result; result; i = (int)result)
            {
                sub_40EBC0(*(unsigned __int8*)(i + 2064), 1, v3, 5);
                result = sub_416EE0(i);
            }
        }
    }
    return result;
}

//----- (004D3130) --------------------------------------------------------
char* sub_4D3130()
{
    char* result; // eax
    int i; // esi
    int v2; // [esp-14h] [ebp-24h]
    int v3; // [esp-14h] [ebp-24h]
    int v4; // [esp-10h] [ebp-20h]
    int v5; // [esp-Ch] [ebp-1Ch]
    int v6; // [esp-8h] [ebp-18h]
    int v7; // [esp-4h] [ebp-14h]
    int v8; // [esp+4h] [ebp-Ch]
    int v9; // [esp+8h] [ebp-8h]
    int v10; // [esp+Ch] [ebp-4h]

    sub_413C80((char*)& byte_587000[197312]);
    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        sub_4E5630(*(_BYTE*)(i + 2064), &v10, &v9, &v8);
        v7 = v8;
        v6 = v9;
        v5 = v10;
        v4 = *(_DWORD*)& byte_5D4594[2598000];
        if (*(_BYTE*)(i + 2064) == 31)
        {
            v2 = sub_553ED0(0);
            sub_413C80((char*)& byte_587000[197316], i + 4704, v2, v4, v5, v6, v7);
        }
        else
        {
            v3 = sub_553ED0(*(unsigned __int8*)(i + 2064) + 1);
            sub_413C80((char*)& byte_587000[197340], i + 4704, v3, v4, v5, v6, v7);
        }
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004D3200) --------------------------------------------------------
BOOL sub_4D3200()
{
    char* v0; // eax
    CHAR FileName[1024]; // [esp+0h] [ebp-400h]

    sub_50D1E0();
    sub_4DB100();
    sub_421B10();
    sub_516F10();
    sub_4FF770();
    sub_4D33B0();
    sub_4D3530();
    sub_416E30();
    sub_446490((void*)1);
    sub_4259F0();
    sub_4D12E0(0);
    sub_40A380();
    sub_4E4DE0();
    sub_57C460();
    sub_57C030();
    sub_511310();
    sub_4FCA80();
    sub_50ABF0();
    sub_517B30();
    sub_5018D0();
    sub_4ECA90();
    sub_506720();
    sub_50D820();
    sub_50E300();
    sub_416950();
    sub_4E3420();
    sub_4E2A20();
    if (!sub_40A5C0(2048))
    {
        sub_4DEC60(*(unsigned int*)& byte_5D4594[1548516]);
        if (!sub_40A5C0(0x2000000))
            sub_413D00();
    }
    sub_56F3B0();
    nullsub_23();
    sub_40EE60();
    v0 = sub_409E10();
    nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v0);
    return DeleteFileA(FileName);
}
// 4E3440: using guessed type void nullsub_23(void);

//----- (004D3310) --------------------------------------------------------
int __cdecl sub_4D3310(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1548716] = a1;
    return result;
}

//----- (004D3320) --------------------------------------------------------
int sub_4D3320()
{
    return *(_DWORD*)& byte_5D4594[1548716];
}

//----- (004D3330) --------------------------------------------------------
int sub_4D3330()
{
    int result; // eax

    result = sub_40A5C0(0x2000000);
    if (result)
    {
        sub_413D30((char*)& byte_587000[197384]);
        sub_43DDD0(0);
        result = sub_43DE60();
    }
    return result;
}

//----- (004D3360) --------------------------------------------------------
void sub_4D3360()
{
    nox_srand(0x141Fu);
}

//----- (004D3370) --------------------------------------------------------
int __cdecl sub_4D3370(char* a1)
{
    *(_DWORD*)& byte_587000[197424] = _open(a1, 33537, 384);
    if (*(int*)& byte_587000[197424] == -1)
        return 0;
    *(_DWORD*)& byte_5D4594[2650636] |= 0x200000u;
    return 1;
}

//----- (004D33B0) --------------------------------------------------------
unsigned int sub_4D33B0()
{
    unsigned int result; // eax

    if (*(int*)& byte_587000[197424] != -1)
        _close(*(int*)& byte_587000[197424]);
    *(_DWORD*)& byte_587000[197424] = -1;
    result = *(_DWORD*)& byte_5D4594[2650636] & 0xFFDFFFFF;
    *(_DWORD*)& byte_5D4594[2650636] &= 0xFFDFFFFF;
    return result;
}

//----- (004D33E0) --------------------------------------------------------
int __cdecl sub_4D33E0(void* a1, int a2)
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[197424];
    if (*(int*)& byte_587000[197424] != -1 && a1 && a2 >= 1)
    {
        _write(*(int*)& byte_587000[197424], &byte_5D4594[2598000], 4u);
        _write(*(int*)& byte_587000[197424], &byte_587000[197432], 1u);
        _write(*(int*)& byte_587000[197424], &a2, 4u);
        result = _write(*(int*)& byte_587000[197424], a1, 2 * a2);
    }
    return result;
}

//----- (004D3450) --------------------------------------------------------
int __cdecl sub_4D3450(int a1, void* a2, unsigned int a3)
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[197424];
    if (*(int*)& byte_587000[197424] != -1)
    {
        _write(*(int*)& byte_587000[197424], &byte_5D4594[2598000], 4u);
        _write(*(int*)& byte_587000[197424], &byte_587000[197433], 1u);
        _write(*(int*)& byte_587000[197424], (const void*)(a1 + 2064), 1u);
        _write(*(int*)& byte_587000[197424], &a3, 4u);
        result = _write(*(int*)& byte_587000[197424], a2, a3);
    }
    return result;
}

//----- (004D34C0) --------------------------------------------------------
int __cdecl sub_4D34C0(char* a1)
{
    char* v2; // eax

    *(_DWORD*)& byte_587000[197428] = _open(a1, 0x8000);
    if (*(int*)& byte_587000[197428] == -1)
        return 0;
    *(_DWORD*)& byte_5D4594[1548732] = 0;
    *(_DWORD*)& byte_5D4594[1548736] = 0;
    *(_DWORD*)& byte_5D4594[1548728] = 0;
    byte_5D4594[1548724] = 0;
    *(_DWORD*)& byte_5D4594[2650636] |= 0x400000u;
    v2 = sub_417040(255);
    sub_4E6860((int)v2, 0, 1);
    return 1;
}

//----- (004D3530) --------------------------------------------------------
void sub_4D3530()
{
    char* v0; // eax

    if (*(int*)& byte_587000[197428] != -1)
        _close(*(int*)& byte_587000[197428]);
    *(_DWORD*)& byte_587000[197428] = -1;
    *(_DWORD*)& byte_5D4594[1548732] = 0;
    *(_DWORD*)& byte_5D4594[1548736] = 0;
    *(_DWORD*)& byte_5D4594[2650636] &= 0xFFBFFFFF;
    v0 = sub_417040(255);
    sub_4E6AA0((int)v0);
}

//----- (004D3580) --------------------------------------------------------
int __cdecl sub_4D3580(int a1)
{
    int v1; // esi
    wchar_t* v2; // esi
    wchar_t* v3; // eax
    int result; // eax
    unsigned int v5; // [esp+8h] [ebp-264h]
    int v6; // [esp+Ch] [ebp-260h]
    int v7; // [esp+10h] [ebp-25Ch]
    int v8; // [esp+14h] [ebp-258h]
    int v9; // [esp+18h] [ebp-254h]
    char v10[80]; // [esp+1Ch] [ebp-250h]
    char v11[512]; // [esp+6Ch] [ebp-200h]

    v1 = 0;
    if (*(int*)& byte_587000[197428] == -1)
    {
        v1 = 1;
        LABEL_30:
        sub_4D3530();
        sub_43DDD0(0);
        sub_43DE60();
        return v1;
    }
    if (!*(_DWORD*)& byte_5D4594[1548732])
    {
        if (_read(*(int*)& byte_587000[197428], &byte_5D4594[1548728], 4u))
            * (_DWORD*)& byte_5D4594[1548732] = 1;
        else
            v1 = 1;
    }
    if (!*(_DWORD*)& byte_5D4594[1548736])
    {
        if (!_read(*(int*)& byte_587000[197428], &byte_5D4594[1548724], 1u))
        {
            v1 = 1;
            goto LABEL_30;
        }
        *(_DWORD*)& byte_5D4594[1548736] = 1;
    }
    if (v1)
        goto LABEL_30;
    while (*(_DWORD*)& byte_5D4594[2598000] == *(_DWORD*)& byte_5D4594[1548728])
    {
        switch (byte_5D4594[1548724])
        {
            case 1u:
                if (a1 == 1)
                    return v1;
                _read(*(int*)& byte_587000[197428], &v9, 1u);
                _read(*(int*)& byte_587000[197428], &v5, 4u);
                _read(*(int*)& byte_587000[197428], &byte_5D4594[1548740], v5);
                sub_51BAD0((unsigned __int8)v9, &byte_5D4594[1548740], v5);
                break;
            case 2u:
                if (a1 == 1)
                    return v1;
                _read(*(int*)& byte_587000[197428], &v6, 1u);
                _read(*(int*)& byte_587000[197428], v10, (unsigned __int8)v6);
                sub_409D70(v10);
                _read(*(int*)& byte_587000[197428], &v7, 4u);
                if ((v7 & 0xFF0000) != 0x10000)
                {
                    v2 = loadString_sub_40F1D0((char*)& byte_587000[197480], 0, "C:\\NoxPost\\src\\Server\\Network\\playback.c", 355);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[197540], 0, "C:\\NoxPost\\src\\Server\\Network\\playback.c", 356);
                    nullsub_4(0, v2, v3, 1);
                    sub_43DDD0(0);
                    sub_43DE60();
                    v1 = 1;
                }
                break;
            case 3u:
                if (a1 == 1)
                {
                    _read(*(int*)& byte_587000[197428], &v8, 4u);
                    _read(*(int*)& byte_587000[197428], v11, 2 * v8);
                    sub_443C80((wchar_t*)v11, 0);
                }
                break;
            case 4u:
                if (a1 == 1)
                    return v1;
                sub_43DDD0(0);
                sub_43DE60();
                break;
            default:
                break;
        }
        if (!_read(*(int*)& byte_587000[197428], &byte_5D4594[1548728], 4u))
        {
            result = v1;
            *(_DWORD*)& byte_5D4594[1548732] = 0;
            return result;
        }
        if (!_read(*(int*)& byte_587000[197428], &byte_5D4594[1548724], 1u))
        {
            result = v1;
            *(_DWORD*)& byte_5D4594[1548736] = 0;
            return result;
        }
        if (v1)
            goto LABEL_30;
    }
    return v1;
}
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (004D3860) --------------------------------------------------------
void __cdecl sub_4D3860(void* a1)
{
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x200000
        && (*(int*)& byte_587000[197424] != -1))
    {
        sub_415F30(*(int*)& byte_587000[197424]);
        _write(*(int*)& byte_587000[197424], a1, 0x99u);
    }
    else if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
    {
        if (*(int*)& byte_587000[197428] != -1)
        {
            sub_415F50(*(int*)& byte_587000[197428]);
            _read(*(int*)& byte_587000[197428], a1, 0x99u);
        }
    }
}

//----- (004D38D0) --------------------------------------------------------
int sub_4D38D0()
{
    int result; // eax
    int v2; // [esp+0h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x200000 && *(int*)& byte_587000[197424] != -1)
    {
        _write(*(int*)& byte_587000[197424], &byte_5D4594[2598000], 4u);
        _write(*(int*)& byte_587000[197424], &byte_587000[197434], 1u);
        *(_DWORD*)& byte_5D4594[1549764] = sub_409B30();
        byte_5D4594[1548725] = strlen(*(const char**)& byte_5D4594[1549764]) + 1;
        _write(*(int*)& byte_587000[197424], &byte_5D4594[1548725], 1u);
        _write(*(int*)& byte_587000[197424], *(const void**)& byte_5D4594[1549764], byte_5D4594[1548725]);
        v2 = 66458;
        _write(*(int*)& byte_587000[197424], &v2, 4u);
        result = 0;
    }
    else if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000 && *(int*)& byte_587000[197428] != -1)
    {
        result = sub_4D3580(0);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004D39B0) --------------------------------------------------------
void sub_4D39B0()
{
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x200000)
    {
        if (*(int*)& byte_587000[197424] != -1)
        {
            _write(*(int*)& byte_587000[197424], &byte_5D4594[2598000], 4u);
            _write(*(int*)& byte_587000[197424], &byte_587000[197435], 1u);
        }
    }
}

//----- (004D39F0) --------------------------------------------------------
int __cdecl sub_4D39F0(const char* a3)
{
    unsigned int v1; // ecx
    char v2; // dl
    unsigned __int8* v3; // edi
    const char* v4; // esi
    int v5; // edx
    int v6; // eax
    unsigned __int8* v7; // edi
    unsigned int v8; // ecx
    unsigned __int8* v9; // edi
    const char* v10; // esi
    unsigned __int8* v11; // edi
    int v12; // ecx
    int v13; // edx
    int v14; // eax
    char* v15; // edi
    unsigned __int8 v16; // cl
    int result; // eax
    char v18[2048]; // [esp+10h] [ebp-800h]

    *(_QWORD*)& byte_5D4594[1549772] = sub_416BB0();
    memset(&byte_5D4594[3835340], 0, 0x48u);
    *(_DWORD*)& byte_5D4594[3835340] = 0;
    *(_DWORD*)& byte_5D4594[3835344] = 0;
    *(_DWORD*)& byte_5D4594[3835348] = 0;
    *(_DWORD*)& byte_5D4594[3835356] = 255;
    *(_DWORD*)& byte_5D4594[3835352] = 0;
    *(_DWORD*)& byte_5D4594[3835360] = 0;
    *(_DWORD*)& byte_5D4594[3835364] = 1;
    *(_DWORD*)& byte_5D4594[3835368] = 1;
    *(_DWORD*)& byte_5D4594[3835372] = 1;
    *(_DWORD*)& byte_5D4594[3835376] = 0;
    *(_DWORD*)& byte_5D4594[3835380] = 0;
    *(_DWORD*)& byte_5D4594[3835384] = 0;
    *(_DWORD*)& byte_5D4594[3835388] = 0;
    *(_DWORD*)& byte_5D4594[3835392] = 1;
    *(_DWORD*)& byte_5D4594[3835396] = -1;
    byte_5D4594[3835400] = 2;
    *(_DWORD*)& byte_5D4594[3835404] = 0;
    *(_DWORD*)& byte_5D4594[3835408] = 0;
    sub_51D0E0();
    if (a3)
    {
        v1 = strlen(a3) + 1;
        v2 = v1;
        v1 >>= 2;
        qmemcpy(&byte_5D4594[3841580], a3, 4 * v1);
        v4 = &a3[4 * v1];
        v3 = &byte_5D4594[4 * v1 + 3841580];
        LOBYTE(v1) = v2;
        v5 = *(_DWORD*)& byte_587000[197560];
        qmemcpy(v3, v4, v1 & 3);
        strcpy((char*)& byte_5D4594[3835436], a3);
        v6 = *(_DWORD*)& byte_587000[197564];
        v7 = &byte_5D4594[strlen((const char*)& byte_5D4594[3835436]) + 3835436];
        *(_DWORD*)v7 = *(_DWORD*)& byte_587000[197556];
        *((_DWORD*)v7 + 1) = v5;
        *((_DWORD*)v7 + 2) = v6;
        v8 = strlen(a3) + 1;
        LOBYTE(v5) = v8;
        v8 >>= 2;
        qmemcpy(&byte_5D4594[3837484], a3, 4 * v8);
        v10 = &a3[4 * v8];
        v9 = &byte_5D4594[4 * v8 + 3837484];
        LOBYTE(v8) = v5;
        LOWORD(v5) = *(_WORD*)& byte_587000[197576];
        qmemcpy(v9, v10, v8 & 3);
        v11 = &byte_5D4594[strlen((const char*)& byte_5D4594[3837484]) + 3837485];
        v12 = *(_DWORD*)& byte_587000[197572];
        *(_DWORD*)--v11 = *(_DWORD*)& byte_587000[197568];
        LOBYTE(v6) = byte_587000[197578];
        *((_DWORD*)v11 + 1) = v12;
        *((_WORD*)v11 + 4) = v5;
        v11[10] = v6;
        DeleteFileA((LPCSTR)& byte_5D4594[3835436]);
        DeleteFileA((LPCSTR)& byte_5D4594[3837484]);
    }
    else
    {
        byte_5D4594[3841580] = byte_5D4594[1549780];
        byte_5D4594[3839532] = byte_5D4594[1549784];
        byte_5D4594[3835436] = byte_5D4594[1549788];
        byte_5D4594[3837484] = byte_5D4594[1549792];
    }
    sub_5028E0();
    v13 = *(_DWORD*)& byte_587000[197584];
    strcpy(v18, a3);
    v14 = *(_DWORD*)& byte_587000[197588];
    v15 = &v18[strlen(v18)];
    *(_DWORD*)v15 = *(_DWORD*)& byte_587000[197580];
    v16 = byte_587000[197592];
    *((_DWORD*)v15 + 1) = v13;
    *((_DWORD*)v15 + 2) = v14;
    v15[12] = v16;
    sub_502A50(v18);
    sub_502AB0(v18);
    result = sub_502B10();
    *(_DWORD*)& byte_5D4594[3835312] = 0;
    *(_DWORD*)& byte_5D4594[3835308] = 0;
    *(_DWORD*)& byte_5D4594[1599580] = 0;
    return result;
}
// 4D39F0: using guessed type char var_800[2048];

//----- (004D3C30) --------------------------------------------------------
__int64 sub_4D3C30()
{
    sub_503F40();
    sub_51D0E0();
    sub_502DF0();
    return sub_416BB0();
}

//----- (004D3C50) --------------------------------------------------------
void __cdecl sub_4D3C50(const void* a1)
{
    qmemcpy(&byte_5D4594[3835340], a1, 0x48u);
}

//----- (004D3C70) --------------------------------------------------------
unsigned __int8* sub_4D3C70()
{
    return &byte_5D4594[3835340];
}

//----- (004D3C80) --------------------------------------------------------
_DWORD* __cdecl sub_4D3C80(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ebp
    int v3; // ecx
    int v4; // edi
    int v5; // esi
    int v6; // edx
    int v7; // ebx
    int v8; // ecx
    int v9; // esi
    int v10; // [esp+10h] [ebp-10h]
    int v11; // [esp+14h] [ebp-Ch]
    int v12; // [esp+1Ch] [ebp-4h]

    result = a1;
    v2 = a1[3];
    v10 = *a1;
    v3 = a1[1];
    v11 = a1[1];
    if (v2 < v3)
    {
        v3 = a1[3];
        v10 = a1[2];
        v11 = a1[3];
    }
    if (a1[5] < v3)
    {
        v10 = a1[4];
        v3 = a1[5];
        v11 = a1[5];
    }
    if (a1[7] < v3)
    {
        v10 = a1[6];
        v11 = a1[7];
    }
    v4 = a1[2];
    v12 = a1[3];
    if (*a1 < v4)
    {
        v4 = *a1;
        v12 = a1[1];
    }
    if (a1[4] < v4)
    {
        v4 = a1[4];
        v12 = a1[5];
    }
    v5 = a1[6];
    if (v5 < v4)
    {
        v4 = a1[6];
        v12 = a1[7];
    }
    v6 = a1[4];
    v7 = a1[5];
    if (*a1 > v6)
    {
        v6 = *a1;
        v7 = a1[1];
    }
    if (a1[2] > v6)
    {
        v7 = a1[3];
        v6 = a1[2];
    }
    if (v5 > v6)
    {
        v6 = a1[6];
        v7 = a1[7];
    }
    v8 = a1[7];
    v9 = a1[6];
    if (a1[1] > v8)
    {
        v9 = *a1;
        v8 = a1[1];
    }
    if (v2 > v8)
    {
        v9 = a1[2];
        v8 = a1[3];
    }
    if (a1[5] > v8)
    {
        v9 = a1[4];
        v8 = a1[5];
    }
    a1[6] = v9;
    *a1 = v10;
    a1[2] = v4;
    a1[7] = v8;
    a1[1] = v11;
    a1[4] = v6;
    a1[5] = v7;
    a1[3] = v12;
    return result;
}

//----- (004D3D90) --------------------------------------------------------
int __cdecl sub_4D3D90(float2* a1, float2* a2)
{
    if (!a1 || !a2)
        return 0;
    a2->field_0 = (a1->field_4 + a1->field_0) * 0.70710677 + 2957.0;
    a2->field_4 = (a1->field_4 - a1->field_0) * 0.70710677 + 2956.0;
    if (a2->field_0 <= 80.5)
        a2->field_0 = 82.5;
    if (a2->field_4 <= 80.5)
        a2->field_4 = 81.5;
    if (a2->field_0 >= 5853.5)
        a2->field_0 = 5851.5;
    if (a2->field_4 >= 5853.5)
        a2->field_4 = 5852.5;
    return 1;
}

//----- (004D3E30) --------------------------------------------------------
int __cdecl sub_4D3E30(float2* a1, float2* a2)
{
    int result; // eax

    if (!a1 || !a2)
        return 0;
    if (a1->field_0 <= 80.5)
        a1->field_0 = 82.5;
    if (a1->field_4 <= 80.5)
        a1->field_4 = 81.5;
    if (a1->field_0 >= 5853.5)
        a1->field_0 = 5851.5;
    if (a1->field_4 >= 5853.5)
        a1->field_4 = 5852.5;
    result = 1;
    a2->field_0 = (a1->field_0 - 1.0 - a1->field_4) * 0.70710677;
    a2->field_4 = (a1->field_4 + a1->field_0 - 5912.0) * 0.70710677;
    return result;
}

//----- (004D3ED0) --------------------------------------------------------
BOOL __cdecl sub_4D3ED0(float2* a1)
{
    BOOL result; // eax
    float v2; // [esp+0h] [ebp-8h]
    float v3; // [esp+4h] [ebp-4h]

    result = 0;
    if (a1)
    {
        v2 = (a1->field_4 + a1->field_0) * 0.70710677 + 2957.0;
        v3 = (a1->field_4 - a1->field_0) * 0.70710677 + 2956.0;
        if (v2 > 80.5 && v3 > 80.5 && v2 < 5853.5 && v3 < 5853.5)
            result = 1;
    }
    return result;
}

//----- (004D3F60) --------------------------------------------------------
int __cdecl sub_4D3F60(int a1)
{
    if (a1 != 1 && a1)
        return 0;
    *(_DWORD*)& byte_5D4594[3835408] = 1;
    return 1;
}

//----- (004D3F80) --------------------------------------------------------
int __cdecl sub_4D3F80(int a1)
{
    int result; // eax

    switch (a1)
    {
        case 0:
            result = 1;
            break;
        case 1:
            result = 2;
            break;
        case 2:
            result = 5;
            break;
        case 3:
            result = 0;
            break;
        case 5:
            result = 8;
            break;
        case 6:
            result = 3;
            break;
        case 7:
            result = 6;
            break;
        case 8:
            result = 7;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}

//----- (004D3FF0) --------------------------------------------------------
int __cdecl sub_4D3FF0(int a1)
{
    int result; // eax

    switch (a1)
    {
        case 0:
            result = 3;
            break;
        case 1:
            result = 0;
            break;
        case 2:
            result = 1;
            break;
        case 3:
            result = 6;
            break;
        case 5:
            result = 2;
            break;
        case 6:
            result = 7;
            break;
        case 7:
            result = 8;
            break;
        case 8:
            result = 5;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}

//----- (004D4060) --------------------------------------------------------
float2* __cdecl sub_4D4060(float2* a1, float2* a2, int a3)
{
    double v3; // st7
    double v4; // st6
    int v5; // esi
    int v6; // edx
    int v7; // ecx
    double v8; // st7
    float2* result; // eax
    double v10; // st7
    int v11; // [esp+Ch] [ebp-8h]
    float v12; // [esp+10h] [ebp-4h]
    float2* v13; // [esp+18h] [ebp+4h]

    v3 = a1->field_0 + 11.5;
    v4 = a1->field_4 + 11.5;
    v13 = (float2*)(__int64)(v3 * 0.021739131);
    v12 = v4;
    v11 = (__int64)(v4 * 0.021739131);
    v5 = (int)(__int64)v3 % 46;
    v6 = (__int64)v12 % 46;
    v7 = 2 * a3;
    if (v5 <= v6)
    {
        if (v7 - v5 <= v6)
        {
            result = a2;
            a2->field_0 = (double)(int)v13 * 46.0 + 11.0;
            v10 = (double)v11;
            goto LABEL_8;
        }
        v8 = (double)(int)((unsigned __int64)(__int64)(v3 * 0.021739131) - 1) * 46.0;
        LABEL_6:
        result = a2;
        a2->field_0 = v8 + 34.0;
        a2->field_4 = (double)v11 * 46.0 + 11.0;
        return result;
    }
    v8 = (double)(int)v13 * 46.0;
    if (v7 - v5 <= v6)
        goto LABEL_6;
    result = a2;
    a2->field_0 = v8 + 11.0;
    v10 = (double)(int)((unsigned __int64)(__int64)(v4 * 0.021739131) - 1);
    LABEL_8:
    result->field_4 = v10 * 46.0 + 34.0;
    return result;
}

//----- (004D4160) --------------------------------------------------------
void sub_4D4160()
{
    int v0; // edi
    int v1; // esi
    int v2; // eax
    int v3; // eax
    int v4; // eax
    char* v5; // eax
    char* v6; // eax
    float2 v8; // [esp+8h] [ebp-808h]
    CHAR FileName[1024]; // [esp+10h] [ebp-800h]
    CHAR ExistingFileName[1024]; // [esp+410h] [ebp-400h]

    sub_40A4D0(0x400000);
    sub_51D4D0((char*)& byte_587000[197596]);
    v8.field_4 = 0.0;
    v8.field_0 = 0.0;
    v0 = 20;
    do
    {
        v1 = 20;
        do
        {
            sub_51D5E0(&v8);
            --v1;
            v8.field_0 = v8.field_0 + 32.526913;
        } while (v1);
        --v0;
        v8.field_0 = 0.0;
        v8.field_4 = v8.field_4 + 32.526913;
    } while (v0);
    v8.field_4 = 0.0;
    v8.field_0 = 0.0;
    v2 = sub_5029A0((char*)& byte_587000[197608]);
    sub_503830(v2);
    sub_503B30(&v8);
    v8.field_4 = 65.053825;
    v8.field_0 = 65.053825;
    v3 = sub_5029A0((char*)& byte_587000[197620]);
    sub_503830(v3);
    sub_503B30(&v8);
    v8.field_4 = 195.16147;
    v8.field_0 = 195.16147;
    v4 = sub_5029A0((char*)& byte_587000[197632]);
    sub_503830(v4);
    sub_503B30(&v8);
    v5 = sub_409E10();
    nox_sprintf(FileName, "%s\\nc.obj", v5);
    v6 = sub_409E10();
    nox_sprintf(ExistingFileName, "%s\\blend.obj", v6);
    DeleteFileA(FileName);
    MoveFileA(ExistingFileName, FileName);
    sub_40A540(0x400000);
}

//----- (004D42C0) --------------------------------------------------------
int sub_4D42C0()
{
    return *(_DWORD*)& byte_5D4594[1550916];
}

//----- (004D42D0) --------------------------------------------------------
int __cdecl sub_4D42D0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1550916] = a1;
    return result;
}

//----- (004D42E0) --------------------------------------------------------
unsigned int __cdecl sub_4D42E0(const char* a1)
{
    unsigned int result; // eax

    result = strlen(a1) + 1;
    qmemcpy(&byte_587000[197860], a1, result);
    return result;
}

//----- (004D4310) --------------------------------------------------------
char* sub_4D4310()
{
    return (char*)& byte_587000[197860];
}

//----- (004D4320) --------------------------------------------------------
BOOL sub_4D4320()
{
    int v0; // esi
    int v1; // eax
    char* v2; // eax
    char* v3; // eax
    BOOL result; // eax
    int i; // eax
    char* v6; // eax
    char* v7; // eax
    char* v8; // [esp-8h] [ebp-C10h]
    char* v9; // [esp-4h] [ebp-C0Ch]
    char* v10; // [esp-4h] [ebp-C0Ch]
    CHAR PathName[1024]; // [esp+8h] [ebp-C00h]
    CHAR FileName[1024]; // [esp+408h] [ebp-800h]
    CHAR ExistingFileName[1024]; // [esp+808h] [ebp-400h]

    v0 = 100;
    sub_4D12E0(1);
    sub_40A4D0(0x400000);
    sub_4DA3C0(&byte_5D4594[1550924]);
    memset(&byte_5D4594[3801836], 0, 0x5B8u);
    while (1)
    {
        v1 = sub_4D44E0();
        if (v1 == 1)
            break;
        if (v1)
        {
            if (--v0)
                continue;
        }
        return 0;
    }
    v2 = sub_409E10();
    nox_sprintf(FileName, "%s\\nc.obj", v2);
    v3 = sub_409E10();
    nox_sprintf(ExistingFileName, "%s\\blend.obj", v3);
    if (_access(FileName, 0) == -1 || (result = DeleteFileA(FileName)))
    {
        if (_access(ExistingFileName, 0) == -1 || (result = MoveFileA(ExistingFileName, FileName)))
        {
            for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
                * (_DWORD*)(i + 44) = 0;
            sub_4D5DB0((int)& byte_5D4594[3801836]);
            v9 = sub_4D4310();
            v6 = sub_409E10();
            nox_sprintf(PathName, "%s\\Maps\\$%s", v6, v9);
            _mkdir(PathName);
            v10 = sub_4D4310();
            v8 = sub_4D4310();
            v7 = sub_409E10();
            nox_sprintf(PathName, "%s\\Maps\\$%s\\$%s.map", v7, v8, v10);
            if (!sub_51E010(PathName, 1))
                return 0;
            sub_4D12E0(1);
            sub_4DA3E0(*(int*)& byte_5D4594[1550924]);
            *(_DWORD*)& byte_5D4594[1550924] = 0;
            sub_40A540(0x400000);
            result = 1;
        }
    }
    return result;
}

//----- (004D44E0) --------------------------------------------------------
int sub_4D44E0()
{
    const char* v0; // eax
    int result; // eax
    int v2; // esi
    int v3; // esi
    float* v4; // edi
    double v5; // st7
    char* i; // esi
    int* j; // esi
    int* k; // esi
    float2 a2; // [esp+4h] [ebp-8h]

    *(_DWORD*)& byte_5D4594[1550916] = 0;
    v0 = (const char*)sub_57C490("theme");
    if (v0)
        sub_4D42E0(v0);
    sub_526C40(0);
    sub_51D100(0);
    result = sub_51E260((int*)& byte_5D4594[1549796], (int)& byte_587000[197860]);
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1549864] = (__int64)(*(float*)& byte_5D4594[1549860] * 0.030743772);
        sub_526AB0(*(unsigned int*)& byte_5D4594[1549872]);
        sub_526950();
        result = sub_5213E0();
        if (result)
        {
            result = sub_520EA0((int)& byte_5D4594[1549796]);
            if (result)
            {
                sub_4D4F40(&byte_5D4594[1549796]);
                if (sub_525D20((int)& byte_5D4594[1549796]))
                {
                    sub_4D52F0();
                    if (sub_5266F0((int)& byte_5D4594[1549796]))
                    {
                        if (!sub_526830((int)& byte_5D4594[1549796]))
                        {
                            v2 = 0;
                            LABEL_25:
                            sub_521A40();
                            sub_521400();
                            sub_520F80();
                            sub_520D50(&byte_5D4594[1549796]);
                            return v2;
                        }
                        sub_5259F0(*(int*)& byte_5D4594[1550916], 0, 0.0);
                        sub_525AF0(*(int*)& byte_5D4594[1550916]);
                        if (*(_DWORD*)& byte_5D4594[1549980])
                        {
                            v3 = (__int64)(*(float*)& byte_5D4594[1549860] * 0.030743772);
                            v4 = sub_521940(2 * v3 + 1, 2 * v3 + 1);
                            v5 = (double)-v3 * 32.526913;
                            a2.field_0 = v5;
                            a2.field_4 = v5;
                            sub_521880(v4, &a2);
                            for (i = (char*)sub_521710(); i; i = (char*)sub_521720((int)i))
                                sub_521BC0((int)v4, (float2*)(i + 20), *((float*)i + 7), *((float*)i + 8));
                            sub_524070((int)& byte_5D4594[1549796], (int)v4);
                            sub_524E00((int)& byte_5D4594[1549796], (int)v4);
                            sub_522340((int)& byte_5D4594[1549796], (int)v4);
                            sub_521A10(v4);
                        }
                        if (sub_524310((int)& byte_5D4594[1549796]))
                        {
                            for (j = (int*)sub_521710(); j; j = (int*)sub_521720((int)j))
                            {
                                if (sub_5238F0(j))
                                {
                                    sub_5235F0(156);
                                    sub_524E00((int)& byte_5D4594[1549796], (int)j);
                                }
                            }
                            for (k = (int*)sub_521710(); k; k = (int*)sub_521720((int)k))
                            {
                                if (!sub_5238F0(k))
                                {
                                    sub_5235F0(156);
                                    sub_524E00((int)& byte_5D4594[1549796], (int)k);
                                }
                            }
                            sub_522D30((int)& byte_5D4594[1549796]);
                            sub_4D4790();
                            sub_522F40(&byte_5D4594[1549796]);
                            sub_521710();
                            sub_5228B0((int)& byte_5D4594[1549796]);
                            v2 = 1;
                            goto LABEL_25;
                        }
                    }
                }
                v2 = 2;
                goto LABEL_25;
            }
        }
    }
    return result;
}

//----- (004D4790) --------------------------------------------------------
float* sub_4D4790()
{
    float* result; // eax
    float* v1; // edi
    int* v2; // esi
    int v3; // ebx
    int v4; // ebp
    int v5; // eax
    int* v6; // ebp
    int v7; // eax
    float* v8; // eax
    double v9; // st7
    double v10; // st7
    float* v11; // eax
    double v12; // st7
    double v13; // st7
    double v14; // st7
    double v15; // st7
    int v16; // eax
    int v17; // eax
    int* v18; // ebp
    int v19; // ecx
    float* v20; // eax
    double v21; // st7
    double v22; // st7
    double v23; // st7
    float* v24; // eax
    double v25; // st7
    double v26; // st7
    double v27; // st7
    int v28; // eax
    int v29; // [esp+8h] [ebp-40h]
    int v30; // [esp+Ch] [ebp-3Ch]
    int v31; // [esp+Ch] [ebp-3Ch]
    int v32; // [esp+10h] [ebp-38h]
    int v33; // [esp+14h] [ebp-34h]
    float2 v34; // [esp+18h] [ebp-30h]
    float2 a2; // [esp+20h] [ebp-28h]
    float v36; // [esp+28h] [ebp-20h]
    float v37; // [esp+2Ch] [ebp-1Ch]
    float2 v38; // [esp+30h] [ebp-18h]
    float2 v39; // [esp+38h] [ebp-10h]
    int2 a1; // [esp+40h] [ebp-8h]

    result = (float*)sub_521710();
    v1 = result;
    v2 = 0;
    if (!result)
        return result;
    v3 = v33;
    do
    {
        if (*(_DWORD*)v1 != 1)
            goto LABEL_117;
        sub_5235F0(156);
        v4 = 0;
        v32 = 0;
        while (1)
        {
            if (!*((_BYTE*)v1 + v4 + 216) && sub_526AC0(1, 100) <= *(int*)& byte_5D4594[1549848])
            {
                switch (v4)
                {
                    case 0:
                    case 1:
                        a1.field_0 = (int)v1[1];
                        if (v4 == 1)
                            a1.field_4 = *((_DWORD*)v1 + 2) + *((_DWORD*)v1 + 4);
                        else
                            a1.field_4 = *((_DWORD*)v1 + 2) - 1;
                        v31 = 0;
                        if (*((int*)v1 + 3) <= 0)
                            goto LABEL_115;
                        while (1)
                        {
                            v17 = sub_521290(&a1);
                            v18 = (int*)v17;
                            if (v17)
                            {
                                if ((int*)v17 != v2)
                                    goto LABEL_72;
                                if (*(_BYTE*)(v17 + 52) & 2)
                                    ++v29;
                            }
                            if ((int*)v17 != v2 || (v19 = v31, v31 == *((_DWORD*)v1 + 3) - 1))
                            {
                                LABEL_72:
                                if (v2 && v29 >= 3)
                                {
                                    v34.field_0 = (double)((v3 + v31) / 2) * 32.526913 + v1[9];
                                    if (v32 == 1)
                                        v34.field_4 = v1[12];
                                    else
                                        v34.field_4 = v1[10];
                                    sub_527030(&v34);
                                    v34.field_0 = v34.field_0 - 16.263456;
                                    if (v29 < 4)
                                        sub_527940((char*)& byte_587000[198320]);
                                    else
                                        sub_527940((char*)& byte_587000[198304]);
                                    v20 = sub_5279B0(&v34.field_0);
                                    if (v20)
                                        sub_527C60((int)v20, 5);
                                    a2.field_0 = v34.field_0;
                                    if (v32 == 1)
                                        a2.field_4 = v34.field_4 - 32.526913;
                                    else
                                        a2.field_4 = v34.field_4;
                                    sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
                                    if (sub_5238F0(v2))
                                    {
                                        v21 = a2.field_4;
                                        if (v32 == 1)
                                            v22 = v21 + 32.526913;
                                        else
                                            v22 = v21 - 32.526913;
                                        a2.field_4 = v22;
                                        sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
                                    }
                                    v23 = v34.field_0 + 16.263456;
                                    if (v29 < 4)
                                    {
                                        v37 = v34.field_4;
                                    }
                                    else
                                    {
                                        v34.field_0 = v23 + 32.526913;
                                        sub_527030(&v34);
                                        v34.field_0 = v34.field_0 + 16.263456;
                                        sub_527940((char*)& byte_587000[198332]);
                                        v24 = sub_5279B0(&v34.field_0);
                                        if (v24)
                                            sub_527C60((int)v24, 3);
                                        v25 = v34.field_0 - 32.526913;
                                        v37 = v34.field_4;
                                        v36 = v25;
                                        a2.field_0 = v25;
                                        if (v32 == 1)
                                            a2.field_4 = v34.field_4 - 32.526913;
                                        else
                                            a2.field_4 = v34.field_4;
                                        sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
                                        if (sub_5238F0(v2))
                                        {
                                            v26 = a2.field_4;
                                            if (v32 == 1)
                                                v27 = v26 + 32.526913;
                                            else
                                                v27 = v26 - 32.526913;
                                            a2.field_4 = v27;
                                            sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
                                        }
                                        v23 = v36;
                                    }
                                    v39.field_0 = v23;
                                    v39.field_4 = v37 - 32.526913;
                                    v38.field_0 = v23;
                                    v38.field_4 = v37 + 32.526913;
                                    sub_522C80(&v39.field_0);
                                    sub_522C80(&v38.field_0);
                                    sub_51D3F0(&v39, &v38);
                                    sub_51D3F0(&v38, &v39);
                                    if (v32 == 1)
                                    {
                                        sub_522CA0((int)v1, &v39.field_0);
                                        if (*v2 == 1)
                                            sub_522CA0((int)v2, &v38.field_0);
                                    }
                                    else
                                    {
                                        sub_522CA0((int)v1, &v38.field_0);
                                        if (*v2 == 1)
                                            sub_522CA0((int)v2, &v39.field_0);
                                    }
                                    sub_521900((int)v1, (int)v2, v32);
                                    v28 = sub_523960(v32);
                                    sub_521900((int)v2, (int)v1, v28);
                                }
                                v19 = v31;
                                v3 = v31;
                                v29 = 1;
                                v2 = v18;
                                if (v18 && *v18 == 1 && v32 == 1)
                                    v2 = 0;
                            }
                            ++a1.field_0;
                            v31 = v19 + 1;
                            if (v19 + 1 >= *((_DWORD*)v1 + 3))
                                goto LABEL_114;
                        }
                    case 2:
                    case 3:
                        if (v4 == 2)
                            a1.field_0 = *((_DWORD*)v1 + 1) + *((_DWORD*)v1 + 3);
                        else
                            a1.field_0 = *((_DWORD*)v1 + 1) - 1;
                        v30 = 0;
                        a1.field_4 = (int)v1[2];
                        if (*((int*)v1 + 4) <= 0)
                            goto LABEL_115;
                        break;
                    default:
                        goto LABEL_115;
                }
                while (1)
                {
                    v5 = sub_521290(&a1);
                    v6 = (int*)v5;
                    if (v5)
                    {
                        if ((int*)v5 != v2)
                            goto LABEL_19;
                        if (*(_BYTE*)(v5 + 52) & 2)
                            ++v29;
                    }
                    if ((int*)v5 != v2 || (v7 = v30, v30 == *((_DWORD*)v1 + 4) - 1))
                    {
                        LABEL_19:
                        if (v2 && v29 >= 3)
                        {
                            if (v32 == 2)
                                v34.field_0 = v1[11];
                            else
                                v34.field_0 = v1[9];
                            v34.field_4 = (double)((v3 + v30) / 2) * 32.526913 + v1[10];
                            sub_527030(&v34);
                            v34.field_4 = v34.field_4 - 16.263456;
                            if (v29 < 4)
                                sub_527940((char*)& byte_587000[198276]);
                            else
                                sub_527940((char*)& byte_587000[198260]);
                            v8 = sub_5279B0(&v34.field_0);
                            if (v8)
                                sub_527C60((int)v8, 7);
                            if (v32 == 2)
                                a2.field_0 = v34.field_0 - 32.526913;
                            else
                                a2.field_0 = v34.field_0;
                            a2.field_4 = v34.field_4;
                            sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
                            if (sub_5238F0(v2))
                            {
                                v9 = a2.field_0;
                                if (v32 == 2)
                                    v10 = v9 + 32.526913;
                                else
                                    v10 = v9 - 32.526913;
                                a2.field_0 = v10;
                                sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
                            }
                            if (v29 < 4)
                            {
                                v15 = v34.field_4 + 16.263456;
                                v36 = v34.field_0;
                            }
                            else
                            {
                                v34.field_4 = v34.field_4 + 16.263456 + 32.526913;
                                sub_527030(&v34);
                                v34.field_4 = v34.field_4 + 16.263456;
                                sub_527940((char*)& byte_587000[198288]);
                                v11 = sub_5279B0(&v34.field_0);
                                if (v11)
                                    sub_527C60((int)v11, 1);
                                v12 = v34.field_4 - 32.526913;
                                v36 = v34.field_0;
                                v37 = v12;
                                if (v32 == 2)
                                    a2.field_0 = v34.field_0 - 32.526913;
                                else
                                    a2.field_0 = v34.field_0;
                                a2.field_4 = v12;
                                sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
                                if (sub_5238F0(v2))
                                {
                                    v13 = a2.field_0;
                                    if (v32 == 2)
                                        v14 = v13 + 32.526913;
                                    else
                                        v14 = v13 - 32.526913;
                                    a2.field_0 = v14;
                                    sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
                                }
                                v15 = v37;
                            }
                            v39.field_0 = v36 - 32.526913;
                            v39.field_4 = v15;
                            v38.field_0 = v36 + 32.526913;
                            v38.field_4 = v15;
                            sub_522C80(&v39.field_0);
                            sub_522C80(&v38.field_0);
                            sub_51D3F0(&v39, &v38);
                            sub_51D3F0(&v38, &v39);
                            if (v32 == 2)
                            {
                                sub_522CA0((int)v1, &v39.field_0);
                                if (*v2 == 1)
                                    sub_522CA0((int)v2, &v38.field_0);
                            }
                            else
                            {
                                sub_522CA0((int)v1, &v38.field_0);
                                if (*v2 == 1)
                                    sub_522CA0((int)v2, &v39.field_0);
                            }
                            sub_521900((int)v1, (int)v2, v32);
                            v16 = sub_523960(v32);
                            sub_521900((int)v2, (int)v1, v16);
                        }
                        v7 = v30;
                        v29 = 1;
                        v3 = v30;
                        v2 = v6;
                        if (v6 && *v6 == 1 && v32 == 3)
                            v2 = 0;
                    }
                    ++a1.field_4;
                    v30 = v7 + 1;
                    if (v7 + 1 >= *((_DWORD*)v1 + 4))
                    {
                        LABEL_114:
                        v4 = v32;
                        break;
                    }
                }
            }
            LABEL_115:
            v32 = ++v4;
            if (v4 >= 4)
                break;
            v2 = 0;
        }
        v2 = 0;
        LABEL_117:
        result = (float*)sub_521720((int)v1);
        v1 = result;
    } while (result);
    return result;
}
// 4D47A7: variable 'v33' is possibly undefined
// 4D4853: variable 'v29' is possibly undefined

//----- (004D4F40) --------------------------------------------------------
float* __cdecl sub_4D4F40(_DWORD* a1)
{
    float* v1; // edi
    float* result; // eax
    double v3; // st7
    int v4; // ebp
    int* v5; // ebx
    float* v6; // esi
    int v7; // eax
    double v8; // st7
    int v9; // esi
    int v10; // edi
    int v11; // ecx
    int v12; // esi
    int* v13; // ebp
    int v14; // edi
    int v15; // ebx
    float* v16; // esi
    int v17; // esi
    int v18; // ebx
    int v19; // edi
    signed int v20; // esi
    int v21; // eax
    float2 v22; // [esp+10h] [ebp-220h]
    int v24; // [esp+18h] [ebp-218h]
    int* v25; // [esp+1Ch] [ebp-214h]
    float* v26; // [esp+20h] [ebp-210h]
    int v27; // [esp+24h] [ebp-20Ch]
    float2 v28; // [esp+28h] [ebp-208h]
    int v30[128]; // [esp+30h] [ebp-200h]

    v1 = 0;
    *(_DWORD*)& byte_5D4594[1550912] = 0;
    if (*a1 == 1)
    {
        v26 = 0;
        v24 = 0;
        v22.field_0 = 0.0;
        v22.field_4 = 0.0;
        v25 = (int*)& byte_587000[197924];
        LABEL_5:
        v4 = 0;
        v5 = &v30[v24];
        v27 = *v25;
        while (1)
        {
            result = (float*)nox_calloc(1u, 0x178u);
            v6 = result;
            *v5 = (int)result;
            if (!result)
                break;
            v7 = v27;
            *(_DWORD*)v6 = v27;
            switch (v7)
            {
                case 2:
                    v22.field_4 = v22.field_4 - 162.63457;
                    *((_DWORD*)v6 + 3) = 4;
                    *((_DWORD*)v6 + 4) = 5;
                    sub_521900((int)v6, (int)v1, 1);
                    sub_521900((int)v1, (int)v6, 0);
                    break;
                case 3:
                    if (*(_DWORD*)v1 == 4)
                    {
                        v22.field_0 = v22.field_0 + 32.526913;
                        v8 = v22.field_4 + 130.10765;
                    }
                    else
                    {
                        v8 = v22.field_4 + 162.63457;
                    }
                    v22.field_4 = v8;
                    *((_DWORD*)v6 + 3) = 4;
                    *((_DWORD*)v6 + 4) = 5;
                    sub_521900((int)v6, (int)v1, 0);
                    sub_521900((int)v1, (int)v6, 1);
                    break;
                case 4:
                    if (v1)
                    {
                        v22.field_0 = v22.field_0 + 162.63457;
                        sub_521900((int)v6, (int)v1, 3);
                        sub_521900((int)v1, (int)v6, 2);
                    }
                    *((_DWORD*)v6 + 3) = 5;
                    *((_DWORD*)v6 + 4) = 4;
                    break;
                case 5:
                    if (*(_DWORD*)v1 == 3)
                        v22.field_4 = v22.field_4 + 32.526913;
                    v22.field_0 = v22.field_0 - 162.63457;
                    *((_DWORD*)v6 + 3) = 5;
                    *((_DWORD*)v6 + 4) = 4;
                    sub_521900((int)v6, (int)v1, 2);
                    sub_521900((int)v1, (int)v6, 3);
                    if (v4 == 5)
                        v26 = v6;
                    break;
                default:
                    break;
            }
            v28.field_0 = v22.field_0 - 878.22662;
            v28.field_4 = v22.field_4 - 878.22662;
            v6[7] = (double) * ((int*)v6 + 3) * 32.526913;
            v6[8] = (double) * ((int*)v6 + 4) * 32.526913;
            sub_521880(v6, &v28);
            sub_521730(v6);
            v1 = v6;
            v9 = v24 + 1;
            ++v5;
            ++v4;
            ++v24;
            if (v4 >= 10)
            {
                ++v25;
                if ((int)v25 < (int)& byte_587000[197940])
                    goto LABEL_5;
                v10 = v30[0];
                v11 = v9;
                v12 = v30[v9 - 1];
                v13 = &v30[v11];
                sub_521900(v12, v30[0], 2);
                sub_521900(v10, v12, 3);
                v14 = (int)v26;
                v15 = 0;
                v22.field_0 = v26[5];
                v22.field_4 = v26[8] + v26[6];
                while (1)
                {
                    result = (float*)nox_calloc(1u, 0x178u);
                    v16 = result;
                    *v13 = (int)result;
                    if (!result)
                        break;
                    *(_DWORD*)result = 3;
                    *((_DWORD*)result + 3) = 4;
                    *((_DWORD*)result + 4) = 5;
                    sub_521900((int)result, v14, 0);
                    sub_521900(v14, (int)v16, 1);
                    v16[7] = (double) * ((int*)v16 + 3) * 32.526913;
                    v16[8] = (double) * ((int*)v16 + 4) * 32.526913;
                    sub_521880(v16, &v22);
                    sub_521730(v16);
                    v14 = (int)v16;
                    v17 = v24 + 1;
                    ++v13;
                    ++v15;
                    v22.field_4 = v22.field_4 + 162.63457;
                    ++v24;
                    if (v15 >= 8)
                    {
                        v18 = v17;
                        v19 = v17 / 5;
                        if (v17 / 5 < 1)
                            v19 = 1;
                        v20 = sub_526AC0(0, v19);
                        do
                        {
                            v21 = v30[v20];
                            *(_DWORD*)(v21 + 84) = *(_DWORD*)& byte_5D4594[1550912];
                            *(_DWORD*)& byte_5D4594[1550912] = v21;
                            v20 += sub_526AC0(1, v19);
                        } while (v20 < v18);
                        result = (float*)v30[v18 - 1];
                        *(_DWORD*)& byte_5D4594[1550916] = v30[v18 - 1];
                        return result;
                    }
                }
                return result;
            }
        }
    }
    else
    {
        result = sub_521990((int)a1);
        *(_DWORD*)& byte_5D4594[1550916] = result;
        if (result)
        {
            v3 = (double)(int)a1[17];
            v22.field_0 = 0.0;
            v22.field_4 = v3 * 32.526913 - result[8] + 97.580734;
            sub_521880(result, &v22);
            sub_521730(*(_DWORD * *)& byte_5D4594[1550916]);
            result = *(float**)& byte_5D4594[1550916];
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1550916] + 84) = *(_DWORD*)& byte_5D4594[1550912];
            *(_DWORD*)& byte_5D4594[1550912] = *(_DWORD*)& byte_5D4594[1550916];
        }
    }
    return result;
}
// 4D4F40: using guessed type int var_200[128];

//----- (004D52F0) --------------------------------------------------------
void sub_4D52F0()
{
    _DWORD* v0; // esi

    v0 = *(_DWORD * *)& byte_5D4594[1550912];
    if (*(_DWORD*)& byte_5D4594[1550912])
    {
        do
        {
            switch (*v0)
            {
                case 1:
                    sub_4D5350(v0, 0, 0, 0, 0);
                    break;
                case 2:
                case 3:
                    sub_4D5350(v0, 0, 0, v0[3], 0);
                    break;
                case 4:
                case 5:
                    sub_4D5350(v0, 0, 0, v0[4], 0);
                    break;
                default:
                    break;
            }
            v0 = (_DWORD*)v0[21];
        } while (v0);
    }
}

//----- (004D5350) --------------------------------------------------------
int __cdecl sub_4D5350(_DWORD* a1, int a2, int a3, int a4, int a5)
{
    int v5; // esi
    int result; // eax

    v5 = a2 + 1;
    if (a2 + 1 >= *(int*)& byte_5D4594[1549868])
        return 0;
    sub_5235F0(155);
    if (*a1 == 1)
        result = sub_4D53B0((int)a1, v5, a3, a4, a5);
    else
        result = sub_4D5630((int)a1, v5, a3, a4, a5);
    return result;
}

//----- (004D53B0) --------------------------------------------------------
int __cdecl sub_4D53B0(int a1, int a2, int a3, int a4, int a5)
{
    float* v5; // ebx
    int v6; // eax
    int v7; // esi
    int v8; // eax
    int v9; // edi
    int v10; // eax
    int v11; // ebp
    int v12; // eax
    int v13; // eax
    signed int v14; // eax
    int v15; // eax
    int v16; // esi
    int v17; // ebp
    float* v18; // esi
    double v19; // st7
    double v20; // st7
    int v21; // eax
    int v22; // eax
    int* v23; // eax
    int v24; // edi
    int v25; // eax
    int v26; // eax
    int v28; // [esp+10h] [ebp-1Ch]
    float2 a2a; // [esp+14h] [ebp-18h]
    int v30; // [esp+1Ch] [ebp-10h]
    int v31; // [esp+20h] [ebp-Ch]
    int v32; // [esp+24h] [ebp-8h]
    int v33; // [esp+28h] [ebp-4h]
    int v34; // [esp+30h] [ebp+4h]

    v5 = (float*)a1;
    v6 = sub_5218B0(a1, 0);
    v7 = v6 != 0 ? 0 : 2;
    v30 = v6 != 0 ? 0 : 2;
    v8 = sub_5218B0(a1, 1);
    v9 = v8 != 0 ? 0 : 3;
    v31 = v8 != 0 ? 0 : 3;
    v10 = sub_5218B0(a1, 2);
    v11 = v10 != 0 ? 0 : 4;
    v32 = v10 != 0 ? 0 : 4;
    v12 = -(sub_5218B0(a1, 3) != 0);
    LOBYTE(v12) = v12 & 0xFB;
    v13 = v12 + 5;
    v33 = v13;
    if (v7 || v9 || v11 || v13)
    {
        v14 = sub_526AC0(0, 3);
        v34 = 0;
        while (1)
        {
            v15 = (v14 + 1) % 4;
            v16 = *(&v30 + v15);
            v28 = v15;
            if (!v16)
                goto LABEL_6;
            v17 = sub_526AC0(
                    *(_DWORD*)& byte_5D4594[1549808] - *(_DWORD*)& byte_5D4594[1549812],
                    *(_DWORD*)& byte_5D4594[1549812] + *(_DWORD*)& byte_5D4594[1549808]);
            v18 = sub_523EC0((int)& byte_5D4594[1549796], v16, v17);
            if (!v18)
                return 0;
            switch (*(_DWORD*)v18)
            {
                case 2:
                    a2a.field_0 = sub_521B00((int)v5, (int)v18);
                    v19 = v5[6] - v18[8];
                    goto LABEL_15;
                case 3:
                    a2a.field_0 = sub_521B00((int)v5, (int)v18);
                    v19 = v5[8] + v5[6];
                    goto LABEL_15;
                case 4:
                    v20 = v5[7] + v5[5];
                    goto LABEL_14;
                case 5:
                    v20 = v5[5] - v18[7];
                LABEL_14:
                    a2a.field_0 = v20;
                    v19 = sub_521B30((int)v5, (int)v18);
                LABEL_15:
                    a2a.field_4 = v19;
                    break;
                default:
                    break;
            }
            sub_521880(v18, &a2a);
            if (!sub_5217A0((int)& byte_5D4594[1549796], (int)v18))
            {
                LABEL_17:
                sub_521A10(v18);
                goto LABEL_26;
            }
            v21 = sub_523920(*(_DWORD*)v18);
            v22 = sub_523960(v21);
            sub_521900((int)v18, (int)v5, v22);
            v23 = (int*)sub_521200((int)v18);
            v24 = (int)v23;
            if (v23)
                break;
            sub_521730(v18);
            if (sub_4D5350(v18, a2, 1, v17, (int)v5))
                goto LABEL_25;
            sub_521760((int)v18);
            sub_521A10(v18);
            LABEL_26:
            if (++v34 >= 8)
                return 1;
            LABEL_6:
            v14 = v28;
        }
        if (sub_5238F0(v23)
            || *(_BYTE*)(v24 + 52) & 2
            || v24 == a5
            || sub_526AC0(1, 100) > * (int*)& byte_5D4594[1549844]
            || !sub_523A10((int)v18, (float*)v24))
        {
            goto LABEL_17;
        }
        sub_521730(v18);
        v25 = sub_523920(*(_DWORD*)v18);
        sub_521A70((int)v18, v24, v25);
        LABEL_25:
        v26 = sub_523920(*(_DWORD*)v18);
        sub_521900((int)v5, (int)v18, v26);
        goto LABEL_26;
    }
    return 1;
}

//----- (004D5630) --------------------------------------------------------
int __cdecl sub_4D5630(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // esi
    int v6; // eax
    int v7; // ebp
    float* v8; // edi
    double v9; // st7
    double v10; // st7
    int v11; // eax
    float* v13; // eax
    float* v14; // edi
    double v15; // st7
    double v16; // st7
    int v17; // eax
    float* v18; // ebp
    int v19; // ebx
    int v20; // eax
    int v21; // eax
    float* v22; // edi
    double v23; // st7
    double v24; // st7
    double v25; // st7
    int v26; // eax
    float* v27; // ebp
    int v28; // ebx
    int v29; // eax
    int v30; // eax
    float* v31; // eax
    int* v32; // edi
    double v33; // st7
    double v34; // st7
    double v35; // st7
    double v36; // st7
    int v37; // eax
    int v38; // eax
    float* v39; // ebp
    int v40; // ebx
    int v41; // eax
    int v42; // eax
    BOOL v43; // [esp+10h] [ebp-14h]
    BOOL v44; // [esp+14h] [ebp-10h]
    int v45; // [esp+18h] [ebp-Ch]
    float2 a2a; // [esp+1Ch] [ebp-8h]
    int v47; // [esp+28h] [ebp+4h]
    int v48; // [esp+28h] [ebp+4h]
    int v49; // [esp+28h] [ebp+4h]

    v5 = a1;
    v43 = 0;
    v44 = 0;
    if (a3 >= *(int*)& byte_5D4594[1549816] || (v6 = sub_4D5D20((_DWORD*)a1), v45 = v6, v6 == 1))
    {
        v7 = 0;
        while (1)
        {
            v8 = sub_521990((int)& byte_5D4594[1549796]);
            if (!v8)
                return 0;
            switch (*(_DWORD*)a1)
            {
                case 2:
                    a2a.field_0 = sub_521B60((int)v8, a1);
                    v9 = *(float*)(a1 + 24) - v8[8];
                    goto LABEL_11;
                case 3:
                    a2a.field_0 = sub_521B60((int)v8, a1);
                    v9 = *(float*)(a1 + 32) + *(float*)(a1 + 24);
                    goto LABEL_11;
                case 4:
                    v10 = *(float*)(a1 + 28) + *(float*)(a1 + 20);
                    goto LABEL_10;
                case 5:
                    v10 = *(float*)(a1 + 20) - v8[7];
                LABEL_10:
                    a2a.field_0 = v10;
                    v9 = sub_521B90((int)v8, a1);
                LABEL_11:
                    a2a.field_4 = v9;
                    break;
                default:
                    break;
            }
            sub_521880(v8, &a2a);
            if (!sub_521820((int)& byte_5D4594[1549796], (int)v8))
            {
                sub_521A10(v8);
                if (++v7 < 10)
                    continue;
            }
            if (v7 == 10)
                return 0;
            sub_521730(v8);
            v11 = sub_523920(*(_DWORD*)a1);
            sub_521A70(a1, (int)v8, v11);
            sub_4D5350(v8, a2, 0, 0, (int)v8);
            return 1;
        }
    }
    if (v6 != 2 && v6 != 8 && v6 != 32 && v6 != 64)
        goto LABEL_43;
    v13 = sub_523EC0((int)& byte_5D4594[1549796], *(_DWORD*)& byte_587000[4 * *(_DWORD*)a1 + 197812], a4);
    v14 = v13;
    if (!v13)
        return 0;
    switch (*(_DWORD*)a1)
    {
        case 2:
            v15 = *(float*)(a1 + 20) - v13[7];
            a2a.field_4 = *(float*)(a1 + 24);
            a2a.field_0 = v15;
            break;
        case 3:
            a2a.field_0 = *(float*)(a1 + 28) + *(float*)(a1 + 20);
            v16 = *(float*)(a1 + 32) + *(float*)(a1 + 24) - v13[8];
            goto LABEL_26;
        case 4:
            a2a.field_0 = *(float*)(a1 + 28) + *(float*)(a1 + 20) - v13[7];
            v16 = *(float*)(a1 + 24) - v13[8];
            goto LABEL_26;
        case 5:
            v16 = *(float*)(a1 + 32) + *(float*)(a1 + 24);
            a2a.field_0 = *(float*)(a1 + 20);
        LABEL_26:
            a2a.field_4 = v16;
            break;
        default:
            break;
    }
    sub_521880(v13, &a2a);
    v47 = sub_5239B0(*(_DWORD*)a1);
    sub_521900((int)v14, v5, v47);
    if (!sub_5217A0((int)& byte_5D4594[1549796], (int)v14))
        goto LABEL_100;
    v17 = sub_521200((int)v14);
    v18 = (float*)v17;
    if (!v17)
    {
        v43 = 1;
        v19 = 0;
        goto LABEL_34;
    }
    if (*(_DWORD*)v17 != 1
        || *(_BYTE*)(v17 + 52) & 2
        || v17 == a5
        || sub_526AC0(1, 100) > * (int*)& byte_5D4594[1549844])
    {
        LABEL_100:
        v43 = 0;
        goto LABEL_41;
    }
    v43 = sub_523A10((int)v14, v18);
    v19 = 1;
    if (!v43)
        goto LABEL_41;
    LABEL_34:
    sub_521730(v14);
    if (!v19)
    {
        if (sub_4D5350(v14, a2, a3 + 1, a4, a5))
            goto LABEL_39;
        sub_521760((int)v14);
        v43 = 0;
        LABEL_41:
        sub_521A10(v14);
        if (v45 == 2 || v45 == 8)
            return 0;
        goto LABEL_43;
    }
    v20 = sub_523920(*(_DWORD*)v14);
    sub_521A70((int)v14, (int)v18, v20);
    LABEL_39:
    v21 = sub_523960(v47);
    sub_521900(v5, (int)v14, v21);
    LABEL_43:
    if (v45 != 4 && v45 != 16 && v45 != 32 && v45 != 64)
        goto LABEL_71;
    v22 = sub_523EC0((int)& byte_5D4594[1549796], *(_DWORD*)& byte_587000[4 * *(_DWORD*)v5 + 197836], a4);
    if (!v22)
        return 0;
    switch (*(_DWORD*)v5)
    {
        case 2:
            v23 = *(float*)(v5 + 28) + *(float*)(v5 + 20);
            a2a.field_4 = *(float*)(v5 + 24);
            a2a.field_0 = v23;
            break;
        case 3:
            a2a.field_0 = *(float*)(v5 + 20) - v22[7];
            v24 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
            goto LABEL_53;
        case 4:
            a2a.field_0 = *(float*)(v5 + 28) + *(float*)(v5 + 20) - v22[7];
            v25 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
            goto LABEL_54;
        case 5:
            v24 = *(float*)(v5 + 24);
            a2a.field_0 = *(float*)(v5 + 20);
        LABEL_53:
            v25 = v24 - v22[8];
        LABEL_54:
            a2a.field_4 = v25;
            break;
        default:
            break;
    }
    sub_521880(v22, &a2a);
    v48 = sub_523970(*(_DWORD*)v5);
    sub_521900((int)v22, v5, v48);
    if (!sub_5217A0((int)& byte_5D4594[1549796], (int)v22))
        goto LABEL_101;
    v26 = sub_521200((int)v22);
    v27 = (float*)v26;
    if (!v26)
    {
        v44 = 1;
        v28 = 0;
        goto LABEL_62;
    }
    if (*(_DWORD*)v26 != 1
        || *(_BYTE*)(v26 + 52) & 2
        || v26 == a5
        || sub_526AC0(1, 100) > * (int*)& byte_5D4594[1549844])
    {
        LABEL_101:
        v44 = 0;
        goto LABEL_69;
    }
    v44 = sub_523A10((int)v22, v27);
    v28 = 1;
    if (!v44)
        goto LABEL_69;
    LABEL_62:
    sub_521730(v22);
    if (!v28)
    {
        if (sub_4D5350(v22, a2, a3 + 1, a4, a5))
            goto LABEL_67;
        sub_521760((int)v22);
        v44 = 0;
        LABEL_69:
        sub_521A10(v22);
        if (v45 == 4 || v45 == 16)
            return 0;
        goto LABEL_71;
    }
    v29 = sub_523920(*(_DWORD*)v22);
    sub_521A70((int)v22, (int)v27, v29);
    LABEL_67:
    v30 = sub_523960(v48);
    sub_521900(v5, (int)v22, v30);
    LABEL_71:
    if (v43 || v44)
    {
        if (v45 != 32 && v45 != 8 && v45 != 16)
            return 1;
        v31 = sub_523EC0((int)& byte_5D4594[1549796], *(_DWORD*)v5, a4);
        v32 = (int*)v31;
        if (v31)
        {
            switch (*(_DWORD*)v5)
            {
                case 2:
                    v33 = *(float*)(v5 + 24);
                    a2a.field_0 = *(float*)(v5 + 20);
                    a2a.field_4 = v33 - v31[8];
                    break;
                case 3:
                    v34 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
                    a2a.field_0 = *(float*)(v5 + 20);
                    a2a.field_4 = v34;
                    break;
                case 4:
                    v35 = *(float*)(v5 + 28) + *(float*)(v5 + 20);
                    a2a.field_4 = *(float*)(v5 + 24);
                    a2a.field_0 = v35;
                    break;
                case 5:
                    v36 = *(float*)(v5 + 20) - v31[7];
                    a2a.field_4 = *(float*)(v5 + 24);
                    a2a.field_0 = v36;
                    break;
                default:
                    break;
            }
            sub_521880(v31, &a2a);
            v37 = sub_523920(*(_DWORD*)v5);
            v49 = sub_523960(v37);
            sub_521900((int)v32, v5, v49);
            if (sub_5217A0((int)& byte_5D4594[1549796], (int)v32))
            {
                v38 = sub_521200((int)v32);
                v39 = (float*)v38;
                if (!v38)
                {
                    v40 = 0;
                    LABEL_89:
                    sub_521730(v32);
                    if (v40)
                    {
                        v41 = sub_523920(*v32);
                        sub_521A70((int)v32, (int)v39, v41);
                        LABEL_96:
                        v42 = sub_523960(v49);
                        sub_521900(v5, (int)v32, v42);
                        return 1;
                    }
                    if (sub_4D5350(v32, a2, a3 + 1, a4, a5))
                        goto LABEL_96;
                    sub_521760((int)v32);
                    goto LABEL_94;
                }
                if (*(_DWORD*)v38 == 1
                    && !(*(_BYTE*)(v38 + 52) & 2)
                    && v38 != a5
                    && sub_526AC0(1, 100) <= *(int*)& byte_5D4594[1549844])
                {
                    v40 = 1;
                    if (sub_523A10((int)v32, v39))
                        goto LABEL_89;
                }
            }
            LABEL_94:
            sub_521A10(v32);
            return 1;
        }
    }
    return 0;
}

//----- (004D5D20) --------------------------------------------------------
int __cdecl sub_4D5D20(_DWORD* a1)
{
    int result; // eax

    if (*a1 == 2 || *a1 == 3)
    {
        if (a1[3] >= a1[4])
            return 1;
    }
    else if (a1[4] >= a1[3])
    {
        return 1;
    }
    if (sub_526AC0(1, 100) > * (int*)& byte_5D4594[1549820])
    {
        if (sub_526AC0(1, 100) > * (int*)& byte_5D4594[1549824])
            result = sub_526AC0(1, 100) >= 50 ? 4 : 2;
        else
            result = 1;
    }
    else
    {
        sub_526AC0(1, 100);
        result = 32;
    }
    return result;
}

//----- (004D5DB0) --------------------------------------------------------
unsigned int __cdecl sub_4D5DB0(int a1)
{
    unsigned int result; // eax
    struct _SYSTEMTIME SystemTime; // [esp+Ch] [ebp-410h]
    CHAR DateStr[1024]; // [esp+1Ch] [ebp-400h]

    strcpy((char*)a1, "Generated Map");
    strcpy((char*)(a1 + 64), "Generated Map");
    *(_WORD*)(a1 + 576) = *(_WORD*)& byte_587000[198380];
    *(_DWORD*)(a1 + 592) = *(_DWORD*)& byte_587000[198384];
    strcpy((char*)(a1 + 656), "http://www.westwood.com");
    strcpy((char*)(a1 + 720), "http://www.westwood.com");
    strcpy((char*)(a1 + 848), "http://www.westwood.com");
    strcpy((char*)(a1 + 976), "Generated Map");
    strcpy((char*)(a1 + 1232), "Westwood Studios");
    GetLocalTime(&SystemTime);
    GetDateFormatA(0x800u, 0, &SystemTime, (LPCSTR)& byte_587000[198496], DateStr, 1024);
    result = strlen(DateStr) + 1;
    qmemcpy((void*)(a1 + 1360), DateStr, result);
    *(_DWORD*)(a1 + 1392) = 3;
    return result;
}

//----- (004D5F30) --------------------------------------------------------
BOOL sub_4D5F30()
{
    int v0; // esi
    int v1; // eax
    char* v2; // eax
    char* v3; // eax
    BOOL result; // eax
    CHAR FileName[1024]; // [esp+8h] [ebp-800h]
    CHAR ExistingFileName[1024]; // [esp+408h] [ebp-400h]

    v0 = 100;
    sub_40A4D0(0x400000);
    memset(&byte_5D4594[3801836], 0, 0x5B8u);
    while (1)
    {
        v1 = sub_4D44E0();
        if (v1 == 1)
            break;
        if (v1)
        {
            if (--v0)
                continue;
        }
        return 0;
    }
    v2 = sub_409E10();
    nox_sprintf(FileName, "%s\\nc.obj", v2);
    v3 = sub_409E10();
    nox_sprintf(ExistingFileName, "%s\\blend.obj", v3);
    result = DeleteFileA(FileName);
    if (!result)
        return result;
    if (!MoveFileA(ExistingFileName, FileName))
        return 0;
    sub_4D5DB0((int)& byte_5D4594[3801836]);
    sub_40A540(0x400000);
    return 1;
}

//----- (004D6000) --------------------------------------------------------
int __cdecl sub_4D6000(int a1)
{
    int result; // eax
    int v2; // esi

    result = 0;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4652) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4656) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4660) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4664) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4668) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4672) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4676) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4680) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4684) = 0;
        *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4688) = sub_4E3CC0();
        result = *(_DWORD*)(v2 + 276);
        *(_DWORD*)(result + 4692) = 63;
    }
    return result;
}

//----- (004D60B0) --------------------------------------------------------
int sub_4D60B0()
{
    int result; // eax
    int i; // esi

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4D6000(i);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D60E0) --------------------------------------------------------
_DWORD* __cdecl sub_4D60E0(int a1)
{
    _DWORD* result; // eax
    int v2; // ecx

    result = (_DWORD*)a1;
    if ((*(_BYTE*)(a1 + 16) & 0x20) != 32)
    {
        v2 = *(_DWORD*)(a1 + 748);
        result = *(_DWORD * *)(v2 + 276);
        if (result[1198] == 1)
        {
            ++result[1163];
            result = *(_DWORD * *)(v2 + 276);
            result[1173] |= 1u;
        }
    }
    return result;
}

//----- (004D6130) --------------------------------------------------------
int __cdecl sub_4D6130(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        if ((*(_BYTE*)(a1 + 16) & 0x20) != 32)
        {
            v2 = *(_DWORD*)(a1 + 748);
            ++* (_DWORD*)(*(_DWORD*)(v2 + 276) + 4660);
            result = *(_DWORD*)(v2 + 276);
            *(_DWORD*)(result + 4692) |= 2u;
        }
    }
    return result;
}

//----- (004D6170) --------------------------------------------------------
int __cdecl sub_4D6170(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        if ((*(_BYTE*)(a1 + 16) & 0x20) != 32)
        {
            v2 = *(_DWORD*)(a1 + 748);
            ++* (_DWORD*)(*(_DWORD*)(v2 + 276) + 4664);
            result = *(_DWORD*)(v2 + 276);
            *(_DWORD*)(result + 4692) |= 4u;
        }
    }
    return result;
}

//----- (004D61B0) --------------------------------------------------------
void __cdecl sub_4D61B0(int a1)
{
    int v2; // eax
    if (a1)
    {
        if ((*(_BYTE*)(a1 + 16) & 0x20) != 32)
        {
            v2 = *(_DWORD*)(a1 + 748);
            ++* (_DWORD*)(*(_DWORD*)(v2 + 276) + 4668);
            int result = *(_DWORD*)(v2 + 276);
            *(_DWORD*)(result + 4692) |= 8u;
        }
    }
}

//----- (004D61F0) --------------------------------------------------------
int __cdecl sub_4D61F0(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        if ((*(_BYTE*)(a1 + 16) & 0x20) != 32)
        {
            v2 = *(_DWORD*)(a1 + 748);
            ++* (_DWORD*)(*(_DWORD*)(v2 + 276) + 4672);
            ++* (_DWORD*)(*(_DWORD*)(v2 + 276) + 4676);
            result = *(_DWORD*)(v2 + 276);
            *(_DWORD*)(result + 4692) |= 0x10u;
        }
    }
    return result;
}

//----- (004D6240) --------------------------------------------------------
int __cdecl sub_4D6240(int a1, int a2)
{
    int result; // eax
    int v3; // eax

    result = a1;
    if (a1)
    {
        if ((*(_BYTE*)(a1 + 16) & 0x20) != 32)
        {
            v3 = *(_DWORD*)(a1 + 748);
            *(_DWORD*)(*(_DWORD*)(v3 + 276) + 4684) += a2;
            result = *(_DWORD*)(v3 + 276);
            *(_DWORD*)(result + 4692) |= 0x20u;
        }
    }
    return result;
}

//----- (004D6290) --------------------------------------------------------
int __cdecl sub_4D6290(int a1)
{
    int result; // eax
    int v2; // eax
    char v3[16]; // [esp+0h] [ebp-10h]

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        v3[0] = -16;
        v3[1] = 11;
        *(_WORD*)& v3[2] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4652);
        *(_WORD*)& v3[4] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4656);
        *(_WORD*)& v3[6] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4660);
        *(_WORD*)& v3[8] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4664);
        *(_WORD*)& v3[10] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4668);
        *(_WORD*)& v3[12] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4672);
        *(_WORD*)& v3[14] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4684);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v3, 16, 0, 1);
    }
    return result;
}

//----- (004D6360) --------------------------------------------------------
int __cdecl sub_4D6360(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOWORD(a1) = 1520;
        HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4652);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
    }
    return result;
}

//----- (004D63B0) --------------------------------------------------------
int __cdecl sub_4D63B0(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOWORD(a1) = 1776;
        HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4660);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
    }
    return result;
}

//----- (004D6400) --------------------------------------------------------
int __cdecl sub_4D6400(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOWORD(a1) = 2032;
        HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4664);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
    }
    return result;
}

//----- (004D6450) --------------------------------------------------------
int __cdecl sub_4D6450(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOWORD(a1) = 2288;
        HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4668);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
    }
    return result;
}

//----- (004D64A0) --------------------------------------------------------
int __cdecl sub_4D64A0(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOWORD(a1) = 2544;
        HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4672);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
    }
    return result;
}

//----- (004D64F0) --------------------------------------------------------
int __cdecl sub_4D64F0(int a1)
{
    int result; // eax
    int v2; // eax

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOWORD(a1) = 2800;
        HIWORD(a1) = *(_WORD*)(*(_DWORD*)(v2 + 276) + 4684);
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 4, 0, 1);
    }
    return result;
}

//----- (004D6540) --------------------------------------------------------
unsigned int __cdecl sub_4D6540(int a1)
{
    int v1; // edi
    unsigned int* v2; // eax
    unsigned int* v3; // ebx
    unsigned int result; // eax
    unsigned int v5; // ebp
    int i; // edi
    unsigned int* v7; // esi
    unsigned int v8; // eax
    int v9; // eax
    float v10; // [esp+0h] [ebp-28h]
    unsigned int v11; // [esp+14h] [ebp-14h]
    unsigned int v12; // [esp+18h] [ebp-10h]
    float v13; // [esp+20h] [ebp-8h]
    unsigned int v14; // [esp+2Ch] [ebp+4h]

    v1 = sub_4E3CE0();
    v2 = (unsigned int*)sub_417090(a1);
    v3 = v2;
    if (!v2 || !v2[1198])
        return 0;
    if (v1 == 1)
    {
        result = sub_4D66E0(v2[1167], v2[1168], v2[1166], v2[1172]);
    }
    else
    {
        v5 = 0;
        v11 = 0;
        v14 = 0;
        v12 = 1;
        v13 = 1.0;
        for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
        {
            v7 = *(unsigned int**)(*(_DWORD*)(i + 748) + 276);
            if (v3[1198])
            {
                v8 = sub_4D66E0(v7[1167], v7[1168], 0, v7[1172]);
                if (v8 > v5)
                    v5 = v8;
                v11 += v7[1167];
                v12 = v7[1172];
                v14 += v7[1168];
            }
        }
        v9 = sub_4D66E0(v11, v14, 0, v12);
        if (v5 > 0)
            v13 = (double)(unsigned int)v9 / (double)v5;
        v10 = (double)(unsigned int)sub_4D66E0(v3[1167], v3[1168], v3[1166], v3[1172]) * v13;
        result = sub_419A70(v10);
    }
    if (result > 0x3B9AC9FF)
        result = 999999999;
    return result;
}

//----- (004D66E0) --------------------------------------------------------
int __cdecl sub_4D66E0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
    float v5; // [esp+4h] [ebp-10h]

    v5 = sub_419AF0(pow((double)a4, *(long double*)& byte_581450[10088]))
         * ((double)a1 * 10.0 + (double)a2 * 35.0 + (double)a3 * 0.1);
    return sub_419A70(v5);
}

//----- (004D6770) --------------------------------------------------------
int __cdecl sub_4D6770(int a1)
{
    char* v1; // ebp
    int v2; // ebx
    int v3; // edi
    char* v4; // esi
    int v5; // eax
    char v7[90]; // [esp+Ch] [ebp-5Ch]

    v1 = sub_417090(a1);
    memset(v7, 0, 0x58u);
    *(_WORD*)& v7[88] = 0;
    v7[0] = -16;
    v7[1] = 12;
    *(_WORD*)& v7[2] = sub_4D7300();
    v2 = 0;
    v3 = sub_4DA7C0();
    if (v3)
    {
        v4 = &v7[8];
        do
        {
            v5 = *(_DWORD*)(v3 + 748);
            if (*(_DWORD*)(*(_DWORD*)(v5 + 276) + 4792) == 1 && v2 < 6)
            {
                *((_WORD*)v4 - 1) = *(_WORD*)(v3 + 36);
                *(_WORD*)v4 = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4668);
                *((_WORD*)v4 + 3) = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4664);
                *((_WORD*)v4 + 1) = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4672);
                *((_WORD*)v4 + 2) = *(_WORD*)(*(_DWORD*)(v5 + 276) + 4680);
                *((_DWORD*)v4 + 2) = sub_4D6540(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064));
                ++v2;
                v4 += 14;
                *(_WORD*)& v7[4] = *((_WORD*)v1 + 2344);
            }
            v3 = sub_4DA7F0(v3);
        } while (v3);
    }
    return sub_4E5390(a1, (int)v7, 90, 0, 1);
}

//----- (004D6880) --------------------------------------------------------
int __cdecl sub_4D6880(int a1, int a2)
{
    char v3[69]; // [esp+8h] [ebp-48h]

    memset(v3, 0, 0x44u);
    v3[68] = 0;
    v3[0] = -16;
    v3[1] = 13;
    if (a2)
        v3[4] |= 1u;
    if (sub_51A950())
        v3[4] |= 2u;
    *(_WORD*)& v3[2] = sub_4E3CC0();
    sub_409B30();
    strcpy(&v3[5], sub_4D6940());
    sub_409B30();
    strcpy(&v3[37], sub_4D6950());
    return sub_4E5390(a1, (int)v3, 69, 0, 1);
}

//----- (004D6940) --------------------------------------------------------
char* sub_4D6940()
{
    return (char*)& byte_5D4594[3803266];
}

//----- (004D6950) --------------------------------------------------------
char* sub_4D6950()
{
    return (char*)& byte_5D4594[3803234];
}

//----- (004D6960) --------------------------------------------------------
int __cdecl sub_4D6960(int a1)
{
    char v2[69]; // [esp+8h] [ebp-48h]

    memset(v2, 0, 0x44u);
    v2[68] = 0;
    v2[0] = -16;
    v2[1] = 14;
    v2[4] = 0;
    if (sub_51A950())
        v2[4] |= 2u;
    *(_WORD*)& v2[2] = sub_4E3CC0();
    sub_409B30();
    strcpy(&v2[5], sub_4D6940());
    sub_409B30();
    strcpy(&v2[37], sub_4D6950());
    return sub_4E5390(a1, (int)v2, 69, 0, 1);
}

//----- (004D6A20) --------------------------------------------------------
int __cdecl sub_4D6A20(int a1, int a2)
{
    __int16 v3; // cx
    int v5; // [esp+0h] [ebp-4h]

    v3 = *(_WORD*)(a2 + 40);
    LOWORD(v5) = 4080;
    HIWORD(v5) = v3;
    return sub_4E5420(a1, &v5, 4, 0, 1);
}

//----- (004D6A60) --------------------------------------------------------
int sub_4D6A60()
{
    int result; // eax
    int i; // esi

    *(_DWORD*)& byte_587000[312784] = 1077936128;
    *(_DWORD*)& byte_587000[312788] = 1065353216;
    *(_DWORD*)& byte_587000[312792] = 1065353216;
    *(_DWORD*)& byte_587000[312796] = 1065353216;
    *(_DWORD*)& byte_587000[312800] = 1077936128;
    *(_DWORD*)& byte_587000[312804] = 1077936128;
    *(_DWORD*)& byte_587000[312808] = 1065353216;
    *(_DWORD*)& byte_587000[312812] = 1065353216;
    *(_DWORD*)& byte_587000[312816] = 1077936128;
    *(_DWORD*)& byte_587000[312820] = 1077936128;
    *(_DWORD*)& byte_587000[312824] = 1065353216;
    *(_DWORD*)& byte_587000[312828] = 1065353216;
    sub_57B200();
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4EEDC0(i, 0);
        sub_4D9C20(i);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D6B10) --------------------------------------------------------
int __cdecl sub_4D6B10(int a1)
{
    int result; // eax
    int i; // esi

    *(_DWORD*)& byte_587000[312784] = *(_DWORD*)& byte_5D4594[1556076];
    *(_DWORD*)& byte_587000[312788] = *(_DWORD*)& byte_5D4594[1556084];
    *(_DWORD*)& byte_587000[312792] = *(_DWORD*)& byte_5D4594[1556064];
    *(_DWORD*)& byte_587000[312796] = *(_DWORD*)& byte_5D4594[1556072];
    *(_DWORD*)& byte_587000[312800] = *(_DWORD*)& byte_5D4594[1556060];
    *(_DWORD*)& byte_587000[312804] = *(_DWORD*)& byte_5D4594[1556096];
    *(_DWORD*)& byte_587000[312808] = *(_DWORD*)& byte_5D4594[1550932];
    *(_DWORD*)& byte_587000[312812] = *(_DWORD*)& byte_5D4594[1556080];
    *(_DWORD*)& byte_587000[312816] = *(_DWORD*)& byte_5D4594[1556088];
    *(_DWORD*)& byte_587000[312820] = *(_DWORD*)& byte_5D4594[1556068];
    *(_DWORD*)& byte_587000[312824] = *(_DWORD*)& byte_5D4594[1556100];
    *(_DWORD*)& byte_587000[312828] = *(_DWORD*)& byte_5D4594[1556092];
    sub_57B200();
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4EEDC0(i, 0);
        if (a1)
            sub_4D9C20(i);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D6BE0) --------------------------------------------------------
int sub_4D6BE0()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1556076] = *(_DWORD*)& byte_587000[312784];
    *(_DWORD*)& byte_5D4594[1556084] = *(_DWORD*)& byte_587000[312788];
    *(_DWORD*)& byte_5D4594[1556064] = *(_DWORD*)& byte_587000[312792];
    *(_DWORD*)& byte_5D4594[1556072] = *(_DWORD*)& byte_587000[312796];
    *(_DWORD*)& byte_5D4594[1556060] = *(_DWORD*)& byte_587000[312800];
    *(_DWORD*)& byte_5D4594[1556096] = *(_DWORD*)& byte_587000[312804];
    *(_DWORD*)& byte_5D4594[1550932] = *(_DWORD*)& byte_587000[312808];
    result = *(_DWORD*)& byte_587000[312820];
    *(_DWORD*)& byte_5D4594[1556080] = *(_DWORD*)& byte_587000[312812];
    *(_DWORD*)& byte_5D4594[1556088] = *(_DWORD*)& byte_587000[312816];
    *(_DWORD*)& byte_5D4594[1556068] = *(_DWORD*)& byte_587000[312820];
    *(_DWORD*)& byte_5D4594[1556100] = *(_DWORD*)& byte_587000[312824];
    *(_DWORD*)& byte_5D4594[1556092] = *(_DWORD*)& byte_587000[312828];
    return result;
}

//----- (004D6C70) --------------------------------------------------------
int sub_4D6C70()
{
    int* v0; // ebp
    int v1; // eax
    int i; // eax
    int v3; // edi
    int v4; // ebx
    int v5; // eax
    int v6; // esi
    int v7; // eax
    int v8; // eax
    char v9; // al
    _DWORD* v10; // esi
    int v11; // eax
    int v12; // eax
    char* v13; // eax
    char* v14; // edi
    wchar_t* v15; // eax
    int j; // esi
    unsigned __int8 v18[20]; // [esp+10h] [ebp-14h]

    sub_40A540(6128);
    sub_40A4D0(4096);
    v0 = 0;
    if (!sub_4D6F30())
        sub_4E3CD0(0);
    sub_4D0F30();
    v1 = *(_DWORD*)& byte_5D4594[2650636];
    LOBYTE(v1) = byte_5D4594[2650636] & 0xEF;
    *(_DWORD*)& byte_5D4594[2650636] = v1;
    sub_40A540(0x10000);
    sub_4D9CF0(255);
    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
        * (_DWORD*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 4792) = 0;
    v3 = sub_4DA7C0();
    if (v3)
    {
        while (1)
        {
            sub_4D6000(v3);
            v4 = *(_DWORD*)(v3 + 748);
            if (sub_40A5C0(1)
                && *(_DWORD*)& byte_5D4594[2650636] & 0x40000
                && (v5 = *(_DWORD*)(v4 + 276), *(_BYTE*)(v5 + 2064) == 31))
            {
                *(_DWORD*)(v5 + 4792) = v0;
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(v4 + 276) + 4792) = sub_4E4100();
            }
            if (*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4792) == 1)
                sub_4D9D20(255, v3);
            sub_4EFE80(v3);
            sub_4FA5D0(v3, *(_DWORD*)(*(_DWORD*)(v4 + 276) + 2164));
            v6 = *(_DWORD*)(v3 + 504);
            if ((int*)v6 != v0)
                break;
            LABEL_21:
            v9 = *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251);
            if (v9)
            {
                if (v9 == 1)
                {
                    v10 = sub_4EF750(v3, (CHAR*)& byte_587000[198552], v0, 1, 1);
                    *(_DWORD*)v18 = v0;
                    *(_DWORD*)& v18[4] = v0;
                    v11 = sub_413290("Replenishment1");
                    *(_DWORD*)& v18[8] = sub_413330(v11);
                    *(_DWORD*)& v18[12] = v0;
                    *(_WORD*)& v18[16] = (_WORD)v0;
                    *(_WORD*)& v18[18] = (_WORD)v0;
                    sub_4E4990((int)v10, (int*)v18);
                }
                else if (v9 == 2)
                {
                    sub_4EF750(v3, (CHAR*)& byte_587000[198588], v0, 1, 1);
                }
            }
            else
            {
                sub_4EF750(v3, (CHAR*)& byte_587000[198544], v0, 1, 1);
            }
            v12 = *(_DWORD*)(v4 + 276);
            if (*(int**)(v12 + 4792) == v0)
                sub_4E6860(v12, (char)v0, (int)v0);
            v3 = sub_4DA7F0(v3);
            if ((int*)v3 == v0)
                goto LABEL_30;
        }
        while (1)
        {
            v7 = *(_DWORD*)(v6 + 8);
            v0 = *(int**)(v6 + 496);
            if (!(v7 & 0x1000000))
                break;
            v8 = *(_DWORD*)(v6 + 12);
            if (v8 & 0x8200)
                goto LABEL_19;
            LABEL_20:
            v6 = (int)v0;
            if (!v0)
                goto LABEL_21;
        }
        if (!(v7 & 0x2000000) || sub_415D10((char*) * (unsigned __int16*)(v6 + 4)) & 0x405)
            goto LABEL_20;
        LABEL_19:
        sub_4E5CC0(v6);
        goto LABEL_20;
    }
    LABEL_30:
    sub_417D50(4);
    sub_419030(1);
    v13 = sub_4186D0((char)v0);
    v14 = v13;
    v13[56] = 9;
    v15 = sub_418C20(9);
    if (v15 != (wchar_t*)v0)
        sub_418800((wchar_t*)v14, v15, 1);
    sub_4184D0((wchar_t*)v14);
    for (j = sub_4DA7C0(); (int*)j != v0; j = sub_4DA7F0(j))
    {
        if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(j + 748) + 276) + 4792) == 1)
            sub_4191D0(v14[57], j + 48, 1, *(_DWORD*)(j + 36), (int)v0);
    }
    sub_4D6BE0();
    return sub_4D6A60();
}

//----- (004D6F30) --------------------------------------------------------
int sub_4D6F30()
{
    return *(_DWORD*)& byte_5D4594[1556156];
}

//----- (004D6F40) --------------------------------------------------------
int __cdecl sub_4D6F40(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556156] = a1;
    return result;
}

//----- (004D6F50) --------------------------------------------------------
int sub_4D6F50()
{
    return *(_DWORD*)& byte_5D4594[1556160];
}

//----- (004D6F60) --------------------------------------------------------
int __cdecl sub_4D6F60(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556160] = a1;
    return result;
}

//----- (004D6F70) --------------------------------------------------------
int sub_4D6F70()
{
    return *(_DWORD*)& byte_5D4594[1556164];
}

//----- (004D6F80) --------------------------------------------------------
int __cdecl sub_4D6F80(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556164] = a1;
    return result;
}

//----- (004D6F90) --------------------------------------------------------
int __cdecl sub_4D6F90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556104] = a1;
    return result;
}

//----- (004D6FA0) --------------------------------------------------------
int sub_4D6FA0()
{
    return *(_DWORD*)& byte_5D4594[1556104];
}

//----- (004D6FB0) --------------------------------------------------------
int __cdecl sub_4D6FB0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556148] = a1;
    return result;
}

//----- (004D6FC0) --------------------------------------------------------
int sub_4D6FC0()
{
    return *(_DWORD*)& byte_5D4594[1556148];
}

//----- (004D6FD0) --------------------------------------------------------
char* sub_4D6FD0()
{
    char* result; // eax
    unsigned __int8* v1; // esi
    unsigned __int8 v2; // dl
    char* v3; // edi
    char* v4; // eax
    char v5[64]; // [esp+0h] [ebp-40h]

    result = *(char**)& byte_5D4594[1556148];
    if (*(_DWORD*)& byte_5D4594[1556148])
    {
        result = (char*)(*(_DWORD*)& byte_5D4594[1556148] - 1);
        *(_DWORD*)& byte_5D4594[1556148] = result;
        if (!result)
        {
            v1 = sub_4DCED0();
            sub_4D6C70();
            if (v1 && strlen((const char*)v1))
            {
                v2 = byte_587000[198596];
                strcpy(v5, (const char*)v1);
                v3 = &v5[strlen(v5)];
                v4 = v5;
                *(_DWORD*)v3 = *(_DWORD*)& byte_587000[198592];
                v3[4] = v2;
            }
            else
            {
                v4 = sub_4D0F60();
            }
            sub_4D2450(v4);
            sub_4DCE80(0);
            sub_4E3CD0(0);
            result = sub_4169F0();
        }
    }
    return result;
}
// 4D6FD0: using guessed type char var_40[64];

//----- (004D7080) --------------------------------------------------------
int sub_4D7080()
{
    *(_DWORD*)& byte_5D4594[1556112] = 1;
    sub_44E0B0(1);
    *(_DWORD*)& byte_5D4594[1556152] = sub_416A00();
    sub_4169E0();
    return sub_4D6FB0(30);
}

//----- (004D70B0) --------------------------------------------------------
char* sub_4D70B0()
{
    char* result; // eax

    result = *(char**)& byte_5D4594[1556152];
    if (!*(_DWORD*)& byte_5D4594[1556152])
        result = sub_4169F0();
    return result;
}

//----- (004D70C0) --------------------------------------------------------
BOOL __cdecl sub_4D70C0(int a1)
{
    return sub_40A5C0(4096) || a1 != 37 && a1 != 38 && a1 != 40 && a1 != 39;
}

//----- (004D7100) --------------------------------------------------------
BOOL __cdecl sub_4D7100(int a1)
{
    return sub_40A5C0(4096) || a1 != 111 && a1 != 112 && a1 != 114 && a1 != 113;
}

//----- (004D7140) --------------------------------------------------------
int __cdecl sub_4D7140(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556144] = a1;
    return result;
}

//----- (004D7150) --------------------------------------------------------
int sub_4D7150()
{
    int result; // eax
    int i; // edi
    int* v2; // esi
    int v3; // eax

    result = *(_DWORD*)& byte_5D4594[1556144];
    if (*(_DWORD*)& byte_5D4594[1556144])
    {
        if (*(_DWORD*)& byte_5D4594[2598000] > * (int*)& byte_5D4594[1556144])
        {
            result = sub_4DA7C0();
            for (i = result; result; i = result)
            {
                v2 = *(int**)(i + 748);
                v3 = v2[69];
                if ((*(_BYTE*)(v3 + 3680) & 1) == 1
                    && *(_DWORD*)(v3 + 4792) == 1
                    && !v2[78]
                    && !v2[79]
                    && (*(_DWORD*)(v3 + 3680) & 0x10) == 16)
                {
                    sub_4DF3C0(v2[69]);
                    sub_4E6AA0(v2[69]);
                    sub_4E6040(i);
                }
                result = sub_4DA7F0(i);
            }
        }
    }
    return result;
}

//----- (004D71E0) --------------------------------------------------------
int __cdecl sub_4D71E0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556136] = a1;
    return result;
}

//----- (004D71F0) --------------------------------------------------------
unsigned int sub_4D71F0()
{
    unsigned int result; // eax
    int v1; // esi
    char v2; // al

    result = *(_DWORD*)& byte_5D4594[1556136];
    if (*(_DWORD*)& byte_5D4594[1556136])
    {
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1556136]) >= 0x2328)
        {
            v1 = 0;
            result = sub_4DA7C0();
            if (result)
            {
                do
                {
                    if (*(_DWORD*)(*(_DWORD*)(result + 748) + 308))
                        v1 = 1;
                    result = sub_4DA7F0(result);
                } while (result);
                if (v1)
                {
                    result = sub_4E3CE0();
                    if (result > 1)
                    {
                        sub_4D71E0(0);
                        result = sub_4D72C0();
                        if (!result)
                        {
                            sub_4D72B0(1);
                            v2 = sub_4D72C0();
                            result = sub_4D7280(255, v2);
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (004D7280) --------------------------------------------------------
int __cdecl sub_4D7280(int a1, char a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = -16;
    v4[1] = 24;
    v4[2] = a2;
    return sub_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (004D72B0) --------------------------------------------------------
int __cdecl sub_4D72B0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556140] = a1;
    return result;
}

//----- (004D72C0) --------------------------------------------------------
int sub_4D72C0()
{
    return *(_DWORD*)& byte_5D4594[1556140];
}

//----- (004D72D0) --------------------------------------------------------
int __cdecl sub_4D72D0(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1556128];
    *(_DWORD*)& byte_5D4594[1556132] = *(_DWORD*)& byte_5D4594[1556128];
    *(_DWORD*)& byte_5D4594[1556128] = a1;
    return result;
}

//----- (004D72F0) --------------------------------------------------------
int sub_4D72F0()
{
    return *(_DWORD*)& byte_5D4594[1556128];
}

//----- (004D7300) --------------------------------------------------------
int sub_4D7300()
{
    return *(_DWORD*)& byte_5D4594[1556132];
}

//----- (004D7310) --------------------------------------------------------
int sub_4D7310()
{
    int v0; // ebx
    int v1; // ebp
    int v2; // esi
    int v3; // edi
    int i; // eax

    v0 = 0;
    v1 = 99999;
    v2 = sub_4DA7C0();
    if (!v2)
        return 0;
    do
    {
        if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 4792) == 1)
        {
            v3 = 0;
            for (i = sub_4E7980(v2); i; i = sub_4E7990(i))
            {
                if (*(_BYTE*)(i + 8) & 0x40)
                    ++v3;
            }
            if (v3 <= v1)
            {
                v1 = v3;
                v0 = v2;
            }
        }
        v2 = sub_4DA7F0(v2);
    } while (v2);
    return v0;
}

//----- (004D7390) --------------------------------------------------------
void __cdecl sub_4D7390(int a1)
{
    int v1; // esi
    int v2; // ebx
    int v3; // edi

    if (a1)
    {
        if (sub_4E3CE0())
        {
            v1 = sub_4E7980(a1);
            if (v1)
            {
                do
                {
                    v2 = sub_4E7990(v1);
                    if (*(_BYTE*)(v1 + 8) & 0x40)
                    {
                        v3 = sub_4D7310();
                        if (v3)
                        {
                            sub_4ED0C0(a1, (int*)v1);
                            sub_4F3070(v3, v1, 1);
                            sub_4DA2C0(v3, "GeneralPrint:GainedKey", 0);
                            sub_501960(820, v3, 0, 0);
                        }
                    }
                    v1 = v2;
                } while (v2);
            }
            sub_4EDD00(a1, 64);
        }
        else
        {
            sub_4EDD00(a1, 64);
        }
    }
}

//----- (004D7430) --------------------------------------------------------
int sub_4D7430()
{
    return *(_DWORD*)& byte_5D4594[1556116];
}

//----- (004D7440) --------------------------------------------------------
int __cdecl sub_4D7440(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556116] = a1;
    return result;
}

//----- (004D7450) --------------------------------------------------------
int __cdecl sub_4D7450(int a1, __int16 a2)
{
    char v3[4]; // [esp+0h] [ebp-4h]

    v3[0] = -16;
    v3[1] = 29;
    *(_WORD*)& v3[2] = a2;
    return sub_4E5420(a1, v3, 4, 0, 1);
}

//----- (004D7480) --------------------------------------------------------
void __cdecl sub_4D7480(int a1)
{
    int v1; // edi
    int v2; // eax
    float2* v3; // ebx

    if (a1 && *(_BYTE*)(a1 + 8) & 4)
    {
        v1 = *(_DWORD*)(a1 + 748);
        v2 = *(_DWORD*)(v1 + 316);
        if (v2)
        {
            v3 = *(float2 * *)(v2 + 700);
            sub_4E6AA0(*(_DWORD*)(v1 + 276));
            sub_4E6040(a1);
            *(_DWORD*)(v1 + 316) = 0;
            sub_4E7010(a1, v3 + 10);
            sub_501960(312, a1, 2, *(_DWORD*)(a1 + 36));
            sub_522FF0(129, v3 + 10);
        }
    }
}

//----- (004D74F0) --------------------------------------------------------
int __cdecl sub_4D74F0(int a1)
{
    int result; // eax

    result = a1;
    if (a1 <= 4)
        return 5;
    if (a1 <= 9)
        return 10;
    if (a1 <= 14)
        return 15;
    if (a1 <= 19)
        result = 20;
    return result;
}

//----- (004D7520) --------------------------------------------------------
char __cdecl sub_4D7520(int a1)
{
    int v1; // eax
    int i; // esi
    int v3; // eax
    int v4; // esi
    int v5; // edi

    LOBYTE(v1) = byte_5D4594[1556120];
    if (*(_DWORD*)& byte_5D4594[1556120] == 1)
    {
        if (a1)
            goto LABEL_19;
        for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
        {
            v3 = *(_DWORD*)(i + 748);
            if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4792) && *(_DWORD*)(v3 + 316))
                sub_4D7480(i);
        }
        v1 = sub_4DA790();
        v4 = v1;
        if (!v1)
        {
            LABEL_19:
            *(_DWORD*)& byte_5D4594[1556120] = a1;
        }
        else
        {
            do
            {
                v5 = sub_4DA7A0(v4);
                LOBYTE(v1) = *(_BYTE*)(v4 + 8);
                if (v1 & 0x20 && *(_BYTE*)(v4 + 12) & 2)
                    LOBYTE(v1) = sub_4E7600(v4);
                v4 = v5;
            } while (v5);
            *(_DWORD*)& byte_5D4594[1556120] = 0;
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1556120] = a1;
    }
    return v1;
}

//----- (004D75E0) --------------------------------------------------------
int sub_4D75E0()
{
    return *(_DWORD*)& byte_5D4594[1556120];
}

//----- (004D75F0) --------------------------------------------------------
int __cdecl sub_4D75F0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556108] = a1;
    return result;
}

//----- (004D7600) --------------------------------------------------------
int sub_4D7600()
{
    int v0; // edi
    int v1; // esi
    int result; // eax
    int v3; // ecx
    int i; // esi
    int v5; // eax

    v0 = sub_4E3CE0();
    v1 = 0;
    result = *(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1556108];
    if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1556108]) >= 0x1E && v0)
    {
        for (result = sub_4DA7C0(); result; result = sub_4DA7F0(result))
        {
            v3 = *(_DWORD*)(result + 748);
            if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4792) && *(_DWORD*)(v3 + 316))
                ++v1;
        }
        if (v0 == v1)
        {
            result = sub_4E8F60();
            if (!result)
            {
                result = sub_4DA7C0();
                for (i = result; result; i = result)
                {
                    v5 = *(_DWORD*)(i + 748);
                    if (*(_DWORD*)(*(_DWORD*)(v5 + 276) + 4792) && *(_DWORD*)(v5 + 316))
                    {
                        sub_4D7480(i);
                        if (v0 <= 1)
                            sub_4DA2C0(i, "Gauntlet.c:WarpRestrictedSolo", 0);
                        else
                            sub_4DA2C0(i, "Gauntlet.c:WarpRestrictedMulti", 0);
                    }
                    result = sub_4DA7F0(i);
                }
            }
        }
    }
    return result;
}

//----- (004D76E0) --------------------------------------------------------
int __cdecl sub_4D76E0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556124] = a1;
    return result;
}

//----- (004D76F0) --------------------------------------------------------
int sub_4D76F0()
{
    return *(_DWORD*)& byte_5D4594[1556124];
}

//----- (004D7700) --------------------------------------------------------
bool sub_4D7700()
{
    HKEY phkResult; // [esp+8h] [ebp-90h]
    BYTE Data[4]; // [esp+Ch] [ebp-8Ch]
    DWORD cbData; // [esp+10h] [ebp-88h]
    DWORD Type; // [esp+14h] [ebp-84h]
    CHAR SubKey[128]; // [esp+18h] [ebp-80h]

    strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
    *(_DWORD*)Data = -1;
    cbData = 4;
    if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult))
    {
        RegQueryValueExA(phkResult, (LPCSTR)& byte_587000[198712], 0, &Type, Data, &cbData);
        RegCloseKey(phkResult);
    }
    return *(_DWORD*)Data >= 9472;
}

//----- (004D7790) --------------------------------------------------------
BOOL sub_4D7790()
{
    char* v0; // eax
    CHAR FileName[1024]; // [esp+0h] [ebp-400h]

    v0 = sub_409E10();
    nox_sprintf(FileName, "%s\\Maps\\G_Lava", v0);
    return _access(FileName, 0) == 0;
}

//----- (004D77D0) --------------------------------------------------------
LSTATUS __cdecl sub_4D77D0(int a1)
{
    LSTATUS result; // eax
    BYTE Data[4]; // [esp+0h] [ebp-88h]
    HKEY phkResult; // [esp+4h] [ebp-84h]
    CHAR SubKey[128]; // [esp+8h] [ebp-80h]

    result = a1 - 4096;
    switch (a1)
    {
        case 4096:
            *(_DWORD*)Data = 9472;
            goto LABEL_8;
        case 4098:
            *(_DWORD*)Data = 9474;
            goto LABEL_8;
        case 4099:
            *(_DWORD*)Data = 9475;
            goto LABEL_8;
        case 4101:
            *(_DWORD*)Data = 9477;
            goto LABEL_8;
        case 4102:
            *(_DWORD*)Data = 9478;
            goto LABEL_8;
        case 4105:
            *(_DWORD*)Data = 9481;
        LABEL_8:
            strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
            result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
            if (!result)
            {
                RegSetValueExA(phkResult, (LPCSTR)& byte_587000[198756], 0, 4u, Data, 4u);
                result = RegCloseKey(phkResult);
            }
            break;
        default:
            return result;
    }
    return result;
}

//----- (004D78C0) --------------------------------------------------------
LSTATUS sub_4D78C0()
{
    LSTATUS result; // eax
    BYTE Data[4]; // [esp+8h] [ebp-90h]
    HKEY phkResult; // [esp+Ch] [ebp-8Ch]
    DWORD cbData; // [esp+10h] [ebp-88h]
    DWORD Type; // [esp+14h] [ebp-84h]
    CHAR SubKey[128]; // [esp+18h] [ebp-80h]

    strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
    *(_DWORD*)Data = -1;
    cbData = 4;
    result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
    if (!result)
    {
        RegQueryValueExA(phkResult, (LPCSTR)& byte_587000[198784], 0, &Type, Data, &cbData);
        result = RegCloseKey(phkResult);
    }
    if (*(int*)Data < 9472)
    {
        result = sub_4D7790();
        if (result == 1)
            result = sub_4D77D0(*(int*)Data);
    }
    return result;
}

//----- (004D7960) --------------------------------------------------------
int __cdecl sub_4D7960(char a1)
{
    int result; // eax

    result = 1 << a1;
    *(_DWORD*)& byte_5D4594[1556300] |= 1 << a1;
    return result;
}

//----- (004D7980) --------------------------------------------------------
BOOL __cdecl sub_4D7980(char a1)
{
    return (*(_DWORD*)& byte_5D4594[1556300] & (1 << a1)) != 0;
}

//----- (004D79A0) --------------------------------------------------------
int __cdecl sub_4D79A0(char a1)
{
    int result; // eax

    result = ~(1 << a1);
    *(_DWORD*)& byte_5D4594[1556300] &= result;
    return result;
}

//----- (004D79C0) --------------------------------------------------------
int __cdecl sub_4D79C0(int a1)
{
    int v1; // esi
    int result; // eax
    int v3; // ecx

    v1 = *(_DWORD*)(a1 + 748);
    sub_4D9D20(255, a1);
    sub_4D6000(a1);
    for (result = sub_4DA7C0(); result; result = sub_4DA7F0(result))
    {
        v3 = *(_DWORD*)(result + 748);
        *(_BYTE*)(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + v3 + 452) = 0;
        *(_DWORD*)(v3 + 4 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 324) = 0;
        *(_BYTE*)(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + v3 + 484) = 0;
        *(_BYTE*)(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + v3 + 516) = 0;
    }
    return result;
}

//----- (004D7A60) --------------------------------------------------------
int __cdecl sub_4D7A60(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[4 * a1 + 1556172] = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (004D7A80) --------------------------------------------------------
int sub_4D7A80()
{
    unsigned __int8* v0; // ebp
    int v1; // edi
    int v2; // esi
    char* v3; // eax
    int v4; // eax
    int v5; // edi
    int v6; // ecx
    int result; // eax

    v0 = &byte_5D4594[1556172];
    v1 = 324 - (_DWORD)& byte_5D4594[1556172];
    v2 = 484;
    do
    {
        v3 = sub_417090(v2 - 484);
        if (v3 && *((_DWORD*)v3 + 523) && *((_DWORD*)v3 + 514) && *((_DWORD*)v3 + 1198) == 1)
            goto LABEL_12;
        if (*(_DWORD*)v0
            && *(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)v0 > (unsigned int)(30 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            v4 = sub_4DA7C0();
            if (v4)
            {
                v5 = (int)& v0[v1];
                do
                {
                    v6 = *(_DWORD*)(v4 + 748);
                    *(_BYTE*)(v2 + v6 - 32) = 0;
                    *(_DWORD*)(v5 + v6) = 0;
                    *(_BYTE*)(v2 + v6) = 0;
                    *(_BYTE*)(v2 + v6 + 32) = 0;
                    v4 = sub_4DA7F0(v4);
                } while (v4);
                v1 = 324 - (_DWORD)& byte_5D4594[1556172];
            }
            LABEL_12:
            *(_DWORD*)v0 = 0;
        }
        ++v2;
        v0 += 4;
        result = v2 - 484;
    } while (v2 - 484 < 32);
    return result;
}

//----- (004D7B40) --------------------------------------------------------
int sub_4D7B40()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[1556172], 0, 0x80u);
    return result;
}

//----- (004D7B60) --------------------------------------------------------
int __cdecl sub_4D7B60(int a1)
{
    int result; // eax
    int i; // esi
    char v3[7]; // [esp+4h] [ebp-8h]

    v3[0] = -46;
    *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a1);
    *(_WORD*)& v3[3] = *(_WORD*)(a1 + 4);
    v3[5] = 1;
    v3[6] = 2;
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 7, 0, 1);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D7BE0) --------------------------------------------------------
int __cdecl sub_4D7BE0(int a1)
{
    int result; // eax
    int i; // esi
    char v3[7]; // [esp+4h] [ebp-8h]

    v3[0] = -46;
    *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a1);
    *(_WORD*)& v3[3] = *(_WORD*)(a1 + 4);
    v3[5] = 2;
    v3[6] = 2;
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 7, 0, 1);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D7C60) --------------------------------------------------------
int sub_4D7C60()
{
    int result; // eax
    float v1; // [esp+0h] [ebp-4h]
    float v2; // [esp+0h] [ebp-4h]

    *(_DWORD*)& byte_5D4594[1556316] = 0;
    *(float*)& byte_5D4594[1556308] = sub_419D40(&byte_587000[198788]);
    v1 = sub_419D40(&byte_587000[198804]);
    *(_DWORD*)& byte_5D4594[1556312] = sub_419A70(v1);
    v2 = sub_419D40(&byte_587000[198820]);
    result = sub_419A70(v2);
    *(_DWORD*)& byte_5D4594[1556304] = result;
    return result;
}

//----- (004D7CC0) --------------------------------------------------------
int sub_4D7CC0()
{
    int result; // eax
    int i; // ecx
    int v2; // edx
    double v3; // st7
    double v4; // st6
    int j; // esi
    _DWORD* v6; // edi
    int v7; // eax

    sub_416BB0();
    result = sub_409F40(0x2000);
    if (result)
    {
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1556316]) > * (int*)& byte_5D4594[1556312])
        {
            for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
            {
                if (!(*(_DWORD*)(i + 16) & 0x8020))
                {
                    v2 = *(_DWORD*)(i + 748);
                    if (!(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 1))
                    {
                        v3 = *(float*)(i + 60) - *(float*)(v2 + 252);
                        v4 = *(float*)(i + 56) - *(float*)(v2 + 248);
                        if (v4 * v4 + v3 * v3 < *(float*)& byte_5D4594[1556308])
                            * (_DWORD*)(v2 + 256) = *(_DWORD*)& byte_5D4594[2598000];
                        *(_DWORD*)(v2 + 248) = *(_DWORD*)(i + 56);
                        *(_DWORD*)(v2 + 252) = *(_DWORD*)(i + 60);
                    }
                }
            }
            *(_DWORD*)& byte_5D4594[1556316] = *(_DWORD*)& byte_5D4594[2598000];
        }
        result = sub_4DA7C0();
        for (j = result; result; j = result)
        {
            if (!(*(_DWORD*)(j + 16) & 0x8020))
            {
                v6 = *(_DWORD * *)(j + 748);
                if (!(*(_BYTE*)(v6[69] + 3680) & 1))
                {
                    v7 = v6[65];
                    if ((unsigned int)(*(_DWORD*)& byte_5D4594[1556316] - v6[64]) > * (int*)& byte_5D4594[1556304])
                    {
                        if (v7)
                        {
                            sub_4D7BE0(j);
                            v6[65] = 0;
                        }
                    }
                    else if (!v7)
                    {
                        if (!sub_40A5C0(32) || *(_BYTE*)(v6[69] + 4) & 1)
                            sub_501960(774, j, 0, 0);
                        sub_4D7B60(j);
                        v6[65] = 1;
                    }
                }
            }
            result = sub_4DA7F0(j);
        }
    }
    return result;
}

//----- (004D7E50) --------------------------------------------------------
int __cdecl sub_4D7E50(int a1)
{
    int result; // eax
    _DWORD* v2; // esi

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v2 = *(_DWORD * *)(a1 + 748);
        v2[62] = 0;
        v2[63] = 0;
        v2[64] = *(_DWORD*)& byte_5D4594[2598000];
        if (v2[65])
            result = sub_4D7BE0(a1);
        v2[65] = 0;
    }
    return result;
}

//----- (004D7EA0) --------------------------------------------------------
int sub_4D7EA0()
{
    int result; // eax
    int i; // esi

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4D7E50(i);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D7ED0) --------------------------------------------------------
void sub_4D7ED0()
{
    nox_srand(0x2310u);
}

//----- (004D7EE0) --------------------------------------------------------
int __cdecl sub_4D7EE0(int a1, char a2)
{
    char v3[2]; // [esp+0h] [ebp-2h]

    v3[0] = -19;
    v3[1] = a2;
    return sub_4E5390(a1, (int)v3, 2, 0, 1);
}

//----- (004D7F10) --------------------------------------------------------
int __cdecl sub_4D7F10(int a1)
{
    char v2[2]; // [esp+0h] [ebp-2h]

    v2[0] = -20;
    v2[1] = sub_40A6C0();
    return sub_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (004D7F40) --------------------------------------------------------
int __cdecl sub_4D7F40(int a1, _DWORD* a2, char a3)
{
    int v3; // esi

    v3 = *(_DWORD*)(a1 + 748);
    LOBYTE(a1) = -38;
    *(_WORD*)((char*)& a1 + 1) = sub_578AC0(a2);
    HIBYTE(a1) = a3;
    return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), &a1, 4, 0, 1);
}

//----- (004D7F90) --------------------------------------------------------
int __cdecl sub_4D7F90(int a1, int a2, char a3, int a4)
{
    int result; // eax
    int v5; // eax

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v5 = *(_DWORD*)(a1 + 748);
        LOBYTE(a1) = 111;
        BYTE1(a1) = a2;
        BYTE2(a1) = *(_BYTE*)(*(_DWORD*)(v5 + 276) + 4 * a2 + 3696);
        HIBYTE(a1) = a3;
        if (a4)
            HIBYTE(a1) = a3 | 0x80;
        result = sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)& a1, 4, 0, 1);
    }
    return result;
}

//----- (004D8000) --------------------------------------------------------
int __cdecl sub_4D8000(int a1, char a2, char a3, int a4)
{
    int result; // eax
    int v5; // ecx

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v5 = *(_DWORD*)(a1 + 748);
        BYTE1(a1) = a2;
        LOBYTE(a1) = -47;
        BYTE2(a1) = a3;
        if (a4)
            BYTE2(a1) = a3 | 0x80;
        result = sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)& a1, 3, 0, 1);
    }
    return result;
}

//----- (004D8060) --------------------------------------------------------
int __cdecl sub_4D8060(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // eax

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v4 = *(_DWORD*)(a1 + 748);
        LOBYTE(a1) = -51;
        BYTE1(a1) = a2;
        BYTE2(a1) = *(_BYTE*)(*(_DWORD*)(v4 + 276) + 4 * a2 + 3696);
        if (a3)
            BYTE2(a1) |= 0x80u;
        result = sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)& a1, 3, 0, 1);
    }
    return result;
}

//----- (004D80C0) --------------------------------------------------------
int __cdecl sub_4D80C0(int a1, char a2)
{
    int result; // eax
    int v3; // eax

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v3 = *(_DWORD*)(a1 + 748);
        LOBYTE(a1) = -21;
        BYTE1(a1) = a2;
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), &a1, 2, 0, 1);
    }
    return result;
}

//----- (004D8100) --------------------------------------------------------
int __cdecl sub_4D8100(int a1, char a2, char a3)
{
    int result; // eax
    int v4; // edx

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        BYTE2(a1) = a3;
        v4 = *(_DWORD*)(result + 748);
        BYTE1(a1) = a2;
        LOBYTE(a1) = -50;
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), &a1, 3, 0, 1);
    }
    return result;
}

//----- (004D8150) --------------------------------------------------------
int __cdecl sub_4D8150(int a1, char a2, char a3)
{
    int result; // eax
    int v4; // edx

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        BYTE2(a1) = a3;
        v4 = *(_DWORD*)(result + 748);
        BYTE1(a1) = a2;
        LOBYTE(a1) = -49;
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), &a1, 3, 0, 1);
    }
    return result;
}

//----- (004D81A0) --------------------------------------------------------
void __cdecl sub_4D81A0(int a1)
{
    double v1; // st7
    int v2; // ecx
    char v3[5]; // [esp+4h] [ebp-8h]

    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v1 = *(float*)(a1 + 28);
        v3[0] = 110;
        v2 = *(_DWORD*)(a1 + 748);
        *(_DWORD*)& v3[1] = (__int64)v1;
        sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v3, 5, 0, 1);
    }
}

//----- (004D81F0) --------------------------------------------------------
int __cdecl sub_4D81F0(int a1, _DWORD* a2)
{
    char v3[7]; // [esp+4h] [ebp-8h]

    v3[0] = 107;
    *(_WORD*)& v3[1] = sub_578AC0(a2);
    *(_DWORD*)& v3[3] = a2[33];
    return sub_4E5420(a1, v3, 7, 0, 1);
}

//----- (004D8230) --------------------------------------------------------
int __cdecl sub_4D8230(int a1, _DWORD* a2)
{
    char v3[7]; // [esp+4h] [ebp-8h]

    v3[0] = 101;
    *(_WORD*)& v3[1] = sub_578AC0(a2);
    *(_DWORD*)& v3[3] = a2[5];
    return sub_4E5420(a1, v3, 7, 0, 1);
}

//----- (004D8270) --------------------------------------------------------
int __cdecl sub_4D8270(int a1)
{
    int v1; // ecx
    int v2; // eax
    char v4[5]; // [esp+0h] [ebp-8h]

    v1 = *(_DWORD*)(a1 + 16);
    v2 = *(_DWORD*)(a1 + 748);
    v4[0] = 102;
    *(_DWORD*)& v4[1] = v1;
    return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 5, 0, 1);
}

//----- (004D82B0) --------------------------------------------------------
int __cdecl sub_4D82B0(int a1, _DWORD* a2, char a3, char a4)
{
    char v5[5]; // [esp+0h] [ebp-8h]

    v5[0] = 100;
    *(_WORD*)& v5[1] = sub_578AC0(a2);
    v5[3] = a3;
    v5[4] = a4;
    return sub_4E5390(a1, (int)v5, 5, 0, 0);
}

//----- (004D82F0) --------------------------------------------------------
_DWORD* __cdecl sub_4D82F0(int a1, _DWORD* a2)
{
    _DWORD* result; // eax
    int v3; // ecx
    int v4; // edi
    int v5; // esi
    int v6; // edx
    _DWORD* v7; // ecx
    int v8; // ecx
    int v9; // eax
    int v10; // edx
    int v11; // ecx
    int v12; // esi
    int v13; // edx
    _DWORD* v14; // ecx
    int v15; // ecx
    int v16; // eax
    int v17; // edx
    int v18; // ecx
    char v19[11]; // [esp+8h] [ebp-Ch]

    result = a2;
    v3 = a2[2];
    v4 = 0;
    if (v3 & 0x11001000)
    {
        v5 = a2[173];
        v6 = 4;
        v7 = (_DWORD*)a2[173];
        do
        {
            if (*v7)
                v4 = 1;
            ++v7;
            --v6;
        } while (v6);
        if (v4)
        {
            v8 = a2[123];
            v19[0] = 81;
            *(_WORD*)& v19[1] = *(_WORD*)(v8 + 36);
            if (*(_BYTE*)(v8 + 8) & 4)
                v19[2] |= 0x80u;
            *(_DWORD*)& v19[3] = sub_415820((int)a2);
            v9 = 0;
            v10 = v5;
            do
            {
                if (*(_DWORD*)v10)
                    v19[v9 + 7] = *(_BYTE*)(*(_DWORD*)v10 + 4);
                else
                    v19[v9 + 7] = -1;
                ++v9;
                v10 += 4;
            } while (v9 < 4);
            result = (_DWORD*)sub_4E5390(a1, (int)v19, 11, 0, 0);
        }
        else
        {
            v11 = a2[123];
            v19[0] = 80;
            *(_WORD*)& v19[1] = *(_WORD*)(v11 + 36);
            if (*(_BYTE*)(v11 + 8) & 4)
                v19[2] |= 0x80u;
            *(_DWORD*)& v19[3] = sub_415820((int)a2);
            result = (_DWORD*)sub_4E5390(a1, (int)v19, 7, 0, 0);
        }
    }
    else if (v3 & 0x2000000)
    {
        v12 = a2[173];
        v13 = 4;
        v14 = (_DWORD*)a2[173];
        do
        {
            if (*v14)
                v4 = 1;
            ++v14;
            --v13;
        } while (v13);
        if (v4)
        {
            v15 = a2[123];
            v19[0] = 82;
            *(_WORD*)& v19[1] = *(_WORD*)(v15 + 36);
            if (*(_BYTE*)(v15 + 8) & 4)
                v19[2] |= 0x80u;
            *(_DWORD*)& v19[3] = sub_415C70((int)a2);
            v16 = 0;
            v17 = v12;
            do
            {
                if (*(_DWORD*)v17)
                    v19[v16 + 7] = *(_BYTE*)(*(_DWORD*)v17 + 4);
                else
                    v19[v16 + 7] = -1;
                ++v16;
                v17 += 4;
            } while (v16 < 4);
            result = (_DWORD*)sub_4E5390(a1, (int)v19, 11, 0, 0);
        }
        else
        {
            v18 = a2[123];
            v19[0] = 79;
            *(_WORD*)& v19[1] = *(_WORD*)(v18 + 36);
            if (*(_BYTE*)(v18 + 8) & 4)
                v19[2] |= 0x80u;
            *(_DWORD*)& v19[3] = sub_415C70((int)a2);
            result = (_DWORD*)sub_4E5390(a1, (int)v19, 7, 0, 0);
        }
    }
    return result;
}

//----- (004D84C0) --------------------------------------------------------
int __cdecl sub_4D84C0(int a1, int a2)
{
    int result; // eax
    int v3; // ecx
    int v4; // ecx
    int v5; // eax
    int v6; // ecx
    char v7[7]; // [esp+0h] [ebp-8h]

    result = a2;
    v3 = *(_DWORD*)(a2 + 8);
    if (v3 & 0x11001000)
    {
        v4 = *(_DWORD*)(a2 + 492);
        v7[0] = 84;
        *(_WORD*)& v7[1] = *(_WORD*)(v4 + 36);
        v5 = sub_415820(a2);
    }
    else
    {
        if (!(v3 & 0x2000000))
            return result;
        v6 = *(_DWORD*)(a2 + 492);
        v7[0] = 83;
        *(_WORD*)& v7[1] = *(_WORD*)(v6 + 36);
        v5 = sub_415C70(a2);
    }
    *(_DWORD*)& v7[3] = v5;
    return sub_4E5390(a1, (int)v7, 7, 0, 0);
}

//----- (004D8540) --------------------------------------------------------
_DWORD* __cdecl sub_4D8540(int a1, _DWORD* a2, int a3)
{
    _DWORD* result; // eax
    char v4[3]; // [esp+4h] [ebp-4h]

    v4[0] = 96;
    *(_WORD*)& v4[1] = sub_578AC0(a2);
    sub_4E5390(a1, (int)v4, 3, 0, 0);
    result = (_DWORD*)a3;
    if (a3)
        result = sub_4D82F0(255, a2);
    return result;
}

//----- (004D8590) --------------------------------------------------------
int __cdecl sub_4D8590(int a1, _DWORD* a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = 97;
    *(_WORD*)& v4[1] = sub_578AC0(a2);
    return sub_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004D85C0) --------------------------------------------------------
int __cdecl sub_4D85C0(int a1, _DWORD* a2)
{
    int result; // eax
    _WORD* v3; // eax
    char v4[7]; // [esp+4h] [ebp-8h]

    result = a2[139];
    if (result)
    {
        v4[0] = -35;
        *(_WORD*)& v4[1] = sub_578AC0(a2);
        v3 = (_WORD*)a2[139];
        *(_WORD*)& v4[3] = *v3;
        *(_WORD*)& v4[5] = v3[2];
        result = sub_4E5390(a1, (int)v4, 7, 0, 1);
    }
    return result;
}

//----- (004D8620) --------------------------------------------------------
int __cdecl sub_4D8620(int a1, _DWORD* a2)
{
    _DWORD* v2; // esi
    int result; // eax
    unsigned int v4; // ecx
    _DWORD* v5; // [esp-4h] [ebp-8h]

    v2 = a2;
    result = a2[139];
    if (result)
    {
        v5 = a2;
        LOBYTE(a2) = 65;
        *(_WORD*)((char*)& a2 + 1) = sub_578AC0(v5);
        LOWORD(v4) = *(_WORD*)v2[139];
        HIBYTE(a2) = v4 >> 1;
        result = sub_4E5390(a1, (int)& a2, 4, 0, 1);
    }
    return result;
}
// 4D8656: variable 'v4' is possibly undefined

//----- (004D8670) --------------------------------------------------------
int __cdecl sub_4D8670(int a1, _DWORD* a2)
{
    int result; // eax
    __int16 v3; // ax
    unsigned __int16* v4; // ecx
    char v5[5]; // [esp+4h] [ebp-8h]

    result = a2[139];
    if (result)
    {
        v5[0] = -60;
        v5[1] = 12;
        v3 = sub_578AC0(a2);
        v4 = (unsigned __int16*)a2[139];
        *(_WORD*)& v5[2] = v3;
        v5[4] = 100 * *v4 / v4[2];
        result = sub_4E5390(a1, (int)v5, 5, 0, 1);
    }
    return result;
}

//----- (004D86E0) --------------------------------------------------------
char* __cdecl sub_4D86E0(int a1)
{
    int v1; // edi
    char* result; // eax
    char* v3; // esi

    v1 = a1;
    result = sub_417090(a1);
    v3 = result;
    if (result)
    {
        result = (char*) * ((_DWORD*)result + 514);
        if (result)
        {
            if (*((_DWORD*)result + 139))
            {
                LOBYTE(a1) = 67;
                *(_WORD*)((char*)& a1 + 1) = **(_WORD * *)(*((_DWORD*)v3 + 514) + 556);
                sub_4E5390(v1, (int)& a1, 3, 0, 1);
                result = (char*)sub_40A5C0(4096);
                if (result)
                    result = (char*)sub_4D8670(v1 | 0x80, *((_DWORD * *)v3 + 514));
            }
        }
    }
    return result;
}

//----- (004D8760) --------------------------------------------------------
__int16 __cdecl sub_4D8760(int a1, __int16 a2, __int16 a3)
{
    __int16 result; // ax
    char v4[5]; // [esp+0h] [ebp-8h]

    result = a3;
    if (a3 < 0)
    {
        *(_WORD*)& v4[3] = a3;
        v4[0] = 66;
        *(_WORD*)& v4[1] = a2;
        result = sub_4E5420(a1, v4, 5, 0, 1);
    }
    return result;
}

//----- (004D87A0) --------------------------------------------------------
int __cdecl sub_4D87A0(int a1, _DWORD* a2)
{
    int result; // eax
    _WORD* v3; // eax
    char v4[7]; // [esp+4h] [ebp-8h]

    result = a2[139];
    if (result)
    {
        if (*(_WORD*)(result + 4))
        {
            v4[0] = 68;
            *(_WORD*)& v4[1] = sub_578AC0(a2);
            v3 = (_WORD*)a2[139];
            *(_WORD*)& v4[3] = *v3;
            *(_WORD*)& v4[5] = v3[2];
            result = sub_4E5390(a1, (int)v4, 7, 0, 0);
        }
    }
    return result;
}

//----- (004D8800) --------------------------------------------------------
int __cdecl sub_4D8800(int a1, int a2)
{
    int result; // eax
    int v3; // eax

    result = a2;
    if (*(_BYTE*)(a2 + 8) & 4)
    {
        v3 = *(_DWORD*)(a2 + 748);
        LOBYTE(a2) = 71;
        BYTE1(a2) = *(_BYTE*)(v3 + 91);
        result = sub_4E5390(a1, (int)& a2, 2, 0, 1);
    }
    return result;
}

//----- (004D8840) --------------------------------------------------------
int __cdecl sub_4D8840(int a1, int a2)
{
    char v3; // cl
    __int16 v5; // [esp+0h] [ebp-2h]

    v3 = *(_BYTE*)(a2 + 440);
    LOBYTE(v5) = 91;
    HIBYTE(v5) = v3;
    return sub_4E5420(a1, &v5, 2, 0, 1);
}

//----- (004D8870) --------------------------------------------------------
int __cdecl sub_4D8870(int a1, int a2)
{
    int result; // eax
    int v3; // eax
    char v4[5]; // [esp+0h] [ebp-8h]

    result = a2;
    if (*(_BYTE*)(a2 + 8) & 4)
    {
        v3 = *(_DWORD*)(a2 + 748);
        v4[0] = 74;
        *(_DWORD*)& v4[1] = *(_DWORD*)(*(_DWORD*)(v3 + 276) + 2164);
        result = sub_4E5420(a1, v4, 5, 0, 1);
    }
    return result;
}

//----- (004D88C0) --------------------------------------------------------
int __cdecl sub_4D88C0(int a1, int a2)
{
    int result; // eax
    int v3; // esi
    char v4[7]; // [esp+4h] [ebp-8h]

    result = a2;
    v3 = *(_DWORD*)(a2 + 748);
    if (*(_BYTE*)(a2 + 8) & 4 && (!v3 || *(_BYTE*)(*(_DWORD*)(v3 + 276) + 2251)))
    {
        v4[0] = -34;
        *(_WORD*)& v4[1] = sub_578AC0((_DWORD*)a2);
        *(_WORD*)& v4[3] = *(_WORD*)(v3 + 4);
        *(_WORD*)& v4[5] = *(_WORD*)(v3 + 8);
        result = sub_4E5450(a1, v4, 7, 0, 1);
    }
    return result;
}

//----- (004D8930) --------------------------------------------------------
int __cdecl sub_4D8930(int a1, int a2)
{
    int result; // eax
    int v3; // esi
    char v4[5]; // [esp+4h] [ebp-8h]

    result = a2;
    v3 = *(_DWORD*)(a2 + 748);
    if (*(_BYTE*)(a2 + 8) & 4 && (!v3 || *(_BYTE*)(*(_DWORD*)(v3 + 276) + 2251)))
    {
        v4[0] = 69;
        *(_WORD*)& v4[1] = sub_578AC0((_DWORD*)a2);
        *(_WORD*)& v4[3] = *(_WORD*)(v3 + 4);
        result = sub_4E5450(a1, v4, 5, 0, 1);
    }
    return result;
}

//----- (004D8990) --------------------------------------------------------
char __cdecl sub_4D8990(int a1, int a2, char a3)
{
    char result; // al
    int v4; // edi
    __int16 v5; // ax
    int v6; // ecx
    __int16 v7; // ax
    char v8[14]; // [esp+8h] [ebp-10h]

    result = *(_BYTE*)(a2 + 8);
    v4 = *(_DWORD*)(a2 + 748);
    if (result & 4)
    {
        v8[0] = 72;
        v5 = sub_578AC0((_DWORD*)a2);
        v6 = *(_DWORD*)(a2 + 556);
        *(_WORD*)& v8[1] = v5;
        *(_WORD*)& v8[5] = *(_WORD*)(v4 + 8);
        v7 = *(_WORD*)(a2 + 490);
        *(_WORD*)& v8[3] = *(_WORD*)(v6 + 4);
        *(_WORD*)& v8[7] = v7;
        *(_WORD*)& v8[9] = *(_WORD*)(*(_DWORD*)(v4 + 276) + 2235);
        *(_WORD*)& v8[11] = *(_WORD*)(*(_DWORD*)(v4 + 276) + 2239);
        v8[13] = a3;
        result = sub_4E5420(a1, v8, 14, 0, 1);
    }
    return result;
}

//----- (004D8A30) --------------------------------------------------------
int __cdecl sub_4D8A30(int a1, int a2)
{
    char v3[5]; // [esp+0h] [ebp-8h]

    v3[0] = 73;
    *(_DWORD*)& v3[1] = a2;
    return sub_4E5420(a1, v3, 5, 0, 1);
}

//----- (004D8A60) --------------------------------------------------------
int __cdecl sub_4D8A60(int a1, int a2)
{
    __int16 v3; // ax
    __int16 v4; // cx
    char v5[5]; // [esp+4h] [ebp-8h]

    if (*(_DWORD*)(a2 + 8) & 0x13001000)
        return sub_4D8AD0(a1, a2);
    v5[0] = 75;
    v3 = sub_578AC0((_DWORD*)a2);
    v4 = *(_WORD*)(a2 + 4);
    *(_WORD*)& v5[1] = v3;
    *(_WORD*)& v5[3] = v4;
    sub_4E5390(a1, (int)v5, 5, 0, 0);
    return sub_4D87A0(a1, (_DWORD*)a2);
}

//----- (004D8AD0) --------------------------------------------------------
int __cdecl sub_4D8AD0(int a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int v4; // edx
    char v6[9]; // [esp+8h] [ebp-Ch]

    v6[0] = 76;
    v2 = *(_DWORD*)(a2 + 692);
    *(_WORD*)& v6[1] = sub_578AC0((_DWORD*)a2);
    *(_WORD*)& v6[3] = *(_WORD*)(a2 + 4);
    v3 = 0;
    v4 = v2;
    do
    {
        if (*(_DWORD*)v4)
            v6[v3 + 5] = *(_BYTE*)(*(_DWORD*)v4 + 4);
        else
            v6[v3 + 5] = -1;
        ++v3;
        v4 += 4;
    } while (v3 < 4);
    sub_4E5390(a1, (int)v6, 9, 0, 0);
    return sub_4D87A0(a1, (_DWORD*)a2);
}

//----- (004D8B50) --------------------------------------------------------
int __cdecl sub_4D8B50(int a1, int a2)
{
    char v3[5]; // [esp+4h] [ebp-8h]

    v3[0] = 77;
    *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a2);
    *(_WORD*)& v3[3] = *(_WORD*)(a2 + 4);
    return sub_4E5390(a1, (int)v3, 5, 0, 0);
}

//----- (004D8B90) --------------------------------------------------------
int __cdecl sub_4D8B90(int a1, char a2)
{
    int result; // eax
    char v3[8]; // [esp+0h] [ebp-8h]

    result = a1;
    if (a1)
    {
        if (!(*(_BYTE*)(a1 + 8) & 4))
            return result;
        v3[0] = 88;
        *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a1);
    }
    else
    {
        v3[0] = 88;
        *(_WORD*)& v3[1] = 0;
    }
    v3[3] = a2;
    *(_DWORD*)& v3[4] = *(_DWORD*)& byte_5D4594[2598000];
    return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8BF0) --------------------------------------------------------
int __cdecl sub_4D8BF0(int a1, char a2)
{
    char v3[8]; // [esp+0h] [ebp-8h]

    v3[0] = 89;
    if (a1)
        * (_WORD*)& v3[1] = *(unsigned __int8*)(a1 + 57);
    else
        *(_WORD*)& v3[1] = 0;
    v3[3] = a2;
    *(_DWORD*)& v3[4] = *(_DWORD*)& byte_5D4594[2598000];
    return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8C40) --------------------------------------------------------
int __cdecl sub_4D8C40(int a1)
{
    __int16 v1; // cx
    char v3[8]; // [esp+0h] [ebp-8h]

    v1 = *(unsigned __int8*)(a1 + 57);
    v3[0] = 86;
    *(_WORD*)& v3[1] = v1;
    v3[3] = 0;
    *(_DWORD*)& v3[4] = *(_DWORD*)& byte_5D4594[2598000];
    return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8C80) --------------------------------------------------------
int __cdecl sub_4D8C80(int a1, char a2)
{
    char v3[8]; // [esp+0h] [ebp-8h]

    v3[0] = 87;
    if (a1)
        * (_WORD*)& v3[1] = *(unsigned __int8*)(a1 + 57);
    else
        *(_WORD*)& v3[1] = -1;
    v3[3] = a2;
    *(_DWORD*)& v3[4] = *(_DWORD*)& byte_5D4594[2598000];
    return sub_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8CD0) --------------------------------------------------------
int __cdecl sub_4D8CD0(int a1)
{
    int result; // eax
    int v2; // esi
    char v3[7]; // [esp+4h] [ebp-8h]

    result = a1;
    v2 = *(_DWORD*)(a1 + 748);
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v3[0] = 85;
        *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a1);
        *(_WORD*)& v3[3] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 2152);
        *(_WORD*)& v3[5] = *(_WORD*)(*(_DWORD*)(v2 + 276) + 2156);
        result = sub_4E5420(255, v3, 7, 0, 1);
    }
    return result;
}

//----- (004D8D40) --------------------------------------------------------
char* __cdecl sub_4D8D40(int a1)
{
    char* result; // eax
    char* i; // esi
    char* v3; // esi
    double v4; // st7
    int v5; // esi
    int v6; // eax
    float v7; // [esp+0h] [ebp-Ch]
    unsigned __int8* v8; // [esp+4h] [ebp-8h]
    int v9; // [esp+10h] [ebp+4h]

    result = (char*)a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        ++* (_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2140);
        result = (char*)sub_40A5C0(1024);
        if (result)
        {
            if (sub_40AA00() && !sub_40AA20())
            {
                for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
                {
                    if (i[3680] & 1)
                        sub_4174F0((int)i, 256);
                }
                sub_40AA30(1);
            }
            result = (char*)sub_40A5C0(0x4000000);
            if (!result)
            {
                result = (char*)sub_40A300();
                if (!result)
                {
                    result = (char*)sub_40AA00();
                    if (result)
                    {
                        if (!sub_417DA0(4))
                        {
                            v5 = sub_40A770();
                            result = (char*)sub_40AA40();
                            if (v5 >= (int)result)
                                return result;
                            v8 = &byte_587000[198928];
                            v4 = sub_419D40(&byte_587000[198960]);
                            goto LABEL_22;
                        }
                        v9 = sub_417DD0();
                        result = (char*)sub_40AA40();
                        if (v9 < (int)result)
                        {
                            result = sub_418B10();
                            v3 = result;
                            if (result)
                            {
                                while (sub_40A830((int)v3) != 1)
                                {
                                    result = sub_418B60((int)v3);
                                    v3 = result;
                                    if (!result)
                                        return result;
                                }
                                v8 = &byte_587000[198872];
                                v4 = sub_419D40(&byte_587000[198904]);
                                LABEL_22:
                                v7 = v4;
                                v6 = sub_419A70(v7);
                                return (char*)sub_40A2A0(v6, (const char*)v8);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (004D8E90) --------------------------------------------------------
int __cdecl sub_4D8E90(int a1, int a2)
{
    int result; // eax

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
        *(_DWORD*)(result + 2136) += a2;
    }
    return result;
}

//----- (004D8EC0) --------------------------------------------------------
int __cdecl sub_4D8EC0(int a1, int a2)
{
    int result; // eax

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
        *(_DWORD*)(result + 2136) -= a2;
    }
    return result;
}

//----- (004D8EF0) --------------------------------------------------------
int __cdecl sub_4D8EF0(int a1)
{
    int v1; // eax
    char v3[11]; // [esp+0h] [ebp-Ch]

    v3[0] = 78;
    v1 = *(_DWORD*)(a1 + 748);
    *(_WORD*)& v3[1] = *(_WORD*)(a1 + 36);
    *(_DWORD*)& v3[3] = *(_DWORD*)(*(_DWORD*)(v1 + 276) + 2136);
    *(_DWORD*)& v3[7] = *(_DWORD*)(*(_DWORD*)(v1 + 276) + 2140);
    return sub_4E5390(255, (int)v3, 11, 0, 1);
}

//----- (004D8F50) --------------------------------------------------------
int __cdecl sub_4D8F50(int a1, int a2)
{
    char v3[13]; // [esp+0h] [ebp-10h]

    v3[0] = -45;
    *(_DWORD*)& v3[1] = a2;
    *(_DWORD*)& v3[5] = sub_40A230();
    *(_DWORD*)& v3[9] = *(_DWORD*)& byte_5D4594[2598000];
    return sub_4E5390(a1, (int)v3, 13, 0, 1);
}

//----- (004D8F90) --------------------------------------------------------
int __cdecl sub_4D8F90(int a1, _DWORD* a2)
{
    char v3[7]; // [esp+4h] [ebp-8h]

    v3[0] = 90;
    *(_WORD*)& v3[1] = sub_578AC0(a2);
    *(_DWORD*)& v3[3] = a2[85];
    return sub_4E5390(a1, (int)v3, 7, 0, 1);
}

//----- (004D8FD0) --------------------------------------------------------
void __cdecl sub_4D8FD0(int a1, _DWORD* a2)
{
    _DWORD* v2; // esi

    v2 = a2;
    if ((unsigned int)0x800000 & a2[2])
    {
        *(_WORD*)((char*)& a2 + 1) = sub_578AC0(a2);
        LOBYTE(a2) = 56 - ((v2[4] & 0x1000000) != 0);
        sub_4E5420(a1, &a2, 3, 0, 1);
    }
}

//----- (004D9020) --------------------------------------------------------
int __cdecl sub_4D9020(int a1, int a2)
{
    int v2; // esi
    __int16 v3; // ax
    double v4; // st7
    __int64 v5; // rax
    double v6; // st7
    __int64 v7; // rax
    double v8; // st7
    int result; // eax
    __int16 v10; // ax
    double v11; // st7
    __int16 v12; // ax
    double v13; // st7
    _DWORD* v14; // [esp-4h] [ebp-10h]
    char v15[6]; // [esp+4h] [ebp-8h]

    v2 = a2;
    if (*(_BYTE*)(a2 + 20) & 0x20)
    {
        v3 = *(_WORD*)(a2 + 36);
        v15[0] = -97;
        v4 = *(float*)(a2 + 104);
        *(_WORD*)& v15[1] = v3;
        v5 = (__int64)v4;
        v6 = *(float*)(a2 + 108);
        v15[3] = v5;
        v7 = (__int64)v6;
        v8 = *(float*)(a2 + 116);
        v15[4] = v7;
        v15[5] = (__int64)v8;
        result = sub_40EBC0(a1, 1, v15, 6);
    }
    else
    {
        v14 = (_DWORD*)a2;
        if (*(float*)(a2 + 104) < 0.0)
        {
            LOBYTE(a2) = 95;
            v12 = sub_578AC0(v14);
            v13 = *(float*)(v2 + 104);
            *(_WORD*)((char*)& a2 + 1) = v12;
            v11 = -v13;
        }
        else
        {
            LOBYTE(a2) = 94;
            v10 = sub_578AC0(v14);
            v11 = *(float*)(v2 + 104);
            *(_WORD*)((char*)& a2 + 1) = v10;
        }
        HIBYTE(a2) = (__int64)v11;
        result = sub_40EBC0(a1, 1, &a2, 4);
    }
    return result;
}

//----- (004D90E0) --------------------------------------------------------
int __cdecl sub_4D90E0(int a1, char a2)
{
    char v3[2]; // [esp+0h] [ebp-2h]

    v3[0] = -105;
    v3[1] = a2;
    return sub_40EBC0(a1, 1, v3, 2);
}

//----- (004D9110) --------------------------------------------------------
int __cdecl sub_4D9110(float* a1, int a2)
{
    int result; // eax
    int i; // edi
    int v4; // esi
    double v5; // st7
    double v6; // st6
    double v7; // st5

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        v4 = *(_DWORD*)(*(_DWORD*)(i + 748) + 276);
        v5 = *a1 - *(float*)(v4 + 3632);
        v6 = a1[1] - *(float*)(v4 + 3636);
        v7 = v6 * v6 + v5 * v5;
        if (v7 < 90000.0)
            sub_4D90E0(*(unsigned __int8*)(v4 + 2064), (__int64)((1.0 - v7 * 0.000011111111) * (double)a2));
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004D91A0) --------------------------------------------------------
int __cdecl sub_4D91A0(int a1, int a2)
{
    char v3[5]; // [esp+8h] [ebp-8h]

    v3[0] = 108;
    *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a2);
    *(_WORD*)& v3[3] = *(_WORD*)(a2 + 4);
    if (sub_40A5C0(0x8000000))
        v3[4] |= 0x80u;
    sub_4E5390(a1, (int)v3, 5, 0, 1);
    return sub_4D85C0(a1, (_DWORD*)a2);
}

//----- (004D9200) --------------------------------------------------------
int __cdecl sub_4D9200(int a1, int a2)
{
    int v4; // [esp+0h] [ebp-4h]

    LOBYTE(v4) = 109;
    *(_WORD*)((char*)& v4 + 1) = *(_WORD*)(a2 + 36);
    if (sub_40A5C0(0x8000000))
        BYTE2(v4) |= 0x80u;
    return sub_4E5390(a1, (int)& v4, 3, 0, 1);
}

//----- (004D9250) --------------------------------------------------------
int __cdecl sub_4D9250(int a1, int a2)
{
    char v3[5]; // [esp+8h] [ebp-8h]

    v3[0] = -37;
    *(_WORD*)& v3[1] = sub_578AC0((_DWORD*)a2);
    *(_WORD*)& v3[3] = *(_WORD*)(a2 + 4);
    sub_4E5390(a1, (int)v3, 5, 0, 1);
    return sub_4D85C0(a1, (_DWORD*)a2);
}

//----- (004D92A0) --------------------------------------------------------
int __cdecl sub_4D92A0(int a1, _DWORD* a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = -36;
    *(_WORD*)& v4[1] = sub_578AC0(a2);
    return sub_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (004D92D0) --------------------------------------------------------
int __cdecl sub_4D92D0(int a1, int a2)
{
    int result; // eax
    int v3; // edi
    int v4; // eax
    int v5; // edx
    char v6[7]; // [esp+8h] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[1556320];
    v3 = *(_DWORD*)(a2 + 692);
    if (!*(_DWORD*)& byte_5D4594[1556320])
    {
        result = sub_4E3AA0((CHAR*)& byte_587000[198984]);
        *(_DWORD*)& byte_5D4594[1556320] = result;
    }
    if (*(_DWORD*)(a2 + 8) & 0x13001000 || *(unsigned __int16*)(a2 + 4) == result)
    {
        v6[0] = 103;
        *(_WORD*)& v6[1] = sub_578AC0((_DWORD*)a2);
        v4 = 0;
        v5 = v3;
        do
        {
            if (*(_DWORD*)v5)
                v6[v4 + 3] = *(_BYTE*)(*(_DWORD*)v5 + 4);
            else
                v6[v4 + 3] = -1;
            ++v4;
            v5 += 4;
        } while (v4 < 4);
        result = sub_4E5420(a1, v6, 7, 0, 1);
    }
    return result;
}

//----- (004D9360) --------------------------------------------------------
int __cdecl sub_4D9360(int a1, _DWORD* a2, char a3, int a4)
{
    char v5[8]; // [esp+0h] [ebp-8h]

    v5[0] = 104;
    *(_WORD*)& v5[1] = sub_578AC0(a2);
    v5[7] = a3;
    *(_DWORD*)& v5[3] = a4;
    return sub_4E5420(a1, v5, 8, 0, 1);
}

//----- (004D93A0) --------------------------------------------------------
_DWORD* __cdecl sub_4D93A0(int a1, int a2)
{
    int v2; // eax
    char* v3; // ecx
    int v4; // eax
    int v5; // esi
    int v6; // edx
    char* v7; // ebx
    _DWORD* result; // eax
    _DWORD* i; // esi
    char v10[21]; // [esp+10h] [ebp-18h]

    v10[0] = 105;
    v2 = *(_DWORD*)(a2 + 748);
    *(_WORD*)& v10[1] = *(_WORD*)(a2 + 36);
    if (*(_BYTE*)(a2 + 540))
        v10[2] |= 0x80u;
    v3 = &v10[3];
    v4 = v2 + 2076;
    v5 = 6;
    do
    {
        v6 = v4;
        v7 = v3;
        v4 += 3;
        v3 += 3;
        --v5;
        *(_WORD*)v7 = *(_WORD*)v6;
        v7[2] = *(_BYTE*)(v6 + 2);
    } while (v5);
    result = (_DWORD*)sub_4E5390(a1, (int)v10, 21, 0, 1);
    for (i = *(_DWORD * *)(a2 + 504); i; i = (_DWORD*)i[124])
    {
        if (i[4] & 0x100)
            result = sub_4D82F0(a1, i);
    }
    return result;
}

//----- (004D9440) --------------------------------------------------------
int __cdecl sub_4D9440(int a1, int a2)
{
    char v3[68]; // [esp+Ch] [ebp-44h]

    v3[0] = -43;
    v3[1] = 1;
    strcpy(&v3[2], (const char*)a2);
    *(_WORD*)& v3[66] = *(_WORD*)(a2 + 72);
    return sub_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D94A0) --------------------------------------------------------
int __cdecl sub_4D94A0(int a1, const char* a2)
{
    char v3[68]; // [esp+8h] [ebp-44h]

    v3[0] = -43;
    v3[1] = 2;
    strcpy(&v3[2], a2);
    return sub_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D9500) --------------------------------------------------------
int __cdecl sub_4D9500(int a1, int a2)
{
    char v3[68]; // [esp+Ch] [ebp-44h]

    v3[0] = -43;
    v3[1] = 3;
    strcpy(&v3[2], (const char*)a2);
    *(_WORD*)& v3[66] = *(_WORD*)(a2 + 72);
    return sub_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D9560) --------------------------------------------------------
int __cdecl sub_4D9560(int a1, char a2, int a3)
{
    int v3; // ecx
    char v5[3]; // [esp+0h] [ebp-4h]
    char v6; // [esp+3h] [ebp-1h]

    v6 = HIBYTE(v3);
    v5[1] = a2;
    v5[0] = -42;
    v5[2] = a3 == 1;
    return sub_4E5420(a1, v5, 3, 0, 1);
}

//----- (004D95A0) --------------------------------------------------------
int __cdecl sub_4D95A0(int a1, char a2, char a3, char a4, __int16 a5)
{
    char v6[6]; // [esp+0h] [ebp-8h]

    v6[1] = a3;
    v6[3] = a4;
    v6[2] = a2;
    v6[0] = -40;
    *(_WORD*)& v6[4] = a5;
    return sub_4E5390(a1, (int)v6, 6, 0, 1);
}

//----- (004D95F0) --------------------------------------------------------
int __cdecl sub_4D95F0(int a1, char a2, __int16 a3)
{
    char v4[4]; // [esp+0h] [ebp-4h]

    v4[1] = a2;
    v4[0] = -39;
    *(_WORD*)& v4[2] = a3;
    return sub_4E5390(a1, (int)v4, 4, 0, 1);
}

//----- (004D9630) --------------------------------------------------------
int __cdecl sub_4D9630(int a1, int a2, char a3)
{
    char v4[6]; // [esp+0h] [ebp-8h]

    *(_DWORD*)& v4[1] = a2;
    v4[0] = -33;
    v4[5] = a3;
    return sub_4E5420(a1, v4, 6, 0, 1);
}

//----- (004D9670) --------------------------------------------------------
int __cdecl sub_4D9670(int a1, _DWORD* a2, char a3)
{
    char v4[4]; // [esp+0h] [ebp-4h]

    v4[0] = -32;
    *(_WORD*)& v4[1] = sub_578AC0(a2);
    v4[3] = a3;
    return sub_4E5390(a1, (int)v4, 4, 0, 0);
}

//----- (004D96B0) --------------------------------------------------------
int __cdecl sub_4D96B0(int a1, _DWORD* a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = -31;
    *(_WORD*)& v4[1] = sub_578AC0(a2);
    return sub_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004D96E0) --------------------------------------------------------
int __cdecl sub_4D96E0(int a1)
{
    char v2[1]; // [esp+1h] [ebp-1h]

    v2[0] = 113;
    return sub_4E5390(a1, (int)v2, 1, 0, 0);
}

//----- (004D9700) --------------------------------------------------------
int __cdecl sub_4D9700(int a1)
{
    int result; // eax

    result = a1;
    switch (a1)
    {
        case 0:
            result = sub_4DA390("report.c:NoComp");
            break;
        case 1:
            result = sub_4DA390("report.c:MinComp");
            break;
        case 2:
            result = sub_4DA390("report.c:AveComp");
            break;
        case 3:
            result = sub_4DA390("report.c:UserComp");
            break;
        default:
            return result;
    }
    return result;
}

//----- (004D9760) --------------------------------------------------------
int __cdecl sub_4D9760(int a1)
{
    int result; // eax
    int v2; // edx

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v2 = *(_DWORD*)(a1 + 748);
        LOBYTE(a1) = -53;
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), &a1, 1, 0, 1);
    }
    return result;
}

//----- (004D97A0) --------------------------------------------------------
int __cdecl sub_4D97A0(int a1, _DWORD* a2, int a3)
{
    LOBYTE(a3) = (a3 != 1) + 52;
    *(_WORD*)((char*)& a3 + 1) = sub_578AC0(a2);
    return sub_4E5390(a1, (int)& a3, 3, 0, 1);
}

//----- (004D97E0) --------------------------------------------------------
int __cdecl sub_4D97E0(int a1)
{
    char v2[1]; // [esp+1h] [ebp-1h]

    v2[0] = 54;
    return sub_4E5390(a1, (int)v2, 1, 0, 1);
}

//----- (004D9800) --------------------------------------------------------
int __cdecl sub_4D9800(int a1, int a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = -28;
    v4[1] = a1 != 0;
    v4[2] = a2 != 0;
    return sub_4E5390(255, (int)v4, 3, 0, 1);
}

//----- (004D9840) --------------------------------------------------------
void __cdecl sub_4D9840(_DWORD* a1, _DWORD* a2)
{
    char v3[7]; // [esp+4h] [ebp-8h]

    if (a1 && a2)
    {
        v3[0] = -98;
        v3[1] = 7;
        v3[2] = 0;
        *(_WORD*)& v3[3] = sub_578AC0(a1);
        *(_WORD*)& v3[5] = sub_578AC0(a2);
    }
    sub_4E5390(255, (int)v3, 7, 0, 1);
}

//----- (004D98A0) --------------------------------------------------------
int __cdecl sub_4D98A0(_DWORD* a1, _DWORD* a2)
{
    char v3[7]; // [esp+4h] [ebp-8h]

    if (a1 && a2)
    {
        v3[0] = -98;
        v3[1] = 14;
        v3[2] = 0;
        *(_WORD*)& v3[3] = sub_578AC0(a1);
        *(_WORD*)& v3[5] = sub_578AC0(a2);
    }
    return sub_4E5390(255, (int)v3, 7, 0, 1);
}

//----- (004D9900) --------------------------------------------------------
void __cdecl sub_4D9900(int a1)
{
    int v1; // ebp
    int v2; // esi
    _WORD* v3; // edi
    int v4; // eax
    int v5; // eax
    int i; // edi
    char* v7; // eax
    int j; // edi
    int v9; // ebx
    int v10; // eax
    int k; // edi
    int v12; // ebx
    int v13; // eax
    int v14; // eax
    _WORD* v15; // [esp+Ch] [ebp-4h]
    int v16; // [esp+14h] [ebp+4h]

    v1 = a1;
    if (a1 && *(_BYTE*)(a1 + 8) & 4)
    {
        v2 = *(_DWORD*)(a1 + 748);
        v3 = *(_WORD * *)(a1 + 556);
        v15 = *(_WORD * *)(a1 + 556);
        v16 = *(int*)(v2 + 228);
        if (*(float*)(v2 + 232) != *(float*)& v16)
        {
            sub_4D8A30(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v16);
            *(_DWORD*)(v2 + 232) = *(_DWORD*)(v2 + 228);
        }
        v4 = *(_DWORD*)(v2 + 276);
        if (*(_DWORD*)(v4 + 2168) != *(_DWORD*)(v4 + 2164))
        {
            sub_4D8870(*(unsigned __int8*)(v4 + 2064), v1);
            *(_DWORD*)(*(_DWORD*)(v2 + 276) + 2168) = *(_DWORD*)(*(_DWORD*)(v2 + 276) + 2164);
        }
        v5 = *(_DWORD*)(v2 + 276);
        if (*(_BYTE*)(v5 + 2172) != *(_BYTE*)(v1 + 440))
        {
            sub_4D8840(*(unsigned __int8*)(v5 + 2064), v1);
            *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2172) = *(_BYTE*)(v1 + 440);
        }
        if (sub_40A5C0(4096))
        {
            for (i = 0; i < 32; ++i)
            {
                v7 = sub_417090(i);
                if (v7 && *((_DWORD*)v7 + 514) && *(_DWORD*)(v2 + 320) != *(unsigned __int8*)(i + v2 + 452))
                {
                    sub_4D9D60(i, v1);
                    *(_BYTE*)(i + v2 + 452) = *(_BYTE*)(v2 + 320);
                }
            }
            for (j = 0; j < 32; ++j)
            {
                v9 = 0;
                if (!*(_DWORD*)& byte_5D4594[1556324])
                    * (_DWORD*)& byte_5D4594[1556324] = sub_4E3AA0((CHAR*)& byte_587000[199072]);
                if (sub_417090(j))
                {
                    v10 = sub_4E7980(v1);
                    if (v10)
                    {
                        while (*(unsigned __int16*)(v10 + 4) != *(_DWORD*)& byte_5D4594[1556324])
                        {
                            v10 = sub_4E7990(v10);
                            if (!v10)
                                goto LABEL_25;
                        }
                        v9 = 1;
                    }
                    LABEL_25:
                    if (v9 != *(unsigned __int8*)(j + v2 + 484))
                    {
                        sub_4D9DF0(j, v1, v9);
                        *(_BYTE*)(j + v2 + 484) = v9;
                    }
                }
            }
            for (k = 0; k < 32; ++k)
            {
                v12 = 0;
                if (!*(_DWORD*)& byte_5D4594[1556328])
                    * (_DWORD*)& byte_5D4594[1556328] = sub_4E3AA0((CHAR*)& byte_587000[199084]);
                if (sub_417090(k))
                {
                    v13 = sub_4E7980(v1);
                    if (v13)
                    {
                        while (*(unsigned __int16*)(v13 + 4) != *(_DWORD*)& byte_5D4594[1556328])
                        {
                            v13 = sub_4E7990(v13);
                            if (!v13)
                                goto LABEL_37;
                        }
                        v12 = 1;
                    }
                    LABEL_37:
                    if (v12 != *(unsigned __int8*)(k + v2 + 516))
                    {
                        sub_4D9E30(k, v1, v12);
                        *(_BYTE*)(k + v2 + 516) = v12;
                    }
                }
            }
            v3 = v15;
        }
        v14 = *(_DWORD*)(v2 + 276);
        if (*(_BYTE*)(v14 + 2184))
        {
            sub_4D85C0(*(unsigned __int8*)(v14 + 2064), (_DWORD*)v1);
            sub_4D88C0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v1);
            sub_4D8990(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v1, *(_BYTE*)(*(_DWORD*)(v2 + 276) + 3684));
            *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2184) = 0;
        }
        if (sub_43AF70() == 1)
        {
            sub_528030(v1);
        }
        else
        {
            if (v3 && *v3 != *(_WORD*)(v2 + 10))
            {
                sub_4D86E0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
                *(_WORD*)(v2 + 10) = *v3;
            }
            if (*(_WORD*)(v2 + 4) != *(_WORD*)(v2 + 6))
            {
                sub_4D8930(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v1);
                *(_WORD*)(v2 + 6) = *(_WORD*)(v2 + 4);
            }
        }
    }
}

//----- (004D9C20) --------------------------------------------------------
int __cdecl sub_4D9C20(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // edx
    char v4[17]; // [esp+0h] [ebp-14h]

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        v4[0] = -17;
        if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
        {
            if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251) == 1)
            {
                *(_DWORD*)& v4[1] = *(_DWORD*)& byte_587000[312816];
                *(_DWORD*)& v4[5] = *(_DWORD*)& byte_587000[312820];
                v3 = *(_DWORD*)& byte_587000[312828];
                *(_DWORD*)& v4[9] = *(_DWORD*)& byte_587000[312824];
            }
            else
            {
                result = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2251) - 2;
                if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251) != 2)
                    return result;
                *(_DWORD*)& v4[1] = *(_DWORD*)& byte_587000[312800];
                *(_DWORD*)& v4[5] = *(_DWORD*)& byte_587000[312804];
                v3 = *(_DWORD*)& byte_587000[312812];
                *(_DWORD*)& v4[9] = *(_DWORD*)& byte_587000[312808];
            }
        }
        else
        {
            *(_DWORD*)& v4[1] = *(_DWORD*)& byte_587000[312784];
            *(_DWORD*)& v4[5] = *(_DWORD*)& byte_587000[312788];
            v3 = *(_DWORD*)& byte_587000[312796];
            *(_DWORD*)& v4[9] = *(_DWORD*)& byte_587000[312792];
        }
        *(_DWORD*)& v4[13] = v3;
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 17, 0, 1);
    }
    return result;
}

//----- (004D9CF0) --------------------------------------------------------
int __cdecl sub_4D9CF0(int a1)
{
    char v2[2]; // [esp+0h] [ebp-2h]

    v2[0] = -16;
    v2[1] = 0;
    return sub_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (004D9D20) --------------------------------------------------------
int __cdecl sub_4D9D20(int a1, int a2)
{
    __int16 v3; // cx
    char v5[4]; // [esp+0h] [ebp-4h]

    v3 = *(_WORD*)(a2 + 36);
    *(_WORD*)v5 = 496;
    *(_WORD*)& v5[2] = v3;
    return sub_4E5390(a1, (int)v5, 4, 0, 1);
}

//----- (004D9D60) --------------------------------------------------------
int __cdecl sub_4D9D60(int a1, int a2)
{
    int v2; // edx
    char v4[5]; // [esp+0h] [ebp-8h]

    v4[0] = -16;
    v4[1] = 4;
    v2 = *(_DWORD*)(a2 + 748);
    *(_WORD*)& v4[3] = *(_WORD*)(a2 + 36);
    v4[2] = *(_BYTE*)(v2 + 320);
    return sub_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9DB0) --------------------------------------------------------
int __cdecl sub_4D9DB0(int a1, int a2, int a3)
{
    char v4[8]; // [esp+0h] [ebp-8h]

    *(_WORD*)& v4[6] = *(_WORD*)(a2 + 36);
    v4[0] = -16;
    v4[1] = 21;
    *(_DWORD*)& v4[2] = a3;
    return sub_4E5420(a1, v4, 8, 0, 1);
}

//----- (004D9DF0) --------------------------------------------------------
int __cdecl sub_4D9DF0(int a1, int a2, char a3)
{
    char v4[5]; // [esp+0h] [ebp-8h]

    *(_WORD*)& v4[3] = *(_WORD*)(a2 + 36);
    v4[0] = -16;
    v4[1] = 22;
    v4[2] = a3;
    return sub_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9E30) --------------------------------------------------------
int __cdecl sub_4D9E30(int a1, int a2, char a3)
{
    char v4[5]; // [esp+0h] [ebp-8h]

    *(_WORD*)& v4[3] = *(_WORD*)(a2 + 36);
    v4[0] = -16;
    v4[1] = 23;
    v4[2] = a3;
    return sub_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9E70) --------------------------------------------------------
int __cdecl sub_4D9E70(int a1)
{
    char v2[2]; // [esp+0h] [ebp-2h]

    v2[0] = -16;
    v2[1] = 20;
    return sub_4E5420(a1, v2, 2, 0, 1);
}

//----- (004D9EA0) --------------------------------------------------------
void sub_4D9EA0()
{
    nox_srand(0x2311u);
}

//----- (004D9EB0) --------------------------------------------------------
int sub_4D9EB0(int a1, wchar_t* a2, ...)
{
    int result; // eax
    int v3; // esi
    char v4; // al
    int v5; // eax
    wchar_t v6[516]; // [esp+4h] [ebp-408h]
    va_list va; // [esp+418h] [ebp+Ch]

    va_start(va, a2);
    result = a1;
    if (a1 && *(_BYTE*)(a1 + 8) & 4)
    {
        v3 = *(_DWORD*)(a1 + 748);
        nox_vswprintf(&v6[260], a2, va);
        LOBYTE(v6[0]) = -88;
        *(wchar_t*)((char*)v6 + 1) = 0;
        HIBYTE(v6[1]) = 0;
        if (sub_4100F0((__int16*)& v6[260]))
            v4 = HIBYTE(v6[1]) | 2;
        else
            v4 = HIBYTE(v6[1]) | 4;
        HIBYTE(v6[1]) = v4;
        v6[2] = 0;
        v6[3] = 0;
        LOBYTE(v6[5]) = 0;
        v6[4] = (unsigned __int8)(nox_wcslen(&v6[260]) + 1);
        if (v6[1] & 0x400)
        {
            nox_wcscpy((wchar_t*)((char*)& v6[5] + 1), &v6[260]);
            v5 = 2;
        }
        else
        {
            nox_sprintf((char*)& v6[5] + 1, "%S", &v6[260]);
            v5 = 1;
        }
        result = sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, v6, v5 * LOBYTE(v6[4]) + 11);
    }
    return result;
}

//----- (004D9FD0) --------------------------------------------------------
int sub_4D9FD0(char a1, wchar_t* a2, ...)
{
    char v2; // al
    int v3; // edi
    int result; // eax
    int i; // esi
    wchar_t v6[516]; // [esp+Ch] [ebp-408h]
    va_list va; // [esp+420h] [ebp+Ch]

    va_start(va, a2);
    nox_vswprintf(&v6[260], a2, va);
    LOBYTE(v6[0]) = -88;
    *(wchar_t*)((char*)v6 + 1) = 0;
    HIBYTE(v6[1]) = a1;
    if (sub_4100F0((__int16*)& v6[260]))
        v2 = HIBYTE(v6[1]) | 2;
    else
        v2 = HIBYTE(v6[1]) | 4;
    HIBYTE(v6[1]) = v2;
    v6[2] = 0;
    v6[3] = 0;
    LOBYTE(v6[5]) = 0;
    v6[4] = (unsigned __int8)(nox_wcslen(&v6[260]) + 1);
    if (v6[1] & 0x400)
    {
        nox_wcscpy((wchar_t*)((char*)& v6[5] + 1), &v6[260]);
        v3 = 2;
    }
    else
    {
        nox_sprintf((char*)& v6[5] + 1, "%S", &v6[260]);
        v3 = 1;
    }
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 1, v6, v3 * LOBYTE(v6[4]) + 11);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DA0F0) --------------------------------------------------------
int __cdecl sub_4DA0F0(int a1, int a2, int* a3)
{
    int result; // eax
    int v4; // edx
    char v5[6]; // [esp+0h] [ebp-8h]

    result = a2;
    switch (a2)
    {
        case 0:
        case 1:
        case 2:
        case 12:
        case 13:
        case 16:
        case 20:
        case 21:
            v5[1] = a2;
            v4 = *a3;
            v5[0] = -87;
            *(_DWORD*)& v5[2] = v4;
            result = sub_40EBC0(a1, 1, v5, 6);
            break;
        case 17:
            LOWORD(a2) = 4521;
            result = sub_40EBC0(a1, 1, &a2, 2);
            break;
        default:
            return result;
    }
    return result;
}

//----- (004DA180) --------------------------------------------------------
int __cdecl sub_4DA180(int a1, _BYTE* a2)
{
    int result; // eax
    int i; // esi
    int j; // esi
    int k; // esi
    char v6[6]; // [esp+8h] [ebp-8h]

    result = a1;
    switch (a1)
    {
        case 3:
        case 4:
        case 8:
        case 18:
        case 19:
        case 21:
            v6[1] = a1;
            v6[0] = -87;
            *(_DWORD*)& v6[2] = *(_DWORD*)a2;
            result = sub_4DA7C0();
            for (i = result; result; i = result)
            {
                sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 1, v6, 6);
                result = sub_4DA7F0(i);
            }
            break;
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11:
            *a2 = -87;
            a2[1] = a1;
            result = sub_4DA7C0();
            for (j = result; result; j = result)
            {
                sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(j + 748) + 276) + 2064), 1, a2, 10);
                result = sub_4DA7F0(j);
            }
            break;
        case 14:
            *a2 = -87;
            a2[1] = a1;
            result = sub_4DA7C0();
            for (k = result; result; k = result)
            {
                sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(k + 748) + 276) + 2064), 1, a2, 11);
                result = sub_4DA7F0(k);
            }
            break;
        default:
            return result;
    }
    return result;
}

//----- (004DA2C0) --------------------------------------------------------
void __cdecl sub_4DA2C0(int a1, const char* a2, char a3)
{
    int v3; // edx
    char v4[52]; // [esp+Ch] [ebp-34h]

    if (a1 && *(_BYTE*)(a1 + 8) & 4 && a2 && !sub_419E60(a1) && strlen(a2) && strlen(a2) <= 0x30)
    {
        v4[2] = a3;
        v4[0] = -87;
        v4[1] = 15;
        v3 = *(_DWORD*)(a1 + 748);
        strcpy(&v4[3], a2);
        sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, v4, strlen(a2) + 4);
    }
}

//----- (004DA390) --------------------------------------------------------
int __cdecl sub_4DA390(const char* a1)
{
    int result; // eax
    int i; // esi

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4DA2C0(i, a1, 0);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DA3C0) --------------------------------------------------------
int __cdecl sub_4DA3C0(_DWORD* a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1556844];
    *a1 = *(_DWORD*)& byte_5D4594[1556844];
    *(_DWORD*)& byte_5D4594[1556844] = 0;
    return result;
}

//----- (004DA3E0) --------------------------------------------------------
int __cdecl sub_4DA3E0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1556844] = a1;
    return result;
}

//----- (004DA3F0) --------------------------------------------------------
BOOL __cdecl sub_4DA3F0(const char* a1, const char* a2)
{
    char* v2; // eax
    const char* v3; // edi
    const char* v4; // ebx
    char* v5; // eax
    const char* v6; // ecx
    const char* v7; // esi
    BOOL result; // eax

    strcpy((char*)& byte_5D4594[1556332], a1);
    strcpy((char*)& byte_5D4594[1556588], a2);
    v2 = strchr((const char*)& byte_5D4594[1556332], 58);
    if (v2)
    {
        v3 = (const char*)& byte_5D4594[1556332];
        *v2 = 0;
        v4 = v2 + 1;
    }
    else
    {
        v3 = 0;
        v4 = (const char*)& byte_5D4594[1556332];
    }
    v5 = strchr((const char*)& byte_5D4594[1556588], 58);
    if (v5)
    {
        v6 = (const char*)& byte_5D4594[1556588];
        *v5 = 0;
        v7 = v5 + 1;
    }
    else
    {
        v6 = 0;
        v7 = (const char*)& byte_5D4594[1556588];
    }
    if (v3 && v6 && _strcmpi(v3, v6))
        result = 0;
    else
        result = strcmp(v4, v7) == 0;
    return result;
}

//----- (004DA4F0) --------------------------------------------------------
int __cdecl sub_4DA4F0(char* a1)
{
    int i; // esi
    int result; // eax
    int v3; // esi
    int v4; // esi
    int v5; // esi

    if (strchr(a1, 58))
    {
        for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
        {
            result = sub_4DA5C0(i, a1);
            if (result)
                return result;
        }
        v3 = sub_4DA870();
        if (v3)
        {
            do
            {
                result = sub_4DA5C0(v3, a1);
                if (result)
                    break;
                result = sub_4DA880(v3);
                v3 = result;
            } while (result);
            return result;
        }
        return 0;
    }
    v4 = sub_4DA790();
    if (v4)
    {
        while (1)
        {
            result = sub_4DA660(v4, a1);
            if (result)
                break;
            v4 = sub_4DA7A0(v4);
            if (!v4)
                goto LABEL_12;
        }
    }
    else
    {
        LABEL_12:
        v5 = sub_4DA870();
        if (!v5)
            return 0;
        while (1)
        {
            result = sub_4DA660(v5, a1);
            if (result)
                break;
            v5 = sub_4DA880(v5);
            if (!v5)
                return 0;
        }
    }
    return result;
}

//----- (004DA5C0) --------------------------------------------------------
int __cdecl sub_4DA5C0(int a1, const char* a2)
{
    int v2; // edi

    v2 = a1;
    if (*(_DWORD*)a1 && !strcmp(*(const char**)a1, a2))
        return v2;
    v2 = *(_DWORD*)(a1 + 504);
    if (v2)
    {
        while (!*(_DWORD*)v2 || strcmp(*(const char**)v2, a2))
        {
            v2 = *(_DWORD*)(v2 + 496);
            if (!v2)
                return 0;
        }
        return v2;
    }
    return 0;
}

//----- (004DA660) --------------------------------------------------------
int __cdecl sub_4DA660(int a1, const char* a2)
{
    int i; // edi
    char* v3; // eax
    const char* v4; // esi
    const char* v5; // eax
    bool v6; // cf
    unsigned __int8 v7; // dl
    unsigned __int8 v8; // bl
    int v9; // eax
    const char* v10; // eax
    unsigned __int8 v11; // dl
    unsigned __int8 v12; // bl
    char* v14; // eax

    i = a1;
    if (*(_DWORD*)a1)
    {
        v3 = strchr(*(const char**)a1, 58);
        v4 = a2;
        if (v3)
        {
            v5 = v3 + 1;
            while (1)
            {
                v6 = *v5 < (unsigned int)* v4;
                if (*v5 != *v4)
                    break;
                if (*v5)
                {
                    v7 = v5[1];
                    v8 = v4[1];
                    v6 = v7 < v8;
                    if (v7 != v8)
                        break;
                    v5 += 2;
                    v4 += 2;
                    if (v7)
                        continue;
                }
                v9 = 0;
                goto LABEL_16;
            }
        }
        else
        {
            v10 = *(const char**)a1;
            while (1)
            {
                v6 = *v10 < (unsigned int)* v4;
                if (*v10 != *v4)
                    break;
                if (*v10)
                {
                    v11 = v10[1];
                    v12 = v4[1];
                    v6 = v11 < v12;
                    if (v11 != v12)
                        break;
                    v10 += 2;
                    v4 += 2;
                    if (v11)
                        continue;
                }
                v9 = 0;
                goto LABEL_16;
            }
        }
        v9 = -(int)v6 - ((int)v6 - 1);
        LABEL_16:
        if (!v9)
            return i;
    }
    for (i = *(_DWORD*)(a1 + 504); i; i = *(_DWORD*)(i + 496))
    {
        if (*(_DWORD*)i)
        {
            v14 = strchr(*(const char**)i, 58);
            if (v14)
            {
                if (!strcmp(v14 + 1, a2))
                    return i;
            }
            else if (!strcmp(*(const char**)i, a2))
            {
                return i;
            }
        }
    }
    return 0;
}

//----- (004DA790) --------------------------------------------------------
int sub_4DA790()
{
    return *(_DWORD*)& byte_5D4594[1556844];
}

//----- (004DA7A0) --------------------------------------------------------
int __cdecl sub_4DA7A0(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 444);
    else
        result = 0;
    return result;
}

//----- (004DA7C0) --------------------------------------------------------
int sub_4DA7C0()
{
    char* v0; // eax

    v0 = sub_416EA0();
    if (!v0)
        return 0;
    while (!*((_DWORD*)v0 + 514))
    {
        v0 = sub_416EE0((int)v0);
        if (!v0)
            return 0;
    }
    return *((_DWORD*)v0 + 514);
}

//----- (004DA7F0) --------------------------------------------------------
int __cdecl sub_4DA7F0(int a1)
{
    char* v1; // eax

    if (!a1)
        return 0;
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v1 = sub_416EE0(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276));
    if (!v1)
        return 0;
    while (!*((_DWORD*)v1 + 514))
    {
        v1 = sub_416EE0((int)v1);
        if (!v1)
            return 0;
    }
    return *((_DWORD*)v1 + 514);
}

//----- (004DA840) --------------------------------------------------------
int sub_4DA840()
{
    return *(_DWORD*)& byte_5D4594[1556848];
}

//----- (004DA850) --------------------------------------------------------
int __cdecl sub_4DA850(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 444);
    else
        result = 0;
    return result;
}

//----- (004DA870) --------------------------------------------------------
int sub_4DA870()
{
    return *(_DWORD*)& byte_5D4594[1556860];
}

//----- (004DA880) --------------------------------------------------------
int __cdecl sub_4DA880(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 444);
    else
        result = 0;
    return result;
}

//----- (004DA8A0) --------------------------------------------------------
int sub_4DA8A0()
{
    return *(_DWORD*)& byte_5D4594[1556852];
}

//----- (004DA8B0) --------------------------------------------------------
int __cdecl sub_4DA8B0(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 476);
    else
        result = 0;
    return result;
}

//----- (004DA8D0) --------------------------------------------------------
int __cdecl sub_4DA8D0(int a1)
{
    int result; // eax

    result = a1;
    if (!*(_DWORD*)(a1 + 484) && !(*(_BYTE*)(a1 + 8) & 1))
    {
        *(_DWORD*)(a1 + 480) = 0;
        *(_DWORD*)(a1 + 476) = *(_DWORD*)& byte_5D4594[1556852];
        if (*(_DWORD*)& byte_5D4594[1556852])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1556852] + 480) = a1;
        *(_DWORD*)& byte_5D4594[1556852] = a1;
        *(_DWORD*)(a1 + 484) = 1;
        *(_DWORD*)(a1 + 520) = 0;
    }
    return result;
}

//----- (004DA920) --------------------------------------------------------
_DWORD* __cdecl sub_4DA920(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx
    int v4; // ecx

    result = a1;
    if (a1[121])
    {
        v2 = a1[120];
        if (v2)
        {
            *(_DWORD*)(v2 + 476) = a1[119];
            v3 = a1[119];
            if (v3)
            {
                *(_DWORD*)(v3 + 480) = a1[120];
                a1[121] = 0;
                a1[130] = 0;
                return result;
            }
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1556852] = a1[119];
            v4 = a1[119];
            if (v4)
                * (_DWORD*)(v4 + 480) = 0;
        }
        a1[121] = 0;
        a1[130] = 0;
    }
    return result;
}

//----- (004DA9A0) --------------------------------------------------------
_DWORD* __cdecl sub_4DA9A0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx

    result = a1;
    v2 = a1[4];
    if (!(v2 & 0x410000))
    {
        a1[118] = 0;
        a1[4] = v2 | 0x10000;
        a1[117] = *(_DWORD*)& byte_5D4594[1556856];
        if (*(_DWORD*)& byte_5D4594[1556856])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1556856] + 472) = a1;
        *(_DWORD*)& byte_5D4594[1556856] = a1;
    }
    return result;
}

//----- (004DA9F0) --------------------------------------------------------
_DWORD* __cdecl sub_4DA9F0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx
    int v4; // ecx

    result = a1;
    v2 = a1[4];
    if (v2 & 0x10000)
    {
        a1[4] = v2 & 0xFFFEFFFF;
        v3 = a1[118];
        if (v3)
            * (_DWORD*)(v3 + 468) = a1[117];
        else
            *(_DWORD*)& byte_5D4594[1556856] = a1[117];
        v4 = a1[117];
        if (v4)
            * (_DWORD*)(v4 + 472) = a1[118];
    }
    return result;
}

//----- (004DAA50) --------------------------------------------------------
char __cdecl sub_4DAA50(int a1, int a2, float a3, float a4)
{
    int v4; // eax
    int v5; // eax
    int v6; // ecx
    int v7; // eax

    if (!*(_DWORD*)& byte_5D4594[1556864])
    {
        *(_DWORD*)& byte_5D4594[1556864] = sub_4E3AA0((CHAR*)& byte_587000[199100]);
        *(_DWORD*)& byte_5D4594[1556868] = sub_4E3AA0((CHAR*)& byte_587000[199108]);
        *(_DWORD*)& byte_5D4594[1556872] = sub_4E3AA0((CHAR*)& byte_587000[199124]);
    }
    v4 = *(_DWORD*)(a1 + 16);
    if (!(v4 & 0x24))
    {
        *(_DWORD*)(a1 + 16) = v4 & 0x35E9FEDB;
        *(float*)(a1 + 72) = a3;
        *(float*)(a1 + 56) = a3;
        *(float*)(a1 + 64) = a3;
        *(float*)(a1 + 76) = a4;
        *(float*)(a1 + 60) = a4;
        v5 = *(_DWORD*)(a1 + 56);
        *(float*)(a1 + 68) = a4;
        *(_DWORD*)(a1 + 156) = v5;
        *(float*)(a1 + 160) = a4;
        sub_4E7290(a1);
        if (*(_BYTE*)(a1 + 8) & 6)
            sub_4E7F10(a1);
        if (a2)
            sub_4EC290(a2, a1);
        v6 = *(_DWORD*)(a1 + 16);
        *(_DWORD*)(a1 + 80) = 0;
        *(_DWORD*)(a1 + 84) = 0;
        *(_DWORD*)(a1 + 88) = 0;
        *(_DWORD*)(a1 + 92) = 0;
        *(_DWORD*)(a1 + 16) = v6 | 4;
        *(_DWORD*)(a1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
        *(_DWORD*)(a1 + 128) = *(_DWORD*)& byte_5D4594[2598000];
        if (sub_40A5C0(0x2000)
            && !sub_40A5C0(4096)
            && (*(unsigned __int16*)(a1 + 4) == *(_DWORD*)& byte_5D4594[1556864] || *(_DWORD*)(a1 + 8) & 0x3001110)
            && !(*(_BYTE*)(a1 + 8) & 1))
        {
            v7 = *(_DWORD*)(a1 + 16);
            LOBYTE(v7) = v7 | 0x40;
            *(_DWORD*)(a1 + 16) = v7;
        }
        *(_DWORD*)(a1 + 448) = 0;
        *(_DWORD*)(a1 + 444) = *(_DWORD*)& byte_5D4594[1556860];
        if (*(_DWORD*)& byte_5D4594[1556860])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1556860] + 448) = a1;
        *(_DWORD*)& byte_5D4594[1556860] = a1;
        LOBYTE(v4) = *(_BYTE*)(a1 + 52);
        *(_DWORD*)(a1 + 16) |= 0x2000000u;
        if ((_BYTE)v4 && (!(*(_DWORD*)(a1 + 8) & 0x10000000) || (int) * (_DWORD*)& byte_5D4594[3803228] >= 0))
        {
            if (sub_40A5C0(2048) || (v4 = sub_417DA0(4)) != 0)
                LOBYTE(v4) = (unsigned int)sub_4191D0(*(_BYTE*)(a1 + 52), a1 + 48, 0, *(_DWORD*)(a1 + 36), 0);
        }
    }
    return v4;
}

//----- (004DAC00) --------------------------------------------------------
void sub_4DAC00()
{
    int v0; // esi
    int v1; // eax
    int i; // ebp
    int v3; // eax
    void(__cdecl * v4)(int, _DWORD); // eax
    unsigned int v5; // ecx
    int v6; // eax

    v0 = *(_DWORD*)& byte_5D4594[1556860];
    if (*(_DWORD*)& byte_5D4594[1556860])
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 508);
            for (i = *(_DWORD*)(v0 + 444); v1; v1 = *(_DWORD*)(v0 + 508))
            {
                if (!(*(_BYTE*)(v1 + 16) & 0x20))
                    break;
                sub_4EC290(*(_DWORD*)(v1 + 508), v0);
            }
            if (*(_BYTE*)(v0 + 8) & 1)
            {
                *(_DWORD*)(v0 + 448) = 0;
                *(_DWORD*)(v0 + 444) = *(_DWORD*)& byte_5D4594[1556848];
                if (*(_DWORD*)& byte_5D4594[1556848])
                    * (_DWORD*)(*(_DWORD*)& byte_5D4594[1556848] + 448) = v0;
                *(_DWORD*)& byte_5D4594[1556848] = v0;
            }
            else
            {
                v3 = *(_DWORD*)(v0 + 16);
                if (v3 & 0x10000)
                {
                    *(_DWORD*)(v0 + 16) = v3 & 0xFFFEFFFF;
                    sub_4DA9A0((_DWORD*)v0);
                }
                if (*(_DWORD*)(v0 + 16) & 0x80000 && !sub_40A5C0(4096))
                    sub_4EC5E0(v0);
                if ((*(_DWORD*)(v0 + 744) || *(float*)(v0 + 80) != 0.0 || *(float*)(v0 + 84) != 0.0)
                    && (signed char) * (_BYTE*)(v0 + 8) >= 0)
                {
                    sub_4DA8D0(v0);
                }
                *(_DWORD*)(v0 + 448) = 0;
                *(_DWORD*)(v0 + 444) = *(_DWORD*)& byte_5D4594[1556844];
                if (*(_DWORD*)& byte_5D4594[1556844])
                    * (_DWORD*)(*(_DWORD*)& byte_5D4594[1556844] + 448) = v0;
                *(_DWORD*)& byte_5D4594[1556844] = v0;
            }
            sub_517640(v0);
            if (*(_DWORD*)(v0 + 696))
                sub_5117F0(v0);
            v4 = *(void(__cdecl * *)(int, _DWORD))(v0 + 688);
            if (v4)
                v4(v0, 0);
            v5 = *(_DWORD*)(v0 + 8);
            if (v5 & 0x400000)
            {
                if (*(_DWORD*)(v0 + 12) & 0x18)
                    v6 = 0;
                else
                    v6 = (unsigned __int8)~*(_BYTE*)(v0 + 12) >> 7;
            }
            else
            {
                v6 = (v5 >> 29) & 1;
            }
            if (0x800000 & v5 || !v6)
            {
                sub_4E44F0(v0);
                if (!(*(_DWORD*)(v0 + 8) & 0x20400000))
                    * (_DWORD*)(v0 + 148) = 0;
            }
            else
            {
                sub_4E44E0(v0);
                sub_527E00(v0);
                *(_DWORD*)(v0 + 148) = -1;
            }
            *(_DWORD*)(v0 + 16) &= 0xFDFFFFFF;
            v0 = i;
        } while (i);
        *(_DWORD*)& byte_5D4594[1556860] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1556860] = 0;
    }
}

//----- (004DADE0) --------------------------------------------------------
char __cdecl sub_4DADE0(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)(a1 + 16);
    if (v1 & 4)
    {
        LOBYTE(v1) = v1 & 0xFB;
        *(_DWORD*)(a1 + 16) = v1;
        sub_4E60A0(a1);
        if (!sub_40A5C0(0x80000))
            sub_5289D0(a1);
        sub_511810(a1);
        sub_4EC300(a1);
        sub_4EC470(a1);
        sub_517870(a1);
        sub_4DAE50(a1);
        sub_4ECFA0(a1);
        sub_511DE0(a1);
        LOBYTE(v1) = *(_BYTE*)(a1 + 8);
        if (v1 & 6)
            LOBYTE(v1) = sub_528990(a1);
    }
    return v1;
}

//----- (004DAE50) --------------------------------------------------------
int __cdecl sub_4DAE50(int a1)
{
    int v1; // eax
    int result; // eax
    int v3; // esi
    int v4; // eax
    int v5; // esi

    sub_4DA9F0((_DWORD*)a1);
    if (*(_BYTE*)(a1 + 8) & 1)
    {
        v1 = *(_DWORD*)(a1 + 448);
        if (v1)
        {
            *(_DWORD*)(v1 + 444) = *(_DWORD*)(a1 + 444);
            result = *(_DWORD*)(a1 + 444);
            if (result)
                * (_DWORD*)(result + 448) = *(_DWORD*)(a1 + 448);
        }
        else
        {
            result = *(_DWORD*)(a1 + 444);
            *(_DWORD*)& byte_5D4594[1556848] = *(_DWORD*)(a1 + 444);
            v3 = *(_DWORD*)(a1 + 444);
            if (v3)
                * (_DWORD*)(v3 + 448) = 0;
        }
    }
    else
    {
        sub_4DA920((_DWORD*)a1);
        v4 = *(_DWORD*)(a1 + 448);
        if (v4)
        {
            *(_DWORD*)(v4 + 444) = *(_DWORD*)(a1 + 444);
            result = *(_DWORD*)(a1 + 444);
            if (result)
                * (_DWORD*)(result + 448) = *(_DWORD*)(a1 + 448);
        }
        else
        {
            result = *(_DWORD*)(a1 + 444);
            *(_DWORD*)& byte_5D4594[1556844] = *(_DWORD*)(a1 + 444);
            v5 = *(_DWORD*)(a1 + 444);
            if (v5)
                * (_DWORD*)(v5 + 448) = 0;
        }
    }
    return result;
}

//----- (004DAF10) --------------------------------------------------------
void sub_4DAF10()
{
    _DWORD* v0; // edi
    _DWORD* v1; // esi
    int v2; // eax
    int v3; // ecx
    _DWORD* v4; // eax
    int v5; // edx
    int v6; // edx
    int v7; // ecx
    int v8; // edx
    _DWORD* v9; // eax

    v0 = *(_DWORD * *)& byte_5D4594[1556860];
    v1 = *(_DWORD * *)& byte_5D4594[1556860];
    if (*(_DWORD*)& byte_5D4594[1556860])
    {
        do
        {
            v2 = v1[2];
            if (v2 & 0x4000)
            {
                v3 = v1[187];
                v4 = v0;
                if (v0)
                {
                    while (1)
                    {
                        v5 = v4[2];
                        if ((v5 & 0x8000) != 0)
                        {
                            v6 = v4[187];
                            if (*(_DWORD*)(v3 + 8) == v4[10])
                                break;
                        }
                        v4 = (_DWORD*)v4[111];
                        if (!v4)
                            goto LABEL_9;
                    }
                    *(_DWORD*)(v3 + 4) = v4;
                    *(_DWORD*)(v6 + 4) = v1;
                    v0 = *(_DWORD * *)& byte_5D4594[1556860];
                }
            }
            LABEL_9:
            if (v1[2] & 0x400)
            {
                v7 = v1[187];
                v8 = *(_DWORD*)(v7 + 16);
                *(_DWORD*)(v7 + 12) = 0;
                v0 = *(_DWORD * *)& byte_5D4594[1556860];
                if (v8)
                {
                    v9 = *(_DWORD * *)& byte_5D4594[1556860];
                    if (*(_DWORD*)& byte_5D4594[1556860])
                    {
                        while (!(v9[2] & 0x400) || v8 != v9[10])
                        {
                            v9 = (_DWORD*)v9[111];
                            if (!v9)
                                goto LABEL_17;
                        }
                        *(_DWORD*)(v7 + 12) = v9;
                        v0 = *(_DWORD * *)& byte_5D4594[1556860];
                    }
                }
            }
            LABEL_17:
            v1 = (_DWORD*)v1[111];
        } while (v1);
    }
}

//----- (004DAFD0) --------------------------------------------------------
_DWORD* __cdecl sub_4DAFD0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx
    int v4; // ecx

    result = a1;
    v2 = a1[4];
    if (v2 & 4)
    {
        a1[4] = v2 & 0xFFFFFFFB;
        v3 = a1[112];
        if (v3)
        {
            *(_DWORD*)(v3 + 444) = a1[111];
            v4 = a1[111];
            if (v4)
            {
                result = (_DWORD*)a1[112];
                *(_DWORD*)(v4 + 448) = result;
            }
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1556844] = a1[111];
            result = (_DWORD*)a1[111];
            if (result)
                result[112] = 0;
        }
    }
    return result;
}

//----- (004DB030) --------------------------------------------------------
_DWORD* sub_4DB030()
{
    _DWORD* result; // eax
    _DWORD* v1; // ecx
    int v2; // edx

    result = *(_DWORD * *)& byte_5D4594[1556860];
    if (*(_DWORD*)& byte_5D4594[1556860])
    {
        do
        {
            v1 = (_DWORD*)result[111];
            result[4] &= 0xFDFFFFFF;
            v2 = *(_DWORD*)& byte_5D4594[1556844];
            if (*(_DWORD*)& byte_5D4594[1556844])
            {
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1556844] + 448) = result;
                v2 = *(_DWORD*)& byte_5D4594[1556844];
            }
            result[111] = v2;
            result[112] = 0;
            *(_DWORD*)& byte_5D4594[1556844] = result;
            result = v1;
        } while (v1);
    }
    *(_DWORD*)& byte_5D4594[1556860] = 0;
    return result;
}

//----- (004DB090) --------------------------------------------------------
int sub_4DB090()
{
    return *(_DWORD*)& byte_587000[201376];
}

//----- (004DB0A0) --------------------------------------------------------
int sub_4DB0A0()
{
    byte_5D4594[1560984] = byte_5D4594[1563136];
    *(_DWORD*)& byte_5D4594[1563080] = 0;
    *(_DWORD*)& byte_5D4594[1563084] = 0;
    *(_DWORD*)& byte_5D4594[1563096] = 0;
    *(_DWORD*)& byte_5D4594[1563064] = 0;
    *(_DWORD*)& byte_5D4594[1563092] = 0;
    *(_DWORD*)& byte_5D4594[1563088] = 0;
    *(_DWORD*)& byte_5D4594[1563044] = 0;
    *(_DWORD*)& byte_5D4594[1563048] = 0;
    *(_DWORD*)& byte_5D4594[1563052] = 0;
    *(_DWORD*)& byte_5D4594[1563100] = 0;
    byte_5D4594[1563104] = byte_5D4594[1563140];
    return 1;
}

//----- (004DB100) --------------------------------------------------------
int sub_4DB100()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[1563080] = 0;
    *(_DWORD*)& byte_5D4594[1563084] = 0;
    *(_DWORD*)& byte_5D4594[1563096] = 0;
    *(_DWORD*)& byte_5D4594[1563064] = 0;
    *(_DWORD*)& byte_5D4594[1563092] = 0;
    *(_DWORD*)& byte_5D4594[1563088] = 0;
    *(_DWORD*)& byte_5D4594[1563072] = 0;
    *(_DWORD*)& byte_5D4594[1563068] = 0;
    return result;
}

//----- (004DB130) --------------------------------------------------------
unsigned int __cdecl sub_4DB130(const char* a1)
{
    unsigned int result; // eax

    result = strlen(a1) + 1;
    qmemcpy(&byte_5D4594[1557900], a1, result);
    return result;
}

//----- (004DB160) --------------------------------------------------------
unsigned __int8* sub_4DB160()
{
    return &byte_5D4594[1557900];
}

//----- (004DB170) --------------------------------------------------------
int __cdecl sub_4DB170(int a1, int a2, int a3)
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1563092] = a3;
    *(_DWORD*)& byte_5D4594[1563088] = *(_DWORD*)& byte_5D4594[2598000];
    result = a1;
    *(_DWORD*)& byte_5D4594[1563084] = a2;
    *(_DWORD*)& byte_5D4594[1563080] = a1;
    *(_DWORD*)& byte_5D4594[1563096] = a2 != 0;
    if (!a1)
        result = sub_4DCBD0(0);
    return result;
}

//----- (004DB1B0) --------------------------------------------------------
int sub_4DB1B0()
{
    return *(_DWORD*)& byte_5D4594[1563080];
}

//----- (004DB1C0) --------------------------------------------------------
int sub_4DB1C0()
{
    return *(_DWORD*)& byte_5D4594[1563084];
}

//----- (004DB1D0) --------------------------------------------------------
BOOL sub_4DB1D0()
{
    char* v0; // eax
    CHAR PathName[1024]; // [esp+0h] [ebp-400h]

    v0 = sub_409E10();
    nox_sprintf(PathName, "%s\\Save", v0);
    return _mkdir(PathName) != -1 || errno != 2;
}

//----- (004DB220) --------------------------------------------------------
int __cdecl sub_4DB220(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563056] = a1;
    return result;
}

//----- (004DB230) --------------------------------------------------------
int __cdecl sub_4DB230(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563060] = a1;
    return result;
}

//----- (004DB240) --------------------------------------------------------
int sub_4DB240()
{
    return *(_DWORD*)& byte_5D4594[1563056];
}

//----- (004DB250) --------------------------------------------------------
int sub_4DB250()
{
    return *(_DWORD*)& byte_5D4594[1563060];
}

//----- (004DB260) --------------------------------------------------------
char* sub_4DB260()
{
    return (char*)& byte_5D4594[1559960];
}

//----- (004DB270) --------------------------------------------------------
unsigned int __cdecl sub_4DB270(const char* a1)
{
    unsigned int result; // eax

    result = strlen(a1) + 1;
    qmemcpy(&byte_5D4594[1559960], a1, result);
    return result;
}

//----- (004DB2A0) --------------------------------------------------------
unsigned int __cdecl sub_4DB2A0(const char* a1)
{
    char* v1; // eax
    char* v2; // eax
    char v4[24]; // [esp+4h] [ebp-418h]
    char v5[1024]; // [esp+1Ch] [ebp-400h]

    strcpy(v5, a1);
    v1 = strrchr(v5, 58);
    if (v1)
        * v1 = 0;
    strcpy(&v4[4], v5);
    v4[strlen(v5)] = 0;
    v2 = sub_409E10();
    nox_sprintf((char*)& byte_5D4594[1558936], "%s\\Save\\%s\\%s\\%s", v2, &byte_587000[199148], &v4[4], v5);
    return _access((LPCSTR)& byte_5D4594[1558936], 0) != -1 ? (unsigned int)& byte_5D4594[1558936] : 0;
}

//----- (004DB370) --------------------------------------------------------
int __cdecl sub_4DB370(const char* a1)
{
    char* v1; // eax
    char* v2; // esi
    int v3; // eax
    int v4; // ecx
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    unsigned int v8; // ecx
    unsigned int v9; // eax
    wchar_t* v10; // eax
    char* v12; // [esp-8h] [ebp-810h]
    char* v13; // [esp-4h] [ebp-80Ch]
    char v14[1024]; // [esp+8h] [ebp-800h]
    char v15[1024]; // [esp+408h] [ebp-400h]

    sub_478000();
    sub_4606B0();
    v1 = sub_417090(31);
    v2 = v1;
    if (!v1)
        return 0;
    v3 = *((_DWORD*)v1 + 514);
    if (!v3)
        return 0;
    if (!a1)
        return 0;
    v4 = *(_DWORD*)(v3 + 16);
    if ((v4 & 0x8000) != 0)
        return 0;
    if (!sub_4DB1D0())
        return 0;
    if (!sub_4DB540((int)& byte_587000[199176]))
        return 0;
    v5 = sub_409B40();
    if (!sub_4DB5A0((int)& byte_587000[199184], (int)v5))
        return 0;
    if (!sub_4DB600(*(int*)& byte_5D4594[1563084]))
        return 0;
    v13 = sub_409B40();
    v12 = sub_409B40();
    v6 = sub_409E10();
    nox_sprintf(v15, "%s\\Save\\%s\\%s\\%s.map", v6, &byte_587000[199192], v12, v13);
    if (!sub_51E010(v15, 0))
        return 0;
    sub_4DB6A0();
    v7 = sub_409E10();
    nox_sprintf(v14, "%s\\Save\\%s\\Player.plr", v7, &byte_587000[199224]);
    v8 = *(_DWORD*)& byte_5D4594[2660684] & 0xFFFFFFF7;
    *(_DWORD*)& byte_5D4594[2660684] &= 0xFFFFFFF7;
    if (*(_DWORD*)& byte_5D4594[1563076])
    {
        v9 = v8;
        LOBYTE(v9) = v8 | 8;
        *(_DWORD*)& byte_5D4594[2660684] = v9;
    }
    byte_5D4594[2661961] = sub_450750();
    if (!sub_41A140(v14, (unsigned __int8)v2[2064]))
        return 0;
    if (!sub_41A230(v14))
        return 0;
    if (strcmp(a1, "WORKING"))
    {
        v10 = loadString_sub_40F1D0((char*)& byte_587000[199312], 0, "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 661);
        sub_4D9FD0(0, v10);
        if (!sub_4DC100((int)& byte_587000[199332], (int)a1))
            return 0;
    }
    *(_DWORD*)& byte_5D4594[1563092] = 0;
    *(_DWORD*)& byte_5D4594[1563088] = 0;
    return 1;
}

//----- (004DB540) --------------------------------------------------------
BOOL __cdecl sub_4DB540(int a1)
{
    char* v1; // eax
    char PathName[1024]; // [esp+0h] [ebp-400h]

    v1 = sub_409E10();
    nox_sprintf(PathName, "%s\\Save\\%s", v1, a1);
    return _mkdir(PathName) != -1 || errno != 2;
}

//----- (004DB5A0) --------------------------------------------------------
BOOL __cdecl sub_4DB5A0(int a1, int a2)
{
    char* v2; // eax
    char PathName[1024]; // [esp+0h] [ebp-400h]

    v2 = sub_409E10();
    nox_sprintf(PathName, "%s\\Save\\%s\\%s", v2, a1, a2);
    return _mkdir(PathName) != -1 || errno != 2;
}

//----- (004DB600) --------------------------------------------------------
int __cdecl sub_4DB600(int a1)
{
    char* v1; // eax
    float* v2; // esi
    _DWORD* v3; // edi
    float v4; // eax
    float v5; // ecx
    int v6; // ecx
    int v7; // eax
    int v8; // esi

    v1 = sub_417090(31);
    if (!v1)
        return 0;
    v2 = (float*) * ((_DWORD*)v1 + 514);
    if (!v2)
        return 0;
    v3 = sub_4E3810((CHAR*)& byte_587000[199368]);
    if (!v3)
        return 0;
    v4 = v2[14];
    v5 = v2[15];
    if (a1)
    {
        v6 = *(_DWORD*)(a1 + 700);
        v4 = *(float*)(v6 + 80);
        v5 = *(float*)(v6 + 84);
    }
    sub_4DAA50((int)v3, 0, v4, v5);
    sub_4DAC00();
    v3[11] = *((_DWORD*)v2 + 11);
    v7 = *((_DWORD*)v2 + 129);
    if (v7)
    {
        do
        {
            v8 = *(_DWORD*)(v7 + 512);
            if (*(_BYTE*)(v7 + 16) & 4)
                sub_4EC290((int)v3, v7);
            v7 = v8;
        } while (v8);
    }
    return 1;
}

//----- (004DB6A0) --------------------------------------------------------
void sub_4DB6A0()
{
    char* v0; // eax
    char* v1; // edi
    int v2; // ebx
    int v3; // esi
    int v4; // ebp
    int v5; // eax

    v0 = sub_417090(31);
    v1 = v0;
    if (v0 && *((_DWORD*)v0 + 514))
    {
        if (!*(_DWORD*)& byte_5D4594[1563124])
            * (_DWORD*)& byte_5D4594[1563124] = sub_4E3AA0((CHAR*)& byte_587000[199388]);
        v2 = sub_4DA790();
        if (v2)
        {
            while (*(unsigned __int16*)(v2 + 4) != *(_DWORD*)& byte_5D4594[1563124])
            {
                v2 = sub_4DA7A0(v2);
                if (!v2)
                    return;
            }
            v3 = *(_DWORD*)(v2 + 516);
            if (v3)
            {
                do
                {
                    v4 = *(_DWORD*)(v3 + 512);
                    sub_4EC290(*((_DWORD*)v1 + 514), v3);
                    if (*(_BYTE*)(v3 + 8) & 2)
                    {
                        if (*(_BYTE*)(*(_DWORD*)(v3 + 748) + 1440) & 0x80)
                        {
                            v5 = *(_DWORD*)(v3 + 12);
                            LOBYTE(v5) = v5 | 0x80;
                            *(_DWORD*)(v3 + 12) = v5;
                            sub_4D91A0((unsigned __int8)v1[2064], v3);
                            sub_417190((unsigned __int8)v1[2064], v3, 1);
                        }
                    }
                    v3 = v4;
                } while (v4);
            }
            *(_DWORD*)(v2 + 44) = 0;
            sub_4E5CC0(v2);
        }
    }
}

//----- (004DB790) --------------------------------------------------------
char* __cdecl sub_4DB790(const char* a1)
{
    char* v1; // esi
    char* result; // eax

    sub_4DCC70(1);
    sub_40A4D0(0x8000000);
    sub_43F140(500);
    v1 = sub_4DB7E0(a1);
    sub_43F1A0();
    sub_40A540(0x8000000);
    result = v1;
    *(_DWORD*)& byte_5D4594[1563068] = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (004DB7E0) --------------------------------------------------------
char* __cdecl sub_4DB7E0(const char* a1)
{
    char* v1; // ebp
    char* result; // eax
    char* v3; // eax
    wchar_t* v4; // eax
    int v5; // eax
    char* v6; // eax
    wchar_t* v7; // eax
    char v8[20]; // [esp+Ch] [ebp-414h]
    char FileName[1024]; // [esp+20h] [ebp-400h]

    v1 = sub_417090(31);
    if (!a1)
        return 0;
    if (!sub_40A5C0(2) || (result = (char*)sub_4738D0()) != 0)
    {
        sub_4DB9C0();
        if (!strcmp(a1, "WORKING")
            || (result = (char*)sub_4DC100((int)a1, (int)& byte_587000[199416])) != 0)
        {
            v3 = sub_409E10();
            nox_sprintf(FileName, "%s\\Save\\%s\\Player.plr", v3, &byte_587000[199424]);
            if (_access(FileName, 0) == -1)
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[199504], 0, "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 755);
                sub_4D9FD0(0, v4);
                result = 0;
            }
            else
            {
                v5 = sub_41D090(FileName);
                sub_4E3C60(v5);
                sub_4E3C70();
                sub_4DB220(1);
                sub_4DB230(1);
                result = sub_41A2E0(FileName, 31);
                if (result)
                {
                    sub_460E60();
                    sub_4721D0();
                    nox_sprintf(v8, "%s.map", v1 + 4760);
                    sub_409D70(v8);
                    v6 = sub_409E10();
                    nox_sprintf(
                            (char*)& byte_5D4594[1559960],
                            "%s\\Save\\%s\\%s\\%s.map",
                            v6,
                            &byte_587000[199532],
                            v1 + 4760,
                            v1 + 4760);
                    sub_4D2450(v8);
                    sub_44E0B0(0);
                    result = (char*)sub_41A480(FileName);
                    if (result)
                    {
                        sub_450B70();
                        sub_445450();
                        sub_528D60();
                        v7 = loadString_sub_40F1D0((char*)& byte_587000[199612], 0, "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 824);
                        sub_4D9FD0(0, v7);
                        result = (char*)1;
                    }
                }
            }
        }
    }
    return result;
}

//----- (004DB9C0) --------------------------------------------------------
void sub_4DB9C0()
{
    int v0; // esi
    int v1; // edi
    int v2; // esi
    int v3; // edi

    v0 = sub_4DA790();
    if (v0)
    {
        do
        {
            v1 = sub_4DA7A0(v0);
            if (sub_4E5B50(v0))
                sub_4E5CC0(v0);
            v0 = v1;
        } while (v1);
    }
    v2 = sub_4DA840();
    if (v2)
    {
        do
        {
            v3 = sub_4DA850(v2);
            if (sub_4E5B80(v2))
                sub_4E5CC0(v2);
            v2 = v3;
        } while (v3);
    }
}

//----- (004DBA30) --------------------------------------------------------
char* __cdecl sub_4DBA30(int a1)
{
    char* result; // eax
    char* v2; // ebx
    int v3; // ebp
    int v4; // esi
    int v5; // edi
    int v6; // eax
    int v7; // esi
    int v8; // ebx
    int* v9; // ebp
    int v10; // eax
    int v11; // eax
    int v12; // eax
    int v13; // ebx
    int* v14; // edi
    int v15; // eax
    int v16; // ebx
    int v17; // eax
    int v18; // esi
    int v19; // edi
    int v20; // esi
    int v21; // edi
    int i; // esi
    int v23; // eax
    char* v24; // [esp+Ch] [ebp-8h]
    int v25; // [esp+10h] [ebp-4h]
    int v26; // [esp+18h] [ebp+4h]

    result = sub_417090(31);
    v2 = result;
    v3 = 0;
    v24 = result;
    if (result)
    {
        v4 = *((_DWORD*)result + 514);
        v25 = *((_DWORD*)result + 514);
        if (v4)
        {
            if (!*(_DWORD*)& byte_5D4594[1563128])
            {
                *(_DWORD*)& byte_5D4594[1563128] = sub_4E3AA0((CHAR*)& byte_587000[199624]);
                *(_DWORD*)& byte_5D4594[1563132] = sub_4E3AA0((CHAR*)& byte_587000[199644]);
            }
            if (a1 == 1)
            {
                v5 = sub_4DA790();
                if (v5)
                {
                    do
                    {
                        v26 = sub_4DA7A0(v5);
                        if (*(unsigned __int16*)(v5 + 4) == *(_DWORD*)& byte_5D4594[1563128])
                        {
                            sub_4E7010(*((_DWORD*)v2 + 514), (float2*)(v5 + 56));
                            *(_DWORD*)(*((_DWORD*)v2 + 514) + 44) = *(_DWORD*)(v5 + 44);
                            *(_DWORD*)(v5 + 44) = 0;
                            sub_4E5CC0(v5);
                        }
                        else
                        {
                            v6 = *(_DWORD*)(v5 + 8);
                            if (v6 & 2)
                            {
                                v7 = *(_DWORD*)(v5 + 748);
                                v8 = 0;
                                if (*(_BYTE*)(v7 + 1129))
                                {
                                    v9 = (int*)(v7 + 1132);
                                    do
                                    {
                                        v10 = sub_4ECF10(*v9);
                                        *v9 = v10;
                                        if (!v10)
                                            * (_BYTE*)(v7 + 1129) = 0;
                                        ++v8;
                                        ++v9;
                                    } while (v8 < *(unsigned __int8*)(v7 + 1129));
                                    v3 = 0;
                                }
                                *(_DWORD*)(v7 + 1196) = sub_4ECF10(*(_DWORD*)(v7 + 1196));
                                if ((int) * (_DWORD*)(v5 + 16) >= 0)
                                    sub_52BAF0(v5);
                                v11 = sub_4ECF10(*(_DWORD*)(v7 + 392));
                                if (v11)
                                    * (_DWORD*)(v7 + 392) = *(_DWORD*)(v11 + 36);
                                else
                                    *(_DWORD*)(v7 + 392) = 0;
                                v12 = sub_4ECF10(*(_DWORD*)(v7 + 1200));
                                if (v12)
                                    * (_DWORD*)(v7 + 1200) = *(_DWORD*)(v12 + 36);
                                else
                                    *(_DWORD*)(v7 + 1200) = 0;
                                *(_DWORD*)(v7 + 1216) = sub_4ECF10(*(_DWORD*)(v7 + 1216));
                                v13 = 0;
                                if (*(_BYTE*)(v7 + 2172))
                                {
                                    v14 = (int*)(v7 + 2140);
                                    do
                                    {
                                        v15 = sub_4ECF10(*v14);
                                        if (v15)
                                            * v14 = *(_DWORD*)(v15 + 36);
                                        else
                                            *(_BYTE*)(v7 + 2172) = 0;
                                        ++v13;
                                        ++v14;
                                    } while (v13 < *(unsigned __int8*)(v7 + 2172));
                                }
                                v2 = v24;
                            }
                            else if (v6 & 0x4000)
                            {
                                if (*(_DWORD*)(*(_DWORD*)(v5 + 748) + 16))
                                    sub_4E44F0(v5);
                            }
                            else if ((v6 & 0x8000) == 0)
                            {
                                if ((v6 & 0x80u) != 0
                                    && *(_DWORD*)(*(_DWORD*)(v5 + 748) + 12) != *(_DWORD*)(*(_DWORD*)(v5 + 748) + 4))
                                {
                                    sub_4DA8D0(v5);
                                }
                            }
                            else
                            {
                                v23 = *(_DWORD*)(*(_DWORD*)(v5 + 748) + 4);
                                if (v23 && *(_DWORD*)(*(_DWORD*)(v23 + 748) + 16))
                                    sub_4E44F0(v5);
                            }
                        }
                        v5 = v26;
                    } while (v26);
                }
                sub_51B0C0();
                sub_516FC0();
                if (*(_DWORD*)& byte_5D4594[1563096])
                {
                    v16 = sub_4DA790();
                    if (v16)
                    {
                        do
                        {
                            v3 = sub_4DA7A0(v16);
                            if ((int) * (_DWORD*)(v16 + 16) >= 0 && sub_4E5B50(v16))
                            {
                                if (*(_BYTE*)(v16 + 8) & 2)
                                {
                                    v17 = *(_DWORD*)(v16 + 12);
                                    if (v17 & 0x2000)
                                    {
                                        v18 = sub_4E7980(v16);
                                        if (v18)
                                        {
                                            do
                                            {
                                                v19 = sub_4E7990(v18);
                                                if (*(unsigned __int16*)(v18 + 4) == *(_DWORD*)& byte_5D4594[1563132])
                                                    sub_4E5CC0(v18);
                                                v18 = v19;
                                            } while (v19);
                                        }
                                    }
                                }
                                sub_4E5CC0(v16);
                            }
                            v16 = v3;
                        } while (v3);
                    }
                    v20 = sub_4DA840();
                    if (v20 != v3)
                    {
                        do
                        {
                            v21 = sub_4DA850(v20);
                            if ((int) * (_DWORD*)(v20 + 16) >= 0)
                            {
                                if (sub_4E5B80(v20))
                                    sub_4E5CC0(v20);
                            }
                            v20 = v21;
                        } while (v21 != v3);
                    }
                    v2 = v24;
                }
                sub_4DB090();
                v4 = v25;
            }
            for (i = *(_DWORD*)(v4 + 516); i != v3; i = *(_DWORD*)(i + 512))
            {
                if (*(_BYTE*)(i + 8) & 2)
                {
                    if (*(_BYTE*)(*(_DWORD*)(i + 748) + 1440) & 0x80)
                    {
                        sub_4D91A0((unsigned __int8)v2[2064], i);
                        sub_417190((unsigned __int8)v2[2064], i, 1);
                        continue;
                    }
                    if ((*(_BYTE*)(i + 12) & 0x80))
                    {
                        sub_4D9250((unsigned __int8)v2[2064], i);
                        sub_417190((unsigned __int8)v2[2064], i, 1);
                        continue;
                    }
                }
            }
            sub_4DB220(v3);
            *(_DWORD*)& byte_5D4594[1563096] = v3;
            result = (char*)sub_416D40();
        }
    }
    return result;
}

//----- (004DBE10) --------------------------------------------------------
int __cdecl sub_4DBE10(int a1, int a2)
{
    int result; // eax
    char* v3; // eax
    int v4; // ebx
    HANDLE v5; // ebp
    char* v6; // ebp
    char* v7; // edx
    char* v8; // esi
    int v9; // ebp
    HANDLE v10; // ebx
    char* v11; // ebx
    char* v12; // edx
    char* v13; // esi
    bool v14; // zf
    char* v15; // eax
    HANDLE hFindFile; // [esp+0h] [ebp-2494Ch]
    HANDLE hFindFilea; // [esp+0h] [ebp-2494Ch]
    char* v18; // [esp+4h] [ebp-24948h]
    int v19; // [esp+8h] [ebp-24944h]
    struct _WIN32_FIND_DATAA FindFileData; // [esp+Ch] [ebp-24940h]
    CHAR PathName[1024]; // [esp+14Ch] [ebp-24800h]
    CHAR FileName[1024]; // [esp+54Ch] [ebp-24400h]
    char v23[16384]; // [esp+94Ch] [ebp-24000h]
    char v24[131072]; // [esp+494Ch] [ebp-20000h]

    result = a1;
    if (a1)
    {
        v3 = sub_409E10();
        nox_sprintf(&PathName, "%s\\Save\\%s", v3, a1);
        result = _access(&PathName, 0);
        if (result != -1)
        {
            nox_sprintf(&FileName, "%s\\Player.plr", &PathName);
            DeleteFileA(&FileName);
            SetCurrentDirectoryA(&PathName);
            v4 = 0;
            v5 = FindFirstFileA((LPCSTR)& byte_587000[199680], &FindFileData);
            hFindFile = v5;
            if (v5 != (HANDLE)-1)
            {
                if (FindFileData.dwFileAttributes & 0x10
                    && strcmp(FindFileData.cFileName, ".")
                    && strcmp(FindFileData.cFileName, ".."))
                {
                    v4 = 1;
                    strcpy(v24, FindFileData.cFileName);
                }
                if (FindNextFileA(v5, &FindFileData))
                {
                    v6 = &v24[1024 * v4];
                    do
                    {
                        if (FindFileData.dwFileAttributes & 0x10
                            && strcmp(FindFileData.cFileName, ".")
                            && strcmp(FindFileData.cFileName, ".."))
                        {
                            v7 = v6;
                            ++v4;
                            v6 += 1024;
                            strcpy(v7, FindFileData.cFileName);
                        }
                    } while (FindNextFileA(hFindFile, &FindFileData));
                    v5 = hFindFile;
                }
                FindClose(v5);
            }
            if (v4 > 0)
            {
                v8 = v24;
                v19 = v4;
                v18 = v24;
                do
                {
                    SetCurrentDirectoryA(v8);
                    v9 = 0;
                    v10 = FindFirstFileA((LPCSTR)& byte_587000[199700], &FindFileData);
                    hFindFilea = v10;
                    if (v10 != (HANDLE)-1)
                    {
                        if (!(FindFileData.dwFileAttributes & 0x10))
                        {
                            v9 = 1;
                            strcpy(v23, FindFileData.cFileName);
                        }
                        if (FindNextFileA(v10, &FindFileData))
                        {
                            v11 = &v23[1024 * v9];
                            do
                            {
                                if (!(FindFileData.dwFileAttributes & 0x10))
                                {
                                    v12 = v11;
                                    ++v9;
                                    v11 += 1024;
                                    strcpy(v12, FindFileData.cFileName);
                                }
                            } while (FindNextFileA(hFindFilea, &FindFileData));
                            v10 = hFindFilea;
                        }
                        FindClose(v10);
                        if (v9 > 0)
                        {
                            v13 = v23;
                            do
                            {
                                DeleteFileA(v13);
                                v13 += 1024;
                                --v9;
                            } while (v9);
                        }
                        v8 = v18;
                    }
                    SetCurrentDirectoryA((LPCSTR)& byte_587000[199704]);
                    RemoveDirectoryA(v8);
                    v8 += 1024;
                    v14 = v19 == 1;
                    v18 = v8;
                    --v19;
                } while (!v14);
            }
            v15 = sub_409E10();
            SetCurrentDirectoryA(v15);
            result = a2;
            if (a2)
                result = RemoveDirectoryA(&PathName);
        }
    }
    return result;
}
// 4DBE10: using guessed type CHAR var_20000[131072];
// 4DBE10: using guessed type CHAR var_24000[16384];

//----- (004DC100) --------------------------------------------------------
int __cdecl sub_4DC100(int a1, int a2)
{
    char* v2; // eax
    char* v3; // eax
    int result; // eax
    int v5; // ebp
    HANDLE v6; // ebx
    char* v7; // ebx
    char* v8; // edx
    int v9; // esi
    char* v10; // edi
    char* v11; // edi
    int v12; // ebp
    HANDLE v13; // ebx
    char* v14; // ebx
    char* v15; // edx
    char* v16; // esi
    bool v17; // cc
    char* v18; // eax
    HANDLE hFindFile; // [esp+10h] [ebp-25154h]
    HANDLE hFindFilea; // [esp+10h] [ebp-25154h]
    int v21; // [esp+14h] [ebp-25150h]
    char* v22; // [esp+18h] [ebp-2514Ch]
    int v23; // [esp+1Ch] [ebp-25148h]
    int v24; // [esp+20h] [ebp-25144h]
    struct _WIN32_FIND_DATAA FindFileData; // [esp+24h] [ebp-25140h]
    CHAR PathName[1024]; // [esp+164h] [ebp-25000h]
    CHAR NewFileName[1024]; // [esp+564h] [ebp-24C00h]
    CHAR ExistingFileName[1024]; // [esp+964h] [ebp-24800h]
    CHAR v29[1024]; // [esp+D64h] [ebp-24400h]
    char v30[16384]; // [esp+1164h] [ebp-24000h]
    char v31[131072]; // [esp+5164h] [ebp-20000h]

    v24 = 1;
    v2 = sub_409E10();
    nox_sprintf(&PathName, "%s\\Save\\%s", v2, a1);
    v3 = sub_409E10();
    nox_sprintf(&v29, "%s\\Save\\%s", v3, a2);
    if (!sub_4DB540(a2))
        return 0;
    sub_4DBE10(a2, 0);
    nox_sprintf(&ExistingFileName, "%s\\Player.plr", &PathName);
    nox_sprintf(&NewFileName, "%s\\Player.plr", &v29);
    result = CopyFileA(&ExistingFileName, &NewFileName, 0);
    if (result)
    {
        result = SetCurrentDirectoryA(&PathName);
        if (result)
        {
            v5 = 0;
            v21 = 0;
            v6 = FindFirstFileA((LPCSTR)& byte_587000[199764], &FindFileData);
            hFindFile = v6;
            if (v6 == (HANDLE)-1)
                goto LABEL_48;
            if (FindFileData.dwFileAttributes & 0x10
                && strcmp(FindFileData.cFileName, ".")
                && strcmp(FindFileData.cFileName, ".."))
            {
                v21 = 1;
                strcpy(v31, FindFileData.cFileName);
                v5 = 1;
            }
            if (FindNextFileA(v6, &FindFileData))
            {
                v7 = &v31[1024 * v5];
                do
                {
                    if (FindFileData.dwFileAttributes & 0x10
                        && strcmp(FindFileData.cFileName, ".")
                        && strcmp(FindFileData.cFileName, ".."))
                    {
                        v8 = v7;
                        ++v5;
                        v7 += 1024;
                        strcpy(v8, FindFileData.cFileName);
                    }
                } while (FindNextFileA(hFindFile, &FindFileData));
                v6 = hFindFile;
                v21 = v5;
            }
            result = FindClose(v6);
            if (result)
            {
                LABEL_48:
                result = SetCurrentDirectoryA(&v29);
                if (result)
                {
                    v9 = 0;
                    if (v5 > 0)
                    {
                        v10 = v31;
                        while (CreateDirectoryA(v10, 0))
                        {
                            ++v9;
                            v10 += 1024;
                            if (v9 >= v5)
                                goto LABEL_24;
                        }
                        return 0;
                    }
                    LABEL_24:
                    result = SetCurrentDirectoryA(&PathName);
                    if (result)
                    {
                        v23 = 0;
                        if (v5 > 0)
                        {
                            v11 = v31;
                            v22 = v31;
                            while (SetCurrentDirectoryA(v11))
                            {
                                v12 = 0;
                                v13 = FindFirstFileA((LPCSTR)& byte_587000[199784], &FindFileData);
                                hFindFilea = v13;
                                if (v13 != (HANDLE)-1)
                                {
                                    if (!(FindFileData.dwFileAttributes & 0x10))
                                    {
                                        v12 = 1;
                                        strcpy(v30, FindFileData.cFileName);
                                        v11 = v22;
                                    }
                                    if (FindNextFileA(v13, &FindFileData))
                                    {
                                        v14 = &v30[1024 * v12];
                                        do
                                        {
                                            if (!(FindFileData.dwFileAttributes & 0x10))
                                            {
                                                v15 = v14;
                                                ++v12;
                                                v14 += 1024;
                                                strcpy(v15, FindFileData.cFileName);
                                            }
                                        } while (FindNextFileA(hFindFilea, &FindFileData));
                                        v13 = hFindFilea;
                                        v11 = v22;
                                    }
                                    if (!FindClose(v13))
                                        return 0;
                                    if (v12 > 0)
                                    {
                                        v16 = v30;
                                        do
                                        {
                                            nox_sprintf(&ExistingFileName, "%s\\%s\\%s", &PathName, v11, v16);
                                            nox_sprintf(&NewFileName, "%s\\%s\\%s", &v29, v11, v16);
                                            if (!CopyFileA(&ExistingFileName, &NewFileName, 0))
                                                v24 = 0;
                                            v16 += 1024;
                                            --v12;
                                        } while (v12);
                                    }
                                }
                                if (!SetCurrentDirectoryA((LPCSTR)& byte_587000[199812]))
                                    return 0;
                                v11 += 1024;
                                v17 = ++v23 < v21;
                                v22 = v11;
                                if (!v17)
                                    goto LABEL_45;
                            }
                            return 0;
                        }
                        LABEL_45:
                        v18 = sub_409E10();
                        result = SetCurrentDirectoryA(v18) ? v24 : 0;
                    }
                }
            }
        }
    }
#ifdef __EMSCRIPTEN__
    EM_ASM(FS.syncfs(false, function(err) {}));
#endif
    return result;
}
// 4DC100: using guessed type CHAR var_20000[131072];
// 4DC100: using guessed type char var_24000[16384];

//----- (004DC550) --------------------------------------------------------
int sub_4DC550()
{
    int v0; // ebx
    char* v1; // edi
    char* v5; // eax
    int v6; // esi
    char* v7; // eax
    char PathName[1024]; // [esp+Ch] [ebp-400h]

    v0 = 0;
    v1 = sub_409E10();
    strcpy(PathName, v1);
    strcat(PathName, "\\Save\\");
    CreateDirectoryA(PathName, 0);
    v5 = sub_409E10();
    nox_sprintf(PathName, "%s\\Save\\AUTOSAVE\\Player.plr", v5);
    if (_access(PathName, 0) != -1)
        v0 = 1;
    v6 = 13;
    do
    {
        v7 = sub_409E10();
        nox_sprintf(PathName, "%s\\Save\\SAVE%04d\\Player.plr", v7, v0);
        if (_access(PathName, 0) != -1)
            ++v0;
        --v6;
    } while (v6);
    return v0;
}
// 4DC550: using guessed type CHAR PathName[1024];

//----- (004DC630) --------------------------------------------------------
int sub_4DC630()
{
    int v0; // ebp
    char* v1; // edi
    HANDLE v5; // esi
    char* v6; // eax
    struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-E40h]
    char PathName[1024]; // [esp+150h] [ebp-D00h]
    char v10[1280]; // [esp+550h] [ebp-900h]
    char v11[1024]; // [esp+A50h] [ebp-400h]

    v0 = 0;
    v1 = sub_409E10();
    strcpy(PathName, v1);
    strcat(PathName, "\\Save\\");
    strcpy(v11, PathName);
    CreateDirectoryA(PathName, 0);
    SetCurrentDirectoryA(PathName);
    v5 = FindFirstFileA("*.plr", &FindFileData);
    if (v5 != (HANDLE)-1)
    {
        if (!(FindFileData.dwFileAttributes & 0x10))
        {
            nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
            sub_41A000(PathName, v10);
            if (v10[0] & 2)
                v0 = 1;
        }
        while (FindNextFileA(v5, &FindFileData))
        {
            if (!(FindFileData.dwFileAttributes & 0x10))
            {
                nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
                sub_41A000(PathName, v10);
                if (v10[0] & 2)
                    ++v0;
            }
        }
        FindClose(v5);
    }
    v6 = sub_409E10();
    SetCurrentDirectoryA(v6);
    return v0;
}
// 4DC630: using guessed type CHAR PathName[1024];

//----- (004DC7D0) --------------------------------------------------------
int sub_4DC7D0()
{
    int v0; // ebp
    char* v1; // edi
    HANDLE v5; // esi
    char* v6; // eax
    struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-E40h]
    char PathName[1024]; // [esp+150h] [ebp-D00h]
    char v10[1280]; // [esp+550h] [ebp-900h]
    char v11[1024]; // [esp+A50h] [ebp-400h]

    v0 = 0;
    v1 = sub_409E10();
    strcpy(PathName, v1);
    strcat(PathName, "\\Save\\");
    strcpy(v11, PathName);
    CreateDirectoryA(PathName, 0);
    SetCurrentDirectoryA(PathName);
    v5 = FindFirstFileA((LPCSTR)& byte_587000[199920], &FindFileData);
    if (v5 != (HANDLE)-1)
    {
        if (!(FindFileData.dwFileAttributes & 0x10))
        {
            nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
            sub_41A000(PathName, v10);
            if (v10[0] & 4)
                v0 = 1;
        }
        while (FindNextFileA(v5, &FindFileData))
        {
            if (!(FindFileData.dwFileAttributes & 0x10))
            {
                nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
                sub_41A000(PathName, v10);
                if (v10[0] & 4)
                    ++v0;
            }
        }
        FindClose(v5);
    }
    v6 = sub_409E10();
    SetCurrentDirectoryA(v6);
    return v0;
}
// 4DC7D0: using guessed type CHAR PathName[1024];

//----- (004DC970) --------------------------------------------------------
char* __cdecl sub_4DC970(char* a1, char* a2)
{
    char* result; // eax

    result = a1;
    if (a1 && a2)
    {
        result = strrchr(a1, 92);
        if (result)
        {
            result = strncpy(a2, result - 8, 8u);
            a2[8] = 0;
        }
    }
    return result;
}

//----- (004DC9B0) --------------------------------------------------------
char* __cdecl sub_4DC9B0(char* a1)
{
    char* result; // eax
    char v2[12]; // [esp+0h] [ebp-Ch]

    if (!a1)
        return (char*)-1;
    result = strrchr(a1, 92);
    if (result)
    {
        strncpy(v2, result - 4, 4u);
        v2[4] = 0;
        result = (char*)atoi(v2);
    }
    return result;
}

//----- (004DCA00) --------------------------------------------------------
char* sub_4DCA00()
{
    unsigned int v0; // ebp
    char* v1; // eax
    HANDLE v2; // ebx
    char* v3; // eax
    char* v4; // eax
    struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-D40h]
    CHAR FileName[1024]; // [esp+148h] [ebp-C00h]
    CHAR PathName[1024]; // [esp+548h] [ebp-800h]
    CHAR Buffer[1024]; // [esp+948h] [ebp-400h]

    v0 = 2;
    GetCurrentDirectoryA(0x400u, Buffer);
    v1 = sub_409E10();
    nox_sprintf(PathName, "%s\\Save\\", v1);
    SetCurrentDirectoryA(PathName);
    v2 = FindFirstFileA("*", &FindFileData);
    if (v2 != (HANDLE)-1)
    {
        if (FindFileData.dwFileAttributes & 0x10)
        {
            if (strcmp(FindFileData.cFileName, ".."))
            {
                if (strcmp(FindFileData.cFileName, "."))
                {
                    nox_sprintf(FileName, "%s%s\\Player.plr", PathName, FindFileData.cFileName);
                    if (_access(FileName, 0) != -1)
                    {
                        v3 = sub_4DC9B0(FileName);
                        if ((unsigned int)v3 >= 2)
                            v0 = (unsigned int)(v3 + 1);
                    }
                }
            }
        }
        while (FindNextFileA(v2, &FindFileData))
        {
            if (FindFileData.dwFileAttributes & 0x10)
            {
                if (strcmp(FindFileData.cFileName, ".."))
                {
                    if (strcmp(FindFileData.cFileName, "."))
                    {
                        nox_sprintf(FileName, "%s%s\\Player.plr", PathName, FindFileData.cFileName);
                        if (_access(FileName, 0) != -1)
                        {
                            v4 = sub_4DC9B0(FileName);
                            if ((unsigned int)v4 >= v0)
                                v0 = (unsigned int)(v4 + 1);
                        }
                    }
                }
            }
        }
        FindClose(v2);
    }
    SetCurrentDirectoryA(Buffer);
    if (v0 > 0x270F)
        return 0;
    nox_sprintf((char*)& byte_5D4594[1563032], "SAVE%04d", v0);
    return (char*)& byte_5D4594[1563032];
}

//----- (004DCBD0) --------------------------------------------------------
int __cdecl sub_4DCBD0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563076] = a1;
    return result;
}

//----- (004DCBE0) --------------------------------------------------------
int sub_4DCBE0()
{
    return *(_DWORD*)& byte_5D4594[1563076];
}

//----- (004DCBF0) --------------------------------------------------------
int __cdecl sub_4DCBF0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563064] = a1;
    return result;
}

//----- (004DCC00) --------------------------------------------------------
int sub_4DCC00()
{
    return *(_DWORD*)& byte_5D4594[1563064];
}

//----- (004DCC10) --------------------------------------------------------
int __cdecl sub_4DCC10(int a1)
{
    int v1; // esi
    int v2; // eax
    int result; // eax

    v1 = 1;
    if (*(_DWORD*)& byte_5D4594[1563092]
        && (unsigned int)(*(_DWORD*)& byte_5D4594[1563092] + *(_DWORD*)& byte_5D4594[1563088]) > * (int*)& byte_5D4594[2598000])
    {
        v1 = 0;
    }
    if (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 284))
        v1 = 0;
    v2 = *(_DWORD*)(a1 + 16);
    if (v2 & 2)
        v1 = 0;
    if ((v2 & 0x8000) != 0)
        v1 = 0;
    if (sub_45D9B0() == 1)
        result = 0;
    else
        result = v1;
    return result;
}

//----- (004DCC70) --------------------------------------------------------
int __cdecl sub_4DCC70(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563072] = a1;
    return result;
}

//----- (004DCC80) --------------------------------------------------------
int sub_4DCC80()
{
    return *(_DWORD*)& byte_5D4594[1563072];
}

//----- (004DCC90) --------------------------------------------------------
BOOL sub_4DCC90()
{
    BOOL result; // eax

    result = 1;
    if (*(_DWORD*)& byte_5D4594[1563080] != 1)
        result = *(_DWORD*)& byte_5D4594[1563092] != 0;
    return result;
}

//----- (004DCCB0) --------------------------------------------------------
BOOL sub_4DCCB0()
{
    BOOL result; // eax
    char* v1; // eax
    int v2; // esi
    int v3; // eax

    if (!sub_40A5C0(2048))
        return 1;
    v1 = sub_417090(31);
    if (!v1
        || (v2 = *((_DWORD*)v1 + 514)) == 0
        || sub_4DCC90()
        || sub_4139B0()
        || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1563068]) < 0x1E
        || sub_477600()
        || (v3 = *(_DWORD*)(v2 + 16), BYTE1(v3) & 0x40))
    {
        result = 0;
    }
    else
    {
        result = sub_4DCC10(v2) != 0;
    }
    return result;
}

//----- (004DCD40) --------------------------------------------------------
int sub_4DCD40()
{
    char* v0; // eax
    int result; // eax
    int i; // esi
    int v3; // eax
    int v4; // edi
    CHAR FileName[1024]; // [esp+4h] [ebp-400h]

    *(_DWORD*)& byte_5D4594[1563048] = sub_416A00();
    sub_4169E0();
    *(_DWORD*)& byte_5D4594[1563044] = 1;
    v0 = sub_409E10();
    nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v0);
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        v3 = *(_DWORD*)(i + 748);
        v4 = *(_DWORD*)(v3 + 276);
        if (*(_DWORD*)(v4 + 4792) && *(_DWORD*)(v3 + 552) != 1)
        {
            if (sub_41A140(FileName, *(unsigned __int8*)(v4 + 2064)))
                sub_41CFA0(FileName, *(unsigned __int8*)(v4 + 2064));
            DeleteFileA(FileName);
        }
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DCE00) --------------------------------------------------------
int sub_4DCE00()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1563044];
    if (*(_DWORD*)& byte_5D4594[1563044])
    {
        result = sub_419F00();
        if (!result)
        {
            result = sub_4DCE30();
            *(_DWORD*)& byte_5D4594[1563044] = 0;
        }
    }
    return result;
}

//----- (004DCE30) --------------------------------------------------------
int sub_4DCE30()
{
    if (!*(_DWORD*)& byte_5D4594[1563048])
        sub_4169F0();
    return sub_446140();
}

//----- (004DCE60) --------------------------------------------------------
int __cdecl sub_4DCE60(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563100] = a1;
    return result;
}

//----- (004DCE70) --------------------------------------------------------
int sub_4DCE70()
{
    return *(_DWORD*)& byte_5D4594[1563100];
}

//----- (004DCE80) --------------------------------------------------------
int __cdecl sub_4DCE80(const char* a1)
{
    int result; // eax

    result = 0;
    if (a1)
    {
        strcpy((char*)& byte_5D4594[1563104], a1);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1563104] = 0;
        *(_DWORD*)& byte_5D4594[1563108] = 0;
        *(_DWORD*)& byte_5D4594[1563112] = 0;
        *(_DWORD*)& byte_5D4594[1563116] = 0;
        *(_DWORD*)& byte_5D4594[1563120] = 0;
    }
    return result;
}

//----- (004DCED0) --------------------------------------------------------
unsigned __int8* sub_4DCED0()
{
    return &byte_5D4594[1563104];
}

//----- (004DCEE0) --------------------------------------------------------
void __cdecl sub_4DCEE0(const char* a1)
{
    if (a1)
    {
        strcpy((char*)& byte_5D4594[1560984], a1);
        *(_DWORD*)& byte_5D4594[1563052] = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1563052] = 0;
    }
}

//----- (004DCF20) --------------------------------------------------------
int sub_4DCF20()
{
    char* v0; // esi
    int result; // eax

    v0 = sub_417090(31);
    result = *(_DWORD*)& byte_5D4594[1563052];
    if (*(_DWORD*)& byte_5D4594[1563052])
    {
        result = sub_4D6FC0();
        if (!result)
        {
            if (v0)
            {
                if (v0[3680] & 0x10)
                {
                    sub_41A2E0((char*)& byte_5D4594[1560984], 31);
                    *(_DWORD*)& byte_5D4594[1563052] = 0;
                    result = DeleteFileA((LPCSTR)& byte_5D4594[1560984]);
                }
            }
        }
    }
    return result;
}

//----- (004DCF80) --------------------------------------------------------
int __cdecl sub_4DCF80(int a1, char a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = -16;
    v4[1] = 28;
    v4[2] = a2;
    return sub_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004DCFB0) --------------------------------------------------------
char __cdecl sub_4DCFB0(int a1)
{
    char result; // al
    int v2; // edi
    int v3; // esi
    int v4; // ecx
    char* v5; // eax
    CHAR FileName[1024]; // [esp+8h] [ebp-400h]

    result = a1;
    v2 = 1;
    if (a1)
    {
        v3 = *(_DWORD*)(a1 + 748);
        v4 = *(_DWORD*)(v3 + 276);
        result = *(_BYTE*)(v4 + 2064);
        if (result != 31)
        {
            if (*(_DWORD*)(v4 + 4792) && *(_DWORD*)(v3 + 552) != 1)
            {
                if (sub_419EE0(*(_BYTE*)(v4 + 2064)))
                    goto LABEL_13;
                v5 = sub_409E10();
                nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v5);
                if (sub_41A140(FileName, *(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064)))
                    v2 = sub_41CFA0(FileName, *(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064));
                result = DeleteFileA(FileName);
                if (v2)
                    LABEL_13:
                    result = sub_4D7960(*(_BYTE*)(*(_DWORD*)(v3 + 276) + 2064));
            }
            else
            {
                result = (unsigned int)sub_4DEAB0(*(unsigned __int8*)(v4 + 2064), 4);
            }
        }
    }
    return result;
}

//----- (004DD0B0) --------------------------------------------------------
char* __cdecl sub_4DD0B0(int a1)
{
    char* result; // eax
    int v2; // esi

    result = (char*)a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 748);
        if (sub_4D7980(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064)))
        {
            result = sub_4DEAB0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 4);
        }
        else
        {
            sub_419EB0(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064), 0);
            result = (char*)sub_4DCF80(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 0);
        }
    }
    return result;
}

//----- (004DD130) --------------------------------------------------------
void sub_4DD130()
{
    nox_srand(0x49C3B96u);
}

//----- (004DD140) --------------------------------------------------------
LPVOID __cdecl sub_4DD140(int a1)
{
    LPVOID result; // eax
    int v3; // [esp+0h] [ebp-4h]

    result = sub_4464D0(1, &v3);
    if (result)
        result = (LPVOID)sub_40BC60(a1, 1, "MOTD", (int)result, v3, 1);
    return result;
}

//----- (004DD180) --------------------------------------------------------
char* __cdecl sub_4DD180(int a1)
{
    char* result; // eax
    char* v2; // edi
    int v3; // eax
    int i; // esi
    int v5; // eax

    result = sub_417090(a1);
    v2 = result;
    if (result)
    {
        sub_4174F0((int)result, 16);
        if (sub_40A5C0(0x2000) && !sub_40A5C0(128))
        {
            v3 = *((_DWORD*)v2 + 514);
            if (v3)
            {
                sub_4FF5B0(v3, 23);
                sub_4FF380(*((_DWORD*)v2 + 514), 23, 5 * *(_WORD*)& byte_5D4594[2649704], 5);
            }
            for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
            {
                if (*(_DWORD*)(i + 8) & 0x10000000)
                    sub_417190(a1, i, 1);
            }
        }
        if ((v2[3680] & 1) == 1)
        {
            v5 = *((_DWORD*)v2 + 514);
            *((_DWORD*)v2 + 908) = *(_DWORD*)(v5 + 56);
            *((_DWORD*)v2 + 909) = *(_DWORD*)(v5 + 60);
            if (sub_40A5C0(512))
                sub_4E6AA0((int)v2);
        }
        sub_4DF1E0(a1);
        if (sub_40A5C0(4096) && sub_40A300() == 1)
            sub_4D9E70(a1);
        if (a1 == 31 && sub_40A5C0(128))
        {
            if (!*(_DWORD*)& byte_5D4594[3596] && sub_43AF70() == 1)
            {
                sub_49C820();
                return (char*)sub_4D9C20(*((_DWORD*)v2 + 514));
            }
            if (*(_DWORD*)& byte_587000[54276] == 1)
            {
                sub_49C560();
                return (char*)sub_4D9C20(*((_DWORD*)v2 + 514));
            }
            sub_457500();
        }
        result = (char*)sub_4D9C20(*((_DWORD*)v2 + 514));
    }
    return result;
}

//----- (004DD310) --------------------------------------------------------
void sub_4DD310()
{
    *(_DWORD*)& byte_5D4594[1563280] = 1;
}

//----- (004DD320) --------------------------------------------------------
_DWORD* __cdecl sub_4DD320(int a1, int a2)
{
    unsigned __int8 v2; // si
    int v3; // esi
    _DWORD* result; // eax
    char* v5; // esi
    unsigned __int8* v6; // eax
    char v7; // al
    char* v8; // ebp
    unsigned int v9; // ecx
    int v10; // eax
    int v11; // eax
    void* v12; // eax
    int v13; // esi
    int v14; // edx
    int v15; // edi
    int v16; // eax
    int v17; // ecx
    int v18; // eax
    int v19; // edx
    size_t v20; // eax
    int v21; // eax
    int v22; // eax
    int v23; // ecx
    char* v24; // eax
    int v25; // [esp-1Ch] [ebp-F4h]
    int v26; // [esp-8h] [ebp-E0h]
    int v27; // [esp+Ch] [ebp-CCh]
    float2 v28; // [esp+10h] [ebp-C8h]
    char v29[60]; // [esp+18h] [ebp-C0h]
    char v30[132]; // [esp+54h] [ebp-84h]

    v2 = *(_BYTE*)(a2 + 152);
    *(_BYTE*)(a2 + 152) = v2 & 0x7F;
    v3 = v2 >> 7;
    if (a1 != 31)
    {
        result = (_DWORD*)sub_40A5C0(4096);
        if (!result && v3 == 1)
            return result;
        if (sub_40A5C0(4096) && !v3)
            return 0;
    }
    v5 = sub_416640();
    sub_40ED10(a1, 1);
    sub_4E4F40(a1);
    sub_4E4F30(a1);
    if (*(_BYTE*)(a2 + 67))
    {
        v6 = &byte_587000[200088];
    }
    else if (*(_DWORD*)& byte_5D4594[1563280])
    {
        v6 = &byte_587000[200068];
    }
    else
    {
        v6 = &byte_587000[200076];
    }
    result = sub_4E3810((CHAR*)v6);
    v27 = (int)result;
    if (result)
    {
        if (a1 != 31)
        {
            v7 = v5[100];
            if (v7)
            {
                if ((unsigned __int8)(1 << *(_BYTE*)(a2 + 66)) & (unsigned __int8)v7)
                    return 0;
            }
        }
        v8 = sub_417000(a1);
        v8[2064] = a1;
        if ((int)v5[102] >= 0)
        {
            *((_WORD*)v8 + 5) = *(_DWORD*)(a2 + 97) >> 1;
            v10 = *(_DWORD*)(a2 + 101) >> 1;
        }
        else
        {
            v9 = *(_DWORD*)(a2 + 97);
            if (nox_win_width >= (int)v9)
            {
                *((_WORD*)v8 + 5) = v9 >> 1;
                *((_WORD*)v8 + 6) = *(_DWORD*)(a2 + 101) >> 1;
                LABEL_23:
                strcpy(v8 + 2112, (const char*)(a2 + 105));
                v8[2135] = *(_BYTE*)(a2 + 152);
                nox_swprintf((wchar_t*)v8 + 1036, L"%S", a2 + 142);
                strcpy(v8 + 2096, (const char*)(a2 + 128));
                v11 = *(_DWORD*)(a2 + 138);
                *((_DWORD*)v8 + 517) = v11;
                if (v11)
                {
                    v12 = sub_425A70(v11);
                    if (!v12)
                        v12 = sub_425AD0(*((_DWORD*)v8 + 517), (wchar_t*)v8 + 1036);
                    sub_425B30((int)v12, a1);
                }
                *((_DWORD*)v8 + 899) = *(_DWORD*)& byte_5D4594[2598000];
                v8[3676] = 2;
                *((_DWORD*)v8 + 920) = 0;
                qmemcpy(v8 + 2185, (const void*)a2, 0x61u);
                nox_wcscpy((wchar_t*)v8 + 2352, (const wchar_t*)(v8 + 2185));
                *((_WORD*)v8 + 1137) = 0;
                sub_4DDA00((int)v8);
                sub_461460((int)v8);
                v13 = v27;
                *((_DWORD*)v8 + 514) = v27;
                v14 = *(_DWORD*)(v13 + 36);
                *((_DWORD*)v8 + 538) = 0;
                *((_DWORD*)v8 + 515) = v14;
                *((_DWORD*)v8 + 539) = sub_4D1600();
                v15 = *(_DWORD*)(v13 + 748);
                *(_DWORD*)(v15 + 276) = v8;
                *((_DWORD*)v8 + 1146) = sub_56F400(**(unsigned __int16**)(v13 + 556));
                *((_DWORD*)v8 + 1148) = sub_56F400(*(unsigned __int16*)(*(_DWORD*)(v13 + 556) + 4));
                *((_DWORD*)v8 + 1149) = sub_56F400(*(unsigned __int16*)(v15 + 4));
                *((_DWORD*)v8 + 1150) = sub_56F400(*(unsigned __int16*)(v15 + 8));
                *((_DWORD*)v8 + 1151) = sub_56F440(*(_DWORD*)(v13 + 28));
                *((_DWORD*)v8 + 1152) = sub_56F440(*(_DWORD*)(v13 + 120));
                *((_DWORD*)v8 + 1153) = sub_56F400(*(_DWORD*)(v13 + 340));
                v16 = sub_56F400((unsigned __int8)v8[2251]);
                v17 = *(_DWORD*)(v8 + 2235);
                *((_DWORD*)v8 + 1154) = v16;
                v18 = sub_56F400(v17);
                v19 = *(_DWORD*)(v8 + 2239);
                *((_DWORD*)v8 + 1155) = v18;
                *((_DWORD*)v8 + 1156) = sub_56F400(v19);
                v20 = nox_wcslen((const wchar_t*)(v8 + 2185));
                v21 = sub_56FAE0((int*)(v8 + 2185), 2 * v20);
                *((_DWORD*)v8 + 1157) = sub_56F400(v21);
                *((_DWORD*)v8 + 1158) = sub_56F400(0);
                *((_DWORD*)v8 + 1159) = sub_56F400(0);
                *((_DWORD*)v8 + 1147) = sub_56F400(*((_DWORD*)v8 + 541));
                v22 = sub_56F400(0);
                v25 = v8[3684];
                *((_DWORD*)v8 + 1160) = v22;
                *((_DWORD*)v8 + 1161) = sub_56F400(v25);
                *((_DWORD*)v8 + 1162) = -1;
                *((_DWORD*)v8 + 1175) = 1;
                if (*(_DWORD*)& byte_5D4594[2650652])
                    sub_41D670((int)(v8 + 2096));
                sub_4D7F10(a1);
                if (sub_40A5C0(4096))
                {
                    sub_4E6860((int)v8, 0, 1);
                }
                else if (sub_40A5C0(512))
                {
                    sub_417630((int)v8);
                }
                else if (v8[2064] == 31 && *(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                {
                    sub_4E6860((int)v8, 0, 1);
                }
                else if (sub_40A5C0(128))
                {
                    if (sub_40A740())
                    {
                        if (!sub_40AA70((int)v8))
                            sub_4E6860((int)v8, 0, 1);
                    }
                    else if (sub_417DA0(4))
                    {
                        sub_4DF3C0((int)v8);
                    }
                }
                else if (!sub_40A5C0(2048))
                {
                    sub_4E6860((int)v8, 1, 1);
                }
                sub_4DDB40((_DWORD*)v13);
                if (v8[2064] == 31)
                    * (_DWORD*)& byte_5D4594[3843628] = v13;
                sub_4DDA90((int)v30, (int)v8);
                v23 = a1;
                LOBYTE(v23) = a1 | 0x80;
                sub_4E5420(v23, v30, 129, 0, 0);
                v8[3676] = 2;
                if (sub_43AF70() == 1 && !sub_40A5C0(128))
                    sub_425F10((int)v8);
                sub_4DAA50(v13, 0, 2944.0, 2944.0);
                sub_4DAC00();
                if (sub_40A5C0(4096))
                {
                    if (!sub_4E8210(v13, (int)& v28))
                        sub_4F7AB0(&v28, v13);
                }
                else
                {
                    sub_4F7AB0(&v28, v13);
                }
                sub_4E7010(v13, &v28);
                sub_422140((int)v8);
                if (a1 != 31)
                {
                    if (sub_459D70() == 2)
                    {
                        v26 = (unsigned __int8)v8[2064];
                        v24 = sub_416590(1);
                        sub_4DD9B0(1, v24, v26);
                    }
                    else
                    {
                        sub_459AA0((int)v29);
                        sub_4DD9B0(1, v29, (unsigned __int8)v8[2064]);
                    }
                }
                if (sub_40A5C0(49152))
                {
                    if (!(v8[3680] & 1))
                        sub_509C30((int)v8);
                }
                if (!sub_40A5C0(2048))
                {
                    if (sub_40A5C0(4096))
                    {
                        sub_4D6960(a1);
                        return *(_DWORD * *)(v13 + 36);
                    }
                    LOWORD(v27) = 484;
                    BYTE2(v27) = 1;
                    sub_4E5420(a1, &v27, 3, 0, 0);
                }
                return *(_DWORD * *)(v13 + 36);
            }
            *((_WORD*)v8 + 5) = nox_win_width / 2;
            v10 = nox_win_height / 2;
        }
        *((_WORD*)v8 + 6) = v10;
        goto LABEL_23;
    }
    return result;
}

//----- (004DD9B0) --------------------------------------------------------
int __cdecl sub_4DD9B0(char a1, const void* a2, int a3)
{
    char v4[60]; // [esp+8h] [ebp-3Ch]

    v4[0] = -79;
    v4[1] = a1;
    qmemcpy(&v4[2], a2, 0x3Au);
    return sub_4E5390(a3, (int)v4, 60, 0, 0);
}

//----- (004DDA00) --------------------------------------------------------
char* __cdecl sub_4DDA00(int a1)
{
    int i; // ebx
    char* result; // eax
    int v3; // esi

    for (i = 2; ; ++i)
    {
        result = sub_416EA0();
        v3 = (int)result;
        if (!result)
            break;
        while (*(_BYTE*)(a1 + 2064) == *(_BYTE*)(v3 + 2064)
               || nox_wcscmp((const wchar_t*)(a1 + 4704), (const wchar_t*)(v3 + 4704)))
        {
            result = sub_416EE0(v3);
            v3 = (int)result;
            if (!result)
                return result;
        }
        nox_swprintf((wchar_t*)(a1 + 2274), L" %d", i);
        nox_swprintf((wchar_t*)(a1 + 4704), L"%s%s", a1 + 2185, a1 + 2274);
    }
    return result;
}

//----- (004DDA90) --------------------------------------------------------
unsigned int __cdecl sub_4DDA90(int a1, int a2)
{
    unsigned int result; // eax

    *(_BYTE*)a1 = 45;
    *(_WORD*)(a1 + 1) = *(_WORD*)(a2 + 2060);
    *(_WORD*)(a1 + 100) = *(_WORD*)(a2 + 2136);
    *(_WORD*)(a1 + 102) = *(_WORD*)(a2 + 2140);
    *(_DWORD*)(a1 + 104) = *(_DWORD*)a2;
    *(_DWORD*)(a1 + 108) = *(_DWORD*)(a2 + 4);
    *(_BYTE*)(a1 + 116) = *(_BYTE*)(a2 + 2152);
    *(_BYTE*)(a1 + 117) = *(_BYTE*)(a2 + 2156);
    *(_BYTE*)(a1 + 118) = *(_BYTE*)(a2 + 3676) == 3;
    *(_DWORD*)(a1 + 112) = *(_DWORD*)(a2 + 3680) & 0x423;
    result = strlen((const char*)(a2 + 2096)) + 1;
    qmemcpy((void*)(a1 + 119), (const void*)(a2 + 2096), result);
    qmemcpy((void*)(a1 + 3), (const void*)(a2 + 2185), 0x61u);
    return result;
}

//----- (004DDB40) --------------------------------------------------------
_DWORD* __cdecl sub_4DDB40(_DWORD* a1)
{
    int v1; // ebx
    int v2; // eax
    char* v3; // ebp
    char v5[256]; // [esp+10h] [ebp-100h]

    *(_DWORD*)& v5[1] = *(_DWORD*)& byte_5D4594[2598000];
    v1 = a1[187];
    v5[0] = 40;
    sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, v5, 5);
    v5[0] = 44;
    *(_WORD*)& v5[1] = sub_578AC0(a1);
    v2 = *(_DWORD*)(v1 + 276);
    *(_DWORD*)& v5[3] = *(_DWORD*)(v2 + 2068);
    sub_40EBC0(*(unsigned __int8*)(v2 + 2064), 1, v5, 7);
    sub_4161E0();
    v3 = sub_416590(0);
    v5[8] = -81;
    *(_DWORD*)& v5[9] = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)& v5[17] = sub_40A5B0() & 0x7FFF0;
    *(_DWORD*)& v5[21] = sub_409E60();
    *(_DWORD*)& v5[13] = 66458;
    v5[25] = sub_409FA0();
    v5[26] = sub_40A020(*((_WORD*)v3 + 26));
    v5[27] = sub_40A180(*((_WORD*)v3 + 26));
    sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, &v5[8], 20);
    v5[28] = -80;
    strcpy(&v5[29], sub_40A4C0());
    qmemcpy(&v5[45], v3 + 24, 0x1Cu);
    if (sub_40A220() && (sub_40A300() || sub_40A180(*((_WORD*)v3 + 26))))
        * (_DWORD*)& v5[73] = sub_40A230();
    else
        *(_DWORD*)& v5[73] = 0;
    sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, &v5[28], 49);
    sub_4DDA90((int)& v5[124], *(_DWORD*)(v1 + 276));
    sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), 1, &v5[124], 129);
    sub_4DDDC0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064));
    v5[80] = 43;
    strcpy(&v5[81], sub_409B30());
    *(_DWORD*)& v5[113] = sub_409B00();
    *(_DWORD*)& v5[117] = *(_DWORD*)& byte_5D4594[2598000];
    sub_552640(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 1, &v5[80], 41, 3);
    return sub_4DDE10(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), *(_DWORD*)(v1 + 276));
}

//----- (004DDDC0) --------------------------------------------------------
FILE* __cdecl sub_4DDDC0(int a1)
{
    FILE* result; // eax
    int v2; // esi
    unsigned __int8* v3; // eax

    result = (FILE*)sub_40A5C0(2);
    v2 = a1;
    if (!result || a1 != 31)
    {
        v3 = sub_40ED60(a1, 1u, &a1);
        if (v3)
            sub_552640(v2 + 1, v3, a1, 3);
        result = sub_40ED10(v2, 1);
    }
    return result;
}

//----- (004DDE10) --------------------------------------------------------
_DWORD* __cdecl sub_4DDE10(int a1, int a2)
{
    _DWORD* result; // eax
    int i; // esi
    int v4; // eax

    result = *(_DWORD * *)(a2 + 2056);
    if (result)
    {
        if (!*(_DWORD*)& byte_5D4594[1563276])
            * (_DWORD*)& byte_5D4594[1563276] = sub_4E3AA0((CHAR*)& byte_587000[200132]);
        result = *(_DWORD * *)(a2 + 2056);
        for (i = result[126]; i; i = *(_DWORD*)(i + 496))
        {
            v4 = *(_DWORD*)(i + 16);
            if (!(v4 & 0x100))
            {
                result = *(_DWORD * *)& byte_5D4594[1563276];
                if (*(unsigned __int16*)(i + 4) != *(_DWORD*)& byte_5D4594[1563276])
                    continue;
            }
            result = sub_4D82F0(a1, (_DWORD*)i);
        }
    }
    return result;
}

//----- (004DDE80) --------------------------------------------------------
int __cdecl sub_4DDE80(int a1, int a2)
{
    int v2; // edi
    int result; // eax

    v2 = *(_DWORD*)(a1 + 748);
    if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 1)
        sub_4E6AA0(*(_DWORD*)(v2 + 276));
    if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 2)
        sub_4DDEF0(a1);
    sub_4174F0(*(_DWORD*)(v2 + 276), 2);
    sub_4E6040(a1);
    result = sub_4E6060(a1, a2);
    *(_DWORD*)(a1 + 744) = sub_4E62F0;
    return result;
}

//----- (004DDEF0) --------------------------------------------------------
int __cdecl sub_4DDEF0(int a1)
{
    int result; // eax

    result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
    if (*(_BYTE*)(result + 3680) & 2)
    {
        sub_417530(result, 2);
        result = sub_4E6040(a1);
        *(_DWORD*)(a1 + 744) = sub_4F8100;
    }
    return result;
}

//----- (004DDF30) --------------------------------------------------------
int __cdecl sub_4DDF30(int a1)
{
    int v1; // eax
    int result; // eax

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
    if (*(_BYTE*)(v1 + 3680) & 2)
        result = *(_DWORD*)(v1 + 3628);
    else
        result = 0;
    return result;
}

//----- (004DDF60) --------------------------------------------------------
int __cdecl sub_4DDF60(int a1)
{
    int v1; // ebx
    char* v2; // esi
    int v3; // eax
    int v4; // edi
    int v5; // ebp
    char* i; // edi
    int v7; // eax
    char* v8; // eax
    char* j; // edi
    unsigned __int8* v10; // eax
    int k; // esi
    int v13; // [esp+Ch] [ebp+4h]

    sub_416640();
    v1 = a1;
    v2 = sub_417090(a1);
    if (sub_40A5C0(4096))
    {
        if (a1 != 31)
        {
            if (v2)
            {
                v3 = *((_DWORD*)v2 + 514);
                if (v3)
                    * (_DWORD*)(*(_DWORD*)(v3 + 748) + 552) = 1;
            }
        }
        sub_4D9CF0(a1);
        if (v2 && *((_DWORD*)v2 + 514))
            sub_4D6000(*((_DWORD*)v2 + 514));
    }
    sub_57B920(v2 + 16);
    v13 = *((_DWORD*)v2 + 514);
    *(_DWORD*)& byte_5D4594[2649712] |= 1 << v1;
    v4 = *(_DWORD*)(v13 + 56);
    v5 = *(_DWORD*)(v13 + 60);
    sub_4DE300(v1);
    *((_DWORD*)v2 + 1175) = 0;
    (*(void(__cdecl * *)(int, _DWORD))(v13 + 688))(v13, 0);
    v2[3676] = 3;
    if (!sub_40A5C0(512))
    {
        *((_DWORD*)v2 + 908) = v4;
        *((_DWORD*)v2 + 909) = v5;
    }
    if (*(_DWORD*)& byte_587000[108752] && sub_40A5C0(0x2000) && !sub_40A5C0(4096))
        sub_4DD140(v1);
    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        v7 = *((_DWORD*)i + 514);
        if (v7)
        {
            if (i != v2)
            {
                sub_417190(v1, v7, 1);
                sub_417190((unsigned __int8)i[2064], *((_DWORD*)v2 + 514), 1);
                sub_4DF360((unsigned __int8)i[2064], *((_DWORD*)v2 + 514));
                if (sub_40A5C0(4096))
                {
                    sub_4D8670((unsigned __int8)i[2064], *((_DWORD * *)v2 + 514));
                    sub_4D8670(v1, *((_DWORD * *)i + 514));
                }
            }
        }
    }
    sub_4DE380(v1);
    sub_4DF2E0(v1);
    if (sub_40A5C0(1024) && !sub_40AA70((int)v2))
        sub_4174F0((int)v2, 256);
    if (sub_43AF70() == 1)
    {
        sub_4161E0();
        sub_416690();
    }
    sub_4E8110(v1);
    if (sub_40A5C0(64))
    {
        v8 = sub_4E8310();
        sub_4D95F0(v1, *v8, *((_WORD*)v8 + 1));
    }
    else if (sub_40A5C0(32))
    {
        for (j = sub_418B10(); j; j = sub_418B60((int)j))
        {
            v10 = sub_4E8320(j[57]);
            sub_4D95A0(v1, *v10, v10[2], v10[1], *((_WORD*)v10 + 2));
        }
    }
    sub_4175C0((int)v2);
    if (sub_409F40(0x2000))
        sub_4DE270((int)v2);
    if (sub_40A5C0(4096))
    {
        for (k = sub_4DA7C0(); k; k = sub_4DA7F0(k))
        {
            if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(k + 748) + 276) + 4792) == 1)
                sub_4D9D20(v1, k);
        }
    }
    if (sub_40A5C0(4096))
        sub_4D7A60(v1);
    return *(_DWORD*)(v13 + 36);
}

//----- (004DE270) --------------------------------------------------------
int __cdecl sub_4DE270(int a1)
{
    int result; // eax
    int i; // esi
    int v3; // [esp-1Ch] [ebp-28h]
    char v4[7]; // [esp+4h] [ebp-8h]

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        if (*(_DWORD*)(i + 36) != *(_DWORD*)(a1 + 2060))
        {
            if (*(_DWORD*)(*(_DWORD*)(i + 748) + 260))
            {
                v4[0] = -46;
                *(_WORD*)& v4[1] = sub_578AC0((_DWORD*)i);
                v3 = *(unsigned __int8*)(a1 + 2064);
                *(_WORD*)& v4[3] = *(_WORD*)(i + 4);
                v4[5] = 1;
                v4[6] = 2;
                sub_4E5420(v3, v4, 7, 0, 1);
            }
        }
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DE300) --------------------------------------------------------
char* __cdecl sub_4DE300(int a1)
{
    char* result; // eax
    int i; // esi
    char v3[132]; // [esp+4h] [ebp-84h]

    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        if (*(unsigned __int8*)(i + 2064) != a1
            && (*(_BYTE*)(i + 2064) != 31 || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000)))
        {
            sub_4DDA90((int)v3, i);
            sub_4E5390(a1, (int)v3, 129, 0, 0);
            sub_4DDE10(a1, i);
        }
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004DE380) --------------------------------------------------------
int __cdecl sub_4DE380(int a1)
{
    int result; // eax
    int i; // esi
    int v3; // eax

    if (!*(_DWORD*)& byte_5D4594[1563284])
        * (_DWORD*)& byte_5D4594[1563284] = sub_4E3AA0((CHAR*)& byte_587000[200140]);
    if (!*(_DWORD*)& byte_5D4594[1563272])
        * (_DWORD*)& byte_5D4594[1563272] = sub_4E3AA0((CHAR*)& byte_587000[200152]);
    result = sub_4DA790();
    for (i = result; result; i = result)
    {
        if (*(_BYTE*)(i + 16) & 4)
        {
            v3 = *(unsigned __int16*)(i + 4);
            if ((unsigned __int16)v3 == *(_DWORD*)& byte_5D4594[1563284] || v3 == *(_DWORD*)& byte_5D4594[1563272])
                sub_417190(a1, i, 1);
        }
        result = sub_4DA7A0(i);
    }
    return result;
}

//----- (004DE410) --------------------------------------------------------
_DWORD* __cdecl sub_4DE410(int a1)
{
    int v1; // ebp
    int v2; // edi
    _DWORD* result; // eax
    _DWORD* i; // esi
    int v5; // ecx
    int v6; // ebx
    unsigned int v7; // edi
    int v8; // [esp+10h] [ebp+4h]

    v1 = a1;
    v2 = 1 << a1;
    v8 = 1 << a1;
    result = (_DWORD*)sub_4DA790();
    for (i = result; result; i = result)
    {
        v5 = i[2];
        i[38] |= v2;
        if (!(v5 & 0x20400000))
            i[37] &= ~v2;
        i[v1 + 140] &= 0xFFFu;
        if (i[2] & 0x20400000)
        {
            v6 = 0x10000;
            v7 = 1;
            do
            {
                if (sub_4E4C90((int)i, v7))
                    i[v1 + 140] |= v6;
                v7 *= 2;
                v6 *= 2;
            } while (v7 < 0x10000);
            v2 = v8;
        }
        result = (_DWORD*)sub_4DA7A0((int)i);
    }
    return result;
}

//----- (004DE4D0) --------------------------------------------------------
int __cdecl sub_4DE4D0(char a1)
{
    int v1; // esi
    int result; // eax
    char v3; // cl

    v1 = 1 << a1;
    for (result = sub_4DA790(); result; result = sub_4DA7A0(result))
    {
        v3 = *(_BYTE*)(result + 16);
        *(_DWORD*)(result + 152) |= v1;
        if (!(v3 & 0x20) && !(*(_DWORD*)(result + 8) & 0x20400006))
            * (_DWORD*)(result + 148) &= ~v1;
    }
    return result;
}

//----- (004DE530) --------------------------------------------------------
char __cdecl sub_4DE530(int a1, char a2)
{
    int v2; // ebp
    char* v3; // eax
    int v4; // esi
    char* v5; // edi
    char* i; // edi
    int v7; // eax
    int j; // eax
    int v9; // edx
    char result; // al
    int v11; // eax
    char v12[3]; // [esp+10h] [ebp-8h]
    int v13; // [esp+14h] [ebp-4h]

    v2 = a1;
    v13 = 1 << a1;
    sub_4D79A0(a1);
    sub_419EB0(v2, 0);
    sub_4E80C0(v2);
    v3 = sub_417090(v2);
    v4 = (int)v3;
    if (v3)
    {
        if (*((_DWORD*)v3 + 514))
            sub_506740(*((_DWORD*)v3 + 514));
        if (*(_DWORD*)(v4 + 4792) && *(_DWORD*)(v4 + 2056) && sub_40A5C0(4096))
        {
            sub_501960(1011, *(_DWORD*)(v4 + 2056), 0, 0);
            *(_DWORD*)(v4 + 4792) = 0;
            if (!sub_4E3CE0())
            {
                v5 = sub_4D0F60();
                sub_4E3CD0(0);
                sub_4D2450(v5);
            }
            sub_4D7390(*(_DWORD*)(v4 + 2056));
            sub_4DE790(*(_DWORD*)(v4 + 2056));
        }
    }
    if (sub_43AF70() == 1 && !sub_40A5C0(128))
        sub_425E90(v4, a2);
    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        v7 = *((_DWORD*)i + 514);
        if (v7 && i != (char*)v4)
        {
            sub_417300(v2, v7, 3);
            sub_417300((unsigned __int8)i[2064], *(_DWORD*)(v4 + 2056), 3);
        }
    }
    if (*(_DWORD*)(v4 + 2056))
    {
        for (j = sub_4DA790(); j; j = sub_4DA7A0(j))
        {
            if ((*(_BYTE*)(j + 8) & 0x80) && *(_DWORD*)(j + 508) == *(_DWORD*)(v4 + 2056))
                * (_DWORD*)(j + 508) = 0;
        }
    }
    sub_40C0E0(v2 + 1);
    sub_4DE410(v2);
    if (v4)
    {
        v12[0] = -82;
        v9 = v2;
        LOBYTE(v9) = v2 | 0x80;
        *(_WORD*)& v12[1] = *(_WORD*)(*(_DWORD*)(v4 + 2056) + 36);
        sub_4E5420(v9, v12, 3, 0, 0);
    }
    if (a2 == 4)
    {
        LOBYTE(a1) = -59;
        sub_552640(v2 + 1, &a1, 1, 3);
    }
    result = sub_4E55F0(v2);
    if (v4)
    {
        sub_4E5AD0(*(_DWORD*)(v4 + 2056));
        if (sub_40A5C0(4096))
            sub_4DE790(*(_DWORD*)(v4 + 2056));
        else
            sub_4EDA40(*(_DWORD * *)(v4 + 2056));
        v11 = v13;
        *(_DWORD*)(v4 + 2140) = 0;
        *(_DWORD*)(v4 + 2136) = 0;
        *(_DWORD*)& byte_5D4594[2649712] &= ~v11;
        *(_BYTE*)(v4 + 3676) = 2;
        result = sub_417530(v4, 16);
    }
    return result;
}

//----- (004DE790) --------------------------------------------------------
void __cdecl sub_4DE790(int a1)
{
    int v1; // esi
    int v2; // edi

    v1 = sub_4E7980(a1);
    if (v1)
    {
        do
        {
            v2 = sub_4E7990(v1);
            sub_4E5CC0(v1);
            v1 = v2;
        } while (v2);
    }
}

//----- (004DE7C0) --------------------------------------------------------
char* __cdecl sub_4DE7C0(int a1)
{
    int v1; // edi
    char* v2; // esi
    int* v3; // eax
    int v4; // ebp
    int v5; // eax
    int i; // eax
    int v7; // ecx
    int v8; // eax
    char* result; // eax
    unsigned __int8* v11; // eax
    int v12; // eax
    int v13; // eax
    unsigned __int8* v14; // eax

    v1 = a1;
    v2 = sub_417090(a1);
    if (sub_4D12A0(v1))
        sub_4D1250(v1);
    if (*((_DWORD*)v2 + 517))
    {
        v3 = sub_425A70(*((_DWORD*)v2 + 517));
        if (v3)
            sub_425B60(v3, v1);
    }
    v4 = *(_DWORD*)(*((_DWORD*)v2 + 514) + 748);
    if (*(_DWORD*)(v4 + 280))
        sub_510DC0(*(_DWORD * *)(v4 + 280));
    *(_DWORD*)(v4 + 280) = 0;
    sub_510E20((unsigned __int8)v2[2064]);
    sub_4FF990(1 << v2[2064]);
    if (!sub_40A5C0(2))
        * ((_DWORD*)v2 + 523) = 0;
    sub_56F4F0((int*)v2 + 1146);
    sub_56F4F0((int*)v2 + 1148);
    sub_56F4F0((int*)v2 + 1149);
    sub_56F4F0((int*)v2 + 1150);
    sub_56F4F0((int*)v2 + 1151);
    sub_56F4F0((int*)v2 + 1152);
    sub_56F4F0((int*)v2 + 1153);
    sub_56F4F0((int*)v2 + 1154);
    sub_56F4F0((int*)v2 + 1155);
    sub_56F4F0((int*)v2 + 1156);
    sub_56F4F0((int*)v2 + 1157);
    sub_56F4F0((int*)v2 + 1158);
    sub_56F4F0((int*)v2 + 1159);
    sub_56F4F0((int*)v2 + 1147);
    sub_56F4F0((int*)v2 + 1160);
    sub_56F4F0((int*)v2 + 1161);
    LOBYTE(a1) = 46;
    *(_WORD*)((char*)& a1 + 1) = sub_578AC0(*((_DWORD * *)v2 + 514));
    v5 = v1;
    LOBYTE(v5) = v1 | 0x80;
    sub_4E5420(v5, &a1, 3, 0, 0);
    sub_4E5CC0(*((_DWORD*)v2 + 514));
    *((_DWORD*)v2 + 514) = 0;
    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
    {
        v7 = *(_DWORD*)(i + 748);
        *(_BYTE*)(v1 + v7 + 452) = 0;
        *(_DWORD*)(v7 + 4 * v1 + 324) = 0;
        *(_BYTE*)(v1 + v7 + 484) = 0;
        *(_BYTE*)(v1 + v7 + 516) = 0;
    }
    v8 = sub_40A8A0();
    if (v8)
    {
        if (sub_40A5C0(1024) && !sub_446180() && sub_40A770() == 1)
            sub_5095E0();
    }
    else
    {
        sub_40A1F0(0);
        sub_416E50(1);
        sub_417D00();
        sub_40A970();
    }
    sub_4E55F0(v1);
    sub_4E4F40(v1);
    sub_4E4F30(v1);
    if (sub_43AF70() == 1)
    {
        sub_4161E0();
        sub_416690();
    }
    result = (char*)sub_40A5C0(4096);
    if (result)
    {
        if (sub_4E9010() == 1)
        {
            v11 = sub_4E8E50();
            result = sub_4D2450((char*)v11);
        }
        else if (sub_4E8F60())
        {
            sub_4D60B0();
            sub_4D76E0(1);
            v12 = sub_4E3CC0();
            v13 = sub_4D74F0(v12);
            sub_4E3CD0(v13 - 1);
            v14 = sub_4E8E50();
            result = sub_4D2450((char*)v14);
        }
        else
        {
            result = (char*)sub_4DA7C0();
            if (result)
            {
                while (!*(_DWORD*)(*((_DWORD*)result + 187) + 312))
                {
                    result = (char*)sub_4DA7F0((int)result);
                    if (!result)
                        return result;
                }
                result = (char*)sub_4E8E60();
            }
        }
    }
    return result;
}
// 4DE9A4: variable 'v8' is possibly undefined
// 4DE9E1: variable 'v9' is possibly undefined

//----- (004DEAB0) --------------------------------------------------------
char* __cdecl sub_4DEAB0(int a1, char a2)
{
    char* result; // eax
    char* v3; // esi

    result = sub_417090(a1);
    v3 = result;
    if (result)
    {
        sub_4DE530((unsigned __int8)result[2064], a2);
        sub_4DE7C0((unsigned __int8)v3[2064]);
        result = (char*)sub_4DEC50((unsigned __int8)v3[2064]);
    }
    return result;
}

//----- (004DEB00) --------------------------------------------------------
char* __cdecl sub_4DEB00(int a1)
{
    char* result; // eax

    result = sub_417090(a1);
    if (result)
        result = sub_4DEAB0((unsigned __int8)result[2064], 4);
    return result;
}

//----- (004DEB30) --------------------------------------------------------
void sub_4DEB30()
{
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x400000))
        sub_552A80(*(unsigned int*)& byte_5D4594[1563148], 1);
}

//----- (004DEB50) --------------------------------------------------------
void sub_4DEB50()
{
    unsigned __int8* v2; // eax
    void* v3; // [esp+0h] [ebp-4h]

    if (sub_40A5C0(2))
    {
        if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
        {
            sub_4D3580(0);
            sub_40ED10(31, 0);
        }
        else
        {
            v2 = sub_40ED60(31, 0, &v3);
            if (v2)
                sub_51BAD0(31, v2, (signed int)v3);
            sub_40ED10(31, 0);
        }
    }
}

//----- (004DEBC0) --------------------------------------------------------
int __cdecl sub_4DEBC0(int a1)
{
    int result; // eax
    char v2[40]; // [esp+4h] [ebp-28h]

    memset(v2, 0, sizeof(v2));
    *(_DWORD*)& v2[16] = sub_409FA0();
    *(_DWORD*)& v2[20] = 2048;
    *(_DWORD*)& v2[8] = a1;
    *(_DWORD*)& v2[12] = 0;
    sub_5520B0(200, 1024);
    *(_DWORD*)& v2[36] = sub_4DEC30;
    *(_DWORD*)& v2[32] = sub_4DF630;
    result = sub_554380((size_t*)v2);
    OnLibraryNotice(256, 0);
    *(_DWORD*)& byte_5D4594[1563148] = result;
    return result;
}

//----- (004DEC30) --------------------------------------------------------
int __cdecl sub_4DEC30(int a1, unsigned __int8* a2, signed int a3)
{
    sub_51BAD0(a1 - 1, a2, a3);
    return 1;
}

//----- (004DEC50) --------------------------------------------------------
int __cdecl sub_4DEC50(int a1)
{
    return sub_5545B0(a1 + 1);
}

//----- (004DEC60) --------------------------------------------------------
int __cdecl sub_4DEC60(unsigned int a1)
{
    sub_5545B0(a1);
    sub_5546A0(a1);
    OnLibraryNotice(257, 0);
    return sub_552450();
}

//----- (004DEC80) --------------------------------------------------------
char* sub_4DEC80()
{
    char* result; // eax
    int i; // esi
    int v2; // eax
    unsigned int v3; // [esp-18h] [ebp-28h]
    int v4; // [esp-10h] [ebp-20h]
    char v5[1]; // [esp+7h] [ebp-9h]
    char v6[3]; // [esp+8h] [ebp-8h]
    int v7; // [esp+Ch] [ebp-4h]

    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        if (*(_DWORD*)(i + 2056))
        {
            v2 = -((*(_DWORD*)(i + 3680) & 0x10) != 0);
            LOBYTE(v2) = v2 & 0xC4;
            if (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(i + 3596) > (unsigned int)((v2 + 90)
                                                                                         * *(_DWORD*)& byte_5D4594[2649704]))
            {
                v7 = *(_DWORD*)(i + 2060);
                sub_4DA180(3, &v7);
                v3 = *(unsigned __int8*)(i + 2064) + 1;
                v5[0] = -58;
                sub_552640(v3, v5, 1, 3);
                sub_4DEAB0(*(unsigned __int8*)(i + 2064), 3);
            }
            if ((*(_BYTE*)(i + 3680) & 0x80))
                sub_4DEAB0(*(unsigned __int8*)(i + 2064), 4);
            if (*(_BYTE*)(i + 3676) != 3 || (*(_BYTE*)(i + 3680) & 0x10) != 16)
            {
                v4 = *(unsigned __int8*)(i + 2064);
                v6[0] = 39;
                *(_WORD*)& v6[1] = *(_WORD*)& byte_5D4594[2598000];
                sub_40EBC0(v4, 1, v6, 3);
            }
            else
            {
                sub_518EE0(*(_DWORD * *)(i + 2056));
            }
            if (*(_DWORD*)(i + 2056) == *(_DWORD*)& byte_5D4594[3843628])
            {
                sub_4E5770(*(_BYTE*)(i + 2064), 1);
            }
            else if (!*(_DWORD*)& byte_5D4594[2650652]
                     || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)sub_40A6C0())
                     || sub_40A5C0(8))
            {
                sub_5528B0(*(unsigned __int8*)(i + 2064) + 1, 0);
            }
        }
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004DEE00) --------------------------------------------------------
_DWORD* __cdecl sub_4DEE00(const char* a1, int a2)
{
    int v2; // edx
    _DWORD* result; // eax
    _DWORD* i; // esi
    int v5; // edi
    unsigned __int8* v6; // eax
    char v7[41]; // [esp+8h] [ebp-2Ch]

    v7[0] = 43;
    v2 = *(_DWORD*)& byte_5D4594[2598000];
    strcpy(&v7[1], a1);
    *(_DWORD*)& v7[37] = v2;
    *(_DWORD*)& v7[33] = a2;
    result = (_DWORD*)sub_4DA7C0();
    for (i = result; result; i = result)
    {
        v5 = i[187];
        sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 1, v7, 41);
        sub_518C30((int)i, i, 0, 0);
        if (!sub_40A5C0(2) || *(_BYTE*)(*(_DWORD*)(v5 + 276) + 2064) != 31)
        {
            v6 = sub_40ED60(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 1u, &a1);
            if (v6)
                sub_552640(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064) + 1, v6, (signed int)a1, 3);
        }
        result = (_DWORD*)sub_4DA7F0((int)i);
    }
    return result;
}

//----- (004DEF00) --------------------------------------------------------
int sub_4DEF00()
{
    char* v0; // ebx
    char v2[20]; // [esp+Ch] [ebp-48h]
    char v3[49]; // [esp+20h] [ebp-34h]

    v0 = sub_416590(0);
    v2[0] = -81;
    *(_DWORD*)& v2[1] = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)& v2[9] = sub_40A5B0() & 0x7FFF0;
    *(_DWORD*)& v2[13] = sub_409E60();
    *(_DWORD*)& v2[5] = 66458;
    v2[17] = sub_409FA0();
    v2[18] = sub_40A020(*((_WORD*)v0 + 26));
    v2[19] = sub_40A180(*((_WORD*)v0 + 26));
    v3[0] = -80;
    strcpy(&v3[1], sub_40A4C0());
    qmemcpy(&v3[17], v0 + 24, 0x1Cu);
    if (sub_40A220() && (sub_40A300() || sub_40A180(*((_WORD*)v0 + 26))))
        * (_DWORD*)& v3[45] = sub_40A230();
    else
        *(_DWORD*)& v3[45] = 0;
    sub_4E5390(159, (int)v2, 20, 0, 0);
    return sub_4E5390(159, (int)v3, 49, 0, 0);
}

//----- (004DF020) --------------------------------------------------------
char* sub_4DF020()
{
    char* result; // eax
    int v1; // ecx
    unsigned __int8* v2; // edi
    char* v3; // esi
    bool v4; // zf
    char* i; // esi
    char v6[60]; // [esp+8h] [ebp-3Ch]

    result = sub_459AA0((int)v6);
    v1 = 29;
    v2 = &byte_5D4594[1563214];
    v3 = v6;
    v4 = 1;
    do
    {
        if (!v1)
            break;
        v4 = *(_WORD*)v3 == *(_WORD*)v2;
        v3 += 2;
        v2 += 2;
        --v1;
    } while (v4);
    if (!v4)
    {
        result = sub_416EA0();
        for (i = result; result; i = result)
        {
            if (i[2064] != 31)
                sub_4DD9B0(1, v6, (unsigned __int8)i[2064]);
            result = sub_416EE0((int)i);
        }
        qmemcpy(&byte_5D4594[1563214], v6, 0x38u);
        *(_WORD*)& byte_5D4594[1563270] = *(_WORD*)& v6[56];
    }
    return result;
}

//----- (004DF0A0) --------------------------------------------------------
int __cdecl sub_4DF0A0(int a1, int a2)
{
    int result; // eax
    int i; // esi
    char v4[3]; // [esp+4h] [ebp-4h]

    v4[0] = 58;
    *(_WORD*)& v4[1] = *(_WORD*)(a1 + 10);
    if (a2 != 32)
        return sub_4E5420(a2, v4, 3, 0, 1);
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v4, 3, 0, 1);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DF120) --------------------------------------------------------
int __cdecl sub_4DF120(int a1)
{
    int result; // eax
    int i; // esi
    char v3[3]; // [esp+4h] [ebp-4h]

    v3[0] = 59;
    *(_WORD*)& v3[1] = *(_WORD*)(a1 + 10);
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 3, 0, 1);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DF180) --------------------------------------------------------
int __cdecl sub_4DF180(int a1)
{
    int result; // eax
    int i; // esi
    char v3[3]; // [esp+4h] [ebp-4h]

    v3[0] = 60;
    *(_WORD*)& v3[1] = *(_WORD*)(a1 + 10);
    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), v3, 3, 0, 1);
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004DF1E0) --------------------------------------------------------
int __cdecl sub_4DF1E0(int a1)
{
    int* i; // esi
    int v2; // eax
    int result; // eax
    int j; // esi
    char v5; // al

    for (i = (int*)sub_410870(); i; i = (int*)sub_410880(i))
    {
        v2 = i[1];
        if (*(_BYTE*)(v2 + 4) & 0x20)
            sub_4DF0A0(v2, a1);
    }
    sub_4DF2A0(a1);
    if (sub_5071C0())
        sub_507190(a1, 1);
    result = sub_40A5C0(4096);
    if (result)
    {
        for (j = sub_4DA790(); j; j = sub_4DA7A0(j))
        {
            if ((*(_BYTE*)(j + 8) & 0x80) && *(_BYTE*)(*(_DWORD*)(j + 748) + 48))
                sub_4D6A20(a1, j);
        }
        result = sub_4D72C0();
        if (result == 1)
        {
            v5 = sub_4D72C0();
            result = sub_4D7280(a1, v5);
        }
    }
    return result;
}

//----- (004DF2A0) --------------------------------------------------------
int* __cdecl sub_4DF2A0(char a1)
{
    int v1; // esi
    int* result; // eax

    v1 = 1 << a1;
    for (result = (int*)sub_410780(); result; result = (int*)sub_410790(result))
    {
        if (result[5] & 8)
            result[7] |= v1;
        else
            result[7] &= ~v1;
    }
    return result;
}

//----- (004DF2E0) --------------------------------------------------------
void __cdecl sub_4DF2E0(int a1)
{
    char* i; // ebx
    int j; // esi

    if (a1 != 31)
    {
        for (i = sub_418B10(); i; i = sub_418B60((int)i))
        {
            sub_4197C0((wchar_t*)i, a1);
            for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j))
            {
                if (sub_419180(j + 48, i[57]))
                    sub_4198A0(j + 48, a1, *(_DWORD*)(j + 36));
            }
        }
    }
}

//----- (004DF360) --------------------------------------------------------
int __cdecl sub_4DF360(int a1, int a2)
{
    __int16 v2; // ax
    float v3; // ecx
    __int16 v4; // ax
    float v5; // edx
    char v7[9]; // [esp+4h] [ebp-Ch]

    v7[0] = 47;
    *(_WORD*)& v7[3] = *(_WORD*)(a2 + 4);
    v2 = sub_578AC0((_DWORD*)a2);
    v3 = *(float*)(a2 + 56);
    *(_WORD*)& v7[1] = v2;
    v4 = sub_419A70(v3);
    v5 = *(float*)(a2 + 60);
    *(_WORD*)& v7[5] = v4;
    *(_WORD*)& v7[7] = sub_419A70(v5);
    return sub_4E5390(a1, (int)v7, 9, 0, 1);
}

//----- (004DF3C0) --------------------------------------------------------
char __cdecl sub_4DF3C0(int a1)
{
    int v1; // edi
    char* v2; // eax
    char* v3; // ebx
    char* v4; // ebx
    char* v5; // esi
    int v6; // ebx
    BOOL v7; // eax
    int v8; // esi
    int v9; // ebx

    v1 = *(_DWORD*)(a1 + 2056);
    v2 = sub_416640();
    v3 = v2;
    if (!v1)
        return (char)v2;
    if (!sub_40A740() && !sub_40A5C0(0x8000))
    {
        LOBYTE(v2) = sub_417DD0();
        if ((_BYTE)v2)
        {
            v2 = sub_4189D0();
            v4 = v2;
            if (v2)
            {
                v2 = (char*)sub_419130(v1 + 48);
                if (!v2)
                    LOBYTE(v2) = (unsigned int)sub_4191D0(v4[57], v1 + 48, 1, *(_DWORD*)(v1 + 36), 1);
            }
        }
        return (char)v2;
    }
    v2 = *(char**)(a1 + 2068);
    if (!v2)
        return (char)v2;
    v5 = sub_418AE0(*(_DWORD*)(a1 + 2068));
    if (v5)
    {
        v6 = v1 + 48;
        v7 = sub_419130(v1 + 48);
        goto LABEL_11;
    }
    v8 = (unsigned __int8)v3[52];
    if ((sub_40A5C0(96) || sub_40A5C0(16) && sub_417DA0(4)) && v8 > 2)
        v8 = 2;
    v2 = (char*)(unsigned __int8)sub_417DE0();
    if ((int)v2 < v8)
    {
        if (!sub_40A5C0(96) || (v9 = (unsigned __int8)sub_417DE0(), v2 = (char*)sub_417DC0(), v9 < (int)v2))
        {
            v2 = sub_418A10();
            v5 = v2;
            if (v2)
            {
                sub_418800((wchar_t*)v2, (wchar_t*)(a1 + 2072), 0);
                sub_418830((int)v5, *(_DWORD*)(a1 + 2068));
                sub_4184D0((wchar_t*)v5);
                v6 = v1 + 48;
                v7 = sub_419130(v1 + 48);
                LABEL_11:
                if (v7)
                    LOBYTE(v2) = sub_4196D0(v6, (int)v5, *(_DWORD*)(v1 + 36), 0);
                else
                    LOBYTE(v2) = (unsigned int)sub_4191D0(v5[57], v6, 1, *(_DWORD*)(v1 + 36), 0);
                return (char)v2;
            }
        }
    }
    return (char)v2;
}

//----- (004DF550) --------------------------------------------------------
int sub_4DF550()
{
    return *(_DWORD*)& byte_5D4594[1563148];
}

//----- (004DF560) --------------------------------------------------------
void sub_4DF560()
{
    nox_srand(0x49C3B97u);
}

//----- (004DF570) --------------------------------------------------------
void sub_4DF570()
{
    nox_srand(0x22FEu);
}

//----- (004DF580) --------------------------------------------------------
int __cdecl sub_4DF580(int a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // ecx
    int v4; // ebx
    int v5; // ecx
    int v6; // eax
    int v7; // ecx

    v2 = *(unsigned __int16*)(a1 + 5);
    if ((unsigned __int16)v2 - (int)* a2 >= 0)
        v3 = (unsigned __int16)v2 - *a2;
    else
        v3 = *a2 - v2;
    v4 = a2[2];
    if (v3 >= v4)
        return 0;
    v5 = a2[1];
    v6 = *(unsigned __int16*)(a1 + 7);
    v7 = (unsigned __int16)v6 - v5 >= 0 ? (unsigned __int16)v6 - v5 : v5 - v6;
    if (v7 >= v4)
        return 0;
    *(_DWORD*)& byte_5D4594[1563300] = a1;
    return 1;
}

//----- (004DF5E0) --------------------------------------------------------
int __cdecl sub_4DF5E0(int a1, int a2)
{
    int v3[3]; // [esp+0h] [ebp-Ch]

    v3[0] = *(_DWORD*)& byte_5D4594[1563292];
    v3[1] = *(_DWORD*)& byte_5D4594[1563296];
    v3[2] = a2;
    *(_DWORD*)& byte_5D4594[1563300] = 0;
    sub_40F0F0(a1, (int(__cdecl*)(_DWORD, int))sub_4DF580, (int)v3);
    return *(_DWORD*)& byte_5D4594[1563300];
}

//----- (004DF630) --------------------------------------------------------
int __cdecl sub_4DF630(int a1, char* a2, unsigned int a3)
{
    char* v3; // edi
    int v4; // ebx
    char* v5; // ebp
    char* v6; // eax
    int** v7; // esi
    unsigned int v8; // eax
    int** v9; // eax
    char* v10; // edi
    int v11; // eax
    char* v13; // edi
    _BYTE* v14; // eax
    int** i; // esi
    signed int v16; // eax
    int** j; // eax
    signed int v18; // eax

    v3 = a2;
    v4 = a1 - 1;
    v5 = &a2[a3];
    v6 = sub_417090(a1 - 1);
    *(_DWORD*)& byte_5D4594[1563308] = 0;
    *(_DWORD*)& byte_5D4594[1563312] = 0;
    *(_DWORD*)& byte_5D4594[1563304] = v6 + 16;
    v7 = sub_40F080(a1 - 1, &a3);
    if (sub_4DF7F0(v7))
    {
        v8 = a3;
        qmemcpy(a2, v7, a3);
        v3 = &a2[v8];
        v9 = sub_40F080(v4, &a3);
        if (v9)
        {
            *v3 = -92;
            v10 = v3 + 1;
            v11 = sub_4DF810(v10, (int)v5, (int)v9);
            if (!v11)
                return v10 - a2 - 1;
            v13 = &v10[v11];
            do
            {
                v14 = sub_4DF8F0(v4, v13, (int)v5);
                v13 = &v13[(_DWORD)v14];
            } while (v14);
            v3 = &v13[sub_4DF8C0(v13, (int)v5)];
        }
    }
    for (i = sub_40EEB0(v4, 1, &a3); i; i = sub_40EEB0(v4, 1, &a3))
    {
        if (*(char*)i != -107
            || *(int*)& byte_5D4594[2650652] != 1
            || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)sub_40A6C0()))
        {
            v16 = sub_4DFAF0(v3, (int)v5, i, a3);
            if (!v16)
                return v3 - a2;
            v3 += v16;
        }
    }
    *(_DWORD*)& byte_5D4594[1563312] = v3 - a2;
    if (!*(_DWORD*)& byte_5D4594[2650652]
        || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)sub_40A6C0())
        || sub_40A5C0(8))
    {
        sub_4E5770(v4, 1);
        for (j = sub_40EEB0(v4, 1, &a3); j; j = sub_40EEB0(v4, 1, &a3))
        {
            v18 = sub_4DFAF0(v3, (int)v5, j, a3);
            if (!v18)
                break;
            v3 += v18;
        }
    }
    return v3 - a2;
}

//----- (004DF7F0) --------------------------------------------------------
BOOL __cdecl sub_4DF7F0(_BYTE* a1)
{
    return a1 && (*a1 == 39 || *a1 == 40);
}

//----- (004DF810) --------------------------------------------------------
int __cdecl sub_4DF810(char* a1, int a2, int a3)
{
    char v4; // al
    bool v5; // zf
    char* v6; // eax
    char v7; // cl
    _BYTE* v8; // eax
    _BYTE* v9; // eax

    if (*(char*)a3 != -61)
        return 0;
    if (a2 - (int)a1 < 16)
        return 0;
    *(_WORD*)(a3 + 5) &= 0xFFFEu;
    *(_WORD*)(a3 + 7) &= 0xFFFEu;
    v4 = sub_57B930(
            *(int*)& byte_5D4594[1563304],
            *(unsigned __int16*)(a3 + 1),
            *(unsigned __int16*)(a3 + 3),
            *(unsigned int*)& byte_5D4594[2598000]);
    v5 = v4 == -1;
    *a1 = v4;
    v6 = a1 + 1;
    if (v5)
    {
        *(_DWORD*)v6 = *(_DWORD*)(a3 + 1);
        v6 = a1 + 5;
    }
    *(_DWORD*)v6 = *(_DWORD*)(a3 + 5);
    v7 = *(_BYTE*)(a3 + 9);
    v8 = v6 + 4;
    *v8 = v7;
    if (*(char*)(a3 + 10) != -1)
    {
        *v8++ = v7 | 0x80;
        *v8 = *(_BYTE*)(a3 + 10);
    }
    v9 = v8 + 1;
    *v9 = *(_BYTE*)(a3 + 11);
    *(_DWORD*)& byte_5D4594[1563292] = *(unsigned __int16*)(a3 + 5);
    *(_DWORD*)& byte_5D4594[1563296] = *(unsigned __int16*)(a3 + 7);
    return (char*)v9 - a1 + 1;
}

//----- (004DF8C0) --------------------------------------------------------
int __cdecl sub_4DF8C0(_BYTE* a1, int a2)
{
    if (a2 - (int)a1 < 3)
        return 0;
    *a1 = 0;
    a1[1] = 0;
    a1[2] = 0;
    return 3;
}

//----- (004DF8F0) --------------------------------------------------------
_BYTE* __cdecl sub_4DF8F0(int a1, _BYTE* a2, int a3)
{
    _BYTE* v3; // ebp
    int v4; // edi
    int v6; // esi
    int v7; // eax
    int v8; // edi

    v3 = a2;
    v4 = 127;
    if (!sub_40F0B0(a1))
        return 0;
    v6 = sub_4DF5E0(a1, 127);
    if (!v6)
    {
        while (1)
        {
            v4 += 127;
            if (v4 > 4064)
                return 0;
            v6 = sub_4DF5E0(a1, v4);
            if (v6)
            {
                if (v4 <= 127)
                    break;
                *a2 = 0;
                v7 = 1;
                v3 = a2 + 1;
                goto LABEL_9;
            }
        }
    }
    v7 = 0;
    LABEL_9:
    v8 = sub_4DF9B0((int)v3, a3, v6, v7);
    if (v8 == -1)
        return (_BYTE*)(v3 - a2);
    sub_40F000(a1, v6);
    return &v3[v8 - (_DWORD)a2];
}

//----- (004DF9B0) --------------------------------------------------------
int __cdecl sub_4DF9B0(int a1, int a2, int a3, int a4)
{
    char v4; // al
    unsigned __int16* v5; // esi
    unsigned __int16 v6; // ax
    _WORD* v7; // esi
    _BYTE* v8; // esi
    _BYTE* v10; // esi
    char v11; // al
    float v12; // [esp+0h] [ebp-14h]
    float v13; // [esp+0h] [ebp-14h]

    if (a2 - a1 < 8 || a4 && a2 - a1 < 10)
        return -1;
    v4 = sub_57B930(
            *(int*)& byte_5D4594[1563304],
            *(unsigned __int16*)(a3 + 1),
            *(unsigned __int16*)(a3 + 3),
            *(unsigned int*)& byte_5D4594[2598000]);
    *(_BYTE*)a1 = v4;
    v5 = (unsigned __int16*)(a1 + 1);
    if (v4 == -1)
    {
        *v5 = *(_WORD*)(a3 + 1);
        *(_WORD*)(a1 + 3) = *(_WORD*)(a3 + 3);
        v5 = (unsigned __int16*)(a1 + 5);
    }
    if (a4)
    {
        v6 = *(_WORD*)(a3 + 5);
        if (v6 > 0x1770u || *(_WORD*)(a3 + 7) > 0x1770u)
            return 0;
        *v5 = v6;
        v7 = v5 + 1;
        *v7 = *(_WORD*)(a3 + 7);
        v8 = v7 + 1;
    }
    else
    {
        v12 = (double) * (unsigned __int16*)(a3 + 5);
        *(_BYTE*)v5 = sub_419A70(v12) - byte_5D4594[1563292];
        v10 = (char*)v5 + 1;
        v13 = (double) * (unsigned __int16*)(a3 + 7);
        *v10 = sub_419A70(v13) - byte_5D4594[1563296];
        v8 = v10 + 1;
    }
    *(_DWORD*)& byte_5D4594[1563292] = *(unsigned __int16*)(a3 + 5);
    *(_DWORD*)& byte_5D4594[1563296] = *(unsigned __int16*)(a3 + 7);
    if (*(char*)a3 == 48 || *(char*)a3 == -61)
    {
        v11 = *(_BYTE*)(a3 + 9);
        *v8 = v11;
        if (*(char*)(a3 + 10) != -1)
        {
            *v8++ = v11 | 0x80;
            *v8 = *(_BYTE*)(a3 + 10);
        }
        if (*(char*)a3 == -61)
            * ++v8 = *(_BYTE*)(a3 + 11);
        ++v8;
    }
    return (int)& v8[-a1];
}

//----- (004DFAF0) --------------------------------------------------------
signed int __cdecl sub_4DFAF0(void* a1, int a2, const void* a3, signed int a4)
{
    signed int result; // eax

    result = a4;
    if (a2 - (int)a1 < a4)
        return 0;
    qmemcpy(a1, a3, a4);
    return result;
}

//----- (004DFB20) --------------------------------------------------------
int sub_4DFB20()
{
    return *(_DWORD*)& byte_5D4594[1563312];
}

//----- (004DFB30) --------------------------------------------------------
void sub_4DFB30()
{
    nox_srand(0x22FFu);
}

//----- (004DFB40) --------------------------------------------------------
void sub_4DFB40()
{
    nox_srand(0x2274u);
}

//----- (004DFB50) --------------------------------------------------------
_DWORD* __cdecl sub_4DFB50(int a1, int a2)
{
    *(_BYTE*)(a2 + 440) |= 8u;
    return sub_501960(75, a2, 0, 0);
}

//----- (004DFB80) --------------------------------------------------------
_DWORD* __cdecl sub_4DFB80(int a1, int a2)
{
    if (!sub_4DFBB0(a2, 8))
        * (_BYTE*)(a2 + 440) &= 0xF7u;
    return sub_501960(76, a2, 0, 0);
}

//----- (004DFBB0) --------------------------------------------------------
int __cdecl sub_4DFBB0(int a1, char a2)
{
    _DWORD* v2; // ebp
    int v3; // eax
    int v4; // edi
    int v5; // esi
    unsigned __int8* v6; // eax

    if (!a1)
        return 0;
    if (!a2)
        return 0;
    v2 = *(_DWORD * *)(a1 + 504);
    if (!v2)
        return 0;
    while (1)
    {
        v3 = v2[4];
        if (v3 & 0x100)
        {
            if (v2[2] & 0x13001000)
                break;
        }
        LABEL_13:
        v2 = (_DWORD*)v2[124];
        if (!v2)
            return 0;
    }
    v4 = 0;
    v5 = v2[173];
    while (!*(_DWORD*)v5)
    {
        LABEL_12:
        ++v4;
        v5 += 4;
        if (v4 >= 4)
            goto LABEL_13;
    }
    v6 = &byte_587000[200164];
    while (*(_DWORD*)(*(_DWORD*)v5 + 112) != *((_DWORD*)v6 - 1) || a2 != *v6)
    {
        v6 += 20;
        if ((int)v6 >= (int)& byte_587000[200284])
            goto LABEL_12;
    }
    return 1;
}

//----- (004DFC30) --------------------------------------------------------
void __cdecl sub_4DFC30(int a1, int a2)
{
    int v2; // esi
    int v3; // edx
    int v5; // [esp+Ch] [ebp+8h]

    v2 = a2;
    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
        {
            v3 = *(_DWORD*)(a2 + 748);
            *(_BYTE*)(a2 + 440) |= 0x10u;
            *(float*)& v5 = *(float*)(a1 + 120) + *(float*)(a2 + 552);
            *(float*)(v2 + 552) = *(float*)& v5;
            sub_4D9360(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (_DWORD*)v2, 0, v5);
            sub_501960(59, v2, 0, 0);
        }
    }
}

//----- (004DFCA0) --------------------------------------------------------
void __cdecl sub_4DFCA0(int a1, int a2)
{
    int v2; // esi
    int v3; // edx
    int v4; // [esp+Ch] [ebp+8h]

    v2 = a2;
    if (a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        if (!sub_4DFBB0(a2, 16))
            * (_BYTE*)(a2 + 440) &= 0xEFu;
        v3 = *(_DWORD*)(a2 + 748);
        *(float*)& v4 = *(float*)(a2 + 552) - *(float*)(a1 + 120);
        *(float*)(v2 + 552) = *(float*)& v4;
        sub_4D9360(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (_DWORD*)v2, 0, v4);
        sub_501960(60, v2, 0, 0);
    }
}

//----- (004DFD10) --------------------------------------------------------
_DWORD* __cdecl sub_4DFD10(int a1, int a2)
{
    *(_BYTE*)(a2 + 440) |= 1u;
    return sub_501960(102, a2, 0, 0);
}

//----- (004DFD40) --------------------------------------------------------
void __cdecl sub_4DFD40(int a1, int a2, int a3)
{
    if (a2 && a3)
    {
        if (!sub_4DFBB0(a2, 1))
            * (_BYTE*)(a2 + 440) &= 0xFEu;
        sub_501960(103, a2, 0, 0);
    }
}

//----- (004DFD80) --------------------------------------------------------
_DWORD* __cdecl sub_4DFD80(int a1, int a2)
{
    *(_BYTE*)(a2 + 440) |= 4u;
    return sub_501960(106, a2, 0, 0);
}

//----- (004DFDB0) --------------------------------------------------------
_DWORD* __cdecl sub_4DFDB0(int a1, int a2)
{
    if (!sub_4DFBB0(a2, 4))
        * (_BYTE*)(a2 + 440) &= 0xFBu;
    return sub_501960(107, a2, 0, 0);
}

//----- (004DFDE0) --------------------------------------------------------
_DWORD* __cdecl sub_4DFDE0(int a1, int a2)
{
    *(_BYTE*)(a2 + 440) |= 2u;
    return sub_501960(110, a2, 0, 0);
}

//----- (004DFE10) --------------------------------------------------------
_DWORD* __cdecl sub_4DFE10(int a1, int a2)
{
    if (!sub_4DFBB0(a2, 2))
        * (_BYTE*)(a2 + 440) &= 0xFDu;
    return sub_501960(111, a2, 0, 0);
}

//----- (004DFE40) --------------------------------------------------------
double __cdecl sub_4DFE40(_DWORD* a1)
{
    double v1; // st7
    double result; // st7
    _DWORD* v3; // edx
    int v4; // eax
    int* v5; // ecx
    int v6; // esi
    int v7; // eax
    int* v8; // ecx
    int v9; // edx
    int v10; // eax
    unsigned __int8 v11; // al
    float v12; // [esp+4h] [ebp-4h]

    v1 = 0.0;
    v12 = 0.0;
    if (!a1)
        return 0.0;
    v3 = (_DWORD*)a1[126];
    if (v3)
    {
        do
        {
            v4 = v3[4];
            if (v4 & 0x100 && v3[2] & 0x13001000)
            {
                v5 = (int*)v3[173];
                v6 = 4;
                do
                {
                    v7 = *v5;
                    if (*v5 && *(_DWORD * (__cdecl * *)(int, int))(v7 + 112) == sub_4DFD10)
                        v1 = v1 + *(float*)(v7 + 120);
                    ++v5;
                    --v6;
                } while (v6);
            }
            v3 = (_DWORD*)v3[124];
        } while (v3);
        v12 = v1;
    }
    if (a1[2] & 0x13001000)
    {
        v8 = (int*)a1[173];
        v9 = 4;
        do
        {
            v10 = *v8;
            if (*v8 && *(_DWORD * (__cdecl * *)(int, int))(v10 + 112) == sub_4DFD10)
                v1 = v1 + *(float*)(v10 + 120);
            ++v8;
            --v9;
        } while (v9);
        v12 = v1;
    }
    if (v1 > 0.5)
        v12 = 0.5;
    if (sub_4FF350((int)a1, 17))
    {
        v11 = sub_4FF570((int)a1, 17);
        result = sub_419D70(&byte_587000[200656], (unsigned int)v11 - 1) + v12;
    }
    else
    {
        result = v12;
    }
    if (result > 0.60000002)
        result = 0.60000002;
    return result;
}

//----- (004DFF40) --------------------------------------------------------
double __cdecl sub_4DFF40(_DWORD* a1)
{
    double v1; // st7
    double result; // st7
    _DWORD* v3; // edx
    int v4; // eax
    int* v5; // ecx
    int v6; // esi
    int v7; // eax
    int* v8; // ecx
    int v9; // edx
    int v10; // eax
    unsigned __int8 v11; // al
    float v12; // [esp+4h] [ebp-4h]

    v1 = 0.0;
    v12 = 0.0;
    if (!a1)
        return 0.0;
    v3 = (_DWORD*)a1[126];
    if (v3)
    {
        do
        {
            v4 = v3[4];
            if (v4 & 0x100 && v3[2] & 0x13001000)
            {
                v5 = (int*)v3[173];
                v6 = 4;
                do
                {
                    v7 = *v5;
                    if (*v5 && *(_DWORD * (__cdecl * *)(int, int))(v7 + 112) == sub_4DFD80)
                        v1 = v1 + *(float*)(v7 + 120);
                    ++v5;
                    --v6;
                } while (v6);
            }
            v3 = (_DWORD*)v3[124];
        } while (v3);
        v12 = v1;
    }
    if (a1[2] & 0x13001000)
    {
        v8 = (int*)a1[173];
        v9 = 4;
        do
        {
            v10 = *v8;
            if (*v8 && *(_DWORD * (__cdecl * *)(int, int))(v10 + 112) == sub_4DFD80)
                v1 = v1 + *(float*)(v10 + 120);
            ++v8;
            --v9;
        } while (v9);
        v12 = v1;
    }
    if (v1 >= 0.5)
        v12 = 0.5;
    if (sub_4FF350((int)a1, 20))
    {
        v11 = sub_4FF570((int)a1, 20);
        result = sub_419D70(&byte_587000[200676], (unsigned int)v11 - 1) + v12;
    }
    else
    {
        result = v12;
    }
    if (result > 0.60000002)
        result = 0.60000002;
    return result;
}

//----- (004E0040) --------------------------------------------------------
double __cdecl sub_4E0040(_DWORD* a1)
{
    double v1; // st7
    double result; // st7
    _DWORD* v3; // edx
    int v4; // eax
    int* v5; // ecx
    int v6; // esi
    int v7; // eax
    int* v8; // ecx
    int v9; // edx
    int v10; // eax
    unsigned __int8 v11; // al
    float v12; // [esp+4h] [ebp-4h]

    v1 = 0.0;
    v12 = 0.0;
    if (!a1)
        return 0.0;
    v3 = (_DWORD*)a1[126];
    if (v3)
    {
        do
        {
            v4 = v3[4];
            if (v4 & 0x100 && v3[2] & 0x13001000)
            {
                v5 = (int*)v3[173];
                v6 = 4;
                do
                {
                    v7 = *v5;
                    if (*v5 && *(_DWORD * (__cdecl * *)(int, int))(v7 + 112) == sub_4DFDE0)
                        v1 = v1 + *(float*)(v7 + 120);
                    ++v5;
                    --v6;
                } while (v6);
            }
            v3 = (_DWORD*)v3[124];
        } while (v3);
        v12 = v1;
    }
    if (a1[2] & 0x13001000)
    {
        v8 = (int*)a1[173];
        v9 = 4;
        do
        {
            v10 = *v8;
            if (*v8 && *(_DWORD * (__cdecl * *)(int, int))(v10 + 112) == sub_4DFDE0)
                v1 = v1 + *(float*)(v10 + 120);
            ++v8;
            --v9;
        } while (v9);
        v12 = v1;
    }
    if (v1 > 0.69999999)
        v12 = 0.69999999;
    if (sub_4FF350((int)a1, 18))
    {
        v11 = sub_4FF570((int)a1, 18);
        result = sub_419D70(&byte_587000[200704], (unsigned int)v11 - 1) + v12;
    }
    else
    {
        result = v12;
    }
    if (result > 0.89999998)
        result = 0.89999998;
    return result;
}

//----- (004E0140) --------------------------------------------------------
_DWORD* __cdecl sub_4E0140(int a1, int a2)
{
    *(_BYTE*)(a2 + 440) |= 0x20u;
    return sub_501960(123, a2, 0, 0);
}

//----- (004E0170) --------------------------------------------------------
void __cdecl sub_4E0170(int a1, int a2)
{
    if (a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        if (!sub_4DFBB0(a2, 32))
            * (_BYTE*)(a2 + 440) &= 0xDFu;
        sub_501960(124, a2, 0, 0);
    }
}

//----- (004E01B0) --------------------------------------------------------
void sub_4E01B0()
{
    nox_srand(0x2275u);
}

//----- (004E01C0) --------------------------------------------------------
void sub_4E01C0()
{
    nox_srand(0x227Eu);
}

//----- (004E01D0) --------------------------------------------------------
void __cdecl sub_4E01D0(int a1, int a2)
{
    _DWORD* v2; // esi
    unsigned __int16 v3; // di
    unsigned int v4; // edi
    int v5; // eax

    if (a2)
    {
        v2 = *(_DWORD * *)(a2 + 492);
        if (v2)
        {
            if (v2[139])
            {
                if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - v2[134]) >= *(int*)& byte_5D4594[2649704]
                    && !(v2[4] & 0x8020))
                {
                    v3 = sub_4EE7A0(*(_DWORD*)(a2 + 492));
                    if ((unsigned __int16)sub_4EE780((int)v2) < v3)
                    {
                        v4 = *(_DWORD*)(a1 + 108);
                        if (*(_DWORD*)(a2 + 8) & 0x2000000)
                        {
                            v5 = sub_415C70(a2);
                            if (v5 & 0x4000)
                                v4 /= 3u;
                        }
                        if (!(*(_DWORD*)& byte_5D4594[2598000]
                              % (v4 * *(_DWORD*)& byte_5D4594[2649704] / (unsigned __int16)sub_4EE7A0((int)v2))))
                            sub_4EE460((int)v2, 1);
                    }
                }
            }
        }
    }
}

//----- (004E02C0) --------------------------------------------------------
void __cdecl sub_4E02C0(int a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // ecx
    unsigned __int8 v4; // dl
    unsigned __int8 v5; // al
    int v6; // esi
    int v7; // edx
    int v8; // ecx

    if (a2)
    {
        if (!(*(_DWORD*)& byte_5D4594[2598000] % *(_DWORD*)(a1 + 108)))
        {
            v2 = a2[2];
            v3 = a2[184];
            if (v2 & 0x1000)
            {
                v4 = *(_BYTE*)(v3 + 108);
                v5 = *(_BYTE*)(v3 + 109);
                v6 = v4++;
                *(_BYTE*)(v3 + 108) = v4;
                if (v4 > v5)
                    * (_BYTE*)(v3 + 108) = v5;
                v7 = *(unsigned __int8*)(v3 + 108);
                if (v6 != v7)
                {
                    v8 = a2[123];
                    if (v8)
                    {
                        if (*(_BYTE*)(v8 + 8) & 4)
                            sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v8 + 748) + 276) + 2064), a2, v7, v5);
                    }
                }
            }
        }
    }
}

//----- (004E0350) --------------------------------------------------------
void sub_4E0350()
{
    nox_srand(0x227Fu);
}

//----- (004E0360) --------------------------------------------------------
void sub_4E0360()
{
    nox_srand(0x2260u);
}

//----- (004E0370) --------------------------------------------------------
float* __cdecl sub_4E0370(int a1, int a2, int a3, int a4, int a5, float* a6)
{
    float* result; // eax

    result = a6;
    *a6 = *(float*)(a1 + 80) * *a6;
    return result;
}

//----- (004E0380) --------------------------------------------------------
float* __cdecl sub_4E0380(int a1, int a2, int a3, int a4, int a5, float* a6)
{
    float* result; // eax

    result = a6;
    *a6 = (1.0 - *(float*)(a1 + 80) + 1.0) * *a6;
    return result;
}

//----- (004E03D0) --------------------------------------------------------
BOOL __cdecl sub_4E03D0(int a1, int a2, int a3, int a4, int a5, BOOL* a6)
{
    BOOL result; // eax

    result = *(_DWORD*)(a1 + 96) >= 1;
    *a6 = result;
    return result;
}

//----- (004E03F0) --------------------------------------------------------
int __cdecl sub_4E03F0(int a1, int a2, int a3, int a4)
{
    int v4; // esi
    int v5; // edi
    _DWORD* v6; // eax
    int v7; // eax
    BOOL(__cdecl * v8)(int, int, int, int, int, BOOL*); // ecx
    bool v9; // cc
    _DWORD* i; // [esp+10h] [ebp-4h]
    int v12; // [esp+20h] [ebp+Ch]

    v4 = a3;
    if (!a3 || !(*(_DWORD*)(a3 + 8) & 0x3001000))
        return 0;
    v5 = a4;
    v6 = (_DWORD*)(*(_DWORD*)(a3 + 692) + 8);
    v12 = 2;
    for (i = v6; ; ++i)
    {
        v7 = *v6;
        if (v7)
        {
            v8 = *(BOOL(__cdecl * *)(int, int, int, int, int, BOOL*))(v7 + 88);
            if (v8 == sub_4E0480)
            {
                v8(v7, v4, a2, v5, a1, &a4);
                if (!a4)
                    break;
            }
        }
        v6 = i + 1;
        v9 = ++v12 < 4;
        if (!v9)
            return 0;
    }
    return 1;
}

//----- (004E0480) --------------------------------------------------------
BOOL __cdecl sub_4E0480(int a1, int a2, int a3, int a4, int a5, BOOL* a6)
{
    BOOL result; // eax

    result = *(_DWORD*)(a1 + 96) < 1;
    *a6 = result;
    return result;
}

//----- (004E04A0) --------------------------------------------------------
void sub_4E04A0()
{
    nox_srand(0x2261u);
}

//----- (004E04B0) --------------------------------------------------------
void sub_4E04B0()
{
    nox_srand(0x226Au);
}

//----- (004E04C0) --------------------------------------------------------
float* __cdecl sub_4E04C0(int a1, int a2, int a3, int a4, float* a5)
{
    float* result; // eax

    result = a5;
    *a5 = *(float*)(a1 + 44) * *a5;
    return result;
}

//----- (004E04D0) --------------------------------------------------------
void __cdecl sub_4E04D0(int a1, int a2, int a3, int a4)
{
    int v4; // esi
    int v5; // ecx
    int v6; // eax
    int v8; // eax
    int v9[3]; // [esp+4h] [ebp-Ch]

    v4 = a4;
    if (*(_BYTE*)(a4 + 8) & 6)
    {
        v5 = *(_DWORD*)(a4 + 60);
        v9[1] = *(_DWORD*)(a4 + 56);
        v6 = *(_DWORD*)(a1 + 60);
        v9[2] = v5;
        v9[0] = a4;
        sub_52C2C0(74, a3, a3, a3, v9, v6);
        if (*(_BYTE*)(v4 + 8) & 4)
        {
            v8 = *(_DWORD*)(v4 + 748);
            a4 = 0;
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), 13, &a4);
        }
    }
}

//----- (004E0550) --------------------------------------------------------
_DWORD* __cdecl sub_4E0550(int a1, int a2, int a3, int a4)
{
    _DWORD* result; // eax
    float v5; // [esp+8h] [ebp+4h]

    result = (_DWORD*)a1;
    v5 = *(float*)(a1 + 56);
    if (a4)
    {
        (*(void(__cdecl * *)(int, int, int, _DWORD, int))(a4 + 716))(a4, a3, a2, (__int64)v5, 7);
        sub_5231B0((float*)(a4 + 56), (__int64)(v5 * 10.0));
        result = sub_501960(224, a4, 0, 0);
    }
    return result;
}

//----- (004E05B0) --------------------------------------------------------
int __cdecl sub_4E05B0(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // edx
    int v5[3]; // [esp+0h] [ebp-Ch]

    result = a3;
    if (a3)
    {
        v4 = *(_DWORD*)(a3 + 60);
        v5[1] = *(_DWORD*)(a3 + 56);
        v5[2] = v4;
        v5[0] = 0;
        result = sub_52D5C0(10, a3, a3, a3, (int)v5, *(_DWORD*)(a1 + 48));
    }
    return result;
}

//----- (004E05F0) --------------------------------------------------------
int __cdecl sub_4E05F0(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // edx
    int v5[3]; // [esp+0h] [ebp-Ch]

    result = a3;
    if (a3)
    {
        v4 = *(_DWORD*)(a3 + 60);
        v5[1] = *(_DWORD*)(a3 + 56);
        v5[2] = v4;
        v5[0] = 0;
        result = sub_52D5C0(11, a3, a3, a3, (int)v5, *(_DWORD*)(a1 + 48));
    }
    return result;
}

//----- (004E0640) --------------------------------------------------------
void __cdecl sub_4E0640(int a1, int a2, int a3, int a4)
{
    if (a2)
    {
        if (a4)
            sub_52DF80(a2 + 56, a4, *(float*)(a1 + 56));
    }
}

//----- (004E0670) --------------------------------------------------------
void __cdecl sub_4E0670(int a1, int a2, int a3, int a4)
{
    int v4; // esi
    int v5; // ecx
    int v6; // eax
    int v8; // eax
    int v9[3]; // [esp+4h] [ebp-Ch]

    v4 = a4;
    if (*(_BYTE*)(a4 + 8) & 6)
    {
        v5 = *(_DWORD*)(a4 + 60);
        v9[1] = *(_DWORD*)(a4 + 56);
        v6 = *(_DWORD*)(a1 + 60);
        v9[2] = v5;
        v9[0] = a4;
        sub_52C1E0(12, a3, a3, a3, v9, v6);
        if (*(_BYTE*)(v4 + 8) & 4)
        {
            v8 = *(_DWORD*)(v4 + 748);
            a4 = 1;
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), 13, &a4);
        }
    }
}

//----- (004E06F0) --------------------------------------------------------
void __cdecl sub_4E06F0(int a1, int a2, int a3, int a4)
{
    if (a4)
    {
        (*(void(__cdecl * *)(int, int, int, _DWORD, int))(a4 + 716))(a4, a3, a2, (__int64) * (float*)(a1 + 56), 9);
        sub_522FF0(129, (float2*)(a4 + 56));
        sub_501960(225, a4, 0, 0);
    }
}

//----- (004E0740) --------------------------------------------------------
void __cdecl sub_4E0740(int a1, int a2, int a3, int a4, int* a5)
{
    int v5; // edi
    unsigned __int16 v6; // ax
    __int16 v7; // si

    if (a3 && a4 && *(_BYTE*)(a4 + 8) & 6)
    {
        v5 = (__int64)(*(float*)(a1 + 68) * (double)* a5);
        if (!v5)
            v5 = 1;
        v6 = sub_4EEC80(a4);
        v7 = v6;
        if (v6 < v5)
        {
            sub_4EEBF0(a4, v6);
            sub_4EEB80(a3, v7);
        }
        else
        {
            sub_4EEBF0(a4, v5);
            sub_4EEB80(a3, v5);
        }
    }
}

//----- (004E07C0) --------------------------------------------------------
void __cdecl sub_4E07C0(int a1, int a2, int a3, int a4, int* a5)
{
    int v5; // eax
    int v6; // esi
    int v7; // eax

    if (a3)
    {
        if (a4)
        {
            v5 = *(_DWORD*)(a4 + 8);
            if (v5 & 6)
            {
                if (!(v5 & 2) || !(*(_BYTE*)(a4 + 12) & 0x40))
                {
                    v6 = (__int64)((double)* a5 * *(float*)(a1 + 68));
                    if (!v6)
                        v6 = 1;
                    v7 = (unsigned __int16)sub_4EE780(a4);
                    if (v7 < v6)
                        sub_4EE460(a3, v7);
                    else
                        sub_4EE460(a3, v6);
                }
            }
        }
    }
}

//----- (004E0850) --------------------------------------------------------
void __cdecl sub_4E0850(int a1, int a2, int a3, int a4)
{
    int v4; // esi
    int v5; // eax

    v4 = a4;
    if ((!(*(_BYTE*)(a4 + 8) & 4)
         || *(_BYTE*)(*(_DWORD*)(a4 + 748) + 88) != 16
         || !(sub_4E6E50((float2*)(a4 + 56), *(__int16*)(a4 + 124), (float2*)(a3 + 56)) & 1))
        && *(_BYTE*)(v4 + 8) & 6
        && sub_4EE7E0(v4, 1, *(_DWORD*)(a1 + 72)))
    {
        if (*(_BYTE*)(v4 + 8) & 4)
        {
            v5 = *(_DWORD*)(v4 + 748);
            a4 = 2;
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 13, &a4);
        }
    }
}

//----- (004E08E0) --------------------------------------------------------
void __cdecl sub_4E08E0(int a1, int a2, int a3, int a4, int* a5)
{
    int v5; // edi
    int v6; // esi
    int v7; // eax
    int v8; // [esp-8h] [ebp-Ch]
    int v9; // [esp+10h] [ebp+Ch]
    float v10; // [esp+14h] [ebp+10h]

    v5 = a3;
    if (a3 && a4 && *(_BYTE*)(a4 + 8) & 6)
    {
        v8 = a4;
        v10 = *(float*)(a1 + 68);
        v6 = *a5;
        v9 = *a5;
        v7 = (unsigned __int16)sub_4EE780(v8);
        if (v7 < v6)
            v9 = v7;
        sub_4EE5E0(v5, (__int64)((double)v9 * v10));
    }
}

//----- (004E0960) --------------------------------------------------------
int __cdecl sub_4E0960(int a1)
{
    int v1; // esi
    int v2; // edx
    int i; // ecx

    v1 = *(_DWORD*)(a1 + 692);
    if (!a1 || !(*(_DWORD*)(a1 + 8) & 0x13001000))
        return 0;
    v2 = 2;
    for (i = v1 + 8; !*(_DWORD*)i || *(int (**)())(*(_DWORD*)i + 40) != nullsub_22; i += 4)
    {
        if (++v2 >= 4)
            return 0;
    }
    return *(_DWORD*)(*(_DWORD*)(v1 + 4 * v2) + 48);
}
// 4E0950: using guessed type void nullsub_22();

//----- (004E09B0) --------------------------------------------------------
int __cdecl sub_4E09B0(int a1, int a2, int a3, int a4, int a5)
{
    int result; // eax

    result = a5;
    *(float*)(a5 + 544) = *(float*)(a1 + 44) * *(float*)(a5 + 544);
    return result;
}

//----- (004E09E0) --------------------------------------------------------
void sub_4E09E0()
{
    nox_srand(0x226Bu);
}

//----- (004E09F0) --------------------------------------------------------
void sub_4E09F0()
{
    nox_srand(0x7DCu);
}

//----- (004E0A00) --------------------------------------------------------
int __cdecl sub_4E0A00(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[200728];
    do
    {
        if (!strcmp(a1, *v2))
            break;
        ++v2;
        ++v1;
    } while ((int)v2 < (int)& byte_587000[200800]);
    return v1;
}

//----- (004E0A70) --------------------------------------------------------
int __cdecl sub_4E0A70(int a1, int a2)
{
    int result; // eax
    double v3; // st7
    double v4; // st6
    __int16 v5; // cx
    double v6; // st5
    double v7; // st6
    int v8; // edx
    float v9; // [esp+0h] [ebp-10h]
    float v10; // [esp+4h] [ebp-Ch]
    float v11; // [esp+8h] [ebp-8h]
    float v12; // [esp+8h] [ebp-8h]
    float v13; // [esp+14h] [ebp+4h]

    result = a1;
    v3 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
    v4 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
    *(_WORD*)(a1 + 124) += 128;
    v5 = *(_WORD*)(a1 + 124);
    v11 = -v4;
    v13 = sqrt(v4 * v4 + v3 * v3) + 0.1;
    v6 = (v4 * *(float*)(result + 84) + v3 * *(float*)(result + 80)) / v13;
    v9 = v6 * v3 / v13;
    v10 = v6 * v4 / v13;
    v7 = (v11 * *(float*)(result + 80) + v3 * *(float*)(result + 84)) / v13;
    v12 = v7 * v11 / v13;
    *(float*)(result + 80) = v12 - v9;
    *(float*)(result + 84) = v3 * v7 / v13 - v10;
    if (v5 >= 256)
        * (_WORD*)(result + 124) = v5 - 256;
    v8 = *(_DWORD*)(result + 76);
    *(_DWORD*)(result + 64) = *(_DWORD*)(result + 72);
    *(_DWORD*)(result + 68) = v8;
    return result;
}

//----- (004E0B30) --------------------------------------------------------
int __cdecl sub_4E0B30(int a1, int a2, int a3, int a4, int a5)
{
    int v6; // edi
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // edi
    int v11; // eax
    int v12; // ebp
    int v13; // eax
    int v14; // eax
    int v15; // ebp
    double v16; // st7
    double v17; // st7
    int v18; // eax
    int v19; // ebx
    int v20; // eax
    int v21; // edx
    int v22; // eax
    char v23; // al
    _DWORD* v24; // eax
    int v25; // edx
    int v26; // ecx
    int v27; // eax
    int v28; // eax
    void(__cdecl * v29)(int, int); // eax
    unsigned __int8 v30; // al
    double v31; // st7
    unsigned __int16 v32; // bp
    int v33; // eax
    float v34; // ecx
    int v35; // eax
    float v36; // edx
    char v37; // al
    int v38; // ebp
    int v39; // eax
    int v40; // eax
    float v41; // [esp+0h] [ebp-28h]
    float v42; // [esp+4h] [ebp-24h]
    float v43; // [esp+4h] [ebp-24h]
    float v44; // [esp+4h] [ebp-24h]
    int v45[4]; // [esp+18h] [ebp-10h]
    float v46; // [esp+30h] [ebp+8h]
    float v47; // [esp+30h] [ebp+8h]

    if (!a1)
        return 1;
    if (sub_4FF350(a1, 23))
    {
        if (!(byte_5D4594[2598000] & 3))
        {
            sub_501960(71, a1, 0, 0);
            return 1;
        }
        return 1;
    }
    v6 = a5;
    if (*(_BYTE*)(a1 + 8) & 2)
    {
        v7 = *(_DWORD*)(a1 + 748);
        *(_DWORD*)(v7 + 2188) = 0;
        if (v6 == 1 || v6 == 12 || v6 == 7 || v6 == 14 || v6 == 6)
            * (_DWORD*)(v7 + 1440) |= 0x80000u;
    }
    v8 = *(_DWORD*)(a1 + 16);
    if ((v8 & 0x8000) == 0)
    {
        v10 = a2;
        if (!sub_417DA0(1))
        {
            v11 = sub_4EC580(a2);
            v12 = v11;
            if (v11)
            {
                if (*(_BYTE*)(v11 + 8) & 6 && !sub_5330C0(a1, v11) && (a1 != v12 || sub_40A5C0(4096)))
                    return 1;
            }
        }
        if (a2 && a3 && !sub_5330C0(a1, a2) && *(_BYTE*)(a1 + 8) & 6 && sub_4E1400(a2, (_DWORD*)a3) && !sub_4E1470(a3)
            || *(_BYTE*)(a1 + 16) & 2)
        {
            return 1;
        }
        if (a2)
        {
            if (sub_4FF350(a1, 22))
            {
                if (*(_BYTE*)(a2 + 8) & 6)
                {
                    if (a3)
                    {
                        if (sub_4E1400(a2, (_DWORD*)a3))
                        {
                            sub_501960(135, a2, 0, 0);
                            sub_4FF5B0(a1, 22);
                            v41 = sub_419D70(&byte_587000[201116], 4);
                            v13 = sub_419A70(v41);
                            (*(void(__cdecl * *)(int, int, _DWORD, int, int))(a2 + 716))(a2, a1, 0, v13, 9);
                            if (*(_BYTE*)(a2 + 8) & 4)
                                sub_4FA020((_DWORD*)a2, 23);
                        }
                    }
                }
            }
        }
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v14 = *(_DWORD*)(a1 + 12);
            v15 = a5;
            if (v14 & 0x200 && a5 == 5)
                return 1;
            if (v14 & 0x400)
            {
                if (a5 == 1 || a5 == 12)
                    return 1;
                if (a5 == 7)
                {
                    a4 /= 2;
                    LABEL_53:
                    v16 = sub_4DFE40((_DWORD*)a1);
                    if (v16 != 0.0 && !(byte_5D4594[2598000] & 3))
                        sub_501960(104, a1, 0, 0);
                    v46 = v16;
                    v42 = (1.0 - v46) * (double)a4;
                    a4 = sub_419A70(v42);
                    if (!a4)
                        a4 = 1;
                    LABEL_58:
                    if (v15 == 9 || v15 == 17)
                    {
                        v17 = sub_4DFF40((_DWORD*)a1);
                        if (v17 != 0.0 && !(byte_5D4594[2598000] & 3))
                            sub_501960(108, a1, 0, 0);
                        v47 = v17;
                        v43 = (1.0 - v47) * (double)a4;
                        a4 = sub_419A70(v43);
                        if (!a4)
                            a4 = 1;
                        v18 = *(_DWORD*)(a1 + 8);
                        if (v18 & 4)
                        {
                            *(_WORD*)(*(_DWORD*)(a1 + 748) + 160) = 2;
                        }
                        else if (v18 & 2 && *(_BYTE*)(a1 + 12) & 0x10)
                        {
                            *(_BYTE*)(*(_DWORD*)(a1 + 748) + 2094) = 2;
                        }
                    }
                    if (!v10)
                    {
                        *(_DWORD*)(a1 + 528) = 0;
                        *(_DWORD*)(a1 + 532) = 0;
                        if (v15 == 12)
                            sub_4FF5B0(a1, 0);
                        v19 = a3;
                        LABEL_87:
                        v22 = *(_DWORD*)(a1 + 8);
                        if (v22 & 4 || v22 & 2 && *(_BYTE*)(a1 + 12) & 0x10)
                            sub_4E1320(a1, v10, v19, &a4, v15);
                        if (v19)
                            * (_DWORD*)(a1 + 520) = v19;
                        else
                            *(_DWORD*)(a1 + 520) = v10;
                        v23 = *(_BYTE*)(a1 + 8);
                        *(_DWORD*)(a1 + 524) = v15;
                        *(_DWORD*)(a1 + 536) = *(_DWORD*)& byte_5D4594[2598000];
                        if (v23 & 2)
                        {
                            v24 = *(_DWORD * *)(a1 + 748);
                            v25 = v24[360];
                            v26 = v24[547];
                            BYTE1(v25) |= 2u;
                            v24[360] = v25;
                            if (!v26)
                            {
                                v24[547] = 2;
                                v24[546] = v15;
                            }
                        }
                        if (v19 && *(_DWORD*)(v19 + 8) & 0x1001000)
                            sub_4E13B0(a1, v10, v19, (int)& a4);
                        if (a1 != v19 || !(*(_DWORD*)(a1 + 8) & 0x1001000))
                        {
                            if (!v10
                                || !(*(_BYTE*)(v10 + 8) & 2)
                                || !*(_DWORD*)(v10 + 748)
                                || (v27 = sub_424300(v10)) == 0
                                || (v28 = *(_DWORD*)(v27 + 32)) == 0
                                || sub_501940(v28) <= 0)
                            {
                                v29 = *(void(__cdecl * *)(int, int))(a1 + 720);
                                if (v29)
                                {
                                    if (v19)
                                        v29(a1, v19);
                                    else
                                        v29(a1, v10);
                                }
                                else if (v19)
                                {
                                    sub_532E20(a1, v19);
                                }
                                else
                                {
                                    sub_532E20(a1, v10);
                                }
                            }
                        }
                        if (v10 && *(_BYTE*)(a1 + 8) & 6 && sub_4FF350(v10, 13))
                        {
                            sub_501960(163, a3, 0, 0);
                            v30 = sub_4FF570(v10, 13);
                            v31 = sub_419D70(&byte_587000[201128], (unsigned int)v30 - 1);
                            v44 = v31 * (double)a4;
                            v32 = sub_419A70(v44);
                            if (v32 < 1u)
                                v32 = 1;
                            sub_4EE460(v10, v32);
                            v45[0] = sub_419A70(*(float*)(v10 + 56));
                            v33 = sub_419A70(*(float*)(v10 + 60));
                            v34 = *(float*)(a1 + 56);
                            v45[1] = v33;
                            v35 = sub_419A70(v34);
                            v36 = *(float*)(a1 + 60);
                            v45[2] = v35;
                            v45[3] = sub_419A70(v36);
                            sub_523270(162, (__int16*)v45, v32);
                        }
                        sub_4E1230(v10, a1, a4);
                        if (*(_BYTE*)(a1 + 8) & 4)
                        {
                            if (a4 >= 20)
                            {
                                v37 = *(_BYTE*)(*(_DWORD*)(a1 + 748) + 88);
                                if (v37 != 1 && v37 != 15)
                                    sub_4FA020((_DWORD*)a1, 30);
                            }
                        }
                        if (sub_40A5C0(6144))
                            sub_4FB050(v10, a1, &a4);
                        if (!v10)
                            goto LABEL_137;
                        if (*(_BYTE*)(v10 + 8) & 2)
                        {
                            v38 = v10;
                        }
                        else
                        {
                            v39 = *(_DWORD*)(v10 + 508);
                            if (!v39 || !(*(_BYTE*)(v39 + 8) & 2))
                            {
                                LABEL_137:
                                if (sub_4FF350(a1, 26) && a5 != 5)
                                {
                                    v40 = a3;
                                    if (!a3)
                                        v40 = v10;
                                    if (a5 != 15 || v10 != a1)
                                        sub_52F710(a1, &a4, a5, v40);
                                    if (!a4)
                                        return 0;
                                }
                                sub_4EE5E0(a1, a4);
                                return 1;
                            }
                            v38 = *(_DWORD*)(v10 + 508);
                        }
                        if (v38 && sub_5330C0(a1, v38))
                            sub_532880(v38);
                        goto LABEL_137;
                    }
                    v19 = a3;
                    if (a3)
                    {
                        if (*(_DWORD*)(a3 + 8) & 0x1001000)
                        {
                            *(_DWORD*)(a1 + 528) = *(_DWORD*)(v10 + 72);
                            *(_DWORD*)(a1 + 532) = *(_DWORD*)(v10 + 76);
                        }
                        else
                        {
                            *(_DWORD*)(a1 + 528) = *(_DWORD*)(a3 + 72);
                            *(_DWORD*)(a1 + 532) = *(_DWORD*)(a3 + 76);
                        }
                        if (a3 == v10 || !(*(_BYTE*)(a1 + 8) & 2))
                            goto LABEL_83;
                        v20 = *(_DWORD*)(a1 + 748);
                        HIWORD(v21) = 0;
                        *(_DWORD*)(v20 + 2188) = 1;
                        LOWORD(v21) = *(_WORD*)(a3 + 4);
                    }
                    else
                    {
                        *(_DWORD*)(a1 + 528) = *(_DWORD*)(v10 + 72);
                        *(_DWORD*)(a1 + 532) = *(_DWORD*)(v10 + 76);
                        if (v15 != 10 && v15 != 2 || !(*(_BYTE*)(a1 + 8) & 2))
                            goto LABEL_83;
                        v20 = *(_DWORD*)(a1 + 748);
                        HIWORD(v21) = 0;
                        *(_DWORD*)(v20 + 2188) = 1;
                        LOWORD(v21) = *(_WORD*)(v10 + 4);
                    }
                    *(_DWORD*)(v20 + 2184) = v21;
                    LABEL_83:
                    sub_4FF5B0(a1, 0);
                    goto LABEL_87;
                }
            }
            else if (v14 & 0x800)
            {
                if (a5 == 9)
                    return 1;
                if (a5 == 17)
                    return 1;
            }
        }
        else
        {
            v15 = a5;
        }
        if (v15 != 1 && v15 != 12 && v15 != 7)
            goto LABEL_58;
        goto LABEL_53;
    }
    if (!sub_534A40(a1))
        return 1;
    v9 = a3;
    if (!a3)
        v9 = a2;
    *(_DWORD*)(a1 + 520) = v9;
    *(_DWORD*)(a1 + 524) = v6;
    *(_DWORD*)(a1 + 536) = *(_DWORD*)& byte_5D4594[2598000];
    return 1;
}

//----- (004E1230) --------------------------------------------------------
void __cdecl sub_4E1230(int a1, int a2, int a3)
{
    int v3; // eax
    int v4; // esi
    char* v5; // eax

    if (*(_BYTE*)(a2 + 8) & 4 && a3 >= 30)
    {
        v3 = *(_DWORD*)& byte_5D4594[1563316];
        if (!*(_DWORD*)& byte_5D4594[1563316])
        {
            v3 = sub_4E3AA0((CHAR*)& byte_587000[201144]);
            *(_DWORD*)& byte_5D4594[1563316] = v3;
        }
        v4 = *(_DWORD*)(a2 + 516);
        if (v4)
        {
            while (*(unsigned __int16*)(v4 + 4) != v3)
            {
                v4 = *(_DWORD*)(v4 + 512);
                if (!v4)
                    return;
            }
            *(_DWORD*)(v4 + 16) &= 0xFFFFFFBF;
            sub_52DF80(a2 + 56, v4, 30.0);
            sub_4EC300(v4);
            sub_4EB9B0(v4, a2);
            if (sub_419130(v4 + 48))
            {
                v5 = sub_418AB0(*(unsigned __int8*)(a1 + 52));
                if (v5)
                    sub_4196D0(v4 + 48, (int)v5, *(_DWORD*)(v4 + 36), 0);
            }
            else
            {
                sub_4191D0(*(_BYTE*)(a1 + 52), v4 + 48, 1, *(_DWORD*)(v4 + 36), 0);
            }
            sub_501960(926, a2, 0, 0);
        }
    }
}

//----- (004E1320) --------------------------------------------------------
int __cdecl sub_4E1320(int a1, int a2, int a3, int* a4, int a5)
{
    int result; // eax
    _DWORD* v6; // esi
    int v7; // ebp
    int* v8; // ebx
    int v9; // eax
    int2 v10; // [esp+4h] [ebp-8h]
    int v11; // [esp+20h] [ebp+14h]

    result = a1;
    v6 = *(_DWORD * *)(a1 + 504);
    if (v6)
    {
        v7 = a5;
        do
        {
            result = v6[4];
            if (result & 0x100)
            {
                v11 = 2;
                v8 = (int*)(v6[173] + 8);
                do
                {
                    v9 = *v8;
                    if (*v8)
                    {
                        if (*(_DWORD*)(v9 + 76))
                        {
                            v10.field_0 = *a4;
                            v10.field_4 = v7;
                            (*(void(__cdecl * *)(int, _DWORD*, int, int, int, int2*))(v9 + 76))(v9, v6, a1, a3, a2, &v10);
                            *a4 = v10.field_0;
                        }
                    }
                    ++v8;
                    result = --v11;
                } while (v11);
            }
            v6 = (_DWORD*)v6[124];
        } while (v6);
    }
    return result;
}

//----- (004E13B0) --------------------------------------------------------
int __cdecl sub_4E13B0(int a1, int a2, int a3, int a4)
{
    int v4; // edi
    int* v5; // esi
    int v6; // eax
    void(__cdecl * v7)(int, int, int, int, int); // ecx
    int result; // eax
    int v9; // [esp+1Ch] [ebp+Ch]

    v4 = a3;
    v9 = 4;
    v5 = *(int**)(v4 + 692);
    do
    {
        v6 = *v5;
        if (*v5)
        {
            v7 = *(void(__cdecl * *)(int, int, int, int, int))(v6 + 64);
            if (v7)
                v7(v6, v4, a2, a1, a4);
        }
        ++v5;
        result = --v9;
    } while (v9);
    return result;
}

//----- (004E1400) --------------------------------------------------------
int __cdecl sub_4E1400(int a1, _DWORD* a2)
{
    int v2; // eax
    int result; // eax
    int v4; // eax

    if (a2)
    {
        v4 = a2[2];
        if (v4 & 0x1000)
        {
            if (!(a2[3] & 0x47F0000))
                return 1;
            if (*(_BYTE*)(a2[184] + 96) & 2)
                return 1;
        }
        else if (v4 & 0x1000000 && !(a2[3] & 0x47F00FE))
        {
            return 1;
        }
        result = ((unsigned __int8)v4 >> 1) & 1;
    }
    else
    {
        v2 = *(_DWORD*)(a1 + 8);
        if (v2 & 4)
            return 1;
        result = v2 & 2 && *(_BYTE*)(a1 + 12) & 0x10;
    }
    return result;
}

//----- (004E1470) --------------------------------------------------------
BOOL __cdecl sub_4E1470(int a1)
{
    int v1; // ecx
    BOOL result; // eax

    result = 0;
    if (a1)
    {
        if (*(_DWORD*)(a1 + 8) & 0x1000000)
        {
            v1 = *(_DWORD*)(a1 + 12);
            if (v1 & 0x4000)
                result = 1;
        }
    }
    return result;
}

//----- (004E14A0) --------------------------------------------------------
int sub_4E14A0()
{
    return 0;
}

//----- (004E14B0) --------------------------------------------------------
int __cdecl sub_4E14B0(int a1, int a2, int a3, int a4, int a5)
{
    int result; // eax

    if (a1 && *(_DWORD*)(a1 + 8) & 0x1001000 && (*(_DWORD*)(a1 + 492) || a5 == 12))
        result = sub_4E0B30(a1, a2, a3, a4, a5);
    else
        result = 0;
    return result;
}

//----- (004E1500) --------------------------------------------------------
int __cdecl sub_4E1500(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // eax
    int result; // eax

    if (*(_DWORD*)(a1 + 8) & 0x2000000
        && (*(_DWORD*)(a1 + 492) || a5 == 12)
        && (a5 != 2 || !(*(_BYTE*)(a1 + 24) & 0x10) ? (v5 = a4) : (v5 = 2 * a4), v5))
    {
        result = sub_4E0B30(a1, a2, a3, v5, a5);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004E1560) --------------------------------------------------------
void __cdecl sub_4E1560(int a1, int a2, int a3, int a4, float a5, int a6)
{
    float* v6; // edi
    int v7; // eax
    void(__cdecl * v8)(int, int, int, int, int, float*); // ecx
    int v9; // eax
    unsigned __int16 v10; // di
    unsigned __int16 v11; // ax

    if (a1)
    {
        if (*(_DWORD*)(a1 + 556))
        {
            v6 = *(float**)(a1 + 748);
            if (!(*(_DWORD*)(a1 + 8) & 0x1000000) || !(*(_DWORD*)(a1 + 12) & 0x7800000))
            {
                v7 = *(_DWORD*)(*(_DWORD*)(a1 + 692) + 4);
                if (v7)
                {
                    v8 = *(void(__cdecl * *)(int, int, int, int, int, float*))(v7 + 76);
                    if (v8)
                        v8(v7, a1, a2, a4, a3, &a5);
                }
                a5 = a5 + *v6;
                v9 = sub_419A70(a5);
                *v6 = a5 - (double)v9;
                if (v9 > 0)
                {
                    v10 = **(_WORD * *)(a1 + 556);
                    (*(void(__cdecl * *)(int, int, int, int, int))(a1 + 716))(a1, a3, a4, v9, a6);
                    if (a2)
                    {
                        if (*(_BYTE*)(a2 + 8) & 4)
                        {
                            v11 = **(_WORD * *)(a1 + 556);
                            if (v10 != v11)
                                sub_4E1650(
                                        *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064),
                                        (_DWORD*)a1,
                                        v10,
                                        v11);
                        }
                    }
                }
            }
        }
    }
}

//----- (004E1650) --------------------------------------------------------
int __cdecl sub_4E1650(int a1, _DWORD* a2, unsigned __int16 a3, unsigned __int16 a4)
{
    int result; // eax
    int v5; // edi

    result = a2[139];
    if (result)
    {
        if (sub_40A5C0(2048))
        {
            result = sub_4D87A0(a1, a2);
        }
        else
        {
            v5 = sub_57B190(a3, *(_WORD*)(a2[139] + 4));
            result = sub_57B190(a4, *(_WORD*)(a2[139] + 4));
            if (v5 != result)
                result = sub_4D87A0(a1, a2);
        }
    }
    return result;
}

//----- (004E16D0) --------------------------------------------------------
void __cdecl sub_4E16D0(int a1, int a2, int a3, int a4, float a5, int a6)
{
    float* v6; // edi
    int v7; // eax
    void(__cdecl * v8)(int, int, int, int, int, float*); // ecx
    int v9; // eax
    unsigned __int16 v10; // di
    unsigned __int16 v11; // ax

    if (a1 && *(_DWORD*)(a1 + 556))
    {
        v6 = *(float**)(a1 + 748);
        v7 = *(_DWORD*)(*(_DWORD*)(a1 + 692) + 4);
        if (v7)
        {
            v8 = *(void(__cdecl * *)(int, int, int, int, int, float*))(v7 + 76);
            if (v8)
                v8(v7, a1, a2, a4, a3, &a5);
        }
        a5 = a5 + *v6;
        v9 = sub_419A70(a5);
        *v6 = a5 - (double)v9;
        if (v9 > 0)
        {
            v10 = **(_WORD * *)(a1 + 556);
            (*(void(__cdecl * *)(int, int, int, int, int))(a1 + 716))(a1, a3, a4, v9, a6);
            if (*(_BYTE*)(a2 + 8) & 4)
            {
                v11 = **(_WORD * *)(a1 + 556);
                if (v10 != v11)
                    sub_4E1650(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064), (_DWORD*)a1, v10, v11);
            }
        }
    }
}

//----- (004E17B0) --------------------------------------------------------
int __cdecl sub_4E17B0(int a1, int a2, int a3, int a4, float a5)
{
    int v5; // esi
    int v6; // eax
    BOOL v8; // eax
    int v9; // ebx
    int v10; // edx
    int v11; // ecx
    int v12; // edi
    int* v13; // eax
    int v14; // ebp
    float v15; // eax
    float2* v16; // ebp
    int v17; // ecx
    int v18; // eax
    int v19; // edx
    int v20; // eax
    BOOL v21; // ecx
    int v22; // eax
    int v23; // eax
    int v24; // eax
    int v25; // ebp
    double v26; // st7
    int v27; // ebp
    char v28; // al
    int v29; // eax
    double v30; // st7
    char v31; // al
    double v32; // st7
    int v33; // ebp
    int v34; // eax
    double v35; // st7
    float v36; // edx
    float v37; // eax
    int v38; // eax
    float v39; // ecx
    float v40; // edx
    int v41; // eax
    float v42; // ebx
    int v43; // eax
    int v44; // edi
    int v45; // eax
    float v46; // [esp+0h] [ebp-2Ch]
    float v47; // [esp+0h] [ebp-2Ch]
    float v48; // [esp+0h] [ebp-2Ch]
    float v49; // [esp+4h] [ebp-28h]
    float v50; // [esp+4h] [ebp-28h]
    float v51; // [esp+4h] [ebp-28h]
    float v52; // [esp+4h] [ebp-28h]
    float v53; // [esp+18h] [ebp-14h]
    int v54; // [esp+1Ch] [ebp-10h]
    int v55; // [esp+20h] [ebp-Ch]
    float2 a3a; // [esp+24h] [ebp-8h]

    v5 = a1;
    v6 = *(_DWORD*)(a1 + 16);
    if (v6 & 2 || (v6 & 0x8000) != 0)
        return 0;
    if (sub_4FF350(a1, 23))
    {
        if (!(byte_5D4594[2598000] & 3))
            sub_501960(71, v5, 0, 0);
        return 1;
    }
    v8 = sub_40A5C0(2048);
    v9 = a2;
    if (v8)
    {
        if (sub_4EC580(a2) == v5 && *(_BYTE*)(v5 + 8) & 4 && LODWORD(a5) != 15)
            return 0;
    }
    if (a3)
        v9 = a3;
    v10 = *(_DWORD*)(v5 + 8);
    v11 = *(_DWORD*)(v5 + 8) & 4;
    if (v11)
    {
        v12 = *(_DWORD*)(v5 + 748);
        v13 = *(int**)(v12 + 276);
        v14 = v13[1];
        v54 = *v13;
        v15 = *(float*)(v12 + 228);
        v55 = v14;
    }
    else
    {
        if (!(v10 & 2) || !(*(_BYTE*)(v5 + 12) & 0x10))
            return 0;
        v12 = *(_DWORD*)(v5 + 748);
        v55 = *(_DWORD*)(v12 + 2056);
        v54 = *(_DWORD*)(v12 + 2060);
        v15 = *(float*)(v12 + 2072);
    }
    v53 = v15;
    if (v11)
    {
        if (*(_BYTE*)(*(_DWORD*)(v12 + 276) + 3680) & 1)
            return 0;
    }
    if (v11)
    {
        *(_DWORD*)(v12 + 304) = 0;
    }
    else if (v10 & 2)
    {
        *(_DWORD*)(v12 + 2188) = 0;
    }
    if (*(_BYTE*)(v5 + 8) & 4 && sub_4DDF30(v5))
        sub_4DDEF0(v5);
    if (sub_4FF350(v5, 27) && v9)
    {
        if (*(_BYTE*)(v9 + 8) & 1)
        {
            v16 = (float2*)(v5 + 56);
            if (sub_4E6E50((float2*)(v5 + 56), *(__int16*)(v5 + 124), (float2*)(v9 + 56)) & 1)
            {
                sub_4E0A70(v9, v5);
                if (!(*(_BYTE*)(v9 + 12) & 0x40))
                {
                    sub_4EC300(v9);
                    sub_4EC290(v5, v9);
                }
                if (*(_BYTE*)(v9 + 8) & 1 && *(_BYTE*)(v9 + 12) & 2)
                    sub_52BE40(v9, v5);
                goto LABEL_36;
            }
        }
        else if (LODWORD(a5) == 16 || LODWORD(a5) == 17)
        {
            v16 = (float2*)(v5 + 56);
            if (sub_4E6E50((float2*)(v5 + 56), *(__int16*)(v5 + 124), (float2*)(v9 + 56)) & 1)
            {
                LABEL_36:
                if (LODWORD(a5) == 16)
                    sub_522FF0(132, v16);
                sub_501960(122, v5, 0, 0);
                return 0;
            }
        }
    }
    if (!a2)
        goto LABEL_120;
    v17 = *(_DWORD*)& byte_5D4594[1563320];
    if (!*(_DWORD*)& byte_5D4594[1563320])
    {
        *(_DWORD*)& byte_5D4594[1563320] = sub_4E3AA0((CHAR*)& byte_587000[201156]);
        *(_DWORD*)& byte_5D4594[1563324] = sub_4E3AA0((CHAR*)& byte_587000[201168]);
        *(_DWORD*)& byte_5D4594[1563328] = sub_4E3AA0((CHAR*)& byte_587000[201180]);
        *(_DWORD*)& byte_5D4594[1563332] = sub_4E3AA0((CHAR*)& byte_587000[201192]);
        *(_DWORD*)& byte_5D4594[1563336] = sub_4E3AA0((CHAR*)& byte_587000[201200]);
        v18 = sub_4E3AA0((CHAR*)& byte_587000[201212]);
        v17 = *(_DWORD*)& byte_5D4594[1563320];
        *(_DWORD*)& byte_5D4594[1563340] = v18;
    }
    v19 = a3;
    if (a3)
    {
        a3a = *(float2*)(a3 + 72);
        v20 = *(unsigned __int16*)(a3 + 4);
        v21 = (unsigned __int16)v20 != v17
              && v20 != *(_DWORD*)& byte_5D4594[1563324]
              && v20 != *(_DWORD*)& byte_5D4594[1563328]
              && v20 != *(_DWORD*)& byte_5D4594[1563332]
              && v20 != *(_DWORD*)& byte_5D4594[1563336]
              && v20 != *(_DWORD*)& byte_5D4594[1563340];
        if (a2 != a3)
        {
            v22 = *(_DWORD*)(v5 + 8);
            if (v22 & 4)
            {
                LABEL_56:
                *(_DWORD*)(v12 + 304) = 1;
                *(_DWORD*)(v12 + 300) = *(unsigned __int16*)(v19 + 4);
                goto LABEL_70;
            }
            if (!(v22 & 2))
                goto LABEL_70;
            LABEL_69:
            *(_DWORD*)(v12 + 2188) = 1;
            *(_DWORD*)(v12 + 2184) = *(unsigned __int16*)(v19 + 4);
            goto LABEL_70;
        }
    }
    else
    {
        v19 = a2;
        a3a = *(float2*)(a2 + 72);
        v23 = *(unsigned __int16*)(a2 + 4);
        v21 = (unsigned __int16)v23 != v17
              && v23 != *(_DWORD*)& byte_5D4594[1563324]
              && v23 != *(_DWORD*)& byte_5D4594[1563328]
              && v23 != *(_DWORD*)& byte_5D4594[1563332];
        if (LODWORD(a5) == 10 || LODWORD(a5) == 2)
        {
            v24 = *(_DWORD*)(v5 + 8);
            if (v24 & 4)
                goto LABEL_56;
            if (!(v24 & 2))
                goto LABEL_70;
            goto LABEL_69;
        }
    }
    LABEL_70:
    if (LODWORD(a5) == 15 || !v21 || !(sub_4E6E50((float2*)(v5 + 56), *(__int16*)(v5 + 124), &a3a) & 1))
        goto LABEL_120;
    if (*(_BYTE*)(v5 + 8) & 4)
    {
        if (*(_BYTE*)(v12 + 88) != 16)
            goto LABEL_86;
    }
    else if (sub_50A020(v5) != 21)
    {
        goto LABEL_86;
    }
    if (!(v54 & 0x3000000))
    {
        LABEL_86:
        v27 = LODWORD(a5);
        if (v55 & 0x400)
        {
            v27 = LODWORD(a5);
            if (*(_BYTE*)(v9 + 8) & 1 || a5 == 0.0 || LODWORD(a5) == 11)
            {
                if (*(_BYTE*)(v5 + 8) & 4)
                {
                    v28 = *(_BYTE*)(v12 + 88);
                    if (v28 != 13 && v28 != 18 && v28 != 19 && v28 != 20)
                        goto LABEL_120;
                }
                else if (!sub_534340(v5))
                {
                    goto LABEL_120;
                }
                if (*(_BYTE*)(v9 + 8) & 1)
                {
                    sub_4E0A70(v9, v5);
                    if (*(_BYTE*)(v9 + 8) & 1)
                    {
                        if (!(*(_BYTE*)(v9 + 12) & 2))
                        {
                            sub_4EC300(v9);
                            sub_4EC290(v5, v9);
                        }
                    }
                }
                sub_501960(890, v5, 0, 0);
                if (*(_BYTE*)(v5 + 8) & 4)
                {
                    v29 = sub_415FA0(18, 20);
                    sub_4FA020((_DWORD*)v5, v29);
                }
                else
                {
                    sub_50A360(v5, 23);
                }
                v30 = sub_419D40(&byte_587000[201308]);
                v47 = v30 * (double)a4;
                sub_4E22A0(v5, a2, a3, 1024, v47, v27);
                return 0;
            }
        }
        else
        {
            if (*(_BYTE*)(v12 + 88) == 1 || sub_4FA2B0(v5) == 45 || HIBYTE(v54) == 1 && HIBYTE(v54) == 2)
            {
                if (*(int*)((char*)dword_980858 + 2) & 0x10)
                    goto M_LABEL_78;
            }
        }
        if (!(v55 & 0x7FF8000) || v27 && v27 != 11 || *(_BYTE*)(v9 + 8) & 1)
            goto LABEL_120;
        if (*(_BYTE*)(v5 + 8) & 4)
        {
            v31 = *(_BYTE*)(v12 + 88);
            if (v31 != 13 && v31 != 18 && v31 != 19 && v31 != 20 && (v31 || !(*(int*)((char*)dword_980858 + 2) & 4)))
                goto LABEL_120;
        }
        else if (!sub_534340(v5))
        {
            goto LABEL_120;
        }
        sub_501960(894, v5, 0, 0);
        if (*(_BYTE*)(v5 + 8) & 4)
            sub_4FA020((_DWORD*)v5, 21);
        else
            sub_50A360(v5, 23);
        v32 = sub_419D40(&byte_587000[201340]);
        v48 = v32 * (double)a4;
        sub_4E22A0(v5, a2, a3, 134184960, v48, v27);
        return 0;
    }
    M_LABEL_78:
    v25 = LODWORD(a5);
    if (LODWORD(a5) != 9 && LODWORD(a5) != 17)
    {
        sub_501960(878, v5, 0, 0);
        if (*(_BYTE*)(v9 + 8) & 1)
        {
            if (!(*(_BYTE*)(v9 + 12) & 0x70))
            {
                sub_4E0A70(v9, v5);
                if (*(_BYTE*)(v9 + 8) & 1)
                {
                    if (!(*(_BYTE*)(v9 + 12) & 2))
                    {
                        sub_4EC300(v9);
                        sub_4EC290(v5, v9);
                    }
                }
            }
        }
        v26 = sub_419D40(&byte_587000[201228]);
        v46 = v26 * (double)a4;
        sub_4E2330(v5, a2, a3, 2, v46, v25);
        return 0;
    }
    LABEL_120:
    switch (LODWORD(a5))
    {
        case 0:
        case 3:
        case 7:
        case 8:
        case 0xA:
        case 0xB:
            v51 = (1.0 - v53) * (double)a4;
            sub_4E20F0(v5, (int)& a1, v51);
            v33 = a4;
            v42 = a5;
            sub_4E2180(v5, a2, a3, a4 - a1, a5);
            v43 = *(_DWORD*)(v5 + 8);
            if (v43 & 4)
            {
                if (!*(_DWORD*)(v12 + 304))
                {
                    *(_DWORD*)(v12 + 304) = 2;
                    *(float*)(v12 + 300) = v42;
                }
            }
            else if (v43 & 2 && !*(_DWORD*)(v12 + 2188))
            {
                *(_DWORD*)(v12 + 2188) = 2;
                *(float*)(v12 + 2184) = v42;
            }
            break;
        case 1:
        case 0xC:
            v33 = a4;
            a1 = a4;
            sub_4E2180(v5, a2, a3, a4, a5);
            v34 = *(_DWORD*)(v5 + 8);
            if (!(v34 & 4))
                goto LABEL_126;
            goto LABEL_124;
        case 2:
            v50 = (1.0 - v53 * 0.5) * (double)a4;
            sub_4E20F0(v5, (int)& a1, v50);
            v33 = a4;
            sub_4E2180(v5, a2, a3, a4 - a1, COERCE_FLOAT(2));
            v41 = *(_DWORD*)(v5 + 8);
            if (v41 & 4)
            {
                if (!*(_DWORD*)(v12 + 304))
                {
                    *(_DWORD*)(v12 + 304) = 2;
                    *(_DWORD*)(v12 + 300) = 2;
                }
            }
            else if (v41 & 2 && !*(_DWORD*)(v12 + 2188))
            {
                *(_DWORD*)(v12 + 2188) = 2;
                *(_DWORD*)(v12 + 2184) = 2;
            }
            break;
        case 4:
        case 5:
        case 6:
        case 0xE:
        case 0xF:
        case 0x10:
            v38 = *(_DWORD*)(v5 + 8);
            v33 = a4;
            a1 = a4;
            if (v38 & 4)
            {
                if (!*(_DWORD*)(v12 + 304))
                {
                    v39 = a5;
                    *(_DWORD*)(v12 + 304) = 2;
                    *(float*)(v12 + 300) = v39;
                }
            }
            else if (v38 & 2 && !*(_DWORD*)(v12 + 2188))
            {
                v40 = a5;
                *(_DWORD*)(v12 + 2188) = 2;
                *(float*)(v12 + 2184) = v40;
            }
            break;
        case 9:
        case 0x11:
            v35 = sub_4E2220(v5);
            v49 = v35 * (double)a4;
            sub_4E20F0(v5, (int)& a1, v49);
            v33 = a4;
            sub_4E2180(v5, a2, a3, a4, a5);
            v34 = *(_DWORD*)(v5 + 8);
            if (v34 & 4)
            {
                LABEL_124:
                if (!*(_DWORD*)(v12 + 304))
                {
                    v36 = a5;
                    *(_DWORD*)(v12 + 304) = 2;
                    *(float*)(v12 + 300) = v36;
                }
            }
            else
            {
                LABEL_126:
                if (v34 & 2 && !*(_DWORD*)(v12 + 2188))
                {
                    v37 = a5;
                    *(_DWORD*)(v12 + 2188) = 2;
                    *(float*)(v12 + 2184) = v37;
                }
            }
            break;
        default:
            v33 = a4;
            a1 = a4;
            break;
    }
    if (v33 > 0 && !a1)
        a1 = 1;
    if (byte_5D4594[2650636] & 0x20 && *(_BYTE*)(v5 + 8) & 4)
        return 1;
    if (sub_40A5C0(4096))
    {
        v44 = a1;
        v52 = sub_4E40B0() * (double)a1;
        v45 = sub_419A70(v52);
        a1 = v45;
        if (v44 > 0 && v45 < 1)
        {
            v45 = 1;
            a1 = 1;
        }
    }
    else
    {
        v45 = a1;
    }
    return sub_4E0B30(v5, a2, a3, v45, SLODWORD(a5));
}

//----- (004E20F0) --------------------------------------------------------
void __cdecl sub_4E20F0(int a1, int a2, float a3)
{
    int v3; // esi
    int v4; // eax
    double v5; // st7
    int v6; // eax
    int v7; // eax
    int v8; // [esp+Ch] [ebp+4h]

    v3 = a1;
    if (a1 && a2)
    {
        v4 = *(_DWORD*)(a1 + 8);
        if (v4 & 4)
        {
            v5 = a3 + *(float*)(*(_DWORD*)(a1 + 748) + 84);
        }
        else
        {
            if (!(v4 & 2))
                goto LABEL_8;
            v5 = a3 + *(float*)(*(_DWORD*)(a1 + 748) + 4);
        }
        a3 = v5;
        LABEL_8:
        v6 = sub_419A70(a3);
        v8 = v6;
        *(_DWORD*)a2 = v6;
        v7 = *(_DWORD*)(v3 + 8);
        if (v7 & 4)
        {
            *(float*)(*(_DWORD*)(v3 + 748) + 84) = a3 - (double)v8;
        }
        else if (v7 & 2)
        {
            *(float*)(*(_DWORD*)(v3 + 748) + 4) = a3 - (double)v8;
        }
    }
}

//----- (004E2180) --------------------------------------------------------
void __cdecl sub_4E2180(int a1, int a2, int a3, int a4, float a5)
{
    int v5; // edi
    int v6; // eax
    _DWORD* v7; // esi
    int v8; // ebx
    int v9; // eax
    int v10; // [esp+Ch] [ebp+4h]
    float v11; // [esp+1Ch] [ebp+14h]

    v5 = a1;
    v6 = *(_DWORD*)(a1 + 8);
    if (v6 & 4)
    {
        v10 = *(int*)(*(_DWORD*)(a1 + 748) + 228);
    }
    else
    {
        if (!(v6 & 2) || !(*(_BYTE*)(a1 + 12) & 0x10))
            return;
        v10 = *(int*)(*(_DWORD*)(a1 + 748) + 2072);
    }
    v7 = *(_DWORD * *)(v5 + 504);
    if (v7)
    {
        v8 = LODWORD(a5);
        do
        {
            if (v7[2] & 0x2000000)
            {
                v9 = v7[4];
                if (v9 & 0x100)
                {
                    v11 = sub_415C00((int)v7) / *(float*)& v10 * (double)a4;
                    sub_4E16D0((int)v7, v5, a2, a3, v11, v8);
                }
            }
            v7 = (_DWORD*)v7[124];
        } while (v7);
    }
}

//----- (004E2220) --------------------------------------------------------
double __cdecl sub_4E2220(int a1)
{
    int v1; // esi
    int v2; // eax
    double v3; // st7
    float v5; // [esp+4h] [ebp-4h]

    v5 = 1.0;
    v1 = *(_DWORD*)(a1 + 504);
    if (!v1)
        return 1.0;
    do
    {
        if (*(_DWORD*)(v1 + 8) & 0x2000000)
        {
            if (*(_BYTE*)(v1 + 24) & 0x10)
            {
                v2 = *(_DWORD*)(v1 + 16);
                if (v2 & 0x100)
                {
                    if (!sub_4133D0(v1))
                    {
                        if (*(_DWORD*)(v1 + 12) & 0x2000000)
                            v3 = *(float*)& byte_587000[201108];
                        else
                            v3 = sub_415BD0(v1);
                        v5 = v3 + v5;
                    }
                }
            }
        }
        v1 = *(_DWORD*)(v1 + 496);
    } while (v1);
    return v5;
}

//----- (004E22A0) --------------------------------------------------------
int __cdecl sub_4E22A0(int a1, int a2, int a3, int a4, float a5, int a6)
{
    _DWORD* i; // esi
    int v7; // eax

    for (i = *(_DWORD * *)(a1 + 504); i; i = (_DWORD*)i[124])
    {
        if (i[4] & 0x100 && a4 & i[3])
            break;
    }
    v7 = a3;
    if (!a3)
        v7 = a2;
    sub_4E1560((int)i, a1, a2, v7, a5, a6);
    if (!(i[4] & 0x20))
        return 0;
    if (*(_BYTE*)(a1 + 8) & 4)
        sub_4FA020((_DWORD*)a1, 13);
    else
        sub_50A160(a1);
    return 1;
}

//----- (004E2330) --------------------------------------------------------
int __cdecl sub_4E2330(int a1, int a2, int a3, int a4, float a5, int a6)
{
    _DWORD* i; // esi
    int v7; // eax

    for (i = *(_DWORD * *)(a1 + 504); i; i = (_DWORD*)i[124])
    {
        if (i[4] & 0x100 && a4 & i[3])
            break;
    }
    v7 = a3;
    if (!a3)
        v7 = a2;
    sub_4E16D0((int)i, a1, a2, v7, a5, a6);
    if (i == 0)
        return 0;
    if (!(i[4] & 0x20))
        return 0;
    if (*(_BYTE*)(a1 + 8) & 4)
        sub_4FA020((_DWORD*)a1, 13);
    else
        sub_50A160(a1);
    return 1;
}

//----- (004E23C0) --------------------------------------------------------
int __cdecl sub_4E23C0(int a1, int a2, int a3, int a4, int a5)
{
    int result; // eax
    float v6; // ecx
    float v7; // eax
    int v8; // edi
    float2 a3a; // [esp+10h] [ebp-8h]

    if (sub_4FF350(a1, 23))
    {
        if (!(byte_5D4594[2598000] & 3))
            sub_501960(71, a1, 0, 0);
        result = 1;
    }
    else if (a2
             && (!a3 ? (v7 = *(float*)(a2 + 76), a3a.field_0 = *(float*)(a2 + 72), a3a.field_4 = v7) : (v6 = *(float*)(a3 + 76), a3a.field_0 = *(float*)(a3 + 72), a3a.field_4 = v6),
            sub_4E6E50((float2*)(a1 + 56), *(__int16*)(a1 + 124), &a3a) & 1
            && (v8 = *(_DWORD*)(a1 + 748), sub_50A020(a1) == 21)
            && *(_BYTE*)(v8 + 481) > (unsigned int)(*(_BYTE*)(v8 + 480) >> 1)))
    {
        sub_501960(878, a1, 0, 0);
        result = 1;
    }
    else
    {
        result = sub_4E0B30(a1, a2, a3, a4, a5);
    }
    return result;
}

//----- (004E24B0) --------------------------------------------------------
int __cdecl sub_4E24B0(int a1, int a2, int a3, int a4, int a5)
{
    return sub_4E0B30(a1, a2, a3, a4, a5);
}

//----- (004E24E0) --------------------------------------------------------
int __cdecl sub_4E24E0(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // eax

    if (a5 != 9 && a5 != 17)
        v5 = a4;
    else
        v5 = 2 * a4;
    return sub_4E0B30(a1, a2, a3, v5, a5);
}

//----- (004E2520) --------------------------------------------------------
int __cdecl sub_4E2520(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // eax

    if (a5 == 1 || a5 == 12 || (v5 = a4, a5 == 7))
        v5 = 9999999;
    return sub_4E0B30(a1, a2, a3, v5, a5);
}

//----- (004E2560) --------------------------------------------------------
int __cdecl sub_4E2560(int a1, int a2, int a3, int a4, int a5)
{
    int result; // eax

    if (a5 != 1 && a5 != 12 && a5 != 2 && a5)
        result = 0;
    else
        result = sub_4E0B30(a1, a2, a3, 999999, a5);
    return result;
}

//----- (004E25A0) --------------------------------------------------------
int __cdecl sub_4E25A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[201112] = a1;
    return result;
}

//----- (004E25B0) --------------------------------------------------------
bool __cdecl sub_4E25B0(int a1, float a2, float a3, int a4, int a5, int a6, int a7)
{
    bool result; // al
    float4 a1a; // [esp+0h] [ebp-3Ch]
    int4 v11; // [esp+10h] [ebp-2Ch]
    int a3a[7]; // [esp+20h] [ebp-1Ch]

    a3a[6] = a7;
    a3a[3] = a4;
    a3a[5] = a6;
    a3a[4] = a5;
    a3a[0] = a1;
    *(float*)& a3a[2] = a3;
    if (a2 >= (double)a3)
        * (float*)& a3a[1] = a2;
    else
        *(float*)& a3a[1] = a3;
    a1a.field_0 = *(float*)a1 - *(float*)& a3a[1];
    a1a.field_4 = *(float*)(a1 + 4) - *(float*)& a3a[1];
    a1a.field_8 = *(float*)& a3a[1] + *(float*)a1;
    a1a.field_C = *(float*)& a3a[1] + *(float*)(a1 + 4);
    sub_517C10(&a1a, sub_4E2700, (int)a3a);
    v11.field_0 = sub_419A70(a1a.field_0) / 23;
    v11.field_4 = sub_419A70(a1a.field_4) / 23;
    v11.field_8 = sub_419A70(a1a.field_8) / 23;
    v11.field_C = sub_419A70(a1a.field_C) / 23;
    result = sub_534FC0(&v11, a1, a2, a4, a5, a6);
    *(_DWORD*)& byte_587000[201112] = 1;
    return result;
}

//----- (004E2700) --------------------------------------------------------
void __cdecl sub_4E2700(float* a1, int a2)
{
    int v2; // esi
    float* v3; // ecx
    double v4; // st7
    double v5; // st6
    long double v6; // st5
    float v7; // edx
    float v8; // eax
    __int64 v9; // rax
    float4 v10; // [esp+8h] [ebp-10h]
    float v11; // [esp+20h] [ebp+8h]

    v2 = a2;
    if ((a1 != *(float**)(a2 + 20) || *(_DWORD*)& byte_587000[201112]) && *(float**)(a2 + 24) != a1)
    {
        v3 = *(float**)a2;
        v4 = a1[14] - **(float**)a2;
        v5 = a1[15] - *(float*)(*(_DWORD*)a2 + 4);
        v6 = sqrt(v5 * v5 + v4 * v4);
        v11 = v6;
        if (v6 <= *(float*)(v2 + 4))
        {
            v7 = a1[14];
            v10.field_0 = *v3;
            v8 = a1[15];
            v10.field_4 = v3[1];
            v10.field_8 = v7;
            v10.field_C = v8;
            if (sub_535250(&v10, 0, 0, 1))
            {
                if (v11 >= (double) * (float*)(v2 + 8))
                    v9 = (__int64)((1.0 - (v11 - *(float*)(v2 + 8)) / (*(float*)(v2 + 4) - *(float*)(v2 + 8)))
                                   * (double) * (int*)(v2 + 12));
                else
                    LODWORD(v9) = *(_DWORD*)(v2 + 12);
                (*((void(__cdecl * *)(float*, _DWORD, _DWORD, _DWORD, _DWORD))a1 + 179))(
                        a1,
                        *(_DWORD*)(v2 + 20),
                        0,
                        v9,
                        *(_DWORD*)(v2 + 16));
            }
        }
    }
}

//----- (004E27D0) --------------------------------------------------------
int __cdecl sub_4E27D0(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // ebp
    int v7; // edi
    int v8; // eax
    unsigned __int16* v9; // eax
    int v10; // edi
    int v11; // eax
    int v12; // eax
    int v13; // eax
    float v14; // [esp+0h] [ebp-1Ch]
    float v15; // [esp+0h] [ebp-1Ch]
    float2 a1a; // [esp+14h] [ebp-8h]
    int v17; // [esp+28h] [ebp+Ch]

    v5 = *(_DWORD*)(a1 + 748);
    if (*(_DWORD*)(a1 + 16) & 0x8020)
        return 0;
    if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a1 + 536)) > 0x14
        || !(*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu))
    {
        if (a3)
        {
            a1a.field_0 = *(float*)(a3 + 56) - *(float*)(a1 + 56) + 0.0099999998;
            a1a.field_4 = *(float*)(a3 + 60) - *(float*)(a1 + 60) + 0.0099999998;
            sub_509F20(&a1a);
            a1a.field_0 = a1a.field_0 * 22.0 + *(float*)(a1 + 56);
            a1a.field_4 = a1a.field_4 * 22.0 + *(float*)(a1 + 60);
            sub_523150(240, 26, &a1a.field_0);
        }
        else
        {
            sub_523150(240, 26, (float*)(a1 + 56));
        }
        sub_501960(1001, a1, 0, 0);
    }
    v7 = (unsigned __int16)sub_4EE780(a1);
    v17 = sub_4E0B30(a1, a2, a3, a4, a5);
    if ((unsigned __int16)sub_4EE780(a1) < v7)
        sub_502490((int*)(v5 + 48), a2, a1);
    v8 = *(_DWORD*)(a1 + 16);
    if ((v8 & 0x8000) == 0 && !(v8 & 0x20))
    {
        v9 = *(unsigned __int16**)(a1 + 556);
        v10 = *v9;
        v14 = (double)v9[2] * 0.333;
        if (v10 > sub_419A70(v14))
        {
            v15 = (double) * (unsigned __int16*)(*(_DWORD*)(a1 + 556) + 4) * 0.66600001;
            if (v10 <= sub_419A70(v15))
            {
                v13 = *(_DWORD*)(a1 + 20);
                if (!(v13 & 0x100))
                    sub_4E4800(a1, (int*)0x100);
            }
        }
        else
        {
            v11 = *(_DWORD*)(a1 + 20);
            if (v11 & 0x100)
                sub_4E4780(a1, 256);
            v12 = *(_DWORD*)(a1 + 20);
            if (!(v12 & 0x200))
                sub_4E4800(a1, (int*)0x200);
        }
    }
    return v17;
}

//----- (004E29B0) --------------------------------------------------------
void sub_4E29B0()
{
    nox_srand(0x7DDu);
}

//----- (004E29C0) --------------------------------------------------------
void sub_4E29C0()
{
    nox_srand(0x898u);
}

//----- (004E29D0) --------------------------------------------------------
void sub_4E29D0()
{
    int i; // esi
    signed int v1; // eax

    for (i = 0; i < 108; i += 4)
    {
        v1 = *(_DWORD*)& byte_5D4594[i + 1563668];
        if (v1 > 1)
            qsort(*(void**)& byte_5D4594[i + 1563348], v1, 4u, sub_4E2A00);
    }
}

//----- (004E2A00) --------------------------------------------------------
int __cdecl sub_4E2A00(const void* a1, const void* a2)
{
    return _strcmpi(*(const char**)(*(_DWORD*)a1 + 4), *(const char**)(*(_DWORD*)a2 + 4));
}

//----- (004E2A20) --------------------------------------------------------
int sub_4E2A20()
{
    int v0; // esi
    int v1; // ebp
    int v2; // eax
    void* v3; // eax

    v0 = *(_DWORD*)& byte_5D4594[1563660];
    if (*(_DWORD*)& byte_5D4594[1563660])
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 220);
            if (*(_DWORD*)(v0 + 4))
                free(*(LPVOID*)(v0 + 4));
            if (*(_DWORD*)(v0 + 136))
                free(*(LPVOID*)(v0 + 136));
            if (*(_DWORD*)(v0 + 144))
                free(*(LPVOID*)(v0 + 144));
            if (*(_DWORD*)(v0 + 164))
                free(*(LPVOID*)(v0 + 164));
            if (*(_DWORD*)(v0 + 176))
                free(*(LPVOID*)(v0 + 176));
            v2 = *(_DWORD*)(v0 + 192);
            if (v2)
            {
                if (*(_BYTE*)(v0 + 24) & 2)
                {
                    v3 = *(void**)(v2 + 476);
                    if (v3)
                        free(v3);
                }
                free(*(LPVOID*)(v0 + 192));
            }
            if (*(_DWORD*)(v0 + 204))
                free(*(LPVOID*)(v0 + 204));
            free((LPVOID)v0);
            v0 = v1;
        } while (v1);
    }
    *(_DWORD*)& byte_5D4594[1563660] = 0;
    if (*(_DWORD*)& byte_5D4594[1563456])
    {
        free(*(LPVOID*)& byte_5D4594[1563456]);
        *(_DWORD*)& byte_5D4594[1563456] = 0;
    }
    *(_DWORD*)& byte_587000[201384] = 1;
    sub_4E2B30();
    sub_42BF80();
    return 1;
}

//----- (004E2B30) --------------------------------------------------------
LPVOID sub_4E2B30()
{
    LPVOID* v0; // esi
    LPVOID result; // eax

    v0 = (LPVOID*)& byte_5D4594[1563348];
    do
    {
        result = *v0;
        if (*v0)
            free(*v0);
        *v0 = 0;
        ++v0;
    } while ((int)v0 < (int)& byte_5D4594[1563456]);
    return result;
}

//----- (004E2B60) --------------------------------------------------------
void* __cdecl sub_4E2B60(char* a1)
{
    void* v1; // eax
    size_t* v2; // ebx
    void* v3; // edi
    void* result; // eax
    void* v5; // ebp
    unsigned __int8* v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // edx
    double v10; // st7
    const char* v11; // eax
    int v12; // eax
    _DWORD* v13; // eax
    _DWORD* v14; // eax
    void* v15; // eax
    double v16; // st7
    int v17; // ecx
    int v18; // esi
    int v19; // eax
    int i; // [esp+0h] [ebp-8h]
    void* v21; // [esp+4h] [ebp-4h]
    unsigned __int8 v22; // [esp+Ch] [ebp+4h]

    if (*(_DWORD*)& byte_5D4594[1563660])
        sub_4E2A20();
    sub_4E3010();
    *(_DWORD*)& byte_5D4594[1563664] = 0;
    v1 = nox_malloc(0x40000u);
    v2 = *(size_t * *)& byte_5D4594[260];
    v3 = v1;
    v21 = v1;
    if (!*(_DWORD*)& byte_5D4594[260])
    {
        v2 = sub_40ABF0(a1, 7);
        if (!v2)
            return 0;
    }
    sub_40AD10(v2, 0, 0);
    while (sub_40ACC0(&i, 4u, 1, (int)v2))
    {
        switch (i)
        {
            case 1397769548:
                sub_415100((int)v2);
                break;
            case 1094863180:
                sub_415320((int)v2);
                break;
            case 1096107040:
                sub_502320((int)v2, v3);
                break;
            case 1096175188:
                sub_502120((int)v2, v3);
                break;
            case 1463897164:
                if (!sub_414F60(v2, v3))
                    goto LABEL_53;
                break;
            case 1179406162:
                if (!sub_414DB0((int)v2))
                    goto LABEL_53;
                break;
            case 1162102597:
                if (!sub_414E70((int)v2, v3))
                    goto LABEL_53;
                break;
            case 1229799751:
                sub_415240((int)v2);
                break;
            case 1414024775:
                v5 = nox_calloc(1u, 0xE0u);
                if (!v5)
                    goto LABEL_53;
                v6 = (unsigned __int8*)v2[2];
                v22 = *v6;
                v2[2] = (size_t)(v6 + 1);
                sub_40ACC0(v3, 1u, v22, (int)v2);
                *((_BYTE*)v3 + v22) = 0;
                *((_DWORD*)v5 + 1) = nox_clone_str((const char*)v3);
                *((_DWORD*)v5 + 2) = 0;
                *(_WORD*)v5 = *(_WORD*)& byte_587000[201384];
                ++* (_DWORD*)& byte_587000[201384];
                *((_DWORD*)v5 + 14) = 1065353216;
                *((_BYTE*)v5 + 120) = -1;
                *((_DWORD*)v5 + 28) = 0;
                *((_DWORD*)v5 + 29) = 1106247680;
                *((_DWORD*)v5 + 3) = -1;
                *((_WORD*)v5 + 20) = 0x4000;
                *((_DWORD*)v5 + 38) = sub_4E0B30;
                *((_DWORD*)v5 + 39) = sub_532E20;
                *((_DWORD*)v5 + 53) = sub_4F49A0;
                if (!sub_4E3220((int)v2, (char*)v3, (int)v5))
                {
                    LABEL_53:
                    sub_40ACA0_free_ptr2(v2);
                    return 0;
                }
                if (!*((_DWORD*)v5 + 35))
                {
                    v7 = *((_DWORD*)v5 + 8);
                    LOBYTE(v7) = v7 | 0x40;
                    *((_DWORD*)v5 + 8) = v7;
                }
                v8 = *((_DWORD*)v5 + 6);
                v9 = *((_DWORD*)v5 + 8) | 0x1000000;
                *((_WORD*)v5 + 10) = *(_WORD*)v5;
                *((_DWORD*)v5 + 8) = v9;
                if (v8 & 0x400000)
                    * ((_DWORD*)v5 + 14) = 1343554297;
                if (v8 & 1)
                {
                    v10 = *((float*)v5 + 31) + *((float*)v5 + 31);
                    *((_DWORD*)v5 + 13) = 1065353216;
                    *((float*)v5 + 31) = v10;
                    *((float*)v5 + 32) = *((float*)v5 + 32) + *((float*)v5 + 32);
                }
                else
                {
                    *((_DWORD*)v5 + 13) = 1056964608;
                }
                v11 = (const char*) * ((_DWORD*)v5 + 1);
                if (!strcmp(*((const char**)v5 + 1), "Boulder")
                    || !strcmp(*((const char**)v5 + 1), "RollingBoulder")
                    || !strcmp(*((const char**)v5 + 1), "BoulderIndestructible"))
                {
                    *((_DWORD*)v5 + 13) = 1008981770;
                    *((_DWORD*)v5 + 14) = 1120403456;
                }
                if (!strcmp(v11, "Rock7"))
                    * ((_DWORD*)v5 + 14) = 1048576000;
                v12 = *((_DWORD*)v5 + 6);
                if (v12 & 2)
                {
                    v13 = (_DWORD*) * ((_DWORD*)v5 + 48);
                    v13[309] = -1;
                    v13[307] = -1;
                    v13[317] = -1;
                }
                else if (v12 & 0x200)
                {
                    v14 = (_DWORD*) * ((_DWORD*)v5 + 48);
                    v14[6] = -1;
                    v14[8] = -1;
                    v14[4] = -1;
                }
                else if (v12 & 0x800)
                {
                    *(_DWORD*)(*((_DWORD*)v5 + 36) + 4) = -1;
                }
                if (*((_DWORD*)v5 + 6) & 0x3000006)
                {
                    if (!*((_DWORD*)v5 + 34))
                    {
                        v15 = nox_calloc(1u, 0x14u);
                        *((_DWORD*)v5 + 34) = v15;
                        if (!v15)
                            return 0;
                    }
                }
                v16 = *((float*)v5 + 14) * 10.0;
                *((_DWORD*)v5 + 4) = 1;
                *((float*)v5 + 14) = v16;
                *(_DWORD*)& byte_5D4594[1563664] ^= sub_4E31A0((int)v5);
                *((_DWORD*)v5 + 55) = *(_DWORD*)& byte_5D4594[1563660];
                *(_DWORD*)& byte_5D4594[1563660] = v5;
                sub_4E3080(*((CHAR * *)v5 + 1));
                v3 = v21;
                break;
        }
    }
    *(_DWORD*)& byte_5D4594[2650664] = 1;
    if (*(_DWORD*)& byte_5D4594[260])
    {
        if (sub_40A5C0(2) && *(_DWORD*)& byte_5D4594[2649708])
        {
            sub_40ACA0_free_ptr2(*(LPVOID*)& byte_5D4594[260]);
            *(_DWORD*)& byte_5D4594[260] = 0;
        }
    }
    else
    {
        sub_40ACA0_free_ptr2(v2);
    }
    result = (void*)sub_4E3110();
    if (result)
    {
        sub_4E3C20();
        result = nox_malloc(4 * *(_DWORD*)& byte_587000[201384]);
        *(_DWORD*)& byte_5D4594[1563456] = result;
        if (result)
        {
            sub_4E3040();
            v17 = *(_DWORD*)& byte_587000[201384];
            v18 = *(_DWORD*)& byte_5D4594[1563660];
            v19 = 1;
            for (i = 1; i < *(int*)& byte_587000[201384]; ++i)
            {
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * (v17 - v19)) = v18;
                sub_4E30D0(v18);
                v17 = *(_DWORD*)& byte_587000[201384];
                v18 = *(_DWORD*)(v18 + 220);
                v19 = i + 1;
            }
            sub_4E29D0();
            free(v3);
            sub_4131A0();
            sub_415AB0();
            sub_4157C0();
            sub_4F0640();
            result = (void*)(sub_42BF10() != 0);
        }
    }
    return result;
}

//----- (004E3010) --------------------------------------------------------
int sub_4E3010()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[1563668], 0, 0x6Cu);
    memset(&byte_5D4594[1563776], 0, 0x6Cu);
    memset(&byte_5D4594[1563348], 0, 0x6Cu);
    return result;
}

//----- (004E3040) --------------------------------------------------------
size_t sub_4E3040()
{
    int i; // esi
    size_t result; // eax

    for (i = 0; i < 108; i += 4)
    {
        result = *(_DWORD*)& byte_5D4594[i + 1563668];
        if (result)
        {
            result = (size_t)nox_calloc(1u, 4 * result);
            *(_DWORD*)& byte_5D4594[i + 1563348] = result;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[i + 1563348] = 0;
        }
        *(_DWORD*)& byte_5D4594[i + 1563776] = 0;
    }
    return result;
}

//----- (004E3080) --------------------------------------------------------
CHAR* __cdecl sub_4E3080(CHAR* a1)
{
    CHAR* result; // eax

    result = a1;
    if (a1)
    {
        result = (CHAR*)sub_4E30A0(a1);
        if ((int)result >= 0)
            ++* (_DWORD*)& byte_5D4594[4 * (_DWORD)result + 1563668];
    }
    return result;
}

//----- (004E30A0) --------------------------------------------------------
int __cdecl sub_4E30A0(CHAR* a1)
{
    int result; // eax
    int v2; // eax

    if (!a1)
        return -1;
    v2 = toupper(*a1);
    if (v2 < 65 || v2 > 90)
        result = 26;
    else
        result = v2 - 65;
    return result;
}

//----- (004E30D0) --------------------------------------------------------
void __cdecl sub_4E30D0(int a1)
{
    int v1; // eax
    int v2; // ecx

    if (a1)
    {
        v1 = sub_4E30A0(*(CHAR * *)(a1 + 4));
        v2 = *(_DWORD*)& byte_5D4594[4 * v1 + 1563348];
        if (v2)
        {
            *(_DWORD*)(v2 + 4 * *(_DWORD*)& byte_5D4594[4 * v1 + 1563776]) = a1;
            ++* (_DWORD*)& byte_5D4594[4 * v1 + 1563776];
        }
    }
}

//----- (004E3110) --------------------------------------------------------
int sub_4E3110()
{
    int v0; // edi
    char* i; // esi
    int v2; // eax

    v0 = 1;
    for (i = (char*)sub_4E3B30(); i; i = (char*)sub_4E3B40((int)i))
    {
        if (!(i[32] & 0x40))
        {
            v2 = *((_DWORD*)i + 15);
            if (v2 != 2)
            {
                if (v2 != 3)
                    continue;
                sub_428270((shape*)(i + 60));
                if (*((float*)i + 24) - *((float*)i + 22) < 85.0 && *((float*)i + 27) - *((float*)i + 21) < 85.0)
                    continue;
                LABEL_9:
                v0 = 0;
                continue;
            }
            if (*((float*)i + 16) + *((float*)i + 16) >= 85.0)
                goto LABEL_9;
        }
    }
    return v0;
}

//----- (004E31A0) --------------------------------------------------------
int __cdecl sub_4E31A0(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // esi

    result = 0;
    if (a1)
    {
        LOWORD(result) = *(_WORD*)a1;
        v2 = result ^ *(_DWORD*)(a1 + 16);
        v3 = sub_4E31E0((_DWORD*)(a1 + 20)) ^ v2;
        result = sub_56FAE0(*(int**)(a1 + 4), strlen(*(const char**)(a1 + 4))) ^ v3;
    }
    return result;
}

//----- (004E31E0) --------------------------------------------------------
int __cdecl sub_4E31E0(_DWORD* a1)
{
    unsigned __int16* v1; // ecx
    int result; // eax

    v1 = (unsigned __int16*)a1[29];
    result = *(unsigned __int16*)a1 ^ a1[3] ^ a1[4] ^ a1[9];
    if (v1)
        result ^= *v1 ^ v1[2];
    return result;
}

//----- (004E3220) --------------------------------------------------------
int __cdecl sub_4E3220(int a1, char* a2, int a3)
{
    char* v3; // ebx
    unsigned __int8* v4; // eax
    char* v5; // edi
    unsigned __int8* v6; // ebp
    int v7; // eax
    char* v8; // eax
    unsigned __int8 v10; // [esp+18h] [ebp+8h]

    v3 = a2;
    while (1)
    {
        LABEL_2:
        v4 = *(unsigned __int8**)(a1 + 8);
        v10 = *v4;
        *(_DWORD*)(a1 + 8) = v4 + 1;
        if (!v10)
            return 1;
        sub_40ACC0(v3, 1u, v10, a1);
        v3[v10] = 0;
        v5 = strtok(v3, " \t\n\r");
        v6 = &byte_587000[201392];
        if (*(_DWORD*)& byte_587000[201396])
        {
            while (strcmp(v5, *(const char**)v6))
            {
                v7 = *((_DWORD*)v6 + 3);
                v6 += 8;
                if (!v7)
                    goto LABEL_2;
            }
            v8 = strtok(0, "=");
            if (v8)
                memmove(v3, v8 + 1, strlen(v8 + 1) + 1);
            if (!(*((int(__cdecl * *)(int, int, char*))v6 + 1))(a3, a1, v3))
                return 0;
        }
    }
}

//----- (004E3320) --------------------------------------------------------
void sub_4E3320()
{
    _DWORD* v0; // ecx
    int v1; // edx
    int v2; // esi

    v0 = *(_DWORD * *)& byte_5D4594[1563660];
    v1 = 0;
    if (*(_DWORD*)& byte_5D4594[1563660])
    {
        do
        {
            v2 = v0[37];
            if (v1 < v2 + v0[45] + v0[49] + v0[52])
                v1 = v2 + v0[45] + v0[49] + v0[52];
            v0 = (_DWORD*)v0[55];
        } while (v0);
    }
}

//----- (004E3360) --------------------------------------------------------
int __cdecl sub_4E3360(unsigned int a1)
{
    _DWORD* v1; // esi
    int v2; // edi
    int result; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // edi
    int v6; // ebx
    _QWORD* v7; // eax

    v1 = 0;
    v2 = 1;
    result = nox_new_alloc_class("objectMemClass", 772, a1);
    *(_DWORD*)& byte_5D4594[1563344] = result;
    if (result)
    {
        if (a1)
        {
            while (1)
            {
                v4 = nox_alloc_class_new_obj_zero((_DWORD*)result);
                if (!v4)
                    break;
                v4[9] = v2++;
                v4[111] = v1;
                v1 = v4;
                if (v2 - 1 >= a1)
                {
                    do
                    {
                        v5 = v1;
                        v1 = (_DWORD*)v1[111];
                        v6 = v5[9];
                        sub_414330(*(unsigned int**)& byte_5D4594[1563344], v5);
                        v5[9] = v6;
                    } while (v1);
                    result = *(_DWORD*)& byte_5D4594[1563344];
                    goto LABEL_9;
                }
                result = *(_DWORD*)& byte_5D4594[1563344];
            }
            while (v1)
            {
                v7 = v1;
                v1 = (_DWORD*)v1[111];
                sub_414330(*(unsigned int**)& byte_5D4594[1563344], v7);
            }
            result = 0;
        }
        else
        {
            LABEL_9:
            sub_4144B0(result);
            result = 1;
        }
    }
    return result;
}

//----- (004E3420) --------------------------------------------------------
int sub_4E3420()
{
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1563344]);
    return 1;
}

//----- (004E3450) --------------------------------------------------------
_DWORD* __cdecl sub_4E3450(int a1)
{
    return sub_4E3470(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * a1));
}

//----- (004E3470) --------------------------------------------------------
_DWORD* __cdecl sub_4E3470(int a1)
{
    _DWORD* result; // eax
    _DWORD* v2; // ebx
    char v3; // al
    int v4; // edx
    void* v5; // eax
    void(__cdecl * v6)(_DWORD*); // ebp
    int v7; // eax
    int v8; // eax
    int v9; // [esp+10h] [ebp-4h]

    result = (_DWORD*)nox_alloc_class_new_obj(*(_DWORD * *)& byte_5D4594[1563344]);
    v2 = result;
    if (result)
    {
        v9 = result[9];
        memset(result, 0, 0x304u);
        *((_WORD*)result + 2) = *(_WORD*)(a1 + 20);
        result[2] = *(_DWORD*)(a1 + 24);
        result[3] = *(_DWORD*)(a1 + 28);
        result[4] = *(_DWORD*)(a1 + 32);
        result[5] = *(_DWORD*)(a1 + 36);
        *((_WORD*)result + 12) = *(_WORD*)(a1 + 40);
        result[7] = *(_DWORD*)(a1 + 44);
        result[8] = *(_DWORD*)(a1 + 48);
        v3 = *((_BYTE*)result + 16);
        v2[28] = *(_DWORD*)(a1 + 52);
        v2[30] = *(_DWORD*)(a1 + 56);
        qmemcpy(v2 + 43, (const void*)(a1 + 60), 0x3Cu);
        if (!(v3 & 0x40))
            sub_4E7290((int)v2);
        *((_BYTE*)v2 + 488) = *(_BYTE*)(a1 + 120);
        *((_WORD*)v2 + 245) = *(_WORD*)(a1 + 122);
        v2[136] = *(_DWORD*)(a1 + 124);
        v2[137] = *(_DWORD*)(a1 + 128);
        v2[138] = *(_DWORD*)(a1 + 132);
        v2[139] = *(_DWORD*)(a1 + 136);
        v2[38] = -1;
        *((_WORD*)v2 + 2) = *(_WORD*)a1;
        if (*(_DWORD*)(a1 + 136))
        {
            result = nox_calloc(1u, 0x14u);
            v2[139] = result;
            if (!result)
                return result;
            qmemcpy(result, *(const void**)(a1 + 136), 0x14u);
        }
        v2[172] = *(_DWORD*)(a1 + 172);
        if (*(_DWORD*)(a1 + 180))
        {
            result = nox_calloc(1u, *(_DWORD*)(a1 + 180));
            v2[173] = result;
            if (!result)
                return result;
            qmemcpy(result, *(const void**)(a1 + 176), *(_DWORD*)(a1 + 180));
        }
        v2[174] = *(_DWORD*)(a1 + 140);
        if (*(_DWORD*)(a1 + 148))
        {
            result = nox_calloc(1u, *(_DWORD*)(a1 + 148));
            v2[175] = result;
            if (!result)
                return result;
            qmemcpy(result, *(const void**)(a1 + 144), *(_DWORD*)(a1 + 148));
        }
        v2[176] = *(_DWORD*)(a1 + 212);
        v2[183] = *(_DWORD*)(a1 + 200);
        if (*(_DWORD*)(a1 + 208))
        {
            result = nox_calloc(1u, *(_DWORD*)(a1 + 208));
            v2[184] = result;
            if (!result)
                return result;
            qmemcpy(result, *(const void**)(a1 + 204), *(_DWORD*)(a1 + 208));
        }
        v2[186] = *(_DWORD*)(a1 + 188);
        if (*(_DWORD*)(a1 + 196))
        {
            result = nox_calloc(1u, *(_DWORD*)(a1 + 196));
            v2[187] = result;
            if (!result)
                return result;
            qmemcpy(result, *(const void**)(a1 + 192), *(_DWORD*)(a1 + 196));
        }
        v2[177] = *(_DWORD*)(a1 + 184);
        v2[178] = *(_DWORD*)(a1 + 168);
        v2[179] = *(_DWORD*)(a1 + 152);
        v2[180] = *(_DWORD*)(a1 + 156);
        v2[181] = *(_DWORD*)(a1 + 160);
        v4 = *(_DWORD*)(a1 + 164);
        v2[190] = 0;
        v2[182] = v4;
        v2[192] = -1;
        v2[9] = v9;
        if (sub_40A5C0(6291456)
            && (v2[2] & 0x20A02 || (int(__cdecl*)(int*))v2[176] == sub_4F5AA0 || *((char*)v2 + 488) != -1)
            && (v5 = nox_calloc(1u, 0xA0Cu), (v2[189] = v5) == 0))
        {
            sub_4E38A0((int)v2);
            result = 0;
        }
        else
        {
            v6 = *(void(__cdecl * *)(_DWORD*))(a1 + 216);
            if (v6)
                v6(v2);
            if (!sub_40A5C0(0x200000))
                v2[11] = (*(_DWORD*)& byte_587000[201376])++;
            v7 = v2[2];
            if (v7 & 0x100000)
            {
                ++* (_DWORD*)& byte_5D4594[1563888];
            }
            else if (v7 & 0x400000)
            {
                ++* (_DWORD*)& byte_5D4594[1563892];
            }
            v8 = *(_DWORD*)& byte_5D4594[1563900] + 1;
            ++* (_DWORD*)& byte_5D4594[1563884];
            if (++ * (_DWORD*)& byte_5D4594[1563900] > * (int*)& byte_5D4594[1563896])
                * (_DWORD*)& byte_5D4594[1563896] = v8;
            result = v2;
        }
    }
    return result;
}

//----- (004E3810) --------------------------------------------------------
_DWORD* __cdecl sub_4E3810(CHAR* a1)
{
    int v1; // eax
    _DWORD* result; // eax

    v1 = sub_4E3830(a1);
    if (v1)
        result = sub_4E3470(v1);
    else
        result = 0;
    return result;
}

//----- (004E3830) --------------------------------------------------------
int __cdecl sub_4E3830(CHAR* a1)
{
    int v1; // eax
    signed int v2; // ecx
    const void* v3; // eax
    int* v4; // eax
    int result; // eax

    if (a1
        && (v1 = sub_4E30A0(a1), v1 >= 0)
        && (v2 = *(_DWORD*)& byte_5D4594[4 * v1 + 1563668], v2 >= 0)
        && (v3 = *(const void**)& byte_5D4594[4 * v1 + 1563348]) != 0
        && (v4 = (int*)bsearch(a1, v3, v2, 4u, sub_4E3880)) != 0)
    {
        result = *v4;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004E3880) --------------------------------------------------------
int __cdecl sub_4E3880(const void* a1, const void* a2)
{
    return _strcmpi((const char*)a1, *(const char**)(*(_DWORD*)a2 + 4));
}

//----- (004E38A0) --------------------------------------------------------
int __cdecl sub_4E38A0(int a1)
{
    int* v1; // esi
    int v2; // ebp
    int v3; // edi
    int v4; // eax
    int v5; // esi
    int v6; // esi

    if (*(_DWORD*)(a1 + 8) & 0x20000)
    {
        v1 = *(int**)(a1 + 748);
        v2 = 3;
        do
        {
            v3 = 4;
            do
            {
                if (*v1)
                    sub_4E38A0(*v1);
                ++v1;
                --v3;
            } while (v3);
            --v2;
        } while (v2);
    }
    if (!sub_40A5C0(0x200000))
    {
        v4 = *(_DWORD*)(a1 + 504);
        if (v4)
        {
            do
            {
                v5 = *(_DWORD*)(v4 + 496);
                sub_4E38A0(v4);
                v4 = v5;
            } while (v5);
        }
    }
    if (*(_DWORD*)a1)
        free(*(LPVOID*)a1);
    if (*(_DWORD*)(a1 + 556))
        free(*(LPVOID*)(a1 + 556));
    if (*(_DWORD*)(a1 + 760))
        free(*(LPVOID*)(a1 + 760));
    if (*(_DWORD*)(a1 + 756))
        free(*(LPVOID*)(a1 + 756));
    if (*(_DWORD*)(a1 + 692))
        free(*(LPVOID*)(a1 + 692));
    if (*(_DWORD*)(a1 + 700))
        free(*(LPVOID*)(a1 + 700));
    if (*(_DWORD*)(a1 + 736))
        free(*(LPVOID*)(a1 + 736));
    if (*(_DWORD*)(a1 + 748))
        free(*(LPVOID*)(a1 + 748));
    v6 = *(_DWORD*)(a1 + 36);
    sub_414400(*(unsigned int**)& byte_5D4594[1563344], (_QWORD*)a1);
    *(_DWORD*)(a1 + 36) = v6;
    return -- * (_DWORD*)& byte_5D4594[1563900];
}

//----- (004E39D0) --------------------------------------------------------
int __cdecl sub_4E39D0(int a1)
{
    return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * *(unsigned __int16*)(a1 + 4)) + 4);
}

//----- (004E39F0) --------------------------------------------------------
wchar_t* __cdecl sub_4E39F0(const char** a1)
{
    const char* v1; // esi
    char* v2; // eax
    const char* v3; // eax
    const char* v4; // edx
    unsigned __int8 v5; // al
    unsigned __int8* v6; // ecx
    unsigned __int8* i; // edx

    v1 = *a1;
    if (!*a1)
        v1 = (const char*)sub_4E39D0((int)a1);
    v2 = strrchr(v1, 58);
    if (v2)
        v3 = v2 + 1;
    else
        v3 = v1;
    v4 = v3;
    strcpy((char*)& byte_5D4594[1563460], "NPC:");
    v5 = *v3;
    v6 = &byte_5D4594[strlen((const char*)& byte_5D4594[1563460]) + 1563460];
    for (i = (unsigned __int8*)(v4 + 1); v5; ++i)
    {
        if (v5 != 95)
            * v6++ = v5;
        v5 = *i;
    }
    *v6 = 0;
    return loadString_sub_40F1D0((char*)& byte_5D4594[1563460], 0, "C:\\NoxPost\\src\\Server\\DBase\\objdb.c", 1577);
}

//----- (004E3A80) --------------------------------------------------------
int __cdecl sub_4E3A80(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * a1) + 4);
    return result;
}

//----- (004E3AA0) --------------------------------------------------------
int __cdecl sub_4E3AA0(CHAR* a1)
{
    unsigned __int16* v1; // eax
    int result; // eax

    v1 = (unsigned __int16*)sub_4E3830(a1);
    if (v1)
        result = *v1;
    else
        result = 0;
    return result;
}

//----- (004E3AC0) --------------------------------------------------------
int sub_4E3AC0()
{
    return *(_DWORD*)& byte_587000[201384];
}

//----- (004E3AD0) --------------------------------------------------------
BOOL __cdecl sub_4E3AD0(int a1)
{
    int v1; // ecx
    int v2; // eax
    int v3; // ecx
    BOOL result; // eax

    if (!*(_DWORD*)& byte_5D4594[1563904])
        * (_DWORD*)& byte_5D4594[1563904] = sub_4E3AA0((CHAR*)& byte_587000[202016]);
    v1 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * a1);
    v2 = *(_DWORD*)(v1 + 24);
    result = 1;
    if (!(v2 & 1))
    {
        if (v2 & 0x400000)
        {
            if (!(0x800000 & v2))
            {
                v3 = *(_DWORD*)(v1 + 32);
                if (v3 & 0x40)
                {
                    if (!(v3 & 0x10000))
                        result = 0;
                }
            }
        }
    }
    return result;
}

//----- (004E3B30) --------------------------------------------------------
LPVOID sub_4E3B30()
{
    return *(LPVOID*)& byte_5D4594[1563660];
}

//----- (004E3B40) --------------------------------------------------------
int __cdecl sub_4E3B40(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 220);
    else
        result = 0;
    return result;
}

//----- (004E3B60) --------------------------------------------------------
int __cdecl sub_4E3B60(CHAR* a1)
{
    return sub_4E3830(a1);
}

//----- (004E3B70) --------------------------------------------------------
int __cdecl sub_4E3B70(int a1)
{
    return *(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * a1);
}

//----- (004E3B80) --------------------------------------------------------
BOOL __cdecl sub_4E3B80(int a1)
{
    return *(int*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * a1) + 12) != -1;
}

//----- (004E3BA0) --------------------------------------------------------
int __cdecl sub_4E3BA0(int a1)
{
    return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1563456] + 4 * a1) + 16);
}

//----- (004E3BC0) --------------------------------------------------------
int __cdecl sub_4E3BC0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563664] ^= *(_DWORD*)(a1 + 16);
    *(_DWORD*)(a1 + 16) = 0;
    return result;
}

//----- (004E3BF0) --------------------------------------------------------
int __cdecl sub_4E3BF0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1563664] ^= *(_DWORD*)(a1 + 16);
    *(_DWORD*)(a1 + 16) = 1;
    *(_DWORD*)& byte_5D4594[1563664] ^= 1u;
    return result;
}

//----- (004E3C20) --------------------------------------------------------
int sub_4E3C20()
{
    int v0; // edi
    LPVOID i; // esi
    int result; // eax

    v0 = 0;
    for (i = sub_4E3B30(); i; i = (LPVOID)sub_4E3B40((int)i))
        v0 ^= sub_4E31A0((int)i);
    result = *(_DWORD*)& byte_5D4594[1563664];
    if (v0 != *(_DWORD*)& byte_5D4594[1563664])
        nullsub_31(1);
    return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (004E3C60) --------------------------------------------------------
int __cdecl sub_4E3C60(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[201380] = a1;
    return result;
}

//----- (004E3C70) --------------------------------------------------------
int sub_4E3C70()
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[201380];
    *(_DWORD*)& byte_587000[201376] = 1000000000;
    if (*(_DWORD*)& byte_587000[201380])
        * (_DWORD*)& byte_587000[201376] = *(_DWORD*)& byte_587000[201380];
    return result;
}

//----- (004E3C90) --------------------------------------------------------
void sub_4E3C90()
{
    nox_srand(0x899u);
}

//----- (004E3CA0) --------------------------------------------------------
double sub_4E3CA0()
{
    return *(float*)& byte_587000[202024];
}

//----- (004E3CB0) --------------------------------------------------------
int __cdecl sub_4E3CB0(float a1)
{
    int result; // eax

    result = LODWORD(a1);
    *(float*)& byte_587000[202024] = a1;
    return result;
}

//----- (004E3CC0) --------------------------------------------------------
int sub_4E3CC0()
{
    return *(_DWORD*)& byte_587000[202028];
}

//----- (004E3CD0) --------------------------------------------------------
int __cdecl sub_4E3CD0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[202028] = a1;
    return result;
}

//----- (004E3CE0) --------------------------------------------------------
int sub_4E3CE0()
{
    int v0; // ebp
    int v1; // esi
    int v2; // edi

    v0 = 0;
    v1 = sub_4DA7C0();
    if (!v1)
        return 0;
    do
    {
        v2 = *(_DWORD*)(v1 + 748);
        if ((!sub_40A5C0(1)
             || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
             || *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064) != 31)
            && *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4792) == 1)
        {
            ++v0;
        }
        v1 = sub_4DA7F0(v1);
    } while (v1);
    return v0;
}

//----- (004E3D50) --------------------------------------------------------
int sub_4E3D50()
{
    int v0; // esi
    float v2; // [esp+0h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1563928])
    {
        *(float*)& byte_5D4594[1563912] = sub_419D40(&byte_587000[202040]);
        *(_DWORD*)& byte_5D4594[1563928] = 1;
    }
    v0 = sub_4E3CE0();
    v2 = (double)(unsigned int)sub_4E3CC0() * ((double)(v0 - 1) * *(float*)& byte_5D4594[1563912] + 1.0);
    return sub_4E3CB0(v2);
}

//----- (004E3DD0) --------------------------------------------------------
__int16 sub_4E3DD0()
{
    int v0; // eax
    int v1; // esi
    int v2; // ebx
    int v3; // ecx
    __int16 v4; // cx
    int v5; // edi
    unsigned __int16 v6; // bp
    unsigned __int16 v7; // ax
    __int16 v8; // cx
    int v9; // ebp
    int v10; // ecx
    __int16 v11; // di
    __int16 v12; // ax
    int v13; // ecx
    float v15; // [esp+0h] [ebp-1Ch]
    float v16; // [esp+0h] [ebp-1Ch]
    float v17; // [esp+0h] [ebp-1Ch]
    float v18; // [esp+0h] [ebp-1Ch]
    float v19; // [esp+Ch] [ebp-10h]
    float v20; // [esp+Ch] [ebp-10h]
    float v21; // [esp+10h] [ebp-Ch]
    float v22; // [esp+14h] [ebp-8h]
    unsigned __int16 v23; // [esp+18h] [ebp-4h]

    v21 = sub_419D40(&byte_587000[202064]);
    v23 = sub_419A70(v21);
    if (!*(_DWORD*)& byte_5D4594[1563932])
    {
        *(float*)& byte_5D4594[1563908] = sub_419D40(&byte_587000[202084]);
        *(float*)& byte_5D4594[1563916] = sub_419D40(&byte_587000[202108]);
        *(float*)& byte_5D4594[1563920] = sub_419D40(&byte_587000[202132]);
        *(float*)& byte_5D4594[1563924] = sub_419D40(&byte_587000[202156]);
        *(_DWORD*)& byte_5D4594[1563932] = 1;
    }
    v19 = (sub_4E3CA0() - 1.0) * *(float*)& byte_5D4594[1563920] + *(float*)& byte_5D4594[1563908];
    sub_4E4080(v19);
    v20 = (sub_4E3CA0() - 1.0) * *(float*)& byte_5D4594[1563924] + *(float*)& byte_5D4594[1563916];
    sub_4E40C0(v20);
    v0 = sub_4DA790();
    v1 = v0;
    if (v0)
    {
        do
        {
            v2 = sub_4DA7A0(v1);
            v0 = *(_DWORD*)(v1 + 8);
            if (v0 & 0x20000 && (v3 = *(_DWORD*)(v1 + 16), (v3 & 0x8000) == 0))
            {
                v0 = *(_DWORD*)(v1 + 556);
                v4 = *(_WORD*)(v0 + 4);
                if (v4)
                {
                    LOWORD(v0) = *(_WORD*)v0;
                    if ((_WORD)v0)
                    {
                        if ((_WORD)v0 == v4)
                        {
                            v5 = sub_4E3B70(*(unsigned __int16*)(v1 + 4));
                            v15 = sub_4E40F0() * (double) * (unsigned __int16*)(*(_DWORD*)(v5 + 136) + 4);
                            v6 = sub_419AB0(v15);
                            v16 = sub_4E40F0() * (double) * *(unsigned __int16**)(v5 + 136);
                            v7 = sub_419AB0(v16);
                            if (!v7)
                                v7 = 1;
                            if (!v6)
                                v6 = 1;
                            if (v7 > v23)
                                v7 = v23;
                            if (v6 > v23)
                                v6 = v23;
                            LOWORD(v0) = sub_4E4560(v1, v7);
                            *(_WORD*)(*(_DWORD*)(v1 + 556) + 4) = v6;
                        }
                    }
                }
            }
            else if (v0 & 2)
            {
                v0 = *(_DWORD*)(v1 + 16);
                if ((v0 & 0x8000) == 0)
                {
                    v0 = *(_DWORD*)(v1 + 556);
                    v8 = *(_WORD*)(v0 + 4);
                    if (v8)
                    {
                        LOWORD(v0) = *(_WORD*)v0;
                        if ((_WORD)v0)
                        {
                            if ((_WORD)v0 == v8)
                            {
                                v0 = sub_4E3B70(*(unsigned __int16*)(v1 + 4));
                                v9 = *(_DWORD*)(v1 + 748);
                                v10 = *(_DWORD*)(v9 + 484);
                                LOWORD(v0) = v10 ? *(_WORD*)(v10 + 72) : *(_WORD*)(*(_DWORD*)(v0 + 136) + 4);
                                if ((signed char) * (_BYTE*)(v9 + 1440) >= 0)
                                {
                                    v22 = (double)(unsigned __int16)v0;
                                    v17 = sub_4E40F0() * v22;
                                    v11 = sub_419AB0(v17);
                                    v18 = sub_4E40F0() * v22;
                                    v12 = sub_419AB0(v18);
                                    if (!v12)
                                        v12 = 1;
                                    if (!v11)
                                        v11 = 1;
                                    sub_4E4560(v1, v12);
                                    v0 = v9 + 412;
                                    v13 = 32;
                                    *(_WORD*)(*(_DWORD*)(v1 + 556) + 4) = v11;
                                    do
                                    {
                                        v0 += 2;
                                        --v13;
                                        *(_WORD*)(v0 - 2) = **(_WORD * *)(v1 + 556);
                                    } while (v13);
                                }
                            }
                        }
                    }
                }
            }
            v1 = v2;
        } while (v2);
    }
    return v0;
}

//----- (004E4080) --------------------------------------------------------
void __cdecl sub_4E4080(float a1)
{
    double v1; // st7

    v1 = sub_419D40(&byte_587000[202180]);
    if (a1 <= v1)
        * (float*)& byte_587000[202032] = a1;
    else
        *(float*)& byte_587000[202032] = v1;
}

//----- (004E40B0) --------------------------------------------------------
double sub_4E40B0()
{
    return *(float*)& byte_587000[202032];
}

//----- (004E40C0) --------------------------------------------------------
void __cdecl sub_4E40C0(float a1)
{
    double v1; // st7

    v1 = sub_419D40(&byte_587000[202196]);
    if (a1 <= v1)
        * (float*)& byte_587000[202036] = a1;
    else
        *(float*)& byte_587000[202036] = v1;
}

//----- (004E40F0) --------------------------------------------------------
double sub_4E40F0()
{
    return *(float*)& byte_587000[202036];
}

//----- (004E4100) --------------------------------------------------------
int sub_4E4100()
{
    unsigned int v0; // ebp
    int v1; // esi
    int v2; // edi
    int result; // eax

    v0 = 0;
    v1 = sub_4DA7C0();
    if (!v1)
        return 1;
    do
    {
        v2 = *(_DWORD*)(v1 + 748);
        if (!sub_40A5C0(1)
            || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
            || *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064) != 31)
        {
            if (*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4792))
                ++v0;
        }
        result = sub_4DA7F0(v1);
        v1 = result;
    } while (result);
    if (v0 < 6)
        return 1;
    return result;
}

//----- (004E4170) --------------------------------------------------------
void sub_4E4170()
{
    float v0; // [esp+0h] [ebp-4h]

    if (!(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)(5 * *(_DWORD*)& byte_5D4594[2649704])))
    {
        v0 = sub_4E3CA0();
        sub_4E3D50();
        if (sub_4E3CA0() != v0)
            sub_4E3DD0();
    }
}

//----- (004E41B0) --------------------------------------------------------
int __cdecl sub_4E41B0(char* a1)
{
    FILE* v1; // edi

    v1 = fopen(a1, "r");
    if (v1)
    {
        do
        {
            while (1)
            {
                do
                {
                    if (!fgets((char*)& byte_5D4594[1563936], 1024, v1))
                    {
                        fclose(v1);
                        return 1;
                    }
                } while (!strtok((char*)& byte_5D4594[1563936], "\r\t\n"));
                if (strcmp((const char*)& byte_5D4594[1563936], "[Banned Users]"))
                    break;
                if (!sub_4E42C0(v1))
                    goto LABEL_11;
            }
        } while (strcmp((const char*)& byte_5D4594[1563936], "[Allowed Users]") || sub_4E4390(v1));
        LABEL_11:
        fclose(v1);
    }
    return 0;
}

//----- (004E42C0) --------------------------------------------------------
int __cdecl sub_4E42C0(FILE* a1)
{
    char* v1; // eax
    char* v2; // eax
    wchar_t v4[26]; // [esp+Ch] [ebp-34h]

    while (1)
    {
        if (!fgets((char*)& byte_5D4594[1563936], 1024, a1))
            return 1;
        v1 = strtok((char*)& byte_5D4594[1563936], "\r\t\n");
        if (!v1)
            return 1;
        nox_swprintf(v4, L"%S", v1);
        if (!fgets((char*)& byte_5D4594[1563936], 1024, a1))
            return 1;
        v2 = strtok((char*)& byte_5D4594[1563936], "\r\t\n");
        if (!v2)
            break;
        if (!strcmp(v2, "0"))
            sub_416770(0, v4, 0);
        else
            sub_416770(0, v4, v2);
    }
    return 0;
}

//----- (004E4390) --------------------------------------------------------
int __cdecl sub_4E4390(FILE* a1)
{
    char* v1; // eax
    wchar_t v3[26]; // [esp+4h] [ebp-34h]

    while (fgets((char*)& byte_5D4594[1563936], 1024, a1))
    {
        v1 = strtok((char*)& byte_5D4594[1563936], "\r\t\n");
        if (!v1)
            break;
        nox_swprintf(v3, L"%S", v1);
        sub_4168A0(v3);
    }
    return 1;
}

//----- (004E43F0) --------------------------------------------------------
FILE* __cdecl sub_4E43F0(char* a1)
{
    FILE* result; // eax
    FILE* v2; // edi
    int* i; // esi
    int* j; // esi

    result = fopen(a1, "w");
    v2 = result;
    if (result)
    {
        fprintf(result, "%s\n", &byte_587000[202212]);
        for (i = sub_416900(); i; i = sub_416910(i))
        {
            if (!*((_QWORD*)i + 8))
            {
                fprintf(v2, "%S\n", i + 3);
                if (*((_BYTE*)i + 72))
                    fprintf(v2, "%s\n", i + 18);
                else
                    fprintf(v2, "0\n");
            }
        }
        fprintf(v2, "\n%s\n", &byte_587000[202228]);
        for (j = sub_4168E0(); j; j = sub_4168F0(j))
            fprintf(v2, "%S\n", j + 3);
        fclose(v2);
        result = (FILE*)1;
    }
    return result;
}

//----- (004E44D0) --------------------------------------------------------
void sub_4E44D0()
{
    nox_srand(0x1428u);
}

//----- (004E44E0) --------------------------------------------------------
int __cdecl sub_4E44E0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 152) = 0;
    return result;
}

//----- (004E44F0) --------------------------------------------------------
int __cdecl sub_4E44F0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 152) = -1;
    return result;
}

//----- (004E4500) --------------------------------------------------------
int* __cdecl sub_4E4500(int a1, int a2, int a3, int a4)
{
    int v4; // ecx
    int* result; // eax
    int v6; // edx

    v4 = 0;
    result = (int*)(a1 + 560);
    do
    {
        if (a4)
            * result |= a3;
        else
            *result &= ~a3;
        v6 = *result;
        if ((1 << v4) & *(_DWORD*)(a1 + 148))
        {
            *result = a2 | v6;
        }
        else if (!(v6 & a3))
        {
            *result = v6 & ~a2;
        }
        ++v4;
        ++result;
    } while (v4 < 32);
    return result;
}

//----- (004E4560) --------------------------------------------------------
int __cdecl sub_4E4560(int a1, unsigned __int16 a2)
{
    int result; // eax
    int v3; // eax
    int v4; // eax
    int* v5; // eax
    int v6; // ecx
    int v7; // edx
    int v8; // eax

    result = *(_DWORD*)(a1 + 556);
    if (result)
    {
        sub_4E44F0(a1);
        v3 = *(_DWORD*)(a1 + 492);
        if (v3 && *(_BYTE*)(v3 + 8) & 4)
            sub_56FC50(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 4632), (int*)a1);
        **(_WORD * *)(a1 + 556) = a2;
        if (*(_BYTE*)(a1 + 8) & 4)
            sub_56F870(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 4584), a2);
        v4 = *(_DWORD*)(a1 + 8);
        if (v4 & 2 && (*(_BYTE*)(a1 + 12) & 0x80))
        {
            if (v4 & 0x20400004)
            {
                v5 = (int*)(a1 + 560);
                v6 = 32;
                do
                {
                    v7 = *v5;
                    ++v5;
                    --v6;
                    *(v5 - 1) = v7 & 0xFFFFF000 | 0x20000;
                } while (v6);
            }
            else
            {
                sub_4E3B70(*(unsigned __int16*)(a1 + 4));
                v8 = sub_4E4C90(a1, 2u);
                sub_4E4500(a1, 0x20000, 2, v8);
            }
        }
        result = *(_DWORD*)(a1 + 492);
        if (result)
        {
            if (*(_BYTE*)(result + 8) & 4)
                result = sub_56FBF0(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(result + 748) + 276) + 4632), (int*)a1);
        }
    }
    return result;
}

//----- (004E4670) --------------------------------------------------------
int* __cdecl sub_4E4670(int a1, int a2)
{
    int v2; // eax
    unsigned int v3; // eax
    int* result; // eax
    int v5; // ecx
    int v6; // edx
    int v7; // eax

    sub_4E44F0(a1);
    v2 = *(_DWORD*)(a1 + 16);
    if (a2)
        v3 = v2 | 0x1000000;
    else
        v3 = v2 & 0xFEFFFFFF;
    *(_DWORD*)(a1 + 16) = v3;
    if (*(_DWORD*)(a1 + 8) & 0x20400004)
    {
        result = (int*)(a1 + 560);
        v5 = 32;
        do
        {
            v6 = *result;
            ++result;
            --v5;
            *(result - 1) = v6 & 0xFFFFF000 | 0x40000;
        } while (v5);
    }
    else
    {
        sub_4E3B70(*(unsigned __int16*)(a1 + 4));
        v7 = sub_4E4C90(a1, 4u);
        result = sub_4E4500(a1, 0x40000, 4, v7);
    }
    return result;
}

//----- (004E46F0) --------------------------------------------------------
void __cdecl sub_4E46F0(int a1, float a2)
{
    int* v2; // eax
    int v3; // ecx
    int v4; // edx
    int v5; // eax

    if (*(float*)(a1 + 104) != a2)
    {
        sub_4E44F0(a1);
        *(float*)(a1 + 104) = a2;
        if (*(_DWORD*)(a1 + 8) & 0x20400004)
        {
            v2 = (int*)(a1 + 560);
            v3 = 32;
            do
            {
                v4 = *v2;
                ++v2;
                --v3;
                *(v2 - 1) = v4 & 0xFFFFF000 | 0x400000;
            } while (v3);
        }
        else
        {
            sub_4E3B70(*(unsigned __int16*)(a1 + 4));
            v5 = sub_4E4C90(a1, 0x40u);
            sub_4E4500(a1, 0x400000, 64, v5);
        }
    }
}

//----- (004E4780) --------------------------------------------------------
int* __cdecl sub_4E4780(int a1, int a2)
{
    int* result; // eax
    int v3; // ecx
    int v4; // edx
    int v5; // eax

    result = *(int**)(a1 + 20);
    if ((unsigned int)result & a2)
    {
        *(_DWORD*)(a1 + 20) = (unsigned int)result & ~a2;
        if (a2 != 1)
        {
            sub_4E44F0(a1);
            if (*(_DWORD*)(a1 + 8) & 0x20400004)
            {
                result = (int*)(a1 + 560);
                v3 = 32;
                do
                {
                    v4 = *result;
                    ++result;
                    --v3;
                    *(result - 1) = v4 & 0xFFFFF000 | 0x80000;
                } while (v3);
            }
            else
            {
                sub_4E3B70(*(unsigned __int16*)(a1 + 4));
                v5 = sub_4E4C90(a1, 8u);
                result = sub_4E4500(a1, 0x80000, 8, v5);
            }
        }
    }
    return result;
}

//----- (004E4800) --------------------------------------------------------
int* __cdecl sub_4E4800(int a1, int* a2)
{
    int* result; // eax
    int v3; // ecx
    int v4; // edx
    int v5; // eax

    result = a2;
    *(_DWORD*)(a1 + 20) |= (unsigned int)a2;
    if (a2 != (int*)1)
    {
        sub_4E44F0(a1);
        if (*(_DWORD*)(a1 + 8) & 0x20400004)
        {
            result = (int*)(a1 + 560);
            v3 = 32;
            do
            {
                v4 = *result;
                ++result;
                --v3;
                *(result - 1) = v4 & 0xFFFFF000 | 0x80000;
            } while (v3);
        }
        else
        {
            sub_4E3B70(*(unsigned __int16*)(a1 + 4));
            v5 = sub_4E4C90(a1, 8u);
            result = sub_4E4500(a1, 0x80000, 8, v5);
        }
    }
    return result;
}

//----- (004E4880) --------------------------------------------------------
int* __cdecl sub_4E4880(int a1, int a2)
{
    int* result; // eax
    int v3; // ecx
    int v4; // edx
    int v5; // eax

    sub_4E44F0(a1);
    *(_DWORD*)(a1 + 132) = a2;
    if (*(_DWORD*)(a1 + 8) & 0x20400004)
    {
        result = (int*)(a1 + 560);
        v3 = 32;
        do
        {
            v4 = *result;
            ++result;
            --v3;
            *(result - 1) = v4 & 0xFFFFF000 | 0x10000;
        } while (v3);
    }
    else
    {
        sub_4E3B70(*(unsigned __int16*)(a1 + 4));
        v5 = sub_4E4C90(a1, 1u);
        result = sub_4E4500(a1, 0x10000, 1, v5);
    }
    return result;
}

//----- (004E48F0) --------------------------------------------------------
int* __cdecl sub_4E48F0(int a1, int a2)
{
    char v2; // cl
    int* result; // eax
    int v4; // ecx
    int v5; // edx
    int v6; // eax

    sub_4E44F0(a1);
    v2 = *(_BYTE*)(a1 + 8);
    *(_DWORD*)(a1 + 340) = a2;
    if (v2 & 4)
        sub_56F7D0(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 4612), a2);
    if (*(_DWORD*)(a1 + 8) & 0x20400004)
    {
        result = (int*)(a1 + 560);
        v4 = 32;
        do
        {
            v5 = *result;
            ++result;
            --v4;
            *(result - 1) = 0x800000 | v5 & 0xFFFFF000;
        } while (v4);
    }
    else
    {
        sub_4E3B70(*(unsigned __int16*)(a1 + 4));
        v6 = sub_4E4C90(a1, 0x80u);
        result = sub_4E4500(a1, 0x800000, 128, v6);
    }
    return result;
}

//----- (004E4990) --------------------------------------------------------
int* __cdecl sub_4E4990(int a1, int* a2)
{
    int v2; // eax
    int v3; // edx
    int* result; // eax
    int v5; // ecx
    int v6; // ecx
    int v7; // edx
    int v8; // eax

    v2 = *(_DWORD*)(a1 + 8);
    if (v2 & 0x1000 && *(_DWORD*)(a1 + 12) & 0x47F0000)
        goto LABEL_19;
    v3 = 0;
    result = a2;
    v5 = 4;
    do
    {
        if (*result)
            v3 = 1;
        ++result;
        --v5;
    } while (v5);
    if (v3)
    {
        LABEL_19:
        result = *(int**)& byte_5D4594[1564960];
        if (!*(_DWORD*)& byte_5D4594[1564960])
        {
            result = (int*)sub_4E3AA0((CHAR*)& byte_587000[202316]);
            *(_DWORD*)& byte_5D4594[1564960] = result;
        }
        if (*(_DWORD*)(a1 + 8) & 0x13001000 || (int*) * (unsigned __int16*)(a1 + 4) == result)
        {
            sub_4E44F0(a1);
            qmemcpy(*(void**)(a1 + 692), a2, 0x14u);
            if (*(_DWORD*)(a1 + 8) & 0x20400004)
            {
                result = (int*)(a1 + 560);
                v6 = 32;
                do
                {
                    v7 = *result;
                    ++result;
                    --v6;
                    *(result - 1) = v7 & 0xFFFFF000 | 0x2000000;
                } while (v6);
            }
            else
            {
                v8 = sub_4E4C90(a1, 0x200u);
                result = sub_4E4500(a1, 0x2000000, 512, v8);
            }
        }
    }
    return result;
}

//----- (004E4A70) --------------------------------------------------------
double __cdecl sub_4E4A70(int a1)
{
    return *(float*)(a1 + 120);
}

//----- (004E4A80) --------------------------------------------------------
int __cdecl sub_4E4A80(int a1)
{
    return *(_DWORD*)(a1 + 340);
}

//----- (004E4A90) --------------------------------------------------------
int* __cdecl sub_4E4A90(int a1, unsigned __int8 a2, int a3)
{
    int v3; // edi
    int v4; // eax
    int* result; // eax
    int v6; // ecx
    int v7; // edx
    int v8; // eax

    v3 = *(_DWORD*)(a1 + 748);
    sub_4E44F0(a1);
    v4 = v3 + 2 * (a2 + 692) + a2 + 692;
    *(_WORD*)v4 = *(_WORD*)a3;
    *(_BYTE*)(v4 + 2) = *(_BYTE*)(a3 + 2);
    if (*(_DWORD*)(a1 + 8) & 0x20400004)
    {
        result = (int*)(a1 + 560);
        v6 = 32;
        do
        {
            v7 = *result;
            ++result;
            --v6;
            *(result - 1) = v7 & 0xFFFFF000 | 0x4000000;
        } while (v6);
    }
    else
    {
        v8 = sub_4E4C90(a1, 0x400u);
        result = sub_4E4500(a1, 0x4000000, 1024, v8);
    }
    return result;
}

//----- (004E4B20) --------------------------------------------------------
int* __cdecl sub_4E4B20(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // ecx
    int v5; // ecx
    int* result; // eax
    int v7; // ecx
    int v8; // edx

    v3 = *(_DWORD*)(a1 + 748);
    sub_4E44F0(a1);
    v4 = *(_DWORD*)(a2 + 8);
    if (a3 == 1)
    {
        if (v4 & 0x1001000)
        {
            *(_DWORD*)(v3 + 2056) |= sub_415820(a2);
            goto LABEL_9;
        }
        v5 = sub_415C70(a2) | *(_DWORD*)(v3 + 2060);
    }
    else
    {
        if (v4 & 0x1001000)
        {
            *(_DWORD*)(v3 + 2056) &= ~sub_415820(a2);
            goto LABEL_9;
        }
        v5 = ~sub_415C70(a2) & *(_DWORD*)(v3 + 2060);
    }
    *(_DWORD*)(v3 + 2060) = v5;
    LABEL_9:
    if (!(*(_DWORD*)(a1 + 8) & 0x20400004))
        return sub_4E4500(a1, 0x4000000, 1024, 1);
    result = (int*)(a1 + 560);
    v7 = 32;
    do
    {
        v8 = *result;
        ++result;
        --v7;
        *(result - 1) = v8 & 0xFFFFF000 | 0x4000000;
    } while (v7);
    return result;
}

//----- (004E4C00) --------------------------------------------------------
int __cdecl sub_4E4C00(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 36);
    else
        result = 0;
    return result;
}

//----- (004E4C10) --------------------------------------------------------
int __cdecl sub_4E4C10(int a1)
{
    int result; // eax

    if (a1)
        result = *(unsigned __int16*)(a1 + 4);
    else
        result = 0;
    return result;
}

//----- (004E4C30) --------------------------------------------------------
int __cdecl sub_4E4C30(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 692);
    else
        result = 0;
    return result;
}

//----- (004E4C50) --------------------------------------------------------
int __cdecl sub_4E4C50(int a1)
{
    int v1; // eax
    int result; // eax

    if (a1 && (v1 = sub_4E3B70(*(unsigned __int16*)(a1 + 4))) != 0)
        result = *(_DWORD*)(v1 + 180);
    else
        result = 0;
    return result;
}

//----- (004E4C80) --------------------------------------------------------
int __cdecl sub_4E4C80(int* a1)
{
    int result; // eax

    if (a1)
        result = *a1;
    else
        result = 0;
    return result;
}

//----- (004E4C90) --------------------------------------------------------
BOOL __cdecl sub_4E4C90(int a1, unsigned int a2)
{
    _DWORD* v2; // eax
    BOOL result; // eax
    _WORD* v4; // esi
    _WORD* v5; // eax

    v2 = (_DWORD*)sub_4E3B70(*(unsigned __int16*)(a1 + 4));
    if (a2 > 0x20)
    {
        if (a2 > 0x200)
        {
            if (a2 == 1024 && *(_BYTE*)(a1 + 8) & 2 && *(_BYTE*)(a1 + 12) & 0x30)
                return 1;
        }
        else
        {
            switch (a2)
            {
                case 0x200u:
                    return (*(_DWORD*)(a1 + 8) & 0x13001000) != 0;
                case 0x40u:
                    if (*(float*)(a1 + 104) != 0.0)
                        return 1;
                    break;
                case 0x80u:
                    return *(_DWORD*)(a1 + 340) != 0;
            }
        }
        return 0;
    }
    if (a2 == 32)
        return 0;
    switch (a2)
    {
        case 1u:
            result = *(_DWORD*)(a1 + 132) != 0;
            break;
        case 2u:
            v4 = *(_WORD * *)(a1 + 556);
            if (!v4)
                return 0;
            v5 = (_WORD*)v2[34];
            if (!v5)
                return 0;
            result = *v5 != *v4;
            break;
        case 4u:
            result = ((unsigned int)(*(_DWORD*)(a1 + 16) ^ v2[8]) >> 24) & 1;
            break;
        case 8u:
            result = v2[9] != *(_DWORD*)(a1 + 20);
            break;
        default:
            return 0;
    }
    return result;
}

//----- (004E4DC0) --------------------------------------------------------
void sub_4E4DC0()
{
    nox_srand(0x1429u);
}

//----- (004E4DD0) --------------------------------------------------------
void sub_4E4DD0()
{
    nox_srand(0x490u);
}

//----- (004E4DE0) --------------------------------------------------------
int sub_4E4DE0()
{
    int v0; // edi
    unsigned __int8* v1; // esi
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1565508])
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1565508]);
    *(_DWORD*)& byte_5D4594[1565508] = 0;
    memset(&byte_5D4594[1565524], 0, 0x40u);
    memset(&byte_5D4594[1565124], 0, 0x180u);
    *(_DWORD*)& byte_5D4594[1565512] = 0;
    *(_DWORD*)& byte_5D4594[1565516] = 0;
    v0 = 0;
    v1 = &byte_5D4594[1565124];
    do
    {
        v1[1] = 2;
        *v1 = 1;
        v1[2] = sub_40A6C0();
        result = sub_4E4E50(v0);
        v1 += 12;
        ++v0;
    } while ((int)v1 < (int)& byte_5D4594[1565508]);
    return result;
}

//----- (004E4E50) --------------------------------------------------------
int __cdecl sub_4E4E50(int a1)
{
    unsigned int v1; // esi
    unsigned __int8 v2; // bl
    unsigned __int8* v3; // ecx
    int result; // eax

    v1 = 1;
    if (*(_DWORD*)& byte_5D4594[2650652] == 1)
        v1 = sub_40A6C0();
    v2 = byte_5D4594[12 * a1 + 1565125];
    v3 = &byte_5D4594[12 * a1 + 1565124];
    if (v2 > 2u)
        * ((_DWORD*)v3 + 2) = *v3 * (v2 - 1) * (*(_DWORD*)& byte_5D4594[2649704] / v1);
    else
        *((_DWORD*)v3 + 2) = 0;
    result = v2 * *v3 * (*(_DWORD*)& byte_5D4594[2649704] / v1);
    *((_DWORD*)v3 + 1) = result;
    return result;
}

//----- (004E4ED0) --------------------------------------------------------
int sub_4E4ED0()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[1565524], 0, 0x40u);
    return result;
}

//----- (004E4EF0) --------------------------------------------------------
int sub_4E4EF0()
{
    unsigned __int8* v0; // esi
    int v1; // edi
    int result; // eax

    v0 = &byte_5D4594[1565124];
    memset(&byte_5D4594[1565124], 0, 0x180u);
    v1 = 0;
    do
    {
        v0[1] = 2;
        *v0 = 1;
        v0[2] = sub_40A6C0();
        result = sub_4E4E50(v1);
        v0 += 12;
        ++v1;
    } while ((int)v0 < (int)& byte_5D4594[1565508]);
    return result;
}

//----- (004E4F30) --------------------------------------------------------
int __cdecl sub_4E4F30(int a1)
{
    int result; // eax

    result = a1;
    *(_WORD*)& byte_5D4594[2 * a1 + 1565524] = 0;
    return result;
}

//----- (004E4F40) --------------------------------------------------------
int __cdecl sub_4E4F40(int a1)
{
    int v1; // esi

    v1 = 12 * a1;
    byte_5D4594[v1 + 1565125] = 2;
    byte_5D4594[v1 + 1565124] = 1;
    byte_5D4594[v1 + 1565126] = sub_40A6C0();
    return sub_4E4E50(a1);
}

//----- (004E4F80) --------------------------------------------------------
int sub_4E4F80()
{
    int result; // eax
    unsigned __int8 v1; // cl
    int v2; // esi

    result = *(_DWORD*)& byte_5D4594[1565512];
    if (*(_DWORD*)& byte_5D4594[1565512])
    {
        do
        {
            v1 = *(_BYTE*)(result + 251);
            v2 = *(_DWORD*)(result + 408);
            if (v1 >= 0x31u && v1 <= 0x33u)
                sub_4E4FC0(result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (004E4FC0) --------------------------------------------------------
void __cdecl sub_4E4FC0(int a1)
{
    int v1; // ecx
    int v2; // ecx

    v1 = *(_DWORD*)(a1 + 412);
    if (v1)
        * (_DWORD*)(v1 + 408) = *(_DWORD*)(a1 + 408);
    else
        *(_DWORD*)& byte_5D4594[1565512] = *(_DWORD*)(a1 + 408);
    v2 = *(_DWORD*)(a1 + 408);
    if (v2)
        * (_DWORD*)(v2 + 412) = *(_DWORD*)(a1 + 412);
    else
        *(_DWORD*)& byte_5D4594[1565516] = *(_DWORD*)(a1 + 412);
    sub_414330(*(unsigned int**)& byte_5D4594[1565508], (_QWORD*)a1);
}

//----- (004E5030) --------------------------------------------------------
int __cdecl sub_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6)
{
    char* v7; // eax
    char* v8; // edx
    _WORD* v9; // esi
    char v10; // cl
    unsigned __int8* v11; // eax
    unsigned __int8* v12; // eax
    int v13; // edi
    int v14; // ecx

    if (a1 == 255 || (a1 & 0x80u) == 0 || *(_DWORD*)& byte_5D4594[2649712] & ~(1 << (a1 & 0x7F)))
    {
        if (a3 > 150)
            return 0;
        v7 = *(char**)& byte_5D4594[1565508];
        if (!*(_DWORD*)& byte_5D4594[1565508])
        {
            if (sub_40A5C0(2048))
                * (_DWORD*)& byte_5D4594[1565520] = 512;
            else
                *(_DWORD*)& byte_5D4594[1565520] = sub_40A5C0(1) ? 3072 : 256;
            if (sub_40A5C0(2048))
                v7 = nox_new_alloc_class_f30("importantClass", 416, *(int*)& byte_5D4594[1565520]);
            else
                v7 = nox_new_alloc_class("importantClass", 416, *(int*)& byte_5D4594[1565520]);
            *(_DWORD*)& byte_5D4594[1565508] = v7;
        }
        v8 = (char*)nox_alloc_class_new_obj_zero(v7);
        if (!v8)
        {
            if (sub_4E52B0() != 1)
                return 0;
            v8 = (char*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1565508]);
            if (!v8)
                return 0;
        }
        qmemcpy(v8 + 251, a2, a3);
        v8[401] = a3;
        *((_DWORD*)v8 + 101) = a4;
        v8[250] = a1;
        *((_DWORD*)v8 + 45) = a5;
        v8[184] = a6;
        *((_DWORD*)v8 + 43) = 0;
        *((_DWORD*)v8 + 42) = 0;
        v8[164] = 0;
        *((_DWORD*)v8 + 44) = *(_DWORD*)& byte_5D4594[2649712];
        memset(v8 + 4, 0, 0x80u);
        v9 = v8 + 186;
        *(_DWORD*)v8 = *(_DWORD*)& byte_5D4594[2598000];
        memset(v8 + 186, 0, 0x40u);
        if (v8[184])
        {
            if (a1 == 255)
            {
                v10 = 0;
                v11 = &byte_5D4594[1565524];
                do
                {
                    if ((1 << v10) & *((_DWORD*)v8 + 44))
                        * v9 = (*(_WORD*)v11)++;
                    v11 += 2;
                    ++v10;
                    ++v9;
                } while ((int)v11 < (int)& byte_5D4594[1565588]);
            }
            else if ((a1 & 0x80u) == 0)
            {
                *(_WORD*)& v8[2 * a1 + 186] = (*(_WORD*)& byte_5D4594[2 * a1 + 1565524])++;
            }
            else
            {
                v12 = &byte_5D4594[1565524];
                v13 = v8[250] & 0x7F;
                v14 = 0;
                do
                {
                    if (v14 != v13 && (1 << v14) & *((_DWORD*)v8 + 44))
                        * v9 = (*(_WORD*)v12)++;
                    v12 += 2;
                    ++v14;
                    ++v9;
                } while ((int)v12 < (int)& byte_5D4594[1565588]);
            }
        }
        *((_DWORD*)v8 + 103) = 0;
        *((_DWORD*)v8 + 102) = *(_DWORD*)& byte_5D4594[1565512];
        if (*(_DWORD*)& byte_5D4594[1565512])
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1565512] + 412) = v8;
            *(_DWORD*)& byte_5D4594[1565512] = v8;
            return 1;
        }
        *(_DWORD*)& byte_5D4594[1565516] = v8;
        *(_DWORD*)& byte_5D4594[1565512] = v8;
    }
    return 1;
}

//----- (004E52B0) --------------------------------------------------------
int sub_4E52B0()
{
    int v0; // ebp
    int v1; // edx
    int v2; // ebx
    unsigned __int16 v3; // si
    unsigned int v4; // edi
    char v5; // al
    int v6; // eax
    __int16 v8[32]; // [esp+10h] [ebp-40h]

    v0 = 0;
    v1 = *(_DWORD*)& byte_5D4594[1565512];
    v8[0] = 0;
    memset(&v8[1], 0, 0x3Cu);
    v2 = -1;
    v3 = 0;
    v8[31] = 0;
    v4 = 999999999;
    if (!*(_DWORD*)& byte_5D4594[1565512])
        return 0;
    do
    {
        v5 = *(_BYTE*)(v1 + 250);
        if (v5 != -1 && v5 >= 0 && v5 != 31)
        {
            v6 = *(unsigned __int8*)(v1 + 250);
            if ((unsigned __int16)++v8[v6] > v3)
            {
                v2 = v6;
                v3 = v8[v6];
            }
        }
        if (*(_DWORD*)v1 < v4)
        {
            v4 = *(_DWORD*)v1;
            v0 = v1;
        }
        v1 = *(_DWORD*)(v1 + 408);
    } while (v1);
    if (v2 != -1)
    {
        nullsub_24(&byte_587000[202360]);
        sub_4E5360(v2);
    }
    if (!v0)
        return 0;
    sub_4E4FC0(v0);
    return 1;
}
// 4E5AB0: using guessed type void __cdecl nullsub_24(_DWORD);

//----- (004E5360) --------------------------------------------------------
char* __cdecl sub_4E5360(int a1)
{
    char* result; // eax
    char* v2; // esi

    result = sub_417090(a1);
    v2 = result;
    if (result)
    {
        sub_4E55F0(a1);
        result = (char*)sub_4174F0((int)v2, 128);
    }
    return result;
}

//----- (004E5390) --------------------------------------------------------
int __cdecl sub_4E5390(int a1, int a2, int a3, int a4, int a5)
{
    return sub_4E5030(a1, (const void*)a2, a3, a4, a5, 1);
}

//----- (004E53C0) --------------------------------------------------------
int __cdecl sub_4E53C0(int a1, const void* a2, int a3, int a4, int a5)
{
    int result; // eax

    if (sub_40A5C0(1))
    {
        sub_40EBC0(a1, 0, a2, a3);
        result = 1;
    }
    else if (a1 == 255 || (a1 & 0x80u) != 0)
    {
        result = 0;
    }
    else
    {
        result = sub_4E5420(a1, a2, a3, a4, a5);
    }
    return result;
}

//----- (004E5420) --------------------------------------------------------
int __cdecl sub_4E5420(int a1, const void* a2, signed int a3, int a4, int a5)
{
    return sub_4E5030(a1, a2, a3, a4, a5, 0);
}

//----- (004E5450) --------------------------------------------------------
int __cdecl sub_4E5450(int a1, char* a2, signed int a3, int a4, int a5)
{
    char* v5; // edi
    int v6; // eax
    int v7; // esi
    char v9; // [esp+10h] [ebp+8h]

    v5 = a2;
    v9 = *a2;
    v6 = *(_DWORD*)& byte_5D4594[1565512];
    if (*(_DWORD*)& byte_5D4594[1565512])
    {
        do
        {
            v7 = *(_DWORD*)(v6 + 408);
            if (v9 == *(_BYTE*)(v6 + 251))
            {
                if (a1 == 255 || (a1 & 0x80u) != 0)
                    sub_4E4FC0(v6);
                else
                    sub_4E54D0(1 << a1, v6, a1);
            }
            v6 = v7;
        } while (v7);
    }
    return sub_4E5420(a1, v5, a3, a4, a5);
}

//----- (004E54D0) --------------------------------------------------------
void __cdecl sub_4E54D0(int a1, int a2, int a3)
{
    int v3; // ecx
    char v4; // dl
    int v5; // esi
    char v6; // cl
    int v7; // ecx
    int v8; // edx
    int v9; // ecx

    v3 = *(_DWORD*)(a2 + 404);
    if (v3)
    {
        v4 = *(_BYTE*)(a2 + 251);
        if (v4 == 49 || v4 == 50 || v4 == 51)
            * (_DWORD*)(v3 + 148) &= ~a1;
    }
    v5 = *(_DWORD*)& byte_5D4594[2649712] & *(_DWORD*)(a2 + 176);
    v6 = *(_BYTE*)(a2 + 250);
    if (v6 == -1)
    {
        v7 = a1 | *(_DWORD*)(a2 + 168);
        *(_DWORD*)(a2 + 168) = v7;
        if ((v5 & v7) == v5)
            sub_4E4FC0(a2);
    }
    else if (v6 >= 0)
    {
        if (*(unsigned __int8*)(a2 + 250) == a3)
            sub_4E4FC0(a2);
    }
    else
    {
        v8 = 1 << (v6 & 0x7F);
        v9 = a1 | *(_DWORD*)(a2 + 168);
        *(_DWORD*)(a2 + 168) = v9;
        if ((v5 & ~v8 & v9) == (v5 & ~v8))
            sub_4E4FC0(a2);
    }
}

//----- (004E55A0) --------------------------------------------------------
int __cdecl sub_4E55A0(unsigned __int8 a1, int a2)
{
    int result; // eax
    int v3; // edi

    result = *(_DWORD*)& byte_5D4594[1565512];
    if (*(_DWORD*)& byte_5D4594[1565512])
    {
        do
        {
            v3 = *(_DWORD*)(result + 408);
            if (*(_DWORD*)(result + 4 * a1 + 4) == a2)
                sub_4E54D0(1 << a1, result, a1);
            result = v3;
        } while (v3);
    }
    return result;
}

//----- (004E55F0) --------------------------------------------------------
int __cdecl sub_4E55F0(unsigned __int8 a1)
{
    int result; // eax
    int v2; // esi

    result = *(_DWORD*)& byte_5D4594[1565512];
    if (*(_DWORD*)& byte_5D4594[1565512])
    {
        do
        {
            v2 = *(_DWORD*)(result + 408);
            sub_4E54D0(1 << a1, result, a1);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (004E5630) --------------------------------------------------------
int __cdecl sub_4E5630(unsigned __int8 a1, _DWORD* a2, _DWORD* a3, _DWORD* a4)
{
    int result; // eax

    result = 12 * a1;
    *a2 = *(_DWORD*)& byte_5D4594[result + 1565128];
    *a3 = byte_5D4594[result + 1565125];
    *a4 = byte_5D4594[result + 1565124];
    return result;
}

//----- (004E5670) --------------------------------------------------------
unsigned int __cdecl sub_4E5670(unsigned __int8 a1)
{
    int v1; // ebp
    int v2; // eax
    int v3; // ecx
    char v4; // al
    unsigned __int8* v5; // esi
    unsigned __int8 v6; // al
    unsigned int result; // eax
    int v8; // eax
    unsigned __int8 v9; // al

    v1 = 0;
    sub_417090(a1);
    v2 = *(_DWORD*)& byte_5D4594[1565516];
    if (*(_DWORD*)& byte_5D4594[1565516])
    {
        do
        {
            v3 = *(_DWORD*)(v2 + 412);
            if (!(*(_DWORD*)(v2 + 168) & (1 << a1)))
            {
                v4 = *(_BYTE*)(v2 + 250);
                if (v4 == -1)
                    goto LABEL_8;
                if (v4 >= 0)
                {
                    if (v4 == a1)
                    {
                        LABEL_8:
                        ++v1;
                        goto LABEL_9;
                    }
                }
                else if (a1 != (v4 & 0x7F))
                {
                    goto LABEL_8;
                }
            }
            LABEL_9:
            v2 = v3;
        } while (v3);
    }
    v5 = &byte_5D4594[12 * a1 + 1565124];
    if (sub_40A6C0() != v5[2])
        v5[2] = sub_40A6C0();
    if (v1 <= *((_DWORD*)v5 + 1))
    {
        v8 = *((_DWORD*)v5 + 2);
        if (v8 > 0 && v1 < v8)
        {
            if (*v5 == 2)
            {
                *v5 = 1;
                return sub_4E4E50(a1);
            }
            v9 = v5[1] - 1;
            v5[1] = v9;
            if (v9 < 2u)
                v5[1] = 2;
        }
        result = sub_4E4E50(a1);
    }
    else
    {
        v6 = v5[1] + 1;
        v5[1] = v6;
        if (v6 > 5u)
        {
            if (*v5 == 2)
                sub_4E5360(a1);
            v5[1] = 5;
            *v5 = 2;
        }
        v5[2] = sub_40A6C0();
        result = sub_4E4E50(a1);
    }
    return result;
}

//----- (004E5770) --------------------------------------------------------
void __cdecl sub_4E5770(unsigned __int8 a1, int a2)
{
    int v2; // edi
    char* v3; // esi
    int v4; // ebp
    int v5; // eax
    char v6; // al
    int v7; // eax
    char v8; // al
    char v9; // cl
    int v10; // eax
    int v11; // eax
    char v12[1]; // [esp+13h] [ebp-1Dh]
    int(__cdecl * v13)(int, int, const void*, int); // [esp+14h] [ebp-1Ch]
    int v14; // [esp+18h] [ebp-18h]
    int v15; // [esp+1Ch] [ebp-14h]
    int v16; // [esp+20h] [ebp-10h]
    int v17; // [esp+24h] [ebp-Ch]
    char v18[5]; // [esp+28h] [ebp-8h]

    v2 = 1 << a1;
    v15 = 1;
    v14 = 0;
    v16 = 1 << a1;
    v3 = sub_417090(a1);
    v13 = sub_40EBC0;
    if (a1 != 31)
        v13 = sub_40ECA0;
    if (!v3 || !sub_40A5C0(1) || v3[3680] & 0x10)
    {
        v4 = *(_DWORD*)& byte_5D4594[1565516];
        if (*(_DWORD*)& byte_5D4594[1565516])
        {
            while (1)
            {
                v17 = *(_DWORD*)(v4 + 412);
                v5 = *(_DWORD*)(v4 + 404);
                if (v5 && *(_BYTE*)(v5 + 16) & 0x20)
                    * (_DWORD*)(v4 + 404) = 0;
                if (v2 & *(_DWORD*)(v4 + 168))
                    goto LABEL_39;
                v6 = *(_BYTE*)(v4 + 250);
                if (v6 != -1)
                {
                    if (v6 >= 0)
                    {
                        if (v6 != a1)
                            goto LABEL_39;
                    }
                    else if (a1 == (v6 & 0x7F))
                    {
                        goto LABEL_39;
                    }
                }
                v7 = *(_DWORD*)(v4 + 404);
                if (v7 && !(v2 & *(_DWORD*)(v7 + 148)) || *(_DWORD*)(v4 + 180) && !(v2 & *(_DWORD*)& byte_5D4594[2649712]))
                {
                    sub_4E54D0(v2, v4, a1);
                    return;
                }
                if (!(v2 & *(_DWORD*)(v4 + 172)))
                    goto LABEL_24;
                v8 = *(_BYTE*)(a1 + v4 + 132);
                if (v8)
                {
                    *(_BYTE*)(a1 + v4 + 132) = v8 - 1;
                    goto LABEL_39;
                }
                if (v14 < byte_5D4594[12 * a1 + 1565124])
                    break;
                LABEL_39:
                v4 = v17;
                if (!v17)
                    goto LABEL_40;
            }
            v9 = *(_BYTE*)(v4 + 164) + 1;
            v10 = v14 + 1;
            *(_DWORD*)(v4 + 172) &= ~v2;
            *(_BYTE*)(v4 + 164) = v9;
            v14 = v10;
            LABEL_24:
            if (v15)
            {
                if (a2 && a1 != 31)
                {
                    v12[0] = -86;
                    if (!v13(a1, a2, v12, 1))
                        return;
                }
                else
                {
                    v18[0] = -86;
                    *(_DWORD*)& v18[1] = *(_DWORD*)& byte_5D4594[2598000];
                    if (!v13(a1, a2, v18, 5))
                        return;
                }
                v15 = 0;
            }
            if (!*(_BYTE*)(v4 + 184))
            {
                v11 = v13(a1, a2, (const void*)(v4 + 251), *(unsigned __int8*)(v4 + 401));
                goto LABEL_36;
            }
            if (byte_5D4594 != (unsigned __int8*)-1564964)
            {
                byte_5D4594[1564964] = -52;
                *(_WORD*)& byte_5D4594[1564965] = *(_WORD*)(v4 + 2 * a1 + 186);
                byte_5D4594[1564967] = *(_BYTE*)(v4 + 401);
                qmemcpy(&byte_5D4594[1564968], (const void*)(v4 + 251), *(unsigned __int8*)(v4 + 401));
                v11 = v13(a1, a2, &byte_5D4594[1564964], *(unsigned __int8*)(v4 + 401) + 4);
                v2 = v16;
                LABEL_36:
                if (v11)
                {
                    *(_DWORD*)(v4 + 172) |= v2;
                    *(_BYTE*)(a1 + v4 + 132) = *(_DWORD*)& byte_5D4594[2649704]
                                               * (unsigned int)byte_5D4594[12 * a1 + 1565125]
                                               / sub_40A6C0();
                    *(_DWORD*)(v4 + 4 * a1 + 4) = *(_DWORD*)& byte_5D4594[2598000];
                    if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
                        sub_4E54D0(v2, v4, a1);
                }
                goto LABEL_39;
            }
            goto LABEL_39;
        }
        LABEL_40:
        if (sub_40A5C0(1)
            && !(*(_DWORD*)& byte_5D4594[2598000]
                 % (*(_DWORD*)& byte_5D4594[2649704] * (unsigned int)byte_5D4594[12 * a1 + 1565125])))
        {
            sub_4E5670(a1);
        }
    }
}

//----- (004E5A90) --------------------------------------------------------
int sub_4E5A90()
{
    int v0; // eax
    int i; // ecx

    v0 = *(_DWORD*)& byte_5D4594[1565512];
    for (i = 0; v0; ++i)
        v0 = *(_DWORD*)(v0 + 408);
    return *(_DWORD*)& byte_5D4594[1565520] - i;
}

//----- (004E5AC0) --------------------------------------------------------
void sub_4E5AC0()
{
    nox_srand(0x13D11u);
}

//----- (004E5AD0) --------------------------------------------------------
void __cdecl sub_4E5AD0(int a1)
{
    char v1; // al
    int v2; // esi
    int v3; // edi

    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v1 = *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251);
        if (v1 == 1)
        {
            sub_4E5F40(a1);
        }
        else if (v1 == 2)
        {
            sub_4E5FC0(a1);
        }
    }
    v2 = *(_DWORD*)(a1 + 516);
    if (v2)
    {
        do
        {
            v3 = *(_DWORD*)(v2 + 512);
            if (*(_BYTE*)(v2 + 8) & 1 || !sub_4E3B80(*(unsigned __int16*)(v2 + 4)))
                sub_4E5CC0(v2);
            v2 = v3;
        } while (v3);
    }
}

//----- (004E5B50) --------------------------------------------------------
BOOL __cdecl sub_4E5B50(int a1)
{
    int v1; // ecx
    BOOL result; // eax

    result = 0;
    if (!sub_40A5C0(0x2000))
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v1 = *(_DWORD*)(a1 + 12);
            if (v1 & 0x100)
                result = 1;
        }
    }
    return result;
}

//----- (004E5B80) --------------------------------------------------------
BOOL __cdecl sub_4E5B80(int a1)
{
    int v1; // eax
    BOOL result; // eax

    if (!*(_DWORD*)& byte_5D4594[1565592])
        * (_DWORD*)& byte_5D4594[1565592] = sub_4E3AA0((CHAR*)& byte_587000[202376]);
    result = 0;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 1)
        {
            if (sub_40A5C0(2048))
            {
                if (*(unsigned __int16*)(a1 + 4) == *(_DWORD*)& byte_5D4594[1565592])
                {
                    v1 = sub_4EC580(a1);
                    if (v1)
                    {
                        if (*(_BYTE*)(v1 + 8) & 4)
                            result = 1;
                    }
                }
            }
        }
    }
    return result;
}

//----- (004E5BF0) --------------------------------------------------------
void __cdecl sub_4E5BF0(int a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // eax
    int v4; // eax
    int v5; // esi
    int v6; // edi

    if (!*(_DWORD*)& byte_5D4594[1565596])
        * (_DWORD*)& byte_5D4594[1565596] = sub_4E3AA0((CHAR*)& byte_587000[202384]);
    v1 = sub_4DA790();
    if (v1)
    {
        do
        {
            v2 = sub_4DA7A0(v1);
            if (!a1
                || !(*(_BYTE*)(v1 + 8) & 4)
                   && ((v3 = *(_DWORD*)(v1 + 492)) == 0 || !(*(_BYTE*)(v3 + 8) & 4))
                   && (*(unsigned __int16*)(v1 + 4) != *(_DWORD*)& byte_5D4594[1565596]
                       || (v4 = *(_DWORD*)(v1 + 508)) == 0
                       || !(*(_BYTE*)(v4 + 8) & 4))
                   && !sub_4E5B50(v1))
            {
                sub_4E5CC0(v1);
            }
            v1 = v2;
        } while (v2);
    }
    v5 = sub_4DA840();
    if (v5)
    {
        do
        {
            v6 = sub_4DA850(v5);
            if (a1 != 1 || !sub_4E5B80(v5))
                sub_4E5CC0(v5);
            v5 = v6;
        } while (v6);
    }
}

//----- (004E5CC0) --------------------------------------------------------
void __cdecl sub_4E5CC0(int a1)
{
    int v1; // eax
    int v2; // eax

    if (a1 && !(*(_BYTE*)(a1 + 16) & 0x20))
    {
        v1 = *(_DWORD*)(a1 + 508);
        if (v1 && *(_BYTE*)(v1 + 8) & 4 && *(_BYTE*)(a1 + 8) & 2 && !sub_500CC0(v1, a1) && (*(_BYTE*)(a1 + 12) & 0x80))
            sub_4E7B60(*(_DWORD*)(a1 + 508), (_DWORD*)a1);
        v2 = *(_DWORD*)(a1 + 492);
        if (v2)
            sub_4ED0C0(v2, (int*)a1);
        sub_4FEAE0(a1);
        if (sub_40A5C0(4096) && *(_BYTE*)(a1 + 8) & 2)
            sub_50E210(a1);
        if (*(_BYTE*)(a1 + 8) & 4)
            sub_506740(a1);
        *(_DWORD*)(a1 + 16) |= 0x20u;
        *(_DWORD*)(a1 + 452) = *(_DWORD*)& byte_5D4594[1565588];
        *(_DWORD*)& byte_5D4594[1565588] = a1;
        *(_DWORD*)(a1 + 456) = *(_DWORD*)& byte_5D4594[2598000];
        if (sub_419130(a1 + 48))
            sub_419570(a1 + 48, *(_DWORD*)(a1 + 36));
    }
}

//----- (004E5DB0) --------------------------------------------------------
void __cdecl sub_4E5DB0(int a1)
{
    int v1; // edi
    int v2; // ebx
    int v3; // eax
    int v4; // esi

    v1 = sub_4DA790();
    if (v1)
    {
        do
        {
            v2 = sub_4DA7A0(v1);
            v3 = *(_DWORD*)(v1 + 504);
            if (v3)
            {
                do
                {
                    v4 = *(_DWORD*)(v3 + 496);
                    if (*(unsigned __int16*)(v3 + 4) == a1)
                        sub_4E5CC0(v3);
                    v3 = v4;
                } while (v4);
            }
            if (*(unsigned __int16*)(v1 + 4) == a1)
                sub_4E5CC0(v1);
            v1 = v2;
        } while (v2);
    }
}

//----- (004E5E20) --------------------------------------------------------
_DWORD* sub_4E5E20()
{
    _DWORD* result; // eax
    _DWORD* v1; // edi
    _DWORD* v2; // esi

    result = *(_DWORD * *)& byte_5D4594[1565588];
    v1 = 0;
    if (*(_DWORD*)& byte_5D4594[1565588])
    {
        do
        {
            v2 = (_DWORD*)result[113];
            if (result[114] == *(_DWORD*)& byte_5D4594[2598000])
            {
                result[113] = v1;
                v1 = result;
                sub_4DA920(result);
            }
            else
            {
                sub_4E5E80(result);
            }
            result = v2;
        } while (v2);
        *(_DWORD*)& byte_5D4594[1565588] = v1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1565588] = 0;
    }
    return result;
}

//----- (004E5E80) --------------------------------------------------------
int __cdecl sub_4E5E80(_DWORD* a1)
{
    sub_4EC4B0((int)a1);
    sub_4EC300((int)a1);
    sub_51AE60((int)a1);
    sub_5116F0((int)a1);
    sub_4EDA40(a1);
    sub_4DADE0((int)a1);
    return sub_4E38A0((int)a1);
}

//----- (004E5EC0) --------------------------------------------------------
_DWORD* sub_4E5EC0()
{
    _DWORD* result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD * *)& byte_5D4594[1565588];
    if (*(_DWORD*)& byte_5D4594[1565588])
    {
        do
        {
            v1 = (_DWORD*)result[113];
            sub_4E5E80(result);
            result = v1;
        } while (v1);
        *(_DWORD*)& byte_5D4594[1565588] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1565588] = 0;
    }
    return result;
}

//----- (004E5F00) --------------------------------------------------------
void __cdecl sub_4E5F00(int(__cdecl* a1)(int, int), int a2)
{
    int i; // esi

    for (i = *(_DWORD*)& byte_5D4594[1565588]; i; i = *(_DWORD*)(i + 452))
    {
        if (*(_DWORD*)(i + 456) != *(_DWORD*)& byte_5D4594[2598000])
            a1(i, a2);
    }
}

//----- (004E5F40) --------------------------------------------------------
int __cdecl sub_4E5F40(int a1)
{
    int result; // eax
    int i; // esi

    if (!*(_DWORD*)& byte_5D4594[1565600])
        * (_DWORD*)& byte_5D4594[1565600] = sub_4E3AA0((CHAR*)& byte_587000[202396]);
    result = sub_4DA790();
    for (i = result; result; i = result)
    {
        if (sub_4EC4F0(i, a1)
            && *(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[1565600]
            && !(*(_BYTE*)(i + 16) & 0x20))
        {
            sub_522FF0(129, (float2*)(i + 56));
            sub_4E5CC0(i);
        }
        result = sub_4DA7A0(i);
    }
    return result;
}

//----- (004E5FC0) --------------------------------------------------------
void __cdecl sub_4E5FC0(int a1)
{
    int v1; // ebx
    int v2; // ebp
    int v3; // esi
    int v4; // edi

    v1 = *(_DWORD*)(a1 + 516);
    if (v1)
    {
        do
        {
            v2 = *(_DWORD*)(v1 + 512);
            if (sub_500CC0(a1, v1))
            {
                v3 = sub_4E7980(v1);
                if (v3)
                {
                    do
                    {
                        v4 = sub_4E7990(v3);
                        sub_4E5CC0(v3);
                        v3 = v4;
                    } while (v4);
                }
                sub_522FF0(129, (float2*)(v1 + 56));
                sub_4E5CC0(v1);
            }
            v1 = v2;
        } while (v2);
    }
}

//----- (004E6040) --------------------------------------------------------
int __cdecl sub_4E6040(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 3628) = 0;
    return result;
}

//----- (004E6060) --------------------------------------------------------
int __cdecl sub_4E6060(int a1, int a2)
{
    int result; // eax

    result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
    if (*(_DWORD*)(result + 3628) == a2)
        return sub_4E6040(a1);
    *(_DWORD*)(result + 3628) = a2;
    return result;
}

//----- (004E60A0) --------------------------------------------------------
char* __cdecl sub_4E60A0(int a1)
{
    char* result; // eax
    int i; // esi

    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        if (*(_DWORD*)(i + 3628) == a1)
            sub_4E60E0(i);
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004E60E0) --------------------------------------------------------
int __cdecl sub_4E60E0(int a1)
{
    int result; // eax
    int v2; // edi

    result = *(_DWORD*)(a1 + 2056);
    if (result)
    {
        if (sub_4DDF30(*(_DWORD*)(a1 + 2056)))
        {
            v2 = sub_4E6280(a1);
            if (!v2)
                return sub_4DDEF0(*(_DWORD*)(a1 + 2056));
        }
        else
        {
            v2 = sub_4E6150(a1);
        }
        sub_4E6040(*(_DWORD*)(a1 + 2056));
        result = sub_4E6060(*(_DWORD*)(a1 + 2056), v2);
    }
    return result;
}

//----- (004E6150) --------------------------------------------------------
int __cdecl sub_4E6150(int a1)
{
    int v1; // eax
    int v2; // eax
    int i; // esi
    char* v4; // eax
    int result; // eax
    char* v6; // eax

    if (!*(_DWORD*)& byte_5D4594[1565616])
        * (_DWORD*)& byte_5D4594[1565616] = sub_4E3AA0((CHAR*)& byte_587000[202408]);
    v1 = *(_DWORD*)(a1 + 3628);
    if (v1)
    {
        if (*(_BYTE*)(v1 + 8) & 4)
        {
            v2 = sub_4DA7F0(*(_DWORD*)(a1 + 3628));
            goto LABEL_7;
        }
    }
    else if (sub_40A5C0(64))
    {
        v2 = sub_4E6230();
        if (v2)
            goto LABEL_7;
    }
    v2 = sub_4DA7C0();
    LABEL_7:
    i = v2;
    if (!v2)
        goto LABEL_16;
    if (*(_BYTE*)(v2 + 8) & 4)
    {
        while (1)
        {
            v4 = sub_417040(*(_DWORD*)(i + 36));
            if (!(*(_BYTE*)(i + 16) & 0x20) && !(v4[3680] & 1))
                break;
            i = sub_4DA7F0(i);
            if (!i)
                goto LABEL_16;
        }
    }
    if (!i)
    {
        LABEL_16:
        result = sub_4E6230();
        if (result)
            return result;
        for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
        {
            v6 = sub_417040(*(_DWORD*)(i + 36));
            if (!(*(_BYTE*)(i + 16) & 0x20) && !(v6[3680] & 1))
                break;
        }
    }
    return i;
}

//----- (004E6230) --------------------------------------------------------
int sub_4E6230()
{
    int result; // eax

    if (!*(_DWORD*)& byte_5D4594[1565616])
        * (_DWORD*)& byte_5D4594[1565616] = sub_4E3AA0((CHAR*)& byte_587000[202420]);
    result = sub_4DA790();
    if (!result)
        return 0;
    while (*(unsigned __int16*)(result + 4) != *(_DWORD*)& byte_5D4594[1565616])
    {
        result = sub_4DA7A0(result);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004E6280) --------------------------------------------------------
int __cdecl sub_4E6280(int a1)
{
    int result; // eax

    if (*(_DWORD*)(a1 + 3628))
        result = sub_4EC420(*(_DWORD*)(a1 + 3628));
    else
        result = sub_4EC3E0(*(_DWORD*)(a1 + 2056));
    if (result)
    {
        while (*(_DWORD*)(result + 16) & 0x8020)
        {
            result = sub_4EC420(result);
            if (!result)
                goto LABEL_9;
        }
    }
    else
    {
        LABEL_9:
        for (result = sub_4EC3E0(*(_DWORD*)(a1 + 2056)); result; result = sub_4EC420(result))
        {
            if (!(*(_DWORD*)(result + 16) & 0x8020))
                break;
        }
    }
    return result;
}

//----- (004E62F0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4E62F0(int a1)
{
    int v1; // edi
    int v2; // edx
    _DWORD* v3; // eax
    int v4; // esi
    int v5; // eax
    int v6; // eax
    int v7; // eax
    unsigned __int8* result; // eax
    int v9; // ebx
    double v10; // st7
    bool v11; // zf
    int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // eax
    double v16; // st7
    double v17; // st7
    _DWORD* v18; // [esp+10h] [ebp-28h]
    float v19; // [esp+14h] [ebp-24h]
    float v20; // [esp+18h] [ebp-20h]
    float v21; // [esp+1Ch] [ebp-1Ch]
    float2 v22; // [esp+20h] [ebp-18h]
    float4 a1a; // [esp+28h] [ebp-10h]

    v1 = a1;
    v2 = 4;
    v3 = *(_DWORD * *)(a1 + 748);
    v18 = v3;
    v4 = v3[69];
    v5 = (int)(v3 + 29);
    do
    {
        if (*(_DWORD*)v5 && *(_BYTE*)(*(_DWORD*)v5 + 16) & 0x20)
            * (_DWORD*)v5 = 0;
        v5 += 4;
        --v2;
    } while (v2);
    sub_4E44F0(a1);
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
    {
        v6 = *(_DWORD*)(v4 + 3628);
        if (v6)
        {
            *(_DWORD*)(v4 + 3632) = *(_DWORD*)(v6 + 56);
            *(_DWORD*)(v4 + 3636) = *(_DWORD*)(v6 + 60);
        }
    }
    v7 = *(_DWORD*)(v4 + 3628);
    if (v7)
    {
        *(_DWORD*)(v4 + 3632) = *(_DWORD*)(v7 + 56);
        *(_DWORD*)(v4 + 3636) = *(_DWORD*)(v7 + 60);
    }
    result = sub_51AB50(*(unsigned __int8*)(v4 + 2064));
    if (result)
    {
        *(_DWORD*)(v4 + 3688) = 0;
        result = sub_51AB50(*(unsigned __int8*)(v4 + 2064));
        v9 = (int)result;
        if (result)
        {
            while (1)
            {
                if (*(_DWORD*)(v9 + 8) == 2)
                {
                    v14 = *(_DWORD*)(v4 + 3672);
                    if (v14)
                    {
                        if (v14 == 1)
                        {
                            v16 = *(float*)(v4 + 3632) - (double) * (int*)(v4 + 2284);
                            v19 = *(float*)(v4 + 3636) - (double) * (int*)(v4 + 2288);
                            if (v16 <= *(float*)& byte_587000[202404])
                            {
                                if (v16 >= -*(float*)& byte_587000[202404])
                                    v20 = *(float*)(v4 + 3632);
                                else
                                    v20 = *(float*)(v4 + 3632) - (*(float*)& byte_587000[202404] + v16) * 0.1;
                            }
                            else
                            {
                                v20 = *(float*)(v4 + 3632) - (v16 - *(float*)& byte_587000[202404]) * 0.1;
                            }
                            if (v19 > (double) * (float*)& byte_587000[202404])
                            {
                                v17 = v19 - *(float*)& byte_587000[202404];
                                goto LABEL_65;
                            }
                            if (-*(float*)& byte_587000[202404] <= v19)
                            {
                                v21 = *(float*)(v4 + 3636);
                            }
                            else
                            {
                                v17 = *(float*)& byte_587000[202404] + v19;
                                LABEL_65:
                                v21 = *(float*)(v4 + 3636) - v17 * 0.1;
                            }
                            if (sub_517590(v20, v21))
                            {
                                *(float*)(v4 + 3632) = v20;
                                *(float*)(v4 + 3636) = v21;
                            }
                            v1 = a1;
                            goto LABEL_72;
                        }
                    }
                    else
                    {
                        v15 = *(_DWORD*)(v4 + 3692);
                        *(_DWORD*)(v4 + 3688) = 1;
                        if (!v15)
                            sub_4E60E0(v4);
                        *(_DWORD*)(v9 + 16) = 0;
                    }
                    goto LABEL_72;
                }
                if (*(_DWORD*)(v9 + 8) != 6)
                {
                    if (*(_DWORD*)(v9 + 8) != 7)
                        goto LABEL_72;
                    if (!sub_4DDF30(v1) && !sub_40A5C0(4096))
                    {
                        a1a.field_0 = *(float*)(v4 + 3632) - 100.0;
                        a1a.field_4 = *(float*)(v4 + 3636) - 100.0;
                        a1a.field_8 = *(float*)(v4 + 3632) + 100.0;
                        v10 = *(float*)(v4 + 3636) + 100.0;
                        *(_DWORD*)& byte_5D4594[1565612] = 0;
                        *(_DWORD*)& byte_5D4594[1565608] = 1287568416;
                        *(_DWORD*)& byte_5D4594[1565604] = v1;
                        a1a.field_C = v10;
                        sub_517C10(&a1a, sub_4E6800, v4 + 3632);
                        if (*(_DWORD*)& byte_5D4594[1565612] && *(_DWORD*)& byte_5D4594[1565612] != *(_DWORD*)(v4 + 3628))
                        {
                            sub_4E6060(*(_DWORD*)(v4 + 2056), *(int*)& byte_5D4594[1565612]);
                            *(_DWORD*)(v4 + 3672) = 0;
                        }
                        else
                        {
                            sub_4E6040(*(_DWORD*)(v4 + 2056));
                            *(_DWORD*)(v4 + 3672) = 1;
                        }
                        goto LABEL_72;
                    }
                }
                if (*(_DWORD*)& byte_5D4594[2650652]
                    && sub_40A5C0(49152)
                    && !sub_509CF0((const char*)(v4 + 2096), *(_BYTE*)(v4 + 2251), *(_DWORD*)(v4 + 2068)))
                {
                    sub_4DA0F0(*(unsigned __int8*)(v4 + 2064), 17, 0);
                    *(_DWORD*)(v9 + 16) = 0;
                    goto LABEL_72;
                }
                if (*(_BYTE*)(v4 + 3680) & 0x20)
                    goto LABEL_45;
                if (sub_40A5C0(4096))
                    break;
                if (sub_40A740()
                    || sub_40A5C0(0x8000)
                    || (v12 = *(_DWORD*)(v4 + 3680), BYTE1(v12) & 1) && (v13 = sub_40A8A0(), v13))
                {
                    v11 = sub_40AA70(v4) == 0;
                    LABEL_44:
                    if (v11)
                    {
                        LABEL_45:
                        sub_4E60E0(v4);
                        *(_DWORD*)(v9 + 16) = 0;
                        goto LABEL_72;
                    }
                }
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000 && v1 == *(_DWORD*)& byte_5D4594[3843628])
                    goto LABEL_52;
                if (!sub_4DDF30(v1))
                {
                    sub_4DF3C0(v4);
                    sub_4E6AA0(v4);
                    sub_4E6040(v1);
                    if (!sub_40A5C0(4096))
                    {
                        sub_4F7AB0(&v22, *(_DWORD*)(v4 + 2056));
                        sub_4E7010(*(_DWORD*)(v4 + 2056), &v22);
                    }
                    LABEL_52:
                    *(_DWORD*)(v9 + 16) = 0;
                    goto LABEL_72;
                }
                sub_4DDEF0(v1);
                *(_DWORD*)(v9 + 16) = 0;
                LABEL_72:
                result = sub_51ABC0(*(unsigned __int8*)(v4 + 2064));
                v9 = (int)result;
                if (!result)
                    goto LABEL_73;
            }
            if (!*(_DWORD*)(v18[69] + 4792))
            {
                if (v18[138] == 1)
                {
                    sub_4DA2C0(a1, "MainBG.wnd:Loading", 0);
                }
                else
                {
                    *(_DWORD*)(v18[69] + 4792) = sub_4E4100();
                    if (*(_DWORD*)(v18[69] + 4792) == 1)
                        sub_4D79C0(a1);
                    else
                        sub_4DA2C0(a1, "GeneralPrint:QuestGameFull", 0);
                }
                v1 = a1;
            }
            if (v18[79])
            {
                sub_4D7480(v1);
                goto LABEL_72;
            }
            if (v18[78])
                goto LABEL_45;
            v11 = *(_DWORD*)(v18[69] + 4792) == 0;
            goto LABEL_44;
        }
        LABEL_73:
        *(_DWORD*)(v4 + 3692) = *(_DWORD*)(v4 + 3688);
    }
    return result;
}
// 4E65F4: variable 'v13' is possibly undefined

//----- (004E6800) --------------------------------------------------------
void __cdecl sub_4E6800(float* a1, int a2)
{
    int v2; // eax
    double v3; // st7
    double v4; // st6
    double v5; // st5

    if ((_BYTE)a1[2] & 2)
    {
        v2 = *((_DWORD*)a1 + 127);
        if (v2)
        {
            if (v2 == *(_DWORD*)& byte_5D4594[1565604])
            {
                v3 = a1[14] - *(float*)a2;
                v4 = a1[15] - *(float*)(a2 + 4);
                v5 = v4 * v4 + v3 * v3;
                if (v5 < *(float*)& byte_5D4594[1565608])
                {
                    *(_DWORD*)& byte_5D4594[1565612] = a1;
                    *(float*)& byte_5D4594[1565608] = v5;
                }
            }
        }
    }
}

//----- (004E6860) --------------------------------------------------------
int __cdecl sub_4E6860(int a1, int a2, int a3)
{
    int v3; // edi
    int v4; // eax
    int v5; // ebp
    int i; // esi
    int v8; // eax
    unsigned int v9; // edx
    int v10; // eax
    int v12; // ecx
    int v13; // [esp+Ch] [ebp+4h]

    v3 = a1;
    if (a1)
    {
        v4 = *(_DWORD*)(a1 + 2056);
        if (v4)
        {
            v5 = *(_DWORD*)(a1 + 2056);
            v13 = *(_DWORD*)(v4 + 748);
            if (!a3 && sub_4FC2B0(v5) == 1)
                return 0;
            if (*(int(__cdecl * *)(_DWORD*))(v5 + 744) == sub_4FAB20)
                return 0;
            if (sub_40A5C0(112))
            {
                if (!*(_DWORD*)& byte_5D4594[1565620])
                    * (_DWORD*)& byte_5D4594[1565620] = sub_4E3AA0((CHAR*)& byte_587000[202480]);
                if (!*(_DWORD*)& byte_5D4594[1565616])
                    * (_DWORD*)& byte_5D4594[1565616] = sub_4E3AA0((CHAR*)& byte_587000[202488]);
                for (i = *(_DWORD*)(*(_DWORD*)(v3 + 2056) + 516); i; i = *(_DWORD*)(i + 512))
                {
                    v8 = *(unsigned __int16*)(i + 4);
                    if ((unsigned __int16)v8 == *(_DWORD*)& byte_5D4594[1565620])
                    {
                        sub_4ED5E0(*(_DWORD*)(v3 + 2056), i, (int*)(*(_DWORD*)(v3 + 2056) + 56));
                    }
                    else if (v8 == *(_DWORD*)& byte_5D4594[1565616])
                    {
                        v9 = *(_DWORD*)(i + 16) & 0xFFFFFFBF;
                        *(_DWORD*)(i + 520) = 0;
                        *(_DWORD*)(i + 16) = v9;
                        sub_4EC300(i);
                        sub_4E8290(1, 0);
                    }
                    else if (*(_DWORD*)(i + 8) & 0x10000000)
                    {
                        sub_4ED790(*(_DWORD*)(v3 + 2056), (_DWORD*)i, (float2*)(*(_DWORD*)(v3 + 2056) + 56));
                    }
                }
            }
            if (sub_4DDF30(*(_DWORD*)(v3 + 2056)))
                sub_4DDEF0(*(_DWORD*)(v3 + 2056));
            sub_4174F0(v3, 1);
            v10 = sub_40A8A0();
            if (!v10 && !sub_40A5C0(4096))
            {
                sub_40A1F0(0);
                sub_416E50(1);
                sub_417D00();
                sub_40A970();
            }
            sub_4DA0F0(*(unsigned __int8*)(v3 + 2064), 12, (int*)& a2);
            sub_4FF380(v5, 0, 0, 5);
            v12 = *(_DWORD*)(v5 + 56);
            *(_DWORD*)(v5 + 16) |= 0x40u;
            *(_DWORD*)(v3 + 3632) = v12;
            *(_DWORD*)(v3 + 3636) = *(_DWORD*)(v5 + 60);
            sub_4E6040(v5);
            if (sub_40A5C0(2048))
            {
                *(_DWORD*)(v3 + 3672) = 1;
                *(_DWORD*)(v3 + 3628) = 0;
            }
            else if (sub_40A5C0(64))
            {
                if (!a3)
                    sub_4E60E0(v3);
            }
            sub_4E5AD0(v5);
            *(_BYTE*)(v13 + 244) = 0;
            *(_DWORD*)(v5 + 744) = sub_4E62F0;
            sub_4D7E50(v5);
        }
    }
    return 1;
}
// 4E69B8: variable 'v10' is possibly undefined
// 4E69DB: variable 'v11' is possibly undefined

//----- (004E6AA0) --------------------------------------------------------
void __cdecl sub_4E6AA0(int a1)
{
    int v1; // esi
    int v2; // edx
    int v3; // eax
    _DWORD* i; // esi

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 2056);
        if (v1)
        {
            if (*(int(__cdecl * *)(_DWORD*))(v1 + 744) != sub_4FAB20)
            {
                sub_417530(a1, 289);
                sub_4FF5B0(v1, 0);
                v2 = *(_DWORD*)(v1 + 16);
                *(_DWORD*)(v1 + 744) = sub_4F8100;
                *(_DWORD*)(v1 + 16) = v2 & 0xFFFFFFBF;
                sub_4E8020(*(_DWORD*)(a1 + 2056));
                if (sub_40A5C0(16))
                {
                    if (sub_417DA0(4))
                    {
                        v3 = *((_DWORD*)sub_418AB0(*(unsigned __int8*)(*(_DWORD*)(a1 + 2056) + 52)) + 19);
                        if (v3)
                        {
                            if (!*(_DWORD*)(v3 + 492))
                                sub_4F3400(*(_DWORD*)(a1 + 2056), v3, 1);
                        }
                    }
                }
                if (sub_40A5C0(49152) && !sub_509D80(a1))
                    sub_509C30(a1);
                if (sub_40A5C0(4096))
                {
                    for (i = (_DWORD*)sub_4DA7C0(); i; i = (_DWORD*)sub_4DA7F0((int)i))
                    {
                        if (*(_DWORD*)(*(_DWORD*)(i[187] + 276) + 4792) == 1)
                            sub_4D8F90(*(unsigned __int8*)(a1 + 2064), i);
                    }
                }
            }
        }
    }
}

//----- (004E6BD0) --------------------------------------------------------
BOOL __cdecl sub_4E6BD0(int a1)
{
    return *(_DWORD*)(a1 + 556) && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a1 + 536)) <= 1;
}

//----- (004E6C00) --------------------------------------------------------
long double __cdecl sub_4E6C00(int a1, int a2)
{
    double v2; // st7
    double v3; // st6
    int v4; // edx
    long double v5; // st5
    long double result; // st7
    double v7; // st6
    int v8; // eax
    double v9; // st6
    float v10; // [esp+4h] [ebp+4h]
    float v11; // [esp+4h] [ebp+4h]

    v2 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
    v3 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
    v4 = *(_DWORD*)(a1 + 172);
    v5 = sqrt(v3 * v3 + v2 * v2);
    result = v5;
    if (v4 == 2)
    {
        result = v5 - *(float*)(a1 + 176);
    }
    else if (v4 == 3)
    {
        v7 = *(float*)(a1 + 184) * 0.5;
        v10 = *(float*)(a1 + 188) * 0.5;
        if (v7 <= v10)
            v7 = v10;
        result = v5 - v7;
    }
    v8 = *(_DWORD*)(a2 + 172);
    if (v8 == 2)
    {
        result = result - *(float*)(a2 + 176);
    }
    else if (v8 == 3)
    {
        v9 = *(float*)(a2 + 184) * 0.5;
        v11 = *(float*)(a2 + 188) * 0.5;
        if (v9 <= v11)
            v9 = v11;
        result = result - v9;
    }
    if (result < 0.0099999998)
        result = 0.0099999998;
    return result;
}

//----- (004E6CE0) --------------------------------------------------------
int __cdecl sub_4E6CE0(float2* a1, float2* a2)
{
    double v2; // st7
    int v3; // ecx
    int v4; // eax
    int v5; // ecx
    int v6; // eax
    int result; // eax

    *(float*)& byte_5D4594[1565628] = a2->field_0 - a1->field_0;
    *(float*)& byte_5D4594[1565632] = a2->field_4 - a1->field_4;
    *(float*)& byte_5D4594[1565652] = *(float*)& byte_5D4594[1565628] * 0.41304299 - *(float*)& byte_5D4594[1565632];
    v2 = *(float*)& byte_5D4594[1565628] * 2.4210529 - *(float*)& byte_5D4594[1565632];
    *(float*)& byte_5D4594[1565656] = v2;
    *(float*)& byte_5D4594[1565636] = *(float*)& byte_5D4594[1565628] * -2.4210529 - *(float*)& byte_5D4594[1565632];
    *(float*)& byte_5D4594[1567708] = *(float*)& byte_5D4594[1565628] * -0.41304299 - *(float*)& byte_5D4594[1565632];
    if (*(float*)& byte_5D4594[1565652] < 0.0)
        v3 = 0;
    else
        v3 = 8;
    if (v2 < 0.0)
        v4 = 0;
    else
        v4 = 4;
    v5 = v4 | v3;
    if (*(float*)& byte_5D4594[1565636] < 0.0)
        v6 = 0;
    else
        v6 = 2;
    *(_DWORD*)& byte_5D4594[1565640] = (*(float*)& byte_5D4594[1567708] >= 0.0) | v6 | v5;
    switch (*(_DWORD*)& byte_5D4594[1565640])
    {
        case 0:
            result = 2;
            break;
        case 2:
            result = 6;
            break;
        case 3:
            result = 4;
            break;
        case 4:
            result = 10;
            break;
        case 0xB:
            result = 5;
            break;
        case 0xC:
            result = 8;
            break;
        case 0xD:
            result = 9;
            break;
        case 0xF:
            result = 1;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

//----- (004E6E50) --------------------------------------------------------
int __cdecl sub_4E6E50(float2* a1, int a2, float2* a3)
{
    int v3; // esi
    int v5[2]; // [esp+4h] [ebp-8h]

    sub_509E20(a2, (int2*)v5);
    v3 = v5[1] + v5[0] + 2 * v5[1] + 4;
    return *(_DWORD*)& byte_587000[4 * (sub_4E6CE0(a1, a3) + 16 * v3) + 202504];
}

//----- (004E6EA0) --------------------------------------------------------
int __cdecl sub_4E6EA0(int a1, float a2, int a3)
{
    int result; // eax

    result = a3;
    if (a3)
    {
        *(_DWORD*)& byte_5D4594[1565648] = 0;
        *(float*)& byte_5D4594[1565644] = a2 * a2;
        *(_DWORD*)(a3 + 36) = a1;
        sub_517F90((float2*)(a1 + 56), a2, sub_4E6EF0, a3);
        result = *(_DWORD*)& byte_5D4594[1565648];
    }
    return result;
}

//----- (004E6EF0) --------------------------------------------------------
void __cdecl sub_4E6EF0(int a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // ecx
    int v4; // eax
    int v5; // eax
    int v6; // esi
    double v7; // st7
    double v8; // st6
    double v9; // st5

    if (!(*(_BYTE*)(a1 + 16) & 0x20)
        && !sub_4EC520(a1, a2[9])
        && (!(*(_BYTE*)(a1 + 8) & 4) || !(*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 3680) & 1))
        && (!a2[2] || sub_5330C0(a2[9], a1)))
    {
        if (sub_4E6E50((float2*)(a2[9] + 56), *(__int16*)(a2[9] + 124), (float2*)(a1 + 56)) & *a2)
        {
            v2 = a2[9];
            if (a1 != v2 && (!a2[1] || sub_5370E0(v2, a1, 0)))
            {
                v3 = *(_DWORD*)(a1 + 8);
                if (a2[3] & v3)
                {
                    v4 = *(_DWORD*)(a1 + 16);
                    if (a2[7] & v4)
                    {
                        if (!(v3 & a2[4]) && !(v4 & a2[8]))
                        {
                            v5 = *(_DWORD*)(a1 + 12);
                            if (!v5 || v5 & a2[5] && !(v5 & a2[6]))
                            {
                                v6 = a2[9];
                                v7 = *(float*)(a1 + 56) - *(float*)(v6 + 56);
                                v8 = *(float*)(a1 + 60) - *(float*)(v6 + 60);
                                v9 = v8 * v8 + v7 * v7;
                                if (v9 < *(float*)& byte_5D4594[1565644])
                                {
                                    *(float*)& byte_5D4594[1565644] = v9;
                                    *(_DWORD*)& byte_5D4594[1565648] = a1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//----- (004E7010) --------------------------------------------------------
void __cdecl sub_4E7010(int a1, float2* a2)
{
    int v2; // edi
    int v3; // ecx
    int v4; // eax
    char v5[5]; // [esp+4h] [ebp-8h]

    if (a1 && !(*(_DWORD*)(a1 + 8) & 0x400000))
    {
        if ((__int64) * (float*)(a1 + 56) != (__int64)a2->field_0 || (__int64) * (float*)(a1 + 60) != (__int64)a2->field_4)
            sub_4E44F0(a1);
        *(float2*)(a1 + 64) = *a2;
        *(float2*)(a1 + 56) = *a2;
        *(float2*)(a1 + 72) = *a2;
        sub_517970(a1);
        if (*(_DWORD*)(a1 + 696))
            sub_537610(a1);
        if (*(_BYTE*)(a1 + 8) & 6)
            sub_537540(a1);
        if (*(_BYTE*)(a1 + 8) & 2)
            sub_5346D0(a1);
        sub_4FD090(a1);
        if (*(_BYTE*)(a1 + 8) & 6)
            sub_5281D0();
        if (*(_BYTE*)(a1 + 8) & 4 && sub_40A5C0(0x2000))
        {
            v2 = *(_DWORD*)(a1 + 748);
            v3 = *(_DWORD*)(v2 + 276);
            *(_DWORD*)(v2 + 272) = *(_DWORD*)& byte_5D4594[2598000];
            sub_4DE4D0(*(_BYTE*)(v3 + 2064));
            v5[0] = -22;
            *(_DWORD*)& v5[1] = *(_DWORD*)& byte_5D4594[2598000];
            sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (int)v5, 5, 0, 0);
        }
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v4 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
            if (!*(_DWORD*)(v4 + 3628) && !(*(_BYTE*)(v4 + 3680) & 3))
            {
                *(_DWORD*)(v4 + 3632) = *(_DWORD*)(a1 + 56);
                *(_DWORD*)(v4 + 3636) = *(_DWORD*)(a1 + 60);
            }
        }
    }
}

//----- (004E7190) --------------------------------------------------------
void __cdecl sub_4E7190(_BYTE* a1, float* a2)
{
    if (!sub_4FF350((int)a1, 14)
        && !(a1[16] & 2)
        && (!sub_40A5C0(4096) || !(a1[8] & 2) || !(a1[12] & 8))
        && (sub_40A5C0(2048) || a1[8] & 6))
    {
        sub_4E7010((int)a1, (float2*)a2);
    }
}

//----- (004E71F0) --------------------------------------------------------
void __cdecl sub_4E71F0(int a1)
{
    int* v1; // esi
    int v2; // eax
    int v3; // ecx
    int v4[3]; // [esp+8h] [ebp-34h]
    int v5[10]; // [esp+14h] [ebp-28h]

    v5[5] = -1;
    v5[7] = -1;
    v1 = *(int**)(a1 + 748);
    v5[0] = 15;
    v5[1] = 1;
    v5[2] = 0;
    v5[3] = 6;
    v5[4] = 0;
    v5[6] = 0;
    v5[8] = 32800;
    v2 = sub_4E6EA0(a1, 50.0, (int)v5);
    if (v2)
    {
        v3 = v1[4];
        v4[0] = v2;
        sub_4FD400(v1[3], v1[2], (_DWORD*)* v1, *v1, v4, v3);
    }
    sub_4E5CC0(a1);
}

//----- (004E7290) --------------------------------------------------------
int __cdecl sub_4E7290(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // edx
    int v4; // ecx

    result = a1;
    switch (*(_DWORD*)(a1 + 172))
    {
        case 1:
            v2 = *(_DWORD*)(a1 + 56);
            *(_DWORD*)(a1 + 232) = v2;
            v3 = v2;
            v4 = *(_DWORD*)(a1 + 60);
            *(_DWORD*)(a1 + 240) = v3;
            *(_DWORD*)(a1 + 236) = v4;
            *(_DWORD*)(a1 + 244) = v4;
            break;
        case 2:
            *(float*)(a1 + 232) = *(float*)(a1 + 56) - *(float*)(a1 + 176);
            *(float*)(a1 + 236) = *(float*)(a1 + 60) - *(float*)(a1 + 176);
            *(float*)(a1 + 240) = *(float*)(a1 + 176) + *(float*)(a1 + 56);
            *(float*)(a1 + 244) = *(float*)(a1 + 176) + *(float*)(a1 + 60);
            break;
        case 3:
            *(float*)(a1 + 232) = *(float*)(a1 + 200) + *(float*)(a1 + 56);
            *(float*)(a1 + 236) = *(float*)(a1 + 196) + *(float*)(a1 + 60);
            *(float*)(a1 + 240) = *(float*)(a1 + 208) + *(float*)(a1 + 56);
            *(float*)(a1 + 244) = *(float*)(a1 + 220) + *(float*)(a1 + 60);
            break;
    }
    return result;
}

//----- (004E7350) --------------------------------------------------------
int __cdecl sub_4E7350(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // edx
    int v4; // ecx

    result = a1;
    switch (*(_DWORD*)(a1 + 172))
    {
        case 1:
            v2 = *(_DWORD*)(a1 + 64);
            *(_DWORD*)(a1 + 232) = v2;
            v3 = v2;
            v4 = *(_DWORD*)(a1 + 68);
            *(_DWORD*)(a1 + 240) = v3;
            *(_DWORD*)(a1 + 236) = v4;
            *(_DWORD*)(a1 + 244) = v4;
            break;
        case 2:
            *(float*)(a1 + 232) = *(float*)(a1 + 64) - *(float*)(a1 + 176);
            *(float*)(a1 + 236) = *(float*)(a1 + 68) - *(float*)(a1 + 176);
            *(float*)(a1 + 240) = *(float*)(a1 + 176) + *(float*)(a1 + 64);
            *(float*)(a1 + 244) = *(float*)(a1 + 176) + *(float*)(a1 + 68);
            break;
        case 3:
            *(float*)(a1 + 232) = *(float*)(a1 + 200) + *(float*)(a1 + 64);
            *(float*)(a1 + 236) = *(float*)(a1 + 196) + *(float*)(a1 + 68);
            *(float*)(a1 + 240) = *(float*)(a1 + 208) + *(float*)(a1 + 64);
            *(float*)(a1 + 244) = *(float*)(a1 + 220) + *(float*)(a1 + 68);
            break;
    }
    return result;
}

//----- (004E7410) --------------------------------------------------------
BOOL __cdecl sub_4E7410(int a1)
{
    if (*(_BYTE*)(a1 + 16) & 0x40)
        return 1;
    sub_4E7290(a1);
    return *(float*)(a1 + 240) - *(float*)(a1 + 232) < 85.0 && *(float*)(a1 + 244) - *(float*)(a1 + 236) < 85.0;
}

//----- (004E7470) --------------------------------------------------------
void __cdecl sub_4E7470(int a1, int a2)
{
    const char* v2; // eax
    unsigned __int8* v3; // edi
    int v4; // eax
    int v5; // edx
    unsigned __int8* v6; // esi
    unsigned __int8* v7; // ecx
    int v8; // ebx
    char* result; // eax
    int v10; // edi
    int i; // ebx
    _DWORD* v12; // esi
    float2 a3; // [esp+Ch] [ebp-8h]

    v2 = (const char*)sub_4E39D0(a1);
    v3 = &byte_587000[203080];
    if (strncmp(v2, "Barrel", 6u))
        v3 = &byte_587000[203240];
    v4 = sub_415FA0(0, 99);
    v5 = 0;
    if (*(_DWORD*)v3)
    {
        v6 = v3;
        v7 = v3;
        do
        {
            if (*((_DWORD*)v6 + 2) > v4)
                break;
            v8 = *((_DWORD*)v7 + 3);
            v7 += 12;
            ++v5;
            v6 = v7;
        } while (v8);
    }
    result = *(char**)& v3[12 * v5];
    v10 = (int)& v3[12 * v5];
    if (result)
    {
        result = *(char**)(v10 + 4);
        for (i = 0; i < (int)result; ++i)
        {
            v12 = sub_4E3810(*(CHAR * *)v10);
            if (v12)
            {
                sub_4ED970(35.0, (float2*)a2, &a3);
                sub_4DAA50((int)v12, 0, a3.field_0, a3.field_4);
            }
            result = *(char**)(v10 + 4);
        }
    }
}

//----- (004E7540) --------------------------------------------------------
void __cdecl sub_4E7540(int a1, int a2)
{
    int v3; // eax

    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 4 && *(_BYTE*)(a2 + 8) & 4 && a1 != a2)
            {
                v3 = *(_DWORD*)(a2 + 748);
                *(_DWORD*)(*(_DWORD*)(v3 + 276) + 3604) = *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
                *(_DWORD*)(*(_DWORD*)(v3 + 276) + 3608) = *(_DWORD*)& byte_5D4594[2598000];
                *(_DWORD*)(*(_DWORD*)(v3 + 276) + 3600) = 1;
            }
        }
    }
}

//----- (004E75B0) --------------------------------------------------------
char __cdecl sub_4E75B0(int a1)
{
    int v1; // eax
    int v2; // eax

    if (!(*(_DWORD*)(a1 + 16) & 0x1000000))
    {
        v1 = *(_DWORD*)(a1 + 8);
        if (v1 & 0x4000)
            sub_501960(235, a1, 0, 0);
    }
    sub_4E4670(a1, 1);
    v2 = *(_DWORD*)(a1 + 8);
    if (v2 & 0x10042000)
        * (_DWORD*)(a1 + 16) &= 0xFFFFFFBF;
    if (!(v2 & 1))
        LOBYTE(v2) = sub_537610(a1);
    return v2;
}

//----- (004E7600) --------------------------------------------------------
int __cdecl sub_4E7600(int a1)
{
    int v1; // eax
    int result; // eax

    if (*(_DWORD*)(a1 + 16) & 0x1000000)
    {
        v1 = *(_DWORD*)(a1 + 8);
        if (v1 & 0x4000)
            sub_501960(236, a1, 0, 0);
    }
    sub_4E4670(a1, 0);
    result = *(_DWORD*)(a1 + 8);
    if (result & 0x10042000)
    {
        result = *(_DWORD*)(a1 + 16);
        LOBYTE(result) = result | 0x40;
        *(_DWORD*)(a1 + 16) = result;
    }
    return result;
}

//----- (004E7650) --------------------------------------------------------
char __cdecl sub_4E7650(int a1)
{
    char result; // al

    if ((*(_DWORD*)(a1 + 16) & 0x1000000) == 0x1000000)
        result = sub_4E7600(a1);
    else
        result = sub_4E75B0(a1);
    return result;
}

//----- (004E7680) --------------------------------------------------------
int __cdecl sub_4E7680(int a1)
{
    int result; // eax

    for (result = a1; *(_WORD*)(a1 + 124) < 0; *(_WORD*)(a1 + 124) += 256)
        ;
    for (; *(_WORD*)(a1 + 124) >= 256; *(_WORD*)(a1 + 124) -= 256)
        ;
    return result;
}

//----- (004E76C0) --------------------------------------------------------
int sub_4E76C0()
{
    int v0; // edi
    int result; // eax
    int i; // esi

    v0 = 0;
    result = sub_4DA790();
    for (i = result; result; i = result)
    {
        nullsub_25(i);
        v0 ^= sub_4E7700(i);
        result = sub_4DA7A0(i);
    }
    return result;
}
// 4E76F0: using guessed type void __cdecl nullsub_25(_DWORD);

//----- (004E7700) --------------------------------------------------------
int __cdecl sub_4E7700(int a1)
{
    unsigned __int16* v1; // ecx
    int result; // eax

    v1 = *(unsigned __int16**)(a1 + 556);
    result = *(_DWORD*)(a1 + 340) ^ *(_DWORD*)(a1 + 248) ^ *(_DWORD*)(a1 + 120) ^ *(_DWORD*)(a1 + 128) ^ *(_DWORD*)(a1 + 132) ^ *(_DWORD*)(a1 + 136) ^ *(_DWORD*)(a1 + 148) ^ *(_DWORD*)(a1 + 152) ^ *(__int16*)(a1 + 124) ^ *(__int16*)(a1 + 126) ^ *(_DWORD*)(a1 + 108) ^ *(_DWORD*)(a1 + 104) ^ *(_DWORD*)(a1 + 100) ^ *(_DWORD*)(a1 + 96) ^ *(_DWORD*)(a1 + 92) ^ *(_DWORD*)(a1 + 88) ^ *(_DWORD*)(a1 + 84) ^ *(_DWORD*)(a1 + 80) ^ *(_DWORD*)(a1 + 76) ^ *(_DWORD*)(a1 + 72) ^ *(_DWORD*)(a1 + 68) ^ *(_DWORD*)(a1 + 64) ^ *(_DWORD*)(a1 + 60) ^ *(_DWORD*)(a1 + 16) ^ *(_DWORD*)(a1 + 20) ^ *(_DWORD*)(a1 + 36) ^ *(_DWORD*)(a1 + 40) ^ *(_DWORD*)(a1 + 44) ^ *(_DWORD*)(a1 + 56) ^ *(unsigned __int16*)(a1 + 4) ^ *(unsigned __int8*)(a1 + 52);
    if (v1)
        result ^= *v1 ^ v1[1] ^ v1[2];
    return result;
}

//----- (004E77E0) --------------------------------------------------------
wchar_t* __cdecl sub_4E77E0(int a1)
{
    int v1; // eax
    _DWORD* v2; // edi
    _DWORD* v3; // eax
    _DWORD* v4; // ebx
    wchar_t* v5; // eax
    int v7; // eax
    const wchar_t* v8; // eax
    int v9; // eax
    int v10; // eax
    wchar_t* v11; // eax
    int v12; // [esp-4h] [ebp-10h]

    v1 = *(_DWORD*)(a1 + 8);
    if (v1 & 0x13001000)
    {
        v2 = *(_DWORD * *)(a1 + 692);
        if (v1 & 0x11001000)
            v3 = sub_413250(*(unsigned __int16*)(a1 + 4));
        else
            v3 = sub_413270(*(unsigned __int16*)(a1 + 4));
        v4 = v3;
        if (!v3)
        {
            v12 = sub_4E39D0(a1);
            v5 = loadString_sub_40F1D0((char*)& byte_587000[203812], 0, "C:\\NoxPost\\src\\Server\\Object\\objutil.c", 983);
            nox_swprintf((wchar_t*)& byte_5D4594[1565660], v5, v12);
            return (wchar_t*)& byte_5D4594[1565660];
        }
        nox_wcscpy((wchar_t*)& byte_5D4594[1565660], (const wchar_t*)& byte_5D4594[1567732]);
        if (*v2 && *(_DWORD*)(*v2 + 8))
        {
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], *(const wchar_t**)(*v2 + 8));
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], L" ");
        }
        v7 = v2[1];
        if (v7)
        {
            v8 = *(const wchar_t**)(v7 + 8);
            if (v8)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1565660], v8);
                nox_wcscat((wchar_t*)& byte_5D4594[1565660], L" ");
            }
        }
        if (v4[2])
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], (const wchar_t*)v4[2]);
        v9 = v2[2];
        if (v9 && *(_DWORD*)(v9 + 8))
        {
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], L" ");
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], *(const wchar_t**)(v2[2] + 8));
        }
        v10 = v2[3];
        if (v10 && *(_DWORD*)(v10 + 12))
        {
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], L" ");
            nox_wcscat((wchar_t*)& byte_5D4594[1565660], *(const wchar_t**)(v2[3] + 12));
            return (wchar_t*)& byte_5D4594[1565660];
        }
    }
    else
    {
        v11 = loadString_sub_40F1D0((char*)& byte_587000[203876], 0, "C:\\NoxPost\\src\\Server\\Object\\objutil.c", 1032);
        nox_wcscpy((wchar_t*)& byte_5D4594[1565660], v11);
    }
    return (wchar_t*)& byte_5D4594[1565660];
}

//----- (004E7980) --------------------------------------------------------
int __cdecl sub_4E7980(int a1)
{
    return *(_DWORD*)(a1 + 504);
}

//----- (004E7990) --------------------------------------------------------
int __cdecl sub_4E7990(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 496);
    else
        result = 0;
    return result;
}

//----- (004E79B0) --------------------------------------------------------
int __cdecl sub_4E79B0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1567712] = a1;
    return result;
}

//----- (004E79C0) --------------------------------------------------------
char __cdecl sub_4E79C0(int a1, int a2)
{
    int v2; // eax
    int i; // esi

    v2 = *(_DWORD*)(a1 + 16);
    if (!(v2 & 2))
    {
        LOBYTE(v2) = v2 | 2;
        *(_DWORD*)(a1 + 16) = v2;
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            if (!*(_DWORD*)& byte_5D4594[1567712])
                * (_DWORD*)& byte_5D4594[1567712] = a2;
            sub_4D8270(a1);
            sub_4FA020((_DWORD*)a1, 13);
            sub_4E46F0(a1, 0.0);
            sub_50B510();
            for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512))
            {
                if (*(_BYTE*)(i + 8) & 2 && (*(_BYTE*)(*(_DWORD*)(i + 748) + 1440) & 0x80))
                    sub_4E79C0(i, a2);
            }
        }
        LOBYTE(v2) = *(_BYTE*)(a1 + 8);
        if (v2 & 2)
        {
            v2 = *(_DWORD*)(a1 + 16);
            if ((v2 & 0x8000) == 0)
                LOBYTE(v2) = (unsigned int)sub_50A260(a1, 0);
        }
    }
    return v2;
}

//----- (004E7A60) --------------------------------------------------------
char __cdecl sub_4E7A60(int a1, int a2)
{
    int v2; // eax
    int i; // esi

    v2 = *(_DWORD*)(a1 + 16);
    if (v2 & 2)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            LOBYTE(v2) = byte_5D4594[1567712];
            if (*(_DWORD*)& byte_5D4594[1567712] && !a2)
                return v2;
            *(_DWORD*)& byte_5D4594[1567712] = 0;
            *(_DWORD*)(a1 + 16) &= 0xFFFFFFFD;
            LOBYTE(v2) = sub_4D8270(a1);
            for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512))
            {
                if (*(_BYTE*)(i + 8) & 2)
                {
                    v2 = *(_DWORD*)(i + 748);
                    if (*(_BYTE*)(v2 + 1440) & 0x80)
                        LOBYTE(v2) = sub_4E7A60(i, a2);
                }
            }
        }
        else
        {
            LOBYTE(v2) = v2 & 0xFD;
            *(_DWORD*)(a1 + 16) = v2;
        }
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v2 = *(_DWORD*)(a1 + 16);
            if ((v2 & 0x8000) == 0)
                LOBYTE(v2) = sub_50A160(a1);
        }
    }
    return v2;
}

//----- (004E7B00) --------------------------------------------------------
void __cdecl sub_4E7B00(int a1, int a2)
{
    int v2; // ecx
    int v3; // edi

    if (a1)
    {
        if (a2)
        {
            v2 = *(_DWORD*)(a2 + 12);
            v3 = *(_DWORD*)(a1 + 748);
            LOBYTE(v2) = v2 | 0x80;
            *(_DWORD*)(a2 + 12) = v2;
            sub_4D9250(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), a2);
            sub_417190(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), a2, 1);
            sub_4EC290(a1, a2);
        }
    }
}

//----- (004E7B60) --------------------------------------------------------
void __cdecl sub_4E7B60(int a1, _DWORD* a2)
{
    int v2; // edi
    int v3; // edx

    v2 = *(_DWORD*)(a1 + 748);
    if (a1)
    {
        if (a2)
        {
            v3 = a2[3];
            LOBYTE(v3) = v3 & 0x7F;
            a2[3] = v3;
            sub_4D92A0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), a2);
            sub_417300(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (int)a2, 1);
            sub_4EC300((int)a2);
        }
    }
}

//----- (004E7BC0) --------------------------------------------------------
int __cdecl sub_4E7BC0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = (*(_DWORD*)(a1 + 8) >> 2) & 1;
    return result;
}

//----- (004E7BE0) --------------------------------------------------------
int __cdecl sub_4E7BE0(int a1)
{
    int v1; // eax
    int v2; // ecx

    v1 = *(_DWORD*)& byte_5D4594[1567716];
    if (!*(_DWORD*)& byte_5D4594[1567716])
    {
        v1 = sub_4E3AA0((CHAR*)& byte_587000[203892]);
        *(_DWORD*)& byte_5D4594[1567716] = v1;
    }
    v2 = *(_DWORD*)(a1 + 516);
    if (!v2)
        return 0;
    while (*(unsigned __int16*)(v2 + 4) != v1)
    {
        v2 = *(_DWORD*)(v2 + 512);
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (004E7C30) --------------------------------------------------------
int __cdecl sub_4E7C30(int a1)
{
    int v1; // eax
    int v2; // ecx

    v1 = *(_DWORD*)& byte_5D4594[1567720];
    if (!*(_DWORD*)& byte_5D4594[1567720])
    {
        v1 = sub_4E3AA0((CHAR*)& byte_587000[203900]);
        *(_DWORD*)& byte_5D4594[1567720] = v1;
    }
    v2 = *(_DWORD*)(a1 + 516);
    if (!v2)
        return 0;
    while (*(unsigned __int16*)(v2 + 4) != v1)
    {
        v2 = *(_DWORD*)(v2 + 512);
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (004E7C80) --------------------------------------------------------
int __cdecl sub_4E7C80(int a1, int a2)
{
    int result; // eax
    int i; // ecx

    result = 0;
    if (a1)
    {
        for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512))
        {
            if (*(unsigned __int16*)(i + 4) == a2 && !(*(_BYTE*)(i + 16) & 0x20))
                ++result;
        }
    }
    return result;
}

//----- (004E7CC0) --------------------------------------------------------
int __cdecl sub_4E7CC0(int a1, int a2)
{
    int result; // eax
    int i; // ecx

    result = 0;
    if (!a1 || !a2)
        return 0;
    for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512))
    {
        if (a2 & *(_DWORD*)(i + 8))
            ++result;
    }
    return result;
}

//----- (004E7CF0) --------------------------------------------------------
int __cdecl sub_4E7CF0(int a1, int a2, int a3)
{
    int result; // eax
    _DWORD* i; // ecx

    result = 0;
    if (!a1 || !a2 || !a3)
        return 0;
    for (i = *(_DWORD * *)(a1 + 516); i; i = (_DWORD*)i[128])
    {
        if (a2 & i[2])
        {
            if (a3 & i[3])
                ++result;
        }
    }
    return result;
}

//----- (004E7D30) --------------------------------------------------------
int __cdecl sub_4E7D30(int a1, int a2)
{
    int result; // eax
    int i; // ecx

    result = 0;
    if (a1)
    {
        for (i = *(_DWORD*)(a1 + 504); i; i = *(_DWORD*)(i + 496))
        {
            if (!a2 || *(unsigned __int16*)(i + 4) == a2 && !(*(_BYTE*)(i + 16) & 0x20))
                ++result;
        }
    }
    return result;
}

//----- (004E7D70) --------------------------------------------------------
int __cdecl sub_4E7D70(int a1, int a2)
{
    int result; // eax
    int i; // ecx

    result = 0;
    if (!a1 || !a2)
        return 0;
    for (i = *(_DWORD*)(a1 + 504); i; i = *(_DWORD*)(i + 496))
    {
        if (a2 & *(_DWORD*)(i + 8))
            ++result;
    }
    return result;
}

//----- (004E7DA0) --------------------------------------------------------
int __cdecl sub_4E7DA0(int a1, int a2, int a3)
{
    int result; // eax
    _DWORD* i; // ecx

    result = 0;
    if (!a1 || !a2 || !a3)
        return 0;
    for (i = *(_DWORD * *)(a1 + 504); i; i = (_DWORD*)i[124])
    {
        if (a2 & i[2])
        {
            if (a3 & i[3])
                ++result;
        }
    }
    return result;
}

//----- (004E7DE0) --------------------------------------------------------
int __cdecl sub_4E7DE0(int a1, int a2)
{
    int v2; // ebx
    _DWORD* v3; // eax
    int v4; // ecx
    int v5; // edx
    int v6; // eax
    bool v7; // zf

    if (!a1 || !a2 || *(_WORD*)(a1 + 4) != *(_WORD*)(a2 + 4))
        return 0;
    v2 = *(_DWORD*)(a1 + 8);
    if (v2 & 0x13001000)
    {
        v3 = *(_DWORD * *)(a1 + 692);
        v4 = 0;
        v5 = *(_DWORD*)(a2 + 692) - (_DWORD)v3;
        while (*v3 == *(_DWORD*)((char*)v3 + v5))
        {
            ++v4;
            ++v3;
            if (v4 >= 4)
                goto LABEL_8;
        }
        return 0;
    }
    LABEL_8:
    if (!(v2 & 0x100))
        return 1;
    v6 = *(_DWORD*)(a1 + 12);
    if (v6 & 1)
    {
        v7 = **(_BYTE * *)(a1 + 736) == **(_BYTE * *)(a2 + 736);
    }
    else
    {
        if (!(v6 & 2))
        {
            if (**(_BYTE * *)(a1 + 736) != **(_BYTE * *)(a2 + 736))
                return 0;
            return 1;
        }
        v7 = strcmp(*(const char**)(a1 + 736), *(const char**)(a2 + 736)) == 0;
    }
    if (!v7)
        return 0;
    return 1;
}

//----- (004E7EC0) --------------------------------------------------------
int __cdecl sub_4E7EC0(int a1, int a2)
{
    int v2; // esi

    if (!a1)
        return 0;
    if (!a2)
        return 0;
    v2 = *(_DWORD*)(a1 + 504);
    if (!v2)
        return 0;
    while (!sub_4E7DE0(v2, a2))
    {
        v2 = *(_DWORD*)(v2 + 496);
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (004E7F10) --------------------------------------------------------
char* __cdecl sub_4E7F10(int a1)
{
    char* result; // eax
    int i; // edi
    int v3; // eax
    int v4; // esi
    int v5; // eax

    *(_DWORD*)(a1 + 140) = 0;
    *(_DWORD*)(a1 + 144) = 0;
    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        v3 = *(_DWORD*)(i + 2056);
        v4 = 1 << *(_BYTE*)(i + 2064);
        if (v3)
        {
            if (sub_4E7F90(v3, a1) == 1)
            {
                v5 = v4 | *(_DWORD*)(a1 + 144);
                *(_DWORD*)(a1 + 140) |= v4;
                *(_DWORD*)(a1 + 144) = v5;
            }
        }
        result = sub_416EE0(i);
    }
    return result;
}

//----- (004E7F90) --------------------------------------------------------
int __cdecl sub_4E7F90(int a1, int a2)
{
    int v2; // ebx

    v2 = 0;
    if (!*(_DWORD*)& byte_5D4594[1567724])
        * (_DWORD*)& byte_5D4594[1567724] = sub_4E3AA0((CHAR*)& byte_587000[203912]);
    if (!a1 || !a2)
        return 0;
    if (!sub_5330C0(a1, a2))
        v2 = 1;
    if (sub_40A5C0(4096)
        && *(unsigned __int16*)(a2 + 4) == *(_DWORD*)& byte_5D4594[1567724]
        && *(_BYTE*)(a1 + 8) & 4
        && !*(_DWORD*)(a2 + 508))
    {
        v2 = 0;
    }
    return v2;
}

//----- (004E8020) --------------------------------------------------------
char* __cdecl sub_4E8020(int a1)
{
    char* result; // eax
    int v2; // ebx
    int v3; // eax
    int v4; // edi
    int v5; // edi
    int v6; // eax
    bool v7; // zf
    int v8; // eax

    result = sub_416EA0();
    v2 = (int)result;
    if (result)
    {
        while (1)
        {
            v3 = *(_DWORD*)(v2 + 2056);
            v4 = 1 << *(_BYTE*)(v2 + 2064);
            if (!v3)
                break;
            v7 = sub_4E7F90(v3, a1) == 1;
            v8 = *(_DWORD*)(a1 + 144);
            if (v7)
            {
                if (!(v8 & v4))
                {
                    *(_DWORD*)(a1 + 144) = v4 | v8;
                    goto LABEL_9;
                }
            }
            else if (v8 & v4)
            {
                *(_DWORD*)(a1 + 144) = v8 & ~v4;
                LABEL_9:
                v6 = v4 | *(_DWORD*)(a1 + 140);
                LABEL_10:
                *(_DWORD*)(a1 + 140) = v6;
                goto LABEL_11;
            }
            LABEL_11:
            result = sub_416EE0(v2);
            v2 = (int)result;
            if (!result)
                return result;
        }
        v5 = ~v4;
        v6 = v5 & *(_DWORD*)(a1 + 140);
        *(_DWORD*)(a1 + 144) &= v5;
        goto LABEL_10;
    }
    return result;
}

//----- (004E80C0) --------------------------------------------------------
int __cdecl sub_4E80C0(char a1)
{
    int result; // eax
    int v2; // esi
    int v3; // edx

    result = sub_4DA790();
    if (result)
    {
        v2 = ~(1 << a1);
        do
        {
            v3 = v2 & *(_DWORD*)(result + 140);
            *(_DWORD*)(result + 144) &= v2;
            *(_DWORD*)(result + 140) = v3;
            result = sub_4DA7A0(result);
        } while (result);
    }
    return result;
}

//----- (004E8110) --------------------------------------------------------
char* __cdecl sub_4E8110(int a1)
{
    int v1; // edi
    char* result; // eax
    char* v3; // ebx
    char* v4; // esi
    int v5; // ebp
    char v6; // al
    int v7; // ecx
    int v8; // eax
    bool v9; // zf
    int v10; // eax
    int v11; // ecx

    v1 = 1 << a1;
    result = sub_417090(a1);
    v3 = result;
    if (result)
    {
        result = (char*)sub_4DA790();
        v4 = result;
        if (result)
        {
            v5 = ~v1;
            do
            {
                v6 = v4[8];
                v7 = v5 & *((_DWORD*)v4 + 35);
                *((_DWORD*)v4 + 36) &= v5;
                *((_DWORD*)v4 + 35) = v7;
                if (!(v6 & 6))
                    goto LABEL_12;
                v8 = *((_DWORD*)v3 + 514);
                if (!v8)
                    goto LABEL_12;
                v9 = sub_4E7F90(v8, (int)v4) == 1;
                v10 = *((_DWORD*)v4 + 36);
                if (v9)
                {
                    if (!(v10 & v1))
                    {
                        v11 = v1 | v10;
                        LABEL_11:
                        *((_DWORD*)v4 + 36) = v11;
                        *((_DWORD*)v4 + 35) |= v1;
                        goto LABEL_12;
                    }
                }
                else if (v10 & v1)
                {
                    v11 = v5 & *((_DWORD*)v4 + 36);
                    goto LABEL_11;
                }
                LABEL_12:
                result = (char*)sub_4DA7A0((int)v4);
                v4 = result;
            } while (result);
        }
    }
    return result;
}

//----- (004E81D0) --------------------------------------------------------
int __cdecl sub_4E81D0(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1567728];
    if (!*(_DWORD*)& byte_5D4594[1567728])
    {
        result = sub_4E3AA0((CHAR*)& byte_587000[203920]);
        *(_DWORD*)& byte_5D4594[1567728] = result;
    }
    if (a1)
    {
        if (*(unsigned __int16*)(a1 + 4) == result)
        {
            result = *(_DWORD*)(a1 + 748);
            *(_DWORD*)(result + 4) = 0;
        }
    }
    return result;
}

//----- (004E8210) --------------------------------------------------------
int __cdecl sub_4E8210(int a1, int a2)
{
    float2* v2; // edi
    unsigned int v3; // esi
    int v4; // eax
    int v5; // ecx

    v2 = 0;
    v3 = 0;
    v4 = sub_4DA7C0();
    if (!v4)
        return 0;
    do
    {
        v5 = *(_DWORD*)(*(_DWORD*)(v4 + 748) + 308);
        if (v5)
        {
            if (**(_DWORD * *)(v5 + 700) > v3)
            {
                v3 = **(_DWORD * *)(v5 + 700);
                v2 = *(float2 * *)(*(_DWORD*)(v4 + 748) + 308);
            }
        }
        v4 = sub_4DA7F0(v4);
    } while (v4);
    if (!v2)
        return 0;
    *(_DWORD*)(*(_DWORD*)(a1 + 748) + 308) = v2;
    sub_4ED970(60.0, v2 + 7, (float2*)a2);
    return 1;
}

//----- (004E8290) --------------------------------------------------------
int __cdecl sub_4E8290(char a1, __int16 a2)
{
    byte_5D4594[1567736] = a1;
    *(_WORD*)& byte_5D4594[1567738] = a2;
    return sub_4D95F0(255, a1, a2);
}

//----- (004E82C0) --------------------------------------------------------
int __cdecl sub_4E82C0(unsigned __int8 a1, char a2, char a3, __int16 a4)
{
    int v4; // eax

    v4 = 6 * a1;
    byte_5D4594[v4 + 1567740] = a1;
    byte_5D4594[v4 + 1567741] = a3;
    byte_5D4594[v4 + 1567742] = a2;
    *(_WORD*)& byte_5D4594[v4 + 1567744] = a4;
    return sub_4D95A0(255, a1, a2, a3, a4);
}

//----- (004E8310) --------------------------------------------------------
char* sub_4E8310()
{
    return (char*)& byte_5D4594[1567736];
}

//----- (004E8320) --------------------------------------------------------
unsigned __int8* __cdecl sub_4E8320(unsigned __int8 a1)
{
    return &byte_5D4594[6 * a1 + 1567740];
}

//----- (004E8340) --------------------------------------------------------
void __cdecl sub_4E8340(float* a1, int a2)
{
    int v2; // eax

    if (*((_BYTE*)a1 + 8) & 0x80)
    {
        v2 = *((_DWORD*)a1 + 187);
        if (*(_DWORD*)(v2 + 16) == *(_DWORD*)a2 && *(_DWORD*)(v2 + 20) == *(_DWORD*)(a2 + 4))
        {
            *(_BYTE*)(v2 + 1) = 0;
            if (sub_40A5C0(4096))
                sub_4E8390((int)a1);
        }
    }
}

//----- (004E8390) --------------------------------------------------------
int __cdecl sub_4E8390(int a1)
{
    *(_BYTE*)(*(_DWORD*)(a1 + 748) + 48) = 1;
    return sub_4D6A20(255, a1);
}

//----- (004E83B0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4E83B0(int a1, int a2)
{
    return sub_502490((int*)(*(_DWORD*)(a1 + 748) + 1272), a2, a1);
}

//----- (004E83D0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4E83D0(int a1, int a2)
{
    int v2; // eax
    int* v3; // eax
    int* v4; // eax

    if (a2)
    {
        v2 = *(_DWORD*)(a2 + 16);
        if ((v2 & 0x8000) == 0 && *(_BYTE*)(a2 + 8) & 6 && sub_5330C0(a1, a2) && !sub_50A090(a1, 15))
        {
            v3 = sub_50A260(a1, 43);
            if (v3)
                v3[1] = *(_DWORD*)& byte_5D4594[2598000];
            v4 = sub_50A260(a1, 15);
            if (v4)
            {
                v4[1] = *(_DWORD*)(a2 + 56);
                v4[2] = *(_DWORD*)(a2 + 60);
                v4[3] = *(_DWORD*)& byte_5D4594[2598000];
            }
        }
    }
    return sub_4E83B0(a1, a2);
}

//----- (004E8460) --------------------------------------------------------
void __cdecl sub_4E8460(int a1, int a2)
{
    int v2; // ecx
    _WORD* v3; // eax
    int v4; // ebx
    int v5; // eax
    __int16 v6; // ax
    int v7; // eax
    __int16 v8; // ax
    int v9; // eax
    int v10; // eax
    int v11; // eax
    char v12; // al
    float v13; // [esp+0h] [ebp-1Ch]
    float v14; // [esp+4h] [ebp-18h]
    int v15; // [esp+4h] [ebp-18h]
    float v16; // [esp+Ch] [ebp-10h]
    float v17; // [esp+Ch] [ebp-10h]
    float v18; // [esp+Ch] [ebp-10h]
    float v19; // [esp+10h] [ebp-Ch]

    if (sub_4FC250(a1, 1))
    {
        if (!a2)
            goto LABEL_14;
        v2 = *(_DWORD*)(a2 + 8);
        if (!(v2 & 6) || (v3 = *(_WORD * *)(a2 + 556), !*v3) && v3[2])
        {
            if (!(v2 & 0x400000) && (signed char) * (_BYTE*)(a2 + 16) >= 0 && *(float*)(a2 + 120) <= (double) * (float*)(a1 + 120))
                goto LABEL_26;
        }
        if ((v2 & 0x80u) == 0)
        {
            if (!(*(_BYTE*)(a2 + 16) & 9) && !(v2 & 1))
            {
                LABEL_14:
                sub_4FA020((_DWORD*)a1, 13);
                sub_4D9110((float*)(a1 + 56), 10);
                sub_4FC300((_DWORD*)a1, 1);
                if (a2)
                {
                    v16 = sub_419D40(&byte_587000[203928]);
                    v4 = sub_419A70(v16);
                    if (!(*(_DWORD*)(a2 + 8) & 0x400000))
                        sub_4E86E0(a1, (float*)a2);
                    v5 = sub_4EC580(a1);
                    (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v4, 2);
                    if (*(_DWORD*)(a2 + 8) & 0x20006)
                        goto LABEL_25;
                    v17 = sub_419D40(&byte_587000[203944]);
                    v6 = sub_419A70(v17);
                    sub_4FF380(a1, 5, v6, 5);
                }
                else
                {
                    v7 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 296);
                    if (v7 && !(byte_5D4594[12332 * *(unsigned __int8*)(v7 + 1) + 2692780] & 5))
                    {
                        LABEL_25:
                        sub_4E7010(a1, (float2*)(a1 + 72));
                        goto LABEL_26;
                    }
                    sub_501960(171, a1, 0, 0);
                    v18 = sub_419D40(&byte_587000[203968]);
                    v8 = sub_419A70(v18);
                    sub_4FF380(a1, 5, v8, 5);
                    v14 = *(float*)(a1 + 68) * 0.043478262;
                    v15 = sub_419A70(v14);
                    v13 = *(float*)(a1 + 64) * 0.043478262;
                    v9 = sub_419A70(v13);
                    sub_534BC0(v9, v15, 100, 2, a1);
                }
                v19 = sub_419D40(&byte_587000[203992]) * (double) * *(unsigned __int16**)(a1 + 556);
                v10 = sub_419A70(v19);
                if (v10 < 1)
                    v10 = 1;
                sub_4EE5E0(a1, v10);
                goto LABEL_25;
            }
        }
        else if (*(_BYTE*)(*(_DWORD*)(a2 + 748) + 1))
        {
            goto LABEL_14;
        }
    }
    LABEL_26:
    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
        {
            v11 = *(_DWORD*)(a2 + 16);
            if ((v11 & 0x8000) == 0)
            {
                if (sub_4FF350(a1, 16))
                {
                    if (sub_4FF550(a1, 16) < (unsigned int)(14 * *(_DWORD*)& byte_5D4594[2649704]))
                    {
                        v12 = sub_4FF570(a1, 16);
                        sub_4FF380(a2, 16, 15 * *(_WORD*)& byte_5D4594[2649704], v12);
                        sub_4FF5B0(a1, 16);
                    }
                }
            }
        }
    }
}

//----- (004E86E0) --------------------------------------------------------
void __cdecl sub_4E86E0(int a1, float* a2)
{
    int v2; // ecx
    float* v3; // eax
    double v4; // st7
    double v5; // st6
    double v6; // st5
    double v7; // st4
    float v8; // [esp+0h] [ebp-8h]
    float v9; // [esp+4h] [ebp-4h]
    float v10; // [esp+Ch] [ebp+4h]
    float v11; // [esp+Ch] [ebp+4h]
    float v12; // [esp+10h] [ebp+8h]
    float v13; // [esp+10h] [ebp+8h]

    v2 = a1;
    if (a1)
    {
        v3 = a2;
        if (a2)
        {
            v12 = *(float*)(a1 + 120);
            v10 = v3[30];
            v8 = v10 + v12;
            v4 = (v12 - v10) / v8;
            v9 = (v10 + v10) / v8;
            v5 = *(float*)(v2 + 84) * v4 + v9 * v3[21];
            v6 = (v10 - v12) / v8;
            v7 = (v12 + v12) / v8;
            v11 = v6 * v3[20] + v7 * *(float*)(v2 + 80);
            v13 = v6 * v3[21] + v7 * *(float*)(v2 + 84);
            *(float*)(v2 + 80) = *(float*)(v2 + 80) * v4 + v9 * v3[20];
            *(float*)(v2 + 84) = v5;
            v3[21] = v13;
            v3[20] = v11;
        }
    }
}

//----- (004E87B0) --------------------------------------------------------
void __cdecl sub_4E87B0(int a1, int a2)
{
    int* v2; // edi
    int v3; // eax
    double v4; // st7
    int v5; // ebx
    int v6; // eax
    int* v7; // eax
    float v8; // [esp+0h] [ebp-10h]

    v2 = *(int**)(a1 + 700);
    if (!*(_DWORD*)& byte_5D4594[1567948])
    {
        *(_DWORD*)& byte_5D4594[1567948] = sub_4E3AA0((CHAR*)& byte_587000[204012]);
        *(_DWORD*)& byte_5D4594[1567952] = sub_4E3AA0((CHAR*)& byte_587000[204028]);
    }
    v3 = *(unsigned __int16*)(a1 + 4);
    if ((unsigned __int16)v3 == *(_DWORD*)& byte_5D4594[1567948])
    {
        v4 = sub_419D40(&byte_587000[204036]);
        LABEL_5:
        v8 = v4;
        v5 = sub_419A70(v8);
        goto LABEL_9;
    }
    if (v3 == *(_DWORD*)& byte_5D4594[1567952])
    {
        v4 = sub_419D40(&byte_587000[204056]);
        goto LABEL_5;
    }
    v5 = *v2;
    LABEL_9:
    if (a2)
    {
        v6 = sub_4EC580(a1);
        if (!(*(unsigned __int8(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v6, a1, v5, 11))
            return;
    }
    else
    {
        v7 = (int*)sub_537760();
        if (v7)
        {
            sub_534BC0(*v7, v7[1], v5, 11, a1);
            sub_4E5CC0(a1);
            return;
        }
    }
    sub_4E5CC0(a1);
}

//----- (004E8880) --------------------------------------------------------
void __cdecl sub_4E8880(int a1, int a2)
{
    int* v2; // eax
    int v3; // eax
    int v4; // eax
    float v5; // [esp+0h] [ebp-1Ch]
    float v6; // [esp+4h] [ebp-18h]
    int v7; // [esp+4h] [ebp-18h]
    int v8; // [esp+8h] [ebp-14h]
    int v9; // [esp+Ch] [ebp-10h]

    v2 = *(int**)(a1 + 700);
    if (a2)
    {
        v9 = *v2;
        v3 = sub_4EC580(a1);
        if ((*(unsigned __int8(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v3, a1, v9, 11))
            sub_4E5CC0(a1);
    }
    else
    {
        v8 = *v2;
        v6 = *(float*)(a1 + 68) * 0.043478262;
        v7 = sub_419A70(v6);
        v5 = *(float*)(a1 + 64) * 0.043478262;
        v4 = sub_419A70(v5);
        sub_534BC0(v4, v7, v8, 11, a1);
        sub_4E5CC0(a1);
    }
}

//----- (004E8910) --------------------------------------------------------
int __cdecl sub_4E8910(int a1, int a2)
{
    int v2; // ebx
    int v4; // ebp
    const char* v5; // esi

    v2 = *(_DWORD*)(a2 + 748);
    if (*(_BYTE*)(v2 + 1) == 5)
        return 0;
    if (*(_DWORD*)(a2 + 508))
        return 0;
    v4 = *(_DWORD*)(a1 + 504);
    if (v4)
    {
        while (!(*(_BYTE*)(v4 + 8) & 0x40))
        {
            LABEL_15:
            v4 = *(_DWORD*)(v4 + 496);
            if (!v4)
                goto LABEL_16;
        }
        v5 = (const char*)sub_4E39D0(v4);
        switch (*(unsigned __int8*)(v2 + 1))
        {
            case 1u:
                if (strcmp(v5, "SilverKey"))
                    goto LABEL_15;
                break;
            case 2u:
                if (strcmp(v5, "GoldKey"))
                    goto LABEL_15;
                break;
            case 3u:
                if (strcmp(v5, "RubyKey"))
                    goto LABEL_15;
                break;
            case 4u:
                if (strcmp(v5, "SapphireKey"))
                    goto LABEL_15;
                break;
            default:
                goto LABEL_15;
        }
    }
    LABEL_16:
    if (*(_BYTE*)(a1 + 8) & 4 && !v4 && sub_40A5C0(4096) && sub_4D72C0() == 1 && *(_BYTE*)(v2 + 1) == 1)
        v4 = sub_4E8A10();
    return v4;
}

//----- (004E8A10) --------------------------------------------------------
int sub_4E8A10()
{
    int v0; // ebx
    int i; // esi
    int v2; // edi
    int v3; // eax
    int result; // eax

    v0 = 0;
    if (!*(_DWORD*)& byte_5D4594[1567956])
        * (_DWORD*)& byte_5D4594[1567956] = sub_4E3AA0((CHAR*)& byte_587000[204112]);
    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
    {
        v2 = 0;
        v3 = sub_4E7980(i);
        if (v3)
        {
            do
            {
                if (*(unsigned __int16*)(v3 + 4) == *(_DWORD*)& byte_5D4594[1567956])
                    ++v2;
                v3 = sub_4E7990(v3);
            } while (v3);
            if (v2 > 0)
                v0 = i;
        }
    }
    result = 0;
    if (v0)
    {
        for (result = sub_4E7980(v0); result; result = sub_4E7990(result))
        {
            if (*(unsigned __int16*)(result + 4) == *(_DWORD*)& byte_5D4594[1567956])
                break;
        }
    }
    return result;
}

//----- (004E8AC0) --------------------------------------------------------
void __cdecl sub_4E8AC0(int a2, int a3)
{
    int v2; // edi
    int v3; // esi
    int v4; // eax
    unsigned __int64 v5; // rax
    char v6; // al
    unsigned __int64 v7; // rax
    int v8; // ebx
    int v9; // eax
    int v10; // ecx
    int v11; // esi
    double v12; // st7
    double v13; // st6
    int v14; // ecx
    int v15; // eax
    int v16; // eax
    unsigned __int64 v17; // rax
    int a3a[2]; // [esp+10h] [ebp-18h]
    float4 a1; // [esp+18h] [ebp-10h]
    float v20; // [esp+2Ch] [ebp+4h]

    v2 = a2;
    v3 = *(_DWORD*)(a2 + 748);
    if (a3 && *(_DWORD*)(v3 + 12) == *(_DWORD*)(v3 + 4))
    {
        v4 = *(_DWORD*)(a2 + 508);
        if (v4)
        {
            if (*(_DWORD*)(a2 + 136) <= *(int*)& byte_5D4594[2598000])
            {
                *(_DWORD*)(a2 + 508) = 0;
            }
            else if (v4 != a3)
            {
                v5 = sub_416BB0() - *(_QWORD*)& byte_5D4594[1567940];
                a3a[1] = HIDWORD(v5);
                if (v5 <= 0x5DC)
                    return;
                if (*(_BYTE*)(a2 + 12) & 4)
                {
                    sub_501960(244, a2, 0, 0);
                    sub_4DA2C0(a3, "objcoll.c:GateLockedMagic", 0);
                }
                else
                {
                    sub_501960(240, a2, 0, 0);
                    sub_4DA2C0(a3, "objcoll.c:DoorLockedMagic", 0);
                }
                LABEL_38:
                *(_QWORD*)& byte_5D4594[1567940] = sub_416BB0();
                return;
            }
        }
        v6 = *(_BYTE*)(v3 + 1);
        if (!v6)
            return;
        if (v6 == 5)
        {
            v7 = sub_416BB0() - *(_QWORD*)& byte_5D4594[1567940];
            a3a[1] = HIDWORD(v7);
            if (v7 <= 0x5DC)
                return;
            if (*(_BYTE*)(a2 + 12) & 4)
            {
                sub_501960(244, a2, 0, 0);
                sub_4DA2C0(a3, "objcoll.c:GateLockedMechanism", 0);
            }
            else
            {
                sub_501960(240, a2, 0, 0);
                sub_4DA2C0(a3, "objcoll.c:DoorLockedMechanism", 0);
            }
            goto LABEL_38;
        }
        v8 = sub_4E8910(a3, a2);
        if (!v8)
        {
            v17 = sub_416BB0() - *(_QWORD*)& byte_5D4594[1567940];
            a3a[1] = HIDWORD(v17);
            if (v17 <= 0x5DC)
                return;
            if (*(_BYTE*)(a2 + 12) & 4)
            {
                sub_501960(244, a2, 0, 0);
                sub_4FADD0(a3, "objcoll.c:GateLockedKey", *(_BYTE*)(v3 + 1));
            }
            else
            {
                sub_501960(240, a2, 0, 0);
                sub_4FADD0(a3, "objcoll.c:DoorLockedKey", *(_BYTE*)(v3 + 1));
            }
            goto LABEL_38;
        }
        v9 = *(_DWORD*)(v3 + 16);
        v10 = *(_DWORD*)(v3 + 20);
        *(_BYTE*)(v3 + 1) = 0;
        v11 = *(_DWORD*)(v3 + 4);
        v12 = (double)(23 * v9);
        a1.field_0 = v12 - 34.0;
        v13 = (double)(23 * v10);
        v20 = v13;
        a1.field_4 = v13 - 34.0;
        a1.field_8 = v12 + 34.0;
        a1.field_C = v20 + 34.0;
        switch (v11)
        {
            case 0:
                v14 = v10 - 1;
                a3a[0] = v9 - 1;
                goto LABEL_24;
            case 8:
                v14 = v10 - 1;
                a3a[0] = v9 + 1;
                goto LABEL_24;
            case 16:
                v15 = v9 + 1;
                goto LABEL_23;
            case 24:
                v15 = v9 - 1;
            LABEL_23:
                a3a[0] = v15;
                v14 = v10 + 1;
            LABEL_24:
                a3a[1] = v14;
                break;
            default:
                break;
        }
        if (sub_40A5C0(4096))
        {
            sub_4E8390(v2);
            sub_4D71E0(*(int*)& byte_5D4594[2598000]);
        }
        sub_517C10(&a1, sub_4E8340, (int)a3a);
        sub_501960(234, v2, 0, 0);
        v16 = *(_DWORD*)(v8 + 492);
        if (v16 && a3 != v16 && *(_BYTE*)(v16 + 8) & 4 && sub_40A5C0(4096) && sub_4D72C0() == 1)
            sub_4DA2C0(*(_DWORD*)(v8 + 492), "GeneralPrint:KeyShared1", 0);
        sub_4E5CC0(v8);
    }
}

//----- (004E8DF0) --------------------------------------------------------
int __cdecl sub_4E8DF0(int a1, int a2)
{
    int result; // eax
    int v3; // ecx

    result = a2;
    if (a2)
    {
        v3 = *(_DWORD*)(a2 + 8);
        if (!(v3 & 2)
            && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a1 + 128)) >= *(int*)& byte_5D4594[2649704] >> 1
            && (!(v3 & 4) || *(_BYTE*)(*(_DWORD*)(a2 + 748) + 240) & 1))
        {
            result = sub_4F36F0(a2, a1, 1, 1);
        }
    }
    return result;
}

//----- (004E8E50) --------------------------------------------------------
unsigned __int8* sub_4E8E50()
{
    return &byte_5D4594[1567844];
}

//----- (004E8E60) --------------------------------------------------------
int sub_4E8E60()
{
    int v0; // esi
    int v1; // edi
    int v2; // ebx
    int v3; // eax
    int v4; // edx
    unsigned int v5; // eax
    int v6; // eax
    int v7; // ecx
    int result; // eax
    int v9; // eax
    int v10; // ecx
    float v11; // [esp+0h] [ebp-1Ch]
    float v12; // [esp+0h] [ebp-1Ch]
    int v13; // [esp+10h] [ebp-Ch]
    int v14; // [esp+18h] [ebp-4h]

    v11 = sub_419D40(&byte_587000[204316]);
    v0 = sub_419A70(v11);
    v1 = 0;
    v14 = v0;
    v2 = v0;
    v13 = 0;
    if (sub_40A220())
    {
        v3 = sub_40A230();
        v4 = (int)v3 / 1000;
        v5 = 0;
        v0 = v5 + v4;
        v14 = v5 + v4;
        v2 = v5 + v4;
    }
    v6 = sub_4DA7C0();
    if (!v6)
        return sub_40A1F0(0);
    do
    {
        v7 = *(_DWORD*)(v6 + 748);
        if (*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4792) == 1)
        {
            ++v1;
            if (*(_DWORD*)(v7 + 312))
                ++v13;
        }
        v6 = sub_4DA7F0(v6);
    } while (v6);
    if (!v1)
        return sub_40A1F0(0);
    v12 = (double)v13 / (double)v1 * (double)v14;
    v9 = sub_419A70(v12);
    v10 = v0 - v9;
    if (v0 - v9 < v0 && (v0 -= v9, v2 != v10) || (result = sub_40A300()) == 0)
    {
        sub_40A2A0(v0, "objcoll.c:ExitCountdown");
        result = sub_4D9E70(255);
    }
    return result;
}

//----- (004E8F60) --------------------------------------------------------
BOOL sub_4E8F60()
{
    int v0; // ebp
    int v1; // eax
    int v2; // ebx
    int v3; // edi
    int v4; // esi
    int v5; // eax
    BOOL result; // eax
    unsigned int v7; // [esp+10h] [ebp-4h]

    v0 = 0;
    v1 = sub_4E3CC0();
    v7 = sub_4D74F0(v1);
    v2 = 1;
    v3 = sub_4DA7C0();
    if (!v3)
        goto LABEL_11;
    do
    {
        v4 = *(_DWORD*)(v3 + 748);
        if (!sub_40A5C0(1)
            || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
            || *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2064) != 31)
        {
            v5 = *(_DWORD*)(v4 + 276);
            if (*(_DWORD*)(v5 + 4792))
            {
                ++v0;
                if (!*(_DWORD*)(v4 + 316))
                    goto LABEL_11;
                if (*(_DWORD*)(v5 + 4696) >= v7)
                    v2 = 0;
            }
        }
        v3 = sub_4DA7F0(v3);
    } while (v3);
    if (v0)
        result = v2 != 1;
    else
        LABEL_11:
        result = 0;
    return result;
}

//----- (004E9010) --------------------------------------------------------
int sub_4E9010()
{
    int v0; // ebp
    int v1; // edi
    int v2; // esi

    v0 = 0;
    v1 = sub_4DA7C0();
    if (v1)
    {
        while (1)
        {
            v2 = *(_DWORD*)(v1 + 748);
            if (!sub_40A5C0(1)
                || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                || *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064) != 31)
            {
                if (*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4792))
                {
                    ++v0;
                    if (!*(_DWORD*)(v2 + 312))
                        break;
                }
            }
            v1 = sub_4DA7F0(v1);
            if (!v1)
            {
                if (!v0)
                    return 0;
                return 1;
            }
        }
    }
    return 0;
}

//----- (004E9090) --------------------------------------------------------
char* __cdecl sub_4E9090(int a1, int a2, int a3)
{
    char* result; // eax
    int v4; // ebp
    int v5; // esi
    _BYTE* v6; // edi
    int i; // edi
    char v8; // al
    int v9; // ebx
    char* v10; // edi
    int v11; // edi
    int v12; // edi
    int v13; // eax
    unsigned int v14; // edi
    int v15; // eax
    int j; // esi
    int v17; // eax
    int v18; // eax
    const char* v19; // [esp+8h] [ebp+8h]

    result = *(char**)& byte_5D4594[1567960];
    if (!*(_DWORD*)& byte_5D4594[1567960])
    {
        result = (char*)sub_4E3AA0((CHAR*)& byte_587000[204360]);
        *(_DWORD*)& byte_5D4594[1567960] = result;
    }
    v4 = a2;
    if (a2)
    {
        if (!(*(_BYTE*)(a2 + 8) & 4))
        {
            nullsub_34(a1, a2, a3);
            return result;
        }
        v5 = *(_DWORD*)(a2 + 748);
        v6 = *(_BYTE * *)(a1 + 700);
        v19 = *(const char**)(a1 + 700);
        if (!sub_40A5C0(4096) || (result = *(char**)(v5 + 312)) == 0 && (result = *(char**)(v5 + 316)) == 0)
        {
            if (!(*(_BYTE*)(a1 + 12) & 2) || (result = (char*)sub_4D75E0()) != 0)
            {
                result = (char*)sub_4DCC90();
                if (result != (char*)1)
                {
                    result = (char*)sub_4DCC10(v4);
                    if (result)
                    {
                        result = (char*)sub_413A50();
                        if (result != (char*)1)
                        {
                            if (*v6 || (result = (char*)sub_40A5C0(4096)) != 0)
                            {
                                if (*(_BYTE*)(*(_DWORD*)(v5 + 276) + 2251) == 1)
                                {
                                    for (i = *(_DWORD*)(v4 + 516); i; i = *(_DWORD*)(i + 512))
                                    {
                                        if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[1567960] && !*(_DWORD*)(i + 492))
                                        {
                                            sub_4E5CC0(i);
                                            v8 = *(_BYTE*)(v5 + 244);
                                            if (v8)
                                                * (_BYTE*)(v5 + 244) = v8 - 1;
                                        }
                                    }
                                }
                                sub_4DCBF0(1);
                                if (sub_40A5C0(2048))
                                {
                                    sub_4DB130("WORKING");
                                    return (char*)sub_4DB170(1, a1, 0);
                                }
                                v9 = 1;
                                if (sub_40A5C0(4096))
                                {
                                    v10 = sub_4D0F60();
                                    v19 = v10;
                                }
                                else
                                {
                                    v10 = (char*)v19;
                                }
                                result = (char*)sub_40A5C0(4096);
                                if (!result)
                                    goto LABEL_47;
                                v11 = 1;
                                do
                                {
                                    if (sub_4FC250(v4, v11))
                                        sub_4FC300((_DWORD*)v4, v11);
                                    ++v11;
                                } while (v11 < 6);
                                v12 = a1;
                                v13 = *(_DWORD*)(a1 + 12);
                                if (v13 & 1)
                                {
                                    v14 = sub_4E3CC0() + 1;
                                    sub_4D60E0(v4);
                                    v15 = *(_DWORD*)(v5 + 276);
                                    if (*(_DWORD*)(v15 + 4696) < v14)
                                    {
                                        *(_DWORD*)(v15 + 4696) = v14;
                                        sub_4D7450(
                                                *(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064),
                                                *(_DWORD*)(*(_DWORD*)(v5 + 276) + 4696));
                                    }
                                    *(_DWORD*)(v5 + 312) = a1;
                                    *(_DWORD*)(v5 + 316) = 0;
                                    sub_4FA020((_DWORD*)v4, 13);
                                    sub_4E6860(*(_DWORD*)(v5 + 276), 0, 0);
                                    sub_4DA180(18, (_BYTE*)(v4 + 36));
                                    v12 = a1;
                                    v9 = sub_4E9010();
                                }
                                else if (v13 & 2)
                                {
                                    *(_DWORD*)(v5 + 312) = 0;
                                    *(_DWORD*)(v5 + 316) = a1;
                                    sub_4D75F0(*(int*)& byte_5D4594[2598000]);
                                    sub_4FA020((_DWORD*)v4, 13);
                                    sub_4E6860(*(_DWORD*)(v5 + 276), 0, 0);
                                    for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j))
                                    {
                                        if (j != v4)
                                            sub_4DA0F0(
                                                    *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(j + 748) + 276) + 2064),
                                                    19,
                                                    (int*)(v4 + 36));
                                    }
                                    sub_4DA2C0(v4, "objcoll.c:PlayerEntersWarp", 0);
                                    v9 = sub_4E8F60();
                                }
                                sub_501960(1003, v12, 0, 0);
                                if (!(*(_BYTE*)(v12 + 12) & 2) && !v9)
                                    sub_4E8E60();
                                result = 0;
                                strcpy((char*)& byte_5D4594[1567844], v19);
                                if (v9 == 1)
                                {
                                    v10 = (char*)v19;
                                    LABEL_47:
                                    if (v10 && *v10)
                                    {
                                        if (*(_BYTE*)(a1 + 12) & 2)
                                        {
                                            v17 = sub_4E3CC0();
                                            v18 = sub_4D74F0(v17);
                                            sub_4E3CD0(v18 - 1);
                                            sub_4D76E0(1);
                                            sub_4D60B0();
                                        }
                                        result = sub_4D2450(v10);
                                    }
                                    return result;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}
// 4E87A0: using guessed type void __cdecl nullsub_34(_DWORD, _DWORD, _DWORD);

//----- (004E9430) --------------------------------------------------------
void __cdecl sub_4E9430(int a1, int a2)
{
    unsigned __int8* v2; // ecx
    int v3; // eax
    int v4; // eax
    int v5; // [esp-8h] [ebp-Ch]
    int v6; // [esp-4h] [ebp-8h]

    v2 = *(unsigned __int8**)(a1 + 700);
    if (a2 && *(_DWORD*)(a2 + 556))
    {
        if (*v2 == 1 && byte_5D4594[2598000] & 1)
            v3 = 1;
        else
            v3 = *v2 >> 1;
        v6 = *((_DWORD*)v2 + 1);
        v5 = v3;
        v4 = sub_4EC580(a1);
        (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v4, a1, v5, v6);
    }
}

//----- (004E9490) --------------------------------------------------------
_DWORD* __cdecl sub_4E9490(int a1, int a2)
{
    _DWORD* result; // eax

    result = (_DWORD*)a2;
    if (a2 && *(_BYTE*)(a2 + 8) & 4 && *(_WORD*)(*(_DWORD*)(a2 + 748) + 4))
    {
        sub_4EEBF0(a2, **(unsigned __int8**)(a1 + 700));
        result = (_DWORD*)(*(_DWORD*)& byte_5D4594[2598000] - *(__int16*)(a1 + 542));
        if ((unsigned int)result > * (int*)& byte_5D4594[2649704] >> 1)
        {
            result = sub_501960(228, a1, 0, 0);
            *(_WORD*)(a1 + 542) = *(_WORD*)& byte_5D4594[2598000];
        }
    }
    return result;
}

//----- (004E9500) --------------------------------------------------------

// Mix Patch new version with fixups

/*void __cdecl sub_4E9500(int a1, int a2, float *a3)
{
  int v3; // esi
  float2 *v4; // edi
  int v5; // ebx
  int v6; // ebp
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // [esp+10h] [ebp-10h]
  int v11[3]; // [esp+14h] [ebp-Ch]

  v3 = a2;
  v4 = (float2 *)a1;
  v5 = *(_DWORD *)(a1 + 748);
  v10 = *(_DWORD *)(a1 + 748);
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) & 0x8020 )
      return;
    if ( !(*(_BYTE *)(a2 + 8) & 4) )
      goto LABEL_23;
    v6 = *(_DWORD *)(a2 + 748);
    if ( *(_BYTE *)(v6 + 88) == 16 && sub_4E6E50((float2 *)(a2 + 56), *(__int16 *)(a2 + 124), (float2 *)(a1 + 72)) & 1 )
    {
      sub_501960(878, v3, 0, 0);
      sub_4E0A70((int)v4, v3);
      sub_52BE40((int)v4, v3);
      return;
    }
    if ( *(_BYTE *)(v6 + 88) == 13 || (!*(_BYTE *)(v6 + 88) && dword_980858[0] & 0x40000 ) )
    {
      v7 = *(_DWORD *)(*(_DWORD *)(v6 + 276) + 4);
      if ( v7 & 0x400 )
      {
        if ( sub_4E6E50((float2 *)(v3 + 56), *(__int16 *)(v3 + 124), v4 + 9) & 1 )
        {
          v8 = sub_415FA0(18, 20);
          sub_501960(890, v3, 0, 0);
          sub_4E0A70((int)v4, v3);
          sub_52BE40((int)v4, v3);
          sub_4FA020((_DWORD *)v3, v8);
          v9 = sub_4FA2B0(v3);
          sub_4F9F90(v9, &a1, &a2);
          v5 = v10;
          *(_BYTE *)(v6 + 236) = a1 - 1;
        }
      }
    }
M_LABEL_13:
    if ( sub_4FA4F0(v3, (int)v4) )
    {
      sub_52BE40((int)v4, v3);
      return;
    }
    if ( sub_4FF350(v3, 27) && sub_4E6E50((float2 *)(v3 + 56), *(__int16 *)(v3 + 124), v4 + 7) & 1 )
    {
      sub_52BE40((int)v4, v3);
      sub_501960(122, v3, 0, 0);
    }
    else
    {
LABEL_23:
      if ( *(_DWORD *)(v5 + 4) == v3 )
      {
        v11[0] = v3;
        sub_4FD400(*(_DWORD *)(v5 + 12), *(_DWORD *)(v5 + 8), *(_DWORD **)v5, (int)v4, v11, *(_DWORD *)(v5 + 16));
        sub_4E5CC0((int)v4);
      }
      else
      {
        sub_4E0A70((int)v4, v3);
      }
    }
  }
  else if ( a3 )
  {
    sub_57B810(a3, a1 + 80);
  }
}*/
void __cdecl sub_4E9500(int a1, int a2, float* a3)
{
    int v3; // esi
    float2* v4; // edi
    int v5; // ebx
    int v6; // ebp
    int v7; // ecx
    int v8; // ebx
    int v9; // eax
    char v10; // al
    int v11; // [esp+10h] [ebp-10h]
    int v12[3]; // [esp+14h] [ebp-Ch]

    v3 = a2;
    v4 = (float2*)a1;
    v5 = *(_DWORD*)(a1 + 748);
    v11 = *(_DWORD*)(a1 + 748);
    if (!a2)
    {
        if (a3)
            sub_57B810(a3, a1 + 80);
        return;
    }
    if (*(_DWORD*)(a2 + 16) & 0x8020)
        return;
    if (*(_BYTE*)(a2 + 8) & 4)
    {
        v6 = *(_DWORD*)(a2 + 748);
        if (*(_BYTE*)(v6 + 88) != 16)
        {
            if (*(_BYTE*)(v6 + 88) != 1
                || sub_4FA2B0(a2) != 45
                || (v10 = *(_BYTE*)(*(_DWORD*)(v6 + 276) + 3), v10 != 1) && v10 != 2)
            {
                LABEL_22:
                if (*(_BYTE*)(v6 + 88) == 13 || !*(_BYTE*)(v6 + 88) && dword_980858[0] & 0x40000)
                {
                    v7 = *(_DWORD*)(*(_DWORD*)(v6 + 276) + 4);
                    if (v7 & 0x400 && sub_4E6E50((float2*)(v3 + 56), *(__int16*)(v3 + 124), v4 + 9) & 1)
                    {
                        v8 = sub_415FA0(18, 20);
                        sub_501960(890, v3, 0, 0);
                        sub_4E0A70((int)v4, v3);
                        sub_52BE40((int)v4, v3);
                        sub_4FA020((_DWORD*)v3, v8);
                        v9 = sub_4FA2B0(v3);
                        sub_4F9F90(v9, &a1, &a2);
                        v5 = v11;
                        *(_BYTE*)(v6 + 236) = a1 - 1;
                    }
                }
                LABEL_13:
                if (sub_4FA4F0(v3, (int)v4))
                {
                    sub_52BE40((int)v4, v3);
                    return;
                }
                if (sub_4FF350(v3, 27) && sub_4E6E50((float2*)(v3 + 56), *(__int16*)(v3 + 124), v4 + 7) & 1)
                {
                    sub_52BE40((int)v4, v3);
                    sub_501960(122, v3, 0, 0);
                    return;
                }
                goto LABEL_18;
            }
            if (!(dword_980858[0] & 0x100000))
                goto LABEL_13;
        }
        if (sub_4E6E50((float2*)(a2 + 56), *(__int16*)(a2 + 124), (float2*)(a1 + 72)) & 1)
        {
            sub_501960(878, v3, 0, 0);
            sub_4E0A70((int)v4, v3);
            sub_52BE40((int)v4, v3);
            return;
        }
        goto LABEL_22;
    }
    LABEL_18:
    if (*(_DWORD*)(v5 + 4) == v3)
    {
        v12[0] = v3;
        sub_4FD400(*(_DWORD*)(v5 + 12), *(_DWORD*)(v5 + 8), *(_DWORD * *)v5, (int)v4, v12, *(_DWORD*)(v5 + 16));
        sub_4E5CC0((int)v4);
    }
    else
    {
        sub_4E0A70((int)v4, v3);
    }
}

//----- (004E96F0) --------------------------------------------------------
void __cdecl sub_4E96F0(int a1, int a2)
{
    int v2; // ebx
    int v3; // eax

    v2 = *(_DWORD*)(a1 + 748);
    if (!sub_40A5C0(2048) || (*(_BYTE*)(sub_4DA7C0() + 16) & 2) != 2)
    {
        sub_502490((int*)(v2 + 1272), a2, a1);
        if (a2 && *(_BYTE*)(a2 + 8) & 6 && !sub_4EC520(a1, a2))
        {
            v3 = *(_DWORD*)(a2 + 16);
            if ((v3 & 0x8000) == 0)
            {
                *(_DWORD*)(v2 + 2176) = a2;
                sub_4EE5E0(a1, 999);
            }
        }
    }
}

//----- (004E9770) --------------------------------------------------------
void __cdecl sub_4E9770(int a1, int a2, float* a3)
{
    int v3; // eax
    float v4; // edx
    __int16 v5; // ax
    double v6; // st7
    int* v7; // eax
    int v8; // eax
    int v9; // [esp-Ch] [ebp-18h]
    float v10; // [esp+0h] [ebp-Ch]
    float v11; // [esp+0h] [ebp-Ch]
    float2 v12; // [esp+4h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[1567964])
    {
        v10 = sub_419D40(&byte_587000[204452]);
        *(_DWORD*)& byte_5D4594[1567968] = sub_419A70(v10);
        v11 = sub_419D40(&byte_587000[204472]);
        *(_DWORD*)& byte_5D4594[1567972] = sub_419A70(v11);
        *(float*)& byte_5D4594[1567976] = sub_419D40(&byte_587000[204500]);
        *(float*)& byte_5D4594[1567980] = sub_419D40(&byte_587000[204520]);
        *(float*)& byte_5D4594[1567984] = sub_419D40(&byte_587000[204544]);
        *(_DWORD*)& byte_5D4594[1567964] = 1;
    }
    if (!sub_40A5C0(4096)
        || (v3 = sub_4EC580(a1)) == 0
        || !a2
        || !(*(_BYTE*)(v3 + 8) & 4)
        || !(*(_BYTE*)(a2 + 8) & 4)
        || sub_5330C0(v3, a2))
    {
        if (a1)
            sub_522FF0(134, (float2*)(a1 + 56));
        if (a2)
        {
            if (*(_BYTE*)(a2 + 8) & 4)
            {
                if (sub_4FA4F0(a2, a1))
                {
                    sub_52BE40(a1, a2);
                    return;
                }
                if (sub_4FF350(a2, 27) && sub_4E6E50((float2*)(a2 + 56), *(__int16*)(a2 + 124), (float2*)(a1 + 56)) & 1)
                {
                    sub_52BE40(a1, a2);
                    sub_501960(122, a2, 0, 0);
                    return;
                }
            }
            v9 = *(_DWORD*)& byte_5D4594[1567968];
            v8 = sub_4EC580(a1);
            (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v8, a1, v9, 7);
            sub_537AF0((int*)(a2 + 56), 0);
        }
        else if (a3)
        {
            sub_57B810(a3, a1 + 80);
            v4 = *(float*)(a1 + 84);
            v12.field_0 = *(float*)(a1 + 80);
            v12.field_4 = v4;
            v5 = sub_509ED0(&v12);
            v6 = *(float*)(a1 + 80) * 0.5;
            *(_WORD*)(a1 + 126) = v5;
            *(float*)(a1 + 80) = v6;
            *(float*)(a1 + 84) = *(float*)(a1 + 84) * 0.5;
            v7 = (int*)sub_537760();
            if (v7)
                sub_534BC0(*v7, v7[1], *(int*)& byte_5D4594[1567968], 7, a1);
            return;
        }
        sub_4E25B0(a1 + 56, *(float*)& byte_5D4594[1567976], 5.0, *(int*)& byte_5D4594[1567972], 7, a1, 0);
        sub_52E040(
                a1 + 56,
                *(float*)& byte_5D4594[1567980],
                *(int*)& byte_5D4594[1567980],
                *(float*)& byte_5D4594[1567984],
                a1,
                0,
                0);
        sub_501960(84, a1, 0, 0);
        sub_4E5CC0(a1);
    }
}

//----- (004E99B0) --------------------------------------------------------
void __cdecl sub_4E99B0(int a1, int a2)
{
    int v2; // edx
    void(__cdecl * v3)(int); // eax

    if (a2 && !sub_4EC520(a1, a2) && *(_BYTE*)(a2 + 8) & 6)
    {
        v2 = *(_DWORD*)(a1 + 16);
        v3 = *(void(__cdecl * *)(int))(a1 + 724);
        BYTE1(v2) |= 0x80u;
        *(_DWORD*)(a1 + 16) = v2;
        if (v3)
            v3(a1);
        else
            sub_4E5CC0(a1);
    }
}

//----- (004E9A00) --------------------------------------------------------
char __cdecl sub_4E9A00(int a1, int a2)
{
    int v2; // eax

    v2 = sub_4E9A30(a1, a2);
    if (v2)
        LOBYTE(v2) = sub_537C10(a1, a2);
    return v2;
}

//----- (004E9A30) --------------------------------------------------------
BOOL __cdecl sub_4E9A30(int a1, int a2)
{
    int v3; // esi
    int v4; // eax
    BOOL v5; // esi

    if (sub_40A5C0(2048) && (*(_BYTE*)(sub_4DA7C0() + 16) & 2) == 2)
        return 0;
    v5 = 1;
    if (a2)
    {
        if (sub_4EC520(a1, a2)
            || sub_40A5C0(512) && (v3 = sub_4EC580(a1), v4 = sub_4EC580(a2), *(_BYTE*)(v3 + 8) & 4) && *(_BYTE*)(v4 + 8) & 4)
        {
            v5 = 0;
        }
    }
    if (sub_4FC250(a2, 4))
        v5 = 0;
    return v5;
}

//----- (004E9AC0) --------------------------------------------------------
void __cdecl sub_4E9AC0(int a1, int a2)
{
    int v2; // esi
    char* v3; // ebp
    int v4; // ebx
    int v5; // eax
    int v6; // eax
    float v7; // [esp+0h] [ebp-28h]
    float v8; // [esp+0h] [ebp-28h]
    int v9; // [esp+4h] [ebp-24h]
    int v10; // [esp+8h] [ebp-20h]
    int v11; // [esp+10h] [ebp-18h]
    int v12; // [esp+10h] [ebp-18h]
    int v13; // [esp+14h] [ebp-14h]
    unsigned int v14; // [esp+2Ch] [ebp+4h]

    v2 = a1;
    v3 = *(char**)(a1 + 700);
    v4 = 1;
    if (a2 && sub_4FF350(a2, 27) && sub_4E6E50((float2*)(a2 + 56), *(__int16*)(a2 + 124), (float2*)(a1 + 56)) & 1)
    {
        sub_4E0A70(a1, a2);
        sub_4EC300(a1);
        sub_4EC290(a2, a1);
        v4 = 0;
        sub_501960(122, a2, 0, 0);
    }
    if (!sub_40A5C0(4096)
        || (v5 = sub_4EC580(a1)) == 0
        || !a2
        || !(*(_BYTE*)(v5 + 8) & 4)
        || !(*(_BYTE*)(a2 + 8) & 4)
        || sub_5330C0(v5, a2))
    {
        if (v4)
        {
            v7 = (double)(unsigned __int8)* v3 * 0.66666669;
            sub_52E040(a1 + 56, v7, 0, 50.0, a1, 0, 0);
            if (a2)
            {
                v11 = (unsigned __int8)* v3 >> 1;
                v6 = sub_4EC580(a1);
                (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v6, a1, v11, 1);
            }
            if (sub_40A5C0(2048))
            {
                v13 = a2;
                v12 = a1;
                v14 = (unsigned __int8)* v3;
                v10 = v14 >> 1;
                v9 = 0;
            }
            else
            {
                v13 = a2;
                v12 = a1;
                v14 = (unsigned __int8)* v3;
                v10 = v14 >> 1;
                v9 = 1097859072;
            }
            v8 = (double)(int)v14 * 0.33333334;
            sub_4E25B0(v2 + 56, v8, *(float*)& v9, v10, 1, v12, v13);
            sub_5231B0((float*)(v2 + 56), *v3);
            sub_501960(42, v2, 0, 0);
            sub_537AF0((int*)(v2 + 56), 2);
            sub_4E5CC0(v2);
        }
    }
}

//----- (004E9C40) --------------------------------------------------------
void __cdecl sub_4E9C40(_DWORD* a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int v4; // eax
    int i; // ebp
    void(__cdecl * v6)(_DWORD*); // eax

    v2 = a2;
    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
        {
            v3 = a1[4];
            if ((v3 & 0x8000) == 0)
            {
                if (sub_40A5C0(4096) && (v4 = a1[3], BYTE1(v4) & 0xF))
                {
                    for (i = sub_4E7980(a2); i; i = sub_4E7990(i))
                    {
                        if (*(_BYTE*)(i + 8) & 0x40)
                        {
                            if (!strcmp((const char*)sub_4E39D0(i), "SilverKey"))
                            {
                                sub_4E5CC0(i);
                                sub_501960(234, (int)a1, 0, 0);
                                v2 = a2;
                                goto LABEL_14;
                            }
                            v2 = a2;
                        }
                    }
                    if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[1567940]) > 0x5DC)
                    {
                        sub_501960(1012, (int)a1, 0, 0);
                        sub_4DA2C0(v2, "objcoll.c:ChestLockedSilver", 0);
                        *(_QWORD*)& byte_5D4594[1567940] = sub_416BB0();
                    }
                }
                else
                {
                    LABEL_14:
                    v6 = (void(__cdecl*)(_DWORD*))a1[181];
                    if (v6)
                        v6(a1);
                    sub_4EDF00((int)a1, v2);
                    sub_4EDA40(a1);
                }
            }
        }
    }
}

//----- (004E9D80) --------------------------------------------------------
void __cdecl sub_4E9D80(int a1, int a2, float* a3)
{
    int* v3; // edi
    int v4; // eax
    int v5; // edi
    int v6; // eax
    float v7; // [esp+0h] [ebp-20h]
    float v8; // [esp+4h] [ebp-1Ch]
    int v9; // [esp+4h] [ebp-1Ch]
    int v10; // [esp+8h] [ebp-18h]

    v3 = *(int**)(a1 + 700);
    if (a2)
    {
        if (!sub_4EC520(a1, a2))
        {
            if (sub_40A5C0(4096) && *(void(__cdecl * *)(int, int, int))(a1 + 696) == sub_4E9E50)
                v5 = 3 * *v3;
            else
                v5 = *v3;
            v6 = sub_4EC580(a1);
            if ((*(int(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v6, a1, v5, 11))
                sub_4E5CC0(a1);
        }
    }
    else if (a3)
    {
        sub_57B810(a3, a1 + 80);
        v10 = *v3;
        v8 = *(float*)(a1 + 68) * 0.043478262;
        v9 = sub_419A70(v8);
        v7 = *(float*)(a1 + 64) * 0.043478262;
        v4 = sub_419A70(v7);
        sub_534BC0(v4, v9, v10, 11, a1);
    }
}

//----- (004E9E50) --------------------------------------------------------
void __cdecl sub_4E9E50(int a1, int a2, int a3)
{
    if (a1 && !sub_40A5C0(4))
        sub_522FF0(136, (float2*)(a1 + 56));
    sub_4E9D80(a1, a2, (float*)a3);
}

//----- (004E9E90) --------------------------------------------------------
int* __cdecl sub_4E9E90(int a1, int a2, float* a3)
{
    int* result; // eax
    int* v4; // esi
    int v5; // eax
    int v6; // eax
    int v7; // edx
    double v8; // st7
    double v9; // st6
    double v10; // st5
    int v11; // eax
    float v12; // [esp+0h] [ebp-1Ch]
    float v13; // [esp+4h] [ebp-18h]
    int v14; // [esp+4h] [ebp-18h]
    float2 a2a; // [esp+14h] [ebp-8h]

    if (a2)
    {
        if ((signed char) * (_BYTE*)(a2 + 8) >= 0)
        {
            v13 = sub_419D40(&byte_587000[204628]);
            v14 = sub_419A70(v13);
            v11 = sub_4EC580(a1);
            result = (int*)(*(int(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v11, a1, v14, 2);
        }
        else
        {
            v6 = *(_DWORD*)(a2 + 748);
            v7 = *(_DWORD*)(a1 + 76);
            *(_DWORD*)(a1 + 64) = *(_DWORD*)(a1 + 72);
            *(_DWORD*)(a1 + 68) = v7;
            v8 = *(float*)(a2 + 56) - *(float*)(a1 + 72);
            v9 = *(float*)(a2 + 60) - *(float*)(a1 + 76);
            a2a.field_0 = -(double) * (int*)& byte_587000[8 * *(_DWORD*)(v6 + 12) + 196188];
            v10 = (double) * (int*)& byte_587000[8 * *(_DWORD*)(v6 + 12) + 196184];
            a2a.field_4 = v10;
            if (v10 * v9 + a2a.field_0 * v8 > 0.0)
            {
                a2a.field_0 = -a2a.field_0;
                a2a.field_4 = -a2a.field_4;
            }
            sub_57B770((float2*)(a1 + 80), &a2a);
            result = sub_501960(283, a1, 0, 0);
        }
    }
    else
    {
        result = (int*)a3;
        if (a3)
        {
            sub_57B810(a3, a1 + 80);
            sub_501960(37, a1, 0, 0);
            result = (int*)sub_537760();
            v4 = result;
            if (result)
            {
                v12 = sub_419D40(&byte_587000[204604]);
                v5 = sub_419A70(v12);
                result = (int*)sub_534BC0(*v4, v4[1], v5, 2, a1);
            }
        }
    }
    return result;
}

//----- (004E9FE0) --------------------------------------------------------
void __cdecl sub_4E9FE0(int a1, int a2, float* a3)
{
    int v3; // eax
    int v4; // eax
    float v5; // [esp+0h] [ebp-1Ch]
    float v6; // [esp+4h] [ebp-18h]
    int v7; // [esp+4h] [ebp-18h]

    if (a2)
    {
        v4 = sub_4EC580(a1);
        (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v4, a1, 20, 2);
    }
    else if (a3)
    {
        sub_57B810(a3, a1 + 80);
        sub_501960(37, a1, 0, 0);
        v6 = *(float*)(a1 + 68) * 0.043478262;
        v7 = sub_419A70(v6);
        v5 = *(float*)(a1 + 64) * 0.043478262;
        v3 = sub_419A70(v5);
        sub_534BC0(v3, v7, 20, 2, a1);
        return;
    }
    sub_4E5CC0(a1);
}

//----- (004EA080) --------------------------------------------------------
void __cdecl sub_4EA080(int a1, int a2, float* a3)
{
    int* v3; // ebp
    __int16 v4; // ax
    double v5; // st7
    double v6; // st7
    int v7; // eax
    int v8; // ecx
    int v9; // eax
    int v10; // eax
    float v11; // [esp+0h] [ebp-20h]
    float v12; // [esp+4h] [ebp-1Ch]
    int v13; // [esp+4h] [ebp-1Ch]
    int v14; // [esp+8h] [ebp-18h]
    int v15; // [esp+Ch] [ebp-14h]

    v3 = *(int**)(a1 + 700);
    if (a2)
    {
        if (sub_5330C0(a1, a2))
        {
            v8 = *(_DWORD*)(a2 + 8);
            if (v8 & 0x20006)
            {
                if (!(*(_DWORD*)(a2 + 16) & 0x8020))
                {
                    v9 = *(_DWORD*)(a1 + 508);
                    if (!v9 || (*(_BYTE*)(v9 + 8) & 4) != 4 || (*(_BYTE*)(v9 + 16) & 2) != 2)
                    {
                        if (!(v8 & 4))
                            goto LABEL_20;
                        if (sub_4FA4F0(a2, a1))
                        {
                            sub_52BE40(a1, a2);
                            return;
                        }
                        if (sub_4FF350(a2, 27) && sub_4E6E50((float2*)(a2 + 56), *(__int16*)(a2 + 124), (float2*)(a1 + 56)) & 1)
                        {
                            sub_52BE40(a1, a2);
                            sub_501960(122, a2, 0, 0);
                        }
                        else
                        {
                            LABEL_20:
                            v15 = *v3;
                            v10 = sub_4EC580(a1);
                            (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v10, a1, v15, 11);
                            sub_501960(96, a1, 0, 0);
                            sub_4E5CC0(a1);
                        }
                    }
                }
            }
        }
    }
    else if (a3)
    {
        sub_57B810(a3, a1 + 80);
        v4 = sub_509ED0((float2*)(a1 + 80));
        v5 = *(float*)(a1 + 80) + *(float*)(a1 + 64);
        *(_WORD*)(a1 + 126) = v4;
        *(float*)(a1 + 64) = v5;
        v6 = *(float*)(a1 + 84) + *(float*)(a1 + 68);
        *(float*)(a1 + 68) = v6;
        v14 = *v3;
        v12 = v6 * 0.043478262;
        v13 = sub_419A70(v12);
        v11 = *(float*)(a1 + 64) * 0.043478262;
        v7 = sub_419A70(v11);
        sub_534BC0(v7, v13, v14, 11, a1);
    }
    else
    {
        sub_4E5CC0(a1);
    }
}

//----- (004EA200) --------------------------------------------------------
void __cdecl sub_4EA200(int a1, int a2, float2* a3)
{
    int* v3; // ecx
    double v5; // st7
    int v8; // eax
    int v9; // eax
    float v10; // [esp+0h] [ebp-1Ch]
    float v11; // [esp+4h] [ebp-18h]
    int v12; // [esp+4h] [ebp-18h]
    int v13; // [esp+8h] [ebp-14h]
    int v14; // [esp+Ch] [ebp-10h]

    v3 = *(int**)(a1 + 700);
    if (a2)
    {
        v14 = *v3;
        v9 = sub_4EC580(a1);
        if ((*(int(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v9, a1, v14, 11))
            sub_4E5CC0(a1);
    }
    else if (a3)
    {
        v5 = *(float*)(a1 + 80);
        if (a3->field_0 * a3->field_4 <= 0.0)
        {
            *(float*)(a1 + 80) = *(float*)(a1 + 84);
        }
        else
        {
            *(float*)(a1 + 80) = -*(float*)(a1 + 84);
            v5 = -v5;
        }
        *(float*)(a1 + 84) = v5;
        v13 = *v3;
        v11 = *(float*)(a1 + 68) * 0.043478262;
        v12 = sub_419A70(v11);
        v10 = *(float*)(a1 + 64) * 0.043478262;
        v8 = sub_419A70(v10);
        sub_534BC0(v8, v12, v13, 11, a1);
    }
}

//----- (004EA2C0) --------------------------------------------------------
void __cdecl sub_4EA2C0(int a1, int a2)
{
    int v2; // eax

    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
        {
            v2 = *(_DWORD*)(a1 + 508);
            if (v2 != a2 && !v2)
            {
                *(_DWORD*)(a1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
                sub_4EC290(a2, a1);
            }
        }
    }
}

//----- (004EA300) --------------------------------------------------------
void __cdecl sub_4EA300(int a1, int a2, float* a3)
{
    char v3; // al

    if (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 12) != 4)
    {
        if (*(_DWORD*)(*(_DWORD*)(a1 + 748) + 12) == 5)
        {
            if (a2)
            {
                sub_501960(351, a1, 0, 0);
                sub_4E5CC0(a1);
                v3 = *(_BYTE*)(a2 + 8);
                ++* (_BYTE*)(a2 + 541);
                *(_WORD*)(a2 + 542) = 1000;
                if (v3 & 4)
                    sub_4DA2C0(a2, "objcoll.c:WebbingSlow", 0);
            }
        }
        else
        {
            sub_4E9D80(a1, a2, a3);
        }
    }
}

//----- (004EA380) --------------------------------------------------------
void __cdecl sub_4EA380(int a1, int a2)
{
    int v2; // eax

    if (a2)
    {
        sub_501960(351, a1, 0, 0);
        sub_4E5CC0(a1);
        v2 = sub_4EC580(a1);
        if ((*(int(__cdecl * *)(int, int, int, _DWORD, int))(a2 + 716))(a2, v2, a1, 0, 2))
        {
            if (*(_BYTE*)(a2 + 8) & 6)
                sub_4FF380(a2, 4, 4 * *(_WORD*)& byte_5D4594[2649704], 3);
            if (*(_BYTE*)(a2 + 8) & 4)
                sub_4DA2C0(a2, "objcoll.c:WebbingSlow", 0);
        }
    }
}

//----- (004EA400) --------------------------------------------------------
void __cdecl sub_4EA400(int a1, int a2)
{
    int v2; // eax
    int v3; // eax

    if (a2)
    {
        v2 = *(_DWORD*)(a2 + 16);
        if ((v2 & 0x8000) == 0)
        {
            if (sub_40A5C0(32))
            {
                if (*(_BYTE*)(a2 + 8) & 4)
                    sub_4EA490(a1, a2);
            }
            else if (sub_40A5C0(64))
            {
                v3 = *(_DWORD*)& byte_5D4594[1567996];
                if (!*(_DWORD*)& byte_5D4594[1567996])
                {
                    v3 = sub_4E3AA0((CHAR*)& byte_587000[204700]);
                    *(_DWORD*)& byte_5D4594[1567996] = v3;
                }
                if (*(unsigned __int16*)(a2 + 4) == v3 || *(_BYTE*)(a2 + 8) & 4)
                    sub_4EA800(a1, a2);
            }
        }
    }
}

//----- (004EA490) --------------------------------------------------------
void __cdecl sub_4EA490(int a1, int a2)
{
    int v2; // esi
    int v3; // edi
    char v4; // bp
    int v5; // ebx
    int v6; // esi
    unsigned __int16 v7; // ax
    int v8; // ebp
    int v9; // ebx
    char* v10; // eax
    char* v11; // esi
    char* v12; // eax
    _DWORD* v13; // eax
    int v14; // ebx
    float2* v15; // [esp-4h] [ebp-24h]
    unsigned __int8 v16; // [esp+10h] [ebp-10h]
    unsigned __int8 v17; // [esp+10h] [ebp-10h]
    char v18[10]; // [esp+14h] [ebp-Ch]
    int v19; // [esp+24h] [ebp+4h]
    int v20; // [esp+24h] [ebp+4h]

    v2 = a1;
    v3 = a2;
    a2 = *(_DWORD*)(a2 + 748);
    v4 = sub_4ECBD0(a1);
    v16 = *(_BYTE*)(a1 + 52);
    if (sub_419150(v3 + 48, a1 + 48))
    {
        v5 = *(_DWORD*)(a1 + 748);
        if (fabs(*(float*)(a1 + 56) - *(float*)v5) > * (double*)& byte_581450[10160]
            || fabs(*(float*)(a1 + 60) - *(float*)(v5 + 4)) > * (double*)& byte_581450[10160])
        {
            v15 = *(float2 * *)(a1 + 748);
            a2 = *(_DWORD*)(v3 + 36);
            sub_4E7010(a1, v15);
            sub_4DA180(4, &a2);
            *(_DWORD*)(v5 + 8) = 0;
            sub_4E82C0(*(_BYTE*)(v3 + 52), 0, v4, 0);
        }
        else
        {
            v6 = *(_DWORD*)(v3 + 504);
            if (v6)
            {
                while (1)
                {
                    if (*(_DWORD*)(v6 + 8) & 0x10000000)
                    {
                        v7 = sub_40A020(32);
                        v8 = *(_DWORD*)(v6 + 748);
                        v9 = v7;
                        v19 = sub_4ECBD0(v6);
                        v17 = *(_BYTE*)(v6 + 52);
                        sub_4D8E90(v3, 1);
                        sub_4D8EF0(v3);
                        if (sub_419130(v3 + 48))
                        {
                            v10 = sub_418AB0(*(unsigned __int8*)(v3 + 52));
                            sub_419090((int)v10, *((_DWORD*)v10 + 13) + 1);
                            if (*(_DWORD*)& byte_5D4594[2650652])
                            {
                                if (a2)
                                    sub_425CA0(*(_DWORD*)(a2 + 276), 0);
                            }
                        }
                        sub_4ED0C0(v3, (int*)v6);
                        sub_4DAA50(v6, 0, *(float*)v8, *(float*)(v8 + 4));
                        sub_4E46F0(v6, 0.0);
                        sub_4174B0(v6, 1);
                        *(_DWORD*)(v8 + 8) = 0;
                        sub_4E82C0(v17, 0, v19, 0);
                        *(_DWORD*)& v18[2] = *(_DWORD*)(v3 + 36);
                        *(_DWORD*)& v18[6] = v19;
                        sub_4DA180(5, v18);
                        if (v9 > 0)
                            break;
                    }
                    v6 = *(_DWORD*)(v6 + 496);
                    if (!v6)
                        return;
                }
                v11 = sub_418B10();
                if (v11)
                {
                    while (*((_DWORD*)v11 + 13) < v9)
                    {
                        v11 = sub_418B60((int)v11);
                        if (!v11)
                            return;
                    }
                    sub_40A4D0(8);
                    sub_4D8C80((int)v11, 0);
                }
            }
        }
    }
    else
    {
        v20 = *(_DWORD*)(a1 + 748);
        if (!*(_DWORD*)(v2 + 492))
        {
            v12 = sub_418AB0(*(unsigned __int8*)(v2 + 52));
            if (v12 && sub_418BC0((int)v12))
            {
                v13 = *(_DWORD * *)(v3 + 504);
                if (v13)
                {
                    while (!(v13[2] & 0x10000000))
                    {
                        v13 = (_DWORD*)v13[124];
                        if (!v13)
                            goto LABEL_27;
                    }
                    sub_4ED930(v3, v13);
                }
                LABEL_27:
                sub_4DADE0(v2);
                v14 = sub_4ECBD0(v2);
                sub_4F3070(v3, v2, 1);
                *(_DWORD*)(*(_DWORD*)(a2 + 276) + 4) |= 1u;
                sub_4D82F0(255, (_DWORD*)v2);
                *(_DWORD*)& v18[2] = *(_DWORD*)(v3 + 36);
                *(_DWORD*)& v18[6] = v14;
                sub_4DA180(6, v18);
                sub_417470(v2, 1);
                *(_DWORD*)(v20 + 8) = 0;
                sub_4E82C0(v16, 1, v4, *(_WORD*)(v3 + 36));
                sub_4EA7A0(v3);
            }
            else
            {
                sub_4DA2C0(v3, "objcoll.c:FlagNoTeam", 0);
            }
        }
    }
}

//----- (004EA7A0) --------------------------------------------------------
int __cdecl sub_4EA7A0(int a1)
{
    int i; // esi
    int result; // eax
    int v3; // eax

    for (i = 0; i < 32; ++i)
    {
        result = sub_4FF350(a1, i);
        if (result)
        {
            result = sub_424920(i);
            if (result)
            {
                v3 = sub_424920(i);
                result = sub_424A50(v3, 0x80000);
                if (result)
                    result = sub_4FF5B0(a1, i);
            }
        }
    }
    return result;
}

//----- (004EA800) --------------------------------------------------------
__int16 __cdecl sub_4EA800(int a1, int a2)
{
    char* v2; // eax
    int v3; // esi
    int* v4; // edi
    char* v5; // eax
    int v6; // ebx
    int v7; // edi
    int v8; // ebp
    int v9; // eax
    char* v10; // edi
    int v11; // edi
    int i; // eax
    int v13; // ebp
    int j; // edi
    int v15; // ebp
    char v17[10]; // [esp+0h] [ebp-Ch]

    LOWORD(v2) = *(_WORD*)& byte_5D4594[1567992];
    if (!*(_DWORD*)& byte_5D4594[1567992])
    {
        v2 = (char*)sub_4E3AA0((CHAR*)& byte_587000[204736]);
        *(_DWORD*)& byte_5D4594[1567992] = v2;
    }
    v3 = a2;
    if (*(_BYTE*)(a2 + 8) & 4)
    {
        v2 = (char*)sub_4E7C30(a2);
        if (!v2)
            return (__int16)v2;
        v3 = *(_DWORD*)(a2 + 516);
        if (!v3)
            return (__int16)v2;
        LOWORD(v2) = *(_WORD*)& byte_5D4594[1567992];
        while (*(unsigned __int16*)(v3 + 4) != *(_DWORD*)& byte_5D4594[1567992])
        {
            v3 = *(_DWORD*)(v3 + 512);
            if (!v3)
                return (__int16)v2;
        }
    }
    if (v3)
    {
        v4 = *(int**)(v3 + 748);
        if (*v4 && *(_BYTE*)(*v4 + 16) & 0x20)
            * v4 = 0;
        v5 = sub_418AB0(*(unsigned __int8*)(a1 + 52));
        v2 = sub_418B60((int)v5);
        v6 = (int)v2;
        if (!v2)
        {
            v2 = sub_418B10();
            v6 = (int)v2;
        }
        v7 = *v4;
        if (v7)
        {
            v2 = (char*) * (unsigned __int8*)(v7 + 52);
            if (v2 == (char*) * (unsigned __int8*)(v6 + 57))
            {
                v8 = (unsigned __int16)sub_40A020(64);
                sub_4D8E90(v7, 1);
                sub_4D8EF0(v7);
                sub_419090(v6, *(_DWORD*)(v6 + 52) + 1);
                if (*(_DWORD*)& byte_5D4594[2650652])
                {
                    v9 = *(_DWORD*)(v7 + 748);
                    if (v9)
                        sub_425CA0(*(_DWORD*)(v9 + 276), 0);
                }
                sub_501960(929, a1, 0, 0);
                *(_DWORD*)& v17[2] = *(_DWORD*)(v7 + 36);
                *(_DWORD*)& v17[6] = *(unsigned __int8*)(v6 + 57);
                sub_4DA180(9, v17);
                sub_522FF0(154, (float2*)(v3 + 56));
                if (v8 > 0)
                {
                    v10 = sub_418B10();
                    if (v10)
                    {
                        while (*((_DWORD*)v10 + 13) < v8)
                        {
                            v10 = sub_418B60((int)v10);
                            if (!v10)
                                goto LABEL_27;
                        }
                        sub_40A4D0(8);
                        sub_4D8C40((int)v10);
                    }
                }
                LABEL_27:
                if (!*(_DWORD*)& byte_5D4594[1567988])
                    * (_DWORD*)& byte_5D4594[1567988] = sub_4E3AA0((CHAR*)& byte_587000[204748]);
                v11 = 0;
                for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
                {
                    if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[1567988])
                        ++v11;
                }
                v13 = sub_415FA0(0, v11 - 1);
                v2 = (char*)sub_4DA790();
                for (j = (int)v2; v2; j = (int)v2)
                {
                    LOWORD(v2) = *(_WORD*)(j + 4);
                    if ((unsigned __int16)v2 == *(_DWORD*)& byte_5D4594[1567988])
                    {
                        if (!v13)
                        {
                            if (j)
                            {
                                v15 = *(_DWORD*)(v3 + 748);
                                sub_4EC300(v3);
                                sub_4EB9B0(v3, 0);
                                sub_419570(v3 + 48, *(_DWORD*)(v3 + 36));
                                sub_4EE6F0(v3);
                                *(_QWORD*)(v15 + 8) = sub_416BB0();
                                sub_4E7010(v3, (float2*)(j + 56));
                                sub_4E8290(0, 0);
                                LOWORD(v2) = sub_522FF0(129, (float2*)(v3 + 56));
                                *(_DWORD*)(v3 + 80) = 0;
                                *(_DWORD*)(v3 + 84) = 0;
                                *(_DWORD*)(v3 + 88) = 0;
                                *(_DWORD*)(v3 + 100) = 0;
                            }
                            return (__int16)v2;
                        }
                        --v13;
                    }
                    v2 = (char*)sub_4DA7A0(j);
                }
            }
        }
    }
    return (__int16)v2;
}

//----- (004EAAA0) --------------------------------------------------------
_DWORD* __cdecl sub_4EAAA0(int a1)
{
    _DWORD* result; // eax

    result = (_DWORD*)a1;
    if (*(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(*(_DWORD*)(a1 + 136) + 3))
    {
        *(_DWORD*)(a1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
        result = sub_501960(281, a1, 0, 0);
    }
    return result;
}

//----- (004EAAD0) --------------------------------------------------------
_DWORD* __cdecl sub_4EAAD0(int a1, int a2)
{
    _DWORD* result; // eax

    result = (_DWORD*)a2;
    if (a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        result = (_DWORD*)a1;
        if (*(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(*(_DWORD*)(a1 + 136) + 30))
        {
            *(_DWORD*)(a1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
            result = sub_501960(**(_DWORD * *)(a1 + 700), a1, 0, 0);
        }
    }
    return result;
}

//----- (004EAB20) --------------------------------------------------------
int __cdecl sub_4EAB20(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(*(_DWORD*)(a1 + 748) + 4) = 1;
    return result;
}

//----- (004EAB40) --------------------------------------------------------
void __cdecl sub_4EAB40(int a1, int a2)
{

    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
            (*(int(__cdecl * *)(int, int))(a1 + 732))(a2, a1);
    }
}

//----- (004EAB60) --------------------------------------------------------
void __cdecl sub_4EAB60(int a1, int a2)
{
    int v2; // ebx
    int v3; // eax
    int v4; // eax
    double v5; // st7

    v2 = *(_DWORD*)(a1 + 700);
    if (a2)
    {
        v3 = *(_DWORD*)(a2 + 8);
        if ((v3 & 0x80u) == 0)
        {
            if (*(_DWORD*)(a1 + 16) & 0x1000000)
            {
                v4 = *(_DWORD*)(a2 + 172);
                if (v4 == 3)
                {
                    if (*(float*)(a1 + 184) < (double) * (float*)(a2 + 184)
                        || *(float*)(a1 + 188) < (double) * (float*)(a2 + 188))
                    {
                        return;
                    }
                    LABEL_11:
                    if (sub_57B850((float2*)(a1 + 56), (float*)(a1 + 172), (float2*)(a2 + 56)))
                    {
                        *(_DWORD*)(a2 + 16) |= 0x60000u;
                        *(float*)(a2 + 164) = (double) * (int*)(v2 + 8);
                        *(float*)(a2 + 168) = (double) * (int*)(v2 + 12);
                        *(_DWORD*)(a2 + 156) = *(_DWORD*)(a1 + 56);
                        *(_DWORD*)(a2 + 160) = *(_DWORD*)(a1 + 60);
                    }
                    return;
                }
                if (v4 != 2)
                    goto LABEL_11;
                v5 = *(float*)(a2 + 176) + *(float*)(a2 + 176);
                if (v5 <= *(float*)(a1 + 184) && v5 <= *(float*)(a1 + 188))
                    goto LABEL_11;
            }
            else if (!*(_DWORD*)(v2 + 24) && (!(v3 & 4) || !sub_4FC250(a2, 4)))
            {
                if (*(_WORD*)(v2 + 20))
                    * (_DWORD*)(v2 + 16) = *(_DWORD*)& byte_5D4594[2598000] + *(unsigned __int16*)(v2 + 20);
                sub_502490((int*)v2, a2, a1);
                *(_DWORD*)(v2 + 24) = 1;
            }
        }
    }
}

//----- (004EACA0) --------------------------------------------------------
_DWORD* __cdecl sub_4EACA0(int a1, int a2)
{
    _DWORD* result; // eax
    int* v3; // ebx

    result = (_DWORD*)a1;
    v3 = *(int**)(a1 + 700);
    if (a2)
    {
        if ((signed char) * (_BYTE*)(a2 + 8) >= 0)
        {
            sub_522FF0(138, (float2*)(a2 + 56));
            sub_501960(147, a2, 0, 0);
            *(float*)(a2 + 164) = (double)* v3;
            *(float*)(a2 + 168) = (double)v3[1];
            sub_4E7190((_BYTE*)a2, (float*)(a2 + 164));
            sub_522FF0(137, (float2*)(a2 + 56));
            result = sub_501960(147, a2, 0, 0);
        }
    }
    return result;
}

//----- (004EAD20) --------------------------------------------------------
int __cdecl sub_4EAD20(int a1, int a2)
{
    int result; // eax

    result = a2;
    if (a2)
        result = sub_4FB550(a2, **(_DWORD * *)(a1 + 700), 1, 0, 0);
    return result;
}

//----- (004EAD50) --------------------------------------------------------
void __cdecl sub_4EAD50(int a1, int a2)
{
    _DWORD* v2; // edi
    char* v3; // eax

    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
        {
            v2 = *(_DWORD * *)(a1 + 748);
            if (*(_WORD*)(*(_DWORD*)(a2 + 748) + 4) < *(_WORD*)(*(_DWORD*)(a2 + 748) + 8) && *v2 > 0)
            {
                if (!sub_419130(a1 + 48)
                    || sub_419130(a2 + 48) && (v3 = sub_418AB0(*(unsigned __int8*)(a2 + 52))) != 0 && sub_419180(a1 + 48, v3[57]))
                {
                    sub_4EEB80(a2, 1);
                    --* v2;
                }
            }
        }
    }
}

//----- (004EADF0) --------------------------------------------------------
void __cdecl sub_4EADF0(int a1, int a2)
{
    int v2; // eax
    int v3; // [esp-8h] [ebp-Ch]

    if (*(float*)(a1 + 104) <= 0.0)
    {
        if (a2)
        {
            v3 = **(_DWORD * *)(a1 + 748);
            v2 = sub_4EC580(a1);
            (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v2, a1, v3, 2);
        }
    }
}

//----- (004EAE30) --------------------------------------------------------
void __cdecl sub_4EAE30(int a1, int a2)
{
    float* v2; // ebx
    int v3; // eax

    v2 = *(float**)(a1 + 700);
    if (a2)
    {
        if (!sub_4FF350(a2, 14))
        {
            if (!sub_40A5C0(4096) || (v3 = *(_DWORD*)(a1 + 508)) == 0 || *(_BYTE*)(v3 + 8) & 4)
            {
                if (*(_DWORD*)(a2 + 8) & 0x3001016)
                {
                    if (!sub_4FF350(a2, 0))
                        sub_522FF0(138, (float2*)(a2 + 56));
                    sub_501960(147, a2, 0, 0);
                    sub_4E7190((_BYTE*)a2, v2);
                    if (!sub_4FF350(a2, 0))
                        sub_522FF0(137, (float2*)(a2 + 56));
                    sub_501960(147, a2, 0, 0);
                }
            }
        }
    }
}

//----- (004EAF00) --------------------------------------------------------
void __cdecl sub_4EAF00(int a1, int a2, float* a3)
{
    int v3; // esi
    int v4; // ebx
    int v5; // eax
    int* v6; // ebp
    int v7; // edi
    char v8; // al
    int* v9; // eax
    int v10; // eax
    int v11; // ebp
    _DWORD* v12; // eax
    int v13; // ecx
    int v14; // eax
    int v15; // edx
    double v16; // st7
    char v17; // al
    int v18; // ecx
    int* v19; // edi
    int v20; // [esp-4h] [ebp-3Ch]
    _DWORD* v21; // [esp+10h] [ebp-28h]
    int v22[9]; // [esp+14h] [ebp-24h]
    int v23; // [esp+3Ch] [ebp+4h]
    int v24; // [esp+40h] [ebp+8h]

    v3 = a1;
    v20 = a1;
    v4 = *(_DWORD*)(a1 + 748);
    v23 = 1;
    v5 = sub_4E7980(v20);
    v6 = (int*)v5;
    v21 = (_DWORD*)v5;
    if (!v5 || *(_BYTE*)(v5 + 16) & 0x20)
    {
        sub_4E5CC0(v3);
    }
    else
    {
        v7 = a2;
        if (!a2 || *(_BYTE*)(a2 + 24) & 0x30)
            sub_522FF0(150, (float2*)(v3 + 56));
        if (!a2)
        {
            if (!a3)
                return;
            if (*(_BYTE*)(v4 + 4))
                sub_57B810(a3, v3 + 80);
            else
                sub_4EB3E0(v3);
            v8 = *(_BYTE*)(v4 + 4);
            if (v8)
            {
                *(_BYTE*)(v4 + 4) = v8 - 1;
            }
            else if (!*(_BYTE*)(v4 + 24))
            {
                *(_BYTE*)(v4 + 24) = 2;
                v23 = 0;
            }
            v9 = (int*)sub_537760();
            if (v9)
                sub_534BC0(*v9, v9[1], 1, 0, v3);
            if (*(_BYTE*)(v4 + 24) == 1)
            {
                sub_4ED790(v3, v6, (float2*)(v3 + 56));
                sub_4E5CC0(v3);
                return;
            }
            if (!*(_BYTE*)(v4 + 4) && v23)
            {
                *(_BYTE*)(v4 + 24) = 0;
                *(_DWORD*)(v4 + 8) = *(_DWORD*)(v3 + 508);
                return;
            }
            LABEL_50:
            sub_4EB250(v3);
            return;
        }
        if (a2 == *(_DWORD*)(v3 + 508))
        {
            sub_4ED0C0(v3, v6);
            sub_4F3070(*(_DWORD*)(v3 + 508), (int)v6, 1);
            v10 = *(_DWORD*)(v3 + 508);
            if (v10 && *(_BYTE*)(v10 + 8) & 4 && !*(_DWORD*)(*(_DWORD*)(v10 + 748) + 104))
                sub_53A420((_DWORD*)v10, (int)v6, 1, 1);
            sub_501960(892, v3, 0, 0);
            sub_4E5CC0(v3);
        }
        else
        {
            if (sub_4EC520(v3, a2))
                return;
            v11 = *(_DWORD*)(v3 + 508);
            v12 = sub_413250(*(unsigned __int16*)(v3 + 4));
            v24 = (int)v12;
            if (!v11 || *(_DWORD*)(v11 + 16) & 0x8020)
            {
                sub_4ED790(v3, v21, (float2*)(v3 + 56));
                sub_4E5CC0(v3);
            }
            else
            {
                v13 = *(_DWORD*)(v7 + 16);
                if ((v13 & 0x8000) == 0 && v12)
                {
                    v14 = sub_4F9FD0(v11);
                    v15 = *(_DWORD*)(v3 + 60);
                    v22[4] = *(_DWORD*)(v3 + 56);
                    v22[7] = v3;
                    v22[5] = v15;
                    *(float*)v22 = sub_4EF1E0(v14, v24);
                    v16 = *(float*)(v3 + 176) + 30.0;
                    LOBYTE(v22[1]) = 0;
                    v22[3] = v11;
                    *(float*)& v22[2] = v16;
                    v22[6] = 0;
                    sub_538840(v3, v11, (int)v22);
                    sub_538290(v7, v11, v3, (int)v22);
                    (*(void(__cdecl * *)(int, int, int, _DWORD, _DWORD))(v7 + 716))(
                            v7,
                            v11,
                            v3,
                            (__int64)(*(float*)v22 + *(double*)& byte_581450[9544]),
                            0);
                    if (!(*(_DWORD*)(v7 + 16) & 0x8020))
                        * (_DWORD*)(v4 + 12) = v7;
                    if (*(_BYTE*)(v4 + 4))
                        sub_4E0A70(v3, v7);
                    else
                        sub_4EB3E0(v3);
                    v17 = *(_BYTE*)(v4 + 4);
                    if (v17 || *(_BYTE*)(v4 + 24))
                    {
                        v18 = 1;
                    }
                    else
                    {
                        *(_BYTE*)(v4 + 24) = 2;
                        v18 = 0;
                    }
                    if (v17)
                        * (_BYTE*)(v4 + 4) = v17 - 1;
                    if (*(_BYTE*)(v4 + 24) == 1)
                    {
                        v19 = (int*)sub_4E7980(v3);
                        sub_501960(893, v3, 0, 0);
                        sub_4ED0C0(v3, v19);
                        sub_4DAA50((int)v19, 0, *(float*)(v3 + 56), *(float*)(v3 + 60));
                        sub_4E5CC0(v3);
                        return;
                    }
                    if (!*(_BYTE*)(v4 + 4) && v18)
                    {
                        *(_DWORD*)(v4 + 8) = v11;
                        *(_BYTE*)(v4 + 24) = 0;
                        return;
                    }
                    goto LABEL_50;
                }
            }
        }
    }
}

//----- (004EB250) --------------------------------------------------------
int __cdecl sub_4EB250(int a1)
{
    float* v1; // esi
    int v2; // ebx
    int result; // eax
    double v4; // st7
    double v5; // st6
    float v6; // [esp+Ch] [ebp-14h]
    float4 a1a; // [esp+10h] [ebp-10h]
    float v8; // [esp+24h] [ebp+4h]

    v1 = (float*)a1;
    v2 = *(_DWORD*)(a1 + 748);
    *(_DWORD*)& byte_5D4594[1567928] = 0;
    *(_DWORD*)& byte_5D4594[1567932] = *(_DWORD*)(v2 + 12);
    *(_DWORD*)& byte_5D4594[1567840] = *(_DWORD*)(a1 + 508);
    *(_DWORD*)& byte_5D4594[1567924] = a1;
    *(_DWORD*)& byte_5D4594[1567836] = 1259902592;
    a1a.field_0 = *(float*)(a1 + 56) - 400.0;
    a1a.field_4 = *(float*)(a1 + 60) - 400.0;
    a1a.field_8 = *(float*)(a1 + 56) + 400.0;
    a1a.field_C = *(float*)(a1 + 60) + 400.0;
    sub_517C10(&a1a, sub_4EB340, a1 + 56);
    result = *(_DWORD*)& byte_5D4594[1567928];
    if (*(_DWORD*)& byte_5D4594[1567928])
    {
        *(_BYTE*)(v2 + 24) = 2;
        result = *(_DWORD*)& byte_5D4594[1567928];
        v4 = *(float*)(*(_DWORD*)& byte_5D4594[1567928] + 56) - *(float*)(a1 + 56);
        v5 = *(float*)(*(_DWORD*)& byte_5D4594[1567928] + 60) - *(float*)(a1 + 60);
        v8 = v5;
        v6 = sqrt(v5 * v8 + v4 * v4) + *(double*)& byte_581450[10176];
        v1[20] = v4 * v1[136] / v6;
        v1[21] = v8 * v1[136] / v6;
    }
    return result;
}

//----- (004EB340) --------------------------------------------------------
void __cdecl sub_4EB340(float* a1, int a2)
{
    double v2; // st7
    double v3; // st6
    double v4; // st5

    if ((_DWORD)a1[2] & 0x20006)
    {
        if (!((_DWORD)a1[4] & 0x8020)
            && !sub_4FF350((int)a1, 0)
            && a1 != *(float**)& byte_5D4594[1567840]
            && a1 != *(float**)& byte_5D4594[1567932])
        {
            if (sub_537110((int)a1, *(int*)& byte_5D4594[1567924]))
            {
                v2 = *(float*)a2 - a1[14];
                v3 = *(float*)(a2 + 4) - a1[15];
                v4 = v3 * v3 + v2 * v2;
                if (v4 <= 160000.0 && v4 < *(float*)& byte_5D4594[1567836])
                {
                    *(float*)& byte_5D4594[1567836] = v4;
                    *(_DWORD*)& byte_5D4594[1567928] = a1;
                }
            }
        }
    }
}

//----- (004EB3E0) --------------------------------------------------------
void __cdecl sub_4EB3E0(int a1)
{
    int v1; // esi
    float* v2; // edi
    int v3; // ebx
    int v4; // eax
    int v5; // ecx
    double v6; // st7
    int v7; // eax
    float2* v8; // [esp-4h] [ebp-10h]
    float v9; // [esp+10h] [ebp+4h]

    v1 = a1;
    v2 = (float*)(a1 + 80);
    v8 = (float2*)(a1 + 80);
    v9 = sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84));
    v3 = sub_509ED0(v8);
    v4 = sub_415FA0(-64, 64) + v3 + 128;
    if (v4 < 0)
        v4 += (unsigned int)(255 - v4) >> 8 << 8;
    if (v4 >= 256)
        v4 += -256 * ((unsigned int)v4 >> 8);
    v5 = *(_DWORD*)(v1 + 76);
    *v2 = v9 * *(float*)& byte_587000[8 * v4 + 194136];
    v6 = v9 * *(float*)& byte_587000[8 * v4 + 194140];
    v7 = *(_DWORD*)(v1 + 72);
    *(_DWORD*)(v1 + 68) = v5;
    *(_DWORD*)(v1 + 64) = v7;
    *(_DWORD*)(v1 + 56) = v7;
    *(float*)(v1 + 84) = v6;
    *(_DWORD*)(v1 + 60) = v5;
    sub_517970(v1);
}

//----- (004EB490) --------------------------------------------------------
void __cdecl sub_4EB490(int a1, int a2)
{
    int v2; // esi
    _DWORD* v3; // ebp
    int v4; // eax
    int v5; // ebx
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // ecx
    double v10; // st7
    int v11; // edx
    int v12; // eax
    int v13; // eax
    char v14; // al
    _WORD* v15; // edi
    int* v16; // edi
    double v17; // st7
    int v18; // [esp-8h] [ebp-3Ch]
    int v19; // [esp-4h] [ebp-38h]
    int v20; // [esp-4h] [ebp-38h]
    int v21[9]; // [esp+10h] [ebp-24h]
    int v22; // [esp+38h] [ebp+4h]

    v2 = a1;
    v19 = *(unsigned __int16*)(a1 + 4);
    v22 = *(_DWORD*)(a1 + 700);
    v3 = sub_413250(v19);
    if (!v3)
        return;
    v4 = *(_DWORD*)(v2 + 508);
    if (v4 == a2)
    {
        if (a2)
            return;
    }
    if (v4)
        v5 = sub_4F9FD0(*(_DWORD*)(v2 + 508));
    else
        v5 = 30;
    if (sub_40A5C0(4096))
    {
        v6 = sub_4EC580(v2);
        if (v6)
        {
            if (!a2)
                goto LABEL_24;
            if (*(_BYTE*)(v6 + 8) & 4 && *(_BYTE*)(a2 + 8) & 4 && !sub_5330C0(v6, a2))
                return;
        }
    }
    if (!a2)
    {
        LABEL_24:
        v16 = (int*)sub_537760();
        if (v16)
        {
            v17 = sub_4EF1E0(v5, (int)v3);
            sub_534BC0(*v16, v16[1], (__int64)v17, 11, v2);
            sub_4E5CC0(v2);
            return;
        }
        goto LABEL_27;
    }
    sub_4F9FD0(*(_DWORD*)(v2 + 508));
    if (!*(_DWORD*)& byte_5D4594[1568000])
        * (_DWORD*)& byte_5D4594[1568000] = sub_4E3AA0((CHAR*)& byte_587000[204860]);
    v7 = *(_DWORD*)(a2 + 16);
    if ((v7 & 0x8000) == 0)
    {
        v8 = *(_DWORD*)(v2 + 56);
        v9 = *(_DWORD*)(v2 + 60);
        v21[7] = v2;
        v21[4] = v8;
        v21[5] = v9;
        v10 = sub_4EF1E0(v5, (int)v3);
        v11 = *(_DWORD*)(v2 + 176);
        *(float*)v21 = v10;
        v12 = *(_DWORD*)(v22 + 4);
        LOBYTE(v21[1]) = 11;
        v21[3] = v12;
        v21[2] = v11;
        v21[6] = 0;
        sub_538840(v2, v12, (int)v21);
        if (*(_DWORD*)(v2 + 508) != a2)
            sub_538290(a2, *(_DWORD*)(v22 + 4), v2, (int)v21);
        v20 = LOBYTE(v21[1]);
        v18 = (__int64)(*(float*)v21 + *(double*)& byte_581450[9544]);
        v13 = sub_4EC580(v2);
        v14 = (*(int(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v13, v2, v18, v20);
        if (*(unsigned __int16*)(v2 + 4) == *(_DWORD*)& byte_5D4594[1568000])
        {
            v15 = *(_WORD * *)(a2 + 556);
            if (v15 && !*v15)
            {
                if (!v15[2])
                    sub_4E5CC0(v2);
                return;
            }
        }
        else if (!v14)
        {
            return;
        }
        LABEL_27:
        sub_4E5CC0(v2);
    }
}

//----- (004EB6A0) --------------------------------------------------------
void __cdecl sub_4EB6A0(int a1, int a2)
{
    int v2; // eax
    _DWORD* v3; // ebp
    _DWORD* v4; // ebx
    int v5; // eax
    int v6; // eax
    float v7; // [esp+0h] [ebp-24h]
    float v8; // [esp+4h] [ebp-20h]
    int v9; // [esp+4h] [ebp-20h]
    int v10; // [esp+8h] [ebp-1Ch]
    int v11; // [esp+Ch] [ebp-18h]
    int v12; // [esp+Ch] [ebp-18h]
    float v13; // [esp+10h] [ebp-14h]

    v2 = *(_DWORD*)& byte_5D4594[1568004];
    v3 = *(_DWORD * *)(a1 + 508);
    v4 = (_DWORD*)v3[187];
    if (!*(_DWORD*)& byte_5D4594[1568004])
    {
        v13 = sub_419D40(&byte_587000[204872]);
        v2 = sub_419A70(v13);
        *(_DWORD*)& byte_5D4594[1568004] = v2;
    }
    if (!a2)
    {
        v10 = v2;
        v8 = *(float*)(a1 + 68) * 0.043478262;
        v9 = sub_419A70(v8);
        v7 = *(float*)(a1 + 64) * 0.043478262;
        v6 = sub_419A70(v7);
        sub_534BC0(v6, v9, v10, 11, a1);
        LABEL_13:
        v4[33] = 0;
        sub_4FC300(v3, 3);
        sub_4E5CC0(a1);
        v4[34] = 0;
        return;
    }
    if (!(*(_DWORD*)(a2 + 16) & 0x8020) && (_DWORD*)a2 != v3)
    {
        v11 = v2;
        v5 = sub_4EC580(a1);
        if ((*(int(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v11, 11)
            && (sub_5330C0((int)v3, a2) || sub_417DA0(1) && *(_BYTE*)(a2 + 8) & 6))
        {
            v4[33] = a2;
            v4[36] = *(_DWORD*)(a2 + 56);
            v4[37] = *(_DWORD*)(a2 + 60);
            v4[38] = *(_DWORD*)& byte_5D4594[2598000];
            v12 = *(_DWORD*)(a1 + 508);
            *(_DWORD*)(a1 + 16) |= 0x40u;
            sub_4E7540(v12, a2);
            sub_501960(999, (int)v3, 0, 0);
            return;
        }
        sub_532E20(a2, a1);
        goto LABEL_13;
    }
}

//----- (004EB800) --------------------------------------------------------
void __cdecl sub_4EB800(int a1, int a2)
{
    int* v2; // esi
    int v3; // edi
    int v4; // eax
    int v5; // eax
    int* v6; // eax

    v2 = *(int**)(a1 + 700);
    if (sub_40A5C0(2048))
        v3 = *v2;
    else
        v3 = v2[1];
    if (a2)
    {
        v4 = *(_DWORD*)(a2 + 16);
        if ((v4 & 0x8000) == 0)
        {
            v5 = sub_4EC580(a1);
            (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v3, 3);
            sub_4E5CC0(a1);
        }
    }
    else
    {
        v6 = (int*)sub_537760();
        if (v6)
            sub_534BC0(*v6, v6[1], v3, 11, a1);
        sub_4E5CC0(a1);
    }
}

//----- (004EB890) --------------------------------------------------------
void __cdecl sub_4EB890(int* a1, int a2)
{
    _DWORD* v2; // eax

    if (a2 && sub_4E9A30((int)a1, a2))
    {
        v2 = sub_4E3810((CHAR*)& byte_587000[204888]);
        if (v2)
        {
            sub_4DAA50((int)v2, a1[127], *((float*)a1 + 14), *((float*)a1 + 15));
            sub_4E5CC0((int)a1);
            sub_4FF380(a2, 5, 90, 5);
            sub_4FF380(a2, 14, 90, 5);
            sub_501960(846, (int)a1, 0, 0);
        }
    }
}

//----- (004EB910) --------------------------------------------------------
void __cdecl sub_4EB910(int* a1, int a2)
{
    _DWORD* v2; // edi
    _DWORD* v3; // edi
    float v4; // [esp+0h] [ebp-14h]

    if (a2 && sub_4E9A30((int)a1, a2))
    {
        v2 = sub_4E3810((CHAR*)& byte_587000[204904]);
        if (v2)
        {
            sub_4DAA50((int)v2, a1[127], *((float*)a1 + 14), *((float*)a1 + 15));
            v3 = (_DWORD*)v2[187];
            v4 = sub_419D40(&byte_587000[204916]) * (double) * (int*)& byte_5D4594[2649704];
            *v3 = sub_419A70(v4);
            sub_501960(847, (int)a1, 0, 0);
            sub_4E5CC0((int)a1);
        }
    }
}

//----- (004EB9B0) --------------------------------------------------------
int __cdecl sub_4EB9B0(int a1, int a2)
{
    _DWORD* v2; // esi
    int result; // eax

    v2 = *(_DWORD * *)(a1 + 748);
    result = a2;
    if (a2 && (result = sub_4EC580(a2)) != 0 && *(_BYTE*)(result + 8) & 4)
    {
        *v2 = result;
        v2[1] = *(unsigned __int8*)(result + 52);
        v2[4] = *(_DWORD*)& byte_5D4594[2598000];
    }
    else
    {
        *v2 = 0;
        v2[1] = 0;
    }
    return result;
}

//----- (004EBA00) --------------------------------------------------------
_DWORD* __cdecl sub_4EBA00(int a1, int a2)
{
    char* v2; // ebp
    _DWORD* v3; // ebx
    _DWORD* result; // eax

    v2 = 0;
    v3 = *(_DWORD * *)(a1 + 748);
    if (a2)
    {
        v2 = sub_418AB0(*(unsigned __int8*)(a2 + 52));
        if (*v3 == a2 && v2 && sub_418BC0((int)v2) > 1)
        {
            if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1568008]) > 0x2D)
            {
                sub_4DA2C0(a2, "objcoll.c:CantPickupBall", 0);
                *(_DWORD*)& byte_5D4594[1568008] = *(_DWORD*)& byte_5D4594[2598000];
            }
            return sub_501960(928, a1, 0, 0);
        }
    }
    if (*(_DWORD*)(a1 + 508) || !a2 || !(*(_BYTE*)(a2 + 8) & 4))
        return sub_501960(928, a1, 0, 0);
    result = *(_DWORD * *)(a2 + 516);
    if (!result)
    {
        LABEL_17:
        sub_4EC290(a2, a1);
        if (sub_419130(a1 + 48))
        {
            if (!v2)
            {
                LABEL_25:
                sub_4EB9B0(a1, a2);
                sub_501960(927, a1, 0, 0);
                *(_DWORD*)(a1 + 16) |= 0x40u;
                return (_DWORD*)sub_4EA7A0(a2);
            }
            sub_4196D0(a1 + 48, (int)v2, *(_DWORD*)(a1 + 36), 0);
        }
        else
        {
            sub_4191D0(*(_BYTE*)(a2 + 52), a1 + 48, 1, *(_DWORD*)(a1 + 36), 0);
        }
        if (v2)
        {
            if (v2[56] == 2)
                sub_4E8290(4, *(_WORD*)(a2 + 36));
            else
                sub_4E8290(2, *(_WORD*)(a2 + 36));
        }
        goto LABEL_25;
    }
    while (*((_WORD*)result + 2) != *(_WORD*)(a1 + 4))
    {
        result = (_DWORD*)result[128];
        if (!result)
            goto LABEL_17;
    }
    return result;
}

//----- (004EBB50) --------------------------------------------------------
int __cdecl sub_4EBB50(int a1, int a2)
{
    int result; // eax

    result = a2;
    if (a2 && !(*(_DWORD*)(a2 + 16) & 0x8020))
    {
        if (*(_BYTE*)(a2 + 8) & 4)
            result = sub_4F3400(a2, a1, 1);
    }
    return result;
}

//----- (004EBB80) --------------------------------------------------------
__int16 __cdecl sub_4EBB80(int a1, int a2)
{
    int v2; // esi
    int v3; // eax
    int* v4; // edi
    char* v5; // esi
    char* v6; // ebp
    int v7; // edi
    int v8; // edi
    int v9; // esi
    int i; // eax
    int v11; // edi
    int j; // esi
    int v14; // [esp+10h] [ebp-4h]

    v2 = sub_4E3AA0((CHAR*)& byte_587000[204964]);
    v3 = sub_4E3AA0((CHAR*)& byte_587000[204976]);
    v14 = v3;
    if (a2)
    {
        LOWORD(v3) = *(_WORD*)(a2 + 4);
        if ((unsigned __int16)v3 == v2)
        {
            v4 = *(int**)(a2 + 748);
            v5 = 0;
            v6 = 0;
            if (sub_419130(a1 + 48))
                v5 = sub_418AB0(*(unsigned __int8*)(a1 + 52));
            if (*v4 && sub_419130(*v4 + 48))
                v6 = sub_418AB0(*(unsigned __int8*)(*v4 + 52));
            if (v5 == v6)
            {
                sub_4D8E90(*v4, 1);
                sub_4D8EF0(*v4);
            }
            if (v5)
            {
                sub_419090((int)v5, *((_DWORD*)v5 + 13) + 1);
                if (*(_DWORD*)& byte_5D4594[2650652])
                {
                    v7 = *v4;
                    if (v7)
                    {
                        v8 = *(_DWORD*)(v7 + 748);
                        if (v8)
                            sub_425CA0(*(_DWORD*)(v8 + 276), 0);
                    }
                }
                sub_501960(929, a1, 0, 0);
                sub_522FF0(154, (float2*)(a2 + 56));
            }
            v9 = 0;
            for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
            {
                if (*(unsigned __int16*)(i + 4) == v14)
                    ++v9;
            }
            v11 = sub_415FA0(0, v9 - 1);
            v3 = sub_4DA790();
            for (j = v3; v3; j = v3)
            {
                LOWORD(v3) = v14;
                if (*(unsigned __int16*)(j + 4) == v14)
                {
                    if (!v11)
                    {
                        if (j)
                        {
                            sub_4EC300(a2);
                            sub_4E7010(a2, (float2*)(j + 56));
                            LOWORD(v3) = sub_522FF0(129, (float2*)(a2 + 56));
                            *(_DWORD*)(a2 + 80) = 0;
                            *(_DWORD*)(a2 + 84) = 0;
                            *(_DWORD*)(a2 + 88) = 0;
                            *(_DWORD*)(a2 + 100) = 0;
                        }
                        return v3;
                    }
                    --v11;
                }
                v3 = sub_4DA7A0(j);
            }
        }
    }
    return v3;
}

//----- (004EBD40) --------------------------------------------------------
void __cdecl sub_4EBD40(int a1, int a2, int a3)
{
    int v3; // ebx
    int* v4; // esi
    unsigned __int16 v5; // ax
    int v6; // esi
    int v7; // edi
    int v8; // esi
    int v9; // eax
    int v10; // eax
    int v11; // [esp+14h] [ebp+4h]

    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 2 && *(_BYTE*)(a2 + 12) & 0x40)
        {
            v3 = a1;
            v4 = *(int**)(a1 + 700);
            v5 = sub_4EE780(a2);
            v6 = *v4;
            v11 = v6;
            v7 = v5;
            v8 = *(_DWORD*)(v6 + 72);
            if (v8 <= v5)
            {
                if (v8)
                {
                    v10 = sub_4EC580(v3);
                    (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v10, v3, v8, 6);
                    sub_4E5CC0(v3);
                    *(_DWORD*)(v11 + 72) -= v8;
                }
                else
                {
                    sub_4E5CC0(v3);
                }
            }
            else
            {
                v9 = sub_4EC580(v3);
                (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v9, v3, v7, 6);
                *(_DWORD*)(v11 + 72) = v8 - v7;
            }
        }
    }
    else if (!a3)
    {
        sub_4E5CC0(a1);
    }
}

//----- (004EBE10) --------------------------------------------------------
void __cdecl sub_4EBE10(int a1, int a2)
{
    if (a2)
    {
        if (*(_BYTE*)(a2 + 8) & 4)
            sub_502490((int*)(*(_DWORD*)(a1 + 748) + 72), a2, a1);
    }
}

//----- (004EBE40) --------------------------------------------------------
void __cdecl sub_4EBE40(int a1, int a2)
{
    float2* v2; // edi
    int v3; // esi
    int v4; // eax
    int v5; // ecx
    int v6; // esi
    _DWORD* v7; // [esp+Ch] [ebp+4h]

    v2 = (float2*)a1;
    v7 = *(_DWORD * *)(a1 + 700);
    if (sub_40A5C0(4096) && a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        sub_4D7520(0);
        v3 = 1;
        v4 = sub_4DA7C0();
        if (!v4)
            goto LABEL_17;
        do
        {
            v5 = *(_DWORD*)(v4 + 748);
            if (*(_DWORD*)(*(_DWORD*)(v5 + 276) + 4792) == 1 && *(_DWORD*)(v5 + 308))
                v3 = 0;
            v4 = sub_4DA7F0(v4);
        } while (v4);
        if (v3 == 1)
            LABEL_17:
            sub_4D71E0(*(int*)& byte_5D4594[2598000]);
        v6 = *(_DWORD*)(a2 + 748);
        if (*(float2 * *)(v6 + 308) != v2
            || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *v7) > * (int*)& byte_5D4594[2649704])
        {
            sub_501960(1005, (int)v2, 0, 0);
            sub_522FF0(130, v2 + 7);
            sub_4DA2C0(a2, "objcoll.c:SoulGateCollide", 0);
        }
        *(_DWORD*)(v6 + 308) = v2;
        *v7 = *(_DWORD*)& byte_5D4594[2598000];
    }
}

//----- (004EBF40) --------------------------------------------------------
void __cdecl sub_4EBF40(int a1, int a2)
{
    int v2; // esi
    int v3; // ebp
    int v4; // ebx
    int v5; // ecx
    _DWORD* v6; // eax
    int v7; // edi
    int v8; // eax
    int v9; // edx
    int v10; // eax
    _DWORD* v11; // ecx
    _DWORD* v12; // eax
    int v13; // edx
    int v14; // eax
    _DWORD* v15; // ecx
    unsigned __int8 v16; // al
    float v17; // [esp+0h] [ebp-20h]
    int v18; // [esp+14h] [ebp-Ch]
    int v19; // [esp+18h] [ebp-8h]

    v2 = a2;
    v3 = *(_DWORD*)(a1 + 692);
    v19 = 0;
    if (a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        v4 = *(_DWORD*)(a2 + 748);
        v5 = 0;
        v6 = (_DWORD*)(*(_DWORD*)(v4 + 276) + 4796);
        while (*v6 != a1)
        {
            ++v5;
            ++v6;
            if (v5 >= 5)
                goto LABEL_8;
        }
        v19 = 1;
        LABEL_8:
        v18 = 0;
        v7 = v3 + 50;
        do
        {
            if (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v7 + 26) > (unsigned int)(240
                                                                                        * *(_DWORD*)& byte_5D4594[2649704]))
            {
                nox_wcscpy((wchar_t*)(v7 - 50), (const wchar_t*)& byte_5D4594[1568012]);
                *(_BYTE*)(v7 + 1) = byte_5D4594[1568016];
                *(_BYTE*)v7 = 0;
                *(_DWORD*)(v7 + 26) = 0;
            }
            v8 = *(_DWORD*)(v4 + 276);
            if (*(_BYTE*)v7 == *(_BYTE*)(v8 + 2251) && !nox_wcscmp((const wchar_t*)(v7 - 50), (const wchar_t*)(v8 + 2185)))
            {
                if (!strcmp((const char*)(v7 + 1), (const char*)(*(_DWORD*)(v4 + 276) + 2112)))
                {
                    v9 = *(_DWORD*)(v4 + 276);
                    v10 = 0;
                    v11 = (_DWORD*)(v9 + 4796);
                    while (*v11)
                    {
                        ++v10;
                        ++v11;
                        if (v10 >= 5)
                        {
                            v2 = a2;
                            goto LABEL_17;
                        }
                    }
                    v2 = a2;
                    *(_DWORD*)(v9 + 4 * v10 + 4796) = a1;
                    LABEL_17:
                    if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[1567940]) <= 0x5DC)
                        return;
                    sub_4DA2C0(v2, "objcoll.c:ExtraLifeAlreadyAwarded", 0);
                    LABEL_19:
                    sub_501960(925, v2, 0, 0);
                    *(_QWORD*)& byte_5D4594[1567940] = sub_416BB0();
                    return;
                }
                v2 = a2;
            }
            v7 += 80;
            ++v18;
        } while (v18 < 64);
        if (v19 == 1)
            goto LABEL_17;
        v17 = sub_419D40(&byte_587000[205104]);
        if (*(_DWORD*)(v4 + 320) < sub_419A70(v17))
        {
            v12 = sub_4E3810((CHAR*)& byte_587000[205156]);
            if (v12)
                ((void(__cdecl*)(int, _DWORD*, int, _DWORD))v12[177])(v2, v12, 1, 0);
            *(_DWORD*)(a1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
            sub_501960(1004, a1, 0, 0);
            sub_522FF0(130, (float2*)(a1 + 56));
            sub_4DA2C0(v2, "objcoll.c:AwardExtraLife", 0);
            v13 = *(_DWORD*)(v4 + 276);
            v14 = 0;
            v15 = (_DWORD*)(v13 + 4796);
            while (*v15)
            {
                ++v14;
                ++v15;
                if (v14 >= 5)
                    goto LABEL_35;
            }
            *(_DWORD*)(v13 + 4 * v14 + 4796) = a1;
            LABEL_35:
            nox_wcscpy((wchar_t*)(v3 + 80 * *(unsigned __int8*)(v3 + 5120)), (const wchar_t*)(*(_DWORD*)(v4 + 276) + 2185));
            *(_BYTE*)(80 * *(unsigned __int8*)(v3 + 5120) + v3 + 50) = *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251);
            strcpy((char*)(80 * *(unsigned __int8*)(v3 + 5120) + v3 + 51), (const char*)(*(_DWORD*)(v4 + 276) + 2112));
            *(_DWORD*)(80 * *(unsigned __int8*)(v3 + 5120) + v3 + 76) = *(_DWORD*)& byte_5D4594[2598000];
            v16 = *(_BYTE*)(v3 + 5120) + 1;
            *(_BYTE*)(v3 + 5120) = v16;
            if (v16 >= 0x40u)
                * (_BYTE*)(v3 + 5120) = 0;
        }
        else if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[1567940]) > 0x5DC)
        {
            sub_4DA2C0(v2, "pickup.c:MaxTradableAnkhsReached", 0);
            goto LABEL_19;
        }
    }
}

//----- (004EC290) --------------------------------------------------------
void __cdecl sub_4EC290(int a1, int a2)
{
    int v2; // eax

    if (a2)
    {
        sub_4EC300(a2);
        v2 = a1;
        if (a1)
        {
            while (*(_BYTE*)(v2 + 16) & 0x20)
            {
                v2 = *(_DWORD*)(v2 + 508);
                if (!v2)
                    goto LABEL_8;
            }
            if (v2)
            {
                *(_DWORD*)(a2 + 512) = *(_DWORD*)(v2 + 516);
                *(_DWORD*)(v2 + 516) = a2;
            }
        }
        LABEL_8:
        *(_DWORD*)(a2 + 508) = v2;
        if (*(_BYTE*)(a2 + 8) & 2)
            sub_5346F0(a2);
        if (*(_BYTE*)(a2 + 8) & 6)
            sub_4E8020(a2);
    }
}

//----- (004EC300) --------------------------------------------------------
void __cdecl sub_4EC300(int a1)
{
    int v1; // eax
    int v2; // edx
    int v3; // edi
    int v4; // edx
    int v5; // ecx
    int v6; // eax
    char v7; // al

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 508);
        if (v1)
        {
            if (*(_BYTE*)(v1 + 8) & 4 && sub_500CC0(v1, a1))
            {
                v2 = *(_DWORD*)(a1 + 12);
                LOBYTE(v2) = v2 & 0x7F;
                v3 = *(_DWORD*)(*(_DWORD*)(a1 + 508) + 748);
                *(_DWORD*)(a1 + 12) = v2;
                sub_4D9200(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), a1);
                sub_417300(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), a1, 1);
            }
            v4 = *(_DWORD*)(a1 + 508);
            v5 = 0;
            v6 = *(_DWORD*)(v4 + 516);
            if (!v6)
                goto LABEL_18;
            do
            {
                if (v6 == a1)
                    break;
                v5 = v6;
                v6 = *(_DWORD*)(v6 + 512);
            } while (v6);
            if (v5)
                * (_DWORD*)(v5 + 512) = *(_DWORD*)(a1 + 512);
            else
                LABEL_18:
                *(_DWORD*)(v4 + 516) = *(_DWORD*)(a1 + 512);
            v7 = *(_BYTE*)(a1 + 8);
            *(_DWORD*)(a1 + 508) = 0;
            if (v7 & 2)
                sub_5346F0(a1);
            if (*(_BYTE*)(a1 + 8) & 6)
                sub_4E8020(a1);
        }
    }
}

//----- (004EC3E0) --------------------------------------------------------
int __cdecl sub_4EC3E0(int a1)
{
    int result; // eax

    if (!a1)
        return 0;
    result = *(_DWORD*)(a1 + 516);
    if (!result)
        return 0;
    while (!(*(_BYTE*)(result + 8) & 2) || !(*(_BYTE*)(*(_DWORD*)(result + 748) + 1440) & 0x80))
    {
        result = *(_DWORD*)(result + 512);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004EC420) --------------------------------------------------------
int __cdecl sub_4EC420(int a1)
{
    int result; // eax

    if (!a1)
        return 0;
    if (!*(_DWORD*)(a1 + 508))
        return 0;
    result = *(_DWORD*)(a1 + 512);
    if (!result)
        return 0;
    while (!(*(_BYTE*)(result + 8) & 2) || !(*(_BYTE*)(*(_DWORD*)(result + 748) + 1440) & 0x80))
    {
        result = *(_DWORD*)(result + 512);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004EC470) --------------------------------------------------------
void __cdecl sub_4EC470(int a1)
{
    int v1; // eax
    int v2; // ecx

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 516);
        if (v1)
        {
            do
            {
                v2 = *(_DWORD*)(v1 + 512);
                *(_DWORD*)(v1 + 508) = 0;
                *(_DWORD*)(v1 + 512) = 0;
                v1 = v2;
            } while (v2);
        }
        *(_DWORD*)(a1 + 516) = 0;
    }
}

//----- (004EC4B0) --------------------------------------------------------
void __cdecl sub_4EC4B0(int a1)
{
    int v1; // eax
    int v2; // esi

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 516);
        if (v1)
        {
            do
            {
                v2 = *(_DWORD*)(v1 + 512);
                sub_4EC290(*(_DWORD*)(a1 + 508), v1);
                v1 = v2;
            } while (v2);
        }
    }
}

//----- (004EC4F0) --------------------------------------------------------
int __cdecl sub_4EC4F0(int a1, int a2)
{
    int v2; // eax

    v2 = a1;
    if (!a1 || !a2)
        return 0;
    while (v2 != a2)
    {
        v2 = *(_DWORD*)(v2 + 508);
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (004EC520) --------------------------------------------------------
int __cdecl sub_4EC520(int a1, int a2)
{
    int v2; // edi
    int v3; // esi

    v2 = a1;
    if (a1 && a2)
    {
        while (2)
        {
            v3 = a2;
            do
            {
                if (sub_419150(v2 + 48, v3 + 48) || v2 == v3)
                    return 1;
                v3 = *(_DWORD*)(v3 + 508);
            } while (v3);
            v2 = *(_DWORD*)(v2 + 508);
            if (v2)
                continue;
            break;
        }
    }
    return 0;
}

//----- (004EC580) --------------------------------------------------------
int __cdecl sub_4EC580(int a1)
{
    int result; // eax
    int i; // ecx

    result = a1;
    if (a1)
    {
        for (i = *(_DWORD*)(a1 + 508); i; i = *(_DWORD*)(i + 508))
        {
            if (*(_BYTE*)(result + 8) & 4)
                break;
            result = i;
        }
    }
    return result;
}

//----- (004EC5B0) --------------------------------------------------------
void sub_4EC5B0()
{
    *(_DWORD*)& byte_5D4594[1568024] = 0;
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1568020]);
    *(_DWORD*)& byte_587000[205200] = 1;
}

//----- (004EC5E0) --------------------------------------------------------
_DWORD* __cdecl sub_4EC5E0(int a1)
{
    _DWORD* result; // eax
    _DWORD* v2; // ebx
    unsigned __int16 v3; // cx
    _BYTE* v4; // ebp

    result = *(_DWORD * *)& byte_587000[205200];
    if (*(_DWORD*)& byte_587000[205200])
    {
        result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1568020]);
        v2 = result;
        if (result)
        {
            v3 = *(_WORD*)(a1 + 4);
            result[1] = a1;
            *result = v3;
            result[2] = *(_DWORD*)(a1 + 56);
            result[3] = *(_DWORD*)(a1 + 60);
            *((_WORD*)result + 8) = *(_WORD*)(a1 + 124);
            if (*(_DWORD*)(a1 + 8) & 0x13001000)
                qmemcpy(result + 7, *(const void**)(a1 + 692), 0x14u);
            if (*(_DWORD*)(a1 + 8) & 0x1000000 && sub_415820(a1) & 0x82)
            {
                v4 = *(_BYTE * *)(a1 + 736);
                *((_BYTE*)v2 + 48) = v4[1];
                *((_BYTE*)v2 + 49) = *v4;
            }
            v2[14] = 0;
            v2[13] = *(_DWORD*)& byte_5D4594[1568024];
            result = *(_DWORD * *)& byte_5D4594[1568024];
            if (*(_DWORD*)& byte_5D4594[1568024])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1568024] + 56) = v2;
            *(_DWORD*)& byte_5D4594[1568024] = v2;
        }
    }
    return result;
}

//----- (004EC6A0) --------------------------------------------------------
void __cdecl sub_4EC6A0(int a1)
{
    int v1; // eax
    _QWORD* v2; // ecx
    int v3; // eax
    int v4; // ecx
    int v5; // ecx

    v1 = *(_DWORD*)& byte_5D4594[1568024];
    if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1568024] + 4) == a1)
    {
        v2 = *(_QWORD * *)& byte_5D4594[1568024];
        *(_DWORD*)& byte_5D4594[1568024] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1568024] + 52);
        v3 = *(_DWORD*)(v1 + 52);
        if (v3)
            * (_DWORD*)(v3 + 56) = 0;
        sub_414330(*(unsigned int**)& byte_5D4594[1568020], v2);
    }
    else if (*(_DWORD*)& byte_5D4594[1568024])
    {
        while (*(_DWORD*)(v1 + 4) != a1)
        {
            v1 = *(_DWORD*)(v1 + 52);
            if (!v1)
                return;
        }
        v4 = *(_DWORD*)(v1 + 56);
        if (v4)
            * (_DWORD*)(v4 + 52) = *(_DWORD*)(v1 + 52);
        v5 = *(_DWORD*)(v1 + 52);
        if (v5)
            * (_DWORD*)(v5 + 56) = *(_DWORD*)(v1 + 56);
        sub_414330(*(unsigned int**)& byte_5D4594[1568020], (_QWORD*)v1);
    }
}

//----- (004EC720) --------------------------------------------------------
void sub_4EC720()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    int v3; // ecx
    int v4; // eax
    _DWORD* v5; // eax
    int v6; // edi
    __int16 v7; // ax
    _BYTE* v8; // eax
    int v9; // eax
    int v10; // eax
    double v11; // st7
    double v12; // st6
    int v13; // eax
    int v14; // ecx
    _BYTE* v15; // eax
    int v16; // eax
    int v17; // ecx
    int v18; // eax

    if (!*(_DWORD*)& byte_5D4594[1568028])
        * (_DWORD*)& byte_5D4594[1568028] = sub_4E3AA0((CHAR*)& byte_587000[205204]);
    if (!sub_40A5C0(4608))
    {
        v0 = *(_DWORD*)& byte_5D4594[1568024];
        *(_DWORD*)& byte_587000[205200] = 0;
        if (*(_DWORD*)& byte_5D4594[1568024])
        {
            while (1)
            {
                if (*(_DWORD*)(v0 + 24))
                {
                    LABEL_18:
                    if (*(_DWORD*)& byte_5D4594[2598000] >= *(int*)(v0 + 20) && sub_4E3BA0(*(_DWORD*)v0))
                    {
                        v5 = sub_4E3450(*(_DWORD*)v0);
                        v6 = (int)v5;
                        if (v5)
                        {
                            sub_4DAA50((int)v5, 0, *(float*)(v0 + 8), *(float*)(v0 + 12));
                            sub_522FF0(129, (float2*)(v0 + 8));
                            v7 = *(_WORD*)(v0 + 16);
                            *(_WORD*)(v6 + 124) = v7;
                            *(_WORD*)(v6 + 126) = v7;
                            if (*(_DWORD*)(v6 + 8) & 0x13001000)
                                sub_4E4990(v6, (int*)(v0 + 28));
                            if (*(_DWORD*)(v6 + 8) & 0x1000000 && sub_415820(v6) & 0x82)
                            {
                                v8 = *(_BYTE * *)(v6 + 736);
                                v8[1] = *(_BYTE*)(v0 + 48);
                                *v8 = *(_BYTE*)(v0 + 49);
                            }
                            sub_501960(283, v6, 0, 0);
                        }
                        v9 = *(_DWORD*)(v0 + 4);
                        if (v9)
                        {
                            if (*(_BYTE*)(v9 + 8) & 2)
                                sub_4E5CC0(*(_DWORD*)(v0 + 4));
                        }
                        *(_DWORD*)(v0 + 24) = 0;
                        *(_DWORD*)(v0 + 4) = v6;
                    }
                    goto LABEL_31;
                }
                v1 = *(_DWORD*)(v0 + 4);
                v2 = 0;
                if (!v1)
                    goto LABEL_16;
                v3 = *(_DWORD*)(v1 + 8);
                if (v3 & 2)
                    break;
                if (*(_BYTE*)(v1 + 16) & 0x20)
                {
                    if (sub_4E3BA0(*(unsigned __int16*)(v1 + 4)))
                        v2 = 1;
                    *(_DWORD*)(v0 + 4) = 0;
                    if (v2)
                        goto LABEL_16;
                }
                else if (v3 & 0x3001000 || *(unsigned __int16*)(v1 + 4) == *(_DWORD*)& byte_5D4594[1568028])
                {
                    if (*(_DWORD*)(v1 + 492) || !sub_4E3BA0(*(unsigned __int16*)(v1 + 4)))
                    {
                        v18 = *(_DWORD*)(v0 + 4);
                        if (*(_DWORD*)(v18 + 492)
                            && sub_4E3BA0(*(unsigned __int16*)(v18 + 4))
                            && *(unsigned __int16*)(*(_DWORD*)(v0 + 4) + 4) != *(_DWORD*)& byte_5D4594[1568028]
                            && sub_409F40(2))
                        {
                            goto LABEL_16;
                        }
                    }
                    else
                    {
                        v10 = *(_DWORD*)(v0 + 4);
                        if (*(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(5 * *(_DWORD*)& byte_5D4594[2649704]
                                                                              + *(_DWORD*)(v10 + 128)))
                        {
                            v11 = *(float*)(v0 + 8) - *(float*)(v10 + 56);
                            v12 = *(float*)(v0 + 12) - *(float*)(v10 + 60);
                            if (v12 * v12 + v11 * v11 > 2500.0)
                            {
                                sub_522FF0(129, (float2*)(v10 + 56));
                                sub_501A30(283, (float2*)(*(_DWORD*)(v0 + 4) + 56), 0, 0);
                                sub_4E7010(*(_DWORD*)(v0 + 4), (float2*)(v0 + 8));
                                v13 = *(_DWORD*)(v0 + 4);
                                v14 = *(_DWORD*)(v13 + 8);
                                if (v14 & 0x1000)
                                {
                                    sub_53C520(v13, 100);
                                }
                                else if (v14 & 0x1000000 && sub_415820(*(_DWORD*)(v0 + 4)) & 0x82)
                                {
                                    v15 = *(_BYTE * *)(*(_DWORD*)(v0 + 4) + 736);
                                    v15[1] = *(_BYTE*)(v0 + 48);
                                    *v15 = *(_BYTE*)(v0 + 49);
                                }
                                v16 = *(_DWORD*)(v0 + 4);
                                v17 = *(_DWORD*)(v16 + 556);
                                if (v17)
                                    sub_4E4560(v16, *(_WORD*)(v17 + 4));
                                sub_522FF0(129, (float2*)(v0 + 8));
                                sub_501A30(283, (float2*)(v0 + 8), 0, 0);
                            }
                        }
                    }
                }
                else if (*(_DWORD*)(v1 + 492))
                {
                    goto LABEL_16;
                }
                LABEL_17:
                if (*(_DWORD*)(v0 + 24))
                    goto LABEL_18;
                LABEL_31:
                v0 = *(_DWORD*)(v0 + 52);
                if (!v0)
                    return;
            }
            v4 = *(_DWORD*)(v1 + 16);
            if (v4 & 0x20)
            {
                *(_DWORD*)(v0 + 4) = 0;
            }
            else if ((v4 & 0x8000) == 0)
            {
                goto LABEL_17;
            }
            LABEL_16:
            *(_DWORD*)(v0 + 24) = 1;
            *(_DWORD*)(v0 + 20) = *(_DWORD*)& byte_5D4594[2598000] + 30 * *(_DWORD*)& byte_5D4594[2649704];
            goto LABEL_17;
        }
    }
}

//----- (004ECA60) --------------------------------------------------------
BOOL sub_4ECA60()
{
    *(_DWORD*)& byte_5D4594[1568020] = nox_new_alloc_class("Respawn", 60, 384);
    return *(_DWORD*)& byte_5D4594[1568020] != 0;
}

//----- (004ECA90) --------------------------------------------------------
void sub_4ECA90()
{
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1568020]);
}

//----- (004ECAA0) --------------------------------------------------------
char* __cdecl sub_4ECAA0(char a1)
{
    char* result; // eax

    if (a1 <= 16)
        result = *(char**)& byte_587000[4 * a1 + 205304];
    else
        result = *(char**)& byte_587000[205304];
    return result;
}

//----- (004ECAC0) --------------------------------------------------------
unsigned __int8 __cdecl sub_4ECAC0(const char* a1)
{
    unsigned __int8 result; // al
    unsigned __int8 v2; // [esp+Ch] [ebp-4h]

    result = 0;
    v2 = 0;
    while (strcmp(a1, *(const char**)& byte_587000[4 * v2 + 205304]))
    {
        v2 = ++result;
        if (result > 0x10u)
            return 0;
    }
    return result;
}

//----- (004ECB20) --------------------------------------------------------
char* __cdecl sub_4ECB20(char* a1)
{
    int v2; // ecx
    unsigned __int8* i; // eax
    int v4; // esi

    if (!a1)
        return (char*)& byte_587000[205676];
    v2 = 0;
    if (!*(_DWORD*)& byte_587000[205224])
        return 0;
    for (i = &byte_587000[205224]; *((char**)i + 1) != a1; i += 8)
    {
        v4 = *((_DWORD*)i + 2);
        ++v2;
        if (!v4)
            return 0;
    }
    return *(char**)& byte_587000[8 * v2 + 205224];
}

//----- (004ECB60) --------------------------------------------------------
int __cdecl sub_4ECB60(const char* a1)
{
    const char* v1; // eax
    int v2; // ebp
    unsigned __int8* v3; // edi

    v1 = *(const char**)& byte_587000[205224];
    v2 = 0;
    if (!*(_DWORD*)& byte_587000[205224])
        return 0;
    v3 = &byte_587000[205224];
    while (strcmp(v1, a1))
    {
        v1 = (const char*) * ((_DWORD*)v3 + 2);
        v3 += 8;
        ++v2;
        if (!v1)
            return 0;
    }
    return *(_DWORD*)& byte_587000[8 * v2 + 205228];
}

//----- (004ECBD0) --------------------------------------------------------
int __cdecl sub_4ECBD0(int a1)
{
    int result; // eax

    if (*(_DWORD*)(a1 + 8) & 0x10000000)
        result = sub_4ECC00(*(const char***)(*(_DWORD*)(a1 + 692) + 4));
    else
        result = 0;
    return result;
}

//----- (004ECC00) --------------------------------------------------------
int __cdecl sub_4ECC00(const char** a1)
{
    const char* v1; // esi
    int v2; // edx
    unsigned __int8* v3; // edi

    if (!a1)
        return 0;
    v1 = *(const char**)& byte_587000[205224];
    v2 = 0;
    if (!*(_DWORD*)& byte_587000[205224])
        return 0;
    v3 = &byte_587000[205224];
    while (strcmp(*a1, v1))
    {
        v1 = (const char*) * ((_DWORD*)v3 + 2);
        v3 += 8;
        ++v2;
        if (!v1)
            return 0;
    }
    return *(_DWORD*)& byte_587000[8 * v2 + 205228];
}

//----- (004ECC70) --------------------------------------------------------
int __cdecl sub_4ECC70(int a1)
{
    int v1; // eax
    int result; // eax

    v1 = *(_DWORD*)& byte_5D4594[1568032];
    if (!*(_DWORD*)& byte_5D4594[1568032])
    {
        v1 = sub_4E3AA0((CHAR*)& byte_587000[205684]);
        *(_DWORD*)& byte_5D4594[1568032] = v1;
    }
    if (*(unsigned __int16*)(a1 + 4) == v1)
        result = sub_4ECC00(*(const char***)(*(_DWORD*)(a1 + 692) + 4));
    else
        result = 0;
    return result;
}

//----- (004ECCB0) --------------------------------------------------------
int __cdecl sub_4ECCB0(int a1)
{
    int result; // eax
    int v2; // edi
    int v3; // esi
    char* v4; // eax
    int v5; // ecx

    result = sub_4ECD90(a1);
    if (!result)
    {
        v2 = sub_4DA790();
        if (v2)
        {
            while (1)
            {
                if (!(*(_BYTE*)(v2 + 16) & 0x20) && *(_DWORD*)(v2 + 36) == a1)
                {
                    sub_4ECEA0(v2);
                    return v2;
                }
                v3 = *(_DWORD*)(v2 + 504);
                if (v3)
                    break;
                LABEL_9:
                v2 = sub_4DA7A0(v2);
                if (!v2)
                    goto LABEL_10;
            }
            while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 36) != a1)
            {
                v3 = *(_DWORD*)(v3 + 496);
                if (!v3)
                    goto LABEL_9;
            }
            goto LABEL_16;
        }
        LABEL_10:
        v3 = sub_4DA870();
        if (v3)
        {
            while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 36) != a1)
            {
                v3 = sub_4DA880(v3);
                if (!v3)
                    goto LABEL_17;
            }
            LABEL_16:
            sub_4ECEA0(v3);
            return v3;
        }
        LABEL_17:
        v4 = sub_416EA0();
        if (v4)
        {
            while (1)
            {
                v5 = *((_DWORD*)v4 + 514);
                if (v5)
                {
                    if (!(*(_BYTE*)(v5 + 16) & 0x20) && *(_DWORD*)(v5 + 36) == a1)
                        break;
                }
                v4 = sub_416EE0((int)v4);
                if (!v4)
                    goto LABEL_22;
            }
            result = *((_DWORD*)v4 + 514);
        }
        else
        {
            LABEL_22:
            result = 0;
        }
    }
    return result;
}

//----- (004ECD90) --------------------------------------------------------
int __cdecl sub_4ECD90(int a1)
{
    _DWORD* v1; // esi

    if (*(_DWORD*)& byte_587000[205696])
        sub_4ECE50();
    v1 = *(_DWORD * *)& byte_5D4594[1568236];
    if (!*(_DWORD*)& byte_5D4594[1568236])
        return 0;
    while (*(_DWORD*)(*v1 + 36) != a1)
    {
        v1 = (_DWORD*)v1[2];
        if (!v1)
            return 0;
    }
    sub_4ECE10(&byte_5D4594[1568236], (int)v1);
    sub_4ECDE0(&byte_5D4594[1568236], (int)v1);
    return *v1;
}

//----- (004ECDE0) --------------------------------------------------------
int __cdecl sub_4ECDE0(_DWORD* a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a2 + 4) = 0;
    *(_DWORD*)(a2 + 8) = *a1;
    if (*a1)
        * (_DWORD*)(*a1 + 4) = a2;
    else
        a1[1] = a2;
    *a1 = a2;
    return result;
}

//----- (004ECE10) --------------------------------------------------------
int __cdecl sub_4ECE10(_DWORD* a1, int a2)
{
    int result; // eax
    int v3; // ecx
    int v4; // ecx

    result = a2;
    v3 = *(_DWORD*)(a2 + 8);
    if (v3)
        * (_DWORD*)(v3 + 4) = *(_DWORD*)(a2 + 4);
    else
        a1[1] = *(_DWORD*)(a2 + 4);
    v4 = *(_DWORD*)(a2 + 4);
    if (v4)
    {
        *(_DWORD*)(v4 + 8) = *(_DWORD*)(a2 + 8);
    }
    else
    {
        result = *(_DWORD*)(a2 + 8);
        *a1 = result;
    }
    return result;
}

//----- (004ECE50) --------------------------------------------------------
int sub_4ECE50()
{
    unsigned __int8* v0; // esi
    int result; // eax

    v0 = &byte_5D4594[1568044];
    *(_DWORD*)& byte_5D4594[1568236] = 0;
    *(_DWORD*)& byte_5D4594[1568240] = 0;
    *(_DWORD*)& byte_5D4594[1568036] = 0;
    *(_DWORD*)& byte_5D4594[1568040] = 0;
    do
    {
        result = sub_4ECDE0(&byte_5D4594[1568036], (int)v0);
        v0 += 12;
    } while ((int)v0 < (int)& byte_5D4594[1568236]);
    *(_DWORD*)& byte_587000[205696] = 0;
    return result;
}

//----- (004ECEA0) --------------------------------------------------------
int __cdecl sub_4ECEA0(int a1)
{
    int* v1; // eax
    int v2; // esi
    int result; // eax
    int v4; // [esp-8h] [ebp-8h]

    v1 = (int*)sub_4ECEF0();
    if (v1)
    {
        *v1 = a1;
        result = sub_4ECDE0(&byte_5D4594[1568236], (int)v1);
    }
    else
    {
        v2 = *(_DWORD*)& byte_5D4594[1568240];
        v4 = *(_DWORD*)& byte_5D4594[1568240];
        **(_DWORD * *)& byte_5D4594[1568240] = a1;
        sub_4ECE10(&byte_5D4594[1568236], v4);
        result = sub_4ECDE0(&byte_5D4594[1568236], v2);
    }
    return result;
}

//----- (004ECEF0) --------------------------------------------------------
int sub_4ECEF0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1568036];
    if (!*(_DWORD*)& byte_5D4594[1568036])
        return 0;
    *(_DWORD*)& byte_5D4594[1568036] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1568036] + 8);
    return result;
}

//----- (004ECF10) --------------------------------------------------------
int __cdecl sub_4ECF10(int a1)
{
    int result; // eax
    int v2; // ecx

    result = sub_4DA790();
    if (result)
    {
        while (*(_BYTE*)(result + 16) & 0x20 || *(_DWORD*)(result + 44) != a1)
        {
            v2 = *(_DWORD*)(result + 504);
            if (v2)
            {
                while (*(_BYTE*)(v2 + 16) & 0x20 || *(_DWORD*)(v2 + 44) != a1)
                {
                    v2 = *(_DWORD*)(v2 + 496);
                    if (!v2)
                        goto LABEL_8;
                }
                return v2;
            }
            LABEL_8:
            result = sub_4DA7A0(result);
            if (!result)
                goto LABEL_9;
        }
    }
    else
    {
        LABEL_9:
        result = sub_4DA870();
        if (result)
        {
            while (*(_BYTE*)(result + 16) & 0x20 || *(_DWORD*)(result + 44) != a1)
            {
                result = sub_4DA880(result);
                if (!result)
                    goto LABEL_13;
            }
        }
        else
        {
            LABEL_13:
            result = sub_4DA840();
            if (result)
            {
                while (*(_BYTE*)(result + 16) & 0x20 || *(_DWORD*)(result + 44) != a1)
                {
                    result = sub_4DA850(result);
                    if (!result)
                        goto LABEL_17;
                }
            }
            else
            {
                LABEL_17:
                result = 0;
            }
        }
    }
    return result;
}

//----- (004ECFA0) --------------------------------------------------------
int __cdecl sub_4ECFA0(int a1)
{
    int result; // eax
    _DWORD* v2; // esi

    result = *(_DWORD*)& byte_587000[205696];
    if (!*(_DWORD*)& byte_587000[205696])
    {
        v2 = *(_DWORD * *)& byte_5D4594[1568236];
        if (*(_DWORD*)& byte_5D4594[1568236])
        {
            result = a1;
            while (*v2 != a1)
            {
                v2 = (_DWORD*)v2[2];
                if (!v2)
                    return result;
            }
            sub_4ECE10(&byte_5D4594[1568236], (int)v2);
            result = sub_4ECDE0(&byte_5D4594[1568036], (int)v2);
        }
    }
    return result;
}

//----- (004ECFE0) --------------------------------------------------------
int sub_4ECFE0()
{
    int result; // eax
    int v1; // esi
    int v2; // edi

    result = *(_DWORD*)& byte_587000[205696];
    if (!*(_DWORD*)& byte_587000[205696])
    {
        v1 = *(_DWORD*)& byte_5D4594[1568236];
        if (*(_DWORD*)& byte_5D4594[1568236])
        {
            do
            {
                v2 = *(_DWORD*)(v1 + 8);
                sub_4ECE10(&byte_5D4594[1568236], v1);
                result = sub_4ECDE0(&byte_5D4594[1568036], v1);
                v1 = v2;
            } while (v2);
        }
    }
    return result;
}

//----- (004ED020) --------------------------------------------------------
int __cdecl sub_4ED020(int a1)
{
    int result; // eax

    result = sub_4DA790();
    if (!result)
        return 0;
    while (*(_BYTE*)(result + 16) & 0x20 || *(_DWORD*)(result + 40) != a1)
    {
        result = sub_4DA7A0(result);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004ED050) --------------------------------------------------------
void __cdecl sub_4ED050(int a1, int a2)
{
    int v2; // eax
    int i; // esi
    int v4; // edi

    LOWORD(v2) = *(_WORD*)& byte_5D4594[1568248];
    if (!*(_DWORD*)& byte_5D4594[1568248])
    {
        v2 = sub_4E3AA0((CHAR*)& byte_587000[205744]);
        *(_DWORD*)& byte_5D4594[1568248] = v2;
    }
    for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512))
    {
        LOWORD(v2) = *(_WORD*)(i + 4);
        if ((unsigned __int16)v2 == *(_DWORD*)& byte_5D4594[1568248])
        {
            v4 = *(_DWORD*)(i + 748);
            LOWORD(v2) = sub_4ED5E0(a1, i, (int*)(a1 + 56));
            *(_DWORD*)(v4 + 4) = a2;
        }
    }
}

//----- (004ED0C0) --------------------------------------------------------
void __cdecl sub_4ED0C0(int a1, int* a2)
{
    int v2; // ebx
    int v3; // eax
    int v4; // ebp
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // esi
    int i; // ecx
    int v10; // edx

    v2 = 1;
    if (a1 && a2)
    {
        v3 = *(_DWORD*)(a1 + 8);
        if (v3 & 4)
        {
            v4 = *(_DWORD*)(a1 + 748);
            if (!sub_40A5C0(4096) && (*(_DWORD*)(a1 + 16) & 0x8000) == 0x8000 && a2[2] & 0x13001000)
                v2 = 0;
            if (a2[2] & 0x10000000)
            {
                if (sub_40A5C0(32))
                {
                    *(_DWORD*)(*(_DWORD*)(v4 + 276) + 4) &= 0xFFFFFFFE;
                    if (v2 == 1)
                        sub_4D84C0(255, (int)a2);
                }
            }
            sub_53E430((_DWORD*)a1, (int)a2, 0, v2);
            sub_53A140((_DWORD*)a1, (int)a2, 0, v2);
            sub_4D8B50(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)a2);
            sub_56FC50(*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4632), a2);
        }
        else if (v3 & 2)
        {
            if (*(_BYTE*)(a1 + 12) & 0x10 && a2[2] & 0x10000000 && sub_40A5C0(32))
                sub_4E4B20(a1, (int)a2, 0);
            sub_53E430((_DWORD*)a1, (int)a2, 1, 1);
            sub_53A140((_DWORD*)a1, (int)a2, 1, 1);
        }
        v5 = a2[125];
        if (v5)
            * (_DWORD*)(v5 + 496) = a2[124];
        else
            *(_DWORD*)(a1 + 504) = a2[124];
        v6 = a2[124];
        if (v6)
            * (_DWORD*)(v6 + 500) = a2[125];
        a2[123] = 0;
        sub_4EC300((int)a2);
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v7 = *(_DWORD*)(a1 + 504);
            v8 = *(_DWORD*)(a1 + 748);
            for (i = 0; v7; i += v10)
            {
                v10 = *(unsigned __int8*)(v7 + 488);
                v7 = *(_DWORD*)(v7 + 496);
            }
            *(_DWORD*)(*(_DWORD*)(v8 + 276) + 3656) = i > * (unsigned __int16*)(a1 + 490);
        }
    }
}

//----- (004ED290) --------------------------------------------------------
int __cdecl sub_4ED290(int a1, int a2, float2* a3)
{
    int v3; // ebp
    int result; // eax
    int* v5; // edi
    int v6; // eax
    int v7; // ebx
    int v8; // eax
    char v9; // di
    int v10; // eax
    int v11; // ecx
    int v12; // eax
    char v13[10]; // [esp+8h] [ebp-Ch]
    unsigned __int8 v14; // [esp+18h] [ebp+4h]

    v3 = a1;
    if (*(_DWORD*)(a2 + 492) != a1)
        return 0;
    if (*(_BYTE*)(a1 + 8) & 4 && sub_53EBF0(a2) && sub_53EC80(a2, 1))
    {
        if (!(*(_DWORD*)(a1 + 16) & 0x8020))
        {
            sub_4DA2C0(a1, "drop.c:CantDropThat", 0);
            sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
        }
        result = 0;
    }
    else
    {
        sub_4ED0C0(a1, (int*)a2);
        sub_4DAA50(a2, 0, a3->field_0, a3->field_4);
        if (*(_DWORD*)(a2 + 8) & 0x1000000)
        {
            if (sub_415820(a2) == 4)
            {
                v5 = *(int**)(a1 + 504);
                if (v5)
                {
                    while (1)
                    {
                        if (v5[2] & 0x1000000)
                        {
                            if (sub_415820((int)v5) == 2)
                            {
                                v6 = v5[4];
                                if (!(v6 & 0x100))
                                {
                                    if (*(_BYTE*)(v5[184] + 2))
                                        break;
                                }
                            }
                        }
                        v5 = (int*)v5[124];
                        if (!v5)
                            goto LABEL_19;
                    }
                    sub_4ED0C0(a1, v5);
                    sub_4E5CC0((int)v5);
                }
            }
        }
        LABEL_19:
        if (*(_DWORD*)(a2 + 8) & 0x10000000)
        {
            v7 = *(_DWORD*)(a2 + 748);
            v8 = sub_4ECBD0(a2);
            v9 = v8;
            v14 = *(_BYTE*)(a2 + 52);
            *(_DWORD*)& v13[2] = *(_DWORD*)(v3 + 36);
            *(_DWORD*)& v13[6] = v8;
            sub_4DA180(7, v13);
            sub_4174B0(a2, 1);
            *(_DWORD*)(v7 + 8) = *(_DWORD*)& byte_5D4594[2598000];
            sub_4E82C0(v14, 2, v9, 0);
        }
        if (!*(_DWORD*)& byte_5D4594[1568252])
            * (_DWORD*)& byte_5D4594[1568252] = sub_4E3AA0((CHAR*)& byte_587000[205772]);
        if (!sub_40A5C0(2048)
            && !sub_40A5C0(4096)
            && !(*(_DWORD*)(a2 + 16) & 0x80000)
            && !(*(_DWORD*)(a2 + 8) & 0x10000000)
            && *(unsigned __int16*)(a2 + 4) != *(_DWORD*)& byte_5D4594[1568252])
        {
            sub_511660((_DWORD*)a2, 10 * *(_DWORD*)& byte_5D4594[2649704]);
        }
        sub_4E46F0(a2, 0.0);
        if (*(_BYTE*)(a2 + 8) & 0x40)
            sub_501960(821, a2, 0, 0);
        if (*(_BYTE*)(a2 + 8) & 2)
        {
            v10 = *(_DWORD*)(a2 + 748);
            v11 = *(_DWORD*)(v10 + 1440);
            *(_DWORD*)(v10 + 1360) = 15;
            BYTE1(v11) |= 1u;
            *(_DWORD*)(v10 + 1440) = v11;
        }
        if (!*(_DWORD*)& byte_5D4594[1568256])
        {
            *(_DWORD*)& byte_5D4594[1568256] = sub_4E3AA0((CHAR*)& byte_587000[205780]);
            *(_DWORD*)& byte_5D4594[1568244] = sub_4E3AA0((CHAR*)& byte_587000[205788]);
        }
        v12 = *(unsigned __int16*)(a2 + 4);
        if ((unsigned __int16)v12 == *(_DWORD*)& byte_5D4594[1568256] || v12 == *(_DWORD*)& byte_5D4594[1568244])
            sub_4FF5B0(v3, 15);
        result = 1;
    }
    return result;
}

//----- (004ED500) --------------------------------------------------------
int __cdecl sub_4ED500(int a1, int a2, float2* a3)
{
    __int16 v3; // ax
    float2 v5; // [esp+Ch] [ebp-8h]

    if (!sub_4ED580(a1, a2, a3))
        return 0;
    *(float2*)(*(_DWORD*)(a2 + 692) + 28) = *a3;
    v5.field_0 = *(float*)(a1 + 56) - a3->field_0;
    v5.field_4 = *(float*)(a1 + 60) - a3->field_4;
    v3 = sub_509ED0(&v5);
    *(_WORD*)(a2 + 126) = v3;
    *(_WORD*)(a2 + 124) = v3;
    sub_501960(825, a2, 0, 0);
    return 1;
}

//----- (004ED580) --------------------------------------------------------
int __cdecl sub_4ED580(int a1, int a2, float2* a3)
{
    if (sub_411A90(a3))
    {
        sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
        return 0;
    }
    if (!sub_4ED290(a1, a2, a3))
        return 0;
    sub_4EC290(a1, a2);
    return 1;
}

//----- (004ED5E0) --------------------------------------------------------
int __cdecl sub_4ED5E0(int a1, int a2, int* a3)
{
    int v3; // edi
    int v4; // ebx
    int v5; // ebp
    int v6; // esi
    int v7; // edi
    int v8; // esi
    int v10; // [esp+10h] [ebp-10h]
    char v11[10]; // [esp+14h] [ebp-Ch]

    if (!sub_40A5C0(16) || !sub_417DA0(4))
    {
        v3 = a2;
        goto LABEL_14;
    }
    v3 = a2;
    v4 = *(_DWORD*)& byte_5D4594[2598000];
    if (!*(_BYTE*)(a2 + 52))
    {
        LABEL_14:
        v8 = a1;
        goto LABEL_15;
    }
    v10 = *(_DWORD*)(a2 + 748);
    v5 = a2;
    v6 = sub_4DA7C0();
    if (v6)
    {
        do
        {
            v7 = *(_DWORD*)(v6 + 748);
            if (sub_419180(v6 + 48, *(_BYTE*)(a2 + 52)) && *(_DWORD*)(v7 + 264) < v4)
            {
                v4 = *(_DWORD*)(v7 + 264);
                v5 = v6;
            }
            v6 = sub_4DA7F0(v6);
        } while (v6);
        v3 = a2;
    }
    v8 = a1;
    if (v5 && a1 != v5)
        * (_DWORD*)(v10 + 4) = v5;
    LABEL_15:
    if (!sub_4ED290(v8, v3, (float2*)a3))
        return 0;
    sub_4EC300(v3);
    sub_4FF5B0(v8, 30);
    *(_DWORD*)& v11[2] = *(_DWORD*)(v8 + 36);
    if (sub_419130(v8 + 48))
        * (_DWORD*)& v11[6] = *(unsigned __int8*)(v8 + 52);
    else
        *(_DWORD*)& v11[6] = 0;
    sub_4DA180(11, v11);
    sub_4174B0(v3, 1);
    return 1;
}

//----- (004ED710) --------------------------------------------------------
int __cdecl sub_4ED710(int a1, int a2, int* a3)
{
    int v3; // edi

    if (!sub_4ED290(a1, a2, (float2*)a3))
        return 0;
    if (*(_BYTE*)(a1 + 8) & 4)
    {
        if (sub_40A5C0(64))
        {
            v3 = *(_DWORD*)(a1 + 748);
            --* (_DWORD*)(*(_DWORD*)(v3 + 276) + 2152);
            *(_DWORD*)(*(_DWORD*)(v3 + 276) + 2156) = sub_4D1600();
            sub_4D8CD0(a1);
            sub_501960(308, a1, 0, 0);
        }
    }
    return 1;
}

//----- (004ED790) --------------------------------------------------------
int __cdecl sub_4ED790(int a1, _DWORD* a2, float2* a3)
{
    int result; // eax
    int(__cdecl * v4)(int, _DWORD*, float2*); // eax

    if (!a2)
        return 0;
    if (sub_40A5C0(0x2000) && !sub_40A5C0(4096) && a2[2] & 0x3001010)
    {
        a2[4] |= 0x40u;
        sub_511810((int)a2);
    }
    v4 = (int(__cdecl*)(int, _DWORD*, float2*))a2[178];
    if (v4)
        result = v4(a1, a2, a3);
    else
        result = sub_4ED290(a1, (int)a2, a3);
    return result;
}

//----- (004ED810) --------------------------------------------------------
int __cdecl sub_4ED810(int a1, int a2, float* a3)
{
    int v3; // esi
    float v4; // ecx
    float v5; // eax
    double v6; // st7
    double v7; // st6
    long double v8; // st6
    int result; // eax
    int v10; // eax
    float4 v11; // [esp+8h] [ebp-10h]
    float v12; // [esp+1Ch] [ebp+4h]
    float v13; // [esp+24h] [ebp+Ch]

    v3 = a1;
    v4 = *(float*)(a1 + 60);
    v11.field_0 = *(float*)(a1 + 56);
    v11.field_4 = v4;
    v5 = a3[1];
    v11.field_8 = *a3;
    v11.field_C = v5;
    v6 = v11.field_8 - v11.field_0;
    v7 = v5 - v4;
    v12 = v7;
    v8 = sqrt(v7 * v12 + v6 * v6);
    v13 = v8;
    if (v8 > 75.0)
    {
        v11.field_8 = v6 * 75.0 / v13 + v11.field_0;
        v11.field_C = v12 * 75.0 / v13 + v11.field_4;
    }
    if (sub_535250(&v11, 0, 0, 0))
    {
        if (!sub_40A5C0(16))
            goto LABEL_13;
        v10 = *(_DWORD*)& byte_5D4594[1568248];
        if (!*(_DWORD*)& byte_5D4594[1568248])
        {
            v10 = sub_4E3AA0((CHAR*)& byte_587000[205820]);
            *(_DWORD*)& byte_5D4594[1568248] = v10;
        }
        if (*(unsigned __int16*)(a2 + 4) == v10)
            result = 0;
        else
            LABEL_13:
            result = sub_4ED790(v3, (_DWORD*)a2, (float2*)& v11.field_8);
    }
    else
    {
        sub_4DA2C0(v3, "drop.c:DropNotAllowed", 0);
        sub_501960(925, v3, 2, *(_DWORD*)(v3 + 36));
        result = 0;
    }
    return result;
}

//----- (004ED930) --------------------------------------------------------
int __cdecl sub_4ED930(int a1, _DWORD* a2)
{
    float2 v3; // [esp+4h] [ebp-8h]

    sub_4ED970(50.0, (float2*)(a1 + 56), &v3);
    return sub_4ED790(a1, a2, &v3);
}

//----- (004ED970) --------------------------------------------------------
float2* __cdecl sub_4ED970(float a1, float2* a2, float2* a3)
{
    float2* v3; // esi
    float v4; // ecx
    int v5; // edi
    double v6; // st7
    float2* result; // eax
    float v8; // edx
    float v9; // [esp+0h] [ebp-14h]
    float4 v10; // [esp+4h] [ebp-10h]
    float v11; // [esp+1Ch] [ebp+8h]

    v3 = a2;
    v4 = a2->field_4;
    v9 = a1 * 0.015625;
    v10.field_0 = a2->field_0;
    v10.field_4 = v4;
    v11 = sub_416030(-3.1415927, 3.1415927);
    v5 = 0;
    while (1)
    {
        v6 = v11 + 1.8849558;
        v11 = v6;
        v10.field_8 = cos(v6) * a1 + v3->field_0;
        v10.field_C = sin(v11) * a1 + v3->field_4;
        if (sub_535250(&v10, 0, 0, 1))
            break;
        ++v5;
        a1 = a1 - v9;
        if (v5 >= 64)
        {
            result = a3;
            *a3 = *v3;
            return result;
        }
    }
    result = a3;
    v8 = v10.field_C;
    a3->field_0 = v10.field_8;
    a3->field_4 = v8;
    return result;
}

//----- (004EDA40) --------------------------------------------------------
_DWORD* __cdecl sub_4EDA40(_DWORD* a1)
{
    float2* v1; // ebp
    int v2; // edi
    int v3; // esi
    _DWORD* result; // eax
    float v5; // edx
    int v6; // esi
    int v7; // ebx
    int v8; // ecx
    int v9; // edx
    _DWORD* v10; // esi
    _DWORD* v11; // edi
    float v12; // [esp+10h] [ebp-34h]
    float v13; // [esp+10h] [ebp-34h]
    int v14; // [esp+14h] [ebp-30h]
    int v15; // [esp+18h] [ebp-2Ch]
    int v16; // [esp+1Ch] [ebp-28h]
    int v17; // [esp+20h] [ebp-24h]
    _DWORD* v18; // [esp+24h] [ebp-20h]
    _DWORD* v19; // [esp+28h] [ebp-1Ch]
    int v20; // [esp+2Ch] [ebp-18h]
    int v21; // [esp+30h] [ebp-14h]
    float4 v22; // [esp+34h] [ebp-10h]
    _DWORD* v23; // [esp+48h] [ebp+4h]

    v1 = (float2*)a1;
    v2 = 0;
    v3 = a1[126];
    v12 = 0.0;
    if (v3)
    {
        do
        {
            if (sub_4EDCD0((int)a1, v3) && *(float*)(v3 + 176) > (double)v12)
                v12 = *(float*)(v3 + 176);
            v3 = *(_DWORD*)(v3 + 496);
        } while (v3);
        v2 = 0;
    }
    result = (_DWORD*)a1[126];
    v5 = *((float*)a1 + 15);
    v6 = -1;
    v15 = 0;
    v7 = 3;
    v20 = 0;
    v21 = -1;
    v14 = 0;
    v16 = 0;
    v22.field_0 = *((float*)a1 + 14);
    v22.field_4 = v5;
    v23 = result;
    v13 = v12 + v12 + 6.0;
    if (!result)
        return result;
    while (2)
    {
        v19 = (_DWORD*)result[124];
        if (!sub_4EDCD0((int)v1, (int)result))
            goto LABEL_31;
        v17 = 0;
        v18 = (_DWORD*)(v7 - 1);
        while (1)
        {
            v22.field_8 = (double)v20 * v13 + v1[7].field_0;
            v22.field_C = v1[7].field_4 - (double)v21 * v13;
            v22.field_8 = sub_416030(-3.0, 3.0) + v22.field_8;
            v22.field_C = sub_416030(-3.0, 3.0) + v22.field_C;
            if (sub_535250(&v22, 0, 0, 1))
            {
                sub_4ED790((int)v1, v23, (float2*)& v22.field_8);
                v8 = 1;
                v16 = 1;
                v17 = 1;
            }
            else
            {
                v8 = v17;
            }
            result = v18;
            if ((_DWORD*)v14 != v18)
            {
                v9 = v15;
                ++v14;
                LABEL_22:
                switch (v9)
                {
                    case 0:
                        v20 = ++v2;
                        break;
                    case 1:
                        ++v6;
                        goto LABEL_27;
                    case 2:
                        v20 = --v2;
                        break;
                    case 3:
                        --v6;
                    LABEL_27:
                        v21 = v6;
                        break;
                    default:
                        goto LABEL_28;
                }
                goto LABEL_28;
            }
            if (v15 != 3 && v18)
            {
                v9 = v15 + 1;
                v14 = 1;
                ++v15;
                goto LABEL_22;
            }
            if (!v16)
                break;
            v7 += 2;
            v18 = (_DWORD*)((char*)v18 + 2);
            v2 = 1 - v7 / 2;
            v20 = 1 - v7 / 2;
            v14 = 1;
            v6 = v7 / -2;
            v21 = v7 / -2;
            v15 = 0;
            v16 = 0;
            LABEL_28:
            if (v8)
                goto LABEL_31;
        }
        if (v8)
        {
            LABEL_31:
            result = v19;
            v23 = v19;
            if (v19)
            {
                result = v19;
                continue;
            }
        }
        else
        {
            v10 = v23;
            if (v23)
            {
                while (1)
                {
                    v11 = (_DWORD*)v10[124];
                    result = (_DWORD*)sub_4EDCD0((int)v1, (int)v10);
                    if (result)
                        result = (_DWORD*)sub_4ED790((int)v1, v10, v1 + 7);
                    if (!v11)
                        break;
                    v10 = v11;
                }
            }
        }
        return result;
    }
}

//----- (004EDCD0) --------------------------------------------------------
BOOL __cdecl sub_4EDCD0(int a1, int a2)
{
    int v2; // eax

    v2 = *(_DWORD*)(a2 + 16);
    return v2 & 0x20 || !(*(_BYTE*)(a1 + 8) & 6) || !(v2 & 0x10000000);
}

//----- (004EDD00) --------------------------------------------------------
char __cdecl sub_4EDD00(int a1, int a2)
{
    int v2; // eax
    int* v3; // esi
    int v4; // edi
    float2 a3; // [esp+8h] [ebp-8h]

    v2 = sub_4E7980(a1);
    v3 = (int*)v2;
    if (v2)
    {
        do
        {
            v4 = sub_4E7990((int)v3);
            v2 = v3[2];
            if (v2 & a2)
            {
                sub_4ED0C0(a1, v3);
                sub_4ED970(60.0, (float2*)(a1 + 56), &a3);
                LOBYTE(v2) = sub_4DAA50((int)v3, 0, a3.field_0, a3.field_4);
            }
            v3 = (int*)v4;
        } while (v4);
    }
    return v2;
}

//----- (004EDD70) --------------------------------------------------------
int sub_4EDD70()
{
    int result; // eax
    int i; // edi
    _DWORD* v2; // esi
    _DWORD* v3; // ebx
    float2 a3; // [esp+4h] [ebp-8h]

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        v2 = *(_DWORD * *)(i + 504);
        if (v2)
        {
            do
            {
                v3 = (_DWORD*)v2[124];
                if (v2[2] & 0x10000000)
                {
                    sub_4ED970(50.0, (float2*)(i + 56), &a3);
                    sub_4ED790(i, v2, &a3);
                }
                v2 = v3;
            } while (v3);
        }
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004EDDE0) --------------------------------------------------------
int __cdecl sub_4EDDE0(int a1, _DWORD* a2, int* a3)
{
    if (!sub_4ED290(a1, (int)a2, (float2*)a3))
        return 0;
    sub_501960(833, (int)a2, 0, 0);
    if (!sub_40A5C0(2048) && !sub_40A5C0(4096))
        sub_511660(a2, 25 * *(_DWORD*)& byte_5D4594[2649704]);
    return 1;
}

//----- (004EDE50) --------------------------------------------------------
int __cdecl sub_4EDE50(int a1, int a2, int* a3)
{
    int v3; // edi
    unsigned __int8* v4; // eax

    if (!a1 || !a2 || !a3)
        return 0;
    v3 = sub_4ED290(a1, a2, (float2*)a3);
    if (v3)
    {
        if (!sub_40A5C0(2048))
            sub_511660((_DWORD*)a2, 25 * *(_DWORD*)& byte_5D4594[2649704]);
        v4 = &byte_587000[205704];
        if (*(_WORD*)& byte_587000[205710])
        {
            while (!(*(_DWORD*)(a2 + 12) & *(_DWORD*)v4) && !(*((_WORD*)v4 + 2) & *(_WORD*)(a2 + 24)))
            {
                v4 += 8;
                if (!*((_WORD*)v4 + 3))
                    return v3;
            }
            sub_501960(*((unsigned __int16*)v4 + 3), a1, 0, 0);
        }
    }
    return v3;
}

//----- (004EDF00) --------------------------------------------------------
void __cdecl sub_4EDF00(int a1, int a2)
{
    int v2; // eax
    double v3; // st7
    double v4; // st7
    double v5; // st7
    double v6; // st6
    double v7; // st7
    double v8; // st6
    double v9; // st7
    double v10; // st6
    double v11; // st5
    float v12; // ecx
    float v13; // edx
    float v14; // eax
    float v15; // eax
    float v16; // esi
    float v17; // eax
    float v18; // esi
    float v19; // ecx
    float v20; // ecx
    float v21; // eax
    float v22; // edx
    int v23; // eax
    _DWORD* v24; // esi
    int v25; // esi
    int v26; // edi
    float v27; // [esp+Ch] [ebp-44h]
    float v28; // [esp+10h] [ebp-40h]
    float v29; // [esp+14h] [ebp-3Ch]
    float v30; // [esp+18h] [ebp-38h]
    int v31; // [esp+1Ch] [ebp-34h]
    int v32; // [esp+1Ch] [ebp-34h]
    float2 a1a; // [esp+20h] [ebp-30h]
    float4 v34; // [esp+28h] [ebp-28h]
    float2 a3[3]; // [esp+38h] [ebp-18h]

    if (a1)
    {
        if (a2)
        {
            v31 = sub_4E7D30(a1, 0);
            if (v31)
            {
                v2 = *(_DWORD*)(a1 + 12);
                if (v2 & 0x100)
                {
                    a1a.field_0 = -1.0;
                    a1a.field_4 = -1.0;
                }
                else if (v2 & 0x200)
                {
                    a1a.field_0 = 1.0;
                    a1a.field_4 = -1.0;
                }
                else if (v2 & 0x400)
                {
                    a1a.field_0 = 1.0;
                    a1a.field_4 = 1.0;
                }
                else if (v2 & 0x800)
                {
                    a1a.field_0 = -1.0;
                    a1a.field_4 = 1.0;
                }
                else
                {
                    a1a.field_0 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
                    a1a.field_4 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
                }
                sub_509F20(&a1a);
                v3 = sub_4EE2A0(a1) + 4.0 + 15.0;
                a3[0].field_0 = v3 * a1a.field_0 + *(float*)(a1 + 56);
                a3[0].field_4 = v3 * a1a.field_4 + *(float*)(a1 + 60);
                v4 = -a1a.field_4;
                v29 = -v4;
                v30 = -a1a.field_0;
                a3[1].field_0 = v4 * 30.0 + a3[0].field_0;
                a3[1].field_4 = a1a.field_0 * 30.0 + a3[0].field_4;
                a3[2].field_0 = v29 * 30.0 + a3[0].field_0;
                a3[2].field_4 = v30 * 30.0 + a3[0].field_4;
                v5 = a3[0].field_0 - *(float*)(a2 + 56);
                v6 = a3[0].field_4 - *(float*)(a2 + 60);
                v27 = v6 * v6 + v5 * v5;
                v7 = a3[1].field_0 - *(float*)(a2 + 56);
                v8 = a3[1].field_4 - *(float*)(a2 + 60);
                v9 = v8 * v8 + v7 * v7;
                v10 = a3[2].field_0 - *(float*)(a2 + 56);
                v11 = a3[2].field_4 - *(float*)(a2 + 60);
                v28 = v11 * v11 + v10 * v10;
                if (v27 >= v9)
                {
                    v13 = a3[1].field_4;
                    v12 = a3[1].field_0;
                }
                else
                {
                    v12 = a3[0].field_0;
                    v13 = a3[0].field_4;
                    a3[0].field_0 = a3[1].field_0;
                    a3[1].field_0 = v12;
                    a3[0].field_4 = a3[1].field_4;
                    v14 = v27;
                    v27 = v9;
                    a3[1].field_4 = v13;
                    v9 = v14;
                }
                if (v9 < v28)
                {
                    v15 = v12;
                    v12 = a3[2].field_0;
                    v16 = v13;
                    v13 = a3[2].field_4;
                    v9 = v28;
                    a3[1].field_0 = a3[2].field_0;
                    a3[1].field_4 = a3[2].field_4;
                    a3[2].field_0 = v15;
                    a3[2].field_4 = v16;
                }
                if (v27 < v9)
                {
                    v17 = a3[0].field_0;
                    v18 = a3[0].field_4;
                    a3[0].field_0 = v12;
                    a3[0].field_4 = v13;
                    a3[1].field_0 = v17;
                    a3[1].field_4 = v18;
                }
                v19 = *(float*)(a1 + 56);
                v34.field_4 = *(float*)(a1 + 60);
                v34.field_0 = v19;
                v34.field_8 = a3[2].field_0;
                v34.field_C = a3[2].field_4;
                if (!sub_535250(&v34, 0, 0, 1))
                {
                    v20 = *(float*)(a2 + 60);
                    a3[2].field_0 = *(float*)(a2 + 56);
                    a3[2].field_4 = v20;
                }
                v34.field_8 = a3[1].field_0;
                v34.field_C = a3[1].field_4;
                if (!sub_535250(&v34, 0, 0, 1))
                {
                    v21 = *(float*)(a2 + 60);
                    a3[1].field_0 = *(float*)(a2 + 56);
                    a3[1].field_4 = v21;
                }
                v34.field_8 = a3[0].field_0;
                v34.field_C = a3[0].field_4;
                if (!sub_535250(&v34, 0, 0, 1))
                {
                    v22 = *(float*)(a2 + 60);
                    a3[0].field_0 = *(float*)(a2 + 56);
                    a3[0].field_4 = v22;
                }
                if (v31 == 1)
                {
                    v23 = sub_4E7980(a1);
                    v24 = (_DWORD*)v23;
                    if (*(char*)(v23 + 488) != -1 && !(*(_BYTE*)(v23 + 8) & 2))
                    {
                        *(_DWORD*)(v23 + 16) |= 0x40u;
                        sub_511810(v23);
                        sub_4ED790(a1, v24, a3);
                    }
                }
                else
                {
                    v25 = sub_4E7980(a1);
                    v26 = 0;
                    if (v25)
                    {
                        do
                        {
                            v32 = sub_4E7990(v25);
                            if (*(char*)(v25 + 488) != -1 && !(*(_BYTE*)(v25 + 8) & 2))
                            {
                                *(_DWORD*)(v25 + 16) |= 0x40u;
                                sub_511810(v25);
                                sub_4ED790(a1, (_DWORD*)v25, &a3[v26++]);
                                if (v26 >= 3)
                                    v26 = 0;
                            }
                            v25 = v32;
                        } while (v32);
                    }
                }
            }
        }
    }
}

//----- (004EE2A0) --------------------------------------------------------
double __cdecl sub_4EE2A0(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)(a1 + 172);
    if (v1 == 2)
        return *(float*)(a1 + 176);
    if (v1 != 3)
        return 0.0;
    if (*(float*)(a1 + 184) <= (double) * (float*)(a1 + 188))
        return *(float*)(a1 + 188) * 0.5;
    return *(float*)(a1 + 184) * 0.5;
}

//----- (004EE2F0) --------------------------------------------------------
int __cdecl sub_4EE2F0(int a1, int a2, int* a3)
{
    int v3; // edi
    __int16 v4; // ax
    unsigned __int8* v5; // ecx

    if (!a1 || !a2 || !a3)
        return 0;
    v3 = sub_4ED290(a1, a2, (float2*)a3);
    if (v3)
    {
        v4 = *(_WORD*)& byte_5D4594[3815180];
        v5 = &byte_5D4594[3815180];
        if (*(short*)& byte_5D4594[3815180] != -1)
        {
            while (v4 != *(_WORD*)(a2 + 4))
            {
                v4 = *((_WORD*)v5 + 2);
                v5 += 4;
                if (v4 == -1)
                    return v3;
            }
            sub_501960(*((unsigned __int16*)v5 + 1), a1, 0, 0);
        }
    }
    return v3;
}

//----- (004EE370) --------------------------------------------------------
int __cdecl sub_4EE370(int a1, int a2, int* a3)
{
    return sub_4ED290(a1, a2, (float2*)a3);
}

//----- (004EE390) --------------------------------------------------------
int __cdecl sub_4EE390(int a1)
{
    int result; // eax
    int v2; // ecx

    result = a1;
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 556);
        if (v2)
        {
            *(_DWORD*)(v2 + 12) = 0;
            result = *(_DWORD*)(a1 + 556);
            *(_DWORD*)(result + 8) = 0;
        }
        else
        {
            *(_DWORD*)0xC = 0;
            *(_DWORD*)(*(_DWORD*)(a1 + 556) + 8) = *(_DWORD*)& byte_5D4594[1568260];
            if (*(_DWORD*)& byte_5D4594[1568260])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1568260] + 448) = a1;
            *(_DWORD*)& byte_5D4594[1568260] = a1;
        }
    }
    return result;
}

//----- (004EE3E0) --------------------------------------------------------
void __cdecl sub_4EE3E0(int a1)
{
    int v1; // eax
    int v2; // ecx
    int v3; // eax
    int v4; // ecx

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 556);
        if (v1)
        {
            v2 = *(_DWORD*)(v1 + 8);
            if (v2)
                * (_DWORD*)(*(_DWORD*)(v2 + 556) + 12) = *(_DWORD*)(v1 + 12);
            v3 = *(_DWORD*)(a1 + 556);
            v4 = *(_DWORD*)(v3 + 12);
            if (v4)
                * (_DWORD*)(*(_DWORD*)(v4 + 556) + 8) = *(_DWORD*)(v3 + 8);
            else
                *(_DWORD*)& byte_5D4594[1568260] = *(_DWORD*)(v3 + 8);
        }
    }
}

//----- (004EE430) --------------------------------------------------------
int sub_4EE430()
{
    return *(_DWORD*)& byte_5D4594[1568260];
}

//----- (004EE440) --------------------------------------------------------
int __cdecl sub_4EE440(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(*(_DWORD*)(a1 + 556) + 8);
    else
        result = 0;
    return result;
}

//----- (004EE460) --------------------------------------------------------
void __cdecl sub_4EE460(int a1, int a2)
{
    unsigned __int16* v2; // ecx
    unsigned __int16 v3; // dx
    int v4; // ecx
    unsigned __int16 v5; // ax

    if (!sub_40A5C0(0x4000000))
    {
        v2 = *(unsigned __int16**)(a1 + 556);
        if (v2)
        {
            v3 = v2[2];
            if (*v2 < v3)
            {
                v4 = *v2 + a2;
                v5 = v3;
                if (v4 < v3)
                    v5 = v4;
                sub_4E4560(a1, v5);
                if (*(_BYTE*)(a1 + 8) & 2)
                    sub_4EE4C0((_DWORD*)a1);
            }
        }
    }
}

//----- (004EE4C0) --------------------------------------------------------
void __cdecl sub_4EE4C0(_DWORD* a1)
{
    int v1; // eax

    if (a1)
    {
        v1 = a1[127];
        if (v1)
        {
            if (*(_BYTE*)(v1 + 8) & 4)
                sub_4D8620(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v1 + 748) + 276) + 2064), a1);
        }
    }
}

//----- (004EE500) --------------------------------------------------------
void __cdecl sub_4EE500(int a1)
{
    int v1; // ebx
    int v2; // esi
    int v3; // ebp
    int v4; // edi
    int v5; // eax
    double v6; // st7
    wchar_t* v7; // eax

    v1 = a1;
    if (a1)
    {
        if (sub_40A5C0(2048))
        {
            v2 = *(_DWORD*)(a1 + 520);
            if (v2)
            {
                v3 = 1;
                v4 = sub_4EC580(*(_DWORD*)(a1 + 520));
                if (*(_BYTE*)(v4 + 8) & 4)
                {
                    v5 = 0;
                    if (v2 == v4)
                        goto LABEL_12;
                    do
                    {
                        if (v5)
                            break;
                        if (*(_BYTE*)(v2 + 8) & 2)
                        {
                            v3 = sub_500CC0(v4, v2);
                            v5 = 1;
                        }
                        v2 = *(_DWORD*)(v2 + 508);
                    } while (v2 != v4);
                    if (v3)
                    {
                        v1 = a1;
                        LABEL_12:
                        v6 = sub_4EF270(v4, *(float*)(v1 + 28));
                        if (v6 > 0.0)
                        {
                            v7 = loadString_sub_40F1D0((char*)& byte_587000[206012], 0, "C:\\NoxPost\\src\\Server\\Object\\health.c", 172);
                            sub_4D9EB0(v4, v7, (unsigned int)(__int64)v6);
                        }
                        return;
                    }
                }
            }
        }
    }
}

//----- (004EE5E0) --------------------------------------------------------
void __cdecl sub_4EE5E0(int a1, int a2)
{
    int v2; // eax
    int v3; // eax
    int v4; // eax
    void(__cdecl * v5)(int); // eax

    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 556);
        if (v2)
        {
            if (*(_WORD*)(v2 + 4) && (!(byte_5D4594[2650636] & 0x20) || !(*(_BYTE*)(a1 + 8) & 4)))
            {
                if (*(_BYTE*)(a1 + 8) & 4)
                {
                    v3 = *(_DWORD*)(a1 + 748);
                    if (v3)
                    {
                        if (!*(_BYTE*)(*(_DWORD*)(v3 + 276) + 2251) && *(_DWORD*)(v3 + 132))
                            sub_537520((_DWORD*)a1);
                    }
                }
                if (**(unsigned __int16**)(a1 + 556) > a2)
                {
                    sub_4E4560(a1, **(_WORD * *)(a1 + 556) - a2);
                }
                else
                {
                    sub_4E4560(a1, 0);
                    v4 = *(_DWORD*)(a1 + 16);
                    if ((v4 & 0x8000) == 0)
                    {
                        BYTE1(v4) |= 0x80u;
                        *(_DWORD*)(a1 + 16) = v4;
                        sub_4FF5B0(a1, 16);
                        if (!sub_534A40(a1))
                            sub_4EE500(a1);
                        if (*(_BYTE*)(a1 + 8) & 2)
                        {
                            sub_50A3D0((_DWORD*)a1);
                        }
                        else
                        {
                            v5 = *(void(__cdecl * *)(int))(a1 + 724);
                            if (v5)
                                v5(a1);
                            else
                                sub_4E5CC0(a1);
                        }
                    }
                }
                if (*(_BYTE*)(a1 + 8) & 2)
                    sub_4EE4C0((_DWORD*)a1);
            }
        }
    }
}

//----- (004EE6F0) --------------------------------------------------------
void __cdecl sub_4EE6F0(int a1)
{
    int v1; // eax

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 556);
        if (v1)
        {
            sub_4E4560(a1, *(_WORD*)(v1 + 4));
            *(_WORD*)(*(_DWORD*)(a1 + 556) + 2) = **(_WORD * *)(a1 + 556);
            if (*(_BYTE*)(a1 + 8) & 2)
                sub_4EE4C0((_DWORD*)a1);
        }
    }
}

//----- (004EE730) --------------------------------------------------------
void __cdecl sub_4EE730(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // edx

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v1 = *(_DWORD*)(a1 + 748);
            if (*(_DWORD*)(a1 + 556))
            {
                v2 = v1 + 12;
                v3 = 32;
                do
                {
                    v2 += 2;
                    --v3;
                    *(_WORD*)(v2 - 2) = **(_WORD * *)(a1 + 556);
                } while (v3);
                *(_WORD*)(v1 + 76) = **(_WORD * *)(a1 + 556);
            }
        }
    }
}

//----- (004EE780) --------------------------------------------------------
__int16 __cdecl sub_4EE780(int a1)
{
    __int16* v1; // eax
    __int16 result; // ax

    if (a1 && (v1 = *(__int16**)(a1 + 556)) != 0)
        result = *v1;
    else
        result = 0;
    return result;
}

//----- (004EE7A0) --------------------------------------------------------
__int16 __cdecl sub_4EE7A0(int a1)
{
    int v1; // eax
    __int16 result; // ax

    if (a1 && (v1 = *(_DWORD*)(a1 + 556)) != 0)
        result = *(_WORD*)(v1 + 4);
    else
        result = 0;
    return result;
}

//----- (004EE7C0) --------------------------------------------------------
int __cdecl sub_4EE7C0(int a1, __int16 a2)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        result = *(_DWORD*)(a1 + 556);
        if (result)
            * (_WORD*)(result + 4) = a2;
    }
    return result;
}

//----- (004EE7E0) --------------------------------------------------------
int __cdecl sub_4EE7E0(int a1, int a2, int a3)
{
    int v3; // ebx
    int v5; // eax
    int v6; // eax
    int v7; // edi
    int v8; // edi
    int v9; // esi
    float v10; // [esp+0h] [ebp-10h]

    v3 = *(unsigned __int8*)(a1 + 540);
    if (!a1)
        return 0;
    if (*(_BYTE*)(a1 + 16) & 2)
        return 0;
    if (sub_4FF350(a1, 23))
        return 0;
    v5 = *(_DWORD*)(a1 + 8);
    if (v5 & 4 && (*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 3680) & 1) == 1)
        return 0;
    if (v5 & 2)
    {
        v6 = *(_DWORD*)(a1 + 12);
        if (v6 & 0x200)
            return 0;
    }
    v10 = sub_4E0040((_DWORD*)a1) * 100.0;
    v7 = sub_419A70(v10);
    if (sub_415FA0(0, 100) < v7)
    {
        sub_4DA2C0(a1, "Health.c:ResistPoison", 0);
        return 0;
    }
    v8 = v3 + a2;
    if (v3 + a2 <= a3)
        goto LABEL_19;
    if (v3 <= a3)
    {
        v8 = a3;
        LABEL_19:
        if (v8 != v3)
        {
            sub_4EEA90(a1, v8);
            sub_501960(100, a1, 0, 0);
        }
        goto LABEL_21;
    }
    v8 = v3;
    LABEL_21:
    if (!v3 && v8 > 0)
    {
        v9 = *(_DWORD*)(a1 + 556);
        if (v9)
            * (_DWORD*)(v9 + 16) = *(_DWORD*)& byte_5D4594[2598000];
    }
    return 1;
}

//----- (004EE8F0) --------------------------------------------------------
void __cdecl sub_4EE8F0(int a1, int a2)
{
    int v2; // eax
    int v3; // eax
    char* v4; // eax
    int v5; // eax
    int v6; // eax

    if (a1)
    {
        if (*(unsigned __int8*)(a1 + 540) > a2)
        {
            *(_BYTE*)(a1 + 540) -= a2;
        }
        else
        {
            v2 = *(_DWORD*)(a1 + 556);
            *(_BYTE*)(a1 + 540) = 0;
            if (v2)
                * (_DWORD*)(v2 + 16) = 0;
            v3 = *(_DWORD*)(a1 + 8);
            if (v3 & 4)
            {
                sub_417530(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276), 1024);
                sub_4DA2C0(a1, "Health.c:PoisonFade", 0);
            }
            else if (v3 & 2)
            {
                if (sub_40A5C0(2048) && *(_BYTE*)(a1 + 12) & 0x10)
                {
                    v4 = sub_417090(31);
                    if (v4)
                    {
                        v5 = *((_DWORD*)v4 + 514);
                        if (v5)
                            sub_4D7F40(v5, (_DWORD*)a1, 0);
                    }
                }
                else if (*(_BYTE*)(a1 + 12) & 0x80)
                {
                    v6 = *(_DWORD*)(a1 + 508);
                    if (v6)
                        sub_4D7F40(v6, (_DWORD*)a1, 0);
                }
            }
        }
    }
}

//----- (004EE9D0) --------------------------------------------------------
void __cdecl sub_4EE9D0(int a1)
{
    int v1; // eax
    int v2; // eax
    char* v3; // eax
    int v4; // eax
    int v5; // eax

    if (a1 && *(_BYTE*)(a1 + 540))
    {
        v1 = *(_DWORD*)(a1 + 556);
        *(_BYTE*)(a1 + 540) = 0;
        if (v1)
            * (_DWORD*)(v1 + 16) = 0;
        v2 = *(_DWORD*)(a1 + 8);
        if (v2 & 4)
        {
            sub_417530(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276), 1024);
        }
        else if (v2 & 2)
        {
            if (sub_40A5C0(2048) && *(_BYTE*)(a1 + 12) & 0x10)
            {
                v3 = sub_417090(31);
                if (v3)
                {
                    v4 = *((_DWORD*)v3 + 514);
                    if (v4)
                        sub_4D7F40(v4, (_DWORD*)a1, 0);
                }
            }
            else if (*(_BYTE*)(a1 + 12) & 0x80)
            {
                v5 = *(_DWORD*)(a1 + 508);
                if (v5)
                    sub_4D7F40(v5, (_DWORD*)a1, 0);
            }
        }
    }
}

//----- (004EEA90) --------------------------------------------------------
void __cdecl sub_4EEA90(int a1, int a2)
{
    int v2; // eax
    int v3; // eax
    int v4; // eax
    char* v5; // eax
    int v6; // eax

    if (a1)
    {
        if (!*(_BYTE*)(a1 + 540) && a2 > 0)
        {
            v2 = *(_DWORD*)(a1 + 556);
            if (v2)
                * (_DWORD*)(v2 + 16) = *(_DWORD*)& byte_5D4594[2598000];
        }
        v3 = *(_DWORD*)(a1 + 8);
        *(_BYTE*)(a1 + 540) = a2;
        if (v3 & 4)
        {
            v4 = *(_DWORD*)(a1 + 748);
            if (a2 != 0)
                sub_4174F0(*(_DWORD*)(v4 + 276), 1024);
            else
                sub_417530(*(_DWORD*)(v4 + 276), 1024);
        }
        else if (v3 & 2)
        {
            if (sub_40A5C0(2048) && *(_BYTE*)(a1 + 12) & 0x10)
            {
                v5 = sub_417090(31);
                if (!v5)
                    goto LABEL_19;
                v6 = *((_DWORD*)v5 + 514);
                if (!v6)
                    goto LABEL_19;
            }
            else
            {
                if ((signed char) * (_BYTE*)(a1 + 12) >= 0)
                    goto LABEL_19;
                v6 = *(_DWORD*)(a1 + 508);
                if (!v6)
                    goto LABEL_19;
            }
            sub_4D7F40(v6, (_DWORD*)a1, a2 != 0);
        }
        LABEL_19:
        if (a2)
            * (_WORD*)(a1 + 542) = 1000;
        else
            *(_WORD*)(a1 + 542) = 0;
    }
}

//----- (004EEB80) --------------------------------------------------------
unsigned __int16 __cdecl sub_4EEB80(int a1, __int16 a2)
{
    unsigned __int16 result; // ax
    int v3; // esi
    __int16 v4; // ax
    unsigned __int16 v5; // cx
    unsigned __int16 v6; // ax

    result = a1;
    if (a1 && *(_BYTE*)(a1 + 8) & 4)
    {
        v3 = *(_DWORD*)(a1 + 748);
        v4 = *(_WORD*)(v3 + 4);
        v5 = *(_WORD*)(v3 + 8);
        *(_WORD*)(v3 + 6) = v4;
        v6 = a2 + v4;
        *(_WORD*)(v3 + 4) = v6;
        if (v6 > v5)
            * (_WORD*)(v3 + 4) = v5;
        sub_56F9E0(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4596), a2);
        result = *(_WORD*)(v3 + 8);
        if (*(_WORD*)(v3 + 4) > result)
            result = (unsigned int)sub_56F870(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4596), result);
    }
    return result;
}

//----- (004EEBF0) --------------------------------------------------------
_DWORD* __cdecl sub_4EEBF0(int a1, int a2)
{
    _DWORD* result; // eax
    unsigned __int16 v3; // cx

    result = (_DWORD*)a1;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            result = *(_DWORD * *)(a1 + 748);
            if (!(byte_5D4594[2650636] & 0x20))
            {
                v3 = *((_WORD*)result + 2);
                *((_WORD*)result + 3) = v3;
                if (v3 > a2)
                    * ((_WORD*)result + 2) = v3 - a2;
                else
                    *((_WORD*)result + 2) = 0;
                if (*((unsigned __int16*)result + 2) > a2)
                    result = sub_56F9E0(*(_DWORD*)(result[69] + 4596), -(__int16)a2);
                else
                    result = sub_56F9E0(*(_DWORD*)(result[69] + 4596), -*((_WORD*)result + 2));
            }
        }
    }
    return result;
}

//----- (004EEC80) --------------------------------------------------------
__int16 __cdecl sub_4EEC80(int a1)
{
    int v1; // eax
    __int16 result; // ax

    if (!a1)
        goto LABEL_9;
    v1 = *(_DWORD*)(a1 + 8);
    if (v1 & 4)
        return *(_WORD*)(*(_DWORD*)(a1 + 748) + 4);
    if (v1 & 2)
        result = 1000;
    else
        LABEL_9:
        result = 0;
    return result;
}

//----- (004EECB0) --------------------------------------------------------
__int16 __cdecl sub_4EECB0(int a1)
{
    __int16 result; // ax

    if (a1 && *(_BYTE*)(a1 + 8) & 4)
        result = *(_WORD*)(*(_DWORD*)(a1 + 748) + 8);
    else
        result = 0;
    return result;
}

//----- (004EECD0) --------------------------------------------------------
int __cdecl sub_4EECD0(int a1, __int16 a2)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            result = *(_DWORD*)(a1 + 748);
            *(_WORD*)(result + 8) = a2;
        }
    }
    return result;
}

//----- (004EECF0) --------------------------------------------------------
_DWORD* __cdecl sub_4EECF0(int a1)
{
    _DWORD* result; // eax
    int v2; // eax
    int v3; // edx
    __int16 v4; // cx

    result = (_DWORD*)a1;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v2 = *(_DWORD*)(a1 + 748);
            v3 = *(_DWORD*)(v2 + 276);
            *(_WORD*)(v2 + 6) = *(_WORD*)(v2 + 4);
            v4 = *(_WORD*)(v2 + 8);
            *(_WORD*)(v2 + 4) = v4;
            result = sub_56F9E0(*(_DWORD*)(v3 + 4596), v4);
        }
    }
    return result;
}

//----- (004EED30) --------------------------------------------------------
void sub_4EED30()
{
    nox_srand(0x22D6u);
}

//----- (004EED40) --------------------------------------------------------
void __cdecl sub_4EED40(int a1, char a2, int a3)
{
    int* v3; // esi
    _DWORD* v4; // edi
    int v5; // ebx

    if (a1 && a2 > 0)
    {
        v3 = (int*)& byte_587000[206108];
        v4 = (_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 3696);
        v5 = a2;
        do
        {
            if (*v3)
            {
                if (sub_40A5C0(4096) || sub_4D6F50() || sub_4D6F70())
                    * v4 = 0;
                else
                    sub_4FB9C0(a1, *v3, a3);
            }
            ++v3;
            ++v4;
            --v5;
        } while (v5);
    }
}

//----- (004EEDC0) --------------------------------------------------------
int __cdecl sub_4EEDC0(int a1, int a2)
{
    int v2; // ebx
    int v3; // edi
    int v4; // esi
    float* v5; // ebp
    __int16 v6; // ax
    char v7; // al
    double v8; // st7
    __int16 v9; // ax
    double v10; // st7
    int i; // eax
    int v12; // edx
    int v13; // eax
    size_t v14; // eax
    int result; // eax
    float v16; // [esp-1Ch] [ebp-40h]
    float v17; // [esp+0h] [ebp-24h]
    float v18; // [esp+0h] [ebp-24h]
    float v19; // [esp+0h] [ebp-24h]
    float v20; // [esp+0h] [ebp-24h]
    int v21; // [esp+0h] [ebp-24h]
    float v22; // [esp+14h] [ebp-10h]
    int v23; // [esp+18h] [ebp-Ch]
    char v24; // [esp+1Ch] [ebp-8h]
    float* v25; // [esp+20h] [ebp-4h]
    float* v26; // [esp+28h] [ebp+4h]

    v2 = a1;
    v3 = *(_DWORD*)(a1 + 748);
    v23 = 0;
    v4 = *(_DWORD*)(v3 + 276);
    v26 = sub_57B350();
    v5 = sub_57B360(*(unsigned __int8*)(v4 + 2251));
    v25 = sub_57B360(0);
    if (sub_40A5C0(0x2000))
    {
        *(_WORD*)(*(_DWORD*)(v2 + 556) + 4) = sub_419A70(*v5);
        v6 = sub_419AB0(*v5);
        sub_4E4560(v2, v6);
        *(_WORD*)(v3 + 8) = sub_419A70(v5[1]);
        *(_WORD*)(v3 + 4) = sub_419A70(v5[1]);
        *(_DWORD*)(v4 + 2239) = sub_419A70(v5[3]);
        v16 = v5[2];
        *(float*)(v2 + 548) = v5[2] * 0.000099999997;
        *(_DWORD*)(v4 + 2235) = sub_419A70(v16);
        if (!*(_BYTE*)(v4 + 2251) && !sub_40A5C0(4096) && !sub_4D6F30())
            sub_4EED40(v2, 10, 0);
    }
    else
    {
        v7 = *(_BYTE*)(v4 + 3684);
        if (v7 > 10)
            v7 = 10;
        v24 = v7;
        v22 = (double)(v7 - 1);
        v17 = (*v5 - *v26) * 0.11111111 * v22 + *v26 + 0.5;
        *(_WORD*)(*(_DWORD*)(v2 + 556) + 4) = sub_419A70(v17);
        sub_4E4560(v2, *(_WORD*)(*(_DWORD*)(v2 + 556) + 4));
        v8 = (v5[1] - v26[1]) * 0.11111111 * v22 + v26[1];
        if (v8 > v5[1])
            v8 = v5[1];
        v18 = v8 + 0.5;
        v9 = sub_419A70(v18);
        *(_WORD*)(v3 + 8) = v9;
        *(_WORD*)(v3 + 4) = v9;
        v19 = (v5[3] - v26[3]) * 0.11111111 * v22 + v26[3] + 0.5;
        *(_DWORD*)(v4 + 2239) = sub_419A70(v19);
        v10 = (v5[2] - v26[2]) * 0.11111111 * v22 + v26[2];
        *(float*)(v2 + 548) = v10 * 0.000099999997;
        v20 = v10 + 0.5;
        *(_DWORD*)(v4 + 2235) = sub_419A70(v20);
        if (!*(_BYTE*)(v4 + 2251))
            sub_4EED40(v2, v24, a2);
    }
    *(float*)(v2 + 120) = (double) * (int*)(v4 + 2239) / v25[3] * 20.0 + 10.0;
    *(_WORD*)(*(_DWORD*)(v3 + 276) + 3652) = (__int64)(((double) * (int*)(v4 + 2239) / v25[3] * 1250.0 + 750.0)
                                                       * *(double*)& byte_581450[10216]);
    *(_WORD*)(v2 + 490) = *(_WORD*)(*(_DWORD*)(v3 + 276) + 3652);
    sub_56F780(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4624), *(_DWORD*)(v4 + 2239));
    sub_56F780(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4620), *(_DWORD*)(v4 + 2235));
    sub_56F870(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4600), *(_WORD*)(v3 + 8));
    sub_56F870(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4592), *(_WORD*)(*(_DWORD*)(v2 + 556) + 4));
    for (i = *(_DWORD*)(v2 + 504); i; v23 += v12)
    {
        v12 = *(unsigned __int8*)(i + 488);
        i = *(_DWORD*)(i + 496);
    }
    *(_DWORD*)(v4 + 3656) = v23 > * (unsigned __int16*)(v2 + 490);
    v13 = *(_DWORD*)(v3 + 276);
    v21 = *(_DWORD*)(v13 + 4628);
    v14 = nox_wcslen((const wchar_t*)(v13 + 2185));
    result = sub_56FB00((int*)(*(_DWORD*)(v3 + 276) + 2185), 2 * v14, v21);
    *(_BYTE*)(v4 + 2184) = 1;
    return result;
}

//----- (004EF140) --------------------------------------------------------
int __cdecl sub_4EF140(int a1)
{
    int v1; // edi
    int v2; // ecx
    int result; // eax
    int i; // ebx
    int v5; // [esp-Ch] [ebp-14h]

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
    if (sub_40A5C0(0x2000))
    {
        v2 = *(_DWORD*)(v1 + 4644);
        *(_BYTE*)(v1 + 3684) = 10;
        sub_56F820(v2, 0xAu);
        result = sub_4EEDC0(a1, 0);
    }
    else
    {
        for (i = 0; i <= 10; ++i)
        {
            if (sub_419D70(&byte_587000[206152], i) > * (float*)(a1 + 28))
                break;
        }
        v5 = *(_DWORD*)(v1 + 4644);
        *(_BYTE*)(v1 + 3684) = i - 1;
        sub_56F820(v5, i - 1);
        result = sub_4EEDC0(a1, 0);
    }
    return result;
}

//----- (004EF1E0) --------------------------------------------------------
double __cdecl sub_4EF1E0(int a1, int a2)
{
    double result; // st7

    if (!*(_DWORD*)& byte_5D4594[1568264])
        * (_DWORD*)& byte_5D4594[1568264] = sub_4E3AA0((CHAR*)& byte_587000[206160]);
    if (!sub_40A5C0(2048) || *(_DWORD*)(a2 + 4) != *(_DWORD*)& byte_5D4594[1568264])
        result = (double)(a1 - *(unsigned __int16*)(a2 + 60)) * *(float*)(a2 + 64)
                 + (double) * (unsigned __int16*)(a2 + 72);
    else
        result = sub_419D40(&byte_587000[206172]) + (double)(a1 - *(unsigned __int16*)(a2 + 60)) * *(float*)(a2 + 64);
    return result;
}

//----- (004EF270) --------------------------------------------------------
double __cdecl sub_4EF270(int a1, float a2)
{
    int v3; // ecx
    double v4; // st7
    float v5; // [esp+Ch] [ebp+8h]

    if (*(float*)(a1 + 28) >= (double)a2)
        return 0.0;
    v3 = *(_DWORD*)(a1 + 748);
    v4 = (a2 - *(float*)(a1 + 28)) * *(float*)& byte_587000[206148] + 1.0;
    v5 = v4;
    *(float*)(a1 + 28) = v4 + *(float*)(a1 + 28);
    sub_56FA40(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4604), v5);
    sub_4D81A0(a1);
    sub_4EF2E0(a1);
    return v5;
}

//----- (004EF2E0) --------------------------------------------------------
void __cdecl sub_4EF2E0(int a1)
{
    int v1; // esi
    wchar_t* v2; // eax

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
    if ((sub_4DB1B0() != 1 || !sub_4DB1C0())
        && sub_419D70(&byte_587000[206192], *(char*)(v1 + 3684) + 1) <= *(float*)(a1 + 28))
    {
        ++* (_BYTE*)(v1 + 3684);
        sub_56F980(*(_DWORD*)(v1 + 4644), 1u);
        sub_4EEDC0(a1, 1);
        if (sub_40A5C0(2048))
        {
            sub_57AF30(a1, 0);
        }
        else
        {
            sub_501960(902, a1, 2, *(_DWORD*)(a1 + 36));
            v2 = loadString_sub_40F1D0((char*)& byte_587000[206244], 0, "C:\\NoxPost\\src\\Server\\GameMech\\explevel.c", 253);
            sub_4D9EB0(a1, v2);
        }
    }
}

//----- (004EF3A0) --------------------------------------------------------
void __cdecl sub_4EF3A0(int a1, float a2)
{
    int v2; // ecx
    wchar_t* v3; // eax

    v2 = *(_DWORD*)(a1 + 748);
    *(float*)(a1 + 28) = a2 + *(float*)(a1 + 28);
    sub_56FA40(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4604), a2);
    sub_4D81A0(a1);
    v3 = loadString_sub_40F1D0((char*)& byte_587000[206296], 0, "C:\\NoxPost\\src\\Server\\GameMech\\explevel.c", 381);
    sub_4D9EB0(a1, v3, (unsigned int)(__int64)a2);
    sub_4EF2E0(a1);
}

//----- (004EF410) --------------------------------------------------------
void __cdecl sub_4EF410(int a1, unsigned __int8 a2)
{
    signed __int8 v2; // bl
    int v3; // esi
    int v4; // edi
    _DWORD* v5; // esi
    int v6; // [esp-10h] [ebp-24h]
    float v7; // [esp+0h] [ebp-14h]

    v2 = a2;
    v3 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
    if ((char)a2 > 10)
    {
        v2 = 10;
        a2 = 10;
    }
    *(float*)(a1 + 28) = sub_419D70(&byte_587000[206316], v2);
    v7 = sub_419D70(&byte_587000[206324], v2);
    sub_56F8C0(*(_DWORD*)(v3 + 4604), v7);
    sub_4D81A0(a1);
    v6 = *(_DWORD*)(v3 + 4644);
    *(_BYTE*)(v3 + 3684) = v2;
    sub_56F820(v6, a2);
    sub_4EEDC0(a1, 0);
    if (sub_40A5C0(2048) && !*(_BYTE*)(v3 + 2251))
    {
        v4 = 1;
        v5 = (_DWORD*)(v3 + 3700);
        do
        {
            if (*v5)
                sub_45DBE0((void*)3, v4, v4 - 1);
            ++v4;
            ++v5;
        } while (v4 < 6);
    }
    if (sub_40A5C0(2048))
        sub_57AF30(a1, 0);
}

//----- (004EF500) --------------------------------------------------------
char* __cdecl sub_4EF500(int a1)
{
    char* result; // eax
    int v2; // eax
    int i; // esi

    result = (char*)sub_40A5C0(2048);
    if (result)
    {
        v2 = *(_DWORD*)& byte_5D4594[2650636];
        if (a1 == 1)
            LOBYTE(v2) = byte_5D4594[2650636] | 0x30;
        else
            LOBYTE(v2) = byte_5D4594[2650636] & 0xCF;
        *(_DWORD*)& byte_5D4594[2650636] = v2;
        result = sub_416EA0();
        for (i = (int)result; result; i = (int)result)
        {
            sub_4EFD80(i);
            sub_4EFC80(i);
            sub_4EFE10(i);
            result = sub_416EE0(i);
        }
    }
    return result;
}

//----- (004EF560) --------------------------------------------------------
void sub_4EF560()
{
    nox_srand(0x22D7u);
}

//----- (004EF570) --------------------------------------------------------
void sub_4EF570()
{
    nox_srand(0x7DAu);
}

//----- (004EF580) --------------------------------------------------------
char sub_4EF580()
{
    char v0; // bl
    int v1; // eax
    int v2; // eax
    int v3; // eax
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax

    v0 = 0;
    v1 = sub_415CD0((char*)0x400);
    if (sub_4E3BA0(v1))
        v0 = 1;
    v2 = sub_415CD0((char*)4);
    if (sub_4E3BA0(v2))
        v0 |= 2u;
    v3 = sub_415CD0((char*)1);
    if (sub_4E3BA0(v3))
        v0 |= 4u;
    v4 = sub_415840((char*)0x8000);
    if (sub_4E3BA0(v4))
        v0 |= 8u;
    v5 = sub_415CD0((char*)0x4000);
    if (sub_4E3BA0(v5))
        v0 |= 0x10u;
    v6 = sub_415840((char*)0x100);
    if (sub_4E3BA0(v6))
        v0 |= 0x20u;
    v7 = sub_415840((char*)0x200);
    if (sub_4E3BA0(v7))
        v0 |= 0x40u;
    v8 = sub_415CD0((char*)0x1000000);
    if (sub_4E3BA0(v8))
        v0 |= 0x80u;
    return v0;
}

//----- (004EF660) --------------------------------------------------------
int __cdecl sub_4EF660(int a1)
{
    int v1; // esi
    int i; // eax

    v1 = *(_DWORD*)(a1 + 748);
    *(_DWORD*)(v1 + 116) = 0;
    *(_DWORD*)(v1 + 120) = 0;
    *(_DWORD*)(v1 + 124) = 0;
    *(_DWORD*)(v1 + 128) = 0;
    *(_DWORD*)(v1 + 308) = 0;
    for (i = 4796; i < 4816; *(_DWORD*)(*(_DWORD*)(v1 + 276) + i - 4) = 0)
        i += 4;
    if (!sub_40A5C0(2048))
        * (_BYTE*)(v1 + 244) = sub_4EF6F0(a1);
    *(_DWORD*)(v1 + 264) = 0;
    *(_DWORD*)(a1 + 520) = 0;
    return sub_422140(*(_DWORD*)(v1 + 276));
}

//----- (004EF6F0) --------------------------------------------------------
int __cdecl sub_4EF6F0(int a1)
{
    int v1; // esi
    int i; // eax

    if (!*(_DWORD*)& byte_5D4594[1568268])
        * (_DWORD*)& byte_5D4594[1568268] = sub_4E3AA0((CHAR*)& byte_587000[206368]);
    v1 = 0;
    for (i = sub_4E7980(a1); i; i = sub_4E7990(i))
    {
        if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[1568268])
            ++v1;
    }
    return v1;
}

//----- (004EF750) --------------------------------------------------------
_DWORD* __cdecl sub_4EF750(int a1, CHAR* a2, int* a3, int a4, int a5)
{
    _DWORD* v5; // eax
    _DWORD* v6; // esi
    void(__cdecl * v7)(_DWORD*, _DWORD); // eax
    int v8; // eax

    v5 = sub_4E3810(a2);
    v6 = v5;
    if (v5)
    {
        v7 = (void(__cdecl*)(_DWORD*, _DWORD))v5[172];
        if (v7)
            v7(v6, 0);
        if (a3)
            sub_4E4990((int)v6, a3);
        sub_4F36F0(a1, (int)v6, a4, a5);
        v8 = v6[2];
        v6[4] &= 0xFFF7FFFF;
        if (v8 & 0x3001000)
            * (_DWORD*)(v6[187] + 4) |= 1u;
    }
    return v6;
}

//----- (004EF7D0) --------------------------------------------------------
char __cdecl sub_4EF7D0(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // edi
    int v5; // eax
    int v6; // ecx
    int v7; // eax
    _DWORD* v8; // ebp
    int v9; // eax
    int v10; // eax
    int v11; // ebp
    int v12; // ecx
    int v13; // eax
    int v14; // eax
    int v15; // eax
    int v16; // edi
    unsigned __int8 v18[20]; // [esp+10h] [ebp-14h]
    unsigned __int8* v19; // [esp+28h] [ebp+4h]
    _DWORD* v20; // [esp+2Ch] [ebp+8h]

    v3 = a1;
    v4 = *(_DWORD*)(a1 + 748);
    v19 = (unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2185);
    if (a2)
    {
        sub_4EE9D0(v3);
        sub_4EE6F0(v3);
        sub_4EECF0(v3);
    }
    sub_4FC180(v3);
    sub_4D7E50(v3);
    *(_DWORD*)(v4 + 312) = 0;
    *(_DWORD*)(v4 + 316) = 0;
    *(_BYTE*)(v3 + 541) = 0;
    *(_DWORD*)(v4 + 84) = 0;
    *(_WORD*)(v4 + 78) = 0;
    *(_WORD*)(v4 + 76) = 0;
    v5 = v4 + 12;
    v6 = 32;
    do
    {
        v5 += 2;
        --v6;
        *(_WORD*)(v5 - 2) = **(_WORD * *)(v3 + 556);
    } while (v6);
    *(_DWORD*)(v3 + 16) &= 0xFFEB3FE7;
    sub_4FA020((_DWORD*)v3, 13);
    sub_4FF580(v3);
    *(_BYTE*)(v4 + 188) = 0;
    *(_DWORD*)(v4 + 216) = 0;
    *(_DWORD*)(v4 + 192) = 0;
    *(_DWORD*)(v4 + 196) = 0;
    *(_DWORD*)(v4 + 200) = 0;
    *(_DWORD*)(v4 + 204) = 0;
    *(_DWORD*)(v4 + 208) = 0;
    *(_BYTE*)(v4 + 212) = 0;
    *(_DWORD*)(v4 + 136) = 0;
    *(_DWORD*)(v4 + 132) = 0;
    *(_DWORD*)(v4 + 268) = 0;
    sub_4F7950(v3);
    *(_DWORD*)(v3 + 520) = 0;
    if (sub_40A5C0(0x2000))
        sub_4DE4D0(*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2064));
    v7 = *(_DWORD*)(v4 + 276);
    if (v7 && !*(_DWORD*)(v7 + 4700))
    {
        sub_4D85C0(*(unsigned __int8*)(v7 + 2064), (_DWORD*)v3);
        sub_4D88C0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), v3);
        if (a3)
        {
            LOBYTE(v7) = sub_4EFC30(v3, 0);
        }
        else
        {
            v8 = *(_DWORD * *)(v3 + 504);
            if (v8)
            {
                do
                {
                    v20 = (_DWORD*)v8[124];
                    if (sub_53E2D0((int)v8) || (v9 = v8[4], !(v9 & 0x100)) || v8[2] & 0x2000000 && sub_415C70((int)v8) & 0x808)
                        sub_4E5CC0((int)v8);
                    v8 = v20;
                } while (v20);
            }
            sub_4EFC30(v3, 1);
            v10 = sub_413290("UserColor1");
            v11 = sub_413330(v10);
            if (sub_40A5C0(2560) || *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251))
            {
                v12 = **(_DWORD * *)(v4 + 276);
                if (!(v12 & 0x400))
                {
                    *(_DWORD*)v18 = 0;
                    *(_DWORD*)& v18[4] = sub_413330(*(_DWORD*)(v11 + 4) + v19[84]);
                    *(_DWORD*)& v18[8] = sub_413330(*(_DWORD*)(v11 + 4) + v19[85]);
                    *(_DWORD*)& v18[12] = 0;
                    sub_4EF750(v3, (CHAR*)& byte_587000[206412], (int*)v18, 1, 0);
                }
            }
            if (!(**(_BYTE * *)(v4 + 276) & 4))
            {
                *(_DWORD*)v18 = 0;
                *(_DWORD*)& v18[4] = sub_413330(*(_DWORD*)(v11 + 4) + v19[83]);
                *(_DWORD*)& v18[8] = 0;
                *(_DWORD*)& v18[12] = 0;
                sub_4EF750(v3, (CHAR*)& byte_587000[206424], (int*)v18, 1, 0);
            }
            if (!(**(_BYTE * *)(v4 + 276) & 1))
            {
                *(_DWORD*)v18 = sub_413330(*(_DWORD*)(v11 + 4) + v19[87]);
                *(_DWORD*)& v18[4] = sub_413330(*(_DWORD*)(v11 + 4) + v19[86]);
                *(_DWORD*)& v18[8] = 0;
                *(_DWORD*)& v18[12] = 0;
                sub_4EF750(v3, (CHAR*)& byte_587000[206436], (int*)v18, 1, 0);
            }
            if (sub_40A5C0(2048))
            {
                v13 = sub_413290("ArmorQuality1");
                *(_DWORD*)v18 = sub_413330(v13);
                *(_DWORD*)& v18[8] = 0;
                *(_DWORD*)& v18[12] = 0;
                if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251))
                {
                    *(_DWORD*)& v18[4] = 0;
                }
                else
                {
                    v14 = sub_413290("Material1");
                    *(_DWORD*)& v18[4] = sub_413330(v14);
                }
                LOBYTE(v7) = (unsigned int)sub_4EF750(
                        v3,
                        *(CHAR * *)& byte_587000[4 * *(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2251)
                                                 + 206376],
                        (int*)v18,
                        1,
                        0);
            }
            else if (sub_40A5C0(4096) && sub_4CFE00() >= 0)
            {
                *(_DWORD*)v18 = 0;
                *(_DWORD*)& v18[4] = 0;
                *(_DWORD*)& v18[8] = 0;
                *(_DWORD*)& v18[12] = 0;
                if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251) == 1)
                {
                    v15 = sub_413290("Replenishment1");
                    *(_DWORD*)& v18[8] = sub_413330(v15);
                }
                LOBYTE(v7) = (unsigned int)sub_4EF750(
                        v3,
                        *(CHAR * *)& byte_587000[4 * *(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2251)
                                                 + 206388],
                        (int*)v18,
                        1,
                        0);
            }
            else
            {
                LOBYTE(v7) = *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251);
                if ((_BYTE)v7)
                {
                    if ((_BYTE)v7 == 1)
                        LOBYTE(v7) = (unsigned int)sub_4EF750(v3, (CHAR*)& byte_587000[206588], 0, 1, 0);
                }
                else
                {
                    sub_4EF750(v3, (CHAR*)& byte_587000[206560], 0, 1, 0);
                    LOBYTE(v7) = (unsigned int)sub_4EF750(v3, (CHAR*)& byte_587000[206572], 0, 1, 0);
                }
            }
        }
        v16 = *(_DWORD*)(v4 + 276);
        if (v16)
            * (_DWORD*)(v16 + 4700) = 1;
    }
    return v7;
}

//----- (004EFC30) --------------------------------------------------------
int __cdecl sub_4EFC30(int a1, char a2)
{
    char v3[9]; // [esp+0h] [ebp-Ch]

    v3[0] = -23;
    *(_DWORD*)& v3[3] = *(_DWORD*)& byte_5D4594[2598000];
    *(_WORD*)& v3[1] = *(_WORD*)(a1 + 36);
    v3[7] = sub_4EF580();
    v3[8] = a2;
    return sub_4E5390(255, (int)v3, 9, 0, 0);
}

//----- (004EFC80) --------------------------------------------------------
int __cdecl sub_4EFC80(int a1)
{
    int v1; // edi
    _DWORD* v2; // ebx
    char v3; // al

    sub_56F7D0(*(_DWORD*)(a1 + 4636), 0);
    v1 = 1;
    v2 = (_DWORD*)(a1 + 3700);
    if (byte_5D4594[2650636] & 0x10)
    {
        do
        {
            *v2 = 3;
            sub_56FCE0(*(_DWORD*)(a1 + 4636), v1++, 3);
            ++v2;
        } while (v1 < 137);
    }
    else
    {
        do
        {
            *v2 = 0;
            sub_56FCE0(*(_DWORD*)(a1 + 4636), v1++, 0);
            ++v2;
        } while (v1 < 137);
        if (sub_40A5C0(4096))
        {
            v3 = *(_BYTE*)(a1 + 2251);
            if (v3 == 1)
            {
                sub_4FB550(*(_DWORD*)(a1 + 2056), 27, 1, 1, 1);
            }
            else if (v3 == 2)
            {
                sub_4FB550(*(_DWORD*)(a1 + 2056), 9, 1, 1, 1);
                sub_4FB550(*(_DWORD*)(a1 + 2056), 41, 1, 1, 1);
            }
        }
    }
    return sub_56FD50(*(_DWORD*)(a1 + 4636), a1 + 3696, 137);
}

//----- (004EFD80) --------------------------------------------------------
int __cdecl sub_4EFD80(int a1)
{
    int v1; // esi
    _DWORD* v2; // ebx

    sub_56F7D0(*(_DWORD*)(a1 + 4640), 0);
    v1 = 1;
    v2 = (_DWORD*)(a1 + 4248);
    if (byte_5D4594[2650636] & 0x10)
    {
        do
        {
            *v2 = 1;
            sub_56FCE0(*(_DWORD*)(a1 + 4640), v1++, 1);
            ++v2;
        } while (v1 < 41);
    }
    else
    {
        do
        {
            *v2 = 0;
            sub_56FCE0(*(_DWORD*)(a1 + 4640), v1++, 0);
            ++v2;
        } while (v1 < 41);
    }
    return sub_56FD50(*(_DWORD*)(a1 + 4640), a1 + 4244, 41);
}

//----- (004EFE10) --------------------------------------------------------
char __cdecl sub_4EFE10(int a1)
{
    char result; // al
    int v2; // esi
    _DWORD* v3; // ebx

    result = *(_BYTE*)(a1 + 2251);
    if (!result)
    {
        v2 = 1;
        v3 = (_DWORD*)(a1 + 3700);
        if (byte_5D4594[2650636] & 0x10)
        {
            do
            {
                *v3 = 5;
                result = sub_56FCE0(*(_DWORD*)(a1 + 4636), v2++, 5);
                ++v3;
            } while (v2 < 6);
        }
        else
        {
            do
            {
                *v3 = 0;
                result = sub_56FCE0(*(_DWORD*)(a1 + 4636), v2++, 0);
                ++v3;
            } while (v2 < 6);
        }
    }
    return result;
}

//----- (004EFE80) --------------------------------------------------------
char __cdecl sub_4EFE80(int a1)
{
    int v1; // edi
    int v2; // eax
    float v4; // [esp+0h] [ebp-Ch]

    v1 = *(_DWORD*)(a1 + 748);
    v2 = sub_4FA6D0(a1);
    sub_4FA5D0(a1, v2);
    sub_4EF140(a1);
    sub_4EFD80(*(_DWORD*)(v1 + 276));
    sub_4EFC80(*(_DWORD*)(v1 + 276));
    sub_4EEDC0(a1, 0);
    sub_4EFE10(*(_DWORD*)(v1 + 276));
    if (sub_40A5C0(4096))
    {
        v4 = sub_419D40(&byte_587000[206600]);
        *(_DWORD*)(v1 + 320) = sub_419A70(v4);
    }
    return sub_4EF7D0(a1, 1, 0);
}

//----- (004EFF10) --------------------------------------------------------
int __cdecl sub_4EFF10(int a1)
{
    int v1; // edi
    unsigned __int16 v2; // ax
    int v3; // ecx
    unsigned int v4; // ecx
    int result; // eax

    v1 = *(_DWORD*)(a1 + 748);
    sub_4EFD80(*(_DWORD*)(v1 + 276));
    sub_4EFC80(*(_DWORD*)(v1 + 276));
    *(_BYTE*)(*(_DWORD*)(v1 + 276) + 3684) = 1;
    sub_4FC180(a1);
    sub_4EEDC0(a1, 0);
    sub_4EFE10(*(_DWORD*)(v1 + 276));
    v2 = *(_WORD*)(v1 + 8);
    v3 = *(_DWORD*)(v1 + 276);
    *(_WORD*)(v1 + 4) = v2;
    *(_WORD*)(v1 + 6) = v2;
    sub_56F870(*(_DWORD*)(v3 + 4596), v2);
    *(_DWORD*)(v1 + 192) = 0;
    *(_DWORD*)(v1 + 196) = 0;
    *(_DWORD*)(v1 + 200) = 0;
    *(_DWORD*)(v1 + 204) = 0;
    *(_DWORD*)(v1 + 208) = 0;
    *(_BYTE*)(v1 + 212) = 0;
    sub_4EE6F0(a1);
    v4 = *(_DWORD*)(a1 + 16) & 0xFFEB3FE7;
    *(_BYTE*)(a1 + 541) = 0;
    *(_DWORD*)(a1 + 16) = v4;
    sub_4FA020((_DWORD*)a1, 13);
    sub_4FF580(a1);
    sub_4FEAE0(a1);
    sub_4EE9D0(a1);
    sub_4F7950(a1);
    sub_4D85C0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), (_DWORD*)a1);
    sub_4D88C0(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), a1);
    *(_DWORD*)(a1 + 520) = 0;
    result = -559023410;
    *(_DWORD*)(*(_DWORD*)(v1 + 276) + 3664) = -559023410;
    *(_DWORD*)(*(_DWORD*)(v1 + 276) + 3660) = -559023410;
    return result;
}

//----- (004F0040) --------------------------------------------------------
int __cdecl sub_4F0040(int a1)
{
    int v1; // eax
    int v2; // edi
    int v3; // edx
    int* v4; // eax
    int v5; // eax
    int* v6; // eax
    int* v7; // eax
    int* v8; // eax
    int* v9; // eax
    _WORD* v10; // ecx
    int v11; // eax
    int v12; // ecx
    double v13; // st7
    int result; // eax

    v1 = *(_DWORD*)& byte_5D4594[1568272];
    v2 = *(_DWORD*)(a1 + 748);
    if (!*(_DWORD*)& byte_5D4594[1568272])
    {
        v1 = sub_4E3AA0((CHAR*)& byte_587000[206628]);
        *(_DWORD*)& byte_5D4594[1568272] = v1;
    }
    if (!(*(_DWORD*)(a1 + 16) & 0x8020))
    {
        if (*(unsigned __int16*)(a1 + 4) == v1)
        {
            sub_50A3A0(a1);
            v3 = *(_DWORD*)(v2 + 484);
            *(_DWORD*)(v2 + 1360) = 4;
            *(float*)(v2 + 1312) = *(float*)(v3 + 112) + *(float*)(a1 + 176) + 10.0;
            goto LABEL_15;
        }
        if (sub_534B60(a1))
        {
            sub_50A3A0(a1);
            sub_50A260(a1, 29);
            *(_DWORD*)(v2 + 1304) = 1042536202;
        }
        else if (sub_534B10(a1))
        {
            sub_50A3A0(a1);
            v4 = sub_50A260(a1, 10);
            if (v4)
            {
                v4[1] = 0;
                *((_BYTE*)v4 + 12) = -1;
            }
            *(_DWORD*)(v2 + 1304) = 1042536202;
        }
        else
        {
            if (!sub_534B90(a1))
                goto LABEL_15;
            sub_50A3A0(a1);
            sub_50A260(a1, 0);
            v5 = *(_DWORD*)(v2 + 1440);
            BYTE1(v5) |= 1u;
            *(_DWORD*)(v2 + 1304) = 1042536202;
            *(_DWORD*)(v2 + 1440) = v5;
        }
        *(_DWORD*)(v2 + 1360) = 38;
    }
    LABEL_15:
    switch (*(_DWORD*)(v2 + 1360))
    {
        case 3:
            v7 = sub_50A260(a1, 3);
            if (v7)
            {
                v7[1] = *(_DWORD*)(a1 + 56);
                v7[2] = *(_DWORD*)(a1 + 60);
                v7[3] = 0;
            }
            break;
        case 4:
            v9 = sub_50A260(a1, 4);
            if (v9)
            {
                v9[1] = *(_DWORD*)(a1 + 56);
                v9[2] = *(_DWORD*)(a1 + 60);
                v9[3] = *(__int16*)(a1 + 124);
            }
            break;
        case 0xA:
            if (sub_534390(a1))
            {
                sub_50A260(a1, 5);
            }
            else
            {
                v8 = sub_50A260(a1, 10);
                if (v8)
                {
                    v8[1] = 0;
                    *((_BYTE*)v8 + 12) = *(_BYTE*)(v2 + 1332);
                }
            }
            break;
        case 0xF:
            v6 = sub_50A260(a1, 15);
            if (v6)
            {
                v6[1] = *(_DWORD*)(a1 + 56);
                v6[2] = *(_DWORD*)(a1 + 60);
                v6[3] = *(_DWORD*)& byte_5D4594[2598000];
            }
            break;
        case 0x26:
            break;
        default:
            sub_50A260(a1, 0);
            break;
    }
    *(_DWORD*)(v2 + 1360) = 38;
    *(_DWORD*)(v2 + 376) = *(__int16*)(a1 + 124);
    *(_DWORD*)(v2 + 380) = *(_DWORD*)(a1 + 56);
    *(_DWORD*)(v2 + 384) = *(_DWORD*)(a1 + 60);
    v10 = *(_WORD * *)(a1 + 556);
    if (*v10 == v10[2])
        sub_4E4560(a1, (__int64)((double)(unsigned __int16)v10[2] * *(float*)(v2 + 1352)));
    *(_WORD*)(*(_DWORD*)(a1 + 556) + 2) = **(_WORD * *)(a1 + 556);
    v11 = v2 + 412;
    v12 = 32;
    do
    {
        v11 += 2;
        --v12;
        *(_WORD*)(v11 - 2) = **(_WORD * *)(a1 + 556);
    } while (v12);
    if (*(_BYTE*)(a1 + 12) & 0x30)
        v13 = *(float*)(v2 + 1328) * 0.5 + 1.7;
    else
        v13 = sub_416030(0.94999999, 1.05) * *(float*)(a1 + 548);
    *(float*)(a1 + 548) = v13;
    if (sub_534300(a1))
        * (_DWORD*)(v2 + 1356) = 1120403456;
    result = *(_DWORD*)(v2 + 1440);
    if (result & 0x40)
        * (_DWORD*)(v2 + 1356) = 0;
    if ((result & 0x8000) != 0)
    {
        BYTE1(result) |= 0x40u;
        *(_DWORD*)(v2 + 1440) = result;
    }
    return result;
}

//----- (004F0390) --------------------------------------------------------
_DWORD* __cdecl sub_4F0390(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)(a1 + 748);
    result[1] = 32;
    *result = 32;
    return result;
}

//----- (004F03B0) --------------------------------------------------------
int __cdecl sub_4F03B0(int a1)
{
    _BYTE* v1; // esi
    int result; // eax

    v1 = *(_BYTE * *)(a1 + 748);
    *v1 = sub_415FA0(55, 60);
    v1[1] = 1;
    v1[2] = 0;
    result = sub_415FA0(0, 255);
    *(_WORD*)(a1 + 126) = result;
    return result;
}

//----- (004F0400) --------------------------------------------------------
int* __cdecl sub_4F0400(int a1)
{
    int* result; // eax

    result = (int*)a1;
    if (!(*(_BYTE*)(a1 + 20) & 0xE))
        result = sub_4E4800(a1, (int*)2);
    return result;
}

//----- (004F0420) --------------------------------------------------------
_DWORD* __cdecl sub_4F0420(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // edx

    result = a1;
    v2 = a1[15];
    a1[39] = a1[14];
    a1[40] = v2;
    return result;
}

//----- (004F0450) --------------------------------------------------------
int __cdecl sub_4F0450(int a1)
{
    int v1; // edi
    __int16 v2; // ax
    int result; // eax

    v1 = *(_DWORD*)(a1 + 748);
    v2 = sub_509E00(*(_DWORD * *)(a1 + 692));
    *(_WORD*)(a1 + 126) = v2;
    *(_WORD*)(a1 + 124) = v2;
    result = sub_4E3AA0((CHAR*)(v1 + 16));
    *(_DWORD*)(v1 + 12) = result;
    return result;
}

//----- (004F0490) --------------------------------------------------------
int __cdecl sub_4F0490(int a1)
{
    int result; // eax

    result = sub_509E00(*(_DWORD * *)(a1 + 692));
    *(_WORD*)(a1 + 126) = result;
    *(_WORD*)(a1 + 124) = result;
    return result;
}

//----- (004F04B0) --------------------------------------------------------
int __cdecl sub_4F04B0(int a1)
{
    int result; // eax
    _DWORD* v2; // edi
    char* v3; // eax
    int v4; // esi
    int v5; // ecx
    int v6; // esi
    int v7; // [esp+4h] [ebp-4h]
    float v8; // [esp+Ch] [ebp+4h]
    float v9; // [esp+Ch] [ebp+4h]

    result = a1;
    v2 = *(_DWORD * *)(a1 + 692);
    if (!*v2)
    {
        v3 = sub_416EA0();
        v4 = 0;
        v7 = 0;
        v8 = 0.0;
        if (v3)
        {
            do
            {
                v5 = *((_DWORD*)v3 + 514);
                if (v5)
                    v8 = v8 + *(float*)(v5 + 28);
                v3 = sub_416EE0((int)v3);
                ++v4;
            } while (v3);
            v7 = v4;
        }
        v9 = v8 / (double)v7;
        v6 = sub_415FA0((__int64)(v9 * *(double*)& byte_581450[10256]), (__int64)(v9 * *(double*)& byte_581450[10264]))
             - (unsigned __int64)(__int64)(v9 * *(double*)& byte_581450[10248]);
        result = sub_415FA0(15, 30);
        *v2 = result + v6;
    }
    return result;
}

//----- (004F0570) --------------------------------------------------------
int* __cdecl sub_4F0570(int a1)
{
    int* result; // eax

    result = (int*)a1;
    if (!(*(_BYTE*)(a1 + 20) & 0xE))
        result = sub_4E4800(a1, (int*)2);
    return result;
}

//----- (004F0590) --------------------------------------------------------
int __cdecl sub_4F0590(int a1)
{
    int v1; // esi
    double v2; // st7
    int result; // eax

    v1 = *(_DWORD*)(a1 + 748);
    switch (*(unsigned __int8*)(sub_51A930() + v1 + 83))
    {
        case 0u:
            v2 = sub_419D40(&byte_587000[206868]);
            goto LABEL_6;
        case 1u:
            v2 = sub_419D40(&byte_587000[206900]);
            goto LABEL_6;
        case 2u:
            v2 = sub_419D40(&byte_587000[206936]);
            goto LABEL_6;
        case 3u:
            v2 = sub_419D40(&byte_587000[206968]);
        LABEL_6:
            *(_BYTE*)(v1 + 87) = (__int64)v2;
            break;
        default:
            break;
    }
    result = *(_DWORD*)(a1 + 12);
    if (result & 1)
    {
        result = sub_509E90(0);
        LABEL_15:
        *(_WORD*)(a1 + 124) = result;
        goto LABEL_16;
    }
    if (result & 2)
    {
        result = sub_509E90(2);
        goto LABEL_15;
    }
    if (result & 4)
    {
        result = sub_509E90(8);
        goto LABEL_15;
    }
    if (result & 8)
    {
        result = sub_509E90(6);
        goto LABEL_15;
    }
    LABEL_16:
    *(_WORD*)(a1 + 126) = *(_WORD*)(a1 + 124);
    return result;
}

//----- (004F0630) --------------------------------------------------------
void sub_4F0630()
{
    nox_srand(0x7DBu);
}

//----- (004F0640) --------------------------------------------------------
const char* sub_4F0640()
{
    char* v0; // eax
    unsigned __int8* v1; // esi
    char v2; // cl
    CHAR* v3; // eax
    const char* v4; // eax
    unsigned __int8* v5; // esi
    int v6; // eax
    const char* v7; // eax
    unsigned __int8* v8; // esi
    int v9; // eax
    const char* v10; // eax
    unsigned __int8* v11; // esi
    int v12; // eax
    const char* result; // eax
    unsigned __int8* v14; // esi
    int v15; // eax

    v0 = *(char**)& byte_587000[208180];
    if (*(_DWORD*)& byte_587000[208180])
    {
        v1 = &byte_587000[208180];
        do
        {
            v2 = *v0;
            v3 = *(CHAR * *)v1;
            if (v2 == 35)
                ++v3;
            *((_DWORD*)v1 + 1) = sub_4E3AA0(v3);
            v0 = (char*) * ((_DWORD*)v1 + 5);
            v1 += 20;
        } while (v0);
    }
    v4 = *(const char**)& byte_587000[210712];
    if (*(_DWORD*)& byte_587000[210712])
    {
        v5 = &byte_587000[210712];
        do
        {
            v6 = sub_413290(v4);
            *((_DWORD*)v5 - 1) = sub_413330(v6);
            v4 = (const char*) * ((_DWORD*)v5 + 6);
            v5 += 24;
        } while (v4);
    }
    v7 = *(const char**)& byte_587000[210856];
    if (*(_DWORD*)& byte_587000[210856])
    {
        v8 = &byte_587000[210856];
        do
        {
            v9 = sub_413290(v7);
            *((_DWORD*)v8 - 1) = sub_413330(v9);
            v7 = (const char*) * ((_DWORD*)v8 + 6);
            v8 += 24;
        } while (v7);
    }
    v10 = *(const char**)& byte_587000[211000];
    if (*(_DWORD*)& byte_587000[211000])
    {
        v11 = &byte_587000[211000];
        do
        {
            v12 = sub_413290(v10);
            *((_DWORD*)v11 - 1) = sub_413330(v12);
            v10 = (const char*) * ((_DWORD*)v11 + 6);
            v11 += 24;
        } while (v10);
    }
    result = *(const char**)& byte_587000[209344];
    if (*(_DWORD*)& byte_587000[209344])
    {
        v14 = &byte_587000[209344];
        do
        {
            v15 = sub_413290(result);
            *((_DWORD*)v14 - 1) = sub_413330(v15);
            result = (const char*) * ((_DWORD*)v14 + 6);
            v14 += 24;
        } while (result);
    }
    return result;
}

//----- (004F0720) --------------------------------------------------------
_DWORD* __cdecl sub_4F0720(int a1, unsigned int a2)
{
    int v2; // eax
    int v3; // ebx
    int* v4; // ebp
    _DWORD* result; // eax
    int v6; // esi
    char v7; // cl
    unsigned __int8* v8; // eax
    unsigned int v9; // eax
    int v10; // ebp
    unsigned int v11; // edi
    char v12; // cl
    unsigned __int8* v13; // esi
    unsigned int v14; // edx

    v2 = *(_DWORD*)& byte_5D4594[1568276];
    v3 = a1;
    v4 = *(int**)(a1 + 692);
    if (!*(_DWORD*)& byte_5D4594[1568276])
    {
        v2 = sub_4E3AA0((CHAR*)& byte_587000[212928]);
        *(_DWORD*)& byte_5D4594[1568276] = v2;
    }
    if (*(unsigned __int16*)(a1 + 4) == v2)
        a2 += 2;
    switch (v4[53])
    {
        case 1:
            if (sub_415FA0(0, 100) <= 75)
                goto LABEL_14;
            result = 0;
            break;
        case 2:
            if (sub_415FA0(0, 100) <= 50)
                goto LABEL_14;
            result = 0;
            break;
        case 3:
            if (sub_415FA0(0, 100) <= 25)
                goto LABEL_14;
            result = 0;
            break;
        case 4:
            if (sub_415FA0(0, 100) <= 5)
                goto LABEL_14;
            result = 0;
            break;
        default:
        LABEL_14:
            v6 = 0;
            v7 = 0;
            v8 = &byte_587000[207044];
            do
            {
                if ((1 << v7) & *v4)
                    v6 += *v8;
                v8 += 8;
                ++v7;
            } while ((int)v8 < (int)& byte_587000[207108]);
            if (v6)
            {
                v9 = sub_415FA0(1, v6);
                v10 = *v4;
                v11 = 0;
                v12 = 0;
                v13 = &byte_587000[207044];
                while (1)
                {
                    v14 = 1 << v12;
                    if (v10 & (1 << v12))
                    {
                        v11 += *v13;
                        v3 = a1;
                        if (v11 >= v9)
                            break;
                    }
                    v13 += 8;
                    ++v12;
                    if ((int)v13 >= (int)& byte_587000[207108])
                    {
                        v14 = a2;
                        break;
                    }
                }
                switch (v14)
                {
                    case 1u:
                        result = sub_4F09F0(v3, a2);
                        break;
                    case 2u:
                        result = sub_4F0C70(v3);
                        break;
                    case 4u:
                        result = sub_4F0D20(v3, a2);
                        break;
                    case 8u:
                        result = (_DWORD*)sub_4F14E0(v3, a2);
                        break;
                    case 0x10u:
                        result = sub_4F0E80(v3, a2);
                        break;
                    case 0x20u:
                        result = sub_4F1D30(v3, a2);
                        break;
                    case 0x40u:
                        result = sub_4F1C40(v3, a2);
                        break;
                    case 0x80u:
                        result = sub_4F1F00(v3, a2);
                        break;
                    default:
                        result = sub_4F1D30(v3, a2);
                        break;
                }
            }
            else
            {
                result = 0;
            }
            break;
    }
    return result;
}

//----- (004F09F0) --------------------------------------------------------
_DWORD* __cdecl sub_4F09F0(int a1, unsigned int a2)
{
    int v2; // esi
    int v3; // ecx
    int i; // eax
    int v5; // eax
    int v6; // edx
    int v7; // ecx
    _DWORD* result; // eax
    int v9; // ebx
    int v10; // ebp
    int v11; // ecx
    unsigned __int8* v12; // eax
    int v13; // edx
    int v14; // edi
    int v15; // esi
    int v16; // edx
    unsigned __int8* j; // ecx
    int v18; // eax

    v2 = *(_DWORD*)(a1 + 692);
    if (*(_BYTE*)(v2 + 4) & 1)
    {
        v3 = 0;
        for (i = 0; i < 137; ++i)
        {
            if (*(_BYTE*)(v2 + i + 8) == 1)
                ++v3;
        }
        if (v3)
        {
            v5 = sub_415FA0(0, v3 - 1);
            v6 = 0;
            v7 = 0;
            while (1)
            {
                if (*(_BYTE*)(v2 + v7 + 8) == 1)
                {
                    if (v6 == v5)
                    {
                        v9 = v7;
                        goto LABEL_27;
                    }
                    ++v6;
                }
                if (++v7 >= 137)
                    return 0;
            }
        }
        return 0;
    }
    v10 = sub_4F0B60(a2);
    v11 = 0;
    if (!*(_DWORD*)& byte_587000[207108])
        return 0;
    v12 = &byte_587000[207104];
    do
    {
        if (v10 & *((_DWORD*)v12 + 2))
            v11 += *v12;
        v13 = *((_DWORD*)v12 + 4);
        v12 += 12;
    } while (v13);
    if (!v11)
        return 0;
    v14 = sub_415FA0(0, v11 - 1);
    v15 = 0;
    v16 = 0;
    if (!*(_DWORD*)& byte_587000[207108])
        return 0;
    for (j = &byte_587000[207104]; ; j += 12)
    {
        if (v10 & *((_DWORD*)j + 2))
        {
            v15 += *j;
            if (v14 < v15)
                break;
        }
        v18 = *((_DWORD*)j + 4);
        ++v16;
        if (!v18)
            return 0;
    }
    v9 = *(_DWORD*)& byte_587000[12 * v16 + 207108];
    LABEL_27:
    if (!v9)
        return 0;
    if (sub_57AEA0(1, v9) || sub_57AEA0(2, v9))
    {
        if (sub_57AEA0(1, v9))
        {
            if (sub_57AEA0(2, v9))
                return 0;
            result = sub_4E3810((CHAR*)& byte_587000[213260]);
        }
        else
        {
            result = sub_4E3810((CHAR*)& byte_587000[213244]);
        }
    }
    else
    {
        result = sub_4E3810((CHAR*)& byte_587000[213228]);
    }
    if (!result)
        return 0;
    *(_BYTE*)result[184] = v9;
    return result;
}

//----- (004F0B60) --------------------------------------------------------
int __cdecl sub_4F0B60(unsigned int a1)
{
    unsigned int v2; // eax
    float* v3; // eax
    int v4; // eax
    int v5; // ecx
    float* v6; // edx
    double v7; // st7
    int v8; // [esp+0h] [ebp-18h]
    float v9[5]; // [esp+4h] [ebp-14h]
    float v10; // [esp+1Ch] [ebp+4h]

    v9[0] = 0.0;
    v9[1] = 0.0;
    v9[2] = 0.0;
    v9[3] = 0.0;
    v9[4] = 0.0;
    if (a1 > 0xA)
        return 16;
    switch (a1)
    {
        case 0u:
            return 1;
        case 1u:
            v9[0] = 87.5;
            v9[1] = 12.5;
            goto LABEL_12;
        case 9u:
            v9[3] = 12.5;
            v9[4] = 87.5;
            goto LABEL_12;
        case 0xAu:
            return 16;
    }
    if (a1 & 1)
    {
        v2 = a1 >> 1;
        v9[v2] = 75.0;
        *(int*)((char*)& v8 + v2 * 4) = 1095237632;
        v9[v2 + 1] = 12.5;
    }
    else
    {
        v3 = &v9[a1 >> 1];
        *(v3 - 1) = 50.0;
        *v3 = 50.0;
    }
    LABEL_12:
    v8 = 545;
    v4 = sub_415FA0(0, 200);
    v5 = 0;
    v6 = v9;
    v7 = 0.0;
    while (1)
    {
        v7 = v7 + *v6;
        v10 = (double)v4 * 0.5;
        if (v10 <= v7)
            break;
        ++v5;
        ++v6;
        if (v5 >= 5)
            return 1;
    }
    return 1 << v5;
}

//----- (004F0C70) --------------------------------------------------------
_DWORD* __cdecl sub_4F0C70(int a1)
{
    int v1; // esi
    int v2; // ecx
    int i; // eax
    _DWORD* result; // eax
    int v5; // eax
    int v6; // edx
    int v7; // ecx
    int v8; // ebx

    v1 = *(_DWORD*)(a1 + 692);
    if (!(*(_BYTE*)(v1 + 4) & 2))
    {
        v8 = sub_415FA0(1, 5);
        goto LABEL_16;
    }
    v2 = 0;
    for (i = 0; i < 6; ++i)
    {
        if (*(_BYTE*)(v1 + i + 145) == 1)
            ++v2;
    }
    if (!v2)
        return 0;
    v5 = sub_415FA0(0, v2 - 1);
    v6 = 0;
    v7 = 0;
    while (*(_BYTE*)(v1 + v7 + 145) != 1)
    {
        LABEL_12:
        if (++v7 >= 6)
            return 0;
    }
    if (v6 != v5)
    {
        ++v6;
        goto LABEL_12;
    }
    v8 = v7;
    LABEL_16:
    if (!v8)
        return 0;
    result = sub_4E3810((CHAR*)& byte_587000[213400]);
    if (result)
        * (_BYTE*)result[184] = v8;
    return result;
}

//----- (004F0D20) --------------------------------------------------------
_DWORD* __cdecl sub_4F0D20(int a1, unsigned int a2)
{
    int v2; // esi
    int v3; // ecx
    int i; // eax
    _DWORD* result; // eax
    int v6; // eax
    int v7; // edx
    int v8; // ecx
    int v9; // esi
    int v10; // ebp
    int v11; // ecx
    unsigned __int8* v12; // eax
    int v13; // edx
    int v14; // edi
    int v15; // esi
    int v16; // edx
    unsigned __int8* j; // ecx
    int v18; // eax
    _DWORD* v19; // ebx
    char* v20; // ebp
    char* v21; // edi

    v2 = *(_DWORD*)(a1 + 692);
    if (*(_BYTE*)(v2 + 4) & 4)
    {
        v3 = 0;
        for (i = 0; i < 41; ++i)
        {
            if (*(_BYTE*)(v2 + i + 151) == 1)
                ++v3;
        }
        if (v3)
        {
            v6 = sub_415FA0(0, v3 - 1);
            v7 = 0;
            v8 = 0;
            while (1)
            {
                if (*(_BYTE*)(v2 + v8 + 151) == 1)
                {
                    if (v7 == v6)
                    {
                        v9 = v8;
                        goto LABEL_29;
                    }
                    ++v7;
                }
                if (++v8 >= 41)
                    return 0;
            }
        }
        result = 0;
    }
    else
    {
        v10 = sub_4F0B60(a2);
        v11 = 0;
        if (!*(_DWORD*)& byte_587000[207796])
            goto LABEL_35;
        v12 = &byte_587000[207792];
        do
        {
            if (v10 & *((_DWORD*)v12 + 2))
                v11 += *v12;
            v13 = *((_DWORD*)v12 + 4);
            v12 += 12;
        } while (v13);
        if (v11)
        {
            v14 = sub_415FA0(0, v11 - 1);
            v15 = 0;
            v16 = 0;
            if (!*(_DWORD*)& byte_587000[207796])
                goto LABEL_36;
            for (j = &byte_587000[207792]; ; j += 12)
            {
                if (v10 & *((_DWORD*)j + 2))
                {
                    v15 += *j;
                    if (v14 < v15)
                        break;
                }
                v18 = *((_DWORD*)j + 4);
                ++v16;
                if (!v18)
                    return 0;
            }
            v9 = *(_DWORD*)& byte_587000[12 * v16 + 207796];
            LABEL_29:
            if (v9)
            {
                result = sub_4E3810((CHAR*)& byte_587000[213492]);
                v19 = result;
                if (result)
                {
                    v20 = (char*)result[184];
                    v21 = sub_427230(v9);
                    result = v19;
                    strcpy(v20, v21);
                }
            }
            else
            {
                LABEL_36:
                result = 0;
            }
        }
        else
        {
            LABEL_35:
            result = 0;
        }
    }
    return result;
}

//----- (004F0E80) --------------------------------------------------------
_DWORD* __cdecl sub_4F0E80(int a1, unsigned int a2)
{
    int v2; // ebx
    int v3; // edi
    unsigned __int8* v4; // esi
    int v5; // eax
    int v7; // ebx
    int v8; // ebp
    int v9; // edi
    unsigned __int8* i; // esi
    int v11; // eax
    int v12; // esi
    int v13; // ebp
    _DWORD* v14; // edi
    int v15; // eax
    int v16; // eax
    __int16 v17; // bx
    int v18; // eax
    int v19; // ecx
    unsigned __int8* v20; // eax
    int v21; // edx
    int v22; // ecx
    unsigned __int8* v23; // eax
    int v24; // edx
    int v25; // edx
    unsigned __int8* v26; // eax
    int v27; // ecx
    int v28; // ecx
    unsigned __int8* v29; // eax
    int v30; // edx
    int v31; // eax
    int v32; // esi
    int v33; // edx
    unsigned __int8* v34; // ecx
    int v35; // edi
    int v36; // ecx
    unsigned __int8* v37; // eax
    int v38; // esi
    int v39; // eax
    int v40; // esi
    int v41; // edx
    unsigned __int8* v42; // ecx
    int v43; // edi
    int v44; // edx
    unsigned __int8* v45; // eax
    int v46; // ecx
    int v47; // eax
    int v48; // edi
    int v49; // esi
    unsigned __int8* v50; // ecx
    int v51; // edx
    signed int v52; // eax
    int v53; // ecx
    int v54; // eax
    int v55; // ebx
    int v56; // edx
    unsigned __int8* v57; // eax
    int v58; // ecx
    int v59; // eax
    int v60; // edi
    int v61; // esi
    unsigned __int8* v62; // ecx
    int v63; // edx
    int v64; // [esp+10h] [ebp-20h]
    int v65; // [esp+14h] [ebp-1Ch]
    int v66; // [esp+18h] [ebp-18h]
    unsigned __int8 v67[20]; // [esp+1Ch] [ebp-14h]

    v65 = 0;
    v2 = sub_4F0B60(a2);
    v3 = 0;
    v64 = v2;
    if (!*(_DWORD*)& byte_587000[208180])
        return 0;
    v4 = &byte_587000[208192];
    do
    {
        if (*(v4 - 4) & 2 && v2 & *(_DWORD*)v4 && sub_4E3BA0(*((_DWORD*)v4 - 2)))
            v3 += *(v4 - 16);
        v5 = *((_DWORD*)v4 + 2);
        v4 += 20;
    } while (v5);
    if (!v3)
        return 0;
    v7 = sub_415FA0(0, v3 - 1);
    v8 = 0;
    v9 = 0;
    if (!*(_DWORD*)& byte_587000[208180])
        return 0;
    for (i = &byte_587000[208192]; ; i += 20)
    {
        if (*(i - 4) & 2)
        {
            if (v64 & *(_DWORD*)i)
            {
                if (sub_4E3BA0(*((_DWORD*)i - 2)))
                {
                    v8 += *(i - 16);
                    if (v7 < v8)
                        break;
                }
            }
        }
        v11 = *((_DWORD*)i + 2);
        ++v9;
        if (!v11)
            return 0;
    }
    v12 = *(_DWORD*)& byte_587000[20 * v9 + 208184];
    if (!v12)
        return 0;
    v13 = sub_415D10(*(char**)& byte_587000[20 * v9 + 208184]);
    v14 = sub_4E3450(v12);
    v66 = (int)v14;
    if (!v14)
        return 0;
    switch (v64)
    {
        case 2:
            v15 = sub_415FA0(0, 1);
            goto LABEL_27;
        case 4:
            v15 = sub_415FA0(0, 2);
            goto LABEL_27;
        case 8:
            v15 = sub_415FA0(1, 3);
            goto LABEL_27;
        case 16:
            v15 = sub_415FA0(2, 4);
        LABEL_27:
            if (!v15)
                return v14;
            *(_DWORD*)v67 = 0;
            *(_DWORD*)& v67[4] = 0;
            *(_DWORD*)& v67[8] = 0;
            *(_DWORD*)& v67[12] = 0;
            *(_WORD*)& v67[16] = 0;
            *(_WORD*)& v67[18] = 0;
            switch (v15)
            {
                case 1:
                    v16 = sub_415FA0(1, 100);
                    if (v16 > 20)
                        v17 = (v16 > 50) + 1;
                    else
                        v17 = 4;
                    break;
                case 2:
                    v18 = sub_415FA0(1, 100);
                    if (v18 > 12)
                        v17 = v18 > 25 ? 3 : 6;
                    else
                        v17 = 5;
                    break;
                case 3:
                    v17 = 7;
                    break;
                default:
                    v17 = 15;
                    if (v15 != 4)
                        v17 = a2;
                    break;
            }
            if (v17 & 1)
            {
                v19 = 0;
                if (!*(_DWORD*)& byte_587000[210856])
                    goto LABEL_178;
                v20 = &byte_587000[210852];
                do
                {
                    if (v64 & *((_DWORD*)v20 + 2) && v13 & *(_DWORD*)(*(_DWORD*)v20 + 32) && !(v13 & *((_DWORD*)v20 + 3)))
                        ++v19;
                    v21 = *((_DWORD*)v20 + 7);
                    v20 += 24;
                } while (v21);
                if (!v19)
                {
                    LABEL_178:
                    if (v17 & 2)
                    {
                        if (v17 & 4)
                        {
                            if (!(v17 & 8))
                                v17 |= 8u;
                        }
                        else
                        {
                            v17 |= 4u;
                        }
                    }
                    else
                    {
                        v17 |= 2u;
                    }
                    v17 &= 0xFFFEu;
                }
            }
            if (v17 & 2)
            {
                v22 = 0;
                if (!*(_DWORD*)& byte_587000[211000])
                    goto LABEL_179;
                v23 = &byte_587000[210996];
                do
                {
                    if (v64 & *((_DWORD*)v23 + 2) && v13 & *(_DWORD*)(*(_DWORD*)v23 + 32) && !(v13 & *((_DWORD*)v23 + 3)))
                        ++v22;
                    v24 = *((_DWORD*)v23 + 7);
                    v23 += 24;
                } while (v24);
                if (!v22)
                {
                    LABEL_179:
                    if (v17 & 4)
                    {
                        if (!(v17 & 8))
                            v17 |= 8u;
                    }
                    else
                    {
                        v17 |= 4u;
                    }
                    v17 &= 0xFFFDu;
                }
            }
            if (v17 & 4)
            {
                v25 = 0;
                if (!*(_DWORD*)& byte_587000[209344])
                    goto LABEL_180;
                v26 = &byte_587000[209340];
                do
                {
                    if (v64 & *((_DWORD*)v26 + 2)
                        && v13 & *(_DWORD*)(*(_DWORD*)v26 + 32)
                        && !(v13 & *((_DWORD*)v26 + 3))
                        && *(_BYTE*)(*(_DWORD*)v26 + 36) & 1)
                    {
                        ++v25;
                    }
                    v27 = *((_DWORD*)v26 + 7);
                    v26 += 24;
                } while (v27);
                if (!v25)
                    LABEL_180:
                    v17 &= 0xFFF3u;
            }
            if (!v17)
                return v14;
            if (!(v17 & 1))
                goto LABEL_103;
            v28 = 0;
            if (!*(_DWORD*)& byte_587000[210856])
                goto LABEL_103;
            v29 = &byte_587000[210852];
            do
            {
                if (*((_DWORD*)v29 + 2) & v64 && v13 & *(_DWORD*)(*(_DWORD*)v29 + 32) && !(v13 & *((_DWORD*)v29 + 3)))
                    ++v28;
                v30 = *((_DWORD*)v29 + 7);
                v29 += 24;
            } while (v30);
            if (!v28)
                goto LABEL_103;
            v31 = sub_415FA0(0, v28 - 1);
            v32 = 0;
            v33 = 0;
            if (!*(_DWORD*)& byte_587000[210856])
                goto LABEL_103;
            v34 = &byte_587000[210852];
            break;
        default:
            return v14;
    }
    while (1)
    {
        if (!(v64 & *((_DWORD*)v34 + 2)) || !(v13 & *(_DWORD*)(*(_DWORD*)v34 + 32)) || v13 & *((_DWORD*)v34 + 3))
            goto LABEL_100;
        if (v32 == v31)
            break;
        ++v32;
        LABEL_100:
        v35 = *((_DWORD*)v34 + 7);
        v34 += 24;
        ++v33;
        if (!v35)
            goto LABEL_103;
    }
    *(_DWORD*)v67 = *(_DWORD*)& byte_587000[24 * v33 + 210852];
    LABEL_103:
    if (v17 & 2)
    {
        v36 = 0;
        if (*(_DWORD*)& byte_587000[211000])
        {
            v37 = &byte_587000[210996];
            do
            {
                if (v64 & *((_DWORD*)v37 + 2) && v13 & *(_DWORD*)(*(_DWORD*)v37 + 32) && !(v13 & *((_DWORD*)v37 + 3)))
                    ++v36;
                v38 = *((_DWORD*)v37 + 7);
                v37 += 24;
            } while (v38);
            if (v36)
            {
                v39 = sub_415FA0(0, v36 - 1);
                v40 = 0;
                v41 = 0;
                if (*(_DWORD*)& byte_587000[211000])
                {
                    v42 = &byte_587000[210996];
                    do
                    {
                        if (v64 & *((_DWORD*)v42 + 2) && v13 & *(_DWORD*)(*(_DWORD*)v42 + 32) && !(v13 & *((_DWORD*)v42 + 3)))
                        {
                            if (v40 == v39)
                            {
                                *(_DWORD*)& v67[4] = *(_DWORD*)& byte_587000[24 * v41 + 210996];
                                break;
                            }
                            ++v40;
                        }
                        v43 = *((_DWORD*)v42 + 7);
                        v42 += 24;
                        ++v41;
                    } while (v43);
                }
            }
        }
    }
    if (v17 & 4)
    {
        v44 = 0;
        if (*(_DWORD*)& byte_587000[209344])
        {
            v45 = &byte_587000[209340];
            do
            {
                if (v64 & *((_DWORD*)v45 + 2)
                    && v13 & *(_DWORD*)(*(_DWORD*)v45 + 32)
                    && !(v13 & *((_DWORD*)v45 + 3))
                    && *(_BYTE*)(*(_DWORD*)v45 + 36) & 1)
                {
                    ++v44;
                }
                v46 = *((_DWORD*)v45 + 7);
                v45 += 24;
            } while (v46);
            if (v44)
            {
                v47 = sub_415FA0(0, v44 - 1);
                v48 = 0;
                v49 = 0;
                if (*(_DWORD*)& byte_587000[209344])
                {
                    v50 = &byte_587000[209340];
                    do
                    {
                        if (v64 & *((_DWORD*)v50 + 2)
                            && v13 & *(_DWORD*)(*(_DWORD*)v50 + 32)
                            && !(v13 & *((_DWORD*)v50 + 3))
                            && *(_BYTE*)(*(_DWORD*)v50 + 36) & 1)
                        {
                            if (v48 == v47)
                            {
                                v65 = v49;
                                *(_DWORD*)& v67[8] = *(_DWORD*)& byte_587000[24 * v49 + 209340];
                                break;
                            }
                            ++v48;
                        }
                        v51 = *((_DWORD*)v50 + 7);
                        v50 += 24;
                        ++v49;
                    } while (v51);
                }
            }
        }
    }
    if (v17 & 8)
    {
        v52 = a2 >> 1;
        if ((int)(a2 >> 1) >= 1)
        {
            if (v52 >= 5)
                v52 = 4;
        }
        else
        {
            v52 = 1;
        }
        v53 = v52 - 1;
        v54 = v52 + 1;
        if (v53 < 1)
            v53 = 1;
        if (v54 >= 5)
            v54 = 4;
        v55 = sub_415FA0(v53, v54);
        v56 = 0;
        if (*(_DWORD*)& byte_587000[209344])
        {
            v57 = &byte_587000[209340];
            do
            {
                if (v55 & *((_DWORD*)v57 + 2)
                    && v13 & *(_DWORD*)(*(_DWORD*)v57 + 32)
                    && !(v13 & *((_DWORD*)v57 + 3))
                    && *(_BYTE*)(*(_DWORD*)v57 + 36) & 2)
                {
                    ++v56;
                }
                v58 = *((_DWORD*)v57 + 7);
                v57 += 24;
            } while (v58);
            if (v56)
            {
                v59 = sub_415FA0(0, v56 - 1);
                v60 = 0;
                v61 = 0;
                if (*(_DWORD*)& byte_587000[209344])
                {
                    v62 = &byte_587000[209340];
                    do
                    {
                        if (v55 & *((_DWORD*)v62 + 2)
                            && v13 & *(_DWORD*)(*(_DWORD*)v62 + 32)
                            && !(v13 & *((_DWORD*)v62 + 3))
                            && *(_BYTE*)(*(_DWORD*)v62 + 36) & 2)
                        {
                            if (v60 == v59)
                            {
                                if (byte_587000[24 * v65 + 209336] != byte_587000[24 * v61 + 209336])
                                    * (_DWORD*)& v67[12] = *(_DWORD*)& byte_587000[24 * v61 + 209340];
                                break;
                            }
                            ++v60;
                        }
                        v63 = *((_DWORD*)v62 + 7);
                        v62 += 24;
                        ++v61;
                    } while (v63);
                }
            }
        }
    }
    sub_4E4990(v66, (int*)v67);
    return (_DWORD*)v66;
}

//----- (004F14E0) --------------------------------------------------------
int __cdecl sub_4F14E0(int a1, unsigned int a2)
{
    int v2; // ebx
    int v3; // edi
    unsigned __int8* v4; // esi
    int v5; // eax
    int v7; // ebx
    int v8; // edi
    int v9; // ebp
    unsigned __int8* v10; // esi
    int v11; // eax
    char* v12; // esi
    _DWORD* v13; // eax
    int v14; // edi
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // eax
    __int16 v19; // bx
    int v20; // eax
    int v21; // ecx
    int v22; // ebp
    unsigned __int8* v23; // eax
    int v24; // edx
    int v25; // ecx
    unsigned __int8* v26; // eax
    int v27; // edx
    int v28; // edx
    unsigned __int8* v29; // eax
    int v30; // ecx
    int v31; // ecx
    unsigned __int8* v32; // eax
    int v33; // edx
    int v34; // eax
    int v35; // esi
    int v36; // edx
    unsigned __int8* v37; // ecx
    int v38; // edi
    int v39; // ecx
    unsigned __int8* v40; // eax
    int v41; // esi
    int v42; // eax
    int v43; // esi
    int v44; // edx
    unsigned __int8* v45; // ecx
    int v46; // edi
    signed int v47; // eax
    int v48; // ecx
    int v49; // eax
    int v50; // ebp
    int v51; // edx
    unsigned __int8* v52; // eax
    int v53; // ecx
    int v54; // eax
    int v55; // edi
    int v56; // esi
    unsigned __int8* v57; // ecx
    int v58; // edx
    signed int v59; // eax
    int v60; // ecx
    int v61; // eax
    int v62; // ebp
    int v63; // edx
    unsigned __int8* v64; // eax
    int v65; // ecx
    int v66; // eax
    int v67; // edi
    int v68; // esi
    unsigned __int8* v69; // ecx
    int v70; // edx
    __int16 v71; // [esp+10h] [ebp-28h]
    int v72; // [esp+14h] [ebp-24h]
    int v73; // [esp+18h] [ebp-20h]
    int v74; // [esp+1Ch] [ebp-1Ch]
    int v75; // [esp+20h] [ebp-18h]
    unsigned __int8 v76[20]; // [esp+24h] [ebp-14h]

    v74 = 0;
    v2 = sub_4F0B60(a2);
    v3 = 0;
    v72 = v2;
    if (!*(_DWORD*)& byte_587000[208180])
        return 0;
    v4 = &byte_587000[208192];
    do
    {
        if (*(v4 - 4) & 1 && v2 & *(_DWORD*)v4 && sub_4E3BA0(*((_DWORD*)v4 - 2)))
            v3 += *(v4 - 16);
        v5 = *((_DWORD*)v4 + 2);
        v4 += 20;
    } while (v5);
    if (!v3)
        return 0;
    v7 = sub_415FA0(0, v3 - 1);
    v8 = 0;
    v9 = 0;
    if (*(_DWORD*)& byte_587000[208180])
    {
        v10 = &byte_587000[208192];
        while (1)
        {
            if (*(v10 - 4) & 1)
            {
                if (v72 & *(_DWORD*)v10)
                {
                    if (sub_4E3BA0(*((_DWORD*)v10 - 2)))
                    {
                        v8 += *(v10 - 16);
                        if (v7 < v8)
                            break;
                    }
                }
            }
            v11 = *((_DWORD*)v10 + 2);
            v10 += 20;
            ++v9;
            if (!v11)
                goto LABEL_17;
        }
        v12 = *(char**)& byte_587000[20 * v9 + 208184];
    }
    else
    {
        LABEL_17:
        v12 = (char*)a2;
    }
    if (!v12)
        return 0;
    v73 = sub_415880(v12);
    v13 = sub_4E3450((int)v12);
    v14 = (int)v13;
    v75 = (int)v13;
    if (!v13)
        return 0;
    v15 = v13[2];
    if (v15 & 0x1000 && *(_DWORD*)(v14 + 12) & 0x47F0000)
    {
        if (**(_BYTE * *)& byte_587000[20 * v9 + 208180] == 35)
        {
            *(_DWORD*)v76 = 0;
            *(_DWORD*)& v76[4] = 0;
            v16 = sub_413290("Replenishment1");
            *(_DWORD*)& v76[8] = sub_413330(v16);
            *(_DWORD*)& v76[12] = 0;
            *(_WORD*)& v76[16] = 0;
            *(_WORD*)& v76[18] = 0;
            sub_4E4990(v14, (int*)v76);
        }
        return v14;
    }
    switch (v72)
    {
        case 2:
            v17 = sub_415FA0(0, 1);
            goto LABEL_33;
        case 4:
            v17 = sub_415FA0(0, 2);
            goto LABEL_33;
        case 8:
            v17 = sub_415FA0(1, 3);
            goto LABEL_33;
        case 16:
            v17 = sub_415FA0(2, 4);
        LABEL_33:
            if (!v17)
                return v14;
            *(_DWORD*)v76 = 0;
            *(_DWORD*)& v76[4] = 0;
            *(_DWORD*)& v76[8] = 0;
            *(_DWORD*)& v76[12] = 0;
            *(_WORD*)& v76[16] = 0;
            *(_WORD*)& v76[18] = 0;
            switch (v17)
            {
                case 1:
                    v18 = sub_415FA0(1, 100);
                    if (v18 > 20)
                    {
                        v19 = (v18 > 50) + 1;
                        LOBYTE(v71) = (v18 > 50) + 1;
                    }
                    else
                    {
                        v19 = 4;
                        LOBYTE(v71) = 4;
                    }
                    break;
                case 2:
                    v20 = sub_415FA0(1, 100);
                    if (v20 > 12)
                    {
                        v19 = v20 > 25 ? 3 : 6;
                        LOBYTE(v71) = v20 > 25 ? 3 : 6;
                    }
                    else
                    {
                        v19 = 5;
                        LOBYTE(v71) = 5;
                    }
                    break;
                case 3:
                    v19 = 7;
                    LOBYTE(v71) = 7;
                    break;
                case 4:
                    v19 = 15;
                    LOBYTE(v71) = 15;
                    break;
                default:
                    v19 = v71;
                    break;
            }
            if (!(v19 & 1))
            {
                v22 = v73;
                goto LABEL_67;
            }
            v21 = 0;
            if (!*(_DWORD*)& byte_587000[210712])
            {
                v22 = v73;
                LABEL_59:
                if (v19 & 2)
                {
                    if (v19 & 4)
                    {
                        if (!(v19 & 8))
                            v19 |= 8u;
                        v19 &= 0xFFFEu;
                        LOBYTE(v71) = v19;
                    }
                    else
                    {
                        v19 = (v19 | 4) & 0xFFFE;
                        LOBYTE(v71) = v19;
                    }
                }
                else
                {
                    v19 = (v19 | 2) & 0xFFFE;
                    LOBYTE(v71) = v19;
                }
                goto LABEL_67;
            }
            v22 = v73;
            v23 = &byte_587000[210708];
            do
            {
                if (v72 & *((_DWORD*)v23 + 2) && v73 & *(_DWORD*)(*(_DWORD*)v23 + 28) && !(v73 & *((_DWORD*)v23 + 4)))
                    ++v21;
                v24 = *((_DWORD*)v23 + 7);
                v23 += 24;
            } while (v24);
            if (!v21)
                goto LABEL_59;
        LABEL_67:
            if (v19 & 2)
            {
                v25 = 0;
                if (!*(_DWORD*)& byte_587000[211000])
                    goto LABEL_196;
                v26 = &byte_587000[210996];
                do
                {
                    if (v72 & *((_DWORD*)v26 + 2) && v22 & *(_DWORD*)(*(_DWORD*)v26 + 28) && !(v22 & *((_DWORD*)v26 + 4)))
                        ++v25;
                    v27 = *((_DWORD*)v26 + 7);
                    v26 += 24;
                } while (v27);
                if (!v25)
                {
                    LABEL_196:
                    if (v19 & 4)
                    {
                        if (!(v19 & 8))
                            v19 |= 8u;
                    }
                    else
                    {
                        v19 |= 4u;
                    }
                    v19 &= 0xFFFDu;
                    LOBYTE(v71) = v19;
                }
            }
            if (v19 & 4)
            {
                v28 = 0;
                if (!*(_DWORD*)& byte_587000[209344])
                    goto LABEL_197;
                v29 = &byte_587000[209340];
                do
                {
                    if (v72 & *((_DWORD*)v29 + 2)
                        && v22 & *(_DWORD*)(*(_DWORD*)v29 + 28)
                        && !(v22 & *((_DWORD*)v29 + 4))
                        && *(_BYTE*)(*(_DWORD*)v29 + 36) & 1)
                    {
                        ++v28;
                    }
                    v30 = *((_DWORD*)v29 + 7);
                    v29 += 24;
                } while (v30);
                if (!v28)
                {
                    LABEL_197:
                    v19 &= 0xFFF3u;
                    LOBYTE(v71) = v19;
                }
            }
            if (!v19)
                return v14;
            if (v19 & 1)
            {
                v31 = 0;
                if (*(_DWORD*)& byte_587000[210712])
                {
                    v32 = &byte_587000[210708];
                    do
                    {
                        if (*((_DWORD*)v32 + 2) & v72 && v22 & *(_DWORD*)(*(_DWORD*)v32 + 28) && !(v22 & *((_DWORD*)v32 + 4)))
                            ++v31;
                        v33 = *((_DWORD*)v32 + 7);
                        v32 += 24;
                    } while (v33);
                    if (v31)
                    {
                        v34 = sub_415FA0(0, v31 - 1);
                        v35 = 0;
                        v36 = 0;
                        if (*(_DWORD*)& byte_587000[210712])
                        {
                            v37 = &byte_587000[210708];
                            do
                            {
                                if (v72 & *((_DWORD*)v37 + 2)
                                    && v22 & *(_DWORD*)(*(_DWORD*)v37 + 28)
                                    && !(v22 & *((_DWORD*)v37 + 4)))
                                {
                                    if (v35 == v34)
                                    {
                                        *(_DWORD*)v76 = *(_DWORD*)& byte_587000[24 * v36 + 210708];
                                        break;
                                    }
                                    ++v35;
                                }
                                v38 = *((_DWORD*)v37 + 7);
                                v37 += 24;
                                ++v36;
                            } while (v38);
                        }
                    }
                }
            }
            if (v19 & 2)
            {
                v39 = 0;
                if (*(_DWORD*)& byte_587000[211000])
                {
                    v40 = &byte_587000[210996];
                    do
                    {
                        if (v72 & *((_DWORD*)v40 + 2) && v22 & *(_DWORD*)(*(_DWORD*)v40 + 28) && !(v22 & *((_DWORD*)v40 + 4)))
                            ++v39;
                        v41 = *((_DWORD*)v40 + 7);
                        v40 += 24;
                    } while (v41);
                    if (v39)
                    {
                        v42 = sub_415FA0(0, v39 - 1);
                        v43 = 0;
                        v44 = 0;
                        if (*(_DWORD*)& byte_587000[211000])
                        {
                            v45 = &byte_587000[210996];
                            do
                            {
                                if (v72 & *((_DWORD*)v45 + 2)
                                    && v22 & *(_DWORD*)(*(_DWORD*)v45 + 28)
                                    && !(v22 & *((_DWORD*)v45 + 4)))
                                {
                                    if (v43 == v42)
                                    {
                                        *(_DWORD*)& v76[4] = *(_DWORD*)& byte_587000[24 * v44 + 210996];
                                        break;
                                    }
                                    ++v43;
                                }
                                v46 = *((_DWORD*)v45 + 7);
                                v45 += 24;
                                ++v44;
                            } while (v46);
                        }
                    }
                }
            }
            if (v19 & 4)
            {
                v47 = a2 >> 1;
                if ((int)(a2 >> 1) >= 1)
                {
                    if (v47 >= 5)
                        v47 = 4;
                }
                else
                {
                    v47 = 1;
                }
                v48 = v47 - 1;
                v49 = v47 + 1;
                if (v48 < 1)
                    v48 = 1;
                if (v49 >= 5)
                    v49 = 4;
                v50 = sub_415FA0(v48, v49);
                v51 = 0;
                if (*(_DWORD*)& byte_587000[209344])
                {
                    v52 = &byte_587000[209340];
                    do
                    {
                        if (v50 & *((_DWORD*)v52 + 2)
                            && v73 & *(_DWORD*)(*(_DWORD*)v52 + 28)
                            && !(v73 & *((_DWORD*)v52 + 4))
                            && *(_BYTE*)(*(_DWORD*)v52 + 36) & 1)
                        {
                            ++v51;
                        }
                        v53 = *((_DWORD*)v52 + 7);
                        v52 += 24;
                    } while (v53);
                    if (v51)
                    {
                        v54 = sub_415FA0(0, v51 - 1);
                        v55 = 0;
                        v56 = 0;
                        if (*(_DWORD*)& byte_587000[209344])
                        {
                            v57 = &byte_587000[209340];
                            do
                            {
                                if (v50 & *((_DWORD*)v57 + 2))
                                {
                                    if (v73 & *(_DWORD*)(*(_DWORD*)v57 + 28)
                                        && !(v73 & *((_DWORD*)v57 + 4))
                                        && *(_BYTE*)(*(_DWORD*)v57 + 36) & 1)
                                    {
                                        if (v55 == v54)
                                        {
                                            LOBYTE(v19) = v71;
                                            v74 = v56;
                                            *(_DWORD*)& v76[8] = *(_DWORD*)& byte_587000[24 * v56 + 209340];
                                            break;
                                        }
                                        ++v55;
                                    }
                                    LOBYTE(v19) = v71;
                                }
                                v58 = *((_DWORD*)v57 + 7);
                                v57 += 24;
                                ++v56;
                            } while (v58);
                        }
                    }
                }
            }
            if (v19 & 8)
            {
                v59 = a2 >> 1;
                if ((int)(a2 >> 1) >= 1)
                {
                    if (v59 >= 5)
                        v59 = 4;
                }
                else
                {
                    v59 = 1;
                }
                v60 = v59 - 1;
                v61 = v59 + 1;
                if (v60 < 1)
                    v60 = 1;
                if (v61 >= 5)
                    v61 = 4;
                v62 = sub_415FA0(v60, v61);
                v63 = 0;
                if (*(_DWORD*)& byte_587000[209344])
                {
                    v64 = &byte_587000[209340];
                    do
                    {
                        if (v62 & *((_DWORD*)v64 + 2)
                            && v73 & *(_DWORD*)(*(_DWORD*)v64 + 28)
                            && !(v73 & *((_DWORD*)v64 + 4))
                            && *(_BYTE*)(*(_DWORD*)v64 + 36) & 2)
                        {
                            ++v63;
                        }
                        v65 = *((_DWORD*)v64 + 7);
                        v64 += 24;
                    } while (v65);
                    if (v63)
                    {
                        v66 = sub_415FA0(0, v63 - 1);
                        v67 = 0;
                        v68 = 0;
                        if (*(_DWORD*)& byte_587000[209344])
                        {
                            v69 = &byte_587000[209340];
                            do
                            {
                                if (v62 & *((_DWORD*)v69 + 2)
                                    && v73 & *(_DWORD*)(*(_DWORD*)v69 + 28)
                                    && !(v73 & *((_DWORD*)v69 + 4))
                                    && *(_BYTE*)(*(_DWORD*)v69 + 36) & 2)
                                {
                                    if (v67 == v66)
                                    {
                                        if (byte_587000[24 * v74 + 209336] != byte_587000[24 * v68 + 209336])
                                            * (_DWORD*)& v76[12] = *(_DWORD*)& byte_587000[24 * v68 + 209340];
                                        break;
                                    }
                                    ++v67;
                                }
                                v70 = *((_DWORD*)v69 + 7);
                                v69 += 24;
                                ++v68;
                            } while (v70);
                        }
                    }
                }
            }
            sub_4E4990(v75, (int*)v76);
            return v75;
        default:
            return v14;
    }
}
// 4F1776: variable 'v71' is possibly undefined

//----- (004F1C40) --------------------------------------------------------
_DWORD* __cdecl sub_4F1C40(int a1, unsigned int a2)
{
    int v2; // ebx
    int v3; // edi
    unsigned __int8* v4; // esi
    int v5; // eax
    _DWORD* result; // eax
    int v7; // ebx
    int v8; // ebp
    int v9; // edi
    unsigned __int8* i; // esi
    int v11; // eax
    int v12; // [esp+18h] [ebp+8h]

    v2 = sub_4F0B60(a2);
    v3 = 0;
    v12 = v2;
    if (!*(_DWORD*)& byte_587000[208180])
        return 0;
    v4 = &byte_587000[208192];
    do
    {
        if (*(v4 - 4) & 4 && v2 & *(_DWORD*)v4 && sub_4E3BA0(*((_DWORD*)v4 - 2)))
            v3 += *(v4 - 16);
        v5 = *((_DWORD*)v4 + 2);
        v4 += 20;
    } while (v5);
    if (!v3)
        return 0;
    v7 = sub_415FA0(0, v3 - 1);
    v8 = 0;
    v9 = 0;
    if (!*(_DWORD*)& byte_587000[208180])
        goto LABEL_24;
    for (i = &byte_587000[208192]; ; i += 20)
    {
        if (*(i - 4) & 4)
        {
            if (*(_DWORD*)i & v12)
            {
                if (sub_4E3BA0(*((_DWORD*)i - 2)))
                {
                    v8 += *(i - 16);
                    if (v7 < v8)
                        break;
                }
            }
        }
        v11 = *((_DWORD*)i + 2);
        ++v9;
        if (!v11)
            return 0;
    }
    if (*(_DWORD*)& byte_587000[20 * v9 + 208184])
        result = sub_4E3450(*(_DWORD*)& byte_587000[20 * v9 + 208184]);
    else
        LABEL_24:
        result = 0;
    return result;
}

//----- (004F1D30) --------------------------------------------------------
_DWORD* __cdecl sub_4F1D30(int a1, unsigned int a2)
{
    unsigned int v2; // ebx
    int v3; // eax
    _DWORD* result; // eax
    _DWORD* v5; // edi
    int* v6; // esi

    v2 = sub_4F0B60(a2);
    if (v2 < 4 || sub_415FA0(1, 100) <= 90)
    {
        if (sub_415FA0(1, 2) == 1)
            result = sub_4E3810((CHAR*)& byte_587000[214712]);
        else
            result = sub_4E3810((CHAR*)& byte_587000[214728]);
        v5 = result;
        if (result)
        {
            v6 = (int*)result[173];
            switch (v2)
            {
                case 2u:
                    *v6 = sub_415FA0(*(int*)& byte_587000[211144], *(int*)& byte_587000[211148]);
                    result = v5;
                    break;
                case 4u:
                    *v6 = sub_415FA0(*(int*)& byte_587000[211152], *(int*)& byte_587000[211156]);
                    result = v5;
                    break;
                case 8u:
                    *v6 = sub_415FA0(*(int*)& byte_587000[211160], *(int*)& byte_587000[211164]);
                    result = v5;
                    break;
                case 0x10u:
                    *v6 = sub_415FA0(*(int*)& byte_587000[211168], *(int*)& byte_587000[211172]);
                    result = v5;
                    break;
                default:
                    *v6 = sub_415FA0(*(int*)& byte_587000[211136], *(int*)& byte_587000[211140]);
                    result = v5;
                    break;
            }
        }
    }
    else
    {
        v3 = sub_415FA0(1, 100);
        if (v3 >= 50)
        {
            if (v3 >= 90)
                result = sub_4E3810((CHAR*)& byte_587000[214660]);
            else
                result = sub_4E3810((CHAR*)& byte_587000[214648]);
        }
        else
        {
            result = sub_4E3810((CHAR*)& byte_587000[214640]);
        }
    }
    return result;
}

//----- (004F1F00) --------------------------------------------------------
_DWORD* __cdecl sub_4F1F00(int a1, unsigned int a2)
{
    return sub_4F1D30(a1, a2);
}

//----- (004F1F20) --------------------------------------------------------
void sub_4F1F20()
{
    int v0; // ebp
    int v1; // eax
    int v2; // esi
    int v3; // ebx
    int v4; // eax
    _DWORD* v5; // edi
    _DWORD* v6; // eax
    _DWORD* v7; // esi
    _DWORD* v8; // edi
    int v9; // [esp+0h] [ebp-10h]
    int v10; // [esp+4h] [ebp-Ch]
    float2 a3; // [esp+8h] [ebp-8h]

    v9 = sub_4E3CC0();
    if (!*(_DWORD*)& byte_5D4594[1568300])
    {
        *(_DWORD*)& byte_5D4594[1568300] = sub_4E3AA0((CHAR*)& byte_587000[214944]);
        *(_DWORD*)& byte_5D4594[1568304] = sub_4E3AA0((CHAR*)& byte_587000[214960]);
    }
    sub_4F2110();
    sub_4F2210();
    v0 = sub_4DA790();
    if (v0)
    {
        do
        {
            v10 = sub_4DA7A0(v0);
            v1 = *(unsigned __int16*)(v0 + 4);
            if ((unsigned __int16)v1 == *(_DWORD*)& byte_5D4594[1568300] || v1 == *(_DWORD*)& byte_5D4594[1568304])
            {
                if (*(_BYTE*)(*(_DWORD*)(v0 + 692) + 216) & 0x80)
                {
                    v7 = sub_4F0720(v0, v9);
                    if (v7)
                    {
                        sub_4DAA50((int)v7, 0, *(float*)(v0 + 56), *(float*)(v0 + 60));
                        if (v7[2] & 0x1000000)
                        {
                            if (v7[3] & 0xC)
                            {
                                v8 = sub_4E3810((CHAR*)& byte_587000[214980]);
                                if (v8)
                                {
                                    a3 = *((float2*)v7 + 7);
                                    sub_4ED970(30.0, (float2*)v7 + 7, &a3);
                                    sub_4DAA50((int)v8, 0, a3.field_0, a3.field_4);
                                }
                            }
                        }
                    }
                }
                sub_4E5CC0(v0);
            }
            else if (*(int* (__cdecl * *)(int))(v0 + 688) == sub_4F0400)
            {
                v2 = sub_4E7980(v0);
                if (v2)
                {
                    do
                    {
                        v3 = sub_4E7990(v2);
                        v4 = *(unsigned __int16*)(v2 + 4);
                        if ((unsigned __int16)v4 == *(_DWORD*)& byte_5D4594[1568300] || v4 == *(_DWORD*)& byte_5D4594[1568304])
                        {
                            v5 = sub_4F0720(v2, v9 + 1);
                            sub_4ED0C0(v0, (int*)v2);
                            sub_4E5CC0(v2);
                            if (v5)
                            {
                                sub_4F3070(v0, (int)v5, 0);
                                if (v5[2] & 0x1000000)
                                {
                                    if (v5[3] & 0xC)
                                    {
                                        v6 = sub_4E3810((CHAR*)& byte_587000[214988]);
                                        if (v6)
                                            sub_4F3070(v0, (int)v6, 0);
                                    }
                                }
                            }
                        }
                        v2 = v3;
                    } while (v3);
                }
            }
            v0 = v10;
        } while (v10);
    }
}

//----- (004F2110) --------------------------------------------------------
void sub_4F2110()
{
    int v0; // esi
    int i; // eax
    int v2; // ecx
    int v3; // ebx
    int v4; // edi
    int j; // esi
    int v6; // eax
    _DWORD* v7; // eax

    v0 = 0;
    if (!*(_DWORD*)& byte_5D4594[1568280])
    {
        *(_DWORD*)& byte_5D4594[1568280] = sub_4E3AA0((CHAR*)& byte_587000[214996]);
        *(_DWORD*)& byte_5D4594[1568284] = sub_4E3AA0((CHAR*)& byte_587000[215012]);
    }
    for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
    {
        v2 = *(unsigned __int16*)(i + 4);
        if (((unsigned __int16)v2 == *(_DWORD*)& byte_5D4594[1568280] || v2 == *(_DWORD*)& byte_5D4594[1568284])
            && (**(_BYTE * *)(i + 692) & 0x80))
        {
            ++v0;
        }
    }
    v3 = sub_415FA0(0, v0 - 1);
    v4 = 0;
    for (j = sub_4DA790(); j; j = sub_4DA7A0(j))
    {
        v6 = *(unsigned __int16*)(j + 4);
        if (((unsigned __int16)v6 == *(_DWORD*)& byte_5D4594[1568280] || v6 == *(_DWORD*)& byte_5D4594[1568284])
            && (**(_BYTE * *)(j + 692) & 0x80))
        {
            if (v4 == v3)
            {
                v7 = sub_4E3810((CHAR*)& byte_587000[215072]);
                if (v7)
                {
                    sub_4DAA50((int)v7, 0, *(float*)(j + 56), *(float*)(j + 60));
                    sub_4E5CC0(j);
                    return;
                }
            }
            else
            {
                ++v4;
            }
        }
    }
}

//----- (004F2210) --------------------------------------------------------
int sub_4F2210()
{
    _DWORD* v0; // ebp
    int v1; // esi
    int v2; // edi
    int v3; // edi
    int v4; // esi
    int result; // eax
    int v6; // ecx
    unsigned int v7; // edi
    _DWORD* v8; // esi
    _DWORD* v9; // ebx
    int v10; // ecx
    int v11; // edx
    char v12; // cl
    int v13; // esi
    int v14; // ebx
    _DWORD* v15; // edi
    int v16; // eax
    int v17; // ecx
    int* v18; // ecx
    int v19; // edx
    int v20; // eax
    unsigned int v21; // ebx
    int v22; // esi
    _DWORD* v23; // edi
    int v24; // eax
    int v25; // ecx
    unsigned int v26; // esi
    int* v27; // edi
    float v28; // [esp+10h] [ebp-14h]
    _DWORD* lpMem; // [esp+14h] [ebp-10h]
    unsigned int v30; // [esp+18h] [ebp-Ch]
    unsigned int v31; // [esp+18h] [ebp-Ch]

    v0 = 0;
    lpMem = 0;
    v1 = sub_4E3CC0();
    v2 = sub_4E3CE0();
    if (!*(_DWORD*)& byte_5D4594[1568288])
    {
        *(_DWORD*)& byte_5D4594[1568288] = sub_4E3AA0((CHAR*)& byte_587000[215080]);
        *(_DWORD*)& byte_5D4594[1568292] = sub_4E3AA0((CHAR*)& byte_587000[215096]);
        *(_DWORD*)& byte_5D4594[1568296] = sub_4E3AA0((CHAR*)& byte_587000[215116]);
    }
    if (v1 == 1)
    {
        v28 = 0.5;
    }
    else
    {
        switch (v2)
        {
            case 1:
            case 2:
                v28 = 0.40000001;
                break;
            case 3:
            case 4:
                v28 = 0.69999999;
                break;
            case 5:
            case 6:
                v28 = 1.0;
                break;
            default:
                break;
        }
    }
    v3 = 0;
    v4 = 0;
    result = sub_4DA790();
    if (result)
    {
        do
        {
            v6 = *(unsigned __int16*)(result + 4);
            if ((unsigned __int16)v6 == *(_DWORD*)& byte_5D4594[1568288])
            {
                if (!(*(_BYTE*)(*(_DWORD*)(result + 692) + 216) & 1))
                    ++v3;
            }
            else if (v6 == *(_DWORD*)& byte_5D4594[1568296])
            {
                ++v4;
            }
            result = sub_4DA7A0(result);
        } while (result);
        if (v3)
        {
            v0 = nox_malloc(4 * v3);
            if (!v4)
                goto LABEL_21;
        }
        else if (!v4)
        {
            return result;
        }
        lpMem = nox_malloc(4 * v4);
        LABEL_21:
        v7 = 0;
        v30 = 0;
        result = sub_4DA790();
        if (result)
        {
            v8 = lpMem;
            v9 = v0;
            do
            {
                v10 = *(unsigned __int16*)(result + 4);
                if ((unsigned __int16)v10 == *(_DWORD*)& byte_5D4594[1568288])
                {
                    v11 = *(_DWORD*)(result + 692);
                    v12 = *(_BYTE*)(v11 + 216);
                    if (v12 & 1)
                    {
                        *(_BYTE*)(v11 + 216) = v12 | 0x80;
                    }
                    else
                    {
                        *v9 = result;
                        ++v7;
                        ++v9;
                    }
                }
                else if (v10 == *(_DWORD*)& byte_5D4594[1568292])
                {
                    *(_BYTE*)(*(_DWORD*)(result + 692) + 216) |= 0x80u;
                }
                else if (v10 == *(_DWORD*)& byte_5D4594[1568296])
                {
                    *v8 = result;
                    ++v8;
                    ++v30;
                }
                result = sub_4DA7A0(result);
            } while (result);
            if (v7)
            {
                v13 = v7 - 1;
                v14 = (__int64)((double)v7 * v28 + 0.5);
                if (v7 != 1)
                {
                    v15 = &v0[v13];
                    do
                    {
                        v16 = sub_415FA0(0, v13);
                        v17 = v0[v16];
                        v0[v16] = *v15;
                        *v15 = v17;
                        --v13;
                        --v15;
                    } while (v13);
                }
                if (v14)
                {
                    v18 = v0;
                    v19 = v14;
                    do
                    {
                        v20 = *v18;
                        ++v18;
                        --v19;
                        *(_BYTE*)(*(_DWORD*)(v20 + 692) + 216) |= 0x80u;
                    } while (v19);
                }
                free(v0);
            }
            v21 = v30;
            if (v30)
            {
                v22 = v30 - 1;
                v31 = (__int64)((double)v30 * v28 + 0.5);
                if (v21 != 1)
                {
                    v23 = &lpMem[v22];
                    do
                    {
                        v24 = sub_415FA0(0, v22);
                        v25 = lpMem[v24];
                        lpMem[v24] = *v23;
                        *v23 = v25;
                        --v22;
                        --v23;
                    } while (v22);
                }
                v26 = 0;
                if (v21)
                {
                    v27 = lpMem;
                    do
                    {
                        if (v26 >= v31)
                            sub_4E5CC0(*v27);
                        ++v26;
                        ++v27;
                    } while (v26 < v21);
                }
                free(lpMem);
            }
        }
    }
    return result;
}
// 4F23B8: variable 'v28' is possibly undefined

//----- (004F24E0) --------------------------------------------------------
int __cdecl sub_4F24E0(int a1)
{
    int v1; // eax
    unsigned __int8* v2; // ecx
    int result; // eax

    v1 = *(_DWORD*)& byte_587000[207108];
    if (!*(_DWORD*)& byte_587000[207108])
        goto LABEL_6;
    v2 = &byte_587000[207108];
    while (v1 != a1 || !*((_DWORD*)v2 + 1))
    {
        v1 = *((_DWORD*)v2 + 3);
        v2 += 12;
        if (!v1)
            goto LABEL_6;
    }
    if (a1 && a1 != 34 && a1 != 27 && a1 != 9 && a1 != 41)
        result = 1;
    else
        LABEL_6:
        result = 0;
    return result;
}

//----- (004F2530) --------------------------------------------------------
BOOL __cdecl sub_4F2530(int a1)
{
    int v1; // eax
    unsigned __int8* i; // ecx

    v1 = *(_DWORD*)& byte_587000[207796];
    if (!*(_DWORD*)& byte_587000[207796])
        return 0;
    for (i = &byte_587000[207796]; v1 != a1 || !*((_DWORD*)i + 1); i += 12)
    {
        v1 = *((_DWORD*)i + 3);
        if (!v1)
            return 0;
    }
    return a1 != 0;
}

//----- (004F2570) --------------------------------------------------------
BOOL __cdecl sub_4F2570(int a1)
{
    return a1 > 0 && a1 < 6;
}

//----- (004F2590) --------------------------------------------------------
int __cdecl sub_4F2590(int a1)
{
    int v1; // ebx
    int v3; // ecx
    int v4; // edx
    unsigned __int8* v5; // eax
    int v6; // edi

    if (!*(_DWORD*)& byte_5D4594[1568328])
    {
        *(_DWORD*)& byte_5D4594[1568328] = sub_4E3AA0((CHAR*)& byte_587000[215208]);
        *(_DWORD*)& byte_5D4594[1568332] = sub_4E3AA0((CHAR*)& byte_587000[215216]);
        *(_DWORD*)& byte_5D4594[1568336] = sub_4E3AA0((CHAR*)& byte_587000[215224]);
        *(_DWORD*)& byte_5D4594[1568340] = sub_4E3AA0((CHAR*)& byte_587000[215232]);
        *(_DWORD*)& byte_5D4594[1568344] = sub_4E3AA0((CHAR*)& byte_587000[215252]);
        *(_DWORD*)& byte_5D4594[1568352] = sub_4E3AA0((CHAR*)& byte_587000[215268]);
        *(_DWORD*)& byte_5D4594[1568348] = sub_4E3AA0((CHAR*)& byte_587000[215280]);
    }
    v1 = *(_DWORD*)(a1 + 8);
    if (v1 & 0x40)
        return 0;
    if (v1 & 0x10)
        return (*(_DWORD*)(a1 + 12) & 0x1FF78) != 0;
    if (v1 & 0x100)
        return sub_4F2700(a1);
    v3 = *(unsigned __int16*)(a1 + 4);
    if ((unsigned __int16)v3 != *(_DWORD*)& byte_5D4594[1568328]
        && v3 != *(_DWORD*)& byte_5D4594[1568332]
        && v3 != *(_DWORD*)& byte_5D4594[1568336])
    {
        v4 = 0;
        if (*(_DWORD*)& byte_587000[208180])
        {
            v5 = &byte_587000[208180];
            while (*((_DWORD*)v5 + 1) != v3)
            {
                v6 = *((_DWORD*)v5 + 5);
                v5 += 20;
                if (!v6)
                    goto LABEL_18;
            }
            v4 = 1;
        }
        LABEL_18:
        if (v3 == *(_DWORD*)& byte_5D4594[1568340]
            || v3 == *(_DWORD*)& byte_5D4594[1568344]
            || v3 == *(_DWORD*)& byte_5D4594[1568352]
            || v3 == *(_DWORD*)& byte_5D4594[1568348])
        {
            return sub_4F2B60(a1);
        }
        if (v4 != 1)
            return 0;
        if (v1 & 0x1000000)
            return sub_4F27A0(a1);
        if (v1 & 0x2000000)
            return sub_4F2B20(a1);
    }
    return 1;
}

//----- (004F2700) --------------------------------------------------------
int __cdecl sub_4F2700(int a1)
{
    int v1; // ecx
    int v2; // eax
    unsigned __int8* i; // ecx
    int v5; // eax
    int v6; // ecx
    unsigned __int8* j; // edx
    unsigned __int8 v8; // al

    v1 = *(_DWORD*)(a1 + 12);
    if (v1 & 1)
    {
        if (*(_DWORD*)& byte_587000[207108])
        {
            v2 = *(_DWORD*)& byte_587000[207108];
            for (i = &byte_587000[207108]; v2 != **(unsigned __int8**)(a1 + 736) || !*((_DWORD*)i + 1); i += 12)
            {
                v2 = *((_DWORD*)i + 3);
                if (!v2)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    if (v1 & 2)
    {
        v5 = sub_427010(*(const char**)(a1 + 736));
        v6 = *(_DWORD*)& byte_587000[207796];
        if (*(_DWORD*)& byte_587000[207796])
        {
            for (j = &byte_587000[207796]; v6 != v5 || !*((_DWORD*)j + 1); j += 12)
            {
                v6 = *((_DWORD*)j + 3);
                if (!v6)
                    return 0;
            }
            return 1;
        }
        return 0;
    }
    if (!(v1 & 4))
        return 0;
    v8 = **(_BYTE * *)(a1 + 736);
    if (!v8 || v8 >= 6u)
        return 0;
    return 1;
}

//----- (004F27A0) --------------------------------------------------------
int __cdecl sub_4F27A0(int a1)
{
    int result; // eax

    result = sub_4F27E0(a1);
    if (result)
    {
        result = sub_4F28C0(a1);
        if (result)
            result = sub_4F2960(a1) != 0;
    }
    return result;
}

//----- (004F27E0) --------------------------------------------------------
int __cdecl sub_4F27E0(int a1)
{
    int v1; // edi
    int v2; // eax
    int v3; // esi
    int v4; // edx
    unsigned __int8* i; // ecx
    int v6; // ebx
    unsigned __int8* v8; // ecx
    int v9; // edx
    unsigned __int8* j; // ecx
    int v11; // ebx

    v1 = **(_DWORD * *)(a1 + 692);
    if (!v1)
        return 1;
    if (*(_DWORD*)(a1 + 8) & 0x1000000)
        v2 = sub_415820(a1);
    else
        v2 = sub_415C70(a1);
    v3 = *(_DWORD*)(a1 + 8) & 0x1000000;
    if (v3)
    {
        v4 = 0;
        if (*(_DWORD*)& byte_587000[210712])
        {
            for (i = &byte_587000[210712]; *((_DWORD*)i - 1) != v1; i += 24)
            {
                v6 = *((_DWORD*)i + 6);
                ++v4;
                if (!v6)
                    return 0;
            }
            v8 = &byte_587000[24 * v4 + 210704];
            goto LABEL_18;
        }
        return 0;
    }
    v9 = 0;
    if (!*(_DWORD*)& byte_587000[210856])
        return 0;
    for (j = &byte_587000[210856]; *((_DWORD*)j - 1) != v1; j += 24)
    {
        v11 = *((_DWORD*)j + 6);
        ++v9;
        if (!v11)
            return 0;
    }
    v8 = &byte_587000[24 * v9 + 210848];
    LABEL_18:
    if (!v8)
        return 0;
    if (v3)
    {
        if (!(v2 & *(_DWORD*)(v1 + 28)) || v2 & *((_DWORD*)v8 + 5))
            return 0;
    }
    else if (!(v2 & *(_DWORD*)(v1 + 32)) || v2 & *((_DWORD*)v8 + 4))
    {
        return 0;
    }
    return 1;
}

//----- (004F28C0) --------------------------------------------------------
int __cdecl sub_4F28C0(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // edx
    unsigned __int8* i; // ecx
    int v5; // ebp
    unsigned __int8* v7; // ecx

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 692) + 4);
    if (v1)
    {
        if (*(_DWORD*)(a1 + 8) & 0x1000000)
            v2 = sub_415820(a1);
        else
            v2 = sub_415C70(a1);
        v3 = 0;
        if (!*(_DWORD*)& byte_587000[211000])
            return 0;
        for (i = &byte_587000[211000]; *((_DWORD*)i - 1) != v1; i += 24)
        {
            v5 = *((_DWORD*)i + 6);
            ++v3;
            if (!v5)
                return 0;
        }
        v7 = &byte_587000[24 * v3 + 210992];
        if (!v7)
            return 0;
        if (*(_DWORD*)(a1 + 8) & 0x1000000)
        {
            if (!(v2 & *(_DWORD*)(v1 + 28)) || v2 & *((_DWORD*)v7 + 5))
                return 0;
        }
        else if (!(v2 & *(_DWORD*)(v1 + 32)) || v2 & *((_DWORD*)v7 + 4))
        {
            return 0;
        }
    }
    return 1;
}

//----- (004F2960) --------------------------------------------------------
int __cdecl sub_4F2960(int a1)
{
    int v1; // eax
    int v2; // eax
    int v3; // eax
    int v4; // eax
    int v5; // eax
    int v6; // ebx
    int v7; // ecx
    char v8; // dl
    unsigned __int8* v9; // edi
    int v10; // esi
    unsigned __int8* v11; // edx
    int v12; // esi
    _BYTE* v13; // ecx
    unsigned __int8* v14; // edx
    int v16; // [esp+10h] [ebp-4h]

    v16 = *(_DWORD*)(a1 + 692);
    if (!*(_DWORD*)& byte_5D4594[1568308])
    {
        v1 = sub_413290("Replenishment1");
        *(_DWORD*)& byte_5D4594[1568308] = sub_413330(v1);
        v2 = sub_413290("Replenishment2");
        *(_DWORD*)& byte_5D4594[1568312] = sub_413330(v2);
        v3 = sub_413290("Replenishment3");
        *(_DWORD*)& byte_5D4594[1568316] = sub_413330(v3);
        v4 = sub_413290("Replenishment4");
        *(_DWORD*)& byte_5D4594[1568320] = sub_413330(v4);
    }
    if (*(_DWORD*)(a1 + 8) & 0x1000000)
        v5 = sub_415820(a1);
    else
        v5 = sub_415C70(a1);
    v6 = 2;
    while (1)
    {
        v7 = *(_DWORD*)(v16 + 4 * v6);
        if (!v7)
            goto LABEL_40;
        v8 = *(_BYTE*)(v7 + 36);
        v9 = 0;
        if (v6 == 2)
        {
            if (!(v8 & 1))
                return 0;
        }
        else if (!(v8 & 2))
        {
            return 0;
        }
        v10 = 0;
        if (!*(_DWORD*)& byte_587000[209344])
            goto LABEL_18;
        v11 = &byte_587000[209344];
        while (*((_DWORD*)v11 - 1) != v7)
        {
            v11 += 24;
            ++v10;
            if (!*(_DWORD*)v11)
                goto LABEL_18;
        }
        v9 = &byte_587000[24 * v10 + 209336];
        if (!v9)
        {
            LABEL_18:
            if (v7 == *(_DWORD*)& byte_5D4594[1568308])
                break;
            if (v7 != *(_DWORD*)& byte_5D4594[1568312]
                && v7 != *(_DWORD*)& byte_5D4594[1568316]
                && v7 != *(_DWORD*)& byte_5D4594[1568320])
            {
                return 0;
            }
        }
        if (v7 == *(_DWORD*)& byte_5D4594[1568308]
            || v7 == *(_DWORD*)& byte_5D4594[1568312]
            || v7 == *(_DWORD*)& byte_5D4594[1568316]
            || v7 == *(_DWORD*)& byte_5D4594[1568320])
        {
            break;
        }
        if (*(_DWORD*)(a1 + 8) & 0x1000000)
        {
            if (!(v5 & *(_DWORD*)(v7 + 28)) || v5 & *((_DWORD*)v9 + 5))
                return 0;
        }
        else if (!(v5 & *(_DWORD*)(v7 + 32)) || v5 & *((_DWORD*)v9 + 4))
        {
            return 0;
        }
        LABEL_40:
        if (++v6 >= 4)
            return 1;
    }
    v12 = 0;
    if (*(_DWORD*)& byte_587000[208180])
    {
        v13 = *(_BYTE * *)& byte_587000[208180];
        v14 = &byte_587000[208180];
        do
        {
            if (*v13 == 35 && *((_DWORD*)v14 + 1) == *(unsigned __int16*)(a1 + 4))
                v12 = 1;
            v13 = (_BYTE*) * ((_DWORD*)v14 + 5);
            v14 += 20;
        } while (v13);
        if (v12)
            goto LABEL_40;
    }
    return 0;
}

//----- (004F2B20) --------------------------------------------------------
int __cdecl sub_4F2B20(int a1)
{
    int result; // eax

    result = sub_4F27E0(a1);
    if (result)
    {
        result = sub_4F28C0(a1);
        if (result)
            result = sub_4F2960(a1) != 0;
    }
    return result;
}

//----- (004F2B60) --------------------------------------------------------
int __cdecl sub_4F2B60(int a1)
{
    int v1; // eax
    _DWORD* v2; // eax
    __int16 v4; // ax
    const char*** v5; // esi
    int v6; // edi

    if (!*(_DWORD*)& byte_5D4594[1568324])
    {
        v1 = sub_413290("Replenishment1");
        *(_DWORD*)& byte_5D4594[1568324] = sub_413330(v1);
    }
    if (*(_DWORD*)(a1 + 8) & 0x1000000 && sub_415820(a1) & 0x10000)
    {
        v2 = *(_DWORD * *)(a1 + 692);
        if (*v2)
            return 0;
        if (v2[1])
            return 0;
        if (v2[2] != *(_DWORD*)& byte_5D4594[1568324])
            return 0;
        if (v2[3])
            return 0;
    }
    if (*(_DWORD*)(a1 + 8) & 0x2000000)
    {
        v4 = sub_415C70(a1);
        v5 = *(const char****)(a1 + 692);
        if (v4 & 0x405)
        {
            v6 = 0;
            while (!*v5 || !_strnicmp(**v5, "UserColo", 8u))
            {
                ++v6;
                ++v5;
                if (v6 >= 4)
                    return 1;
            }
            return 0;
        }
    }
    return 1;
}

//----- (004F2C30) --------------------------------------------------------
BOOL __cdecl sub_4F2C30(int a1)
{
    int v1; // edi
    float v3; // [esp+0h] [ebp-Ch]

    if (!*(_DWORD*)& byte_5D4594[1568356])
    {
        *(_DWORD*)& byte_5D4594[1568356] = sub_4E3AA0((CHAR*)& byte_587000[215384]);
        *(_DWORD*)& byte_5D4594[1568360] = sub_4E3AA0((CHAR*)& byte_587000[215396]);
        *(_DWORD*)& byte_5D4594[1568364] = sub_4E3AA0((CHAR*)& byte_587000[215408]);
        *(_DWORD*)& byte_5D4594[1568368] = sub_4E3AA0((CHAR*)& byte_587000[215428]);
        *(_DWORD*)& byte_5D4594[1568372] = sub_4E3AA0((CHAR*)& byte_587000[215440]);
        *(_DWORD*)& byte_5D4594[1568376] = sub_4E3AA0((CHAR*)& byte_587000[215460]);
        *(_DWORD*)& byte_5D4594[1568380] = sub_4E3AA0((CHAR*)& byte_587000[215476]);
        *(_DWORD*)& byte_5D4594[1568384] = sub_4E3AA0((CHAR*)& byte_587000[215492]);
        *(_DWORD*)& byte_5D4594[1568388] = sub_4E3AA0((CHAR*)& byte_587000[215512]);
        *(_DWORD*)& byte_5D4594[1568392] = sub_4E3AA0((CHAR*)& byte_587000[215532]);
        *(_DWORD*)& byte_5D4594[1568396] = sub_4E3AA0((CHAR*)& byte_587000[215552]);
        *(_DWORD*)& byte_5D4594[1568400] = sub_4E3AA0((CHAR*)& byte_587000[215576]);
        *(_DWORD*)& byte_5D4594[1568404] = sub_4E3AA0((CHAR*)& byte_587000[215596]);
    }
    if (!a1 || !(*(_BYTE*)(a1 + 8) & 4))
        return 1;
    if (sub_4E7D30(a1, *(int*)& byte_5D4594[1568356]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568360]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568364]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568368]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568372]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568376]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568380]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568384]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568388]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568392]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568396]) > 9
        || sub_4E7D30(a1, *(int*)& byte_5D4594[1568400]) > 9)
    {
        return 0;
    }
    v3 = sub_419D40(&byte_587000[215616]);
    v1 = sub_419A70(v3);
    return sub_4E7D30(a1, *(int*)& byte_5D4594[1568404]) <= v1;
}

//----- (004F2E70) --------------------------------------------------------
BOOL __cdecl sub_4F2E70(int a1)
{
    int v1; // eax
    int v2; // esi
    unsigned __int8* v3; // ecx

    v1 = *(_DWORD*)& byte_587000[207108];
    v2 = 0;
    if (*(_DWORD*)& byte_587000[207108])
    {
        v3 = &byte_587000[207108];
        while (v1 != a1 || !*((_DWORD*)v3 + 1))
        {
            v1 = *((_DWORD*)v3 + 3);
            v3 += 12;
            if (!v1)
                goto LABEL_8;
        }
        v2 = 1;
    }
    LABEL_8:
    if (a1 == 46 || a1 == 47 || a1 == 48 || a1 == 49 || a1 == 122 || a1 == 123 || a1 == 124 || a1 == 125)
        v2 = 1;
    return a1 >= 75 && a1 <= 114 || v2;
}

//----- (004F2EF0) --------------------------------------------------------
BOOL __cdecl sub_4F2EF0(int a1)
{
    int v1; // eax
    int v2; // edi
    unsigned __int8* v3; // ecx
    int* v4; // eax
    unsigned __int8* v5; // edx
    int v6; // ecx
    int* v7; // eax
    int v8; // ecx

    v1 = *(_DWORD*)& byte_587000[207796];
    v2 = 0;
    if (*(_DWORD*)& byte_587000[207796])
    {
        v3 = &byte_587000[207796];
        while (v1 != a1 || !*((_DWORD*)v3 + 1))
        {
            v1 = *((_DWORD*)v3 + 3);
            v3 += 12;
            if (!v1)
                goto LABEL_8;
        }
        v2 = 1;
    }
    LABEL_8:
    v4 = *(int**)& byte_587000[207032];
    v5 = &byte_587000[207032];
    if (*(_DWORD*)& byte_587000[207032])
    {
        do
        {
            v6 = *v4;
            v7 = v4 + 1;
            if (v6)
            {
                while (1)
                {
                    v8 = *v7;
                    if (*v7 == a1)
                        break;
                    ++v7;
                    if (!v8)
                        goto LABEL_14;
                }
                v2 = 1;
            }
            LABEL_14:
            v4 = (int*) * ((_DWORD*)v5 + 1);
            v5 += 4;
        } while (v4);
    }
    return v2 != 0;
}

//----- (004F2F70) --------------------------------------------------------
int __cdecl sub_4F2F70(_DWORD* a1, int a2)
{
    int result; // eax

    if (sub_53A420(a1, a2, 1, 1) || (result = sub_53E650(a1, a2, 1, 1)) != 0)
        result = 1;
    return result;
}

//----- (004F2FB0) --------------------------------------------------------
int __cdecl sub_4F2FB0(_DWORD* a1, int a2)
{
    int result; // eax

    if (sub_53A140(a1, a2, 1, 1) || (result = sub_53E430(a1, a2, 1, 1)) != 0)
        result = 1;
    return result;
}

//----- (004F2FF0) --------------------------------------------------------
int __cdecl sub_4F2FF0(int a1, int a2)
{
    int v2; // ebp
    int* v3; // esi
    int result; // eax
    int(__cdecl * v5)(int, int, int); // ecx

    v2 = 2;
    v3 = (int*)(*(_DWORD*)(a1 + 692) + 8);
    do
    {
        result = *v3;
        if (*v3)
        {
            v5 = *(int(__cdecl * *)(int, int, int))(result + 112);
            if (v5)
                result = v5(result, a2, a1);
        }
        ++v3;
        --v2;
    } while (v2);
    return result;
}

//----- (004F3030) --------------------------------------------------------
int __cdecl sub_4F3030(int a1, int a2)
{
    int v2; // ebp
    int* v3; // esi
    int result; // eax
    int(__cdecl * v5)(int, int, int); // ecx

    v2 = 2;
    v3 = (int*)(*(_DWORD*)(a1 + 692) + 8);
    do
    {
        result = *v3;
        if (*v3)
        {
            v5 = *(int(__cdecl * *)(int, int, int))(result + 116);
            if (v5)
                result = v5(result, a2, a1);
        }
        ++v3;
        --v2;
    } while (v2);
    return result;
}

//----- (004F3070) --------------------------------------------------------
void __cdecl sub_4F3070(int a1, int a2, int a3)
{
    int v3; // ebp
    int v4; // eax
    int v5; // ebx
    int i; // eax
    int v7; // ecx

    v3 = 0;
    if (a1 && a2 && !(*(_BYTE*)(a1 + 16) & 0x20) && !(*(_BYTE*)(a2 + 16) & 0x20))
    {
        *(_DWORD*)(a2 + 500) = 0;
        *(_DWORD*)(a2 + 496) = *(_DWORD*)(a1 + 504);
        v4 = *(_DWORD*)(a1 + 504);
        if (v4)
            * (_DWORD*)(v4 + 500) = a2;
        *(_DWORD*)(a1 + 504) = a2;
        *(_DWORD*)(a2 + 492) = a1;
        sub_4EC290(a1, a2);
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v5 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
            if (a3)
                sub_4D8A60(*(unsigned __int8*)(v5 + 2064), a2);
            sub_56FBF0(*(_DWORD*)(v5 + 4632), (int*)a2);
            for (i = *(_DWORD*)(a1 + 504); i; v3 += v7)
            {
                v7 = *(unsigned __int8*)(i + 488);
                i = *(_DWORD*)(i + 496);
            }
            *(_DWORD*)(v5 + 3656) = v3 > * (unsigned __int16*)(a1 + 490);
        }
        if (*(_BYTE*)(a2 + 8) & 0x40)
            sub_501960(820, a1, 0, 0);
    }
}

//----- (004F3180) --------------------------------------------------------
bool __cdecl sub_4F3180(int a1, int a2)
{
    int v2; // esi
    _DWORD* v3; // eax
    bool result; // al

    if (*(_BYTE*)(a1 + 8) & 4
        && ((v2 = sub_4F9FD0(a1), !(*(_DWORD*)(a2 + 8) & 0x2000000)) ? (v3 = sub_413250(*(unsigned __int16*)(a2 + 4))) : (v3 = sub_413270(*(unsigned __int16*)(a2 + 4))),
            v3))
    {
        result = v2 >= *((unsigned __int16*)v3 + 30);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004F31E0) --------------------------------------------------------
int __cdecl sub_4F31E0(int a1, int a2, int a3)
{
    BOOL v3; // eax
    int v4; // edi
    int v5; // ebp
    char* v6; // eax
    int v7; // ecx
    int result; // eax
    int v9; // eax
    int i; // ecx
    int v11; // edx
    int v12; // esi
    int v13; // esi

    v3 = sub_40A5C0(4096);
    v4 = a1;
    v5 = a2;
    if (v3
        || !sub_419130(a2 + 48)
        || sub_419150(v4 + 48, v5 + 48)
        || (v6 = sub_418AB0(*(unsigned __int8*)(v5 + 52))) == 0)
    {
        if (*(_DWORD*)(v5 + 492))
        {
            result = 0;
        }
        else if (*(_WORD*)(v4 + 490))
        {
            v9 = *(_DWORD*)(v4 + 504);
            for (i = 0; v9; i += v11)
            {
                v11 = *(unsigned __int8*)(v9 + 488);
                v9 = *(_DWORD*)(v9 + 496);
            }
            if (2 * *(unsigned __int16*)(v4 + 490) - i >= *(unsigned __int8*)(v5 + 488))
            {
                if ((*(_BYTE*)(v5 + 8) & 0x10) != 16
                    || ((v12 = sub_4E7D30(v4, *(unsigned __int16*)(v5 + 4)), !sub_40A5C0(6144)) ? (v13 = v12 - 3) : (v13 = v12 - 9),
                        v13 < 0))
                {
                    sub_4DADE0(v5);
                    sub_4F3070(v4, v5, a3);
                    result = 1;
                }
                else
                {
                    sub_4DA2C0(v4, "pickup.c:MaxSameItem", 0);
                    result = 0;
                }
            }
            else
            {
                sub_4DA2C0(v4, "pickup.c:CarryingTooMuch", 0);
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        if (*(_BYTE*)(v4 + 8) & 4)
        {
            v7 = *(_DWORD*)(v4 + 748);
            a1 = (unsigned __int8)v6[56];
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v7 + 276) + 2064), 16, &a1);
        }
        result = 0;
    }
    return result;
}

//----- (004F3350) --------------------------------------------------------
int __cdecl sub_4F3350(int a1, int a2, int a3)
{
    int v4; // ebx
    unsigned __int8* v5; // eax

    if (!a1 || !a2)
        return 0;
    if (!sub_419E60(a1) && !(*(_BYTE*)(a2 + 12) & 0x84))
        (*(void(__cdecl * *)(int, int))(a2 + 732))(a1, a2);
    if (*(_BYTE*)(a2 + 16) & 0x20)
        return 1;
    v4 = sub_4F31E0(a1, a2, a3);
    if (v4)
    {
        v5 = &byte_587000[215640];
        if (*(_WORD*)& byte_587000[215646])
        {
            while (!(*(_DWORD*)(a2 + 12) & *(_DWORD*)v5) && !(*((_WORD*)v5 + 2) & *(_WORD*)(a2 + 24)))
            {
                v5 += 8;
                if (!*((_WORD*)v5 + 3))
                    return v4;
            }
            sub_501960(*((unsigned __int16*)v5 + 3), a1, 0, 0);
        }
    }
    return v4;
}

//----- (004F3400) --------------------------------------------------------
int __cdecl sub_4F3400(int a1, int a2, int a3)
{
    int v3; // ebp
    int result; // eax
    int v5; // ebx
    char v6[10]; // [esp+Ch] [ebp-Ch]

    v3 = *(_DWORD*)(a2 + 748);
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v5 = sub_4F31E0(a1, a2, a3);
    if (v5)
    {
        *(_DWORD*)(*(_DWORD*)(a1 + 748) + 264) = *(_DWORD*)& byte_5D4594[2598000];
        sub_4EC290(a1, a2);
        sub_4FF380(a1, 30, 0, 5);
        sub_501960(313, a1, 0, 0);
        *(_DWORD*)& v6[2] = *(_DWORD*)(a1 + 36);
        if (sub_419130(a1 + 48))
            * (_DWORD*)& v6[6] = *(unsigned __int8*)(a1 + 52);
        else
            *(_DWORD*)& v6[6] = 0;
        sub_4DA180(10, v6);
        sub_417470(a2, 1);
    }
    result = v5;
    *(_DWORD*)(v3 + 4) = 0;
    return result;
}

//----- (004F34D0) --------------------------------------------------------
int __cdecl sub_4F34D0(int a1, int a2, int a3)
{
    int result; // eax

    sub_53F8E0(a1, a2);
    if (*(_BYTE*)(a2 + 16) & 0x20)
        result = 1;
    else
        result = sub_4F31E0(a1, a2, a3);
    return result;
}

//----- (004F3510) --------------------------------------------------------
int __cdecl sub_4F3510(int a1, int a2, int a3)
{
    int v3; // edi
    int result; // eax

    if (sub_4EC4F0(a2, a1))
    {
        v3 = sub_4F31E0(a1, a2, a3);
        if (v3)
            sub_501960(824, a1, 0, 0);
        result = v3;
    }
    else
    {
        if (*(_BYTE*)(a1 + 8) & 4)
            sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
        result = 0;
    }
    return result;
}

//----- (004F3580) --------------------------------------------------------
int __cdecl sub_4F3580(int a1, int a2, int a3)
{
    int v3; // edi
    int v4; // edi
    char* v5; // ebx
    int j; // esi
    int i; // edi

    if (!sub_4F31E0(a1, a2, a3))
        return 0;
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 1;
    v3 = *(_DWORD*)(a1 + 748);
    if (!sub_40A5C0(64))
        return 1;
    sub_501960(307, a1, 0, 0);
    ++* (_DWORD*)(*(_DWORD*)(v3 + 276) + 2152);
    *(_DWORD*)(*(_DWORD*)(v3 + 276) + 2156) = sub_4D1600();
    sub_4D8CD0(a1);
    if (!sub_419130(a1 + 48))
    {
        if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 2152) == sub_4D1600())
        {
            sub_40A4D0(8);
            sub_4D8E90(a1, 1);
            sub_4D8EF0(a1);
            for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
            {
                if (i != a1)
                {
                    sub_4D8D40(i);
                    sub_4D8EF0(i);
                }
            }
        }
        return 1;
    }
    v4 = 0;
    v5 = sub_418AB0(*(unsigned __int8*)(a1 + 52));
    if (v5)
    {
        for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j))
        {
            if (sub_419180(j + 48, v5[57]))
                v4 += *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(j + 748) + 276) + 2152);
        }
        if (v4 == sub_4D1600())
            sub_40A4D0(8);
    }
    return 1;
}

//----- (004F36F0) --------------------------------------------------------
int __cdecl sub_4F36F0(int a1, int a2, int a3, int a4)
{
    int v4; // eax
    int(__cdecl * v5)(int, int, int, int); // eax
    int v6; // eax
    int v7; // ebx
    int v8; // eax

    if (!a1)
        return 0;
    if (!a2)
        return 0;
    if (!*(_WORD*)(a1 + 490))
        return 0;
    if (*(_BYTE*)(a2 + 16) & 0x20)
        return 0;
    v4 = *(_DWORD*)(a1 + 16);
    if ((v4 & 0x8000) != 0 || !sub_4E3BA0(*(unsigned __int16*)(a2 + 4)) || !(*(_BYTE*)(a1 + 8) & 6))
        return 0;
    v5 = *(int(__cdecl * *)(int, int, int, int))(a2 + 708);
    if (v5)
        v6 = v5(a1, a2, a3, a4);
    else
        v6 = sub_4F31E0(a1, a2, a3);
    v7 = v6;
    if (v6)
    {
        v8 = *(_DWORD*)(a2 + 16);
        if (v8 & 0x40)
        {
            LOBYTE(v8) = v8 & 0xBF;
            *(_DWORD*)(a2 + 16) = v8;
            if (*(_DWORD*)(a2 + 696))
                sub_5117F0(a2);
        }
        if (*(int*)(a2 + 768) != -1)
        {
            sub_502490((int*)(a2 + 764), a1, a2);
            *(_DWORD*)(a2 + 768) = -1;
        }
    }
    return v7;
}

//----- (004F37D0) --------------------------------------------------------
int __cdecl sub_4F37D0(int a1, int a2, int a3)
{
    int v3; // ebx
    int* v4; // eax
    int v5; // edi
    char v7; // al
    double v8; // st7
    int v9; // ebp
    char v10; // al
    double v11; // st7
    int v12; // eax
    int v13; // edi
    float v14; // [esp+0h] [ebp-18h]
    float v15; // [esp+4h] [ebp-14h]
    int v16; // [esp+14h] [ebp-4h]
    int v17; // [esp+20h] [ebp+8h]

    v3 = a2;
    v4 = *(int**)(a2 + 736);
    v16 = 0;
    v5 = *v4;
    v17 = *v4;
    if (sub_40A5C0(0x2000)
        && !sub_40A5C0(4096)
        && *(_BYTE*)(a1 + 8) & 4
        && !sub_57B3D0(v3, *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251)))
    {
        sub_4DA2C0(a1, "pickup.c:ObjectEquipClassFail", 0);
        sub_501960(925, a1, 2, *(_DWORD*)(a1 + 36));
        return 0;
    }
    if (sub_419E60(a1))
        goto LABEL_36;
    if (*(_BYTE*)(v3 + 12) & 0x10 && *(_DWORD*)(a1 + 556))
    {
        if (!(*(_BYTE*)(a1 + 8) & 4))
            goto LABEL_17;
        v7 = *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251);
        if (v7)
        {
            if (v7 == 1)
            {
                v8 = (double)v17 * *(float*)& byte_587000[312816];
            }
            else
            {
                if (v7 != 2)
                    goto LABEL_17;
                v8 = (double)v17 * *(float*)& byte_587000[312800];
            }
        }
        else
        {
            v8 = (double)v17 * *(float*)& byte_587000[312784];
        }
        v15 = v8;
        v5 = sub_419A70(v15);
        v17 = v5;
        LABEL_17:
        if (v5 + **(unsigned __int16**)(a1 + 556) < *(unsigned __int16*)(*(_DWORD*)(a1 + 556) + 4))
        {
            sub_4EE460(a1, v5);
            sub_501960(754, a1, 0, 0);
            v16 = 1;
        }
    }
    if (!(*(_BYTE*)(v3 + 12) & 0x20) || !(*(_BYTE*)(a1 + 8) & 4))
        goto LABEL_30;
    v9 = *(_DWORD*)(a1 + 748);
    v10 = *(_BYTE*)(*(_DWORD*)(v9 + 276) + 2251);
    if (v10)
    {
        if (v10 == 1)
        {
            v11 = (double)v17 * *(float*)& byte_587000[312820];
        }
        else
        {
            if (v10 != 2)
                goto LABEL_28;
            v11 = (double)v17 * *(float*)& byte_587000[312804];
        }
    }
    else
    {
        v11 = (double)v17 * *(float*)& byte_587000[312788];
    }
    v14 = v11;
    v5 = sub_419A70(v14);
    LABEL_28:
    if (v5 + *(unsigned __int16*)(v9 + 4) < *(unsigned __int16*)(v9 + 8))
    {
        sub_4EEB80(a1, v5);
        sub_501960(755, a1, 0, 0);
        v16 = 1;
    }
    LABEL_30:
    if (*(_BYTE*)(v3 + 12) & 0x40 && *(_BYTE*)(a1 + 8) & 4 && *(_BYTE*)(a1 + 540))
    {
        sub_4EE9D0(a1);
        v12 = sub_424800(14, 1);
        sub_501960(v12, a1, 0, 0);
        sub_4E5CC0(v3);
        return 1;
    }
    if (v16)
    {
        sub_4E5CC0(v3);
        return 1;
    }
    LABEL_36:
    sub_5116F0(v3);
    v13 = sub_4F31E0(a1, v3, a3);
    if (v13 == 1)
        sub_501960(832, a1, 0, 0);
    return v13;
}

//----- (004F3A60) --------------------------------------------------------
int __cdecl sub_4F3A60(int a1, int a2, int a3)
{
    int* v3; // edi
    wchar_t* v4; // eax
    int result; // eax
    int v6; // edi
    int v7; // [esp-8h] [ebp-10h]

    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v3 = *(int**)(a2 + 692);
        sub_4FA590(a1, *v3);
        sub_4E5CC0(a2);
        v7 = *v3;
        v4 = loadString_sub_40F1D0((char*)& byte_587000[215812], 0, "C:\\NoxPost\\src\\Server\\Object\\pickdrop\\pickup.c", 709);
        sub_4D9EB0(a1, v4, v7);
        sub_501960(307, a1, 0, 0);
        result = 1;
    }
    else
    {
        v6 = sub_4F31E0(a1, a2, a3);
        if (v6)
            sub_501960(307, a1, 0, 0);
        result = v6;
    }
    return result;
}

//----- (004F3B00) --------------------------------------------------------
int __cdecl sub_4F3B00(int a1, int a2, int a3, int a4)
{
    int v4; // ebp
    int v5; // eax
    int v6; // ebx
    int v7; // esi
    _DWORD* v8; // edi
    char* v9; // eax
    _DWORD* v10; // ecx
    int v11; // edx
    int v12; // ebp
    int v13; // edi
    char v15; // bl
    char v16; // dl
    char v17; // dl
    int v18; // [esp+10h] [ebp-10h]
    unsigned __int8* v19; // [esp+14h] [ebp-Ch]
    _DWORD* v20; // [esp+18h] [ebp-8h]
    int v21; // [esp+1Ch] [ebp-4h]

    v4 = a2;
    v5 = sub_415820(a2);
    v6 = a1;
    v18 = v5;
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return sub_53A720(v6, v4, a3, a4);
    v21 = *(_DWORD*)(a1 + 748);
    if (!(v5 & 0x82))
        return sub_53A720(v6, v4, a3, a4);
    v7 = *(_DWORD*)(a1 + 504);
    v8 = *(_DWORD * *)(a2 + 692);
    v20 = *(_DWORD * *)(a2 + 692);
    v19 = *(unsigned __int8**)(a2 + 736);
    if (!v7)
        return sub_53A720(v6, v4, a3, a4);
    while (1)
    {
        if (*(_WORD*)(v7 + 4) != *(_WORD*)(v4 + 4) || !(*(_DWORD*)(v7 + 8) & 0x1000000) || !(sub_415820(v7) & v18))
            goto LABEL_15;
        v9 = *(char**)(v7 + 736);
        v10 = v8;
        v11 = *(_DWORD*)(v7 + 692) - (_DWORD)v8;
        v12 = 1;
        v13 = 4;
        do
        {
            if (*(_DWORD*)((char*)v10 + v11) != *v10)
                v12 = 0;
            ++v10;
            --v13;
        } while (v13);
        if (v12 == 1 && !v9[2] && *v19 + (unsigned __int8)* v9 <= 250)
            break;
        v6 = a1;
        v4 = a2;
        v8 = v20;
        LABEL_15:
        v7 = *(_DWORD*)(v7 + 496);
        if (!v7)
            return sub_53A720(v6, v4, a3, a4);
    }
    v15 = v19[1] + v9[1];
    v16 = *v9;
    v9[1] = v15;
    v17 = *v19 + v16;
    *v9 = v17;
    sub_4D82B0(*(unsigned __int8*)(*(_DWORD*)(v21 + 276) + 2064), (_DWORD*)v7, v15, v17);
    sub_4E5CC0(a2);
    sub_53A6C0(a1, a2);
    return 1;
}

//----- (004F3C60) --------------------------------------------------------
int __cdecl sub_4F3C60(int a1, int a2, int a3)
{
    int v4; // ebx

    if (sub_40A5C0(6144))
        sub_53F8E0(a1, a2);
    if (*(_BYTE*)(a2 + 16) & 0x20)
        return 1;
    v4 = sub_4F31E0(a1, a2, a3);
    if (v4)
    {
        if (*(_BYTE*)(a2 + 12) & 1)
        {
            sub_501960(826, a1, 0, 0);
            return v4;
        }
        sub_501960(828, a1, 0, 0);
    }
    return v4;
}

//----- (004F3CE0) --------------------------------------------------------
int __cdecl sub_4F3CE0(int a1, int a2, int a3)
{
    int v4; // esi

    if (sub_40A5C0(6144))
        sub_53F8E0(a1, a2);
    if (*(_BYTE*)(a2 + 16) & 0x20)
        return 1;
    v4 = sub_4F31E0(a1, a2, a3);
    if (v4)
        sub_501960(826, a1, 0, 0);
    return v4;
}

//----- (004F3D50) --------------------------------------------------------
int __cdecl sub_4F3D50(int a1, int a2, int a3)
{
    int v3; // ebx
    __int16 v4; // ax
    unsigned __int8* v5; // ecx

    if (!a1 || !a2)
        return 0;
    v3 = sub_4F31E0(a1, a2, a3);
    if (v3)
    {
        v4 = *(_WORD*)& byte_5D4594[3815404];
        v5 = &byte_5D4594[3815404];
        if (*(short*)& byte_5D4594[3815404] != -1)
        {
            while (v4 != *(_WORD*)(a2 + 4))
            {
                v4 = *((_WORD*)v5 + 2);
                v5 += 4;
                if (v4 == -1)
                    return v3;
            }
            sub_501960(*((unsigned __int16*)v5 + 1), a1, 0, 0);
        }
    }
    return v3;
}

//----- (004F3DD0) --------------------------------------------------------
int __cdecl sub_4F3DD0(int a1, int a2)
{
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    ++* (_DWORD*)(*(_DWORD*)(a1 + 748) + 320);
    sub_4E5CC0(a2);
    sub_501960(1004, a1, 0, 0);
    return 1;
}

//----- (004F3E20) --------------------------------------------------------
void sub_4F3E20()
{
    nox_srand(0x4E2Au);
}

//----- (004F3E30) --------------------------------------------------------
int __cdecl sub_4F3E30(unsigned __int16 a1, int a2, int a3)
{
    int v3; // ebp
    unsigned __int16 v4; // si
    _DWORD* v5; // eax
    _DWORD* v6; // esi
    int v7; // edx
    int v8; // eax
    int v10; // [esp+10h] [ebp-10Ch]
    int v11; // [esp+14h] [ebp-108h]
    int v12; // [esp+18h] [ebp-104h]
    char v13[256]; // [esp+1Ch] [ebp-100h]

    v3 = 0;
    if (a3 <= 0)
        return 1;
    while (1)
    {
        if (a1 < 0x3Cu)
        {
            sub_426AC0(&v10, 1u);
            sub_426AC0(v13, (unsigned __int8)v10);
            v13[(unsigned __int8)v10] = 0;
            v4 = sub_4E3AA0(v13);
            if (!v4)
                return 0;
        }
        else
        {
            sub_426AC0(&v11, 2u);
            v4 = sub_42C2B0(v11);
            if (!v4)
                return 0;
        }
        sub_426C20(&v12, 4u);
        v5 = sub_4E3450(v4);
        v6 = v5;
        if (!v5 || !((int(__cdecl*)(_DWORD*, _DWORD))v5[176])(v5, 0))
            break;
        v7 = *(_DWORD*)(a2 + 504);
        v6[125] = 0;
        v6[124] = v7;
        v8 = *(_DWORD*)(a2 + 504);
        if (v8)
            * (_DWORD*)(v8 + 500) = v6;
        ++v3;
        *(_DWORD*)(a2 + 504) = v6;
        v6[123] = a2;
        if (v3 >= a3)
            return 1;
    }
    return 0;
}
// 4F3E30: using guessed type char var_100[256];

//----- (004F3F50) --------------------------------------------------------
int __cdecl sub_4F3F50(int a1, int a2, int* a3)
{
    int v3; // eax
    int v4; // edi
    int result; // eax
    char* v6; // eax
    int v7; // eax
    int v8; // edi

    if (sub_40A5C0(0x400000) || sub_4E3BA0(*(unsigned __int16*)(a1 + 4)))
    {
        if (a3)
        {
            v6 = sub_426A70();
            *(float*)(a1 + 56) = *(float*)(a1 + 56) - (double)(int)(23 * *(_DWORD*)v6) + (double)* a3 - 11.0;
            *(float*)(a1 + 60) = *(float*)(a1 + 60) - (double)(int)(23 * *((_DWORD*)v6 + 1)) + (double)a3[1] - 11.0;
        }
        if (sub_40A5C0(0x400000))
        {
            sub_5048A0(a1);
            result = 1;
        }
        else if (sub_40A5C0(0x200000) || sub_4E3AD0(*(unsigned __int16*)(a1 + 4)))
        {
            sub_4DAA50(a1, a2, *(float*)(a1 + 56), *(float*)(a1 + 60));
            result = 1;
        }
        else
        {
            v7 = *(_DWORD*)(a1 + 504);
            if (v7)
            {
                do
                {
                    v8 = *(_DWORD*)(v7 + 496);
                    sub_4E38A0(v7);
                    v7 = v8;
                } while (v8);
            }
            *(_DWORD*)(a1 + 504) = 0;
            sub_4E38A0(a1);
            result = 0;
        }
    }
    else
    {
        v3 = *(_DWORD*)(a1 + 504);
        if (v3)
        {
            do
            {
                v4 = *(_DWORD*)(v3 + 496);
                sub_4E38A0(v3);
                v3 = v4;
            } while (v4);
        }
        sub_4E38A0(a1);
        result = 0;
    }
    return result;
}

//----- (004F40A0) --------------------------------------------------------
char __cdecl sub_4F40A0(int a1)
{
    int v2; // eax
    const char* v3; // esi

    if (a1)
    {
        if (*(_DWORD*)a1)
            return -1;
        if (*(_DWORD*)(a1 + 504))
            return -1;
        if (*(_DWORD*)(a1 + 516))
            return -1;
        if (*(_BYTE*)(a1 + 52))
            return -1;
        v2 = sub_4E3B70(*(unsigned __int16*)(a1 + 4));
        if ((*(_DWORD*)(a1 + 16) ^ *(_DWORD*)(v2 + 32)) & 0x11408162)
            return -1;
        if ((*(_BYTE*)(a1 + 20) ^ *(_BYTE*)(v2 + 36)) & 0x5E)
            return -1;
        if (sub_40A5C0(6291456))
        {
            v3 = *(const char**)(a1 + 756);
            if (v3 && strlen(v3))
                return -1;
        }
        else if (sub_40A5C0(1) && *(int*)(a1 + 768) != -1)
        {
            return -1;
        }
    }
    return 0;
}

//----- (004F4170) --------------------------------------------------------
int __cdecl sub_4F4170(int a1, int a2, int a3)
{
    _BYTE** v3; // esi
    _BYTE* v4; // ebx
    unsigned int v5; // edx
    _BYTE* v6; // eax
    int v7; // eax
    int v8; // ebx
    int v9; // ebp
    _DWORD* v10; // edi
    _BYTE* v11; // edx
    int result; // eax
    _BYTE* v13; // eax
    int* v14; // ebx
    _BYTE* v15; // edi
    unsigned __int16 v16; // ax
    _BYTE* j; // edi
    unsigned int i; // edi
    int v19; // [esp+10h] [ebp-18h]
    int v20; // [esp+14h] [ebp-14h]
    int v21; // [esp+18h] [ebp-10h]
    int v22; // [esp+1Ch] [ebp-Ch]
    int v23[2]; // [esp+20h] [ebp-8h]

    v3 = (_BYTE * *)a1;
    LOBYTE(v20) = 0;
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        * (_DWORD*)(a1 + 136) = 0;
    sub_426AC0((_BYTE*)v3 + 40, 4u);
    v4 = v3[4];
    v21 = (unsigned int)v3[4] & 0x11408162;
    sub_426AC0(&v21, 4u);
    v5 = (unsigned int)v3[4] & 0xEEBF7E9D;
    v3[4] = (_BYTE*)v5;
    v6 = (_BYTE*)v5;
    if ((unsigned __int8)v4 & 0x40)
    {
        LOBYTE(v6) = v5 | 0x40;
        v3[4] = v6;
    }
    v7 = v21;
    v3[4] = (_BYTE*)(v21 | (unsigned int)v3[4]);
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
    {
        if (v7 & 0x1000000)
            sub_4E75B0((int)v3);
        else
            sub_4E7600((int)v3);
    }
    v8 = a3;
    v9 = a2;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if (a3 < 40 || a2 < 4)
        {
            sub_426AC0(v23, 8u);
            v10 = v3 + 14;
            *((float*)v3 + 14) = (double)v23[0];
            *((float*)v3 + 15) = (double)v23[1];
        }
        else
        {
            v10 = v3 + 14;
            sub_426AC0((_BYTE*)v3 + 56, 4u);
            sub_426AC0((_BYTE*)v3 + 60, 4u);
        }
        v11 = (_BYTE*)v10[1];
        v3[16] = (_BYTE*)* v10;
        v3[17] = v11;
    }
    else
    {
        sub_426AC0((_BYTE*)v3 + 56, 4u);
        sub_426AC0((_BYTE*)v3 + 60, 4u);
    }
    if (v8 >= 10)
    {
        if (*v3)
            LOBYTE(v19) = strlen(*v3);
        else
            LOBYTE(v19) = 0;
        sub_426AC0(&v19, 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            if ((_BYTE)v19)
            {
                result = (int)nox_malloc((unsigned __int8)v19 + 1);
                *v3 = (_BYTE*)result;
                if (!result)
                    return result;
            }
        }
        sub_426AC0(*v3, (unsigned __int8)v19);
        if (*v3)
            (*v3)[(unsigned __int8)v19] = 0;
    }
    if (v8 >= 20)
        sub_426AC0((_BYTE*)v3 + 52, 1u);
    if (v8 >= 30)
    {
        v13 = v3[126];
        for (LOBYTE(v20) = 0; v13; LOBYTE(v20) = v20 + 1)
            v13 = (_BYTE*) * ((_DWORD*)v13 + 124);
        sub_426AC0(&v20, 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            v3[34] = (_BYTE*)(unsigned __int8)v20;
    }
    if (v8 >= 40)
    {
        v14 = (int*)(v3 + 11);
        sub_426AC0((_BYTE*)v3 + 44, 4u);
        if (!v3[11] && *(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
            * v14 = (*(_DWORD*)& byte_587000[201376])++;
        if (v9 >= 2)
        {
            v15 = v3[129];
            v16 = 0;
            a1 = 0;
            if (v15)
            {
                do
                {
                    if (!(v15[16] & 0x20) && sub_4E3B80(*((unsigned __int16*)v15 + 2)))
                        ++a1;
                    v15 = (_BYTE*) * ((_DWORD*)v15 + 128);
                } while (v15);
                v16 = a1;
            }
            if (v9 < 5)
            {
                v22 = v16;
                sub_426AC0(&v22, 4u);
                a1 = v22;
            }
            else
            {
                sub_426AC0(&a1, 2u);
            }
            if (*(_DWORD*)& byte_5D4594[3803300])
            {
                for (i = 0; i < (unsigned __int16)a1; ++i)
                {
                    sub_426AC0(&a3, 4u);
                    if (!sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
                        sub_516F90(*v14, a3);
                }
            }
            else
            {
                for (j = v3[129]; j; j = (_BYTE*) * ((_DWORD*)j + 128))
                {
                    if (!(j[16] & 0x20) && sub_4E3B80(*((unsigned __int16*)j + 2)))
                        sub_426AC0(j + 44, 4u);
                }
            }
        }
        if (v9 >= 3)
        {
            v21 = (unsigned int)v3[5] & 0x5E;
            sub_426AC0(&v21, 4u);
            sub_4E4780((int)v3, 94);
            sub_4E4800((int)v3, (int*)v21);
        }
    }
    return 1;
}

//----- (004F4530) --------------------------------------------------------
int __cdecl sub_4F4530(int* a1, int a2)
{
    int* v2; // esi
    int v3; // edi
    int v4; // ecx
    __int16 v5; // ax
    int result; // eax
    int* v7; // ebp
    int* v8; // edi
    int v9; // ecx
    int v10; // ebx
    unsigned int v11; // edx
    unsigned int v12; // eax
    int v13; // eax
    int v14; // eax
    int v15; // edi
    int k; // edi
    unsigned int j; // edi
    int v18; // [esp+10h] [ebp-1Ch]
    int v19; // [esp+14h] [ebp-18h]
    int i; // [esp+18h] [ebp-14h]
    int v21; // [esp+1Ch] [ebp-10h]
    int v22[2]; // [esp+20h] [ebp-Ch]
    int v23; // [esp+28h] [ebp-4h]

    v2 = a1;
    v3 = a2;
    v4 = a1[34];
    v5 = 0;
    LOBYTE(v19) = 0;
    v18 = 0;
    v23 = v4;
    if (a2 >= 40 || !*(_DWORD*)& byte_5D4594[3803300])
    {
        v18 = 64;
        sub_426AC0(&v18, 2u);
        v5 = v18;
        if ((__int16)v18 > 64)
            return 0;
    }
    if (v3 < 40 || v5 < 61)
        return sub_4F4170((int)v2, v5, v3);
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        v2[34] = 0;
    sub_426AC0((_BYTE*)v2 + 40, 4u);
    v7 = v2 + 11;
    sub_426AC0((_BYTE*)v2 + 44, 4u);
    if (!v2[11] && *(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
        * v7 = (*(_DWORD*)& byte_587000[201376])++;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if ((__int16)v18 < 4)
        {
            sub_426AC0(v22, 8u);
            v8 = v2 + 14;
            *((float*)v2 + 14) = (double)v22[0];
            *((float*)v2 + 15) = (double)v22[1];
        }
        else
        {
            v8 = v2 + 14;
            sub_426AC0((_BYTE*)v2 + 56, 4u);
            sub_426AC0((_BYTE*)v2 + 60, 4u);
        }
        v9 = v8[1];
        v2[16] = *v8;
        v2[17] = v9;
    }
    else
    {
        sub_426AC0((_BYTE*)v2 + 56, 4u);
        sub_426AC0((_BYTE*)v2 + 60, 4u);
    }
    LOBYTE(a1) = sub_4F40A0((int)v2);
    sub_426AC0(&a1, 1u);
    if (!(_BYTE)a1)
        return 1;
    v10 = v2[4];
    v21 = v2[4] & 0x11408162;
    sub_426AC0(&v21, 4u);
    v11 = v2[4] & 0xEEBF7E9D;
    v2[4] = v11;
    v12 = v11;
    if (v10 & 0x40)
    {
        LOBYTE(v12) = v11 | 0x40;
        v2[4] = v12;
    }
    v13 = v21;
    v2[4] |= v21;
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
    {
        if (v13 & 0x1000000)
            sub_4E75B0((int)v2);
        else
            sub_4E7600((int)v2);
    }
    if (*v2)
        LOBYTE(a2) = strlen((const char*)* v2);
    else
        LOBYTE(a2) = 0;
    sub_426AC0(&a2, 1u);
    if (*(_DWORD*)& byte_5D4594[3803300] != 1
        || !(_BYTE)a2
        || (result = (int)nox_malloc((unsigned __int8)a2 + 1), (*v2 = result) != 0))
    {
        sub_426AC0((_BYTE*)* v2, (unsigned __int8)a2);
        if (*v2)
            * (_BYTE*)((unsigned __int8)a2 + *v2) = 0;
        sub_426AC0((_BYTE*)v2 + 52, 1u);
        v14 = v2[126];
        for (LOBYTE(v19) = 0; v14; LOBYTE(v19) = v19 + 1)
            v14 = *(_DWORD*)(v14 + 496);
        sub_426AC0(&v19, 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            v2[34] = (unsigned __int8)v19;
        v15 = v2[129];
        for (i = 0; v15; v15 = *(_DWORD*)(v15 + 512))
        {
            if (!(*(_BYTE*)(v15 + 16) & 0x20) && sub_4E3B80(*(unsigned __int16*)(v15 + 4)))
                ++i;
        }
        sub_426AC0(&i, 2u);
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            for (j = 0; j < (unsigned __int16)i; ++j)
            {
                sub_426AC0(v22, 4u);
                if (!sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
                    sub_516F90(*v7, v22[0]);
            }
        }
        else
        {
            for (k = v2[129]; k; k = *(_DWORD*)(k + 512))
            {
                if (!(*(_BYTE*)(k + 16) & 0x20) && sub_4E3B80(*(unsigned __int16*)(k + 4)))
                    sub_426AC0((_BYTE*)(k + 44), 4u);
            }
        }
        v21 = v2[5] & 0x5E;
        sub_426AC0(&v21, 4u);
        sub_4E4780((int)v2, 94);
        sub_4E4800((int)v2, (int*)v21);
        if ((__int16)v18 < 63 || (result = sub_4F5580((int)(v2 + 191), (char*)v2[189])) != 0)
        {
            if ((__int16)v18 >= 64)
            {
                v22[0] = v23 - *(_DWORD*)& byte_5D4594[2598000];
                sub_426AC0(v22, 4u);
                if (v22[0] > 0 && *(_DWORD*)& byte_5D4594[3803300] == 1)
                {
                    if (v2[4] & 0x400000)
                        v2[32] = v22[0];
                }
            }
            return 1;
        }
    }
    return result;
}

//----- (004F49A0) --------------------------------------------------------
int __cdecl sub_4F49A0(int a1)
{
    int* v1; // esi
    int v2; // edi
    int result; // eax

    v1 = (int*)a1;
    v2 = *(_DWORD*)(a1 + 136);
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v2;
            result = 1;
        }
    }
    return result;
}

//----- (004F4A20) --------------------------------------------------------
int __cdecl sub_4F4A20(int a1)
{
    int v1; // esi
    int v2; // edi
    int result; // eax

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 136);
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)a1);
    if (result)
    {
        sub_426AC0(*(_BYTE * *)(v1 + 700), 4u);
        if (!*(_DWORD*)(v1 + 136)
            || *(_DWORD*)& byte_5D4594[3803300] != 1
            || (result = sub_4F3E30(a1, v1, *(_DWORD*)(v1 + 136))) != 0)
        {
            *(_DWORD*)(v1 + 136) = v2;
            result = 1;
        }
    }
    return result;
}

//----- (004F4AB0) --------------------------------------------------------
int __cdecl sub_4F4AB0(int a1)
{
    int* v1; // esi
    int v2; // ebx
    int v3; // edi
    int result; // eax
    size_t v5; // [esp+Ch] [ebp-4h]

    v1 = (int*)a1;
    v2 = *(_DWORD*)(a1 + 736);
    v3 = *(_DWORD*)(a1 + 136);
    v5 = strlen(*(const char**)(a1 + 736)) + 1;
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if ((__int16)a1 >= 2)
        {
            sub_426AC0(&v5, 4u);
            sub_426AC0((_BYTE*)v2, v5);
        }
        else
        {
            sub_426AC0((_BYTE*)v2, v5);
        }
        if (*(_DWORD*)& byte_5D4594[3803300] != 1
            || (*(_DWORD*)(v2 + 256) = 0, !v1[34])
            || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F4B90) --------------------------------------------------------
int __cdecl sub_4F4B90(int a1)
{
    int* v1; // ebp
    _BYTE* v2; // ebx
    int v3; // edi
    int result; // eax
    _BYTE* i; // esi
    size_t v6; // [esp+Ch] [ebp-4h]

    v1 = (int*)a1;
    v2 = *(_BYTE * *)(a1 + 700);
    v3 = *(_DWORD*)(a1 + 136);
    v6 = strlen(*(const char**)(a1 + 700)) + 1;
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if ((__int16)a1 >= 2)
        {
            sub_426AC0(&v6, 4u);
            sub_426AC0(v2, v6);
        }
        else if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            for (i = v2; ; ++i)
            {
                sub_426AC0(i, 1u);
                if (!*i)
                    break;
            }
        }
        else
        {
            sub_426AC0(v2, v6);
        }
        if ((__int16)a1 >= 31)
        {
            sub_426AC0(v2 + 80, 4u);
            sub_426AC0(v2 + 84, 4u);
        }
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F4CB0) --------------------------------------------------------
int __cdecl sub_4F4CB0(int a1)
{
    int v1; // edi
    int v2; // esi
    int result; // eax
    int v4; // ebx
    int v5; // ebp
    int v6; // [esp+8h] [ebp-14h]
    int v7; // [esp+Ch] [ebp-10h]
    int v8; // [esp+10h] [ebp-Ch]
    int v9; // [esp+14h] [ebp-8h]
    int v10; // [esp+18h] [ebp-4h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 748);
    v10 = *(_DWORD*)(a1 + 136);
    v7 = 60;
    sub_426AC0(&v7, 2u);
    if ((__int16)v7 > 60)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)v7);
    if (result)
    {
        if (!*(_DWORD*)& byte_5D4594[3803300])
        {
            a1 = *(_DWORD*)(v2 + 12);
            v8 = *(unsigned __int8*)(v2 + 1);
            v6 = *(_DWORD*)(v2 + 4);
        }
        sub_426AC0(&a1, 4u);
        sub_426AC0(&v8, 4u);
        if ((__int16)v7 < 41)
            v6 = a1;
        else
            sub_426AC0(&v6, 4u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            *(_DWORD*)(v2 + 12) = a1;
            *(_WORD*)(v2 + 40) = (a1 << 8) / 32;
            *(_DWORD*)(v2 + 4) = v6;
            *(_DWORD*)(v2 + 8) = a1;
            v9 = *(int*)& byte_587000[8 * v6 + 196184] / 2;
            v4 = (__int64)(((double)v9 + *(float*)(v1 + 56)) * 0.043478262);
            v9 = *(int*)& byte_587000[8 * v6 + 196188] / 2;
            v5 = (__int64)(((double)v9 + *(float*)(v1 + 60)) * 0.043478262);
            sub_410360(v1, v4, v5);
            *(_DWORD*)(v2 + 16) = v4;
            *(_DWORD*)(v2 + 20) = v5;
            *(_BYTE*)(v2 + 1) = v8;
        }
        if (!*(_DWORD*)(v1 + 136)
            || *(_DWORD*)& byte_5D4594[3803300] != 1
            || (result = sub_4F3E30(v7, v1, *(_DWORD*)(v1 + 136))) != 0)
        {
            *(_DWORD*)(v1 + 136) = v10;
            result = 1;
        }
    }
    return result;
}

//----- (004F4E50) --------------------------------------------------------
int __cdecl sub_4F4E50(float a1)
{
    int v1; // edi
    _BYTE* v2; // esi
    int result; // eax
    double v4; // st7
    double v5; // st7
    double v6; // st7
    char* v7; // ebp
    char* v8; // eax
    char* v9; // eax
    char* v10; // eax
    int v11; // [esp+Ch] [ebp-Ch]
    int v12; // [esp+10h] [ebp-8h]
    int v13; // [esp+14h] [ebp-4h]

    v1 = LODWORD(a1);
    v2 = *(_BYTE * *)(LODWORD(a1) + 748);
    v13 = *(_DWORD*)(LODWORD(a1) + 136);
    v11 = 61;
    sub_426AC0(&v11, 2u);
    if ((__int16)v11 > 61)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)v11);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            sub_426AC0(&a1, 4u);
            sub_426AC0(&v12, 4u);
            v5 = (double)SLODWORD(a1);
            a1 = v5;
            *(float*)(v1 + 184) = v5;
            v6 = (double)v12;
            *(float*)(v1 + 188) = v6;
            if (a1 > 60.0)
                * (_DWORD*)(v1 + 184) = 1114636288;
            if (v6 > 60.0)
                * (_DWORD*)(v1 + 188) = 1114636288;
        }
        else
        {
            v4 = *(float*)(v1 + 188);
            LODWORD(a1) = (__int64) * (float*)(v1 + 184);
            v12 = (__int64)v4;
            sub_426AC0(&a1, 4u);
            sub_426AC0(&v12, 4u);
        }
        sub_428270((shape*)(v1 + 172));
        if ((__int16)v11 < 41)
        {
            sub_426AC0(&a1, 3u);
            sub_426AC0(&a1, 3u);
            sub_426AC0(&a1, 3u);
        }
        else
        {
            sub_426AC0(v2 + 54, 1u);
            sub_426AC0(v2 + 55, 1u);
            sub_426AC0(v2 + 56, 1u);
            sub_426AC0(v2 + 57, 1u);
            sub_426AC0(v2 + 58, 1u);
            sub_426AC0(v2 + 59, 1u);
        }
        sub_426AC0(v2, 4u);
        if ((__int16)v11 >= 3)
        {
            v7 = *(char**)(v1 + 756);
            if (v7)
                v8 = v7 + 256;
            else
                v8 = 0;
            sub_4F5580((int)(v2 + 20), v8);
            if (v7)
                v9 = v7 + 384;
            else
                v9 = 0;
            sub_4F5580((int)(v2 + 28), v9);
            if ((__int16)v11 >= 31)
            {
                if (v7)
                    v10 = v7 + 512;
                else
                    v10 = 0;
                sub_4F5580((int)(v2 + 12), v10);
            }
        }
        else
        {
            sub_4F5540((int)(v2 + 20));
            sub_4F5540((int)(v2 + 28));
        }
        if (*(_DWORD*)& byte_5D4594[3803300] == 1 && (__int16)v11 < 31)
        {
            sub_426AC0(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
            sub_426AC0(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
            sub_426AC0(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
            sub_426AC0(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
        }
        sub_426AC0(v2 + 44, 4u);
        sub_426AC0(v2 + 48, 4u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            v2[52] = 0;
            v2[53] = 0;
        }
        if (!*(_DWORD*)& byte_5D4594[3803300] || (__int16)v11 >= 21)
        {
            sub_426AC0(v2 + 52, 1u);
            sub_426AC0(v2 + 53, 1u);
        }
        if ((__int16)v11 >= 61)
        {
            sub_426AC0(v2 + 8, 1u);
            sub_426AC0(v2 + 9, 1u);
            sub_426AC0((_BYTE*)(v1 + 132), 4u);
            if (*(_DWORD*)& byte_5D4594[3803300] == 1)
                sub_4E4880(v1, *(_DWORD*)(v1 + 132));
        }
        if (!*(_DWORD*)(v1 + 136)
            || *(_DWORD*)& byte_5D4594[3803300] != 1
            || (result = sub_4F3E30(v11, v1, *(_DWORD*)(v1 + 136))) != 0)
        {
            result = 1;
            *(_DWORD*)(v1 + 136) = v13;
        }
    }
    return result;
}

//----- (004F51D0) --------------------------------------------------------
int __cdecl sub_4F51D0(int a1)
{
    int* v1; // edi
    int v2; // ebx
    int v3; // esi
    int result; // eax
    char* v5; // eax
    int v6; // [esp+Ch] [ebp-4h]

    v1 = (int*)a1;
    v2 = *(_DWORD*)(a1 + 756);
    v3 = *(_DWORD*)(a1 + 700);
    v6 = *(_DWORD*)(a1 + 136);
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if ((__int16)a1 < 42)
            * (_DWORD*)(v3 + 24) = 0;
        else
            sub_426AC0((_BYTE*)(v3 + 24), 4u);
        if ((__int16)a1 < 41)
        {
            sub_426AC0((_BYTE*)(v3 + 8), 8u);
            *(_DWORD*)(v3 + 4) = -1;
            *(_DWORD*)v3 = 0;
            *(_DWORD*)(v3 + 16) = 0;
            *(_WORD*)(v3 + 20) = 0;
        }
        else
        {
            if (v2)
                v5 = (char*)(v2 + 128);
            else
                v5 = 0;
            sub_4F5580(v3, v5);
            sub_426AC0((_BYTE*)(v3 + 8), 8u);
            sub_426AC0((_BYTE*)(v3 + 16), 4u);
            sub_426AC0((_BYTE*)(v3 + 20), 2u);
        }
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            result = 1;
            v1[34] = v6;
        }
    }
    return result;
}

//----- (004F5300) --------------------------------------------------------
int __cdecl sub_4F5300(int a1)
{
    int* v1; // esi
    int v2; // edi
    int v3; // ebx
    int result; // eax
    int v5; // [esp+Ch] [ebp-4h]

    v1 = (int*)a1;
    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(_DWORD*)(a1 + 136);
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            sub_426AC0((_BYTE*)(v2 + 16), 4u);
        }
        else
        {
            if (*(_DWORD*)(v2 + 12))
                v5 = *(_DWORD*)(v2 + 16);
            else
                v5 = 0;
            sub_426AC0(&v5, 4u);
        }
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F53D0) --------------------------------------------------------
int __cdecl sub_4F53D0(int a1)
{
    int* v1; // esi
    _BYTE* v2; // edi
    int v3; // ebx
    int result; // eax

    v1 = (int*)a1;
    v2 = *(_BYTE * *)(a1 + 748);
    v3 = *(_DWORD*)(a1 + 136);
    a1 = 61;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 61)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0(v2 + 8, 4u);
        if ((__int16)a1 >= 41)
            sub_426AC0(v2 + 16, 4u);
        if ((__int16)a1 >= 61)
            sub_426AC0(v2 + 12, 1u);
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F54A0) --------------------------------------------------------
int __cdecl sub_4F54A0(int a1)
{
    int* v1; // esi
    int v2; // edi
    int v3; // ebx
    int result; // eax

    v1 = (int*)a1;
    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(_DWORD*)(a1 + 136);
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0((_BYTE*)(v2 + 8), 4u);
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F5540) --------------------------------------------------------
int __cdecl sub_4F5540(int a1)
{
    int result; // eax
    FILE* v2; // eax

    result = *(_DWORD*)& byte_5D4594[3803300];
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
    {
        v2 = sub_426A60();
        sub_502790(v2, (char*)a1);
        result = sub_40A5C0(0x400000);
        if (!result)
            * (_DWORD*)(a1 + 4) = -1;
    }
    return result;
}

//----- (004F5580) --------------------------------------------------------
int __cdecl sub_4F5580(int a1, char* a2)
{
    bool v3; // zf
    int v4; // eax
    size_t v5; // [esp+Ch] [ebp-408h]
    int v6; // [esp+10h] [ebp-404h]
    char v7[1024]; // [esp+14h] [ebp-400h]

    v6 = 1;
    sub_426AC0(&v6, 2u);
    if ((__int16)v6 > 1)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
    {
        sub_426AC0(&v5, 4u);
        if (v5 >= 0x400)
            return 0;
        sub_426AC0(v7, v5);
        v3 = v5 == 0;
        v7[v5] = 0;
        if (!v3)
        {
            if (sub_40A5C0(6291456))
                strcpy(a2, v7);
            else
                *(_DWORD*)(a1 + 4) = sub_5071D0(v7);
        }
    }
    else
    {
        if (sub_40A5C0(6291456))
        {
            if (a2)
            {
                v5 = strlen(a2);
                sub_426AC0(&v5, 4u);
                sub_426AC0(a2, v5);
                goto LABEL_16;
            }
        }
        else
        {
            v4 = *(_DWORD*)(a1 + 4);
            if (v4 != -1)
            {
                v5 = strlen(*(const char**)(48 * v4 + *(_DWORD*)& byte_5D4594[1599636]));
                sub_426AC0(&v5, 4u);
                sub_426AC0(*(_BYTE * *)(48 * *(_DWORD*)(a1 + 4) + *(_DWORD*)& byte_5D4594[1599636]), v5);
                goto LABEL_16;
            }
        }
        v5 = 0;
        sub_426AC0(&v5, 4u);
    }
    LABEL_16:
    sub_426AC0((_BYTE*)a1, 4u);
    return 1;
}
// 4F5580: using guessed type char var_400[1024];

//----- (004F5730) --------------------------------------------------------
int __cdecl sub_4F5730(int a1)
{
    int v1; // edi
    int v2; // esi
    int v3; // ebp
    int result; // eax
    int* v5; // eax
    int* v6; // esi
    int v7; // [esp+Ch] [ebp-4h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(_DWORD*)(a1 + 136);
    v7 = 60;
    sub_426AC0(&v7, 2u);
    if ((__int16)v7 > 60)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)v7);
    if (result)
    {
        sub_426AC0((_BYTE*)(v2 + 4), 4u);
        sub_426AC0((_BYTE*)(v2 + 8), 4u);
        sub_426AC0((_BYTE*)(v2 + 32), 4u);
        if ((__int16)v7 >= 41)
        {
            sub_426AC0((_BYTE*)v2, 1u);
            if (*(_DWORD*)& byte_5D4594[3803300])
            {
                sub_426AC0((_BYTE*)(v2 + 16), 4u);
                sub_426AC0((_BYTE*)(v2 + 24), 4u);
            }
            else
            {
                v5 = *(int**)(v2 + 12);
                a1 = 0;
                if (v5)
                    a1 = *v5;
                sub_426AC0(&a1, 4u);
                v6 = *(int**)(v2 + 20);
                a1 = 0;
                if (v6)
                    a1 = *v6;
                sub_426AC0(&a1, 4u);
            }
        }
        if ((__int16)v7 >= 42)
        {
            sub_426AC0((_BYTE*)(v1 + 548), 4u);
            sub_426AC0((_BYTE*)(v1 + 544), 4u);
        }
        if (!*(_DWORD*)(v1 + 136)
            || *(_DWORD*)& byte_5D4594[3803300] != 1
            || (result = sub_4F3E30(v7, v1, *(_DWORD*)(v1 + 136))) != 0)
        {
            *(_DWORD*)(v1 + 136) = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F5890) --------------------------------------------------------
int __cdecl sub_4F5890(int a1)
{
    int v1; // edi
    int v2; // ebp
    int v3; // eax
    int result; // eax
    _BYTE* v5; // esi
    int v6; // edi
    int* v7; // ebp
    int v8; // ebx
    char* v9; // eax
    size_t v10; // [esp-Ch] [ebp-128h]
    int v11; // [esp+8h] [ebp-114h]
    int v12; // [esp+Ch] [ebp-110h]
    int* v13; // [esp+10h] [ebp-10Ch]
    int v14; // [esp+14h] [ebp-108h]
    int v15; // [esp+18h] [ebp-104h]
    char v16[256]; // [esp+1Ch] [ebp-100h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 692);
    v3 = *(_DWORD*)(a1 + 136);
    v13 = *(int**)(a1 + 692);
    v14 = v3;
    v12 = 60;
    sub_426AC0(&v12, 2u);
    if ((__int16)v12 > 60)
        return 0;
    result = sub_4F4530((int*)a1, (__int16)v12);
    if (result)
    {
        if ((__int16)v12 < 41)
            sub_426AC0(&v15, 4u);
        sub_426AC0((_BYTE*)(a1 + 124), 1u);
        sub_426AC0((_BYTE*)(v2 + 28), 4u);
        sub_426AC0((_BYTE*)(v2 + 32), 4u);
        v5 = (_BYTE*)(v2 + 20);
        sub_426AC0((_BYTE*)(v2 + 20), 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            if ((__int16)v12 < 31)
            {
                sub_426AC0((_BYTE*)v2, 0x14u);
                goto LABEL_16;
            }
            v6 = 0;
            if (!*v5)
            {
                v1 = a1;
                v2 = (int)v13;
                goto LABEL_19;
            }
            v7 = v13;
            do
            {
                sub_426AC0(&v11, 1u);
                sub_426AC0(v16, (unsigned __int8)v11);
                v16[(unsigned __int8)v11] = 0;
                *v7 = sub_4243F0(v16);
                ++v6;
                ++v7;
            } while (v6 < (unsigned __int8)* v5);
        }
        else
        {
            v8 = 0;
            if (!*v5)
                goto LABEL_16;
            do
            {
                LOBYTE(v11) = strlen(sub_424870(*(_DWORD*)v2));
                sub_426AC0(&v11, 1u);
                v10 = (unsigned __int8)v11;
                v9 = sub_424870(*(_DWORD*)v2);
                sub_426AC0(v9, v10);
                ++v8;
                v2 += 4;
            } while (v8 < (unsigned __int8)* v5);
        }
        v1 = a1;
        v2 = (int)v13;
        LABEL_16:
        if (*(_DWORD*)& byte_5D4594[3803300] != 1)
        {
            LABEL_20:
            if (!*(_DWORD*)(v1 + 136)
                || *(_DWORD*)& byte_5D4594[3803300] != 1
                || (result = sub_4F3E30(v12, v1, *(_DWORD*)(v1 + 136))) != 0)
            {
                result = 1;
                *(_DWORD*)(v1 + 136) = v14;
            }
            return result;
        }
        LABEL_19:
        *(_WORD*)(v1 + 126) = *(_WORD*)(v1 + 124);
        *(_DWORD*)(v2 + 24) = 0;
        goto LABEL_20;
    }
    return result;
}
// 4F5890: using guessed type char var_100[256];

//----- (004F5AA0) --------------------------------------------------------
int __cdecl sub_4F5AA0(int* a1)
{
    int result; // eax
    _DWORD* v2; // eax
    int v3; // [esp+8h] [ebp-98h]
    int v4; // [esp+Ch] [ebp-94h]
    int v5; // [esp+10h] [ebp-90h]
    char v6[140]; // [esp+14h] [ebp-8Ch]

    v5 = a1[34];
    memset(v6, 0, sizeof(v6));
    v3 = 60;
    sub_426AC0(&v3, 2u);
    if ((__int16)v3 > 60)
        return 0;
    result = sub_4F4530(a1, (__int16)v3);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
            goto LABEL_14;
        if (sub_40A5C0(6291456))
        {
            v2 = (_DWORD*)sub_45A060();
            if (!v2)
                goto LABEL_14;
            while (v2[32] != a1[10])
            {
                v2 = (_DWORD*)sub_45A070((int)v2);
                if (!v2)
                    goto LABEL_14;
            }
        }
        else if (a1[2] & 0x20400000)
        {
            v2 = sub_45A720(a1[10]);
        }
        else
        {
            v2 = sub_45A6F0(a1[9]);
        }
        qmemcpy(v6, v2 + 34, sizeof(v6));
        LABEL_14:
        if ((__int16)v3 >= 2)
        {
            sub_426AC0(v6, 4u);
            sub_426AC0(&v6[4], 4u);
            sub_426AC0(&v6[8], 4u);
            sub_426AC0(&v6[12], 4u);
            sub_426AC0(&v6[16], 0xCu);
            sub_426AC0(&v6[28], 2u);
            sub_426AC0(&v6[30], 2u);
            sub_426AC0(&v6[32], 4u);
            sub_426AC0(&v6[40], 2u);
            sub_426AC0(&v6[42], 0x30u);
            sub_426AC0(&v6[90], 0x10u);
            sub_426AC0(&v6[106], 0x10u);
            sub_426AC0(&v6[122], 2u);
            sub_426AC0(&v6[124], 2u);
            sub_426AC0(&v6[126], 2u);
            sub_426AC0(&v6[128], 4u);
            sub_426AC0(&v6[134], 2u);
            sub_426AC0(&v6[136], 2u);
            sub_426AC0(&v6[138], 1u);
            if ((__int16)v3 > 40)
            {
                if ((__int16)v3 >= 42)
                {
                    sub_426AC0(&v6[36], 4u);
                }
                else
                {
                    sub_426AC0(&v4, 1u);
                    *(_DWORD*)& v6[36] = (unsigned __int8)v4;
                }
                LABEL_19:
                if (*(_DWORD*)& byte_5D4594[3803300] == 1)
                    goto LABEL_20;
                LABEL_22:
                if (!a1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(v3, (int)a1, a1[34])) != 0)
                {
                    a1[34] = v5;
                    result = 1;
                }
                return result;
            }
            if (*(_DWORD*)& byte_5D4594[3803300] != 1)
                goto LABEL_22;
            *(_DWORD*)& v6[36] = 0;
        }
        else
        {
            sub_426AC0(v6, 4u);
            sub_426AC0(&v6[4], 4u);
            sub_426AC0(&v6[8], 4u);
            sub_426AC0(&v6[12], 4u);
            sub_426AC0(&v6[16], 0xCu);
            sub_426AC0(&v6[28], 2u);
            sub_426AC0(&v6[30], 2u);
            sub_426AC0(&v6[32], 4u);
            *(_WORD*)& v6[40] = 0;
            *(_WORD*)& v6[122] = 0;
            *(_WORD*)& v6[124] = 0;
            *(_WORD*)& v6[126] = 0;
            *(_DWORD*)& v6[128] = 0;
            *(_WORD*)& v6[134] = 0;
            v6[138] = -128;
            if (*(_DWORD*)& byte_5D4594[3803300] != 1)
                goto LABEL_22;
            if (*(float*)& v6[4] > 63.0
                || (double) * (int*)& v6[12] * *(double*)& byte_581450[9752] > * (double*)& byte_581450[9744])
            {
                sub_484CE0((int)v6, 63.0);
                goto LABEL_19;
            }
        }
        LABEL_20:
        if (sub_40A5C0(6291456))
            qmemcpy((void*)(a1[189] + 2432), v6, 0x8Cu);
        goto LABEL_22;
    }
    return result;
}

//----- (004F5E50) --------------------------------------------------------
int __cdecl sub_4F5E50(int a1)
{
    int* v1; // edi
    _BYTE* v2; // esi
    int v3; // ebp
    int result; // eax

    v1 = (int*)a1;
    v2 = *(_BYTE * *)(a1 + 748);
    v3 = *(_DWORD*)(a1 + 136);
    a1 = 61;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 61)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0(v2 + 4, 4u);
        sub_426AC0(v2 + 8, 4u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1 || sub_40A5C0(0x200000))
            * (_DWORD*)v2 = *((_DWORD*)v2 + 1);
        if ((__int16)a1 >= 61)
            sub_426AC0(v2, 4u);
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}
