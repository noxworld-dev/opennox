#include "../../../proto.h"

//----- (004D42C0) --------------------------------------------------------
int sub_4D42C0()
{
    return *(_DWORD*)& byte_5D4594[1550916];
}

//----- (00522A40) --------------------------------------------------------
int __cdecl sub_522A40(int a1)
{
    int v2; // ebx
    int v3; // edi
    int v4; // esi
    float* v5; // eax

    if (!*(_DWORD*)(a1 + 472))
        return 1;
    v2 = sub_5259E0();
    if (!v2)
        return 0;
    while (1)
    {
        if (*(_DWORD*)v2 == 1)
        {
            v3 = 0;
            if (*(_DWORD*)(a1 + 472) > 0)
                break;
        }
        LABEL_9:
        v2 = *(_DWORD*)(v2 + 68);
        if (!v2)
            return 0;
    }
    v4 = a1 + 216;
    while (1)
    {
        v5 = sub_522AD0((float*)v2, v4);
        if (v5)
            break;
        ++v3;
        v4 += 64;
        if (v3 >= *(int*)(a1 + 472))
            goto LABEL_9;
    }
    sub_527D50((int)v5, (char*)(a1 + 476));
    return 1;
}

//----- (005259D0) --------------------------------------------------------
double sub_5259D0()
{
    return *(float*)& byte_5D4594[2487580];
}

//----- (00526A90) --------------------------------------------------------
void sub_526A90()
{
    free(*(LPVOID*)& byte_5D4594[2487672]);
}

//----- (005228B0) --------------------------------------------------------
void __cdecl sub_5228B0_mapgen_populate(int a1)
{
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    int i; // ebp
    int j; // esi
    float* v6; // eax
    float v8; // [esp+8h] [ebp-8h]
    float v9; // [esp+Ch] [ebp-4h]

    sub_5235F0(157);
    if (!sub_522A40(a1))
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[254784], 0, "C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c", 848);
        sub_4D9FD0(0, v1);
        v2 = loadString_sub_40F1D0((char*)& byte_587000[254844], 0, "C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c", 849);
        sub_4D9FD0(0, v2);
        v3 = loadString_sub_40F1D0((char*)& byte_587000[254904], 0, "C:\\NoxPost\\src\\Server\\MapGen\\Generate\\populate.c", 850);
        sub_4D9FD0(0, v3);
    }
    sub_5259D0();
    for (i = sub_4D42C0(); i; i = *(_DWORD*)(i + 64))
    {
        sub_5235F0(157);
        if (*(_DWORD*)(i + 372) && !(*(_BYTE*)(i + 52) & 2))
            sub_522340(a1, i);
        if (*(_DWORD*)(a1 + 60))
        {
            for (j = *(_DWORD*)(i + 368); j; j = *(_DWORD*)(j + 24))
            {
                if (*(_DWORD*)j)
                    sub_51D4D0((char*)& byte_587000[254924]);
                else
                    sub_51D4D0((char*)& byte_587000[254912]);
                sub_5245A0(
                        a1,
                        (float*)(j + 4),
                        (__int64)((*(float*)(j + 12) - *(float*)(j + 4) + 0.5) * 0.030743772),
                        (__int64)((*(float*)(j + 16) - *(float*)(j + 8) + 0.5) * 0.030743772));
            }
        }
    }
    v6 = (float*)sub_4D42C0();
    v8 = (v6[11] + v6[9]) * 0.5;
    v9 = (v6[12] + v6[10]) * 0.5;
    sub_527940((char*)& byte_587000[254936]);
    sub_5279B0(&v8);
    sub_469B90((int*)(a1 + 536));
    sub_526A90();
}