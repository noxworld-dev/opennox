#include "proto.h"

extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern int default_win_width;
extern int default_win_height;

extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
extern int nox_things_count;

FILE* nox_file_log = 0;

nox_alloc_class* nox_alloc_window = 0;

nox_window* nox_win_unk1 = 0;
nox_window* nox_win_unk2 = 0;
nox_window* nox_win_unk3 = 0;
nox_window* nox_win_unk4 = 0;
nox_window* nox_win_unk5 = 0;
nox_window* nox_win_cur_weapon = 0;

extern nox_parse_thing_funcs_t nox_parse_thing_funcs[];
extern int nox_parse_thing_funcs_cnt;

//----- (0044CCA0) --------------------------------------------------------
int sub_44CCA0()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[830616], 0, 0x6Cu);
    memset(&byte_5D4594[830724], 0, 0x6Cu);
    memset(&byte_5D4594[830296], 0, 0x6Cu);
    return result;
}

//----- (0044CCD0) --------------------------------------------------------
size_t sub_44CCD0()
{
    int i; // esi
    size_t result; // eax

    for (i = 0; i < 108; i += 4)
    {
        result = *(_DWORD*)& byte_5D4594[i + 830616];
        if (result)
        {
            result = (size_t)nox_calloc(1u, 8 * result);
            *(_DWORD*)& byte_5D4594[i + 830296] = result;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[i + 830296] = 0;
        }
        *(_DWORD*)& byte_5D4594[i + 830724] = 0;
    }
    return result;
}

//----- (0044CD10) --------------------------------------------------------
CHAR* __cdecl sub_44CD10(CHAR* a1)
{
    CHAR* result; // eax

    result = a1;
    if (a1)
    {
        result = (CHAR*)sub_44CD30(a1);
        if ((int)result >= 0)
            ++* (_DWORD*)& byte_5D4594[4 * (_DWORD)result + 830616];
    }
    return result;
}

//----- (0044CD30) --------------------------------------------------------
int __cdecl sub_44CD30(CHAR* a1)
{
    int result; // eax
    int v2; // eax

    if (!a1)
        return -1;
    v2 = toupper(*a1);
    if (v2 < 65 || v2 > 90)
        result = 26;
    else
        result = v2 - 65;
    return result;
}

//----- (0044CD60) --------------------------------------------------------
void __cdecl sub_44CD60(nox_thing* a1, int a2)
{
    if (!a1)
        return;

    int v2 = sub_44CD30(a1->name);
    if (v2 < 0)
        return;

    int v3 = *(_DWORD*)& byte_5D4594[4 * v2 + 830296];
    if (!v3)
        return;

    int v4 = *(_DWORD*)& byte_5D4594[4 * v2 + 830724];
    *(_DWORD*)(v3 + 8 * v4) = a1;
    *(_DWORD*)(v3 + 8 * v4 + 4) = a2;
    ++* (_DWORD*)& byte_5D4594[4 * v2 + 830724];
}

//----- (0044CDB0) --------------------------------------------------------
void sub_44CDB0()
{
    int i; // esi
    signed int v1; // eax

    for (i = 0; i < 108; i += 4)
    {
        v1 = *(_DWORD*)& byte_5D4594[i + 830616];
        if (v1 > 1)
            qsort(*(void**)& byte_5D4594[i + 830296], v1, 8u, sub_44CDE0);
    }
}

//----- (0044CDE0) --------------------------------------------------------
int __cdecl sub_44CDE0(const void* a1, const void* a2)
{
    return _strcmpi(**(const char***)a1, **(const char***)a2);
}

//----- (0044CE00) --------------------------------------------------------
int __cdecl nox_parse_thing(int a1, char* a2, nox_thing* obj)
{
    char* v3; // ebx
    unsigned __int8* v4; // eax
    char* v5; // edi
    char* v8; // eax
    unsigned __int8 v10; // [esp+18h] [ebp+8h]

    v3 = a2;
    while (1)
    {
        v4 = *(unsigned __int8**)(a1 + 8);
        v10 = *v4;
        *(_DWORD*)(a1 + 8) = v4 + 1;
        if (!v10)
            return 1;
        sub_40ACC0(v3, 1u, v10, a1);
        v3[v10] = 0;
        v5 = strtok(v3, " \t\n\r");
        for (int i = 0; i < nox_parse_thing_funcs_cnt; i++)
        {
            nox_parse_thing_funcs_t* v6 = &nox_parse_thing_funcs[i];
            if (strcmp(v5, v6->name) == 0)
            {
                v8 = strtok(0, "=");
                if (v8)
                    memmove(v3, v8 + 1, strlen(v8 + 1) + 1);
                v6->parse_func(obj, a1, v3);
                break;
            }
        }
    }
}

//----- (0044CEF0) --------------------------------------------------------
char* __cdecl nox_get_thing_name(int i)
{
    if (i < 1 || i >= nox_things_count)
        return 0;
    return nox_things_array[i]->name;
}

//----- (0044CF10) --------------------------------------------------------
nox_thing* __cdecl nox_get_thing(int i)
{
    if (i < 1 || i >= nox_things_count)
        return 0;
    return nox_things_array[i];
}

//----- (0044CF30) --------------------------------------------------------
wchar_t* __cdecl nox_get_thing_field_4(int i)
{
    if (i < 1 || i >= nox_things_count)
        return 0;
    return nox_things_array[i]->field_4;
}

//----- (0044CF60) --------------------------------------------------------
wchar_t* __cdecl nox_get_thing_field_8(int i)
{
    if (i < 1 || i >= nox_things_count)
        return 0;
    return nox_things_array[i]->field_8;
}

//----- (0044CF90) --------------------------------------------------------
int __cdecl nox_get_thing_field_70(int i)
{
    if (i < 1 || i >= nox_things_count)
        return 0;
    return nox_things_array[i]->field_70;
}

//----- (0044CFC0) --------------------------------------------------------
int __cdecl sub_44CFC0(CHAR* a1)
{
    return sub_44CFD0(a1);
}

//----- (0044CFD0) --------------------------------------------------------
int __cdecl sub_44CFD0(CHAR* a1)
{
    int v1; // eax
    signed int v2; // ecx
    const void* v3; // eax
    _DWORD* v4; // eax
    int result; // eax

    if (a1
        && (v1 = sub_44CD30(a1), v1 >= 0)
        && (v2 = *(_DWORD*)& byte_5D4594[4 * v1 + 830616], v2 >= 0)
        && (v3 = *(const void**)& byte_5D4594[4 * v1 + 830296]) != 0
        && (v4 = bsearch(a1, v3, v2, 8u, sub_44D020)) != 0)
    {
        result = v4[1];
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0044D020) --------------------------------------------------------
int __cdecl sub_44D020(const void* a1, const void* a2)
{
    return _strcmpi((const char*)a1, **(const char***)a2);
}

//----- (0044D040) --------------------------------------------------------
int __cdecl sub_44D040(int i)
{
    nox_thing* obj = nox_get_thing(i);
    if (!obj)
        return 0;
    return (obj->pri_class >> 22) & 1;
}

//----- (0044D060) --------------------------------------------------------
BOOL __cdecl sub_44D060(int a1)
{
    int v1; // eax

    v1 = nox_get_thing(a1);
    return v1 && *(_DWORD*)(v1 + 32) & 0x400000 && *(_BYTE*)(v1 + 36) & 0x18;
}

//----- (0044D090) --------------------------------------------------------
int __cdecl sub_44D090(int a1)
{
    int result; // eax

    result = nox_get_thing(a1);
    if (result)
        result = (*(_DWORD*)(result + 32) & 0x20400000) != 0;
    return result;
}

//----- (0044D0C0) --------------------------------------------------------
int __cdecl sub_44D0C0(float a1, int i)
{
    float v2; // esi
    _DWORD* v3; // ebx
    _DWORD* v4; // ebp
    int v5; // edi
    int v6; // ecx
    float v9; // [esp+4h] [ebp+4h]

    if (i < 1 || i >= nox_things_count)
        return 0;
    v2 = a1;
    memset((void*)LODWORD(a1), 0, 0x200u);
    *(_DWORD*)(LODWORD(a1) + 108) = i;
    v3 = (_DWORD*)(LODWORD(a1) + 136);
    v4 = (_DWORD*)(LODWORD(a1) + 152);
    v5 = &(nox_things_array[i]->field_c);
    *(_BYTE*)LODWORD(a1) = *(_BYTE*)v5;
    *(_BYTE*)(LODWORD(a1) + 1) = *(_BYTE*)(v5 + 1);
    *(_WORD*)(LODWORD(a1) + 106) = *(_WORD*)(v5 + 10);
    *(_DWORD*)(LODWORD(a1) + 112) = *(_DWORD*)(v5 + 20);
    *(_DWORD*)(LODWORD(a1) + 116) = *(_DWORD*)(v5 + 24);
    *(_DWORD*)(LODWORD(a1) + 120) = *(_DWORD*)(v5 + 28);
    *(_DWORD*)(LODWORD(a1) + 280) = *(_DWORD*)(v5 + 72);
    *(_BYTE*)(LODWORD(a1) + 298) = *(_BYTE*)(v5 + 2);
    *(_DWORD*)(LODWORD(a1) + 300) = *(_DWORD*)(v5 + 76);
    *(_DWORD*)(LODWORD(a1) + 304) = *(_DWORD*)(v5 + 80);
    *(_DWORD*)(LODWORD(a1) + 308) = *(_DWORD*)(v5 + 84);
    *(_DWORD*)(LODWORD(a1) + 464) = *(_DWORD*)(v5 + 88);
    *(_DWORD*)(LODWORD(a1) + 492) = *(_DWORD*)(v5 + 92);
    *(_DWORD*)(LODWORD(a1) + 136) = *(unsigned __int8*)(v5 + 3);
    *(_DWORD*)(LODWORD(a1) + 168) = *(_DWORD*)(v5 + 4);
    *(_DWORD*)(LODWORD(a1) + 152) = *(_DWORD*)(v5 + 36);
    *(_DWORD*)(LODWORD(a1) + 156) = *(_DWORD*)(v5 + 40);
    *(_DWORD*)(LODWORD(a1) + 160) = *(_DWORD*)(v5 + 44);
    *(_WORD*)(LODWORD(a1) + 164) = *(_WORD*)(v5 + 12);
    *(_WORD*)(LODWORD(a1) + 166) = *(_WORD*)(v5 + 14);
    *(_DWORD*)(LODWORD(a1) + 44) = *(unsigned __int8*)(v5 + 8);
    *(_DWORD*)(LODWORD(a1) + 48) = *(_DWORD*)(v5 + 52);
    *(float*)(LODWORD(a1) + 52) = *(float*)(v5 + 52) * *(float*)(v5 + 52);
    *(_DWORD*)(LODWORD(a1) + 56) = *(_DWORD*)(v5 + 64);
    *(_DWORD*)(LODWORD(a1) + 60) = *(_DWORD*)(v5 + 68);
    *(_DWORD*)(LODWORD(a1) + 96) = *(_DWORD*)(v5 + 56);
    v6 = *(_DWORD*)(LODWORD(a1) + 44);
    *(_DWORD*)(LODWORD(a1) + 100) = *(_DWORD*)(v5 + 60);
    if (v6 == 3)
        sub_428270((shape*)(LODWORD(a1) + 44));
    v9 = *(float*)(v5 + 32);
    if (v9 >= *(double*)& byte_581450[9568])
    {
        *(_DWORD*)(LODWORD(v2) + 172) = 0;
    }
    else
    {
        v9 = -v9;
        *(_DWORD*)(LODWORD(v2) + 172) = 1;
    }
    *(float*)(LODWORD(v2) + 140) = v9;
    if (v9 != 0.0)
    {
        sub_484D70(LODWORD(v2) + 136, v9);
        if (!*v3)
        {
            *v3 = 1;
            *v4 = 255;
            *(_DWORD*)(LODWORD(v2) + 156) = 255;
            *(_DWORD*)(LODWORD(v2) + 160) = 255;
        }
    }
    if (*(_DWORD*)(LODWORD(v2) + 112) & 0x13001000)
    {
        *(_DWORD*)(LODWORD(v2) + 432) = 0;
        *(_DWORD*)(LODWORD(v2) + 436) = 0;
        *(_DWORD*)(LODWORD(v2) + 440) = 0;
        *(_DWORD*)(LODWORD(v2) + 444) = 0;
        *(_WORD*)(LODWORD(v2) + 448) = -1;
        *(_WORD*)(LODWORD(v2) + 450) = -1;
    }
    nox_thing* v7 = nox_things_array[i];
    if (v7->field_78)
        sub_49B950((_DWORD*)LODWORD(v2), v7->field_78);
    return 1;
}

//----- (0044D2C0) --------------------------------------------------------
void sub_44D2C0()
{
    for (nox_thing* cur = nox_things_head; cur; cur = cur->next) {
        if (*((_BYTE*)&cur->field_14) == 3) {
            double v1 = cur->field_40;
            float v2 = cur->field_40;

            shape v3;
            v3.field_0 = 3;
            v3.field_4 = v2;
            v3.field_8 = v1 * v1;

            sub_428270(&v3);
        }
    }
}

//----- (0044D310) --------------------------------------------------------
nox_thing* nox_get_things_head()
{
    return nox_things_head;
}

//----- (0044D320) --------------------------------------------------------
int __cdecl sub_44D320(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 108);
    else
        result = 0;
    return result;
}

//----- (0044D330) --------------------------------------------------------
int __cdecl sub_44D330(CHAR* a1)
{
    return sub_44D340(a1);
}

//----- (0044D340) --------------------------------------------------------
int __cdecl sub_44D340(CHAR* a1)
{
    int v1; // eax
    signed int v2; // ecx
    int* v3; // eax
    int result; // eax

    if (a1
        && (v1 = sub_44CD30(a1), v1 >= 0)
        && (v2 = *(_DWORD*)& byte_5D4594[4 * v1 + 830616], v2 >= 0)
        && (v3 = (int*)bsearch(a1, *(const void**)& byte_5D4594[4 * v1 + 830296], v2, 8u, sub_44D020)) != 0)
    {
        result = *v3;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0044D390) --------------------------------------------------------
int nox_get_things_count()
{
    return nox_things_count;
}

//----- (0044D3A0) --------------------------------------------------------
void sub_44D3A0()
{
    if (*(_DWORD*)& byte_5D4594[831076])
    {
        switch (*(_DWORD*)& byte_5D4594[830864])
        {
        case 0:
            if (*(_DWORD*)& byte_5D4594[830872] && *(_DWORD*)& byte_587000[122848])
            {
                if (!sub_44D660(*(const char**)& byte_5D4594[830872]))
                    goto LABEL_29;
                if (!*(_DWORD*)& byte_587000[122856] || !*(_DWORD*)& byte_587000[93160] || *(_DWORD*)& byte_5D4594[831084])
                    goto LABEL_16;
                *(_DWORD*)& byte_5D4594[831084] = 1;
                sub_43DBD0();
                *(_DWORD*)& byte_5D4594[830864] = 1;
            }
            else if (*(_DWORD*)& byte_5D4594[831084])
            {
                sub_43DBE0();
                *(_DWORD*)& byte_5D4594[831084] = 0;
            }
            break;
        case 1:
            if (!sub_43DC40())
                LABEL_16 :
                *(_DWORD*)& byte_5D4594[830864] = 2;
            break;
        case 2:
            sub_486320(&byte_5D4594[830876], 0x4000);
            if (!sub_44D7E0(*(int*)& byte_5D4594[830868]))
            {
                *(_DWORD*)& byte_5D4594[830864] = 0;
                goto LABEL_29;
            }
            *(_DWORD*)& byte_5D4594[830864] = 3;
            *(_DWORD*)& byte_5D4594[830972] = *(_DWORD*)& byte_5D4594[830872];
            *(_DWORD*)& byte_5D4594[830860] = *(_DWORD*)& byte_5D4594[830868];
            break;
        case 3:
            if (!*(_DWORD*)& byte_587000[122848]
                || !*(_DWORD*)& byte_5D4594[830972]
                || *(_DWORD*)& byte_5D4594[830872] != *(_DWORD*)& byte_5D4594[830972]
                || !*(_DWORD*)& byte_5D4594[831088]
                || AIL_stream_status(*(_DWORD*)& byte_5D4594[831088]) == 2)
            {
                *(_DWORD*)& byte_5D4594[830864] = 4;
                sub_486350((int)& byte_5D4594[830876], 0);
            }
            break;
        case 4:
            if (!*(_DWORD*)& byte_5D4594[831088]
                || AIL_stream_status(*(_DWORD*)& byte_5D4594[831088]) == 2
                || !(*(_DWORD*)& byte_5D4594[830880] & 0xFFFF0000))
            {
                sub_44D640();
                *(_DWORD*)& byte_5D4594[830864] = 0;
                if (*(_DWORD*)& byte_5D4594[831084])
                {
                    sub_43DBE0();
                    *(_DWORD*)& byte_5D4594[831084] = 0;
                }
                if (*(_DWORD*)& byte_5D4594[830972] == *(_DWORD*)& byte_5D4594[830872])
                    LABEL_29:
                *(_DWORD*)& byte_5D4594[830872] = 0;
            }
            break;
        default:
            break;
        }
        sub_486520((unsigned int*)& byte_5D4594[830980]);
        sub_486520((unsigned int*)& byte_5D4594[830876]);
        if (*(_DWORD*)& byte_5D4594[831088]
            && (**(_BYTE * *)& byte_587000[81128] & 2 || byte_5D4594[830876] & 2 || byte_5D4594[830980] & 2))
        {
            sub_44D5C0(*(int*)& byte_5D4594[831088], *(int*)& byte_5D4594[830860]);
        }
    }
}
// 58141C: using guessed type int __stdcall AIL_stream_status(_DWORD);

//----- (0044D5C0) --------------------------------------------------------
void __cdecl sub_44D5C0(int a1, int a2)
{
    unsigned int v2; // eax

    if (a1)
    {
        v2 = (*(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 4) >> 16)
            * ((*(unsigned __int16*)& byte_5D4594[830882]
                * ((a2 * (unsigned int) * (unsigned __int16*)& byte_5D4594[830986]) >> 14)) >> 14);
        *(_DWORD*)& byte_5D4594[830876] &= 0xFFFFFFFD;
        **(_DWORD * *)& byte_587000[122852] &= 0xFFFFFFFD;
        AIL_set_stream_volume(a1, (int)(127 * (v2 >> 14)) / 100);
    }
}
// 581430: using guessed type int __stdcall AIL_set_stream_volume(_DWORD, _DWORD);

//----- (0044D640) --------------------------------------------------------
int sub_44D640()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[831088];
    if (*(_DWORD*)& byte_5D4594[831088])
    {
        AIL_close_stream(*(_DWORD*)& byte_5D4594[831088]);
        *(_DWORD*)& byte_5D4594[831088] = 0;
    }
    return result;
}
// 581418: using guessed type int __stdcall AIL_close_stream(_DWORD);

//----- (0044D660) --------------------------------------------------------
BOOL __cdecl sub_44D660(const char* a1)
{
    unsigned __int8 v1; // dl
    char* v2; // edi
    int v3; // eax
    char* v4; // eax
    unsigned int v5; // kr08_4
    char v7[540]; // [esp+Ch] [ebp-21Ch]

    sub_44D640();
    strcpy(v7, "dialog\\");
    *(_DWORD*)& byte_587000[122856] = 0;
    strcat(v7, a1);
    if (!strchr(v7, 46))
    {
        v1 = byte_587000[122872];
        v2 = &v7[strlen(v7)];
        *(_DWORD*)v2 = *(_DWORD*)& byte_587000[122868];
        v2[4] = v1;
    }
    v3 = AIL_open_stream(*(_DWORD*)& byte_5D4594[831092], v7, 51200);
    *(_DWORD*)& byte_5D4594[831088] = v3;
    if (v3)
        return v3 != 0;
    v4 = sub_413890();
    if (!v4)
    {
        v3 = *(_DWORD*)& byte_5D4594[831088];
        return v3 != 0;
    }
    *(_DWORD*)& byte_587000[122856] = 1;
    strncpy(&v7[40], v4, 0x1F4u);
    v7[539] = 0;
    v5 = strlen(&v7[40]) + 1;
    if (v5 != 1 && v7[v5 + 38] != 92)
        * (_WORD*)& v7[strlen(&v7[40]) + 40] = *(_WORD*)& byte_587000[122876];
    strcat(&v7[40], v7);
    *(_DWORD*)& byte_5D4594[831088] = AIL_open_stream(*(_DWORD*)& byte_5D4594[831092], &v7[40], 51200);
    return *(_DWORD*)& byte_5D4594[831088] != 0;
}
// 581408: using guessed type int __stdcall AIL_open_stream(_DWORD, _DWORD, _DWORD);

//----- (0044D7E0) --------------------------------------------------------
int __cdecl sub_44D7E0(int a1)
{
    if (!*(_DWORD*)& byte_5D4594[831088])
        return 0;
    sub_44D5C0(*(int*)& byte_5D4594[831088], a1);
    AIL_start_stream(*(_DWORD*)& byte_5D4594[831088]);
    return 1;
}
// 581410: using guessed type int __stdcall AIL_start_stream(_DWORD);

//----- (0044D810) --------------------------------------------------------
int sub_44D810()
{
    int v1; // [esp+4h] [ebp-4h]

    if (!*(_DWORD*)& byte_5D4594[831076])
    {
        *(_DWORD*)& byte_5D4594[831092] = sub_43F130();
        *(_DWORD*)& byte_587000[122848] = *(_DWORD*)& byte_5D4594[831092] != 0;
        sub_4864A0(&byte_5D4594[830876]);
        sub_486380(&byte_5D4594[830876], 0x1F4u, 0, 0x4000);
        *(_DWORD*)& byte_5D4594[830864] = 0;
        *(_DWORD*)& byte_5D4594[830972] = 0;
        *(_DWORD*)& byte_5D4594[830872] = 0;
        *(_DWORD*)& byte_5D4594[831080] = 0;
        *(_DWORD*)& byte_5D4594[831084] = 0;
        *(_DWORD*)& byte_5D4594[831076] = 1;
        loadString_sub_40F1D0((char*)& byte_587000[122920], &v1, "C:\\NoxPost\\src\\client\\Audio\\AudDiag.c", 279);
        if (v1)
            sub_44D900(v1, 0);
    }
    return 1;
}

//----- (0044D8C0) --------------------------------------------------------
void sub_44D8C0()
{
    if (*(_DWORD*)& byte_5D4594[831076])
    {
        sub_44D8F0();
        sub_44D640();
        sub_44D3A0();
        *(_DWORD*)& byte_5D4594[831076] = 0;
    }
}

//----- (0044D8F0) --------------------------------------------------------
int sub_44D8F0()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[830872] = 0;
    *(_DWORD*)& byte_5D4594[830972] = 0;
    return result;
}

//----- (0044D900) --------------------------------------------------------
int __cdecl sub_44D900(int a1, int a2)
{
    int v2; // eax

    if (*(_DWORD*)& byte_587000[122848] && a1)
    {
        v2 = a2;
        if (a2 > 100)
            v2 = 100;
        *(_DWORD*)& byte_5D4594[830872] = a1;
        *(_DWORD*)& byte_5D4594[830868] = v2;
    }
    return 1;
}

//----- (0044D930) --------------------------------------------------------
int sub_44D930()
{
    if (!*(_DWORD*)& byte_587000[122848])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830872] || *(_DWORD*)& byte_5D4594[831088])
        return 1;
    return 0;
}

//----- (0044D960) --------------------------------------------------------
void sub_44D960()
{
    *(_DWORD*)& byte_587000[122848] = 0;
}

//----- (0044D970) --------------------------------------------------------
int sub_44D970()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[831092];
    if (*(_DWORD*)& byte_5D4594[831092])
        * (_DWORD*)& byte_587000[122848] = 1;
    return result;
}

//----- (0044D990) --------------------------------------------------------
int sub_44D990()
{
    return *(_DWORD*)& byte_587000[122848];
}

//----- (0044D9A0) --------------------------------------------------------
int sub_44D9A0()
{
    if (*(_DWORD*)& byte_5D4594[823772])
    {
        return 1;
    }
    sub_44D9D0();
    return 1;
}

//----- (0044D9D0) --------------------------------------------------------
void sub_44D9D0()
{
    struc_36* arr = (struc_36*)& byte_5D4594[831108];
    for (int i = 0; i < 4; i++)
    {
        arr[i].fields[0] = 0;
    }
}

//----- (0044D9F0) --------------------------------------------------------
int __cdecl sub_44D9F0(int a1)
{
    int v1; // ebx
    unsigned __int8* v2; // edi
    int v3; // ebp
    unsigned __int8* v4; // esi
    int result; // eax
    int (*result2)(void); // eax

    v1 = 1;
    if (a1)
        v1 = 5;
    *(_DWORD*)& byte_5D4594[831100] = clock();
    v2 = &byte_5D4594[831112];
    v3 = 4;
    do
    {
        v4 = v2 - 4;
        result = (int)(*((_DWORD*)v2 - 1) & 5);
        if (result == v1)
        {
            (*((void(__cdecl * *)(unsigned __int8*))v2 + 5))(v2 - 4);
            result = *(int*)v2;
            if (*(int*)v2 <= 0)
            {
                if (!(*v4 & 2))
                {
                    result2 = (int (*)(void)) * ((_DWORD*)v2 + 4);
                    *(_DWORD*)v4 &= ~v1;
                    if (result2)
                        result = result2();
                }
            }
            else
            {
                result--;
                *(_DWORD*)v2 = result;
            }
        }
        v2 += 28;
        --v3;
    } while (v3);
    return result;
}

//----- (0044DA60) --------------------------------------------------------
int __cdecl sub_44DA60(int a1)
{
    if (sub_44DFD0(sub_44DD70))
    {
        return 1;
    }
    struc_36* obj = sub_44DF50();
    if (!obj)
        return 0;
    int v1 = 3;
    if (a1)
        v1 = 7;
    obj->fields[0] = v1;
    obj->fields[1] = 0;
    obj->fields[2] = 0;
    obj->fields[3] = 0;
    obj->field_5 = 0;
    obj->field_6 = sub_44DDC0;
    return 1;
}

//----- (0044DAB0) --------------------------------------------------------
int __cdecl sub_44DAB0(int a1, int a2, void (*a3)(void))
{
    if (*(_DWORD*)& byte_5D4594[2650672] == 1)
    {
        if (a3)
            a3();
        return 1;
    }
    sub_44DF90(sub_44DD20);
    struc_36* obj = sub_44DF50();
    if (!obj)
        return 0;

    int v3 = 1;
    if (a2)
        v3 = 5;
    obj->fields[0] = v3;
    obj->fields[1] = a1;
    obj->fields[2] = 0;
    obj->fields[3] = 16711680 / a1;
    obj->field_5 = a3;
    obj->field_6 = sub_44DD20;
    return 1;
}

//----- (0044DB30) --------------------------------------------------------
int __cdecl sub_44DB30(int a1, int a2, void (*a3)(void))
{
    sub_44DF90(sub_44DD70);
    struc_36* obj = sub_44DF50();
    if (!obj)
    {
        return 0;
    }
    int v3 = 1;
    if (a2)
        v3 = 5;
    obj->fields[0] = v3;
    obj->fields[1] = a1;
    obj->fields[2] = 0;
    obj->fields[3] = 16711680 / a1;
    obj->field_5 = a3;
    obj->field_6 = sub_44DD70;
    sub_44DF90(sub_44DDC0);
    return 1;
}

//----- (0044DBA0) --------------------------------------------------------
int __cdecl sub_44DBA0(int a1, int a2, void (*a3)(void))
{
    struc_36* obj = sub_44DF50();
    if (!obj)
    {
        return 0;
    }
    int v3 = 1;
    if (a2)
        v3 = 5;
    obj->fields[0] = v3;
    obj->fields[1] = a1;
    obj->fields[2] = 0;
    obj->fields[3] = 16711680 / a1;
    obj->field_5 = a3;
    obj->field_6 = sub_44DDF0;
    return 1;
}

//----- (0044DBF0) --------------------------------------------------------
int __cdecl sub_44DBF0(int a1, int a2, void (*a3)(void))
{
    struc_36* obj = sub_44DF50();
    if (!obj)
    {
        return 0;
    }
    int v3 = 1;
    if (a2)
        v3 = 5;
    obj->fields[0] = v3;
    obj->fields[1] = a1;
    obj->fields[2] = 0;
    obj->fields[3] = 16711680 / a1;
    obj->field_5 = a3;
    obj->field_6 = sub_44DE30;
    return 1;
}

//----- (0044DC40) --------------------------------------------------------
int __cdecl sub_44DC40(int a1, int a2)
{
    struc_36* obj = sub_44DF50();
    if (!obj)
    {
        return 0;
    }
    int v4 = a1 * nox_backbuffer_height / 100;
    obj->fields[0] = 3;
    obj->fields[1] = a2;
    obj->fields[2] = 0;
    obj->fields[3] = (v4 << 16) / a2;
    obj->field_5 = 0;
    obj->field_6 = sub_44DE80;
    return 1;
}

//----- (0044DCA0) --------------------------------------------------------
int __cdecl sub_44DCA0(int a1, int a2)
{
    struc_36* obj = sub_44DF50();
    if (!obj)
    {
        return 0;
    }
    int v4 = a1 * nox_backbuffer_height / 100;
    v4 <<= 16;
    obj->fields[0] = 1;
    obj->fields[1] = a2;
    obj->fields[2] = v4;
    obj->fields[3] = v4 / a2;
    obj->fields[4] = 0;
    obj->field_5 = 0;
    obj->field_6 = sub_44DEE0;
    return 1;
}

//----- (0044DD00) --------------------------------------------------------
BOOL sub_44DD00()
{
    return sub_44DFD0(sub_44DE80) != 0;
}

//----- (0044DD20) --------------------------------------------------------
int __cdecl sub_44DD20(int a1)
{
    int result; // eax

    sub_433F10(*(int*)(a1 + 8) >> 16, *(int*)(a1 + 8) >> 16, *(int*)(a1 + 8) >> 16);
    sub_49D0F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
    result = *(_DWORD*)(a1 + 12);
    *(_DWORD*)(a1 + 8) += result;
    return result;
}

//----- (0044DD70) --------------------------------------------------------
int __cdecl sub_44DD70(int a1)
{
    int v1; // esi
    int result; // eax
    unsigned __int8 v3; // [esp+8h] [ebp+4h]

    v1 = a1;
    v3 = -1 - (*(int*)(a1 + 8) >> 16);
    sub_433F10(v3, v3, v3);
    sub_49D0F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
    result = *(_DWORD*)(v1 + 12) + *(_DWORD*)(v1 + 8);
    *(_DWORD*)(v1 + 8) = result;
    return result;
}

//----- (0044DDC0) --------------------------------------------------------
void sub_44DDC0()
{
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_49CE30(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (0044DDF0) --------------------------------------------------------
int4* __cdecl sub_44DDF0(int a1)
{
    int v1; // edx

    v1 = *(_DWORD*)(a1 + 12) + *(_DWORD*)(a1 + 8);
    *(_DWORD*)(a1 + 8) = v1;
    sub_433F10(BYTE2(v1), BYTE2(v1), BYTE2(v1));
    return sub_49D050(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (0044DE30) --------------------------------------------------------
int4* __cdecl sub_44DE30(int a1)
{
    int v1; // edx

    v1 = *(_DWORD*)(a1 + 12) + *(_DWORD*)(a1 + 8);
    *(_DWORD*)(a1 + 8) = v1;
    sub_433F10(-1 - BYTE2(v1), -1 - BYTE2(v1), -1 - BYTE2(v1));
    return sub_49D050(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (0044DE80) --------------------------------------------------------
void __cdecl sub_44DE80(_DWORD* a1)
{
    int v1; // esi

    if (a1[1])
        a1[2] += a1[3];
    v1 = a1[2] >> 16;
    sub_434430(0, 0, 0);
    sub_49CE30(0, 0, nox_backbuffer_width, v1);
    sub_49CE30(0, nox_backbuffer_height - v1, nox_backbuffer_width, v1);
}

//----- (0044DEE0) --------------------------------------------------------
void __cdecl sub_44DEE0(_DWORD* a1)
{
    int v1; // ecx
    int v2; // esi

    if (!a1[4])
    {
        sub_44DF90(sub_44DE80);
        a1[4] = 1;
    }
    v1 = a1[2] - a1[3];
    a1[2] = v1;
    v2 = v1 >> 16;
    sub_434430(0, 0, 0);
    sub_49CE30(0, 0, nox_backbuffer_width, v2);
    sub_49CE30(0, nox_backbuffer_height - v2, nox_backbuffer_width, v2);
}

//----- (0044DF50) --------------------------------------------------------
struc_36* sub_44DF50()
{
    struc_36* it = (struc_36*)& byte_5D4594[831108];
    int v1 = 0;
    while (it->fields[0] & 1)
    {
        it++;
        if (++v1 >= 4)
            return 0;
    }
    return it;
}

//----- (0044DF70) --------------------------------------------------------
char* sub_44DF70()
{
    struc_36* arr = (struc_36*)& byte_5D4594[831108];
    for (int i = 0; i < 4; i++)
    {
        int v2 = arr->fields[0];
        arr++;
        *((_DWORD*)arr - 7) = v2 & 0xFFFFFFFE;
    }
    return arr;
}

//----- (0044DF90) --------------------------------------------------------
int __cdecl sub_44DF90(int a1)
{
    void (*v4)(void); // eax

    int result = 0;
    struc_36* it = (struc_36*)&byte_5D4594[831108];
    for (int i = 0; i < 4; i++)
    {
        if (it->fields[0] & 1 && it->field_6 == a1)
        {
            v4 = it->field_5;
            it->fields[0] &= 0xFFFFFFFE;
            if (v4)
                v4();
            result = 1;
        }
        it++;
    }
    return result;
}

//----- (0044DFD0) --------------------------------------------------------
int __cdecl sub_44DFD0(int a1)
{
    struc_36* it = (struc_36*)& byte_5D4594[831108];
    int v2 = 0;
    while (!(it->fields[0] & 1) || it->field_6 != a1)
    {
        it++;
        if (++v2 >= 4)
            return 0;
    }
    return it != 0;
}

//----- (0044E000) --------------------------------------------------------
void sub_44E000()
{
    if (!sub_44DFD0(sub_44DD70))
        * (_DWORD*)& byte_5D4594[2650672] = 1;
}

//----- (0044E020) --------------------------------------------------------
void sub_44E020()
{
    if (!sub_44DFD0(sub_44DD20))
        sub_413A00(0);
}

//----- (0044E040) --------------------------------------------------------
void sub_44E040()
{
    sub_44E070();
    sub_44E090();
    sub_44DF90(sub_44DDC0);
    *(_DWORD*)& byte_5D4594[2650672] = 0;
    sub_413A00(0);
}

//----- (0044E070) --------------------------------------------------------
int sub_44E070()
{
    sub_44DF90(sub_44DD70);
    return sub_44DF90(sub_44DE30);
}

//----- (0044E090) --------------------------------------------------------
int sub_44E090()
{
    sub_44DF90(sub_44DD20);
    return sub_44DF90(sub_44DDF0);
}

//----- (0044E0B0) --------------------------------------------------------
int __cdecl sub_44E0B0(int a1)
{
    sub_44E070();
    sub_44E090();
    *(_DWORD*)& byte_5D4594[2650672] = 1;
    return sub_44DA60(a1);
}

//----- (0044E0D0) --------------------------------------------------------
BOOL sub_44E0D0()
{
    if (sub_44DFD0(sub_44DD70))
        return 1;
    if (sub_44DFD0(sub_44DD20))
        return 1;
    return *(_DWORD*)& byte_5D4594[2650672] != 0;
}

//----- (0044E110) --------------------------------------------------------
_DWORD* sub_44E110()
{
    _DWORD* v0; // eax
    int v1; // eax
    _DWORD* v2; // eax
    int v3; // eax
    _DWORD* v4; // eax
    int v5; // eax
    _DWORD* v6; // eax
    int v7; // eax
    _DWORD* v8; // eax
    int v9; // eax
    _DWORD* v10; // eax
    int v11; // eax
    _DWORD* v12; // eax
    int v13; // eax
    _DWORD* v14; // eax
    int v15; // eax
    _DWORD* v16; // eax
    int v17; // eax
    _DWORD* v18; // eax
    int v19; // eax
    _DWORD* v20; // eax
    int v21; // eax
    _DWORD* result; // eax
    int v23; // eax

    if (!*(_DWORD*)& byte_5D4594[832484])
        * (_DWORD*)& byte_5D4594[832484] = sub_43F360((char*)& byte_587000[123044]);
    v0 = *(_DWORD * *)& byte_5D4594[832496];
    if (!*(_DWORD*)& byte_5D4594[832496])
    {
        v1 = sub_44CFC0((CHAR*)& byte_587000[123052]);
        v0 = sub_45A240(v1);
        *(_DWORD*)& byte_5D4594[832496] = v0;
    }
    v0[30] |= 0x1000000u;
    v2 = *(_DWORD * *)& byte_5D4594[832492];
    if (!*(_DWORD*)& byte_5D4594[832492])
    {
        v3 = sub_44CFC0((CHAR*)& byte_587000[123068]);
        v2 = sub_45A240(v3);
        *(_DWORD*)& byte_5D4594[832492] = v2;
    }
    v2[30] |= 0x1000000u;
    v4 = *(_DWORD * *)& byte_5D4594[832500];
    if (!*(_DWORD*)& byte_5D4594[832500])
    {
        v5 = sub_44CFC0((CHAR*)& byte_587000[123088]);
        v4 = sub_45A240(v5);
        *(_DWORD*)& byte_5D4594[832500] = v4;
    }
    v4[30] |= 0x1000000u;
    v6 = *(_DWORD * *)& byte_5D4594[832504];
    if (!*(_DWORD*)& byte_5D4594[832504])
    {
        v7 = sub_44CFC0((CHAR*)& byte_587000[123096]);
        v6 = sub_45A240(v7);
        *(_DWORD*)& byte_5D4594[832504] = v6;
    }
    v6[30] |= 0x1000000u;
    v8 = *(_DWORD * *)& byte_5D4594[832508];
    if (!*(_DWORD*)& byte_5D4594[832508])
    {
        v9 = sub_44CFC0((CHAR*)& byte_587000[123108]);
        v8 = sub_45A240(v9);
        *(_DWORD*)& byte_5D4594[832508] = v8;
    }
    v8[30] |= 0x1000000u;
    v10 = *(_DWORD * *)& byte_5D4594[832512];
    if (!*(_DWORD*)& byte_5D4594[832512])
    {
        v11 = sub_44CFC0((CHAR*)& byte_587000[123120]);
        v10 = sub_45A240(v11);
        *(_DWORD*)& byte_5D4594[832512] = v10;
    }
    v10[30] |= 0x1000000u;
    v12 = *(_DWORD * *)& byte_5D4594[832516];
    if (!*(_DWORD*)& byte_5D4594[832516])
    {
        v13 = sub_44CFC0((CHAR*)& byte_587000[123128]);
        v12 = sub_45A240(v13);
        *(_DWORD*)& byte_5D4594[832516] = v12;
    }
    v12[30] |= 0x1000000u;
    v14 = *(_DWORD * *)& byte_5D4594[832520];
    if (!*(_DWORD*)& byte_5D4594[832520])
    {
        v15 = sub_44CFC0((CHAR*)& byte_587000[123144]);
        v14 = sub_45A240(v15);
        *(_DWORD*)& byte_5D4594[832520] = v14;
    }
    v14[30] |= 0x1000000u;
    v16 = *(_DWORD * *)& byte_5D4594[832524];
    if (!*(_DWORD*)& byte_5D4594[832524])
    {
        v17 = sub_44CFC0((CHAR*)& byte_587000[123160]);
        v16 = sub_45A240(v17);
        *(_DWORD*)& byte_5D4594[832524] = v16;
    }
    v16[30] |= 0x1000000u;
    v18 = *(_DWORD * *)& byte_5D4594[832528];
    if (!*(_DWORD*)& byte_5D4594[832528])
    {
        v19 = sub_44CFC0((CHAR*)& byte_587000[123176]);
        v18 = sub_45A240(v19);
        *(_DWORD*)& byte_5D4594[832528] = v18;
    }
    v18[30] |= 0x1000000u;
    v20 = *(_DWORD * *)& byte_5D4594[832532];
    if (!*(_DWORD*)& byte_5D4594[832532])
    {
        v21 = sub_44CFC0((CHAR*)& byte_587000[123188]);
        v20 = sub_45A240(v21);
        *(_DWORD*)& byte_5D4594[832532] = v20;
    }
    v20[30] |= 0x1000000u;
    result = *(_DWORD * *)& byte_5D4594[832536];
    if (!*(_DWORD*)& byte_5D4594[832536])
    {
        v23 = sub_44CFC0((CHAR*)& byte_587000[123200]);
        result = sub_45A240(v23);
        *(_DWORD*)& byte_5D4594[832536] = result;
    }
    result[30] |= 0x1000000u;
    return result;
}

//----- (0044E320) --------------------------------------------------------
void sub_44E320()
{
    int v0; // eax

    sub_46ADE0(*(int*)& byte_5D4594[831236]);
    sub_46B500(0);
    nox_window_set_hidden(*(int*)& byte_5D4594[831236], 1);
    sub_450580();
    sub_43DDA0();
    *(_DWORD*)& byte_5D4594[2650672] = 0;
    if (*(_DWORD*)& byte_5D4594[831220] == 255)
    {
        if (*(_DWORD*)& byte_5D4594[815132] == 1)
        {
            sub_4505E0();
            sub_4A2500();
            sub_578E00();
        }
    }
    else if (byte_5D4594[832472] & 5)
    {
        sub_450160(254, 1, 2);
        return;
    }
    v0 = sub_44E3B0();
    sub_44DB30(v0, 1, sub_44E3C0);
}

//----- (0044E3B0) --------------------------------------------------------
int sub_44E3B0()
{
    return 25;
}

//----- (0044E3C0) --------------------------------------------------------
int sub_44E3C0()
{
    sub_450580();
    *(_DWORD*)& byte_5D4594[831260] = 0;
    return sub_413A00(0);
}

//----- (0044E3E0) --------------------------------------------------------
int sub_44E3E0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[831224];
    *(_DWORD*)& byte_5D4594[831248] = 1;
    if (*(_DWORD*)& byte_5D4594[831224])
    {
        result = sub_44D900(*(int*)& byte_5D4594[831240], 100);
        *(_DWORD*)& byte_5D4594[831244] = 1;
    }
    return result;
}

//----- (0044E410) --------------------------------------------------------
wchar_t* sub_44E410()
{
    int v0; // esi
    int v1; // edi
    int i; // ebp
    int v3; // ebx
    int v4; // esi
    wchar_t* result; // eax
    int v6; // [esp-2Ch] [ebp-80h]
    int v7; // [esp+10h] [ebp-44h]
    char v8[64]; // [esp+14h] [ebp-40h]

    v0 = 0;
    v7 = 0;
    v1 = 0;
    for (i = 1; ; ++i)
    {
        while (1)
        {
            if (v0)
            {
                if (v0 == 1)
                    v3 = v1 ? (v1 != 1) + 2 : 4;
                else
                    v3 = v0 + 3;
            }
            else
            {
                v3 = 1;
            }
            nox_sprintf(v8, "Briefing:%sChapterBegin%d", *(_DWORD*)& byte_587000[4 * v1 + 122944], i);
            v4 = 32 * (v1 + v0 + 10 * v1);
            *(_DWORD*)& byte_5D4594[v4 + 831300] = sub_42F970(&v8[9]);
            *(_DWORD*)& byte_5D4594[v4 + 831304] = loadString_sub_40F1D0(
                v8,
                &byte_5D4594[v4 + 831308],
                "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c",
                1221);
            v6 = *(_DWORD*)& byte_587000[4 * v1 + 122944];
            *(_DWORD*)& byte_5D4594[v4 + 831312] = v3;
            nox_sprintf(v8, "Briefing:%sChapterLoss%d", v6, i);
            *(_DWORD*)& byte_5D4594[v4 + 831316] = sub_42F970(&v8[9]);
            ++v1;
            *(_DWORD*)& byte_5D4594[v4 + 831320] = loadString_sub_40F1D0(
                v8,
                &byte_5D4594[v4 + 831324],
                "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c",
                1227);
            *(_DWORD*)& byte_5D4594[v4 + 831328] = v3;
            if (v1 >= 3)
                break;
            v0 = v7;
        }
        v7 = i;
        if (i >= 11)
            break;
        v0 = i;
        v1 = 0;
    }
    *(_DWORD*)& byte_5D4594[831264] = sub_42F970("CreditsImage");
    result = loadString_sub_40F1D0((char*)& byte_587000[123412], &byte_5D4594[831272], "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1233);
    *(_DWORD*)& byte_5D4594[831268] = result;
    return result;
}

//----- (0044E560) --------------------------------------------------------
_DWORD* sub_44E560()
{
    _DWORD* result; // eax
    _DWORD* v1; // eax

    *(_DWORD*)& byte_5D4594[831284] = (nox_win_width - default_win_width) / 2;
    *(_DWORD*)& byte_5D4594[831288] = (nox_win_height - default_win_height) / 2;
    result = nox_window_new(0, 56, 0, 0, nox_win_width, nox_win_height, sub_44E6E0);
    *(_DWORD*)& byte_5D4594[831236] = result;
    if (result)
    {
        sub_46B300((int)result, sub_44E630);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[831236] + 56) = *(_DWORD*)& byte_5D4594[2650656];
        result = nox_new_window_from_file("Briefing.wnd", 0);
        *(_DWORD*)& byte_5D4594[831232] = result;
        if (result)
        {
            sub_46B120(result, *(int*)& byte_5D4594[831236]);
            sub_46A9B0(*(_DWORD * *)& byte_5D4594[831232], *(int*)& byte_5D4594[831284], *(int*)& byte_5D4594[831288]);
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[831232], 1010);
            sub_46B340((int)v1, sub_44E6F0);
            sub_44E410();
            result = *(_DWORD * *)& byte_5D4594[831236];
        }
    }
    return result;
}

//----- (0044E630) --------------------------------------------------------
int __cdecl sub_44E630(int a1, int a2, int a3, int a4)
{
    int v2; // eax

    if (*(_DWORD*)& byte_5D4594[831248] && a2 != 18 && a2 != 17 && sub_41D1B0() != 1)
    {
        sub_450580();
        if (*(_DWORD*)& byte_5D4594[831220])
        {
            if (*(_DWORD*)& byte_5D4594[831220] == 255)
            {
                *(_DWORD*)& byte_5D4594[2650672] = 0;
                v2 = sub_44E3B0();
                sub_44DAB0(v2, 1, sub_44E320);
                *(_DWORD*)& byte_5D4594[2650672] = 1;
            }
        }
        else
        {
            sub_46ADE0(*(int*)& byte_5D4594[831236]);
            sub_46B500(0);
            *(_DWORD*)& byte_5D4594[831256] = 1;
            sub_46D580();
        }
        sub_46B300(*(int*)& byte_5D4594[831236], 0);
    }
    return 1;
}

//----- (0044E6E0) --------------------------------------------------------
BOOL __cdecl sub_44E6E0(int a1, int a2, int a3, int a4)
{
    return a2 == 23;
}

//----- (0044E6F0) --------------------------------------------------------
int __cdecl sub_44E6F0(_DWORD* a1, int xLeft)
{
    int v2; // eax
    int v3; // eax

    *(float*)& byte_5D4594[831276] = *(float*)& byte_5D4594[831276] - sub_44E8B0();
    v2 = sub_419A70(*(float*)& byte_5D4594[831276]);
    sub_46A9B0(a1, 0, v2);
    sub_49F6F0(*(int*)& byte_5D4594[831284], *(int*)& byte_5D4594[831288], default_win_width, default_win_height);
    if (byte_5D4594[832472] & 1)
    {
        sub_44E8E0((int)a1, xLeft);
    }
    else if (byte_5D4594[832472] & 2)
    {
        sub_44F0F0((int)a1, xLeft);
    }
    else if (byte_5D4594[832472] & 4)
    {
        sub_44F300((int)a1, xLeft);
    }
    else
    {
        sub_488D00((int)a1, xLeft);
    }
    sub_49F6F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
    if ((__int64) * (float*)& byte_5D4594[831276] <= *(int*)& byte_5D4594[831280]
        && *(_DWORD*)& byte_5D4594[831244] == 1
        && !sub_44D930()
        && (unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[831292]) > 0x3A98
        && (*(_DWORD*)& byte_5D4594[832488] == 1 || !(byte_5D4594[832472] & 5)))
    {
        if (byte_5D4594[832472] & 2 && *(_DWORD*)& byte_5D4594[832480])
            sub_452D80(582, 100);
        sub_450580();
        if (*(_DWORD*)& byte_5D4594[831220])
        {
            *(_DWORD*)& byte_5D4594[2650672] = 0;
            v3 = sub_44E3B0();
            sub_44DAB0(v3, 1, sub_44E320);
            *(_DWORD*)& byte_5D4594[2650672] = 1;
        }
        else if (!*(_DWORD*)& byte_5D4594[831256])
        {
            sub_46ADE0(*(int*)& byte_5D4594[831236]);
            *(_DWORD*)& byte_5D4594[831256] = 1;
            sub_46D580();
            sub_46B300(*(int*)& byte_5D4594[831236], 0);
        }
        sub_46B340((int)a1, sub_44E8D0);
    }
    return 1;
}

//----- (0044E8B0) --------------------------------------------------------
double sub_44E8B0()
{
    double result; // st7

    if (*(_DWORD*)& byte_5D4594[831220] == 255)
        result = 1.0;
    else
        result = 0.0;
    return result;
}

//----- (0044E8D0) --------------------------------------------------------
int sub_44E8D0()
{
    return 1;
}

//----- (0044E8E0) --------------------------------------------------------
int __cdecl sub_44E8E0(int a1, int a2)
{
    int v2; // ebx
    int v3; // esi
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    unsigned __int8* v6; // eax
    unsigned __int8* v7; // ebp
    int v8; // esi
    int v9; // ecx
    int v10; // ebx
    int v11; // eax
    signed int v12; // eax
    int v13; // esi
    wchar_t* v14; // eax
    int v15; // esi
    wchar_t* v16; // eax
    int v17; // esi
    wchar_t* v18; // eax
    int v19; // esi
    wchar_t* v20; // eax
    wchar_t* v21; // eax
    int v22; // ebx
    int v23; // esi
    int v24; // ebp
    wchar_t* v25; // eax
    wchar_t* v26; // eax
    int v27; // esi
    wchar_t* v28; // eax
    wchar_t* v29; // eax
    int v30; // esi
    int v31; // ebp
    int result; // eax
    int v33; // ebp
    unsigned __int16* v34; // esi
    int v35; // ebx
    float v36; // [esp+0h] [ebp-674h]
    int v37; // [esp+0h] [ebp-674h]
    int v38; // [esp+14h] [ebp-660h]
    int v39; // [esp+18h] [ebp-65Ch]
    int v40; // [esp+1Ch] [ebp-658h]
    int v41; // [esp+20h] [ebp-654h]
    int v42; // [esp+24h] [ebp-650h]
    int v43; // [esp+28h] [ebp-64Ch]
    int v44; // [esp+2Ch] [ebp-648h]
    int v45; // [esp+30h] [ebp-644h]
    int v46; // [esp+34h] [ebp-640h]
    int v47; // [esp+38h] [ebp-63Ch]
    unsigned __int8* v48; // [esp+3Ch] [ebp-638h]
    int v49; // [esp+40h] [ebp-634h]
    int v50; // [esp+44h] [ebp-630h]
    int v51; // [esp+48h] [ebp-62Ch]
    int v52; // [esp+4Ch] [ebp-628h]
    char v53; // [esp+50h] [ebp-624h]
    WCHAR WideCharStr[11]; // [esp+54h] [ebp-620h]
    wchar_t v55[257]; // [esp+72h] [ebp-602h]
    wchar_t v56[256]; // [esp+274h] [ebp-400h]
    wchar_t v57[256]; // [esp+474h] [ebp-200h]

    v49 = (nox_win_width - default_win_width) / 2;
    v47 = 0;
    v45 = 0;
    v50 = (nox_win_height - default_win_height) / 2;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v2 = nox_win_width / 2;
    v3 = nox_win_height / 2;
    v51 = nox_win_width / 2;
    v52 = nox_win_height/ 2;
    v4 = loadString_sub_40F1D0((char*)& byte_587000[123480], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 449);
    nox_wcscpy(&v55[1], v4);
    v5 = loadString_sub_40F1D0((char*)& byte_587000[123552], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 451);
    nox_wcscpy(v56, v5);
    nox_wcscat(v56, L" ");
    _itow(*(int*)& byte_5D4594[831228], WideCharStr, 10);
    nox_wcscat(v56, WideCharStr);
    nox_swprintf(v57, L"%s - %s", &v55[1], v56);
    sub_43F840(*(_DWORD*)(a2 + 200), v57, &v39, &v38, 0);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v57, v2 - v39 / 2, v38 + v3 - 240);
    v40 = *(_DWORD*)& byte_587000[122968] - *(_DWORD*)& byte_587000[122964];
    v36 = (double)v38 * 1.5;
    v41 = sub_419A70(v36);
    v6 = &byte_587000[122964];
    v43 = 0;
    v42 = 0;
    v7 = &byte_5D4594[832364];
    v48 = &byte_587000[122964];
    while (1)
    {
        v8 = *(_DWORD*)v6 + v3 - 240;
        v9 = *(_DWORD*)v7;
        v10 = *((_DWORD*)v6 - 1) + v2 - 320;
        if (*(_DWORD*)v7)
        {
            ++v43;
            if (v9 == *(_DWORD*)& byte_5D4594[2618908])
                v47 = *((unsigned __int16*)v7 + 5);
            else
                v45 += *((unsigned __int16*)v7 + 5);
            sub_434390(*(int*)& byte_5D4594[2614256]);
            nox_swprintf(&v55[1], L"%d) %s", v42 + 1, *(_DWORD*)v7 + 4704);
            v11 = *(_DWORD*)(a2 + 200);
            v46 = *(_DWORD*)& byte_587000[122968] - *(_DWORD*)& byte_587000[122960] + v10 - 16;
            sub_43F840(v11, &v55[1], &v44, &v53, 0);
            while (v10 + v44 >= v46)
            {
                v12 = nox_wcslen(&v55[1]);
                if (v12 <= 5)
                    break;
                v55[v12] = 0;
                sub_43F840(*(_DWORD*)(a2 + 200), &v55[1], &v44, &v53, 0);
            }
            sub_43FAF0(*(_DWORD*)(a2 + 200), &v55[1], v10, v8, v40 - 8, v38);
            v13 = v41 + v41 / 2 + v8;
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v14 = loadString_sub_40F1D0((char*)& byte_587000[123648], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 529);
            sub_43FAF0(*(_DWORD*)(a2 + 200), v14, v10, v13, *(int*)& byte_5D4594[832476], v38);
            nox_swprintf(&v55[1], L" %d", *((unsigned __int16*)v7 + 3));
            sub_434390(*(int*)& byte_5D4594[2614268]);
            sub_43FAF0(
                *(_DWORD*)(a2 + 200),
                &v55[1],
                v10 + *(_DWORD*)& byte_5D4594[832476],
                v13,
                v40 - *(_DWORD*)& byte_5D4594[832476] - 8,
                v38);
            v15 = v41 + v13;
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v16 = loadString_sub_40F1D0((char*)& byte_587000[123728], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 541);
            sub_43FAF0(*(_DWORD*)(a2 + 200), v16, v10, v15, *(int*)& byte_5D4594[832476], v38);
            nox_swprintf(&v55[1], L" %d", *((unsigned __int16*)v7 + 4));
            sub_434390(*(int*)& byte_5D4594[2614268]);
            sub_43FAF0(
                *(_DWORD*)(a2 + 200),
                &v55[1],
                v10 + *(_DWORD*)& byte_5D4594[832476],
                v15,
                v40 - *(_DWORD*)& byte_5D4594[832476] - 8,
                v38);
            v17 = v41 + v15;
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v18 = loadString_sub_40F1D0((char*)& byte_587000[123804], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 553);
            sub_43FAF0(*(_DWORD*)(a2 + 200), v18, v10, v17, *(int*)& byte_5D4594[832476], v38);
            nox_swprintf(&v55[1], L" %d", *((unsigned __int16*)v7 + 2));
            sub_434390(*(int*)& byte_5D4594[2614268]);
            sub_43FAF0(
                *(_DWORD*)(a2 + 200),
                &v55[1],
                v10 + *(_DWORD*)& byte_5D4594[832476],
                v17,
                v40 - *(_DWORD*)& byte_5D4594[832476] - 8,
                v38);
            v19 = v41 + v17;
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v20 = loadString_sub_40F1D0((char*)& byte_587000[123872], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 565);
            sub_43FAF0(*(_DWORD*)(a2 + 200), v20, v10, v19, *(int*)& byte_5D4594[832476], v38);
            nox_swprintf(&v55[1], L" %d", *((_DWORD*)v7 + 3));
            sub_434390(*(int*)& byte_5D4594[2650684]);
            sub_43FAF0(
                *(_DWORD*)(a2 + 200),
                &v55[1],
                v10 + *(_DWORD*)& byte_5D4594[832476],
                v19,
                v40 - *(_DWORD*)& byte_5D4594[832476] - 8,
                v38);
            v6 = v48;
        }
        v6 += 8;
        v7 += 16;
        ++v42;
        v48 = v6;
        if ((int)v6 >= (int)& byte_587000[123012])
            break;
        v2 = v51;
        v3 = v52;
    }
    v21 = loadString_sub_40F1D0((char*)& byte_587000[123944], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 583);
    nox_swprintf(&v55[1], v21, *(_DWORD*)& byte_5D4594[832356]);
    sub_43F840(*(_DWORD*)(a2 + 200), &v55[1], &v39, &v38, 0);
    v22 = v49;
    v23 = v49 - v39 / 2 + 320;
    v24 = v50 + 2 * (150 - v38) + 150 - v38;
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)& v55[1], v23, v24);
    if (v47)
    {
        v37 = v47;
        v25 = loadString_sub_40F1D0((char*)& byte_587000[124012], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 593);
        nox_swprintf(&v55[1], v25, v37);
    }
    else
    {
        v26 = loadString_sub_40F1D0((char*)& byte_587000[124080], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 596);
        nox_swprintf(&v55[1], v26);
    }
    if (v43 <= 1)
    {
        nox_wcscpy(v57, &v55[1]);
    }
    else
    {
        v27 = v45;
        if (v45)
        {
            v28 = loadString_sub_40F1D0((char*)& byte_587000[124152], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 606);
            if (v28)
                nox_swprintf(v56, v28, v27);
        }
        else
        {
            v29 = loadString_sub_40F1D0((char*)& byte_587000[124228], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 612);
            nox_wcscpy(v56, v29);
        }
        nox_swprintf(v57, L"%s - %s", &v55[1], v56);
    }
    sub_43F840(*(_DWORD*)(a2 + 200), v57, &v39, &v38, 0);
    v30 = v22 - v39 / 2 + 320;
    v31 = v50 + 2 * (225 - v38);
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v57, v30, v31);
    result = *(_DWORD*)& byte_5D4594[2598000] / 0x1Eu;
    if (*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu)
    {
        if (*(_DWORD*)& byte_587000[122956] != 1)
            return result;
    }
    else
    {
        result = 1;
        if (*(_DWORD*)& byte_587000[122956] == 1)
        {
            *(_DWORD*)& byte_587000[122956] = *(_DWORD*)& byte_5D4594[2598000] % 0x1Eu;
            return result;
        }
        *(_DWORD*)& byte_587000[122956] = 1;
    }
    v33 = *(_DWORD*)& byte_5D4594[2523948];
    v34 = loadString_sub_40F1D0((char*)& byte_587000[124324], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 642);
    sub_43F840(*(_DWORD*)(a2 + 200), v34, &v39, 0, 0);
    v35 = v22 - v39 / 2 + 320;
    sub_434390(v33);
    return sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v34, v35, v50 + 450);
}

//----- (0044F0F0) --------------------------------------------------------
int __cdecl sub_44F0F0(int a1, int a2)
{
    int v2; // esi
    int v3; // ebx
    wchar_t* v4; // eax
    int result; // eax
    int v6; // esi
    int v7; // ebx
    unsigned __int16* v8; // ebp
    int v9; // esi
    int v10; // [esp+10h] [ebp-40Ch]
    int v11; // [esp+14h] [ebp-408h]
    int v12; // [esp+18h] [ebp-404h]
    wchar_t v13[256]; // [esp+1Ch] [ebp-400h]
    wchar_t v14[256]; // [esp+21Ch] [ebp-200h]

    v2 = nox_win_width / 2;
    v3 = nox_win_height / 2;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v4 = loadString_sub_40F1D0((char*)& byte_587000[124392], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 668);
    nox_wcscpy(v13, v4);
    nox_wcscat(v13, L" %d");
    nox_swprintf(v14, v13, *(_DWORD*)& byte_5D4594[832468]);
    sub_43F840(*(_DWORD*)(a2 + 200), v14, &v10, &v11, 0);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v14, v2 - v10 / 2, v3 + 2 * (v11 - 80) + v11 - 80);
    if (*(_DWORD*)& byte_5D4594[832464])
    {
        sub_43F840(*(_DWORD*)(a2 + 200), *(unsigned __int16**)& byte_5D4594[832464], &v10, &v11, 0);
        sub_43F6E0(*(_DWORD*)(a2 + 200), *(__int16**)& byte_5D4594[832464], v2 - v10 / 2, v3 + 2 * (80 - v11) + 80 - v11);
    }
    result = *(_DWORD*)& byte_5D4594[2598000] / 0x1Eu;
    if (*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu)
    {
        if (*(_DWORD*)& byte_587000[123008] != 1)
            return result;
    }
    else
    {
        result = 1;
        if (*(_DWORD*)& byte_587000[123008] == 1)
        {
            *(_DWORD*)& byte_587000[123008] = *(_DWORD*)& byte_5D4594[2598000] % 0x1Eu;
            return result;
        }
        *(_DWORD*)& byte_587000[123008] = 1;
    }
    v12 = *(_DWORD*)& byte_5D4594[2523948];
    v6 = (nox_win_width - default_win_width) / 2;
    v7 = (nox_win_height - default_win_height) / 2;
    v8 = loadString_sub_40F1D0((char*)& byte_587000[124460], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 714);
    sub_43F840(*(_DWORD*)(a2 + 200), v8, &v10, 0, 0);
    v9 = v6 - v10 / 2 + 320;
    sub_434390(v12);
    return sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v8, v9, v7 + 462);
}

//----- (0044F300) --------------------------------------------------------
int __cdecl sub_44F300(int a1, int a2)
{
    char* v2; // ebx
    int v3; // esi
    int v4; // edi
    unsigned __int16* v5; // ebp
    __int16* v6; // ebp
    wchar_t* v7; // eax
    int v8; // ebp
    __int16* v9; // ebp
    wchar_t* v10; // eax
    int v11; // ebp
    __int16* v12; // ebp
    wchar_t* v13; // eax
    int v14; // ebp
    __int16* v15; // ebx
    wchar_t* v16; // eax
    unsigned __int16* v17; // ebx
    unsigned __int16* v18; // ebp
    unsigned __int16* v19; // ebx
    unsigned __int16* v20; // ebp
    unsigned __int16* v21; // ebx
    unsigned __int16* v22; // ebp
    int result; // eax
    int v24; // ebp
    unsigned __int16* v25; // ebx
    int v26; // [esp-3Ch] [ebp-70h]
    int v27; // [esp+10h] [ebp-24h]
    int v28; // [esp+14h] [ebp-20h]
    unsigned __int16* v29; // [esp+18h] [ebp-1Ch]
    unsigned __int16* v30; // [esp+1Ch] [ebp-18h]
    int v31; // [esp+20h] [ebp-14h]
    unsigned __int16* v32; // [esp+24h] [ebp-10h]
    unsigned __int16* v33; // [esp+28h] [ebp-Ch]
    int2 v34; // [esp+2Ch] [ebp-8h]

    v2 = sub_437250();
    sub_44E110();
    sub_431510();
    sub_45ACA0(1);
    sub_446780();
    v3 = (nox_win_width - default_win_width) / 2;
    v4 = (nox_win_height - default_win_height) / 2;
    v5 = loadString_sub_40F1D0((char*)& byte_587000[124528], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 765);
    sub_43F840(*(_DWORD*)(a2 + 200), v5, &v31, 0, 0);
    v29 = (unsigned __int16*)(v3 - v31 / 2 + 320);
    v30 = (unsigned __int16*)(v4 + 20);
    sub_434390(*(int*)& byte_5D4594[2650656]);
    v26 = *(_DWORD*)(a2 + 200);
    v32 = (unsigned __int16*)((char*)v29 - 1);
    sub_43F6E0(v26, (__int16*)v5, (int)v29 - 1, v4 + 19);
    v33 = (unsigned __int16*)((char*)v29 + 1);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v29 + 1, v4 + 19);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v32, v4 + 21);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v33, v4 + 21);
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v5, (int)v29, v4 + 20);
    v34.field_0 = v3 + 73;
    v34.field_4 = v4 + 123;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832492] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832492] + 300))(v2, *(_DWORD*)& byte_5D4594[832492]);
    v34.field_0 = v3 + 109;
    v34.field_4 = v4 + 76;
    v6 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[124596], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 792);
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], v6, v34.field_0, v34.field_4);
    sub_43F840(*(int*)& byte_5D4594[832484], (unsigned __int16*)v6, &v27, 0, 0);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v7 = loadString_sub_40F1D0((char*)& byte_587000[124664], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 799);
    sub_43FAF0(*(int*)& byte_5D4594[832484], v7, v34.field_0, v34.field_4, v3 - v34.field_0 + 520, 0);
    v34.field_0 = v3 + 565;
    v34.field_4 = v4 + 117;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832496] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832496] + 300))(v2, *(_DWORD*)& byte_5D4594[832496]);
    v29 = loadString_sub_40F1D0((char*)& byte_587000[124732], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 809);
    sub_43F840(*(int*)& byte_5D4594[832484], v29, &v27, 0, 0);
    v30 = loadString_sub_40F1D0((char*)& byte_587000[124800], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 811);
    sub_43F840(*(int*)& byte_5D4594[832484], v30, &v28, 0, 0);
    v8 = v3 + 520;
    if (v28 + v27 <= 390)
    {
        v34.field_4 = v4 + 115;
        v34.field_0 = v8 - v28 - v27 - 4;
        sub_434390(*(int*)& byte_5D4594[2614256]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v29, v34.field_0, v34.field_4);
        v34.field_0 = v8 - v28;
        v34.field_4 = v4 + 115;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v30, v34.field_0, v34.field_4);
    }
    else
    {
        v34.field_0 = v3 + 199;
        v34.field_4 = v4 + 115;
        sub_434390(*(int*)& byte_5D4594[2614256]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v29, v34.field_0, v34.field_4);
        v34.field_0 += v27 + 4;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43FAF0(*(int*)& byte_5D4594[832484], v30, v34.field_0, v34.field_4, v8 - v34.field_0, 0);
    }
    v34.field_0 = v3 + 133;
    v34.field_4 = v4 + 192;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832504] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832504] + 300))(v2, *(_DWORD*)& byte_5D4594[832504]);
    v34.field_0 = v3 + 157;
    v34.field_4 = v4 + 156;
    v9 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[124868], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 862);
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], v9, v34.field_0, v34.field_4);
    sub_43F840(*(int*)& byte_5D4594[832484], (unsigned __int16*)v9, &v27, 0, 0);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v10 = loadString_sub_40F1D0((char*)& byte_587000[124936], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 869);
    sub_43FAF0(*(int*)& byte_5D4594[832484], v10, v34.field_0, v34.field_4, v4 - v34.field_0 + 630, 0);
    v34.field_0 = v3 + 525;
    v34.field_4 = v4 + 222;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832500] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832500] + 300))(v2, *(_DWORD*)& byte_5D4594[832500]);
    v29 = loadString_sub_40F1D0((char*)& byte_587000[125004], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 879);
    sub_43F840(*(int*)& byte_5D4594[832484], v29, &v27, 0, 0);
    v30 = loadString_sub_40F1D0((char*)& byte_587000[125072], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 881);
    sub_43F840(*(int*)& byte_5D4594[832484], v30, &v28, 0, 0);
    v11 = v3 + 500;
    if (v28 + v27 <= 215)
    {
        v34.field_4 = v4 + 198;
        v34.field_0 = v11 - v28 - v27 - 4;
        sub_434390(*(int*)& byte_5D4594[2614256]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v29, v34.field_0, v34.field_4);
        v34.field_0 = v11 - v28;
        v34.field_4 = v4 + 198;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v30, v34.field_0, v34.field_4);
    }
    else
    {
        v34.field_0 = v3 + 250;
        v34.field_4 = v4 + 198;
        sub_434390(*(int*)& byte_5D4594[2614256]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v29, v34.field_0, v34.field_4);
        v34.field_0 += v27 + 4;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43FAF0(*(int*)& byte_5D4594[832484], v30, v34.field_0, v34.field_4, v11 - v34.field_0, 0);
    }
    v34.field_0 = v3 + 182;
    v34.field_4 = v4 + 262;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832528] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832528] + 300))(v2, *(_DWORD*)& byte_5D4594[832528]);
    v34.field_0 = v3 + 201;
    v34.field_4 = v4 + 251;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832536] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832536] + 300))(v2, *(_DWORD*)& byte_5D4594[832536]);
    v34.field_0 = v3 + 185;
    v34.field_4 = v4 + 234;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832532] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832532] + 300))(v2, *(_DWORD*)& byte_5D4594[832532]);
    v34.field_0 = v3 + 221;
    v34.field_4 = v4 + 240;
    v12 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[125140], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 942);
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], v12, v34.field_0, v34.field_4);
    sub_43F840(*(int*)& byte_5D4594[832484], (unsigned __int16*)v12, &v27, 0, 0);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v13 = loadString_sub_40F1D0((char*)& byte_587000[125208], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 949);
    sub_43FAF0(*(int*)& byte_5D4594[832484], v13, v34.field_0, v34.field_4, v3 - v34.field_0 + 470, 0);
    v34.field_0 = v3 + 484;
    v34.field_4 = v4 + 278;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832516] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832516] + 300))(v2, *(_DWORD*)& byte_5D4594[832516]);
    v34.field_0 = v3 + 503;
    v34.field_4 = v4 + 303;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832520] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832520] + 300))(v2, *(_DWORD*)& byte_5D4594[832520]);
    v29 = loadString_sub_40F1D0((char*)& byte_587000[125276], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 964);
    sub_43F840(*(int*)& byte_5D4594[832484], v29, &v27, 0, 0);
    v30 = loadString_sub_40F1D0((char*)& byte_587000[125344], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 966);
    sub_43F840(*(int*)& byte_5D4594[832484], v30, &v28, 0, 0);
    v14 = v3 + 462;
    if (v28 + v27 <= 350)
    {
        v34.field_4 = v4 + 286;
        v34.field_0 = v14 - v28 - v27 - 4;
        sub_434390(*(int*)& byte_5D4594[2614256]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v29, v34.field_0, v34.field_4);
        v34.field_0 = v14 - v28;
        v34.field_4 = v4 + 286;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v30, v34.field_0, v34.field_4);
    }
    else
    {
        v34.field_0 = v3 + 113;
        v34.field_4 = v4 + 286;
        sub_434390(*(int*)& byte_5D4594[2614256]);
        sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v29, v34.field_0, v34.field_4);
        v34.field_0 += v27 + 4;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43FAF0(*(int*)& byte_5D4594[832484], v30, v34.field_0, v34.field_4, v14 - v34.field_0, 0);
    }
    v34.field_0 = v3 + 186;
    v34.field_4 = v4 + 333;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832512] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832512] + 300))(v2, *(_DWORD*)& byte_5D4594[832512]);
    v34.field_0 = v3 + 219;
    v34.field_4 = v4 + 345;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832508] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832508] + 300))(v2, *(_DWORD*)& byte_5D4594[832508]);
    v34.field_0 = v3 + 220;
    v34.field_4 = v4 + 322;
    sub_473A10(v2, &v34, (_DWORD*)(*(_DWORD*)& byte_5D4594[832524] + 12));
    (*(void(__cdecl * *)(char*, _DWORD))(*(_DWORD*)& byte_5D4594[832524] + 300))(v2, *(_DWORD*)& byte_5D4594[832524]);
    v34.field_0 = v3 + 241;
    v34.field_4 = v4 + 330;
    v15 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[125412], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1027);
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], v15, v34.field_0, v34.field_4);
    sub_43F840(*(int*)& byte_5D4594[832484], (unsigned __int16*)v15, &v27, 0, 0);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v16 = loadString_sub_40F1D0((char*)& byte_587000[125480], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1034);
    sub_43FAF0(*(int*)& byte_5D4594[832484], v16, v34.field_0, v34.field_4, v3 - v34.field_0 + 550, 0);
    v17 = loadString_sub_40F1D0((char*)& byte_587000[125548], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1040);
    v18 = loadString_sub_40F1D0((char*)& byte_587000[125616], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1041);
    sub_43F840(*(int*)& byte_5D4594[832484], v17, &v27, 0, 0);
    sub_43F840(*(int*)& byte_5D4594[832484], v18, &v28, 0, 0);
    v34.field_0 = v3 - (v27 + v28) / 2 + 320;
    v34.field_4 = v4 + 370;
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v17, v34.field_0, v34.field_4);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v18, v34.field_0, v34.field_4);
    v19 = loadString_sub_40F1D0((char*)& byte_587000[125684], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1055);
    v20 = loadString_sub_40F1D0((char*)& byte_587000[125752], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1056);
    sub_43F840(*(int*)& byte_5D4594[832484], v19, &v27, 0, 0);
    sub_43F840(*(int*)& byte_5D4594[832484], v20, &v28, 0, 0);
    v34.field_0 = v3 - (v28 + v27) / 2 + 320;
    v34.field_4 = v4 + 395;
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v19, v34.field_0, v34.field_4);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v20, v34.field_0, v34.field_4);
    v21 = loadString_sub_40F1D0((char*)& byte_587000[125820], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1070);
    v22 = loadString_sub_40F1D0((char*)& byte_587000[125888], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1071);
    sub_43F840(*(int*)& byte_5D4594[832484], v21, &v27, 0, 0);
    sub_43F840(*(int*)& byte_5D4594[832484], v22, &v28, 0, 0);
    v34.field_0 = v3 - (v28 + v27) / 2 + 320;
    v34.field_4 = v4 + 420;
    sub_434390(*(int*)& byte_5D4594[2614256]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v21, v34.field_0, v34.field_4);
    v34.field_0 += v27 + 4;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(*(int*)& byte_5D4594[832484], (__int16*)v22, v34.field_0, v34.field_4);
    result = *(_DWORD*)& byte_5D4594[2598000] / 0x1Eu;
    if (*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu)
    {
        if (*(_DWORD*)& byte_587000[123012] != 1)
            return result;
    }
    else
    {
        result = 1;
        if (*(_DWORD*)& byte_587000[123012] == 1)
        {
            *(_DWORD*)& byte_587000[123012] = *(_DWORD*)& byte_5D4594[2598000] % 0x1Eu;
            return result;
        }
        *(_DWORD*)& byte_587000[123012] = 1;
    }
    v24 = *(_DWORD*)& byte_5D4594[2523948];
    v25 = loadString_sub_40F1D0((char*)& byte_587000[125956], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1097);
    sub_43F840(*(int*)& byte_5D4594[832484], v25, &v27, 0, 0);
    v34.field_4 = v4 + 450;
    v34.field_0 = v3 - v27 / 2 + 320;
    sub_434390(v24);
    return sub_43F6E0(*(_DWORD*)(a2 + 200), (__int16*)v25, v34.field_0, v34.field_4);
}

//----- (00450160) --------------------------------------------------------
int __cdecl sub_450160(int a1, int a2, char a3)
{
    int v3; // ebx
    int v4; // edi
    _DWORD* v5; // esi
    int v6; // edi
    char* v7; // eax
    char* v8; // eax
    char* v9; // eax
    int v10; // edi
    int v11; // eax
    int v12; // eax
    int result; // eax
    int v14; // [esp+Ch] [ebp-4h]
    unsigned __int16** v15; // [esp+14h] [ebp+4h]

    v3 = a1;
    *(_DWORD*)& byte_5D4594[831260] = 1;
    *(_DWORD*)& byte_5D4594[831244] = 1;
    v14 = *(_DWORD*)& byte_5D4594[2618908];
    *(_DWORD*)& byte_5D4594[832488] = 0;
    *(_DWORD*)& byte_5D4594[832472] = 0;
    *(_DWORD*)& byte_5D4594[831256] = 0;
    byte_5D4594[831252] = a1 + 1;
    if (*(_DWORD*)& byte_5D4594[2618908])
        v4 = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618908] + 2251);
    else
        v4 = a2;
    sub_46A8C0(*(int*)& byte_5D4594[831236]);
    sub_46ADC0(*(int*)& byte_5D4594[831236]);
    sub_46B500(*(int*)& byte_5D4594[831236]);
    sub_46B300(*(int*)& byte_5D4594[831236], sub_44E630);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[831232], 1010);
    sub_46B340((int)v5, sub_44E6F0);
    *(_DWORD*)& byte_5D4594[831220] = a2;
    v15 = (unsigned __int16**)v5[8];
    if (v3 == 255)
    {
        sub_46AE60(*(int*)& byte_5D4594[831232], 0);
        nox_window_call_field_94((int)v5, 16385, *(int*)& byte_5D4594[831268], 0);
        sub_46AD80((int)v5, 0x2000);
        *(_DWORD*)& byte_5D4594[831240] = sub_578D80();
        v6 = 24;
        *(_DWORD*)& byte_5D4594[831220] = 255;
    }
    else if (v3 == 254)
    {
        sub_409B30();
        v7 = sub_42F970("GauntletStartMines");
        sub_46AE60(*(int*)& byte_5D4594[831232], (int)v7);
        nox_window_call_field_94((int)v5, 16385, (int)& byte_5D4594[832540], 0);
        v6 = 0;
        if (a3 & 1)
        {
            *(_DWORD*)& byte_5D4594[832472] = 1;
            v8 = sub_42F970("MenuSystemBG");
            sub_46AE60(*(int*)& byte_5D4594[831232], (int)v8);
            sub_431510();
            sub_45ACA0(1);
        }
        else if (a3 & 4)
        {
            *(_DWORD*)& byte_5D4594[832472] = 4;
            v9 = sub_42F970("GauntletInstructionBackground");
            sub_46AE60(*(int*)& byte_5D4594[831232], (int)v9);
            sub_431510();
            sub_45ACA0(1);
        }
        else
        {
            *(_DWORD*)& byte_5D4594[832472] = 2;
            sub_46AE60(*(int*)& byte_5D4594[831232], *(int*)& byte_5D4594[832460]);
            if (*(_DWORD*)& byte_5D4594[832464])
                nox_window_call_field_94((int)v5, 16385, *(int*)& byte_5D4594[832464], 0);
            sub_431510();
            sub_45ACA0(1);
        }
        sub_446780();
        *(_DWORD*)& byte_5D4594[831240] = 0;
        *(_DWORD*)& byte_5D4594[831244] = 1;
        *(_DWORD*)& byte_5D4594[831224] = 0;
    }
    else
    {
        v10 = 32 * (v3 + v4 + 10 * v4);
        if (a2)
        {
            sub_46AE60(*(int*)& byte_5D4594[831232], *(_DWORD*)& byte_5D4594[v10 + 831300]);
            nox_window_call_field_94((int)v5, 16385, *(_DWORD*)& byte_5D4594[v10 + 831304], 0);
            v11 = *(_DWORD*)& byte_5D4594[v10 + 831308];
            v6 = *(_DWORD*)& byte_5D4594[v10 + 831312];
        }
        else
        {
            sub_46AE60(*(int*)& byte_5D4594[831232], *(_DWORD*)& byte_5D4594[v10 + 831316]);
            nox_window_call_field_94((int)v5, 16385, *(_DWORD*)& byte_5D4594[v10 + 831320], 0);
            v11 = *(_DWORD*)& byte_5D4594[v10 + 831324];
            v6 = *(_DWORD*)& byte_5D4594[v10 + 831328];
        }
        *(_DWORD*)& byte_5D4594[831240] = v11;
    }
    sub_43F840(v5[59], *v15, 0, &byte_5D4594[831280], default_win_height);
    sub_46AB20(v5, default_win_width, *(int*)& byte_5D4594[831280]);
    if (v3 == 255)
    {
        *(_DWORD*)& byte_5D4594[831276] = 1140457472;
        *(_DWORD*)& byte_5D4594[831280] = -20 - *(_DWORD*)& byte_5D4594[831280];
    }
    else
    {
        *(_DWORD*)& byte_5D4594[831280] = (480 - *(_DWORD*)(v5[59] + 8) - *(int*)& byte_5D4594[831280]) / 2;
        *(float*)& byte_5D4594[831276] = (double) * (int*)& byte_5D4594[831280];
    }
    sub_431290();
    *(_DWORD*)& byte_5D4594[831224] = 0;
    if (a2 || v3 == 255)
    {
        if (v3 != 254)
            * (_DWORD*)& byte_5D4594[831224] = 1;
    }
    else if (v3 != 254)
    {
        if (*(_DWORD*)(v14 + 4 * v3 + 4408))
        {
            sub_46ADE0(*(int*)& byte_5D4594[831236]);
            *(_DWORD*)& byte_5D4594[831256] = 1;
            sub_46D580();
            sub_46B300(*(int*)& byte_5D4594[831236], 0);
        }
        else
        {
            *(_DWORD*)& byte_5D4594[831224] = 1;
            *(_DWORD*)(v14 + 4 * v3 + 4408) = 1;
        }
    }
    sub_43DD70(v6, 50);
    *(_QWORD*)& byte_5D4594[831292] = sub_416BB0();
    *(_DWORD*)& byte_5D4594[831248] = 0;
    v12 = sub_44E3B0();
    sub_44DB30(v12, 1, sub_44E3E0);
    result = *(_DWORD*)& byte_5D4594[831224];
    if (*(_DWORD*)& byte_5D4594[831224])
        * (_DWORD*)& byte_5D4594[831244] = 0;
    return result;
}

//----- (00450560) --------------------------------------------------------
int sub_450560()
{
    return *(_DWORD*)& byte_5D4594[831260];
}

//----- (00450570) --------------------------------------------------------
int sub_450570()
{
    return *(_DWORD*)& byte_5D4594[831220];
}

//----- (00450580) --------------------------------------------------------
int sub_450580()
{
    int result; // eax

    sub_44D8F0();
    result = 0;
    *(_DWORD*)& byte_5D4594[832488] = 1;
    *(_DWORD*)& byte_5D4594[831224] = 0;
    *(_DWORD*)& byte_5D4594[831292] = 0;
    *(_DWORD*)& byte_5D4594[831296] = 0;
    return result;
}

//----- (004505B0) --------------------------------------------------------
int sub_4505B0()
{
    int v0; // eax
    int result; // eax

    sub_450580();
    *(_DWORD*)& byte_5D4594[2650672] = 0;
    v0 = sub_44E3B0();
    result = sub_44DAB0(v0, 1, sub_44E320);
    *(_DWORD*)& byte_5D4594[2650672] = 1;
    return result;
}

//----- (004505E0) --------------------------------------------------------
int sub_4505E0()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[831236])
    {
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[831236]);
        *(_DWORD*)& byte_5D4594[831236] = 0;
        *(_DWORD*)& byte_5D4594[831232] = 0;
    }
    *(_DWORD*)& byte_5D4594[831260] = 0;
    *(_DWORD*)& byte_5D4594[832484] = 0;
    if (*(_DWORD*)& byte_5D4594[832504])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832504]);
    *(_DWORD*)& byte_5D4594[832504] = 0;
    if (*(_DWORD*)& byte_5D4594[832492])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832492]);
    *(_DWORD*)& byte_5D4594[832492] = 0;
    if (*(_DWORD*)& byte_5D4594[832500])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832500]);
    *(_DWORD*)& byte_5D4594[832500] = 0;
    if (*(_DWORD*)& byte_5D4594[832496])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832496]);
    *(_DWORD*)& byte_5D4594[832496] = 0;
    if (*(_DWORD*)& byte_5D4594[832508])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832508]);
    *(_DWORD*)& byte_5D4594[832508] = 0;
    if (*(_DWORD*)& byte_5D4594[832512])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832512]);
    *(_DWORD*)& byte_5D4594[832512] = 0;
    if (*(_DWORD*)& byte_5D4594[832516])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832516]);
    *(_DWORD*)& byte_5D4594[832516] = 0;
    if (*(_DWORD*)& byte_5D4594[832520])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832520]);
    *(_DWORD*)& byte_5D4594[832520] = 0;
    if (*(_DWORD*)& byte_5D4594[832524])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832524]);
    *(_DWORD*)& byte_5D4594[832524] = 0;
    if (*(_DWORD*)& byte_5D4594[832528])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832528]);
    *(_DWORD*)& byte_5D4594[832528] = 0;
    if (*(_DWORD*)& byte_5D4594[832532])
        sub_45A4B0(*(_QWORD * *)& byte_5D4594[832532]);
    result = *(_DWORD*)& byte_5D4594[832536];
    *(_DWORD*)& byte_5D4594[832532] = 0;
    if (*(_DWORD*)& byte_5D4594[832536])
        result = sub_45A4B0(*(_QWORD * *)& byte_5D4594[832536]);
    *(_DWORD*)& byte_5D4594[832536] = 0;
    return result;
}

//----- (00450750) --------------------------------------------------------
unsigned __int8 sub_450750()
{
    return byte_5D4594[831252];
}

//----- (00450760) --------------------------------------------------------
char __cdecl sub_450760(char a1)
{
    char result; // al

    result = a1;
    byte_5D4594[831252] = a1;
    return result;
}

//----- (00450770) --------------------------------------------------------
int __cdecl sub_450770(int a1)
{
    size_t v1; // ebx
    unsigned __int8* v2; // esi
    unsigned __int16* v3; // edi
    _DWORD* v4; // esi
    unsigned __int16* v5; // eax
    unsigned __int16* v6; // eax
    unsigned __int16* v7; // eax
    unsigned __int16* v8; // eax
    int v9; // eax

    memset(&byte_5D4594[832364], 0, 0x60u);
    *(_DWORD*)& byte_5D4594[832356] = 0;
    v1 = 0;
    *(_DWORD*)& byte_5D4594[832356] = *(unsigned __int16*)(a1 + 2);
    *(_DWORD*)& byte_5D4594[831228] = *(unsigned __int16*)(a1 + 4);
    v2 = &byte_5D4594[832368];
    v3 = (unsigned __int16*)(a1 + 6);
    do
    {
        if (*v3)
        {
            *((_DWORD*)v2 - 1) = sub_417040(*v3);
            *(_WORD*)v2 = v3[4];
            *((_WORD*)v2 + 1) = v3[1];
            *((_WORD*)v2 + 2) = v3[2];
            *((_WORD*)v2 + 3) = v3[3];
            *((_DWORD*)v2 + 2) = *(_DWORD*)(v3 + 5);
            ++v1;
        }
        v2 += 16;
        v3 += 7;
    } while ((int)v2 < (int)& byte_5D4594[832464]);
    qsort(&byte_5D4594[832364], v1, 0x10u, sub_450960);
    if (!*(_DWORD*)& byte_5D4594[832476])
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[831232], 1010);
        v5 = loadString_sub_40F1D0((char*)& byte_587000[126092], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1656);
        sub_43F840(v4[59], v5, &a1, 0, 0);
        if (a1 > * (int*)& byte_5D4594[832476])
            * (_DWORD*)& byte_5D4594[832476] = a1;
        v6 = loadString_sub_40F1D0((char*)& byte_587000[126164], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1660);
        sub_43F840(v4[59], v6, &a1, 0, 0);
        if (a1 > * (int*)& byte_5D4594[832476])
            * (_DWORD*)& byte_5D4594[832476] = a1;
        v7 = loadString_sub_40F1D0((char*)& byte_587000[126224], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1664);
        sub_43F840(v4[59], v7, &a1, 0, 0);
        if (a1 > * (int*)& byte_5D4594[832476])
            * (_DWORD*)& byte_5D4594[832476] = a1;
        v8 = loadString_sub_40F1D0((char*)& byte_587000[126292], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1668);
        sub_43F840(v4[59], v8, &a1, 0, 0);
        v9 = *(_DWORD*)& byte_5D4594[832476];
        if (a1 > * (int*)& byte_5D4594[832476])
        {
            v9 = a1;
            *(_DWORD*)& byte_5D4594[832476] = a1;
        }
        if (v9 > 85)
            * (_DWORD*)& byte_5D4594[832476] = 85;
    }
    return sub_450160(254, 1, 1);
}

//----- (00450960) --------------------------------------------------------
int __cdecl sub_450960(const void* a1, const void* a2)
{
    unsigned int v2; // eax
    unsigned int v3; // ecx
    int result; // eax

    v2 = *((_DWORD*)a1 + 3);
    v3 = *((_DWORD*)a2 + 3);
    if (v2 == v3)
        result = 0;
    else
        result = v2 < v3 ? 1 : -1;
    return result;
}

//----- (00450980) --------------------------------------------------------
int __cdecl sub_450980(int a1, int a2)
{
    char* v2; // eax
    wchar_t* v3; // eax
    int result; // eax

    *(_DWORD*)& byte_5D4594[832480] = 0;
    sub_431510();
    sub_45ACA0(1);
    sub_446780();
    v2 = sub_42F970((const char*)(a1 + 5));
    sub_450AD0(v2);
    if (strlen((const char*)(a1 + 37)))
    {
        v3 = loadString_sub_40F1D0((char*)(a1 + 37), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1714);
        sub_450AF0((int)v3);
    }
    else
    {
        sub_450AF0((int)& byte_5D4594[832544]);
    }
    sub_450B00(*(unsigned __int16*)(a1 + 2));
    if (*(_BYTE*)(a1 + 4) & 2)
        * (_DWORD*)& byte_5D4594[832480] = 1;
    result = a2;
    if (a2)
        result = sub_450160(254, 1, 2);
    return result;
}

//----- (00450A30) --------------------------------------------------------
int __cdecl sub_450A30(int a1, int a2)
{
    char* v2; // eax
    wchar_t* v3; // eax
    int result; // eax

    *(_DWORD*)& byte_5D4594[832480] = 0;
    sub_431510();
    sub_45ACA0(1);
    sub_446780();
    v2 = sub_42F970((const char*)(a1 + 5));
    sub_450AD0(v2);
    if (strlen((const char*)(a1 + 37)))
    {
        v3 = loadString_sub_40F1D0((char*)(a1 + 37), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIBrief.c", 1756);
        sub_450AF0((int)v3);
    }
    else
    {
        sub_450AF0((int)& byte_5D4594[832548]);
    }
    sub_450B00(*(unsigned __int16*)(a1 + 2));
    result = a2;
    if (a2)
        result = sub_450160(254, 1, 4);
    return result;
}

//----- (00450AD0) --------------------------------------------------------
char* __cdecl sub_450AD0(char* a1)
{
    char* result; // eax

    result = a1;
    if (!a1)
        result = sub_42F970("WarriorChapterBegin8");
    *(_DWORD*)& byte_5D4594[832460] = result;
    return result;
}

//----- (00450AF0) --------------------------------------------------------
int __cdecl sub_450AF0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[832464] = a1;
    return result;
}

//----- (00450B00) --------------------------------------------------------
int __cdecl sub_450B00(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[832468] = a1;
    return result;
}

//----- (00450B10) --------------------------------------------------------
int sub_450B10()
{
    return *(_DWORD*)& byte_5D4594[832468];
}

//----- (00450B20) --------------------------------------------------------
wchar_t* __cdecl sub_450B20(wchar_t* a1)
{
    wchar_t* result; // eax

    result = a1;
    if (a1)
    {
        if (*a1)
        {
            result = nox_wcscpy((wchar_t*)& byte_5D4594[832552], a1);
            *(_DWORD*)& byte_5D4594[833728] = 1;
        }
    }
    return result;
}

//----- (00450B50) --------------------------------------------------------
int sub_450B50()
{
    int result; // eax

    result = 0;
    *(_WORD*)& byte_5D4594[832552] = 0;
    *(_DWORD*)& byte_5D4594[833728] = 0;
    *(_DWORD*)& byte_5D4594[833732] = 0;
    return result;
}

//----- (00450B70) --------------------------------------------------------
int sub_450B70()
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[833720], 16399, 0, 0);
}

//----- (00450B90) --------------------------------------------------------
int __cdecl sub_450B90(unsigned __int8 a1, int a2)
{
    if (*(_DWORD*)& byte_5D4594[833724])
        nox_window_call_field_94(*(int*)& byte_5D4594[833720], 16397, a2, a1);
    if (sub_579740())
        sub_579750(a2);
    return 1;
}

//----- (00450BE0) --------------------------------------------------------
void sub_450BE0()
{
    *(_DWORD*)& byte_5D4594[833724] = 1;
}

//----- (00450BF0) --------------------------------------------------------
void sub_450BF0()
{
    *(_DWORD*)& byte_5D4594[833724] = 0;
}

//----- (00450C00) --------------------------------------------------------
int sub_450C00(unsigned __int8 a1, wchar_t* a2, ...)
{
    va_list va; // [esp+Ch] [ebp+Ch]

    va_start(va, a2);
    nox_vswprintf((wchar_t*)& byte_5D4594[832680], a2, va);
    return sub_450B90(a1, (int)& byte_5D4594[832680]);
}

//----- (00450C30) --------------------------------------------------------
wchar_t* __cdecl sub_450C30(unsigned __int8 a1, int a2)
{
    wchar_t* result; // eax

    if (a2)
        return (wchar_t*)sub_450B90(a1, a2);
    result = loadString_sub_40F1D0((char*)& byte_587000[126456], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 97);
    if (result)
        result = (wchar_t*)sub_450B90(a1, (int)result);
    return result;
}

//----- (00450C70) --------------------------------------------------------
int sub_450C70()
{
    int v0; // esi
    wchar_t* v1; // eax
    int result; // eax
    char v3[56]; // [esp+Ch] [ebp-5A4h]
    char v4[332]; // [esp+44h] [ebp-56Ch]
    unsigned __int8 v5[1056]; // [esp+190h] [ebp-420h]

    v0 = *(_DWORD*)& byte_5D4594[2650660];
    *(_DWORD*)& byte_5D4594[833704] = nox_win_width - 1;
    *(_DWORD*)& byte_5D4594[833708] = nox_win_height / 2;
    *(_DWORD*)& byte_5D4594[833712] = nox_window_new(
        0,
        56,
        0,
        0,
        nox_win_width - 1,
        nox_win_height / 2,
        0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[833712], sub_450E80, sub_450E90, 0);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[833712] + 56) = *(_DWORD*)& byte_5D4594[2650656];
    memset(v4, 0, sizeof(v4));
    *(_DWORD*)& v4[36] = 0x80000000;
    *(_DWORD*)& v4[52] = 0x80000000;
    *(_DWORD*)& v4[24] = 0;
    memset(v3, 0, sizeof(v3));
    *(_DWORD*)& v4[48] = 0;
    *(_DWORD*)& v4[28] = v0;
    *(_DWORD*)& v4[68] = v0;
    *(_WORD*)& v3[2] = 0x0a;
    *(_WORD*)& v3[0] = 0x80;
    *(_DWORD*)& v3[4] = 1;
    *(_DWORD*)& v3[8] = 1;
    *(_DWORD*)& v3[12] = 1;
    *(_DWORD*)& v3[16] = 0;
    v1 = sub_401020();
    nox_wcsncpy((wchar_t*)& v4[72], v1, 0x40u);
    *(_WORD*)& v4[198] = 0;
    *(_DWORD*)& v4[8] = 32;
    *(_DWORD*)& byte_5D4594[833720] = sub_4A4310(
        *(int*)& byte_5D4594[833712],
        1152,
        0,
        0,
        *(int*)& byte_5D4594[833704],
        *(_DWORD*)& byte_5D4594[833708] - 20,
        (int)v4,
        (__int16*)v3);
    *(_DWORD*)& v4[44] = v0;
    *(_DWORD*)& v4[28] = v0;
    *(_DWORD*)& v4[36] = v0;
    *(_DWORD*)& v4[52] = v0;
    *(_DWORD*)& v4[68] = v0;
    *(_WORD*)& v5[1042] = *(_WORD*)& byte_5D4594[833704];
    nox_wcscpy((wchar_t*)v5, (const wchar_t*)& byte_5D4594[833736]);
    *(_WORD*)& v5[1040] = 128;
    *(_DWORD*)& v5[1024] = 0;
    *(_DWORD*)& v5[1028] = 0;
    *(_DWORD*)& v5[1032] = 0;
    *(_DWORD*)& v5[1036] = 0;
    nox_wcscpy((wchar_t*)& v4[72], (const wchar_t*)& byte_5D4594[833740]);
    *(_DWORD*)& v4[8] = 128;
    *(_DWORD*)& byte_5D4594[833716] = sub_488500(
        *(int*)& byte_5D4594[833712],
        16393,
        0,
        *(_DWORD*)& byte_5D4594[833708] - 20,
        *(int*)& byte_5D4594[833704],
        20,
        (int)v4,
        (wchar_t*)v5);
    sub_46B300(*(int*)& byte_5D4594[833716], sub_450F40);
    result = *(_DWORD*)& byte_5D4594[833712];
    *(_DWORD*)& byte_5D4594[833728] = 0;
    *(_DWORD*)& byte_5D4594[833732] = 0;
    *(_WORD*)& byte_5D4594[832552] = 0;
    return result;
}

//----- (00450E80) --------------------------------------------------------
int sub_450E80()
{
    return 0;
}

//----- (00450E90) --------------------------------------------------------
int __cdecl sub_450E90(int a1, int a2)
{
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if (*(_BYTE*)(a1 + 4) & 0x80)
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
        return 1;
    }
    if (*(_DWORD*)(a2 + 20) != 0x80000000)
    {
        if (*(_DWORD*)& byte_587000[80824])
        {
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
            return 1;
        }
        sub_434460(*(_DWORD*)(a2 + 20));
        sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    return 1;
}

//----- (00450F40) --------------------------------------------------------
int __cdecl sub_450F40(_DWORD* a1, int a2, int a3, int a4)
{
    _DWORD* v4; // eax

    if (a2 != 21)
        return sub_487D70(a1, a2, a3, a4);
    v4 = sub_42CD70();
    if (v4)
    {
        while (v4[9] != 11 || a3 != *v4)
        {
            v4 = (_DWORD*)v4[19];
            if (!v4)
                goto LABEL_6;
        }
        if (a4 == 2)
        {
            sub_451350();
            return 1;
        }
        return 1;
    }
LABEL_6:
    if (a3 == 1)
    {
        if (a4 == 2)
            sub_49B7A0();
    }
    else
    {
        if (a3 != 28)
            return sub_487D70(a1, a2, a3, a4);
        if (a4 == 2)
        {
            sub_450FD0();
            return 1;
        }
    }
    return 1;
}

//----- (00450FD0) --------------------------------------------------------
int sub_450FD0()
{
    wchar_t* v0; // esi
    size_t v1; // eax
    wchar_t* v3; // [esp-14h] [ebp-218h]
    wchar_t* v4; // [esp-14h] [ebp-218h]
    wchar_t v5[256]; // [esp+4h] [ebp-200h]

    if (!*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 32) + 1044))
    {
        v0 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[833716], 16413, 0, 0);
        if (*(_DWORD*)& byte_5D4594[833732] && *(_WORD*)& byte_5D4594[832552])
        {
            if (_nox_wcsicmp(v0, (const wchar_t*)& byte_5D4594[832552]))
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[126560], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 124);
                sub_450C30(4u, (int)v4);
            }
            else
            {
                *(_DWORD*)& byte_5D4594[833732] = 0;
                v3 = loadString_sub_40F1D0((char*)& byte_587000[126508], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 121);
                sub_450C30(6u, (int)v3);
            }
            nox_window_call_field_94(*(int*)& byte_5D4594[833716], 16414, (int)& byte_5D4594[833744], 0);
        }
        else
        {
            nox_wcscpy(v5, L"> ");
            nox_wcscat(v5, v0);
            sub_450B90(4u, (int)v5);
            if (v0)
            {
                if (*(_DWORD*)& byte_5D4594[2650636] & 0x200000)
                {
                    v1 = nox_wcslen(v0);
                    sub_4D33E0(v0, v1 + 1);
                }
                sub_443C80(v0, 0);
            }
            nox_window_call_field_94(*(int*)& byte_5D4594[833716], 16414, (int)& byte_5D4594[833748], 0);
        }
    }
    return 1;
}

//----- (00451100) --------------------------------------------------------
int sub_451100()
{
    int v0; // ecx
    _DWORD* v1; // eax
    int v2; // edx
    int v3; // edx
    int v4; // edx
    int v5; // edx
    int result; // eax

    v0 = *(_DWORD*)& byte_5D4594[2650660];
    if (*(_DWORD*)& byte_5D4594[833712])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[833712] + 56) = *(_DWORD*)& byte_5D4594[2650656];
    if (*(_DWORD*)& byte_5D4594[833720])
    {
        v1 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[833720] + 32);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 56) = 0x80000000;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 80) = 0x80000000;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 64) = v0;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 72) = v0;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 88) = 0x80000000;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 104) = v0;
        v2 = v1[9];
        if (v2)
        {
            *(_DWORD*)(v2 + 56) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[9] + 80) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[9] + 64) = v0;
            *(_DWORD*)(v1[9] + 72) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[9] + 88) = v0;
            v3 = *(_DWORD*)(v1[9] + 400);
            if (v3)
            {
                *(_DWORD*)(v3 + 56) = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 80) = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 64) = v0;
                *(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 72) = *(_DWORD*)& byte_5D4594[2650656];
                *(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 88) = *(_DWORD*)& byte_5D4594[2650656];
            }
        }
        v4 = v1[7];
        if (v4)
        {
            *(_DWORD*)(v4 + 56) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[7] + 80) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[7] + 64) = v0;
            *(_DWORD*)(v1[7] + 72) = *(_DWORD*)& byte_5D4594[2523948];
            *(_DWORD*)(v1[7] + 88) = v0;
            *(_DWORD*)(v1[7] + 104) = v0;
        }
        v5 = v1[8];
        if (v5)
        {
            *(_DWORD*)(v5 + 56) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[8] + 80) = *(_DWORD*)& byte_5D4594[2650656];
            *(_DWORD*)(v1[8] + 64) = v0;
            *(_DWORD*)(v1[8] + 72) = *(_DWORD*)& byte_5D4594[2523948];
            *(_DWORD*)(v1[8] + 88) = v0;
            *(_DWORD*)(v1[8] + 104) = v0;
        }
    }
    result = *(_DWORD*)& byte_5D4594[833716];
    if (*(_DWORD*)& byte_5D4594[833716])
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 56) = *(_DWORD*)& byte_5D4594[2650656];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 80) = v0;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 64) = v0;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 72) = v0;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 88) = v0;
        result = *(_DWORD*)& byte_5D4594[833716];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 104) = v0;
    }
    return result;
}

//----- (004512B0) --------------------------------------------------------
int sub_4512B0()
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[833712]))
        return 0;
    if (sub_46B4F0() == *(_DWORD*)& byte_5D4594[833716])
        sub_46B500(0);
    nox_window_set_hidden(*(int*)& byte_5D4594[833712], 1);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[833712] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 36) &= 0xFFFFFFFB;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 36) &= 0xFFFFFFFD;
    *(_DWORD*)& byte_5D4594[3799524] = 1;
    return 1;
}

//----- (00451350) --------------------------------------------------------
int sub_451350()
{
    int result; // eax
    wchar_t* v1; // eax

    if (!(sub_46ADA0(*(int*)& byte_5D4594[833712]) & 0x10))
        return sub_4512B0();
    result = sub_446360();
    if (!result)
    {
        sub_46A8C0(*(int*)& byte_5D4594[833712]);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833712] + 4) |= 8u;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833720] + 4) |= 8u;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 4) |= 8u;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[833716] + 4) |= 1u;
        sub_46B500(*(int*)& byte_5D4594[833716]);
        result = *(_DWORD*)& byte_5D4594[833728];
        if (*(_DWORD*)& byte_5D4594[833728])
        {
            sub_450B70();
            v1 = loadString_sub_40F1D0((char*)& byte_587000[126620], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 459);
            result = sub_450C00(4u, v1);
            *(_DWORD*)& byte_5D4594[833732] = 1;
        }
    }
    return result;
}

//----- (00451410) --------------------------------------------------------
int sub_451410()
{
    return ((unsigned __int8)~sub_46ADA0(*(int*)& byte_5D4594[833712]) >> 4) & 1;
}

//----- (00451430) --------------------------------------------------------
void sub_451430()
{
    int v0; // eax

    if (nox_win_height == default_win_height || nox_win_width == default_win_width)
    {
        v0 = sub_43F320(0);
        if (*(_DWORD*)& byte_5D4594[839884])
        {
            if (*(_DWORD*)& byte_5D4594[839888])
            {
                *(_DWORD*)& byte_5D4594[839884] = 0;
                *(_DWORD*)& byte_5D4594[839888] = 0;
            }
            else
            {
                *(_DWORD*)& byte_5D4594[839884] = 320;
                *(_DWORD*)& byte_5D4594[839888] = nox_win_height - 21 * v0;
            }
        }
        else if (*(_DWORD*)& byte_5D4594[839888])
        {
            *(_DWORD*)& byte_5D4594[839884] = 320;
            *(_DWORD*)& byte_5D4594[839888] = 0;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[839888] = nox_win_height - 21 * v0;
        }
    }
}

//----- (004514F0) --------------------------------------------------------
int sub_4514F0()
{
    int result; // eax
    int v1; // edi
    int v2; // esi
    unsigned __int8* v3; // ebx

    result = *(_DWORD*)& byte_5D4594[823776];
    if (*(_DWORD*)& byte_5D4594[823776])
    {
        v1 = sub_43F320(0);
        sub_434460(*(int*)& byte_5D4594[2650656]);
        sub_49CE30(*(int*)& byte_5D4594[839884], *(int*)& byte_5D4594[839888], 320, 21 * v1);
        sub_434460(1);
        sub_49CC70(*(int*)& byte_5D4594[839884], *(int*)& byte_5D4594[839888], 320, 21 * v1);
        sub_434390(1);
        result = *(_DWORD*)& byte_5D4594[839888];
        v2 = *(_DWORD*)& byte_5D4594[839888] + 20 * v1;
        if (v2 > 0)
        {
            v3 = &byte_5D4594[835800];
            do
            {
                if ((int)v3 >= (int)& byte_5D4594[835880])
                    break;
                result = sub_43FAF0(0, *(_WORD * *)v3, *(_DWORD*)& byte_5D4594[839884] + 4, v2, 316, 0);
                v2 -= v1;
                v3 += 4;
            } while (v2 > 0);
        }
    }
    return result;
}

//----- (004515B0) --------------------------------------------------------
wchar_t* sub_4515B0(wchar_t* a1, ...)
{
    wchar_t* v1; // esi
    va_list va; // [esp+8h] [ebp+8h]

    va_start(va, a1);
    if (!nox_file_log)
        sub_451630();
    v1 = (wchar_t*)sub_451610();
    nox_swprintf((wchar_t*)& byte_5D4594[833752], a1, va);
    fprintf(nox_file_log, "%S", &byte_5D4594[833752]);
    fflush(nox_file_log);
    return nox_wcsncpy(v1, (const wchar_t*)& byte_5D4594[833752], 0x63u);
}

//----- (00451610) --------------------------------------------------------
int sub_451610()
{
    int result; // eax
    unsigned __int8* v1; // ecx

    result = *(_DWORD*)& byte_5D4594[835876];
    v1 = &byte_5D4594[835876];
    do
    {
        *(_DWORD*)v1 = *((_DWORD*)v1 - 1);
        v1 -= 4;
    } while ((int)v1 > (int)& byte_5D4594[835800]);
    *(_DWORD*)& byte_5D4594[835800] = result;
    return result;
}

//----- (00451630) --------------------------------------------------------
unsigned __int8* sub_451630()
{
    unsigned __int8* v1; // ecx
    unsigned __int8* result; // eax
    wchar_t* v3; // [esp-Ch] [ebp-Ch]
    wchar_t* v4; // [esp-8h] [ebp-8h]

    nox_file_log = fopen("log", "w");
    if (!nox_file_log)
    {
        v4 = loadString_sub_40F1D0((char*)& byte_587000[126708], 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 272);
        v3 = loadString_sub_40F1D0((char*)& byte_587000[126756], 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 271);
        nullsub_4(getWindowHandle_sub_401FD0(), v3, v4, 0);
        nox_exit(0);
    }
    v1 = &byte_5D4594[835880];
    result = &byte_5D4594[835800];
    do
    {
        *(_DWORD*)result = v1;
        *(_WORD*)v1 = 0;
        result += 4;
        v1 += 200;
    } while ((int)result < (int)& byte_5D4594[835880]);
    return result;
}
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (004517A0) --------------------------------------------------------
wchar_t* sub_4517A0(wchar_t* a1, ...)
{
    wchar_t* v1; // esi
    wchar_t* v2; // eax
    wchar_t* v5; // [esp-Ch] [ebp-Ch]
    va_list va; // [esp+8h] [ebp+8h]

    va_start(va, a1);
    if (!nox_file_log)
        sub_451630();
    v1 = (wchar_t*)sub_451610();
    v2 = loadString_sub_40F1D0((char*)& byte_587000[126924], 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 355);
    nox_swprintf((wchar_t*)& byte_5D4594[833752], v2);
    nox_vswprintf((wchar_t*)& byte_5D4594[833770], a1, va);
    fprintf(nox_file_log, "%S", &byte_5D4594[833752]);
    fflush(nox_file_log);
    v5 = loadString_sub_40F1D0((char*)& byte_587000[126980], 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 365);
    nullsub_4(getWindowHandle_sub_401FD0(), &byte_5D4594[833752], v5, 0);
    return nox_wcsncpy(v1, (const wchar_t*)& byte_5D4594[833752], 0x63u);
}
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00451850) --------------------------------------------------------
int __cdecl sub_451850(int a2, int a3)
{
    int v2; // edi
    unsigned __int8* v3; // esi
    int result; // eax

    v2 = 0;
    v3 = &byte_5D4594[840712];
    do
    {
        sub_451920((_DWORD*)v3 - 21);
        *(_DWORD*)v3 = sub_40AF80(v2);
        v3 += 200;
        ++v2;
    } while ((int)v3 < (int)& byte_5D4594[1045312]);
    *(_DWORD*)& byte_5D4594[1045420] = a3;
    *(_DWORD*)& byte_5D4594[1045428] = a2;
    if (a3)
    {
        *(_DWORD*)& byte_5D4594[1045424] = sub_4BD340(a3, 0x100000, 200, 0x2000);
        *(_DWORD*)& byte_5D4594[1045436] = sub_4BD280(200, 576);
    }
    if (!*(_DWORD*)& byte_5D4594[1045424]
        || !*(_DWORD*)& byte_5D4594[1045420]
        || !*(_DWORD*)& byte_5D4594[1045428]
        || !*(_DWORD*)& byte_5D4594[1045436])
    {
        return 0;
    }
    sub_425760(&byte_5D4594[840612]);
    sub_4864A0(&byte_5D4594[1045228]);
    result = 1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045428] + 184) = &byte_5D4594[1045228];
    *(_DWORD*)& byte_5D4594[1045432] = 1;
    return result;
}

//----- (00451920) --------------------------------------------------------
int __cdecl sub_451920(_DWORD* a2)
{
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
    a2[14] = 0;
    a2[15] = 0;
    a2[19] = 0;
    a2[20] = 0;
    a2[12] = 1;
    a2[48] = 0;
    a2[18] = 0;
    a2[17] = 0;
    a2[25] = 0;
    a2[26] = 0;
    a2[16] = 600;
    return sub_4862E0((int)(a2 + 4), 0x4000);
}

//----- (00451970) --------------------------------------------------------
void sub_451970()
{
    sub_4521F0();
    sub_452230();
    if (*(_DWORD*)& byte_5D4594[1045424])
    {
        sub_4BD3C0(*(LPVOID*)& byte_5D4594[1045424]);
        *(_DWORD*)& byte_5D4594[1045424] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1045436])
    {
        sub_4BD2D0(*(LPVOID*)& byte_5D4594[1045436]);
        *(_DWORD*)& byte_5D4594[1045436] = 0;
    }
    *(_DWORD*)& byte_5D4594[1045432] = 0;
}

//----- (004519C0) --------------------------------------------------------
int sub_4519C0()
{
    int result; // eax
    int v1; // esi
    int v2; // eax
    int v3; // ebp
    int v4; // eax
    unsigned __int8* v5; // edi
    unsigned __int8* v6; // esi
    unsigned __int8* v7; // edi
    int v8; // eax
    int v9; // eax
    int v10; // eax

    result = *(_DWORD*)& byte_5D4594[1045432];
    if (*(_DWORD*)& byte_5D4594[1045432])
    {
        result = *(_DWORD*)& byte_5D4594[1045448];
        if (!*(_DWORD*)& byte_5D4594[1045448])
        {
            *(_DWORD*)& byte_5D4594[1045448] = 1;
            sub_486520(*(unsigned int**)& byte_587000[127004]);
            v1 = *(_DWORD*)& byte_5D4594[840612];
            ++* (_DWORD*)& byte_5D4594[1045440];
            if (*(unsigned __int8**)& byte_5D4594[840612] != &byte_5D4594[840612])
            {
                do
                {
                    v2 = *(_DWORD*)(v1 + 36);
                    if (*(_DWORD*)(v2 + 100) != *(_DWORD*)& byte_5D4594[1045440])
                    {
                        sub_425760((_DWORD*)(v2 + 88));
                        *(_DWORD*)(*(_DWORD*)(v1 + 36) + 52) = 0;
                        *(_DWORD*)(*(_DWORD*)(v1 + 36) + 100) = *(_DWORD*)& byte_5D4594[1045440];
                    }
                    sub_486520((unsigned int*)(v1 + 184));
                    if (*(_DWORD*)(v1 + 28) != 4)
                        sub_451BE0(v1);
                    v1 = *(_DWORD*)v1;
                } while ((unsigned __int8*)v1 != &byte_5D4594[840612]);
                v1 = *(_DWORD*)& byte_5D4594[840612];
                if (*(unsigned __int8**)& byte_5D4594[840612] != &byte_5D4594[840612])
                {
                    do
                    {
                        sub_452510(v1);
                        v1 = *(_DWORD*)v1;
                    } while ((unsigned __int8*)v1 != &byte_5D4594[840612]);
                    v1 = *(_DWORD*)& byte_5D4594[840612];
                }
            }
            v3 = 0;
            sub_452010();
            if ((unsigned __int8*)v1 == &byte_5D4594[840612])
                goto LABEL_35;
            do
            {
                v4 = *(_DWORD*)(v1 + 176);
                v5 = *(unsigned __int8**)v1;
                if (!v4 || v1 != *(_DWORD*)(v4 + 152))
                    sub_4523D0((_DWORD*)v1);
                if (*(_BYTE*)(v1 + 24) & 1)
                {
                    sub_451FE0(v1);
                }
                else
                {
                    v3 += (unsigned int)(33 * (*(_DWORD*)(*(_DWORD*)(v1 + 36) + 20) >> 16)) >> 14;
                    sub_452050((_DWORD*)v1);
                }
                v1 = (int)v5;
            } while (v5 != &byte_5D4594[840612]);
            if (v3 <= 100)
                LABEL_35:
            sub_486350((int)& byte_5D4594[1045228], 0x4000);
            else
                sub_486350((int)& byte_5D4594[1045228], 0x190000u / v3);
            result = sub_486520((unsigned int*)& byte_5D4594[1045228]);
            v6 = *(unsigned __int8**)& byte_5D4594[840612];
            if (*(unsigned __int8**)& byte_5D4594[840612] != &byte_5D4594[840612])
            {
                do
                {
                    v7 = *(unsigned __int8**)v6;
                    result = *((_DWORD*)v6 + 7);
                    if (result == 1)
                    {
                        sub_451DC0((int)v6);
                        v8 = sub_451CA0(v6);
                        *((_DWORD*)v6 + 74) = v8;
                        if (!v8)
                        {
                            do
                            {
                                if (!sub_452120((int)v6))
                                    break;
                                v7 = *(unsigned __int8**)v6;
                                sub_451DC0((int)v6);
                                v9 = sub_451CA0(v6);
                                *((_DWORD*)v6 + 74) = v9;
                            } while (!v9);
                        }
                        v10 = sub_451CA0(v6);
                        *((_DWORD*)v6 + 74) = v10;
                        if (!v10 || (result = sub_452490(v6)) == 0)
                        {
                            sub_4523D0(v6);
                            result = sub_451FE0((int)v6);
                        }
                    }
                    v6 = v7;
                } while (v7 != &byte_5D4594[840612]);
            }
            *(_DWORD*)& byte_5D4594[1045448] = 0;
        }
    }
    return result;
}

//----- (00451BE0) --------------------------------------------------------
int __cdecl sub_451BE0(int a1)
{
    int v1; // eax
    int v2; // edi
    unsigned int v3; // ebx
    _DWORD* v4; // esi
    int v5; // eax
    int v6; // eax
    _DWORD* v7; // ebx
    int result; // eax
    int v9; // esi
    _DWORD* v10; // esi

    v1 = a1;
    v2 = *(_DWORD*)(a1 + 36);
    v3 = *(_DWORD*)(a1 + 188) >> 16;
    v4 = *(_DWORD * *)(v2 + 88);
    if (v4 != (_DWORD*)(v2 + 88))
    {
        do
        {
            v5 = (v4[44] >> 16) - v3;
            if (v5 < 0)
                v5 = v3 - (v4[44] >> 16);
            if (v5 >= (*(_DWORD*)(v2 + 20) >> 16) / 10)
            {
                if (v4[44] >> 16 < v3)
                    break;
            }
            else
            {
                v6 = v4[4];
                if (*(_BYTE*)(v2 + 4) & 0x10)
                {
                    if (v6)
                        break;
                }
                else if (!v6)
                {
                    break;
                }
            }
            v4 = (_DWORD*)* v4;
        } while (v4 != (_DWORD*)(v2 + 88));
        v1 = a1;
    }
    v7 = (_DWORD*)(v1 + 12);
    sub_425770((_DWORD*)(v1 + 12));
    sub_4258E0((int)v4, v7);
    result = *(_DWORD*)(v2 + 56);
    v9 = *(_DWORD*)(v2 + 52) + 1;
    *(_DWORD*)(v2 + 52) = v9;
    if (result)
    {
        if (v9 > result)
        {
            v10 = (_DWORD*)(*(_DWORD*)(v2 + 92) - 12);
            sub_425920(*(_DWORD * **)(v2 + 92));
            sub_4523D0(v10);
            result = *(_DWORD*)(v2 + 52) - 1;
            *(_DWORD*)(v2 + 52) = result;
        }
    }
    return result;
}

//----- (00451CA0) --------------------------------------------------------
int __cdecl sub_451CA0(_DWORD* a1)
{
    int v1; // ecx
    int v3; // eax
    _DWORD* v4; // ecx

    v1 = a1[42];
    a1[108] = v1;
    if (!v1)
        return 0;
    v3 = 0;
    if (v1 > 0)
    {
        v4 = a1 + 76;
        do
        {
            *v4 = v3++;
            ++v4;
        } while (v3 < a1[108]);
    }
    a1[43] = -1;
    return sub_451CF0(a1);
}

//----- (00451CF0) --------------------------------------------------------
int __cdecl sub_451CF0(_DWORD* a1)
{
    int v1; // ecx
    int result; // eax
    int v3; // edx
    int v4; // edi
    int v5; // eax
    int v6; // edi
    int v7; // ecx
    _DWORD* v8; // eax
    int v9; // eax

    v1 = a1[9];
    result = a1[108];
    v3 = *(_DWORD*)(v1 + 4);
    if (result)
    {
        if (v3 & 2)
        {
            v5 = sub_415FF0(0, result - 1, "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 376);
            v6 = a1[108] - 1;
            a1[43] = a1[v5 + 76];
            v7 = v5;
            if (v5 < v6)
            {
                v8 = &a1[v5 + 76];
                do
                {
                    ++v7;
                    *v8 = v8[1];
                    ++v8;
                } while (v7 < a1[108] - 1);
            }
        }
        else
        {
            ++a1[43];
        }
        v9 = a1[43];
        --a1[108];
        result = sub_4BD710(a1[v9 + 10]);
    }
    else if (v3 & 1)
    {
        if (*(_DWORD*)(v1 + 60) && (v4 = a1[109] + 1, a1[109] = v4, v4 >= *(int*)(v1 + 60)))
            result = 0;
        else
            result = sub_451CA0(a1);
    }
    return result;
}

//----- (00451DC0) --------------------------------------------------------
int __cdecl sub_451DC0(int a1)
{
    _DWORD* v1; // esi
    int result; // eax
    int v3; // ebx
    int i; // edi
    int v5; // eax
    int v6; // eax

    v1 = *(_DWORD * *)(a1 + 36);
    result = *(_DWORD*)(a1 + 168);
    v3 = v1[1];
    if (result)
    {
        if (v1[17] < 0x21u)
            return result;
        sub_451F90(a1);
    }
    if (v3 & 4)
    {
        if (v1[17] >= 0x21u)
        {
            v5 = sub_451E80(a1);
            result = sub_451F30(a1, v5);
        }
        else
        {
            result = v1[48];
            for (i = 0; i < result; ++i)
            {
                sub_451F30(a1, i);
                result = v1[48];
            }
        }
    }
    else if (v3 & 2)
    {
        v6 = sub_415FF0(0, v1[48] - 1, "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 536);
        result = sub_451F30(a1, v6);
    }
    else
    {
        result = sub_451F30(a1, 0);
    }
    return result;
}

//----- (00451E80) --------------------------------------------------------
int __cdecl sub_451E80(int a1)
{
    int v1; // eax
    int v2; // ebx
    int v3; // eax
    int v4; // ecx
    int v5; // edx
    int v6; // eax
    int v7; // edx
    int v8; // eax
    int v9; // edi
    int v10; // ecx
    _DWORD* v11; // eax

    v1 = *(_DWORD*)(a1 + 36);
    v2 = *(_DWORD*)(v1 + 4);
    if (*(int*)(a1 + 568) <= 0)
    {
        v3 = *(_DWORD*)(v1 + 192);
        v4 = 0;
        *(_DWORD*)(a1 + 568) = v3;
        if (v3 > 0)
        {
            v5 = a1 + 440;
            do
            {
                v5 += 4;
                v6 = v3 - v4++ - 1;
                *(_DWORD*)(v5 - 4) = v6;
                v3 = *(_DWORD*)(a1 + 568);
            } while (v4 < v3);
        }
    }
    v7 = *(_DWORD*)(a1 + 568) - 1;
    *(_DWORD*)(a1 + 568) = v7;
    if (!(v2 & 2))
        return *(_DWORD*)(a1 + 4 * v7 + 440);
    v8 = sub_415FF0(0, v7, "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 431);
    v9 = *(_DWORD*)(a1 + 4 * v8 + 440);
    v10 = v8;
    if (v8 < *(int*)(a1 + 568))
    {
        v11 = (_DWORD*)(a1 + 4 * v8 + 440);
        do
        {
            ++v10;
            *v11 = v11[1];
            ++v11;
        } while (v10 < *(int*)(a1 + 568));
    }
    return v9;
}

//----- (00451F30) --------------------------------------------------------
int __cdecl sub_451F30(int a1, int a2)
{
    int v2; // edx
    int result; // eax

    *(_DWORD*)(a1 + 4 * *(_DWORD*)(a1 + 168) + 40) = sub_4BD470(
        *(_DWORD * **)& byte_5D4594[1045424],
        *(__int16*)(*(_DWORD*)(a1 + 36) + 2 * a2 + 128));
    v2 = *(_DWORD*)(a1 + 168);
    result = *(_DWORD*)(a1 + 4 * v2 + 40);
    if (result)
    {
        sub_4BD650(*(_DWORD*)(a1 + 4 * v2 + 40));
        result = *(_DWORD*)(a1 + 168) + 1;
        *(_DWORD*)(a1 + 168) = result;
    }
    return result;
}

//----- (00451F90) --------------------------------------------------------
int __cdecl sub_451F90(int a1)
{
    int v1; // edi
    int result; // eax
    int* v3; // esi

    v1 = 0;
    result = *(_DWORD*)(a1 + 168);
    if (result <= 0)
    {
        *(_DWORD*)(a1 + 168) = 0;
    }
    else
    {
        v3 = (int*)(a1 + 40);
        do
        {
            sub_4BD660(*v3);
            *v3 = 0;
            result = *(_DWORD*)(a1 + 168);
            ++v1;
            ++v3;
        } while (v1 < result);
        *(_DWORD*)(a1 + 168) = 0;
    }
    return result;
}

//----- (00451FE0) --------------------------------------------------------
int __cdecl sub_451FE0(int a1)
{
    sub_425920((_DWORD * *)a1);
    *(_DWORD*)(a1 + 280) = 0;
    return sub_4BD300(*(_DWORD * *)& byte_5D4594[1045436], a1);
}

//----- (00452010) --------------------------------------------------------
int sub_452010()
{
    unsigned __int8* v0; // esi
    int v1; // ebx
    int v2; // edi

    v0 = &byte_5D4594[839892];
    v1 = 6;
    do
    {
        v2 = 10;
        do
        {
            sub_425760(v0);
            v0 += 12;
            --v2;
        } while (v2);
        --v1;
    } while (v1);
    return ++ * (_DWORD*)& byte_5D4594[1045444];
}

//----- (00452050) --------------------------------------------------------
_DWORD* __cdecl sub_452050(_DWORD* a1)
{
    _DWORD* v1; // esi
    int v2; // edi
    unsigned int v3; // ebx
    unsigned __int8* v4; // ebp
    _DWORD* result; // eax
    _DWORD** v6; // esi
    _DWORD** v7; // esi
    _DWORD* v8; // esi

    v1 = (_DWORD*)a1[9];
    v2 = v1[12] + a1[75];
    v3 = (a1[47] >> 16) / 0x666u;
    v4 = &byte_5D4594[120 * v2 + 839892];
    if (v1[26] == *(_DWORD*)& byte_5D4594[1045444])
    {
        result = (_DWORD*)v1[27];
        if (v2 <= (int)result)
        {
            if ((_DWORD*)v2 == result && v3 > v1[31])
            {
                v1[31] = v3;
                v7 = (_DWORD * *)(v1 + 28);
                sub_425920(v7);
                result = sub_4258E0((int)& v4[12 * v3], v7);
            }
        }
        else
        {
            v1[27] = v2;
            v1[31] = v3;
            v6 = (_DWORD * *)(v1 + 28);
            sub_425920(v6);
            result = sub_4258E0((int)& v4[12 * v3], v6);
        }
    }
    else
    {
        v1[26] = *(_DWORD*)& byte_5D4594[1045444];
        v1[27] = v2;
        v1[31] = v3;
        v8 = v1 + 28;
        sub_425770(v8);
        result = sub_4258E0((int)& v4[12 * v3], v8);
    }
    return result;
}

//----- (00452120) --------------------------------------------------------
int* __cdecl sub_452120(int a1)
{
    int v1; // ebp
    int* result; // eax
    int* v3; // ebx
    unsigned __int8* v4; // esi
    unsigned __int8* v5; // edi

    v1 = 0;
    result = sub_4521A0(*(_DWORD*)(a1 + 300) + *(_DWORD*)(*(_DWORD*)(a1 + 36) + 48));
    v3 = result;
    if (result)
    {
        sub_452190((int)result);
        v4 = *(unsigned __int8**)& byte_5D4594[840612];
        if (*(unsigned __int8**)& byte_5D4594[840612] != &byte_5D4594[840612])
        {
            do
            {
                v5 = *(unsigned __int8**)v4;
                if (*((int**)v4 + 9) == v3)
                {
                    sub_4523D0(v4);
                    sub_451FE0((int)v4);
                    v1 = 1;
                }
                v4 = v5;
            } while (v5 != &byte_5D4594[840612]);
        }
        result = (int*)v1;
    }
    return result;
}

//----- (00452190) --------------------------------------------------------
_DWORD** __cdecl sub_452190(int a1)
{
    return sub_425920((_DWORD * *)(a1 + 112));
}

//----- (004521A0) --------------------------------------------------------
int* __cdecl sub_4521A0(int a1)
{
    int v1; // ebp
    unsigned __int8* v2; // ebx
    int v3; // edi
    int* v4; // esi
    int* v5; // eax

    v1 = 0;
    v2 = &byte_5D4594[839892];
    if (a1 > 0)
    {
        while (1)
        {
            v3 = 0;
            v4 = (int*)v2;
            do
            {
                v5 = sub_425890(v4);
                if (v5)
                    return v5 - 28;
                ++v3;
                v4 += 3;
            } while (v3 < 10);
            ++v1;
            v2 += 120;
            if (v1 < a1)
                continue;
            break;
        }
    }
    return 0;
}

//----- (004521F0) --------------------------------------------------------
int sub_4521F0()
{
    int result; // eax
    unsigned __int8* v1; // esi
    unsigned __int8* v2; // edi

    result = *(_DWORD*)& byte_5D4594[1045432];
    if (*(_DWORD*)& byte_5D4594[1045432])
    {
        v1 = *(unsigned __int8**)& byte_5D4594[840612];
        if (*(unsigned __int8**)& byte_5D4594[840612] != &byte_5D4594[840612])
        {
            do
            {
                v2 = *(unsigned __int8**)v1;
                sub_4523D0(v1);
                result = sub_451FE0((int)v1);
                v1 = v2;
            } while (v2 != &byte_5D4594[840612]);
        }
    }
    return result;
}

//----- (00452230) --------------------------------------------------------
int***** sub_452230()
{
    int***** result; // eax
    int**** v1; // esi

    result = *(int******)& byte_5D4594[1045432];
    if (*(_DWORD*)& byte_5D4594[1045432])
    {
        result = *(int******)& byte_5D4594[840612];
        if (*(unsigned __int8**)& byte_5D4594[840612] != &byte_5D4594[840612])
        {
            do
            {
                v1 = *result;
                if ((_BYTE)result[6] & 1)
                    sub_451FE0((int)result);
                result = (int*****)v1;
            } while (v1 != (int****)& byte_5D4594[840612]);
        }
    }
    return result;
}

//----- (00452270) --------------------------------------------------------
char* __cdecl sub_452270(int a1)
{
    char* result; // eax

    if (*(_DWORD*)& byte_5D4594[1045432] && a1 >= 0 && a1 < 1023)
        result = (char*)& byte_5D4594[200 * a1 + 840628];
    else
        result = 0;
    return result;
}

//----- (004522A0) --------------------------------------------------------
int __cdecl sub_4522A0(int a1)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1045432])
        result = *(_DWORD*)(a1 + 64);
    else
        result = 0;
    return result;
}

//----- (004522C0) --------------------------------------------------------
int __cdecl sub_4522C0(int a1)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1045432])
        result = *(_DWORD*)(a1 + 8);
    else
        result = 0;
    return result;
}

//----- (004522E0) --------------------------------------------------------
char* __cdecl sub_4522E0(int a1)
{
    char* result; // eax

    if (*(_DWORD*)& byte_5D4594[1045432])
        result = *(char**)(a1 + 84);
    else
        result = (char*)& byte_587000[127128];
    return result;
}

//----- (00452300) --------------------------------------------------------
_DWORD* __cdecl sub_452300(_DWORD* a1)
{
    _DWORD* v1; // esi

    if (!*(_DWORD*)& byte_5D4594[1045432])
        return 0;
    if (!*(_DWORD*)& byte_587000[126996])
        return 0;
    if (!*a1)
        return 0;
    v1 = sub_4BD2E0(*(_DWORD * **)& byte_5D4594[1045436]);
    if (!v1)
    {
        sub_452230();
        v1 = sub_4BD2E0(*(_DWORD * **)& byte_5D4594[1045436]);
        if (!v1)
            return 0;
    }
    memset(v1, 0, 0x240u);
    v1[9] = a1;
    sub_425770(v1);
    v1[7] = 0;
    v1[75] = 0;
    v1[142] = 0;
    v1[108] = 0;
    v1[42] = 0;
    sub_4864A0(v1 + 46);
    sub_4258E0((int)& byte_5D4594[840612], v1);
    v1[70] = (*(_DWORD*)& byte_587000[127000])++;
    return v1;
}

//----- (004523D0) --------------------------------------------------------
int __cdecl sub_4523D0(_DWORD* a1)
{
    int result; // eax

    if (!(a1[6] & 1))
    {
        sub_452410((int)a1);
        sub_451F90((int)a1);
        a1[7] = 4;
        a1[70] = 0;
        result = a1[6];
        LOBYTE(result) = result | 1;
        a1[6] = result;
    }
    return result;
}

//----- (00452410) --------------------------------------------------------
int __cdecl sub_452410(int a1)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 176);
    if (result && a1 == *(_DWORD*)(result + 152))
    {
        if (*(_BYTE*)(a1 + 24) & 2)
            sub_4BDA80(*(_DWORD*)(a1 + 176));
        sub_4BDB30(*(_DWORD*)(a1 + 176));
        *(_DWORD*)(*(_DWORD*)(a1 + 176) + 152) = 0;
        *(_DWORD*)(*(_DWORD*)(a1 + 176) + 148) = 0;
        result = *(_DWORD*)(a1 + 176);
        *(_DWORD*)(result + 140) = 0;
        *(_DWORD*)(*(_DWORD*)(a1 + 176) + 144) = 0;
        *(_DWORD*)(*(_DWORD*)(a1 + 176) + 112) = 0;
        *(_DWORD*)(a1 + 176) = 0;
    }
    return result;
}

//----- (00452490) --------------------------------------------------------
int __cdecl sub_452490(_DWORD* a1)
{
    int v1; // eax
    int v3; // edi
    int v4; // eax

    v1 = a1[44];
    if (a1 != *(_DWORD * *)(v1 + 152))
        return 0;
    v3 = a1[74];
    sub_4BDB90((_DWORD*)v1, (_DWORD*)a1[74]);
    a1[7] = 3;
    v4 = a1[6];
    LOBYTE(v4) = v4 | 2;
    a1[6] = v4;
    a1[74] = 0;
    if (!sub_4BDB40(a1[44]))
        return 1;
    a1[7] = 1;
    a1[74] = v3;
    a1[6] &= 0xFFFFFFFD;
    return 0;
}

//----- (00452510) --------------------------------------------------------
int __cdecl sub_452510(int a3)
{
    int v1; // eax
    int v2; // eax
    unsigned __int64 v3; // rax

    if (!*(_DWORD*)& byte_587000[126996])
        * (_DWORD*)(a3 + 28) = 4;
    while (1)
    {
        v1 = *(_DWORD*)(a3 + 28);
        if (!v1)
            break;
        v2 = v1 - 2;
        if (v2)
        {
            LODWORD(v3) = v2 - 2;
            if (!(_DWORD)v3)
                LODWORD(v3) = sub_4523D0((_DWORD*)a3);
            return v3;
        }
        v3 = sub_416BB0();
        if (v3 <= *(_QWORD*)(a3 + 288))
            return v3;
        *(_DWORD*)(a3 + 28) = *(_DWORD*)(a3 + 32);
    }
    LODWORD(v3) = sub_452580((_DWORD*)a3);
    if (!(_DWORD)v3)
        LODWORD(v3) = sub_4523D0((_DWORD*)a3);
    return v3;
}

//----- (00452580) --------------------------------------------------------
int __cdecl sub_452580(_DWORD* a1)
{
    int v1; // edi
    int result; // eax
    int v3; // eax
    int v4; // eax
    int v5; // eax

    v1 = a1[9];
    if (!*(_DWORD*)(v1 + 192))
        return 0;
    v3 = a1[75];
    a1[109] = 0;
    result = sub_452810(*(_DWORD*)(v1 + 48) + v3, 0);
    a1[44] = result;
    if (result)
    {
        v4 = sub_415FF0(*(_DWORD*)(v1 + 76), *(_DWORD*)(v1 + 80), "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 1482);
        sub_486320((_DWORD*)(a1[44] + 48), v4 + 100);
        sub_4BDB20(a1[44]);
        *(_DWORD*)(a1[44] + 152) = a1;
        *(_DWORD*)(a1[44] + 140) = sub_452770;
        *(_DWORD*)(a1[44] + 144) = sub_4526F0;
        *(_DWORD*)(a1[44] + 148) = sub_4526D0;
        a1[7] = 1;
        *(_DWORD*)(a1[44] + 112) = a1 + 46;
        if (*(_BYTE*)(v1 + 4) & 8)
        {
            v5 = sub_415FF0(*(_DWORD*)(v1 + 68), *(_DWORD*)(v1 + 72), "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 1497);
            if (v5 > 33)
                sub_452690((int)a1, v5, 1);
        }
        result = 1;
    }
    return result;
}

//----- (00452690) --------------------------------------------------------
__int64 __cdecl sub_452690(int a3, __int64 a4, int a5)
{
    __int64 result; // rax

    *(_DWORD*)(a3 + 32) = a5;
    result = a4 + sub_416BB0();
    *(_QWORD*)(a3 + 288) = result;
    *(_DWORD*)(a3 + 28) = 2;
    return result;
}

//----- (004526D0) --------------------------------------------------------
int __cdecl sub_4526D0(int a1)
{
    *(_DWORD*)(*(_DWORD*)(a1 + 152) + 28) = 4;
    return 0;
}

//----- (004526F0) --------------------------------------------------------
int __cdecl sub_4526F0(int a1)
{
    _DWORD* v1; // esi
    int v2; // eax

    v1 = *(_DWORD * *)(a1 + 152);
    v1[6] &= 0xFFFFFFFD;
    v2 = 4;
    if (v1[7] != 4)
    {
        if (v1[74] || v1[142])
            v2 = 1;
        else
            v1[71] = 0;
        if (v1[71])
        {
            sub_452690((int)v1, (unsigned int)v1[71], v2);
            v1[71] = 0;
            return 0;
        }
        v1[7] = v2;
    }
    return 0;
}

//----- (00452770) --------------------------------------------------------
int __cdecl sub_452770(_DWORD* a1)
{
    _DWORD* v1; // esi
    _DWORD* v2; // ebx
    int v4; // eax
    unsigned int v5; // eax

    v1 = (_DWORD*)a1[38];
    v2 = (_DWORD*)sub_451CF0((_DWORD*)a1[38]);
    if (*(_DWORD*)(v1[9] + 72) < 0x21u)
    {
        sub_4BDB90(a1, v2);
        return 0;
    }
    sub_4BDB90(a1, 0);
    v4 = v1[9];
    if (!(*(_BYTE*)(v4 + 4) & 8) || v2 || v1[142])
    {
        v5 = sub_415FF0(*(_DWORD*)(v4 + 68), *(_DWORD*)(v4 + 72), "C:\\NoxPost\\src\\client\\Audio\\AudEvent.c", 706);
        if (v5 < 0x21)
        {
            sub_4BDB90(a1, v2);
            return 0;
        }
        v1[71] = v5;
        v1[74] = v2;
    }
    return 0;
}

//----- (00452810) --------------------------------------------------------
int* __cdecl sub_452810(int a1, char a2)
{
    int* v2; // esi
    int* v3; // eax

    v2 = 0;
    if (*(_DWORD*)& byte_5D4594[1045428])
    {
        v3 = sub_487810(*(int*)& byte_5D4594[1045428], 1);
        v2 = v3;
        if (v3)
        {
            if (v3[31] & 0x15 && v3[30] > a1)
                return 0;
            sub_4BDA80((int)v3);
            v2[29] = *(_DWORD*)& byte_587000[127004];
            v2[30] = a1;
            if (a2 & 1)
                v2[32] = -1;
            else
                v2[32] = 0;
            sub_486320(v2 + 4, 0x4000);
        }
    }
    return v2;
}

//----- (00452890) --------------------------------------------------------
BOOL __cdecl sub_452890(int a1, void* a2)
{
    int v2; // esi
    unsigned __int8* v3; // eax
    int v4; // eax
    char* v5; // ebx
    char* v6; // eax
    char v7; // dl
    char* v8; // eax
    int v9; // ebp
    unsigned __int8* v10; // eax
    __int16 v11; // ax
    int v12; // ecx
    int* v13; // eax
    int v14; // ecx
    __int16 v15; // cx
    __int16 v16; // cx
    int v17; // edx
    char* v18; // eax
    char v19; // cl
    BOOL result; // eax
    int v21; // [esp-4h] [ebp-30h]
    _WORD* v22; // [esp+10h] [ebp-1Ch]
    unsigned __int8 v23; // [esp+18h] [ebp-14h]
    unsigned __int8 v24; // [esp+1Ch] [ebp-10h]
    unsigned __int8 v25; // [esp+20h] [ebp-Ch]
    unsigned __int8 v26; // [esp+24h] [ebp-8h]
    unsigned __int8 v27; // [esp+28h] [ebp-4h]
    unsigned __int8 v28; // [esp+30h] [ebp+4h]
    unsigned __int8 v29; // [esp+30h] [ebp+4h]

    v2 = a1;
    v3 = *(unsigned __int8**)(a1 + 8);
    v21 = a1;
    v28 = *v3;
    *(_DWORD*)(v21 + 8) = v3 + 1;
    sub_40ACC0(a2, 1u, v28, v21);
    *((_BYTE*)a2 + v28) = 0;
    v4 = sub_40AF50(a2);
    if (v4 && (v5 = sub_452270(v4)) != 0)
    {
        while (1)
        {
            v6 = *(char**)(v2 + 8);
            v7 = *v6;
            v8 = v6 + 1;
            *(_DWORD*)(v2 + 8) = v8;
            switch (v7)
            {
            case 0:
                *(_DWORD*)v5 = 1;
                result = v7 == 0;
                break;
            case 1:
                v23 = *v8;
                *(_DWORD*)(v2 + 8) = v8 + 1;
                *((_DWORD*)v5 + 12) = v23;
                continue;
            case 2:
                v26 = *v8;
                *(_DWORD*)(v2 + 8) = v8 + 1;
                *((_DWORD*)v5 + 1) = v26;
                continue;
            case 3:
                v27 = *v8;
                *(_DWORD*)(v2 + 8) = v8 + 1;
                sub_4862E0((int)(v5 + 16), 163 * v27);
                continue;
            case 4:
                v24 = *v8;
                *(_DWORD*)(v2 + 8) = v8 + 1;
                *((_DWORD*)v5 + 14) = v24;
                continue;
            case 5:
                v25 = *v8;
                *(_DWORD*)(v2 + 8) = v8 + 1;
                *((_DWORD*)v5 + 15) = v25;
                continue;
            case 6:
                v17 = *v8;
                *(_DWORD*)(v2 + 8) = v8 + 1;
                *((_DWORD*)v5 + 19) = v17;
                v18 = *(char**)(v2 + 8);
                v19 = *v18;
                *(_DWORD*)(v2 + 8) = v18 + 1;
                *((_DWORD*)v5 + 20) = v19;
                continue;
            case 7:
                v9 = 0;
                v22 = v5 + 128;
                while (1)
                {
                    v10 = *(unsigned __int8**)(v2 + 8);
                    v29 = *v10;
                    *(_DWORD*)(v2 + 8) = v10 + 1;
                    if (!v29)
                        break;
                    sub_40ACC0(a2, 1u, v29, v2);
                    *((_BYTE*)a2 + v29) = 0;
                    if (v9 < 32)
                    {
                        v11 = sub_486A10(*(int*)& byte_5D4594[1045420], a2);
                        *v22 = v11;
                        if (v11 != -1)
                        {
                            ++v9;
                            ++v22;
                        }
                    }
                }
                *((_DWORD*)v5 + 48) = v9;
                continue;
            case 8:
                v12 = *(_DWORD*)v8;
                *(_DWORD*)(v2 + 8) = v8 + 4;
                *((_DWORD*)v5 + 17) = v12;
                v13 = *(int**)(v2 + 8);
                v14 = *v13;
                *(_DWORD*)(v2 + 8) = v13 + 1;
                *((_DWORD*)v5 + 18) = v14;
                continue;
            case 9:
                v15 = *(_WORD*)v8;
                *(_DWORD*)(v2 + 8) = v8 + 2;
                if (v15 > 0)
                    * ((_DWORD*)v5 + 16) = 15 * v15;
                continue;
            case 0xA:
                v16 = *(_WORD*)v8;
                *(_DWORD*)(v2 + 8) = v8 + 2;
                *((_DWORD*)v5 + 2) = v16;
                continue;
            default:
                result = 0;
                break;
            }
            break;
        }
    }
    else
    {
        sub_452B30(v2);
        result = 1;
    }
    return result;
}

//----- (00452B00) --------------------------------------------------------
BOOL __cdecl sub_452B00(int a1)
{
    *(_DWORD*)(a1 + 8) += **(unsigned __int8**)(a1 + 8) + 1;
    return sub_452B30(a1);
}

//----- (00452B30) --------------------------------------------------------
BOOL __cdecl sub_452B30(int a1)
{
    int v1; // eax
    char* v2; // ecx
    char v3; // bl
    unsigned __int8* v4; // ecx
    unsigned __int8 v5; // dl
    int v6; // ecx
    BOOL result; // eax
    char v8; // [esp+Ch] [ebp+4h]

    v1 = a1;
    while (1)
    {
        v2 = *(char**)(v1 + 8);
        v3 = *v2;
        v8 = *v2;
        *(_DWORD*)(v1 + 8) = v2 + 1;
        switch (v8)
        {
        case 0:
            result = v3 == 0;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            *(_DWORD*)(v1 + 8) = v2 + 2;
            continue;
        case 6:
        case 9:
        case 0xA:
            *(_DWORD*)(v1 + 8) = v2 + 3;
            continue;
        case 7:
            while (1)
            {
                v4 = *(unsigned __int8**)(v1 + 8);
                v5 = *v4;
                v6 = (int)(v4 + 1);
                *(_DWORD*)(v1 + 8) = v6;
                if (!v5)
                    break;
                *(_DWORD*)(v1 + 8) = v6 + v5;
            }
            continue;
        case 8:
            *(_DWORD*)(v1 + 8) = v2 + 9;
            continue;
        default:
            result = 0;
            break;
        }
        break;
    }
    return result;
}

//----- (00452BD0) --------------------------------------------------------
int __cdecl sub_452BD0(int a1, char* a2)
{
    int v2; // esi
    char* v3; // ebx
    char* v4; // eax
    int v5; // edi
    int v6; // eax
    char* v7; // edi
    __int16* v8; // eax
    __int16 v9; // cx
    unsigned __int8* v10; // eax
    __int16* v11; // eax
    __int16 v12; // cx
    char* v13; // eax
    char v14; // cl
    char* v15; // eax
    char v16; // cl
    char* v17; // eax
    int v18; // edx
    char* v19; // eax
    char v20; // cl
    int result; // eax
    char* v22; // ecx
    char v23; // al
    int v24; // ebp
    char* v25; // eax
    __int16 v26; // ax
    char* v27; // eax
    char v28; // cl
    int v29; // eax
    unsigned __int8 v30; // [esp+10h] [ebp+4h]
    _WORD* v31; // [esp+10h] [ebp+4h]
    char* v32; // [esp+14h] [ebp+8h]

    v2 = a1;
    v3 = a2;
    v4 = *(char**)(a1 + 8);
    v5 = *v4;
    *(_DWORD*)(a1 + 8) = v4 + 1;
    sub_40ACC0(a2, 1u, v5, a1);
    a2[v5] = 0;
    v6 = sub_40AF50(a2);
    if (v6 && (v7 = sub_452270(v6)) != 0)
    {
        v8 = *(__int16**)(a1 + 8);
        v9 = *v8;
        *(_DWORD*)(a1 + 8) = v8 + 1;
        *((_DWORD*)v7 + 1) = 2;
        *((_DWORD*)v7 + 2) = v9;
        v10 = *(unsigned __int8**)(a1 + 8);
        v30 = *v10;
        *(_DWORD*)(v2 + 8) = v10 + 1;
        sub_4862E0((int)(v7 + 16), 163 * v30);
        v11 = *(__int16**)(v2 + 8);
        v12 = *v11;
        *(_DWORD*)(v2 + 8) = v11 + 1;
        if (v12 > 0)
            * ((_DWORD*)v7 + 16) = 15 * v12;
        v13 = *(char**)(v2 + 8);
        v14 = *v13;
        *(_DWORD*)(v2 + 8) = v13 + 1;
        *((_DWORD*)v7 + 14) = v14;
        v15 = *(char**)(v2 + 8);
        v16 = *v15;
        *(_DWORD*)(v2 + 8) = v15 + 1;
        *((_DWORD*)v7 + 19) = v16;
        v17 = *(char**)(v2 + 8);
        v18 = *v17;
        *(_DWORD*)(v2 + 8) = v17 + 1;
        *((_DWORD*)v7 + 20) = v18;
        v19 = *(char**)(v2 + 8);
        v20 = *v19;
        *(_DWORD*)(v2 + 8) = v19 + 1;
        *((_DWORD*)v7 + 12) = v20;
        if (v20 < 3)
        {
            v32 = 0;
            v31 = v7 + 128;
            while (1)
            {
                v22 = *(char**)(v2 + 8);
                v23 = *v22;
                *(_DWORD*)(v2 + 8) = v22 + 1;
                if (!v23)
                    break;
                v24 = v23;
                sub_40ACC0(v3, 1u, v23, v2);
                v3[v24] = 0;
                v25 = strrchr(v3, 46);
                if (v25)
                    * v25 = 0;
                v26 = sub_486A10(*(int*)& byte_5D4594[1045420], v3);
                *v31 = v26;
                if (v26 != -1)
                {
                    ++v32;
                    ++v31;
                }
            }
            *(_DWORD*)v7 = 1;
            *((_DWORD*)v7 + 48) = v32;
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        for (*(_DWORD*)(a1 + 8) += 9; ; *(_DWORD*)(a1 + 8) = v29 + v28)
        {
            v27 = *(char**)(a1 + 8);
            v28 = *v27;
            v29 = (int)(v27 + 1);
            *(_DWORD*)(a1 + 8) = v29;
            if (!v28)
                break;
        }
        result = 1;
    }
    return result;
}

//----- (00452D80) --------------------------------------------------------
_DWORD* __cdecl sub_452D80(int a1, int a2)
{
    _DWORD* result; // eax
    _DWORD* v3; // esi

    result = sub_452270(a1);
    if (result)
    {
        result = sub_452300(result);
        v3 = result;
        if (result)
        {
            sub_452EE0((int)result, a2);
            result = (_DWORD*)sub_452510((int)v3);
        }
    }
    return result;
}

//----- (00452DC0) --------------------------------------------------------
_DWORD* __cdecl sub_452DC0(int a1, int a2, int a3)
{
    _DWORD* result; // eax
    _DWORD* v4; // esi

    result = sub_452270(a1);
    if (result)
    {
        result = sub_452300(result);
        v4 = result;
        if (result)
        {
            sub_452EE0((int)result, a2);
            sub_452F80((int)v4, a3);
            result = (_DWORD*)sub_452510((int)v4);
        }
    }
    return result;
}

//----- (00452E10) --------------------------------------------------------
_DWORD* __cdecl sub_452E10(int a1, int a2, int a3)
{
    _DWORD* result; // eax
    _DWORD* v4; // esi

    result = sub_452270(a1);
    if (result)
    {
        result = sub_452300(result);
        v4 = result;
        if (result)
        {
            sub_452EE0((int)result, a2);
            sub_452F80((int)v4, a3);
            v4[75] = 2;
            result = (_DWORD*)sub_452510((int)v4);
        }
    }
    return result;
}

//----- (00452E60) --------------------------------------------------------
_DWORD* __cdecl sub_452E60(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    *a1 = 0;
    a1[1] = 0;
    return result;
}

//----- (00452E80) --------------------------------------------------------
_DWORD* __cdecl sub_452E80(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    *a1 = 0;
    return result;
}

//----- (00452E90) --------------------------------------------------------
int __cdecl sub_452E90(_DWORD* a1, int a2)
{
    int result; // eax

    result = a2;
    *a1 = a2;
    if (a2)
    {
        a1[1] = *(_DWORD*)(a2 + 280);
        result = *(_DWORD*)(a2 + 36);
        a1[2] = result;
    }
    return result;
}

//----- (00452EB0) --------------------------------------------------------
int __cdecl sub_452EB0(int* a1)
{
    int result; // eax

    result = *a1;
    if (*a1 && (a1[2] != *(_DWORD*)(result + 36) || a1[1] != *(_DWORD*)(result + 280)))
    {
        result = 0;
        *a1 = 0;
    }
    return result;
}

//----- (00452EE0) --------------------------------------------------------
int __cdecl sub_452EE0(int a1, int a2)
{
    int v2; // eax

    v2 = sub_452F10(a1, a2);
    sub_486320((_DWORD*)(a1 + 184), v2);
    return sub_4863B0((unsigned int*)(a1 + 184));
}

//----- (00452F10) --------------------------------------------------------
unsigned int __cdecl sub_452F10(int a1, int a2)
{
    int v2; // ecx

    v2 = a2;
    if (a2 <= 100)
    {
        if (a2 < 0)
            v2 = 0;
    }
    else
    {
        v2 = 100;
    }
    return (unsigned int)(163 * v2 * (*(_DWORD*)(*(_DWORD*)(a1 + 36) + 20) >> 16)) >> 14;
}

//----- (00452F50) --------------------------------------------------------
int __cdecl sub_452F50(int a1, int a2)
{
    int v2; // eax

    v2 = sub_452F10(a1, a2);
    return sub_486350(a1 + 184, v2);
}

//----- (00452F80) --------------------------------------------------------
_DWORD* __cdecl sub_452F80(int a1, int a2)
{
    int v2; // eax

    v2 = sub_452FA0(a2);
    return sub_486320((_DWORD*)(a1 + 248), v2);
}

//----- (00452FA0) --------------------------------------------------------
int __cdecl sub_452FA0(int a1)
{
    int v1; // eax

    v1 = a1;
    if (a1 <= 50)
    {
        if (a1 < -50)
            v1 = -50;
    }
    else
    {
        v1 = 50;
    }
    return (v1 * 8192) / 50 + 8192;
}

//----- (00452FE0) --------------------------------------------------------
int __cdecl sub_452FE0(int a1, int a2)
{
    int v2; // eax

    v2 = sub_452FA0(a2);
    return sub_486350(a1 + 248, v2);
}

//----- (00453000) --------------------------------------------------------
int __cdecl sub_453000(_DWORD* a1, unsigned int a2, int a3)
{
    sub_486380(a1 + 46, a2, a3, 0x4000);
    sub_486380(a1 + 54, a2, a3, 0x4000);
    return sub_486380(a1 + 62, a2, a3, 0x4000);
}

//----- (00453050) --------------------------------------------------------
void sub_453050()
{
    *(_DWORD*)& byte_587000[126996] = 0;
}

//----- (00453060) --------------------------------------------------------
void sub_453060()
{
    *(_DWORD*)& byte_587000[126996] = 1;
}

//----- (00453070) --------------------------------------------------------
int sub_453070()
{
    return *(_DWORD*)& byte_587000[126996];
}

//----- (00453080) --------------------------------------------------------
BOOL __cdecl sub_453080(char a1)
{
    BOOL result; // eax

    if (*(_DWORD*)& byte_5D4594[1045460])
        result = sub_453690(1 << a1);
    else
        result = sub_453660(1 << a1);
    return result;
}

//----- (004530C0) --------------------------------------------------------
int __cdecl sub_4530C0(int a1, int a2)
{
    int v2; // edi
    wchar_t* v3; // eax
    int v4; // esi
    int v5; // ebx
    int v6; // eax
    wchar_t* v7; // eax
    int v8; // esi
    int v9; // ebx
    int v10; // eax
    _DWORD* v11; // eax
    _DWORD* v12; // eax
    wchar_t v14[66]; // [esp+Ch] [ebp-84h]

    v2 = 0;
    *(_DWORD*)& byte_5D4594[1045468] = nox_new_window_from_file("objlst.wnd", sub_4533D0);
    sub_46B340(*(int*)& byte_5D4594[1045468], sub_453350);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1045468], a1);
    sub_46B280(*(int*)& byte_5D4594[1045468], a1);
    *(_DWORD*)& byte_5D4594[1045464] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], 1510);
    sub_4532E0();
    nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16399, 0, 0);
    if (a2 == 0x1000000)
    {
        *(_DWORD*)& byte_5D4594[1045460] = 0;
        v7 = loadString_sub_40F1D0((char*)& byte_587000[127380], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c", 321);
        nox_wcscpy(v14, v7);
        v8 = 4;
        v9 = 25;
        do
        {
            v10 = sub_4159F0(v8);
            if (v10)
            {
                nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16397, v10, -1);
                ++v2;
            }
            v8 *= 2;
            --v9;
        } while (v9);
    }
    else if (a2 == 0x2000000)
    {
        *(_DWORD*)& byte_5D4594[1045460] = 1;
        v3 = loadString_sub_40F1D0((char*)& byte_587000[127316], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c", 308);
        nox_wcscpy(v14, v3);
        v4 = 1;
        v5 = 26;
        do
        {
            v6 = sub_415E80(v4);
            if (v6)
            {
                nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16397, v6, -1);
                ++v2;
            }
            v4 *= 2;
            --v5;
        } while (v5);
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16385, (int)v14, 0);
    v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], 1513);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16408, (int)v11, 0);
    v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], 1514);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16409, (int)v12, 0);
    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1045460] + 1045472] = v2;
    sub_453750();
    if (!sub_40A5C0(1) || sub_40A5C0(49152))
        sub_46AD20(*(_DWORD * *)& byte_5D4594[1045468], 1515, 1533, 0);
    return *(_DWORD*)& byte_5D4594[1045468];
}

//----- (004532E0) --------------------------------------------------------
_DWORD* sub_4532E0()
{
    int v0; // esi
    int v1; // edi
    int v2; // ebx
    _DWORD* result; // eax

    v0 = sub_43F320(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1045464] + 236)) + 1;
    sub_46AB20(*(_DWORD * *)& byte_5D4594[1045464], *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045464] + 8), 15 * v0 + 2);
    v1 = 1520;
    v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045464] + 20) + v0 + 2;
    do
    {
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], v1);
        result[5] = v2;
        v2 += v0;
        ++v1;
    } while (v1 < 1534);
    return result;
}

//----- (00453350) --------------------------------------------------------
int __cdecl sub_453350(int a1, int a2)
{
    int result; // eax
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        result = 1;
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
        result = 1;
    }
    return result;
}

//----- (004533D0) --------------------------------------------------------
int __cdecl sub_4533D0(int a1, int a2, int a3, int a4)
{
    int v3; // esi
    int v5; // eax
    int v6; // eax
    int v7; // edx
    int v8; // ecx
    int v9; // edx
    int v10; // ecx
    wchar_t* v11; // [esp-4h] [ebp-Ch]

    if (a2 == 0x4000)
    {
        if ((_DWORD*)a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], 1513)
            || (_DWORD*)a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], 1514))
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 0x4000, a3, 0);
        LABEL_35:
            sub_453750();
        }
        return 0;
    }
    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0((int*)a3);
    switch (v3)
    {
    case 1513:
    case 1514:
        nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 0x4000, a3, 0);
        goto LABEL_35;
    case 1515:
        if (*(_DWORD*)& byte_5D4594[1045460])
            * (_DWORD*)& byte_5D4594[1045456] = -1;
        else
            *(_DWORD*)& byte_5D4594[1045452] = -1;
        goto LABEL_6;
    case 1516:
        if (*(_DWORD*)& byte_5D4594[1045460])
            * (_DWORD*)& byte_5D4594[1045456] = 0;
        else
            *(_DWORD*)& byte_5D4594[1045452] = 0;
    LABEL_6:
        sub_453750();
        goto LABEL_7;
    case 1520:
    case 1521:
    case 1522:
    case 1523:
    case 1524:
    case 1525:
    case 1526:
    case 1527:
    case 1528:
    case 1529:
    case 1530:
    case 1531:
    case 1532:
    case 1533:
        v5 = sub_4A4800(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1045464] + 32));
        v11 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045464], 16406, v5 + v3 - 1520, 0);
        if (*(_DWORD*)& byte_5D4594[1045460])
            v6 = sub_415DA0(v11);
        else
            v6 = sub_415960(v11);
        if (*(_BYTE*)(a3 + 36) & 4)
        {
            if (*(_DWORD*)& byte_5D4594[1045460])
            {
                sub_453640(&byte_5D4594[1045456], v6, 0);
            }
            else
            {
                v7 = 0;
                if (v6 > 0)
                {
                    do
                    {
                        v8 = v6 >> 8;
                        if (v6 >> 8 > 0)
                            v6 >>= 8;
                        ++v7;
                    } while (v8 > 0);
                }
                sub_453620(&byte_5D4594[v7 + 1045451], v6, 0);
            }
        }
        else if (*(_DWORD*)& byte_5D4594[1045460])
        {
            sub_453640(&byte_5D4594[1045456], v6, 1);
        }
        else
        {
            v9 = 0;
            if (v6 > 0)
            {
                do
                {
                    v10 = v6 >> 8;
                    if (v6 >> 8 > 0)
                        v6 >>= 8;
                    ++v9;
                } while (v10 > 0);
            }
            sub_453620(&byte_5D4594[v9 + 1045451], v6, 1);
        }
    LABEL_7:
        sub_459D50(1);
        break;
    default:
        break;
    }
    sub_452D80(766, 100);
    return 0;
}

//----- (004535E0) --------------------------------------------------------
int* __cdecl sub_4535E0(int* a1)
{
    int* result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1045452] = *a1;
    return result;
}

//----- (004535F0) --------------------------------------------------------
int __cdecl sub_4535F0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1045456] = a1;
    return result;
}

//----- (00453600) --------------------------------------------------------
char* sub_453600()
{
    return (char*)& byte_5D4594[1045452];
}

//----- (00453610) --------------------------------------------------------
int sub_453610()
{
    return *(_DWORD*)& byte_5D4594[1045456];
}

//----- (00453620) --------------------------------------------------------
_BYTE* __cdecl sub_453620(_BYTE* a1, char a2, int a3)
{
    _BYTE* result; // eax

    result = a1;
    if (a3)
        * a1 |= a2;
    else
        *a1 &= ~a2;
    return result;
}

//----- (00453640) --------------------------------------------------------
_DWORD* __cdecl sub_453640(_DWORD* a1, int a2, int a3)
{
    _DWORD* result; // eax

    result = a1;
    if (a3)
        * a1 |= a2;
    else
        *a1 &= ~a2;
    return result;
}

//----- (00453660) --------------------------------------------------------
BOOL __cdecl sub_453660(int a1)
{
    int v1; // ecx
    int v2; // edx
    int v3; // eax

    v1 = a1;
    v2 = 0;
    if (a1 > 0)
    {
        do
        {
            v3 = v1 >> 8;
            if (v1 >> 8 > 0)
                v1 >>= 8;
            ++v2;
        } while (v3 > 0);
    }
    return ((unsigned __int8)v1 & byte_5D4594[v2 + 1045451]) != 0;
}

//----- (00453690) --------------------------------------------------------
BOOL __cdecl sub_453690(int a1)
{
    return (a1 & *(_DWORD*)& byte_5D4594[1045456]) != 0;
}

//----- (004536B0) --------------------------------------------------------
int __cdecl sub_4536B0(_DWORD* a1)
{
    int v1; // ebx
    int v2; // edi
    _DWORD* v3; // esi
    int v4; // ebp
    int result; // eax

    v1 = 1;
    *a1 = -1;
    v2 = 1;
    v3 = a1;
    v4 = 27;
    do
    {
        result = sub_415840((char*)v2);
        if (result)
        {
            result = sub_4E3BA0(result);
            if (!result)
            {
                result = (unsigned __int8)~(_BYTE)v1;
                *(_BYTE*)v3 &= ~(_BYTE)v1;
            }
        }
        if (v1 == 128)
        {
            v1 = 1;
            v3 = (_DWORD*)((char*)v3 + 1);
        }
        else
        {
            v1 *= 2;
        }
        v2 *= 2;
        --v4;
    } while (v4);
    return result;
}

//----- (00453710) --------------------------------------------------------
int sub_453710()
{
    int v0; // edi
    int v1; // esi
    int v2; // ebx
    int v3; // eax

    v0 = -1;
    v1 = 1;
    v2 = 26;
    do
    {
        v3 = sub_415CD0((char*)v1);
        if (v3 && !sub_4E3BA0(v3))
            v0 &= ~v1;
        v1 *= 2;
        --v2;
    } while (v2);
    return v0;
}

//----- (00453750) --------------------------------------------------------
char sub_453750()
{
    int v0; // esi
    int i; // ebx
    _DWORD* j; // edi
    bool v3; // zf
    int v4; // eax

    v0 = sub_4A4800(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1045464] + 32));
    for (i = 1520; i <= 1533; ++i)
    {
        for (j = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045468], i); (1 << v0) & 0x33; ++v0)
            ;
        if (v0 >= *(int*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1045460] + 1045472])
        {
            LOBYTE(v4) = nox_window_set_hidden((int)j, 1);
        }
        else
        {
            nox_window_set_hidden((int)j, 0);
            v3 = !sub_453080(v0);
            v4 = j[9];
            if (v3)
                LOBYTE(v4) = v4 & 0xFB;
            else
                LOBYTE(v4) = v4 | 4;
            j[9] = v4;
        }
        ++v0;
    }
    return v4;
}

//----- (004537F0) --------------------------------------------------------
int sub_4537F0()
{
    int v0; // esi
    int v1; // edi
    int v2; // eax
    int v3; // eax
    int v4; // esi
    int v5; // edi
    int result; // eax
    int v7; // eax

    v0 = 1;
    v1 = 26;
    do
    {
        v2 = sub_415CD0((char*)v0);
        if (v2)
        {
            v3 = sub_4E3B70(v2);
            sub_4E3BF0(v3);
        }
        v0 *= 2;
        --v1;
    } while (v1);
    v4 = 1;
    v5 = 27;
    do
    {
        result = sub_415840((char*)v4);
        if (result)
        {
            v7 = sub_4E3B70(result);
            result = sub_4E3BF0(v7);
        }
        v4 *= 2;
        --v5;
    } while (v5);
    return result;
}

//----- (00453850) --------------------------------------------------------
int __cdecl sub_453850(int a1)
{
    int v1; // ebx
    int v2; // eax
    int v3; // esi
    int v4; // edi
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    const wchar_t* v8; // eax
    _DWORD* v9; // esi
    _DWORD* v10; // esi
    wchar_t v12[64]; // [esp+Ch] [ebp-80h]

    *(_DWORD*)& byte_5D4594[1045484] = nox_new_window_from_file("spelllst.wnd", sub_453C00);
    sub_46B340(*(int*)& byte_5D4594[1045484], sub_453B80);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1045484], a1);
    sub_46B280(*(int*)& byte_5D4594[1045484], a1);
    *(_DWORD*)& byte_5D4594[1045480] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], 1110);
    *(_DWORD*)& byte_5D4594[1045508] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], 1112);
    sub_453B00();
    nox_window_call_field_94(*(int*)& byte_5D4594[1045480], 16399, 0, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045508], 16399, 0, 0);
    v1 = 1;
    do
    {
        if (sub_424B50(v1))
        {
            v2 = sub_424A70(v1);
            v3 = v2;
            if (!(v2 & 0x15000))
            {
                if (v2 & 0x1000000 || (v4 = v2 & 0x2000000) != 0 && v2 & 0x4000000)
                {
                    v7 = loadString_sub_40F1D0((char*)& byte_587000[127452], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 307);
                    nox_wcscpy(v12, v7);
                }
                else
                {
                    if (!(v2 & 0x6000000))
                        goto LABEL_14;
                    nox_wcscpy(v12, (const wchar_t*)& byte_5D4594[1045512]);
                    if (v4)
                    {
                        v5 = loadString_sub_40F1D0((char*)& byte_587000[127508], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 314);
                        nox_wcscat(v12, v5);
                    }
                    if (v3 & 0x4000000)
                    {
                        v6 = loadString_sub_40F1D0((char*)& byte_587000[127568], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 318);
                        nox_wcscat(v12, v6);
                    }
                }
                nox_window_call_field_94(*(int*)& byte_5D4594[1045508], 16397, (int)v12, -1);
                v8 = (const wchar_t*)sub_424930(v1);
                nox_wcsncpy(v12, v8, 0x3Fu);
                nox_window_call_field_94(*(int*)& byte_5D4594[1045480], 16397, (int)v12, -1);
            }
        }
    LABEL_14:
        ++v1;
    } while (v1 < 137);
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], 1113);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045480], 16408, (int)v9, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045508], 16408, (int)v9, 0);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], 1114);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045480], 16409, (int)v10, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045508], 16409, (int)v10, 0);
    sub_454040(&byte_5D4594[1045488]);
    sub_454120();
    if (!sub_40A5C0(1) || sub_40A5C0(49152))
        sub_46AD20(*(_DWORD * *)& byte_5D4594[1045484], 1115, 1133, 0);
    return *(_DWORD*)& byte_5D4594[1045484];
}

//----- (00453B00) --------------------------------------------------------
_DWORD* sub_453B00()
{
    int v0; // esi
    int v1; // edi
    int v2; // ebx
    _DWORD* result; // eax

    v0 = sub_43F320(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1045480] + 236)) + 1;
    sub_46AB20(*(_DWORD * *)& byte_5D4594[1045480], *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045480] + 8), 15 * v0 + 2);
    sub_46AB20(*(_DWORD * *)& byte_5D4594[1045508], *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045508] + 8), 15 * v0 + 2);
    v1 = 1120;
    v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045480] + 20) + v0 + 2;
    do
    {
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], v1);
        result[5] = v2;
        v2 += v0;
        ++v1;
    } while (v1 < 1134);
    return result;
}

//----- (00453B80) --------------------------------------------------------
int __cdecl sub_453B80(int a1, int a2)
{
    int result; // eax
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        result = 1;
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
        result = 1;
    }
    return result;
}

//----- (00453C00) --------------------------------------------------------
int __cdecl sub_453C00(int a1, int a2, int* a3, int a4)
{
    int* v3; // edi
    int v4; // ebx
    __int16* v5; // edi
    int v6; // ebp
    int v7; // ebx
    int v8; // esi
    int i; // eax
    int result; // eax
    int v11; // esi
    wchar_t* v12; // eax
    int v13; // esi
    wchar_t* v14; // eax
    char* v15; // ebp
    wchar_t* v16; // eax
    wchar_t* v17; // [esp-10h] [ebp-5Ch]
    wchar_t* v18; // [esp-10h] [ebp-5Ch]
    int v19[15]; // [esp+10h] [ebp-3Ch]
    char* v20; // [esp+54h] [ebp+8h]
    int v21; // [esp+58h] [ebp+Ch]

    if (a2 == 0x4000)
    {
        if (a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], 1113)
            || a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], 1114))
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1045480], 0x4000, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1045508], 0x4000, (int)a3, 0);
        LABEL_37:
            sub_454120();
        }
        return 0;
    }
    if (a2 != 16391)
        return 0;
    v3 = a3;
    v4 = sub_46B0A0(a3);
    v21 = v4;
    switch (v4)
    {
    case 1113:
    case 1114:
        nox_window_call_field_94(*(int*)& byte_5D4594[1045480], 0x4000, (int)v3, 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[1045508], 0x4000, (int)v3, 0);
        goto LABEL_37;
    case 1115:
    case 1116:
        v5 = *(__int16**)(*(_DWORD*)& byte_5D4594[1045480] + 32);
        v6 = 0;
        v20 = sub_4165B0();
        if (*v5 > 0)
        {
            v7 = 0;
            do
            {
                if (*((_DWORD*)v5 + 6) + v7 != -4)
                {
                    v8 = sub_424960((wchar_t*)(*((_DWORD*)v5 + 6) + v7 + 4));
                    if (v8)
                    {
                        if (v21 == 1115)
                        {
                            if (!sub_40A5C0(64) && !(v20[52] & 0x40) || v8 != 132)
                                sub_453FA0((int)& byte_5D4594[1045488], v8, 1);
                        }
                        else
                        {
                            sub_453FA0((int)& byte_5D4594[1045488], v8, 0);
                        }
                    }
                }
                ++v6;
                v7 += 524;
            } while (v6 < *v5);
        }
        if (*(_DWORD*)& byte_5D4594[2650652])
        {
            sub_57A1E0(v19, 0, 0, 4, 6128);
            for (i = 0; i < 5; ++i)
                * (_DWORD*)& byte_5D4594[i * 4 + 1045488] &= v19[i + 6];
        }
        sub_454120();
        goto LABEL_19;
    case 1120:
    case 1121:
    case 1122:
    case 1123:
    case 1124:
    case 1125:
    case 1126:
    case 1127:
    case 1128:
    case 1129:
    case 1130:
    case 1131:
    case 1132:
    case 1133:
        v11 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045480] + 32);
        v12 = (wchar_t*)(*(_DWORD*)(v11 + 24)
            + 524 * (sub_4A4800(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1045480] + 32)) + v4 - 1120)
            + 4);
        if (!v12)
            goto LABEL_19;
        v13 = sub_424960(v12);
        if (!v13)
            goto LABEL_19;
        if (!*(_DWORD*)& byte_5D4594[2650652] || (sub_57A1E0(v19, 0, 0, 4, 6128), sub_454000((int)& v19[6], v13)))
        {
            v15 = sub_4165B0();
            if ((sub_40A5C0(64) || v15[52] & 0x40) && v13 == 132)
            {
                v3[9] ^= 4u;
                v18 = loadString_sub_40F1D0((char*)& byte_587000[127748], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 226);
                v16 = loadString_sub_40F1D0((char*)& byte_587000[127816], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 225);
                sub_449A10(*(int*)& byte_5D4594[1045484], (int)v16, (int)v18, 33, 0, 0);
                sub_44A360(1);
            }
            else
            {
                if (v3[9] & 4)
                    sub_453FA0((int)& byte_5D4594[1045488], v13, 0);
                else
                    sub_453FA0((int)& byte_5D4594[1045488], v13, 1);
            LABEL_19:
                sub_459D50(1);
            }
        }
        else
        {
            v3[9] ^= 4u;
            v17 = loadString_sub_40F1D0((char*)& byte_587000[127632], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 211);
            v14 = loadString_sub_40F1D0((char*)& byte_587000[127692], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\spelllst.c", 210);
            sub_449A10(*(int*)& byte_5D4594[1045484], (int)v14, (int)v17, 33, 0, 0);
            sub_44A360(1);
        }
    LABEL_20:
        sub_452D80(766, 100);
        result = 0;
        break;
    default:
        goto LABEL_20;
    }
    return result;
}

//----- (00453F70) --------------------------------------------------------
void __cdecl sub_453F70(const void* a1)
{
    qmemcpy(&byte_5D4594[1045488], a1, 0x14u);
}

//----- (00453F90) --------------------------------------------------------
char* sub_453F90()
{
    return (char*)& byte_5D4594[1045488];
}

//----- (00453FA0) --------------------------------------------------------
int __cdecl sub_453FA0(int a1, int a2, int a3)
{
    bool v3; // sf
    char v4; // cl
    int result; // eax
    unsigned __int8 v6; // [esp+8h] [ebp+8h]

    v4 = a2 & 0x1F;
    v3 = (a2 & 0x8000001F & 0x80000000) != 0;
    v6 = a2 / 32;
    if (v3)
        v4 = ((v4 - 1) | 0xE0) + 1;
    result = 1 << v4;
    if (a3)
    {
        *(_DWORD*)(a1 + 4 * v6) |= result;
    }
    else
    {
        result = ~result;
        *(_DWORD*)(a1 + 4 * v6) &= result;
    }
    return result;
}

//----- (00454000) --------------------------------------------------------
BOOL __cdecl sub_454000(int a1, int a2)
{
    return (*(_DWORD*)(a1 + 4 * ((a2 / 32) & 0xFF)) & (1 << (a2 % 32))) != 0;
}

//----- (00454040) --------------------------------------------------------
int __cdecl sub_454040(_DWORD* a1)
{
    int v1; // esi
    int v2; // edi
    int result; // eax
    unsigned __int8 v4; // [esp+Ch] [ebp-4h]

    v1 = 1;
    *a1 = -1;
    v4 = 0;
    v2 = 1;
    a1[1] = -1;
    a1[2] = -1;
    a1[3] = -1;
    a1[4] = -1;
    do
    {
        if (v1 == 0x80000000)
        {
            v1 = 1;
            ++v4;
        }
        else
        {
            v1 *= 2;
        }
        result = sub_424B50(v2);
        if (result)
        {
            result = sub_424A70(v2);
            if (result & 0x7000000)
            {
                result = sub_424B70(v2);
                if (!result)
                {
                    result = (int)& a1[v4];
                    *(_DWORD*)result = ~v1 & a1[v4];
                }
            }
        }
        ++v2;
    } while (v2 < 137);
    return result;
}

//----- (004540E0) --------------------------------------------------------
int __cdecl sub_4540E0(int a1)
{
    int v1; // esi
    int result; // eax

    v1 = 1;
    do
    {
        if (sub_454000(a1, v1))
            result = sub_424B90(v1);
        else
            result = sub_424BB0(v1);
        ++v1;
    } while (v1 < 137);
    return result;
}

//----- (00454120) --------------------------------------------------------
char sub_454120()
{
    int v0; // ebp
    int v1; // ebx
    _DWORD* v2; // esi
    int v3; // edi
    int v4; // ecx
    bool v5; // zf
    int v6; // eax
    int v8; // [esp+10h] [ebp-4h]

    v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045480] + 32);
    v0 = 1120;
    v1 = 524 * sub_4A4800(v8);
    do
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045484], v0);
        v3 = 0;
        v4 = *(_DWORD*)(v8 + 24);
        if (v4 + v1 != -4 && *(_WORD*)(v4 + v1 + 4))
        {
            v3 = sub_424960((wchar_t*)(v4 + v1 + 4));
            nox_window_set_hidden((int)v2, 0);
        }
        else
        {
            nox_window_set_hidden((int)v2, 1);
        }
        v1 += 524;
        if (v3)
        {
            v5 = !sub_454000((int)& byte_5D4594[1045488], v3);
            v6 = v2[9];
            if (!v5)
            {
                LOBYTE(v6) = v6 | 4;
                goto LABEL_11;
            }
        }
        else
        {
            v6 = v2[9];
        }
        LOBYTE(v6) = v6 & 0xFB;
    LABEL_11:
        ++v0;
        v2[9] = v6;
    } while (v0 <= 1133);
    return v6;
}

//----- (004541D0) --------------------------------------------------------
int __cdecl sub_4541D0(int a1)
{
    int v2; // esi
    _DWORD* v3; // ebx
    char* v4; // ebp
    char* v5; // esi
    _DWORD* v6; // edi
    _DWORD* v7; // ebx
    _DWORD* v8; // edi
    _DWORD* v9; // ebx
    _DWORD* v10; // edi
    _DWORD* v11; // eax
    _DWORD* v12; // [esp+0h] [ebp-4h]
    _DWORD* v13; // [esp+0h] [ebp-4h]
    int v14; // [esp+0h] [ebp-4h]
    _DWORD* v15; // [esp+8h] [ebp+4h]
    _DWORD* v16; // [esp+8h] [ebp+4h]
    _DWORD* v17; // [esp+8h] [ebp+4h]

    if (*(_DWORD*)& byte_5D4594[1045516])
        return 0;
    v2 = *(_DWORD*)& byte_587000[26048];
    if (sub_43F320(0) > 10)
        v2 = 2;
    *(_DWORD*)& byte_5D4594[1045516] = nox_new_window_from_file(*(const char**)& byte_587000[4 * v2 + 127824], sub_454BA0);
    sub_43FE20(100);
    sub_416640();
    sub_46B120(*(_DWORD * *)& byte_5D4594[1045516], a1);
    *(_DWORD*)& byte_5D4594[1045520] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10102);
    *(_DWORD*)& byte_5D4594[1045524] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10103);
    *(_DWORD*)& byte_5D4594[1045532] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10109);
    *(_DWORD*)& byte_5D4594[1045528] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10105);
    *(_DWORD*)& byte_5D4594[1045536] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10200);
    *(_DWORD*)& byte_5D4594[1045540] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10111);
    *(_DWORD*)& byte_5D4594[1045544] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10112);
    *(_DWORD*)& byte_5D4594[1045548] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10113);
    *(_DWORD*)& byte_5D4594[1045556] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10104);
    *(_DWORD*)& byte_5D4594[1045560] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10125);
    *(_DWORD*)& byte_5D4594[1045564] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10127);
    *(_DWORD*)& byte_5D4594[1045568] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10129);
    *(_DWORD*)& byte_5D4594[1045572] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10131);
    *(_DWORD*)& byte_5D4594[1045576] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10126);
    *(_DWORD*)& byte_5D4594[1045580] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10128);
    *(_DWORD*)& byte_5D4594[1045584] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10130);
    *(_DWORD*)& byte_5D4594[1045588] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10132);
    *(_DWORD*)& byte_5D4594[1045552] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10123);
    *(_DWORD*)& byte_5D4594[1045592] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10133);
    v3 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[1045532] + 32);
    v4 = sub_42F970("UISlider");
    v5 = sub_42F970("UISliderLit");
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10190);
    v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10188);
    v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10189);
    *(_DWORD*)(v6[100] + 8) = 16;
    *(_DWORD*)(v6[100] + 12) = 10;
    sub_4B5700((int)v6, 0, 0, (int)v4, (int)v5, (int)v5);
    sub_46B280((int)v6, *(int*)& byte_5D4594[1045532]);
    sub_46B280((int)v15, *(int*)& byte_5D4594[1045532]);
    sub_46B280((int)v12, *(int*)& byte_5D4594[1045532]);
    v3[9] = v6;
    v3[7] = v15;
    v3[8] = v12;
    v7 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[1045528] + 32);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10187);
    v16 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10185);
    v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10186);
    *(_DWORD*)(v8[100] + 8) = 16;
    *(_DWORD*)(v8[100] + 12) = 10;
    sub_4B5700((int)v8, 0, 0, (int)v4, (int)v5, (int)v5);
    sub_46B280((int)v8, *(int*)& byte_5D4594[1045528]);
    sub_46B280((int)v16, *(int*)& byte_5D4594[1045528]);
    sub_46B280((int)v13, *(int*)& byte_5D4594[1045528]);
    v7[9] = v8;
    v7[7] = v16;
    v7[8] = v13;
    v9 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[1045536] + 32);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10203);
    v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10201);
    v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10202);
    *(_DWORD*)(v10[100] + 8) = 16;
    v14 = (int)v11;
    *(_DWORD*)(v10[100] + 12) = 10;
    sub_4B5700((int)v10, 0, 0, (int)v4, (int)v5, (int)v5);
    sub_46B280((int)v10, *(int*)& byte_5D4594[1045536]);
    sub_46B280((int)v17, *(int*)& byte_5D4594[1045536]);
    sub_46B280(v14, *(int*)& byte_5D4594[1045536]);
    v9[9] = v10;
    v9[7] = v17;
    v9[8] = v14;
    sub_454740();
    sub_454640();
    if (sub_40A5C0(1))
        sub_46B340(*(int*)& byte_5D4594[1045516], sub_454A90);
    sub_46A8A0();
    return *(_DWORD*)& byte_5D4594[1045516];
}

//----- (00454640) --------------------------------------------------------
int sub_454640()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi
    int v2; // eax
    unsigned __int16* v3; // eax
    unsigned __int16* v4; // eax
    unsigned __int16* v5; // eax
    int v6; // eax
    int v7; // eax
    int result; // eax
    int v9; // [esp+4h] [ebp-8h]
    int v10; // [esp+8h] [ebp-4h]

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10123);
    v1 = v0;
    v2 = sub_43F320(v0[59]) + 1;
    v1[7] = v1[5] + 4 * v2 + 2;
    v1[3] = 4 * v2 + 2;
    v3 = loadString_sub_40F1D0((char*)& byte_587000[128040], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 88);
    sub_43F840(v1[59], v3, &v9, 0, 0);
    v4 = loadString_sub_40F1D0((char*)& byte_587000[128092], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 89);
    sub_43F840(v1[59], v4, &v10, 0, 0);
    if (v10 > v9)
        v9 = v10;
    v5 = loadString_sub_40F1D0((char*)& byte_587000[128144], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 94);
    sub_43F840(v1[59], v5, &v10, 0, 0);
    v6 = v9;
    if (v10 > v9)
        v6 = v10;
    v7 = v6 + 7;
    v9 = v7;
    v1[2] = v7;
    result = v9 + v1[4];
    v1[6] = result;
    return result;
}

//----- (00454740) --------------------------------------------------------
int* sub_454740()
{
    char* v0; // esi
    _DWORD* v1; // edi
    wchar_t* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    char v9; // dl
    int v10; // ecx
    int v11; // eax
    char* i; // esi
    WCHAR WideCharStr[18]; // [esp+Ch] [ebp-24h]

    v0 = sub_416640();
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10136);
    v2 = sub_40A630();
    nox_window_call_field_94((int)v1, 16414, (int)v2, 0);
    if (*(short*)(v0 + 105) != -1)
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045584], 1);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045568] + 36) |= 4u;
        _itow(*(unsigned __int16*)(v0 + 105), WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1045584], 16414, (int)WideCharStr, 0);
    }
    if (*(short*)(v0 + 107) != -1)
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045588], 1);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045572] + 36) |= 4u;
        _itow(*(unsigned __int16*)(v0 + 107), WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1045588], 16414, (int)WideCharStr, 0);
    }
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10124);
    if ((int)v0[102] < 0)
        v3[9] |= 4u;
    if (v0[100] & 0x20)
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045556], 1);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045524] + 36) |= 4u;
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[1045556], 16414, (int)(v0 + 78), 0);
    if (sub_4D6F30())
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045520], 0);
    }
    else
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045520], 1);
        if (v0[100] & 0x10)
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045520] + 36) = 4;
        }
        else
        {
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10206);
            sub_46ABB0((int)v4, 0);
        }
    }
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10207);
    v5[9] |= 4u;
    *(_DWORD*)& byte_5D4594[1045596] = *(_DWORD*)& byte_5D4594[1045528];
    v6 = loadString_sub_40F1D0((char*)& byte_587000[128200], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 242);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045552], 16397, (int)v6, -1);
    v7 = loadString_sub_40F1D0((char*)& byte_587000[128252], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 243);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045552], 16397, (int)v7, -1);
    v8 = loadString_sub_40F1D0((char*)& byte_587000[128304], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 244);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045552], 16397, (int)v8, -1);
    if (v0[100] & 0x10)
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1045532], 0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1045528], 1);
    }
    v9 = v0[100];
    if (v9)
    {
        v10 = 0;
        v11 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045552] + 32);
        if (v9 & 1)
        {
            **(_DWORD * *)(v11 + 48) = 0;
            v10 = 1;
            *(_DWORD*)(*(_DWORD*)(v11 + 48) + 4) = -1;
        }
        if (v0[100] & 2)
        {
            *(_DWORD*)(*(_DWORD*)(v11 + 48) + 4 * ++v10 - 4) = 1;
            *(_DWORD*)(*(_DWORD*)(v11 + 48) + 4 * v10) = -1;
        }
        if (v0[100] & 4)
        {
            *(_DWORD*)(*(_DWORD*)(v11 + 48) + 4 * v10) = 2;
            *(_DWORD*)(*(_DWORD*)(v11 + 48) + 4 * v10 + 4) = -1;
        }
    }
    _itow((unsigned __int8)v0[104], WideCharStr, 10);
    nox_window_call_field_94(*(int*)& byte_5D4594[1045592], 16414, (int)WideCharStr, 0);
    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        if (i[2064] != 31 || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
            sub_455920((int)(i + 4704));
    }
    return sub_455800();
}

//----- (00454A90) --------------------------------------------------------
int __cdecl sub_454A90(int a1, int a2)
{
    _WORD* v2; // eax
    int v3; // eax
    char v4; // cl
    int xLeft; // [esp+8h] [ebp-8h]
    int yTop; // [esp+Ch] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045540] + 4) & 8)
    {
        v2 = (_WORD*)nox_window_call_field_94(*(int*)& byte_5D4594[1045540], 16413, 0, 0);
        if (v2 && *v2)
        {
            if (!(*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045544] + 4) & 8))
                sub_46ABB0(*(int*)& byte_5D4594[1045544], 1);
        }
        else if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045544] + 4) & 8)
        {
            sub_46ABB0(*(int*)& byte_5D4594[1045544], 0);
        }
    }
    v3 = nox_window_call_field_94(*(int*)& byte_5D4594[1045596], 16404, 0, 0);
    v4 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1045548] + 4);
    if (v3 < 0)
    {
        if (v4 & 8)
            sub_46ABB0(*(int*)& byte_5D4594[1045548], 0);
    }
    else if (!(v4 & 8))
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045548], 1);
        return 1;
    }
    return 1;
}

//----- (00454BA0) --------------------------------------------------------
int __cdecl sub_454BA0(int a1, int a2, int* a3, int a4)
{
    int v4; // eax
    int result; // eax
    char* v6; // eax
    int v7; // esi
    char* v8; // esi
    const wchar_t* v9; // eax
    char* v10; // esi
    const wchar_t* v11; // eax
    char* v12; // esi
    const wchar_t* v13; // eax
    char* v14; // esi
    const wchar_t* v15; // eax
    char* v16; // eax
    char v17; // dl
    _DWORD* v18; // esi
    _DWORD* v19; // eax
    _DWORD* v20; // eax
    char* v21; // esi
    wchar_t* v22; // esi
    int v23; // esi
    int v24; // esi
    char* v25; // eax
    int* v26; // eax
    int* v27; // ebp
    int v28; // eax
    wchar_t* v29; // eax
    wchar_t* v30; // edi
    char* v31; // eax
    char* v32; // esi
    int* v33; // eax
    int* v34; // edi
    int v35; // eax
    wchar_t* v36; // eax
    char* v37; // eax
    char* v38; // esi
    char* v39; // ebp
    const wchar_t* v40; // eax
    wchar_t* v41; // esi
    int v42; // ebx
    int v43; // ebp
    _DWORD* v44; // esi
    const wchar_t* v45; // eax
    wchar_t* v46; // edi
    int v47; // ebx
    WCHAR WideCharStr[8]; // [esp+10h] [ebp-10h]
    char* v49; // [esp+28h] [ebp+8h]
    char* v50; // [esp+30h] [ebp+10h]
    char* v51; // [esp+30h] [ebp+10h]

    switch (a2)
    {
    case 16387:
        v43 = a4;
        v44 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], a4);
        v51 = sub_416630();
        v49 = sub_416640();
        if (!v44 || (unsigned __int16)a3 == 1)
            goto LABEL_101;
        v45 = (const wchar_t*)nox_window_call_field_94((int)v44, 16413, 0, 0);
        v46 = (wchar_t*)v45;
        if (!v45 || !*v45 || (v47 = nox_wcstol(v45, 0, 10), v47 < 0))
            v47 = 0;
        switch (v43)
        {
        case 10104:
            nox_wcscpy((wchar_t*)v49 + 39, v46);
            goto LABEL_101;
        case 10126:
            if (v47 > 14)
            {
                LOBYTE(v47) = 14;
                _itow(14, WideCharStr, 10);
                nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
            }
            v51[1] = v47 | v51[1] & 0xF0;
            result = 0;
            break;
        case 10128:
            if (v47 > 14)
            {
                LOBYTE(v47) = 14;
                _itow(14, WideCharStr, 10);
                nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
            }
            v51[1] = (16 * v47) | v51[1] & 0xF;
            result = 0;
            break;
        case 10130:
            *(_WORD*)(v51 + 5) = v47;
            result = 0;
            break;
        case 10132:
            *(_WORD*)(v51 + 7) = v47;
            result = 0;
            break;
        case 10133:
            if (v47 <= 32)
            {
                if (v47 < 1)
                {
                    v47 = 1;
                    _itow(1, WideCharStr, 10);
                    nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
                }
            }
            else
            {
                v47 = 32;
                _itow(32, WideCharStr, 10);
                nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
            }
            sub_409F80(v47);
            result = 0;
            v51[4] = v47;
            break;
        case 10136:
            sub_40A610(v46);
            result = 0;
            break;
        default:
            goto LABEL_101;
        }
        break;
    case 16391:
        v7 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        switch (v7)
        {
        case 10102:
            v16 = sub_416630();
            v17 = *v16 ^ 0x10;
            *v16 = v17;
            if (v17 & 0x10)
            {
                v20 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10206);
                sub_46ABB0((int)v20, 1);
            }
            else
            {
                v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10206);
                sub_46ABB0((int)v18, 0);
                v18[9] &= 0xFFFFFFFB;
                v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10207);
                v19[9] |= 4u;
                nox_window_set_hidden(*(int*)& byte_5D4594[1045532], 1);
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045516], 10188, 10190, 1);
                nox_window_set_hidden(*(int*)& byte_5D4594[1045528], 0);
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045516], 10185, 10187, 0);
            }
            return 0;
        case 10103:
            v21 = sub_416630();
            sub_46ABB0(
                *(int*)& byte_5D4594[1045556],
                ((unsigned int)~*(_DWORD*)(*(_DWORD*)& byte_5D4594[1045524] + 36) >> 2) & 1);
            *v21 ^= 0x20u;
            return 0;
        case 10112:
            v22 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045540], 16413, 0, 0);
            if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1045528]))
                sub_4168A0(v22);
            else
                sub_416770(0, v22, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1045540], 16414, (int)& byte_5D4594[1045600], 0);
            return 0;
        case 10113:
            sub_416640();
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045520] + 36) & 4)
            {
                v23 = nox_window_call_field_94(*(int*)& byte_5D4594[1045532], 16404, 0, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1045532], 16398, v23, 0);
                sub_416860(v23);
            }
            else
            {
                v24 = nox_window_call_field_94(*(int*)& byte_5D4594[1045528], 16404, 0, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[1045528], 16398, v24, 0);
                sub_416820(v24);
            }
            return 0;
        case 10124:
            v25 = sub_416630();
            v25[2] ^= 0x80u;
            return 0;
        case 10125:
            v8 = sub_416630();
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045560] + 36) & 4)
            {
                sub_46ABB0(*(int*)& byte_5D4594[1045576], 0);
                v8[1] |= 0xFu;
                return 0;
            }
            sub_46ABB0(*(int*)& byte_5D4594[1045576], 1);
            v9 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045576], 16413, 0, 0);
            if (!*v9)
                goto LABEL_101;
            v8[1] = v8[1] & 0xF0 | nox_wcstol(v9, 0, 10);
            return 0;
        case 10127:
            v10 = sub_416630();
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045564] + 36) & 4)
            {
                sub_46ABB0(*(int*)& byte_5D4594[1045580], 0);
                v10[1] |= 0xF0u;
                return 0;
            }
            sub_46ABB0(*(int*)& byte_5D4594[1045580], 1);
            v11 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045580], 16413, 0, 0);
            if (!*v11)
                goto LABEL_101;
            v10[1] = v10[1] & 0xF | nox_wcstol(v11, 0, 10);
            return 0;
        case 10129:
            v12 = sub_416630();
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045568] + 36) & 4)
            {
                sub_46ABB0(*(int*)& byte_5D4594[1045584], 0);
                *(_WORD*)(v12 + 5) = -1;
                return 0;
            }
            sub_46ABB0(*(int*)& byte_5D4594[1045584], 1);
            v13 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045584], 16413, 0, 0);
            if (!*v13)
                goto LABEL_101;
            *(_WORD*)(v12 + 5) = nox_wcstol(v13, 0, 10);
            return 0;
        case 10131:
            v14 = sub_416630();
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1045572] + 36) & 4)
            {
                sub_46ABB0(*(int*)& byte_5D4594[1045588], 0);
                *(_WORD*)(v14 + 7) = -1;
                return 0;
            }
            sub_46ABB0(*(int*)& byte_5D4594[1045588], 1);
            v15 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045588], 16413, 0, 0);
            if (!*v15)
                goto LABEL_101;
            *(_WORD*)(v14 + 7) = nox_wcstol(v15, 0, 10);
            result = 0;
            break;
        case 10191:
            v33 = (int*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16404, 0, 0);
            v34 = v33;
            v35 = *v33;
            if (v35 < 0)
                goto LABEL_101;
            do
            {
                v36 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16406, v35, 0);
                v37 = sub_4170D0(v36);
                v38 = v37;
                if (v37 && v37[2064] != 31)
                {
                    if (sub_40A5C0(4096))
                        sub_4DCFB0(*((_DWORD*)v38 + 514));
                    else
                        sub_4DEAB0((unsigned __int8)v38[2064], 4);
                }
                v35 = v34[1];
                ++v34;
            } while (v35 >= 0);
            return 0;
        case 10192:
            v26 = (int*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16404, 0, 0);
            v27 = v26;
            v28 = *v26;
            if (v28 < 0)
                goto LABEL_101;
            do
            {
                v29 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16406, v28, 0);
                v30 = v29;
                v31 = sub_4170D0(v29);
                v32 = v31;
                if (v31 && v31[2064] != 31)
                {
                    if (sub_40A5C0(4096))
                        sub_4DCFB0(*((_DWORD*)v32 + 514));
                    else
                        sub_4DEB00((unsigned __int8)v32[2064]);
                    sub_416770(0, v30, v32 + 2112);
                }
                v28 = v27[1];
                ++v27;
            } while (v28 >= 0);
            return 0;
        case 10206:
            nox_window_set_hidden(*(int*)& byte_5D4594[1045532], 0);
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045516], 10188, 10190, 0);
            nox_window_set_hidden(*(int*)& byte_5D4594[1045528], 1);
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045516], 10185, 10187, 1);
            *(_DWORD*)& byte_5D4594[1045596] = *(_DWORD*)& byte_5D4594[1045532];
            return 0;
        case 10207:
            nox_window_set_hidden(*(int*)& byte_5D4594[1045532], 1);
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045516], 10188, 10190, 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1045528], 0);
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045516], 10185, 10187, 0);
            *(_DWORD*)& byte_5D4594[1045596] = *(_DWORD*)& byte_5D4594[1045528];
            return 0;
        default:
            goto LABEL_101;
        }
        break;
    case 16400:
        v4 = sub_46B0A0(a3) - 10123;
        if (v4)
        {
            if (v4 != 77)
                goto LABEL_101;
            if (sub_455770())
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1045516], 10191, 10192, 1);
            else
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1045516], 10191, 10192, 0);
            result = 0;
        }
        else
        {
            v6 = sub_416640();
            v6[100] ^= 1 << a4;
            result = 0;
        }
        break;
    case 16415:
        v39 = sub_416630();
        v50 = sub_416640();
        v40 = (const wchar_t*)nox_window_call_field_94((int)a3, 16413, 0, 0);
        v41 = (wchar_t*)v40;
        if (!v40 || !*v40 || (v42 = nox_wcstol(v40, 0, 10), v42 < 0))
            v42 = 0;
        switch (sub_46B0A0(a3))
        {
        case 10104:
            nox_wcscpy((wchar_t*)v50 + 39, v41);
            goto LABEL_101;
        case 10126:
            if (v42 > 14)
            {
                LOBYTE(v42) = 14;
                _itow(14, WideCharStr, 10);
                nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
            }
            result = 0;
            v39[1] = v42 | v39[1] & 0xF0;
            break;
        case 10128:
            if (v42 > 14)
            {
                LOBYTE(v42) = 14;
                _itow(14, WideCharStr, 10);
                nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
            }
            result = 0;
            v39[1] = (16 * v42) | v39[1] & 0xF;
            break;
        case 10130:
            *(_WORD*)(v39 + 5) = v42;
            result = 0;
            break;
        case 10132:
            *(_WORD*)(v39 + 7) = v42;
            result = 0;
            break;
        case 10133:
            if (v42 <= 32)
            {
                if (v42 < 1)
                {
                    v42 = 1;
                    _itow(1, WideCharStr, 10);
                    nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
                }
            }
            else
            {
                v42 = 32;
                _itow(32, WideCharStr, 10);
                nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
            }
            sub_409F80(v42);
            v39[4] = v42;
            result = 0;
            break;
        case 10136:
            sub_40A610(v41);
            result = 0;
            break;
        default:
            goto LABEL_101;
        }
        break;
    default:
    LABEL_101:
        result = 0;
        break;
    }
    return result;
}

//----- (00455770) --------------------------------------------------------
int sub_455770()
{
    int* v0; // eax
    int* v1; // esi
    int v2; // eax
    wchar_t* v3; // eax
    char* v4; // eax

    v0 = (int*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16404, 0, 0);
    v1 = v0;
    v2 = *v0;
    if (v2 < 0)
        return 0;
    while (1)
    {
        v3 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16406, v2, 0);
        v4 = sub_4170D0(v3);
        if (v4)
        {
            if (v4[2064] != 31)
                break;
        }
        v2 = v1[1];
        ++v1;
        if (v2 < 0)
            return 0;
    }
    return 1;
}

//----- (004557D0) --------------------------------------------------------
int __cdecl sub_4557D0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        result = *(_DWORD*)& byte_5D4594[1045516];
        if (*(_DWORD*)& byte_5D4594[1045516])
            result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1045516]);
    }
    *(_DWORD*)& byte_5D4594[1045516] = 0;
    return result;
}

//----- (00455800) --------------------------------------------------------
int* sub_455800()
{
    int* result; // eax
    int v1; // eax
    int* i; // esi
    int* j; // esi
    WCHAR WideCharStr[10]; // [esp+4h] [ebp-48h]
    wchar_t v5[26]; // [esp+18h] [ebp-34h]

    result = *(int**)& byte_5D4594[1045516];
    if (*(_DWORD*)& byte_5D4594[1045516])
    {
        v1 = sub_409FA0();
        _itow(v1, WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1045592], 16414, (int)WideCharStr, 0);
        result = (int*)sub_40A5C0(1);
        if (result)
        {
            sub_416640();
            nox_window_call_field_94(*(int*)& byte_5D4594[1045528], 16399, 0, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1045532], 16399, 0, 0);
            for (i = sub_4168E0(); i; i = sub_4168F0(i))
                nox_window_call_field_94(*(int*)& byte_5D4594[1045532], 16397, (int)(i + 3), -1);
            result = sub_416900();
            for (j = result; result; j = result)
            {
                if (*((_BYTE*)j + 72))
                {
                    nox_window_call_field_94(*(int*)& byte_5D4594[1045528], 16397, (int)(j + 3), -1);
                }
                else
                {
                    nox_swprintf(v5, L"*%s", j + 3);
                    nox_window_call_field_94(*(int*)& byte_5D4594[1045528], 16397, (int)v5, -1);
                }
                result = sub_416910(j);
            }
        }
    }
    return result;
}

//----- (00455920) --------------------------------------------------------
int __cdecl sub_455920(int a1)
{
    int result; // eax
    _DWORD* v2; // eax

    result = *(_DWORD*)& byte_5D4594[1045516];
    if (*(_DWORD*)& byte_5D4594[1045516])
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045516], 10200);
        result = nox_window_call_field_94((int)v2, 16397, a1, 3);
    }
    return result;
}

//----- (00455950) --------------------------------------------------------
void __cdecl sub_455950(wchar_t* a1)
{
    int v1; // eax

    if (*(_DWORD*)& byte_5D4594[1045516])
    {
        v1 = sub_4559B0(a1);
        if (v1 != -1)
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16398, v1, 0);
            if (!sub_455770())
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1045516], 10191, 10192, 0);
        }
    }
}

//----- (004559B0) --------------------------------------------------------
int __cdecl sub_4559B0(wchar_t* a1)
{
    int v1; // esi
    int v2; // ebx
    const wchar_t* v3; // eax

    v1 = 0;
    v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045536] + 32);
    if (*(short*)(v2 + 44) <= 0)
        return -1;
    while (1)
    {
        v3 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1045536], 16406, v1, 0);
        if (!nox_wcscmp(v3, a1))
            break;
        if (++v1 >= *(__int16*)(v2 + 44))
            return -1;
    }
    return v1;
}

//----- (00455A00) --------------------------------------------------------
int __cdecl sub_455A00(int a1)
{
    int result; // eax

    if (a1 && *(_DWORD*)& byte_5D4594[1045608] && sub_46ADA0(*(int*)& byte_5D4594[1045604]) & 0x10)
        result = sub_46A8C0(*(int*)& byte_5D4594[1045604]);
    else
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1045604], 1);
    return result;
}

//----- (00455A50) --------------------------------------------------------
char __cdecl sub_455A50(char a1)
{
    _DWORD* v1; // edi
    int v2; // eax
    int v3; // esi
    int v4; // edx

    v1 = 0;
    sub_418C80(*(int*)& byte_5D4594[2616328]);
    if (!(*(_DWORD*)& byte_5D4594[1045604] || (v2 = sub_455C30()) != 0))
    {
        return v2;
    }
    int cur_w, cur_h, cur_d;
    sub_43BEB0_get_video_mode(&cur_w, &cur_h, &cur_d);

    int max_w, max_h;
    sub_430C50_get_video_max(&max_w, &max_h);

    if (cur_w > max_w)
        cur_w = max_w;
    if (cur_h > max_h)
        cur_h = max_h;

    *(_DWORD*)& byte_5D4594[1045612] = 0;
    *(_DWORD*)& byte_5D4594[1045616] = 0;
    *(_DWORD*)& byte_5D4594[1045620] = 0;
    *(_DWORD*)& byte_5D4594[1045608] = 1;
    *(_DWORD*)& byte_5D4594[1045624] = 0;
    sub_46ACE0(*(_DWORD * *)& byte_5D4594[1045604], 8811, 8826, 1);
    v3 = 0;
    byte_5D4594[1045628] = a1;
    if (a1)
    {
        do
        {
            v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045604], v3 + 8811);
            nox_window_set_hidden((int)v1, 0);
            ++v3;
        } while (v3 < byte_5D4594[1045628]);
    }
    if (byte_5D4594[1045628] <= 4u)
        v4 = cur_w - *(_DWORD*)(*(int*)& byte_5D4594[1045604] + 8) / 2;
    else
        v4 = cur_w - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 8);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 16) = v4 - 91;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 8)
        + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 16);
    LOBYTE(v2) = byte_5D4594[1045628];
    if (byte_5D4594[1045628] <= 8u)
    {
        if (byte_5D4594[1045628] <= 4u)
        {
            if (!v1)
            {
                *(_DWORD*)& byte_5D4594[1045608] = 0;
                return v2;
            }
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 20) = cur_h - 40 * byte_5D4594[1045628];
        }
        else
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 20) = cur_h - *(int*)(*(_DWORD*)& byte_5D4594[1045604] + 12) / 2;
        }
    }
    else
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 20) = cur_h - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 12);
    }
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 28) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 12)
        + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045604] + 20);
    LOBYTE(v2) = sub_46A8C0(*(int*)& byte_5D4594[1045604]);
    return v2;
}

//----- (00455C10) --------------------------------------------------------
int sub_455C10()
{
    *(_DWORD*)& byte_5D4594[1045608] = 0;
    return sub_455A00(0);
}

//----- (00455C30) --------------------------------------------------------
int sub_455C30()
{
    int result; // eax
    int v1; // edi
    wchar_t* v2; // esi
    wchar_t* v3; // eax

    if (*(_DWORD*)& byte_5D4594[1045604])
        return 1;
    result = nox_new_window_from_file("GUI_CTF.wnd", 0);
    *(_DWORD*)& byte_5D4594[1045604] = result;
    if (result)
    {
        v1 = 8811;
        while (1)
        {
            v2 = (wchar_t*)sub_46B0C0((_DWORD*)result, v1);
            nox_window_set_all_funcs(v2, 0, sub_455CD0, 0);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[128372], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 201);
            sub_46B000(v2 + 18, v3);
            if (++v1 > 8826)
                break;
            result = *(_DWORD*)& byte_5D4594[1045604];
        }
        sub_455A00(0);
        *(_DWORD*)& byte_5D4594[1045632] = sub_42F970("FlagTeamBorder");
        result = 1;
    }
    return result;
}

//----- (00455CD0) --------------------------------------------------------
int __cdecl sub_455CD0(_BYTE* a1, _DWORD* a2)
{
    _BYTE* v2; // esi
    int v3; // eax
    _BYTE* v5; // [esp-Ch] [ebp-18h]
    int v6; // [esp+4h] [ebp-8h]
    int v7; // [esp+8h] [ebp-4h]
    unsigned __int8 v8; // [esp+10h] [ebp+4h]

    v2 = a1;
    v5 = a1;
    v8 = *a1 - 107;
    sub_46AA60(v5, &v6, &v7);
    if (byte_5D4594[v8 + 1045612] == 1)
    {
        v3 = a2[8];
        if (v3)
        {
        LABEL_8:
            sub_47D2C0(v3, v6, v7);
            goto LABEL_9;
        }
    }
    else if (byte_5D4594[v8 + 1045612] == 2)
    {
        v3 = a2[12];
        if (v3)
            goto LABEL_8;
    }
    else
    {
        v3 = a2[6];
        if (v3)
            goto LABEL_8;
    }
LABEL_9:
    if (v2[4] & 0x20 && *(_DWORD*)& byte_5D4594[1045632])
        sub_47D2C0(*(int*)& byte_5D4594[1045632], v6 - 4, v7 - 4);
    return 1;
}

//----- (00455D80) --------------------------------------------------------
wchar_t* __cdecl sub_455D80(unsigned __int8 a1, char a2)
{
    wchar_t* result; // eax
    wchar_t* v3; // esi
    wchar_t* v4; // eax

    byte_5D4594[a1 + 1045611] = a2;
    result = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045604], a1 + 8810);
    v3 = result;
    if (result)
    {
        if (result[2] & 0x20)
        {
            if (a2)
            {
                if (a2 == 1)
                {
                    v4 = loadString_sub_40F1D0((char*)& byte_587000[128436], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 234);
                }
                else
                {
                    if (a2 != 2)
                        return result;
                    v4 = loadString_sub_40F1D0((char*)& byte_587000[128492], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 238);
                }
            }
            else
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[128540], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 242);
            }
        }
        else if (a2)
        {
            if (a2 == 1)
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[128588], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 252);
            }
            else
            {
                if (a2 != 2)
                    return result;
                v4 = loadString_sub_40F1D0((char*)& byte_587000[128644], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 256);
            }
        }
        else
        {
            v4 = loadString_sub_40F1D0((char*)& byte_587000[128692], 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 260);
        }
        result = sub_46B000(v3 + 18, v4);
    }
    return result;
}

//----- (00455E70) --------------------------------------------------------
int __cdecl sub_455E70(unsigned __int8 a1)
{
    _DWORD* v2; // eax
    _DWORD* v3; // eax

    for (int i = 0; i < byte_5D4594[1045628]; i++)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045604], i + 8811);
        sub_46AD80((int)v2, 32);
    }
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045604], a1 + 8810);
    return sub_46AD60((int)v3, 32);
}

//----- (00455EE0) --------------------------------------------------------
int sub_455EE0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1045604];
    if (*(_DWORD*)& byte_5D4594[1045604])
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1045604]);
    *(_DWORD*)& byte_5D4594[1045604] = 0;
    *(_DWORD*)& byte_5D4594[1045608] = 0;
    return result;
}

//----- (00455F10) --------------------------------------------------------
int __cdecl sub_455F10(int a1)
{
    int result; // eax

    if (a1 && *(_DWORD*)& byte_5D4594[1045640] && sub_46ADA0(*(int*)& byte_5D4594[1045636]) & 0x10)
        result = sub_46A8C0(*(int*)& byte_5D4594[1045636]);
    else
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1045636], 1);
    return result;
}

//----- (00455F60) --------------------------------------------------------
int sub_455F60()
{
    int result; // eax
    int v1; // ecx
    int v2; // [esp+0h] [ebp-14h]
    int v3; // [esp+4h] [ebp-10h]
    int v4; // [esp+8h] [ebp-Ch]
    int v5; // [esp+Ch] [ebp-8h]
    int v6; // [esp+10h] [ebp-4h]

    sub_418C80(*(int*)& byte_5D4594[2616328]);
    if (*(_DWORD*)& byte_5D4594[1045636] || (result = sub_456070()) != 0)
    {
        sub_43BEB0_get_video_mode(&v3, &v2, &v6);
        sub_430C50_get_video_max(&v4, &v5);
        v1 = v3;
        if (v3 > v4)
        {
            v1 = v4;
            v3 = v4;
        }
        if (v2 > v5)
            v2 = v5;
        *(_DWORD*)& byte_5D4594[1045640] = 1;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 16) = v1 - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 8) / 3 - 91;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 8)
            + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 16);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 20) = v2 - 120;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 28) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 12)
            + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1045636] + 20);
        byte_5D4594[1045644] = 0;
        result = sub_46A8C0(*(int*)& byte_5D4594[1045636]);
    }
    return result;
}

//----- (00456050) --------------------------------------------------------
int sub_456050()
{
    *(_DWORD*)& byte_5D4594[1045640] = 0;
    return sub_455F10(0);
}

//----- (00456070) --------------------------------------------------------
int sub_456070()
{
    if (!*(_DWORD*)& byte_5D4594[1045636])
    {
        *(_DWORD*)& byte_5D4594[1045636] = nox_new_window_from_file("gui_fb.wnd", 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1045636], 0, sub_4560D0, 0);
        if (!*(_DWORD*)& byte_5D4594[1045636])
            return 0;
        sub_455F10(0);
        *(_DWORD*)& byte_5D4594[1045648] = sub_42F970("FlagTeamBorder");
    }
    return 1;
}

//----- (004560D0) --------------------------------------------------------
int __cdecl sub_4560D0(int a1, int a2)
{
    int v2; // eax
    int v4; // [esp+4h] [ebp-8h]
    int v5; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &v4, &v5);
    v2 = *(_DWORD*)(a2 + 24);
    if (v2)
        sub_47D2C0(v2, v4, v5);
    if (*(_BYTE*)(a1 + 4) & 0x20 && *(_DWORD*)& byte_5D4594[1045648])
        sub_47D2C0(*(int*)& byte_5D4594[1045648], v4 - 4, v5 - 4);
    return 1;
}

//----- (00456140) --------------------------------------------------------
wchar_t* __cdecl sub_456140(unsigned __int8 a1)
{
    wchar_t* result; // eax
    int v2; // esi
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax

    byte_5D4594[1045644] = a1;
    result = (wchar_t*)a1;
    v2 = *(_DWORD*)& byte_5D4594[1045636] + 36;
    switch (a1)
    {
    case 0u:
        *(_DWORD*)(v2 + 24) = sub_42F970("BallAtHome");
        v3 = loadString_sub_40F1D0((char*)& byte_587000[128780], 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 165);
        result = sub_46B000((wchar_t*)v2, v3);
        break;
    case 1u:
        *(_DWORD*)(v2 + 24) = sub_42F970("BallAway");
        v4 = loadString_sub_40F1D0((char*)& byte_587000[128840], 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 170);
        result = sub_46B000((wchar_t*)v2, v4);
        break;
    case 2u:
        *(_DWORD*)(v2 + 24) = sub_42F970("BallRed");
        v5 = loadString_sub_40F1D0((char*)& byte_587000[128896], 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 175);
        result = sub_46B000((wchar_t*)v2, v5);
        break;
    case 4u:
        *(_DWORD*)(v2 + 24) = sub_42F970("BallBlue");
        v6 = loadString_sub_40F1D0((char*)& byte_587000[128956], 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 180);
        result = sub_46B000((wchar_t*)v2, v6);
        break;
    default:
        return result;
    }
    return result;
}

//----- (00456240) --------------------------------------------------------
int sub_456240()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1045636];
    if (*(_DWORD*)& byte_5D4594[1045636])
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1045636]);
    *(_DWORD*)& byte_5D4594[1045636] = 0;
    *(_DWORD*)& byte_5D4594[1045640] = 0;
    return result;
}

//----- (00456270) --------------------------------------------------------
int __cdecl sub_456270(int a1)
{
    int v1; // esi
    _DWORD* v3; // edi
    _DWORD* v4; // ebx
    char* v5; // ebp
    _DWORD* v6; // esi
    _DWORD* v7; // edi
    _DWORD* v8; // esi
    _DWORD* v9; // esi
    wchar_t* v10; // eax
    _DWORD* v11; // [esp+4h] [ebp-Ch]
    _DWORD* v12; // [esp+4h] [ebp-Ch]
    char* v13; // [esp+8h] [ebp-8h]
    _DWORD* v14; // [esp+Ch] [ebp-4h]
    _DWORD* v15; // [esp+14h] [ebp+4h]
    _DWORD* v16; // [esp+14h] [ebp+4h]

    v1 = *(_DWORD*)& byte_587000[26048];
    if (sub_43F320(0) > 10)
        v1 = 2;
    if (*(_DWORD*)& byte_5D4594[1045684])
        return 0;
    *(_DWORD*)& byte_5D4594[1045684] = nox_new_window_from_file(*(const char**)& byte_587000[4 * v1 + 129048], sub_4567C0);
    *(_DWORD*)& byte_5D4594[1045688] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10507);
    *(_DWORD*)& byte_5D4594[1045692] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10509);
    sub_46B120(*(_DWORD * *)& byte_5D4594[1045684], a1);
    sub_46B340(*(int*)& byte_5D4594[1045684], sub_456640);
    sub_46A8A0();
    sub_425760(&byte_5D4594[1045652]);
    sub_425760(&byte_5D4594[1045668]);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
    v14 = (_DWORD*)v3[8];
    v13 = sub_42F970("UISlider");
    v5 = sub_42F970("UISliderLit");
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10517);
    v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10515);
    v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10516);
    *(_DWORD*)(v6[100] + 8) = 16;
    *(_DWORD*)(v6[100] + 12) = 10;
    sub_4B5700((int)v6, 0, 0, (int)v13, (int)v5, (int)v5);
    sub_46B280((int)v6, (int)v3);
    sub_46B280((int)v15, (int)v3);
    sub_46B280((int)v11, (int)v3);
    v14[9] = v6;
    v14[7] = v15;
    v14[8] = v11;
    v7 = (_DWORD*)v4[8];
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10520);
    v16 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10518);
    v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10519);
    *(_DWORD*)(v8[100] + 8) = 16;
    *(_DWORD*)(v8[100] + 12) = 10;
    sub_4B5700((int)v8, 0, 0, (int)v13, (int)v5, (int)v5);
    sub_46B280((int)v8, (int)v4);
    sub_46B280((int)v16, (int)v4);
    sub_46B280((int)v12, (int)v4);
    v7[9] = v8;
    v7[7] = v16;
    v7[8] = v12;
    sub_456500();
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10504);
    if (sub_40A5C0(128))
    {
        v10 = loadString_sub_40F1D0((char*)& byte_587000[129280], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 631);
        nox_window_call_field_94((int)v9, 16385, (int)v10, -1);
    }
    return *(_DWORD*)& byte_5D4594[1045684];
}

//----- (00456500) --------------------------------------------------------
int sub_456500()
{
    _DWORD* v0; // ebp
    _DWORD* v1; // ebx
    char* i; // esi
    char* j; // esi
    _DWORD* v4; // edi
    int result; // eax

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
    nox_window_call_field_94((int)v0, 16399, 0, 0);
    nox_window_call_field_94((int)v1, 16399, 0, 0);
    sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
    sub_46ABB0(*(int*)& byte_5D4594[1045692], 0);
    for (i = sub_418B10(); i; i = sub_418B60((int)i))
        sub_457230((wchar_t*)i);
    for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
    {
        if (j[2064] != 31 || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
        {
            sub_457140(*((_DWORD*)j + 515), (wchar_t*)j + 2352);
            v4 = sub_418C80(*((_DWORD*)j + 515));
            if (sub_419130((int)v4))
                sub_4571A0(*((_DWORD*)j + 515), *((unsigned __int8*)v4 + 4));
        }
    }
    if (sub_40A5C0(4096))
    {
        sub_46ABB0((int)v0, 0);
        result = sub_46ABB0((int)v1, 0);
    }
    else
    {
        sub_46ABB0((int)v0, 1);
        result = sub_46ABB0((int)v1, 1);
    }
    return result;
}

//----- (00456640) --------------------------------------------------------
int __cdecl sub_456640(int a1, int a2)
{
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // esi
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_418C80(*(int*)& byte_5D4594[2616328]);
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
    }
    if (sub_40A5C0(1) && !sub_40A5C0(0x8000) && !sub_40A740())
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
        if (nox_window_call_field_94((int)v2, 16404, 0, 0) < 0)
        {
            v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10503);
            sub_46ABB0((int)v6, 0);
        }
        else
        {
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
            v4 = (_DWORD*)nox_window_call_field_94((int)v3, 16404, 0, 0);
            v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10503);
            sub_46ABB0((int)v5, *v4 >= 0);
        }
    }
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
    if (nox_window_call_field_94((int)v7, 16404, 0, 0) < 0)
    {
        sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
        sub_46ABB0(*(int*)& byte_5D4594[1045692], 0);
    }
    return 1;
}

//----- (004567C0) --------------------------------------------------------
int __cdecl sub_4567C0(int a1, int a2, int* a3, int a4)
{
    char* v3; // esi
    int v4; // esi
    _DWORD* v5; // eax
    int v6; // eax
    _DWORD* v7; // eax
    int v8; // ebx
    int* v9; // eax
    int* v10; // ebp
    int i; // eax
    wchar_t* v12; // eax
    char* v13; // eax
    char* v14; // esi
    _DWORD* v15; // eax
    int v16; // edi
    _DWORD* v17; // eax
    _DWORD* v18; // eax
    _DWORD* v20; // eax
    int v21; // eax
    char* v22; // esi
    wchar_t* v23; // edi
    _DWORD* v24; // eax
    int v25; // eax
    char* v26; // eax
    wchar_t* v27; // eax
    wchar_t* v28; // [esp-10h] [ebp-8Ch]
    char* v29; // [esp+8h] [ebp-74h]
    wchar_t v30[56]; // [esp+Ch] [ebp-70h]

    if (a2 != 16391)
    {
        if (a2 != 16400)
            return 0;
        if (sub_46B0A0(a3) == 10502)
        {
            v3 = sub_4165B0();
            if (nox_window_call_field_94((int)a3, 16404, 0, 0) < 0)
            {
                sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
                sub_46ABB0(*(int*)& byte_5D4594[1045692], 0);
            }
            else if (sub_40A5C0(0x8000) || v3[53] < 0)
            {
                sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
                sub_46ABB0(*(int*)& byte_5D4594[1045692], 0);
            }
            else
            {
                if (sub_40A5C0(1))
                    sub_46ABB0(*(int*)& byte_5D4594[1045692], 1);
                if (sub_40A5C0(128) || !*(_DWORD*)& byte_5D4594[1045696])
                    sub_46ABB0(*(int*)& byte_5D4594[1045688], 1);
                else
                    sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
            }
            if (sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
        }
    }
    v4 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    if (v4 > 10507)
    {
        if (v4 == 10509)
        {
            v28 = loadString_sub_40F1D0((char*)& byte_587000[129336], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 504);
            v27 = loadString_sub_40F1D0((char*)& byte_587000[129392], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 504);
            sub_449A10(*(int*)& byte_5D4594[1045684], (int)v27, (int)v28, 163, 0, 0);
        }
        return 0;
    }
    if (v4 == 10507)
    {
        v24 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
        v25 = nox_window_call_field_94((int)v24, 16404, 0, 0);
        sub_456D00(v25, v30);
        v26 = sub_418A40(v30);
        if (v26)
        {
            sub_456BB0((int)v26);
            return 0;
        }
        return 0;
    }
    if (v4 == 4001)
    {
        v20 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
        v21 = nox_window_call_field_94((int)v20, 16404, 0, 0);
        sub_456D00(v21, v30);
        v22 = sub_418A40(v30);
        if (v22)
        {
            v23 = (wchar_t*)sub_449E60(168);
            if (!sub_4190F0(v23))
            {
                sub_418CD0((wchar_t*)v22, v23);
                return 0;
            }
        }
        return 0;
    }
    if (v4 != 10503)
        return 0;
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
    v6 = nox_window_call_field_94((int)v5, 16404, 0, 0);
    if (v6 >= 0)
    {
        sub_456D00(v6, v30);
        v29 = sub_418A40(v30);
        if (v29)
        {
            v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
            v8 = (int)v7;
            v9 = (int*)nox_window_call_field_94((int)v7, 16404, 0, 0);
            v10 = v9;
            for (i = *v9; i >= 0; ++v10)
            {
                v12 = (wchar_t*)nox_window_call_field_94(v8, 16406, i, 0);
                v13 = sub_4170D0(v12);
                v14 = v13;
                if (v13)
                {
                    if (!(v13[3680] & 1) && !(v13[4] & 1))
                    {
                        v15 = sub_418C80(*((_DWORD*)v13 + 515));
                        v16 = (int)v15;
                        if (v15)
                        {
                            if (sub_419130((int)v15))
                                sub_4196D0(v16, (int)v29, *((_DWORD*)v14 + 515), 1);
                            else
                                sub_4191D0(v29[57], v16, 1, *((_DWORD*)v14 + 515), 1);
                        }
                    }
                }
                i = v10[1];
            }
        }
    }
    v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
    nox_window_call_field_94((int)v17, 16403, -1, 0);
    v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
    nox_window_call_field_94((int)v18, 16403, -1, 0);
    return 0;
}

//----- (00456BB0) --------------------------------------------------------
char __cdecl sub_456BB0(int a1)
{
    _DWORD* v1; // eax
    int v2; // esi
    int v3; // edi
    _DWORD* v4; // esi
    float2 v6; // [esp+8h] [ebp-8h]

    LOBYTE(v1) = byte_5D4594[2618908];
    if (!*(_DWORD*)& byte_5D4594[2618908]
        || !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 4) & 1)
        && !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 1))
    {
        v2 = sub_40A5C0(1);
        v1 = sub_418C80(*(int*)& byte_5D4594[2616328]);
        v3 = (int)v1;
        if (v1)
        {
            if (sub_419130((int)v1))
            {
                if (!v2)
                {
                    sub_419960(a1, v3, *(__int16*)& byte_5D4594[2616328]);
                    LOBYTE(v1) = byte_5D4594[1045696] + 1;
                    ++* (_DWORD*)& byte_5D4594[1045696];
                    return (char)v1;
                }
                sub_4196D0(v3, a1, *(int*)& byte_5D4594[2616328], 1);
                v1 = (_DWORD*)sub_40A5C0(128);
                if (!v1)
                {
                    v1 = sub_417040(*(int*)& byte_5D4594[2616328]);
                    v4 = v1;
                    if (v1)
                    {
                        sub_4F7AB0(&v6, v1[514]);
                        sub_4E7010(v4[514], &v6);
                        LOBYTE(v1) = byte_5D4594[1045696] + 1;
                        ++* (_DWORD*)& byte_5D4594[1045696];
                        return (char)v1;
                    }
                }
            }
            else
            {
                if (v2)
                {
                    sub_4191D0(*(_BYTE*)(a1 + 57), v3, v2, *(int*)& byte_5D4594[2616328], 1);
                    LOBYTE(v1) = byte_5D4594[1045696] + 1;
                    ++* (_DWORD*)& byte_5D4594[1045696];
                    return (char)v1;
                }
                LOBYTE(v1) = sub_419900(a1, v3, *(__int16*)& byte_5D4594[2616328]);
            }
            ++* (_DWORD*)& byte_5D4594[1045696];
            return (char)v1;
        }
    }
    return (char)v1;
}

//----- (00456D00) --------------------------------------------------------
wchar_t* __cdecl sub_456D00(int a1, wchar_t* a2)
{
    _DWORD* v2; // eax
    const wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t v6[56]; // [esp+0h] [ebp-70h]

    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
    v3 = (const wchar_t*)nox_window_call_field_94((int)v2, 16406, a1, 0);
    nox_wcscpy(v6, v3);
    v4 = nox_wcstok(v6, L"\t\n\r");
    return nox_wcscpy(a2, v4);
}

//----- (00456D60) --------------------------------------------------------
int* __cdecl sub_456D60(int a1)
{
    int* v1; // esi
    int* v2; // edi
    int* result; // eax
    int* v4; // esi
    int* v5; // edi

    if (a1 && *(_DWORD*)& byte_5D4594[1045684])
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1045684]);
    v1 = sub_425890((int*)& byte_5D4594[1045652]);
    if (v1)
    {
        do
        {
            v2 = sub_4258A0(v1);
            sub_425920((_DWORD * *)v1);
            free(v1);
            v1 = v2;
        } while (v2);
    }
    result = sub_425890((int*)& byte_5D4594[1045668]);
    v4 = result;
    if (result)
    {
        do
        {
            v5 = sub_4258A0(v4);
            sub_425920((_DWORD * *)v4);
            free(v4);
            v4 = v5;
        } while (v5);
    }
    *(_DWORD*)& byte_5D4594[1045684] = 0;
    return result;
}

//----- (00456DF0) --------------------------------------------------------
int __cdecl sub_456DF0(int a1)
{
    int result; // eax
    int v2; // esi
    _DWORD* v3; // eax

    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        result = sub_456E40(a1, 1);
        v2 = result;
        if (result != -1)
        {
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
            result = nox_window_call_field_94((int)v3, 16398, v2, 0);
        }
    }
    return result;
}

//----- (00456E40) --------------------------------------------------------
int __cdecl sub_456E40(int a1, int a2)
{
    int* v2; // esi
    int v3; // edi

    v2 = sub_425890((int*)& byte_5D4594[1045652]);
    v3 = 0;
    if (!v2)
        return -1;
    while (v2[15] != a1)
    {
        v2 = sub_4258A0(v2);
        ++v3;
        if (!v2)
            return -1;
    }
    if (a2)
    {
        sub_425920((_DWORD * *)v2);
        free(v2);
    }
    return v3;
}

//----- (00456EA0) --------------------------------------------------------
int __cdecl sub_456EA0(wchar_t* a1)
{
    int result; // eax
    _DWORD* v2; // edi
    int v3; // eax
    int v4; // esi

    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
        v3 = sub_456F10(a1, 1);
        v4 = v3;
        if (v3 != -1)
        {
            sub_4258C0((_DWORD * *)& byte_5D4594[1045668], v3);
            nox_window_call_field_94((int)v2, 16404, 0, 0);
            nox_window_call_field_94((int)v2, 16398, v4, 0);
        }
        result = sub_456500();
    }
    return result;
}

//----- (00456F10) --------------------------------------------------------
int __cdecl sub_456F10(wchar_t* a1, int a2)
{
    int* v2; // esi
    int v3; // ebx
    wchar_t* v4; // eax
    wchar_t v6[56]; // [esp+Ch] [ebp-70h]

    v2 = sub_425890((int*)& byte_5D4594[1045668]);
    v3 = 0;
    if (!v2)
        return -1;
    while (1)
    {
        nox_wcscpy(v6, (const wchar_t*)v2 + 6);
        v4 = nox_wcstok(v6, L" \t\n\r");
        if (!_nox_wcsicmp(v4, a1))
            break;
        v2 = sub_4258A0(v2);
        ++v3;
        if (!v2)
            return -1;
    }
    if (a2)
    {
        sub_425920((_DWORD * *)v2);
        free(v2);
    }
    return v3;
}

//----- (00456FA0) --------------------------------------------------------
int sub_456FA0()
{
    int result; // eax
    int* v1; // esi
    int* v2; // edi

    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        v1 = sub_425890((int*)& byte_5D4594[1045668]);
        if (v1)
        {
            do
            {
                v2 = sub_4258A0(v1);
                sub_425920((_DWORD * *)v1);
                free(v1);
                v1 = v2;
            } while (v2);
        }
        sub_46ABB0(*(int*)& byte_5D4594[1045688], 0);
        sub_46ABB0(*(int*)& byte_5D4594[1045692], 0);
        result = sub_456500();
    }
    return result;
}

//----- (00457010) --------------------------------------------------------
int __cdecl sub_457010(int a1, wchar_t* a2)
{
    char* v2; // ebp
    int result; // eax
    _DWORD* v4; // esi
    int v5; // edi
    unsigned __int8 v6; // al
    unsigned __int8 v7; // al
    wchar_t* v8; // [esp-20h] [ebp-94h]
    wchar_t v9[56]; // [esp+4h] [ebp-70h]

    v2 = sub_4165B0();
    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
        v5 = nox_window_call_field_94((int)v4, 16404, 0, 0);
        nox_wcscpy(v9, a2);
        if (sub_40A5C0(96) || v2[52] & 0x60)
        {
            v6 = *(_BYTE*)(a1 + 57);
            if (v6 < 3u)
            {
                if (v6 == 1)
                    v8 = loadString_sub_40F1D0((char*)& byte_587000[129468], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 778);
                else
                    v8 = loadString_sub_40F1D0((char*)& byte_587000[129524], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 782);
                nox_wcscat(v9, v8);
            }
        }
        nox_window_call_field_94((int)v4, 16398, v5, 0);
        nox_window_call_field_94((int)v4, 16402, v5, 0);
        v7 = sub_457120(a1);
        nox_window_call_field_94((int)v4, 16397, (int)v9, v7);
        result = nox_window_call_field_94((int)v4, 16403, v5, 0);
    }
    return result;
}

//----- (00457120) --------------------------------------------------------
unsigned __int8 __cdecl sub_457120(int a1)
{
    return byte_587000[8 * (*(unsigned __int8*)(a1 + 56) % 10) + 128968];
}

//----- (00457140) --------------------------------------------------------
int __cdecl sub_457140(int a1, wchar_t* a2)
{
    int result; // eax
    wchar_t* v3; // esi
    _DWORD* v4; // eax

    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        v3 = (wchar_t*)nox_malloc(0x48u);
        sub_425770(v3);
        sub_4258E0((int)& byte_5D4594[1045652], v3);
        nox_wcscpy(v3 + 6, a2);
        *((_DWORD*)v3 + 15) = a1;
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501);
        result = nox_window_call_field_94((int)v4, 16397, (int)a2, 3);
    }
    return result;
}

//----- (004571A0) --------------------------------------------------------
int __cdecl sub_4571A0(int a1, int a2)
{
    int result; // eax
    int v3; // ebp
    int v4; // esi
    int v5; // edi
    int* i; // eax

    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10501)[8];
        result = sub_456E40(a1, 0);
        v4 = result;
        if (result != -1)
        {
            v5 = 3;
            if (a2)
            {
                for (i = sub_425890((int*)& byte_5D4594[1045668]); i; i = sub_4258A0(i))
                {
                    if (i[15] == a2)
                        v5 = *((unsigned __int8*)i + 64);
                }
            }
            result = *(_DWORD*)(v3 + 24);
            *(_DWORD*)(result + 524 * v4 + 516) = **(_DWORD * *)& byte_5D4594[4 * v5 + 2649836];
        }
    }
    return result;
}

//----- (00457230) --------------------------------------------------------
char* __cdecl sub_457230(wchar_t* a1)
{
    char* v1; // ebp
    char* result; // eax
    _DWORD* v3; // esi
    char* v4; // edi
    char v5; // al
    _DWORD* v6; // eax
    wchar_t* v7; // [esp-14h] [ebp-94h]
    wchar_t v8[56]; // [esp+10h] [ebp-70h]

    v1 = sub_4165B0();
    result = *(char**)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
    {
        v3 = nox_malloc(0x48u);
        result = sub_418A40(a1);
        v4 = result;
        if (result)
        {
            v3[15] = (unsigned __int8)result[57];
            v3[17] = (unsigned __int8)result[56];
            *((_BYTE*)v3 + 64) = sub_457120((int)result);
            sub_425770(v3);
            sub_4258E0((int)& byte_5D4594[1045668], v3);
            nox_wcscpy((wchar_t*)v3 + 6, a1);
            nox_wcscpy(v8, a1);
            if (sub_40A5C0(96) || v1[52] & 0x60)
            {
                v5 = v4[57];
                if ((unsigned __int8)v5 < 3u)
                {
                    if (v5 == 1)
                        v7 = loadString_sub_40F1D0((char*)& byte_587000[129584], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 893);
                    else
                        v7 = loadString_sub_40F1D0((char*)& byte_587000[129640], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\playrlst.c", 897);
                    nox_wcscat(v8, v7);
                }
            }
            v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1045684], 10502);
            result = (char*)nox_window_call_field_94((int)v6, 16397, (int)v8, *((unsigned __int8*)v3 + 64));
        }
    }
    return result;
}

//----- (00457350) --------------------------------------------------------
int* __cdecl sub_457350(unsigned __int8 a1, unsigned __int8 a2)
{
    int* result; // eax

    for (result = sub_425890((int*)& byte_5D4594[1045668]); result; result = sub_4258A0(result))
    {
        if (result[15] == a1)
            result[15] = a2;
    }
    return result;
}

//----- (004573A0) --------------------------------------------------------
int sub_4573A0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1045684];
    if (*(_DWORD*)& byte_5D4594[1045684])
        result = sub_456500();
    return result;
}

//----- (004573B0) --------------------------------------------------------
void sub_4573B0()
{
    *(_DWORD*)& byte_5D4594[1045696] = 0;
}

//----- (004573C0) --------------------------------------------------------
int __cdecl sub_4573C0(__int16 a1)
{
    int v1; // ecx
    unsigned __int8* i; // eax
    int v3; // esi

    if (!*(_DWORD*)& byte_5D4594[1046548])
        sub_457410();
    v1 = 0;
    if (!*(_DWORD*)& byte_587000[129668])
        return *(_DWORD*)& byte_587000[129680];
    for (i = &byte_587000[129668]; (a1 & 0x17F0) != *((_DWORD*)i + 1); i += 12)
    {
        v3 = *((_DWORD*)i + 3);
        ++v1;
        if (!v3)
            return *(_DWORD*)& byte_587000[129680];
    }
    return *(_DWORD*)& byte_587000[12 * v1 + 129668];
}

//----- (00457410) --------------------------------------------------------
char* sub_457410()
{
    char* result; // eax
    unsigned __int8* v1; // esi

    result = *(char**)& byte_5D4594[1046548];
    if (!*(_DWORD*)& byte_5D4594[1046548])
    {
        result = *(char**)& byte_587000[129664];
        if (*(_DWORD*)& byte_587000[129664])
        {
            v1 = &byte_587000[129664];
            do
            {
                *((_DWORD*)v1 + 1) = loadString_sub_40F1D0(result, 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 212);
                result = (char*) * ((_DWORD*)v1 + 3);
                v1 += 12;
            } while (result);
        }
        *(_DWORD*)& byte_5D4594[1046548] = 1;
    }
    return result;
}

//----- (00457460) --------------------------------------------------------
int __cdecl sub_457460(int a1)
{
    WCHAR WideCharStr[16]; // [esp+4h] [ebp-20h]

    _itow(*(unsigned __int16*)(a1 + 54), WideCharStr, 10);
    nox_window_call_field_94(*(int*)& byte_5D4594[1046516], 16414, (int)WideCharStr, 0);
    _itow(*(unsigned __int8*)(a1 + 56), WideCharStr, 10);
    return nox_window_call_field_94(*(int*)& byte_5D4594[1046520], 16414, (int)WideCharStr, 0);
}

//----- (004574D0) --------------------------------------------------------
int sub_4574D0()
{
    if (!*(_DWORD*)& byte_5D4594[1046492])
        return 0;
    sub_4597E0(0);
    *(_DWORD*)& byte_5D4594[1046492] = 0;
    return 1;
}

//----- (00457500) --------------------------------------------------------
int sub_457500()
{
    int v1; // esi
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // edi
    char* v5; // ebx
    _DWORD* v6; // esi
    _DWORD* v7; // ebp
    _DWORD* v8; // eax
    char* v9; // esi
    wchar_t* v10; // esi
    wchar_t* v11; // eax
    wchar_t* v12; // eax
    _DWORD* v13; // eax
    char* v14; // [esp+0h] [ebp-8h]
    _DWORD* v15; // [esp+4h] [ebp-4h]

    if (!sub_446360())
    {
        if (*(_DWORD*)& byte_5D4594[1046492])
        {
            sub_452D80(231, 100);
            sub_4574D0();
            return 1;
        }
        if (sub_40A5C0(1))
        {
            sub_459D50(1);
            if (*(_DWORD*)& byte_587000[129656])
                sub_425760(&byte_5D4594[1045956]);
        }
        v1 = *(_DWORD*)& byte_587000[26048];
        if (sub_43F320(0) > 10)
            v1 = 2;
        *(_DWORD*)& byte_5D4594[1046492] = nox_new_window_from_file(*(const char**)& byte_587000[4 * v1 + 129760], sub_4585D0);
        sub_43FE20(100);
        sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1046492],
            nox_win_width - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1046492] + 8) - 10,
            0);
        sub_46B300(*(int*)& byte_5D4594[1046492], sub_458590);
        sub_46B340(*(int*)& byte_5D4594[1046492], sub_458500);
        *(_DWORD*)& byte_5D4594[1046512] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10101);
        *(_DWORD*)& byte_5D4594[1046496] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10114);
        *(_DWORD*)& byte_5D4594[1046500] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10183);
        *(_DWORD*)& byte_5D4594[1046504] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10197);
        *(_DWORD*)& byte_5D4594[1046508] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10199);
        *(_DWORD*)& byte_5D4594[1046524] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10150);
        *(_DWORD*)& byte_5D4594[1046516] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10134);
        *(_DWORD*)& byte_5D4594[1046520] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10135);
        *(_DWORD*)& byte_5D4594[1046536] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10153);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10331);
        sub_46B070((int)v2, sub_457AA0);
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10333);
        sub_46B070((int)v3, sub_457B00);
        sub_46B280(*(int*)& byte_5D4594[1046524], *(int*)& byte_5D4594[1046492]);
        sub_46B280(*(int*)& byte_5D4594[1046532], *(int*)& byte_5D4594[1046492]);
        sub_46B280(*(int*)& byte_5D4594[1046536], *(int*)& byte_5D4594[1046492]);
        sub_46B280(*(int*)& byte_5D4594[1046500], *(int*)& byte_5D4594[1046492]);
        sub_46B280(*(int*)& byte_5D4594[1046504], *(int*)& byte_5D4594[1046492]);
        sub_46B280(*(int*)& byte_5D4594[1046508], *(int*)& byte_5D4594[1046492]);
        sub_46B2C0(*(int*)& byte_5D4594[1046524], sub_4585D0);
        sub_46B2C0(*(int*)& byte_5D4594[1046532], sub_4585D0);
        sub_46B2C0(*(int*)& byte_5D4594[1046536], sub_4585D0);
        sub_46B2C0(*(int*)& byte_5D4594[1046500], sub_4585D0);
        sub_46B2C0(*(int*)& byte_5D4594[1046504], sub_4585D0);
        sub_46B2C0(*(int*)& byte_5D4594[1046508], sub_4585D0);
        *(_DWORD*)& byte_5D4594[1046352] = sub_42F970("UITabs1");
        *(_DWORD*)& byte_5D4594[1046356] = sub_42F970("UITabs2");
        *(_DWORD*)& byte_5D4594[1046360] = sub_42F970("UITabs3");
        v4 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046496] + 32);
        v14 = sub_42F970("UISlider");
        v5 = sub_42F970("UISliderLit");
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046500], 10182);
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046500], 10180);
        v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046500], 10181);
        *(_DWORD*)(v6[100] + 8) = 16;
        *(_DWORD*)(v6[100] + 12) = 10;
        sub_4B5700((int)v6, 0, 0, (int)v14, (int)v5, (int)v5);
        sub_46B280((int)v6, *(int*)& byte_5D4594[1046496]);
        sub_46B280((int)v7, *(int*)& byte_5D4594[1046496]);
        sub_46B280((int)v15, *(int*)& byte_5D4594[1046496]);
        v4[9] = v6;
        v4[7] = v7;
        v4[8] = v15;
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10160);
        v8[9] |= 4u;
        v9 = sub_4165D0(0);
        if (sub_40A5C0(1))
            sub_4161E0();
        sub_457410();
        sub_457B60((int)v9);
        sub_457A10();
        if (sub_40A5C0(1))
        {
            sub_4165F0(0, 1);
            sub_4165D0(1);
        }
        else
        {
            v10 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10159);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[130156], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1811);
            nox_window_call_field_94((int)v10, 16385, (int)v11, -1);
            v12 = loadString_sub_40F1D0((char*)& byte_587000[130224], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1812);
            sub_46B000(v10 + 18, v12);
            v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10149);
            nox_window_set_hidden((int)v13, 0);
            nox_window_set_hidden(*(int*)& byte_5D4594[1046508], 1);
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10145, 10146, 1);
        }
        if (*(_DWORD*)& byte_587000[129656])
        {
            if (sub_4D6F30() || sub_4D6F50())
            {
                sub_443C80((wchar_t*)& byte_587000[130244], 1);
            }
            else if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
            {
                sub_443C80((wchar_t*)& byte_587000[130284], 1);
            }
        }
        *(_DWORD*)& byte_587000[129656] = 0;
    }
    return 1;
}

//----- (00457A10) --------------------------------------------------------
char* sub_457A10()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi
    int v2; // edi
    int v3; // eax
    char* result; // eax
    unsigned __int8* v5; // ebx
    int v6; // edi
    int v7; // edx
    int v8; // [esp+8h] [ebp-4h]

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10120);
    v1 = v0;
    v2 = 0;
    v3 = 6 * (sub_43F320(v0[59]) + 1);
    v1[7] = v1[5] + v3 + 2;
    v1[3] = v3 + 2;
    result = *(char**)& byte_587000[129664];
    if (*(_DWORD*)& byte_587000[129664])
    {
        v5 = &byte_587000[129664];
        do
        {
            sub_43F840(v1[59], *((unsigned __int16**)v5 + 1), &v8, 0, 0);
            if (v8 > v2)
                v2 = v8;
            result = (char*) * ((_DWORD*)v5 + 3);
            v5 += 12;
        } while (result);
    }
    v6 = v2 + 7;
    v7 = v1[6] - v6;
    v1[2] = v6;
    v1[4] = v7;
    return result;
}

//----- (00457AA0) --------------------------------------------------------
int __cdecl sub_457AA0(int a1, _BYTE* a2)
{
    wchar_t* v2; // eax

    if (*a2 & 4)
        v2 = loadString_sub_40F1D0((char*)& byte_587000[130372], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 446);
    else
        v2 = loadString_sub_40F1D0((char*)& byte_587000[130436], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 450);
    sub_4776B0(v2);
    return 1;
}

//----- (00457B00) --------------------------------------------------------
int __cdecl sub_457B00(int a1, _BYTE* a2)
{
    wchar_t* v2; // eax

    if (*a2 & 4)
        v2 = loadString_sub_40F1D0((char*)& byte_587000[130500], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 465);
    else
        v2 = loadString_sub_40F1D0((char*)& byte_587000[130564], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 469);
    sub_4776B0(v2);
    return 1;
}

//----- (00457B60) --------------------------------------------------------
int __cdecl sub_457B60(int a1)
{
    char* v1; // eax
    _DWORD* v2; // eax
    char* v3; // eax
    unsigned __int16 v4; // di
    char* v5; // esi
    _DWORD* v6; // eax
    unsigned __int16 v7; // ax
    unsigned __int8 v8; // al
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // edi
    int v12; // eax
    _DWORD* v13; // edi
    int v14; // eax
    _DWORD* v15; // edi
    int v16; // eax
    unsigned int v17; // ecx
    WCHAR WideCharStr[16]; // [esp+0h] [ebp-E8h]
    wchar_t v20[100]; // [esp+20h] [ebp-C8h]

    sub_416640();
    v1 = sub_40A4C0();
    nox_swprintf(v20, L"%S", v1);
    nox_window_call_field_94(*(int*)& byte_5D4594[1046512], 16414, (int)v20, 0);
    sub_459CD0();
    if (sub_40A5C0(128))
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10122);
    else
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10119);
    nox_window_set_hidden((int)v2, 1);
    if (sub_40A5C0(1))
    {
        sub_46ABB0(*(int*)& byte_5D4594[1046508], 1);
        if (sub_40A5C0(128))
        {
            v3 = sub_416590(1);
            v4 = *((_WORD*)v3 + 26) & 0x17F0;
            sub_458230(v4, v3, 1);
            v5 = sub_4165B0();
            *((_WORD*)v5 + 26) = v4 | *((_WORD*)v5 + 26) & 0xE80F;
            if (sub_40A740())
            {
                sub_46ABB0(*(int*)& byte_5D4594[1046508], 0);
            }
            else if (sub_417DA0(4))
            {
                v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046508], 10330);
                v6[9] |= 4u;
            }
            else
            {
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1046508], 10331, 10333, 0);
            }
        }
        else
        {
            if (sub_417DA0(4))
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1046508], 10330, 10331, 0);
            else
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1046508], 10330, 10333, 0);
            v5 = (char*)a1;
            sub_458230(*(unsigned __int16*)(a1 + 52), (char*)a1, 0);
        }
        v7 = sub_40A020(*((_WORD*)v5 + 26));
        _itow(v7, WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1046516], 16414, (int)WideCharStr, 0);
        v8 = sub_40A180(*((_WORD*)v5 + 26));
        _itow(v8, WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1046520], 16414, (int)WideCharStr, 0);
        sub_4580E0((int)v5);
    }
    else
    {
        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10161);
        sub_46ABB0((int)v9, 0);
        sub_46ABB0(*(int*)& byte_5D4594[1046536], 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1046536] + 4) |= 8u;
        sub_46ABB0(*(int*)& byte_5D4594[1046504], 1);
        sub_46AD20(*(_DWORD * *)& byte_5D4594[1046504], 10134, 10135, 0);
        sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10141, 10141, 1);
        v5 = (char*)a1;
        sub_458230(*(unsigned __int16*)(a1 + 52), (char*)a1, 0);
        _itow(*(unsigned __int16*)(a1 + 54), WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1046516], 16414, (int)WideCharStr, 0);
        _itow(*(unsigned __int8*)(a1 + 56), WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[1046520], 16414, (int)WideCharStr, 0);
        if (sub_43AF70() == 1)
        {
            v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10210);
            nox_window_set_hidden((int)v10, 0);
            sub_457FE0();
        }
    }
    v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046508], 10331);
    if (sub_417DA0(2))
    {
        v12 = v11[9];
        LOBYTE(v12) = v12 | 4;
        v11[9] = v12;
    }
    v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046508], 10333);
    if (sub_417DA0(1))
    {
        v14 = v13[9];
        LOBYTE(v14) = v14 | 4;
        v13[9] = v14;
    }
    v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10119);
    v16 = sub_4573C0(*((_WORD*)v5 + 26));
    nox_window_call_field_94((int)v15, 16385, v16, 0);
    sub_459880((int)v5);
    LOWORD(v17) = *((_WORD*)v5 + 26);
    return sub_457F30((v17 >> 12) & 1);
}
// 457F15: variable 'v17' is possibly undefined

//----- (00457F30) --------------------------------------------------------
int __cdecl sub_457F30(int a1)
{
    int v1; // esi
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // esi
    _DWORD* v5; // eax

    v1 = a1 != 1;
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046504], 10152);
    sub_46ABB0((int)v2, v1);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046504], 10141);
    sub_46ABB0((int)v3, v1);
    sub_46ABB0(*(int*)& byte_5D4594[1046516], v1);
    sub_46ABB0(*(int*)& byte_5D4594[1046520], v1);
    if (a1 == 1)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10122);
        if (!wndIsShown_sub_46ACC0((int)v4))
            nox_window_set_hidden((int)v4, 1);
    }
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10183);
    return nox_window_set_hidden((int)v5, a1);
}

//----- (00457FE0) --------------------------------------------------------
int sub_457FE0()
{
    _DWORD* v0; // esi
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-8h]
    wchar_t* v6; // [esp-4h] [ebp-8h]

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10210);
    if (sub_40A5C0(0x4000))
    {
        v5 = loadString_sub_40F1D0((char*)& byte_587000[130636], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 380);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[130708], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 379);
        nox_swprintf((wchar_t*)& byte_5D4594[1045700], L"%s %s", v1, v5);
    }
    else if (sub_40A5C0(0x8000))
    {
        v6 = loadString_sub_40F1D0((char*)& byte_587000[130788], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 385);
        v2 = loadString_sub_40F1D0((char*)& byte_587000[130856], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 384);
        nox_swprintf((wchar_t*)& byte_5D4594[1045700], L"%s %s", v2, v6);
    }
    else
    {
        v3 = loadString_sub_40F1D0((char*)& byte_587000[130936], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 389);
        nox_swprintf((wchar_t*)& byte_5D4594[1045700], v3);
    }
    return nox_window_call_field_94((int)v0, 16385, (int)& byte_5D4594[1045700], -1);
}

//----- (004580E0) --------------------------------------------------------
int __cdecl sub_4580E0(int a1)
{
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    __int16 v3; // ax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    int v10; // [esp-4h] [ebp-4h]

    v1 = loadString_sub_40F1D0((char*)& byte_587000[131000], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 736);
    nox_swprintf((wchar_t*)& byte_5D4594[1045968], v1, a1);
    if (sub_40A5C0(128))
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[131060], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 739);
        nox_swprintf((wchar_t*)& byte_5D4594[1046096], v2);
    }
    else
    {
        v3 = sub_40A5B0();
        v10 = sub_4573C0(v3);
        v4 = loadString_sub_40F1D0((char*)& byte_587000[131120], 0, (const char*)& byte_587000[0x20000], 743);
        nox_swprintf((wchar_t*)& byte_5D4594[1046096], v4, v10);
    }
    if (sub_40A5C0(1))
        v5 = loadString_sub_40F1D0((char*)& byte_587000[131180], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 748);
    else
        v5 = loadString_sub_40F1D0((char*)& byte_587000[131240], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 752);
    nox_swprintf((wchar_t*)& byte_5D4594[1046224], v5);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10121);
    nox_window_call_field_94((int)v6, 16385, (int)& byte_5D4594[1045968], -1);
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10118);
    nox_window_call_field_94((int)v7, 16385, (int)& byte_5D4594[1046096], -1);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10117);
    return nox_window_call_field_94((int)v8, 16385, (int)& byte_5D4594[1046224], -1);
}

//----- (00458230) --------------------------------------------------------
int __cdecl sub_458230(int a1, char* a2, int a3)
{
    int v3; // ebp
    int* v4; // ebx
    int v5; // eax
    int v6; // esi
    int i; // eax
    int j; // eax
    wchar_t* v9; // eax
    int result; // eax
    char* v11; // ebx
    int v12; // eax
    int v13; // eax
    char* v14; // eax
    int v15; // [esp-8h] [ebp-160h]
    int v16; // [esp-4h] [ebp-15Ch]
    int v17; // [esp+10h] [ebp-148h]
    int v18; // [esp+14h] [ebp-144h]
    char v19[58]; // [esp+18h] [ebp-140h]
    char v20[58]; // [esp+54h] [ebp-104h]
    wchar_t v21[100]; // [esp+90h] [ebp-C8h]

    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16399, 0, 0);
    v3 = a1;
    v18 = -1;
    *(_DWORD*)& byte_5D4594[1046552] = a1;
    v4 = sub_4D09B0();
    v17 = 0;
    if (!v4)
        goto LABEL_30;
    do
    {
        if (v4[6])
        {
            v5 = sub_4CFFC0((int)v4);
            if (v5 & v3)
            {
                strcpy(v19, (const char*)v4 + 12);
                qmemcpy(v20, v19, 0x38u);
                *(_WORD*)& v20[56] = *(_WORD*)& v19[56];
                sub_57A1E0((int*)v19, 0, 0, 1, a1);
                sub_57A1E0((int*)v20, "user.rul", 0, 3, a1);
                v6 = -1;
                for (i = 0; i < 20; i += 4)
                {
                    if (*(_DWORD*)& v19[i + 24] != *(_DWORD*)& v20[i + 24])
                        v6 = 6;
                }
                if (v6 == -1)
                {
                    for (j = 0; j < 4; ++j)
                    {
                        if (v19[j + 44] != v20[j + 44])
                            v6 = 6;
                    }
                    if (v6 == -1 && *(_DWORD*)& v19[48] != *(_DWORD*)& v20[48])
                        v6 = 6;
                }
                v16 = *((unsigned __int8*)v4 + 33);
                v15 = *((unsigned __int8*)v4 + 32);
                v9 = loadString_sub_40F1D0((char*)& byte_587000[131312], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 823);
                nox_swprintf(v21, v9, v4 + 3, v15, v16);
                nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16397, (int)v21, v6);
                if (!_strcmpi(a2, (const char*)v4 + 12))
                {
                    v18 = v17;
                    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16403, v17, 0);
                    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16412, v17, 0);
                }
                v3 = a1;
                ++v17;
            }
        }
        v4 = sub_4D09C0(v4);
    } while (v4);
    if (v18 < 0)
    {
    LABEL_30:
        nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16403, 0, 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16412, 0, 0);
    }
    result = a3;
    if (a3)
    {
        v11 = sub_4165B0();
        v12 = nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16404, 0, 0);
        if (v12 >= 0
            && (v13 = nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16406, v12, 0),
                nox_sprintf((char*)v21, "%S", v13),
                (v14 = strtok((char*)v21, "\t")) != 0))
        {
            strcpy(v11, v14);
        }
        else
        {
            *v11 = 0;
        }
        sub_57A1E0((int*)v11, "user.rul", 0, 7, v3);
        result = sub_459880((int)v11);
    }
    return result;
}
// 458291: variable 'v5' is possibly undefined

//----- (00458500) --------------------------------------------------------
int __cdecl sub_458500(_DWORD* a1, int a2)
{
    int2* v1; // edi
    _DWORD* v2; // esi
    int xLeft; // [esp+8h] [ebp-8h]
    int v5; // [esp+Ch] [ebp-4h]

    v1 = sub_4309F0();
    sub_46AA60(a1, &xLeft, &v5);
    sub_49CF10(xLeft, v5 + 25, a1[2], a1[3] - 25);
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10120);
    if (!wndIsShown_sub_46ACC0((int)v2) && !sub_46AAB0(v2, v1->field_0, v1->field_4))
    {
        sub_46ADE0((int)v2);
        nox_window_set_hidden((int)v2, 1);
    }
    return 1;
}

//----- (00458590) --------------------------------------------------------
int __cdecl sub_458590(int a1, int a2, int a3, int a4)
{
    if (a2 == 21)
    {
        if (a3 != 1)
            return 0;
        if (a4 == 2)
        {
            sub_452D80(231, 100);
            sub_4597E0(0);
        }
    }
    return 1;
}

//----- (004585D0) --------------------------------------------------------
int __cdecl sub_4585D0(int a1, unsigned int a2, int a3, int a4)
{
    _DWORD* v4; // esi
    char* v5; // ebp
    int result; // eax
    int v7; // eax
    int v8; // ebx
    int v9; // edi
    int* v10; // eax
    int v11; // edi
    _DWORD* v12; // esi
    _DWORD* v13; // eax
    _DWORD* v14; // eax
    _DWORD* v15; // eax
    int v16; // edi
    _DWORD* v17; // eax
    char* v18; // esi
    int v19; // edi
    __int16 v20; // ax
    bool v21; // cc
    wchar_t* v22; // eax
    wchar_t* v23; // eax
    wchar_t* v24; // eax
    char* v25; // esi
    _DWORD* v26; // esi
    int v27; // edi
    int v28; // eax
    char* v29; // esi
    _DWORD* v30; // edi
    int v31; // eax
    wchar_t* v32; // ebp
    int v33; // edi
    unsigned int v34; // ecx
    int v35; // eax
    char* v36; // edi
    char* v37; // ebx
    wchar_t* v38; // [esp-10h] [ebp-F0h]
    wchar_t* v39; // [esp-10h] [ebp-F0h]
    WCHAR WideCharStr[4]; // [esp+10h] [ebp-D0h]
    char v41[100]; // [esp+18h] [ebp-C8h]
    char v42[100]; // [esp+7Ch] [ebp-64h]

    if (a2 > 0x4007)
    {
        if (a2 == 16400)
        {
            v28 = sub_46B0A0((int*)a3) - 10114;
            if (v28)
            {
                if (v28 == 6)
                {
                    v29 = sub_4165B0();
                    v30 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10119);
                    v31 = nox_window_call_field_94(a3, 16404, 0, 0);
                    if (v31 >= 0 && v31 < *(__int16*)(*(_DWORD*)(a3 + 32) + 44))
                    {
                        v32 = (wchar_t*)nox_window_call_field_94(a3, 16406, a4, 0);
                        nox_window_call_field_94((int)v30, 16385, (int)v32, -1);
                        v33 = *((_WORD*)v29 + 26) & 0x17F0;
                        *((_WORD*)v29 + 26) &= 0xE80Fu;
                        *((_WORD*)v29 + 26) |= sub_459650(v32);
                        if (v33 != (*((_WORD*)v29 + 26) & 0x17F0))
                            sub_458230(*((unsigned __int16*)v29 + 26), (char*)& byte_5D4594[1046556], 1);
                        nox_window_set_hidden(a3, 1);
                        sub_46ADE0(a3);
                        *((_WORD*)v29 + 27) = sub_40A020(*((_WORD*)v29 + 26));
                        v29[56] = sub_40A180(*((_WORD*)v29 + 26));
                        sub_457460((int)v29);
                        sub_459D50(1);
                        if (v29[53] & 0x10)
                        {
                            sub_424BD0();
                            sub_4537F0();
                            sub_459700();
                        }
                        LOWORD(v34) = *((_WORD*)v29 + 26);
                        sub_457F30((v34 >> 12) & 1);
                        return 1;
                    }
                }
            }
            else if (nox_window_call_field_94(a3, 16404, 0, 0) >= 0)
            {
                v35 = nox_window_call_field_94(a3, 16406, a4, 0);
                nox_sprintf(v42, "%S", v35);
                v36 = strtok(v42, "\t");
                v37 = sub_4165B0();
                strcpy(v37, v36);
                sub_57A1E0((int*)v37, "user.rul", 0, 7, *((_WORD*)v37 + 26));
                sub_459880((int)v37);
                sub_459D50(1);
            }
        }
        return 1;
    }
    if (a2 == 16391)
    {
        v9 = sub_46B0A0((int*)a3);
        sub_452D80(766, 100);
        switch (v9)
        {
        case 10119:
            v26 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10120);
            nox_window_set_hidden((int)v26, 0);
            sub_46ADC0((int)v26);
            sub_46A8C0((int)v26);
            sub_4596A0();
            return 1;
        case 10122:
            v27 = (*(_BYTE*)(a3 + 36) & 4) != 0;
            if (!sub_40A5C0(49152))
            {
                sub_46ABB0(*(int*)& byte_5D4594[1046500], v27);
                sub_46ABB0(*(int*)& byte_5D4594[1046504], v27);
            }
            sub_459D50(1);
            return 1;
        case 10141:
            sub_459700();
            return 1;
        case 10145:
            v18 = sub_416590(1);
            sub_459AA0((int)v18);
            sub_4165F0(1, 0);
            v19 = sub_417DD0();
            if (sub_40A5C0(128) && (v20 = *((_WORD*)v18 + 26), v20 & 0x60))
            {
                if (v20 < 0)
                {
                    v21 = v19 <= 2;
                }
                else
                {
                    v21 = v19 <= 2;
                    if (v19 < 2)
                    {
                        v22 = loadString_sub_40F1D0((char*)& byte_587000[131412], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1363);
                        sub_449A10(
                            *(int*)& byte_5D4594[1046492],
                            (int)& byte_5D4594[1046560],
                            (int)v22,
                            56,
                            (int (*)(void))sub_459150,
                            0);
                        sub_44A360(1);
                        return 1;
                    }
                }
                if (!v21)
                {
                    v38 = loadString_sub_40F1D0((char*)& byte_587000[131472], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1371);
                    v23 = loadString_sub_40F1D0((char*)& byte_587000[131536], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1370);
                    sub_449A10(*(int*)& byte_5D4594[1046492], (int)v23, (int)v38, 33, 0, 0);
                    sub_44A360(1);
                    return 1;
                }
            }
            else if (sub_40A5C0(128) && sub_40A5C0(16) && sub_417DA0(4) && v19 > 2)
            {
                v39 = loadString_sub_40F1D0((char*)& byte_587000[131592], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1384);
                v24 = loadString_sub_40F1D0((char*)& byte_587000[131656], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1383);
                sub_449A10(*(int*)& byte_5D4594[1046492], (int)v24, (int)v39, 33, 0, 0);
                sub_44A360(1);
                return 1;
            }
            sub_459150();
            OnLibraryNotice(261, 0);
            result = 1;
            break;
        case 10146:
            v25 = sub_4165B0();
            if (sub_40A5C0(128))
            {
                if ((int)v25[53] < 0)
                    sub_419030(1);
                *((_WORD*)v25 + 26) &= 0x3FFFu;
            }
            goto LABEL_58;
        case 10149:
        LABEL_58:
            sub_4597E0(0);
            return 1;
        case 10152:
            v10 = (int*)sub_416590(1);
            sub_4BDC10(v10);
            return 1;
        case 10159:
            v11 = *(_DWORD*)(a3 + 396);
            sub_46B120((_DWORD*)a3, 0);
            sub_46B120((_DWORD*)a3, v11);
            v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10196);
            if (sub_40A5C0(1))
            {
                nox_window_set_hidden((int)v12, 0);
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10161, 10163, 0);
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1046492], 10161, 10163, 1);
                sub_4593B0(0);
                v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10163);
                v13[9] |= 4u;
                v14 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10161);
                v14[9] &= 0xFFFFFFFB;
                v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10162);
                v15[9] &= 0xFFFFFFFB;
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10141, 10141, 1);
            }
            else
            {
                nox_window_set_hidden((int)v12, 1);
                *(_DWORD*)& byte_5D4594[1046532] = sub_456270(*(int*)& byte_5D4594[1046492]);
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10141, 10141, 1);
            }
            nox_window_set_hidden(*(int*)& byte_5D4594[1046524], 1);
            return 1;
        case 10160:
            v16 = *(_DWORD*)(a3 + 396);
            sub_46B120((_DWORD*)a3, 0);
            sub_46B120((_DWORD*)a3, v16);
            if (*(_DWORD*)& byte_5D4594[1046532])
            {
                sub_456D60(1);
                *(_DWORD*)& byte_5D4594[1046532] = 0;
            }
            if (*(_DWORD*)& byte_5D4594[1046528])
            {
                sub_4557D0(1);
                *(_DWORD*)& byte_5D4594[1046528] = 0;
            }
            if (*(_DWORD*)& byte_5D4594[1046536])
            {
                sub_4AD820();
                *(_DWORD*)& byte_5D4594[1046540] = 0;
            }
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10161, 10163, 1);
            if (sub_40A5C0(1))
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[1046492], 10141, 10141, 0);
            v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10196);
            nox_window_set_hidden((int)v17, 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1046524], 0);
            return 1;
        case 10161:
            sub_4593B0(1);
            return 1;
        case 10162:
            sub_4593B0(2);
            return 1;
        case 10163:
            sub_4593B0(0);
            return 1;
        case 10330:
            if (sub_417DA0(4))
            {
                sub_418690(0);
                sub_419030(1);
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1046508], 10331, 10333, 0);
                result = 1;
            }
            else
            {
                sub_4185B0();
                if (sub_417DA0(2))
                    sub_4181F0(0);
                else
                    sub_418690(1);
                sub_46AD20(*(_DWORD * *)& byte_5D4594[1046508], 10331, 10333, 1);
                result = 1;
            }
            return result;
        case 10331:
            if (sub_417DA0(2))
            {
                sub_417D70(2);
                sub_418690(1);
            }
            else
            {
                sub_418690(0);
                sub_418390();
            }
            return 1;
        case 10332:
            sub_4181F0(1);
            return 1;
        case 10333:
            if (sub_417DA0(1))
                sub_417D70(1);
            else
                sub_417D50(1);
            return 1;
        default:
            return 1;
        }
        return result;
    }
    if (a2 == 23)
        return 0;
    if (a2 != 16387)
        return 1;
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], a4);
    sub_416630();
    v5 = sub_4165B0();
    if (!v4)
        return 0;
    if ((unsigned __int16)a3 == 1)
    {
        if (a4 == 10101)
        {
            v4[26] = *(_DWORD*)& byte_5D4594[2523948];
            return 1;
        }
        return 1;
    }
    v7 = nox_window_call_field_94((int)v4, 16413, 0, 0);
    nox_sprintf(v41, "%S", v7);
    if (!v41 || !v41[0])
        return 1;
    v8 = atoi(v41);
    if (v8 < 0)
        v8 = 0;
    if (a4 == 10101)
    {
        v4[26] = sub_4344A0(230, 165, 65);
        strcpy(v5 + 9, v41);
        sub_40A440(v41);
        return 1;
    }
    if (a4 == 10134)
    {
        *((_WORD*)v5 + 27) = v8;
        sub_459D50(1);
        return 1;
    }
    if (a4 != 10135)
        return 1;
    if (v8 > 255)
    {
        LOBYTE(v8) = -1;
        _itow(255, WideCharStr, 10);
        nox_window_call_field_94((int)v4, 16414, (int)WideCharStr, -1);
    }
    v5[56] = v8;
    sub_459D50(1);
    return 1;
}
// 458F5A: variable 'v34' is possibly undefined

//----- (00459150) --------------------------------------------------------
char sub_459150()
{
    char* v0; // ebp
    int i; // edi
    char* v2; // esi
    int v3; // ebx
    wchar_t* v4; // eax
    char* v5; // eax
    const char* v6; // edi
    char* v7; // eax
    int v8; // ebx
    char* v9; // esi
    unsigned __int8 v10; // dl
    char* v11; // edi
    char* v12; // eax
    char* v13; // eax
    int* v14; // eax
    int* v16; // [esp-Ch] [ebp-2Ch]
    int* v17; // [esp-4h] [ebp-24h]
    __int16 v18; // [esp-4h] [ebp-24h]
    char v19[16]; // [esp+10h] [ebp-10h]

    v0 = sub_4165B0();
    if (v0[52] & 0x60)
    {
        for (i = sub_417DD0(); i < 2; ++i)
        {
            v2 = sub_4186D0(0);
            v3 = (i != 0) + 1;
            if (sub_40A740())
            {
                sub_418800((wchar_t*)v2, (wchar_t*)& byte_5D4594[1046564], 0);
            }
            else
            {
                v4 = sub_418C20(v3);
                sub_418800((wchar_t*)v2, v4, 1);
            }
            v2[56] = v3;
            sub_4184D0((wchar_t*)v2);
        }
        sub_417D50(4);
    }
    LOBYTE(v5) = v0[57];
    if ((_BYTE)v5)
    {
        v5 = sub_409B80();
        v6 = v5;
    }
    else
    {
        v6 = v0;
    }
    if (*v6)
    {
        v7 = sub_409B40();
        v8 = _strcmpi(v6, v7);
        sub_4165F0(1, 0);
        v9 = sub_4165D0(0);
        sub_40A440(v9 + 9);
        if (!((*((_WORD*)v9 + 26) >> 8) & 0x10))
        {
            sub_409FB0(*((_WORD*)v9 + 26), *((_WORD*)v9 + 27));
            sub_40A040(*((_WORD*)v9 + 26), v9[56]);
        }
        if (v8 && sub_43AF70() == 1)
        {
            if (!sub_40A5C0(128))
            {
                sub_4263C0();
                sub_40DF90();
                sub_4264D0();
                sub_416150(15, 0);
            }
            if (!v9[57])
                sub_41D650();
        }
        if (sub_40A5C0(128))
        {
            sub_40A540(49152);
            sub_40A4D0(*((_WORD*)v9 + 26) & 0xC000);
        }
        v9[57] = 0;
        if (v8)
        {
            v19[0] = 0;
            *(_DWORD*)& v19[1] = 0;
            *(_DWORD*)& v19[5] = 0;
            *(_DWORD*)& v19[9] = 0;
            v10 = byte_587000[131672];
            strcpy(v19, v6);
            v11 = &v19[strlen(v19)];
            *(_DWORD*)v11 = *(_DWORD*)& byte_587000[131668];
            v11[4] = v10;
            sub_4D2450(v19);
            sub_416690();
            sub_4165D0(1);
            LOBYTE(v5) = (unsigned int)sub_4597E0(0);
        }
        else
        {
            sub_424BD0();
            sub_4537F0();
            v17 = (int*)sub_459870();
            v12 = sub_416590(1);
            sub_57AAA0("user.rul", v12, v17);
            v13 = sub_409B30();
            sub_57A950(v13);
            v18 = sub_40A5B0();
            v16 = (int*)sub_459870();
            v14 = (int*)sub_416590(0);
            sub_57A1E0(v14, "user.rul", v16, 3, v18);
            LOBYTE(v5) = (unsigned int)sub_4597E0(0);
        }
    }
    return (char)v5;
}

//----- (004593B0) --------------------------------------------------------
int __cdecl sub_4593B0(int a1)
{
    _DWORD* v1; // esi
    _DWORD* v2; // ebx
    _DWORD* v3; // edi
    int result; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10163);
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10161);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10162);
    if (a1)
    {
        if (a1 == 1)
        {
            v1[15] = *(_DWORD*)& byte_5D4594[1046360];
            v3[15] = *(_DWORD*)& byte_5D4594[1046356];
            if (*(_DWORD*)& byte_5D4594[1046532])
            {
                sub_456D60(1);
                *(_DWORD*)& byte_5D4594[1046532] = 0;
            }
            if (*(_DWORD*)& byte_5D4594[1046540])
            {
                sub_4AD820();
                *(_DWORD*)& byte_5D4594[1046540] = 0;
            }
            *(_DWORD*)& byte_5D4594[1046528] = sub_4541D0(*(int*)& byte_5D4594[1046492]);
            result = sub_459560(10161);
        }
        else
        {
            result = a1 - 2;
            if (a1 == 2)
            {
                v1[15] = *(_DWORD*)& byte_5D4594[1046360];
                if (sub_40A5C0(1))
                    v2[15] = *(_DWORD*)& byte_5D4594[1046360];
                else
                    v2[21] = *(_DWORD*)& byte_5D4594[1046360];
                if (*(_DWORD*)& byte_5D4594[1046528])
                {
                    sub_4557D0(1);
                    *(_DWORD*)& byte_5D4594[1046528] = 0;
                }
                if (*(_DWORD*)& byte_5D4594[1046540])
                {
                    sub_4AD820();
                    *(_DWORD*)& byte_5D4594[1046540] = 0;
                }
                *(_DWORD*)& byte_5D4594[1046532] = sub_456270(*(int*)& byte_5D4594[1046492]);
                result = sub_459560(10162);
            }
        }
    }
    else
    {
        if (sub_40A5C0(1))
            v2[15] = *(_DWORD*)& byte_5D4594[1046356];
        else
            v2[21] = *(_DWORD*)& byte_5D4594[1046356];
        v3[15] = *(_DWORD*)& byte_5D4594[1046356];
        if (*(_DWORD*)& byte_5D4594[1046532])
        {
            sub_456D60(1);
            *(_DWORD*)& byte_5D4594[1046532] = 0;
        }
        else if (*(_DWORD*)& byte_5D4594[1046528])
        {
            sub_4557D0(1);
            *(_DWORD*)& byte_5D4594[1046528] = 0;
        }
        *(_DWORD*)& byte_5D4594[1046540] = sub_4AD320(*(int*)& byte_5D4594[1046492]);
        result = sub_459560(10163);
    }
    return result;
}

//----- (00459560) --------------------------------------------------------
int __cdecl sub_459560(int a1)
{
    _DWORD* v1; // ebx
    int v2; // esi
    _DWORD* v3; // edi
    _DWORD* v4; // eax
    _DWORD* v5; // edi
    _DWORD* v6; // edi
    _DWORD* v7; // edi

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], a1);
    v2 = v1[99];
    switch (a1)
    {
    case 10161:
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10163);
        sub_46B120(v6, 0);
        sub_46B120(v6, v2);
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10162);
        goto LABEL_7;
    case 10162:
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10163);
        sub_46B120(v5, 0);
        sub_46B120(v5, v2);
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10161);
        goto LABEL_7;
    case 10163:
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10162);
        sub_46B120(v3, 0);
        sub_46B120(v3, v2);
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10161);
    LABEL_7:
        v7 = v4;
        sub_46B120(v4, 0);
        sub_46B120(v7, v2);
        break;
    }
    sub_46B120(v1, 0);
    return sub_46B120(v1, v2);
}

//----- (00459650) --------------------------------------------------------
int __cdecl sub_459650(wchar_t* a1)
{
    int v1; // edi
    const wchar_t** v2; // eax
    unsigned __int8* v3; // esi
    int v4; // ecx

    v1 = 0;
    if (!*(_DWORD*)& byte_587000[129668])
        return 0;
    v2 = (const wchar_t**)& byte_587000[129668];
    v3 = &byte_587000[129668];
    while (nox_wcscmp(*v2, a1))
    {
        v4 = *((_DWORD*)v3 + 3);
        v3 += 12;
        ++v1;
        v2 = (const wchar_t**)v3;
        if (!v4)
            return 0;
    }
    return *(_DWORD*)& byte_587000[12 * v1 + 129672];
}

//----- (004596A0) --------------------------------------------------------
int sub_4596A0()
{
    _DWORD* v0; // edi
    int result; // eax
    int* v2; // esi

    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10120);
    nox_window_call_field_94((int)v0, 16399, 0, 0);
    result = *(_DWORD*)& byte_587000[129668];
    if (*(_DWORD*)& byte_587000[129668])
    {
        v2 = (int*)& byte_587000[129668];
        do
        {
            if (v2[1] != 4096)
                nox_window_call_field_94((int)v0, 16397, *v2, -1);
            result = v2[3];
            v2 += 3;
        } while (result);
    }
    return result;
}

//----- (00459700) --------------------------------------------------------
int sub_459700()
{
    char* v0; // esi
    int v1; // eax
    int v2; // edi
    const wchar_t* v3; // eax
    wchar_t v5[256]; // [esp+8h] [ebp-200h]

    sub_416580();
    v0 = sub_4165B0();
    v1 = nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16404, 0, 0);
    v2 = v1;
    v3 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16406, v1, 0);
    nox_wcscpy(v5, v3);
    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16398, v2, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16402, v2, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16397, (int)v5, -1);
    nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16403, v2, 0);
    sub_57A9F0(v0, "user.rul");
    sub_57A1E0((int*)v0, "user.rul", 0, 5, *((_WORD*)v0 + 26));
    sub_459880((int)v0);
    return sub_459D50(1);
}

//----- (004597E0) --------------------------------------------------------
int* __cdecl sub_4597E0(int a1)
{
    int v1; // eax
    int* result; // eax

    if (*(_DWORD*)& byte_5D4594[1046492])
    {
        v1 = sub_46B4F0();
        if (nox_window_is_child(*(int*)& byte_5D4594[1046492], v1))
            sub_46B500(0);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1046492]);
        *(_DWORD*)& byte_5D4594[1046492] = 0;
        sub_456D60(0);
        sub_4BE610();
        *(_DWORD*)& byte_5D4594[1046532] = 0;
        sub_4557D0(0);
        *(_DWORD*)& byte_5D4594[1046528] = 0;
        sub_4AD820();
        *(_DWORD*)& byte_5D4594[1046536] = 0;
    }
    result = (int*)a1;
    if (a1)
    {
        result = sub_57ADF0((int*)& byte_5D4594[1045956]);
        *(_DWORD*)& byte_587000[129656] = 1;
    }
    return result;
}

//----- (00459870) --------------------------------------------------------
char* sub_459870()
{
    return (char*)& byte_5D4594[1045956];
}

//----- (00459880) --------------------------------------------------------
int __cdecl sub_459880(int a1)
{
    __int16 v1; // ax
    wchar_t* v2; // eax
    _DWORD* v4; // eax
    int v5; // ecx
    unsigned int v6; // ecx

    sub_416630();
    v1 = *(_WORD*)(a1 + 52);
    if (v1 & 0x20)
    {
        if (!*(_BYTE*)(a1 + 57) && sub_40A5C0(1))
        {
            sub_46ABB0(*(int*)& byte_5D4594[1046516], 1);
            sub_46ABB0(*(int*)& byte_5D4594[1046520], 1);
        }
        v2 = loadString_sub_40F1D0((char*)& byte_587000[131772], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1900);
    }
    else
    {
        LOBYTE(v1) = *(_BYTE*)(a1 + 57);
        if (v1 & 0x400)
        {
            if (!LOBYTE(v1) && sub_40A5C0(1))
            {
                sub_46ABB0(*(int*)& byte_5D4594[1046516], 1);
                sub_46ABB0(*(int*)& byte_5D4594[1046520], 1);
            }
            v2 = loadString_sub_40F1D0((char*)& byte_587000[131848], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1912);
        }
        else
        {
            if (!LOBYTE(v1) && sub_40A5C0(1) && !sub_40A5C0(49152))
            {
                sub_46ABB0(*(int*)& byte_5D4594[1046516], 1);
                sub_46ABB0(*(int*)& byte_5D4594[1046520], 1);
            }
            v2 = loadString_sub_40F1D0((char*)& byte_587000[131920], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 1926);
        }
    }
    nox_wcscpy((wchar_t*)(*(_DWORD*)& byte_5D4594[1046516] + 108), v2);
    sub_4580E0(a1);
    sub_459A40((char*)(a1 + 9));
    if (sub_40A5C0(1) && !sub_40A5C0(49152))
    {
        sub_46ABB0(*(int*)& byte_5D4594[1046500], *(_BYTE*)(a1 + 57) == 0);
        sub_46ABB0(*(int*)& byte_5D4594[1046504], *(_BYTE*)(a1 + 57) == 0);
    }
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10122);
    v5 = v4[9];
    if (*(_BYTE*)(a1 + 57))
        v6 = v5 | 4;
    else
        v6 = v5 & 0xFFFFFFFB;
    v4[9] = v6;
    sub_453F70((const void*)(a1 + 24));
    sub_4535E0((int*)(a1 + 44));
    return sub_4535F0(*(_DWORD*)(a1 + 48));
}

//----- (00459A40) --------------------------------------------------------
int __cdecl sub_459A40(char* a1)
{
    char v2[100]; // [esp+0h] [ebp-12Ch]
    wchar_t v3[100]; // [esp+64h] [ebp-C8h]

    strncpy(v2, a1, 0xFu);
    v2[15] = 0;
    nox_swprintf(v3, L"%S", v2);
    return nox_window_call_field_94(*(int*)& byte_5D4594[1046512], 16414, (int)v3, 0);
}

//----- (00459AA0) --------------------------------------------------------
char* __cdecl sub_459AA0(int a1)
{
    int v1; // eax
    const wchar_t* v2; // eax
    const wchar_t* v3; // eax
    char* result; // eax
    int v5; // eax
    const char* v6; // edi
    char v7[100]; // [esp+Ch] [ebp-64h]

    v1 = nox_window_call_field_94(*(int*)& byte_5D4594[1046512], 16413, 0, 0);
    nox_sprintf(v7, "%S", v1);
    strncpy((char*)(a1 + 9), v7, 0xFu);
    *(_WORD*)(a1 + 52) = sub_459C10();
    qmemcpy((void*)(a1 + 24), sub_453F90(), 0x14u);
    *(_DWORD*)(a1 + 44) = *(_DWORD*)sub_453600();
    *(_DWORD*)(a1 + 48) = sub_453610();
    v2 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1046516], 16413, 0, 0);
    if (*v2)
        * (_WORD*)(a1 + 54) = nox_wcstol(v2, 0, 10);
    v3 = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[1046520], 16413, 0, 0);
    if (*v3)
        * (_BYTE*)(a1 + 56) = nox_wcstol(v3, 0, 10);
    *(_BYTE*)(a1 + 57) = (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10122)[9] >> 2) & 1;
    result = (char*)nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16404, 0, 0);
    if ((int)result >= 0
        && (v5 = nox_window_call_field_94(*(int*)& byte_5D4594[1046496], 16406, (int)result, 0),
            nox_sprintf(v7, "%S", v5),
            (result = strtok(v7, "\t")) != 0))
    {
        v6 = result;
        result = 0;
        strcpy((char*)a1, v6);
    }
    else
    {
        *(_BYTE*)a1 = 0;
    }
    return result;
}

//----- (00459C10) --------------------------------------------------------
int sub_459C10()
{
    wchar_t* v0; // eax

    v0 = (wchar_t*)sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10119);
    return sub_459650(v0 + 54);
}

//----- (00459C30) --------------------------------------------------------
int sub_459C30()
{
    char* v0; // esi
    int result; // eax
    _DWORD* v2; // edi
    int v3; // eax

    v0 = sub_416590(1);
    sub_453F70(v0 + 24);
    sub_4535E0((int*)v0 + 11);
    sub_4535F0(*((_DWORD*)v0 + 12));
    result = *(_DWORD*)& byte_5D4594[1046492];
    if (*(_DWORD*)& byte_5D4594[1046492])
    {
        sub_459880((int)v0);
        sub_4BDF70((int*)v0);
        sub_458230(*((unsigned __int16*)v0 + 26), v0, 0);
        sub_457460((int)v0);
        if (sub_43AF70() == 1)
            sub_457FE0();
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10119);
        v3 = sub_4573C0(*((_WORD*)v0 + 26));
        result = nox_window_call_field_94((int)v2, 16385, v3, 0);
    }
    return result;
}

//----- (00459CD0) --------------------------------------------------------
int sub_459CD0()
{
    int result; // eax
    unsigned __int8 v1; // al
    wchar_t* v2; // eax
    _DWORD* v3; // eax
    int v4; // [esp-4h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1046492];
    if (*(_DWORD*)& byte_5D4594[1046492])
    {
        if (sub_40A740() || sub_40A5C0(0x8000))
            v1 = sub_417DE0();
        else
            v1 = sub_417DD0();
        v4 = v1;
        v2 = loadString_sub_40F1D0((char*)& byte_587000[132012], 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\guiserv.c", 2071);
        nox_swprintf((wchar_t*)& byte_5D4594[1046364], v2, v4);
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1046492], 10110);
        result = nox_window_call_field_94((int)v3, 16385, (int)& byte_5D4594[1046364], -1);
    }
    return result;
}

//----- (00459D50) --------------------------------------------------------
int __cdecl sub_459D50(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1046544] = a1;
    return result;
}

//----- (00459D60) --------------------------------------------------------
int sub_459D60()
{
    return *(_DWORD*)& byte_5D4594[1046544];
}

//----- (00459D70) --------------------------------------------------------
int sub_459D70()
{
    int v0; // eax

    v0 = -(*(_DWORD*)& byte_5D4594[1046492] != 0);
    LOBYTE(v0) = v0 & 0xFE;
    return v0 + 2;
}

//----- (00459D80) --------------------------------------------------------
int __cdecl sub_459D80(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1046492];
    if (*(_DWORD*)& byte_5D4594[1046492])
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1046492], a1);
    return result;
}

//----- (00459DA0) --------------------------------------------------------
BOOL sub_459DA0()
{
    return *(_DWORD*)& byte_5D4594[1046492] != 0;
}

//----- (00459DB0) --------------------------------------------------------
BOOL __cdecl sub_459DB0(int a1)
{
    return *(_DWORD*)(a1 + 112) & 0x400000 && *(_BYTE*)(a1 + 116) & 8;
}

//----- (00459DD0) --------------------------------------------------------
int __cdecl sub_459DD0(int a1, char a2)
{
    int result; // eax
    int v3; // ecx
    int v4; // ecx

    result = a1;
    v3 = *(_DWORD*)(a1 + 120);
    *(_BYTE*)(a1 + 284) |= a2;
    if (v3 >= 0)
    {
        v4 = *(_DWORD*)& byte_5D4594[1046596];
        *(_DWORD*)(a1 + 412) = 0;
        *(_DWORD*)(a1 + 408) = v4;
        if (*(_DWORD*)& byte_5D4594[1046596])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1046596] + 412) = a1;
        *(_DWORD*)& byte_5D4594[1046596] = a1;
        *(_DWORD*)(a1 + 120) |= 0x80000000;
    }
    return result;
}

//----- (00459E30) --------------------------------------------------------
int __cdecl sub_459E30(int a1, char a2)
{
    int result; // eax
    bool v3; // zf
    int v4; // ecx
    int v5; // ecx

    result = a1;
    if (*(int*)(a1 + 120) < 0)
    {
        v3 = ((unsigned __int8)~a2 & *(_BYTE*)(a1 + 284)) == 0;
        *(_BYTE*)(a1 + 284) &= ~a2;
        if (v3)
        {
            v4 = *(_DWORD*)(a1 + 408);
            if (v4)
                * (_DWORD*)(v4 + 412) = *(_DWORD*)(a1 + 412);
            v5 = *(_DWORD*)(a1 + 412);
            if (v5)
                * (_DWORD*)(v5 + 408) = *(_DWORD*)(a1 + 408);
            else
                *(_DWORD*)& byte_5D4594[1046596] = *(_DWORD*)(a1 + 408);
            *(_DWORD*)(a1 + 120) &= 0x7FFFFFFFu;
        }
    }
    return result;
}

//----- (00459EB0) --------------------------------------------------------
int sub_459EB0()
{
    return *(_DWORD*)& byte_5D4594[1046596];
}

//----- (00459EC0) --------------------------------------------------------
int __cdecl sub_459EC0(int a1)
{
    return *(_DWORD*)(a1 + 408);
}

//----- (00459ED0) --------------------------------------------------------
int __cdecl sub_459ED0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 416) = *(_DWORD*)& byte_5D4594[1046600];
    *(_DWORD*)(a1 + 420) = 0;
    if (*(_DWORD*)& byte_5D4594[1046600])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1046600] + 420) = a1;
    *(_DWORD*)& byte_5D4594[1046600] = a1;
    return result;
}

//----- (00459F00) --------------------------------------------------------
int __cdecl sub_459F00(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    v2 = *(_DWORD*)(a1 + 416);
    if (v2)
        * (_DWORD*)(v2 + 420) = *(_DWORD*)(a1 + 420);
    v3 = *(_DWORD*)(a1 + 420);
    if (v3)
    {
        result = *(_DWORD*)(a1 + 416);
        *(_DWORD*)(v3 + 416) = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1046600] = *(_DWORD*)(a1 + 416);
    }
    return result;
}

//----- (00459F40) --------------------------------------------------------
int __cdecl sub_459F40(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 424) = *(_DWORD*)& byte_5D4594[1046576];
    *(_DWORD*)(a1 + 428) = 0;
    if (*(_DWORD*)& byte_5D4594[1046576])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1046576] + 428) = a1;
    *(_DWORD*)& byte_5D4594[1046576] = a1;
    return result;
}

//----- (00459F70) --------------------------------------------------------
_DWORD* __cdecl sub_459F70(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    v2 = a1[106];
    if (v2)
    {
        *(_DWORD*)(v2 + 428) = a1[107];
    }
    else if (!a1[107] && *(_DWORD * *)& byte_5D4594[1046576] != a1)
    {
        return result;
    }
    v3 = a1[107];
    if (v3)
        * (_DWORD*)(v3 + 424) = a1[106];
    else
        *(_DWORD*)& byte_5D4594[1046576] = a1[106];
    a1[106] = 0;
    a1[107] = 0;
    result = (_DWORD*)sub_452EB0(a1 + 124);
    if (result)
        result = (_DWORD*)sub_4523D0(result);
    return result;
}

//----- (0045A000) --------------------------------------------------------
int sub_45A000()
{
    return *(_DWORD*)& byte_5D4594[1046600];
}

//----- (0045A010) --------------------------------------------------------
int __cdecl sub_45A010(int a1)
{
    return *(_DWORD*)(a1 + 416);
}

//----- (0045A020) --------------------------------------------------------
int sub_45A020()
{
    return *(_DWORD*)& byte_5D4594[1046588];
}

//----- (0045A030) --------------------------------------------------------
int sub_45A030()
{
    return *(_DWORD*)& byte_5D4594[1046568];
}

//----- (0045A040) --------------------------------------------------------
int __cdecl sub_45A040(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 360);
    else
        result = 0;
    return result;
}

//----- (0045A060) --------------------------------------------------------
int sub_45A060()
{
    return *(_DWORD*)& byte_5D4594[1046572];
}

//----- (0045A070) --------------------------------------------------------
int __cdecl sub_45A070(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 368);
    else
        result = 0;
    return result;
}

//----- (0045A090) --------------------------------------------------------
int sub_45A090()
{
    return *(_DWORD*)& byte_5D4594[1046576];
}

//----- (0045A0A0) --------------------------------------------------------
int __cdecl sub_45A0A0(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 424);
    else
        result = 0;
    return result;
}

//----- (0045A0C0) --------------------------------------------------------
int sub_45A0C0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1046572];
    if (!*(_DWORD*)& byte_5D4594[1046572])
        return 0;
    while (!(*(_DWORD*)(result + 120) & 0x2000000))
    {
        result = *(_DWORD*)(result + 368);
        if (!result)
            return 0;
    }
    return result;
}

//----- (0045A0E0) --------------------------------------------------------
int __cdecl sub_45A0E0(int a1)
{
    int result; // eax

    result = *(_DWORD*)(a1 + 368);
    if (!result)
        return 0;
    while (!(*(_DWORD*)(result + 120) & 0x2000000))
    {
        result = *(_DWORD*)(result + 368);
        if (!result)
            return 0;
    }
    return result;
}

//----- (0045A110) --------------------------------------------------------
_DWORD* __cdecl sub_45A110(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    a1[98] = 0;
    a1[97] = *(_DWORD*)& byte_5D4594[1046580];
    if (*(_DWORD*)& byte_5D4594[1046580])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1046580] + 392) = a1;
    else
        *(_DWORD*)& byte_5D4594[1046584] = a1;
    *(_DWORD*)& byte_5D4594[1046580] = a1;
    a1[30] |= 0x400000u;
    return result;
}

//----- (0045A160) --------------------------------------------------------
_DWORD* __cdecl sub_45A160(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    if (a1[30] & 0x400000)
    {
        v2 = a1[98];
        if (v2)
            * (_DWORD*)(v2 + 388) = a1[97];
        else
            *(_DWORD*)& byte_5D4594[1046580] = a1[97];
        v3 = a1[97];
        if (v3)
            * (_DWORD*)(v3 + 392) = a1[98];
        else
            *(_DWORD*)& byte_5D4594[1046584] = a1[98];
        a1[30] &= 0xFFBFFFFF;
    }
    return result;
}

//----- (0045A1D0) --------------------------------------------------------
BOOL __cdecl sub_45A1D0(int a1)
{
    *(_DWORD*)& byte_5D4594[1046592] = nox_new_alloc_class("drawableClass", 512, a1);
    return *(_DWORD*)& byte_5D4594[1046592] != 0;
}

//----- (0045A200) --------------------------------------------------------
int sub_45A200()
{
    nox_free_alloc_class(*(LPVOID*)& byte_5D4594[1046592]);
    *(_DWORD*)& byte_5D4594[1046592] = 0;
    *(_DWORD*)& byte_5D4594[1046568] = 0;
    *(_DWORD*)& byte_5D4594[1046572] = 0;
    *(_DWORD*)& byte_5D4594[1046580] = 0;
    *(_DWORD*)& byte_5D4594[1046584] = 0;
    *(_DWORD*)& byte_5D4594[1046588] = 0;
    return 1;
}

//----- (0045A240) --------------------------------------------------------
_DWORD* __cdecl sub_45A240(int a1)
{
    _DWORD* v1; // esi
    _DWORD* result; // eax
    int(__cdecl * v3)(_DWORD*, int); // eax
    int v4; // eax

    v1 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1046592]);
    if (v1 || (result = sub_45A330(), (v1 = result) != 0))
    {
        result = (_DWORD*)sub_44D0C0(*(float*)& v1, a1);
        if (result)
        {
            v3 = (int(__cdecl*)(_DWORD*, int))v1[75];
            if (v3 == nox_thing_static_random_draw)
            {
                v4 = sub_415FF0(0, *(unsigned __int8*)(v1[76] + 8) - 1, "C:\\NoxPost\\src\\Client\\Drawable\\drawable.c", 401);
                sub_45AB80((int)v1, v4);
            }
            else if (v3 == nox_thing_red_spark_draw || v3 == nox_thing_blue_spark_draw || v3 == nox_thing_yellow_spark_draw || v3 == nox_thing_green_spark_draw || v3 == nox_thing_cyan_spark_draw)
            {
                *((_WORD*)v1 + 52) = 35;
                *((_BYTE*)v1 + 296) = 2;
            }
            else
            {
                sub_45AB80((int)v1, 0);
            }
            v1[79] = *(_DWORD*)& byte_5D4594[2598000];
            v1[85] = *(_DWORD*)& byte_5D4594[2598000];
            ++* (_DWORD*)& byte_5D4594[1046588];
            v1[120] = 0;
            v1[121] = 0;
            result = v1;
        }
    }
    return result;
}

//----- (0045A330) --------------------------------------------------------
void* sub_45A330()
{
    if (!*(_DWORD*)& byte_5D4594[1046584])
        return 0;
    sub_45A4E0(*(int*)& byte_5D4594[1046584]);
    return nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[1046592]);
}

//----- (0045A360) --------------------------------------------------------
int __cdecl sub_45A360(int a1, int a2, int a3)
{
    _DWORD* v3; // eax
    int v4; // esi
    int v6; // edx

    v3 = sub_45A240(a1);
    v4 = (int)v3;
    if (!v3)
        return 0;
    sub_452E60(v3 + 124);
    if (*(_DWORD*)(v4 + 464))
        sub_49BC80((_DWORD*)v4);
    if (*(_DWORD*)(v4 + 120) & 0x200000)
        sub_49BAB0((_DWORD*)v4);
    if (*(_DWORD*)(v4 + 492))
        sub_459F40(v4);
    *(_DWORD*)(v4 + 12) = a2;
    *(_DWORD*)(v4 + 32) = a2;
    *(_DWORD*)(v4 + 16) = a3;
    *(_DWORD*)(v4 + 36) = a3;
    *(_DWORD*)(v4 + 320) = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)(v4 + 368) = *(_DWORD*)& byte_5D4594[1046572];
    *(_DWORD*)(v4 + 372) = 0;
    if (*(_DWORD*)& byte_5D4594[1046572])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1046572] + 372) = v4;
    *(_DWORD*)& byte_5D4594[1046572] = v4;
    sub_49AA00((_DWORD*)v4);
    if (*(_DWORD*)(v4 + 120) & 0x10000)
    {
        v6 = *(_DWORD*)& byte_5D4594[1046568];
        *(_DWORD*)(v4 + 364) = 0;
        *(_DWORD*)(v4 + 360) = v6;
        if (*(_DWORD*)& byte_5D4594[1046568])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1046568] + 364) = v4;
        *(_DWORD*)& byte_5D4594[1046568] = v4;
    }
    if (*(_BYTE*)(v4 + 112) & 4)
        sub_459ED0(v4);
    *(_DWORD*)(v4 + 120) |= 0x1000000u;
    sub_45A990(v4);
    *(_DWORD*)(v4 + 480) = 0;
    *(_DWORD*)(v4 + 484) = 0;
    sub_45A480(v4);
    return v4;
}

//----- (0045A480) --------------------------------------------------------
void __cdecl sub_45A480(int a1)
{
    int v1; // ecx

    if (*(_DWORD*)(a1 + 112) & 0x1000000 && *(_BYTE*)(a1 + 116) & 0xC0)
    {
        v1 = *(_DWORD*)(a1 + 120);
        if (v1 & 0x4000)
            sub_495F70(a1);
    }
}

//----- (0045A4B0) --------------------------------------------------------
int __cdecl sub_45A4B0(_QWORD* a1)
{
    sub_495B00((int)a1);
    sub_414330(*(unsigned int**)& byte_5D4594[1046592], a1);
    return -- * (_DWORD*)& byte_5D4594[1046588];
}

//----- (0045A4E0) --------------------------------------------------------
int __cdecl sub_45A4E0(int a1)
{
    int v1; // eax
    int v2; // eax
    int v3; // eax
    int v4; // eax

    v1 = *(_DWORD*)(a1 + 372);
    if (v1)
        * (_DWORD*)(v1 + 368) = *(_DWORD*)(a1 + 368);
    else
        *(_DWORD*)& byte_5D4594[1046572] = *(_DWORD*)(a1 + 368);
    v2 = *(_DWORD*)(a1 + 368);
    if (v2)
        * (_DWORD*)(v2 + 372) = *(_DWORD*)(a1 + 372);
    sub_49A9B0(a1);
    sub_476F10(a1);
    if (*(_DWORD*)(a1 + 120) & 0x10000)
    {
        v3 = *(_DWORD*)(a1 + 364);
        if (v3)
            * (_DWORD*)(v3 + 360) = *(_DWORD*)(a1 + 360);
        else
            *(_DWORD*)& byte_5D4594[1046568] = *(_DWORD*)(a1 + 360);
        v4 = *(_DWORD*)(a1 + 360);
        if (v4)
            * (_DWORD*)(v4 + 364) = *(_DWORD*)(a1 + 364);
    }
    sub_45A160((_DWORD*)a1);
    sub_49BCD0((_DWORD*)a1);
    sub_49BAF0((_DWORD*)a1);
    sub_49BA10((_DWORD*)a1);
    sub_459E30(a1, 3);
    sub_459F70((_DWORD*)a1);
    if (*(_BYTE*)(a1 + 112) & 4)
        sub_459F00(a1);
    if (sub_419130(a1 + 24))
        sub_419570(a1 + 24, *(_DWORD*)(a1 + 128));
    return sub_45A4B0((_QWORD*)a1);
}

//----- (0045A5E0) --------------------------------------------------------
void __cdecl sub_45A5E0(int a1)
{
    int v1; // esi
    int v2; // edi

    v1 = *(_DWORD*)& byte_5D4594[1046572];
    if (*(_DWORD*)& byte_5D4594[1046572])
    {
        do
        {
            v2 = *(_DWORD*)(v1 + 368);
            if (!(*(_BYTE*)(v1 + 112) & 4) || !a1 || !sub_45A630(v1))
                sub_45A4E0(v1);
            v1 = v2;
        } while (v2);
    }
}

//----- (0045A630) --------------------------------------------------------
int __cdecl sub_45A630(int a1)
{
    char* v1; // eax

    v1 = sub_416EA0();
    if (!v1)
        return 0;
    while (*(_DWORD*)(a1 + 128) != *((_DWORD*)v1 + 515))
    {
        v1 = sub_416EE0((int)v1);
        if (!v1)
            return 0;
    }
    return 1;
}

//----- (0045A670) --------------------------------------------------------
int __cdecl sub_45A670(unsigned int a1)
{
    int result; // eax
    _DWORD* v2; // esi
    _DWORD* v3; // edi

    result = *(_DWORD*)& byte_5D4594[1046604];
    if (!*(_DWORD*)& byte_5D4594[1046604])
    {
        result = sub_44CFC0((CHAR*)& byte_587000[132084]);
        *(_DWORD*)& byte_5D4594[1046604] = result;
    }
    v2 = *(_DWORD * *)& byte_5D4594[1046572];
    if (*(_DWORD*)& byte_5D4594[1046572])
    {
        do
        {
            result = v2[28];
            v3 = (_DWORD*)v2[92];
            if (!(result & 0x20400006))
            {
                result = sub_49C520((int)v2);
                if (!result)
                {
                    result = v2[27];
                    if (result != *(_DWORD*)& byte_5D4594[1046604] && v2[80] < a1)
                        result = sub_45A4E0((int)v2);
                }
            }
            v2 = v3;
        } while (v3);
    }
    return result;
}

//----- (0045A6F0) --------------------------------------------------------
_DWORD* __cdecl sub_45A6F0(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1046572];
    if (!*(_DWORD*)& byte_5D4594[1046572])
        return 0;
    while (result[28] & 0x20400000 || result[32] != a1)
    {
        result = (_DWORD*)result[92];
        if (!result)
            return 0;
    }
    return result;
}

//----- (0045A720) --------------------------------------------------------
_DWORD* __cdecl sub_45A720(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1046572];
    if (!*(_DWORD*)& byte_5D4594[1046572])
        return 0;
    while (!(result[28] & 0x20400000) || result[32] != a1)
    {
        result = (_DWORD*)result[92];
        if (!result)
            return 0;
    }
    return result;
}

//----- (0045A750) --------------------------------------------------------
int sub_45A750()
{
    int result; // eax
    _DWORD* v1; // edi
    int v2; // ecx
    int v3; // edx
    int v4; // ebp
    int v5; // edx
    int v6; // esi
    int v7; // ecx
    int v8; // ebx
    int v9; // eax
    int v10; // [esp+4h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[2614252];
    v1 = *(_DWORD * *)& byte_5D4594[1046572];
    v10 = *(_DWORD*)& byte_5D4594[2614252];
    if (*(_DWORD*)& byte_5D4594[1046572])
    {
        do
        {
            if (v1[28] & 0x300000)
            {
                v2 = v1[8];
                if (v2)
                {
                    v4 = v1[3];
                    v5 = v1[4];
                    v6 = (v1[3] - v2) >> 1;
                    v7 = v6;
                    if (v6 < 0)
                        v7 = -v6;
                    if (v7 > 1)
                        v4 = v1[3] + v6;
                    v8 = (v1[4] - v1[9]) >> 1;
                    v9 = v8;
                    if (v8 < 0)
                        v9 = -v8;
                    if (v9 > 1)
                        v5 = v1[4] + v8;
                    result = v6;
                    if (v6 < 0)
                        result = -v6;
                    if (result <= 10)
                    {
                        result = (v1[4] - v1[9]) >> 1;
                        if (v8 < 0)
                            result = -v8;
                        if (result <= 10)
                        {
                            v1[72] = *(_DWORD*)& byte_5D4594[2598000];
                            sub_49AA90(v1, v4, v5);
                            result = v10;
                            if (v1 == (_DWORD*)v10)
                            {
                                if (v6 < 0)
                                    v6 = -v6;
                                if (v6 > 1)
                                    goto LABEL_30;
                                if (v8 < 0)
                                    v8 = -v8;
                                if (v8 > 1)
                                    LABEL_30:
                                result = sub_435600(v1[3], v1[4]);
                            }
                        }
                    }
                }
                else
                {
                    v3 = v1[4];
                    v1[8] = v1[3];
                    v1[9] = v3;
                }
            }
            v1 = (_DWORD*)v1[92];
        } while (v1);
    }
    return result;
}

//----- (0045A840) --------------------------------------------------------
int __cdecl sub_45A840(_DWORD* a1)
{
    int result; // eax
    int v2; // eax
    int v3; // eax

    if (sub_4356C0((int)a1, 23))
    {
        sub_484BE0(a1 + 34, 128, 128, 255);
        sub_484D70((int)(a1 + 34), 300.0);
        result = 1;
    }
    else if (sub_4356C0((int)a1, 15) || a1 == *(_DWORD * *)& byte_5D4594[2614252] && sub_467430() & 8)
    {
        sub_484BE0(a1 + 34, 255, 255, 255);
        sub_484D70((int)(a1 + 34), 200.0);
        result = 1;
    }
    else
    {
        v2 = a1[28];
        if (!(v2 & 2) || v2 & 0x80000)
        {
            result = 0;
        }
        else if (a1[69] == 10)
        {
            sub_484D70((int)(a1 + 34), 0.0);
            result = 1;
        }
        else
        {
            sub_484BE0(a1 + 34, 255, 255, 255);
            v3 = a1[29];
            if (v3 & 1)
            {
                sub_484D70((int)(a1 + 34), 25.0);
                result = 1;
            }
            else if (v3 & 2)
            {
                sub_484D70((int)(a1 + 34), 35.0);
                result = 1;
            }
            else
            {
                if (v3 & 4)
                    sub_484D70((int)(a1 + 34), 45.0);
                result = 1;
            }
        }
    }
    return result;
}

//----- (0045A990) --------------------------------------------------------
int __cdecl sub_45A990(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 120) |= 4u;
    return result;
}

//----- (0045A9A0) --------------------------------------------------------
int __cdecl sub_45A9A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 120) &= 0xFFFFFFFB;
    return result;
}

//----- (0045A9B0) --------------------------------------------------------
int* __cdecl sub_45A9B0(int a1, int a2)
{
    int v2; // esi
    int v3; // ebp
    char* v4; // eax
    char* v5; // edi
    int* result; // eax
    int v7; // edi
    int v8; // ebx
    int v9; // eax
    int v10; // esi
    __int64 v11; // rax
    int v12; // eax
    int* v13; // esi
    int* v14; // edi
    int* v15; // edi
    int v16; // [esp+Ch] [ebp-Ch]
    char* v17; // [esp+10h] [ebp-8h]
    int* v18; // [esp+14h] [ebp-4h]

    v2 = a1;
    v3 = 0;
    v16 = 0;
    v4 = sub_452270(*(_DWORD*)(a1 + 492));
    v5 = v4;
    v17 = v4;
    result = (int*)sub_437250();
    v18 = result;
    if (v5 && result)
    {
        if (*(_DWORD*)(a1 + 120) & 0x1000000 && !(*(_BYTE*)(a1 + 280) & 0xC))
        {
            v7 = *(_DWORD*)(a2 + 12) - *(_DWORD*)(a1 + 12);
            v8 = *(_DWORD*)(a2 + 16) - *(_DWORD*)(a1 + 16);
            v9 = sub_4522A0((int)v17);
            v10 = v9;
            if (v7 < v9 && v8 < v9 && v9 > 0)
            {
                v11 = (__int64)sqrt((double)(v8 * v8 + v7 * v7 + 1));
                if ((int)v11 < v10)
                {
                    v12 = 100 * (v10 - (int)v11) / v10;
                    v3 = v12;
                    if (v12 <= 100)
                    {
                        if (v12 < 0)
                            v3 = 0;
                    }
                    else
                    {
                        v3 = 100;
                    }
                    v16 = 50 * (*(int*)(a1 + 12) - v18[6] - *v18) / (nox_win_width / 2);
                }
            }
            v2 = a1;
        }
        v13 = (int*)(v2 + 496);
        result = (int*)sub_452EB0(v13);
        v14 = result;
        if (v3)
        {
            if (result)
            {
                sub_452FE0((int)result, v16);
                result = (int*)sub_452F50((int)v14, v3);
            }
            else
            {
                result = sub_452300(v17);
                v15 = result;
                if (result)
                {
                    sub_452EE0((int)result, v3);
                    sub_452F80((int)v15, v16);
                    result = (int*)sub_452E90(v13, (int)v15);
                }
            }
        }
        else if (result)
        {
            result = (int*)sub_4523D0(result);
        }
    }
    return result;
}

//----- (0045AB40) --------------------------------------------------------
int sub_45AB40()
{
    int result; // eax
    int i; // esi

    result = sub_45A090();
    for (i = result; result; i = result)
    {
        if (*(_DWORD*)(i + 492))
            sub_45A9B0(i, *(int*)& byte_5D4594[2614252]);
        result = sub_45A0A0(i);
    }
    return result;
}

//----- (0045AB80) --------------------------------------------------------
int __cdecl sub_45AB80(int a1, int a2)
{
    int result; // eax

    result = a1;
    if (!(*(_BYTE*)(a1 + 112) & 2) || !(*(_DWORD*)(a1 + 116) & 0x40000) || *(_DWORD*)(a1 + 276) != 8)
    {
        *(_DWORD*)(a1 + 312) = *(_DWORD*)(a1 + 308);
        *(_DWORD*)(a1 + 308) = a2;
    }
    return result;
}

//----- (0045ABC0) --------------------------------------------------------
int __cdecl sub_45ABC0(const void* a1, const void* a2)
{
    int v2; // edi
    const wchar_t* v3; // esi
    const wchar_t* v4; // eax
    int result; // eax
    int v6; // [esp-4h] [ebp-Ch]

    v2 = *(_DWORD*)a2;
    if (*(_DWORD*)& byte_5D4594[1046868] == 1)
    {
        v3 = (const wchar_t*)sub_427240(*(_DWORD*)a1);
        v4 = (const wchar_t*)sub_427240(v2);
    }
    else
    {
        v6 = *(_DWORD*)a1;
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251))
        {
            v3 = (const wchar_t*)sub_424930(v6);
            v4 = (const wchar_t*)sub_424930(v2);
        }
        else
        {
            v3 = (const wchar_t*)sub_425260(v6);
            v4 = (const wchar_t*)sub_425260(v2);
        }
    }
    if (v3 && v4)
        result = _nox_wcsicmp(v3, v4);
    else
        result = 0;
    return result;
}

//----- (0045AC40) --------------------------------------------------------
int sub_45AC40()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1046880] = sub_4344A0(15, 15, 15);
    result = sub_4344A0(115, 100, 100);
    *(_DWORD*)& byte_5D4594[1046884] = result;
    return result;
}

//----- (0045AC70) --------------------------------------------------------
unsigned int sub_45AC70()
{
    unsigned int result; // eax

    if (wndIsShown_sub_46ACC0(nox_win_unk1))
        result = sub_45AD70(0);
    else
        result = sub_45ACA0(0);
    return result;
}

//----- (0045ACA0) --------------------------------------------------------
int __cdecl sub_45ACA0(int a1)
{
    int v1; // eax
    int v2; // ecx

    if (wndIsShown_sub_46ACC0(nox_win_unk1) || *(_DWORD*)& byte_5D4594[1047520] == 1)
        return 0;
    *(_DWORD*)& byte_5D4594[1046864] = 0;
    *(_DWORD*)& byte_5D4594[3799524] = 1;
    *(_DWORD*)& byte_5D4594[1046868] = *(_DWORD*)& byte_5D4594[1046872] != 0;
    v1 = sub_46AE00();
    v2 = nox_win_unk1;
    if (v1 == nox_win_unk1)
    {
        sub_46ADE0(nox_win_unk1);
        v2 = nox_win_unk1;
    }
    nox_window_set_hidden(v2, 1);
    sub_452D80(787, 100);
    if (a1)
    {
        *(_DWORD*)& byte_587000[132132] = 1;
        *(_DWORD*)& byte_5D4594[1046936] = 0;
        nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 1);
    }
    if (sub_477670() == 1)
        sub_477660();
    return 1;
}

//----- (0045AD70) --------------------------------------------------------
unsigned int __cdecl sub_45AD70(int a1)
{
    unsigned int result; // eax
    wchar_t* v2; // eax

    result = sub_477600();
    if (!result)
    {
        if (!sub_4372B0() || (result = sub_40A5C0(2048)) == 0)
        {
            if (!*(_DWORD*)& byte_5D4594[2618908]
                || sub_45ADF0(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618908] + 2251)))
            {
                result = sub_45B010(a1);
            }
            else
            {
                v2 = loadString_sub_40F1D0((char*)& byte_587000[132176], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 377);
                sub_445490(v2);
                result = (unsigned int)sub_452D80(925, 100);
            }
        }
    }
    return result;
}

//----- (0045ADF0) --------------------------------------------------------
int __cdecl sub_45ADF0(int a1)
{
    int v1; // edi
    int i; // esi
    int v3; // eax
    int k; // esi
    int v5; // eax
    int j; // esi
    int v7; // eax
    int v9; // [esp+Ch] [ebp-4h]

    v1 = 0;
    *(_DWORD*)& byte_5D4594[1046656] = sub_43F320(0) + 2;
    *(_DWORD*)& byte_5D4594[1047508] = 0;
    *(_DWORD*)& byte_5D4594[1047512] = 0;
    v9 = 2 * (141 / *(_DWORD*)& byte_5D4594[1046656]) - 2;
    if (*(_DWORD*)& byte_5D4594[1046868] == 1)
    {
        for (i = sub_427300(); i; i = sub_427320(i))
        {
            if (sub_40A5C0(0x2000) && !sub_40A5C0(4096) || *(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4 * i + 4244))
            {
                if (sub_4D70C0(i))
                {
                    v3 = *(_DWORD*)& byte_5D4594[1047508];
                    v1 = 1;
                    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1047508] + 1046960] = i;
                    *(_DWORD*)& byte_5D4594[1047508] = v3 + 1;
                }
            }
        }
    }
    else if (a1)
    {
        for (j = sub_424AD0(); j; j = sub_424AF0(j))
        {
            if (j != 34
                && !sub_57AEA0(a1, j)
                && (sub_40A5C0(0x2000) && !sub_40A5C0(4096) || *(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4 * j + 3696)))
            {
                if (sub_424A50(j, 86016))
                    ++* (_DWORD*)& byte_5D4594[1047512];
                if (!sub_424A50(j, 0x2000))
                {
                    v7 = *(_DWORD*)& byte_5D4594[1047508];
                    v1 = 1;
                    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1047508] + 1046960] = j;
                    *(_DWORD*)& byte_5D4594[1047508] = v7 + 1;
                }
            }
        }
    }
    else
    {
        for (k = sub_425330(); k; k = sub_425350(k))
        {
            if (sub_40A5C0(0x2000) && !sub_40A5C0(4096) || *(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4 * k + 3696))
            {
                v5 = *(_DWORD*)& byte_5D4594[1047508];
                v1 = 1;
                *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1047508] + 1046960] = k;
                *(_DWORD*)& byte_5D4594[1047508] = v5 + 1;
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1046940] = (*(_DWORD*)& byte_5D4594[1047508] - *(_DWORD*)& byte_5D4594[1047512]) / v9 + 1;
    qsort(&byte_5D4594[1046960], *(_DWORD*)& byte_5D4594[1047508] - *(_DWORD*)& byte_5D4594[1047512], 4u, sub_45ABC0);
    return v1;
}

//----- (0045B010) --------------------------------------------------------
unsigned int __cdecl sub_45B010(int a1)
{
    unsigned int result; // eax

    result = sub_446360();
    if (!result)
    {
        result = sub_4AE3D0();
        if (!result)
        {
            if (a1 || (result = sub_57AF20()) == 0)
            {
                *(_DWORD*)& byte_5D4594[1046864] = 1;
                *(_DWORD*)& byte_5D4594[1046868] = *(_DWORD*)& byte_5D4594[1046872] != 0;
                sub_46A8C0(nox_win_unk1);
                result = (unsigned int)sub_452D80(786, 100);
            }
        }
    }
    return result;
}

//----- (0045B070) --------------------------------------------------------
int __cdecl sub_45B070(int a1, int a2)
{
    if (*(_DWORD*)& byte_5D4594[1047520] == 1)
        return 1;
    if (a2 == 10)
    {
        sub_45AC70();
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[2614252]
        && !sub_478030()
        && !sub_47A260()
        && (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) == 2)
    {
        return 1;
    }
    if (a2 != 5)
        return 0;
    nox_window_set_hidden(*(int*)& byte_5D4594[1046944], 0);
    if (*(_DWORD*)& byte_587000[132132])
    {
        if (*(_DWORD*)& byte_5D4594[1046936] + 1 < *(int*)& byte_5D4594[1046940])
        {
            ++* (_DWORD*)& byte_5D4594[1046936];
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1046932] = 0;
            *(_DWORD*)& byte_587000[132132] = 0;
            nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 0);
        }
        if (*(_DWORD*)& byte_5D4594[1046872])
            ** (_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B200;
        else
            **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B1F0;
        *(_DWORD*)& byte_5D4594[1046868] = 2;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046924] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
    LABEL_23:
        sub_452D80(788, 100);
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[1046932] < *(int*)& byte_5D4594[1047508] - *(_DWORD*)& byte_5D4594[1047512] - 1)
    {
        ++* (_DWORD*)& byte_5D4594[1046932];
        if (*(_DWORD*)& byte_5D4594[1046872])
            ** (_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B200;
        else
            **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B1F0;
        *(_DWORD*)& byte_5D4594[1046868] = 2;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046924] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
        goto LABEL_23;
    }
    return 1;
}

//----- (0045B1F0) --------------------------------------------------------
int sub_45B1F0()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[1046868] = 0;
    *(_DWORD*)& byte_5D4594[1046872] = 0;
    return result;
}

//----- (0045B200) --------------------------------------------------------
int sub_45B200()
{
    int result; // eax

    result = 1;
    *(_DWORD*)& byte_5D4594[1046868] = 1;
    *(_DWORD*)& byte_5D4594[1046872] = 1;
    return result;
}

//----- (0045B210) --------------------------------------------------------
int __cdecl sub_45B210(int a1, int a2)
{
    if (*(_DWORD*)& byte_5D4594[1047520] == 1)
        return 1;
    if (a2 == 10)
    {
        sub_45AC70();
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[2614252]
        && !sub_478030()
        && !sub_47A260()
        && (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) == 2)
    {
        return 1;
    }
    if (a2 != 5)
        return 0;
    nox_window_set_hidden(*(int*)& byte_5D4594[1046948], 0);
    if (!*(_DWORD*)& byte_587000[132132])
    {
        if (*(int*)& byte_5D4594[1046932] < *(int*)& byte_5D4594[1047508] - *(int*)& byte_5D4594[1047512])
        {
            if (*(int*)& byte_5D4594[1046932] <= 0)
            {
                *(_DWORD*)& byte_587000[132132] = 1;
                *(_DWORD*)& byte_5D4594[1046936] = *(_DWORD*)& byte_5D4594[1046940] - 1;
                nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 1);
            }
            else
            {
                --* (_DWORD*)& byte_5D4594[1046932];
            }
        }
        else
        {
            *(_DWORD*)& byte_587000[132132] = 1;
            *(_DWORD*)& byte_5D4594[1046936] = 0;
            nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 1);
        }
    LABEL_18:
        if (*(_DWORD*)& byte_5D4594[1046872])
            ** (_DWORD * *)(*(_DWORD*)& byte_5D4594[1046928] + 96) = sub_45B200;
        else
            **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046928] + 96) = sub_45B1F0;
        *(_DWORD*)& byte_5D4594[1046868] = 3;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046928] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
        sub_452D80(788, 100);
        return 1;
    }
    if (*(_DWORD*)& byte_5D4594[1046936])
    {
        --* (_DWORD*)& byte_5D4594[1046936];
        goto LABEL_18;
    }
    return 1;
}

//----- (0045B360) --------------------------------------------------------
int __cdecl sub_45B360(_DWORD* a1, unsigned int a2)
{
    int v2; // esi

    v2 = 0;
    if (*(_DWORD*)& byte_5D4594[1047520] == 1
        || *(_DWORD*)& byte_5D4594[2614252]
        && !sub_478030()
        && !sub_47A260()
        && (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) == 2)
    {
        return 1;
    }
    if (a2 != 5)
    {
        if (a2 <= 5 || a2 > 7)
            return 0;
        return 1;
    }
    if (*a1 == 1310)
    {
        if (*(_DWORD*)& byte_5D4594[1046872])
        {
            *(_DWORD*)& byte_5D4594[1046868] = 0;
            *(_DWORD*)& byte_5D4594[1046872] = 0;
            if (!sub_45ADF0(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1047516] + 2251)))
            {
                *(_DWORD*)& byte_5D4594[1046868] = 1;
                *(_DWORD*)& byte_5D4594[1046872] = 1;
                sub_45ADF0(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1047516] + 2251));
                sub_452D80(925, 100);
                return 1;
            }
            v2 = 1;
        }
        if (!*(_DWORD*)& byte_587000[132132] || *(_DWORD*)& byte_5D4594[1046936] || v2 == 1)
        {
            *(_DWORD*)& byte_587000[132132] = 1;
            *(_DWORD*)& byte_5D4594[1046936] = 0;
            sub_452D80(788, 100);
            *(_DWORD*)& byte_5D4594[1046868] = 3;
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046928] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
            **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046928] + 96) = sub_45B1F0;
            nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1046948], 0);
            sub_46ADE0(nox_win_unk1);
            sub_477660();
        }
        return 1;
    }
    if (*a1 != 1320)
        return 1;
    if (*(_DWORD*)& byte_5D4594[1046872] != 1)
    {
        *(_DWORD*)& byte_5D4594[1046868] = 1;
        *(_DWORD*)& byte_5D4594[1046872] = 1;
        if (!sub_45ADF0(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1047516] + 2251)))
        {
            *(_DWORD*)& byte_5D4594[1046868] = 0;
            *(_DWORD*)& byte_5D4594[1046872] = 0;
            sub_45ADF0(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1047516] + 2251));
            sub_452D80(925, 100);
            return 1;
        }
        v2 = 1;
    }
    if (*(_DWORD*)& byte_587000[132132] && !*(_DWORD*)& byte_5D4594[1046936] && v2 != 1)
        return 1;
    *(_DWORD*)& byte_587000[132132] = 1;
    *(_DWORD*)& byte_5D4594[1046936] = 0;
    sub_452D80(788, 100);
    if (v2 == 1)
    {
        *(_DWORD*)& byte_5D4594[1046868] = 2;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046924] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
        **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B200;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1046868] = 3;
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046928] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
        **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046928] + 96) = sub_45B200;
    }
    nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 1);
    nox_window_set_hidden(*(int*)& byte_5D4594[1046948], 0);
    sub_46ADE0(nox_win_unk1);
    sub_477660();
    return 1;
}

//----- (0045B5F0) --------------------------------------------------------
int __cdecl sub_45B5F0(int a1, unsigned int a2, unsigned int a3)
{
    int v3; // ebp
    int v4; // edi
    int v5; // esi
    int result; // eax
    bool v7; // sf
    signed int v8; // ebp
    int v9; // eax
    int v10; // ecx
    char v11; // al
    int v12; // eax
    int v13; // eax
    int v14; // [esp+10h] [ebp-4h]

    v3 = a3 >> 16;
    v4 = (unsigned __int16)a3;
    if (*(_DWORD*)& byte_5D4594[1047520] == 1
        || *(_DWORD*)& byte_5D4594[2614252]
        && !sub_478030()
        && !sub_47A260()
        && (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) == 2)
    {
        return 1;
    }
    if (!*(_DWORD*)& byte_587000[132132])
    {
        if (a2 >= 5)
        {
            if (a2 <= 8)
                return 1;
            if (a2 == 11)
            {
            LABEL_47:
                sub_45AC70();
                return 1;
            }
        }
        return 0;
    }
    *(_DWORD*)& byte_5D4594[1046656] = sub_43F320(0) + 2;
    v5 = 141 / *(_DWORD*)& byte_5D4594[1046656] - 1;
    sub_46AA20(a1, &v14, &a3);
    switch (a2)
    {
    case 5u:
        if (*(_DWORD*)& byte_5D4594[2614252] && (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) == 2)
            return 1;
        *(_DWORD*)& byte_5D4594[1047536] = v3;
        v7 = (int)(-19 - a3 + v3) < 0;
        v8 = -19 - a3 + v3;
        *(_DWORD*)& byte_5D4594[1047532] = v4;
        if (v7)
        {
            *(_DWORD*)& byte_587000[132136] = -1;
            return 1;
        }
        v9 = v8 / *(int*)& byte_5D4594[1046656];
        if (v8 / *(int*)& byte_5D4594[1046656] >= v5)
            goto LABEL_14;
        if (v4 - v14 > 145)
            v9 += v5;
        *(_DWORD*)& byte_587000[132136] = 2 * v5 * *(_DWORD*)& byte_5D4594[1046936] + v9;
        sub_46ADC0(a1);
        v10 = *(_DWORD*)& byte_587000[132136];
        if (*(_DWORD*)& byte_587000[132136] >= *(int*)& byte_5D4594[1047508] - *(_DWORD*)& byte_5D4594[1047512])
            goto LABEL_14;
        v11 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251);
        if (!v11 && !*(_DWORD*)& byte_5D4594[1046868])
        {
            *(_DWORD*)& byte_5D4594[1047528] = *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_587000[132136] + 1046960];
            sub_477640(*(int*)& byte_5D4594[1047528], 1);
            sub_452D80(793, 100);
            return 1;
        }
        if (v11 != 2 || *(_DWORD*)& byte_5D4594[1046868] != 1)
        {
            if (*(_DWORD*)& byte_5D4594[1046868])
                return 1;
            *(_DWORD*)& byte_5D4594[1047528] = *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_587000[132136] + 1046960];
            sub_477640(*(int*)& byte_5D4594[1047528], 1);
            sub_452D80(793, 100);
            result = 1;
        }
        else
        {
            if (!*(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4232))
            {
                if (!sub_40A5C0(0x2000) || sub_40A5C0(4096))
                {
                    sub_46ADE0(a1);
                    sub_45B930(*(int*)& byte_587000[132136]);
                    *(_DWORD*)& byte_5D4594[1047528] = 0;
                LABEL_14:
                    *(_DWORD*)& byte_587000[132136] = -1;
                    return 1;
                }
                v10 = *(_DWORD*)& byte_587000[132136];
            }
            *(_DWORD*)& byte_5D4594[1047528] = *(_DWORD*)& byte_5D4594[4 * v10 + 1046960] + 74;
            sub_477640(*(int*)& byte_5D4594[1047528], 1);
            sub_452D80(793, 100);
            result = 1;
        }
        break;
    case 6u:
    case 7u:
        if ((int) * (_DWORD*)& byte_587000[132136] >= 0)
        {
            v12 = *(_DWORD*)& byte_5D4594[1047532] - v4;
            if (*(int*)& byte_5D4594[1047532] - v4 < 0)
                v12 = v4 - *(_DWORD*)& byte_5D4594[1047532];
            if (v12 >= 5)
                goto LABEL_52;
            v13 = *(_DWORD*)& byte_5D4594[1047536] - v3;
            if (*(int*)& byte_5D4594[1047536] - v3 < 0)
                v13 = v3 - *(_DWORD*)& byte_5D4594[1047536];
            if (v13 >= 5)
                LABEL_52:
            sub_45DCA0(*(int*)& byte_5D4594[1047528], 0, v4, v3, 0);
            else
                sub_45B930(*(int*)& byte_587000[132136]);
        }
        if (sub_46AE00())
            sub_46ADE0(a1);
        sub_477660();
        return 1;
    case 8u:
        return 1;
    case 0xBu:
        goto LABEL_47;
    default:
        return 0;
    }
    return result;
}

//----- (0045B930) --------------------------------------------------------
int __cdecl sub_45B930(int a1)
{
    *(_DWORD*)& byte_587000[132132] = 0;
    *(_DWORD*)& byte_5D4594[1046932] = a1;
    *(_DWORD*)& byte_5D4594[1046936] = 99;
    if (*(_DWORD*)& byte_5D4594[1046872])
        ** (_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B200;
    else
        **(_DWORD * *)(*(_DWORD*)& byte_5D4594[1046924] + 96) = sub_45B1F0;
    *(_DWORD*)& byte_5D4594[1046868] = 2;
    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1046924] + 96) + 12) = sub_430B40_get_mouse_prev_seq();
    sub_452D80(788, 100);
    nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[1046944], 0);
    return nox_window_set_hidden(*(int*)& byte_5D4594[1046948], 0);
}

int sub_45BD30(int a1, int a2)
{
    return 1;
}

//----- (0045B9D0) --------------------------------------------------------
int sub_45B9D0()
{
    int result; // eax
    _DWORD* v1; // esi
    _DWORD* v2; // esi
    char* v3; // eax
    char* v4; // eax

    *(_DWORD*)& byte_5D4594[1047516] = *(_DWORD*)& byte_5D4594[2618908];
    result = sub_42F970("ArrowNW");
    *(_DWORD*)& byte_5D4594[1046888] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowN");
    *(_DWORD*)& byte_5D4594[1046892] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowNE");
    *(_DWORD*)& byte_5D4594[1046896] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowW");
    *(_DWORD*)& byte_5D4594[1046900] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowE");
    *(_DWORD*)& byte_5D4594[1046908] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowSW");
    *(_DWORD*)& byte_5D4594[1046912] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowS");
    *(_DWORD*)& byte_5D4594[1046916] = result;
    if (!result)
        return 0;

    result = sub_42F970("ArrowSE");
    *(_DWORD*)& byte_5D4594[1046920] = result;
    if (!result)
        return 0;

    result = sub_42F970("BookOfKnowledge");
    *(_DWORD*)& byte_5D4594[1046856] = result;
    if (!result)
        return 0;

    result = sub_42F970("GuideTabLit");
    *(_DWORD*)& byte_5D4594[1046660] = result;
    if (!result)
        return 0;

    result = sub_42F970("SpellTabLit");
    *(_DWORD*)& byte_5D4594[1046644] = result;
    if (!result)
        return 0;

    result = sub_42FA20("BookPageForward");
    *(_DWORD*)& byte_5D4594[1046924] = result;
    if (!result)
        return 0;

    **(_DWORD * *)(result + 96) = sub_45B1F0;
    result = sub_42FA20("BookPageBackward");
    *(_DWORD*)& byte_5D4594[1046928] = result;
    if (!result)
        return 0;

    **(_DWORD * *)(result + 96) = sub_45B1F0;
    nox_win_unk1 = nox_window_new(
        0,
        1196,
        5,
        nox_win_height - 323,
        285,
        168,
        0);
    nox_window_set_all_funcs(nox_win_unk1, sub_45B5F0, sub_45BD40, 0);
    nox_window_set_hidden(nox_win_unk1, 1);
    result = nox_window_new(nox_win_unk1, 8, 257, 15, 27, 40, 0);
    v1 = (_DWORD*)result;
    if (!result)
        return 0;

    nox_window_set_all_funcs((_DWORD*)result, sub_45B360, sub_45BD30, sub_45CF00);
    *v1 = 1320;
    result = nox_window_new(nox_win_unk1, 8, 253, 61, 27, 40, 0);
    v2 = (_DWORD*)result;
    if (!result)
        return 0;

    nox_window_set_all_funcs((_DWORD*)result, sub_45B360, sub_45BD30, sub_45CF00);
    *v2 = 1310;
    *(_DWORD*)& byte_5D4594[1046944] = nox_window_new(
        nox_win_unk1,
        136,
        24,
        138,
        20,
        20,
        0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1046944], sub_45B210, 0, 0);
    v3 = sub_42F970("ArrowW");
    sub_46AE60(*(int*)& byte_5D4594[1046944], (int)v3);
    *(_DWORD*)& byte_5D4594[1046948] = nox_window_new(
        nox_win_unk1,
        136,
        233,
        138,
        20,
        20,
        0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1046948], sub_45B070, 0, 0);
    v4 = sub_42F970("ArrowE");
    sub_46AE60(*(int*)& byte_5D4594[1046948], (int)v4);
    *(_DWORD*)& byte_5D4594[1046952] = nox_window_new(
        nox_win_unk1,
        8,
        63,
        19,
        30,
        30,
        0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1046952], sub_45CC10, sub_45CB30, 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[1046952], 1);
    *(_DWORD*)& byte_5D4594[1046956] = nox_window_new(0, 40, 0, 0, 30, 30, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1046956], 0, sub_45C7D0, 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[1046956], 1);
    *(_DWORD*)& byte_5D4594[1046868] = 0;
    *(_DWORD*)& byte_5D4594[1046872] = 0;
    *(_DWORD*)& byte_587000[132132] = 1;
    *(_DWORD*)& byte_5D4594[1046936] = 0;

    return 1;
}

//----- (0045BD40) --------------------------------------------------------
int __cdecl sub_45BD40(int a1)
{
    int v1; // esi
    int v2; // ebp
    int v3; // edi
    int v4; // esi
    int v5; // ebx
    int v6; // ebp
    int v7; // edi
    int v8; // esi
    char v9; // cl
    unsigned __int16* v10; // eax
    __int16* v11; // eax
    unsigned __int16* v12; // eax
    unsigned __int16* v13; // eax
    int v14; // esi
    wchar_t* v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // ebp
    wchar_t* v19; // eax
    int v20; // ebx
    wchar_t* v21; // eax
    wchar_t* v22; // eax
    int v23; // esi
    unsigned __int16* v24; // eax
    int v25; // eax
    _WORD* v26; // eax
    int v27; // eax
    unsigned __int16* v28; // eax
    unsigned __int16* v29; // esi
    int v30; // edi
    int v31; // edx
    int v32; // ecx
    unsigned __int16* v33; // eax
    int v34; // ecx
    _WORD* v35; // eax
    unsigned __int16* v36; // eax
    int v37; // eax
    __int16 v38; // bx
    unsigned __int16* v39; // eax
    int v40; // eax
    int v41; // esi
    _WORD* v42; // eax
    int v43; // esi
    int v44; // ebp
    wchar_t* v45; // eax
    int v46; // esi
    int v47; // esi
    unsigned __int16* v48; // ebp
    unsigned __int16* v49; // ebp
    unsigned __int16* v50; // ebp
    unsigned __int16* v51; // ebp
    wchar_t* v52; // eax
    unsigned __int16* v53; // eax
    int v55; // [esp-10h] [ebp-23Ch]
    int v56; // [esp-10h] [ebp-23Ch]
    int v57; // [esp-10h] [ebp-23Ch]
    int v58; // [esp-Ch] [ebp-238h]
    int v59; // [esp-Ch] [ebp-238h]
    int v60; // [esp-8h] [ebp-234h]
    int v61; // [esp-8h] [ebp-234h]
    int v62; // [esp-4h] [ebp-230h]
    int v63; // [esp-4h] [ebp-230h]
    int v64; // [esp-4h] [ebp-230h]
    int v65; // [esp+10h] [ebp-21Ch]
    int v66; // [esp+14h] [ebp-218h]
    int v67; // [esp+18h] [ebp-214h]
    int v68; // [esp+1Ch] [ebp-210h]
    WCHAR WideCharStr[4]; // [esp+20h] [ebp-20Ch]
    int v70; // [esp+28h] [ebp-204h]
    wchar_t v71[256]; // [esp+2Ch] [ebp-200h]

    sub_46AA20(a1, &v66, &v67);
    v1 = v66 - 24;
    v2 = v67 - 76;
    v3 = sub_43F320(0);
    *(_DWORD*)& byte_5D4594[1046656] = v3 + 2;
    sub_434390(*(int*)& byte_5D4594[1046880]);
    sub_47D2C0(*(int*)& byte_5D4594[1046856], v1, v2);
    if (*(_DWORD*)& byte_5D4594[1046872])
        sub_47D2C0(*(int*)& byte_5D4594[1046660], v1, v2);
    else
        sub_47D2C0(*(int*)& byte_5D4594[1046644], v1, v2);
    if (*(_DWORD*)& byte_5D4594[1046868] == 3)
    {
        sub_4BE6D0(*(int*)& byte_5D4594[1046928], v1, v2);
        goto LABEL_75;
    }
    if (*(_DWORD*)& byte_5D4594[1046868] == 2)
    {
        sub_4BE6D0(*(int*)& byte_5D4594[1046924], v1, v2);
        goto LABEL_75;
    }
    if (*(_DWORD*)& byte_587000[132132])
    {
        v4 = *(_DWORD*)& byte_5D4594[1046936];
        *(_DWORD*)WideCharStr = 141 / *(_DWORD*)& byte_5D4594[1046656] - 1;
        if (!*(_DWORD*)& byte_5D4594[1046936])
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[1046944], 1);
            v4 = *(_DWORD*)& byte_5D4594[1046936];
        }
        v5 = 0;
        v6 = v66 + 78;
        v7 = v67 + 19;
        if (2 * *(_DWORD*)WideCharStr > 0)
        {
            while (1)
            {
                v8 = v5 + 2 * *(_DWORD*)WideCharStr * v4;
                if (v8 >= *(int*)& byte_5D4594[1047508] - *(_DWORD*)& byte_5D4594[1047512])
                    break;
                if (v5 == *(_DWORD*)WideCharStr)
                {
                    v6 = v66 + 199;
                    v7 = v67 + 19;
                }
                sub_434390(*(int*)& byte_5D4594[1046880]);
                v9 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251);
                if (*(_DWORD*)& byte_5D4594[1046868] == 1)
                {
                    if (v9 == 2 && !sub_424B70(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960] + 74))
                        sub_434390(*(int*)& byte_5D4594[1046884]);
                    v10 = (unsigned __int16*)sub_427240(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]);
                    sub_43F840(0, v10, &v65, 0, 128);
                    v62 = v7;
                    v60 = v6 - v65 / 2;
                    v11 = (__int16*)sub_427240(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]);
                }
                else if (v9)
                {
                    if (!sub_424B70(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]))
                        sub_434390(*(int*)& byte_5D4594[1046884]);
                    v13 = (unsigned __int16*)sub_424930(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]);
                    sub_43F840(0, v13, &v65, 0, 128);
                    v62 = v7;
                    v60 = v6 - v65 / 2;
                    v11 = (__int16*)sub_424930(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]);
                }
                else
                {
                    v12 = (unsigned __int16*)sub_425260(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]);
                    sub_43F840(0, v12, &v65, 0, 128);
                    v62 = v7;
                    v60 = v6 - v65 / 2;
                    v11 = (__int16*)sub_425260(*(_DWORD*)& byte_5D4594[4 * v8 + 1046960]);
                }
                sub_43F6E0(0, v11, v60, v62);
                v7 += *(_DWORD*)& byte_5D4594[1046656];
                if (++v5 >= 2 * *(_DWORD*)WideCharStr)
                    break;
                v4 = *(_DWORD*)& byte_5D4594[1046936];
            }
        }
        goto LABEL_75;
    }
    if (*(_DWORD*)& byte_5D4594[1046868] == 1)
    {
        v14 = v67 + 51;
        v15 = loadString_sub_40F1D0((char*)& byte_587000[132380], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 978);
        nox_swprintf(v71, L"%s ", v15);
        v16 = sub_427460(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]) - 1;
        if (v16)
        {
            v17 = v16 - 1;
            if (v17)
            {
                if (v17 == 2)
                {
                    v18 = 76;
                    v19 = loadString_sub_40F1D0((char*)& byte_587000[132520], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 995);
                    nox_wcscat(v71, v19);
                    v20 = 0;
                }
                else
                {
                    v18 = *(_DWORD*)WideCharStr;
                    v20 = *(_DWORD*)WideCharStr;
                }
            }
            else
            {
                v18 = 38;
                v21 = loadString_sub_40F1D0((char*)& byte_587000[132476], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 989);
                nox_wcscat(v71, v21);
                v20 = 0;
            }
        }
        else
        {
            v18 = 38;
            v22 = loadString_sub_40F1D0((char*)& byte_587000[132432], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 983);
            nox_wcscat(v71, v22);
            v20 = 19;
        }
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251) == 2
            && (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4232) || sub_40A5C0(0x2000) && !sub_40A5C0(4096)))
        {
            sub_43F840(0, v71, &v70, 0, 0);
            sub_43FAF0(0, v71, (108 - v70) / 2 + v66 + 24, v14, 128, 0);
        }
        v23 = v14 + v3 + 2;
        v24 = (unsigned __int16*)sub_427240(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        sub_43FA80(0, v24, &v70, &v68, 108);
        if (v68 <= v3)
            v25 = (108 - v70) / 2 + v66 + 24;
        else
            v25 = v66 + 24;
        v55 = v25;
        v26 = (_WORD*)sub_427240(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        sub_43FD80(0, v26, v55, v23, 128, 0);
        v63 = v23 + v20 + v68 + 2;
        v61 = (108 - v18) / 2 + v66 + 24;
        v27 = sub_427400(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        sub_47D2C0(v27, v61, v63);
        v28 = (unsigned __int16*)sub_4272E0(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        v29 = v28;
        v30 = v67 + 52;
        if (v28)
        {
            sub_43F840(0, v28, 0, WideCharStr, 92);
            v31 = *(_DWORD*)WideCharStr;
            v32 = v66 + 153;
            goto LABEL_53;
        }
    }
    else
    {
        if (!*(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251))
        {
            sub_425450(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
            v33 = (unsigned __int16*)sub_425260(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
            sub_43FA80(0, v33, &v70, &v68, 108);
            if (v68 <= v3)
                v34 = (108 - v70) / 2 + v66 + 24;
            else
                v34 = v66 + 24;
            v58 = v67 + 53;
            v56 = v34;
            v35 = (_WORD*)sub_425260(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
            sub_43FD80(0, v35, v56, v58, 128, 0);
            v36 = (unsigned __int16*)sub_4252F0(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
            v29 = v36;
            v30 = v67 + 52;
            if (!v36)
                goto LABEL_75;
            sub_43F840(0, v36, 0, WideCharStr, 92);
            v31 = *(_DWORD*)WideCharStr;
            v32 = v66 + 153;
        LABEL_53:
            v37 = (141 - v31) / 2 + v67 + 17;
            if (v37 > v30)
                goto LABEL_73;
            goto LABEL_74;
        }
        v38 = sub_424A70(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        v39 = (unsigned __int16*)sub_424930(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        sub_43FA80(0, v39, &v65, &v68, 108);
        if (v68 <= v3)
            v40 = (108 - v65) / 2 + v66 + 24;
        else
            v40 = v66 + 24;
        v41 = v67 + 53;
        v59 = v67 + 53;
        v57 = v40;
        v42 = (_WORD*)sub_424930(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        sub_43FD80(0, v42, v57, v59, 128, 0);
        v43 = v41 + v68 + 2;
        v44 = sub_4249A0(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960], 1);
        v45 = loadString_sub_40F1D0((char*)& byte_587000[132564], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1115);
        nox_swprintf(v71, L"%s ", v45);
        if (v44)
        {
            _itow(v44, WideCharStr, 10);
            nox_wcscat(v71, WideCharStr);
        }
        else if (sub_424A50(
            *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960],
            0x800000))
        {
            nox_wcscat(v71, L"0");
        }
        else
        {
            nox_wcscat(v71, L"*");
        }
        sub_43F840(0, v71, &v65, 0, 0);
        v46 = v43 + 2;
        sub_43FAF0(0, v71, (108 - v65) / 2 + v66 + 24, v46, 128, 0);
        v47 = v46 + v3 + 2;
        if (v38 & 0x100)
        {
            v48 = loadString_sub_40F1D0((char*)& byte_587000[132628], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1173);
            sub_43F840(0, v48, &v65, 0, 0);
            sub_43FAF0(0, v48, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
            v47 += v3;
        }
        if (v38 & 4)
        {
            v49 = loadString_sub_40F1D0((char*)& byte_587000[132680], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1181);
            sub_43F840(0, v49, &v65, 0, 0);
            sub_43FAF0(0, v49, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
            v47 += v3;
        }
        if (v38 & 8)
        {
            v50 = loadString_sub_40F1D0((char*)& byte_587000[132732], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1189);
            sub_43F840(0, v50, &v65, 0, 0);
            sub_43FAF0(0, v50, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
            v47 += v3;
        }
        if (v38 & 0x20)
        {
            v51 = loadString_sub_40F1D0((char*)& byte_587000[132784], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1197);
            sub_43F840(0, v51, &v65, 0, 0);
            sub_43FAF0(0, v51, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
            v47 += v3;
        }
        v64 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516]
            + 4 * *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]
            + 3696);
        v52 = loadString_sub_40F1D0((char*)& byte_587000[132836], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1206);
        nox_swprintf(v71, v52, v64);
        sub_43F840(0, v71, &v65, 0, 0);
        sub_43FAF0(0, v71, (108 - v65) / 2 + v66 + 24, v3 + v47, 128, 0);
        v53 = (unsigned __int16*)sub_424A30(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
        v29 = v53;
        v30 = v67 + 52;
        if (v53)
        {
            sub_43F840(0, v53, 0, WideCharStr, 92);
            v32 = v66 + 153;
            v37 = (141 - *(_DWORD*)WideCharStr) / 2 + v67 + 17;
            if (v37 > v30)
                LABEL_73:
            v37 = v30;
        LABEL_74:
            sub_43FAF0(0, v29, v32, v37, 92, 0);
            goto LABEL_75;
        }
    }
LABEL_75:
    if (!*(_DWORD*)& byte_587000[132132]
        && *(int*)& byte_5D4594[1046932] >= *(int*)& byte_5D4594[1047508] - *(int*)& byte_5D4594[1047512] - 1)
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1046948], 1);
    }
    return 1;
}

//----- (0045C7D0) --------------------------------------------------------
int __cdecl sub_45C7D0(_DWORD* a1)
{
    int v1; // esi
    int v3; // edi
    int v4; // eax
    int v5; // eax
    int v6; // edi
    int v7; // eax
    int v8; // eax
    int v9; // eax
    int v10; // ecx
    double v11; // st7
    int v12; // eax
    int v13; // [esp-28h] [ebp-34h]
    int v14; // [esp-28h] [ebp-34h]
    int v15; // [esp-24h] [ebp-30h]
    int v16; // [esp-20h] [ebp-2Ch]
    char v17; // [esp-18h] [ebp-24h]
    char v18; // [esp-18h] [ebp-24h]
    char v19; // [esp-14h] [ebp-20h]
    char v20; // [esp-14h] [ebp-20h]
    int v21; // [esp-10h] [ebp-1Ch]
    int v22; // [esp-Ch] [ebp-18h]
    int v23; // [esp-Ch] [ebp-18h]
    int v24; // [esp+4h] [ebp-8h]
    int v25; // [esp+8h] [ebp-4h]

    v1 = *(_DWORD*)& byte_5D4594[1046652] != 0 ? 3 : 0;
    if (!*(_DWORD*)& byte_5D4594[1047520])
        return 1;
    if (*(_DWORD*)& byte_5D4594[1046648]
        && sub_430B40_get_mouse_prev_seq() - *(_DWORD*)& byte_5D4594[1046648] < (unsigned int)(2 * *(_DWORD*)& byte_5D4594[2649704]))
    {
        return 1;
    }
    sub_46AA60(a1, &v25, &v24);
    if (*(_DWORD*)& byte_5D4594[1046648])
    {
        v3 = 50;
        do
        {
            v19 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1287);
            v17 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1286);
            v16 = sub_415FF0(-10, -1, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1284);
            v15 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1283);
            v4 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1282);
            v13 = v24 + v4;
            v5 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1281);
            sub_431540(v1, v25 + v5, v13, v15, v16, 1, v17, v19, 2, 1);
            --v3;
        } while (v3);
        sub_452D80(795, 100);
        *(_DWORD*)& byte_5D4594[1046648] = 0;
    }
    v6 = 2;
    do
    {
        v20 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1331);
        v18 = sub_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1330);
        v7 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1326);
        v14 = v24 + v7;
        v8 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1325);
        sub_431540(v1, v25 + v8, v14, 0, 0, 0, v18, v20, 1, 1);
        --v6;
    } while (v6);
    v22 = v24;
    v21 = v25;
    if (*(_DWORD*)& byte_5D4594[1046652] == 1)
        v9 = sub_425310(*(int*)& byte_5D4594[1047524], 0);
    else
        v9 = sub_424A90(*(int*)& byte_5D4594[1047524]);
    sub_47D2C0(v9, v21, v22);
    *(float*)& byte_5D4594[1046636] = *(float*)& byte_5D4594[1046636] + *(float*)& byte_5D4594[1046620];
    *(float*)& byte_5D4594[1046640] = *(float*)& byte_5D4594[1046640] + *(float*)& byte_5D4594[1046624];
    if ((double) * (int*)& byte_5D4594[1046668] <= *(float*)& byte_5D4594[1046636]
        && (double) * (int*)& byte_5D4594[1046672] <= *(float*)& byte_5D4594[1046640])
    {
    LABEL_26:
        sub_45DBE0(*(void**)& byte_5D4594[1046676], *(int*)& byte_5D4594[1047524], *(int*)& byte_5D4594[1046852]);
        sub_45D810();
        goto LABEL_27;
    }
    if (*(float*)& byte_5D4594[1046636] > (double) * (float*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[1046628] + 1046692])
    {
        v10 = *(_DWORD*)& byte_5D4594[1046628] + 1;
        *(_DWORD*)& byte_5D4594[1046628] = v10;
        if (v10 < *(int*)& byte_5D4594[1046680])
        {
            if (v10 <= *(int*)& byte_5D4594[1046680] - 1)
            {
                *(float*)& byte_5D4594[1046620] = *(float*)& byte_5D4594[8 * v10 + 1046692]
                    - *(float*)& byte_5D4594[8 * v10 + 1046684];
                *(float*)& byte_5D4594[1046624] = *(float*)& byte_5D4594[8 * v10 + 1046696]
                    - *(float*)& byte_5D4594[8 * v10 + 1046688];
                sub_509F20((float2*)& byte_5D4594[1046620]);
                if (nox_win_width < 1000)
                {
                    if (nox_win_width < 750)
                        v11 = 6.0;
                    else
                        v11 = 8.0;
                }
                else
                {
                    v11 = 10.0;
                }
                *(float*)& byte_5D4594[1046620] = *(float*)& byte_5D4594[1046620] * v11;
                *(float*)& byte_5D4594[1046624] = *(float*)& byte_5D4594[1046624] * v11;
            }
            goto LABEL_27;
        }
        goto LABEL_26;
    }
LABEL_27:
    v23 = sub_419A70(*(float*)& byte_5D4594[1046640]);
    v12 = sub_419A70(*(float*)& byte_5D4594[1046636]);
    sub_46A9B0(a1, v12, v23);
    return 1;
}

//----- (0045CB30) --------------------------------------------------------
int __cdecl sub_45CB30(_DWORD* a1)
{
    int v1; // eax
    int v2; // esi
    int v4; // [esp+4h] [ebp-8h]
    int v5; // [esp+8h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[1046868])
    {
        if (*(_DWORD*)& byte_5D4594[1046868] != 1
            || *(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251) != 2
            || !*(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4232) && (!sub_40A5C0(0x2000) || sub_40A5C0(4096)))
        {
            return 1;
        }
        v1 = sub_424A90(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960] + 74);
    }
    else if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251))
    {
        v1 = sub_424A90(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960]);
    }
    else
    {
        v1 = sub_425310(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960], 0);
    }
    v2 = v1;
    if (v1)
    {
        sub_46AA60(a1, &v5, &v4);
        sub_47D2C0(v2, v5, v4);
    }
    return 1;
}

//----- (0045CC10) --------------------------------------------------------
int __cdecl sub_45CC10(_DWORD* a1, int a2, unsigned int a3)
{
    int result; // eax
    int v4; // ebp
    char v5; // al
    char v6; // al

    if (*(_DWORD*)& byte_5D4594[2614252] && (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) == 2)
        return 1;
    v4 = a3 >> 16;
    if (*(_DWORD*)& byte_5D4594[1046868] == 1)
    {
        v5 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251);
        if (v5 == 1
            || !v5
            || !sub_40A5C0(0x2000) && !sub_40A5C0(4096) && !*(_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4232))
        {
            return 0;
        }
    }
    switch (a2)
    {
    case 5:
        if (sub_46AE00() || *(_DWORD*)& byte_5D4594[1047540])
            goto LABEL_44;
        v6 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251);
        if (!v6 && !*(_DWORD*)& byte_5D4594[1046868])
        {
            *(_DWORD*)& byte_5D4594[1047540] = *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960];
            sub_477640(*(int*)& byte_5D4594[1047540], 1);
        LABEL_22:
            sub_46ADC0((int)a1);
            sub_452D80(793, 100);
            return 1;
        }
        if (v6 == 2 && *(_DWORD*)& byte_5D4594[1046868] == 1)
        {
            *(_DWORD*)& byte_5D4594[1047540] = *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960] + 74;
            sub_477640(*(int*)& byte_5D4594[1047540], 1);
            goto LABEL_22;
        }
        if (*(_DWORD*)& byte_5D4594[1046868])
            goto LABEL_44;
        *(_DWORD*)& byte_5D4594[1047540] = *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960];
        if (!sub_424A50(*(int*)& byte_5D4594[1047540], 86016))
        {
            sub_477640(*(int*)& byte_5D4594[1047540], 1);
            goto LABEL_22;
        }
        *(_DWORD*)& byte_5D4594[1047540] = 0;
        return 1;
    case 6:
    case 7:
        if (!*(_DWORD*)& byte_5D4594[1047540])
            goto LABEL_44;
        if (!sub_46AAB0(a1, (unsigned __int16)a3, v4))
        {
            if (sub_460650())
            {
                sub_45D9D0(*(int*)& byte_5D4594[1047540]);
            }
            else if (sub_4611A0())
            {
                sub_4611B0();
            }
            else
            {
                sub_45DCA0(*(int*)& byte_5D4594[1047540], 0, (unsigned __int16)a3, v4, 0);
            }
        LABEL_42:
            *(_DWORD*)& byte_5D4594[1047540] = 0;
            sub_46ADE0((int)a1);
            goto LABEL_43;
        }
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251))
        {
            if (sub_460650())
            {
                sub_45DF60(0, 0);
                *(_DWORD*)& byte_5D4594[1047540] = 0;
                sub_46ADE0((int)a1);
                sub_477660();
                return 1;
            }
            if (!sub_424A50(*(int*)& byte_5D4594[1047540], 1536))
            {
                sub_45DF60(*(int*)& byte_5D4594[1047540], 0);
                sub_477660();
                return 1;
            }
            if (sub_45DF60(*(int*)& byte_5D4594[1047540], 1))
                goto LABEL_42;
        }
        else
        {
            if (sub_4611A0())
            {
                sub_45DFC0(0);
                *(_DWORD*)& byte_5D4594[1047540] = 0;
                sub_46ADE0((int)a1);
                sub_477660();
                return 1;
            }
            if (sub_45DFC0(*(int*)& byte_5D4594[1047540]))
                goto LABEL_42;
        }
    LABEL_43:
        sub_477660();
    LABEL_44:
        result = 1;
        break;
    case 8:
        goto LABEL_44;
    default:
        return 0;
    }
    return result;
}

//----- (0045CF00) --------------------------------------------------------
int __cdecl sub_45CF00(_DWORD* a1)
{
    wchar_t* v1; // eax
    wchar_t* v3; // eax
    wchar_t* v4; // eax

    if (*a1 == 1310)
    {
        if (!*(_BYTE*)(*(_DWORD*)& byte_5D4594[1047516] + 2251))
        {
            v3 = loadString_sub_40F1D0((char*)& byte_587000[133244], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1640);
            sub_4776B0(v3);
            return 1;
        }
        v4 = loadString_sub_40F1D0((char*)& byte_587000[133300], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1644);
        sub_4776B0(v4);
    }
    else if (*a1 == 1320)
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[133352], 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1649);
        sub_4776B0(v1);
        return 1;
    }
    return 1;
}

//----- (0045CFA0) --------------------------------------------------------
int sub_45CFA0()
{
    int result; // eax

    if (*(_DWORD*)& byte_587000[132132])
        result = 0;
    else
        result = *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1046932] + 1046960];
    return result;
}

//----- (0045CFC0) --------------------------------------------------------
int sub_45CFC0()
{
    return ((unsigned __int8)~sub_46ADA0(nox_win_unk1) >> 4) & 1;
}

//----- (0045CFE0) --------------------------------------------------------
void __cdecl sub_45CFE0(int a1, int a2, int a3, int a4)
{
    int v4; // ebx
    int v5; // ebp
    int v6; // esi
    int* v7; // edi
    int v8; // eax
    int v9; // esi
    unsigned __int8* v10; // eax
    int v11; // [esp+14h] [ebp+4h]

    v4 = *(_DWORD*)& byte_5D4594[2618908];
    if (!*(_DWORD*)& byte_5D4594[2618908])
        return;
    v5 = a1;
    if (sub_57AEA0(*(unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618908] + 2251), a1) == 9)
        return;
    *(_DWORD*)(v4 + 4 * a1 + 3696) = a2;
    if (sub_424A50(a1, 4096))
    {
        v11 = 0x2000;
        goto LABEL_9;
    }
    if (sub_424A50(a1, 0x4000))
    {
        v11 = 0x8000;
        goto LABEL_9;
    }
    if (sub_424A50(a1, 0x10000))
    {
        v11 = 0x20000;
    LABEL_9:
        v6 = 1;
        v7 = (int*)(v4 + 3700);
        do
        {
            if (sub_424A50(v6, v11) && sub_424B50(v6))
                * v7 = a2;
            ++v6;
            ++v7;
        } while (v6 < 137);
    }
    *(_DWORD*)& byte_5D4594[1046868] = 0;
    *(_DWORD*)& byte_5D4594[1046872] = 0;
    sub_45ADF0(*(unsigned __int8*)(v4 + 2251));
    if (v5 == 34)
    {
        v8 = 1;
        if (*(_DWORD*)(v4 + 3832) != 1 || !a3)
            v8 = 0;
        sub_460EC0(v8);
    }
    else if (a3)
    {
        v9 = 0;
        v10 = &byte_5D4594[1046960];
        do
        {
            if (*(_DWORD*)v10 == v5)
                break;
            v10 += 4;
            ++v9;
        } while ((int)v10 < (int)& byte_5D4594[1047508]);
        if (v9 != 137)
        {
            sub_45ACA0(0);
            sub_45B930(v9);
            sub_45B010(0);
            sub_499CF0((int*)2, v5, a4);
        }
    }
}

//----- (0045D140) --------------------------------------------------------
void __cdecl sub_45D140(int a1, int a2)
{
    int v2; // edx
    unsigned __int8* v3; // esi
    _DWORD* v4; // ecx
    int v5; // eax
    int* v6; // ecx
    int v7; // eax
    int v8; // esi
    unsigned __int8* v9; // eax

    v2 = *(_DWORD*)& byte_5D4594[2618908];
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        v3 = &byte_587000[132124];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 4 * a1 + 4244) = 1;
        if (*(_DWORD*)& byte_587000[132124])
        {
            do
            {
                v4 = *(_DWORD * *)v3;
                if (a1 == **(_DWORD * *)v3)
                {
                    v5 = v4[1];
                    v6 = v4 + 1;
                    if (v5)
                    {
                        do
                        {
                            ++v6;
                            *(_DWORD*)(v2 + 4 * v5 + 4244) = 1;
                            v5 = *v6;
                        } while (*v6);
                    }
                }
                v7 = *((_DWORD*)v3 + 1);
                v3 += 4;
            } while (v7);
        }
        *(_DWORD*)& byte_5D4594[1046868] = 1;
        *(_DWORD*)& byte_5D4594[1046872] = 1;
        sub_45ADF0(*(unsigned __int8*)(v2 + 2251));
        if (a2)
        {
            v8 = 0;
            v9 = &byte_5D4594[1046960];
            do
            {
                if (*(_DWORD*)v9 == a1)
                    break;
                v9 += 4;
                ++v8;
            } while ((int)v9 < (int)& byte_5D4594[1047124]);
            if (v8 != 41)
            {
                sub_45ACA0(0);
                sub_45B930(v8);
                sub_45B010(0);
                sub_499CF0((int*)4, a1, 0);
            }
        }
    }
}

//----- (0045D200) --------------------------------------------------------
int* __cdecl sub_45D200(int* a1, int a2, int2* a3)
{
    int* result; // eax
    int v4; // ecx
    int v5; // ecx

    sub_45AD70(1);
    sub_46A9B0(nox_win_unk1, a3->field_0, a3->field_4);
    result = a1;
    if (a1 == (int*)2 || a1 == (int*)4)
    {
        v5 = 0;
        result = (int*)& byte_5D4594[1046960];
        do
        {
            if (*result == a2)
                break;
            ++result;
            ++v5;
        } while ((int)result < (int)& byte_5D4594[1047508]);
        if (v5 != 137)
            result = (int*)sub_45B930(v5);
    }
    else if (a1 == (int*)3)
    {
        v4 = 0;
        result = (int*)& byte_5D4594[1046960];
        do
        {
            if (*result == a2)
                break;
            ++result;
            ++v4;
        } while ((int)result < (int)& byte_5D4594[1046984]);
        if (v4 != 6)
            result = (int*)sub_45B930(v4);
    }
    return result;
}

//----- (0045D290) --------------------------------------------------------
char* __cdecl sub_45D290(int a1, char* a2, int a3)
{
    char* result; // eax
    int v4; // esi

    result = sub_417040(*(int*)& byte_5D4594[2616328]);
    if (result)
    {
        *(_DWORD*)& byte_5D4594[1046868] = 0;
        *(_DWORD*)& byte_5D4594[1046872] = 0;
        sub_45ADF0((unsigned __int8)result[2251]);
        result = a2;
        if (a2)
        {
            v4 = 0;
            result = (char*)& byte_5D4594[1046960];
            do
            {
                if (*(_DWORD*)result == a1)
                    break;
                result += 4;
                ++v4;
            } while ((int)result < (int)& byte_5D4594[1046984]);
            if (v4 != 6)
            {
                sub_45ACA0(0);
                sub_45B930(v4);
                sub_45B010(0);
                result = (char*)a3;
                if (a3)
                    result = (char*)sub_499CF0((int*)3, a1, a3);
            }
        }
    }
    return result;
}

//----- (0045D320) --------------------------------------------------------
int __cdecl sub_45D320(int a1)
{
    int v1; // ebx
    int result; // eax
    int v3; // ebp
    int v4; // esi
    _DWORD* v5; // edi

    v1 = *(_DWORD*)& byte_5D4594[2618908];
    result = sub_45ACA0(1);
    if (v1)
    {
        *(_DWORD*)(v1 + 4 * a1 + 3696) = 0;
        sub_461360(a1);
        if (sub_424A50(a1, 4096))
        {
            v3 = 0x2000;
        }
        else if (sub_424A50(a1, 0x4000))
        {
            v3 = 0x8000;
        }
        else
        {
            if (!sub_424A50(a1, 0x10000))
                return sub_45ADF0(*(unsigned __int8*)(v1 + 2251));
            v3 = 0x20000;
        }
        v4 = 1;
        v5 = (_DWORD*)(v1 + 3700);
        do
        {
            if (sub_424A50(v4, v3))
            {
                if (sub_424B50(v4))
                {
                    *v5 = 0;
                    sub_461360(v4);
                }
            }
            ++v4;
            ++v5;
        } while (v4 < 137);
        return sub_45ADF0(*(unsigned __int8*)(v1 + 2251));
    }
    return result;
}

//----- (0045D400) --------------------------------------------------------
int __cdecl sub_45D400(int a1)
{
    int v1; // edi
    int result; // eax
    unsigned __int8* v3; // ebp
    _DWORD* v4; // esi
    int v5; // eax
    _DWORD* i; // esi
    int v7; // eax

    v1 = *(_DWORD*)& byte_5D4594[2618908];
    result = sub_45ACA0(1);
    if (v1)
    {
        *(_DWORD*)(v1 + 4 * a1 + 4244) = 0;
        sub_461360(a1 + 74);
        v3 = &byte_587000[132124];
        if (*(_DWORD*)& byte_587000[132124])
        {
            do
            {
                v4 = *(_DWORD * *)v3;
                if (a1 == **(_DWORD * *)v3)
                {
                    v5 = v4[1];
                    for (i = v4 + 1; v5; ++i)
                    {
                        *(_DWORD*)(v1 + 4 * v5 + 4244) = 0;
                        sub_461360(*i + 74);
                        v5 = i[1];
                    }
                }
                v7 = *((_DWORD*)v3 + 1);
                v3 += 4;
            } while (v7);
        }
        result = sub_45ADF0(*(unsigned __int8*)(v1 + 2251));
    }
    return result;
}

//----- (0045D4A0) --------------------------------------------------------
char* __cdecl sub_45D4A0(int a1)
{
    char* result; // eax

    sub_45ACA0(1);
    sub_4611E0(a1, 0, 0);
    if (*(_DWORD*)& byte_5D4594[1047516])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1047516] + 4 * a1 + 3696) = 0;
    sub_461360(a1);
    result = sub_417040(*(int*)& byte_5D4594[2616328]);
    if (result)
        result = (char*)sub_45ADF0((unsigned __int8)result[2251]);
    return result;
}

//----- (0045D500) --------------------------------------------------------
int __cdecl sub_45D500(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1046864];
    if (a1)
    {
        if (*(_DWORD*)& byte_5D4594[1046864])
            result = nox_window_set_hidden(nox_win_unk1, 0);
    }
    else if (*(_DWORD*)& byte_5D4594[1046864])
    {
        result = sub_47A260();
        if (!result)
            result = nox_window_set_hidden(nox_win_unk1, 1);
    }
    return result;
}

//----- (0045D550) --------------------------------------------------------
_DWORD* __cdecl sub_45D550(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    if (a1)
        result = (_DWORD*)sub_46AA60(*(_DWORD * *)& byte_5D4594[1046952], a1, a1 + 1);
    return result;
}

//----- (0045D570) --------------------------------------------------------
int __cdecl sub_45D570(int a1, int a2)
{
    int result; // eax
    double v3; // st7
    int2 a4; // [esp+Ch] [ebp-10h]
    int2 a3; // [esp+14h] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[1047520];
    if (*(_DWORD*)& byte_5D4594[1047520] != 1)
    {
        sub_4606B0();
        *(_DWORD*)& byte_5D4594[1046612] = sub_45E180();
        if (a1 != 2 || (result = sub_424A50(a2, 86016)) == 0)
        {
            result = sub_4612D0(a2);
            if (result != 1)
            {
                if (a1 == 2 || a1 == 4)
                {
                    result = sub_461250();
                }
                else
                {
                    if (a1 != 3)
                        return result;
                    result = sub_4612A0();
                }
                *(_DWORD*)& byte_5D4594[1046852] = result;
                if (result != -1)
                {
                    *(_DWORD*)& byte_5D4594[1047520] = 1;
                    if (a1 == 2 || a1 == 3)
                    {
                        *(_DWORD*)& byte_5D4594[1046868] = 0;
                        *(_DWORD*)& byte_5D4594[1046872] = 0;
                    }
                    else
                    {
                        *(_DWORD*)& byte_5D4594[1046868] = 1;
                        *(_DWORD*)& byte_5D4594[1046872] = 1;
                    }
                    sub_45D550(&byte_5D4594[1046844]);
                    *(float*)& byte_5D4594[1046636] = (double) * (int*)& byte_5D4594[1046844];
                    *(float*)& byte_5D4594[1046640] = (double) * (int*)& byte_5D4594[1046848];
                    sub_46A9B0(*(_DWORD * *)& byte_5D4594[1046956], *(int*)& byte_5D4594[1046844], *(int*)& byte_5D4594[1046848]);
                    sub_461320(*(int*)& byte_5D4594[1046852], &byte_5D4594[1046668]);
                    a3.field_0 = 400;
                    a4.field_4 = 400;
                    *(_DWORD*)& byte_5D4594[1047524] = a2;
                    *(_DWORD*)& byte_5D4594[1046652] = a1 == 3;
                    *(_DWORD*)& byte_5D4594[1046676] = a1;
                    *(_DWORD*)& byte_587000[80828] = 1;
                    a3.field_4 = -500;
                    a4.field_0 = 350;
                    *(_DWORD*)& byte_5D4594[1046680] = 0;
                    sub_4BEDE0(
                        (int2*)& byte_5D4594[1046844],
                        (int2*)& byte_5D4594[1046668],
                        &a3,
                        &a4,
                        19,
                        0.0,
                        sub_45D7D0,
                        0);
                    *(_DWORD*)& byte_5D4594[1046628] = 0;
                    *(float*)& byte_5D4594[1046620] = *(float*)& byte_5D4594[1046692] - *(float*)& byte_5D4594[1046684];
                    *(float*)& byte_5D4594[1046624] = *(float*)& byte_5D4594[1046696] - *(float*)& byte_5D4594[1046688];
                    sub_509F20((float2*)& byte_5D4594[1046620]);
                    if (nox_win_width < 1000)
                    {
                        if (nox_win_width < 750)
                            v3 = 6.0;
                        else
                            v3 = 8.0;
                    }
                    else
                    {
                        v3 = 10.0;
                    }
                    *(float*)& byte_5D4594[1046620] = *(float*)& byte_5D4594[1046620] * v3;
                    *(float*)& byte_5D4594[1046624] = *(float*)& byte_5D4594[1046624] * v3;
                    nox_window_set_hidden(*(int*)& byte_5D4594[1046956], 0);
                    sub_46A8C0(*(int*)& byte_5D4594[1046956]);
                    if (sub_40A5C0(2048))
                        sub_57AF30(0, a1);
                    *(_DWORD*)& byte_5D4594[1046648] = sub_430B40_get_mouse_prev_seq();
                    if (!sub_40A5C0(2048) || sub_446360() == 1 || (result = sub_4DB1B0(), result == 1))
                        result = sub_45D870();
                }
            }
        }
    }
    return result;
}

//----- (0045D7D0) --------------------------------------------------------
int __cdecl sub_45D7D0(int* a1, int* a2)
{
    int result; // eax
    double v3; // st7

    result = *(_DWORD*)& byte_5D4594[1046680];
    if (*(int*)& byte_5D4594[1046680] < 20)
    {
        result = *(_DWORD*)& byte_5D4594[1046680] + 1;
        *(float*)& byte_5D4594[8 * result + 1046676] = (double)* a1;
        *(float*)& byte_5D4594[8 * result + 1046680] = (double)a1[1];
        *(float*)& byte_5D4594[8 * result + 1046684] = (double)* a2;
        v3 = (double)a2[1];
        *(_DWORD*)& byte_5D4594[1046680] = result;
        *(float*)& byte_5D4594[8 * result + 1046688] = v3;
    }
    return result;
}

//----- (0045D810) --------------------------------------------------------
int sub_45D810()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1047520];
    if (*(_DWORD*)& byte_5D4594[1047520])
    {
        *(_DWORD*)& byte_5D4594[1047520] = 0;
        nox_window_set_hidden(*(int*)& byte_5D4594[1046956], 1);
        *(_DWORD*)& byte_5D4594[1046648] = 0;
        sub_45E110(*(int*)& byte_5D4594[1046612]);
        result = sub_40A5C0(2048);
        if (result)
        {
            sub_57B0A0();
            result = sub_413A00(0);
        }
    }
    return result;
}

//----- (0045D870) --------------------------------------------------------
int sub_45D870()
{
    int result; // eax
    int v1; // esi
    int v3; // edi
    int v4; // ebx
    int v5; // ebp
    int v6; // eax
    int v7; // [esp-30h] [ebp-38h]
    char v8; // [esp-20h] [ebp-28h]
    int v9; // [esp+0h] [ebp-8h]
    int v10; // [esp+4h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1047520];
    if (*(_DWORD*)& byte_5D4594[1047520])
    {
        v1 = *(_DWORD*)& byte_5D4594[1046652] != 1 ? 0 : 3;
        v9 = ((int) * (_DWORD*)& byte_5D4594[1046668] - sub_419A70(*(float*)& byte_5D4594[1046636])) / 50;
        v10 = ((int) * (_DWORD*)& byte_5D4594[1046672] - sub_419A70(*(float*)& byte_5D4594[1046640])) / 50;
        v3 = sub_419A70(*(float*)& byte_5D4594[1046636]);
        v4 = sub_419A70(*(float*)& byte_5D4594[1046640]);
        v5 = 50;
        do
        {
            v8 = sub_415FF0(3, 4, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2483);
            v7 = v4 - sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2479);
            v6 = sub_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2478);
            sub_431540(v1, v3 + v6, v7, 0, 0, 1, v8, 0, 0, 1);
            v3 += v9;
            v4 += v10;
            --v5;
        } while (v5);
        sub_45DBE0(*(void**)& byte_5D4594[1046676], *(int*)& byte_5D4594[1047524], *(int*)& byte_5D4594[1046852]);
        result = sub_45D810();
    }
    return result;
}

//----- (0045D9B0) --------------------------------------------------------
int sub_45D9B0()
{
    return *(_DWORD*)& byte_5D4594[1047520];
}

//----- (0045D9C0) --------------------------------------------------------
BOOL sub_45D9C0()
{
    return *(_DWORD*)& byte_5D4594[1047916] != 0;
}

//----- (0045D9D0) --------------------------------------------------------
int __cdecl sub_45D9D0(int a1)
{
    if (*(_DWORD*)& byte_5D4594[1047916])
        return 0;
    *(_DWORD*)& byte_5D4594[1047916] = a1;
    byte_5D4594[1047920] = 0;
    sub_4160D0(5);
    *(_DWORD*)& byte_5D4594[1047928] = 0;
    *(_DWORD*)& byte_5D4594[1047924] = 0;
    return 1;
}

//----- (0045DA10) --------------------------------------------------------
int __cdecl sub_45DA10(int a1)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1047916])
        return 0;
    *(_DWORD*)& byte_5D4594[1047916] = a1;
    byte_5D4594[1047920] = 0;
    sub_4160D0(5);
    result = 1;
    *(_DWORD*)& byte_5D4594[1047924] = 1;
    return result;
}

//----- (0045DA50) --------------------------------------------------------
void __cdecl sub_45DA50(int a1)
{
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        if (!sub_4372B0())
        {
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
            {
                sub_45DB20(
                    (char*)(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) + 8 * a1),
                    1,
                    *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) + 8 * a1 + 4) & 1);
                sub_45DAD0(a1);
            }
            else
            {
                sub_45DAF0(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) + 8 * a1));
                sub_45DAD0(a1);
            }
        }
    }
}

//----- (0045DAD0) --------------------------------------------------------
void __cdecl sub_45DAD0(int a1)
{
    *(_DWORD*)& byte_587000[133484] = a1;
    *(_DWORD*)& byte_5D4594[1049540] = *(_DWORD*)& byte_5D4594[2598000];
}

//----- (0045DAF0) --------------------------------------------------------
int __cdecl sub_45DAF0(int a1)
{
    int result; // eax
    __int16 v3; // [esp+0h] [ebp-2h]

    result = sub_477600();
    if (!result)
    {
        result = a1;
        if (a1)
        {
            HIBYTE(v3) = a1;
            LOBYTE(v3) = 122;
            result = sub_40EBC0(31, 0, &v3, 2);
        }
    }
    return result;
}

//----- (0045DB20) --------------------------------------------------------
int __cdecl sub_45DB20(char* a1, int a2, char a3)
{
    int result; // eax
    int v4; // ecx
    char* v5; // eax
    char v6[22]; // [esp+0h] [ebp-18h]

    result = sub_477600();
    if (!result && *(_DWORD*)a1)
    {
        v4 = 0;
        v6[0] = 121;
        v5 = &v6[1];
        do
        {
            if (v4 >= a2)
                * (_DWORD*)v5 = 0;
            else
                *(_DWORD*)v5 = *(_DWORD*)& v5[a1 - &v6[1]];
            ++v4;
            v5 += 4;
        } while (v4 < 5);
        v6[21] = a3;
        result = sub_40EBC0(31, 0, v6, 22);
    }
    return result;
}

//----- (0045DB90) --------------------------------------------------------
int sub_45DB90()
{
    int result; // eax

    result = 0;
    memset(&byte_5D4594[1049544], 0, 0x88u);
    byte_5D4594[1049680] = 0;
    return result;
}

//----- (0045DBB0) --------------------------------------------------------
void sub_45DBB0()
{
    if (*(_DWORD*)& byte_5D4594[1047916])
    {
        sub_45DB20((char*)& byte_5D4594[1047916], 1, byte_5D4594[1047924]);
        *(_DWORD*)& byte_5D4594[1047916] = 0;
    }
}

//----- (0045DBE0) --------------------------------------------------------
void* __cdecl sub_45DBE0(void* a1, int a2, int a3)
{
    void* result; // eax

    sub_45DC40(*(int*)& byte_587000[133480], a2, a3);
    result = a1;
    if (a1 == (void*)2)
    {
        if (a2 && (result = (void*)sub_424A50(a2, 1536)) != 0)
        {
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) + 8 * a3 + 4) = 1;
        }
        else
        {
            result = *(void**)& byte_587000[133480];
            *(_BYTE*)(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) + 8 * a3 + 4) = 0;
        }
    }
    return result;
}

//----- (0045DC40) --------------------------------------------------------
_DWORD* __cdecl sub_45DC40(int a1, int a2, int a3)
{
    wchar_t* v3; // eax
    _DWORD* result; // eax

    *(_DWORD*)(*(_DWORD*)(a1 + 204) + 8 * a3) = a2;
    if (*(_DWORD*)(a1 + 4 * a3 + 212))
    {
        v3 = (wchar_t*)sub_424930(a2);
        sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 4 * a3 + 212) + 36), v3);
    }
    result = *(_DWORD * *)& byte_5D4594[2618908];
    if (*(_DWORD*)& byte_5D4594[2618908])
        result = sub_452D80(794, 100);
    return result;
}

//----- (0045DCA0) --------------------------------------------------------
int __cdecl sub_45DCA0(int a1, char a2, int a3, int a4, int* a5)
{
    unsigned __int16 v5; // si
    int v6; // edi
    int* v7; // esi
    int v8; // eax
    int v9; // ebx
    int v10; // ecx
    int v11; // edi
    unsigned __int16 v13; // [esp+10h] [ebp-8h]
    unsigned __int16 v14; // [esp+14h] [ebp-4h]

    v5 = 0;
    v14 = 137;
    v13 = 0;
    if ((wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1048148]) || !sub_45DEB0((int*)& byte_5D4594[1047940], a1, a3, a4))
        && a5 != (int*)& byte_5D4594[1047940])
    {
        v6 = *(_DWORD*)& byte_5D4594[1049476] != 0 ? 0 : 4;
        v7 = (int*)& byte_5D4594[256 * v6 + 1048196];
        while (1)
        {
            v8 = sub_45DE60((int)v7, a3, a4);
            v9 = v8;
            if (v8 >= 0)
            {
                v10 = v7[51];
                v14 = *(_WORD*)(v10 + 8 * v8);
                v13 = *(unsigned __int8*)(v10 + 8 * v8 + 4);
            }
            if (sub_45DEB0(v7, a1, a3, a4))
                break;
            v7 += 64;
            ++v6;
            if ((int)v7 >= (int)& byte_5D4594[1049476])
                goto LABEL_16;
        }
        if (sub_477670() == 1)
        {
            v11 = v6 << 8;
            *(_BYTE*)(*(_DWORD*)& byte_5D4594[v11 + 1048400] + 8 * v9 + 4) = sub_424A50(a1, 1536);
        }
        else
        {
            v11 = v6 << 8;
            *(_BYTE*)(*(_DWORD*)& byte_5D4594[v11 + 1048400] + 8 * v9 + 4) = a2;
        }
        sub_45DDF0((int)& byte_5D4594[v11 + 1048196]);
    LABEL_16:
        v5 = v13;
    }
    return v5 | (v14 << 16);
}

//----- (0045DDF0) --------------------------------------------------------
int __cdecl sub_45DDF0(int a1)
{
    int i; // esi
    int result; // eax

    for (i = 0; i < 5; ++i)
        result = sub_45DE10(i, a1);
    return result;
}

//----- (0045DE10) --------------------------------------------------------
int __cdecl sub_45DE10(int a1, int a2)
{
    int v2; // eax
    char v3; // bl
    _DWORD* v4; // eax
    int result; // eax

    v2 = *(_DWORD*)(a2 + 204);
    v3 = *(_BYTE*)(v2 + 8 * a1 + 4);
    v4 = (_DWORD*)(v2 + 8 * a1);
    if (v3 & 1 && *v4)
        result = sub_46AE10(*(_DWORD*)(a2 + 4 * a1 + 232), 1);
    else
        result = sub_46AE10(*(_DWORD*)(a2 + 4 * a1 + 232), 0);
    return result;
}

//----- (0045DE60) --------------------------------------------------------
int __cdecl sub_45DE60(int a1, int a2, int a3)
{
    int v3; // esi
    _DWORD** i; // edi

    v3 = 0;
    for (i = (_DWORD * *)(a1 + 212); !sub_46AAB0(*i, a2, a3); ++i)
    {
        if (++v3 >= 5)
            return -1;
    }
    return v3;
}

//----- (0045DEB0) --------------------------------------------------------
int __cdecl sub_45DEB0(int* a1, int a2, int a3, int a4)
{
    int v4; // ebx
    wchar_t* v5; // eax
    _DWORD* v6; // ecx
    int v7; // eax

    v4 = sub_45DE60((int)a1, a3, a4);
    if (v4 >= 0)
    {
        if (a1 != (int*)& byte_5D4594[1047940])
        {
        LABEL_8:
            sub_45DC40((int)a1, a2, v4);
            return 1;
        }
        if (sub_424BF0(a2))
        {
            v6 = (_DWORD*)a1[51];
            v7 = 0;
            while (*v6 != a2)
            {
                ++v7;
                v6 += 2;
                if (v7 >= 3)
                    goto LABEL_8;
            }
            v5 = loadString_sub_40F1D0((char*)& byte_587000[133772], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 504);
        }
        else
        {
            v5 = loadString_sub_40F1D0((char*)& byte_587000[133712], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 496);
        }
        sub_445490(v5);
        sub_452D80(925, 100);
    }
    return 0;
}

//----- (0045DF60) --------------------------------------------------------
int __cdecl sub_45DF60(int a1, char a2)
{
    int result; // eax

    if (a1)
    {
        sub_452D80(766, 100);
        if (!(a2 & 1) || sub_424A50(a1, 0x2000))
        {
            *(_DWORD*)& byte_5D4594[1047556] = a1;
            *(_DWORD*)& byte_5D4594[1047928] = 1;
            result = 0;
        }
        else
        {
            sub_45DA10(a1);
            result = 1;
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1047928] = 0;
        result = 0;
    }
    return result;
}

//----- (0045DFC0) --------------------------------------------------------
int __cdecl sub_45DFC0(int a1)
{
    int result; // eax
    int v2; // esi
    int v3; // eax

    if (a1)
    {
        v2 = *(_DWORD*)& byte_5D4594[24 * a1 + 1047768];
        if (v2)
        {
            *(_DWORD*)& byte_5D4594[1047932] = 0;
            *(_DWORD*)& byte_5D4594[1047936] = 0;
            sub_45DAF0(a1);
            sub_452D80(766, 100);
            result = v2;
        }
        else
        {
            v3 = *(_DWORD*)& byte_5D4594[24 * a1 + 1047764];
            *(_DWORD*)& byte_5D4594[1047932] = 1;
            *(_DWORD*)& byte_5D4594[1047936] = v3;
            sub_452D80(766, 100);
            result = 0;
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1047932] = 0;
        *(_DWORD*)& byte_5D4594[1047936] = 0;
        result = 0;
    }
    return result;
}

//----- (0045E040) --------------------------------------------------------
_DWORD* sub_45E040()
{
    _DWORD** v0; // edx
    _DWORD* v1; // ecx
    int v2; // edi
    int i; // eax
    _DWORD* result; // eax
    wchar_t* v5; // eax
    int* v6; // ecx
    int v7; // esi
    char v8; // al
    int v9[5]; // [esp+8h] [ebp-14h]

    v0 = *(_DWORD * **)& byte_5D4594[1048144];
    v1 = *(_DWORD * *)& byte_5D4594[1048144];
    v2 = 0;
    for (i = 0; i < 3; ++i)
    {
        if (*v1)
            break;
        v1 += 2;
    }
    if (i == 3)
    {
        result = *(_DWORD * *)& byte_5D4594[2618908];
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 3832))
            {
                v5 = loadString_sub_40F1D0((char*)& byte_587000[133828], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1145);
                sub_445490(v5);
                result = sub_452D80(925, 100);
            }
        }
    }
    else
    {
        byte_5D4594[1049488] = 0;
        v6 = v9;
        v7 = 3;
        do
        {
            result = *v0;
            if (*v0)
            {
                *v6 = (int)result;
                ++v2;
                ++v6;
            }
            v0 += 2;
            --v7;
        } while (v7);
        if (v2 < 5)
        {
            v8 = byte_5D4594[1047924];
            v9[v2] = 34;
            result = (_DWORD*)sub_45DB20((char*)v9, v2 + 1, v8);
            *(_DWORD*)& byte_5D4594[1047916] = 0;
            *(_DWORD*)& byte_5D4594[1049480] = 0;
        }
    }
    return result;
}
// 45E040: using guessed type int var_14[5];

//----- (0045E110) --------------------------------------------------------
int __cdecl sub_45E110(int a1)
{
    int result; // eax

    result = a1;
    if (a1 >= 0 && a1 < 5 && !*(_DWORD*)& byte_5D4594[1049476] && !*(_DWORD*)& byte_5D4594[1049496])
    {
        *(_BYTE*)(*(_DWORD*)& byte_587000[133480] + 200) = a1;
        *(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) = *(_DWORD*)& byte_587000[133480]
            + 40
            * *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
        if (*(_DWORD*)& byte_5D4594[2618908])
            sub_452D80(798, 100);
        result = sub_45DDF0(*(int*)& byte_587000[133480]);
    }
    return result;
}

//----- (0045E180) --------------------------------------------------------
int sub_45E180()
{
    return *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
}

//----- (0045E190) --------------------------------------------------------
int sub_45E190()
{
    int v0; // ebp
    int v1; // ebx
    int v2; // edi
    unsigned __int8* v4; // esi
    char* v5; // eax
    char* v6; // eax
    char* v7; // eax
    char* v8; // eax
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    char* v11; // eax
    char* v12; // eax
    char* v13; // eax
    char* v14; // eax
    wchar_t* v15; // eax
    wchar_t* v16; // eax
    char* v17; // eax
    char* v18; // eax
    char* v19; // eax
    char* v20; // eax
    char* v21; // eax
    int v22; // eax
    _DWORD* v23; // eax
    wchar_t* v24; // esi
    char* v25; // eax
    wchar_t* v26; // eax
    wchar_t* v27; // esi
    char* v28; // eax
    wchar_t* v29; // eax
    char* v30; // eax
    char* v31; // eax
    char* v32; // eax
    char* v33; // eax
    char* v34; // eax
    char* v35; // eax
    wchar_t* v36; // eax
    wchar_t* v37; // esi
    char* v38; // eax
    wchar_t* v39; // eax
    wchar_t* v40; // esi
    char* v41; // eax
    wchar_t* v42; // eax
    wchar_t* v43; // esi
    char* v44; // eax
    wchar_t* v45; // eax
    char* v46; // eax
    _DWORD* v47; // eax
    int v48; // eax
    int v49; // ecx
    int* v50; // ebx
    int v51; // edi
    int v52; // ecx
    _DWORD* v53; // esi
    char* v54; // eax
    char* v55; // eax
    char* v56; // eax
    char* v57; // eax
    _DWORD* v58; // esi
    _DWORD* v59; // esi
    int v60; // eax
    bool v61; // zf
    int j; // eax
    int v63; // [esp-8h] [ebp-58h]
    unsigned __int16 v64; // [esp+Ch] [ebp-44h]
    int v65; // [esp+10h] [ebp-40h]
    int v66; // [esp+14h] [ebp-3Ch]
    int v67; // [esp+18h] [ebp-38h]
    int v68; // [esp+20h] [ebp-30h]
    int v69; // [esp+20h] [ebp-30h]
    int i; // [esp+24h] [ebp-2Ch]
    unsigned __int8* v71; // [esp+28h] [ebp-28h]
    char v72[32]; // [esp+30h] [ebp-20h]

    v0 = 0;
    *(_DWORD*)& byte_5D4594[1047916] = 0;
    byte_5D4594[1047920] = 0;
    sub_416170(5);
    *(_DWORD*)& byte_5D4594[1047924] = 0;
    *(_DWORD*)& byte_5D4594[1047928] = 0;
    *(_DWORD*)& byte_5D4594[1049480] = 0;
    byte_5D4594[1049488] = 0;
    v68 = sub_43F320(0);
    *(_DWORD*)& byte_5D4594[1047548] = (nox_win_width - 320) / 2;
    *(_DWORD*)& byte_5D4594[1047552] = nox_win_height - 74;
    *(_DWORD*)& byte_5D4594[1049684] = sub_43F360((char*)& byte_587000[133840]);
    *(_DWORD*)& byte_587000[133656] = *(_DWORD*)& byte_5D4594[1047548];
    v1 = *(_DWORD*)& byte_5D4594[1047548] + 69;
    *(_DWORD*)& byte_587000[133660] = *(_DWORD*)& byte_5D4594[1047552] - 17;
    v2 = *(_DWORD*)& byte_5D4594[1047552] + 32;
    *(_DWORD*)& byte_587000[133664] = *(_DWORD*)& byte_5D4594[1047548] + 320;
    *(_DWORD*)& byte_587000[133668] = nox_win_height;
    if (!*(_DWORD*)& byte_5D4594[2618908])
        return 0;
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
        sub_4601F0(
            *(int*)& byte_587000[133480],
            *(_DWORD*)& byte_5D4594[1047548] + 69,
            *(_DWORD*)& byte_5D4594[1047552] + 32,
            5,
            0,
            sub_45EF50,
            sub_45FDE0);
    else
        sub_4601F0(
            *(int*)& byte_587000[133480],
            *(_DWORD*)& byte_5D4594[1047548] + 69,
            *(_DWORD*)& byte_5D4594[1047552] + 32,
            5,
            0,
            sub_45EF50,
            sub_45FBD0);
    v4 = &byte_5D4594[1048964];
    do
    {
        v2 -= 60;
        sub_4601F0((int)v4, v1, v2, 5, 0, sub_45EF50, sub_45FDE0);
        nox_window_set_hidden(*((_DWORD*)v4 + 52), 1);
        v4[200] = 0;
        *((_DWORD*)v4 + 51) = v4;
        v4 -= 256;
    } while ((int)v4 >= (int)& byte_5D4594[1048196]);
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
    {
        *(_DWORD*)& byte_5D4594[1049504] = nox_window_new(
            0,
            1160,
            *(_DWORD*)& byte_5D4594[1047548] + 260,
            *(int*)& byte_5D4594[1047552],
            45,
            66,
            0);
        sub_46AE40(*(int*)& byte_5D4594[1049504], -263, 0);
        *(_DWORD*)& byte_5D4594[1049536] = nox_win_height - 74;
        sub_46B300(*(int*)& byte_5D4594[1049504], sub_45F8D0);
        *(_DWORD*)& byte_5D4594[1049520] = nox_window_new(*(int*)& byte_5D4594[1049504], 1032, 9, 33, 32, 32, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1049520], sub_45F7A0, sub_460000, 0);
        *(_DWORD*)& byte_5D4594[1049500] = nox_window_new(*(int*)& byte_5D4594[1049504], 1160, 0, 19, 12, 12, 0);
        sub_46B300(*(int*)& byte_5D4594[1049500], sub_45FB90);
        sub_46AE40(*(int*)& byte_5D4594[1049500], -265, -23);
        v5 = sub_42F970("QuickBarTrapButton");
        sub_46AE60(*(int*)& byte_5D4594[1049500], (int)v5);
        v6 = sub_42F970("QuickBarTrapButtonLit");
        sub_46AEA0(*(int*)& byte_5D4594[1049500], (int)v6);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1049504] = nox_window_new(
            0,
            1672,
            *(_DWORD*)& byte_5D4594[1047548] + 260,
            *(int*)& byte_5D4594[1047552],
            45,
            66,
            0);
        sub_46AE40(*(int*)& byte_5D4594[1049504], -263, 0);
        *(_DWORD*)& byte_5D4594[1049536] = nox_win_height - 74;
        sub_46B300(*(int*)& byte_5D4594[1049504], sub_45F8D0);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
    {
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) == 1)
        {
            if ((!*(_DWORD*)& byte_5D4594[2618908] || !*(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 3832))
                && (!sub_40A5C0(0x2000) || sub_40A5C0(4096) || sub_4D6F50() || sub_4D6F70()))
            {
                v17 = sub_42F970("QuickBarWarriorRight");
                sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v17);
                v18 = sub_42F970("QuickBarWarriorRight");
                sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v18);
                sub_46AD80(*(int*)& byte_5D4594[1049520], 8);
                sub_46AD80(*(int*)& byte_5D4594[1049500], 8);
                sub_46B340(*(int*)& byte_5D4594[1049500], sub_45EF30);
            }
            else
            {
                v13 = sub_42F970("QuickBarTrap");
                sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v13);
                v14 = sub_42F970("QuickBarTrapHit");
                sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v14);
                v15 = loadString_sub_40F1D0((char*)& byte_587000[134012], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1805);
                sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049520] + 36), v15);
                sub_46AD60(*(int*)& byte_5D4594[1049520], 8);
                v16 = loadString_sub_40F1D0((char*)& byte_587000[134068], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1808);
                sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049500] + 36), v16);
                sub_46AD60(*(int*)& byte_5D4594[1049500], 8);
            }
        }
        else if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) == 2)
        {
            if ((!*(_DWORD*)& byte_5D4594[2618908] || !*(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 3832))
                && (!sub_40A5C0(0x2000) || sub_40A5C0(4096) || sub_4D6F50() || sub_4D6F70()))
            {
                v11 = sub_42F970("QuickBarWarriorRight");
                sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v11);
                v12 = sub_42F970("QuickBarWarriorRight");
                sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v12);
                sub_46AD80(*(int*)& byte_5D4594[1049520], 8);
                sub_46AD80(*(int*)& byte_5D4594[1049500], 8);
                sub_46B340(*(int*)& byte_5D4594[1049500], sub_45EF30);
            }
            else
            {
                v7 = sub_42F970("QuickBarBomber");
                sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v7);
                v8 = sub_42F970("QuickBarBomberHit");
                sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v8);
                v9 = loadString_sub_40F1D0((char*)& byte_587000[134216], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1838);
                sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049520] + 36), v9);
                sub_46AD60(*(int*)& byte_5D4594[1049520], 8);
                v10 = loadString_sub_40F1D0((char*)& byte_587000[134276], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1841);
                sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049500] + 36), v10);
                sub_46AD60(*(int*)& byte_5D4594[1049500], 8);
            }
        }
    }
    else
    {
        v19 = sub_42F970("QuickBarWarriorRight");
        sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v19);
        v20 = sub_42F970("QuickBarWarriorRight");
        sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v20);
    }
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
    {
        sub_4601F0(
            (int)& byte_5D4594[1047940],
            *(_DWORD*)& byte_5D4594[1047548] + 122,
            *(_DWORD*)& byte_5D4594[1047552] - 17,
            3,
            21,
            sub_45EF50,
            sub_45FDE0);
        v21 = sub_42F970("QuickBarTrapTray");
        sub_46AE60(*(int*)& byte_5D4594[1048148], (int)v21);
        sub_46AE40(*(int*)& byte_5D4594[1048148], -40, -20);
        v22 = *(_DWORD*)& byte_5D4594[1048192];
        LOBYTE(v22) = byte_5D4594[1048192] | 1;
        *(_DWORD*)& byte_5D4594[1048192] = v22;
        nox_window_set_hidden(*(int*)& byte_5D4594[1048148], 1);
        *(_DWORD*)& byte_5D4594[1049484] = 0;
        v23 = nox_window_new(*(int*)& byte_5D4594[1048148], 1032, 20, -7, 110, v68, 0);
        nox_window_set_all_funcs(v23, 0, sub_45FAC0, 0);
        v24 = (wchar_t*)nox_window_new(*(int*)& byte_5D4594[1048148], 1032, 15, 12, 10, 14, 0);
        sub_46AE60((int)v24, 0);
        v25 = sub_42F970("QuickBarTrapTrayUpLit");
        sub_46AEA0((int)v24, (int)v25);
        nox_window_set_all_funcs(v24, sub_45F630, sub_45F6F0, 0);
        sub_46AE40((int)v24, -55, -32);
        v26 = loadString_sub_40F1D0((char*)& byte_587000[134432], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1883);
        sub_46B000(v24 + 18, v26);
        *((_DWORD*)v24 + 92) = 3;
        v27 = (wchar_t*)nox_window_new(*(int*)& byte_5D4594[1048148], 1032, 15, 32, 10, 14, 0);
        sub_46AE60((int)v27, 0);
        v28 = sub_42F970("QuickBarTrapTrayDownLit");
        sub_46AEA0((int)v27, (int)v28);
        nox_window_set_all_funcs(v27, sub_45F630, sub_45F6F0, 0);
        sub_46AE40((int)v27, -55, -52);
        v29 = loadString_sub_40F1D0((char*)& byte_587000[134512], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1892);
        sub_46B000(v27 + 18, v29);
        *((_DWORD*)v27 + 92) = 4;
        *(_DWORD*)& byte_5D4594[1049508] = nox_window_new(
            0,
            1032,
            *(_DWORD*)& byte_5D4594[1047548] - 1,
            *(_DWORD*)& byte_5D4594[1047552] + 26,
            61,
            48,
            0);
        sub_46AE40(*(int*)& byte_5D4594[1049508], 1, -26);
        v30 = sub_42F970("QuickBarSpellSetBase");
        sub_46AE60(*(int*)& byte_5D4594[1049508], (int)v30);
        v31 = sub_42F970("QuickBarSpellSetBase");
        sub_46AEA0(*(int*)& byte_5D4594[1049508], (int)v31);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049508] + 368) = 5;
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1049508], sub_45F8D0, sub_45F6F0, 0);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1049508] = nox_window_new(
            0,
            1032,
            *(_DWORD*)& byte_5D4594[1047548] - 1,
            *(_DWORD*)& byte_5D4594[1047552] + 26,
            61,
            48,
            0);
        sub_46AE40(*(int*)& byte_5D4594[1049508], 1, -26);
        v32 = sub_42F970("QuickBarWarriorLeft");
        sub_46AE60(*(int*)& byte_5D4594[1049508], (int)v32);
        v33 = sub_42F970("QuickBarWarriorLeft");
        sub_46AEA0(*(int*)& byte_5D4594[1049508], (int)v33);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1049508], sub_45F8D0, sub_45F6F0, 0);
    }
    *(_DWORD*)& byte_5D4594[1049524] = nox_window_new(*(int*)& byte_5D4594[1049508], 1160, 0, 9, 29, 30, 0);
    v34 = sub_42F970("SpellbookButton");
    sub_46AE60(*(int*)& byte_5D4594[1049524], (int)v34);
    v35 = sub_42F970("SpellbookButtonLit");
    sub_46AEA0(*(int*)& byte_5D4594[1049524], (int)v35);
    *(_DWORD*)& byte_5D4594[1049528] = nox_window_new(*(int*)& byte_5D4594[1049524], 1064, 1, 2, 28, 28, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1049528], sub_45F450, sub_45EF30, sub_45F3F0);
    v36 = loadString_sub_40F1D0((char*)& byte_587000[134692], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1931);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049528] + 36), v36);
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
    {
        v37 = (wchar_t*)nox_window_new(*(int*)& byte_5D4594[1049508], 1032, 30, 0, 15, 19, 0);
        sub_46AE40((int)v37, -29, -26);
        sub_46AE60((int)v37, 0);
        v38 = sub_42F970("QuickBarSpellSetUpLit");
        sub_46AEA0((int)v37, (int)v38);
        nox_window_set_all_funcs(v37, sub_45F630, sub_45F6F0, 0);
        *((_DWORD*)v37 + 92) = 0;
        v39 = loadString_sub_40F1D0((char*)& byte_587000[134772], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1943);
        sub_46B000(v37 + 18, v39);
        v40 = (wchar_t*)nox_window_new(*(int*)& byte_5D4594[1049508], 1032, 30, 29, 15, 19, 0);
        sub_46AE40((int)v40, -29, -55);
        sub_46AE60((int)v40, 0);
        v41 = sub_42F970("QuickBarSpellSetDownLit");
        sub_46AEA0((int)v40, (int)v41);
        nox_window_set_all_funcs(v40, sub_45F630, sub_45F6F0, 0);
        *((_DWORD*)v40 + 92) = 1;
        v42 = loadString_sub_40F1D0((char*)& byte_587000[134856], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1953);
        sub_46B000(v40 + 18, v42);
        v43 = (wchar_t*)nox_window_new(*(int*)& byte_5D4594[1049508], 1032, 48, 16, 13, 17, 0);
        sub_46AE40((int)v43, -47, -42);
        sub_46AE60((int)v43, 0);
        v44 = sub_42F970("QuickBarSpellSetMaxLit");
        sub_46AEA0((int)v43, (int)v44);
        nox_window_set_all_funcs(v43, sub_45F630, sub_45F6F0, 0);
        *((_DWORD*)v43 + 92) = 2;
        v45 = loadString_sub_40F1D0((char*)& byte_587000[134940], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1963);
        sub_46B000(v43 + 18, v45);
        *(_DWORD*)& byte_5D4594[1049516] = nox_window_new(0, 1032, 0, 0, 1, 1, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1049516], sub_45EF40, sub_45F8F0, 0);
        *(_DWORD*)& byte_5D4594[1049512] = nox_window_new(
            0,
            1152,
            *(int*)& byte_5D4594[1047548],
            *(int*)& byte_5D4594[1047552],
            2,
            2,
            0);
        v46 = sub_42F970("QuickBarTitle");
        sub_46AE60(*(int*)& byte_5D4594[1049512], (int)v46);
        v47 = nox_window_new(*(int*)& byte_5D4594[1049512], 8, 115, 6, 101, 14, 0);
        nox_window_set_all_funcs(v47, 0, sub_45F9B0, 0);
    }
    v64 = 0;
    while (1)
    {
        v65 = 0;
        v66 = 0;
        v69 = 5;
        v48 = v64 << 8;
        v49 = *(_DWORD*)& byte_5D4594[v48 + 1048404];
        v71 = &byte_5D4594[v48 + 1048196];
        v50 = (int*)& byte_5D4594[v48 + 1048428];
        v51 = *(_DWORD*)(v49 + 16) + 10;
        v52 = *(_DWORD*)(v49 + 20) + 5;
        v67 = v51;
        for (i = v52; ; v52 = i)
        {
            v53 = nox_window_new(0, 1160, v51, v52, 30, 10, 0);
            v63 = v0 + 1;
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
            {
                nox_sprintf(v72, "QuickBarNugget%d", v63);
                v54 = sub_42F970(v72);
                sub_46AE60((int)v53, (int)v54);
                *(_DWORD*)& v72[strlen(v72)] = *(_DWORD*)& byte_587000[134996];
                v55 = sub_42F970(v72);
                sub_46AEA0((int)v53, (int)v55);
                v51 = v67;
            }
            else
            {
                nox_sprintf(v72, "QuickBarWarriorNugget%d", v63);
                v56 = sub_42F970(v72);
                sub_46AE60((int)v53, (int)v56);
                v57 = sub_42F970(v72);
                sub_46AEA0((int)v53, (int)v57);
            }
            sub_46AE40((int)v53, -70 - v65, -23);
            nox_window_set_all_funcs(v53, sub_45F8D0, 0, 0);
            *v50 = (int)v53;
            sub_45DE10(v0, (int)v71);
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
            {
                v58 = nox_window_new(*v50, 1032, 12, 0, 10, 10, 0);
                nox_window_set_all_funcs(v58, sub_45F520, sub_45EF30, sub_45F480);
                v58[92] = v0 | (v64 << 16);
            }
            if (v64 == 4)
            {
                v59 = nox_window_new(*(_DWORD*)& byte_5D4594[v66 + 1049452], 1032, 13, 39, 10, 10, 0);
                nox_window_set_all_funcs(v59, 0, sub_45F5D0, 0);
                v59[92] = v0++;
            }
            else
            {
                nox_window_set_hidden(*v50, 1);
            }
            ++v50;
            v60 = *(_DWORD*)& byte_587000[v66 + 133488];
            v51 += v60;
            v67 = v51;
            v61 = v69 == 1;
            v65 += v60;
            v66 += 4;
            --v69;
            if (v61)
                break;
        }
        if (++v64 >= 5u)
            break;
        v0 = 0;
    }
    if (!*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
    {
        for (j = 0; j < 120; j += 24)
        {
            *(_DWORD*)& byte_5D4594[j + 1047788] = *(_DWORD*)& byte_587000[j + 133536];
            *(_DWORD*)& byte_5D4594[j + 1047792] = *(_DWORD*)& byte_587000[j + 133540];
            *(_DWORD*)& byte_5D4594[j + 1047796] = *(_DWORD*)& byte_587000[j + 133544];
            *(_DWORD*)& byte_5D4594[j + 1047800] = *(_DWORD*)& byte_587000[j + 133548];
            *(_DWORD*)& byte_5D4594[j + 1047804] = *(_DWORD*)& byte_587000[j + 133552];
            *(_DWORD*)& byte_5D4594[j + 1047808] = 0;
        }
    }
    sub_45E110(0);
    return 1;
}

//----- (0045EF30) --------------------------------------------------------
int sub_45EF30()
{
    return 1;
}

//----- (0045EF40) --------------------------------------------------------
int sub_45EF40()
{
    return 0;
}

//----- (0045EF50) --------------------------------------------------------
int __cdecl sub_45EF50(int a1, int a2, unsigned int a3)
{
    int* v3; // esi
    int v4; // ebx
    _DWORD* v5; // eax
    unsigned __int16 v7; // di
    int v8; // ebp
    _DWORD* v9; // ecx
    int v10; // eax
    int v11; // ecx
    unsigned int v12; // eax
    int v13; // eax
    int2 v14; // [esp+10h] [ebp-8h]
    int v15; // [esp+24h] [ebp+Ch]

    v3 = *(int**)(a1 + 368);
    if (!*(_DWORD*)& byte_5D4594[2614252] || (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) != 2)
    {
        v4 = 0;
        v5 = v3 + 53;
        do
        {
            if (a1 == *v5)
                break;
            ++v4;
            ++v5;
        } while (v4 < 5);
        if (v4 == 5)
            return 0;
        v7 = a3;
        v8 = 8 * v4;
        v15 = a3 >> 16;
        v9 = (_DWORD*)(8 * v4 + v3[51]);
        v14.field_0 = 8 * v4 + v3[51];
        switch (a2)
        {
        case 5:
            if (!*v9
                || *(_DWORD*)& byte_5D4594[1047928]
                || *(_DWORD*)& byte_5D4594[1047932]
                || sub_57AF20()
                || *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) && !sub_424B70(*(_DWORD*)v14.field_0))
            {
                return 1;
            }
            sub_46ADC0(a1);
            sub_477640(*(_DWORD*)v14.field_0, 2);
            *(_DWORD*)& byte_5D4594[1049692] = v3;
            *(_DWORD*)& byte_5D4594[1049696] = v3[51];
            sub_452D80(793, 100);
            return 1;
        case 6:
        case 7:
            if (!sub_46AE00())
                return 1;
            if (sub_57AF20())
                goto LABEL_51;
            v10 = sub_45DE60((int)v3, v7, v15);
            if (*(_DWORD*)& byte_5D4594[1047932])
            {
                if (v10 < 0)
                    sub_4611B0();
                *(_DWORD*)& byte_5D4594[1047932] = 0;
                goto LABEL_51;
            }
            if (*(_DWORD*)& byte_5D4594[1047928])
            {
                if (v10 < 0)
                    sub_45D9D0(*(int*)& byte_5D4594[1047556]);
                *(_DWORD*)& byte_5D4594[1047928] = 0;
                goto LABEL_52;
            }
            if (v10 < 0)
            {
                v12 = sub_45DCA0(*(_DWORD*)(v8 + v3[51]), *(_BYTE*)(v8 + v3[51] + 4), v7, v15, v3);
                if (v12 >> 16 == 137)
                {
                    v14.field_0 = v7;
                    v14.field_4 = v15;
                    v13 = sub_4281F0(&v14, (int4*)& byte_587000[133656]);
                    if (v13 || *(_DWORD*)& byte_5D4594[1049696] && *(_DWORD*)& byte_5D4594[1049696] != v3[51])
                        goto LABEL_51;
                    *(_DWORD*)(v3[51] + 8 * v4) = 0;
                    *(_BYTE*)(v3[51] + v8 + 4) = 0;
                    if (v3 == (int*)& byte_5D4594[1047940])
                        goto LABEL_51;
                }
                else
                {
                    *(_DWORD*)(v3[51] + 8 * v4) = v12 >> 16;
                    *(_BYTE*)(v3[51] + v8 + 4) = v12;
                    if (v3 == (int*)& byte_5D4594[1047940])
                        goto LABEL_51;
                }
            }
            else
            {
                if (*(_DWORD*)& byte_5D4594[1049692])
                {
                    if (*(int**)& byte_5D4594[1049692] == v3
                        && *(_DWORD*)& byte_5D4594[1049692] == *(_DWORD*)& byte_587000[133480])
                    {
                        if (*(_DWORD*)& byte_5D4594[1049696])
                        {
                            v11 = v3[51];
                            if (*(_DWORD*)& byte_5D4594[1049696] != v11)
                            {
                                sub_45F390(*(int*)& byte_5D4594[1049696], v11, v4, v10);
                                sub_452D80(794, 100);
                                sub_45DDF0((int)v3);
                                goto LABEL_51;
                            }
                        }
                    }
                }
                if (v10 == v4)
                {
                    *(_DWORD*)& byte_5D4594[1049532] = a1;
                    if (!*(_DWORD*)& byte_5D4594[2618908] || v3 == (int*)& byte_5D4594[1047940])
                        goto LABEL_53;
                    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
                    {
                        if (sub_424B70(*(_DWORD*)v14.field_0))
                        {
                            sub_45DF60(*(_DWORD*)v14.field_0, *(_BYTE*)(v14.field_0 + 4));
                            sub_45DAD0(v4);
                        }
                    }
                    else
                    {
                        sub_45DFC0(*(_DWORD*)v14.field_0);
                        sub_45DAD0(v4);
                    }
                LABEL_51:
                    if (*(_DWORD*)& byte_5D4594[1047928])
                        goto LABEL_54;
                LABEL_52:
                    if (*(_DWORD*)& byte_5D4594[1047932])
                        goto LABEL_54;
                LABEL_53:
                    sub_46ADE0(a1);
                    *(_DWORD*)& byte_5D4594[1049532] = 0;
                LABEL_54:
                    sub_477660();
                    return 1;
                }
                sub_45F300((int)v3, v4, v10);
                sub_452D80(794, 100);
                if (v3 == (int*)& byte_5D4594[1047940])
                    goto LABEL_51;
            }
            sub_45DDF0((int)v3);
            goto LABEL_51;
        case 8:
        case 12:
        case 16:
            return 0;
        default:
            return 1;
        }
    }
    return 1;
}
// 45F261: variable 'v13' is possibly undefined

//----- (0045F300) --------------------------------------------------------
wchar_t* __cdecl sub_45F300(int a1, int a2, int a3)
{
    int v3; // eax
    int v4; // ecx
    int v5; // edx
    _DWORD* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax

    v3 = *(_DWORD*)(a1 + 204);
    v4 = *(_DWORD*)(v3 + 8 * a2);
    v5 = *(_DWORD*)(v3 + 8 * a2 + 4);
    *(_DWORD*)(v3 + 8 * a2) = *(_DWORD*)(8 * a3 + v3);
    *(_DWORD*)(v3 + 8 * a2 + 4) = *(_DWORD*)(8 * a3 + v3 + 4);
    v6 = (_DWORD*)(*(_DWORD*)(a1 + 204) + 8 * a3);
    *v6 = v4;
    v6[1] = v5;
    v7 = (wchar_t*)sub_424930(*(_DWORD*)(*(_DWORD*)(a1 + 204) + 8 * a2));
    sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 4 * a2 + 212) + 36), v7);
    v8 = (wchar_t*)sub_424930(*(_DWORD*)(8 * a3 + *(_DWORD*)(a1 + 204)));
    return sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 4 * a3 + 212) + 36), v8);
}

//----- (0045F390) --------------------------------------------------------
wchar_t* __cdecl sub_45F390(int a1, int a2, int a3, int a4)
{
    int v4; // edi
    int v5; // ebx
    wchar_t* v6; // eax

    v4 = *(_DWORD*)(a2 + 8 * a4);
    v5 = *(_DWORD*)(a2 + 8 * a4 + 4);
    *(_DWORD*)(a2 + 8 * a4) = *(_DWORD*)(a1 + 8 * a3);
    *(_DWORD*)(a2 + 8 * a4 + 4) = *(_DWORD*)(a1 + 8 * a3 + 4);
    *(_DWORD*)(a1 + 8 * a3) = v4;
    *(_DWORD*)(a1 + 8 * a3 + 4) = v5;
    v6 = (wchar_t*)sub_424930(*(_DWORD*)(a2 + 8 * a4));
    return sub_46B000((wchar_t*)(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 4 * a4 + 212) + 36), v6);
}

//----- (0045F3F0) --------------------------------------------------------
int sub_45F3F0()
{
    wchar_t* v0; // eax

    if (sub_45CFC0())
        v0 = loadString_sub_40F1D0((char*)& byte_587000[135064], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 901);
    else
        v0 = loadString_sub_40F1D0((char*)& byte_587000[135124], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 905);
    sub_4776B0(v0);
    return 1;
}

//----- (0045F450) --------------------------------------------------------
int __cdecl sub_45F450(int a1, unsigned int a2)
{
    if (a2 >= 5)
    {
        if (a2 <= 6)
            return 1;
        if (a2 == 7)
        {
            sub_45AC70();
            return 1;
        }
    }
    return 0;
}

//----- (0045F480) --------------------------------------------------------
int __cdecl sub_45F480(int a1)
{
    wchar_t* v1; // eax

    if (sub_45F500(
        *(unsigned __int16*)(a1 + 368),
        (int)& byte_5D4594[256 * ((unsigned __int16)(*(_DWORD*)(a1 + 368) >> 16)) + 1048196]))
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[135180], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 941);
    }
    else
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[135236], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 945);
    }
    sub_4776B0(v1);
    return 1;
}

//----- (0045F500) --------------------------------------------------------
int __cdecl sub_45F500(int a1, int a2)
{
    return (*(_DWORD*)(*(_DWORD*)(a2 + 4 * a1 + 232) + 36) >> 1) & 1;
}

//----- (0045F520) --------------------------------------------------------
int __cdecl sub_45F520(int a1, unsigned int a2)
{
    int v2; // ebx
    int v3; // esi
    int v4; // eax
    int v5; // edi
    int v6; // eax

    v2 = (unsigned __int16)(*(_DWORD*)(a1 + 368) >> 16) << 8;
    v3 = *(unsigned __int16*)(a1 + 368);
    v4 = *(_DWORD*)& byte_5D4594[v2 + 1048400];
    v5 = v4 + 8 * v3;
    v6 = *(_DWORD*)(v4 + 8 * v3);
    if (!v6)
        return 0;
    if (a2 != 5)
    {
        if (a2 > 5 && a2 <= 7)
            return 1;
        return 0;
    }
    if (sub_424A50(v6, 2098176))
    {
        sub_452D80(925, 100);
    }
    else
    {
        *(_BYTE*)(v5 + 4) ^= 1u;
        sub_45DE10(v3, (int)& byte_5D4594[v2 + 1048196]);
        sub_452D80(921, 100);
    }
    return 1;
}

//----- (0045F5D0) --------------------------------------------------------
int __cdecl sub_45F5D0(_DWORD* a1)
{
    int v1; // esi
    __int16* v2; // esi
    int v4; // [esp+4h] [ebp-4h]

    v1 = a1[92];
    sub_46AA60(a1, &v4, &a1);
    v2 = (__int16*)sub_42E8E0(v1 + 28, 1);
    if (v2)
    {
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43F6E0(*(int*)& byte_5D4594[1049684], v2, v4, (int)a1);
    }
    return 1;
}

//----- (0045F630) --------------------------------------------------------
int __cdecl sub_45F630(int a1, unsigned int a2)
{
    int v2; // esi

    v2 = *(_DWORD*)(a1 + 368);
    if ((!*(_DWORD*)& byte_5D4594[2614252] || (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2) != 2)
        && !sub_4AE3D0())
    {
        if (a2 == 5)
        {
            switch (v2)
            {
            case 0:
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049508] + 60) = 0;
                sub_460540();
                break;
            case 1:
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049508] + 60) = 0;
                sub_4604F0();
                break;
            case 2:
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049508] + 60) = 0;
                sub_460920();
                break;
            case 3:
                sub_4603F0();
                break;
            case 4:
                sub_4603A0();
                break;
            default:
                break;
            }
            *(_DWORD*)& byte_5D4594[1049700] = 2;
            *(_DWORD*)& byte_5D4594[1049704] = v2;
        }
        else if (a2 <= 5 || a2 > 7)
        {
            return 0;
        }
    }
    return 1;
}

//----- (0045F6F0) --------------------------------------------------------
int __cdecl sub_45F6F0(_DWORD* a1)
{
    _DWORD* v1; // esi
    int v2; // edi
    char* v3; // eax
    int v4; // ecx
    int v5; // esi
    int v6; // eax
    int v8; // [esp+8h] [ebp-4h]

    v1 = a1;
    v2 = a1[92];
    sub_46AA60(a1, &a1, &v8);
    v3 = (char*)a1 + v1[24];
    v4 = v1[25] + v8;
    a1 = (_DWORD*)((char*)a1 + v1[24]);
    v8 = v4;
    if (*(int*)& byte_5D4594[1049700] <= 0 || *(int*)& byte_5D4594[1049704] != v2)
    {
        v5 = v1[15];
        if (v5)
            sub_47D2C0(v5, (int)v3, v4);
    }
    else
    {
        sub_47D2C0(v1[19], (int)v3, v4);
        if (!-- * (_DWORD*)& byte_5D4594[1049700] && *(_DWORD*)& byte_5D4594[1049704] <= 2)
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1049508] + 60) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049508] + 76);
    }
    v6 = sub_45CFC0();
    sub_46AE10(*(int*)& byte_5D4594[1049524], v6);
    return 1;
}

//----- (0045F7A0) --------------------------------------------------------
int __cdecl sub_45F7A0(_DWORD* a1, unsigned int a2, unsigned int a3)
{
    int result; // eax

    if (a2 < 5)
        goto LABEL_18;
    if (a2 <= 6)
        return 1;
    if (a2 != 7)
    {
    LABEL_18:
        sub_46AE10(*(int*)& byte_5D4594[1049504], 0);
        return 0;
    }
    if (*(_DWORD*)& byte_5D4594[1047928])
    {
        if (!sub_46AAB0(a1, (unsigned __int16)a3, a3 >> 16))
            sub_45E040();
        sub_46ADE0((int)a1);
        *(_DWORD*)& byte_5D4594[1049532] = 0;
        *(_DWORD*)& byte_5D4594[1047928] = 0;
        return 1;
    }
    sub_46AE10(*(int*)& byte_5D4594[1049504], 1);
    if (!*(_DWORD*)& byte_5D4594[2618908])
        return 1;
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) == 1 && sub_45F890())
    {
        sub_46ADC0((int)a1);
        *(_DWORD*)& byte_5D4594[1049532] = a1;
        *(_DWORD*)& byte_5D4594[1047928] = 1;
        result = 1;
    }
    else
    {
        sub_45E040();
        result = 1;
    }
    return result;
}

//----- (0045F890) --------------------------------------------------------
int sub_45F890()
{
    int* v0; // esi
    int v1; // edi

    v0 = *(int**)& byte_5D4594[1048144];
    v1 = 0;
    while (!*v0 || (sub_424A70(*v0) & 8) != 8)
    {
        ++v1;
        v0 += 2;
        if (v1 >= 3)
            return 0;
    }
    return 1;
}

//----- (0045F8D0) --------------------------------------------------------
BOOL __cdecl sub_45F8D0(int a1, int a2, int a3, int a4)
{
    return a2 != 8 && a2 != 12 && a2 != 16;
}

//----- (0045F8F0) --------------------------------------------------------
int sub_45F8F0()
{
    sub_45F900();
    return 1;
}

//----- (0045F900) --------------------------------------------------------
_DWORD* sub_45F900()
{
    _DWORD* result; // eax
    int i; // edi
    int v2; // ecx
    int v3; // eax
    int v4; // esi

    result = *(_DWORD * *)& byte_587000[133480];
    if (*(_DWORD*)& byte_587000[133480])
    {
        if (*(_DWORD*)& byte_5D4594[1049496])
        {
            result = (_DWORD*)sub_430B40_get_mouse_prev_seq();
            if (*(_DWORD * *)& byte_5D4594[1049492] == result)
                return result;
            *(_DWORD*)& byte_5D4594[1049496] = 0;
        }
        else
        {
            result = (_DWORD*)sub_430B40_get_mouse_prev_seq();
            if (*(_DWORD * *)& byte_5D4594[1049492] != result)
                return result;
            *(_DWORD*)& byte_5D4594[1049496] = 1;
        }
        for (i = 0; i < 5; ++i)
        {
            v2 = *(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204);
            v3 = *(_DWORD*)(v2 + 8 * i);
            v4 = v2 + 8 * i;
            if (v3)
            {
                if (!sub_424A50(v3, 2098176))
                {
                    *(_BYTE*)(v4 + 4) ^= 1u;
                    sub_45DE10(i, *(int*)& byte_587000[133480]);
                }
            }
        }
        sub_45DDF0(*(int*)& byte_587000[133480]);
        result = sub_452D80(921, 100);
    }
    return result;
}

//----- (0045F9B0) --------------------------------------------------------
int __cdecl sub_45F9B0(_DWORD* a1)
{
    _DWORD* v1; // esi
    wchar_t* v2; // eax
    char* v3; // esi
    int v5; // [esp-8h] [ebp-5Ch]
    int v6; // [esp+0h] [ebp-54h]
    int v7; // [esp+4h] [ebp-50h]
    int v8; // [esp+8h] [ebp-4Ch]
    int v9; // [esp+Ch] [ebp-48h]
    int v10; // [esp+10h] [ebp-44h]
    wchar_t v11[32]; // [esp+14h] [ebp-40h]

    if (!*(_DWORD*)& byte_5D4594[1049476])
    {
        v1 = a1;
        sub_46AA60(a1, &v6, &a1);
        nox_window_get_size((int)v1, &v7, &v9);
        v5 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200) + 1;
        v2 = loadString_sub_40F1D0((char*)& byte_587000[135296], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1276);
        nox_swprintf(v11, v2, v5);
        sub_43F840(0, v11, &v8, &v10, 0);
        v3 = (char*)a1 - sub_43F320(0);
        a1 = &v3[sub_43F320(*(int*)& byte_5D4594[1049684]) + 1];
        v6 += (v7 - v8) / 2;
        sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_4343E0(*(int*)& byte_5D4594[2614248]);
        sub_43F730(0, (__int16*)v11, v6, (int)a1);
    }
    return 1;
}

//----- (0045FAC0) --------------------------------------------------------
int __cdecl sub_45FAC0(_DWORD* a1)
{
    _DWORD* v1; // esi
    wchar_t* v2; // eax
    int v4; // [esp-4h] [ebp-58h]
    int v5; // [esp+4h] [ebp-50h]
    int v6; // [esp+8h] [ebp-4Ch]
    int v7; // [esp+Ch] [ebp-48h]
    int v8; // [esp+10h] [ebp-44h]
    wchar_t v9[32]; // [esp+14h] [ebp-40h]

    v1 = a1;
    sub_46AA60(a1, &a1, &v7);
    nox_window_get_size((int)v1, &v5, &v8);
    v4 = byte_5D4594[1048140] + 1;
    v2 = loadString_sub_40F1D0((char*)& byte_587000[135348], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1299);
    nox_swprintf(v9, v2, v4);
    sub_43F840(0, v9, &v6, 0, 0);
    a1 = (_DWORD*)((char*)a1 + (v5 - v6) / 2);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_4343E0(*(int*)& byte_5D4594[2614248]);
    sub_43F730(0, (__int16*)v9, (int)a1, v7);
    return 1;
}

//----- (0045FB90) --------------------------------------------------------
int __cdecl sub_45FB90(int a1, unsigned int a2, int a3, int a4)
{
    if (a2 >= 5)
    {
        if (a2 <= 6)
            return 1;
        if (a2 == 7)
        {
            if (!wndIsShown_sub_46ACC0(a1))
                sub_461060();
            return 1;
        }
    }
    return 0;
}

//----- (0045FBD0) --------------------------------------------------------
int __cdecl sub_45FBD0(int yTop)
{
    int v1; // ebx
    int v2; // esi
    _DWORD* v3; // eax
    int v5; // ebp
    int v6; // eax
    int* v7; // edi
    int v8; // eax
    int v9; // esi
    wchar_t* v10; // eax
    __int16* v11; // eax
    wchar_t* v12; // eax
    int v13; // eax
    unsigned int v14; // eax
    int v15; // [esp-10h] [ebp-20h]
    int v16; // [esp-Ch] [ebp-1Ch]
    int v17; // [esp-Ch] [ebp-1Ch]
    int xLeft; // [esp+8h] [ebp-8h]
    int v19; // [esp+Ch] [ebp-4h]

    v1 = yTop;
    v2 = 0;
    v3 = (_DWORD*)(*(_DWORD*)(yTop + 368) + 212);
    do
    {
        if (yTop == *v3)
            break;
        ++v2;
        ++v3;
    } while (v2 < 5);
    if (v2 == 5)
        return 0;
    sub_46AA60((_DWORD*)yTop, &xLeft, &yTop);
    v5 = sub_43F320(0);
    v6 = *(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204);
    v7 = (int*)(v6 + 8 * v2);
    v8 = *(_DWORD*)(v6 + 8 * v2);
    if (v8)
    {
        if (*(_DWORD*)& byte_5D4594[2598000] <= 0xAu
            || v2 != *(_DWORD*)& byte_587000[133484]
            || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1049540]) >= 0xA)
        {
            v9 = sub_425310(v8, 0);
            v19 = 0;
        }
        else
        {
            v9 = sub_425310(v8, 1);
            v19 = 1;
        }
        v16 = *v7;
        if (*(_DWORD*)& byte_5D4594[24 * *v7 + 1047776])
        {
            v10 = (wchar_t*)sub_425260(v16);
            sub_46B000((wchar_t*)(v1 + 36), v10);
            if (v9)
            {
            LABEL_14:
                sub_47D2C0(v9, xLeft, yTop);
            LABEL_19:
                v13 = 24 * *v7;
                if (*(_DWORD*)& byte_5D4594[v13 + 1047776] || !*(_DWORD*)& byte_5D4594[v13 + 1047772] || sub_4372B0())
                {
                    v14 = sub_4252D0(*v7);
                    if (v14 / *(_DWORD*)& byte_5D4594[2649704])
                    {
                        if (!v19)
                            sub_49CF10(
                                xLeft,
                                yTop,
                                34,
                                34
                                - (*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[24 * *v7 + 1047784])
                                / (v14
                                    / *(_DWORD*)& byte_5D4594[2649704]));
                    }
                }
                return 1;
            }
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v17 = yTop + v5 + 2;
            v15 = xLeft + 6;
            v11 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[135396], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1388);
        }
        else
        {
            v12 = (wchar_t*)sub_425260(v16);
            sub_46B000((wchar_t*)(v1 + 36), v12);
            if (v9)
                goto LABEL_14;
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v17 = yTop + v5 + 2;
            v15 = xLeft + 6;
            v11 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[135444], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1401);
        }
        sub_43F6E0(0, v11, v15, v17);
        goto LABEL_19;
    }
    return 1;
}

//----- (0045FDE0) --------------------------------------------------------
int __cdecl sub_45FDE0(int yTop)
{
    int v1; // edi
    int v2; // esi
    unsigned __int8* v3; // eax
    int* v4; // ebx
    _DWORD* v5; // eax
    int v7; // eax
    int v8; // ecx
    int v9; // ebp
    unsigned __int8 v10; // al
    wchar_t* v11; // eax
    __int16* v12; // eax
    int v13; // ebp
    int v14; // edi
    int* v15; // edi
    int v16; // [esp-Ch] [ebp-24h]
    int v17; // [esp-8h] [ebp-20h]
    int xLeft; // [esp+Ch] [ebp-Ch]
    unsigned __int8* v19; // [esp+10h] [ebp-8h]
    int v20; // [esp+14h] [ebp-4h]

    v1 = yTop;
    v2 = 0;
    v3 = *(unsigned __int8**)(yTop + 368);
    v19 = v3;
    v4 = (int*) * ((_DWORD*)v3 + 51);
    v5 = v3 + 212;
    do
    {
        if (yTop == *v5)
            break;
        ++v2;
        ++v5;
    } while (v2 < 5);
    if (v2 == 5)
        return 0;
    sub_46AA60((_DWORD*)yTop, &xLeft, &yTop);
    if (v4[2 * v2])
    {
        if (*(_DWORD*)& byte_5D4594[2598000] <= 0xAu
            || v2 != *(_DWORD*)& byte_587000[133484]
            || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[1049540]) >= 0xA)
        {
            v7 = sub_424A90(v4[2 * v2]);
        }
        else
        {
            v7 = sub_424AB0(v4[2 * v2]);
        }
        v8 = v4[2 * v2];
        v9 = v7;
        v10 = byte_5D4594[v8 + 1049544];
        if ((char)v10 > 0)
            byte_5D4594[v8 + 1049544] = v10 - 1;
        v11 = (wchar_t*)sub_424930(v4[2 * v2]);
        sub_46B000((wchar_t*)(v1 + 36), v11);
        if (v9)
        {
            sub_47D2C0(v9, xLeft, yTop);
        }
        else
        {
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v17 = sub_43F320(0) + yTop + 2;
            v16 = xLeft + 6;
            v12 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[135492], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1491);
            sub_43F6E0(0, v12, v16, v17);
        }
        v13 = sub_470DD0();
        v14 = sub_4249A0(v4[2 * v2], 1);
        v20 = v14;
        if (v19 == &byte_5D4594[1047940] && v2 > 0)
        {
            v15 = v4;
            v19 = (unsigned __int8*)v2;
            do
            {
                if (*v15)
                    v13 -= sub_4249A0(*v15, 2);
                v15 += 2;
                --v19;
            } while (v19);
            v14 = v20;
        }
        if (!sub_424B70(v4[2 * v2]) || sub_4372B0() || sub_4356C0(*(int*)& byte_5D4594[2614252], 29))
        {
            sub_49CF10(xLeft, yTop, 30, 30);
            return 1;
        }
        if (v13 < v14 && v14)
        {
            sub_49CF10(xLeft, yTop, 30, 30 * (v14 - v13) / v14);
            return 1;
        }
    }
    else
    {
        sub_46B000((wchar_t*)(v1 + 36), (wchar_t*)& byte_5D4594[1049716]);
    }
    return 1;
}

//----- (00460000) --------------------------------------------------------
int sub_460000()
{
    int v0; // edx
    int v1; // eax
    int result; // eax

    v0 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049504] + 20);
    v1 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049504] + 20) - *(_DWORD*)& byte_5D4594[1049536];
    if (v1 >= 0)
    {
        if (v1 <= 0)
        {
            if (*(_DWORD*)& byte_5D4594[1049536] > nox_win_height)
            {
                sub_460070();
                *(_DWORD*)& byte_5D4594[1049536] = nox_win_height - 74;
            }
            result = 1;
        }
        else
        {
            sub_46A9B0(*(_DWORD * *)& byte_5D4594[1049504], *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049504] + 16), v0 - 1);
            result = 1;
        }
    }
    else
    {
        sub_46A9B0(*(_DWORD * *)& byte_5D4594[1049504], *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049504] + 16), v0 + 1);
        result = 1;
    }
    return result;
}

//----- (00460070) --------------------------------------------------------
int sub_460070()
{
    int result; // eax
    char* v1; // eax
    char* v2; // eax
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    char* v5; // eax
    char* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax

    result = *(_DWORD*)& byte_5D4594[2618908];
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) == 1)
        {
            v5 = sub_42F970("QuickBarTrap");
            sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v5);
            v6 = sub_42F970("QuickBarTrapHit");
            sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v6);
            v7 = loadString_sub_40F1D0((char*)& byte_587000[135572], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1544);
            sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049520] + 36), v7);
            sub_46AD60(*(int*)& byte_5D4594[1049520], 8);
            v8 = loadString_sub_40F1D0((char*)& byte_587000[135628], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1547);
            sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049500] + 36), v8);
            sub_46AD60(*(int*)& byte_5D4594[1049500], 8);
            result = sub_46B340(*(int*)& byte_5D4594[1049500], 0);
        }
        else
        {
            result = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) - 2;
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) == 2)
            {
                v1 = sub_42F970("QuickBarBomber");
                sub_46AE60(*(int*)& byte_5D4594[1049504], (int)v1);
                v2 = sub_42F970("QuickBarBomberHit");
                sub_46AEA0(*(int*)& byte_5D4594[1049504], (int)v2);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[135728], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1559);
                sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049520] + 36), v3);
                sub_46AD60(*(int*)& byte_5D4594[1049520], 8);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[135788], 0, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 1562);
                sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1049500] + 36), v4);
                sub_46AD60(*(int*)& byte_5D4594[1049500], 8);
                result = sub_46B340(*(int*)& byte_5D4594[1049500], 0);
            }
        }
    }
    return result;
}

//----- (004601F0) --------------------------------------------------------
int __cdecl sub_4601F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v7; // esi
    char* v8; // eax
    int v9; // ebx
    unsigned __int8* v10; // ebp
    int* v11; // edi
    _DWORD* v12; // eax
    int v13; // eax
    int result; // eax
    int v15; // [esp+Ch] [ebp+4h]

    v7 = a1;
    *(_DWORD*)(a1 + 208) = nox_window_new(0, 1224, a2 - 10, a3 - 15, 199, 59, 0);
    v8 = sub_42F970("QuickBarBase");
    sub_46AE60(*(_DWORD*)(a1 + 208), (int)v8);
    sub_46AE40(*(_DWORD*)(a1 + 208), -61, -18);
    sub_46B300(*(_DWORD*)(a1 + 208), sub_45F8D0);
    v9 = a5 + 10;
    if (a4 > 0)
    {
        v10 = &byte_587000[133488];
        v11 = (int*)(a1 + 212);
        v15 = a4;
        do
        {
            v12 = nox_window_new(*(_DWORD*)(v7 + 208), 1032, v9, 15, 34, 34, 0);
            *v11 = (int)v12;
            nox_window_set_all_funcs(v12, a6, a7, 0);
            v13 = *v11;
            ++v11;
            v10 += 4;
            *(_DWORD*)(v13 + 368) = v7;
            v9 += *((_DWORD*)v10 - 1);
            --v15;
        } while (v15);
    }
    result = *(unsigned __int8*)(v7 + 200);
    *(_DWORD*)(v7 + 204) = v7 + 40 * result;
    return result;
}

//----- (004602F0) --------------------------------------------------------
void* sub_4602F0()
{
    int v0; // ebp
    unsigned __int8* v1; // esi
    int v2; // edi
    _DWORD* v3; // ecx
    _BYTE* v4; // eax
    int v5; // edx
    unsigned __int8* v6; // edx
    unsigned __int8* v7; // eax
    int v8; // ecx
    void* result; // eax

    sub_4606B0();
    v0 = 0;
    v1 = &byte_5D4594[1048196];
    do
    {
        v2 = 5;
        v3 = (_DWORD*)(*(_DWORD*)& byte_587000[133480] + v0);
        v4 = v1 + 4;
        v5 = *(_DWORD*)& byte_587000[133480] + v0 - (_DWORD)v1;
        do
        {
            *v3 = 0;
            v4[v5] = 0;
            *((_DWORD*)v4 - 1) = 0;
            *v4 = 0;
            v3 += 2;
            v4 += 8;
            --v2;
        } while (v2);
        v1 += 256;
        v0 += 40;
    } while ((int)v1 < (int)& byte_5D4594[1049476]);
    v6 = &byte_5D4594[1047940];
    do
    {
        v7 = v6;
        v8 = 3;
        do
        {
            *(_DWORD*)v7 = 0;
            v7[4] = 0;
            v7 += 8;
            --v8;
        } while (v8);
        v6 += 40;
    } while ((int)v6 < (int)& byte_5D4594[1048060]);
    result = *(void**)& byte_587000[133480];
    if (*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 232))
        result = (void*)sub_45DDF0(*(int*)& byte_587000[133480]);
    return result;
}

//----- (00460380) --------------------------------------------------------
void* sub_460380()
{
    unsigned __int8* v0; // eax

    v0 = &byte_5D4594[1047804];
    do
    {
        *(_DWORD*)v0 = 0;
        v0 += 24;
    } while ((int)v0 < (int)& byte_5D4594[1047924]);
    return sub_4602F0();
}

//----- (004603A0) --------------------------------------------------------
_DWORD* sub_4603A0()
{
    if (byte_5D4594[1048140] == 2)
        byte_5D4594[1048140] = 0;
    else
        ++byte_5D4594[1048140];
    *(_DWORD*)& byte_5D4594[1048144] = &byte_5D4594[40 * byte_5D4594[1048140] + 1047940];
    return sub_452D80(798, 100);
}

//----- (004603F0) --------------------------------------------------------
_DWORD* sub_4603F0()
{
    if (byte_5D4594[1048140])
        --byte_5D4594[1048140];
    else
        byte_5D4594[1048140] = 2;
    *(_DWORD*)& byte_5D4594[1048144] = &byte_5D4594[40 * byte_5D4594[1048140] + 1047940];
    return sub_452D80(798, 100);
}

//----- (00460440) --------------------------------------------------------
_DWORD* sub_460440()
{
    _DWORD* result; // eax

    if (sub_4160F0(6u, *(_DWORD*)& byte_5D4594[2649704] >> 1))
    {
        LOBYTE(result) = 0;
        *(_DWORD*)& byte_5D4594[1049708] = 0;
    }
    else
    {
        result = (_DWORD*)++ * (_DWORD*)& byte_5D4594[1049708];
        if (*(int*)& byte_5D4594[1049708] >= 3)
        {
            byte_5D4594[1048140] = 2;
            return result;
        }
    }
    byte_5D4594[1048140] = (unsigned __int8)result;
    *(_DWORD*)& byte_5D4594[1048144] = &byte_5D4594[40 * (unsigned __int8)result + 1047940];
    sub_4160D0(6);
    return sub_452D80(798, 100);
}

//----- (004604B0) --------------------------------------------------------
int __cdecl sub_4604B0(int a1)
{
    int result; // eax

    result = a1;
    if (a1 >= 0 && a1 < 3)
    {
        byte_5D4594[1048140] = a1;
        result = 5 * (unsigned __int8)a1;
        *(_DWORD*)& byte_5D4594[1048144] = &byte_5D4594[40 * (unsigned __int8)a1 + 1047940];
    }
    return result;
}

//----- (004604E0) --------------------------------------------------------
int sub_4604E0()
{
    return byte_5D4594[1048140];
}

//----- (004604F0) --------------------------------------------------------
int sub_4604F0()
{
    int result; // eax
    int v1; // eax

    result = *(_DWORD*)& byte_5D4594[1049476];
    if (!*(_DWORD*)& byte_5D4594[1049476])
    {
        result = *(_DWORD*)& byte_5D4594[1049496];
        if (!*(_DWORD*)& byte_5D4594[1049496])
        {
            result = sub_57AF20();
            if (!result)
            {
                sub_45DAD0(-1);
                v1 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200) + 1;
                if (v1 > 4)
                    v1 = 0;
                result = sub_45E110(v1);
            }
        }
    }
    return result;
}

//----- (00460540) --------------------------------------------------------
int sub_460540()
{
    int result; // eax
    int v1; // eax

    result = *(_DWORD*)& byte_5D4594[1049476];
    if (!*(_DWORD*)& byte_5D4594[1049476])
    {
        result = *(_DWORD*)& byte_5D4594[1049496];
        if (!*(_DWORD*)& byte_5D4594[1049496])
        {
            result = sub_57AF20();
            if (!result)
            {
                sub_45DAD0(-1);
                v1 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200) - 1;
                if (v1 < 0)
                    v1 = 4;
                result = sub_45E110(v1);
            }
        }
    }
    return result;
}

//----- (00460590) --------------------------------------------------------
void sub_460590()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1049476];
    if (!*(_DWORD*)& byte_5D4594[1049476])
    {
        result = *(_DWORD*)& byte_5D4594[1049496];
        if (!*(_DWORD*)& byte_5D4594[1049496])
        {
            if (sub_4160F0(7u, *(_DWORD*)& byte_5D4594[2649704] >> 1))
            {
                LOBYTE(result) = 0;
                *(_DWORD*)& byte_5D4594[1049712] = 0;
            }
            else
            {
                result = ++ * (_DWORD*)& byte_5D4594[1049712];
                if (*(int*)& byte_5D4594[1049712] >= 5)
                {
                    *(_BYTE*)(*(_DWORD*)& byte_587000[133480] + 200) = 4;
                    return;
                }
            }
            *(_BYTE*)(*(_DWORD*)& byte_587000[133480] + 200) = result;
            *(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) = *(_DWORD*)& byte_587000[133480]
                + 40
                * *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
            sub_4160D0(7);
            sub_452D80(798, 100);
            sub_45DDF0(*(int*)& byte_587000[133480]);
        }
    }
}

//----- (00460630) --------------------------------------------------------
void sub_460630()
{
    if (!*(_DWORD*)& byte_5D4594[1049476])
    {
        int result = sub_430B40_get_mouse_prev_seq();
        *(_DWORD*)& byte_5D4594[1049492] = result;
    }
}

//----- (00460650) --------------------------------------------------------
int sub_460650()
{
    return *(_DWORD*)& byte_5D4594[1047928];
}

//----- (00460660) --------------------------------------------------------
int sub_460660()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1049532];
    if (*(_DWORD*)& byte_5D4594[1049532] || *(_DWORD*)& byte_5D4594[1047928] || *(_DWORD*)& byte_5D4594[1047932])
    {
        sub_46ADE0(*(int*)& byte_5D4594[1049532]);
        *(_DWORD*)& byte_5D4594[1049532] = 0;
        *(_DWORD*)& byte_5D4594[1047928] = 0;
        *(_DWORD*)& byte_5D4594[1047932] = 0;
        result = 1;
    }
    return result;
}

//----- (004606B0) --------------------------------------------------------
int sub_4606B0()
{
    unsigned __int8* v0; // ebp
    int v1; // ecx
    unsigned __int8* v2; // ebx
    int* v3; // edi
    _BYTE* v4; // esi
    int v6; // [esp+0h] [ebp-Ch]
    int v7; // [esp+4h] [ebp-8h]
    int v8; // [esp+8h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[1049476] != 1)
        return 0;
    v6 = 0;
    v0 = &byte_5D4594[1048196];
    do
    {
        v1 = (int)& v0[-v6 - *(_DWORD*)& byte_587000[133480]];
        v2 = v0;
        v3 = (int*)(v0 + 232);
        v4 = (_BYTE*)(v6 + *(_DWORD*)& byte_587000[133480] + 4);
        v8 = (int)& v0[-v6 - *(_DWORD*)& byte_587000[133480]];
        v7 = 5;
        while (1)
        {
            *((_DWORD*)v4 - 1) = *(_DWORD*)v2;
            *v4 = v4[v1];
            nox_window_set_hidden(*v3, 1);
            ++v3;
            v2 += 8;
            v4 += 8;
            if (!--v7)
                break;
            v1 = v8;
        }
        nox_window_set_hidden(*((_DWORD*)v0 + 52), 1);
        v0 += 256;
        v6 += 40;
    } while ((int)v0 < (int)& byte_5D4594[1049220]);
    *(_BYTE*)(*(_DWORD*)& byte_587000[133480] + 200) = byte_5D4594[1047908];
    *(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) = *(_DWORD*)& byte_587000[133480]
        + 40 * *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
    sub_45DDF0(*(int*)& byte_587000[133480]);
    nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 0);
    sub_452D80(800, 100);
    *(_DWORD*)& byte_5D4594[1049476] = 0;
    return 1;
}

//----- (00460920) --------------------------------------------------------
_DWORD* sub_460920()
{
    unsigned __int8* v0; // ebx
    int* v1; // ebp
    unsigned __int8* v2; // esi
    _DWORD* v3; // edi
    int v4; // eax
    _DWORD* result; // eax
    int v6; // [esp+0h] [ebp-Ch]
    int v7; // [esp+4h] [ebp-8h]
    int i; // [esp+8h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[1049476])
        return (_DWORD*)sub_4606B0();
    result = *(_DWORD * *)& byte_5D4594[1049496];
    if (!*(_DWORD*)& byte_5D4594[1049496])
    {
        result = (_DWORD*)sub_57AF20();
        if (!result)
        {
            result = *(_DWORD * *)& byte_5D4594[1049476];
            if (!*(_DWORD*)& byte_5D4594[1049476])
            {
                if (*(_DWORD*)& byte_5D4594[1049484] == 1)
                    sub_461010();
                v6 = 0;
                v0 = &byte_5D4594[1048428];
                do
                {
                    v1 = (int*)v0;
                    v2 = v0 - 228;
                    v3 = (_DWORD*)(v6 + *(_DWORD*)& byte_587000[133480]);
                    v7 = 5;
                    v4 = v6 + *(_DWORD*)& byte_587000[133480] - (_DWORD)(v0 - 232);
                    for (i = v6 + *(_DWORD*)& byte_587000[133480] - (_DWORD)(v0 - 232); ; v4 = i)
                    {
                        *((_DWORD*)v2 - 1) = *v3;
                        *v2 = v2[v4];
                        nox_window_set_hidden(*v1, 0);
                        ++v1;
                        v3 += 2;
                        v2 += 8;
                        if (!--v7)
                            break;
                    }
                    nox_window_set_hidden(*((_DWORD*)v0 - 6), 0);
                    sub_45DDF0((int)(v0 - 232));
                    v0 += 256;
                    v6 += 40;
                } while ((int)v0 < (int)& byte_5D4594[1049452]);
                *(_DWORD*)& byte_5D4594[1047912] = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
                *(_BYTE*)(*(_DWORD*)& byte_587000[133480] + 200) = 4;
                *(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 204) = *(_DWORD*)& byte_587000[133480]
                    + 40
                    * *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
                sub_45DDF0(*(int*)& byte_587000[133480]);
                nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 1);
                result = sub_452D80(799, 100);
                *(_DWORD*)& byte_5D4594[1049476] = 1;
            }
        }
    }
    return result;
}

//----- (00460940) --------------------------------------------------------
int __thiscall sub_460940(void* this)
{
    int result; // eax
    void* v2; // [esp+0h] [ebp-4h]

    v2 = this;
    if (!*(_DWORD*)& byte_5D4594[3803300] && sub_461450() == 1)
    {
        sub_461400();
        sub_461440(0);
    }
    if (*(_DWORD*)& byte_5D4594[2618908])
        LOBYTE(v2) = *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251);
    else
        LOBYTE(v2) = sub_431770()[66];
    sub_426AC0(&v2, 1u);
    if (!(_BYTE)v2)
    {
        result = sub_460A10(*(int*)& byte_587000[133480], 5, 5, 0);
        if (!result)
            return result;
        return 1;
    }
    result = sub_460A10(*(int*)& byte_587000[133480], 5, 5, (char)v2);
    if (result)
    {
        result = sub_460A10((int)& byte_5D4594[1047940], 3, 3, (char)v2);
        if (result)
        {
            if (*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 232))
                sub_45DDF0(*(int*)& byte_587000[133480]);
            return 1;
        }
    }
    return result;
}

//----- (00460A10) --------------------------------------------------------
int __cdecl sub_460A10(int a1, int a2, int a3, char a4)
{
    int v4; // esi
    int v5; // ebp
    char* v6; // eax
    bool v7; // zf
    size_t v9; // [esp-14h] [ebp-120h]
    int v10; // [esp+0h] [ebp-10Ch]
    int v11; // [esp+4h] [ebp-108h]
    int v12; // [esp+8h] [ebp-104h]
    char v13[256]; // [esp+Ch] [ebp-100h]

    if (a2 <= 0)
        return 1;
    v4 = a1;
    v11 = a1;
    v12 = a2;
    do
    {
        v5 = a3;
        if (a3 > 0)
        {
            do
            {
                if (*(_DWORD*)& byte_5D4594[3803300] == 1)
                {
                    sub_426AC0(&v10, 1u);
                    sub_426AC0(v13, (unsigned __int8)v10);
                    v13[(unsigned __int8)v10] = 0;
                    if (a4)
                        * (_DWORD*)v4 = sub_4243F0(v13);
                    else
                        *(_DWORD*)v4 = sub_424D80(v13);
                }
                else
                {
                    if (a4)
                    {
                        LOBYTE(v10) = strlen(sub_424870(*(_DWORD*)v4));
                        sub_426AC0(&v10, 1u);
                        v9 = (unsigned __int8)v10;
                        v6 = sub_424870(*(_DWORD*)v4);
                    }
                    else
                    {
                        LOBYTE(v10) = strlen(sub_425250(*(_DWORD*)v4));
                        sub_426AC0(&v10, 1u);
                        v9 = (unsigned __int8)v10;
                        v6 = sub_425250(*(_DWORD*)v4);
                    }
                    sub_426AC0(v6, v9);
                }
                sub_426AC0((_BYTE*)(v4 + 4), 1u);
                v4 += 8;
                --v5;
            } while (v5);
        }
        v4 = v11 + 40;
        v7 = v12 == 1;
        v11 += 40;
        --v12;
    } while (!v7);
    return 1;
}
// 460A10: using guessed type char var_100[256];

//----- (00460B90) --------------------------------------------------------
int __cdecl sub_460B90(int a1)
{
    int i; // esi
    int result; // eax
    int j; // esi

    if (a1)
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1049500], 0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049504], 0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049520], 0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049508], 0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 0);
        for (i = 232; i < 252; i += 4)
        {
            nox_window_set_hidden(*(_DWORD*)(i + *(_DWORD*)& byte_587000[133480] - 20), 0);
            nox_window_set_hidden(*(_DWORD*)(i + *(_DWORD*)& byte_587000[133480]), 0);
            if (*(_DWORD*)& byte_5D4594[1049484])
            {
                nox_window_set_hidden(*(_DWORD*)& byte_5D4594[i + 1047920], 0);
                nox_window_set_hidden(*(_DWORD*)& byte_5D4594[i + 1047940], 0);
                nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 1);
            }
        }
        if (*(_DWORD*)& byte_5D4594[1049484])
            nox_window_set_hidden(*(int*)& byte_5D4594[1048148], 0);
        result = nox_window_set_hidden(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 208), 0);
    }
    else
    {
        if (*(_DWORD*)& byte_5D4594[1049476])
            sub_460920();
        nox_window_set_hidden(*(int*)& byte_5D4594[1049500], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049504], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049520], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049508], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 1);
        for (j = 232; j < 252; j += 4)
        {
            nox_window_set_hidden(*(_DWORD*)(j + *(_DWORD*)& byte_587000[133480] - 20), 1);
            nox_window_set_hidden(*(_DWORD*)(j + *(_DWORD*)& byte_587000[133480]), 1);
        }
        nox_window_set_hidden(*(_DWORD*)(*(_DWORD*)& byte_587000[133480] + 208), 1);
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1048148], 1);
    }
    return result;
}

//----- (00460D40) --------------------------------------------------------
BOOL sub_460D40()
{
    return *(_DWORD*)& byte_5D4594[1049508] != 0;
}

//----- (00460D50) --------------------------------------------------------
int sub_460D50()
{
    unsigned __int8* v0; // edi
    _DWORD** v1; // esi
    int v2; // ebx
    unsigned __int8* v3; // esi
    int result; // eax

    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1049500]);
    *(_DWORD*)& byte_5D4594[1049500] = 0;
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1049504]);
    *(_DWORD*)& byte_5D4594[1049504] = 0;
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1049520]);
    *(_DWORD*)& byte_5D4594[1049520] = 0;
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1049508]);
    *(_DWORD*)& byte_5D4594[1049508] = 0;
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1049512]);
    *(_DWORD*)& byte_5D4594[1049512] = 0;
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1049516]);
    *(_DWORD*)& byte_5D4594[1049516] = 0;
    v0 = &byte_5D4594[1048404];
    do
    {
        sub_46C4E0(*(_DWORD * *)v0);
        *(_DWORD*)v0 = 0;
        v1 = (_DWORD * *)(v0 + 24);
        v2 = 5;
        do
        {
            sub_46C4E0(*(v1 - 5));
            *(v1 - 5) = 0;
            sub_46C4E0(*v1);
            *v1 = 0;
            ++v1;
            --v2;
        } while (v2);
        v0 += 256;
    } while ((int)v0 < (int)& byte_5D4594[1049684]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1048148]);
    *(_DWORD*)& byte_5D4594[1048148] = 0;
    v3 = &byte_5D4594[1048152];
    do
    {
        result = sub_46C4E0(*(_DWORD * *)v3);
        *(_DWORD*)v3 = 0;
        v3 += 4;
    } while ((int)v3 < (int)& byte_5D4594[1048164]);
    *(_DWORD*)& byte_5D4594[1049532] = 0;
    *(_DWORD*)& byte_5D4594[1047928] = 0;
    *(_DWORD*)& byte_5D4594[1047932] = 0;
    return result;
}

//----- (00460E60) --------------------------------------------------------
int sub_460E60()
{
    int result; // eax

    if (sub_460D40())
        sub_460D50();
    result = sub_45E190();
    if (result)
    {
        sub_460EA0(*(int*)& byte_587000[80828]);
        result = 1;
    }
    return result;
}

//----- (00460E90) --------------------------------------------------------
int sub_460E90()
{
    int result; // eax

    result = sub_460D40();
    if (result == 1)
        result = sub_460D50();
    return result;
}

//----- (00460EA0) --------------------------------------------------------
int __cdecl sub_460EA0(int a1)
{
    return sub_460B90(a1);
}

//----- (00460EB0) --------------------------------------------------------
char __cdecl sub_460EB0(int a1, char a2)
{
    char result; // al

    result = a2;
    byte_5D4594[a1 + 1049544] = a2;
    return result;
}

//----- (00460EC0) --------------------------------------------------------
_DWORD* __cdecl sub_460EC0(int a1)
{
    _DWORD* result; // eax
    int v2; // esi
    int v3; // eax
    int v4; // [esp-24h] [ebp-24h]
    int v5; // [esp-20h] [ebp-20h]
    int v6; // [esp-1Ch] [ebp-1Ch]
    char v7; // [esp-14h] [ebp-14h]
    char v8; // [esp-10h] [ebp-10h]

    if (!a1)
        return (_DWORD*)sub_460070();
    result = *(_DWORD * *)& byte_5D4594[1049500];
    if (!(*(_BYTE*)(*(_DWORD*)& byte_5D4594[1049500] + 4) & 8))
    {
        v2 = 50;
        *(_DWORD*)& byte_5D4594[1049536] = nox_win_height + 1;
        do
        {
            v8 = sub_415FF0(4, 6, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2732);
            v7 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2731);
            v6 = sub_415FF0(-20, -5, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2729);
            v5 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2728);
            v4 = sub_415FF0(0, 20, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2727)
                + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049504] + 20)
                + 10;
            v3 = sub_415FF0(0, 20, "C:\\NoxPost\\src\\Client\\Gui\\guispell.c", 2726);
            result = sub_431540(0, v3 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049504] + 16) + 10, v4, v5, v6, 1, v7, v8, 2, 1);
            --v2;
        } while (v2);
    }
    return result;
}

//----- (00461010) --------------------------------------------------------
_DWORD* sub_461010()
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[1049484];
    if (*(_DWORD*)& byte_5D4594[1049484])
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[1048148], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 0);
        sub_46AE10(*(int*)& byte_5D4594[1049500], 0);
        result = sub_452D80(797, 100);
        *(_DWORD*)& byte_5D4594[1049484] = 0;
    }
    return result;
}

//----- (00461060) --------------------------------------------------------
_DWORD* sub_461060()
{
    _DWORD* result; // eax

    if (*(_DWORD*)& byte_5D4594[1049484] == 1)
        return sub_461010();
    if (*(_DWORD*)& byte_5D4594[1049476] == 1)
        sub_4606B0();
    nox_window_set_hidden(*(int*)& byte_5D4594[1048148], 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[1049512], 1);
    sub_46AE10(*(int*)& byte_5D4594[1049500], 1);
    result = sub_452D80(796, 100);
    *(_DWORD*)& byte_5D4594[1049484] = 1;
    return result;
}

//----- (00461080) --------------------------------------------------------
int sub_461080()
{
    return *(_DWORD*)& byte_5D4594[1049484];
}

//----- (00461090) --------------------------------------------------------
char* __cdecl sub_461090(int a1, int a2)
{
    int v2; // edx
    char* result; // eax

    v2 = *(_DWORD*)& byte_5D4594[2598000];
    result = (char*)& byte_5D4594[1047808];
    do
    {
        if (*((_DWORD*)result - 5) == a1)
        {
            *(_DWORD*)result = a2 == 0 ? v2 : 0;
            *((_DWORD*)result - 3) = a2;
        }
        result += 24;
    } while ((int)result < (int)& byte_5D4594[1047928]);
    return result;
}

//----- (004610D0) --------------------------------------------------------
char* __cdecl sub_4610D0(unsigned __int8 a1)
{
    int* v1; // esi
    char* result; // eax

    if (a1 != 6)
        return sub_461090(*(_DWORD*)& byte_5D4594[24 * a1 + 1047764], 1);
    v1 = (int*)& byte_5D4594[1047788];
    do
    {
        result = sub_461090(*v1, 1);
        v1 += 6;
    } while ((int)v1 < (int)& byte_5D4594[1047908]);
    return result;
}

//----- (00461120) --------------------------------------------------------
char* __cdecl sub_461120(int a1, int a2)
{
    int v2; // edx
    char* result; // eax

    v2 = 1 << a1;
    result = (char*)& byte_5D4594[1047800];
    do
    {
        if (*((_DWORD*)result - 3) == a1)
        {
            if (a2)
                * (_DWORD*)result |= v2;
            else
                *(_DWORD*)result &= ~v2;
        }
        result += 24;
    } while ((int)result < (int)& byte_5D4594[1047920]);
    return result;
}

//----- (00461160) --------------------------------------------------------
BOOL __cdecl sub_461160(int a1)
{
    int v1; // edx
    unsigned __int8* v2; // eax

    v1 = 1;
    v2 = &byte_5D4594[1047788];
    while (*(_DWORD*)v2 != a1)
    {
        v2 += 24;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[1047908])
            return 0;
    }
    return ((1 << a1) & *(_DWORD*)& byte_5D4594[24 * v1 + 1047776]) != 0;
}

//----- (004611A0) --------------------------------------------------------
int sub_4611A0()
{
    return *(_DWORD*)& byte_5D4594[1047932];
}

//----- (004611B0) --------------------------------------------------------
int sub_4611B0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1047936];
    if (*(_DWORD*)& byte_5D4594[1047936])
    {
        result = sub_45DAF0(*(int*)& byte_5D4594[1047936]);
        *(_DWORD*)& byte_5D4594[1047936] = 0;
        *(_DWORD*)& byte_5D4594[1047932] = 0;
    }
    return result;
}

//----- (004611E0) --------------------------------------------------------
void __cdecl sub_4611E0(int a1, int a2, char* a3)
{
    unsigned __int8* v3; // esi

    if (a1 >= 1 && a1 < 6)
    {
        v3 = &byte_5D4594[1047804];
        do
        {
            if (*((_DWORD*)v3 - 4) == a1 && *(_DWORD*)v3 != a2)
            {
                if (sub_40A5C0(2) && *(_DWORD*)& byte_5D4594[2618908])
                    * (_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 4 * a1 + 3696) = a2;
                *(_DWORD*)v3 = a2;
                if (a2)
                    sub_45D290(a1, a3, (int)a3);
            }
            v3 += 24;
        } while ((int)v3 < (int)& byte_5D4594[1047924]);
    }
}

//----- (00461250) --------------------------------------------------------
int sub_461250()
{
    int v0; // ecx
    int v1; // esi
    _DWORD* v2; // eax

    v0 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
    do
    {
        v1 = 0;
        v2 = (_DWORD*)(*(_DWORD*)& byte_587000[133480] + 40 * v0);
        do
        {
            if (!*v2)
            {
                sub_45E110(v0);
                return v1;
            }
            ++v1;
            v2 += 2;
        } while (v1 < 5);
        if (++v0 >= 5)
            v0 = 0;
    } while (v0 != *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200));
    return -1;
}

//----- (004612A0) --------------------------------------------------------
int sub_4612A0()
{
    int result; // eax
    _DWORD* i; // ecx

    result = 0;
    for (i = (_DWORD*)(*(_DWORD*)& byte_587000[133480] + 40
        * *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200));
        *i;
        i += 2)
    {
        if (++result >= 5)
            return -1;
    }
    return result;
}

//----- (004612D0) --------------------------------------------------------
int __cdecl sub_4612D0(int a1)
{
    int v1; // edx
    int v2; // eax
    _DWORD* v3; // ecx

    v1 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
    do
    {
        v2 = 0;
        v3 = (_DWORD*)(*(_DWORD*)& byte_587000[133480] + 40 * v1);
        do
        {
            if (*v3 == a1)
                return 1;
            ++v2;
            v3 += 2;
        } while (v2 < 5);
        if (++v1 >= 5)
            v1 = 0;
    } while (v1 != *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200));
    return 0;
}

//----- (00461320) --------------------------------------------------------
void __cdecl sub_461320(int a1, _DWORD* a2)
{
    if (a2)
    {
        if (a1 >= 0 && a1 < 5)
            sub_46AA60(*(_DWORD * *)(*(_DWORD*)& byte_587000[133480] + 4 * a1 + 212), a2, a2 + 1);
    }
}

//----- (00461360) --------------------------------------------------------
int __cdecl sub_461360(int a1)
{
    int v1; // edx
    int v2; // ecx
    int v3; // ebx
    int v4; // esi
    int result; // eax

    v1 = *(_DWORD*)& byte_587000[133480];
    v2 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
    v3 = *(unsigned __int8*)(*(_DWORD*)& byte_587000[133480] + 200);
    do
    {
        v4 = 5;
        result = 40 * v2;
        do
        {
            if (*(_DWORD*)(result + v1) == a1)
            {
                *(_DWORD*)(result + v1) = 0;
                v1 = *(_DWORD*)& byte_587000[133480];
            }
            result += 8;
            --v4;
        } while (v4);
        if (++v2 >= 5)
            v2 = 0;
    } while (v2 != v3);
    return result;
}

//----- (004613B0) --------------------------------------------------------
int sub_4613B0()
{
    int v0; // ebp
    int v1; // edx
    int v2; // eax
    int v3; // edi
    int result; // eax
    int v5; // [esp+10h] [ebp-4h]

    v0 = *(_DWORD*)& byte_587000[133480];
    v1 = *(_DWORD*)& byte_587000[133480];
    v5 = 5;
    do
    {
        v2 = v1;
        v3 = 5;
        do
        {
            *(_DWORD*)& byte_5D4594[v2 + 1047564 - v0] = *(_DWORD*)v2;
            byte_5D4594[v2 + 1047568 - v0] = *(_BYTE*)(v2 + 4);
            v2 += 40;
            --v3;
        } while (v3);
        v1 += 8;
        result = --v5;
    } while (v5);
    return result;
}

//----- (00461400) --------------------------------------------------------
int sub_461400()
{
    int i; // esi
    int result; // eax
    int v2; // ecx

    for (i = 0; i < 40; i += 8)
    {
        result = i;
        v2 = 5;
        do
        {
            *(_DWORD*)(result + *(_DWORD*)& byte_587000[133480]) = *(_DWORD*)& byte_5D4594[result + 1047564];
            *(_BYTE*)(result + *(_DWORD*)& byte_587000[133480] + 4) = byte_5D4594[result + 1047568];
            result += 40;
            --v2;
        } while (v2);
    }
    return result;
}

//----- (00461440) --------------------------------------------------------
int __cdecl sub_461440(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1049688] = a1;
    return result;
}

//----- (00461450) --------------------------------------------------------
int sub_461450()
{
    return *(_DWORD*)& byte_5D4594[1049688];
}

//----- (00461460) --------------------------------------------------------
int __cdecl sub_461460(int a1)
{
    int v1; // eax
    char v2; // cl
    char v3; // dl
    int v4; // eax
    char v5; // cl
    char v6; // dl
    int v7; // eax
    char v8; // cl
    char v9; // dl
    int v10; // eax
    char v11; // cl
    char v12; // dl
    int result; // eax

    v1 = sub_4344A0(*(_BYTE*)(a1 + 2253), *(_BYTE*)(a1 + 2254), *(_BYTE*)(a1 + 2255));
    v2 = *(_BYTE*)(a1 + 2257);
    v3 = *(_BYTE*)(a1 + 2256);
    *(_DWORD*)(a1 + 2296) = v1;
    v4 = sub_4344A0(v3, v2, *(_BYTE*)(a1 + 2258));
    v5 = *(_BYTE*)(a1 + 2260);
    v6 = *(_BYTE*)(a1 + 2259);
    *(_DWORD*)(a1 + 2292) = v4;
    v7 = sub_4344A0(v6, v5, *(_BYTE*)(a1 + 2261));
    v8 = *(_BYTE*)(a1 + 2263);
    v9 = *(_BYTE*)(a1 + 2262);
    *(_DWORD*)(a1 + 2300) = v7;
    v10 = sub_4344A0(v9, v8, *(_BYTE*)(a1 + 2264));
    v11 = *(_BYTE*)(a1 + 2266);
    v12 = *(_BYTE*)(a1 + 2265);
    *(_DWORD*)(a1 + 2304) = v10;
    *(_DWORD*)(a1 + 2308) = sub_4344A0(v12, v11, *(_BYTE*)(a1 + 2267));
    result = *(_DWORD*)& byte_5D4594[2523948];
    *(_DWORD*)(a1 + 2312) = *(_DWORD*)& byte_5D4594[2523948];
    return result;
}

//----- (00461520) --------------------------------------------------------
char* sub_461520()
{
    char* result; // eax
    int i; // esi

    result = sub_416EA0();
    for (i = (int)result; result; i = (int)result)
    {
        sub_461460(i);
        result = sub_416EE0(i);
    }
    return result;
}

//----- (00461550) --------------------------------------------------------
int __cdecl sub_461550(int a1)
{
    if (*(_DWORD*)& byte_5D4594[1062480])
        * (_DWORD*)& byte_5D4594[1062484] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 4);
    else
        *(_DWORD*)& byte_5D4594[1062484] = 0;
    *(_DWORD*)& byte_5D4594[1062480] = a1;
    sub_4619F0();
    if (!*(_DWORD*)& byte_5D4594[1062480])
        return sub_4BF010(0);
    *(_DWORD*)(**(_DWORD * *)& byte_5D4594[1062480] + 128) = *(_DWORD*)(a1 + 4);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 136) = 1;
    return sub_4BF010(**(_DWORD * *)& byte_5D4594[1062480]);
}

//----- (004615C0) --------------------------------------------------------
int sub_4615C0()
{
    int v0; // eax
    int v1; // ecx

    v0 = *(_DWORD*)& byte_5D4594[1063640];
    if (!*(_DWORD*)& byte_5D4594[1063640])
    {
        v0 = sub_44CFC0((CHAR*)& byte_587000[136416]);
        *(_DWORD*)& byte_5D4594[1063640] = v0;
    }
    if (!*(_DWORD*)& byte_5D4594[1049904])
        return *(_DWORD*)& byte_5D4594[1049900];
    v1 = *(_DWORD*)& byte_5D4594[1049904];
    while (*(_DWORD*)(v1 + 108) != v0)
    {
        v1 = *(_DWORD*)(v1 + 368);
        if (!v1)
            return *(_DWORD*)& byte_5D4594[1049900];
    }
    return *(_DWORD*)& byte_5D4594[1049904];
}

//----- (00461600) --------------------------------------------------------
int __cdecl sub_461600(int a1)
{
    int* v1; // ecx
    int result; // eax

    v1 = (int*)& byte_5D4594[1049872];
    while (1)
    {
        result = *v1;
        if (*v1)
            break;
    LABEL_5:
        ++v1;
        if ((int)v1 >= (int)& byte_5D4594[1049908])
            return 0;
    }
    while (*(_DWORD*)(result + 108) != a1)
    {
        result = *(_DWORD*)(result + 368);
        if (!result)
            goto LABEL_5;
    }
    return result;
}

//----- (00461630) --------------------------------------------------------
int __cdecl sub_461630(__int16 a1)
{
    int v1; // ecx
    char v3[3]; // [esp+0h] [ebp-4h]
    char v4; // [esp+3h] [ebp-1h]

    v4 = HIBYTE(v1);
    v3[0] = -15;
    *(_WORD*)& v3[1] = a1;
    return sub_4E53C0(31, v3, 3, 0, 0);
}

//----- (00461660) --------------------------------------------------------
int __cdecl sub_461660(int a1, int a2, const void* a3)
{
    int* v3; // eax
    wchar_t* v4; // eax
    int v6; // ecx
    int v7; // edx
    int v8; // eax
    int2 a4; // [esp+8h] [ebp-8h]

    if (a2 != *(_DWORD*)& byte_5D4594[1062560]
        && a2 != *(_DWORD*)& byte_5D4594[1049728]
        && a2 != *(_DWORD*)& byte_5D4594[1049724]
        && a2 != *(_DWORD*)& byte_5D4594[1062556]
        && a2 != *(_DWORD*)& byte_5D4594[1062564])
    {
        v3 = sub_461970(a1, a2);
        if (v3)
        {
            if (*(_BYTE*)(*v3 + 112) & 0x10)
                sub_472310();
        }
        else
        {
            if (!sub_4617C0(a1, a2, a3, &a4))
            {
                v4 = loadString_sub_40F1D0((char*)& byte_587000[136456], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 682);
                sub_445490(v4);
                return 0;
            }
            v6 = a4.field_0;
            v7 = a4.field_4;
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[148 * (a4.field_4 + 14 * a4.field_0 + 7 * a4.field_0) + 1050020] + 112) & 0x10)
            {
                sub_472310();
                v7 = a4.field_4;
                v6 = a4.field_0;
            }
            if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[148 * (v7 + 14 * v6 + 7 * v6) + 1050020] + 112) & 0x3001000)
            {
                *(_DWORD*)& byte_5D4594[1062516] = 0;
                if (v7 >= 3)
                    * (_DWORD*)& byte_5D4594[1062516] = 10 * (5 * v7 - 10);
            }
        }
        v8 = nox_get_thing(a2);
        if (v8)
        {
            if (*(_DWORD*)(v8 + 32) & 0x1001000)
                sub_4673F0(a4.field_0, a4.field_4);
        }
    }
    return 1;
}

//----- (004617C0) --------------------------------------------------------
int __cdecl sub_4617C0(int a1, int a2, const void* a3, int2* a4)
{
    unsigned __int16 v4; // di
    unsigned __int16 i; // dx
    int result; // eax
    int v7; // ebp
    int v8; // esi
    unsigned __int8* v9; // ebx
    _DWORD* v10; // eax
    wchar_t* v11; // eax
    int v12; // eax
    int v13; // eax
    int v14; // ecx
    _DWORD* v15; // esi

    v4 = 0;
    while (1)
    {
        for (i = 0; i < 4u; ++i)
        {
            if (!byte_5D4594[148 * (v4 + 14 * i + 7 * i) + 1050160])
            {
                v7 = i;
                v8 = v4;
                v9 = &byte_5D4594[148 * (v4 + 14 * i + 7 * i) + 1050020];
                v10 = sub_45A240(a2);
                *(_DWORD*)v9 = v10;
                if (v10)
                {
                    v10[30] |= 0x40000000u;
                    v12 = *(_DWORD*)v9;
                    *((_DWORD*)v9 + 1) = a1;
                    v9[140] = 1;
                    if (*(_DWORD*)(v12 + 112) & 0x13001000)
                    {
                        qmemcpy((void*)(v12 + 432), a3, 0x14u);
                        v8 = v4;
                    }
                    if (a4)
                    {
                        a4->field_0 = v7;
                        a4->field_4 = v8;
                    }
                    if (sub_461930() && !*(_DWORD*)& byte_5D4594[1062480])
                    {
                        if ((v13 = *(_DWORD*)v9, v14 = *(_DWORD*)(*(_DWORD*)v9 + 112), v14 & 0x1000000)
                            && !(*(_BYTE*)(v13 + 116) & 2)
                            || v14 & 0x1000)
                        {
                            v15 = sub_413250(*(_DWORD*)(v13 + 108));
                            if (!v15
                                || (unsigned __int8)(1 << *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251)) & *((_BYTE*)v15 + 62))
                            {
                                sub_461550((int)v9);
                                *((_DWORD*)v9 + 34) = 1;
                            }
                        }
                    }
                    result = 1;
                }
                else
                {
                    v11 = loadString_sub_40F1D0((char*)& byte_587000[136508], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 550);
                    sub_445490(v11);
                    result = 0;
                }
                return result;
            }
        }
        if (++v4 < 0x14u)
            continue;
        break;
    }
    return 0;
}

//----- (00461930) --------------------------------------------------------
int sub_461930()
{
    unsigned __int8* v0; // ecx
    int v1; // eax

    v0 = &byte_5D4594[1049872];
    while (1)
    {
        v1 = *(_DWORD*)v0;
        if (*(_DWORD*)v0)
            break;
    LABEL_5:
        v0 += 4;
        if ((int)v0 >= (int)& byte_5D4594[1049908])
            return 0;
    }
    while (!(*(_DWORD*)(v1 + 112) & 0x1001000))
    {
        v1 = *(_DWORD*)(v1 + 368);
        if (!v1)
            goto LABEL_5;
    }
    return 1;
}

//----- (00461970) --------------------------------------------------------
int* __cdecl sub_461970(int a1, int a2)
{
    int* v2; // edx
    int v3; // ecx
    int* result; // eax

    if (!(*(_DWORD*)(nox_get_thing(a2) + 32) & 0x4000000))
    {
        v2 = (int*)& byte_5D4594[1050020];
        while (1)
        {
            v3 = 0;
            result = v2;
            do
            {
                if (*((_BYTE*)result + 140) && *(_DWORD*)(*result + 108) == a2 && *((_BYTE*)result + 140) < 0x20u)
                {
                    result[(unsigned __int8)(*((_BYTE*)result + 140))++ + 1] = a1;
                    return result;
                }
                ++v3;
                result += 777;
            } while (v3 < 4);
            v2 += 37;
            if ((int)v2 < (int)& byte_5D4594[1052980])
                continue;
            break;
        }
    }
    return 0;
}

//----- (004619F0) --------------------------------------------------------
char* sub_4619F0()
{
    char* v0; // edi
    char* result; // eax
    int v2; // esi
    int v3; // ecx

    v0 = (char*)& byte_5D4594[1050160];
    do
    {
        result = v0;
        v2 = 4;
        do
        {
            v3 = 0;
            if ((unsigned __int8)* result > 0u)
            {
                do
                {
                    *((_DWORD*)result - 1) = 0;
                    ++v3;
                } while (v3 < (unsigned __int8)* result);
            }
            result += 3108;
            --v2;
        } while (v2);
        v0 += 148;
    } while ((int)v0 <= (int)& byte_5D4594[1053120]);
    return result;
}

//----- (00461A30) --------------------------------------------------------
int __cdecl sub_461A30(int a1, int a2)
{
    int v2; // esi
    wchar_t* v4; // eax

    v2 = *(_DWORD*)(a1 + 396);
    if (a2 != 6)
        return 0;
    *(_DWORD*)& byte_5D4594[1049864] = 4;
    v4 = loadString_sub_40F1D0((char*)& byte_587000[136564], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1220);
    sub_445490(v4);
    sub_46ADC0(v2);
    return 1;
}

//----- (00461A80) --------------------------------------------------------
void __cdecl sub_461A80(int a1)
{
    int v1; // ebx
    char* v2; // esi
    _QWORD* v3; // eax
    _QWORD* v4; // eax
    wchar_t* v5; // eax

    v1 = 0;
    v2 = sub_461EF0(a1);
    if (v2)
    {
        if (*(_BYTE*)(**(_DWORD * *)v2 + 112) & 0x10)
            v1 = 1;
        sub_461E60((_QWORD * **)v2);
        *(_DWORD*)(*(_DWORD*)v2 + 132) = 0;
        sub_461B50();
        v3 = (_QWORD*)sub_461F90(a1);
        if (v3)
            sub_45A4B0(v3);
        if (v1)
            sub_472310();
    }
    else
    {
        v4 = *(_QWORD * *)& byte_5D4594[1049848];
        if (*(_DWORD*)& byte_5D4594[1049848] && *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) == a1)
        {
            if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x10)
            {
                sub_472310();
                v4 = *(_QWORD * *)& byte_5D4594[1049848];
            }
            sub_45A4B0(v4);
            *(_DWORD*)& byte_5D4594[1049848] = 0;
            *(_DWORD*)& byte_5D4594[1049856] = 0;
            sub_4776A0();
        }
        else
        {
            v5 = loadString_sub_40F1D0((char*)& byte_587000[136616], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1439);
            sub_445490(v5);
        }
    }
}

//----- (00461B50) --------------------------------------------------------
unsigned __int8* sub_461B50()
{
    int v0; // ebx
    unsigned __int8* result; // eax
    int v2; // ebp
    int v3; // ecx
    int v4; // edi
    int v5; // esi
    int v6; // ebx
    int v7; // eax
    unsigned __int8* v8; // edx
    unsigned __int8* v9; // eax
    int v10; // ecx
    int v11; // ecx
    int v12; // edx
    int i; // eax
    int v14; // ebp
    bool v15; // cc
    int j; // esi
    int v17; // edx
    int v18; // ecx
    int* v19; // [esp+10h] [ebp-38h]
    unsigned __int8* v20; // [esp+14h] [ebp-34h]
    int* v21; // [esp+18h] [ebp-30h]
    int v22; // [esp+1Ch] [ebp-2Ch]
    int v23; // [esp+20h] [ebp-28h]
    int v24; // [esp+24h] [ebp-24h]
    int v25; // [esp+28h] [ebp-20h]
    int* v26; // [esp+2Ch] [ebp-1Ch]
    int v27; // [esp+30h] [ebp-18h]
    unsigned __int8* v28; // [esp+38h] [ebp-10h]
    unsigned __int8* v29; // [esp+3Ch] [ebp-Ch]
    int v30; // [esp+40h] [ebp-8h]

    v0 = 0;
    result = &byte_5D4594[1050156];
    v25 = 0;
    v26 = (int*)& byte_5D4594[1050156];
LABEL_2:
    v2 = 0;
    v24 = 0;
    v21 = (int*)(result - 136);
    v20 = result;
    v19 = (int*)(result + 4);
    while (*(_BYTE*)v19)
    {
    LABEL_35:
        v24 = ++v2;
        v19 += 777;
        v20 += 3108;
        v21 += 777;
        if (v2 >= 4)
        {
            result += 148;
            v25 = ++v0;
            v26 = (int*)result;
            if ((int)result >= (int)& byte_5D4594[1053116])
                return result;
            goto LABEL_2;
        }
    }
    v3 = v0;
    v27 = v0;
    if ((int)result < (int)& byte_5D4594[1053116])
    {
    LABEL_5:
        if (v3 == v0)
        {
            v4 = v2;
            v22 = v2;
        }
        else
        {
            v4 = 0;
            v22 = 0;
        }
        result = &byte_5D4594[148 * (v3 + 14 * v4 + 7 * v4) + 1050160];
        while (!*result)
        {
            ++v4;
            result += 3108;
            v22 = v4;
            if (v4 >= 4)
            {
                v27 = ++v3;
                if (v3 >= 20)
                    goto LABEL_38;
                goto LABEL_5;
            }
        }
        v5 = 7 * v4 + v3 + 14 * v4;
        v6 = 148 * v5;
        v7 = *(_DWORD*)& byte_5D4594[148 * v5 + 1050020];
        v8 = &byte_5D4594[148 * v5 + 1050020];
        v29 = &byte_5D4594[148 * v5 + 1050020];
        v30 = *(_DWORD*)(v7 + 108);
        if (!(*(_DWORD*)(v7 + 112) & 0x4000000))
        {
            v9 = &byte_5D4594[1050160];
            v23 = 0;
            v28 = &byte_5D4594[1050160];
            while (1)
            {
                v10 = 0;
                while (!*v9 || *v9 == 32 || *(_DWORD*)(*((_DWORD*)v9 - 35) + 108) != v30 || v10 == v4 && v23 == v27)
                {
                    ++v10;
                    v9 += 3108;
                    if (v10 >= 4)
                        goto LABEL_28;
                }
                v11 = 7 * v10 + v23 + 14 * v10;
                v12 = byte_5D4594[148 * v11 + 1050160];
                for (i = byte_5D4594[v6 + 1050160]; i > 0; v6 = 148 * v5)
                {
                    if (v12 == 32)
                        break;
                    --i;
                    v14 = v12++ + v11;
                    *(_DWORD*)& byte_5D4594[4 * (v14 + 36 * v11) + 1050024] = *(_DWORD*)& byte_5D4594[4 * (i + v5 + 36 * v5)
                        + 1050024];
                    v4 = v22;
                }
                byte_5D4594[148 * v11 + 1050160] = v12;
                if (i <= 0)
                {
                    byte_5D4594[v6 + 1050160] = 0;
                    sub_45A4B0(*(_QWORD * *)v29);
                    v0 = v25;
                    *(_DWORD*)v29 = 0;
                    v2 = v24 - 1;
                    v21 -= 777;
                    result = (unsigned __int8*)v26;
                    v19 -= 777;
                    v20 -= 3108;
                    goto LABEL_35;
                }
                byte_5D4594[v6 + 1050160] = i;
            LABEL_28:
                v9 = v28 + 148;
                v15 = (int)(v28 + 148) < (int)& byte_5D4594[1053120];
                ++v23;
                v28 += 148;
                if (v15)
                    continue;
                break;
            }
            v2 = v24;
            v8 = &byte_5D4594[148 * v5 + 1050020];
        }
        qmemcpy(v21, v8, 0x94u);
        if (*(_DWORD*)v20)
            * (_DWORD*)& byte_5D4594[1062480] = v21;
        result = (unsigned __int8*)v26;
        byte_5D4594[v6 + 1050160] = 0;
        *(_DWORD*)v8 = 0;
        *(_DWORD*)& byte_5D4594[v6 + 1050152] = 0;
        v0 = v25;
        goto LABEL_35;
    }
LABEL_38:
    for (j = v0; j < 20; ++j)
    {
        if (j == v0)
            v17 = v2;
        else
            v17 = 0;
        v18 = 4 - v17;
        result = &byte_5D4594[148 * (j + 14 * v17 + 7 * v17) + 1050156];
        do
        {
            *((_DWORD*)result - 1) = 0;
            *(_DWORD*)result = 0;
            result += 3108;
            --v18;
        } while (v18);
    }
    return result;
}

//----- (00461E60) --------------------------------------------------------
_QWORD** __cdecl sub_461E60(_QWORD*** a1)
{
    _QWORD** v1; // eax
    int v2; // edi
    int v3; // ecx
    _QWORD** result; // eax

    v1 = *a1;
    v2 = (int)a1[1];
    if (v2 < *((unsigned __int8*)* a1 + 140) - 1)
    {
        v3 = 4 * v2 + 4;
        do
        {
            ++v2;
            *(_QWORD * *)((char*)v1 + v3) = *(_QWORD * *)((char*)v1 + v3 + 4);
            v1 = *a1;
            v3 += 4;
        } while (v2 < *((unsigned __int8*)* a1 + 140) - 1);
    }
    if (!-- * ((_BYTE*)* a1 + 140))
    {
        sub_45A4B0(**a1);
        **a1 = 0;
    }
    result = (_QWORD * *)(*a1)[34];
    if (result)
    {
        sub_461550(0);
        result = *a1;
        (*a1)[34] = 0;
    }
    return result;
}

//----- (00461EF0) --------------------------------------------------------
char* __cdecl sub_461EF0(int a1)
{
    unsigned __int8* v1; // ebx
    int v2; // edi
    unsigned __int8* v3; // esi
    int v4; // eax
    int v5; // edx
    unsigned __int8* v6; // ecx
    char* result; // eax
    int v8; // [esp+10h] [ebp-4h]

    v8 = 0;
    v1 = &byte_5D4594[1050160];
    while (1)
    {
        v2 = 0;
        v3 = v1;
        do
        {
            v4 = 0;
            v5 = *v3;
            if (v5 > 0)
            {
                v6 = v3 - 136;
                while (*(_DWORD*)v6 != a1)
                {
                    ++v4;
                    v6 += 4;
                    if (v4 >= v5)
                        goto LABEL_7;
                }
                *(_DWORD*)& byte_5D4594[1049792] = v4;
                result = (char*)& byte_5D4594[1049788];
                *(_DWORD*)& byte_5D4594[1049788] = &byte_5D4594[148 * (v8 + 14 * v2 + 7 * v2) + 1050020];
                return result;
            }
        LABEL_7:
            ++v2;
            v3 += 3108;
        } while (v2 < 4);
        v1 += 148;
        ++v8;
        if ((int)v1 <= (int)& byte_5D4594[1053120])
            continue;
        return 0;
    }
}

//----- (00461F90) --------------------------------------------------------
int __cdecl sub_461F90(int a1)
{
    int v1; // ecx
    unsigned __int8* v2; // eax
    int v3; // esi
    int v5; // eax
    int v6; // eax
    int v7; // eax

    v1 = 0;
    v2 = &byte_5D4594[1049872];
    while (1)
    {
        v3 = *(_DWORD*)v2;
        if (*(_DWORD*)v2)
            break;
    LABEL_5:
        v2 += 4;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[1049908])
            return 0;
    }
    while (*(_DWORD*)(v3 + 128) != a1)
    {
        v3 = *(_DWORD*)(v3 + 368);
        if (!v3)
            goto LABEL_5;
    }
    v5 = *(_DWORD*)(v3 + 372);
    if (v5)
        * (_DWORD*)(v5 + 368) = *(_DWORD*)(v3 + 368);
    else
        *(_DWORD*)& byte_5D4594[4 * v1 + 1049872] = *(_DWORD*)(v3 + 368);
    v6 = *(_DWORD*)(v3 + 368);
    if (v6)
        * (_DWORD*)(v6 + 372) = *(_DWORD*)(v3 + 372);
    v7 = *(_DWORD*)(v3 + 112);
    if (v7 & 0x1000 || sub_415880(*(char**)(v3 + 108)) == 2 || sub_415880(*(char**)(v3 + 108)) == 128)
        sub_470D70();
    return v3;
}

//----- (00462040) --------------------------------------------------------
void __cdecl sub_462040(int a1)
{
    int v1; // edi
    char* v2; // ebp
    int v3; // eax
    const void* v4; // esi
    _DWORD* v5; // eax
    _DWORD* v6; // ebx
    wchar_t* v7; // eax
    int v8; // eax
    int v9; // esi
    int v10; // edi
    char* v11; // eax
    unsigned __int8* v12; // ebp
    int v13; // ecx
    unsigned __int8* v14; // eax
    int v15; // eax
    __int16 v16; // ax
    int* v17; // eax
    __int16 v18; // [esp+10h] [ebp-Ch]
    __int16 v19; // [esp+14h] [ebp-8h]
    int v20; // [esp+20h] [ebp+4h]

    v1 = a1;
    v2 = sub_461EF0(a1);
    if (v2)
    {
        v20 = sub_4622E0(**(_DWORD * *)v2);
        v3 = **(_DWORD * *)v2;
    }
    else
    {
        if (!*(_DWORD*)& byte_5D4594[1049848] || *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) != a1)
        {
            v7 = loadString_sub_40F1D0((char*)& byte_587000[136668], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1605);
            goto LABEL_36;
        }
        v20 = sub_4622E0(*(int*)& byte_5D4594[1049848]);
        v3 = *(_DWORD*)& byte_5D4594[1049848];
    }
    v4 = (const void*)(v3 + 432);
    v19 = *(_WORD*)(v3 + 294);
    v18 = *(_WORD*)(v3 + 292);
    if (v20 == 9)
    {
        v7 = loadString_sub_40F1D0((char*)& byte_587000[136780], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1701);
        goto LABEL_36;
    }
    v5 = sub_45A240(*(_DWORD*)(v3 + 108));
    v6 = v5;
    if (!v5)
    {
        v7 = loadString_sub_40F1D0((char*)& byte_587000[136724], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1619);
    LABEL_36:
        sub_445490(v7);
        return;
    }
    v8 = v5[30];
    v6[32] = v1;
    v6[30] = v8 | 0x40000000;
    qmemcpy(v6 + 108, v4, 0x18u);
    *((_WORD*)v6 + 146) = v18;
    *((_WORD*)v6 + 147) = v19;
    sub_4623E0(v6, v20);
    v9 = 0;
    if (v2)
    {
        *(_DWORD*)(*(_DWORD*)v2 + 132) = 1;
        if (*(_DWORD*)(*(_DWORD*)v2 + 136))
        {
            sub_461550(0);
            *(_DWORD*)(*(_DWORD*)v2 + 136) = 0;
        }
    }
    if (v6[28] & 0x1000000 && v6[29] & 0xC)
    {
        v10 = 1;
        if (*(_DWORD*)& byte_5D4594[1062488] && (v11 = sub_461EF0(*(int*)& byte_5D4594[1062488])) != 0)
        {
            *(_DWORD*)(**(_DWORD * *)v11 + 128) = *(_DWORD*)(*(_DWORD*)v11 + 4);
            sub_4623B0(**(_DWORD * *)v11);
        }
        else
        {
            v12 = &byte_5D4594[1050020];
            do
            {
                if (!v10)
                    break;
                v13 = 0;
                v14 = v12;
                while (!v14[140] || !(*(_BYTE*)(*(_DWORD*)v14 + 115) & 1) || *(_DWORD*)(*(_DWORD*)v14 + 116) != 2)
                {
                    ++v13;
                    v14 += 3108;
                    if (v13 >= 4)
                        goto LABEL_26;
                }
                v15 = 148 * (v9 + 14 * v13 + 7 * v13);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[v15 + 1050020] + 128) = *(_DWORD*)& byte_5D4594[v15 + 1050024];
                sub_4623B0(*(_DWORD*)& byte_5D4594[v15 + 1050020]);
                v10 = 0;
            LABEL_26:
                v12 += 148;
                ++v9;
            } while ((int)v12 < (int)& byte_5D4594[1052980]);
        }
    }
    if (!v20)
        * (_DWORD*)& byte_5D4594[1062488] = v6[32];
    v16 = *((_WORD*)v6 + 224);
    if (v16 >= 0)
        sub_470D90(v16, *((__int16*)v6 + 225));
    if (*(_DWORD*)& byte_5D4594[1062496])
    {
        v17 = (int*)sub_461EF0(*(int*)& byte_5D4594[1062496]);
        if (v17)
        {
            *(_DWORD*)(*v17 + 136) = 1;
            sub_461550(*v17);
            *(_DWORD*)& byte_5D4594[1062496] = 0;
        }
    }
}

//----- (004622E0) --------------------------------------------------------
int __cdecl sub_4622E0(int a1)
{
    int v1; // edi
    int result; // eax

    v1 = *(_DWORD*)(a1 + 112);
    if (*(_DWORD*)(a1 + 112) & 0x1000000 && *(_BYTE*)(a1 + 116) & 2)
        return 0;
    if (!(v1 & 0x2000000) || (result = 1, !(*(_BYTE*)(a1 + 116) & 1)))
    {
        if (v1 & 0x2000000)
        {
            if (*(_DWORD*)(a1 + 116) & 0x144)
                return 2;
            if (*(_BYTE*)(a1 + 116) & 0x90)
                return 3;
            if (*(_BYTE*)(a1 + 116) & 0x20)
                return 4;
            if (*(_BYTE*)(a1 + 116) & 2)
                return 8;
            if (*(_BYTE*)(a1 + 116) & 8)
                return 5;
        }
        if (*(_DWORD*)(a1 + 112) & 0x1000000)
        {
            if (*(_BYTE*)(a1 + 116) & 4)
                return 8;
            return 7;
        }
        if (v1 & 0x1000)
            return 7;
        result = 9;
    }
    return result;
}

//----- (004623B0) --------------------------------------------------------
int __cdecl sub_4623B0(int a1)
{
    int v1; // ecx
    char v3[3]; // [esp+0h] [ebp-4h]
    char v4; // [esp+3h] [ebp-1h]

    v4 = HIBYTE(v1);
    v3[0] = 117;
    *(_WORD*)& v3[1] = sub_578B00(a1);
    return sub_40EBC0(31, 0, v3, 3);
}

//----- (004623E0) --------------------------------------------------------
_DWORD* __cdecl sub_4623E0(_DWORD* a1, int a2)
{
    int v2; // ebx
    _DWORD* result; // eax
    int v4; // ecx
    int v5; // ecx

    if (!(a1[28] & 0x2000000))
        goto LABEL_19;
    v2 = a1[29];
    if (v2 & 0x140)
    {
        result = *(_DWORD * *)& byte_5D4594[4 * a2 + 1049872];
        if (!result)
            goto LABEL_19;
        while (result[92])
            result = (_DWORD*)result[92];
        if (!result)
            goto LABEL_19;
        if (v2 & 0x40)
        {
            if (result[28] & 0x2000000)
            {
                v4 = result[29];
                if (v4 & 0x100)
                    result = (_DWORD*)result[93];
            }
        }
    }
    else
    {
        if (!(v2 & 0x10))
            goto LABEL_19;
        result = *(_DWORD * *)& byte_5D4594[4 * a2 + 1049872];
        if (!result)
            goto LABEL_19;
        while (result[92])
            result = (_DWORD*)result[92];
    }
    if (result)
    {
        v5 = result[92];
        if (v5)
            * (_DWORD*)(v5 + 372) = a1;
        a1[92] = result[92];
        result[92] = a1;
        a1[93] = result;
        return result;
    }
LABEL_19:
    a1[93] = 0;
    a1[92] = *(_DWORD*)& byte_5D4594[4 * a2 + 1049872];
    result = *(_DWORD * *)& byte_5D4594[4 * a2 + 1049872];
    if (result)
        result[93] = a1;
    *(_DWORD*)& byte_5D4594[4 * a2 + 1049872] = a1;
    return result;
}

//----- (004624D0) --------------------------------------------------------
int __cdecl sub_4624D0(int a1)
{
    int result; // eax
    int v2; // edi
    int* v3; // eax
    int* v4; // esi

    result = sub_461F90(a1);
    v2 = result;
    if (!result)
        return result;
    v3 = (int*)sub_461EF0(a1);
    v4 = v3;
    if (!v3)
        return sub_45A4B0((_QWORD*)v2);
    *(_DWORD*)(*v3 + 132) = 0;
    if (*(_DWORD*)& byte_5D4594[1062492] != v2)
    {
        if (sub_415880(*(char**)(v2 + 108)) & 0xC
            && *(_DWORD*)& byte_5D4594[1062480]
            && sub_415880(*(char**)(**(_DWORD * *)& byte_5D4594[1062480] + 108)) == 2)
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 136) = 0;
            sub_461550(0);
        }
        return sub_45A4B0((_QWORD*)v2);
    }
    *(_DWORD*)& byte_5D4594[1062492] = 0;
    if (*(_DWORD*)& byte_5D4594[1062480])
    {
        *(_DWORD*)& byte_5D4594[1062496] = *(_DWORD*)(v2 + 128);
        *(_DWORD*)(**(_DWORD * *)& byte_5D4594[1062480] + 128) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 4);
        sub_4623B0(**(_DWORD * *)& byte_5D4594[1062480]);
    }
    else
    {
        sub_461550(*v3);
        *(_DWORD*)(*v4 + 136) = 1;
    }
    return sub_45A4B0((_QWORD*)v2);
}

//----- (004625D0) --------------------------------------------------------
int __cdecl sub_4625D0(_DWORD* a1)
{
    __int16* v2; // eax
    int v3; // [esp+0h] [ebp-10h]
    int v4; // [esp+4h] [ebp-Ch]
    int v5; // [esp+8h] [ebp-8h]
    int v6; // [esp+Ch] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[1049864] == 5)
        return 1;
    sub_46AA60(a1, &v3, &v4);
    nox_window_get_size((int)a1, &v5, &v6);
    if (v4 + v6 > 0)
    {
        sub_434390(*(int*)& byte_5D4594[2523948]);
        if (*(_DWORD*)& byte_5D4594[1062480] && **(_DWORD * *)& byte_5D4594[1062480])
        {
            *(_DWORD*)(**(_DWORD * *)& byte_5D4594[1062480] + 12) = v3 + v5 / 2;
            *(_DWORD*)(**(_DWORD * *)& byte_5D4594[1062480] + 16) = v4 + v6 / 2;
            (*(void(__cdecl * *)(unsigned __int8*, _DWORD))(**(_DWORD * *)& byte_5D4594[1062480] + 300))(
                &byte_5D4594[1049732],
                **(_DWORD * *)& byte_5D4594[1062480]);
        }
        v2 = (__int16*)sub_42E8E0(35, 1);
        if (v2)
            sub_43F6E0(*(int*)& byte_5D4594[1063636], v2, v3 + 22, v4 + 41);
    }
    return 1;
}

//----- (004626C0) --------------------------------------------------------
double __cdecl sub_4626C0(int a1)
{
    int v1; // edx
    int* i; // ecx
    int v3; // eax

    if (!a1 || !(*(_DWORD*)(a1 + 112) & 0x13001000))
        return 0.0;
    v1 = 2;
    for (i = (int*)(a1 + 440); ; ++i)
    {
        v3 = *i;
        if (*i)
        {
            if (*(void(__cdecl * *)(int, int, int, int))(v3 + 52) == sub_4E06F0)
                break;
        }
        if (++v1 >= 4)
            return 0.0;
    }
    return *(float*)(v3 + 56);
}

//----- (00462700) --------------------------------------------------------
double __cdecl sub_462700(int a1)
{
    int v1; // edx
    int* i; // ecx
    int v3; // eax

    if (!a1 || !(*(_DWORD*)(a1 + 112) & 0x13001000))
        return 0.0;
    v1 = 2;
    for (i = (int*)(a1 + 440); ; ++i)
    {
        v3 = *i;
        if (*i)
        {
            if (*(_DWORD * (__cdecl * *)(int, int, int, int))(v3 + 52) == sub_4E0550)
                break;
        }
        if (++v1 >= 4)
            return 0.0;
    }
    return *(float*)(v3 + 56);
}

//----- (00462740) --------------------------------------------------------
int sub_462740()
{
    wchar_t* v0; // eax
    _DWORD* v1; // eax

    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1062476]))
        return 0;
    nox_window_set_hidden(*(int*)& byte_5D4594[1062476], 1);
    *(_DWORD*)& byte_5D4594[1063116] = 0;
    *(_DWORD*)& byte_5D4594[1063120] = 0;
    v0 = loadString_sub_40F1D0((char*)& byte_587000[136832], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2361);
    nox_wcscpy((wchar_t*)& byte_5D4594[1063124], v0);
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1062476], 9156);
    nox_window_call_field_94((int)v1, 16399, 0, 0);
    sub_46ADE0(*(int*)& byte_5D4594[1062456]);
    *(_DWORD*)& byte_5D4594[1049864] = 0;
    sub_477610(0);
    return 1;
}

//----- (004627F0) --------------------------------------------------------
int __cdecl sub_4627F0(_DWORD* a1)
{
    int2* v1; // esi
    int v2; // ebx
    int v3; // eax
    int result; // eax
    wchar_t* v5; // eax
    _DWORD* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // esi
    wchar_t* v11; // eax
    wchar_t* v12; // eax
    wchar_t* v13; // eax
    wchar_t* v14; // eax
    int v15; // eax
    int v16; // ecx
    float* v17; // eax
    double v18; // st7
    int v19; // ecx
    int v20; // eax
    wchar_t* v21; // eax
    wchar_t* v22; // eax
    int v23; // ecx
    int v24; // eax
    int v25; // ecx
    _DWORD* v26; // edi
    int v27; // eax
    double v28; // st7
    int v29; // eax
    double v30; // st7
    double v31; // st7
    double v32; // st7
    int v33; // eax
    wchar_t* v34; // eax
    wchar_t* v35; // eax
    wchar_t* v36; // eax
    wchar_t* v37; // eax
    wchar_t* v38; // eax
    int v39; // ecx
    _DWORD* v40; // eax
    wchar_t* v41; // eax
    wchar_t* v42; // eax
    int v43; // edi
    int v44; // ecx
    wchar_t* v45; // eax
    int v46; // ebx
    int v47; // ecx
    wchar_t* v48; // eax
    int v49; // eax
    _DWORD* v50; // eax
    wchar_t* v51; // [esp-Ch] [ebp-444h]
    wchar_t* v52; // [esp-Ch] [ebp-444h]
    wchar_t* v53; // [esp-Ch] [ebp-444h]
    wchar_t* v54; // [esp-4h] [ebp-43Ch]
    wchar_t* v55; // [esp-4h] [ebp-43Ch]
    int v56; // [esp+0h] [ebp-438h]
    double v57; // [esp+0h] [ebp-438h]
    double v58; // [esp+0h] [ebp-438h]
    double v59; // [esp+0h] [ebp-438h]
    double v60; // [esp+0h] [ebp-438h]
    double v61; // [esp+0h] [ebp-438h]
    double v62; // [esp+0h] [ebp-438h]
    int v63; // [esp+4h] [ebp-434h]
    int v64; // [esp+4h] [ebp-434h]
    float v65; // [esp+4h] [ebp-434h]
    int v66; // [esp+4h] [ebp-434h]
    int v67; // [esp+4h] [ebp-434h]
    float v68; // [esp+18h] [ebp-420h]
    float v69; // [esp+1Ch] [ebp-41Ch]
    float v70; // [esp+20h] [ebp-418h]
    float v71; // [esp+24h] [ebp-414h]
    float v72; // [esp+28h] [ebp-410h]
    int v73; // [esp+2Ch] [ebp-40Ch]
    int2 v74; // [esp+30h] [ebp-408h]
    wchar_t v75[256]; // [esp+38h] [ebp-400h]
    wchar_t v76[256]; // [esp+238h] [ebp-200h]

    v73 = 1;
    v1 = sub_4309F0();
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v2 = 0;
    sub_43F340(0);
    sub_43F320(0);
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_49CE30(*a1 + 11, a1[1] + 15, 200, 200);
    sub_463370(*(_DWORD * *)& byte_5D4594[1062456], v1, &v74);
    if (sub_4281F0(&v74, (int4*)& byte_587000[136352]) || sub_4281F0(&v74, (int4*)& byte_587000[136368]))
    {
        if (sub_4281F0(&v74, (int4*)& byte_587000[136368]) && (v74.field_4 - 13) / 50 != 1)
        {
            sub_477610(7);
            goto LABEL_14;
        }
    }
    else
    {
        if (sub_4281F0(&v74, (int4*)& byte_587000[136336]))
        {
            sub_477610(0);
            goto LABEL_14;
        }
        if (!sub_478030())
        {
            sub_477610(7);
            goto LABEL_14;
        }
        if (!sub_479870() || (LOBYTE(v3) = sub_479880(&v74), !v3))
        {
            sub_477610(7);
            goto LABEL_14;
        }
    }
    sub_477610(6);
LABEL_14:
    result = *(_DWORD*)& byte_5D4594[1063116];
    if (!*(_DWORD*)& byte_5D4594[1063116])
    {
        if (*(_DWORD*)& byte_5D4594[1063120])
        {
            *(_DWORD*)& byte_5D4594[1063120] = 0;
            v5 = loadString_sub_40F1D0((char*)& byte_587000[136900], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2529);
            nox_wcscpy((wchar_t*)& byte_5D4594[1063124], v5);
            v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1062476], 9156);
            result = nox_window_call_field_94((int)v6, 16399, 0, 0);
        }
        return result;
    }
    if (*(_DWORD*)& byte_5D4594[1063120] == *(_DWORD*)& byte_5D4594[1063116])
        return result;
    *(_DWORD*)& byte_5D4594[1063120] = *(_DWORD*)& byte_5D4594[1063116];
    v7 = loadString_sub_40F1D0((char*)& byte_587000[136968], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2545);
    nox_swprintf((wchar_t*)& byte_5D4594[1063124], L"%s ", v7);
    v8 = sub_4BF050(*(wchar_t**)& byte_5D4594[1063116]);
    nox_wcscpy(v75, v8);
    if (!nox_wcscmp(v75, (const wchar_t*)& byte_5D4594[1063652]))
        * (_DWORD*)& byte_5D4594[1063120] = 0;
    nox_wcscat((wchar_t*)& byte_5D4594[1063124], v75);
    v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1062476], 9151);
    sub_46AEE0((int)v9, (int)& byte_5D4594[1063124]);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1062476], 9156);
    nox_window_call_field_94((int)v10, 16399, 0, 0);
    if (sub_40A5C0(2048))
    {
        if (*(_WORD*)(*(_DWORD*)& byte_5D4594[1063116] + 294))
        {
            sub_4633B0(*(int*)& byte_5D4594[1063116], &v71, &v68);
            v63 = (int)v68;
            v56 = (int)v71;
            v11 = loadString_sub_40F1D0((char*)& byte_587000[137028], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2575);
            nox_swprintf(v75, v11, v56, v63);
        }
        else
        {
            v12 = loadString_sub_40F1D0((char*)& byte_587000[137084], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2583);
            nox_wcscpy(v75, v12);
        }
    }
    else
    {
        switch (sub_57B190(
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1063116] + 292),
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1063116] + 294)))
        {
        case 0:
            v13 = loadString_sub_40F1D0((char*)& byte_587000[137228], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2595);
            goto LABEL_30;
        case 1:
            v52 = loadString_sub_40F1D0((char*)& byte_587000[137292], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2599);
            nox_swprintf(v75, v52);
            break;
        case 2:
            v53 = loadString_sub_40F1D0((char*)& byte_587000[137356], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2603);
            nox_swprintf(v75, v53);
            break;
        case 3:
            v13 = loadString_sub_40F1D0((char*)& byte_587000[137420], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2607);
        LABEL_30:
            nox_swprintf(v75, v13);
            break;
        case 4:
            v51 = loadString_sub_40F1D0((char*)& byte_587000[137156], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2591);
            nox_swprintf(v75, v51);
            break;
        default:
            break;
        }
    }
    nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
    nox_window_call_field_94((int)v10, 16397, (int)& byte_5D4594[1063656], -1);
    v64 = *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[1063116] + 298);
    v14 = loadString_sub_40F1D0((char*)& byte_587000[137484], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2620);
    nox_swprintf(v75, v14, v64);
    nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
    nox_window_call_field_94((int)v10, 16397, (int)& byte_5D4594[1063660], -1);
    v15 = *(_DWORD*)& byte_5D4594[1063116];
    v16 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 112);
    if (!(v16 & 0x2000000))
    {
        if (!(v16 & 0x1001000))
            goto LABEL_72;
        v23 = *(_DWORD*)& byte_5D4594[2618908];
        LODWORD(v68) = *(_DWORD*)& byte_5D4594[1063116] + 432;
        v69 = 1.0;
        v70 = *(float*)& byte_5D4594[2618908];
        if (!*(_DWORD*)& byte_5D4594[1063644])
        {
            *(_DWORD*)& byte_5D4594[1063644] = sub_44CFC0((CHAR*)& byte_587000[137608]);
            v24 = sub_44CFC0((CHAR*)& byte_587000[137620]);
            v23 = *(_DWORD*)& byte_5D4594[2618908];
            *(_DWORD*)& byte_5D4594[1063648] = v24;
            v15 = *(_DWORD*)& byte_5D4594[1063116];
        }
        if (!v23 || !(*(_BYTE*)(v15 + 116) & 2))
            goto LABEL_50;
        v25 = *(_DWORD*)(v23 + 4);
        if (v25 & 4)
        {
            v26 = sub_413250(*(int*)& byte_5D4594[1063644]);
            v2 = 4;
        }
        else
        {
            if (!(v25 & 8))
                goto LABEL_50;
            v26 = sub_413250(*(int*)& byte_5D4594[1063648]);
            v2 = 8;
        }
        if (v26)
            goto LABEL_51;
        v15 = *(_DWORD*)& byte_5D4594[1063116];
    LABEL_50:
        v26 = sub_413250(*(_DWORD*)(v15 + 108));
    LABEL_51:
        v71 = sub_4626C0(*(int*)& byte_5D4594[1063116]);
        v72 = sub_462700(*(int*)& byte_5D4594[1063116]);
        v27 = *(_DWORD*)LODWORD(v68);
        if (*(_DWORD*)LODWORD(v68) && *(float* (__cdecl * *)(int, int, int, int, float*))(v27 + 40) == sub_4E04C0)
            v69 = *(float*)(v27 + 44);
        v28 = sub_4EF1E0(*(_DWORD*)(LODWORD(v70) + 2239), (int)v26);
        v29 = v26[1];
        v70 = v28 * v69 + v71 + v72;
        if (v29 == *(_DWORD*)& byte_5D4594[1063648] && sub_40A5C0(2048))
        {
            v30 = sub_419D40((void*)& byte_587000[137632]);
        }
        else
        {
            LODWORD(v68) = *((unsigned __int16*)v26 + 36);
            v30 = (double)SLODWORD(v68);
        }
        v68 = v30 * v69;
        v31 = v70 - v68 - v72 - v71;
        v69 = v31;
        if (v31 < 0.0)
        {
            v32 = v70 - v69;
            v69 = 0.0;
            v70 = v32;
        }
        v33 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 116);
        if (v33 & 0xC)
        {
            v34 = loadString_sub_40F1D0((char*)& byte_587000[137688], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2770);
            nox_swprintf(v75, v34);
        }
        else if (!(v33 & 2) || v2)
        {
            v58 = v70;
            v55 = loadString_sub_40F1D0((char*)& byte_587000[137812], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2776);
            nox_swprintf(v75, v55, v58);
        }
        else
        {
            v57 = v70;
            v54 = loadString_sub_40F1D0((char*)& byte_587000[137744], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2773);
            nox_swprintf(v75, v54, v57);
        }
        nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
        nox_wcscpy(v75, L"  ");
        v59 = v68;
        v35 = loadString_sub_40F1D0((char*)& byte_587000[137876], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2785);
        nox_swprintf(v76, v35, v59);
        nox_wcscat(v75, v76);
        nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
        nox_wcscpy(v75, L"  ");
        v60 = v69;
        v36 = loadString_sub_40F1D0((char*)& byte_587000[137936], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2792);
        nox_swprintf(v76, v36, v60);
        nox_wcscat(v75, v76);
        nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
        if (v72 > 0.0)
        {
            nox_wcscpy(v75, L"  ");
            v61 = v72;
            v37 = loadString_sub_40F1D0((char*)& byte_587000[138000], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2801);
            nox_swprintf(v76, v37, v61);
            nox_wcscat(v75, v76);
            nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
        }
        if (v71 > 0.0)
        {
            nox_wcscpy(v75, L"  ");
            v62 = v71;
            v38 = loadString_sub_40F1D0((char*)& byte_587000[138060], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2811);
            nox_swprintf(v76, v38, v62);
            nox_wcscat(v75, v76);
            nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
        }
        nox_window_call_field_94((int)v10, 16397, (int)& byte_5D4594[1063668], -1);
        goto LABEL_71;
    }
    v17 = (float*)sub_413270(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 108));
    v18 = 1.0;
    v19 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 432);
    if (v19 && *(float* (__cdecl * *)(int, int, int, int, int, float*))(v19 + 76) == sub_4E0370)
        v18 = *(float*)(v19 + 80);
    v65 = v18 * v17[16] * 1000.0 + 0.5;
    v20 = sub_419A70(v65);
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1063116] + 116) & 2)
    {
        v21 = loadString_sub_40F1D0((char*)& byte_587000[137536], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2647);
        nox_swprintf(v75, v21);
    }
    else
    {
        v66 = v20;
        v22 = loadString_sub_40F1D0((char*)& byte_587000[137592], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2649);
        nox_swprintf(v75, v22, v66);
    }
    nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
    nox_window_call_field_94((int)v10, 16397, (int)& byte_5D4594[1063664], -1);
LABEL_71:
    v15 = *(_DWORD*)& byte_5D4594[1063116];
LABEL_72:
    v39 = *(_DWORD*)(v15 + 112);
    if (v39 & 0x13001000)
    {
        if (v39 & 0x11001000)
            v40 = sub_413250(*(_DWORD*)(v15 + 108));
        else
            v40 = sub_413270(*(_DWORD*)(v15 + 108));
        if (v40)
        {
            v15 = *(_DWORD*)& byte_5D4594[1063116];
            v43 = *(_DWORD*)& byte_5D4594[1063116] + 432;
            if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 112) & 0x10000000)
                goto LABEL_91;
            v44 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 440);
            if (v44 && *(_DWORD*)(v44 + 16))
            {
                v45 = loadString_sub_40F1D0((char*)& byte_587000[138236], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2851);
                nox_swprintf(v75, v45);
                nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
                v46 = 0;
                nox_wcscpy(v75, L"  ");
                nox_swprintf(v76, *(const wchar_t**)(*(_DWORD*)(v43 + 8) + 16));
                nox_wcscat(v75, v76);
                nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
                v15 = *(_DWORD*)& byte_5D4594[1063116];
            }
            else
            {
                v46 = v73;
            }
            v47 = *(_DWORD*)(v43 + 12);
            if (v47 && *(_DWORD*)(v47 + 16))
            {
                if (v46 == 1)
                {
                    v48 = loadString_sub_40F1D0((char*)& byte_587000[138308], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2868);
                    nox_swprintf(v75, v48);
                    nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
                    v73 = 0;
                    v46 = 0;
                }
                nox_wcscpy(v75, L"  ");
                nox_swprintf(v76, *(const wchar_t**)(*(_DWORD*)(v43 + 12) + 16));
                nox_wcscat(v75, v76);
                nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
                v15 = *(_DWORD*)& byte_5D4594[1063116];
            }
            if (v46)
                goto LABEL_91;
            nox_window_call_field_94((int)v10, 16397, (int)& byte_5D4594[1063672], -1);
        }
        else
        {
            v41 = loadString_sub_40F1D0((char*)& byte_587000[138120], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2835);
            nox_swprintf(v75, v41);
            nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
            v42 = loadString_sub_40F1D0((char*)& byte_587000[138184], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2837);
            nox_swprintf(v75, v42);
            nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
        }
        v15 = *(_DWORD*)& byte_5D4594[1063116];
    }
LABEL_91:
    v49 = nox_get_thing_field_8(*(_DWORD*)(v15 + 108));
    if (v49)
        nox_window_call_field_94((int)v10, 16397, v49, -1);
    v67 = nox_get_thing_field_70(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 108));
    v50 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1062476], 9155);
    return sub_46AE60((int)v50, v67);
}
// 462878: variable 'v3' is possibly undefined
// 46288E: variable 'v4' is possibly undefined
// 4628A4: variable 'v5' is possibly undefined
// 4628CE: variable 'v6' is possibly undefined
// 4628E8: variable 'v7' is possibly undefined

//----- (00463370) --------------------------------------------------------
int __cdecl sub_463370(_DWORD* a1, _DWORD* a2, _DWORD* a3)
{
    _DWORD* v4; // eax
    _DWORD* v5; // ecx
    int result; // eax
    int v7; // [esp+0h] [ebp-4h]

    sub_46AA60(a1, &a1, &v7);
    v4 = a2;
    v5 = a3;
    *a3 = *a2 - (_DWORD)a1;
    result = v4[1] - v7;
    v5[1] = result;
    return result;
}

//----- (004633B0) --------------------------------------------------------
int __cdecl sub_4633B0(int a1, float* a2, float* a3)
{
    int result; // eax
    int v4; // esi
    float v5; // [esp+0h] [ebp-10h]
    float v6; // [esp+0h] [ebp-10h]

    result = a1;
    *a2 = *(unsigned __int16*)(a1 + 292);
    *a3 = *(unsigned __int16*)(a1 + 294);
    if (*(_DWORD*)(a1 + 112) & 0x13001000)
    {
        v4 = *(_DWORD*)(a1 + 436);
        if (v4)
        {
            if (*(float* (__cdecl * *)(int, int, int, int, int, float*))(v4 + 76) == sub_4E0380)
            {
                v5 = (double)* a2 * *(float*)(v4 + 80);
                *a2 = sub_419A70(v5);
                v6 = (double)* a3 * *(float*)(v4 + 80);
                result = sub_419A70(v6);
                *a3 = result;
            }
        }
    }
    return result;
}

//----- (00463420) --------------------------------------------------------
int __cdecl sub_463420(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1050012] = a1;
    return result;
}

//----- (00463430) --------------------------------------------------------
int __cdecl sub_463430(int a1)
{
    int v1; // et1
    int v2; // ebp
    int v3; // esi
    int v4; // edi
    int v5; // eax
    int v6; // eax
    int v7; // ebp
    int v8; // eax
    int v9; // edi
    int v10; // esi
    int v11; // esi
    int v12; // edi
    int v13; // et1
    int v14; // et1
    int2 v16; // [esp+10h] [ebp-28h]
    wchar_t v17[16]; // [esp+18h] [ebp-20h]

    v1 = *(_DWORD*)& byte_587000[136184];
    sub_46A9B0(*(_DWORD * *)(a1 + 396), 0, v1);
    sub_46AA60((_DWORD*)a1, &v16, &v16.field_4);
    sub_43F320(0);
    v2 = 0;
    v3 = v16.field_0 + 10;
    v4 = v16.field_4 + 234;
    do
    {
        if ((1 << v2) & *(_DWORD*)& byte_5D4594[1062540] && v2 != 31 && v2 != 30)
        {
            v5 = sub_424920(v2);
            v6 = sub_424A90(v5);
            sub_47D2C0(v6, v3, v4);
            v3 += 35;
        }
        ++v2;
    } while (v2 < 32);
    v7 = 0;
    do
    {
        if (byte_5D4594[1062536] & (unsigned __int8)(1 << v7))
        {
            v8 = sub_413420(1 << v7);
            sub_47D2C0(v8, v3, v4);
            v3 += 35;
        }
        ++v7;
    } while (v7 < 6);
    if (sub_40A5C0(4096) && *(_DWORD*)& byte_5D4594[1050008])
    {
        v4 += 5;
        v3 += 6;
        sub_47D2C0(
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1050008] + 96) + 4)
                + 4
                * (*(_DWORD*)& byte_5D4594[2598000]
                    % (unsigned int) * (unsigned __int8*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1050008] + 96) + 8))),
            v3 - 58,
            v4 - 53);
        nox_swprintf(v17, L"X %d", *(_DWORD*)& byte_5D4594[1050012]);
        sub_434390(*(int*)& byte_5D4594[2614244]);
        sub_43F6E0(*(int*)& byte_5D4594[1063636], (__int16*)v17, v3 + 20, v4 + 9);
        *(_DWORD*)& byte_5D4594[1049812] = v3 - 30;
        *(_DWORD*)& byte_5D4594[1049816] = v4 - 20;
        *(_DWORD*)& byte_5D4594[1049820] = v3 + 30;
        *(_DWORD*)& byte_5D4594[1049824] = v4 + 20;
    }
    if (sub_40A5C0(4096) && sub_4BFD30())
    {
        v9 = v4 + 5;
        v10 = v3 + 66;
        sub_47D2C0(*(int*)& byte_5D4594[1050004], v10 - 64, v9 - 58);
        *(_DWORD*)& byte_5D4594[1049828] = v10 - 30;
        *(_DWORD*)& byte_5D4594[1049832] = v9 - 20;
        *(_DWORD*)& byte_5D4594[1049836] = v10 + 30;
        *(_DWORD*)& byte_5D4594[1049840] = v9 + 20;
    }
    if (byte_5D4594[1049868])
    {
        v11 = v16.field_4 + 13;
        v12 = v16.field_0 + 254;
        if (v16.field_4 + 163 > 0)
        {
            sub_49F7F0();
            sub_49F6F0(v12, v11, 260, 150);
            if (byte_5D4594[1049869])
            {
                if (byte_5D4594[1049869] == 1)
                    sub_469D40(v12, v11, *(int*)& byte_5D4594[1062512]);
            }
            else
            {
                sub_4643B0(v12, v11);
            }
            sub_49F860();
        }
        if (*(_DWORD*)& byte_5D4594[1049864] == 5)
        {
            sub_4627F0(&v16);
            sub_47D2C0(*(int*)& byte_5D4594[1049912], v16.field_0, v16.field_4);
        }
        else
        {
            if (byte_5D4594[1049870])
            {
                if (byte_5D4594[1049870] == 1)
                {
                    sub_463880(&v16.field_0);
                    sub_47D2C0(*(int*)& byte_5D4594[1049912], v16.field_0, v16.field_4);
                }
            }
            else
            {
                sub_4BF7E0(&v16);
                sub_47D2C0(*(int*)& byte_5D4594[1049908], v16.field_0, v16.field_4);
            }
            sub_434390(*(int*)& byte_5D4594[2523948]);
            sub_43FAF0(0, &byte_5D4594[1062588], v16.field_0 + 13, v16.field_4 + 17, 196, 0);
        }
    }
    if (byte_5D4594[1049868] == 1)
    {
        v14 = *(_DWORD*)& byte_587000[136184];
        *(_DWORD*)& byte_587000[136184] = v14 + 64;
        if (v14 + 64 > 0)
        {
            *(_DWORD*)& byte_587000[136184] = 0;
            byte_5D4594[1049868] = 2;
        }
    }
    else if (byte_5D4594[1049868] == 3)
    {
        v13 = *(_DWORD*)& byte_587000[136184];
        *(_DWORD*)& byte_587000[136184] = v13 - 32;
        if (v13 - 32 <= -225)
        {
            *(_DWORD*)& byte_587000[136184] = -225;
            byte_5D4594[1049868] = 0;
            if (byte_5D4594[1049869])
            {
                if (byte_5D4594[1049869] == 1)
                    * (_DWORD*)& byte_5D4594[1062520] = *(_DWORD*)& byte_5D4594[1062512];
            }
            else
            {
                *(_DWORD*)& byte_5D4594[1062516] = *(_DWORD*)& byte_5D4594[1062512];
            }
            byte_5D4594[1049869] = 0;
            *(_DWORD*)& byte_5D4594[1062512] = *(_DWORD*)& byte_5D4594[1062516];
            nox_window_call_field_94(*(int*)& byte_5D4594[1062508], 16395, 0, 850);
            nox_window_call_field_94(
                *(int*)& byte_5D4594[1062508],
                16394,
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - *(_DWORD*)& byte_5D4594[1062512],
                0);
            sub_46AE60(*(int*)& byte_5D4594[1062528], 0);
            sub_46AEC0(*(int*)& byte_5D4594[1062528], *(int*)& byte_5D4594[1049976]);
            sub_46B080(*(_DWORD * *)& byte_5D4594[1062528], 9105);
            byte_5D4594[1049870] = 0;
            sub_46AE60(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049992]);
            sub_46AEC0(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049996]);
            sub_46B080(*(_DWORD * *)& byte_5D4594[1062524], 9107);
            nox_window_set_hidden(*(int*)& byte_5D4594[1062468], 0);
        }
    }
    if (sub_467C80() && sub_4372B0())
        sub_467C10();
    return 1;
}

//----- (00463880) --------------------------------------------------------
int* __cdecl sub_463880(int* a1)
{
    int v1; // esi
    int v2; // eax
    int v3; // eax
    int v4; // ebp
    int* result; // eax
    int v6; // edi
    int v7; // ebx
    int v8; // edi
    int v9; // ebx
    int v10; // edi
    int v11; // ebx
    wchar_t* v12; // eax
    int v13; // ebx
    wchar_t* v14; // eax
    int v15; // ebx
    wchar_t* v16; // eax
    wchar_t* v17; // eax
    int v18; // eax
    int v19; // ebx
    wchar_t* v20; // eax
    wchar_t* v21; // eax
    int v22; // eax
    wchar_t* v23; // eax
    wchar_t* v24; // eax
    int v25; // ebx
    wchar_t* v26; // eax
    int v27; // eax
    wchar_t* v28; // eax
    int v29; // eax
    int v30; // ebx
    wchar_t* v31; // eax
    wchar_t* v32; // eax
    unsigned __int8* v33; // ecx
    int v34; // esi
    unsigned __int16* v35; // eax
    int v36; // ebx
    wchar_t* v37; // eax
    wchar_t* v38; // eax
    int v39; // [esp-8h] [ebp-248h]
    int v40; // [esp-4h] [ebp-244h]
    int v41; // [esp+0h] [ebp-240h]
    int v42; // [esp+0h] [ebp-240h]
    int v43; // [esp+0h] [ebp-240h]
    int v44; // [esp+0h] [ebp-240h]
    float v45; // [esp+0h] [ebp-240h]
    int v46; // [esp+0h] [ebp-240h]
    float v47; // [esp+0h] [ebp-240h]
    int v48; // [esp+0h] [ebp-240h]
    float v49; // [esp+0h] [ebp-240h]
    int v50; // [esp+0h] [ebp-240h]
    float v51; // [esp+4h] [ebp-23Ch]
    int v52; // [esp+4h] [ebp-23Ch]
    int v53; // [esp+4h] [ebp-23Ch]
    float v54; // [esp+4h] [ebp-23Ch]
    float v55; // [esp+4h] [ebp-23Ch]
    int v56; // [esp+4h] [ebp-23Ch]
    float v57; // [esp+4h] [ebp-23Ch]
    float v58; // [esp+4h] [ebp-23Ch]
    int v59; // [esp+4h] [ebp-23Ch]
    float v60; // [esp+4h] [ebp-23Ch]
    int v61; // [esp+4h] [ebp-23Ch]
    float v62; // [esp+4h] [ebp-23Ch]
    float v63; // [esp+4h] [ebp-23Ch]
    int v64; // [esp+4h] [ebp-23Ch]
    float v65; // [esp+4h] [ebp-23Ch]
    int v66; // [esp+4h] [ebp-23Ch]
    int v67; // [esp+18h] [ebp-228h]
    int v68; // [esp+1Ch] [ebp-224h]
    float v69; // [esp+20h] [ebp-220h]
    float* v70; // [esp+24h] [ebp-21Ch]
    float* v71; // [esp+28h] [ebp-218h]
    int v72; // [esp+2Ch] [ebp-214h]
    int v73; // [esp+30h] [ebp-210h]
    int v74; // [esp+34h] [ebp-20Ch]
    int v75; // [esp+38h] [ebp-208h]
    int v76; // [esp+3Ch] [ebp-204h]
    wchar_t v77[256]; // [esp+40h] [ebp-200h]

    v1 = sub_43F320(0);
    v2 = sub_43F320(*(int*)& byte_5D4594[1063636]);
    v68 = v1 - v2;
    v51 = (double)(v1 - v2) * 0.5 + 0.5;
    v3 = sub_419A70(v51);
    v4 = *(_DWORD*)& byte_5D4594[2618908];
    v73 = v3;
    result = a1;
    v72 = *(_DWORD*)& byte_5D4594[2523948];
    v6 = *a1;
    v7 = a1[1];
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        sub_57B350();
        v70 = sub_57B360(*(unsigned __int8*)(v4 + 2251));
        v71 = sub_57B360(0);
        v8 = v6 + 11;
        v9 = v7 + 15;
        sub_434390(v72);
        sub_434460(*(int*)& byte_5D4594[2650656]);
        sub_49CE30(v8, v9, 200, 200);
        v10 = v8 + 2;
        v11 = v9 + 2 * v1 + 3;
        v52 = *(char*)(v4 + 3684);
        v12 = loadString_sub_40F1D0((char*)& byte_587000[138392], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1878);
        nox_swprintf(v77, v12, v52);
        sub_43FAF0(0, v77, v10, v11, 200, 0);
        v13 = v11 + v1 + 1;
        if (sub_40A5C0(2048))
        {
            v53 = (__int64)sub_419D70(&byte_587000[138404], *(char*)(v4 + 3684) + 1);
            v41 = *(_DWORD*)& byte_5D4594[1062544];
            v14 = loadString_sub_40F1D0((char*)& byte_587000[138448], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1886);
            nox_swprintf(v77, v14, v41, v53);
            sub_43FAF0(0, v77, v10, v13, 200, 0);
        }
        v15 = 2 * v1 + 2 + v13;
        v16 = loadString_sub_40F1D0((char*)& byte_587000[138496], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1896);
        sub_43FAF0(0, v16, v10, v15, 200, 0);
        sub_434460(*(int*)& byte_5D4594[2598268]);
        sub_49CE30(v10 + 60, v15, 90, v1);
        v54 = (double)(int)(90 * *(_DWORD*)(v4 + 2247)) / *v70;
        v67 = sub_419A70(v54);
        sub_434460(*(int*)& byte_5D4594[2589776]);
        sub_49CE30(v10 + 60, v15, v67, v1);
        v68 = 90 * sub_470CC0();
        v55 = (double)v68 / *v70;
        v67 = sub_419A70(v55);
        sub_434460(*(int*)& byte_5D4594[2650644]);
        sub_49CE30(v10 + 60, v15, v67, v1);
        v56 = sub_419A70(*v70);
        v42 = *(_DWORD*)(v4 + 2247);
        v17 = loadString_sub_40F1D0((char*)& byte_587000[138544], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1914);
        nox_swprintf(v77, v17, v42, v56);
        sub_43F840(*(int*)& byte_5D4594[1063636], v77, &v67, 0, 0);
        LODWORD(v69) = v15 + v73;
        sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 - v67 + 193, v15 + v73, 200, 0);
        v18 = sub_470CC0();
        nox_swprintf(v77, L"%d", v18);
        sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 + 45, SLODWORD(v69), 200, 0);
        v19 = v15 + v1 + 1;
        if (*(_BYTE*)(v4 + 2251))
        {
            sub_434460(*(int*)& byte_5D4594[2650648]);
            sub_49CE30(v10 + 60, v19, 90, v1);
            v68 = 90 * *(_DWORD*)(v4 + 2243);
            v57 = (double)v68 / v70[1];
            v67 = sub_419A70(v57);
            v20 = loadString_sub_40F1D0((char*)& byte_587000[138604], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1941);
            sub_43FAF0(0, v20, v10, v19, 200, 0);
            sub_434460(*(int*)& byte_5D4594[2650684]);
            sub_49CE30(v10 + 60, v19, v67, v1);
            v68 = 90 * sub_470DD0();
            v58 = (double)v68 / v70[1];
            v67 = sub_419A70(v58);
            sub_434460(*(int*)& byte_5D4594[2649820]);
            sub_49CE30(v10 + 60, v19, v67, v1);
            v59 = sub_419A70(v70[1]);
            v43 = *(_DWORD*)(v4 + 2243);
            v21 = loadString_sub_40F1D0((char*)& byte_587000[138652], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1952);
            nox_swprintf(v77, v21, v43, v59);
            sub_43F840(*(int*)& byte_5D4594[1063636], v77, &v67, 0, 0);
            sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 - v67 + 193, v19 + v73, 200, 0);
            v22 = sub_470DD0();
            nox_swprintf(v77, L"%d", v22);
            sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 + 45, v19 + v73, 200, 0);
            v19 += v1 + 1;
        }
        sub_434460(*(int*)& byte_5D4594[2650660]);
        sub_49CE30(v10 + 60, v19, 90, v1);
        v68 = 90 * *(_DWORD*)(v4 + 2239);
        v60 = (double)v68 / v70[3];
        v67 = sub_419A70(v60);
        v23 = loadString_sub_40F1D0((char*)& byte_587000[138712], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1975);
        sub_43FAF0(0, v23, v10, v19, 200, 0);
        sub_434460(*(int*)& byte_5D4594[2597996]);
        sub_49CE30(v10 + 60, v19, v67, v1);
        v61 = sub_419A70(v70[3]);
        v44 = *(_DWORD*)(v4 + 2239);
        v24 = loadString_sub_40F1D0((char*)& byte_587000[138764], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1982);
        nox_swprintf(v77, v24, v44, v61);
        sub_43F840(*(int*)& byte_5D4594[1063636], v77, &v67, 0, 0);
        sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 - v67 + 193, v19 + v73, 200, 0);
        nox_swprintf(v77, L"%d", *(_DWORD*)(v4 + 2239));
        sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 + 45, v19 + v73, 200, 0);
        v25 = v19 + v1 + 1;
        sub_434460(*(int*)& byte_5D4594[2614256]);
        sub_49CE30(v10 + 60, v25, 90, v1);
        v68 = 90 * *(_DWORD*)(v4 + 2235);
        v62 = (double)v68 / v70[2] + 0.5;
        v67 = sub_419A70(v62);
        v26 = loadString_sub_40F1D0((char*)& byte_587000[138824], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2006);
        sub_43FAF0(0, v26, v10, v25, 200, 0);
        sub_434460(*(int*)& byte_5D4594[2589772]);
        sub_49CE30(v10 + 60, v25, v67, v1);
        sub_434390(*(int*)& byte_5D4594[2523948]);
        v69 = *(float*)& byte_5D4594[1063100] / (v71[2] * 0.000001);
        if (byte_5D4594[1062541] & 2)
            v69 = ((double)v67 + v69) * 1.25 - (double)v67;
        if (byte_5D4594[1062540] & 0x10)
            v69 = ((double)v67 + v69) * 0.5 - (double)v67;
        if (v69 >= 0.0)
        {
            if (v69 > 0.0)
            {
                *(float*)& v68 = COERCE_FLOAT(sub_419A70(v69));
                if (v67 + v68 > 90)
                    v68 = 90 - v67;
                sub_434460(*(int*)& byte_5D4594[2589772]);
                sub_49CE30(v67 + v10 + 60, v25, v68, v1);
                sub_434390(*(int*)& byte_5D4594[2650684]);
            }
        }
        else
        {
            sub_434460(*(int*)& byte_5D4594[2650648]);
            v45 = -v69;
            v46 = sub_419A70(v45);
            v27 = sub_419A70(v69);
            sub_49CE30(v67 + v27 + v10 + 60, v25, v46, v1);
        }
        *(float*)& v68 = v69 * 100.0 * 0.011111111;
        v63 = v70[2] * 100.0 / v71[2];
        v64 = sub_419A70(v63);
        v47 = (double) * (int*)(v4 + 2235) * 100.0 / v71[2] + *(float*)& v68 + 0.5;
        v48 = sub_419A70(v47);
        v28 = loadString_sub_40F1D0((char*)& byte_587000[138872], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2045);
        nox_swprintf(v77, v28, v48, v64);
        sub_43F840(*(int*)& byte_5D4594[1063636], v77, &v76, 0, 0);
        LODWORD(v69) = v25 + v73;
        sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 - v76 + 193, v25 + v73, 200, 0);
        sub_434390(*(int*)& byte_5D4594[2523948]);
        v65 = (double) * (int*)(v4 + 2235) * 100.0 / v71[2] + *(float*)& v68 + 0.5;
        v29 = sub_419A70(v65);
        nox_swprintf(v77, L"%d", v29);
        sub_43FAF0(*(int*)& byte_5D4594[1063636], v77, v10 + 45, SLODWORD(v69), 200, 0);
        sub_434390(*(int*)& byte_5D4594[2523948]);
        v30 = 2 * v1 + 2 + v25;
        if (*(_DWORD*)& byte_587000[26048] == 6 || *(_DWORD*)& byte_587000[26048] == 8)
            v10 += 39;
        sub_434390(v72);
        v31 = loadString_sub_40F1D0((char*)& byte_587000[138932], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2072);
        nox_wcscpy(v77, v31);
        sub_43F840(0, v77, &v75, 0, 0);
        sub_43FAF0(0, v77, v10, v30, 0, 0);
        v49 = *(float*)& byte_5D4594[1062548] * 1000.0 + 0.5;
        v50 = sub_419A70(v49);
        v32 = loadString_sub_40F1D0((char*)& byte_587000[138984], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2076);
        nox_swprintf(v77, v32, v50, 1000);
        sub_43FAF0(0, v77, v75 + v10 + 5, v30, 0, 0);
        v33 = &byte_5D4594[1050160];
        v74 = v30 + v1 + 1;
        v34 = 0;
        v71 = (float*)& byte_5D4594[1050160];
        do
        {
            v68 = 4;
            do
            {
                if (*v33)
                    v34 += *v33 * *(unsigned __int8*)(*((_DWORD*)v33 - 35) + 298);
                v33 += 3108;
                --v68;
            } while (*(float*)& v68 != 0.0);
            v33 = (unsigned __int8*)(v71 + 37);
            v71 += 37;
        } while ((int)v71 < (int)& byte_5D4594[1053120]);
        sub_434390(v72);
        v35 = loadString_sub_40F1D0((char*)& byte_587000[139036], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2098);
        sub_43F840(0, v35, &v67, 0, 0);
        v36 = v74;
        v40 = v74;
        v39 = v10 + v75 - v67;
        v37 = loadString_sub_40F1D0((char*)& byte_587000[139084], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2099);
        sub_43FAF0(0, v37, v39, v40, 0, 0);
        if (v34 > * (unsigned __int16*)(v4 + 3652))
            v72 = *(_DWORD*)& byte_5D4594[2650644];
        sub_434390(v72);
        v66 = *(unsigned __int16*)(v4 + 3652);
        v38 = loadString_sub_40F1D0((char*)& byte_587000[139132], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2107);
        nox_swprintf(v77, v38, v34, v66);
        result = (int*)sub_43FAF0(0, v77, v75 + v10 + 5, v36, 0, 0);
    }
    return result;
}

//----- (004643B0) --------------------------------------------------------
int __cdecl sub_4643B0(int a1, int a2)
{
    int v2; // ebx
    int v3; // esi
    unsigned __int8* v4; // ebp
    int v5; // edi
    int v6; // ebx
    int v7; // esi
    double v8; // st7
    double v9; // st6
    int v10; // eax
    int v11; // edx
    int v12; // eax
    __int16 v13; // ax
    __int16 v14; // ax
    __int16 v15; // si
    bool v16; // zf
    int result; // eax
    int v18; // [esp-8h] [ebp-5Ch]
    int v19; // [esp-4h] [ebp-58h]
    int v20; // [esp+10h] [ebp-44h]
    int v21; // [esp+14h] [ebp-40h]
    int v22; // [esp+18h] [ebp-3Ch]
    unsigned __int8* v23; // [esp+1Ch] [ebp-38h]
    int v24; // [esp+20h] [ebp-34h]
    int v25; // [esp+24h] [ebp-30h]
    int v26; // [esp+28h] [ebp-2Ch]
    int v27; // [esp+2Ch] [ebp-28h]
    WCHAR WideCharStr[16]; // [esp+34h] [ebp-20h]
    unsigned __int8* v29; // [esp+58h] [ebp+4h]

    v2 = a2;
    sub_47D2C0(*(int*)& byte_5D4594[1049928], a1, a2);
    _itow(*(int*)& byte_5D4594[1062552], WideCharStr, 10);
    sub_434390(*(int*)& byte_5D4594[2589772]);
    sub_43F840(*(int*)& byte_5D4594[1063636], WideCharStr, &v24, 0, 0);
    sub_43F6E0(*(int*)& byte_5D4594[1063636], (__int16*)WideCharStr, a1 - v24 + 43, a2 + 36);
    if (*(_DWORD*)& byte_5D4594[1049864] == 5)
        sub_47D2C0(*(int*)& byte_5D4594[1049932], a1, a2 + 50);
    if (sub_473670())
        sub_47D2C0(*(int*)& byte_5D4594[1049936], a1, a2 + 100);
    v3 = a1 + 60;
    v4 = &byte_5D4594[1050160];
    v27 = a1 + 60;
    v5 = a2 - *(_DWORD*)& byte_5D4594[1062512];
    v20 = 0;
    v23 = &byte_5D4594[1050160];
    do
    {
        if (v5 > v2 - 50)
        {
            v6 = v3;
            sub_47D2C0(*(_DWORD*)& byte_5D4594[4 * (v20 % 3) + 1049916], v3, v5);
            v29 = v4;
            v22 = 4;
            while (1)
            {
                if (*v4)
                {
                    v7 = *((_DWORD*)v4 - 35);
                    if (v7)
                        break;
                }
            LABEL_43:
                v6 += 50;
                v4 += 3108;
                v16 = v22 == 1;
                v29 = v4;
                --v22;
                if (v16)
                {
                    v2 = a2;
                    v4 = v23;
                    v3 = v27;
                    goto LABEL_45;
                }
            }
            v21 = 0;
            sub_434560(1);
            sub_434580(0x40u);
            v8 = (double) * (unsigned __int16*)(v7 + 292);
            v25 = *(unsigned __int16*)(v7 + 294);
            v9 = (double)v25;
            if (v8 >= v9 * *(double*)& byte_581450[9608])
            {
                if (v8 >= v9 * *(double*)& byte_581450[9544])
                    goto LABEL_16;
                v10 = *(_DWORD*)& byte_5D4594[2589772];
            }
            else
            {
                v10 = *(_DWORD*)& byte_5D4594[2650644];
            }
            if (v10 != 0x80000000)
            {
                sub_434460(v10);
                sub_49CE30(v6, v5, 50, 50);
            }
        LABEL_16:
            sub_434580(0x80u);
            if (*((_DWORD*)v4 - 2))
            {
                v11 = *(_DWORD*)& byte_5D4594[1049964];
                v19 = v5;
                v18 = v6;
            }
            else
            {
                if (*((_DWORD*)v4 - 1))
                {
                    sub_47D2C0(*(int*)& byte_5D4594[1049968], v6, v5);
                LABEL_27:
                    sub_434560(0);
                    *(_DWORD*)(v7 + 16) = v5 + 25;
                    *(_DWORD*)(v7 + 12) = v6 + 25;
                    (*(void(__cdecl * *)(unsigned __int8*, int))(v7 + 300))(&byte_5D4594[1049732], v7);
                    if (*(_DWORD*)& byte_5D4594[1049864] == 6)
                    {
                        if (*(_DWORD*)(v7 + 112) & 0x13001000)
                        {
                            if ((*(_DWORD*)(v7 + 112) & 0x1000) == 4096)
                            {
                                v13 = *(_WORD*)(v7 + 450);
                                if (*(_WORD*)(v7 + 448) < v13)
                                {
                                    if (v13)
                                        v21 = 1;
                                }
                            }
                        }
                        v14 = *(_WORD*)(v7 + 294);
                        if ((*(_WORD*)(v7 + 292) == v14 || !v14) && !v21)
                            sub_49CF10(v6, v5, 50, 50);
                    }
                    if (*v29 > 1u)
                    {
                        nox_swprintf(WideCharStr, L"%d", *v29);
                        sub_434390(*(int*)& byte_5D4594[2523948]);
                        sub_43F6E0(*(int*)& byte_5D4594[1063636], (__int16*)WideCharStr, v6 + 6, v5 + 6);
                    }
                    if (*(_DWORD*)(v7 + 112) & 0x13001000)
                    {
                        v15 = *(_WORD*)(v7 + 448);
                        if (v15 >= 0)
                        {
                            nox_swprintf(WideCharStr, L"%d", v15);
                            sub_434390(*(int*)& byte_5D4594[2650684]);
                            sub_43F840(*(int*)& byte_5D4594[1063636], WideCharStr, &v26, 0, 0);
                            sub_43F6E0(*(int*)& byte_5D4594[1063636], (__int16*)WideCharStr, v6 - v26 + 44, v5 + 6);
                        }
                    }
                    v4 = v29;
                    goto LABEL_43;
                }
                if (*((_DWORD*)v4 - 34) != *(_DWORD*)& byte_5D4594[1062488])
                    goto LABEL_27;
                if (!*(_DWORD*)& byte_5D4594[1062480])
                    goto LABEL_27;
                v12 = **(_DWORD * *)& byte_5D4594[1062480];
                if (!**(_DWORD * *)& byte_5D4594[1062480]
                    || !(*(_DWORD*)(v12 + 112) & 0x1000000)
                    || !(*(_BYTE*)(v12 + 116) & 0xC))
                {
                    goto LABEL_27;
                }
                v11 = *(_DWORD*)& byte_5D4594[1049968];
                v19 = v5;
                v18 = v6;
            }
            sub_47D2C0(v11, v18, v19);
            goto LABEL_27;
        }
    LABEL_45:
        v5 += 50;
        result = v2 + 150;
        if (v5 > v2 + 150)
            break;
        v4 += 148;
        ++v20;
        v23 = v4;
    } while ((int)v4 < (int)& byte_5D4594[1053120]);
    return result;
}

//----- (00464770) --------------------------------------------------------
int __cdecl sub_464770(int a1, int a2, unsigned int a3)
{
    int v3; // eax
    int v4; // esi
    int v5; // eax
    int v6; // eax
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1049864] == 6)
        return 1;
    switch (a2)
    {
    case 5:
    case 8:
        return 1;
    case 6:
        if (!*(_DWORD*)& byte_5D4594[1049848])
            goto LABEL_25;
        if (!sub_46AAB0(*(_DWORD * *)& byte_5D4594[1062456], (unsigned __int16)a3, a3 >> 16))
            goto LABEL_22;
        if (*(_DWORD*)& byte_5D4594[1049856])
        {
            if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x1001000)
            {
                if (*(_DWORD*)& byte_5D4594[1062480])
                {
                    sub_4672C0();
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[1062492] = *(_DWORD*)& byte_5D4594[1049848];
                    sub_464B70(*(int*)& byte_5D4594[1049848]);
                }
            }
        }
        else if (!(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x1001000)
            || *(_DWORD*)& byte_5D4594[148
            * (*(_DWORD*)& byte_5D4594[1049800]
                + 14 * *(_DWORD*)& byte_5D4594[1049796]
                + 7 * *(_DWORD*)& byte_5D4594[1049796])
            + 1050152])
        {
            sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
        }
        else
        {
            if (sub_415880(*(char**)(*(_DWORD*)& byte_5D4594[1049848] + 108)) == 2)
            {
                v3 = sub_415840((char*)4);
                v4 = sub_461600(v3);
                v5 = sub_415840((char*)8);
                v6 = sub_461600(v5);
                if (!v4 && !v6)
                {
                    sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
                    sub_4776A0();
                    if (!*(_DWORD*)& byte_5D4594[1049856])
                        sub_45A4B0(*(_QWORD * *)& byte_5D4594[1049848]);
                    *(_DWORD*)& byte_5D4594[1049848] = 0;
                    *(_DWORD*)& byte_5D4594[1049856] = 0;
                    return 1;
                }
            }
            if (*(_DWORD*)& byte_5D4594[1062480])
                * (_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 136) = 0;
            sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
            sub_461550((int)& byte_5D4594[148
                * (*(_DWORD*)& byte_5D4594[1049800]
                    + 14 * *(_DWORD*)& byte_5D4594[1049796]
                    + 7 * *(_DWORD*)& byte_5D4594[1049796])
                + 1050020]);
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 136) = 1;
        }
    LABEL_22:
        sub_4776A0();
        if (!*(_DWORD*)& byte_5D4594[1049856])
            sub_45A4B0(*(_QWORD * *)& byte_5D4594[1049848]);
        *(_DWORD*)& byte_5D4594[1049848] = 0;
        *(_DWORD*)& byte_5D4594[1049856] = 0;
    LABEL_25:
        sub_46ADE0(*(int*)& byte_5D4594[1062456]);
        result = 1;
        break;
    case 7:
        if (*(_DWORD*)& byte_5D4594[1062480])
            sub_4672C0();
        return 1;
    default:
        return 0;
    }
    return result;
}

//----- (004649B0) --------------------------------------------------------
BOOL __cdecl sub_4649B0(int a1, int a2, int a3)
{
    BOOL result; // eax
    unsigned __int8* v4; // ebp
    unsigned __int8 v5; // al
    _DWORD* v6; // eax
    wchar_t* v7; // eax
    unsigned __int8* v8; // ecx
    int v9; // eax
    int v10; // eax

    result = sub_464B40(a2, a3);
    if (result)
    {
        v4 = &byte_5D4594[148 * (a3 + 14 * a2 + 7 * a2) + 1050020];
        v5 = byte_5D4594[148 * (a3 + 14 * a2 + 7 * a2) + 1050160];
        if (v5)
        {
            if (*(_DWORD*)(a1 + 112) & 0x4000000)
                return 0;
            if (*(_DWORD*)(*(_DWORD*)v4 + 108) != *(_DWORD*)(a1 + 108))
                return 0;
        }
        if (v5 >= 0x20u)
            return 0;
        if (!v5)
        {
            v6 = sub_45A240(*(_DWORD*)(a1 + 108));
            *(_DWORD*)v4 = v6;
            if (!v6)
            {
                v7 = loadString_sub_40F1D0((char*)& byte_587000[139200], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 898);
                sub_445490(v7);
                return 0;
            }
            v6[30] |= 0x40000000u;
            qmemcpy((void*)(*(_DWORD*)v4 + 432), (const void*)(a1 + 432), 0x18u);
            *(_WORD*)(*(_DWORD*)v4 + 292) = *(_WORD*)(a1 + 292);
            *(_WORD*)(*(_DWORD*)v4 + 294) = *(_WORD*)(a1 + 294);
        }
        v8 = &byte_5D4594[1049872];
        *(_DWORD*)& v4[4 * v4[140]++ + 4] = *(_DWORD*)(a1 + 128);
        *((_DWORD*)v4 + 33) = 0;
        while (1)
        {
            v9 = *(_DWORD*)v8;
            if (*(_DWORD*)v8)
                break;
        LABEL_17:
            v8 += 4;
            if ((int)v8 >= (int)& byte_5D4594[1049908])
                return 1;
        }
        while (*(_DWORD*)(v9 + 128) != *(_DWORD*)(a1 + 128))
        {
            v9 = *(_DWORD*)(v9 + 368);
            if (!v9)
                goto LABEL_17;
        }
        v10 = *((_DWORD*)v4 + 34);
        *((_DWORD*)v4 + 33) = 1;
        if (v10)
        {
            sub_461550(0);
            *((_DWORD*)v4 + 34) = 0;
        }
        result = 1;
    }
    return result;
}

//----- (00464B40) --------------------------------------------------------
BOOL __cdecl sub_464B40(int a1, int a2)
{
    return a1 >= 0 && a1 < 4 && a2 >= 0 && a2 < 21;
}

//----- (00464B70) --------------------------------------------------------
int __cdecl sub_464B70(int a1)
{
    int v1; // ecx
    char v3[3]; // [esp+0h] [ebp-4h]
    char v4; // [esp+3h] [ebp-1h]

    v4 = HIBYTE(v1);
    v3[0] = 118;
    *(_WORD*)& v3[1] = sub_578B00(a1);
    return sub_40EBC0(31, 0, v3, 3);
}

//----- (00464BA0) --------------------------------------------------------
int sub_464BA0()
{
    return 0;
}

//----- (00464BB0) --------------------------------------------------------
BOOL __cdecl sub_464BB0(int a1, int a2)
{
    return a2 != 8 && a2 != 12 && a2 != 16;
}

//----- (00464BD0) --------------------------------------------------------
int __cdecl sub_464BD0(int a1, int a2, unsigned int a3)
{
    int v4; // eax
    int v5; // eax
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // esi
    int v10; // edi
    int v11; // eax
    int v12; // ecx
    int v13; // eax
    int v14; // eax
    int v15; // eax
    int v16; // esi
    int v17; // edi
    int v18; // eax
    int v19; // ecx
    int v20; // eax
    int v21; // eax
    int v26; // eax
    _DWORD* v28; // esi
    wchar_t* v29; // eax
    int v30; // eax
    int v31; // eax
    int v32; // esi
    int v33; // edi
    int v34; // eax
    int v35; // eax
    int v36; // eax
    int v37; // eax
    int v38; // eax
    int v39; // eax
    _DWORD* v40; // ecx
    int v41; // edx
    int v42; // edx
    int v43; // eax
    int v44; // edx
    int v45; // esi
    int v46; // eax
    int v47; // eax
    int v48; // esi
    const void* v49; // edi
    wchar_t* v50; // eax
    int2 v51; // [esp-24h] [ebp-7Ch]
    int v52; // [esp-1Ch] [ebp-74h]
    int v53; // [esp-18h] [ebp-70h]
    int v54; // [esp-8h] [ebp-60h]
    int v55; // [esp-4h] [ebp-5Ch]
    int2 v56; // [esp+8h] [ebp-50h]
    int2 v57; // [esp+10h] [ebp-48h]
    int2 v58; // [esp+18h] [ebp-40h]
    int2 v59; // [esp+20h] [ebp-38h]

    v59.field_4 = a3 >> 16;
    v59.field_0 = (unsigned __int16)a3;
    sub_463370(*(_DWORD * *)& byte_5D4594[1062456], &v59, &v56);
    if (sub_45D9B0() || byte_5D4594[1049868] != 2)
        return 1;
    switch (a2)
    {
    case 5:
        if (sub_4372B0())
            return 1;
        if (*(_DWORD*)& byte_5D4594[1049864] == 5)
        {
            v8 = sub_4281F0(&v56, (int4*)& byte_587000[136352]);
            if (v8)
            {
                v9 = (v56.field_0 - 314) / 50;
                v10 = (*(_DWORD*)& byte_5D4594[1062512] + v56.field_4 - 13) / 50;
                if (!sub_464B40(v9, v10))
                    return 1;
                v11 = 148 * (v10 + 14 * v9 + 7 * v9);
                if (byte_5D4594[v11 + 1050160])
                {
                    v12 = *(_DWORD*)& byte_5D4594[v11 + 1050020];
                    v13 = *(_DWORD*)& byte_5D4594[v11 + 1050024];
                    *(_DWORD*)& byte_5D4594[1063116] = v12;
                    *(_DWORD*)(v12 + 128) = v13;
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[1063116] = 0;
                }
                return 1;
            }
            if (sub_478030())
            {
                if (sub_479870())
                {
                    LOBYTE(v14) = sub_479880(&v56);
                    if (v14)
                    {
                        *(_DWORD*)& byte_5D4594[1063116] = sub_4798A0(&v56);
                        return 1;
                    }
                }
            }
        }
        else if (*(_DWORD*)& byte_5D4594[1049864] == 6)
        {
            v15 = sub_4281F0(&v56, (int4*)& byte_587000[136352]);
            if (v15)
            {
                v16 = (v56.field_0 - 314) / 50;
                v17 = (*(_DWORD*)& byte_5D4594[1062512] + v56.field_4 - 13) / 50;
                if (sub_464B40(v16, v17))
                {
                    v18 = 148 * (v17 + 14 * v16 + 7 * v16);
                    if (byte_5D4594[v18 + 1050160])
                    {
                        v19 = *(_DWORD*)& byte_5D4594[v18 + 1050020];
                        v20 = *(_DWORD*)& byte_5D4594[v18 + 1050024];
                        *(_DWORD*)(v19 + 128) = v20;
                        if (v19)
                        {
                            sub_4657B0(v20);
                            return 1;
                        }
                    }
                }
            }
        }
        else if (byte_5D4594[1049870] != 1 || (v21 = sub_4281F0(&v56, (int4*)& byte_587000[136336]), v21 != 1))
        {
            if (byte_5D4594[1049869]
                || sub_4281F0(&v56, (int4*)& byte_587000[136384])
                || sub_4281F0(&v56, (int4*)& byte_587000[136400]))
            {
                if (sub_4281F0(&v56, (int4*)& byte_587000[136384]) == 1)
                    return 0;
                if (sub_4281F0(&v56, (int4*)& byte_587000[136400]) == 1)
                    return 0;
            }
            else
            {
                sub_46ADC0(*(int*)& byte_5D4594[1062456]);
                if (sub_479590() == 3)
                    sub_4657E0(&v56);
                else
                    sub_4658A0(*(int*)& byte_5D4594[1062456], &v56);
                if (*(_DWORD*)& byte_5D4594[1049848])
                {
                    sub_477690(*(int*)& byte_5D4594[1049848]);
                    sub_4160D0(0);
                    *(int2*)& byte_5D4594[1062572] = v56;
                    sub_452D80(791, 100);
                    return 1;
                }
            }
        }
        return 1;
    case 6:
        goto LABEL_53;
    case 7:
        if (sub_4372B0() || *(_DWORD*)& byte_5D4594[1049864] == 6)
            return 1;
        if (!byte_5D4594[1049869])
        {
            v26 = sub_4281F0(&v56, (int4*)& byte_587000[136368]);
            if (v26)
            {
                if ((v56.field_4 - 13) / 50 == 1)
                {
                    if (*(_DWORD*)& byte_5D4594[1049864] != 5)
                    {
                        sub_465CA0();
                        return 1;
                    }
                LABEL_5:
                    sub_462740();
                    return 1;
                }
            }
        }
    LABEL_53:
        if (sub_4372B0() || *(_DWORD*)& byte_5D4594[1049864] == 6)
            return 1;
        if (*(_DWORD*)& byte_5D4594[1049864] == 5)
        {
            if (sub_477630() == 7)
                goto LABEL_5;
        }
        else
        {
            sub_46ADE0(*(int*)& byte_5D4594[1062456]);
        }
        if (*(_DWORD*)& byte_5D4594[1049864] == 4)
        {
            v58 = v59;
            sub_473970(&v58, &v58);
            v28 = sub_49ABF0(&v58, 20);
            if (v28)
            {
                v57.field_0 = nox_win_width / 2;
                v57.field_4 = nox_win_height / 2;
                sub_473970(&v57, &v57);
                if ((v57.field_0 - v28[3]) * (v57.field_0 - v28[3]) + (v57.field_4 - v28[4]) * (v57.field_4 - v28[4]) <= 5625)
                {
                LABEL_64:
                    *(_DWORD*)& byte_5D4594[1049864] = 0;
                    return 1;
                }
                v29 = loadString_sub_40F1D0((char*)& byte_587000[139256], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3858);
            }
            else
            {
                v29 = loadString_sub_40F1D0((char*)& byte_587000[139308], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3869);
            }
            sub_445490(v29);
            goto LABEL_64;
        }
        if (!*(_DWORD*)& byte_5D4594[1049848])
            return 1;
        if (!sub_46AAB0(*(_DWORD * *)& byte_5D4594[1062456], v59.field_0, v59.field_4)
            || (v30 = sub_4281F0(&v56, (int4*)& byte_587000[136384]), v30)
            || (v31 = sub_4281F0(&v56, (int4*)& byte_587000[136400]), v31))
        {
            v58 = v59;
            sub_473970(&v58, &v57);
            if (*(_DWORD*)& byte_5D4594[1049856] == 1)
            {
                if (!sub_4C12C0())
                    sub_465BE0(&v57);
            }
            else
            {
                v47 = *(_DWORD*)& byte_5D4594[1049800]
                    + 14 * *(_DWORD*)& byte_5D4594[1049796]
                    + 7 * *(_DWORD*)& byte_5D4594[1049796];
                v48 = byte_5D4594[148 * v47 + 1050160];
                if (byte_5D4594[148 * v47 + 1050160])
                {
                    v49 = 0;
                    sub_46ADE0(*(int*)& byte_5D4594[1062456]);
                    if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x13001000)
                        v49 = (const void*)(*(_DWORD*)& byte_5D4594[1049848] + 432);
                    sub_4C05F0(0, 0);
                    v53 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 108);
                    v52 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128);
                    v51 = v58;
                    v50 = loadString_sub_40F1D0((char*)& byte_587000[139356], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4148);
                    sub_4C0430((int)v50, v51.field_0, v51.field_4, v52, v53, v49, v48 + 1, 0, sub_465CD0, 0);
                }
                else if (!sub_4C12C0())
                {
                    sub_465BE0(&v57);
                }
            }
            if (*(_DWORD*)& byte_5D4594[1049856])
                goto LABEL_121;
        LABEL_119:
            v55 = *(_DWORD*)& byte_5D4594[1049800];
            v54 = *(_DWORD*)& byte_5D4594[1049796];
            goto LABEL_120;
        }
        v32 = *(_DWORD*)& byte_5D4594[1062572] - v56.field_0;
        v33 = *(_DWORD*)& byte_5D4594[1062576] - v56.field_4;
        if (!sub_4160F0(0, *(_DWORD*)& byte_5D4594[2649704] / 3u) && v32 * v32 + v33 * v33 < 100)
        {
            v34 = sub_4281F0(&v56, (int4*)& byte_587000[136352]);
            if (!v34)
                goto LABEL_121;
            if (!sub_4C12C0())
            {
                if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x3001000)
                {
                    v35 = 148
                        * (*(_DWORD*)& byte_5D4594[1049800]
                            + 14 * *(_DWORD*)& byte_5D4594[1049796]
                            + 7 * *(_DWORD*)& byte_5D4594[1049796]);
                    if (*(_DWORD*)& byte_5D4594[v35 + 1050156])
                    {
                        sub_461550(0);
                        *(_DWORD*)& byte_5D4594[148
                            * (*(_DWORD*)& byte_5D4594[1049800]
                                + 14 * *(_DWORD*)& byte_5D4594[1049796]
                                + 7 * *(_DWORD*)& byte_5D4594[1049796])
                            + 1050156] = 0;
                    }
                    else if (*(_DWORD*)& byte_5D4594[v35 + 1050152])
                    {
                        sub_464B70(*(int*)& byte_5D4594[1049848]);
                    }
                    else
                    {
                        sub_465C30(*(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
                    }
                }
                else
                {
                    sub_465C70(*(int*)& byte_5D4594[1049848]);
                }
            }
            goto LABEL_80;
        }
        v36 = sub_4281F0(&v56, (int4*)& byte_587000[136336]);
        if (v36 && !byte_5D4594[1049870])
        {
            if (!*(_DWORD*)& byte_5D4594[1049856])
            {
                sub_4623B0(*(int*)& byte_5D4594[1049848]);
                sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
            }
            goto LABEL_121;
        }
        v37 = sub_4281F0(&v56, (int4*)& byte_587000[136352]);
        if (!v37)
            goto LABEL_119;
        v38 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 108);
        if (v38 == *(_DWORD*)& byte_5D4594[1062560]
            || v38 == *(_DWORD*)& byte_5D4594[1049728]
            || v38 == *(_DWORD*)& byte_5D4594[1049724]
            || v38 == *(_DWORD*)& byte_5D4594[1062556]
            || v38 == *(_DWORD*)& byte_5D4594[1062564])
        {
            sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
            goto LABEL_121;
        }
        *(_DWORD*)& byte_5D4594[1049804] = (v56.field_0 - 314) / 50;
        *(_DWORD*)& byte_5D4594[1049808] = (*(_DWORD*)& byte_5D4594[1062512] + v56.field_4 - 13) / 50;
        if (!sub_464B40((v56.field_0 - 314) / 50, (*(_DWORD*)& byte_5D4594[1062512] + v56.field_4 - 13) / 50))
            goto LABEL_121;
        if (*(_DWORD*)& byte_5D4594[1049856])
        {
            v39 = 148
                * (*(_DWORD*)& byte_5D4594[1049808]
                    + 14 * *(_DWORD*)& byte_5D4594[1049804]
                    + 7 * *(_DWORD*)& byte_5D4594[1049804]);
            if (byte_5D4594[v39 + 1050160]
                && (v40 = *(_DWORD * *)& byte_5D4594[v39 + 1050020]) != 0
                && ((v41 = v40[28], v41 & 0x2000000)
                    && *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x2000000
                    && v40[29] == *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 116)
                    || v41 & 0x1001000 && *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 112) & 0x1001000))
            {
                v42 = *(_DWORD*)& byte_5D4594[v39 + 1050024];
                *(_DWORD*)& byte_5D4594[1049860] = 1;
                v40[32] = v42;
                sub_4623B0((int)v40);
            }
            else
            {
                *(_DWORD*)& byte_5D4594[1049860] = 1;
                sub_464B70(*(int*)& byte_5D4594[1049848]);
            }
            goto LABEL_121;
        }
        if (byte_5D4594[148
            * (*(_DWORD*)& byte_5D4594[1049800]
                + 14 * *(_DWORD*)& byte_5D4594[1049796]
                + 7 * *(_DWORD*)& byte_5D4594[1049796])
            + 1050160])
        {
            v55 = *(_DWORD*)& byte_5D4594[1049800];
            v54 = *(_DWORD*)& byte_5D4594[1049796];
        LABEL_120:
            sub_4649B0(*(int*)& byte_5D4594[1049848], v54, v55);
            goto LABEL_121;
        }
        if (!sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049804], *(int*)& byte_5D4594[1049808]))
        {
        LABEL_80:
            sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]);
            goto LABEL_121;
        }
        sub_452D80(792, 100);
        v43 = *(_DWORD*)& byte_5D4594[1049800]
            + 14 * *(_DWORD*)& byte_5D4594[1049796]
            + 7 * *(_DWORD*)& byte_5D4594[1049796];
        v44 = 37 * v43;
        v45 = *(_DWORD*)& byte_5D4594[148 * v43 + 1050156];
        if (v45)
        {
            v46 = 148
                * (*(_DWORD*)& byte_5D4594[1049808]
                    + 14 * *(_DWORD*)& byte_5D4594[1049804]
                    + 7 * *(_DWORD*)& byte_5D4594[1049804]);
            *(_DWORD*)& byte_5D4594[v46 + 1050156] = v45;
            *(_DWORD*)& byte_5D4594[4 * v44 + 1050156] = 0;
            *(_DWORD*)& byte_5D4594[1062480] = &byte_5D4594[v46 + 1050020];
        }
        sub_461B50();
    LABEL_121:
        sub_4776A0();
        if (!*(_DWORD*)& byte_5D4594[1049856])
            sub_45A4B0(*(_QWORD * *)& byte_5D4594[1049848]);
        *(_DWORD*)& byte_5D4594[1049848] = 0;
        *(_DWORD*)& byte_5D4594[1049856] = 0;
        return 1;
    case 8:
        return 1;
    case 9:
        if (*(_DWORD*)& byte_5D4594[1049864] == 5)
            goto LABEL_5;
        return 0;
    case 19:
        if (sub_4372B0())
            return 1;
        v6 = sub_4281F0(&v56, (int4*)& byte_587000[136384]);
        if (v6)
            goto LABEL_124;
        v7 = sub_4281F0(&v56, (int4*)& byte_587000[136400]);
        if (v7)
            goto LABEL_124;
        nox_window_call_field_94(*(int*)& byte_5D4594[1062456], 16391, *(int*)& byte_5D4594[1062500], 0);
        return 1;
    case 20:
        if (sub_4372B0())
            return 1;
        v4 = sub_4281F0(&v56, (int4*)& byte_587000[136384]);
        if (v4)
            goto LABEL_124;
        v5 = sub_4281F0(&v56, (int4*)& byte_587000[136400]);
        if (v5)
            goto LABEL_124;
        nox_window_call_field_94(*(int*)& byte_5D4594[1062456], 16391, *(int*)& byte_5D4594[1062504], 0);
        return 1;
    default:
    LABEL_124:
        if (*(_DWORD*)& byte_5D4594[1049864] == 5)
            return 1;
        return 0;
    }
}
// 464C71: variable 'v4' is possibly undefined
// 464C8B: variable 'v5' is possibly undefined
// 464CD6: variable 'v6' is possibly undefined
// 464CF0: variable 'v7' is possibly undefined
// 464D4C: variable 'v8' is possibly undefined
// 464E24: variable 'v14' is possibly undefined
// 464E64: variable 'v15' is possibly undefined
// 464F2B: variable 'v21' is possibly undefined
// 464F52: variable 'v22' is possibly undefined
// 464F6C: variable 'v23' is possibly undefined
// 465009: variable 'v24' is possibly undefined
// 465020: variable 'v25' is possibly undefined
// 465066: variable 'v26' is possibly undefined
// 465200: variable 'v30' is possibly undefined
// 46521A: variable 'v31' is possibly undefined
// 465281: variable 'v34' is possibly undefined
// 46535F: variable 'v36' is possibly undefined
// 4653B8: variable 'v37' is possibly undefined

//----- (004657B0) --------------------------------------------------------
int __cdecl sub_4657B0(__int16 a1)
{
    char v2[4]; // [esp+0h] [ebp-4h]

    v2[0] = -55;
    v2[1] = 30;
    *(_WORD*)& v2[2] = a1;
    return sub_40EBC0(31, 0, v2, 4);
}

//----- (004657E0) --------------------------------------------------------
char __cdecl sub_4657E0(_DWORD* a1)
{
    int v1; // eax

    v1 = sub_4281F0((int2*)a1, (int4*)& byte_587000[136352]);
    if (v1)
    {
        LOBYTE(v1) = byte_5D4594[148
            * ((a1[1] + *(_DWORD*)& byte_5D4594[1062512] - 13) / 50
                + 14 * ((*a1 - 314) / 50)
                + 7 * ((*a1 - 314) / 50))
            + 1050160];
        if ((_BYTE)v1)
            LOBYTE(v1) = sub_465870(*(_DWORD*)& byte_5D4594[148
                * ((a1[1] + *(_DWORD*)& byte_5D4594[1062512] - 13) / 50
                    + 14 * ((*a1 - 314) / 50)
                    + 7 * ((*a1 - 314) / 50))
                + 1050020
                + 4
                * byte_5D4594[148
                * ((a1[1] + *(_DWORD*)& byte_5D4594[1062512] - 13) / 50
                    + 14 * ((*a1 - 314) / 50)
                    + 7 * ((*a1 - 314) / 50))
                + 1050160]]);
    }
    return v1;
}
// 4657F5: variable 'v1' is possibly undefined

//----- (00465870) --------------------------------------------------------
int __cdecl sub_465870(__int16 a1)
{
    char v2[4]; // [esp+0h] [ebp-4h]

    v2[0] = -55;
    v2[1] = 28;
    *(_WORD*)& v2[2] = a1;
    return sub_40EBC0(31, 0, v2, 4);
}

//----- (004658A0) --------------------------------------------------------
void __cdecl sub_4658A0(int a1, int2* a2)
{
    if (byte_5D4594[1049868] == 2)
    {
        if (sub_4281F0(a2, (int4*)& byte_587000[136336]))
        {
            *(_DWORD*)& byte_5D4594[1049848] = *(_DWORD*)& byte_5D4594[4 * sub_465990(a2) + 1049872];
            *(_DWORD*)& byte_5D4594[1049856] = 1;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1049856] = 0;
            if (sub_4281F0(a2, (int4*)& byte_587000[136368]))
            {
                if ((a2->field_4 - 13) / 50 == 2)
                    sub_473610();
            }
            else if (sub_4281F0(a2, (int4*)& byte_587000[136352]))
            {
                *(_DWORD*)& byte_5D4594[1049796] = (a2->field_0 - 314) / 50;
                *(_DWORD*)& byte_5D4594[1049800] = (a2->field_4 + *(int*)& byte_5D4594[1062512] - 13) / 50;
                if (sub_464B40(*(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]))
                    sub_465A30();
            }
        }
    }
}
// 4658C2: variable 'v2' is possibly undefined
// 4658FF: variable 'v3' is possibly undefined
// 465934: variable 'v5' is possibly undefined

//----- (00465990) --------------------------------------------------------
int __cdecl sub_465990(_DWORD* a1)
{
    int v1; // eax
    int v2; // esi
    int v3; // eax
    int v5; // eax
    int2 v6; // [esp+4h] [ebp-8h]

    v1 = a1[1] - 15;
    v6.field_0 = *a1 - 11;
    v6.field_4 = v1;
    v2 = 0;
    while (1)
    {
        v3 = sub_4281F0(&v6, (int4*)& byte_587000[16 * v2 + 136192]);
        if (!v3)
            goto LABEL_6;
        if (v2 == 6)
            break;
        if (v2)
            return v2;
        if (*(_DWORD*)& byte_5D4594[1049872])
            return 0;
    LABEL_6:
        if (++v2 >= 9)
            return -1;
    }
    v5 = *(_DWORD*)& byte_5D4594[1049904];
    if (!*(_DWORD*)& byte_5D4594[1049904])
        return 5;
    while (!(*(_DWORD*)(v5 + 112) & 0x2000000) || !(*(_BYTE*)(v5 + 116) & 2))
    {
        v5 = *(_DWORD*)(v5 + 368);
        if (!v5)
            return 5;
    }
    return 8;
}
// 4659C7: variable 'v3' is possibly undefined

//----- (00465A30) --------------------------------------------------------
void sub_465A30()
{
    int v0; // eax
    _DWORD* v1; // eax
    wchar_t* v2; // eax
    int* v3[2]; // [esp+0h] [ebp-8h]

    v0 = 148
        * (*(_DWORD*)& byte_5D4594[1049800] + 14 * *(_DWORD*)& byte_5D4594[1049796] + 7 * *(_DWORD*)& byte_5D4594[1049796]);
    if (byte_5D4594[v0 + 1050160])
    {
        v1 = sub_45A240(*(_DWORD*)(*(_DWORD*)& byte_5D4594[v0 + 1050020] + 108));
        *(_DWORD*)& byte_5D4594[1049848] = v1;
        if (v1)
        {
            v1[30] |= 0x40000000u;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) = *(_DWORD*)& byte_5D4594[148
                * (*(_DWORD*)& byte_5D4594[1049800]
                    + 14
                    * *(_DWORD*)& byte_5D4594[1049796]
                    + 7
                    * *(_DWORD*)& byte_5D4594[1049796])
                + 1050024];
            qmemcpy(
                (void*)(*(_DWORD*)& byte_5D4594[1049848] + 432),
                (const void*)(*(_DWORD*)& byte_5D4594[148
                    * (*(_DWORD*)& byte_5D4594[1049800]
                        + 14 * *(_DWORD*)& byte_5D4594[1049796]
                        + 7 * *(_DWORD*)& byte_5D4594[1049796])
                    + 1050020]
                    + 432),
                0x18u);
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1049848] + 292) = *(_WORD*)(*(_DWORD*)& byte_5D4594[148
                * (*(_DWORD*)& byte_5D4594[1049800]
                    + 14
                    * *(_DWORD*)& byte_5D4594[1049796]
                    + 7
                    * *(_DWORD*)& byte_5D4594[1049796])
                + 1050020]
                + 292);
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1049848] + 294) = *(_WORD*)(*(_DWORD*)& byte_5D4594[148
                * (*(_DWORD*)& byte_5D4594[1049800]
                    + 14
                    * *(_DWORD*)& byte_5D4594[1049796]
                    + 7
                    * *(_DWORD*)& byte_5D4594[1049796])
                + 1050020]
                + 294);
            v3[1] = 0;
            v3[0] = (int*)& byte_5D4594[148
                * (*(_DWORD*)& byte_5D4594[1049800]
                    + 14 * *(_DWORD*)& byte_5D4594[1049796]
                    + 7 * *(_DWORD*)& byte_5D4594[1049796])
                + 1050020];
            sub_461E60((_QWORD * **)v3);
        }
        else
        {
            v2 = loadString_sub_40F1D0((char*)& byte_587000[139404], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1123);
            sub_445490(v2);
        }
    }
}

//----- (00465BE0) --------------------------------------------------------
int __cdecl sub_465BE0(int2* a1)
{
    int result; // eax
    __int16 v2; // dx
    char v3[7]; // [esp+0h] [ebp-8h]

    result = *(_DWORD*)& byte_5D4594[1049848];
    if (*(_DWORD*)& byte_5D4594[1049848])
    {
        v3[0] = 114;
        *(_WORD*)& v3[1] = sub_578B00(*(int*)& byte_5D4594[1049848]);
        v2 = a1->field_4;
        *(_WORD*)& v3[3] = a1->field_0;
        *(_WORD*)& v3[5] = v2;
        result = sub_40EBC0(31, 0, v3, 7);
    }
    return result;
}

//----- (00465C30) --------------------------------------------------------
BOOL __cdecl sub_465C30(int a1, int a2)
{
    *(_DWORD*)& byte_5D4594[1049796] = a1;
    *(_DWORD*)& byte_5D4594[1049800] = a2;
    sub_465A30();
    sub_4623B0(*(int*)& byte_5D4594[1049848]);
    return sub_4649B0(*(int*)& byte_5D4594[1049848], a1, a2);
}

//----- (00465C70) --------------------------------------------------------
void __cdecl sub_465C70(int a1)
{
    int v2; // [esp-4h] [ebp-4h]

    if (a1)
    {
        v2 = a1;
        LOBYTE(a1) = 116;
        *(_WORD*)((char*)& a1 + 1) = sub_578B00(v2);
        sub_40EBC0(31, 0, &a1, 3);
    }
}

//----- (00465CA0) --------------------------------------------------------
int sub_465CA0()
{
    nox_window_set_hidden(*(int*)& byte_5D4594[1062476], 0);
    *(_DWORD*)& byte_5D4594[1049864] = 5;
    sub_477610(6);
    return sub_46ADC0(*(int*)& byte_5D4594[1062456]);
}

//----- (00465CD0) --------------------------------------------------------
void __cdecl sub_465CD0(_DWORD* a1, int a2, int a3, int a4)
{
    int v4; // edi
    char* v5; // ebx
    int v6; // esi
    int2 v7; // [esp+8h] [ebp-8h]

    v4 = a4;
    if (a4)
    {
        sub_473970((int2*)a1, &v7);
        v5 = sub_461EF0(a2);
        if (v5)
        {
            v6 = 4;
            do
            {
                *(_DWORD*)& byte_5D4594[1049848] = **(_DWORD * *)v5;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) = *(_DWORD*)(*(_DWORD*)v5 + v6);
                if (!sub_4C12C0())
                    sub_465BE0(&v7);
                v6 += 4;
                --v4;
                *(_DWORD*)& byte_5D4594[1049848] = 0;
            } while (v4);
        }
    }
}

//----- (00465D50) --------------------------------------------------------
int __cdecl sub_465D50_draw(int a1)
{
    int v2; // eax
    int result; // eax
    int v4; // [esp+0h] [ebp-4h]

    sub_46AA60(*(_DWORD * *)(a1 + 396), &v4, &a1);
    v2 = sub_4615C0();
    if (v2)
    {
        *(_DWORD*)(v2 + 12) = v4 + 51;
        *(_DWORD*)(v2 + 16) = a1 + 81;
        (*(void(__cdecl * *)(unsigned __int8*, int))(v2 + 300))(&byte_5D4594[1049732], v2);
        result = 1;
    }
    else
    {
        if (!*(_DWORD*)& byte_5D4594[1062496] && !*(_DWORD*)& byte_5D4594[1062492])
            sub_47D2C0(*(int*)& byte_5D4594[1050000], v4 + 21, a1 + 50);
        result = 1;
    }
    return result;
}

//----- (00465DE0) --------------------------------------------------------
int __cdecl sub_465DE0(int a1)
{
    *(_DWORD*)& byte_5D4594[1049844] = a1;
    return sub_467460();
}
// 467460: using guessed type int sub_467460(void);

//----- (00465DF0) --------------------------------------------------------
int sub_465DF0()
{
    return *(_DWORD*)& byte_5D4594[1049844];
}

//----- (00465E00) --------------------------------------------------------
int sub_465E00()
{
    _DWORD* v0; // eax
    int result; // eax
    _DWORD* v2; // eax
    char* v3; // eax
    char* v4; // eax
    _DWORD* v5; // eax
    int v6; // eax
    int v7; // eax

    sub_467050();
    sub_4671E0();
    *(_DWORD*)& byte_5D4594[1063636] = sub_43F360((char*)& byte_587000[139424]);
    *(_DWORD*)& byte_5D4594[1049732] = 0;
    *(_DWORD*)& byte_5D4594[1049736] = 0;
    *(_DWORD*)& byte_5D4594[1049740] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1049744] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1049764] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1049768] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1049748] = 0;
    *(_DWORD*)& byte_5D4594[1049752] = 0;
    *(_DWORD*)& byte_5D4594[1062452] = nox_window_new(0, 552, 0, 0, 563, 264, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1062452], 0, sub_4661C0, 0);
    v0 = nox_window_new(*(int*)& byte_5D4594[1062452], 8, 0, 224, nox_win_width, 40, 0);
    nox_window_set_all_funcs(v0, sub_464BA0, sub_4661C0, sub_4667E0);
    *(_DWORD*)& byte_5D4594[1062456] = nox_window_new(*(int*)& byte_5D4594[1062452], 40, 0, 0, 563, 224, sub_466220);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1062456], sub_464BD0, sub_463430, sub_466620);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062456] + 44) |= 0x100u;
    *(_DWORD*)& byte_5D4594[1062472] = nox_window_new(*(int*)& byte_5D4594[1062452], 40, 0, 0, 1, 1, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1062472], sub_464BD0, sub_4661C0, 0);
    *(_DWORD*)& byte_5D4594[1062468] = nox_window_new(*(int*)& byte_5D4594[1062456], 40, 173, 174, 50, 50, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1062468], sub_464770, sub_4625D0, sub_4661D0);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062468] + 44) |= 0x100u;
    result = sub_466950(*(int*)& byte_5D4594[1062456]);
    if (!result)
        return 0;

    result = sub_466C40(*(int*)& byte_5D4594[1062456]);
    if (!result)
        return 0;

    result = sub_466ED0(*(int*)& byte_5D4594[1062456]);
    if (!result)
        return 0;

    nox_win_unk5 = nox_window_new(0, 0x408 | NOX_WIN_LAYER_BACK, -1, nox_win_height - 127, 111, 127, 0);
    if (!nox_win_unk5)
        return 0;

    nox_window_set_all_funcs(nox_win_unk5, sub_464BB0, sub_466580, 0);
    v3 = sub_42F970("CurrentWeapon");
    sub_46AE60(nox_win_unk5, (int)v3);
    v4 = sub_42F970("CurrentWeaponLit");
    sub_46AEA0(nox_win_unk5, (int)v4);
    sub_46AE40(nox_win_unk5, -1, 0);
    nox_win_init_cur_weapon(nox_win_unk5, 24, 51, 53, 53);
    sub_471160(nox_win_unk5, 79, 40, 20, 127);
    sub_470D70();
    v5 = nox_window_new(nox_win_unk5, 8, 5, 11, 28, 29, 0);
    nox_window_set_all_funcs(v5, sub_466550, sub_4661C0, sub_466160);
    memset(&byte_5D4594[1050020], 0, 0x3090u);
    if (!*(_DWORD*)& byte_5D4594[1062560])
    {
        *(_DWORD*)& byte_5D4594[1062560] = sub_44CFC0((CHAR*)& byte_587000[139468]);
        *(_DWORD*)& byte_5D4594[1049728] = sub_44CFC0((CHAR*)& byte_587000[139476]);
        *(_DWORD*)& byte_5D4594[1049724] = sub_44CFC0((CHAR*)& byte_587000[139492]);
    }
    *(_DWORD*)& byte_5D4594[1052980] = sub_45A240(*(int*)& byte_5D4594[1062560]);
    if (*(_DWORD*)& byte_5D4594[1052980])
        byte_5D4594[1053120] = 1;
    v6 = *(_DWORD*)& byte_5D4594[1062564];
    if (!*(_DWORD*)& byte_5D4594[1062564])
    {
        v6 = sub_44CFC0((CHAR*)& byte_587000[139508]);
        *(_DWORD*)& byte_5D4594[1062564] = v6;
    }
    *(_DWORD*)& byte_5D4594[1056088] = sub_45A240(v6);
    if (*(_DWORD*)& byte_5D4594[1056088])
        byte_5D4594[1056228] = 1;
    v7 = *(_DWORD*)& byte_5D4594[1062556];
    if (!*(_DWORD*)& byte_5D4594[1062556])
    {
        v7 = sub_44CFC0((CHAR*)& byte_587000[139520]);
        *(_DWORD*)& byte_5D4594[1062556] = v7;
    }
    *(_DWORD*)& byte_5D4594[1059196] = sub_45A240(v7);
    if (*(_DWORD*)& byte_5D4594[1059196])
        byte_5D4594[1059336] = 1;

    return *(_DWORD*)& byte_5D4594[1062456];
}

//----- (00466160) --------------------------------------------------------
int sub_466160()
{
    wchar_t* v0; // eax

    if (byte_5D4594[1049868] == 2)
        v0 = loadString_sub_40F1D0((char*)& byte_587000[139564], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 410);
    else
        v0 = loadString_sub_40F1D0((char*)& byte_587000[139620], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 414);
    sub_4776B0(v0);
    return 1;
}

//----- (004661C0) --------------------------------------------------------
int sub_4661C0()
{
    return 1;
}

//----- (004661D0) --------------------------------------------------------
int sub_4661D0()
{
    wchar_t* v0; // eax
    wchar_t* v2; // eax

    if (*(_DWORD*)& byte_5D4594[1062480])
    {
        v0 = sub_4BF050(**(wchar_t***)& byte_5D4594[1062480]);
        sub_4776B0(v0);
    }
    else
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[139672], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3331);
        sub_4776B0(v2);
    }
    return 1;
}

//----- (00466220) --------------------------------------------------------
int __cdecl sub_466220(int a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // ecx
    int v6; // ecx
    int v7; // ecx
    int v8; // eax

    if (a2 == 16391)
    {
        switch (sub_46B0A0(a3))
        {
        case 9102:
            if (*(int*)& byte_5D4594[1062512] - 25 >= 0)
                v5 = *(int*)& byte_5D4594[1062512] - 25 - (*(int*)& byte_5D4594[1062512] - 25) % 50;
            else
                v5 = 0;
            *(_DWORD*)& byte_5D4594[1062512] = v5;
            nox_window_call_field_94(
                *(int*)& byte_5D4594[1062508],
                16394,
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - v5,
                0);
            sub_452D80(766, 100);
            result = 0;
            break;
        case 9103:
            v6 = *(_DWORD*)& byte_5D4594[1062512] + 50;
            *(_DWORD*)& byte_5D4594[1062512] = v6;
            if (v6 <= *(int*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4))
                v7 = v6 - v6 % 50;
            else
                v7 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4);
            *(_DWORD*)& byte_5D4594[1062512] = v7;
            nox_window_call_field_94(
                *(int*)& byte_5D4594[1062508],
                16394,
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - v7,
                0);
            sub_452D80(766, 100);
            result = 0;
            break;
        case 9105:
            v8 = sub_469FA0() - 150;
            if (*(_DWORD*)& byte_5D4594[1049864] == 5)
                goto LABEL_23;
            if (v8 < 0)
                v8 = 0;
            byte_5D4594[1049869] = 1;
            *(_DWORD*)& byte_5D4594[1062516] = *(_DWORD*)& byte_5D4594[1062512];
            *(_DWORD*)& byte_5D4594[1062512] = *(_DWORD*)& byte_5D4594[1062520];
            nox_window_call_field_94(*(int*)& byte_5D4594[1062508], 16395, 0, v8);
            nox_window_call_field_94(
                *(int*)& byte_5D4594[1062508],
                16394,
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - *(_DWORD*)& byte_5D4594[1062512],
                0);
            sub_46AE60(*(int*)& byte_5D4594[1062528], *(int*)& byte_5D4594[1049980]);
            sub_46AEC0(*(int*)& byte_5D4594[1062528], *(int*)& byte_5D4594[1049984]);
            sub_46B080(*(_DWORD * *)& byte_5D4594[1062528], 9106);
            result = 0;
            break;
        case 9106:
            byte_5D4594[1049869] = 0;
            *(_DWORD*)& byte_5D4594[1062520] = *(_DWORD*)& byte_5D4594[1062512];
            *(_DWORD*)& byte_5D4594[1062512] = *(_DWORD*)& byte_5D4594[1062516];
            nox_window_call_field_94(*(int*)& byte_5D4594[1062508], 16395, 0, 850);
            nox_window_call_field_94(
                *(int*)& byte_5D4594[1062508],
                16394,
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - *(_DWORD*)& byte_5D4594[1062512],
                0);
            sub_46AE60(*(int*)& byte_5D4594[1062528], 0);
            sub_46AEC0(*(int*)& byte_5D4594[1062528], *(int*)& byte_5D4594[1049976]);
            sub_46B080(*(_DWORD * *)& byte_5D4594[1062528], 9105);
            result = 0;
            break;
        case 9107:
            if (*(_DWORD*)& byte_5D4594[1049864] == 5)
                goto LABEL_23;
            byte_5D4594[1049870] = 1;
            sub_46AE60(*(int*)& byte_5D4594[1062524], 0);
            sub_46AEC0(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049988]);
            sub_46B080(*(_DWORD * *)& byte_5D4594[1062524], 9108);
            nox_window_set_hidden(*(int*)& byte_5D4594[1062468], 1);
            result = 0;
            break;
        case 9108:
            if (*(_DWORD*)& byte_5D4594[1049864] != 5)
            {
                byte_5D4594[1049870] = 0;
                sub_46AE60(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049992]);
                sub_46AEC0(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049996]);
                sub_46B080(*(_DWORD * *)& byte_5D4594[1062524], 9107);
                nox_window_set_hidden(*(int*)& byte_5D4594[1062468], 0);
            }
            goto LABEL_23;
        case 9111:
            sub_467C10();
            result = 0;
            break;
        default:
            goto LABEL_23;
        }
    }
    else if (a2 == 16393)
    {
        result = 0;
        *(_DWORD*)& byte_5D4594[1062512] = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - a4;
    }
    else
    {
    LABEL_23:
        result = 0;
    }
    return result;
}

//----- (00466550) --------------------------------------------------------
int __cdecl sub_466550(int a1, unsigned int a2)
{
    if (a2 >= 5)
    {
        if (a2 <= 6)
            return 1;
        if (a2 == 7)
        {
            sub_467C60();
            return 1;
        }
    }
    return 0;
}

//----- (00466580) --------------------------------------------------------
int __cdecl sub_466580(_DWORD* a1)
{
    _DWORD* v1; // esi
    int v2; // eax
    __int16* v3; // eax
    int v5; // [esp+4h] [ebp-Ch]
    int v6; // [esp+8h] [ebp-8h]
    int v7; // [esp+Ch] [ebp-4h]

    v1 = a1;
    sub_46AA60(a1, &v5, &a1);
    nox_window_get_size((int)v1, &v7, &v6);
    if (byte_5D4594[1049868])
        v2 = v1[19];
    else
        v2 = v1[15];
    sub_47D2C0(v2, v5, (int)a1);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v3 = (__int16*)sub_42E8E0(35, 1);
    if (v3)
        sub_43F6E0(*(int*)& byte_5D4594[1063636], v3, v5 + 19, (int)a1 + 102);
    return 1;
}

//----- (00466620) --------------------------------------------------------
int __cdecl sub_466620(int a1, int a2, unsigned int a3)
{
    wchar_t* v3; // eax
    int2 a2a; // [esp+0h] [ebp-8h]

    a2a.field_4 = a3 >> 16;
    a2a.field_0 = (unsigned __int16)a3;
    v3 = sub_466660(a1, &a2a);
    sub_4776B0(v3);
    return 1;
}

//----- (00466660) --------------------------------------------------------
wchar_t* __cdecl sub_466660(int a1, int2* a2)
{
    int v2; // eax
    int v3; // eax
    wchar_t* result; // eax
    wchar_t* v5; // eax
    int v6; // eax
    int v7; // esi
    int v8; // edi
    int v9; // edx
    int v10; // eax
    int v12; // eax
    int v13; // ecx

    v2 = sub_4281F0(a2, (int4*)& byte_587000[136336]);
    if (!v2)
    {
        if (!byte_5D4594[1049869])
        {
            v6 = sub_4281F0(a2, (int4*)& byte_587000[136368]);
            if (v6)
            {
                v7 = a2->field_4 - 13;
                v8 = v7 / 50;
                v9 = 20;
                *(_DWORD*)& byte_5D4594[1049796] = v7 / 50;
            }
            else
            {
                v10 = sub_4281F0(a2, (int4*)& byte_587000[136352]);
                if (!v10)
                    return 0;
                v8 = (a2->field_0 - 314) / 50;
                *(_DWORD*)& byte_5D4594[1049796] = (a2->field_0 - 314) / 50;
                v9 = (a2->field_4 + *(_DWORD*)& byte_5D4594[1062512] - 13) / 50;
            }
            *(_DWORD*)& byte_5D4594[1049800] = v9;
            if (sub_464B40(v8, v9))
            {
                v12 = 148
                    * (*(_DWORD*)& byte_5D4594[1049800]
                        + 14 * *(_DWORD*)& byte_5D4594[1049796]
                        + 7 * *(_DWORD*)& byte_5D4594[1049796]);
                if (byte_5D4594[v12 + 1050160])
                {
                    v13 = *(_DWORD*)& byte_5D4594[v12 + 1050020];
                    *(_DWORD*)(v13 + 128) = *(_DWORD*)& byte_5D4594[v12 + 1050024];
                    return sub_4BF050((wchar_t*)v13);
                }
            }
        }
        return 0;
    }
    if (byte_5D4594[1049870] == 1)
        return 0;
    v3 = sub_465990(a2);
    if (v3 == -1)
        return loadString_sub_40F1D0((char*)& byte_587000[139728], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3155);
    v5 = *(wchar_t**)& byte_5D4594[4 * v3 + 1049872];
    if (v5)
        result = sub_4BF050(v5);
    else
        result = loadString_sub_40F1D0((char*)& byte_587000[139780], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3159);
    return result;
}
// 466676: variable 'v2' is possibly undefined
// 4666FF: variable 'v6' is possibly undefined
// 466737: variable 'v10' is possibly undefined

//----- (004667E0) --------------------------------------------------------
int __cdecl sub_4667E0(int a1, int a2, unsigned int a3)
{
    int v3; // edx
    int v4; // esi
    int v5; // ecx
    int v6; // eax
    wchar_t* v7; // eax
    int result; // eax
    int v9; // ecx
    wchar_t* v10; // eax
    int v11; // eax
    wchar_t* v12; // eax
    int v13; // eax
    wchar_t* v14; // eax
    int2 v15; // [esp+4h] [ebp-8h]

    v3 = 40;
    v15.field_0 = (unsigned __int16)a3;
    v15.field_4 = a3 >> 16;
    v4 = 0;
    while (v3 <= (unsigned __int16)a3)
    {
        v3 += 35;
        ++v4;
    }
    v5 = 0;
    do
    {
        if ((1 << v5) & *(_DWORD*)& byte_5D4594[1062540] && v5 != 31)
            --v4;
        if (v4 < 0)
            break;
        ++v5;
    } while (v5 < 32);
    if (v5 != 32)
    {
        v6 = sub_424920(v5);
        v7 = (wchar_t*)sub_424930(v6);
        sub_4776B0(v7);
        return 1;
    }
    v9 = 0;
    do
    {
        if ((1 << v9) & byte_5D4594[1062536])
            --v4;
        if (v4 < 0)
            break;
        ++v9;
    } while (v9 < 6);
    if (v9 != 6)
    {
        v10 = sub_413480(1 << v9);
        sub_4776B0(v10);
        return 1;
    }
    if (!sub_40A5C0(4096))
        goto LABEL_28;
    v11 = sub_4281F0(&v15, (int4*)& byte_5D4594[1049812]);
    if (v11 == 1)
    {
        v12 = loadString_sub_40F1D0((char*)& byte_587000[139828], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4385);
        sub_4776B0(v12);
        return 1;
    }
    v13 = sub_4281F0(&v15, (int4*)& byte_5D4594[1049828]);
    if (v13 == 1 && sub_4BFD30() == 1)
    {
        v14 = loadString_sub_40F1D0((char*)& byte_587000[139884], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4388);
        sub_4776B0(v14);
        result = 1;
    }
    else
    {
    LABEL_28:
        sub_4776B0(0);
        result = 1;
    }
    return result;
}
// 4668C0: variable 'v11' is possibly undefined
// 466900: variable 'v13' is possibly undefined

//----- (00466950) --------------------------------------------------------
int __cdecl sub_466950(int a1)
{
    _DWORD* v1; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    int v5[4]; // [esp+10h] [ebp-15Ch]
    char v6[332]; // [esp+20h] [ebp-14Ch]

    v5[1] = 0;
    v5[2] = 0;
    memset(v6, 0, sizeof(v6));
    v5[3] = 0;
    v5[0] = 0;
    *(_DWORD*)& v6[24] = 0;
    *(_DWORD*)& v6[48] = 0;
    *(_DWORD*)& v6[32] = *(_DWORD*)& byte_5D4594[1049940];
    *(_DWORD*)& v6[40] = *(_DWORD*)& byte_5D4594[1049944];
    *(_DWORD*)& v6[56] = *(_DWORD*)& byte_5D4594[1049944];
    *(_DWORD*)& v6[68] = 0x80000000;
    *(_DWORD*)& v6[8] = 1;
    *(_WORD*)& v6[72] = 0;
    *(_DWORD*)& v6[16] = a1;
    v1 = (_DWORD*)sub_4A91A0(a1, 1161, 522, 2, 20, 25, v6);
    *(_DWORD*)& byte_5D4594[1062500] = v1;
    if (!v1)
        return 0;
    sub_46B080(v1, 9102);
    memset(v6, 0, sizeof(v6));
    *(_DWORD*)& v6[32] = *(_DWORD*)& byte_5D4594[1049948];
    *(_DWORD*)& v6[24] = 0;
    *(_DWORD*)& v6[48] = 0;
    *(_DWORD*)& v6[40] = *(_DWORD*)& byte_5D4594[1049952];
    *(_DWORD*)& v6[56] = *(_DWORD*)& byte_5D4594[1049952];
    *(_DWORD*)& v6[68] = 0x80000000;
    *(_DWORD*)& v6[8] = 1;
    *(_WORD*)& v6[72] = 0;
    *(_DWORD*)& v6[16] = a1;
    v3 = (_DWORD*)sub_4A91A0(a1, 1161, 522, 148, 20, 25, v6);
    *(_DWORD*)& byte_5D4594[1062504] = v3;
    if (!v3)
        return 0;
    sub_46B080(v3, 9103);
    memset(v6, 0, sizeof(v6));
    v5[2] = 0;
    *(_DWORD*)& v6[20] = 0x80000000;
    *(_DWORD*)& v6[44] = 0x80000000;
    *(_DWORD*)& v6[28] = 0x80000000;
    *(_DWORD*)& v6[36] = 0x80000000;
    *(_DWORD*)& v6[52] = 0x80000000;
    *(_DWORD*)& v6[8] = 8;
    *(_DWORD*)& v6[16] = a1;
    v5[3] = 0;
    v5[0] = 0;
    v5[1] = 850;
    v4 = sub_4B4EE0(a1, 1033, 524, 42, 16, 91, v6, (float*)v5);
    *(_DWORD*)& byte_5D4594[1062508] = v4;
    if (!v4)
        return 0;
    sub_46B300((int)v4, sub_466BF0);
    sub_46B300(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 400), sub_466BA0);
    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 400) + 8) = 16;
    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 400) + 12) = 16;
    sub_46AE40(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 400), 0, -15);
    sub_4B5700(
        *(int*)& byte_5D4594[1062508],
        0,
        0,
        *(int*)& byte_5D4594[1049956],
        *(int*)& byte_5D4594[1049960],
        *(int*)& byte_5D4594[1049960]);
    return 1;
}

//----- (00466BA0) --------------------------------------------------------
int __cdecl sub_466BA0(_DWORD* a1, int a2, unsigned int a3, int a4)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1049848])
        result = sub_464BD0((int)a1, a2, a3);
    else
        result = sub_4A7F50(a1, a2, a3, a4);
    return result;
}

//----- (00466BF0) --------------------------------------------------------
int __cdecl sub_466BF0(int a1, int a2, unsigned int a3, int a4)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1049848])
        result = sub_464BD0(a1, a2, a3);
    else
        result = sub_4B4BA0(a1, a2, a3, a4);
    return result;
}

//----- (00466C40) --------------------------------------------------------
int __cdecl sub_466C40(int a1)
{
    _DWORD* v1; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    char v5[332]; // [esp+Ch] [ebp-14Ch]

    memset(v5, 0, sizeof(v5));
    *(_DWORD*)& v5[24] = 0;
    *(_DWORD*)& v5[48] = 0;
    *(_DWORD*)& v5[32] = 0;
    *(_DWORD*)& v5[40] = 0;
    *(_DWORD*)& v5[56] = *(_DWORD*)& byte_5D4594[1049976];
    *(_DWORD*)& v5[60] = -243;
    *(_DWORD*)& v5[64] = -170;
    *(_DWORD*)& v5[16] = a1;
    *(_DWORD*)& v5[8] = 1;
    v1 = (_DWORD*)sub_4A91A0(a1, 1161, 243, 170, 34, 34, v5);
    *(_DWORD*)& byte_5D4594[1062528] = v1;
    if (!v1)
        return 0;
    sub_46B080(v1, 9105);
    sub_46B070(*(int*)& byte_5D4594[1062528], sub_466E20);
    memset(v5, 0, sizeof(v5));
    *(_DWORD*)& v5[24] = *(_DWORD*)& byte_5D4594[1049992];
    *(_DWORD*)& v5[48] = 0;
    *(_DWORD*)& v5[32] = 0;
    *(_DWORD*)& v5[40] = 0;
    *(_DWORD*)& v5[56] = *(_DWORD*)& byte_5D4594[1049996];
    *(_DWORD*)& v5[60] = -5;
    *(_DWORD*)& v5[64] = -186;
    *(_DWORD*)& v5[16] = a1;
    *(_DWORD*)& v5[8] = 1;
    v3 = (_DWORD*)sub_4A91A0(a1, 1161, 5, 186, 34, 34, v5);
    *(_DWORD*)& byte_5D4594[1062524] = v3;
    if (!v3)
        return 0;
    sub_46B080(v3, 9107);
    sub_46B070(*(int*)& byte_5D4594[1062524], sub_466E20);
    memset(v5, 0, sizeof(v5));
    *(_DWORD*)& v5[24] = 0;
    *(_DWORD*)& v5[48] = 0;
    *(_DWORD*)& v5[32] = 0;
    *(_DWORD*)& v5[40] = 0;
    *(_DWORD*)& v5[56] = *(_DWORD*)& byte_5D4594[1049972];
    *(_DWORD*)& v5[60] = -547;
    *(_DWORD*)& v5[64] = -2;
    *(_DWORD*)& v5[16] = a1;
    *(_DWORD*)& v5[8] = 1;
    v4 = (_DWORD*)sub_4A91A0(a1, 1161, 547, 2, 16, 16, v5);
    *(_DWORD*)& byte_5D4594[1062532] = v4;
    if (!v4)
        return 0;
    sub_46B080(v4, 9111);
    sub_46B070(*(int*)& byte_5D4594[1062532], sub_466E20);
    return 1;
}

//----- (00466E20) --------------------------------------------------------
int __cdecl sub_466E20(_DWORD* a1)
{
    wchar_t* v1; // eax
    int result; // eax

    switch (*a1)
    {
    case 0x2391:
        v1 = loadString_sub_40F1D0((char*)& byte_587000[139948], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 424);
        goto LABEL_7;
    case 0x2392:
        v1 = loadString_sub_40F1D0((char*)& byte_587000[140000], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 428);
        goto LABEL_7;
    case 0x2393:
        v1 = loadString_sub_40F1D0((char*)& byte_587000[140052], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 432);
        goto LABEL_7;
    case 0x2394:
        v1 = loadString_sub_40F1D0((char*)& byte_587000[140100], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 436);
        goto LABEL_7;
    case 0x2397:
        v1 = loadString_sub_40F1D0((char*)& byte_587000[140152], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 440);
    LABEL_7:
        sub_4776B0(v1);
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

//----- (00466ED0) --------------------------------------------------------
int __cdecl sub_466ED0(int a1)
{
    int result; // eax
    _DWORD* v2; // eax

    result = nox_new_window_from_file("identify.wnd", 0);
    *(_DWORD*)& byte_5D4594[1062476] = result;
    if (result)
    {
        sub_46AB20((_DWORD*)result, 200, 200);
        sub_46B120(*(_DWORD * *)& byte_5D4594[1062476], a1);
        sub_46A9B0(*(_DWORD * *)& byte_5D4594[1062476], 51, 15);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1062476], 9155);
        sub_46B340((int)v2, sub_466F50);
        result = 1;
    }
    return result;
}

//----- (00466F50) --------------------------------------------------------
int __cdecl sub_466F50(_DWORD* a1, int* a2)
{
    int v3; // ecx
    _DWORD* v4; // eax
    int v5; // ecx
    _DWORD* v6; // ebx
    int v7; // edx
    int v8; // edi
    int v9; // ebp
    _BYTE* v10; // esi
    int* v11; // edi
    _BYTE** v12; // esi
    int v13; // ebx
    _BYTE* v14; // eax
    int v15; // [esp+0h] [ebp-8h]
    int v16; // [esp+4h] [ebp-4h]

    if (!*(_DWORD*)& byte_5D4594[1063116])
        return 1;
    v3 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 112);
    if (v3 & 0x13001000)
    {
        v4 = v3 & 0x11001000 ? sub_413250(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 108)) : sub_413270(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1063116] + 108));
        v6 = v4;
        if (v4)
        {
            v7 = *(_DWORD*)& byte_5D4594[1063116];
            v8 = 1;
            v9 = *(_DWORD*)& byte_5D4594[1063116] + 432;
            v10 = v4 + 4;
            do
            {
                LOBYTE(v4) = v10[1];
                LOBYTE(v5) = *v10;
                LOBYTE(v7) = *(v10 - 1);
                sub_4340A0(v8++, v7, v5, (int)v4);
                v10 += 3;
            } while (v8 < 7);
            v11 = v6 + 9;
            v12 = (_BYTE * *)v9;
            v13 = 4;
            do
            {
                v14 = *v12;
                if (*v12)
                {
                    LOBYTE(v5) = v14[26];
                    LOBYTE(v7) = v14[25];
                    LOBYTE(v14) = v14[24];
                    sub_4340A0(*v11, (int)v14, v7, v5);
                }
                ++v12;
                ++v11;
                --v13;
            } while (v13);
        }
    }
    sub_46AA60(a1, &v15, &v16);
    sub_47D2C0(a2[6], a2[15] + v15, a2[16] + v16);
    return 1;
}
// 466FBD: variable 'v7' is possibly undefined
// 466FBD: variable 'v5' is possibly undefined

//----- (00467050) --------------------------------------------------------
char* sub_467050()
{
    char* result; // eax

    *(_DWORD*)& byte_5D4594[1049908] = sub_42F970("InventoryBase");
    *(_DWORD*)& byte_5D4594[1049912] = sub_42F970("InventoryIdentifyBase");
    *(_DWORD*)& byte_5D4594[1049916] = sub_42F970("InventoryTray1");
    *(_DWORD*)& byte_5D4594[1049920] = sub_42F970("InventoryTray2");
    *(_DWORD*)& byte_5D4594[1049924] = sub_42F970("InventoryTray3");
    *(_DWORD*)& byte_5D4594[1049928] = sub_42F970("InventoryTraySpecial");
    *(_DWORD*)& byte_5D4594[1049932] = sub_42F970("InventoryTrayIdentifyLit");
    *(_DWORD*)& byte_5D4594[1049936] = sub_42F970("InventoryTrayMapLit");
    *(_DWORD*)& byte_5D4594[1049940] = sub_42F970("InventoryUpButton");
    *(_DWORD*)& byte_5D4594[1049944] = sub_42F970("InventoryUpButtonLit");
    *(_DWORD*)& byte_5D4594[1049948] = sub_42F970("InventoryDownButton");
    *(_DWORD*)& byte_5D4594[1049952] = sub_42F970("InventoryDownButtonLit");
    *(_DWORD*)& byte_5D4594[1049956] = sub_42F970("InventorySliderButton");
    *(_DWORD*)& byte_5D4594[1049960] = sub_42F970("InventorySliderButtonLit");
    *(_DWORD*)& byte_5D4594[1049964] = sub_42F970("InventoryEquipRing");
    *(_DWORD*)& byte_5D4594[1049968] = sub_42F970("InventoryQuickItemRing");
    *(_DWORD*)& byte_5D4594[1049972] = sub_42F970("InventoryCloseButtonLit");
    *(_DWORD*)& byte_5D4594[1049976] = sub_42F970("InventoryJournalButtonLit");
    *(_DWORD*)& byte_5D4594[1049980] = sub_42F970("InventoryInventoryButton");
    *(_DWORD*)& byte_5D4594[1049984] = sub_42F970("InventoryInventoryButtonLit");
    *(_DWORD*)& byte_5D4594[1049988] = sub_42F970("InventoryDollButtonLit");
    *(_DWORD*)& byte_5D4594[1049992] = sub_42F970("InventoryStatsButton");
    *(_DWORD*)& byte_5D4594[1049996] = sub_42F970("InventoryStatsButtonLit");
    *(_DWORD*)& byte_5D4594[1050000] = sub_42F970("GUIFist");
    *(_DWORD*)& byte_5D4594[1050004] = sub_42F970("SharedKeyMode");
    result = sub_42FA20("ExtraLives");
    *(_DWORD*)& byte_5D4594[1050008] = result;
    return result;
}

//----- (004671E0) --------------------------------------------------------
int sub_4671E0()
{
    int result; // eax
    int v1; // ecx
    wchar_t* v2; // eax
    int v3; // [esp-8h] [ebp-6Ch]
    wchar_t* v4; // [esp-4h] [ebp-68h]
    char v5[100]; // [esp+0h] [ebp-64h]

    nox_wcscpy((wchar_t*)& byte_5D4594[1062588], (const wchar_t*)& byte_5D4594[1063676]);
    if (sub_40A5C0(4096) || sub_4D6F50() || (result = sub_4D6F70()) != 0)
    {
        result = *(_DWORD*)& byte_5D4594[1049844];
        if (*(_DWORD*)& byte_5D4594[1049844] > 0xAu)
            result = 10;
        v1 = *(_DWORD*)& byte_5D4594[2618908];
    }
    else
    {
        v1 = *(_DWORD*)& byte_5D4594[2618908];
        if (!*(_DWORD*)& byte_5D4594[2618908])
            return result;
        result = *(char*)(*(_DWORD*)& byte_5D4594[2618908] + 3684);
    }
    if (v1)
    {
        nox_sprintf(
            v5,
            "experience:%s%d",
            *(_DWORD*)& byte_587000[4 * *(unsigned __int8*)(v1 + 2251) + 29456],
            result);
        v4 = loadString_sub_40F1D0(v5, 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4763);
        v3 = *(_DWORD*)& byte_5D4594[2618908] + 4704;
        v2 = loadString_sub_40F1D0((char*)& byte_587000[140836], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4761);
        result = nox_swprintf((wchar_t*)& byte_5D4594[1062588], v2, v3, v4);
    }
    return result;
}

//----- (004672C0) --------------------------------------------------------
int sub_4672C0()
{
    int result; // eax
    int v1; // edi
    int v2; // eax
    _DWORD* v3; // edx
    int v4; // eax
    int i; // esi
    int v6; // eax

    result = *(_DWORD*)& byte_5D4594[2614252];
    if (!*(_DWORD*)& byte_5D4594[2614252])
        return result;
    result = sub_477600();
    if (result)
        return result;
    result = sub_461160(1);
    if (result)
        return result;
    v1 = *(_DWORD*)& byte_5D4594[2618908];
    if (!*(_DWORD*)& byte_5D4594[2618908])
        return result;
    result = *(_DWORD*)& byte_5D4594[2614252];
    if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 276) == 34)
        return result;
    v2 = sub_4281F0((int2*)& byte_5D4594[1062572], (int4*)& byte_587000[136336]);
    if (v2 == 1)
        sub_477690(0);
    v3 = *(_DWORD * *)& byte_5D4594[1062480];
    if (*(_DWORD*)& byte_5D4594[1062480])
    {
        if (sub_415880(*(char**)(**(_DWORD * *)& byte_5D4594[1062480] + 108)) == 2)
        {
            v4 = sub_415840((char*)2);
            result = sub_461600(v4);
            if (result)
            {
            LABEL_11:
                *(_DWORD*)& byte_5D4594[1062492] = result;
                sub_464B70(result);
                result = sub_452D80(895, 100);
            }
            return result;
        }
        v3 = *(_DWORD * *)& byte_5D4594[1062480];
    }
    for (i = 1; i < 27; ++i)
    {
        result = 1 << i;
        if (1 << i != 2 && result & *(_DWORD*)(v1 + 4))
        {
            v6 = sub_415840((char*)(1 << i));
            result = sub_461600(v6);
            if (result)
                goto LABEL_11;
            v3 = *(_DWORD * *)& byte_5D4594[1062480];
        }
    }
    if (v3)
    {
        *(_DWORD*)(*v3 + 128) = v3[1];
        sub_4623B0(**(_DWORD * *)& byte_5D4594[1062480]);
        result = sub_452D80(895, 100);
    }
    return result;
}
// 467323: variable 'v2' is possibly undefined

//----- (004673F0) --------------------------------------------------------
int __cdecl sub_4673F0(int a1, int a2)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1062580] = a1;
    *(_DWORD*)& byte_5D4594[1062584] = a2;
    return result;
}

//----- (00467410) --------------------------------------------------------
int __cdecl sub_467410(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1062540] = a1;
    return result;
}

//----- (00467420) --------------------------------------------------------
char __cdecl sub_467420(char a1)
{
    char result; // al

    result = a1;
    byte_5D4594[1062536] = a1;
    return result;
}

//----- (00467430) --------------------------------------------------------
unsigned __int8 sub_467430()
{
    return byte_5D4594[1062536];
}

//----- (00467440) --------------------------------------------------------
int __cdecl sub_467440(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1062544] = a1;
    return result;
}

//----- (00467450) --------------------------------------------------------
int __cdecl sub_467450(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1062548] = a1;
    return result;
}

//----- (00467470) --------------------------------------------------------
int __cdecl sub_467470(int a1, float a2)
{
    int result; // eax

    result = (unsigned __int8)a1;
    *(float*)& byte_5D4594[4 * (unsigned __int8)a1 + 1063100] = a2;
    return result;
}

//----- (00467490) --------------------------------------------------------
int __cdecl sub_467490(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1062552] = a1;
    return result;
}

//----- (004674A0) --------------------------------------------------------
int sub_4674A0()
{
    return *(_DWORD*)& byte_5D4594[1062552];
}

//----- (004674B0) --------------------------------------------------------
void __cdecl nox_window_set_visible_unk5(int visible)
{
    if (visible)
        nox_window_set_hidden(nox_win_unk5, 0);
    else
        nox_window_set_hidden(nox_win_unk5, 1);
}

//----- (004674E0) --------------------------------------------------------
void __cdecl sub_4674E0(int a1)
{
    if (sub_477600() != 1)
    {
        if (!sub_413A50())
        {
            int result = sub_467520(a1);
            if (result)
            {
                *(_DWORD*)(*(_DWORD*)result + 128) = *((_DWORD*)result + 1);
                sub_465C70(*(_DWORD*)result);
            }
        }
    }
}

//----- (00467520) --------------------------------------------------------
char* __cdecl sub_467520(int a1)
{
    int v1; // esi
    unsigned __int8* v2; // edx
    int v3; // eax
    unsigned __int8* v4; // ecx

    v1 = 0;
    v2 = &byte_5D4594[1050020];
    while (1)
    {
        v3 = 0;
        v4 = v2;
        do
        {
            if (v4[140] && *(_DWORD*)(*(_DWORD*)v4 + 108) == a1)
                return (char*)& byte_5D4594[148 * (v1 + 14 * v3 + 7 * v3) + 1050020];
            ++v3;
            v4 += 3108;
        } while (v3 < 4);
        v2 += 148;
        ++v1;
        if ((int)v2 <= (int)& byte_5D4594[1052980])
            continue;
        break;
    }
    return 0;
}

//----- (00467590) --------------------------------------------------------
int sub_467590()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2618908])
        result = *(char*)(*(_DWORD*)& byte_5D4594[2618908] + 3684);
    else
        result = 1;
    return result;
}

//----- (004675B0) --------------------------------------------------------
int sub_4675B0()
{
    return *(_DWORD*)& byte_5D4594[1049864];
}

//----- (004675C0) --------------------------------------------------------
int __cdecl sub_4675C0(int a1)
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1049864] = a1;
    if (a1 == 5)
        result = sub_465CA0();
    else
        result = sub_462740();
    return result;
}

//----- (004675E0) --------------------------------------------------------
__int16 __cdecl sub_4675E0(int a1, __int16 a2, __int16 a3)
{
    char* v3; // eax
    int v4; // eax

    v3 = sub_461EF0(a1);
    if (v3)
    {
        *(_WORD*)(**(_DWORD * *)v3 + 292) = a2;
        v4 = **(_DWORD * *)v3;
        *(_WORD*)(v4 + 294) = a3;
    }
    else
    {
        LOWORD(v4) = *(_WORD*)& byte_5D4594[1049848];
        if (*(_DWORD*)& byte_5D4594[1049848] && *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) == a1)
        {
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1049848] + 292) = a2;
            LOWORD(v4) = a3;
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1049848] + 294) = a3;
        }
    }
    return v4;
}

//----- (00467650) --------------------------------------------------------
int sub_467650()
{
    int result; // eax

    sub_462740();
    *(_DWORD*)& byte_5D4594[1049864] = 6;
    sub_477610(8);
    result = sub_467C80();
    if (!result)
        result = sub_467BB0();
    return result;
}

//----- (00467680) --------------------------------------------------------
void sub_467680()
{
    if (*(_DWORD*)& byte_5D4594[1049864] == 6)
        * (_DWORD*)& byte_5D4594[1049864] = 0;
}

//----- (004676A0) --------------------------------------------------------
int sub_4676A0()
{
    return *(_DWORD*)& byte_5D4594[1062452];
}

//----- (004676B0) --------------------------------------------------------
char* sub_4676B0()
{
    return (char*)& byte_587000[136384];
}

//----- (004676C0) --------------------------------------------------------
char* sub_4676C0()
{
    return (char*)& byte_587000[136400];
}

//----- (004676D0) --------------------------------------------------------
int __cdecl sub_4676D0(int a1)
{
    char* v1; // eax
    int result; // eax

    v1 = sub_461EF0(a1);
    if (v1)
        return **(_DWORD * *)v1;
    result = *(_DWORD*)& byte_5D4594[1049848];
    if (!*(_DWORD*)& byte_5D4594[1049848] || *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) != a1)
        result = 0;
    return result;
}

//----- (00467700) --------------------------------------------------------
int __cdecl sub_467700(int a1)
{
    char* v1; // eax

    v1 = sub_461EF0(a1);
    if (v1)
        return *(unsigned __int8*)(*(_DWORD*)v1 + 140);
    if (*(_DWORD*)& byte_5D4594[1049848] && *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128) == a1)
        return 1;
    return 0;
}

//----- (00467740) --------------------------------------------------------
int __cdecl sub_467740(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1062488] = a1;
    return result;
}

//----- (00467750) --------------------------------------------------------
int __cdecl sub_467750(int a1, char a2)
{
    char* v2; // eax
    int v3; // eax
    wchar_t* v5; // eax
    int* v6; // eax

    if (!a1)
    {
        if (*(_DWORD*)& byte_5D4594[1062480])
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 136) = 0;
            *(_DWORD*)& byte_5D4594[1062480] = 0;
        }
    LABEL_8:
        if (a2)
        {
            if (a2 != 1)
                return 0;
            v5 = loadString_sub_40F1D0((char*)& byte_587000[140892], 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 5379);
            sub_445490(v5);
            if (!*(_DWORD*)& byte_5D4594[1062484])
                return 0;
            v6 = (int*)sub_461EF0(*(int*)& byte_5D4594[1062484]);
            if (v6)
            {
                sub_461550(*v6);
                return 0;
            }
        }
        *(_DWORD*)& byte_5D4594[1062484] = 0;
        return 0;
    }
    v2 = sub_461EF0(a1);
    if (!v2)
        goto LABEL_8;
    if (*(_DWORD*)& byte_5D4594[1062480])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 136) = 0;
    v3 = *(_DWORD*)v2;
    *(_DWORD*)& byte_5D4594[1062480] = v3;
    *(_DWORD*)(v3 + 136) = 1;
    return 1;
}

//----- (00467810) --------------------------------------------------------
int __cdecl sub_467810(int a1, int a2)
{
    int result; // eax

    if (a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20)
        result = 0;
    else
        result = byte_5D4594[148 * (a2 + 14 * a1 + 7 * a1) + 1050160];
    return result;
}

//----- (00467850) --------------------------------------------------------
int __cdecl sub_467850(int a1)
{
    char* v1; // eax
    int result; // eax

    v1 = sub_467520(a1);
    if (v1)
        result = (unsigned __int8)v1[140];
    else
        result = 0;
    return result;
}

//----- (00467870) --------------------------------------------------------
char* __cdecl sub_467870(int a1, int a2)
{
    char* result; // eax

    if (a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20)
        result = 0;
    else
        result = (char*)& byte_5D4594[148 * (a2 + 14 * a1 + 7 * a1) + 1050024];
    return result;
}

//----- (004678B0) --------------------------------------------------------
int sub_4678B0()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[1062480])
        result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1062480] + 4);
    else
        result = 0;
    return result;
}

//----- (004678C0) --------------------------------------------------------
int sub_4678C0()
{
    return *(_DWORD*)& byte_5D4594[1062488];
}

//----- (004678D0) --------------------------------------------------------
int sub_4678D0()
{
    int v0; // edi
    int v1; // esi
    int v2; // eax
    int v3; // eax
    int result; // eax
    char* v5; // eax

    v0 = *(_DWORD*)& byte_5D4594[2618908];
    if (!*(_DWORD*)& byte_5D4594[2618908])
        goto LABEL_7;
    v1 = 1;
    while (1)
    {
        if (1 << v1 != 2)
        {
            if ((1 << v1) & *(_DWORD*)(v0 + 4))
            {
                v2 = sub_415840((char*)(1 << v1));
                v3 = sub_461600(v2);
                if (v3)
                    break;
            }
        }
        if (++v1 >= 27)
            goto LABEL_7;
    }
    v5 = sub_461EF0(*(_DWORD*)(v3 + 128));
    if (v5)
        result = **(_DWORD * *)v5;
    else
        LABEL_7:
    result = 0;
    return result;
}

//----- (00467930) --------------------------------------------------------
char* __cdecl sub_467930(int a1, int a2, int a3)
{
    char* result; // eax
    int v4; // ecx

    result = (char*)a1;
    if (a1)
    {
        result = sub_461EF0(a1);
        if (result)
        {
            v4 = **(_DWORD * *)result;
            *(_WORD*)(v4 + 448) = a2;
            *(_WORD*)(v4 + 450) = a3;
            result = *(char**)result;
            if (*((_DWORD*)result + 33) == 1)
                result = (char*)sub_470D90(a2, a3);
        }
    }
    return result;
}

//----- (00467980) --------------------------------------------------------
int sub_467980()
{
    unsigned __int8* v0; // ebp
    unsigned __int8* v1; // esi
    int v2; // edi

    v0 = &byte_5D4594[1050020];
    do
    {
        v1 = v0;
        v2 = 4;
        do
        {
            if (*(_DWORD*)v1)
            {
                sub_45A4B0(*(_QWORD * *)v1);
                *(_DWORD*)v1 = 0;
            }
            v1[140] = 0;
            *((_DWORD*)v1 + 33) = 0;
            *((_DWORD*)v1 + 34) = 0;
            v1 += 3108;
            --v2;
        } while (v2);
        v0 += 148;
    } while ((int)v0 <= (int)& byte_5D4594[1052980]);
    sub_462740();
    *(_DWORD*)& byte_5D4594[1049864] = 0;
    sub_461550(0);
    *(_DWORD*)& byte_5D4594[1062488] = 0;
    memset(&byte_5D4594[1049872], 0, 0x24u);
    *(_DWORD*)& byte_5D4594[1062492] = 0;
    *(_DWORD*)& byte_5D4594[1062496] = 0;
    byte_5D4594[1062536] = 0;
    *(_DWORD*)& byte_5D4594[1062540] = 0;
    *(_DWORD*)& byte_5D4594[1062544] = 0;
    *(_DWORD*)& byte_5D4594[1062548] = 0;
    *(_DWORD*)& byte_5D4594[1062552] = 0;
    sub_472310();
    *(_DWORD*)& byte_587000[136184] = -225;
    byte_5D4594[1049868] = 0;
    byte_5D4594[1049869] = 0;
    *(_DWORD*)& byte_5D4594[1062516] = 0;
    *(_DWORD*)& byte_5D4594[1062520] = 0;
    *(_DWORD*)& byte_5D4594[1062512] = 0;
    nox_window_call_field_94(*(int*)& byte_5D4594[1062508], 16395, 0, 850);
    nox_window_call_field_94(
        *(int*)& byte_5D4594[1062508],
        16394,
        *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4) - *(_DWORD*)& byte_5D4594[1062512],
        0);
    sub_46AE60(*(int*)& byte_5D4594[1062528], 0);
    sub_46AEC0(*(int*)& byte_5D4594[1062528], *(int*)& byte_5D4594[1049976]);
    sub_46B080(*(_DWORD * *)& byte_5D4594[1062528], 9105);
    byte_5D4594[1049870] = 0;
    sub_46AE60(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049992]);
    sub_46AEC0(*(int*)& byte_5D4594[1062524], *(int*)& byte_5D4594[1049996]);
    sub_46B080(*(_DWORD * *)& byte_5D4594[1062524], 9107);
    return nox_window_set_hidden(*(int*)& byte_5D4594[1062468], 0);
}

//----- (00467B00) --------------------------------------------------------
int __cdecl sub_467B00(int a1, int a2)
{
    int v2; // ebx
    unsigned __int8* v3; // ebp
    int i; // esi
    int v5; // edi
    int v6; // eax
    int v8; // [esp+10h] [ebp-8h]
    unsigned __int8* v9; // [esp+14h] [ebp-4h]

    v2 = 0;
    v8 = 0;
    v9 = &byte_5D4594[1050020];
    do
    {
        v3 = v9;
        for (i = 0; i < 4; ++i)
        {
            v5 = sub_467810(i, v2);
            if (!v5)
                goto LABEL_15;
            if (*(_DWORD*)(*(_DWORD*)v3 + 108) == a1)
            {
                v6 = 31;
                if (*(_BYTE*)(*(_DWORD*)v3 + 112) & 0x10)
                    v6 = sub_40A5C0(6144) ? 9 : 3;
                if (!(*(_DWORD*)(*(_DWORD*)v3 + 112) & 0x4000000) && a2 + v5 <= v6)
                    LABEL_15:
                ++v8;
            }
            v3 += 3108;
        }
        ++v2;
        v9 += 148;
    } while ((int)v9 < (int)& byte_5D4594[1052980]);
    return v8;
}

//----- (00467BB0) --------------------------------------------------------
int sub_467BB0()
{
    int result; // eax

    result = sub_446360();
    if (!result)
    {
        result = sub_4AE3D0();
        if (!result)
        {
            result = sub_477600();
            if (!result)
            {
                result = sub_4372B0();
                if (!result)
                {
                    result = sub_57AF20();
                    if (!result)
                    {
                        if (byte_5D4594[1049868] == 3 || !byte_5D4594[1049868])
                        {
                            byte_5D4594[1049868] = 1;
                            sub_452D80(789, 100);
                        }
                        result = *(_DWORD*)& byte_5D4594[1062516];
                        *(_DWORD*)& byte_5D4594[1062512] = *(_DWORD*)& byte_5D4594[1062516];
                    }
                }
            }
        }
    }
    return result;
}

//----- (00467C10) --------------------------------------------------------
int sub_467C10()
{
    if (*(_DWORD*)& byte_5D4594[1049864] == 6)
        return 1;
    if (!sub_467C80())
        return 0;
    byte_5D4594[1049868] = 3;
    sub_452D80(790, 100);
    if (*(_DWORD*)& byte_5D4594[1049864] == 5)
        sub_462740();
    sub_467CD0();
    return 1;
}

//----- (00467C60) --------------------------------------------------------
int sub_467C60()
{
    int result; // eax

    if (sub_467C80())
        result = sub_467C10();
    else
        result = sub_467BB0();
    return result;
}

//----- (00467C80) --------------------------------------------------------
BOOL sub_467C80()
{
    return byte_5D4594[1049868] == 1 || byte_5D4594[1049868] == 2;
}

//----- (00467CA0) --------------------------------------------------------
int sub_467CA0()
{
    int result; // eax

    result = sub_467C80();
    if (!result)
    {
        *(_DWORD*)& byte_5D4594[1062516] = 0;
        result = *(_DWORD*)& byte_5D4594[1062508];
        if (*(_DWORD*)& byte_5D4594[1062508])
            result = nox_window_call_field_94(
                *(int*)& byte_5D4594[1062508],
                16394,
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1062508] + 32) + 4),
                0);
    }
    return result;
}

//----- (00467CD0) --------------------------------------------------------
int sub_467CD0()
{
    int v0; // esi
    char* v1; // eax
    char* v2; // edi
    unsigned __int8* v3; // ebx
    int v4; // eax
    int v5; // eax
    int v6; // eax

    v0 = 0;
    if (*(_DWORD*)& byte_5D4594[1049848])
    {
        if (!*(_DWORD*)& byte_5D4594[1049856]
            && !sub_4649B0(*(int*)& byte_5D4594[1049848], *(int*)& byte_5D4594[1049796], *(int*)& byte_5D4594[1049800]))
        {
            sub_461660(
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 108),
                (const void*)(*(_DWORD*)& byte_5D4594[1049848] + 432));
            v1 = sub_461EF0(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128));
            v2 = v1;
            if (v1)
            {
                v3 = &byte_5D4594[1049872];
                *(_DWORD*)(*(_DWORD*)v1 + 132) = 0;
                do
                {
                    v4 = *(_DWORD*)v3;
                    if (*(_DWORD*)v3)
                    {
                        while (*(_DWORD*)(v4 + 128) != *(_DWORD*)(*(_DWORD*)& byte_5D4594[1049848] + 128))
                        {
                            v4 = *(_DWORD*)(v4 + 368);
                            if (!v4)
                                goto LABEL_12;
                        }
                        *(_DWORD*)(*(_DWORD*)v2 + 132) = 1;
                        if (*(_DWORD*)(*(_DWORD*)v2 + 136))
                        {
                            sub_461550(0);
                            *(_DWORD*)(*(_DWORD*)v2 + 136) = 0;
                        }
                    }
                LABEL_12:
                    v3 += 4;
                } while ((int)v3 < (int)& byte_5D4594[1049908]);
            }
        }
        *(_DWORD*)& byte_5D4594[1049848] = 0;
        *(_DWORD*)& byte_5D4594[1049856] = 0;
        sub_4776A0();
        v0 = 1;
    }
    v5 = sub_46AE00();
    if (nox_window_is_child(*(int*)& byte_5D4594[1062452], v5) == 1)
    {
        v6 = sub_46AE00();
        sub_46ADE0(v6);
    }
    return v0;
}

//----- (00467DF0) --------------------------------------------------------
int __cdecl sub_467DF0(int a1)
{
    int result; // eax
    int i; // edi
    int j; // esi
    int v4[3]; // [esp+0h] [ebp-Ch]

    v4[0] = 25;
    v4[1] = 25;
    v4[2] = 25;
    sub_4460A0(0);
    if (sub_47A260() == 1)
        sub_47A1F0();
    if (sub_478030() == 1)
        sub_479280();
    sub_45D810();
    sub_4B8220();
    sub_49A2F0();
    sub_4573B0();
    if (!sub_40A5C0(1))
    {
        sub_469B90(v4);
        sub_4349C0(v4);
        sub_421B10();
    }
    sub_49C4B0();
    sub_49C4F0();
    sub_49A630();
    sub_49BBB0();
    sub_431510();
    sub_45A5E0(a1);
    result = sub_40A5C0(1);
    if (!result)
    {
        sub_410160();
        for (i = 0; i < 5632; i += 44)
        {
            for (j = 0; j < 512; j += 4)
            {
                *(_BYTE*)(*(_DWORD*)(j + *(_DWORD*)& byte_5D4594[2650668]) + i) = 0;
                *(_DWORD*)(*(_DWORD*)(j + *(_DWORD*)& byte_5D4594[2650668]) + i + 4) = 255;
                *(_DWORD*)(*(_DWORD*)(j + *(_DWORD*)& byte_5D4594[2650668]) + i + 24) = 255;
                sub_422200(*(_DWORD*)(j + *(_DWORD*)& byte_5D4594[2650668]) + i + 4);
                result = sub_422200(*(_DWORD*)(j + *(_DWORD*)& byte_5D4594[2650668]) + i + 24);
            }
        }
    }
    return result;
}
// 49A2F0: using guessed type int __cdecl sub_49A2F0(_DWORD, _DWORD, _DWORD);

//----- (00467F30) --------------------------------------------------------
int sub_467F30()
{
    *(_DWORD*)& byte_5D4594[1064192] = nox_new_window_from_file("wolProg.wnd", sub_467FC0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1064192], sub_467F70, 0, 0);
    sub_46A8A0();
    sub_4680B0();
    return 1;
}

//----- (00467F70) --------------------------------------------------------
int __cdecl sub_467F70(int a1, int a2, int a3, int a4)
{
    if (a2 != 21)
        return 0;
    if (a3 != 1)
        return 0;
    if (a4 == 2)
    {
        sub_452D80(231, 100);
        if (*(_DWORD*)& byte_5D4594[815132])
            sub_4207F0(1);
    }
    return 1;
}

//----- (00467FC0) --------------------------------------------------------
int __cdecl sub_467FC0(int a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v4; // eax

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        result = 1;
    }
    else if (a2 == 16391)
    {
        v4 = sub_46B0A0(a3);
        if (v4 >= 1806 && v4 <= 1807)
            sub_468020();
        sub_452D80(921, 100);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00468020) --------------------------------------------------------
void sub_468020()
{
    sub_46B0C0(0, 1700);
    if (*(_DWORD*)& byte_5D4594[815132])
    {
        sub_468060();
        sub_4207F0(1);
        sub_44A560();
        sub_40E0A0();
    }
}

//----- (00468060) --------------------------------------------------------
int sub_468060()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1064192];
    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1064192]);
        *(_DWORD*)& byte_5D4594[1064192] = 0;
    }
    return result;
}

//----- (00468080) --------------------------------------------------------
int sub_468080()
{
    int result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD*)& byte_5D4594[1064192];
    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1802);
        nox_window_set_hidden((int)v1, 0);
        result = v1[9];
        LOBYTE(result) = result | 4;
        v1[9] = result;
    }
    return result;
}

//----- (004680B0) --------------------------------------------------------
int sub_4680B0()
{
    int result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD*)& byte_5D4594[1064192];
    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1801);
        nox_window_set_hidden((int)v1, 0);
        result = v1[9];
        LOBYTE(result) = result | 4;
        v1[9] = result;
    }
    return result;
}

//----- (004680E0) --------------------------------------------------------
int sub_4680E0()
{
    int result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD*)& byte_5D4594[1064192];
    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1803);
        nox_window_set_hidden((int)v1, 0);
        result = v1[9];
        LOBYTE(result) = result | 4;
        v1[9] = result;
    }
    return result;
}

//----- (00468110) --------------------------------------------------------
int sub_468110()
{
    int result; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // esi
    wchar_t* v3; // eax

    result = *(_DWORD*)& byte_5D4594[1064192];
    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1804);
        nox_window_set_hidden((int)v1, 0);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1805);
        v3 = loadString_sub_40F1D0((char*)& byte_587000[140968], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolprog.c", 192);
        result = nox_window_call_field_94((int)v2, 16385, (int)v3, 0);
    }
    return result;
}

//----- (00468170) --------------------------------------------------------
int sub_468170()
{
    int result; // eax
    _DWORD* v1; // esi
    int v2; // eax
    wchar_t* v3; // eax
    _DWORD* v4; // eax
    int v5; // [esp+4h] [ebp-10h]
    int v6; // [esp+8h] [ebp-Ch]
    int v7; // [esp+Ch] [ebp-8h]
    int v8; // [esp+10h] [ebp-4h]

    result = *(_DWORD*)& byte_5D4594[1064192];
    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v6 = 0;
        v5 = 0;
        v8 = 0;
        v7 = 0;
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1804);
        sub_41E590(&v6, &v5, &v8, &v7);
        if (v6)
            v2 = 100 * v6 / v5;
        else
            v2 = 0;
        nox_window_call_field_94((int)v1, 16416, v2, 0);
        v3 = loadString_sub_40F1D0((char*)& byte_587000[141036], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolprog.c", 226);
        nox_swprintf((wchar_t*)& byte_5D4594[1063680], v3, v6, v5, v8 / 3600, v8 / 60, v8 % 60, v7 / 3600, v7 / 60, v7 % 60);
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1805);
        result = nox_window_call_field_94((int)v4, 16385, (int)& byte_5D4594[1063680], 0);
    }
    return result;
}

//----- (004682B0) --------------------------------------------------------
int sub_4682B0()
{
    _DWORD* v0; // esi
    wchar_t* v1; // eax
    int result; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax

    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1805);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[141100], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolprog.c", 250);
        if (v1)
            nox_window_call_field_94((int)v0, 16385, (int)v1, 0);
    }
    result = sub_41E540();
    if (!result)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1806);
        nox_window_set_hidden((int)v3, 1);
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1807);
        nox_window_set_hidden((int)v4, 0);
        sub_43DDD0(0);
        result = sub_43DE60();
    }
    return result;
}

//----- (00468340) --------------------------------------------------------
int sub_468340()
{
    _DWORD* v0; // esi
    wchar_t* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax

    if (*(_DWORD*)& byte_5D4594[1064192])
    {
        v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1805);
        v1 = sub_41E5D0();
        if (v1)
            nox_window_call_field_94((int)v0, 16385, (int)v1, 0);
    }
    v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1806);
    nox_window_set_hidden((int)v2, 1);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064192], 1807);
    return nox_window_set_hidden((int)v3, 0);
}

//----- (004683B0) --------------------------------------------------------
int sub_4683B0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax

    nox_set_draw_unk1(sub_41E210);
    *(_DWORD*)& byte_5D4594[1064816] = nox_new_window_from_file("wolreg.wnd", sub_4685D0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1064816], sub_468480, 0, 0);
    *(_DWORD*)& byte_5D4594[1064820] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1755);
    *(_DWORD*)& byte_5D4594[1064824] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1756);
    *(_DWORD*)& byte_5D4594[1064828] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1754);
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1766);
    v0[9] |= 4u;
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1767);
    v1[9] |= 4u;
    *(_DWORD*)& byte_5D4594[1064296] = 0;
    sub_46ABB0(*(int*)& byte_5D4594[1064816], 1);
    return 1;
}

//----- (00468480) --------------------------------------------------------
int __cdecl sub_468480(int a1, int a2, int a3, int a4)
{
    if (a2 != 21)
        return 0;
    if (a3 != 1)
        return 0;
    if (a4 == 2)
    {
        sub_452D80(231, 100);
        sub_4684C0();
    }
    return 1;
}

//----- (004684C0) --------------------------------------------------------
int sub_4684C0()
{
    _DWORD* v0; // esi
    int result; // eax

    v0 = sub_46B0C0(0, 1700);
    result = *(_DWORD*)& byte_5D4594[1064296];
    switch (*(_DWORD*)& byte_5D4594[1064296])
    {
    case 0:
        sub_41E300(5);
        sub_4207F0(1);
        sub_46ABB0((int)v0, 1);
        sub_4A1BE0(1);
        result = sub_4A1A40(0);
        break;
    case 1:
        *(_DWORD*)& byte_5D4594[1064296] = 0;
        nox_window_set_hidden(*(int*)& byte_5D4594[1064824], 1);
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1064820], 0);
        break;
    case 2:
        *(_DWORD*)& byte_5D4594[1064296] = 0;
        nox_window_set_hidden(*(int*)& byte_5D4594[1064828], 1);
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1064820], 0);
        break;
    case 3:
        *(_DWORD*)& byte_5D4594[1064296] = 1;
        nox_window_set_hidden(*(int*)& byte_5D4594[1064828], 1);
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1064824], 0);
        break;
    case 4:
        sub_41E300(5);
        sub_4207F0(1);
        sub_46ABB0((int)v0, 1);
        result = sub_4A1BE0(1);
        break;
    default:
        return result;
    }
    return result;
}

//----- (004685D0) --------------------------------------------------------
int __cdecl sub_4685D0(int a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v4; // esi
    int v5; // eax
    int v6; // [esp+0h] [ebp-2FCh]
    int v7; // [esp+4h] [ebp-2F8h]
    int v8; // [esp+8h] [ebp-2F4h]
    char v9[80]; // [esp+Ch] [ebp-2F0h]
    char v10[80]; // [esp+5Ch] [ebp-2A0h]
    char v11[80]; // [esp+ACh] [ebp-250h]
    wchar_t File[256]; // [esp+FCh] [ebp-200h]

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        return 1;
    }
    if (a2 != 16391)
    {
        if (a2 == 16415)
            sub_46B0A0(a3);
        return 0;
    }
    v4 = sub_46B0A0(a3);
    sub_452D80(921, 100);
    if (v4 != 1752)
    {
        if (v4 == 1753)
        {
            sub_4684C0();
            return 1;
        }
        return 1;
    }
    switch (*(_DWORD*)& byte_5D4594[1064296])
    {
    case 0:
        if (sub_468BB0(&v7, &v6, &v8, File))
        {
            *(_DWORD*)& byte_5D4594[1064300] = 0;
            sub_40E020(v7, v6, v8, (int)& byte_5D4594[1064196]);
            sub_46ABB0(*(int*)& byte_5D4594[1064816], 0);
        }
        else
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[1064820], 1);
            sub_468840(File);
            *(_DWORD*)& byte_5D4594[1064296] = 2;
        }
        result = 1;
        break;
    case 1:
        if (sub_468890(v10, v11, v9, &v6, &v7, File))
        {
            sub_40DFE0((int)v10, (int)v11, (int)& byte_5D4594[1064196], (int)v9, (unsigned __int8)v6, (unsigned __int8)v7);
            sub_46ABB0(*(int*)& byte_5D4594[1064816], 0);
        }
        else
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[1064824], 1);
            sub_468840(File);
            *(_DWORD*)& byte_5D4594[1064296] = 3;
        }
        result = 1;
        break;
    case 4:
        v5 = sub_4200F0();
        nox_sprintf((char*)File, "http://apiregister.westwood.com/consent_form/index_%d.html", v5);
        ShellExecuteA(0, 0, (LPCSTR)File, 0, (LPCSTR)& byte_587000[141188], 3);
        result = 1;
        break;
    case 5:
        sub_41E300(5);
        sub_4207F0(1);
        sub_44A560();
        result = 1;
        break;
    default:
        return 1;
    }
    return result;
}

//----- (00468840) --------------------------------------------------------
int __cdecl sub_468840(wchar_t* a1)
{
    _DWORD* v1; // eax

    nox_wcscpy((wchar_t*)& byte_5D4594[1064304], a1);
    nox_window_set_hidden(*(int*)& byte_5D4594[1064828], 0);
    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1768);
    return nox_window_call_field_94((int)v1, 16385, (int)& byte_5D4594[1064304], 6);
}

//----- (00468890) --------------------------------------------------------
int __cdecl sub_468890(char* a1, char* a2, char* a3, _BYTE* a4, _BYTE* a5, wchar_t* a6)
{
    _DWORD* v6; // eax
    int v7; // eax
    _DWORD* v8; // eax
    int v9; // eax
    _DWORD* v10; // eax
    int v11; // eax
    _DWORD* v12; // eax
    int v13; // eax
    char v14; // al
    wchar_t* v15; // eax
    int result; // eax
    wchar_t* v17; // eax
    wchar_t* v18; // eax
    wchar_t* v19; // eax
    wchar_t* v20; // eax
    wchar_t* v21; // [esp-4h] [ebp-60h]
    wchar_t* v22; // [esp-4h] [ebp-60h]
    wchar_t* v23; // [esp-4h] [ebp-60h]
    wchar_t* v24; // [esp-4h] [ebp-60h]
    wchar_t* v25; // [esp-4h] [ebp-60h]
    char v26[80]; // [esp+Ch] [ebp-50h]

    *a4 = (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1766)[9] >> 2) & 1;
    *a5 = (sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1767)[9] >> 2) & 1;
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1762);
    v7 = nox_window_call_field_94((int)v6, 16413, 0, 0);
    nox_sprintf(a1, "%S", v7);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1763);
    v9 = nox_window_call_field_94((int)v8, 16413, 0, 0);
    nox_sprintf(a2, "%S", v9);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1764);
    v11 = nox_window_call_field_94((int)v10, 16413, 0, 0);
    nox_sprintf(v26, "%S", v11);
    v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1765);
    v13 = nox_window_call_field_94((int)v12, 16413, 0, 0);
    nox_sprintf(a3, "%S", v13);
    v14 = *a1;
    if (*a1)
    {
        if ((unsigned __int8)v14 < 0x31u || (unsigned __int8)v14 > 0x39u)
        {
            if (strlen(a2) == 8)
            {
                if (!strcmp(a2, v26))
                {
                    if (!*(_DWORD*)& byte_5D4594[1064300] || *a3)
                    {
                        result = 1;
                    }
                    else
                    {
                        v25 = loadString_sub_40F1D0((char*)& byte_587000[141772], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 176);
                        v20 = loadString_sub_40F1D0((char*)& byte_587000[141828], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 175);
                        nox_swprintf(a6, L"%s %s", v20, v25);
                        result = 0;
                    }
                }
                else
                {
                    v24 = loadString_sub_40F1D0((char*)& byte_587000[141640], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 166);
                    v19 = loadString_sub_40F1D0((char*)& byte_587000[141696], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 165);
                    nox_swprintf(a6, L"%s %s", v19, v24);
                    result = 0;
                }
            }
            else
            {
                v23 = loadString_sub_40F1D0((char*)& byte_587000[141508], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 158);
                v18 = loadString_sub_40F1D0((char*)& byte_587000[141564], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 157);
                nox_swprintf(a6, L"%s %s", v18, v23);
                result = 0;
            }
        }
        else
        {
            v22 = loadString_sub_40F1D0((char*)& byte_587000[141376], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 150);
            v17 = loadString_sub_40F1D0((char*)& byte_587000[141432], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 149);
            nox_swprintf(a6, L"%s %s", v17, v22);
            result = 0;
        }
    }
    else
    {
        v21 = loadString_sub_40F1D0((char*)& byte_587000[141252], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 142);
        v15 = loadString_sub_40F1D0((char*)& byte_587000[141308], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 141);
        nox_swprintf(a6, L"%s %s", v15, v21);
        result = 0;
    }
    return result;
}

//----- (00468BB0) --------------------------------------------------------
int __cdecl sub_468BB0(int* a1, int* a2, int* a3, wchar_t* a4)
{
    _DWORD* v4; // eax
    const wchar_t* v5; // esi
    _DWORD* v6; // eax
    const wchar_t* v7; // edi
    _DWORD* v8; // eax
    const wchar_t* v9; // ebx
    _DWORD* v10; // eax
    int v11; // eax
    wchar_t* v12; // eax
    int result; // eax
    wchar_t* v14; // eax
    wchar_t* v15; // eax
    wchar_t* v16; // [esp-4h] [ebp-14h]
    wchar_t* v17; // [esp-4h] [ebp-14h]
    wchar_t* v18; // [esp-4h] [ebp-14h]

    *a4 = 0;
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1758);
    v5 = (const wchar_t*)nox_window_call_field_94((int)v4, 16413, 0, 0);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1759);
    v7 = (const wchar_t*)nox_window_call_field_94((int)v6, 16413, 0, 0);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1760);
    v9 = (const wchar_t*)nox_window_call_field_94((int)v8, 16413, 0, 0);
    v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1761);
    v11 = nox_window_call_field_94((int)v10, 16413, 0, 0);
    nox_sprintf((char*)& byte_5D4594[1064196], "%S", v11);
    if (v5 && v7 && nox_wcslen(v9) == 4)
    {
        if (byte_5D4594[1064196])
        {
            *a1 = nox_wcstol(v5, 0, 10);
            *a2 = nox_wcstol(v7, 0, 10);
            *a3 = nox_wcstol(v9, 0, 10);
            if ((int)* a1 < 1 || (int)* a1 > 12 || (int)* a2 < 1 || (int)* a2 > 31)
            {
                v17 = loadString_sub_40F1D0((char*)& byte_587000[142152], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 228);
                v14 = loadString_sub_40F1D0((char*)& byte_587000[142208], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 227);
                nox_swprintf(a4, L"%s %s", v14, v17);
                result = 0;
            }
            else
            {
                result = 1;
            }
        }
        else
        {
            v16 = loadString_sub_40F1D0((char*)& byte_587000[142028], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 216);
            v12 = loadString_sub_40F1D0((char*)& byte_587000[142084], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 215);
            nox_swprintf(a4, L"%s %s", v12, v16);
            result = 0;
        }
    }
    else
    {
        v18 = loadString_sub_40F1D0((char*)& byte_587000[141908], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 209);
        v15 = loadString_sub_40F1D0((char*)& byte_587000[141964], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 208);
        nox_swprintf(a4, L"%s %s", v15, v18);
        result = 0;
    }
    return result;
}

//----- (00468DC0) --------------------------------------------------------
int sub_468DC0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1064816];
    if (*(_DWORD*)& byte_5D4594[1064816])
    {
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1064816]);
        *(_DWORD*)& byte_5D4594[1064816] = 0;
        *(_DWORD*)& byte_5D4594[1064820] = 0;
        *(_DWORD*)& byte_5D4594[1064824] = 0;
        *(_DWORD*)& byte_5D4594[1064828] = 0;
    }
    return result;
}

//----- (00468DF0) --------------------------------------------------------
int __cdecl sub_468DF0(wchar_t* a1)
{
    sub_46ABB0(*(int*)& byte_5D4594[1064816], 1);
    if (*(_DWORD*)& byte_5D4594[1064296])
    {
        if (*(_DWORD*)& byte_5D4594[1064296] == 1)
        {
            *(_DWORD*)& byte_5D4594[1064296] = 3;
            nox_window_set_hidden(*(int*)& byte_5D4594[1064824], 1);
            return sub_468840(a1);
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1064296] = 2;
        nox_window_set_hidden(*(int*)& byte_5D4594[1064820], 1);
    }
    return sub_468840(a1);
}

//----- (00468E60) --------------------------------------------------------
int __cdecl sub_468E60(int a1)
{
    int result; // eax
    _DWORD* v2; // esi
    _DWORD* v3; // eax

    sub_46ABB0(*(int*)& byte_5D4594[1064816], 1);
    result = *(_DWORD*)& byte_5D4594[1064296];
    if (*(_DWORD*)& byte_5D4594[1064296])
    {
        if (*(_DWORD*)& byte_5D4594[1064296] == 1)
        {
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1753);
            nox_window_set_hidden((int)v3, 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[1064824], 1);
            result = sub_468840((wchar_t*)& byte_5D4594[2660140]);
            *(_DWORD*)& byte_5D4594[1064296] = 5;
        }
    }
    else
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064816], 1765);
        *(_DWORD*)& byte_5D4594[1064300] = a1;
        *(_DWORD*)& byte_5D4594[1064296] = 1;
        nox_window_set_hidden(*(int*)& byte_5D4594[1064820], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1064824], 0);
        if (*(_DWORD*)& byte_5D4594[1064300])
            result = nox_window_set_hidden((int)v2, 0);
        else
            result = nox_window_set_hidden((int)v2, 1);
    }
    return result;
}

//----- (00468F30) --------------------------------------------------------
int sub_468F30()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[142272], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolreg.c", 472);
    sub_468840(v0);
    *(_DWORD*)& byte_5D4594[1064296] = 4;
    nox_window_set_hidden(*(int*)& byte_5D4594[1064820], 1);
    return sub_46ABB0(*(int*)& byte_5D4594[1064816], 1);
}

//----- (00468F80) --------------------------------------------------------
void __cdecl sub_468F80(int a1)
{
    _DWORD* v1; // esi
    int v2; // ecx
    unsigned __int8* v3; // edi
    bool v4; // cc
    int v5; // ecx
    int v6; // eax
    int v7; // edx
    int v8; // edx
    int v9; // ecx
    unsigned __int8* v10; // edi
    int v11; // eax
    int v12; // ebx
    int v13; // edx
    int v14; // eax
    int v15; // ecx
    int v16; // edx
    int4 v17; // [esp+Ch] [ebp-24h]
    int v18; // [esp+1Ch] [ebp-14h]
    int v19; // [esp+20h] [ebp-10h]
    int v20; // [esp+24h] [ebp-Ch]
    int v21; // [esp+28h] [ebp-8h]
    int v22; // [esp+2Ch] [ebp-4h]

    v1 = (_DWORD*)a1;
    *(_DWORD*)& byte_5D4594[2650676] = 46 * ((*(_DWORD*)(a1 + 16) + 11) / 46 - 1) - 11;
    *(_DWORD*)& byte_5D4594[2650680] = 46 * ((*(_DWORD*)(a1 + 20) + 11) / 46) - 57;
    if (byte_5D4594[2650637] & 8)
    {
        v2 = 2464;
        v3 = &byte_5D4594[2618924];
        do
        {
            *(_DWORD*)v3 = 16711680;
            *((_DWORD*)v3 + 1) = 16711680;
            *((_DWORD*)v3 + 2) = 16711680;
            *((_DWORD*)v3 + 3) = 16711680;
            *((_DWORD*)v3 + 4) = 16711680;
            *((_DWORD*)v3 + 5) = 16711680;
            *((_DWORD*)v3 + 6) = 16711680;
            *((_DWORD*)v3 + 7) = 16711680;
            *((_DWORD*)v3 + 8) = 16711680;
            *((_DWORD*)v3 + 9) = 16711680;
            *((_DWORD*)v3 + 10) = 16711680;
            *((_DWORD*)v3 + 11) = 16711680;
            *((_DWORD*)v3 + 12) = 16711680;
            *((_DWORD*)v3 + 13) = 16711680;
            *((_DWORD*)v3 + 14) = 16711680;
            *((_DWORD*)v3 + 15) = 16711680;
            *((_DWORD*)v3 + 16) = 16711680;
            *((_DWORD*)v3 + 17) = 16711680;
            *((_DWORD*)v3 + 18) = 16711680;
            *((_DWORD*)v3 + 19) = 16711680;
            *((_DWORD*)v3 + 20) = 16711680;
            v3 += 84;
            v4 = v2 <= 7;
            v2 -= 7;
        } while (!v4);
    }
    else
    {
        sub_434A10(&a1, &v22, &v21);
        if (sub_57AF20())
        {
            v5 = 50;
            v6 = 50;
            v7 = 50;
            v22 = 50;
            v21 = 50;
            a1 = 50;
        }
        else
        {
            v6 = v21;
            v5 = v22;
            v7 = a1;
        }
        v8 = v7 << 16;
        v20 = v6 << 16;
        v19 = v5 << 16;
        v18 = v8;
        v9 = 2464;
        v10 = &byte_5D4594[2618924];
        v11 = v8;
        v12 = v19;
        v13 = v20;
        do
        {
            *(_DWORD*)v10 = v11;
            *((_DWORD*)v10 + 1) = v12;
            *((_DWORD*)v10 + 2) = v13;
            *((_DWORD*)v10 + 3) = v11;
            *((_DWORD*)v10 + 4) = v12;
            *((_DWORD*)v10 + 5) = v13;
            *((_DWORD*)v10 + 6) = v11;
            *((_DWORD*)v10 + 7) = v12;
            *((_DWORD*)v10 + 8) = v13;
            *((_DWORD*)v10 + 9) = v11;
            *((_DWORD*)v10 + 10) = v12;
            *((_DWORD*)v10 + 11) = v13;
            *((_DWORD*)v10 + 12) = v11;
            *((_DWORD*)v10 + 13) = v12;
            *((_DWORD*)v10 + 14) = v13;
            *((_DWORD*)v10 + 15) = v11;
            *((_DWORD*)v10 + 16) = v12;
            *((_DWORD*)v10 + 17) = v13;
            *((_DWORD*)v10 + 18) = v11;
            *((_DWORD*)v10 + 19) = v12;
            *((_DWORD*)v10 + 20) = v13;
            v10 += 84;
            v4 = v9 <= 7;
            v9 -= 7;
        } while (!v4);
        v14 = v1[4];
        v17.field_0 = v14 - 100;
        v15 = v1[5];
        v17.field_4 = v15 - 100;
        v16 = v1[9];
        v17.field_8 = v1[8] + v14 + 100;
        v17.field_C = v16 + v15 + 100;
        sub_49AB00(&v17, (void(__cdecl*)(int, int))sub_469140, (int)v1);
    }
}

//----- (00469140) --------------------------------------------------------
void __cdecl sub_469140(int arg0)
{
    int v1; // esi
    int v2; // eax
    signed int v3; // ebp
    int v4; // edi
    int v5; // ecx
    int v6; // eax
    int v7; // ebx
    int v8; // ebp
    signed int v9; // eax
    int v10; // edx
    int v11; // ebp
    int v12; // edi
    int v13; // eax
    int v14; // edx
    unsigned int v15; // eax
    unsigned int v16; // eax
    __int16 v17; // cx
    int v18; // edi
    int v19; // ebx
    int v20; // eax
    int v21; // ecx
    int v22; // edi
    int v23; // eax
    int v24; // eax
    int v25; // eax
    int* v26; // esi
    float v27; // [esp+0h] [ebp-68h]
    float v28; // [esp+0h] [ebp-68h]
    int v29; // [esp+14h] [ebp-54h]
    signed int v30; // [esp+18h] [ebp-50h]
    int v31; // [esp+1Ch] [ebp-4Ch]
    signed int v32; // [esp+20h] [ebp-48h]
    signed int v33; // [esp+24h] [ebp-44h]
    int i; // [esp+2Ch] [ebp-3Ch]
    unsigned int v35; // [esp+30h] [ebp-38h]
    unsigned int v36; // [esp+34h] [ebp-34h]
    int2 a1; // [esp+38h] [ebp-30h]
    int2 a4; // [esp+40h] [ebp-28h]
    int v39; // [esp+4Ch] [ebp-1Ch]
    int2 a3; // [esp+50h] [ebp-18h]
    int2 a2; // [esp+58h] [ebp-10h]
    int2 v42; // [esp+60h] [ebp-8h]
    int v43; // [esp+6Ch] [ebp+4h]
    int v44; // [esp+6Ch] [ebp+4h]
    int v45; // [esp+6Ch] [ebp+4h]

    v1 = arg0;
    if (sub_45A840((_DWORD*)arg0)
        || *(_DWORD*)(arg0 + 112) & 0x80000
        && (v2 = *(_DWORD*)(arg0 + 120), v2 & 0x1000000)
        && *(_DWORD*)(arg0 + 144) > 0
        && v2 & 4)
    {
        if (!sub_57AF20()
            || arg0 == *(_DWORD*)& byte_5D4594[2614252]
            || *(int(__cdecl * *)(int*, int))(arg0 + 300) == nox_thing_glow_orb_draw)
        {
            v3 = *(_DWORD*)(arg0 + 148);
            v4 = *(_DWORD*)(arg0 + 144);
            if (*(_DWORD*)(arg0 + 120) & 0x20000000)
            {
                v3 += sub_415FF0(0, *(_DWORD*)(arg0 + 148) >> 18, "C:\\NoxPost\\src\\Client\\Light\\Light16.c", 267) << 16;
                v27 = (double)v3 * 0.000015258789;
                v4 = sub_484C60(v27);
            }
            v28 = sub_484BD0() * 65536.0;
            if (v3 > sub_419A70(v28))
            {
                v33 = *(_DWORD*)& byte_587000[142320];
                if ((unsigned int)v3 <= *(int*)& byte_587000[142320])
                    v33 = v3;
                v5 = *(_DWORD*)(arg0 + 12) - *(_DWORD*)& byte_5D4594[2650676];
                v36 = (v3 >> 16) * (v3 >> 16);
                v6 = *(_DWORD*)(arg0 + 168);
                v7 = *(_DWORD*)(arg0 + 16) - *(_DWORD*)& byte_5D4594[2650680];
                a4.field_0 = *(_DWORD*)(arg0 + 12) - *(_DWORD*)& byte_5D4594[2650676];
                a4.field_4 = v7;
                if (v6 == 0xFFFF)
                {
                    v35 = v4 * v4;
                    v43 = (v5 - v4) / 23;
                    if (v43 < 0)
                        v43 = 0;
                    v30 = (v5 + v4) / 0x17u;
                    if (v30 > 56)
                        v30 = 56;
                    v8 = (v7 - v4) / 23;
                    if (v8 < 0)
                        v8 = 0;
                    v9 = (v7 + v4) / 0x17u;
                    v32 = (v7 + v4) / 0x17u;
                    if (v9 > 44)
                    {
                        v32 = 44;
                        v9 = 44;
                    }
                    v31 = v8;
                    v10 = 23 * v8;
                    v39 = 23 * v8;
                    if (v8 <= v9)
                    {
                        v11 = *(_DWORD*)& byte_587000[142328];
                        v12 = 23 * v43;
                        while (1)
                        {
                            v13 = v7 - v10;
                            v29 = v43;
                            if (v43 <= v30)
                            {
                                v14 = v13 * v13;
                                for (i = v13 * v13; ; v14 = i)
                                {
                                    v15 = v14 + (v5 - v12) * (v5 - v12);
                                    if (v15 <= v35)
                                    {
                                        v16 = sub_4C1C70(v33 + v11, 66 * v15 * *(_DWORD*)& byte_587000[142324] / v36 + 0x10000);
                                        v11 = *(_DWORD*)& byte_587000[142328];
                                        if (v16 > * (int*)& byte_587000[142328])
                                        {
                                            sub_4695E0(
                                                v29,
                                                v31,
                                                (int*)(v1 + 152),
                                                8 * (v16 - *(_DWORD*)& byte_587000[142328]),
                                                *(_DWORD*)(v1 + 172));
                                            v7 = a4.field_4;
                                            v5 = a4.field_0;
                                            v11 = *(_DWORD*)& byte_587000[142328];
                                        }
                                        else
                                        {
                                            v7 = a4.field_4;
                                            v5 = a4.field_0;
                                        }
                                        v12 += 23;
                                    }
                                    else
                                    {
                                        v12 += 23;
                                    }
                                    if (++v29 > v30)
                                        break;
                                }
                            }
                            v39 += 23;
                            if (++v31 > v32)
                                break;
                            v12 = 23 * v43;
                            v10 = v39;
                        }
                    }
                }
                else
                {
                    a1.field_0 = (v5 << 16) / 23;
                    v17 = *(_WORD*)(arg0 + 164);
                    v18 = v4 << 16;
                    a1.field_4 = (v7 << 16) / 23;
                    v19 = v18 / 23;
                    v20 = sub_4C1C60(
                        v18 / 23,
                        16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v17 + 0x4000) >> 4) + 2661964]);
                    v21 = v18 / 23;
                    v22 = v20;
                    v23 = sub_4C1C60(v21, 16 * *(_DWORD*)& byte_5D4594[4 * (*(unsigned __int16*)(arg0 + 164) >> 4) + 2661964]);
                    a3.field_0 = a1.field_0 + v22;
                    LOWORD(v22) = *(_WORD*)(arg0 + 164) + *(_WORD*)(arg0 + 166);
                    a3.field_4 = a1.field_4 + v23;
                    v44 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v22 + 0x4000) >> 4) + 2661964]);
                    v24 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)v22 >> 4) + 2661964]);
                    LOWORD(v22) = *(_WORD*)(v1 + 164) - *(_WORD*)(v1 + 166);
                    a2.field_0 = a1.field_0 + v44;
                    a2.field_4 = a1.field_4 + v24;
                    v45 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v22 + 0x4000) >> 4) + 2661964]);
                    v25 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)v22 >> 4) + 2661964]);
                    v26 = (int*)(v1 + 152);
                    v42.field_0 = a1.field_0 + v45;
                    v42.field_4 = a1.field_4 + v25;
                    sub_4696B0(&a1, &a2, &a3, &a4, v3, v26);
                    sub_4696B0(&a1, &a3, &v42, &a4, v3, v26);
                }
            }
        }
    }
}

//----- (004695E0) --------------------------------------------------------
int __cdecl sub_4695E0(int a1, int a2, int* a3, int a4, int a5)
{
    int v5; // ebx
    int v6; // esi
    int v7; // edi
    int v8; // eax
    unsigned __int8* v9; // ecx
    int v10; // esi
    int v11; // edi
    int result; // eax

    v5 = a4;
    if (a5)
        v5 = -a4;
    v6 = sub_4C1C60(v5, *a3) << 8;
    v7 = sub_4C1C60(v5, a3[1]) << 8;
    v8 = sub_4C1C60(v5, a3[2]);
    v9 = &byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618924];
    v10 = *(_DWORD*)& byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618924] + v6;
    v11 = *(_DWORD*)& byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618928] + v7;
    result = *(_DWORD*)& byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618932] + (v8 << 8);
    if (v10 <= 16711680)
    {
        if (v10 < 0)
            v10 = 0;
    }
    else
    {
        v10 = 16711680;
    }
    if (v11 <= 16711680)
    {
        if (v11 < 0)
            v11 = 0;
    }
    else
    {
        v11 = 16711680;
    }
    if (result <= 16711680)
    {
        if (result < 0)
            result = 0;
        *((_DWORD*)v9 + 1) = v11;
        *(_DWORD*)v9 = v10;
        *((_DWORD*)v9 + 2) = result;
    }
    else
    {
        *((_DWORD*)v9 + 1) = v11;
        *(_DWORD*)v9 = v10;
        result = 16711680;
        *((_DWORD*)v9 + 2) = 16711680;
    }
    return result;
}

//----- (004696B0) --------------------------------------------------------
int __cdecl sub_4696B0(int2* a1, int2* a2, int2* a3, int2* a4, signed int a5, int* a6)
{
    int v6; // edx
    int v7; // edi
    int2* v8; // edi
    int2* v9; // ebx
    int2* v10; // esi
    int result; // eax
    int v12; // ecx
    char v13[184]; // [esp+10h] [ebp-228h]
    char v14[184]; // [esp+C8h] [ebp-170h]
    char v15[184]; // [esp+180h] [ebp-B8h]

    v6 = a1->field_4;
    v7 = a2->field_4;
    if (v6 > v7)
    {
        v10 = a3;
        if (v7 <= a3->field_4)
        {
            v9 = a2;
            v8 = a1;
            goto LABEL_9;
        }
        v9 = a3;
    }
    else
    {
        v8 = a3;
        if (v6 <= a3->field_4)
        {
            v9 = a1;
            v10 = a2;
            goto LABEL_9;
        }
        v9 = a3;
    }
    v10 = a1;
    v8 = a2;
LABEL_9:
    sub_484DC0(v9, v10, (int*)v15);
    sub_484DC0(v9, v8, (int*)v14);
    sub_4697C0((int*)v15, (int*)v14, a4, a5, a6);
    result = v10->field_4;
    v12 = v8->field_4;
    if (result >= v12)
    {
        if (result > v12)
        {
            sub_484DC0(v8, v10, (int*)v13);
            result = sub_4697C0((int*)v15, (int*)v13, a4, a5, a6);
        }
    }
    else
    {
        sub_484DC0(v10, v8, (int*)v13);
        result = sub_4697C0((int*)v13, (int*)v14, a4, a5, a6);
    }
    return result;
}

//----- (004697C0) --------------------------------------------------------
int __cdecl sub_4697C0(int* a1, int* a2, int2* a3, signed int a4, int* a5)
{
    int result; // eax
    int* v6; // edi
    int v7; // esi
    int v8; // edx
    int v9; // ebp
    int* v10; // ecx
    char* v11; // eax
    int v12; // edi
    int v13; // eax
    int v14; // esi
    int v15; // ebx
    int v16; // eax
    unsigned int v17; // eax
    int v18; // [esp+10h] [ebp-10h]
    char* i; // [esp+14h] [ebp-Ch]
    int j; // [esp+18h] [ebp-8h]
    unsigned int v21; // [esp+1Ch] [ebp-4h]
    int* v22; // [esp+24h] [ebp+4h]
    signed int v23; // [esp+28h] [ebp+8h]
    int v24; // [esp+30h] [ebp+10h]

    result = *a1;
    v6 = a2;
    v7 = *a1 + a1[1];
    v18 = *a1 + a1[1];
    if (*a1 < *a2)
        result = *a2;
    if (v7 > a2[1] + *a2)
    {
        v18 = a2[1] + *a2;
        v7 = a2[1] + *a2;
    }
    if (v7 - result > 1)
    {
        v23 = *(_DWORD*)& byte_587000[142308];
        if ((unsigned int)a4 <= *(int*)& byte_587000[142308])
            v23 = a4;
        v21 = (a4 >> 16) * (a4 >> 16);
        v8 = 23 * result - a3->field_4;
        v24 = 23 * result - a3->field_4;
        v9 = result;
        if (result < v7)
        {
            v10 = &v6[result + 2];
            v11 = (char*)((char*)a1 - (char*)v6);
            v12 = *(_DWORD*)& byte_587000[142316];
            v22 = v10;
            for (i = v11; ; v11 = i)
            {
                v13 = *(int*)((char*)v10 + (_DWORD)v11);
                v14 = 23 * v13 - a3->field_0;
                v15 = v13;
                if (v13 < *v10)
                {
                    v16 = v8 * v8;
                    for (j = v8 * v8; ; v16 = j)
                    {
                        v17 = sub_4C1C70(v12 + v23, 66 * *(_DWORD*)& byte_587000[142312] * (v16 + v14 * v14) / v21 + 0x10000);
                        v12 = *(_DWORD*)& byte_587000[142316];
                        if (v17 > * (int*)& byte_587000[142316])
                        {
                            sub_4695E0(v15, v9, a5, 8 * (v17 - *(_DWORD*)& byte_587000[142316]), 0);
                            v12 = *(_DWORD*)& byte_587000[142316];
                        }
                        v14 += 23;
                        if (++v15 >= *v22)
                            break;
                    }
                    v8 = v24;
                    v10 = v22;
                }
                result = v18;
                v8 += 23;
                ++v9;
                ++v10;
                v24 = v8;
                v22 = v10;
                if (v9 >= v18)
                    break;
            }
        }
    }
    return result;
}

//----- (00469920) --------------------------------------------------------
char* __cdecl sub_469920(_DWORD* a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // ecx
    int v4; // ebx
    int v5; // esi
    int v6; // ecx
    int v7; // ebp
    int v10; // ebx
    int v11; // eax
    int v12; // edi
    int v13; // ecx
    char* result; // eax
    int v16; // [esp+18h] [ebp-Ch]
    int v17; // [esp+1Ch] [ebp-8h]
    int v18; // [esp+20h] [ebp-4h]

    if (byte_5D4594[2650637] & 8)
        return (char*)& byte_587000[142336];
    v1 = *a1 - *(_DWORD*)& byte_5D4594[2650676];
    v2 = a1[1] - *(_DWORD*)& byte_5D4594[2650680];
    v3 = v1 / 23;
    v4 = v2 / 23;
    if (v1 / 23 < 0 || v4 < 0 || v3 > 56 || v4 > 44)
        return (char*)& byte_587000[142336];
    v5 = v1 % 23;
    v6 = 12 * (v4 + 40 * v3 + 5 * v3);
    v7 = v2 % 23;
    v16 = *(_DWORD*)& byte_5D4594[v6 + 2618924]
        + v5 * (*(int*)& byte_5D4594[v6 + 2619464] - *(int*)& byte_5D4594[v6 + 2618924]) / 23;
    v17 = *(_DWORD*)& byte_5D4594[v6 + 2618928]
        + v5 * (*(int*)& byte_5D4594[v6 + 2619468] - *(int*)& byte_5D4594[v6 + 2618928]) / 23;
    v18 = *(_DWORD*)& byte_5D4594[v6 + 2618932]
        + v5 * (*(int*)& byte_5D4594[v6 + 2619472] - *(int*)& byte_5D4594[v6 + 2618932]) / 23;
    v10 = *(_DWORD*)& byte_5D4594[v6 + 2618936];
    v11 = v5 * (*(_DWORD*)& byte_5D4594[v6 + 2619476] - v10);
    v12 = v2 % 23
        * (*(_DWORD*)& byte_5D4594[v6 + 2618940]
            + v5 * (*(int*)& byte_5D4594[v6 + 2619480] - *(int*)& byte_5D4594[v6 + 2618940]) / 23
            - v17);
    v13 = v7
        * (*(_DWORD*)& byte_5D4594[v6 + 2618944]
            + v5 * (*(int*)& byte_5D4594[v6 + 2619484] - *(int*)& byte_5D4594[v6 + 2618944]) / 23
            - v18);
    *(_DWORD*)& byte_5D4594[1064836] = (v16 + v7 * (v10 + v11 / 23 - v16) / 23) >> 16;
    *(_DWORD*)& byte_5D4594[1064840] = (v17 + v12 / 23) >> 16;
    result = (char*)& byte_5D4594[1064836];
    *(_DWORD*)& byte_5D4594[1064844] = (v18 + v13 / 23) >> 16;
    return result;
}

//----- (00469B90) --------------------------------------------------------
int __cdecl sub_469B90(int* a1)
{
    int result; // eax

    *(_DWORD*)& byte_587000[142296] = *a1;
    *(_DWORD*)& byte_587000[142300] = a1[1];
    result = a1[2];
    *(_DWORD*)& byte_587000[142304] = a1[2];
    return result;
}

//----- (00469BB0) --------------------------------------------------------
char* sub_469BB0()
{
    return (char*)& byte_587000[142296];
}

//----- (00469BC0) --------------------------------------------------------
void sub_469BC0()
{
    int v0; // esi
    int v1; // eax
    int v2; // ebx
    int i; // ebp
    int v4; // eax
    int v5; // eax
    int v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // [esp-20h] [ebp-1078h]
    wchar_t* v9; // [esp-20h] [ebp-1078h]
    wchar_t* v10; // [esp-20h] [ebp-1078h]
    int v11; // [esp+4h] [ebp-1054h]
    int v12; // [esp+8h] [ebp-1050h]
    char v13[76]; // [esp+Ch] [ebp-104Ch]
    wchar_t v14[2048]; // [esp+58h] [ebp-1000h]

    v0 = *(_DWORD*)& byte_5D4594[2618908];
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        v1 = sub_43F320(0);
        v2 = *(_DWORD*)(v0 + 3644);
        v11 = v1;
        for (i = -v1; v2; i += v11 + v12)
        {
            strcpy(v13, "Journal:");
            HIWORD(v4) = 0;
            strcat(&v13, (const char*)v2);
            LOWORD(v4) = *(_WORD*)(v2 + 72);
            v5 = v4 - 2;
            if (v5)
            {
                v6 = v5 - 2;
                if (v6)
                {
                    if (v6 == 4)
                    {
                        v8 = loadString_sub_40F1D0((char*)& byte_587000[142564], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 64);
                        nox_wcscpy(v14, v8);
                    }
                    else
                    {
                        v14[0] = 0;
                    }
                }
                else
                {
                    v9 = loadString_sub_40F1D0((char*)& byte_587000[142500], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 60);
                    nox_wcscpy(v14, v9);
                }
            }
            else
            {
                v10 = loadString_sub_40F1D0((char*)& byte_587000[142440], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 56);
                nox_wcscpy(v14, v10);
            }
            nox_wcscat(v14, L" ");
            v7 = loadString_sub_40F1D0((char*)& v13, 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 74);
            nox_wcscat(v14, v7);
            sub_43F840(0, v14, 0, &v12, 240);
            v2 = *(_DWORD*)(v2 + 64);
        }
        *(_DWORD*)& byte_5D4594[1064848] = i <= 0 ? 0 : i;
    }
}

//----- (00469D40) --------------------------------------------------------
void __cdecl sub_469D40(int xLeft, int yTop, int a3)
{
    int v3; // esi
    int v4; // ebp
    int v5; // ebx
    int i; // eax
    int v7; // eax
    int v8; // edi
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    wchar_t* v12; // eax
    int v13; // esi
    int v14; // [esp+10h] [ebp-1054h]
    int v15; // [esp+14h] [ebp-1050h]
    char v16[76]; // [esp+18h] [ebp-104Ch]
    wchar_t v17[2048]; // [esp+64h] [ebp-1000h]

    v3 = *(_DWORD*)& byte_5D4594[2618908];
    v4 = yTop - a3;
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        sub_434460(*(int*)& byte_5D4594[2650656]);
        sub_49CE30(xLeft, yTop, 260, 150);
        v5 = *(_DWORD*)(v3 + 3644);
        if (v5)
        {
            for (i = *(_DWORD*)(v5 + 64); i; i = *(_DWORD*)(i + 64))
                v5 = i;
            v14 = sub_43F320(0);
            do
            {
                HIWORD(v7) = 0;
                strcpy(v16, "Journal:");
                strcat(v16, (const char*)v5);
                LOWORD(v7) = *(_WORD*)(v5 + 72);
                switch (v7)
                {
                case 1:
                    v8 = *(_DWORD*)& byte_5D4594[2523948];
                    goto LABEL_12;
                case 2:
                    v8 = *(_DWORD*)& byte_5D4594[2650644];
                    v9 = loadString_sub_40F1D0((char*)& byte_587000[142680], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 135);
                    nox_wcscpy(v17, v9);
                    break;
                case 4:
                    v8 = *(_DWORD*)& byte_5D4594[2650660];
                    v10 = loadString_sub_40F1D0((char*)& byte_587000[142740], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 140);
                    nox_wcscpy(v17, v10);
                    break;
                case 8:
                    v8 = *(_DWORD*)& byte_5D4594[2589772];
                    v11 = loadString_sub_40F1D0((char*)& byte_587000[142804], 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 145);
                    nox_wcscpy(v17, v11);
                    break;
                default:
                    v8 = *(_DWORD*)& byte_5D4594[2618904];
                LABEL_12:
                    v17[0] = 0;
                    break;
                }
                nox_wcscat(v17, L" ");
                v12 = loadString_sub_40F1D0((char*)& v16, 0, "C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c", 155);
                nox_wcscat(v17, v12);
                sub_43F840(0, &v17, 0, &v15, 240);
                v13 = v15 + v4;
                if (v15 + v4 > yTop)
                {
                    sub_434390(v8);
                    sub_43FAF0(0, &v17, xLeft + 10, v4, 240, 0);
                }
                v4 = v13 + v14;
                if (v13 + v14 > yTop + 150)
                    break;
                v5 = *(_DWORD*)(v5 + 68);
            } while (v5);
        }
    }
}

//----- (00469FA0) --------------------------------------------------------
int sub_469FA0()
{
    return *(_DWORD*)& byte_5D4594[1064848];
}

//----- (00469FB0) --------------------------------------------------------
int __cdecl sub_469FB0(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[142868];
    while (strcmp(*v2, a1))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[142928])
            return -1;
    }
    return v1;
}

//----- (0046A010) --------------------------------------------------------
BOOL __cdecl sub_46A010(_DWORD* a1, char* a2)
{
    _DWORD* v2; // esi
    char* v3; // ebx
    unsigned __int8* v4; // edx
    int v5; // ecx
    const char* v6; // edi
    int v8; // ebp
    unsigned __int8* v9; // eax
    unsigned __int8* v10; // eax
    unsigned __int8* v11; // eax
    unsigned __int8* v12; // eax
    int v13; // ebp
    int v14; // edi
    unsigned __int8* v15; // ebp
    int* v16; // eax
    int v17; // ecx
    int* v18; // eax
    int v19; // ecx
    int* v20; // eax
    int v21; // ecx
    char* v22; // eax
    char v23; // cl
    int v24; // edi
    char* v25; // eax
    unsigned __int8* v26; // ecx
    bool v27; // zf
    int* v28; // eax
    int v29; // ecx
    _DWORD* v30; // [esp-4h] [ebp-40h]
    int v31; // [esp+10h] [ebp-2Ch]
    unsigned __int8* v32; // [esp+14h] [ebp-28h]
    int v33; // [esp+18h] [ebp-24h]
    int v34; // [esp+1Ch] [ebp-20h]
    int v35; // [esp+20h] [ebp-1Ch]
    int v36; // [esp+24h] [ebp-18h]
    int v37; // [esp+28h] [ebp-14h]
    int v38; // [esp+2Ch] [ebp-10h]
    int v39; // [esp+30h] [ebp-Ch]
    int v40; // [esp+34h] [ebp-8h]
    const char* v41; // [esp+38h] [ebp-4h]
    unsigned __int8 v42; // [esp+40h] [ebp+4h]
    unsigned __int8 v43; // [esp+40h] [ebp+4h]
    unsigned __int8 v44; // [esp+40h] [ebp+4h]
    unsigned __int8 v45; // [esp+40h] [ebp+4h]
    unsigned __int8 v46; // [esp+40h] [ebp+4h]
    const char** v47; // [esp+40h] [ebp+4h]
    unsigned __int8* v48; // [esp+44h] [ebp+8h]
    int v49; // [esp+44h] [ebp+8h]

    v2 = a1;
    v3 = a2;
    v30 = a1;
    v4 = (unsigned __int8*)(a1[2] + 4);
    a1[2] = v4;
    v42 = *v4;
    v2[2] = v4 + 1;
    sub_40ACC0(a2, 1u, v42, (int)v30);
    a2[v42] = 0;
    v5 = 0;
    if (*(_DWORD*)& byte_5D4594[251540] > 0)
    {
        v6 = (const char*)& byte_5D4594[2692748];
        v48 = &byte_5D4594[2692748];
        while (strcmp(v6, v3))
        {
            ++v5;
            v6 = (const char*)(v48 + 12332);
            v48 += 12332;
            if (v5 >= *(int*)& byte_5D4594[251540])
                return 0;
        }
        v49 = v5;
        if (v5 != -1)
        {
            v38 = 12332 * v5;
            memset(&byte_5D4594[12332 * v5 + 2701180], 0, 0xF00u);
            v2[2] += 14;
            sub_40AD60((char*)& v31, 1, 1, v2);
            v8 = 0;
            if ((_BYTE)v31)
            {
                while (v8 < 8)
                {
                    v9 = (unsigned __int8*)v2[2];
                    v43 = *v9;
                    v2[2] = v9 + 1;
                    sub_40ACC0(v3, 1u, v43, (int)v2);
                    v3[v43] = 0;
                    if (++v8 >= (unsigned __int8)v31)
                        goto LABEL_11;
                }
            }
            else
            {
            LABEL_11:
                v10 = (unsigned __int8*)v2[2];
                v44 = *v10;
                v2[2] = v10 + 1;
                sub_40ACC0(v3, 1u, v44, (int)v2);
                v3[v44] = 0;
                v11 = (unsigned __int8*)v2[2];
                v45 = *v11;
                v2[2] = v11 + 1;
                sub_40ACC0(v3, 1u, v45, (int)v2);
                v3[v45] = 0;
                v12 = (unsigned __int8*)v2[2];
                v46 = *v12;
                v2[2] = v12 + 1;
                sub_40ACC0(v3, 1u, v46, (int)v2);
                v3[v46] = 0;
                ++v2[2];
                v47 = (const char**)& byte_587000[142868];
                while (1)
                {
                    v13 = sub_469FB0(*v47);
                    v36 = v13;
                    if (v13 < 0)
                        break;
                    sub_40AD60((char*)& v35, 1, 1, v2);
                    if ((unsigned __int8)v35 >= 0x10u)
                        break;
                    v14 = 0;
                    v34 = 0;
                    if ((_BYTE)v35)
                    {
                        v37 = 3083 * v49;
                        while (1)
                        {
                            v33 = 4;
                            v32 = &byte_5D4594[4 * (v14 + 16 * v13 + v37) + 2701180];
                            v15 = &byte_5D4594[8 * (v14 + 16 * v13) + 2693504 + v38];
                            do
                            {
                                v16 = (int*)v2[2];
                                v17 = *v16;
                                v2[2] = v16 + 1;
                                *((_DWORD*)v15 - 1) = v17;
                                v18 = (int*)v2[2];
                                v19 = *v18;
                                v2[2] = v18 + 1;
                                *(_DWORD*)v15 = v19;
                                v20 = (int*)v2[2];
                                v21 = *v20;
                                v2[2] = v20 + 1;
                                v40 = v21;
                                *v3 = byte_5D4594[1064852];
                                if (v21 == -1)
                                {
                                    v22 = (char*)v2[2];
                                    v23 = *v22++;
                                    v2[2] = v22;
                                    LOBYTE(v41) = v23;
                                    LOBYTE(v39) = *v22;
                                    v2[2] = v22 + 1;
                                    v24 = (unsigned __int8)v39;
                                    sub_40ACC0(v3, (unsigned __int8)v39, 1, (int)v2);
                                    v21 = v40;
                                    v3[v24] = 0;
                                    v14 = v34;
                                }
                                v25 = sub_42FAA0(v21, v41, v3);
                                v26 = v32;
                                v15 += 1920;
                                *(_DWORD*)v32 = v25;
                                v27 = v33 == 1;
                                v32 = v26 + 960;
                                --v33;
                            } while (!v27);
                            v34 = ++v14;
                            if (v14 >= (unsigned __int8)v35)
                                break;
                            v13 = v36;
                        }
                    }
                    ++v47;
                    if ((int)v47 >= (int)& byte_587000[142928])
                    {
                        v28 = (int*)v2[2];
                        v29 = *v28;
                        v2[2] = v28 + 1;
                        return v29 == 1162757152;
                    }
                }
            }
        }
    }
    return 0;
}

//----- (0046A360) --------------------------------------------------------
int sub_46A360()
{
    int i; // ebx
    int v1; // edx
    int v2; // esi
    unsigned __int8* v3; // edi

    for (i = 0; i < 986560; i += 12332)
    {
        v1 = 0;
        do
        {
            v2 = 15;
            do
            {
                v3 = &byte_5D4594[i + 2701180 + v1];
                v1 += 64;
                --v2;
                memset(v3, 0, 0x40u);
            } while (v2);
        } while (v1 < 3840);
    }
    return 1;
}

//----- (0046A3B0) --------------------------------------------------------
int __cdecl sub_46A3B0(int a1, int a2, int a3, int a4)
{
    return *(_DWORD*)& byte_5D4594[4 * (16 * (a2 + 12 * a4 + 3 * a4) + a3 + 3083 * a1) + 2701180];
}

//----- (0046A3F0) --------------------------------------------------------
char* __cdecl sub_46A3F0(int a1, int a2, int a3, int a4)
{
    return (char*)& byte_5D4594[12332 * a1 + 2693500 + 8 * (a3 + 16 * (a2 + 12 * a4 + 3 * a4))];
}

//----- (0046A430) --------------------------------------------------------
void __cdecl sub_46A430(int a1)
{
    if (!sub_40A5C0(2048))
    {
        if (!*(_DWORD*)& byte_5D4594[1064868])
        {
            **(_WORD * *)& byte_5D4594[1064864] = 0;
            *(_WORD*)(*(_DWORD*)& byte_5D4594[1064864] + 1052) = 0;
            sub_46A8C0(*(int*)& byte_5D4594[1064856]);
            sub_46C690(*(int*)& byte_5D4594[1064856]);
            sub_46B500(*(int*)& byte_5D4594[1064860]);
            *(_DWORD*)& byte_5D4594[1064868] = 1;
            *(_DWORD*)& byte_5D4594[1064872] = a1;
        }
    }
}

//----- (0046A4A0) --------------------------------------------------------
int sub_46A4A0()
{
    return *(_DWORD*)& byte_5D4594[1064868];
}

//----- (0046A4B0) --------------------------------------------------------
size_t __cdecl sub_46A4B0(wchar_t* a1, int a2)
{
    _DWORD* v2; // ebp
    size_t v3; // edi
    size_t result; // eax
    const wchar_t* v5; // edi
    char v6; // al
    int v7; // eax
    char v8[520]; // [esp+Ch] [ebp-208h]

    v2 = sub_45A6F0(*(int*)& byte_5D4594[2616328]);
    v3 = nox_wcsspn(a1, L" ");
    result = nox_wcslen(a1);
    if (v3 != result)
    {
        v5 = &a1[v3];
        v8[0] = -88;
        *(_WORD*)& v8[9] = 0;
        *(_WORD*)& v8[1] = *(_WORD*)& byte_5D4594[2616328];
        v8[3] = 0;
        if (sub_4100F0((__int16*)a1))
            v6 = v8[3] | 2;
        else
            v6 = v8[3] | 4;
        v8[3] = v6;
        if (a2)
            v8[3] |= 1u;
        v8[8] = nox_wcslen(v5) + 1;
        if (v8[3] & 4)
        {
            nox_wcscpy((wchar_t*)& v8[11], v5);
            v7 = 2;
        }
        else
        {
            nox_sprintf(&v8[11], "%S", v5);
            v7 = 1;
        }
        if (v2)
        {
            *(_WORD*)& v8[4] = *((_WORD*)v2 + 6);
            *(_WORD*)& v8[6] = *((_WORD*)v2 + 8);
        }
        else
        {
            *(_WORD*)& v8[6] = -1;
            *(_WORD*)& v8[4] = -1;
        }
        result = sub_40EBC0(31, 0, v8, v7 * (unsigned __int8)v8[8] + 11);
    }
    return result;
}

//----- (0046A5D0) --------------------------------------------------------
int __cdecl sub_46A5D0(_DWORD* a1, int a2)
{
    int v2; // ecx
    bool v3; // sf
    int v5; // [esp+4h] [ebp-8h]
    int v6; // [esp+8h] [ebp-4h]

    v5 = 0;
    v6 = 0;
    sub_46A8C0(*(int*)& byte_5D4594[1064856]);
    sub_46B500(*(int*)& byte_5D4594[1064860]);
    sub_43F840(0, *(unsigned __int16**)& byte_5D4594[1064864], &v5, 0, 0);
    sub_43F840(0, (unsigned __int16*)(*(_DWORD*)& byte_5D4594[1064864] + 512), &v6, 0, 0);
    v3 = v5 + v6 - 90 < 0;
    v5 += v6 + 10;
    v2 = v5;
    if (v5 < 100)
    {
        v2 = 100;
    LABEL_5:
        v5 = v2;
        goto LABEL_6;
    }
    if (v5 > 320)
    {
        v2 = 320;
        goto LABEL_5;
    }
LABEL_6:
    sub_46A9B0(
        *(_DWORD * *)& byte_5D4594[1064856],
        (nox_win_width - v2) / 2,
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064856] + 20));
    sub_46AB20(a1, v5, 20);
    return sub_488160((int)a1, a2);
}

//----- (0046A6A0) --------------------------------------------------------
int sub_46A6A0()
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1064856]))
        return 0;
    if (sub_46B4F0() == *(_DWORD*)& byte_5D4594[1064860])
        sub_46B500(0);
    sub_46C6E0(*(int*)& byte_5D4594[1064856]);
    nox_window_set_hidden(*(int*)& byte_5D4594[1064856], 1);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064856] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064860] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)& byte_5D4594[3799524] = 1;
    *(_DWORD*)& byte_5D4594[1064868] = 0;
    return 1;
}

//----- (0046A730) --------------------------------------------------------
_DWORD* sub_46A730()
{
    _DWORD* result; // eax

    *(_DWORD*)& byte_5D4594[1064876] = nox_win_width / 2;
    *(_DWORD*)& byte_5D4594[1064880] = 2 * nox_win_height / 3;
    result = nox_new_window_from_file("GuiChat.wnd", sub_46A820);
    *(_DWORD*)& byte_5D4594[1064856] = result;
    if (result)
    {
        sub_46A9B0(result, *(int*)& byte_5D4594[1064876], *(int*)& byte_5D4594[1064880]);
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1064856], 9201);
        *(_DWORD*)& byte_5D4594[1064860] = result;
        if (result)
        {
            sub_46B340((int)result, sub_46A5D0);
            sub_46B300(*(int*)& byte_5D4594[1064860], sub_46A7E0);
            result = *(_DWORD * *)& byte_5D4594[1064856];
            *(_DWORD*)& byte_5D4594[1064864] = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064860] + 32);
        }
    }
    return result;
}

//----- (0046A7E0) --------------------------------------------------------
int __cdecl sub_46A7E0(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 != 21 || a3 != 1)
        return sub_487D70(a1, a2, a3, a4);
    if (a4 == 2)
        sub_49B7A0();
    return 1;
}

//----- (0046A820) --------------------------------------------------------
int __cdecl sub_46A820(int a1, int a2, int a3, int a4)
{
    if (a2 == 16415)
    {
        if (*(_WORD*)(*(_DWORD*)& byte_5D4594[1064864] + 1052))
            sub_46A4B0(*(wchar_t**)& byte_5D4594[1064864], *(int*)& byte_5D4594[1064872]);
        sub_46A6A0();
    }
    return 0;
}

//----- (0046A860) --------------------------------------------------------
int sub_46A860()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1064856];
    if (*(_DWORD*)& byte_5D4594[1064856])
    {
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[1064856]);
        *(_DWORD*)& byte_5D4594[1064856] = 0;
    }
    *(_DWORD*)& byte_5D4594[1064860] = 0;
    *(_DWORD*)& byte_5D4594[1064864] = 0;
    *(_DWORD*)& byte_5D4594[1064868] = 0;
    *(_DWORD*)& byte_5D4594[1064872] = 0;
    return result;
}

//----- (0046A8A0) --------------------------------------------------------
int sub_46A8A0()
{
    return 0;
}

//----- (0046A8B0) --------------------------------------------------------
int sub_46A8B0()
{
    return 0;
}

//----- (0046A8C0) --------------------------------------------------------
int __cdecl sub_46A8C0(int a1)
{
    int result; // eax
    int v2; // eax
    int v3; // eax

    if (!a1)
        return -2;
    v2 = *(_DWORD*)& byte_5D4594[1064888];
    if (*(_DWORD*)& byte_5D4594[1064888] == a1)
    {
    LABEL_6:
        sub_46A960(a1);
        sub_46A920(a1);
        v3 = *(_DWORD*)(a1 + 4);
        LOBYTE(v3) = v3 | 1;
        *(_DWORD*)(a1 + 4) = v3;
        nox_window_set_hidden(a1, 0);
        result = 0;
    }
    else
    {
        while (v2)
        {
            v2 = *(_DWORD*)(v2 + 388);
            if (v2 == a1)
                goto LABEL_6;
        }
        result = -3;
    }
    return result;
}

//----- (0046A920) --------------------------------------------------------
int __cdecl sub_46A920(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 392) = 0;
    *(_DWORD*)(a1 + 388) = *(_DWORD*)& byte_5D4594[1064888];
    if (*(_DWORD*)& byte_5D4594[1064888])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[1064888] + 392) = a1;
    else
        nox_win_unk4 = a1;
    *(_DWORD*)& byte_5D4594[1064888] = a1;
    return result;
}

//----- (0046A960) --------------------------------------------------------
void __cdecl sub_46A960(nox_window* win)
{
    nox_window* v2 = win->field_97;
    if (v2) {
        v2->field_98 = win->field_98;
    } else {
        nox_win_unk4 = win->field_98;
    }
    nox_window* v3 = win->field_98;
    if (v3) {
        v3->field_97 = win->field_97;
    } else {
        *(_DWORD*)& byte_5D4594[1064888] = win->field_97;
    }
}

//----- (0046A9B0) --------------------------------------------------------
int __cdecl sub_46A9B0(_DWORD* a1, int a2, int a3)
{
    int v4; // esi
    int v5; // ecx

    if (!a1)
        return -2;
    v4 = a1[2];
    a1[4] = a2;
    v5 = a3 + a1[3];
    a1[5] = a3;
    a1[6] = a2 + v4;
    a1[7] = v5;
    sub_46A9F0(a1);
    return 0;
}

//----- (0046A9F0) --------------------------------------------------------
_DWORD* __cdecl sub_46A9F0(_DWORD* a1)
{
    _DWORD* result; // eax
    int v2; // ecx
    int v3; // edx
    int v4; // ecx
    int v5; // edx

    result = a1;
    v2 = a1[4];
    v3 = a1[6];
    if (v2 > v3)
    {
        a1[4] = v3;
        a1[6] = v2;
    }
    v4 = a1[5];
    v5 = a1[7];
    if (v4 > v5)
    {
        a1[5] = v5;
        a1[7] = v4;
    }
    return result;
}

//----- (0046AA20) --------------------------------------------------------
int __cdecl sub_46AA20(int a1, _DWORD* a2, _DWORD* a3)
{
    int result; // eax

    if (a1)
    {
        *a2 = *(_DWORD*)(a1 + 16);
        *a3 = *(_DWORD*)(a1 + 20);
        result = 0;
    }
    else
    {
        *a3 = 0;
        *a2 = 0;
        result = -2;
    }
    return result;
}

//----- (0046AA60) --------------------------------------------------------
int __cdecl sub_46AA60(nox_window* win, _DWORD* a2, _DWORD* a3)
{
    if (!win)
        return -2;

    *a2 = win->field_4;
    *a3 = win->field_5;
    for (nox_window* i = win->field_99; i; i = i->field_99) {
        *a2 += i->field_4;
        *a3 += i->field_5;
    }
    return 0;
}

//----- (0046AAB0) --------------------------------------------------------
BOOL __cdecl sub_46AAB0(_DWORD* a1, int a2, int a3)
{
    _DWORD* v3; // esi
    int v5; // [esp+4h] [ebp-Ch]
    int v6; // [esp+8h] [ebp-8h]
    int v7; // [esp+Ch] [ebp-4h]

    v3 = a1;
    sub_46AA60(a1, &a1, &v6);
    nox_window_get_size((int)v3, &v5, &v7);
    return a2 >= (int)a1 && a2 <= (int)a1 + v5 && a3 >= v6 && a3 <= v6 + v7;
}

//----- (0046AB20) --------------------------------------------------------
int __cdecl sub_46AB20(_DWORD* a1, int a2, int a3)
{
    int v4; // esi

    if (!a1)
        return -2;
    a1[6] = a2 + a1[4];
    v4 = a3 + a1[5];
    a1[2] = a2;
    a1[3] = a3;
    a1[7] = v4;
    nox_window_call_field_94((int)a1, 16388, a2, a3);
    return 0;
}

//----- (0046AB70) --------------------------------------------------------
int __cdecl nox_window_get_size(nox_window* win, int* outW, int* outH)
{
    if (!win) {
        *outW = 0;
        *outH = 0;
        return -2;
    }
    *outW = win->width;
    *outH = win->height;
    return 0;
}

//----- (0046ABB0) --------------------------------------------------------
int __cdecl sub_46ABB0(int a1, int a2)
{
    int v3; // ecx
    unsigned int v4; // ecx
    int v5; // esi

    if (!a1)
        return -2;
    v3 = *(_DWORD*)(a1 + 4);
    if (a2)
        v4 = v3 | 8;
    else
        v4 = v3 & 0xFFFFFFF7;
    v5 = *(_DWORD*)(a1 + 400);
    for (*(_DWORD*)(a1 + 4) = v4; v5; v5 = *(_DWORD*)(v5 + 388))
        sub_46ABB0(v5, a2);
    return 0;
}

//----- (0046AC00) --------------------------------------------------------
int __cdecl nox_window_set_hidden(nox_window* win, int hidden)
{
    if (!win)
        return -2;

    if (!hidden) {
        win->flags &= ~NOX_WIN_HIDDEN;
        return 0;
    }

    if ((win->flags & 0x8000) == 0)
        sub_46AC60(win);

    if (*(_DWORD*)& byte_5D4594[3799468]) {
        if (!(win->flags & NOX_WIN_HIDDEN))
            * (_DWORD*)& byte_5D4594[3799524] = 1;
    }
    win->flags |= NOX_WIN_HIDDEN;
    return 0;
}

//----- (0046AC60) --------------------------------------------------------
void __cdecl sub_46AC60(int a1)
{
    int v2; // esi

    if (*(_BYTE*)(a1 + 4) & 0x80)
    {
        if (*(_DWORD*)(a1 + 60))
            sub_42FAE0(*(_DWORD*)(a1 + 60));
        if (*(_DWORD*)(a1 + 84))
            sub_42FAE0(*(_DWORD*)(a1 + 84));
        if (*(_DWORD*)(a1 + 68))
            sub_42FAE0(*(_DWORD*)(a1 + 68));
        if (*(_DWORD * *)(a1 + 92))
            sub_42FAE0(*(_DWORD*)(a1 + 92));
        v2 = *(_DWORD*)(a1 + 76);
        if (v2)
            sub_42FAE0(v2);
    }
}

//----- (0046ACC0) --------------------------------------------------------
int __cdecl wndIsShown_sub_46ACC0(int a1)
{
    int result; // eax

    if (a1)
        result = (*(_DWORD*)(a1 + 4) >> 4) & 1;
    else
        result = 1;
    return result;
}

//----- (0046ACE0) --------------------------------------------------------
void __cdecl sub_46ACE0(_DWORD* a1, int a2, int a3, int a4)
{
    for (int i = a2; i <= a3; i++)
    {
        _DWORD* v5 = sub_46B0C0(a1, i);
        nox_window_set_hidden((int)v5, a4);
    }
}

//----- (0046AD20) --------------------------------------------------------
void __cdecl sub_46AD20(_DWORD* a1, int a2, int a3, int a4)
{
    int i; // esi
    _DWORD* v5; // eax

    for (i = a2; i <= a3; ++i)
    {
        v5 = sub_46B0C0(a1, i);
        sub_46ABB0((int)v5, a4);
    }
}

//----- (0046AD60) --------------------------------------------------------
int __cdecl sub_46AD60(int a1, int a2)
{
    int result; // eax

    if (!a1)
        return -2;
    result = *(_DWORD*)(a1 + 4);
    *(_DWORD*)(a1 + 4) = a2 | result;
    return result;
}

//----- (0046AD80) --------------------------------------------------------
int __cdecl sub_46AD80(int a1, int a2)
{
    int result; // eax

    if (!a1)
        return -2;
    result = *(_DWORD*)(a1 + 4);
    *(_DWORD*)(a1 + 4) = result & ~a2;
    return result;
}

//----- (0046ADA0) --------------------------------------------------------
int __cdecl sub_46ADA0(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 4);
    else
        result = -2;
    return result;
}

//----- (0046ADC0) --------------------------------------------------------
int __cdecl sub_46ADC0(int a1)
{
    if (nox_win_unk3)
        return -4;
    nox_win_unk3 = a1;
    return 0;
}

//----- (0046ADE0) --------------------------------------------------------
int __cdecl sub_46ADE0(int a1)
{
    if (a1 == nox_win_unk3)
        nox_win_unk3 = 0;
    return 0;
}

//----- (0046AE00) --------------------------------------------------------
int sub_46AE00()
{
    return nox_win_unk3;
}

//----- (0046AE10) --------------------------------------------------------
int __cdecl sub_46AE10(int a1, int a2)
{
    int result; // eax
    int v3; // ecx

    result = a1;
    if (a1)
    {
        v3 = *(_DWORD*)(a1 + 36);
        if (a2)
            * (_DWORD*)(a1 + 36) = v3 | 2;
        else
            *(_DWORD*)(a1 + 36) = v3 & 0xFFFFFFFD;
    }
    return result;
}

//----- (0046AE40) --------------------------------------------------------
int __cdecl sub_46AE40(int a1, int a2, int a3)
{
    int result; // eax

    result = a1;
    if (a1)
    {
        *(_DWORD*)(a1 + 96) = a2;
        *(_DWORD*)(a1 + 100) = a3;
    }
    return result;
}

//----- (0046AE60) --------------------------------------------------------
int __cdecl sub_46AE60(int a1, int a2)
{
    if (!a1)
        return -2;
    *(_DWORD*)(a1 + 60) = a2;
    return 0;
}

//----- (0046AE80) --------------------------------------------------------
int __cdecl sub_46AE80(int a1, int a2)
{
    if (!a1)
        return -2;
    *(_DWORD*)(a1 + 84) = a2;
    return 0;
}

//----- (0046AEA0) --------------------------------------------------------
int __cdecl sub_46AEA0(int a1, int a2)
{
    if (!a1)
        return -2;
    *(_DWORD*)(a1 + 76) = a2;
    return 0;
}

//----- (0046AEC0) --------------------------------------------------------
int __cdecl sub_46AEC0(int a1, int a2)
{
    if (!a1)
        return -2;
    *(_DWORD*)(a1 + 92) = a2;
    return 0;
}

//----- (0046AEE0) --------------------------------------------------------
int __cdecl sub_46AEE0(int a1, int a2)
{
    nox_window_call_field_94(a1, 16385, a2, 0);
    return 0;
}

//----- (0046AF00) --------------------------------------------------------
int __cdecl sub_46AF00(int a1)
{
    int v1; // ecx
    int result; // eax

    if (!a1)
        goto LABEL_9;
    v1 = *(_DWORD*)(a1 + 44);
    if (v1 & 0x800)
        return nox_window_call_field_94(a1, 16386, 0, 0);
    if ((v1 & 0x80u) != 0)
        result = nox_window_call_field_94(a1, 16413, 0, 0);
    else
        LABEL_9:
    result = 0;
    return result;
}

//----- (0046AF40) --------------------------------------------------------
int __cdecl sub_46AF40(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(a1 + 236);
    return result;
}

//----- (0046AF50) --------------------------------------------------------
int __cdecl sub_46AF50(int a1, int a2)
{
    int result; // eax

    if (a1 && *(_BYTE*)(a1 + 44) & 0x20)
        result = nox_window_call_field_94(a1, 16406, a2, 0);
    else
        result = 0;
    return result;
}

//----- (0046AF80) --------------------------------------------------------
int __cdecl sub_46AF80_copy_window_part(nox_window* win, const void* p)
{
    if (!win)
        return -2;
    if (!p)
        return -3;
    qmemcpy(win->field_9, p, 83*4);
    return 0;
}

//----- (0046AFB0) --------------------------------------------------------
int __cdecl sub_46AFB0(int a1, void* a2)
{
    int result; // eax

    if (!a1)
        return -2;
    if (!a2)
        return -3;
    result = 0;
    qmemcpy(a2, (const void*)(a1 + 36), 0x14Cu);
    return result;
}

//----- (0046AFE0) --------------------------------------------------------
int __cdecl sub_46AFE0(int a1, int a2)
{
    if (!a1)
        return -2;
    *(_DWORD*)(a1 + 56) = a2;
    return 0;
}

//----- (0046B000) --------------------------------------------------------
wchar_t* __cdecl sub_46B000(wchar_t* a1, wchar_t* a2)
{
    wchar_t* result; // eax
    wchar_t* v3; // eax

    if (a2)
    {
        if (nox_wcslen(a2) < 0x40)
        {
            result = nox_wcscpy(a1 + 102, a2);
        }
        else
        {
            v3 = loadString_sub_40F1D0((char*)& byte_587000[143168], 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c", 1004);
            result = nox_wcscpy(a1 + 102, v3);
        }
    }
    else
    {
        result = a1;
        a1[102] = 0;
    }
    return result;
}

//----- (0046B070) --------------------------------------------------------
int __cdecl sub_46B070(int a1, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a1 + 384) = a2;
    return result;
}

//----- (0046B080) --------------------------------------------------------
int __cdecl sub_46B080(_DWORD* a1, int a2)
{
    if (!a1)
        return -2;
    *a1 = a2;
    return 0;
}

//----- (0046B0A0) --------------------------------------------------------
int __cdecl sub_46B0A0(int* a1)
{
    int result; // eax

    if (a1)
        result = *a1;
    else
        result = -2;
    return result;
}

//----- (0046B0C0) --------------------------------------------------------
_DWORD* __cdecl sub_46B0C0(_DWORD* a1, int a2)
{
    _DWORD* v2; // esi
    _DWORD* v3; // eax
    _DWORD* result; // eax

    v2 = a1;
    if (!a1)
    {
        v2 = *(_DWORD * *)& byte_5D4594[1064888];
        if (!*(_DWORD*)& byte_5D4594[1064888])
            return 0;
    }
    while (*v2 != a2)
    {
        v3 = (_DWORD*)v2[100];
        if (v3)
        {
            result = sub_46B0C0(v3, a2);
            if (result)
                return result;
        }
        v2 = (_DWORD*)v2[97];
        if (!v2)
            return 0;
    }
    return v2;
}

//----- (0046B110) --------------------------------------------------------
int sub_46B110()
{
    return *(_DWORD*)& byte_5D4594[1064888];
}

//----- (0046B120) --------------------------------------------------------
int __cdecl sub_46B120(nox_window* win, int a2)
{
    if (!win)
        return -2;
    if (win->field_99)
        sub_46B180(win);
    else
        sub_46A960(win);
    if (a2) {
        nox_window_set_ptrs_97(win, a2);
    } else {
        sub_46A920((int)win);
        win->field_99 = 0;
    }
    return 0;
}

//----- (0046B180) --------------------------------------------------------
void __cdecl sub_46B180(nox_window* win)
{
    nox_window* v2 = win->field_98;
    if (v2) {
        nox_window* v3 = win->field_97;
        v2->field_97 = v3;
        if (v3) {
            v3->field_98 = win->field_98;
        }
    } else {
        if (win->field_97) {
            win->field_99->field_100 = win->field_97;
            win->field_97->field_98 = win->field_98;
            win->field_97 = 0;
        } else {
            win->field_99->field_100 = 0;
        }
    }
}

//----- (0046B200) --------------------------------------------------------
void __cdecl nox_window_set_ptrs_97(nox_window* win, nox_window* a2)
{
    if (!a2)
        return;

    win->field_98 = 0;
    nox_window* v2 = a2->field_100;
    win->field_97 = v2;
    if (v2)
        v2->field_98 = win;
    a2->field_100 = win;
    win->field_99 = a2;
}

//----- (0046B240) --------------------------------------------------------
int __cdecl sub_46B240(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(a1 + 396);
    return result;
}

//----- (0046B250) --------------------------------------------------------
int __cdecl nox_window_is_child(nox_window* a1, nox_window* a2)
{
    if (!a1)
        return 0;
    if (!a2)
        return 0;

    nox_window* cur = a2;
    while (1) {
        cur = cur->field_99;
        if (a1 == cur)
            break;
        if (!cur)
            return 0;
    }
    return 1;
}

//----- (0046B280) --------------------------------------------------------
int __cdecl sub_46B280(int a1, int a2)
{
    if (!a1)
        return -2;
    if (a2)
        * (_DWORD*)(a1 + 52) = a2;
    else
        *(_DWORD*)(a1 + 52) = a1;
    return 0;
}

//----- (0046B2B0) --------------------------------------------------------
int __cdecl sub_46B2B0(int a1)
{
    int result; // eax

    result = a1;
    if (a1)
        result = *(_DWORD*)(a1 + 52);
    return result;
}

//----- (0046B2C0) --------------------------------------------------------
int __cdecl sub_46B2C0(int a1, int (*a2)(int, int, int, int))
{
    if (!a1)
        return -2;
    if (a2)
        * (_DWORD*)(a1 + 376) = a2;
    else
        *(_DWORD*)(a1 + 376) = sub_46B2F0;
    return 0;
}

//----- (0046B2F0) --------------------------------------------------------
int sub_46B2F0(int a1, int a2, int a3, int a4)
{
    return 0;
}

//----- (0046B300) --------------------------------------------------------
int __cdecl sub_46B300(int a1, int (*a2)(int, int, int, int))
{
    if (!a1)
        return -2;
    if (a2)
        * (_DWORD*)(a1 + 372) = a2;
    else
        *(_DWORD*)(a1 + 372) = sub_46B330;
    return 0;
}

//----- (0046B330) --------------------------------------------------------
int sub_46B330(int a1, int a2, int a3, int a4)
{
    return 0;
}

//----- (0046B340) --------------------------------------------------------
int __cdecl sub_46B340(int a1, int (*a2)(int, int))
{
    if (!a1)
        return -2;
    if (a2)
        * (_DWORD*)(a1 + 380) = a2;
    else
        *(_DWORD*)(a1 + 380) = sub_46B370;
    return 0;
}

//----- (0046B370) --------------------------------------------------------
int __cdecl sub_46B370(int a1, int* a2)
{
    int v2; // edx
    int v3; // ecx
    int result; // eax
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (a2[5] != 0x80000000)
        {
            sub_434460(a2[5]);
            sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        }
        result = 1;
    }
    else
    {
        v2 = *(_DWORD*)(a1 + 100);
        xLeft += *(_DWORD*)(a1 + 96);
        v3 = v2 + yTop;
        LOBYTE(v2) = *(_BYTE*)(a1 + 36);
        yTop = v3;
        if (v2 & 2)
            sub_47D2C0(a2[10], xLeft, v3);
        else
            sub_47D2C0(a2[6], xLeft, v3);
        result = 1;
    }
    return result;
}

//----- (0046B430) --------------------------------------------------------
int __cdecl nox_window_set_all_funcs(nox_window* win, int (*a2)(int, int, int, int), int (*draw)(nox_window*, void*), void* a4)
{
    if (!win)
        return -2;
    if (a2)
        win->field_93 = a2;
    else
        win->field_93 = sub_46B330;
    if (draw)
        win->draw = draw;
    else
        win->draw = sub_46B370;
    win->field_96 = a4;
    return 0;
}

//----- (0046B490) --------------------------------------------------------
int __cdecl nox_window_call_field_94(nox_window* win, int a2, int a3, int a4)
{
    if (!win)
        return 0;
    return win->field_94(win, a2, a3, a4);
}

//----- (0046B4C0) --------------------------------------------------------
int __cdecl nox_window_call_field_93(nox_window* win, int a2, int a3, int a4)
{
    if (!win)
        return 0;
    return win->field_93(win, a2, a3, a4);
}

//----- (0046B4F0) --------------------------------------------------------
int sub_46B4F0()
{
    return nox_win_unk2;
}

//----- (0046B500) --------------------------------------------------------
int __cdecl sub_46B500(nox_window* win)
{
    if (win) {
        if (win->flags & 0x400)
            return 0;
    }
    if (nox_win_unk2) {
        if (nox_win_unk2 != win)
            nox_window_call_field_94(nox_win_unk2, 23, 0, 0);
    }
    nox_win_unk2 = win;
    if (!win) {
        nox_win_unk2 = 0;
        return 0;
    }
    if (!nox_window_call_field_94(win, 23, 1, 0))
    {
        nox_window* cur = win;
        while (1) {
            cur = cur->field_99;
            if (!cur)
                break;
            if (nox_window_call_field_94(cur, 23, 1, 0))
                return 0;
        }
        nox_win_unk2 = 0;
    }
    return 0;
}

//----- (0046B580) --------------------------------------------------------
int __cdecl sub_46B580(int a1)
{
    if (!a1)
        return -2;
    if (!(*(_BYTE*)(a1 + 4) & 0x10))
        sub_46B370(a1, (int*)(a1 + 36));
    return 0;
}

//----- (0046B5B0) --------------------------------------------------------
_DWORD* __cdecl sub_46B5B0(_DWORD* a1, int a2, int a3)
{
    _DWORD* result; // eax
    _DWORD* i; // esi
    _DWORD* v5; // ecx
    int v6; // edx
    int j; // edi
    int v8; // ecx

    result = a1;
    if (a1)
    {
    LABEL_2:
        for (i = (_DWORD*)result[100]; i; i = (_DWORD*)i[97])
        {
            v5 = (_DWORD*)i[99];
            v6 = i[4];
            for (j = i[5]; v5; v5 = (_DWORD*)v5[99])
            {
                v6 += v5[4];
                j += v5[5];
            }
            if (a2 >= v6 && a2 <= v6 + (signed int)(i[2]) && a3 >= j && a3 <= j + (signed int)(i[3]))
            {
                v8 = i[1];
                if (v8 & 8)
                {
                    if (!(v8 & 0x10))
                    {
                        result = i;
                        goto LABEL_2;
                    }
                }
            }
        }
    }
    return result;
}

//----- (0046B630) --------------------------------------------------------
int __cdecl sub_46B630(int a1, int a2, int a3)
{
    int result; // eax
    int i; // esi
    _DWORD* v5; // ecx
    int v6; // edx
    int j; // edi

    result = a1;
    if (a1)
    {
    LABEL_2:
        for (i = *(_DWORD*)(result + 400); i; i = *(_DWORD*)(i + 388))
        {
            v5 = *(_DWORD * *)(i + 396);
            v6 = *(_DWORD*)(i + 16);
            for (j = *(_DWORD*)(i + 20); v5; v5 = (_DWORD*)v5[99])
            {
                v6 += v5[4];
                j += v5[5];
            }
            if (a2 >= v6
                && a2 <= v6 + *(_DWORD*)(i + 8)
                && a3 >= j
                && a3 <= j + *(_DWORD*)(i + 12)
                && !(*(_BYTE*)(i + 4) & 0x10))
            {
                result = i;
                goto LABEL_2;
            }
        }
    }
    return result;
}

//----- (0046B6B0) --------------------------------------------------------
void __cdecl sub_46B6B0(unsigned __int8* a1)
{
    int v1; // edi
    unsigned __int8* v2; // esi
    char v3; // bl
    int v4; // eax
    int v5; // ecx
    unsigned __int8 v6; // [esp-8h] [ebp-14h]
    char v7; // [esp+10h] [ebp+4h]

    v1 = nox_win_unk2;
    if (v1)
    {
        v2 = a1;
        if (*a1)
        {
            v3 = 1;
            if (a1[2] != 1)
            {
                v4 = *a1;
                v5 = a1[1];
                v7 = 1;
                if (!nox_window_call_field_93(nox_win_unk2, 21, v4, v5))
                {
                    while (1)
                    {
                        v1 = *(_DWORD*)(v1 + 396);
                        if (!v1)
                            break;
                        if (nox_window_call_field_93(v1, 21, *v2, v2[1]))
                            goto LABEL_9;
                    }
                    v3 = 0;
                    v7 = 0;
                }
            LABEL_9:
                v6 = *v2;
                v2[2] = v3;
                sub_4309B0(v6, v7);
            }
        }
    }
}

//----- (0046B740) --------------------------------------------------------
void sub_46B740()
{
    wchar_t* v0; // edi
    wchar_t* v1; // ebx
    int2* v2; // ebp
    unsigned __int16 v3; // si
    int v4; // eax
    int v5; // edx
    unsigned __int16 v6; // cx
    int v7; // eax
    int v8; // esi
    int v9; // edi
    int v10; // esi
    int v11; // esi
    int v12; // edx
    int v13; // edi
    int v14; // ecx
    int v15; // ebp
    int v16; // ecx
    int v17; // ecx
    int v18; // ecx
    int v19; // ebp
    int v20; // ecx
    _DWORD* v21; // eax
    _DWORD* v22; // eax
    wchar_t* v23; // eax
    _DWORD* v24; // esi
    int v25; // eax
    int v26; // ecx
    int v27; // eax
    int v28; // eax
    int v29; // esi
    int v30; // ecx
    int v31; // eax
    int v32; // eax
    int v33; // eax
    int v34; // ecx
    int v35; // eax
    int v36; // eax
    int v37; // eax
    int i; // ebp
    int v39; // edi
    int v40; // esi
    void(__cdecl * v41)(wchar_t*, wchar_t*, int); // eax
    int v42; // eax
    int v43; // eax
    int v44; // edi
    int v45; // eax
    int v46; // eax
    int v47; // esi
    int v48; // ecx
    int v49; // ecx
    char* v50; // eax
    int v51; // eax
    char* v52; // eax
    int v53; // eax
    int v54; // esi
    wchar_t* v55; // eax
    int v56; // esi
    int v57; // ecx
    int v58; // ecx
    int v59; // edx
    int v60; // [esp+0h] [ebp-2Ch]
    wchar_t* v61; // [esp+4h] [ebp-28h]
    int v62; // [esp+4h] [ebp-28h]
    int v63; // [esp+8h] [ebp-24h]
    int v64; // [esp+Ch] [ebp-20h]
    int2 v65; // [esp+14h] [ebp-18h]
    int v66[4]; // [esp+1Ch] [ebp-10h]

    v0 = 0;
    v1 = 0;
    v63 = 0;
    v61 = 0;
    v64 = 0;
    v2 = sub_4309F0();
    v65.field_0 = (int)v2;
    v3 = v2->field_4;
    v4 = v2[3].field_0;
    v5 = v2[6].field_0;
    v66[1] = v2[4].field_4;
    v6 = v2->field_0;
    v66[0] = v4;
    v7 = v2[1].field_0;
    v66[2] = v5;
    v8 = v6 | (v3 << 16);
    v66[3] = v7;
    v60 = v8;
    sub_4776B0(0);
    if (*(_DWORD*)& byte_5D4594[815132] || sub_477600())
        sub_477610(0);
    else
        sub_477610(14);
    if (nox_win_unk3)
    {
        sub_477610(0);
        *(_DWORD*)& byte_5D4594[1064916] = 0;
        v1 = (wchar_t*)sub_46B5B0(nox_win_unk3, v2->field_0, v2->field_4);
        v62 = 0;
        while (1)
        {
            v9 = v66[v62];
            if (!v9)
            {
                if (!v62 && v2[2].field_4 == 1)
                    nox_window_call_field_93((int)v1, 8, v60, 0);
                goto LABEL_18;
            }
            v10 = (int)v1;
            if (v1)
                break;
            if (nox_window_call_field_93(nox_win_unk3, v9, v60, 0))
                goto LABEL_14;
        LABEL_18:
            if (++v62 >= 4)
                goto LABEL_123;
        }
        while (!nox_window_call_field_93(v10, v9, v60, 0))
        {
            if (v10 != nox_win_unk3)
            {
                v10 = *(_DWORD*)(v10 + 396);
                if (v10)
                    continue;
            }
            goto LABEL_18;
        }
    LABEL_14:
        v66[v62] = 0;
        goto LABEL_18;
    }
    if (*(_DWORD*)& byte_5D4594[1064916])
    {
        sub_477610(0);
        switch (v66[0])
        {
        case 0:
        case 8:
            if (!(*(_BYTE*)(*(_DWORD*)& byte_5D4594[1064916] + 4) & 4) || sub_45D9B0())
                goto LABEL_50;
            v11 = v2[1].field_4;
            v12 = v2[2].field_0;
            v13 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 396);
            if (!v13)
                goto LABEL_41;
            v14 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 16);
            if (v14 + v11 >= 0)
            {
                v15 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 24);
                v16 = *(_DWORD*)(v13 + 8);
                if (v11 + v15 > v16)
                    v11 = v16 - v15;
                v1 = 0;
            }
            else
            {
                v11 = -v14;
            }
            v17 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 20);
            if (v17 + v12 >= 0)
            {
                v19 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 28);
                v20 = *(_DWORD*)(v13 + 12);
                if (v12 + v19 <= v20)
                {
                LABEL_41:
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 16) += v11;
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 20) += v12;
                    v21 = *(_DWORD * *)& byte_5D4594[1064916];
                    if (*(int*)(*(_DWORD*)& byte_5D4594[1064916] + 16) < 0)
                    {
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 16) = 0;
                        v21 = *(_DWORD * *)& byte_5D4594[1064916];
                    }
                    if ((int)v21[5] < 0)
                    {
                        v21[5] = 0;
                        v21 = *(_DWORD * *)& byte_5D4594[1064916];
                    }
                    v21[6] = v21[2] + v21[4];
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 28) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 12)
                        + *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 20);
                    v22 = *(_DWORD * *)& byte_5D4594[1064916];
                    if (*(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 24) > nox_win_width)
                    {
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 24) = nox_win_width;
                        v22 = *(_DWORD * *)& byte_5D4594[1064916];
                    }
                    if (v22[7] > nox_win_height)
                    {
                        v22[7] = nox_win_height;
                        v22 = *(_DWORD * *)& byte_5D4594[1064916];
                    }
                    v2 = (int2*)v65.field_0;
                    v22[4] = v22[6] - v22[2];
                    v8 = v60;
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 20) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 28)
                        - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 12);
                LABEL_50:
                    nox_window_call_field_93(*(int*)& byte_5D4594[1064916], 8, v8, 0);
                    goto LABEL_51;
                }
                v18 = v20 - v19;
            }
            else
            {
                v18 = -v17;
            }
            v12 = v18;
            goto LABEL_41;
        case 6:
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064916] + 4) &= 0xFFFFFFFE;
            if (sub_46AAB0(*(_DWORD * *)& byte_5D4594[1064916], v2->field_0, v2->field_4))
            {
                nox_window_call_field_93(*(int*)& byte_5D4594[1064916], 6, v8, 0);
            }
            else if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[1064916] + 4) & 4)
            {
                nox_window_call_field_93(*(int*)& byte_5D4594[1064916], 6, v8, 0);
            }
            v64 = 1;
            v66[0] = 0;
            goto LABEL_123;
        case 7:
            sub_46B500(*(int*)& byte_5D4594[1064916]);
            nox_window_call_field_93(*(int*)& byte_5D4594[1064916], 7, v8, 0);
            v64 = 1;
            v66[0] = 0;
            goto LABEL_123;
        default:
        LABEL_51:
            v66[0] = 0;
            goto LABEL_123;
        }
    }
    if (*(_DWORD*)& byte_5D4594[1064912])
    {
        v23 = (wchar_t*)sub_46B5B0(**(_DWORD * **)& byte_5D4594[1064912], v2->field_0, v2->field_4);
        goto LABEL_98;
    }
    v24 = *(_DWORD * *)& byte_5D4594[1064888];
    if (!*(_DWORD*)& byte_5D4594[1064888])
        goto LABEL_69;
    while (1)
    {
        v25 = v24[1];
        if (v25 & 0x20)
        {
            if (!(v25 & 0x10))
            {
                v26 = v2->field_0;
                if (v2->field_0 >= (int)v24[4] && v26 <= (int)v24[6])
                {
                    v27 = v2->field_4;
                    if (v27 >= (int)v24[5] && v27 <= (int)v24[7])
                    {
                        v28 = sub_46B630((int)v24, v26, v27);
                        if (!v0 && (*(_DWORD*)(v28 + 384) || *(_WORD*)(v28 + 240)))
                            v0 = (wchar_t*)v28;
                        if (v24[1] & 8)
                            break;
                    }
                }
            }
        }
        v24 = (_DWORD*)v24[97];
        if (!v24)
            goto LABEL_69;
    }
    v61 = v0;
    v1 = (wchar_t*)sub_46B5B0(v24, v2->field_0, v2->field_4);
    if (!v1)
    {
    LABEL_69:
        v29 = *(_DWORD*)& byte_5D4594[1064888];
        if (!*(_DWORD*)& byte_5D4594[1064888])
            goto LABEL_83;
        while (1)
        {
            if (!(*(_BYTE*)(v29 + 4) & 0x70))
            {
                v30 = v2->field_0;
                if (v2->field_0 >= *(int*)(v29 + 16) && v30 <= *(int*)(v29 + 24))
                {
                    v31 = v2->field_4;
                    if (v31 >= *(int*)(v29 + 20) && v31 <= *(int*)(v29 + 28))
                    {
                        v32 = sub_46B630(v29, v30, v31);
                        if (!v0 && (*(_DWORD*)(v32 + 384) || *(_WORD*)(v32 + 240)))
                            v0 = (wchar_t*)v32;
                        if (*(_BYTE*)(v29 + 4) & 8)
                            break;
                    }
                }
            }
            v29 = *(_DWORD*)(v29 + 388);
            if (!v29)
                goto LABEL_83;
        }
        v61 = v0;
        v1 = (wchar_t*)sub_46B5B0((_DWORD*)v29, v2->field_0, v2->field_4);
        if (!v1)
        {
        LABEL_83:
            v1 = *(wchar_t**)& byte_5D4594[1064888];
            if (!*(_DWORD*)& byte_5D4594[1064888])
                goto LABEL_113;
            while (1)
            {
                v33 = *((_DWORD*)v1 + 1);
                if (v33 & 0x40)
                {
                    if (!(v33 & 0x10))
                    {
                        v34 = v2->field_0;
                        if (v2->field_0 >= *((int*)v1 + 4) && v34 <= *((int*)v1 + 6))
                        {
                            v35 = v2->field_4;
                            if (v35 >= *((int*)v1 + 5) && v35 <= *((int*)v1 + 7))
                            {
                                v36 = sub_46B630((int)v1, v34, v35);
                                if (!v0 && (*(_DWORD*)(v36 + 384) || *(_WORD*)(v36 + 240)))
                                    v0 = (wchar_t*)v36;
                                if (v1[2] & 8)
                                    break;
                            }
                        }
                    }
                }
                v1 = (wchar_t*) * ((_DWORD*)v1 + 97);
                if (!v1)
                    goto LABEL_113;
            }
            v61 = v0;
            v23 = (wchar_t*)sub_46B5B0(v1, v2->field_0, v2->field_4);
        LABEL_98:
            v1 = v23;
            if (!v23)
                goto LABEL_113;
            goto LABEL_99;
        }
    }
LABEL_99:
    v37 = *((_DWORD*)v1 + 1);
    v61 = v1;
    if (v37 & 0x200)
    {
        v1 = 0;
    }
    else if (v1)
    {
        sub_477610(0);
        for (i = 0; i < 4; ++i)
        {
            v39 = v66[i];
            if (v39)
            {
                v40 = (int)v1;
                if (nox_window_call_field_93((int)v1, v39, v60, 0))
                {
                LABEL_107:
                    if (!i && v66[0] == 5)
                        * (_DWORD*)& byte_5D4594[1064916] = v40;
                    v66[i] = 0;
                }
                else
                {
                    while (1)
                    {
                        v40 = *(_DWORD*)(v40 + 396);
                        if (!v40)
                            break;
                        if (nox_window_call_field_93(v40, v39, v60, 0))
                            goto LABEL_107;
                    }
                }
            }
        }
        v0 = v61;
        v2 = (int2*)v65.field_0;
    }
LABEL_113:
    if (!v0 && !sub_46C2A0((int)v1))
        v0 = v1;
    if (sub_430B30())
    {
        if (v0)
        {
            v41 = (void(__cdecl*)(wchar_t*, wchar_t*, int)) * ((_DWORD*)v0 + 96);
            if (v41)
            {
                v41(v0, v0 + 18, v60);
            }
            else if (v0[120])
            {
                sub_4776B0(v0 + 120);
            }
        }
        else
        {
            v63 = 1;
        }
    }
LABEL_123:
    if (!*(_DWORD*)& byte_5D4594[1064916] && v1 != *(wchar_t**)& byte_5D4594[1064900])
    {
        if (nox_win_unk3)
        {
            if (nox_window_is_child(nox_win_unk3, *(int*)& byte_5D4594[1064900]))
                nox_window_call_field_93(*(int*)& byte_5D4594[1064900], 18, v60, 0);
        }
        else if (*(_DWORD*)& byte_5D4594[1064900])
        {
            nox_window_call_field_93(*(int*)& byte_5D4594[1064900], 18, v60, 0);
        }
        if (v1)
            nox_window_call_field_93((int)v1, 17, v60, 0);
        *(_DWORD*)& byte_5D4594[1064900] = v1;
    }
    if (sub_4356B0() == 3
        && !*(_DWORD*)& byte_5D4594[1064940]
        && !sub_4372B0()
        && !sub_413A50()
        && !sub_477600()
        && !sub_4372E0())
    {
        v42 = sub_4675B0();
        if (v42 == 5)
        {
            sub_477610(6);
            goto LABEL_201;
        }
        if (v42 == 6)
        {
            sub_477610(8);
            goto LABEL_201;
        }
        v43 = sub_476F90();
        v44 = v43;
        if (v43)
        {
            if (!(*(_DWORD*)(v43 + 112) & 0x400006)
                || sub_4C3220(v43)
                || *(_DWORD*)(v44 + 112) & 2 && *(_BYTE*)(v44 + 116) & 8
                || *(_DWORD*)(v44 + 112) & 2 && *(_BYTE*)(v44 + 280) & 0x10)
            {
                v46 = sub_4676A0();
                v47 = *(_DWORD*)& byte_5D4594[1064888];
                if (*(_DWORD*)& byte_5D4594[1064888])
                {
                    while (1)
                    {
                        if (!(*(_BYTE*)(v47 + 4) & 0x10)
                            && v2->field_0 >= *(int*)(v47 + 16)
                            && v2->field_0 <= *(int*)(v47 + 24))
                        {
                            v48 = v2->field_4;
                            if (v48 >= *(int*)(v47 + 20) && v48 <= *(int*)(v47 + 28))
                                break;
                        }
                        v47 = *(_DWORD*)(v47 + 388);
                        if (!v47)
                            goto LABEL_175;
                    }
                    if (v47 == v46
                        && ((v49 = v2->field_4,
                            v65.field_0 = v2->field_0,
                            v65.field_4 = v49,
                            v50 = sub_4676B0(),
                            v51 = sub_4281F0(&v65, (int4*)v50),
                            v51)
                            || (v52 = sub_4676C0(), v53 = sub_4281F0(&v65, (int4*)v52), v53)))
                    {
                        v63 = 1;
                    }
                    else if (v47 && sub_46C2A0(v47) != 1)
                    {
                        goto LABEL_201;
                    }
                }
            LABEL_175:
                sub_435670(&v65);
                v54 = (v65.field_0 - *(_DWORD*)(v44 + 12)) * (v65.field_0 - *(_DWORD*)(v44 + 12))
                    + (v65.field_4 - *(_DWORD*)(v44 + 16)) * (v65.field_4 - *(_DWORD*)(v44 + 16));
                if ((int) * (_DWORD*)(v44 + 112) >= 0 || sub_477680())
                {
                    if (v54 < 15625)
                    {
                        if (*(_DWORD*)& byte_5D4594[2618908])
                        {
                            v57 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 3680);
                            if (!(v57 & 0x200) && !sub_478030())
                            {
                                if (*(_DWORD*)(v44 + 112) & 2 && *(_BYTE*)(v44 + 280) & 0x10)
                                {
                                    sub_477610(4);
                                }
                                else if (*(_DWORD*)(v44 + 112) & 2 && *(_BYTE*)(v44 + 116) & 8)
                                {
                                    sub_477610(3);
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (v63 == 1)
                    {
                        v55 = sub_4BF050((wchar_t*)v44);
                        sub_4776B0(v55);
                    }
                    if (v54 >= 5625)
                    {
                        sub_477610(15);
                    }
                    else
                    {
                        if (sub_40A5C0(6144) || sub_57B450((int*)v44))
                            sub_477610(2);
                        else
                            sub_477610(16);
                        v56 = sub_430AF0();
                        if (v66[v56] == sub_430B00())
                        {
                            sub_46C140(v44);
                            v66[sub_430AF0()] = 0;
                        }
                    }
                }
            }
            else
            {
                v45 = *(_DWORD*)& byte_5D4594[1064944];
                if (!*(_DWORD*)& byte_5D4594[1064944])
                {
                    v45 = sub_44CFC0((CHAR*)& byte_587000[143184]);
                    *(_DWORD*)& byte_5D4594[1064944] = v45;
                }
                if (*(_DWORD*)(v44 + 112) & 0x400000 && (*(_BYTE*)(v44 + 116) & 0x80) && !(*(_BYTE*)(v44 + 280) & 0xC)
                    || *(_DWORD*)(v44 + 108) == v45 && !*(_DWORD*)(v44 + 276))
                {
                    sub_435670(&v65);
                    if ((v65.field_0 - *(_DWORD*)(v44 + 12)) * (v65.field_0 - *(_DWORD*)(v44 + 12))
                        + (v65.field_4 - *(_DWORD*)(v44 + 16)) * (v65.field_4 - *(_DWORD*)(v44 + 16)) < 5625
                        && (*(_DWORD*)(v44 + 120) & 0x1000000) == 0x1000000
                        && !(*(_BYTE*)(v44 + 280) & 0xC))
                    {
                        sub_477610(13);
                    }
                }
            }
        }
        else if (sub_479590() == 2)
        {
            sub_477610(11);
        }
        else if (sub_479590() == 3)
        {
            sub_477610(12);
        }
    }
LABEL_201:
    v58 = v66[1];
    v59 = v66[2];
    v2[3].field_0 = v66[0];
    v2[1].field_0 = v66[3];
    v2[4].field_4 = v58;
    v2[6].field_0 = v59;
    if (v64 == 1)
        * (_DWORD*)& byte_5D4594[1064916] = 0;
    sub_46C200();
}
// 46BF71: variable 'v51' is possibly undefined
// 46BF88: variable 'v53' is possibly undefined

//----- (0046C140) --------------------------------------------------------
void __cdecl sub_46C140(int a1)
{
    int v2; // eax
    wchar_t* v3; // eax
    int v4; // [esp+0h] [ebp-4h]

    if (!*(_DWORD*)& byte_5D4594[1064928])
    {
        *(_DWORD*)& byte_5D4594[1064928] = sub_44CFC0((CHAR*)& byte_587000[143192]);
        *(_DWORD*)& byte_5D4594[1064932] = sub_44CFC0((CHAR*)& byte_587000[143200]);
        *(_DWORD*)& byte_5D4594[1064936] = sub_44CFC0((CHAR*)& byte_587000[143216]);
    }
    if (a1)
    {
        v2 = *(_DWORD*)(a1 + 108);
        if (v2 == *(_DWORD*)& byte_5D4594[1064928]
            || v2 == *(_DWORD*)& byte_5D4594[1064932]
            || v2 == *(_DWORD*)& byte_5D4594[1064936]
            || sub_467B00(v2, 1))
        {
            LOBYTE(v4) = 115;
            *(_WORD*)((char*)& v4 + 1) = sub_578B00(a1);
            sub_40EBC0(31, 0, &v4, 3);
        }
        else
        {
            sub_452D80(925, 100);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[143276], 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c", 83);
            sub_445490(v3);
        }
    }
}

//----- (0046C200) --------------------------------------------------------
void sub_46C200()
{
    int v0; // esi
    bool v1; // zf
    int v2; // edi

    v0 = *(_DWORD*)& byte_5D4594[1064896];
    v1 = *(_DWORD*)& byte_5D4594[1064896] == 0;
    *(_DWORD*)& byte_5D4594[1064896] = 0;
    if (!v1)
    {
        do
        {
            v2 = *(_DWORD*)(v0 + 388);
            if (nox_win_unk3 == v0)
                sub_46ADE0(v0);
            if (nox_win_unk2 == v0)
                sub_46B500(0);
            if (*(_DWORD*)& byte_5D4594[1064912] && v0 == **(_DWORD * *)& byte_5D4594[1064912])
                sub_46C6E0(**(_DWORD * *)& byte_5D4594[1064912]);
            if (*(_DWORD*)& byte_5D4594[1064900] == v0)
                * (_DWORD*)& byte_5D4594[1064900] = 0;
            if (*(_DWORD*)& byte_5D4594[1064916] == v0)
                * (_DWORD*)& byte_5D4594[1064916] = 0;
            nox_window_call_field_94(v0, 2, 0, 0);
            sub_414330(nox_alloc_window, (_QWORD*)v0);
            v0 = v2;
        } while (v2);
    }
}

//----- (0046C2A0) --------------------------------------------------------
int __cdecl sub_46C2A0(int a1)
{
    int v2; // eax

    if (!a1)
        return 1;
    if (*(_BYTE*)(a1 + 4) & 0x10)
        return 1;
    v2 = *(_DWORD*)(a1 + 396);
    if (v2)
    {
        while (!(*(_BYTE*)(v2 + 4) & 0x10))
        {
            v2 = *(_DWORD*)(v2 + 396);
            if (!v2)
                return 0;
        }
        return 1;
    }
    return 0;
}

//----- (0046C2E0) --------------------------------------------------------
void mainloop_draw()
{
    if (nox_win_unk4) {
        // background and some UI parts
        nox_window* v1 = nox_win_unk4;
        nox_window* v2 = 0;
        do {
            v2 = v1->field_98;
            if (v1->flags & NOX_WIN_LAYER_BACK) {
                nox_window_draw_recursive(v1);
            }
            v1 = v2;
        } while (v2);
    }
    if (nox_win_unk4) {
        nox_window* v3 = nox_win_unk4;
        nox_window* v4 = 0;
        do {
            v4 = v3->field_98;
            if ((v3->flags & (NOX_WIN_LAYER_BACK | NOX_WIN_LAYER_FRONT)) == 0) {
                nox_window_draw_recursive(v3);
            }
            v3 = v4;
        } while (v4);
    }
    if (nox_win_unk4) {
        nox_window* v5 = nox_win_unk4;
        nox_window* v6 = 0;
        do {
            v6 = v5->field_98;
            if (v5->flags & NOX_WIN_LAYER_FRONT)
                nox_window_draw_recursive(v5);
            v5 = v6;
        } while (v6);
    }
}

//----- (0046C370) --------------------------------------------------------
int __cdecl nox_window_draw_recursive(nox_window* win)
{
    if (!win)
        return -2;
    if (win->flags & NOX_WIN_HIDDEN)
        return 0;

    if (win->draw)
        win->draw(win, win->field_9);
    if ((win->flags & 0x1000) == 0x1000)
        sub_4AA030(win, win->field_9);

    for (nox_window* i = win->field_100; i; i = i->field_97)
        nox_window_draw_recursive(i);
    return 0;
}

//----- (0046C3E0) --------------------------------------------------------
nox_window* __cdecl nox_window_new(nox_window* a1, int flags, int a3, int a4, int w, int h, int (*fnc)(int, int, int, int))
{
    nox_alloc_class* al = nox_alloc_window;
    if (!al) {
        al = nox_new_alloc_class("Window", sizeof(nox_window), 576);
        nox_alloc_window = al;
    }
    if (!al)
        return 0;

    nox_window* win = (nox_window*)nox_alloc_class_new_obj_zero(al);
    if (!win)
        return 0;

    if (a1) {
        nox_window_set_ptrs_97(win, a1);
    } else {
        sub_46A920((int) win);
    }
    win->field_0 = 0;
    win->flags = flags;
    win->width = w;
    win->height = h;
    win->field_4 = a3;
    win->field_5 = a4;
    *((_WORD*)win + 120) = 0;
    win->field_6 = w + a3;
    win->field_7 = h + a4;
    sub_46A9F0(win);
    win->draw = sub_46B370;
    win->field_93 = sub_46B330;
    if (fnc) {
        win->field_94 = fnc;
        nox_window_call_field_94((int)win, 1, 0, 0);
    } else {
        win->field_94 = sub_46B2F0;
    }
    memset(win->field_9, 0, 332);
    win->field_92 = 0;
    return win;
}

//----- (0046C4E0) --------------------------------------------------------
int __cdecl sub_46C4E0(_DWORD* a1)
{
    int v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // edi

    if (!a1)
        return -2;
    v2 = a1[1];
    if (!(v2 & 0x800))
    {
        BYTE1(v2) |= 8u;
        a1[1] = v2;
        sub_46AC60((int)a1);
        if (nox_win_unk3 == a1)
            sub_46ADE0((int)a1);
        if (nox_win_unk2 == a1)
            sub_46B500(0);
        if (*(_DWORD*)& byte_5D4594[1064912] && a1 == **(_DWORD * **)& byte_5D4594[1064912])
            sub_46C6E0(**(_DWORD * *)& byte_5D4594[1064912]);
        if (*(_DWORD * *)& byte_5D4594[1064900] == a1)
            * (_DWORD*)& byte_5D4594[1064900] = 0;
        if (*(_DWORD * *)& byte_5D4594[1064916] == a1)
            * (_DWORD*)& byte_5D4594[1064916] = 0;
        v3 = (_DWORD*)a1[100];
        if (v3)
        {
            do
            {
                v4 = (_DWORD*)v3[97];
                sub_46C4E0(v3);
                v3 = v4;
            } while (v4);
        }
        if (a1[99])
            sub_46B180(a1);
        else
            sub_46A960((int)a1);
        a1[98] = 0;
        a1[97] = *(_DWORD*)& byte_5D4594[1064896];
        *(_DWORD*)& byte_5D4594[1064896] = a1;
    }
    return 0;
}

//----- (0046C5D0) --------------------------------------------------------
int sub_46C5D0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi

    v0 = *(_DWORD * *)& byte_5D4594[1064888];
    if (*(_DWORD*)& byte_5D4594[1064888])
    {
        do
        {
            v1 = (_DWORD*)v0[97];
            sub_46C4E0(v0);
            v0 = v1;
        } while (v1);
    }
    sub_46C200();
    sub_4144D0(nox_alloc_window);
    return 0;
}

//----- (0046C610) --------------------------------------------------------
int sub_46C610()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax
    char v3[332]; // [esp+0h] [ebp-14Ch]

    v0 = nox_window_new(0, 12, 100, 100, 200, 200, 0);
    *(_DWORD*)& v3[20] = 4;
    sub_46AF80_copy_window_part((int)v0, v3);
    v1 = nox_window_new(0, 12, 150, 150, 200, 200, 0);
    *(_DWORD*)& v3[20] = 8;
    sub_46AF80_copy_window_part((int)v1, v3);
    return 1;
}

//----- (0046C690) --------------------------------------------------------
int __cdecl sub_46C690(int a1)
{
    _DWORD* v2; // eax

    if (!a1)
        return -2;
    if (*(_DWORD*)(a1 + 396))
        return -3;
    v2 = nox_malloc(8u);
    if (!v2)
        return -1;
    *v2 = a1;
    v2[1] = *(_DWORD*)& byte_5D4594[1064912];
    *(_DWORD*)& byte_5D4594[1064912] = v2;
    return 0;
}

//----- (0046C6E0) --------------------------------------------------------
int __cdecl sub_46C6E0(int a1)
{
    int v2; // esi

    if (!a1)
        return -2;
    if (!*(_DWORD*)& byte_5D4594[1064912] || **(_DWORD * *)& byte_5D4594[1064912] != a1)
        return -1;
    v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1064912] + 4);
    free(*(LPVOID*)& byte_5D4594[1064912]);
    *(_DWORD*)& byte_5D4594[1064912] = v2;
    return 0;
}

//----- (0046C720) --------------------------------------------------------
int sub_46C720()
{
    return *(_DWORD*)& byte_5D4594[1064916];
}

//----- (0046C730) --------------------------------------------------------
int sub_46C730()
{
    int result; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    int i; // esi
    _DWORD* v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax

    result = nox_new_window_from_file("SelChar.wnd", sub_46C920);
    *(_DWORD*)& byte_5D4594[1082856] = result;
    if (result)
    {
        *(_DWORD*)(result + 4) |= 0x20u;
        sub_46B300(*(int*)& byte_5D4594[1082856], sub_46CCA0);
        *(_DWORD*)& byte_5D4594[1082860] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 510);
        *(_DWORD*)& byte_5D4594[1082864] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 511);
        *(_DWORD*)& byte_5D4594[1082868] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 512);
        sub_46B2C0(*(int*)& byte_5D4594[1082860], sub_46C920);
        sub_46B120(*(_DWORD * *)& byte_5D4594[1082864], *(int*)& byte_5D4594[1082860]);
        sub_46B120(*(_DWORD * *)& byte_5D4594[1082868], *(int*)& byte_5D4594[1082860]);
        *(_DWORD*)& byte_5D4594[1082872] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 501);
        *(_DWORD*)& byte_5D4594[1082876] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 502);
        *(_DWORD*)& byte_5D4594[1082880] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 503);
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 504);
        nox_window_set_hidden((int)v1, 1);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 505);
        nox_window_set_hidden((int)v2, 1);
        for (i = 500; i <= 512; ++i)
        {
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], i);
            if (v4)
                sub_46AD60((int)v4, 1024);
        }
        v5 = loadString_sub_40F1D0((char*)& byte_587000[143360], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 341);
        sub_46AEE0(*(int*)& byte_5D4594[1082872], (int)v5);
        v6 = loadString_sub_40F1D0((char*)& byte_587000[143408], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 342);
        sub_46AEE0(*(int*)& byte_5D4594[1082876], (int)v6);
        sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1082856],
            (nox_win_width - *(int*)(*(_DWORD*)& byte_5D4594[1082856] + 8)) / 2,
            0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1082856], 1);
        sub_46ABB0(*(int*)& byte_5D4594[1082856], 0);
        result = 1;
    }
    return result;
}

//----- (0046C920) --------------------------------------------------------
int __cdecl sub_46C920(_DWORD* a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // esi
    int v6; // eax
    wchar_t* v7; // eax
    int v8; // edx
    int v9; // eax
    _DWORD* v10; // eax
    wchar_t* v11; // eax
    wchar_t* v12; // [esp-10h] [ebp-24h]
    wchar_t* v13; // [esp-10h] [ebp-24h]
    char v14[12]; // [esp+8h] [ebp-Ch]

    if (a2 != 16391)
    {
        if (a2 == 16400)
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[1082860], 16403, a4, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1082864], 16403, a4, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1082868], 16403, a4, 0);
            return 0;
        }
        return 0;
    }
    v5 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    if (v5 == 501)
    {
        v8 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1082864] + 32) + 48);
        if (v8 >= 0)
        {
            v9 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 120);
            if ((v9 & 0x8000) != 0)
            {
                v10 = sub_46B0C0(a1, 501);
                sub_46ABB0((int)v10, 0);
                return 0;
            }
            if (strlen((const char*)& byte_5D4594[1278 * v8 + 1064952]))
            {
                sub_4DC970((char*)& byte_5D4594[1278 * v8 + 1064952], (char*)& byte_5D4594[1082840]);
                sub_46ADE0(*(int*)& byte_5D4594[1082856]);
                v13 = loadString_sub_40F1D0((char*)& byte_587000[143456], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 184);
                v11 = loadString_sub_40F1D0((char*)& byte_587000[143524], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 183);
                sub_449A10(*(int*)& byte_5D4594[1082856], (int)v11, (int)v13, 56, sub_46CC70, sub_46CC90);
                return 0;
            }
            if (v8)
                nox_sprintf(v14, "SAVE%04d", v8);
            else
                strcpy(v14, "AUTOSAVE");
            sub_4DB130(v14);
            sub_4DB170(1, 0, 0);
            goto LABEL_25;
        }
        return 0;
    }
    if (v5 != 502)
    {
        if (v5 == 503)
        {
            if (sub_450560())
            {
                sub_450580();
                sub_43DDA0();
                sub_43DDD0(0);
                sub_43DE60();
                sub_446060();
                sub_46D6F0();
                return 0;
            }
        LABEL_25:
            sub_46D6F0();
            return 0;
        }
        return 0;
    }
    v6 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1082864] + 32) + 48);
    if (v6 >= 0 && strlen((const char*)& byte_5D4594[1278 * v6 + 1064952]))
    {
        if (sub_4372B0())
        {
            sub_46CBD0();
        }
        else
        {
            v12 = loadString_sub_40F1D0((char*)& byte_587000[143616], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 233);
            v7 = loadString_sub_40F1D0((char*)& byte_587000[143680], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 232);
            sub_449A10(0, (int)v7, (int)v12, 24, sub_46CBD0, sub_44A400);
        }
        result = 0;
    }
    else
    {
        sub_452D80(925, 100);
        result = 0;
    }
    return result;
}

//----- (0046CBD0) --------------------------------------------------------
int sub_46CBD0()
{
    int result; // eax
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-Ch] [ebp-1Ch]
    char v3[12]; // [esp+4h] [ebp-Ch]

    result = 0;
    if (strlen((const char*)& byte_5D4594[1278 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1082864] + 32) + 48)
        + 1064952]))
    {
        sub_4DC970(
            (char*)& byte_5D4594[1278 * *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1082864] + 32) + 48) + 1064952],
            v3);
        if (!sub_4DB790(v3))
        {
            v2 = loadString_sub_40F1D0((char*)& byte_587000[143736], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 75);
            v1 = loadString_sub_40F1D0((char*)& byte_587000[143788], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 74);
            sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
        }
        if (sub_450560())
            sub_4505B0();
        sub_44A400();
        result = sub_46D6F0();
    }
    return result;
}

//----- (0046CC70) --------------------------------------------------------
int sub_46CC70()
{
    sub_4DB130((const char*)& byte_5D4594[1082840]);
    sub_4DB170(1, 0, 0);
    return sub_46D6F0();
}

//----- (0046CC90) --------------------------------------------------------
int sub_46CC90()
{
    return sub_46ADC0(*(int*)& byte_5D4594[1082856]);
}

//----- (0046CCA0) --------------------------------------------------------
int sub_46CCA0(int a1, int a2, int a3, int a4)
{
    return 1;
}

//----- (0046CCB0) --------------------------------------------------------
int sub_46CCB0()
{
    int result; // eax

    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1082856]);
    result = 0;
    *(_DWORD*)& byte_5D4594[1082856] = 0;
    *(_DWORD*)& byte_5D4594[1082864] = 0;
    *(_DWORD*)& byte_5D4594[1082868] = 0;
    return result;
}

//----- (0046CCD0) --------------------------------------------------------
int __cdecl sub_46CCD0(int a1, int a2)
{
    int result; // eax
    char* v3; // esi
    char* v4; // eax
    char v5[12]; // [esp+Ch] [ebp-18h]
    char v6[12]; // [esp+18h] [ebp-Ch]

    sub_4DC970((char*)(a1 + 4), v5);
    sub_4DC970((char*)(a1 + 4), v6);
    if (!strcmp(v5, "AUTOSAVE"))
        return -1;
    if (!strcmp(v6, "AUTOSAVE"))
        return 1;
    v3 = sub_4DC9B0((char*)(a1 + 4));
    v4 = sub_4DC9B0((char*)(a2 + 4));
    if (v3 == v4)
        result = 0;
    else
        result = (int)v3 <= (int)v4 ? -1 : 1;
    return result;
}

//----- (0046CD70) --------------------------------------------------------
int __cdecl sub_46CD70(_BYTE* a1)
{
    char v2[12]; // [esp+0h] [ebp-Ch]

    if (*a1 & 8)
        return 10;
    sub_4DC970(a1 + 4, v2);
    return (strcmp(v2, "AUTOSAVE") != 0) + 13;
}

//----- (0046CDC0) --------------------------------------------------------
int __cdecl sub_46CDC0(int a1)
{
    int v1; // ebp
    int v2; // ebx
    const SYSTEMTIME* v3; // esi
    struct _FILETIME FileTime; // [esp+10h] [ebp-10h]
    FILETIME FileTime2; // [esp+18h] [ebp-8h]

    v1 = -1;
    v2 = 0;
    v3 = (const SYSTEMTIME*)(a1 + 1188);
    do
    {
        if (strlen((const char*)& v3[-74]))
        {
            SystemTimeToFileTime(v3, &FileTime);
            if (v1 == -1 || CompareFileTime(&FileTime, &FileTime2) == 1)
            {
                v1 = v2;
                FileTime2 = FileTime;
            }
        }
        ++v2;
        v3 = (const SYSTEMTIME*)((char*)v3 + 1278);
    } while (v2 < 14);
    return v1;
}

//----- (0046CE40) --------------------------------------------------------
int __cdecl sub_46CE40(int a1, int a2, int a3, _BYTE* a4)
{
    int v4; // ebp
    char* v5; // eax
    _BYTE* v6; // ebx
    int v7; // esi
    _BYTE* v8; // edi
    int v9; // esi
    int v10; // ebx
    wchar_t* v11; // eax
    wchar_t* v12; // eax
    wchar_t* v13; // eax
    wchar_t* v14; // eax
    char v15; // al
    char v16; // al
    wchar_t* v17; // eax
    char v18; // al
    char v19; // al
    char v20; // al
    int v21; // esi
    _DWORD* v22; // eax
    _DWORD* v23; // eax
    _DWORD* v24; // eax
    int result; // eax
    int v26; // esi
    wchar_t* v27; // [esp-14h] [ebp-1238h]
    wchar_t* v28; // [esp-14h] [ebp-1238h]
    wchar_t* v29; // [esp-14h] [ebp-1238h]
    wchar_t* v30; // [esp-14h] [ebp-1238h]
    wchar_t* v31; // [esp-14h] [ebp-1238h]
    wchar_t* v32; // [esp-14h] [ebp-1238h]
    wchar_t* v33; // [esp-14h] [ebp-1238h]
    wchar_t* v34; // [esp-14h] [ebp-1238h]
    wchar_t* v35; // [esp-14h] [ebp-1238h]
    wchar_t* v36; // [esp-14h] [ebp-1238h]
    wchar_t* v37; // [esp-14h] [ebp-1238h]
    wchar_t* v38; // [esp-14h] [ebp-1238h]
    wchar_t* v39; // [esp-4h] [ebp-1228h]
    int v40; // [esp+14h] [ebp-1210h]
    char v41[12]; // [esp+18h] [ebp-120Ch]
    wchar_t v42[512]; // [esp+24h] [ebp-1200h]
    CHAR DateStr[256]; // [esp+424h] [ebp-E00h]
    CHAR TimeStr[256]; // [esp+524h] [ebp-D00h]
    char v45[1024]; // [esp+624h] [ebp-C00h]
    CHAR PathName[1024]; // [esp+A24h] [ebp-800h]
    CHAR Buffer[1024]; // [esp+E24h] [ebp-400h]

    v4 = 0;
    GetCurrentDirectoryA(0x400u, &Buffer);
    v5 = sub_409E10();
    nox_sprintf(&PathName, "%s\\Save\\", v5);
    CreateDirectoryA(&PathName, 0);
    nox_window_call_field_94(a1, 16399, 0, 0);
    nox_window_call_field_94(a2, 16399, 0, 0);
    nox_window_call_field_94(a3, 16399, 0, 0);
    nox_sprintf(&v45, "%sAUTOSAVE\\Player.plr", &PathName);
    v6 = a4;
    if (sub_41A000(&v45, a4))
        v4 = 1;
    v7 = 1;
    v8 = a4 + 1278;
    do
    {
        nox_sprintf(&v45, "%sSAVE%04d\\Player.plr", &PathName, v7);
        if (sub_41A000(&v45, v8))
            ++v4;
        ++v7;
        v8 += 1278;
    } while (v7 < 14);
    v9 = 0;
    v40 = 0;
    while (1)
    {
        v10 = (int)& v6[1278 * v9];
        if (strlen((const char*)(v10 + 4)))
        {
            sub_4DC970((char*)(v10 + 4), &v41);
            nox_sprintf(
                &DateStr,
                "nox.str:%s",
                *(_DWORD*)& byte_587000[4 * *(unsigned __int8*)(v10 + 1274) + 29456]);
            v39 = loadString_sub_40F1D0(&DateStr, 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 667);
            v13 = loadString_sub_40F1D0((char*)& byte_587000[144092], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 666);
            nox_swprintf(&v42, v13, v10 + 1224, v39);
            if (!strcmp(&v41, "AUTOSAVE"))
            {
                nox_wcscat(&v42, L" ");
                v14 = loadString_sub_40F1D0((char*)& byte_587000[144148], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 674);
                nox_wcscat(&v42, v14);
            LABEL_56:
                v21 = sub_46CD70((_BYTE*)v10);
                nox_window_call_field_94(a1, 16397, (int)& byte_587000[145320], v21);
                nox_window_call_field_94(a3, 16397, (int)& v42, v21);
                GetDateFormatA(0x800u, 1u, (const SYSTEMTIME*)(v10 + 1188), 0, &DateStr, 256);
                GetTimeFormatA(0x800u, 0xEu, (const SYSTEMTIME*)(v10 + 1188), 0, &TimeStr, 256);
                nox_swprintf(&v42, L"%S, %S ", &DateStr, &TimeStr);
                nox_window_call_field_94(a2, 16397, (int)& v42, v21);
                v9 = v40;
                goto LABEL_57;
            }
            nox_wcscat(&v42, L" - ");
            v15 = *(_BYTE*)(v10 + 1277);
            switch (v15)
            {
            case 1:
                v16 = *(_BYTE*)(v10 + 1274);
                if (!v16)
                {
                    v27 = loadString_sub_40F1D0((char*)& byte_587000[144208], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 688);
                    nox_wcscat(&v42, v27);
                    goto LABEL_56;
                }
                if (v16 != 1)
                {
                    v28 = loadString_sub_40F1D0((char*)& byte_587000[144316], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 692);
                    nox_wcscat(&v42, v28);
                    goto LABEL_56;
                }
                v17 = loadString_sub_40F1D0((char*)& byte_587000[144268], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 690);
                break;
            case 2:
                v18 = *(_BYTE*)(v10 + 1274);
                if (!v18)
                {
                    v29 = loadString_sub_40F1D0((char*)& byte_587000[144376], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 699);
                    nox_wcscat(&v42, v29);
                    goto LABEL_56;
                }
                if (v18 != 1)
                {
                    v30 = loadString_sub_40F1D0((char*)& byte_587000[144488], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 703);
                    nox_wcscat(&v42, v30);
                    goto LABEL_56;
                }
                v17 = loadString_sub_40F1D0((char*)& byte_587000[144432], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 701);
                break;
            case 3:
                v19 = *(_BYTE*)(v10 + 1274);
                if (!v19)
                {
                    v31 = loadString_sub_40F1D0((char*)& byte_587000[144536], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 710);
                    nox_wcscat(&v42, v31);
                    goto LABEL_56;
                }
                if (v19 != 1)
                {
                    v32 = loadString_sub_40F1D0((char*)& byte_587000[144656], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 714);
                    nox_wcscat(&v42, v32);
                    goto LABEL_56;
                }
                v17 = loadString_sub_40F1D0((char*)& byte_587000[144596], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 712);
                break;
            case 4:
                v33 = loadString_sub_40F1D0((char*)& byte_587000[144712], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 718);
                nox_wcscat(&v42, v33);
                goto LABEL_56;
            case 5:
                v17 = loadString_sub_40F1D0((char*)& byte_587000[144772], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 720);
                break;
            case 6:
                v34 = loadString_sub_40F1D0((char*)& byte_587000[144832], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 722);
                nox_wcscat(&v42, v34);
                goto LABEL_56;
            case 7:
                v35 = loadString_sub_40F1D0((char*)& byte_587000[144884], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 724);
                nox_wcscat(&v42, v35);
                goto LABEL_56;
            case 8:
                v17 = loadString_sub_40F1D0((char*)& byte_587000[144940], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 726);
                break;
            case 9:
                v36 = loadString_sub_40F1D0((char*)& byte_587000[145000], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 728);
                nox_wcscat(&v42, v36);
                goto LABEL_56;
            case 10:
                v37 = loadString_sub_40F1D0((char*)& byte_587000[145064], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 730);
                nox_wcscat(&v42, v37);
                goto LABEL_56;
            case 11:
                v20 = *(_BYTE*)(v10 + 1274);
                if (v20)
                {
                    if (v20 == 1)
                        v38 = loadString_sub_40F1D0((char*)& byte_587000[145184], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 737);
                    else
                        v38 = loadString_sub_40F1D0((char*)& byte_587000[145232], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 739);
                    nox_wcscat(&v42, v38);
                    goto LABEL_56;
                }
                v17 = loadString_sub_40F1D0((char*)& byte_587000[145124], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 735);
                break;
            default:
                v17 = loadString_sub_40F1D0((char*)& byte_587000[145292], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 743);
                break;
            }
            nox_wcscat(&v42, v17);
            goto LABEL_56;
        }
        nox_window_call_field_94(a1, 16397, (int)& byte_587000[143900], 3);
        if (v9)
        {
            v11 = loadString_sub_40F1D0((char*)& byte_587000[143948], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 645);
            nox_window_call_field_94(a2, 16397, (int)v11, 3);
            v12 = loadString_sub_40F1D0((char*)& byte_587000[143996], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 650);
            nox_window_call_field_94(a3, 16397, (int)v12, 3);
        }
        else
        {
            nox_window_call_field_94(a2, 16397, (int)& byte_587000[143904], 3);
            nox_window_call_field_94(a3, 16397, (int)& byte_587000[143908], 3);
        }
    LABEL_57:
        v40 = ++v9;
        if (v9 >= 14)
            break;
        v6 = a4;
    }
    v22 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 503);
    if (v4 <= 0)
    {
        sub_46ABB0((int)v22, 0);
        v24 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 502);
        sub_46ABB0((int)v24, 0);
        sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 501);
    }
    else
    {
        sub_46ABB0((int)v22, 1);
        v23 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 502);
        sub_46ABB0((int)v23, 1);
    }
    result = sub_46CDC0((int)a4);
    v26 = result;
    if (result != -1)
    {
        nox_window_call_field_94(a1, 16403, result, 0);
        nox_window_call_field_94(a2, 16403, v26, 0);
        result = nox_window_call_field_94(a3, 16403, v26, 0);
    }
    return result;
}

//----- (0046D580) --------------------------------------------------------
int sub_46D580()
{
    int result; // eax
    _DWORD* v1; // esi
    int v2; // eax
    wchar_t* v3; // eax
    _DWORD* v4; // esi
    wchar_t* v5; // eax
    wchar_t* v6; // eax

    result = sub_40A5C0(4096);
    if (!result)
    {
        memset(&byte_5D4594[1064948], 0, 0x45E4u);
        sub_46CE40(
            *(int*)& byte_5D4594[1082860],
            *(int*)& byte_5D4594[1082864],
            *(int*)& byte_5D4594[1082868],
            &byte_5D4594[1064948]);
        sub_46A8C0(*(int*)& byte_5D4594[1082856]);
        sub_46ABB0(*(int*)& byte_5D4594[1082856], 1);
        sub_46ADC0(*(int*)& byte_5D4594[1082856]);
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 501);
        if (sub_450560() && !sub_450570()
            || (v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 276), v2 == 2)
            || v2 == 1
            || v2 == 51)
        {
            sub_46ABB0((int)v1, 0);
        }
        else
        {
            sub_46ABB0((int)v1, 1);
        }
        if (sub_450560())
        {
            v3 = loadString_sub_40F1D0((char*)& byte_587000[145376], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 860);
            sub_46AEE0(*(int*)& byte_5D4594[1082880], (int)v3);
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 509);
            v5 = loadString_sub_40F1D0((char*)& byte_587000[145424], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 862);
        }
        else
        {
            v6 = loadString_sub_40F1D0((char*)& byte_587000[145472], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 866);
            sub_46AEE0(*(int*)& byte_5D4594[1082880], (int)v6);
            v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[1082856], 509);
            v5 = loadString_sub_40F1D0((char*)& byte_587000[145524], 0, "C:\\NoxPost\\src\\client\\Gui\\GUISave.c", 868);
        }
        sub_46AEE0((int)v4, (int)v5);
        result = sub_413A00(1);
    }
    return result;
}

//----- (0046D6F0) --------------------------------------------------------
int sub_46D6F0()
{
    memset(&byte_5D4594[1064948], 0, 0x45E4u);
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1082856]))
        return 0;
    nox_window_set_hidden(*(int*)& byte_5D4594[1082856], 1);
    sub_46ABB0(*(int*)& byte_5D4594[1082856], 0);
    sub_46ADE0(*(int*)& byte_5D4594[1082856]);
    sub_413A00(0);
    return 1;
}

//----- (0046D750) --------------------------------------------------------
int __cdecl sub_46D750(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    int v10; // edi
    int v11; // ecx
    int v12; // esi

    if (!a1 || a4 - a2 <= 0 || a5 - a3 <= 0)
        return -1;
    v10 = a6;
    if (a6 < 1)
        v10 = 1;
    v11 = a7;
    if (a7 < 0)
        v11 = 0;
    v12 = a8;
    if (a8 < 0)
        v12 = 0;
    *(_DWORD*)& byte_5D4594[1082924] = a5 - a3;
    *(_DWORD*)& byte_5D4594[1082916] = a1;
    *(_DWORD*)& byte_5D4594[1082920] = a4 - a2 - (a4 - a2) % 4;
    *(_DWORD*)& byte_5D4594[1082896] = a2;
    *(_DWORD*)& byte_587000[145540] = v10;
    *(_DWORD*)& byte_5D4594[1082892] = a3;
    *(_DWORD*)& byte_587000[145544] = v11;
    *(_DWORD*)& byte_587000[145548] = v11;
    *(_DWORD*)& byte_587000[145552] = v12;
    *(_DWORD*)& byte_5D4594[1082908] = a4;
    *(_DWORD*)& byte_5D4594[1082912] = a5;
    *(_DWORD*)& byte_5D4594[1082904] = a9;
    *(_DWORD*)& byte_5D4594[1082900] = a10;
    return 0;
}

//----- (0046D830) --------------------------------------------------------
int sub_46D830()
{
    __int16* v1; // ebp
    int v2; // ebx
    int v3; // edi
    __int16* v4; // esi
    int v5; // [esp+4h] [ebp-Ch]
    int v6; // [esp+8h] [ebp-8h]
    int v7; // [esp+Ch] [ebp-4h]

    if ((int) * (_DWORD*)& byte_587000[145548] < 0)
        return 0;
    if ((int)-- * (_DWORD*)& byte_587000[145548] >= 0)
        goto LABEL_15;
    v1 = *(__int16**)& byte_5D4594[1082916];
    if (!*(_DWORD*)& byte_5D4594[1082916])
        return 0;
    v5 = *(_DWORD*)& byte_5D4594[1082896];
    v7 = *(_DWORD*)& byte_587000[145540];
    if (*(_DWORD*)& byte_5D4594[3801780] == 1)
    {
        v7 = 2 * *(_DWORD*)& byte_587000[145540];
        v5 = 2 * *(_DWORD*)& byte_5D4594[1082896];
    }
    v2 = *(_DWORD*)& byte_5D4594[1082892];
    v3 = 0;
    v4 = (__int16*)(v5 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * *(_DWORD*)& byte_5D4594[1082892]));
    v6 = 0;
    while (v6 < *(int*)& byte_5D4594[1082924])
    {
        *v1 = sub_4A9B70(v4);
        v4 = (__int16*)((char*)v4 + v7);
        v3 += *(_DWORD*)& byte_587000[145540];
        ++v1;
        if (v3 >= *(int*)& byte_5D4594[1082920])
        {
            v2 += *(_DWORD*)& byte_587000[145540];
            v3 = 0;
            v6 += *(_DWORD*)& byte_587000[145540];
            v4 = (__int16*)(v5 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + 4 * v2));
        }
    }
    if ((int) * (_DWORD*)& byte_587000[145552] >= 0)
    {
        if (-- * (int*)& byte_587000[145552] >= 0)
            * (_DWORD*)& byte_587000[145548] = *(_DWORD*)& byte_587000[145544];
    LABEL_15:
        if (*(_DWORD*)& byte_5D4594[1082904])
            (*(void(__cdecl * *)(_DWORD)) & byte_5D4594[1082904])(*(_DWORD*)& byte_5D4594[1082900]);
    }
    return 1;
}

//----- (0046D950) --------------------------------------------------------
void __cdecl sub_46D950(_DWORD* a1)
{
    int v2; // edx
    char v3[1024]; // [esp+0h] [ebp-400h]

    v2 = ++ * (_DWORD*)& byte_5D4594[1082928];
    if (!a1[257])
    {
        if (a1[256])
            nox_sprintf(v3, "%s%d.bmp", a1, v2);
        else
            nox_sprintf(v3, "%s.bmp", a1);
        sub_46D9D0((int)v3,
            *(int*)& byte_5D4594[1082916],
            *(LPVOID*)& byte_5D4594[1082920],
            *(int*)& byte_5D4594[1082924]);
    }
}

//----- (0046D9D0) --------------------------------------------------------
FILE* __cdecl sub_46D9D0(int a1, int a2, LPVOID lpMem, int a4)
{
    int v4; // ebp
    size_t v5; // edi
    int v6; // esi
    size_t v7; // eax
    char* v8; // eax
    unsigned int v9; // edx
    _BYTE* v10; // ecx
    unsigned int v11; // edx
    _BYTE* v12; // eax
    FILE* result; // eax
    FILE* v14; // esi
    char* v15; // ebx
    unsigned __int8 v16[14]; // [esp+10h] [ebp-38h]
    unsigned __int8 v17[40]; // [esp+20h] [ebp-28h]
    char* lpMema; // [esp+54h] [ebp+Ch]

    v4 = a4;
    v5 = (size_t)lpMem;
    v6 = a4 * (_DWORD)lpMem;
    *(_DWORD*)v17 = 40;
    *(_DWORD*)& v17[4] = lpMem;
    v7 = 3 * a4 * (_DWORD)lpMem;
    *(_DWORD*)& v17[8] = a4;
    *(_WORD*)& v17[12] = 1;
    *(_WORD*)& v17[14] = 24;
    *(_DWORD*)& v17[32] = 0;
    *(_DWORD*)& v17[16] = 0;
    *(_DWORD*)& v17[20] = 3 * a4 * (_DWORD)lpMem;
    *(_DWORD*)& v17[24] = 0;
    *(_DWORD*)& v17[28] = 0;
    *(_DWORD*)& v17[36] = 0;
    *(_WORD*)v16 = 19778;
    *(_WORD*)& v16[6] = 0;
    *(_WORD*)& v16[8] = 0;
    *(_DWORD*)& v16[10] = 54;
    *(_DWORD*)& v16[2] = v7 + 54;
    v8 = (char*)nox_malloc(v7);
    v10 = (_BYTE*)a2;
    lpMema = v8;
    if (v6 > 0)
    {
        do
        {
            LOBYTE(v9) = *v10;
            v10 += 2;
            *v8 = 8 * v9;
            LOWORD(v9) = *((_WORD*)v10 - 1);
            v11 = v9 >> 2;
            v12 = v8 + 1;
            *v12 = v11 & 0xF8;
            LOWORD(v11) = *((_WORD*)v10 - 1);
            v9 = v11 >> 7;
            *++v12 = v9 & 0xF8;
            v8 = v12 + 1;
            --v6;
        } while (v6);
    }
    result = fopen((const char*)a1, "wb");
    v14 = result;
    if (result)
    {
        fwrite(v16, 0xEu, 1u, result);
        fwrite(v17, 0x28u, 1u, v14);
        v15 = &lpMema[2 * v5 * (a4 - 1) + v5 * (a4 - 1)];
        if (a4 > 0)
        {
            do
            {
                fwrite(v15, v5, 3u, v14);
                v15 -= 3 * v5;
                --v4;
            } while (v4);
        }
        fclose(v14);
        free(lpMema);
    }
    return result;
}
// 46DA62: variable 'v9' is possibly undefined

//----- (0046DB00) --------------------------------------------------------
int sub_46DB00()
{
    if (!*(_DWORD*)& byte_5D4594[1083964])
    {
        *(_DWORD*)& byte_5D4594[1083964] = nox_malloc(2 * nox_win_width * nox_win_height);
        strcpy((char*)& byte_5D4594[1082932], "nox");
        *(_DWORD*)& byte_5D4594[1083956] = 1;
        *(_DWORD*)& byte_5D4594[1083960] = 0;
    }
    sub_409EC0(4096);
    return sub_46D750(
        *(int*)& byte_5D4594[1083964],
        0,
        0,
        nox_win_width,
        nox_win_height,
        1,
        0,
        0,
        sub_46D950,
        (int)& byte_5D4594[1082932]);
}

//----- (0046DB80) --------------------------------------------------------
int sub_46DB80()
{
    int i; // esi
    int result; // eax

    for (i = 0; i < 8; i += 4)
    {
        nox_window_call_field_94(*(_DWORD*)& byte_5D4594[i + 1090060], 16399, 1, 0);
        nox_window_call_field_94(*(_DWORD*)& byte_5D4594[i + 1090068], 16399, 1, 0);
        nox_window_call_field_94(*(_DWORD*)& byte_5D4594[i + 1090076], 16399, 1, 0);
        nox_window_call_field_94(*(_DWORD*)& byte_5D4594[i + 1090084], 16399, 1, 0);
        result = nox_window_call_field_94(*(_DWORD*)& byte_5D4594[i + 1090092], 16399, 1, 0);
    }
    return result;
}

//----- (0046DC00) --------------------------------------------------------
int __cdecl sub_46DC00(int a1, unsigned __int8 a2, int a3)
{
    nox_window_call_field_94(a1, 16397, a3, a2);
    return 1;
}

//----- (0046DC30) --------------------------------------------------------
int sub_46DC30(int a1, unsigned __int8 a2, wchar_t* a3, ...)
{
    va_list va; // [esp+10h] [ebp+10h]

    va_start(va, a3);
    nox_vswprintf((wchar_t*)& byte_5D4594[1089000], a3, va);
    return sub_46DC00(a1, a2, (int)& byte_5D4594[1089000]);
}

//----- (0046DC60) --------------------------------------------------------
wchar_t* __cdecl sub_46DC60(int a1, unsigned __int8 a2, int a3)
{
    wchar_t* result; // eax

    if (a3)
        return (wchar_t*)sub_46DC00(a1, a2, a3);
    result = loadString_sub_40F1D0((char*)& byte_587000[145752], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1050);
    if (result)
        result = (wchar_t*)sub_46DC00(a1, a2, (int)result);
    return result;
}

//----- (0046DCC0) --------------------------------------------------------
char* sub_46DCC0()
{
    char* result; // eax
    signed int v1; // ebx
    unsigned int v2; // esi
    unsigned int v3; // edi
    int v4; // ebp
    char* k; // esi
    int v6; // eax
    char* l; // eax
    int v8; // ecx
    int v9; // ebx
    int v10; // esi
    char* v11; // edi
    int m; // ebp
    unsigned __int8 v13; // dl
    int v14; // eax
    int v15; // ecx
    int v16; // edi
    _DWORD* v17; // eax
    _DWORD* v18; // edi
    char* v19; // eax
    int v20; // edx
    unsigned __int8 v21; // al
    int v22; // ecx
    unsigned int v23; // esi
    char* i; // eax
    int v25; // ecx
    unsigned int v26; // ebp
    int v27; // esi
    char* v28; // edi
    unsigned int j; // ebx
    unsigned __int8 v30; // dl
    int v31; // eax
    int v32; // ecx
    int v33; // ecx
    int v34; // edi
    _DWORD* v35; // eax
    _DWORD* v36; // edi
    char* v37; // eax
    int v38; // edx
    unsigned __int8 v39; // al
    int v40; // ecx
    unsigned int v41; // [esp+0h] [ebp-8h]
    wchar_t* v42; // [esp+4h] [ebp-4h]
    wchar_t* v43; // [esp+4h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[1090120] == 5)
    {
        v23 = sub_416F40();
        v43 = (wchar_t*)v23;
        byte_5D4594[1090117] = 0;
        byte_5D4594[1090118] = 0;
        if (sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2650636] & 0x40000)
            v43 = (wchar_t*)--v23;
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v25 = *((_DWORD*)i + 920);
            if (!(v25 & 1) || v25 & 0x20)
            {
                if (!*((_DWORD*)i + 527))
                    * ((_DWORD*)i + 527) = 0x8000000;
            }
            else
            {
                *((_DWORD*)i + 527) |= 0x80000000;
            }
        }
        v26 = 0;
        if (byte_5D4594[1090117] < v23)
        {
            v27 = (int)v43;
            do
            {
                v28 = sub_416EA0();
                for (j = -1; v28; v28 = sub_416EE0((int)v28))
                {
                    if ((v28[2064] != 31 || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                        && *((int*)v28 + 527) >= v26
                        && !sub_46E1E0(*((_DWORD*)v28 + 515))
                        && *((int*)v28 + 527) < j)
                    {
                        j = *((_DWORD*)v28 + 527);
                        v27 = (int)v28;
                    }
                }
                v30 = byte_5D4594[1090117];
                v31 = 80 * byte_5D4594[1090117];
                *(_DWORD*)& byte_5D4594[v31 + 1084192] = *(_DWORD*)(v27 + 2060);
                v32 = *(_DWORD*)(v27 + 3680);
                if (!(v32 & 1) || v32 & 0x20)
                {
                    v33 = *(_DWORD*)(v27 + 2108);
                    if (v33 == 0x8000000)
                    {
                        *(_DWORD*)& byte_5D4594[v31 + 1084196] = 0;
                    }
                    else
                    {
                        *(_DWORD*)& byte_5D4594[v31 + 1084196] = v33;
                        ++byte_5D4594[1090118];
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[v31 + 1084196] = *(_DWORD*)(v27 + 2108) + 0x80000000;
                }
                *(_DWORD*)& byte_5D4594[v31 + 1084200] = *(unsigned __int16*)(v27 + 2148);
                *(_DWORD*)& byte_5D4594[v31 + 1084208] = *(_DWORD*)(v27 + 3680);
                v34 = 80 * v30;
                *(_DWORD*)& byte_5D4594[v34 + 1084204] = sub_46E080(v27);
                nox_wcscpy((wchar_t*)& byte_5D4594[v34 + 1084132], (const wchar_t*)(v27 + 4704));
                sub_46E170((wchar_t*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084132]);
                byte_5D4594[80 * byte_5D4594[1090117] + 1084188] = *(_BYTE*)(v27 + 2251);
                v35 = sub_418C80(*(_DWORD*)(v27 + 2060));
                v36 = v35;
                if (v35 && sub_419130((int)v35))
                {
                    v37 = sub_418AB0(*((unsigned __int8*)v36 + 4));
                    if (v37)
                    {
                        v38 = (unsigned __int8)v37[57];
                        v39 = byte_5D4594[1090117];
                        *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = v38;
                    }
                    else
                    {
                        v39 = byte_5D4594[1090117];
                        *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
                    }
                }
                else
                {
                    v39 = byte_5D4594[1090117];
                    *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
                }
                byte_5D4594[1090117] = v39 + 1;
                v26 = j;
            } while ((unsigned __int8)(v39 + 1) < (unsigned int)v43);
        }
        for (result = sub_416EA0(); result; result = sub_416EE0((int)result))
        {
            v40 = *((_DWORD*)result + 920);
            if (!(v40 & 1) || v40 & 0x20)
            {
                if (*((_DWORD*)result + 527) == 0x8000000)
                    * ((_DWORD*)result + 527) = 0;
            }
            else
            {
                *((_DWORD*)result + 527) &= 0x7FFFFFFFu;
            }
        }
    }
    else if (sub_40A5C0(1024))
    {
        v1 = 0x80000000;
        v41 = sub_416F40();
        v2 = sub_417DD0();
        byte_5D4594[1090116] = 0;
        v42 = (wchar_t*)v2;
        byte_5D4594[1090117] = 0;
        byte_5D4594[1090118] = 0;
        if (sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2650636] & 0x40000)
            --v41;
        if (byte_5D4594[1090116] < v2)
        {
            v3 = v2;
            do
            {
                v4 = 0x7FFFFFFF;
                for (k = sub_418B10(); k; k = sub_418B60((int)k))
                {
                    if (*((int*)k + 13) >= v1 && !sub_46E130((unsigned __int8)k[57]) && *((int*)k + 13) < v4)
                    {
                        v4 = *((_DWORD*)k + 13);
                        v3 = (unsigned int)k;
                    }
                }
                v6 = 56 * byte_5D4594[1090116];
                *(_DWORD*)& byte_5D4594[v6 + 1087252] = *(_DWORD*)(v3 + 52);
                *(_DWORD*)& byte_5D4594[v6 + 1087248] = *(unsigned __int8*)(v3 + 57);
                byte_5D4594[v6 + 1087256] = *(_BYTE*)(v3 + 56);
                nox_wcscpy((wchar_t*)& byte_5D4594[v6 + 1087204], (const wchar_t*)v3);
                sub_46E170((wchar_t*)& byte_5D4594[56 * byte_5D4594[1090116] + 1087204]);
                ++byte_5D4594[1090116];
                v1 = v4;
            } while (byte_5D4594[1090116] < (unsigned int)v42);
        }
        for (l = sub_416EA0(); l; l = sub_416EE0((int)l))
        {
            v8 = *((_DWORD*)l + 920);
            if (v8 & 1 && !(v8 & 0x20))
                * ((_DWORD*)l + 535) += 0xFFFF;
        }
        v9 = -1;
        if (byte_5D4594[1090117] < v41)
        {
            v10 = (int)v42;
            do
            {
                v11 = sub_416EA0();
                for (m = 0x7FFFFFFF; v11; v11 = sub_416EE0((int)v11))
                {
                    if ((v11[2064] != 31 || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                        && *((int*)v11 + 535) >= v9
                        && !sub_46E1E0(*((_DWORD*)v11 + 515))
                        && *((int*)v11 + 535) < m)
                    {
                        m = *((_DWORD*)v11 + 535);
                        v10 = (int)v11;
                    }
                }
                v13 = byte_5D4594[1090117];
                v14 = 80 * byte_5D4594[1090117];
                *(_DWORD*)& byte_5D4594[v14 + 1084192] = *(_DWORD*)(v10 + 2060);
                v15 = *(_DWORD*)(v10 + 3680);
                if (!(v15 & 1) || v15 & 0x20)
                {
                    *(_DWORD*)& byte_5D4594[v14 + 1084196] = *(_DWORD*)(v10 + 2140);
                    ++byte_5D4594[1090118];
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[v14 + 1084196] = *(_DWORD*)(v10 + 2140) - 0xFFFF;
                }
                *(_DWORD*)& byte_5D4594[v14 + 1084200] = *(unsigned __int16*)(v10 + 2148);
                *(_DWORD*)& byte_5D4594[v14 + 1084208] = *(_DWORD*)(v10 + 3680);
                v16 = 80 * v13;
                *(_DWORD*)& byte_5D4594[v16 + 1084204] = sub_46E080(v10);
                nox_wcscpy((wchar_t*)& byte_5D4594[v16 + 1084132], (const wchar_t*)(v10 + 4704));
                sub_46E170((wchar_t*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084132]);
                byte_5D4594[80 * byte_5D4594[1090117] + 1084188] = *(_BYTE*)(v10 + 2251);
                v17 = sub_418C80(*(_DWORD*)(v10 + 2060));
                v18 = v17;
                if (v17 && sub_419130((int)v17))
                {
                    v19 = sub_418AB0(*((unsigned __int8*)v18 + 4));
                    if (v19)
                    {
                        v20 = (unsigned __int8)v19[57];
                        v21 = byte_5D4594[1090117];
                        *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = v20;
                    }
                    else
                    {
                        v21 = byte_5D4594[1090117];
                        *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
                    }
                }
                else
                {
                    v21 = byte_5D4594[1090117];
                    *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
                }
                byte_5D4594[1090117] = v21 + 1;
                v9 = m;
            } while ((unsigned __int8)(v21 + 1) < v41);
        }
        for (result = sub_416EA0(); result; result = sub_416EE0((int)result))
        {
            v22 = *((_DWORD*)result + 920);
            if (v22 & 1)
            {
                if (!(v22 & 0x20))
                    * ((_DWORD*)result + 535) -= 0xFFFF;
            }
        }
    }
    else
    {
        result = sub_46E4E0();
    }
    return result;
}

//----- (0046E080) --------------------------------------------------------
int __cdecl sub_46E080(int a1)
{
    int v1; // eax
    _DWORD* v3; // eax

    if (sub_40A5C0(32))
    {
        v1 = *(_DWORD*)(a1 + 2060);
        if (v1 == *(unsigned __int16*)& byte_5D4594[1090128])
            return 2;
        if (v1 == *(unsigned __int16*)& byte_5D4594[1090130])
            return 3;
    }
    else if (sub_40A5C0(64))
    {
        if (*(_DWORD*)(a1 + 2060) == *(unsigned __int16*)& byte_5D4594[1090132])
            return 4;
    }
    else if (sub_40A5C0(16))
    {
        v3 = sub_45A6F0(*(_DWORD*)(a1 + 2060));
        if (v3)
        {
            if (sub_4356C0((int)v3, 30))
                return 1;
        }
    }
    return 0;
}

//----- (0046E130) --------------------------------------------------------
int __cdecl sub_46E130(int a1)
{
    int v1; // eax
    unsigned __int8* i; // ecx

    v1 = 0;
    if (!byte_5D4594[1090116])
        return 0;
    for (i = &byte_5D4594[1087248]; *(_DWORD*)i != a1; i += 56)
    {
        if (++v1 >= (unsigned int)byte_5D4594[1090116])
            return 0;
    }
    return 1;
}

//----- (0046E170) --------------------------------------------------------
unsigned __int16* __cdecl sub_46E170(wchar_t* a1)
{
    unsigned __int16* v1; // esi
    size_t v2; // edi
    unsigned __int16* v3; // edi

    v1 = a1;
    v2 = nox_wcslen(a1);
    sub_43F840(0, v1, (int*)& a1, 0, 0);
    if ((int)(a1 + 5) > * (int*)& byte_5D4594[1084036])
    {
        v3 = &v1[v2];
        do
        {
            *v3 = 0;
            --v3;
            sub_43F840(0, v1, (int*)& a1, 0, 0);
        } while ((int)(a1 + 5) > * (int*)& byte_5D4594[1084036]);
    }
    return v1;
}

//----- (0046E1E0) --------------------------------------------------------
int __cdecl sub_46E1E0(int a1)
{
    int v1; // eax
    unsigned __int8* i; // ecx

    v1 = 0;
    if (!byte_5D4594[1090117])
        return 0;
    for (i = &byte_5D4594[1084192]; *(_DWORD*)i != a1; i += 80)
    {
        if (++v1 >= (unsigned int)byte_5D4594[1090117])
            return 0;
    }
    return 1;
}

//----- (0046E4E0) --------------------------------------------------------
char* sub_46E4E0()
{
    int v0; // ebx
    unsigned int v1; // esi
    unsigned int v2; // edi
    signed int v3; // ebp
    char* i; // esi
    int v5; // eax
    char* j; // eax
    int v7; // ecx
    int v8; // ebx
    int v9; // esi
    char* v10; // edi
    signed int k; // ebp
    unsigned __int8 v12; // dl
    int v13; // eax
    int v14; // ecx
    int v15; // edi
    _DWORD* v16; // eax
    _DWORD* v17; // edi
    char* v18; // eax
    int v19; // edx
    unsigned __int8 v20; // al
    char* result; // eax
    int v22; // ecx
    unsigned int v23; // [esp+10h] [ebp-8h]
    wchar_t* v24; // [esp+14h] [ebp-4h]

    v0 = 0x7FFFFFFF;
    v1 = sub_417DD0();
    v24 = (wchar_t*)v1;
    v23 = sub_416F40();
    byte_5D4594[1090116] = 0;
    byte_5D4594[1090117] = 0;
    byte_5D4594[1090118] = 0;
    if (sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2650636] & 0x40000)
        --v23;
    if (byte_5D4594[1090116] < v1)
    {
        v2 = v1;
        do
        {
            v3 = 0x80000000;
            for (i = sub_418B10(); i; i = sub_418B60((int)i))
            {
                if (*((int*)i + 13) <= v0 && !sub_46E130((unsigned __int8)i[57]) && *((int*)i + 13) > v3)
                {
                    v3 = *((_DWORD*)i + 13);
                    v2 = (unsigned int)i;
                }
            }
            v5 = 56 * byte_5D4594[1090116];
            *(_DWORD*)& byte_5D4594[v5 + 1087252] = *(_DWORD*)(v2 + 52);
            *(_DWORD*)& byte_5D4594[v5 + 1087248] = *(unsigned __int8*)(v2 + 57);
            byte_5D4594[v5 + 1087256] = *(_BYTE*)(v2 + 56);
            nox_wcscpy((wchar_t*)& byte_5D4594[v5 + 1087204], (const wchar_t*)v2);
            sub_46E170((wchar_t*)& byte_5D4594[56 * byte_5D4594[1090116] + 1087204]);
            ++byte_5D4594[1090116];
            v0 = v3;
        } while (byte_5D4594[1090116] < (unsigned int)v24);
    }
    for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
    {
        v7 = *((_DWORD*)j + 920);
        if (v7 & 1 && !(v7 & 0x20))
            * ((_DWORD*)j + 534) -= 0xFFFF;
    }
    v8 = 0x7FFFFFFF;
    if (byte_5D4594[1090117] < v23)
    {
        v9 = (int)v24;
        do
        {
            v10 = sub_416EA0();
            for (k = 0x80000000; v10; v10 = sub_416EE0((int)v10))
            {
                if ((v10[2064] != 31 || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
                    && *((int*)v10 + 534) <= v8
                    && !sub_46E1E0(*((_DWORD*)v10 + 515))
                    && *((int*)v10 + 534) > k)
                {
                    k = *((_DWORD*)v10 + 534);
                    v9 = (int)v10;
                }
            }
            v12 = byte_5D4594[1090117];
            v13 = 80 * byte_5D4594[1090117];
            *(_DWORD*)& byte_5D4594[v13 + 1084192] = *(_DWORD*)(v9 + 2060);
            v14 = *(_DWORD*)(v9 + 3680);
            if (!(v14 & 1) || v14 & 0x20)
            {
                *(_DWORD*)& byte_5D4594[v13 + 1084196] = *(_DWORD*)(v9 + 2136);
                ++byte_5D4594[1090118];
            }
            else
            {
                *(_DWORD*)& byte_5D4594[v13 + 1084196] = *(_DWORD*)(v9 + 2136) + 0xFFFF;
            }
            *(_DWORD*)& byte_5D4594[v13 + 1084200] = *(unsigned __int16*)(v9 + 2148);
            v15 = 80 * v12;
            *(_DWORD*)& byte_5D4594[v15 + 1084204] = sub_46E080(v9);
            *(_DWORD*)& byte_5D4594[v15 + 1084208] = *(_DWORD*)(v9 + 3680);
            nox_wcscpy((wchar_t*)& byte_5D4594[v15 + 1084132], (const wchar_t*)(v9 + 4704));
            sub_46E170((wchar_t*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084132]);
            byte_5D4594[80 * byte_5D4594[1090117] + 1084188] = *(_BYTE*)(v9 + 2251);
            v16 = sub_418C80(*(_DWORD*)(v9 + 2060));
            v17 = v16;
            if (v16 && sub_419130((int)v16))
            {
                v18 = sub_418AB0(*((unsigned __int8*)v17 + 4));
                if (v18)
                {
                    v19 = (unsigned __int8)v18[57];
                    v20 = byte_5D4594[1090117];
                    *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = v19;
                }
                else
                {
                    v20 = byte_5D4594[1090117];
                    *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
                }
            }
            else
            {
                v20 = byte_5D4594[1090117];
                *(_DWORD*)& byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
            }
            byte_5D4594[1090117] = v20 + 1;
            v8 = k;
        } while ((unsigned __int8)(v20 + 1) < v23);
    }
    for (result = sub_416EA0(); result; result = sub_416EE0((int)result))
    {
        v22 = *((_DWORD*)result + 920);
        if (v22 & 1)
        {
            if (!(v22 & 0x20))
                * ((_DWORD*)result + 534) += 0xFFFF;
        }
    }
    return result;
}

//----- (0046E870) --------------------------------------------------------
int sub_46E870()
{
    int v0; // ebx
    unsigned __int16* v1; // eax
    int v2; // eax
    unsigned __int16* v3; // eax
    unsigned __int16* v4; // eax
    int v5; // eax
    unsigned __int16* v6; // eax
    int v7; // eax
    unsigned __int16* v8; // eax
    unsigned __int16* v9; // eax
    unsigned __int16* v10; // eax
    unsigned __int16* v11; // eax
    unsigned __int16* v12; // eax
    int v13; // eax
    int v14; // ecx
    unsigned __int8* v15; // eax
    int v16; // edi
    int v17; // esi
    int v18; // ebp
    int v19; // edi
    int v20; // ebx
    _DWORD* v21; // eax
    int v22; // edx
    int v23; // ecx
    _DWORD* v24; // eax
    int v25; // edx
    _DWORD* v26; // eax
    int v27; // edx
    _DWORD* v28; // eax
    int v29; // ecx
    int v30; // esi
    int result; // eax
    int v32; // [esp-4h] [ebp-1DCh]
    int v33; // [esp-4h] [ebp-1DCh]
    int v34; // [esp-4h] [ebp-1DCh]
    int v35; // [esp-4h] [ebp-1DCh]
    int v36; // [esp-4h] [ebp-1DCh]
    int v37; // [esp-4h] [ebp-1DCh]
    int v38; // [esp-4h] [ebp-1DCh]
    int v39; // [esp-4h] [ebp-1DCh]
    int v40; // [esp-4h] [ebp-1DCh]
    int v41; // [esp+10h] [ebp-1C8h]
    int v42; // [esp+14h] [ebp-1C4h]
    int v43; // [esp+18h] [ebp-1C0h]
    int v44; // [esp+1Ch] [ebp-1BCh]
    int v45[3]; // [esp+20h] [ebp-1B8h]
    int v46; // [esp+2Ch] [ebp-1ACh]
    int v47; // [esp+30h] [ebp-1A8h]
    char v48[56]; // [esp+34h] [ebp-1A4h]
    char v49[332]; // [esp+6Ch] [ebp-16Ch]
    wchar_t v50[16]; // [esp+1B8h] [ebp-20h]

    *(_DWORD*)& byte_587000[145668] = 6;
    sub_46F030();
    v0 = sub_43F320(0);
    v46 = v0;
    *(_DWORD*)& byte_5D4594[1084036] = 80;
    if (sub_43AF70() == 1)
    {
        nox_swprintf(v50, L"%S", &byte_587000[145768]);
        sub_43F840(0, v50, &v41, &v44, nox_win_width);
    }
    else
    {
        v32 = nox_win_width;
        v1 = loadString_sub_40F1D0((char*)& byte_587000[145824], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1641);
        sub_43F840(0, v1, &v41, &v44, v32);
    }
    v2 = v41;
    if (v41 < 18)
    {
        v2 = 18;
        v41 = 18;
    }
    *(_DWORD*)& byte_5D4594[1084040] = v2 + 14;
    v33 = nox_win_width;
    v3 = loadString_sub_40F1D0((char*)& byte_587000[145868], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1649);
    sub_43F840(0, v3, &v41, &v44, v33);
    v34 = nox_win_width;
    v4 = loadString_sub_40F1D0((char*)& byte_587000[145912], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1650);
    sub_43F840(0, v4, &v42, &v43, v34);
    v5 = v41;
    if (v42 > v41)
    {
        v5 = v42;
        v41 = v42;
    }
    *(_DWORD*)& byte_5D4594[1084048] = v5 + 7;
    v35 = nox_win_width;
    v6 = loadString_sub_40F1D0((char*)& byte_587000[145964], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1657);
    sub_43F840(0, v6, &v41, &v44, v35);
    sub_43F840(0, (unsigned __int16*)& byte_587000[145972], &v42, &v43, nox_win_width);
    v7 = v41;
    if (v42 > v41)
    {
        v7 = v42;
        v41 = v42;
    }
    *(_DWORD*)& byte_5D4594[1084052] = v7 + 7;
    v36 = nox_win_width;
    v8 = loadString_sub_40F1D0((char*)& byte_587000[146032], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1667);
    sub_43F840(0, v8, &v41, &v44, v36);
    v37 = nox_win_width;
    v9 = loadString_sub_40F1D0((char*)& byte_587000[146076], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1668);
    sub_43F840(0, v9, &v42, &v43, v37);
    if (v42 > v41)
        v41 = v42;
    v38 = nox_win_width;
    v10 = loadString_sub_40F1D0((char*)& byte_587000[146120], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1671);
    sub_43F840(0, v10, &v42, &v43, v38);
    if (v42 > v41)
        v41 = v42;
    v39 = nox_win_width;
    v11 = loadString_sub_40F1D0((char*)& byte_587000[146164], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1674);
    sub_43F840(0, v11, &v42, &v43, v39);
    if (v42 > v41)
        v41 = v42;
    v40 = nox_win_width;
    v12 = loadString_sub_40F1D0((char*)& byte_587000[146212], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1677);
    sub_43F840(0, v12, &v42, &v43, v40);
    v13 = v41;
    if (v42 > v41)
    {
        v13 = v42;
        v41 = v42;
    }
    v14 = 0;
    *(_DWORD*)& byte_5D4594[1084044] = v13 + 7;
    v15 = &byte_5D4594[1084036];
    do
    {
        v16 = *(_DWORD*)v15;
        v15 += 4;
        v14 += v16;
    } while ((int)v15 < (int)& byte_5D4594[1084056]);
    *(_DWORD*)& byte_5D4594[1090040] = v14;
    *(_DWORD*)& byte_5D4594[1090044] = 439 - v0;
    *(_DWORD*)& byte_5D4594[1090048] = nox_window_new(0, 1560, 0, v0 + 40, 1, 1, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1090048], sub_46F060, sub_46F080, 0);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090048] + 56) = 0x80000000;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090048] + 64) = 0x80000000;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090048] + 72) = 0x80000000;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090048] + 80) = 0x80000000;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090048] + 88) = 0x80000000;
    memset(v49, 0, sizeof(v49));
    nox_wcscpy((wchar_t*)& v49[72], (const wchar_t*)& byte_5D4594[1090136]);
    *(_DWORD*)& v49[68] = *(_DWORD*)& byte_5D4594[2650644];
    *(_DWORD*)& v49[20] = 0x80000000;
    memset(v48, 0, sizeof(v48));
    *(_WORD*)& v48[6] = 0;
    *(_DWORD*)& v48[12] = 0;
    *(_DWORD*)& v48[16] = 0;
    *(_DWORD*)& v49[28] = 0x80000000;
    *(_DWORD*)& v49[36] = 0x80000000;
    *(_DWORD*)& v49[44] = 0x80000000;
    *(_DWORD*)& v49[52] = 0x80000000;
    v17 = 0;
    v47 = 3 * v0;
    v18 = 3 * v0 + 1;
    *(_DWORD*)& v49[8] = 32;
    *(_DWORD*)& v48[2] = (unsigned __int16)(v0 + 1);
    strcpy(v48, "@");
    *(_DWORD*)& v48[8] = 1;
    v19 = 2 * (v0 + 1);
    v20 = 2 * v0;
    do
    {
        v21 = sub_4A4310(
            *(int*)& byte_5D4594[1090048],
            1088,
            v17 * *(_DWORD*)& byte_5D4594[1090040],
            v18,
            *(int*)& byte_5D4594[1090040],
            *(_DWORD*)& byte_5D4594[1090044] - v19,
            (int)v49,
            (__int16*)v48);
        v22 = *(_DWORD*)& byte_5D4594[1084036];
        v23 = *(_DWORD*)& byte_5D4594[1090044] - v19;
        *(_DWORD*)& byte_5D4594[4 * v17 + 1090052] = v21;
        v24 = sub_4A4310((int)v21, 1088, 0, v20, v22, v23, (int)v49, (__int16*)v48);
        v25 = *(_DWORD*)& byte_5D4594[1090044];
        *(_DWORD*)& byte_5D4594[4 * v17 + 1090060] = v24;
        v26 = sub_4A4310(
            *(_DWORD*)& byte_5D4594[4 * v17 + 1090052],
            1088,
            *(int*)& byte_5D4594[1084036],
            v20,
            *(int*)& byte_5D4594[1084040],
            v25 - v19,
            (int)v49,
            (__int16*)v48);
        v27 = *(_DWORD*)& byte_5D4594[1090044];
        *(_DWORD*)& byte_5D4594[4 * v17 + 1090068] = v26;
        *(_DWORD*)& byte_5D4594[4 * v17 + 1090076] = sub_4A4310(
            *(_DWORD*)& byte_5D4594[4 * v17 + 1090052],
            1088,
            *(_DWORD*)& byte_5D4594[1084036] + *(_DWORD*)& byte_5D4594[1084040],
            v20,
            *(int*)& byte_5D4594[1084044],
            v27 - v19,
            (int)v49,
            (__int16*)v48);
        v28 = sub_4A4310(
            *(_DWORD*)& byte_5D4594[4 * v17 + 1090052],
            1088,
            *(_DWORD*)& byte_5D4594[1084036] + *(_DWORD*)& byte_5D4594[1084040] + *(_DWORD*)& byte_5D4594[1084044],
            v20,
            *(int*)& byte_5D4594[1084048],
            *(_DWORD*)& byte_5D4594[1090044] - v19,
            (int)v49,
            (__int16*)v48);
        v29 = *(_DWORD*)& byte_5D4594[1090044];
        *(_DWORD*)& byte_5D4594[4 * v17 + 1090084] = v28;
        *(_DWORD*)& byte_5D4594[4 * v17 + 1090092] = sub_4A4310(
            *(_DWORD*)& byte_5D4594[4 * v17 + 1090052],
            1088,
            *(_DWORD*)& byte_5D4594[1084036]
            + *(_DWORD*)& byte_5D4594[1084040]
            + *(_DWORD*)& byte_5D4594[1084048]
            + *(_DWORD*)& byte_5D4594[1084044],
            v20,
            *(int*)& byte_5D4594[1084052],
            v29 - v19,
            (int)v49,
            (__int16*)v48);
        sub_46B2C0(*(_DWORD*)& byte_5D4594[4 * v17 + 1090052], sub_46F070);
        sub_46B120(*(_DWORD * *)& byte_5D4594[4 * v17 + 1090060], *(_DWORD*)& byte_5D4594[4 * v17 + 1090052]);
        sub_46B120(*(_DWORD * *)& byte_5D4594[4 * v17 + 1090068], *(_DWORD*)& byte_5D4594[4 * v17 + 1090052]);
        sub_46B120(*(_DWORD * *)& byte_5D4594[4 * v17 + 1090076], *(_DWORD*)& byte_5D4594[4 * v17 + 1090052]);
        sub_46B120(*(_DWORD * *)& byte_5D4594[4 * v17 + 1090084], *(_DWORD*)& byte_5D4594[4 * v17 + 1090052]);
        sub_46B120(*(_DWORD * *)& byte_5D4594[4 * v17 + 1090092], *(_DWORD*)& byte_5D4594[4 * v17 + 1090052]);
        ++v17;
    } while (v17 < 2);
    *(_DWORD*)& v49[8] = 2048;
    *(_DWORD*)& v49[68] = *(_DWORD*)& byte_5D4594[2589772];
    v45[0] = loadString_sub_40F1D0((char*)& byte_587000[146264], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1772);
    v30 = v46 + 1;
    v45[1] = 0;
    v45[2] = 0;
    *(_DWORD*)& byte_5D4594[1090100] = sub_489300(
        *(int*)& byte_5D4594[1090048],
        1088,
        0,
        v46,
        *(int*)& byte_5D4594[1090040],
        v46 + 1,
        v49,
        v45);
    *(_DWORD*)& v49[68] = *(_DWORD*)& byte_5D4594[2523948];
    v45[0] = loadString_sub_40F1D0((char*)& byte_587000[146312], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1782);
    *(_DWORD*)& byte_5D4594[1090112] = sub_489300(
        *(int*)& byte_5D4594[1090048],
        1088,
        0,
        v20,
        *(int*)& byte_5D4594[1090040],
        v30,
        v49,
        v45);
    *(_DWORD*)& v49[68] = *(_DWORD*)& byte_5D4594[2650644];
    v45[0] = loadString_sub_40F1D0((char*)& byte_587000[146364], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1790);
    *(_DWORD*)& byte_5D4594[1090108] = sub_489300(
        *(int*)& byte_5D4594[1090048],
        1088,
        0,
        v47,
        *(int*)& byte_5D4594[1090040],
        v30,
        v49,
        v45);
    *(_DWORD*)& v49[68] = *(_DWORD*)& byte_5D4594[2618904];
    v45[0] = loadString_sub_40F1D0((char*)& byte_587000[146416], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1798);
    *(_DWORD*)& byte_5D4594[1090104] = sub_489300(
        *(int*)& byte_5D4594[1090048],
        1088,
        0,
        0,
        *(int*)& byte_5D4594[1090040],
        v30,
        v49,
        v45);
    result = *(_DWORD*)& byte_5D4594[1090048];
    *(_DWORD*)& byte_587000[145664] = 1;
    return result;
}

//----- (0046F030) --------------------------------------------------------
wchar_t* sub_46F030()
{
    int i; // esi
    wchar_t* result; // eax

    for (i = 0; i < 12; i += 4)
    {
        result = loadString_sub_40F1D0(*(char**)& byte_587000[i + 145676], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 167);
        *(_DWORD*)& byte_5D4594[i + 1084056] = result;
    }
    return result;
}

//----- (0046F060) --------------------------------------------------------
int sub_46F060()
{
    return 0;
}

//----- (0046F070) --------------------------------------------------------
int sub_46F070()
{
    return 0;
}

//----- (0046F080) --------------------------------------------------------
int __cdecl sub_46F080(int a1, int a2)
{
    char* v2; // ebp
    char* v4; // esi
    __int16 v5; // ax
    int v6; // eax
    _DWORD* v7; // eax
    int v8; // eax
    int v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    unsigned __int8 v12; // bl
    unsigned __int8 v13; // di
    int v14; // esi
    int v15; // ebp
    int v16; // edi
    int v17; // esi
    int v18; // eax
    unsigned __int8 v19; // al
    char* v20; // eax
    wchar_t* v21; // eax
    wchar_t* v22; // edi
    wchar_t* v23; // eax
    wchar_t* v24; // eax
    int v25; // esi
    wchar_t* v26; // eax
    int v27; // [esp-14h] [ebp-38h]
    int v28; // [esp-10h] [ebp-34h]
    int v29; // [esp-10h] [ebp-34h]
    int v30; // [esp-10h] [ebp-34h]
    unsigned __int8 v31; // [esp+4h] [ebp-20h]
    unsigned __int8 v32; // [esp+4h] [ebp-20h]
    int v33; // [esp+8h] [ebp-1Ch]
    int v34; // [esp+Ch] [ebp-18h]
    char* v35; // [esp+10h] [ebp-14h]
    int v36; // [esp+14h] [ebp-10h]
    int v37; // [esp+18h] [ebp-Ch]
    int xLeft; // [esp+1Ch] [ebp-8h]
    int yTop; // [esp+20h] [ebp-4h]
    unsigned __int8 v40; // [esp+28h] [ebp+4h]

    v2 = 0;
    v35 = 0;
    if (!sub_40A5C0(8) && *(_DWORD*)& byte_587000[145668] != 6)
    {
        *(_DWORD*)& byte_5D4594[1090120] = *(_DWORD*)& byte_587000[145668] - 1;
        if (*(int*)& byte_587000[145668] - 1 < 0)
            * (_DWORD*)& byte_5D4594[1090120] = 5;
        sub_4703F0();
        *(_DWORD*)& byte_587000[145668] = 6;
        if (!*(_DWORD*)& byte_5D4594[1090120])
            return 1;
    }
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    v4 = sub_416590(0);
    if (sub_40A5C0(1))
    {
        v5 = sub_40A5B0();
        v6 = (unsigned __int16)sub_40A020(v5);
    }
    else
    {
        v6 = *((unsigned __int16*)v4 + 27);
    }
    v34 = v6;
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
            sub_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
    }
    if (*(_DWORD*)& byte_587000[145664]
        || *(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(*(_DWORD*)& byte_5D4594[1090124]
            + *(_DWORD*)& byte_5D4594[2649704]))
    {
        *(_DWORD*)& byte_5D4594[3799524] = 1;
        *(_DWORD*)& byte_5D4594[1090124] = *(_DWORD*)& byte_5D4594[2598000];
        *(_DWORD*)& byte_587000[145672] = -1;
        v33 = 0;
        sub_46DB80();
        sub_46DCC0();
        *(_DWORD*)& byte_587000[145664] = 0;
        v7 = sub_418C80(*(int*)& byte_5D4594[2616328]);
        if (v7)
        {
            v2 = sub_418AB0(*((unsigned __int8*)v7 + 4));
            v35 = v2;
        }
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 3680);
            if (!(v8 & 1) || v8 & 0x20)
                v33 = 1;
        }
        v9 = *(_DWORD*)& byte_5D4594[1090120];
        if (byte_5D4594[1090116] && (*(_DWORD*)& byte_5D4594[1090120] == 2 || *(_DWORD*)& byte_5D4594[1090120] == 3))
        {
            v10 = loadString_sub_40F1D0((char*)& byte_587000[146504], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1338);
            sub_46DC60(*(int*)& byte_5D4594[1090060], 9u, (int)v10);
            sub_46DC60(*(int*)& byte_5D4594[1090068], 9u, (int)& byte_587000[146512]);
            sub_46DC60(*(int*)& byte_5D4594[1090076], 9u, (int)& byte_587000[146516]);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[146556], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1341);
            sub_46DC60(*(int*)& byte_5D4594[1090084], 9u, (int)v11);
            sub_46DC60(*(int*)& byte_5D4594[1090092], 9u, (int)& byte_587000[146564]);
            v12 = 0;
            v31 = 0;
            if (byte_5D4594[1090116])
            {
                do
                {
                    v13 = sub_46FEB0(v31);
                    v14 = 56 * v31;
                    sub_46DC30(*(int*)& byte_5D4594[1090060], v13, (wchar_t*)& byte_587000[146568], &byte_5D4594[v14 + 1087204]);
                    sub_46DC30(*(int*)& byte_5D4594[1090068], v13, (wchar_t*)& byte_587000[146576]);
                    sub_46DC30(*(int*)& byte_5D4594[1090076], v13, (wchar_t*)& byte_587000[146580]);
                    sub_46DC30(
                        *(int*)& byte_5D4594[1090084],
                        v13,
                        (wchar_t*)& byte_587000[146584],
                        *(_DWORD*)& byte_5D4594[v14 + 1087252]);
                    sub_46DC30(*(int*)& byte_5D4594[1090092], v13, (wchar_t*)& byte_587000[146592]);
                    v31 = ++v12;
                } while (v12 < byte_5D4594[1090116]);
            }
            else
            {
                v13 = a1;
            }
            sub_46DC30(*(int*)& byte_5D4594[1090060], v13, (wchar_t*)& byte_587000[146596]);
            sub_46DC30(*(int*)& byte_5D4594[1090068], v13, (wchar_t*)& byte_587000[146600]);
            sub_46DC30(*(int*)& byte_5D4594[1090076], v13, (wchar_t*)& byte_587000[146604]);
            sub_46DC30(*(int*)& byte_5D4594[1090084], v13, (wchar_t*)& byte_587000[146608]);
            sub_46DC30(*(int*)& byte_5D4594[1090092], v13, (wchar_t*)& byte_587000[146612]);
            v9 = *(_DWORD*)& byte_5D4594[1090120];
        }
        v36 = *(__int16*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1090060] + 32) + 46);
        if (byte_5D4594[1090117] && (v9 == 2 || v9 == 4 || v9 == 5))
        {
            sub_46F8F0(0, 0);
            v9 = *(_DWORD*)& byte_5D4594[1090120];
            if (*(_DWORD*)& byte_5D4594[1090120] == 4)
            {
                if (byte_5D4594[1090117] <= 3u)
                    LOBYTE(a2) = byte_5D4594[1090117];
                else
                    LOBYTE(a2) = 3;
            }
            else
            {
                LOBYTE(a2) = byte_5D4594[1090117];
            }
            v32 = 0;
            if ((_BYTE)a2)
            {
                do
                {
                    v15 = 0;
                    v16 = v32 >> 4;
                    if (v32 == 16)
                        sub_46F8F0(1, v36);
                    if (sub_40A5C0(1024) && v34 > 0 && *(int*)& byte_5D4594[80 * v32 + 1084196] >= v34)
                        v15 = 1;
                    v17 = 80 * v32;
                    v18 = *(_DWORD*)& byte_5D4594[v17 + 1084208];
                    if (!(v18 & 1) || v18 & 0x20 || v15)
                    {
                        if (*(int*)& byte_5D4594[80 * v32 + 1084184] == -1)
                        {
                            v40 = 3;
                            if (v18 & 0x20 || v15)
                                v40 = 2;
                        }
                        else
                        {
                            v19 = sub_46FE60(*(_DWORD*)& byte_5D4594[80 * v32 + 1084184]);
                            v40 = sub_46FEB0(v19);
                            if (byte_5D4594[80 * v32 + 1084208] & 0x20 || v15)
                                v40 -= 2;
                        }
                    }
                    else
                    {
                        v40 = 9;
                    }
                    if (*(_DWORD*)& byte_5D4594[80 * v32 + 1084192] == *(_DWORD*)& byte_5D4594[2616328])
                    {
                        *(_DWORD*)& byte_587000[145672] = *(__int16*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[4 * v16 + 1090060] + 32)
                            + 46);
                        *(_DWORD*)& byte_5D4594[1088996] = v32 >> 4;
                    }
                    sub_46DC30(
                        *(_DWORD*)& byte_5D4594[4 * v16 + 1090060],
                        v40,
                        (wchar_t*)& byte_587000[146616],
                        &byte_5D4594[v17 + 1084132]);
                    sub_46DC30(
                        *(_DWORD*)& byte_5D4594[4 * v16 + 1090076],
                        v40,
                        (wchar_t*)& byte_587000[146624],
                        *(_DWORD*)& byte_5D4594[4 * byte_5D4594[80 * v32 + 1084188] + 1084056]);
                    if (*(_DWORD*)& byte_5D4594[1090120] != 5 || *(_DWORD*)& byte_5D4594[80 * v32 + 1084196] > 0)
                        sub_46DC30(
                            *(_DWORD*)& byte_5D4594[4 * v16 + 1090084],
                            v40,
                            (wchar_t*)& byte_587000[146632],
                            *(_DWORD*)& byte_5D4594[80 * v32 + 1084196]);
                    else
                        sub_46DC30(*(_DWORD*)& byte_5D4594[4 * v16 + 1090084], v40, (wchar_t*)& byte_587000[146640]);
                    sub_46DC30(
                        *(_DWORD*)& byte_5D4594[4 * v16 + 1090092],
                        v40,
                        (wchar_t*)& byte_587000[146648],
                        *(_DWORD*)& byte_5D4594[80 * v32 + 1084200]);
                    if (*(_DWORD*)& byte_5D4594[1090120] == 5)
                    {
                        v20 = sub_417040(*(_DWORD*)& byte_5D4594[80 * v32 + 1084192]);
                        if (v20)
                            sub_46DC30(*(_DWORD*)& byte_5D4594[4 * v16 + 1090068], v40, (wchar_t*)& byte_587000[146656], v20 + 2096);
                    }
                    else
                    {
                        v21 = sub_46FB50(*(_DWORD*)& byte_5D4594[80 * v32 + 1084204], &v37);
                        sub_46DC60(*(_DWORD*)& byte_5D4594[4 * v16 + 1090068], v37, (int)v21);
                    }
                    ++v32;
                } while (v32 < (unsigned __int8)a2);
                v9 = *(_DWORD*)& byte_5D4594[1090120];
                v2 = v35;
            }
        }
        else if (v9 == 1)
        {
            sub_46FFD0();
            v9 = *(_DWORD*)& byte_5D4594[1090120];
        }
        switch (v9)
        {
        case 1:
        case 2:
        case 4:
        case 5:
            switch (v9)
            {
            case 2:
                v22 = loadString_sub_40F1D0((char*)& byte_587000[146704], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1475);
                break;
            case 4:
                v22 = loadString_sub_40F1D0((char*)& byte_587000[146756], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1479);
                break;
            case 5:
                v22 = loadString_sub_40F1D0((char*)& byte_587000[146800], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1483);
                break;
            case 1:
                v22 = loadString_sub_40F1D0((char*)& byte_587000[146844], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1487);
                break;
            default:
                v22 = (wchar_t*)a2;
                break;
            }
            if (!sub_40A5C0(1) || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
            {
                if (*(_DWORD*)& byte_5D4594[1090120] == 1)
                {
                    v28 = sub_450B10();
                    v23 = loadString_sub_40F1D0((char*)& byte_587000[146900], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1499);
                    nox_swprintf((wchar_t*)& byte_5D4594[1086692], L"%s %d", v23, v28);
                }
                else
                {
                    v29 = byte_5D4594[1090118];
                    v27 = (unsigned __int8)sub_46FEE0();
                    v24 = loadString_sub_40F1D0((char*)& byte_587000[146968], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1501);
                    nox_swprintf((wchar_t*)& byte_5D4594[1086692], L"%s %d / %d", v24, v27, v29);
                }
            }
            break;
        case 3:
            if (v2)
            {
                v33 = 1;
                v25 = (unsigned __int8)sub_46FF70(*((_DWORD*)v2 + 13));
            }
            else
            {
                v25 = 0;
            }
            v22 = loadString_sub_40F1D0((char*)& byte_587000[147040], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1519);
            if (!sub_40A5C0(1) || !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
            {
                v30 = byte_5D4594[1090116];
                v26 = loadString_sub_40F1D0((char*)& byte_587000[147084], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1525);
                nox_swprintf((wchar_t*)& byte_5D4594[1086692], L"%s %d / %d", v26, v25, v30);
            }
            break;
        default:
            v22 = (wchar_t*)a2;
            break;
        }
        if (v33)
        {
            if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090100]))
                nox_window_set_hidden(*(int*)& byte_5D4594[1090100], 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[1090100], 16385, (int)& byte_5D4594[1086692], 0);
        }
        else if (!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090100]))
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[1090100], 1);
        }
        nox_window_call_field_94(*(int*)& byte_5D4594[1090104], 16385, (int)v22, 0);
        sub_46FC50();
        sub_46FD80();
    }
    if ((int) * (_DWORD*)& byte_587000[145672] >= 0)
        sub_46FAE0();
    return 1;
}

//----- (0046F8F0) --------------------------------------------------------
wchar_t* __cdecl sub_46F8F0(int a1, int a2)
{
    int v2; // edi
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t* v6; // [esp-14h] [ebp-1Ch]
    wchar_t* v7; // [esp-14h] [ebp-1Ch]
    wchar_t* v8; // [esp-14h] [ebp-1Ch]

    v2 = a2;
    if (a2 > 0)
    {
        do
        {
            sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090060], 9u, (int)& byte_587000[147124]);
            sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090068], 9u, (int)& byte_587000[147128]);
            sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090076], 9u, (int)& byte_587000[147132]);
            sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090084], 9u, (int)& byte_587000[147136]);
            sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090092], 9u, (int)& byte_587000[147140]);
            --v2;
        } while (v2);
    }
    v3 = loadString_sub_40F1D0((char*)& byte_587000[147180], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 189);
    sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090060], 9u, (int)v3);
    sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090068], 9u, (int)& byte_587000[147188]);
    if (*(_DWORD*)& byte_5D4594[1090120] == 1)
        v6 = loadString_sub_40F1D0((char*)& byte_587000[147228], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 193);
    else
        v6 = loadString_sub_40F1D0((char*)& byte_587000[147280], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 195);
    sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090076], 9u, (int)v6);
    if (*(_DWORD*)& byte_5D4594[1090120] == 5)
    {
        v7 = loadString_sub_40F1D0((char*)& byte_587000[147324], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 199);
        sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090084], 9u, (int)v7);
    }
    else
    {
        if (*(_DWORD*)& byte_5D4594[1090120] == 1)
            v8 = loadString_sub_40F1D0((char*)& byte_587000[147368], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 201);
        else
            v8 = loadString_sub_40F1D0((char*)& byte_587000[147420], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 203);
        sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090084], 9u, (int)v8);
    }
    if (*(_DWORD*)& byte_5D4594[1090120] == 1)
        v4 = loadString_sub_40F1D0((char*)& byte_587000[147464], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 207);
    else
        v4 = loadString_sub_40F1D0((char*)& byte_587000[147508], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 209);
    return sub_46DC60(*(_DWORD*)& byte_5D4594[4 * a1 + 1090092], 9u, (int)v4);
}

//----- (0046FAE0) --------------------------------------------------------
void sub_46FAE0()
{
    int yTop; // [esp+0h] [ebp-8h]
    int v1; // [esp+4h] [ebp-4h]

    sub_46AA60(*(_DWORD * *)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1088996] + 1090060], &v1, &yTop);
    yTop += *(_DWORD*)& byte_587000[145672]
        * *(__int16*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1088996] + 1090060] + 32) + 2)
        + *(__int16*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[1088996] + 1090060] + 32) + 2)
        / 2;
    sub_434460(*(int*)& byte_5D4594[2589772]);
    sub_499B70(v1 + 1, yTop, 3);
}

//----- (0046FB50) --------------------------------------------------------
wchar_t* __cdecl sub_46FB50(int a1, _BYTE* a2)
{
    wchar_t* v2; // eax
    wchar_t* result; // eax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax

    switch (a1)
    {
    case 4:
        v2 = loadString_sub_40F1D0((char*)& byte_587000[147552], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 244);
        nox_swprintf((wchar_t*)& byte_5D4594[1090024], L"<%s", v2);
        *a2 = 4;
        result = (wchar_t*)& byte_5D4594[1090024];
        break;
    case 1:
        v4 = loadString_sub_40F1D0((char*)& byte_587000[147604], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 250);
        nox_swprintf((wchar_t*)& byte_5D4594[1090024], L"<%s", v4);
        result = (wchar_t*)& byte_5D4594[1090024];
        *a2 = 4;
        break;
    case 2:
        v5 = loadString_sub_40F1D0((char*)& byte_587000[147656], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 256);
        nox_swprintf((wchar_t*)& byte_5D4594[1090024], L"<%s", v5);
        result = (wchar_t*)& byte_5D4594[1090024];
        *a2 = 7;
        break;
    case 3:
        v6 = loadString_sub_40F1D0((char*)& byte_587000[147708], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 262);
        nox_swprintf((wchar_t*)& byte_5D4594[1090024], L"<%s", v6);
        *a2 = 13;
        result = (wchar_t*)& byte_5D4594[1090024];
        break;
    default:
        result = (wchar_t*)& byte_587000[147724];
        *a2 = 4;
        break;
    }
    return result;
}

//----- (0046FC50) --------------------------------------------------------
char sub_46FC50()
{
    __int16 v0; // ax
    __int16 v1; // ax
    int v2; // eax
    int v3; // eax
    wchar_t* v4; // eax
    int v6; // [esp-Ch] [ebp-Ch]
    int v7; // [esp-8h] [ebp-8h]

    if (sub_40A220() && (!sub_40A5C0(1) || sub_40A300() || (v0 = sub_40A5B0(), sub_40A180(v0))))
    {
        if (!sub_40A5C0(1) || sub_40A300() || (v1 = sub_40A5B0(), LOBYTE(v2) = sub_40A180(v1), (_BYTE)v2))
        {
            if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090108]))
                nox_window_set_hidden(*(int*)& byte_5D4594[1090108], 0);
            v3 = sub_40A230();
            v7 = v3 % 60000 / 1000;
            v6 = v3 / 60000;
            v4 = loadString_sub_40F1D0((char*)& byte_587000[147764], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 352);
            nox_swprintf((wchar_t*)& byte_5D4594[1084068], v4, v6, v7);
            LOBYTE(v2) = nox_window_call_field_94(*(int*)& byte_5D4594[1090108], 16385, (int)& byte_5D4594[1084068], 0);
        }
    }
    else
    {
        v2 = wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090108]);
        if (!v2)
            LOBYTE(v2) = nox_window_set_hidden(*(int*)& byte_5D4594[1090108], 1);
    }
    return v2;
}

//----- (0046FD80) --------------------------------------------------------
int sub_46FD80()
{
    int result; // eax
    __int16 v1; // ax
    int v2; // eax
    wchar_t* v3; // eax
    int v4; // [esp-4h] [ebp-4h]

    if (sub_40A5C0(4224))
    {
        result = wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090112]);
        if (!result)
            result = nox_window_set_hidden(*(int*)& byte_5D4594[1090112], 1);
    }
    else
    {
        if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090112]))
            nox_window_set_hidden(*(int*)& byte_5D4594[1090112], 0);
        if (sub_40A5C0(1))
        {
            v1 = sub_40A5B0();
            v2 = (unsigned __int16)sub_40A020(v1);
        }
        else
        {
            v2 = *((unsigned __int16*)sub_416590(0) + 27);
        }
        v4 = v2;
        v3 = loadString_sub_40F1D0((char*)& byte_587000[147816], 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 390);
        nox_swprintf((wchar_t*)& byte_5D4594[1083972], v3, v4);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[1090112], 16385, (int)& byte_5D4594[1083972], 0);
    }
    return result;
}

//----- (0046FE60) --------------------------------------------------------
unsigned __int8 __cdecl sub_46FE60(int a1)
{
    unsigned __int8 result; // al
    unsigned __int8 v2; // [esp+8h] [ebp-4h]

    result = 0;
    v2 = 0;
    if (!byte_5D4594[1090116])
        return 0;
    while (*(_DWORD*)& byte_5D4594[56 * v2 + 1087248] != a1)
    {
        v2 = ++result;
        if (result >= byte_5D4594[1090116])
            return 0;
    }
    return result;
}

//----- (0046FEB0) --------------------------------------------------------
unsigned __int8 __cdecl sub_46FEB0(unsigned __int8 a1)
{
    return byte_587000[8 * (byte_5D4594[56 * a1 + 1087256] % 10) + 145584];
}

//----- (0046FEE0) --------------------------------------------------------
char sub_46FEE0()
{
    int v0; // eax
    char v1; // bl
    unsigned __int8* i; // edx
    int v4; // esi
    int v5; // ecx
    unsigned __int8* v6; // eax
    int v7; // ecx
    unsigned __int8* v8; // eax

    v0 = 0;
    v1 = 1;
    if (!byte_5D4594[1090117])
        return 0;
    for (i = &byte_5D4594[1084192]; *(_DWORD*)i != *(_DWORD*)& byte_5D4594[2616328]; i += 80)
    {
        if (++v0 >= (unsigned int)byte_5D4594[1090117])
            return 0;
    }
    v4 = *(_DWORD*)& byte_5D4594[80 * v0 + 1084196];
    if (!sub_40A5C0(1024))
    {
        v7 = byte_5D4594[1090117];
        if (byte_5D4594[1090117])
        {
            v8 = &byte_5D4594[1084196];
            do
            {
                if (*(_DWORD*)v8 > v4)
                    ++v1;
                v8 += 80;
                --v7;
            } while (v7);
        }
        return v1;
    }
    v5 = byte_5D4594[1090117];
    if (!byte_5D4594[1090117])
        return v1;
    v6 = &byte_5D4594[1084196];
    do
    {
        if (*(_DWORD*)v6 < v4)
            ++v1;
        v6 += 80;
        --v5;
    } while (v5);
    return v1;
}

//----- (0046FF70) --------------------------------------------------------
char __cdecl sub_46FF70(int a1)
{
    char v1; // bl
    int v2; // ecx
    unsigned __int8* v3; // eax
    int v5; // ecx
    unsigned __int8* v6; // eax

    v1 = 1;
    if (!sub_40A5C0(1024))
    {
        v5 = byte_5D4594[1090116];
        if (byte_5D4594[1090116])
        {
            v6 = &byte_5D4594[1087252];
            do
            {
                if (*(_DWORD*)v6 > a1)
                    ++v1;
                v6 += 56;
                --v5;
            } while (v5);
        }
        return v1;
    }
    v2 = byte_5D4594[1090116];
    if (!byte_5D4594[1090116])
        return v1;
    v3 = &byte_5D4594[1087252];
    do
    {
        if (*(_DWORD*)v3 < a1)
            ++v1;
        v3 += 56;
        --v2;
    } while (v2);
    return v1;
}

//----- (0046FFD0) --------------------------------------------------------
unsigned __int8 sub_46FFD0()
{
    unsigned __int8 result; // al
    int v1; // ebx
    unsigned __int8* v2; // ebp
    char* v3; // eax
    unsigned __int8* v4; // esi
    unsigned __int8 v5; // al
    unsigned __int8 v6; // di
    int v7; // edx
    int v8; // eax
    int v9; // eax
    int v10; // eax
    wchar_t* v11; // eax
    int v12; // eax
    int v13; // edx
    int v14; // eax
    unsigned __int8 v15; // cl
    float v16; // [esp+0h] [ebp-4Ch]
    int v17; // [esp+14h] [ebp-38h]
    int v18; // [esp+18h] [ebp-34h]
    int v19; // [esp+1Ch] [ebp-30h]
    int v20; // [esp+20h] [ebp-2Ch]
    int v21; // [esp+24h] [ebp-28h]
    int v22; // [esp+28h] [ebp-24h]
    int v23; // [esp+2Ch] [ebp-20h]
    int v24; // [esp+30h] [ebp-1Ch]
    float v25; // [esp+34h] [ebp-18h]
    int v26; // [esp+38h] [ebp-14h]
    int v27; // [esp+3Ch] [ebp-10h]
    int v28; // [esp+40h] [ebp-Ch]
    int v29; // [esp+44h] [ebp-8h]
    int v30; // [esp+48h] [ebp-4h]

    sub_46DB80();
    sub_46F8F0(0, 0);
    result = byte_5D4594[1090117];
    v23 = 0;
    if (byte_5D4594[1090117])
    {
        v1 = 1;
        v2 = &byte_5D4594[1084184];
        do
        {
            v3 = sub_417040(*((_DWORD*)v2 + 2));
            v4 = (unsigned __int8*)v3;
            if (v3 && *((_DWORD*)v3 + 1198))
            {
                if (v2[24] & 1)
                {
                    LOBYTE(v21) = 9;
                }
                else if (*(int*)v2 == -1)
                {
                    LOBYTE(v21) = 4;
                }
                else
                {
                    v5 = sub_46FE60(*(_DWORD*)v2);
                    LOBYTE(v21) = sub_46FEB0(v5);
                }
                if (*((_DWORD*)v2 + 2) == *(_DWORD*)& byte_5D4594[2616328])
                {
                    *(_DWORD*)& byte_587000[145672] = *(__int16*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[1090060] + 32) + 46);
                    *(_DWORD*)& byte_5D4594[1088996] = 0;
                }
                v6 = v21;
                sub_46DC30(*(int*)& byte_5D4594[1090060], v21, (wchar_t*)& byte_587000[147828], v2 - 52);
                sub_46DC30(*(int*)& byte_5D4594[1090076], v6, (wchar_t*)& byte_587000[147836], v4[4816]);
                v7 = *((_DWORD*)v2 + 2);
                v8 = v4[2282];
                LOBYTE(v22) = 4;
                if (v7 == *(_DWORD*)& byte_5D4594[2616328])
                {
                    v9 = sub_470CD0();
                    v24 = v9;
                    v25 = (double)v9;
                    v10 = sub_470CC0();
                    v24 = v10;
                    v16 = (double)v10 / v25 * 100.0;
                    v8 = sub_419A70(v16);
                }
                if (v8 > 25)
                {
                    if (v8 <= 50)
                        LOBYTE(v22) = 15;
                }
                else
                {
                    LOBYTE(v22) = 6;
                }
                sub_46DC30(*(int*)& byte_5D4594[1090084], v22, (wchar_t*)& byte_587000[147844], v8);
                sub_46DC30(
                    *(int*)& byte_5D4594[1090092],
                    v6,
                    (wchar_t*)& byte_587000[147856],
                    *(_DWORD*)& byte_5D4594[4 * v2[4] + 1084056]);
                v11 = sub_46FB50(*((_DWORD*)v2 + 5), &v26);
                sub_46DC60(*(int*)& byte_5D4594[1090068], v26, (int)v11);
                if (v4[4824])
                {
                    sub_46AA60(*(_DWORD * *)& byte_5D4594[1090068], &v19, &v18);
                    nox_window_get_size(*(int*)& byte_5D4594[1090068], &v28, &v27);
                    v12 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090068] + 32);
                    v19 += 5;
                    v18 = v18 + *(__int16*)(v12 + 2) / 2 + *(__int16*)(v12 + 2) * v1 - 1;
                    sub_434460(*(int*)& byte_5D4594[2523948]);
                    sub_4C3270(v19, v18, 2, *(int*)& byte_5D4594[2523948]);
                    sub_49F500(v19 + 2, v18);
                    sub_49F500(v19 + 9, v18);
                    sub_49E4B0();
                    sub_49F500(v19 + 9, v18);
                    sub_49F500(v19 + 9, v18 + 3);
                    sub_49E4B0();
                    sub_49F500(v19 + 7, v18);
                    sub_49F500(v19 + 7, v18 + 2);
                    sub_49E4B0();
                }
                if (v4[4825])
                {
                    sub_46AA60(*(_DWORD * *)& byte_5D4594[1090068], &v17, &v20);
                    nox_window_get_size(*(int*)& byte_5D4594[1090068], &v30, &v29);
                    v13 = v17 + 5;
                    v14 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090068] + 32);
                    v15 = v4[4824];
                    v17 += 5;
                    if (v15 == 1)
                        v17 = v13 + 15;
                    v20 = v20 + *(__int16*)(v14 + 2) / 2 + *(__int16*)(v14 + 2) * v1 - 1;
                    sub_434460(*(int*)& byte_5D4594[2589772]);
                    sub_4C3270(v17, v20, 2, *(int*)& byte_5D4594[2589772]);
                    sub_49F500(v17 + 2, v20);
                    sub_49F500(v17 + 9, v20);
                    sub_49E4B0();
                    sub_49F500(v17 + 9, v20);
                    sub_49F500(v17 + 9, v20 + 3);
                    sub_49E4B0();
                    sub_49F500(v17 + 7, v20);
                    sub_49F500(v17 + 7, v20 + 2);
                    sub_49E4B0();
                }
                ++v1;
            }
            result = v23 + 1;
            v2 += 80;
            ++v23;
        } while (v23 < byte_5D4594[1090117]);
        *(_DWORD*)& byte_587000[145664] = 1;
    }
    else
    {
        *(_DWORD*)& byte_587000[145664] = 1;
    }
    return result;
}

//----- (004703F0) --------------------------------------------------------
int sub_4703F0()
{
    int result; // eax
    int v1; // edx

    *(_DWORD*)& byte_5D4594[1090120] = (*(_DWORD*)& byte_5D4594[1090120] + 1) % 6;
    result = sub_43AF70();
    v1 = *(_DWORD*)& byte_5D4594[1090120];
    if (result || *(_DWORD*)& byte_5D4594[1090120] != 5)
    {
        if (*(_DWORD*)& byte_5D4594[1090120] == 1)
        {
            result = sub_40A5C0(4096);
            v1 = *(_DWORD*)& byte_5D4594[1090120];
            if (!result)
            {
                result = (*(_DWORD*)& byte_5D4594[1090120] + 1) / 6;
                v1 = (*(_DWORD*)& byte_5D4594[1090120] + 1) % 6;
                *(_DWORD*)& byte_5D4594[1090120] = (*(_DWORD*)& byte_5D4594[1090120] + 1) % 6;
            }
        }
    }
    else
    {
        v1 = 0;
        *(_DWORD*)& byte_5D4594[1090120] = 0;
    }
    switch (v1)
    {
    case 0:
        sub_46B500(0);
        nox_window_set_hidden(*(int*)& byte_5D4594[1090048], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1090100], 1);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090052] + 4) &= 0xFFFFFFF7;
        result = *(_DWORD*)& byte_5D4594[1090056];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090056] + 4) &= 0xFFFFFFF7;
        break;
    case 1:
    case 2:
        sub_46A8C0(*(int*)& byte_5D4594[1090048]);
        sub_46A8C0(*(int*)& byte_5D4594[1090100]);
        nox_window_set_hidden(*(int*)& byte_5D4594[1090100], 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090052] + 4) |= 8u;
        result = *(_DWORD*)& byte_5D4594[1090056];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090056] + 4) |= 8u;
        goto LABEL_10;
    case 3:
    case 4:
    case 5:
    LABEL_10:
        *(_DWORD*)& byte_587000[145664] = 1;
        break;
    default:
        return result;
    }
    return result;
}

//----- (00470510) --------------------------------------------------------
int sub_470510()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1090048];
    if (*(_DWORD*)& byte_5D4594[1090048])
    {
        result = *(_DWORD*)& byte_5D4594[1090120];
        if (*(_DWORD*)& byte_5D4594[1090120] == 2)
        {
            *(_DWORD*)& byte_587000[145664] = 1;
        }
        else
        {
            *(_DWORD*)& byte_587000[145668] = *(_DWORD*)& byte_5D4594[1090120];
            *(_DWORD*)& byte_5D4594[1090120] = 0;
            result = sub_4703F0();
        }
    }
    return result;
}

//----- (00470550) --------------------------------------------------------
int sub_470550()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1090048];
    if (*(_DWORD*)& byte_5D4594[1090048])
    {
        result = *(_DWORD*)& byte_5D4594[1090120];
        if (*(_DWORD*)& byte_5D4594[1090120])
        {
            *(_DWORD*)& byte_5D4594[1090120] = 4;
            result = sub_4703F0();
        }
    }
    return result;
}

//----- (00470580) --------------------------------------------------------
BOOL sub_470580()
{
    return *(_DWORD*)& byte_5D4594[1090120] && wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090048]) != 1;
}

//----- (004705B0) --------------------------------------------------------
int sub_4705B0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[1090048];
    if (*(_DWORD*)& byte_5D4594[1090048])
    {
        if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1090048]))
            nox_window_set_hidden(*(int*)& byte_5D4594[1090048], 0);
        *(_DWORD*)& byte_5D4594[1090120] = 0;
        result = sub_4703F0();
    }
    return result;
}

//----- (004705F0) --------------------------------------------------------
char __cdecl sub_4705F0(char a1, char a2, __int16 a3)
{
    char result; // al

    result = a2;
    if (a2 == 1)
    {
        result = a1;
        if (a1 != 2 && a1)
        {
            if (a1 == 1)
            {
                result = a3;
                *(_WORD*)& byte_5D4594[1090128] = a3;
            }
        }
        else
        {
            *(_WORD*)& byte_5D4594[1090128] = 0;
        }
    }
    else if (a2 == 2)
    {
        result = a1;
        if (a1 != 2 && a1)
        {
            if (a1 == 1)
                * (_WORD*)& byte_5D4594[1090130] = a3;
        }
        else
        {
            *(_WORD*)& byte_5D4594[1090130] = 0;
        }
    }
    return result;
}

//----- (00470650) --------------------------------------------------------
char __cdecl sub_470650(char a1, __int16 a2)
{
    char result; // al

    result = a1;
    if (a1 && a1 != 1)
    {
        if (a1 == 4 || a1 == 2)
        {
            result = a2;
            *(_WORD*)& byte_5D4594[1090132] = a2;
        }
    }
    else
    {
        *(_WORD*)& byte_5D4594[1090132] = 0;
    }
    return result;
}

//----- (00470680) --------------------------------------------------------
int sub_470680()
{
    int result; // eax

    result = 0;
    *(_WORD*)& byte_5D4594[1090128] = 0;
    *(_WORD*)& byte_5D4594[1090130] = 0;
    *(_WORD*)& byte_5D4594[1090132] = 0;
    return result;
}

//----- (004706A0) --------------------------------------------------------
BOOL sub_4706A0()
{
    return *(_DWORD*)& byte_5D4594[1090048] && *(_DWORD*)& byte_5D4594[1090120];
}

//----- (004706C0) --------------------------------------------------------
int __cdecl sub_4706C0(int a1)
{
    int result; // eax

    if (a1 && *(_DWORD*)& byte_5D4594[1090180] && sub_46ADA0(*(int*)& byte_5D4594[1090176]) & 0x10)
        result = sub_46A8C0(*(int*)& byte_5D4594[1090176]);
    else
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1090176], 1);
    return result;
}

//----- (00470710) --------------------------------------------------------
int sub_470710()
{
    int result; // eax

    result = nox_new_window_from_file("GuiFps.wnd", 0);
    *(_DWORD*)& byte_5D4594[1090176] = result;
    if (result)
    {
        sub_46B340(result, sub_470770);
        sub_46A9B0(
            *(_DWORD * *)& byte_5D4594[1090176],
            121,
            nox_win_height - *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090176] + 12) - 5);
        *(_DWORD*)& byte_5D4594[1090140] = sub_43F360((char*)& byte_587000[147880]);
        sub_4706C0(0);
        result = 1;
    }
    return result;
}

//----- (00470770) --------------------------------------------------------
int __cdecl sub_470770(int a1, int a2)
{
    int v1; // ebx
    DWORD v2; // eax
    DWORD v3; // ecx
    unsigned int v4; // eax
    unsigned __int8 v5; // cl
    int v6; // esi
    int v7; // ebp
    int i; // edi
    int v9; // eax
    int v10; // eax
    int xLeft; // [esp+Ch] [ebp-8h]
    int yTop; // [esp+10h] [ebp-4h]

    v1 = a1;
    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if (*(int*)& byte_5D4594[1090256] >= *(int*)& byte_587000[147864])
    {
        *(_DWORD*)& byte_587000[147864] = *(_DWORD*)& byte_5D4594[1090256] + 10;
        v2 = nox_get_ticks();
        v3 = v2;
        v4 = 0x2710 / (v2 - *(_DWORD*)& byte_5D4594[1090268]);
        *(_DWORD*)& byte_5D4594[1090264] = v3;
        *(_DWORD*)& byte_5D4594[1090268] = v3;
        *(_DWORD*)& byte_5D4594[1090260] = v4;
    }
    v5 = byte_5D4594[1090248];
    if (*(_WORD*)& byte_5D4594[1090246])
    {
        *(_WORD*)& byte_5D4594[1090246] = 0;
        ++* (_WORD*)& byte_5D4594[2 * byte_5D4594[1090248] + 1090184];
    }
    *(_DWORD*)& byte_5D4594[1090252] = (*(_DWORD*)& byte_5D4594[1090252] + 1) % 3u;
    if (!*(_DWORD*)& byte_5D4594[1090252])
        byte_5D4594[1090248] = (v5 + 1) % 31;
    sub_49CF10(xLeft, yTop, *(_DWORD*)(v1 + 8), *(_DWORD*)(v1 + 12));
    sub_434390(*(int*)& byte_5D4594[2523948]);
    nox_swprintf((wchar_t*)& byte_5D4594[1090144], L"%d", *(_DWORD*)& byte_5D4594[1090260]);
    sub_43F840(*(int*)& byte_5D4594[1090140], (unsigned __int16*)& byte_5D4594[1090144], &a1, 0, 0);
    sub_43F6E0(
        *(int*)& byte_5D4594[1090140],
        (__int16*)& byte_5D4594[1090144],
        xLeft + (*(int*)(v1 + 8) - a1) / 2,
        yTop + 3);
    v6 = xLeft + 1;
    v7 = yTop + 14;
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_49CE30(v6, v7, 30, 3);
    for (i = 1; i < 31; ++i)
    {
        v9 = *(unsigned __int16*)& byte_5D4594[2 * ((i + byte_5D4594[1090248]) % 31) + 1090184];
        if ((_WORD)v9)
        {
            v10 = v9 - 1;
            if (v10)
            {
                if (v10 == 1)
                {
                    a1 = 2;
                    sub_434460(*(int*)& byte_5D4594[2589772]);
                }
                else
                {
                    a1 = 3;
                    sub_434460(*(int*)& byte_5D4594[2618904]);
                }
            }
            else
            {
                a1 = 1;
                sub_434460(*(int*)& byte_5D4594[2650644]);
            }
            if (a1)
                sub_49CC70(v6, v7 - a1 + 3, 1, a1);
        }
        else
        {
            a1 = 0;
        }
        ++v6;
    }
    if (*(_DWORD*)& byte_5D4594[2614264] / 0xFAu)
    {
        if (*(_DWORD*)& byte_5D4594[2614264] / 0xFAu == 1)
            sub_434390(*(int*)& byte_5D4594[2589772]);
        else
            sub_434390(*(int*)& byte_5D4594[2650644]);
    }
    else
    {
        sub_434390(*(int*)& byte_5D4594[2618904]);
    }
    nox_swprintf((wchar_t*)& byte_5D4594[1090144], L"%d", *(_DWORD*)& byte_5D4594[2614264]);
    sub_43F840(*(int*)& byte_5D4594[1090140], (unsigned __int16*)& byte_5D4594[1090144], &a1, 0, 0);
    sub_43F6E0(
        *(int*)& byte_5D4594[1090140],
        (__int16*)& byte_5D4594[1090144],
        xLeft + (*(int*)(v1 + 8) - a1) / 2,
        yTop + 22);
    sub_434460(*(int*)& byte_5D4594[2614248]);
    sub_49CC70(xLeft, yTop, *(_DWORD*)(v1 + 8), *(_DWORD*)(v1 + 12));
    ++* (_DWORD*)& byte_5D4594[1090256];
    return 1;
}

//----- (00470A50) --------------------------------------------------------
int __cdecl sub_470A50(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1090180] = a1;
    return result;
}

//----- (00470A60) --------------------------------------------------------
int sub_470A60()
{
    *(_DWORD*)& byte_5D4594[1090180] = *(_DWORD*)& byte_5D4594[1090180] == 0;
    return sub_4706C0(1);
}

//----- (00470A80) --------------------------------------------------------
void sub_470A80()
{
    ++* (_WORD*)& byte_5D4594[1090246];
}

//----- (00470A90) --------------------------------------------------------
int sub_470A90()
{
    return *(_DWORD*)& byte_5D4594[1096252];
}

//----- (00470AA0) --------------------------------------------------------
int __cdecl sub_470AA0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1096252] = a1;
    if (*(_DWORD*)& byte_5D4594[1093176])
    {
        if (a1)
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[1093076], 0);
            result = nox_window_set_hidden(*(int*)& byte_5D4594[1093096], 0);
        }
        else
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[1093076], 1);
            result = nox_window_set_hidden(*(int*)& byte_5D4594[1093096], 1);
        }
    }
    return result;
}

//----- (00470B00) --------------------------------------------------------
unsigned __int8* sub_470B00()
{
    unsigned __int8* result; // eax

    *(_DWORD*)& byte_5D4594[1090284] = sub_4344A0(255, 0, 0);
    *(_DWORD*)& byte_5D4594[1090280] = sub_4344A0(100, 0, 0);
    *(_DWORD*)& byte_5D4594[1091964] = sub_4344A0(0, 255, 0);
    *(_DWORD*)& byte_5D4594[1092992] = sub_4344A0(0, 100, 0);
    *(_DWORD*)& byte_5D4594[1093048] = *(_DWORD*)& byte_5D4594[1090284];
    *(_DWORD*)& byte_5D4594[1093052] = *(_DWORD*)& byte_5D4594[1090280];
    *(_DWORD*)& byte_5D4594[1093068] = sub_4344A0(0, 0, 255);
    *(_DWORD*)& byte_5D4594[1093072] = sub_4344A0(0, 0, 100);
    *(_DWORD*)& byte_5D4594[1093128] = sub_4344A0(240, 0, 240);
    *(_DWORD*)& byte_5D4594[1093132] = sub_4344A0(50, 0, 50);
    *(_DWORD*)& byte_5D4594[1093148] = sub_4344A0(255, 0, 255);
    *(_DWORD*)& byte_5D4594[1093152] = sub_4344A0(50, 0, 50);
    *(_DWORD*)& byte_5D4594[1093168] = sub_4344A0(255, 0, 255);
    *(_DWORD*)& byte_5D4594[1093172] = sub_4344A0(50, 0, 50);
    result = &byte_5D4594[1094732];
    do
    {
        *((_DWORD*)result - 384) = 0;
        *(_DWORD*)result = 0;
        result += 24;
    } while ((int)result < (int)& byte_5D4594[1096268]);
    return result;
}

//----- (00470C20) --------------------------------------------------------
int __cdecl sub_470C20(_DWORD* a1, _DWORD* a2)
{
    int result; // eax

    *a1 = *(_DWORD*)& byte_5D4594[1090280];
    result = *(_DWORD*)& byte_5D4594[1090284];
    *a2 = *(_DWORD*)& byte_5D4594[1090284];
    return result;
}

//----- (00470C40) --------------------------------------------------------
int __cdecl sub_470C40(int a1)
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1096264] = a1;
    if (a1)
    {
        result = *(_DWORD*)& byte_5D4594[1091964];
        *(_DWORD*)& byte_5D4594[1093048] = *(_DWORD*)& byte_5D4594[1091964];
        *(_DWORD*)& byte_5D4594[1093052] = *(_DWORD*)& byte_5D4594[1092992];
    }
    else
    {
        result = *(_DWORD*)& byte_5D4594[1090280];
        *(_DWORD*)& byte_5D4594[1093048] = *(_DWORD*)& byte_5D4594[1090284];
        *(_DWORD*)& byte_5D4594[1093052] = *(_DWORD*)& byte_5D4594[1090280];
    }
    return result;
}

//----- (00470C80) --------------------------------------------------------
int __cdecl sub_470C80(int a1, int a2)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2618908])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 2247) = a2;
    result = a1;
    *(_DWORD*)& byte_5D4594[1093044] = a2;
    *(_DWORD*)& byte_5D4594[1093040] = a1;
    *(_DWORD*)& byte_5D4594[1096260] = 32;
    return result;
}

//----- (00470CB0) --------------------------------------------------------
int __cdecl sub_470CB0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1093040] = a1;
    return result;
}

//----- (00470CC0) --------------------------------------------------------
int sub_470CC0()
{
    return *(_DWORD*)& byte_5D4594[1093040];
}

//----- (00470CD0) --------------------------------------------------------
int sub_470CD0()
{
    return *(_DWORD*)& byte_5D4594[1093044];
}

//----- (00470CE0) --------------------------------------------------------
int __cdecl sub_470CE0(int a1, int a2)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2618908])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 2243) = a2;
    result = a1;
    *(_DWORD*)& byte_5D4594[1093064] = a2;
    *(_DWORD*)& byte_5D4594[1093060] = a1;
    *(_DWORD*)& byte_5D4594[1096260] = 32;
    return result;
}

//----- (00470D10) --------------------------------------------------------
int __cdecl sub_470D10(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1093060] = a1;
    return result;
}

//----- (00470D20) --------------------------------------------------------
int __cdecl sub_470D20(int a1, int a2)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[1093120] = a1;
    *(_DWORD*)& byte_5D4594[1093124] = a2;
    if (a1 != a2)
        result = sub_4160D0(17);
    return result;
}

//----- (00470D40) --------------------------------------------------------
BOOL sub_470D40()
{
    return !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1093136]) || !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[1093156]);
}

//----- (00470D70) --------------------------------------------------------
int sub_470D70()
{
    nox_window_set_hidden(*(int*)& byte_5D4594[1093136], 1);
    return nox_window_set_hidden(*(int*)& byte_5D4594[1093156], 1);
}

//----- (00470D90) --------------------------------------------------------
int __cdecl sub_470D90(int a1, int a2)
{
    int result; // eax

    nox_window_set_hidden(*(int*)& byte_5D4594[1093136], 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[1093156], 0);
    result = a1;
    *(_DWORD*)& byte_5D4594[1093140] = a1;
    *(_DWORD*)& byte_5D4594[1093144] = a2;
    *(_DWORD*)& byte_5D4594[1093160] = a1;
    *(_DWORD*)& byte_5D4594[1093164] = a2;
    return result;
}

//----- (00470DD0) --------------------------------------------------------
int sub_470DD0()
{
    return *(_DWORD*)& byte_5D4594[1093060];
}

//----- (00470DE0) --------------------------------------------------------
int sub_470DE0()
{
    int result; // eax
    int v1; // ebp
    int v2; // edx
    int v3; // esi

    result = *(_DWORD*)& byte_5D4594[2616328];
    if (*(_DWORD*)& byte_5D4594[2616328])
    {
        v1 = *(_DWORD*)& byte_5D4594[1093040];
        if (*(int*)& byte_5D4594[1093040] >= 1)
        {
            result = -858993458 * *(_DWORD*)& byte_5D4594[1093044];
            v2 = 2 * *(_DWORD*)& byte_5D4594[1093044] / 5;
            v3 = v2;
            if (*(_DWORD*)& byte_5D4594[1093040] < v2)
            {
                *(_DWORD*)& byte_5D4594[1091960] = *(_DWORD*)& byte_5D4594[2649704] / 3u
                    + *(_DWORD*)& byte_5D4594[1093040]
                    * ((unsigned int)(3 * *(_DWORD*)& byte_5D4594[2649704]) >> 2)
                    / v2;
                result = sub_4160F0(4u, *(_DWORD*)& byte_5D4594[1091960] - 1);
                if (result)
                {
                    sub_452D80(896, 66 * (v3 - v1) / v3 + 33);
                    result = sub_4160D0(4);
                }
            }
        }
    }
    return result;
}

//----- (00470E90) --------------------------------------------------------
int __cdecl sub_470E90(int a1, int a2)
{
    int result; // eax

    switch (a2)
    {
    case 5:
        sub_4672C0();
        goto LABEL_4;
    case 8:
    case 12:
    case 16:
        result = 0;
        break;
    default:
    LABEL_4:
        result = 1;
        break;
    }
    return result;
}

//----- (00470EE0) --------------------------------------------------------
void __cdecl nox_win_init_cur_weapon(nox_window* a1, int a2, int a3, int w, int h)
{
    nox_win_cur_weapon = nox_window_new(a1, 0x408, a2, a3, w, h, 0);
    nox_window_set_all_funcs(nox_win_cur_weapon, sub_470E90, sub_470F40_draw, sub_4710B0);
    nox_win_cur_weapon->field_8 = 4;
}

//----- (00470F40) --------------------------------------------------------
int __cdecl sub_470F40_draw(nox_window* win)
{
    int v2; // eax
    unsigned __int8* v3; // edi
    int v4; // ebx
    int v5; // esi
    int v6; // ecx
    int v7; // eax
    double v8; // st7
    double v9; // st6
    int v12; // [esp+10h] [ebp-1Ch]
    int v14; // [esp+18h] [ebp-14h]
    int v16; // [esp+20h] [ebp-Ch]
    int v17; // [esp+24h] [ebp-8h]
    int v18; // [esp+30h] [ebp+4h]

    v2 = 5 * win->field_8;
    v18 = 1;
    v3 = &byte_5D4594[4 * v2 + 1093036];
    sub_46AA60(win, &v14, &v16);

    int w;
    int h;
    nox_window_get_size(win, &w, &h);
    v4 = w / 2;
    v17 = w / 2 + v14;
    v5 = h / 2 + v16;

    v6 = *((int*)v3 + 2);
    if (v6)
        v12 = (*((int*)v3 + 1) << 8) / v6;
    else
        v18 = 0;
    *((_DWORD*)v3 + 4) = *((_DWORD*)v3 + 3);
    if (!v18) {
        sub_465D50_draw(win);
        return 1;
    }
    if (v12 >= 256) {
        v7 = sub_4678D0();
        if (v7) {
            v8 = (double) * (unsigned __int16*)(v7 + 292);
            v9 = (double) * (unsigned __int16*)(v7 + 294);
            if (v8 < v9 * *(double*)& byte_581450[9608]) {
                *((_DWORD*)v3 + 4) = *(_DWORD*)& byte_5D4594[2650644];
                v12 = 1;
            } else if (v8 < v9 * *(double*)& byte_581450[9544]) {
                *((_DWORD*)v3 + 4) = *(_DWORD*)& byte_5D4594[2589772];
                v12 = 1;
            } else {
                v18 = 0;
                v12 = 1;
            }
        } else {
            v18 = 0;
            v12 = 1;
        }
    }
    if (v18) {
        sub_434560(1);
        sub_434580(0x40u);
        sub_4AE6F0(v17, v5, v4, v12, *((_DWORD*)v3 + 4));
        sub_434560(0);
    }
    sub_465D50_draw(win);
    return 1;
}
// 470FE2: variable 'v12' is possibly undefined

//----- (004710B0) --------------------------------------------------------
int sub_4710B0()
{
    wchar_t* v0; // eax
    wchar_t* v1; // esi
    wchar_t* v2; // eax
    int v3; // eax
    wchar_t* v4; // esi
    wchar_t* v5; // eax
    int result; // eax
    wchar_t* v7; // eax

    v0 = (wchar_t*)sub_4615C0();
    v1 = v0;
    if (v0)
    {
        v2 = sub_4BF050(v0);
        nox_wcscpy((wchar_t*)& byte_5D4594[1091968], v2);
        if (v1[58] & 0xC)
        {
            v3 = *(_DWORD*)& byte_5D4594[1096292];
            if (!*(_DWORD*)& byte_5D4594[1096292])
            {
                v3 = sub_4E3AA0((CHAR*)& byte_587000[148392]);
                *(_DWORD*)& byte_5D4594[1096292] = v3;
            }
            v4 = (wchar_t*)sub_461600(v3);
            if (v4)
            {
                nox_wcscat((wchar_t*)& byte_5D4594[1091968], L"\n");
                v5 = sub_4BF050(v4);
                nox_wcscat((wchar_t*)& byte_5D4594[1091968], v5);
            }
        }
        sub_4776B0((wchar_t*)& byte_5D4594[1091968]);
        result = 1;
    }
    else
    {
        v7 = loadString_sub_40F1D0((char*)& byte_587000[148444], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 881);
        sub_4776B0(v7);
        result = 1;
    }
    return result;
}

//----- (00471160) --------------------------------------------------------
int __cdecl sub_471160(int a1, int a2, int a3, int a4, int a5)
{
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    int result; // eax

    *(_DWORD*)& byte_5D4594[1093136] = nox_window_new(a1, 1032, a2, a3, a4, a5, 0);
    *(_DWORD*)& byte_5D4594[1093156] = nox_window_new(a1, 1032, a2 - 17, a3 - 15, 15, 15, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093136], 0, sub_471250, 0);
    v5 = loadString_sub_40F1D0((char*)& byte_587000[148504], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 921);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1093136] + 36), v5);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093156], 0, sub_471450, 0);
    v6 = loadString_sub_40F1D0((char*)& byte_587000[148560], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 925);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1093156] + 36), v6);
    result = *(_DWORD*)& byte_5D4594[1093136];
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093136] + 32) = 5;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093156] + 32) = 6;
    return result;
}

//----- (00471250) --------------------------------------------------------
int __cdecl sub_471250(_DWORD* a1)
{
    unsigned __int8* v1; // esi
    int v2; // edi
    unsigned __int8* v3; // esi
    int result; // eax
    int v5; // eax
    int v6; // ecx
    int v7; // ebx
    int v8; // ebp
    int v9; // ecx
    int v10; // esi
    int v11; // edi
    double v12; // st7
    int v13; // eax
    unsigned __int8* v14; // esi
    int v15; // [esp+10h] [ebp-1Ch]
    int v16; // [esp+14h] [ebp-18h]
    int v17; // [esp+18h] [ebp-14h]
    int v18; // [esp+1Ch] [ebp-10h]
    int v19; // [esp+20h] [ebp-Ch]
    unsigned __int8* v20; // [esp+24h] [ebp-8h]
    float v21; // [esp+28h] [ebp-4h]
    float v22; // [esp+30h] [ebp+4h]

    v20 = &byte_5D4594[20 * a1[8] + 1093036];
    v1 = v20;
    sub_46AA60(a1, &v18, &v17);
    v2 = 1;
    if (*((int*)v1 + 2) >= 1)
    {
        v15 = 1;
        v5 = sub_430B40_get_mouse_prev_seq();
        v6 = *((_DWORD*)v1 + 2);
        v19 = v5;
        if (v6 > 30)
        {
            v15 = 0;
            v2 = 0;
        }
        v7 = (v2 + 61) / v6 - v2;
        v8 = 61 - v7;
        v22 = 0.001;
        v16 = 0;
        v21 = (double)(v2 - v6 * ((v2 + 61) / v6) + 61) / (double)v6;
        if (v6 > 0)
        {
            while (1)
            {
                if (v16 >= *((_DWORD*)v1 + 1))
                    v9 = *((_DWORD*)v1 + 4);
                else
                    v9 = *((_DWORD*)v1 + 3);
                v10 = v8;
                v8 -= v7 + v2;
                v11 = v7;
                if (v7 <= 0)
                    v11 = 1;
                v12 = v22 + v21;
                v22 = v12;
                if (v12 >= *(double*)& byte_581450[9512])
                {
                    --v8;
                    --v10;
                    ++v11;
                    v22 = v22 - *(double*)& byte_581450[9512];
                }
                sub_434460(v9);
                sub_434560(1);
                if (v10 < 0)
                {
                    v13 = -v10;
                    v10 = 0;
                    v11 -= v13;
                }
                if (v11 > 0)
                {
                    v14 = &byte_587000[8 * v10 + 147905];
                    do
                    {
                        if ((int)v14 >= (int)& byte_587000[148393])
                            break;
                        if (*(_DWORD*)(v14 + 3) != v19)
                        {
                            sub_49CE30(v18 + *(v14 - 1), v17 + *v14, v14[1], 1);
                            *(_DWORD*)(v14 + 3) = v19;
                        }
                        v14 += 8;
                        --v11;
                    } while (v11 > 0);
                }
                sub_434560(0);
                if (++v16 >= *((_DWORD*)v20 + 2))
                    break;
                v2 = v15;
                v1 = v20;
            }
        }
        result = 1;
    }
    else
    {
        sub_434460(*((_DWORD*)v1 + 3));
        sub_434560(1);
        v3 = &byte_587000[147905];
        do
        {
            sub_49CE30(v18 + *(v3 - 1), v17 + *v3, v3[1], 1);
            v3 += 8;
        } while ((int)v3 < (int)& byte_587000[148393]);
        sub_434560(0);
        result = 1;
    }
    return result;
}

//----- (00471450) --------------------------------------------------------
int __cdecl sub_471450(_DWORD* a1)
{
    _DWORD* v1; // esi
    int v3; // [esp+4h] [ebp-10h]
    int v4; // [esp+8h] [ebp-Ch]
    WCHAR WideCharStr[4]; // [esp+Ch] [ebp-8h]

    v1 = a1;
    _itow(*(_DWORD*)& byte_5D4594[20 * a1[8] + 1093040], WideCharStr, 10);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F840(*(int*)& byte_5D4594[1096288], WideCharStr, &v3, 0, 0);
    sub_46AA60(v1, &v4, &a1);
    sub_43F6E0(*(int*)& byte_5D4594[1096288], (__int16*)WideCharStr, v4 - v3 / 2 + 8, (int)a1 + 1);
    return 1;
}

//----- (004714E0) --------------------------------------------------------
int sub_4714E0()
{
    int v1; // edi
    unsigned __int8* v2; // esi
    wchar_t* v3; // eax
    int v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    int v7; // eax
    _DWORD* v8; // esi
    char* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    _DWORD* v12; // esi
    char* v13; // eax
    wchar_t* v14; // eax
    char v15[32]; // [esp+4h] [ebp-20h]

    if (!*(_DWORD*)& byte_5D4594[2618908])
        return 0;
    *(_DWORD*)& byte_5D4594[1096288] = sub_43F360((char*)& byte_587000[148576]);
    *(_DWORD*)& byte_5D4594[1096264] = 0;
    *(_DWORD*)& byte_5D4594[1096256] = 0;
    *(_DWORD*)& byte_5D4594[1096260] = 0;
    *(_DWORD*)& byte_5D4594[1091908] = 0;
    *(_DWORD*)& byte_5D4594[1091912] = 0;
    *(_DWORD*)& byte_5D4594[1091916] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1091920] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1091940] = nox_win_width;
    *(_DWORD*)& byte_5D4594[1091944] = nox_win_height;
    *(_DWORD*)& byte_5D4594[1091924] = 0;
    *(_DWORD*)& byte_5D4594[1091928] = 0;
    v1 = 0;
    v2 = &byte_5D4594[1092996];
    do
    {
        nox_sprintf(v15, "HealthMana%d", ++v1);
        *(_DWORD*)v2 = sub_42F970(v15);
        v2 += 4;
    } while ((int)v2 < (int)& byte_5D4594[1093036]);
    if (!*(_DWORD*)& byte_5D4594[1096268])
    {
        *(_DWORD*)& byte_5D4594[1096268] = sub_44CFC0((CHAR*)& byte_587000[148600]);
        *(_DWORD*)& byte_5D4594[1096272] = sub_44CFC0((CHAR*)& byte_587000[148612]);
        *(_DWORD*)& byte_5D4594[1096276] = sub_44CFC0((CHAR*)& byte_587000[148624]);
        *(_DWORD*)& byte_5D4594[1096280] = sub_44CFC0((CHAR*)& byte_587000[148644]);
        *(_DWORD*)& byte_5D4594[1096284] = sub_44CFC0((CHAR*)& byte_587000[148656]);
    }
    *(_DWORD*)& byte_5D4594[1090276] = nox_window_new(
        0,
        136,
        nox_win_width - 91,
        nox_win_height - 201,
        91,
        201,
        0);
    sub_46AE60(*(int*)& byte_5D4594[1090276], *(int*)& byte_5D4594[1092996]);
    *(_DWORD*)& byte_5D4594[1091364] = nox_window_new(*(int*)& byte_5D4594[1090276], 8, 6, 166, 28, 30, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1091364], sub_471B90, sub_471A80, 0);
    v3 = loadString_sub_40F1D0((char*)& byte_587000[148704], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1029);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1091364] + 36), v3);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1091364] + 32) = 2;
    *(_WORD*)& byte_5D4594[1091384] = 0;
    v4 = nox_get_thing(*(int*)& byte_5D4594[1096276]);
    if (v4)
    {
        sub_44D0C0(COERCE_FLOAT(&byte_5D4594[1091388]), *(_DWORD*)(v4 + 28));
        *(_DWORD*)& byte_5D4594[1091368] = &byte_5D4594[1091388];
        if (byte_5D4594 != (unsigned __int8*)-1091388)
            * (_DWORD*)& byte_5D4594[1091508] |= 0x40000000u;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1091368] = 0;
    }
    *(_DWORD*)& byte_5D4594[1091380] = *(_DWORD*)& byte_5D4594[1096276];
    *(_DWORD*)& byte_5D4594[1090292] = nox_window_new(*(int*)& byte_5D4594[1090276], 8, 34, 166, 28, 30, 0);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1090292], sub_471B90, sub_471A80, 0);
    v5 = loadString_sub_40F1D0((char*)& byte_587000[148764], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1060);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1090292] + 36), v5);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090292] + 32) = 0;
    *(_WORD*)& byte_5D4594[1090312] = 0;
    *(_DWORD*)& byte_5D4594[1090296] = 0;
    *(_DWORD*)& byte_5D4594[1090308] = 0;
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
    {
        *(_DWORD*)& byte_5D4594[1090828] = nox_window_new(*(int*)& byte_5D4594[1090276], 8, 62, 166, 28, 30, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1090828], sub_471B90, sub_471A80, 0);
        v6 = loadString_sub_40F1D0((char*)& byte_587000[148820], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1083);
        sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1090828] + 36), v6);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1090828] + 32) = 1;
        *(_WORD*)& byte_5D4594[1090848] = 0;
        v7 = nox_get_thing(*(int*)& byte_5D4594[1096272]);
        if (v7)
        {
            sub_44D0C0(COERCE_FLOAT(&byte_5D4594[1090852]), *(_DWORD*)(v7 + 28));
            *(_DWORD*)& byte_5D4594[1090832] = &byte_5D4594[1090852];
            if (byte_5D4594 != (unsigned __int8*)-1090852)
                * (_DWORD*)& byte_5D4594[1090972] |= 0x40000000u;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1090832] = 0;
        }
        *(_DWORD*)& byte_5D4594[1090844] = *(_DWORD*)& byte_5D4594[1096272];
        *(_DWORD*)& byte_5D4594[1091900] = sub_42F970("PoisonTube");
        v8 = nox_window_new(*(int*)& byte_5D4594[1090276], 136, 0, 0, 91, 159, 0);
        v9 = sub_42F970("HealthManaTubes");
        sub_46AE60((int)v8, (int)v9);
        *(_DWORD*)& byte_5D4594[1093056] = nox_window_new((int)v8, 8, 60, 34, 25, 125, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093056], sub_472100, sub_471D10, 0);
        v10 = loadString_sub_40F1D0((char*)& byte_587000[148900], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1122);
        sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1093056] + 36), v10);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093056] + 32) = 1;
        *(_DWORD*)& byte_5D4594[1093036] = nox_window_new((int)v8, 8, 34, 34, 25, 125, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093036], sub_472100, sub_471D10, 0);
        v11 = loadString_sub_40F1D0((char*)& byte_587000[148952], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1135);
        sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1093036] + 36), v11);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093036] + 32) = 0;
        *(_DWORD*)& byte_5D4594[1093076] = nox_window_new(0, 8, 0, 0, 0, 0, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093076], 0, sub_471C00, 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093076] + 32) = 0;
        *(_DWORD*)& byte_5D4594[1093096] = nox_window_new(0, 8, 0, 0, 0, 0, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093096], 0, sub_471C00, 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093096] + 32) = 1;
        *(_DWORD*)& byte_5D4594[1093176] = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1091900] = sub_42F970("WarriorPoisonTube");
        v12 = nox_window_new(*(int*)& byte_5D4594[1090276], 136, 0, 0, 91, 159, 0);
        v13 = sub_42F970("WarriorHealthTube");
        sub_46AE60((int)v12, (int)v13);
        *(_DWORD*)& byte_5D4594[1093036] = nox_window_new((int)v12, 8, 34, 34, 25, 125, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093036], sub_472100, sub_471D10, 0);
        v14 = loadString_sub_40F1D0((char*)& byte_587000[149048], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 1173);
        sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[1093036] + 36), v14);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093036] + 32) = 0;
        *(_DWORD*)& byte_5D4594[1093076] = nox_window_new(0, 24, 0, 0, 0, 0, 0);
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[1093076], 0, sub_471C00, 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1093076] + 32) = 0;
    }
    sub_472280();
    sub_470B00();
    if (sub_40A5C0(4096))
    {
        *(_DWORD*)& byte_5D4594[1096252] = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[1096252] = 0;
        nox_window_set_hidden(*(int*)& byte_5D4594[1093076], 1);
        nox_window_set_hidden(*(int*)& byte_5D4594[1093096], 1);
    }
    return 1;
}

//----- (00471A80) --------------------------------------------------------
int __cdecl sub_471A80(_DWORD* a1)
{
    int v1; // esi
    int v2; // esi
    int v3; // eax
    int v4; // eax
    __int16* v5; // esi
    int v6; // eax
    int v8; // [esp+4h] [ebp-14h]
    wchar_t v9[8]; // [esp+8h] [ebp-10h]

    v1 = a1[8];
    sub_46AA60(a1, &v8, &a1);
    v2 = 536 * v1;
    if (*(_WORD*)& byte_5D4594[v2 + 1090312])
    {
        v3 = *(_DWORD*)& byte_5D4594[v2 + 1090296];
        if (v3)
        {
            *(_DWORD*)(v3 + 12) = v8 + 14;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[v2 + 1090296] + 16) = (char*)a1 + 15;
            (*(void(__cdecl * *)(unsigned __int8*, _DWORD))(*(_DWORD*)& byte_5D4594[v2 + 1090296] + 300))(
                &byte_5D4594[1091908],
                *(_DWORD*)& byte_5D4594[v2 + 1090296]);
        }
        sub_434390(*(int*)& byte_5D4594[2523948]);
        nox_swprintf(v9, L"%d", *(unsigned __int16*)& byte_5D4594[v2 + 1090312]);
        v4 = sub_43F320(*(int*)& byte_5D4594[1096288]);
        sub_43F6E0(*(int*)& byte_5D4594[1096288], (__int16*)v9, v8 - 2, (int)((char*)a1 - v4 + 10));
    }
    v5 = (__int16*)& byte_5D4594[v2 + 1090300];
    if (v5)
    {
        v6 = sub_43F320(*(int*)& byte_5D4594[1096288]);
        sub_43F6E0(*(int*)& byte_5D4594[1096288], v5, v8 - 2, (int)((char*)a1 - v6 + 33));
    }
    return 1;
}

//----- (00471B90) --------------------------------------------------------
int __cdecl sub_471B90(int a1, int a2)
{
    int result; // eax

    switch (a2)
    {
    case 5:
        if (*(_DWORD*)& byte_5D4594[536 * *(_DWORD*)(a1 + 32) + 1090308])
            sub_4674E0(*(_DWORD*)& byte_5D4594[536 * *(_DWORD*)(a1 + 32) + 1090308]);
        goto LABEL_5;
    case 8:
    case 12:
    case 16:
        result = 0;
        break;
    default:
    LABEL_5:
        result = 1;
        break;
    }
    return result;
}

//----- (00471C00) --------------------------------------------------------
int __cdecl sub_471C00(int a1)
{
    int v1; // esi
    unsigned __int8* v2; // ebp
    int v3; // edi
    int v4; // esi
    int v5; // ebx
    int v7; // [esp+Ch] [ebp+4h]

    v1 = *(_DWORD*)(a1 + 32);
    v7 = v1;
    v2 = &byte_5D4594[20 * v1 + 1093036];
    if (sub_4372E0() || *(_DWORD*)& byte_5D4594[2650672] || sub_40A5C0(9437184))
        return 1;
    if (v1)
        v3 = nox_win_width / 2 + 21;
    else
        v3 = nox_win_width / 2 + 15;
    v4 = nox_win_height / 2 - 48;
    v5 = 48 * *((int*)v2 + 1) / *((int*)v2 + 2);
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_49CE30(v3, v4, 2, 48);
    sub_434460(*((_DWORD*)v2 + 3));
    sub_49CE30(v3, v4 - v5 + 48, 2, v5);
    if (v7)
    {
        sub_434460(*(int*)& byte_5D4594[2650648]);
    }
    else if (*(_DWORD*)& byte_5D4594[1096264])
    {
        sub_434460(*(int*)& byte_5D4594[2650688]);
    }
    else
    {
        sub_434460(*(int*)& byte_5D4594[2598268]);
    }
    sub_49CC70(v3 - 1, v4 - 1, 4, 50);
    return 1;
}

//----- (00471D10) --------------------------------------------------------
int __cdecl sub_471D10(int xLeft)
{
    _DWORD* v1; // ebx
    int v2; // esi
    unsigned __int8* v3; // edi
    int v4; // ecx
    int result; // eax
    int v6; // ebx
    int* v7; // edi
    int v8; // esi
    unsigned __int8* v9; // esi
    int v10; // edi
    int v11; // eax
    int v12; // eax
    int v13; // ecx
    int v14; // eax
    int v15; // eax
    int v16; // eax
    int yTop; // [esp+Ch] [ebp-14h]
    int v18; // [esp+10h] [ebp-10h]
    int v19; // [esp+14h] [ebp-Ch]
    unsigned __int8* v20; // [esp+18h] [ebp-8h]
    unsigned __int8* v21; // [esp+1Ch] [ebp-4h]

    v1 = (_DWORD*)xLeft;
    v18 = *(_DWORD*)(xLeft + 32);
    v2 = v18;
    v3 = &byte_5D4594[20 * v18 + 1093036];
    v20 = &byte_5D4594[20 * v18 + 1093036];
    if (!v18 && *(_DWORD*)& byte_5D4594[1096264])
    {
        sub_46AA60(*(_DWORD * *)& byte_5D4594[1090276], &xLeft, &yTop);
        sub_47D2C0(*(int*)& byte_5D4594[1091900], xLeft, yTop);
    }
    sub_46AA60(v1, &xLeft, &yTop);
    xLeft += 5;
    if (*(_DWORD*)& byte_5D4594[3799468])
    {
        sub_434460(*(int*)& byte_5D4594[2650656]);
        sub_49CE30(xLeft, yTop, 15, 125);
    }
    v4 = *((_DWORD*)v3 + 2);
    if (v4)
    {
        v6 = 125 * *((_DWORD*)v3 + 1) / v4;
        sub_49CF10(xLeft, yTop, 15, 125 - v6);
        sub_434460(*((_DWORD*)v3 + 3));
        sub_434560(1);
        sub_49CE30(xLeft, yTop - v6 + 125, 15, v6);
        sub_434560(0);
        sub_49F500(xLeft, yTop - v6 + 125);
        sub_49F570(14, 0);
        sub_49E4B0();
        if (v2 < 2 && *(_DWORD*)& byte_587000[80844] == 1)
        {
            v19 = 64;
            v7 = (int*)& byte_5D4594[1536 * v2 + 1093188];
            v21 = &byte_5D4594[1536 * v2 + 1093188];
            do
            {
                if (v7[2])
                {
                    v8 = *(v7 - 1) >> 4;
                    if (v8 >= 125 - v6)
                    {
                        if (*(_DWORD*)& byte_5D4594[1096264])
                            sub_434460(*((_DWORD*)v20 + 3));
                        else
                            sub_434460(v7[3]);
                        if (*v7 <= 2)
                            sub_49CE30(xLeft + *(v7 - 2), yTop + v8, *v7, *v7);
                        else
                            sub_4720C0(xLeft + *(v7 - 2), yTop + v8);
                        *(v7 - 1) -= v7[1];
                    }
                    else
                    {
                        v7[2] = 0;
                    }
                    v2 = v18;
                }
                v7 += 6;
                --v19;
            } while (v19);
            if (v6 > 1)
            {
                v9 = v21;
                v10 = 64;
                do
                {
                    if (!*((_DWORD*)v9 + 2))
                    {
                        v11 = sub_415FF0(1, 100, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 668);
                        if (v11 >= 80)
                            * (_DWORD*)v9 = (v11 >= 95) + 2;
                        else
                            *(_DWORD*)v9 = 1;
                        v12 = sub_415FF0(0, 14, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 676);
                        v13 = *(_DWORD*)v9;
                        *((_DWORD*)v9 - 2) = v12;
                        if (v13 + v12 > 15)
                            * ((_DWORD*)v9 - 2) = 15 - v13;
                        *((_DWORD*)v9 - 1) = 16 * (125 - v13);
                        *((_DWORD*)v9 + 1) = sub_415FF0(4, 48, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 684);
                        *((_DWORD*)v9 + 2) = 1;
                        LOBYTE(v19) = sub_415FF0(0, 64, "C:\\NoxPost\\src\\Client\\Gui\\guimeter.c", 688);
                        if (v18)
                            v14 = sub_4344A0(v19, v19, 255);
                        else
                            v14 = sub_4344A0(255, v19, v19);
                        *((_DWORD*)v9 + 3) = v14;
                    }
                    v9 += 24;
                    --v10;
                } while (v10);
                v2 = v18;
            }
        }
        if (!v2)
        {
            if (*(int*)& byte_5D4594[1096260] <= 0)
            {
                v16 = *(_DWORD*)& byte_5D4594[1096256] >> 3;
            }
            else
            {
                v15 = *(_DWORD*)& byte_5D4594[1096260] + *(_DWORD*)& byte_5D4594[1096256];
                *(_DWORD*)& byte_5D4594[1096256] = v15;
                --* (_DWORD*)& byte_5D4594[1096260];
                v16 = v15 >> 3;
                if (v16 >= 10)
                {
                    v16 = 0;
                    *(_DWORD*)& byte_5D4594[1096256] = 0;
                }
            }
            sub_46AE60(*(int*)& byte_5D4594[1090276], *(_DWORD*)& byte_5D4594[4 * v16 + 1092996]);
        }
        sub_472080();
        result = 1;
    }
    else
    {
        sub_49CF10(xLeft, yTop, 15, 125);
        result = 1;
    }
    return result;
}

//----- (00472080) --------------------------------------------------------
int sub_472080()
{
    int result; // eax

    result = *(int*)& byte_5D4594[1093120];
    if (*(int*)& byte_5D4594[1093120] != *(int*)& byte_5D4594[1093124])
    {
        result = sub_416120(0x11u);
        if (result)
        {
            result = 0x64u / *(int*)& byte_5D4594[2649704];
            *(int*)& byte_5D4594[1093120] += 0x64u / *(int*)& byte_5D4594[2649704];
        }
    }
    return result;
}

//----- (004720C0) --------------------------------------------------------
int __cdecl sub_4720C0(int xLeft, int a2)
{
    sub_49EFA0(xLeft + 1, a2);
    sub_49CE30(xLeft, a2 + 1, 3, 1);
    return sub_49EFA0(xLeft + 1, a2 + 2);
}

//----- (00472100) --------------------------------------------------------
int __cdecl sub_472100(int a1, int a2)
{
    int result; // eax
    int v3; // [esp-4h] [ebp-4h]

    switch (a2)
    {
    case 7:
        v3 = *(_DWORD*)& byte_5D4594[1096252] == 1;
        *(_DWORD*)& byte_5D4594[1096252] = 1 - *(_DWORD*)& byte_5D4594[1096252];
        nox_window_set_hidden(*(int*)& byte_5D4594[1093076], v3);
        if (byte_5D4594[2661958])
            nox_window_set_hidden(*(int*)& byte_5D4594[1093096], *(_DWORD*)& byte_5D4594[1096252] == 0);
        sub_452D80(901, 100);
        goto LABEL_6;
    case 8:
    case 12:
    case 16:
        result = 0;
        break;
    default:
    LABEL_6:
        result = 1;
        break;
    }
    return result;
}

//----- (004721A0) --------------------------------------------------------
int __cdecl sub_4721A0(int a1)
{
    int result; // eax

    if (a1)
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1090276], 0);
    else
        result = nox_window_set_hidden(*(int*)& byte_5D4594[1090276], 1);
    return result;
}

//----- (004721D0) --------------------------------------------------------
int sub_4721D0()
{
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1090276]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[1093076]);
    if (*(_DWORD*)& byte_5D4594[1093096])
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[1093096]);
    sub_4714E0();
    sub_472310();
    return sub_4721A0(*(int*)& byte_587000[80828]);
}

//----- (00472220) --------------------------------------------------------
void sub_472220()
{
    if (!sub_477600())
    {
        if (*(_DWORD*)& byte_5D4594[1090308])
            sub_4674E0(*(int*)& byte_5D4594[1090308]);
    }
}

//----- (00472240) --------------------------------------------------------
void sub_472240()
{
    if (!sub_477600())
    {
        if (*(_DWORD*)& byte_5D4594[1090844])
            sub_4674E0(*(int*)& byte_5D4594[1090844]);
    }
}

//----- (00472260) --------------------------------------------------------
void sub_472260()
{
    if (!sub_477600())
    {
        if (*(_DWORD*)& byte_5D4594[1091380])
            sub_4674E0(*(int*)& byte_5D4594[1091380]);
    }
}

//----- (00472280) --------------------------------------------------------
wchar_t* sub_472280()
{
    wchar_t* result; // eax
    char* v1; // eax
    char* v2; // eax
    char* v3; // eax

    result = *(wchar_t**)& byte_5D4594[2618908];
    if (*(_DWORD*)& byte_5D4594[2618908])
    {
        v1 = sub_42E8E0(38, 1);
        nox_wcsncpy((wchar_t*)& byte_5D4594[1091372], (const wchar_t*)v1, 3u);
        *(_WORD*)& byte_5D4594[1091378] = 0;
        v2 = sub_42E8E0(36, 1);
        nox_wcsncpy((wchar_t*)& byte_5D4594[1090300], (const wchar_t*)v2, 3u);
        result = *(wchar_t**)& byte_5D4594[2618908];
        *(_WORD*)& byte_5D4594[1090306] = 0;
        if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 2251))
        {
            v3 = sub_42E8E0(37, 1);
            result = nox_wcsncpy((wchar_t*)& byte_5D4594[1090836], (const wchar_t*)v3, 3u);
            *(_WORD*)& byte_5D4594[1090842] = 0;
        }
    }
    return result;
}

//----- (00472310) --------------------------------------------------------
unsigned __int8* sub_472310()
{
    unsigned __int8* result; // eax
    int v1; // eax

    *(_WORD*)& byte_5D4594[1091384] = sub_467850(*(int*)& byte_5D4594[1096276]);
    *(_WORD*)& byte_5D4594[1090848] = sub_467850(*(int*)& byte_5D4594[1096272]);
    *(_WORD*)& byte_5D4594[1091384] = sub_467850(*(int*)& byte_5D4594[1096276]);
    *(_WORD*)& byte_5D4594[1090312] = sub_467850(*(int*)& byte_5D4594[1096268]);
    if (*(_WORD*)& byte_5D4594[1090312])
    {
        result = (unsigned __int8*)nox_get_thing(*(int*)& byte_5D4594[1096268]);
        if (result)
        {
            sub_44D0C0(COERCE_FLOAT(&byte_5D4594[1090316]), *((_DWORD*)result + 7));
            result = &byte_5D4594[1090316];
            *(_DWORD*)& byte_5D4594[1090296] = &byte_5D4594[1090316];
            if (byte_5D4594 != (unsigned __int8*)-1090316)
            {
                result = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[1090436] | 0x40000000);
                *(_DWORD*)& byte_5D4594[1090308] = *(_DWORD*)& byte_5D4594[1096268];
                *(_DWORD*)& byte_5D4594[1090436] |= 0x40000000u;
                return result;
            }
        }
        else
        {
            *(_DWORD*)& byte_5D4594[1090296] = 0;
        }
        *(_DWORD*)& byte_5D4594[1090308] = *(_DWORD*)& byte_5D4594[1096268];
    }
    else
    {
        *(_WORD*)& byte_5D4594[1090312] = sub_467850(*(int*)& byte_5D4594[1096284]);
        if (*(_WORD*)& byte_5D4594[1090312])
        {
            v1 = nox_get_thing(*(int*)& byte_5D4594[1096284]);
            if (v1)
            {
                sub_44D0C0(COERCE_FLOAT(&byte_5D4594[1090316]), *(_DWORD*)(v1 + 28));
                *(_DWORD*)& byte_5D4594[1090296] = &byte_5D4594[1090316];
                if (byte_5D4594 != (unsigned __int8*)-1090316)
                {
                    *(_DWORD*)& byte_5D4594[1090436] |= 0x40000000u;
                    result = *(unsigned __int8**)& byte_5D4594[1096284];
                    *(_DWORD*)& byte_5D4594[1090308] = *(_DWORD*)& byte_5D4594[1096284];
                    return result;
                }
            }
            else
            {
                *(_DWORD*)& byte_5D4594[1090296] = 0;
            }
            result = *(unsigned __int8**)& byte_5D4594[1096284];
            *(_DWORD*)& byte_5D4594[1090308] = *(_DWORD*)& byte_5D4594[1096284];
        }
        else
        {
            result = (unsigned __int8*)sub_467850(*(int*)& byte_5D4594[1096280]);
            *(_WORD*)& byte_5D4594[1090312] = (_WORD)result;
            if ((_WORD)result)
            {
                result = (unsigned __int8*)nox_get_thing(*(int*)& byte_5D4594[1096280]);
                if (result)
                {
                    result = (unsigned __int8*)sub_44D0C0(COERCE_FLOAT(&byte_5D4594[1090316]), *((_DWORD*)result + 7));
                    *(_DWORD*)& byte_5D4594[1090296] = &byte_5D4594[1090316];
                    if (byte_5D4594 != (unsigned __int8*)-1090316)
                    {
                        result = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[1090436] | 0x40000000);
                        *(_DWORD*)& byte_5D4594[1090308] = *(_DWORD*)& byte_5D4594[1096280];
                        *(_DWORD*)& byte_5D4594[1090436] |= 0x40000000u;
                        return result;
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[1090296] = 0;
                }
                *(_DWORD*)& byte_5D4594[1090308] = *(_DWORD*)& byte_5D4594[1096280];
            }
            else
            {
                *(_DWORD*)& byte_5D4594[1090296] = 0;
                *(_DWORD*)& byte_5D4594[1090308] = 0;
            }
        }
    }
    return result;
}

//----- (004724E0) --------------------------------------------------------
void sub_4724E0()
{
    *(_DWORD*)& byte_587000[149232] -= 10;
    if (*(int*)& byte_587000[149232] < 500)
        * (_DWORD*)& byte_587000[149232] = 500;
}

//----- (00472500) --------------------------------------------------------
void sub_472500()
{
    *(_DWORD*)& byte_587000[149232] += 10;
    if (*(_DWORD*)& byte_587000[149232] > 4000)
        * (_DWORD*)& byte_587000[149232] = 4000;
}

//----- (00472520) --------------------------------------------------------
int __cdecl sub_472520(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[149232] = a1;
    return result;
}

//----- (00472530) --------------------------------------------------------
int sub_472530()
{
    return *(_DWORD*)& byte_587000[149232];
}

//----- (00472540) --------------------------------------------------------
int __cdecl sub_472540(int a1)
{
    int v1; // edx
    int v2; // eax
    int result; // eax
    int2 a1a; // [esp+0h] [ebp-8h]

    if (a1 == *(_DWORD*)& byte_5D4594[2614252])
    {
        sub_435670(&a1a);
    }
    else
    {
        v1 = *(_DWORD*)(a1 + 16);
        a1a.field_0 = *(_DWORD*)(a1 + 12);
        a1a.field_4 = v1;
    }
    v2 = sub_421790(&a1a, *(int*)& byte_5D4594[1096312]);
    if (v2)
        * (_DWORD*)& byte_5D4594[1096312] = v2;
    else
        v2 = *(_DWORD*)& byte_5D4594[1096312];
    if (v2)
        result = (unsigned __int8)sub_4214A0(v2)[130];
    else
        result = 1;
    return result;
}

//----- (004725C0) --------------------------------------------------------
int4* __cdecl sub_4725C0(int a1)
{
    int4* result; // eax

    result = (int4*)sub_4356C0(*(int*)& byte_5D4594[2614252], 2);
    if (!result)
    {
        sub_437260();
        *(_DWORD*)& byte_5D4594[1096316] = sub_472540(a1);
        sub_472600(a1, *(int*)& byte_5D4594[1096316]);
        result = sub_437290();
    }
    return result;
}

//----- (00472600) --------------------------------------------------------
int __cdecl sub_472600(int a1, int a2)
{
    char* v2; // ebp
    int v3; // esi
    int v4; // kr08_4
    int v5; // ebx
    int v6; // et1
    int v7; // esi
    int v8; // ebx
    int v9; // ebp
    int v10; // eax
    int v11; // edi
    char v12; // al
    int v13; // eax
    int v14; // esi
    int v15; // ebp
    unsigned __int8* v16; // esi
    int v17; // eax
    int v18; // eax
    int v19; // eax
    int v20; // et1
    int v21; // ecx
    int v22; // ebx
    int v23; // ebp
    int v24; // esi
    int v25; // ecx
    int v26; // et1
    char v27; // al
    char v28; // dl
    int v29; // edi
    char* v30; // esi
    float* v31; // esi
    int v32; // et1
    double v33; // st7
    int v34; // et1
    double v35; // st7
    float* j; // esi
    int v37; // et1
    double v38; // st7
    _DWORD* v39; // eax
    int k; // esi
    struc_19* v41; // eax
    int v42; // et1
    int v43; // eax
    int v44; // eax
    int v45; // edi
    _DWORD* v46; // eax
    char* v47; // eax
    int* v48; // eax
    _DWORD* v49; // eax
    _DWORD* v50; // edi
    char* v51; // eax
    int* v52; // eax
    int v53; // eax
    int v54; // eax
    char* v55; // eax
    char* v56; // eax
    _DWORD* v57; // eax
    int* v58; // eax
    int l; // esi
    BOOL v60; // eax
    int v61; // edx
    _DWORD* v62; // edi
    struc_19* v63; // eax
    int v64; // et1
    char* v65; // eax
    int* v66; // eax
    int v68; // [esp-10h] [ebp-70h]
    int v69; // [esp+10h] [ebp-50h]
    int v70; // [esp+10h] [ebp-50h]
    int i; // [esp+14h] [ebp-4Ch]
    int v72; // [esp+14h] [ebp-4Ch]
    int v73; // [esp+14h] [ebp-4Ch]
    int v74; // [esp+18h] [ebp-48h]
    char* v75; // [esp+18h] [ebp-48h]
    int2 v76; // [esp+20h] [ebp-40h]
    int v77; // [esp+28h] [ebp-38h]
    int v78; // [esp+2Ch] [ebp-34h]
    int v79; // [esp+30h] [ebp-30h]
    int v80; // [esp+34h] [ebp-2Ch]
    int v81; // [esp+38h] [ebp-28h]
    int2 xLeft; // [esp+40h] [ebp-20h]
    int yTop; // [esp+4Ch] [ebp-14h]
    int2 v84; // [esp+50h] [ebp-10h]
    int v85; // [esp+5Ch] [ebp-4h]

    v2 = sub_437250();
    if (!byte_5D4594[1096300])
    {
        byte_5D4594[1096300] = sub_410D60("InvisibleWallSet");
        byte_5D4594[1096301] = sub_410D60("InvisibleBlockingWallSet");
    }
    sub_434560(0);
    sub_49F7F0();
    v3 = nox_win_width / 6;
    v4 = nox_win_height - nox_win_width / 6;
    yTop = v4 / 2;
    sub_49F6F0(0, 0, nox_win_width, nox_win_height);
    v5 = *(_DWORD*)v2;
    if (*(_DWORD*)v2 <= 0)
    {
        sub_49CF10(0, v4 / 2, v3, v3);
    }
    else
    {
        sub_434460(*(int*)& byte_5D4594[2650656]);
        if (v5 >= v3)
        {
            sub_49CE30(0, v4 / 2, v3, v3);
        }
        else
        {
            sub_49CE30(0, v4 / 2, v5, v3);
            sub_49CF10(v5, v4 / 2, v3 - v5, v3);
        }
    }
    sub_434560(1);
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_434580(0x5Au);
    sub_473510(-1, yTop - 1, v3 + 2, v3 + 2);
    sub_434580(0x3Cu);
    sub_473510(-2, yTop - 2, v3 + 4, v3 + 4);
    sub_434580(0x28u);
    sub_473510(-3, yTop - 3, v3 + 6, v3 + 6);
    sub_434560(0);
    sub_49F6F0(0, yTop, v3, v3);
    v6 = *(_DWORD*)& byte_587000[149232];
    v7 = v3 * v6 / 100;
    sub_435670(&v84);
    v8 = v84.field_0 - v7 / 2;
    v9 = v84.field_4 - v7 / 2;
    xLeft.field_0 = v84.field_0 - v7 / 2;
    xLeft.field_4 = v9;
    v81 = v8 / 23;
    v77 = (v8 + v7) / 23;
    v78 = (v9 + v7) / 23;
    v74 = 23 * (v8 / 23);
    v80 = 23 * (v9 / 23);
    v10 = v9 / 23;
    for (i = v9 / 23; i <= v78; ++i)
    {
        v11 = sub_4106A0(v10);
        while (v11)
        {
            v12 = *(_BYTE*)(v11 + 1);
            if (v12 == byte_5D4594[1096300])
                goto LABEL_37;
            if (v12 == byte_5D4594[1096301])
                goto LABEL_37;
            if (*(_BYTE*)(v11 + 8) && *(unsigned __int8*)(v11 + 8) != a2)
                goto LABEL_37;
            v13 = *(unsigned __int8*)(v11 + 5);
            if (v13 < v81)
                goto LABEL_37;
            if (v13 > v77)
                break;
            v14 = v74 + 23 * (v13 - v81);
            if (*(_BYTE*)(v11 + 4) & 0x10)
            {
                v15 = *(_DWORD*)(v11 + 32);
                if (!v15)
                    goto LABEL_37;
                v69 = 0;
                v16 = &byte_587000[149244];
                while (1)
                {
                    v17 = sub_410580(
                        *((_DWORD*)v16 - 1) + *(unsigned __int8*)(v11 + 5),
                        *(_DWORD*)v16 + *(unsigned __int8*)(v11 + 6));
                    if (v17)
                    {
                        if (*(_DWORD*)(v17 + 12))
                            goto LABEL_28;
                    }
                    else
                    {
                        v18 = sub_410580(*((_DWORD*)v16 - 1) + *(unsigned __int8*)(v11 + 5), *(unsigned __int8*)(v11 + 6));
                        if (v18 && *(_DWORD*)(v18 + 12)
                            || (v19 = sub_410580(*(unsigned __int8*)(v11 + 5), *(_DWORD*)v16 + *(unsigned __int8*)(v11 + 6))) != 0
                            && *(_DWORD*)(v19 + 12))
                        {
                        LABEL_28:
                            if (v69 < 4)
                            {
                                v20 = *(_DWORD*)& byte_587000[149232];
                                v21 = 8 * *(unsigned __int8*)(v15 + 299);
                                v22 = 100 * (*(int*)(v15 + 12) - xLeft.field_0) / v20;
                                v85 = 100 * (*(int*)(v15 + 16) - xLeft.field_4) / v20;
                                v23 = 100 * *(int*)& byte_587000[v21 + 196184] / v20;
                                v24 = 100 * *(int*)& byte_587000[v21 + 196188] / v20;
                                sub_434460(*(int*)& byte_5D4594[2650644]);
                                sub_49F500(v22, yTop + v85);
                                sub_49F570(v23, v24);
                                sub_49E4B0();
                                v8 = xLeft.field_0;
                            }
                            goto LABEL_37;
                        }
                    }
                    v16 += 8;
                    ++v69;
                    if ((int)v16 >= (int)& byte_587000[149276])
                        goto LABEL_37;
                }
            }
            if (sub_40A5C0(0x10000) || *(_DWORD*)(v11 + 12))
            {
                v26 = *(_DWORD*)& byte_587000[149232];
                v25 = v26;
                v76.field_0 = 100 * (v14 - v8) / v26;
                v76.field_4 = yTop + 100 * (v80 - v9) / v26;
                v27 = *(_BYTE*)(v11 + 4);
                if (!(v27 & 4) || (v28 = *(_BYTE*)(*(_DWORD*)(v11 + 28) + 21), v28 != 3) && v28 != 2)
                {
                    if (!(v27 & 0x20))
                        sub_4730D0(&v76, *(_BYTE*)v11, 2300 / v25);
                }
            }
        LABEL_37:
            v11 = *(_DWORD*)(v11 + 24);
            v9 = xLeft.field_4;
        }
        v10 = i + 1;
        v80 += 23;
    }
    if (byte_5D4594[2650636] & 8)
    {
        v29 = sub_50CB00();
        v30 = (char*)sub_50CB10();
        if (v29 >= 2)
        {
            sub_434460(*(int*)& byte_5D4594[2618904]);
            if (v29 - 1 > 0)
            {
                v31 = (float*)(v30 + 8);
                v72 = v29 - 1;
                do
                {
                    v32 = *(_DWORD*)& byte_587000[149232];
                    v33 = *(v31 - 1);
                    xLeft.field_0 = (int)(100 * ((unsigned __int64)(__int64) * (v31 - 2) - v8)) / v32;
                    sub_49F500(xLeft.field_0, yTop + (int)(100 * ((unsigned __int64)(__int64)v33 - v9)) / v32);
                    v34 = *(_DWORD*)& byte_587000[149232];
                    v35 = v31[1];
                    xLeft.field_0 = (int)(100 * ((unsigned __int64)(__int64)* v31 - v8)) / v34;
                    sub_49F500(xLeft.field_0, yTop + (int)(100 * ((unsigned __int64)(__int64)v35 - v9)) / v34);
                    sub_49E4B0();
                    v31 += 2;
                    --v72;
                } while (v72);
            }
        }
        for (j = (float*)sub_50AAE0(); j; j = (float*)sub_50AB10())
        {
            sub_434460(*(int*)& byte_5D4594[2650644]);
            v37 = *(_DWORD*)& byte_587000[149232];
            v38 = j[1];
            xLeft.field_0 = (int)(100 * ((unsigned __int64)(__int64)* j - v8)) / v37;
            sub_473570(xLeft.field_0, yTop + (int)(100 * ((unsigned __int64)(__int64)v38 - v9)) / v37);
        }
    }
    v73 = 0;
    if (!*(_DWORD*)& byte_5D4594[1096304])
    {
        *(_DWORD*)& byte_5D4594[1096304] = sub_44CFC0((CHAR*)& byte_587000[149320]);
        *(_DWORD*)& byte_5D4594[1096308] = sub_44CFC0((CHAR*)& byte_587000[149328]);
    }
    v39 = sub_418C80(*(int*)& byte_5D4594[2616328]);
    v70 = (int)v39;
    if (v39 && sub_419130((int)v39))
        v73 = 1;
    for (k = sub_459EB0(); k; k = sub_459EC0(k))
    {
        v41 = sub_4217B0((int2*)(k + 12), 0);
        if (v41)
        {
            if (BYTE2(v41->field_0[32]) != a2)
                continue;
        }
        else if (a2 != 1)
        {
            continue;
        }
        v42 = *(_DWORD*)& byte_587000[149232];
        xLeft.field_0 = 100 * (*(int*)(k + 12) - v8) / v42;
        xLeft.field_4 = yTop + 100 * (*(int*)(k + 16) - v9) / v42;
        if (!(*(_DWORD*)(k + 112) & 0x400000) || (v43 = *(_DWORD*)& byte_5D4594[2650684], !(*(_BYTE*)(k + 116) & 8)))
            v43 = *(_DWORD*)& byte_5D4594[2650644];
        sub_434460(v43);
        v44 = *(_DWORD*)(k + 108);
        if (v44 == *(int*)& byte_5D4594[1096304])
        {
            if (sub_418B10() || (v45 = sub_45A000()) == 0)
            {
            LABEL_64:
                sub_434460(*(int*)& byte_5D4594[2618904]);
                v46 = sub_418C80(*(_DWORD*)(k + 128));
                if (v46)
                {
                    v47 = sub_418AB0(*((unsigned __int8*)v46 + 4));
                    if (v47)
                    {
                        v48 = (int*)sub_418D50((int)v47);
                        sub_434460(*v48);
                    }
                }
                sub_473420(&xLeft);
            }
            else
            {
                while (!sub_4356C0(v45, 30))
                {
                    v45 = sub_45A010(v45);
                    if (!v45)
                        goto LABEL_64;
                }
            }
            continue;
        }
        if (v44 == *(int*)& byte_5D4594[1096308])
        {
            v49 = sub_418C80(*(_DWORD*)(k + 128));
            v50 = v49;
            if (v49 && sub_419130((int)v49))
            {
                v51 = sub_418AB0(*((unsigned __int8*)v50 + 4));
                if (v51)
                {
                    v52 = (int*)sub_418D50((int)v51);
                    sub_434460(*v52);
                }
            }
            else
            {
                sub_434460(*(int*)& byte_5D4594[2523948]);
            }
            sub_4734F0(&xLeft.field_0);
            continue;
        }
        v53 = *(_DWORD*)(k + 112);
        if (v53 & 0x10000000)
        {
            if (*(_DWORD*)(k + 120) & 0x1000000)
            {
                sub_434460(*(int*)& byte_5D4594[2523948]);
                v54 = sub_4B9470(*(const char***)(k + 436));
                v55 = sub_418AB0(v54);
                if (v55)
                    goto LABEL_88;
                goto LABEL_89;
            }
        }
        else
        {
            if (!(v53 & 4))
            {
                sub_473570(xLeft.field_0, xLeft.field_4);
                continue;
            }
            if (!sub_40A5C0(32))
            {
                if (k == *(int*)& byte_5D4594[2614252])
                    sub_4735C0(xLeft.field_0, xLeft.field_4);
                else
                    sub_473570(xLeft.field_0, xLeft.field_4);
                continue;
            }
            v56 = sub_417040(*(_DWORD*)(k + 128));
            if (v56)
            {
                v81 = *((_DWORD*)v56 + 1) & 1;
                if (v81)
                {
                    sub_434460(*(int*)& byte_5D4594[2523948]);
                    v57 = sub_418C80(*(_DWORD*)(k + 128));
                    if (v57)
                    {
                        v55 = *((_BYTE*)v57 + 4) == 1 ? sub_418AB0(2) : sub_418AB0(1);
                        if (v55)
                        {
                        LABEL_88:
                            v58 = (int*)sub_418D50((int)v55);
                            sub_434460(*v58);
                        }
                    }
                LABEL_89:
                    sub_4733B0(&xLeft);
                    continue;
                }
            }
        }
    }
    v79 = *(_DWORD*)& byte_5D4594[2618904];
    for (l = sub_45A000(); l; l = sub_45A010(l))
    {
        v60 = sub_4356C0(l, 30);
        v61 = *(_DWORD*)(l + 128);
        v77 = v60;
        v62 = sub_418C80(v61);
        v68 = *(_DWORD*)(l + 128);
        v81 = (int)v62;
        v75 = sub_417040(v68);
        if (v70 && v62 && v73)
        {
            v76.field_0 = sub_419150(v70, (int)v62);
            if (v76.field_0)
                goto LABEL_103;
        }
        else
        {
            v76.field_0 = 0;
        }
        if (v77 || l == *(_DWORD*)& byte_5D4594[2614252] || *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 1)
        {
        LABEL_103:
            v63 = sub_4217B0((int2*)(l + 12), 0);
            if ((!v63 || BYTE2(v63->field_0[32]) == a2) && v75 && (v75[3680] & 1) != 1)
            {
                v64 = *(_DWORD*)& byte_587000[149232];
                xLeft.field_0 = 100 * (*(int*)(l + 12) - v8) / v64;
                xLeft.field_4 = yTop + 100 * (*(int*)(l + 16) - v9) / v64;
                if (l == *(_DWORD*)& byte_5D4594[2614252] || v76.field_0)
                    sub_434460(v79);
                else
                    sub_434460(*(int*)& byte_5D4594[2650644]);
                if (v77)
                {
                    if (v81)
                    {
                        v65 = sub_418AB0(*(unsigned __int8*)(v81 + 4));
                        if (v65)
                        {
                            v66 = (int*)sub_418D50((int)v65);
                            sub_434460(*v66);
                        }
                    }
                    sub_473420(&xLeft);
                }
                else
                {
                    sub_473570(xLeft.field_0, xLeft.field_4);
                }
            }
        }
    }
    return sub_49F860();
}

//----- (004730D0) --------------------------------------------------------
int __cdecl sub_4730D0(int2* a1, unsigned __int8 a2, int a3)
{
    int result; // eax
    int v4; // ebx
    int v5; // edi
    int2* v6; // ebp

    if (*(_DWORD*)& byte_587000[149232] <= 2000)
    {
        v4 = *(_DWORD*)& byte_5D4594[2650660];
        result = a2;
        v5 = a3 / 2;
        switch (a2)
        {
        case 0u:
            result = sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4, *(int*)& byte_5D4594[2650660]);
            break;
        case 1u:
            result = sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, *(int*)& byte_5D4594[2650660]);
            break;
        case 2u:
            sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4, *(int*)& byte_5D4594[2650660]);
            result = sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, v4);
            break;
        case 3u:
            sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5, *(int*)& byte_5D4594[2650660]);
            result = sub_473380(a1->field_0, a3 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
            break;
        case 4u:
            sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, *(int*)& byte_5D4594[2650660]);
            result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
            break;
        case 5u:
            sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4, *(int*)& byte_5D4594[2650660]);
            result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4 + a3, v4);
            break;
        case 6u:
            v6 = a1;
            sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, *(int*)& byte_5D4594[2650660]);
            goto LABEL_15;
        case 7u:
            sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5, *(int*)& byte_5D4594[2650660]);
            result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
            break;
        case 8u:
            sub_473380(
                v5 + a1->field_0,
                v5 + a1->field_4,
                a1->field_0 + a3,
                a1->field_4 + a3,
                *(int*)& byte_5D4594[2650660]);
            result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
            break;
        case 9u:
            sub_473380(
                v5 + a1->field_0,
                v5 + a1->field_4,
                a1->field_0 + a3,
                a1->field_4 + a3,
                *(int*)& byte_5D4594[2650660]);
            result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0, a1->field_4 + a3, v4);
            break;
        case 0xAu:
            v6 = a1;
            sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5, *(int*)& byte_5D4594[2650660]);
        LABEL_15:
            result = sub_473380(v6->field_0, a3 + v6->field_4, v5 + v6->field_0, v6->field_4 + v5, v4);
            break;
        default:
            return result;
        }
    }
    else
    {
        sub_434460(*(int*)& byte_5D4594[2650660]);
        result = sub_49EFA0(a1->field_0, a1->field_4);
    }
    return result;
}

//----- (00473380) --------------------------------------------------------
int __cdecl sub_473380(int a1, int a2, int a3, int a4, int a5)
{
    sub_434460(a5);
    sub_49F500(a1, a2);
    sub_49F500(a3, a4);
    return sub_49E4B0();
}

//----- (004733B0) --------------------------------------------------------
int __cdecl sub_4733B0(_DWORD* a1)
{
    int v1; // esi
    int v2; // edi

    v1 = a1[1] + 4;
    v2 = *a1 - 2;
    sub_49F500(v2, v1);
    v1 -= 8;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v2 += 4;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v1 += 4;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    sub_49F500(v2 - 4, v1);
    return sub_49E4B0();
}

//----- (00473420) --------------------------------------------------------
int __cdecl sub_473420(_DWORD* a1)
{
    int v1; // edi
    int v2; // esi

    v1 = a1[1] + 6;
    v2 = *a1 - 4;
    sub_49F500(v2, v1);
    v1 -= 12;
    v2 -= 2;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v1 += 6;
    v2 += 4;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v1 -= 6;
    v2 += 2;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v1 += 6;
    v2 += 2;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v1 -= 6;
    v2 += 4;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    v1 += 12;
    v2 -= 2;
    sub_49F500(v2, v1);
    sub_49E4B0();
    sub_49F500(v2, v1);
    sub_49F500(v2 - 8, v1);
    return sub_49E4B0();
}

//----- (004734F0) --------------------------------------------------------
int __cdecl sub_4734F0(int* a1)
{
    return sub_4B0B90(*a1, a1[1], 3);
}

//----- (00473510) --------------------------------------------------------
int __cdecl sub_473510(int a1, int a2, int a3, int a4)
{
    int v4; // esi
    int v5; // edi

    sub_49F500(a1, a2);
    v4 = a1 + a3 - 1;
    sub_49F500(v4, a2);
    sub_49E4B0();
    sub_49F500(v4, a2);
    v5 = a4 - 1 + a2;
    sub_49F500(v4, v5);
    sub_49E4B0();
    sub_49F500(v4, v5);
    sub_49F500(a1, v5);
    return sub_49E4B0();
}

//----- (00473570) --------------------------------------------------------
void __cdecl sub_473570(int xLeft, int yTop)
{
    if (*(_DWORD*)& byte_587000[149232] > 1200)
        sub_499B70(xLeft, yTop, (*(_DWORD*)& byte_587000[149232] < 1750) + 2);
    else
        sub_499B70(xLeft, yTop, 4);
}

//----- (004735C0) --------------------------------------------------------
void __cdecl sub_4735C0(int xLeft, int yTop)
{
    if (*(_DWORD*)& byte_587000[149232] > 1200)
        sub_499B70(xLeft, yTop, (*(_DWORD*)& byte_587000[149232] < 1750) + 4);
    else
        sub_499B70(xLeft, yTop, 6);
}

//----- (00473610) --------------------------------------------------------
char sub_473610()
{
    int v0; // eax

    v0 = sub_477600();
    if (v0 != 1)
    {
        if (byte_5D4594[1096424] & 1)
        {
            sub_452D80(785, 100);
            v0 = *(_DWORD*)& byte_5D4594[1096424];
            LOBYTE(v0) = byte_5D4594[1096424] & 0xFE;
        }
        else
        {
            sub_452D80(784, 100);
            v0 = *(_DWORD*)& byte_5D4594[1096424];
            LOBYTE(v0) = byte_5D4594[1096424] | 1;
        }
        *(_DWORD*)& byte_5D4594[3799524] = 1;
        *(_DWORD*)& byte_5D4594[1096424] = v0;
    }
    return v0;
}

//----- (00473670) --------------------------------------------------------
int sub_473670()
{
    return byte_5D4594[1096424] & 1;
}

//----- (00473680) --------------------------------------------------------
int sub_473680()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[1096420] = sub_42F970("CursorBitmap");
    result = sub_455C30();
    if (result)
    {
        result = sub_456070();
        if (result)
        {
            result = sub_470710();
            if (result)
            {
                result = sub_4714E0();
                if (result)
                {
                    result = sub_45B9D0();
                    if (result)
                    {
                        result = sub_476E20();
                        if (result)
                        {
                            result = sub_4BFAD0();
                            if (result)
                            {
                                result = sub_465E00();
                                *(_DWORD*)& byte_5D4594[1096328] = result;
                                if (result)
                                {
                                    result = sub_4ADAD0();
                                    if (result)
                                    {
                                        result = sub_48D000();
                                        if (result)
                                        {
                                            result = sub_4C3760();
                                            if (result)
                                            {
                                                result = sub_46C730();
                                                if (result)
                                                {
                                                    result = sub_4C09D0();
                                                    if (result)
                                                    {
                                                        result = sub_478110();
                                                        if (result)
                                                        {
                                                            result = sub_49B3E0();
                                                            if (result)
                                                            {
                                                                result = sub_4BFC90();
                                                                if (result)
                                                                {
                                                                    result = sub_4BFEF0();
                                                                    if (result)
                                                                    {
                                                                        result = sub_4799A0();
                                                                        if (result)
                                                                        {
                                                                            result = sub_460E60();
                                                                            if (result)
                                                                            {
                                                                                result = sub_450C70();
                                                                                *(_DWORD*)& byte_5D4594[1096352] = result;
                                                                                if (result)
                                                                                {
                                                                                    result = sub_46A730();
                                                                                    if (result)
                                                                                    {
                                                                                        result = sub_44E560();
                                                                                        if (result)
                                                                                        {
                                                                                            result = sub_4C3500();
                                                                                            if (result)
                                                                                            {
                                                                                                result = sub_46E870();
                                                                                                *(_DWORD*)& byte_5D4594[1096340] = result;
                                                                                                if (result)
                                                                                                {
                                                                                                    result = sub_4465C0();
                                                                                                    *(_DWORD*)& byte_5D4594[1096324] = result;
                                                                                                    if (result)
                                                                                                    {
                                                                                                        result = sub_4C1D80();
                                                                                                        if (result)
                                                                                                        {
                                                                                                            result = sub_445790();
                                                                                                            if (result)
                                                                                                            {
                                                                                                                result = sub_4AB260();
                                                                                                                if (result)
                                                                                                                {
                                                                                                                    result = sub_445650();
                                                                                                                    if (result)
                                                                                                                    {
                                                                                                                        result = sub_4C3390();
                                                                                                                        if (result)
                                                                                                                        {
                                                                                                                            result = sub_48C980();
                                                                                                                            if (result)
                                                                                                                            {
                                                                                                                                sub_450BE0();
                                                                                                                                sub_4AB4A0(0);
                                                                                                                                sub_4AB4D0(0);
                                                                                                                                if (!*(_DWORD*)& byte_587000[80828]
                                                                                                                                    || *(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                                                                                                                                {
                                                                                                                                    sub_4721A0(0);
                                                                                                                                    sub_460EA0(0);
                                                                                                                                    nox_window_set_visible_unk5(0);
                                                                                                                                    sub_45D500(0);
                                                                                                                                    sub_455A00(0);
                                                                                                                                    sub_455F10(0);
                                                                                                                                }
                                                                                                                                result = 1;
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (00473840) --------------------------------------------------------
int sub_473840()
{
    sub_450BF0();
    sub_4C03E0();
    sub_46CCB0();
    sub_4AE3B0();
    sub_48D450();
    sub_4C4220();
    sub_4C12A0();
    sub_4BFD10();
    sub_49B490();
    sub_478F80();
    sub_479D10();
    sub_4AB470();
    sub_4C34A0();
    sub_445770();
    sub_456240();
    sub_455EE0();
    sub_460E90();
    sub_4505E0();
    sub_46A860();
    sub_49C7A0();
    sub_4597E0(1);
    sub_467980();
    sub_46C5D0();
    *(_DWORD*)& byte_587000[80828] = *(_DWORD*)& byte_587000[80832];
    return 1;
}

//----- (004738D0) --------------------------------------------------------
int sub_4738D0()
{
    sub_45ACA0(1);
    return 1;
}

//----- (004738E0) --------------------------------------------------------
int sub_4738E0()
{
    int result; // eax
    _DWORD* v1; // eax

    result = 1;
    if (*(_DWORD*)& byte_5D4594[1556112] != 1)
    {
        if (byte_5D4594[1096424] & 1)
        {
            v1 = sub_45A6F0(*(int*)& byte_5D4594[2616328]);
            sub_4725C0((int)v1);
        }
        result = sub_445530();
    }
    return result;
}

//----- (00473920) --------------------------------------------------------
void sub_473920()
{
    *(_DWORD*)& byte_5D4594[1096520] = 1;
}

//----- (00473930) --------------------------------------------------------
char* sub_473930()
{
    char* result; // eax

    *(_DWORD*)& byte_5D4594[1096456] = sub_42FA20("ConfusedBirdies");
    result = sub_42FA20("SphericalShieldAnim");
    *(_DWORD*)& byte_5D4594[1096460] = result;
    return result;
}

//----- (00473960) --------------------------------------------------------
int sub_473960()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[1096456] = 0;
    *(_DWORD*)& byte_5D4594[1096460] = 0;
    return result;
}

//----- (00473970) --------------------------------------------------------
void __cdecl sub_473970(int2* a1, int2* a2)
{
    a2->field_0 = *(_DWORD*)& byte_5D4594[1096428] + a1->field_0;
    a2->field_4 = *(_DWORD*)& byte_5D4594[1096432] + a1->field_4;
}

//----- (004739A0) --------------------------------------------------------
int __cdecl sub_4739A0(int2* a1, int2* a2)
{
    int result; // eax

    a2->field_0 = a1->field_0 - *(_DWORD*)& byte_5D4594[1096428];
    result = a1->field_4 - *(_DWORD*)& byte_5D4594[1096432];
    a2->field_4 = result;
    return result;
}

//----- (004739D0) --------------------------------------------------------
int __cdecl sub_4739D0(int a1)
{
    return a1 - *(_DWORD*)& byte_5D4594[1096432];
}

//----- (004739E0) --------------------------------------------------------
int __cdecl sub_4739E0(_DWORD* a1, int2* a2, int2* a3)
{
    int result; // eax

    a3->field_0 = a2->field_0 + *a1 - a1[4];
    result = a2->field_4;
    a3->field_4 = result + a1[1] - a1[5];
    return result;
}

//----- (00473A10) --------------------------------------------------------
int __cdecl sub_473A10(_DWORD* a1, int2* a2, _DWORD* a3)
{
    int result; // eax

    *a3 = a2->field_0 + a1[4] - *a1;
    result = a2->field_4;
    a3[1] = result + a1[5] - a1[1];
    return result;
}

//----- (00473A40) --------------------------------------------------------
int sub_473A40()
{
    *(_DWORD*)& byte_5D4594[1096464] = nox_malloc(sizeof(void*) * 8192);
    if (!*(_DWORD*)& byte_5D4594[1096464])
        return 0;
    *(_DWORD*)& byte_5D4594[1096468] = 0;
    *(_DWORD*)& byte_5D4594[1096472] = nox_malloc(0x800u);
    if (!*(_DWORD*)& byte_5D4594[1096472])
        return 0;
    *(_DWORD*)& byte_5D4594[1096476] = 0;
    *(_DWORD*)& byte_5D4594[1096480] = nox_malloc(0x800u);
    if (!*(_DWORD*)& byte_5D4594[1096480])
        return 0;
    *(_DWORD*)& byte_5D4594[1096484] = 0;
    *(_DWORD*)& byte_5D4594[1096488] = nox_malloc(0x800u);
    if (!*(_DWORD*)& byte_5D4594[1096488])
        return 0;
    *(_DWORD*)& byte_5D4594[1096492] = 0;
    *(_DWORD*)& byte_5D4594[1096496] = nox_malloc(0x400u);
    if (!*(_DWORD*)& byte_5D4594[1096496])
        return 0;
    *(_DWORD*)& byte_5D4594[1096500] = 0;
    *(_DWORD*)& byte_5D4594[1096504] = nox_malloc(0x400u);
    if (!*(_DWORD*)& byte_5D4594[1096504])
        return 0;
    *(_DWORD*)& byte_5D4594[1096508] = 0;
    *(_DWORD*)& byte_5D4594[1096512] = nox_malloc(0x400u);
    if (!*(_DWORD*)& byte_5D4594[1096512])
        return 0;
    *(_DWORD*)& byte_5D4594[1096516] = 0;
    return 1;
}

//----- (00473B30) --------------------------------------------------------
int sub_473B30()
{
    if (*(_DWORD*)& byte_5D4594[1096464])
    {
        free(*(LPVOID*)& byte_5D4594[1096464]);
        *(_DWORD*)& byte_5D4594[1096464] = 0;
        *(_DWORD*)& byte_5D4594[1096468] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1096472])
    {
        free(*(LPVOID*)& byte_5D4594[1096472]);
        *(_DWORD*)& byte_5D4594[1096472] = 0;
        *(_DWORD*)& byte_5D4594[1096476] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1096480])
    {
        free(*(LPVOID*)& byte_5D4594[1096480]);
        *(_DWORD*)& byte_5D4594[1096480] = 0;
        *(_DWORD*)& byte_5D4594[1096484] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1096488])
    {
        free(*(LPVOID*)& byte_5D4594[1096488]);
        *(_DWORD*)& byte_5D4594[1096488] = 0;
        *(_DWORD*)& byte_5D4594[1096492] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1096496])
    {
        free(*(LPVOID*)& byte_5D4594[1096496]);
        *(_DWORD*)& byte_5D4594[1096496] = 0;
        *(_DWORD*)& byte_5D4594[1096500] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1096504])
    {
        free(*(LPVOID*)& byte_5D4594[1096504]);
        *(_DWORD*)& byte_5D4594[1096504] = 0;
        *(_DWORD*)& byte_5D4594[1096508] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[1096512])
    {
        free(*(LPVOID*)& byte_5D4594[1096512]);
        *(_DWORD*)& byte_5D4594[1096512] = 0;
        *(_DWORD*)& byte_5D4594[1096516] = 0;
    }
    return 1;
}

//----- (00473C10) --------------------------------------------------------
char __cdecl sub_473C10(_DWORD* a1, unsigned __int8* a2)
{
    int v2; // eax
    unsigned __int8* v3; // esi
    unsigned __int8 v4; // dl
    int v5; // ecx
    int v6; // ebx
    int v7; // ebp
    int v8; // eax
    int v9; // edi
    int v10; // eax
    int v11; // ecx
    int v12; // eax
    int v13; // ecx
    int v14; // eax
    int v15; // edx
    int v16; // eax
    int v17; // ecx
    int v18; // eax
    int v19; // ecx
    bool v20; // zf
    BOOL v21; // edx
    int v22; // ebx
    int v23; // ecx
    int v24; // edx
    int v25; // eax
    unsigned __int8 v26; // al
    unsigned __int8 v27; // al
    char v28; // cl
    int v29; // eax
    int v30; // eax
    int v31; // eax
    int* v32; // edi
    int v33; // eax
    int v34; // eax
    int v35; // eax
    int v36; // edx
    int v37; // eax
    int v38; // eax
    int v39; // eax
    int v40; // edx
    int v41; // eax
    int v42; // eax
    int v43; // eax
    int v44; // edx
    char* v45; // eax
    int v46; // ebx
    int v47; // ebp
    int v48; // eax
    int v49; // ecx
    int v50; // edx
    int v51; // eax
    int v52; // eax
    int v53; // eax
    _BYTE* v54; // edi
    char* v55; // eax
    int v56; // ebx
    int v57; // ebp
    int v58; // eax
    int v59; // edx
    int v60; // ecx
    int v61; // eax
    int v63; // [esp-18h] [ebp-80h]
    int v64; // [esp-14h] [ebp-7Ch]
    int v65; // [esp-10h] [ebp-78h]
    int v66; // [esp-Ch] [ebp-74h]
    int v67; // [esp-8h] [ebp-70h]
    int v68; // [esp-4h] [ebp-6Ch]
    int v69; // [esp-4h] [ebp-6Ch]
    int a3; // [esp+10h] [ebp-58h]
    int a4; // [esp+14h] [ebp-54h]
    int v72; // [esp+18h] [ebp-50h]
    int v73; // [esp+1Ch] [ebp-4Ch]
    int v74; // [esp+20h] [ebp-48h]
    int v75; // [esp+24h] [ebp-44h]
    int v76; // [esp+28h] [ebp-40h]
    int2 v77; // [esp+2Ch] [ebp-3Ch]
    int2 a2a; // [esp+34h] [ebp-34h]
    int2 a1a; // [esp+3Ch] [ebp-2Ch]
    int2 v80; // [esp+44h] [ebp-24h]
    int2 v81; // [esp+4Ch] [ebp-1Ch]
    int v82; // [esp+54h] [ebp-14h]
    int v83[3]; // [esp+5Ch] [ebp-Ch]
    int v84; // [esp+70h] [ebp+8h]

    LOBYTE(v2) = nox_win_width;
    v3 = a2;
    a4 = nox_win_width;
    v72 = 0;
    a3 = 0;
    if (!a2)
        return v2;
    v4 = a2[4];
    if (!(v4 & 1))
        return v2;
    v5 = a2[6];
    v6 = *a1 + 23 * a2[5] - a1[4];
    v82 = *a1 + 23 * a2[5] - a1[4];
    v7 = a1[1] + 23 * v5 - a1[5];
    v74 = *(_DWORD*)& byte_587000[4 * a2[3] + 149364];
    v8 = v74;
    if (v74 == -1)
    {
        v8 = *a2;
        v74 = *a2;
    }
    v84 = v8;
    if (v8)
    {
        if (v8 == 1 && v4 & 0x40)
            v84 = 12;
    }
    else if (v4 & 0x40)
    {
        v84 = 11;
    }
    if (!*(_DWORD*)& byte_587000[80808])
        goto LABEL_54;
    v9 = 16 * v74;
    v10 = *(_DWORD*)& byte_587000[16 * v74 + 85440];
    v11 = *(_DWORD*)& byte_587000[16 * v74 + 85448];
    a1a.field_4 = v7 + *(_DWORD*)& byte_587000[16 * v74 + 85444];
    v12 = v6 + v10;
    a2a.field_4 = v7 + *(_DWORD*)& byte_587000[16 * v74 + 85452];
    v13 = v6 + v11;
    a1a.field_0 = v12;
    a2a.field_0 = v13;
    if (v74 == 7 || v74 == 9)
    {
        if (sub_4C42A0(&a1a, &a2a, &a3, &a4))
        {
            v22 = 1;
        }
        else
        {
            v22 = 0;
            a3 = a2a.field_0;
        }
        v23 = *(_DWORD*)& byte_587000[v9 + 85508];
        a1a.field_0 = v82 + *(_DWORD*)& byte_587000[v9 + 85504];
        v24 = v82 + *(_DWORD*)& byte_587000[v9 + 85512];
        v25 = *(_DWORD*)& byte_587000[v9 + 85516];
        a1a.field_4 = v7 + v23;
        a2a.field_0 = v24;
        a2a.field_4 = v7 + v25;
        v2 = sub_4C42A0(&a1a, &a2a, &a3, &a4);
        if (v2)
        {
        LABEL_51:
            v19 = a3;
            v2 = a4;
            goto LABEL_52;
        }
        if (!v22)
            return v2;
        v2 = a4;
        if (a4 > a1a.field_0)
        {
            v2 = a1a.field_0;
            a4 = a1a.field_0;
        }
        v19 = a3;
    LABEL_52:
        if (v19 >= v2)
        {
            v26 = v3[4];
            v3[3] = 0;
            LOBYTE(v2) = v26 & 0xFC;
            v3[4] = v2;
            return v2;
        }
    LABEL_54:
        v27 = v3[4];
        v28 = v3[4] & 2;
        if (!v28)
        {
            v29 = (v3[4] >> 2) & 2;
            goto LABEL_64;
        }
        if (*(_DWORD*)& byte_5D4594[805848] && *(_DWORD*)& byte_5D4594[805844])
        {
            if (!*(_DWORD*)& byte_587000[80820] && *(_DWORD*)& byte_587000[154952])
                goto LABEL_61;
            v72 = 8;
        }
        if (*(_DWORD*)& byte_587000[80820])
        {
        LABEL_62:
            v29 = (v27 & 8 | 4u) >> 2;
        LABEL_64:
            v73 = v29;
            if (v28 && *(_DWORD*)& byte_5D4594[805844] && !(byte_5D4594[12332 * v3[1] + 2692780] & 4))
            {
                v30 = v72;
                LOBYTE(v30) = v72 | 2;
                v72 = v30;
            }
            else
            {
                v72 |= 1u;
            }
            if (*(_DWORD*)& byte_587000[80816])
            {
                switch (v74)
                {
                case 0:
                case 3:
                    v31 = v3[6];
                    v77.field_0 = 23 * v3[5];
                    v77.field_4 = 23 * (v31 + 1);
                    v32 = (int*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    if (*(_DWORD*)& byte_5D4594[3801780] == 1 && v32 != (int*)31)
                    {
                        v83[0] = *v32;
                        v83[1] = v32[1];
                        v33 = v32[2];
                        v32 = v83;
                        v83[2] = v33;
                    }
                    v77.field_0 += 23;
                    v77.field_4 -= 23;
                    v34 = (*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    goto LABEL_96;
                case 1:
                case 4:
                    v35 = v3[6];
                    v77.field_0 = 23 * v3[5];
                    v77.field_4 = 23 * v35;
                    v32 = (int*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    if (*(_DWORD*)& byte_5D4594[3801780] == 1 && v32 != (int*)31)
                    {
                        v83[0] = *v32;
                        v83[1] = v32[1];
                        v36 = v32[2];
                        v32 = v83;
                        v83[2] = v36;
                    }
                    v77.field_0 += 23;
                    v77.field_4 += 23;
                    goto LABEL_95;
                case 7:
                    v37 = v3[6];
                    v77.field_0 = 23 * v3[5];
                    v77.field_4 = 23 * v37;
                    v32 = (int*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    if (*(_DWORD*)& byte_5D4594[3801780] == 1 && v32 != (int*)31)
                    {
                        v83[0] = *v32;
                        v83[1] = v32[1];
                        v38 = v32[2];
                        v32 = v83;
                        v83[2] = v38;
                    }
                    v77.field_0 += 23;
                    v34 = (*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    goto LABEL_96;
                case 8:
                    v39 = v3[6];
                    v77.field_0 = 23 * v3[5] + 11;
                    v77.field_4 = 23 * v39 + 11;
                    v32 = (int*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    if (*(_DWORD*)& byte_5D4594[3801780] == 1 && v32 != (int*)31)
                    {
                        v83[0] = *v32;
                        v83[1] = v32[1];
                        v40 = v32[2];
                        v32 = v83;
                        v83[2] = v40;
                    }
                    v77.field_0 -= 34;
                    v77.field_4 -= 34;
                    goto LABEL_95;
                case 10:
                    v41 = v3[6];
                    v77.field_0 = 23 * v3[5];
                    v77.field_4 = 23 * (v41 + 1);
                    v32 = (int*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    if (*(_DWORD*)& byte_5D4594[3801780] == 1 && v32 != (int*)31)
                    {
                        v83[0] = *v32;
                        v83[1] = v32[1];
                        v42 = v32[2];
                        v32 = v83;
                        v83[2] = v42;
                    }
                    v77.field_0 += 11;
                    v77.field_4 -= 11;
                    v34 = (*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    goto LABEL_96;
                default:
                    v43 = v3[6];
                    v77.field_0 = 23 * v3[5];
                    v77.field_4 = 23 * (v43 + 1);
                    v32 = (int*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                    if (*(_DWORD*)& byte_5D4594[3801780] == 1 && v32 != (int*)31)
                    {
                        v83[0] = *v32;
                        v83[1] = v32[1];
                        v44 = v32[2];
                        v32 = v83;
                        v83[2] = v44;
                    }
                    v77.field_0 += 23;
                LABEL_95:
                    v34 = (*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                LABEL_96:
                    v74 = v34;
                    v45 = sub_46A3F0(v3[1], v84, v3[2], v73);
                    v46 = v82 + *(_DWORD*)v45 - 51;
                    v47 = -73 - *((_DWORD*)v45 + 1) + v7;
                    v48 = sub_4345F0(1);
                    LOBYTE(v48) = *((_BYTE*)v32 + 8);
                    LOBYTE(v49) = *((_BYTE*)v32 + 4);
                    LOBYTE(v50) = *(_BYTE*)v32;
                    sub_433CD0(v50, v49, v48);
                    if (!(v72 & 2))
                    {
                        v69 = v72;
                        v66 = a4;
                        v65 = a3;
                        v64 = nox_win_height;
                        v63 = v74;
                        v52 = sub_46A3B0(v3[1], v84, v3[2], v73);
                        (*(void(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[3807128])(
                            v52,
                            v46,
                            v47,
                            v32,
                            v63,
                            v64,
                            v65,
                            v66,
                            0,
                            v69);
                        goto LABEL_106;
                    }
                    if (!sub_47D380(a3, a4))
                        goto LABEL_106;
                    sub_434560(1);
                    sub_434580(0x80u);
                    sub_47D400(*(_DWORD*)& byte_587000[80820] == 0, a1[5]);
                    v68 = v47;
                    v67 = v46;
                    v51 = sub_46A3B0(v3[1], v84, v3[2], v73);
                    break;
                }
            }
            else
            {
                v53 = v3[6];
                v77.field_0 = 23 * v3[5] + 11;
                v77.field_4 = 23 * v53 + 11;
                v54 = (_BYTE*)(*(int(__cdecl * *)(int2*)) & byte_5D4594[3807156])(&v77);
                v55 = sub_46A3F0(v3[1], v84, v3[2], v73);
                v56 = v82 + *(_DWORD*)v55 - 50;
                v57 = -72 - *((_DWORD*)v55 + 1) + v7;
                v58 = sub_4345F0(1);
                LOBYTE(v59) = v54[8];
                LOBYTE(v58) = v54[4];
                LOBYTE(v60) = *v54;
                sub_433CD0(v60, v58, v59);
                if (!(v72 & 2))
                {
                    if (sub_47D380(a3, a4))
                    {
                        sub_47D400(*(_DWORD*)& byte_587000[80820] == 0, a1[5]);
                        v61 = sub_46A3B0(v3[1], v84, v3[2], v73);
                        sub_47D2C0(v61, v56, v57);
                        sub_47D400(0, 0);
                    }
                    goto LABEL_106;
                }
                if (!sub_47D380(a3, a4))
                {
                LABEL_106:
                    sub_4345F0(0);
                    LOBYTE(v2) = v3[4] & 0xFC;
                    v3[3] = 0;
                    v3[4] = v2;
                    *((_DWORD*)v3 + 3) = 1;
                    return v2;
                }
                sub_434560(1);
                sub_434580(0x80u);
                sub_47D400(*(_DWORD*)& byte_587000[80820] == 0, a1[5]);
                v68 = v57;
                v67 = v56;
                v51 = sub_46A3B0(v3[1], v84, v3[2], v73);
            }
            sub_47D2C0(v51, v67, v68);
            sub_47D400(0, 0);
            sub_434560(0);
            goto LABEL_106;
        }
    LABEL_61:
        v72 |= 4u;
        goto LABEL_62;
    }
    if (v74 != 8 && v74 != 10)
    {
        v2 = sub_4C42A0(&a1a, &a2a, &a3, &a4);
        if (!v2)
            return v2;
        goto LABEL_51;
    }
    v76 = v13;
    v75 = v12;
    if (sub_4C42A0(&a1a, &a2a, &v75, &v76))
        v73 = v76 - v75 >= 3;
    else
        v73 = 0;
    v14 = *(_DWORD*)& byte_587000[16 * v74 + 85504];
    v15 = *(_DWORD*)& byte_587000[16 * v74 + 85516];
    v80.field_4 = v7 + *(_DWORD*)& byte_587000[16 * v74 + 85508];
    v16 = v6 + v14;
    v17 = v6 + *(_DWORD*)& byte_587000[16 * v74 + 85512];
    v80.field_0 = v16;
    a3 = v16;
    v81.field_0 = v17;
    a4 = v17;
    v81.field_4 = v7 + v15;
    v18 = sub_4C42A0(&v80, &v81, &a3, &a4);
    v19 = a3;
    v20 = v18 == 0;
    v2 = a4;
    if (v20)
        v21 = 0;
    else
        v21 = a4 - a3 >= 3;
    if (v73)
    {
        if (v21)
        {
            if (a3 > v75)
            {
                v19 = v75;
                a3 = v75;
            }
            if (v19 <= v80.field_0)
            {
                v19 = 0;
                a3 = 0;
            }
            if (a4 < v76)
            {
                v2 = v76;
                a4 = v76;
            }
            if (v2 >= v81.field_0)
            {
                v2 = nox_win_width;
                a4 = nox_win_width;
            }
        }
        else
        {
            v19 = v75;
            v2 = v76;
            a3 = v75;
            a4 = v76;
            if (v74 != 8)
            {
                v84 = 1;
            LABEL_33:
                if (v19 == v80.field_0)
                {
                    v19 = 0;
                    a3 = 0;
                }
                goto LABEL_52;
            }
            v84 = 0;
            if (v76 == v81.field_0)
            {
                v2 = nox_win_width;
                a4 = nox_win_width;
            }
        }
        goto LABEL_52;
    }
    if (v21)
    {
        v84 = (v74 != 8) + 13;
        if (a4 == v81.field_0)
        {
            v2 = nox_win_width;
            a4 = nox_win_width;
        }
        goto LABEL_33;
    }
    return v2;
}
// 474366: variable 'v50' is possibly undefined
// 474366: variable 'v49' is possibly undefined
// 4744A3: variable 'v60' is possibly undefined
// 4744A3: variable 'v59' is possibly undefined

//----- (004745F0) --------------------------------------------------------
int __cdecl sub_4745F0(_DWORD* a1)
{
    void(__cdecl * v1)(int, unsigned __int8*); // ebx
    int result; // eax
    int* i; // ebp
    int v4; // esi
    int v5; // eax

    v1 = sub_476850;
    if (*(_DWORD*)& byte_5D4594[3799624])
        v1 = (void(__cdecl*)(int, unsigned __int8*))sub_476AE0;
    result = *(_DWORD*)& byte_5D4594[1096484];
    for (i = *(int**)& byte_5D4594[1096480]; *(_DWORD*)& byte_5D4594[1096484]; -- * (_DWORD*)& byte_5D4594[1096484])
    {
        v4 = *i;
        ++i;
        sub_4746C0(a1, v4);
        if (sub_4984B0(v4))
        {
            *(_DWORD*)(v4 + 484) = 1;
            v1((int)a1, (unsigned __int8*)v4);
            if (*(_BYTE*)(v4 + 280) & 0x40)
                sub_4C4F40(a1, v4);
            sub_474E60(a1, v4);
            sub_495BB0((_DWORD*)v4, a1);
            if (byte_5D4594[2650636] & 2)
                nox_thing_debug_draw(a1, v4);
            v5 = *(_DWORD*)(v4 + 480);
            *(_DWORD*)(v4 + 132) = 0;
            if (!v5 && !*(_DWORD*)(v4 + 488))
                * (_DWORD*)(v4 + 340) = *(_DWORD*)& byte_5D4594[2598000];
        }
        result = *(_DWORD*)& byte_5D4594[1096484] - 1;
    }
    return result;
}

//----- (004746C0) --------------------------------------------------------
int __cdecl sub_4746C0(_DWORD* a1, int a2)
{
    int v2; // edi
    int v3; // eax
    int v4; // eax
    int v5; // edi
    int v6; // eax
    int v7; // eax
    char v8; // al
    int result; // eax
    int v10; // [esp-24h] [ebp-34h]
    int v11; // [esp-24h] [ebp-34h]
    int v12; // [esp-24h] [ebp-34h]
    int v13; // [esp-24h] [ebp-34h]
    char v14; // [esp-1Ch] [ebp-2Ch]
    char v15; // [esp-1Ch] [ebp-2Ch]
    char v16; // [esp-1Ch] [ebp-2Ch]
    char v17; // [esp-1Ch] [ebp-2Ch]
    char v18; // [esp-18h] [ebp-28h]
    char v19; // [esp-18h] [ebp-28h]
    char v20; // [esp-18h] [ebp-28h]
    char v21; // [esp-18h] [ebp-28h]
    int v22; // [esp-8h] [ebp-18h]
    int v23; // [esp-8h] [ebp-18h]
    int v24; // [esp-8h] [ebp-18h]
    int v25; // [esp-8h] [ebp-18h]
    int2 v26; // [esp+8h] [ebp-8h]

    if (sub_4356C0(a2, 0) && !sub_474B40(a2))
        goto LABEL_37;
    if (sub_4356C0(a2, 14))
    {
        sub_4739E0(a1, (int2*)(a2 + 12), &v26);
        sub_4B6720(&v26, *(int*)& byte_5D4594[2650684], 30, 31);
    }
    if (sub_4356C0(a2, 9) && !sub_413A50())
    {
        if (!*(_DWORD*)& byte_5D4594[1096524])
        {
            *(_DWORD*)& byte_5D4594[1096524] = sub_44CFC0((CHAR*)& byte_587000[149612]);
            *(_DWORD*)& byte_5D4594[1096528] = sub_44CFC0((CHAR*)& byte_587000[149632]);
        }
        if (*(_DWORD*)(a2 + 12) != *(_DWORD*)(a2 + 32) || *(_DWORD*)(a2 + 16) != *(_DWORD*)(a2 + 36))
            v2 = 2;
        else
            v2 = 0;
        if (v2 > 0)
        {
            do
            {
                v22 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1055);
                v18 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1051);
                v14 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1050);
                v10 = *(_DWORD*)(a2 + 16)
                    + *(__int16*)(a2 + 104)
                    + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1048);
                v3 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1047);
                sub_499F60(*(int*)& byte_5D4594[1096524], *(_DWORD*)(a2 + 12) + v3, v10, 1, v14, v18, 0, 0, 0, v22);
                v23 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1066);
                v19 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1062);
                v15 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1061);
                v11 = *(_DWORD*)(a2 + 16)
                    + *(__int16*)(a2 + 104)
                    + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1059);
                v4 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1058);
                sub_499F60(*(int*)& byte_5D4594[1096528], *(_DWORD*)(a2 + 12) + v4, v11, 1, v15, v19, 0, 0, 0, v23);
                --v2;
            } while (v2);
        }
    }
    if (sub_4356C0(a2, 8) && !sub_413A50())
    {
        if (!*(_DWORD*)& byte_5D4594[1096532])
        {
            *(_DWORD*)& byte_5D4594[1096532] = sub_44CFC0((CHAR*)& byte_587000[150056]);
            *(_DWORD*)& byte_5D4594[1096536] = sub_44CFC0((CHAR*)& byte_587000[150076]);
        }
        if (*(_DWORD*)(a2 + 12) != *(_DWORD*)(a2 + 32) || (v5 = 1, *(_DWORD*)(a2 + 16) != *(_DWORD*)(a2 + 36)))
            v5 = 2;
        do
        {
            v24 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1108);
            v20 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1104);
            v16 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1103);
            v12 = *(_DWORD*)(a2 + 16)
                + *(__int16*)(a2 + 104)
                + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1101);
            v6 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1100);
            sub_499F60(*(int*)& byte_5D4594[1096532], *(_DWORD*)(a2 + 12) + v6, v12, 1, v16, v20, 0, 0, 0, v24);
            v25 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1119);
            v21 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1115);
            v17 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1114);
            v13 = *(_DWORD*)(a2 + 16)
                + *(__int16*)(a2 + 104)
                + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1112);
            v7 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1111);
            sub_499F60(*(int*)& byte_5D4594[1096536], *(_DWORD*)(a2 + 12) + v7, v13, 1, v17, v21, 0, 0, 0, v25);
            --v5;
        } while (v5);
    }
    if (sub_4356C0(a2, 17))
        sub_474BE0(a1, (int*)(a2 + 12), a2, 0, 0, *(int*)& byte_5D4594[2650644], *(int*)& byte_5D4594[2589776], 1);
    if (sub_4356C0(a2, 18))
        sub_474BE0(a1, (int*)(a2 + 12), a2, 85, 1, *(int*)& byte_5D4594[2618904], *(int*)& byte_5D4594[2614268], 1);
    if (sub_4356C0(a2, 20))
        sub_474BE0(a1, (int*)(a2 + 12), a2, 170, 2, *(int*)& byte_5D4594[2650684], *(int*)& byte_5D4594[2523948], 1);
    if (!sub_4356C0(a2, 27) || (v8 = *(_BYTE*)(a2 + 297)) != 0 && v8 != 1 && v8 != 2)
        LABEL_37:
    result = 0;
    else
        result = sub_499810((int)a1, a2);
    return result;
}

//----- (00474B40) --------------------------------------------------------
int __cdecl sub_474B40(int a1)
{
    _DWORD* v1; // edi
    _DWORD* v2; // eax
    int v3; // eax

    v1 = sub_418C80(*(int*)& byte_5D4594[2616328]);
    if (v1)
    {
        v2 = sub_418C80(*(_DWORD*)(a1 + 128));
        if (v2)
        {
            if (*(_DWORD*)& byte_5D4594[2616328] == *(_DWORD*)(a1 + 128) || sub_419150((int)v1, (int)v2))
                return 1;
        }
    }
    v3 = *(_DWORD*)& byte_5D4594[2614252];
    if (a1 == *(_DWORD*)& byte_5D4594[2614252])
        return 1;
    if (*(_DWORD*)& byte_5D4594[2614252])
    {
        if (!sub_4356C0(*(int*)& byte_5D4594[2614252], 21))
        {
            v3 = *(_DWORD*)& byte_5D4594[2614252];
            goto LABEL_9;
        }
        return 1;
    }
LABEL_9:
    if (*(_BYTE*)(a1 + 112) & 4)
    {
        if (a1 != v3)
            sub_417040(*(_DWORD*)(a1 + 128));
    }
    return 0;
}

//----- (00474BE0) --------------------------------------------------------
int __cdecl sub_474BE0(_DWORD* a1, int* a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int* v8; // ebp
    int v9; // esi
    int v10; // eax
    int v11; // edx
    int v12; // edi
    int v13; // eax
    int v14; // ecx
    int v15; // eax
    int v16; // edi
    int v17; // ebx
    int v18; // eax
    int v19; // ecx
    int v20; // eax
    int v21; // ecx
    int v22; // eax
    int v23; // eax
    int result; // eax
    float v25; // [esp+0h] [ebp-2Ch]
    float v26; // [esp+0h] [ebp-2Ch]
    float v27; // [esp+0h] [ebp-2Ch]
    float v28; // [esp+0h] [ebp-2Ch]
    int i; // [esp+14h] [ebp-18h]
    int2 v30; // [esp+1Ch] [ebp-10h]
    int2 v31; // [esp+24h] [ebp-8h]
    float v32; // [esp+34h] [ebp+8h]

    v8 = a2;
    v9 = a8;
    for (i = 0; i < 2; ++i)
    {
        if (i)
        {
            v9 += 128;
            if (v9 < 256)
                goto LABEL_7;
        }
        else
        {
            v9 = a4 + (unsigned __int8)(10 * (byte_5D4594[2598000] + *(_BYTE*)(a3 + 128)));
            if (v9 < 256)
                goto LABEL_7;
        }
        v9 -= 256;
    LABEL_7:
        v32 = 0.70709997;
        if (!a5)
            v32 = 1.0;
        v25 = (double)(2 * *(int*)& byte_587000[8 * v9 + 192088]) * v32 + (double)* v8;
        v10 = sub_419A70(v25);
        v11 = *(int*)& byte_587000[8 * v9 + 192092];
        v30.field_0 = v10;
        v26 = (double)(2 * v11) * v32 + (double)v8[1];
        v30.field_4 = sub_419A70(v26);
        v12 = v9 - 6 + (v9 - 6 < 0 ? 0x100 : 0);
        v27 = (double)(2 * *(int*)& byte_587000[8 * v12 + 192088]) * v32 + (double)* v8;
        v13 = sub_419A70(v27);
        v14 = *(int*)& byte_587000[8 * v12 + 192092];
        v31.field_0 = v13;
        v28 = (double)(2 * v14) * v32 + (double)v8[1];
        v15 = sub_419A70(v28);
        v16 = v30.field_4;
        v17 = v15;
        v18 = v8[1];
        v19 = 0;
        v31.field_4 = v17;
        if (v30.field_4 >= v18)
            goto LABEL_25;
        if (a8 == 1)
            v19 = 1;
        if (v30.field_4 >= v18)
        {
        LABEL_25:
            if (!a8)
                goto LABEL_24;
        }
        if (v19)
        {
        LABEL_24:
            if (a5 == 1)
            {
                v20 = *v8;
                v21 = v30.field_0;
                goto LABEL_19;
            }
            if (a5 == 2)
            {
                v20 = v30.field_0;
                v21 = *v8;
            LABEL_19:
                v22 = 35 * (v20 - v21) / (2 * *(_DWORD*)& byte_587000[192088]);
                v16 = v22 + v30.field_4;
                v17 += v22;
            }
            v23 = *(__int16*)(a3 + 104);
            v30.field_4 = -20 - v23 + v16;
            v31.field_4 = -20 - v23 + v17;
            sub_474DD0(a1, &v30, &v31, a6, a7);
        }
        result = i + 1;
    }
    return result;
}

//----- (00474DD0) --------------------------------------------------------
int __cdecl sub_474DD0(_DWORD* a1, int2* a2, int2* a3, int a4, int a5)
{
    int2 xLeft; // [esp+8h] [ebp-8h]

    sub_4739E0(a1, a2, &xLeft);
    sub_4B6720(&xLeft, a4, 10, 12);
    sub_434460(a5);
    sub_499B70(xLeft.field_0, xLeft.field_4, 3);
    sub_49F500(xLeft.field_0, xLeft.field_4);
    sub_4739E0(a1, a3, &xLeft);
    sub_49F500(xLeft.field_0, xLeft.field_4);
    sub_434460(a5);
    return sub_49E4B0();
}

//----- (00474E60) --------------------------------------------------------
int __cdecl sub_474E60(_DWORD* a1, int a2)
{
    int v2; // esi
    int v3; // eax
    _DWORD* v4; // ebp
    int v5; // edx
    char v6; // al
    int v7; // ecx
    int v8; // eax
    int v9; // edx
    int v10; // eax
    int v11; // ebx
    int v12; // ebp
    int v13; // eax
    int v14; // eax
    int v15; // eax
    int v16; // ebx
    int v17; // edi
    int v18; // eax
    int v19; // eax
    int v20; // eax
    int v21; // eax
    int v22; // eax
    int v23; // eax
    int v24; // edx
    int v25; // ebx
    int v26; // eax
    char v27; // al
    int result; // eax
    int v29; // [esp-20h] [ebp-44h]
    int v30; // [esp-1Ch] [ebp-40h]
    int v31; // [esp-1Ch] [ebp-40h]
    __int16 v32; // [esp-18h] [ebp-3Ch]
    __int16 v33; // [esp-18h] [ebp-3Ch]
    char v34; // [esp-14h] [ebp-38h]
    char v35; // [esp-14h] [ebp-38h]
    char v36; // [esp-10h] [ebp-34h]
    char v37; // [esp-10h] [ebp-34h]
    int v38; // [esp-8h] [ebp-2Ch]
    float v39; // [esp+0h] [ebp-24h]
    int v40; // [esp+0h] [ebp-24h]
    int v41; // [esp+0h] [ebp-24h]
    int2 xLeft; // [esp+14h] [ebp-10h]
    int2 a3; // [esp+1Ch] [ebp-8h]
    int v44; // [esp+2Ch] [ebp+8h]

    v2 = a2;
    if (sub_4356C0(a2, 0) && !sub_474B40(a2))
        goto LABEL_54;
    if (sub_4356C0(a2, 22))
    {
        v3 = *(_DWORD*)& byte_5D4594[1096540];
        if (!*(_DWORD*)& byte_5D4594[1096540])
        {
            v3 = sub_44CFC0((CHAR*)& byte_587000[150500]);
            *(_DWORD*)& byte_5D4594[1096540] = v3;
        }
        sub_499710(*(_DWORD*)(a2 + 12), *(_DWORD*)(a2 + 16), *(_WORD*)(a2 + 104), v3);
    }
    if (sub_4356C0(a2, 3) || sub_4356C0(a2, 5) || sub_4356C0(a2, 29) || sub_4356C0(a2, 28))
    {
        v4 = a1;
        sub_4739E0(a1, (int2*)(a2 + 12), &xLeft);
        v5 = 5 - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - sub_419A70(*(float*)(a2 + 100));
        v6 = *(_BYTE*)(a2 + 112);
        v7 = v5 + xLeft.field_4;
        xLeft.field_4 += v5;
        if (v6 & 4 && *(_DWORD*)(a2 + 276) == 6)
        {
            v8 = 8 * *(unsigned __int8*)(a2 + 297);
            v9 = *(_DWORD*)& byte_587000[v8 + 149432];
            v10 = *(_DWORD*)& byte_587000[v8 + 149436];
            xLeft.field_0 += v9;
            xLeft.field_4 = v10 + v7;
        }
        if (sub_4356C0(a2, 29))
        {
            sub_434600(1);
            sub_433E40(*(int*)& byte_5D4594[2650684]);
        }
        sub_4BE6D0(*(int*)& byte_5D4594[1096456], xLeft.field_0 - 64, xLeft.field_4 - 64);
        sub_434600(0);
    }
    else
    {
        v4 = a1;
    }
    if (sub_4356C0(a2, 4) && !sub_413A50())
    {
        v11 = sub_419A70(*(float*)(a2 + 48));
        v39 = *(float*)(a2 + 100) * 0.5;
        v44 = sub_419A70(v39);
        if (!*(_DWORD*)& byte_5D4594[1096544])
            * (_DWORD*)& byte_5D4594[1096544] = sub_44CFC0((CHAR*)& byte_587000[150512]);
        v12 = 2;
        do
        {
            v40 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1307);
            v36 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1303);
            v34 = sub_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1302);
            v32 = sub_415FF0(0, v44, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1301);
            v30 = *(_DWORD*)(v2 + 16) + sub_415FF0(-v11, v11, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1300);
            v13 = sub_415FF0(-v11, v11, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1299);
            sub_499F60(*(int*)& byte_5D4594[1096544], *(_DWORD*)(v2 + 12) + v13, v30, v32, v34, v36, -5, 0, 0, v40);
            --v12;
        } while (v12);
        v4 = a1;
    }
    if (sub_4356C0(v2, 21) && !sub_413A50())
    {
        if (!*(_DWORD*)& byte_5D4594[1096548])
            * (_DWORD*)& byte_5D4594[1096548] = sub_44CFC0((CHAR*)& byte_587000[150776]);
        v41 = sub_415FF0(2, 3, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1335);
        v37 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1331);
        v35 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1330);
        v29 = sub_419A70(*(float*)(v2 + 100)) + 12;
        v14 = sub_419A70(*(float*)(v2 + 100));
        v33 = sub_415FF0(v14 + 8, v29, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1329);
        v31 = *(_DWORD*)(v2 + 16) + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1327);
        v15 = sub_415FF0(-6, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1326);
        sub_499F60(*(int*)& byte_5D4594[1096548], *(_DWORD*)(v2 + 12) + v15, v31, v33, v35, v37, 1, 0, 0, v41);
    }
    if (sub_4356C0(v2, 13) && !sub_413A50())
    {
        if (!*(_DWORD*)& byte_5D4594[1096552])
        {
            *(_DWORD*)& byte_5D4594[1096452] = sub_4344A0(255, 0, 255);
            *(_DWORD*)& byte_5D4594[1096436] = sub_4344A0(255, 180, 255);
            *(_DWORD*)& byte_5D4594[1096552] = 1;
        }
        sub_4739E0(v4, (int2*)(v2 + 12), &a3);
        v16 = 10;
        do
        {
            v17 = sub_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1366);
            v38 = sub_419A70(*(float*)(v2 + 48));
            v18 = sub_419A70(*(float*)(v2 + 48));
            v19 = sub_415FF0(-v18, v38, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1369);
            xLeft.field_0 = a3.field_0 + v19;
            v20 = sub_419A70(*(float*)(v2 + 100));
            v21 = sub_415FF0(-10 - v20, 0, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1370);
            xLeft.field_4 = v21 + a3.field_4 + *(__int16*)(v2 + 104);
            v22 = sub_415FF0(3, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1372);
            sub_4B6720(&xLeft, *(int*)& byte_5D4594[1096452], v17 + v22, v17 + 2);
            sub_434460(*(int*)& byte_5D4594[1096436]);
            sub_499B70(xLeft.field_0, xLeft.field_4, v17);
            --v16;
        } while (v16);
    }
    if (sub_4356C0(v2, 17))
        sub_474BE0(v4, (int*)(v2 + 12), v2, 0, 0, *(int*)& byte_5D4594[2650644], *(int*)& byte_5D4594[2589776], 0);
    if (sub_4356C0(v2, 18))
        sub_474BE0(v4, (int*)(v2 + 12), v2, 85, 1, *(int*)& byte_5D4594[2618904], *(int*)& byte_5D4594[2614268], 0);
    if (sub_4356C0(v2, 20))
        sub_474BE0(v4, (int*)(v2 + 12), v2, 170, 2, *(int*)& byte_5D4594[2650684], *(int*)& byte_5D4594[2523948], 0);
    if (sub_4356C0(v2, 26))
    {
        sub_4739E0(v4, (int2*)(v2 + 12), &xLeft);
        v23 = *(_DWORD*)(v2 + 276);
        v24 = -90 - *(__int16*)(v2 + 104);
        v25 = xLeft.field_0 - 64;
        xLeft.field_0 -= 64;
        xLeft.field_4 += v24;
        if (v23 == 6)
        {
            v26 = 8 * *(unsigned __int8*)(v2 + 297);
            xLeft.field_0 = *(_DWORD*)& byte_587000[v26 + 149504] + v25;
            xLeft.field_4 += *(_DWORD*)& byte_587000[v26 + 149508];
        }
        sub_434560(1);
        sub_434580(0x80u);
        sub_4BE6D0(*(int*)& byte_5D4594[1096460], xLeft.field_0, xLeft.field_4);
        sub_434560(0);
    }
    if (sub_4356C0(v2, 27) && (v27 = *(_BYTE*)(v2 + 297)) != 0 && v27 != 1 && v27 != 2)
        result = sub_499810((int)v4, v2);
    else
        LABEL_54:
    result = 0;
    return result;
}

//----- (004754C0) --------------------------------------------------------
size_t __cdecl sub_4754C0(int a1)
{
    size_t result; // eax

    result = *(_DWORD*)& byte_5D4594[1096516];
    if (*(int*)& byte_5D4594[1096516] < 256)
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1096512] + 4 * *(_DWORD*)& byte_5D4594[1096516]) = a1;
        result = ++ * (_DWORD*)& byte_5D4594[1096516];
    }
    return result;
}

//----- (004754F0) --------------------------------------------------------
void __cdecl sub_4754F0(_DWORD* a1)
{
    int v1; // edx
    int v2; // ecx
    int v3; // edx
    int4 v4; // [esp+0h] [ebp-10h]

    v1 = a1[4] + a1[8];
    v4.field_0 = a1[4];
    v2 = a1[5];
    v4.field_8 = v1;
    v3 = a1[9];
    v4.field_4 = v2;
    v4.field_C = v3 + v2 + 128;
    *(_DWORD*)& byte_5D4594[1096468] = 0;
    *(_DWORD*)& byte_5D4594[1096476] = 0;
    *(_DWORD*)& byte_5D4594[1096484] = 0;
    *(_DWORD*)& byte_5D4594[1096492] = 0;
    *(_DWORD*)& byte_5D4594[1096500] = 0;
    *(_DWORD*)& byte_5D4594[1096508] = 0;
    sub_49AB00(&v4, (void(__cdecl*)(int, int))sub_475560, (int)a1);
}

//----- (00475560) --------------------------------------------------------
void __cdecl sub_475560(int a1)
{
    if (sub_4756E0((_DWORD*)a1))
    {
        if (*(int*)& byte_5D4594[1096484] < 512)
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1096480] + 4 * (*(_DWORD*)& byte_5D4594[1096484])++) = a1;
        return;
    }
    if (sub_475740((_DWORD*)a1))
    {
        if (*(int*)& byte_5D4594[1096476] < 512)
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1096472] + 4 * (*(_DWORD*)& byte_5D4594[1096476])++) = a1;
    }
    else if (sub_4757A0(a1))
    {
        if (*(int*)& byte_5D4594[1096492] < 512)
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1096488] + 4 * (*(_DWORD*)& byte_5D4594[1096492])++) = a1;
    }
    else if (sub_4757D0((_DWORD*)a1)
        && (*(_DWORD*)& byte_587000[80836] || a1 == *(_DWORD*)& byte_5D4594[2614252] || sub_4984B0(a1)))
    {
        if (!*(_DWORD*)(a1 + 488))
        {
            if (sub_4984B0(a1))
            {
                *(_DWORD*)(a1 + 484) = 1;
                *(_DWORD*)(a1 + 480) = 0;
            }
            else
            {
                if (!*(_DWORD*)(a1 + 484) || *(_BYTE*)(a1 + 112) & 6)
                    return;
                *(_DWORD*)(a1 + 480) = 1;
            }
        }
        if ((*(_DWORD*)(a1 + 480) || *(_DWORD*)(a1 + 488))
            && (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(a1 + 340)) > * (int*)& byte_5D4594[2649704])
        {
            *(_DWORD*)(a1 + 480) = 0;
        }
        else if (*(int*)& byte_5D4594[1096468] < 8192)
        {
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[1096464] + 4 * (*(_DWORD*)& byte_5D4594[1096468])++) = a1;
        }
    }
}

//----- (004756E0) --------------------------------------------------------
int __cdecl sub_4756E0(_DWORD* a1)
{
    int result; // eax
    int(__cdecl * v2)(int*, int); // esi
    int v3; // edx
    int v4; // ecx

    result = 0;
    v2 = (int(__cdecl*)(int*, int))a1[75];
    if (v2)
    {
        v3 = a1[30];
        v4 = a1[28];
        if (!(v3 & 0x1000)
            && v3 & 1
            && (v2 == nox_thing_static_draw || v2 == nox_thing_static_random_draw)
            && !(v4 & 0x80800000)
            && (v3 & 0x48 || v4 & 0x400000)
            && !(v3 & 0x800))
        {
            result = 1;
        }
    }
    return result;
}

//----- (00475740) --------------------------------------------------------
int __cdecl sub_475740(_DWORD* a1)
{
    int result; // eax
    int(__cdecl * v2)(int*, int); // edx
    int v3; // ebx
    int v4; // ecx

    result = 0;
    v2 = (int(__cdecl*)(int*, int))a1[75];
    if (v2)
    {
        v3 = a1[30];
        v4 = a1[28];
        if (!(v3 & 0x1000))
        {
            if (v3 & 1)
            {
                result = 1;
                if ((v2 == nox_thing_static_draw || v2 == nox_thing_static_random_draw)
                    && !(v4 & 0x80800000)
                    && !(v3 & 0x800)
                    && (v3 & 0x48 || v4 & 0x400000))
                {
                    result = 0;
                }
            }
        }
    }
    return result;
}

//----- (004757A0) --------------------------------------------------------
int __cdecl sub_4757A0(int a1)
{
    int result; // eax
    int v2; // ecx

    result = 0;
    if (*(_DWORD*)(a1 + 300))
    {
        v2 = *(_DWORD*)(a1 + 120);
        if (!(v2 & 0x1000))
        {
            if (v2 & 0x4000)
            {
                if (v2 & 0x40)
                    result = 1;
            }
        }
    }
    return result;
}

//----- (004757D0) --------------------------------------------------------
int __cdecl sub_4757D0(_DWORD* a1)
{
    int result; // eax
    int v2; // ecx

    result = 0;
    if (a1[75])
    {
        v2 = a1[30];
        if (!(v2 & 1) && (!(a1[28] & 0x2000) || v2 & 0x1000000) && !(v2 & 0x1000))
            result = 1;
    }
    return result;
}

//----- (00475810) --------------------------------------------------------
int4* __cdecl sub_475810_draw(int* a1)
{
    int* v1; // edi
    int v2; // ebx
    int v3; // ebp
    int v4; // esi
    int v5; // eax
    int v6; // ecx
    int v7; // esi
    int v8; // ebp
    int4* result; // eax
    int v10; // ebp
    int v11; // eax
    int v13; // edx
    int v14; // ebx
    int v15; // eax
    int i; // ebp
    int v17; // eax
    unsigned __int8** v18; // esi
    bool j; // zf
    unsigned __int8* v20; // eax
    int v21; // ebx
    unsigned __int8* v22; // ecx
    int v23; // esi
    int v24; // eax
    int v25; // ebp
    int v26; // eax
    int v27; // eax
    char v28; // al
    unsigned __int8** v29; // esi
    unsigned __int8** v30; // esi
    int v31; // edx
    unsigned __int8* v32; // eax
    unsigned __int8* v33; // eax
    unsigned __int8 v34; // dl
    int* v35; // [esp+10h] [ebp-14h]
    int v36; // [esp+14h] [ebp-10h]
    unsigned __int8** v37; // [esp+14h] [ebp-10h]
    float2 v38; // [esp+1Ch] [ebp-8h]
    int v39; // [esp+28h] [ebp+4h]
    int v40; // [esp+28h] [ebp+4h]
    int v41; // [esp+28h] [ebp+4h]

    if (!*(_DWORD*)& byte_5D4594[1096448])
        * (_DWORD*)& byte_5D4594[1096448] = sub_44CFC0((CHAR*)& byte_587000[151196]);
    sub_477F80();
    v1 = a1;
    *(_DWORD*)& byte_5D4594[3799496] = 0;
    v2 = a1[1];
    v39 = *a1;
    if (v39)
    {
        *(_DWORD*)& byte_5D4594[3799468] = 1;
        v3 = v1[3];
        v4 = v1[2] + 1;
        sub_437290();
        if (*(_DWORD*)& byte_5D4594[3799524])
        {
            sub_434460(*(int*)& byte_5D4594[2650656]);
            sub_49CE30(0, 0, nox_backbuffer_width, v2);
            sub_49CE30(0, v3, nox_backbuffer_width, nox_backbuffer_height - v3);
            sub_49CE30(0, v2, v39, v3 - v2);
            sub_49CE30(v4, v2, nox_backbuffer_width - v4, v3 - v2);
            *(_DWORD*)& byte_5D4594[3799524] = 0;
        }
        sub_434460(*(int*)& byte_5D4594[2650660]);
        sub_49CC70(v39 - 2, v2 - 2, v4 - v39 + 4, v3 - v2 + 4);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[3799468] = 0;
    }
    sub_437260();
    v5 = v1[12];
    if (v5)
    {
        if (v5 <= 0)
            v1[12] = -1 - v5;
        else
            v1[12] = 1 - v5;
    }
    *(_DWORD*)& byte_5D4594[1096428] = v1[4] - *v1;
    *(_DWORD*)& byte_5D4594[1096432] = v1[5] - v1[1];
    v6 = v1[5];
    v36 = v1[4] / 23;
    *(_DWORD*)& byte_5D4594[1096516] = 0;
    v7 = v6 / 23;
    sub_496150(v1);
    v8 = 0;
    if (!sub_40A5C0(2048) && !sub_413830()
        || sub_40A5C0(2048) && !sub_413840()
        || sub_4356C0(*(int*)& byte_5D4594[2614252], 2)
        || *(_DWORD*)& byte_5D4594[2650672])
    {
        v8 = 1;
    }
    if (*(_DWORD*)& byte_5D4594[1556112] || v8)
    {
        sub_434350(*(int*)& byte_5D4594[2650656]);
        sub_440900();
        result = sub_437290();
        *(_DWORD*)& byte_5D4594[3799524] = 1;
        return result;
    }
    if (*(_DWORD*)& byte_5D4594[1096520])
    {
        sub_434350(*(int*)& byte_5D4594[2523948]);
        sub_440900();
        sub_434350(*(int*)& byte_5D4594[2650656]);
        *(_DWORD*)& byte_5D4594[1096520] = 0;
        result = sub_437290();
        *(_DWORD*)& byte_5D4594[3799524] = 1;
        return result;
    }
    (*(void(__cdecl * *)(_DWORD)) & byte_5D4594[3807132])(v1);
    v10 = 1;
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x100000
        || (v38.field_0 = (double)v1[6], v38.field_4 = (double)v1[7], v11 = sub_411160(&v38), v11 == 255)
        || v11 == -1)
    {
        v10 = 0;
    }
    sub_4765F0((int)v1);
    sub_4754F0(v1);
    if (v10)
    {
        sub_481C20(v1);
        sub_4C5500(v1);
    }
    else
    {
        sub_440900();
    }
    sub_475F10(v1);
    v13 = (int)v1[9] / 23 + 4;
    v14 = v13 + v7;
    if (v7 <= v13 + v7)
    {
        v15 = v36;
        v40 = v36 + v1[8] / 23 + 2;
        while (1)
        {
            for (i = v15; i <= v40; ++i)
            {
                v17 = sub_410580(i, v7);
                if (v17 && !(byte_5D4594[12332 * *(unsigned __int8*)(v17 + 1) + 2692780] & 4))
                {
                    if (*(_BYTE*)(v17 + 4) & 2)
                    {
                        if (*(int*)& byte_5D4594[1096508] < 256)
                            * (_DWORD*)(*(_DWORD*)& byte_5D4594[1096504] + 4 * (*(_DWORD*)& byte_5D4594[1096508])++) = v17;
                    }
                    else if (*(int*)& byte_5D4594[1096500] < 256)
                    {
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[1096496] + 4 * (*(_DWORD*)& byte_5D4594[1096500])++) = v17;
                    }
                }
            }
            if (++v7 > v14)
                break;
            v15 = v36;
        }
    }
    v18 = *(unsigned __int8***)& byte_5D4594[1096496];
    for (j = (*(_DWORD*)& byte_5D4594[1096500])-- == 0; !j; -- * (_DWORD*)& byte_5D4594[1096500])
    {
        v20 = *v18;
        ++v18;
        sub_473C10(v1, v20);
        j = *(_DWORD*)& byte_5D4594[1096500] == 0;
    }
    sub_475FE0(v1);
    sub_4773C0(v1);
    qsort(*(void**)& byte_5D4594[1096464], *(size_t*)& byte_5D4594[1096468], 4u, sub_476160);
    qsort(*(void**)& byte_5D4594[1096512], *(size_t*)& byte_5D4594[1096516], 4u, sub_476240);
    v35 = *(int**)& byte_5D4594[1096464];
    v37 = *(unsigned __int8***)& byte_5D4594[1096512];
    v21 = 0x7FFFFFFF;
    if (*(_DWORD*)& byte_5D4594[1096468])
        v41 = *(_DWORD*)(**(_DWORD * *)& byte_5D4594[1096464] + 16);
    else
        v41 = 0x7FFFFFFF;
    if (*(_DWORD*)& byte_5D4594[1096516])
    {
        v22 = **(unsigned __int8***)& byte_5D4594[1096512];
    LABEL_51:
        v21 = sub_476080(v22);
    }
    while (*(_DWORD*)& byte_5D4594[1096468] || *(_DWORD*)& byte_5D4594[1096516])
    {
        if (v41 >= v21)
        {
            if (*(_DWORD*)& byte_5D4594[1096516])
            {
                sub_473C10(v1, *v37);
                v29 = v37 + 1;
                j = *(_DWORD*)& byte_5D4594[1096516] == 1;
                ++v37;
                --* (_DWORD*)& byte_5D4594[1096516];
                if (!j)
                {
                    v22 = *v29;
                    goto LABEL_51;
                }
            }
            v21 = 0x7FFFFFFF;
        }
        else if (*(_DWORD*)& byte_5D4594[1096468])
        {
            v23 = *v35;
            v24 = (int)(v35 + 1);
            ++v35;
            if (-- * (_DWORD*)& byte_5D4594[1096468])
                v41 = *(_DWORD*)(*(_DWORD*)v24 + 16);
            else
                v41 = 0x7FFFFFFF;
            if (*(_DWORD*)(v23 + 108) != *(_DWORD*)& byte_5D4594[1096448] || sub_418B10() || (v25 = sub_45A000()) == 0)
            {
            LABEL_64:
                v26 = *(_DWORD*)(v23 + 112);
                if (!(v26 & 6) || (unsigned int)(*(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)(v23 + 288)) <= 5)
                    goto LABEL_71;
                if (v26 & 2)
                {
                    v27 = *(_DWORD*)(v23 + 276);
                    if (v27 == 9 || v27 == 10)
                        goto LABEL_71;
                }
                else if (*(_DWORD*)& byte_5D4594[2614252] == v23)
                {
                LABEL_71:
                    sub_4746C0(v1, v23);
                    if ((*(int(__cdecl * *)(int*, int))(v23 + 300))(v1, v23))
                    {
                        if (byte_5D4594[2650636] & 2)
                            nox_thing_debug_draw(v1, v23);
                        v28 = *(_BYTE*)(v23 + 280);
                        *(_DWORD*)(v23 + 132) = 0;
                        if (v28 & 0x40)
                            sub_4C4F40(v1, v23);
                        sub_474E60(v1, v23);
                        sub_495BB0((_DWORD*)v23, v1);
                        if (!*(_DWORD*)(v23 + 480) && !*(_DWORD*)(v23 + 488))
                            * (_DWORD*)(v23 + 340) = *(_DWORD*)& byte_5D4594[2598000];
                        if (sub_459DB0(v23))
                            sub_459DD0(v23, 1);
                        if (*(_DWORD*)(v23 + 112) & 0x20006)
                            sub_49A6A0(v1, v23);
                    }
                }
            }
            else
            {
                while (!sub_4356C0(v25, 30))
                {
                    v25 = sub_45A010(v25);
                    if (!v25)
                        goto LABEL_64;
                }
            }
        }
        else
        {
            v41 = 0x7FFFFFFF;
        }
    }
    sub_4AFD40();
    sub_4C5060(v1);
    v30 = *(unsigned __int8***)& byte_5D4594[1096504];
    v31 = *(_DWORD*)& byte_5D4594[1096508];
    if (*(_DWORD*)& byte_587000[80812])
    {
        --* (_DWORD*)& byte_5D4594[1096508];
        if (v31)
        {
            do
            {
                v32 = *v30;
                ++v30;
                sub_473C10(v1, v32);
                j = (*(_DWORD*)& byte_5D4594[1096508])-- == 0;
            } while (!j);
        }
    }
    else
    {
        --* (_DWORD*)& byte_5D4594[1096508];
        if (v31)
        {
            do
            {
                v33 = *v30;
                ++v30;
                v34 = v33[4];
                v33[3] = 0;
                v33[4] = v34 & 0xFC;
                j = (*(_DWORD*)& byte_5D4594[1096508])-- == 0;
            } while (!j);
        }
    }
    sub_44D9F0(0);
    if (byte_5D4594[2650636] & 8)
        sub_476270(v1);
    sub_45AB40();
    sub_437290();
    *(_DWORD*)& byte_5D4594[3799496] = 1;
    return (int4*)sub_476680();
}
