#include "guicurs.h"

#include "../../proto.h"

extern int nox_win_width;
extern int nox_win_height;
int nox_client_mouseCursorType = 0;

//----- (00477A30) --------------------------------------------------------
int __cdecl nox_video_cursorDrawImpl_477A30(int a1, int a2, int a3)
{
    int v3; // edi
    int v4; // ebp
    int v5; // esi
    int v6; // eax
    __int16* v7; // eax
    __int16* v8; // eax
    __int16* v9; // eax
    __int16* v10; // eax
    __int16* v11; // eax
    __int16* v12; // eax
    __int16* v13; // eax
    int2* v14; // eax
    int v15; // esi
    int v16; // ebx
    int result; // eax
    int v18; // [esp+10h] [ebp-Ch]
    float2 v19; // [esp+14h] [ebp-8h]

    v18 = *(_DWORD*)& byte_5D4594[3799496];
    v3 = a2 - 64;
    v4 = a3 - 64;
    *(_DWORD*)& byte_5D4594[3799496] = 0;
    *(_DWORD*)& byte_5D4594[3798728] = 1;
    *(_DWORD*)& byte_5D4594[1097212] = a2 - 64;
    *(_DWORD*)& byte_5D4594[1097216] = a3 - 64;
    if (byte_5D4594[2598000] & 1)
        ++* (_DWORD*)& byte_5D4594[1097288];
    sub_434390(*(int*)& byte_5D4594[2589772]);
    v5 = sub_43F320(0);
    if (sub_460650() || sub_4611A0())
    {
        LOWORD(result) = sub_4BE6D0(*(int*)& byte_5D4594[1097240], v3, v4);
        *(_DWORD*)& byte_5D4594[3798728] = 0;
        *(_DWORD*)& byte_587000[151528] = 5;
        *(_DWORD*)& byte_5D4594[3799496] = v18;
    }
    else
    {
        v6 = nox_client_mouseCursorType;
        if (nox_client_mouseCursorType != *(_DWORD*)& byte_587000[151528] && nox_client_mouseCursorType != 14)
        {
            sub_48B680(0);
            v6 = nox_client_mouseCursorType;
        }
        switch (v6)
        {
            case 1:
                v10 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[151952], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 199);
                sub_43F6E0(0, v10, v3 + 54, a3 - v5);
                sub_4BE6D0(*(int*)& byte_5D4594[1097224], v3, v4);
                break;
            case 2:
                v7 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[151816], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 176);
                sub_43F6E0(0, v7, v3 + 49, v5 + a3);
                sub_4BE6D0(*(int*)& byte_5D4594[1097228], v3, v4);
                goto LABEL_16;
            case 3:
                v8 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[151860], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 185);
                sub_43F6E0(0, v8, v3 + 39, a3 - v5);
                sub_4BE6D0(*(int*)& byte_5D4594[1097232], v3, v4);
                break;
            case 4:
                v9 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[151908], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 192);
                sub_43F6E0(0, v9, v3 + 49, a3 - v5);
                sub_4BE6D0(*(int*)& byte_5D4594[1097236], v3, v4);
                break;
            case 6:
            case 7:
                v11 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[151996], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 207);
                sub_43F6E0(0, v11, v3 + 49, v4 + 88);
                sub_4BE6D0(*(_DWORD*)& byte_5D4594[4 * nox_client_mouseCursorType + 1097220], v3, v4);
                break;
            case 8:
                v12 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[152044], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 214);
                sub_43F6E0(0, v12, v3 + 49, a3 - v5);
                sub_4BE6D0(*(int*)& byte_5D4594[1097252], v3, v4);
                *(_DWORD*)& byte_5D4594[1097208] = 2 * v5 + 4;
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                sub_4BE6D0(*(_DWORD*)& byte_5D4594[4 * v6 + 1097220], v3, v4);
                break;
            case 13:
                v13 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[152088], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 223);
                sub_43F6E0(0, v13, v3 + 54, v5 + a3);
                sub_4BE6D0(*(int*)& byte_5D4594[1097272], v3, v4);
            LABEL_16:
                *(_DWORD*)& byte_5D4594[1097208] = -2 * v5;
                break;
            case 14:
                v14 = nox_client_getMousePos_4309F0();
                v19.field_0 = (double)(v14->field_0 - nox_win_width / 2);
                v19.field_4 = (double)(v14->field_4 - nox_win_height / 2);
                //dprintf("cur %f %f %d", v19.field_0, v19.field_4, sub_509ED0(&v19));
                v15 = sub_509ED0(&v19) / 8;
                if (v19.field_4 * v19.field_4 + v19.field_0 * v19.field_0 > 10000.0
                    || *(_DWORD*)& byte_5D4594[2614252] && *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 276) == 6)
                {
                    v15 += 32;
                }
                v16 = sub_476F80();
                if (v16)
                {
                    sub_48B680(1);
                    if (!(*(_BYTE*)(v16 + 112) & 6) || sub_495A80(*(_DWORD*)(v16 + 128)))
                        sub_48B800(*(int*)& byte_5D4594[2650684]);
                    else
                        sub_48B800(*(int*)& byte_5D4594[2650644]);
                }
                else
                {
                    sub_48B680(0);
                }
                sub_4BE710(*(int*)& byte_5D4594[1097276], v3, v4, v15);
                sub_4345F0(0);
                break;
            case 15:
                sub_4BE6D0(*(_DWORD*)& byte_5D4594[4 * v6 + 1097220], v3, v4);
                *(_DWORD*)& byte_5D4594[1097208] = -2 * v5;
                break;
            case 16:
                sub_4BE6D0(*(_DWORD*)& byte_5D4594[4 * v6 + 1097220], v3, v4);
                *(_DWORD*)& byte_5D4594[1097208] = -v5;
                break;
            default:
                sub_4BE6D0(*(int*)& byte_5D4594[1097220], v3, v4);
                break;
        }
        result = v18;
        *(_DWORD*)& byte_5D4594[3798728] = 0;
        *(_DWORD*)& byte_587000[151528] = nox_client_mouseCursorType;
        *(_DWORD*)& byte_5D4594[3799496] = v18;
    }
    return result;
}

