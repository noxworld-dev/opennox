#include "../../../proto.h"

//----- (004DB370) --------------------------------------------------------
int __cdecl sub_4DB370_savegame(const char* a1)
{
    char* v1; // eax
    char* v2; // esi
    int v3; // eax
    int v4; // ecx
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    unsigned int v8; // ecx
    unsigned int v9; // eax
    wchar_t* v10; // eax
    char* v12; // [esp-8h] [ebp-810h]
    char* v13; // [esp-4h] [ebp-80Ch]
    char v14[1024]; // [esp+8h] [ebp-800h]
    char v15[1024]; // [esp+408h] [ebp-400h]

    sub_478000();
    sub_4606B0();
    v1 = sub_417090(31);
    v2 = v1;
    if (!v1)
        return 0;
    v3 = *((_DWORD*)v1 + 514);
    if (!v3)
        return 0;
    if (!a1)
        return 0;
    v4 = *(_DWORD*)(v3 + 16);
    if ((v4 & 0x8000) != 0)
        return 0;
    if (!sub_4DB1D0())
        return 0;
    if (!sub_4DB540((int)& byte_587000[199176]))
        return 0;
    v5 = sub_409B40();
    if (!sub_4DB5A0((int)& byte_587000[199184], (int)v5))
        return 0;
    if (!sub_4DB600(*(int*)& byte_5D4594[1563084]))
        return 0;
    v13 = sub_409B40();
    v12 = sub_409B40();
    v6 = sub_409E10();
    nox_sprintf(v15, "%s\\Save\\%s\\%s\\%s.map", v6, &byte_587000[199192], v12, v13);
    if (!sub_51E010(v15, 0))
        return 0;
    sub_4DB6A0();
    v7 = sub_409E10();
    nox_sprintf(v14, "%s\\Save\\%s\\Player.plr", v7, &byte_587000[199224]);
    v8 = *(_DWORD*)& byte_5D4594[2660684] & 0xFFFFFFF7;
    *(_DWORD*)& byte_5D4594[2660684] &= 0xFFFFFFF7;
    if (*(_DWORD*)& byte_5D4594[1563076])
    {
        v9 = v8;
        LOBYTE(v9) = v8 | 8;
        *(_DWORD*)& byte_5D4594[2660684] = v9;
    }
    byte_5D4594[2661961] = sub_450750();
    if (!sub_41A140(v14, (unsigned __int8)v2[2064]))
        return 0;
    if (!sub_41A230(v14))
        return 0;
    if (strcmp(a1, "WORKING"))
    {
        v10 = loadString_sub_40F1D0((char*)& byte_587000[199312], 0, "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 661);
        sub_4D9FD0(0, v10);
        if (!sub_4DC100((int)& byte_587000[199332], (int)a1))
            return 0;
    }
    *(_DWORD*)& byte_5D4594[1563092] = 0;
    *(_DWORD*)& byte_5D4594[1563088] = 0;
    return 1;
}

//----- (004DB7E0) --------------------------------------------------------
char* __cdecl sub_4DB7E0_savegame(const char* a1)
{
    char* v1; // ebp
    char* result; // eax
    char* v3; // eax
    wchar_t* v4; // eax
    int v5; // eax
    char* v6; // eax
    wchar_t* v7; // eax
    char v8[20]; // [esp+Ch] [ebp-414h]
    char FileName[1024]; // [esp+20h] [ebp-400h]

    v1 = sub_417090(31);
    if (!a1)
        return 0;
    if (!sub_40A5C0(2) || (result = (char*)sub_4738D0()) != 0)
    {
        sub_4DB9C0();
        if (!strcmp(a1, "WORKING")
            || (result = (char*)sub_4DC100((int)a1, (int)& byte_587000[199416])) != 0)
        {
            v3 = sub_409E10();
            nox_sprintf(FileName, "%s\\Save\\%s\\Player.plr", v3, &byte_587000[199424]);
            if (_access(FileName, 0) == -1)
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[199504], 0, "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 755);
                sub_4D9FD0(0, v4);
                result = 0;
            }
            else
            {
                v5 = sub_41D090(FileName);
                sub_4E3C60(v5);
                sub_4E3C70();
                sub_4DB220(1);
                sub_4DB230(1);
                result = sub_41A2E0(FileName, 31);
                if (result)
                {
                    sub_460E60();
                    sub_4721D0();
                    nox_sprintf(v8, "%s.map", v1 + 4760);
                    sub_409D70(v8);
                    v6 = sub_409E10();
                    nox_sprintf(
                            (char*)& byte_5D4594[1559960],
                            "%s\\Save\\%s\\%s\\%s.map",
                            v6,
                            &byte_587000[199532],
                            v1 + 4760,
                            v1 + 4760);
                    sub_4D2450(v8);
                    sub_44E0B0(0);
                    result = (char*)sub_41A480(FileName);
                    if (result)
                    {
                        sub_450B70();
                        sub_445450();
                        sub_528D60();
                        v7 = loadString_sub_40F1D0((char*)& byte_587000[199612], 0, "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 824);
                        sub_4D9FD0(0, v7);
                        result = (char*)1;
                    }
                }
            }
        }
    }
    return result;
}