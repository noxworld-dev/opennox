#include "animdraw.h"
#include "../../proto.h"

//----- (004BBD60) --------------------------------------------------------
int __cdecl nox_thing_animate_draw( unsigned int * a1, struct nox_drawable * dr)
{
    int v2; // edi
    int v3; // esi
    int v4; // ecx
    int result; // eax
    int v6; // ebx
    int v7; // eax

    v2 = dr->field_76;
    switch (*(unsigned int *)(v2 + 12))
    {
        case 0:
            v3 = (*(unsigned int *)& byte_5D4594[2598000] - dr->field_79) / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
            v7 = *(unsigned __int8*)(v2 + 8);
            if (v3 >= v7)
                v3 = v7 - 1;
            goto LABEL_12;
        case 1:
            v3 = (*(unsigned int *)& byte_5D4594[2598000] - dr->field_79) / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
            if (v3 < *(unsigned __int8*)(v2 + 8))
                goto LABEL_12;
            sub_45A4E0_drawable(dr);
            return 0;
        case 2:
            if (dr->flags & 0x1000000)
                goto LABEL_9;
            if (!(dr->field_28 & 0x10000000))
                goto LABEL_8;
            if (nox_common_gameFlags_check_40A5C0(32))
            {
                LABEL_9:
                v3 = (*(unsigned int *)& byte_5D4594[2598000] + dr->field_32)
                     / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
                goto LABEL_10;
            }
            if (dr->field_28 & 0x10000000)
                goto LABEL_14;
        LABEL_8:
            v3 = 0;
            goto LABEL_12;
        case 3:
            v6 = 2 * *(unsigned __int8*)(v2 + 8);
            sub_434560(1);
            v3 = (*(unsigned int *)& byte_5D4594[2598000] - dr->field_79) / ((unsigned int) * (unsigned __int8*)(v2 + 9) + 1);
            if (v3 < v6)
            {
                sub_434580(-56 - 200 * v3 / v6);
                LABEL_10:
                v4 = *(unsigned __int8*)(v2 + 8);
                if (v3 >= v4)
                    v3 %= v4;
                LABEL_12:
                sub_4C4770_draw(a1, dr, *(unsigned int *)(*(unsigned int *)(v2 + 4) + 4 * v3));
                if ( *(unsigned int *)(v2 + 12) == 3)
                    sub_434560(0);
                LABEL_14:
                result = 1;
            }
            else
            {
                sub_45A4E0_drawable(dr);
                result = 0;
            }
            return result;
        case 4:
            v3 = sub_415FF0(0, *(unsigned __int8*)(v2 + 8) - 1, "C:\\NoxPost\\src\\Client\\Draw\\animdraw.c", 24);
            goto LABEL_12;
        case 5:
            v3 = dr->field_77;
            goto LABEL_12;
        default:
            goto LABEL_14;
    }
}
