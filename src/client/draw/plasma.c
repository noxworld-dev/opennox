#include "plasma.h"

#include "fx.h"
#include "../../proto.h"

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
                v20 = nox_float2int(v28);
                v21 = *(_DWORD*)v17;
                a3a.field_0 = v20;
                v29 = v37 * *(float*)& byte_587000[8 * v21 + 194140];
                v22 = nox_float2int(v29);
                v23 = *((_DWORD*)v17 + 4);
                v24 = v37 * *(float*)& byte_587000[8 * *((_DWORD*)v17 + 7) + 194136];
                a3a.field_4 = v22;
                v25 = *((_DWORD*)v17 + 5);
                a2a.field_0 = v23;
                a2a.field_4 = v25;
                v30 = v24;
                v26 = nox_float2int(v30);
                v27 = *((_DWORD*)v17 + 7);
                a4a.field_0 = v26;
                v31 = v37 * *(float*)& byte_587000[8 * v27 + 194140];
                a4a.field_4 = nox_float2int(v31);
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
