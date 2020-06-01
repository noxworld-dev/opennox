#include "sdecode.h"

#include "../../client/system/parsecmd.h"
#include "../../common/system/team.h"
#include "../system/trade.h"
#include "mapsend.h"
#include "../../client/network/cdecode.h"
#include "../../proto.h"

//----- (0051BAD0) --------------------------------------------------------
int __cdecl sub_51BAD0_net_sdecode(int a1, unsigned __int8* a2, signed int a3)
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
    if (*(_DWORD*)& nox_common_engineFlags & 0x200000)
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
                    if (!nox_common_gameFlags_check_40A5C0(2048))
                    {
                        v35 = *(_DWORD*)(v9 + 16);
                        if (v35 & 0x4000)
                            v34 = 0;
                    }
                    if (!nox_common_gameFlags_check_40A5C0(128) && v34)
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
                             || nox_common_gameFlags_check_40A5C0(4096))
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
                    if (!nox_common_gameFlags_check_40A5C0(128) && v33)
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
                            if (nox_common_gameFlags_check_40A5C0(2) && j[2064] == 31)
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
                            if (nox_common_gameFlags_check_40A5C0(2) && *(_DWORD*)(v48 + 36) == *(_DWORD*)& byte_5D4594[2616328])
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
                    sub_519DE0_net_mapsend(*(unsigned __int8*)(v8 + 2064));
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
                    if (nox_common_gameFlags_check_40A5C0(4096)
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
                            if (!nox_common_gameFlags_check_40A5C0(128))
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
                            if (nox_common_gameFlags_check_40A5C0(4096))
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
                            if (nox_common_gameFlags_check_40A5C0(4096))
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
                                    if (sub_50F820_trade(v69, v9, *(float*)& v68) == 1)
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
                                        sub_50EF10_trade(v9, v65);
                                }
                            }
                            goto LABEL_232;
                        case 0x16u:
                            v72 = (_DWORD*)v10[70];
                            if (v72)
                                sub_5100C0_trade(v9, v72, *((unsigned __int16*)v4 + 1));
                            goto LABEL_252;
                        case 0x17u:
                            v73 = v10[70];
                            if (v73)
                                sub_510640_trade(v9, v73, *((unsigned __int16*)v4 + 1), (float*)v4[4]);
                            goto LABEL_255;
                        case 0x18u:
                            v74 = v10[70];
                            if (!v74)
                                goto LABEL_252;
                            sub_510BE0_trade((int*)v9, v74, (_DWORD*) * ((unsigned __int16*)v4 + 1));
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
                            sub_5109C0_trade((int*)v9, v77, (_DWORD*) * ((unsigned __int16*)v4 + 1));
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
