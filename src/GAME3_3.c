#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "proto.h"

extern nox_memfile* nox_loaded_thing_bin;

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
        v45 = nox_float2int(v52);
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
        v6 = nox_float2int(a3);
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
    v11.field_0 = nox_float2int(a1a.field_0) / 23;
    v11.field_4 = nox_float2int(a1a.field_4) / 23;
    v11.field_8 = nox_float2int(a1a.field_8) / 23;
    v11.field_C = nox_float2int(a1a.field_C) / 23;
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
        if (v10 > nox_float2int(v14))
        {
            v15 = (double) * (unsigned __int16*)(*(_DWORD*)(a1 + 556) + 4) * 0.66600001;
            if (v10 <= nox_float2int(v15))
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
void* __cdecl sub_4E2B60(void)
{
    void* v1; // eax
    void* v3; // edi
    void* result; // eax
    void* v5; // ebp
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
    v3 = v1;
    v21 = v1;

    nox_memfile* things = nox_open_thing_bin();
    if (!things)
        return 0;
    sub_40AD10(things, 0, 0);
    while (nox_memfile_read(&i, 4u, 1, things))
    {
        switch (i)
        {
            case 1397769548:
                sub_415100_read_spells(things);
                break;
            case 1094863180:
                sub_415320(things);
                break;
            case 1096107040:
                sub_502320(things, v3);
                break;
            case 1096175188:
                sub_502120(things, v3);
                break;
            case 1463897164:
                if (!sub_414F60(things, v3))
                    goto LABEL_53;
                break;
            case 1179406162:
                if (!sub_414DB0(things))
                    goto LABEL_53;
                break;
            case 1162102597:
                if (!sub_414E70(things, v3))
                    goto LABEL_53;
                break;
            case 1229799751:
                sub_415240(things);
                break;
            case 1414024775:
                v5 = nox_calloc(1u, 0xE0u);
                if (!v5)
                    goto LABEL_53;
                v22 = *(unsigned __int8*)things->cur;
                things->cur++;
                nox_memfile_read(v3, 1u, v22, things);
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
                if (!sub_4E3220(things, (char*)v3, (int)v5))
                {
                    LABEL_53:
                    nox_memfile_free(things);
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
    if (nox_loaded_thing_bin)
    {
        if (sub_40A5C0(2) && *(_DWORD*)& byte_5D4594[2649708])
        {
            nox_free_thing_bin();
        }
    }
    else
    {
        nox_memfile_free(things);
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
                nox_shape_box_calc((nox_shape*)(i + 60));
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
        nox_memfile_read(v3, 1u, v10, a1);
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
    v23 = nox_float2int(v21);
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
                            v6 = nox_float2int16_abs(v15);
                            v16 = sub_4E40F0() * (double) * *(unsigned __int16**)(v5 + 136);
                            v7 = nox_float2int16_abs(v16);
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
                                    v11 = nox_float2int16_abs(v17);
                                    v18 = sub_4E40F0() * v22;
                                    v12 = nox_float2int16_abs(v18);
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
                    v4 = nox_float2int(v16);
                    if (!(*(_DWORD*)(a2 + 8) & 0x400000))
                        sub_4E86E0(a1, (float*)a2);
                    v5 = sub_4EC580(a1);
                    (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v4, 2);
                    if (*(_DWORD*)(a2 + 8) & 0x20006)
                        goto LABEL_25;
                    v17 = sub_419D40(&byte_587000[203944]);
                    v6 = nox_float2int(v17);
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
                    v8 = nox_float2int(v18);
                    sub_4FF380(a1, 5, v8, 5);
                    v14 = *(float*)(a1 + 68) * 0.043478262;
                    v15 = nox_float2int(v14);
                    v13 = *(float*)(a1 + 64) * 0.043478262;
                    v9 = nox_float2int(v13);
                    sub_534BC0(v9, v15, 100, 2, a1);
                }
                v19 = sub_419D40(&byte_587000[203992]) * (double) * *(unsigned __int16**)(a1 + 556);
                v10 = nox_float2int(v19);
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
        v5 = nox_float2int(v8);
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
        v7 = nox_float2int(v6);
        v5 = *(float*)(a1 + 64) * 0.043478262;
        v4 = nox_float2int(v5);
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
    v0 = nox_float2int(v11);
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
    v9 = nox_float2int(v12);
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
        *(_DWORD*)& byte_5D4594[1567968] = nox_float2int(v10);
        v11 = sub_419D40(&byte_587000[204472]);
        *(_DWORD*)& byte_5D4594[1567972] = nox_float2int(v11);
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
        v9 = nox_float2int(v8);
        v7 = *(float*)(a1 + 64) * 0.043478262;
        v4 = nox_float2int(v7);
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
            v14 = nox_float2int(v13);
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
                v5 = nox_float2int(v12);
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
        v7 = nox_float2int(v6);
        v5 = *(float*)(a1 + 64) * 0.043478262;
        v3 = nox_float2int(v5);
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
        v13 = nox_float2int(v12);
        v11 = *(float*)(a1 + 64) * 0.043478262;
        v7 = nox_float2int(v11);
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
        v12 = nox_float2int(v11);
        v10 = *(float*)(a1 + 64) * 0.043478262;
        v8 = nox_float2int(v10);
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
        v2 = nox_float2int(v13);
        *(_DWORD*)& byte_5D4594[1568004] = v2;
    }
    if (!a2)
    {
        v10 = v2;
        v8 = *(float*)(a1 + 68) * 0.043478262;
        v9 = nox_float2int(v8);
        v7 = *(float*)(a1 + 64) * 0.043478262;
        v6 = nox_float2int(v7);
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
            *v3 = nox_float2int(v4);
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
        if (*(_DWORD*)(v4 + 320) < nox_float2int(v17))
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
    v7 = nox_float2int(v10);
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
        *(_WORD*)(*(_DWORD*)(v2 + 556) + 4) = nox_float2int(*v5);
        v6 = nox_float2int16_abs(*v5);
        sub_4E4560(v2, v6);
        *(_WORD*)(v3 + 8) = nox_float2int(v5[1]);
        *(_WORD*)(v3 + 4) = nox_float2int(v5[1]);
        *(_DWORD*)(v4 + 2239) = nox_float2int(v5[3]);
        v16 = v5[2];
        *(float*)(v2 + 548) = v5[2] * 0.000099999997;
        *(_DWORD*)(v4 + 2235) = nox_float2int(v16);
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
        *(_WORD*)(*(_DWORD*)(v2 + 556) + 4) = nox_float2int(v17);
        sub_4E4560(v2, *(_WORD*)(*(_DWORD*)(v2 + 556) + 4));
        v8 = (v5[1] - v26[1]) * 0.11111111 * v22 + v26[1];
        if (v8 > v5[1])
            v8 = v5[1];
        v18 = v8 + 0.5;
        v9 = nox_float2int(v18);
        *(_WORD*)(v3 + 8) = v9;
        *(_WORD*)(v3 + 4) = v9;
        v19 = (v5[3] - v26[3]) * 0.11111111 * v22 + v26[3] + 0.5;
        *(_DWORD*)(v4 + 2239) = nox_float2int(v19);
        v10 = (v5[2] - v26[2]) * 0.11111111 * v22 + v26[2];
        *(float*)(v2 + 548) = v10 * 0.000099999997;
        v20 = v10 + 0.5;
        *(_DWORD*)(v4 + 2235) = nox_float2int(v20);
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
        *(_DWORD*)(v1 + 320) = nox_float2int(v4);
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
    v1 = nox_float2int(v3);
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
        v5 = nox_float2int(v15);
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
    v5 = nox_float2int(v14);
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
            sub_426AC0_file3_fread(&v10, 1u);
            sub_426AC0_file3_fread(v13, (unsigned __int8)v10);
            v13[(unsigned __int8)v10] = 0;
            v4 = sub_4E3AA0(v13);
            if (!v4)
                return 0;
        }
        else
        {
            sub_426AC0_file3_fread(&v11, 2u);
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
    sub_426AC0_file3_fread((_BYTE*)v3 + 40, 4u);
    v4 = v3[4];
    v21 = (unsigned int)v3[4] & 0x11408162;
    sub_426AC0_file3_fread(&v21, 4u);
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
            sub_426AC0_file3_fread(v23, 8u);
            v10 = v3 + 14;
            *((float*)v3 + 14) = (double)v23[0];
            *((float*)v3 + 15) = (double)v23[1];
        }
        else
        {
            v10 = v3 + 14;
            sub_426AC0_file3_fread((_BYTE*)v3 + 56, 4u);
            sub_426AC0_file3_fread((_BYTE*)v3 + 60, 4u);
        }
        v11 = (_BYTE*)v10[1];
        v3[16] = (_BYTE*)* v10;
        v3[17] = v11;
    }
    else
    {
        sub_426AC0_file3_fread((_BYTE*)v3 + 56, 4u);
        sub_426AC0_file3_fread((_BYTE*)v3 + 60, 4u);
    }
    if (v8 >= 10)
    {
        if (*v3)
            LOBYTE(v19) = strlen(*v3);
        else
            LOBYTE(v19) = 0;
        sub_426AC0_file3_fread(&v19, 1u);
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
        sub_426AC0_file3_fread(*v3, (unsigned __int8)v19);
        if (*v3)
            (*v3)[(unsigned __int8)v19] = 0;
    }
    if (v8 >= 20)
        sub_426AC0_file3_fread((_BYTE*)v3 + 52, 1u);
    if (v8 >= 30)
    {
        v13 = v3[126];
        for (LOBYTE(v20) = 0; v13; LOBYTE(v20) = v20 + 1)
            v13 = (_BYTE*) * ((_DWORD*)v13 + 124);
        sub_426AC0_file3_fread(&v20, 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            v3[34] = (_BYTE*)(unsigned __int8)v20;
    }
    if (v8 >= 40)
    {
        v14 = (int*)(v3 + 11);
        sub_426AC0_file3_fread((_BYTE*)v3 + 44, 4u);
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
                sub_426AC0_file3_fread(&v22, 4u);
                a1 = v22;
            }
            else
            {
                sub_426AC0_file3_fread(&a1, 2u);
            }
            if (*(_DWORD*)& byte_5D4594[3803300])
            {
                for (i = 0; i < (unsigned __int16)a1; ++i)
                {
                    sub_426AC0_file3_fread(&a3, 4u);
                    if (!sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
                        sub_516F90(*v14, a3);
                }
            }
            else
            {
                for (j = v3[129]; j; j = (_BYTE*) * ((_DWORD*)j + 128))
                {
                    if (!(j[16] & 0x20) && sub_4E3B80(*((unsigned __int16*)j + 2)))
                        sub_426AC0_file3_fread(j + 44, 4u);
                }
            }
        }
        if (v9 >= 3)
        {
            v21 = (unsigned int)v3[5] & 0x5E;
            sub_426AC0_file3_fread(&v21, 4u);
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
        sub_426AC0_file3_fread(&v18, 2u);
        v5 = v18;
        if ((__int16)v18 > 64)
            return 0;
    }
    if (v3 < 40 || v5 < 61)
        return sub_4F4170((int)v2, v5, v3);
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        v2[34] = 0;
    sub_426AC0_file3_fread((_BYTE*)v2 + 40, 4u);
    v7 = v2 + 11;
    sub_426AC0_file3_fread((_BYTE*)v2 + 44, 4u);
    if (!v2[11] && *(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
        * v7 = (*(_DWORD*)& byte_587000[201376])++;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if ((__int16)v18 < 4)
        {
            sub_426AC0_file3_fread(v22, 8u);
            v8 = v2 + 14;
            *((float*)v2 + 14) = (double)v22[0];
            *((float*)v2 + 15) = (double)v22[1];
        }
        else
        {
            v8 = v2 + 14;
            sub_426AC0_file3_fread((_BYTE*)v2 + 56, 4u);
            sub_426AC0_file3_fread((_BYTE*)v2 + 60, 4u);
        }
        v9 = v8[1];
        v2[16] = *v8;
        v2[17] = v9;
    }
    else
    {
        sub_426AC0_file3_fread((_BYTE*)v2 + 56, 4u);
        sub_426AC0_file3_fread((_BYTE*)v2 + 60, 4u);
    }
    LOBYTE(a1) = sub_4F40A0((int)v2);
    sub_426AC0_file3_fread(&a1, 1u);
    if (!(_BYTE)a1)
        return 1;
    v10 = v2[4];
    v21 = v2[4] & 0x11408162;
    sub_426AC0_file3_fread(&v21, 4u);
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
    sub_426AC0_file3_fread(&a2, 1u);
    if (*(_DWORD*)& byte_5D4594[3803300] != 1
        || !(_BYTE)a2
        || (result = (int)nox_malloc((unsigned __int8)a2 + 1), (*v2 = result) != 0))
    {
        sub_426AC0_file3_fread((_BYTE*)* v2, (unsigned __int8)a2);
        if (*v2)
            * (_BYTE*)((unsigned __int8)a2 + *v2) = 0;
        sub_426AC0_file3_fread((_BYTE*)v2 + 52, 1u);
        v14 = v2[126];
        for (LOBYTE(v19) = 0; v14; LOBYTE(v19) = v19 + 1)
            v14 = *(_DWORD*)(v14 + 496);
        sub_426AC0_file3_fread(&v19, 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            v2[34] = (unsigned __int8)v19;
        v15 = v2[129];
        for (i = 0; v15; v15 = *(_DWORD*)(v15 + 512))
        {
            if (!(*(_BYTE*)(v15 + 16) & 0x20) && sub_4E3B80(*(unsigned __int16*)(v15 + 4)))
                ++i;
        }
        sub_426AC0_file3_fread(&i, 2u);
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            for (j = 0; j < (unsigned __int16)i; ++j)
            {
                sub_426AC0_file3_fread(v22, 4u);
                if (!sub_40A5C0(0x200000) && !sub_40A5C0(0x400000))
                    sub_516F90(*v7, v22[0]);
            }
        }
        else
        {
            for (k = v2[129]; k; k = *(_DWORD*)(k + 512))
            {
                if (!(*(_BYTE*)(k + 16) & 0x20) && sub_4E3B80(*(unsigned __int16*)(k + 4)))
                    sub_426AC0_file3_fread((_BYTE*)(k + 44), 4u);
            }
        }
        v21 = v2[5] & 0x5E;
        sub_426AC0_file3_fread(&v21, 4u);
        sub_4E4780((int)v2, 94);
        sub_4E4800((int)v2, (int*)v21);
        if ((__int16)v18 < 63 || (result = sub_4F5580((int)(v2 + 191), (char*)v2[189])) != 0)
        {
            if ((__int16)v18 >= 64)
            {
                v22[0] = v23 - *(_DWORD*)& byte_5D4594[2598000];
                sub_426AC0_file3_fread(v22, 4u);
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
    sub_426AC0_file3_fread(&a1, 2u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)a1);
    if (result)
    {
        sub_426AC0_file3_fread(*(_BYTE * *)(v1 + 700), 4u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if ((__int16)a1 >= 2)
        {
            sub_426AC0_file3_fread(&v5, 4u);
            sub_426AC0_file3_fread((_BYTE*)v2, v5);
        }
        else
        {
            sub_426AC0_file3_fread((_BYTE*)v2, v5);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if ((__int16)a1 >= 2)
        {
            sub_426AC0_file3_fread(&v6, 4u);
            sub_426AC0_file3_fread(v2, v6);
        }
        else if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            for (i = v2; ; ++i)
            {
                sub_426AC0_file3_fread(i, 1u);
                if (!*i)
                    break;
            }
        }
        else
        {
            sub_426AC0_file3_fread(v2, v6);
        }
        if ((__int16)a1 >= 31)
        {
            sub_426AC0_file3_fread(v2 + 80, 4u);
            sub_426AC0_file3_fread(v2 + 84, 4u);
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
    sub_426AC0_file3_fread(&v7, 2u);
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
        sub_426AC0_file3_fread(&a1, 4u);
        sub_426AC0_file3_fread(&v8, 4u);
        if ((__int16)v7 < 41)
            v6 = a1;
        else
            sub_426AC0_file3_fread(&v6, 4u);
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
    sub_426AC0_file3_fread(&v11, 2u);
    if ((__int16)v11 > 61)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)v11);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            sub_426AC0_file3_fread(&a1, 4u);
            sub_426AC0_file3_fread(&v12, 4u);
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
            sub_426AC0_file3_fread(&a1, 4u);
            sub_426AC0_file3_fread(&v12, 4u);
        }
        nox_shape_box_calc((nox_shape*)(v1 + 172));
        if ((__int16)v11 < 41)
        {
            sub_426AC0_file3_fread(&a1, 3u);
            sub_426AC0_file3_fread(&a1, 3u);
            sub_426AC0_file3_fread(&a1, 3u);
        }
        else
        {
            sub_426AC0_file3_fread(v2 + 54, 1u);
            sub_426AC0_file3_fread(v2 + 55, 1u);
            sub_426AC0_file3_fread(v2 + 56, 1u);
            sub_426AC0_file3_fread(v2 + 57, 1u);
            sub_426AC0_file3_fread(v2 + 58, 1u);
            sub_426AC0_file3_fread(v2 + 59, 1u);
        }
        sub_426AC0_file3_fread(v2, 4u);
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
            sub_426AC0_file3_fread(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
            sub_426AC0_file3_fread(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
            sub_426AC0_file3_fread(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
            sub_426AC0_file3_fread(&a1, 1u);
            sub_426AA0(4 * LOBYTE(a1));
        }
        sub_426AC0_file3_fread(v2 + 44, 4u);
        sub_426AC0_file3_fread(v2 + 48, 4u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            v2[52] = 0;
            v2[53] = 0;
        }
        if (!*(_DWORD*)& byte_5D4594[3803300] || (__int16)v11 >= 21)
        {
            sub_426AC0_file3_fread(v2 + 52, 1u);
            sub_426AC0_file3_fread(v2 + 53, 1u);
        }
        if ((__int16)v11 >= 61)
        {
            sub_426AC0_file3_fread(v2 + 8, 1u);
            sub_426AC0_file3_fread(v2 + 9, 1u);
            sub_426AC0_file3_fread((_BYTE*)(v1 + 132), 4u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if ((__int16)a1 < 42)
            * (_DWORD*)(v3 + 24) = 0;
        else
            sub_426AC0_file3_fread((_BYTE*)(v3 + 24), 4u);
        if ((__int16)a1 < 41)
        {
            sub_426AC0_file3_fread((_BYTE*)(v3 + 8), 8u);
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
            sub_426AC0_file3_fread((_BYTE*)(v3 + 8), 8u);
            sub_426AC0_file3_fread((_BYTE*)(v3 + 16), 4u);
            sub_426AC0_file3_fread((_BYTE*)(v3 + 20), 2u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            sub_426AC0_file3_fread((_BYTE*)(v2 + 16), 4u);
        }
        else
        {
            if (*(_DWORD*)(v2 + 12))
                v5 = *(_DWORD*)(v2 + 16);
            else
                v5 = 0;
            sub_426AC0_file3_fread(&v5, 4u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 61)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0_file3_fread(v2 + 8, 4u);
        if ((__int16)a1 >= 41)
            sub_426AC0_file3_fread(v2 + 16, 4u);
        if ((__int16)a1 >= 61)
            sub_426AC0_file3_fread(v2 + 12, 1u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0_file3_fread((_BYTE*)(v2 + 8), 4u);
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
    sub_426AC0_file3_fread(&v6, 2u);
    if ((__int16)v6 > 1)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300] == 1)
    {
        sub_426AC0_file3_fread(&v5, 4u);
        if (v5 >= 0x400)
            return 0;
        sub_426AC0_file3_fread(v7, v5);
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
                sub_426AC0_file3_fread(&v5, 4u);
                sub_426AC0_file3_fread(a2, v5);
                goto LABEL_16;
            }
        }
        else
        {
            v4 = *(_DWORD*)(a1 + 4);
            if (v4 != -1)
            {
                v5 = strlen(*(const char**)(48 * v4 + *(_DWORD*)& byte_5D4594[1599636]));
                sub_426AC0_file3_fread(&v5, 4u);
                sub_426AC0_file3_fread(*(_BYTE * *)(48 * *(_DWORD*)(a1 + 4) + *(_DWORD*)& byte_5D4594[1599636]), v5);
                goto LABEL_16;
            }
        }
        v5 = 0;
        sub_426AC0_file3_fread(&v5, 4u);
    }
    LABEL_16:
    sub_426AC0_file3_fread((_BYTE*)a1, 4u);
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
    sub_426AC0_file3_fread(&v7, 2u);
    if ((__int16)v7 > 60)
        return 0;
    result = sub_4F4530((int*)v1, (__int16)v7);
    if (result)
    {
        sub_426AC0_file3_fread((_BYTE*)(v2 + 4), 4u);
        sub_426AC0_file3_fread((_BYTE*)(v2 + 8), 4u);
        sub_426AC0_file3_fread((_BYTE*)(v2 + 32), 4u);
        if ((__int16)v7 >= 41)
        {
            sub_426AC0_file3_fread((_BYTE*)v2, 1u);
            if (*(_DWORD*)& byte_5D4594[3803300])
            {
                sub_426AC0_file3_fread((_BYTE*)(v2 + 16), 4u);
                sub_426AC0_file3_fread((_BYTE*)(v2 + 24), 4u);
            }
            else
            {
                v5 = *(int**)(v2 + 12);
                a1 = 0;
                if (v5)
                    a1 = *v5;
                sub_426AC0_file3_fread(&a1, 4u);
                v6 = *(int**)(v2 + 20);
                a1 = 0;
                if (v6)
                    a1 = *v6;
                sub_426AC0_file3_fread(&a1, 4u);
            }
        }
        if ((__int16)v7 >= 42)
        {
            sub_426AC0_file3_fread((_BYTE*)(v1 + 548), 4u);
            sub_426AC0_file3_fread((_BYTE*)(v1 + 544), 4u);
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
    sub_426AC0_file3_fread(&v12, 2u);
    if ((__int16)v12 > 60)
        return 0;
    result = sub_4F4530((int*)a1, (__int16)v12);
    if (result)
    {
        if ((__int16)v12 < 41)
            sub_426AC0_file3_fread(&v15, 4u);
        sub_426AC0_file3_fread((_BYTE*)(a1 + 124), 1u);
        sub_426AC0_file3_fread((_BYTE*)(v2 + 28), 4u);
        sub_426AC0_file3_fread((_BYTE*)(v2 + 32), 4u);
        v5 = (_BYTE*)(v2 + 20);
        sub_426AC0_file3_fread((_BYTE*)(v2 + 20), 1u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            if ((__int16)v12 < 31)
            {
                sub_426AC0_file3_fread((_BYTE*)v2, 0x14u);
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
                sub_426AC0_file3_fread(&v11, 1u);
                sub_426AC0_file3_fread(v16, (unsigned __int8)v11);
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
                sub_426AC0_file3_fread(&v11, 1u);
                v10 = (unsigned __int8)v11;
                v9 = sub_424870(*(_DWORD*)v2);
                sub_426AC0_file3_fread(v9, v10);
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
    sub_426AC0_file3_fread(&v3, 2u);
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
            sub_426AC0_file3_fread(v6, 4u);
            sub_426AC0_file3_fread(&v6[4], 4u);
            sub_426AC0_file3_fread(&v6[8], 4u);
            sub_426AC0_file3_fread(&v6[12], 4u);
            sub_426AC0_file3_fread(&v6[16], 0xCu);
            sub_426AC0_file3_fread(&v6[28], 2u);
            sub_426AC0_file3_fread(&v6[30], 2u);
            sub_426AC0_file3_fread(&v6[32], 4u);
            sub_426AC0_file3_fread(&v6[40], 2u);
            sub_426AC0_file3_fread(&v6[42], 0x30u);
            sub_426AC0_file3_fread(&v6[90], 0x10u);
            sub_426AC0_file3_fread(&v6[106], 0x10u);
            sub_426AC0_file3_fread(&v6[122], 2u);
            sub_426AC0_file3_fread(&v6[124], 2u);
            sub_426AC0_file3_fread(&v6[126], 2u);
            sub_426AC0_file3_fread(&v6[128], 4u);
            sub_426AC0_file3_fread(&v6[134], 2u);
            sub_426AC0_file3_fread(&v6[136], 2u);
            sub_426AC0_file3_fread(&v6[138], 1u);
            if ((__int16)v3 > 40)
            {
                if ((__int16)v3 >= 42)
                {
                    sub_426AC0_file3_fread(&v6[36], 4u);
                }
                else
                {
                    sub_426AC0_file3_fread(&v4, 1u);
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
            sub_426AC0_file3_fread(v6, 4u);
            sub_426AC0_file3_fread(&v6[4], 4u);
            sub_426AC0_file3_fread(&v6[8], 4u);
            sub_426AC0_file3_fread(&v6[12], 4u);
            sub_426AC0_file3_fread(&v6[16], 0xCu);
            sub_426AC0_file3_fread(&v6[28], 2u);
            sub_426AC0_file3_fread(&v6[30], 2u);
            sub_426AC0_file3_fread(&v6[32], 4u);
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
    sub_426AC0_file3_fread(&a1, 2u);
    if ((__int16)a1 > 61)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0_file3_fread(v2 + 4, 4u);
        sub_426AC0_file3_fread(v2 + 8, 4u);
        if (*(_DWORD*)& byte_5D4594[3803300] == 1 || sub_40A5C0(0x200000))
            * (_DWORD*)v2 = *((_DWORD*)v2 + 1);
        if ((__int16)a1 >= 61)
            sub_426AC0_file3_fread(v2, 4u);
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}
