#include "../../proto.h"

//----- (00512B10) --------------------------------------------------------
int sub_512B10()
{
    int v0; // eax
    wchar_t* v1; // eax

    v0 = script_pop();
    if (*(_DWORD*)& byte_5D4594[3821964] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[3821964] + 8) & 4)
    {
        v1 = loadString_sub_40F1D0(*(char**)& byte_5D4594[4 * v0 + 3831212], 0, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1285);
        sub_4D9EB0(*(int*)& byte_5D4594[3821964], v1);
    }
    return 0;
}

//----- (00512B60) --------------------------------------------------------
int sub_512B60()
{
    int v0; // eax
    wchar_t* v1; // eax

    v0 = script_pop();
    v1 = loadString_sub_40F1D0(*(char**)& byte_5D4594[4 * v0 + 3831212], 0, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1310);
    sub_4D9FD0(0, v1);
    return 0;
}

//----- (00512B90) --------------------------------------------------------
int sub_512B90()
{
    int v0; // edi
    int v1; // eax
    int v2; // esi
    char* v3; // ecx
    wchar_t* v4; // eax
    int v6; // [esp+8h] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = sub_511B60(v1);
    if (v2)
    {
        v3 = *(char**)& byte_5D4594[4 * v0 + 3831212];
        v6 = 0;
        v4 = loadString_sub_40F1D0(v3, &v6, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1342);
        sub_528AC0(v2, v4, 0);
        if (sub_40A5C0(2048))
            sub_44D900(v6, 100);
    }
    return 0;
}

//----- (00513F70) --------------------------------------------------------
int sub_513F70()
{
    int v0; // eax
    wchar_t* v1; // eax
    int v2; // eax

    v0 = script_pop();
    v1 = loadString_sub_40F1D0(*(char**)& byte_5D4594[4 * v0 + 3831212], 0, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 2901);
    v2 = sub_512E80((int)v1);
    sub_507230(v2);
    return 0;
}

//----- (00514A80) --------------------------------------------------------
int sub_514A80()
{
    __int16 v0; // di
    int v1; // ebx
    int v2; // eax
    int v3; // esi
    char* v4; // edx
    wchar_t* v5; // eax
    wchar_t v7; // [esp-4h] [ebp-14h]
    int v8; // [esp+Ch] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_511B60(v2);
    if (v3)
    {
        v4 = *(char**)& byte_5D4594[4 * v1 + 3831212];
        v7 = v0 * *(_WORD*)& byte_5D4594[2649704];
        v8 = 0;
        v5 = loadString_sub_40F1D0(v4, &v8, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3629);
        sub_528AC0(v3, v5, v7);
        if (sub_40A5C0(2048))
            sub_44D900(v8, 100);
    }
    return 0;
}

//----- (00514B10) --------------------------------------------------------
int sub_514B10()
{
    wchar_t v0; // di
    int v1; // ebx
    int v2; // eax
    int v3; // esi
    char* v4; // ecx
    wchar_t* v5; // eax
    int v7; // [esp+Ch] [ebp-4h]

    v0 = script_pop();
    v1 = script_pop();
    v2 = script_pop();
    v3 = sub_511B60(v2);
    if (v3)
    {
        v4 = *(char**)& byte_5D4594[4 * v1 + 3831212];
        v7 = 0;
        v5 = loadString_sub_40F1D0(v4, &v7, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3670);
        sub_528AC0(v3, v5, v0);
        if (v7)
        {
            if (sub_40A5C0(2048))
                sub_44D900(v7, 100);
        }
    }
    return 0;
}