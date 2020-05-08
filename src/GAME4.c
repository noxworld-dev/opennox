#include "proto.h"

extern int nox_win_width;

FILE* nox_file_7 = 0;
FILE* nox_file_8 = 0;

//----- (004F5F30) --------------------------------------------------------
int __cdecl sub_4F5F30(int* a1)
{
    unsigned __int8* v1; // esi
    int result; // eax
    unsigned __int8 v3; // cl
    unsigned __int8 v4; // al
    unsigned __int8 v5; // bl
    unsigned __int8 v6; // al
    int v7; // [esp+Ch] [ebp-94h]
    unsigned __int8 v8; // [esp+12h] [ebp-8Eh]
    unsigned __int8 v9; // [esp+13h] [ebp-8Dh]
    int v10; // [esp+14h] [ebp-8Ch]
    char v11; // [esp+1Ah] [ebp-86h]
    char v12; // [esp+1Bh] [ebp-85h]
    int v13; // [esp+1Ch] [ebp-84h]
    char v14[128]; // [esp+20h] [ebp-80h]

    v1 = (unsigned __int8*)a1[184];
    v13 = a1[34];
    v10 = 60;
    sub_426AC0(&v10, 2u);
    if ((__int16)v10 > 60)
        return 0;
    result = sub_4F4530(a1, (__int16)v10);
    if (result)
    {
        if ((__int16)v10 >= 31)
        {
            if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            {
                if ((__int16)v10 >= 41)
                {
                    sub_426AC0(&v7, 1u);
                    if ((unsigned __int8)v7 >= 0x80u)
                        return 0;
                    sub_426AC0(v14, (unsigned __int8)v7);
                    v14[(unsigned __int8)v7] = 0;
                    *v1 = sub_4243F0(v14);
                }
                else
                {
                    sub_426AC0(&v7, 1u);
                    if ((unsigned __int8)v7 >= 0x80u)
                        return 0;
                    sub_426AC0(v14, (unsigned __int8)v7);
                    v14[(unsigned __int8)v7] = 0;
                    sub_4243F0(v14);
                    sub_426AC0(&v7, 1u);
                    if ((unsigned __int8)v7 >= 0x80u)
                        return 0;
                    sub_426AC0(v14, (unsigned __int8)v7);
                    v14[(unsigned __int8)v7] = 0;
                    v5 = sub_4243F0(v14);
                    sub_426AC0(&v7, 1u);
                    if ((unsigned __int8)v7 >= 0x80u)
                        return 0;
                    sub_426AC0(v14, (unsigned __int8)v7);
                    v14[(unsigned __int8)v7] = 0;
                    v6 = sub_4243F0(v14);
                    *v1 = v5;
                    if (v6)
                        * v1 = v6;
                }
                goto LABEL_28;
            }
        }
        else if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            sub_426AC0(&v12, 1u);
            sub_426AC0(&v9, 1u);
            sub_426AC0(&v8, 1u);
            v3 = v9;
            if (v9 >= 0x89u)
            {
                v3 = 0;
                v9 = 0;
            }
            v4 = v8;
            if (v8 >= 0x89u)
            {
                v4 = 0;
                v8 = 0;
            }
            *v1 = v3;
            if (v4)
                * v1 = v4;
            if ((_WORD)v10 == 10)
                sub_426AC0(&v11, 1u);
            goto LABEL_28;
        }
        strcpy(v14, sub_424870(*v1));
        LOBYTE(v7) = strlen(v14);
        sub_426AC0(&v7, 1u);
        sub_426AC0(v14, (unsigned __int8)v7);
    LABEL_28:
        if (!a1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(v10, (int)a1, a1[34])) != 0)
        {
            a1[34] = v13;
            result = 1;
        }
    }
    return result;
}
// 4F5F30: using guessed type char var_80[128];

//----- (004F6240) --------------------------------------------------------
int __cdecl sub_4F6240(int* a1)
{
    _BYTE* v1; // ebp
    int result; // eax
    int v3; // [esp+8h] [ebp-8Ch]
    int v4; // [esp+Ch] [ebp-88h]
    int v5; // [esp+10h] [ebp-84h]
    char v6[128]; // [esp+14h] [ebp-80h]

    v1 = (_BYTE*)a1[184];
    v5 = a1[34];
    v4 = 61;
    sub_426AC0(&v4, 2u);
    if ((__int16)v4 > 61)
        return 0;
    result = sub_4F4530(a1, (__int16)v4);
    if (result)
    {
        strcpy(v6, sub_425250((unsigned __int8)* v1));
        LOBYTE(v3) = strlen(v6);
        sub_426AC0(&v3, 1u);
        if ((unsigned __int8)v3 < 0x80u)
        {
            sub_426AC0(v6, (unsigned __int8)v3);
            v6[(unsigned __int8)v3] = 0;
            *v1 = sub_424D80(v6);
            if (!a1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(v4, (int)a1, a1[34])) != 0)
            {
                a1[34] = v5;
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
// 4F6240: using guessed type char var_80[128];

//----- (004F6390) --------------------------------------------------------
int __cdecl sub_4F6390(int* a1)
{
    int* v1; // esi
    char* v2; // ebx
    int v3; // ebp
    int result; // eax
    int v5; // [esp+Ch] [ebp-4h]

    v1 = a1;
    v2 = (char*)a1[184];
    v3 = a1[34];
    v5 = 60;
    sub_426AC0(&v5, 2u);
    if ((__int16)v5 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)v5);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            sub_426AC0(&a1, 1u);
            if ((unsigned __int8)a1 >= 0x40u)
                return 0;
            sub_426AC0(v2, (unsigned __int8)a1);
            v2[(unsigned __int8)a1] = 0;
        }
        else
        {
            LOBYTE(a1) = strlen(v2);
            sub_426AC0(&a1, 1u);
            sub_426AC0(v2, (unsigned __int8)a1);
        }
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(v5, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F64A0) --------------------------------------------------------
int __cdecl sub_4F64A0(int a1)
{
    int result; // eax
    const char*** v2; // esi
    int v3; // ebx
    int v4; // esi
    char* v5; // edi
    int v6; // eax
    int v7; // ecx
    int v8; // esi
    unsigned __int8 v9; // bl
    int v10; // edi
    int v11; // eax
    size_t v12; // eax
    _DWORD* v13; // eax
    unsigned __int8 v14; // [esp+12h] [ebp-126h]
    unsigned __int8 v15; // [esp+13h] [ebp-125h]
    int v16; // [esp+14h] [ebp-124h]
    int v17; // [esp+18h] [ebp-120h]
    int v18; // [esp+1Ch] [ebp-11Ch]
    int v19; // [esp+20h] [ebp-118h]
    char v20[20]; // [esp+24h] [ebp-114h]
    char v21[256]; // [esp+38h] [ebp-100h]

    v19 = *(_DWORD*)(a1 + 136);
    v17 = 64;
    sub_426AC0(&v17, 2u);
    if ((__int16)v17 > 64)
        return 0;
    result = sub_4F4530((int*)a1, (__int16)v17);
    if (!result)
        return result;
    if ((__int16)v17 < 11 && *(_DWORD*)& byte_5D4594[3803300] == 1)
    {
        *(_DWORD*)v20 = 0;
        *(_DWORD*)& v20[4] = 0;
        *(_DWORD*)& v20[8] = 0;
        *(_DWORD*)& v20[12] = 0;
        sub_4E4990(a1, (int*)v20);
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        v4 = 0;
        v5 = v20;
        while (1)
        {
            sub_426AC0(&v18, 1u);
            if ((int)(unsigned __int8)v18 >= 256)
                return 0;
            sub_426AC0(v21, (unsigned __int8)v18);
            v21[(unsigned __int8)v18] = 0;
            v6 = sub_413290(v21);
            *(_DWORD*)v5 = sub_413330(v6);
            ++v4;
            v5 += 4;
            if (v4 >= 4)
            {
                *(_WORD*)& v20[16] = -1;
                *(_WORD*)& v20[18] = -1;
                sub_4E4990(a1, (int*)v20);
                goto LABEL_18;
            }
        }
    }
    v2 = *(const char****)(a1 + 692);
    v3 = 4;
    do
    {
        if (*v2)
        {
            LOBYTE(v18) = strlen(**v2);
            sub_426AC0(&v18, 1u);
            sub_426AC0(**v2, (unsigned __int8)v18);
        }
        else
        {
            LOBYTE(v18) = 0;
            sub_426AC0(&v18, 1u);
        }
        ++v2;
        --v3;
    } while (v3);
LABEL_18:
    if ((__int16)v17 >= 41)
    {
        v7 = 0;
        if (*(_DWORD*)(a1 + 8) & 0x1000 && *(_DWORD*)(a1 + 12) & 0x47F0000)
            v7 = 1;
        if (((__int16)v17 >= 62 || !(*(_DWORD*)(a1 + 8) & 0x1000) || !(*(_DWORD*)(a1 + 12) & 0x4000000)) && v7)
        {
            v8 = *(_DWORD*)(a1 + 736);
            v14 = *(_BYTE*)(v8 + 108);
            v15 = *(_BYTE*)(v8 + 109);
            v9 = v15;
            v16 = *(_DWORD*)(v8 + 112);
            v10 = v16;
            v14 = *(_BYTE*)(v8 + 108);
            sub_426AC0(&v14, 1u);
            v15 = *(_BYTE*)(v8 + 109);
            sub_426AC0(&v15, 1u);
            if ((__int16)v17 >= 61)
            {
                v16 = *(_DWORD*)(v8 + 112);
                sub_426AC0(&v16, 4u);
            }
            if (!sub_40A5C0(4096))
            {
                *(_BYTE*)(v8 + 108) = v14;
                goto LABEL_36;
            }
            if (v14 <= v9 && v16 >= 0 && v16 <= v10 && v9 == v15)
            {
                *(_BYTE*)(v8 + 108) = v14;
            LABEL_36:
                *(_BYTE*)(v8 + 109) = v15;
                *(_DWORD*)(v8 + 112) = v16;
                goto LABEL_37;
            }
            *(_BYTE*)(v8 + 108) = 0;
            *(_BYTE*)(v8 + 109) = v9;
            *(_DWORD*)(v8 + 112) = 0;
        }
    }
LABEL_37:
    if ((__int16)v17 >= 42)
    {
        LOWORD(v11) = sub_4EE780(a1);
        v16 = v11;
        v12 = sub_426AC0(&v16, 2u);
        LOWORD(v12) = *(_WORD*)(*(_DWORD*)(a1 + 556) + 4);
        if ((unsigned __int16)v16 > (unsigned __int16)v12)
            v16 = v12;
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            if (sub_4DB240() == 1 || sub_4DB250() == 1 || sub_40A5C0(4096) && sub_419EA0())
            {
                sub_4E4560(a1, v16);
            }
            else
            {
                v13 = sub_413250(*(unsigned __int16*)(a1 + 4));
                if (v13)
                {
                    *(_WORD*)(*(_DWORD*)(a1 + 556) + 4) = *((_WORD*)v13 + 26);
                    *(_WORD*)(*(_DWORD*)(a1 + 556) + 2) = *((_WORD*)v13 + 26);
                    sub_4E4560(a1, *((_WORD*)v13 + 26));
                }
            }
        }
    }
    if ((_WORD)v17 == 63)
        sub_426AC0(&v14, 1u);
    if ((__int16)v17 >= 64)
        sub_426AC0((_BYTE*)(*(_DWORD*)(a1 + 748) + 4), 4u);
    if (*(_DWORD*)(a1 + 136) && *(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_4F3E30(v17, a1, *(_DWORD*)(a1 + 136)))
        return 0;
    *(_DWORD*)(a1 + 136) = v19;
    return 1;
}
// 4F673C: variable 'v11' is possibly undefined
// 4F64A0: using guessed type char var_100[256];

//----- (004F6860) --------------------------------------------------------
int __cdecl sub_4F6860(int a1)
{
    int result; // eax
    const char*** v2; // esi
    int v3; // ebx
    int v4; // esi
    char* v5; // edi
    int v6; // eax
    int v7; // eax
    size_t v8; // eax
    _DWORD* v9; // eax
    int v10; // [esp+Ch] [ebp-128h]
    int v11; // [esp+10h] [ebp-124h]
    size_t v12; // [esp+14h] [ebp-120h]
    char v13; // [esp+1Bh] [ebp-119h]
    int v14; // [esp+1Ch] [ebp-118h]
    char v15[20]; // [esp+20h] [ebp-114h]
    char v16[256]; // [esp+34h] [ebp-100h]

    v14 = *(_DWORD*)(a1 + 136);
    v10 = 62;
    sub_426AC0(&v10, 2u);
    if ((__int16)v10 > 62)
        return 0;
    result = sub_4F4530((int*)a1, (__int16)v10);
    if (result)
    {
        if ((__int16)v10 < 11 && *(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            *(_DWORD*)v15 = 0;
            *(_DWORD*)& v15[4] = 0;
            *(_DWORD*)& v15[8] = 0;
            *(_DWORD*)& v15[12] = 0;
            sub_4E4990(a1, (int*)v15);
            return 1;
        }
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            v4 = 0;
            v5 = v15;
            while (1)
            {
                sub_426AC0(&v11, 1u);
                if ((int)(unsigned __int8)v11 >= 256)
                    return 0;
                sub_426AC0(v16, (unsigned __int8)v11);
                v16[(unsigned __int8)v11] = 0;
                v6 = sub_413290(v16);
                *(_DWORD*)v5 = sub_413330(v6);
                ++v4;
                v5 += 4;
                if (v4 >= 4)
                {
                    *(_WORD*)& v15[16] = -1;
                    *(_WORD*)& v15[18] = -1;
                    sub_4E4990(a1, (int*)v15);
                    goto LABEL_18;
                }
            }
        }
        v2 = *(const char****)(a1 + 692);
        v3 = 4;
        do
        {
            if (*v2)
            {
                LOBYTE(v11) = strlen(**v2);
                sub_426AC0(&v11, 1u);
                sub_426AC0(**v2, (unsigned __int8)v11);
            }
            else
            {
                LOBYTE(v11) = 0;
                sub_426AC0(&v11, 1u);
            }
            ++v2;
            --v3;
        } while (v3);
    LABEL_18:
        if ((__int16)v10 >= 41)
        {
            LOWORD(v7) = sub_4EE780(a1);
            v12 = v7;
            v8 = sub_426AC0(&v12, 2u);
            LOWORD(v8) = *(_WORD*)(*(_DWORD*)(a1 + 556) + 4);
            if ((unsigned __int16)v12 > (unsigned __int16)v8)
                v12 = v8;
            if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            {
                if (sub_4DB240() == 1 || sub_4DB250() == 1 || sub_40A5C0(4096) && sub_419EA0())
                {
                    sub_4E4560(a1, v12);
                }
                else
                {
                    v9 = sub_413270(*(unsigned __int16*)(a1 + 4));
                    if (v9)
                    {
                        *(_WORD*)(*(_DWORD*)(a1 + 556) + 4) = *((_WORD*)v9 + 26);
                        *(_WORD*)(*(_DWORD*)(a1 + 556) + 2) = *((_WORD*)v9 + 26);
                        sub_4E4560(a1, *((_WORD*)v9 + 26));
                    }
                }
            }
        }
        if ((_WORD)v10 == 61)
            sub_426AC0(&v13, 1u);
        if ((__int16)v10 >= 62)
            sub_426AC0((_BYTE*)(*(_DWORD*)(a1 + 748) + 4), 4u);
        if (*(_DWORD*)(a1 + 136) && *(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_4F3E30(v10, a1, *(_DWORD*)(a1 + 136)))
            return 0;
        *(_DWORD*)(a1 + 136) = v14;
        result = 1;
    }
    return result;
}
// 4F69F8: variable 'v7' is possibly undefined
// 4F6860: using guessed type char var_100[256];

//----- (004F6B20) --------------------------------------------------------
int __cdecl sub_4F6B20(int* a1)
{
    int v1; // ecx
    int result; // eax
    const char*** v3; // esi
    int v4; // ebp
    char* v5; // esi
    int v6; // esi
    char* v7; // edi
    int v8; // eax
    bool v9; // zf
    char* v10; // eax
    char v11; // cl
    char v12; // [esp+Eh] [ebp-126h]
    char v13; // [esp+Fh] [ebp-125h]
    int v14; // [esp+10h] [ebp-124h]
    char* v15; // [esp+14h] [ebp-120h]
    int v16; // [esp+18h] [ebp-11Ch]
    int v17; // [esp+1Ch] [ebp-118h]
    char v18[20]; // [esp+20h] [ebp-114h]
    char v19[256]; // [esp+34h] [ebp-100h]

    v1 = a1[34];
    v15 = (char*)a1[184];
    v17 = v1;
    v16 = 60;
    sub_426AC0(&v16, 2u);
    if ((__int16)v16 > 60)
        return 0;
    result = sub_4F4530(a1, (__int16)v16);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            v6 = 0;
            v7 = v18;
            while (1)
            {
                sub_426AC0(&v14, 1u);
                if ((int)(unsigned __int8)v14 >= 256)
                    return 0;
                sub_426AC0(v19, (unsigned __int8)v14);
                v19[(unsigned __int8)v14] = 0;
                v8 = sub_413290(v19);
                *(_DWORD*)v7 = sub_413330(v8);
                ++v6;
                v7 += 4;
                if (v6 >= 4)
                {
                    *(_WORD*)& v18[16] = -1;
                    *(_WORD*)& v18[18] = -1;
                    sub_4E4990((int)a1, (int*)v18);
                    sub_426AC0(&v13, 1u);
                    sub_426AC0(&v12, 1u);
                    v9 = !sub_40A5C0(4096);
                    v10 = v15;
                    if (!v9)
                        v15[2] = 0;
                    v11 = v12;
                    v10[1] = v13;
                    *v10 = v11;
                    goto LABEL_17;
                }
            }
        }
        v3 = (const char***)a1[173];
        v4 = 4;
        do
        {
            if (*v3)
            {
                LOBYTE(v14) = strlen(**v3);
                sub_426AC0(&v14, 1u);
                sub_426AC0(**v3, (unsigned __int8)v14);
            }
            else
            {
                LOBYTE(v14) = 0;
                sub_426AC0(&v14, 1u);
            }
            ++v3;
            --v4;
        } while (v4);
        v5 = v15;
        sub_426AC0(v15 + 1, 1u);
        sub_426AC0(v5, 1u);
    LABEL_17:
        if (a1[34] && *(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_4F3E30(v16, (int)a1, a1[34]))
            return 0;
        a1[34] = v17;
        result = 1;
    }
    return result;
}
// 4F6B20: using guessed type char var_100[256];

//----- (004F6D20) --------------------------------------------------------
int __cdecl sub_4F6D20(int* a1)
{
    int result; // eax
    const char*** v2; // esi
    int v3; // ebx
    char* v4; // esi
    int v5; // edi
    int v6; // eax
    _DWORD* v7; // edx
    int v8; // [esp+4h] [ebp-120h]
    int v9; // [esp+8h] [ebp-11Ch]
    int v10; // [esp+Ch] [ebp-118h]
    char v11[20]; // [esp+10h] [ebp-114h]
    char v12[256]; // [esp+24h] [ebp-100h]

    v10 = a1[34];
    v9 = 60;
    sub_426AC0(&v9, 2u);
    if ((__int16)v9 > 60)
        return 0;
    result = sub_4F4530(a1, (__int16)v9);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            v4 = v11;
            v5 = 4;
            do
            {
                sub_426AC0(&v8, 1u);
                sub_426AC0(v12, (unsigned __int8)v8);
                v12[(unsigned __int8)v8] = 0;
                v6 = sub_413290(v12);
                *(_DWORD*)v4 = sub_413330(v6);
                v4 += 4;
                --v5;
            } while (v5);
            *(_WORD*)& v11[16] = -1;
            *(_WORD*)& v11[18] = -1;
            sub_4E4990((int)a1, (int*)v11);
            if (a1[2] & 0x10000000)
            {
                v7 = (_DWORD*)a1[187];
                *v7 = a1[14];
                v7[1] = a1[15];
            }
        }
        else
        {
            v2 = (const char***)a1[173];
            v3 = 4;
            do
            {
                if (*v2)
                {
                    LOBYTE(v8) = strlen(**v2);
                    sub_426AC0(&v8, 1u);
                    sub_426AC0(**v2, (unsigned __int8)v8);
                }
                else
                {
                    LOBYTE(v8) = 0;
                    sub_426AC0(&v8, 1u);
                }
                ++v2;
                --v3;
            } while (v3);
        }
        if (!a1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(v9, (int)a1, a1[34])) != 0)
        {
            a1[34] = v10;
            result = 1;
        }
    }
    return result;
}
// 4F6D20: using guessed type char var_100[256];

//----- (004F6EC0) --------------------------------------------------------
int __cdecl sub_4F6EC0(int a1)
{
    int* v1; // esi
    _BYTE* v2; // edi
    int v3; // ebx
    int result; // eax

    v1 = (int*)a1;
    v2 = *(_BYTE * *)(a1 + 692);
    v3 = *(_DWORD*)(a1 + 136);
    a1 = 60;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 60)
        return 0;
    result = sub_4F4530(v1, (__int16)a1);
    if (result)
    {
        sub_426AC0(v2, 4u);
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(a1, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}

//----- (004F6F60) --------------------------------------------------------
int __cdecl sub_4F6F60(int* a1)
{
    int* v1; // esi
    _BYTE* v2; // edi
    int v3; // ebp
    int result; // eax
    _DWORD* v5; // edi
    int v6; // eax
    float v7; // [esp+0h] [ebp-18h]
    int v8; // [esp+10h] [ebp-8h]
    int v9; // [esp+14h] [ebp-4h]

    v1 = a1;
    v2 = (_BYTE*)a1[187];
    v3 = a1[34];
    v8 = 61;
    sub_426AC0(&v8, 2u);
    if ((__int16)v8 > 61)
        return 0;
    result = sub_4F4530(v1, (__int16)v8);
    if (result)
    {
        if ((__int16)v8 >= 61)
        {
            LOBYTE(a1) = 0;
            sub_426AC0(v2, 4u);
            if (*(_DWORD*)& byte_5D4594[3803300] == 1)
            {
                v9 = 80 * *(_DWORD*)v2 / 50;
                v7 = (double)v9;
                nullsub_35(v1, LODWORD(v7));
            }
            if (sub_40A5C0(2048))
            {
                v5 = sub_45A720(v1[10]);
                if (v5)
                {
                    v6 = sub_459EB0();
                    if (v6)
                    {
                        while ((_DWORD*)v6 != v5)
                        {
                            v6 = sub_459EC0(v6);
                            if (!v6)
                                goto LABEL_14;
                        }
                        LOBYTE(a1) = 1;
                    }
                }
            }
        LABEL_14:
            sub_426AC0(&a1, 1u);
        }
        if (!v1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || (result = sub_4F3E30(v8, (int)v1, v1[34])) != 0)
        {
            v1[34] = v3;
            result = 1;
        }
    }
    return result;
}
// 4E4770: using guessed type void __cdecl nullsub_35(_DWORD, _DWORD);

//----- (004F70A0) --------------------------------------------------------
int __cdecl sub_4F70A0(int a1)
{
    int* v1; // esi
    _BYTE* v2; // edi
    int v3; // ebx

    v1 = (int*)a1;
    v2 = *(_BYTE * *)(a1 + 748);
    v3 = *(_DWORD*)(a1 + 136);
    a1 = 61;
    sub_426AC0(&a1, 2u);
    if ((__int16)a1 > 61)
        return 0;
    if ((__int16)a1 <= 0)
        return 0;
    if (!sub_4F4530(v1, (__int16)a1))
        return 0;
    sub_426AC0(v2, 4u);
    if (v1[34])
    {
        if (*(_DWORD*)& byte_5D4594[3803300] == 1 && !sub_4F3E30(a1, (int)v1, v1[34]))
            return 0;
    }
    v1[34] = v3;
    return 1;
}

//----- (004F7130) --------------------------------------------------------
int __cdecl sub_4F7130(int* a1)
{
    _BYTE* v1; // ebx
    int v2; // eax
    int v3; // edi
    int v4; // esi
    _BYTE* v5; // ebp
    char* v6; // eax
    char* v7; // eax
    char* v8; // eax
    char* v9; // edi
    int* v10; // ebp
    char v11; // cl
    int* v12; // ebx
    int v13; // eax
    int v14; // esi
    _BYTE* v15; // eax
    int v16; // ebp
    int v17; // edi
    _DWORD* v18; // esi
    int v19; // ecx
    bool v20; // cc
    int v21; // esi
    _BYTE* v22; // edi
    size_t v24; // [esp-4h] [ebp-138h]
    char v25; // [esp+13h] [ebp-121h]
    int v26; // [esp+14h] [ebp-120h]
    int v27; // [esp+18h] [ebp-11Ch]
    int v28; // [esp+1Ch] [ebp-118h]
    int v29; // [esp+20h] [ebp-114h]
    int v30; // [esp+24h] [ebp-110h]
    int v31; // [esp+28h] [ebp-10Ch]
    _BYTE* v32; // [esp+2Ch] [ebp-108h]
    int v33; // [esp+30h] [ebp-104h]
    char v34[256]; // [esp+34h] [ebp-100h]

    v1 = (_BYTE*)a1[187];
    v2 = a1[34];
    v3 = a1[189];
    v32 = (_BYTE*)a1[187];
    v33 = v2;
    v29 = 63;
    sub_426AC0(&v29, 2u);
    if ((__int16)v29 <= 63 && (__int16)v29 > 0 && sub_4F4530(a1, (__int16)v29))
    {
        LOBYTE(v31) = 3;
        sub_426AC0(&v31, 1u);
        v4 = 0;
        if ((_BYTE)v31)
        {
            v5 = v1 + 80;
            do
            {
                sub_426AC0(v5, 1u);
                ++v4;
                ++v5;
            } while (v4 < (unsigned __int8)v31);
        }
        sub_426AC0(v1 + 86, 1u);
        sub_426AC0(v1 + 87, 1u);
        sub_426AC0(v1 + 88, 4u);
        if (v3)
            v6 = (char*)(v3 + 1920);
        else
            v6 = 0;
        sub_4F5580((int)(v1 + 48), v6);
        if (v3)
            v7 = (char*)(v3 + 2048);
        else
            v7 = 0;
        sub_4F5580((int)(v1 + 56), v7);
        if (v3)
            v8 = (char*)(v3 + 2176);
        else
            v8 = 0;
        sub_4F5580((int)(v1 + 72), v8);
        if (v3)
            v9 = (char*)(v3 + 2304);
        else
            v9 = 0;
        sub_4F5580((int)(v1 + 64), v9);
        if (*(_DWORD*)& byte_5D4594[3803300])
        {
            sub_426AC0(&v27, 1u);
            v16 = 0;
            if ((_BYTE)v27)
            {
                while (1)
                {
                    sub_426AC0(&v30, 1u);
                    v17 = 0;
                    if ((_BYTE)v30)
                        break;
                LABEL_36:
                    if (++v16 >= (unsigned __int8)v27)
                        goto LABEL_37;
                }
                while (1)
                {
                    sub_426AC0(&v28, 1u);
                    sub_426AC0(v34, (unsigned __int8)v28);
                    v34[(unsigned __int8)v28] = 0;
                    v18 = sub_4E3810(v34);
                    if (!v18)
                        return 0;
                    sub_426AC0(&v26, 2u);
                    sub_426C20(&v32, 4u);
                    if (!((int(__cdecl*)(_DWORD*, _DWORD))v18[176])(v18, 0))
                        return 0;
                    v19 = v17++ + 4 * v16;
                    v20 = v17 < (unsigned __int8)v30;
                    *(_DWORD*)& v1[4 * v19] = v18;
                    if (!v20)
                        goto LABEL_36;
                }
            }
        }
        else
        {
            LOBYTE(v26) = 3;
            sub_426AC0(&v26, 1u);
            v10 = (int*)v1;
            v28 = 3;
            do
            {
                v11 = 0;
                v12 = v10;
                v25 = 0;
                v13 = 4;
                do
                {
                    if (*v12)
                        ++v11;
                    ++v12;
                    --v13;
                } while (v13);
                v25 = v11;
                sub_426AC0(&v25, 1u);
                v30 = 4;
                do
                {
                    v14 = *v10;
                    if (*v10)
                    {
                        LOBYTE(v27) = strlen((const char*)sub_4E39D0(*v10));
                        sub_426AC0(&v27, 1u);
                        v24 = (unsigned __int8)v27;
                        v15 = (_BYTE*)sub_4E39D0(v14);
                        sub_426AC0(v15, v24);
                        sub_51DF90(v14);
                    }
                    ++v10;
                    --v30;
                } while (v30);
                v10 = v12;
                --v28;
            } while (v28);
            v1 = v32;
        }
    LABEL_37:
        if ((__int16)v29 >= 62)
        {
            LOBYTE(v26) = 3;
            sub_426AC0(&v26, 1u);
            v21 = 0;
            if ((_BYTE)v26)
            {
                v22 = v1 + 83;
                do
                {
                    sub_426AC0(v22, 1u);
                    ++v21;
                    ++v22;
                } while (v21 < (unsigned __int8)v26);
            }
        }
        if ((__int16)v29 >= 63)
            sub_426AC0(v1 + 92, 4u);
        if (!a1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || sub_4F3E30(v29, (int)a1, a1[34]))
        {
            a1[34] = v33;
            return 1;
        }
    }
    return 0;
}
// 4F7130: using guessed type char var_100[256];

//----- (004F74D0) --------------------------------------------------------
int __cdecl sub_4F74D0(int* a1)
{
    _BYTE* v1; // esi
    int v2; // ebp
    int i; // eax
    char* v4; // eax
    int v5; // edi
    int v6; // eax
    int v7; // edi
    int v8; // eax
    int v9; // ebp
    char* v10; // eax
    int v11; // eax
    int v12; // edi
    int v13; // eax
    int v14; // ebp
    char* v15; // eax
    int v16; // eax
    size_t v18; // [esp-4h] [ebp-124h]
    size_t v19; // [esp-4h] [ebp-124h]
    size_t v20; // [esp-4h] [ebp-124h]
    int v21; // [esp+10h] [ebp-110h]
    int v22; // [esp+14h] [ebp-10Ch]
    int v23; // [esp+18h] [ebp-108h]
    int v24; // [esp+1Ch] [ebp-104h]
    char v25[256]; // [esp+20h] [ebp-100h]

    v1 = (_BYTE*)a1[173];
    v24 = a1[34];
    v23 = 63;
    sub_426AC0(&v23, 2u);
    if ((__int16)v23 <= 63)
    {
        v2 = 0;
        if ((__int16)v23 > 0)
        {
            if (sub_4F4530(a1, (__int16)v23))
            {
                sub_426AC0(v1, 4u);
                sub_426AC0(v1 + 4, 4u);
                v22 = 0;
                for (i = 0; i < 137; ++i)
                {
                    if (v1[i + 8] == 1)
                        ++v22;
                }
                sub_426AC0(&v22, 2u);
                if (*(_DWORD*)& byte_5D4594[3803300])
                {
                    v5 = 0;
                    if ((_WORD)v22)
                    {
                        do
                        {
                            sub_426AC0(&v21, 1u);
                            sub_426AC0(v25, (unsigned __int8)v21);
                            v25[(unsigned __int8)v21] = 0;
                            v6 = sub_4243F0(v25);
                            if (!v6)
                                return 0;
                            v1[v6 + 8] = 1;
                        } while (++v5 < (unsigned __int16)v22);
                    }
                }
                else
                {
                    do
                    {
                        if (v1[v2 + 8])
                        {
                            LOBYTE(v21) = strlen(sub_424870(v2));
                            sub_426AC0(&v21, 1u);
                            v18 = (unsigned __int8)v21;
                            v4 = sub_424870(v2);
                            sub_426AC0(v4, v18);
                        }
                        ++v2;
                    } while (v2 < 137);
                }
                v7 = 0;
                v8 = 0;
                v22 = 0;
                do
                {
                    if (v1[v8 + 145] == 1)
                        ++v22;
                    ++v8;
                } while (v8 < 6);
                sub_426AC0(&v22, 2u);
                if (*(_DWORD*)& byte_5D4594[3803300])
                {
                    if ((_WORD)v22)
                    {
                        do
                        {
                            sub_426AC0(&v21, 1u);
                            sub_426AC0(v25, (unsigned __int8)v21);
                            v25[(unsigned __int8)v21] = 0;
                            v11 = sub_424D80(v25);
                            if (!v11)
                                return 0;
                            v1[v11 + 145] = 1;
                        } while (++v7 < (unsigned __int16)v22);
                    }
                }
                else
                {
                    v9 = 0;
                    do
                    {
                        if (v1[v9 + 145])
                        {
                            LOBYTE(v21) = strlen(sub_425250(v9));
                            sub_426AC0(&v21, 1u);
                            v19 = (unsigned __int8)v21;
                            v10 = sub_425250(v9);
                            sub_426AC0(v10, v19);
                        }
                        ++v9;
                    } while (v9 < 6);
                }
                v12 = 0;
                v13 = 0;
                v22 = 0;
                do
                {
                    if (v1[v13 + 151] == 1)
                        ++v22;
                    ++v13;
                } while (v13 < 41);
                sub_426AC0(&v22, 2u);
                if (*(_DWORD*)& byte_5D4594[3803300])
                {
                    if ((_WORD)v22)
                    {
                        do
                        {
                            sub_426AC0(&v21, 1u);
                            sub_426AC0(v25, (unsigned __int8)v21);
                            v25[(unsigned __int8)v21] = 0;
                            v16 = sub_427010(v25);
                            if (!v16)
                                return 0;
                            v1[v16 + 151] = 1;
                        } while (++v12 < (unsigned __int16)v22);
                    }
                }
                else
                {
                    v14 = 0;
                    do
                    {
                        if (v1[v14 + 151])
                        {
                            LOBYTE(v21) = strlen(sub_427230(v14));
                            sub_426AC0(&v21, 1u);
                            v20 = (unsigned __int8)v21;
                            v15 = sub_427230(v14);
                            sub_426AC0(v15, v20);
                        }
                        ++v14;
                    } while (v14 < 41);
                }
                sub_426AC0(v1 + 196, 4u);
                sub_426AC0(v1 + 192, 4u);
                sub_426AC0(v1 + 200, 4u);
                sub_426AC0(v1 + 204, 4u);
                sub_426AC0(v1 + 208, 4u);
                if ((__int16)v23 >= 62)
                    sub_426AC0(v1 + 212, 4u);
                if ((__int16)v23 >= 63)
                    sub_426AC0(v1 + 216, 1u);
                if (!a1[34] || *(_DWORD*)& byte_5D4594[3803300] != 1 || sub_4F3E30(v23, (int)a1, a1[34]))
                {
                    a1[34] = v24;
                    return 1;
                }
            }
        }
    }
    return 0;
}
// 4F74D0: using guessed type char var_100[256];

//----- (004F78D0) --------------------------------------------------------
void sub_4F78D0()
{
    nox_srand(0x4E34u);
}

//----- (004F78E0) --------------------------------------------------------
int __cdecl sub_4F78E0(int a1, int a2)
{
    int v2; // eax

    if (*(_DWORD*)(a2 + 492) != a1)
        return 0;
    v2 = *(_DWORD*)(a1 + 504);
    if (!v2)
        return 0;
    while (v2 != a2)
    {
        v2 = *(_DWORD*)(v2 + 496);
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (004F7920) --------------------------------------------------------
int __cdecl sub_4F7920(int a1, int a2)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 504);
    if (!result)
        return 0;
    while (*(_DWORD*)(result + 36) != a2)
    {
        result = *(_DWORD*)(result + 496);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004F7950) --------------------------------------------------------
void __cdecl sub_4F7950(int a1)
{
    int v1; // ebp
    int v2; // edi
    int* v3; // esi

    v1 = *(_DWORD*)(a1 + 748);
    v2 = 3;
    v3 = (int*)(v1 + 168);
    do
    {
        if (*v3)
            sub_4E5CC0(*v3);
        *v3 = 0;
        ++v3;
        --v2;
    } while (v2);
    *(_BYTE*)(v1 + 181) = 0;
    *(_BYTE*)(v1 + 180) = 0;
}

//----- (004F79A0) --------------------------------------------------------
void __cdecl sub_4F79A0(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // eax
    float2 v5; // [esp+8h] [ebp-8h]

    v3 = *(_DWORD*)(a1 + 748);
    if (!(*(_BYTE*)(*(_DWORD*)(v3 + 276) + 3680) & 3))
    {
        v4 = *(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 180) + 168);
        if (v4)
        {
            LODWORD(v5.field_0) = a2;
            LODWORD(v5.field_4) = a3;
            sub_4E7010(v4, &v5);
        }
        else
        {
            *(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 180) + 168) = sub_4E3810((CHAR*)& byte_587000[215932]);
            sub_4DAA50(*(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 180) + 168), a1, *(float*)& a2, *(float*)& a3);
        }
    }
}

//----- (004F7A40) --------------------------------------------------------
int __cdecl sub_4F7A40(int a1)
{
    int v1; // edi
    int v2; // ecx
    signed int v3; // edx
    int v4; // edi

    v1 = *(__int16*)(a1 + 126);
    v2 = (unsigned __int8)sub_4FF570(a1, 3);
    v3 = (*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(a1 + 36)) % 0x28u;
    if (v3 > 20)
        v3 = 40 - v3;
    v4 = (v2 + 3) * (v3 - 10) + v1;
    if (v4 < 0)
        v4 += (unsigned int)(255 - v4) >> 8 << 8;
    if (v4 >= 256)
        v4 += -256 * ((unsigned int)v4 >> 8);
    return v4;
}

//----- (004F7AB0) --------------------------------------------------------
_DWORD* __cdecl sub_4F7AB0(float2* a1, int a2)
{
    _DWORD* result; // eax
    int v3; // ebp
    int v4; // ebx
    float2* v5; // edi
    int v6; // esi
    int j; // ebx
    int v8; // ebp
    int v9; // edi
    int i; // esi
    double v11; // st7
    double v12; // st6
    double v13; // st5
    int v14; // esi
    float v15; // [esp+10h] [ebp-10h]
    int v16; // [esp+14h] [ebp-Ch]
    float v17; // [esp+18h] [ebp-8h]
    int v18; // [esp+1Ch] [ebp-4h]

    result = *(_DWORD * *)& byte_5D4594[1568868];
    v3 = 0;
    v16 = 0;
    if (!*(_DWORD*)& byte_5D4594[1568868])
    {
        result = (_DWORD*)sub_4E3AA0((CHAR*)& byte_587000[215948]);
        *(_DWORD*)& byte_5D4594[1568868] = result;
    }
    if (a2)
    {
        if (sub_419130(a2 + 48))
        {
            v16 = *(unsigned __int8*)(a2 + 52);
            sub_418AB0(v16);
            v3 = v16;
        }
        v4 = 0;
        v5 = 0;
        v6 = sub_4DA790();
        if (!v6)
            goto LABEL_13;
        do
        {
            if (*(unsigned __int16*)(v6 + 4) == *(_DWORD*)& byte_5D4594[1568868])
            {
                v5 = (float2*)v6;
                if (sub_4F7CE0(v6, v3))
                    ++v4;
            }
            v6 = sub_4DA7A0(v6);
        } while (v6);
        v18 = v4;
        if (v4)
        {
            v17 = 0.0;
            j = 0;
            v8 = 1;
            v9 = sub_4DA790();
            if (!v9)
                goto LABEL_39;
            do
            {
                if (*(unsigned __int16*)(v9 + 4) == *(_DWORD*)& byte_5D4594[1568868] && sub_4F7CE0(v9, v16))
                {
                    v15 = 10000000.0;
                    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
                    {
                        if (i != a2 && sub_5330C0(a2, i))
                        {
                            v11 = *(float*)(v9 + 56) - *(float*)(i + 56);
                            v12 = *(float*)(v9 + 60) - *(float*)(i + 60);
                            v13 = v12 * v12 + v11 * v11;
                            if (v13 < v15)
                                v15 = v13;
                            v8 = 0;
                        }
                    }
                    if (v15 > (double)v17)
                    {
                        j = v9;
                        v17 = v15;
                    }
                }
                v9 = sub_4DA7A0(v9);
            } while (v9);
            if (v8 || !j)
            {
            LABEL_39:
                v14 = sub_415FA0(0, v18 - 1);
                for (j = sub_4DA790(); j; j = sub_4DA7A0(j))
                {
                    if (*(unsigned __int16*)(j + 4) == *(_DWORD*)& byte_5D4594[1568868] && sub_4F7CE0(j, v16))
                    {
                        if (!v14)
                            break;
                        --v14;
                    }
                }
            }
            result = (_DWORD*)& a1->field_0;
            *a1 = *(float2*)(j + 56);
        }
        else
        {
            if (!v5)
            {
            LABEL_13:
                result = (_DWORD*)& a1->field_0;
                a1->field_0 = 2000.0;
                a1->field_4 = 2000.0;
                return result;
            }
            result = (_DWORD*)& a1->field_0;
            *a1 = v5[7];
        }
    }
    return result;
}

//----- (004F7CE0) --------------------------------------------------------
BOOL __cdecl sub_4F7CE0(int a1, int a2)
{
    return *(_DWORD*)(a1 + 16) & 0x1000000 && (!a2 || !sub_419130(a1 + 48) || sub_419180(a1 + 48, a2));
}

//----- (004F7D30) --------------------------------------------------------
int __cdecl sub_4F7D30(int a1, int a2)
{
    int v2; // eax
    int v3; // ecx
    int v5; // esi

    v2 = *(_DWORD*)(a1 + 8);
    if (v2 & 4)
    {
        v3 = *(_DWORD*)(a1 + 748);
        if (*(unsigned __int8*)(v3 + 91) >= a2)
        {
            *(_BYTE*)(v3 + 91) -= a2;
            sub_4D8800(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), a1);
            return 1;
        }
    }
    else
    {
        if (!(v2 & 2))
            return 1;
        v5 = *(_DWORD*)(a1 + 748);
        if (*(unsigned __int8*)(v5 + 1128) >= a2)
        {
            *(_BYTE*)(v5 + 1128) -= a2;
            return 1;
        }
    }
    return 0;
}

//----- (004F7DB0) --------------------------------------------------------
void __cdecl sub_4F7DB0(int a1, char a2)
{
    int v2; // eax

    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v2 = *(_DWORD*)(a1 + 748);
        *(_BYTE*)(v2 + 91) -= a2;
        sub_4D8800(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), a1);
    }
}

//----- (004F7DF0) --------------------------------------------------------
int __cdecl sub_4F7DF0(int a1)
{
    int v1; // eax
    int v2; // esi
    int v4; // eax

    v1 = *(_DWORD*)& byte_5D4594[1568872];
    if (!*(_DWORD*)& byte_5D4594[1568872])
    {
        v1 = sub_4E3AA0((CHAR*)& byte_587000[216008]);
        *(_DWORD*)& byte_5D4594[1568872] = v1;
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
    v4 = *(_DWORD*)(v2 + 16);
    LOBYTE(v4) = v4 & 0xBF;
    *(_DWORD*)(v2 + 16) = v4;
    sub_52DF80(a1 + 56, v2, 100.0);
    *(_DWORD*)(v2 + 520) = 0;
    sub_4EC300(v2);
    sub_501960(926, a1, 0, 0);
    sub_4E8290(1, 0);
    return 1;
}

//----- (004F7E80) --------------------------------------------------------
int __cdecl sub_4F7E80(int a1)
{
    if (a1 & 0x200)
        return 70;
    if (a1 & 0x4000)
        return 100;
    if (a1 & 0x800)
        return 50;
    if (a1 & 0x100)
        return 45;
    if (a1 & 0x1000)
        return 75;
    if (a1 & 0x2000)
        return 100;
    if (a1 & 0x7FF8000)
        return 45;
    return (a1 & 0x400) != 0 ? 75 : 10;
}

//----- (004F7EF0) --------------------------------------------------------
__int16 __cdecl sub_4F7EF0(int a1)
{
    char* v1; // eax
    char* v2; // ebp
    _DWORD* v3; // edi
    int v4; // ebx
    float v5; // edx
    int v6; // edi
    int v7; // eax
    float2 v9; // [esp+10h] [ebp-8h]

    v1 = sub_416640();
    v2 = v1;
    if (a1)
    {
        v3 = *(_DWORD * *)(a1 + 748);
        v4 = v3[69];
        if (!sub_40A5C0(4096) || (v1 = (char*)v3[137]) == 0)
        {
            if (v4)
                * (_DWORD*)(v4 + 4700) = 0;
            if (sub_40A5C0(4096))
            {
                sub_4EF7D0(a1, 1, 1);
                *((_BYTE*)v3 + *(unsigned __int8*)(v3[69] + 2064) + 452) = -6;
                sub_4DA2C0(a1, "GeneralPrint:Respawn", 0);
            }
            else
            {
                sub_4EF7D0(a1, 1, 0);
            }
            if (sub_40A5C0(4096))
                sub_501960(1006, a1, 0, 0);
            else
                sub_501960(148, a1, 0, 0);
            if (!*(_DWORD*)& byte_5D4594[2650652] || *(_DWORD*)(v2 + 58))
                sub_53FBC0((float*)(a1 + 56), *(__int16*)(a1 + 124));
            v5 = *(float*)(a1 + 60);
            v9.field_0 = *(float*)(a1 + 56);
            v9.field_4 = v5;
            if (sub_40A5C0(4096) && (v6 = v3[77]) != 0)
                sub_4F80C0(v6, &v9);
            else
                sub_4F7AB0(&v9, a1);
            sub_4E7010(a1, &v9);
            if (sub_40A5C0(16))
            {
                if (sub_417DA0(4))
                {
                    v7 = *((_DWORD*)sub_418AB0(*(unsigned __int8*)(*(_DWORD*)(v4 + 2056) + 52)) + 19);
                    if (v7)
                    {
                        if (!*(_DWORD*)(v7 + 492))
                            sub_4F3400(*(_DWORD*)(v4 + 2056), v7, 1);
                    }
                }
            }
            v1 = (char*)sub_40A5C0(0x2000);
            if (v1)
                LOWORD(v1) = sub_4FF380(a1, 23, 5 * *(_WORD*)& byte_5D4594[2649704], 5);
        }
    }
    return (__int16)v1;
}

//----- (004F80C0) --------------------------------------------------------
BOOL __cdecl sub_4F80C0(int a1, float2* a3)
{
    int v2; // ebx
    BOOL result; // eax

    *a3 = *(float2*)(a1 + 56);
    v2 = 32;
    do
    {
        sub_4ED970(60.0, (float2*)(a1 + 56), a3);
        result = sub_411A90(a3);
        if (!result)
            break;
        --v2;
    } while (v2);
    return result;
}

//----- (004F8100) --------------------------------------------------------
char __cdecl sub_4F8100(_DWORD* a1)
{
    _DWORD* v1; // edi
    int v2; // ebx
    int v3; // edx
    int v4; // esi
    _WORD* v5; // ebp
    int v6; // eax
    int v7; // eax
    __int16 v8; // ax
    _DWORD* v9; // eax
    int v10; // ecx
    __int16 v11; // ax
    __int16 v12; // ax
    int v13; // eax
    int v14; // eax
    unsigned __int8 v15; // cl
    int v16; // eax
    double v17; // st7
    int v18; // eax
    float v20; // [esp+0h] [ebp-14h]
    float v21; // [esp+18h] [ebp+4h]

    v1 = a1;
    v2 = 0;
    v3 = 4;
    v4 = a1[187];
    v5 = (_WORD*)a1[139];
    v6 = v4 + 116;
    do
    {
        if (*(_DWORD*)v6 && *(_BYTE*)(*(_DWORD*)v6 + 16) & 0x20)
            * (_DWORD*)v6 = 0;
        v6 += 4;
        --v3;
    } while (v3);
    if (!(a1[4] & 0x20))
    {
        if (sub_40A5C0(4096) && *(_DWORD*)(v4 + 280))
        {
            a1[22] = 0;
            a1[23] = 0;
            a1[20] = 0;
            a1[21] = 0;
        }
        if (sub_40A5C0(4096)
            && (v7 = *(_DWORD*)(v4 + 548)) != 0
            && *(_BYTE*)(*(_DWORD*)(v4 + 276) + 2064) != 31
            && *(_DWORD*)& byte_5D4594[2598000] - v7 > (unsigned int)(30 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            LOBYTE(v6) = sub_4DCFB0((int)a1);
        }
        else
        {
            v8 = *(_WORD*)(v4 + 78);
            if (v8)
            {
                *(_WORD*)(v4 + 78) = v8 - 1;
            }
            else
            {
                if (*(_WORD*)(v4 + 76))
                    v2 = 1000 * (*(unsigned __int16*)(v4 + 76) - (unsigned __int16)* v5) / *(unsigned __int16*)(v4 + 76);
                *(_WORD*)(v4 + 76) = *v5;
                if (v2 > 0)
                    * (_WORD*)(v4 + 78) = 7;
            }
            if (sub_40A5C0(0x4000000))
                sub_4F9E70((int)a1);
            sub_4F9ED0(a1);
            v9 = *(_DWORD * *)(v4 + 276);
            v10 = v9[907];
            if (!v10)
                v10 = v9[514];
            v9[908] = *(_DWORD*)(v10 + 56);
            v9[909] = *(_DWORD*)(v10 + 60);
            v11 = *(_WORD*)(v4 + 160);
            if (v11)
                * (_WORD*)(v4 + 160) = v11 - 1;
            sub_4E44F0((int)a1);
            v12 = *(_WORD*)(v4 + 82);
            if (v12)
                * (_WORD*)(v4 + 82) = v12 - 1;
            v13 = a1[4];
            if ((v13 & 0x8000) == 0)
            {
                if (v2 > 0)
                {
                    v14 = a1[131];
                    if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2252))
                    {
                        if (v14 == 5)
                        {
                            sub_501960(330, (int)a1, 0, 0);
                        }
                        else if (v2 <= 450)
                        {
                            if (v2 <= 70)
                                sub_501960(327, (int)a1, 0, 0);
                            else
                                sub_501960(328, (int)a1, 0, 0);
                        }
                        else
                        {
                            sub_501960(329, (int)a1, 0, 0);
                        }
                    }
                    else if (v14 == 5)
                    {
                        sub_501960(320, (int)a1, 0, 0);
                    }
                    else if (v2 <= 450)
                    {
                        if (v2 <= 70)
                            sub_501960(317, (int)a1, 0, 0);
                        else
                            sub_501960(318, (int)a1, 0, 0);
                    }
                    else
                    {
                        sub_501960(319, (int)a1, 0, 0);
                    }
                }
                v15 = *(_BYTE*)(v4 + 91);
                if (v15 < 0x64u)
                    * (_BYTE*)(v4 + 91) = v15 + 0x64u / *(_DWORD*)& byte_5D4594[2649704];
            }
            v16 = *(_DWORD*)(v4 + 216);
            if (v16
                && !*(_BYTE*)(v4 + 188)
                && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - v16) > * (int*)& byte_5D4594[2614260])
            {
                sub_4FB2A0((int)a1);
                *(_DWORD*)(v4 + 216) = 0;
            }
            sub_4F8420((int)a1);
            sub_4F8460((int)a1);
            if (sub_4FF350((int)a1, 8) && *(_BYTE*)(v4 + 88) != 1)
                sub_4FA020(a1, 5);
            sub_421C70((int)a1);
            v6 = *(_DWORD*)(v4 + 132);
            if (v6)
            {
                v17 = sub_419D40(&byte_587000[216044]);
                v18 = *(_DWORD*)(v4 + 132);
                if (*(_BYTE*)(v18 + 16) & 0x20)
                {
                    LOBYTE(v6) = (unsigned int)sub_537520(a1);
                }
                else
                {
                    sub_4E7540((int)a1, v18);
                    v21 = v17;
                    v20 = -v21;
                    LOBYTE(v6) = sub_52DF80((int)(v1 + 14), *(_DWORD*)(v4 + 132), v20);
                }
            }
        }
    }
    return v6;
}

//----- (004F8420) --------------------------------------------------------
void __cdecl sub_4F8420(int a1)
{
    _DWORD* i; // esi
    int v2; // eax
    int v3; // eax

    for (i = *(_DWORD * *)(a1 + 504); i; i = (_DWORD*)i[124])
    {
        v2 = i[4];
        if (v2 & 0x100)
        {
            LOBYTE(v3) = sub_4F3180(a1, (int)i);
            if (!v3)
                sub_4ED930(a1, i);
        }
    }
}
// 4F8444: variable 'v3' is possibly undefined

//----- (004F8460) --------------------------------------------------------
void __cdecl sub_4F8460(int a1)
{
    int v1; // esi
    int v2; // edi
    char v3; // al
    int v4; // edx
    unsigned __int8* v5; // ebp
    int v6; // ecx
    int v7; // eax
    unsigned __int8 v8; // al
    int v9; // ecx
    unsigned int v10; // eax
    int v11; // ebx
    unsigned __int8 v12; // al
    int v13; // ecx
    unsigned __int8 v14; // cl
    int v15; // kr00_4
    int v16; // ebx
    unsigned int v17; // ecx
    unsigned __int8 v18; // cl
    bool v19; // cc
    int v20; // ecx
    int v21; // eax
    double v22; // st7
    double v23; // st6
    double v24; // st7
    signed int v25; // ebx
    int v26; // eax
    unsigned int v27; // eax
    int v28; // eax
    int v29; // eax
    int v30; // eax
    unsigned int v31; // ecx
    unsigned int v32; // ebx
    unsigned int v33; // ebp
    int v34; // eax
    unsigned int v35; // eax
    int v36; // eax
    int v37; // eax
    int v38; // ecx
    int v39; // esi
    int v40; // edi
    __int16 v41; // ax
    int v42; // ecx
    int j; // edi
    char* v44; // eax
    int i; // edi
    char* v46; // eax
    int v47; // eax
    unsigned __int8* v48; // eax
    signed int v49; // edi
    int v50; // eax
    double v51; // st7
    int v52; // eax
    int v53; // eax
    unsigned __int8 v54; // al
    int v55; // ecx
    int v56; // eax
    int v57; // eax
    int v58; // eax
    int v59; // eax
    int v60; // ecx
    int v61; // eax
    int v62; // eax
    int v63; // eax
    int v64; // eax
    int v65; // eax
    char v66; // al
    int v67; // [esp+10h] [ebp-Ch]
    int v68; // [esp+14h] [ebp-8h]
    int v69; // [esp+18h] [ebp-4h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 748);
    a1 = 0;
    v68 = 0;
    switch (*(unsigned __int8*)(v2 + 88))
    {
    case 0u:
    case 5u:
        if (!sub_4F9BC0(v1))
            goto LABEL_10;
        v20 = *(_DWORD*)(*(_DWORD*)(v1 + 748) + 276);
        if (*(_DWORD*)(v20 + 3656))
        {
            v69 = 3;
            if (*(_BYTE*)(v20 + 2252))
                sub_501960(333, v1, 0, 0);
            else
                sub_501960(323, v1, 0, 0);
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 13, &v69);
            goto LABEL_10;
        }
        v21 = *(_DWORD*)(v2 + 276);
        v68 = 1;
        if (*(_BYTE*)(v2 + 88) != 5
            && (v23 = (double) * (int*)(v21 + 2288) - *(float*)(v1 + 60),
                v22 = (double) * (int*)(v21 + 2284) - *(float*)(v1 + 56),
                v23 * v23 + v22 * v22 <= 10000.0)
            || sub_4FC250(v1, 4))
        {
            a1 = 0;
            goto LABEL_93;
        }
        v24 = *(float*)(v1 + 544) + *(float*)(v1 + 544);
        a1 = 1;
        *(float*)(v1 + 544) = v24;
        sub_4F9F90(6, &v67, &v69);
        v25 = (*(_DWORD*)(v1 + 36) + *(_DWORD*)& byte_5D4594[2598000]) / (unsigned int)(v69 + 1) % v67;
        if (v25 <= (int)((*(_DWORD*)(v1 + 36) + *(_DWORD*)& byte_5D4594[2598000] - 1) / (unsigned int)(v69 + 1) % v67)
            || v25 != 2 && v25 != 8)
        {
            goto LABEL_90;
        }
        v26 = sub_411160((float2*)(v1 + 56));
        if (v26 < 0 || v26 >= *(int*)& byte_5D4594[251568])
            goto LABEL_90;
        v27 = *(_DWORD*)& byte_5D4594[60 * v26 + 2682224];
        if (v27 <= 0x80)
        {
            if (v27 == 128)
            {
                sub_501960(278, v1, 0, 0);
                goto LABEL_90;
            }
            v28 = v27 - 2;
            if (!v28)
                goto LABEL_90;
            v29 = v28 - 6;
            if (!v29)
            {
                sub_501960(277, v1, 0, 0);
                goto LABEL_90;
            }
            if (v29 == 56)
            {
                sub_501960(276, v1, 0, 0);
                goto LABEL_90;
            }
        LABEL_87:
            sub_501960(275, v1, 0, 0);
            goto LABEL_90;
        }
        switch (v27)
        {
        case 0x400u:
            sub_501960(274, v1, 0, 0);
            break;
        case 0x800u:
            sub_501960(279, v1, 0, 0);
            break;
        case 0x4000u:
            break;
        default:
            goto LABEL_87;
        }
    LABEL_90:
        if (sub_415FA0(0, 100) <= 1)
            sub_501960(322, v1, 0, 0);
    LABEL_93:
        if (!sub_4F9AB0(v1))
        {
            if (sub_4FF350(v1, 3))
                * (_WORD*)(v1 + 126) = sub_4F7A40(v1);
            v30 = 8 * *(__int16*)(v1 + 126);
            *(float*)(v1 + 88) = *(float*)& byte_587000[v30 + 194136] * *(float*)(v1 + 544) + *(float*)(v1 + 88);
            *(float*)(v1 + 92) = *(float*)& byte_587000[v30 + 194140] * *(float*)(v1 + 544) + *(float*)(v1 + 92);
        }
        if (!*(_BYTE*)(v2 + 88))
        {
            sub_4F9F90(4, &v67, &v69);
            v31 = *(_DWORD*)(v1 + 36) + *(_DWORD*)& byte_5D4594[2598000];
            v32 = (v31 - 1) / (v69 + 1) % v67;
            v33 = v31 / (v69 + 1) % v67;
            if ((!sub_4FC250(v1, 4) || a1) && v33 != v32 && (v33 == 3 || v33 == 9))
            {
                v34 = sub_411160((float2*)(v1 + 56));
                if (v34 >= 0 && v34 < *(int*)& byte_5D4594[251568])
                {
                    v35 = *(_DWORD*)& byte_5D4594[60 * v34 + 2682224];
                    if (v35 <= 0x80)
                    {
                        if (v35 == 128)
                        {
                            sub_501960(272, v1, 0, 0);
                            goto LABEL_10;
                        }
                        v36 = v35 - 2;
                        if (!v36)
                            goto LABEL_10;
                        v37 = v36 - 6;
                        if (!v37)
                        {
                            sub_501960(271, v1, 0, 0);
                            goto LABEL_10;
                        }
                        if (v37 == 56)
                        {
                            sub_501960(270, v1, 0, 0);
                            goto LABEL_10;
                        }
                    LABEL_116:
                        sub_501960(269, v1, 0, 0);
                        goto LABEL_10;
                    }
                    switch (v35)
                    {
                    case 0x400u:
                        sub_501960(268, v1, 0, 0);
                        break;
                    case 0x800u:
                        sub_501960(273, v1, 0, 0);
                        break;
                    case 0x4000u:
                        break;
                    default:
                        goto LABEL_116;
                    }
                }
            }
        }
    LABEL_10:
        if (sub_51AC40(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064)))
            goto LABEL_247;
        v3 = *(_BYTE*)(v2 + 88);
        if ((!v3 || v3 == 5) && !sub_4F9A80(v1))
        {
            sub_4FA020((_DWORD*)v1, 13);
            *(_DWORD*)(v1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
        }
        v4 = *(_DWORD*)(v2 + 276);
        *(_DWORD*)(v2 + 240) &= 0xFFFFFFE1;
        if (*(_BYTE*)(v4 + 3680) & 3
            || (v69 = sub_4FEE50(31, v1), (v5 = sub_51AB50(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064))) == 0))
        {
        LABEL_247:
            if (v68)
            {
                v66 = *(_BYTE*)(v2 + 88);
                if (v66)
                {
                    if (v66 != 5)
                    {
                        if (sub_4FC250(v1, 4))
                            sub_4FC300((_DWORD*)v1, 4);
                    }
                }
            }
            return;
        }
        while (1)
        {
            if (!v69 || *((_DWORD*)v5 + 2) == 1)
            {
                switch (*((_DWORD*)v5 + 2))
                {
                case 1:
                    if (!sub_4FF350(v1, 25) && (!sub_40A5C0(4096) || !*(_DWORD*)(v2 + 280)) && sub_4FC250(v1, 1) != 1)
                        * (_WORD*)(v1 + 126) = *((_WORD*)v5 + 6);
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    if (sub_4F9BC0(v1))
                    {
                        sub_4FEE90(v1);
                        if (!sub_4FC250(v1, 1)
                            && (*(_BYTE*)(v2 + 88) != 1
                                || *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4) & 0x47F0000 && sub_4FA2B0(v1) != 29))
                        {
                            if (*(_BYTE*)(v2 + 88) == 16)
                            {
                                sub_4FA020((_DWORD*)v1, 17);
                            }
                            else
                            {
                                if (a1)
                                    sub_4FA020((_DWORD*)v1, 5);
                                else
                                    sub_4FA020((_DWORD*)v1, 0);
                                v56 = *(_DWORD*)(v2 + 240);
                                if (v5[12] & 2)
                                    LOBYTE(v56) = v56 | 1;
                                else
                                    LOBYTE(v56) = v56 & 0xFE;
                                *(_DWORD*)(v2 + 240) = v56;
                                if (*((_DWORD*)v5 + 2) == 4)
                                    * (_DWORD*)(v2 + 240) |= 4u;
                                if (*((_DWORD*)v5 + 2) == 5)
                                {
                                    v57 = *(_DWORD*)(v2 + 240);
                                    LOBYTE(v57) = v57 | 2;
                                    *(_DWORD*)(v2 + 240) = v57;
                                }
                                if (*((_DWORD*)v5 + 2) == 2)
                                {
                                    v58 = *(_DWORD*)(v2 + 240);
                                    LOBYTE(v58) = v58 | 8;
                                    *(_DWORD*)(v2 + 240) = v58;
                                }
                                if (*((_DWORD*)v5 + 2) == 3)
                                {
                                    v59 = *(_DWORD*)(v2 + 240);
                                    LOBYTE(v59) = v59 | 0x10;
                                    *(_DWORD*)(v2 + 240) = v59;
                                }
                                *(_DWORD*)(v1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
                            }
                        }
                    }
                    break;
                case 6:
                    if (sub_4F9C40(v1))
                    {
                        if (!sub_40A5C0(128) && !sub_4F7DF0(v1))
                            sub_4F9C70((_DWORD*)v1);
                        if (*(_BYTE*)(v2 + 88) == 10)
                            sub_4FA020((_DWORD*)v1, 13);
                    }
                    break;
                case 7:
                    if (!sub_4F9BC0(v1) || sub_4FC250(v1, 1) || sub_4FC3E0(v1, 2))
                        break;
                    sub_4FEE90(v1);
                    v60 = *(_DWORD*)(*(_DWORD*)(v1 + 748) + 276);
                    if (*(_DWORD*)(v60 + 3656))
                    {
                        v67 = 3;
                        if (*(_BYTE*)(v60 + 2252))
                            sub_501960(333, v1, 0, 0);
                        else
                            sub_501960(323, v1, 0, 0);
                        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 13, &v67);
                    }
                    else if (sub_4F7D30(v1, 90))
                    {
                        if (sub_4FF350(v1, 3))
                            * (_WORD*)(v1 + 126) = sub_4F7A40(v1);
                        *(_DWORD*)(v1 + 16) |= 0x4000u;
                        sub_4FA020((_DWORD*)v1, 12);
                        *(_DWORD*)(v1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
                        return;
                    }
                    break;
                case 0x14:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 1);
                        sub_501960(186, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x15:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 7);
                        sub_501960(190, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x16:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 3);
                        sub_501960(192, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x17:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 5);
                        sub_501960(188, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x18:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 2);
                        sub_501960(187, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x19:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 0);
                        sub_501960(193, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x1A:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 8);
                        sub_501960(189, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x1B:
                    if (!sub_40A5C0(128))
                    {
                        if (!*(_DWORD*)(v2 + 216))
                            sub_4F9B90(v1);
                        *(_DWORD*)(v2 + 184) = sub_424830(*(_DWORD*)(v2 + 184), 6);
                        sub_501960(191, v1, 0, 0);
                        *(_BYTE*)(v2 + 188) = 0;
                    }
                    break;
                case 0x1C:
                    sub_4FA020((_DWORD*)v1, 13);
                    if (!sub_40A5C0(128))
                    {
                        if (*(_DWORD*)(v2 + 216))
                        {
                            sub_4FB2A0(v1);
                            *(_DWORD*)(v2 + 216) = 0;
                        }
                        else
                        {
                            v61 = sub_4ECCB0(*((_DWORD*)v5 + 3));
                            sub_4FB0E0(v1, v61);
                        }
                    }
                    break;
                case 0x1D:
                    sub_4FA020((_DWORD*)v1, 13);
                    if (!sub_40A5C0(128))
                    {
                        if (*(_DWORD*)(v2 + 216))
                        {
                            sub_4FB2A0(v1);
                            *(_DWORD*)(v2 + 216) = 0;
                        }
                        v62 = *(_DWORD*)(v2 + 276);
                        *(_DWORD*)(v2 + 220) = *(_DWORD*)(v62 + 2284);
                        *(_DWORD*)(v2 + 224) = *(_DWORD*)(v62 + 2288);
                        v63 = sub_4ECCB0(*((_DWORD*)v5 + 3));
                        sub_4FB0E0(v1, v63);
                    }
                    break;
                case 0x1E:
                    if (!sub_40A5C0(128))
                    {
                        if (*(_DWORD*)(v2 + 216))
                        {
                            sub_4FB2A0(v1);
                            *(_DWORD*)(v2 + 216) = 0;
                        }
                        v64 = *(_DWORD*)(v2 + 276);
                        *(_DWORD*)(v2 + 220) = *(_DWORD*)(v64 + 2284);
                        *(_DWORD*)(v2 + 224) = *(_DWORD*)(v64 + 2288);
                        v65 = sub_4ECCB0(*((_DWORD*)v5 + 3));
                        sub_4FB1D0(v1, v65);
                    }
                    break;
                default:
                    break;
                }
            }
            v5 = sub_51ABC0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
            if (!v5)
                goto LABEL_247;
        }
    case 1u:
        if (!sub_538960(v1))
        {
            if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 4) & 4)
            {
                sub_4FA020((_DWORD*)v1, 14);
                *(_DWORD*)(v1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
            }
            else
            {
                sub_4FA020((_DWORD*)v1, 13);
                *(_BYTE*)(*(_DWORD*)(v2 + 276) + 8) = 0;
            }
        }
        goto LABEL_10;
    case 2u:
        sub_4F9F90(21, &v67, &v69);
        v54 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v55 = v67;
        *(_BYTE*)(v2 + 236) = v54;
        if (v54 >= v55)
            * (_BYTE*)(v2 + 236) = v55 - 1;
        goto LABEL_10;
    case 3u:
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) > * (int*)& byte_5D4594[2649704])
        {
            sub_4FA020((_DWORD*)v1, 4);
            *(_DWORD*)(v2 + 240) &= 0xFFFFFFDF;
            v38 = *(_DWORD*)(v1 + 16) | 0x18;
            *(_DWORD*)(v1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
            *(_DWORD*)(v1 + 16) = v38;
            *(_DWORD*)(v1 + 84) = 0;
            *(_DWORD*)(v1 + 80) = 0;
            *(_DWORD*)(v1 + 92) = 0;
            *(_DWORD*)(v1 + 88) = 0;
            *(_DWORD*)(v1 + 100) = 0;
            *(_DWORD*)(v1 + 96) = 0;
            v39 = 0;
            if (*(_DWORD*)& byte_5D4594[1599640] > 0)
            {
                v40 = 0;
                do
                {
                    if (!strncmp(
                        "PlayerDeath",
                        *(const char**)(v40 + *(_DWORD*)& byte_5D4594[1599636]),
                        0xBu))
                        sub_507310(v39, 0, 0);
                    ++v39;
                    v40 += 48;
                } while (v39 < *(int*)& byte_5D4594[1599640]);
            }
        }
        return;
    case 4u:
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) <= *(int*)& byte_5D4594[2649704] >> 1)
            return;
        if (!sub_40A5C0(1024)
            || (v41 = sub_40A020(1024), v41 <= 0)
            || (v42 = *(_DWORD*)(v2 + 276), *(_DWORD*)(v42 + 2140) < v41))
        {
            if (sub_40A5C0(0x2000)
                && (v47 = *(_DWORD*)(v2 + 276), !(*(_BYTE*)(v47 + 3680) & 1))
                && (v48 = sub_51AB50(*(unsigned __int8*)(v47 + 2064))) != 0)
            {
                while (*((_DWORD*)v48 + 2) != 6)
                {
                    v48 = sub_51ABC0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
                    if (!v48)
                        goto LABEL_149;
                }
                sub_51AC30(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
                sub_4F7EF0(v1);
            }
            else
            {
            LABEL_149:
                if (!sub_40A5F0())
                    return;
                sub_4F7EF0(v1);
            }
            goto LABEL_10;
        }
        if (*(_BYTE*)(v42 + 3680) & 1)
        {
            a1 = *(_DWORD*)(v42 + 3628);
            sub_4E6040(v1);
            for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
            {
                v46 = sub_417040(*(_DWORD*)(i + 36));
                if (!(*(_DWORD*)(i + 16) & 0x8000) && !(v46[3680] & 1))
                    sub_4E6060(v1, i);
            }
        }
        else
        {
            sub_4174F0(v42, 32);
            sub_4E6860(*(_DWORD*)(v2 + 276), 0, 0);
            sub_4E6040(v1);
            sub_4E60A0(v1);
            if (!sub_4F9E10(v1))
            {
                for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j))
                {
                    v44 = sub_417040(*(_DWORD*)(j + 36));
                    if (!(*(_DWORD*)(j + 16) & 0x8000) && !(v44[3680] & 1))
                        sub_4E6060(v1, j);
                }
            }
        }
        return;
    case 0xAu:
        goto LABEL_9;
    case 0xCu:
        sub_4F9F90(3, &v69, &a1);
        v49 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(a1 + 1);
        v50 = sub_4DA7C0();
        if (!v50)
            goto LABEL_155;
        while (*(_DWORD*)(*(_DWORD*)(v50 + 748) + 132) != v1)
        {
            v50 = sub_4DA7F0(v50);
            if (!v50)
            {
            LABEL_155:
                v51 = *(float*)(v1 + 544) + *(float*)(v1 + 544);
                v52 = 8 * *(__int16*)(v1 + 124);
                *(float*)(v1 + 88) = v51 * *(float*)& byte_587000[v52 + 194136];
                *(float*)(v1 + 92) = v51 * *(float*)& byte_587000[v52 + 194140];
                break;
            }
        }
        if (v49 >= v69)
        {
            sub_4FA020((_DWORD*)v1, 0);
            v53 = *(_DWORD*)(v1 + 16);
            BYTE1(v53) &= 0xBFu;
            *(_DWORD*)(v1 + 16) = v53;
            *(_DWORD*)(v1 + 136) = *(_DWORD*)& byte_5D4594[2598000];
        }
        return;
    case 0xDu:
        *(_DWORD*)(v1 + 16) &= 0xFFFFBFFE;
        if (sub_4F9A80(v1))
            sub_4FA020((_DWORD*)v1, 0);
        if (sub_40A5C0(128)
            || !(**(_DWORD * *)(v2 + 276) & 0x3000000)
            || !sub_533E70(v1)
            && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) <= *(int*)& byte_5D4594[2649704] >> 2)
        {
            goto LABEL_10;
        }
        sub_4FA020((_DWORD*)v1, 15);
    LABEL_9:
        *(_BYTE*)(v2 + 236) = 0;
        goto LABEL_10;
    case 0xEu:
        sub_4F9F90(33, &v69, &v67);
        *(_BYTE*)(v2 + 236) = v69 - 1;
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) > * (int*)& byte_5D4594[2649704])
            sub_4FA020((_DWORD*)v1, 13);
        goto LABEL_10;
    case 0xFu:
        sub_4F9F90(40, &v67, &v69);
        v8 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v9 = v67;
        *(_BYTE*)(v2 + 236) = v8;
        if (v8 >= v9)
        {
            sub_4FA020((_DWORD*)v1, 16);
            *(_BYTE*)(v2 + 236) = v67 - 1;
        }
        goto LABEL_10;
    case 0x10u:
        sub_4F9F90(40, &v69, &v67);
        *(_BYTE*)(v2 + 236) = v69 - 1;
        goto LABEL_10;
    case 0x11u:
        sub_4F9F90(40, &v67, &v69);
        v10 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v11 = v67 - v10;
        if ((int)(v67 - v10) < v67)
        {
            if (v11 <= 0)
            {
                LOBYTE(v11) = 0;
                sub_4FA020((_DWORD*)v1, 13);
            }
            *(_BYTE*)(v2 + 236) = v11;
        }
        else
        {
            *(_BYTE*)(v2 + 236) = v67 - 1;
        }
        goto LABEL_10;
    case 0x12u:
        sub_4F9F90(48, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x13u:
        sub_4F9F90(49, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x14u:
        sub_4F9F90(47, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x15u:
        sub_4F9F90(30, &v69, &v67);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v67 + 1);
        v6 = v69;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x16u:
        sub_4F9F90(31, &v69, &v67);
        *(_BYTE*)(v2 + 236) = v69 - 1;
        goto LABEL_10;
    case 0x17u:
        sub_4F9F90(50, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x18u:
        sub_4F9F90(19, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x19u:
        sub_4F9F90(20, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
        goto LABEL_56;
    case 0x1Au:
        sub_4F9F90(15, &v67, &v69);
        LOBYTE(v7) = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v6 = v67;
        *(_BYTE*)(v2 + 236) = v7;
        v7 = (unsigned __int8)v7;
    LABEL_56:
        v19 = v7 < v6;
        goto LABEL_57;
    case 0x1Bu:
        sub_4F9F90(16, &v67, &v69);
        v14 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v15 = v67;
        *(_BYTE*)(v2 + 236) = v14;
        if (v14 >= v15 / 2)
        {
            sub_4FA020((_DWORD*)v1, 28);
            *(_BYTE*)(v2 + 236) = v67 / 2;
        }
        goto LABEL_10;
    case 0x1Cu:
        sub_4F9F90(16, &v67, &v69);
        *(_BYTE*)(v2 + 236) = v67 / 2;
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) > 0x14)
        {
            sub_4FA020((_DWORD*)v1, 29);
            *(_BYTE*)(v2 + 236) = v67 / 2;
        }
        goto LABEL_10;
    case 0x1Du:
        sub_4F9F90(16, &v67, &v69);
        v16 = v67;
        v17 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        goto LABEL_51;
    case 0x1Eu:
        sub_4F9F90(52, &v67, &v69);
        v12 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
        v13 = v67;
        *(_BYTE*)(v2 + 236) = v12;
        if (v12 >= v13)
        {
            sub_4FA020((_DWORD*)v1, 13);
            *(_DWORD*)(v2 + 164) = 0;
        }
        goto LABEL_10;
    case 0x20u:
        sub_4F9F90(54, &v67, &v69);
        *(_BYTE*)(v2 + 236) = v67 / 2;
        if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) > 0x14)
        {
            sub_4FA020((_DWORD*)v1, 33);
            *(_BYTE*)(v2 + 236) = v67 / 2;
        }
        goto LABEL_10;
    case 0x21u:
        sub_4F9F90(54, &v67, &v69);
        v16 = v67;
        v17 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
    LABEL_51:
        v18 = v16 / 2 + v17;
        *(_BYTE*)(v2 + 236) = v18;
        v19 = v18 < v16;
    LABEL_57:
        if (!v19)
            sub_4FA020((_DWORD*)v1, 13);
        goto LABEL_10;
    default:
        goto LABEL_10;
    }
}

//----- (004F9A80) --------------------------------------------------------
BOOL __cdecl sub_4F9A80(int a1)
{
    return *(_DWORD*)(*(_DWORD*)(a1 + 748) + 4 * *(unsigned __int8*)(*(_DWORD*)(a1 + 748) + 181) + 168) != 0;
}

//----- (004F9AB0) --------------------------------------------------------
int __cdecl sub_4F9AB0(int a1)
{
    int v1; // edi
    int v2; // ecx
    int result; // eax
    double v4; // st7
    int v5; // eax
    double v6; // st7
    float2 v7; // [esp+8h] [ebp-8h]

    v1 = *(_DWORD*)(a1 + 748);
    v2 = *(_DWORD*)(v1 + 4 * *(unsigned __int8*)(v1 + 181) + 168);
    if (!v2)
        return 0;
    v7.field_0 = *(float*)(v2 + 56) - *(float*)(a1 + 56);
    v4 = *(float*)(v2 + 60) - *(float*)(a1 + 60);
    v7.field_4 = v4;
    if (v4 * v7.field_4 + v7.field_0 * v7.field_0 >= 100.0)
    {
        *(_WORD*)(a1 + 126) = sub_509ED0(&v7);
        if (sub_4FF350(a1, 3))
            * (_WORD*)(a1 + 126) = sub_4F7A40(a1);
        v5 = 8 * *(__int16*)(a1 + 126);
        *(float*)(a1 + 88) = *(float*)& byte_587000[v5 + 194136] * *(float*)(a1 + 544) + *(float*)(a1 + 88);
        v6 = *(float*)& byte_587000[v5 + 194140] * *(float*)(a1 + 544);
        result = 1;
        *(float*)(a1 + 92) = v6 + *(float*)(a1 + 92);
    }
    else
    {
        sub_4E5CC0(v2);
        result = 0;
        *(_DWORD*)(v1 + 4 * *(unsigned __int8*)(v1 + 181) + 168) = 0;
    }
    return result;
}

//----- (004F9B90) --------------------------------------------------------
void* __cdecl sub_4F9B90(int a1)
{
    int v1; // esi
    void* result; // eax

    v1 = *(_DWORD*)(a1 + 748);
    result = sub_424820();
    *(_DWORD*)(v1 + 184) = result;
    *(_DWORD*)(v1 + 216) = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (004F9BC0) --------------------------------------------------------
int __cdecl sub_4F9BC0(int a1)
{
    int v1; // esi
    int v3; // eax

    v1 = *(_DWORD*)(a1 + 748);
    if (sub_4FF350(a1, 25))
        return 0;
    if (sub_4FF350(a1, 5))
        return 0;
    if (sub_40A5C0(4096) && *(_DWORD*)(v1 + 280))
        return 0;
    if (*(_BYTE*)(v1 + 88) == 1)
    {
        v3 = *(_DWORD*)(v1 + 104);
        if (v3)
        {
            if (*(_DWORD*)(v3 + 8) & 0x1000000 && *(_BYTE*)(v3 + 12) & 8)
                return 0;
        }
    }
    return 1;
}

//----- (004F9C40) --------------------------------------------------------
BOOL __cdecl sub_4F9C40(int a1)
{
    int v1; // esi
    BOOL result; // eax

    v1 = *(_DWORD*)(a1 + 748);
    if (sub_4FF350(a1, 25))
        result = 0;
    else
        result = *(_BYTE*)(v1 + 88) != 23;
    return result;
}

//----- (004F9C70) --------------------------------------------------------
void __cdecl sub_4F9C70(_DWORD* a1)
{
    int v1; // edi
    int v2; // eax
    int v3; // ebp
    int v4; // eax
    int v5; // eax
    char v6; // bp

    if (a1 && sub_4F9DC0((int)a1))
    {
        v1 = a1[187];
        v2 = *(_DWORD*)(*(_DWORD*)(v1 + 276) + 4);
        if (v2)
        {
            if (v2 & 0x47F0000 && sub_4FA2B0((int)a1) != 29)
            {
                v3 = *(_DWORD*)(*(_DWORD*)(v1 + 104) + 736);
                if (*(_BYTE*)(v3 + 108) || !*(_BYTE*)(v3 + 109))
                {
                    a1[34] = *(_DWORD*)& byte_5D4594[2598000];
                    *(_BYTE*)(v1 + 236) = 0;
                    sub_4FA020(a1, 1);
                    sub_53F8E0((int)a1, *(_DWORD*)(v1 + 104));
                }
                else if (sub_4F7D30((int)a1, 45))
                {
                    v4 = *(_DWORD*)(v3 + 96);
                    LOBYTE(v4) = v4 | 2;
                    *(_DWORD*)(v3 + 96) = v4;
                    a1[34] = *(_DWORD*)& byte_5D4594[2598000];
                    *(_BYTE*)(v1 + 236) = 0;
                    sub_4FA020(a1, 1);
                }
            }
            else if (*(_BYTE*)(v1 + 88) != 1)
            {
                v5 = sub_4F7E80(*(_DWORD*)(*(_DWORD*)(v1 + 276) + 4));
                v6 = v5;
                if (sub_4F7D30((int)a1, v5))
                {
                    a1[34] = *(_DWORD*)& byte_5D4594[2598000];
                    *(_BYTE*)(v1 + 236) = 0;
                    if (!sub_4FA020(a1, 1))
                        sub_4F7DB0((int)a1, -v6);
                }
            }
            sub_4FF5B0((int)a1, 0);
            sub_4FF5B0((int)a1, 23);
            sub_4FEB10(67, (int)a1);
        }
        else if (*(_BYTE*)(v1 + 88) != 1)
        {
            sub_4FA020(a1, 1);
        }
    }
}

//----- (004F9DC0) --------------------------------------------------------
BOOL __cdecl sub_4F9DC0(int a1)
{
    BOOL result; // eax

    if (!a1)
        return 0;
    if (!*(_DWORD*)(*(_DWORD*)(a1 + 748) + 288)
        || sub_5330C0(a1, *(_DWORD*)(*(_DWORD*)(a1 + 748) + 288))
        || (result = sub_40A5C0(4096)))
    {
        result = 1;
    }
    return result;
}

//----- (004F9E10) --------------------------------------------------------
int __cdecl sub_4F9E10(int a1)
{
    int v1; // eax
    int v2; // ecx

    if (!a1)
        return 0;
    if (!*(_DWORD*)(a1 + 520))
        return 0;
    v1 = sub_4EC580(*(_DWORD*)(a1 + 520));
    if (*(_BYTE*)(v1 + 16) & 0x20)
        return 0;
    v2 = *(_DWORD*)(v1 + 8);
    if (v2 & 2 || v2 & 4 && *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(v1 + 748) + 276) + 3680) & 1)
        return 0;
    sub_4E6060(a1, v1);
    return 1;
}

//----- (004F9E70) --------------------------------------------------------
void __cdecl sub_4F9E70(int a1)
{
    int v1; // edx
    int v2; // eax
    _WORD* v3; // ecx

    v1 = sub_40AA50();
    v2 = *(_DWORD*)(a1 + 16);
    v3 = *(_WORD * *)(a1 + 556);
    if ((v2 & 0x8000) == 0
        && v3
        && *v3
        && !(*(_DWORD*)& byte_5D4594[2598000]
            % (v1 * *(_DWORD*)& byte_5D4594[2649704] / (unsigned int)(unsigned __int16)v3[2])))
    {
        sub_4EE5E0(a1, 1);
    }
}

//----- (004F9ED0) --------------------------------------------------------
void __cdecl sub_4F9ED0(_DWORD* a1)
{
    int v1; // ecx
    int v2; // ebx
    unsigned __int16* v3; // eax
    int v4; // ecx
    unsigned __int16 v5; // si

    v1 = a1[4];
    v2 = a1[187];
    v3 = (unsigned __int16*)a1[139];
    if ((v1 & 0x8000) != 0)
        return;
    if (!v3)
        goto LABEL_8;
    v4 = *(_DWORD*)& byte_5D4594[2649704];
    if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - a1[134]) > * (int*)& byte_5D4594[2649704])
    {
        v5 = v3[2];
        if (*v3 < v5
            && v5
            && !(*(_DWORD*)& byte_5D4594[2598000] % (300 * *(_DWORD*)& byte_5D4594[2649704] / (unsigned int)v3[2])))
        {
            sub_4EE460((int)a1, 1);
        LABEL_8:
            v4 = *(_DWORD*)& byte_5D4594[2649704];
            goto LABEL_9;
        }
    }
LABEL_9:
    if (*(_WORD*)(v2 + 4) < *(_WORD*)(v2 + 8)
        && !(*(_DWORD*)& byte_5D4594[2598000] % (300 * v4 / (unsigned int) * (unsigned __int16*)(v2 + 8))))
    {
        sub_4EEB80((int)a1, 1);
    }
}

//----- (004F9F90) --------------------------------------------------------
int __cdecl sub_4F9F90(int a1, _DWORD* a2, int* a3)
{
    int result; // eax

    *a2 = *(_DWORD*)& byte_5D4594[8 * a1 + 1568412];
    result = *(_DWORD*)& byte_5D4594[8 * a1 + 1568416];
    *a3 = result;
    return result;
}

//----- (004F9FB0) --------------------------------------------------------
int __cdecl sub_4F9FB0(int a1, int a2, int a3)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[8 * a1 + 1568412] = a2;
    *(_DWORD*)& byte_5D4594[8 * a1 + 1568416] = a3;
    return result;
}

//----- (004F9FD0) --------------------------------------------------------
int __cdecl sub_4F9FD0(int a1)
{
    int v1; // ecx

    if (!a1)
        return 0;
    v1 = *(_DWORD*)(a1 + 8);
    if (v1 & 4)
        return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2239);
    if (!(v1 & 2))
        return 0;
    if (*(_BYTE*)(a1 + 12) & 0x10)
        return *(unsigned __int8*)(*(_DWORD*)(a1 + 748) + 1324);
    return 30;
}

//----- (004FA020) --------------------------------------------------------
int __cdecl sub_4FA020(_DWORD* a1, int a2)
{
    int v2; // ebx
    int v3; // ebp
    int v4; // eax
    int v5; // esi
    int v7; // eax
    int v8; // eax
    int v9; // ecx

    v2 = a2;
    v3 = 1;
    v4 = a1[4];
    v5 = a1[187];
    if ((v4 & 0x8000) != 0 && a2 != 3 && a2 != 4)
        return 0;
    if (!sub_40A5C0(2048))
    {
        v7 = a1[4];
        if (v7 & 0x4000)
        {
            if (a2 == 30)
                return 0;
        }
    }
    if (a2 == 24 || a2 == 25 || a2 == 26 || a2 == 27 || a2 == 28 || a2 == 29)
    {
        if (sub_4FC250((int)a1, 1))
            return 0;
        if (*(_BYTE*)(v5 + 88) == 12)
            return 0;
    }
    if (*(_BYTE*)(v5 + 88) == 1)
    {
        if (a2 == 1)
            goto LABEL_26;
        if (sub_4FC3E0((int)a1, 2) && a2 != 4 && a2 != 3)
            return 0;
    }
    if (a2 != 1)
    {
        *(_BYTE*)(*(_DWORD*)(v5 + 276) + 8) = 0;
        switch (a2)
        {
        case 3:
        case 4:
            *(_WORD*)(v5 + 160) = 0;
            *(_DWORD*)(v5 + 164) = 0;
            break;
        case 25:
            if (*(unsigned __int8*)(v5 + 88) != a2)
                sub_501960(301, (int)a1, 0, 0);
            break;
        case 26:
            if (*(unsigned __int8*)(v5 + 88) != a2)
                sub_501960(300, (int)a1, 0, 0);
            break;
        case 28:
            if (*(unsigned __int8*)(v5 + 88) != a2)
                sub_501960(302, (int)a1, 0, 0);
            break;
        default:
            goto LABEL_42;
        }
        goto LABEL_42;
    }
LABEL_26:
    if (*(_DWORD*)v5 <= *(int*)& byte_5D4594[2598000])
    {
        v8 = *(_DWORD*)(v5 + 276);
        v9 = *(_DWORD*)(v8 + 4);
        *(_DWORD*)v5 = 0;
        if (v9)
        {
            *(_BYTE*)(v8 + 8) = 0;
        }
        else
        {
            *(_BYTE*)(*(_DWORD*)(v5 + 276) + 8) = sub_415FA0(23, 24);
            if (!*(_BYTE*)(*(_DWORD*)(v5 + 276) + 2251) && sub_415FA0(0, 100) > 75)
                * (_BYTE*)(*(_DWORD*)(v5 + 276) + 8) = 25;
            sub_4FF5B0((int)a1, 0);
            sub_4FF5B0((int)a1, 23);
            sub_4FEB10(67, (int)a1);
        }
    }
    else
    {
        v3 = 0;
        v2 = *(unsigned __int8*)(v5 + 88);
    }
LABEL_42:
    if (*(unsigned __int8*)(v5 + 88) != v2)
    {
        *(_BYTE*)(v5 + 89) = *(_BYTE*)(v5 + 88);
        *(_BYTE*)(v5 + 88) = v2;
        a1[34] = *(_DWORD*)& byte_5D4594[2598000];
        *(_BYTE*)(v5 + 236) = 0;
    }
    if (v2 == 30)
        * (_DWORD*)(v5 + 164) = *(_DWORD*)& byte_5D4594[2598000];
    return v3;
}

//----- (004FA280) --------------------------------------------------------
int __cdecl sub_4FA280(int a1)
{
    int v1; // ecx

    v1 = 2;
    while (!((1 << v1) & a1))
    {
        if (++v1 >= 27)
            return 0;
    }
    return *(_DWORD*)& byte_587000[4 * v1 + 215824];
}

//----- (004FA2B0) --------------------------------------------------------
int __cdecl sub_4FA2B0(int a1)
{
    int v1; // edi
    int result; // eax
    int v3; // ecx

    v1 = *(_DWORD*)(a1 + 748);
    switch (*(unsigned __int8*)(v1 + 88))
    {
    case 0u:
        result = 4;
        break;
    case 1u:
    case 0xEu:
    case 0x16u:
        if (sub_4FC250(a1, 2) && sub_4FC3E0(a1, 2))
        {
            result = 46;
        }
        else if (sub_4FC250(a1, 1))
        {
            result = 45;
        }
        else
        {
            result = *(_DWORD*)(v1 + 276);
            v3 = *(_DWORD*)(result + 4);
            if (v3 & 0x47F0000)
            {
                result = ~(unsigned __int8) * (_DWORD*)(*(_DWORD*)(*(_DWORD*)(v1 + 104) + 736) + 96) & 2;
                LOBYTE(result) = result | 0x1D;
            }
            else if (v3 && v3 != 1 || (LOBYTE(result) = *(_BYTE*)(result + 8), !(_BYTE)result))
            {
                result = sub_4FA280(v3);
            }
            else
            {
                result = (unsigned __int8)result;
            }
        }
        break;
    case 2u:
    case 0xAu:
        result = 21;
        break;
    case 3u:
        result = 1;
        break;
    case 4u:
        result = 2;
        break;
    case 5u:
        result = 6;
        break;
    case 0xCu:
        result = 3;
        break;
    case 0xDu:
        result = (*(_DWORD*)(*(_DWORD*)(v1 + 276) + 4) & 0x400) != 0 ? 0x26 : 0;
        break;
    case 0xFu:
    case 0x10u:
    case 0x11u:
        result = 40;
        break;
    case 0x12u:
        result = 48;
        break;
    case 0x13u:
        result = 49;
        break;
    case 0x14u:
        result = 47;
        break;
    case 0x15u:
        result = 30;
        break;
    case 0x17u:
        result = 50;
        break;
    case 0x18u:
        result = 19;
        break;
    case 0x19u:
        result = 20;
        break;
    case 0x1Au:
        result = 15;
        break;
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Du:
        result = 16;
        break;
    case 0x1Eu:
        result = 52;
        break;
    case 0x20u:
        result = 54;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (004FA490) --------------------------------------------------------
int __cdecl sub_4FA490(int a1)
{
    int result; // eax
    _DWORD* i; // esi
    int* v3; // edi
    int v4; // ebx
    int(__cdecl * v5)(int, _DWORD*, _DWORD); // ecx

    result = a1;
    for (i = *(_DWORD * *)(a1 + 504); i; i = (_DWORD*)i[124])
    {
        result = i[4];
        if (result & 0x100 && i[2] & 0x13001000)
        {
            v3 = (int*)i[173];
            v4 = 4;
            do
            {
                result = *v3;
                if (*v3)
                {
                    v5 = *(int(__cdecl * *)(int, _DWORD*, _DWORD))(result + 100);
                    if (v5)
                        result = v5(result, i, 0);
                }
                ++v3;
                --v4;
            } while (v4);
        }
    }
    return result;
}

//----- (004FA4F0) --------------------------------------------------------
int __cdecl sub_4FA4F0(int a1, int a2)
{
    _DWORD* v2; // edi
    int v3; // eax
    int v4; // ebp
    int* v5; // ebx
    int v6; // esi
    BOOL(__cdecl * v7)(int, int, int, int, int, BOOL*); // eax
    int v8; // eax
    int result; // eax
    int v10; // [esp+10h] [ebp-4h]

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
    LABEL_10:
        v2 = (_DWORD*)v2[124];
        if (!v2)
            return 0;
    }
    v4 = 2;
    v5 = (int*)(v2[173] + 8);
    while (1)
    {
        v6 = *v5;
        v10 = 0;
        if (v6)
        {
            v7 = *(BOOL(__cdecl * *)(int, int, int, int, int, BOOL*))(v6 + 88);
            if (v7)
            {
                if (v7 == sub_4E03D0)
                {
                    v8 = sub_4EC580(a2);
                    (*(void(__cdecl * *)(int, _DWORD*, int, int, int, int*))(v6 + 88))(v6, v2, a1, a2, v8, &v10);
                    result = 1;
                    if (v10 == 1)
                        return result;
                }
            }
        }
        ++v4;
        ++v5;
        if (v4 >= 4)
            goto LABEL_10;
    }
}

//----- (004FA590) --------------------------------------------------------
_DWORD* __cdecl sub_4FA590(int a1, int a2)
{
    int v2; // eax

    v2 = *(_DWORD*)(a1 + 748);
    *(_DWORD*)(*(_DWORD*)(v2 + 276) + 2164) += a2;
    return sub_56F920(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4588), a2);
}

//----- (004FA5D0) --------------------------------------------------------
_DWORD* __cdecl sub_4FA5D0(int a1, unsigned int a2)
{
    int v2; // esi
    int v3; // edx
    unsigned int v4; // eax

    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(_DWORD*)(v2 + 276);
    v4 = *(_DWORD*)(v3 + 2164);
    if (v4 >= a2)
        * (_DWORD*)(v3 + 2164) = v4 - a2;
    else
        *(_DWORD*)(v3 + 2164) = 0;
    return sub_56F920(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4588), -a2);
}

//----- (004FA620) --------------------------------------------------------
_DWORD* __cdecl sub_4FA620(int a1, int a2)
{
    _DWORD* result; // eax
    int v3; // eax
    int v4; // edx

    result = (_DWORD*)a1;
    if (a1 && *(_BYTE*)(a1 + 8) & 4)
    {
        v3 = *(_DWORD*)(a1 + 748);
        if (a2 >= 0 || (v4 = *(_DWORD*)(v3 + 276), *(_DWORD*)(v4 + 2164) >= (unsigned int)-a2))
        {
            *(_DWORD*)(*(_DWORD*)(v3 + 276) + 2164) += a2;
            result = sub_56F920(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4588), a2);
        }
        else
        {
            *(_DWORD*)(v4 + 2164) = 0;
            result = sub_56F7D0(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4588), 0);
        }
    }
    return result;
}

//----- (004FA6B0) --------------------------------------------------------
int __cdecl sub_4FA6B0(int a1)
{
    return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2164);
}

//----- (004FA6D0) --------------------------------------------------------
int __cdecl sub_4FA6D0(int a1)
{
    int result; // eax

    if (a1 && *(_BYTE*)(a1 + 8) & 4)
        result = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2164);
    else
        result = 0;
    return result;
}

//----- (004FA700) --------------------------------------------------------
int __cdecl sub_4FA700(int a1)
{
    int result; // eax
    int v2; // ebp
    _DWORD* v3; // esi
    int v4; // eax
    int v5; // eax
    int v6; // ebp
    unsigned int v7; // edx
    __int16 v8; // ax
    __int16 v9; // ax
    int v10; // ebp
    unsigned int v11; // eax
    int v12; // eax
    __int16 v13; // cx

    result = a1;
    v2 = *(_DWORD*)(a1 + 748);
    if (!*(_DWORD*)(v2 + 292))
    {
        result = (int)nox_calloc(1u, 0x898u);
        *(_DWORD*)(v2 + 292) = result;
    }
    v3 = *(_DWORD * *)(v2 + 292);
    if (v3)
    {
        memset(v3, 0, 0x898u);
        v3[545] = v2;
        v4 = sub_4E3AA0((CHAR*)& byte_587000[216216]);
        v3[121] = sub_517560(v4);
        v3[334] = 1048576000;
        *((_BYTE*)v3 + 1340) = 1;
        v3[336] = 1061997773;
        *((_BYTE*)v3 + 1348) = 1;
        v3[360] = 186376;
        *((_BYTE*)v3 + 1444) = 0;
        *((_BYTE*)v3 + 544) = 0;
        v3[138] = 5;
        v3[340] = 38;
        v3[327] = 1056964608;
        v3[326] = 1062501089;
        v3[328] = 1125515264;
        v3[329] = 1106247680;
        *((_BYTE*)v3 + 1332) = -1;
        v3[330] = 1065353216;
        *((_BYTE*)v3 + 1324) = 30;
        v3[332] = 1056964608;
        v3[338] = 1065353216;
        v3[307] = -1;
        v3[309] = -1;
        v3[311] = -1;
        v3[313] = -1;
        v3[315] = -1;
        v3[317] = -1;
        v3[319] = -1;
        v3[321] = -1;
        v3[323] = -1;
        v3[325] = -1;
        v3[510] = 3;
        v3[524] = -1;
        v3[525] = -1;
        *v3 = -559023410;
        v3[94] = *(__int16*)(a1 + 124);
        v3[95] = *(_DWORD*)(a1 + 56);
        v3[96] = *(_DWORD*)(a1 + 60);
        result = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2251);
        if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
        {
            v5 = result - 1;
            if (v5)
            {
                result = v5 - 1;
                if (!result)
                {
                    v6 = v3[360];
                    v3[339] = 1112014848;
                    v3[410] = 0x8000000;
                    v3[360] = v6 | 0x20;
                    *((_WORD*)v3 + 724) = 0;
                    v7 = *(_DWORD*)& byte_5D4594[2649704];
                    v3[430] = 0x10000000;
                    *((_WORD*)v3 + 725) = v7 >> 1;
                    *((_WORD*)v3 + 728) = 0;
                    *((_WORD*)v3 + 729) = 6 * *(_WORD*)& byte_5D4594[2649704];
                    v3[432] = 0x20000000;
                    v3[446] = 0x20000000;
                    *((_WORD*)v3 + 732) = 3 * *(_WORD*)& byte_5D4594[2649704];
                    v8 = *(_WORD*)& byte_5D4594[2649704];
                    *((_WORD*)v3 + 736) = 0;
                    *((_WORD*)v3 + 733) = 30 * v8;
                    v3[401] = 0x40000000;
                    v3[424] = 0x40000000;
                    v3[456] = 0x40000000;
                    v3[455] = 0x40000000;
                    v3[464] = 0x40000000;
                    v9 = *(_WORD*)& byte_5D4594[2649704];
                    v3[376] = 2147483648;
                    *((_WORD*)v3 + 740) = 0;
                    *((_WORD*)v3 + 737) = 2 * v9;
                    result = *(_DWORD*)& byte_5D4594[2649704];
                    *((_WORD*)v3 + 741) = 6 * *(_WORD*)& byte_5D4594[2649704];
                }
            }
            else
            {
                v10 = v3[360];
                v3[339] = 1112014848;
                v3[410] = 0x8000000;
                v3[360] = v10 | 0x20;
                *((_WORD*)v3 + 724) = 0;
                v11 = *(_DWORD*)& byte_5D4594[2649704];
                *((_WORD*)v3 + 728) = 0;
                *((_WORD*)v3 + 725) = v11 >> 1;
                v3[423] = 0x10000000;
                v3[408] = 0x10000000;
                v3[411] = 0x10000000;
                *((_WORD*)v3 + 729) = *(_WORD*)& byte_5D4594[2649704];
                v3[384] = 0x20000000;
                v3[405] = 0x20000000;
                *((_WORD*)v3 + 732) = 3 * *(_WORD*)& byte_5D4594[2649704];
                *((_WORD*)v3 + 733) = 30 * *(_WORD*)& byte_5D4594[2649704];
                v12 = sub_415FA0(0, 100);
                if (v12 >= 33)
                {
                    if (v12 >= 66)
                    {
                        v3[415] = 0x40000000;
                        v3[422] = 0x40000000;
                    }
                    else
                    {
                        v3[388] = 0x40000000;
                    }
                }
                else
                {
                    v3[399] = 0x40000000;
                }
                *((_WORD*)v3 + 736) = 0;
                v13 = *(_WORD*)& byte_5D4594[2649704];
                v3[376] = 2147483648;
                *((_WORD*)v3 + 740) = 0;
                *((_WORD*)v3 + 737) = 2 * v13;
                result = 6 * *(_DWORD*)& byte_5D4594[2649704];
                *((_WORD*)v3 + 741) = 6 * *(_WORD*)& byte_5D4594[2649704];
            }
        }
        else
        {
            v3[339] = 0;
        }
    }
    return result;
}

//----- (004FAAC0) --------------------------------------------------------
char __cdecl sub_4FAAC0(_DWORD* a1)
{
    int v1; // eax
    int v2; // edx

    v1 = a1[2];
    if (v1 & 4)
    {
        LOBYTE(v1) = v1 & 0xFB | 2;
        v2 = *(_DWORD*)(a1[187] + 292);
        a1[2] = v1;
        a1[187] = v2;
        a1[3] = 16;
    }
    return v1;
}

//----- (004FAAF0) --------------------------------------------------------
char __cdecl sub_4FAAF0(_DWORD* a1)
{
    int v1; // eax
    int v2; // edx

    v1 = a1[2];
    if (v1 & 2)
    {
        LOBYTE(v1) = v1 & 0xFD | 4;
        v2 = *(_DWORD*)(a1[187] + 2180);
        a1[2] = v1;
        a1[187] = v2;
        a1[3] = 0;
    }
    return v1;
}

//----- (004FAB20) --------------------------------------------------------
int __cdecl sub_4FAB20(_DWORD* a1)
{
    int v1; // edi
    int result; // eax
    int v3; // ebx
    int v4; // eax
    char v5; // al
    int v6; // ecx

    v1 = a1[187];
    if (*(_DWORD*)(v1 + 292) || (sub_4FA700((int)a1), (result = *(_DWORD*)(v1 + 292)) != 0))
    {
        result = sub_4FAC70((int)a1);
        if (!result)
        {
            v3 = *(_DWORD*)(v1 + 292);
            v4 = *(_DWORD*)(v3 + 1440);
            BYTE1(v4) |= 1u;
            *(_DWORD*)(v3 + 1440) = v4;
            sub_4FAAC0(a1);
            sub_50A5C0(*(float*)& a1);
            sub_4FAAF0(a1);
            v5 = sub_4FABC0((int)a1);
            v6 = *(_DWORD*)(v1 + 276);
            *(_BYTE*)(v1 + 88) = v5;
            *(_BYTE*)(v1 + 236) = *(_BYTE*)(v3 + 481);
            *(_DWORD*)(v6 + 3632) = a1[14];
            result = a1[15];
            *(_DWORD*)(v6 + 3636) = result;
        }
    }
    else
    {
        a1[186] = sub_4F8100;
    }
    return result;
}

//----- (004FABC0) --------------------------------------------------------
char __cdecl sub_4FABC0(int a1)
{
    int v1; // ecx
    char v2; // al
    char result; // al

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 292);
    v2 = *(_BYTE*)(v1 + 544);
    if (v2 == -1)
        return 13;
    switch (*(_DWORD*)(v1 + 24 * (v2 + 23)))
    {
    case 7:
    case 8:
    case 0xA:
    case 0xD:
    case 0x1D:
        result = (*(_DWORD*)(v1 + 1440) & 0x4000) != 0 ? 5 : 0;
        break;
    case 9:
        result = 0;
        break;
    case 0x10:
    case 0x11:
        result = 1;
        break;
    case 0x12:
    case 0x13:
    case 0x14:
        result = 2;
        break;
    case 0x15:
    case 0x17:
        result = 16;
        break;
    case 0x16:
        result = 17;
        break;
    case 0x18:
        result = 5;
        break;
    case 0x1E:
        result = 3;
        break;
    case 0x1F:
        result = 4;
        break;
    default:
        return 13;
    }
    return result;
}

//----- (004FAC70) --------------------------------------------------------
int __cdecl sub_4FAC70(int a1)
{
    int v1; // edi
    char* v2; // ebx
    float2 v4; // [esp+Ch] [ebp-8h]

    v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 292);
    v2 = sub_416640();
    if (!**(_WORD * *)(a1 + 556))
    {
        if (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 548) < (unsigned int)(2 * *(_DWORD*)& byte_5D4594[2649704]))
            return 1;
        sub_4FA700(a1);
        sub_4EF7D0(a1, 1, 0);
        if (!*(_DWORD*)& byte_5D4594[2650652] || *(_DWORD*)(v2 + 58))
            sub_53FBC0((float*)(a1 + 56), *(__int16*)(a1 + 124));
        sub_4F7AB0(&v4, a1);
        sub_4E7010(a1, &v4);
        sub_501960(148, a1, 0, 0);
        if (sub_40A5C0(0x2000))
            sub_4FF380(a1, 23, 5 * *(_WORD*)& byte_5D4594[2649704], 5);
    }
    return 0;
}

//----- (004FAD50) --------------------------------------------------------
int __cdecl sub_4FAD50(int a1, int a2, int a3, char a4)
{
    int result; // eax
    int v5; // ecx
    char v6[5]; // [esp+0h] [ebp-8h]

    result = a1;
    if (a1 && *(_BYTE*)(a1 + 8) & 4)
    {
        v5 = *(_DWORD*)(a1 + 748);
        v6[0] = -16;
        if (a2)
        {
            if (a2 == 1)
            {
                v6[1] = 31;
            }
            else
            {
                result = a2 - 2;
                if (a2 != 2)
                    return result;
                v6[1] = 32;
            }
        }
        else
        {
            v6[1] = 30;
        }
        *(_WORD*)& v6[3] = *(_WORD*)(a3 + 36);
        v6[2] = a4;
        result = sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), v6, 5, 0, 1);
    }
    return result;
}

//----- (004FADD0) --------------------------------------------------------
void __cdecl sub_4FADD0(int a1, const char* a2, char a3)
{
    unsigned int v4; // kr04_4
    char v5[52]; // [esp+8h] [ebp-34h]

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            if (a2)
            {
                v4 = strlen(a2) + 1;
                if ((_BYTE)v4 != 1 && (unsigned __int8)(v4 - 1) <= 0x30u)
                {
                    v5[51] = a3;
                    v5[0] = -16;
                    v5[1] = 33;
                    strcpy(&v5[2], a2);
                    sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064), v5, 52, 0, 1);
                }
            }
        }
    }
}

//----- (004FAE70) --------------------------------------------------------
void sub_4FAE70()
{
    nox_srand(0x1432u);
}

//----- (004FAE80) --------------------------------------------------------
int __cdecl sub_4FAE80(int a1, int a2, int a3)
{
    int v3; // ebp
    int v4; // edi
    int v5; // eax
    int v6; // ecx
    _DWORD* v7; // eax
    unsigned __int8* v8; // ecx
    _DWORD* v9; // esi
    int v10; // eax
    int* v11; // esi
    int v12; // eax
    char* i; // esi
    int v14; // eax
    wchar_t* v16; // eax
    unsigned __int8* v17; // [esp+10h] [ebp+4h]

    v3 = a1;
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    if (a2 <= 0 || a2 >= 41)
    {
        v16 = loadString_sub_40F1D0((char*)& byte_587000[216340], 0, "C:\\NoxPost\\src\\Server\\Magic\\PlyrGide.c", 39);
        sub_4D9EB0(a1, v16);
        return 0;
    }
    v4 = *(_DWORD*)(a1 + 748);
    v5 = *(_DWORD*)(v4 + 276);
    v6 = *(_DWORD*)(v5 + 4 * a2 + 4244);
    v7 = (_DWORD*)(v5 + 4 * a2 + 4244);
    if (v6)
        return 0;
    *v7 = 1;
    sub_56FCE0(*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4640), a2, *(_DWORD*)(*(_DWORD*)(v4 + 276) + 4 * a2 + 4244));
    if (a3)
    {
        sub_501960(227, a1, 0, 0);
        sub_4FAD50(a1, 1, a1, a2);
    }
    v8 = &byte_587000[216292];
    v17 = &byte_587000[216292];
    if (*(_DWORD*)& byte_587000[216292])
    {
        do
        {
            v9 = *(_DWORD * *)v8;
            if (a2 == **(_DWORD * *)v8)
            {
                v10 = v9[1];
                v11 = v9 + 1;
                if (v10)
                {
                    do
                    {
                        *(_DWORD*)(*(_DWORD*)(v4 + 276) + 4 * v10 + 4244) = 1;
                        sub_56FCE0(
                            *(_DWORD*)(*(_DWORD*)(v4 + 276) + 4640),
                            *v11,
                            *(_DWORD*)(*(_DWORD*)(v4 + 276) + 4 * *v11 + 4244));
                        v10 = v11[1];
                        ++v11;
                    } while (v10);
                    v8 = v17;
                }
            }
            v12 = *((_DWORD*)v8 + 1);
            v8 += 4;
            v17 = v8;
        } while (v12);
    }
    if (a3)
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v14 = *((_DWORD*)i + 514);
            if (v14 != v3)
            {
                if (v14)
                    sub_4FAD50(v14, 1, v3, a2);
            }
        }
    }
    sub_4D8000(v3, a2, a3, 0);
    return 1;
}

//----- (004FB000) --------------------------------------------------------
int __cdecl sub_4FB000(int a1, int a2)
{
    int v2; // esi
    const char* v3; // eax
    int v4; // eax
    int result; // eax

    if (a1
        && a2
        && *(_BYTE*)(a1 + 8) & 4
        && *(_BYTE*)(a2 + 8) & 2
        && (v2 = *(_DWORD*)(a1 + 748), v3 = (const char*)sub_4E39D0(a2), (v4 = sub_427010(v3)) != 0))
    {
        result = *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4 * v4 + 4244);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004FB050) --------------------------------------------------------
int __cdecl sub_4FB050(int a1, int a2, int* a3)
{
    int result; // eax
    float v4; // [esp+0h] [ebp-8h]

    result = sub_4FB000(a1, a2);
    if (result)
    {
        v4 = sub_419D40(&byte_587000[216356]) * (double)* a3 + 0.5;
        result = sub_419A70(v4);
        *a3 = result;
    }
    return result;
}

//----- (004FB090) --------------------------------------------------------
void sub_4FB090()
{
    nox_srand(0x1433u);
}

//----- (004FB0A0) --------------------------------------------------------
void sub_4FB0A0()
{
    nox_srand(0x143Cu);
}

//----- (004FB0B0) --------------------------------------------------------
void __cdecl sub_4FB0B0(int a1)
{
    wchar_t* v1; // eax

    v1 = loadString_sub_40F1D0(*(char**)& byte_587000[4 * a1 + 216380], 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 86);
    sub_445490(v1);
}

//----- (004FB0E0) --------------------------------------------------------
int __cdecl sub_4FB0E0(int a1, int a2)
{
    _DWORD* v2; // edi
    int v3; // esi
    int v5; // ecx
    _DWORD* v6; // eax
    int v7[3]; // [esp+8h] [ebp-Ch]

    v2 = (_DWORD*)a1;
    v3 = *(_DWORD*)(a1 + 748);
    if (!*(_BYTE*)(v3 + 212))
        return 0;
    a1 = sub_4FD150(a1, *(_DWORD*)(v3 + 192), 0);
    v7[0] = a2;
    *(float*)& v7[1] = (double) * (int*)(v3 + 220);
    *(float*)& v7[2] = (double) * (int*)(v3 + 224);
    if (a1)
    {
        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
        sub_501960(231, (int)v2, 0, 0);
    }
    else
    {
        sub_4FDD20(*(_DWORD*)(v3 + 192), v2, v7);
    }
    v5 = 1;
    if (*(_BYTE*)(v3 + 212) > 1u)
    {
        v6 = (_DWORD*)(v3 + 192);
        do
        {
            ++v5;
            *v6 = v6[1];
            ++v6;
        } while (v5 < *(unsigned __int8*)(v3 + 212));
    }
    *(_DWORD*)(v3 + 4 * v5 + 188) = 0;
    --* (_BYTE*)(v3 + 212);
    return 1;
}

//----- (004FB1D0) --------------------------------------------------------
int __cdecl sub_4FB1D0(int a1, int a2)
{
    _DWORD* v2; // edi
    int v3; // esi
    int v5[3]; // [esp+8h] [ebp-Ch]

    v2 = (_DWORD*)a1;
    v3 = *(_DWORD*)(a1 + 748);
    if (!*(_BYTE*)(v3 + 212))
        return 0;
    a1 = sub_4FD150(a1, *(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 212) + 188), 0);
    v5[0] = a2;
    *(float*)& v5[1] = (double) * (int*)(v3 + 220);
    *(float*)& v5[2] = (double) * (int*)(v3 + 224);
    if (a1)
    {
        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
        sub_501960(231, (int)v2, 0, 0);
    }
    else
    {
        sub_4FDD20(*(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 212) + 188), v2, v5);
    }
    --* (_BYTE*)(v3 + 212);
    return 1;
}

//----- (004FB2A0) --------------------------------------------------------
int __cdecl sub_4FB2A0(int a1)
{
    _DWORD* v1; // edi
    int v2; // ebp
    int v3; // esi
    _DWORD* v4; // eax
    int v5; // ebx
    int result; // eax
    int v7; // eax
    int v8; // ebx
    int v9; // ecx
    int v10; // eax
    double v11; // st7
    int* v12; // eax
    wchar_t* v13; // eax
    int v14[3]; // [esp+10h] [ebp-Ch]

    v1 = (_DWORD*)a1;
    v2 = 1;
    v3 = *(_DWORD*)(a1 + 748);
    if (sub_424850(*(void**)(v3 + 184)))
    {
        v2 = 0;
    }
    else
    {
        v4 = *(_DWORD * *)(v3 + 184);
        if (v4 && *v4)
        {
            if (!sub_40A5C0(4096))
            {
                v5 = *(_DWORD*)(v3 + 288);
                if (sub_424A50(**(_DWORD * *)(v3 + 184), 32))
                {
                    if (v5)
                    {
                        result = sub_5330C0((int)v1, v5);
                        if (!result)
                            return result;
                    }
                }
            }
            v7 = **(_DWORD * *)(v3 + 184);
            if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * v7 + 3696) || v7 == 34)
            {
                v2 = 0;
                a1 = sub_4FD0E0((int)v1, v7);
                if (a1 || (a1 = sub_4FD150((int)v1, **(_DWORD * *)(v3 + 184), 0)) != 0)
                {
                    sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
                    sub_501960(231, (int)v1, 0, 0);
                }
                else
                {
                    v8 = sub_4FCF90((int)v1, **(_DWORD * *)(v3 + 184), 1);
                    if (v8 < 0)
                    {
                        a1 = 11;
                        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
                        sub_501960(232, (int)v1, 0, 0);
                    }
                    else
                    {
                        v14[0] = *(_DWORD*)(*(_DWORD*)(v3 + 276) + 3640);
                        if (sub_40A5C0(4096))
                        {
                            if (sub_424A50(**(_DWORD * *)(v3 + 184), 32))
                            {
                                v9 = *(_DWORD*)(v3 + 276);
                                if (*(_DWORD*)(v9 + 3640))
                                {
                                    if (!sub_5330C0((int)v1, *(_DWORD*)(v9 + 3640)))
                                        v14[0] = 0;
                                }
                            }
                        }
                        v10 = *(_DWORD*)(v3 + 276);
                        *(float*)& v14[1] = (double) * (int*)(v10 + 2284);
                        v11 = (double) * (int*)(v10 + 2288);
                        v12 = *(int**)(v3 + 184);
                        *(float*)& v14[2] = v11;
                        if (sub_4FDD20(*v12, v1, v14))
                        {
                            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, *(int**)(v3 + 184));
                        }
                        else
                        {
                            sub_4FD030((int)v1, v8);
                            a1 = 8;
                        }
                    }
                }
            }
        }
    }
    if (*(_BYTE*)(v3 + 88) == 2)
        sub_4FA020(v1, 13);
    if (v2)
    {
        v13 = loadString_sub_40F1D0((char*)& byte_587000[216908], 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 301);
        result = sub_4D9EB0((int)v1, v13);
    }
    else if (a1)
    {
        result = sub_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), **(_DWORD * *)(v3 + 184), 0);
    }
    else
    {
        result = sub_424A50(**(_DWORD * *)(v3 + 184), 0x100000);
        if (!result)
            result = sub_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), **(_DWORD * *)(v3 + 184), 15);
    }
    return result;
}

//----- (004FB550) --------------------------------------------------------
int __cdecl sub_4FB550(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // ebp
    int v6; // esi
    int v7; // ebx
    wchar_t* v8; // eax
    _DWORD* v9; // eax
    int v10; // edx
    int v11; // ebp
    int v12; // edi
    _DWORD* v13; // eax
    int v14; // edx
    int v15; // edi
    char* i; // edi
    int v17; // eax
    _DWORD* v18; // ebx
    int v20; // [esp+14h] [ebp+8h]

    v5 = a1;
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v6 = a2;
    if (a2 <= 0 || a2 >= 137)
    {
        v8 = loadString_sub_40F1D0((char*)& byte_587000[216964], 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 339);
        goto LABEL_76;
    }
    v7 = *(_DWORD*)(a1 + 748);
    if (sub_40A5C0(6144) && *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696) == 3
        || *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696) == 5)
    {
        v8 = loadString_sub_40F1D0((char*)& byte_587000[217020], 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 351);
    LABEL_76:
        sub_4D9EB0(a1, v8);
        return 0;
    }
    if (sub_40A5C0(4096)
        && (a2 == 34
            || a2 == 134
            || a2 == 45
            || a2 == 46
            || a2 == 47
            || a2 == 48
            || a2 == 49
            || a2 == 117
            || a2 == 118
            || a2 == 119
            || a2 == 120
            || a2 == 121
            || a2 == 122
            || a2 == 123
            || a2 == 124
            || a2 == 125
            || a2 == 19)
        && *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696))
    {
        v8 = loadString_sub_40F1D0((char*)& byte_587000[217076], 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 386);
        goto LABEL_76;
    }
    ++* (_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696);
    v9 = (_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696);
    if (*v9 > 5)
        * v9 = 5;
    if (sub_40A5C0(4096))
    {
        v10 = *(_DWORD*)(v7 + 276);
        if (*(_DWORD*)(v10 + 4 * a2 + 3696) > 3)
            * (_DWORD*)(v10 + 4 * a2 + 3696) = 3;
    }
    if (a5)
        * (_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696) = a5;
    sub_56FCE0(*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4636), a2, *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696));
    if (sub_424A50(a2, 4096))
    {
        v20 = 0x2000;
        goto LABEL_41;
    }
    if (sub_424A50(a2, 0x4000))
    {
        v20 = 0x8000;
        goto LABEL_41;
    }
    if (sub_424A50(a2, 0x10000))
    {
        v20 = 0x20000;
    LABEL_41:
        v11 = 1;
        v12 = 3700;
        do
        {
            if (sub_424A50(v11, v20) && sub_424B50(v11))
            {
                if (a5)
                    * (_DWORD*)(v12 + *(_DWORD*)(v7 + 276)) = a5;
                else
                    ++* (_DWORD*)(v12 + *(_DWORD*)(v7 + 276));
                v13 = (_DWORD*)(v12 + *(_DWORD*)(v7 + 276));
                if (*v13 > 5)
                    * v13 = 5;
                if (sub_40A5C0(4096))
                {
                    v14 = *(_DWORD*)(v7 + 276);
                    if (*(_DWORD*)(v14 + 4 * v6 + 3696) > 3)
                        * (_DWORD*)(v14 + 4 * v6 + 3696) = 3;
                }
                sub_56FCE0(*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4636), v6, *(_DWORD*)(v12 + *(_DWORD*)(v7 + 276)));
            }
            v12 += 4;
            ++v11;
        } while (v12 < 4244);
        v5 = a1;
    }
    if (a3)
    {
        v15 = 1;
        sub_501960(226, v5, 0, 0);
        if (sub_40A5C0(2048) && (v6 == 34 || sub_424A50(v6, 86016)))
            v15 = 0;
        if (!sub_40A5C0(4096) || *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4792))
        {
            if (v15)
            {
                sub_4FAD50(v5, 0, v5, v6);
                if (!sub_419E60(v5))
                {
                    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
                    {
                        v17 = *((_DWORD*)i + 514);
                        if (v17 != v5 && v17)
                            sub_4FAD50(v17, 0, v5, v6);
                    }
                }
            }
        }
    }
    if (sub_40A5C0(2048) && a3 == 1 && a4 == 1)
    {
        v18 = *(_DWORD * *)(v7 + 280);
        if (v18)
            sub_50F4C0(v18);
    }
    sub_4D7F90(v5, v6, a3, a4);
    return 1;
}

//----- (004FB940) --------------------------------------------------------
void sub_4FB940()
{
    nox_srand(0x143Du);
}

//----- (004FB950) --------------------------------------------------------
void sub_4FB950()
{
    nox_srand(0x22EAu);
}

//----- (004FB960) --------------------------------------------------------
void __cdecl sub_4FB960(int a1)
{
    wchar_t* v1; // eax

    v1 = loadString_sub_40F1D0(*(char**)& byte_587000[4 * a1 + 217092], 0, "C:\\NoxPost\\src\\Server\\Ability\\Ability.c", 75);
    sub_445490(v1);
}

//----- (004FB990) --------------------------------------------------------
char* sub_4FB990()
{
    char* result; // eax

    memset(&byte_5D4594[1568876], 0, 0x300u);
    result = nox_new_alloc_class("executingAbilityClass", 24, 64);
    *(_DWORD*)& byte_5D4594[1569644] = result;
    return result;
}

//----- (004FB9C0) --------------------------------------------------------
int __cdecl sub_4FB9C0(int a1, int a2, int a3)
{
    int v3; // eax
    int v4; // ecx
    int v5; // edx
    _DWORD* v6; // ecx
    _DWORD* v7; // ecx
    int i; // edi
    int result; // eax
    wchar_t* v10; // eax

    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    if (a2 <= 0 || a2 >= 6)
    {
        v10 = loadString_sub_40F1D0((char*)& byte_587000[217368], 0, "C:\\NoxPost\\src\\Server\\Ability\\Ability.c", 108);
        sub_4D9EB0(a1, v10);
        return 0;
    }
    v3 = *(_DWORD*)(a1 + 748);
    v4 = *(_DWORD*)(v3 + 276);
    v5 = *(_DWORD*)(v4 + 4 * a2 + 3696);
    v6 = (_DWORD*)(v4 + 4 * a2 + 3696);
    if (v5)
    {
        sub_4DA2C0(a1, "use.c:HadAbility", 0);
        result = 0;
    }
    else
    {
        *v6 = 5;
        v7 = (_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * a2 + 3696);
        if (*v7 > 5)
            * v7 = 5;
        sub_56FCE0(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4636), a2, *(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * a2 + 3696));
        sub_4D8060(a1, a2, a3);
        if (sub_40A5C0(4096))
        {
            sub_4FAD50(a1, 2, a1, a2);
            if (!sub_419E60(a1))
            {
                for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
                {
                    if (i != a1)
                        sub_4FAD50(i, 2, a1, a2);
                }
            }
        }
        result = 1;
    }
    return result;
}

//----- (004FBAF0) --------------------------------------------------------
void __cdecl sub_4FBAF0(_DWORD* a1, int a2)
{
    __int16 v2; // ax
    __int16 v3; // ax

    if (!(a1[4] & 0x8020))
    {
        switch (a2)
        {
        case 1:
            sub_53FEB0((int)a1);
            break;
        case 2:
            sub_53FF40((int)a1);
            break;
        case 3:
            sub_540070(a1);
            break;
        case 4:
            v2 = sub_425470(4);
            sub_5400B0(a1, v2);
            break;
        case 5:
            v3 = sub_425470(5);
            sub_540110((int)a1, v3);
            break;
        default:
            return;
        }
    }
}

//----- (004FBB70) --------------------------------------------------------
void __cdecl sub_4FBB70(int a1, int a2)
{
    _DWORD* v2; // esi
    int v3; // edi
    int v4; // ebx
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // ebp
    int v10; // ebx
    _DWORD* v11; // eax
    int v12; // ecx
    int v13; // eax

    v2 = (_DWORD*)a1;
    if (!a1)
        return;
    v3 = a2;
    if (a2 <= 0)
        return;
    if (a2 >= 6)
        return;
    if (*(_DWORD*)(a1 + 16) & 0x8020)
        return;
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return;
    v4 = *(_DWORD*)(a1 + 748);
    if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251))
        return;
    if (sub_40A5C0(32) && v3 == 1)
    {
        v5 = v2[126];
        if (v5)
        {
            while (!(*(_DWORD*)(v5 + 8) & 0x10000000))
            {
                v5 = *(_DWORD*)(v5 + 496);
                if (!v5)
                    goto LABEL_12;
            }
            a1 = 5;
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
            goto LABEL_49;
        }
    LABEL_12:
        v6 = sub_4FC3E0((int)v2, 2);
        goto LABEL_16;
    }
    if (v3 == 2)
    {
        v6 = sub_4FC250((int)v2, 1);
    LABEL_16:
        if (v6)
        {
        LABEL_19:
            a1 = 2;
        LABEL_30:
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
        LABEL_49:
            sub_501960(231, (int)v2, 0, 0);
            return;
        }
        v7 = sub_4FC250((int)v2, 3);
        goto LABEL_18;
    }
    if (v3 == 1)
    {
        v6 = sub_4FC3E0((int)v2, 2);
        goto LABEL_16;
    }
    if (v3 != 3)
        goto LABEL_25;
    if (sub_4FC3E0((int)v2, 2))
        goto LABEL_19;
    v7 = sub_4FC250((int)v2, 1);
LABEL_18:
    if (v7)
        goto LABEL_19;
LABEL_25:
    if (sub_4FC250((int)v2, v3))
        goto LABEL_19;
    if (*(_BYTE*)(v4 + 88) == 12 || !sub_40A5C0(2048) && (v8 = v2[4], BYTE1(v8) & 0x40))
    {
        a1 = 6;
        goto LABEL_30;
    }
    v9 = *(_DWORD*)(v4 + 276);
    if ((!sub_40A5C0(0x2000) || sub_40A5C0(4096)) && !*(_DWORD*)(v9 + 4 * v3 + 3696))
    {
        a1 = 3;
        goto LABEL_48;
    }
    if (v3 == 1 && *(_DWORD*)(*(_DWORD*)(v4 + 276) + 3656) == 1)
    {
        a1 = 7;
        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
        return;
    }
    if (*(_DWORD*)& byte_5D4594[4 * (v3 + 6 * *(unsigned __int8*)(v9 + 2064)) + 1568876])
    {
        a1 = 2;
    LABEL_48:
        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
        goto LABEL_49;
    }
    *(_DWORD*)& byte_5D4594[4 * (v3 + 6 * *(unsigned __int8*)(v9 + 2064)) + 1568876] = sub_4252D0(v3);
    if (sub_4252D0(v3))
        sub_4D8100((int)v2, v3, 0);
    v10 = sub_425470(v3);
    if (v10 > 0)
    {
        v11 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1569644]);
        if (v11)
        {
            v12 = *(_DWORD*)& byte_5D4594[2598000];
            v11[1] = v2;
            *v11 = v3;
            v11[2] = v10 + v12;
            v11[4] = *(_DWORD*)& byte_5D4594[1569648];
            v11[3] = 1;
            v11[5] = 0;
            if (*(_DWORD*)& byte_5D4594[1569648])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1569648] + 20) = v11;
            *(_DWORD*)& byte_5D4594[1569648] = v11;
        }
    }
    sub_4FBAF0(v2, v3);
    v13 = sub_425230(v3, 0);
    sub_501960(v13, (int)v2, 0, 0);
}

//----- (004FBE60) --------------------------------------------------------
int __cdecl sub_4FBE60(int a1, int a2)
{
    char* v2; // eax
    int result; // eax

    v2 = sub_417040(*(_DWORD*)(a1 + 36));
    if (v2)
        result = *(_DWORD*)& byte_5D4594[4 * (a2 + 6 * (unsigned __int8)v2[2064]) + 1568876];
    else
        result = 0;
    return result;
}

//----- (004FBEA0) --------------------------------------------------------
char* __cdecl sub_4FBEA0(int a1, int a2, int a3)
{
    char* result; // eax
    int v4; // edx

    result = sub_417040(*(_DWORD*)(a1 + 36));
    if (result)
    {
        v4 = a2 + 6 * (unsigned __int8)result[2064];
        result = (char*)a3;
        *(_DWORD*)& byte_5D4594[4 * v4 + 1568876] = a3;
    }
    return result;
}

//----- (004FBEE0) --------------------------------------------------------
void sub_4FBEE0()
{
    char* i; // edi
    int j; // esi
    int v2; // eax
    int v3; // ecx
    int* v4; // esi
    int v5; // eax
    int* v6; // edi
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // [esp-Ch] [ebp-14h]

    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        if (*((_DWORD*)i + 514) && !i[2251])
        {
            for (j = 0; j < 6; ++j)
            {
                v2 = j + 6 * (unsigned __int8)i[2064];
                v3 = *(_DWORD*)& byte_5D4594[4 * v2 + 1568876];
                if (v3)
                {
                    *(_DWORD*)& byte_5D4594[4 * v2 + 1568876] = v3 - 1;
                    if (!*(_DWORD*)& byte_5D4594[4 * (j + 6 * (unsigned __int8)i[2064]) + 1568876])
                        sub_4D8100(*((_DWORD*)i + 514), j, 1);
                }
            }
        }
    }
    v4 = *(int**)& byte_5D4594[1569648];
    if (*(_DWORD*)& byte_5D4594[1569648])
    {
        while (1)
        {
            v5 = v4[4];
            v6 = (int*)v4[4];
            if (*(_DWORD*)(v4[1] + 16) & 0x8020)
                break;
            if (*(_DWORD*)& byte_5D4594[2598000] > (unsigned int)v4[2])
            {
                v11 = v4[1];
                v8 = sub_425230(*v4, 2);
                sub_501960(v8, v11, 0, 0);
                sub_4FC3C0(v4[1], *v4, 0);
                if (*v4 == 1)
                    sub_4FA020((_DWORD*)v4[1], 13);
                v9 = v4[4];
                if (v9)
                    * (_DWORD*)(v9 + 20) = v4[5];
                v10 = v4[5];
                if (v10)
                {
                    *(_DWORD*)(v10 + 16) = v4[4];
                    goto LABEL_24;
                }
            LABEL_23:
                *(_DWORD*)& byte_5D4594[1569648] = v4[4];
                goto LABEL_24;
            }
        LABEL_25:
            v4 = v6;
            if (!v6)
                return;
        }
        if (v5)
            * (_DWORD*)(v5 + 20) = v4[5];
        v7 = v4[5];
        if (v7)
        {
            *(_DWORD*)(v7 + 16) = v4[4];
        LABEL_24:
            sub_414330(*(unsigned int**)& byte_5D4594[1569644], v4);
            goto LABEL_25;
        }
        goto LABEL_23;
    }
}

//----- (004FC030) --------------------------------------------------------
int __cdecl sub_4FC030(int a1, int a2)
{
    _DWORD* v2; // eax

    v2 = *(_DWORD * *)& byte_5D4594[1569648];
    if (!*(_DWORD*)& byte_5D4594[1569648])
        return -1;
    while (v2[1] != a1 || *v2 != a2)
    {
        v2 = (_DWORD*)v2[4];
        if (!v2)
            return -1;
    }
    return v2[2] - *(_DWORD*)& byte_5D4594[2598000];
}

//----- (004FC070) --------------------------------------------------------
_DWORD* __cdecl sub_4FC070(int a1, int a2, int a3)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1569648];
    if (*(_DWORD*)& byte_5D4594[1569648])
    {
        while (result[1] != a1 || *result != a2)
        {
            result = (_DWORD*)result[4];
            if (!result)
                return result;
        }
        result[2] = a3 + *(_DWORD*)& byte_5D4594[2598000];
    }
    return result;
}

//----- (004FC0B0) --------------------------------------------------------
void __cdecl sub_4FC0B0(int a1, int a2)
{
    int v2; // eax
    int v3; // esi
    int v4; // eax
    int v5; // edi
    int v6; // eax
    int v7; // eax

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
            if (!*(_BYTE*)(v2 + 2251))
            {
                *(_DWORD*)& byte_5D4594[4 * (a2 + 6 * *(unsigned __int8*)(v2 + 2064)) + 1568876] = 0;
                sub_4D80C0(a1, a2);
                v3 = *(_DWORD*)& byte_5D4594[1569648];
                if (*(_DWORD*)& byte_5D4594[1569648])
                {
                    do
                    {
                        v4 = *(_DWORD*)(v3 + 4);
                        v5 = *(_DWORD*)(v3 + 16);
                        if (v4 == a1 && *(_DWORD*)v3 == a2)
                        {
                            sub_4FC3C0(v4, *(_DWORD*)v3, 0);
                            v6 = *(_DWORD*)(v3 + 16);
                            if (v6)
                                * (_DWORD*)(v6 + 20) = *(_DWORD*)(v3 + 20);
                            v7 = *(_DWORD*)(v3 + 20);
                            if (v7)
                                * (_DWORD*)(v7 + 16) = *(_DWORD*)(v3 + 16);
                            else
                                *(_DWORD*)& byte_5D4594[1569648] = *(_DWORD*)(v3 + 16);
                            sub_414330(*(unsigned int**)& byte_5D4594[1569644], (_QWORD*)v3);
                        }
                        v3 = v5;
                    } while (v5);
                }
            }
        }
    }
}

//----- (004FC180) --------------------------------------------------------
void __cdecl sub_4FC180(int a1)
{
    int v1; // edx
    int i; // eax
    int v3; // ecx
    int v4; // esi
    int v5; // eax
    int v6; // edi
    int v7; // eax
    int v8; // eax

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            v1 = *(_DWORD*)(a1 + 748);
            if (!*(_BYTE*)(*(_DWORD*)(v1 + 276) + 2251))
            {
                for (i = 1; i < 6; ++i)
                {
                    v3 = i + 6 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064);
                    *(_DWORD*)& byte_5D4594[4 * v3 + 1568876] = 0;
                }
                sub_4D80C0(a1, 6);
                v4 = *(_DWORD*)& byte_5D4594[1569648];
                if (*(_DWORD*)& byte_5D4594[1569648])
                {
                    do
                    {
                        v5 = *(_DWORD*)(v4 + 4);
                        v6 = *(_DWORD*)(v4 + 16);
                        if (v5 == a1)
                        {
                            sub_4FC3C0(v5, *(_DWORD*)v4, 0);
                            v7 = *(_DWORD*)(v4 + 16);
                            if (v7)
                                * (_DWORD*)(v7 + 20) = *(_DWORD*)(v4 + 20);
                            v8 = *(_DWORD*)(v4 + 20);
                            if (v8)
                                * (_DWORD*)(v8 + 16) = *(_DWORD*)(v4 + 16);
                            else
                                *(_DWORD*)& byte_5D4594[1569648] = *(_DWORD*)(v4 + 16);
                            sub_414330(*(unsigned int**)& byte_5D4594[1569644], (_QWORD*)v4);
                        }
                        v4 = v6;
                    } while (v6);
                }
            }
        }
    }
}

//----- (004FC250) --------------------------------------------------------
int __cdecl sub_4FC250(int a1, int a2)
{
    int v2; // eax
    _DWORD* v3; // eax
    int v4; // ecx

    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v2 = *(_DWORD*)(a1 + 748);
    if (v2)
    {
        if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
            return 0;
    }
    v3 = *(_DWORD * *)& byte_5D4594[1569648];
    if (!*(_DWORD*)& byte_5D4594[1569648])
        return 0;
    while (1)
    {
        v4 = v3[4];
        if (v3[1] == a1 && *v3 == a2)
            break;
        v3 = (_DWORD*)v3[4];
        if (!v4)
            return 0;
    }
    return 1;
}

//----- (004FC2B0) --------------------------------------------------------
int __cdecl sub_4FC2B0(int a1)
{
    int v1; // eax
    int v2; // eax

    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v1 = *(_DWORD*)(a1 + 748);
    if (v1)
    {
        if (*(_BYTE*)(*(_DWORD*)(v1 + 276) + 2251))
            return 0;
    }
    v2 = *(_DWORD*)& byte_5D4594[1569648];
    if (!*(_DWORD*)& byte_5D4594[1569648])
        return 0;
    while (*(_DWORD*)(v2 + 4) != a1)
    {
        v2 = *(_DWORD*)(v2 + 16);
        if (!v2)
            return 0;
    }
    return 1;
}

//----- (004FC300) --------------------------------------------------------
void __cdecl sub_4FC300(_DWORD* a1, int a2)
{
    int v2; // eax
    int v3; // esi
    int v4; // ecx

    if (a1 && a2 > 0 && a2 < 6)
    {
        switch (a2)
        {
        case 3:
            sub_4D98A0(a1, *(_DWORD * *)(a1[187] + 136));
            break;
        case 4:
            sub_4FF5B0((int)a1, 31);
            break;
        case 5:
            return;
        }
        sub_4FC3C0((int)a1, a2, 0);
        v2 = *(_DWORD*)& byte_5D4594[1569648];
        if (*(_DWORD*)& byte_5D4594[1569648])
        {
            do
            {
                v3 = *(_DWORD*)(v2 + 16);
                if (*(_DWORD * *)(v2 + 4) == a1 && *(_DWORD*)v2 == a2)
                {
                    if (v3)
                        * (_DWORD*)(v3 + 20) = *(_DWORD*)(v2 + 20);
                    v4 = *(_DWORD*)(v2 + 20);
                    if (v4)
                        * (_DWORD*)(v4 + 16) = *(_DWORD*)(v2 + 16);
                    else
                        *(_DWORD*)& byte_5D4594[1569648] = *(_DWORD*)(v2 + 16);
                    sub_414330(*(unsigned int**)& byte_5D4594[1569644], (_QWORD*)v2);
                }
                v2 = v3;
            } while (v3);
        }
    }
}

//----- (004FC3C0) --------------------------------------------------------
int __cdecl sub_4FC3C0(int a1, char a2, char a3)
{
    return sub_4D8150(a1, a2, a3);
}

//----- (004FC3E0) --------------------------------------------------------
int __cdecl sub_4FC3E0(int a1, int a2)
{
    int v2; // eax
    _DWORD* v3; // eax
    int v4; // ecx

    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v2 = *(_DWORD*)(a1 + 748);
    if (v2)
    {
        if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
            return 0;
    }
    v3 = *(_DWORD * *)& byte_5D4594[1569648];
    if (!*(_DWORD*)& byte_5D4594[1569648])
        return 0;
    while (1)
    {
        v4 = v3[4];
        if (v3[1] == a1 && *v3 == a2)
            break;
        v3 = (_DWORD*)v3[4];
        if (!v4)
            return 0;
    }
    return v3[3];
}

//----- (004FC440) --------------------------------------------------------
void __cdecl sub_4FC440(int a1, int a2)
{
    int v2; // eax
    _DWORD* v3; // eax
    int v4; // ecx

    if (*(_BYTE*)(a1 + 8) & 4)
    {
        v2 = *(_DWORD*)(a1 + 748);
        if (!v2 || !*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
        {
            v3 = *(_DWORD * *)& byte_5D4594[1569648];
            if (*(_DWORD*)& byte_5D4594[1569648])
            {
                while (1)
                {
                    v4 = v3[4];
                    if (v3[1] == a1 && *v3 == a2)
                        break;
                    v3 = (_DWORD*)v3[4];
                    if (!v4)
                        return;
                }
                v3[3] = 0;
            }
        }
    }
}

//----- (004FC4A0) --------------------------------------------------------
int __cdecl sub_4FC4A0(int a1, int a2, int a3)
{
    int result; // eax

    result = a3;
    *(_DWORD*)& byte_5D4594[4 * (a2 + 6 * a1) + 1568876] = a3;
    return result;
}

//----- (004FC4C0) --------------------------------------------------------
int __cdecl sub_4FC4C0(int a1)
{
    char* v1; // esi
    int v2; // eax
    int v3; // ecx
    double v4; // st7
    double v5; // st6

    v1 = sub_416EA0();
    if (!v1)
        return 0;
    while (1)
    {
        v2 = *((_DWORD*)v1 + 514);
        if (v2)
        {
            if (!v1[2251])
            {
                if (sub_4FC250(v2, 2))
                {
                    v3 = *((_DWORD*)v1 + 514);
                    v4 = *(float*)(a1 + 56) - *(float*)(v3 + 56);
                    v5 = *(float*)(a1 + 60) - *(float*)(v3 + 60);
                    if (sqrt(v5 * v5 + v4 * v4) + 0.1 < 300.0)
                    {
                        if (sub_537110(v3, a1))
                            break;
                    }
                }
            }
        }
        v1 = sub_416EE0((int)v1);
        if (!v1)
            return 0;
    }
    return 1;
}

//----- (004FC560) --------------------------------------------------------
void sub_4FC560()
{
    nox_srand(0x22EBu);
}

//----- (004FC570) --------------------------------------------------------
int __cdecl sub_4FC570(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1569652] = a1;
    return result;
}

//----- (004FC580) --------------------------------------------------------
int __cdecl sub_4FC580(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1569656] = a1;
    return result;
}

//----- (004FC590) --------------------------------------------------------
int sub_4FC590()
{
    int result; // eax
    int v1; // esi
    int v2; // edi

    result = *(_DWORD*)& byte_5D4594[1569652];
    if (*(_DWORD*)& byte_5D4594[1569652])
    {
        result = sub_4DA7C0();
        if (result)
        {
            v1 = 0;
            if (*(_DWORD*)& byte_5D4594[1599640] > 0)
            {
                v2 = 0;
                do
                {
                    if (!strncmp(
                        "MapInitialize",
                        *(const char**)(v2 + *(_DWORD*)& byte_5D4594[1599636]),
                        0xDu))
                        sub_507310(v1, 0, 0);
                    ++v1;
                    v2 += 48;
                } while (v1 < *(int*)& byte_5D4594[1599640]);
            }
            result = sub_4FC570(0);
        }
    }
    return result;
}

//----- (004FC600) --------------------------------------------------------
int sub_4FC600()
{
    int result; // eax
    int v1; // esi
    int v2; // edi

    result = *(_DWORD*)& byte_5D4594[1569656];
    if (*(_DWORD*)& byte_5D4594[1569656])
    {
        result = sub_4DA7C0();
        if (result)
        {
            v1 = 0;
            if (*(_DWORD*)& byte_5D4594[1599640] > 0)
            {
                v2 = 0;
                do
                {
                    if (!strncmp("MapEntry", *(const char**)(v2 + *(_DWORD*)& byte_5D4594[1599636]), 8u))
                        sub_507310(v1, 0, 0);
                    ++v1;
                    v2 += 48;
                } while (v1 < *(int*)& byte_5D4594[1599640]);
            }
            result = sub_4FC580(0);
        }
    }
    return result;
}

//----- (004FC670) --------------------------------------------------------
int __cdecl sub_4FC670(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1569660] = a1;
    return result;
}

//----- (004FC680) --------------------------------------------------------
void sub_4FC680()
{
    int v0; // eax

    if (sub_40A5C0(2048) && !sub_40A5C0(0x80000) && *(_DWORD*)& byte_5D4594[1569660])
    {
        v0 = sub_4DA7C0();
        if (v0)
        {
            sub_4FBB70(v0, *(int*)& byte_5D4594[1569660]);
            *(_DWORD*)& byte_5D4594[1569660] = 0;
        }
    }
}

//----- (004FC6D0) --------------------------------------------------------
int sub_4FC6D0()
{
    int result; // eax
    char* v1; // eax
    int i; // edi
    int v3; // esi
    int v4; // eax
    BOOL v5; // ebp
    int j; // esi
    int v7; // eax
    CHAR FileName[1024]; // [esp+Ch] [ebp-400h]

    result = *(_DWORD*)& byte_5D4594[1569652];
    if (*(_DWORD*)& byte_5D4594[1569652] == 1 || *(_DWORD*)& byte_5D4594[1569656] == 1)
    {
        result = sub_4DA7C0();
        if (result)
        {
            if (sub_40A5C0(4096))
            {
                if (sub_4E3CC0() == 1)
                {
                    sub_4D6960(255);
                    sub_4D7440(1);
                    sub_4D60B0();
                }
                else if (!sub_4D6F30() || sub_4D7430())
                {
                    if (sub_4D76F0() == 1)
                    {
                        sub_4D6880(255, 1);
                        sub_4D76E0(0);
                        sub_4D7440(1);
                        sub_4D60B0();
                    }
                    else
                    {
                        v1 = sub_409E10();
                        nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v1);
                        for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
                        {
                            v3 = *(_DWORD*)(i + 748);
                            v4 = *(_DWORD*)(v3 + 276);
                            if (*(_DWORD*)(v4 + 4792) == 1
                                && !*(_DWORD*)(v3 + 552)
                                && sub_41A140(FileName, *(unsigned __int8*)(v4 + 2064)))
                            {
                                v5 = sub_419EE0(*(_BYTE*)(*(_DWORD*)(v3 + 276) + 2064));
                                sub_4DCF80(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1);
                                if (!sub_41CFA0(FileName, *(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064)) && !v5)
                                    sub_4DCF80(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0);
                                DeleteFileA(FileName);
                            }
                            sub_4D6770(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064));
                        }
                        sub_4D6880(255, 0);
                        sub_4D7440(1);
                        sub_4D60B0();
                    }
                }
                else
                {
                    sub_4D6960(255);
                    sub_4D7440(1);
                    sub_4D60B0();
                }
            }
            else
            {
                sub_4D9800(1, 1);
            }
            result = sub_40A5C0(0x2000);
            if (result)
            {
                result = sub_40A5C0(128);
                if (!result)
                {
                    result = sub_4DA7C0();
                    for (j = result; result; j = result)
                    {
                        v7 = *(_DWORD*)(*(_DWORD*)(j + 748) + 276);
                        if (*(_BYTE*)(v7 + 2064) != 31 && !(*(_BYTE*)(v7 + 3680) & 1))
                            sub_4FF380(j, 23, 0, 5);
                        result = sub_4DA7F0(j);
                    }
                }
            }
        }
    }
    return result;
}

//----- (004FC950) --------------------------------------------------------
void sub_4FC950()
{
    nox_srand(0x1446u);
}

//----- (004FC960) --------------------------------------------------------
int __cdecl sub_4FC960(int a1, char a2)
{
    int result; // eax
    int i; // esi
    int v4; // eax
    int v5; // [esp-Ch] [ebp-10h]

    result = sub_4DA7C0();
    for (i = result; result; i = result)
    {
        if (i != a1)
        {
            v5 = *(_DWORD*)(i + 36);
            v4 = sub_4FE1C0(*(_DWORD*)(a1 + 36), a2);
            sub_501960(v4, a1, 2, v5);
        }
        result = sub_4DA7F0(i);
    }
    return result;
}

//----- (004FC9B0) --------------------------------------------------------
int sub_4FC9B0()
{
    int result; // eax

    result = sub_4FE850();
    if (result)
    {
        result = nox_new_alloc_class("magicEntityClass", 60, 64);
        *(_DWORD*)& byte_5D4594[1569668] = result;
        if (result)
        {
            result = sub_4E3810((CHAR*)& byte_587000[217476]);
            *(_DWORD*)& byte_5D4594[1569664] = result;
            if (result)
            {
                sub_4DAA50(result, 0, 2944.0, 2944.0);
                *(_DWORD*)& byte_5D4594[1569676] = sub_4E3AA0((CHAR*)& byte_587000[217492]);
                *(_DWORD*)& byte_5D4594[1569680] = sub_4E3AA0((CHAR*)& byte_587000[217500]);
                *(_DWORD*)& byte_5D4594[1569684] = sub_4E3AA0((CHAR*)& byte_587000[217516]);
                *(_DWORD*)& byte_5D4594[1569688] = sub_4E3AA0((CHAR*)& byte_587000[217528]);
                *(_DWORD*)& byte_5D4594[1569692] = sub_4E3AA0((CHAR*)& byte_587000[217540]);
                *(_DWORD*)& byte_5D4594[1569696] = sub_4E3AA0((CHAR*)& byte_587000[217552]);
                *(_DWORD*)& byte_5D4594[1569700] = sub_4E3AA0((CHAR*)& byte_587000[217564]);
                result = 1;
            }
        }
    }
    return result;
}

//----- (004FCA80) --------------------------------------------------------
int sub_4FCA80()
{
    sub_4FE880();
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1569668]);
    *(_DWORD*)& byte_5D4594[1569672] = 0;
    sub_4E5CC0(*(int*)& byte_5D4594[1569664]);
    *(_DWORD*)& byte_5D4594[1569664] = 0;
    return 1;
}

//----- (004FCAC0) --------------------------------------------------------
int __cdecl sub_4FCAC0(int a1, int a2)
{
    int i; // eax
    int v3; // ecx
    _DWORD* v4; // eax

    sub_4FE8A0(a1);
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1569668]);
    *(_DWORD*)& byte_5D4594[1569672] = 0;
    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
    {
        v3 = *(_DWORD*)(i + 748);
        *(_BYTE*)(v3 + 188) = 0;
        *(_DWORD*)(v3 + 216) = 0;
        *(_DWORD*)(v3 + 192) = 0;
        *(_DWORD*)(v3 + 196) = 0;
        *(_DWORD*)(v3 + 200) = 0;
        *(_DWORD*)(v3 + 204) = 0;
        *(_DWORD*)(v3 + 208) = 0;
        *(_BYTE*)(v3 + 212) = 0;
    }
    if (a2)
    {
        v4 = sub_4E3810((CHAR*)& byte_587000[217572]);
        *(_DWORD*)& byte_5D4594[1569664] = v4;
        if (!v4)
            return 0;
        sub_4DAA50((int)v4, 0, 2944.0, 2944.0);
    }
    return 1;
}

//----- (004FCB70) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void sub_4FCB70()
{
    sub_4FCB80();
    sub_4FEEF0();
}

//----- (004FCB80) --------------------------------------------------------
void sub_4FCB80()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax
    int v3; // eax
    int v4; // edi
    int v5; // eax
    int v6; // eax
    int v7; // ebx
    int v8; // edx
    int v9; // ebp
    int v10; // eax
    _DWORD* v11; // ebx
    int v12; // eax
    int v13; // eax
    _DWORD* v14; // eax
    _DWORD* v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // edi
    char* v19; // ebx
    unsigned __int8 v20; // bp
    int v21; // eax
    int v22; // edx
    char v23[2]; // [esp+6h] [ebp-12h]
    int v24; // [esp+8h] [ebp-10h]
    int v25; // [esp+Ch] [ebp-Ch]
    int v26; // [esp+10h] [ebp-8h]
    int v27; // [esp+14h] [ebp-4h]

    v0 = *(_DWORD*)& byte_5D4594[1569672];
    if (*(_DWORD*)& byte_5D4594[1569672])
    {
        while (1)
        {
            v1 = *(_DWORD*)(v0 + 4);
            if (*(_DWORD*)(v1 + 16) & 0x8020)
            {
                v2 = *(_DWORD*)(v0 + 52);
                if (v2)
                    * (_DWORD*)(v2 + 56) = *(_DWORD*)(v0 + 56);
                v3 = *(_DWORD*)(v0 + 56);
                if (!v3)
                    goto LABEL_39;
                *(_DWORD*)(v3 + 52) = *(_DWORD*)(v0 + 52);
                goto LABEL_40;
            }
            if (*(_DWORD*)& byte_5D4594[2598000] < *(int*)(v0 + 40))
                goto LABEL_47;
            v4 = 0;
            if (*(_BYTE*)(v1 + 8) & 4)
                v4 = *(_DWORD*)(v1 + 748);
            if (!*(_BYTE*)(v0 + 36))
            {
                v23[0] = 112;
                v5 = *(_DWORD*)(v4 + 276);
                v23[1] = *(_BYTE*)(v0 + 4 * *(unsigned __int8*)(v0 + 28) + 8);
                sub_40EBC0(*(unsigned __int8*)(v5 + 2064), 1, v23, 2);
            }
            v6 = *(unsigned __int8*)(v0 + 28);
            v7 = **(_DWORD * *)(v0 + 32);
            v24 = *(_DWORD*)(v0 + 4 * v6 + 8);
            v8 = v24;
            if (v7 != v24)
            {
                v19 = sub_416640();
                LOBYTE(v27) = sub_424A20(*(_DWORD*)(v0 + 4 * *(unsigned __int8*)(v0 + 28) + 8))[*(unsigned __int8*)(v0 + 36)];
                v20 = v27;
                if (!*(_DWORD*)& byte_5D4594[2650652] || *(_DWORD*)(v19 + 62))
                    sub_4FC960(*(_DWORD*)(v0 + 4), v27);
                v21 = sub_424830(*(_DWORD*)(v0 + 32), v20);
                v22 = *(_DWORD*)(v0 + 4);
                *(_DWORD*)(v0 + 32) = v21;
                if (*(_BYTE*)(v22 + 8) & 4)
                    * (_DWORD*)(v4 + 184) = *(_DWORD*)(v0 + 32);
                ++* (_BYTE*)(v0 + 36);
                *(_DWORD*)(v0 + 40) = *(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(v0 + 44);
                goto LABEL_47;
            }
            v26 = *(_DWORD*)(v0 + 4 * v6 + 12);
            if (!*(_BYTE*)(v0 + 29))
                goto LABEL_26;
            if (v24 != 34)
                break;
        LABEL_29:
            v14 = *(_DWORD * *)(v0 + 4);
            if (v14[2] & 4)
            {
                v15 = *(_DWORD * *)(v4 + 276);
                *(_DWORD*)(v4 + 220) = v15[571];
                *(_DWORD*)(v4 + 224) = v15[572];
                if (*(_DWORD*)(v0 + 48))
                    v15[910] = *(_DWORD*)(v0 + 4);
                else
                    v15[910] = *(_DWORD*)(v4 + 288);
                sub_4FB2A0(*(_DWORD*)(v0 + 4));
                *(_DWORD*)(v4 + 216) = 0;
                *(_BYTE*)(v4 + 188) = 0;
                *(_BYTE*)(v4 + 212) = 0;
            }
            else
            {
                sub_4FDD20(v8, v14, 0);
            }
            v16 = *(_DWORD*)(v0 + 52);
            if (v16)
                * (_DWORD*)(v16 + 56) = *(_DWORD*)(v0 + 56);
            v17 = *(_DWORD*)(v0 + 56);
            if (!v17)
            {
            LABEL_39:
                *(_DWORD*)& byte_5D4594[1569672] = *(_DWORD*)(v0 + 52);
                goto LABEL_40;
            }
            *(_DWORD*)(v17 + 52) = *(_DWORD*)(v0 + 52);
        LABEL_40:
            v18 = *(_DWORD*)(v0 + 52);
            sub_414330(*(unsigned int**)& byte_5D4594[1569668], (_QWORD*)v0);
            v0 = v18;
        LABEL_48:
            if (!v0)
                return;
        }
        if (*(_BYTE*)(*(_DWORD*)(v0 + 4) + 8) & 4)
        {
            v9 = 0;
            v10 = 1;
            if (!*(_BYTE*)(v4 + 212))
                goto LABEL_51;
            v11 = (_DWORD*)(v4 + 192);
            do
            {
                if (*v11 == v8)
                {
                    v12 = *(_DWORD*)(v4 + 276);
                    v25 = 6;
                    sub_4DA0F0(*(unsigned __int8*)(v12 + 2064), 0, &v25);
                    v8 = v24;
                    v10 = 0;
                }
                ++v9;
                ++v11;
            } while (v9 < *(unsigned __int8*)(v4 + 212));
            if (v10)
            {
            LABEL_51:
                if (sub_4FCF90(*(_DWORD*)(v0 + 4), v8, 2) < 0)
                {
                    v13 = *(_DWORD*)(v4 + 276);
                    v25 = 11;
                    sub_4DA0F0(*(unsigned __int8*)(v13 + 2064), 0, &v25);
                    sub_501960(232, *(_DWORD*)(v0 + 4), 0, 0);
                }
                else
                {
                    *(_DWORD*)(v4 + 4 * (unsigned __int8)(*(_BYTE*)(v4 + 212))++ + 192) = v24;
                }
                v8 = v24;
            }
        }
    LABEL_26:
        if (v8 != 34 && v26)
        {
            *(_BYTE*)(v0 + 36) = 0;
            *(_DWORD*)(v0 + 32) = sub_424820();
            *(_DWORD*)(v0 + 40) = *(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)(v0 + 44);
            ++* (_BYTE*)(v0 + 28);
        LABEL_47:
            v0 = *(_DWORD*)(v0 + 52);
            goto LABEL_48;
        }
        goto LABEL_29;
    }
}

//----- (004FCEB0) --------------------------------------------------------
int __cdecl sub_4FCEB0(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // ecx

    result = sub_4FE930();
    if (result)
    {
        do
        {
            v2 = *(_DWORD*)(result + 116);
            if (a1 != 1 || (v3 = *(_DWORD*)(result + 48)) == 0 || (*(_BYTE*)(v3 + 8) & 4) != 4)
                sub_4FE9D0(result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (004FCEF0) --------------------------------------------------------
int __cdecl sub_4FCEF0(int a1, int* a2, int a3)
{
    int* v3; // ebx
    int v5; // esi
    int v6; // edi
    int v7; // eax
    int v8; // eax

    if (a1)
    {
        v3 = a2;
        if (a2)
        {
            if (a3)
            {
                if (byte_5D4594[2650636] & 0x20)
                    return 1;
                if (*(_BYTE*)(a1 + 8) & 2)
                    return 1;
                v5 = (unsigned __int16)sub_4EEC80(a1);
                v6 = 0;
                if (a3 <= 0)
                    return 1;
                while (1)
                {
                    v7 = *v3;
                    if ((int)* v3 < 75 || v7 > 114)
                        v8 = sub_4249A0(v7, 2);
                    else
                        v8 = sub_500CA0(v7, a1);
                    if (v8 > v5)
                        break;
                    v5 -= v8;
                    ++v6;
                    ++v3;
                    if (v6 >= a3)
                        return 1;
                }
            }
        }
    }
    return 0;
}

//----- (004FCF90) --------------------------------------------------------
int __cdecl sub_4FCF90(int a1, int a2, int a3)
{
    unsigned __int16* v3; // ebp
    int result; // eax
    int v5; // eax
    int v6; // esi

    v3 = *(unsigned __int16**)(a1 + 748);
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return -1;
    if (!a2)
        return -1;
    if (byte_5D4594[2650636] & 0x20)
        return 0;
    if (a2 < 75 || a2 > 114)
        v5 = sub_4249A0(a2, a3);
    else
        v5 = sub_500CA0(a2, a1);
    v6 = v5;
    if (v3[2] >= v5)
    {
        sub_4EEBF0(a1, v5);
        result = v6;
    }
    else
    {
        v3[40] = sub_4249A0(a2, 1);
        result = -1;
        v3[41] = *(_WORD*)& byte_5D4594[2649704];
    }
    return result;
}

//----- (004FD030) --------------------------------------------------------
unsigned __int16 __cdecl sub_4FD030(int a1, __int16 a2)
{
    unsigned __int16 result; // ax

    result = a1;
    if (*(_BYTE*)(a1 + 8) & 4)
        result = sub_4EEB80(a1, a2);
    return result;
}

//----- (004FD050) --------------------------------------------------------
void __cdecl sub_4FD050(_DWORD* a1, int a2)
{
    a1[16] = *(_DWORD*)(a2 + 56);
    a1[17] = *(_DWORD*)(a2 + 60);
    a1[14] = *(_DWORD*)(a2 + 56);
    a1[15] = *(_DWORD*)(a2 + 60);
    a1[18] = *(_DWORD*)(a2 + 56);
    a1[19] = *(_DWORD*)(a2 + 60);
    sub_517970((int)a1);
}

//----- (004FD090) --------------------------------------------------------
void __cdecl sub_4FD090(int a1)
{
    int i; // esi
    int v2; // eax

    for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512))
    {
        if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[1569676])
        {
            v2 = *(_DWORD*)(i + 16);
            if ((v2 & 0x8000) == 0 && !*(_DWORD*)(*(_DWORD*)(i + 748) + 4))
                sub_4FD050((_DWORD*)i, a1);
        }
    }
}

//----- (004FD0E0) --------------------------------------------------------
int __cdecl sub_4FD0E0(int a1, int a2)
{
    int v2; // ebx
    int v4; // eax

    sub_424A70(a2);
    v2 = sub_4EC580(a1);
    if (!sub_424B70(a2))
        return 10;
    if (*(_BYTE*)(a1 + 8) & 4)
        return sub_57AEA0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251), a2);
    v4 = -sub_57AEE0(a2, v2);
    LOBYTE(v4) = v4 & 0xF6;
    return v4 + 10;
}

//----- (004FD150) --------------------------------------------------------
int __cdecl sub_4FD150(int a1, int a2, int a3)
{
    int v3; // eax
    int result; // eax
    int v5; // eax
    int v6; // eax
    int v7; // edi
    double v8; // st7
    int v9; // eax
    int v10; // edx
    int v11; // [esp-14h] [ebp-20h]
    int v12; // [esp-14h] [ebp-20h]

    sub_4EC580(a1);
    if (a3)
        goto LABEL_9;
    if (sub_40A5C0(16))
    {
        if (!*(_DWORD*)& byte_5D4594[1569704])
            * (_DWORD*)& byte_5D4594[1569704] = sub_4E3AA0((CHAR*)& byte_587000[217588]);
        if (sub_424A50(a2, 0x80000))
        {
            v3 = *(_DWORD*)(a1 + 516);
            if (v3)
            {
                while (*(unsigned __int16*)(v3 + 4) != *(_DWORD*)& byte_5D4594[1569704])
                {
                    v3 = *(_DWORD*)(v3 + 512);
                    if (!v3)
                        goto LABEL_9;
                }
                if (sub_419130(a1 + 48))
                    return 17;
            }
        }
        goto LABEL_9;
    }
    if (sub_40A5C0(64))
    {
        if (!*(_DWORD*)& byte_5D4594[1569708])
            * (_DWORD*)& byte_5D4594[1569708] = sub_4E3AA0((CHAR*)& byte_587000[217596]);
        if (sub_424A50(a2, 0x80000))
        {
            v5 = *(_DWORD*)(a1 + 516);
            if (v5)
            {
                while (*(unsigned __int16*)(v5 + 4) != *(_DWORD*)& byte_5D4594[1569708])
                {
                    v5 = *(_DWORD*)(v5 + 512);
                    if (!v5)
                        goto LABEL_9;
                }
                return 16;
            }
        }
    LABEL_9:
        if (sub_4FF350(a1, 29))
            return 14;
        if (!sub_4D7100(a2))
            return 10;
        switch (a2)
        {
        case 29:
            if (sub_4E7C80(a1, *(int*)& byte_5D4594[1569692]) > 0)
                return 3;
            if (sub_4E7C80(a1, *(int*)& byte_5D4594[1569688]) <= 0)
            {
                v10 = *(_DWORD*)& byte_5D4594[1569684];
                goto LABEL_43;
            }
            return 3;
        case 31:
            v9 = sub_4E7C80(a1, *(int*)& byte_5D4594[1569696]);
            goto LABEL_44;
        case 50:
            v7 = sub_4E7C80(a1, *(int*)& byte_5D4594[1569680]);
            v12 = sub_4FE7B0(a2, a1) - 1;
            v8 = sub_419D70(&byte_587000[217620], v12);
            goto LABEL_33;
        case 52:
            v10 = *(_DWORD*)& byte_5D4594[1569700];
        LABEL_43:
            v9 = sub_4E7C80(a1, v10);
        LABEL_44:
            if (v9 <= 0)
                goto LABEL_46;
            return 3;
        case 58:
            v7 = sub_4E7C80(a1, *(int*)& byte_5D4594[1569676]);
            v11 = sub_4FE7B0(a2, a1) - 1;
            v8 = sub_419D70(&byte_587000[217608], v11);
        LABEL_33:
            if (v7 < (int)(__int64)v8)
                goto LABEL_46;
            result = 3;
            break;
        default:
        LABEL_46:
            result = 0;
            break;
        }
        return result;
    }
    if (!sub_40A5C0(32))
        goto LABEL_9;
    if (!sub_424A50(a2, 0x80000))
        goto LABEL_9;
    v6 = *(_DWORD*)(a1 + 504);
    if (!v6)
        goto LABEL_9;
    while (!(*(_DWORD*)(v6 + 8) & 0x10000000))
    {
        v6 = *(_DWORD*)(v6 + 496);
        if (!v6)
            goto LABEL_9;
    }
    return 13;
}

//----- (004FD400) --------------------------------------------------------
int __cdecl sub_4FD400(int a1, int a2, _DWORD* a3, int a4, int* a5, int a6)
{
    int result; // eax
    int(__cdecl * v7)(int, int, int, int, int, int); // eax
    double v8; // st7
    int v9; // edi

    if (!a1)
        return 0;
    if (!a3)
        return 0;
    if (!a2)
        return 0;
    if (!a5)
        return 0;
    if (sub_424A50(a1, 128) && *a5 && !(*(_BYTE*)(*a5 + 8) & 6))
        return 0;
    if (!*a5 || sub_4FDC10(a1, *a5))
    {
        switch (a1)
        {
        case 1:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C390;
            goto LABEL_95;
        case 2:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52DC80;
            goto LABEL_95;
        case 3:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C750;
            goto LABEL_95;
        case 4:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, (int(__cdecl*)(_WORD*))sub_530310, sub_530380, 0, 0);
        case 5:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C3E0;
            goto LABEL_95;
        case 6:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52BBA0;
            goto LABEL_95;
        case 8:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, 0, sub_52F460, 0, 0);
        case 9:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_5011F0,
                sub_5013E0,
                sub_501690,
                0);
        case 10:
        case 11:
            v7 = sub_52D5C0;
            goto LABEL_95;
        case 12:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C1E0;
            goto LABEL_95;
        case 13:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52BBB0;
            goto LABEL_95;
        case 14:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CDB0;
            goto LABEL_95;
        case 15:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C920;
            goto LABEL_95;
        case 16:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52D1E0;
            goto LABEL_95;
        case 17:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C8D0;
            goto LABEL_95;
        case 18:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52BF00;
            goto LABEL_95;
        case 19:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_537E60;
            goto LABEL_95;
        case 21:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_531310,
                sub_531410,
                sub_531420,
                70);
        case 22:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, 0, sub_52E210, 0, 0);
        case 23:
            v7 = sub_52DE40;
            goto LABEL_95;
        case 24:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_52E820,
                sub_52E850,
                (int)nullsub_29,
                30);
        case 26:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52DF40;
            goto LABEL_95;
        case 27:
            v7 = sub_52C790;
            goto LABEL_95;
        case 28:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, 0, sub_52ED40, 0, 3 * *(_DWORD*)& byte_5D4594[2649704]);
        case 29:
            v7 = sub_52D3C0;
            goto LABEL_95;
        case 31:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_52EF30,
                sub_52EFD0,
                sub_52F1D0,
                2 * *(_DWORD*)& byte_5D4594[2649704] / 3u);
        case 32:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C350;
            goto LABEL_95;
        case 33:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C060;
            goto LABEL_95;
        case 34:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_537FA0;
            goto LABEL_95;
        case 35:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, (int(__cdecl*)(_WORD*))sub_52F220, sub_52F2E0, 0, 0);
        case 36:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C640;
            goto LABEL_95;
        case 37:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CA30;
            goto LABEL_95;
        case 38:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52BEB0;
            goto LABEL_95;
        case 39:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C980;
            goto LABEL_95;
        case 40:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C9E0;
            goto LABEL_95;
        case 41:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52DD50;
            goto LABEL_95;
        case 42:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C6D0;
            goto LABEL_95;
        case 43:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_52F820,
                sub_52F8A0,
                sub_530100,
                30);
        case 44:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CE90;
            goto LABEL_95;
        case 45:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CA80;
            goto LABEL_95;
        case 46:
        case 47:
        case 48:
        case 49:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CBD0;
            goto LABEL_95;
        case 50:
            v7 = sub_540160;
            goto LABEL_95;
        case 51:
            return sub_4FEBA0(
                a1,
                a2,
                (_DWORD*)* a5,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_52F5A0,
                sub_52F650,
                sub_52F670,
                0);
        case 52:
            v7 = sub_52D9D0;
            goto LABEL_95;
        case 53:
            v7 = sub_52D8A0;
            goto LABEL_95;
        case 54:
            return sub_4FEBA0(
                a1,
                a2,
                (_DWORD*)* a5,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_531A00,
                0,
                sub_531AF0,
                0);
        case 55:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C230;
            goto LABEL_95;
        case 56:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_530F90,
                sub_5310C0,
                sub_531290,
                0);
        case 57:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CA70;
            goto LABEL_95;
        case 58:
            v7 = sub_540440;
            goto LABEL_95;
        case 59:
            v8 = sub_419D40(&byte_587000[217640]);
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_531580,
                sub_531600,
                sub_5319E0,
                (__int64)v8);
        case 60:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C720;
            goto LABEL_95;
        case 61:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52D150;
            goto LABEL_95;
        case 62:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52D110;
            goto LABEL_95;
        case 63:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52D190;
            goto LABEL_95;
        case 64:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52D1A0;
            goto LABEL_95;
        case 65:
            v7 = sub_52BFA0;
            goto LABEL_95;
        case 66:
            v7 = sub_52C000;
            goto LABEL_95;
        case 67:
            return sub_4FEBA0(
                a1,
                a2,
                (_DWORD*)* a5,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_531490,
                sub_5314F0,
                sub_531560,
                0);
        case 68:
        case 133:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52BF20;
            goto LABEL_95;
        case 69:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52BF50;
            goto LABEL_95;
        case 70:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C680;
            goto LABEL_95;
        case 71:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C5A0;
            goto LABEL_95;
        case 72:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C190;
            goto LABEL_95;
        case 74:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C2C0;
            goto LABEL_95;
        case 75:
        case 76:
        case 77:
        case 78:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:
        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 114:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_500DA0,
                sub_5010D0,
                sub_5011C0,
                0);
        case 115:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, (int(__cdecl*)(_WORD*))sub_530CA0, sub_530D30, 0, 0);
        case 116:
            return sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_530160,
                sub_530250,
                sub_530270,
                0);
        case 117:
        case 118:
        case 119:
        case 120:
        case 122:
        case 123:
        case 124:
        case 125:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, (int(__cdecl*)(_WORD*))sub_5305D0, sub_530650, 0, 0);
        case 121:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, (int(__cdecl*)(_WORD*))sub_530820, sub_530880, 0, 0);
        case 126:
            return sub_4FEBA0(a1, a2, a3, a4, a5, a6, (int(__cdecl*)(_WORD*))sub_530A30, sub_530B70, 0, 0);
        case 127:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52D330;
            goto LABEL_95;
        case 128:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52DB60;
            goto LABEL_95;
        case 129:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52CCD0;
            goto LABEL_95;
        case 130:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C530;
            goto LABEL_95;
        case 131:
            v7 = (int(__cdecl*)(int, int, int, int, int, int))sub_52C270;
        LABEL_95:
            v9 = v7(a1, a2, (int)a3, a4, (int)a5, a6);
            if (!v9)
                sub_501960(231, a4, 0, 0);
            result = v9;
            break;
        case 132:
            result = sub_4FEBA0(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                (int(__cdecl*)(_WORD*))sub_4FFA90,
                sub_500070,
                sub_500080,
                0);
            break;
        default:
            result = 1;
            break;
        }
    }
    else
    {
        sub_501960(231, *a5, 0, 0);
        result = 0;
    }
    return result;
}
// 52ED30: using guessed type void nullsub_29();

//----- (004FDC10) --------------------------------------------------------
int __cdecl sub_4FDC10(int a1, int a2)
{
    int v3; // esi
    int v4; // eax
    int v5; // esi

    if (!*(_DWORD*)& byte_5D4594[1569712])
    {
        *(_DWORD*)& byte_5D4594[1569712] = sub_4E3AA0((CHAR*)& byte_587000[217660]);
        *(_DWORD*)& byte_5D4594[1569716] = sub_4E3AA0((CHAR*)& byte_587000[217672]);
    }
    if (!a2)
        return 0;
    if (sub_424A50(a1, 0x80000) && *(_BYTE*)(a2 + 8) & 4)
    {
        v3 = *(_DWORD*)(a2 + 748);
        if (sub_40A5C0(32))
        {
            if (*(_BYTE*)(*(_DWORD*)(v3 + 276) + 4) & 1)
                return 0;
        }
        else if (sub_40A5C0(64))
        {
            v4 = *(_DWORD*)(a2 + 516);
            if (v4)
            {
                while (*(unsigned __int16*)(v4 + 4) != *(_DWORD*)& byte_5D4594[1569712])
                {
                    v4 = *(_DWORD*)(v4 + 512);
                    if (!v4)
                        return 1;
                }
                return 0;
            }
        }
        else if (sub_40A5C0(16))
        {
            v5 = *(_DWORD*)(a2 + 516);
            if (v5)
            {
                while (*(unsigned __int16*)(v5 + 4) != *(_DWORD*)& byte_5D4594[1569716] || !sub_419130(a2 + 48))
                {
                    v5 = *(_DWORD*)(v5 + 512);
                    if (!v5)
                        return 1;
                }
                return 0;
            }
        }
    }
    return 1;
}

//----- (004FDD20) --------------------------------------------------------
int __cdecl sub_4FDD20(int a1, _DWORD* a2, int* a3)
{
    int v3; // ebx

    v3 = sub_4FE7B0(a1, (int)a2);
    if (sub_424A50(a1, 32))
    {
        sub_4FF5B0((int)a2, 0);
        sub_4FF5B0((int)a2, 23);
        sub_4FEB10(67, (int)a2);
    }
    if (!sub_424A50(a1, 4) || a2 == (_DWORD*)* a3)
        return sub_4FD400(a1, (int)a2, a2, (int)a2, a3, v3);
    sub_4FDDA0((int)a2, *a3, a1);
    return 1;
}

//----- (004FDDA0) --------------------------------------------------------
_DWORD* __cdecl sub_4FDDA0(int a1, int a2, int a3)
{
    int v3; // esi
    int v4; // eax
    int v5; // eax
    int v6; // eax
    float v7; // edx
    double v8; // st7
    double v9; // st7
    double v10; // st6
    _DWORD* result; // eax
    _DWORD* v12; // edi
    int* v13; // ebx
    __int16 v14; // ax
    int v15; // ecx
    __int16 v16; // ax
    int v17; // eax
    int v18; // [esp-10h] [ebp-34h]
    int v19; // [esp-10h] [ebp-34h]
    char v20; // [esp-4h] [ebp-28h]
    int2 v21; // [esp+Ch] [ebp-18h]
    float4 v22; // [esp+14h] [ebp-10h]
    float a2a; // [esp+28h] [ebp+4h]

    v3 = a1;
    a2a = *(float*)(a1 + 176) + 4.0;
    if (!a2)
    {
        if (*(_BYTE*)(v3 + 8) & 4)
        {
            v4 = *(_DWORD*)(v3 + 748);
            *(float*)& v21.field_0 = (double) * (int*)(*(_DWORD*)(v4 + 276) + 2284);
            *(float*)& v21.field_4 = (double) * (int*)(*(_DWORD*)(v4 + 276) + 2288);
            v18 = sub_424A70(a3);
            v5 = sub_540610((float2*)& v21, v3, v18, 600.0, 0, v3);
        }
        else
        {
            v19 = sub_424A70(a3);
            v5 = sub_540610(0, v3, v19, 600.0, 0, v3);
        }
        a2 = v5;
    }
    v6 = 8 * *(__int16*)(v3 + 124);
    v7 = *(float*)(v3 + 60);
    v8 = a2a * *(float*)& byte_587000[v6 + 194136];
    v22.field_0 = *(float*)(v3 + 56);
    v9 = v8 + *(float*)(v3 + 56);
    v10 = a2a * *(float*)& byte_587000[v6 + 194140];
    v22.field_4 = v7;
    v22.field_C = v10 + *(float*)(v3 + 60);
    v22.field_8 = v9 + *(float*)(v3 + 80);
    v22.field_C = v22.field_C + *(float*)(v3 + 84);
    result = (_DWORD*)sub_535250(&v22, 0, 0, 5);
    if (result)
    {
        result = sub_4E3810((CHAR*)& byte_587000[217680]);
        v12 = result;
        if (result)
        {
            v13 = (int*)result[187];
            v13[4] = sub_4FE7B0(a3, v3);
            sub_4DAA50((int)v12, v3, v22.field_8, v22.field_C);
            v14 = *(_WORD*)(v3 + 124);
            *((_WORD*)v12 + 62) = v14;
            *((_WORD*)v12 + 63) = v14;
            *v13 = v3;
            v13[1] = a2;
            v13[2] = v3;
            v13[3] = a3;
            sub_509E20(*(__int16*)(v3 + 124), &v21);
            v15 = *((__int16*)v12 + 62);
            *((float*)v12 + 20) = *(float*)& byte_587000[8 * v15 + 194136] * *((float*)v12 + 136);
            *((float*)v12 + 21) = *(float*)& byte_587000[8 * v15 + 194140] * *((float*)v12 + 136);
            *((float*)v12 + 20) = *((float*)v12 + 20) + *(float*)(v3 + 80);
            *((float*)v12 + 21) = *((float*)v12 + 21) + *(float*)(v3 + 84);
            if (sub_4FF350(v3, 21))
            {
                v20 = sub_4FF570(v3, 21);
                v16 = sub_4FF550(v3, 21);
                sub_4FF380((int)v12, 21, v16, v20);
            }
            v17 = sub_424800(a3, 0);
            result = sub_501960(v17, v3, 0, 0);
        }
    }
    return result;
}

//----- (004FDF90) --------------------------------------------------------
void __cdecl sub_4FDF90(int a1, int a2)
{
    int v2; // edi
    int v3; // eax
    int result; // eax
    float v5; // [esp+0h] [ebp-10h]

    if (sub_4FF350(a1, 22) && !(*(_DWORD*)(a2 + 16) & 0x8008) && *(_BYTE*)(a2 + 8) & 6 && sub_5330C0(a1, a2))
    {
        v2 = *(unsigned __int8*)(a1 + 430) - 1;
        sub_501960(135, a1, 0, 0);
        sub_4FF5B0(a1, 22);
        v5 = sub_419D70(&byte_587000[217688], v2);
        v3 = sub_419A70(v5);
        (*(void(__cdecl * *)(int, int, int, int, int))(a2 + 716))(a2, a1, a1, v3, 9);
    }
    result = *(_DWORD*)(a2 + 8);
    if (result & 0x20006)
    {
        if (!(*(_DWORD*)(a2 + 16) & 0x8020))
        {
            if (!sub_4EC520(a2, a1))
                sub_4FF5B0(a1, 0);
        }
    }
    if (*(_BYTE*)(a1 + 8) & 4 && *(_DWORD*)(a2 + 8) & 0x20000 && !(*(_DWORD*)(a2 + 16) & 0x8020))
        sub_4FF5B0(a1, 0);
}

//----- (004FE060) --------------------------------------------------------
int __cdecl sub_4FE060(int a1, int a2)
{
    int v2; // ebx
    int v3; // esi
    int* v4; // edi
    int v5; // eax
    int result; // eax
    int v7[137]; // [esp+8h] [ebp-224h]

    v2 = 0;
    v3 = sub_424AD0();
    if (!v3)
        goto LABEL_14;
    v4 = v7;
    do
    {
        if (!sub_4FE100(v3))
        {
            v5 = sub_424A70(v3);
            if (v5 & a1 || v5 & 0x1000000)
            {
                if (v5 & a2)
                {
                    *v4 = v3;
                    ++v2;
                    ++v4;
                }
            }
        }
        v3 = sub_424AF0(v3);
    } while (v3);
    if (v2)
        result = v7[sub_415FA0(0, v2 - 1)];
    else
        LABEL_14:
    result = 0;
    return result;
}
// 4FE060: using guessed type int var_224[137];

//----- (004FE100) --------------------------------------------------------
int __cdecl sub_4FE100(int a1)
{
    int result; // eax

    switch (a1)
    {
    case 1:
    case 2:
    case 6:
    case 13:
    case 15:
    case 18:
    case 19:
    case 20:
    case 30:
    case 32:
    case 33:
    case 34:
    case 38:
    case 51:
    case 57:
    case 68:
    case 69:
    case 70:
    case 73:
    case 129:
    case 133:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (004FE1C0) --------------------------------------------------------
int __cdecl sub_4FE1C0(int a1, char a2)
{
    char* v2; // eax
    int result; // eax

    if (sub_40A5C0(1))
    {
        if (*(_BYTE*)(sub_4ECCB0(a1) + 8) & 4)
        {
        LABEL_5:
            v2 = sub_417040(a1);
            if (!v2)
                return 0;
            if (!v2[2252])
            {
                switch (a2)
                {
                case 0:
                    goto LABEL_25;
                case 1:
                    goto LABEL_18;
                case 2:
                    goto LABEL_19;
                case 3:
                    goto LABEL_24;
                case 5:
                    goto LABEL_20;
                case 6:
                    goto LABEL_23;
                case 7:
                    goto LABEL_22;
                case 8:
                    goto LABEL_21;
                default:
                    return 0;
                }
            }
            switch (a2)
            {
            case 0:
                result = 201;
                break;
            case 1:
                result = 194;
                break;
            case 2:
                result = 195;
                break;
            case 3:
                result = 200;
                break;
            case 5:
                result = 196;
                break;
            case 6:
                result = 199;
                break;
            case 7:
                result = 198;
                break;
            case 8:
                result = 197;
                break;
            default:
                return 0;
            }
            return result;
        }
    }
    else if (sub_45A6F0(a1)[28] & 4)
    {
        goto LABEL_5;
    }
    switch (a2)
    {
    case 0:
    LABEL_25:
        result = 193;
        break;
    case 1:
    LABEL_18:
        result = 186;
        break;
    case 2:
    LABEL_19:
        result = 187;
        break;
    case 3:
    LABEL_24:
        result = 192;
        break;
    case 5:
    LABEL_20:
        result = 188;
        break;
    case 6:
    LABEL_23:
        result = 191;
        break;
    case 7:
    LABEL_22:
        result = 190;
        break;
    case 8:
    LABEL_21:
        result = 189;
        break;
    default:
        return 0;
    }
    return result;
}

//----- (004FE340) --------------------------------------------------------
int __cdecl sub_4FE340(int a1, int* a2, int a3, int a4, int a5)
{
    _DWORD* v5; // edi
    int* v6; // ebp
    int v7; // edx
    int* v8; // ecx
    int v9; // ebx
    int v10; // edx
    int* v11; // ecx
    int* v12; // eax
    int v13; // ecx
    BYTE v15; // eax
    int v16; // esi
    int* v17; // esi
    int v18; // ebp
    int v19; // ecx
    _DWORD* v20; // esi
    int v21; // eax
    int v22; // edx
    int v23; // eax
    int* v24; // ecx
    int* v25; // edx
    int v26; // [esp+10h] [ebp-4h]

    v5 = (_DWORD*)a1;
    if (*(_DWORD*)(a1 + 16) & 0x8022)
        return 0;
    v6 = a2;
    v7 = 0;
    v8 = a2;
    do
    {
        if ((int)* v8 < 0 || (int)* v8 >= 137)
            return 0;
        ++v7;
        ++v8;
    } while (v7 < 5);
    if (!(*(_BYTE*)(a1 + 8) & 4))
        return 0;
    v9 = *(_DWORD*)(a1 + 748);
    if (*(_DWORD*)(v9 + 280))
        return 0;
    v10 = 0;
    v11 = a2;
    do
    {
        if (!*(_DWORD*)(*(_DWORD*)(v9 + 276) + 4 * *v11 + 3696) && *v11)
            return 0;
        ++v10;
        ++v11;
    } while (v10 < 5);
    if (*(_DWORD*)(v9 + 216))
        return 0;
    v26 = 0;
    if (a3 > 0)
    {
        v12 = a2;
        v13 = a3;
        do
        {
            if (*v12 == 34)
                v26 = 1;
            ++v12;
            --v13;
        } while (v13);
        if (v26)
        {
            if (!sub_4FCEF0(a1, a2, a3))
            {
                a1 = 12;
                sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
                sub_501960(232, (int)v5, 0, 0);
                return 0;
            }
            if (*(_BYTE*)(*(_DWORD*)(v9 + 276) + 2251) == 2)
            {
                v15 = sub_500D70((int)v5, 5);
                if (!v15)
                {
                    a1 = 4;
                LABEL_44:
                    sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
                    goto LABEL_29;
                }
                v16 = sub_4E7CF0((int)v5, 2, 0x2000);
                if (v16 >= (int)(__int64)sub_419D40(&byte_587000[217736]))
                {
                    a1 = 5;
                    goto LABEL_44;
                }
            }
            else if (*(unsigned __int8*)(v9 + 244) >= (int)(__int64)sub_419D40(&byte_587000[217752]))
            {
                a1 = 5;
            LABEL_28:
                sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
            LABEL_29:
                sub_501960(231, (int)v5, 0, 0);
                return 0;
            }
            v17 = a2;
            v18 = 0;
            while (1)
            {
                a1 = sub_4FD0E0((int)v5, *v17);
                if (a1)
                    goto LABEL_28;
                a1 = sub_4FD150((int)v5, *v17, v26);
                if (a1)
                    goto LABEL_28;
                ++v18;
                ++v17;
                if (v18 >= a3)
                {
                    v6 = a2;
                    goto LABEL_36;
                }
            }
        }
    }
    a1 = sub_4FD0E0(a1, *a2);
    if (a1)
    {
        sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
        goto LABEL_29;
    }
    a1 = sub_4FD150((int)v5, *v6, 0);
    if (a1)
        goto LABEL_44;
LABEL_36:
    sub_4FA020(v5, 2);
    v19 = *(_DWORD*)& byte_5D4594[2598000];
    *(_BYTE*)(v9 + 188) = 1;
    *(_DWORD*)(v9 + 216) = v19;
    v20 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1569668]);
    if (!v20)
        return 0;
    v21 = a5;
    v22 = a4;
    v20[1] = v5;
    v20[12] = v21;
    *((_BYTE*)v20 + 36) = 0;
    v20[10] = *(_DWORD*)& byte_5D4594[2598000];
    v20[11] = v22;
    v20[8] = sub_424820();
    *((_BYTE*)v20 + 28) = 0;
    *((_BYTE*)v20 + 29) = 0;
    v23 = 0;
    v24 = v6;
    v25 = v20 + 2;
    do
    {
        if (v23 >= a3)
        {
            *v25 = 0;
        }
        else
        {
            *v25 = *v24;
            if (*v24 == 34)
                * ((_BYTE*)v20 + 29) = 1;
        }
        ++v23;
        ++v24;
        ++v25;
    } while (v23 < 5);
    v20[14] = 0;
    v20[13] = *(_DWORD*)& byte_5D4594[1569672];
    if (*(_DWORD*)& byte_5D4594[1569672])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1569672] + 56) = v20;
    *(_DWORD*)& byte_5D4594[1569672] = v20;
    return 1;
}
// 4FE46E: variable 'v15' is possibly undefined

//----- (004FE680) --------------------------------------------------------
void __cdecl sub_4FE680(int a1, float a2)
{
    int v2; // esi
    int v3; // ebp
    int v4; // eax
    int v5; // ecx
    double v6; // st7
    double v7; // st6
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // eax
    int v12; // edi

    v2 = *(_DWORD*)& byte_5D4594[1569672];
    if (*(_DWORD*)& byte_5D4594[1569672])
    {
        v3 = a1;
        do
        {
            v4 = *(_DWORD*)(v2 + 4);
            if (((*(_BYTE*)(v4 + 8) & 4) != 4 || !sub_419150(v3 + 48, v4 + 48))
                && (v5 = *(_DWORD*)(v2 + 4),
                    v6 = *(float*)(v5 + 56) - *(float*)(v3 + 56),
                    v7 = *(float*)(v5 + 60) - *(float*)(v3 + 60),
                    sqrt(v7 * v7 + v6 * v6) + 0.1 < a2)
                && sub_537110(v3, *(_DWORD*)(v2 + 4)))
            {
                v8 = *(_DWORD*)(v2 + 4);
                if ((*(_BYTE*)(v8 + 8) & 4) == 4)
                {
                    v9 = *(_DWORD*)(v8 + 748);
                    *(_DWORD*)(v9 + 216) = 0;
                    *(_BYTE*)(v9 + 188) = 0;
                    a1 = 15;
                    sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
                    sub_501960(231, *(_DWORD*)(v2 + 4), 0, 0);
                    sub_4FA020(*(_DWORD * *)(v2 + 4), 13);
                }
                v10 = *(_DWORD*)(v2 + 52);
                if (v10)
                    * (_DWORD*)(v10 + 56) = *(_DWORD*)(v2 + 56);
                v11 = *(_DWORD*)(v2 + 56);
                if (v11)
                    * (_DWORD*)(v11 + 52) = *(_DWORD*)(v2 + 52);
                else
                    *(_DWORD*)& byte_5D4594[1569672] = *(_DWORD*)(v2 + 52);
                v12 = *(_DWORD*)(v2 + 52);
                sub_414330(*(unsigned int**)& byte_5D4594[1569668], (_QWORD*)v2);
                v2 = v12;
            }
            else
            {
                v2 = *(_DWORD*)(v2 + 52);
            }
        } while (v2);
    }
}

//----- (004FE7B0) --------------------------------------------------------
int __cdecl sub_4FE7B0(int a1, int a2)
{
    int v2; // eax
    int result; // eax
    int v4; // eax

    v2 = *(_DWORD*)& byte_5D4594[1569720];
    if (!*(_DWORD*)& byte_5D4594[1569720])
    {
        v2 = sub_4E3AA0((CHAR*)& byte_587000[217768]);
        *(_DWORD*)& byte_5D4594[1569720] = v2;
    }
    if (*(unsigned __int16*)(a2 + 4) == v2)
        return 1;
    if (sub_40A5C0(1392))
        goto LABEL_15;
    if (!a2)
        return 2;
    v4 = *(_DWORD*)(a2 + 8);
    if (v4 & 4)
        return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 4 * a1 + 3696);
    if (!(v4 & 2))
        LABEL_15:
    result = 3;
    else
        result = *(_DWORD*)(*(_DWORD*)(a2 + 748) + 2040);
    return result;
}

//----- (004FE840) --------------------------------------------------------
void sub_4FE840()
{
    nox_srand(0x1447u);
}

//----- (004FE850) --------------------------------------------------------
BOOL sub_4FE850()
{
    *(_DWORD*)& byte_5D4594[1569724] = nox_new_alloc_class("spellDuration", 120, 512);
    return *(_DWORD*)& byte_5D4594[1569724] != 0;
}

//----- (004FE880) --------------------------------------------------------
void sub_4FE880()
{
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1569724]);
    *(_DWORD*)& byte_5D4594[1569728] = 0;
}

//----- (004FE8A0) --------------------------------------------------------
void __cdecl sub_4FE8A0(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // edi

    if (a1)
    {
        v1 = *(_DWORD*)& byte_5D4594[1569728];
        if (*(_DWORD*)& byte_5D4594[1569728])
        {
            do
            {
                v2 = *(_DWORD*)(v1 + 48);
                v3 = *(_DWORD*)(v1 + 116);
                if (!v2 || !(*(_BYTE*)(v2 + 8) & 4))
                {
                    sub_4FE900(v1);
                    sub_4FE980(v1);
                }
                v1 = v3;
            } while (v3);
        }
    }
    else
    {
        sub_4144D0(*(_DWORD * *)& byte_5D4594[1569724]);
        *(_DWORD*)& byte_5D4594[1569728] = 0;
    }
}

//----- (004FE900) --------------------------------------------------------
int __cdecl sub_4FE900(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    v2 = *(_DWORD*)(a1 + 112);
    if (v2)
        * (_DWORD*)(v2 + 116) = *(_DWORD*)(a1 + 116);
    else
        *(_DWORD*)& byte_5D4594[1569728] = *(_DWORD*)(a1 + 116);
    v3 = *(_DWORD*)(a1 + 116);
    if (v3)
        * (_DWORD*)(v3 + 112) = *(_DWORD*)(a1 + 112);
    return result;
}

//----- (004FE930) --------------------------------------------------------
int sub_4FE930()
{
    return *(_DWORD*)& byte_5D4594[1569728];
}

//----- (004FE940) --------------------------------------------------------
int __cdecl sub_4FE940(int a1)
{
    return *(_DWORD*)(a1 + 116);
}

//----- (004FE950) --------------------------------------------------------
_WORD* sub_4FE950()
{
    _WORD* result; // eax

    result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1569724]);
    if (result)
        * result = ++ * (_WORD*)& byte_5D4594[1569732];
    return result;
}

//----- (004FE980) --------------------------------------------------------
void __cdecl sub_4FE980(int a1)
{
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // esi

    v1 = *(_DWORD*)(a1 + 108);
    if (v1)
    {
        do
        {
            v2 = *(_DWORD*)(v1 + 116);
            sub_4FE980(v1);
            v1 = v2;
        } while (v2);
    }
    v3 = *(_DWORD*)(a1 + 104);
    if (v3)
    {
        do
        {
            v4 = *(_DWORD*)(v3 + 116);
            sub_4FE980(v3);
            v3 = v4;
        } while (v4);
    }
    sub_414330(*(unsigned int**)& byte_5D4594[1569724], (_QWORD*)a1);
}

//----- (004FE9D0) --------------------------------------------------------
char __cdecl sub_4FE9D0(int a1)
{
    int v1; // eax
    int v2; // ecx
    int v3; // eax
    char result; // al
    int i; // esi

    v1 = *(_DWORD*)(a1 + 16);
    if (v1 && *(_BYTE*)(v1 + 8) & 4)
    {
        v2 = *(_DWORD*)(a1 + 4);
        v3 = *(_DWORD*)(v1 + 748);
        if (v2 == 43)
            sub_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 43, 0);
        else
            sub_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), v2, 15);
    }
    if (*(_DWORD*)(a1 + 4) == 43)
    {
        for (i = *(_DWORD*)(a1 + 108); i; i = *(_DWORD*)(i + 116))
        {
            if (*(_DWORD*)(i + 48))
                sub_4FEF90(i, *(_DWORD * *)(i + 48));
        }
    }
    else if (*(_DWORD*)(a1 + 48))
    {
        sub_4FEF90(a1, *(_DWORD * *)(a1 + 48));
        result = *(_BYTE*)(a1 + 88) | 1;
        *(_BYTE*)(a1 + 88) = result;
        return result;
    }
    result = *(_BYTE*)(a1 + 88) | 1;
    *(_BYTE*)(a1 + 88) = result;
    return result;
}

//----- (004FEA70) --------------------------------------------------------
BOOL __cdecl sub_4FEA70(int a1, float2* a2)
{
    double v2; // st7
    double v3; // st7
    float v5; // [esp+0h] [ebp-8h]

    v2 = a2->field_0 - *(float*)(a1 + 56);
    if (v2 < 0.0)
        v2 = -v2;
    v5 = v2;
    v3 = a2->field_4 - *(float*)(a1 + 60);
    if (v3 < 0.0)
        v3 = -v3;
    return v5 >= 5.0 || v3 >= 5.0;
}

//----- (004FEAE0) --------------------------------------------------------
int __cdecl sub_4FEAE0(int a1)
{
    int result; // eax
    int v2; // esi

    result = sub_4FE930();
    if (result)
    {
        do
        {
            v2 = *(_DWORD*)(result + 116);
            if (*(_DWORD*)(result + 16) == a1)
                sub_4FE9D0(result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (004FEB10) --------------------------------------------------------
_DWORD* __cdecl sub_4FEB10(int a1, int a2)
{
    _DWORD* result; // eax
    int v3; // ecx
    _DWORD* v4; // esi

    result = *(_DWORD * *)& byte_5D4594[1569728];
    if (*(_DWORD*)& byte_5D4594[1569728])
    {
        do
        {
            v3 = result[1];
            v4 = (_DWORD*)result[29];
            if (v3 == a1 && result[4] == a2 || a1 >= 75 && a1 <= 114 && v3 >= 75 && v3 <= 114 && result[4] == a2)
                sub_4FE9D0((int)result);
            result = v4;
        } while (v4);
    }
    return result;
}

//----- (004FEB60) --------------------------------------------------------
unsigned int __cdecl sub_4FEB60(int a1, int a2)
{
    unsigned int result; // eax

    result = *(_DWORD*)(a2 + 8);
    if (result & 0x1000)
    {
        result = *(_DWORD*)(a2 + 12);
        if (result & 0x40000)
            result = (unsigned int)sub_4FEB10(43, a1);
        if (*(_DWORD*)(a2 + 12) & 0x4000000)
            result = (unsigned int)sub_4FEB10(59, a1);
    }
    return result;
}

//----- (004FEBA0) --------------------------------------------------------
int __cdecl sub_4FEBA0(int a1, int a2, _DWORD* a3, int a4, _DWORD* a5, int a6, int(__cdecl* a7)(_WORD*), int a8, int a9, int a10)
{
    int v10; // eax
    _WORD* v12; // esi
    int v13; // edx
    int v14; // ecx
    int v15; // ecx
    BOOL v16; // eax
    int v17; // eax

    v10 = *(_DWORD*)& byte_5D4594[1569736];
    if (!*(_DWORD*)& byte_5D4594[1569736])
    {
        v10 = sub_4E3AA0((CHAR*)& byte_587000[217800]);
        *(_DWORD*)& byte_5D4594[1569736] = v10;
    }
    if (a3 && !(a3[4] & 0x8020) || !a4 || *(unsigned __int16*)(a4 + 4) == v10)
    {
        if (a3)
        {
            if ((a1 == 59 || a1 == 43) && sub_4FEE50(a1, (int)a3) == 1)
                return 1;
            sub_4FEB10(a1, (int)a3);
        }
        sub_4FED70();
        v12 = sub_4FE950();
        if (v12)
        {
            *((_DWORD*)v12 + 1) = a1;
            *((_DWORD*)v12 + 2) = a6;
            *((_DWORD*)v12 + 4) = a3;
            *((_DWORD*)v12 + 3) = a2;
            *((_DWORD*)v12 + 27) = 0;
            *((_DWORD*)v12 + 26) = 0;
            if (a4 && *(unsigned __int16*)(a4 + 4) == *(_DWORD*)& byte_5D4594[1569736])
            {
                *((_DWORD*)v12 + 5) = 1;
                *((_DWORD*)v12 + 6) = a4;
                *((_DWORD*)v12 + 7) = *(_DWORD*)(a4 + 56);
                v13 = *(_DWORD*)(a4 + 60);
            }
            else
            {
                *((_DWORD*)v12 + 5) = 0;
                *((_DWORD*)v12 + 6) = 0;
                *((_DWORD*)v12 + 7) = a3[14];
                v13 = a3[15];
            }
            *((_DWORD*)v12 + 9) = 0;
            *((_DWORD*)v12 + 8) = v13;
            *((_DWORD*)v12 + 12) = *a5;
            *((_DWORD*)v12 + 13) = a5[1];
            v14 = a5[2];
            *((_DWORD*)v12 + 23) = a7;
            *((_DWORD*)v12 + 14) = v14;
            *((_DWORD*)v12 + 24) = a8;
            *((_DWORD*)v12 + 25) = a9;
            *((_DWORD*)v12 + 15) = *(_DWORD*)& byte_5D4594[2598000];
            *((_DWORD*)v12 + 16) = *(_DWORD*)& byte_5D4594[2598000];
            v15 = a10 + *(_DWORD*)& byte_5D4594[2598000];
            *((_BYTE*)v12 + 88) = 0;
            *((_DWORD*)v12 + 17) = v15;
            sub_4FED40((int)v12);
            v16 = sub_424A50(a1, 4);
            v17 = sub_424800(a1, v16);
            sub_501960(v17, (int)a3, 0, 0);
            if (!a7 || !a7(v12))
                return 1;
            sub_4FE9D0((int)v12);
        }
    }
    return 0;
}

//----- (004FED40) --------------------------------------------------------
int __cdecl sub_4FED40(int a1)
{
    int result; // eax

    result = a1;
    if (*(_DWORD*)& byte_5D4594[1569728])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1569728] + 112) = a1;
    *(_DWORD*)(a1 + 112) = 0;
    *(_DWORD*)(a1 + 116) = *(_DWORD*)& byte_5D4594[1569728];
    *(_DWORD*)& byte_5D4594[1569728] = a1;
    return result;
}

//----- (004FED70) --------------------------------------------------------
int sub_4FED70()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[1569728];
    if (*(_DWORD*)& byte_5D4594[1569728])
    {
        do
        {
            v1 = *(_DWORD*)(result + 116);
            if (*(_BYTE*)(result + 88) & 1)
                sub_4FEDA0((int*)result);
            result = v1;
        } while (v1);
    }
    return result;
}

//----- (004FEDA0) --------------------------------------------------------
void __cdecl sub_4FEDA0(int* a1)
{
    int v1; // eax
    void(__cdecl * v2)(int*); // eax
    int v3; // eax
    int v4; // ecx
    int v5; // [esp-Ch] [ebp-10h]

    if (a1[4])
    {
        v5 = a1[4];
        v1 = sub_424800(a1[1], 2);
        sub_501960(v1, v5, 0, 0);
    }
    v2 = (void(__cdecl*)(int*))a1[25];
    if (v2)
        v2(a1);
    v3 = a1[4];
    if (v3)
    {
        v4 = *(_DWORD*)(v3 + 8);
        if (v4 & 4)
        {
            if (*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 2251) || !sub_4FC250(v3, 1))
            {
                sub_4FA020((_DWORD*)a1[4], 13);
                sub_4FE900((int)a1);
                sub_4FE980((int)a1);
                return;
            }
        }
        else if (v4 & 2)
        {
            sub_541630(v3, a1[1]);
        }
    }
    sub_4FE900((int)a1);
    sub_4FE980((int)a1);
}

//----- (004FEE50) --------------------------------------------------------
int __cdecl sub_4FEE50(int a1, int a2)
{
    int v2; // ecx
    int result; // eax

    v2 = *(_DWORD*)& byte_5D4594[1569728];
    if (!*(_DWORD*)& byte_5D4594[1569728])
        return 0;
    result = 1;
    while (*(_DWORD*)(v2 + 20) || *(_DWORD*)(v2 + 4) != a1 || *(_DWORD*)(v2 + 16) != a2 || *(_BYTE*)(v2 + 88) & 1)
    {
        v2 = *(_DWORD*)(v2 + 116);
        if (!v2)
            return 0;
    }
    return result;
}

//----- (004FEE90) --------------------------------------------------------
char __cdecl sub_4FEE90(int a1)
{
    int v1; // eax
    int v2; // esi
    int v3; // edi

    v1 = sub_4FE930();
    v2 = v1;
    if (v1)
    {
        do
        {
            v3 = sub_4FE940(v2);
            v1 = *(_DWORD*)(v2 + 16);
            if (v1 == a1)
            {
                v1 = *(_DWORD*)(v2 + 4);
                if (v1 == 24 || v1 == 43 || v1 == 35 || v1 == 8 || v1 == 22 || v1 == 59 || v1 == 67)
                    LOBYTE(v1) = sub_4FE9D0(v2);
            }
            v2 = v3;
        } while (v3);
    }
    return v1;
}

//----- (004FEEF0) --------------------------------------------------------
void sub_4FEEF0()
{
    int v0; // esi
    int v1; // ebp
    int v2; // eax
    int v3; // eax
    int v4; // eax
    unsigned int v5; // eax
    int(__cdecl * v6)(int); // eax

    v0 = *(_DWORD*)& byte_5D4594[1569728];
    if (*(_DWORD*)& byte_5D4594[1569728])
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 116);
            if (*(_BYTE*)(v0 + 88) & 1)
            {
                sub_4FEDA0((int*)v0);
            }
            else
            {
                v2 = *(_DWORD*)(v0 + 16);
                if (v2 && *(_DWORD*)(v2 + 16) & 0x8020)
                    * (_DWORD*)(v0 + 16) = 0;
                v3 = *(_DWORD*)(v0 + 12);
                if (v3 && *(_BYTE*)(v3 + 16) & 0x20)
                    * (_DWORD*)(v0 + 12) = 0;
                if (!*(_DWORD*)(v0 + 16) && !*(_DWORD*)(v0 + 20))
                    goto LABEL_23;
                v4 = *(_DWORD*)(v0 + 24);
                if (v4 && *(_BYTE*)(v4 + 16) & 0x20)
                    * (_DWORD*)(v0 + 24) = 0;
                v5 = *(_DWORD*)(v0 + 68);
                if (v5 != *(_DWORD*)(v0 + 60) && v5 <= *(int*)& byte_5D4594[2598000]
                    || (v6 = *(int(__cdecl * *)(int))(v0 + 96)) != 0 && v6(v0))
                {
                LABEL_23:
                    sub_4FE9D0(v0);
                }
            }
            v0 = v1;
        } while (v1);
    }
}

//----- (004FEF90) --------------------------------------------------------
void __cdecl sub_4FEF90(int a1, _DWORD* a2)
{
    int v2; // ecx
    int v3; // eax
    char v4; // cl
    int i; // esi
    char v6; // al
    char v7; // cl
    char v8; // dl
    __int16 v9; // ax
    char v10; // cl
    char v11[7]; // [esp+8h] [ebp-8h]

    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 16);
        if (v2)
        {
            if (a2)
            {
                v3 = *(_DWORD*)(a1 + 4);
                v11[0] = -98;
                switch (v3)
                {
                case 7:
                    v6 = *(_BYTE*)(a1 + 8);
                    v11[1] = 10;
                    v11[2] = v6;
                    goto LABEL_13;
                case 9:
                    v4 = *(_BYTE*)(a1 + 8);
                    v11[1] = 9;
                    v11[2] = v4;
                    goto LABEL_13;
                case 22:
                    v8 = *(_BYTE*)(a1 + 8);
                    v11[1] = 12;
                    v11[2] = v8;
                    goto LABEL_13;
                case 24:
                    v7 = *(_BYTE*)(a1 + 8);
                    v11[1] = 11;
                    v11[2] = v7;
                    goto LABEL_13;
                case 35:
                    if (v2 == *(_DWORD*)(a1 + 48))
                        return;
                    v11[1] = 13;
                    *(_WORD*)& v11[3] = sub_578AC0(a2);
                    v9 = sub_578AC0(*(_DWORD * *)(a1 + 16));
                    v10 = *(_BYTE*)(a1 + 8);
                    *(_WORD*)& v11[5] = v9;
                    v11[2] = v10;
                    sub_4E5390(255, (int)v11, 7, 0, 1);
                    sub_417470(*(_DWORD*)(a1 + 16), 2);
                    goto LABEL_16;
                case 43:
                    for (i = *(_DWORD*)(a1 + 108); i; i = *(_DWORD*)(i + 116))
                        sub_4FEF90(i, *(_DWORD * *)(i + 48));
                    return;
                case 59:
                    v11[1] = 8;
                    v11[2] = *(_BYTE*)(v2 + 124);
                LABEL_13:
                    *(_WORD*)& v11[5] = sub_578AC0(a2);
                    *(_WORD*)& v11[3] = sub_578AC0(*(_DWORD * *)(a1 + 16));
                    sub_4E5390(255, (int)v11, 7, 0, 1);
                    sub_417470(*(_DWORD*)(a1 + 16), 2);
                LABEL_16:
                    sub_417470((int)a2, 2);
                    break;
                default:
                    return;
                }
            }
        }
    }
}

//----- (004FF130) --------------------------------------------------------
char* __cdecl sub_4FF130(int a1)
{
    char* result; // eax
    int v2; // edx
    int i; // esi
    char v4; // dl
    char v5; // al
    __int16 v6; // ax
    _DWORD* v7; // edx
    __int16 v8; // ax
    char v9; // cl
    _DWORD* v10; // [esp-4h] [ebp-10h]
    char v11[7]; // [esp+4h] [ebp-8h]

    v11[0] = -98;
    result = (char*)(*(_DWORD*)(a1 + 4) - 7);
    switch (*(_DWORD*)(a1 + 4))
    {
    case 7:
        v4 = *(_BYTE*)(a1 + 8);
        v11[1] = 3;
        v11[2] = v4;
        goto LABEL_11;
    case 9:
        v11[1] = 2;
        goto LABEL_10;
    case 0x16:
        v11[1] = 5;
    LABEL_10:
        v11[2] = *(_BYTE*)(a1 + 8);
        goto LABEL_11;
    case 0x18:
        v5 = *(_BYTE*)(a1 + 8);
        v11[1] = 4;
        v11[2] = v5;
        goto LABEL_11;
    case 0x23:
        result = *(char**)(a1 + 48);
        if (*(char**)(a1 + 16) != result)
        {
            v10 = *(_DWORD * *)(a1 + 48);
            v11[1] = 6;
            *(_WORD*)& v11[3] = sub_578AC0(v10);
            v8 = sub_578AC0(*(_DWORD * *)(a1 + 16));
            v9 = *(_BYTE*)(a1 + 8);
            *(_WORD*)& v11[5] = v8;
            v11[2] = v9;
            sub_4E5390(255, (int)v11, 7, 0, 1);
            sub_4174B0(*(_DWORD*)(a1 + 16), 2);
            result = sub_4174B0(*(_DWORD*)(a1 + 48), 2);
        }
        return result;
    case 0x2B:
        for (i = *(_DWORD*)(a1 + 108); i; i = *(_DWORD*)(i + 116))
            result = (char*)sub_4FF130(i);
        return result;
    case 0x3B:
        v2 = *(_DWORD*)(a1 + 16);
        v11[1] = 1;
        v11[2] = *(_BYTE*)(v2 + 124);
    LABEL_11:
        result = *(char**)(a1 + 48);
        if (result)
        {
            v6 = sub_578AC0(*(_DWORD * *)(a1 + 48));
            v7 = *(_DWORD * *)(a1 + 16);
            *(_WORD*)& v11[5] = v6;
            *(_WORD*)& v11[3] = sub_578AC0(v7);
            sub_4E5390(255, (int)v11, 7, 0, 1);
            sub_4174B0(*(_DWORD*)(a1 + 16), 2);
            result = sub_4174B0(*(_DWORD*)(a1 + 48), 2);
        }
        break;
    default:
        return result;
    }
    return result;
}

//----- (004FF2D0) --------------------------------------------------------
int __cdecl sub_4FF2D0(int a1, int a2)
{
    int result; // eax
    int v3; // ecx

    result = sub_4FE930();
    if (!result)
        return 0;
    while (1)
    {
        if (!(*(_BYTE*)(result + 88) & 1) && *(_DWORD*)(result + 4) == a1)
        {
            v3 = *(_DWORD*)(result + 48);
            if (v3)
            {
                if (v3 == a2)
                    break;
            }
        }
        result = sub_4FE940(result);
        if (!result)
            return 0;
    }
    return result;
}

//----- (004FF310) --------------------------------------------------------
void __cdecl sub_4FF310(int a1)
{
    int* v1; // esi
    int* v2; // edi

    v1 = *(int**)& byte_5D4594[1569728];
    if (*(_DWORD*)& byte_5D4594[1569728])
    {
        do
        {
            v2 = (int*)v1[29];
            if (v1[4] == a1)
            {
                if (sub_424A70(v1[1]) & 0x20)
                    sub_4FE9D0((int)v1);
            }
            v1 = v2;
        } while (v2);
    }
}

//----- (004FF350) --------------------------------------------------------
BOOL __cdecl sub_4FF350(int a1, char a2)
{
    BOOL result; // eax

    result = a1;
    if (a1)
        result = ((1 << a2) & *(_DWORD*)(a1 + 340)) != 0;
    return result;
}

//----- (004FF380) --------------------------------------------------------
__int16 __cdecl sub_4FF380(int a1, int a2, __int16 a3, char a4)
{
    int v4; // eax
    int v5; // eax
    int v6; // eax

    LOWORD(v4) = *(_WORD*)& byte_5D4594[1569740];
    if (!*(_DWORD*)& byte_5D4594[1569740])
    {
        *(_DWORD*)& byte_5D4594[1569740] = sub_4E3AA0((CHAR*)& byte_587000[217808]);
        v4 = sub_4E3AA0((CHAR*)& byte_587000[217816]);
        *(_DWORD*)& byte_5D4594[1569744] = v4;
    }
    if (a1)
    {
        LOWORD(v4) = *(_WORD*)(a1 + 4);
        if ((unsigned __int16)v4 != *(_DWORD*)& byte_5D4594[1569740] || a2 != 29)
        {
            if (sub_40A5C0(4096) && *(unsigned __int16*)(a1 + 4) == *(_DWORD*)& byte_5D4594[1569740] && a2 == 3)
            {
                LOWORD(v4) = (unsigned int)sub_501960(582, a1, 0, 0);
            }
            else
            {
                v4 = sub_40A5C0(4096);
                if (v4
                    && (LOWORD(v4) = *(_WORD*)& byte_5D4594[1569744],
                        *(unsigned __int16*)(a1 + 4) == *(_DWORD*)& byte_5D4594[1569744])
                    && a2 == 3)
                {
                    LOWORD(v4) = (unsigned int)sub_501960(595, a1, 0, 0);
                }
                else if (*(_BYTE*)(a1 + 8) & 2
                    && (v4 = *(_DWORD*)(a1 + 12), BYTE1(v4) & 0x10)
                    && a2 == 11
                    && (v4 = sub_40A5C0(2048)) == 0)
                {
                    LOWORD(v4) = *(_WORD*)(a1 + 4);
                    if ((unsigned __int16)v4 == *(_DWORD*)& byte_5D4594[1569740])
                    {
                        LOWORD(v4) = (unsigned int)sub_501960(582, a1, 0, 0);
                    }
                    else if (v4 == *(_DWORD*)& byte_5D4594[1569744])
                    {
                        LOWORD(v4) = (unsigned int)sub_501960(595, a1, 0, 0);
                    }
                }
                else if (!(*(_DWORD*)(a1 + 16) & 0x8022))
                {
                    if (!sub_4FF350(a1, a2) || (v4 = sub_4FF550(a1, a2)) != 0)
                    {
                        if (a2)
                            sub_4FF5B0(a1, 0);
                        *(_WORD*)(a1 + 2 * a2 + 344) = a3;
                        *(_BYTE*)(a1 + a2 + 408) = a4;
                        sub_4E48F0(a1, (1 << a2) | *(_DWORD*)(a1 + 340));
                        v5 = sub_424920(a2);
                        v6 = sub_424800(v5, 1);
                        LOWORD(v4) = (unsigned int)sub_501960(v6, a1, 0, 0);
                    }
                }
            }
        }
    }
    return v4;
}

//----- (004FF550) --------------------------------------------------------
int __cdecl sub_4FF550(int a1, int a2)
{
    return *(unsigned __int16*)(a1 + 2 * a2 + 344);
}

//----- (004FF570) --------------------------------------------------------
char __cdecl sub_4FF570(int a1, int a2)
{
    return *(_BYTE*)(a1 + a2 + 408);
}

//----- (004FF580) --------------------------------------------------------
int __cdecl sub_4FF580(int a1)
{
    int result; // eax
    _WORD* v2; // ecx

    sub_4E48F0(a1, 0);
    result = 0;
    v2 = (_WORD*)(a1 + 344);
    do
    {
        *v2 = 0;
        *(_BYTE*)(a1 + result++ + 408) = 0;
        ++v2;
    } while (result < 32);
    return result;
}

//----- (004FF5B0) --------------------------------------------------------
int __cdecl sub_4FF5B0(int a1, int a2)
{
    int result; // eax
    int v3; // ecx
    int v4; // eax
    int v5; // eax

    result = 1 << a2;
    v3 = *(_DWORD*)(a1 + 340);
    if (v3 & (1 << a2))
    {
        sub_4E48F0(a1, v3 & ~result);
        result = 0;
        *(_WORD*)(a1 + 2 * a2 + 344) = 0;
        *(_BYTE*)(a1 + a2 + 408) = 0;
        if (a2 != 16 && a2 != 30)
        {
            v4 = sub_424920(a2);
            v5 = sub_424800(v4, 2);
            result = sub_501960(v5, a1, 0, 0);
        }
    }
    return result;
}

//----- (004FF620) --------------------------------------------------------
void __cdecl sub_4FF620(int a1)
{
    int v1; // edi
    unsigned __int16 v2; // ax
    __int16 v3; // ax
    int v4; // eax

    if (*(_DWORD*)(a1 + 340))
    {
        v1 = 0;
        do
        {
            if ((1 << v1) & *(_DWORD*)(a1 + 340))
            {
                if (v1 == 16
                    && (unsigned int) * (unsigned __int16*)(a1 + 376) % *(_DWORD*)& byte_5D4594[2649704] == *(_DWORD*)& byte_5D4594[2649704]
                    - 1)
                {
                    sub_501960(26, a1, 0, 0);
                }
                v2 = *(_WORD*)(a1 + 2 * v1 + 344);
                if (v2 > 0u)
                {
                    v3 = v2 - 1;
                    *(_WORD*)(a1 + 2 * v1 + 344) = v3;
                    if (!v3)
                    {
                        if (v1 == 7)
                        {
                            v4 = *(_DWORD*)(a1 + 16);
                            LOBYTE(v4) = v4 & 0xBF;
                            *(_DWORD*)(a1 + 16) = v4;
                        }
                        else if (v1 == 16)
                        {
                            *(_DWORD*)(a1 + 520) = 0;
                            *(_DWORD*)(a1 + 524) = 13;
                            sub_4EE5E0(a1, 9999999);
                            sub_501960(779, a1, 0, 0);
                            if (*(_BYTE*)(a1 + 8) & 4)
                            {
                                sub_4D8D40(a1);
                                sub_4D8EF0(a1);
                            }
                        }
                        sub_4FF5B0(a1, v1);
                        *(_BYTE*)(v1 + a1 + 408) = 0;
                    }
                }
            }
            ++v1;
        } while (v1 < 32);
        if (sub_4FF350(a1, 9))
            * (float*)(a1 + 544) = *(float*)(a1 + 544) * 1.25;
    }
}

//----- (004FF730) --------------------------------------------------------
BOOL sub_4FF730()
{
    *(_DWORD*)& byte_5D4594[1569756] = 0;
    *(_DWORD*)& byte_5D4594[1569748] = nox_new_alloc_class(
        "MagicWall",
        32,
        (*(_DWORD*)& byte_587000[217844] << 6) + 32);
    return *(_DWORD*)& byte_5D4594[1569748] != 0;
}

//----- (004FF770) --------------------------------------------------------
int sub_4FF770()
{
    int result; // eax

    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1569748]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1569748] = 0;
    *(_DWORD*)& byte_5D4594[1569752] = 0;
    *(_DWORD*)& byte_5D4594[1569756] = 0;
    return result;
}

//----- (004FF790) --------------------------------------------------------
void sub_4FF790()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1569748]);
    *(_DWORD*)& byte_5D4594[1569752] = 0;
}

//----- (004FF7B0) --------------------------------------------------------
void __cdecl sub_4FF7B0(int a1)
{
    char v1; // cl
    int v2; // edi
    _DWORD* v3; // esi
    char* v4; // eax
    int v6; // [esp-14h] [ebp-28h]
    char v7[6]; // [esp+Ch] [ebp-8h]

    v1 = *(_BYTE*)(a1 + 2064);
    v2 = 1 << v1;
    if (v1 != 31)
    {
        v3 = *(_DWORD * *)& byte_5D4594[1569752];
        if (*(_DWORD*)& byte_5D4594[1569752])
        {
            do
            {
                if (*(_BYTE*)(a1 + 3680) & 0x10)
                {
                    if (!(v2 & v3[4]))
                    {
                        v4 = (char*)v3[2];
                        v7[0] = 61;
                        v7[1] = v4[1];
                        v7[2] = *v4;
                        v7[3] = v4[2];
                        v7[4] = v4[5];
                        v6 = *(unsigned __int8*)(a1 + 2064);
                        v7[5] = v4[6];
                        sub_4E5420(v6, v7, 6, 0, 1);
                        v3[4] = v2 | v3[4];
                    }
                }
                v3 = (_DWORD*)v3[6];
            } while (v3);
        }
    }
}

//----- (004FF840) --------------------------------------------------------
int __cdecl sub_4FF840(int a1)
{
    int result; // eax
    int v2; // esi

    result = *(_DWORD*)& byte_5D4594[1569752];
    if (*(_DWORD*)& byte_5D4594[1569752])
    {
        do
        {
            v2 = *(_DWORD*)(result + 24);
            if (*(_DWORD*)(result + 8) == a1)
                sub_4FF870(result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (004FF870) --------------------------------------------------------
void __cdecl sub_4FF870(int a1)
{
    _BYTE* v1; // eax
    int v2; // eax
    int v3; // eax

    sub_4FF900(a1);
    if (sub_40A5C0(1))
    {
        v1 = *(_BYTE * *)(a1 + 8);
        if (*(_DWORD*)a1)
        {
            v1[1] = *(_BYTE*)(a1 + 12);
            **(_BYTE * *)(a1 + 8) = *(_BYTE*)(a1 + 13);
            *(_BYTE*)(*(_DWORD*)(a1 + 8) + 2) = *(_BYTE*)(a1 + 14);
        }
        else
        {
            sub_410430((unsigned __int8)v1[5], (unsigned __int8)v1[6]);
        }
    }
    v2 = *(_DWORD*)(a1 + 28);
    if (v2)
        * (_DWORD*)(v2 + 24) = *(_DWORD*)(a1 + 24);
    else
        *(_DWORD*)& byte_5D4594[1569752] = *(_DWORD*)(a1 + 24);
    v3 = *(_DWORD*)(a1 + 24);
    if (v3)
        * (_DWORD*)(v3 + 28) = *(_DWORD*)(a1 + 28);
    sub_414330(*(unsigned int**)& byte_5D4594[1569748], (_QWORD*)a1);
}

//----- (004FF900) --------------------------------------------------------
int __cdecl sub_4FF900(int a1)
{
    int v1; // esi
    unsigned int i; // edi
    int result; // eax
    char v4; // cl
    char v5; // dl
    int v6; // eax
    int v7; // eax
    char v8[6]; // [esp+8h] [ebp-8h]

    v1 = a1;
    for (i = 0; i < 0x20; ++i)
    {
        result = 1 << i;
        if ((1 << i) & *(_DWORD*)(v1 + 16))
        {
            if (*(_DWORD*)v1)
            {
                v4 = *(_BYTE*)(v1 + 12);
                v5 = *(_BYTE*)(v1 + 13);
                v8[3] = *(_BYTE*)(v1 + 14);
                v6 = *(_DWORD*)(v1 + 8);
                v8[0] = 61;
                v8[1] = v4;
                v8[2] = v5;
                v8[4] = *(_BYTE*)(v6 + 5);
                v8[5] = *(_BYTE*)(v6 + 6);
                result = sub_4E5420(i, v8, 6, 0, 1);
            }
            else
            {
                v7 = *(_DWORD*)(v1 + 8);
                LOBYTE(a1) = 62;
                *(_WORD*)((char*)& a1 + 1) = *(_WORD*)(v7 + 5);
                result = sub_4E5420(i, &a1, 3, 0, 1);
            }
        }
    }
    return result;
}

//----- (004FF990) --------------------------------------------------------
int __cdecl sub_4FF990(int a1)
{
    int result; // eax

    for (result = *(_DWORD*)& byte_5D4594[1569752]; result; result = *(_DWORD*)(result + 24))
        * (_DWORD*)(result + 16) &= ~a1;
    return result;
}

//----- (004FF9B0) --------------------------------------------------------
char __cdecl sub_4FF9B0(int a1, int a2, int a3, int a4, int a5)
{
    char result; // al

    result = sub_4FFA40(a1);
    switch (a1)
    {
    case 1:
        if (a5 != a3)
            result = sub_4FFA40(7);
        break;
    case 7:
        if (a5 != a3)
            result = sub_4FFA40(1);
        break;
    case 3:
        if (a4 != a2)
            result = sub_4FFA40(5);
        break;
    default:
        if (a1 == 5 && a4 != a2)
            result = sub_4FFA40(3);
        break;
    }
    return result;
}

//----- (004FFA40) --------------------------------------------------------
char __cdecl sub_4FFA40(int a1)
{
    char result; // al

    switch (a1)
    {
    case 1:
        result = 7;
        break;
    case 2:
    case 6:
        result = 1;
        break;
    case 3:
        result = 8;
        break;
    case 5:
        result = 10;
        break;
    case 7:
        result = 9;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (004FFA90) --------------------------------------------------------
int __cdecl sub_4FFA90(int a1)
{
    int v1; // edi
    int v2; // eax
    float v3; // edx
    float v4; // ecx
    float v5; // edx
    int v6; // edi
    int v7; // edi
    int v9; // eax
    int v10; // esi
    int v11; // ebx
    int v13; // ebp
    int v14; // ebx
    int v15; // ebp
    int v16; // [esp+4h] [ebp-28h]
    unsigned __int8 v17; // [esp+8h] [ebp-24h]
    unsigned __int8 v18; // [esp+8h] [ebp-24h]
    unsigned __int8 v19; // [esp+8h] [ebp-24h]
    int i; // [esp+Ch] [ebp-20h]
    int j; // [esp+Ch] [ebp-20h]
    int v22; // [esp+10h] [ebp-1Ch]
    float2 v23; // [esp+14h] [ebp-18h]
    float4 a1a; // [esp+1Ch] [ebp-10h]

    v1 = a1;
    v22 = 60 * *(_DWORD*)& byte_5D4594[2649704] * (*(_DWORD*)(a1 + 8) + 5);
    v2 = *(_DWORD*)(a1 + 16);
    if (!v2 || *(_DWORD*)(v2 + 16) & 0x8020)
        return 1;
    v3 = *(float*)(a1 + 32);
    a1a.field_0 = *(float*)(a1 + 28);
    v4 = *(float*)(a1 + 52);
    a1a.field_4 = v3;
    v5 = *(float*)(a1 + 56);
    a1a.field_8 = v4;
    a1a.field_C = v5;
    if (!(unsigned __int8)sub_5374B0(&a1a))
    {
        v6 = *(_DWORD*)(v1 + 16);
        if (*(_BYTE*)(v6 + 8) & 4)
        {
            v7 = *(_DWORD*)(v6 + 748);
            a1 = 2;
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v7 + 276) + 2064), 0, &a1);
        }
        return 1;
    }
    v23.field_0 = a1a.field_8 - a1a.field_0;
    v23.field_4 = a1a.field_C - a1a.field_4;
    v9 = sub_509ED0(&v23);
    v10 = sub_509EA0(v9);
    v11 = (__int64) * (float*)(v1 + 52) / 23;
    v13 = (__int64) * (float*)(v1 + 56) / 23;
    if ((((_BYTE)v11 + (_BYTE)v13) & 1) == 1)
        ++v11;
    v16 = v11;
    a1 = (__int64) * (float*)(v1 + 56) / 23;
    v17 = sub_4FFA40(v10);
    if (sub_4FFD00(v1, v11, v13, v17))
    {
        for (i = 0; i < *(int*)& byte_587000[4 * *(_DWORD*)(v1 + 8) + 217844]; ++i)
        {
            v11 = (unsigned __int8)sub_4FFEF0(v10, v16, v11, 0);
            v13 = (unsigned __int8)sub_4FFFB0(v10, a1, v13, 0);
            v18 = sub_4FF9B0(v10, v16, a1, v11, v13);
            if (!sub_4FFD00(v1, v11, v13, v18))
                break;
        }
        v14 = v16;
        v15 = a1;
        for (j = 0; j < *(int*)& byte_587000[4 * *(_DWORD*)(v1 + 8) + 217844]; ++j)
        {
            v14 = (unsigned __int8)sub_4FFEF0(v10, v16, v14, 1);
            v15 = (unsigned __int8)sub_4FFFB0(v10, a1, v15, 1);
            v19 = sub_4FF9B0(v10, v16, a1, v14, v15);
            if (!sub_4FFD00(v1, v14, v15, v19))
                break;
        }
    }
    *(_DWORD*)(v1 + 68) = v22 + *(_DWORD*)& byte_5D4594[2598000];
    return 0;
}

//----- (004FFD00) --------------------------------------------------------
BOOL __cdecl sub_4FFD00(int a1, int a2, int a3, unsigned __int8 a4)
{
    int v4; // ebx
    int v5; // eax
    unsigned __int8* v6; // esi
    char v7; // al
    unsigned __int8* v9; // eax
    int v10; // [esp-4h] [ebp-20h]
    char v11; // [esp+10h] [ebp-Ch]
    char v12; // [esp+14h] [ebp-8h]
    char v13; // [esp+18h] [ebp-4h]

    v4 = 0;
    v13 = 0;
    v12 = 0;
    v11 = 0;
    if (!byte_5D4594[1570004])
    {
        byte_5D4594[1570004] = sub_410D60("MagicWallSystemUseOnly");
        byte_5D4594[1570005] = sub_410D60("InvisibleWallSet");
        byte_5D4594[1570006] = sub_410D60("InvisibleBlockingWallSet");
    }
    v5 = sub_410580(a2, a3);
    v6 = (unsigned __int8*)v5;
    if (v5)
    {
        v7 = *(_BYTE*)(v5 + 1);
        if (v7 == byte_5D4594[1570004])
            return 0;
        if (v7 != byte_5D4594[1570005] && v7 != byte_5D4594[1570006])
        {
            if (v6[4] & 0x1C)
                return 0;
            v13 = v6[1];
            v4 = 1;
            v12 = *v6;
            v11 = v6[2];
            *v6 = sub_42A6C0(*v6, a4);
            goto LABEL_11;
        }
    }
    else
    {
        v9 = (unsigned __int8*)sub_410250(a2, a3);
        v6 = v9;
        if (v9)
        {
            v9[1] = byte_5D4594[1570004];
            *v9 = a4;
            if (!a4 || a4 == 1)
            {
                v9[2] = v9[5] % (__int16)sub_410E00(byte_5D4594[1570004]);
                goto LABEL_12;
            }
        LABEL_11:
            v6[2] = 0;
            if (v4)
            {
            LABEL_13:
                sub_4FFE80(a1, v6, v4, v13, v12, v11);
                return v4 == 0;
            }
        LABEL_12:
            v10 = v6[1];
            v6[4] |= 8u;
            v6[7] = sub_410E20(v10);
            goto LABEL_13;
        }
    }
    return 0;
}

//----- (004FFE80) --------------------------------------------------------
_DWORD* __cdecl sub_4FFE80(int a1, _BYTE* a2, int a3, char a4, char a5, char a6)
{
    _DWORD* result; // eax

    result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1569748]);
    if (result)
    {
        result[2] = a2;
        *result = a3;
        *((_BYTE*)result + 4) = *a2;
        *((_BYTE*)result + 12) = a4;
        *((_BYTE*)result + 13) = a5;
        *((_BYTE*)result + 14) = a6;
        result[5] = a1;
        result[4] = 0;
        result[7] = 0;
        result[6] = *(_DWORD*)& byte_5D4594[1569752];
        if (*(_DWORD*)& byte_5D4594[1569752])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1569752] + 28) = result;
        *(_DWORD*)& byte_5D4594[1569752] = result;
    }
    return result;
}

//----- (004FFEF0) --------------------------------------------------------
char __cdecl sub_4FFEF0(int a1, int a2, int a3, char a4)
{
    char result; // al
    char v5; // al

    if (!a4)
    {
        switch (a1)
        {
        case 0:
            goto LABEL_3;
        case 1:
            goto LABEL_4;
        case 2:
            goto LABEL_5;
        case 3:
            goto LABEL_12;
        case 5:
            goto LABEL_10;
        case 6:
            goto LABEL_9;
        case 7:
            goto LABEL_8;
        case 8:
            goto LABEL_7;
        default:
            goto LABEL_14;
        }
    }
    switch (a1)
    {
    case 0:
    LABEL_7:
        result = a3 - 1;
        break;
    case 1:
    LABEL_8:
        result = a3 - 1;
        break;
    case 2:
    LABEL_9:
        result = a3 - 1;
        break;
    case 3:
    LABEL_12:
        v5 = a3;
        if (a3 != a2)
            goto LABEL_11;
        goto LABEL_13;
    case 5:
    LABEL_10:
        v5 = a3;
        if (a3 == a2)
            LABEL_11:
        result = v5 - 1;
        else
            LABEL_13:
        result = v5 + 1;
        break;
    case 6:
    LABEL_5:
        result = a3 + 1;
        break;
    case 7:
    LABEL_4:
        result = a3 + 1;
        break;
    case 8:
    LABEL_3:
        result = a3 + 1;
        break;
    default:
    LABEL_14:
        result = a3;
        break;
    }
    return result;
}

//----- (004FFFB0) --------------------------------------------------------
char __cdecl sub_4FFFB0(int a1, int a2, int a3, char a4)
{
    char v4; // al
    char result; // al

    if (!a4)
    {
        switch (a1)
        {
        case 0:
            goto LABEL_3;
        case 1:
            goto LABEL_7;
        case 2:
            goto LABEL_13;
        case 3:
            goto LABEL_10;
        case 5:
            goto LABEL_14;
        case 6:
            goto LABEL_9;
        case 7:
            goto LABEL_11;
        case 8:
            goto LABEL_6;
        default:
            goto LABEL_15;
        }
    }
    switch (a1)
    {
    case 0:
    LABEL_6:
        result = a3 + 1;
        break;
    case 1:
    LABEL_7:
        v4 = a3;
        if (a3 != a2)
            goto LABEL_12;
        result = a3 - 1;
        break;
    case 2:
    LABEL_9:
        result = a3 - 1;
        break;
    case 3:
    LABEL_14:
        result = a3 + 1;
        break;
    case 5:
    LABEL_10:
        result = a3 - 1;
        break;
    case 6:
    LABEL_13:
        result = a3 + 1;
        break;
    case 7:
    LABEL_11:
        v4 = a3;
        if (a3 != a2)
            goto LABEL_4;
    LABEL_12:
        result = v4 + 1;
        break;
    case 8:
    LABEL_3:
        v4 = a3;
    LABEL_4:
        result = v4 - 1;
        break;
    default:
    LABEL_15:
        result = a3;
        break;
    }
    return result;
}

//----- (00500070) --------------------------------------------------------
int sub_500070()
{
    return 0;
}

//----- (00500080) --------------------------------------------------------
int __cdecl sub_500080(int a1)
{
    int result; // eax
    int v2; // esi

    result = *(_DWORD*)& byte_5D4594[1569752];
    if (*(_DWORD*)& byte_5D4594[1569752])
    {
        do
        {
            v2 = *(_DWORD*)(result + 24);
            if (*(_DWORD*)(result + 20) == a1)
                sub_4FF870(result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (005000B0) --------------------------------------------------------
int __cdecl sub_5000B0(_DWORD* a1)
{
    int v1; // eax
    int v2; // esi
    int v4; // esi
    int v5; // [esp+0h] [ebp-2Ch]
    int v6; // [esp+4h] [ebp-28h]
    int v7; // [esp+8h] [ebp-24h]
    int v8; // [esp+Ch] [ebp-20h]
    int v9; // [esp+10h] [ebp-1Ch]
    int v10; // [esp+14h] [ebp-18h]
    int v11; // [esp+18h] [ebp-14h]
    int v12; // [esp+1Ch] [ebp-10h]
    int v13; // [esp+20h] [ebp-Ch]
    int v14; // [esp+24h] [ebp-8h]
    int v15; // [esp+28h] [ebp-4h]

    v6 = 1;
    sub_426AC0(&v6, 2u);
    if ((__int16)v6 > 1 || (__int16)v6 <= 0)
        return 0;
    v1 = *(_DWORD*)& byte_5D4594[1569752];
    for (LOBYTE(v5) = 0; v1; v1 = *(_DWORD*)(v1 + 24))
        LOBYTE(v5) = v5 + 1;
    sub_426AC0(&v5, 1u);
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if ((_BYTE)v5)
        {
            sub_5002D0(a1);
            v4 = 0;
            *(_DWORD*)& byte_5D4594[1569756] = 0;
            if ((_BYTE)v5)
            {
                do
                {
                    sub_426AC0(&v13, 4u);
                    sub_426AC0(&v15, 1u);
                    sub_426AC0(&v14, 1u);
                    sub_426AC0(&v12, 1u);
                    sub_426AC0(&v11, 1u);
                    sub_426AC0(&v10, 1u);
                    sub_426AC0(&v9, 1u);
                    sub_426AC0(&v8, 1u);
                    sub_426AC0(&v7, 1u);
                    sub_426AC0(&a1, 1u);
                    sub_500330(v15, v14, v13, v12, v11, v10, v9, v8, v7, (char)a1);
                    ++v4;
                } while (v4 < (unsigned __int8)v5);
            }
        }
        return 1;
    }
    v2 = *(_DWORD*)& byte_5D4594[1569752];
    if (!*(_DWORD*)& byte_5D4594[1569752])
        return 1;
    do
    {
        sub_426AC0((_BYTE*)v2, 4u);
        sub_426AC0((_BYTE*)(*(_DWORD*)(v2 + 8) + 5), 1u);
        sub_426AC0((_BYTE*)(*(_DWORD*)(v2 + 8) + 6), 1u);
        sub_426AC0((_BYTE*)(v2 + 12), 1u);
        sub_426AC0((_BYTE*)(v2 + 13), 1u);
        sub_426AC0((_BYTE*)(v2 + 14), 1u);
        sub_426AC0((_BYTE*)(*(_DWORD*)(v2 + 8) + 1), 1u);
        sub_426AC0((_BYTE*)(*(_DWORD*)(v2 + 8) + 2), 1u);
        sub_426AC0(*(_BYTE * *)(v2 + 8), 1u);
        sub_426AC0((_BYTE*)(*(_DWORD*)(v2 + 8) + 7), 1u);
        v2 = *(_DWORD*)(v2 + 24);
    } while (v2);
    return 1;
}

//----- (005002D0) --------------------------------------------------------
int __cdecl sub_5002D0(_DWORD* a1)
{
    int v1; // ecx
    int v3[3]; // [esp+0h] [ebp-Ch]

    v3[0] = (int)a1;
    v1 = a1[187];
    *(float*)& v3[1] = (double) * (int*)(*(_DWORD*)(v1 + 276) + 2284);
    *(float*)& v3[2] = (double) * (int*)(*(_DWORD*)(v1 + 276) + 2288);
    return sub_4FEBA0(132, (int)a1, a1, (int)a1, v3, 3, 0, 0, 0, 0);
}

//----- (00500330) --------------------------------------------------------
void __cdecl sub_500330(char a1, char a2, int a3, char a4, char a5, char a6, char a7, char a8, char a9, char a10)
{
    int v11; // ecx
    int result;

    if (*(int*)& byte_5D4594[1569756] < 15)
    {
        result = 16 * *(_DWORD*)& byte_5D4594[1569756];
        v11 = *(_DWORD*)& byte_5D4594[1569756] + 1;
        byte_5D4594[result + 1569764] = a1;
        byte_5D4594[result + 1569765] = a2;
        *(_DWORD*)& byte_5D4594[result + 1569768] = a3;
        byte_5D4594[result + 1569772] = a4;
        byte_5D4594[result + 1569773] = a5;
        byte_5D4594[result + 1569774] = a6;
        byte_5D4594[result + 1569775] = a7;
        byte_5D4594[result + 1569776] = a8;
        byte_5D4594[result + 1569777] = a9;
        byte_5D4594[result + 1569778] = a10;
        *(_DWORD*)& byte_5D4594[1569756] = v11;
    }
}

//----- (005003B0) --------------------------------------------------------
int __cdecl sub_5003B0(int a1)
{
    int v1; // edi
    int result; // eax
    int v3; // ebp
    unsigned __int8* v4; // esi
    _BYTE* v5; // eax

    if (*(int*)& byte_5D4594[1569756] <= 0)
    {
        v1 = a1;
    }
    else
    {
        v1 = sub_4FE930();
        if (!v1)
            return 0;
        while (*(_DWORD*)(v1 + 4) != 132 || *(_DWORD*)(v1 + 16) != a1 || *(_BYTE*)(v1 + 88) & 1)
        {
            result = sub_4FE940(v1);
            v1 = result;
            if (!result)
                return result;
        }
        if (!v1)
            return 0;
        *(_DWORD*)(v1 + 92) = sub_4FFA90;
        *(_DWORD*)(v1 + 96) = sub_500070;
        *(_DWORD*)(v1 + 100) = sub_500080;
        *(_DWORD*)(v1 + 48) = 0;
    }
    v3 = 0;
    if (*(_DWORD*)& byte_5D4594[1569756] > 0)
    {
        v4 = &byte_5D4594[1569764];
        do
        {
            v5 = (_BYTE*)sub_410580(*v4, v4[1]);
            if (v5)
            {
                *v5 = v4[13];
            }
            else
            {
                v5 = sub_410250(*v4, v4[1]);
                if (!v5)
                    return 0;
                v5[4] |= 8u;
                v5[1] = v4[11];
                v5[2] = v4[12];
                *v5 = v4[13];
                v5[7] = v4[14];
            }
            sub_4FFE80(v1, v5, *((_DWORD*)v4 + 1), v4[8], v4[9], v4[10]);
            ++v3;
            v4 += 16;
        } while (v3 < *(int*)& byte_5D4594[1569756]);
    }
    *(_DWORD*)& byte_5D4594[1569756] = 0;
    return 1;
}

//----- (005004D0) --------------------------------------------------------
int sub_5004D0()
{
    int result; // eax

    for (result = *(_DWORD*)& byte_5D4594[1569752]; result; result = *(_DWORD*)(result + 24))
    {
        if (*(_DWORD*)result == 1)
            ** (_BYTE * *)(result + 8) = *(_BYTE*)(result + 13);
    }
    return result;
}

//----- (005004F0) --------------------------------------------------------
int sub_5004F0()
{
    int result; // eax

    for (result = *(_DWORD*)& byte_5D4594[1569752]; result; result = *(_DWORD*)(result + 24))
    {
        if (*(_DWORD*)result == 1)
            ** (_BYTE * *)(result + 8) = *(_BYTE*)(result + 4);
    }
    return result;
}

//----- (00500510) --------------------------------------------------------
void __cdecl sub_500510(const char* a1)
{
    if (a1)
        strcpy((char*)& byte_5D4594[1570008], a1);
}

//----- (00500540) --------------------------------------------------------
char* __cdecl sub_500540(char* a1, int a2)
{
    char* result; // eax
    char* v3; // edx

    result = sub_5005E0(a1);
    if (result)
    {
        *((_DWORD*)result + 34) = a2;
    }
    else
    {
        result = (char*)nox_malloc(0x94u);
        v3 = result;
        if (result)
        {
            strcpy(result, (const char*)& byte_5D4594[1570140]);
            *((_DWORD*)result + 33) = 0;
            *((_DWORD*)result + 34) = a2;
            *((_DWORD*)result + 36) = 0;
            *((_DWORD*)result + 35) = *(_DWORD*)& byte_5D4594[1570272];
            result = *(char**)& byte_5D4594[1570272];
            if (*(_DWORD*)& byte_5D4594[1570272])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1570272] + 144) = v3;
            *(_DWORD*)& byte_5D4594[1570272] = v3;
        }
    }
    return result;
}

//----- (005005E0) --------------------------------------------------------
char* __cdecl sub_5005E0(char* a1)
{
    unsigned int v1; // edx
    unsigned __int8* v2; // edi
    unsigned __int8* v3; // edi
    char* v4; // esi
    char v5; // cl
    unsigned int v6; // ecx
    char v7; // al
    int i; // esi

    if (strchr(a1, 58))
    {
        v6 = strlen(a1) + 1;
        v7 = v6;
        v6 >>= 2;
        qmemcpy(&byte_5D4594[1570140], a1, 4 * v6);
        v4 = &a1[4 * v6];
        v3 = &byte_5D4594[4 * v6 + 1570140];
        v5 = v7;
    }
    else
    {
        strcpy((char*)& byte_5D4594[1570140], (const char*)& byte_5D4594[1570008]);
        *(_WORD*)& byte_5D4594[strlen((const char*)& byte_5D4594[1570140]) + 1570140] = *(_WORD*)& byte_587000[217952];
        v1 = strlen(a1) + 1;
        v2 = &byte_5D4594[strlen((const char*)& byte_5D4594[1570140]) + 1570140];
        qmemcpy(v2, a1, 4 * (v1 >> 2));
        v4 = &a1[4 * (v1 >> 2)];
        v3 = &v2[4 * (v1 >> 2)];
        v5 = v1;
    }
    qmemcpy(v3, v4, v5 & 3);
    for (i = *(_DWORD*)& byte_5D4594[1570272]; i; i = *(_DWORD*)(i + 140))
    {
        if (!_strcmpi((const char*)i, (const char*)& byte_5D4594[1570140]))
            break;
    }
    return (char*)i;
}

//----- (005006B0) --------------------------------------------------------
char* __cdecl sub_5006B0(char* a1, int a2)
{
    char* result; // eax
    char* v3; // edx

    result = sub_5005E0(a1);
    if (result)
    {
        *((_DWORD*)result + 34) = a2;
    }
    else
    {
        result = (char*)nox_malloc(0x94u);
        v3 = result;
        if (result)
        {
            strcpy(result, (const char*)& byte_5D4594[1570140]);
            *((_DWORD*)result + 33) = 1;
            *((_DWORD*)result + 34) = a2;
            *((_DWORD*)result + 36) = 0;
            *((_DWORD*)result + 35) = *(_DWORD*)& byte_5D4594[1570272];
            result = *(char**)& byte_5D4594[1570272];
            if (*(_DWORD*)& byte_5D4594[1570272])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1570272] + 144) = v3;
            *(_DWORD*)& byte_5D4594[1570272] = v3;
        }
    }
    return result;
}

//----- (00500750) --------------------------------------------------------
int __cdecl sub_500750(char* a1)
{
    char* v1; // eax
    int result; // eax

    v1 = sub_5005E0(a1);
    if (v1)
        result = *((_DWORD*)v1 + 34);
    else
        result = 0;
    return result;
}

//----- (00500770) --------------------------------------------------------
double __cdecl sub_500770(char* a1)
{
    char* v1; // eax
    double result; // st7

    v1 = sub_5005E0(a1);
    if (v1)
        result = *((float*)v1 + 34);
    else
        result = 0.0;
    return result;
}

//----- (00500790) --------------------------------------------------------
void __cdecl sub_500790(LPVOID lpMem)
{
    int v1; // ecx
    int v2; // ecx

    v1 = *((_DWORD*)lpMem + 36);
    if (v1)
        * (_DWORD*)(v1 + 140) = *((_DWORD*)lpMem + 35);
    v2 = *((_DWORD*)lpMem + 35);
    if (v2)
        * (_DWORD*)(v2 + 144) = *((_DWORD*)lpMem + 36);
    if (lpMem == *(LPVOID*)& byte_5D4594[1570272])
        * (_DWORD*)& byte_5D4594[1570272] = *((_DWORD*)lpMem + 35);
    free(lpMem);
}

//----- (005007E0) --------------------------------------------------------
char* __cdecl sub_5007E0(char* a1)
{
    unsigned __int8* v1; // edx
    char* result; // eax
    unsigned int v3; // kr04_4
    char* v4; // esi
    int v5; // esi
    int v6; // edi
    int v7; // esi
    int v8; // ebx
    const char* v9; // edi
    char* v10; // edx
    const char* v11; // ebx
    int v12; // esi
    unsigned int v13; // kr0C_4
    int v14; // edi
    int v15; // ebp
    unsigned int v16; // kr10_4
    int v17; // [esp+18h] [ebp+4h]

    sub_5009B0(a1);
    v1 = (unsigned __int8*)strchr((const char*)& byte_5D4594[1570140], 42);
    if (v1)
    {
        v3 = strlen((const char*)& byte_5D4594[1570140]) + 1;
        result = 0;
        if (!strcmp((const char*)& byte_5D4594[1570140], "*:*"))
        {
            result = *(char**)& byte_5D4594[1570272];
            if (*(_DWORD*)& byte_5D4594[1570272])
            {
                do
                {
                    v4 = (char*) * ((_DWORD*)result + 35);
                    sub_500790(result);
                    result = v4;
                } while (v4);
            }
        }
        else if (v1 == &byte_5D4594[v3 + 1570138])
        {
            v5 = *(_DWORD*)& byte_5D4594[1570272];
            if (*(_DWORD*)& byte_5D4594[1570272])
            {
                do
                {
                    v6 = *(_DWORD*)(v5 + 140);
                    result = (char*)_strnicmp((const char*)v5, (const char*)& byte_5D4594[1570140], v3 - 2);
                    if (!result)
                        sub_500790((LPVOID)v5);
                    v5 = v6;
                } while (v6);
            }
        }
        else if (v1 == &byte_5D4594[1570140])
        {
            v7 = *(_DWORD*)& byte_5D4594[1570272];
            if (*(_DWORD*)& byte_5D4594[1570272])
            {
                do
                {
                    v8 = *(_DWORD*)(v7 + 140);
                    result = strstr((const char*)v7, (const char*)& byte_5D4594[1570141]);
                    if (result)
                    {
                        v9 = result;
                        result = 0;
                        if (v3 - 2 == strlen(v9))
                            sub_500790((LPVOID)v7);
                    }
                    v7 = v8;
                } while (v8);
            }
        }
        else
        {
            v10 = strchr((const char*)& byte_5D4594[1570140], 58);
            result = 0;
            v11 = v10 + 2;
            v12 = *(_DWORD*)& byte_5D4594[1570272];
            v13 = strlen(v10 + 2) + 1;
            if (*(_DWORD*)& byte_5D4594[1570272])
            {
                v14 = v10 - (char*)& byte_5D4594[1570140];
                v17 = v10 - (char*)& byte_5D4594[1570140];
                do
                {
                    v15 = *(_DWORD*)(v12 + 140);
                    result = (char*)_strnicmp((const char*)v12, (const char*)& byte_5D4594[1570140], v14 + 1);
                    if (!result)
                    {
                        result = strstr((const char*)(v14 + v12 + 2), v11);
                        if (result)
                        {
                            v16 = strlen(result) + 1;
                            result = (char*)(v13 - 1);
                            if (v13 - 1 == v16 - 1)
                                sub_500790((LPVOID)v12);
                            v14 = v17;
                        }
                    }
                    v12 = v15;
                } while (v15);
            }
        }
    }
    else
    {
        result = sub_5005E0(a1);
        if (result)
            sub_500790(result);
    }
    return result;
}

//----- (005009B0) --------------------------------------------------------
unsigned int __cdecl sub_5009B0(char* a1)
{
    unsigned int v1; // ecx
    char v2; // al
    unsigned __int8* v3; // edi
    unsigned __int8* v4; // esi
    unsigned int result; // eax

    if (strchr(a1, 58))
    {
        result = strlen(a1) + 1;
        qmemcpy(&byte_5D4594[1570140], a1, result);
    }
    else
    {
        v1 = strlen((const char*)& byte_5D4594[1570008]) + 1;
        v2 = v1;
        v1 >>= 2;
        qmemcpy(&byte_5D4594[1570140], &byte_5D4594[1570008], 4 * v1);
        v4 = &byte_5D4594[4 * v1 + 1570008];
        v3 = &byte_5D4594[4 * v1 + 1570140];
        LOBYTE(v1) = v2;
        result = 0;
        qmemcpy(v3, v4, v1 & 3);
        *(_WORD*)& byte_5D4594[strlen((const char*)& byte_5D4594[1570140]) + 1570140] = *(_WORD*)& byte_587000[217960];
        strcat((char*)& byte_5D4594[1570140], a1);
    }
    return result;
}

//----- (00500A60) --------------------------------------------------------
int sub_500A60()
{
    int result; // eax
    int v1; // eax
    int j; // esi
    int v3; // edi
    int i; // [esp+0h] [ebp-Ch]
    int v5; // [esp+4h] [ebp-8h]
    int v6; // [esp+8h] [ebp-4h]

    v5 = 1;
    sub_426AC0(&v5, 2u);
    if ((__int16)v5 > 1)
        return 0;
    v1 = *(_DWORD*)& byte_5D4594[1570272];
    for (i = 0; v1; ++i)
        v1 = *(_DWORD*)(v1 + 140);
    if (sub_40A5C0(2048))
    {
        sub_426AC0(&i, 4u);
        for (j = *(_DWORD*)& byte_5D4594[1570272]; j; j = *(_DWORD*)(j + 140))
        {
            LOBYTE(v6) = strlen((const char*)j);
            sub_426AC0(&v6, 1u);
            sub_426AC0((_BYTE*)j, (unsigned __int8)v6);
            sub_426AC0((_BYTE*)(j + 132), 4u);
            v3 = *(_DWORD*)(j + 132);
            if (v3)
            {
                if (v3 == 1)
                    sub_426AC0((_BYTE*)(j + 136), 4u);
            }
            else
            {
                sub_426AC0((_BYTE*)(j + 136), 4u);
            }
        }
        result = 1;
    }
    else
    {
        i = 0;
        sub_426AC0(&i, 4u);
        result = 1;
    }
    return result;
}

//----- (00500B70) --------------------------------------------------------
int sub_500B70()
{
    unsigned int i; // esi
    int v2; // [esp+0h] [ebp-118h]
    int v3; // [esp+4h] [ebp-114h]
    unsigned int v4; // [esp+8h] [ebp-110h]
    int v5; // [esp+Ch] [ebp-10Ch]
    int v6; // [esp+10h] [ebp-108h]
    int v7; // [esp+14h] [ebp-104h]
    char v8[256]; // [esp+18h] [ebp-100h]

    sub_5007E0((char*)& byte_587000[217964]);
    v3 = 1;
    sub_426AC0(&v3, 2u);
    if ((__int16)v3 > 1)
        return 0;
    sub_426AC0(&v4, 4u);
    for (i = 0; i < v4; ++i)
    {
        sub_426AC0(&v2, 1u);
        sub_426AC0(v8, (unsigned __int8)v2);
        v8[(unsigned __int8)v2] = 0;
        sub_426AC0(&v5, 4u);
        if (v5)
        {
            if (v5 == 1)
            {
                sub_426AC0(&v7, 4u);
                sub_5006B0(v8, v7);
            }
        }
        else
        {
            sub_426AC0(&v6, 4u);
            sub_500540(v8, v6);
        }
    }
    return 1;
}
// 500B70: using guessed type char var_100[256];

//----- (00500C70) --------------------------------------------------------
int __cdecl sub_500C70(int a1, int a2)
{
    *((_DWORD*)sub_417090(a1) + 912) = a2;
    return sub_4D7EE0(a1, a2);
}

//----- (00500CA0) --------------------------------------------------------
int __cdecl sub_500CA0(int a1, int a2)
{
    int result; // eax

    if (a2 && *(_BYTE*)(a2 + 8) & 4)
        result = *(_DWORD*)& byte_587000[4 * a1 + 217668];
    else
        result = 0;
    return result;
}

//----- (00500CC0) --------------------------------------------------------
int __cdecl sub_500CC0(int a1, int a2)
{
    int v2; // eax
    int result; // eax

    if ((*(_BYTE*)(a2 + 8) & 2 && (v2 = *(_DWORD*)(a2 + 16), (v2 & 0x8000) == 0) || sub_534A40(a2))
        && (*(_BYTE*)(*(_DWORD*)(a2 + 748) + 1440) & 0x80))
    {
        result = sub_4EC4F0(a2, a1);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00500D10) --------------------------------------------------------
int __cdecl sub_500D10(int a1)
{
    int v1; // esi
    int i; // edi

    v1 = *(_DWORD*)(a1 + 516);
    for (i = 0; v1; v1 = *(_DWORD*)(v1 + 512))
    {
        if (sub_500CC0(a1, v1))
            i += sub_500D50(v1);
    }
    return i;
}

//----- (00500D50) --------------------------------------------------------
int __cdecl sub_500D50(int a1)
{
    int v1; // eax
    int v3; // eax

    v1 = *(_DWORD*)(a1 + 12);
    if (v1 & 1)
        return 1;
    v3 = -((v1 & 2) != 0);
    LOBYTE(v3) = v3 & 0xFE;
    return v3 + 4;
}

//----- (00500D70) --------------------------------------------------------
bool __cdecl sub_500D70(int a1, int a2)
{
    int v2; // ebx

    v2 = sub_427460(a2);
    return sub_500D10(a1) + v2 <= 4;
}

//----- (00500DA0) --------------------------------------------------------
int __cdecl sub_500DA0(int a1)
{
    int v1; // eax
    int v2; // edi
    int v3; // ebp
    BYTE v5; // eax
    char* v6; // eax
    int v7; // eax
    int v8; // edx
    int v9; // eax
    int v10; // eax
    double v11; // st7
    int v12; // eax
    int v13; // ecx
    char v14; // al
    float v15; // [esp+0h] [ebp-20h]
    __int16 v16; // [esp+0h] [ebp-20h]
    unsigned __int8 v17[16]; // [esp+10h] [ebp-10h]

    v1 = *(_DWORD*)(a1 + 16);
    v2 = *(_DWORD*)(a1 + 4) - 74;
    if (!v1 || *(_DWORD*)(v1 + 16) & 0x8020 || *(_DWORD*)(a1 + 20))
        return 1;
    if (*(_BYTE*)(v1 + 8) & 4)
    {
        v3 = *(_DWORD*)(v1 + 748);
        if (sub_40A5C0(4608) && !*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * v2 + 4244))
        {
            sub_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:NeedGuideToSummon", 0);
            return 1;
        }
        v5 = sub_500D70(*(_DWORD*)(a1 + 16), v2);
        if (!v5)
        {
            sub_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:CreatureControlFailed", 0);
            return 1;
        }
    }
    if (!sub_500F40(a1, COERCE_FLOAT(&v17[2])))
        return 1;
    v17[10] = *(_BYTE*)(*(_DWORD*)(a1 + 16) + 124);
    v6 = sub_427230(v2);
    *(_WORD*)v17 = sub_4E3AA0(v6);
    *(_WORD*)& v17[11] = (*(_WORD*)& byte_5D4594[1570276])++;
    if (*(_WORD*)& byte_5D4594[1570276] >= 0xFDE8u)
        * (_WORD*)& byte_5D4594[1570276] = 0;
    v7 = *(_DWORD*)& v17[4];
    v17[13] = 0;
    *(_DWORD*)(a1 + 72) = *(_DWORD*)v17;
    v8 = *(_DWORD*)& v17[8];
    *(_DWORD*)(a1 + 76) = v7;
    LOWORD(v7) = *(_WORD*)& v17[12];
    *(_DWORD*)(a1 + 80) = v8;
    *(_WORD*)(a1 + 84) = v7;
    v9 = sub_427460(v2) - 1;
    if (v9)
    {
        v10 = v9 - 1;
        if (v10)
        {
            if (v10 != 2)
            {
                v12 = a1;
                goto LABEL_22;
            }
            v11 = sub_419D70(&byte_587000[218220], 2);
        }
        else
        {
            v11 = sub_419D70(&byte_587000[218204], 1);
        }
    }
    else
    {
        v11 = sub_419D70(&byte_587000[218188], 0);
    }
    v15 = v11;
    v12 = sub_419A70(v15);
LABEL_22:
    v13 = v12 + *(_DWORD*)& byte_5D4594[2598000];
    v16 = v12;
    v14 = v17[10];
    *(_DWORD*)(a1 + 68) = v13;
    sub_5236F0(*(__int16*)& v17[11], (float*)& v17[2], v14, *(__int16*)v17, v16);
    return 0;
}
// 500E24: variable 'v5' is possibly undefined

//----- (00500F40) --------------------------------------------------------
int __cdecl sub_500F40(int a1, float a2)
{
    _DWORD* v2; // esi
    int v3; // eax
    float v4; // edi
    float v5; // edx
    float v6; // ecx
    double v7; // st7
    double v8; // st6
    long double v9; // st6
    float v10; // edx
    int result; // eax
    int v12; // esi
    int v13; // esi
    float v14; // edx
    float v15; // eax
    float v16; // ecx
    int v17; // eax
    int v18; // edx
    float4 v19; // [esp+8h] [ebp-10h]

    v2 = (_DWORD*)a1;
    if (*(float*)& a1 == 0.0)
        return 0;
    v3 = *(_DWORD*)(a1 + 16);
    if (!v3)
        return 0;
    v4 = a2;
    if (a2 == 0.0)
        return 0;
    if (*(_BYTE*)(v3 + 8) & 4)
    {
        v19.field_0 = *(float*)(v3 + 56);
        v5 = *(float*)(v3 + 60);
        v6 = *(float*)(a1 + 56);
        v19.field_8 = *(float*)(a1 + 52);
        v19.field_C = v6;
        v7 = v19.field_8 - v19.field_0;
        v19.field_4 = v5;
        v8 = v6 - v5;
        *(float*)& a1 = v8;
        v9 = sqrt(v8 * *(float*)& a1 + v7 * v7);
        a2 = v9;
        if (v9 > 50.0)
        {
            v19.field_8 = v7 * 50.0 / a2 + v19.field_0;
            v19.field_C = *(float*)& a1 * 50.0 / a2 + v19.field_4;
        }
        if (sub_535250(&v19, 0, 0, 9) && !sub_411A90((float2*)& v19.field_8))
        {
            v10 = v19.field_C;
            *(_DWORD*)LODWORD(v4) = LODWORD(v19.field_8);
            *(float*)(LODWORD(v4) + 4) = v10;
            return 1;
        }
        v12 = v2[4];
        if (*(_BYTE*)(v12 + 8) & 4)
        {
            v13 = *(_DWORD*)(v12 + 748);
            a1 = 2;
            sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v13 + 276) + 2064), 0, &a1);
        }
        return 0;
    }
    v19.field_0 = *(float*)(v3 + 56);
    v14 = *(float*)(v3 + 60);
    v15 = *(float*)(a1 + 52);
    v16 = *(float*)(a1 + 56);
    v19.field_4 = v14;
    v19.field_8 = v15;
    v19.field_C = v16;
    if (sub_535250(&v19, 0, 0, 9))
    {
        *(_DWORD*)LODWORD(v4) = v2[13];
        *(_DWORD*)(LODWORD(v4) + 4) = v2[14];
        result = 1;
    }
    else
    {
        v17 = v2[4];
        *(_DWORD*)LODWORD(v4) = *(_DWORD*)(v17 + 56);
        v18 = *(_DWORD*)(v17 + 60);
        result = 1;
        *(_DWORD*)(LODWORD(v4) + 4) = v18;
    }
    return result;
}

//----- (005010D0) --------------------------------------------------------
int __cdecl sub_5010D0(int a1)
{
    int v1; // eax
    int v2; // edi
    int v3; // ebx
    int result; // eax
    BYTE v5; // eax
    _DWORD* v6; // eax

    v1 = *(_DWORD*)(a1 + 16);
    if (!v1 || *(_DWORD*)(v1 + 16) & 0x8020)
        return 1;
    if (*(_DWORD*)(a1 + 68) - 1 != *(_DWORD*)& byte_5D4594[2598000])
        return 0;
    v2 = *(_DWORD*)(a1 + 4) - 74;
    if (!(*(_BYTE*)(v1 + 8) & 4))
        goto LABEL_17;
    v3 = *(_DWORD*)(v1 + 748);
    if (sub_40A5C0(512) && !*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * v2 + 4244))
    {
        sub_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:NeedGuideToSummon", 0);
        return 1;
    }
    v5 = sub_500D70(*(_DWORD*)(a1 + 16), v2);
    if (v5)
    {
    LABEL_17:
        v6 = sub_5016C0(*(unsigned __int16*)(a1 + 72), (int*)(a1 + 74), *(_DWORD*)(a1 + 16), *(_BYTE*)(a1 + 82));
        if (v6)
            sub_501960(899, (int)v6, 0, 0);
        *(_BYTE*)(a1 + 85) = 1;
        result = 1;
    }
    else
    {
        sub_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:CreatureControlFailed", 0);
        result = 1;
    }
    return result;
}
// 50115B: variable 'v5' is possibly undefined

//----- (005011C0) --------------------------------------------------------
void __cdecl sub_5011C0(int a1)
{
    if (!*(_BYTE*)(a1 + 85))
    {
        sub_523760(*(_WORD*)(a1 + 83));
        sub_501A30(900, (float2*)(a1 + 74), 0, 0);
    }
}

//----- (005011F0) --------------------------------------------------------
int __cdecl sub_5011F0(int* a1)
{
    __int16 v1; // ax
    int v3; // eax
    int v4; // eax
    int v5; // eax
    int v6; // ecx
    int v7; // eax
    int v8; // eax
    double v9; // st7
    int* v10; // eax
    int v11; // edx
    int v12; // [esp-14h] [ebp-1Ch]
    int v13; // [esp-8h] [ebp-10h]
    float v14; // [esp+0h] [ebp-8h]
    int v15; // [esp+0h] [ebp-8h]
    float v16; // [esp+0h] [ebp-8h]

    if (a1[5])
    {
        v14 = sub_419D40(&byte_587000[218296]);
        v1 = sub_419A70(v14);
        sub_4FF380(a1[12], 3, v1, a1[2]);
        sub_4E7540(a1[4], a1[12]);
        return 1;
    }
    v15 = a1[4];
    v3 = sub_424A70(a1[1]);
    v4 = sub_540610((float2*)(a1 + 13), a1[4], v3, 300.0, 0, v15);
    a1[12] = v4;
    if (!v4)
    {
        sub_4DA2C0(a1[4], "Summon.c:CharmNoCreatureCloseEnough", 0);
        sub_501960(16, a1[4], 0, 0);
        return 1;
    }
    if (*(_BYTE*)(v4 + 8) & 2 && !sub_500CC0(a1[4], v4))
    {
        v5 = sub_4272B0(*(unsigned __int16*)(a1[12] + 4));
        v6 = a1[4];
        if (*(_BYTE*)(v6 + 8) & 4)
        {
            if (!v5)
            {
                sub_4DA2C0(v6, "Summon.c:CreatureNotCharmable", 0);
                v12 = a1[4];
                a1[12] = 0;
                sub_501960(16, v12, 0, 0);
                return 1;
            }
            if (!*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v6 + 748) + 276) + 4 * v5 + 4244))
            {
                a1[12] = 0;
                sub_4DA2C0(v6, "Summon.c:NeedGuideToCharm", 0);
                sub_501960(16, a1[4], 0, 0);
                return 1;
            }
        }
        v7 = sub_427460(v5) - 1;
        if (v7)
        {
            v8 = v7 - 1;
            if (v8)
            {
                if (v8 != 2)
                {
                    v10 = a1;
                    goto LABEL_20;
                }
                v9 = sub_419D70(&byte_587000[218456], a1[2] - 1);
            }
            else
            {
                v9 = sub_419D70(&byte_587000[218436], a1[2] - 1);
            }
        }
        else
        {
            v9 = sub_419D70(&byte_587000[218416], a1[2] - 1);
        }
        v16 = v9;
        v10 = (int*)sub_419A70(v16);
    LABEL_20:
        v11 = a1[12];
        a1[17] = (int)v10 + *(_DWORD*)& byte_5D4594[2598000];
        sub_4FF380(v11, 28, (_WORD)v10 + 1, 5);
        sub_4FF130((int)a1);
        return 0;
    }
    v13 = a1[4];
    a1[12] = 0;
    sub_501960(16, v13, 0, 0);
    return 1;
}

//----- (005013E0) --------------------------------------------------------
int __cdecl sub_5013E0(int* a1)
{
    int v1; // eax
    int v2; // eax
    int v4; // eax
    int v5; // ecx
    int v6; // eax
    BYTE v7; // eax
    int v8; // eax
    int v9; // ecx
    int v10; // edi
    int v11; // eax
    int v12; // ebp
    unsigned __int16 v13; // ax
    int v14; // edi
    unsigned __int16 v15; // di
    int v16; // eax
    int v17; // edi
    int v18; // eax
    int v19; // edx
    int v20; // eax
    int v21; // ecx
    int v22; // eax
    int v23; // [esp-10h] [ebp-14h]

    v1 = a1[12];
    if (!v1 || *(_DWORD*)(v1 + 16) & 0x8020)
        goto LABEL_6;
    if (sub_4E6C00(a1[4], a1[12]) > 300.0)
    {
        v2 = a1[4];
        if (*(_BYTE*)(v2 + 8) & 4)
            sub_4DA2C0(v2, "Summon.c:CharmBrokenDistance", 0);
    LABEL_6:
        sub_501960(16, a1[4], 0, 0);
        return 1;
    }
    if (a1[17] - 1 != *(_DWORD*)& byte_5D4594[2598000])
        return 0;
    v4 = a1[12];
    v5 = *(_DWORD*)(v4 + 12);
    if (v5 & 0x2000)
    {
        sub_4DA2C0(a1[4], "Summon.c:CreatureControlImpossible", 0);
    LABEL_13:
        sub_501960(16, a1[4], 0, 0);
        return 1;
    }
    if (*(_BYTE*)(a1[4] + 8) & 4)
    {
        v6 = sub_4272B0(*(unsigned __int16*)(v4 + 4));
        v7 = sub_500D70(a1[4], v6);
        if (!v7)
        {
            sub_4DA2C0(a1[4], "Summon.c:CreatureControlFailed", 0);
            goto LABEL_13;
        }
    }
    sub_4FF5B0(a1[12], 28);
    v8 = sub_4EC580(a1[12]);
    v9 = a1[4];
    if (v8 == v9)
    {
        if (*(_BYTE*)(v9 + 8) & 4)
            sub_4DA2C0(v9, "Summon.c:CreatureAlreadyOwned", 0);
        goto LABEL_6;
    }
    sub_4EC300(a1[12]);
    sub_4EC290(a1[4], a1[12]);
    if (sub_419130(a1[12] + 48))
        sub_419570(a1[12] + 48, *(_DWORD*)(a1[12] + 36));
    v10 = *(_DWORD*)(a1[12] + 748);
    v11 = *(_DWORD*)(v10 + 1440);
    LOBYTE(v11) = v11 | 0x80;
    *(_DWORD*)(v10 + 1440) = v11;
    if (sub_40A5C0(4096))
    {
        v12 = sub_4E3B70(*(unsigned __int16*)(a1[12] + 4));
        v13 = sub_4EE780(a1[12]);
        v14 = *(_DWORD*)(v10 + 484);
        v15 = v14 ? *(_WORD*)(v14 + 72) : *(_WORD*)(*(_DWORD*)(v12 + 136) + 4);
        *(_WORD*)(*(_DWORD*)(a1[12] + 556) + 4) = v15;
        if (v13 > v15)
            sub_4E4560(a1[12], v15);
    }
    v16 = a1[4];
    if (*(_BYTE*)(v16 + 8) & 4)
    {
        v17 = *(_DWORD*)(v16 + 748);
        sub_533900(v16, a1[12], *(_DWORD*)(*(_DWORD*)(v17 + 276) + 3648));
        v18 = a1[12];
        v19 = *(_DWORD*)(v18 + 12);
        LOBYTE(v19) = v19 | 0x80;
        *(_DWORD*)(v18 + 12) = v19;
        v20 = a1[12];
        v21 = *(_DWORD*)(v20 + 12);
        BYTE1(v21) |= 1u;
        *(_DWORD*)(v20 + 12) = v21;
        sub_4D91A0(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064), a1[12]);
        sub_417190(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064), a1[12], 1);
        sub_4DF360(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064), a1[12]);
        if (sub_40A5C0(4096))
            sub_50E140(a1[12]);
    }
    else
    {
        sub_533900(v16, a1[12], 4);
    }
    v23 = a1[4];
    v22 = sub_424800(a1[1], 1);
    sub_501960(v22, v23, 0, 0);
    return 1;
}
// 50148A: variable 'v7' is possibly undefined

//----- (00501690) --------------------------------------------------------
int __cdecl sub_501690(int a1)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 48);
    if (result)
    {
        if (!(*(_DWORD*)(result + 16) & 0x8020))
        {
            sub_4FF5B0(result, 5);
            result = sub_4FF5B0(*(_DWORD*)(a1 + 48), 28);
        }
    }
    return result;
}

//----- (005016C0) --------------------------------------------------------
_DWORD* __cdecl sub_5016C0(int a1, int* a2, int a3, unsigned __int8 a4)
{
    _DWORD* result; // eax
    _DWORD* v5; // esi
    int v6; // ebp
    int v7; // ecx
    int v8; // ebx
    int v9; // eax

    result = sub_4E3450(a1);
    v5 = result;
    if (!result)
        return result;
    sub_4DAA50((int)result, a3, *(float*)a2, *((float*)a2 + 1));
    v6 = v5[187];
    *((_WORD*)v5 + 63) = a4;
    *((_WORD*)v5 + 62) = a4;
    v7 = *(_DWORD*)(v6 + 1440);
    LOBYTE(v7) = v7 | 0x80;
    *(_DWORD*)(v6 + 1440) = v7;
    if (!a3)
        return v5;
    if (!(*(_BYTE*)(a3 + 8) & 4))
    {
        sub_533900(a3, (int)v5, 4);
        *(_DWORD*)(v6 + 1360) = 38;
        return v5;
    }
    v8 = *(_DWORD*)(a3 + 748);
    sub_533900(a3, (int)v5, *(_DWORD*)(*(_DWORD*)(v8 + 276) + 3648));
    *(_DWORD*)(v6 + 1360) = 38;
    v5[3] |= 0x80u;
    sub_4D91A0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)v5);
    sub_417190(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)v5, 1);
    sub_4DF360(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)v5);
    if (sub_419130(a3 + 48))
        sub_4191D0(*(_BYTE*)(a3 + 52), a3 + 48, 1, v5[9], 0);
    v9 = v5[3];
    BYTE1(v9) |= 1u;
    v5[3] = v9;
    return v5;
}

//----- (005017F0) --------------------------------------------------------
void __cdecl sub_5017F0(int a1)
{
    int v1; // eax
    int v2; // esi

    if (!*(_DWORD*)& byte_5D4594[1570280])
        * (_DWORD*)& byte_5D4594[1570280] = sub_4E3AA0((CHAR*)& byte_587000[218608]);
    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 504);
        if (v1)
        {
            do
            {
                v2 = *(_DWORD*)(v1 + 496);
                if (*(unsigned __int16*)(v1 + 4) == *(_DWORD*)& byte_5D4594[1570280])
                    sub_4E5CC0(v1);
                v1 = v2;
            } while (v2);
        }
        sub_522FF0(129, (float2*)(a1 + 56));
        sub_4E5CC0(a1);
    }
}

//----- (00501860) --------------------------------------------------------
int sub_501860()
{
    int result; // eax
    unsigned __int8* v1; // eax

    if (*(_DWORD*)& byte_5D4594[1599064])
        return 1;
    *(_DWORD*)& byte_5D4594[1599056] = nox_new_alloc_class("AudEvent", 36, 128);
    if (!*(_DWORD*)& byte_5D4594[1599056])
        return 0;
    v1 = &byte_5D4594[1570292];
    do
    {
        *((_DWORD*)v1 - 2) = 600;
        *(_DWORD*)v1 = 0;
        *((_DWORD*)v1 + 1) = 0;
        *((_DWORD*)v1 + 2) = 0;
        *((_DWORD*)v1 + 3) = 0;
        *((_DWORD*)v1 + 4) = 0;
        v1 += 28;
    } while ((int)v1 < (int)& byte_5D4594[1598936]);
    result = 1;
    *(_DWORD*)& byte_5D4594[1599064] = 1;
    return result;
}

//----- (005018D0) --------------------------------------------------------
void sub_5018D0()
{
    if (*(_DWORD*)& byte_5D4594[1599064])
    {
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1599056]);
        *(_DWORD*)& byte_5D4594[1599060] = 0;
        *(_DWORD*)& byte_5D4594[1599064] = 0;
    }
}

//----- (00501900) --------------------------------------------------------
int __cdecl sub_501900(int a1)
{
    return *(_DWORD*)& byte_5D4594[28 * a1 + 1570288];
}

//----- (00501920) --------------------------------------------------------
int __cdecl sub_501920(int a1)
{
    return *(_DWORD*)& byte_5D4594[28 * a1 + 1570284];
}

//----- (00501940) --------------------------------------------------------
int __cdecl sub_501940(int a1)
{
    return *(_DWORD*)& byte_5D4594[28 * a1 + 1570296];
}

//----- (00501960) --------------------------------------------------------
_DWORD* __cdecl sub_501960(int a1, int a2, int a3, int a4)
{
    _DWORD* result; // eax
    _DWORD* v5; // esi

    result = (_DWORD*)sub_40A5C0(0x80000);
    if (result != (_DWORD*)1)
    {
        if (a2)
        {
            if (a1)
            {
                result = (_DWORD*)sub_501940(a1);
                if ((int)result > 0)
                {
                    if (!sub_40A5C0(4096) || !(*(_BYTE*)(a2 + 8) & 4) || (result = (_DWORD*)sub_419E60(a2)) == 0)
                    {
                        result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1599056]);
                        v5 = result;
                        if (result)
                        {
                            result[1] = a1;
                            if (*(_BYTE*)(a2 + 16) & 0x20)
                                result[4] = 0;
                            else
                                result[4] = a2;
                            result[2] = *(_DWORD*)(a2 + 56);
                            result[3] = *(_DWORD*)(a2 + 60);
                            result[5] = a3;
                            result[6] = a4;
                            if (a3 != 2)
                                sub_50CD40(a1, a2, (_DWORD*)(a2 + 56));
                            result = *(_DWORD * *)& byte_5D4594[1599060];
                            *v5 = *(_DWORD*)& byte_5D4594[1599060];
                            *(_DWORD*)& byte_5D4594[1599060] = v5;
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (00501A30) --------------------------------------------------------
void __cdecl sub_501A30(int a1, float2* a2, int a3, int a4)
{
    int* v4; // esi

    if (!sub_40A5C0(0x80000))
    {
        if (a1)
        {
            if (sub_501940(a1) > 0)
            {
                v4 = (int*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1599056]);
                if (v4)
                {
                    v4[1] = a1;
                    *((float2*)v4 + 1) = *a2;
                    v4[4] = 0;
                    v4[5] = a3;
                    v4[6] = a4;
                    if (a3 != 2)
                        sub_50CD40(a1, 0, a2);
                    *v4 = *(_DWORD*)& byte_5D4594[1599060];
                    *(_DWORD*)& byte_5D4594[1599060] = v4;
                }
            }
        }
    }
}

//----- (00501AC0) --------------------------------------------------------
int __cdecl sub_501AC0(int a1)
{
    int result; // eax

    result = a1;
    if (a1 >= 0)
    {
        if (a1 > 100)
            result = 100;
        *(_DWORD*)& byte_5D4594[1599068] = result;
    }
    else
    {
        result = 0;
        *(_DWORD*)& byte_5D4594[1599068] = 0;
    }
    return result;
}

//----- (00501AE0) --------------------------------------------------------
int sub_501AE0()
{
    return *(_DWORD*)& byte_5D4594[1599068];
}

//----- (00501AF0) --------------------------------------------------------
int __cdecl sub_501AF0(int a1, float* a2, float* a3)
{
    float* v3; // eax
    int v4; // esi
    double v5; // st7
    int v6; // eax
    int v7; // eax
    int v9; // [esp+Ch] [ebp-4h]
    float v10; // [esp+14h] [ebp+4h]
    float v11; // [esp+18h] [ebp+8h]

    v3 = a2;
    v4 = *(_DWORD*)& byte_5D4594[28 * a1 + 1570284];
    v9 = *(_DWORD*)& byte_5D4594[28 * a1 + 1570284];
    v11 = *a2 - *a3;
    v10 = v3[1] - a3[1];
    v5 = (double)v9;
    if (v11 >= v5)
        return 0;
    if (v10 >= v5)
        return 0;
    if (v4 <= 0)
        return 0;
    v6 = sub_419B10(sqrt(v10 * v10 + v11 * v11 + 0.1));
    if (v6 >= v4)
        return 0;
    v7 = 100 * (v4 - v6) / v4;
    if (v7 <= 100)
    {
        if (v7 < 0)
            v7 = 0;
    }
    else
    {
        v7 = 100;
    }
    return v7 <= *(int*)& byte_5D4594[1599068] ? 0 : v7;
}

//----- (00501BB0) --------------------------------------------------------
unsigned int __cdecl sub_501BB0(int a1, float* a2, float* a3)
{
    int v3; // eax
    int v4; // ecx

    v3 = sub_501AF0(a1, a2, a3);
    v4 = *(_DWORD*)& byte_5D4594[28 * a1 + 1570292];
    if (!v4)
        return 0;
    return (v3 * v4) / 100;
}

//----- (00501C00) --------------------------------------------------------
char __cdecl sub_501C00(float* a1, int a2)
{
    char v2; // bl
    int v3; // ecx
    char* v4; // eax
    int v5; // eax
    float v6; // ecx
    struc_19* v7; // eax
    int2 v9; // [esp+4h] [ebp-8h]

    v2 = 0;
    if (a2)
    {
        v3 = *(_DWORD*)(a2 + 8);
        if (v3 & 4)
        {
            v2 = *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 3668);
            goto LABEL_7;
        }
        if (v3 & 2)
        {
            v4 = sub_4214A0(**(_DWORD * *)(a2 + 748));
            if (v4)
            {
                v2 = v4[130];
            LABEL_7:
                if (v2)
                    return v2;
                goto LABEL_8;
            }
        }
    }
LABEL_8:
    v5 = sub_419A70(*a1);
    v6 = a1[1];
    v9.field_0 = v5;
    v9.field_4 = sub_419A70(v6);
    v7 = sub_4217B0(&v9, 0);
    if (v7)
        return BYTE2(v7->field_0[32]);
    return v2;
}

//----- (00501CA0) --------------------------------------------------------
int __cdecl sub_501CA0(int a1)
{
    int v1; // ebx
    int v2; // ebp
    int v3; // eax
    int v4; // ecx
    int v5; // ecx
    int v6; // eax
    int v7; // edx
    struc_19* v8; // eax
    int i; // esi
    int v10; // eax
    char* v11; // eax
    char v12; // al
    int v13; // eax
    int v14; // eax
    char* v16; // [esp+Ch] [ebp-Ch]
    int2 v17; // [esp+10h] [ebp-8h]
    char v18; // [esp+1Ch] [ebp+4h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 748);
    v16 = 0;
    v3 = *(_DWORD*)(v2 + 276);
    if (!(*(_BYTE*)(v3 + 3680) & 3) || (v4 = *(_DWORD*)(v3 + 3628)) == 0)
    {
        if (*(int*)(v3 + 3664) == -559023410)
            sub_421C70(a1);
        v5 = *(_DWORD*)(v2 + 276);
        goto LABEL_11;
    }
    if (*(_BYTE*)(v4 + 8) & 4)
    {
        v5 = *(_DWORD*)(*(_DWORD*)(v4 + 748) + 276);
    LABEL_11:
        v18 = *(_BYTE*)(v5 + 3668);
        goto LABEL_12;
    }
    v6 = sub_419A70(*(float*)(*(_DWORD*)(v3 + 3628) + 56));
    v7 = *(_DWORD*)(v2 + 276);
    v17.field_0 = v6;
    v17.field_4 = sub_419A70(*(float*)(*(_DWORD*)(v7 + 3628) + 60));
    v8 = sub_4217B0(&v17, 0);
    if (v8)
        v18 = BYTE2(v8->field_0[32]);
    else
        v18 = 0;
LABEL_12:
    sub_501E80();
    if (sub_419130(v1 + 48))
        v16 = sub_418AB0(*(unsigned __int8*)(v1 + 52));
    for (i = *(_DWORD*)& byte_5D4594[1599060]; i; i = *(_DWORD*)i)
    {
        v10 = *(_DWORD*)(i + 20);
        if (v10 == 1)
        {
            v11 = sub_418AB0(*(_DWORD*)(i + 24));
            if (v16 && v11 && v16 == v11)
                goto LABEL_22;
        }
        else if (v10 != 2 || *(_DWORD*)(v1 + 36) == *(_DWORD*)(i + 24))
        {
        LABEL_22:
            v12 = sub_501C00((float*)(i + 8), *(_DWORD*)(i + 16));
            if (v12 == v18 || !v12)
            {
                if (*(_BYTE*)(v2 + 188) || (v13 = *(_DWORD*)(i + 4), v13 < 186) || v13 > 193 || v1 != *(_DWORD*)(i + 16))
                {
                    v14 = sub_501AF0(*(_DWORD*)(i + 4), (float*)(i + 8), (float*)(*(_DWORD*)(v2 + 276) + 3632)) >> 1;
                    if (v14 > 0)
                    {
                        if (*(_DWORD*)& byte_5D4594[28 * *(_DWORD*)(i + 4) + 1570304])
                            sub_501EA0((_DWORD*)i, v14);
                        else
                            sub_501FD0(v1, i, v14);
                    }
                }
            }
            continue;
        }
    }
    return sub_502060(v1);
}

//----- (00501E80) --------------------------------------------------------
int sub_501E80()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[1598928], 0, 0x80u);
    return result;
}

//----- (00501EA0) --------------------------------------------------------
_DWORD* __cdecl sub_501EA0(_DWORD* a1, int a2)
{
    unsigned int v2; // esi

    v2 = a1[1];
    if (!sub_501EF0(v2))
    {
        sub_501F10(v2);
        *(_DWORD*)& byte_5D4594[28 * v2 + 1570308] = 0;
    }
    a1[8] = a2;
    return sub_501F30((int)& byte_5D4594[28 * v2 + 1570284], a1);
}

//----- (00501EF0) --------------------------------------------------------
int __cdecl sub_501EF0(unsigned int a1)
{
    return *(_DWORD*)& byte_5D4594[4 * (a1 >> 5) + 1598928] & (1 << (a1 & 0x1F));
}

//----- (00501F10) --------------------------------------------------------
unsigned int __cdecl sub_501F10(unsigned int a1)
{
    unsigned int result; // eax

    result = a1 >> 5;
    *(_DWORD*)& byte_5D4594[4 * (a1 >> 5) + 1598928] |= 1 << (a1 & 0x1F);
    return result;
}

//----- (00501F30) --------------------------------------------------------
_DWORD* __cdecl sub_501F30(int a1, _DWORD* a2)
{
    _DWORD* result; // eax
    _DWORD* v3; // ebp
    int v4; // ebx
    int v5; // esi
    int v6; // edx
    int v7; // ecx
    _DWORD* v8; // [esp+10h] [ebp-4h]

    result = *(_DWORD * *)(a1 + 24);
    v3 = *(_DWORD * *)(a1 + 24);
    v8 = *(_DWORD * *)(a1 + 24);
    if (result)
    {
        v4 = 1;
        v5 = a2[8];
        do
        {
            v6 = result[8];
            v7 = v5 - v6;
            if (v5 - v6 < 0)
                v7 = v6 - v5;
            if (v7 >= 5)
            {
                if (v5 > v6)
                    break;
            }
            else if (byte_5D4594[28 * a2[1] + 1570300] & 0x10)
            {
                break;
            }
            if (++v4 > * (int*)(a1 + 20))
                return result;
            v3 = result;
            result = (_DWORD*)result[7];
        } while (result);
        a2[7] = result;
        if (result == v8)
            * (_DWORD*)(a1 + 24) = a2;
        else
            v3[7] = a2;
    }
    else
    {
        result = a2;
        a2[7] = v3;
        *(_DWORD*)(a1 + 24) = a2;
    }
    return result;
}

//----- (00501FD0) --------------------------------------------------------
int __cdecl sub_501FD0(int a1, int a2, __int16 a3)
{
    int v3; // esi
    double v4; // st7
    __int16 v5; // dx
    float v7; // [esp+0h] [ebp-Ch]

    v3 = *(_DWORD*)(a1 + 748);
    v4 = *(float*)(a2 + 8);
    v5 = *(_WORD*)(a2 + 4) | (a3 << 10);
    LOBYTE(a1) = (a1 == *(_DWORD*)(a2 + 16)) - 90;
    HIWORD(a1) = v5;
    v7 = v4 - *(float*)(*(_DWORD*)(v3 + 276) + 3632);
    BYTE1(a1) = 50 * sub_419A70(v7) / (nox_win_width / 2);
    return sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, &a1, 4);
}

//----- (00502060) --------------------------------------------------------
int __cdecl sub_502060(int a1)
{
    int* v1; // ecx
    int v2; // ebx
    int result; // eax
    int v4; // edi
    int v5; // esi
    int i; // ebp
    int v7; // edx
    unsigned int v8; // [esp+10h] [ebp-8h]
    unsigned __int8* v9; // [esp+14h] [ebp-4h]

    v1 = (int*)& byte_5D4594[1598928];
    v2 = 0;
    v9 = &byte_5D4594[1598928];
    do
    {
        result = *v1;
        v8 = *v1;
        if (*v1)
        {
            v4 = 0;
            do
            {
                if (result & 1)
                {
                    v5 = *(_DWORD*)& byte_5D4594[28 * (v2 + v4) + 1570308];
                    for (i = *(_DWORD*)& byte_5D4594[28 * (v2 + v4) + 1570304]; v5; v5 = *(_DWORD*)(v5 + 28))
                    {
                        v7 = i--;
                        if (v7 <= 0)
                            break;
                        sub_501FD0(a1, v5, *(_DWORD*)(v5 + 32));
                    }
                }
                result = v8 >> 1;
                ++v4;
                v8 >>= 1;
            } while (v4 < 32);
            v1 = (int*)v9;
        }
        ++v1;
        v2 += 32;
        v9 = (unsigned __int8*)v1;
    } while ((int)v1 < (int)& byte_5D4594[1599056]);
    return result;
}

//----- (00502100) --------------------------------------------------------
void sub_502100()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1599056]);
    *(_DWORD*)& byte_5D4594[1599060] = 0;
}

//----- (00502120) --------------------------------------------------------
BOOL __cdecl sub_502120(int a1, void* a2)
{
    int v2; // esi
    int v3; // ebp
    unsigned __int8* v4; // eax
    int v5; // eax
    char* v6; // ecx
    char v7; // bl
    unsigned __int8* v8; // ecx
    unsigned __int8* v9; // ecx
    unsigned __int8 v10; // dl
    int v11; // ecx
    __int16 v12; // dx
    __int16 v13; // dx
    BOOL result; // eax
    int v15; // [esp-4h] [ebp-20h]
    unsigned __int8 v16; // [esp+10h] [ebp-Ch]
    unsigned __int8 v17; // [esp+14h] [ebp-8h]
    unsigned __int8 v18; // [esp+18h] [ebp-4h]
    unsigned __int8 v19; // [esp+20h] [ebp+4h]

    v2 = a1;
    v3 = *(_DWORD*)& byte_5D4594[1599064];
    v4 = *(unsigned __int8**)(a1 + 8);
    v15 = a1;
    v19 = *v4;
    *(_DWORD*)(v15 + 8) = v4 + 1;
    sub_40ACC0(a2, 1u, v19, v15);
    *((_BYTE*)a2 + v19) = 0;
    v5 = sub_40AF50(a2);
    if (!v5)
        v3 = 0;
    while (2)
    {
        v6 = *(char**)(v2 + 8);
        v7 = *v6;
        v8 = (unsigned __int8*)(v6 + 1);
        *(_DWORD*)(v2 + 8) = v8;
        switch (v7)
        {
        case 0:
            result = v7 == 0;
            break;
        case 1:
        case 5:
            *(_DWORD*)(v2 + 8) = v8 + 1;
            continue;
        case 2:
            v16 = *v8;
            *(_DWORD*)(v2 + 8) = v8 + 1;
            if (v3)
                * (_DWORD*)& byte_5D4594[28 * v5 + 1570300] = v16;
            continue;
        case 3:
            v18 = *v8;
            *(_DWORD*)(v2 + 8) = v8 + 1;
            if (v3)
                * (_DWORD*)& byte_5D4594[28 * v5 + 1570292] = v18;
            continue;
        case 4:
            v17 = *v8;
            *(_DWORD*)(v2 + 8) = v8 + 1;
            if (v3)
                * (_DWORD*)& byte_5D4594[28 * v5 + 1570304] = v17;
            continue;
        case 6:
            *(_DWORD*)(v2 + 8) = v8 + 2;
            continue;
        case 7:
            while (1)
            {
                v9 = *(unsigned __int8**)(v2 + 8);
                v10 = *v9;
                v11 = (int)(v9 + 1);
                *(_DWORD*)(v2 + 8) = v11;
                if (!v10)
                    break;
                *(_DWORD*)(v2 + 8) = v11 + v10;
                ++* (_DWORD*)& byte_5D4594[28 * v5 + 1570296];
            }
            continue;
        case 8:
            *(_DWORD*)(v2 + 8) = v8 + 8;
            continue;
        case 9:
            v12 = *(_WORD*)v8;
            *(_DWORD*)(v2 + 8) = v8 + 2;
            if (v3)
                * (_DWORD*)& byte_5D4594[28 * v5 + 1570284] = 15 * v12;
            continue;
        case 0xA:
            v13 = *(_WORD*)v8;
            *(_DWORD*)(v2 + 8) = v8 + 2;
            if (v3)
                * (_DWORD*)& byte_5D4594[28 * v5 + 1570288] = v13;
            continue;
        default:
            result = 0;
            break;
        }
        break;
    }
    return result;
}

//----- (00502320) --------------------------------------------------------
int __cdecl sub_502320(int a1, void* a2)
{
    int v2; // ebx
    int* v3; // eax
    int v4; // edi

    v2 = 0;
    v3 = *(int**)(a1 + 8);
    v4 = *v3;
    *(_DWORD*)(a1 + 8) = v3 + 1;
    if (v4 <= 0)
        return 1;
    while (sub_502370(a1, a2))
    {
        if (++v2 >= v4)
            return 1;
    }
    return 0;
}

//----- (00502370) --------------------------------------------------------
int __cdecl sub_502370(int a1, void* a2)
{
    char* v2; // eax
    int v3; // edi
    int v4; // eax
    unsigned __int8* v5; // ecx
    __int16 v6; // bp
    unsigned __int8 v7; // dl
    __int16 v8; // di
    int v9; // ecx
    char* v10; // eax
    char v11; // dl
    int v12; // eax
    char* v14; // eax
    char v15; // cl
    int v16; // eax
    unsigned __int8 v17; // [esp+14h] [ebp+8h]

    v2 = *(char**)(a1 + 8);
    v3 = *v2;
    *(_DWORD*)(a1 + 8) = v2 + 1;
    sub_40ACC0(a2, 1u, v3, a1);
    *((_BYTE*)a2 + v3) = 0;
    v4 = sub_40AF50(a2);
    if (v4 && *(_DWORD*)& byte_5D4594[1599064])
    {
        v5 = *(unsigned __int8**)(a1 + 8);
        v6 = *(_WORD*)v5;
        v5 += 2;
        *(_DWORD*)(a1 + 8) = v5;
        v7 = *v5++;
        *(_DWORD*)(a1 + 8) = v5;
        v8 = *(_WORD*)v5;
        v5 += 2;
        *(_DWORD*)(a1 + 8) = v5;
        v17 = *v5;
        *(_DWORD*)(a1 + 8) = v5 + 1;
        if (v8 > 0)
            * (_DWORD*)& byte_5D4594[28 * v4 + 1570284] = 15 * v8;
        v9 = 28 * v4;
        *(_DWORD*)& byte_5D4594[v9 + 1570288] = v6;
        *(_DWORD*)& byte_5D4594[v9 + 1570292] = v7;
        *(_DWORD*)& byte_5D4594[v9 + 1570304] = v17;
        *(_DWORD*)(a1 + 8) += 3;
        while (1)
        {
            v10 = *(char**)(a1 + 8);
            v11 = *v10;
            v12 = (int)(v10 + 1);
            *(_DWORD*)(a1 + 8) = v12;
            if (!v11)
                break;
            *(_DWORD*)(a1 + 8) = v12 + v11;
            ++* (_DWORD*)& byte_5D4594[v9 + 1570296];
        }
        *(_DWORD*)& byte_5D4594[v9 + 1570300] = 2;
    }
    else
    {
        for (*(_DWORD*)(a1 + 8) += 9; ; *(_DWORD*)(a1 + 8) = v16 + v15)
        {
            v14 = *(char**)(a1 + 8);
            v15 = *v14;
            v16 = (int)(v14 + 1);
            *(_DWORD*)(a1 + 8) = v16;
            if (!v15)
                break;
        }
    }
    return 1;
}

//----- (00502490) --------------------------------------------------------
unsigned __int8* __cdecl sub_502490(int* a1, int a2, int a3)
{
    int v3; // eax
    int v4; // ecx
    unsigned __int8* result; // eax
    int v6; // edi
    LPVOID* v7; // esi
    int v8; // eax

    *(_DWORD*)& byte_5D4594[1599076] = 0;
    v3 = *a1;
    if (*a1 & 1)
        return 0;
    v4 = a1[1];
    if (v4 == -1)
        return 0;
    if (v3 & 2)
    {
        LOBYTE(v3) = v3 | 1;
        *a1 = v3;
    }
    if (*(_DWORD*)& byte_5D4594[1599660])
    {
        sub_5025A0((int)a1, a2, a3);
        result = &byte_5D4594[1599076];
    }
    else
    {
        sub_507310(v4, a2, a3);
        if (*(_DWORD*)(48 * a1[1] + *(_DWORD*)& byte_5D4594[1599636] + 4))
            * (_DWORD*)& byte_5D4594[1599076] = script_pop();
        v6 = *(_DWORD*)& byte_5D4594[1599624];
        *(_DWORD*)& byte_5D4594[1599660] = 0;
        if (*(_DWORD*)& byte_5D4594[1599624] < *(int*)& byte_5D4594[1599632])
        {
            v7 = (LPVOID*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1599624] + 3831212];
            do
            {
                free(*v7);
                v8 = *(_DWORD*)& byte_5D4594[1599632];
                *v7 = 0;
                ++v6;
                ++v7;
            } while (v6 < v8);
            v6 = *(_DWORD*)& byte_5D4594[1599624];
        }
        *(_DWORD*)& byte_5D4594[1599632] = v6;
        sub_5025E0((int)a1, a2, a3);
        if (*(_DWORD*)& byte_5D4594[1599468] > 0)
            sub_502490(*(int**)& byte_5D4594[1599084], *(int*)& byte_5D4594[1599088], *(int*)& byte_5D4594[1599092]);
        result = &byte_5D4594[1599076];
    }
    return result;
}

//----- (005025A0) --------------------------------------------------------
void __cdecl sub_5025A0(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // ecx

    if (*(int*)& byte_5D4594[1599468] < 32)
    {
        result = 12 * *(_DWORD*)& byte_5D4594[1599468];
        v4 = *(_DWORD*)& byte_5D4594[1599468] + 1;
        *(_DWORD*)& byte_5D4594[result + 1599084] = a1;
        *(_DWORD*)& byte_5D4594[result + 1599088] = a2;
        *(_DWORD*)& byte_5D4594[result + 1599092] = a3;
        *(_DWORD*)& byte_5D4594[1599468] = v4;
    }
}

//----- (005025E0) --------------------------------------------------------
int __cdecl sub_5025E0(int a1, int a2, int a3)
{
    int result; // eax
    int v4; // edi
    int v5; // ecx
    unsigned __int8* v6; // esi
    unsigned __int8* v7; // eax
    int v8; // ecx
    int v9; // [esp+4h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1599468];
    if (*(_DWORD*)& byte_5D4594[1599468])
    {
        v4 = 0;
        if (*(_DWORD*)& byte_5D4594[1599468] > 0)
        {
            v5 = *(_DWORD*)& byte_5D4594[1599468] - 1;
            v9 = *(_DWORD*)& byte_5D4594[1599468] - 1;
            v6 = &byte_5D4594[1599084];
            do
            {
                if (*(_DWORD*)v6 == a1 && *((_DWORD*)v6 + 1) == a2 && *((_DWORD*)v6 + 2) == a3)
                {
                    if ((int)v6 < (int)& byte_5D4594[1599468] && v4 < v5)
                    {
                        v7 = v6;
                        v8 = v5 - v4;
                        do
                        {
                            --v8;
                            *(_DWORD*)v7 = *((_DWORD*)v7 + 3);
                            *((_DWORD*)v7 + 1) = *((_DWORD*)v7 + 4);
                            *((_DWORD*)v7 + 2) = *((_DWORD*)v7 + 5);
                            v7 += 12;
                        } while (v8);
                        result = *(_DWORD*)& byte_5D4594[1599468];
                        v5 = v9;
                    }
                    --result;
                    --v5;
                    *(_DWORD*)& byte_5D4594[1599468] = result;
                    v9 = v5;
                }
                ++v4;
                v6 += 12;
            } while (v4 < result);
        }
    }
    return result;
}

//----- (00502670) --------------------------------------------------------
void __cdecl sub_502670(unsigned __int8* a1, int a2, void(__cdecl* a3)(int, int), int a4)
{
    int* i; // esi
    int v5; // eax
    int* j; // esi
    _DWORD* v7; // eax
    int* k; // esi
    int v9; // eax
    int* l; // esi
    unsigned __int8* v11; // eax

    if (a1)
    {
        switch (*a1)
        {
        case 0u:
            if (!a2)
            {
                for (i = (int*) * ((_DWORD*)a1 + 21); i; i = (int*)i[2])
                {
                    v5 = sub_4ED020(*i);
                    if (v5)
                        a3(v5, a4);
                }
            }
            break;
        case 1u:
            if (a2 == 1)
            {
                for (j = (int*) * ((_DWORD*)a1 + 21); j; j = (int*)j[2])
                {
                    v7 = sub_579C40(*j);
                    if (v7)
                        a3((int)v7, a4);
                }
            }
            break;
        case 2u:
            if (a2 == 2)
            {
                for (k = (int*) * ((_DWORD*)a1 + 21); k; k = (int*)k[2])
                {
                    v9 = sub_410580(*k, k[1]);
                    if (v9)
                        a3(v9, a4);
                }
                goto LABEL_20;
            }
            break;
        case 3u:
        LABEL_20:
            for (l = (int*) * ((_DWORD*)a1 + 21); l; l = (int*)l[2])
            {
                v11 = (unsigned __int8*)sub_57C0A0(*l);
                if (v11)
                    sub_502670(v11, a2, a3, a4);
            }
            break;
        default:
            return;
        }
    }
}

//----- (00502790) --------------------------------------------------------
int __cdecl sub_502790(FILE* a1, char* a2)
{
    int result; // eax
    int i; // ebx
    int v4; // edi
    int v5; // eax
    int v6; // [esp+8h] [ebp-410h]
    int v7; // [esp+Ch] [ebp-40Ch]
    int v8; // [esp+10h] [ebp-408h]
    int v9; // [esp+14h] [ebp-404h]
    char v10[1024]; // [esp+18h] [ebp-400h]

    sub_408E40((char*)& v8, 4, 1, a1);
    sub_408E40(v10, 1, v8, a1);
    sub_408E40(a2, 4, 1, a1);
    sub_408E40((char*)& v7, 4, 1, a1);
    result = v7;
    for (i = 0; i < v7; ++i)
    {
        sub_408E40((char*)& v6, 1, 1, a1);
        sub_409050(a1, 1, 1);
        v4 = 0;
        v5 = 268 * (unsigned __int8)v6;
        if (byte_587000[v5 + 218640])
        {
            do
            {
                switch (*(_DWORD*)& byte_587000[8 * v4 + 218648 + v5])
                {
                case 0:
                case 3:
                case 4:
                case 5:
                case 6:
                    sub_409050(a1, 4, 1);
                    break;
                case 1:
                    sub_409050(a1, 8, 1);
                    break;
                case 2:
                case 7:
                    sub_408E40((char*)& v9, 1, 1, a1);
                    sub_409050(a1, (unsigned __int8)v9, 1);
                    break;
                default:
                    break;
                }
                ++v4;
                v5 = 268 * (unsigned __int8)v6;
            } while (v4 < byte_587000[v5 + 218640]);
        }
        result = v7;
    }
    return result;
}

//----- (005028E0) --------------------------------------------------------
char* sub_5028E0()
{
    char* result; // eax

    *(_DWORD*)& byte_5D4594[1599480] = -1;
    *(_DWORD*)& byte_5D4594[1599572] = -1;
    *(_DWORD*)& byte_5D4594[1599476] = 0;
    *(_DWORD*)& byte_5D4594[1599540] = 0;
    *(_DWORD*)& byte_5D4594[1599544] = 0;
    *(_DWORD*)& byte_5D4594[1599532] = 0;
    *(_DWORD*)& byte_5D4594[1599536] = 0;
    *(_DWORD*)& byte_5D4594[1599556] = 0;
    *(_DWORD*)& byte_5D4594[1599560] = 0;
    *(_DWORD*)& byte_5D4594[1599548] = 0;
    *(_DWORD*)& byte_5D4594[1599552] = 0;
    *(_DWORD*)& byte_5D4594[1599564] = 0;
    *(_DWORD*)& byte_5D4594[1599568] = 0;
    *(_DWORD*)& byte_5D4594[1599484] = 0;
    *(_DWORD*)& byte_5D4594[1599488] = 0;
    *(_DWORD*)& byte_5D4594[1599492] = 0;
    *(_DWORD*)& byte_5D4594[1599496] = 0;
    memset(&byte_5D4594[1599500], 0, 0x20u);
    if (!*(_DWORD*)& byte_5D4594[1599588])
        * (_DWORD*)& byte_5D4594[1599588] = nox_malloc(0x800u);
    result = *(char**)& byte_5D4594[1599592];
    if (!*(_DWORD*)& byte_5D4594[1599592])
    {
        result = (char*)nox_malloc(0x800u);
        *(_DWORD*)& byte_5D4594[1599592] = result;
    }
    return result;
}

//----- (005029A0) --------------------------------------------------------
int __cdecl sub_5029A0(char* a1)
{
    int v1; // edi
    int i; // esi

    v1 = 0;
    if (*(int*)& byte_5D4594[1599596] <= 0)
        return -1;
    for (i = 0; _strcmpi(a1, (const char*)(i + *(_DWORD*)& byte_5D4594[1599576])); i += 76)
    {
        if (++v1 >= *(int*)& byte_5D4594[1599596])
            return -1;
    }
    return v1;
}

//----- (005029F0) --------------------------------------------------------
int __cdecl sub_5029F0(int a1)
{
    int result; // eax

    if (a1 < 0 || a1 > * (int*)& byte_5D4594[1599596])
        result = 0;
    else
        result = *(_DWORD*)& byte_5D4594[1599576] + 76 * a1;
    return result;
}

//----- (00502A20) --------------------------------------------------------
int sub_502A20()
{
    return *(_DWORD*)& byte_5D4594[1599596];
}

//----- (00502A30) --------------------------------------------------------
BOOL __cdecl sub_502A30(char* a1)
{
    int v1; // eax

    v1 = sub_5029A0(a1);
    return sub_502D70(v1);
}

//----- (00502A50) --------------------------------------------------------
int __cdecl sub_502A50(char* a1)
{
    int result; // eax

    sub_502DF0();
    if (a1)
    {
        strncpy(*(char**)& byte_5D4594[1599588], a1, 0x7FFu);
        result = 1;
    }
    else
    {
        **(_BYTE * *)& byte_5D4594[1599588] = byte_5D4594[1599608];
        result = 0;
    }
    return result;
}

//----- (00502A90) --------------------------------------------------------
int sub_502A90()
{
    return strlen(*(const char**)& byte_5D4594[1599588]) != 0 ? *(_DWORD*)& byte_5D4594[1599588] : 0;
}

//----- (00502AB0) --------------------------------------------------------
int __cdecl sub_502AB0(char* a1)
{
    int result; // eax

    if (a1)
    {
        strncpy(*(char**)& byte_5D4594[1599592], a1, 0x7FFu);
        result = 1;
    }
    else
    {
        **(_BYTE * *)& byte_5D4594[1599592] = byte_5D4594[1599612];
        result = 0;
    }
    return result;
}

//----- (00502AF0) --------------------------------------------------------
int sub_502AF0()
{
    return strlen(*(const char**)& byte_5D4594[1599592]) != 0 ? *(_DWORD*)& byte_5D4594[1599592] : 0;
}

//----- (00502B10) --------------------------------------------------------
int sub_502B10()
{
    int result; // eax
    int v1; // ebp
    int v2; // ecx
    int v3; // ebp
    char v4; // [esp+12h] [ebp-56h]
    char v5; // [esp+13h] [ebp-55h]
    int v6; // [esp+14h] [ebp-54h]
    int v7; // [esp+18h] [ebp-50h]
    int v8; // [esp+1Ch] [ebp-4Ch]
    float v9; // [esp+20h] [ebp-48h]
    float v10; // [esp+24h] [ebp-44h]
    char v11[64]; // [esp+28h] [ebp-40h]

    *(_DWORD*)& byte_5D4594[1599596] = 0;
    if (!*(_DWORD*)& byte_5D4594[1599588])
        * (_DWORD*)& byte_5D4594[1599588] = nox_malloc(0x800u);
    if (!*(_DWORD*)& byte_5D4594[1599592])
        * (_DWORD*)& byte_5D4594[1599592] = nox_malloc(0x800u);
    if (!*(_DWORD*)& byte_5D4594[1599576])
        * (_DWORD*)& byte_5D4594[1599576] = nox_malloc(0x26000u);
    result = 0;
    if (strlen(*(const char**)& byte_5D4594[1599588]))
    {
        result = sub_502DA0(*(char**)& byte_5D4594[1599588]);
        if (result)
        {
            fread(&v8, 4u, 1u, nox_file_8);
            if (v8 == -889266515)
            {
                while (1)
                {
                    v6 = 0;
                    fread(&v6, 4u, 1u, nox_file_8);
                    v1 = v6;
                    if (!v6)
                        break;
                    if (*(_DWORD*)& byte_5D4594[1599596] >= 2048)
                        goto LABEL_10;
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * *(_DWORD*)& byte_5D4594[1599596] + 72) = ftell(nox_file_8) - 4;
                    fread(&v7, 1u, 1u, nox_file_8);
                    fread(v11, (unsigned __int8)v7, 1u, nox_file_8);
                    v2 = -1 - (unsigned __int8)v7;
                    v11[(unsigned __int8)v7] = 0;
                    v3 = v2 + v1;
                    strcpy((char*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * *(_DWORD*)& byte_5D4594[1599596]), v11);
                    fread(&v4, 1u, 1u, nox_file_8);
                    fread(&v5, 1u, 1u, nox_file_8);
                    fread(&v9, 4u, 1u, nox_file_8);
                    fread(&v10, 4u, 1u, nox_file_8);
                    *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * *(_DWORD*)& byte_5D4594[1599596] + 64) = v9;
                    *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * (*(_DWORD*)& byte_5D4594[1599596])++ + 68) = v10;
                    fseek(nox_file_8, v3 - 10, 1);
                }
                sub_502DF0();
                result = 1;
            }
            else
            {
            LABEL_10:
                sub_502DF0();
                result = 0;
            }
        }
    }
    return result;
}
// 502B10: using guessed type char var_40[64];

//----- (00502D70) --------------------------------------------------------
BOOL __cdecl sub_502D70(int a1)
{
    if (a1 < 0 || a1 >= *(int*)& byte_5D4594[1599596])
        return 0;
    *(_DWORD*)& byte_5D4594[3835396] = a1;
    return sub_503830(a1) == 0;
}

//----- (00502DA0) --------------------------------------------------------
FILE* __cdecl sub_502DA0(char* a1)
{
    FILE* result; // eax

    result = nox_file_8;
    if (nox_file_8
        || (result = (FILE*)sub_426910(a1, 1, -1)) != 0
        && (result = sub_426A60(), (nox_file_8 = result) != 0))
    {
        fseek(result, 0, 0);
        result = (FILE*)1;
    }
    return result;
}

//----- (00502DF0) --------------------------------------------------------
FILE* sub_502DF0()
{
    FILE* result; // eax

    result = nox_file_8;
    if (nox_file_8)
    {
        result = sub_4269F0();
        nox_file_8 = 0;
    }
    return result;
}

//----- (00502E10) --------------------------------------------------------
FILE* __cdecl sub_502E10(int a1)
{
    if (!nox_file_8 || a1 < 0 || a1 >= *(int*)& byte_5D4594[1599596])
        return 0;
    fseek(nox_file_8, *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * a1 + 72), 0);
    return nox_file_8;
}

//----- (00502E50) --------------------------------------------------------
FILE* __cdecl sub_502E50(char* a1)
{
    FILE* result; // eax
    int v2; // eax

    result = (FILE*)a1;
    if (a1)
    {
        v2 = sub_5029A0(a1);
        result = sub_502E10(v2);
    }
    return result;
}

//----- (00502E70) --------------------------------------------------------
double __cdecl sub_502E70(int a1)
{
    double result; // st7

    if (a1 < 0 || a1 >= *(int*)& byte_5D4594[1599596])
        result = -1.0;
    else
        result = *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * a1 + 64);
    return result;
}

//----- (00502EA0) --------------------------------------------------------
double __cdecl sub_502EA0(int a1)
{
    double result; // st7

    if (a1 < 0 || a1 >= *(int*)& byte_5D4594[1599596])
        result = -1.0;
    else
        result = *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * a1 + 68);
    return result;
}

//----- (00502ED0) --------------------------------------------------------
FILE* __cdecl sub_502ED0(const char* a1)
{
    FILE* result; // eax
    int v2; // edx
    int v3; // eax
    char* v4; // edi
    unsigned __int8 v5; // cl
    FILE* v6; // edi
    FILE* v7; // ebx
    int v8; // ebp
    int v9; // ecx
    int v10; // ebp
    int v11; // [esp+Ch] [ebp-854h]
    int v12; // [esp+10h] [ebp-850h]
    int v13; // [esp+14h] [ebp-84Ch]
    int v14; // [esp+18h] [ebp-848h]
    int v15; // [esp+1Ch] [ebp-844h]
    char v16[64]; // [esp+20h] [ebp-840h]
    char v17[2048]; // [esp+60h] [ebp-800h]

    v13 = 0;
    result = (FILE*)sub_503140();
    if (result)
    {
        v2 = *(_DWORD*)& byte_587000[229712];
        strcpy(v17, (const char*)& byte_5D4594[3841580]);
        v3 = *(_DWORD*)& byte_587000[229716];
        v4 = &v17[strlen(v17)];
        *(_DWORD*)v4 = *(_DWORD*)& byte_587000[229708];
        v5 = byte_587000[229720];
        *((_DWORD*)v4 + 1) = v2;
        *((_DWORD*)v4 + 2) = v3;
        v4[12] = v5;
        result = fopen(v17, "rb");
        v6 = result;
        if (result)
        {
            result = fopen(*(const char**)& byte_5D4594[1599588], "wb");
            v7 = result;
            if (result)
            {
                fread(&v14, 4u, 1u, v6);
                if (v14 == -889266515)
                {
                    fwrite(&v14, 4u, 1u, v7);
                    while (1)
                    {
                        v12 = 0;
                        fread(&v12, 4u, 1u, v6);
                        v8 = v12;
                        if (!v12)
                            break;
                        fread(&v11, 1u, 1u, v6);
                        fread(v16, (unsigned __int8)v11, 1u, v6);
                        v9 = -1 - (unsigned __int8)v11;
                        v16[(unsigned __int8)v11] = 0;
                        v10 = v9 + v8;
                        if (!strcmp(v16, a1))
                        {
                            fseek(v6, v10, 1);
                        }
                        else
                        {
                            v13 = 1;
                            fwrite(&v12, 4u, 1u, v7);
                            fwrite(&v11, 1u, 1u, v7);
                            fwrite(v16, (unsigned __int8)v11, 1u, v7);
                            for (; v10; --v10)
                            {
                                fread(&v11, 1u, 1u, v6);
                                fwrite(&v11, 1u, 1u, v7);
                            }
                        }
                    }
                    v15 = 0;
                    fwrite(&v15, 4u, 1u, v7);
                    fclose(v6);
                    fclose(v7);
                    sub_502B10();
                    result = (FILE*)(v13 != 0);
                }
                else
                {
                    fclose(v6);
                    fclose(v7);
                    result = 0;
                }
            }
        }
    }
    return result;
}
// 502ED0: using guessed type char var_800[2048];
// 502ED0: using guessed type char var_840[64];

//----- (00503140) --------------------------------------------------------
BOOL sub_503140()
{
    BOOL result; // eax
    int v1; // edx
    int v2; // eax
    char* v3; // edi
    unsigned __int8 v4; // cl
    char NewFileName[2048]; // [esp+4h] [ebp-800h]

    sub_502DF0();
    result = 0;
    if (strlen(*(const char**)& byte_5D4594[1599588]))
    {
        result = 0;
        if (strlen((const char*)& byte_5D4594[3841580]))
        {
            v1 = *(_DWORD*)& byte_587000[229736];
            strcpy(NewFileName, (const char*)& byte_5D4594[3841580]);
            v2 = *(_DWORD*)& byte_587000[229740];
            v3 = &NewFileName[strlen(NewFileName)];
            *(_DWORD*)v3 = *(_DWORD*)& byte_587000[229732];
            v4 = byte_587000[229744];
            *((_DWORD*)v3 + 1) = v1;
            *((_DWORD*)v3 + 2) = v2;
            v3[12] = v4;
            if (remove(NewFileName) != -1 || errno != 13)
                result = rename(*(LPCSTR*)& byte_5D4594[1599588], NewFileName) != -1;
            else
                result = 0;
        }
    }
    return result;
}
// 503140: using guessed type CHAR NewFileName[2048];

//----- (00503230) --------------------------------------------------------
FILE* __cdecl sub_503230(const char* a1, char* a2)
{
    FILE* result; // eax
    int v3; // edx
    int v4; // eax
    char* v5; // edi
    unsigned __int8 v6; // cl
    FILE* v7; // ebx
    FILE* v8; // ebp
    int v9; // esi
    int v10; // edx
    int v11; // ecx
    int i; // esi
    char v13; // [esp+13h] [ebp-85Dh]
    int v14; // [esp+14h] [ebp-85Ch]
    int v15; // [esp+18h] [ebp-858h]
    int v16; // [esp+1Ch] [ebp-854h]
    int v17; // [esp+20h] [ebp-850h]
    int v18; // [esp+24h] [ebp-84Ch]
    int v19; // [esp+28h] [ebp-848h]
    int v20; // [esp+2Ch] [ebp-844h]
    char v21[64]; // [esp+30h] [ebp-840h]
    char v22[2048]; // [esp+70h] [ebp-800h]

    result = (FILE*)sub_503140();
    if (result)
    {
        v3 = *(_DWORD*)& byte_587000[229752];
        strcpy(v22, (const char*)& byte_5D4594[3841580]);
        v4 = *(_DWORD*)& byte_587000[229756];
        v5 = &v22[strlen(v22)];
        *(_DWORD*)v5 = *(_DWORD*)& byte_587000[229748];
        v6 = byte_587000[229760];
        *((_DWORD*)v5 + 1) = v3;
        *((_DWORD*)v5 + 2) = v4;
        v5[12] = v6;
        result = fopen(v22, "rb");
        v7 = result;
        if (result)
        {
            v8 = fopen(*(const char**)& byte_5D4594[1599588], "wb");
            if (v8)
            {
                fread(&v17, 4u, 1u, v7);
                fwrite(&v17, 4u, 1u, v8);
                while (1)
                {
                    fread(&v16, 4u, 1u, v7);
                    v9 = v16;
                    if (!v16)
                        break;
                    fread(&v14, 1u, 1u, v7);
                    fread(v21, (unsigned __int8)v14, 1u, v7);
                    v10 = (unsigned __int8)v14;
                    v11 = -1 - (unsigned __int8)v14;
                    v21[(unsigned __int8)v14] = 0;
                    v20 = v11 + v9;
                    if (!strcmp(v21, a1))
                    {
                        LOBYTE(v15) = strlen(a2);
                        v19 = v16 + (unsigned __int8)v15 - v10;
                        fwrite(&v19, 4u, 1u, v8);
                        fwrite(&v15, 1u, 1u, v8);
                        fwrite(a2, (unsigned __int8)v15, 1u, v8);
                    }
                    else
                    {
                        fwrite(&v16, 4u, 1u, v8);
                        fwrite(&v14, 1u, 1u, v8);
                        fwrite(v21, (unsigned __int8)v14, 1u, v8);
                    }
                    for (i = v20; i; --i)
                    {
                        fread(&v13, 1u, 1u, v7);
                        fwrite(&v13, 1u, 1u, v8);
                    }
                }
                v18 = 0;
                fwrite(&v18, 4u, 1u, v8);
                fclose(v7);
                fclose(v8);
                sub_502B10();
                result = (FILE*)1;
            }
            else
            {
                fclose(v7);
                result = 0;
            }
        }
    }
    return result;
}
// 503230: using guessed type char var_800[2048];
// 503230: using guessed type char var_840[64];

//----- (005034B0) --------------------------------------------------------
int __cdecl sub_5034B0(char* a1)
{
    int v1; // edx
    __int16 v2; // ax
    char* v3; // edi
    char* v4; // eax
    FILE* v5; // esi
    int result; // eax
    FILE* v7; // ebx
    int v8; // edi
    int v9; // edi
    int v10; // edi
    int v11; // edi
    unsigned __int8 v12; // [esp+Fh] [ebp-105Dh]
    int v13; // [esp+10h] [ebp-105Ch]
    char v14; // [esp+17h] [ebp-1055h]
    int v15; // [esp+18h] [ebp-1054h]
    int v16; // [esp+1Ch] [ebp-1050h]
    int v17; // [esp+20h] [ebp-104Ch]
    int v18; // [esp+24h] [ebp-1048h]
    int v19; // [esp+28h] [ebp-1044h]
    char v20[64]; // [esp+2Ch] [ebp-1040h]
    char v21[4096]; // [esp+6Ch] [ebp-1000h]

    v1 = *(_DWORD*)& byte_587000[229776];
    strcpy(v21, (const char*)& byte_5D4594[3841580]);
    v2 = *(_WORD*)& byte_587000[229780];
    v3 = &v21[strlen(v21)];
    *(_DWORD*)v3 = *(_DWORD*)& byte_587000[229772];
    *((_DWORD*)v3 + 1) = v1;
    *((_WORD*)v3 + 4) = v2;
    v4 = (char*)sub_502A90();
    sub_502DA0(v4);
    v5 = sub_502E50(a1);
    if (v5)
    {
        v7 = fopen(v21, "wb");
        if (v7)
        {
            fread(&v17, 4u, 1u, v5);
            v8 = v17;
            fread(&v13, 1u, 1u, v5);
            fread(v20, (unsigned __int8)v13, 1u, v5);
            v9 = -1 - (unsigned __int8)v13 + v8;
            v20[(unsigned __int8)v13] = 0;
            fread(&v14, 1u, 1u, v5);
            fread(&v12, 1u, 1u, v5);
            fread(&v19, 4u, 1u, v5);
            fread(&v18, 4u, 1u, v5);
            v10 = v9 - 10;
            if (v12 > 1u)
            {
                fread(&v16, 4u, 1u, v5);
                fseek(v5, v16, 1);
                v10 += -4 - v16;
            }
            fread(&v15, 4u, 1u, v5);
            v11 = v10 - 4;
            if (v15 == -889266515)
            {
                v15 = -1410467122;
                fwrite(&v15, 4u, 1u, v7);
                for (; v11; --v11)
                {
                    fread(&v13, 1u, 1u, v5);
                    fwrite(&v13, 1u, 1u, v7);
                }
                sub_502DF0();
                fclose(v7);
                result = 1;
            }
            else
            {
                sub_502DF0();
                fclose(v7);
                result = 0;
            }
        }
        else
        {
            sub_502DF0();
            result = 0;
        }
    }
    else
    {
        sub_502DF0();
        result = 0;
    }
    return result;
}
// 5034B0: using guessed type char var_1000[4096];
// 5034B0: using guessed type char var_1040[64];

//----- (005036D0) --------------------------------------------------------
int __cdecl sub_5036D0(char* a1, LPCSTR lpFileName)
{
    const char* v2; // edi
    char* v3; // eax
    FILE* v4; // eax
    FILE* v5; // esi
    FILE* v7; // edi
    char v8; // [esp+Bh] [ebp-55h]
    int v9; // [esp+Ch] [ebp-54h]
    int v10; // [esp+10h] [ebp-50h]
    int v11; // [esp+14h] [ebp-4Ch]
    int v12; // [esp+18h] [ebp-48h]
    int v13; // [esp+1Ch] [ebp-44h]
    char v14[64]; // [esp+20h] [ebp-40h]

    v2 = lpFileName;
    DeleteFileA(lpFileName);
    v3 = (char*)sub_502A90();
    sub_502DA0(v3);
    v4 = sub_502E50(a1);
    v5 = v4;
    if (!v4)
    {
        sub_502DF0();
        return 0;
    }
    fread(&v11, 4u, 1u, v4);
    fread(&v10, 1u, 1u, v5);
    fread(v14, (unsigned __int8)v10, 1u, v5);
    v14[(unsigned __int8)v10] = 0;
    fread(&v8, 1u, 1u, v5);
    fread(&lpFileName, 1u, 1u, v5);
    fread(&v12, 4u, 1u, v5);
    fread(&v13, 4u, 1u, v5);
    if ((unsigned __int8)lpFileName <= 1u)
        return 0;
    fread(&v9, 4u, 1u, v5);
    if (!v9)
        return 0;
    v7 = fopen(v2, "wb");
    if (!v7)
        return 0;
    for (; v9; --v9)
    {
        fread(&a1, 1u, 1u, v5);
        fwrite(&a1, 1u, 1u, v7);
    }
    sub_502DF0();
    fclose(v7);
    return 1;
}
// 5036D0: using guessed type char var_40[64];

//----- (00503830) --------------------------------------------------------
int __cdecl sub_503830(int a1)
{
    FILE* v1; // esi
    _DWORD* v2; // eax
    int v3; // esi
    unsigned __int8 v5; // [esp+Fh] [ebp-19Dh]
    int v6; // [esp+10h] [ebp-19Ch]
    char v7; // [esp+17h] [ebp-195h]
    int v8; // [esp+18h] [ebp-194h]
    int v9; // [esp+1Ch] [ebp-190h]
    int v10; // [esp+20h] [ebp-18Ch]
    int v11[8]; // [esp+24h] [ebp-188h]
    int v19[2]; // [esp+44h] [ebp-168h]
    int v21; // [esp+4Ch] [ebp-160h]
    int v22; // [esp+50h] [ebp-15Ch]
    int v23; // [esp+54h] [ebp-158h]
    char v24[4]; // [esp+58h] [ebp-154h]
    int4 v25; // [esp+5Ch] [ebp-150h]
    char v26[64]; // [esp+6Ch] [ebp-140h]
    char v27[256]; // [esp+ACh] [ebp-100h]

    if (a1 < 0)
        return 0;
    if (a1 >= *(int*)& byte_5D4594[1599596])
        return 0;
    sub_503F40();
    *(_DWORD*)& byte_5D4594[1599572] = -1;
    *(_DWORD*)& byte_5D4594[1599644] = 0;
    sub_502DA0(*(char**)& byte_5D4594[1599588]);
    if (!sub_502E10(a1))
        return 0;
    v1 = sub_426A60();
    fread(&v22, 4u, 1u, v1);
    fread(&v9, 1u, 1u, v1);
    fread(v26, (unsigned __int8)v9, 1u, v1);
    fread(&v7, 1u, 1u, v1);
    fread(&v5, 1u, 1u, v1);
    fread(&v21, 4u, 1u, v1);
    fread(&v23, 4u, 1u, v1);
    if (v5 > 1u)
    {
        fread(&v6, 4u, 1u, v1);
        fseek(v1, v6, 1);
    }
    fread(&v10, 4u, 1u, v1);
    if (v10 != -889266515)
        return 0;
    fread(v19, 4u, 1u, v1);
    fread(&v19[1], 4u, 1u, v1);
    sub_426A80(v19);
    fread(v11, 4u, 1u, v1);
    fread(&v11[1], 4u, 1u, v1);
    fread(&v11[6], 4u, 1u, v1);
    fread(&v11[7], 4u, 1u, v1);
    fread(&v11[2], 4u, 1u, v1);
    fread(&v11[3], 4u, 1u, v1);
    fread(&v11[4], 4u, 1u, v1);
    fread(&v11[5], 4u, 1u, v1);
    sub_4D3C80(v11);
    qmemcpy(&byte_5D4594[1599500], v11, 0x20u);
    sub_428170(&v11, &v25);
    sub_426A50(1);
    while (1)
    {
        v6 = 0;
        LOBYTE(v8) = 0;
        sub_426AC0(&v8, 1u);
        if (!(_BYTE)v8)
            break;
        sub_426AC0(v27, (unsigned __int8)v8);
        sub_426AC0(&v24, 4u);
        if (!sub_426EA0((int)& v11, v27, &v6))
        {
            if (v6 == 1)
                goto LABEL_15;
            v2 = sub_4E3810(v27);
            v3 = (int)v2;
            if (!v2)
                return 0;
            if (!((int(__cdecl*)(_DWORD*, int4*))v2[176])(v2, &v25))
            {
                sub_4E38A0(v3);
            LABEL_15:
                sub_502DF0();
                return 0;
            }
            sub_4F3F50(v3, 0, &v25.field_0);
        }
    }
    sub_426A50(0);
    *(_DWORD*)& byte_5D4594[1599480] = a1;
    *(_DWORD*)& byte_5D4594[1599476] = 0;
    *(_DWORD*)& byte_5D4594[3835396] = a1;
    sub_502DF0();
    return 1;
}

//----- (00503B30) --------------------------------------------------------
int __cdecl sub_503B30(float2* a1)
{
    int result; // eax
    int v2; // edi
    double v3; // st7
    float v4; // ecx
    char* v5; // eax
    char* v6; // ecx
    int v7; // eax
    int v8; // esi
    int v9; // edi
    int i; // eax
    int j; // eax
    int k; // eax
    float2 v13; // [esp+Ch] [ebp-50h]
    float2 v14; // [esp+14h] [ebp-48h]
    float2 a2; // [esp+1Ch] [ebp-40h]
    int2 v16; // [esp+24h] [ebp-38h]
    int4 v17; // [esp+2Ch] [ebp-30h]
    int v18[8]; // [esp+3Ch] [ebp-20h]

    result = sub_4D3D90(a1, &a2);
    if (result)
    {
        v2 = *(_DWORD*)& byte_5D4594[3835396];
        if (*(_DWORD*)& byte_5D4594[1599480] != *(_DWORD*)& byte_5D4594[3835396]
            || *(int*)& byte_5D4594[1599480] == -1
            || *(_DWORD*)& byte_5D4594[1599476] == 1)
        {
            result = sub_503830(*(int*)& byte_5D4594[3835396]);
            if (!result)
                return result;
            v2 = *(_DWORD*)& byte_5D4594[3835396];
        }
        v18[2] = (__int64)a2.field_0;
        v18[3] = (__int64)a2.field_4;
        v13.field_0 = *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * v2 + 64) + a1->field_0;
        v13.field_4 = *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * v2 + 68) + a1->field_4;
        sub_4D3D90(&v13, &v14);
        v18[4] = (__int64)v14.field_0;
        v18[5] = (__int64)v14.field_4;
        v3 = *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * *(_DWORD*)& byte_5D4594[3835396] + 64) + a1->field_0;
        v13.field_4 = a1->field_4;
        v13.field_0 = v3;
        sub_4D3D90(&v13, &v14);
        v18[0] = (__int64)v14.field_0;
        v4 = a1->field_0;
        v18[1] = (__int64)v14.field_4;
        v13.field_0 = v4;
        v13.field_4 = *(float*)(*(_DWORD*)& byte_5D4594[1599576] + 76 * *(_DWORD*)& byte_5D4594[3835396] + 68)
            + a1->field_4;
        sub_4D3D90(&v13, &v14);
        v18[6] = (__int64)v14.field_0;
        v18[7] = (__int64)v14.field_4;
        sub_4D3C80(v18);
        sub_428170(v18, &v17);
        v5 = sub_426A70();
        v6 = v5;
        v7 = *(_DWORD*)v5;
        *(_DWORD*)& byte_5D4594[1599484] = v7;
        *(_DWORD*)& byte_5D4594[1599488] = *((_DWORD*)v6 + 1);
        *(float*)& byte_5D4594[1599492] = (double)(23 * v7);
        *(float*)& byte_5D4594[1599496] = (double)(int)(23 * *(_DWORD*)& byte_5D4594[1599488]);
        v8 = (__int64)(a2.field_0 - (double) * (int*)& byte_5D4594[1599508]);
        v9 = (__int64)(a2.field_4 - (double) * (int*)& byte_5D4594[1599512]);
        result = sub_504150(v8, v9);
        if (result)
        {
            result = sub_504330(v8, v9);
            if (result)
            {
                result = sub_504560(v8, v9);
                if (result)
                {
                    result = sub_504910(v8, v9);
                    if (result)
                    {
                        sub_579D20();
                        for (i = sub_579890(); i; i = sub_5798A0(i))
                            * (_DWORD*)(i + 480) |= 0x80000000;
                        *(_DWORD*)& byte_5D4594[3835392] = sub_4D0010(&v17, *(int*)& byte_5D4594[3835392]);
                        result = sub_504720(v8, v9);
                        if (result)
                        {
                            for (j = sub_579890(); j; j = sub_5798A0(j))
                                * (_DWORD*)(j + 4) = 0;
                            for (k = sub_4DA870(); k; k = sub_4DA880(k))
                                * (_DWORD*)(k + 44) = 0;
                            sub_5799C0();
                            sub_4DB030();
                            *(_DWORD*)& byte_5D4594[1599476] = 1;
                            if (*(_DWORD*)& byte_5D4594[1599644])
                            {
                                ++* (_DWORD*)& byte_5D4594[3835308];
                                sub_542BF0(*(int*)& byte_5D4594[3835312], v8, v9);
                                v16.field_0 = v8;
                                v16.field_4 = v9;
                                sub_543110((LPCSTR)& byte_5D4594[3830188], &v16);
                                if (*(_DWORD*)& byte_5D4594[1599580])
                                {
                                    remove((LPCSTR)& byte_5D4594[3835436]);
                                    rename((LPCSTR)& byte_5D4594[3837484], (LPCSTR)& byte_5D4594[3835436]);
                                    sub_541670(
                                        (LPCSTR)& byte_5D4594[3835436],
                                        (LPCSTR)& byte_5D4594[3830188],
                                        (LPCSTR)& byte_5D4594[3837484]);
                                }
                                else
                                {
                                    *(_DWORD*)& byte_5D4594[1599580] = 1;
                                    rename((LPCSTR)& byte_5D4594[3830188], (LPCSTR)& byte_5D4594[3837484]);
                                }
                            }
                            ++* (_DWORD*)& byte_5D4594[3835312];
                            result = 1;
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (00503EC0) --------------------------------------------------------
int __cdecl sub_503EC0(int a1, float* a2)
{
    float2 a1a; // [esp+0h] [ebp-18h]
    float2 v4; // [esp+8h] [ebp-10h]
    float2 a2a; // [esp+10h] [ebp-8h]

    if (*(_DWORD*)& byte_5D4594[1599480] != *(_DWORD*)& byte_5D4594[3835396]
        || *(int*)& byte_5D4594[1599480] == -1
        || *(_DWORD*)& byte_5D4594[1599476] == 1)
    {
        return 0;
    }
    a1a.field_0 = (double) * (int*)& byte_5D4594[1599508];
    a1a.field_4 = (double) * (int*)& byte_5D4594[1599512];
    sub_4D3E30(&a1a, &a2a);
    sub_4D3E30((float2*)(a1 + 56), &v4);
    *a2 = v4.field_0 - a2a.field_0;
    a2[1] = v4.field_4 - a2a.field_4;
    return 1;
}

//----- (00503F40) --------------------------------------------------------
char* sub_503F40()
{
    int* v0; // esi
    int* v1; // edi
    int v2; // esi
    int v3; // edi
    LPVOID* v4; // edi
    LPVOID* v5; // ebx
    int v6; // eax
    int v7; // esi
    LPVOID* v8; // esi
    LPVOID* v9; // edi
    _QWORD** v10; // edi
    _QWORD** v11; // ebx
    int v12; // eax
    int v13; // esi

    v0 = *(int**)& byte_5D4594[1599540];
    if (*(_DWORD*)& byte_5D4594[1599540])
    {
        do
        {
            v1 = (int*)v0[1];
            if (!*(_DWORD*)& byte_5D4594[1599476])
                sub_4E38A0(*v0);
            free(v0);
            v0 = v1;
        } while (v1);
    }
    v2 = *(_DWORD*)& byte_5D4594[1599548];
    if (*(_DWORD*)& byte_5D4594[1599548])
    {
        do
        {
            v3 = *(_DWORD*)(v2 + 4);
            if (!*(_DWORD*)& byte_5D4594[1599476])
                free(*(LPVOID*)v2);
            free((LPVOID)v2);
            v2 = v3;
        } while (v3);
    }
    v4 = *(LPVOID * *)& byte_5D4594[1599556];
    if (*(_DWORD*)& byte_5D4594[1599556])
    {
        do
        {
            v5 = (LPVOID*)v4[4];
            v6 = *((_DWORD*)* v4 + 4);
            if (v6)
            {
                do
                {
                    v7 = *(_DWORD*)(v6 + 16);
                    sub_4221E0(v6);
                    v6 = v7;
                } while (v7);
            }
            free(*v4);
            free(v4);
            v4 = v5;
        } while (v5);
    }
    v8 = *(LPVOID * *)& byte_5D4594[1599532];
    if (*(_DWORD*)& byte_5D4594[1599532])
    {
        do
        {
            v9 = (LPVOID*)v8[1];
            if (!*(_DWORD*)& byte_5D4594[1599476] && *((_BYTE*)* v8 + 4) & 4)
                free(*((LPVOID*)* v8 + 7));
            free(*v8);
            free(v8);
            v8 = v9;
        } while (v9);
    }
    v10 = *(_QWORD * **)& byte_5D4594[1599564];
    if (*(_DWORD*)& byte_5D4594[1599564])
    {
        do
        {
            v11 = (_QWORD * *)v10[1];
            if (*(_DWORD*)& byte_5D4594[1599476])
            {
                free(v10);
            }
            else
            {
                v12 = *((_DWORD*)* v10 + 21);
                if (v12)
                {
                    do
                    {
                        v13 = *(_DWORD*)(v12 + 8);
                        sub_57C390((_QWORD*)v12);
                        v12 = v13;
                    } while (v13);
                }
                sub_57C370(*v10);
                free(v10);
            }
            v10 = v11;
        } while (v11);
    }
    *(_DWORD*)& byte_5D4594[1599568] = 0;
    *(_DWORD*)& byte_5D4594[1599564] = 0;
    return sub_5028E0();
}

//----- (005040A0) --------------------------------------------------------
_DWORD* __cdecl sub_5040A0(int a1, int a2, float a3)
{
    _DWORD* result; // eax
    _DWORD* v4; // esi
    void* v5; // eax
    double v6; // st7
    bool v7; // zf
    float v8; // [esp+10h] [ebp+Ch]

    result = nox_malloc(0x18u);
    v4 = result;
    if (result)
    {
        v5 = nox_malloc(0x14u);
        *v4 = v5;
        if (v5)
        {
            v4[5] = 0;
            v4[4] = *(_DWORD*)& byte_5D4594[1599556];
            if (*(_DWORD*)& byte_5D4594[1599556])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599556] + 20) = v4;
            *(_DWORD*)& byte_5D4594[1599556] = v4;
            v6 = (double)a1 * 46.0;
            ++* (_DWORD*)& byte_5D4594[1599560];
            v7 = LOBYTE(a3) == 1;
            *((_BYTE*)v4 + 12) = LOBYTE(a3);
            *((float*)v4 + 1) = v6;
            v8 = (double)a2 * 46.0;
            *((float*)v4 + 2) = v8;
            result = v4;
            if (v7)
                * ((float*)v4 + 1) = v6 + 23.0;
            else
                *((float*)v4 + 2) = v8 + 23.0;
        }
        else
        {
            free(v4);
            result = 0;
        }
    }
    return result;
}

//----- (00504150) --------------------------------------------------------
int __cdecl sub_504150(int a1, int a2)
{
    int v2; // eax
    const char* v3; // edx
    int v5; // edi
    int* i; // esi
    float2 a1a; // [esp+Ch] [ebp-50h]
    char v8[72]; // [esp+14h] [ebp-48h]
    float v9; // [esp+60h] [ebp+4h]
    float v10; // [esp+64h] [ebp+8h]

    if (*(int*)& byte_587000[229704] == -1)
    {
        v2 = 0;
        if (*(int*)& byte_5D4594[251568] > 0)
        {
            v3 = (const char*)& byte_5D4594[2682188];
            while (strcmp(v3, "TransparentFloor"))
            {
                ++v2;
                v3 += 60;
                if (v2 >= *(int*)& byte_5D4594[251568])
                    goto LABEL_8;
            }
            *(_DWORD*)& byte_587000[229704] = v2;
        LABEL_8:
            if (v2 == -1)
                return 0;
        }
    }
    qmemcpy(v8, sub_4D3C70(), sizeof(v8));
    v5 = *(_DWORD*)& byte_5D4594[1599556];
    if (*(_DWORD*)& byte_5D4594[1599556])
    {
        v9 = (double)a1;
        v10 = (double)a2;
        do
        {
            a1a.field_0 = v9 + *(float*)(v5 + 4);
            a1a.field_4 = v10 + *(float*)(v5 + 8);
            sub_51D540(**(_DWORD * *)v5);
            sub_51D570(*(_DWORD*)(*(_DWORD*)v5 + 4));
            sub_51D5C0(1);
            if (**(_DWORD * *)v5 != *(_DWORD*)& byte_587000[229704])
                sub_51D8F0(&a1a);
            for (i = *(int**)(*(_DWORD*)v5 + 16); i; i = (int*)i[4])
            {
                sub_544070(i[2]);
                sub_5440A0(i[3]);
                sub_51D540(*i);
                sub_51D570(i[1]);
                sub_544310(&a1a);
            }
            v5 = *(_DWORD*)(v5 + 16);
        } while (v5);
    }
    sub_4D3C50(v8);
    return 1;
}

//----- (00504290) --------------------------------------------------------
_DWORD* __cdecl sub_504290(char a1, char a2)
{
    _DWORD* result; // eax
    _DWORD* v3; // esi
    _BYTE* v4; // eax

    result = nox_malloc(0xCu);
    v3 = result;
    if (result)
    {
        result[2] = 0;
        result[1] = *(_DWORD*)& byte_5D4594[1599532];
        if (*(_DWORD*)& byte_5D4594[1599532])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599532] + 8) = result;
        *(_DWORD*)& byte_5D4594[1599532] = result;
        v4 = nox_calloc(1u, 0x24u);
        *v3 = v4;
        v4[5] = a1;
        *(_BYTE*)(*v3 + 6) = a2;
        result = v3;
    }
    return result;
}

//----- (005042F0) --------------------------------------------------------
_DWORD* __cdecl sub_5042F0(int a1, int a2)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1599532];
    if (!*(_DWORD*)& byte_5D4594[1599532])
        return 0;
    while (*(unsigned __int8*)(*result + 5) != a1 || *(unsigned __int8*)(*result + 6) != a2)
    {
        result = (_DWORD*)result[1];
        if (!result)
            return 0;
    }
    return result;
}

//----- (00504330) --------------------------------------------------------
int __cdecl sub_504330(int a1, int a2)
{
    unsigned __int8** v2; // edi
    int v3; // ebp
    int v4; // ecx
    int v6; // ebx
    unsigned __int8* v7; // esi
    unsigned __int8 v8; // dl
    unsigned __int8 v9; // al
    _DWORD* v11; // [esp-4h] [ebp-14h]
    int v12; // [esp-4h] [ebp-14h]

    v2 = *(unsigned __int8***)& byte_5D4594[1599532];
    if (!*(_DWORD*)& byte_5D4594[1599532])
        return 1;
    while (1)
    {
        v3 = (a1 + 23 * (*v2)[5]) / 23;
        v4 = a2 + 23 * (*v2)[6];
        v6 = v4 / 23;
        v7 = (unsigned __int8*)sub_410580(v3, v6);
        if (v7)
        {
            v8 = **v2;
            if (*(_DWORD*)& byte_5D4594[3835368])
                * v7 = sub_42A6C0(*v7, v8);
            else
                *v7 = v8;
            goto LABEL_8;
        }
        v7 = (unsigned __int8*)sub_410250(v3, v6);
        if (!v7)
            return 0;
        *v7 = **v2;
    LABEL_8:
        v7[1] = (*v2)[1];
        v7[2] = (*v2)[2];
        v7[7] = (*v2)[7];
        if (((*v2)[4] & 0x80u) != 0)
            v7[4] |= 0x80u;
        if (v7[2] >= sub_410DD0(v7[1], *v7, 0))
            v7[2] = 0;
        if (v7[4] & 4)
            sub_4107A0(*((LPVOID*)v7 + 7));
        if ((*v2)[4] & 4)
        {
            v7[4] |= 4u;
            v11 = (_DWORD*) * ((_DWORD*)* v2 + 7);
            *((_DWORD*)v7 + 7) = v11;
            sub_410760(v11);
        }
        if ((*v2)[4] & 8)
        {
            v9 = v7[4];
            if (!(v9 & 8))
            {
                v12 = *((_DWORD*)v7 + 7);
                v7[4] = v9 | 8;
                sub_410840(v12);
            }
        }
        if ((*v2)[4] & 0x40)
            v7[4] |= 0x40u;
        v2 = (unsigned __int8**)v2[1];
        if (!v2)
            return 1;
    }
}

//----- (005044B0) --------------------------------------------------------
_DWORD* __cdecl sub_5044B0(int a1, float a2, float a3)
{
    _DWORD* result; // eax
    _DWORD* v4; // esi
    _DWORD* v5; // eax
    _DWORD* v6; // eax

    result = nox_malloc(0xCu);
    v4 = result;
    if (result)
    {
        v5 = sub_579E70();
        *v4 = v5;
        if (v5)
        {
            v4[2] = 0;
            v4[1] = *(_DWORD*)& byte_5D4594[1599548];
            if (*(_DWORD*)& byte_5D4594[1599548])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599548] + 8) = v4;
            *(_DWORD*)& byte_5D4594[1599548] = v4;
            *(_DWORD*)* v4 = a1;
            *(float*)(*v4 + 8) = a2;
            *(float*)(*v4 + 12) = a3;
            *(_DWORD*)(*v4 + 488) = 0;
            v6 = (_DWORD*)v4[1];
            if (v6)
            {
                *(_DWORD*)(*v4 + 484) = *v6;
                *(_DWORD*)(*(_DWORD*)v4[1] + 488) = *v4;
                result = v4;
            }
            else
            {
                result = v4;
                *(_DWORD*)(*v4 + 484) = 0;
            }
        }
        else
        {
            free(v4);
            result = 0;
        }
    }
    return result;
}

//----- (00504560) --------------------------------------------------------
int __cdecl sub_504560(int a1, int a2)
{
    int* v2; // esi
    float v4; // [esp+8h] [ebp+4h]
    float v5; // [esp+Ch] [ebp+8h]

    v2 = *(int**)& byte_5D4594[1599548];
    if (*(_DWORD*)& byte_5D4594[1599548])
    {
        v4 = (double)a1;
        v5 = (double)a2;
        do
        {
            *(float*)(*v2 + 8) = v4 + *(float*)(*v2 + 8);
            *(float*)(*v2 + 12) = v5 + *(float*)(*v2 + 12);
            sub_579E90(*v2);
            v2 = (int*)v2[1];
        } while (v2);
    }
    return 1;
}

//----- (005045B0) --------------------------------------------------------
int sub_5045B0()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1599480] == *(_DWORD*)& byte_5D4594[3835396]
        && *(int*)& byte_5D4594[1599480] != -1
        && *(_DWORD*)& byte_5D4594[1599476] != 1
        || (result = sub_503830(*(int*)& byte_5D4594[3835396])) != 0)
    {
        result = **(_DWORD * *)& byte_5D4594[1599548];
    }
    return result;
}

//----- (005045F0) --------------------------------------------------------
int __cdecl sub_5045F0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(a1 + 484);
    return result;
}

//----- (00504600) --------------------------------------------------------
_DWORD* __cdecl sub_504600(const char* a1, int a2, char a3)
{
    _DWORD* v3; // ebx
    _DWORD* result; // eax
    void* v5; // eax
    char* v6; // edx
    unsigned int v7; // ecx
    char v8; // al
    char* v9; // edi
    const char* v10; // esi

    v3 = nox_malloc(0xCu);
    if (!v3)
        return 0;
    v5 = sub_57C330();
    *v3 = v5;
    if (!v5)
        return 0;
    v3[2] = 0;
    v3[1] = *(_DWORD*)& byte_5D4594[1599564];
    if (*(_DWORD*)& byte_5D4594[1599564])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599564] + 8) = v3;
    *(_DWORD*)& byte_5D4594[1599564] = v3;
    *(_DWORD*)(*v3 + 88) = 0;
    *(_DWORD*)(*v3 + 92) = 0;
    *(_DWORD*)(*v3 + 84) = 0;
    *(_DWORD*)(*v3 + 4) = a2;
    *(_BYTE*)* v3 = a3;
    v6 = (char*)(*v3 + 8);
    v7 = strlen(a1) + 1;
    v8 = v7;
    v7 >>= 2;
    qmemcpy(v6, a1, 4 * v7);
    v10 = &a1[4 * v7];
    v9 = &v6[4 * v7];
    LOBYTE(v7) = v8;
    result = v3;
    qmemcpy(v9, v10, v7 & 3);
    return result;
}

//----- (005046A0) --------------------------------------------------------
int __cdecl sub_5046A0(_DWORD* a1, int a2)
{
    char** v2; // esi
    _DWORD* v4; // eax
    char v5; // cl
    int v6; // ecx

    v2 = *(char***)& byte_5D4594[1599564];
    if (!*(_DWORD*)& byte_5D4594[1599564])
        return 0;
    while (*((_DWORD*)* v2 + 1) != a2)
    {
        v2 = (char**)v2[1];
        if (!v2)
            return 0;
    }
    v4 = sub_57C360();
    if (!v4)
        return 0;
    v5 = **v2;
    if (!v5 || v5 == 1 || v5 == 3)
    {
        *v4 = *a1;
        goto LABEL_12;
    }
    if (v5 != 2)
        return 0;
    *v4 = *a1;
    v4[1] = a1[1];
LABEL_12:
    v4[3] = 0;
    v4[2] = *((_DWORD*)* v2 + 21);
    v6 = *((_DWORD*)* v2 + 21);
    if (v6)
        * (_DWORD*)(v6 + 12) = v4;
    *((_DWORD*)* v2 + 21) = v4;
    return 1;
}

//----- (00504720) --------------------------------------------------------
int __cdecl sub_504720(int a1, int a2)
{
    int* v2; // esi

    sub_504760(a1, a2);
    v2 = *(int**)& byte_5D4594[1599564];
    if (*(_DWORD*)& byte_5D4594[1599564])
    {
        do
        {
            sub_57C3B0(*v2);
            v2 = (int*)v2[1];
        } while (v2);
    }
    return 1;
}

//----- (00504760) --------------------------------------------------------
int __cdecl sub_504760(int a1, int a2)
{
    int result; // eax
    char** v3; // ebp
    char v4; // bl
    int* v5; // esi
    int v6; // eax
    int v7; // ecx
    int v8; // [esp+4h] [ebp-50h]
    char v9[76]; // [esp+8h] [ebp-4Ch]

    result = sub_57BF80();
    v3 = *(char***)& byte_5D4594[1599564];
    v8 = result;
    if (*(_DWORD*)& byte_5D4594[1599564])
    {
        while (1)
        {
            v4 = **v3;
            nox_sprintf(v9, "%s%%%d", *v3 + 8, *(_DWORD*)& byte_5D4594[3835312]);
            strcpy(*v3 + 8, v9);
            result = (int)* v3;
            *((_DWORD*)* v3 + 1) += v8;
            v5 = (int*) * ((_DWORD*)* v3 + 21);
            if (v5)
                break;
        LABEL_15:
            v3 = (char**)v3[1];
            if (!v3)
                return result;
        }
        while (1)
        {
            if (v4)
            {
                switch (v4)
                {
                case 1:
                    result = sub_579C60(*v5);
                    if (result)
                        * v5 = *(_DWORD*)result;
                    break;
                case 2:
                    v6 = v5[1];
                    *v5 = (a1 + 23 * *v5) / 23;
                    v7 = a2 + 23 * v6;
                    result = -1307163959 * v7;
                    v5[1] = v7 / 23;
                    break;
                case 3:
                    result = v8 + *v5;
                    goto LABEL_13;
                }
            }
            else
            {
                result = sub_4CFFE0(*v5);
                if (result)
                {
                    result = *(_DWORD*)(result + 40);
                LABEL_13:
                    *v5 = result;
                    goto LABEL_14;
                }
            }
        LABEL_14:
            v5 = (int*)v5[2];
            if (!v5)
                goto LABEL_15;
        }
    }
    return result;
}

//----- (005048A0) --------------------------------------------------------
_DWORD* __cdecl sub_5048A0(int a1)
{
    _DWORD* result; // eax
    _DWORD* v2; // ecx

    result = nox_malloc(0xCu);
    if (!result)
        return 0;
    result[2] = 0;
    *result = a1;
    result[1] = *(_DWORD*)& byte_5D4594[1599540];
    if (*(_DWORD*)& byte_5D4594[1599540])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599540] + 8) = result;
    *(_DWORD*)& byte_5D4594[1599540] = result;
    *(_DWORD*)(*result + 448) = 0;
    v2 = (_DWORD*)result[1];
    if (v2)
    {
        *(_DWORD*)(*result + 444) = *v2;
        *(_DWORD*)(*(_DWORD*)result[1] + 448) = *result;
    }
    else
    {
        *(_DWORD*)(*result + 444) = 0;
    }
    return result;
}

//----- (00504910) --------------------------------------------------------
int __cdecl sub_504910(int a1, int a2)
{
    int* v2; // esi
    float v4; // [esp+8h] [ebp+4h]
    float v5; // [esp+Ch] [ebp+8h]

    v2 = *(int**)& byte_5D4594[1599540];
    if (*(_DWORD*)& byte_5D4594[1599540])
    {
        v4 = (double)a1;
        v5 = (double)a2;
        do
        {
            *(float*)(*v2 + 56) = v4 + *(float*)(*v2 + 56);
            *(float*)(*v2 + 60) = v5 + *(float*)(*v2 + 60);
            sub_4DAA50(*v2, 0, *(float*)(*v2 + 56), *(float*)(*v2 + 60));
            *(_DWORD*)(*v2 + 16) |= 0x80000000;
            v2 = (int*)v2[1];
        } while (v2);
    }
    return 1;
}

//----- (00504980) --------------------------------------------------------
int sub_504980()
{
    int result; // eax

    if ((*(_DWORD*)& byte_5D4594[1599480] == *(_DWORD*)& byte_5D4594[3835396]
        && *(int*)& byte_5D4594[1599480] != -1
        && *(_DWORD*)& byte_5D4594[1599476] != 1
        || sub_503830(*(int*)& byte_5D4594[3835396]))
        && *(_DWORD*)& byte_5D4594[1599540])
    {
        result = **(_DWORD * *)& byte_5D4594[1599540];
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (005049C0) --------------------------------------------------------
int __cdecl sub_5049C0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(a1 + 444);
    return result;
}

//----- (005049D0) --------------------------------------------------------
LPVOID sub_5049D0()
{
    return *(LPVOID*)& byte_5D4594[1599540];
}

//----- (005049E0) --------------------------------------------------------
int __cdecl sub_5049E0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(a1 + 4);
    return result;
}

//----- (005049F0) --------------------------------------------------------
int __cdecl sub_5049F0(FILE* a1, int a2)
{
    return fseek(a1, a2, 1);
}

//----- (00504A10) --------------------------------------------------------
int __cdecl sub_504A10(int a1)
{
    int* v1; // esi
    int v3; // eax
    int v4; // eax
    int v5; // ecx
    int v6; // ecx

    if (!a1)
        return 0;
    v1 = *(int**)& byte_5D4594[1599540];
    if (!*(_DWORD*)& byte_5D4594[1599540])
        return 0;
    while (*v1 != a1)
    {
        v1 = (int*)v1[1];
        if (!v1)
            return 0;
    }
    v3 = v1[1];
    if (v3)
        * (_DWORD*)(v3 + 8) = v1[2];
    v4 = v1[2];
    if (v4)
        * (_DWORD*)(v4 + 4) = v1[1];
    if (v1 == *(int**)& byte_5D4594[1599540])
        * (_DWORD*)& byte_5D4594[1599540] = v1[1];
    v5 = *(_DWORD*)(*v1 + 444);
    if (v5)
        * (_DWORD*)(v5 + 448) = *(_DWORD*)(*v1 + 448);
    v6 = *(_DWORD*)(*v1 + 448);
    if (v6)
        * (_DWORD*)(v6 + 444) = *(_DWORD*)(*v1 + 444);
    sub_4E38A0(*v1);
    free(v1);
    return 1;
}

//----- (00504AB0) --------------------------------------------------------
int __cdecl sub_504AB0(char* a1)
{
    char* v1; // eax
    const char* v2; // eax
    FILE* v3; // ebp
    int result; // eax
    FILE* v5; // esi
    int v6; // edi
    int v7; // edi
    char v8; // [esp+Fh] [ebp-851h]
    int v9; // [esp+10h] [ebp-850h]
    int v10; // [esp+14h] [ebp-84Ch]
    int v11; // [esp+18h] [ebp-848h]
    int v12; // [esp+1Ch] [ebp-844h]
    char v13[64]; // [esp+20h] [ebp-840h]
    char v14[2048]; // [esp+60h] [ebp-800h]

    v12 = 0;
    strcpy(v14, (const char*)sub_502A90());
    sub_502DF0();
    v1 = (char*)sub_502AF0();
    sub_502A50(v1);
    sub_502B10();
    v2 = (const char*)sub_502A90();
    v3 = fopen(v2, "r+b");
    if (v3)
    {
        v5 = fopen(a1, "rb");
        if (v5)
        {
            fseek(v3, -4, 2);
            fread(&v11, 4u, 1u, v5);
            if (v11 == -889266515)
            {
                while (1)
                {
                    fread(&v10, 4u, 1u, v5);
                    v6 = v10;
                    if (!v10)
                        break;
                    fread(&v9, 1u, 1u, v5);
                    fread(v13, (unsigned __int8)v9, 1u, v5);
                    v7 = -1 - (unsigned __int8)v9 + v6;
                    v13[(unsigned __int8)v9] = 0;
                    if (sub_5029A0(v13) == -1)
                    {
                        fwrite(&v10, 4u, 1u, v3);
                        fwrite(&v9, 1u, 1u, v3);
                        fwrite(v13, (unsigned __int8)v9, 1u, v3);
                        for (; v7; --v7)
                        {
                            fread(&v8, 1u, 1u, v5);
                            fwrite(&v8, 1u, 1u, v3);
                        }
                    }
                    else
                    {
                        fseek(v5, v7, 1);
                    }
                }
                fwrite(&v12, 4u, 1u, v3);
                fclose(v3);
                fclose(v5);
                sub_502A50(v14);
                sub_502B10();
                result = 1;
            }
            else
            {
                fclose(v3);
                fclose(v5);
                sub_502A50(v14);
                sub_502B10();
                result = 0;
            }
        }
        else
        {
            fclose(v3);
            sub_502A50(v14);
            sub_502B10();
            result = 0;
        }
    }
    else
    {
        sub_502A50(v14);
        sub_502B10();
        result = 0;
    }
    return result;
}
// 504AB0: using guessed type char var_840[64];

//----- (00504CF0) --------------------------------------------------------
int __cdecl sub_504CF0(_DWORD* a2)
{
    int result; // eax
    int i; // esi
    int j; // esi
    int v4; // eax
    float v5; // ecx
    int v6; // eax
    _DWORD* v7; // ebp
    unsigned __int16 v8; // ax
    _DWORD* v9; // eax
    _DWORD* v10; // edi
    int v11; // ebx
    int v12; // [esp+10h] [ebp-24h]
    int v13; // [esp+14h] [ebp-20h]
    int v14; // [esp+18h] [ebp-1Ch]
    int2 a1; // [esp+1Ch] [ebp-18h]
    int4 v16; // [esp+24h] [ebp-10h]

    v13 = 1;
    sub_426AC0(&v13, 2u);
    if ((__int16)v13 > 1)
        return 0;
    if (a2)
        sub_428170(a2, &v16);
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&v12, 2u);
        if ((_WORD)v12)
        {
            v7 = a2;
            while (1)
            {
                sub_426C20(&a1, 4u);
                v8 = sub_42C2B0(v12);
                v9 = sub_4E3450(v8);
                v10 = v9;
                if (!v9)
                    break;
                v11 = 0;
                if (!((int(__cdecl*)(_DWORD*, unsigned int))v9[176])(v9, a2 != 0 ? (unsigned int)& v16 : 0))
                    break;
                if (v10[4] & 0x400000)
                {
                    v7 = (_DWORD*)v10[32];
                    v11 = 1;
                }
                if (sub_4F3F50((int)v10, 0, (int*)(a2 != 0 ? (unsigned int)& v16 : 0)) == 1 && v11 == 1)
                    sub_511660(v10, (int)v7);
                sub_426AC0(&v12, 2u);
                if (!(_WORD)v12)
                    return 1;
            }
            sub_4269F0();
            return 0;
        }
        return 1;
    }
    for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
    {
        if (!a2
            || (a1.field_0 = sub_419A70(*(float*)(i + 56)), a1.field_4 = sub_419A70(*(float*)(i + 60)), sub_4280E0(&a1, a2)))
        {
            if (sub_4E3B80(*(unsigned __int16*)(i + 4)) && !sub_51DF90(i))
                return 0;
        }
    }
    for (j = sub_4DA840(); j; j = sub_4DA850(j))
    {
        if (a2)
        {
            v4 = sub_419A70(*(float*)(j + 56));
            v5 = *(float*)(j + 60);
            a1.field_0 = v4;
            a1.field_4 = sub_419A70(v5);
            if (!sub_4280E0(&a1, a2))
                continue;
        }
        if (*(_DWORD*)(j + 8) & 0x1000000 && *(_BYTE*)(j + 12) & 0x40)
        {
            v6 = sub_4E7980(j);
            *(_DWORD*)(v6 + 56) = *(_DWORD*)(j + 56);
            *(_DWORD*)(v6 + 60) = *(_DWORD*)(j + 60);
            sub_51DF90(v6);
        }
        else if (sub_4E3B80(*(unsigned __int16*)(j + 4)) && !sub_51DF90(j))
        {
            return 0;
        }
    }
    if (sub_40A5C0(0x200000) || !sub_40A5C0(1) || sub_40A5C0(0x400000) || (result = sub_51DED0()) != 0)
    {
        v14 = 0;
        sub_426AC0(&v14, 2u);
        return 1;
    }
    return result;
}

//----- (00504F90) --------------------------------------------------------
int sub_504F90()
{
    int result; // eax
    char v1; // [esp+3h] [ebp-5h]
    int v2; // [esp+4h] [ebp-4h]

    v2 = 1;
    sub_426AC0(&v2, 2u);
    if ((__int16)v2 > 1)
        return 0;
    v1 = 0;
    if (*(_DWORD*)& byte_5D4594[1599636] && sub_40A5C0(1) && !sub_40A5C0(0x400000))
        v1 = 1;
    sub_426AC0(&v1, 1u);
    if (!v1)
        return 1;
    sub_426AC0(*(_BYTE * *)(*(_DWORD*)& byte_5D4594[1599636] + 76), 4 * *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 64));
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        result = sub_51AF80();
        if (!result)
            return result;
        return 1;
    }
    result = sub_51AEA0();
    if (result)
        return 1;
    return result;
}

//----- (00505050) --------------------------------------------------------
LPVOID sub_505050()
{
    return *(LPVOID*)& byte_5D4594[1599616];
}

//----- (00505060) --------------------------------------------------------
LPVOID sub_505060()
{
    LPVOID result; // eax

    result = *(LPVOID*)& byte_5D4594[1599616];
    if (*(_DWORD*)& byte_5D4594[1599616])
    {
        free(*(LPVOID*)& byte_5D4594[1599616]);
        *(_DWORD*)& byte_5D4594[1599616] = 0;
    }
    return result;
}

//----- (00505080) --------------------------------------------------------
int sub_505080()
{
    FILE* v0; // ebx
    BOOL v1; // ebp
    char* v2; // edi
    __int16 v3; // dx
    unsigned __int8 v4; // al
    char* v5; // edi
    char* v6; // edi
    unsigned __int8 v7; // cl
    __int16 v8; // si
    int v9; // edi
    FILE* v10; // eax
    FILE* v11; // esi
    int result; // eax
    _BYTE* v13; // eax
    _BYTE* v14; // edi
    int i; // esi
    char v16; // [esp+13h] [ebp-409h]
    size_t v17; // [esp+14h] [ebp-408h]
    int v18; // [esp+18h] [ebp-404h]
    char v19[1024]; // [esp+1Ch] [ebp-400h]

    v0 = 0;
    v18 = 1;
    v17 = 0;
    v1 = sub_40A5C0(0x200000);
    sub_505060();
    v2 = sub_409E10();
    v3 = *(_WORD*)& byte_587000[229832];
    strcpy(v19, v2);
    v4 = byte_587000[229834];
    v5 = &v19[strlen(v19)];
    *(_DWORD*)v5 = *(_DWORD*)& byte_587000[229828];
    *((_WORD*)v5 + 2) = v3;
    v5[6] = v4;
    strcat(v19, sub_409B40());
    *(_WORD*)& v19[strlen(v19)] = *(_WORD*)& byte_587000[229836];
    strcat(v19, sub_409B40());
    v6 = &v19[strlen(v19) + 1];
    v7 = byte_587000[229844];
    v8 = v18;
    *(_DWORD*)--v6 = *(_DWORD*)& byte_587000[229840];
    v6[4] = v7;
    sub_426AC0(&v18, 2u);
    if (v8 > (__int16)v18)
        return 0;
    v9 = 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            sub_426AC0(&v17, 4u);
            if ((int)v17 <= 0)
                return 1;
            if (sub_40A5C0(0x400000))
            {
                sub_426AA0(v17);
                return 1;
            }
            if (v1)
            {
                v0 = fopen(v19, "wb");
                if (v0)
                {
                    v14 = (_BYTE*)v18;
                    goto LABEL_18;
                }
            }
            else
            {
                v13 = nox_malloc(v17);
                *(_DWORD*)& byte_5D4594[1599616] = v13;
                if (v13)
                {
                    v14 = v13;
                LABEL_18:
                    for (i = 0; i < (int)v17; ++i)
                    {
                        sub_426AC0(&v16, 1u);
                        if (v1)
                            fwrite(&v16, 1u, 1u, v0);
                        else
                            *v14++ = v16;
                    }
                    if (v0)
                        fclose(v0);
                    return 1;
                }
            }
        }
        return 0;
    }
    if (v1 && (v10 = fopen(v19, "rb"), (v11 = v10) != 0))
    {
        fseek(v10, 0, 2);
        v17 = ftell(v11);
        fseek(v11, 0, 0);
        sub_426AC0(&v17, 4u);
        if ((int)v17 > 0)
        {
            do
            {
                fread(&v16, 1u, 1u, v11);
                sub_426AC0(&v16, 1u);
                ++v9;
            } while (v9 < (int)v17);
        }
        fclose(v11);
        result = 1;
    }
    else
    {
        v17 = 0;
        sub_426AC0(&v17, 4u);
        result = 1;
    }
    return result;
}
// 505080: using guessed type char var_400[1024];

//----- (00505360) --------------------------------------------------------
int sub_505360()
{
    int v1; // ebp
    unsigned __int8* v3; // edi
    int v4; // eax
    size_t v5; // esi
    void* v6; // eax
    int v9; // eax
    int v10; // ebp
    int v12; // esi
    int v13; // ebp
    char* v14; // eax
    int v15; // ecx
    _BYTE* v16; // esi
    bool v17; // cf
    unsigned __int8 v18; // dl
    int v19; // eax
    char* v20; // eax
    char* v21; // eax
    char* v22; // eax
    int v23; // eax
    int v24; // eax
    int v25; // ecx
    int v27; // eax
    int v29; // edi
    int v30; // ebx
    int v31; // ecx
    int v32; // esi
    int i; // edi
    int v35; // esi
    char v36[2]; // [esp+12h] [ebp-40Ah]
    int v37; // [esp+14h] [ebp-408h]
    char v38[1024]; // [esp+1Ch] [ebp-400h]

    strcpy(v36, "%");
    nox_file_7 = fopen("nc.obj", "rb");
    if (!nox_file_7)
        return 0;
    if (!sub_505870("SCRIPT03"))
        goto LABEL_45;
    if (!sub_505870("STRG"))
        goto LABEL_9;
    v1 = 0;
    *(_DWORD*)& byte_5D4594[1599624] = sub_505800();
    *(_DWORD*)& byte_5D4594[1599632] = *(_DWORD*)& byte_5D4594[1599624];
    if (*(_DWORD*)& byte_5D4594[1599624] > 0)
    {
        v3 = &byte_5D4594[3831212];
        do
        {
            v4 = sub_505800();
            v5 = v4;
            v6 = nox_calloc(1u, v4 + 1);
            *(_DWORD*)v3 = v6;
            if (!sub_505830(v5, v6))
                goto LABEL_45;
            ++v1;
            v3 += 4;
        } while (v1 < *(int*)& byte_5D4594[1599624]);
    }
    if (!sub_505870("CODE"))
    {
    LABEL_9:
        fclose(nox_file_7);
        return 0;
    }
    v9 = sub_505800();
    *(_DWORD*)& byte_5D4594[1599640] = v9;
    if (v9)
    {
        *(_DWORD*)& byte_5D4594[1599636] = nox_calloc(1u, 48 * v9);
        v9 = *(_DWORD*)& byte_5D4594[1599640];
    }
    v10 = 0;
    v37 = 0;
    if (v9 > 0)
    {
        while (sub_505870("FUNC"))
        {
            v12 = sub_505800();
            v13 = 48 * v10;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13) = nox_calloc(1u, v12 + 1);
            if (!sub_505830(v12, *(void**)(*(_DWORD*)& byte_5D4594[1599636] + v13)))
                goto LABEL_51;
            if (strlen(*(const char**)(*(_DWORD*)& byte_5D4594[1599636] + v13)) >= 0x400)
                return 0;
            strcpy(v38, *(const char**)(*(_DWORD*)& byte_5D4594[1599636] + v13));
            v14 = strtok(v38, v36);
            v16 = *(_BYTE * *)(*(_DWORD*)& byte_5D4594[1599636] + v13);
            while (1)
            {
                LOBYTE(v15) = *v14;
                v17 = (unsigned __int8)* v14 < *v16;
                if (*v14 != *v16)
                    break;
                if (!(_BYTE)v15)
                    goto LABEL_23;
                v18 = v14[1];
                LOBYTE(v15) = v18;
                v17 = v18 < v16[1];
                if (v18 != v16[1])
                    break;
                v14 += 2;
                v16 += 2;
                if (!v18)
                {
                LABEL_23:
                    v19 = 0;
                    goto LABEL_25;
                }
            }
            v19 = -(int)v17 - ((int)v17 - 1);
        LABEL_25:
            if (v19)
            {
                v20 = strtok(0, v36);
                nox_sprintf(v38, "%%%s", v20);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 36) = nox_calloc(1u, strlen(v38) + 1);
                strcpy(*(char**)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 36), v38);
                v21 = strtok(0, v36);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 40) = atoi(v21);
                v22 = strtok(0, v36);
                v23 = atoi(v22);
                v15 = *(_DWORD*)& byte_5D4594[1599636];
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 44) = v23;
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 36) = 0;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 40) = 0;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 44) = 0;
            }
            v24 = sub_505800();
            v25 = *(_DWORD*)& byte_5D4594[1599636];
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 4) = v24;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 8) = sub_505800();
            if (!sub_505870("SYMB"))
                goto LABEL_45;
            v27 = sub_505800();
            v29 = v37;
            v30 = v27;
            if (!v37)
                v30 = v27 + 1;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 12) = v30;
            sub_505800();
            if (v30)
            {
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 20) = nox_calloc(1u, 4 * v30);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 24) = nox_calloc(1u, 4 * v30);
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 20) = 0;
                v31 = *(_DWORD*)& byte_5D4594[1599636];
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 24) = 0;
            }
            v32 = 0;
            if (!v29)
            {
                v32 = 1;
                **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1599636] + 20) = 0;
                v31 = *(_DWORD*)& byte_5D4594[1599636];
                **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1599636] + 24) = 0;
            }
            for (i = 0; v32 < v30; ++v32)
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 20) + 4 * v32) = sub_505800();
                v31 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 24);
                *(_DWORD*)(v31 + 4 * v32) = i;
                i += *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 20) + 4 * v32);
            }
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 16) = i;
            if (i)
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 28) = nox_calloc(1u, 4 * i);
            else
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 28) = 0;
            if (!sub_505870("DATA"))
                goto LABEL_9;
            v35 = sub_505800();
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 32) = nox_calloc(1u, v35);
            if (fread(*(void**)(*(_DWORD*)& byte_5D4594[1599636] + v13 + 32), 1u, v35, nox_file_7) != v35)
            {
            LABEL_51:
                fclose(nox_file_7);
                return 0;
            }
            if (++v37 >= *(int*)& byte_5D4594[1599640])
                goto LABEL_44;
            v10 = v37;
        }
        goto LABEL_9;
    }
LABEL_44:
    if (!sub_505870("DONE"))
    {
    LABEL_45:
        fclose(nox_file_7);
        return 0;
    }
    fclose(nox_file_7);
    return 1;
}
// 5053BC: variable 'v0' is possibly undefined
// 5053D6: variable 'v2' is possibly undefined
// 505436: variable 'v7' is possibly undefined
// 505486: variable 'v11' is possibly undefined
// 505607: variable 'v15' is possibly undefined
// 50563A: variable 'v26' is possibly undefined
// 505655: variable 'v28' is possibly undefined
// 5056C8: variable 'v31' is possibly undefined
// 505749: variable 'v34' is possibly undefined

//----- (00505800) --------------------------------------------------------
int sub_505800()
{
    size_t v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v1 = fread(&v3, 4u, 1u, nox_file_7);
    return v1 == 1 ? v3 : 0;
}

//----- (00505830) --------------------------------------------------------
BOOL __cdecl sub_505830(size_t a1, void* a2)
{
    size_t v2; // eax

    v2 = fread(a2, 1u, a1, nox_file_7);
    *((_BYTE*)a2 + a1) = 0;
    return v2 == a1;
}

//----- (00505870) --------------------------------------------------------
BOOL __cdecl sub_505870(const char* a1)
{
    char v2[256]; // [esp+Ch] [ebp-100h]

    sub_505830(strlen(a1), v2);
    return strcmp(v2, a1) == 0;
}

//----- (005058F0) --------------------------------------------------------
char* sub_5058F0()
{
    int v0; // edi
    LPVOID* v1; // esi
    int v2; // eax
    int v3; // ebx
    LPVOID* v4; // esi
    int v5; // eax
    char* result; // eax
    int v7; // edi
    int v8; // esi

    v0 = *(_DWORD*)& byte_5D4594[1599624];
    if (*(_DWORD*)& byte_5D4594[1599624] < *(int*)& byte_5D4594[1599632])
    {
        v1 = (LPVOID*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1599624] + 3831212];
        do
        {
            free(*v1);
            v2 = *(_DWORD*)& byte_5D4594[1599632];
            *v1 = 0;
            ++v0;
            ++v1;
        } while (v0 < v2);
        v0 = *(_DWORD*)& byte_5D4594[1599624];
    }
    if (v0)
    {
        v3 = 0;
        if (v0 > 0)
        {
            v4 = (LPVOID*)& byte_5D4594[3831212];
            do
            {
                free(*v4);
                v5 = *(_DWORD*)& byte_5D4594[1599624];
                *v4 = 0;
                ++v3;
                ++v4;
            } while (v3 < v5);
        }
    }
    result = *(char**)& byte_5D4594[1599636];
    *(_DWORD*)& byte_5D4594[1599624] = 0;
    *(_DWORD*)& byte_5D4594[1599628] = 0;
    *(_DWORD*)& byte_5D4594[1599632] = 0;
    if (*(_DWORD*)& byte_5D4594[1599636])
    {
        v7 = 0;
        if (*(_DWORD*)& byte_5D4594[1599640] > 0)
        {
            v8 = 0;
            do
            {
                if (*(_DWORD*)& result[v8])
                {
                    free(*(LPVOID*)& result[v8]);
                    result = *(char**)& byte_5D4594[1599636];
                }
                if (*(_DWORD*)& result[v8 + 36])
                {
                    free(*(LPVOID*)& result[v8 + 36]);
                    result = *(char**)& byte_5D4594[1599636];
                }
                if (*(_DWORD*)& result[v8 + 20])
                {
                    free(*(LPVOID*)& result[v8 + 20]);
                    result = *(char**)& byte_5D4594[1599636];
                }
                if (*(_DWORD*)& result[v8 + 24])
                {
                    free(*(LPVOID*)& result[v8 + 24]);
                    result = *(char**)& byte_5D4594[1599636];
                }
                if (*(_DWORD*)& result[v8 + 28])
                {
                    free(*(LPVOID*)& result[v8 + 28]);
                    result = *(char**)& byte_5D4594[1599636];
                }
                if (*(_DWORD*)& result[v8 + 32])
                {
                    free(*(LPVOID*)& result[v8 + 32]);
                    result = *(char**)& byte_5D4594[1599636];
                }
                ++v7;
                v8 += 48;
            } while (v7 < *(int*)& byte_5D4594[1599640]);
        }
        free(result);
        *(_DWORD*)& byte_5D4594[1599636] = 0;
    }
    *(_DWORD*)& byte_5D4594[1599640] = 0;
    return result;
}

//----- (00505A40) --------------------------------------------------------
int sub_505A40()
{
    int v0; // edi
    char* v1; // eax
    FILE* v2; // eax
    FILE* v3; // esi
    FILE* v5; // esi
    int i; // ebx
    int j; // ebx
    char v8; // [esp+Bh] [ebp-9h]
    int v9; // [esp+Ch] [ebp-8h]
    int v10; // [esp+10h] [ebp-4h]

    v0 = 0;
    v10 = 1;
    v9 = 0;
    sub_426A30();
    v1 = sub_409E10();
    nox_sprintf((char*)& byte_5D4594[3830188], "%s\\nc.obj", v1);
    *(_DWORD*)& byte_5D4594[1599644] = 0;
    sub_426AC0(&v10, 2u);
    if ((__int16)v10 < 1)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[3803300])
    {
        v2 = fopen((const char*)& byte_5D4594[3830188], "rb");
        v3 = v2;
        if (!v2)
        {
            v9 = 0;
            sub_426AC0(&v9, 4u);
            return 1;
        }
        fseek(v2, 0, 2);
        v9 = ftell(v3);
        fseek(v3, 0, 0);
        sub_426AC0(&v9, 4u);
        if (v9 > 0)
        {
            do
            {
                fread(&v8, 1u, 1u, v3);
                sub_426AC0(&v8, 1u);
                ++v0;
            } while (v0 < v9);
        }
        fclose(v3);
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[3803300] != 1)
        return 0;
    v5 = fopen((const char*)& byte_5D4594[3830188], "wb");
    if (!v5)
        return 0;
    sub_426AC0(&v9, 4u);
    *(_DWORD*)& byte_5D4594[1599644] = v9;
    if (sub_40A5C0(0x400000))
    {
        for (i = 0; i < v9; ++i)
        {
            sub_426AC0(&v8, 1u);
            fwrite(&v8, 1u, 1u, v5);
        }
    }
    else
    {
        for (j = 0; j < v9; ++j)
        {
            sub_426AC0(&v8, 1u);
            fwrite(&v8, 1u, 1u, v5);
        }
    }
    fclose(v5);
    if (v9 <= 0 || sub_40A5C0(6291456))
        return 1;
    return sub_505360();
}

//----- (00505C30) --------------------------------------------------------
int sub_505C30()
{
    char v0; // bp
    int v2; // ebx
    int i; // eax
    int v4; // esi
    int j; // eax
    int v6; // edi
    char v7; // al
    bool v8; // zf
    char* v9; // eax
    char* v10; // esi
    int v11; // edi
    int v12; // [esp+10h] [ebp-15Ch]
    int v13; // [esp+14h] [ebp-158h]
    char v14[2]; // [esp+1Ah] [ebp-152h]
    int v15; // [esp+1Ch] [ebp-150h]
    int v16; // [esp+20h] [ebp-14Ch]
    int v17; // [esp+24h] [ebp-148h]
    int v18; // [esp+28h] [ebp-144h]
    int v19[2]; // [esp+2Ch] [ebp-140h]
    int v21; // [esp+34h] [ebp-138h]
    int v22; // [esp+38h] [ebp-134h]
    char v23[76]; // [esp+3Ch] [ebp-130h]
    char v24[76]; // [esp+88h] [ebp-E4h]
    char v25[76]; // [esp+D4h] [ebp-98h]
    char v26[76]; // [esp+120h] [ebp-4Ch]

    v15 = 3;
    v0 = sub_426A30();
    sub_426AC0(&v15, 2u);
    if ((__int16)v15 > 3)
        return 0;
    v2 = 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        v21 = 0;
        v22 = 0;
        sub_426AC0(&v13, 4u);
        if (v13 <= 0)
            return 1;
        while (1)
        {
            sub_426AC0(&v17, 1u);
            sub_426AC0(v23, (unsigned __int8)v17);
            v8 = (_WORD)v15 == 2;
            if ((__int16)v15 < 2)
            {
                if (strlen(sub_409B30()) + 1 + strlen(v23) >= 0x35)
                    return 0;
                v9 = sub_409B30();
                nox_sprintf(v25, "%s.map:%s", v9, v23);
                strcpy(v23, v25);
                v8 = (_WORD)v15 == 2;
            }
            if (v8)
            {
                strcpy(v14, ":");
                strcpy(v24, sub_409B30());
                *(_WORD*)& v24[strlen(v24)] = *(_WORD*)& byte_587000[229976];
                strcpy(v26, v23);
                strtok(v26, v14);
                v10 = strtok(0, v14);
                if (strlen(sub_409B30()) + 1 + strlen(v10) >= 0x35)
                    return 0;
                strcat(v24, v10);
                strcpy(v23, v24);
            }
            sub_426AC0(&v18, 1u);
            sub_426AC0(&v16, 4u);
            if (!(v0 & 4))
            {
                if (sub_40A5C0(0x400000))
                {
                    sub_504600(v23, v16, v18);
                }
                else if (sub_40A5C0(2097153))
                {
                    sub_57C0C0(v23, v16, v18);
                }
            }
            sub_426AC0(&v12, 4u);
            v11 = 0;
            if (v12 > 0)
                break;
        LABEL_44:
            if (++v2 >= v13)
                return 1;
        }
        while (1)
        {
            if ((_BYTE)v18)
            {
                if ((_BYTE)v18 == 1)
                    goto LABEL_38;
                if ((_BYTE)v18 != 2)
                {
                    if ((_BYTE)v18 != 3)
                        return 0;
                LABEL_38:
                    sub_426AC0(&v19[0], 4u);
                    goto LABEL_39;
                }
                sub_426AC0(&v19[0], 4u);
                sub_426AC0(&v19[1], 4u);
            }
            else
            {
                sub_426AC0(&v19[0], 4u);
            }
        LABEL_39:
            if (!(v0 & 4))
            {
                if (sub_40A5C0(0x400000))
                    sub_5046A0(v19, v16);
                else
                    sub_57C130(v19, v16);
            }
            if (++v11 >= v12)
                goto LABEL_44;
        }
    }
    v13 = 0;
    for (i = sub_57C080(); i; i = sub_57C090(i))
        ++v13;
    sub_426AC0(&v13, 4u);
    v4 = sub_57C080();
    if (!v4)
        return 1;
    do
    {
        LOBYTE(v17) = strlen((const char*)(v4 + 8)) + 1;
        sub_426AC0(&v17, 1u);
        sub_426AC0((_BYTE*)(v4 + 8), (unsigned __int8)v17);
        sub_426AC0((_BYTE*)v4, 1u);
        sub_426AC0((_BYTE*)(v4 + 4), 4u);
        v12 = 0;
        for (j = *(_DWORD*)(v4 + 84); j; j = *(_DWORD*)(j + 8))
            ++v12;
        sub_426AC0(&v12, 4u);
        v6 = *(_DWORD*)(v4 + 84);
        if (v6)
        {
            while (1)
            {
                v7 = *(_BYTE*)v4;
                if (!*(_BYTE*)v4 || v7 == 1)
                    goto LABEL_15;
                if (v7 != 2)
                    break;
                sub_426AC0((_BYTE*)v6, 4u);
                sub_426AC0((_BYTE*)(v6 + 4), 4u);
            LABEL_16:
                v6 = *(_DWORD*)(v6 + 8);
                if (!v6)
                    goto LABEL_17;
            }
            if (v7 != 3)
                return 0;
        LABEL_15:
            sub_426AC0((_BYTE*)v6, 4u);
            goto LABEL_16;
        }
    LABEL_17:
        v4 = sub_57C090(v4);
    } while (v4);
    return 1;
}
// 505C30: using guessed type char var_E4[76];

//----- (005060D0) --------------------------------------------------------
int sub_5060D0()
{
    int j; // eax
    char* v2; // esi
    int i; // esi
    size_t v4; // [esp+0h] [ebp-15Ch]
    int v5; // [esp+4h] [ebp-158h]
    int v6; // [esp+8h] [ebp-154h]
    char v7[80]; // [esp+Ch] [ebp-150h]
    char v8[256]; // [esp+5Ch] [ebp-100h]

    v6 = 1;
    sub_426AC0(&v6, 2u);
    if ((__int16)v6 < 1)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&v5, 4u);
        for (i = 0; i < v5; ++i)
        {
            sub_426AC0(&v4, 4u);
            sub_426AC0(v7, v4);
            sub_426AC0(&v4, 4u);
            sub_426AC0(v8, v4);
            if (!sub_40A5C0(0x400000) && sub_40A5C0(1))
                sub_57C500(v7, v8);
        }
        return 1;
    }
    v5 = 0;
    for (j = sub_57C3E0(); j; j = sub_57C3F0(j))
        ++v5;
    sub_426AC0(&v5, 4u);
    v2 = (char*)sub_57C3E0();
    if (!v2)
        return 1;
    do
    {
        v4 = strlen(v2);
        ++v4;
        sub_426AC0(&v4, 4u);
        sub_426AC0(v2, v4);
        v4 = strlen(v2 + 80);
        ++v4;
        sub_426AC0(&v4, 4u);
        sub_426AC0(v2 + 80, v4);
        v2 = (char*)sub_57C3F0((int)v2);
    } while (v2);
    return 1;
}

//----- (00506260) --------------------------------------------------------
int __cdecl sub_506260(_DWORD* a1)
{
    float* v2; // esi
    _DWORD* v3; // edi
    char* v4; // esi
    int v5; // ebx
    _BYTE* v6; // edi
    char* v7; // esi
    char** v8; // eax
    char* v9; // ebp
    _BYTE* v10; // esi
    int v11; // ebx
    _BYTE* v12; // ebp
    _BYTE* v13; // edi
    int v14; // ebx
    _BYTE* v15; // ebp
    _BYTE* v16; // edi
    float* v17; // [esp+10h] [ebp-9Ch]
    int v18; // [esp+14h] [ebp-98h]
    int v19; // [esp+18h] [ebp-94h]
    int v20; // [esp+1Ch] [ebp-90h]
    unsigned int v21; // [esp+20h] [ebp-8Ch]
    float v22; // [esp+24h] [ebp-88h]
    float v23; // [esp+28h] [ebp-84h]
    int v24; // [esp+2Ch] [ebp-80h]
    int v25; // [esp+30h] [ebp-7Ch]
    int2 v26; // [esp+34h] [ebp-78h]
    int v27; // [esp+3Ch] [ebp-70h]
    __int64 v28; // [esp+40h] [ebp-6Ch]
    __int64 v29; // [esp+48h] [ebp-64h]
    int4 v30; // [esp+50h] [ebp-5Ch]
    char v31[76]; // [esp+60h] [ebp-4Ch]

    v18 = 4;
    sub_426AC0(&v18, 2u);
    if ((__int16)v18 > 4)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&v19, 4u);
        v24 = 0;
        if (v19 > 0)
        {
            while (1)
            {
                sub_426AC0(&v25, 4u);
                if ((__int16)v18 < 4)
                {
                    sub_426AC0(&v21, 4u);
                    v28 = v21;
                    v22 = (double)v21;
                    sub_426AC0(&v21, 4u);
                    v29 = v21;
                    v23 = (double)v21;
                }
                else
                {
                    sub_426AC0(&v22, 4u);
                    sub_426AC0(&v23, 4u);
                }
                if ((__int16)v18 >= 3)
                {
                    sub_426AC0(&v20, 1u);
                    if ((_BYTE)v20)
                    {
                        sub_426AC0(v31, (unsigned __int8)v20);
                        v31[(unsigned __int8)v20] = 0;
                    }
                    else
                    {
                        v31[0] = byte_5D4594[1599648];
                    }
                }
                if (a1)
                {
                    v7 = sub_426A70();
                    sub_428170(a1, &v30);
                    v22 = v22 - (double)(int)(23 * *(_DWORD*)v7) + (double)v30.field_0 - 11.0;
                    v23 = v23 - (double)(int)(23 * *((_DWORD*)v7 + 1)) + (double)v30.field_4 - 11.0;
                }
                if (sub_40A5C0(0x400000))
                {
                    v8 = (char**)sub_5044B0(v25, v22, v23);
                    v9 = *v8;
                    v17 = (float*)* v8;
                }
                else
                {
                    v17 = sub_579970(v25, v22, v23);
                    v9 = (char*)v17;
                }
                if (!v9)
                    break;
                if ((__int16)v18 >= 3)
                    strcpy(v9 + 16, v31);
                sub_426AC0(v9 + 480, 4u);
                if ((__int16)v18 < 4)
                {
                    sub_426AC0(&v21, 4u);
                    v10 = v9 + 476;
                    v9[476] = v21;
                }
                else
                {
                    v10 = v9 + 476;
                    sub_426AC0(v9 + 476, 1u);
                }
                if ((__int16)v18 >= 2)
                {
                    v14 = 0;
                    if (*v10)
                    {
                        v15 = v9 + 96;
                        v16 = v17 + 87;
                        do
                        {
                            sub_426AC0(v16, 4u);
                            sub_426AC0(v15, 1u);
                            ++v14;
                            v16 += 4;
                            v15 += 8;
                        } while (v14 < (unsigned __int8)* v10);
                    }
                }
                else
                {
                    v11 = 0;
                    if (*v10)
                    {
                        v12 = v9 + 96;
                        v13 = v17 + 87;
                        do
                        {
                            sub_426AC0(v13, 4u);
                            *v12 = 2;
                            ++v11;
                            v13 += 4;
                            v12 += 8;
                        } while (v11 < (unsigned __int8)* v10);
                    }
                }
                if (++v24 >= v19)
                    return 1;
            }
            return 0;
        }
        return 1;
    }
    v19 = 0;
    v2 = (float*)sub_579860();
    if (v2)
    {
        do
        {
            v3 = a1;
            if (!a1 || (v26.field_0 = (__int64)v2[2], v26.field_4 = (__int64)v2[3], sub_427F30(&v26, a1)))
                ++v19;
            v2 = (float*)sub_579870((int)v2);
        } while (v2);
    }
    else
    {
        v3 = a1;
    }
    sub_426AC0(&v19, 4u);
    v4 = (char*)sub_579860();
    if (!v4)
        return 1;
    do
    {
        if (!v3
            || (v26.field_0 = (__int64) * ((float*)v4 + 2), v26.field_4 = (__int64) * ((float*)v4 + 3), sub_427F30(&v26, v3)))
        {
            sub_426AC0(v4, 4u);
            sub_426AC0(v4 + 8, 4u);
            sub_426AC0(v4 + 12, 4u);
            LOBYTE(v20) = strlen(v4 + 16);
            sub_426AC0(&v20, 1u);
            sub_426AC0(v4 + 16, (unsigned __int8)v20);
            v27 = *((_DWORD*)v4 + 120) & 1;
            sub_426AC0(&v27, 4u);
            sub_426AC0(v4 + 476, 1u);
            v5 = 0;
            if (v4[476])
            {
                v6 = v4 + 96;
                do
                {
                    sub_426AC0(*((_BYTE * *)v6 - 1), 4u);
                    sub_426AC0(v6, 1u);
                    ++v5;
                    v6 += 8;
                } while (v5 < (unsigned __int8)v4[476]);
            }
            v3 = a1;
        }
        v4 = (char*)sub_579870((int)v4);
    } while (v4);
    return 1;
}
// 506260: using guessed type char var_4C[76];

//----- (005066D0) --------------------------------------------------------
int sub_5066D0()
{
    int result; // eax

    result = nox_new_alloc_class("VoteClass", 52, 64);
    *(_DWORD*)& byte_5D4594[1599652] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1599656] = 0;
        result = 1;
    }
    return result;
}

//----- (00506700) --------------------------------------------------------
void sub_506700()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[1599652]);
    *(_DWORD*)& byte_5D4594[1599656] = 0;
}

//----- (00506720) --------------------------------------------------------
int sub_506720()
{
    int result; // eax

    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1599652]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1599652] = 0;
    *(_DWORD*)& byte_5D4594[1599656] = 0;
    return result;
}

//----- (00506740) --------------------------------------------------------
int __cdecl sub_506740(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // ecx
    int v4; // edi

    result = a1;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            result = *(_DWORD*)& byte_5D4594[1599656];
            v2 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
            if (*(_DWORD*)& byte_5D4594[1599656])
            {
                do
                {
                    v3 = *(_DWORD*)(result + 8);
                    v4 = *(_DWORD*)(result + 44);
                    if (v3 & v2)
                    {
                        *(_DWORD*)(result + 8) = ~v2 & v3;
                        --* (_BYTE*)(result + 4);
                    }
                    if (!*(_BYTE*)(result + 4))
                        sub_5067B0(result);
                    result = v4;
                } while (v4);
            }
        }
    }
    return result;
}

//----- (005067B0) --------------------------------------------------------
void __cdecl sub_5067B0(int a1)
{
    int v1; // esi

    if (a1)
    {
        if (*(_DWORD*)a1 == 2)
        {
            v1 = 0;
            do
            {
                if ((1 << v1) & *(_DWORD*)(a1 + 8))
                    sub_506840(v1);
                ++v1;
            } while (v1 < 32);
        }
        sub_506810(a1);
        sub_414330(*(unsigned int**)& byte_5D4594[1599652], (_QWORD*)a1);
        if (!*(_DWORD*)& byte_5D4594[1599656])
            sub_507190(255, 0);
    }
}

//----- (00506810) --------------------------------------------------------
int __cdecl sub_506810(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    v2 = *(_DWORD*)(a1 + 44);
    if (v2)
        * (_DWORD*)(v2 + 48) = *(_DWORD*)(a1 + 48);
    v3 = *(_DWORD*)(a1 + 48);
    if (v3)
    {
        result = *(_DWORD*)(a1 + 44);
        *(_DWORD*)(v3 + 44) = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1599656] = *(_DWORD*)(a1 + 44);
    }
    return result;
}

//----- (00506840) --------------------------------------------------------
int __cdecl sub_506840(int a1)
{
    char v2[2]; // [esp+0h] [ebp-2h]

    v2[0] = -18;
    v2[1] = 7;
    return sub_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (00506870) --------------------------------------------------------
char __cdecl sub_506870(int a1, int a2, wchar_t* a3)
{
    char result; // al

    result = a2;
    if (a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        switch (a1)
        {
        case 0:
            result = sub_5068E0(0, a2, a3);
            break;
        case 1:
            result = sub_5068E0(1, a2, a3);
            break;
        case 2:
            result = (unsigned int)sub_506B00(2, a2);
            break;
        case 3:
            result = (unsigned int)sub_506B80(3, a2, a3);
            break;
        default:
            return result;
        }
    }
    return result;
}

//----- (005068E0) --------------------------------------------------------
char __cdecl sub_5068E0(int a1, int a2, wchar_t* a3)
{
    int v3; // eax
    int v4; // ebp
    int v5; // esi
    int v6; // edi
    int v7; // esi

    LOBYTE(v3) = byte_587000[229980];
    if (*(_DWORD*)& byte_587000[229980] <= 0x20u)
    {
        if (*(_DWORD*)& byte_587000[229980])
        {
            if (a3)
            {
                if (a2)
                {
                    v4 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064);
                    v3 = sub_416EA0();
                    v5 = v3;
                    if (v3)
                    {
                        while (1)
                        {
                            if (*(_DWORD*)(v5 + 2092) == 1)
                            {
                                v3 = nox_wcscmp((const wchar_t*)(v5 + 4704), a3);
                                if (!v3)
                                    break;
                            }
                            v3 = sub_416EE0(v5);
                            v5 = v3;
                            if (!v3)
                                return v3;
                        }
                        if (*(_BYTE*)(v5 + 2064) != 31)
                        {
                            v6 = *(_DWORD*)(v5 + 2056);
                            if (v6)
                            {
                                if (a2 != v6)
                                {
                                    if (!sub_417DA0(4) || (v3 = sub_419150(a2 + 48, v6 + 48)) != 0)
                                    {
                                        v7 = *(_DWORD*)& byte_5D4594[1599656];
                                        if (!*(_DWORD*)& byte_5D4594[1599656])
                                            goto LABEL_21;
                                        while (*(_DWORD*)v7 != a1 || *(_DWORD*)(v7 + 28) != v6)
                                        {
                                            v7 = *(_DWORD*)(v7 + 44);
                                            if (!v7)
                                                goto LABEL_21;
                                        }
                                        if (!v7)
                                        {
                                        LABEL_21:
                                            v3 = sub_506A20(a1, a2);
                                            v7 = v3;
                                            if (!v3)
                                                return v3;
                                            *(_DWORD*)(v3 + 28) = v6;
                                            if (sub_417DA0(4))
                                                * (_DWORD*)(v7 + 20) = 1;
                                        }
                                        v3 = *(_DWORD*)(v7 + 8);
                                        if (!(v4 & v3))
                                        {
                                            LOBYTE(v3) = *(_BYTE*)(v7 + 4) + 1;
                                            *(_DWORD*)(v7 + 8) |= v4;
                                            *(_BYTE*)(v7 + 4) = v3;
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
    return v3;
}

//----- (00506A20) --------------------------------------------------------
_DWORD* __cdecl sub_506A20(int a1, int a2)
{
    int v2; // ebx
    _DWORD* v3; // esi

    v2 = 0;
    if (!a2 || !(*(_BYTE*)(a2 + 8) & 4))
        return 0;
    if (!*(_DWORD*)& byte_5D4594[1599656])
        v2 = 1;
    v3 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1599652]);
    if (!v3)
        return 0;
    *v3 = a1;
    v3[6] = *(_DWORD*)& byte_5D4594[2598000];
    v3[4] = a2 + 48;
    switch (a1)
    {
    case 0:
    case 1:
        *((_BYTE*)v3 + 12) = byte_587000[229980];
        break;
    case 2:
    case 3:
        *((_BYTE*)v3 + 12) = 6;
        break;
    default:
        *((_BYTE*)v3 + 12) = byte_587000[229984];
        break;
    }
    sub_506AD0((int)v3);
    if (v2)
        sub_507190(255, 1);
    return v3;
}

//----- (00506AD0) --------------------------------------------------------
int __cdecl sub_506AD0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 48) = 0;
    *(_DWORD*)(a1 + 44) = *(_DWORD*)& byte_5D4594[1599656];
    if (*(_DWORD*)& byte_5D4594[1599656])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1599656] + 48) = a1;
    *(_DWORD*)& byte_5D4594[1599656] = a1;
    return result;
}

//----- (00506B00) --------------------------------------------------------
_DWORD* __cdecl sub_506B00(int a1, int a2)
{
    _DWORD* result; // eax
    int v3; // esi
    char v4; // cl

    result = *(_DWORD * *)& byte_587000[229988];
    if (*(_DWORD*)& byte_587000[229988])
    {
        if (a2)
        {
            result = *(_DWORD * *)(*(_DWORD*)(a2 + 748) + 276);
            v3 = 1 << *((_BYTE*)result + 2064);
            if (result[1198])
            {
                result = *(_DWORD * *)& byte_5D4594[1599656];
                if (!*(_DWORD*)& byte_5D4594[1599656])
                    goto LABEL_9;
                while (*result != a1)
                {
                    result = (_DWORD*)result[11];
                    if (!result)
                        goto LABEL_9;
                }
                if (!result)
                {
                LABEL_9:
                    result = sub_506A20(a1, a2);
                    if (!result)
                        return result;
                    result[5] = 0;
                }
                if (!(result[2] & v3))
                {
                    v4 = *((_BYTE*)result + 4) + 1;
                    result[2] |= v3;
                    *((_BYTE*)result + 4) = v4;
                }
            }
        }
    }
    return result;
}

//----- (00506B80) --------------------------------------------------------
_DWORD* __cdecl sub_506B80(int a1, int a2, wchar_t* a3)
{
    _DWORD* result; // eax
    int v4; // edi
    const wchar_t* v5; // esi
    int v6; // esi
    char v7; // cl

    result = *(_DWORD * *)& byte_587000[229992];
    if (*(_DWORD*)& byte_587000[229992])
    {
        if (a3)
        {
            result = (_DWORD*)a2;
            if (a2)
            {
                result = *(_DWORD * *)(*(_DWORD*)(a2 + 748) + 276);
                v4 = 1 << *((_BYTE*)result + 2064);
                if (result[1198])
                {
                    result = sub_416EA0();
                    v5 = (const wchar_t*)result;
                    if (result)
                    {
                        while (1)
                        {
                            if (*((_DWORD*)v5 + 523) == 1)
                            {
                                result = (_DWORD*)nox_wcscmp(v5 + 2352, a3);
                                if (!result)
                                    break;
                            }
                            result = sub_416EE0((int)v5);
                            v5 = (const wchar_t*)result;
                            if (!result)
                                return result;
                        }
                        if (*((_BYTE*)v5 + 2064) != 31)
                        {
                            result = (_DWORD*) * ((_DWORD*)v5 + 1198);
                            if (result)
                            {
                                v6 = *((_DWORD*)v5 + 514);
                                if (v6)
                                {
                                    if (a2 != v6)
                                    {
                                        result = *(_DWORD * *)& byte_5D4594[1599656];
                                        if (!*(_DWORD*)& byte_5D4594[1599656])
                                            goto LABEL_20;
                                        while (*result != a1 || result[7] != v6)
                                        {
                                            result = (_DWORD*)result[11];
                                            if (!result)
                                                goto LABEL_20;
                                        }
                                        if (!result)
                                        {
                                        LABEL_20:
                                            result = sub_506A20(a1, a2);
                                            if (!result)
                                                return result;
                                            result[7] = v6;
                                        }
                                        if (!(result[2] & v4))
                                        {
                                            v7 = *((_BYTE*)result + 4) + 1;
                                            result[2] |= v4;
                                            *((_BYTE*)result + 4) = v7;
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

//----- (00506C90) --------------------------------------------------------
void __cdecl sub_506C90(int a1, int a2, wchar_t* a3)
{
    if (a2 && *(_BYTE*)(a2 + 8) & 4)
    {
        switch (a1)
        {
        case 0:
            sub_506D00(a2, a3);
            break;
        case 1:
            sub_506D00(a2, a3);
            break;
        case 2:
            sub_506DE0(a2);
            break;
        case 3:
            sub_506E50(a2, a3);
            break;
        default:
            return;
        }
    }
}

//----- (00506D00) --------------------------------------------------------
void __cdecl sub_506D00(int a1, wchar_t* a2)
{
    char* v2; // esi
    int v3; // esi
    int v4; // eax
    int v5; // edx
    int v6; // esi
    bool v7; // zf

    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 4)
            {
                v2 = sub_416EA0();
                if (v2)
                {
                    while (*((_DWORD*)v2 + 523) != 1 || nox_wcscmp((const wchar_t*)v2 + 2352, a2))
                    {
                        v2 = sub_416EE0((int)v2);
                        if (!v2)
                            return;
                    }
                    if (v2[2064] != 31)
                    {
                        v3 = *((_DWORD*)v2 + 514);
                        if (v3)
                        {
                            v4 = *(_DWORD*)& byte_5D4594[1599656];
                            v5 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
                            if (*(_DWORD*)& byte_5D4594[1599656])
                            {
                                while (*(_DWORD*)v4 || *(_DWORD*)(v4 + 28) != v3 || !(v5 & *(_DWORD*)(v4 + 8)))
                                {
                                    v4 = *(_DWORD*)(v4 + 44);
                                    if (!v4)
                                        return;
                                }
                                if (v4)
                                {
                                    v6 = ~v5 & *(_DWORD*)(v4 + 8);
                                    v7 = (*(_BYTE*)(v4 + 4))-- == 1;
                                    *(_DWORD*)(v4 + 8) = v6;
                                    if (v7)
                                        sub_5067B0(v4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//----- (00506DE0) --------------------------------------------------------
void __cdecl sub_506DE0(int a1)
{
    int result;
    int v2; // edx
    char v3; // cl
    int v4; // esi

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 4)
        {
            result = *(_DWORD*)& byte_5D4594[1599656];
            v2 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
            if (*(_DWORD*)& byte_5D4594[1599656])
            {
                while (*(_DWORD*)result != 2)
                {
                    result = *(_DWORD*)(result + 44);
                    if (!result)
                        return;
                }
                if (result && v2 & *(_DWORD*)(result + 8))
                {
                    v3 = *(_BYTE*)(result + 4) - 1;
                    v4 = ~v2 & *(_DWORD*)(result + 8);
                    *(_BYTE*)(result + 4) = v3;
                    *(_DWORD*)(result + 8) = v4;
                    if (!v3)
                        sub_5067B0(result);
                }
            }
        }
    }
}

//----- (00506E50) --------------------------------------------------------
void __cdecl sub_506E50(int a1, wchar_t* a2)
{
    char* v2; // esi
    int v3; // esi
    int v4; // eax
    int v5; // edx
    int v6; // esi
    bool v7; // zf

    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 4)
            {
                v2 = sub_416EA0();
                if (v2)
                {
                    while (*((_DWORD*)v2 + 523) != 1 || nox_wcscmp((const wchar_t*)v2 + 2352, a2))
                    {
                        v2 = sub_416EE0((int)v2);
                        if (!v2)
                            return;
                    }
                    if (v2[2064] != 31)
                    {
                        v3 = *((_DWORD*)v2 + 514);
                        if (v3)
                        {
                            v4 = *(_DWORD*)& byte_5D4594[1599656];
                            v5 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
                            if (*(_DWORD*)& byte_5D4594[1599656])
                            {
                                while (*(_DWORD*)v4 != 3 || *(_DWORD*)(v4 + 28) != v3 || !(v5 & *(_DWORD*)(v4 + 8)))
                                {
                                    v4 = *(_DWORD*)(v4 + 44);
                                    if (!v4)
                                        return;
                                }
                                if (v4)
                                {
                                    v6 = ~v5 & *(_DWORD*)(v4 + 8);
                                    v7 = (*(_BYTE*)(v4 + 4))-- == 1;
                                    *(_DWORD*)(v4 + 8) = v6;
                                    if (v7)
                                        sub_5067B0(v4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//----- (00506F30) --------------------------------------------------------
_DWORD* sub_506F30()
{
    _DWORD* result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD * *)& byte_5D4594[1599656];
    if (*(_DWORD*)& byte_5D4594[1599656])
    {
        do
        {
            v1 = (_DWORD*)result[11];
            switch (*result)
            {
            case 0:
            case 1:
                sub_506F80((int)result);
                break;
            case 2:
                sub_507090((int)result);
                break;
            case 3:
                sub_507100((int)result);
                break;
            default:
                break;
            }
            result = v1;
        } while (v1);
    }
    return result;
}

//----- (00506F80) --------------------------------------------------------
void __cdecl sub_506F80(int a1)
{
    int v1; // esi
    int v3; // esi

    v1 = *(_DWORD*)(a1 + 28);
    if (*(_BYTE*)(v1 + 16) & 0x20)
    {
        sub_5067B0(a1);
        return;
    }
    *(_DWORD*)(a1 + 16) = v1 + 48;
    if (sub_507000(a1) == 1)
    {
        v3 = *(_DWORD*)(v1 + 748);
        sub_4DEAB0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 4);
        sub_416770(15, (wchar_t*)(*(_DWORD*)(v3 + 276) + 4704), (const char*)(*(_DWORD*)(v3 + 276) + 2112));
        sub_5067B0(a1);
    }
}

//----- (00507000) --------------------------------------------------------
BOOL __cdecl sub_507000(int a1)
{
    int v1; // edi
    int i; // esi
    int j; // eax

    v1 = 0;
    if (*(_BYTE*)(a1 + 4) >= *(_BYTE*)(a1 + 12))
        return 1;
    if (*(_DWORD*)(a1 + 20) == 1)
    {
        for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
        {
            if (sub_419150(*(_DWORD*)(a1 + 16), i + 48))
                ++v1;
        }
    }
    else
    {
        for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j))
            ++v1;
    }
    return *(unsigned __int8*)(a1 + 4) >= (unsigned int)(v1 - 1) && *(_BYTE*)(a1 + 4) >= 2u;
}

//----- (00507090) --------------------------------------------------------
void __cdecl sub_507090(int a1)
{
    int i; // esi
    int v3; // eax
    char* v4; // eax

    sub_4E3CE0();
    if (*(unsigned __int8*)(a1 + 4) >= sub_4E3CE0())
    {
        for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
        {
            v3 = *(_DWORD*)(*(_DWORD*)(i + 748) + 276);
            if (*(_DWORD*)(v3 + 4792) == 1)
                sub_4F7EF0(*(_DWORD*)(v3 + 2056));
        }
        sub_4E3CD0(0);
        v4 = sub_4D0F60();
        sub_4D2450(v4);
        sub_5067B0(a1);
    }
}

//----- (00507100) --------------------------------------------------------
void __cdecl sub_507100(int a1)
{
    int v1; // edi
    int v2; // ebx
    unsigned int v3; // eax
    unsigned int result; // eax

    v1 = *(_DWORD*)(a1 + 28);
    if (!v1)
    {
        sub_5067B0(a1);
        return;
    }
    if (*(_BYTE*)(v1 + 16) & 0x20)
    {
        sub_5067B0(a1);
        return;
    }
    v2 = *(_DWORD*)(v1 + 748);
    if (!*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4792))
    {
        sub_5067B0(a1);
        return;
    }
    if (*(_BYTE*)(a1 + 4) >= *(_BYTE*)(a1 + 12))
    {
    LABEL_8:
        sub_4DCFB0(v1);
        sub_416770(15, (wchar_t*)(*(_DWORD*)(v2 + 276) + 4704), (const char*)(*(_DWORD*)(v2 + 276) + 2112));
        sub_5067B0(a1);
        return;
    }
    v3 = sub_4E3CE0();
    if (v3 <= 1)
    {
        sub_5067B0(a1);
        return;
    }
    result = v3 - 1;
    if (*(unsigned __int8*)(a1 + 4) >= result && *(_BYTE*)(a1 + 4) >= 2u)
        goto LABEL_8;
}

//----- (00507190) --------------------------------------------------------
int __cdecl sub_507190(int a1, char a2)
{
    int v2; // ecx
    char v4[3]; // [esp+0h] [ebp-4h]
    char v5; // [esp+3h] [ebp-1h]

    v5 = HIBYTE(v2);
    v4[0] = -18;
    v4[1] = 6;
    v4[2] = a2;
    return sub_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (005071C0) --------------------------------------------------------
BOOL sub_5071C0()
{
    return *(_DWORD*)& byte_5D4594[1599656] != 0;
}

//----- (005071D0) --------------------------------------------------------
int __cdecl sub_5071D0(const char* a1)
{
    int v1; // ebp
    const char** i; // edi

    v1 = 0;
    if (*(int*)& byte_5D4594[1599640] <= 0)
        return -1;
    for (i = *(const char***)& byte_5D4594[1599636]; strcmp(*i, a1); i += 12)
    {
        if (++v1 >= *(int*)& byte_5D4594[1599640])
            return -1;
    }
    return v1;
}

//----- (00507230) --------------------------------------------------------
int __cdecl sub_507230(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1599660];
    if (*(int*)& byte_5D4594[1599660] < 1024)
    {
        *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1599660] + 3821996] = a1;
        *(_DWORD*)& byte_5D4594[1599660] = ++result;
    }
    return result;
}

//----- (00507250) --------------------------------------------------------
int script_pop()
{
    int v0; // eax

    v0 = *(_DWORD*)& byte_5D4594[1599660];
    if (*(_DWORD*)& byte_5D4594[1599660] > 0)
        v0 = -- * (_DWORD*)& byte_5D4594[1599660];
    return *(_DWORD*)& byte_5D4594[4 * v0 + 3821996];
}

//----- (00507270) --------------------------------------------------------
int __cdecl sub_507270(int** a1)
{
    int result; // eax

    result = **a1;
    ++* a1;
    return result;
}

//----- (00507280) --------------------------------------------------------
double __cdecl sub_507280(float** a1)
{
    double result; // st7

    result = **a1;
    ++* a1;
    return result;
}

//----- (00507290) --------------------------------------------------------
LPVOID sub_507290()
{
    LPVOID result; // eax

    *(_DWORD*)& byte_5D4594[3821640] = 0;
    byte_5D4594[3821644] = byte_5D4594[1599668];
    result = *(LPVOID*)& byte_5D4594[1599636];
    *(_DWORD*)& byte_5D4594[3821636] = 0;
    if (*(_DWORD*)& byte_5D4594[1599636])
    {
        **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1599636] + 76) = -2;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4) = -1;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 8) = 1;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 12) = 0;
        result = (LPVOID)sub_4DB240();
        if (!result)
            result = (LPVOID)sub_507310(1, 0, 0);
    }
    return result;
}

//----- (00507310) --------------------------------------------------------
int __cdecl sub_507310(int a1, int a2, int a3)
{
    int v3; // ebx
    int v4; // eax
    int v5; // ebp
    int v6; // esi
    int v7; // ecx
    int v8; // edx
    int v9; // esi
    int v10; // eax
    int v11; // esi
    int v12; // eax
    double v13; // st7
    int v14; // edi
    int v15; // eax
    int v16; // ecx
    int v17; // esi
    int v18; // eax
    int v19; // eax
    int v20; // esi
    int v21; // eax
    double v22; // st7
    int v23; // esi
    int v24; // eax
    int v25; // eax
    int v26; // esi
    int v27; // eax
    int v28; // esi
    int v29; // eax
    int v30; // esi
    int v31; // eax
    int v32; // esi
    int v33; // eax
    int v34; // esi
    int v35; // eax
    int v36; // esi
    int v37; // eax
    int v38; // esi
    int v39; // eax
    char v40; // si
    int v41; // eax
    char v42; // si
    int v43; // eax
    int v44; // esi
    int v45; // esi
    int v46; // edi
    int v47; // esi
    float v48; // edi
    int v49; // esi
    int v50; // edi
    int v51; // esi
    int v52; // esi
    int v53; // edx
    double v54; // st7
    float* v55; // eax
    int v56; // eax
    double v57; // st7
    float* v58; // eax
    int v59; // ecx
    float* v60; // eax
    double v61; // st7
    int v62; // ebp
    int v63; // edi
    int v64; // ebx
    int v65; // esi
    int v66; // eax
    int v67; // eax
    int v68; // edi
    int v69; // esi
    int v70; // esi
    int v71; // ecx
    float* v72; // eax
    double v73; // st7
    int v74; // edi
    int v75; // esi
    int v76; // edx
    int v77; // eax
    int v78; // edi
    int v79; // esi
    int v80; // esi
    int v81; // esi
    int v82; // edi
    int v83; // esi
    int v84; // esi
    char v85; // di
    int v86; // esi
    char v87; // di
    int v88; // esi
    int v89; // edi
    int v90; // esi
    int v91; // edi
    int v92; // esi
    int v93; // edi
    int v94; // esi
    int v95; // esi
    int v96; // eax
    int v97; // esi
    int v98; // esi
    int v99; // eax
    int v100; // esi
    int v101; // kr00_4
    int v102; // esi
    int v103; // eax
    int v104; // esi
    int v105; // kr04_4
    int v106; // esi
    int v107; // eax
    int v108; // esi
    int v109; // kr08_4
    int v110; // esi
    int v111; // eax
    int v112; // esi
    int v113; // kr0C_4
    int v114; // esi
    int v115; // eax
    int v116; // esi
    int v117; // esi
    int v118; // esi
    int v119; // edi
    int v120; // esi
    int v121; // ebx
    int v122; // eax
    int v123; // esi
    int v124; // esi
    int result; // eax
    int v126; // eax
    int v127; // edi
    int v128; // esi
    int v129; // ebx
    int v130; // eax
    int v131; // esi
    int v132; // edi
    int v133; // ebx
    int v134; // eax
    int v135; // eax
    int v136; // eax
    int v137; // eax
    int v138; // eax
    int v139; // eax
    int v140; // [esp+10h] [ebp-118h]
    float v141; // [esp+10h] [ebp-118h]
    float v142; // [esp+10h] [ebp-118h]
    int v143; // [esp+10h] [ebp-118h]
    float v144; // [esp+10h] [ebp-118h]
    int v145; // [esp+10h] [ebp-118h]
    float v146; // [esp+10h] [ebp-118h]
    float v147; // [esp+10h] [ebp-118h]
    float v148; // [esp+10h] [ebp-118h]
    float v149; // [esp+10h] [ebp-118h]
    float v150; // [esp+10h] [ebp-118h]
    float v151; // [esp+10h] [ebp-118h]
    float v152; // [esp+10h] [ebp-118h]
    float v153; // [esp+10h] [ebp-118h]
    float v154; // [esp+10h] [ebp-118h]
    float v155; // [esp+10h] [ebp-118h]
    float v156; // [esp+10h] [ebp-118h]
    float v157; // [esp+10h] [ebp-118h]
    int v158; // [esp+10h] [ebp-118h]
    float v159; // [esp+10h] [ebp-118h]
    int v160; // [esp+18h] [ebp-110h]
    int v161; // [esp+1Ch] [ebp-10Ch]
    int v162; // [esp+20h] [ebp-108h]
    int v163; // [esp+24h] [ebp-104h]
    char v164[256]; // [esp+28h] [ebp-100h]

    v3 = a3;
    *(_DWORD*)& byte_5D4594[3821964] = a2;
    v4 = *(_DWORD*)& byte_5D4594[1599636];
    *(_DWORD*)& byte_5D4594[3821968] = a3;
    v5 = 48 * a1;
    v6 = 0;
    v7 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 48 * a1 + 8);
    v161 = 0;
    v162 = 48 * a1;
    if (v7 > 0)
    {
        do
        {
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * ++v6 - 4) = script_pop();
            v4 = *(_DWORD*)& byte_5D4594[1599636];
        } while (v6 < *(int*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 8));
    }
    v8 = *(_DWORD*)(v4 + v5 + 32);
    v163 = *(_DWORD*)& byte_5D4594[1599660];
    v160 = v8;
    while (1)
    {
        switch (sub_507270((int**)& v160))
        {
        case 0:
        case 3:
            v9 = sub_507270((int**)& v160);
            v10 = sub_507270((int**)& v160);
            if (v9)
            {
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76)
                    + 4 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 72) + 4 * v10)));
            }
            else if (v10 < 0)
            {
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760)
                    + 4 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 24) - 4 * v10)));
            }
            else
            {
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28)
                    + 4 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 24) + 4 * v10)));
            }
            continue;
        case 1:
            v11 = sub_507270((int**)& v160);
            v12 = sub_507270((int**)& v160);
            if (v11)
            {
                v13 = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76)
                    + 4 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 72) + 4 * v12));
            }
            else if (v12 < 0)
            {
                v13 = *(float*)(*(_DWORD*)(v3 + 760)
                    + 4 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 24) - 4 * v12));
            }
            else
            {
                v13 = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28)
                    + 4 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 24) + 4 * v12));
            }
            goto LABEL_16;
        case 2:
            v14 = sub_507270((int**)& v160);
            v15 = sub_507270((int**)& v160);
            if (v14)
            {
                v16 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 68) + 4 * v15);
                v17 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 72) + 4 * v15);
            }
            else if (v15 < 0)
            {
                v18 = 4 * v15;
                v16 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 20) - v18);
                v17 = -*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 24) - v18);
            }
            else
            {
                v16 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 20) + 4 * v15);
                v17 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 24) + 4 * v15);
            }
            if (v16 > 1)
                sub_507230(v16);
            sub_507230(v14);
            sub_507230(v17);
            continue;
        case 4:
        case 6:
            v19 = sub_507270((int**)& v160);
            sub_507230(v19);
            continue;
        case 5:
            v141 = sub_507280((float**)& v160);
            sub_507230(SLODWORD(v141));
            continue;
        case 7:
            v20 = script_pop();
            v21 = script_pop();
            sub_507230(v21 + v20);
            continue;
        case 8:
            v142 = COERCE_FLOAT(script_pop());
            v22 = COERCE_FLOAT(script_pop()) + v142;
            goto LABEL_29;
        case 9:
            v26 = script_pop();
            v27 = script_pop();
            sub_507230(v27 - v26);
            continue;
        case 10:
            v144 = COERCE_FLOAT(script_pop());
            *(float*)& v145 = COERCE_FLOAT(script_pop()) - v144;
            sub_507230(v145);
            continue;
        case 11:
            v28 = script_pop();
            v29 = script_pop();
            sub_507230(v28 * v29);
            continue;
        case 12:
            v146 = COERCE_FLOAT(script_pop());
            v22 = COERCE_FLOAT(script_pop()) * v146;
        LABEL_29:
            *(float*)& v143 = v22;
            sub_507230(v143);
            continue;
        case 13:
            v30 = script_pop();
            v31 = script_pop();
            sub_507230(v31 / v30);
            continue;
        case 14:
            v147 = COERCE_FLOAT(script_pop());
            v13 = COERCE_FLOAT(script_pop()) / v147;
            goto LABEL_16;
        case 15:
            v32 = script_pop();
            v33 = script_pop();
            sub_507230(v33 % v32);
            continue;
        case 16:
            v34 = script_pop();
            v35 = script_pop();
            sub_507230(v35 & v34);
            continue;
        case 17:
            v36 = script_pop();
            v37 = script_pop();
            sub_507230(v37 | v36);
            continue;
        case 18:
            v38 = script_pop();
            v39 = script_pop();
            sub_507230(v39 ^ v38);
            continue;
        case 19:
            v160 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 32) + 4 * sub_507270((int**)& v160);
            continue;
        case 20:
            v44 = sub_507270((int**)& v160);
            if (script_pop())
                v160 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 32) + 4 * v44;
            continue;
        case 21:
            v45 = sub_507270((int**)& v160);
            if (!script_pop())
                v160 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 32) + 4 * v45;
            continue;
        case 22:
        case 24:
            v46 = script_pop();
            v47 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v47) = v46;
                sub_507230(v46);
            }
            else
            {
                if (v47 < 0)
                    * (_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v47) = v46;
                else
                    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v47) = v46;
                sub_507230(v46);
            }
            continue;
        case 23:
            v48 = COERCE_FLOAT(script_pop());
            v49 = script_pop();
            if (script_pop())
            {
                *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v49) = v48;
                sub_507230(SLODWORD(v48));
            }
            else
            {
                if (v49 < 0)
                    * (float*)(*(_DWORD*)(v3 + 760) - 4 * v49) = v48;
                else
                    *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v49) = v48;
                sub_507230(SLODWORD(v48));
            }
            continue;
        case 25:
            v74 = script_pop();
            v75 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v75) *= v74;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v75));
            }
            else if (v75 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v75) *= v74;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v75));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v75) *= v74;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v75));
            }
            continue;
        case 26:
            v150 = COERCE_FLOAT(script_pop());
            v52 = script_pop();
            if (script_pop())
            {
                v76 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76);
                v54 = v150 * *(float*)(v76 + 4 * v52);
                v55 = (float*)(v76 + 4 * v52);
                goto LABEL_98;
            }
            if (v52 >= 0)
            {
                v77 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28);
                v57 = v150 * *(float*)(v77 + 4 * v52);
                v58 = (float*)(v77 + 4 * v52);
                goto LABEL_101;
            }
            v59 = 4 * v52;
            v60 = (float*)(*(_DWORD*)(v3 + 760) - 4 * v52);
            v61 = v150 * *v60;
            goto LABEL_103;
        case 27:
            v78 = script_pop();
            v79 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v79) /= v78;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v79));
            }
            else if (v79 < 0)
            {
                v80 = 4 * v79;
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - v80) /= v78;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - v80));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v79) /= v78;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v79));
            }
            continue;
        case 28:
            v151 = COERCE_FLOAT(script_pop());
            v81 = script_pop();
            if (script_pop())
            {
                *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v81) = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76)
                    + 4 * v81)
                    / v151;
                v13 = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v81);
                goto LABEL_16;
            }
            if (v81 >= 0)
            {
                *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v81) = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v81)
                    / v151;
                v13 = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v81);
                goto LABEL_16;
            }
            v71 = 4 * v81;
            v72 = (float*)(*(_DWORD*)(v3 + 760) - 4 * v81);
            v73 = *v72 / v151;
            goto LABEL_114;
        case 29:
            v50 = script_pop();
            v51 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v51) += v50;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v51));
            }
            else if (v51 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v51) += v50;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v51));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v51) += v50;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v51));
            }
            continue;
        case 30:
            v148 = COERCE_FLOAT(script_pop());
            v52 = script_pop();
            if (script_pop())
            {
                v53 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76);
                v54 = v148 + *(float*)(v53 + 4 * v52);
                v55 = (float*)(v53 + 4 * v52);
            LABEL_98:
                *v55 = v54;
                sub_507230(COERCE_INT(*(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v52)));
            }
            else if (v52 < 0)
            {
                v59 = 4 * v52;
                v60 = (float*)(*(_DWORD*)(v3 + 760) - 4 * v52);
                v61 = v148 + *v60;
            LABEL_103:
                *v60 = v61;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - v59));
            }
            else
            {
                v56 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28);
                v57 = v148 + *(float*)(v56 + 4 * v52);
                v58 = (float*)(v56 + 4 * v52);
            LABEL_101:
                *v58 = v57;
                sub_507230(COERCE_INT(*(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v52)));
            }
            continue;
        case 31:
            v62 = script_pop();
            v63 = script_pop();
            v64 = script_pop();
            if (v64)
            {
                v65 = 4 * v63;
                v66 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v63);
            }
            else
            {
                v65 = 4 * v63;
                if (v63 < 0)
                    v66 = *(_DWORD*)(*(_DWORD*)(a3 + 760) - 4 * v63);
                else
                    v66 = *(_DWORD*)(*(_DWORD*)(v162 + *(_DWORD*)& byte_5D4594[1599636] + 28) + 4 * v63);
            }
            nox_sprintf(
                v164,
                "%s%s",
                *(_DWORD*)& byte_5D4594[4 * v66 + 3831212],
                *(_DWORD*)& byte_5D4594[4 * v62 + 3831212]);
            v67 = sub_512E40(v164);
            if (v64)
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + v65) = v67;
                sub_507230(v67);
                v5 = v162;
            }
            else
            {
                if (v63 < 0)
                    * (_DWORD*)(*(_DWORD*)(a3 + 760) - v65) = v67;
                else
                    *(_DWORD*)(*(_DWORD*)(v162 + *(_DWORD*)& byte_5D4594[1599636] + 28) + v65) = v67;
                sub_507230(v67);
                v5 = v162;
            }
            goto LABEL_4;
        case 32:
            v68 = script_pop();
            v69 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v69) -= v68;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v69));
            }
            else if (v69 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v69) -= v68;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v69));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v69) -= v68;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v69));
            }
            continue;
        case 33:
            v149 = COERCE_FLOAT(script_pop());
            v70 = script_pop();
            if (script_pop())
            {
                *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v70) = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76)
                    + 4 * v70)
                    - v149;
                v13 = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v70);
            LABEL_16:
                *(float*)& v140 = v13;
                sub_507230(v140);
                continue;
            }
            if (v70 >= 0)
            {
                *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v70) = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v70)
                    - v149;
                v13 = *(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v70);
                goto LABEL_16;
            }
            v71 = 4 * v70;
            v72 = (float*)(*(_DWORD*)(v3 + 760) - 4 * v70);
            v73 = *v72 - v149;
        LABEL_114:
            *v72 = v73;
            sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - v71));
            break;
        case 34:
            v82 = script_pop();
            v83 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v83) %= v82;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v83));
            }
            else if (v83 < 0)
            {
                v84 = 4 * v83;
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - v84) %= v82;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - v84));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v83) %= v82;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v83));
            }
            continue;
        case 35:
            v95 = script_pop();
            v96 = script_pop();
            sub_507230(v96 == v95);
            continue;
        case 36:
            v152 = COERCE_FLOAT(script_pop());
            if (COERCE_FLOAT(script_pop()) != v152)
                goto LABEL_184;
            sub_507230(1);
            continue;
        case 37:
            v97 = script_pop();
            if (!strcmp(
                *(const char**)& byte_5D4594[4 * script_pop() + 3831212],
                *(const char**)& byte_5D4594[4 * v97 + 3831212]))
                sub_507230(1);
            else
                sub_507230(0);
            continue;
        case 38:
            v40 = script_pop();
            v41 = script_pop();
            sub_507230(v41 << v40);
            continue;
        case 39:
            v42 = script_pop();
            v43 = script_pop();
            sub_507230(v43 >> v42);
            continue;
        case 40:
            v98 = script_pop();
            v99 = script_pop();
            sub_507230(v99 < v98);
            continue;
        case 41:
            v153 = COERCE_FLOAT(script_pop());
            if (COERCE_FLOAT(script_pop()) >= (double)v153)
                goto LABEL_184;
            sub_507230(1);
            continue;
        case 42:
            v100 = script_pop();
            v101 = strcmp(
                *(const char**)& byte_5D4594[4 * script_pop() + 3831212],
                *(const char**)& byte_5D4594[4 * v100 + 3831212]);
            if (v101)
                sub_507230(-(v101 < 0) - ((v101 < 0) - 1) < 0);
            else
                sub_507230(0);
            continue;
        case 43:
            v102 = script_pop();
            v103 = script_pop();
            sub_507230(v103 > v102);
            continue;
        case 44:
            v154 = COERCE_FLOAT(script_pop());
            if (COERCE_FLOAT(script_pop()) <= (double)v154)
                goto LABEL_184;
            sub_507230(1);
            continue;
        case 45:
            v104 = script_pop();
            v105 = strcmp(
                *(const char**)& byte_5D4594[4 * script_pop() + 3831212],
                *(const char**)& byte_5D4594[4 * v104 + 3831212]);
            if (v105)
                sub_507230(-(v105 < 0) - ((v105 < 0) - 1) > 0);
            else
                sub_507230(0);
            continue;
        case 46:
            v106 = script_pop();
            v107 = script_pop();
            sub_507230(v107 <= v106);
            continue;
        case 47:
            v155 = COERCE_FLOAT(script_pop());
            if (COERCE_FLOAT(script_pop()) > (double)v155)
                goto LABEL_184;
            sub_507230(1);
            continue;
        case 48:
            v108 = script_pop();
            v109 = strcmp(
                *(const char**)& byte_5D4594[4 * script_pop() + 3831212],
                *(const char**)& byte_5D4594[4 * v108 + 3831212]);
            if (v109)
                sub_507230(-(v109 < 0) - ((v109 < 0) - 1) <= 0);
            else
                sub_507230(1);
            continue;
        case 49:
            v110 = script_pop();
            v111 = script_pop();
            sub_507230(v111 >= v110);
            continue;
        case 50:
            v156 = COERCE_FLOAT(script_pop());
            if (COERCE_FLOAT(script_pop()) < (double)v156)
                goto LABEL_184;
            sub_507230(1);
            continue;
        case 51:
            v112 = script_pop();
            v113 = strcmp(
                *(const char**)& byte_5D4594[4 * script_pop() + 3831212],
                *(const char**)& byte_5D4594[4 * v112 + 3831212]);
            if (v113)
                sub_507230(-(v113 < 0) - ((v113 < 0) - 1) >= 0);
            else
                sub_507230(1);
            continue;
        case 52:
            v114 = script_pop();
            v115 = script_pop();
            sub_507230(v115 != v114);
            continue;
        case 53:
            v157 = COERCE_FLOAT(script_pop());
            if (COERCE_FLOAT(script_pop()) == v157)
                goto LABEL_184;
            sub_507230(1);
            continue;
        case 54:
            v116 = script_pop();
            if (!strcmp(
                *(const char**)& byte_5D4594[4 * script_pop() + 3831212],
                *(const char**)& byte_5D4594[4 * v116 + 3831212]))
                sub_507230(0);
            else
                sub_507230(1);
            continue;
        case 55:
            v117 = script_pop();
            if (script_pop() && v117)
                sub_507230(1);
            else
                LABEL_184:
            sub_507230(0);
            continue;
        case 56:
            v118 = script_pop();
            if (script_pop() || v118)
                sub_507230(1);
            else
                sub_507230(0);
            continue;
        case 57:
            v85 = script_pop();
            v86 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v86) <<= v85;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v86));
            }
            else if (v86 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v86) <<= v85;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v86));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v86) <<= v85;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v86));
            }
            continue;
        case 58:
            v87 = script_pop();
            v88 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v88) >>= v87;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v88));
            }
            else if (v88 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v88) >>= v87;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v88));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v88) >>= v87;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v88));
            }
            continue;
        case 59:
            v89 = script_pop();
            v90 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v90) &= v89;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v90));
            }
            else if (v90 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v90) &= v89;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v90));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v90) &= v89;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v90));
            }
            continue;
        case 60:
            v93 = script_pop();
            v94 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v94) |= v93;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v94));
            }
            else if (v94 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v94) |= v93;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v94));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v94) |= v93;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v94));
            }
            continue;
        case 61:
            v91 = script_pop();
            v92 = script_pop();
            if (script_pop())
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v92) ^= v91;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * v92));
            }
            else if (v92 < 0)
            {
                *(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v92) ^= v91;
                sub_507230(*(_DWORD*)(*(_DWORD*)(v3 + 760) - 4 * v92));
            }
            else
            {
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v92) ^= v91;
                sub_507230(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * v92));
            }
            continue;
        case 62:
            v135 = script_pop();
            sub_507230(v135 == 0);
            continue;
        case 63:
            v136 = script_pop();
            sub_507230(~v136);
            continue;
        case 64:
            v137 = script_pop();
            sub_507230(-v137);
            continue;
        case 65:
            v159 = -COERCE_FLOAT(script_pop());
            sub_507230(SLODWORD(v159));
            continue;
        case 66:
            v119 = script_pop();
            v120 = script_pop();
            v121 = script_pop();
            v122 = script_pop();
            if (v119 < 0 || v119 >= v122)
                v161 = 1;
            if (v121)
            {
                v123 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * (v119 + v120));
            }
            else if (v120 < 0)
            {
                v123 = *(_DWORD*)(*(_DWORD*)(a3 + 760) + 4 * (v120 - v119));
            }
            else
            {
                v123 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * (v119 + v120));
            }
            sub_507230(v123);
            goto LABEL_198;
        case 67:
            v127 = script_pop();
            v128 = script_pop();
            v129 = script_pop();
            v130 = script_pop();
            if (v127 < 0 || v127 > v130)
                v161 = 1;
            if (v129)
            {
                sub_507230(COERCE_INT(*(float*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + 76) + 4 * (v127 + v128))));
            }
            else
            {
                if (v128 < 0)
                    v158 = *(int*)(*(_DWORD*)(a3 + 760) + 4 * (v128 - v127));
                else
                    v158 = *(int*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 28) + 4 * (v127 + v128));
                sub_507230(v158);
            }
            goto LABEL_198;
        case 68:
            v131 = script_pop();
            v132 = script_pop();
            v133 = script_pop();
            v134 = script_pop();
            if (v131 < 0 || v131 > v134)
                v161 = 1;
            sub_507230(v133);
            if (v132 < 0)
                sub_507230(v132 - v131);
            else
                sub_507230(v132 + v131);
        LABEL_198:
            if (v161)
                goto LABEL_199;
        LABEL_4:
            v3 = a3;
            continue;
        case 69:
            v138 = sub_507270((int**)& v160);
            if (sub_508B70(a1, v138) != 1)
                continue;
            goto LABEL_199;
        case 70:
            v139 = sub_507270((int**)& v160);
            sub_507310(v139, a2, v3);
            continue;
        case 73:
            v23 = script_pop();
            v24 = script_pop();
            nox_sprintf(
                v164,
                "%s%s",
                *(_DWORD*)& byte_5D4594[4 * v24 + 3831212],
                *(_DWORD*)& byte_5D4594[4 * v23 + 3831212]);
            v25 = sub_512E40(v164);
            sub_507230(v25);
            continue;
        default:
        LABEL_199:
            v124 = v163;
            result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1599636] + v5 + 4);
            if (*(_DWORD*)& byte_5D4594[1599660] != result + v163)
            {
                if (result)
                {
                    if (*(_DWORD*)& byte_5D4594[1599660])
                    {
                        v126 = script_pop();
                        *(_DWORD*)& byte_5D4594[1599660] = v124;
                        result = sub_507230(v126);
                    }
                    else
                    {
                        *(_DWORD*)& byte_5D4594[1599660] = v163;
                        result = sub_507230(0);
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[1599660] = v163;
                }
            }
            return result;
        }
    }
}

//----- (00508B70) --------------------------------------------------------
int __cdecl sub_508B70(int a1, int a2)
{
    int v2; // ebx
    int result; // eax

    v2 = 48 * a1;
    if (!*(_DWORD*)(48 * a1 + *(_DWORD*)& byte_5D4594[1599636] + 36))
        return (*(int(__cdecl * *)()) & byte_587000[4 * a2 + 245900])();
    if (sub_508C30(a2))
        strcpy((char*)& byte_5D4594[3821644], *(const char**)(v2 + *(_DWORD*)& byte_5D4594[1599636] + 36));
    if (sub_508C70(a2))
    {
        *(_DWORD*)& byte_5D4594[3821636] = *(_DWORD*)(v2 + *(_DWORD*)& byte_5D4594[1599636] + 40);
        *(_DWORD*)& byte_5D4594[3821640] = *(_DWORD*)(v2 + *(_DWORD*)& byte_5D4594[1599636] + 44);
    }
    result = (*(int(__cdecl * *)()) & byte_587000[4 * a2 + 245900])();
    byte_5D4594[3821644] = byte_5D4594[1599672];
    *(_DWORD*)& byte_5D4594[3821640] = 0;
    *(_DWORD*)& byte_5D4594[3821636] = 0;
    return result;
}

//----- (00508C30) --------------------------------------------------------
int __cdecl sub_508C30(int a1)
{
    int v1; // eax
    unsigned __int8* i; // ecx

    v1 = 0;
    if (*(int*)& byte_587000[246800] <= 0)
        return 0;
    for (i = &byte_587000[246748]; *(_DWORD*)& byte_587000[4 * a1 + 245900] != *(_DWORD*)i; i += 4)
    {
        if (++v1 >= *(int*)& byte_587000[246800])
            return 0;
    }
    return 1;
}

//----- (00508C70) --------------------------------------------------------
int __cdecl sub_508C70(int a1)
{
    int v1; // eax
    unsigned __int8* i; // ecx

    v1 = 0;
    if (*(int*)& byte_587000[246768] <= 0)
        return 0;
    for (i = &byte_587000[246772]; *(_DWORD*)& byte_587000[4 * a1 + 245900] != *(_DWORD*)i; i += 4)
    {
        if (++v1 >= *(int*)& byte_587000[246768])
            return 0;
    }
    return 1;
}

//----- (00508CB0) --------------------------------------------------------
int __cdecl sub_508CB0(_DWORD* a1, int a2)
{
    int v2; // edi
    int result; // eax
    int v4; // ecx
    _DWORD* v5; // esi
    _DWORD* v6; // esi
    int v7; // esi
    _DWORD* v8; // esi

    v2 = a1[189];
    if (!v2)
        return 0;
    if (a2 == 14)
    {
        if (sub_40A5C0(6291456))
            result = v2;
        else
            result = *(_DWORD*)(48 * a1[192] + *(_DWORD*)& byte_5D4594[1599636]);
        return result;
    }
    v4 = a1[2];
    if (v4 & 0x200)
    {
        v5 = (_DWORD*)a1[187];
        if (a2)
        {
            if (a2 != 1)
            {
                if (a2 == 2)
                {
                    if (sub_40A5C0(6291456))
                        result = v2 + 384;
                    else
                        result = *(_DWORD*)(48 * v5[8] + *(_DWORD*)& byte_5D4594[1599636]);
                    return result;
                }
                return 0;
            }
            if (sub_40A5C0(6291456))
                result = v2 + 256;
            else
                result = *(_DWORD*)(48 * v5[6] + *(_DWORD*)& byte_5D4594[1599636]);
        }
        else if (sub_40A5C0(6291456))
        {
            result = v2 + 512;
        }
        else
        {
            result = *(_DWORD*)(48 * v5[4] + *(_DWORD*)& byte_5D4594[1599636]);
        }
    }
    else if (v4 & 2)
    {
        v6 = (_DWORD*)a1[187];
        switch (a2)
        {
        case 3:
            if (sub_40A5C0(6291456))
                result = v2 + 640;
            else
                result = *(_DWORD*)(48 * v6[309] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 4:
            if (sub_40A5C0(6291456))
                result = v2 + 768;
            else
                result = *(_DWORD*)(48 * v6[307] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 5:
            if (sub_40A5C0(6291456))
                result = v2 + 896;
            else
                result = *(_DWORD*)(48 * v6[317] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 6:
            if (sub_40A5C0(6291456))
                result = v2 + 1024;
            else
                result = *(_DWORD*)(48 * v6[311] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 7:
            if (sub_40A5C0(6291456))
                result = v2 + 1152;
            else
                result = *(_DWORD*)(48 * v6[313] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 8:
            if (sub_40A5C0(6291456))
                result = v2 + 1280;
            else
                result = *(_DWORD*)(48 * v6[315] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 9:
            if (sub_40A5C0(6291456))
                result = v2 + 1408;
            else
                result = *(_DWORD*)(48 * v6[319] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 10:
            if (sub_40A5C0(6291456))
                result = v2 + 1536;
            else
                result = *(_DWORD*)(48 * v6[321] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 11:
            if (sub_40A5C0(6291456))
                result = v2 + 1664;
            else
                result = *(_DWORD*)(48 * v6[323] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 13:
            if (sub_40A5C0(6291456))
                result = v2 + 1792;
            else
                result = *(_DWORD*)(48 * v6[325] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        default:
            return 0;
        }
    }
    else if (v4 & 0x800)
    {
        v7 = a1[175];
        if (a2 != 12)
            return 0;
        if (sub_40A5C0(6291456))
            result = v2 + 128;
        else
            result = *(_DWORD*)(48 * *(_DWORD*)(v7 + 4) + *(_DWORD*)& byte_5D4594[1599636]);
    }
    else
    {
        if (!(v4 & 0x20000))
            return 0;
        v8 = (_DWORD*)a1[187];
        switch (a2)
        {
        case 15:
            if (sub_40A5C0(6291456))
                result = v2 + 1920;
            else
                result = *(_DWORD*)(48 * v8[13] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 16:
            if (sub_40A5C0(6291456))
                result = v2 + 2048;
            else
                result = *(_DWORD*)(48 * v8[15] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 17:
            if (sub_40A5C0(6291456))
                result = v2 + 2304;
            else
                result = *(_DWORD*)(48 * v8[17] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        case 18:
            if (sub_40A5C0(6291456))
                result = v2 + 2176;
            else
                result = *(_DWORD*)(48 * v8[19] + *(_DWORD*)& byte_5D4594[1599636]);
            break;
        default:
            return 0;
        }
    }
    return result;
}

//----- (00509120) --------------------------------------------------------
void __cdecl sub_509120(_DWORD* a1, int a2, const char* a3)
{
    char* v3; // ebx
    int v4; // ecx
    _DWORD* v5; // esi
    char* v6; // edx
    _DWORD* v7; // esi
    int v8; // esi
    _DWORD* v9; // esi

    v3 = (char*)a1[189];
    if (v3)
    {
        if (a2 == 14)
        {
            if (sub_40A5C0(6291456))
                strcpy(v3, a3);
            else
                a1[192] = sub_5071D0(a3);
            return;
        }
        v4 = a1[2];
        if (v4 & 0x200)
        {
            v5 = (_DWORD*)a1[187];
            if (a2)
            {
                if (a2 == 1)
                {
                    if (!sub_40A5C0(6291456))
                    {
                        v5[6] = sub_5071D0(a3);
                        return;
                    }
                    v6 = v3 + 256;
                }
                else
                {
                    if (a2 != 2)
                        return;
                    if (!sub_40A5C0(6291456))
                    {
                        v5[8] = sub_5071D0(a3);
                        return;
                    }
                    v6 = v3 + 384;
                }
            }
            else
            {
                if (!sub_40A5C0(6291456))
                {
                    v5[4] = sub_5071D0(a3);
                    return;
                }
                v6 = v3 + 512;
            }
        LABEL_66:
            strcpy(v6, a3);
            return;
        }
        if (v4 & 2)
        {
            v7 = (_DWORD*)a1[187];
            switch (a2)
            {
            case 3:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 640;
                    goto LABEL_66;
                }
                v7[309] = sub_5071D0(a3);
                break;
            case 4:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 768;
                    goto LABEL_66;
                }
                v7[307] = sub_5071D0(a3);
                break;
            case 5:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 896;
                    goto LABEL_66;
                }
                v7[317] = sub_5071D0(a3);
                break;
            case 6:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1024;
                    goto LABEL_66;
                }
                v7[311] = sub_5071D0(a3);
                break;
            case 7:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1152;
                    goto LABEL_66;
                }
                v7[313] = sub_5071D0(a3);
                break;
            case 8:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1280;
                    goto LABEL_66;
                }
                v7[315] = sub_5071D0(a3);
                break;
            case 9:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1408;
                    goto LABEL_66;
                }
                v7[319] = sub_5071D0(a3);
                break;
            case 10:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1536;
                    goto LABEL_66;
                }
                v7[321] = sub_5071D0(a3);
                break;
            case 11:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1664;
                    goto LABEL_66;
                }
                v7[323] = sub_5071D0(a3);
                break;
            case 13:
                if (sub_40A5C0(6291456))
                {
                    v6 = v3 + 1792;
                    goto LABEL_66;
                }
                v7[325] = sub_5071D0(a3);
                break;
            default:
                return;
            }
        }
        else
        {
            if (v4 & 0x800)
            {
                v8 = a1[175];
                if (a2 != 12)
                    return;
                if (!sub_40A5C0(6291456))
                {
                    *(_DWORD*)(v8 + 4) = sub_5071D0(a3);
                    return;
                }
                v6 = v3 + 128;
                goto LABEL_66;
            }
            if (v4 & 0x20000)
            {
                v9 = (_DWORD*)a1[187];
                switch (a2)
                {
                case 15:
                    if (sub_40A5C0(6291456))
                    {
                        v6 = v3 + 1920;
                        goto LABEL_66;
                    }
                    v9[13] = sub_5071D0(a3);
                    break;
                case 16:
                    if (sub_40A5C0(6291456))
                    {
                        v6 = v3 + 2048;
                        goto LABEL_66;
                    }
                    v9[15] = sub_5071D0(a3);
                    break;
                case 17:
                    if (sub_40A5C0(6291456))
                    {
                        v6 = v3 + 2304;
                        goto LABEL_66;
                    }
                    v9[17] = sub_5071D0(a3);
                    break;
                case 18:
                    if (sub_40A5C0(6291456))
                    {
                        v6 = v3 + 2176;
                        goto LABEL_66;
                    }
                    v9[19] = sub_5071D0(a3);
                    break;
                default:
                    return;
                }
            }
        }
    }
}

//----- (005095E0) --------------------------------------------------------
int sub_5095E0()
{
    int v0; // ebp
    BOOL v1; // ebx
    int v2; // esi
    char* i; // eax
    int v4; // ecx
    int v5; // edi
    int v6; // ebp
    int v7; // eax
    int v8; // eax
    int result; // eax
    char* v10; // [esp+10h] [ebp-8h]
    int v11; // [esp+14h] [ebp-4h]

    v0 = 0;
    v11 = 0;
    v10 = 0;
    v1 = 0;
    v2 = 0x7FFFFFFF;
    for (i = sub_418B10(); i; i = sub_418B60((int)i))
    {
        v4 = *((_DWORD*)i + 13);
        if (v4 <= v2)
        {
            v1 = v4 == v2 && v0;
            v2 = *((_DWORD*)i + 13);
            v10 = i;
            v0 = (int)i;
        }
    }
    v5 = sub_4DA7C0();
    if (v5)
    {
        do
        {
            v6 = *(_DWORD*)(v5 + 748);
            if (!sub_419130(v5 + 48))
            {
                v7 = *(_DWORD*)(v6 + 276);
                if (!(*(_BYTE*)(v7 + 3680) & 1))
                {
                    v8 = *(_DWORD*)(v7 + 2140);
                    if (v8 <= v2)
                    {
                        v1 = v8 == v2 && v11;
                        v2 = v8;
                        v11 = v5;
                    }
                }
            }
            v5 = sub_4DA7F0(v5);
        } while (v5);
        v0 = (int)v10;
    }
    sub_40A4D0(8);
    if (v1)
        return sub_4D8BF0(0, 1);
    result = v11;
    if (v11)
        return sub_4D8B90(v11, 1);
    if (v0)
        result = sub_4D8BF0(v0, 1);
    return result;
}

//----- (005096F0) --------------------------------------------------------
int sub_5096F0()
{
    int result; // eax
    unsigned __int8* v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // esi
    int v5; // edi
    char v6[5]; // [esp+0h] [ebp-8h]

    result = sub_40A1A0();
    if (!result)
        return result;
    if (sub_40A5C0(4096))
    {
        v1 = sub_4E8E50();
        sub_4D2450((char*)v1);
        sub_4DA390("chklimit.c:AutoExitToNextMap");
        v2 = sub_4DA7C0();
        if (v2)
        {
            do
            {
                v3 = *(_DWORD*)(v2 + 748);
                if (!*(_DWORD*)(v3 + 312) && *(_DWORD*)(*(_DWORD*)(v3 + 276) + 4792) == 1)
                    sub_4D60E0(v2);
                v2 = sub_4DA7F0(v2);
            } while (v2);
            return sub_40A1F0(0);
        }
        return sub_40A1F0(0);
    }
    if (!sub_40A300())
    {
        if (sub_40A5C0(96))
        {
            sub_5099B0();
            return sub_40A1F0(0);
        }
        if (sub_40A5C0(272))
        {
            sub_5098A0();
            return sub_40A1F0(0);
        }
        if (sub_40A5C0(1024))
            sub_5095E0();
        return sub_40A1F0(0);
    }
    sub_40A4D0(0x4000000);
    v6[0] = -102;
    v4 = sub_4DA7C0();
    if (!v4)
        return sub_40A1F0(0);
    do
    {
        v5 = *(_DWORD*)(v4 + 748);
        if (v5)
        {
            *(_WORD*)& v6[1] = (__int64) * (float*)(*(_DWORD*)(v5 + 276) + 3632);
            *(_WORD*)& v6[3] = (__int64) * (float*)(*(_DWORD*)(v5 + 276) + 3636);
            sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 1, v6, 5);
        }
        sub_501960(582, v4, 2, *(_DWORD*)(v4 + 36));
        v4 = sub_4DA7F0(v4);
    } while (v4);
    return sub_40A1F0(0);
}

//----- (005098A0) --------------------------------------------------------
int sub_5098A0()
{
    int v0; // ebp
    BOOL v1; // ebx
    signed int v2; // esi
    char* i; // eax
    signed int v4; // ecx
    int v5; // edi
    int v6; // ebp
    int v7; // eax
    signed int v8; // eax
    int result; // eax
    char* v10; // [esp+10h] [ebp-8h]
    int v11; // [esp+14h] [ebp-4h]

    v0 = 0;
    v11 = 0;
    v10 = 0;
    v1 = 0;
    v2 = 2147483648;
    for (i = sub_418B10(); i; i = sub_418B60((int)i))
    {
        v4 = *((_DWORD*)i + 13);
        if (v4 >= v2)
        {
            v1 = v4 == v2 && v0;
            v2 = *((_DWORD*)i + 13);
            v10 = i;
            v0 = (int)i;
        }
    }
    v5 = sub_4DA7C0();
    if (v5)
    {
        do
        {
            v6 = *(_DWORD*)(v5 + 748);
            if (!sub_419130(v5 + 48))
            {
                v7 = *(_DWORD*)(v6 + 276);
                if (!(*(_BYTE*)(v7 + 3680) & 1))
                {
                    v8 = *(_DWORD*)(v7 + 2136);
                    if (v8 >= v2)
                    {
                        v1 = v8 == v2 && v11;
                        v2 = v8;
                        v11 = v5;
                    }
                }
            }
            v5 = sub_4DA7F0(v5);
        } while (v5);
        v0 = (int)v10;
    }
    sub_40A4D0(8);
    if (v1)
        return sub_4D8BF0(0, 1);
    result = v11;
    if (v11)
        return sub_4D8B90(v11, 1);
    if (v0)
        result = sub_4D8BF0(v0, 1);
    return result;
}

//----- (005099B0) --------------------------------------------------------
int sub_5099B0()
{
    int v0; // edi
    BOOL v1; // ebx
    int v2; // esi
    char* i; // eax
    int v4; // ecx
    int result; // eax

    v0 = 0;
    v1 = 0;
    v2 = -1;
    for (i = sub_418B10(); i; i = sub_418B60((int)i))
    {
        v4 = *((_DWORD*)i + 13);
        if (v4 >= v2)
        {
            v1 = v4 == v2 && v0;
            v2 = *((_DWORD*)i + 13);
            v0 = (int)i;
        }
    }
    sub_40A4D0(8);
    if (!v0 || v1)
    {
        if (sub_40A5C0(64))
            result = sub_4D8C40(0);
        else
            result = sub_4D8C80(0, 1);
    }
    else if (sub_40A5C0(64))
    {
        result = sub_4D8C40(v0);
    }
    else
    {
        result = sub_4D8C80(v0, 1);
    }
    return result;
}

//----- (00509A60) --------------------------------------------------------
char sub_509A60()
{
    char* v0; // eax
    __int16 v1; // ax
    int v2; // edi
    char* v3; // esi
    int v4; // esi
    int v5; // eax
    char* v6; // edi
    __int16 v7; // ax
    int v8; // ebp
    int v9; // ebx
    int i; // esi
    int v11; // eax

    if (sub_40A5C0(1024))
    {
        v6 = 0;
        v7 = sub_40A5B0();
        LOWORD(v0) = sub_40A020(v7);
        v8 = (unsigned __int16)v0;
        if ((int)(unsigned __int16)v0 >= 1)
        {
            v9 = 0;
            for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
            {
                v11 = *(_DWORD*)(*(_DWORD*)(i + 748) + 276);
                if (!(*(_BYTE*)(v11 + 3680) & 1) && *(_DWORD*)(v11 + 2140) < v8)
                {
                    v0 = (char*)sub_419130(i + 48);
                    if (v0)
                    {
                        if (v6)
                        {
                            v0 = sub_418AB0(*(unsigned __int8*)(i + 52));
                            if (v6 != v0)
                                return (char)v0;
                        }
                        else
                        {
                            v6 = sub_418AB0(*(unsigned __int8*)(i + 52));
                        }
                    }
                    else
                    {
                        if (v9 || v6)
                            return (char)v0;
                        v9 = i;
                    }
                }
            }
            v0 = sub_40A8A0();
            if (v0)
            {
                sub_40A4D0(8);
                if (v6)
                {
                    LOBYTE(v0) = sub_4D8BF0((int)v6, 0);
                }
                else if (v9)
                {
                    LOBYTE(v0) = sub_4D8B90(v9, 0);
                }
                else
                {
                    LOBYTE(v0) = sub_4D8B90(0, 0);
                }
            }
        }
    }
    else
    {
        v0 = (char*)sub_40A5C0(512);
        if (!v0)
        {
            v1 = sub_40A5B0();
            LOWORD(v0) = sub_40A020(v1);
            v2 = (unsigned __int16)v0;
            if ((_WORD)v0)
            {
                v3 = sub_418B10();
                if (v3)
                {
                    while (*((_DWORD*)v3 + 13) < v2)
                    {
                        v3 = sub_418B60((int)v3);
                        if (!v3)
                            goto LABEL_7;
                    }
                    sub_40A4D0(8);
                    LOBYTE(v0) = sub_4D8BF0((int)v3, 0);
                }
                else
                {
                LABEL_7:
                    v0 = (char*)sub_4DA7C0();
                    v4 = (int)v0;
                    if (v0)
                    {
                        while (1)
                        {
                            v5 = *(_DWORD*)(*(_DWORD*)(v4 + 748) + 276);
                            if (!(*(_BYTE*)(v5 + 3680) & 1) && *(_DWORD*)(v5 + 2136) >= v2)
                                break;
                            v0 = (char*)sub_4DA7F0(v4);
                            v4 = (int)v0;
                            if (!v0)
                                return (char)v0;
                        }
                        sub_40A4D0(8);
                        LOBYTE(v0) = sub_4D8B90(v4, 0);
                    }
                }
            }
        }
    }
    return (char)v0;
}
// 509BEA: variable 'v0' is possibly undefined

//----- (00509C30) --------------------------------------------------------
_DWORD* __cdecl sub_509C30(int a1)
{
    char* v1; // edx

    if (!*(_DWORD*)& byte_5D4594[1599688])
    {
        sub_425760(&byte_5D4594[1599676]);
        *(_DWORD*)& byte_5D4594[1599688] = 1;
    }
    v1 = (char*)nox_malloc(0x20u);
    *((_DWORD*)v1 + 6) = *(_DWORD*)(a1 + 2068);
    strcpy(v1 + 12, (const char*)(a1 + 2096));
    v1[28] = *(_BYTE*)(a1 + 2251);
    return sub_4257F0((int*)& byte_5D4594[1599676], v1);
}

//----- (00509CB0) --------------------------------------------------------
int* sub_509CB0()
{
    int* result; // eax
    int* v1; // esi
    int* v2; // edi

    result = *(int**)& byte_5D4594[1599688];
    if (*(_DWORD*)& byte_5D4594[1599688])
    {
        result = sub_425890((int*)& byte_5D4594[1599676]);
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
    return result;
}

//----- (00509CF0) --------------------------------------------------------
int __cdecl sub_509CF0(const char* a1, char a2, int a3)
{
    int* v3; // edi

    v3 = sub_425890((int*)& byte_5D4594[1599676]);
    if (!v3)
        return 1;
    while (strcmp((const char*)v3 + 12, a1) || a2 == *((_BYTE*)v3 + 28) && a3 == v3[6])
    {
        v3 = sub_4258A0(v3);
        if (!v3)
            return 1;
    }
    return 0;
}

//----- (00509D80) --------------------------------------------------------
int __cdecl sub_509D80(int a1)
{
    int* v1; // edi

    v1 = sub_425890((int*)& byte_5D4594[1599676]);
    if (!v1)
        return 0;
    while (strcmp((const char*)v1 + 12, (const char*)(a1 + 2096)))
    {
        v1 = sub_4258A0(v1);
        if (!v1)
            return 0;
    }
    return 1;
}

//----- (00509E00) --------------------------------------------------------
int __cdecl sub_509E00(_DWORD* a1)
{
    return *(_DWORD*)& byte_587000[4 * (*a1 + 3 * a1[1]) + 230072];
}

//----- (00509E20) --------------------------------------------------------
int __cdecl sub_509E20(int a1, int2* a2)
{
    int v2; // ecx
    int v3; // ecx
    int result; // eax

    v2 = *(int*)& byte_587000[8 * a1 + 192088];
    if (v2 <= *(int*)& byte_587000[230092])
        a2->field_0 = (v2 >= -*(int*)& byte_587000[230092]) - 1;
    else
        a2->field_0 = 1;
    v3 = *(int*)& byte_587000[8 * a1 + 192092];
    result = *(_DWORD*)& byte_587000[230092];
    if (v3 <= *(int*)& byte_587000[230092])
    {
        result = -*(int*)& byte_587000[230092];
        if (v3 >= -*(int*)& byte_587000[230092])
            a2->field_4 = 0;
        else
            a2->field_4 = -1;
    }
    else
    {
        a2->field_4 = 1;
    }
    return result;
}

//----- (00509E90) --------------------------------------------------------
int __cdecl sub_509E90(int a1)
{
    return *(_DWORD*)& byte_587000[4 * a1 + 230056];
}

//----- (00509EA0) --------------------------------------------------------
int __cdecl sub_509EA0(int a1)
{
    int2 a2; // [esp+0h] [ebp-8h]

    sub_509E20(a1, &a2);
    return a2.field_4 + a2.field_0 + 2 * a2.field_4 + 4;
}

//----- (00509ED0) --------------------------------------------------------
int __cdecl sub_509ED0(float2* a1)
{
    int result; // eax
    float v2; // [esp+0h] [ebp-4h]

    v2 = (atan2(a1->field_4, a1->field_0) + 6.2831855) * 40.743664 + 0.5;
    result = sub_419A70(v2);
    if (result < 0)
        result += (unsigned int)(255 - result) >> 8 << 8;
    if (result >= 256)
        result += -256 * ((unsigned int)result >> 8);
    return result;
}

//----- (00509F20) --------------------------------------------------------
void __cdecl sub_509F20(float2* a1)
{
    double v1; // st7

    v1 = sub_419AF0(sqrt(a1->field_0 * a1->field_0 + a1->field_4 * a1->field_4));
    a1->field_0 = a1->field_0 / v1;
    a1->field_4 = a1->field_4 / v1;
}

//----- (00509F60) --------------------------------------------------------
void __cdecl sub_509F60(int a1, int a2)
{
    int v2; // esi
    char v3; // al
    int v5; // edi
    _DWORD* v6; // esi

    v2 = *(_DWORD*)(a1 + 748);
    sub_5341A0((char*)& byte_587000[233784], *(_DWORD*)& byte_5D4594[2598000], a2);
    v3 = *(_BYTE*)(v2 + 544);
    if (v3 == -1)
    {
        sub_5341A0((char*)& byte_587000[233804]);
        sub_5341A0((char*)& byte_587000[233832]);
    }
    else
    {
        if (v3 >= 0)
        {
            v5 = v3 + 1;
            v6 = (_DWORD*)(v2 + 8 * (3 * v3 + 69));
            do
            {
                sub_5341A0((char*)& byte_587000[233824], *(_DWORD*)& byte_587000[4 * *v6 + 230096]);
                v6 -= 6;
                --v5;
            } while (v5);
        }
        sub_5341A0((char*)& byte_587000[233832]);
    }
}

//----- (00509FF0) --------------------------------------------------------
int __cdecl sub_509FF0(int a1)
{
    int result; // eax

    result = a1;
    if (*(_BYTE*)(*(_DWORD*)a1 + 16) & 0x20)
        * (_DWORD*)a1 = 0;
    return result;
}

//----- (0050A010) --------------------------------------------------------
int __cdecl sub_50A010(int a1)
{
    int result; // eax

    result = a1 < 39;
    LOBYTE(result) = a1 > 39;
    return result;
}

//----- (0050A020) --------------------------------------------------------
int __cdecl sub_50A020(int a1)
{
    return *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23));
}

//----- (0050A040) --------------------------------------------------------
int __cdecl sub_50A040(int a1)
{
    int v1; // ebx
    int v2; // esi
    int* i; // edi
    int v4; // eax

    v1 = *(_DWORD*)(a1 + 748);
    v2 = *(char*)(v1 + 544) - 1;
    if (v2 < 0)
        return 38;
    for (i = (int*)(v1 + 8 * (3 * v2 + 69)); ; i -= 6)
    {
        v4 = sub_50A010(*i);
        if (!v4)
            break;
        if (--v2 < 0)
            return 38;
    }
    return *(_DWORD*)(v1 + 8 * (3 * v2 + 69));
}
// 50A06B: variable 'v4' is possibly undefined

//----- (0050A090) --------------------------------------------------------
int __cdecl sub_50A090(int a1, int a2)
{
    int v2; // ecx
    int v3; // eax
    _DWORD* i; // ecx

    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(char*)(v2 + 544) - 1;
    if (v3 < 0)
        return 0;
    for (i = (_DWORD*)(v2 + 8 * (3 * v3 + 69)); *i != a2; i -= 6)
    {
        if (--v3 < 0)
            return 0;
    }
    return 1;
}

//----- (0050A0D0) --------------------------------------------------------
int __cdecl sub_50A0D0(int a1, int a2)
{
    int v2; // ecx
    int v3; // eax
    _DWORD* i; // ecx

    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(char*)(v2 + 544);
    if (v3 < 0)
        return 0;
    for (i = (_DWORD*)(v2 + 8 * (3 * v3 + 69)); *i != a2; i -= 6)
    {
        if (--v3 < 0)
            return 0;
    }
    return 1;
}

//----- (0050A110) --------------------------------------------------------
int __cdecl sub_50A110(int a1)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 748);
    *(_BYTE*)(result + 481) = 0;
    *(_BYTE*)(result + 482) = 0;
    *(_BYTE*)(result + 483) = 0;
    *(_DWORD*)(result + 8) = 0;
    *(_DWORD*)(result + 268) = 0;
    *(_DWORD*)(result + 296) = 0;
    *(_DWORD*)(result + 364) = 0;
    *(_DWORD*)(result + 548) = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)(result + 496) = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (0050A160) --------------------------------------------------------
char __cdecl sub_50A160(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // eax
    char v4; // al
    _DWORD* v5; // edi
    int v6; // eax
    void(__cdecl * v7)(int); // eax
    char v8; // cl
    int v9; // edi
    int* v10; // ebp
    int v11; // eax
    char result; // al
    int v13; // [esp-Ch] [ebp-1Ch]
    int v14; // [esp-8h] [ebp-18h]
    int v15; // [esp-4h] [ebp-14h]

    v1 = *(_DWORD*)(a1 + 748);
    v2 = *(char*)(v1 + 544);
    v15 = v2;
    v14 = *(_DWORD*)& byte_587000[4 * *(_DWORD*)(v1 + 8 * (3 * v2 + 69)) + 230096];
    v13 = *(_DWORD*)(a1 + 36);
    v3 = sub_4E39D0(a1);
    sub_5341A0((char*)& byte_587000[233876], *(_DWORD*)& byte_5D4594[2598000], v3, v13, v14, v15);
    v4 = *(_BYTE*)(v1 + 544);
    if (v4 >= 0)
    {
        v5 = (_DWORD*)(v1 + 24 * (v4 + 23));
        v6 = sub_50A010(*(_DWORD*)(v1 + 24 * (v4 + 23)));
        if (!v6)
        {
            if (v5[5])
            {
                v7 = *(void(__cdecl * *)(int)) & byte_587000[16 * *v5 + 233168];
                if (v7)
                    v7(a1);
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1599692] = 1;
    v8 = *(_BYTE*)(v1 + 544) - 1;
    v9 = v8;
    *(_BYTE*)(v1 + 544) = v8;
    if (v8 >= 0)
    {
        v10 = (int*)(v1 + 8 * (3 * v8 + 69));
        do
        {
            v11 = sub_50A010(*v10);
            if (!v11)
                break;
            v10 -= 6;
            --v9;
            --* (_BYTE*)(v1 + 544);
        } while (v9 >= 0);
    }
    sub_50A110(a1);
    result = *(_BYTE*)(v1 + 544);
    if (result < 0)
    {
        *(_BYTE*)(v1 + 544) = 0;
        *(_DWORD*)(v1 + 552) = 0;
    }
    return result;
}
// 50A1CB: variable 'v6' is possibly undefined
// 50A21D: variable 'v11' is possibly undefined

//----- (0050A260) --------------------------------------------------------
int* __cdecl sub_50A260(int a1, int a2)
{
    int v2; // esi
    int* result; // eax
    char v4; // cl
    _DWORD* v5; // edi
    int v6; // eax
    void(__cdecl * v7)(int); // eax
    char v8; // al
    int* v9; // esi
    int v10; // eax
    int v11; // [esp-8h] [ebp-18h]
    int v12; // [esp-4h] [ebp-14h]

    v2 = *(_DWORD*)(a1 + 748);
    if (!(*(_BYTE*)(a1 + 8) & 2))
        return 0;
    v4 = *(_BYTE*)(v2 + 544);
    if (v4 == 23)
        return 0;
    if (v4 < 0)
        goto LABEL_19;
    if (*(_DWORD*)(v2 + 552) == 31 && a2 != 30)
        return 0;
    v5 = (_DWORD*)(v2 + 24 * (v4 + 23));
    if (*(_DWORD*)(v2 + 24 * (v4 + 23)) || v4)
    {
        v6 = sub_50A010(*(_DWORD*)(v2 + 24 * (v4 + 23)));
        if (!v6 && v5[5])
        {
            v7 = *(void(__cdecl * *)(int)) & byte_587000[16 * *v5 + 233172];
            if (v7)
                v7(a1);
        }
    }
    else
    {
    LABEL_19:
        *(_BYTE*)(v2 + 544) = -1;
    }
    v8 = *(_BYTE*)(v2 + 544) + 1;
    *(_BYTE*)(v2 + 544) = v8;
    v9 = (int*)(v2 + 24 * (v8 + 23));
    *v9 = a2;
    v9[5] = 0;
    sub_50A110(a1);
    v12 = *(_DWORD*)& byte_587000[4 * a2 + 230096];
    v11 = *(_DWORD*)(a1 + 36);
    v10 = sub_4E39D0(a1);
    sub_5341A0((char*)& byte_587000[233916], *(_DWORD*)& byte_5D4594[2598000], v10, v11, v12);
    result = v9;
    *(_DWORD*)& byte_5D4594[1599692] = 1;
    return result;
}
// 50A2CD: variable 'v6' is possibly undefined

//----- (0050A360) --------------------------------------------------------
int* __cdecl sub_50A360(int a1, int a2)
{
    int* result; // eax

    if (*(_BYTE*)(a1 + 8) & 2
        && *(_DWORD*)(*(_DWORD*)(a1 + 748) + 24 * (*(char*)(*(_DWORD*)(a1 + 748) + 544) + 23)) != a2)
    {
        result = sub_50A260(a1, a2);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0050A3A0) --------------------------------------------------------
void __cdecl sub_50A3A0(int a1)
{
    if (*(_BYTE*)(a1 + 8) & 2 && !sub_5341F0(a1))
    {
        do
            sub_50A160(a1);
        while (!sub_5341F0(a1));
    }
}

//----- (0050A3D0) --------------------------------------------------------
int __cdecl sub_50A3D0(_DWORD* a1)
{
    int v1; // ebx
    int i; // edi
    int result; // eax
    int v4; // ecx
    int v5; // eax
    int v6; // eax
    int v7; // ecx
    int v8; // edi
    int v9; // ecx
    int v10; // eax
    int v11; // eax
    int v12; // esi

    v1 = a1[187];
    if (sub_40A5C0(4096))
        sub_50E1E0((int)a1);
    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
    {
        if ((_DWORD*)sub_4DDF30(i) == a1)
            sub_4DDEF0(i);
    }
    sub_50A3A0((int)a1);
    sub_50A260((int)a1, 31);
    sub_50A260((int)a1, 30);
    result = sub_534A40((int)a1);
    if (!result)
    {
        v4 = a1[4];
        LOBYTE(v4) = v4 & 0x7F;
        a1[4] = v4;
        sub_4DA9F0(a1);
        sub_4FF580((int)a1);
        if ((signed char) * (_BYTE*)(v1 + 1440) >= 0)
        {
            if (!sub_40A5C0(4096))
                goto LABEL_13;
            v5 = sub_415FA0(5, 8);
        }
        else
        {
            v5 = sub_415FA0(10, 20);
        }
        sub_511660(a1, *(_DWORD*)& byte_5D4594[2649704] * v5);
    LABEL_13:
        v6 = a1[127];
        if (v6 && *(_BYTE*)(v6 + 8) & 4)
        {
            v7 = a1[3];
            v8 = *(_DWORD*)(v6 + 748);
            LOBYTE(v7) = v7 & 0x7F;
            a1[3] = v7;
            sub_4D9200(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)a1);
            sub_417300(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)a1, 1);
        }
        v9 = a1[3];
        BYTE1(v9) &= 0xFEu;
        a1[3] = v9;
        sub_4EC4B0((int)a1);
        sub_4EC300((int)a1);
        v10 = a1[3];
        if (!(v10 & 0x2000))
            sub_4EDA40(a1);
        if (!sub_40A5C0(2048) && *(_DWORD*)(v1 + 2188) == 2 && *(_DWORD*)(v1 + 2184) == 2)
        {
            if (a1[130])
            {
                v11 = sub_4EC580(a1[130]);
                if (*(_BYTE*)(v11 + 8) & 4)
                    sub_4FC0B0(v11, 1);
            }
        }
        result = sub_40A5C0(4096);
        if (result)
        {
            v12 = a1[130];
            if (v12)
            {
                result = sub_4EC580(v12);
                if (*(_BYTE*)(result + 8) & 4)
                    result = sub_4D6170(result);
            }
        }
    }
    return result;
}

//----- (0050A5C0) --------------------------------------------------------
int __cdecl sub_50A5C0(float a1)
{
    int v1; // esi
    int v2; // edi
    char v3; // al
    int v4; // eax
    int result; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    unsigned __int16* v9; // eax
    int v10; // ecx
    unsigned __int16 v11; // cx
    int v12; // ecx
    int v13; // eax
    int v14; // edx
    int v15; // ebp
    int v16; // edx
    _DWORD* v17; // eax
    void(__cdecl * v18)(int); // eax
    int v19; // ebx
    unsigned __int8 v20; // cl
    int v21; // [esp+14h] [ebp+4h]

    v1 = LODWORD(a1);
    v2 = *(_DWORD*)(LODWORD(a1) + 748);
    v3 = *(_BYTE*)(v2 + 2094);
    if (v3)
        * (_BYTE*)(v2 + 2094) = v3 - 1;
    v4 = *(_DWORD*)(v2 + 2192);
    if (v4 && *(_DWORD*)(v4 + 16) & 0x8020)
        * (_DWORD*)(v2 + 2192) = 0;
    sub_50A910(SLODWORD(a1));
    sub_50CDD0(SLODWORD(a1));
    result = *(_DWORD*)(LODWORD(a1) + 16);
    if (result & 0x1000000)
    {
        *(_DWORD*)& byte_5D4594[1599692] = 0;
        result = *(_DWORD*)(v2 + 484);
        if (result)
        {
            if (!(*(_DWORD*)(LODWORD(a1) + 16) & 0x8020))
            {
                v6 = *(_DWORD*)(v2 + 1440);
                if (v6 & 0x200)
                {
                    v7 = sub_424300(SLODWORD(a1));
                    if (v7)
                        sub_501960(*(_DWORD*)(v7 + 64), SLODWORD(a1), 0, 0);
                    sub_502490((int*)(v2 + 1248), *(_DWORD*)(LODWORD(a1) + 520), SLODWORD(a1));
                    sub_5341A0(
                        (char*)& byte_587000[234068],
                        *(_DWORD*)& byte_5D4594[2598000],
                        **(unsigned __int16**)(LODWORD(a1) + 556),
                        *(unsigned __int16*)(*(_DWORD*)(LODWORD(a1) + 556) + 4));
                }
                v8 = *(_DWORD*)(v2 + 520);
                if (v8 && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - v8) >= *(int*)& byte_5D4594[2649704])
                {
                    sub_532800(SLODWORD(a1));
                    *(_DWORD*)(v2 + 520) = 0;
                }
                sub_5469B0(SLODWORD(a1));
            }
            v9 = *(unsigned __int16**)(LODWORD(a1) + 556);
            if (v9)
            {
                v10 = *(_DWORD*)(LODWORD(a1) + 16);
                if ((v10 & 0x8000) == 0
                    && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(LODWORD(a1) + 536)) > * (int*)& byte_5D4594[2649704])
                {
                    v11 = v9[2];
                    if (*v9 < v11
                        && v11
                        && !(*(_DWORD*)& byte_5D4594[2598000] % (180 * *(_DWORD*)& byte_5D4594[2649704] / (unsigned int)v9[2])))
                    {
                        sub_4EE460(SLODWORD(a1), 1);
                    }
                }
            }
            sub_5281F0(a1);
            sub_547210(SLODWORD(a1));
            sub_546A70(SLODWORD(a1));
            sub_50A850(SLODWORD(a1));
            v12 = *(_DWORD*)& byte_5D4594[1599692];
            v21 = *(_DWORD*)& byte_5D4594[1599692];
            while (1)
            {
                v13 = *(char*)(v2 + 544);
                v14 = 3 * v13 + 69;
                v13 *= 3;
                v15 = *(_DWORD*)(v2 + 8 * v14);
                v16 = *(_DWORD*)(v2 + 8 * v13 + 572);
                v17 = (_DWORD*)(v2 + 8 * v13 + 572);
                if (v16)
                    break;
                *v17 = 1;
                *(_DWORD*)& byte_5D4594[1599692] = 0;
                v18 = *(void(__cdecl * *)(int)) & byte_587000[16 * v15 + 233160];
                if (v18)
                {
                    v18(v1);
                    v12 = *(_DWORD*)& byte_5D4594[1599692];
                    if (*(_DWORD*)& byte_5D4594[1599692])
                        continue;
                }
                goto LABEL_30;
            }
            if (v12)
                goto LABEL_31;
        LABEL_30:
            *(_DWORD*)& byte_5D4594[1599692] = v21;
        LABEL_31:
            (*(void(__cdecl * *)(int)) & byte_587000[16 * v15 + 233164])(v1);
            if (*(_DWORD*)& byte_5D4594[1599692])
                sub_509F60(v1, (int)& byte_587000[234084]);
            v19 = *(_DWORD*)(v2 + 1440);
            BYTE1(v19) &= 0xFDu;
            *(_DWORD*)(v2 + 1440) = v19;
            sub_421FF0(v1);
            v20 = *(_BYTE*)(v2 + 1128);
            if (v20 < 0x64u)
                * (_BYTE*)(v2 + 1128) = v20 + 0x64u / *(_DWORD*)& byte_5D4594[2649704];
            if (sub_534840(v1))
                sub_534950(v1);
            result = *(_DWORD*)& byte_5D4594[2649704];
            if (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 536) > (unsigned int)(3 * *(_DWORD*)& byte_5D4594[2649704]))
                * (_DWORD*)(v2 + 1440) &= 0xFFF7FFFF;
        }
    }
    return result;
}

//----- (0050A850) --------------------------------------------------------
char __cdecl sub_50A850(int a1)
{
    _BYTE* v1; // esi
    unsigned __int8* v2; // eax
    unsigned __int8 v3; // cl
    unsigned __int8 v4; // cl
    unsigned __int8 v5; // dl
    unsigned __int8 v6; // cl

    v1 = *(_BYTE * *)(a1 + 748);
    if (*(_BYTE*)(a1 + 12) & 0x10)
    {
        v2 = *(unsigned __int8**)& v1[24 * (char)v1[544] + 552];
        if (v2 == (unsigned __int8*)16 || v2 == (unsigned __int8*)17)
        {
            v1[483] = 0;
            return (char)v2;
        }
    }
    LOBYTE(v2) = v1[483];
    if (!(_BYTE)v2)
    {
        v2 = sub_533D00(a1);
        if (v2)
        {
            v1[480] = v2[9];
            if (!v2[9])
                goto LABEL_13;
            v3 = v1[482] + 1;
            v1[482] = v3;
            if (v3 >= v2[10] + 1)
            {
                v4 = v1[481];
                v1[482] = 0;
                v1[481] = ++v4;
                v5 = v4;
                v6 = v2[9];
                if (v5 >= v6)
                {
                    if (*((_DWORD*)v2 + 3))
                    {
                        v1[481] = 0;
                        return (char)v2;
                    }
                    v1[481] = v6 - 1;
                LABEL_13:
                    v1[483] = 1;
                    return (char)v2;
                }
            }
        }
    }
    return (char)v2;
}

//----- (0050A910) --------------------------------------------------------
int __cdecl sub_50A910(int a1)
{
    int v1; // ecx
    int v2; // eax
    int result; // eax
    _DWORD* v4; // esi
    int v5; // edi
    _DWORD* v6; // ebx
    int v7; // eax
    int v8; // eax
    int v9; // ecx
    int v10; // eax
    int v11; // ecx
    int v12; // [esp+0h] [ebp-8h]
    int v13; // [esp+4h] [ebp-4h]

    v1 = *(_DWORD*)(a1 + 748);
    v12 = v1;
    v2 = *(_DWORD*)(v1 + 1216);
    if (v2 && *(_DWORD*)(v2 + 16) & 0x8020)
        * (_DWORD*)(v1 + 1216) = 0;
    result = *(char*)(v1 + 544);
    if (result >= 0)
    {
        v4 = (_DWORD*)(v1 + 8 * (3 * result + 69));
        v13 = result + 1;
        while (1)
        {
            v5 = 0;
            if (*(_DWORD*)& byte_587000[16 * *v4 + 230388] > 0)
            {
                v6 = v4 + 1;
                do
                {
                    if (*(_DWORD*)& byte_587000[4 * (v5 + 4 * *v4) + 230392] == 1 && *v6)
                        sub_509FF0((int)v6);
                    ++v5;
                    v6 += 2;
                } while (v5 < *(int*)& byte_587000[16 * *v4 + 230388]);
                v1 = v12;
            }
            switch (*v4)
            {
            case 3:
                v7 = v4[3];
                if (v7)
                    goto LABEL_26;
                break;
            case 7:
            case 8:
                v10 = v4[3];
                if (v10)
                {
                    if (sub_5370E0(a1, v10, 0) || sub_50A0D0(a1, 3))
                    {
                        v7 = v4[3];
                        v11 = *(_DWORD*)(v7 + 56);
                        goto LABEL_27;
                    }
                    v4[3] = 0;
                }
                break;
            case 0xF:
                v7 = *(_DWORD*)(v1 + 1196);
                if (v7)
                {
                LABEL_26:
                    v11 = *(_DWORD*)(v7 + 56);
                LABEL_27:
                    v4[1] = v11;
                    v4[2] = *(_DWORD*)(v7 + 60);
                }
                break;
            case 0x11:
                v8 = v4[3];
                if (v8 && sub_5370E0(a1, v8, 0))
                {
                    v9 = v4[3];
                    v4[1] = *(_DWORD*)(v9 + 56);
                    v4[2] = *(_DWORD*)(v9 + 60);
                }
                break;
            default:
                break;
            }
            v4 -= 6;
            result = --v13;
            if (!v13)
                break;
            v1 = v12;
        }
    }
    return result;
}

//----- (0050AA90) --------------------------------------------------------
int __cdecl sub_50AA90(int a1)
{
    int v1; // edx
    int v2; // eax
    _DWORD* i; // ecx
    int v5; // esi

    v1 = *(_DWORD*)(a1 + 748);
    v2 = *(char*)(v1 + 544);
    if (v2 < 0)
        return 0;
    for (i = (_DWORD*)(v1 + 8 * (3 * v2 + 69)); *i != 3; i -= 6)
    {
        if (--v2 < 0)
            return 0;
    }
    v5 = v1 + 24 * v2 + 564;
    if (*(_DWORD*)v5)
        sub_509FF0(v5);
    return *(_DWORD*)v5;
}

//----- (0050AAE0) --------------------------------------------------------
int sub_50AAE0()
{
    int v0; // eax

    v0 = sub_4DA790();
    *(_DWORD*)& byte_5D4594[1599696] = v0;
    if (!v0)
        return 0;
    while (!(*(_BYTE*)(v0 + 8) & 2))
    {
        v0 = sub_4DA7A0(v0);
        *(_DWORD*)& byte_5D4594[1599696] = v0;
        if (!v0)
            return 0;
    }
    return v0 + 56;
}

//----- (0050AB10) --------------------------------------------------------
int sub_50AB10()
{
    int v0; // eax

    v0 = sub_4DA7A0(*(int*)& byte_5D4594[1599696]);
    *(_DWORD*)& byte_5D4594[1599696] = v0;
    if (!v0)
        return 0;
    while (!(*(_BYTE*)(v0 + 8) & 2))
    {
        v0 = sub_4DA7A0(v0);
        *(_DWORD*)& byte_5D4594[1599696] = v0;
        if (!v0)
            return 0;
    }
    return v0 + 56;
}

//----- (0050AB50) --------------------------------------------------------
__int16 __cdecl sub_50AB50(int a1, int a2)
{
    __int16 result; // ax

    if (a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256)
        result = 0;
    else
        result = *(_WORD*)& byte_5D4594[12 * (a2 + (a1 << 8)) + 1599724];
    return result;
}

//----- (0050AB90) --------------------------------------------------------
int sub_50AB90()
{
    int result; // eax

    result = nox_new_alloc_class("VisitNodes", 16, 1024);
    *(_DWORD*)& byte_5D4594[2386184] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[2386176] = nox_malloc(0x2000u);
        if (*(_DWORD*)& byte_5D4594[2386176])
        {
            *(_DWORD*)& byte_5D4594[2386172] = 0;
            result = 1;
        }
        else
        {
            nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386184]);
            result = 0;
        }
    }
    return result;
}

//----- (0050ABF0) --------------------------------------------------------
void sub_50ABF0()
{
    free(*(LPVOID*)& byte_5D4594[2386176]);
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386184]);
    *(_DWORD*)& byte_5D4594[2386184] = 0;
}

//----- (0050AC20) --------------------------------------------------------
int __cdecl sub_50AC20(int a3, _WORD* a2)
{
    unsigned __int16* v2; // ecx
    unsigned __int16 v3; // dx
    unsigned __int16 v4; // ax
    unsigned __int16 v5; // dx
    __int16 v6; // ax
    _DWORD* v7; // esi
    _WORD* v8; // edi
    int result; // eax
    int v10; // eax
    int v11; // esi
    int v12; // esi
    __int16 v13; // ax
    _WORD* v14; // edi
    __int16 v15; // ax
    _WORD* v16; // edi
    float v17; // [esp+0h] [ebp-18h]
    float v18; // [esp+0h] [ebp-18h]
    float v19; // [esp+0h] [ebp-18h]
    float v20; // [esp+0h] [ebp-18h]
    int v21; // [esp+Ch] [ebp-Ch]
    float2 a1; // [esp+10h] [ebp-8h]

    v2 = (unsigned __int16*)a3;
    v3 = *(_WORD*)(a3 + 2);
    a3 = *(unsigned __int16*)a3;
    v21 = v3;
    if (!(byte_5D4594[12 * (v3 + (a3 << 8)) + 1599724] & 0x3C))
        return 0;
    *(_DWORD*)& byte_5D4594[2386152] = 0;
    v4 = *v2;
    v5 = v2[1];
    a1.field_0 = (double)a3 * 23.0;
    v6 = *(_WORD*)& byte_5D4594[12 * (v5 + (v4 << 8)) + 1599724];
    a1.field_4 = (double)v21 * 23.0;
    if (v6 & 0x10)
    {
        a3 = 2048;
        sub_517B70(&a1, sub_50AE80, (int)& a3);
        if (*(_DWORD*)& byte_5D4594[2386152])
        {
            v7 = (_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 700) + 8);
            if (*(int*)(*(_DWORD*)& byte_5D4594[2386152] + 700) != -8)
            {
                if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 16) & 0x1000000)
                {
                    v8 = a2;
                    *a2 = (__int16) * (int*)v7 / 23;
                    result = 1;
                    v8[1] = (int)v7[1] / 23;
                    return result;
                }
            }
        }
        return 0;
    }
    if (v6 & 0x20)
    {
        a3 = 1024;
        sub_517B70(&a1, sub_50AE80, (int)& a3);
        v10 = *(_DWORD*)& byte_5D4594[2386152];
        if (!*(_DWORD*)& byte_5D4594[2386152])
            return 0;
        v11 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 748) + 12);
        goto LABEL_18;
    }
    if (v6 & 4)
    {
        a3 = 0x4000;
        sub_517B70(&a1, sub_50AE80, (int)& a3);
        if (*(_DWORD*)& byte_5D4594[2386152])
        {
            v12 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 748) + 4);
            if (v12)
            {
                if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 16) & 0x1000000)
                {
                    v17 = *(float*)(v12 + 56) * 0.043478262;
                    v13 = sub_419A70(v17);
                    v14 = a2;
                    *a2 = v13;
                    v18 = *(float*)(v12 + 60) * 0.043478262;
                    v14[1] = sub_419A70(v18);
                    return 1;
                }
            }
        }
        return 0;
    }
    if (v6 & 8)
    {
        a3 = 0x8000;
        sub_517B70(&a1, sub_50AE80, (int)& a3);
        v10 = *(_DWORD*)& byte_5D4594[2386152];
        if (*(_DWORD*)& byte_5D4594[2386152])
        {
            v11 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 748) + 4);
        LABEL_18:
            if (v11 && *(_DWORD*)(v10 + 16) & 0x1000000)
            {
                v19 = *(float*)(v11 + 56) * 0.043478262;
                v15 = sub_419A70(v19);
                v16 = a2;
                *a2 = v15;
                v20 = *(float*)(v11 + 60) * 0.043478262;
                v16[1] = sub_419A70(v20);
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

//----- (0050AE80) --------------------------------------------------------
void __cdecl sub_50AE80(int a1, int a2)
{
    if (*(_DWORD*)(a1 + 8) & *(_DWORD*)a2)
        * (_DWORD*)& byte_5D4594[2386152] = a1;
}

//----- (0050AEA0) --------------------------------------------------------
int __cdecl sub_50AEA0(int a1, float2* a2, _DWORD* a3)
{
    unsigned __int16* v3; // ecx
    unsigned __int16 v4; // dx
    unsigned __int16 v5; // ax
    unsigned __int16 v6; // dx
    __int16 v7; // ax
    int v9; // [esp+0h] [ebp-Ch]
    float2 a1a; // [esp+4h] [ebp-8h]

    v3 = (unsigned __int16*)a1;
    v4 = *(_WORD*)(a1 + 2);
    a1 = *(unsigned __int16*)a1;
    v9 = v4;
    if (!(byte_5D4594[12 * (v4 + (a1 << 8)) + 1599724] & 0x3C))
        return 0;
    *(_DWORD*)& byte_5D4594[2386152] = 0;
    v5 = *v3;
    v6 = v3[1];
    a1a.field_0 = (double)a1 * 23.0;
    v7 = *(_WORD*)& byte_5D4594[12 * (v6 + (v5 << 8)) + 1599724];
    a1a.field_4 = (double)v9 * 23.0;
    if (v7 & 0x10)
    {
        a1 = 2048;
    }
    else if (v7 & 0x20)
    {
        a1 = 1024;
    }
    else if (v7 & 4)
    {
        a1 = 0x4000;
    }
    else if (v7 & 8)
    {
        a1 = 0x8000;
    }
    sub_517B70(&a1a, sub_50AE80, (int)& a1);
    if (!*(_DWORD*)& byte_5D4594[2386152] || !(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 16) & 0x1000000))
        return 0;
    *a2 = *(float2*)(*(_DWORD*)& byte_5D4594[2386152] + 56);
    *a3 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2386152] + 36);
    return 1;
}

//----- (0050AFA0) --------------------------------------------------------
float* sub_50AFA0()
{
    int i; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // esi
    int v5; // eax
    int v6; // esi
    int v7; // eax
    int v8; // esi
    int v9; // eax
    int v10; // eax
    double v11; // st7
    int v12; // ebx
    int v13; // esi
    int v14; // eax
    int v15; // ecx
    unsigned __int8* v16; // ebp
    float* v17; // esi
    __int16 v18; // ax
    float* result; // eax
    float* k; // edi
    int v21; // esi
    int v22; // eax
    float v23; // [esp+0h] [ebp-3Ch]
    float v24; // [esp+0h] [ebp-3Ch]
    float v25; // [esp+0h] [ebp-3Ch]
    float v26; // [esp+0h] [ebp-3Ch]
    float v27; // [esp+0h] [ebp-3Ch]
    float v28; // [esp+0h] [ebp-3Ch]
    float v29; // [esp+0h] [ebp-3Ch]
    float v30; // [esp+0h] [ebp-3Ch]
    float v31; // [esp+0h] [ebp-3Ch]
    float v32; // [esp+0h] [ebp-3Ch]
    float v33; // [esp+0h] [ebp-3Ch]
    float v34; // [esp+0h] [ebp-3Ch]
    float v35; // [esp+4h] [ebp-38h]
    float v36; // [esp+4h] [ebp-38h]
    int j; // [esp+14h] [ebp-28h]
    int v38; // [esp+18h] [ebp-24h]
    int v39; // [esp+1Ch] [ebp-20h]
    int v40; // [esp+20h] [ebp-1Ch]
    float v41; // [esp+24h] [ebp-18h]
    float v42; // [esp+28h] [ebp-14h]
    float2 a2; // [esp+2Ch] [ebp-10h]
    int v44; // [esp+34h] [ebp-8h]

    *(_DWORD*)& byte_5D4594[2386160] = 0;
    memset(&byte_5D4594[1599716], 0, 0xC0000u);
    *(_DWORD*)& byte_5D4594[2386164] = 0;
    for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
    {
        sub_50B2C0(i);
        v1 = *(_DWORD*)(i + 8);
        if ((v1 & 0x80u) == 0)
        {
            if (v1 & 0x800)
            {
                v23 = *(float*)(i + 56) * 0.043478262;
                v2 = sub_419A70(v23);
                v24 = *(float*)(i + 60) * 0.043478262;
                v3 = sub_419A70(v24);
                byte_5D4594[12 * (v3 + (v2 << 8)) + 1599724] |= 0x10u;
            }
            else if (v1 & 0x400)
            {
                v25 = *(float*)(i + 56) * 0.043478262;
                v4 = sub_419A70(v25);
                v26 = *(float*)(i + 60) * 0.043478262;
                v5 = sub_419A70(v26);
                byte_5D4594[12 * (v5 + (v4 << 8)) + 1599724] |= 0x20u;
            }
            else if (v1 & 0x4000)
            {
                v27 = *(float*)(i + 56) * 0.043478262;
                v6 = sub_419A70(v27);
                v28 = *(float*)(i + 60) * 0.043478262;
                v7 = sub_419A70(v28);
                byte_5D4594[12 * (v7 + (v6 << 8)) + 1599724] |= 4u;
            }
            else if ((v1 & 0x8000) == 0)
            {
                if (!(*(_BYTE*)(i + 16) & 0x49))
                {
                    if (v1 & 0x400000)
                    {
                        v31 = *(float*)(i + 232) * 0.043478262;
                        v10 = sub_419A70(v31);
                        v11 = *(float*)(i + 236) * 0.043478262;
                        v12 = v10;
                        v44 = v10;
                        v32 = v11;
                        v13 = sub_419A70(v32);
                        v33 = *(float*)(i + 240) * 0.043478262;
                        v39 = sub_419A70(v33);
                        v34 = *(float*)(i + 244) * 0.043478262;
                        v14 = sub_419A70(v34);
                        v15 = v13;
                        v40 = v14;
                        for (j = v13; v15 <= v14; j = v15)
                        {
                            v38 = v12;
                            if (v12 <= v39)
                            {
                                v16 = &byte_5D4594[12 * (v15 + (v12 << 8)) + 1599724];
                                do
                                {
                                    v17 = (float*)& byte_587000[234108];
                                    while (1)
                                    {
                                        v41 = (double)v38 * 23.0;
                                        a2.field_0 = v41 + *(v17 - 1);
                                        v42 = (double)j * 23.0;
                                        a2.field_4 = v42 + *v17;
                                        if (sub_547DB0(i, &a2))
                                            break;
                                        v17 += 2;
                                        if ((int)v17 >= (int)& byte_587000[234180])
                                            goto LABEL_22;
                                    }
                                    v18 = *(_WORD*)v16;
                                    LOBYTE(v18) = *(unsigned __int16*)v16 | 1;
                                    *(_WORD*)v16 = v18;
                                    if (!(*(_BYTE*)(i + 16) & 0x10))
                                    {
                                        LOBYTE(v18) = v18 | 2;
                                        *(_WORD*)v16 = v18;
                                    }
                                LABEL_22:
                                    ++v12;
                                    v16 += 3072;
                                    v38 = v12;
                                } while (v12 <= v39);
                                v15 = j;
                                v14 = v40;
                                v12 = v44;
                            }
                            ++v15;
                        }
                    }
                }
            }
            else
            {
                v29 = *(float*)(i + 56) * 0.043478262;
                v8 = sub_419A70(v29);
                v30 = *(float*)(i + 60) * 0.043478262;
                v9 = sub_419A70(v30);
                byte_5D4594[12 * (v9 + (v8 << 8)) + 1599724] |= 8u;
            }
        }
    }
    result = (float*)sub_579860();
    for (k = result; result; k = result)
    {
        if (sub_579EE0((int)k, 0x80u))
        {
            v35 = k[2] * 0.043478262;
            v21 = sub_419A70(v35);
            v36 = k[3] * 0.043478262;
            v22 = sub_419A70(v36);
            *(_WORD*)& byte_5D4594[12 * (v22 + (v21 << 8)) + 1599724] |= 0x40u;
        }
        result = (float*)sub_579870((int)k);
    }
    return result;
}

//----- (0050B2C0) --------------------------------------------------------
int __cdecl sub_50B2C0(int a1)
{
    int v1; // ebp
    int result; // eax
    double v3; // st7
    int v4; // eax
    double v5; // st7
    int v6; // ebx
    int v7; // esi
    int v8; // eax
    int v9; // ecx
    unsigned __int8* v10; // edi
    float* v11; // esi
    int v12; // eax
    __int16 v13; // ax
    float v14; // [esp+0h] [ebp-74h]
    float v15; // [esp+0h] [ebp-74h]
    float v16; // [esp+0h] [ebp-74h]
    float v17; // [esp+0h] [ebp-74h]
    int v18; // [esp+14h] [ebp-60h]
    int v19; // [esp+18h] [ebp-5Ch]
    int v20; // [esp+1Ch] [ebp-58h]
    float v21; // [esp+20h] [ebp-54h]
    float v22; // [esp+24h] [ebp-50h]
    float2 a2; // [esp+28h] [ebp-4Ch]
    int v24; // [esp+30h] [ebp-44h]
    char v25[60]; // [esp+38h] [ebp-3Ch]
    int a1a; // [esp+78h] [ebp+4h]

    v1 = a1;
    result = *(_DWORD*)(a1 + 8);
    if (!(result & 0xC080)
        && (result & 0x2000 || !(*(_BYTE*)(a1 + 16) & 0x49))
        && (result & 0x2008 || *(_BYTE*)(a1 + 16) & 2))
    {
        if (result & 0x10000)
        {
            qmemcpy(v25, (const void*)(a1 + 172), sizeof(v25));
            if (*(_DWORD*)(a1 + 172) == 2)
            {
                v3 = *(float*)& byte_587000[234176] + *(float*)(a1 + 176);
                *(float*)(a1 + 176) = v3;
                *(float*)(a1 + 180) = v3 * v3;
            }
            else if (*(_DWORD*)(a1 + 172) == 3)
            {
                *(float*)(a1 + 184) = *(float*)& byte_587000[234176] + *(float*)& byte_587000[234176] + *(float*)(a1 + 184);
                *(float*)(a1 + 188) = *(float*)& byte_587000[234176] + *(float*)& byte_587000[234176] + *(float*)(a1 + 188);
                sub_428270((shape*)(a1 + 172));
            }
            sub_4E7290(a1);
        }
        v14 = *(float*)(a1 + 232) * 0.043478262;
        v4 = sub_419A70(v14);
        v5 = *(float*)(a1 + 236) * 0.043478262;
        v6 = v4;
        v24 = v4;
        v15 = v5;
        v7 = sub_419A70(v15);
        v16 = *(float*)(a1 + 240) * 0.043478262;
        v19 = sub_419A70(v16);
        v17 = *(float*)(a1 + 244) * 0.043478262;
        v8 = sub_419A70(v17);
        v9 = v7;
        v20 = v8;
        for (a1a = v7; v9 <= v8; a1a = v9)
        {
            v18 = v6;
            if (v6 <= v19)
            {
                v10 = &byte_5D4594[12 * (v9 + (v6 << 8)) + 1599724];
                do
                {
                    v11 = (float*)& byte_587000[234108];
                    while (1)
                    {
                        v21 = (double)v18 * 23.0;
                        a2.field_0 = v21 + *(v11 - 1);
                        v22 = (double)a1a * 23.0;
                        a2.field_4 = v22 + *v11;
                        if (sub_547DB0(v1, &a2))
                            break;
                        v11 += 2;
                        if ((int)v11 >= (int)& byte_587000[234180])
                            goto LABEL_25;
                    }
                    *((_DWORD*)v10 - 1) = *(_DWORD*)& byte_5D4594[2386164];
                    v12 = *(_DWORD*)(v1 + 8);
                    if (v12 & 8 || *(_BYTE*)(v1 + 16) & 2)
                    {
                        v13 = *(_WORD*)v10 | 0x100;
                        *(_WORD*)v10 = v13;
                        if (!(*(_BYTE*)(v1 + 16) & 0x10))
                        {
                            HIBYTE(v13) |= 2u;
                            *(_WORD*)v10 = v13;
                        }
                    }
                    else if (v12 & 0x2000)
                    {
                        v10[1] |= 4u;
                    }
                LABEL_25:
                    ++v6;
                    v10 += 3072;
                    v18 = v6;
                } while (v6 <= v19);
                v9 = a1a;
                v8 = v20;
                v6 = v24;
            }
            ++v9;
        }
        result = *(_DWORD*)(v1 + 8);
        if (result & 0x10000)
        {
            qmemcpy((void*)(v1 + 172), v25, 0x3Cu);
            result = sub_4E7290(v1);
        }
    }
    return result;
}

//----- (0050B500) --------------------------------------------------------
void sub_50B500()
{
    *(_DWORD*)& byte_5D4594[2386168] = 0;
}

//----- (0050B510) --------------------------------------------------------
int sub_50B510()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[2386168] = 0;
    *(_DWORD*)& byte_5D4594[2386172] = 0;
    return result;
}

//----- (0050B520) --------------------------------------------------------
int sub_50B520()
{
    int result; // eax
    int i; // esi

    result = *(_DWORD*)& byte_5D4594[2598000];
    if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[2386172]) >= 0xF)
    {
        *(_DWORD*)& byte_5D4594[2386172] = *(_DWORD*)& byte_5D4594[2598000];
        ++* (_DWORD*)& byte_5D4594[2386164];
        result = sub_4DA790();
        for (i = result; result; i = result)
        {
            sub_50B2C0(i);
            result = sub_4DA7A0(i);
        }
        *(_DWORD*)& byte_5D4594[2386168] = 1;
    }
    return result;
}

//----- (0050B580) --------------------------------------------------------
int __cdecl sub_50B580(int a1, float4* a3)
{
    float v2; // edx
    bool v3; // c0
    float v4; // edx
    float4 a1a; // [esp+0h] [ebp-10h]

    if (a3->field_0 >= (double)a3->field_8)
    {
        v2 = a3->field_0;
        a1a.field_0 = a3->field_8;
    }
    else
    {
        v2 = a3->field_8;
        a1a.field_0 = a3->field_0;
    }
    v3 = a3->field_4 < (double)a3->field_C;
    a1a.field_8 = v2;
    if (v3)
    {
        v4 = a3->field_C;
        a1a.field_4 = a3->field_4;
    }
    else
    {
        v4 = a3->field_4;
        a1a.field_4 = a3->field_C;
    }
    a1a.field_C = v4;
    *(_DWORD*)& byte_5D4594[2386156] = 1;
    *(_DWORD*)& byte_5D4594[2386148] = a1;
    sub_517C10(&a1a, (void(__cdecl*)(float*, int))sub_50B600, (int)a3);
    return *(_DWORD*)& byte_5D4594[2386156];
}

//----- (0050B600) --------------------------------------------------------
void __cdecl sub_50B600(float* arg0, float4* a1)
{
    int v2; // eax
    int v3; // eax
    double v4; // st6
    double v5; // st7
    double v6; // st7
    double v7; // st7
    double v8; // st7
    float v9; // [esp+10h] [ebp-30h]
    float v10; // [esp+14h] [ebp-2Ch]
    float v11; // [esp+1Ch] [ebp-24h]
    float v12; // [esp+20h] [ebp-20h]
    float v13; // [esp+24h] [ebp-1Ch]
    float2 a3; // [esp+28h] [ebp-18h]
    float4 a2; // [esp+30h] [ebp-10h]

    if (*(_DWORD*)& byte_5D4594[2386156] && *(float**)& byte_5D4594[2386148] != arg0)
    {
        v2 = *((_DWORD*)arg0 + 2);
        if (v2 & 6)
        {
            if (sub_5330C0(*(int*)& byte_5D4594[2386148], (int)arg0))
                return;
        }
        else if (!(v2 & 0x400008))
        {
            return;
        }
        if (!((_BYTE)arg0[4] & 0x48) && (signed char) * ((_BYTE*)arg0 + 8) >= 0)
        {
            v3 = *((_DWORD*)arg0 + 43);
            if (v3 == 2)
            {
                if (sub_57C8A0(a1, (float2*)arg0 + 7, &a3))
                {
                    v4 = a3.field_4 - arg0[15];
                    if (v4 * v4 + (a3.field_0 - arg0[14]) * (a3.field_0 - arg0[14]) <= arg0[45])
                        * (_DWORD*)& byte_5D4594[2386156] = 0;
                }
            }
            else if (v3 == 3)
            {
                v12 = arg0[48] + arg0[14];
                v5 = arg0[49] + arg0[15];
                a2.field_0 = v12;
                v13 = v5;
                v6 = arg0[50] + arg0[14];
                a2.field_4 = v13;
                v9 = v6;
                v7 = arg0[51] + arg0[15];
                a2.field_8 = v9;
                v10 = v7;
                v8 = arg0[52] + arg0[14];
                a2.field_C = v10;
                v11 = arg0[53] + arg0[15];
                a3.field_0 = arg0[54] + arg0[14];
                a3.field_4 = arg0[55] + arg0[15];
                if (sub_427980(a1, &a2))
                {
                    *(_DWORD*)& byte_5D4594[2386156] = 0;
                }
                else
                {
                    a2.field_0 = v12;
                    a2.field_4 = v13;
                    a2.field_8 = v8;
                    a2.field_C = v11;
                    if (sub_427980(a1, &a2))
                        goto LABEL_22;
                    a2.field_0 = a3.field_0;
                    a2.field_4 = a3.field_4;
                    a2.field_8 = v8;
                    a2.field_C = v11;
                    if (sub_427980(a1, &a2)
                        || (a2.field_0 = a3.field_0, a2.field_4 = a3.field_4, a2.field_8 = v9, a2.field_C = v10, sub_427980(a1, &a2)))
                    {
                    LABEL_22:
                        *(_DWORD*)& byte_5D4594[2386156] = 0;
                    }
                }
            }
        }
    }
}

//----- (0050B810) --------------------------------------------------------
BOOL __cdecl sub_50B810(int a1, float* a2)
{
    int v2; // esi
    int v3; // edi
    BOOL result; // eax
    float v5; // [esp+0h] [ebp-10h]
    float v6; // [esp+0h] [ebp-10h]

    v5 = *a2 * 0.043478262;
    v2 = sub_419A70(v5);
    v6 = a2[1] * 0.043478262;
    v3 = sub_419A70(v6);
    if (sub_50B870(a1, v2, v3))
        result = 0;
    else
        result = sub_50B8A0(a1, v2, v3);
    return result;
}

//----- (0050B870) --------------------------------------------------------
BOOL __cdecl sub_50B870(int a1, int a2, int a3)
{
    return sub_57B630(a1, a2, a3) != -1;
}

//----- (0050B8A0) --------------------------------------------------------
BOOL __cdecl sub_50B8A0(int a1, int a2, int a3)
{
    BOOL result; // eax

    if (sub_50B950(a1, a2, a3))
        result = 0;
    else
        result = sub_50B8E0(a1, a2, a3) == 0;
    return result;
}

//----- (0050B8E0) --------------------------------------------------------
unsigned int __cdecl sub_50B8E0(int a1, int a2, int a3)
{
    int v3; // esi
    unsigned int v4; // eax
    int v5; // ecx
    unsigned int result; // eax

    v3 = 12 * (a3 + (a2 << 8));
    if (*(_DWORD*)& byte_5D4594[v3 + 1599720] != *(_DWORD*)& byte_5D4594[2386164])
        goto LABEL_12;
    HIWORD(v4) = HIWORD(a1);
    v5 = *(_DWORD*)(a1 + 16);
    if (v5 & 0x4000)
    {
        LOWORD(v4) = *(_WORD*)& byte_5D4594[v3 + 1599724];
        return (v4 >> 9) & 1;
    }
    if (byte_5D4594[v3 + 1599725] & 1)
        return 1;
    if (sub_534020(a1) || !(byte_5D4594[v3 + 1599725] & 4))
        LABEL_12:
    result = 0;
    else
        result = 1;
    return result;
}

//----- (0050B950) --------------------------------------------------------
int __cdecl sub_50B950(int a1, int a2, int a3)
{
    int v3; // ecx
    int result; // eax

    v3 = *(_DWORD*)(a1 + 16);
    if (v3 & 0x4000)
        result = (byte_5D4594[12 * (a3 + (a2 << 8)) + 1599724] >> 1) & 1;
    else
        result = byte_5D4594[12 * (a3 + (a2 << 8)) + 1599724] & 1;
    return result;
}

//----- (0050B9A0) --------------------------------------------------------
int __cdecl sub_50B9A0(int a1, int a2, int a3, float* a4)
{
    *(_BYTE*)(*(_DWORD*)(a3 + 748) + 2172) = 0;
    sub_50BA00(0, a3, (float*)(a3 + 56), a4, 0, 0);
    if (*(_DWORD*)& byte_5D4594[2386180] > a2 && !*(_DWORD*)& byte_5D4594[1599712])
        * (_DWORD*)& byte_5D4594[1599712] = 1;
    return sub_50C990(a1, 0, a2);
}

//----- (0050BA00) --------------------------------------------------------
LPVOID __cdecl sub_50BA00(int a1, int a2, float* a3, float* a4, int(__cdecl* a5)(int, int, int), int a6)
{
    int v6; // eax
    double v7; // st7
    int v8; // eax
    double v9; // st7
    LPVOID result; // eax
    unsigned __int16* v11; // eax
    unsigned __int16 v12; // cx
    unsigned __int16 v13; // dx
    unsigned __int16* v14; // ebx
    unsigned __int16* v15; // esi
    int v16; // edx
    int v17; // edi
    int v18; // eax
    int v19; // edi
    int v20; // edx
    int v21; // ecx
    unsigned __int16 v22; // bp
    int v23; // ebp
    int v24; // ebx
    unsigned __int16 v25; // ax
    int v26; // ecx
    float v27; // edx
    float v28; // eax
    int v29; // ecx
    int v30; // edi
    _WORD* v31; // eax
    unsigned __int16* v32; // eax
    unsigned __int16* v33; // ebp
    unsigned __int16* v34; // esi
    unsigned __int16* v35; // edi
    int v36; // eax
    int v37; // eax
    bool v38; // zf
    int v39; // eax
    int v40; // eax
    int v41; // eax
    int v42; // eax
    BOOL v43; // eax
    int v44; // eax
    unsigned __int16* v45; // esi
    unsigned __int16* v46; // edi
    int v47; // [esp-4h] [ebp-70h]
    int v48; // [esp-4h] [ebp-70h]
    int v49; // [esp-4h] [ebp-70h]
    int v50; // [esp-4h] [ebp-70h]
    float v51; // [esp+0h] [ebp-6Ch]
    float v52; // [esp+0h] [ebp-6Ch]
    float v53; // [esp+0h] [ebp-6Ch]
    float v54; // [esp+0h] [ebp-6Ch]
    int v55; // [esp+0h] [ebp-6Ch]
    int v56; // [esp+0h] [ebp-6Ch]
    int v57; // [esp+0h] [ebp-6Ch]
    int v58; // [esp+0h] [ebp-6Ch]
    int v59; // [esp+14h] [ebp-58h]
    char v60; // [esp+18h] [ebp-54h]
    int v61; // [esp+1Ch] [ebp-50h]
    int i; // [esp+20h] [ebp-4Ch]
    BOOL v63; // [esp+24h] [ebp-48h]
    int v64; // [esp+28h] [ebp-44h]
    int v65; // [esp+2Ch] [ebp-40h]
    int v66; // [esp+30h] [ebp-3Ch]
    int v67; // [esp+34h] [ebp-38h]
    __int16 v68[2]; // [esp+38h] [ebp-34h]
    int v69; // [esp+3Ch] [ebp-30h]
    int v70; // [esp+40h] [ebp-2Ch]
    unsigned __int8* v71; // [esp+44h] [ebp-28h]
    unsigned __int8* v72; // [esp+48h] [ebp-24h]
    int v73; // [esp+4Ch] [ebp-20h]
    int v74; // [esp+50h] [ebp-1Ch]
    int2 a2a; // [esp+54h] [ebp-18h]
    float4 v76; // [esp+5Ch] [ebp-10h]
    unsigned __int16* v77; // [esp+78h] [ebp+Ch]

    v67 = 0;
    v64 = 0;
    v65 = 0;
    v59 = a1 != 0 ? 0 : 999999;
    *(_DWORD*)& byte_5D4594[1599712] = 0;
    ++* (_DWORD*)& byte_5D4594[2386160];
    if (!*(_DWORD*)& byte_5D4594[2386168])
        sub_50B520();
    v51 = *a3 * 0.043478262;
    v6 = sub_419A70(v51);
    v7 = a3[1] * 0.043478262;
    a2a.field_0 = v6;
    v52 = v7;
    a2a.field_4 = sub_419A70(v52);
    sub_50C8D0(a2, &a2a);
    v61 = 0;
    v63 = !sub_50B8A0(a2, a2a.field_0, a2a.field_4);
    if (a5 && !a5(a2, a2a.field_0, a2a.field_4))
        v61 = 1;
    v53 = *a4 * 0.043478262;
    v8 = sub_419A70(v53);
    v9 = a4[1] * 0.043478262;
    v73 = v8;
    v54 = v9;
    v74 = sub_419A70(v54);
    result = *(LPVOID*)& byte_5D4594[2386184];
    if (!*(_DWORD*)& byte_5D4594[2386184])
    {
        *(_DWORD*)& byte_5D4594[2386180] = 0;
        *(_DWORD*)& byte_5D4594[1599712] = 2;
        return result;
    }
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386184]);
    v11 = (unsigned __int16*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386184]);
    *v11 = a2a.field_0;
    v11[1] = a2a.field_4;
    v12 = *v11;
    v13 = v11[1];
    *((_DWORD*)v11 + 1) = 0;
    *((_DWORD*)v11 + 2) = 0;
    v14 = v11;
    v66 = 0;
    *(_DWORD*)& byte_5D4594[12 * (v13 + (v12 << 8)) + 1599716] = *(_DWORD*)& byte_5D4594[2386160];
    while (2)
    {
        v15 = v14;
        v14 = 0;
        v77 = 0;
        if (!v15)
            goto LABEL_40;
        while (2)
        {
            v16 = *v15;
            v17 = v15[1];
            v18 = ((unsigned __int16)v16 - v73) * ((unsigned __int16)v16 - v73)
                + ((unsigned __int16)v17 - v74) * ((unsigned __int16)v17 - v74);
            if (a1)
            {
                if (v18 > v59)
                {
                    v67 = (int)v15;
                    v59 = ((unsigned __int16)v16 - v73) * ((unsigned __int16)v16 - v73)
                        + ((unsigned __int16)v17 - v74) * ((unsigned __int16)v17 - v74);
                }
            }
            else
            {
                if (v18 < v59)
                {
                    v67 = (int)v15;
                    v59 = ((unsigned __int16)v16 - v73) * ((unsigned __int16)v16 - v73)
                        + ((unsigned __int16)v17 - v74) * ((unsigned __int16)v17 - v74);
                }
                if (!v63 && !v61 && v16 == v73 && v17 == v74)
                {
                    *(_DWORD*)& byte_5D4594[1599712] = 0;
                    return (LPVOID)sub_50C320(a2, (int)v15, a4);
                }
            }
            v69 = sub_415FA0(0, 7);
            for (i = 0; i < 8; ++i)
            {
                v19 = (i + v69) % 8;
                v20 = *(_DWORD*)& byte_587000[8 * v19 + 234216];
                v21 = *(_DWORD*)& byte_587000[8 * v19 + 234220];
                v22 = *v15;
                v72 = &byte_587000[8 * v19 + 234216];
                v23 = v20 + v22;
                v24 = v21 + v15[1];
                v71 = &byte_587000[8 * v19 + 234220];
                if (v23 < 0
                    || v23 >= 256
                    || v24 < 0
                    || v24 >= 256
                    || *(_DWORD*)& byte_5D4594[12 * (v24 + (v23 << 8)) + 1599716] == *(_DWORD*)& byte_5D4594[2386160])
                {
                    continue;
                }
                *(_DWORD*)& byte_5D4594[12 * (v24 + (v23 << 8)) + 1599716] = *(_DWORD*)& byte_5D4594[2386160];
                if (v23 == v73 && v24 == v74)
                {
                    v25 = v15[1];
                    v70 = 23 * *v15 + 11;
                    v76.field_0 = (double)v70;
                    v26 = 23 * v25;
                    v27 = *a4;
                    v28 = a4[1];
                    v70 = v26 + 11;
                    v76.field_8 = v27;
                    v76.field_4 = (double)(v26 + 11);
                    v76.field_C = v28;
                    if (sub_50B580(a2, &v76))
                    {
                        v29 = *(_DWORD*)(a2 + 16);
                        if (v29 & 0x4000)
                        {
                            if (sub_535250(&v76, 0, 0, 5))
                                goto LABEL_31;
                        }
                        else if (sub_535250(&v76, 0, 0, 1))
                        {
                        LABEL_31:
                            v30 = a2;
                            goto LABEL_32;
                        }
                    }
                }
                if (v19 < 4)
                {
                    v30 = a2;
                }
                else
                {
                    v60 = ~(*(_WORD*)(a2 + 16) >> 8) & 0xD8 | 0x98;
                    sub_57B4D0(a2);
                    switch (v19)
                    {
                    case 4:
                        v36 = (unsigned __int8)sub_57B500(*v15, v15[1] + 1, v60);
                        if (v36 != 1 && v36 != 6 && v36 != 10 && v36 != 9 && v36 != 255)
                            continue;
                        LOBYTE(v37) = sub_57B500(*v15 + 1, v15[1], v60);
                        goto LABEL_54;
                    case 5:
                        v39 = (unsigned __int8)sub_57B500(*v15 - 1, v15[1], v60);
                        if (v39 != 1 && v39 != 6 && v39 != 10 && v39 != 9 && v39 != 255)
                            continue;
                        LOBYTE(v37) = sub_57B500(*v15, v15[1] - 1, v60);
                    LABEL_54:
                        v37 = (unsigned __int8)v37;
                        if ((unsigned __int8)v37 == 1 || v37 == 4 || v37 == 7)
                            goto LABEL_86;
                        v38 = v37 == 8;
                        break;
                    case 6:
                        v40 = (unsigned __int8)sub_57B500(*v15, v15[1] + 1, v60);
                        if (v40 && v40 != 5 && v40 != 9 && v40 != 8 && v40 != 255)
                            continue;
                        v37 = (unsigned __int8)sub_57B500(*v15 - 1, v15[1], v60);
                        if (!v37 || v37 == 3 || v37 == 10)
                            goto LABEL_86;
                        v38 = v37 == 7;
                        break;
                    case 7:
                        v41 = (unsigned __int8)sub_57B500(*v15 + 1, v15[1], v60);
                        if (v41 && v41 != 5 && v41 != 9 && v41 != 8 && v41 != 255)
                            continue;
                        v42 = (unsigned __int8)sub_57B500(*v15, v15[1] - 1, v60);
                        if (v42)
                        {
                            if (v42 != 3 && v42 != 10 && v42 != 7 && v42 != 255)
                                continue;
                        }
                        goto LABEL_86;
                    default:
                        goto LABEL_86;
                    }
                    if (!v38 && v37 != 255)
                        continue;
                LABEL_86:
                    v30 = a2;
                    if (sub_50B950(a2, *v15, *(_DWORD*)v71 + v15[1]) || sub_50B950(a2, *(_DWORD*)v72 + *v15, v15[1]))
                        continue;
                }
                if (sub_50B870(v30, v23, v24))
                    continue;
                if (v73 != v23 || v74 != v24)
                {
                    if (!sub_50C830(v30, v23, v24))
                        continue;
                }
                else if (!sub_50C830(v30, v23, v24))
                {
                    continue;
                }
                v43 = sub_50B8A0(v30, v23, v24);
                if (v63)
                {
                    if (v43)
                    {
                        v64 = 1;
                    }
                    else if (!sub_50B950(v30, *v15, v15[1]) && sub_50B950(v30, v23, v24))
                    {
                        continue;
                    }
                }
                else
                {
                    if (!v43)
                        continue;
                    if (a5)
                    {
                        v44 = a5(v30, v23, v24);
                        if (v61)
                        {
                            if (v44)
                                v65 = 1;
                        }
                        else if (!v44)
                        {
                            continue;
                        }
                    }
                }
            LABEL_32:
                v31 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386184]);
                if (!v31)
                {
                    v55 = *(_DWORD*)(v30 + 36);
                    v47 = sub_4E39D0(v30);
                    sub_5341A0((char*)& byte_587000[234404], *(_DWORD*)& byte_5D4594[2598000], v47, v55);
                LABEL_130:
                    *(_DWORD*)& byte_5D4594[1599712] = 1;
                    return (LPVOID)sub_50C320(v30, v67, 0);
                }
                *v31 = v23;
                v31[1] = v24;
                *((_DWORD*)v31 + 1) = v15;
                *((_DWORD*)v31 + 2) = v77;
                v77 = v31;
            }
            if (!sub_50AC20((int)v15, v68))
                goto LABEL_38;
            *((_BYTE*)v15 + 12) |= 2u;
            v32 = (unsigned __int16*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386184]);
            if (!v32)
            {
                v30 = a2;
                v56 = *(_DWORD*)(a2 + 36);
                v48 = sub_4E39D0(a2);
                sub_5341A0((char*)& byte_587000[234456], *(_DWORD*)& byte_5D4594[2598000], v48, v56);
                goto LABEL_130;
            }
            *(_DWORD*)v32 = *(_DWORD*)v68;
            *((_DWORD*)v32 + 1) = v15;
            *((_DWORD*)v32 + 2) = v77;
            v77 = v32;
        LABEL_38:
            v15 = (unsigned __int16*) * ((_DWORD*)v15 + 2);
            if (v15)
                continue;
            break;
        }
        v14 = v77;
    LABEL_40:
        v33 = 0;
        if (v64)
        {
            v34 = v14;
            if (v14)
            {
                do
                {
                    v35 = (unsigned __int16*) * ((_DWORD*)v34 + 2);
                    if (sub_50B8A0(a2, *v34, v34[1]))
                    {
                        v33 = v34;
                    }
                    else if (v33)
                    {
                        *((_DWORD*)v33 + 2) = *((_DWORD*)v34 + 2);
                    }
                    else
                    {
                        v14 = (unsigned __int16*) * ((_DWORD*)v34 + 2);
                    }
                    v34 = v35;
                } while (v35);
                v33 = 0;
            }
            v63 = 0;
            v64 = 0;
        }
        if (v65)
        {
            v45 = v14;
            if (v14)
            {
                do
                {
                    v46 = (unsigned __int16*) * ((_DWORD*)v45 + 2);
                    if (a5(a2, *v45, v45[1]))
                    {
                        v33 = v45;
                    }
                    else if (v33)
                    {
                        *((_DWORD*)v33 + 2) = *((_DWORD*)v45 + 2);
                    }
                    else
                    {
                        v14 = (unsigned __int16*) * ((_DWORD*)v45 + 2);
                    }
                    v45 = v46;
                } while (v46);
            }
            v61 = 0;
            v65 = 0;
        }
        if (v14)
        {
            if (a6 && v66 >= a6)
            {
                v58 = *(_DWORD*)(a2 + 36);
                v50 = sub_4E39D0(a2);
                sub_5341A0((char*)& byte_587000[234556], *(_DWORD*)& byte_5D4594[2598000], v50, v58);
                goto LABEL_134;
            }
            ++v66;
            continue;
        }
        break;
    }
    v57 = *(_DWORD*)(a2 + 36);
    v49 = sub_4E39D0(a2);
    sub_5341A0((char*)& byte_587000[234508], *(_DWORD*)& byte_5D4594[2598000], v49, v57);
LABEL_134:
    v30 = a2;
    *(_DWORD*)& byte_5D4594[1599712] = 2;
    return (LPVOID)sub_50C320(v30, v67, 0);
}

//----- (0050C320) --------------------------------------------------------
int __cdecl sub_50C320(int a1, int a2, _DWORD* a3)
{
    int result; // eax
    unsigned __int16* v4; // edi
    int v5; // esi
    _DWORD* v6; // eax
    unsigned __int16* v7; // esi
    int v8; // ebp
    int v9; // eax
    char v10; // cl
    int v11; // ebx
    int v12; // ecx
    unsigned __int16 v13; // ax
    int v14; // edx
    unsigned __int16 v15; // ax
    int v16; // ecx
    unsigned __int16 v17; // ax
    double v18; // st7
    double v19; // st7
    double v20; // st7
    int v21; // ecx
    _DWORD* v22; // eax
    _DWORD* v23; // edx
    int v24; // eax
    int v25; // [esp+Ch] [ebp-1Ch]
    float2 v26; // [esp+10h] [ebp-18h]
    float4 v27; // [esp+18h] [ebp-10h]

    result = a1;
    v4 = (unsigned __int16*)a2;
    v5 = *(_DWORD*)(a1 + 748);
    v25 = *(_DWORD*)(a1 + 748);
    if (!a2)
    {
        *(_DWORD*)& byte_5D4594[2386180] = 0;
        return result;
    }
    v6 = a3;
    if (a3)
    {
        **(_DWORD * *)& byte_5D4594[2386176] = *a3;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[2386176] + 4) = v6[1];
    }
    else if (*(_BYTE*)(a2 + 12) & 2 && sub_50AEA0(a2, &v26, &a1))
    {
        **(float**)& byte_5D4594[2386176] = v26.field_0;
        *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 4) = v26.field_4;
        if (*(_BYTE*)(v5 + 2172) < 8u)
            * (_DWORD*)(v5 + 4 * (unsigned __int8)(*(_BYTE*)(v5 + 2172))++ + 2140) = a1;
    }
    else
    {
        a2 = *v4;
        **(float**)& byte_5D4594[2386176] = (double)a2 * 23.0 + 11.5;
        a2 = v4[1];
        *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 4) = (double)a2 * 23.0 + 11.5;
    }
    v7 = (unsigned __int16*) * ((_DWORD*)v4 + 1);
    v8 = 1;
    if (v7)
    {
        while (1)
        {
            v9 = *v7 - *v4;
            v10 = *((_BYTE*)v7 + 12);
            v11 = v7[1] - v4[1];
            a2 = *v7 - *v4;
            if (!(v10 & 2))
                goto LABEL_19;
            if (!sub_50AEA0((int)v7, &v26, &a1))
                break;
            v12 = v25;
            *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = v26.field_0;
            *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8 + 4) = v26.field_4;
            if (*(_BYTE*)(v25 + 2172) < 8u)
            {
                a2 = a2 * a2 + v11 * v11;
                if ((double)a2 > 4761.0)
                    goto LABEL_17;
                v13 = v7[1];
                a2 = 23 * *v7 + 11;
                v14 = 23 * v13;
                v15 = *v4;
                v27.field_0 = (double)a2;
                a2 = v14 + 11;
                v16 = 23 * v15;
                v17 = v4[1];
                v27.field_4 = (double)(v14 + 11);
                v27.field_8 = (double)(v16 + 11);
                a2 = 23 * v17 + 11;
                v27.field_C = (double)a2;
                if (!sub_535250(&v27, 0, 0, 1))
                {
                    v12 = v25;
                LABEL_17:
                    *(_DWORD*)(v12 + 4 * (unsigned __int8)(*(_BYTE*)(v12 + 2172))++ + 2140) = a1;
                    goto LABEL_38;
                }
            }
        LABEL_38:
            v4 = v7;
            v7 = (unsigned __int16*) * ((_DWORD*)v7 + 1);
            ++v8;
            if (!v7)
                goto LABEL_39;
        }
        v9 = a2;
    LABEL_19:
        if (v9 <= 0)
        {
            if (v9 < 0)
            {
                if (v11 > 0)
                {
                    a2 = *v7;
                    *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
                    a2 = v7[1];
                    v20 = (double)a2;
                LABEL_29:
                    *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8 + 4) = v20 * 23.0 + 2.3;
                    goto LABEL_38;
                }
                if (v11 < 0)
                {
                    a2 = *v7;
                    *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
                    a2 = v7[1];
                    v18 = (double)a2;
                    goto LABEL_37;
                }
                a2 = *v7;
                *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 23.0 - 2.3;
                a2 = v7[1];
                v19 = (double)a2;
                goto LABEL_25;
            }
            if (v11 > 0)
            {
                a2 = *v7;
                *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 11.5;
                a2 = v7[1];
                v20 = (double)a2;
                goto LABEL_29;
            }
            if (v11 < 0)
            {
                a2 = *v7;
                *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 11.5;
                a2 = v7[1];
                v18 = (double)a2;
                goto LABEL_37;
            }
        }
        else
        {
            if (v11 <= 0)
            {
                if (v11 < 0)
                {
                    a2 = *v7;
                    *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 2.3;
                    a2 = v7[1];
                    v18 = (double)a2;
                LABEL_37:
                    *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8 + 4) = v18 * 23.0 + 23.0 - 2.3;
                    goto LABEL_38;
                }
                a2 = *v7;
                *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 2.3;
                a2 = v7[1];
                v19 = (double)a2;
            LABEL_25:
                *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8 + 4) = v19 * 23.0 + 11.5;
                goto LABEL_38;
            }
            a2 = *v7;
            *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8) = (double)a2 * 23.0 + 2.3;
            a2 = v7[1];
            *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v8 + 4) = (double)a2 * 23.0 + 2.3;
        }
        goto LABEL_38;
    }
LABEL_39:
    v21 = 0;
    *(_DWORD*)& byte_5D4594[2386180] = v8;
    for (result = v8 / 2; v21 < *(int*)& byte_5D4594[2386180] / 2; result = *(_DWORD*)& byte_5D4594[2386180] / 2)
    {
        v22 = (_DWORD*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v21);
        v23 = (_DWORD*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * (v8 - v21) - 8);
        v26 = *(float2*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v21);
        *v22 = *v23;
        v22[1] = v23[1];
        v24 = *(_DWORD*)& byte_5D4594[2386180] - v21++;
        *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v24 - 8) = v26.field_0;
        *(float*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v24 - 4) = v26.field_4;
        v8 = *(_DWORD*)& byte_5D4594[2386180];
    }
    return result;
}

//----- (0050C830) --------------------------------------------------------
int __cdecl sub_50C830(int a1, int a2, int a3)
{
    int v3; // ecx
    float* v4; // esi
    float2 v6; // [esp+4h] [ebp-8h]
    float v7; // [esp+10h] [ebp+4h]
    float v8; // [esp+14h] [ebp+8h]

    v3 = *(_DWORD*)(a1 + 16);
    if (v3 & 0x4000 || sub_534020(a1))
        return 1;
    v4 = (float*)& byte_587000[234188];
    v8 = (double)(23 * a2);
    while (1)
    {
        v6.field_0 = v8 + *(v4 - 1);
        v7 = (double)(23 * a3);
        v6.field_4 = v7 + *v4;
        if (sub_411160(&v6) == 6)
            break;
        v4 += 2;
        if ((int)v4 >= (int)& byte_587000[234220])
            return 1;
    }
    return 0;
}

//----- (0050C8D0) --------------------------------------------------------
void __cdecl sub_50C8D0(int a1, int2* a2)
{
    int v2; // ecx
    int v3; // edx
    long double v4; // st7
    float v5; // [esp+Ch] [ebp-4h]
    float v6; // [esp+Ch] [ebp-4h]

    if (sub_50B870(a1, a2->field_0, a2->field_4))
    {
        v2 = a2->field_0;
        v3 = a2->field_4;
        v5 = (double)v3 * 23.0 + 11.5;
        v4 = *(float*)(a1 + 56) - ((double)a2->field_0 * 23.0 + 11.5);
        v6 = *(float*)(a1 + 60) - v5;
        if (fabs(v6) >= fabs(v4))
        {
            if (v6 <= 0.0)
                a2->field_4 = v3 - 1;
            else
                a2->field_4 = v3 + 1;
        }
        else if (v4 <= 0.0)
        {
            a2->field_0 = v2 - 1;
        }
        else
        {
            a2->field_0 = v2 + 1;
        }
    }
}

//----- (0050C990) --------------------------------------------------------
int __cdecl sub_50C990(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // esi
    int v5; // eax
    _DWORD* v6; // edi

    v3 = 0;
    if (*(int*)& byte_5D4594[2386180] <= 0)
        return a2;
    v4 = a2;
    v5 = a1 + 8 * a2;
    while (v4 != a3 - 1)
    {
        ++v4;
        v5 += 8;
        v6 = (_DWORD*)(*(_DWORD*)& byte_5D4594[2386176] + 8 * v3++);
        *(_DWORD*)(v5 - 8) = *v6;
        *(_DWORD*)(v5 - 4) = v6[1];
        if (v3 >= *(int*)& byte_5D4594[2386180])
            return v4;
    }
    sub_5341A0((char*)& byte_587000[234608]);
    return v4;
}

//----- (0050CA00) --------------------------------------------------------
int __cdecl sub_50CA00(int a1, int a2, int a3, float* a4)
{
    *(_BYTE*)(*(_DWORD*)(a3 + 748) + 2172) = 0;
    sub_50BA00(1, a3, (float*)(a3 + 56), a4, sub_50CA60, 6);
    if (*(_DWORD*)& byte_5D4594[2386180] > a2 && !*(_DWORD*)& byte_5D4594[1599712])
        * (_DWORD*)& byte_5D4594[1599712] = 1;
    return sub_50C990(a1, 0, a2);
}

//----- (0050CA60) --------------------------------------------------------
BOOL __cdecl sub_50CA60(int a4, int a2, int a3)
{
    float2 a1; // [esp+0h] [ebp-8h]

    *(_DWORD*)& byte_5D4594[1599708] = 0;
    a1.field_0 = (double)a2 * 23.0 + 11.5;
    a1.field_4 = (double)a3 * 23.0 + 11.5;
    sub_517F90(&a1, 100.0, sub_50CAC0, a4);
    return *(_DWORD*)& byte_5D4594[1599708] == 0;
}

//----- (0050CAC0) --------------------------------------------------------
void __cdecl sub_50CAC0(int a1, int a2)
{
    if (*(_DWORD*)& byte_5D4594[1599708] != 1)
    {
        if (sub_5330C0(a2, a1))
            * (_DWORD*)& byte_5D4594[1599708] = 1;
    }
}

//----- (0050CAF0) --------------------------------------------------------
int sub_50CAF0()
{
    return *(_DWORD*)& byte_5D4594[1599712];
}

//----- (0050CB00) --------------------------------------------------------
int sub_50CB00()
{
    return *(_DWORD*)& byte_5D4594[2386180];
}

//----- (0050CB10) --------------------------------------------------------
LPVOID sub_50CB10()
{
    return *(LPVOID*)& byte_5D4594[2386176];
}

//----- (0050CB20) --------------------------------------------------------
int __cdecl sub_50CB20(int a1, float* a2)
{
    int v2; // eax
    double v3; // st7
    unsigned __int16* v4; // eax
    int v5; // ecx
    unsigned __int16* v6; // ebp
    int v7; // esi
    int v8; // edi
    unsigned __int8* v9; // ebx
    int v10; // esi
    int v11; // edi
    _WORD* v12; // eax
    float v14; // [esp+0h] [ebp-24h]
    float v15; // [esp+0h] [ebp-24h]
    int v16; // [esp+0h] [ebp-24h]
    int2 a2a; // [esp+14h] [ebp-10h]
    float2 v18; // [esp+1Ch] [ebp-8h]
    unsigned __int16* v19; // [esp+2Ch] [ebp+8h]

    ++* (_DWORD*)& byte_5D4594[2386160];
    v14 = *a2 * 0.043478262;
    v2 = sub_419A70(v14);
    v3 = a2[1] * 0.043478262;
    a2a.field_0 = v2;
    v15 = v3;
    a2a.field_4 = sub_419A70(v15);
    sub_50C8D0(a1, &a2a);
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386184]);
    v4 = (unsigned __int16*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386184]);
    *v4 = a2a.field_0;
    v4[1] = a2a.field_4;
    v5 = v4[1] + (*v4 << 8);
    *((_DWORD*)v4 + 1) = 0;
    *((_DWORD*)v4 + 2) = 0;
    *(_DWORD*)& byte_5D4594[12 * v5 + 1599716] = *(_DWORD*)& byte_5D4594[2386160];
    do
    {
        v6 = v4;
        v19 = 0;
        if (!v4)
            break;
        do
        {
            v7 = *v6;
            v8 = v6[1];
            if (byte_5D4594[12 * ((unsigned __int16)v8 + (v7 << 8)) + 1599724] & 0x40 && !sub_50B870(a1, v7, v8))
            {
                v18.field_0 = (double)(23 * v7 + 11);
                v18.field_4 = (double)(23 * v8 + 11);
                return sub_518740(&v18, 0x80u);
            }
            v9 = &byte_587000[234284];
            do
            {
                v10 = *v6 + *((_DWORD*)v9 - 1);
                v11 = *(_DWORD*)v9 + v6[1];
                if (v10 >= 0
                    && v10 < 256
                    && v11 >= 0
                    && v11 < 256
                    && *(_DWORD*)& byte_5D4594[12 * (v11 + (v10 << 8)) + 1599716] != *(_DWORD*)& byte_5D4594[2386160])
                {
                    v16 = *(_DWORD*)v9 + v6[1];
                    *(_DWORD*)& byte_5D4594[12 * (v11 + (v10 << 8)) + 1599716] = *(_DWORD*)& byte_5D4594[2386160];
                    if (!sub_50B870(a1, v10, v16))
                    {
                        if (sub_50C830(a1, v10, v11))
                        {
                            v12 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386184]);
                            if (v12)
                            {
                                *v12 = v10;
                                v12[1] = v11;
                                *((_DWORD*)v12 + 1) = v6;
                                *((_DWORD*)v12 + 2) = v19;
                                v19 = v12;
                            }
                        }
                    }
                }
                v9 += 8;
            } while ((int)v9 < (int)& byte_587000[234316]);
            v6 = (unsigned __int16*) * ((_DWORD*)v6 + 2);
        } while (v6);
        v4 = v19;
    } while (v19);
    return 0;
}

//----- (0050CD30) --------------------------------------------------------
unsigned __int8* sub_50CD30()
{
    return &byte_5D4594[2386196];
}

//----- (0050CD40) --------------------------------------------------------
char* __cdecl sub_50CD40(int a1, int a2, _DWORD* a3)
{
    char* result; // eax

    result = (char*)sub_501900(a1);
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[2386188]
            || (result = nox_new_alloc_class("MonsterListen", 24, 128),
            (*(_DWORD*)& byte_5D4594[2386188] = result) != 0))
        {
            result = (char*)sub_534160(a2);
            if (result)
            {
                result = (char*)nox_alloc_class_new_obj(*(_DWORD * *)& byte_5D4594[2386188]);
                if (result)
                {
                    *(_DWORD*)result = a1;
                    *((_DWORD*)result + 1) = a2;
                    *((_DWORD*)result + 2) = *a3;
                    *((_DWORD*)result + 3) = a3[1];
                    *((_DWORD*)result + 4) = *(_DWORD*)& byte_5D4594[2598000];
                    *((_DWORD*)result + 5) = *(_DWORD*)& byte_5D4594[2386192];
                    *(_DWORD*)& byte_5D4594[2386192] = result;
                }
            }
        }
    }
    return result;
}

//----- (0050CDD0) --------------------------------------------------------
unsigned __int8* __cdecl sub_50CDD0(int a1)
{
    int v1; // ebx
    int v2; // edi
    unsigned __int8* result; // eax
    int v4; // esi
    unsigned int v5; // eax
    int v6; // ebp
    int v7; // eax
    int v8; // eax
    int v9; // [esp-4h] [ebp-18h]
    int* v10; // [esp+Ch] [ebp-8h]
    int v11; // [esp+10h] [ebp-4h]
    int v12; // [esp+18h] [ebp+4h]

    v1 = a1;
    v2 = 0;
    v9 = a1;
    v11 = *(_DWORD*)(a1 + 748);
    v10 = 0;
    v12 = 0;
    result = (unsigned __int8*)sub_528190(v9);
    if (result)
    {
        result = (unsigned __int8*)sub_534B10(v1);
        if (!result)
        {
            result = (unsigned __int8*)sub_534B90(v1);
            if (!result)
            {
                result = (unsigned __int8*)sub_534B60(v1);
                if (!result)
                {
                    v4 = *(_DWORD*)& byte_5D4594[2386192];
                    if (*(_DWORD*)& byte_5D4594[2386192])
                    {
                        do
                        {
                            v5 = *(_DWORD*)(v4 + 16);
                            v6 = *(_DWORD*)(v4 + 20);
                            if (*(_DWORD*)& byte_5D4594[2598000] < v5 || *(_DWORD*)& byte_5D4594[2598000] - v5 > 2)
                            {
                                if (v2)
                                    * (_DWORD*)(v2 + 20) = v6;
                                else
                                    *(_DWORD*)& byte_5D4594[2386192] = *(_DWORD*)(v4 + 20);
                                sub_414330(*(unsigned int**)& byte_5D4594[2386188], (_QWORD*)v4);
                            }
                            else
                            {
                                v7 = *(_DWORD*)(v4 + 4);
                                if (v7 && *(_BYTE*)(v7 + 16) & 0x20)
                                    * (_DWORD*)(v4 + 4) = 0;
                                if (*(_DWORD*)(v11 + 404) <= *(int*)(v4 + 16))
                                {
                                    if (sub_50CF10(v1, v4))
                                    {
                                        v8 = sub_50D000(v1, v4);
                                        if (v8 > 0 && v8 > v12)
                                        {
                                            v12 = v8;
                                            v10 = (int*)v4;
                                        }
                                    }
                                }
                                v2 = v4;
                            }
                            v4 = v6;
                        } while (v6);
                        result = (unsigned __int8*)v10;
                        if (v10 && ((unsigned int)v10[4] > * (int*)(v11 + 404) || v12 > * (int*)(v11 + 408)))
                            result = sub_50D110(v1, v10, v12);
                    }
                }
            }
        }
    }
    return result;
}

//----- (0050CF10) --------------------------------------------------------
BOOL __cdecl sub_50CF10(int a1, int a2)
{
    int v2; // ebx
    int v3; // edi
    int v4; // ebp
    int v5; // eax
    BOOL result; // eax
    int v7; // eax
    float v8; // edx
    struc_19* v9; // eax
    int2 v10; // [esp+10h] [ebp-8h]
    int v11; // [esp+1Ch] [ebp+4h]
    char v12; // [esp+1Ch] [ebp+4h]

    v2 = a1;
    v3 = *(_DWORD*)(a1 + 748);
    v4 = sub_4EC580(*(_DWORD*)(a2 + 4));
    v5 = sub_501900(*(_DWORD*)a2);
    v11 = v5;
    if (*(_DWORD*)(v3 + 404) > * (int*)& byte_5D4594[2598000])
        return 0;
    if (!v4)
    {
    LABEL_6:
        if (!v5)
            return 0;
        goto LABEL_10;
    }
    if (sub_5330C0(v2, v4))
    {
        v5 = v11;
        goto LABEL_6;
    }
    if (!(v11 & 0x10))
        return 0;
LABEL_10:
    v12 = sub_501C00((float*)(a2 + 8), *(_DWORD*)(a2 + 4));
    result = 1;
    if (v12)
    {
        v7 = sub_419A70(*(float*)(v2 + 56));
        v8 = *(float*)(v2 + 60);
        v10.field_0 = v7;
        v10.field_4 = sub_419A70(v8);
        v9 = sub_4217B0(&v10, 0);
        if (v9)
        {
            if (v12 != BYTE2(v9->field_0[32]))
                result = 0;
        }
    }
    return result;
}

//----- (0050D000) --------------------------------------------------------
int __cdecl sub_50D000(int a1, int a2)
{
    char v2; // bp
    int v3; // esi
    int result; // eax
    float v5; // eax
    float v6; // edx
    float v7; // eax
    float v8; // [esp+0h] [ebp-24h]
    float4 v9; // [esp+14h] [ebp-10h]

    v2 = sub_501900(*(_DWORD*)a2);
    v3 = sub_501AF0(*(_DWORD*)a2, (float*)(a2 + 8), (float*)(a1 + 56));
    if (!sub_50D0C0(v2, v3))
        return -1;
    v5 = *(float*)(a1 + 56);
    v6 = *(float*)(a2 + 8);
    v9.field_4 = *(float*)(a1 + 60);
    v9.field_0 = v5;
    v7 = *(float*)(a2 + 12);
    v9.field_8 = v6;
    v9.field_C = v7;
    if (!sub_535250(&v9, 0, 0, 5))
    {
        v8 = (double)v3 * 0.5;
        v3 = sub_419A70(v8);
    }
    if (sub_50D0C0(v2, v3))
        result = v3;
    else
        result = -1;
    return result;
}

//----- (0050D0C0) --------------------------------------------------------
int __cdecl sub_50D0C0(char a1, int a2)
{
    if (a1 & 0x20)
    {
        if (a2 < *(int*)& byte_587000[234644])
            return 0;
    }
    else if (a1 & 0x40)
    {
        if (a2 < *(int*)& byte_587000[234652])
            return 0;
    }
    else if (a2 < *(int*)& byte_587000[234648])
    {
        return 0;
    }
    return 1;
}

//----- (0050D110) --------------------------------------------------------
unsigned __int8* __cdecl sub_50D110(int a1, _DWORD* a2, int a3)
{
    _DWORD* v3; // esi
    int v4; // eax
    int v5; // eax

    v3 = *(_DWORD * *)(a1 + 748);
    v3[97] = *a2;
    v3[101] = *(_DWORD*)& byte_5D4594[2598000];
    v3[102] = a3;
    v4 = a2[1];
    if (v4)
        v3[98] = *(_DWORD*)(v4 + 36);
    else
        v3[98] = 0;
    sub_50D190(a1, a2 + 2, v3 + 99);
    v5 = sub_4EC580(a2[1]);
    return sub_502490(v3 + 320, v5, a1);
}

//----- (0050D190) --------------------------------------------------------
_DWORD* __cdecl sub_50D190(int a1, _DWORD* a2, _DWORD* a3)
{
    _DWORD* result; // eax

    result = a2;
    *a3 = *a2;
    a3[1] = a2[1];
    *(_DWORD*)& byte_5D4594[2386196] = *a2;
    *(_DWORD*)& byte_5D4594[2386200] = a2[1];
    return result;
}

//----- (0050D1C0) --------------------------------------------------------
int sub_50D1C0()
{
    int result; // eax

    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386188]);
    result = 0;
    *(_DWORD*)& byte_5D4594[2386188] = 0;
    *(_DWORD*)& byte_5D4594[2386192] = 0;
    return result;
}

//----- (0050D1E0) --------------------------------------------------------
void sub_50D1E0()
{
    if (*(_DWORD*)& byte_5D4594[2386188])
    {
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386188]);
        *(_DWORD*)& byte_5D4594[2386188] = 0;
    }
    *(_DWORD*)& byte_5D4594[2386192] = 0;
}

//----- (0050D210) --------------------------------------------------------
int sub_50D210()
{
    return *(_DWORD*)& byte_5D4594[2386204];
}

//----- (0050D220) --------------------------------------------------------
int __cdecl sub_50D220(int a1, int a2)
{
    int result; // eax
    int v3; // esi
    int v4; // edi

    result = 0;
    v3 = *(_DWORD*)(a1 + 748);
    v4 = *(_DWORD*)(v3 + 280);
    *(_DWORD*)(v3 + 268) = 0;
    if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - v4) >= 0xA)
    {
        *(_DWORD*)(v3 + 272) = *(_DWORD*)a2;
        *(_DWORD*)(v3 + 276) = *(_DWORD*)(a2 + 4);
        *(_DWORD*)(v3 + 8) = sub_50B9A0(v3 + 12, 32, a1, (float*)a2);
        result = sub_50CAF0();
        *(_BYTE*)(v3 + 284) = result;
        *(_DWORD*)(v3 + 280) = *(_DWORD*)& byte_5D4594[2598000];
    }
    else
    {
        *(_DWORD*)(v3 + 8) = 0;
        *(_BYTE*)(v3 + 284) = 1;
    }
    return result;
}

//----- (0050D2A0) --------------------------------------------------------
int __cdecl sub_50D2A0(int a1, int a2)
{
    _DWORD* v2; // esi
    int result; // eax

    v2 = *(_DWORD * *)(a1 + 748);
    v2[92] = *(_DWORD*)a2;
    v2[93] = *(_DWORD*)(a2 + 4);
    result = sub_547F20(a1, (float*)a2);
    v2[74] = result;
    v2[91] = 0;
    return result;
}

//----- (0050D2E0) --------------------------------------------------------
BOOL __cdecl sub_50D2E0(int a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // edx
    int v4; // ecx
    double v5; // st7
    double v6; // st6
    _DWORD* v8; // edi
    int v9; // eax

    v1 = *(_DWORD*)(a1 + 748);
    v2 = *(_DWORD*)(v1 + 296);
    if (v2 && !*(_DWORD*)(v1 + 8))
    {
        v3 = *(_DWORD*)(v1 + 364);
        v4 = *(_DWORD*)(v1 + 4 * v3 + 300);
        v5 = *(float*)(v4 + 8) - *(float*)(a1 + 56);
        v6 = *(float*)(v4 + 12) - *(float*)(a1 + 60);
        if (v6 * v6 + v5 * v5 < 64.0)
        {
            if (v3 == v2 - 1)
            {
                *(_DWORD*)(v1 + 296) = 0;
                return 1;
            }
            *(_DWORD*)(v1 + 364) = v3 + 1;
            v4 = *(_DWORD*)(v1 + 4 * (v3 + 1) + 300);
        }
        v8 = (_DWORD*)(v4 + 8);
        sub_50D220(a1, v4 + 8);
        if (!*(_BYTE*)(v1 + 284))
        {
            v9 = *(_DWORD*)(v1 + 8);
            *(_DWORD*)(v1 + 8 * v9 + 4) = *v8;
            *(_DWORD*)(v1 + 8 * v9 + 8) = v8[1];
        }
    }
    return sub_50D3B0((float*)a1) && *(_BYTE*)(v1 + 284) == 2;
}

//----- (0050D3B0) --------------------------------------------------------
int __cdecl sub_50D3B0(float* a1)
{
    int v1; // esi
    int v2; // ebp
    float v3; // edx
    int v4; // edi
    float* v5; // ebx
    double v6; // st7
    double v7; // st6
    double v8; // st5
    float* v10; // edi
    double v11; // st7
    double v12; // st7
    __int16 v13; // ax
    int v14; // eax
    double v15; // st7
    float* v16; // [esp+10h] [ebp-2Ch]
    float v17; // [esp+14h] [ebp-28h]
    float* v18; // [esp+18h] [ebp-24h]
    int v19; // [esp+1Ch] [ebp-20h]
    float v20; // [esp+1Ch] [ebp-20h]
    float v21; // [esp+20h] [ebp-1Ch]
    float2 v22; // [esp+24h] [ebp-18h]
    float4 v23; // [esp+2Ch] [ebp-10h]
    float v24; // [esp+40h] [ebp+4h]

    v1 = *((_DWORD*)a1 + 187);
    v2 = 0;
    if (*(_DWORD*)(v1 + 8))
    {
        v3 = a1[15];
        v23.field_0 = a1[14];
        v23.field_4 = v3;
        v4 = *(_DWORD*)(v1 + 268);
        v16 = 0;
        v18 = 0;
        v19 = 0;
        v17 = 10000000.0;
        if (v4 >= *(int*)(v1 + 8))
        {
        LABEL_14:
            *(_DWORD*)(v1 + 8) = 0;
            return 0;
        }
        v5 = (float*)(v1 + 8 * v4 + 12);
        do
        {
            v23.field_8 = *v5;
            v23.field_C = v5[1];
            if (sub_535250(&v23, 0, 0, 132))
            {
                v6 = v23.field_8 - a1[14];
                v7 = v23.field_C - a1[15];
                v8 = v7 * v7 + v6 * v6;
                if (v8 > 64.0)
                {
                    if (!v16 || v17 > v8)
                    {
                        v17 = v8;
                        v16 = v5;
                        v2 = v4;
                    }
                }
                else
                {
                    if (v4 == *(_DWORD*)(v1 + 8) - 1)
                    {
                        *(_DWORD*)(v1 + 8) = 0;
                        return 1;
                    }
                    v18 = v5;
                    v19 = v4;
                }
            }
            ++v4;
            v5 += 2;
        } while (v4 < *(int*)(v1 + 8));
        if (!v16)
        {
            if (!v18)
                goto LABEL_14;
            v2 = v19;
        }
        v10 = a1;
        *(_DWORD*)& byte_5D4594[2386204] = v2;
        *(_DWORD*)(v1 + 268) = v2;
        v20 = *(float*)(v1 + 8 * v2 + 12) - a1[14];
        v11 = *(float*)(v1 + 8 * v2 + 16) - a1[15];
        v21 = v11;
        v24 = sqrt(v11 * v21 + v20 * v20) + *(double*)& byte_581450[10288];
        if (v2 <= 0)
        {
            v22.field_0 = *(float*)(v1 + 20) - *(float*)(v1 + 12);
            v12 = *(float*)(v1 + 24) - *(float*)(v1 + 16);
        }
        else
        {
            v22.field_0 = *(float*)(v1 + 8 * v2 + 12) - *(float*)(v1 + 8 * v2 + 4);
            v12 = *(float*)(v1 + 8 * v2 + 16) - *(float*)(v1 + 8 * v2 + 8);
        }
        v22.field_4 = v12;
        v13 = sub_509ED0(&v22);
        *((_WORD*)v10 + 62) = v13;
        *((_WORD*)v10 + 63) = v13;
        v14 = *(_DWORD*)(v1 + 1440);
        if (v14 & 0x4000)
            v15 = *(float*)(*(_DWORD*)(v1 + 484) + 96) * v10[136];
        else
            v15 = v10[136];
        v10[22] = v15 * v20 / v24;
        v10[23] = v15 * v21 / v24;
    }
    return 0;
}

//----- (0050D5A0) --------------------------------------------------------
int __cdecl sub_50D5A0(int a1)
{
    int v1; // esi
    double v2; // st7
    float* v3; // edi
    double v4; // st6
    float v6; // edx
    char v7; // al
    bool v8; // zf
    int v9; // eax
    double v10; // st7
    double v11; // st6
    double v12; // st7
    double v13; // st6
    float4 v14; // [esp+Ch] [ebp-10h]

    v1 = *(_DWORD*)(a1 + 748);
    v2 = *(float*)(v1 + 24 * *(char*)(v1 + 544) + 556) - *(float*)(a1 + 56);
    v3 = (float*)(v1 + 24 * *(char*)(v1 + 544) + 556);
    v4 = *(float*)(v1 + 24 * *(char*)(v1 + 544) + 560) - *(float*)(a1 + 60);
    if (sqrt(v4 * v4 + v2 * v2) + *(double*)& byte_581450[10288] <= 8.0)
        return 1;
    v6 = *(float*)(a1 + 60);
    v14.field_0 = *(float*)(a1 + 56);
    v14.field_4 = v6;
    v14.field_8 = *v3;
    v7 = (*(_DWORD*)(a1 + 16) >> 12) & 4;
    v14.field_C = v3[1];
    v8 = sub_535250(&v14, 0, 0, v7) == 0;
    v9 = *(_DWORD*)(v1 + 8);
    if (v8)
    {
        if (!v9)
        {
            if (!*(_DWORD*)(v1 + 296)
                || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 280)) > 0xA
                && (v12 = *(float*)(v1 + 368) - *v3, v13 = *(float*)(v1 + 372) - v3[1], v13 * v13 + v12 * v12 > 10000.0))
            {
                sub_50D2A0(a1, (int)v3);
            }
            if (*(_DWORD*)(v1 + 296))
            {
            LABEL_16:
                if (sub_50D2E0(a1))
                {
                    *(_DWORD*)(v1 + 8) = 0;
                    *(_DWORD*)(v1 + 296) = 0;
                    return 1;
                }
                return 0;
            }
            sub_5341A0((char*)& byte_587000[234672]);
            sub_50D220(a1, (int)v3);
        }
    }
    else if (!v9
        || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v1 + 280)) > 0xA
        && (v10 = *(float*)(v1 + 272) - *v3, v11 = *(float*)(v1 + 276) - v3[1], v11 * v11 + v10 * v10 > 2500.0))
    {
        sub_50D220(a1, (int)v3);
    }
    if (*(_DWORD*)(v1 + 296))
        goto LABEL_16;
    if (*(_DWORD*)(v1 + 8) && sub_50D3B0((float*)a1))
    {
        *(_DWORD*)(v1 + 8) = 0;
        return 1;
    }
    return 0;
}

//----- (0050D780) --------------------------------------------------------
int sub_50D780()
{
    int result; // eax

    result = nox_new_alloc_class("SpawnClass", 12, 96);
    *(_DWORD*)& byte_5D4594[2386216] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[2386212] = 0;
        result = nox_new_alloc_class("MonsterListClass", 148, 96);
        *(_DWORD*)& byte_5D4594[2386220] = result;
        if (result)
        {
            *(_DWORD*)& byte_5D4594[2386224] = 0;
            *(_DWORD*)& byte_5D4594[2386228] = 0;
            result = 1;
        }
    }
    return result;
}

//----- (0050D7E0) --------------------------------------------------------
void sub_50D7E0()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386216]);
    *(_DWORD*)& byte_5D4594[2386212] = 0;
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386220]);
    *(_DWORD*)& byte_5D4594[2386224] = 0;
    *(_DWORD*)& byte_5D4594[2386228] = 0;
}

//----- (0050D820) --------------------------------------------------------
void sub_50D820()
{
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386216]);
    *(_DWORD*)& byte_5D4594[2386216] = 0;
    *(_DWORD*)& byte_5D4594[2386212] = 0;
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386220]);
    *(_DWORD*)& byte_5D4594[2386220] = 0;
    *(_DWORD*)& byte_5D4594[2386224] = 0;
    *(_DWORD*)& byte_5D4594[2386228] = 0;
}

//----- (0050D860) --------------------------------------------------------
int __cdecl sub_50D860(int a1, int a2)
{
    if (*(float*)(a1 + 4) == *(float*)(a2 + 4))
        return 0;
    if (*(float*)(a1 + 4) <= (double) * (float*)(a2 + 4))
        return -1;
    return 1;
}

//----- (0050D890) --------------------------------------------------------
unsigned int sub_50D890()
{
    unsigned int result; // eax

    if (!(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)(5 * *(_DWORD*)& byte_5D4594[2649704])))
        sub_50D8D0();
    result = *(_DWORD*)& byte_5D4594[2598000] / 0xFu;
    if (!(*(_DWORD*)& byte_5D4594[2598000] % 0xFu))
        result = sub_50D960();
    return result;
}

//----- (0050D8D0) --------------------------------------------------------
void sub_50D8D0()
{
    int* v0; // edi
    int* v1; // ebp
    int v2; // ebx
    int v3; // esi
    int v4; // eax

    v0 = *(int**)& byte_5D4594[2386212];
    if (*(_DWORD*)& byte_5D4594[2386212])
    {
        do
        {
            v1 = (int*)v0[1];
            v2 = 1;
            v3 = sub_4DA7C0();
            if (!v3)
                goto LABEL_13;
            do
            {
                v4 = *(_DWORD*)(v3 + 748);
                if (*(_DWORD*)(*(_DWORD*)(v4 + 276) + 4792) == 1 && !*(_DWORD*)(v4 + 312) && sub_4E6C00(v3, *v0) < 700.0)
                    v2 = 0;
                v3 = sub_4DA7F0(v3);
            } while (v3);
            if (v2 == 1)
                LABEL_13:
            sub_4E5CC0(*v0);
            v0 = v1;
        } while (v1);
    }
}

//----- (0050D960) --------------------------------------------------------
int sub_50D960()
{
    int v0; // ebx
    int v1; // edi
    int v2; // eax
    int* v3; // ebp
    int v4; // ecx
    _DWORD* v5; // esi
    _DWORD* v6; // eax
    int v7; // eax
    int i; // edx
    double v9; // st7
    int v10; // edi
    float* v11; // ecx
    int v12; // esi
    int j; // edx
    int k; // ecx
    int v15; // ebx
    int v16; // eax
    int v17; // eax
    int v18; // eax
    int v19; // esi
    int v20; // edi
    int v21; // eax
    int v22; // esi
    int v23; // ebp
    int v24; // edx
    unsigned __int8* v25; // eax
    int* v26; // esi
    int* v27; // ebx
    char v28; // cl
    unsigned __int8* v29; // eax
    int v30; // eax
    int v31; // eax
    int v32; // eax
    float v34; // [esp+0h] [ebp-40h]
    int v35; // [esp+14h] [ebp-2Ch]
    int v36; // [esp+18h] [ebp-28h]
    int v37; // [esp+18h] [ebp-28h]
    float4 a2; // [esp+20h] [ebp-20h]
    float4 v39; // [esp+30h] [ebp-10h]

    v34 = sub_419D40(&byte_587000[234752]);
    v35 = sub_419A70(v34);
    v36 = 0;
    memset(&byte_5D4594[2386232], 0, 0x80u);
    v0 = sub_4DA7C0();
    if (v0)
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 748);
            *(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 2386232] = 0;
            v2 = *(_DWORD*)(v1 + 276);
            if (*(_DWORD*)(v2 + 4792))
            {
                v3 = *(int**)& byte_5D4594[2386212];
                a2.field_0 = *(float*)(v0 + 56) - (double) * (unsigned __int16*)(v2 + 10) - 100.0;
                a2.field_4 = *(float*)(v0 + 60) - (double) * (unsigned __int16*)(*(_DWORD*)(v1 + 276) + 12) - 100.0;
                a2.field_8 = (double) * (unsigned __int16*)(*(_DWORD*)(v1 + 276) + 10) + *(float*)(v0 + 56) + 100.0;
                a2.field_C = (double) * (unsigned __int16*)(*(_DWORD*)(v1 + 276) + 12) + *(float*)(v0 + 60) + 100.0;
                if (*(_DWORD*)& byte_5D4594[2386212])
                {
                    do
                    {
                        if (sub_428220((float2*)(*v3 + 56), &a2))
                        {
                            v39.field_0 = *(float*)(v0 + 56);
                            v39.field_4 = *(float*)(v0 + 60);
                            v4 = *v3;
                            v39.field_8 = *(float*)(*v3 + 56);
                            v39.field_C = *(float*)(v4 + 60);
                            if (sub_535250(&v39, 0, 0, 69))
                            {
                                v5 = sub_50DE60(*v3);
                                if (!v5)
                                {
                                    v6 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386220]);
                                    v5 = v6;
                                    if (!v6)
                                        break;
                                    v6[35] = *(_DWORD*)& byte_5D4594[2386224];
                                    if (*(_DWORD*)& byte_5D4594[2386224])
                                        * (_DWORD*)(*(_DWORD*)& byte_5D4594[2386224] + 144) = v6;
                                    *(_DWORD*)& byte_5D4594[2386224] = v6;
                                    ++* (_DWORD*)& byte_5D4594[2386228];
                                    *v6 = *v3;
                                }
                                v5[2] |= 1 << *(_BYTE*)(*(_DWORD*)(v1 + 276) + 2064);
                                v7 = *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064);
                                ++* (_DWORD*)& byte_5D4594[4 * v7 + 2386232];
                                if (*(_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 2386232] > v35)
                                    v36 = 1;
                                *(float*)& v5[*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064) + 3] = sub_4E6C00(*v3, v0);
                            }
                        }
                        v3 = (int*)v3[1];
                    } while (v3);
                }
            }
            v0 = sub_4DA7F0(v0);
        } while (v0);
        if (v36)
        {
            for (i = *(_DWORD*)& byte_5D4594[2386224]; i; i = *(_DWORD*)(i + 140))
            {
                v9 = 0.0;
                v10 = 0;
                v11 = (float*)(i + 12);
                v12 = 32;
                do
                {
                    if (*v11 != 0.0)
                    {
                        v9 = v9 + *v11;
                        ++v10;
                    }
                    ++v11;
                    --v12;
                } while (v12);
                *(float*)(i + 4) = v9 / (double)v10;
            }
            for (j = *(_DWORD*)& byte_5D4594[2386224]; j; j = *(_DWORD*)(j + 140))
            {
                for (k = *(_DWORD*)(j + 140); k; k = *(_DWORD*)(k + 140))
                {
                    if (*(float*)(k + 4) > (double) * (float*)(j + 4))
                    {
                        v15 = *(_DWORD*)(j + 140);
                        if (v15 == k)
                        {
                            v16 = *(_DWORD*)(j + 144);
                            *(_DWORD*)(k + 144) = v16;
                            if (v16)
                                * (_DWORD*)(v16 + 140) = k;
                            v17 = *(_DWORD*)(k + 140);
                            *(_DWORD*)(j + 140) = v17;
                            if (v17)
                                * (_DWORD*)(v17 + 144) = j;
                            *(_DWORD*)(j + 144) = k;
                            *(_DWORD*)(k + 140) = j;
                        }
                        else
                        {
                            v18 = *(_DWORD*)(j + 144);
                            v19 = *(_DWORD*)(k + 140);
                            v20 = *(_DWORD*)(k + 144);
                            if (v18)
                                * (_DWORD*)(v18 + 140) = k;
                            if (v20)
                                * (_DWORD*)(v20 + 140) = j;
                            if (v15)
                                * (_DWORD*)(v15 + 144) = k;
                            if (v19)
                                * (_DWORD*)(v19 + 144) = j;
                            *(_DWORD*)(j + 144) = v20;
                            *(_DWORD*)(j + 140) = v19;
                            *(_DWORD*)(k + 144) = v18;
                            *(_DWORD*)(k + 140) = v15;
                        }
                        if (j == *(_DWORD*)& byte_5D4594[2386224])
                            * (_DWORD*)& byte_5D4594[2386224] = k;
                        v21 = k;
                        k = j;
                        j = v21;
                    }
                }
            }
            while (1)
            {
                v22 = 0;
                v23 = 0;
                v24 = 0;
                v25 = &byte_5D4594[2386232];
                do
                {
                    if (*(_DWORD*)v25 > v22)
                    {
                        v22 = *(_DWORD*)v25;
                        v23 = v24;
                    }
                    v25 += 4;
                    ++v24;
                } while ((int)v25 < (int)& byte_5D4594[2386360]);
                if (v22 <= v35)
                    break;
                v26 = *(int**)& byte_5D4594[2386224];
                v37 = 1;
                if (*(_DWORD*)& byte_5D4594[2386224])
                {
                    do
                    {
                        if (v37 != 1)
                            break;
                        v27 = (int*)v26[35];
                        if (v26[2] & (1 << v23))
                        {
                            sub_4E5CC0(*v26);
                            v28 = 0;
                            v29 = &byte_5D4594[2386232];
                            do
                            {
                                if ((1 << v28) & v26[2])
                                    --* (_DWORD*)v29;
                                v29 += 4;
                                ++v28;
                            } while ((int)v29 < (int)& byte_5D4594[2386360]);
                            v30 = v26[35];
                            if (v30)
                                * (_DWORD*)(v30 + 144) = v26[36];
                            v31 = v26[36];
                            if (v31)
                                * (_DWORD*)(v31 + 140) = v26[35];
                            else
                                *(_DWORD*)& byte_5D4594[2386224] = v26[35];
                            sub_414330(*(unsigned int**)& byte_5D4594[2386220], v26);
                            v32 = *(_DWORD*)& byte_5D4594[4 * v23 + 2386232];
                            --* (_DWORD*)& byte_5D4594[2386228];
                            if (v32 <= v35)
                                v37 = 0;
                        }
                        v26 = v27;
                    } while (v27);
                }
            }
        }
    }
    return sub_50DE10();
}

//----- (0050DE10) --------------------------------------------------------
int sub_50DE10()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[2386224];
    if (*(_DWORD*)& byte_5D4594[2386224])
    {
        do
        {
            v1 = *(_DWORD*)(result + 140);
            sub_414330(*(unsigned int**)& byte_5D4594[2386220], (_QWORD*)result);
            result = v1;
            --* (_DWORD*)& byte_5D4594[2386228];
        } while (v1);
        *(_DWORD*)& byte_5D4594[2386224] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[2386224] = 0;
    }
    return result;
}

//----- (0050DE60) --------------------------------------------------------
_DWORD* __cdecl sub_50DE60(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[2386224];
    if (!*(_DWORD*)& byte_5D4594[2386224])
        return 0;
    while (*result != a1)
    {
        result = (_DWORD*)result[35];
        if (!result)
            return 0;
    }
    return result;
}

//----- (0050DE80) --------------------------------------------------------
int __cdecl sub_50DE80(int a1, float* a2)
{
    int v2; // edi
    int v3; // esi
    int v4; // eax
    int v5; // ecx
    float v7; // [esp+0h] [ebp-20h]
    float4 a2a; // [esp+10h] [ebp-10h]

    v7 = sub_419D40(&byte_587000[234776]);
    v2 = sub_419A70(v7);
    v3 = sub_4DA7C0();
    if (!v3)
        return 1;
    while (1)
    {
        v4 = *(_DWORD*)(v3 + 748);
        v5 = *(_DWORD*)(v4 + 276);
        if (*(_DWORD*)(v5 + 4792))
        {
            a2a.field_0 = *(float*)(v3 + 56) - (double) * (unsigned __int16*)(v5 + 10) - 100.0;
            a2a.field_4 = *(float*)(v3 + 60) - (double) * (unsigned __int16*)(*(_DWORD*)(v4 + 276) + 12) - 100.0;
            a2a.field_8 = (double) * (unsigned __int16*)(*(_DWORD*)(v4 + 276) + 10) + *(float*)(v3 + 56) + 100.0;
            a2a.field_C = (double) * (unsigned __int16*)(*(_DWORD*)(v4 + 276) + 12) + *(float*)(v3 + 60) + 100.0;
            if (sub_428220((float2*)a2, &a2a))
            {
                *(_DWORD*)& byte_5D4594[2386208] = 0;
                sub_517C10(&a2a, sub_50DFB0, v3);
                if (*(_DWORD*)& byte_5D4594[2386208] >= v2)
                    break;
            }
        }
        v3 = sub_4DA7F0(v3);
        if (!v3)
            return 1;
    }
    return 0;
}

//----- (0050DFB0) --------------------------------------------------------
void __cdecl sub_50DFB0(float* a1, int a2)
{
    float v2; // ecx
    float v3; // eax
    float v4; // ecx
    float4 v5; // [esp+4h] [ebp-10h]

    if ((_BYTE)a1[2] & 2 && !((_DWORD)a1[4] & 0x20) && (((_DWORD)a1[4] & 0x8000) != 0x8000 || sub_534A40((int)a1)))
    {
        v2 = *(float*)(a2 + 56);
        v3 = a1[14];
        v5.field_4 = *(float*)(a2 + 60);
        v5.field_0 = v2;
        v4 = a1[15];
        v5.field_8 = v3;
        v5.field_C = v4;
        if (sub_535250(&v5, 0, 0, 69) == 1)
            ++* (_DWORD*)& byte_5D4594[2386208];
    }
}

//----- (0050E030) --------------------------------------------------------
int __cdecl sub_50E030(int a1, _DWORD* a2)
{
    int v2; // ebp
    _DWORD* v3; // esi
    int result; // eax
    _DWORD* v5; // edi
    int v6; // eax
    _DWORD* v7; // eax
    int v8; // ecx
    int* v9; // edx
    _DWORD* v10; // edi
    int v11; // esi
    int v12; // ebp
    _DWORD* v13; // edx
    int v14; // esi

    v2 = *(_DWORD*)(a1 + 748);
    v3 = (_DWORD*)a2[187];
    if (!v3[549])
    {
        result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386216]);
        v5 = (_DWORD*)result;
        if (!result)
            return result;
        sub_50E110(result);
        *v5 = a2;
        ++* (_BYTE*)(v2 + 86);
        v3[549] = v5;
        v3[548] = a1;
        v6 = a2[3];
        if (v6 & 0x2000)
        {
            v7 = sub_4E3810((CHAR*)& byte_587000[234800]);
            if (v7)
            {
                v8 = v7[173];
                v9 = v3 + 511;
                v10 = (_DWORD*)v7[173];
                v11 = 3;
                do
                {
                    v12 = *v9;
                    ++v9;
                    *v10 = v12;
                    ++v10;
                    --v11;
                } while (v11);
                *(_DWORD*)(v8 + 24) = 0;
                *(_DWORD*)(v8 + 28) = a2[14];
                *(_DWORD*)(v8 + 32) = a2[15];
                *(_BYTE*)(v8 + 20) = 0;
                v13 = (_DWORD*)v8;
                v14 = 3;
                do
                {
                    if (*v13)
                        ++* (_BYTE*)(v8 + 20);
                    ++v13;
                    --v14;
                } while (v14);
            }
            sub_4F3070((int)a2, (int)v7, 1);
        }
    }
    return 1;
}

//----- (0050E110) --------------------------------------------------------
int __cdecl sub_50E110(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 8) = 0;
    *(_DWORD*)(a1 + 4) = *(_DWORD*)& byte_5D4594[2386212];
    if (*(_DWORD*)& byte_5D4594[2386212])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[2386212] + 8) = a1;
    *(_DWORD*)& byte_5D4594[2386212] = a1;
    return result;
}

//----- (0050E140) --------------------------------------------------------
void __cdecl sub_50E140(int a1)
{
    int v1; // esi
    int v2; // eax

    if (a1)
    {
        v1 = *(_DWORD*)(a1 + 748);
        v2 = *(_DWORD*)(v1 + 2192);
        if (v2)
        {
            --* (_BYTE*)(*(_DWORD*)(v2 + 748) + 86);
            *(_DWORD*)(v1 + 2192) = 0;
        }
        if (*(_DWORD*)(v1 + 2196))
        {
            sub_50E1B0(*(_DWORD*)(v1 + 2196));
            sub_414330(*(unsigned int**)& byte_5D4594[2386216], *(_QWORD * *)(v1 + 2196));
            *(_DWORD*)(v1 + 2196) = 0;
        }
    }
}

//----- (0050E1B0) --------------------------------------------------------
int __cdecl sub_50E1B0(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    v2 = *(_DWORD*)(a1 + 4);
    if (v2)
        * (_DWORD*)(v2 + 8) = *(_DWORD*)(a1 + 8);
    v3 = *(_DWORD*)(a1 + 8);
    if (v3)
    {
        result = *(_DWORD*)(a1 + 4);
        *(_DWORD*)(v3 + 4) = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[2386212] = *(_DWORD*)(a1 + 4);
    }
    return result;
}

//----- (0050E1E0) --------------------------------------------------------
void __cdecl sub_50E1E0(int a1)
{
    if (a1)
    {
        if (!sub_534A40(a1))
            sub_50E140(a1);
    }
}

//----- (0050E210) --------------------------------------------------------
void __cdecl sub_50E210(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // esi
    int v4; // edi

    v1 = *(_DWORD*)(a1 + 748);
    if (!*(_DWORD*)& byte_5D4594[2386360])
        * (_DWORD*)& byte_5D4594[2386360] = sub_4E3AA0((CHAR*)& byte_587000[234808]);
    if (*(_BYTE*)(a1 + 8) & 2)
    {
        v2 = *(_DWORD*)(a1 + 12);
        if (v2 & 0x2000)
        {
            if (*(_DWORD*)(v1 + 2196))
            {
                v3 = sub_4E7980(a1);
                if (v3)
                {
                    do
                    {
                        v4 = sub_4E7990(v3);
                        if (*(unsigned __int16*)(v3 + 4) == *(_DWORD*)& byte_5D4594[2386360])
                            sub_4E5CC0(v3);
                        v3 = v4;
                    } while (v4);
                }
            }
        }
    }
    sub_50E140(a1);
}

//----- (0050E2A0) --------------------------------------------------------
int sub_50E2A0()
{
    int result; // eax

    result = nox_new_alloc_class("TradeSessions", 64, 64);
    *(_DWORD*)& byte_5D4594[2386492] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[2386496] = nox_new_alloc_class("TradeItems", 16, 500);
        if (*(_DWORD*)& byte_5D4594[2386496])
        {
            memset(&byte_5D4594[2386364], 0, 0x80u);
            *(_DWORD*)& byte_5D4594[2386500] = 0;
            result = 1;
        }
        else
        {
            sub_50E300();
            result = 0;
        }
    }
    return result;
}

//----- (0050E300) --------------------------------------------------------
int sub_50E300()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2386492])
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386492]);
    *(_DWORD*)& byte_5D4594[2386492] = 0;
    if (*(_DWORD*)& byte_5D4594[2386496])
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386496]);
    result = 0;
    memset(&byte_5D4594[2386364], 0, 0x80u);
    *(_DWORD*)& byte_5D4594[2386496] = 0;
    *(_DWORD*)& byte_5D4594[2386500] = 0;
    return result;
}

//----- (0050E360) --------------------------------------------------------
int sub_50E360()
{
    _DWORD* v0; // edi
    int* i; // esi
    int result; // eax

    v0 = *(_DWORD * *)& byte_5D4594[2386500];
    if (*(_DWORD*)& byte_5D4594[2386500])
    {
        do
        {
            if (v0[4])
            {
                for (i = (int*)v0[5]; i; i = (int*)i[2])
                    sub_4E38A0(*i);
                v0[5] = 0;
            }
            v0 = (_DWORD*)v0[14];
        } while (v0);
    }
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386492]);
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386496]);
    result = 0;
    memset(&byte_5D4594[2386364], 0, 0x80u);
    *(_DWORD*)& byte_5D4594[2386500] = 0;
    return result;
}

//----- (0050E3D0) --------------------------------------------------------
int __cdecl sub_50E3D0(int a1, int a2, float a3)
{
    float v3; // ebp
    int v4; // edi
    int v5; // ebx
    int v6; // eax
    int v7; // eax
    int v8; // eax
    double v9; // st7
    int v10; // eax
    int v11; // esi
    int v12; // edi
    double v13; // st7
    int v14; // eax
    _BYTE* v15; // esi
    double v16; // st7
    int v17; // eax
    double v18; // st7
    int v19; // ecx
    int v20; // ecx
    unsigned __int16* v21; // ecx
    double v22; // st7
    int v23; // eax
    double v24; // st7
    float v26; // [esp+0h] [ebp-20h]
    int v27; // [esp+14h] [ebp-Ch]
    float v28; // [esp+18h] [ebp-8h]
    int v29; // [esp+28h] [ebp+8h]
    float v30; // [esp+28h] [ebp+8h]
    float v31; // [esp+2Ch] [ebp+Ch]

    v3 = a3;
    v4 = 0;
    v27 = 0;
    v31 = (double) * (unsigned int*)(LODWORD(a3) + 32);
    if (!*(_DWORD*)& byte_5D4594[2386504])
    {
        *(_DWORD*)& byte_5D4594[2386504] = sub_4E3AA0((CHAR*)& byte_587000[235608]);
        *(_DWORD*)& byte_5D4594[2386508] = sub_4E3AA0((CHAR*)& byte_587000[235616]);
        *(_DWORD*)& byte_5D4594[2386512] = sub_4E3AA0((CHAR*)& byte_587000[235624]);
    }
    v5 = a2;
    if (a2 && *(_DWORD*)(a2 + 16))
    {
        v6 = *(_DWORD*)(a2 + 8);
        if (*(_BYTE*)(v6 + 8) & 4)
            v6 = *(_DWORD*)(a2 + 12);
        v27 = *(_DWORD*)(v6 + 692);
        v4 = *(_DWORD*)(v6 + 692);
    }
    v7 = *(_DWORD*)(LODWORD(v3) + 8);
    if (v7 & 0x100)
    {
        v8 = *(_DWORD*)(LODWORD(v3) + 12);
        if (v8 & 1)
        {
            v9 = (double)(unsigned __int16)sub_424C40(COERCE_FLOAT(**(_BYTE * *)(LODWORD(v3) + 736)));
        LABEL_16:
            v31 = v9;
            goto LABEL_17;
        }
        if (v8 & 2)
        {
            v10 = sub_4E3B60(*(CHAR * *)(LODWORD(v3) + 736));
            if (v10)
                v31 = (double) * (unsigned int*)(v10 + 48);
            if (sub_40A5C0(4096))
            {
                v9 = sub_419D40(&byte_587000[235632]) * v31;
                goto LABEL_16;
            }
        }
    }
LABEL_17:
    if (*(_DWORD*)(LODWORD(v3) + 8) & 0x13001000)
    {
        v11 = *(_DWORD*)(LODWORD(v3) + 692);
        v12 = 4;
        do
        {
            if (*(_DWORD*)v11)
            {
                *(float*)& v29 = (double) * (int*)(*(_DWORD*)v11 + 20);
                if (sub_40A5C0(4096))
                    v13 = sub_419D40(&byte_587000[235660]) * *(float*)& v29;
                else
                    v13 = *(float*)& v29;
                v31 = v13 + v31;
            }
            v11 += 4;
            --v12;
        } while (v12);
        v4 = v27;
    }
    v14 = *(_DWORD*)(LODWORD(v3) + 8);
    v30 = v31;
    if (v14 & 0x1000000 && *(_BYTE*)(LODWORD(v3) + 12) & 0x82)
    {
        v15 = *(_BYTE * *)(LODWORD(v3) + 736);
        if (!v15[2] && *v15)
        {
            if (sub_40A5C0(4096))
                v16 = sub_419D40(&byte_587000[235692]);
            else
                v16 = sub_419D40(&byte_587000[235716]);
            v26 = v16;
            v17 = sub_419A70(v26);
            v18 = (double)v17;
            v19 = (unsigned __int8)v15[1];
            if (v19 > v17)
            {
                v28 = v31 / v18;
                v31 = (double)(v19 - v17) * v28 + v31;
            }
            else
            {
                v31 = (double)(unsigned __int8)v15[1] / v18 * v31;
            }
        }
    }
    else if (v14 & 0x1000)
    {
        if (*(_DWORD*)(LODWORD(v3) + 12) & 0x47F0000)
        {
            v20 = *(_DWORD*)(LODWORD(v3) + 736);
            if (*(_BYTE*)(v20 + 109))
            {
                v4 = v27;
                v31 = (double) * (unsigned __int8*)(v20 + 108) / (double) * (unsigned __int8*)(v20 + 109) * v31;
            }
        }
    }
    if (v4 && v5 && *(_DWORD*)(v5 + 16) && a1)
    {
        v31 = v31 * *(float*)(v4 + 1716);
        v30 = v30 * *(float*)(v4 + 1716);
    }
    v21 = *(unsigned __int16**)(LODWORD(v3) + 556);
    if (v21 && v21[2])
        v31 = (double)* v21 / (double)v21[2] * v31;
    if (v4 && !a1)
    {
        v22 = sub_40A5C0(4096) ? sub_419D40(&byte_587000[235736]) : *(float*)(v4 + 1720);
        v23 = *(unsigned __int16*)(LODWORD(v3) + 4);
        if ((unsigned __int16)v23 != *(_DWORD*)& byte_5D4594[2386504]
            && v23 != *(_DWORD*)& byte_5D4594[2386512]
            && v23 != *(_DWORD*)& byte_5D4594[2386508])
        {
            v31 = v22 * v31;
            v30 = v22 * v30;
        }
    }
    if (sub_40A5C0(4096)
        && !a1
        && *(_DWORD*)(LODWORD(v3) + 8) & 0x3001000
        && *(_BYTE*)(*(_DWORD*)(LODWORD(v3) + 748) + 4) & 1)
    {
        v30 = 0.0;
    }
    else if (v31 >= 1.0)
    {
        goto LABEL_64;
    }
    v31 = 1.0;
LABEL_64:
    if (v30 < 1.0)
        v30 = 1.0;
    if (a1 == 2)
    {
        v24 = sub_419D40(&byte_587000[235756]) * (v30 - v31);
        v31 = v24;
        if (v24 < 1.0)
            v31 = 1.0;
    }
    return sub_419A70(v31);
}

//----- (0050E7A0) --------------------------------------------------------
int __cdecl sub_50E7A0(_DWORD* a1, int a2)
{
    int* v2; // esi
    int v4; // eax
    int v5; // eax
    int v6; // eax

    v2 = (int*)a1[5];
    if (!v2)
        return 0;
    while (*v2 != a2)
    {
        v2 = (int*)v2[2];
        if (!v2)
            return 0;
    }
    v4 = v2[2];
    if (v4)
        * (_DWORD*)(v4 + 12) = v2[3];
    v5 = v2[3];
    if (v5)
        * (_DWORD*)(v5 + 8) = v2[2];
    if (v2 == (int*)a1[5])
        a1[5] = v2[2];
    v6 = a1[2];
    if (!(*(_BYTE*)(v6 + 8) & 4))
        v6 = a1[3];
    sub_50E820(v6, *v2);
    sub_414330(*(unsigned int**)& byte_5D4594[2386496], v2);
    return 1;
}

//----- (0050E820) --------------------------------------------------------
int __cdecl sub_50E820(int a1, int a2)
{
    int v3; // ecx
    int v5; // [esp+0h] [ebp-4h]

    HIWORD(v5) = *(_WORD*)(a2 + 36);
    v3 = *(_DWORD*)(a1 + 748);
    LOWORD(v5) = 2505;
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)& v5, 4, 0, 1);
}

//----- (0050E870) --------------------------------------------------------
_DWORD* sub_50E870()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi

    v0 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386492]);
    v1 = v0;
    if (!v0)
        return 0;
    v0[2] = 0;
    v0[3] = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[8] = 0;
    v0[9] = 0;
    v0[10] = 0;
    v0[11] = 0;
    v0[5] = 0;
    v0[12] = sub_4E3810((CHAR*)& byte_587000[235776]);
    v1[13] = sub_4E3810((CHAR*)& byte_587000[235784]);
    v1[15] = 0;
    v1[14] = *(_DWORD*)& byte_5D4594[2386500];
    if (*(_DWORD*)& byte_5D4594[2386500])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[2386500] + 60) = v1;
    *(_DWORD*)& byte_5D4594[2386500] = v1;
    return v1;
}

//----- (0050E8F0) --------------------------------------------------------
_DWORD* __cdecl sub_50E8F0(int a1, int a2)
{
    int v2; // ebx
    int v3; // eax
    _DWORD* v4; // esi
    _DWORD* result; // eax

    v2 = 0;
    if (sub_40A5C0(4096)
        && (v3 = *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064),
            v4 = *(_DWORD * *)& byte_5D4594[4 * v3 + 2386364],
            *(_DWORD*)& byte_5D4594[4 * v3 + 2386364] = 0,
            v4))
    {
        v2 = 1;
    }
    else
    {
        result = sub_50E870();
        v4 = result;
        if (!result)
            return result;
    }
    v4[2] = a1;
    v4[3] = a2;
    v4[4] = 1;
    if (!v2)
        sub_50E970((int)v4);
    return v4;
}

//----- (0050E970) --------------------------------------------------------
void __cdecl sub_50E970(int a1)
{
    int v1; // edi
    int v2; // eax
    int v3; // esi
    unsigned int v4; // esi
    _DWORD* v5; // eax
    CHAR** v6; // eax
    unsigned __int8* v7; // esi
    _DWORD* v8; // eax
    int v9; // ecx
    _DWORD* v10; // eax
    int v11; // edi
    _DWORD* v12; // ebx
    int v13; // eax
    unsigned int v14; // esi
    _DWORD* v15; // eax
    _DWORD* v16; // eax
    _DWORD* v17; // eax
    _DWORD* v18; // eax
    _DWORD* v19; // eax
    _DWORD* v20; // eax
    _DWORD* v21; // eax
    _DWORD* v22; // eax
    _DWORD* v23; // eax
    _DWORD* v24; // eax
    _DWORD* v25; // eax
    _DWORD* v26; // eax
    _DWORD* v27; // eax
    _DWORD* v28; // eax
    _DWORD* v29; // eax
    _DWORD* v30; // eax
    _DWORD* v31; // eax
    _DWORD* v32; // eax
    _BYTE* v33; // esi
    unsigned __int8* v34; // ebp
    _DWORD* v35; // eax
    int v36; // ebx
    int v37; // eax
    int v38; // edx
    int v39; // eax
    float v40; // [esp+0h] [ebp-38h]
    int v41; // [esp+14h] [ebp-24h]
    int v42; // [esp+18h] [ebp-20h]
    _BYTE* v43; // [esp+20h] [ebp-18h]
    unsigned __int8 v44[20]; // [esp+24h] [ebp-14h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 8);
    if (v2 && *(_BYTE*)(v2 + 8) & 2 && *(_BYTE*)(v2 + 12) & 8
        || (v2 = *(_DWORD*)(a1 + 12)) != 0 && *(_BYTE*)(v2 + 8) & 2 && *(_BYTE*)(v2 + 12) & 8)
    {
        v3 = v2;
        if (sub_40A5C0(4096))
        {
            v40 = sub_419D40(&byte_587000[235792]);
            v4 = sub_419A70(v40);
            if (sub_4E3CC0() < v4)
            {
                v5 = sub_4E3810((CHAR*)& byte_587000[235812]);
                if (v5)
                    sub_50EE00(a1, *(float*)& v5);
            }
            if (*(_DWORD*)& byte_587000[234816])
            {
                v6 = (CHAR * *)& byte_587000[234816];
                v7 = &byte_587000[234816];
                do
                {
                    v8 = sub_4E3810(*v6);
                    if (v8)
                        sub_50EE00(a1, *(float*)& v8);
                    v9 = *((_DWORD*)v7 + 1);
                    v7 += 4;
                    v6 = (CHAR * *)v7;
                } while (v9);
            }
            v10 = sub_4E3810((CHAR*)& byte_587000[235828]);
            v11 = (int)v10;
            if (v10)
            {
                v12 = (_DWORD*)v10[173];
                v13 = sub_4E3CC0();
                *v12 = 8;
                v14 = v13 + 2;
                v15 = sub_4F0720(v11, v13 + 2);
                if (v15)
                    sub_50EE00(a1, *(float*)& v15);
                *v12 = 8;
                v16 = sub_4F0720(v11, v14);
                if (v16)
                    sub_50EE00(a1, *(float*)& v16);
                *v12 = 8;
                v17 = sub_4F0720(v11, v14);
                if (v17)
                    sub_50EE00(a1, *(float*)& v17);
                *v12 = 8;
                v18 = sub_4F0720(v11, v14);
                if (v18)
                    sub_50EE00(a1, *(float*)& v18);
                *v12 = 16;
                v19 = sub_4F0720(v11, v14);
                if (v19)
                    sub_50EE00(a1, *(float*)& v19);
                *v12 = 16;
                v20 = sub_4F0720(v11, v14);
                if (v20)
                    sub_50EE00(a1, *(float*)& v20);
                *v12 = 16;
                v21 = sub_4F0720(v11, v14);
                if (v21)
                    sub_50EE00(a1, *(float*)& v21);
                *v12 = 16;
                v22 = sub_4F0720(v11, v14);
                if (v22)
                    sub_50EE00(a1, *(float*)& v22);
                *v12 = 1;
                v23 = sub_4F0720(v11, v14);
                if (v23)
                    sub_50EE00(a1, *(float*)& v23);
                *v12 = 1;
                v24 = sub_4F0720(v11, v14);
                if (v24)
                    sub_50EE00(a1, *(float*)& v24);
                *v12 = 1;
                v25 = sub_4F0720(v11, v14);
                if (v25)
                    sub_50EE00(a1, *(float*)& v25);
                *v12 = 1;
                v26 = sub_4F0720(v11, v14);
                if (v26)
                    sub_50EE00(a1, *(float*)& v26);
                *v12 = 1;
                v27 = sub_4F0720(v11, v14);
                if (v27)
                    sub_50EE00(a1, *(float*)& v27);
                *v12 = 1;
                v28 = sub_4F0720(v11, v14);
                if (v28)
                    sub_50EE00(a1, *(float*)& v28);
                *v12 = 4;
                v29 = sub_4F0720(v11, v14);
                if (v29)
                    sub_50EE00(a1, *(float*)& v29);
                *v12 = 4;
                v30 = sub_4F0720(v11, v14);
                if (v30)
                    sub_50EE00(a1, *(float*)& v30);
                *v12 = 4;
                v31 = sub_4F0720(v11, v14);
                if (v31)
                    sub_50EE00(a1, *(float*)& v31);
                if (sub_415FA0(0, 100) > 90)
                {
                    *v12 = 2;
                    v32 = sub_4F0720(v11, v14);
                    if (v32)
                        sub_50EE00(a1, *(float*)& v32);
                }
                sub_4E5CC0(v11);
            }
        }
        else
        {
            v33 = *(_BYTE * *)(v3 + 692);
            v43 = v33;
            if (v33)
            {
                if (*v33)
                {
                    v42 = 0;
                    if (*v33)
                    {
                        v34 = v33 + 8;
                        do
                        {
                            v41 = 0;
                            if (*v34)
                            {
                                do
                                {
                                    v35 = sub_4E3810(*(CHAR * *)(*((_DWORD*)v34 - 1) + 4));
                                    v36 = (int)v35;
                                    if (v35)
                                    {
                                        if (v35[2] & 0x13001000)
                                        {
                                            v37 = *((_DWORD*)v34 + 2);
                                            v38 = *((_DWORD*)v34 + 4);
                                            *(_DWORD*)& v44[4] = *((_DWORD*)v34 + 3);
                                            *(_DWORD*)v44 = v37;
                                            v39 = *((_DWORD*)v34 + 5);
                                            *(_DWORD*)& v44[8] = v38;
                                            *(_DWORD*)& v44[12] = v39;
                                            sub_4E4990(v36, (int*)v44);
                                        }
                                        if (*(int(__cdecl * *)(int*))(v36 + 704) == sub_4F5F30)
                                            ** (_BYTE * *)(v36 + 736) = v34[4];
                                        if (*(int(__cdecl * *)(int*))(v36 + 704) == sub_4F6240)
                                            ** (_BYTE * *)(v36 + 736) = v34[4];
                                        if (*(int(__cdecl * *)(int*))(v36 + 704) == sub_4F6390)
                                        {
                                            strcpy(*(char**)(v36 + 736), (const char*)sub_4E3A80(*((_DWORD*)v34 + 1)));
                                            v1 = a1;
                                            v33 = v43;
                                        }
                                        sub_50EE00(v1, *(float*)& v36);
                                    }
                                    ++v41;
                                } while (v41 < *v34);
                            }
                            v34 += 28;
                            ++v42;
                        } while (v42 < (unsigned __int8)* v33);
                    }
                }
            }
        }
    }
}

//----- (0050EE00) --------------------------------------------------------
float* __cdecl sub_50EE00(int a1, float a2)
{
    float* result; // eax
    float* v3; // esi
    unsigned int v4; // ebx
    int v5; // edi
    _DWORD* i; // eax
    int v7; // eax

    result = (float*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386496]);
    v3 = result;
    if (result)
    {
        *result = a2;
        *((_DWORD*)result + 1) = sub_50E3D0(1, a1, a2);
        v4 = sub_50EEC0(v3);
        if (*(_DWORD*)(a1 + 20))
        {
            if (v4 <= sub_50EEC0(*(_DWORD * *)(a1 + 20)))
            {
                v3[3] = 0.0;
                v3[2] = *(float*)(a1 + 20);
                *(_DWORD*)(*(_DWORD*)(a1 + 20) + 12) = v3;
                *(_DWORD*)(a1 + 20) = v3;
                result = v3;
            }
            else
            {
                v5 = *(_DWORD*)(a1 + 20);
                for (i = *(_DWORD * *)(v5 + 8); i; i = *(_DWORD * *)(v5 + 8))
                {
                    if (v4 <= sub_50EEC0(i))
                        break;
                    v5 = *(_DWORD*)(v5 + 8);
                }
                v3[2] = *(float*)(v5 + 8);
                v7 = *(_DWORD*)(v5 + 8);
                if (v7)
                    * (_DWORD*)(v7 + 12) = v3;
                *(_DWORD*)(v5 + 8) = v3;
                *((_DWORD*)v3 + 3) = v5;
                result = v3;
            }
        }
        else
        {
            v3[2] = 0.0;
            v3[3] = 0.0;
            *(_DWORD*)(a1 + 20) = v3;
            result = v3;
        }
    }
    return result;
}

//----- (0050EEC0) --------------------------------------------------------
int __cdecl sub_50EEC0(_DWORD* a1)
{
    int v1; // ecx
    int v2; // eax
    unsigned __int8* v3; // edx

    v1 = 16781312;
    v2 = 255;
    v3 = &byte_581450[10308];
    do
    {
        if (*(_DWORD*)(*a1 + 8) & v1 && (!*(_DWORD*)v3 || *(_DWORD*)v3 & *(_DWORD*)(*a1 + 12)))
            break;
        v1 = *((_DWORD*)v3 + 1);
        v3 += 8;
        --v2;
    } while (v1);
    return a1[1] | (v2 << 24);
}

//----- (0050EF10) --------------------------------------------------------
_DWORD* __cdecl sub_50EF10(int a1, int a2)
{
    int v2; // edx
    int v3; // eax
    wchar_t* v4; // eax
    int v6; // ecx
    int v7; // eax
    wchar_t* v8; // eax
    _DWORD* v9; // esi
    char v10; // al
    int v11; // eax
    int v12; // eax
    int v13; // [esp-4h] [ebp-114h]
    wchar_t v14[128]; // [esp+10h] [ebp-100h]

    v2 = *(_DWORD*)(a1 + 8) & 4;
    if (v2)
    {
        v3 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 280);
        if (v3)
        {
            if (*(_DWORD*)(v3 + 12) != a2)
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[235924], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 1836);
                sub_4D9EB0(a1, v4);
            }
            return 0;
        }
    }
    v6 = *(_DWORD*)(a2 + 8) & 4;
    if (v6)
    {
        v7 = *(_DWORD*)(a2 + 748);
        if (*(_DWORD*)(v7 + 280))
        {
            if (v2)
            {
                v13 = *(_DWORD*)(v7 + 276) + 4704;
                v8 = loadString_sub_40F1D0((char*)& byte_587000[235988], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 1878);
                nox_swprintf(v14, v8, v13);
                sub_4D9EB0(a1, v14);
            }
            return 0;
        }
    }
    if (v2)
    {
        if (!v6)
        {
            v9 = sub_50E8F0(a1, a2);
            goto LABEL_18;
        }
    }
    else if (!v6)
    {
        goto LABEL_17;
    }
    if (!v2)
    {
        v9 = sub_50E8F0(a2, a1);
        goto LABEL_18;
    }
LABEL_17:
    v9 = sub_50E870();
    v9[2] = a1;
    v9[3] = a2;
LABEL_18:
    if (!v9)
        return 0;
    v9[1] = *(_DWORD*)& byte_5D4594[2598000];
    sub_50F370(v9, a1);
    sub_50F370(v9, a2);
    v10 = *(_BYTE*)(a1 + 8);
    if (v9[4])
    {
        if (v10 & 4)
            sub_50F0F0(a1, (int)v9);
        if (*(_BYTE*)(a2 + 8) & 4)
            sub_50F0F0(a2, (int)v9);
    }
    else
    {
        if (v10 & 4)
            sub_50F1A0(a1, (int)v9);
        if (*(_BYTE*)(a2 + 8) & 4)
            sub_50F1A0(a2, (int)v9);
    }
    if (v9[4])
    {
        v11 = v9[2];
        if (*(_BYTE*)(v11 + 8) & 4)
            sub_50F280(v11, (int)v9);
        else
            sub_50F280(v9[3], (int)v9);
        if (v9[4] && sub_40A5C0(2048))
        {
            v12 = v9[2];
            if (!(*(_BYTE*)(v12 + 8) & 4))
                v12 = v9[3];
            sub_4E79C0(v12, 0);
        }
    }
    return v9;
}

//----- (0050F0F0) --------------------------------------------------------
int __cdecl sub_50F0F0(int a1, int a2)
{
    int v2; // ebx
    int v3; // ebp
    wchar_t* v4; // eax
    char v6[86]; // [esp+10h] [ebp-58h]

    *(_WORD*)v6 = 3529;
    v2 = *(_DWORD*)(a2 + 8);
    if (*(_BYTE*)(v2 + 8) & 4)
    {
        v3 = *(_DWORD*)(a2 + 8);
        v2 = *(_DWORD*)(a2 + 12);
    }
    else
    {
        v3 = *(_DWORD*)(a2 + 12);
    }
    v4 = sub_4E39F0((const char**)v2);
    nox_wcsncpy((wchar_t*)& v6[4], v4, 0x18u);
    *(_WORD*)& v6[52] = 0;
    strcpy(&v6[54], (const char*)(*(_DWORD*)(v2 + 692) + 1684));
    *(_WORD*)& v6[2] = *(_WORD*)(v2 + 4);
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 2064), (int)v6, 86, 0, 1);
}

//----- (0050F1A0) --------------------------------------------------------
int __cdecl sub_50F1A0(int a1, int a2)
{
    int v2; // eax
    int v3; // esi
    int v4; // edx
    wchar_t* v6; // [esp-8h] [ebp-40h]
    wchar_t* v7; // [esp-8h] [ebp-40h]
    char v8[52]; // [esp+4h] [ebp-34h]

    *(_WORD*)v8 = 3273;
    v2 = *(_DWORD*)(a2 + 8);
    v3 = *(_DWORD*)(a1 + 748);
    if (a1 != v2)
    {
        if (*(_BYTE*)(v2 + 8) & 4)
        {
            nox_wcscpy((wchar_t*)& v8[2], (const wchar_t*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 4704));
            return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
        }
        v7 = sub_4E39F0(*(const char***)(a2 + 12));
        nox_wcsncpy((wchar_t*)& v8[2], v7, 0x18u);
    LABEL_8:
        *(_WORD*)& v8[50] = 0;
        return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
    }
    v4 = *(_DWORD*)(a2 + 12);
    if (!(*(_BYTE*)(v4 + 8) & 4))
    {
        v6 = sub_4E39F0((const char**)v4);
        nox_wcsncpy((wchar_t*)& v8[2], v6, 0x18u);
        goto LABEL_8;
    }
    nox_wcscpy((wchar_t*)& v8[2], (const wchar_t*)(*(_DWORD*)(*(_DWORD*)(v4 + 748) + 276) + 4704));
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
}

//----- (0050F280) --------------------------------------------------------
int __cdecl sub_50F280(int a1, int a2)
{
    int result; // eax
    _DWORD* i; // esi

    result = a2;
    for (i = *(_DWORD * *)(a2 + 20); i; i = (_DWORD*)i[2])
        result = sub_50F2B0(a1, i);
    return result;
}

//----- (0050F2B0) --------------------------------------------------------
int __cdecl sub_50F2B0(int a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // ecx
    int v4; // esi
    int v5; // edx
    unsigned __int16* v6; // ecx
    int i; // eax
    char v9[18]; // [esp+8h] [ebp-14h]

    v2 = *a2;
    v3 = a2[1];
    v4 = *(_DWORD*)(a1 + 748);
    v5 = *(_DWORD*)(*a2 + 692);
    v9[0] = -55;
    v9[1] = 8;
    *(_WORD*)& v9[4] = *(_WORD*)(v2 + 36);
    *(_WORD*)& v9[2] = *(_WORD*)(v2 + 4);
    *(_DWORD*)& v9[6] = v3;
    v6 = *(unsigned __int16**)(v2 + 556);
    if (v6)
        * (_DWORD*)& v9[10] = *v6;
    else
        *(_DWORD*)& v9[10] = 0;
    if (*(_DWORD*)(v2 + 8) & 0x13001000)
    {
        for (i = 0; i < 4; ++i)
        {
            if (*(_DWORD*)v5)
                v9[i + 14] = *(_BYTE*)(*(_DWORD*)v5 + 4);
            else
                v9[i + 14] = -1;
            v5 += 4;
        }
    }
    else
    {
        *(_DWORD*)& v9[14] = -1;
    }
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)v9, 18, 0, 1);
}

//----- (0050F370) --------------------------------------------------------
_DWORD* __cdecl sub_50F370(_DWORD* a1, int a2)
{
    _DWORD* result; // eax

    result = a1;
    *a1 = 1;
    if (*(_BYTE*)(a2 + 8) & 4)
        * (_DWORD*)(*(_DWORD*)(a2 + 748) + 280) = a1;
    return result;
}

//----- (0050F3A0) --------------------------------------------------------
void __cdecl sub_50F3A0(_DWORD* a1)
{
    int* i; // edi
    int* j; // edi

    for (i = (int*)a1[8]; i; i = (int*)i[2])
        sub_4F3070(a1[2], *i, 1);
    sub_4FA590(a1[2], **(_DWORD * *)(a1[12] + 692));
    sub_50F450(a1[2]);
    for (j = (int*)a1[9]; j; j = (int*)j[2])
        sub_4F3070(a1[3], *j, 1);
    sub_4FA590(a1[3], **(_DWORD * *)(a1[13] + 692));
    sub_50F450(a1[3]);
    sub_50F490(a1, a1[2]);
    sub_50F490(a1, a1[3]);
    sub_510000((int)a1);
}

//----- (0050F450) --------------------------------------------------------
int __cdecl sub_50F450(int a1)
{
    int v2; // edx
    char v4[2]; // [esp+0h] [ebp-2h]

    v2 = *(_DWORD*)(a1 + 748);
    *(_WORD*)v4 = 457;
    return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 2, 0, 1);
}

//----- (0050F490) --------------------------------------------------------
int __cdecl sub_50F490(_DWORD* a1, int a2)
{
    int result; // eax

    result = a2;
    *a1 = 0;
    if (*(_BYTE*)(a2 + 8) & 4)
    {
        result = *(_DWORD*)(a2 + 748);
        if (*(_DWORD * *)(result + 280) == a1)
            * (_DWORD*)(result + 280) = 0;
    }
    return result;
}

//----- (0050F4C0) --------------------------------------------------------
void __cdecl sub_50F4C0(_DWORD* a1)
{
    int v1; // eax
    int v2; // eax
    int v3; // edi

    sub_50F490(a1, a1[2]);
    sub_50F490(a1, a1[3]);
    v1 = a1[2];
    if (*(_BYTE*)(v1 + 8) & 4)
        sub_4E7A60(v1, 0);
    else
        sub_4E7A60(a1[3], 0);
    v2 = a1[2];
    if (*(_BYTE*)(v2 + 8) & 4)
    {
        sub_50F560(v2);
        v3 = a1[2];
    }
    else
    {
        sub_50F560(a1[3]);
        v3 = a1[3];
    }
    if (sub_40A5C0(4096))
        * (_DWORD*)& byte_5D4594[4 * *(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 2064) + 2386364] = a1;
    else
        sub_510000((int)a1);
}

//----- (0050F560) --------------------------------------------------------
int __cdecl sub_50F560(int a1)
{
    int v2; // edx
    __int16 v4; // [esp+0h] [ebp-2h]

    v2 = *(_DWORD*)(a1 + 748);
    v4 = 713;
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (int)& v4, 2, 0, 1);
}

//----- (0050F5A0) --------------------------------------------------------
void __cdecl sub_50F5A0(int a1, int a2)
{
    int v2; // eax
    int v3; // eax
    int v4; // ecx
    int v5; // eax
    int v6; // eax
    int v7; // [esp-34h] [ebp-3Ch]

    v2 = *(_DWORD*)(a1 + 8);
    if (v2 == a2)
    {
        *(_DWORD*)(a1 + 24) = 1;
    }
    else if (*(_DWORD*)(a1 + 12) == a2)
    {
        *(_DWORD*)(a1 + 28) = 1;
    }
    if (*(_BYTE*)(v2 + 8) & 4)
        sub_50F720(v2, (_DWORD*)a1);
    v3 = *(_DWORD*)(a1 + 12);
    if (*(_BYTE*)(v3 + 8) & 4)
        sub_50F720(v3, (_DWORD*)a1);
    if (*(_DWORD*)(a1 + 24) == 1 && *(_DWORD*)(a1 + 28) == 1)
    {
        sub_50F790(a1, *(_DWORD*)(a1 + 12), *(int**)(a1 + 32));
        sub_50F790(a1, *(_DWORD*)(a1 + 8), *(int**)(a1 + 36));
        sub_50F7F0(*(_DWORD*)(a1 + 12), *(_DWORD*)(a1 + 48));
        sub_50F7F0(*(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 52));
        sub_50F6B0(*(_DWORD*)(a1 + 32));
        v7 = *(_DWORD*)(a1 + 36);
        *(_DWORD*)(a1 + 32) = 0;
        sub_50F6B0(v7);
        v4 = *(_DWORD*)(a1 + 48);
        *(_DWORD*)(a1 + 36) = 0;
        **(_DWORD * *)(v4 + 692) = 0;
        **(_DWORD * *)(*(_DWORD*)(a1 + 52) + 692) = 0;
        v5 = *(_DWORD*)(a1 + 16);
        *(_DWORD*)(a1 + 40) = 0;
        *(_DWORD*)(a1 + 44) = 0;
        if (v5 == 1)
        {
            v6 = *(_DWORD*)(a1 + 8);
            if (*(_BYTE*)(v6 + 8) & 4)
                sub_50F6E0(v6);
            else
                sub_50F6E0(*(_DWORD*)(a1 + 12));
        }
        else
        {
            sub_50F3A0((_DWORD*)a1);
        }
    }
}

//----- (0050F6B0) --------------------------------------------------------
int __cdecl sub_50F6B0(int a1)
{
    int result; // eax
    int v2; // esi

    result = a1;
    if (a1)
    {
        do
        {
            v2 = *(_DWORD*)(result + 8);
            sub_414330(*(unsigned int**)& byte_5D4594[2386496], (_QWORD*)result);
            result = v2;
        } while (v2);
    }
    return result;
}

//----- (0050F6E0) --------------------------------------------------------
int __cdecl sub_50F6E0(int a1)
{
    int v2; // edx
    __int16 v4; // [esp+0h] [ebp-2h]

    v2 = *(_DWORD*)(a1 + 748);
    v4 = 1993;
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (int)& v4, 2, 0, 1);
}

//----- (0050F720) --------------------------------------------------------
int __cdecl sub_50F720(int a1, _DWORD* a2)
{
    int v2; // edx
    int v3; // edi
    int v4; // esi
    char v5; // al
    char v6; // al

    v2 = a1;
    v3 = a2[6];
    v4 = *(_DWORD*)(a1 + 748);
    v5 = 0;
    LOWORD(a1) = 969;
    BYTE2(a1) = 0;
    if (v3)
    {
        v5 = (a2[2] != v2) + 1;
        BYTE2(a1) = (a2[2] != v2) + 1;
    }
    if (a2[7])
    {
        if (a2[3] == v2)
            v6 = v5 | 1;
        else
            v6 = v5 | 2;
        BYTE2(a1) = v6;
    }
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)& a1, 3, 0, 1);
}

//----- (0050F790) --------------------------------------------------------
void __cdecl sub_50F790(int a1, int a2, int* a3)
{
    int* i; // esi
    float* v4; // eax
    int v5; // ecx

    for (i = a3; i; i = (int*)i[2])
    {
        if (*(_BYTE*)(a2 + 8) & 4)
        {
            sub_4F3070(a2, *i, 1);
        }
        else
        {
            v4 = sub_50EE00(a1, *(float*)i);
            if (v4)
            {
                v5 = *(_DWORD*)(a1 + 8);
                if (*(_BYTE*)(v5 + 8) & 4)
                    sub_50F2B0(v5, v4);
                else
                    sub_50F2B0(*(_DWORD*)(a1 + 12), v4);
            }
        }
    }
}

//----- (0050F7F0) --------------------------------------------------------
_DWORD* __cdecl sub_50F7F0(int a1, int a2)
{
    _DWORD* result; // eax

    result = (_DWORD*)a1;
    if (*(_BYTE*)(a1 + 8) & 4)
        result = sub_4FA590(a1, **(_DWORD * *)(a2 + 692));
    return result;
}

//----- (0050F820) --------------------------------------------------------
int __cdecl sub_50F820(int a1, int a2, float a3)
{
    float v3; // ebx
    int result; // eax
    int* v5; // eax
    int* v6; // edi
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // eax
    int v12; // eax

    if (!*(_DWORD*)& byte_5D4594[2386516])
        * (_DWORD*)& byte_5D4594[2386516] = sub_4E3AA0((CHAR*)& byte_587000[236008]);
    if (*(_DWORD*)(a1 + 8) == a2)
    {
        v3 = a3;
        if (!sub_50FD60(*(_DWORD * *)(a1 + 32), SLODWORD(a3)))
            return 0;
    }
    else
    {
        if (*(_DWORD*)(a1 + 12) != a2)
            return 0;
        v3 = a3;
        if (!sub_50FD60(*(_DWORD * *)(a1 + 36), SLODWORD(a3)))
            return 0;
    }
    v5 = (int*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386496]);
    v6 = v5;
    if (v5)
    {
        *(float*)v5 = v3;
        v5[2] = 0;
        v5[3] = 0;
        v5[1] = sub_50E3D0(1, a1, v3);
        if (*(_DWORD*)(a1 + 8) == a2)
        {
            v6[2] = *(_DWORD*)(a1 + 32);
            v9 = *(_DWORD*)(a1 + 32);
            if (v9)
                * (_DWORD*)(v9 + 12) = v6;
            *(_DWORD*)(a1 + 32) = v6;
        }
        else
        {
            v6[2] = *(_DWORD*)(a1 + 36);
            v10 = *(_DWORD*)(a1 + 36);
            if (v10)
                * (_DWORD*)(v10 + 12) = v6;
            *(_DWORD*)(a1 + 36) = v6;
        }
        sub_50FB90((_DWORD*)a1);
        v11 = *(_DWORD*)(a1 + 8);
        *(_DWORD*)(a1 + 24) = 0;
        *(_DWORD*)(a1 + 28) = 0;
        if (*(_BYTE*)(v11 + 8) & 4)
        {
            if (!(*(_BYTE*)(*(_DWORD*)(a1 + 12) + 8) & 4) && *(_DWORD*)(a1 + 44) <= *(int*)(a1 + 40))
                * (_DWORD*)(a1 + 28) = 1;
        }
        else if (*(_DWORD*)(a1 + 40) <= *(int*)(a1 + 44))
        {
            *(_DWORD*)(a1 + 24) = 1;
        }
        if (*(_BYTE*)(v11 + 8) & 4)
        {
            sub_50FA00(v11, (_DWORD*)a1);
            sub_50FAE0(*(_DWORD*)(a1 + 8), a2, a1, *v6, v6[1]);
            sub_50F720(*(_DWORD*)(a1 + 8), (_DWORD*)a1);
        }
        v12 = *(_DWORD*)(a1 + 12);
        if (*(_BYTE*)(v12 + 8) & 4)
        {
            sub_50FA00(v12, (_DWORD*)a1);
            sub_50FAE0(*(_DWORD*)(a1 + 12), a2, a1, *v6, v6[1]);
            sub_50F720(*(_DWORD*)(a1 + 12), (_DWORD*)a1);
        }
        result = 1;
    }
    else
    {
        if (*(_BYTE*)(*(_DWORD*)(a1 + 8) + 8) & 4)
        {
            v7 = loadString_sub_40F1D0((char*)& byte_587000[236056], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 2487);
            sub_4D9EB0(*(_DWORD*)(a1 + 8), v7);
        }
        if (!(*(_BYTE*)(*(_DWORD*)(a1 + 12) + 8) & 4))
            return 0;
        v8 = loadString_sub_40F1D0((char*)& byte_587000[236120], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 2490);
        sub_4D9EB0(*(_DWORD*)(a1 + 12), v8);
        result = 0;
    }
    return result;
}

//----- (0050FA00) --------------------------------------------------------
int __cdecl sub_50FA00(int a1, _DWORD* a2)
{
    int v2; // edx
    int v3; // esi
    int v4; // edx
    int v5; // edx
    char v7[14]; // [esp+4h] [ebp-10h]

    v7[0] = -55;
    v2 = a2[2];
    v3 = *(_DWORD*)(a1 + 748);
    v7[1] = 6;
    if (v2 == a1)
    {
        v4 = a2[3];
        *(_DWORD*)& v7[2] = **(_DWORD * *)(a2[12] + 692);
        if (*(_BYTE*)(v4 + 8) & 4)
        {
            v5 = a2[13];
            *(_DWORD*)& v7[6] = 0;
        }
        else
        {
            v5 = a2[13];
            *(_DWORD*)& v7[6] = a2[11] - a2[10];
        }
        *(_DWORD*)& v7[10] = **(_DWORD * *)(v5 + 692);
    }
    else if (a2[3] == a1)
    {
        *(_DWORD*)& v7[2] = **(_DWORD * *)(a2[13] + 692);
        if (*(_BYTE*)(v2 + 8) & 4)
            * (_DWORD*)& v7[6] = 0;
        else
            *(_DWORD*)& v7[6] = a2[10] - a2[11];
        *(_DWORD*)& v7[10] = **(_DWORD * *)(a2[12] + 692);
    }
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), (int)v7, 14, 0, 1);
}

//----- (0050FAE0) --------------------------------------------------------
int __cdecl sub_50FAE0(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // esi
    __int16 v6; // dx
    int v7; // ecx
    int v8; // edx
    int i; // eax
    char v11[15]; // [esp+4h] [ebp-10h]

    v5 = *(_DWORD*)(a1 + 748);
    v11[0] = -55;
    v11[2] = a1 == a2;
    v11[1] = 4;
    v6 = *(_WORD*)(a4 + 36);
    *(_WORD*)& v11[3] = *(_WORD*)(a4 + 4);
    *(_DWORD*)& v11[7] = a5;
    v7 = *(_DWORD*)(a4 + 8);
    *(_WORD*)& v11[5] = v6;
    if (v7 & 0x13001000)
    {
        v8 = *(_DWORD*)(a4 + 692);
        for (i = 0; i < 4; ++i)
        {
            if (*(_DWORD*)v8)
                v11[i + 11] = *(_BYTE*)(*(_DWORD*)v8 + 4);
            else
                v11[i + 11] = -1;
            v8 += 4;
        }
    }
    else
    {
        *(_DWORD*)& v11[11] = -1;
    }
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)v11, 15, 0, 1);
}

//----- (0050FB90) --------------------------------------------------------
_DWORD* __cdecl sub_50FB90(_DWORD* a1)
{
    int v1; // ecx
    _DWORD* result; // eax
    int* v3; // edi
    int v4; // eax
    int* v5; // edi
    int v6; // eax
    int v7; // ecx
    unsigned int v8; // ecx
    unsigned int v9; // edi
    unsigned int v10; // eax
    int v11; // eax
    unsigned int v12; // edi
    unsigned int v13; // eax
    int v14; // ecx

    v1 = a1[2];
    result = (_DWORD*)(*(_DWORD*)(v1 + 8) & 4);
    if (result != (_DWORD*)4 || (*(_BYTE*)(a1[3] + 8) & 4) != 4)
    {
        v3 = *(int**)(a1[12] + 692);
        if (result)
            sub_4FA590(v1, *v3);
        *v3 = 0;
        v4 = a1[3];
        v5 = *(int**)(a1[13] + 692);
        if (*(_BYTE*)(v4 + 8) & 4)
            sub_4FA590(v4, *v5);
        *v5 = 0;
        v6 = sub_50FD20(a1, a1[2]);
        v7 = a1[3];
        a1[10] = v6;
        result = (_DWORD*)sub_50FD20(a1, v7);
        v8 = a1[10];
        a1[11] = result;
        if ((unsigned int)result <= v8)
        {
            if ((unsigned int)result < v8)
            {
                v12 = v8 - (_DWORD)result;
                if (*(_BYTE*)(a1[3] + 8) & 4)
                {
                    v13 = sub_4FA6B0(a1[3]);
                    if (v13 < v12)
                    {
                        a1[11] += v13;
                        **(_DWORD * *)(a1[13] + 692) += v13;
                        result = sub_4FA5D0(a1[3], v13);
                    }
                    else
                    {
                        v14 = a1[13];
                        a1[11] += v12;
                        **(_DWORD * *)(v14 + 692) += v12;
                        result = sub_4FA5D0(a1[3], v12);
                    }
                }
                else
                {
                    a1[11] = v8;
                    result = *(_DWORD * *)(a1[13] + 692);
                    *result += v12;
                }
            }
        }
        else
        {
            v9 = (unsigned int)result - v8;
            if (*(_BYTE*)(a1[2] + 8) & 4)
            {
                v10 = sub_4FA6B0(a1[2]);
                if (v10 < v9)
                {
                    a1[10] += v10;
                    **(_DWORD * *)(a1[12] + 692) += v10;
                    result = sub_4FA5D0(a1[2], v10);
                }
                else
                {
                    a1[10] += v9;
                    **(_DWORD * *)(a1[12] + 692) += v9;
                    result = sub_4FA5D0(a1[2], v9);
                }
            }
            else
            {
                v11 = a1[12];
                a1[10] = v9 + v8;
                result = *(_DWORD * *)(v11 + 692);
                *result += v9;
            }
        }
    }
    return result;
}

//----- (0050FD20) --------------------------------------------------------
int __cdecl sub_50FD20(_DWORD* a1, int a2)
{
    int v2; // edx
    int v3; // ecx
    int result; // eax
    int v5; // edx

    if (a1[2] == a2)
    {
        v2 = a1[12];
        v3 = a1[8];
    }
    else
    {
        v2 = a1[13];
        v3 = a1[9];
    }
    for (result = **(_DWORD * *)(v2 + 692); v3; result += v5)
    {
        v5 = *(_DWORD*)(v3 + 4);
        v3 = *(_DWORD*)(v3 + 8);
    }
    return result;
}

//----- (0050FD60) --------------------------------------------------------
BOOL __cdecl sub_50FD60(_DWORD* a1, int a2)
{
    _DWORD* v2; // esi
    unsigned int v3; // edi
    unsigned int v4; // ecx
    int v5; // eax
    int* v6; // edx
    int v7; // ecx
    int v8; // eax
    int v9; // edx
    int* i; // ecx
    int v12[4]; // [esp+8h] [ebp-20h]
    int v13[4]; // [esp+18h] [ebp-10h]

    v13[0] = 0;
    v12[0] = 0;
    v2 = a1;
    v13[1] = 0;
    v12[1] = 0;
    v3 = 0;
    v13[2] = 0;
    v12[2] = 0;
    v13[3] = 0;
    for (v12[3] = 0; v2; v2 = (_DWORD*)v2[2])
    {
        v4 = 0;
        v5 = *(unsigned __int16*)(*v2 + 4);
        v6 = v13;
        while (*v6 != v5)
        {
            ++v4;
            ++v6;
            if (v4 >= 4)
            {
                v7 = v12[v3];
                v13[v3] = v5;
                v12[v3++] = v7 + 1;
                goto LABEL_6;
            }
        }
        ++v12[v4];
    LABEL_6:
        ;
    }
    v8 = 0;
    if (!v3)
        return 1;
    HIWORD(v9) = 0;
    for (i = v13; ; ++i)
    {
        LOWORD(v9) = *(_WORD*)(a2 + 4);
        if (*i == v9 && !(*(_DWORD*)(a2 + 8) & 0x13001000))
            break;
        if (++v8 >= v3)
            return v3 < 4;
    }
    return 1;
}

//----- (0050FE20) --------------------------------------------------------
int __cdecl sub_50FE20(int a1, int a2)
{
    int* v2; // edi
    int v3; // ebp
    int result; // eax
    float* v5; // eax
    int v6; // ecx
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // eax

    v2 = sub_50FFE0(*(_DWORD * *)(a1 + 32), a2);
    if (v2)
    {
        v3 = *(_DWORD*)(a1 + 8);
    }
    else
    {
        result = sub_50FFE0(*(_DWORD * *)(a1 + 36), a2);
        v2 = (int*)result;
        if (!result)
            return result;
        v3 = *(_DWORD*)(a1 + 12);
    }
    if (*(_BYTE*)(v3 + 8) & 4)
    {
        sub_4F3070(v3, *v2, 1);
    }
    else
    {
        v5 = sub_50EE00(a1, *(float*)v2);
        if (v5)
        {
            v6 = *(_DWORD*)(a1 + 8);
            if (!(*(_BYTE*)(v6 + 8) & 4))
                v6 = *(_DWORD*)(a1 + 12);
            sub_50F2B0(v6, v5);
        }
    }
    v7 = v2[2];
    if (v7)
        * (_DWORD*)(v7 + 12) = v2[3];
    v8 = v2[3];
    if (v8)
        * (_DWORD*)(v8 + 8) = v2[2];
    if (*(_DWORD*)(a1 + 8) == v3)
    {
        if (*(int**)(a1 + 32) == v2)
            * (_DWORD*)(a1 + 32) = v2[2];
    }
    else if (*(int**)(a1 + 36) == v2)
    {
        *(_DWORD*)(a1 + 36) = v2[2];
    }
    sub_50FB90((_DWORD*)a1);
    *(_DWORD*)(a1 + 24) = 0;
    *(_DWORD*)(a1 + 28) = 0;
    v9 = *(_DWORD*)(a1 + 8);
    if (*(_BYTE*)(v9 + 8) & 4)
    {
        if (!(*(_BYTE*)(*(_DWORD*)(a1 + 12) + 8) & 4) && *(_DWORD*)(a1 + 44) <= *(int*)(a1 + 40))
            * (_DWORD*)(a1 + 28) = 1;
    }
    else if (*(_DWORD*)(a1 + 40) <= *(int*)(a1 + 44))
    {
        *(_DWORD*)(a1 + 24) = 1;
    }
    if (*(_BYTE*)(v9 + 8) & 4)
    {
        sub_50FA00(v9, (_DWORD*)a1);
        sub_50FF90(*(_DWORD*)(a1 + 8), a1, *v2);
        sub_50F720(*(_DWORD*)(a1 + 8), (_DWORD*)a1);
    }
    v10 = *(_DWORD*)(a1 + 12);
    if (*(_BYTE*)(v10 + 8) & 4)
    {
        sub_50FA00(v10, (_DWORD*)a1);
        sub_50FF90(*(_DWORD*)(a1 + 12), a1, *v2);
        sub_50F720(*(_DWORD*)(a1 + 12), (_DWORD*)a1);
    }
    sub_414330(*(unsigned int**)& byte_5D4594[2386496], v2);
    return 1;
}

//----- (0050FF90) --------------------------------------------------------
int __cdecl sub_50FF90(int a1, int a2, int a3)
{
    int v4; // ecx
    int v6; // [esp+0h] [ebp-4h]

    HIWORD(v6) = *(_WORD*)(a3 + 36);
    v4 = *(_DWORD*)(a1 + 748);
    LOWORD(v6) = 1481;
    return sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)& v6, 4, 0, 1);
}

//----- (0050FFE0) --------------------------------------------------------
_DWORD* __cdecl sub_50FFE0(_DWORD* a1, int a2)
{
    _DWORD* result; // eax

    result = a1;
    if (!a1)
        return 0;
    while (*(_DWORD*)(*result + 36) != a2)
    {
        result = (_DWORD*)result[2];
        if (!result)
            return 0;
    }
    return result;
}

//----- (00510000) --------------------------------------------------------
void __cdecl sub_510000(int a1)
{
    int* v1; // esi
    int* v2; // ebx
    int v3; // eax
    int v4; // eax

    v1 = *(int**)(a1 + 20);
    if (v1)
    {
        do
        {
            v2 = (int*)v1[2];
            sub_4E38A0(*v1);
            sub_414330(*(unsigned int**)& byte_5D4594[2386496], v1);
            v1 = v2;
        } while (v2);
    }
    sub_4E38A0(*(_DWORD*)(a1 + 48));
    sub_4E38A0(*(_DWORD*)(a1 + 52));
    sub_50F6B0(*(_DWORD*)(a1 + 32));
    sub_50F6B0(*(_DWORD*)(a1 + 36));
    v3 = *(_DWORD*)(a1 + 56);
    if (v3)
        * (_DWORD*)(v3 + 60) = *(_DWORD*)(a1 + 60);
    v4 = *(_DWORD*)(a1 + 60);
    if (v4)
        * (_DWORD*)(v4 + 56) = *(_DWORD*)(a1 + 56);
    if (a1 == *(_DWORD*)& byte_5D4594[2386500])
        * (_DWORD*)& byte_5D4594[2386500] = *(_DWORD*)(a1 + 56);
    sub_414330(*(unsigned int**)& byte_5D4594[2386492], (_QWORD*)a1);
}

//----- (005100A0) --------------------------------------------------------
int __cdecl sub_5100A0(int a1, int a2)
{
    int* v2; // eax
    int result; // eax

    v2 = sub_50FFE0(*(_DWORD * *)(a1 + 20), a2);
    if (v2)
        result = *v2;
    else
        result = 0;
    return result;
}

//----- (005100C0) --------------------------------------------------------
float* __cdecl sub_5100C0(int a1, _DWORD* a2, int a3)
{
    int v3; // edi
    unsigned int v4; // ebx
    float* result; // eax
    int v6; // esi
    unsigned int v7; // eax
    unsigned int v8; // ebp
    int v9; // ebx
    wchar_t* v10; // eax
    int v11; // eax
    int v12; // ebx
    _DWORD* v13; // eax
    void(__cdecl * v14)(int, _DWORD*, int, int); // ecx
    int v15; // [esp+0h] [ebp-14h]
    float v16; // [esp+0h] [ebp-14h]
    float v17; // [esp+0h] [ebp-14h]
    int v18; // [esp+18h] [ebp+4h]

    v3 = a1;
    v15 = a1;
    v18 = *(_DWORD*)(a1 + 748);
    v4 = sub_4FA6B0(v15);
    if (!*(_DWORD*)& byte_5D4594[2386548])
        * (_DWORD*)& byte_5D4594[2386548] = sub_4E3AA0((CHAR*)& byte_587000[236144]);
    result = (float*)a2[5];
    if (result)
    {
        while (!*(_DWORD*)result || *(_DWORD*)(*(_DWORD*)result + 36) != a3)
        {
            result = (float*) * ((_DWORD*)result + 2);
            if (!result)
                return result;
        }
        v6 = *(_DWORD*)result;
        if (*(_DWORD*)result)
        {
            v7 = sub_50E3D0(1, (int)a2, *result);
            v8 = v7;
            if (v7 > v4)
                return (float*)sub_5104F0(v3, v7 - v4);
            if (*(_BYTE*)(v6 + 8) & 0x10)
            {
                v9 = sub_4E7D30(v3, *(unsigned __int16*)(v6 + 4));
                if (v9 >= (sub_40A5C0(6144) ? 9 : 3))
                {
                    v10 = loadString_sub_40F1D0((char*)& byte_587000[236200], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 2943);
                    return (float*)sub_4D9EB0(v3, v10);
                }
            }
            if (*(unsigned __int16*)(v6 + 4) == *(_DWORD*)& byte_5D4594[2386548])
            {
                v16 = sub_419D40(&byte_587000[236224]);
                if (*(_DWORD*)(v18 + 320) >= sub_419A70(v16))
                {
                    sub_4DA2C0(v3, "pickup.c:MaxTradableAnkhsReached", 0);
                    return (float*)sub_501960(925, v3, 0, 0);
                }
            }
            if (sub_40A5C0(4096))
            {
                v11 = *(_DWORD*)(v6 + 8);
                if (v11 & 0x1000)
                {
                    if (*(_DWORD*)(v6 + 12) & 0x200000)
                    {
                        v17 = sub_419D40(&byte_587000[236276]);
                        v12 = sub_419A70(v17);
                        if (sub_4E7D30(v3, *(unsigned __int16*)(v6 + 4)) >= v12)
                        {
                            sub_4DA2C0(v3, "pickup.c:MaxSameItem", 0);
                            return (float*)sub_501960(925, v3, 0, 0);
                        }
                    }
                }
            }
            if (sub_40A5C0(4096) && (sub_5105D0(v6) || *(unsigned __int16*)(v6 + 4) == *(_DWORD*)& byte_5D4594[2386548]))
                v13 = sub_4E3450(*(unsigned __int16*)(v6 + 4));
            else
                v13 = (_DWORD*)v6;
            if (v13[2] & 0x110 || (v14 = (void(__cdecl*)(int, _DWORD*, int, int))v13[177]) == 0)
            {
                sub_4F3070(v3, (int)v13, 1);
                sub_501960(307, v3, 2, *(_DWORD*)(v3 + 36));
            }
            else
            {
                v14(v3, v13, 1, 1);
            }
            sub_510320(v6, (int)a2);
            if (sub_510540(v6))
                sub_50E7A0(a2, v6);
            sub_4FA5D0(v3, v8);
            result = (float*)sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v18 + 276) + 2064), v3);
        }
    }
    return result;
}

//----- (00510320) --------------------------------------------------------
void __cdecl sub_510320(int a1, int a2)
{
    int v2; // ecx
    _BYTE* v3; // ebp
    int v4; // eax
    int v5; // esi
    char v6; // cl
    int v7; // edx
    int v8; // eax

    if (a1 && a2)
    {
        v2 = *(_DWORD*)(a2 + 8);
        if (*(_BYTE*)(v2 + 8) & 4)
            v2 = *(_DWORD*)(a2 + 12);
        v3 = *(_BYTE * *)(v2 + 692);
        v4 = sub_5103A0(a2, a1);
        if (v4 != -1)
        {
            v5 = (int)& v3[28 * v4];
            v6 = v3[28 * v4 + 8] - 1;
            *(_BYTE*)(v5 + 8) = v6;
            if (!v6)
            {
                v7 = v4;
                if (v4 < (unsigned __int8)* v3 - 1)
                {
                    v8 = v5 + 4;
                    do
                    {
                        ++v7;
                        qmemcpy((void*)v8, (const void*)(v8 + 28), 0x1Cu);
                        v8 += 28;
                    } while (v7 < (unsigned __int8)* v3 - 1);
                }
                --* v3;
            }
        }
    }
}

//----- (005103A0) --------------------------------------------------------
int __cdecl sub_5103A0(int a1, int a2)
{
    int v2; // eax
    _BYTE* v3; // edi
    int v4; // esi
    int i; // ebx

    v2 = *(_DWORD*)(a1 + 8);
    if (*(_BYTE*)(v2 + 8) & 4)
        v2 = *(_DWORD*)(a1 + 12);
    v3 = *(_BYTE * *)(v2 + 692);
    v4 = 0;
    if (!*v3)
        return -1;
    for (i = (int)(v3 + 4); !sub_5103F0(a2, i); i += 28)
    {
        if (++v4 >= (unsigned __int8)* v3)
            return -1;
    }
    return v4;
}

//----- (005103F0) --------------------------------------------------------
int __cdecl sub_5103F0(int a1, int a2)
{
    int v2; // ebp
    int v3; // esi
    _DWORD* v4; // edx
    int v5; // edx

    v2 = 0;
    if (!a1 || !a2)
        return 0;
    if (*(_WORD*)(a1 + 4) == **(_WORD * *)a2)
    {
        v3 = *(_DWORD*)(a1 + 8);
        v2 = 1;
        if (v3 & 0x13001000)
        {
            v4 = *(_DWORD * *)(a1 + 692);
            if (*(_DWORD*)(a2 + 12) != *v4)
                v2 = 0;
            if (*(_DWORD*)(a2 + 16) != v4[1])
                v2 = 0;
            if (*(_DWORD*)(a2 + 20) != v4[2])
                v2 = 0;
            if (*(_DWORD*)(a2 + 24) != v4[3])
                v2 = 0;
        }
        if (v3 & 0x100)
        {
            v5 = *(_DWORD*)(a1 + 12);
            if (v5 & 1 || v5 & 4)
            {
                if (**(unsigned __int8**)(a1 + 736) != *(_DWORD*)(a2 + 8))
                    return 0;
            }
            else if (strcmp(*(const char**)(a1 + 736), (const char*)sub_4E3A80(*(_DWORD*)(a2 + 8))))
            {
                v2 = 0;
            }
        }
    }
    return v2;
}

//----- (005104F0) --------------------------------------------------------
int __cdecl sub_5104F0(int a1, __int16 a2)
{
    int v2; // eax
    char v4[4]; // [esp+0h] [ebp-4h]

    *(_WORD*)& v4[2] = a2;
    v2 = *(_DWORD*)(a1 + 748);
    v4[0] = -55;
    v4[1] = 27;
    return sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v4, 4, 0, 1);
}

//----- (00510540) --------------------------------------------------------
int __cdecl sub_510540(int a1)
{
    int v1; // eax
    int result; // eax

    if (!sub_40A5C0(4096))
        goto LABEL_12;
    if (!*(_DWORD*)& byte_5D4594[2386520])
    {
        *(_DWORD*)& byte_5D4594[2386520] = sub_4E3AA0((CHAR*)& byte_587000[236324]);
        *(_DWORD*)& byte_5D4594[2386528] = sub_4E3AA0((CHAR*)& byte_587000[236332]);
        *(_DWORD*)& byte_5D4594[2386524] = sub_4E3AA0((CHAR*)& byte_587000[236340]);
        *(_DWORD*)& byte_5D4594[2386532] = sub_4E3AA0((CHAR*)& byte_587000[236348]);
    }
    v1 = *(unsigned __int16*)(a1 + 4);
    if ((unsigned __int16)v1 == *(_DWORD*)& byte_5D4594[2386520]
        || v1 == *(_DWORD*)& byte_5D4594[2386524]
        || v1 == *(_DWORD*)& byte_5D4594[2386528]
        || v1 == *(_DWORD*)& byte_5D4594[2386532])
    {
        result = 0;
    }
    else
    {
    LABEL_12:
        result = 1;
    }
    return result;
}

//----- (005105D0) --------------------------------------------------------
BOOL __cdecl sub_5105D0(int a1)
{
    int v1; // eax

    if (!*(_DWORD*)& byte_5D4594[2386536])
    {
        *(_DWORD*)& byte_5D4594[2386536] = sub_4E3AA0((CHAR*)& byte_587000[236364]);
        *(_DWORD*)& byte_5D4594[2386544] = sub_4E3AA0((CHAR*)& byte_587000[236372]);
        *(_DWORD*)& byte_5D4594[2386540] = sub_4E3AA0((CHAR*)& byte_587000[236380]);
    }
    v1 = *(unsigned __int16*)(a1 + 4);
    return (unsigned __int16)v1 == *(_DWORD*)& byte_5D4594[2386536]
        || v1 == *(_DWORD*)& byte_5D4594[2386540]
        || v1 == *(_DWORD*)& byte_5D4594[2386544];
}

//----- (00510640) --------------------------------------------------------
float* __cdecl sub_510640(int a1, int a2, int a3, float* a4)
{
    int v4; // ebp
    float* result; // eax
    _DWORD* v6; // edi
    int v7; // esi
    unsigned int v8; // ebx
    int v9; // edi
    int v10; // eax
    int v11; // edi
    _DWORD* v12; // eax
    void(__cdecl * v13)(int, _DWORD*, int, int); // ecx
    wchar_t* v14; // eax
    int v15; // [esp+0h] [ebp-1Ch]
    float v16; // [esp+0h] [ebp-1Ch]
    float v17; // [esp+0h] [ebp-1Ch]
    unsigned int v18; // [esp+14h] [ebp-8h]
    unsigned int v19; // [esp+18h] [ebp-4h]
    int v20; // [esp+20h] [ebp+4h]

    v4 = a1;
    v15 = a1;
    v20 = *(_DWORD*)(a1 + 748);
    v19 = sub_4FA6B0(v15);
    if (!*(_DWORD*)& byte_5D4594[2386552])
        * (_DWORD*)& byte_5D4594[2386552] = sub_4E3AA0((CHAR*)& byte_587000[236388]);
    result = a4;
    v18 = 0;
    if (a4)
    {
        while (1)
        {
            v6 = (_DWORD*)a2;
            result = *(float**)(a2 + 20);
            if (!result)
                return result;
            while (*(unsigned __int16*)(*(_DWORD*)result + 4) != a3)
            {
                result = (float*) * ((_DWORD*)result + 2);
                if (!result)
                    return result;
            }
            v7 = *(_DWORD*)result;
            if (!*(_DWORD*)result)
                return result;
            v8 = sub_50E3D0(1, a2, *result);
            if (v8 > v19)
                return (float*)sub_5104F0(v4, v8 - v19);
            if (*(_BYTE*)(v7 + 8) & 0x10)
            {
                v9 = sub_4E7D30(v4, *(unsigned __int16*)(v7 + 4));
                if (v9 >= (sub_40A5C0(6144) ? 9 : 3))
                {
                    v14 = loadString_sub_40F1D0((char*)& byte_587000[236444], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3108);
                    return (float*)sub_4D9EB0(v4, v14);
                }
                v6 = (_DWORD*)a2;
            }
            if (*(unsigned __int16*)(v7 + 4) == *(_DWORD*)& byte_5D4594[2386552])
            {
                v16 = sub_419D40(&byte_587000[236468]);
                if (*(_DWORD*)(v20 + 320) >= sub_419A70(v16))
                    break;
            }
            if (sub_40A5C0(4096))
            {
                v10 = *(_DWORD*)(v7 + 8);
                if (v10 & 0x1000)
                {
                    if (*(_DWORD*)(v7 + 12) & 0x200000)
                    {
                        v17 = sub_419D40(&byte_587000[236520]);
                        v11 = sub_419A70(v17);
                        if (sub_4E7D30(v4, *(unsigned __int16*)(v7 + 4)) >= v11)
                        {
                            sub_4DA2C0(v4, "pickup.c:MaxSameItem", 0);
                            goto LABEL_36;
                        }
                        v6 = (_DWORD*)a2;
                    }
                }
            }
            if (sub_40A5C0(4096) && (sub_5105D0(v7) || *(unsigned __int16*)(v7 + 4) == *(_DWORD*)& byte_5D4594[2386552]))
                v12 = sub_4E3450(*(unsigned __int16*)(v7 + 4));
            else
                v12 = (_DWORD*)v7;
            v13 = (void(__cdecl*)(int, _DWORD*, int, int))v12[177];
            if (v13)
                v13(v4, v12, 1, 1);
            else
                sub_4F3070(v4, (int)v12, 1);
            sub_510320(v7, (int)v6);
            if (sub_510540(v7))
                sub_50E7A0(v6, v7);
            sub_4FA5D0(v4, v8);
            sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v20 + 276) + 2064), v4);
            result = (float*)++v18;
            if (v18 >= (unsigned int)a4)
                return result;
        }
        sub_4DA2C0(v4, "pickup.c:MaxTradableAnkhsReached", 0);
    LABEL_36:
        result = (float*)sub_501960(925, v4, 0, 0);
    }
    return result;
}

//----- (005108D0) --------------------------------------------------------
_DWORD* __cdecl sub_5108D0(int a1, int a2, int a3)
{
    int v3; // edi
    _DWORD* result; // eax
    int v5; // ebx
    int v6; // ecx
    int v7; // ecx
    unsigned __int8 v8; // dl
    _WORD* v9; // ecx
    __int16 v10; // dx
    char v11[8]; // [esp+Ch] [ebp-8h]

    v3 = 0;
    result = *(_DWORD * *)(a1 + 504);
    v5 = *(_DWORD*)(a1 + 748);
    v11[0] = -55;
    v11[1] = 31;
    *(_WORD*)& v11[2] = a3;
    if (result)
    {
        while (result[9] != a3)
        {
            result = (_DWORD*)result[124];
            if (!result)
                return result;
        }
        v6 = result[2];
        if (v6 & 0x1000)
        {
            if (result[3] & 0x47F0000)
            {
                v7 = result[184];
                v8 = *(_BYTE*)(v7 + 109);
                if (*(_BYTE*)(v7 + 108) < v8)
                {
                    if (v8)
                        v3 = 1;
                }
            }
        }
        v9 = (_WORD*)result[139];
        if (v9 && (v10 = v9[2], *v9 != v10) && v10 || v3)
        {
            *(_DWORD*)& v11[4] = sub_50E3D0(2, a2, *(float*)& result);
            result = (_DWORD*)sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), v11, 8, 0, 1);
        }
        else
        {
            result = sub_501960(925, a1, 0, 0);
        }
    }
    return result;
}

//----- (005109C0) --------------------------------------------------------
_DWORD* __cdecl sub_5109C0(int* a1, int a2, _DWORD* a3)
{
    int v3; // ebx
    int v4; // esi
    _DWORD* result; // eax
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    char v8[8]; // [esp+Ch] [ebp-8h]

    v3 = a1[187];
    if (!*(_DWORD*)& byte_5D4594[2386556])
        * (_DWORD*)& byte_5D4594[2386556] = sub_4E3AA0((CHAR*)& byte_587000[236568]);
    v4 = a1[126];
    result = a3;
    v8[0] = -55;
    v8[1] = 29;
    *(_WORD*)& v8[2] = (_WORD)a3;
    if (v4)
    {
        while (*(_DWORD * *)(v4 + 36) != a3)
        {
            v4 = *(_DWORD*)(v4 + 496);
            if (!v4)
                return result;
        }
        if (sub_53EBF0(v4) == 1)
        {
            v6 = loadString_sub_40F1D0((char*)& byte_587000[236616], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3298);
            sub_4D9EB0((int)a1, v6);
            result = sub_501960(925, (int)a1, 2, a1[9]);
        }
        else if (*(unsigned __int16*)(v4 + 4) == *(_DWORD*)& byte_5D4594[2386556])
        {
            v7 = loadString_sub_40F1D0((char*)& byte_587000[236676], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3308);
            sub_4D9EB0((int)a1, v7);
            result = sub_501960(925, (int)a1, 2, a1[9]);
        }
        else
        {
            *(_DWORD*)& v8[4] = sub_50E3D0(0, a2, *(float*)& v4);
            result = (_DWORD*)sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), v8, 8, 0, 1);
        }
    }
    return result;
}

//----- (00510AE0) --------------------------------------------------------
_DWORD* __cdecl sub_510AE0(int* a1, int a2, _DWORD* a3)
{
    _DWORD* result; // eax
    int v4; // esi
    int v5; // ebp
    unsigned int v6; // eax
    int v7; // eax
    int v8; // ebx

    result = (_DWORD*)sub_4FA6B0((int)a1);
    v4 = a1[126];
    v5 = a1[187];
    if (v4)
    {
        result = a3;
        while (*(_DWORD * *)(v4 + 36) != a3)
        {
            v4 = *(_DWORD*)(v4 + 496);
            if (!v4)
                return result;
        }
        v6 = sub_50E3D0(2, a2, *(float*)& v4);
        sub_4FA5D0((int)a1, v6);
        sub_4E4560(v4, *(_WORD*)(*(_DWORD*)(v4 + 556) + 4));
        sub_4D87A0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (_DWORD*)v4);
        v7 = *(_DWORD*)(v4 + 8);
        if (v7 & 0x1000 && *(_DWORD*)(v4 + 12) & 0x47F0000)
        {
            v8 = *(_DWORD*)(v4 + 736);
            if (sub_53C520(v4, 100))
                sub_4D82B0(
                    *(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064),
                    (_DWORD*)v4,
                    *(_BYTE*)(v8 + 108),
                    *(_BYTE*)(v8 + 109));
        }
        sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)a1);
        result = sub_501960(803, (int)a1, 2, a1[9]);
    }
    return result;
}

//----- (00510BE0) --------------------------------------------------------
_DWORD* __cdecl sub_510BE0(int* a1, int a2, _DWORD* a3)
{
    _DWORD* result; // eax
    int v4; // ebx
    int v5; // esi
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    int v8; // eax

    sub_4FA6B0((int)a1);
    result = *(_DWORD * *)& byte_5D4594[2386560];
    v4 = a1[187];
    if (!*(_DWORD*)& byte_5D4594[2386560])
    {
        result = (_DWORD*)sub_4E3AA0((CHAR*)& byte_587000[236692]);
        *(_DWORD*)& byte_5D4594[2386560] = result;
    }
    v5 = a1[126];
    if (v5)
    {
        result = a3;
        while (*(_DWORD * *)(v5 + 36) != a3)
        {
            v5 = *(_DWORD*)(v5 + 496);
            if (!v5)
                return result;
        }
        if (sub_53EBF0(v5) == 1)
        {
            v6 = loadString_sub_40F1D0((char*)& byte_587000[236740], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3413);
            sub_4D9EB0((int)a1, v6);
            result = sub_501960(925, (int)a1, 2, a1[9]);
        }
        else if (*(unsigned __int16*)(v5 + 4) == *(_DWORD*)& byte_5D4594[2386560])
        {
            v7 = loadString_sub_40F1D0((char*)& byte_587000[236800], 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3423);
            sub_4D9EB0((int)a1, v7);
            result = sub_501960(925, (int)a1, 2, a1[9]);
        }
        else
        {
            sub_4ED0C0((int)a1, (int*)v5);
            sub_4E5CC0(v5);
            v8 = sub_50E3D0(0, a2, *(float*)& v5);
            sub_4FA590((int)a1, v8);
            sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)a1);
            result = sub_501960(307, (int)a1, 2, a1[9]);
        }
    }
    return result;
}

//----- (00510D10) --------------------------------------------------------
unsigned __int16 __cdecl sub_510D10(int* a1, int a2, int a3, unsigned int a4)
{
    unsigned __int16 result; // ax
    int v5; // ebp
    int v6; // ebx
    int v7; // esi
    int v8; // eax

    sub_4FA6B0((int)a1);
    result = a4;
    v5 = a1[187];
    v6 = 0;
    if (a4)
    {
        while (1)
        {
            v7 = a1[126];
            if (!v7)
                break;
            while (1)
            {
                result = *(_WORD*)(v7 + 4);
                if (result == a3)
                    break;
                v7 = *(_DWORD*)(v7 + 496);
                if (!v7)
                    return result;
            }
            sub_4ED0C0((int)a1, (int*)v7);
            sub_4E5CC0(v7);
            v8 = sub_50E3D0(0, a2, *(float*)& v7);
            sub_4FA590((int)a1, v8);
            sub_4D8870(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)a1);
            result = a4;
            if (++v6 >= a4)
                return (unsigned int)sub_501960(307, (int)a1, 2, a1[9]);
        }
    }
    return result;
}

//----- (00510DC0) --------------------------------------------------------
void __cdecl sub_510DC0(_DWORD* a1)
{
    if (a1[4])
        sub_50F4C0(a1);
    else
        sub_50F3A0(a1);
}

//----- (00510DE0) --------------------------------------------------------
int __cdecl sub_510DE0(int a1, int a2)
{
    int v2; // eax
    _DWORD* v3; // eax

    v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 280);
    if (!v2)
        return 0;
    v3 = *(_DWORD * *)(v2 + 20);
    if (!v3)
        return 0;
    while (*(_DWORD*)(*v3 + 36) != a2)
    {
        v3 = (_DWORD*)v3[2];
        if (!v3)
            return 0;
    }
    return *v3;
}

//----- (00510E20) --------------------------------------------------------
void __cdecl sub_510E20(int a1)
{
    if (*(_DWORD*)& byte_5D4594[4 * a1 + 2386364])
        sub_510000(*(_DWORD*)& byte_5D4594[4 * a1 + 2386364]);
    *(_DWORD*)& byte_5D4594[4 * a1 + 2386364] = 0;
}

//----- (00510E50) --------------------------------------------------------
void sub_510E50()
{
    *(_DWORD*)& byte_5D4594[2386564] = 0;
}

//----- (00510E60) --------------------------------------------------------
signed int __cdecl sub_510E60(int a1)
{
    signed int result; // eax
    int v2; // edi
    float v3; // eax
    float v4; // ecx
    float v5; // eax
    float v6; // ecx
    float2 a2; // [esp+8h] [ebp-30h]
    int v8[2]; // [esp+10h] [ebp-28h]
    float4 a1a; // [esp+18h] [ebp-20h]
    float4 v10; // [esp+28h] [ebp-10h]

    result = *(_DWORD*)(a1 + 16);
    v2 = *(_DWORD*)(a1 + 748);
    if (result >= 0)
    {
        *(_DWORD*)(a1 + 500) = 0;
        *(_DWORD*)(a1 + 496) = *(_DWORD*)& byte_5D4594[2386564];
        if (*(_DWORD*)& byte_5D4594[2386564])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[2386564] + 500) = a1;
        *(_DWORD*)& byte_5D4594[2386564] = a1;
        result = *(_DWORD*)(a1 + 16) | 0x80000000;
        *(_DWORD*)(a1 + 16) = result;
    }
    if (*(_BYTE*)(a1 + 16) & 0x20)
        result = (signed int)sub_510FD0((_DWORD*)a1);
    if (*(_DWORD*)(a1 + 16) & 0x1000000)
    {
        v3 = *(float*)(a1 + 60);
        a1a.field_0 = *(float*)(a1 + 56);
        a1a.field_4 = v3;
        a1a.field_8 = cos(*(float*)v2) * 600.0 + *(float*)(a1 + 56);
        a1a.field_C = sin(*(float*)v2) * 600.0 + *(float*)(a1 + 60);
        if (sub_535250(&a1a, &a2, 0, 5))
        {
            v4 = a1a.field_C;
            *(float*)(a1 + 156) = a1a.field_8;
            *(float*)(a1 + 160) = v4;
        }
        else
        {
            v5 = a2.field_0;
            v6 = a2.field_4;
            *(float*)(a1 + 156) = a2.field_0;
            *(float*)(a1 + 160) = v6;
            a1a.field_8 = v5;
            a1a.field_C = v6;
        }
        *(float*)v2 = *(float*)(v2 + 8) + *(float*)v2;
        if (a1a.field_0 >= (double)a1a.field_8)
        {
            v10.field_8 = a1a.field_0;
            v10.field_0 = a1a.field_8;
        }
        else
        {
            v10.field_0 = a1a.field_0;
            v10.field_8 = a1a.field_8;
        }
        if (a1a.field_4 >= (double)a1a.field_C)
        {
            v10.field_C = a1a.field_4;
            v10.field_4 = a1a.field_C;
        }
        else
        {
            v10.field_4 = a1a.field_4;
            v10.field_C = a1a.field_C;
        }
        v8[0] = a1;
        v8[1] = (int)& a1a;
        sub_517C10(&v10, sub_511020, (int)v8);
    }
    else
    {
        *(_DWORD*)v2 = *(_DWORD*)(v2 + 4);
    }
    return result;
}

//----- (00510FD0) --------------------------------------------------------
_DWORD* __cdecl sub_510FD0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    if (a1[4] < 0)
    {
        v2 = a1[125];
        if (v2)
            * (_DWORD*)(v2 + 496) = a1[124];
        else
            *(_DWORD*)& byte_5D4594[2386564] = a1[124];
        v3 = a1[124];
        if (v3)
            * (_DWORD*)(v3 + 500) = a1[125];
    }
    a1[4] &= 0x7FFFFFFFu;
    return result;
}

//----- (00511020) --------------------------------------------------------
void __cdecl sub_511020(int a1, int a2)
{
    int v2; // eax
    double v3;
    int v6; // eax
    int v7; // [esp-Ch] [ebp-20h]
    float2 a3; // [esp+Ch] [ebp-8h]

    v2 = *(_DWORD*)(a1 + 16);
    if (!(v2 & 0x41)
        && (!(v2 & 0x10) || sub_40A5C0(4096) && *(_BYTE*)(a1 + 8) & 2 && (*(_DWORD*)(a1 + 16) & 0x8000) != 0x8000)
        && *(_DWORD*)(a1 + 556)
        && sub_57C8A0(*(float4 * *)(a2 + 4), (float2*)(a1 + 56), &a3))
    {
        v3 = *(float*)(a1 + 60) - a3.field_4;
        if (*(float*)(a1 + 176) * *(float*)(a1 + 176) > v3 * v3
            + (*(float*)(a1 + 56) - a3.field_0)
            * (*(float*)(a1 + 56) - a3.field_0))
        {
            v7 = *(_DWORD*)a2;
            v6 = sub_4EC580(*(_DWORD*)a2);
            (*(void(__cdecl * *)(int, int, int, int, int))(a1 + 716))(a1, v6, v7, 500, 16);
            sub_501960(298, a1, 0, 0);
        }
    }
}

//----- (00511100) --------------------------------------------------------
void __cdecl sub_511100(int a1)
{
    int v1; // edi
    char* v2; // eax
    int v3; // esi
    double v4; // st7
    double v5; // st7
    float v6; // [esp+8h] [ebp-20h]
    float v7; // [esp+Ch] [ebp-1Ch]
    float v8; // [esp+14h] [ebp-14h]
    float v9; // [esp+18h] [ebp-10h]
    float v10; // [esp+1Ch] [ebp-Ch]
    float v11; // [esp+20h] [ebp-8h]
    float i; // [esp+24h] [ebp-4h]
    float v13; // [esp+2Ch] [ebp+4h]

    v1 = a1;
    v2 = sub_417090(a1);
    v3 = *(_DWORD*)& byte_5D4594[2386564];
    v4 = (double) * ((unsigned __int16*)v2 + 5);
    v9 = *((float*)v2 + 908) - v4;
    v13 = (double) * ((unsigned __int16*)v2 + 6);
    v10 = *((float*)v2 + 909) - v13;
    v11 = v4 + *((float*)v2 + 908);
    for (i = v13 + *((float*)v2 + 909); v3; v3 = *(_DWORD*)(v3 + 496))
    {
        if (*(_DWORD*)(v3 + 16) & 0x1000000)
        {
            if (*(float*)(v3 + 56) >= (double) * (float*)(v3 + 156))
            {
                v5 = *(float*)(v3 + 56);
                v6 = *(float*)(v3 + 156);
            }
            else
            {
                v5 = *(float*)(v3 + 156);
                v6 = *(float*)(v3 + 56);
            }
            if (*(float*)(v3 + 60) >= (double) * (float*)(v3 + 160))
            {
                v8 = *(float*)(v3 + 60);
                v7 = *(float*)(v3 + 160);
            }
            else
            {
                v7 = *(float*)(v3 + 60);
                v8 = *(float*)(v3 + 160);
            }
            if (v9 < v5 && v11 >(double)v6 && v10 < (double)v8 && i >(double)v7)
                sub_511250(v1, (float*)v3);
        }
        else
        {
            **(_DWORD * *)(v3 + 748) = *(_DWORD*)(*(_DWORD*)(v3 + 748) + 4);
        }
    }
}

//----- (00511250) --------------------------------------------------------
int __cdecl sub_511250(int a1, float* a2)
{
    __int16 v2; // ax
    float v3; // ecx
    __int16 v4; // ax
    float v5; // edx
    char v7[9]; // [esp+4h] [ebp-Ch]

    v7[0] = -107;
    v2 = sub_419A30(a2[14]);
    v3 = a2[15];
    *(_WORD*)& v7[1] = v2;
    v4 = sub_419A30(v3);
    v5 = a2[39];
    *(_WORD*)& v7[3] = v4;
    *(_WORD*)& v7[5] = sub_419A30(v5);
    *(_WORD*)& v7[7] = sub_419A30(a2[40]);
    return sub_40EBC0(a1, 1, v7, 9);
}

//----- (005112C0) --------------------------------------------------------
BOOL sub_5112C0()
{
    *(_DWORD*)& byte_5D4594[2386568] = nox_new_alloc_class("Springs", 52, 256);
    return *(_DWORD*)& byte_5D4594[2386568] != 0;
}

//----- (005112F0) --------------------------------------------------------
void sub_5112F0()
{
    *(_DWORD*)& byte_5D4594[2386572] = 0;
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386568]);
}

//----- (00511310) --------------------------------------------------------
int sub_511310()
{
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386568]);
    *(_DWORD*)& byte_5D4594[2386572] = 0;
    return 1;
}

//----- (00511330) --------------------------------------------------------
void __cdecl sub_511330(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)& byte_5D4594[2386572];
    if (*(_DWORD*)& byte_5D4594[2386572])
    {
        while (*(_DWORD*)(v1 + 8) != a1)
        {
            v1 = *(_DWORD*)(v1 + 44);
            if (!v1)
                return;
        }
        if (v1)
            sub_511360(v1);
    }
}

//----- (00511360) --------------------------------------------------------
void __cdecl sub_511360(int a1)
{
    int v1; // ecx
    int v2; // ecx

    v1 = *(_DWORD*)(a1 + 48);
    if (v1)
        * (_DWORD*)(v1 + 44) = *(_DWORD*)(a1 + 44);
    else
        *(_DWORD*)& byte_5D4594[2386572] = *(_DWORD*)(a1 + 44);
    v2 = *(_DWORD*)(a1 + 44);
    if (v2)
        * (_DWORD*)(v2 + 48) = *(_DWORD*)(a1 + 48);
    sub_414330(*(unsigned int**)& byte_5D4594[2386568], (_QWORD*)a1);
}

//----- (005113A0) --------------------------------------------------------
void sub_5113A0()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    int v3; // ecx
    int v4; // eax
    int v5; // ecx
    double v6; // st7
    long double v7; // st7
    double v8; // st7
    double v9; // st7
    float v10; // [esp+0h] [ebp-1Ch]
    float v11; // [esp+4h] [ebp-18h]
    float v12; // [esp+14h] [ebp-8h]
    float v13; // [esp+14h] [ebp-8h]
    float v14; // [esp+18h] [ebp-4h]
    float v15; // [esp+18h] [ebp-4h]

    v0 = *(_DWORD*)& byte_5D4594[2386572];
    if (*(_DWORD*)& byte_5D4594[2386572])
    {
        do
        {
            v1 = *(_DWORD*)(v0 + 8);
            v2 = *(_DWORD*)(v0 + 44);
            if (!v1)
                goto LABEL_16;
            v3 = *(_DWORD*)(v0 + 12);
            if (!v3)
                goto LABEL_16;
            if (!(*(_BYTE*)(v1 + 16) & 0x20)
                && !(*(_BYTE*)(v3 + 16) & 0x20)
                && (v4 = *(_DWORD*)(v0 + 12),
                    v5 = *(_DWORD*)(v0 + 8),
                    v12 = *(float*)(v4 + 64) - *(float*)(v5 + 64),
                    v6 = *(float*)(v4 + 68) - *(float*)(v5 + 68),
                    v14 = v6,
                    v7 = sqrt(v6 * v14 + v12 * v12),
                    *(float*)(v0 + 32) = v7,
                    v7 <= *(float*)(v0 + 28)))
            {
                v8 = *(float*)(v0 + 32) - *(float*)(v0 + 24);
                if (!(*(_BYTE*)(v0 + 40) & 1) || v8 >= 0.0)
                {
                    if (v8 > * (float*)(v0 + 24))
                        v8 = *(float*)(v0 + 24);
                    v9 = -(v8 * *(float*)(v0 + 16));
                    v15 = v9 * (v14 / *(float*)(v0 + 32));
                    v13 = v9 * (v12 / *(float*)(v0 + 32));
                    v11 = -v15;
                    v10 = -v13;
                    sub_548600(*(_DWORD*)(v0 + 8), v10, v11);
                    sub_537610(*(_DWORD*)(v0 + 8));
                    sub_548600(*(_DWORD*)(v0 + 12), v13, v15);
                    sub_537610(*(_DWORD*)(v0 + 12));
                    *(_DWORD*)(v0 + 36) = *(_DWORD*)(v0 + 32);
                }
            }
            else
            {
            LABEL_16:
                sub_511360(v0);
            }
            v0 = v2;
        } while (v2);
    }
}

//----- (005114D0) --------------------------------------------------------
void __cdecl sub_5114D0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    float* v6; // eax
    double v7; // st7
    double v8; // st6
    long double v9; // st7

    if (a1 && a2 && !(*(_BYTE*)(a1 + 16) & 0x20) && !(*(_BYTE*)(a2 + 16) & 0x20))
    {
        v6 = (float*)nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386568]);
        if (v6)
        {
            *((_DWORD*)v6 + 4) = a3;
            *((_DWORD*)v6 + 5) = a4;
            *((_DWORD*)v6 + 2) = a1;
            *((_DWORD*)v6 + 3) = a2;
            *((_DWORD*)v6 + 6) = a5;
            *((_DWORD*)v6 + 7) = a6;
            v7 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
            v8 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
            v9 = sqrt(v8 * v8 + v7 * v7);
            v6[8] = v9;
            v6[9] = v9;
            sub_511560((int)v6);
        }
    }
}

//----- (00511560) --------------------------------------------------------
int __cdecl sub_511560(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 48) = 0;
    *(_DWORD*)(a1 + 44) = *(_DWORD*)& byte_5D4594[2386572];
    if (*(_DWORD*)& byte_5D4594[2386572])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[2386572] + 48) = a1;
    *(_DWORD*)& byte_5D4594[2386572] = a1;
    return result;
}

//----- (00511590) --------------------------------------------------------
void __cdecl sub_511590(int a1, int a2)
{
    int v2; // ebx
    _DWORD* v3; // eax
    int v4; // esi
    double v5; // st7
    double v6; // st6
    char v7; // dl
    long double v8; // st7
    float v9; // [esp+10h] [ebp+4h]

    v2 = a1;
    if (a1)
    {
        if (a2)
        {
            if (!(*(_BYTE*)(a1 + 16) & 0x20) && !(*(_BYTE*)(a2 + 16) & 0x20))
            {
                v3 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386568]);
                v4 = (int)v3;
                if (v3)
                {
                    v3[2] = a1;
                    v3[3] = a2;
                    v3[4] = 1114636288;
                    v9 = sub_4E4A70(a1);
                    if (sub_4E4A70(a2) >= v9)
                        sub_4E4A70(a2);
                    else
                        sub_4E4A70(v2);
                    *(_DWORD*)(v4 + 20) = 0;
                    v5 = *(float*)(a2 + 56) - *(float*)(v2 + 56);
                    v6 = *(float*)(a2 + 60) - *(float*)(v2 + 60);
                    v7 = *(_BYTE*)(v4 + 40) | 1;
                    *(_DWORD*)(v4 + 28) = 1132462080;
                    *(_BYTE*)(v4 + 40) = v7;
                    v8 = sqrt(v6 * v6 + v5 * v5);
                    *(float*)(v4 + 32) = v8;
                    *(float*)(v4 + 36) = v8;
                    *(float*)(v4 + 24) = v8;
                    sub_511560(v4);
                }
            }
        }
    }
}

//----- (00511660) --------------------------------------------------------
int __cdecl sub_511660(_DWORD* a1, int a2)
{
    int result; // eax
    unsigned int v3; // edx
    int v4; // ecx
    int v5; // eax
    int v6; // eax

    result = a1[4];
    if (!(result & 0x10000))
    {
        if (result & 0x400000)
            sub_5116F0((int)a1);
        v3 = *(_DWORD*)& byte_5D4594[2598000] + a2;
        v4 = 0;
        a1[34] = *(_DWORD*)& byte_5D4594[2598000] + a2;
        v5 = *(_DWORD*)& byte_5D4594[2386576];
        if (!*(_DWORD*)& byte_5D4594[2386576])
            goto LABEL_14;
        do
        {
            if (v3 < *(int*)(v5 + 136))
                break;
            v4 = v5;
            v5 = *(_DWORD*)(v5 + 468);
        } while (v5);
        if (v4)
        {
            *(_DWORD*)(v4 + 468) = a1;
            if (!v5)
            {
                v6 = a1[4];
                a1[117] = 0;
                result = v6 | 0x400000;
                a1[4] = result;
                return result;
            }
        }
        else
        {
        LABEL_14:
            *(_DWORD*)& byte_5D4594[2386576] = a1;
        }
        a1[117] = v5;
        result = a1[4] | 0x400000;
        a1[4] = result;
    }
    return result;
}

//----- (005116F0) --------------------------------------------------------
int __cdecl sub_5116F0(int a1)
{
    int result; // eax
    int v2; // ecx

    result = *(_DWORD*)(a1 + 16);
    if (result & 0x400000)
    {
        v2 = 0;
        *(_DWORD*)(a1 + 16) = result & 0xFFBFFFFF;
        result = *(_DWORD*)& byte_5D4594[2386576];
        if (*(_DWORD*)& byte_5D4594[2386576])
        {
            while (result != a1)
            {
                v2 = result;
                result = *(_DWORD*)(result + 468);
                if (!result)
                    return result;
            }
            if (result)
            {
                if (v2)
                {
                    result = *(_DWORD*)(a1 + 468);
                    *(_DWORD*)(v2 + 468) = result;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[2386576] = *(_DWORD*)(a1 + 468);
                }
            }
        }
    }
    return result;
}

//----- (00511750) --------------------------------------------------------
void sub_511750()
{
    _DWORD* v0; // esi
    _DWORD* v1; // edi
    int v2; // edx

    v0 = *(_DWORD * *)& byte_5D4594[2386576];
    if (*(_DWORD*)& byte_5D4594[2386576])
    {
        do
        {
            v1 = (_DWORD*)v0[117];
            if (v0[123])
            {
                sub_5116F0((int)v0);
            }
            else
            {
                if (v0[34] > * (int*)& byte_5D4594[2598000])
                    return;
                sub_5116F0((int)v0);
                v2 = v0[5];
                LOBYTE(v2) = v2 | 0x80;
                v0[5] = v2;
                sub_4E5CC0((int)v0);
            }
            v0 = v1;
        } while (v1);
    }
}

//----- (005117B0) --------------------------------------------------------
int sub_5117B0()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[2386576];
    if (*(_DWORD*)& byte_5D4594[2386576])
    {
        do
        {
            v1 = *(_DWORD*)(result + 468);
            sub_5116F0(result);
            result = v1;
        } while (v1);
        *(_DWORD*)& byte_5D4594[2386576] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[2386576] = 0;
    }
    return result;
}

//----- (005117F0) --------------------------------------------------------
char __cdecl sub_5117F0(int a1)
{
    char result; // al

    result = a1;
    if (!(*(_BYTE*)(a1 + 8) & 1))
        result = sub_537610(a1);
    return result;
}

//----- (00511810) --------------------------------------------------------
void __cdecl sub_511810(int a1)
{
    if (!(*(_BYTE*)(a1 + 8) & 1))
    {
        if (sub_537580(a1))
            sub_5375A0(a1);
    }
}

//----- (00511850) --------------------------------------------------------
void sub_511850()
{
    int v0; // esi
    int v1; // eax

    sub_5486D0();
    v0 = 5;
    do
    {
        sub_5118A0(0.2);
        sub_548B60();
        --v0;
    } while (v0);
    while (!sub_537590())
    {
        v1 = sub_537700();
        if ((signed char) * (_BYTE*)(v1 + 8) >= 0)
            sub_4DA8D0(v1);
    }
    sub_548740();
}

//----- (005118A0) --------------------------------------------------------
int __cdecl sub_5118A0(float a1)
{
    int i; // esi
    int result; // eax
    int j; // esi
    double v4; // st7
    float v5; // ecx
    float* v6; // edi
    unsigned __int8* v7; // edx
    char v8; // al
    int v9; // eax
    double v10; // st7
    double v11; // st6
    float v12; // [esp+8h] [ebp-24h]
    float v13; // [esp+10h] [ebp-1Ch]
    float v14; // [esp+10h] [ebp-1Ch]
    float2 v15; // [esp+14h] [ebp-18h]
    float4 v16; // [esp+1Ch] [ebp-10h]

    if (!*(_DWORD*)& byte_5D4594[2386580])
    {
        *(_DWORD*)& byte_5D4594[2386580] = sub_4E3AA0((CHAR*)& byte_587000[236824]);
        *(_DWORD*)& byte_5D4594[2386584] = sub_4E3AA0((CHAR*)& byte_587000[236844]);
        *(_DWORD*)& byte_5D4594[2386588] = sub_4E3AA0((CHAR*)& byte_587000[236864]);
        *(_DWORD*)& byte_5D4594[2386592] = sub_4E3AA0((CHAR*)& byte_587000[236884]);
        *(_DWORD*)& byte_5D4594[2386596] = sub_4E3AA0((CHAR*)& byte_587000[236900]);
        *(_DWORD*)& byte_5D4594[2386600] = sub_4E3AA0((CHAR*)& byte_587000[236920]);
        *(_DWORD*)& byte_5D4594[2386604] = sub_4E3AA0((CHAR*)& byte_587000[236944]);
        *(_DWORD*)& byte_5D4594[2386608] = sub_4E3AA0((CHAR*)& byte_587000[236968]);
        *(_DWORD*)& byte_5D4594[2386612] = sub_4E3AA0((CHAR*)& byte_587000[236992]);
        *(_DWORD*)& byte_5D4594[2386616] = sub_4E3AA0((CHAR*)& byte_587000[237012]);
    }
    for (i = sub_537740(); i; i = sub_537750(i))
        sub_5481C0(i);
    sub_5113A0();
    result = sub_537740();
    for (j = result; result; j = result)
    {
        if (*(_BYTE*)(j + 16) & 2 || *(_BYTE*)(j + 8) & 2 && sub_50A0D0(j, 67))
        {
            *(_DWORD*)(j + 100) = 0;
            *(_DWORD*)(j + 96) = 0;
            *(_DWORD*)(j + 84) = 0;
            *(_DWORD*)(j + 80) = 0;
        }
        else
        {
            if (sub_4FF350(j, 5) || sub_4FF350(j, 25) || sub_4FF350(j, 28))
            {
                v4 = *(float*)(j + 96);
                v13 = *(float*)(j + 100);
            }
            else
            {
                v4 = *(float*)(j + 96) + *(float*)(j + 88);
                v13 = *(float*)(j + 100) + *(float*)(j + 92);
            }
            v5 = *(float*)(j + 64);
            v6 = (float*)(j + 64);
            v14 = v13 - *(float*)(j + 84) * *(float*)(j + 112);
            *(float*)(j + 80) = (v4 - *(float*)(j + 112) * *(float*)(j + 80)) * a1 + *(float*)(j + 80);
            *(float*)(j + 84) = v14 * a1 + *(float*)(j + 84);
            v16.field_0 = v5;
            v16.field_4 = *(float*)(j + 68);
            v7 = &byte_5D4594[2386580];
            v16.field_8 = a1 * *(float*)(j + 80) + *(float*)(j + 64);
            v16.field_C = a1 * *(float*)(j + 84) + *(float*)(j + 68);
            v8 = (*(_DWORD*)(j + 16) >> 12) & 4 | 1;
            while (*(unsigned __int16*)(j + 4) != *(_DWORD*)v7)
            {
                v7 += 4;
                if ((int)v7 >= (int)& byte_5D4594[2386620])
                    goto LABEL_20;
            }
            v8 = (*(_DWORD*)(j + 16) >> 12) & 4 | 0x41;
        LABEL_20:
            if (sub_535250(&v16, 0, 0, v8))
            {
                *v6 = v16.field_8;
                *(float*)(j + 68) = v16.field_C;
            }
            v9 = *(_DWORD*)(j + 16);
            if (!(v9 & 0x4000) && *(_DWORD*)(j + 556) && sub_411160((float2*)(j + 64)) == 6)
            {
                v15.field_0 = 0.0;
                v15.field_4 = 0.0;
                sub_548630(j, 6u, &v15);
            }
            v10 = *v6 - *(float*)(j + 56);
            if (v10 < 0.0)
                v10 = -v10;
            v11 = *(float*)(j + 68) - *(float*)(j + 60);
            if (v11 < 0.0)
                v11 = -v11;
            if (v10 > 0.0099999998 || (v12 = v11, v12 > 0.0099999998))
            {
                sub_4E44F0(j);
                sub_4E7290(j);
                sub_517970(j);
            }
        }
        result = sub_537750(j);
    }
    return result;
}

//----- (00511B60) --------------------------------------------------------
int __cdecl sub_511B60(int a1)
{
    int result; // eax
    int v2; // edi
    int v3; // esi

    if (a1 == -1)
    {
        result = *(_DWORD*)& byte_5D4594[3821964];
        if (*(_DWORD*)& byte_5D4594[3821964] && !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[3821964] + 16) & 0x20))
            return result;
        return 0;
    }
    if (a1 != -2)
    {
        result = sub_511C50(a1);
        if (result)
            return result;
        v2 = sub_4DA790();
        if (v2)
        {
            while (1)
            {
                if (!(*(_BYTE*)(v2 + 16) & 0x20) && *(_DWORD*)(v2 + 44) == a1)
                {
                    sub_511D70(v2);
                    return v2;
                }
                v3 = *(_DWORD*)(v2 + 504);
                if (v3)
                    break;
            LABEL_17:
                v2 = sub_4DA7A0(v2);
                if (!v2)
                    goto LABEL_18;
            }
            while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 44) != a1)
            {
                v3 = *(_DWORD*)(v3 + 496);
                if (!v3)
                    goto LABEL_17;
            }
        }
        else
        {
        LABEL_18:
            v3 = sub_4DA870();
            if (!v3)
                return 0;
            while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 44) != a1)
            {
                result = sub_4DA880(v3);
                v3 = result;
                if (!result)
                    return result;
            }
        }
        sub_511D70(v3);
        return v3;
    }
    result = *(_DWORD*)& byte_5D4594[3821968];
    if (!*(_DWORD*)& byte_5D4594[3821968] || *(_BYTE*)(*(_DWORD*)& byte_5D4594[3821968] + 16) & 0x20)
        return 0;
    return result;
}

//----- (00511C50) --------------------------------------------------------
int __cdecl sub_511C50(int a1)
{
    _DWORD* v1; // esi

    if (*(_DWORD*)& byte_587000[237036])
        sub_511D20();
    v1 = *(_DWORD * *)& byte_5D4594[2386820];
    if (!*(_DWORD*)& byte_5D4594[2386820])
        return 0;
    while (*(_BYTE*)(*v1 + 16) & 0x20 || *(_DWORD*)(*v1 + 44) != a1)
    {
        v1 = (_DWORD*)v1[2];
        if (!v1)
            return 0;
    }
    sub_511CE0(&byte_5D4594[2386820], (int)v1);
    sub_511CB0(&byte_5D4594[2386820], (int)v1);
    return *v1;
}

//----- (00511CB0) --------------------------------------------------------
int __cdecl sub_511CB0(_DWORD* a1, int a2)
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

//----- (00511CE0) --------------------------------------------------------
int __cdecl sub_511CE0(_DWORD* a1, int a2)
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

//----- (00511D20) --------------------------------------------------------
int sub_511D20()
{
    unsigned __int8* v0; // esi
    int result; // eax

    v0 = &byte_5D4594[2386628];
    *(_DWORD*)& byte_5D4594[2386820] = 0;
    *(_DWORD*)& byte_5D4594[2386824] = 0;
    *(_DWORD*)& byte_5D4594[2386620] = 0;
    *(_DWORD*)& byte_5D4594[2386624] = 0;
    do
    {
        result = sub_511CB0(&byte_5D4594[2386620], (int)v0);
        v0 += 12;
    } while ((int)v0 < (int)& byte_5D4594[2386820]);
    *(_DWORD*)& byte_587000[237036] = 0;
    return result;
}

//----- (00511D70) --------------------------------------------------------
int __cdecl sub_511D70(int a1)
{
    int* v1; // eax
    int v2; // esi
    int result; // eax
    int v4; // [esp-8h] [ebp-8h]

    v1 = (int*)sub_511DC0();
    if (v1)
    {
        *v1 = a1;
        result = sub_511CB0(&byte_5D4594[2386820], (int)v1);
    }
    else
    {
        v2 = *(_DWORD*)& byte_5D4594[2386824];
        v4 = *(_DWORD*)& byte_5D4594[2386824];
        **(_DWORD * *)& byte_5D4594[2386824] = a1;
        sub_511CE0(&byte_5D4594[2386820], v4);
        result = sub_511CB0(&byte_5D4594[2386820], v2);
    }
    return result;
}

//----- (00511DC0) --------------------------------------------------------
int sub_511DC0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[2386620];
    if (!*(_DWORD*)& byte_5D4594[2386620])
        return 0;
    *(_DWORD*)& byte_5D4594[2386620] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2386620] + 8);
    return result;
}

//----- (00511DE0) --------------------------------------------------------
int __cdecl sub_511DE0(int a1)
{
    int result; // eax
    _DWORD* v2; // esi

    result = *(_DWORD*)& byte_587000[237036];
    if (!*(_DWORD*)& byte_587000[237036])
    {
        v2 = *(_DWORD * *)& byte_5D4594[2386820];
        if (*(_DWORD*)& byte_5D4594[2386820])
        {
            result = a1;
            while (*v2 != a1)
            {
                v2 = (_DWORD*)v2[2];
                if (!v2)
                    return result;
            }
            sub_511CE0(&byte_5D4594[2386820], (int)v2);
            result = sub_511CB0(&byte_5D4594[2386620], (int)v2);
        }
    }
    return result;
}

//----- (00511E20) --------------------------------------------------------
int sub_511E20()
{
    int result; // eax
    int v1; // esi
    int v2; // edi

    result = *(_DWORD*)& byte_587000[237036];
    if (!*(_DWORD*)& byte_587000[237036])
    {
        v1 = *(_DWORD*)& byte_5D4594[2386820];
        if (*(_DWORD*)& byte_5D4594[2386820])
        {
            do
            {
                v2 = *(_DWORD*)(v1 + 8);
                sub_511CE0(&byte_5D4594[2386820], v1);
                result = sub_511CB0(&byte_5D4594[2386620], v1);
                v1 = v2;
            } while (v2);
        }
    }
    return result;
}

//----- (00511E60) --------------------------------------------------------
void sub_511E60()
{
    if (!*(_DWORD*)& byte_5D4594[2386836])
        * (_DWORD*)& byte_5D4594[2386836] = sub_4E3AA0((CHAR*)& byte_587000[246804]);
    sub_5058F0();
    sub_51AC60();
    *(_DWORD*)& byte_5D4594[2386844] = 0;
    *(_DWORD*)& byte_5D4594[2386848] = 0;
    *(_DWORD*)& byte_5D4594[2386852] = 0;
}

//----- (00511EB0) --------------------------------------------------------
int sub_511EB0()
{
    int v0; // edi
    int v1; // esi

    v0 = script_pop();
    v1 = script_pop();
    if (*(_DWORD*)& byte_5D4594[3821636] || *(_DWORD*)& byte_5D4594[3821640])
    {
        v1 = (*(int*)& byte_5D4594[3821636] + 23 * v1) / 23;
        v0 = (*(int*)& byte_5D4594[3821640] + 23 * v0) / 23;
    }
    if (sub_410580(v1, v0))
        sub_507230(v0 | (v1 << 16));
    else
        sub_507230(0);
    return 0;
}

//----- (00511F50) --------------------------------------------------------
int sub_511F50()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_410580(v0 >> 16, (unsigned __int16)v0);
    if (v1)
        sub_511F80(v1);
    return 0;
}

//----- (00511F80) --------------------------------------------------------
void __cdecl sub_511F80(int a1)
{
    int v1; // edx
    int v2; // ecx
    char v3; // al
    int v4; // eax
    char* v5; // eax
    int v6; // eax
    float2 v7; // [esp+0h] [ebp-8h]
    int v8; // [esp+Ch] [ebp+4h]

    v1 = a1;
    if (*(_BYTE*)(a1 + 4) & 4)
    {
        v2 = *(_DWORD*)(a1 + 28);
        v3 = *(_BYTE*)(v2 + 21);
        if (v3 != 3 && v3 != 4)
        {
            v4 = *(_DWORD*)(v2 + 4);
            *(_BYTE*)(v2 + 21) = 4;
            v8 = 23 * *(_DWORD*)(v2 + 8);
            v7.field_0 = (double)(23 * v4) + 11.5;
            v7.field_4 = (double)v8 + 11.5;
            if (!*(_DWORD*)& byte_5D4594[2386840])
            {
                v5 = sub_410EE0(*(unsigned __int8*)(v1 + 1));
                v6 = sub_40AF50(v5);
                sub_501A30(v6, &v7, 0, 0);
            }
        }
    }
}

//----- (00512010) --------------------------------------------------------
int sub_512010()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 2, (void(__cdecl*)(int, int))sub_511F80, 0);
    return 0;
}

//----- (00512040) --------------------------------------------------------
int sub_512040()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_410580(v0 >> 16, (unsigned __int16)v0);
    if (v1)
        sub_512070(v1);
    return 0;
}

//----- (00512070) --------------------------------------------------------
void __cdecl sub_512070(int a1)
{
    int v1; // edx
    int v2; // ecx
    char v3; // al
    int v4; // eax
    char* v5; // eax
    int v6; // eax
    float2 v7; // [esp+0h] [ebp-8h]
    int v8; // [esp+Ch] [ebp+4h]

    v1 = a1;
    if (*(_BYTE*)(a1 + 4) & 4)
    {
        v2 = *(_DWORD*)(a1 + 28);
        v3 = *(_BYTE*)(v2 + 21);
        if (v3 != 1 && v3 != 2)
        {
            v4 = *(_DWORD*)(v2 + 4);
            *(_BYTE*)(v2 + 21) = 2;
            v8 = 23 * *(_DWORD*)(v2 + 8);
            v7.field_0 = (double)(23 * v4) + 11.5;
            v7.field_4 = (double)v8 + 11.5;
            if (!*(_DWORD*)& byte_5D4594[2386840])
            {
                v5 = sub_410F20(*(unsigned __int8*)(v1 + 1));
                v6 = sub_40AF50(v5);
                sub_501A30(v6, &v7, 0, 0);
            }
        }
    }
}

//----- (00512100) --------------------------------------------------------
int sub_512100()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 2, (void(__cdecl*)(int, int))sub_512070, 0);
    return 0;
}

//----- (00512130) --------------------------------------------------------
int sub_512130()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_410580(v0 >> 16, (unsigned __int16)v0);
    if (v1)
        sub_512160(v1);
    return 0;
}

//----- (00512160) --------------------------------------------------------
void __cdecl sub_512160(int a1)
{
    int v1; // eax
    char v2; // cl
    int v3; // ecx
    char* v4; // eax
    int v5; // ecx
    int v6; // eax
    float2 v7; // [esp+4h] [ebp-8h]

    if (*(_BYTE*)(a1 + 4) & 4)
    {
        v1 = *(_DWORD*)(a1 + 28);
        v2 = *(_BYTE*)(v1 + 21);
        if (v2 == 1 || v2 == 2)
        {
            v5 = *(_DWORD*)(v1 + 4);
            *(_BYTE*)(v1 + 21) = 4;
            v7.field_0 = (double)(23 * v5) + 11.5;
            v7.field_4 = (double)(int)(23 * *(_DWORD*)(v1 + 8)) + 11.5;
            if (*(_DWORD*)& byte_5D4594[2386840])
                return;
            v4 = sub_410EE0(*(unsigned __int8*)(a1 + 1));
        }
        else
        {
            v3 = *(_DWORD*)(v1 + 4);
            *(_BYTE*)(v1 + 21) = 2;
            v7.field_0 = (double)(23 * v3) + 11.5;
            v7.field_4 = (double)(int)(23 * *(_DWORD*)(v1 + 8)) + 11.5;
            if (*(_DWORD*)& byte_5D4594[2386840])
                return;
            v4 = sub_410F20(*(unsigned __int8*)(a1 + 1));
        }
        v6 = sub_40AF50(v4);
        sub_501A30(v6, &v7, 0, 0);
    }
}

//----- (00512260) --------------------------------------------------------
int sub_512260()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 2, (void(__cdecl*)(int, int))sub_512160, 0);
    return 0;
}

//----- (00512290) --------------------------------------------------------
int sub_512290()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_410580(v0 >> 16, (unsigned __int16)v0);
    if (v1)
        sub_5122C0(v1);
    return 0;
}

//----- (005122C0) --------------------------------------------------------
int __cdecl sub_5122C0(int a1)
{
    int v1; // edx
    int2 v3; // [esp+0h] [ebp-8h]

    v1 = *(unsigned __int8*)(a1 + 6);
    v3.field_0 = *(unsigned __int8*)(a1 + 5);
    v3.field_4 = v1;
    return sub_534DA0(&v3);
}

//----- (005122F0) --------------------------------------------------------
int sub_5122F0()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 2, (void(__cdecl*)(int, int))sub_5122C0, 0);
    return 0;
}

//----- (00512320) --------------------------------------------------------
int sub_512320()
{
    int v0; // esi
    int v1; // eax

    v0 = script_pop();
    v1 = script_pop();
    sub_51ACA0(v1 * *(_DWORD*)& byte_5D4594[2649704], v0, 0);
    return 0;
}

//----- (00512350) --------------------------------------------------------
int sub_512350()
{
    int v0; // esi
    int v1; // eax

    v0 = script_pop();
    v1 = script_pop();
    sub_51ACA0(v1, v0, 0);
    return 0;
}

//----- (00512370) --------------------------------------------------------
int sub_512370()
{
    int v0; // edi
    int v1; // eax
    int v2; // eax
    int v3; // esi
    int v4; // eax
    _DWORD* v5; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = v2;
    if (v2)
    {
        v4 = *(_DWORD*)(v2 + 16);
        if ((v4 & 0x8000) == 0)
        {
            v5 = sub_579C40(v0);
            if (v5)
                sub_5123C0(v3, (int)v5);
        }
    }
    return 0;
}

//----- (005123C0) --------------------------------------------------------
int* __cdecl sub_5123C0(int a1, int a2)
{
    int* result; // eax
    int v3; // ebx
    int* v4; // eax
    int* v5; // eax
    int* i; // esi

    result = *(int**)(a1 + 16);
    if (SBYTE1(result) >= 0)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v3 = *(_DWORD*)(a1 + 748);
            sub_50A3A0(a1);
            v4 = sub_50A260(a1, 32);
            if (v4)
                v4[1] = 8;
            if (*(_BYTE*)(a2 + 476))
            {
                v5 = sub_50A260(a1, 10);
                if (v5)
                {
                    v5[1] = a2;
                    *((_BYTE*)v5 + 12) = *(_BYTE*)(v3 + 1332);
                }
            }
            result = sub_50A260(a1, 8);
            if (result)
            {
                result[1] = *(_DWORD*)(a2 + 8);
                result[2] = *(_DWORD*)(a2 + 12);
                result[3] = 0;
            }
        }
        else if (*(unsigned __int16*)(a1 + 4) == *(_DWORD*)& byte_5D4594[2386836])
        {
            result = (int*)sub_5124C0((_DWORD*)a1, (_DWORD*)a2);
        }
        else
        {
            result = (int*)sub_4DA790();
            for (i = result; result; i = result)
            {
                if (*((unsigned __int16*)i + 2) == *(_DWORD*)& byte_5D4594[2386836]
                    && *(_DWORD*)(i[187] + 32) == *(_DWORD*)(a1 + 40))
                {
                    sub_5124C0(i, (_DWORD*)a2);
                }
                result = (int*)sub_4DA7A0((int)i);
            }
        }
    }
    return result;
}

//----- (005124C0) --------------------------------------------------------
int __cdecl sub_5124C0(_DWORD* a1, _DWORD* a2)
{
    int v2; // edi

    v2 = a1[187];
    sub_4E75B0((int)a1);
    a1[20] = 0;
    a1[21] = 0;
    *(_BYTE*)v2 = 0;
    *(_DWORD*)(v2 + 8) = *a2;
    return sub_4DA8D0((int)a1);
}

//----- (00512500) --------------------------------------------------------
int sub_512500()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    _DWORD* v3; // ebx
    int* i; // esi
    int v5; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_57C0A0(v1);
    v3 = sub_579C40(v0);
    if (v3)
    {
        if (v2)
        {
            for (i = *(int**)(v2 + 84); i; i = (int*)i[2])
            {
                v5 = sub_4ED020(*i);
                if (v5)
                    sub_5123C0(v5, (int)v3);
            }
        }
    }
    return 0;
}

//----- (00512560) --------------------------------------------------------
int sub_512560()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax
    int v3; // ecx

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        if (*(_BYTE*)(v2 + 8) & 2)
        {
            v3 = *(_DWORD*)(v2 + 16);
            if ((v3 & 0x8000) == 0)
                sub_5125A0(v2, v0);
        }
    }
    return 0;
}

//----- (005125A0) --------------------------------------------------------
float* __cdecl sub_5125A0(int a1, int a2)
{
    float* result; // eax
    int v3; // edx
    float v4; // [esp+0h] [ebp-8h]
    float v5; // [esp+4h] [ebp-4h]

    result = (float*)sub_509E90(a2);
    if (*(_BYTE*)(a1 + 8) & 2)
    {
        v3 = *(_DWORD*)(a1 + 16);
        if ((v3 & 0x8000) == 0)
        {
            v4 = *(float*)& byte_587000[8 * (_DWORD)result + 194136] * 10.0 + *(float*)(a1 + 56);
            v5 = *(float*)& byte_587000[8 * (_DWORD)result + 194140] * 10.0 + *(float*)(a1 + 60);
            result = (float*)sub_50A260(a1, 25);
            if (result)
            {
                result[1] = v4;
                result[2] = v5;
            }
        }
    }
    return result;
}

//----- (00512610) --------------------------------------------------------
int sub_512610()
{
    int v0; // edi
    int v1; // eax
    int result; // eax
    int* i; // esi
    int v4; // eax
    int v5; // ecx

    v0 = script_pop();
    v1 = script_pop();
    result = sub_57C0A0(v1);
    if (result)
    {
        for (i = *(int**)(result + 84); i; i = (int*)i[2])
        {
            v4 = sub_4ED020(*i);
            if (v4 && *(_BYTE*)(v4 + 8) & 2)
            {
                v5 = *(_DWORD*)(v4 + 16);
                if ((v5 & 0x8000) == 0)
                    sub_5125A0(v4, v0);
            }
        }
        result = 0;
    }
    return result;
}

//----- (00512670) --------------------------------------------------------
int sub_512670()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_4E75B0(v1);
    return 0;
}

//----- (00512690) --------------------------------------------------------
int sub_512690()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_5126C0, 0);
    return 0;
}

//----- (005126C0) --------------------------------------------------------
char __cdecl sub_5126C0(int a1)
{
    return sub_4E75B0(a1);
}

//----- (005126D0) --------------------------------------------------------
int sub_5126D0()
{
    int v0; // eax
    _DWORD* v1; // eax

    v0 = script_pop();
    v1 = sub_579C40(v0);
    if (v1)
        v1[120] |= 1u;
    return 0;
}

//----- (005126F0) --------------------------------------------------------
int sub_5126F0()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 1, (void(__cdecl*)(int, int))sub_512720, 0);
    return 0;
}

//----- (00512720) --------------------------------------------------------
int __cdecl sub_512720(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 480) |= 1u;
    return result;
}

//----- (00512730) --------------------------------------------------------
int sub_512730()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_4E7600(v1);
    return 0;
}

//----- (00512750) --------------------------------------------------------
int sub_512750()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_512780, 0);
    return 0;
}

//----- (00512780) --------------------------------------------------------
int __cdecl sub_512780(int a1)
{
    return sub_4E7600(a1);
}

//----- (00512790) --------------------------------------------------------
int sub_512790()
{
    int v0; // eax
    _DWORD* v1; // eax

    v0 = script_pop();
    v1 = sub_579C40(v0);
    if (v1)
        v1[120] &= 0xFFFFFFFE;
    return 0;
}

//----- (005127B0) --------------------------------------------------------
int sub_5127B0()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 1, (void(__cdecl*)(int, int))sub_5127E0, 0);
    return 0;
}

//----- (005127E0) --------------------------------------------------------
int __cdecl sub_5127E0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 480) &= 0xFFFFFFFE;
    return result;
}

//----- (005127F0) --------------------------------------------------------
int sub_5127F0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_4E7650(v1);
    return 0;
}

//----- (00512810) --------------------------------------------------------
int sub_512810()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_512840, 0);
    return 0;
}

//----- (00512840) --------------------------------------------------------
char __cdecl sub_512840(int a1)
{
    return sub_4E7650(a1);
}

//----- (00512850) --------------------------------------------------------
int sub_512850()
{
    int v0; // eax
    _DWORD* v1; // eax

    v0 = script_pop();
    v1 = sub_579C40(v0);
    if (v1)
        v1[120] ^= 1u;
    return 0;
}

//----- (00512870) --------------------------------------------------------
int sub_512870()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 1, (void(__cdecl*)(int, int))sub_5128A0, 0);
    return 0;
}

//----- (005128A0) --------------------------------------------------------
int __cdecl sub_5128A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 480) ^= 1u;
    return result;
}

//----- (005128B0) --------------------------------------------------------
int sub_5128B0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_4E5CC0(v1);
    return 0;
}

//----- (005128D0) --------------------------------------------------------
int sub_5128D0()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_512900, 0);
    return 0;
}

//----- (00512900) --------------------------------------------------------
void __cdecl sub_512900(int a1)
{
    sub_4E5CC0(a1);
}

//----- (00512910) --------------------------------------------------------
int sub_512910()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_512930(v1);
    return 0;
}

//----- (00512930) --------------------------------------------------------
void __cdecl sub_512930(int a1)
{
    int v1; // eax
    int v2; // edi
    int* v3; // eax
    int* v4; // eax

    if (*(_BYTE*)(a1 + 8) & 2)
    {
        v1 = *(_DWORD*)(a1 + 16);
        if ((v1 & 0x8000) == 0)
        {
            v2 = *(_DWORD*)(a1 + 748);
            sub_50A3A0(a1);
            v3 = sub_50A260(a1, 32);
            if (v3)
                v3[1] = 10;
            v4 = sub_50A260(a1, 10);
            if (v4)
            {
                v4[1] = 0;
                *((_BYTE*)v4 + 12) = *(_BYTE*)(v2 + 1332);
            }
        }
    }
}

//----- (00512990) --------------------------------------------------------
int sub_512990()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_512930, 0);
    return 0;
}

//----- (005129C0) --------------------------------------------------------
int sub_5129C0()
{
    int v0; // eax

    v0 = script_pop();
    sub_511B60(v0);
    return 0;
}

//----- (005129E0) --------------------------------------------------------
int sub_5129E0()
{
    int v0; // eax

    v0 = script_pop();
    sub_511B60(v0);
    return 0;
}

//----- (00512A00) --------------------------------------------------------
int sub_512A00()
{
    int v0; // eax
    int result; // eax
    int v2; // esi
    int v3; // eax
    _DWORD* v4; // edi
    int* v5; // eax
    int* v6; // eax
    int* v7; // eax

    v0 = script_pop();
    result = sub_511B60(v0);
    v2 = result;
    if (result)
    {
        if (*(_BYTE*)(result + 8) & 2)
        {
            v3 = *(_DWORD*)(result + 16);
            if ((v3 & 0x8000) == 0)
            {
                v4 = *(_DWORD * *)(v2 + 748);
                sub_50A3A0(v2);
                v5 = sub_50A260(v2, 32);
                if (v5)
                    v5[1] = 37;
                v6 = sub_50A260(v2, 25);
                if (v6)
                {
                    *((float*)v6 + 1) = *(float*)& byte_587000[8 * v4[94] + 194136] * 10.0 + *(float*)(v2 + 56);
                    *((float*)v6 + 2) = *(float*)& byte_587000[8 * v4[94] + 194140] * 10.0 + *(float*)(v2 + 60);
                }
                v7 = sub_50A260(v2, 37);
                if (v7)
                {
                    v7[1] = v4[95];
                    v7[2] = v4[96];
                    v7[3] = 0;
                }
                result = 0;
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (00512AC0) --------------------------------------------------------
int sub_512AC0()
{
    int v0; // esi
    int v1; // edi
    float2* v2; // eax
    int v3; // eax
    float2* v5; // [esp-Ch] [ebp-14h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = (float2*)sub_579C40(v0);
    if (v2)
    {
        v5 = v2 + 1;
        v3 = sub_40AF50(*(void**)& byte_5D4594[4 * v1 + 3831212]);
        sub_501A30(v3, v5, 0, 0);
    }
    return 0;
}

//----- (00512B10) --------------------------------------------------------
int sub_512B10()
{
    int v0; // eax
    wchar_t* v1; // eax

    v0 = script_pop();
    if (*(_DWORD*)& byte_5D4594[3821964] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[3821964] + 8) & 4)
    {
        v1 = loadString_sub_40F1D0(*(char**)& byte_5D4594[4 * v0 + 3831212], 0, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1285);
        sub_4D9EB0(*(int*)& byte_5D4594[3821964], v1);
    }
    return 0;
}

//----- (00512B60) --------------------------------------------------------
int sub_512B60()
{
    int v0; // eax
    wchar_t* v1; // eax

    v0 = script_pop();
    v1 = loadString_sub_40F1D0(*(char**)& byte_5D4594[4 * v0 + 3831212], 0, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1310);
    sub_4D9FD0(0, v1);
    return 0;
}

//----- (00512B90) --------------------------------------------------------
int sub_512B90()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    char* v3; // ecx
    wchar_t* v4; // eax
    int v6; // [esp+8h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = *(char**)& byte_5D4594[4 * v0 + 3831212];
        v6 = 0;
        v4 = loadString_sub_40F1D0(v3, &v6, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1342);
        sub_528AC0(v2, v4, 0);
        if (sub_40A5C0(2048))
            sub_44D900(v6, 100);
    }
    return 0;
}

//----- (00512C10) --------------------------------------------------------
int sub_512C10()
{
    return 1;
}

//----- (00512C20) --------------------------------------------------------
int sub_512C20()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1 && (*(_BYTE*)(v1 + 8) & 0x80))
    {
        *(_BYTE*)(*(_DWORD*)(v1 + 748) + 1) = 0;
        sub_501960(234, v1, 0, 0);
    }
    return 0;
}

//----- (00512C60) --------------------------------------------------------
int sub_512C60()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1 && (*(_BYTE*)(v1 + 8) & 0x80))
    {
        *(_BYTE*)(*(_DWORD*)(v1 + 748) + 1) = 5;
        sub_501960(233, v1, 0, 0);
    }
    return 0;
}

//----- (00512CA0) --------------------------------------------------------
int sub_512CA0()
{
    int v0; // eax
    int v1; // eax
    int result; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1 && *(_DWORD*)(v1 + 16) & 0x1000000)
    {
        sub_507230(1);
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00512CE0) --------------------------------------------------------
int sub_512CE0()
{
    int v0; // eax
    _DWORD* v1; // eax
    int result; // eax

    v0 = script_pop();
    v1 = sub_579C40(v0);
    if (v1 && v1[120] & 1)
    {
        sub_507230(1);
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00512D20) --------------------------------------------------------
int sub_512D20()
{
    int v0; // eax
    int v1; // eax
    int result; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1 && (*(_BYTE*)(v1 + 8) & 0x80))
    {
        sub_507230(*(_BYTE*)(*(_DWORD*)(v1 + 748) + 1) != 0);
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00512D70) --------------------------------------------------------
int sub_512D70()
{
    int v0; // esi
    int v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    *(float*)& v3 = sub_416030(*(float*)& v1, *(float*)& v0);
    sub_507230(v3);
    return 0;
}

//----- (00512DB0) --------------------------------------------------------
int sub_512DB0()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_415FA0(v1, v0);
    sub_507230(v2);
    return 0;
}

//----- (00512DE0) --------------------------------------------------------
int sub_512DE0()
{
    int v0; // esi
    int v1; // edi
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    sub_51ACA0(v2 * *(_DWORD*)& byte_5D4594[2649704], v0, v1);
    return 0;
}

//----- (00512E10) --------------------------------------------------------
int sub_512E10()
{
    int v0; // esi
    int v1; // edi
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    sub_51ACA0(v2, v0, v1);
    return 0;
}

//----- (00512E40) --------------------------------------------------------
int __cdecl sub_512E40(char* a1)
{
    char* v1; // eax
    int v2; // ecx

    if (*(_DWORD*)& byte_5D4594[1599632] >= 1024)
        return *(_DWORD*)& byte_5D4594[1599632] - 1;
    v1 = _strdup(a1);
    v2 = *(_DWORD*)& byte_5D4594[1599632];
    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1599632] + 3831212] = v1;
    *(_DWORD*)& byte_5D4594[1599632] = v2 + 1;
    return v2;
}

//----- (00512E80) --------------------------------------------------------
int __cdecl sub_512E80(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)& byte_5D4594[1599628];
    if (*(int*)& byte_5D4594[1599628] < 1024)
    {
        *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1599628] + 3826092] = a1;
        *(_DWORD*)& byte_5D4594[1599628] = ++v1;
    }
    return v1 - 1;
}

//----- (00512EA0) --------------------------------------------------------
int sub_512EA0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    _itoa(v0, (char*)& byte_5D4594[3821708], 10);
    v1 = sub_512E40((char*)& byte_5D4594[3821708]);
    sub_507230(v1);
    return 0;
}

//----- (00512ED0) --------------------------------------------------------
int sub_512ED0()
{
    float v0; // eax
    int v1; // eax

    v0 = COERCE_FLOAT(script_pop());
    nox_sprintf((char*)& byte_5D4594[3821708], "%f", v0, v0);
    v1 = sub_512E40((char*)& byte_5D4594[3821708]);
    sub_507230(v1);
    return 0;
}

//----- (00512F10) --------------------------------------------------------
int sub_512F10()
{
    int v0; // esi
    int v1; // edi
    float* v2; // esi
    _DWORD* v3; // eax
    _DWORD* v4; // edi

    v0 = script_pop();
    v1 = script_pop();
    v2 = (float*)sub_579C40(v0);
    if (v2)
    {
        v3 = sub_4E3810(*(CHAR * *)& byte_5D4594[4 * v1 + 3831212]);
        v4 = v3;
        if (!v3)
        {
            sub_507230(0);
            return 0;
        }
        sub_4DAA50((int)v3, 0, v2[2], v2[3]);
        sub_507230(v4[11]);
    }
    return 0;
}

//----- (00512F80) --------------------------------------------------------
int sub_512F80()
{
    int v0; // edi
    int v1; // ebx
    int v2; // ebp
    int v3; // eax
    int v4; // esi
    int v6[3]; // [esp+10h] [ebp-Ch]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = script_pop();
    v4 = sub_511B60(v3);
    if (v4)
    {
        v6[0] = sub_511B60(v2);
        v6[1] = v1;
        v6[2] = v0;
        sub_512FE0(v4, v6);
    }
    return 0;
}

//----- (00512FE0) --------------------------------------------------------
void __cdecl sub_512FE0(int a1, int* a2)
{
    int v2; // eax
    int v3; // [esp-Ch] [ebp-Ch]
    int v4; // [esp-8h] [ebp-8h]
    int v5; // [esp-4h] [ebp-4h]

    if (a2[1] > 0)
    {
        v5 = a2[2];
        v4 = a2[1];
        v3 = *a2;
        v2 = sub_4EC580(*a2);
        (*(void(__cdecl * *)(int, int, int, int, int))(a1 + 716))(a1, v2, v3, v4, v5);
    }
}

//----- (00513010) --------------------------------------------------------
int sub_513010()
{
    int v0; // esi
    int v1; // edi
    int v2; // ebx
    int v3; // ebp
    unsigned __int8* v4; // eax
    int v6[3];

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = script_pop();
    v6[0] = sub_511B60(v2);
    v6[1] = v1;
    v6[2] = v0;
    v4 = (unsigned __int8*)sub_57C0A0(v3);
    sub_502670(v4, 0, (void(__cdecl*)(int, int))sub_512FE0, (int)v6);
    return 0;
}

//----- (00513070) --------------------------------------------------------
int sub_513070()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    float v4; // [esp+8h] [ebp-10h]
    int v5[3]; // [esp+Ch] [ebp-Ch]

    v4 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v5[1] = v0;
        v5[0] = (__int64)v4;
        sub_5130E0(v2, v5);
        sub_507230(v5[2]);
    }
    else
    {
        sub_507230(0);
    }
    return 0;
}

//----- (005130E0) --------------------------------------------------------
_DWORD* __cdecl sub_5130E0(int a1, _DWORD* a2)
{
    _DWORD* v2; // eax
    _DWORD* v3; // esi
    _DWORD* result; // eax
    int v5; // eax

    v2 = sub_4E3810((CHAR*)& byte_587000[247016]);
    v3 = v2;
    if (v2)
    {
        sub_4DAA50((int)v2, 0, *(float*)(a1 + 56), *(float*)(a1 + 60));
        v5 = v3[187];
        *(_DWORD*)(v5 + 28) = a1;
        *(_DWORD*)(v5 + 8) = a2[1];
        *(_DWORD*)(v5 + 4) = *a2;
        *(_BYTE*)v5 = 0;
        v3[20] = 0;
        v3[21] = 0;
        sub_4E75B0((int)v3);
        sub_4DA8D0((int)v3);
        result = (_DWORD*)v3[11];
        a2[2] = result;
    }
    else
    {
        result = a2;
        a2[2] = 0;
    }
    return result;
}

//----- (00513160) --------------------------------------------------------
int sub_513160()
{
    int v0; // esi
    int v1; // edi
    unsigned __int8* v2; // eax
    float v4; // [esp+8h] [ebp-10h]
    int v5[3]; // [esp+Ch] [ebp-Ch]

    v4 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = script_pop();
    v5[1] = v0;
    v5[0] = (__int64)v4;
    v2 = (unsigned __int8*)sub_57C0A0(v1);
    sub_502670(v2, 0, (void(__cdecl*)(int, int))sub_5130E0, (int)v5);
    return 0;
}

//----- (005131C0) --------------------------------------------------------
int sub_5131C0()
{
    int v0; // esi
    int v1; // edi
    int v2; // esi
    int result; // eax
    int v4; // eax
    int v5; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_4243F0(*(const char**)& byte_5D4594[4 * v0 + 3831212]);
    if (v2)
    {
        v4 = sub_511B60(v1);
        if (v4)
        {
            v5 = sub_4FB550(v4, v2, 1, 0, 0);
            sub_507230(v5);
        }
        else
        {
            sub_507230(0);
        }
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00513230) --------------------------------------------------------
int sub_513230()
{
    int v0; // esi
    int v1; // edi
    unsigned __int8* v2; // eax
    int v4; // [esp+8h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v4 = sub_4243F0(*(const char**)& byte_5D4594[4 * v0 + 3831212]);
    if (v4)
    {
        v2 = (unsigned __int8*)sub_57C0A0(v1);
        sub_502670(v2, 0, (void(__cdecl*)(int, int))sub_513280, (int)& v4);
    }
    return 0;
}

//----- (00513280) --------------------------------------------------------
int __cdecl sub_513280(int a1, int* a2)
{
    int v2; // esi

    v2 = 0;
    if (sub_40A5C0(2048)
        && *(_BYTE*)(a1 + 8) & 4
        && !*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 4 * *a2 + 3696))
    {
        v2 = 1;
    }
    return sub_4FB550(a1, *a2, 1, v2, 0);
}

//----- (005132E0) --------------------------------------------------------
int sub_5132E0()
{
    int v0; // esi
    int v1; // ebx
    int v2; // esi
    int v3; // edi
    float v5; // [esp+Ch] [ebp-54h]
    int v6[2]; // [esp+18h] [ebp-48h]
    char v8[64]; // [esp+20h] [ebp-40h]

    v5 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = script_pop();
    strcpy(v8, *(const char**)& byte_5D4594[4 * v0 + 3831212]);
    v2 = sub_424880(v8);
    if (v2 != -1)
    {
        v3 = sub_511B60(v1);
        if (v3)
        {
            v6[0] = v2;
            v6[1] = (__int64)((double) * (unsigned int*)& byte_5D4594[2649704] * v5);
            sub_513390(v3, v6);
        }
    }
    return 0;
}

//----- (00513390) --------------------------------------------------------
__int16 __cdecl sub_513390(int a1, int* a2)
{
    return sub_4FF380(a1, *a2, a2[1], 5);
}

//----- (005133B0) --------------------------------------------------------
int sub_5133B0()
{
    int v0; // esi
    int v1; // ebx
    int v2; // eax
    unsigned __int8* v3; // eax
    float v5; // [esp+Ch] [ebp-54h]
    int v6[2]; // [esp+18h] [ebp-48h]
    char v7[64]; // [esp+20h] [ebp-40h]

    v5 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = script_pop();
    strcpy(v7, *(const char**)& byte_5D4594[4 * v0 + 3831212]);
    v2 = sub_424880(v7);
    if (v2 != -1)
    {
        v6[0] = v2;
        v6[1] = (__int64)((double) * (unsigned int*)& byte_5D4594[2649704] * v5);
        v3 = (unsigned __int8*)sub_57C0A0(v1);
        sub_502670(v3, 0, (void(__cdecl*)(int, int))sub_513390, (int)v6);
    }
    return 0;
}

//----- (00513460) --------------------------------------------------------
int sub_513460()
{
    int v0; // eax

    v0 = *((_DWORD*)sub_417090(31) + 514);
    if (v0)
        sub_507230(*(_DWORD*)(v0 + 44));
    else
        sub_507230(0);
    return 0;
}

//----- (00513490) --------------------------------------------------------
int sub_513490()
{
    int v0; // eax
    char v2[76]; // [esp+4h] [ebp-4Ch]

    strcpy(v2, *(const char**)& byte_5D4594[4 * script_pop() + 3831212]);
    strcat(v2, (const char*)& byte_5D4594[3821644]);
    v0 = sub_4DA4F0(v2);
    if (v0)
        sub_507230(*(_DWORD*)(v0 + 44));
    else
        sub_507230(0);
    return 0;
}

//----- (00513530) --------------------------------------------------------
int sub_513530()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_507230(*(_DWORD*)(v1 + 56));
    else
        sub_507230(0);
    return 0;
}

//----- (00513570) --------------------------------------------------------
int sub_513570()
{
    int v0; // eax
    _DWORD* v1; // eax

    v0 = script_pop();
    v1 = sub_579C40(v0);
    if (v1)
        sub_507230(v1[2]);
    else
        sub_507230(0);
    return 0;
}

//----- (005135B0) --------------------------------------------------------
int sub_5135B0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_507230(*(_DWORD*)(v1 + 60));
    else
        sub_507230(0);
    return 0;
}

//----- (005135F0) --------------------------------------------------------
int sub_5135F0()
{
    int v0; // eax
    _DWORD* v1; // eax

    v0 = script_pop();
    v1 = sub_579C40(v0);
    if (v1)
        sub_507230(v1[3]);
    else
        sub_507230(0);
    return 0;
}

//----- (00513630) --------------------------------------------------------
int sub_513630()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_507230(*(_DWORD*)(v1 + 104));
    else
        sub_507230(0);
    return 0;
}

//----- (00513670) --------------------------------------------------------
int sub_513670()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_507230(*(__int16*)(v1 + 124));
    else
        sub_507230(0);
    return 0;
}

//----- (005136A0) --------------------------------------------------------
int sub_5136A0()
{
    int v0; // eax
    int v1; // eax
    float2 v3; // [esp+0h] [ebp-Ch]
    float v4; // [esp+8h] [ebp-4h]

    v4 = COERCE_FLOAT(script_pop());
    LODWORD(v3.field_0) = script_pop();
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v3.field_0 = (double) * (int*)& byte_5D4594[3821636] + v3.field_0;
        v3.field_4 = (double) * (int*)& byte_5D4594[3821640] + v4;
        sub_4E7010(v1, &v3);
    }
    return 0;
}

//----- (00513700) --------------------------------------------------------
int sub_513700()
{
    int v0; // eax
    float* v1; // eax
    float v3; // [esp+0h] [ebp-8h]
    float v4; // [esp+4h] [ebp-4h]

    v4 = COERCE_FLOAT(script_pop());
    v3 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = (float*)sub_579C40(v0);
    if (v1)
    {
        v1[2] = (double) * (int*)& byte_5D4594[3821636] + v3;
        v1[3] = (double) * (int*)& byte_5D4594[3821640] + v4;
    }
    return 0;
}

//----- (00513750) --------------------------------------------------------
int sub_513750()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
        sub_4E46F0(v2, *(float*)& v0);
    return 0;
}

//----- (00513780) --------------------------------------------------------
int sub_513780()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax
    unsigned int v3; // ecx

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = v0;
        if (v0 < 0)
            v3 = v0 + ((unsigned int)(255 - v0) >> 8 << 8);
        if ((int)v3 >= 256)
            LOWORD(v3) = -256 * (v3 >> 8) + v3;
        *(_WORD*)(v2 + 126) = v3;
        *(_WORD*)(v2 + 124) = v3;
    }
    return 0;
}

//----- (005137D0) --------------------------------------------------------
int sub_5137D0()
{
    int v0; // eax
    int v1; // eax
    float v3; // [esp+0h] [ebp-8h]
    float v4; // [esp+4h] [ebp-4h]

    v4 = COERCE_FLOAT(script_pop());
    v3 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        *(float*)(v1 + 88) = v3 + *(float*)(v1 + 88);
        *(float*)(v1 + 92) = v4 + *(float*)(v1 + 92);
    }
    return 0;
}

//----- (00513820) --------------------------------------------------------
int sub_513820()
{
    int v0; // eax
    float* v1; // eax
    double v2; // st7
    double v3; // st6
    float v5; // [esp+0h] [ebp-Ch]
    float v6; // [esp+0h] [ebp-Ch]
    float v7; // [esp+4h] [ebp-8h]
    float v8; // [esp+8h] [ebp-4h]
    float v9; // [esp+8h] [ebp-4h]

    v5 = COERCE_FLOAT(script_pop());
    v8 = COERCE_FLOAT(script_pop());
    v7 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = (float*)sub_511B60(v0);
    if (v1)
    {
        v2 = v1[14] - v8 + (double) * (int*)& byte_5D4594[3821636];
        v3 = v1[15] - v5 + (double) * (int*)& byte_5D4594[3821640];
        v6 = v3;
        v9 = sqrt(v3 * v6 + v2 * v2);
        v1[22] = v7 * v2 / v9 + v1[22];
        v1[23] = v7 * v6 / v9 + v1[23];
    }
    return 0;
}

//----- (005138B0) --------------------------------------------------------
int sub_5138B0()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax
    int v3; // eax

    v0 = script_pop();
    v1 = 0;
    v2 = sub_511B60(v0);
    if (v2)
    {
        v3 = *(_DWORD*)(v2 + 504);
        if (v3)
            v1 = *(_DWORD*)(v3 + 44);
    }
    sub_507230(v1);
    return 0;
}

//----- (005138E0) --------------------------------------------------------
int sub_5138E0()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax
    int v3; // eax

    v0 = script_pop();
    v1 = 0;
    v2 = sub_511B60(v0);
    if (v2)
    {
        v3 = *(_DWORD*)(v2 + 496);
        if (v3)
            v1 = *(_DWORD*)(v3 + 44);
    }
    sub_507230(v1);
    return 0;
}

//----- (00513910) --------------------------------------------------------
int sub_513910()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // edi

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_511B60(v0);
    v4 = 0;
    if (v2 && v3 && sub_4F78E0(v2, v3))
        v4 = 1;
    sub_507230(v4);
    return 0;
}

//----- (00513960) --------------------------------------------------------
int sub_513960()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_507230(*(_DWORD*)(*(_DWORD*)(v1 + 492) + 44));
    else
        sub_507230(0);
    return 0;
}

//----- (005139A0) --------------------------------------------------------
int sub_5139A0()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // ebp
    int v5; // eax
    int v6; // edi

    if (!*(_DWORD*)& byte_5D4594[2386860])
    {
        *(_DWORD*)& byte_5D4594[2386860] = sub_4E3AA0((CHAR*)& byte_587000[247024]);
        *(_DWORD*)& byte_5D4594[2386864] = sub_4E3AA0((CHAR*)& byte_587000[247032]);
        *(_DWORD*)& byte_5D4594[2386868] = sub_4E3AA0((CHAR*)& byte_587000[247048]);
    }
    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_511B60(v0);
    v4 = v3;
    if (v2 && v3)
    {
        if (sub_40A5C0(2048)
            && (*(_BYTE*)(v2 + 8) & 4) == 4
            && *(_DWORD*)& byte_5D4594[2386844] != *(_DWORD*)& byte_5D4594[2598000])
        {
            *(_DWORD*)& byte_5D4594[2386844] = *(_DWORD*)& byte_5D4594[2598000];
            *(_DWORD*)& byte_5D4594[2386848] = 0;
            *(_DWORD*)& byte_5D4594[2386852] = 0;
        }
        if (*(_BYTE*)(v2 + 8) & 4)
        {
            if (sub_40A5C0(2048))
            {
                v5 = *(unsigned __int16*)(v2 + 4);
                if ((unsigned __int16)v5 != *(_DWORD*)& byte_5D4594[2386860]
                    && v5 != *(_DWORD*)& byte_5D4594[2386864]
                    && v5 != *(_DWORD*)& byte_5D4594[2386868])
                {
                    sub_513B00(v2, v4);
                }
            }
        }
        v6 = sub_4F36F0(v2, v4, 1, 1);
        if (v6 == 1
            && *(_BYTE*)(v2 + 8) & 4
            && sub_40A5C0(2048)
            && *(unsigned __int16*)(v4 + 4) != *(_DWORD*)& byte_5D4594[2386860])
        {
            ++* (_DWORD*)& byte_5D4594[2386848];
            sub_507230(1);
            return 0;
        }
    }
    else
    {
        v6 = 0;
    }
    sub_507230(v6);
    return 0;
}

//----- (00513B00) --------------------------------------------------------
void __cdecl sub_513B00(int a1, int a2)
{
    _DWORD* v2; // ebp
    int v3; // edi
    int v4; // esi
    int v5; // eax
    int v6; // eax
    float2 v7; // [esp+0h] [ebp-8h]

    if (!*(_DWORD*)& byte_5D4594[2386856])
        * (_DWORD*)& byte_5D4594[2386856] = sub_4E3AA0((CHAR*)& byte_587000[247064]);
    if (sub_467B00(*(unsigned __int16*)(a2 + 4), 1) - *(int*)& byte_5D4594[2386848] <= 0)
    {
        v2 = 0;
        v3 = 999999;
        v4 = sub_4E7980(a1);
        if (v4)
        {
            do
            {
                if (!(*(_BYTE*)(v4 + 8) & 0x10))
                {
                    v5 = *(_DWORD*)(v4 + 16);
                    if (!(v5 & 0x100) && *(unsigned __int16*)(v4 + 4) != *(_DWORD*)& byte_5D4594[2386856] && !sub_53EBF0(v4))
                    {
                        v6 = sub_50E3D0(1, 0, *(float*)& v4);
                        if (v6 < v3)
                        {
                            v3 = v6;
                            v2 = (_DWORD*)v4;
                        }
                    }
                }
                v4 = sub_4E7990(v4);
            } while (v4);
            if (v2)
            {
                sub_4ED970(50.0, (float2*)(a1 + 56), &v7);
                sub_4ED790(a1, v2, &v7);
                if (!*(_DWORD*)& byte_5D4594[2386852])
                {
                    sub_4DA2C0(a1, "pickup.c:CarryingTooMuch", 0);
                    *(_DWORD*)& byte_5D4594[2386852] = 1;
                }
            }
        }
    }
}

//----- (00513C10) --------------------------------------------------------
int sub_513C10()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    _DWORD* v3; // eax
    int v4; // eax
    int result; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = (_DWORD*)sub_511B60(v0);
    if (v2 && v3)
    {
        v4 = sub_4ED930(v2, v3);
        sub_507230(v4);
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00513C60) --------------------------------------------------------
int sub_513C60()
{
    return 0;
}

//----- (00513C70) --------------------------------------------------------
int sub_513C70()
{
    int v0; // esi
    int v1; // ebx
    int v2; // eax
    char v3; // si
    int v4; // eax
    int v5; // eax
    int result; // eax
    char v7[64]; // [esp+Ch] [ebp-40h]

    v0 = script_pop();
    v1 = script_pop();
    strcpy(v7, *(const char**)& byte_5D4594[4 * v0 + 3831212]);
    v2 = sub_424880(v7);
    v3 = v2;
    if (v2 != -1 && (v4 = sub_511B60(v1)) != 0)
    {
        v5 = sub_4FF350(v4, v3);
        sub_507230(v5);
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00513D00) --------------------------------------------------------
int sub_513D00()
{
    int v0; // esi
    int v1; // ebx
    int v2; // esi
    int v3; // eax
    char v5[64]; // [esp+Ch] [ebp-40h]

    v0 = script_pop();
    v1 = script_pop();
    strcpy(v5, *(const char**)& byte_5D4594[4 * v0 + 3831212]);
    v2 = sub_424880(v5);
    if (v2 != -1)
    {
        v3 = sub_511B60(v1);
        if (v3)
            sub_4FF5B0(v3, v2);
    }
    return 0;
}

//----- (00513D70) --------------------------------------------------------
int sub_513D70()
{
    int v0; // eax
    int v1; // eax
    unsigned __int16* v2; // ecx
    int result; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1 && (v2 = *(unsigned __int16**)(v1 + 556)) != 0)
    {
        sub_507230(*v2);
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00513DB0) --------------------------------------------------------
int sub_513DB0()
{
    int v0; // eax
    int v1; // eax
    int v2; // ecx
    int result; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1 && (v2 = *(_DWORD*)(v1 + 556)) != 0)
    {
        sub_507230(*(unsigned __int16*)(v2 + 4));
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (00513DF0) --------------------------------------------------------
int sub_513DF0()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2 && v0 > 0)
        sub_4EE460(v2, v0);
    return 0;
}

//----- (00513E20) --------------------------------------------------------
int sub_513E20()
{
    float v0; // eax
    float v2; // [esp+4h] [ebp-Ch]
    float v3; // [esp+8h] [ebp-8h]
    float v4; // [esp+Ch] [ebp-4h]
    int v5; // [esp+Ch] [ebp-4h]

    v4 = COERCE_FLOAT(script_pop());
    v2 = COERCE_FLOAT(script_pop());
    v3 = COERCE_FLOAT(script_pop());
    v0 = COERCE_FLOAT(script_pop());
    *(float*)& v5 = sqrt((v3 - v4) * (v3 - v4) + (v0 - v2) * (v0 - v2));
    sub_507230(v5);
    return 0;
}

//----- (00513E80) --------------------------------------------------------
int sub_513E80()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // edx
    double v5; // st7
    double v6; // st7

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_511B60(v0);
    v4 = 0;
    if (v2 && v3)
    {
        v5 = *(float*)(v2 + 56) - *(float*)(v3 + 56);
        if (v5 < 0.0)
            v5 = -v5;
        if (v5 <= 512.0)
        {
            v6 = *(float*)(v2 + 60) - *(float*)(v3 + 60);
            if (v6 < 0.0)
                v6 = -v6;
            if (v6 <= 512.0)
                v4 = sub_5370E0(v2, v3, 0);
        }
    }
    sub_507230(v4);
    return 0;
}

//----- (00513F10) --------------------------------------------------------
int sub_513F10()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00513F20) --------------------------------------------------------
int sub_513F20()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00513F30) --------------------------------------------------------
int sub_513F30()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00513F40) --------------------------------------------------------
int sub_513F40()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00513F50) --------------------------------------------------------
int sub_513F50()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00513F60) --------------------------------------------------------
int sub_513F60()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00513F70) --------------------------------------------------------
int sub_513F70()
{
    int v0; // eax
    wchar_t* v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = loadString_sub_40F1D0(*(char**)& byte_5D4594[4 * v0 + 3831212], 0, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 2901);
    v2 = sub_512E80((int)v1);
    sub_507230(v2);
    return 0;
}

//----- (00513FA0) --------------------------------------------------------
int sub_513FA0()
{
    int v0; // esi
    char* v1; // eax
    int result; // eax

    v0 = script_pop();
    v1 = sub_431770();
    switch (v0)
    {
    case 0:
        sub_507230(*(_DWORD*)(v1 + 50));
        result = 0;
        break;
    case 1:
        sub_507230(*(_DWORD*)(v1 + 54));
        result = 0;
        break;
    case 2:
        sub_507230(*(_DWORD*)(v1 + 58));
        result = 0;
        break;
    case 3:
        sub_507230(*(_DWORD*)(v1 + 62));
        result = 0;
        break;
    case 4:
        sub_507230((unsigned __int8)v1[66]);
        result = 0;
        break;
    case 5:
        sub_507230((unsigned __int8)v1[67]);
        result = 0;
        break;
    default:
        sub_507230(0);
        result = 0;
        break;
    }
    return result;
}

//----- (00514050) --------------------------------------------------------
int sub_514050()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    __int16 v4; // ax
    float2 v6; // [esp+8h] [ebp-8h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_511B60(v0);
    if (v2 && v3)
    {
        v6.field_0 = *(float*)(v3 + 56) - *(float*)(v2 + 56);
        v6.field_4 = *(float*)(v3 + 60) - *(float*)(v2 + 60);
        v4 = sub_509ED0(&v6);
        *(_WORD*)(v2 + 126) = v4;
        *(_WORD*)(v2 + 124) = v4;
    }
    return 0;
}

//----- (005140B0) --------------------------------------------------------
int sub_5140B0()
{
    int v0; // eax
    int v1; // eax
    int v3; // [esp+0h] [ebp-10h]
    int v4; // [esp+4h] [ebp-Ch]
    float v5; // [esp+8h] [ebp-8h]
    float v6; // [esp+Ch] [ebp-4h]

    v5 = COERCE_FLOAT(script_pop());
    v6 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        *(float*)& v4 = (double) * (int*)& byte_5D4594[3821640] + v5;
        *(float*)& v3 = (double) * (int*)& byte_5D4594[3821636] + v6;
        sub_514110(v1, v3, v4);
    }
    return 0;
}

//----- (00514110) --------------------------------------------------------
int* __cdecl sub_514110(int a1, int a2, int a3)
{
    int* result; // eax
    int* v4; // eax

    result = *(int**)(a1 + 16);
    if (SBYTE1(result) >= 0 && *(_BYTE*)(a1 + 8) & 2)
    {
        sub_50A3A0(a1);
        v4 = sub_50A260(a1, 32);
        if (v4)
            v4[1] = 8;
        result = sub_50A260(a1, 8);
        if (result)
        {
            result[1] = a2;
            result[2] = a3;
            result[3] = 0;
        }
    }
    return result;
}

//----- (00514170) --------------------------------------------------------
int sub_514170()
{
    int v0; // eax
    int result; // eax
    int* i; // esi
    int v3; // eax
    int v4; // [esp+0h] [ebp-14h]
    int v5; // [esp+4h] [ebp-10h]
    float v6; // [esp+Ch] [ebp-8h]
    float v7; // [esp+10h] [ebp-4h]

    v6 = COERCE_FLOAT(script_pop());
    v7 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    result = sub_57C0A0(v0);
    if (result)
    {
        for (i = *(int**)(result + 84); i; i = (int*)i[2])
        {
            v3 = sub_4ED020(*i);
            if (v3)
            {
                *(float*)& v5 = (double) * (int*)& byte_5D4594[3821640] + v6;
                *(float*)& v4 = (double) * (int*)& byte_5D4594[3821636] + v7;
                sub_514110(v3, v4, v5);
            }
        }
        result = 0;
    }
    return result;
}

//----- (005141F0) --------------------------------------------------------
int sub_5141F0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_51AD60(v0);
    sub_507230(v1 != 0);
    return 0;
}

//----- (00514210) --------------------------------------------------------
int sub_514210()
{
    int v0; // ebp
    const char* v1; // edi
    const char* v2; // esi
    unsigned int v3; // ebx
    char* v4; // edi
    char* v5; // edi
    const char* v6; // esi
    char v7; // cl
    char v8; // bl
    char v9; // si
    int result; // eax
    int v11; // eax
    char v12; // al
    unsigned __int8 v13; // [esp+10h] [ebp-68h]
    float v14; // [esp+14h] [ebp-64h]
    float v15; // [esp+18h] [ebp-60h]
    int v16; // [esp+1Ch] [ebp-5Ch]
    float2 v17; // [esp+20h] [ebp-58h]
    int v19[4]; // [esp+28h] [ebp-50h]
    char v20[64]; // [esp+38h] [ebp-40h]

    v16 = script_pop();
    v0 = script_pop();
    v15 = COERCE_FLOAT(script_pop());
    v14 = COERCE_FLOAT(script_pop());
    v1 = *(const char**)& byte_5D4594[4 * script_pop() + 3831212];
    strcpy(v20, "MSG_FX_");
    v17.field_0 = (double) * (int*)& byte_5D4594[3821636] + v14;
    v17.field_4 = (double) * (int*)& byte_5D4594[3821640] + v15;
    v2 = v1;
    v3 = strlen(v1) + 1;
    v4 = &v20[strlen(v20)];
    qmemcpy(v4, v2, 4 * (v3 >> 2));
    v6 = &v2[4 * (v3 >> 2)];
    v5 = &v4[4 * (v3 >> 2)];
    v7 = v3;
    v8 = 87;
    v13 = 87;
    qmemcpy(v5, v6, v7 & 3);
    do
    {
        if (!_strcmpi(*(const char**)& byte_587000[4 * v13 + 238648], v20))
            break;
        v13 = ++v8;
    } while ((unsigned __int8)v8 <= 0x73u);
    v9 = v8 + 39;
    switch ((unsigned __int8)(v8 + 39))
    {
    case 0x81u:
    case 0x82u:
    case 0x83u:
    case 0x84u:
    case 0x85u:
    case 0x86u:
    case 0x87u:
    case 0x88u:
    case 0x89u:
    case 0x8Au:
    case 0x8Bu:
    case 0x96u:
    case 0x9Au:
    case 0xA0u:
    case 0xA3u:
        sub_522FF0(v8 + 39, &v17);
        result = 0;
        break;
    case 0x8Cu:
    case 0x8Fu:
    case 0x90u:
    case 0x91u:
    case 0x94u:
    case 0x95u:
        v19[0] = *(_DWORD*)& byte_5D4594[3821636] + sub_419A70(v14);
        v19[1] = *(_DWORD*)& byte_5D4594[3821640] + sub_419A70(v15);
        v19[2] = *(_DWORD*)& byte_5D4594[3821636] + sub_419A70(*(float*)& v0);
        v19[3] = *(_DWORD*)& byte_5D4594[3821640] + sub_419A70(*(float*)& v16);
        sub_5232F0(v9, (int)v19);
        result = 0;
        break;
    case 0x93u:
        v12 = sub_419AD0(*(float*)& v0);
        sub_5231B0(&v17, v12);
        result = 0;
        break;
    case 0x97u:
        v11 = sub_419A70(*(float*)& v0);
        sub_4D9110(&v17, v11);
        result = 0;
        break;
    case 0x98u:
        sub_523790((int4*)v19, 30);
        result = 0;
        break;
    case 0xA2u:
        v19[0] = *(_DWORD*)& byte_5D4594[3821636] + sub_419A70(v14);
        v19[1] = *(_DWORD*)& byte_5D4594[3821640] + sub_419A70(v15);
        v19[2] = *(_DWORD*)& byte_5D4594[3821636] + sub_419A70(*(float*)& v0);
        v19[3] = *(_DWORD*)& byte_5D4594[3821640] + sub_419A70(*(float*)& v16);
        sub_523270(v9, (__int16*)v19, 100);
        result = 0;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (00514490) --------------------------------------------------------
int sub_514490()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    int v3; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_511B60(v0);
    sub_4EC290(v2, v3);
    return 0;
}

//----- (005144C0) --------------------------------------------------------
int sub_5144C0()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    int v3; // eax
    int* i; // esi
    int v5; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_57C0A0(v0);
    if (v3)
    {
        for (i = *(int**)(v3 + 84); i; i = (int*)i[2])
        {
            v5 = sub_4ED020(*i);
            if (v5)
                sub_4EC290(v2, v5);
        }
    }
    return 0;
}

//----- (00514510) --------------------------------------------------------
int sub_514510()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int* v4; // esi
    int i; // edi
    int v6; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_57C0A0(v1);
    if (v2)
    {
        v3 = sub_511B60(v0);
        v4 = *(int**)(v2 + 84);
        for (i = v3; v4; v4 = (int*)v4[2])
        {
            v6 = sub_4ED020(*v4);
            if (v6)
                sub_4EC290(v6, i);
        }
    }
    return 0;
}

//----- (00514570) --------------------------------------------------------
int sub_514570()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // ebp
    int* i; // edi
    int v6; // ebx
    int* j; // esi
    int v8; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_57C0A0(v1);
    v3 = sub_57C0A0(v0);
    v4 = v3;
    if (v2)
    {
        if (v3)
        {
            for (i = *(int**)(v2 + 84); i; i = (int*)i[2])
            {
                v6 = sub_4ED020(*i);
                if (v6)
                {
                    for (j = *(int**)(v4 + 84); j; j = (int*)j[2])
                    {
                        v8 = sub_4ED020(*j);
                        if (v8)
                            sub_4EC290(v6, v8);
                    }
                }
            }
        }
    }
    return 0;
}

//----- (005145F0) --------------------------------------------------------
int sub_5145F0()
{
    int v0; // esi
    int v1; // edi
    int v2; // esi
    int v3; // eax
    int v4; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v0);
    v3 = sub_511B60(v1);
    v4 = sub_4EC4F0(v3, v2);
    sub_507230(v4);
    return 0;
}

//----- (00514630) --------------------------------------------------------
int sub_514630()
{
    int v0; // esi
    int v1; // edi
    int result; // eax
    int v3; // esi
    int v4; // eax
    int* v5; // esi
    int v6; // edi
    int v7; // ebx
    int v8; // eax

    v0 = script_pop();
    v1 = script_pop();
    result = sub_57C0A0(v0);
    v3 = result;
    if (result)
    {
        v4 = sub_511B60(v1);
        v5 = *(int**)(v3 + 84);
        v6 = v4;
        v7 = 1;
        if (v5)
        {
            while (1)
            {
                v8 = sub_4ED020(*v5);
                if (v8)
                {
                    if (!sub_4EC4F0(v6, v8))
                        break;
                }
                v5 = (int*)v5[2];
                if (!v5)
                {
                    sub_507230(1);
                    return 0;
                }
            }
            v7 = 0;
        }
        sub_507230(v7);
        result = 0;
    }
    return result;
}

//----- (005146B0) --------------------------------------------------------
int sub_5146B0()
{
    int v0; // edi
    int v1; // eax
    int result; // eax
    int v3; // esi
    int v4; // eax
    int* v5; // esi
    int v6; // edi
    int v7; // ebx
    int v8; // eax

    v0 = script_pop();
    v1 = script_pop();
    result = sub_57C0A0(v1);
    v3 = result;
    if (result)
    {
        v4 = sub_511B60(v0);
        v5 = *(int**)(v3 + 84);
        v6 = v4;
        v7 = 1;
        if (v5)
        {
            while (1)
            {
                v8 = sub_4ED020(*v5);
                if (v8)
                {
                    if (!sub_4EC4F0(v8, v6))
                        break;
                }
                v5 = (int*)v5[2];
                if (!v5)
                {
                    sub_507230(1);
                    return 0;
                }
            }
            v7 = 0;
        }
        sub_507230(v7);
        result = 0;
    }
    return result;
}

//----- (00514730) --------------------------------------------------------
int sub_514730()
{
    int v0; // esi
    int v1; // edi
    int v2; // esi
    int v3; // eax
    int* v4; // ebx
    int i; // ebp
    int v6; // edi
    int* v7; // esi
    int v8; // eax
    int v10; // [esp+8h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_57C0A0(v0);
    v3 = sub_57C0A0(v1);
    v10 = v3;
    if (!v2 || !v3)
        return 0;
    v4 = *(int**)(v2 + 84);
    for (i = 1; v4; v4 = (int*)v4[2])
    {
        if (!i)
            break;
        v6 = sub_4ED020(*v4);
        if (v6)
        {
            v7 = *(int**)(v10 + 84);
            if (v7)
            {
                while (1)
                {
                    v8 = sub_4ED020(*v7);
                    if (v8)
                    {
                        if (!sub_4EC4F0(v8, v6))
                            break;
                    }
                    v7 = (int*)v7[2];
                    if (!v7)
                        goto LABEL_12;
                }
                i = 0;
            }
        }
    LABEL_12:
        ;
    }
    sub_507230(i);
    return 0;
}

//----- (005147E0) --------------------------------------------------------
int sub_5147E0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    sub_4EC300(v1);
    return 0;
}

//----- (00514800) --------------------------------------------------------
int sub_514800()
{
    int* v0; // eax
    char v2[76]; // [esp+4h] [ebp-4Ch]

    strcpy(v2, *(const char**)& byte_5D4594[4 * script_pop() + 3831212]);
    strcat(v2, (const char*)& byte_5D4594[3821644]);
    v0 = (int*)sub_579E30(v2);
    if (v0)
        sub_507230(*v0);
    else
        sub_507230(0);
    return 0;
}

//----- (005148A0) --------------------------------------------------------
int sub_5148A0()
{
    int v0; // eax
    char v2[76]; // [esp+4h] [ebp-4Ch]

    strcpy(v2, *(const char**)& byte_5D4594[4 * script_pop() + 3831212]);
    strcat(v2, (const char*)& byte_5D4594[3821644]);
    v0 = sub_57C280(v2, 1);
    if (v0)
        sub_507230(*(_DWORD*)(v0 + 4));
    else
        sub_507230(0);
    return 0;
}

//----- (00514940) --------------------------------------------------------
int sub_514940()
{
    int v0; // eax
    char v2[76]; // [esp+4h] [ebp-4Ch]

    strcpy(v2, *(const char**)& byte_5D4594[4 * script_pop() + 3831212]);
    strcat(v2, (const char*)& byte_5D4594[3821644]);
    v0 = sub_57C280(v2, 0);
    if (v0)
        sub_507230(*(_DWORD*)(v0 + 4));
    else
        sub_507230(0);
    return 0;
}

//----- (005149E0) --------------------------------------------------------
int sub_5149E0()
{
    int v0; // eax
    char v2[76];

    strcpy(v2, *(const char**)& byte_5D4594[4 * script_pop() + 3831212]);
    strcat(v2, (const char*)& byte_5D4594[3821644]);
    v0 = sub_57C280(v2, 2);
    if (v0)
        sub_507230(*(_DWORD*)(v0 + 4));
    else
        sub_507230(0);
    return 0;
}

//----- (00514A80) --------------------------------------------------------
int sub_514A80()
{
    __int16 v0; // di
    int v1; // ebx
    int v2; // eax
    int v3; // esi
    char* v4; // edx
    wchar_t* v5; // eax
    wchar_t v7; // [esp-4h] [ebp-14h]
    int v8; // [esp+Ch] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_511B60(v2);
    if (v3)
    {
        v4 = *(char**)& byte_5D4594[4 * v1 + 3831212];
        v7 = v0 * *(_WORD*)& byte_5D4594[2649704];
        v8 = 0;
        v5 = loadString_sub_40F1D0(v4, &v8, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3629);
        sub_528AC0(v3, v5, v7);
        if (sub_40A5C0(2048))
            sub_44D900(v8, 100);
    }
    return 0;
}

//----- (00514B10) --------------------------------------------------------
int sub_514B10()
{
    wchar_t v0; // di
    int v1; // ebx
    int v2; // eax
    int v3; // esi
    char* v4; // ecx
    wchar_t* v5; // eax
    int v7; // [esp+Ch] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_511B60(v2);
    if (v3)
    {
        v4 = *(char**)& byte_5D4594[4 * v1 + 3831212];
        v7 = 0;
        v5 = loadString_sub_40F1D0(v4, &v7, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3670);
        sub_528AC0(v3, v5, v0);
        if (v7)
        {
            if (sub_40A5C0(2048))
                sub_44D900(v7, 100);
        }
    }
    return 0;
}

//----- (00514BA0) --------------------------------------------------------
int sub_514BA0()
{
    script_pop();
    script_pop();
    return 0;
}

//----- (00514BB0) --------------------------------------------------------
int sub_514BB0()
{
    int v0; // eax
    _DWORD* v1; // eax

    v0 = script_pop();
    v1 = (_DWORD*)sub_511B60(v0);
    if (v1)
        sub_528D00(v1);
    return 0;
}

//----- (00514BD0) --------------------------------------------------------
int sub_514BD0()
{
    sub_528D60();
    return 0;
}

//----- (00514BE0) --------------------------------------------------------
int sub_514BE0()
{
    int v0; // esi
    int v1; // eax

    v0 = script_pop();
    v1 = script_pop();
    sub_500540(*(char**)& byte_5D4594[4 * v0 + 3831212], v1);
    return 0;
}

//----- (00514C10) --------------------------------------------------------
int sub_514C10()
{
    int v0; // esi
    int v1; // eax

    v0 = script_pop();
    v1 = script_pop();
    sub_5006B0(*(char**)& byte_5D4594[4 * v0 + 3831212], v1);
    return 0;
}

//----- (00514C40) --------------------------------------------------------
int sub_514C40()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_500750(*(char**)& byte_5D4594[4 * v0 + 3831212]);
    sub_507230(v1);
    return 0;
}

//----- (00514C60) --------------------------------------------------------
int sub_514C60()
{
    int v0; // eax
    int v2; // [esp+0h] [ebp-4h]

    v0 = script_pop();
    *(float*)& v2 = sub_500770((char*) * (_DWORD*)& byte_5D4594[4 * v0 + 3831212]);
    sub_507230(v2);
    return 0;
}

//----- (00514C90) --------------------------------------------------------
int sub_514C90()
{
    int v0; // eax

    v0 = script_pop();
    sub_5007E0(*(char**)& byte_5D4594[4 * v0 + 3831212]);
    return 0;
}

//----- (00514CB0) --------------------------------------------------------
int sub_514CB0()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = script_pop();
    v1 = 0;
    v2 = sub_511B60(v0);
    if (v2
        && *(_DWORD*)& byte_5D4594[3821968]
        && *(_DWORD*)(v2 + 44) == *(_DWORD*)(*(_DWORD*)& byte_5D4594[3821968] + 44))
    {
        v1 = 1;
    }
    sub_507230(v1);
    return 0;
}

//----- (00514CF0) --------------------------------------------------------
int sub_514CF0()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = script_pop();
    v1 = 0;
    v2 = sub_511B60(v0);
    if (v2
        && *(_DWORD*)& byte_5D4594[3821964]
        && *(_DWORD*)(v2 + 44) == *(_DWORD*)(*(_DWORD*)& byte_5D4594[3821964] + 44))
    {
        v1 = 1;
    }
    sub_507230(v1);
    return 0;
}

//----- (00514D30) --------------------------------------------------------
int sub_514D30()
{
    if (*(_DWORD*)& byte_5D4594[3821968])
        sub_507230(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3821968] + 44));
    else
        sub_507230(*(int*)& byte_5D4594[3821968]);
    return 0;
}

//----- (00514D60) --------------------------------------------------------
int sub_514D60()
{
    if (*(_DWORD*)& byte_5D4594[3821964])
        sub_507230(*(_DWORD*)(*(_DWORD*)& byte_5D4594[3821964] + 44));
    else
        sub_507230(*(int*)& byte_5D4594[3821964]);
    return 0;
}

//----- (00514D90) --------------------------------------------------------
int sub_514D90()
{
    int v0; // ebx
    int v1; // ebp
    int v2; // esi
    int v3; // edi
    int v4; // eax
    char v6; // [esp+10h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = script_pop();
    v6 = sub_548F70(*(const char**)& byte_5D4594[4 * v2 + 3831212]);
    v4 = sub_511B60(v3);
    if (v4)
        sub_548C80(v4, v6, v1, v0);
    return 0;
}

//----- (00514DF0) --------------------------------------------------------
int sub_514DF0()
{
    int v0; // eax
    int v1; // eax
    int v2; // ecx

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v2 = *(_DWORD*)(v1 + 748);
        if (*(_BYTE*)(v1 + 8) & 2)
        {
            *(_DWORD*)(v2 + 2096) = -1;
            *(_DWORD*)(v2 + 2100) = -1;
            sub_4E4780(v1, 16);
        }
    }
    return 0;
}

//----- (00514E30) --------------------------------------------------------
int sub_514E30()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2 && *(_BYTE*)(v2 + 8) & 2)
        strcpy((char*)(*(_DWORD*)(v2 + 748) + 2106), *(const char**)& byte_5D4594[4 * v0 + 3831212]);
    return 0;
}

//----- (00514E90) --------------------------------------------------------
int sub_514E90()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax
    const char* v4; // [esp-4h] [ebp-8h]

    v0 = script_pop();
    v1 = script_pop();
    v4 = *(const char**)& byte_5D4594[4 * v0 + 3831212];
    v2 = sub_40AF50(*(void**)& byte_5D4594[4 * v1 + 3831212]);
    sub_548DE0(*(int*)& byte_5D4594[3821964], *(int*)& byte_5D4594[3821968], v2, v4);
    return 0;
}

//----- (00514ED0) --------------------------------------------------------
int sub_514ED0()
{
    int v0; // esi
    int v1; // edi
    int v2; // esi
    int v3; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v0);
    v3 = sub_511B60(v1);
    if (v2 && v3)
        sub_548CD0(v2, v3);
    return 0;
}

//----- (00514F10) --------------------------------------------------------
int sub_514F10()
{
    int v0; // ebp
    int v1; // esi
    int v2; // eax
    int v3; // ebx
    int v4; // eax
    int v5; // edi
    int v6; // eax
    int v7; // esi
    float2 v9; // [esp+10h] [ebp-14h]
    int v10[3]; // [esp+18h] [ebp-Ch]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_4243F0(*(const char**)& byte_5D4594[4 * v2 + 3831212]);
    if (v3)
    {
        v4 = sub_511B60(v1);
        v5 = v4;
        if (v4)
        {
            if (!(*(_DWORD*)(v4 + 16) & 0x8020))
            {
                v6 = sub_511B60(v0);
                v7 = v6;
                if (v6)
                {
                    v9.field_0 = *(float*)(v6 + 56) - *(float*)(v5 + 56);
                    v9.field_4 = *(float*)(v6 + 60) - *(float*)(v5 + 60);
                    *(_WORD*)(v5 + 124) = sub_509ED0(&v9);
                    v10[0] = v7;
                    v10[1] = *(_DWORD*)(v7 + 56);
                    v10[2] = *(_DWORD*)(v7 + 60);
                    sub_4FDD20(v3, (_DWORD*)v5, v10);
                }
            }
        }
    }
    return 0;
}

//----- (00514FC0) --------------------------------------------------------
int sub_514FC0()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    int v3; // eax
    _DWORD* v4; // esi
    float v6; // [esp+8h] [ebp-1Ch]
    float v7; // [esp+Ch] [ebp-18h]
    float2 v8; // [esp+10h] [ebp-14h]
    float v9[3]; // [esp+18h] [ebp-Ch]

    v7 = COERCE_FLOAT(script_pop());
    v6 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_4243F0(*(const char**)& byte_5D4594[4 * v1 + 3831212]);
    if (v2)
    {
        v3 = sub_511B60(v0);
        v4 = (_DWORD*)v3;
        if (v3)
        {
            v8.field_0 = v6 - *(float*)(v3 + 56);
            v8.field_4 = v7 - *(float*)(v3 + 60);
            *(_WORD*)(v3 + 124) = sub_509ED0(&v8);
            v9[0] = 0.0;
            v9[1] = v6;
            v9[2] = v7;
            sub_4FDD20(v2, v4, v9);
        }
    }
    return 0;
}

//----- (00515060) --------------------------------------------------------
int sub_515060()
{
    int v0; // esi
    int v1; // eax
    int v2; // edi
    int v3; // esi
    float2 v5; // [esp+8h] [ebp-1Ch]
    float2 v6; // [esp+10h] [ebp-14h]
    int v7[3]; // [esp+18h] [ebp-Ch]

    v0 = script_pop();
    LODWORD(v5.field_4) = script_pop();
    LODWORD(v5.field_0) = script_pop();
    v1 = script_pop();
    v2 = sub_4243F0(*(const char**)& byte_5D4594[4 * v1 + 3831212]);
    if (v2)
    {
        v3 = sub_511B60(v0);
        if (v3)
        {
            v6 = v5;
            sub_4E7010(*(int*)& byte_5D4594[1569664], &v6);
            v6.field_0 = *(float*)(v3 + 56) - v5.field_0;
            v6.field_4 = *(float*)(v3 + 60) - v5.field_4;
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1569664] + 124) = sub_509ED0(&v6);
            v7[0] = v3;
            v7[1] = *(_DWORD*)(v3 + 56);
            v7[2] = *(_DWORD*)(v3 + 60);
            sub_4FDD20(v2, *(_DWORD * *)& byte_5D4594[1569664], &v7);
        }
    }
    return 0;
}

//----- (00515130) --------------------------------------------------------
int sub_515130()
{
    int v0; // eax
    int v1; // esi
    float2 v3; // [esp+4h] [ebp-24h]
    float v4; // [esp+Ch] [ebp-1Ch]
    float v5; // [esp+10h] [ebp-18h]
    float2 v6; // [esp+14h] [ebp-14h]
    float v7[3]; // [esp+1Ch] [ebp-Ch]

    v5 = COERCE_FLOAT(script_pop());
    v4 = COERCE_FLOAT(script_pop());
    LODWORD(v3.field_4) = script_pop();
    LODWORD(v3.field_0) = script_pop();
    v0 = script_pop();
    v1 = sub_4243F0(*(const char**)& byte_5D4594[4 * v0 + 3831212]);
    if (v1)
    {
        v6 = v3;
        sub_4E7010(*(int*)& byte_5D4594[1569664], &v6);
        v6.field_0 = v4 - v3.field_0;
        v6.field_4 = v5 - v3.field_4;
        *(_WORD*)(*(_DWORD*)& byte_5D4594[1569664] + 124) = sub_509ED0(&v6);
        v7[1] = v4;
        v7[0] = 0.0;
        v7[2] = v5;
        sub_4FDD20(v1, *(_DWORD * *)& byte_5D4594[1569664], &v7);
    }
    return 0;
}

//----- (00515200) --------------------------------------------------------
int sub_515200()
{
    *(_DWORD*)& byte_5D4594[2650672] = 0;
    sub_44DB30(25, 0, 0);
    return 0;
}

//----- (00515220) --------------------------------------------------------
int sub_515220()
{
    sub_44DAB0(25, 0, sub_44E000);
    return 0;
}

//----- (00515240) --------------------------------------------------------
int sub_515240()
{
    BOOL v0; // esi
    int v1; // esi
    int v2; // edi
    int v3; // esi
    int v4; // edi
    int v5; // eax
    int v6; // eax
    int i; // eax
    int v9; // ecx

    if (!*(_DWORD*)& byte_5D4594[2386872])
        * (_DWORD*)& byte_5D4594[2386872] = sub_4E3AA0((CHAR*)& byte_587000[247228]);
    if (script_pop() != 1)
    {
        if (sub_44DCA0(16, 30))
            sub_477530(0);
        for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
        {
            if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[2386872])
            {
                v9 = *(_DWORD*)(i + 16);
                if (v9 & 0x40)
                    * (_DWORD*)(i + 16) = v9 & 0xFFFFFFBF;
            }
        }
        return 0;
    }
    v0 = sub_44DD00();
    if (sub_44DC40(16, 10))
        sub_477530(1);
    if (v0)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[2386876])
    {
        *(_DWORD*)& byte_5D4594[2386876] = sub_4E3AA0((CHAR*)& byte_587000[247244]);
        *(_DWORD*)& byte_5D4594[2386880] = sub_4E3AA0((CHAR*)& byte_587000[247256]);
        *(_DWORD*)& byte_5D4594[2386884] = sub_4E3AA0((CHAR*)& byte_587000[247272]);
        *(_DWORD*)& byte_5D4594[2386888] = sub_4E3AA0((CHAR*)& byte_587000[247280]);
        *(_DWORD*)& byte_5D4594[2386892] = sub_4E3AA0((CHAR*)& byte_587000[247292]);
        *(_DWORD*)& byte_5D4594[2386896] = sub_4E3AA0((CHAR*)& byte_587000[247304]);
        *(_DWORD*)& byte_5D4594[2386900] = sub_4E3AA0((CHAR*)& byte_587000[247316]);
    }
    v1 = sub_4DA840();
    if (v1)
    {
        do
        {
            v2 = sub_4DA850(v1);
            if (*(unsigned __int16*)(v1 + 4) != *(_DWORD*)& byte_5D4594[2386900])
                sub_4E5CC0(v1);
            v1 = v2;
        } while (v2);
    }
    v3 = sub_4DA790();
    if (!v3)
        return 0;
    do
    {
        v4 = sub_4DA7A0(v3);
        if (*(_DWORD*)(v3 + 508)
            && ((v5 = *(unsigned __int16*)(v3 + 4), (unsigned __int16)v5 == *(_DWORD*)& byte_5D4594[2386876])
                || v5 == *(_DWORD*)& byte_5D4594[2386880]
                || v5 == *(_DWORD*)& byte_5D4594[2386884]
                || v5 == *(_DWORD*)& byte_5D4594[2386888]
                || v5 == *(_DWORD*)& byte_5D4594[2386892]
                || v5 == *(_DWORD*)& byte_5D4594[2386896]))
        {
            sub_4E5CC0(v3);
        }
        else
        {
            if (*(unsigned __int16*)(v3 + 4) == *(_DWORD*)& byte_5D4594[2386872])
            {
                v6 = *(_DWORD*)(v3 + 16);
                if (!(v6 & 0x40))
                {
                    LOBYTE(v6) = v6 | 0x40;
                    *(_DWORD*)(v3 + 16) = v6;
                }
            }
            sub_4FEB10(132, v3);
            sub_4FEB10(56, v3);
            sub_4FEB10(24, v3);
            sub_4FEB10(43, v3);
            sub_4FEB10(22, v3);
            sub_4FEB10(31, v3);
            sub_4FEB10(35, v3);
            sub_4FEB10(8, v3);
            sub_4FEB10(9, v3);
            sub_4FEB10(4, v3);
            sub_4FEB10(115, v3);
            sub_4FEB10(21, v3);
            sub_4FEB10(59, v3);
            sub_4FEB10(75, v3);
        }
        v3 = v4;
    } while (v4);
    return 0;
}

//----- (005154A0) --------------------------------------------------------
int sub_5154A0()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax
    int v3; // ecx

    v0 = -1;
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = *(_DWORD*)(v2 + 8);
        if (v3 & 0x4000)
            v0 = *(unsigned __int8*)(*(_DWORD*)(v2 + 748) + 12);
    }
    sub_507230(v0);
    return 0;
}

//----- (005154E0) --------------------------------------------------------
int sub_5154E0()
{
    __int16 v0; // bx
    int v1; // edi
    int v2; // eax
    int v3; // esi

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    if (v2)
    {
        v3 = sub_511B60(v2);
        if (v3)
        {
            sub_427500(v3, *(char**)& byte_5D4594[4 * v1 + 3831212], v0);
            if (v0 & 0xB)
            {
                sub_501960(903, v3, 0, 0);
                return 0;
            }
        }
    }
    else
    {
        sub_427550(*(char**)& byte_5D4594[4 * v1 + 3831212], v0);
    }
    return 0;
}

//----- (00515550) --------------------------------------------------------
int sub_515550()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    if (v1)
    {
        v2 = sub_511B60(v1);
        if (v2)
        {
            sub_427630(v2, *(const char**)& byte_5D4594[4 * v0 + 3831212]);
            return 0;
        }
    }
    else
    {
        sub_427680(*(const char**)& byte_5D4594[4 * v0 + 3831212]);
    }
    return 0;
}

//----- (005155A0) --------------------------------------------------------
int sub_5155A0()
{
    __int16 v0; // si
    int v1; // edi
    int v2; // eax
    int v3; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    if (v2)
    {
        v3 = sub_511B60(v2);
        if (v3)
        {
            sub_427720(v3, *(const char**)& byte_5D4594[4 * v1 + 3831212], v0);
            return 0;
        }
    }
    else
    {
        sub_427770(*(const char**)& byte_5D4594[4 * v1 + 3831212], v0);
    }
    return 0;
}

//----- (00515600) --------------------------------------------------------
int sub_515600()
{
    int v0; // eax
    int v1; // eax
    int v3; // [esp+0h] [ebp-28h]
    int v4; // [esp+4h] [ebp-24h]
    int v5; // [esp+8h] [ebp-20h]
    int v6; // [esp+Ch] [ebp-1Ch]
    int v7; // [esp+10h] [ebp-18h]
    int v8[5]; // [esp+14h] [ebp-14h]

    v7 = script_pop();
    v6 = script_pop();
    v5 = script_pop();
    v4 = script_pop();
    v3 = script_pop();
    v0 = script_pop();
    v8[0] = v3;
    v8[1] = v4;
    v8[2] = v5;
    v8[3] = v6;
    v8[4] = v7;
    v1 = sub_511B60(v0);
    if (v1)
        sub_515680(v1, v8);
    return 0;
}

//----- (00515680) --------------------------------------------------------
void __cdecl sub_515680(int a1, int a2)
{
    int v2; // ebx
    int v3; // eax
    int* v4; // edi
    float2 v5; // [esp+8h] [ebp-8h]

    v2 = *(_DWORD*)(a1 + 748);
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v3 = *(_DWORD*)(a1 + 16);
            if ((v3 & 0x8000) == 0)
            {
                v5.field_0 = *(float*)(a2 + 8) - *(float*)a2;
                v5.field_4 = *(float*)(a2 + 12) - *(float*)(a2 + 4);
                sub_50A3A0(a1);
                v4 = sub_50A260(a1, 4);
                if (v4)
                {
                    v4[1] = *(_DWORD*)a2;
                    v4[2] = *(_DWORD*)(a2 + 4);
                    v4[3] = sub_509ED0(&v5);
                }
                *(_DWORD*)(v2 + 1312) = *(_DWORD*)(a2 + 16);
            }
        }
    }
}

//----- (00515700) --------------------------------------------------------
int sub_515700()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    int v3; // [esp+0h] [ebp-28h]
    int v4; // [esp+4h] [ebp-24h]
    int v5; // [esp+8h] [ebp-20h]
    int v6; // [esp+Ch] [ebp-1Ch]
    int v7; // [esp+10h] [ebp-18h]
    int v8[5]; // [esp+14h] [ebp-14h]

    v7 = script_pop();
    v6 = script_pop();
    v5 = script_pop();
    v4 = script_pop();
    v3 = script_pop();
    v0 = script_pop();
    v8[1] = v4;
    v8[3] = v6;
    v8[0] = v3;
    v8[2] = v5;
    v8[4] = v7;
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, sub_515680, (int)v8);
    return 0;
}

//----- (00515780) --------------------------------------------------------
int sub_515780()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_5157A0(v1);
    return 0;
}

//----- (005157A0) --------------------------------------------------------
void __cdecl sub_5157A0(int a1)
{
    int result; // eax

    if (a1 && *(_BYTE*)(a1 + 8) & 2)
    {
        result = *(int*)(a1 + 16);
        if (SBYTE1(result) >= 0)
        {
            sub_50A3A0(a1);
            sub_50A260(a1, 5);
        }
    }
}

//----- (005157D0) --------------------------------------------------------
int sub_5157D0()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_5157A0, 0);
    return 0;
}

//----- (00515800) --------------------------------------------------------
int sub_515800()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_515820(v1);
    return 0;
}

//----- (00515820) --------------------------------------------------------
void __cdecl sub_515820(int a1)
{
    int result; // eax

    if (a1 && *(_BYTE*)(a1 + 8) & 2)
    {
        result = *(int*)(a1 + 16);
        if (SBYTE1(result) >= 0)
        {
            sub_50A3A0(a1);
            sub_50A260(a1, 0);
        }
    }
}

//----- (00515850) --------------------------------------------------------
int sub_515850()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_515820, 0);
    return 0;
}

//----- (00515880) --------------------------------------------------------
int sub_515880()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = sub_511B60(v0);
        if (v3)
            sub_5158C0(v2, v3);
    }
    return 0;
}

//----- (005158C0) --------------------------------------------------------
void __cdecl sub_5158C0(int a1, int a2)
{
    int v2; // eax
    int* v3; // eax

    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 2)
            {
                if (a1 != a2)
                {
                    v2 = *(_DWORD*)(a1 + 16);
                    if ((v2 & 0x8000) == 0)
                    {
                        sub_50A3A0(a1);
                        v3 = sub_50A260(a1, 3);
                        if (v3)
                        {
                            v3[1] = *(_DWORD*)(a2 + 56);
                            v3[2] = *(_DWORD*)(a2 + 60);
                            v3[3] = a2;
                        }
                    }
                }
            }
        }
    }
}

//----- (00515910) --------------------------------------------------------
int sub_515910()
{
    int v0; // esi
    int v1; // edi
    int v2; // eax
    unsigned __int8* v3; // eax
    int v5; // [esp-4h] [ebp-Ch]

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v0);
    if (v2)
    {
        v5 = v2;
        v3 = (unsigned __int8*)sub_57C0A0(v1);
        sub_502670(v3, 0, sub_5158C0, v5);
    }
    return 0;
}

//----- (00515950) --------------------------------------------------------
int sub_515950()
{
    int v0; // eax
    int v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_515980(v1, &v3);
    return 0;
}

//----- (00515980) --------------------------------------------------------
int __cdecl sub_515980(int a1, _DWORD* a2)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 748);
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            *(_DWORD*)(result + 1308) = *a2;
            *(_DWORD*)(result + 1304) = *a2;
        }
    }
    return result;
}

//----- (005159B0) --------------------------------------------------------
int sub_5159B0()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_515980, (int)& v3);
    return 0;
}

//----- (005159E0) --------------------------------------------------------
int sub_5159E0()
{
    int v0; // eax
    int v1; // eax
    float v3; // [esp+0h] [ebp-10h]
    float v4; // [esp+4h] [ebp-Ch]
    float2 v5;

    v4 = COERCE_FLOAT(script_pop());
    v3 = COERCE_FLOAT(script_pop());
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v5.field_0 = v3;
        v5.field_4 = v4;
        sub_515A30(v1, (float2*)& v5);
    }
    return 0;
}

//----- (00515A30) --------------------------------------------------------
void __cdecl sub_515A30(int a1, float2* a2)
{
    int v2; // eax
    int* v3; // eax
    float* v4; // edi
    float* v5; // eax

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v2 = *(_DWORD*)(a1 + 16);
            if ((v2 & 0x8000) == 0)
            {
                if (sub_534220(a1))
                {
                    sub_50A3A0(a1);
                    v3 = sub_50A260(a1, 32);
                    if (v3)
                        v3[1] = 16;
                    sub_50A260(a1, 16);
                    v4 = (float*)sub_50A260(a1, 51);
                    if (v4)
                    {
                        v4[1] = sub_534470(a1) + *(float*)(a1 + 176);
                        v4[3] = a2->field_0;
                        v4[4] = a2->field_4;
                    }
                    v5 = (float*)sub_50A260(a1, 7);
                    if (v5)
                    {
                        v5[1] = a2->field_0;
                        v5[2] = a2->field_4;
                        v5[3] = 0;
                    }
                }
            }
        }
    }
}

//----- (00515AE0) --------------------------------------------------------
int sub_515AE0()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    float2 v3; // [esp+0h] [ebp-10h]
    float2 v4; // [esp+8h] [ebp-8h]

    LODWORD(v3.field_4) = script_pop();
    LODWORD(v3.field_0) = script_pop();
    v0 = script_pop();
    v4 = v3;
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_515A30, (int)& v4);
    return 0;
}

//----- (00515B30) --------------------------------------------------------
int sub_515B30()
{
    int v0; // eax
    int v1; // eax
    int v3[2]; // [esp+0h] [ebp-10h]
    int v4[2]; // [esp+8h] [ebp-8h]

    v3[1] = script_pop();
    v3[0] = script_pop();
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        *(_QWORD*)v4 = *(_QWORD*)v3;
        sub_515B80(v1, v4);
    }
    return 0;
}

//----- (00515B80) --------------------------------------------------------
void __cdecl sub_515B80(int a1, _DWORD* a2)
{
    int v2; // eax
    int* v3; // eax
    int* v4; // eax

    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 2)
            {
                v2 = *(_DWORD*)(a1 + 16);
                if ((v2 & 0x8000) == 0)
                {
                    if (sub_534280(a1))
                    {
                        sub_50A3A0(a1);
                        v3 = sub_50A260(a1, 32);
                        if (v3)
                            v3[1] = 17;
                        v4 = sub_50A260(a1, 17);
                        if (v4)
                        {
                            v4[1] = *a2;
                            v4[2] = a2[1];
                            v4[3] = 0;
                        }
                    }
                }
            }
        }
    }
}

//----- (00515BF0) --------------------------------------------------------
int sub_515BF0()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    int v3[2]; // [esp+0h] [ebp-10h]
    int v4[2]; // [esp+8h] [ebp-8h]

    v3[1] = script_pop();
    v3[0] = script_pop();
    v0 = script_pop();
    *(_QWORD*)v4 = *(_QWORD*)v3;
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_515B80, (int)v4);
    return 0;
}

//----- (00515C40) --------------------------------------------------------
int __fastcall sub_515C40(int a1)
{
    char v1; // bl
    int v2; // eax
    int v3; // eax
    char v5; // [esp+1h] [ebp-1h]

    v5 = HIBYTE(a1);
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_511B60(v2);
    if (v3)
    {
        v5 = v1;
        sub_515C80(v3, &v5);
    }
    return 0;
}

//----- (00515C80) --------------------------------------------------------
int __cdecl sub_515C80(int a1, _BYTE* a2)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            result = *(_DWORD*)(a1 + 748);
            *(_BYTE*)(result + 1332) = *a2;
        }
    }
    return result;
}

//----- (00515CB0) --------------------------------------------------------
int sub_515CB0()
{
    char v0; // bl
    int v1; // eax
    unsigned __int8* v2; // eax
    char v4; // [esp+1h] [ebp-1h]

    v0 = script_pop();
    v1 = script_pop();
    v4 = v0;
    v2 = (unsigned __int8*)sub_57C0A0(v1);
    sub_502670(v2, 0, (void(__cdecl*)(int, int))sub_515C80, (int)& v4);
    return 0;
}

//----- (00515CF0) --------------------------------------------------------
int sub_515CF0()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = sub_511B60(v0);
        sub_515D30(v2, v3);
    }
    return 0;
}

//----- (00515D30) --------------------------------------------------------
void __cdecl sub_515D30(int a1, int a2)
{
    int v2; // ebx
    int v3; // eax
    int* v4; // eax
    int* v5; // eax

    v2 = *(_DWORD*)(a1 + 748);
    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 2)
            {
                if (a1 != a2)
                {
                    v3 = *(_DWORD*)(a1 + 16);
                    if ((v3 & 0x8000) == 0)
                    {
                        sub_50A3A0(a1);
                        *(_DWORD*)(v2 + 1216) = a2;
                        sub_5281D0();
                        v4 = sub_50A260(a1, 32);
                        if (v4)
                            v4[1] = 15;
                        v5 = sub_50A260(a1, 15);
                        if (v5)
                        {
                            v5[1] = *(_DWORD*)(a2 + 56);
                            v5[2] = *(_DWORD*)(a2 + 60);
                            v5[3] = *(_DWORD*)& byte_5D4594[2598000];
                        }
                    }
                }
            }
        }
    }
}

//----- (00515DB0) --------------------------------------------------------
int sub_515DB0()
{
    int v0; // esi
    int v1; // edi
    unsigned __int8* v2; // eax
    int v4; // [esp-4h] [ebp-Ch]

    v0 = script_pop();
    v1 = script_pop();
    v4 = sub_511B60(v0);
    v2 = (unsigned __int8*)sub_57C0A0(v1);
    sub_502670(v2, 0, sub_515D30, v4);
    return 0;
}

//----- (00515DF0) --------------------------------------------------------
int sub_515DF0()
{
    int v0; // eax
    int v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_515E20(v1, &v3);
    return 0;
}

//----- (00515E20) --------------------------------------------------------
int __cdecl sub_515E20(int a1, _DWORD* a2)
{
    int result; // eax

    result = a1;
    if (a1 && a2)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            result = *(_DWORD*)(a1 + 748);
            *(_DWORD*)(result + 1336) = *a2;
        }
    }
    return result;
}

//----- (00515E50) --------------------------------------------------------
int sub_515E50()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_515E20, (int)& v3);
    return 0;
}

//----- (00515E80) --------------------------------------------------------
int sub_515E80()
{
    int v0; // eax
    int v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_515EB0(v1, &v3);
    return 0;
}

//----- (00515EB0) --------------------------------------------------------
int __cdecl sub_515EB0(int a1, _DWORD* a2)
{
    int result; // eax

    result = a1;
    if (a1 && a2)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            result = *(_DWORD*)(a1 + 748);
            *(_DWORD*)(result + 1344) = *a2;
        }
    }
    return result;
}

//----- (00515EE0) --------------------------------------------------------
int sub_515EE0()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_515EB0, (int)& v3);
    return 0;
}

//----- (00515F10) --------------------------------------------------------
int sub_515F10()
{
    int v0; // ebx
    int v1; // esi
    int v2; // edi
    int v3; // eax
    int v5[2]; // [esp+Ch] [ebp-8h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v5[0] = sub_511B60(v1);
    if (v5[0])
    {
        v3 = sub_511B60(v2);
        if (v3)
        {
            v5[1] = v0;
            sub_515F70(v3, v5);
        }
    }
    return 0;
}

//----- (00515F70) --------------------------------------------------------
void __cdecl sub_515F70(int a1, _DWORD* a2)
{
    int v2; // eax
    int* v3; // eax
    int* v4; // eax
    int* v5; // eax
    int v6; // edx
    int v7; // edx

    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
        {
            v2 = *(_DWORD*)(a1 + 16);
            if ((v2 & 0x8000) == 0 && !sub_50A0D0(a1, 24))
            {
                v3 = sub_50A260(a1, 32);
                if (v3)
                    v3[1] = 24;
                v4 = sub_50A260(a1, 41);
                if (v4)
                    v4[1] = *(_DWORD*)& byte_5D4594[2598000] + a2[1];
                v5 = sub_50A260(a1, 24);
                if (v5)
                {
                    v6 = *a2;
                    v5[1] = *(_DWORD*)(*a2 + 56);
                    v7 = *(_DWORD*)(v6 + 60);
                    v5[3] = 0;
                    v5[2] = v7;
                }
            }
        }
    }
}

//----- (00516000) --------------------------------------------------------
int sub_516000()
{
    int v0; // edi
    int v1; // esi
    int v2; // ebx
    unsigned __int8* v3; // eax
    int v5[2]; // [esp+Ch] [ebp-8h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v5[0] = sub_511B60(v1);
    if (v5[0])
    {
        v5[1] = v0;
        v3 = (unsigned __int8*)sub_57C0A0(v2);
        sub_502670(v3, 0, (void(__cdecl*)(int, int))sub_515F70, (int)v5);
    }
    return 0;
}

//----- (00516060) --------------------------------------------------------
int sub_516060()
{
    int v0; // eax
    int v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_516090(v1, &v3);
    return 0;
}

//----- (00516090) --------------------------------------------------------
void __cdecl sub_516090(int a1, _DWORD* a2)
{
    int v2; // eax
    int* v3; // eax
    int* v4; // eax

    if (a1)
    {
        if (a2)
        {
            if (*(_BYTE*)(a1 + 8) & 2)
            {
                v2 = *(_DWORD*)(a1 + 16);
                if ((v2 & 0x8000) == 0)
                {
                    v3 = sub_50A260(a1, 32);
                    if (v3)
                        v3[1] = 1;
                    v4 = sub_50A260(a1, 1);
                    if (v4)
                        v4[1] = *(_DWORD*)& byte_5D4594[2598000] + *a2;
                }
            }
        }
    }
}

//----- (005160F0) --------------------------------------------------------
int sub_5160F0()
{
    int v0; // eax
    unsigned __int8* v1; // eax
    int v3; // [esp+0h] [ebp-4h]

    v3 = script_pop();
    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_516090, (int)& v3);
    return 0;
}

//----- (00516120) --------------------------------------------------------
int sub_516120()
{
    int v0; // eax
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v2 = sub_4FA6D0(v1);
        sub_507230(v2);
    }
    else
    {
        sub_507230(0);
    }
    return 0;
}

//----- (00516160) --------------------------------------------------------
int sub_516160()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
        sub_4FA620(v2, v0);
    return 0;
}

//----- (00516190) --------------------------------------------------------
int sub_516190()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
        sub_4EF3A0(v2, *(float*)& v0);
    return 0;
}

//----- (005161C0) --------------------------------------------------------
int sub_5161C0()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v4; // edi

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = sub_511B60(v0);
    v4 = 0;
    if (v2 && v3 && sub_5330C0(v2, v3))
        v4 = 1;
    sub_507230(v4);
    return 0;
}

//----- (00516210) --------------------------------------------------------
int sub_516210()
{
    int v0; // esi
    int v1; // eax
    int result; // eax
    const char* v3; // ecx
    int v4; // ebp
    const char* v5; // ebx
    unsigned __int8* v6; // edi
    int v7; // [esp+10h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v7 = sub_511B60(v1);
    if (v7)
    {
        v3 = *(const char**)& byte_587000[237172];
        v4 = 1;
        if (*(_DWORD*)& byte_587000[237172])
        {
            v5 = *(const char**)& byte_5D4594[4 * v0 + 3831212];
            v6 = &byte_587000[237172];
            while (strcmp(v3, v5))
            {
                v3 = (const char*) * ((_DWORD*)v6 + 1);
                v6 += 4;
                v4 *= 2;
                if (!v3)
                    return 0;
            }
            sub_507230((v4 & *(_DWORD*)(v7 + 8)) != 0);
        }
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (005162D0) --------------------------------------------------------
int sub_5162D0()
{
    int v0; // eax
    int result; // eax
    unsigned __int8* v2; // edi
    int v3; // ebp
    const char* v4; // ecx
    bool v5; // zf
    const char** i; // [esp+10h] [ebp-10h]
    unsigned __int8* v7; // [esp+14h] [ebp-Ch]
    int v8; // [esp+18h] [ebp-8h]
    int v9; // [esp+1Ch] [ebp-4h]

    v8 = script_pop();
    v0 = script_pop();
    v9 = sub_511B60(v0);
    if (v9)
    {
        v2 = &byte_587000[237304];
        if (byte_587000 != (unsigned __int8*)-237304)
        {
            v7 = &byte_587000[237304];
            for (i = (const char**)& byte_587000[237304]; ; i += 32)
            {
                v3 = 1;
                v4 = *i;
                if (*i)
                    break;
            LABEL_8:
                v5 = v7 + 128 == 0;
                v2 = v7 + 128;
                v7 += 128;
                if (v5)
                    return 0;
            }
            while (strcmp(v4, *(const char**)& byte_5D4594[4 * v8 + 3831212]))
            {
                v4 = (const char*) * ((_DWORD*)v2 + 1);
                v2 += 4;
                v3 *= 2;
                if (!v4)
                    goto LABEL_8;
            }
            sub_507230((v3 & *(_DWORD*)(v9 + 12)) != 0);
        }
        result = 0;
    }
    else
    {
        sub_507230(0);
        result = 0;
    }
    return result;
}

//----- (005163C0) --------------------------------------------------------
int sub_5163C0()
{
    int v0; // eax
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v2 = sub_548F40(v1);
        sub_507230(v2);
    }
    else
    {
        sub_507230(0);
    }
    return 0;
}

//----- (00516400) --------------------------------------------------------
int sub_516400()
{
    if (sub_40A5C0(2048))
    {
        sub_4DB130("AUTOSAVE");
        sub_4DB170(1, 0, 0);
    }
    return 0;
}

//----- (00516430) --------------------------------------------------------
int sub_516430()
{
    int v0; // ebx
    char v2[3]; // [esp+4h] [ebp-8h]
    int v3; // [esp+8h] [ebp-4h]

    v0 = script_pop();
    v3 = script_pop();
    if (sub_40A5C0(2048))
    {
        sub_43D9B0(v3, v0);
    }
    else
    {
        v2[1] = v3;
        v2[2] = v0;
        v2[0] = -27;
        sub_4E5390(255, (int)v2, 3, 0, 1);
    }
    return 0;
}

//----- (005164A0) --------------------------------------------------------
int __thiscall sub_5164A0(void* this)
{
    void* v2; // [esp+0h] [ebp-4h]

    v2 = this;
    if (sub_40A5C0(2048))
    {
        sub_43DA80();
    }
    else
    {
        LOBYTE(v2) = -26;
        sub_4E5390(255, (int)& v2, 3, 0, 1);
    }
    return 0;
}

//----- (005164E0) --------------------------------------------------------
int __thiscall sub_5164E0(void* this)
{
    void* v2; // [esp+0h] [ebp-4h]

    v2 = this;
    if (sub_40A5C0(2048))
    {
        sub_43DAD0();
    }
    else
    {
        LOBYTE(v2) = -25;
        sub_4E5390(255, (int)& v2, 3, 0, 1);
    }
    return 0;
}

//----- (00516520) --------------------------------------------------------
int __thiscall sub_516520(void* this)
{
    void* v2; // [esp+0h] [ebp-4h]

    v2 = this;
    if (sub_40A5C0(2048))
    {
        sub_43D9B0(0, 0);
    }
    else
    {
        LOWORD(v2) = 229;
        sub_4E5390(255, (int)& v2, 3, 0, 1);
    }
    return 0;
}

//----- (00516570) --------------------------------------------------------
int __thiscall sub_516570(_BYTE* this)
{
    int v1; // eax
    _BYTE* v2; // esi
    _BYTE* v4; // [esp+0h] [ebp-4h]

    v4 = this;
    v1 = sub_4DA7C0();
    if (v1)
    {
        do
        {
            v2 = *(_BYTE * *)(*(_DWORD*)(v1 + 748) + 276);
            if (v2[2064] == 31)
                break;
            v1 = sub_4DA7F0(v1);
        } while (v1);
    }
    else
    {
        v2 = v4;
    }
    *(_DWORD*)& byte_5D4594[2650672] = 1;
    return sub_4D9560((unsigned __int8)v2[2064], byte_5D4594[2386828], *(int*)& byte_5D4594[2386832]);
}

//----- (005165D0) --------------------------------------------------------
int sub_5165D0()
{
    *(_DWORD*)& byte_5D4594[2386828] = script_pop() - 1;
    sub_413A00(1);
    return sub_44DAB0(25, 1, (void (*)(void))sub_516570);
}

//----- (00516600) --------------------------------------------------------
int sub_516600()
{
    int i; // esi
    int v1; // esi
    int v2; // edi

    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
    {
        if (*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064) == 31)
            break;
    }
    sub_4277B0(i, 0xEu);
    v1 = sub_4E7980(i);
    if (v1)
    {
        do
        {
            v2 = sub_4E7990(v1);
            if (*(_BYTE*)(v1 + 8) & 0x40)
                sub_4E5CC0(v1);
            v1 = v2;
        } while (v2);
    }
    *(_DWORD*)& byte_5D4594[2386832] = 1;
    sub_5165D0();
    return 0;
}

//----- (00516680) --------------------------------------------------------
int sub_516680()
{
    *(_DWORD*)& byte_5D4594[2386832] = 0;
    sub_5165D0();
    return 0;
}

//----- (005166A0) --------------------------------------------------------
int sub_5166A0()
{
    char* v0; // eax
    int v1; // ecx

    v0 = sub_417090(31);
    v1 = 0;
    if (v0 && *(_DWORD*)(*(_DWORD*)(*((_DWORD*)v0 + 514) + 748) + 284))
        v1 = 1;
    sub_507230(v1);
    return 0;
}

//----- (005166E0) --------------------------------------------------------
int sub_5166E0()
{
    char* v0; // eax
    int v1; // ecx

    v0 = sub_417090(31);
    v1 = 0;
    if (v0 && *(_DWORD*)(*(_DWORD*)(*((_DWORD*)v0 + 514) + 748) + 280))
        v1 = 1;
    sub_507230(v1);
    return 0;
}

//----- (00516720) --------------------------------------------------------
int sub_516720()
{
    char* v0; // esi
    int v1; // eax
    int v2; // eax
    int v3; // ecx
    int v4; // ecx

    v0 = sub_417090(31);
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = *(_DWORD*)(v2 + 12);
        BYTE1(v3) |= 1u;
        *(_DWORD*)(v2 + 12) = v3;
        v4 = *((_DWORD*)v0 + 514);
        if (v4)
            sub_4EC290(v4, v2);
    }
    return 0;
}

//----- (00516760) --------------------------------------------------------
int sub_516760()
{
    int v0; // eax
    int v1; // eax
    int v2; // edx

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v2 = *(_DWORD*)(v1 + 12);
        BYTE1(v2) &= 0xFEu;
        *(_DWORD*)(v1 + 12) = v2;
        sub_4EC300(v1);
    }
    return 0;
}

//----- (00516790) --------------------------------------------------------
int __thiscall sub_516790(void* this)
{
    int v1; // eax
    int v2; // eax
    void* v4; // [esp+0h] [ebp-4h]

    v4 = this;
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
        sub_507230((*(_DWORD*)(v2 + 12) >> 8) & 1);
    else
        sub_507230((int)v4);
    return 0;
}

//----- (005167D0) --------------------------------------------------------
int sub_5167D0()
{
    char* v0; // esi
    int v1; // eax
    int v2; // eax
    int v3; // ecx

    v0 = sub_417090(31);
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = *((_DWORD*)v0 + 514);
        if (v3)
            sub_4E7B00(v3, v2);
    }
    return 0;
}

//----- (00516810) --------------------------------------------------------
int sub_516810()
{
    char* v0; // esi
    int v1; // eax
    _DWORD* v2; // eax
    int v3; // ecx

    v0 = sub_417090(31);
    v1 = script_pop();
    v2 = (_DWORD*)sub_511B60(v1);
    if (v2)
    {
        v3 = *((_DWORD*)v0 + 514);
        if (v3)
            sub_4E7B60(v3, v2);
    }
    return 0;
}

//----- (00516850) --------------------------------------------------------
int __thiscall sub_516850(void* this)
{
    int v1; // eax
    int v2; // eax
    void* v4; // [esp+0h] [ebp-4h]

    v4 = this;
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
        sub_507230((*(_DWORD*)(v2 + 12) & 0xFFu) >> 7);
    else
        sub_507230((int)v4);
    return 0;
}

//----- (00516890) --------------------------------------------------------
int sub_516890()
{
    _DWORD* v0; // edi
    int v1; // esi
    int v2; // ebx
    _DWORD* v3; // eax
    _DWORD* v4; // eax

    v0 = (_DWORD*) * ((_DWORD*)sub_417090(31) + 514);
    v1 = 0;
    v2 = script_pop();
    v3 = (_DWORD*)v0[126];
    if (v3)
    {
        while (!(v3[2] & 0x1000000) || !(v3[3] & 0x7800000))
        {
            v3 = (_DWORD*)v3[124];
            if (!v3)
                goto LABEL_7;
        }
        v1 = (v3[4] >> 8) & 1;
        sub_4E5CC0((int)v3);
    }
LABEL_7:
    v4 = sub_4EF750((int)v0, *(CHAR * *)& byte_587000[4 * v2 + 247336], 0, 1, 1);
    if (v1)
        sub_4F2F70(v0, (int)v4);
    return 0;
}

//----- (00516920) --------------------------------------------------------
int sub_516920()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        if (v0 == 1)
        {
            sub_4E79C0(v2, 1);
            return 0;
        }
        sub_4E7A60(v2, 1);
    }
    return 0;
}

//----- (00516960) --------------------------------------------------------
int sub_516960()
{
    *(_DWORD*)& byte_5D4594[2386840] = script_pop();
    return 0;
}

//----- (00516970) --------------------------------------------------------
int sub_516970()
{
    int v0; // esi
    int v1; // edi
    int v2; // eax
    int v3; // eax
    _DWORD* v4; // eax
    int result; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_511B60(v2);
    if (!v3 || !(*(_BYTE*)(v3 + 8) & 2))
        return 0;
    v4 = *(_DWORD * *)(v3 + 748);
    switch (v1)
    {
    case 3:
        v4[309] = v0;
        result = 0;
        break;
    case 4:
        v4[307] = v0;
        result = 0;
        break;
    case 5:
        v4[317] = v0;
        result = 0;
        break;
    case 6:
        v4[311] = v0;
        result = 0;
        break;
    case 7:
        v4[313] = v0;
        result = 0;
        break;
    case 8:
        v4[315] = v0;
        result = 0;
        break;
    case 9:
        v4[319] = v0;
        result = 0;
        break;
    case 10:
        v4[321] = v0;
        result = 0;
        break;
    case 11:
        v4[323] = v0;
        result = 0;
        break;
    case 13:
        v4[325] = v0;
        return 0;
    default:
        return 0;
    }
    return result;
}

//----- (00516A50) --------------------------------------------------------
int sub_516A50()
{
    int v0; // esi
    int v1; // eax
    _DWORD* v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = (_DWORD*)sub_511B60(v1);
    if (v2)
        sub_511660(v2, v0);
    return 0;
}

//----- (00516A80) --------------------------------------------------------
void __cdecl sub_516A80(int a1, int a2, int a3, int a4)
{
    int v4; // eax
    _DWORD* v5; // eax
    int v6; // ecx

    if (!*(_DWORD*)& byte_5D4594[2386904])
        * (_DWORD*)& byte_5D4594[2386904] = sub_4E3AA0((CHAR*)& byte_587000[247416]);
    v4 = sub_4E7980(a1);
    if (v4)
    {
        while (*(unsigned __int16*)(v4 + 4) != *(_DWORD*)& byte_5D4594[2386904])
        {
            v4 = sub_4E7990(v4);
            if (!v4)
                goto LABEL_8;
        }
        sub_4E5CC0(v4);
    }
LABEL_8:
    v5 = sub_4E3810((CHAR*)& byte_587000[247424]);
    if (v5)
    {
        v6 = v5[173];
        *(_DWORD*)v6 = a2;
        *(_DWORD*)(v6 + 4) = a3;
        *(_DWORD*)(v6 + 8) = a4;
        *(_BYTE*)(v6 + 20) = 0;
        if (a2)
            * (_BYTE*)(v6 + 20) = 1;
        if (a3)
            ++* (_BYTE*)(v6 + 20);
        if (a4)
            ++* (_BYTE*)(v6 + 20);
        *(_DWORD*)(v6 + 24) = 0;
        *(_DWORD*)(v6 + 28) = *(_DWORD*)(a1 + 56);
        *(_DWORD*)(v6 + 32) = *(_DWORD*)(a1 + 60);
        sub_4F3070(a1, (int)v5, 1);
    }
}

//----- (00516B40) --------------------------------------------------------
int sub_516B40()
{
    int v0; // ebp
    int v1; // ebx
    int v2; // edi
    int v3; // eax
    int v4; // eax
    int v5; // esi
    int v6; // eax
    int v7; // edi
    int v8; // ebx
    int v9; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = script_pop();
    v4 = sub_511B60(v3);
    v5 = v4;
    if (v4)
    {
        if (*(_BYTE*)(v4 + 8) & 2)
        {
            v6 = *(_DWORD*)(v4 + 12);
            if (v6 & 0x2000)
            {
                v7 = sub_4243F0(*(const char**)& byte_5D4594[4 * v2 + 3831212]);
                v8 = sub_4243F0(*(const char**)& byte_5D4594[4 * v1 + 3831212]);
                v9 = sub_4243F0(*(const char**)& byte_5D4594[4 * v0 + 3831212]);
                sub_516A80(v5, v7, v8, v9);
            }
        }
    }
    return 0;
}

//----- (00516BC0) --------------------------------------------------------
int sub_516BC0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_4D9760(v1);
    return 0;
}

//----- (00516BE0) --------------------------------------------------------
int sub_516BE0()
{
    int v0; // esi
    int v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
        sub_548FE0(v2, *(const char**)& byte_5D4594[4 * v0 + 3831212]);
    return 0;
}

//----- (00516C10) --------------------------------------------------------
int sub_516C10()
{
    sub_44E040();
    return 0;
}

//----- (00516C20) --------------------------------------------------------
int sub_516C20()
{
    sub_44E0B0(1);
    return 0;
}

//----- (00516C30) --------------------------------------------------------
int sub_516C30()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = script_pop();
    v1 = 0;
    v2 = sub_511B60(v0);
    if (v2 && *(_BYTE*)(v2 + 8) & 2)
        v1 = (*(_DWORD*)(*(_DWORD*)(v2 + 748) + 1440) >> 7) & 1;
    sub_507230(v1);
    return 0;
}

//----- (00516C70) --------------------------------------------------------
int sub_516C70()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_516C90(v1);
    return 0;
}

//----- (00516C90) --------------------------------------------------------
int __cdecl sub_516C90(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        if (*(_BYTE*)(a1 + 8) & 2)
            * (_DWORD*)(*(_DWORD*)(a1 + 748) + 1440) |= 0x100000u;
    }
    return result;
}

//----- (00516CB0) --------------------------------------------------------
int sub_516CB0()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_516C90, 0);
    return 0;
}

//----- (00516CE0) --------------------------------------------------------
int sub_516CE0()
{
    int v0; // eax
    int v1; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
        sub_516D00(v1);
    return 0;
}

//----- (00516D00) --------------------------------------------------------
unsigned int __cdecl sub_516D00(int a1)
{
    unsigned int result; // eax
    int v2; // edx

    result = a1;
    if (a1 && *(_BYTE*)(a1 + 8) & 2)
    {
        v2 = *(_DWORD*)(a1 + 16);
        if ((v2 & 0x8000) != 0)
        {
            *(_DWORD*)(*(_DWORD*)(a1 + 748) + 1440) &= 0xFFEFFFFF;
            result = sub_534AB0(a1);
        }
    }
    return result;
}

//----- (00516D40) --------------------------------------------------------
int sub_516D40()
{
    int v0; // eax
    unsigned __int8* v1; // eax

    v0 = script_pop();
    v1 = (unsigned __int8*)sub_57C0A0(v0);
    sub_502670(v1, 0, (void(__cdecl*)(int, int))sub_516D00, 0);
    return 0;
}

//----- (00516D70) --------------------------------------------------------
int sub_516D70()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v2 = *(_DWORD*)& byte_5D4594[2386908];
        if (!*(_DWORD*)& byte_5D4594[2386908])
        {
            v2 = sub_4E3AA0((CHAR*)& byte_587000[247432]);
            *(_DWORD*)& byte_5D4594[2386908] = v2;
        }
        sub_507230(*(unsigned __int16*)(v1 + 4) == v2);
    }
    return 0;
}

//----- (00516DC0) --------------------------------------------------------
int sub_516DC0()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = script_pop();
    v1 = sub_511B60(v0);
    if (v1)
    {
        v2 = *(_DWORD*)& byte_5D4594[2386912];
        if (!*(_DWORD*)& byte_5D4594[2386912])
        {
            v2 = sub_4E3AA0((CHAR*)& byte_587000[247444]);
            *(_DWORD*)& byte_5D4594[2386912] = v2;
        }
        sub_507230(*(unsigned __int16*)(v1 + 4) == v2);
    }
    return 0;
}

//----- (00516E10) --------------------------------------------------------
int sub_516E10()
{
    int v0; // eax

    v0 = script_pop();
    sub_578C90(v0);
    return 0;
}

//----- (00516E30) --------------------------------------------------------
int sub_516E30()
{
    int v0; // edi
    int v1; // eax
    int v2; // eax
    int v3; // esi
    char* v4; // eax

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    v3 = v2;
    if (v2 && *(_BYTE*)(v2 + 8) & 4)
    {
        if (v0 <= 0)
            sub_4D8EC0(v2, -v0);
        else
            sub_4D8E90(v2, v0);
        v4 = sub_418AB0(*(unsigned __int8*)(v3 + 52));
        if (v4)
            sub_419090((int)v4, v0 + *((_DWORD*)v4 + 13));
        sub_4D8EF0(v3);
    }
    return 0;
}

//----- (00516EA0) --------------------------------------------------------
int sub_516EA0()
{
    int v0; // eax
    int v1; // esi
    int v2; // eax

    v0 = script_pop();
    v1 = 0;
    v2 = sub_511B60(v0);
    if (v2 && *(_BYTE*)(v2 + 8) & 4)
        v1 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 2136);
    sub_507230(v1);
    return 0;
}

//----- (00516EE0) --------------------------------------------------------
BOOL sub_516EE0()
{
    *(_DWORD*)& byte_5D4594[2386920] = 0;
    *(_DWORD*)& byte_5D4594[2386916] = nox_new_alloc_class("PendingOwn", 12, 512);
    return *(_DWORD*)& byte_5D4594[2386916] != 0;
}

//----- (00516F10) --------------------------------------------------------
int sub_516F10()
{
    int result; // eax

    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[2386916]);
    result = 0;
    *(_DWORD*)& byte_5D4594[2386916] = 0;
    *(_DWORD*)& byte_5D4594[2386920] = 0;
    return result;
}

//----- (00516F30) --------------------------------------------------------
void sub_516F30()
{
    sub_4144D0(*(_DWORD * *)& byte_5D4594[2386916]);
    *(_DWORD*)& byte_5D4594[2386920] = 0;
}

//----- (00516F50) --------------------------------------------------------
int __cdecl sub_516F50(int a1, int a2)
{
    int v2; // eax

    v2 = sub_4DA870();
    if (!v2)
        return 0;
    while (*(_DWORD*)(v2 + 44) != a2)
    {
        v2 = sub_4DA880(v2);
        if (!v2)
            return 0;
    }
    sub_4EC290(a1, v2);
    return 1;
}

//----- (00516F90) --------------------------------------------------------
_DWORD* __cdecl sub_516F90(int a1, int a2)
{
    _DWORD* result; // eax

    result = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[2386916]);
    if (result)
    {
        *result = a1;
        result[1] = a2;
        result[2] = *(_DWORD*)& byte_5D4594[2386920];
        *(_DWORD*)& byte_5D4594[2386920] = result;
    }
    return result;
}

//----- (00516FC0) --------------------------------------------------------
void sub_516FC0()
{
    int* v0; // esi
    int v1; // edi
    int v2; // eax

    v0 = *(int**)& byte_5D4594[2386920];
    if (*(_DWORD*)& byte_5D4594[2386920])
    {
        do
        {
            v1 = sub_4ECF10(*v0);
            v2 = sub_4ECF10(v0[1]);
            if (v1 && v2)
                sub_4EC290(v1, v2);
            v0 = (int*)v0[2];
        } while (v0);
    }
    sub_516F30();
}

//----- (00517010) --------------------------------------------------------
int sub_517010()
{
    int result; // eax
    FILE* v1; // esi
    char v2[256]; // [esp+4h] [ebp-100h]

    *(_DWORD*)& byte_5D4594[2386924] = 0;
    result = sub_408CC0((char*)& byte_587000[249116], 0);
    v1 = (FILE*)result;
    if (result)
    {
        result = sub_408D40(result, 23);
        if (result)
        {
            while (sub_517090(v1, v2) && sub_517170(v1, v2))
                ;
            sub_408D90(v1);
            result = 1;
        }
    }
    return result;
}

//----- (00517090) --------------------------------------------------------
int __cdecl sub_517090(FILE* a1, _BYTE* a2)
{
    _BYTE* v2; // ebx
    int v3; // ecx
    int v4; // edi
    int v5; // ebp
    int v6; // eax
    WORD CharType[2]; // [esp+10h] [ebp-4h]

    v2 = a2;
    v3 = 0;
    *(_DWORD*)CharType = 0;
    v4 = 1;
    do
    {
        while (1)
        {
            v5 = v3;
            sub_408E40((char*)CharType, 1, 1, a1);
            if (sub_409370() == -1)
                return 0;
            if (*(_DWORD*)& byte_587000[1668] <= 1)
            {
                v3 = *(_DWORD*)CharType;
                v6 = isspace(CharType[0]);
            }
            else
            {
                v6 = isspace(CharType[0]);
                v3 = *(_DWORD*)CharType;
            }
            if (v6)
                break;
            v4 = 0;
            if (v3 != 47 || v5 != 47)
            {
                *v2++ = v3;
            }
            else
            {
                sub_517140(a1);
                v2 = a2;
                v3 = *(_DWORD*)CharType;
                v4 = 1;
            }
        }
    } while (v4);
    *v2 = 0;
    return 1;
}

//----- (00517140) --------------------------------------------------------
int __cdecl sub_517140(FILE* a1)
{
    FILE* v1; // esi
    int result; // eax

    v1 = a1;
    do
    {
        LOBYTE(a1) = 0;
        sub_408E40((char*)& a1, 1, 1, v1);
        result = sub_409370();
    } while (result != -1 && (_BYTE)a1 != 10);
    return result;
}

//----- (00517170) --------------------------------------------------------
int __cdecl sub_517170(FILE* a1, const char* a2)
{
    int result; // eax
    _DWORD* v3; // ebx
    unsigned __int8* v4; // esi
    int v5; // eax
    char* v6; // edi
    int v7; // edi
    unsigned __int8* v8; // esi
    int v9; // [esp+10h] [ebp-104h]
    char v10[256]; // [esp+14h] [ebp-100h]

    result = (int)nox_calloc(1u, 0xF8u);
    v3 = (_DWORD*)result;
    if (result)
    {
        strcpy((char*)result, a2);
        while (1)
        {
            if (!sub_517090(a1, v10) || !_strcmpi("END", v10))
            {
                v3[61] = *(_DWORD*)& byte_5D4594[2386924];
                *(_DWORD*)& byte_5D4594[2386924] = v3;
                return 1;
            }
            if (sub_40A5C0(2048) || sub_40A5C0(0x200000))
            {
                if (_strcmpi("ARENA", v10))
                {
                    if (_strcmpi("SOLO", v10))
                        goto LABEL_10;
                }
                else
                {
                    sub_517140(a1);
                }
            }
            else
            {
            LABEL_10:
                if (!sub_40A5C0(0x2000))
                    goto LABEL_14;
                if (_strcmpi("SOLO", v10))
                {
                    if (_strcmpi("ARENA", v10))
                    {
                    LABEL_14:
                        v4 = &byte_587000[248192];
                        if (*(_DWORD*)& byte_587000[248192])
                        {
                            do
                            {
                                if (!_strcmpi(*(const char**)v4, v10))
                                    break;
                                v5 = *((_DWORD*)v4 + 3);
                                v4 += 12;
                            } while (v5);
                        }
                        if (!*(_DWORD*)v4)
                        {
                            free(v3);
                            return 0;
                        }
                        v6 = (char*)v3 + *((_DWORD*)v4 + 2);
                        switch (*((_DWORD*)v4 + 1))
                        {
                        case 0:
                            sub_517090(a1, v10);
                            *(_DWORD*)v6 = atoi(v10);
                            continue;
                        case 1:
                            sub_517090(a1, v10);
                            *(float*)v6 = atof(v10);
                            continue;
                        case 2:
                            sub_517090(a1, v10);
                            *(_DWORD*)v6 = sub_40AF50(v10);
                            continue;
                        case 3:
                            sub_517090(a1, v10);
                            if (sub_549040((int)v3, v10))
                                continue;
                            return 0;
                        case 4:
                            sub_517090(a1, v10);
                            if (sub_5490E0((int)v3, v10))
                                continue;
                            return 0;
                        case 5:
                            sub_517090(a1, v10);
                            if (sub_549180((int)v3, v10))
                                continue;
                            return 0;
                        case 6:
                            v9 = 0;
                            sub_517090(a1, v10);
                            sub_423930(v10, &v9, (const char**)& byte_587000[247536]);
                            *(_WORD*)v6 = v9;
                            continue;
                        case 7:
                            sub_517090(a1, v6);
                            if (!strcmp("NULL", v6))
                                * v6 = 0;
                            continue;
                        case 8:
                            sub_517090(a1, v10);
                            v3[31] = 18;
                            v7 = 0;
                            v8 = &byte_587000[247464];
                            break;
                        default:
                            continue;
                        }
                        while (_strcmpi(v10, (const char*)(*(_DWORD*)v8 + 7)))
                        {
                            v8 += 4;
                            ++v7;
                            if ((int)v8 >= (int)& byte_587000[247536])
                                goto LABEL_27;
                        }
                        v3[31] = v7;
                    LABEL_27:
                        if (v3[31] == 18)
                            return 0;
                    }
                }
                else
                {
                    sub_517140(a1);
                }
            }
        }
    }
    return result;
}

//----- (005174F0) --------------------------------------------------------
_DWORD* sub_5174F0()
{
    _DWORD* result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD * *)& byte_5D4594[2386924];
    if (*(_DWORD*)& byte_5D4594[2386924])
    {
        do
        {
            v1 = (_DWORD*)result[61];
            free(result);
            result = v1;
        } while (v1);
        *(_DWORD*)& byte_5D4594[2386924] = 0;
    }
    return result;
}

//----- (00517520) --------------------------------------------------------
int sub_517520()
{
    int v0; // esi
    int v1; // eax

    v0 = *(_DWORD*)& byte_5D4594[2386924];
    if (!*(_DWORD*)& byte_5D4594[2386924])
        return 1;
    while (1)
    {
        v1 = sub_4E3AA0((CHAR*)v0);
        *(_DWORD*)(v0 + 240) = v1;
        if (!v1)
            break;
        v0 = *(_DWORD*)(v0 + 244);
        if (!v0)
            return 1;
    }
    sub_5174F0();
    return 0;
}

//----- (00517560) --------------------------------------------------------
_DWORD* __cdecl sub_517560(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[2386924];
    if (!*(_DWORD*)& byte_5D4594[2386924])
        return 0;
    while (result[60] != a1)
    {
        result = (_DWORD*)result[61];
        if (!result)
            return 0;
    }
    return result;
}

//----- (00517590) --------------------------------------------------------
BOOL __cdecl sub_517590(float a1, float a2)
{
    int v4; // [esp+0h] [ebp-4h]

    sub_5175E0(a1, (int)& a1);
    sub_5175E0(a2, (int)& v4);
    return a1 >= 0.0
        && SLODWORD(a1) < *(int*)& byte_5D4594[2386944]
        && v4 >= 0
        && v4 < *(int*)& byte_5D4594[2386944];
}

//----- (005175E0) --------------------------------------------------------
int __cdecl sub_5175E0(float a1, int a2)
{
    int result; // eax

    if (a1 >= 0.0)
    {
        result = a2;
        *(_DWORD*)& byte_5D4594[2386932] = &byte_5D4594[2386952];
        *(float*)& byte_5D4594[2386952] = a1 * 0.011764706 + 8388608.0;
        *(_DWORD*)a2 = 0x7FFFFF & *(_DWORD*)& byte_5D4594[2386952];
    }
    else
    {
        result = sub_419A70(a1);
        *(_DWORD*)a2 = result;
    }
    return result;
}

//----- (00517640) --------------------------------------------------------
__int16 __cdecl sub_517640(signed int a1)
{
    int v1; // edi
    int v2; // eax
    signed int v3; // esi
    int v4; // ebx
    signed int v5; // eax
    int v6; // ecx
    int v8; // [esp+4h] [ebp-14h]
    int v9; // [esp+8h] [ebp-10h]
    int v10; // [esp+Ch] [ebp-Ch]
    int v11; // [esp+10h] [ebp-8h]
    int v12; // [esp+14h] [ebp-4h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 16);
    if (!(v2 & 0x20) && !(v2 & 0x200) && v2 & 4)
    {
        if (!(*(_BYTE*)(a1 + 8) & 1))
        {
            sub_4E7350(a1);
            sub_5175E0(*(float*)(v1 + 232), (int)& v8);
            sub_5175E0(*(float*)(v1 + 236), (int)& v10);
            sub_5175E0(*(float*)(v1 + 240), (int)& a1);
            sub_5175E0(*(float*)(v1 + 244), (int)& v9);
            v3 = v8;
            if (v8 < 0)
            {
                v3 = 0;
                v8 = 0;
            }
            v4 = v10;
            if (v10 < 0)
            {
                v4 = 0;
                v10 = 0;
            }
            v5 = a1;
            if (a1 >= *(int*)& byte_5D4594[2386944])
            {
                v5 = *(_DWORD*)& byte_5D4594[2386944] - 1;
                a1 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            }
            v6 = v9;
            if (v9 >= *(int*)& byte_5D4594[2386944])
            {
                v6 = *(_DWORD*)& byte_5D4594[2386944] - 1;
                v9 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            }
            for (*(_BYTE*)(v1 + 336) = 0; v4 <= v6; ++v4)
            {
                if (v3 <= v5)
                {
                    do
                    {
                        sub_517780(1, v3, v4, v1);
                        v5 = a1;
                        ++v3;
                    } while (v3 <= a1);
                    v3 = v8;
                    v6 = v9;
                }
            }
        }
        sub_5175E0(*(float*)(v1 + 64), (int)& v12);
        sub_5175E0(*(float*)(v1 + 68), (int)& v11);
        sub_517780(0, v12, v11, v1);
        v2 = *(_DWORD*)(v1 + 16);
        BYTE1(v2) |= 2u;
        *(_DWORD*)(v1 + 16) = v2;
    }
    return v2;
}

//----- (00517780) --------------------------------------------------------
int __cdecl sub_517780(int a1, int a2, int a3, int a4)
{
    int result; // eax
    unsigned __int8 v5; // cl
    int v6; // esi
    int v7; // esi

    if (a1)
    {
        result = a1 - 1;
        if (a1 == 1)
        {
            v5 = *(_BYTE*)(a4 + 336);
            if (v5 < 4u)
            {
                result = a4 + 16 * (v5 + 17);
                *(_BYTE*)(a4 + 336) = v5 + 1;
                *(_WORD*)result = a2;
                *(_WORD*)(result + 2) = a3;
                *(_DWORD*)(result + 12) = a4;
                *(_DWORD*)(result + 8) = 0;
                *(_DWORD*)(result + 4) = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a2) + 16 * a3 + 4);
                v6 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a2) + 16 * a3 + 4);
                if (v6)
                    * (_DWORD*)(v6 + 8) = result;
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a2) + 16 * a3 + 4) = result;
            }
        }
    }
    else
    {
        *(_DWORD*)(a4 + 268) = a4;
        result = a4 + 256;
        *(_WORD*)(a4 + 256) = a2;
        *(_WORD*)(a4 + 258) = a3;
        *(_DWORD*)(a4 + 264) = 0;
        *(_DWORD*)(a4 + 260) = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a2) + 16 * a3);
        v7 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a2) + 16 * a3);
        if (v7)
            * (_DWORD*)(v7 + 8) = result;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a2) + 16 * a3) = result;
    }
    return result;
}

//----- (00517870) --------------------------------------------------------
__int16 __cdecl sub_517870(int a1)
{
    int v1; // eax
    int v2; // edi
    unsigned __int16* v3; // ebx

    v1 = *(_DWORD*)(a1 + 16);
    if (v1 & 0x200)
    {
        sub_5178E0(0, (unsigned __int16*)(a1 + 256));
        if (!(*(_BYTE*)(a1 + 8) & 1))
        {
            v2 = 0;
            if (*(_BYTE*)(a1 + 336))
            {
                v3 = (unsigned __int16*)(a1 + 272);
                do
                {
                    sub_5178E0(1, v3);
                    ++v2;
                    v3 += 8;
                } while (v2 < *(unsigned __int8*)(a1 + 336));
            }
            *(_BYTE*)(a1 + 336) = 0;
        }
        v1 = *(_DWORD*)(a1 + 16);
        BYTE1(v1) &= 0xFDu;
        *(_DWORD*)(a1 + 16) = v1;
    }
    return v1;
}

//----- (005178E0) --------------------------------------------------------
unsigned __int16* __cdecl sub_5178E0(int a1, unsigned __int16* a2)
{
    unsigned __int16* result; // eax
    int v3; // ecx
    int v4; // ecx
    int v5; // ecx
    int v6; // ecx

    if (a1)
    {
        result = (unsigned __int16*)(a1 - 1);
        if (a1 == 1)
        {
            result = a2;
            v3 = *((_DWORD*)a2 + 2);
            if (v3)
                * (_DWORD*)(v3 + 4) = *((_DWORD*)a2 + 1);
            else
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * *a2) + 16 * a2[1] + 4) = *((_DWORD*)a2 + 1);
            v4 = *((_DWORD*)a2 + 1);
            if (v4)
                * (_DWORD*)(v4 + 8) = *((_DWORD*)a2 + 2);
        }
    }
    else
    {
        result = a2;
        v5 = *((_DWORD*)a2 + 2);
        if (v5)
            * (_DWORD*)(v5 + 4) = *((_DWORD*)a2 + 1);
        else
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * *a2) + 16 * a2[1]) = *((_DWORD*)a2 + 1);
        v6 = *((_DWORD*)a2 + 1);
        if (v6)
            * (_DWORD*)(v6 + 8) = *((_DWORD*)a2 + 2);
    }
    return result;
}

//----- (00517970) --------------------------------------------------------
void __cdecl sub_517970(int a1)
{
    sub_517870(a1);
    if (sub_517590(*(float*)(a1 + 64), *(float*)(a1 + 68)))
        sub_517640(a1);
    else
        sub_4E5CC0(a1);
}

//----- (005179B0) --------------------------------------------------------
void __cdecl sub_5179B0(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // ecx
    int v4; // edx
    int v5; // eax
    __int16 v6; // dx
    int v7; // eax
    int v8; // [esp+4h] [ebp-4h]

    v1 = a1;
    if (!(*(_BYTE*)(a1 + 480) & 2))
    {
        sub_5175E0(*(float*)(a1 + 8), (int)& a1);
        sub_5175E0(*(float*)(v1 + 12), (int)& v8);
        v2 = v8;
        v3 = a1;
        v4 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * a1) + 16 * v8 + 8);
        if (v4)
        {
            *(_DWORD*)(v4 + 500) = v1;
            v3 = a1;
            v2 = v8;
        }
        *(_DWORD*)(v1 + 500) = 0;
        v5 = 16 * v2;
        *(_DWORD*)(v1 + 496) = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v3) + v5 + 8);
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v3) + v5 + 8) = v1;
        v6 = a1;
        *(_WORD*)(v1 + 494) = v8;
        v7 = *(_DWORD*)(v1 + 480);
        *(_WORD*)(v1 + 492) = v6;
        LOBYTE(v7) = v7 | 2;
        *(_DWORD*)(v1 + 480) = v7;
    }
}

//----- (00517A70) --------------------------------------------------------
int __cdecl sub_517A70(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    if (*(_BYTE*)(a1 + 480) & 2)
    {
        v2 = *(_DWORD*)(a1 + 500);
        if (v2)
            * (_DWORD*)(v2 + 496) = *(_DWORD*)(a1 + 496);
        else
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * *(__int16*)(a1 + 492))
                + 16 * *(__int16*)(a1 + 494)
                + 8) = *(_DWORD*)(a1 + 496);
        v3 = *(_DWORD*)(a1 + 496);
        if (v3)
            * (_DWORD*)(v3 + 500) = *(_DWORD*)(a1 + 500);
        *(_DWORD*)(a1 + 480) &= 0xFFFFFFFD;
    }
    return result;
}

//----- (00517AE0) --------------------------------------------------------
int sub_517AE0()
{
    size_t v0; // eax
    int i; // esi

    *(_DWORD*)& byte_5D4594[2386944] = 70;
    *(_DWORD*)& byte_5D4594[2386940] = nox_malloc(0x118u);
    v0 = *(_DWORD*)& byte_5D4594[2386944];
    for (i = 0; i < *(int*)& byte_5D4594[2386944]; ++i)
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * i) = nox_calloc(v0, 0x10u);
        v0 = *(_DWORD*)& byte_5D4594[2386944];
    }
    return 1;
}

//----- (00517B30) --------------------------------------------------------
void sub_517B30()
{
    int i; // esi

    for (i = 0; i < *(int*)& byte_5D4594[2386944]; ++i)
        free(*(LPVOID*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * i));
    free(*(LPVOID*)& byte_5D4594[2386940]);
}

//----- (00517B70) --------------------------------------------------------
void __cdecl sub_517B70(float2* a1, void(__cdecl* a2)(_DWORD, int), int a3)
{
    int v3; // ecx
    int v4; // eax
    int i; // esi
    int v6; // [esp+8h] [ebp-8h]
    int v7; // [esp+Ch] [ebp-4h]

    if (!a2)
        return;
    sub_5175E0(a1->field_0, (int)& v6);
    sub_5175E0(a1->field_4, (int)& v7);
    v3 = v6;
    if (v6 >= 0)
    {
        if (v6 < *(int*)& byte_5D4594[2386944])
            goto LABEL_7;
        v3 = *(_DWORD*)& byte_5D4594[2386944] - 1;
    }
    else
    {
        v3 = 0;
    }
    v6 = v3;
LABEL_7:
    v4 = v7;
    if (v7 >= 0)
    {
        if (v7 < *(int*)& byte_5D4594[2386944])
            goto LABEL_12;
        v4 = *(_DWORD*)& byte_5D4594[2386944] - 1;
    }
    else
    {
        v4 = 0;
    }
    v7 = v4;
LABEL_12:
    for (i = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v3) + 16 * v4 + 4); i; i = *(_DWORD*)(i + 4))
        a2(*(_DWORD*)(i + 12), a3);
}

//----- (00517C10) --------------------------------------------------------
void __cdecl sub_517C10(float4* a1, void(__cdecl* a2)(float*, int), int a3)
{
    int v3; // eax
    int v4; // et1
    void(__cdecl * v5)(float*, int); // ebp
    int v6; // eax
    int v7; // edi
    float4* v8; // edi
    int v9; // esi
    int v10; // edx
    int v11; // eax
    int v12; // ecx
    int v13; // ebx
    int v14; // eax
    int v15; // ecx
    int v16; // esi
    int v17; // et1
    _DWORD* v18; // eax
    int v19; // ecx
    float* v20; // ecx
    int v21; // et1
    int v22; // [esp+4h] [ebp-10h]
    int v23; // [esp+8h] [ebp-Ch]
    int v24; // [esp+Ch] [ebp-8h]
    int v25; // [esp+10h] [ebp-4h]
    int v26; // [esp+18h] [ebp+4h]
    int v27; // [esp+1Ch] [ebp+8h]
    int v28; // [esp+20h] [ebp+Ch]

    v4 = *(_DWORD*)& byte_587000[249172];
    v3 = v4;
    if (v4 < 1)
    {
        v5 = a2;
        if (a2)
        {
            v6 = v3 + 1;
            v7 = *(_DWORD*)& byte_5D4594[4 * v6 + 2386964];
            *(_DWORD*)& byte_587000[249172] = v6;
            *(_DWORD*)& byte_5D4594[4 * v6 + 2386964] = v7 + 1;
            v8 = a1;
            sub_5175E0(a1->field_0, (int)& v24);
            sub_5175E0(a1->field_4, (int)& v25);
            sub_5175E0(a1->field_8, (int)& v22);
            sub_5175E0(a1->field_C, (int)& v23);
            v9 = v24;
            if (v24 < 0)
            {
                v24 = 0;
                v9 = 0;
            }
            v10 = v22;
            if (v22 >= *(int*)& byte_5D4594[2386944])
            {
                v10 = *(_DWORD*)& byte_5D4594[2386944] - 1;
                v22 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            }
            v11 = v25;
            if (v25 < 0)
            {
                v11 = 0;
                v25 = 0;
            }
            if (v23 >= *(int*)& byte_5D4594[2386944])
                v23 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            v12 = v11;
            v26 = v11;
            if (v11 <= v23)
            {
                v13 = a3;
                do
                {
                    v14 = v9;
                    v27 = v9;
                    if (v9 <= v10)
                    {
                        v15 = 16 * v12;
                        v28 = v15;
                        do
                        {
                            v16 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v14) + v15 + 4);
                            if (v16)
                            {
                                do
                                {
                                    v17 = *(_DWORD*)& byte_587000[249172];
                                    v18 = (_DWORD*)(*(_DWORD*)(v16 + 12) + 4 * v17 + 248);
                                    v19 = *(_DWORD*)& byte_5D4594[4 * v17 + 2386964];
                                    if (*v18 != v19)
                                    {
                                        *v18 = v19;
                                        v20 = *(float**)(v16 + 12);
                                        if (v20[58] < (double)v8->field_8
                                            && v20[60] > (double)v8->field_0
                                            && v20[59] < (double)v8->field_C
                                            && v20[61] > (double)v8->field_4)
                                        {
                                            v5(v20, v13);
                                        }
                                    }
                                    v16 = *(_DWORD*)(v16 + 4);
                                } while (v16);
                                v15 = v28;
                                v10 = v22;
                                v14 = v27;
                            }
                            v27 = ++v14;
                        } while (v14 <= v10);
                        v12 = v26;
                        v9 = v24;
                    }
                    v26 = ++v12;
                } while (v12 <= v23);
            }
            v21 = *(_DWORD*)& byte_587000[249172];
            *(_DWORD*)& byte_587000[249172] = v21 - 1;
        }
    }
}

//----- (00517DC0) --------------------------------------------------------
void __cdecl sub_517DC0(float4* a1, void(__cdecl* a2)(int, int), int a3)
{
    void(__cdecl * v3)(int, int); // ebp
    int v4; // ebx
    int v5; // edx
    int v6; // eax
    int v7; // ecx
    int v8; // eax
    int v9; // esi
    int v10; // eax
    int v11; // [esp+Ch] [ebp-10h]
    int v12; // [esp+10h] [ebp-Ch]
    int v13; // [esp+14h] [ebp-8h]
    int v14; // [esp+18h] [ebp-4h]
    float4* v15; // [esp+20h] [ebp+4h]
    int i; // [esp+24h] [ebp+8h]

    v3 = a2;
    if (a2)
    {
        sub_5175E0(a1->field_0, (int)& v13);
        sub_5175E0(a1->field_4, (int)& v14);
        sub_5175E0(a1->field_8, (int)& v11);
        sub_5175E0(a1->field_C, (int)& v12);
        v4 = v13;
        if (v13 < 0)
        {
            v13 = 0;
            v4 = 0;
        }
        v5 = v11;
        if (v11 >= *(int*)& byte_5D4594[2386944])
        {
            v5 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            v11 = *(_DWORD*)& byte_5D4594[2386944] - 1;
        }
        v6 = v14;
        if (v14 < 0)
        {
            v6 = 0;
            v14 = 0;
        }
        if (v12 >= *(int*)& byte_5D4594[2386944])
            v12 = *(_DWORD*)& byte_5D4594[2386944] - 1;
        v7 = v6;
        for (i = v6; v7 <= v12; i = v7)
        {
            if (v4 <= v5)
            {
                v8 = 16 * v7;
                v15 = (float4*)(16 * v7);
                do
                {
                    v9 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v4) + v8);
                    if (v9)
                    {
                        do
                        {
                            v10 = *(_DWORD*)(v9 + 12);
                            if (*(_BYTE*)(v10 + 8) & 1)
                                v3(v10, a3);
                            v9 = *(_DWORD*)(v9 + 4);
                        } while (v9);
                        v5 = v11;
                        v8 = (int)v15;
                    }
                    ++v4;
                } while (v4 <= v5);
                v4 = v13;
                v7 = i;
            }
            ++v7;
        }
    }
}

//----- (00517ED0) --------------------------------------------------------
void __cdecl sub_517ED0(float4* a1, void(__cdecl* a2)(float*, int), int a3)
{
    sub_517C10(a1, a2, a3);
    sub_517DC0(a1, (void(__cdecl*)(int, int))a2, a3);
}

//----- (00517F00) --------------------------------------------------------
int* __cdecl sub_517F00(float* a1, int(__cdecl* a2)(int*, int), int a3)
{
    int* result; // eax
    int* i; // esi
    double v5; // st7
    double v6; // st7

    result = (int*)sub_410780();
    for (i = result; result; i = result)
    {
        v5 = (double)(23 * i[1]);
        if (v5 > * a1 && v5 < a1[2])
        {
            v6 = (double)(23 * i[2]);
            if (v6 > a1[1] && v6 < a1[3])
                a2(i, a3);
        }
        result = (int*)sub_410790(i);
    }
    return result;
}

//----- (00517F90) --------------------------------------------------------
void __cdecl sub_517F90(float2* a1, float a2, int a3, int a4)
{
    double v4; // st7
    int a3a[4]; // [esp+0h] [ebp-20h]
    float4 a1a; // [esp+10h] [ebp-10h]

    a3a[0] = (int)a1;
    a3a[2] = a3;
    *(float*)& a3a[1] = a2 * a2;
    v4 = a1->field_0 - a2;
    a3a[3] = a4;
    a1a.field_0 = v4;
    a1a.field_4 = a1->field_4 - a2;
    a1a.field_8 = a2 + a1->field_0;
    a1a.field_C = a2 + a1->field_4;
    sub_517C10(&a1a, sub_518000, (int)a3a);
}

//----- (00518000) --------------------------------------------------------
void __cdecl sub_518000(float* a1, int a2)
{
    double v2; // st7
    double v3; // st6

    v2 = **(float**)a2 - a1[14];
    v3 = *(float*)(*(_DWORD*)a2 + 4) - a1[15];
    if (v3 * v3 + v2 * v2 < *(float*)(a2 + 4))
        (*(void(__cdecl * *)(float*, _DWORD))(a2 + 8))(a1, *(_DWORD*)(a2 + 12));
}

//----- (00518040) --------------------------------------------------------
int __cdecl sub_518040(int arg0, float a2, int arg8, int a4)
{
    int result; // eax
    double v5; // st7
    double v6; // st7
    int a3[4]; // [esp+0h] [ebp-20h]
    float4 a1; // [esp+10h] [ebp-10h]

    result = arg0;
    if (arg0)
    {
        v5 = *(float*)arg0 - a2;
        a3[2] = arg8;
        a3[0] = arg0;
        *(float*)& a3[1] = a2;
        a1.field_0 = v5;
        v6 = *(float*)(arg0 + 4) - a2;
        a3[3] = a4;
        a1.field_4 = v6;
        a1.field_8 = a2 + *(float*)arg0;
        a1.field_C = a2 + *(float*)(arg0 + 4);
        sub_517C10(&a1, sub_5180B0, (int)a3);
    }
    return result;
}

//----- (005180B0) --------------------------------------------------------
void __cdecl sub_5180B0(int a1, int a2)
{
    float2* v2; // eax
    double v3; // st7
    long double v4; // st7
    long double v5; // st7
    float2* v6; // eax
    double v7; // st7
    float2 v8;

    if (a1 && a2)
    {
        if (*(_DWORD*)(a1 + 172) == 2)
        {
            v6 = *(float2 * *)a2;
            *(float*)& v8 = **(float**)a2 - *(float*)(a1 + 56);
            v7 = v6->field_4 - *(float*)(a1 + 60);
            v8.field_4 = v7;
            v4 = sqrt(v7 * v8.field_4 + v8.field_0 * v8.field_0) - *(float*)(a1 + 176);
        }
        else
        {
            if (*(_DWORD*)(a1 + 172) == 3)
            {
                v5 = sub_54A990((float2*) * (_DWORD*)a2, *(float*)(a2 + 4), a1, &v8);
                goto LABEL_9;
            }
            v2 = *(float2 * *)a2;
            *(float*)& v8 = **(float**)a2 - *(float*)(a1 + 56);
            v3 = v2->field_4 - *(float*)(a1 + 60);
            v8.field_4 = v3;
            v4 = sqrt(v3 * v8.field_4 + v8.field_0 * v8.field_0);
        }
        v5 = *(float*)(a2 + 4) - v4;
    LABEL_9:
        if (v5 > 0.0)
            (*(void(__cdecl * *)(int, _DWORD))(a2 + 8))(a1, *(_DWORD*)(a2 + 12));
    }
}

//----- (00518170) --------------------------------------------------------
void __cdecl sub_518170(int a1, float a2, int a3, int a4)
{
    void(__cdecl * v4)(int, int); // ebp
    int v5; // ebx
    int v6; // edx
    int v7; // eax
    double v8; // st7
    int v9; // ecx
    int v10; // edi
    int v11; // eax
    int v12; // esi
    int v13; // ecx
    double v14; // st7
    double v15; // st6
    float v16; // [esp+0h] [ebp-24h]
    float v17; // [esp+0h] [ebp-24h]
    float v18; // [esp+0h] [ebp-24h]
    float v19; // [esp+0h] [ebp-24h]
    int v20; // [esp+14h] [ebp-10h]
    int v21; // [esp+18h] [ebp-Ch]
    int v22; // [esp+1Ch] [ebp-8h]
    int v23; // [esp+20h] [ebp-4h]
    int v24; // [esp+2Ch] [ebp+8h]
    int v25; // [esp+30h] [ebp+Ch]
    int v26; // [esp+34h] [ebp+10h]

    v4 = (void(__cdecl*)(int, int))a3;
    if (a3)
    {
        v16 = *(float*)a1 - a2;
        sub_5175E0(v16, (int)& v22);
        v17 = *(float*)(a1 + 4) - a2;
        sub_5175E0(v17, (int)& v23);
        v18 = a2 + *(float*)a1;
        sub_5175E0(v18, (int)& v20);
        v19 = a2 + *(float*)(a1 + 4);
        sub_5175E0(v19, (int)& v21);
        v5 = v22;
        if (v22 < 0)
        {
            v22 = 0;
            v5 = 0;
        }
        v6 = v20;
        if (v20 >= *(int*)& byte_5D4594[2386944])
        {
            v6 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            v20 = *(_DWORD*)& byte_5D4594[2386944] - 1;
        }
        v7 = v23;
        if (v23 < 0)
        {
            v7 = 0;
            v23 = 0;
        }
        if (v21 >= *(int*)& byte_5D4594[2386944])
            v21 = *(_DWORD*)& byte_5D4594[2386944] - 1;
        v8 = a2 * a2;
        v9 = v7;
        v24 = v7;
        *(float*)& v25 = v8;
        if (v7 <= v21)
        {
            v10 = a4;
            do
            {
                if (v5 <= v6)
                {
                    v11 = 16 * v9;
                    v26 = 16 * v9;
                    do
                    {
                        v12 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v5) + v11);
                        if (v12)
                        {
                            do
                            {
                                v13 = *(_DWORD*)(v12 + 12);
                                if (*(_BYTE*)(v13 + 8) & 1)
                                {
                                    v14 = *(float*)a1 - *(float*)(v13 + 56);
                                    v15 = *(float*)(a1 + 4) - *(float*)(v13 + 60);
                                    if (v15 * v15 + v14 * v14 <= *(float*)& v25)
                                        v4(v13, v10);
                                }
                                v12 = *(_DWORD*)(v12 + 4);
                            } while (v12);
                            v11 = v26;
                            v6 = v20;
                        }
                        ++v5;
                    } while (v5 <= v6);
                    v5 = v22;
                    v9 = v24;
                }
                v24 = ++v9;
            } while (v9 <= v21);
        }
    }
}

//----- (005182D0) --------------------------------------------------------
void __cdecl sub_5182D0(float* a1, float a2, void(__cdecl* a3)(int, int), int a4)
{
    void(__cdecl * v4)(int, int); // ebp
    int v5; // ebx
    int v6; // edx
    int v7; // eax
    double v8; // st7
    int v9; // ecx
    int v10; // edi
    int v11; // eax
    int v12; // esi
    double v13; // st7
    double v14; // st6
    float v15; // [esp+0h] [ebp-24h]
    float v16; // [esp+0h] [ebp-24h]
    float v17; // [esp+0h] [ebp-24h]
    float v18; // [esp+0h] [ebp-24h]
    int v19; // [esp+14h] [ebp-10h]
    int v20; // [esp+18h] [ebp-Ch]
    int v21; // [esp+1Ch] [ebp-8h]
    int v22; // [esp+20h] [ebp-4h]
    int v23; // [esp+2Ch] [ebp+8h]
    float v24; // [esp+30h] [ebp+Ch]
    int v25; // [esp+34h] [ebp+10h]

    v4 = a3;
    if (a3)
    {
        v15 = *a1 - a2;
        sub_5175E0(v15, (int)& v21);
        v16 = a1[1] - a2;
        sub_5175E0(v16, (int)& v22);
        v17 = a2 + *a1;
        sub_5175E0(v17, (int)& v19);
        v18 = a2 + a1[1];
        sub_5175E0(v18, (int)& v20);
        v5 = v21;
        if (v21 < 0)
        {
            v21 = 0;
            v5 = 0;
        }
        v6 = v19;
        if (v19 >= *(int*)& byte_5D4594[2386944])
        {
            v6 = *(_DWORD*)& byte_5D4594[2386944] - 1;
            v19 = *(_DWORD*)& byte_5D4594[2386944] - 1;
        }
        v7 = v22;
        if (v22 < 0)
        {
            v7 = 0;
            v22 = 0;
        }
        if (v20 >= *(int*)& byte_5D4594[2386944])
            v20 = *(_DWORD*)& byte_5D4594[2386944] - 1;
        v8 = a2 * a2;
        v9 = v7;
        v23 = v7;
        v24 = v8;
        if (v7 <= v20)
        {
            v10 = a4;
            do
            {
                if (v5 <= v6)
                {
                    v11 = 16 * v9;
                    v25 = 16 * v9;
                    do
                    {
                        v12 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v5) + v11 + 8);
                        if (v12)
                        {
                            do
                            {
                                if (*(_BYTE*)(v12 + 480) & 1)
                                {
                                    v13 = *a1 - *(float*)(v12 + 8);
                                    v14 = a1[1] - *(float*)(v12 + 12);
                                    if (v14 * v14 + v13 * v13 <= v24)
                                        v4(v12, v10);
                                }
                                v12 = *(_DWORD*)(v12 + 496);
                            } while (v12);
                            v11 = v25;
                            v6 = v19;
                        }
                        ++v5;
                    } while (v5 <= v6);
                    v5 = v21;
                    v9 = v23;
                }
                v23 = ++v9;
            } while (v9 <= v20);
        }
    }
}

//----- (00518440) --------------------------------------------------------
int __cdecl sub_518440(int a1, unsigned __int8 a2)
{
    return sub_518460((float2*)a1, a2, 0);
}

//----- (00518460) --------------------------------------------------------
int __cdecl sub_518460(float2* a1, unsigned __int8 a2, int a3)
{
    int v3; // edi
    float v5; // [esp+0h] [ebp-2Ch]
    float v6; // [esp+0h] [ebp-2Ch]
    float v7; // [esp+0h] [ebp-2Ch]
    float v8; // [esp+0h] [ebp-2Ch]
    float v9; // [esp+18h] [ebp-14h]
    int4 v10; // [esp+1Ch] [ebp-10h]

    ++* (_DWORD*)& byte_5D4594[2386960];
    *(_DWORD*)& byte_5D4594[2386928] = 1148846080;
    v9 = 0.0;
    v3 = 0;
    do
    {
        v5 = a1->field_0 - v9;
        sub_5175E0(v5, &v10.field_0);
        v6 = a1->field_4 - v9;
        sub_5175E0(v6, &v10.field_4);
        v7 = v9 + a1->field_0;
        sub_5175E0(v7, &v10.field_8);
        v8 = v9 + a1->field_4;
        sub_5175E0(v8, &v10.field_C);
        *(_DWORD*)& byte_5D4594[2386948] = 0;
        sub_518550(&v10, (int*)a1, a2, a3);
        if (*(_DWORD*)& byte_5D4594[2386948])
        {
            v3 = *(_DWORD*)& byte_5D4594[2386948];
            v9 = *(float*)& byte_5D4594[2386928];
        }
        else
        {
            if (v3)
                return v3;
            v9 = v9 + 85.0;
        }
    } while (v9 < 1000.0);
    return v3;
}

//----- (00518550) --------------------------------------------------------
int __cdecl sub_518550(int* a1, int* a2, unsigned __int8 a3, int a4)
{
    int* v4; // ebp
    int v5; // eax
    float v6; // edx
    int result; // eax
    int v8; // ecx
    int v9; // edx
    int v10; // ecx
    int v11; // eax
    int v12; // esi
    int v13; // ebx
    int v14; // edi
    int* v15; // ebp
    double v16; // st7
    double v17; // st6
    long double v18; // st5
    int v19; // [esp+4h] [ebp-20h]
    int v20; // [esp+8h] [ebp-1Ch]
    int v21; // [esp+Ch] [ebp-18h]
    float v22; // [esp+10h] [ebp-14h]
    float4 v23; // [esp+14h] [ebp-10h]

    v4 = a1;
    if ((int)* a1 < 0)
        * a1 = 0;
    v5 = *(_DWORD*)& byte_5D4594[2386944];
    if (a1[2] >= *(int*)& byte_5D4594[2386944])
    {
        a1[2] = *(_DWORD*)& byte_5D4594[2386944] - 1;
        v5 = *(_DWORD*)& byte_5D4594[2386944];
    }
    if (a1[1] < 0)
    {
        a1[1] = 0;
        v5 = *(_DWORD*)& byte_5D4594[2386944];
    }
    if (a1[3] >= v5)
        a1[3] = v5 - 1;
    v6 = *((float*)a2 + 1);
    result = a1[1];
    LODWORD(v23.field_0) = *a2;
    v8 = a1[3];
    v23.field_4 = v6;
    v20 = result;
    if (result <= v8)
    {
        v9 = 16 * result;
        v21 = 16 * result;
        do
        {
            v10 = *v4;
            v19 = *v4;
            if (*v4 <= v4[2])
            {
                do
                {
                    v11 = v9 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v10);
                    if (*(_DWORD*)(v11 + 12) != *(_DWORD*)& byte_5D4594[2386960])
                    {
                        v12 = *(_DWORD*)(v11 + 8);
                        if (v12)
                        {
                            do
                            {
                                if (*(_BYTE*)(v12 + 480) & 1 && sub_579EE0(v12, a3))
                                {
                                    if (!a4)
                                        goto LABEL_35;
                                    v13 = 0;
                                    v14 = 0;
                                    if (*(_BYTE*)(v12 + 476))
                                    {
                                        v15 = (int*)(v12 + 92);
                                        do
                                        {
                                            if (*(_BYTE*)(*v15 + 480) & 1 && sub_579EE0(*v15, a3))
                                                ++v13;
                                            ++v14;
                                            v15 += 2;
                                        } while (v14 < *(unsigned __int8*)(v12 + 476));
                                        v4 = a1;
                                        if (v13)
                                        {
                                        LABEL_35:
                                            v16 = *(float*)a2 - *(float*)(v12 + 8);
                                            v17 = *((float*)a2 + 1) - *(float*)(v12 + 12);
                                            v18 = sqrt(v17 * v17 + v16 * v16);
                                            if (v18 < *(float*)& byte_5D4594[2386928])
                                            {
                                                v23.field_8 = *(float*)(v12 + 8);
                                                v23.field_C = *(float*)(v12 + 12);
                                                if (sub_535250(&v23, 0, 0, 1))
                                                {
                                                    *(_DWORD*)& byte_5D4594[2386948] = v12;
                                                    v22 = v18;
                                                    *(float*)& byte_5D4594[2386928] = v22;
                                                }
                                            }
                                        }
                                    }
                                }
                                v12 = *(_DWORD*)(v12 + 496);
                            } while (v12);
                            v9 = v21;
                            v10 = v19;
                        }
                        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[2386940] + 4 * v10) + v9 + 12) = *(_DWORD*)& byte_5D4594[2386960];
                    }
                    v19 = ++v10;
                } while (v10 <= v4[2]);
                result = v20;
            }
            ++result;
            v9 += 16;
            v20 = result;
            v21 = v9;
        } while (result <= v4[3]);
    }
    return result;
}

//----- (00518740) --------------------------------------------------------
int __cdecl sub_518740(float2* a1, unsigned __int8 a2)
{
    return sub_518460(a1, a2, 1);
}

//----- (00518760) --------------------------------------------------------
void sub_518760()
{
    nox_srand(0x22F4u);
}

//----- (00518770) --------------------------------------------------------
int sub_518770()
{
    int result; // eax

    result = sub_4E3AA0((CHAR*)& byte_587000[249176]);
    *(_DWORD*)& byte_5D4594[2386972] = result;
    if (result)
    {
        result = sub_4E3AA0((CHAR*)& byte_587000[249196]);
        *(_DWORD*)& byte_5D4594[2386976] = result;
        if (result)
        {
            result = sub_4E3AA0((CHAR*)& byte_587000[249212]);
            *(_DWORD*)& byte_5D4594[2386980] = result;
            if (result)
            {
                *(_DWORD*)& byte_5D4594[2386984] = sub_4E3AA0((CHAR*)& byte_587000[249220]);
                result = *(_DWORD*)& byte_5D4594[2386984] != 0;
            }
        }
    }
    return result;
}

//----- (005187E0) --------------------------------------------------------
int __cdecl sub_5187E0(int a1, int a2)
{
    __int16 v2; // ax
    float v3; // ecx
    __int16 v4; // ax
    float v5; // edx
    int v6; // eax
    char v7; // al
    int2 a2a; // [esp+4h] [ebp-14h]
    char v10[11]; // [esp+Ch] [ebp-Ch]

    v10[0] = 48;
    *(_WORD*)& v10[3] = *(_WORD*)(a2 + 4);
    v2 = sub_578AC0((_DWORD*)a2);
    v3 = *(float*)(a2 + 56);
    *(_WORD*)& v10[1] = v2;
    v4 = sub_419A70(v3);
    v5 = *(float*)(a2 + 60);
    *(_WORD*)& v10[5] = v4;
    v6 = sub_419A70(v5);
    *(_WORD*)& v10[7] = v6;
    if (*(_BYTE*)(a2 + 8) & 1 && *(_BYTE*)(a2 + 12) & 0x30)
    {
        LOWORD(v6) = *(_WORD*)(a2 + 124);
        v10[10] = v6 >> 3;
    }
    else
    {
        v10[10] = -1;
    }
    sub_509E20(*(__int16*)(a2 + 124), &a2a);
    if ((unsigned __int8)(LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4) <= 3u)
        v7 = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
    else
        v7 = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 3;
    v10[9] = 16 * v7;
    return sub_40EF40(a1, v10, 11);
}

//----- (005188A0) --------------------------------------------------------
int __cdecl sub_5188A0(int a1, int a2)
{
    __int16* v2; // eax
    int v3; // ebx
    __int16 v4; // ax
    __int16 v5; // cx
    __int16 v6; // dx
    __int16 v7; // ax
    float v8; // ecx
    char v10[9];

    if (*(_DWORD*)(a2 + 8) & 0x20000)
    {
        v2 = *(__int16**)(a2 + 556);
        if (v2)
        {
            v3 = *(_DWORD*)(a2 + 748);
            if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a2 + 536)) > 2)
            {
                v4 = *v2;
                v5 = *(_WORD*)(v3 + 2 * a1 + 96);
                if (v4 != v5)
                {
                    sub_4D8760(a1, *(_DWORD*)(a2 + 36), v4 - v5);
                    *(_WORD*)(v3 + 2 * a1 + 96) = **(_WORD * *)(a2 + 556);
                }
            }
        }
    }
    v6 = *(_WORD*)(a2 + 4);
    v10[0] = 47;
    *(_WORD*)& v10[3] = v6;
    *(_WORD*)& v10[1] = sub_578AC0((_DWORD*)a2);
    v7 = sub_419A70(*(float*)(a2 + 56));
    v8 = *(float*)(a2 + 60);
    *(_WORD*)& v10[5] = v7;
    *(_WORD*)& v10[7] = sub_419A70(v8);
    return sub_40EF40(a1, v10, 9);
}

//----- (00518960) --------------------------------------------------------
int __cdecl sub_518960(int a1, _DWORD* a2, int a3)
{
    int v3; // ebx
    _DWORD* v4; // esi
    __int16* v5; // eax
    int v6; // edi
    __int16 v7; // ax
    __int16 v8; // cx
    __int16 v9; // dx
    __int16 v10; // ax
    float v11; // ecx
    __int16 v12; // ax
    int v13; // edi
    char v14; // al
    char v15; // al
    int2 a2a; // [esp+Ch] [ebp-14h]
    char v18[11]; // [esp+14h] [ebp-Ch]

    v3 = a1;
    v4 = a2;
    if (a3)
    {
        v5 = (__int16*)a2[139];
        if (v5)
        {
            v6 = a2[187];
            if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - a2[134]) > 2)
            {
                v7 = *v5;
                v8 = *(_WORD*)(v6 + 2 * a1 + 412);
                if (v7 != v8)
                {
                    sub_4D8760(a1, a2[9], v7 - v8);
                    *(_WORD*)(v6 + 2 * v3 + 412) = *(_WORD*)v4[139];
                }
            }
        }
    }
    v9 = *((_WORD*)v4 + 2);
    v18[0] = 48;
    *(_WORD*)& v18[3] = v9;
    *(_WORD*)& v18[1] = sub_578AC0(v4);
    v10 = sub_419A70(*((float*)v4 + 14));
    v11 = *((float*)v4 + 15);
    *(_WORD*)& v18[5] = v10;
    v12 = sub_419A70(v11);
    v13 = v4[187];
    *(_WORD*)& v18[7] = v12;
    v18[9] = sub_533790((int)v4);
    v14 = *((_BYTE*)v4 + 12);
    v18[10] = *(_BYTE*)(v13 + 481);
    if (v14 & 0x10 && *(_BYTE*)(v13 + 2094) && sub_415FA0(0, 10) >= 8)
    {
        v18[9] = 14;
        sub_4F9F90(50, &a3, &a1);
        v18[10] = sub_415FA0(0, a3);
    }
    sub_509E20(*((__int16*)v4 + 62), &a2a);
    LOBYTE(a3) = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
    if ((unsigned __int8)a3 <= 3u)
        v15 = a3;
    else
        v15 = a3 - 1;
    v18[9] |= 16 * v15;
    return sub_40EF40(v3, v18, 11);
}

//----- (00518AE0) --------------------------------------------------------
int __cdecl sub_518AE0(int a1, int a2, _DWORD* a3)
{
    _DWORD* v3; // esi
    __int16 v4; // ax
    int v5; // ecx
    int v7; // eax
    char v8; // dl
    int v9; // eax
    char v10; // dl
    unsigned __int8 v11; // cl
    int v12; // esi
    int v13; // esi
    unsigned __int8 v14; // al
    char v15; // dl

    v3 = a3;
    v4 = sub_578AC0(a3);
    v5 = v3[2];
    *(_WORD*)((char*)& a3 + 1) = v4;
    if (v5 & 0x400000 && v3[3] & 0x18)
    {
        HIBYTE(a3) = *(_BYTE*)v3[187];
        LOBYTE(a3) = -77;
        return sub_4E5390(a2, (int)& a3, 4, 0, 1);
    }
    v7 = *((unsigned __int16*)v3 + 2);
    if ((unsigned __int16)v7 == *(_DWORD*)& byte_5D4594[2386972])
    {
        v8 = *(_BYTE*)(v3[187] + 20);
        LOBYTE(a3) = 57;
        HIBYTE(a3) = v8;
        return sub_40EBC0(a2, 1, &a3, 4);
    }
    if (v7 == *(_DWORD*)& byte_5D4594[2386980])
    {
        v9 = v3[4];
        LOBYTE(a3) = 57;
        HIBYTE(a3) = ~HIBYTE(v9) & 1;
        return sub_40EBC0(a2, 1, &a3, 4);
    }
    if (v7 == *(_DWORD*)& byte_5D4594[2386976])
    {
        v10 = *(_BYTE*)v3[187];
        LOBYTE(a3) = -76;
        HIBYTE(a3) = v10 & 1;
        return sub_40EBC0(a2, 1, &a3, 4);
    }
    if (v5 & 0x4000)
    {
        v11 = *(_BYTE*)(v3[187] + 16);
        LOBYTE(a3) = 57;
        HIBYTE(a3) = v11 >> 2;
        return sub_40EBC0(a2, 1, &a3, 4);
    }
    if ((v5 & 0x8000) != 0)
    {
        v12 = v3[187];
        if (v12 && (v13 = *(_DWORD*)(v12 + 4)) != 0)
        {
            v14 = *(_BYTE*)(*(_DWORD*)(v13 + 748) + 16);
            LOBYTE(a3) = 57;
            HIBYTE(a3) = v14 >> 2;
        }
        else
        {
            HIBYTE(a3) = 0;
            LOBYTE(a3) = 57;
        }
        return sub_40EBC0(a2, 1, &a3, 4);
    }
    if ((v5 & 0x80u) != 0)
    {
        v15 = *(_BYTE*)(v3[187] + 12);
        LOBYTE(a3) = -78;
        HIBYTE(a3) = v15;
        return sub_40EBC0(a2, 1, &a3, 4);
    }
    sub_527E50(a1, v3);
    return 0;
}

//----- (00518C30) --------------------------------------------------------
int __cdecl sub_518C30(int a1, _DWORD* a2, int a3, signed int a4)
{
    int v4; // ebx
    _DWORD* v5; // esi
    int v6; // edi
    int v7; // ebp
    __int16* v8; // eax
    __int16 v9; // ax
    __int16 v10; // cx
    __int16 v11; // ax
    __int16 v12; // ax
    float v13; // ecx
    __int16 v14; // ax
    float v15; // edx
    char v16; // al
    char v17; // al
    signed int v18; // eax
    char v19; // al
    int result; // eax
    int2 a2a; // [esp+10h] [ebp-14h]
    char v22[12]; // [esp+18h] [ebp-Ch]
    int v23; // [esp+28h] [ebp+4h]

    v4 = a1;
    v5 = a2;
    v23 = *(_DWORD*)(a1 + 748);
    v6 = a2[187];
    v7 = *(unsigned __int8*)(*(_DWORD*)(v23 + 276) + 2064);
    if (a4)
    {
        v8 = (__int16*)a2[139];
        if (v8)
        {
            if ((unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - a2[134]) > 2)
            {
                v9 = *v8;
                v10 = *(_WORD*)(v6 + 2 * v7 + 12);
                if (v9 != v10)
                {
                    sub_4D8760(v7, a2[9], v9 - v10);
                    *(_WORD*)(v6 + 2 * v7 + 12) = *(_WORD*)v5[139];
                }
            }
        }
    }
    if ((_DWORD*)v4 == v5)
        sub_4D9900(v4);
    *(_DWORD*)(*(_DWORD*)(v23 + 276) + 4 * *(unsigned __int8*)(*(_DWORD*)(v6 + 276) + 2064) + 4452) = *(_DWORD*)& byte_5D4594[2598000];
    v11 = *((_WORD*)v5 + 2);
    v22[0] = -61;
    *(_WORD*)& v22[3] = v11;
    v12 = sub_578AC0(v5);
    v13 = *((float*)v5 + 14);
    *(_WORD*)& v22[1] = v12;
    v14 = sub_419A70(v13);
    v15 = *((float*)v5 + 15);
    *(_WORD*)& v22[5] = v14;
    *(_WORD*)& v22[7] = sub_419A70(v15);
    v22[9] = 0;
    v22[11] = sub_4FA2B0((int)v5);
    v16 = *(_BYTE*)(v6 + 88);
    if (v16 == 1
        || v16 == 10
        || v16 == 2
        || v16 == 15
        || v16 == 16
        || v16 == 17
        || v16 == 14
        || v16 == 20
        || v16 == 18
        || v16 == 19
        || v16 == 21
        || v16 == 22
        || v16 == 24
        || v16 == 25
        || v16 == 27
        || v16 == 28
        || v16 == 29
        || v16 == 26
        || v16 == 30
        || v16 == 32)
    {
        v22[10] = *(_BYTE*)(v6 + 236);
    }
    else
    {
        v22[10] = -1;
    }
    if (*(_WORD*)(v6 + 160) && sub_415FA0(0, 10) >= 8)
    {
        v22[11] = 50;
        v22[10] = -1;
    }
    v17 = *(_BYTE*)(v6 + 88);
    if ((v17 == 3 || v17 == 4) && v5[131] == 16)
    {
        v22[11] = 51;
        v22[10] = -1;
    }
    if (*(_BYTE*)(v6 + 88) != 30 && *(_DWORD*)(v6 + 164))
    {
        sub_4F9F90(52, &a4, (int*)& a2);
        v18 = (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v6 + 164)) / ((unsigned int)a2 + 1);
        if (v18 >= a4 || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v6 + 164)) >= 4)
        {
            *(_DWORD*)(v6 + 164) = 0;
        }
        else
        {
            v22[11] = 52;
            v22[10] = v18;
        }
    }
    sub_509E20(*((__int16*)v5 + 62), &a2a);
    LOBYTE(a2) = LOBYTE(a2a.field_0) + 3 * LOBYTE(a2a.field_4) + 4;
    if ((unsigned __int8)a2 <= 3u)
        v19 = (char)a2;
    else
        v19 = (_BYTE)a2 - 1;
    v22[9] |= 16 * v19;
    if (a3)
        result = sub_40EF40(*(unsigned __int8*)(*(_DWORD*)(v23 + 276) + 2064), v22, 12);
    else
        result = sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v23 + 276) + 2064), 1, v22, 12);
    return result;
}

//----- (00518EE0) --------------------------------------------------------
int __cdecl sub_518EE0(_DWORD* a3)
{
    _DWORD* v1; // ebx
    int v2; // esi
    int v3; // edi
    int result; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // eax
    int v11; // eax
    int v12; // eax
    int v13; // ebp
    int v14; // ebx
    int v15; // eax
    int v16; // edi
    char v17[3]; // [esp+Ch] [ebp-20h]
    int v18; // [esp+10h] [ebp-1Ch]
    char v19[5]; // [esp+14h] [ebp-18h]
    float4 a1; // [esp+1Ch] [ebp-10h]

    v1 = a3;
    v2 = a3[187];
    v3 = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064);
    sub_40F020(v3);
    if (v3 != 31 && !((*(_DWORD*)& byte_5D4594[2598000] + v3) % (unsigned int)(15 * *(_DWORD*)& byte_5D4594[2649704])))
        sub_4D9020(v3, (int)a3);
    if (!*(_DWORD*)& byte_5D4594[2650652]
        || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)sub_40A6C0())
        || sub_40A5C0(8))
    {
        if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 0x40)
        {
            v19[0] = 40;
            *(_DWORD*)& v19[1] = *(_DWORD*)& byte_5D4594[2598000];
            sub_40EF40(v3, v19, 5);
            sub_417530(*(_DWORD*)(v2 + 276), 64);
        }
        else
        {
            v17[0] = 39;
            *(_WORD*)& v17[1] = *(_WORD*)& byte_5D4594[2598000];
            sub_40EF40(v3, v17, 3);
        }
    }
    if (!*(_DWORD*)& byte_5D4594[2650652]
        || a3 == *(_DWORD * *)& byte_5D4594[3843628]
        || sub_40A5C0(8)
        || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)sub_40A6C0()))
    {
        if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 3 || *(_DWORD*)& byte_5D4594[2650636] & 0x400000)
        {
            result = sub_519330((int)a3);
            if (!result)
                return result;
            if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
                sub_518C30((int)a3, a3, 1, 1);
        }
        else
        {
            result = sub_518C30((int)a3, a3, 1, 1);
            if (!result)
                return result;
        }
        v5 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v5 + 10);
        a1.field_0 = *(float*)(v5 + 3632) - (double)v18 - 100.0;
        v6 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v6 + 12);
        a1.field_4 = *(float*)(v6 + 3636) - (double)v18 - 100.0;
        v7 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v7 + 10);
        a1.field_8 = (double)v18 + *(float*)(v7 + 3632) + 100.0;
        v8 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v8 + 12);
        a1.field_C = (double)v18 + *(float*)(v8 + 3636) + 100.0;
        sub_517ED0(&a1, sub_5193B0, (int)a3);
        v9 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v9 + 10);
        a1.field_0 = *(float*)(v9 + 3632) - (double)v18 - 128.0;
        v10 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v10 + 12);
        a1.field_4 = *(float*)(v10 + 3636) - (double)v18 - 128.0;
        v11 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v11 + 10);
        a1.field_8 = (double)v18 + *(float*)(v11 + 3632) + 128.0;
        v12 = *(_DWORD*)(v2 + 276);
        v18 = *(unsigned __int16*)(v12 + 12);
        a1.field_C = (double)v18 + *(float*)(v12 + 3636) + 128.0;
        sub_517F00(&a1, sub_519660, (int)a3);
        if (sub_519710(v2))
            sub_519760((int)a3, &a1.field_0);
        if (byte_5D4594[2598000] & 8)
        {
            v13 = 0;
            v14 = 1 << *(_BYTE*)(*(_DWORD*)(v2 + 276) + 2064);
            v15 = sub_4DA790();
        LABEL_25:
            v16 = v15;
            while (1)
            {
                if (v16)
                {
                    if (!(*(_DWORD*)(v16 + 8) & 0x20400000)
                        && !sub_4173D0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), v16)
                        && (*(float*)(v16 + 232) > (double)a1.field_8
                            || *(float*)(v16 + 240) < (double)a1.field_0
                            || *(float*)(v16 + 236) > (double)a1.field_C
                            || *(float*)(v16 + 244) < (double)a1.field_4))
                    {
                        if (v14 & *(_DWORD*)(v16 + 148))
                        {
                            sub_528A60(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), (_DWORD*)v16);
                            *(_DWORD*)(v16 + 152) |= v14;
                            *(_DWORD*)(v16 + 148) &= ~v14;
                        }
                    }
                    if (v13)
                        v15 = sub_4DA850(v16);
                    else
                        v15 = sub_4DA7A0(v16);
                    goto LABEL_25;
                }
                if (v13 == 1)
                    break;
                v16 = sub_4DA840();
                v13 = 1;
            }
            v1 = a3;
        }
    }
    if (!*(_DWORD*)& byte_5D4594[2650652]
        || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)sub_40A6C0())
        || sub_40A5C0(8))
    {
        sub_4FF7B0(*(_DWORD*)(v2 + 276));
        sub_511100(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
    }
    return sub_501CA0((int)v1);
}

//----- (00519330) --------------------------------------------------------
int __cdecl sub_519330(int a1)
{
    int v1; // esi
    char v3[12]; // [esp+8h] [ebp-Ch]

    v1 = *(_DWORD*)(a1 + 748);
    v3[0] = -61;
    *(_WORD*)& v3[3] = 0;
    *(_WORD*)& v3[1] = 0;
    *(_WORD*)& v3[5] = (__int64) * (float*)(*(_DWORD*)(v1 + 276) + 3632);
    *(_WORD*)& v3[7] = (__int64) * (float*)(*(_DWORD*)(v1 + 276) + 3636);
    v3[9] = 0;
    v3[10] = -1;
    v3[11] = 0;
    return sub_40EF40(*(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064), v3, 12);
}

//----- (005193B0) --------------------------------------------------------
char __cdecl sub_5193B0(_DWORD* a1, int a2)
{
    int v2; // ebx
    int v3; // eax

    v2 = *(_DWORD*)(a2 + 748);
    if ((_DWORD*)a2 != a1 || (sub_527E50(a2, a1), v3 = *(_DWORD*)(v2 + 276), *(_BYTE*)(v3 + 3680) & 1))
    {
        if (!sub_40A5C0(0x2000)
            || (LOBYTE(v3) = byte_5D4594[2598000], *(_DWORD*)(v2 + 272) != *(_DWORD*)& byte_5D4594[2598000]))
        {
            LOBYTE(v3) = sub_519410(a2, (int)a1);
        }
    }
    return v3;
}

//----- (00519410) --------------------------------------------------------
char __cdecl sub_519410(int a1, int a2)
{
    int v2; // ebx
    int v3; // ecx
    int v4; // eax
    int v5; // edi
    int v6; // ebp
    int v7; // eax
    int v8; // eax
    float v9; // ecx
    float v10; // edx
    int v11; // eax
    int v13; // [esp+10h] [ebp-14h]
    float4 v14; // [esp+14h] [ebp-10h]

    v4 = *(_DWORD*)(a1 + 748);
    v13 = v4;
    v2 = 0;
    v3 = *(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064);
    LOBYTE(v4) = *(_BYTE*)(a2 + 16);
    v5 = v3;
    if (!(v4 & 0x20) && !(*(_DWORD*)(a2 + 8) & 0x40000000))
    {
        v6 = 1 << v3;
        if (a2 != a1 && v6 & *(_DWORD*)(a2 + 140))
        {
            sub_4D97A0(v3, (_DWORD*)a2, (v6 & *(_DWORD*)(a2 + 144)) != 0);
            LOBYTE(v4) = ~(_BYTE)v6;
            *(_DWORD*)(a2 + 140) &= ~v6;
        }
        if (v6 & *(_DWORD*)(a2 + 152) || *(_BYTE*)(a2 + 8) & 1)
        {
            v7 = *(_DWORD*)(a2 + 16);
            if (!(v7 & 0x800) || sub_4EC4F0(a2, a1) || (v4 = sub_40A5C0(512)) != 0)
            {
                v8 = *(_DWORD*)(v13 + 276);
                v14.field_0 = *(float*)(v8 + 3632);
                v9 = *(float*)(a2 + 60);
                v10 = *(float*)(v8 + 3636);
                v14.field_8 = *(float*)(a2 + 56);
                v4 = *(_DWORD*)(a2 + 8);
                v14.field_4 = v10;
                v14.field_C = v9;
                if (v4 & 0x20400000 || (v4 = sub_4173D0(v5, a2)) != 0 || (v4 = sub_535250(&v14, 0, 0, 69)) != 0)
                {
                    if (v6 & *(_DWORD*)(a2 + 148))
                    {
                        if (*(_BYTE*)(a2 + 20) & 0x20)
                            return v4;
                    }
                    else if (*(_DWORD*)(a2 + 4 * v5 + 560) & 0xFFF)
                    {
                        *(_DWORD*)(a2 + 4 * v5 + 560) |= (*(_DWORD*)(a2 + 4 * v5 + 560) & 0xFFF) << 16;
                    }
                    v11 = *(_DWORD*)(a2 + 8);
                    if (v11 & 0x400000)
                    {
                        v2 = sub_518AE0(a1, v5, (_DWORD*)a2);
                    }
                    else if (v11 & 0x200000)
                    {
                        if (v11 & 2)
                        {
                            v2 = sub_518960(v5, (_DWORD*)a2, 1);
                        }
                        else if (v11 & 4)
                        {
                            v2 = sub_518C30(a1, (_DWORD*)a2, 1, 1);
                        }
                        else
                        {
                            v2 = sub_5187E0(v5, a2);
                        }
                    }
                    else if (v11 & 0x100000)
                    {
                        v2 = sub_5188A0(v5, a2);
                    }
                    else
                    {
                        *(_DWORD*)(a2 + 152) = 0;
                    }
                    LOBYTE(v4) = sub_527E50(a1, (_DWORD*)a2);
                    if (v2)
                    {
                        v4 = v6 | *(_DWORD*)(a2 + 148);
                        *(_DWORD*)(a2 + 152) &= ~v6;
                        *(_DWORD*)(a2 + 148) = v4;
                    }
                }
                else if (v6 & *(_DWORD*)(a2 + 148))
                {
                    if (*(_BYTE*)(a2 + 8) & 6)
                        sub_528A60(v5, (_DWORD*)a2);
                    else
                        sub_528A90(v5, (_DWORD*)a2);
                    v4 = ~v6 & *(_DWORD*)(a2 + 148);
                    *(_DWORD*)(a2 + 152) |= v6;
                    *(_DWORD*)(a2 + 148) = v4;
                }
            }
        }
    }
    return v4;
}

//----- (00519660) --------------------------------------------------------
int __cdecl sub_519660(int a1, int a2)
{
    int v2; // esi
    int result; // eax
    int v4; // ebx
    int v5; // [esp-4h] [ebp-10h]

    v2 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064);
    result = (v2 & *(_DWORD*)(a1 + 28)) != 0;
    switch (*(unsigned __int8*)(a1 + 21))
    {
    case 1u:
    case 4u:
        v4 = 0;
        break;
    case 2u:
    case 3u:
        v4 = 1;
        break;
    default:
        v4 = a2;
        break;
    }
    if (result != v4)
    {
        v5 = sub_410580(*(_DWORD*)(a1 + 4), *(_DWORD*)(a1 + 8));
        if (v4)
        {
            sub_4DF120(v5);
            result = v2 | *(_DWORD*)(a1 + 28);
        }
        else
        {
            sub_4DF180(v5);
            result = ~v2 & *(_DWORD*)(a1 + 28);
        }
        *(_DWORD*)(a1 + 28) = result;
    }
    return result;
}

//----- (00519710) --------------------------------------------------------
int __cdecl sub_519710(int a1)
{
    int result; // eax

    result = sub_417270(*(unsigned __int8*)(*(_DWORD*)(a1 + 276) + 2064));
    if (result)
        result = result > 60 || *(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a1 + 268) > (unsigned int)(60 / result);
    return result;
}

//----- (00519760) --------------------------------------------------------
void __cdecl sub_519760(int a1, float* a2)
{
    int v2; // ebp
    int v3; // edi
    int v4; // eax
    int v5; // esi

    v2 = *(_DWORD*)(a1 + 748);
    v3 = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064);
    v4 = sub_4172C0(v3);
    v5 = v4;
    if (v4)
    {
        if (*(_BYTE*)(v4 + 16) & 0x20)
        {
            sub_417430(v4);
        }
        else if (*(float*)(v4 + 56) < (double)* a2
            || *(float*)(v4 + 56) > (double)a2[2]
            || *(float*)(v4 + 60) < (double)a2[1]
            || *(float*)(v4 + 60) > (double)a2[3])
        {
            *(_DWORD*)(v4 + 152) |= 1 << v3;
            sub_519410(a1, v4);
            sub_4D9020(v3, v5);
            *(_DWORD*)(v2 + 268) = *(_DWORD*)& byte_5D4594[2598000];
        }
    }
}

//----- (00519820) --------------------------------------------------------
void sub_519820()
{
    nox_srand(0x22F5u);
}

//----- (00519830) --------------------------------------------------------
int __cdecl sub_519830(int a1, char a2)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        *(_DWORD*)(a1 + 40) = 0;
        *(_BYTE*)a1 = a2;
        *(_WORD*)(a1 + 2) = 0;
        *(_WORD*)(a1 + 4) = 0;
        *(_DWORD*)(a1 + 8) = 0;
        *(_DWORD*)(a1 + 12) = 0;
        *(_DWORD*)(a1 + 16) = 1;
        *(_WORD*)(a1 + 20) = 512;
        *(_DWORD*)(a1 + 24) = 0;
        *(_BYTE*)(a1 + 28) = 2;
        *(_DWORD*)(a1 + 32) = 0;
        *(_DWORD*)(a1 + 44) = 0;
    }
    return result;
}

//----- (00519870) --------------------------------------------------------
int sub_519870()
{
    char v0; // di
    unsigned __int8* v1; // esi
    int result; // eax

    v0 = 0;
    v1 = &byte_5D4594[2387148];
    *(_WORD*)& byte_5D4594[2388636] = 0;
    *(_WORD*)& byte_5D4594[2388638] = 0;
    *(_DWORD*)& byte_5D4594[2388640] = 0;
    *(_DWORD*)& byte_5D4594[2388648] = 0;
    do
    {
        result = sub_519830((int)v1, v0);
        v1 += 48;
        ++v0;
    } while ((int)v1 < (int)& byte_5D4594[2388636]);
    return result;
}

//----- (005198B0) --------------------------------------------------------
void __cdecl sub_5198B0(unsigned __int8 a1)
{
    char v1; // bl
    unsigned __int8* v2; // esi

    v1 = 0;
    v2 = &byte_5D4594[2387150];
    do
    {
        if (*(_WORD*)v2 == 1)
        {
            *(_WORD*)v2 = 0;
            nullsub_27(v2 - 2);
            sub_519C80(v2 - 2, a1);
            ++* (_WORD*)& byte_5D4594[2388638];
            if (*((_WORD*)v2 + 1) == 1)
            {
                if (*(_DWORD*)(v2 + 6))
                    free(*(LPVOID*)(v2 + 6));
            }
            sub_519830((int)(v2 - 2), v1);
        }
        v2 += 48;
        ++v1;
    } while ((int)v2 < (int)& byte_5D4594[2388638]);
}
// 519920: using guessed type void __cdecl nullsub_27(_DWORD);

//----- (00519930) --------------------------------------------------------
int __cdecl sub_519930(int a1)
{
    int v1; // edi
    unsigned __int8* v2; // esi
    char* i; // eax
    char v4; // al
    int v6; // [esp+8h] [ebp-4h]

    v1 = 0;
    v6 = 0;
    v2 = &byte_5D4594[48 * a1 + 2387148];
    if (v2)
    {
        if (a1 < 32)
        {
            for (i = (char*)sub_555250(*v2, &v6); i; i = (char*)sub_555290(*v2, &v6))
            {
                v4 = *i;
                if (v4 == -72 || v4 == -71)
                    ++v1;
            }
        }
    }
    return v1;
}

//----- (00519990) --------------------------------------------------------
void sub_519990()
{
    int v0; // edi
    unsigned __int8* v1; // esi

    if (*(_DWORD*)& byte_5D4594[2388648])
    {
        if (!*(_DWORD*)& byte_5D4594[2388644])
            sub_519EB0();
        v0 = 0;
        v1 = &byte_5D4594[2387180];
        do
        {
            if (*((_WORD*)v1 - 15) == 1)
            {
                if (sub_519930(v0 + 1) > * (v1 - 4))
                    ++* (_DWORD*)v1;
                else
                    sub_5199F0(v1 - 32);
            }
            v1 += 48;
            ++v0;
        } while ((int)v1 < (int)& byte_5D4594[2388668]);
    }
}

//----- (005199F0) --------------------------------------------------------
void __cdecl sub_5199F0(unsigned __int8* a1)
{
    char* v1; // eax
    wchar_t* v2; // eax
    _WORD* v3; // ebp
    unsigned int v4; // eax
    int v5; // esi
    int v6; // edi
    unsigned int v7; // ecx
    unsigned int v8; // eax
    unsigned int v9; // esi
    int v10; // ebp
    char* v11; // edi
    wchar_t* v12; // eax
    int v13; // eax
    wchar_t* v14; // eax
    int v15; // [esp-4h] [ebp-178h]
    int v16; // [esp-4h] [ebp-178h]
    int v17; // [esp+10h] [ebp-164h]
    int v18; // [esp+14h] [ebp-160h]
    char v19[88]; // [esp+1Ch] [ebp-158h]
    wchar_t v20[128]; // [esp+74h] [ebp-100h]

    if (a1)
    {
        if (!*((_DWORD*)a1 + 6))
        {
            v1 = sub_417090(*a1);
            if (v1)
            {
                v15 = (int)(v1 + 4704);
                v2 = loadString_sub_40F1D0((char*)& byte_587000[249408], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 231);
                nox_swprintf(v20, v2, &byte_5D4594[2387068], v15);
                sub_450B90(6u, (int)v20);
            }
            *(_DWORD*)& v19[4] = *((_DWORD*)a1 + 3);
            v19[0] = -72;
            strcpy(&v19[8], (const char*)& byte_5D4594[2387068]);
            sub_552640(*a1 + 1, v19, 88, 3);
        }
        v3 = nox_malloc(*((unsigned __int16*)a1 + 10) + 6);
        if (v3)
        {
            v4 = *((unsigned __int16*)a1 + 10);
            if ((unsigned __int16)v4 >= (unsigned int)(*((_DWORD*)a1 + 3) - *((_DWORD*)a1 + 6)))
            {
                v17 = *((_DWORD*)a1 + 3) - *((_DWORD*)a1 + 6);
                v4 = *((_DWORD*)a1 + 3) - *((_DWORD*)a1 + 6);
            }
            else
            {
                v17 = *((unsigned __int16*)a1 + 10);
            }
            LOBYTE(v18) = -71;
            HIWORD(v18) = *((_WORD*)a1 + 8);
            *(_DWORD*)v3 = v18;
            v3[2] = v4;
            if (*((_WORD*)a1 + 2))
            {
                v5 = *((_DWORD*)a1 + 2);
                v6 = *((_DWORD*)a1 + 6);
            }
            else
            {
                v5 = *((_DWORD*)a1 + 6);
                v6 = *(_DWORD*)& byte_5D4594[2388640];
            }
            qmemcpy(v3 + 3, (const void*)(v6 + v5), v4);
            sub_552640(*a1 + 1, v3, v4 + 6, 3);
            free(v3);
            v7 = *((_DWORD*)a1 + 3);
            v8 = v17 + *((_DWORD*)a1 + 6);
            ++* ((_DWORD*)a1 + 4);
            *((_DWORD*)a1 + 6) = v8;
            if (v8 < v7)
            {
                *((_WORD*)a1 + 1) = 1;
            }
            else
            {
                v9 = (sub_416BB0() - *((_QWORD*)a1 + 5)) / (unsigned __int64)1000;
                if (v9)
                    v10 = *((_DWORD*)a1 + 3) / v9;
                else
                    v10 = *((_DWORD*)a1 + 3);
                v11 = sub_417090(*a1);
                if (v11)
                {
                    v12 = loadString_sub_40F1D0((char*)& byte_587000[249464], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 299);
                    nox_swprintf(v20, v12, *((_DWORD*)a1 + 6), *((_DWORD*)a1 + 4) - 1, v10, v9, v11 + 4704);
                    sub_450B90(6u, (int)v20);
                }
                if (*((_WORD*)a1 + 2) == 1 && *((_DWORD*)a1 + 2))
                    free(*((LPVOID*)a1 + 2));
                v13 = *(_DWORD*)& byte_5D4594[2388648];
                if (*(_DWORD*)& byte_5D4594[2388648])
                    v13 = -- * (_DWORD*)& byte_5D4594[2388648];
                v16 = v13;
                v14 = loadString_sub_40F1D0((char*)& byte_587000[249520], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 315);
                nox_swprintf(v20, v14, v16);
                sub_450B90(6u, (int)v20);
                sub_519830((int)a1, *a1);
            }
        }
    }
}
// 519AFD: variable 'v18' is possibly undefined

//----- (00519C80) --------------------------------------------------------
void __cdecl sub_519C80(unsigned __int8* a1, unsigned __int8 a2)
{
    int v2; // ecx
    wchar_t* v3; // eax
    int v4; // [esp-Ch] [ebp-114h]
    char v5[2]; // [esp+6h] [ebp-102h]
    wchar_t v6[128]; // [esp+8h] [ebp-100h]

    if (a1)
    {
        v2 = *a1;
        v5[0] = -70;
        v5[1] = a2;
        sub_552640(v2 + 1, v5, 2, 3);
        if (*(_DWORD*)& byte_5D4594[2388648])
            --* (_DWORD*)& byte_5D4594[2388648];
        v4 = *a1;
        v3 = loadString_sub_40F1D0((char*)& byte_587000[249572], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 350);
        nox_swprintf(v6, v3, v4, a2);
        sub_450B90(6u, (int)v6);
    }
}

//----- (00519D20) --------------------------------------------------------
char* __cdecl sub_519D20(int a1)
{
    unsigned __int8* v1; // esi
    wchar_t* v2; // eax
    char* result; // eax

    v1 = &byte_5D4594[48 * a1 + 2387148];
    ++* (_DWORD*)& byte_5D4594[2388648];
    if (*((_WORD*)v1 + 1))
    {
        if (*((_WORD*)v1 + 1) == 1)
            v2 = loadString_sub_40F1D0((char*)& byte_587000[249628], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 392);
        else
            v2 = loadString_sub_40F1D0((char*)& byte_587000[249676], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 397);
        result = (char*)sub_450B90(6u, (int)v2);
    }
    else
    {
        ++* (_WORD*)& byte_5D4594[2388636];
        *((_WORD*)v1 + 1) = 1;
        *((_DWORD*)v1 + 6) = 0;
        *((_DWORD*)v1 + 4) = 1;
        *((_WORD*)v1 + 10) = 512;
        *((_DWORD*)v1 + 3) = *(_DWORD*)& byte_5D4594[2388644];
        *((_QWORD*)v1 + 5) = sub_416BB0();
        result = sub_417090(a1);
    }
    return result;
}

//----- (00519DE0) --------------------------------------------------------
int __cdecl sub_519DE0(int a1)
{
    unsigned __int8* v1; // esi
    char* v2; // ebx
    int result; // eax
    wchar_t* v4; // eax

    v1 = &byte_5D4594[48 * a1 + 2387148];
    v2 = sub_417090(a1);
    *((_WORD*)v1 + 1) = 0;
    nullsub_27(v1);
    ++* (_WORD*)& byte_5D4594[2388638];
    if (*((_WORD*)v1 + 2) == 1 && *((_DWORD*)v1 + 2))
        free(*((LPVOID*)v1 + 2));
    sub_519830((int)v1, a1);
    result = *(_DWORD*)& byte_5D4594[2388648];
    if (*(_DWORD*)& byte_5D4594[2388648])
        result = -- * (_DWORD*)& byte_5D4594[2388648];
    if (v2)
    {
        v4 = loadString_sub_40F1D0((char*)& byte_587000[249728], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 428);
        result = sub_450C00(6u, v4, v2 + 4704);
    }
    return result;
}
// 519920: using guessed type void __cdecl nullsub_27(_DWORD);

//----- (00519E80) --------------------------------------------------------
_DWORD* __cdecl sub_519E80(int a1)
{
    sub_417090(a1);
    return sub_4DE410(byte_5D4594[48 * a1 + 2387148]);
}

//----- (00519EB0) --------------------------------------------------------
int sub_519EB0()
{
    char* v0; // eax
    unsigned __int8* v1; // ebx
    void* v2; // eax
    const void* v3; // esi
    unsigned int v4; // kr00_4
    wchar_t* v5; // eax
    char* v6; // edi
    unsigned __int8 v7; // cl
    FILE* v8; // ebx
    int result; // eax
    wchar_t* v10; // eax
    const char* v11; // [esp+10h] [ebp-104h]
    char v12[256]; // [esp+14h] [ebp-100h]

    v0 = sub_409B30();
    v11 = v0;
    if (*(_DWORD*)& byte_5D4594[2388648])
    {
        v1 = &byte_5D4594[2387156];
        do
        {
            if (*((_WORD*)v1 - 3) == 1)
            {
                v2 = nox_malloc(*(size_t*)& byte_5D4594[2388644]);
                *(_DWORD*)v1 = v2;
                if (v2)
                {
                    v3 = *(const void**)& byte_5D4594[2388640];
                    v4 = *(_DWORD*)& byte_5D4594[2388644];
                    *((_WORD*)v1 - 2) = 1;
                    qmemcpy(v2, v3, v4);
                    *((_DWORD*)v1 + 1) = *(_DWORD*)& byte_5D4594[2388644];
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[249788], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 478);
                    sub_450B90(6u, (int)v5);
                }
                else
                {
                    sub_519C80(v1 - 8, 1u);
                }
            }
            v1 += 48;
        } while ((int)v1 < (int)& byte_5D4594[2388644]);
        v0 = (char*)v11;
    }
    if (!v0)
        goto LABEL_16;
    if (!memcmp(v0, &byte_5D4594[2388652], 1u))
        goto LABEL_16;
    strcpy(v12, "maps\\");
    strcat(v12, sub_409B40());
    *(_WORD*)& v12[strlen(v12)] = *(_WORD*)& byte_587000[249808];
    strcat(v12, sub_409B40());
    v6 = &v12[strlen(v12) + 1];
    v7 = byte_587000[249816];
    *(_DWORD*)--v6 = *(_DWORD*)& byte_587000[249812];
    v6[4] = v7;
    v8 = fopen(v12, "rb");
    if (v8)
    {
        strcpy((char*)& byte_5D4594[2386988], v12);
        strcpy((char*)& byte_5D4594[2387068], v11);
        fseek(v8, 0, 2);
        *(_DWORD*)& byte_5D4594[2388644] = ftell(v8);
        fseek(v8, 0, 0);
        *(_DWORD*)& byte_5D4594[2388640] = nox_malloc(*(size_t*)& byte_5D4594[2388644]);
        sub_40ADD0_fread(*(char**)& byte_5D4594[2388640], 1u, *(size_t*)& byte_5D4594[2388644], v8);
        fclose(v8);
        result = 1;
    }
    else
    {
    LABEL_16:
        v10 = loadString_sub_40F1D0((char*)& byte_587000[249864], 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 518);
        sub_450B90(6u, (int)v10);
        result = 0;
    }
    return result;
}

//----- (0051A100) --------------------------------------------------------
LPVOID sub_51A100()
{
    LPVOID result; // eax

    if (*(_DWORD*)& byte_5D4594[2388648])
        sub_5198B0(0);
    result = *(LPVOID*)& byte_5D4594[2388640];
    if (*(_DWORD*)& byte_5D4594[2388640])
        free(*(LPVOID*)& byte_5D4594[2388640]);
    *(_DWORD*)& byte_5D4594[2388644] = 0;
    return result;
}

//----- (0051A130) --------------------------------------------------------
int sub_51A130()
{
    return *(_DWORD*)& byte_5D4594[2388648];
}

//----- (0051A140) --------------------------------------------------------
BOOL __cdecl sub_51A140(int a1)
{
    unsigned __int8* v1; // eax

    v1 = &byte_5D4594[48 * a1 + 2387148];
    return v1 && a1 < 32 && *((_WORD*)v1 + 1) == 1;
}

//----- (0051A170) --------------------------------------------------------
int __cdecl sub_51A170(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    if (!a1)
        return -1;
    v1 = 0;
    v2 = (const char**)& byte_587000[249880];
    while (strcmp(*v2, a1))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[249892])
            return -1;
    }
    return v1;
}

//----- (0051A1D0) --------------------------------------------------------
char* __cdecl sub_51A1D0(int a1)
{
    char* result; // eax

    if (a1 <= -1 || a1 >= 3)
        result = 0;
    else
        result = *(char**)& byte_587000[4 * a1 + 249880];
    return result;
}

//----- (0051A1F0) --------------------------------------------------------
void __cdecl sub_51A1F0(int a1)
{
    int v1; // ebx
    int v2; // edi
    int v3; // ebx
    int v4; // eax
    int v5; // ecx
    int v6; // esi
    double v7; // st7
    int v8; // eax
    int v9; // ebx
    int v10; // ebp
    int v11; // esi
    int v12; // edi
    int v13; // eax
    int v14; // ebx
    int v15; // edi
    int i; // esi
    int v17; // esi
    int v18; // edi
    float v19; // [esp+0h] [ebp-20h]
    float v20; // [esp+0h] [ebp-20h]
    unsigned int v21; // [esp+10h] [ebp-10h]
    int v22; // [esp+14h] [ebp-Ch]
    int v23; // [esp+18h] [ebp-8h]
    unsigned int v24; // [esp+1Ch] [ebp-4h]
    int v25; // [esp+24h] [ebp+4h]

    v21 = 0;
    v23 = 0;
    v1 = sub_4E3CC0();
    v22 = v1;
    v19 = sub_419D40(&byte_587000[252424]);
    v24 = sub_419A70(v19);
    if (!*(_DWORD*)& byte_5D4594[2388668])
    {
        *(_DWORD*)& byte_5D4594[2388668] = sub_4E3AA0((CHAR*)& byte_587000[252444]);
        *(_DWORD*)& byte_5D4594[2388672] = sub_4E3AA0((CHAR*)& byte_587000[252460]);
    }
    v2 = sub_4DA790();
    if (v2)
    {
        v3 = a1;
        do
        {
            v4 = sub_4DA7A0(v2);
            v5 = *(_DWORD*)(v2 + 8);
            v25 = v4;
            if (v5 & 0x20 && *(_BYTE*)(v2 + 12) & 1)
            {
                ++v21;
            }
            else if (*(unsigned __int16*)(v2 + 4) == *(_DWORD*)& byte_5D4594[2388668])
            {
                ++v23;
            }
            if (v5 & 0x20000)
            {
                v6 = *(_DWORD*)(v2 + 748);
                if (*(_DWORD*)(16 * v3 + v6))
                {
                    switch (*(unsigned __int8*)(v6 + v3 + 83))
                    {
                    case 0u:
                        v7 = sub_419D40(&byte_587000[252480]);
                        goto LABEL_18;
                    case 1u:
                        v7 = sub_419D40(&byte_587000[252512]);
                        goto LABEL_18;
                    case 2u:
                        v7 = sub_419D40(&byte_587000[252548]);
                        goto LABEL_18;
                    case 3u:
                        v7 = sub_419D40(&byte_587000[252580]);
                    LABEL_18:
                        *(_BYTE*)(v6 + 87) = (__int64)v7;
                        break;
                    default:
                        break;
                    }
                    if (sub_4E3CC0() >= v24 && *(_BYTE*)(v6 + v3 + 83) != 3)
                        * (_BYTE*)(v6 + 87) *= 2;
                    v8 = sub_51A500(*(_DWORD*)(16 * v3 + v6));
                    if (v8)
                        * (_WORD*)(v2 + 4) = v8;
                }
                else
                {
                    sub_4E5CC0(v2);
                }
            }
            v2 = v25;
        } while (v25);
        if (v21 > 1)
        {
            v9 = sub_415FA0(0, v21 - 1);
            v10 = 0;
            v11 = sub_4DA790();
            if (v11)
            {
                do
                {
                    v12 = sub_4DA7A0(v11);
                    if (*(_BYTE*)(v11 + 8) & 0x20 && *(_BYTE*)(v11 + 12) & 1)
                    {
                        if (v10 != v9)
                            sub_4E5CC0(v11);
                        ++v10;
                    }
                    v11 = v12;
                } while (v12);
            }
        }
        v1 = v22;
    }
    sub_51A940(0);
    if (v1 >= 5)
    {
        v20 = sub_419D40(&byte_587000[252656]);
        v13 = sub_419A70(v20);
        if (v1 == 5 || v1 >= v13 || v1 & 1 && sub_415FA0(1, 100) >= 50)
        {
            sub_51A940(1);
            if (v23)
            {
                v14 = sub_415FA0(1, v23);
                v15 = 0;
                for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
                {
                    if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[2388668] && ++v15 == v14)
                        sub_51A5A0((int*)(i + 56));
                    if (*(unsigned __int16*)(i + 4) == *(_DWORD*)& byte_5D4594[2388672] && sub_415FA0(1, 100) >= 50)
                        sub_51A7A0((int*)(i + 56));
                }
            }
        }
    }
    v17 = sub_4DA790();
    if (v17)
    {
        do
        {
            v18 = sub_4DA7A0(v17);
            if (*(unsigned __int16*)(v17 + 4) == *(_DWORD*)& byte_5D4594[2388668])
                sub_4E5CC0(v17);
            if (*(unsigned __int16*)(v17 + 4) == *(_DWORD*)& byte_5D4594[2388672])
                sub_4E5CC0(v17);
            v17 = v18;
        } while (v18);
    }
}

//----- (0051A500) --------------------------------------------------------
int __cdecl sub_51A500(int a1)
{
    int v1; // ecx
    int v2; // edx
    unsigned __int8* i; // eax
    int v4; // esi

    if (!*(_DWORD*)& byte_5D4594[2388664])
        sub_51A550();
    if (!a1)
        return 0;
    v1 = 0;
    if (!*(_DWORD*)& byte_587000[249904])
        return 0;
    HIWORD(v2) = 0;
    for (i = &byte_587000[249904]; ; i += 16)
    {
        LOWORD(v2) = *(_WORD*)(a1 + 4);
        if (*((_DWORD*)i - 1) == v2)
            break;
        v4 = *((_DWORD*)i + 4);
        ++v1;
        if (!v4)
            return 0;
    }
    return *(_DWORD*)& byte_587000[16 * v1 + 249908];
}

//----- (0051A550) --------------------------------------------------------
CHAR* sub_51A550()
{
    CHAR* result; // eax
    unsigned __int8* v1; // esi

    result = *(CHAR * *)& byte_587000[249904];
    if (*(_DWORD*)& byte_587000[249904])
    {
        v1 = &byte_587000[249896];
        do
        {
            *((_DWORD*)v1 + 3) = sub_4E3AA0(result);
            *((_DWORD*)v1 + 1) = sub_4E3AA0(*(CHAR * *)v1);
            result = (CHAR*) * ((_DWORD*)v1 + 6);
            v1 += 16;
        } while (result);
        *(_DWORD*)& byte_5D4594[2388664] = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[2388664] = 1;
    }
    return result;
}

//----- (0051A5A0) --------------------------------------------------------
void __cdecl sub_51A5A0(int* a1)
{
    _DWORD* v1; // edi
    _DWORD* v2; // esi
    int v3; // eax
    int v4; // eax
    double v5; // st7
    int v6; // eax
    _DWORD* v7; // esi
    int v8; // eax
    _DWORD* v9; // eax
    int v10; // eax
    _DWORD* v11; // eax
    int v12; // eax
    _DWORD* v13; // eax
    int v14; // eax
    _DWORD* v15; // eax
    float v16; // [esp+8h] [ebp-8h]
    float v17; // [esp+Ch] [ebp-4h]

    v1 = sub_4E3810((CHAR*)& byte_587000[252796]);
    v16 = sub_4E40F0();
    if (v1)
    {
        v2 = (_DWORD*)v1[187];
        v3 = v2[121];
        if (v3)
            v4 = *(_DWORD*)(v3 + 72);
        else
            v4 = *(unsigned __int16*)(*(_DWORD*)(sub_4E3B70(*((unsigned __int16*)v1 + 2)) + 136) + 4);
        if (v16 < 1.0)
            v16 = 1.0;
        v5 = (double)v4 * v16;
        v17 = v5;
        sub_4E4560((int)v1, (__int64)v5);
        *(_WORD*)(v1[139] + 4) = sub_419A70(v17);
        if (!*(_WORD*)v1[139])
            sub_4E4560((int)v1, 1u);
        v6 = v1[139];
        if (!*(_WORD*)(v6 + 4))
            * (_WORD*)(v6 + 4) = 1;
        v2[411] = 0x10000000;
        v2[423] = 0x10000000;
        v2[340] = 4;
        v2[326] = 1062501089;
        v2[510] = 3;
        v2[410] = 0x8000000;
        v2[444] = 0x20000000;
        v2[388] = 0x40000000;
        v2[415] = 0x40000000;
        sub_419D40(&byte_587000[252804]);
        v2[330] = 1062836634;
        sub_4DAA50((int)v1, 0, *(float*)a1, *((float*)a1 + 1));
        v7 = sub_4E3810((CHAR*)& byte_587000[252824]);
        if (v7)
        {
            v8 = sub_4E3CC0();
            v9 = sub_4F0720((int)v7, v8 + 2);
            if (v9)
                sub_4F3070((int)v1, (int)v9, 0);
            v10 = sub_4E3CC0();
            v11 = sub_4F0720((int)v7, v10 + 2);
            if (v11)
                sub_4F3070((int)v1, (int)v11, 0);
            v12 = sub_4E3CC0();
            v13 = sub_4F0720((int)v7, v12 + 2);
            if (v13)
                sub_4F3070((int)v1, (int)v13, 0);
            v14 = sub_4E3CC0();
            v15 = sub_4F0720((int)v7, v14 + 2);
            if (v15)
                sub_4F3070((int)v1, (int)v15, 0);
            sub_4E38A0((int)v7);
        }
    }
}

//----- (0051A7A0) --------------------------------------------------------
void __cdecl sub_51A7A0(int* a1)
{
    _DWORD* v1; // edi
    _DWORD* v2; // esi
    int v3; // eax
    int v4; // eax
    double v5; // st7
    int v6; // eax
    _DWORD* v7; // esi
    int v8; // eax
    _DWORD* v9; // eax
    float v10; // [esp+8h] [ebp-8h]
    float v11; // [esp+Ch] [ebp-4h]

    v1 = sub_4E3810((CHAR*)& byte_587000[252840]);
    v10 = sub_4E40F0();
    if (v1)
    {
        v2 = (_DWORD*)v1[187];
        v3 = v2[121];
        if (v3)
            v4 = *(_DWORD*)(v3 + 72);
        else
            v4 = *(unsigned __int16*)(*(_DWORD*)(sub_4E3B70(*((unsigned __int16*)v1 + 2)) + 136) + 4);
        if (v10 < 1.0)
            v10 = 1.0;
        v5 = (double)v4 * v10;
        v11 = v5;
        sub_4E4560((int)v1, (__int64)v5);
        *(_WORD*)(v1[139] + 4) = sub_419A70(v11);
        if (!*(_WORD*)v1[139])
            sub_4E4560((int)v1, 1u);
        v6 = v1[139];
        if (!*(_WORD*)(v6 + 4))
            * (_WORD*)(v6 + 4) = 1;
        v2[340] = 4;
        v2[411] = 0x10000000;
        v2[423] = 0x10000000;
        v2[326] = 1062501089;
        v2[510] = 1;
        v2[410] = 0x8000000;
        v2[444] = 0x20000000;
        v2[415] = 0x40000000;
        sub_4DAA50((int)v1, 0, *(float*)a1, *((float*)a1 + 1));
        v7 = sub_4E3810((CHAR*)& byte_587000[252852]);
        if (v7)
        {
            v8 = sub_4E3CC0();
            v9 = sub_4F0720((int)v7, v8 + 2);
            if (v9)
                sub_4F3070((int)v1, (int)v9, 0);
            sub_4E38A0((int)v7);
        }
    }
}

//----- (0051A920) --------------------------------------------------------
int __cdecl sub_51A920(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[2388660] = a1;
    return result;
}

//----- (0051A930) --------------------------------------------------------
int sub_51A930()
{
    return *(_DWORD*)& byte_5D4594[2388660];
}

//----- (0051A940) --------------------------------------------------------
int __cdecl sub_51A940(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[2388656] = a1;
    return result;
}

//----- (0051A950) --------------------------------------------------------
int sub_51A950()
{
    return *(_DWORD*)& byte_5D4594[2388656];
}

//----- (0051A960) --------------------------------------------------------
int __cdecl sub_51A960(int a1, unsigned __int8* a2)
{
    char* v2; // eax
    int v3; // esi
    int v5; // eax
    int v6; // edx
    int v7; // [esp+Ch] [ebp-C04h]
    char v8[3072]; // [esp+10h] [ebp-C00h]

    v2 = sub_417090(a1);
    v3 = *a2;
    v7 = *a2;
    if (v2 && !(v2[3680] & 0x10))
        return v3 + 1;
    v5 = sub_51AAA0((int)(a2 + 1), v3, (int)v8);
    v6 = *(_DWORD*)& byte_5D4594[4 * a1 + 2388804];
    if (v6 + v5 < 128)
    {
        *(_DWORD*)& byte_5D4594[4 * a1 + 2388804] = v6 + v5;
        qmemcpy(&byte_5D4594[24 * (v6 + (a1 << 7)) + 2388932], v8, 24 * v5);
        v3 = v7;
    }
    sub_51AA20(a1);
    return v3 + 1;
}

//----- (0051AA20) --------------------------------------------------------
int __cdecl sub_51AA20(int a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // edx
    int result; // eax
    int v5; // ebx
    unsigned __int8* v6; // ecx

    v1 = 0;
    v2 = 0;
    v3 = 0;
    result = *(_DWORD*)& byte_5D4594[4 * a1 + 2388804] - 1;
    if (result >= 0)
    {
        v5 = *(_DWORD*)& byte_5D4594[4 * a1 + 2388804];
        v6 = &byte_5D4594[24 * (result + (a1 << 7)) + 2388948];
        do
        {
            if (*(_DWORD*)v6)
            {
                result = *((_DWORD*)v6 - 2) - 2;
                if (*((_DWORD*)v6 - 2) == 2)
                {
                    if (v3)
                        * (_DWORD*)v6 = 0;
                    else
                        v3 = 1;
                }
                else
                {
                    result = *((_DWORD*)v6 - 2) - 4;
                    if (*((_DWORD*)v6 - 2) == 4)
                    {
                        if (v1)
                            * (_DWORD*)v6 = 0;
                        else
                            v1 = 1;
                    }
                    else
                    {
                        result = *((_DWORD*)v6 - 2) - 5;
                        if (*((_DWORD*)v6 - 2) == 5)
                        {
                            if (v2)
                                * (_DWORD*)v6 = 0;
                            else
                                v2 = 1;
                        }
                    }
                }
            }
            v6 -= 24;
            --v5;
        } while (v5);
    }
    return result;
}

//----- (0051AAA0) --------------------------------------------------------
int __cdecl sub_51AAA0(int a1, int a2, int a3)
{
    int v3; // edi
    int v4; // ebp
    _DWORD* v5; // ebx
    int v6; // ecx
    unsigned __int8 v7; // al
    int v9; // [esp+8h] [ebp-4h]

    v3 = 0;
    v4 = 0;
    v9 = 0;
    if (a2 <= 0)
        return 0;
    v5 = (_DWORD*)(a3 + 12);
    do
    {
        v6 = *(unsigned __int8*)(a1 + v4);
        v4 += 4;
        *(v5 - 1) = v6;
        if (sub_42D440(v6))
        {
            v7 = sub_42D450(*(v5 - 1));
            *v5 = 0;
            qmemcpy(v5, (const void*)(v4 + a1), v7);
            v4 += v7;
            v3 = v9;
        }
        else
        {
            *v5 = 0;
        }
        v5[1] = 1;
        ++v3;
        v5 += 6;
        v9 = v3;
    } while (v4 < a2);
    return v3;
}

//----- (0051AB50) --------------------------------------------------------
unsigned __int8* __cdecl sub_51AB50(int a1)
{
    int v1; // esi
    int v2; // edx

    *(_DWORD*)& byte_5D4594[4 * a1 + 2388676] = 0;
    if (*(int*)& byte_5D4594[4 * a1 + 2388804] <= 0)
        return 0;
    v1 = a1 << 7;
    while (1)
    {
        v2 = *(_DWORD*)& byte_5D4594[4 * a1 + 2388676];
        if (*(_DWORD*)& byte_5D4594[24 * (v1 + v2) + 2388948])
            break;
        *(_DWORD*)& byte_5D4594[4 * a1 + 2388676] = v2 + 1;
        if (v2 + 1 >= *(int*)& byte_5D4594[4 * a1 + 2388804])
            return 0;
    }
    return &byte_5D4594[24 * (v1 + *(_DWORD*)& byte_5D4594[4 * a1 + 2388676]) + 2388932];
}

//----- (0051ABC0) --------------------------------------------------------
unsigned __int8* __cdecl sub_51ABC0(int a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // esi

    v1 = *(_DWORD*)& byte_5D4594[4 * a1 + 2388676] + 1;
    *(_DWORD*)& byte_5D4594[4 * a1 + 2388676] = v1;
    v2 = v1;
    if (v1 >= *(int*)& byte_5D4594[4 * a1 + 2388804])
        return 0;
    v3 = a1 << 7;
    while (!*(_DWORD*)& byte_5D4594[24 * (v3 + v2) + 2388948])
    {
        *(_DWORD*)& byte_5D4594[4 * a1 + 2388676] = ++v2;
        if (v2 >= *(int*)& byte_5D4594[4 * a1 + 2388804])
            return 0;
    }
    return &byte_5D4594[24 * (v3 + *(_DWORD*)& byte_5D4594[4 * a1 + 2388676]) + 2388932];
}

//----- (0051AC30) --------------------------------------------------------
int __cdecl sub_51AC30(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[4 * a1 + 2388804] = 0;
    return result;
}

//----- (0051AC40) --------------------------------------------------------
BOOL __cdecl sub_51AC40(int a1)
{
    return *(_DWORD*)& byte_5D4594[4 * a1 + 2388804] == 0;
}

//----- (0051AC60) --------------------------------------------------------
void sub_51AC60()
{
    int v0; // ecx
    int i; // eax

    v0 = *(_DWORD*)& byte_5D4594[2487236];
    if (*(_DWORD*)& byte_5D4594[2487236])
    {
        for (i = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2487236] + 24); i; i = *(_DWORD*)(i + 24))
            v0 = i;
        *(_DWORD*)(v0 + 24) = *(_DWORD*)& byte_5D4594[2487240];
        *(_DWORD*)& byte_5D4594[2487240] = *(_DWORD*)& byte_5D4594[2487236];
        *(_DWORD*)& byte_5D4594[2487236] = 0;
    }
}

//----- (0051ACA0) --------------------------------------------------------
int __cdecl sub_51ACA0(int a1, int a2, int a3)
{
    _DWORD* v3; // esi
    int result; // eax
    int v5; // eax
    int i; // ecx

    v3 = sub_51AD40();
    if (!v3)
        return sub_507230(0);
    *v3 = a1 + *(_DWORD*)& byte_5D4594[2598000];
    v3[1] = a2;
    v3[2] = a3;
    v5 = sub_51AD20();
    v3[3] = v5;
    v3[4] = 0;
    v3[5] = 0;
    v3[6] = 0;
    sub_507230(v5);
    result = *(_DWORD*)& byte_5D4594[2487236];
    if (*(_DWORD*)& byte_5D4594[2487236])
    {
        for (i = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2487236] + 24); i; i = *(_DWORD*)(i + 24))
            result = i;
        *(_DWORD*)(result + 24) = v3;
        v3[7] = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[2487236] = v3;
        v3[7] = 0;
    }
    return result;
}

//----- (0051AD20) --------------------------------------------------------
int sub_51AD20()
{
    int result; // eax

    result = ++ * (_DWORD*)& byte_587000[252868];
    if (*(_DWORD*)& byte_587000[252868] > 0x7D00u)
    {
        result = 1;
        *(_DWORD*)& byte_587000[252868] = 1;
    }
    return result;
}

//----- (0051AD40) --------------------------------------------------------
void* sub_51AD40()
{
    void* result; // eax

    result = *(void**)& byte_5D4594[2487240];
    if (!*(_DWORD*)& byte_5D4594[2487240])
        return nox_malloc(0x20u);
    *(_DWORD*)& byte_5D4594[2487240] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2487240] + 24);
    return result;
}

//----- (0051AD60) --------------------------------------------------------
int __cdecl sub_51AD60(int a1)
{
    int v1; // eax

    v1 = *(_DWORD*)& byte_5D4594[2487236];
    if (!*(_DWORD*)& byte_5D4594[2487236])
        return 0;
    while (*(_DWORD*)(v1 + 12) != a1)
    {
        v1 = *(_DWORD*)(v1 + 24);
        if (!v1)
            return 0;
    }
    sub_51AD90(v1);
    return 1;
}

//----- (0051AD90) --------------------------------------------------------
int __cdecl sub_51AD90(int a1)
{
    int v1; // edx
    _DWORD* v2; // ecx
    int v3; // esi
    int result; // eax

    v1 = *(_DWORD*)(a1 + 24);
    v2 = (_DWORD*)(a1 + 24);
    if (v1)
        * (_DWORD*)(v1 + 28) = *(_DWORD*)(a1 + 28);
    v3 = *(_DWORD*)(a1 + 28);
    if (v3)
        * (_DWORD*)(v3 + 24) = *v2;
    if (a1 == *(_DWORD*)& byte_5D4594[2487236])
        * (_DWORD*)& byte_5D4594[2487236] = *v2;
    result = *v2;
    *v2 = *(_DWORD*)& byte_5D4594[2487240];
    *(_DWORD*)& byte_5D4594[2487240] = a1;
    *(_DWORD*)(a1 + 28) = 0;
    return result;
}

//----- (0051ADF0) --------------------------------------------------------
void sub_51ADF0()
{
    _DWORD* v0; // esi
    int v1; // edi
    int v2; // ebx
    int v3; // ebp

    v0 = *(_DWORD * *)& byte_5D4594[2487236];
    if (*(_DWORD*)& byte_5D4594[2487236])
    {
        do
        {
            if (*v0 > * (int*)& byte_5D4594[2598000])
            {
                v0 = (_DWORD*)v0[6];
            }
            else
            {
                v1 = v0[1];
                v2 = v0[5];
                v3 = v0[4];
                if (*(_DWORD*)(48 * v1 + *(_DWORD*)& byte_5D4594[1599636] + 8))
                    sub_507230(v0[2]);
                v0 = (_DWORD*)sub_51AD90((int)v0);
                sub_507310(v1, v2, v3);
            }
        } while (v0);
    }
}

//----- (0051AE60) --------------------------------------------------------
_DWORD* __cdecl sub_51AE60(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[2487236];
    if (*(_DWORD*)& byte_5D4594[2487236])
    {
        do
        {
            if (result[4] == a1)
            {
                result = (_DWORD*)sub_51AD90((int)result);
            }
            else
            {
                if (result[5] == a1)
                    result[5] = 0;
                result = (_DWORD*)result[6];
            }
        } while (result);
    }
    return result;
}

//----- (0051AEA0) --------------------------------------------------------
int sub_51AEA0()
{
    int v0; // eax
    int j; // esi
    int v2; // eax
    int v3; // eax
    int v5; // [esp+8h] [ebp-Ch]
    int i; // [esp+Ch] [ebp-8h]
    int v7; // [esp+10h] [ebp-4h]

    v7 = 1;
    sub_426AC0(&v7, 2u);
    sub_426AC0(&byte_5D4594[2598000], 4u);
    v0 = *(_DWORD*)& byte_5D4594[2487236];
    for (i = 0; v0; v0 = *(_DWORD*)(v0 + 24))
        ++i;
    sub_426AC0(&i, 4u);
    for (j = *(_DWORD*)& byte_5D4594[2487236]; j; j = *(_DWORD*)(j + 24))
    {
        sub_426AC0((_BYTE*)j, 4u);
        sub_426AC0((_BYTE*)(j + 4), 4u);
        sub_426AC0((_BYTE*)(j + 8), 4u);
        v2 = *(_DWORD*)(j + 16);
        if (v2)
            v5 = *(_DWORD*)(v2 + 44);
        else
            v5 = 0;
        sub_426AC0(&v5, 4u);
        v3 = *(_DWORD*)(j + 20);
        if (v3)
            v5 = *(_DWORD*)(v3 + 44);
        else
            v5 = 0;
        sub_426AC0(&v5, 4u);
    }
    return 1;
}

//----- (0051AF80) --------------------------------------------------------
int sub_51AF80()
{
    int v0; // ebx
    _DWORD* v1; // eax
    _DWORD* v2; // esi
    int v3; // eax
    int i; // ecx
    int v6; // [esp+Ch] [ebp-20h]
    unsigned int v7; // [esp+10h] [ebp-1Ch]
    int v8; // [esp+14h] [ebp-18h]
    int v9; // [esp+18h] [ebp-14h]
    int v10; // [esp+1Ch] [ebp-10h]
    int v11; // [esp+20h] [ebp-Ch]
    int v12; // [esp+24h] [ebp-8h]
    int v13; // [esp+28h] [ebp-4h]

    v6 = 1;
    sub_426AC0(&v6, 2u);
    if ((__int16)v6 <= 1 && (__int16)v6 > 0)
    {
        sub_426AC0(&v8, 4u);
        sub_426AC0(&v7, 4u);
        v0 = 0;
        if (v7 <= 0)
            return 1;
        while (1)
        {
            sub_426AC0(&v9, 4u);
            sub_426AC0(&v10, 4u);
            sub_426AC0(&v11, 4u);
            sub_426AC0(&v12, 4u);
            sub_426AC0(&v13, 4u);
            v1 = sub_51AD40();
            v2 = v1;
            if (!v1)
                break;
            *v1 = v9 + *(_DWORD*)& byte_5D4594[2598000] - v8;
            v1[1] = v10;
            v1[2] = v11;
            v1[3] = sub_51AD20();
            v2[4] = 0;
            v2[5] = 0;
            v2[4] = v12;
            v2[5] = v13;
            v2[6] = 0;
            v3 = *(_DWORD*)& byte_5D4594[2487236];
            if (*(_DWORD*)& byte_5D4594[2487236])
            {
                for (i = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2487236] + 24); i; i = *(_DWORD*)(i + 24))
                    v3 = i;
                *(_DWORD*)(v3 + 24) = v2;
                v2[7] = v3;
            }
            else
            {
                *(_DWORD*)& byte_5D4594[2487236] = v2;
                v2[7] = 0;
            }
            if (++v0 >= v7)
                return 1;
        }
    }
    return 0;
}

//----- (0051B0C0) --------------------------------------------------------
void sub_51B0C0()
{
    int* v0; // esi

    v0 = *(int**)& byte_5D4594[2487236];
    if (*(_DWORD*)& byte_5D4594[2487236])
    {
        do
        {
            if (v0[4])
                v0[4] = sub_511B60(v0[4]);
            if (v0[5])
                v0[5] = sub_511B60(v0[5]);
            v0 = (int*)v0[6];
        } while (v0);
    }
}

//----- (0051B100) --------------------------------------------------------
char sub_51B100()
{
    int i; // esi
    int v1; // edi
    int v2; // esi
    int v3; // ebx
    int v4; // eax
    int v5; // eax
    void(__cdecl * v6)(int); // eax
    int v7; // edi
    _WORD* v8; // eax
    double v9; // st7
    int v10; // eax
    int v11; // ecx
    int v12; // eax
    int j; // esi
    void(__cdecl * v14)(int); // eax
    int v15; // eax
    int v16; // ecx
    int v17; // edx
    int v18; // eax
    int k; // esi
    int v20; // eax
    int v21; // edx
    int v22; // ecx
    __int16 v23; // ax
    __int16 v24; // ax
    char v25; // al
    int v26; // eax
    _WORD* v27; // eax
    BOOL v28; // edi
    int v29; // ecx
    int v30; // edi
    unsigned __int8 v31; // cl
    _BYTE* v32; // esi
    char v33; // bl
    char v34; // al
    int v35; // edx
    char v36; // al
    int v37; // eax
    char v38; // al
    int v39; // eax
    int v40; // eax
    int v41; // ecx
    int v42; // eax
    double v43; // st7
    int v44; // ecx
    char* v45; // eax
    int v46; // eax
    char v47; // al
    int v48; // eax
    int v49; // eax
    int v50; // ecx
    int v51; // eax
    double v52; // st7
    int v53; // ecx
    char* v54; // eax
    int v55; // eax
    double v56; // st7
    float v58; // [esp+0h] [ebp-48h]
    float v59; // [esp+0h] [ebp-48h]
    char v60; // [esp+17h] [ebp-31h]
    float v61; // [esp+18h] [ebp-30h]
    float v62; // [esp+1Ch] [ebp-2Ch]
    float2 v63; // [esp+20h] [ebp-28h]
    float2 v64; // [esp+28h] [ebp-20h]
    float v65; // [esp+34h] [ebp-14h]
    float4 v66;

    for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i))
    {
        v1 = *(_DWORD*)(i + 748);
        sub_4FA490(i);
        *(_DWORD*)(v1 + 288) = sub_54AF40(i);
    }
    v2 = sub_4DA8A0();
    if (v2)
    {
        do
        {
            v3 = sub_4DA8B0(v2);
            if (!(*(_BYTE*)(v2 + 16) & 0x20))
            {
                v4 = *(_DWORD*)(v2 + 520);
                if (v4 && *(_BYTE*)(v4 + 16) & 0x20)
                {
                    v5 = *(_DWORD*)(v4 + 508);
                    if (!v5 || *(_BYTE*)(v5 + 16) & 0x20)
                        * (_DWORD*)(v2 + 520) = 0;
                    else
                        *(_DWORD*)(v2 + 520) = v5;
                }
                v6 = *(void(__cdecl * *)(int))(v2 + 744);
                if (v6)
                {
                    if (*(_BYTE*)(v2 + 8) & 4)
                    {
                        v7 = *(_DWORD*)(v2 + 748);
                        if (!(*(_BYTE*)(v2 + 16) & 2))
                            v6(v2);
                        sub_51AC30(*(unsigned __int8*)(*(_DWORD*)(v7 + 276) + 2064));
                    }
                    else if (!(*(_BYTE*)(v2 + 16) & 2))
                    {
                        v6(v2);
                    }
                }
                if (*(_BYTE*)(v2 + 8) & 2)
                    sub_4E44F0(v2);
                sub_51B870(v2);
                v8 = *(_WORD * *)(v2 + 556);
                if (v8)
                    v8[1] = *v8;
                v9 = *(float*)(v2 + 64) - *(float*)(v2 + 56);
                *(_DWORD*)(v2 + 16) &= 0xFFEFFFFF;
                v58 = v9;
                v61 = sub_419A10(v58);
                v59 = *(float*)(v2 + 68) - *(float*)(v2 + 60);
                v62 = sub_419A10(v59);
                if (*(float*)(v2 + 88) <= *(double*)& byte_581450[10392]
                    || *(float*)(v2 + 88) >= *(double*)& byte_581450[10256]
                    || *(float*)(v2 + 92) <= *(double*)& byte_581450[10392]
                    || *(float*)(v2 + 92) >= *(double*)& byte_581450[10256]
                    || *(float*)(v2 + 80) <= *(double*)& byte_581450[10392]
                    || *(float*)(v2 + 80) >= *(double*)& byte_581450[10256]
                    || *(float*)(v2 + 84) <= *(double*)& byte_581450[10392]
                    || *(float*)(v2 + 84) >= *(double*)& byte_581450[10256]
                    || v61 <= *(double*)& byte_581450[10392]
                    || v61 >= *(double*)& byte_581450[10256]
                    || v62 <= *(double*)& byte_581450[10392]
                    || v62 >= *(double*)& byte_581450[10256]
                    || *(float*)(v2 + 104) <= *(double*)& byte_581450[10392]
                    || *(float*)(v2 + 104) >= *(double*)& byte_581450[10256]
                    || *(float*)(v2 + 108) <= *(double*)& byte_581450[10392]
                    || *(float*)(v2 + 108) >= *(double*)& byte_581450[10256])
                {
                    sub_537610(v2);
                    *(_DWORD*)(v2 + 16) &= 0xF7FFFFFF;
                }
                else
                {
                    *(_DWORD*)(v2 + 88) = 0;
                    *(_DWORD*)(v2 + 92) = 0;
                    *(_DWORD*)(v2 + 80) = 0;
                    *(_DWORD*)(v2 + 84) = 0;
                    sub_4E46F0(v2, 0.0);
                    v10 = *(_DWORD*)(v2 + 56);
                    *(_DWORD*)(v2 + 68) = *(_DWORD*)(v2 + 60);
                    v11 = *(_DWORD*)(v2 + 16);
                    *(_DWORD*)(v2 + 64) = v10;
                    v12 = *(_DWORD*)(v2 + 744);
                    *(_DWORD*)(v2 + 108) = 0;
                    *(_DWORD*)(v2 + 16) = v11 | 0x8000000;
                    if (!v12)
                        sub_4DA920((_DWORD*)v2);
                }
            }
            v2 = v3;
        } while (v3);
    }
    for (j = sub_4DA840(); j; j = sub_4DA850(j))
    {
        if (!(*(_BYTE*)(j + 16) & 0x22))
        {
            v14 = *(void(__cdecl * *)(int))(j + 744);
            if (v14)
                v14(j);
            sub_51B870(j);
            sub_51B810(j);
            sub_537770(j);
            v15 = *(_DWORD*)(j + 56);
            v16 = *(_DWORD*)(j + 60);
            *(_WORD*)(j + 124) = *(_WORD*)(j + 126);
            v17 = *(_DWORD*)(j + 64);
            *(_DWORD*)(j + 72) = v15;
            v18 = *(_DWORD*)(j + 68);
            *(_DWORD*)(j + 56) = v17;
            *(_DWORD*)(j + 76) = v16;
            *(_DWORD*)(j + 60) = v18;
            *(_DWORD*)(j + 88) = 0;
            *(_DWORD*)(j + 92) = 0;
            sub_517970(j);
        }
    }
    sub_511850();
    for (k = sub_4DA8A0(); k; k = sub_4DA8B0(k))
    {
        v20 = *(_DWORD*)(k + 64);
        v21 = *(_DWORD*)(k + 60);
        *(_DWORD*)(k + 72) = *(_DWORD*)(k + 56);
        v22 = *(_DWORD*)(k + 68);
        *(_DWORD*)(k + 56) = v20;
        LOBYTE(v20) = *(_BYTE*)(k + 541);
        *(_DWORD*)(k + 76) = v21;
        LOWORD(v21) = *(_WORD*)(k + 126);
        *(_DWORD*)(k + 60) = v22;
        *(_DWORD*)(k + 88) = 0;
        *(_DWORD*)(k + 92) = 0;
        *(_WORD*)(k + 124) = v21;
        if ((unsigned __int8)v20 > 4u)
            * (_BYTE*)(k + 541) = 4;
        *(float*)(k + 544) = (*(float*)(k + 552) + *(float*)(k + 548))
            * (5.0 - (double) * (unsigned __int8*)(k + 541))
            * 0.2;
        if (sub_4FF350(k, 4))
            * (float*)(k + 544) = *(float*)(k + 544) * 0.5;
        if (*(_BYTE*)(k + 541) || *(_BYTE*)(k + 540))
        {
            v23 = *(_WORD*)(k + 542);
            if (v23 > 0)
            {
                v24 = v23 - 1;
                *(_WORD*)(k + 542) = v24;
                if (!v24)
                {
                    v25 = *(_BYTE*)(k + 541);
                    if (v25)
                        * (_BYTE*)(k + 541) = v25 - 1;
                    if (*(_BYTE*)(k + 540))
                    {
                        v26 = *(_DWORD*)(k + 16);
                        if ((v26 & 0x8000) == 0)
                            sub_4EE8F0(k, 1);
                    }
                    *(_WORD*)(k + 542) = 1000;
                }
            }
        }
        sub_4FF620(k);
        if (*(_BYTE*)(k + 540))
        {
            v27 = *(_WORD * *)(k + 556);
            if (v27)
            {
                if (v27[2] > 0u && *v27 > 0u)
                {
                    v28 = sub_40A5C0(4096);
                    v29 = *(_DWORD*)(*(_DWORD*)(k + 556) + 16);
                    v30 = v28 + 1;
                    if (!v29 || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - v29) > 0x3C)
                    {
                        v31 = *(_BYTE*)(k + 540);
                        if (v31 > 8u || !(*(_DWORD*)& byte_5D4594[2598000] % (unsigned int)(128 >> (v31 - 1))))
                            (*(void(__cdecl * *)(int, _DWORD, _DWORD, int, int))(k + 716))(k, 0, 0, v30, 5);
                    }
                }
            }
        }
    }
    v32 = sub_410780();
    if (v32)
    {
        v33 = v60;
        while (v32)
        {
            switch (v32[21])
            {
            case 1:
                v47 = v32[20];
                if (v47 & 4)
                {
                    if ((v47 & 8) == 8)
                    {
                        v48 = *((_DWORD*)v32 + 6) - 1;
                        *((_DWORD*)v32 + 6) = v48;
                        if (!v48)
                        {
                            v49 = *((_DWORD*)v32 + 1);
                            v32[21] = 4;
                            v50 = 23 * v49;
                            v51 = *((_DWORD*)v32 + 2);
                            v52 = (double)(v50 + 11);
                            v53 = *((_DWORD*)v32 + 3);
                            v64.field_0 = v52;
                            v64.field_4 = (double)(23 * v51 + 11);
                            v54 = sub_410EE0(*(unsigned __int8*)(v53 + 1));
                            v55 = sub_40AF50(v54);
                            sub_501A30(v55, &v64, 0, 0);
                        }
                    }
                }
                goto LABEL_90;
            case 2:
                v36 = v32[22] - 1;
                v32[22] = v36;
                if (!v36)
                {
                    v37 = *((_DWORD*)v32 + 4);
                    v32[21] = 1;
                    *((_DWORD*)v32 + 6) = *(_DWORD*)& byte_5D4594[2649704] * v37;
                }
                v33 = 1;
                goto LABEL_92;
            case 3:
                v38 = v32[20];
                if (!(v38 & 4) || v38 & 8 || (v39 = *((_DWORD*)v32 + 6) - 1, (*((_DWORD*)v32 + 6) = v39) != 0))
                {
                LABEL_90:
                    v33 = 0;
                }
                else
                {
                    v40 = *((_DWORD*)v32 + 1);
                    v32[21] = 2;
                    v41 = 23 * v40;
                    v42 = *((_DWORD*)v32 + 2);
                    v43 = (double)(v41 + 11);
                    v44 = *((_DWORD*)v32 + 3);
                    v63.field_0 = v43;
                    v63.field_4 = (double)(23 * v42 + 11);
                    v45 = sub_410F20(*(unsigned __int8*)(v44 + 1));
                    v46 = sub_40AF50(v45);
                    sub_501A30(v46, &v63, 0, 0);
                    v33 = 0;
                }
                break;
            case 4:
                v34 = v32[22] + 1;
                v32[22] = v34;
                if (v34 == 23)
                {
                    v35 = *((_DWORD*)v32 + 4);
                    v32[21] = 3;
                    *((_DWORD*)v32 + 6) = *(_DWORD*)& byte_5D4594[2649704] * v35;
                }
                v33 = 1;
                goto LABEL_92;
            default:
                if (v33)
                {
                LABEL_92:
                    v56 = (double)(int)(23 * *((_DWORD*)v32 + 1)) + 11.5;
                    v65 = (double)(int)(23 * *((_DWORD*)v32 + 2)) + 11.5;
                    v66.field_0 = v56 - 42.5;
                    v66.field_4 = v65 - 42.5;
                    v66.field_8 = v56 + 42.5;
                    v66.field_C = v65 + 42.5;
                    sub_517C10(&v66, (void(__cdecl*)(float*, int))sub_51B860, 0);
                }
                break;
            }
            v32 = (_BYTE*)sub_410790((int*)v32);
        }
    }
    sub_511750();
    return sub_509A60();
}
// 51B5E7: variable 'v60' is possibly undefined

//----- (0051B810) --------------------------------------------------------
int __cdecl sub_51B810(int a1)
{
    float* v1; // eax
    double v2; // st7
    int v3; // edx
    double v4; // st7
    int v6; // [esp-4h] [ebp-4h]
    float v7; // [esp+4h] [ebp+4h]

    v1 = (float*)a1;
    v6 = a1;
    v2 = *(float*)(a1 + 88) + *(float*)(a1 + 80);
    v3 = *(_DWORD*)(a1 + 68);
    *(_DWORD*)(a1 + 56) = *(_DWORD*)(a1 + 64);
    *(_DWORD*)(a1 + 60) = v3;
    v4 = v2 * *(float*)(a1 + 112);
    *(float*)(a1 + 80) = v4;
    v7 = (v1[23] + v1[21]) * v1[28];
    v1[21] = v7;
    v1[16] = v4 + v1[16];
    v1[17] = v7 + v1[17];
    return sub_4E7290(v6);
}

//----- (0051B860) --------------------------------------------------------
char __cdecl sub_51B860(int a1)
{
    return sub_537610(a1);
}

//----- (0051B870) --------------------------------------------------------
void __cdecl sub_51B870(int a1)
{
    int v1; // esi
    int v2; // ecx
    double v3; // st7
    double v4; // st7
    double v5; // st7
    double v6; // st6
    long double v7; // st6
    double v8; // st7
    double v9; // st7
    float v10; // [esp+0h] [ebp-14h]
    float v11; // [esp+0h] [ebp-14h]
    float v12; // [esp+0h] [ebp-14h]
    float v13; // [esp+10h] [ebp-4h]
    int v14; // [esp+18h] [ebp+4h]

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 16);
    v3 = *(float*)(a1 + 104);
    if (v2 & 0x40000)
    {
        v10 = v3 + *(float*)(a1 + 108);
        sub_4E46F0(a1, v10);
        v4 = *(float*)(a1 + 108) - 1.0;
        *(_DWORD*)(a1 + 88) = 0;
        *(_DWORD*)(a1 + 92) = 0;
        *(_DWORD*)(a1 + 80) = 0;
        *(_DWORD*)(a1 + 84) = 0;
        *(float*)(a1 + 108) = v4;
        v5 = *(float*)(a1 + 56) - *(float*)(a1 + 156);
        v6 = *(float*)(a1 + 60) - *(float*)(a1 + 160);
        v13 = v6;
        v7 = sqrt(v6 * v13 + v5 * v5);
        *(float*)& v14 = v7;
        if (v7 > 0.0)
        {
            *(float*)(v1 + 88) = v5 * -3.0 / *(float*)& v14;
            *(float*)(v1 + 92) = v13 * -3.0 / *(float*)& v14;
        }
        if (*(float*)(v1 + 104) < -50.0)
        {
            sub_4E46F0(v1, 90.0);
            *(_DWORD*)(v1 + 16) &= 0xFFFBFFFF;
            sub_4E7010(v1, (float2*)(v1 + 164));
        }
    }
    else if (v3 != 0.0 || *(float*)(a1 + 108) != 0.0)
    {
        if (0x800000 & v2)
        {
            v11 = *(float*)(a1 + 104) + *(float*)(a1 + 108);
            sub_4E46F0(a1, v11);
            if (*(float*)(a1 + 104) >= 0.0)
            {
                *(float*)(a1 + 108) = *(float*)(a1 + 108) - 0.5;
            }
            else
            {
                sub_4E46F0(a1, 0.0);
                v8 = -*(float*)(a1 + 108) * *(float*)(a1 + 116) * 0.1;
                *(float*)(a1 + 108) = v8;
                if (v8 < 2.0)
                {
                    sub_4E46F0(a1, 0.0);
                    *(_DWORD*)(a1 + 108) = 0;
                }
            }
        }
        else if (!(v2 & 0x100000))
        {
            if (*(float*)(a1 + 104) > 0.0)
            {
                if (*(float*)(a1 + 108) <= 0.0)
                    * (_DWORD*)(a1 + 16) = v2 | 0x20000;
                v12 = *(float*)(a1 + 104) + *(float*)(a1 + 108);
                sub_4E46F0(a1, v12);
                *(float*)(a1 + 108) = *(float*)(a1 + 108) - 1.0;
            }
            if (*(float*)(a1 + 104) <= 0.0)
            {
                v9 = *(float*)(a1 + 108);
                *(_DWORD*)(a1 + 16) &= 0xFFFDFFFF;
                if (v9 < 0.0 && !(*(_BYTE*)(a1 + 8) & 1))
                {
                    sub_537610(a1);
                    if (*(float*)(a1 + 108) < -10.0)
                    {
                        if (*(_BYTE*)(a1 + 8) & 4)
                            sub_501960(280, a1, 0, 0);
                    }
                }
                sub_4E46F0(a1, 0.0);
                *(_DWORD*)(a1 + 108) = 0;
            }
        }
    }
}

//----- (0051BAC0) --------------------------------------------------------
void sub_51BAC0()
{
    nox_srand(0x2308u);
}

//----- (0051BAD0) --------------------------------------------------------
int __cdecl sub_51BAD0(int a1, unsigned __int8* a2, signed int a3)
{
    unsigned __int8* v4; // esi
    char* v5; // eax
    char* v6; // eax
    int v7; // edx
    int v8; // ebx
    int v9; // ebp
    int* v10; // edi
    char* v11; // ecx
    unsigned __int16 v12; // ax
    int v13; // ecx
    int v14; // ecx
    int v15; // edi
    int v16; // eax
    int v17; // edi
    int v18; // eax
    int v19; // edi
    int v20; // eax
    unsigned __int16 v21; // dx
    int v22; // edi
    int v23; // ebx
    int v24; // edi
    int i; // eax
    int v26; // edi
    int v27; // eax
    int v28; // edi
    int v29; // eax
    void(__cdecl * v30)(int, int, _DWORD); // ecx
    int v31; // edi
    int v32; // eax
    BOOL v33; // edi
    int v34; // edi
    int v35; // eax
    int* v36; // edi
    int v37; // ebx
    _DWORD* v38; // eax
    int v39; // ecx
    int v40; // ebx
    int v41; // eax
    wchar_t* v42; // eax
    wchar_t* v43; // eax
    int v44; // eax
    int v45; // edi
    _DWORD* v46; // eax
    _DWORD* v47; // ebx
    int v48; // ebx
    char* v49; // ebp
    char* j; // ebp
    int v51; // eax
    char* v52; // eax
    int v53; // edi
    char* v54; // eax
    char* v55; // edi
    int v56; // eax
    int v57; // eax
    int v58; // edi
    int v59; // eax
    int v60; // ebx
    int v61; // edi
    unsigned __int8 v62; // al
    _DWORD* v63; // eax
    int v64; // eax
    int v65; // eax
    int v66; // eax
    int v67; // edi
    int* v68; // edi
    int v69; // eax
    int v70; // edi
    int v71; // eax
    _DWORD* v72; // eax
    int v73; // eax
    int v74; // eax
    int v75; // eax
    int v76; // eax
    int v77; // eax
    int v78; // eax
    unsigned __int8 v79; // al
    int v80; // eax
    int v81; // ecx
    unsigned int v82; // [esp-8h] [ebp-65Ch]
    float v83; // [esp+0h] [ebp-654h]
    float v84; // [esp+4h] [ebp-650h]
    int v85; // [esp+18h] [ebp-63Ch]
    char* v86; // [esp+1Ch] [ebp-638h]
    char v87[2]; // [esp+22h] [ebp-632h]
    char v88[4]; // [esp+24h] [ebp-630h]
    char* v89; // [esp+28h] [ebp-62Ch]
    char v90[6]; // [esp+2Ch] [ebp-628h]
    unsigned __int8* v91; // [esp+34h] [ebp-620h]
    char v92[5]; // [esp+38h] [ebp-61Ch]
    int v93; // [esp+40h] [ebp-614h]
    float2 v94; // [esp+44h] [ebp-610h]
    float2 v96; // [esp+4Ch] [ebp-608h]
    wchar_t v97[256]; // [esp+54h] [ebp-600h]
    CHAR FileName[1024]; // [esp+254h] [ebp-400h]

    // mix patch
    int vU101[2]; // ebp

    if (a3)
    {
        //	OutputDebugStringA("S -> ");
        //    dhexdump((_BYTE*)a2, a3);
    }

    if (a3 <= 0)
    {
        *((_DWORD*)sub_417090(a1) + 899) = *(_DWORD*)& byte_5D4594[2598000];
        return 1;
    }
    v4 = a2;
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x200000)
    {
        v5 = sub_417090(a1);
        sub_4D3450((int)v5, a2, a3);
    }
    switch (*a2)
    {
    case 0x20u:
        if (!sub_4DD320(a1, (int)(a2 + 1)))
            sub_5545B0(a1 + 1);
        return 1;
    case 0x22u:
        sub_4DE7C0(a1);
        return 1;
    case 0x25u:
        *((_DWORD*)sub_417090(a1) + 899) = *(_DWORD*)& byte_5D4594[2598000];
        return 1;
    }
    v91 = &a2[a3];
    v6 = sub_417090(a1);
    v8 = (int)v6;
    v89 = v6;
    if (!v6)
        return 1;
    v93 = *((_DWORD*)v6 + 514);
    v9 = v93;
    if (!v93)
        return 1;
    v10 = *(int**)(v93 + 748);
    v85 = *(_DWORD*)(v93 + 748);
    if (a2 < v91)
    {
        while (v4 < v91)
        {
            v11 = 0;
            switch (*v4)
            {
            case 0x26u:
                goto LABEL_272;
            case 0x29u:
                sub_4174F0(v8, 64);
                ++v4;
                goto LABEL_273;
            case 0x3Fu:
                v4 += sub_51A960(*(unsigned __int8*)(v10[69] + 2064), v4 + 1) + 1;
                goto LABEL_273;
            case 0x40u:
                v84 = (double) * (unsigned __int16*)(v4 + 5);
                v83 = (double) * (unsigned __int16*)(v4 + 3);
                sub_4F79A0(v9, SLODWORD(v83), SLODWORD(v84));
                v4 += 7;
                goto LABEL_273;
            case 0x72u:
                v19 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                v7 = *(_DWORD*)(v85 + 276);
                if (!(*(_BYTE*)(v7 + 3680) & 3)
                    && !*(_DWORD*)(v85 + 280)
                    && !*(_DWORD*)(v85 + 284)
                    && !(*(_BYTE*)(v9 + 16) & 2))
                {
                    v20 = sub_4F7920(v9, v19);
                    if (v20)
                    {
                        v21 = *(_WORD*)(v4 + 5);
                        v94.field_0 = (double) * (unsigned __int16*)(v4 + 3);
                        v94.field_4 = (double)v21;
                        sub_4ED810(v9, v20, &v94);
                    }
                }
                v10 = (int*)v85;
                v4 += 7;
                goto LABEL_273;
            case 0x73u:
                v22 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                if (sub_4DB1B0())
                    goto LABEL_55;
                v7 = *(_DWORD*)(v85 + 276);
                if (*(_BYTE*)(v7 + 3680) & 3)
                    goto LABEL_55;
                if (*(_DWORD*)(v85 + 280))
                    goto LABEL_55;
                if (*(_DWORD*)(v85 + 284))
                    goto LABEL_55;
                if (*(_BYTE*)(v9 + 16) & 2)
                    goto LABEL_55;
                v23 = sub_4ECCB0(v22);
                if (!v23)
                    goto LABEL_55;
                v24 = 0;
                for (i = sub_4E7980(v9); i; i = sub_4E7990(i))
                    v24 += *(unsigned __int8*)(i + 488);
                if (v24 + *(unsigned __int8*)(v23 + 488) <= *(unsigned __int16*)(v9 + 490))
                {
                    //sub_4F36F0(v9, v23, 1, 1);
                    vU101[0] = v9;
                    vU101[1] = v23;
                    OnLibraryNotice(420, vU101, v9, v23);
                LABEL_55:
                    v8 = (int)v89;
                    v10 = (int*)v85;
                    v4 += 3;
                }
                else
                {
                    sub_4DA2C0(v9, "pickup.c:CarryingTooMuch", 0);
                    v8 = (int)v89;
                    v10 = (int*)v85;
                    v4 += 3;
                }
                goto LABEL_273;
            case 0x74u:
                v26 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                if (sub_4DB1B0())
                    goto LABEL_196;
                v7 = *(_DWORD*)(v85 + 276);
                if (*(_BYTE*)(v7 + 3680) & 3)
                    goto LABEL_196;
                v27 = sub_4F7920(v9, v26);
                if (!v27)
                    goto LABEL_196;
                sub_53F8E0(v9, v27);
                v10 = (int*)v85;
                v4 += 3;
                goto LABEL_273;
            case 0x75u:
                v15 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                if (sub_4DB1B0())
                    goto LABEL_196;
                v7 = v85;
                if (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3)
                    goto LABEL_196;
                v16 = sub_4F7920(v9, v15);
                if (!v16)
                    goto LABEL_196;
                sub_4F2F70((_DWORD*)v9, v16);
                v10 = (int*)v85;
                v4 += 3;
                goto LABEL_273;
            case 0x76u:
                v17 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                if (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3)
                    goto LABEL_196;
                v18 = sub_4F7920(v9, v17);
                if (!v18)
                    goto LABEL_196;
                v7 = v85;
                if (*(_BYTE*)(v85 + 88) == 1 && *(_DWORD*)(v18 + 8) & 0x1000000 && *(_BYTE*)(v18 + 12) & 8)
                    goto LABEL_196;
                sub_4F2FB0((_DWORD*)v9, v18);
                v10 = (int*)v85;
                v4 += 3;
                goto LABEL_273;
            case 0x78u:
                v31 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                v7 = v85;
                if (!(*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 1))
                {
                    if (*(_WORD*)(v4 + 1))
                    {
                        v32 = sub_4ECCB0(v31);
                        if (v32)
                            sub_533900(v9, v32, v4[3]);
                    }
                    else
                    {
                        sub_533900(v9, 0, v4[3]);
                    }
                }
                v10 = (int*)v85;
                v4 += 4;
                goto LABEL_273;
            case 0x79u:
                v34 = 1;
                if (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 1)
                {
                    sub_4DA2C0(v9, "GeneralPrint:NoSpellWarningGeneral", 0);
                    v34 = 0;
                }
                if (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 2)
                {
                    sub_4DA2C0(v9, "GeneralPrint:ConjureNoSpellWarning1", 0);
                    v34 = 0;
                }
                if (!sub_40A5C0(2048))
                {
                    v35 = *(_DWORD*)(v9 + 16);
                    if (v35 & 0x4000)
                        v34 = 0;
                }
                if (!sub_40A5C0(128) && v34)
                {
                    v36 = (int*)(v4 + 1);
                    v37 = 0;
                    v38 = v4 + 1;
                    v39 = 5;
                    do
                    {
                        if (*v38)
                            ++v37;
                        ++v38;
                        --v39;
                    } while (v39);
                    if ((v37 != 1
                        || !sub_424A50(*v36, 32)
                        || !*(_DWORD*)(v85 + 288)
                        || sub_5330C0(v9, *(_DWORD*)(v85 + 288))
                        || sub_40A5C0(4096))
                        && !sub_4FE340(v9, (int*)(v4 + 1), v37, 3, v4[21])
                        && v37 == 1)
                    {
                        v40 = 5;
                        do
                        {
                            if (*v36)
                                sub_4D9630(*(unsigned __int8*)(*(_DWORD*)(v85 + 276) + 2064), *v36, 0);
                            ++v36;
                            --v40;
                        } while (v40);
                    }
                }
                v8 = (int)v89;
                v10 = (int*)v85;
                v4 += 22;
                goto LABEL_273;
            case 0x7Au:
                v33 = (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3) == 0;
                if (!sub_40A5C0(128) && v33)
                    sub_4FBB70(v9, v4[1]);
                v10 = (int*)v85;
                v4 += 2;
                goto LABEL_273;
            case 0x7Bu:
                v28 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                v7 = v85;
                if (!(*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3) && !*(_DWORD*)(v85 + 280) && !*(_DWORD*)(v85 + 284))
                {
                    v29 = sub_4ECCB0(v28);
                    if (v29)
                    {
                        v30 = *(void(__cdecl * *)(int, int, _DWORD))(v29 + 696);
                        if (v30)
                            v30(v29, v9, 0);
                    }
                }
                v10 = (int*)v85;
                v4 += 3;
                goto LABEL_273;
            case 0xA5u:
                *(_WORD*)(v8 + 8 * v4[1] + 16) = *((_WORD*)v4 + 1);
                *(_WORD*)(v8 + 8 * v4[1] + 18) = *((_WORD*)v4 + 2);
                v14 = v4[1];
                v7 = *(_DWORD*)(v4 + 6);
                v4 += 10;
                *(_DWORD*)(v8 + 8 * v14 + 20) = v7;
                goto LABEL_273;
            case 0xA8u:
                if (v4[3] & 2)
                {
                    nox_swprintf(v97, L"%S", v4 + 11);
                    v44 = 1;
                }
                else
                {
                    nox_wcscpy(v97, (const wchar_t*)(v4 + 11));
                    v44 = 2;
                }
                v45 = v44 * v4[8] + 11;
                if (sub_57A190(v8))
                    goto LABEL_139;
                if (!(v4[3] & 1))
                {
                    for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
                    {
                        if (sub_40A5C0(2) && j[2064] == 31)
                        {
                            sub_48EA70(31, (unsigned int)v4, v45);
                        }
                        else
                        {
                            sub_552640((unsigned __int8)j[2064] + 1, v4, v45, 0);
                            sub_5528B0((unsigned __int8)j[2064] + 1, 1);
                        }
                    }
                LABEL_139:
                    v9 = v93;
                    v8 = (int)v89;
                    v4 += v45;
                    v10 = (int*)v85;
                    goto LABEL_273;
                }
                v46 = sub_418C80(*(unsigned __int16*)(v4 + 1));
                v47 = v46;
                if (!v46)
                    goto LABEL_139;
                if (!sub_419130((int)v46))
                    goto LABEL_139;
                v86 = sub_418AB0(*((unsigned __int8*)v47 + 4));
                if (!v86)
                    goto LABEL_139;
                v48 = sub_4DA7C0();
                if (!v48)
                    goto LABEL_139;
                do
                {
                    v49 = sub_417040(*(_DWORD*)(v48 + 36));
                    if (v49 && sub_419180(v48 + 48, v86[57]))
                    {
                        if (sub_40A5C0(2) && *(_DWORD*)(v48 + 36) == *(_DWORD*)& byte_5D4594[2616328])
                        {
                            sub_48EA70((unsigned __int8)v49[2064], (unsigned int)v4, v45);
                        }
                        else
                        {
                            sub_552640((unsigned __int8)v49[2064] + 1, v4, v45, 0);
                            sub_5528B0((unsigned __int8)v49[2064] + 1, 1);
                        }
                    }
                    v48 = sub_4DA7F0(v48);
                } while (v48);
                v9 = v93;
                v8 = (int)v89;
                v4 += v45;
                v10 = (int*)v85;
            LABEL_273:
                break;
            case 0xAAu:
                v13 = v10[69];
                *(_DWORD*)& v92[1] = *(_DWORD*)(v4 + 1);
                v92[0] = -85;
                sub_40EBC0(*(unsigned __int8*)(v13 + 2064), 1, v92, 5);
                v4 += 5;
                goto LABEL_273;
            case 0xABu:
                sub_4E55A0(*(_BYTE*)(v10[69] + 2064), *(_DWORD*)(v4 + 1));
                v4 += 5;
                goto LABEL_273;
            case 0xACu:
                v12 = *(_WORD*)(v4 + 1);
                v4 += 5;
                *(_DWORD*)(v8 + 2284) = v12;
                *(_DWORD*)(v8 + 2288) = *((unsigned __int16*)v4 - 1);
                goto LABEL_273;
            case 0xADu:
                sub_4DDF60(*(unsigned __int8*)(v8 + 2064));
                ++v4;
                goto LABEL_273;
            case 0xAEu:
                sub_4DE530(*(unsigned __int8*)(v8 + 2064), 2);
                ++v4;
                goto LABEL_273;
            case 0xB6u:
                sub_4E6860(v8, 1, 1);
                v51 = *(_DWORD*)(v8 + 2056);
                if (v51)
                    sub_419570(v51 + 48, *(_DWORD*)(v8 + 2060));
                sub_519D20(*(unsigned __int8*)(v8 + 2064));
                ++v4;
                goto LABEL_273;
            case 0xB7u:
                sub_519DE0(*(unsigned __int8*)(v8 + 2064));
                ++v4;
                goto LABEL_273;
            case 0xBBu:
                sub_443E90(v8, v4[1], (wchar_t*)(v4 + 5));
                v4 += 2 * v4[4] + 7;
                goto LABEL_273;
            case 0xBCu:
                v87[0] = -67;
                v42 = sub_40A630();
                if (!*v42 || _nox_wcsicmp((const wchar_t*)(v4 + 1), v42))
                {
                    v87[1] = 0;
                }
                else
                {
                    v87[1] = 1;
                    if (!sub_4D12A0(*(unsigned __int8*)(v8 + 2064)))
                    {
                        sub_4D1210(*(unsigned __int8*)(v8 + 2064));
                        v43 = loadString_sub_40F1D0((char*)& byte_587000[253012], 0, "C:\\NoxPost\\src\\Server\\Network\\sdecode.c", 735);
                        sub_450C00(6u, v43, v8 + 4704);
                    }
                }
                sub_4E5420(*(unsigned __int8*)(v8 + 2064), v87, 2, 0, 1);
                v4 += 21;
                goto LABEL_273;
            case 0xBEu:
                goto LABEL_166;
            case 0xBFu:
                *(_BYTE*)(v8 + 3676) = 3;
                sub_519E80(*(unsigned __int8*)(v8 + 2064));
                ++v4;
                goto LABEL_273;
            case 0xC0u:
                sub_4DD180(*(unsigned __int8*)(v8 + 2064));
            LABEL_166:
                ++v4;
                goto LABEL_273;
            case 0xC1u:
                if (sub_40A5C0(4096)
                    && *(_BYTE*)(v8 + 2064) != 31
                    && *(_DWORD*)(v8 + 2092)
                    && *(_DWORD*)(v8 + 2056)
                    && v10[138] == 1)
                {
                    sub_4DEAB0(*(unsigned __int8*)(v8 + 2064), 2);
                    v4 += 3;
                }
                else
                {
                    v52 = sub_409E10();
                    nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v52);
                    if (sub_41A140(FileName, *(unsigned __int8*)(v8 + 2064)))
                        sub_41CFA0(FileName, *(unsigned __int8*)(v8 + 2064));
                    DeleteFileA(FileName);
                    v4 += 3;
                }
                goto LABEL_273;
            case 0xC2u:
                switch (v4[1])
                {
                case 0u:
                    sub_40B5D0(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], (const char*)v4 + 8, *((_DWORD*)v4 + 1), v4[136]);
                    v4 += 140;
                    break;
                case 1u:
                    LOBYTE(v11) = v4[3];
                    sub_40BFF0(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], v11);
                    v4 += 4;
                    break;
                case 2u:
                    v90[0] = -62;
                    v90[1] = 3;
                    v90[2] = v4[2];
                    v82 = *(unsigned __int8*)(v8 + 2064) + 1;
                    *(_WORD*)& v90[4] = *((_WORD*)v4 + 2);
                    sub_552640(v82, v90, 6, 3);
                    sub_40B250(
                        *(unsigned __int8*)(v8 + 2064) + 1,
                        v4[2],
                        *((_WORD*)v4 + 2),
                        v4 + 8,
                        *((unsigned __int16*)v4 + 3));
                    v4 += *((unsigned __int16*)v4 + 3) + 8;
                    break;
                case 3u:
                    sub_40BF60(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], *((unsigned __int16*)v4 + 2));
                    v4 += 6;
                    break;
                case 4u:
                    sub_40C030(*(unsigned __int8*)(v8 + 2064) + 1, v4[2]);
                    v4 += 3;
                    break;
                case 5u:
                    LOBYTE(v7) = v4[3];
                    sub_40B720(v7, v4[2]);
                    v4 += 4;
                    break;
                case 6u:
                    LOBYTE(v11) = v4[3];
                    sub_40C070(*(unsigned __int8*)(v8 + 2064) + 1, (int)v11, v4[2]);
                    v4 += 4;
                    break;
                default:
                    goto LABEL_273;
                }
                goto LABEL_273;
            case 0xC4u:
                if (v4[1] == 10)
                {
                    v55 = sub_418AB0(*(_DWORD*)(v4 + 2));
                    if (v55)
                    {
                        v56 = sub_4ECCB0(*((unsigned __int16*)v4 + 3));
                        sub_4191D0(v55[57], v56 + 48, 1, *((unsigned __int16*)v4 + 3), 1);
                    }
                    v10 = (int*)v85;
                    v4 += 10;
                }
                else if (v4[1] == 11)
                {
                    v53 = sub_4ECCB0(*((unsigned __int16*)v4 + 3));
                    if (v53)
                    {
                        if (!sub_40A5C0(128))
                        {
                            sub_4F7AB0(&v96, v53);
                            sub_4E7010(v53, &v96);
                        }
                        v54 = sub_418AB0(*(_DWORD*)(v4 + 2));
                        if (v54)
                            sub_4196D0(v53 + 48, (int)v54, *((unsigned __int16*)v4 + 3), 1);
                    }
                    v10 = (int*)v85;
                    v4 += 10;
                }
                goto LABEL_273;
            case 0xC8u:
                sub_446070();
                ++v4;
                goto LABEL_273;
            case 0xC9u:
                goto LABEL_226;
            case 0xD0u:
                if (v4[1] == 1)
                {
                    if (sub_4DB1B0()
                        || (v7 = v10[69], *(_BYTE*)(v7 + 3680) & 3)
                        || (v57 = sub_4ECCB0(*((unsigned __int16*)v4 + 1))) == 0)
                    {
                    LABEL_232:
                        v4 += 4;
                    }
                    else
                    {
                        sub_548CD0(v9, v57);
                        v4 += 4;
                    }
                }
                else if (v4[1] == 2)
                {
                    sub_548D30(v9, v4[2]);
                    v4 += 3;
                }
                goto LABEL_273;
            case 0xD4u:
                v41 = sub_40A220();
                sub_4D8F50(a1, v41);
                ++v4;
                goto LABEL_273;
            case 0xE0u:
                v58 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                if (*(_WORD*)(v4 + 1))
                {
                    v59 = sub_4ECCB0(v58);
                    sub_53AB90(v9, v59);
                    v10 = (int*)v85;
                    v4 += 3;
                }
                else
                {
                    sub_53AB90(v9, 0);
                LABEL_196:
                    v10 = (int*)v85;
                    v4 += 3;
                }
                goto LABEL_273;
            case 0xE2u:
                v60 = sub_578B40(*(unsigned __int16*)(v4 + 1));
                if ((byte_5D4594[2650637] & 0x80u) != 0)
                    sub_578B70(*(unsigned __int16*)(v4 + 1));
                v61 = sub_4F7920(v9, v60);
                if (v61 || (v61 = sub_510DE0(v9, v60)) != 0 || (v61 = sub_4ECCB0(v60)) != 0)
                {
                    v88[0] = -30;
                    *(_WORD*)& v88[1] = sub_578AC0((_DWORD*)v61);
                    v62 = v4[3];
                    if (v62 == 1)
                    {
                        v88[3] = **(_BYTE * *)(v61 + 736);
                    }
                    else if (v62 == 2)
                    {
                        v88[3] = sub_427010(*(const char**)(v61 + 736));
                    }
                    else
                    {
                        v88[3] = **(_BYTE * *)(v61 + 736);
                    }
                    sub_4E5420(*(unsigned __int8*)(*(_DWORD*)(v85 + 276) + 2064), v88, 4, 0, 1);
                }
                v8 = (int)v89;
                v10 = (int*)v85;
                v4 += 4;
                goto LABEL_273;
            case 0xE3u:
                switch (v4[1])
                {
                case 1u:
                    sub_4FA020((_DWORD*)v9, 26);
                    break;
                case 2u:
                    sub_4FA020((_DWORD*)v9, 25);
                    break;
                case 4u:
                    sub_4FA020((_DWORD*)v9, 27);
                    break;
                default:
                    goto LABEL_273;
                }
                goto LABEL_272;
            case 0xEEu:
                switch (v4[1])
                {
                case 0u:
                    if (sub_40A5C0(4096))
                        sub_506870(3, v9, (wchar_t*)v4 + 1);
                    else
                        sub_506870(0, v9, (wchar_t*)v4 + 1);
                    v4 += 52;
                    goto LABEL_226;
                case 1u:
                    sub_506870(1, v9, (wchar_t*)v4 + 1);
                    v4 += 52;
                    goto LABEL_226;
                case 2u:
                    if (sub_40A5C0(4096))
                        sub_506C90(3, v9, (wchar_t*)v4 + 1);
                    else
                        sub_506C90(0, v9, (wchar_t*)v4 + 1);
                    v4 += 52;
                    goto LABEL_226;
                case 3u:
                    sub_506C90(1, v9, (wchar_t*)v4 + 1);
                    v4 += 52;
                    goto LABEL_226;
                case 4u:
                    sub_506870(2, v9, 0);
                    break;
                case 5u:
                    sub_506C90(2, v9, 0);
                    break;
                default:
                    return 0;
                }
                v4 += 2;
            LABEL_226:
                switch (v4[1])
                {
                case 0xEu:
                    if (v10[70])
                        sub_50F3A0((_DWORD*)v10[70]);
                    goto LABEL_272;
                case 0xFu:
                    v67 = sub_578B40(*((unsigned __int16*)v4 + 1));
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*((unsigned __int16*)v4 + 1));
                    v68 = (int*)sub_4F7920(v9, v67);
                    if (v68)
                    {
                        v69 = *(_DWORD*)(v85 + 280);
                        if (v69)
                        {
                            if (sub_50F820(v69, v9, *(float*)& v68) == 1)
                                sub_4ED0C0(v9, v68);
                        }
                    }
                    goto LABEL_243;
                case 0x10u:
                    v70 = sub_578B40(*((unsigned __int16*)v4 + 1));
                    if ((byte_5D4594[2650637] & 0x80u) != 0)
                        sub_578B70(*((unsigned __int16*)v4 + 1));
                    v71 = *(_DWORD*)(v85 + 280);
                    if (v71)
                    {
                        sub_50FE20(v71, v70);
                        v10 = (int*)v85;
                        v4 += 4;
                    }
                    else
                    {
                    LABEL_243:
                        v10 = (int*)v85;
                        v4 += 4;
                    }
                    goto LABEL_273;
                case 0x11u:
                    v66 = v10[70];
                    if (v66)
                        sub_50F5A0(v66, v9);
                    goto LABEL_272;
                case 0x12u:
                    if (v10[70])
                        sub_50F4C0((_DWORD*)v10[70]);
                    goto LABEL_272;
                case 0x15u:
                    if (!sub_4DB1B0() && !(*(_BYTE*)(v10[69] + 3680) & 3))
                    {
                        v64 = sub_578B40(*((unsigned __int16*)v4 + 1));
                        v65 = sub_4ECCB0(v64);
                        if (v65)
                        {
                            if (*(_BYTE*)(v65 + 12) & 8)
                                sub_50EF10(v9, v65);
                        }
                    }
                    goto LABEL_232;
                case 0x16u:
                    v72 = (_DWORD*)v10[70];
                    if (v72)
                        sub_5100C0(v9, v72, *((unsigned __int16*)v4 + 1));
                    goto LABEL_252;
                case 0x17u:
                    v73 = v10[70];
                    if (v73)
                        sub_510640(v9, v73, *((unsigned __int16*)v4 + 1), (float*)v4[4]);
                    goto LABEL_255;
                case 0x18u:
                    v74 = v10[70];
                    if (!v74)
                        goto LABEL_252;
                    sub_510BE0((int*)v9, v74, (_DWORD*) * ((unsigned __int16*)v4 + 1));
                    v4 += 4;
                    goto LABEL_273;
                case 0x19u:
                    v76 = v10[70];
                    if (v76)
                    {
                        sub_510D10((int*)v9, v76, *((unsigned __int16*)v4 + 1), v4[4]);
                        v4 += 5;
                    }
                    else
                    {
                    LABEL_255:
                        v4 += 5;
                    }
                    goto LABEL_273;
                case 0x1Au:
                    v75 = v10[70];
                    if (!v75)
                        goto LABEL_252;
                    sub_510AE0((int*)v9, v75, (_DWORD*) * ((unsigned __int16*)v4 + 1));
                    v4 += 4;
                    break;
                case 0x1Cu:
                    v77 = v10[70];
                    if (!v77)
                        goto LABEL_252;
                    sub_5109C0((int*)v9, v77, (_DWORD*) * ((unsigned __int16*)v4 + 1));
                    v4 += 4;
                    break;
                case 0x1Eu:
                    v78 = v10[70];
                    if (v78)
                    {
                        sub_5108D0(v9, v78, *((unsigned __int16*)v4 + 1));
                        v4 += 4;
                    }
                    else
                    {
                    LABEL_252:
                        v4 += 4;
                    }
                    break;
                default:
                    return 0;
                }
                goto LABEL_273;
            case 0xF0u:
                v79 = v4[1];
                if (v79 == 3)
                {
                    v80 = v10[69];
                    v81 = *(_DWORD*)(v80 + 2056);
                    if (v81)
                    {
                        v7 = *(_DWORD*)(v81 + 16);
                        if ((v7 & 0x8000) != 0)
                        {
                            v10[137] = 0;
                            sub_4F7EF0(*(_DWORD*)(v80 + 2056));
                        }
                    }
                }
                else
                {
                    if (v79 != 27)
                        goto LABEL_273;
                    sub_4DD0B0(v9);
                }
            LABEL_272:
                v4 += 2;
                goto LABEL_273;
            case 0xF1u:
                v63 = (_DWORD*)sub_4F7920(v9, *(unsigned __int16*)(v4 + 1));
                if (v63)
                {
                    sub_4ED790(v9, v63, (float2*)(v9 + 56));
                    sub_4DA2C0(v9, "pickup.c:CarryingTooMuch", 0);
                }
                v4 += 3;
                goto LABEL_273;
            default:
                return 0;
            }
        }
    }
    *(_DWORD*)(v8 + 3596) = *(_DWORD*)& byte_5D4594[2598000];
    return 1;
}
// 51C788: variable 'v7' is possibly undefined

//----- (0051D0D0) --------------------------------------------------------
void sub_51D0D0()
{
    nox_srand(0x2309u);
}

//----- (0051D0E0) --------------------------------------------------------
void sub_51D0E0()
{
    *(_DWORD*)& byte_5D4594[2487244] = 0;
}

//----- (0051D0F0) --------------------------------------------------------
int __cdecl sub_51D0F0(char a1)
{
    byte_5D4594[3835400] = a1;
    return 1;
}

//----- (0051D100) --------------------------------------------------------
int __cdecl sub_51D100(int a1)
{
    if (a1 != 1 && a1)
        return 0;
    *(_DWORD*)& byte_5D4594[3835404] = a1;
    return 1;
}

//----- (0051D120) --------------------------------------------------------
_DWORD* __cdecl sub_51D120(float* a1)
{
    _DWORD* result; // eax
    _DWORD* v2; // esi
    float2 v3; // [esp+4h] [ebp-8h]

    result = (float*)sub_4D3D90((float2*)a1, &v3);
    if (result)
    {
        result = sub_5798F0(v3.field_0, v3.field_4);
        v2 = result;
        if (result)
        {
            if (*(_DWORD*)& byte_5D4594[2487244])
            {
                if (*(_DWORD*)& byte_5D4594[3835404] == 1)
                {
                    sub_51D300(*(int*)& byte_5D4594[2487244], (int)result, byte_5D4594[3835400]);
                    sub_51D300((int)v2, *(int*)& byte_5D4594[2487244], byte_5D4594[3835400]);
                }
            }
            *(_DWORD*)& byte_5D4594[2487244] = v2;
            result = v2;
        }
    }
    return result;
}

//----- (0051D1A0) --------------------------------------------------------
float* __cdecl sub_51D1A0(float2* a1)
{
    float* result; // eax
    float2 a2; // [esp+0h] [ebp-8h]

    result = (float*)sub_4D3D90(a1, &a2);
    if (result)
        result = sub_579AD0(a2.field_0, a2.field_4);
    return result;
}

//----- (0051D1E0) --------------------------------------------------------
int __cdecl sub_51D1E0(LPVOID lpMem)
{
    LPVOID v1; // eax
    char* i; // esi
    int v4; // ebx
    char* v5; // edi

    if (!lpMem)
        return 0;
    v1 = sub_579860();
    if (!v1)
        return 0;
    while (v1 != lpMem)
    {
        v1 = (LPVOID)sub_579870((int)v1);
        if (!v1)
            return 0;
    }
    for (i = (char*)sub_579860(); i; i = (char*)sub_579870((int)i))
    {
        v4 = 0;
        if (i[476])
        {
            v5 = i + 96;
            do
            {
                if (*((LPVOID*)v5 - 1) == lpMem)
                    sub_51D370((int)i, (int)lpMem, *v5);
                ++v4;
                v5 += 8;
            } while (v4 < (unsigned __int8)i[476]);
        }
    }
    sub_579B30(lpMem);
    return 1;
}

//----- (0051D270) --------------------------------------------------------
float* __cdecl sub_51D270(float* a1)
{
    float* result; // eax
    float2 v2; // [esp+0h] [ebp-8h]

    result = (float*)sub_4D3D90((float2*)a1, &v2);
    if (result)
    {
        result = sub_579AD0(v2.field_0, v2.field_0);
        if (result)
            result = (float*)sub_51D1E0(result);
    }
    return result;
}

//----- (0051D2C0) --------------------------------------------------------
int __cdecl sub_51D2C0(int a1, int a2)
{
    return sub_51D300(a1, a2, byte_5D4594[3835400]);
}

//----- (0051D2E0) --------------------------------------------------------
int __cdecl sub_51D2E0(int a1, int a2)
{
    return sub_51D370(a1, a2, byte_5D4594[3835400]);
}

//----- (0051D300) --------------------------------------------------------
int __cdecl sub_51D300(int a1, int a2, char a3)
{
    unsigned __int8 v3; // al
    int v4; // ecx
    int v5; // esi
    _BYTE* v6; // eax

    v3 = *(_BYTE*)(a1 + 476);
    if (v3 >= 0x1Fu || a1 == a2)
        return 0;
    v4 = 0;
    v5 = v3;
    if ((int)v3 > 0)
    {
        v6 = (_BYTE*)(a1 + 96);
        do
        {
            if (*((_DWORD*)v6 - 1) == a2 && *v6 == a3)
                break;
            ++v4;
            v6 += 8;
        } while (v4 < v5);
    }
    if (v4 != v5)
        return 0;
    *(_DWORD*)(a1 + 8 * v5 + 92) = a2;
    *(_BYTE*)(a1 + 8 * (unsigned __int8)(*(_BYTE*)(a1 + 476))++ + 96) = a3;
    return 1;
}

//----- (0051D370) --------------------------------------------------------
int __cdecl sub_51D370(int a1, int a2, char a3)
{
    int v3; // eax
    int v4; // esi
    _BYTE* i; // ecx
    int v7; // ecx
    _DWORD* v8; // eax

    if (a1 == a2)
        return 0;
    v3 = 0;
    v4 = *(unsigned __int8*)(a1 + 476);
    if (v4 <= 0)
        return 0;
    for (i = (_BYTE*)(a1 + 96); *((_DWORD*)i - 1) != a2 || *i != a3; i += 8)
    {
        if (++v3 >= v4)
            return 0;
    }
    v7 = v3;
    if (v3 < v4 - 1)
    {
        v8 = (_DWORD*)(a1 + 8 * v3 + 92);
        do
        {
            ++v7;
            *v8 = v8[2];
            v8[1] = v8[3];
            v8 += 2;
        } while (v7 < *(unsigned __int8*)(a1 + 476) - 1);
    }
    --* (_BYTE*)(a1 + 476);
    return 1;
}

//----- (0051D3F0) --------------------------------------------------------
float2* __cdecl sub_51D3F0(float2* a1, float2* a2)
{
    float2* result; // eax
    float2* v3; // esi

    result = a1;
    if (a1)
    {
        if (a2)
        {
            result = (float2*)sub_51D1A0(a1);
            v3 = result;
            if (result)
            {
                result = (float2*)sub_51D1A0(a2);
                if (result)
                    result = (float2*)sub_51D2C0((int)v3, (int)result);
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (0051D440) --------------------------------------------------------
float* __cdecl sub_51D440(float* a1, float* a2)
{
    float* result; // eax
    float* v3; // esi

    result = a1;
    if (a1)
    {
        if (a2)
        {
            result = sub_51D1A0((float2*)a1);
            v3 = result;
            if (result)
            {
                result = sub_51D1A0((float2*)a2);
                if (result)
                    result = (float*)sub_51D2E0((int)v3, (int)result);
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (0051D490) --------------------------------------------------------
int __cdecl sub_51D490(char* a1)
{
    int v1; // edi
    const char* v2; // esi

    if (!a1)
        return -1;
    v1 = 0;
    v2 = (const char*)& byte_5D4594[2682188];
    while (_strcmpi(v2, a1))
    {
        v2 += 60;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[2692748])
            return -1;
    }
    return v1;
}

//----- (0051D4D0) --------------------------------------------------------
int __cdecl sub_51D4D0(char* a1)
{
    int v1; // ebx
    int v2; // edi
    const char* v3; // esi

    v1 = 0;
    v2 = 0;
    v3 = (const char*)& byte_5D4594[2682188];
    do
    {
        if (!_strcmpi(v3, a1))
        {
            v1 = 1;
            *(_DWORD*)& byte_5D4594[3835340] = v2;
        }
        v3 += 60;
        ++v2;
    } while ((int)v3 < (int)& byte_5D4594[2692748]);
    if (!_strcmpi(a1, "NONE"))
    {
        *(_DWORD*)& byte_5D4594[3835340] = 255;
        return 1;
    }
    if (v1)
        return 1;
    *(_DWORD*)& byte_5D4594[3835340] = 0;
    return 0;
}

//----- (0051D540) --------------------------------------------------------
int __cdecl sub_51D540(int a1)
{
    int result; // eax

    if (a1 < 0 || a1 >= 176)
    {
        *(_DWORD*)& byte_5D4594[3835340] = 0;
        result = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[3835340] = a1;
        result = 1;
    }
    return result;
}

//----- (0051D570) --------------------------------------------------------
int __cdecl sub_51D570(int a1)
{
    int result; // eax

    if (a1 <= byte_5D4594[60 * *(_DWORD*)& byte_5D4594[3835340] + 2682240]
        * byte_5D4594[60 * *(_DWORD*)& byte_5D4594[3835340] + 2682241]
        - 1)
    {
        *(_DWORD*)& byte_5D4594[3835348] = a1;
        result = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[3835348] = 0;
        result = 0;
    }
    return result;
}

//----- (0051D5C0) --------------------------------------------------------
int __cdecl sub_51D5C0(int a1)
{
    if (a1 != 1 && a1)
        return 0;
    *(_DWORD*)& byte_5D4594[3835344] = a1;
    return 1;
}

//----- (0051D5E0) --------------------------------------------------------
float* __cdecl sub_51D5E0(float* a1)
{
    float* result; // eax
    float2 v2; // [esp+0h] [ebp-8h]

    result = a1;
    if (a1)
    {
        if (*(_DWORD*)& byte_5D4594[3835340] == 255
            || (sub_4D3D90((float2*)a1, &v2), (result = (float*)sub_51D8F0(&v2)) != 0)
            && (*(_DWORD*)& byte_5D4594[3835364] != 1 || (result = (float*)sub_527380(&v2.field_0)) != 0))
        {
            result = (float*)1;
        }
    }
    return result;
}

//----- (0051D650) --------------------------------------------------------
float* __cdecl sub_51D650(float* a1)
{
    float* v1; // esi
    char v3[0x48]; // [esp+8h] [ebp-48h]

    qmemcpy(v3, sub_4D3C70(), 0x48u);
    sub_51D4D0((char*)& byte_587000[253096]);
    v1 = sub_51D5E0(a1);
    sub_4D3C50(v3);
    return v1;
}

//----- (0051D6A0) --------------------------------------------------------
int __cdecl sub_51D6A0(int a1)
{
    int result; // eax
    char v2[0x48]; // [esp+8h] [ebp-48h]

    if (!a1)
        return 0;
    if (!*(_DWORD*)a1)
        return 0;
    qmemcpy(v2, sub_4D3C70(), 0x48u);
    sub_51D4D0((char*)& byte_587000[253104]);
    result = sub_51D8F0((float2*)(a1 + 4));
    if (result)
    {
        if (*(_DWORD*)& byte_5D4594[3835364] != 1 || (result = sub_527380((float*)(a1 + 4))) != 0)
        {
            sub_4D3C50(v2);
            *(_DWORD*)(a1 + 4) = 0;
            *(_DWORD*)a1 = 0;
            *(_DWORD*)(a1 + 8) = 0;
            result = 1;
        }
    }
    return result;
}

//----- (0051D740) --------------------------------------------------------
int __cdecl sub_51D740(float* a1, int a2)
{
    double v2; // st7
    double v3; // st6
    int v4; // ebx
    int v5; // esi
    int v6; // ebp
    int v7; // edx
    int v8; // edx
    float v9; // ecx
    int result; // eax
    int v11; // eax
    float v12; // edx
    int v13; // eax
    float v14; // edx
    float2 v15; // [esp+10h] [ebp-8h]
    float v17; // [esp+1Ch] [ebp+4h]

    if (!sub_4D3D90((float2*)a1, &v15))
        return 0;
    if (!a2)
        return 0;
    v2 = v15.field_0 + 11.5;
    v3 = v15.field_4 + 11.5;
    v4 = (__int64)(v2 * 0.021739131);
    v17 = v3;
    v5 = (__int64)(v3 * 0.021739131);
    v6 = (int)(__int64)v2 % 46;
    v7 = (__int64)v17 % 46;
    if (v4 - 1 <= 0 || v4 >= 127 || v5 - 1 <= 0 || v5 >= 127)
        return 0;
    if (v6 <= v7)
    {
        if (46 - v6 > v7)
        {
            v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2650668] + 4 * v4 - 4) + 44 * v5 + 24;
            goto LABEL_10;
        }
        v13 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2650668] + 4 * v4) + 44 * v5 + 24;
        v14 = v15.field_4;
        *(float*)(a2 + 4) = v15.field_0;
        *(_DWORD*)a2 = v13;
        *(float*)(a2 + 8) = v14;
        result = 1;
    }
    else
    {
        if (46 - v6 > v7)
        {
            v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2650668] + 4 * v4) + 44 * v5 - 20;
        LABEL_10:
            v9 = v15.field_4;
            *(float*)(a2 + 4) = v15.field_0;
            *(_DWORD*)a2 = v8;
            *(float*)(a2 + 8) = v9;
            return 1;
        }
        v11 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2650668] + 4 * v4) + 44 * v5 + 4;
        v12 = v15.field_4;
        *(float*)(a2 + 4) = v15.field_0;
        *(_DWORD*)a2 = v11;
        *(float*)(a2 + 8) = v12;
        result = 1;
    }
    return result;
}

//----- (0051D8B0) --------------------------------------------------------
int __cdecl sub_51D8B0(int a1)
{
    if (!a1)
        return -1;
    if (*(_DWORD*)a1)
        return **(_DWORD * *)a1;
    return -1;
}

//----- (0051D8D0) --------------------------------------------------------
int __cdecl sub_51D8D0(int a1)
{
    if (!a1)
        return -1;
    if (*(_DWORD*)a1)
        return *(_DWORD*)(*(_DWORD*)a1 + 4);
    return -1;
}

//----- (0051D8F0) --------------------------------------------------------
int __cdecl sub_51D8F0(float2* a1)
{
    double v1; // st7
    double v2; // st6
    int v3; // esi
    int v4; // edi
    int v5; // ebp
    int v6; // edx
    int result; // eax
    int v8; // [esp+10h] [ebp-20h]
    int v9; // [esp+14h] [ebp-1Ch]
    int v10; // [esp+18h] [ebp-18h]
    int v11; // [esp+1Ch] [ebp-14h]
    int v12; // [esp+20h] [ebp-10h]
    char v13; // [esp+24h] [ebp-Ch]
    int v14; // [esp+28h] [ebp-8h]
    int v15; // [esp+2Ch] [ebp-4h]
    float v16; // [esp+34h] [ebp+4h]

    v9 = *(_DWORD*)& byte_5D4594[3835348];
    v1 = a1->field_0 + 11.5;
    v8 = *(_DWORD*)& byte_5D4594[3835340];
    v10 = 0;
    v13 = 0;
    v11 = -1;
    v12 = -1;
    v14 = 255;
    v15 = 0;
    v2 = a1->field_4 + 11.5;
    v3 = (__int64)(v1 * 0.021739131);
    v16 = v2;
    v4 = (__int64)(v2 * 0.021739131);
    v5 = (int)(__int64)v1 % 46;
    v6 = (__int64)v16 % 46;
    if (*(_DWORD*)& byte_5D4594[3835340] == 255)
        result = sub_51D9C0(v3, v4, v5, v6, 0);
    else
        result = sub_51D9C0(v3, v4, v5, v6, (int)& v8);
    return result;
}

//----- (0051D9C0) --------------------------------------------------------
int __cdecl sub_51D9C0(int a1, int a2, int a3, int a4, int a5)
{
    int result; // eax

    if (a1 - 1 <= 0 || a1 >= 127 || a2 - 1 <= 0 || a2 >= 127)
        return 0;
    if (a3 <= a4)
    {
        if (46 - a3 <= a4)
            result = sub_51DA70(a1, a2, a5, 2, 0);
        else
            result = sub_51DA70(a1 - 1, a2, a5, 1, 0);
    }
    else if (46 - a3 <= a4)
    {
        result = sub_51DA70(a1, a2, a5, 1, 0);
    }
    else
    {
        result = sub_51DA70(a1, a2 - 1, a5, 2, 0);
    }
    return result;
}
