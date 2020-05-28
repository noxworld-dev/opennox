#include "selclass.h"

#include "selcolor.h"
#include "../../proto.h"

//----- (004A4A20) --------------------------------------------------------
int __cdecl sub_4A4A20(int a1, int a2, int* a3, int a4)
{
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // ebx
    _DWORD* v8; // esi
    wchar_t* v9; // eax

    if (a2 != 16389)
    {
        if (a2 != 16391)
            return 0;
        v4 = sub_46B0A0(a3);
        if (v4 >= 601)
        {
            if (v4 <= 603)
                return 1;
            if (v4 == 610)
            {
                if (sub_40A5C0(0x2000) && !sub_40A5C0(4096))
                {
                    if (sub_4D6F50() || (v5 = sub_4D6F70()) != 0)
                        v5 = 1;
                    sub_4A4B70(v5);
                }
                sub_4A4970();
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1307732] + 52) = sub_4A5D00;
            }
        }
        sub_452D80(921, 100);
        return 1;
    }
    v6 = sub_46B0A0(a3);
    v7 = v6;
    if (v6 >= 601 && v6 <= 603)
    {
        sub_46ABB0(*(int*)& byte_5D4594[1307728], 1);
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1307736], 605);
        *(_BYTE*)(*(_DWORD*)& byte_5D4594[1307724] + 66) = v7 - 89;
        v9 = loadString_sub_40F1D0(
            *(char**)& byte_587000[4 * (unsigned __int8)(v7 - 89) + 170208],
            0,
            "C:\\NoxPost\\src\\client\\shell\\SelClass.c",
            279);
        nox_window_call_field_94((int)v8, 16385, (int)v9, 0);
        *(_DWORD*)& byte_5D4594[1307740] = v7;
    }
    sub_452D80(920, 100);
    return 1;
}

