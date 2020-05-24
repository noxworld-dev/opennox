#include "canidraw.h"
#include "../../proto.h"

//----- (004BC930) --------------------------------------------------------
int __cdecl nox_thing_cond_animate_draw( unsigned int * a1, struct nox_drawable * dr)
{
    int v2; // eax
    int v3; // edi
    int v4; // ecx
    int v5; // esi
    int v6; // edx
    int v7; // edx
    int v8; // edx
    signed int v10; // eax

    v2 = dr->field_76;
    if (dr->flags & 0x1000000)
    {
        v3 = *(unsigned int *)(v2 + 4);
        v4 = *(unsigned __int8*)(v2 + 24);
        v5 = *(unsigned __int8*)(v2 + 29);
        v6 = *(unsigned int *)(v2 + 36);
    }
    else
    {
        v3 = *(unsigned int *)(v2 + 8);
        v4 = *(unsigned __int8*)(v2 + 25);
        v5 = *(unsigned __int8*)(v2 + 30);
        v6 = *(unsigned int *)(v2 + 40);
    }
    v7 = v6 - 2;
    if (v7)
    {
        v8 = v7 - 2;
        if (v8)
        {
            if (v8 != 1)
                return 0;
            v10 = dr->field_77;
        }
        else
        {
            v10 = sub_415FF0(0, v4, "C:\\NoxPost\\src\\client\\Draw\\CAniDraw.c", 57);
        }
    }
    else
    {
        v10 = (*(unsigned int *)& byte_5D4594[2598000] + dr->field_32) / (unsigned int)(v5 + 1);
        if (v10 >= v4)
            v10 %= v4;
    }
    sub_4C4770_draw(a1, dr, *(unsigned int *)(v3 + 4 * v10));
    return 1;
}
