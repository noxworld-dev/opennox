#include "vectdraw.h"
#include "../../proto.h"

//----- (004BC5D0) --------------------------------------------------------
int __cdecl sub_4BC5D0(_DWORD* a1, int a2)
{
    int result; // eax
    int v3; // ecx
    int v4; // ecx

    switch (*(unsigned int *)(a2 + 44))
    {
        case 0:
            result = (*(unsigned int *)& byte_5D4594[2598000] - a1[79]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
            v4 = *(__int16*)(a2 + 40);
            if (result >= v4)
                result = v4 - 1;
            break;
        case 1:
            result = (*(unsigned int *)& byte_5D4594[2598000] - a1[79]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
            if (result >= *(__int16*)(a2 + 40))
            {
                sub_45A4E0_drawable((int)a1);
                result = -1;
            }
            break;
        case 2:
            result = (*(unsigned int *)& byte_5D4594[2598000] + a1[32]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
            v3 = *(__int16*)(a2 + 40);
            if (result >= v3)
                result %= v3;
            break;
        case 4:
            result = sub_415FF0(0, *(__int16*)(a2 + 40) - 1, "C:\\NoxPost\\src\\Client\\Draw\\vectdraw.c", 19);
            break;
        case 5:
            result = a1[77];
            break;
        default:
            result = 0;
            break;
    }
    return result;
}
