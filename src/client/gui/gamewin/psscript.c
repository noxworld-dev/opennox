#include "psscript.h"

#include "gamewin.h"
#include "../../../proto.h"

//----- (004A0800) --------------------------------------------------------
int __cdecl sub_4A0800(wchar_t* a1, char* a2)
{
    wchar_t* v2; // eax

    v2 = loadString_sub_40F1D0(a2, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 267);
    sub_46B000(a1, v2);
    return 1;
}

//----- (004A0A90) --------------------------------------------------------
int __cdecl sub_4A0A90(int a1, char* a2)
{
    wchar_t* v2; // eax

    if (!strcmp(a2, "Options.wnd:8BitColor"))
    {
        v2 = L"\tWindowed";
    }
    else if (!strcmp(a2, "Options.wnd:16BitColor"))
    {
        v2 = L"\tFullscreen";
    }
    else
    {
        v2 = loadString_sub_40F1D0(a2, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 424);
    }
    nox_wcsncpy((wchar_t*)(a1 + 72), v2, 0x3Fu);
    *(_WORD*)(a1 + 196) = 0;
    return 1;
}

//----- (004A10A0) --------------------------------------------------------
int __cdecl sub_4A10A0(_DWORD* a1, const char* a2, char* a3)
{
    char* v3; // eax
    char* v4; // eax
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    char* v8; // eax
    char* v9; // eax
    int result; // eax
    char* v11; // eax
    char* v12; // eax
    char* v13; // eax
    char* v14; // eax
    const char* v15; // esi
    char* v16; // eax
    char* v17; // eax
    char* v18; // eax
    char* v19; // eax
    char* v20; // eax
    char* v21; // eax

    if (!strcmp(a2, "VERTSLIDER") || !strcmp(a2, "HORZSLIDER"))
    {
        *(_DWORD*)& byte_5D4594[1305820] = 0;
        *(_DWORD*)& byte_5D4594[1305824] = 0;
        *(_DWORD*)& byte_5D4594[1305828] = 0;
        *(_DWORD*)& byte_5D4594[1305832] = 0;
        v20 = strtok(a3, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1305820] = atoi(v20);
        v21 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1305824] = atoi(v21);
        result = 1;
        *a1 = &byte_5D4594[1305820];
    }
    else if (!strcmp(a2, "SCROLLLISTBOX"))
    {
        memset(&byte_5D4594[1306892], 0, 0x38u);
        v3 = strtok(a3, " \t\n\r");
        *(_WORD*)& byte_5D4594[1306892] = atoi(v3);
        v4 = strtok(0, " \t\n\r");
        *(_WORD*)& byte_5D4594[1306894] = atoi(v4);
        v5 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306896] = atoi(v5);
        v6 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306900] = atoi(v6);
        v7 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306904] = atoi(v7);
        v8 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306908] = atoi(v8);
        v9 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1306912] = atoi(v9);
        result = 1;
        *a1 = &byte_5D4594[1306892];
    }
    else if (!strcmp(a2, "ENTRYFIELD"))
    {
        memset(&byte_5D4594[1305836], 0, 0x420u);
        v11 = strtok(a3, " \t\n\r");
        *(_WORD*)& byte_5D4594[1306876] = atoi(v11);
        v12 = strtok(0, " \t\n\r");
        if (v12)
            * (_WORD*)& byte_5D4594[1306878] = atoi(v12);
        else
            *(_WORD*)& byte_5D4594[1306878] = -1;
        v13 = strtok(0, " \t\n\r");
        if (v13)
        {
            *(_DWORD*)& byte_5D4594[1306860] = atoi(v13);
            *(_DWORD*)& byte_5D4594[1306860] = *(_DWORD*)& byte_5D4594[1306860] != 0;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1306860] = 0;
        }
        v14 = strtok(0, " \t\n\r");
        v15 = v14;
        if (v14)
        {
            *(_DWORD*)& byte_5D4594[1306864] = atoi(v14) == 1;
            *(_DWORD*)& byte_5D4594[1306868] = atoi(v15) == 2;
            *(_DWORD*)& byte_5D4594[1306872] = atoi(v15) == 3;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1306864] = 0;
            *(_DWORD*)& byte_5D4594[1306868] = 0;
            *(_DWORD*)& byte_5D4594[1306872] = 0;
        }
        *a1 = &byte_5D4594[1305836];
        result = 1;
    }
    else if (!strcmp(a2, "STATICTEXT"))
    {
        v16 = strtok(a3, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1307256] = atoi(v16);
        *(_DWORD*)& byte_5D4594[1307256] = *(_DWORD*)& byte_5D4594[1307256] != 0;
        v17 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1307260] = atoi(v17);
        *(_DWORD*)& byte_5D4594[1307260] = *(_DWORD*)& byte_5D4594[1307260] != 0;
        v18 = strtok(0, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1307252] = loadString_sub_40F1D0(v18, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 542);
        result = 1;
        *a1 = &byte_5D4594[1307252];
    }
    else if (!strcmp(a2, "RADIOBUTTON"))
    {
        v19 = strtok(a3, " \t\n\r");
        *(_DWORD*)& byte_5D4594[1305812] = atoi(v19);
        *(_DWORD*)& byte_5D4594[1307256] = *(_DWORD*)& byte_5D4594[1307256] != 0;
        result = 1;
        *a1 = &byte_5D4594[1305812];
    }
    else
    {
        result = 1;
        *a1 = 0;
    }
    return result;
}

