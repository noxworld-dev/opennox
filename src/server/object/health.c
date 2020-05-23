#include "../../proto.h"

//----- (004EE500) --------------------------------------------------------
void __cdecl sub_4EE500_obj_health(int a1)
{
    int v1; // ebx
    int v2; // esi
    int v3; // ebp
    int v4; // edi
    int v5; // eax
    double v6; // st7
    wchar_t* v7; // eax

    v1 = a1;
    if (a1)
    {
        if (sub_40A5C0(2048))
        {
            v2 = *(_DWORD*)(a1 + 520);
            if (v2)
            {
                v3 = 1;
                v4 = sub_4EC580(*(_DWORD*)(a1 + 520));
                if (*(_BYTE*)(v4 + 8) & 4)
                {
                    v5 = 0;
                    if (v2 == v4)
                        goto LABEL_12;
                    do
                    {
                        if (v5)
                            break;
                        if (*(_BYTE*)(v2 + 8) & 2)
                        {
                            v3 = sub_500CC0(v4, v2);
                            v5 = 1;
                        }
                        v2 = *(_DWORD*)(v2 + 508);
                    } while (v2 != v4);
                    if (v3)
                    {
                        v1 = a1;
                        LABEL_12:
                        v6 = sub_4EF270(v4, *(float*)(v1 + 28));
                        if (v6 > 0.0)
                        {
                            v7 = loadString_sub_40F1D0((char*)& byte_587000[206012], 0, "C:\\NoxPost\\src\\Server\\Object\\health.c", 172);
                            sub_4D9EB0(v4, v7, (unsigned int)(__int64)v6);
                        }
                        return;
                    }
                }
            }
        }
    }
}