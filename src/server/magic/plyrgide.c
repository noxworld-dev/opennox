#include "../../proto.h"

//----- (004FAE80) --------------------------------------------------------
int __cdecl sub_4FAE80_magic_plyrgide(int a1, int a2, int a3)
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