#include "options.h"

#include "../../proto.h"

//----- (004AA650) --------------------------------------------------------
void sub_4AA650()
{
    char* v2; // ecx
    void* v3; // [esp+0h] [ebp-4h]

    if (!sub_44D930())
    {
        v2 = *(char**)& byte_587000[4 * (*(_DWORD*)& byte_5D4594[1309744])++ + 172892];
        loadString_sub_40F1D0(v2, &v3, "C:\\NoxPost\\src\\client\\shell\\Options.c", 131);
        *(_DWORD*)& byte_5D4594[1309744] %= 3;
        if (v3)
            /*(void*)*/sub_44D900((int)v3, 100);
    }
}

