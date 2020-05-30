// FIXME
#include "../../../client/gui/guimsg.h"

#include "../../../proto.h"

extern FILE* nox_file_2;

//----- (0041C8F0) --------------------------------------------------------
int __cdecl sub_41C8F0(char* a1, unsigned int a2)
{
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    int result; // eax
    char* v5; // eax
    FILE* v6; // eax
    char* v7; // esi
    int v8; // edi
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    CHAR PathName[1024]; // [esp+4h] [ebp-400h]

    if (nox_common_mapflags_check(1) || a2 >= *(int*)& byte_587000[55984])
    {
        v5 = sub_409E10();
        nox_sprintf(PathName, "%s\\Save\\", v5);
        CreateDirectoryA(PathName, 0);
        v6 = sub_408CC0_fopen((char*)& byte_5D4594[2660688], 1);
        nox_file_2 = v6;
        if (v6)
        {
            if (sub_408D40((int)v6, 27))
            {
                v7 = a1;
                if ((_WORD)a2)
                {
                    v8 = (unsigned __int16)a2;
                    do
                    {
                        sub_409200(v7++, 1, 1, nox_file_2);
                        --v8;
                    } while (v8);
                }
                sub_408D90(nox_file_2);
                if (nox_common_mapflags_check(4096))
                    byte_5D4594[2661961] = sub_465DF0();
                else
                    byte_5D4594[2661961] = 0;
                if (sub_41A230((char*)& byte_5D4594[2660688]))
                {
                    v9 = loadString_sub_40F1D0((char*)& byte_587000[56752], 0, "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3420);
                    sub_450C00(0xCu, v9);
                    v10 = loadString_sub_40F1D0((char*)& byte_587000[56816], 0, "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3421);
                    sub_445490(v10);
                    result = 1;
                }
                else
                {
                    sub_413D30((char*)& byte_587000[56648]);
                    result = 0;
                }
            }
            else
            {
                sub_413D30((char*)& byte_587000[56600], &byte_5D4594[2660688]);
                result = 0;
            }
        }
        else
        {
            sub_413D30((char*)& byte_587000[56552], &byte_5D4594[2660688]);
            result = 0;
        }
    }
    else
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[56392], 0, "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3341);
        sub_450C00(0xCu, v2);
        v3 = loadString_sub_40F1D0((char*)& byte_587000[56460], 0, "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3342);
        sub_445490(v3);
        sub_413D30((char*)& byte_587000[56480], &byte_5D4594[2660688]);
        result = 0;
    }
    return result;
}