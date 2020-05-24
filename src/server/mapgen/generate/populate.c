#include "../../../proto.h"

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