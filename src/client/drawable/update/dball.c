#include "dball.h"

#include "../../draw/fx.h"
#include "../../../proto.h"

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
            result = (_DWORD*)sub_45A360_drawable(*(int*)& byte_5D4594[1523008], *(_DWORD*)(a1 + 12), *(_DWORD*)(a1 + 16));
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
                result = sub_45A110_drawable(v4);
            }
            v3 = (_DWORD*)((char*)v3 - 1);
        } while (v3);
    }
    return result;
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
