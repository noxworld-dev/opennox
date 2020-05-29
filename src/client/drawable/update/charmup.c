#include "charmup.h"

#include "../../../proto.h"

//----- (004CD150) --------------------------------------------------------
void __cdecl sub_4CD150(int a1, _DWORD* a2, int a3, int a4)
{
    int v4; // eax
    int v5; // esi
    int v6; // eax
    int v7; // ebx
    int v8; // eax
    int v9; // ecx
    int v10; // eax
    int v11; // eax
    _DWORD* v12; // eax
    int v13; // eax
    _DWORD* v14; // ebp
    int v15; // eax
    int v16; // eax
    int v17; // edi
    int v18; // eax
    int v19; // eax
    int v20; // edx
    int v21; // ecx
    int v22; // esi
    char v23; // al
    int v25; // [esp+14h] [ebp-4h]
    int v26; // [esp+24h] [ebp+Ch]
    int v27; // [esp+28h] [ebp+10h]

    v4 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 16);
    if (v4 >= 50)
        return;
    LOBYTE(v4) = *(_BYTE*)(a3 + 432);
    if (!(_BYTE)v4)
    {
        if (a3 == -432)
            return;
        if (a4)
        {
            v5 = *(unsigned __int16*)(a3 + 441) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 28);
            v6 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 29);
            LOWORD(v7) = *(_WORD*)(a3 + 437);
            v8 = *(unsigned __int16*)(a3 + 443) + v6;
            LOWORD(v9) = *(_WORD*)(a3 + 439);
        }
        else
        {
            v5 = *(unsigned __int16*)(a3 + 437) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 36);
            v10 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 37);
            LOWORD(v7) = *(_WORD*)(a3 + 441);
            v8 = *(unsigned __int16*)(a3 + 439) + v10;
            LOWORD(v9) = *(_WORD*)(a3 + 443);
        }
        goto LABEL_19;
    }
    if (a3 == -432)
        return;
    if (sub_578B70(*(_DWORD*)(a3 + 437)))
    {
        v11 = sub_578B30(*(_DWORD*)(a3 + 437));
        v12 = sub_45A720(v11);
    }
    else
    {
        v13 = sub_578B30(*(_DWORD*)(a3 + 437));
        v12 = sub_45A6F0(v13);
    }
    v14 = v12;
    if (sub_578B70(*(_DWORD*)(a3 + 441)))
    {
        v15 = sub_578B30(*(_DWORD*)(a3 + 441));
        v4 = sub_45A720(v15);
    }
    else
    {
        v16 = sub_578B30(*(_DWORD*)(a3 + 441));
        v4 = sub_45A6F0(v16);
    }
    v17 = v4;
    if (!v14 || !v4)
        return;
    if (!a4)
    {
        v5 = v14[3] + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 80);
        v19 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 81);
        v7 = *(_DWORD*)(v17 + 12);
        v8 = v14[4] + v19;
        v9 = *(_DWORD*)(v17 + 16);
        LABEL_19:
        LOWORD(v25) = v9;
        goto LABEL_20;
    }
    v5 = *(_DWORD*)(v4 + 12) + sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 70);
    v18 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 71);
    v7 = v14[3];
    v8 = *(_DWORD*)(v17 + 16) + v18;
    v25 = v14[4];
    LABEL_20:
    v20 = v5 + *a2 - a2[4];
    v27 = *(__int16*)(a3 + 104);
    v26 = a2[5];
    v21 = v8 + a2[1] - v26 - v27;
    if (v20 < 0)
        v5 = a2[4] + *a2 + 1;
    if (v21 < 0)
        v8 = a2[1] + v26 - v27 + 1;
    if (v20 >= a2[8])
        v5 = a2[2] + a2[4] - 1;
    if (v21 >= a2[9])
        v8 = a2[3] - v27 + v26 - 1;
    v4 = sub_45A360_drawable(a1, v5, v8);
    v22 = v4;
    if (v4)
    {
        v23 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 112);
        *(_WORD*)(v22 + 432) = v7;
        *(_WORD*)(v22 + 434) = v25;
        *(_BYTE*)(v22 + 443) = v23;
        LOBYTE(v4) = sub_415FF0(3, 10, "C:\\NoxPost\\src\\client\\Drawable\\Update\\charmup.c", 119);
        *(_BYTE*)(v22 + 444) = v4;
    }
    return;
}
