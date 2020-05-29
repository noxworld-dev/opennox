#include "magicdrw.h"

#include "../../proto.h"

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
        sub_484D70_light_intensity(a2 + 136, v9);
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
        sub_484D70_light_intensity(a2 + 136, v9);
    }
    return 1;
}
