#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "proto.h"

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;
extern int nox_backbuffer_width32;

extern float input_sensitivity;

extern nox_video_mode nox_video_modes[];
extern int nox_video_modes_cnt;

extern table_116008_t table_116008[];
extern int table_116008_cnt;

void (*mainloop_enter)(void*);
void* mainloop_enter_args;
void (*mainloop_exit)();

const int default_win_width = 640;
const int default_win_height = 480;
const int default_win_depth = 16;

const int max_win_width = 1024;
const int max_win_height = 768;

int nox_win_width = 0;
int nox_win_height = 0;

int nox_win_width_1 = default_win_width;
int nox_win_height_1 = default_win_height;
int nox_win_depth_1 = default_win_depth;

int nox_win_width_2 = default_win_width;
int nox_win_height_2 = default_win_height;
int nox_win_depth_2 = default_win_depth;

int nox_max_width = max_win_width;
int nox_max_height = max_win_height;

extern int g_fullscreen;
int g_scaled = 0;
int g_fullscreen_cfg = 0;
int g_scaled_cfg = 0;
extern float draw_gamma;


int (*nox_draw_unk1)(void) = 0;

FILE* nox_file_6 = 0;

nox_thing* nox_things_head = 0;
nox_thing** nox_things_array = 0;
int nox_things_count = 0;

nox_mouse_state_t nox_input_buffer[256] = {0};
int nox_input_buffer_cap = sizeof(nox_input_buffer)/sizeof(nox_mouse_state_t);
int nox_processing_input = 0;

nox_mouse_state_t nox_mouse = {0};
nox_mouse_state_t nox_mouse_prev = {0};
_DWORD nox_mouse_prev_seq = 0;
_DWORD nox_mouse_prev_seq_2 = 0;
mouse_pos_t nox_mouse_min = {0, 0};
mouse_pos_t nox_mouse_max = {default_win_width-1, default_win_height-1};
mouse_pos_t nox_mouse_prev_left = {0};
mouse_pos_t nox_mouse_prev_right = {0};
mouse_pos_t nox_mouse_prev_middle = {0};

obj_5D4594_754088_t* ptr_5D4594_754088 = 0;
int ptr_5D4594_754088_cnt = 0;

obj_5D4594_754088_t* ptr_5D4594_754092 = 0;
int ptr_5D4594_754092_cnt = 0;

int obj_5D4594_754104_switch = 0;

obj_5D4594_3799572_t* ptr_5D4594_3799572 = 0;
obj_5D4594_3799572_t obj_5D4594_3799660 = {0};
obj_5D4594_3799572_t obj_5D4594_3800716 = {0};

//----- (00427F30) --------------------------------------------------------
int __cdecl sub_427F30(int2* a1, int* a2)
{
    int v2; // esi
    int v3; // ecx
    int v4; // ebp
    int v5; // edi
    int v6; // ebx
    int v7; // esi
    int v9; // edx
    int v10; // eax
    int v12; // [esp+18h] [ebp-18h]
    int v13; // [esp+1Ch] [ebp-14h]

    v2 = a1->field_0;
    if ((double)a1->field_0 < 57.5)
        return 0;
    v3 = a1->field_4;
    if ((double)v3 < 57.5)
        return 0;
    if (v2 > 5888)
        return 0;
    if (v3 > 5888)
        return 0;
    v4 = v2 / 23;
    v5 = v3 / 23;
    v6 = a2[1] / 23;
    v12 = a2[2] / 23;
    v13 = a2[3] / 23;
    v7 = a2[4] / 23;
    v9 = a2[5] / 23;
    if (v3 / 23 < v6 || v5 > a2[7] / 23 || v4 < v12 || v4 > v7)
        return 0;
    if (v5 > v13)
    {
        if (v4 < v5 + v12 - v13)
            return 0;
        v10 = *a2 / 23;
    }
    else
    {
        v10 = *a2 / 23;
        if (v4 < v10 + v6 - v5)
            return 0;
    }
    if (v5 > v9)
    {
        if (v4 > v7 + v9 - v5)
            return 0;
    }
    else if (v4 > v5 + v10 - v6)
    {
        return 0;
    }
    return 1;
}

//----- (004280E0) --------------------------------------------------------
int __cdecl sub_4280E0(int2* a1, _DWORD* a2)
{
    int v2; // ebx
    int v3; // esi
    int v4; // ebp
    int v5; // eax
    int v6; // edi
    int v7; // edx
    int v9; // edx

    v2 = a2[2];
    v3 = a1->field_0;
    if (a1->field_0 < v2)
        return 0;
    v4 = a2[4];
    if (v3 > v4)
        return 0;
    v5 = a1->field_4;
    v6 = a2[1];
    if (v5 < v6 || v5 > a2[7])
        return 0;
    v7 = a2[3];
    if (v5 > v7)
    {
        if (v3 < v2 + v5 - v7)
            return 0;
        v4 = a2[4];
    }
    else if (v3 < *a2 + v6 - v5)
    {
        return 0;
    }
    v9 = a2[5];
    if (v5 > v9)
    {
        if (v3 > v4 + v9 - v5)
            return 0;
    }
    else if (v3 > * a2 + v5 - v6)
    {
        return 0;
    }
    return 1;
}

//----- (00428170) --------------------------------------------------------
int __cdecl sub_428170(_DWORD* a1, int4* a2)
{
    int v2; // edx
    int v3; // edx

    v2 = a1[1];
    if (v2 >= a1[7])
    {
        a2->field_C = v2;
        a2->field_4 = a1[7];
    }
    else
    {
        a2->field_4 = v2;
        a2->field_C = a1[7];
    }
    v3 = a1[2];
    if (v3 >= a1[4])
    {
        a2->field_8 = v3;
        a2->field_0 = a1[4];
    }
    else
    {
        a2->field_0 = v3;
        a2->field_8 = a1[4];
    }
    if (a2->field_0 < 0)
        a2->field_0 = 0;
    if (a2->field_4 < 0)
        a2->field_4 = 0;
    if (a2->field_8 >= 5888)
        a2->field_8 = 5887;
    if (a2->field_C >= 5888)
        a2->field_C = 5887;
    return 0;
}

//----- (004281F0) --------------------------------------------------------
int __cdecl sub_4281F0(int2* a1, int4* a2)
{
    int v2; // ecx
    bool result; // al

    result = 0;
    if (a1->field_0 >= a2->field_0 && a1->field_0 <= a2->field_8)
    {
        v2 = a1->field_4;
        if (v2 >= a2->field_4 && v2 <= a2->field_C)
            result = 1;
    }
    return result;
}

//----- (00428220) --------------------------------------------------------
BOOL __cdecl sub_428220(float2* a1, float4* a2)
{
    return a1->field_0 >= (double)a2->field_0
           && a1->field_0 <= (double)a2->field_8
           && a1->field_4 >= (double)a2->field_4
           && a1->field_4 <= (double)a2->field_C;
}

//----- (00428270) --------------------------------------------------------
void __cdecl sub_428270(shape* a1)
{
    shape* v1; // eax
    double v2; // st7
    double v3; // st7
    double v4; // st6
    double v5; // st7
    double v6; // st6
    float v7; // [esp+0h] [ebp-4h]
    float v8; // [esp+8h] [ebp+4h]

    v1 = a1;
    v8 = a1->field_C * 0.35354999;
    v2 = v1->field_10 * 0.35354999;
    v7 = v2;
    v3 = v2 - v8;
    v1->field_14 = v3;
    v4 = -v8 - v7;
    v1->field_18 = v4;
    v1->field_1C = v4;
    v1->field_20 = v3;
    v5 = v7 + v8;
    v1->field_24 = v5;
    v6 = v8 - v7;
    v1->field_28 = v6;
    v1->field_2C = v6;
    v1->field_30 = v5;
}

//----- (004282D0) --------------------------------------------------------
char* __cdecl sub_4282D0(char* a1, int a2)
{
    char* result; // eax

    result = strncpy((char*)& byte_5D4594[741316], a1, 0x10u);
    *(_DWORD*)& byte_5D4594[741304] = a2;
    return result;
}

//----- (004282F0) --------------------------------------------------------
void* __cdecl sub_4282F0(int a1, int a2, size_t a3)
{
    int v3; // ebx
    size_t v4; // edi
    unsigned int i; // esi
    size_t v6; // ebp
    void* result; // eax
    size_t v8; // ebp
    int v9; // edx
    int v10; // esi
    int v11; // eax
    int j; // [esp+14h] [ebp+4h]

    v3 = a1;
    v4 = 0;
    if (*(_DWORD*)(a1 + 608))
    {
        for (i = 0; i < *(int*)& byte_5D4594[741332]; ++i)
        {
            free(*(LPVOID*)(*(_DWORD*)(a1 + 608) + 4 * i));
            *(_DWORD*)(*(_DWORD*)(a1 + 608) + 4 * i) = 0;
        }
        free(*(LPVOID*)(a1 + 608));
        *(_DWORD*)(a1 + 608) = 0;
    }
    if (*(_DWORD*)(a1 + 612))
    {
        free(*(LPVOID*)(a1 + 612));
        *(_DWORD*)(a1 + 612) = 0;
    }
    if (*(_DWORD*)(a1 + 616))
    {
        free(*(LPVOID*)(a1 + 616));
        *(_DWORD*)(a1 + 616) = 0;
    }
    if (*(_DWORD*)(a1 + 620))
    {
        free(*(LPVOID*)(a1 + 620));
        *(_DWORD*)(a1 + 620) = 0;
    }
    if (*(_DWORD*)(a1 + 624))
    {
        free(*(LPVOID*)(a1 + 624));
        *(_DWORD*)(a1 + 624) = 0;
    }
    if (*(_DWORD*)(a1 + 628))
    {
        free(*(LPVOID*)(a1 + 628));
        *(_DWORD*)(a1 + 628) = 0;
    }
    if (*(_DWORD*)(a1 + 632))
    {
        free(*(LPVOID*)(a1 + 632));
        *(_DWORD*)(a1 + 632) = 0;
    }
    v6 = 4 * a3;
    *(_DWORD*)(a1 + 608) = nox_malloc(4 * a3);
    if (a3)
    {
        do
            *(_DWORD*)(*(_DWORD*)(a1 + 608) + 4 * v4++) = nox_malloc(0xAu);
        while (v4 < a3);
    }
    *(_DWORD*)(a1 + 612) = nox_malloc(v6);
    *(_DWORD*)(a1 + 616) = nox_malloc(v6);
    *(_DWORD*)(a1 + 620) = nox_malloc(a3);
    *(_DWORD*)(a1 + 624) = nox_malloc(a3);
    *(_DWORD*)(a1 + 628) = nox_malloc(v6);
    result = nox_malloc(a3);
    v8 = 0;
    *(_DWORD*)(a1 + 632) = result;
    if (a3)
    {
        v9 = a2 + 16;
        for (j = a2 + 16; ; v9 = j)
        {
            strcpy(*(char**)(*(_DWORD*)(v3 + 608) + 4 * v8), (const char*)(v9 - 16));
            *(_DWORD*)(*(_DWORD*)(v3 + 612) + 4 * v8) = *(_DWORD*)(v9 - 4);
            *(_DWORD*)(*(_DWORD*)(v3 + 616) + 4 * v8) = *(_DWORD*)v9;
            *(_BYTE*)(*(_DWORD*)(v3 + 620) + v8) = *(_BYTE*)(v9 + 4);
            *(_BYTE*)(*(_DWORD*)(v3 + 624) + v8) = *(_BYTE*)(v9 + 5);
            *(_BYTE*)(*(_DWORD*)(v3 + 632) + v8) = *(_BYTE*)(v9 + 12);
            v10 = *(_DWORD*)(v9 + 8);
            v11 = time(0) - v10;
            ++v8;
            *(_DWORD*)(j + 8) = v11;
            *(_DWORD*)(*(_DWORD*)(v3 + 628) + 4 * v8 - 4) = v11;
            result = (void*)a3;
            j += 32;
            if (v8 >= a3)
                break;
        }
        *(_WORD*)(v3 + 6) = a3;
        *(_DWORD*)& byte_5D4594[741332] = a3;
    }
    else
    {
        *(_WORD*)(a1 + 6) = 0;
        *(_DWORD*)& byte_5D4594[741332] = 0;
    }
    return result;
}

//----- (00428540) --------------------------------------------------------
unsigned int __cdecl sub_428540(int a1, char* a2, int a3)
{
    unsigned int result; // eax
    char* v4; // ecx
    char v5; // bl

    if (*(_DWORD*)(a1 + 636))
    {
        free(*(LPVOID*)(a1 + 636));
        *(_DWORD*)(a1 + 636) = 0;
    }
    *(_DWORD*)(a1 + 636) = nox_malloc(2 * a3);
    result = 0;
    if (2 * a3)
    {
        v4 = a2;
        do
        {
            v5 = *v4;
            v4 += 2;
            *(_BYTE*)(result + *(_DWORD*)(a1 + 636)) = v5;
            *(_BYTE*)(result + *(_DWORD*)(a1 + 636) + 1) = *(v4 - 1);
            result += 2;
        } while (result < 2 * a3);
        *(_DWORD*)& byte_5D4594[741308] = a3;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[741308] = a3;
    }
    return result;
}

//----- (004285C0) --------------------------------------------------------
char* __cdecl sub_4285C0(__int16* a1)
{
    char* result; // eax
    __int16* v2; // ebx
    void* v3; // eax
    unsigned int v4; // esi
    bool v5; // zf
    void* v6; // eax
    void* v7; // eax
    void* v8; // eax
    void* v9; // eax
    void* v10; // eax
    void* v11; // eax
    char* v12; // ebp
    int v13; // eax
    size_t v14; // [esp-24h] [ebp-30h]
    size_t v15; // [esp-20h] [ebp-2Ch]
    size_t v16; // [esp-18h] [ebp-24h]
    size_t v17; // [esp-14h] [ebp-20h]
    size_t v18; // [esp-Ch] [ebp-18h]
    size_t v19; // [esp-8h] [ebp-14h]
    int v20; // [esp+10h] [ebp+4h]

    result = (char*)sub_4E3CE0();
    v2 = a1;
    *a1 = (__int16)result;
    if ((__int16)result <= 0)
    {
        *(_DWORD*)& byte_5D4594[741332] = *a1;
    }
    else
    {
        v3 = nox_malloc(4 * (__int16)result);
        v4 = 0;
        v5 = *a1 == 0;
        *((_DWORD*)a1 + 134) = v3;
        if (!v5)
        {
            do
                *(_DWORD*)(*((_DWORD*)a1 + 134) + 4 * v4++) = nox_malloc(0xAu);
            while (v4 < *a1);
        }
        v6 = nox_malloc(4 * *a1);
        v19 = *a1;
        *((_DWORD*)a1 + 135) = v6;
        v7 = nox_malloc(v19);
        v18 = 4 * *a1;
        *((_DWORD*)a1 + 144) = v7;
        *((_DWORD*)a1 + 136) = nox_malloc(v18);
        v8 = nox_malloc(4 * *a1);
        v17 = 4 * *a1;
        *((_DWORD*)a1 + 137) = v8;
        v9 = nox_malloc(v17);
        v16 = 4 * *a1;
        *((_DWORD*)a1 + 138) = v9;
        *((_DWORD*)a1 + 139) = nox_malloc(v16);
        v10 = nox_malloc(4 * *a1);
        v15 = 4 * *a1;
        *((_DWORD*)a1 + 140) = v10;
        v11 = nox_malloc(v15);
        v14 = 4 * *a1;
        *((_DWORD*)a1 + 141) = v11;
        *((_DWORD*)a1 + 142) = nox_malloc(v14);
        *((_DWORD*)a1 + 143) = nox_malloc(4 * *a1);
        v20 = 0;
        result = sub_416EA0();
        v12 = result;
        if (result)
        {
            do
            {
                if (*((_DWORD*)v12 + 1198))
                {
                    strcpy(*(char**)(*((_DWORD*)v2 + 134) + 4 * v20), v12 + 2096);
                    v13 = sub_554200((unsigned __int8)v12[2064] + 1);
                    *(_DWORD*)(*((_DWORD*)v2 + 135) + 4 * v20) = htonl(v13);
                    *(_BYTE*)(v20 + *((_DWORD*)v2 + 144)) = v12[2251];
                    *(_DWORD*)(*((_DWORD*)v2 + 136) + 4 * v20) = *((_DWORD*)v12 + 1172);
                    *(_DWORD*)(*((_DWORD*)v2 + 137) + 4 * v20) = *((_DWORD*)v12 + 1172);
                    *(_DWORD*)(*((_DWORD*)v2 + 138) + 4 * v20) = *((_DWORD*)v12 + 1166);
                    *(_DWORD*)(*((_DWORD*)v2 + 139) + 4 * v20) = *((_DWORD*)v12 + 1165);
                    *(_DWORD*)(*((_DWORD*)v2 + 140) + 4 * v20) = *((_DWORD*)v12 + 1167);
                    *(_DWORD*)(*((_DWORD*)v2 + 141) + 4 * v20) = *((_DWORD*)v12 + 1168);
                    *(_DWORD*)(*((_DWORD*)v2 + 142) + 4 * v20) = *((_DWORD*)v12 + 1171);
                    *(_DWORD*)(*((_DWORD*)v2 + 143) + 4 * v20++) = sub_4D6540((unsigned __int8)v12[2064]);
                }
                v12 = sub_416EE0((int)v12);
            } while (v12);
            result = (char*)* v2;
            *(_DWORD*)& byte_5D4594[741332] = *v2;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[741332] = *v2;
        }
    }
    return result;
}

//----- (00428810) --------------------------------------------------------
BOOL __cdecl sub_428810(int a1, int a2)
{
    u_short* v2; // esi
    u_short* v3; // edi
    BOOL v4; // esi
    char v6[72]; // [esp+8h] [ebp-48h]

    v2 = sub_42ADA0(a1, a2, *(__int16*)& byte_5D4594[741308], (unsigned int*)& byte_5D4594[741312]);
    v3 = sub_42A8B0(v2, (int*)& byte_5D4594[741312]);
    free(v2);
    v4 = 1;
    if (sub_420360(v6, &a2))
        v4 = sub_40DEA0((int)v6, (__int16)a2, (int)v3, *(int*)& byte_5D4594[741312]);
    free(v3);
    return v4;
}

//----- (00428890) --------------------------------------------------------
BOOL __cdecl sub_428890(__int16* a1)
{
    u_short* v1; // esi
    u_short* v2; // edi
    BOOL v3; // esi
    char v5[72]; // [esp+8h] [ebp-48h]

    v1 = sub_42B810(a1, (unsigned int*)& byte_5D4594[741300]);
    v2 = sub_42A8B0(v1, (int*)& byte_5D4594[741300]);
    free(v1);
    v3 = 1;
    if (sub_420360(v5, &a1))
        v3 = sub_40DEA0((int)v5, (__int16)a1, (int)v2, *(int*)& byte_5D4594[741300]);
    free(v2);
    return v3;
}

//----- (00428910) --------------------------------------------------------
LPVOID __cdecl sub_428910(LPVOID* a1)
{
    unsigned int i; // edi
    LPVOID result; // eax

    if (a1[152])
    {
        for (i = 0; i < *(int*)& byte_5D4594[741332]; ++i)
        {
            free(*((LPVOID*)a1[152] + i));
            *((_DWORD*)a1[152] + i) = 0;
        }
        free(a1[152]);
        a1[152] = 0;
    }
    if (a1[153])
    {
        free(a1[153]);
        a1[153] = 0;
    }
    if (a1[154])
    {
        free(a1[154]);
        a1[154] = 0;
    }
    if (a1[155])
    {
        free(a1[155]);
        a1[155] = 0;
    }
    result = a1[159];
    if (result)
    {
        free(a1[159]);
        a1[159] = 0;
    }
    return result;
}

//----- (004289D0) --------------------------------------------------------
LPVOID __cdecl sub_4289D0(LPVOID* a1)
{
    unsigned int i; // edi
    LPVOID result; // eax

    if (a1[134])
    {
        for (i = 0; i < *(int*)& byte_5D4594[741332]; ++i)
        {
            free(*((LPVOID*)a1[134] + i));
            *((_DWORD*)a1[134] + i) = 0;
        }
        free(a1[134]);
        a1[134] = 0;
    }
    if (a1[135])
    {
        free(a1[135]);
        a1[135] = 0;
    }
    if (a1[144])
    {
        free(a1[144]);
        a1[144] = 0;
    }
    if (a1[136])
    {
        free(a1[136]);
        a1[136] = 0;
    }
    if (a1[137])
    {
        free(a1[137]);
        a1[137] = 0;
    }
    if (a1[138])
    {
        free(a1[138]);
        a1[138] = 0;
    }
    if (a1[139])
    {
        free(a1[139]);
        a1[139] = 0;
    }
    if (a1[140])
    {
        free(a1[140]);
        a1[140] = 0;
    }
    if (a1[141])
    {
        free(a1[141]);
        a1[141] = 0;
    }
    if (a1[142])
    {
        free(a1[142]);
        a1[142] = 0;
    }
    result = a1[143];
    if (result)
    {
        free(a1[143]);
        a1[143] = 0;
    }
    return result;
}

//----- (00428B30) --------------------------------------------------------
int sub_428B30()
{
    int v1; // eax
    unsigned __int16 v2; // bp
    int v3; // esi
    int v4; // eax
    int v5; // esi
    int i; // esi
    unsigned __int16 v7; // ax
    int v8; // [esp+4h] [ebp-110h]
    int v9; // [esp+8h] [ebp-10Ch]
    int v10; // [esp+Ch] [ebp-108h]
    int v11; // [esp+10h] [ebp-104h]
    char v12[256]; // [esp+14h] [ebp-100h]

    v11 = 1;
    sub_426AC0(&v11, 2u);
    if ((__int16)v11 > 1)
    return 0;
    sub_42BFB0();
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&v9, 2u);
        for (i = 0; (unsigned __int16)i < (unsigned __int16)v9; ++i)
        {
            sub_426AC0(&v10, 2u);
            sub_426AC0(&v8, 1u);
            sub_426AC0(v12, (unsigned __int8)v8);
            v12[(unsigned __int8)v8] = 0;
            if (!sub_40A5C0(2) || sub_40A5C0(1))
                v7 = sub_4E3AA0(v12);
            else
                v7 = sub_44CFC0(v12);
            sub_42C310(v7, v10);
        }
        return 1;
    }
    sub_42BFE0();
    LOWORD(v1) = sub_42C300();
    v9 = v1;
    sub_426AC0(&v9, 2u);
    v2 = 0;
    if (!sub_4E3AC0())
        return 1;
    v3 = 0;
    do
    {
        LOWORD(v4) = sub_42C2E0(v3);
        v10 = v4;
        if ((_WORD)v4)
        {
            sub_426AC0(&v10, 2u);
            v5 = sub_4E3B70(v3);
            LOBYTE(v8) = strlen(*(const char**)(v5 + 4));
            sub_426AC0(&v8, 1u);
            sub_426AC0(*(_BYTE * *)(v5 + 4), (unsigned __int8)v8);
        }
        v3 = ++v2;
    } while (v2 < (unsigned int)sub_4E3AC0());
    return 1;
}
// 428B85: variable 'v1' is possibly undefined
// 428BAB: variable 'v4' is possibly undefined
// 428B30: using guessed type char var_100[256];

//----- (00428CD0) --------------------------------------------------------
int __cdecl sub_428CD0(int a1)
{
    char* i; // eax
    char* v3; // esi
    unsigned int j; // edi
    char* k; // eax
    char* v6; // esi
    char* v7; // ebp
    char* v8; // ebp
    unsigned int v9; // esi
    unsigned __int8* v10; // esi
    _WORD* v11; // ebx
    _BYTE* v12; // eax
    char* v13; // edi
    int v14; // eax
    unsigned int v15; // ebp
    bool v16; // cc
    char* v17; // edi
    double v18; // st7
    double v19; // st7
    double v20; // st7
    double v21; // st7
    char* v22; // edi
    char* v23; // eax
    _BYTE* v24; // esi
    unsigned int v25; // [esp+10h] [ebp-2Ch]
    int v26; // [esp+14h] [ebp-28h]
    int v27; // [esp+18h] [ebp-24h]
    unsigned int v28; // [esp+1Ch] [ebp-20h]
    float v29[2]; // [esp+20h] [ebp-1Ch]
    int v30; // [esp+28h] [ebp-14h]
    int v31; // [esp+2Ch] [ebp-10h]
    char v32[12]; // [esp+30h] [ebp-Ch]

    v30 = 0;
    if (a1)
        return 1;
    v26 = 4;
    sub_426AC0(&v26, 2u);
    if ((__int16)v26 > 4)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&v25, 4u);
        v9 = 1;
        if (v25 >= 1)
        {
            do
            {
                sub_426AC0(&a1, 4u);
                sub_426AC0(v29, 8u);
                if (!sub_420D40(SLODWORD(v29[0]), SLODWORD(v29[1]), v9, a1))
                    return 0;
                if ((__int16)v26 < 3)
                    sub_426AC0(&v31, 4u);
            } while (++v9 <= v25);
        }
        sub_426AC0(&v25, 4u);
        v28 = 1;
        if (v25 >= 1)
        {
            do
            {
                v10 = sub_421230();
                if (!v10)
                    return 0;
                sub_426AC0(&v27, 1u);
                sub_426AC0(v10 + 4, (unsigned __int8)v27);
                v10[(unsigned __int8)v27 + 4] = 0;
                if ((__int16)v26 >= 3
                    || (sub_426AC0(&v31, 4u),
                        sub_426AC0(v32, 0xCu),
                        v10[104] = v32[0],
                        v10[105] = v32[4],
                        v10[106] = v32[8],
                        (__int16)v26 >= 3))
                {
                    sub_426AC0(&a1, 1u);
                    v10[104] = a1;
                    sub_426AC0(&a1, 1u);
                    v10[105] = a1;
                    sub_426AC0(&a1, 1u);
                    v10[106] = a1;
                }
                sub_426AC0(v10 + 130, 1u);
                v11 = v10 + 128;
                sub_426AC0(v10 + 128, 2u);
                v12 = nox_calloc(*((unsigned __int16*)v10 + 64), 4u);
                *((_DWORD*)v10 + 27) = v12;
                if (!v12)
                    return 0;
                sub_426AC0(v12, 4 * (unsigned __int16)* v11);
                sub_421040((int)v10);
                v13 = sub_421030(**((_DWORD * *)v10 + 27));
                *((_DWORD*)v10 + 22) = sub_419A70(*((float*)v13 + 1));
                *((_DWORD*)v10 + 23) = sub_419A70(*((float*)v13 + 2));
                *((_DWORD*)v10 + 24) = sub_419A70(*((float*)v13 + 1));
                v14 = sub_419A70(*((float*)v13 + 2));
                v15 = 1;
                v16 = *v11 <= 1u;
                *((_DWORD*)v10 + 25) = v14;
                if (!v16)
                {
                    do
                    {
                        v17 = sub_421030(*(_DWORD*)(*((_DWORD*)v10 + 27) + 4 * v15));
                        v18 = *((float*)v17 + 1);
                        v29[0] = *((float*)v17 + 1);
                        if (v18 >= (double) * ((int*)v10 + 22))
                        {
                            v19 = *((float*)v17 + 1);
                            v29[0] = *((float*)v17 + 1);
                            if (v19 > (double) * ((int*)v10 + 24))
                                * ((_DWORD*)v10 + 24) = sub_419A70(v29[0]);
                        }
                        else
                        {
                            *((_DWORD*)v10 + 22) = sub_419A70(v29[0]);
                        }
                        v20 = *((float*)v17 + 2);
                        v29[0] = *((float*)v17 + 2);
                        if (v20 >= (double) * ((int*)v10 + 23))
                        {
                            v21 = *((float*)v17 + 2);
                            v29[0] = *((float*)v17 + 2);
                            if (v21 > (double) * ((int*)v10 + 25))
                                * ((_DWORD*)v10 + 25) = sub_419A70(v29[0]);
                        }
                        else
                        {
                            *((_DWORD*)v10 + 23) = sub_419A70(v29[0]);
                        }
                        ++v15;
                    } while (v15 < (unsigned __int16)* v11);
                }
                if ((__int16)v26 >= 2)
                {
                    v22 = *(char**)v10;
                    sub_4F5580((int)(v10 + 112), *(char**)v10);
                    if (v22)
                        v23 = v22 + 128;
                    else
                        v23 = 0;
                    sub_4F5580((int)(v10 + 120), v23);
                }
                if ((__int16)v26 >= 4)
                {
                    v24 = v10 + 132;
                    sub_426AC0(v24, 4u);
                    if (*v24 & 1)
                        ++v30;
                }
            } while (++v28 <= v25);
        }
        sub_4D72D0(v30);
        return 1;
    }
    v25 = 0;
    for (i = sub_420CA0(); i; ++v25)
        i = sub_420CD0(i);
    sub_426AC0(&v25, 4u);
    v3 = sub_420CA0();
    for (j = 0; j < v25; ++j)
    {
        sub_426AC0(v3, 4u);
        sub_426AC0(v3 + 4, 8u);
        v3 = sub_420CD0(v3);
    }
    v25 = 0;
    for (k = sub_4210A0(); k; ++v25)
        k = sub_4210E0((int)k);
    sub_426AC0(&v25, 4u);
    v6 = sub_4210A0();
    v28 = 0;
    if (v25 <= 0)
        return 1;
    do
    {
        v7 = *(char**)v6;
        LOBYTE(v27) = strlen(v6 + 4);
        sub_426AC0(&v27, 1u);
        sub_426AC0(v6 + 4, (unsigned __int8)v27);
        LOBYTE(a1) = v6[104];
        sub_426AC0(&a1, 1u);
        LOBYTE(a1) = v6[105];
        sub_426AC0(&a1, 1u);
        LOBYTE(a1) = v6[106];
        sub_426AC0(&a1, 1u);
        sub_426AC0(v6 + 130, 1u);
        sub_426AC0(v6 + 128, 2u);
        sub_426AC0(*((_BYTE * *)v6 + 27), 4 * *((unsigned __int16*)v6 + 64));
        sub_4F5580((int)(v6 + 112), v7);
        if (v7)
            v8 = v7 + 128;
        else
            v8 = 0;
        sub_4F5580((int)(v6 + 120), v8);
        sub_426AC0(v6 + 132, 4u);
        v6 = sub_4210E0((int)v6);
        ++v28;
    } while (v28 < v25);
    return 1;
}

//----- (00429200) --------------------------------------------------------
int sub_429200()
{
    int result; // eax
    char* v1; // esi
    int v2; // [esp+0h] [ebp-10h]
    int v3[3]; // [esp+4h] [ebp-Ch]

    v2 = 1;
    sub_426AC0(&v2, 2u);
    if ((__int16)v2 < 1)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            sub_426AC0(&v3[0], 4u);
            sub_426AC0(&v3[1], 4u);
            sub_426AC0(&v3[2], 4u);
            sub_469B90(v3);
            if (sub_40A5C0(2097154))
                sub_4349C0(v3);
        }
        result = 1;
    }
    else
    {
        v1 = sub_469BB0();
        sub_426AC0(v1, 4u);
        sub_426AC0(v1 + 4, 4u);
        sub_426AC0(v1 + 8, 4u);
        result = 1;
    }
    return result;
}

//----- (004292C0) --------------------------------------------------------
int __cdecl sub_4292C0(_DWORD* a1)
{
    int result; // eax
    _DWORD* v2; // edi
    char* v3; // esi
    _DWORD* v4; // eax
    int v5; // [esp+4h] [ebp-20h]
    int v6; // [esp+8h] [ebp-1Ch]
    int2 v7;
    int4 v9; // [esp+14h] [ebp-10h]

    v5 = 2;
    sub_426AC0(&v5, 2u);
    if ((__int16)v5 > 2)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&byte_5D4594[741336], 2u);
        v6 = 0;
        if (*(_WORD*)& byte_5D4594[741336] > 0)
        {
            v2 = a1;
            do
            {
                sub_426AC0(&v7, 8u);
                if (a1)
                {
                    v3 = sub_426A70();
                    sub_428170(a1, &v9);
                    v7.field_0 += v9.field_0 / 23 - *(_DWORD*)v3;
                    v7.field_4 += v9.field_4 / 23 - *((_DWORD*)v3 + 1);
                }
                if (sub_40A5C0(0x400000))
                {
                    v4 = sub_5042F0(v7.field_0, v7.field_4);
                    if (v4)
                        v2 = (_DWORD*)* v4;
                }
                else
                {
                    v2 = (_DWORD*)sub_410580(v7.field_0, v7.field_4);
                }
                if (v2)
                {
                    *((_BYTE*)v2 + 4) |= 0x40u;
                    if ((__int16)v5 < 2)
                        * ((_BYTE*)v2 + 2) = 0;
                }
                ++v6;
            } while (v6 < *(__int16*)& byte_5D4594[741336]);
        }
        result = 1;
    }
    else
    {
        *(_WORD*)& byte_5D4594[741336] = 0;
        sub_410640((void(__cdecl*)(int, int))sub_429450, (int)a1);
        sub_426AC0(&byte_5D4594[741336], 2u);
        sub_410640((void(__cdecl*)(int, int))sub_4294B0, (int)a1);
        result = 1;
    }
    return result;
}

//----- (00429450) --------------------------------------------------------
void __cdecl sub_429450(_BYTE* a1, _DWORD* a2)
{
    int v2; // eax
    int2 v3; // [esp+4h] [ebp-8h]

    if (!a2
        || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2, sub_427F30(&v3, a2)))
    {
        if (a1[4] & 0x40)
            ++* (_WORD*)& byte_5D4594[741336];
    }
}

//----- (004294B0) --------------------------------------------------------
void __cdecl sub_4294B0(_BYTE* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // edx
    int2 v4; // [esp+4h] [ebp-8h]

    if (!a2
        || (v2 = (unsigned __int8)a1[6], v4.field_0 = 23 * (unsigned __int8)a1[5], v4.field_4 = 23 * v2, sub_427F30(&v4, a2)))
    {
        if (a1[4] & 0x40)
        {
            v3 = (unsigned __int8)a1[6];
            v4.field_0 = (unsigned __int8)a1[5];
            v4.field_4 = v3;
            sub_426AC0(&v4, 8u);
        }
    }
}

//----- (00429520) --------------------------------------------------------
void sub_429520()
{
    *(_DWORD*)& byte_5D4594[741344] = 0;
}

//----- (00429530) --------------------------------------------------------
int __cdecl sub_429530(_DWORD* a1)
{
    int result; // eax
    _DWORD* v2; // edi
    char* v3; // esi
    _DWORD* v4; // eax
    int v5; // [esp+4h] [ebp-20h]
    int v6; // [esp+8h] [ebp-1Ch]
    int2 v7;
    int4 v9; // [esp+14h] [ebp-10h]

    v5 = 1;
    sub_426AC0(&v5, 2u);
    if ((__int16)v5 > 1)
        return 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        sub_426AC0(&byte_5D4594[741340], 2u);
        v6 = 0;
        if (*(_WORD*)& byte_5D4594[741340] > 0)
        {
            v2 = a1;
            do
            {
                sub_426AC0(&v7, 8u);
                if (a1)
                {
                    v3 = sub_426A70();
                    sub_428170(a1, &v9);
                    v7.field_0 += v9.field_0 / 23 - *(_DWORD*)v3;
                    v7.field_4 += v9.field_4 / 23 - *((_DWORD*)v3 + 1);
                }
                if (sub_40A5C0(0x400000))
                {
                    v4 = sub_5042F0(v7.field_0, v7.field_4);
                    if (v4)
                        v2 = (_DWORD*)* v4;
                }
                else
                {
                    v2 = (_DWORD*)sub_410580(v7.field_0, v7.field_4);
                }
                if (v2)
                {
                    *((_BYTE*)v2 + 4) |= 8u;
                    *((_WORD*)v2 + 5) = *(_WORD*)& byte_5D4594[741344];
                    ++* (_DWORD*)& byte_5D4594[741344];
                    if (!sub_40A5C0(0x400000))
                        sub_410840((int)v2);
                }
                ++v6;
            } while (v6 < *(__int16*)& byte_5D4594[741340]);
        }
        result = 1;
    }
    else
    {
        *(_WORD*)& byte_5D4594[741340] = 0;
        sub_410640((void(__cdecl*)(int, int))sub_4296E0, (int)a1);
        sub_426AC0(&byte_5D4594[741340], 2u);
        sub_410640((void(__cdecl*)(int, int))sub_429740, (int)a1);
        result = 1;
    }
    return result;
}

//----- (004296E0) --------------------------------------------------------
void __cdecl sub_4296E0(_BYTE* a1, _DWORD* a2)
{
    int v2; // eax
    int2 v3; // [esp+4h] [ebp-8h]

    if (!a2
        || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2, sub_427F30(&v3, a2)))
    {
        if (a1[4] & 8)
            ++* (_WORD*)& byte_5D4594[741340];
    }
}

//----- (00429740) --------------------------------------------------------
void __cdecl sub_429740(_BYTE* a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // edx
    int2 v4; // [esp+4h] [ebp-8h]

    if (!a2
        || (v2 = (unsigned __int8)a1[6], v4.field_0 = 23 * (unsigned __int8)a1[5], v4.field_4 = 23 * v2, sub_427F30(&v4, a2)))
    {
        if (a1[4] & 8)
        {
            v3 = (unsigned __int8)a1[6];
            v4.field_0 = (unsigned __int8)a1[5];
            v4.field_4 = v3;
            sub_426AC0(&v4, 8u);
        }
    }
}

//----- (004297B0) --------------------------------------------------------
void sub_4297B0()
{
    *(_DWORD*)& byte_5D4594[741352] = 0;
}

//----- (004297C0) --------------------------------------------------------
int __cdecl sub_4297C0(_DWORD* a1)
{
    char* v2; // esi
    int* v3; // edi
    _BYTE* v4; // ebx
    char* v5; // ebp
    int* v6; // eax
    int v7; // eax
    char v8; // dl
    int v9; // [esp+4h] [ebp-1Ch]
    int v10; // [esp+8h] [ebp-18h]
    int v11; // [esp+Ch] [ebp-14h]
    int4 v12; // [esp+10h] [ebp-10h]

    v9 = 2;
    sub_426AC0(&v9, 2u);
    if ((__int16)v9 > 2)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[3803300])
    {
        *(_WORD*)& byte_5D4594[741348] = 0;
        sub_410640((void(__cdecl*)(int, int))sub_429A00, (int)a1);
        sub_426AC0(&byte_5D4594[741348], 2u);
        sub_410640((void(__cdecl*)(int, int))sub_429A60, (int)a1);
        return 1;
    }
    sub_426AC0(&byte_5D4594[741348], 2u);
    v11 = 0;
    if (*(_WORD*)& byte_5D4594[741348] > 0)
    {
        while (1)
        {
            v2 = (char*)nox_calloc(1u, 0x20u);
            v3 = (int*)(v2 + 4);
            sub_426AC0(v2 + 4, 8u);
            sub_426AC0(v2 + 16, 4u);
            sub_426AC0(v2 + 20, 1u);
            v4 = v2 + 21;
            v2[21] = 0;
            if ((__int16)v9 >= 2)
            {
                sub_426AC0(v2 + 21, 1u);
                sub_426AC0(v2 + 22, 1u);
                sub_426AC0(v2 + 24, 4u);
                sub_426AC0(v2 + 28, 4u);
            }
            if (a1)
            {
                v5 = sub_426A70();
                sub_428170(a1, &v12);
                *v3 += v12.field_0 / 23 - *(_DWORD*)v5;
                *((_DWORD*)v2 + 2) += v12.field_4 / 23 - *((_DWORD*)v5 + 1);
            }
            if (!sub_40A5C0(0x400000))
                break;
            v6 = sub_5042F0(*v3, *((_DWORD*)v2 + 2));
            if (!v6)
                goto LABEL_14;
            v7 = *v6;
            v10 = v7;
            LABEL_15:
            if (v7)
            {
                v8 = *(_BYTE*)(v7 + 4);
                *(_DWORD*)(v7 + 28) = v2;
                *(_BYTE*)(v7 + 4) = v8 | 4;
                *(_WORD*)(v7 + 10) = *(_WORD*)& byte_5D4594[741352];
                ++* (_DWORD*)& byte_5D4594[741352];
                *((_DWORD*)v2 + 3) = v7;
                if (!*v4)
                {
                    if (v2[20] & 8)
                    {
                        *((_DWORD*)v2 + 7) = -1;
                        *v4 = 3;
                        v2[22] = 23;
                    }
                    else
                    {
                        *((_DWORD*)v2 + 7) = 0;
                        *v4 = 1;
                        v2[22] = 0;
                    }
                }
                if (!sub_40A5C0(0x400000))
                    sub_410760(v2);
            }
            if (++v11 >= *(__int16*)& byte_5D4594[741348])
                return 1;
        }
        v10 = sub_410580(*v3, *((_DWORD*)v2 + 2));
        LABEL_14:
        v7 = v10;
        goto LABEL_15;
    }
    return 1;
}

//----- (00429A00) --------------------------------------------------------
void __cdecl sub_429A00(_BYTE* a1, _DWORD* a2)
{
    int v2; // eax
    int2 v3; // [esp+4h] [ebp-8h]

    if (!a2
        || (v2 = (unsigned __int8)a1[6], v3.field_0 = 23 * (unsigned __int8)a1[5], v3.field_4 = 23 * v2, sub_427F30(&v3, a2)))
    {
        if (a1[4] & 4)
            ++* (_WORD*)& byte_5D4594[741348];
    }
}

//----- (00429A60) --------------------------------------------------------
void __cdecl sub_429A60(int a1, _DWORD* a2)
{
    int v2; // eax
    int v3; // edx
    _BYTE* v4; // esi
    int2 v5; // [esp+4h] [ebp-8h]

    if (!a2
        || (v2 = *(unsigned __int8*)(a1 + 6),
            v5.field_0 = 23 * *(unsigned __int8*)(a1 + 5),
            v5.field_4 = 23 * v2,
            sub_427F30(&v5, a2)))
    {
        if (*(_BYTE*)(a1 + 4) & 4)
        {
            v3 = *(unsigned __int8*)(a1 + 6);
            v4 = *(_BYTE * *)(a1 + 28);
            v5.field_0 = *(unsigned __int8*)(a1 + 5);
            v5.field_4 = v3;
            sub_426AC0(&v5, 8u);
            sub_426AC0(v4 + 16, 4u);
            sub_426AC0(v4 + 20, 1u);
            sub_426AC0(v4 + 21, 1u);
            sub_426AC0(v4 + 22, 1u);
            sub_426AC0(v4 + 24, 4u);
            sub_426AC0(v4 + 28, 4u);
        }
    }
}

//----- (00429B20) --------------------------------------------------------
int __cdecl sub_429B20(_DWORD* a1)
{
    _DWORD* v2; // ebp
    int v3; // esi
    int v5; // edx
    int v6; // edx
    int v7; // ecx
    int v8; // eax
    int v9; // edi
    _BYTE* v10; // eax
    _BYTE* v11; // esi
    struc_19* v12; // eax
    int v13; // eax
    int v14; // eax
    char v15; // bl
    char v16; // bl
    unsigned __int8* v17; // esi
    int v18; // edi
    unsigned __int8* v19; // eax
    unsigned __int8* v20; // edi
    unsigned __int8* v21; // ebx
    char v22; // [esp+2h] [ebp-3Ah]
    char v23; // [esp+3h] [ebp-39h]
    int v24; // [esp+4h] [ebp-38h]
    int v25; // [esp+8h] [ebp-34h]
    int v26; // [esp+Ch] [ebp-30h]
    int v27; // [esp+10h] [ebp-2Ch]
    int v28; // [esp+14h] [ebp-28h]
    int v29; // [esp+18h] [ebp-24h]
    int v30; // [esp+1Ch] [ebp-20h]
    int v31; // [esp+20h] [ebp-1Ch]
    int2 v32; // [esp+24h] [ebp-18h]
    int4 v33; // [esp+2Ch] [ebp-10h]

    v31 = sub_426A30();
    if (!byte_5D4594[741372])
        byte_5D4594[741372] = sub_410D60("MagicWallSystemUseOnly");
    sub_4297B0();
    sub_429520();
    v28 = 7;
    sub_426AC0(&v28, 2u);
    if ((__int16)v28 > 7)
        return 0;
    if ((__int16)v28 < 6)
        return sub_42A150(v28, a1);
    v2 = a1;
    if (!*(_DWORD*)& byte_5D4594[3803300])
    {
        if (a1)
        {
            sub_428170(a1, &v33);
            *(_DWORD*)& byte_5D4594[741360] = v33.field_0 / 23;
            v3 = v33.field_8 / 23;
            *(_DWORD*)& byte_5D4594[741356] = v33.field_8 / 23;
            *(_DWORD*)& byte_5D4594[741368] = v33.field_4 / 23;
            v5 = v33.field_C / 23;
            *(_DWORD*)& byte_5D4594[741364] = v5;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[741368] = 256;
            *(_DWORD*)& byte_5D4594[741360] = 256;
            *(_DWORD*)& byte_5D4594[741364] = 0;
            *(_DWORD*)& byte_5D4594[741356] = 0;
            sub_410640((void(__cdecl*)(int, int))sub_42A0F0, 0);
            v3 = *(_DWORD*)& byte_5D4594[741356];
            v5 = *(_DWORD*)& byte_5D4594[741364];
        }
        v25 = v3 - *(_DWORD*)& byte_5D4594[741360] + 1;
        v27 = v5 - *(_DWORD*)& byte_5D4594[741368] + 1;
    }
    sub_426AC0(&byte_5D4594[741360], 4u);
    sub_426AC0(&byte_5D4594[741368], 4u);
    sub_426AC0(&v25, 4u);
    sub_426AC0(&v27, 4u);
    v26 = 0;
    v29 = 0;
    if (*(_DWORD*)& byte_5D4594[3803300])
    {
        if (v2)
        {
            sub_428170(v2, &v33);
            v13 = v33.field_0 / 23 - *(_DWORD*)& byte_5D4594[741360];
            *(_DWORD*)& byte_5D4594[741360] = v33.field_0 / 23;
            v29 = v13;
            v14 = v33.field_4 / 23 - *(_DWORD*)& byte_5D4594[741368];
            *(_DWORD*)& byte_5D4594[741368] = v33.field_4 / 23;
            v26 = v14;
        }
        sub_426AC0(&v22, 1u);
        v15 = v22;
        if (v22 == -1)
            return 1;
        while (1)
        {
            sub_426AC0(&a1, 1u);
            LOBYTE(v30) = v29 + v15;
            LOBYTE(a1) = v26 + (_BYTE)a1;
            sub_426AC0(&v24, 1u);
            v16 = (unsigned __int8)v24 >> 7;
            LOBYTE(v24) = v24 & 0x7F;
            if (sub_40A5C0(0x400000))
            {
                v17 = (unsigned __int8*)* sub_504290(v30, (char)a1);
            }
            else
            {
                v18 = (unsigned __int8)v30;
                v19 = (unsigned __int8*)sub_410580((unsigned __int8)v30, (unsigned __int8)a1);
                v17 = v19;
                if (v19)
                {
                    if (v31 & 1)
                        * v19 = sub_42A6C0(*v19, v24);
                    else
                        *v19 = v24;
                    goto LABEL_46;
                }
                v17 = (unsigned __int8*)sub_410250(v18, (unsigned __int8)a1);
                if (!v17)
                    return 0;
            }
            *v17 = v24;
            LABEL_46:
            if (v16)
                v17[4] |= 0x80u;
            v20 = v17 + 1;
            sub_426AC0(v17 + 1, 1u);
            v21 = v17 + 2;
            sub_426AC0(v17 + 2, 1u);
            if (v31 & 1 && *v21 >= sub_410DD0(*v20, *v17, 0))
                * v21 = 0;
            v17[7] = sub_410E20(*v20);
            if ((_WORD)v28 == 6)
            {
                sub_426AC0(&v24, 1u);
                v17[8] = 1;
                *((_DWORD*)v17 + 3) = 0;
            }
            else
            {
                sub_426AC0(v17 + 8, 1u);
                sub_426AC0(&v24, 1u);
                *((_DWORD*)v17 + 3) = (unsigned __int8)v24;
            }
            sub_426AC0(&v22, 1u);
            v15 = v22;
            if (v22 == -1)
                return 1;
        }
    }
    v6 = *(_DWORD*)& byte_5D4594[741368];
    v26 = *(_DWORD*)& byte_5D4594[741368];
    if (*(_DWORD*)& byte_5D4594[741368] <= *(int*)& byte_5D4594[741368] + v27)
    {
        v7 = v25;
        v8 = *(_DWORD*)& byte_5D4594[741360];
        do
        {
            v9 = v8;
            v29 = v8;
            if (v8 <= v8 + v7)
            {
                do
                {
                    v10 = (_BYTE*)sub_410580(v9, v26);
                    v11 = v10;
                    if (v10)
                    {
                        if (v10[1] != byte_5D4594[741372])
                        {
                            if (!v2
                                || (v32.field_0 = 23 * (unsigned __int8)v10[5],
                                    v32.field_4 = 23 * (unsigned __int8)v10[6],
                                    sub_427F30(&v32, v2)))
                            {
                                sub_426AC0(v11 + 5, 1u);
                                sub_426AC0(v11 + 6, 1u);
                                if ((int)v11[4] >= 0)
                                    LOBYTE(v24) = *v11;
                                else
                                    LOBYTE(v24) = *v11 | 0x80;
                                sub_426AC0(&v24, 1u);
                                sub_426AC0(v11 + 1, 1u);
                                sub_426AC0(v11 + 2, 1u);
                                v32.field_0 = 23 * (unsigned __int8)v11[5] + 11;
                                v32.field_4 = 23 * (unsigned __int8)v11[6] + 11;
                                v12 = sub_4217B0(&v32, 0);
                                if (v12 || (v12 = (struc_19*)sub_421990(&v32, 10.0, 0)) != 0)
                                    v23 = BYTE2(v12->field_0[32]);
                                else
                                    v23 = 100;
                                sub_426AC0(&v23, 1u);
                                if (sub_40A5C0(0x200000))
                                    LOBYTE(v24) = 0;
                                else
                                    LOBYTE(v24) = v11[12];
                                sub_426AC0(&v24, 1u);
                                v2 = a1;
                                v9 = v29;
                            }
                        }
                    }
                    v8 = *(_DWORD*)& byte_5D4594[741360];
                    v7 = v25;
                    v29 = ++v9;
                } while (v9 <= *(int*)& byte_5D4594[741360] + v25);
                v6 = *(_DWORD*)& byte_5D4594[741368];
            }
            ++v26;
        } while (v26 <= v6 + v27);
    }
    v22 = -1;
    sub_426AC0(&v22, 1u);
    return 1;
}

//----- (0042A0F0) --------------------------------------------------------
int __cdecl sub_42A0F0(int a1)
{
    int result; // eax

    if ((int) * (unsigned __int8*)(a1 + 5) < *(int*)& byte_5D4594[741360])
    * (_DWORD*)& byte_5D4594[741360] = *(unsigned __int8*)(a1 + 5);
    if ((int) * (unsigned __int8*)(a1 + 5) > * (int*)& byte_5D4594[741356])
    * (_DWORD*)& byte_5D4594[741356] = *(unsigned __int8*)(a1 + 5);
    if ((int) * (unsigned __int8*)(a1 + 6) < *(int*)& byte_5D4594[741368])
    * (_DWORD*)& byte_5D4594[741368] = *(unsigned __int8*)(a1 + 6);
    result = *(unsigned __int8*)(a1 + 6);
    if (result > * (int*)& byte_5D4594[741364])
        * (_DWORD*)& byte_5D4594[741364] = *(unsigned __int8*)(a1 + 6);
    return result;
}

//----- (0042A150) --------------------------------------------------------
int __cdecl sub_42A150(__int16 a1, _DWORD* a2)
{
    int v2; // eax
    _DWORD* v3; // ebx
    int v4; // edi
    int v5; // esi
    int v6; // edx
    int v7; // edx
    int v8; // ebp
    int v9; // ecx
    int v10; // eax
    int v11; // edi
    int v12; // eax
    _BYTE* v13; // esi
    struc_19* v14; // eax
    int v16; // eax
    int v17; // ebp
    unsigned __int8 v18; // bl
    char v19; // bl
    unsigned __int8** v20; // eax
    unsigned __int8* v21; // esi
    unsigned __int8* v22; // eax
    unsigned __int8 v23; // al
    __int16 v24; // bx
    unsigned __int8* v25; // edi
    char v26; // [esp+13h] [ebp-2Dh]
    int v27; // [esp+14h] [ebp-2Ch]
    int v28; // [esp+18h] [ebp-28h]
    int v29; // [esp+1Ch] [ebp-24h]
    int v30; // [esp+20h] [ebp-20h]
    int v31; // [esp+24h] [ebp-1Ch]
    int2 v32; // [esp+28h] [ebp-18h]
    int4 v33; // [esp+30h] [ebp-10h]

    v2 = sub_426A30();
    v3 = a2;
    v30 = v2;
    v4 = 0;
    if (!*(_DWORD*)& byte_5D4594[3803300])
    {
        if (a2)
        {
            sub_428170(a2, &v33);
            *(_DWORD*)& byte_5D4594[741360] = v33.field_0 / 23;
            v5 = v33.field_8 / 23;
            *(_DWORD*)& byte_5D4594[741356] = v33.field_8 / 23;
            *(_DWORD*)& byte_5D4594[741368] = v33.field_4 / 23;
            v6 = v33.field_C / 23;
            *(_DWORD*)& byte_5D4594[741364] = v33.field_C / 23;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[741368] = 256;
            *(_DWORD*)& byte_5D4594[741360] = 256;
            *(_DWORD*)& byte_5D4594[741364] = 0;
            *(_DWORD*)& byte_5D4594[741356] = 0;
            sub_410640((void(__cdecl*)(int, int))sub_42A0F0, 0);
            v5 = *(_DWORD*)& byte_5D4594[741356];
            v6 = *(_DWORD*)& byte_5D4594[741364];
        }
        v28 = v5 - *(_DWORD*)& byte_5D4594[741360] + 1;
        v29 = v6 - *(_DWORD*)& byte_5D4594[741368] + 1;
    }
    sub_426AC0(&byte_5D4594[741360], 4u);
    sub_426AC0(&byte_5D4594[741368], 4u);
    sub_426AC0(&v28, 4u);
    sub_426AC0(&v29, 4u);
    if (!*(_DWORD*)& byte_5D4594[3803300])
    {
        v7 = *(_DWORD*)& byte_5D4594[741368];
        v8 = *(_DWORD*)& byte_5D4594[741368];
        if (*(_DWORD*)& byte_5D4594[741368] > * (int*)& byte_5D4594[741368] + v29)
            return 1;
        v9 = v28;
        v10 = *(_DWORD*)& byte_5D4594[741360];
        while (1)
        {
            v11 = v10;
            if (v10 > v10 + v9)
                goto LABEL_27;
            do
            {
                v12 = sub_410580(v11, v8);
                v13 = (_BYTE*)v12;
                if (v3)
                {
                    if (!v12)
                        goto LABEL_15;
                    v32.field_0 = 23 * *(unsigned __int8*)(v12 + 5);
                    v32.field_4 = 23 * *(unsigned __int8*)(v12 + 6);
                    if (!sub_427F30(&v32, v3))
                    {
                        v13 = 0;
                        LOBYTE(v27) = -1;
                        goto LABEL_19;
                    }
                }
                if (!v13)
                {
                    LABEL_15:
                    LOBYTE(v27) = -1;
                    goto LABEL_19;
                }
                if ((int)v13[4] >= 0)
                    LOBYTE(v27) = *v13;
                else
                    LOBYTE(v27) = *v13 | 0x80;
                LABEL_19:
                sub_426AC0(&v27, 1u);
                if ((_BYTE)v27 != (_BYTE)-1)
                {
                    sub_426AC0(v13 + 1, 1u);
                    sub_426AC0(v13 + 2, 1u);
                    v32.field_0 = 23 * (unsigned __int8)v13[5] + 11;
                    v32.field_4 = 23 * (unsigned __int8)v13[6] + 11;
                    v14 = sub_4217B0(&v32, 0);
                    if (v14 || (v14 = (struc_19*)sub_421990(&v32, 10.0, 0)) != 0)
                        v26 = BYTE2(v14->field_0[32]);
                    else
                        v26 = 1;
                    sub_426AC0(&v26, 1u);
                    LOBYTE(a1) = v13[12];
                    sub_426AC0(&a1, 1u);
                }
                v10 = *(_DWORD*)& byte_5D4594[741360];
                v9 = v28;
                ++v11;
            } while (v11 <= *(int*)& byte_5D4594[741360] + v28);
            v7 = *(_DWORD*)& byte_5D4594[741368];
            LABEL_27:
            if (++v8 > v7 + v29)
                return 1;
        }
    }
    if (v3)
    {
        sub_428170(v3, &v33);
        *(_DWORD*)& byte_5D4594[741360] = v33.field_0 / 23;
        *(_DWORD*)& byte_5D4594[741368] = v33.field_4 / 23;
    }
    v31 = 0;
    if (v29 < 0)
        return 1;
    v16 = v28;
    while (1)
    {
        v17 = 0;
        if (v16 >= 0)
            break;
        LABEL_60:
        v31 = ++v4;
        if (v4 > v29)
            return 1;
    }
    while (1)
    {
        sub_426AC0(&v27, 1u);
        if ((_BYTE)v27 != (_BYTE)-1)
            break;
        LABEL_59:
        v16 = v28;
        if (++v17 > v28)
            goto LABEL_60;
    }
    v18 = v27;
    LOBYTE(v27) = v27 & 0x7F;
    v19 = v18 >> 7;
    if (sub_40A5C0(0x400000))
    {
        v20 = (unsigned __int8**)sub_504290(v17 + byte_5D4594[741360], v4 + byte_5D4594[741368]);
        v21 = *v20;
        **v20 = v27;
        LABEL_43:
        if (v19)
            v21[4] |= 0x80u;
        v24 = a1;
        if (a1 < 2)
        {
            v21[1] = 0;
            v21[7] = sub_410E20(0);
            v21[8] = 1;
        }
        else
        {
            v25 = v21 + 1;
            sub_426AC0(v21 + 1, 1u);
            if (v24 >= 3)
                sub_426AC0(v21 + 2, 1u);
            else
                sub_42A650(v21);
            if (v30 & 1 && v21[2] >= sub_410DD0(*v25, *v21, 0))
                v21[2] = 0;
            v21[7] = sub_410E20(*v25);
            if (v24 < 4)
                v21[8] = 1;
            else
                sub_426AC0(v21 + 8, 1u);
            LOBYTE(a2) = 0;
            if (v24 >= 5)
                sub_426AC0(&a2, 1u);
            v4 = v31;
            *((_DWORD*)v21 + 3) = (unsigned __int8)a2;
        }
        goto LABEL_59;
    }
    v22 = (unsigned __int8*)sub_410580(v17 + *(_DWORD*)& byte_5D4594[741360], v4 + *(_DWORD*)& byte_5D4594[741368]);
    v21 = v22;
    if (v22)
    {
        if (v30 & 1)
        {
            v23 = sub_42A6C0(*v22, v27);
            LABEL_42:
            *v21 = v23;
            goto LABEL_43;
        }
        LABEL_41:
        v23 = v27;
        goto LABEL_42;
    }
    v21 = (unsigned __int8*)sub_410250(v17 + *(_DWORD*)& byte_5D4594[741360], v4 + *(_DWORD*)& byte_5D4594[741368]);
    if (v21)
        goto LABEL_41;
    return 0;
}

//----- (0042A650) --------------------------------------------------------
int __cdecl sub_42A650(unsigned __int8* a1)
{
unsigned __int8 v1; // cl
int result; // eax

v1 = *a1;
a1[2] = 0;
if (!v1)
a1[2] = a1[5] % 3;
if (v1 == 1)
a1[2] = a1[5] % 3;
result = sub_46A3B0(a1[1], v1, a1[2], (a1[4] >> 2) & 2);
if (!result)
a1[2] = 0;
return result;
}

//----- (0042A6C0) --------------------------------------------------------
unsigned __int8 __cdecl sub_42A6C0(unsigned __int8 a1, unsigned __int8 a2)
{
    return byte_587000[13 * a1 + 71276 + a2];
}

//----- (0042A6E0) --------------------------------------------------------
int sub_42A6E0()
{
    __int16 v0; // ax
    int v2; // [esp+0h] [ebp-8h]
    int v3; // [esp+4h] [ebp-4h]

    v3 = 3;
    sub_426AC0(&v3, 2u);
    v0 = v3;
    if ((__int16)v3 > 3)
        return 0;
    if ((__int16)v3 >= 1)
    {
        sub_426AC0(&byte_5D4594[3801836], 0x40u);
        sub_426AC0(&byte_5D4594[3801900], 0x200u);
        sub_426AC0(&byte_5D4594[3802412], 0x10u);
        sub_426AC0(&byte_5D4594[3802428], 0x40u);
        sub_426AC0(&byte_5D4594[3802492], 0x40u);
        sub_426AC0(&byte_5D4594[3802556], 0x80u);
        sub_426AC0(&byte_5D4594[3802684], 0x80u);
        sub_426AC0(&byte_5D4594[3802812], 0x100u);
        sub_426AC0(&byte_5D4594[3803068], 0x80u);
        sub_426AC0(&byte_5D4594[3803196], 0x20u);
        sub_426AC0(&byte_5D4594[3803228], 4u);
        v0 = v3;
        if ((_WORD)v3 == 2)
        {
            sub_426AC0(&byte_5D4594[3803232], 1u);
            sub_426AC0(&byte_5D4594[3803233], 1u);
            v0 = v3;
        }
        else if (*(_DWORD*)& byte_5D4594[3803300] == 1)
        {
            byte_5D4594[3803232] = 2;
            byte_5D4594[3803233] = 16;
        }
    }
    if (v0 < 3)
    {
        byte_5D4594[3803234] = byte_5D4594[741376];
        byte_5D4594[3803266] = byte_5D4594[741380];
    }
    else
    {
        LOBYTE(v2) = strlen((const char*)& byte_5D4594[3803234]);
        sub_426AC0(&v2, 1u);
        sub_426AC0(&byte_5D4594[3803234], (unsigned __int8)v2);
        byte_5D4594[(unsigned __int8)v2 + 3803234] = 0;
        LOBYTE(v2) = strlen((const char*)& byte_5D4594[3803266]);
        sub_426AC0(&v2, 1u);
        sub_426AC0(&byte_5D4594[3803266], (unsigned __int8)v2);
        byte_5D4594[(unsigned __int8)v2 + 3803266] = 0;
    }
    return 1;
}

//----- (0042A8B0) --------------------------------------------------------
u_short* __cdecl sub_42A8B0(_BYTE* a1, int* a2)
{
    int v2; // eax
    _BYTE* v3; // esi
    _BYTE* v4; // ebx
    u_short* result; // eax
    int v6; // esi
    void* v7; // eax
    int v8; // eax
    u_short* v9; // esi
    unsigned __int8 v10[12]; // [esp+Ch] [ebp-Ch]

    *(_WORD*)v10 = 0;
    *(_WORD*)& v10[2] = 0;
    v2 = *a2;
    *(_DWORD*)& v10[4] = 0;
    v3 = nox_malloc(2 * v2);
    sub_42A970(a1, v3, a2);
    v4 = sub_42AC50(v3, (size_t*)a2);
    if (v3)
        free(v3);
    if (v4)
    {
        v6 = *a2;
        v7 = operator_new(0x10u);
        if (v7)
            v8 = sub_42C910((int)v7, (char*)& byte_587000[71480], v4, v6);
        else
            v8 = 0;
        sub_42C360(v10, v8);
        free(v4);
        v9 = sub_42C480(v10, (unsigned int*)a2);
        sub_42C330(v10);
        result = v9;
    }
    else
    {
        sub_42C330(v10);
        result = 0;
    }
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042A970) --------------------------------------------------------
int __cdecl sub_42A970(_BYTE* a1, _BYTE* a2, int* a3)
{
    int v3; // eax
    char v4; // bl
    int v5; // edx
    int v6; // ecx
    int v7; // esi
    int v8; // eax
    int* v9; // edx
    _BYTE* v10; // ebp
    int v11; // edi
    char v12; // cl
    int result; // eax
    int v14; // edx
    int v15; // eax
    int v16; // ebp
    char v17; // [esp+13h] [ebp-405h]
    unsigned __int8 v18; // [esp+14h] [ebp-404h]
    int v19[256]; // [esp+18h] [ebp-400h]

    v3 = 0;
    v4 = 1;
    memset(v19, 0, sizeof(v19));
    v18 = 1;
    v5 = *a3;
    if (*a3 > 0)
    {
        do
        {
            v6 = (unsigned __int8)a1[v3++];
            ++v19[v6];
        } while (v3 < v5);
    }
    v7 = v19[0];
    v17 = 0;
    v8 = 0;
    v9 = v19;
    while (*v9)
    {
        if (*v9 < v7)
        {
            v7 = *v9;
            v17 = v8;
        }
        ++v8;
        ++v9;
        if (v8 >= 256)
            goto LABEL_10;
    }
    v17 = v8;
    LABEL_10:
    v10 = a1;
    v11 = 1;
    *a2 = v17;
    v12 = *a1;
    result = 1;
    v14 = *a3;
    if ((int)* a3 < 1)
    {
        *a3 = 1;
    }
    else
    {
        do
        {
            if (v10[v11] != v12 || v11 >= v14)
            {
                if ((unsigned __int8)v4 <= 3u)
                {
                    if ((int)v18 > 0)
                    {
                        v16 = v18;
                        do
                        {
                            if (v12 == v17)
                                a2[result++] = v12;
                            a2[result++] = v12;
                            --v16;
                        } while (v16);
                    }
                }
                else
                {
                    a2[result] = v17;
                    v15 = result + 1;
                    a2[v15++] = v4;
                    a2[v15] = v12;
                    result = v15 + 1;
                }
                v10 = a1;
                v4 = 1;
                v12 = a1[v11];
            }
            else
            {
                ++v4;
            }
            ++v11;
            v18 = v4;
            v14 = *a3;
        } while (v11 <= *a3);
        *a3 = result;
    }
    return result;
}
// 42A970: using guessed type int var_400[256];

//----- (0042AAA0) --------------------------------------------------------
double __cdecl sub_42AAA0(int* a1)
{
    int v1; // eax
    int v2; // esi
    int v3; // edi
    int v4; // ecx
    int v5; // edi
    int v6; // esi
    unsigned __int8* v7; // ecx
    int v8; // eax
    int v9; // edx
    int v10; // ecx
    int v11; // eax
    int v13; // [esp+Ch] [ebp+4h]

    if ((int)* a1 < 0 || !*(_DWORD*)& byte_5D4594[741656])
    {
        *(_DWORD*)& byte_5D4594[741656] = 1;
        v1 = *a1;
        if ((int)* a1 < 0)
            v1 = -v1;
        v2 = 1;
        v3 = 21;
        v4 = (161803398 - v1) % 1000000000;
        *(_DWORD*)& byte_5D4594[741604] = (161803398 - v1) % 1000000000;
        do
        {
            *(_DWORD*)& byte_5D4594[4 * (v3 % 55) + 741384] = v2;
            v2 = v4 - v2 + (v4 - v2 < 0 ? 0x3B9ACA00 : 0);
            v4 = *(_DWORD*)& byte_5D4594[4 * (v3 % 55) + 741384];
            v3 += 21;
        } while (v3 <= 1134);
        v5 = 4;
        do
        {
            v6 = 1;
            v7 = &byte_5D4594[741388];
            do
            {
                v8 = *(_DWORD*)v7 - *(_DWORD*)& byte_5D4594[4 * ((v6 + 30) % 55) + 741388];
                *(_DWORD*)v7 = v8;
                if (v8 < 0)
                    * (_DWORD*)v7 = v8 + 1000000000;
                v7 += 4;
                ++v6;
            } while ((int)v7 <= (int)& byte_5D4594[741604]);
            --v5;
        } while (v5);
        *(_DWORD*)& byte_5D4594[741648] = 0;
        *(_DWORD*)& byte_5D4594[741652] = 31;
        *a1 = 1;
    }
    v9 = ++ * (_DWORD*)& byte_5D4594[741648];
    if (*(_DWORD*)& byte_5D4594[741648] == 56)
    {
        v9 = 1;
        *(_DWORD*)& byte_5D4594[741648] = 1;
    }
    v10 = ++ * (_DWORD*)& byte_5D4594[741652];
    if (*(_DWORD*)& byte_5D4594[741652] == 56)
    {
        v10 = 1;
        *(_DWORD*)& byte_5D4594[741652] = 1;
    }
    v11 = *(_DWORD*)& byte_5D4594[4 * v9 + 741384] - *(_DWORD*)& byte_5D4594[4 * v10 + 741384];
    v13 = v11;
    if (v11 < 0)
    {
        v11 += 1000000000;
        v13 = v11;
    }
    *(_DWORD*)& byte_5D4594[4 * v9 + 741384] = v11;
    return (double)v13 * *(double*)& byte_581450[8368];
}

//----- (0042ABF0) --------------------------------------------------------
void __cdecl sub_42ABF0(int a1, int a2, int a3)
{
    double v3; // st7
    int i; // esi
    __int64 v5; // rax

    if (a3 > 0)
        a3 = -a3;
    v3 = sub_42AAA0(&a3);
    for (i = 0; i < a2; ++i)
    {
        v5 = (__int64)(v3 * 255.0);
        if ((int)v5 < 0)
            LODWORD(v5) = -(int)v5;
        *(_BYTE*)(i + a1) = v5;
        v3 = sub_42AAA0(&a3);
    }
}

//----- (0042AC50) --------------------------------------------------------
_BYTE* __cdecl sub_42AC50(_BYTE* a1, size_t* a2)
{
    size_t* v2; // esi
    void* v3; // ebp
    size_t v4; // ecx
    _BYTE* v5; // edi
    _BYTE* result; // eax
    time_t v7; // eax
    int v8; // ebx
    u_long v9; // eax
    time_t v10; // eax
    unsigned __int8 v11; // al
    int v12; // ebp
    int v13; // ecx
    _BYTE* v14; // edx
    int v15; // ebx
    char v16; // al
    int v17; // [esp-Ch] [ebp-28h]
    void* v18; // [esp-8h] [ebp-24h]
    time_t v19; // [esp+Ch] [ebp-10h]
    LPVOID lpMem; // [esp+10h] [ebp-Ch]
    int v21; // [esp+14h] [ebp-8h]
    u_long v22; // [esp+18h] [ebp-4h]
    float v23; // [esp+24h] [ebp+8h]
    unsigned __int8 v24; // [esp+24h] [ebp+8h]

    v2 = a2;
    v19 = 0;
    v3 = nox_malloc(*a2);
    v4 = *a2 + 5;
    lpMem = v3;
    v5 = nox_malloc(v4);
    if ((int)* a2 >= 15)
    {
        v7 = time(0);
        v8 = v7;
        if (v7 > 0)
            v8 = -v7;
        v9 = htonl(v8);
        v17 = *a2;
        v22 = v9;
        sub_42ABF0((int)v3, v17, v8);
        v10 = time(0);
        v19 = v10;
        if (v10 > 0)
            v19 = -v10;
        if ((int)* a2 >= 241)
            v23 = 241.0;
        else
            v23 = (double)(int)(*a2 - 14);
        v11 = (unsigned __int64)(__int64)(sub_42AAA0(&v19) * v23) + 10;
        v12 = 0;
        v13 = 0;
        v24 = v11;
        if ((int)* v2 > 0)
        {
            v21 = v11;
            v14 = a1;
            v15 = (_BYTE*)lpMem - a1;
            while (1)
            {
                if (v13 == 5)
                {
                    v5[5] = v11;
                    v13 = 6;
                }
                if (v13 == v21)
                {
                    *(_DWORD*)& v5[v13] = v22;
                    v13 += 4;
                }
                v16 = *v14 ^ v14[v15];
                ++v13;
                ++v12;
                ++v14;
                v5[v13 - 1] = v16;
                if (v12 >= (int)* v2)
                    break;
                v11 = v24;
            }
        }
        v18 = lpMem;
        *v2 += 5;
        free(v18);
        result = v5;
    }
    else
    {
        *a2 = -2;
        free(v3);
        free(v5);
        result = 0;
    }
    return result;
}

//----- (0042ADA0) --------------------------------------------------------
u_short* __cdecl sub_42ADA0(int a1, int a2, __int16 a3, unsigned int* a4)
{
    int v4; // esi
    int v5; // edi
    void* v6; // eax
    int v7; // eax
    int v8; // edi
    void* v9; // eax
    int v10; // eax
    int v11; // edi
    void* v12; // eax
    int v13; // eax
    int v14; // edi
    void* v15; // eax
    int v16; // eax
    void* v17; // eax
    int v18; // eax
    int v19; // edi
    void* v20; // eax
    int v21; // eax
    int v22; // edi
    void* v23; // eax
    int v24; // eax
    void* v25; // eax
    int v26; // eax
    int v27; // edi
    void* v28; // eax
    int v29; // eax
    int v30; // edi
    void* v31; // eax
    int v32; // eax
    int v33; // edi
    void* v34; // eax
    int v35; // eax
    int v36; // edi
    void* v37; // eax
    int v38; // eax
    void* v39; // eax
    int v40; // eax
    void* v41; // eax
    int v42; // eax
    void* v43; // eax
    int v44; // eax
    void* v45; // eax
    int v46; // eax
    void* v47; // eax
    int v48; // eax
    int v49; // edi
    void* v50; // eax
    int v51; // eax
    int v52; // edi
    void* v53; // eax
    int v54; // eax
    int v55; // edi
    void* v56; // eax
    int v57; // eax
    int v58; // edi
    void* v59; // eax
    int v60; // eax
    void* v61; // eax
    int v62; // eax
    void* v63; // eax
    int v64; // eax
    void* v65; // eax
    int v66; // eax
    int v67; // edi
    void* v68; // eax
    int v69; // eax
    int v70; // edi
    void* v71; // eax
    int v72; // eax
    void* v73; // eax
    int v74; // eax
    void* v75; // eax
    int v76; // eax
    void* v77; // eax
    int v78; // eax
    void* v79; // eax
    int v80; // eax
    void* v81; // eax
    int v82; // eax
    int v83; // eax
    char v84; // di
    void* v85; // eax
    int v86; // eax
    void* v87; // eax
    int v88; // eax
    __int16 v89; // di
    void* v90; // eax
    int v91; // eax
    int v92; // eax
    const char* v93; // edi
    void* v94; // eax
    int v95; // eax
    int v96; // edi
    void* v97; // eax
    int v98; // eax
    int v99; // edi
    void* v100; // eax
    int v101; // eax
    void* v102; // eax
    int v103; // eax
    void* v104; // eax
    int v105; // eax
    int v106; // edi
    void* v107; // eax
    int v108; // eax
    void* v109; // eax
    int v110; // eax
    const void* v111; // esi
    void* v112; // eax
    int v113; // eax
    int v114; // eax
    u_short* v115; // esi
    char v117; // [esp+Ch] [ebp-10h]
    char v118[12]; // [esp+10h] [ebp-Ch]
    char v119; // [esp+20h] [ebp+4h]
    char v120; // [esp+20h] [ebp+4h]
    char v121; // [esp+20h] [ebp+4h]
    char v122; // [esp+20h] [ebp+4h]
    char v123; // [esp+20h] [ebp+4h]
    char v124; // [esp+20h] [ebp+4h]
    char v125; // [esp+20h] [ebp+4h]
    char v126; // [esp+20h] [ebp+4h]
    char v127; // [esp+20h] [ebp+4h]
    char v128; // [esp+20h] [ebp+4h]
    char v129; // [esp+24h] [ebp+8h]

    v4 = a1;
    v5 = *(_DWORD*)(a1 + 8);
    *(_WORD*)v118 = 0;
    *(_WORD*)& v118[2] = 0;
    *(_DWORD*)& v118[4] = 0;
    v6 = operator_new(0x10u);
    if (v6)
        v7 = sub_42C8B0((int)v6, (char*)& byte_587000[71632], v5);
    else
        v7 = 0;
    sub_42C360(v118, v7);
    v8 = *(_DWORD*)(a1 + 12);
    v9 = operator_new(0x10u);
    if (v9)
        v10 = sub_42C8B0((int)v9, (char*)& byte_587000[71640], v8);
    else
        v10 = 0;
    sub_42C360(v118, v10);
    v11 = *(_DWORD*)(a1 + 16);
    v12 = operator_new(0x10u);
    if (v12)
        v13 = sub_42C8B0((int)v12, (char*)& byte_587000[71648], v11);
    else
        v13 = 0;
    sub_42C360(v118, v13);
    v14 = *(_DWORD*)(a1 + 20);
    v15 = operator_new(0x10u);
    if (v15)
        v16 = sub_42C8B0((int)v15, (char*)& byte_587000[71656], v14);
    else
        v16 = 0;
    sub_42C360(v118, v16);
    v119 = *(_BYTE*)(a1 + 24);
    v17 = operator_new(0x10u);
    if (v17)
        v18 = sub_42C7F0((int)v17, (char*)& byte_587000[71664], v119);
    else
        v18 = 0;
    sub_42C360(v118, v18);
    v19 = *(_DWORD*)(v4 + 32);
    v20 = operator_new(0x10u);
    if (v20)
        v21 = sub_42C8B0((int)v20, (char*)& byte_587000[71672], v19);
    else
        v21 = 0;
    sub_42C360(v118, v21);
    v22 = *(_DWORD*)(v4 + 36);
    v23 = operator_new(0x10u);
    if (v23)
        v24 = sub_42C8B0((int)v23, (char*)& byte_587000[71680], v22);
    else
        v24 = 0;
    sub_42C360(v118, v24);
    v120 = *(_BYTE*)(v4 + 40);
    v25 = operator_new(0x10u);
    if (v25)
        v26 = sub_42C7F0((int)v25, (char*)& byte_587000[71688], v120);
    else
        v26 = 0;
    sub_42C360(v118, v26);
    v27 = *(_DWORD*)(v4 + 44);
    v28 = operator_new(0x10u);
    if (v28)
        v29 = sub_42C8B0((int)v28, (char*)& byte_587000[71696], v27);
    else
        v29 = 0;
    sub_42C360(v118, v29);
    v30 = *(_DWORD*)(v4 + 48);
    v31 = operator_new(0x10u);
    if (v31)
        v32 = sub_42C8B0((int)v31, (char*)& byte_587000[71704], v30);
    else
        v32 = 0;
    sub_42C360(v118, v32);
    v33 = *(_DWORD*)(v4 + 52);
    v34 = operator_new(0x10u);
    if (v34)
        v35 = sub_42C8B0((int)v34, (char*)& byte_587000[71712], v33);
    else
        v35 = 0;
    sub_42C360(v118, v35);
    v36 = *(_DWORD*)(v4 + 56);
    v37 = operator_new(0x10u);
    if (v37)
        v38 = sub_42C8B0((int)v37, (char*)& byte_587000[71720], v36);
    else
        v38 = 0;
    sub_42C360(v118, v38);
    v121 = *(_BYTE*)(v4 + 60);
    v39 = operator_new(0x10u);
    if (v39)
        v40 = sub_42C7F0((int)v39, (char*)& byte_587000[71728], v121);
    else
        v40 = 0;
    sub_42C360(v118, v40);
    v122 = *(_BYTE*)(v4 + 61);
    v41 = operator_new(0x10u);
    if (v41)
        v42 = sub_42C7F0((int)v41, (char*)& byte_587000[71736], v122);
    else
        v42 = 0;
    sub_42C360(v118, v42);
    v123 = *(_BYTE*)(v4 + 25);
    v43 = operator_new(0x10u);
    if (v43)
        v44 = sub_42C7F0((int)v43, (char*)& byte_587000[71744], v123);
    else
        v44 = 0;
    sub_42C360(v118, v44);
    v45 = operator_new(0x10u);
    if (v45)
        v46 = sub_42C8E0((int)v45, (char*)& byte_587000[71752], (const char*)(v4 + 96));
    else
        v46 = 0;
    sub_42C360(v118, v46);
    v47 = operator_new(0x10u);
    if (v47)
        v48 = sub_42C8E0((int)v47, (char*)& byte_587000[71760], (const char*)(v4 + 352));
    else
        v48 = 0;
    sub_42C360(v118, v48);
    v49 = *(_DWORD*)(v4 + 64);
    v50 = operator_new(0x10u);
    if (v50)
        v51 = sub_42C8B0((int)v50, (char*)& byte_587000[71768], v49);
    else
        v51 = 0;
    sub_42C360(v118, v51);
    v52 = *(_DWORD*)(v4 + 68);
    v53 = operator_new(0x10u);
    if (v53)
        v54 = sub_42C8B0((int)v53, (char*)& byte_587000[71776], v52);
    else
        v54 = 0;
    sub_42C360(v118, v54);
    v55 = *(_DWORD*)(v4 + 72);
    v56 = operator_new(0x10u);
    if (v56)
        v57 = sub_42C8B0((int)v56, (char*)& byte_587000[71784], v55);
    else
        v57 = 0;
    sub_42C360(v118, v57);
    v58 = *(_DWORD*)(v4 + 88);
    v59 = operator_new(0x10u);
    if (v59)
        v60 = sub_42C8B0((int)v59, (char*)& byte_587000[71792], v58);
    else
        v60 = 0;
    sub_42C360(v118, v60);
    v124 = *(_BYTE*)(v4 + 84);
    v61 = operator_new(0x10u);
    if (v61)
        v62 = sub_42C7F0((int)v61, (char*)& byte_587000[71800], v124);
    else
        v62 = 0;
    sub_42C360(v118, v62);
    v125 = *(_BYTE*)(v4 + 85);
    v63 = operator_new(0x10u);
    if (v63)
        v64 = sub_42C7F0((int)v63, (char*)& byte_587000[71808], v125);
    else
        v64 = 0;
    sub_42C360(v118, v64);
    v126 = *(_BYTE*)(v4 + 86);
    v65 = operator_new(0x10u);
    if (v65)
        v66 = sub_42C7F0((int)v65, (char*)& byte_587000[71816], v126);
    else
        v66 = 0;
    sub_42C360(v118, v66);
    v67 = *(_DWORD*)(v4 + 92);
    v68 = operator_new(0x10u);
    if (v68)
        v69 = sub_42C8B0((int)v68, (char*)& byte_587000[71824], v67);
    else
        v69 = 0;
    sub_42C360(v118, v69);
    v70 = *(_DWORD*)(v4 + 28);
    v71 = operator_new(0x10u);
    if (v71)
        v72 = sub_42C8B0((int)v71, (char*)& byte_587000[71832], v70);
    else
        v72 = 0;
    sub_42C360(v118, v72);
    v73 = operator_new(0x10u);
    if (v73)
        v74 = sub_42C7F0((int)v73, (char*)& byte_587000[71840], 1);
    else
        v74 = 0;
    sub_42C360(v118, v74);
    v127 = *(_BYTE*)(v4 + 26);
    v75 = operator_new(0x10u);
    if (v75)
        v76 = sub_42C7F0((int)v75, (char*)& byte_587000[71848], v127);
    else
        v76 = 0;
    sub_42C360(v118, v76);
    switch (a2)
    {
        case 0:
            *(_DWORD*)& byte_5D4594[741668] = 0;
            v77 = operator_new(0x10u);
            if (v77)
                v78 = sub_42C8B0((int)v77, (char*)& byte_587000[71856], 0);
            else
                v78 = 0;
            sub_42C360(v118, v78);
            v79 = operator_new(0x10u);
            if (v79)
                v80 = sub_42C7F0((int)v79, (char*)& byte_587000[71864], 0);
            else
                v80 = 0;
            sub_42C360(v118, v80);
            v81 = operator_new(0x10u);
            if (v81)
            {
                v82 = sub_42C820((int)v81, (char*)& byte_587000[71872], -1);
                sub_42C360(v118, v82);
                break;
            }
            sub_42C360(v118, 0);
            break;
        case 2:
            v83 = *(_DWORD*)& byte_5D4594[741668] + 1;
            *(_DWORD*)& byte_5D4594[741668] = v83;
            v84 = v83;
            v85 = operator_new(0x10u);
            if (v85)
                v86 = sub_42C8B0((int)v85, (char*)& byte_587000[71880], v84);
            else
                v86 = 0;
            sub_42C360(v118, v86);
            v87 = operator_new(0x10u);
            if (v87)
                v88 = sub_42C7F0((int)v87, (char*)& byte_587000[71888], 1);
            else
                v88 = 0;
            sub_42C360(v118, v88);
            v89 = *(_WORD*)(v4 + 6);
            v90 = operator_new(0x10u);
            if (v90)
                v91 = sub_42C820((int)v90, (char*)& byte_587000[71896], v89);
            else
                v91 = 0;
            sub_42C360(v118, v91);
            v92 = 0;
            for (*(_DWORD*)& byte_5D4594[741660] = 0; v92 < *(__int16*)(v4 + 6); *(_DWORD*)& byte_5D4594[741660] = v92)
            {
                byte_587000[71491] = v92 + 48;
                v93 = *(const char**)(*(_DWORD*)(v4 + 608) + 4 * v92);
                v94 = operator_new(0x10u);
                if (v94)
                    v95 = sub_42C8E0((int)v94, (char*)& byte_587000[71488], v93);
                else
                    v95 = 0;
                sub_42C360(v118, v95);
                byte_587000[71499] = byte_5D4594[741660] + 48;
                v96 = *(_DWORD*)(*(_DWORD*)(v4 + 612) + 4 * *(_DWORD*)& byte_5D4594[741660]);
                v97 = operator_new(0x10u);
                if (v97)
                    v98 = sub_42C8B0((int)v97, (char*)& byte_587000[71496], v96);
                else
                    v98 = 0;
                sub_42C360(v118, v98);
                byte_587000[71515] = byte_5D4594[741660] + 48;
                v99 = *(_DWORD*)(*(_DWORD*)(v4 + 616) + 4 * *(_DWORD*)& byte_5D4594[741660]);
                v100 = operator_new(0x10u);
                if (v100)
                    v101 = sub_42C8B0((int)v100, (char*)& byte_587000[71512], v99);
                else
                    v101 = 0;
                sub_42C360(v118, v101);
                byte_587000[71507] = byte_5D4594[741660] + 48;
                v128 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[741660] + *(_DWORD*)(v4 + 620));
                v102 = operator_new(0x10u);
                if (v102)
                    v103 = sub_42C7F0((int)v102, (char*)& byte_587000[71504], v128);
                else
                    v103 = 0;
                sub_42C360(v118, v103);
                byte_587000[71523] = byte_5D4594[741660] + 48;
                v129 = *(_BYTE*)(*(_DWORD*)(v4 + 624) + *(_DWORD*)& byte_5D4594[741660]);
                v104 = operator_new(0x10u);
                if (v104)
                    v105 = sub_42C7F0((int)v104, (char*)& byte_587000[71520], v129);
                else
                    v105 = 0;
                sub_42C360(v118, v105);
                byte_587000[71531] = byte_5D4594[741660] + 48;
                v106 = *(_DWORD*)(*(_DWORD*)(v4 + 628) + 4 * *(_DWORD*)& byte_5D4594[741660]);
                v107 = operator_new(0x10u);
                if (v107)
                    v108 = sub_42C8B0((int)v107, (char*)& byte_587000[71528], v106);
                else
                    v108 = 0;
                sub_42C360(v118, v108);
                byte_587000[71539] = byte_5D4594[741660] + 48;
                v117 = *(_BYTE*)(*(_DWORD*)(v4 + 632) + *(_DWORD*)& byte_5D4594[741660]);
                v109 = operator_new(0x10u);
                if (v109)
                    v110 = sub_42C7F0((int)v109, (char*)& byte_587000[71536], v117);
                else
                    v110 = 0;
                sub_42C360(v118, v110);
                v92 = *(_DWORD*)& byte_5D4594[741660] + 1;
            }
            v111 = *(const void**)(v4 + 636);
            v112 = operator_new(0x10u);
            if (v112)
            {
                v113 = sub_42C910((int)v112, (char*)& byte_587000[71904], v111, 2 * a3);
                sub_42C360(v118, v113);
                break;
            }
            sub_42C360(v118, 0);
            break;
        case 1:
            ++ * (_DWORD*)& byte_5D4594[741668];
            sub_42BDC0(v118, (char*)& byte_587000[71912], byte_5D4594[741668]);
            sub_42BCE0(v118, (char*)& byte_587000[71920], 0);
            sub_42BD50(v118, (char*)& byte_587000[71928], *(_WORD*)(v4 + 6));
            v114 = 0;
            for (*(_DWORD*)& byte_5D4594[741660] = 0; v114 < *(__int16*)(v4 + 6); *(_DWORD*)& byte_5D4594[741660] = v114)
            {
                byte_587000[71491] = v114 + 48;
                sub_42BE30(v118, (char*)& byte_587000[71488], *(const char**)(*(_DWORD*)(v4 + 608) + 4 * v114));
                byte_587000[71499] = byte_5D4594[741660] + 48;
                sub_42BDC0(
                        v118,
                        (char*)& byte_587000[71496],
                        *(_DWORD*)(*(_DWORD*)(v4 + 612) + 4 * *(_DWORD*)& byte_5D4594[741660]));
                byte_587000[71515] = byte_5D4594[741660] + 48;
                sub_42BDC0(
                        v118,
                        (char*)& byte_587000[71512],
                        *(_DWORD*)(*(_DWORD*)(v4 + 616) + 4 * *(_DWORD*)& byte_5D4594[741660]));
                byte_587000[71507] = byte_5D4594[741660] + 48;
                sub_42BCE0(
                        v118,
                        (char*)& byte_587000[71504],
                        *(_BYTE*)(*(_DWORD*)& byte_5D4594[741660] + *(_DWORD*)(v4 + 620)));
                byte_587000[71523] = byte_5D4594[741660] + 48;
                sub_42BCE0(
                        v118,
                        (char*)& byte_587000[71520],
                        *(_BYTE*)(*(_DWORD*)(v4 + 624) + *(_DWORD*)& byte_5D4594[741660]));
                byte_587000[71531] = byte_5D4594[741660] + 48;
                sub_42BDC0(
                        v118,
                        (char*)& byte_587000[71528],
                        *(_DWORD*)(*(_DWORD*)(v4 + 628) + 4 * *(_DWORD*)& byte_5D4594[741660]));
                byte_587000[71539] = byte_5D4594[741660] + 48;
                sub_42BCE0(
                        v118,
                        (char*)& byte_587000[71536],
                        *(_BYTE*)(*(_DWORD*)(v4 + 632) + *(_DWORD*)& byte_5D4594[741660]));
                v114 = *(_DWORD*)& byte_5D4594[741660] + 1;
            }
            sub_42BEA0(v118, (char*)& byte_587000[71936], *(const void**)(v4 + 636), 2 * a3);
            break;
    }
    v115 = sub_42C480(v118, a4);
    sub_42C330(v118);
    return v115;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042B810) --------------------------------------------------------
u_short* __cdecl sub_42B810(__int16* a1, unsigned int* a2)
{
    __int16* v2; // esi
    int v3; // edi
    void* v4; // eax
    int v5; // eax
    int v6; // edi
    void* v7; // eax
    int v8; // eax
    int v9; // edi
    void* v10; // eax
    int v11; // eax
    void* v12; // eax
    int v13; // eax
    void* v14; // eax
    int v15; // eax
    int v16; // edi
    void* v17; // eax
    int v18; // eax
    void* v19; // eax
    int v20; // eax
    __int16 v21; // di
    void* v22; // eax
    int v23; // eax
    char v24; // di
    void* v25; // eax
    int v26; // eax
    int v27; // eax
    const char* v28; // edi
    void* v29; // eax
    int v30; // eax
    int v31; // edi
    void* v32; // eax
    int v33; // eax
    void* v34; // eax
    int v35; // eax
    int v36; // edi
    void* v37; // eax
    int v38; // eax
    int v39; // edi
    void* v40; // eax
    int v41; // eax
    int v42; // edi
    void* v43; // eax
    int v44; // eax
    int v45; // edi
    void* v46; // eax
    int v47; // eax
    int v48; // edi
    void* v49; // eax
    int v50; // eax
    int v51; // edi
    void* v52; // eax
    int v53; // eax
    int v54; // edi
    void* v55; // eax
    int v56; // eax
    u_short* v57; // esi
    char v59[12]; // [esp+8h] [ebp-Ch]
    char v60; // [esp+18h] [ebp+4h]
    char v61; // [esp+18h] [ebp+4h]

    v2 = a1;
    v3 = *((_DWORD*)a1 + 1);
    *(_WORD*)v59 = 0;
    *(_WORD*)& v59[2] = 0;
    *(_DWORD*)& v59[4] = 0;
    v4 = operator_new(0x10u);
    if (v4)
        v5 = sub_42C8B0((int)v4, (char*)& byte_587000[71944], v3);
    else
        v5 = 0;
    sub_42C360(v59, v5);
    v6 = *((_DWORD*)a1 + 2);
    v7 = operator_new(0x10u);
    if (v7)
        v8 = sub_42C8B0((int)v7, (char*)& byte_587000[71952], v6);
    else
        v8 = 0;
    sub_42C360(v59, v8);
    v9 = *((_DWORD*)a1 + 3);
    v10 = operator_new(0x10u);
    if (v10)
        v11 = sub_42C8B0((int)v10, (char*)& byte_587000[71960], v9);
    else
        v11 = 0;
    sub_42C360(v59, v11);
    v12 = operator_new(0x10u);
    if (v12)
        v13 = sub_42C8E0((int)v12, (char*)& byte_587000[71968], (const char*)a1 + 24);
    else
        v13 = 0;
    sub_42C360(v59, v13);
    v14 = operator_new(0x10u);
    if (v14)
        v15 = sub_42C8E0((int)v14, (char*)& byte_587000[71976], (const char*)a1 + 280);
    else
        v15 = 0;
    sub_42C360(v59, v15);
    v16 = *((_DWORD*)a1 + 5);
    v17 = operator_new(0x10u);
    if (v17)
        v18 = sub_42C8B0((int)v17, (char*)& byte_587000[71984], v16);
    else
        v18 = 0;
    sub_42C360(v59, v18);
    v60 = *((_BYTE*)a1 + 16);
    v19 = operator_new(0x10u);
    if (v19)
        v20 = sub_42C7F0((int)v19, (char*)& byte_587000[71992], v60);
    else
        v20 = 0;
    sub_42C360(v59, v20);
    v21 = *v2;
    v22 = operator_new(0x10u);
    if (v22)
        v23 = sub_42C820((int)v22, (char*)& byte_587000[72000], v21);
    else
        v23 = 0;
    sub_42C360(v59, v23);
    v24 = byte_5D4594[741672];
    v25 = operator_new(0x10u);
    if (v25)
        v26 = sub_42C8B0((int)v25, (char*)& byte_587000[72008], v24);
    else
        v26 = 0;
    sub_42C360(v59, v26);
    v27 = 0;
    for (*(_DWORD*)& byte_5D4594[741664] = 0; v27 < *v2; *(_DWORD*)& byte_5D4594[741664] = v27)
    {
        byte_587000[71547] = v27 + 48;
        v28 = *(const char**)(*((_DWORD*)v2 + 134) + 4 * v27);
        v29 = operator_new(0x10u);
        if (v29)
            v30 = sub_42C8E0((int)v29, (char*)& byte_587000[71544], v28);
        else
            v30 = 0;
        sub_42C360(v59, v30);
        byte_587000[71555] = byte_5D4594[741664] + 48;
        v31 = *(_DWORD*)(*((_DWORD*)v2 + 135) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v32 = operator_new(0x10u);
        if (v32)
            v33 = sub_42C8B0((int)v32, (char*)& byte_587000[71552], v31);
        else
            v33 = 0;
        sub_42C360(v59, v33);
        byte_587000[71563] = byte_5D4594[741664] + 48;
        v61 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[741664] + *((_DWORD*)v2 + 144));
        v34 = operator_new(0x10u);
        if (v34)
            v35 = sub_42C7F0((int)v34, (char*)& byte_587000[71560], v61);
        else
            v35 = 0;
        sub_42C360(v59, v35);
        byte_587000[71571] = byte_5D4594[741664] + 48;
        v36 = *(_DWORD*)(*((_DWORD*)v2 + 136) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v37 = operator_new(0x10u);
        if (v37)
            v38 = sub_42C8B0((int)v37, (char*)& byte_587000[71568], v36);
        else
            v38 = 0;
        sub_42C360(v59, v38);
        byte_587000[71579] = byte_5D4594[741664] + 48;
        v39 = *(_DWORD*)(*((_DWORD*)v2 + 137) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v40 = operator_new(0x10u);
        if (v40)
            v41 = sub_42C8B0((int)v40, (char*)& byte_587000[71576], v39);
        else
            v41 = 0;
        sub_42C360(v59, v41);
        byte_587000[71587] = byte_5D4594[741664] + 48;
        v42 = *(_DWORD*)(*((_DWORD*)v2 + 138) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v43 = operator_new(0x10u);
        if (v43)
            v44 = sub_42C8B0((int)v43, (char*)& byte_587000[71584], v42);
        else
            v44 = 0;
        sub_42C360(v59, v44);
        byte_587000[71595] = byte_5D4594[741664] + 48;
        v45 = *(_DWORD*)(*((_DWORD*)v2 + 139) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v46 = operator_new(0x10u);
        if (v46)
            v47 = sub_42C8B0((int)v46, (char*)& byte_587000[71592], v45);
        else
            v47 = 0;
        sub_42C360(v59, v47);
        byte_587000[71603] = byte_5D4594[741664] + 48;
        v48 = *(_DWORD*)(*((_DWORD*)v2 + 140) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v49 = operator_new(0x10u);
        if (v49)
            v50 = sub_42C8B0((int)v49, (char*)& byte_587000[71600], v48);
        else
            v50 = 0;
        sub_42C360(v59, v50);
        byte_587000[71611] = byte_5D4594[741664] + 48;
        v51 = *(_DWORD*)(*((_DWORD*)v2 + 141) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v52 = operator_new(0x10u);
        if (v52)
            v53 = sub_42C8B0((int)v52, (char*)& byte_587000[71608], v51);
        else
            v53 = 0;
        sub_42C360(v59, v53);
        byte_587000[71619] = byte_5D4594[741664] + 48;
        v54 = *(_DWORD*)(*((_DWORD*)v2 + 142) + 4 * *(_DWORD*)& byte_5D4594[741664]);
        v55 = operator_new(0x10u);
        if (v55)
            v56 = sub_42C8B0((int)v55, (char*)& byte_587000[71616], v54);
        else
            v56 = 0;
        sub_42C360(v59, v56);
        byte_587000[71627] = byte_5D4594[741664] + 48;
        sub_42BDC0(
                v59,
                (char*)& byte_587000[71624],
                *(_DWORD*)(*((_DWORD*)v2 + 143) + 4 * *(_DWORD*)& byte_5D4594[741664]));
        v27 = *(_DWORD*)& byte_5D4594[741664] + 1;
    }
    v57 = sub_42C480(v59, a2);
    ++* (_DWORD*)& byte_5D4594[741672];
    sub_42C330(v59);
    return v57;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BCE0) --------------------------------------------------------
int __thiscall sub_42BCE0(_DWORD* this, char* a2, char a3)
{
    _DWORD* v3; // esi
    void* v4; // eax
    int v5; // eax

    v3 = this;
    v4 = operator_new(0x10u);
    if (v4)
        v5 = sub_42C7F0((int)v4, a2, a3);
    else
        v5 = 0;
    return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BD50) --------------------------------------------------------
int __thiscall sub_42BD50(_DWORD* this, char* a2, char a3)
{
    _DWORD* v3; // esi
    void* v4; // eax
    int v5; // eax

    v3 = this;
    v4 = operator_new(0x10u);
    if (v4)
        v5 = sub_42C820((int)v4, a2, a3);
    else
        v5 = 0;
    return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BDC0) --------------------------------------------------------
int __thiscall sub_42BDC0(_DWORD* this, char* a2, char a3)
{
    _DWORD* v3; // esi
    void* v4; // eax
    int v5; // eax

    v3 = this;
    v4 = operator_new(0x10u);
    if (v4)
        v5 = sub_42C8B0((int)v4, a2, a3);
    else
        v5 = 0;
    return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BE30) --------------------------------------------------------
int __thiscall sub_42BE30(_DWORD* this, char* a2, const char* a3)
{
    _DWORD* v3; // esi
    void* v4; // eax
    int v5; // eax

    v3 = this;
    v4 = operator_new(0x10u);
    if (v4)
        v5 = sub_42C8E0((int)v4, a2, a3);
    else
        v5 = 0;
    return sub_42C360(v3, v5);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BEA0) --------------------------------------------------------
int __thiscall sub_42BEA0(_DWORD* this, char* a2, const void* a3, unsigned __int16 a4)
{
    _DWORD* v4; // esi
    void* v5; // eax
    int v6; // eax

    v4 = this;
    v5 = operator_new(0x10u);
    if (v5)
        v6 = sub_42C910((int)v5, a2, a3, a4);
    else
        v6 = 0;
    return sub_42C360(v4, v6);
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042BF10) --------------------------------------------------------
int sub_42BF10()
{
    int v1; // eax

    if (*(_DWORD*)& byte_5D4594[741676])
        return 1;
    if (sub_40A5C0(2097153))
    {
        v1 = sub_4E3AC0();
    }
    else
    {
        if (!sub_40A5C0(2))
            return 0;
        v1 = nox_get_things_count();
    }
    *(_DWORD*)& byte_5D4594[741680] = v1;
    *(_DWORD*)& byte_5D4594[741676] = nox_malloc(2 * v1);
    if (*(_DWORD*)& byte_5D4594[741676])
    {
        sub_42BFB0();
        return 1;
    }
    return 0;
}

//----- (0042BF80) --------------------------------------------------------
LPVOID sub_42BF80()
{
    LPVOID result; // eax

    result = *(LPVOID*)& byte_5D4594[741676];
    if (*(_DWORD*)& byte_5D4594[741676])
    {
        free(*(LPVOID*)& byte_5D4594[741676]);
        *(_DWORD*)& byte_5D4594[741676] = 0;
    }
    *(_DWORD*)& byte_5D4594[741680] = 0;
    return result;
}

//----- (0042BFB0) --------------------------------------------------------
int sub_42BFB0()
{
    int result; // eax

    result = 0;
    memset(*(void**)& byte_5D4594[741676], 0, 2 * *(_DWORD*)& byte_5D4594[741680]);
    *(_WORD*)& byte_5D4594[741684] = 0;
    return result;
}

//----- (0042BFE0) --------------------------------------------------------
int sub_42BFE0()
{
    int result; // eax
    int i; // esi
    unsigned __int16 v2; // ax
    bool v3; // zf
    _WORD* v4; // eax
    int j; // ecx
    unsigned __int16 v6; // ax
    _WORD* v7; // eax
    int k; // esi
    _WORD* v9; // eax
    int l; // eax
    unsigned __int16 v11; // cx
    _WORD* v12; // ecx
    int m; // esi
    _WORD* v14; // eax
    int v15; // [esp+4h] [ebp-4h]

    result = sub_40A5C0(2097153);
    if (result)
    {
        sub_42BFB0();
        v15 = 1;
        for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
        {
            v2 = *(_WORD*)(i + 4);
            v3 = *(_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v2) == 0;
            v4 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v2);
            if (v3)
            {
                *v4 = v15;
                ++* (_WORD*)& byte_5D4594[741684];
                ++v15;
            }
            for (j = *(_DWORD*)(i + 504); j; j = *(_DWORD*)(j + 496))
            {
                v6 = *(_WORD*)(j + 4);
                v3 = *(_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v6) == 0;
                v7 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v6);
                if (v3)
                {
                    *v7 = v15;
                    ++* (_WORD*)& byte_5D4594[741684];
                    ++v15;
                }
            }
            if (*(_DWORD*)(i + 8) & 0x20000)
                sub_42C210(i, &v15, &byte_5D4594[741684]);
        }
        for (k = sub_4DA870(); k; k = sub_4DA880(k))
        {
            v9 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * *(unsigned __int16*)(k + 4));
            if (!*v9)
            {
                *v9 = v15;
                ++* (_WORD*)& byte_5D4594[741684];
                ++v15;
            }
            if (*(_DWORD*)(k + 8) & 0x20000)
                sub_42C210(k, &v15, &byte_5D4594[741684]);
        }
        for (l = sub_4DA840(); l; l = sub_4DA850(l))
        {
            v11 = *(_WORD*)(l + 4);
            v3 = *(_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v11) == 0;
            v12 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v11);
            if (v3)
            {
                *v12 = v15;
                ++* (_WORD*)& byte_5D4594[741684];
                ++v15;
            }
        }
        result = sub_40A5C0(0x200000);
        if (!result)
        {
            result = sub_40A5C0(1);
            if (result == 1)
            {
                result = sub_40A5C0(2);
                if (result == 1)
                {
                    result = sub_40A5C0(0x400000);
                    if (!result)
                    {
                        result = sub_45A060();
                        for (m = result; result; m = result)
                        {
                            if (!sub_4E3AD0(*(_DWORD*)(m + 108)) && sub_4E3B80(*(_DWORD*)(m + 108)))
                            {
                                v14 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * *(_DWORD*)(m + 108));
                                if (!*v14)
                                {
                                    *v14 = v15;
                                    ++* (_WORD*)& byte_5D4594[741684];
                                    ++v15;
                                }
                            }
                            result = sub_45A070(m);
                        }
                    }
                }
            }
        }
    }
    return result;
}

//----- (0042C210) --------------------------------------------------------
int __cdecl sub_42C210(int a1, _WORD* a2, _WORD* a3)
{
    int result; // eax
    int v4; // edi
    int v5; // ebx
    _WORD* v6; // eax
    int i; // ecx
    unsigned __int16 v8; // ax
    bool v9; // zf
    _WORD* v10; // eax
    int v11; // [esp+14h] [ebp+4h]

    result = *(_DWORD*)(a1 + 748);
    v11 = 3;
    do
    {
        v4 = result;
        v5 = 4;
        do
        {
            if (*(_DWORD*)v4)
            {
                v6 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * *(unsigned __int16*)(*(_DWORD*)v4 + 4));
                if (!*v6)
                {
                    *v6 = (*a2)++;
                    ++* a3;
                }
                for (i = *(_DWORD*)(*(_DWORD*)v4 + 504); i; i = *(_DWORD*)(i + 496))
                {
                    v8 = *(_WORD*)(i + 4);
                    v9 = *(_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v8) == 0;
                    v10 = (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * v8);
                    if (v9)
                    {
                        *v10 = (*a2)++;
                        ++* a3;
                    }
                }
            }
            v4 += 4;
            --v5;
        } while (v5);
        result = v4;
        --v11;
    } while (v11);
    return result;
}

//----- (0042C2B0) --------------------------------------------------------
__int16 __cdecl sub_42C2B0(__int16 a1)
{
    _WORD* v1; // ecx
    unsigned int v2; // eax

    v1 = *(_WORD * *)& byte_5D4594[741676];
    if (*(_DWORD*)& byte_5D4594[741676] && (v2 = 0, *(_DWORD*)& byte_5D4594[741680]))
    {
        while (*v1 != a1)
        {
            ++v2;
            ++v1;
            if (v2 >= *(int*)& byte_5D4594[741680])
                goto LABEL_5;
        }
    }
    else
    {
        LABEL_5:
        LOWORD(v2) = 0;
    }
    return v2;
}

//----- (0042C2E0) --------------------------------------------------------
__int16 __cdecl sub_42C2E0(int a1)
{
    __int16 result; // ax

    if (*(_DWORD*)& byte_5D4594[741676])
        result = *(_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * a1);
    else
        result = 0;
    return result;
}

//----- (0042C300) --------------------------------------------------------
__int16 sub_42C300()
{
    return *(_WORD*)& byte_5D4594[741684];
}

//----- (0042C310) --------------------------------------------------------
LPVOID __cdecl sub_42C310(unsigned __int16 a1, __int16 a2)
{
    LPVOID result; // eax

    result = *(LPVOID*)& byte_5D4594[741676];
    if (*(_DWORD*)& byte_5D4594[741676])
        * (_WORD*)(*(_DWORD*)& byte_5D4594[741676] + 2 * a1) = a2;
    return result;
}

//----- (0042C330) --------------------------------------------------------
void __thiscall sub_42C330(_DWORD* this)
{
    _DWORD* v1; // esi
    _DWORD* v2; // edi

    v1 = (_DWORD*)this[1];
    if (v1)
    {
        do
        {
            v2 = (_DWORD*)v1[3];
            if (v1)
            {
                sub_42CC50(v1);
                operator_delete(v1);
            }
            v1 = v2;
        } while (v2);
    }
}
// 42CC50: using guessed type int __thiscall sub_42CC50(_DWORD);

//----- (0042C360) --------------------------------------------------------
int __thiscall sub_42C360(_DWORD* this, int a2)
{
    int result; // eax

    result = a2;
    *(_DWORD*)(a2 + 12) = this[1];
    this[1] = a2;
    return result;
}

//----- (0042C370) --------------------------------------------------------
u_short* __thiscall sub_42C370(u_short* this, u_short* a2)
{
    u_short* v2; // edi
    u_short v3; // ax
    u_short v4; // ax
    u_short* v5; // esi
    u_short v6; // ax
    void* v7; // eax
    int v8; // ecx
    int v9; // ebx
    _DWORD* v10; // esi
    u_short v11; // ax
    unsigned int v12; // ebp
    void* v13; // eax
    int v14; // eax
    int v16; // [esp+8h] [ebp-8h]
    u_short* v17; // [esp+Ch] [ebp-4h]
    int v18; // [esp+14h] [ebp+4h]

    v2 = this;
    v3 = *a2;
    v17 = this;
    *this = *a2;
    *this = ntohs(v3);
    v4 = a2[1];
    v2[1] = a2[1];
    v5 = a2 + 2;
    v2[1] = ntohs(v4);
    v6 = *v2;
    *((_DWORD*)v2 + 1) = 0;
    v16 = v6 - 4;
    if (v16 <= 0)
        return v2;
    while (1)
    {
        v7 = operator_new(0x10u);
        v8 = *(_DWORD*)v5;
        v9 = (int)v7;
        v10 = v5 + 4;
        *(_DWORD*)v7 = v8;
        *((_DWORD*)v7 + 1) = *(v10 - 1);
        v11 = ntohs(*((_WORD*)v7 + 3));
        v12 = v11;
        v13 = operator_new(v11);
        *(_DWORD*)(v9 + 8) = v13;
        qmemcpy(v13, v10, v12);
        v14 = -(ntohs(*(_WORD*)(v9 + 6)) & 3) & 3;
        v18 = (int)v10 + v14 + v12;
        v16 += -8 - v14 - v12;
        sub_42CCE0((u_short*)v9);
        sub_42C360(v17, v9);
        if (v16 <= 0)
            break;
        v5 = (u_short*)v18;
    }
    return v17;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042C480) --------------------------------------------------------
u_short* __thiscall sub_42C480(_DWORD* this, unsigned int* a2)
{
    _DWORD* v2; // ebx
    int i; // eax
    unsigned int v4; // ecx
    u_short* v5; // edi
    int v6; // ebx
    _DWORD* v7; // ebp
    char* v8; // ebp
    int v9; // ebp

    v2 = this;
    *a2 = 4;
    for (i = this[1]; i; i = *(_DWORD*)(i + 12))
    {
        v4 = *a2 + 8;
        *a2 = v4;
        *a2 = *(unsigned __int16*)(i + 6) + v4 + (-(((unsigned __int8) * (_WORD*)(i + 6) + (_BYTE)v4) & 3) & 3);
    }
    v5 = (u_short*)operator_new(*a2);
    *v5 = htons(*(_WORD*)a2);
    v5[1] = htons(*((_WORD*)v2 + 1));
    v6 = v2[1];
    v7 = v5 + 2;
    if (!v6)
        return v5;
    do
    {
        sub_42CC70(v6);
        *v7 = *(_DWORD*)v6;
        v7[1] = *(_DWORD*)(v6 + 4);
        v8 = (char*)(v7 + 2);
        qmemcpy(v8, *(const void**)(v6 + 8), ntohs(*(_WORD*)(v6 + 6)));
        v9 = (int)& v8[ntohs(*(_WORD*)(v6 + 6))];
        v7 = (_DWORD*)((-(ntohs(*(_WORD*)(v6 + 6)) & 3) & 3) + v9);
        sub_42CCE0((u_short*)v6);
        v6 = *(_DWORD*)(v6 + 12);
    } while (v6);
    return v5;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042C580) --------------------------------------------------------
int __thiscall sub_42C580(_DWORD* this, char* a2)
{
    int v2; // esi

    v2 = this[1];
    if (!v2)
        return 0;
    while (strncmp(a2, (const char*)v2, 4u))
    {
        v2 = *(_DWORD*)(v2 + 12);
        if (!v2)
            return 0;
    }
    return v2;
}

//----- (0042C5C0) --------------------------------------------------------
bool __thiscall sub_42C5C0(_DWORD* this, char* a2, _BYTE* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_BYTE * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C5E0) --------------------------------------------------------
bool __thiscall sub_42C5E0(_DWORD* this, char* a2, _BYTE* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_BYTE * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C600) --------------------------------------------------------
bool __thiscall sub_42C600(_DWORD* this, char* a2, _WORD* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_WORD * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C630) --------------------------------------------------------
bool __thiscall sub_42C630(_DWORD* this, char* a2, _WORD* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_WORD * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C660) --------------------------------------------------------
bool __thiscall sub_42C660(_DWORD* this, char* a2, _DWORD* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_DWORD * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C680) --------------------------------------------------------
bool __thiscall sub_42C680(_DWORD* this, char* a2, _DWORD* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_DWORD * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C6A0) --------------------------------------------------------
bool __thiscall sub_42C6A0(_DWORD* this, char* a2, char* a3)
{
    int v3; // eax
    bool v4; // zf

    v3 = sub_42C580(this, a2);
    v4 = v3 == 0;
    if (v3)
    {
        strcpy(a3, *(const char**)(v3 + 8));
        v4 = v3 == 0;
    }
    return !v4;
}

//----- (0042C6E0) --------------------------------------------------------
bool __thiscall sub_42C6E0(_DWORD* this, char* a2, _DWORD* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_DWORD * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C700) --------------------------------------------------------
bool __thiscall sub_42C700(_DWORD* this, char* a2, _DWORD* a3)
{
    int v3; // eax

    v3 = sub_42C580(this, a2);
    if (v3)
        * a3 = **(_DWORD * *)(v3 + 8);
    return v3 != 0;
}

//----- (0042C720) --------------------------------------------------------
bool __thiscall sub_42C720(_DWORD* this, char* a2, void* a3, unsigned int* a4)
{
    int v4; // eax
    bool v5; // zf
    unsigned int v6; // ecx

    v4 = sub_42C580(this, a2);
    v5 = v4 == 0;
    if (v4)
    {
        v6 = *(unsigned __int16*)(v4 + 6);
        if ((unsigned __int16)v6 >= (int)* a4)
        v6 = *a4;
        qmemcpy(a3, *(const void**)(v4 + 8), v6);
        *a4 = *(unsigned __int16*)(v4 + 6);
        v5 = v4 == 0;
    }
    return !v5;
}

//----- (0042C770) --------------------------------------------------------
int __thiscall sub_42C770(LPVOID* this)
{
    LPVOID* v1; // ebx
    int result; // eax

    v1 = this;
    operator_delete(this[2]);
    result = 0;
    strcpy((char*)v1, (const char*)& byte_5D4594[741688]);
    *((_WORD*)v1 + 2) = 0;
    *((_WORD*)v1 + 3) = 0;
    v1[2] = 0;
    v1[3] = 0;
    return result;
}

//----- (0042C7C0) --------------------------------------------------------
int __thiscall sub_42C7C0(int this, char* a2, char a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42C940((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C7F0) --------------------------------------------------------
int __thiscall sub_42C7F0(int this, char* a2, char a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42C9A0((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C820) --------------------------------------------------------
int __thiscall sub_42C820(int this, char* a2, char a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42CA00((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C850) --------------------------------------------------------
int __thiscall sub_42C850(int this, char* a2, char a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42CA60((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C880) --------------------------------------------------------
int __thiscall sub_42C880(int this, char* a2, char a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42CAC0((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C8B0) --------------------------------------------------------
int __thiscall sub_42C8B0(int this, char* a2, char a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42CB20((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C8E0) --------------------------------------------------------
int __thiscall sub_42C8E0(int this, char* a2, const char* a3)
{
    int v3; // esi

    v3 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42CB80((LPVOID*)this, a2, a3);
    return v3;
}

//----- (0042C910) --------------------------------------------------------
int __thiscall sub_42C910(int this, char* a2, const void* a3, unsigned __int16 a4)
{
    int v4; // esi

    v4 = this;
    *(_DWORD*)(this + 8) = 0;
    sub_42CBF0((LPVOID*)this, a2, a3, a4);
    return v4;
}

//----- (0042C940) --------------------------------------------------------
char* __thiscall sub_42C940(LPVOID* this, char* a2, char a3)
{
    LPVOID* v3; // ebx
    char* result; // eax
    unsigned int v5; // edx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 1;
    *((_WORD*)v3 + 3) = 1;
    result = (char*)operator_new(1u);
    v5 = *((unsigned __int16*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, &a3, v5);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042C9A0) --------------------------------------------------------
char* __thiscall sub_42C9A0(LPVOID* this, char* a2, char a3)
{
    LPVOID* v3; // ebx
    char* result; // eax
    unsigned int v5; // edx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 2;
    *((_WORD*)v3 + 3) = 1;
    result = (char*)operator_new(1u);
    v5 = *((unsigned __int16*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, &a3, v5);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CA00) --------------------------------------------------------
char* __thiscall sub_42CA00(LPVOID* this, char* a2, char a3)
{
    LPVOID* v3; // ebx
    char* result; // eax
    unsigned int v5; // edx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 3;
    *((_WORD*)v3 + 3) = 2;
    result = (char*)operator_new(2u);
    v5 = *((unsigned __int16*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, &a3, v5);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CA60) --------------------------------------------------------
char* __thiscall sub_42CA60(LPVOID* this, char* a2, char a3)
{
    LPVOID* v3; // ebx
    char* result; // eax
    unsigned int v5; // edx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 4;
    *((_WORD*)v3 + 3) = 2;
    result = (char*)operator_new(2u);
    v5 = *((unsigned __int16*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, &a3, v5);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CAC0) --------------------------------------------------------
char* __thiscall sub_42CAC0(LPVOID* this, char* a2, char a3)
{
    LPVOID* v3; // ebx
    char* result; // eax
    unsigned int v5; // edx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 5;
    *((_WORD*)v3 + 3) = 4;
    result = (char*)operator_new(4u);
    v5 = *((unsigned __int16*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, &a3, v5);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CB20) --------------------------------------------------------
char* __thiscall sub_42CB20(LPVOID* this, char* a2, char a3)
{
    LPVOID* v3; // ebx
    char* result; // eax
    unsigned int v5; // edx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 6;
    *((_WORD*)v3 + 3) = 4;
    result = (char*)operator_new(4u);
    v5 = *((unsigned __int16*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, &a3, v5);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CB80) --------------------------------------------------------
char* __thiscall sub_42CB80(LPVOID* this, char* a2, const char* a3)
{
    LPVOID* v3; // ebx
    unsigned int v4; // kr08_4
    char* result; // eax
    unsigned __int16 v6; // cx

    v3 = this;
    sub_42C770(this);
    strncpy((char*)v3, a2, 4u);
    *((_WORD*)v3 + 2) = 7;
    v4 = strlen(a3) + 1;
    *((_WORD*)v3 + 3) = v4;
    result = (char*)operator_new((unsigned __int16)v4);
    v6 = *((_WORD*)v3 + 3);
    v3[2] = result;
    qmemcpy(result, a3, v6);
    v3[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CBF0) --------------------------------------------------------
void* __thiscall sub_42CBF0(LPVOID* this, char* a2, const void* a3, unsigned __int16 a4)
{
    LPVOID* v4; // ebx
    void* result; // eax
    unsigned int v6; // edx

    v4 = this;
    sub_42C770(this);
    strncpy((char*)v4, a2, 4u);
    *((_WORD*)v4 + 2) = 20;
    *((_WORD*)v4 + 3) = a4;
    result = operator_new(a4);
    v6 = *((unsigned __int16*)v4 + 3);
    v4[2] = result;
    qmemcpy(result, a3, v6);
    v4[3] = 0;
    return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0042CC60) --------------------------------------------------------
int __thiscall sub_42CC60(unsigned __int16* this)
{
return this[2];
}

//----- (0042CC70) --------------------------------------------------------
u_short __thiscall sub_42CC70(int this)
{
    int v1; // esi
    u_short v2; // ax
    u_short v3; // cx
    u_short result; // ax

    v1 = this;
    switch (*(unsigned __int16*)(this + 4))
    {
        case 3u:
        case 4u:
            **(_WORD * *)(this + 8) = htons(**(_WORD * *)(this + 8));
        break;
        case 5u:
        case 6u:
            **(_DWORD * *)(this + 8) = htonl(**(_DWORD * *)(this + 8));
        break;
        default:
            break;
    }
    v2 = htons(*(_WORD*)(v1 + 4));
    v3 = *(_WORD*)(v1 + 6);
    *(_WORD*)(v1 + 4) = v2;
    result = htons(v3);
    *(_WORD*)(v1 + 6) = result;
    return result;
}

//----- (0042CCE0) --------------------------------------------------------
__int16 __thiscall sub_42CCE0(u_short* this)
{
    u_short* v1; // esi
    u_short v2; // ax
    u_short v3; // cx
    u_long v4; // eax

    v1 = this;
    v2 = ntohs(this[2]);
    v3 = v1[3];
    v1[2] = v2;
    v1[3] = ntohs(v3);
    LOWORD(v4) = v1[2] - 3;
    switch (v1[2])
    {
        case 3u:
        case 4u:
            LOWORD(v4) = ntohs(**((_WORD * *)v1 + 2));
            **((_WORD * *)v1 + 2) = v4;
            break;
        case 5u:
        case 6u:
            v4 = ntohl(**((_DWORD * *)v1 + 2));
            **((_DWORD * *)v1 + 2) = v4;
            break;
        default:
            return v4;
    }
    return v4;
}

//----- (0042CD50) --------------------------------------------------------
char* __cdecl sub_42CD50(_BYTE* a1)
{
    *a1 = byte_5D4594[747864];
    return (char*)& byte_5D4594[741692];
}

//----- (0042CD70) --------------------------------------------------------
LPVOID sub_42CD70()
{
    return *(LPVOID*)& byte_5D4594[754056];
}

//----- (0042CD80) --------------------------------------------------------
void* __cdecl sub_42CD80(void* a1)
{
    void* result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[754056] = a1;
    return result;
}

//----- (0042CD90) --------------------------------------------------------
void sub_42CD90()
{
    _DWORD* result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD * *)& byte_5D4594[754056];
    if (result)
    {
        do
        {
            v1 = (_DWORD*)result[19];
            free(result);
            result = v1;
        } while (v1);
    }
    *(_DWORD*)& byte_5D4594[754056] = 0;
    byte_5D4594[747848] = 0;
    byte_5D4594[750956] = 0;
    *(_DWORD*)& byte_5D4594[754036] = 0;
    *(_DWORD*)& byte_5D4594[754040] = 0;
    *(_DWORD*)& byte_5D4594[754044] = 0;
    *(_DWORD*)& byte_5D4594[754048] = 0;
    *(_DWORD*)& byte_5D4594[747856] = 100;
    *(_DWORD*)& byte_5D4594[747868] = 4;
}

//----- (0042CDF0) --------------------------------------------------------
_DWORD* __cdecl sub_42CDF0(FILE* a1)
{
    int v1; // eax
    FILE* v2; // edi
    _DWORD* result; // eax
    _DWORD* v4; // ebx
    int v5; // ebp
    unsigned __int8* v6; // esi
    int v7; // eax
    int v8; // ebp
    unsigned __int8* v9; // esi
    int v10; // eax
    _DWORD* v11; // [esp+Ch] [ebp+4h]
    _DWORD* v12; // [esp+Ch] [ebp+4h]

    v1 = sub_430AF0();
    v2 = a1;
    fprintf(a1, "MousePickup = %s\n", *(_DWORD*)& byte_587000[4 * v1 + 73652]);
    result = *(_DWORD * *)& byte_5D4594[754056];
    v4 = *(_DWORD * *)& byte_5D4594[754056];
    if (*(_DWORD*)& byte_5D4594[754056])
    {
        for (result = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[754056] + 76); result; result = (_DWORD*)result[19])
            v4 = result;
        for (; v4; v4 = (_DWORD*)v4[18])
        {
            v5 = 0;
            if (v4[8] > 0)
            {
                v11 = v4;
                do
                {
                    if (*(_DWORD*)& byte_587000[73672])
                    {
                        v6 = &byte_587000[73672];
                        do
                        {
                            if (*v11 == (char*) * ((_DWORD*)v6 + 1))
                                fprintf(v2, "%s ", *(_DWORD*)v6);
                            v7 = *((_DWORD*)v6 + 4);
                            v6 += 16;
                        } while (v7);
                    }
                    if (v5 != v4[8] - 1)
                        fprintf(v2, "+ ");
                    ++v5;
                    v11++;
                } while (v5 < v4[8]);
            }
            fprintf(v2, "= ");
            v8 = 0;
            if (v4[17] > 0)
            {
                v12 = v4 + 9;
                do
                {
                    if (*(_DWORD*)& byte_587000[75880])
                    {
                        v9 = &byte_587000[75880];
                        do
                        {
                            if (*v12 == (char*) * ((_DWORD*)v9 + 1))
                                fprintf(v2, "%s ", *(_DWORD*)v9);
                            v10 = *((_DWORD*)v9 + 3);
                            v9 += 12;
                        } while (v10);
                    }
                    if (v8 != v4[17] - 1)
                        fprintf(v2, "+ ");
                    ++v8;
                    v12++;
                } while (v8 < v4[17]);
            }
            result = (_DWORD*)fprintf(v2, "\n");
        }
    }
    return result;
}

//----- (0042CF50) --------------------------------------------------------
int __cdecl sub_42CF50(const char* a1)
{
    int result; // eax
    const char* v2; // ebp
    _DWORD* v3; // ebx
    char* v4; // ebp
    int v5; // edi
    const char** v6; // esi
    const char* v7; // eax
    int v8; // ebp
    unsigned __int8* v9; // edi
    int v10; // eax
    char* v11; // eax
    const char* v12; // ecx
    int v13; // ebp
    unsigned __int8* v14; // edi
    int v15; // eax
    char* v16; // [esp+10h] [ebp-408h]
    int v17; // [esp+14h] [ebp-404h]
    char v18[1024]; // [esp+18h] [ebp-400h]

    *(_DWORD*)& byte_5D4594[747868] = 4;
    byte_5D4594[747848] = 0;
    strcpy(v18, a1);
    result = (int)strtok(v18, " \r\t\n");
    v2 = (const char*)result;
    v16 = (char*)result;
    if (result)
    {
        result = (int)nox_calloc(1u, 0x60u);
        v3 = (_DWORD*)result;
        v17 = result;
        if (result)
        {
            if (!strcmp(v2, "MousePickup"))
            {
                strtok(0, " \r\t\n");
                v4 = strtok(0, " \r\t\n");
                v5 = 0;
                v6 = (const char**)& byte_587000[73652];
                while (_strcmpi(v4, *v6))
                {
                    ++v6;
                    ++v5;
                    if ((int)v6 >= (int)& byte_587000[73668])
                        goto LABEL_9;
                }
                if (v5 < 4)
                    goto LABEL_10;
                LABEL_9:
                v5 = 0;
                LABEL_10:
                sub_430AA0(v5);
                free(v3);
                result = 1;
            }
            else
            {
                while (*v2 != 61)
                {
                    if (*v2 != 43)
                    {
                        v7 = *(const char**)& byte_587000[73672];
                        v8 = 0;
                        if (*(_DWORD*)& byte_587000[73672])
                        {
                            v9 = &byte_587000[73672];
                            while (strcmp(v7, v16))
                            {
                                v7 = (const char*) * ((_DWORD*)v9 + 4);
                                v9 += 16;
                                ++v8;
                                if (!v7)
                                    goto LABEL_21;
                            }
                            v10 = v3[8];
                            if (v10 == 8)
                            {
                                LABEL_38:
                                free(v3);
                                return 0;
                            }
                            v3[v10] = *(_DWORD*)& byte_587000[16 * v8 + 73676];
                            ++v3[8];
                        }
                        LABEL_21:
                        if (!*(_DWORD*)& byte_587000[16 * v8 + 73672])
                            return 0;
                    }
                    v16 = strtok(0, " \r\t\n");
                    if (!v16)
                        break;
                    v2 = v16;
                }
                v3[17] = 0;
                v11 = strtok(0, " \r\t\n");
                if (v11)
                {
                    while (*v11 != 61)
                    {
                        if (*v11 != 43)
                        {
                            v12 = *(const char**)& byte_587000[75880];
                            v13 = 0;
                            if (*(_DWORD*)& byte_587000[75880])
                            {
                                v14 = &byte_587000[75880];
                                while (strcmp(v12, v11))
                                {
                                    v12 = (const char*) * ((_DWORD*)v14 + 3);
                                    v14 += 12;
                                    ++v13;
                                    if (!v12)
                                    {
                                        v3 = (_DWORD*)v17;
                                        goto LABEL_33;
                                    }
                                }
                                v3 = (_DWORD*)v17;
                                v15 = *(_DWORD*)(v17 + 68);
                                if (v15 == 8)
                                    goto LABEL_38;
                                *(_DWORD*)(v17 + 4 * v15 + 36) = *(_DWORD*)& byte_587000[12 * v13 + 75884];
                                ++* (_DWORD*)(v17 + 68);
                            }
                            LABEL_33:
                            if (!*(_DWORD*)& byte_587000[12 * v13 + 75880])
                                return 0;
                        }
                        v11 = strtok(0, " \r\t\n");
                        if (!v11)
                            break;
                    }
                }
                v3[18] = 0;
                v3[19] = *(_DWORD*)& byte_5D4594[754056];
                if (*(_DWORD*)& byte_5D4594[754056])
                    * (_DWORD*)(*(_DWORD*)& byte_5D4594[754056] + 72) = v3;
                *(_DWORD*)& byte_5D4594[754056] = v3;
                result = 1;
            }
        }
    }
    return result;
}

//----- (0042D220) --------------------------------------------------------
unsigned int sub_42D220()
{
    int v0; // ebx
    int2* v1; // ebp
    int v2; // esi
    int* v3; // edi
    int v4; // ebx
    bool v5; // zf
    int v6; // eax
    bool v7; // zf
    int v8; // eax
    int v9; // eax
    int v10; // edx
    _DWORD* v11; // ebp
    int v12; // esi
    int v13; // edx
    int v14; // eax
    _DWORD* v15; // ecx
    int v16; // ecx
    int i; // eax
    int v19; // [esp+10h] [ebp-Ch]
    int v20; // [esp+10h] [ebp-Ch]
    int v21; // [esp+14h] [ebp-8h]
    int2* v22; // [esp+18h] [ebp-4h]

    v0 = 0;
    v21 = 0;
    v1 = sub_4309F0();
    v22 = v1;
    v2 = *(_DWORD*)& byte_5D4594[754056];
    if (*(_DWORD*)& byte_5D4594[754056])
    {
        while (1)
        {
            v19 = 0;
            if (*(_DWORD*)(v2 + 32) > 0)
                break;
            LABEL_33:
            if (v19 == *(_DWORD*)(v2 + 32))
            {
                v10 = v21;
                v21 = v2;
                *(_DWORD*)(v2 + 80) = v10;
                *(_BYTE*)(v2 + 88) = 1;
            }
            v2 = *(_DWORD*)(v2 + 76);
            if (!v2)
            {
                v0 = v21;
                goto LABEL_37;
            }
        }
        v3 = (int*)v2;
        while (1)
        {
            v4 = *v3;
            if (!(*v3 & 0xFFFF0000))
                break;
            if (v4 & 0x10000 && byte_5D4594[747848] != 2)
            {
                switch (v4)
                {
                    case 65536:
                        v6 = v1[3].field_0;
                        if (v6 != 5 && v6 != 8)
                            goto LABEL_33;
                        v7 = v6 == 8;
                        break;
                    case 65537:
                        v8 = v1[6].field_0;
                        if (v8 != 13 && v8 != 16)
                            goto LABEL_33;
                        v7 = v8 == 16;
                        break;
                    case 65538:
                        v9 = v1[4].field_4;
                        if (v9 != 9 && v9 != 12)
                            goto LABEL_33;
                        v7 = v9 == 12;
                        break;
                    case 65539:
                        if (v1[1].field_0 == 19)
                            goto LABEL_32;
                        goto LABEL_33;
                    case 65540:
                        if (v1[1].field_0 == 20)
                            goto LABEL_32;
                        goto LABEL_33;
                    default:
                        goto LABEL_32;
                }
                if (v7)
                {
                    v5 = *(_DWORD*)(v2 + 36) == 1;
                    LABEL_17:
                    if (v5)
                        goto LABEL_33;
                    goto LABEL_32;
                }
            }
            else if (v4 & 0x20000 && (byte_5D4594[750956] || !((1 << v4) & *(_DWORD*)& byte_5D4594[747844])))
            {
                goto LABEL_33;
            }
            LABEL_32:
            ++v3;
            if (++v19 >= *(int*)(v2 + 32))
                goto LABEL_33;
        }
        if (sub_46B4F0() || sub_46A4A0() || sub_430970(v4) == 1)
            goto LABEL_33;
        v5 = sub_430950(v4) == 1;
        goto LABEL_17;
    }
    LABEL_37:
    if (v0)
    {
        do
        {
            if (*(_BYTE*)(v0 + 88))
            {
                v20 = 0;
                if (*(_DWORD*)(v0 + 32) > 0)
                {
                    v11 = (_DWORD*)v0;
                    do
                    {
                        v12 = v21;
                        do
                        {
                            if (*(_BYTE*)(v12 + 88))
                            {
                                if (v12 != v0)
                                {
                                    v13 = *(_DWORD*)(v12 + 32);
                                    v14 = 0;
                                    if (v13 > 0)
                                    {
                                        v15 = (_DWORD*)v12;
                                        while (*v11 != *v15)
                                        {
                                            ++v14;
                                            ++v15;
                                            if (v14 >= v13)
                                                goto LABEL_52;
                                        }
                                        if (*(int*)(v0 + 32) >= v13)
                                            * (_BYTE*)(v12 + 88) = 0;
                                        else
                                            *(_BYTE*)(v0 + 88) = 0;
                                    }
                                }
                            }
                            LABEL_52:
                            v12 = *(_DWORD*)(v12 + 80);
                        } while (v12);
                        ++v11;
                        ++v20;
                    } while (v20 < *(int*)(v0 + 32));
                    v1 = v22;
                }
            }
            v0 = *(_DWORD*)(v0 + 80);
        } while (v0);
        v0 = v21;
    }
    v16 = 0;
    for (i = v0; i; i = *(_DWORD*)(i + 80))
    {
        if (*(_BYTE*)(i + 88))
        {
            *(_DWORD*)(i + 84) = v16;
            v16 = i;
            *(_DWORD*)(i + 92) = *(_DWORD*)& byte_5D4594[2598000];
        }
    }
    sub_42D6B0(v1, v16);
    return sub_42D510();
}

//----- (0042D440) --------------------------------------------------------
int __cdecl sub_42D440(int a1)
{
    return *(_DWORD*)& byte_587000[12 * a1 + 72020];
}

//----- (0042D450) --------------------------------------------------------
unsigned __int8 __cdecl sub_42D450(int a1)
{
    return byte_587000[12 * a1 + 72024];
}

//----- (0042D460) --------------------------------------------------------
int __cdecl sub_42D460(int a1)
{
    int result; // eax

    switch (a1)
    {
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 42:
        case 43:
        case 44:
        case 45:
            result = 1;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

//----- (0042D4B0) --------------------------------------------------------
int __cdecl sub_42D4B0(int a1)
{
    int result; // eax

    switch (a1)
    {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
            result = 1;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}

//----- (0042D510) --------------------------------------------------------
unsigned int sub_42D510()
{
    int v0; // ebp
    __int64 v1; // kr00_8
    unsigned int result; // eax
    int v3; // ebx
    __int64 v4; // kr08_8
    int v5; // eax
    int v6; // edx
    int* v7; // ebx
    int v8; // eax
    int v9; // edx
    unsigned __int8 v10; // al

    v0 = 0;
    v1 = sub_416BB0();
    *(_DWORD*)& byte_5D4594[747864] = 0;
    result = sub_40A5C0(1);
    if (result)
    {
        v3 = *(_DWORD*)& byte_5D4594[754040];
        result = *(_DWORD*)& byte_5D4594[754036];
        if (*(_DWORD*)& byte_5D4594[754040] != *(_DWORD*)& byte_5D4594[754036])
        {
            v4 = v1 + 50;
            do
            {
                if (HIDWORD(v4) < *(int*)& byte_5D4594[24 * v3 + 747888])
                    break;
                if (HIDWORD(v4) <= *(int*)& byte_5D4594[24 * v3 + 747888])
                {
                    result = v1 + 50;
                    if ((unsigned int)v4 < *(int*)& byte_5D4594[24 * v3 + 747884])
                        break;
                }
                if (*(_DWORD*)& byte_5D4594[24 * v3 + 747900] == 1)
                {
                    v5 = *(_DWORD*)& byte_5D4594[747864];
                    v6 = *(_DWORD*)& byte_5D4594[24 * v3 + 747892];
                    byte_5D4594[*(_DWORD*)& byte_5D4594[747864] + 741692] = byte_5D4594[24 * v3 + 747892];
                    *(_DWORD*)& byte_5D4594[747864] = v5 + 4;
                    result = sub_42D440(v6);
                    if (result)
                    {
                        result = sub_42D450(*(_DWORD*)& byte_5D4594[24 * v3 + 747892]);
                        qmemcpy(&byte_5D4594[*(_DWORD*)& byte_5D4594[747864] + 741692], &byte_5D4594[24 * v3 + 747896], result);
                        *(_DWORD*)& byte_5D4594[747864] += result;
                    }
                }
                v3 = (v3 + 1) % 128;
            } while (v3 != *(_DWORD*)& byte_5D4594[754036]);
        }
        *(_DWORD*)& byte_5D4594[754040] = v3;
    }
    else if (*(_DWORD*)& byte_5D4594[754036] > 0)
    {
        v7 = (int*)& byte_5D4594[747892];
        do
        {
            if (v7[2] == 1)
            {
                v8 = *(_DWORD*)& byte_5D4594[747864];
                v9 = *v7;
                byte_5D4594[*(_DWORD*)& byte_5D4594[747864] + 741692] = *(_BYTE*)v7;
                *(_DWORD*)& byte_5D4594[747864] = v8 + 4;
                if (sub_42D440(v9))
                {
                    v10 = sub_42D450(*v7);
                    qmemcpy(&byte_5D4594[*(_DWORD*)& byte_5D4594[747864] + 741692], v7 + 1, v10);
                    *(_DWORD*)& byte_5D4594[747864] += v10;
                }
            }
            result = *(_DWORD*)& byte_5D4594[754036];
            ++v0;
            v7 += 6;
        } while (v0 < *(int*)& byte_5D4594[754036]);
    }
    return result;
}

//----- (0042E600) --------------------------------------------------------
char* sub_42E600()
{
    sub_413A00(0);
    return sub_4DB790("AUTOSAVE");
}

//----- (0042E620) --------------------------------------------------------
int sub_42E620()
{
    return sub_413A00(0);
}

//----- (0042E630) --------------------------------------------------------
int sub_42E630()
{
    char* v0; // eax
    int result; // eax

    v0 = (char*)sub_416640();
    switch (*(_DWORD*)(v0 + 66))
    {
        case 1:
            result = sub_554290();
            break;
        case 2:
            result = sub_554300();
            break;
        case 3:
            result = *(_DWORD*)(v0 + 70);
            break;
        default:
            result = 0;
            break;
    }
    return result;
}
// 42E644: control flows out of bounds to 554290
// 42E649: control flows out of bounds to 554300

//----- (0042E670) --------------------------------------------------------
void __cdecl sub_42E670(int a1, int a2)
{
    bool v2; // zf
    int result; // eax
    int v4; // ecx
    int v5; // eax

    v2 = !sub_40A5C0(1);
    result = *(_DWORD*)& byte_5D4594[754036];
    if (v2)
    {
        if (*(int*)& byte_5D4594[754036] >= 128)
            return;
    }
    else
    {
        result = *(_DWORD*)& byte_5D4594[754036] + 1;
        if (*(_DWORD*)& byte_5D4594[754036] + 1 == *(_DWORD*)& byte_5D4594[754040])
            return;
    }
    if (byte_5D4594[2661958] || (result = sub_42D460(a1)) == 0)
    {
        if (sub_40A5C0(1) && sub_42D4B0(a1))
        {
            result = *(_DWORD*)& byte_5D4594[754040];
            v4 = *(_DWORD*)& byte_5D4594[754036];
            if (*(_DWORD*)& byte_5D4594[754040] != *(_DWORD*)& byte_5D4594[754036])
            {
                while (*(_DWORD*)& byte_5D4594[24 * result + 747892] != a1)
                {
                    result = (result + 1) % 128;
                    if (result == *(_DWORD*)& byte_5D4594[754036])
                        goto LABEL_14;
                }
                return;
            }
        }
        else
        {
            v4 = *(_DWORD*)& byte_5D4594[754036];
        }
        LABEL_14:
        v5 = 24 * v4;
        *(_DWORD*)& byte_5D4594[v5 + 747884] = *(_DWORD*)& byte_5D4594[747876];
        *(_DWORD*)& byte_5D4594[v5 + 747888] = *(_DWORD*)& byte_5D4594[747880];
        *(_DWORD*)& byte_5D4594[v5 + 747892] = a1;
        *(_DWORD*)& byte_5D4594[v5 + 747900] = 1;
        *(_DWORD*)& byte_5D4594[v5 + 747896] = a2;
        *(_DWORD*)& byte_5D4594[754036] = v4 + 1;
        if (sub_40A5C0(1))
        {
            *(_DWORD*)& byte_5D4594[754036] %= 128;
        }
    }
}

//----- (0042E780) --------------------------------------------------------
void __cdecl sub_42E780(int a1, int a2)
{
    if (*(_DWORD*)& byte_5D4594[2614252] && !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[2614252] + 120) & 2))
    {
        int result = sub_413A50();
        if (!result)
            sub_42E670(a1, a2);
    }
}

//----- (0042E7B0) --------------------------------------------------------
void __cdecl sub_42E7B0(int a1)
{
    int v1; // esi
    __int16 v2; // ax

    v1 = a1;
    if (a1
        && (!*(_DWORD*)& byte_5D4594[2618908] || !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 3))
        && sub_478030() != 1
        && sub_446360() != 1)
    {
        v2 = *(_WORD*)(v1 + 128);
        LOWORD(a1) = 464;
        HIWORD(a1) = v2;
        sub_40EBC0(31, 0, &a1, 4);
    }
}

//----- (0042E810) --------------------------------------------------------
void __cdecl sub_42E810(int a1)
{
    int v1; // [esp-4h] [ebp-4h]

    if (a1 && (!*(_DWORD*)& byte_5D4594[2618908] || !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 3)))
    {
        v1 = a1;
        LOBYTE(a1) = 123;
        *(_WORD*)((char*)& a1 + 1) = sub_578B00(v1);
        sub_40EBC0(31, 0, &a1, 3);
    }
}

//----- (0042E850) --------------------------------------------------------
void __cdecl sub_42E850(int a1)
{
    int v1; // esi

    v1 = a1;
    if (a1
        && (!*(_DWORD*)& byte_5D4594[2618908] || !(*(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 3))
        && sub_47A260() != 1
        && sub_446360() != 1)
    {
        LOWORD(a1) = 5577;
        HIWORD(a1) = sub_578B00(v1);
        sub_40EBC0(31, 0, &a1, 4);
    }
}

//----- (0042E8C0) --------------------------------------------------------
void __cdecl sub_42E8C0(int a1)
{
    nullsub_33(a1, &byte_5D4594[747884], *(_DWORD*)& byte_5D4594[754036]);
}
// 42E8B0: using guessed type void __cdecl nullsub_33(_DWORD, _DWORD, _DWORD);

//----- (0042E8E0) --------------------------------------------------------
char* __cdecl sub_42E8E0(int a1, int a2)
{
    _DWORD* v2; // esi
    int v3; // ebp
    int v4; // edi
    _DWORD* v5; // ebx
    int v6; // ecx
    unsigned __int8* v7; // eax

    v2 = *(_DWORD * *)& byte_5D4594[754056];
    if (!*(_DWORD*)& byte_5D4594[754056])
        return (char*)& byte_5D4594[754072];
    while (1)
    {
        v3 = v2[17];
        v4 = 0;
        if (v3 > 0)
            break;
        LABEL_11:
        v2 = (_DWORD*)v2[19];
        if (!v2)
            return (char*)& byte_5D4594[754072];
    }
    v5 = v2 + 9;
    while (1)
    {
        if (*v5 == a1 && --a2 <= 0)
        {
            v6 = 0;
            if (*(_DWORD*)& byte_587000[73672])
                break;
        }
        LABEL_10:
        ++v4;
        ++v5;
        if (v4 >= v3)
            goto LABEL_11;
    }
    v7 = &byte_587000[73672];
    while (*v2 != *((_DWORD*)v7 + 1))
    {
        v7 += 16;
        ++v6;
        if (!*(_DWORD*)v7)
            goto LABEL_10;
    }
    return *(char**)& byte_587000[16 * v6 + 73684];
}

//----- (0042E960) --------------------------------------------------------
char* __cdecl sub_42E960(wchar_t* a1)
{
    int v1; // edi
    unsigned __int8* i; // esi
    int v3; // eax

    v1 = 0;
    if (!*(_DWORD*)& byte_587000[73672])
        return 0;
    for (i = &byte_587000[73672]; _nox_wcsicmp(*((const wchar_t**)i + 3), a1); i += 16)
    {
        v3 = *((_DWORD*)i + 4);
        ++v1;
        if (!v3)
            return 0;
    }
    return *(char**)& byte_587000[16 * v1 + 73672];
}

//----- (0042E9B0) --------------------------------------------------------
char* __cdecl sub_42E9B0(char* a1)
{
    int v1; // edi
    const char** v2; // eax
    unsigned __int8* v3; // esi
    int v4; // ecx

    v1 = 0;
    if (!*(_DWORD*)& byte_587000[73672])
        return (char*)& byte_5D4594[754076];
    v2 = (const char**)& byte_587000[73672];
    v3 = &byte_587000[73672];
    while (_strcmpi(*v2, a1))
    {
        v4 = *((_DWORD*)v3 + 4);
        v3 += 16;
        ++v1;
        v2 = (const char**)v3;
        if (!v4)
            return (char*)& byte_5D4594[754076];
    }
    return *(char**)& byte_587000[16 * v1 + 73684];
}

//----- (0042EA00) --------------------------------------------------------
char* __cdecl sub_42EA00(char* a1)
{
    int v1; // ecx
    unsigned __int8* i; // eax
    int v3; // esi

    v1 = 0;
    if (!*(_DWORD*)& byte_587000[73672])
        return (char*)& byte_5D4594[754080];
    for (i = &byte_587000[73672]; *((char**)i + 1) != a1; i += 16)
    {
        v3 = *((_DWORD*)i + 4);
        ++v1;
        if (!v3)
            return (char*)& byte_5D4594[754080];
    }
    return *(char**)& byte_587000[16 * v1 + 73684];
}

//----- (0042EA40) --------------------------------------------------------
int __cdecl sub_42EA40(wchar_t* a1)
{
    int v1; // edi
    unsigned __int8* i; // esi
    int v3; // eax

    v1 = 0;
    if (!*(_DWORD*)& byte_587000[75880])
        return 0;
    for (i = &byte_587000[75880]; _nox_wcsicmp(*((const wchar_t**)i + 2), a1); i += 12)
    {
        v3 = *((_DWORD*)i + 3);
        ++v1;
        if (!v3)
            return 0;
    }
    return *(_DWORD*)& byte_587000[12 * v1 + 75880];
}

//----- (0042EA90) --------------------------------------------------------
char* __cdecl sub_42EA90(char* a1)
{
    int v1; // edi
    const char** v2; // eax
    unsigned __int8* v3; // esi
    int v4; // ecx

    v1 = 0;
    if (!*(_DWORD*)& byte_587000[75880])
        return (char*)& byte_5D4594[754084];
    v2 = (const char**)& byte_587000[75880];
    v3 = &byte_587000[75880];
    while (_strcmpi(*v2, a1))
    {
        v4 = *((_DWORD*)v3 + 3);
        v3 += 12;
        ++v1;
        v2 = (const char**)v3;
        if (!v4)
            return (char*)& byte_5D4594[754084];
    }
    return *(char**)& byte_587000[12 * v1 + 75888];
}

//----- (0042EAE0) --------------------------------------------------------
char* sub_42EAE0()
{
    unsigned __int8* v0; // esi
    int v1; // eax
    char* result; // eax
    unsigned __int8* v3; // esi
    char v4[256]; // [esp+4h] [ebp-100h]

    if (*(_DWORD*)& byte_587000[73672])
    {
        v0 = &byte_587000[73684];
        do
        {
            *(_DWORD*)v0 = loadString_sub_40F1D0(*((char**)v0 - 1), 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2092);
            v1 = *((_DWORD*)v0 + 1);
            v0 += 16;
        } while (v1);
    }
    *(_DWORD*)& byte_587000[75888] = loadString_sub_40F1D0((char*)& byte_587000[80484], 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2095);
    result = *(char**)& byte_587000[75892];
    if (*(_DWORD*)& byte_587000[75892])
    {
        v3 = &byte_587000[75892];
        do
        {
            nox_sprintf(v4, "bindevent:%s", result);
            *((_DWORD*)v3 + 2) = loadString_sub_40F1D0(v4, 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2100);
            result = (char*) * ((_DWORD*)v3 + 3);
            v3 += 12;
        } while (result);
    }
    return result;
}

//----- (0042EB90) --------------------------------------------------------
int __cdecl sub_42EB90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[754052] = a1;
    return result;
}

//----- (0042EBA0) --------------------------------------------------------
int sub_42EBA0()
{
    return *(_DWORD*)& byte_5D4594[754052];
}

//----- (0042EBB0) --------------------------------------------------------
void __cdecl sub_42EBB0(unsigned int a1, void (*fnc)(int), int field_4, const char* name)
{
    wchar_t* v6; // eax
    wchar_t* v8; // eax

    if (a1 == 1)
    {
        obj_5D4594_754088_t* arr = (obj_5D4594_754088_t*)realloc(ptr_5D4594_754088, sizeof(obj_5D4594_754088_t) * (ptr_5D4594_754088_cnt + 1));
        ptr_5D4594_754088 = arr;
        if (!arr)
        {
            v6 = loadString_sub_40F1D0((char*)& byte_587000[80600], 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\focus.c", 37);
            sub_4516C0(v6);
            nox_exit(-1);
        }
        arr[ptr_5D4594_754088_cnt].fnc = fnc;
        arr[ptr_5D4594_754088_cnt].field_4 = field_4;
        strcpy(arr[ptr_5D4594_754088_cnt].name, name);
        ++ptr_5D4594_754088_cnt;
    }
    else if (a1 == 2)
    {
        obj_5D4594_754088_t* arr = realloc(ptr_5D4594_754092, sizeof(obj_5D4594_754088_t) * (ptr_5D4594_754092_cnt + 1));
        ptr_5D4594_754092 = arr;
        if (!arr)
        {
            v8 = loadString_sub_40F1D0((char*)& byte_587000[80656], 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\focus.c", 52);
            sub_4516C0(v8);
            nox_exit(-1);
        }
        arr[ptr_5D4594_754092_cnt].fnc = fnc;
        arr[ptr_5D4594_754092_cnt].field_4 = field_4;
        int sz = strlen(name) + 1;
        qmemcpy(arr[ptr_5D4594_754092_cnt].name, name, sz);
        ++ptr_5D4594_754092_cnt;
    }
}

//----- (0042ED20) --------------------------------------------------------
void sub_42ED20()
{
    if (!obj_5D4594_754104_switch)
    {
        return;
    }
    obj_5D4594_754104_switch = 0;
    if (!ptr_5D4594_754088)
    {
        return;
    }
    for (int i = 0; i < ptr_5D4594_754088_cnt; i++)
    {
        obj_5D4594_754088_t* cur = &ptr_5D4594_754088[i];
        cur->fnc(cur->field_4);
    }
}

//----- (0042ED70) --------------------------------------------------------
void sub_42ED70()
{
    if (obj_5D4594_754104_switch)
    {
        return;
    }
    obj_5D4594_754104_switch = 1;
    if (!ptr_5D4594_754092)
    {
        return;
    }
    for (int i = 0; i < ptr_5D4594_754092_cnt; i++)
    {
        obj_5D4594_754088_t* cur = &ptr_5D4594_754092[i];
        cur->fnc(cur->field_4);
    }
}

//----- (0042EDC0) --------------------------------------------------------
void sub_42EDC0()
{
    if (ptr_5D4594_754088)
    {
        free(ptr_5D4594_754088);
        ptr_5D4594_754088 = 0;
    }
    if (ptr_5D4594_754092)
    {
        free(ptr_5D4594_754092);
        ptr_5D4594_754092 = 0;
    }
}

//----- (0042EE00) --------------------------------------------------------
int sub_42EE00()
{
    unsigned __int8* v0; // ecx
    int result; // eax
    int v2; // esi

    v0 = *(unsigned __int8**)& byte_5D4594[787200];
    result = 0;
    if (*(_DWORD*)& byte_5D4594[787200] && *(_DWORD*)& byte_5D4594[787216])
    {
        v2 = *(_DWORD*)& byte_5D4594[787216];
        do
        {
            result += *v0++;
            --v2;
        } while (v2);
    }
    return result;
}

//----- (0042EE30) --------------------------------------------------------
int __cdecl sub_42EE30(int a1)
{
    char* v1; // eax
    int result; // eax
    int* v3; // eax
    int* v4; // esi
    int v5; // eax
    unsigned __int8* v6; // edi
    int v7; // eax
    signed int v8; // [esp-4h] [ebp-40h]
    char v9[20]; // [esp+8h] [ebp-34h]

    *(_DWORD*)& byte_5D4594[787144] = 0;
    v1 = sub_430100(a1);
    result = (int)fopen(v1, "rb");
    nox_file_6 = result;
    if (result)
    {
        v3 = (int*)sub_42F0B0(a1);
        v4 = v3;
        if (v3)
        {
            v5 = sub_42F1B0(v3, (int*)v9);
            if (v5)
            {
                v6 = (unsigned __int8*)v4 + v5;
                *(_DWORD*)& byte_5D4594[787168] = *(_DWORD*)& v9[16];
                *(_DWORD*)& byte_5D4594[787172] = *(_DWORD*)& v9[12];
                *(_DWORD*)& byte_5D4594[787184] = *(_DWORD*)& v9[4];
                if (*(_DWORD*)& byte_5D4594[787208])
                {
                    free(*(LPVOID*)& byte_5D4594[787208]);
                    *(_DWORD*)& byte_5D4594[787208] = 0;
                }
                if (*(_DWORD*)& byte_5D4594[754144])
                    * (_DWORD*)& byte_5D4594[787208] = nox_malloc(*(size_t*)& byte_5D4594[787184]);
                if (!*(_DWORD*)& byte_5D4594[787212])
                    * (_DWORD*)& byte_5D4594[787212] = sub_578BF0();
                if (*(_DWORD*)& byte_5D4594[2650640] == 1)
                    sub_47A270();
                *(_DWORD*)& byte_5D4594[787148] = nox_malloc(36 * *(_DWORD*)& byte_5D4594[787172]);
                *(_DWORD*)& byte_5D4594[787152] = nox_malloc(12 * *(_DWORD*)& byte_5D4594[787168]);
                sub_42F200(v6, a1);
                free(v4);
                v7 = 0x800000;
                if (*(_DWORD*)& v9[4] * *(_DWORD*)& byte_5D4594[787172] < 0x800000)
                    v7 = *(_DWORD*)& v9[4] * *(_DWORD*)& byte_5D4594[787172];
                v8 = *(_DWORD*)& v9[4] * (v7 / *(_DWORD*)& v9[4]);
                *(_DWORD*)& byte_5D4594[787192] = v8 / *(_DWORD*)& v9[4];
                result = (int)nox_malloc(v8);
                *(_DWORD*)& byte_5D4594[787200] = result;
                if (result)
                {
                    *(_DWORD*)& byte_5D4594[3807164] = &byte_5D4594[754148];
                    *(_DWORD*)& byte_5D4594[787144] = 1;
                    sub_42EFF0();
                    result = 1;
                }
            }
            else
            {
                free(v4);
                fclose(nox_file_6);
                result = 0;
            }
        }
        else
        {
            fclose(nox_file_6);
            result = 0;
        }
    }
    return result;
}

//----- (0042EFF0) --------------------------------------------------------
int sub_42EFF0()
{
    int result; // eax

    sub_42F030();
    if (*(_DWORD*)& byte_5D4594[3804680])
    {
        result = *(_DWORD*)& byte_5D4594[787192];
        *(_DWORD*)& byte_5D4594[787176] = *(_DWORD*)& byte_5D4594[787184];
    }
    else
    {
        result = *(_DWORD*)& byte_5D4594[787180];
        *(_DWORD*)& byte_5D4594[787176] = *(_DWORD*)& byte_5D4594[787180];
    }
    *(_DWORD*)& byte_5D4594[787188] = *(_DWORD*)& byte_5D4594[787192];
    return result;
}

//----- (0042F030) --------------------------------------------------------
char* sub_42F030()
{
    char* result; // eax
    int v1; // edi
    int v2; // esi

    result = *(char**)& byte_5D4594[787172];
    v1 = 0;
    if (*(_DWORD*)& byte_5D4594[787172] > 0)
    {
        result = *(char**)& byte_5D4594[787148];
        v2 = 0;
        do
        {
            if (*(_DWORD*)& result[v2])
            {
                if (*(int*)& result[v2 + 24] == -1)
                {
                    free(*(LPVOID*)& result[v2]);
                    result = *(char**)& byte_5D4594[787148];
                }
                *(_DWORD*)& result[v2] = 0;
                result = *(char**)& byte_5D4594[787148];
            }
            ++v1;
            v2 += 36;
        } while (v1 < *(int*)& byte_5D4594[787172]);
    }
    *(_DWORD*)& byte_5D4594[787136] = 0;
    *(_DWORD*)& byte_5D4594[787140] = &byte_5D4594[754108];
    *(_DWORD*)& byte_5D4594[754136] = &byte_5D4594[787108];
    *(_DWORD*)& byte_5D4594[754140] = 0;
    return result;
}

//----- (0042F0B0) --------------------------------------------------------
FILE* __cdecl sub_42F0B0(int a1)
{
    char* v1; // eax
    FILE* result; // eax
    FILE* v3; // esi
    char* v4; // edi
    signed int v5; // eax
    size_t v6; // [esp+8h] [ebp-8h]
    int v7; // [esp+Ch] [ebp-4h]

    v6 = 0;
    v7 = 0;
    v1 = sub_430120(a1);
    result = fopen(v1, "rb");
    v3 = result;
    if (result)
    {
        sub_40ADD0_fread((char*)& v7, 4u, 1u, result);
        *(_DWORD*)& byte_5D4594[754144] = 0;
        if (v7 == -85082901)
        {
            *(_DWORD*)& byte_5D4594[754144] = 1;
        }
        else if (v7 != -85082902)
        {
            fclose(v3);
            return 0;
        }
        sub_40ADD0_fread((char*)& v6, 4u, 1u, v3);
        v4 = (char*)nox_malloc(v6);
        if (v4)
        {
            fseek(v3, 0, 0);
            v5 = sub_40ADD0_fread(v4, 1u, v6, v3);
            if (v5 == v6)
            {
                fclose(v3);
                result = (FILE*)v4;
            }
            else
            {
                fclose(v3);
                result = 0;
            }
        }
        else
        {
            fclose(v3);
            result = 0;
        }
    }
    return result;
}

//----- (0042F1B0) --------------------------------------------------------
int __cdecl sub_42F1B0(int* a1, int* a2)
{
    int v2; // edx
    bool v3; // zf

    v2 = *a1;
    v3 = *a1 == -85082902;
    *a2 = *a1;
    if (!v3 && v2 != -85082901)
        return 0;
    a2[3] = a1[2];
    a2[1] = a1[3];
    a2[2] = a1[4];
    a2[4] = a1[5];
    return 24;
}

//----- (0042F200) --------------------------------------------------------
int __cdecl sub_42F200(unsigned __int8* a1, int a2)
{
unsigned __int8* v2; // ecx
int result; // eax
int v4; // esi
int v5; // ebx
_DWORD* v6; // ecx
int v7; // edx
int v8; // edi
int v9; // ebp
int v10; // ebx
int v11; // edx
unsigned __int8* v12; // ecx
unsigned __int8 v13; // al
_DWORD* v14; // ecx
int v15; // edi
int v16; // [esp+0h] [ebp-Ch]
int v17; // [esp+4h] [ebp-8h]
int v18; // [esp+8h] [ebp-4h]
int v19; // [esp+10h] [ebp+4h]

v2 = a1;
result = 0;
v17 = 0;
v16 = 0;
*(_DWORD*)& byte_5D4594[787180] = 0;
v19 = 0;
if (*(_DWORD*)& byte_5D4594[787172] > 0)
{
v4 = 0;
do
{
v5 = *((_DWORD*)v2 + 1);
v6 = v2 + 8;
if (*(_DWORD*)& byte_5D4594[754144])
{
v7 = *v6;
++v6;
}
else
{
v7 = v5;
}
v8 = *v6;
v2 = (unsigned __int8*)(v6 + 1);
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148]) = 0;
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148] + 4) = 0;
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148] + 8) = v16;
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148] + 12) = v5;
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148] + 16) = v7;
result = v17;
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148] + 20) = v17;
*(_DWORD*)(v4 + *(_DWORD*)& byte_5D4594[787148] + 24) = v8;
v16 += v7;
if (v8 == -1)
{
v8 = 1;
}
else if (v5 > * (int*)& byte_5D4594[787180])
{
*(_DWORD*)& byte_5D4594[787180] = v5;
}
v9 = 0;
if (v8 <= 0)
{
v10 = v19;
}
else
{
v10 = v19;
v11 = 12 * v17;
v18 = v8;
v17 += v8;
do
{
*(_WORD*)(v11 + *(_DWORD*)& byte_5D4594[787152] + 8) = v19;
v12 = &v2[*v2 + 1];
v13 = *v12;
v14 = v12 + 1;
*(_BYTE*)(v11 + *(_DWORD*)& byte_5D4594[787152] + 10) = v13;
if (a2 == 1)
v15 = *v14;
else
v15 = v14[1];
v2 = (unsigned __int8*)(v14 + 2);
v11 += 12;
*(_DWORD*)(v11 + *(_DWORD*)& byte_5D4594[787152] - 12) = v9;
v9 += v15;
--v18;
} while (v18);
result = v17;
}
v4 += 36;
v19 = v10 + 1;
} while (v10 + 1 < *(int*)& byte_5D4594[787172]);
}
if (*(_DWORD*)& byte_5D4594[787180] > * (int*)& byte_5D4594[787184])
* (_DWORD*)& byte_5D4594[787180] = *(_DWORD*)& byte_5D4594[787184];
return result;
}

//----- (0042F370) --------------------------------------------------------
int __cdecl sub_42F370(int a1)
{
    int result; // eax
    char* v2; // eax
    int* v3; // eax
    int* v4; // esi
    int v5; // eax
    unsigned __int8* v6; // ebx
    char v7[20]; // [esp+8h] [ebp-14h]

    if (!nox_file_6)
        return 1;
    *(_DWORD*)& byte_5D4594[787144] = 0;
    v2 = sub_430100(a1);
    if (a1 != *(_DWORD*)& byte_587000[80720])
    {
        *(_DWORD*)& byte_587000[80720] = a1;
        sub_42F490(v2);
    }
    sub_42F030();
    v3 = (int*)sub_42F0B0(a1);
    v4 = v3;
    if (v3)
    {
        v5 = sub_42F1B0(v3, (int*)v7);
        if (v5)
        {
            v6 = (unsigned __int8*)v4 + v5;
            if (*(_DWORD*)& byte_5D4594[2650640] == 1)
                sub_47A270();
            sub_42F200(v6, a1);
            free(v4);
            if (*(_DWORD*)& byte_5D4594[787208])
            {
                free(*(LPVOID*)& byte_5D4594[787208]);
                *(_DWORD*)& byte_5D4594[787208] = 0;
            }
            if (*(_DWORD*)& byte_5D4594[754144])
                * (_DWORD*)& byte_5D4594[787208] = nox_malloc(*(size_t*)& byte_5D4594[787184]);
            sub_42EFF0();
            result = 1;
            *(_DWORD*)& byte_5D4594[787144] = 1;
        }
        else
        {
            free(v4);
            fclose(nox_file_6);
            result = 0;
        }
    }
    else
    {
        fclose(nox_file_6);
        result = 0;
    }
    return result;
}

//----- (0042F490) --------------------------------------------------------
BOOL __cdecl sub_42F490(char* a1)
{
    if (nox_file_6)
        fclose(nox_file_6);
    nox_file_6 = fopen(a1, "rb");
    return nox_file_6 != 0;
}

//----- (0042F4D0) --------------------------------------------------------
void sub_42F4D0()
{
    _BYTE* v0; // eax
    int v1; // edi
    int v2; // esi

    *(_DWORD*)& byte_5D4594[787144] = 0;
    sub_42F030();
    if (*(_DWORD*)& byte_5D4594[787200])
    {
        free(*(LPVOID*)& byte_5D4594[787200]);
        *(_DWORD*)& byte_5D4594[787200] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[787148])
    {
        free(*(LPVOID*)& byte_5D4594[787148]);
        *(_DWORD*)& byte_5D4594[787148] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[787152])
    {
        free(*(LPVOID*)& byte_5D4594[787152]);
        *(_DWORD*)& byte_5D4594[787152] = 0;
    }
    v0 = *(_BYTE * *)& byte_5D4594[787156];
    if (*(_DWORD*)& byte_5D4594[787156])
    {
        v1 = 0;
        if (*(_DWORD*)& byte_5D4594[787164] > 0)
        {
            v2 = 0;
            do
            {
                if (v0[v2 + 101] == 2)
                {
                    free(*(LPVOID*)(*(_DWORD*)& v0[v2 + 96] + 4));
                    free(*(LPVOID*)(v2 + *(_DWORD*)& byte_5D4594[787156] + 96));
                    v0 = *(_BYTE * *)& byte_5D4594[787156];
                }
                ++v1;
                v2 += 104;
            } while (v1 < *(int*)& byte_5D4594[787164]);
        }
        free(v0);
        *(_DWORD*)& byte_5D4594[787156] = 0;
        *(_DWORD*)& byte_5D4594[787160] = 0;
        *(_DWORD*)& byte_5D4594[787164] = 0;
    }
    *(_DWORD*)& byte_5D4594[787192] = 0;
    *(_DWORD*)& byte_5D4594[787188] = 0;
    *(_DWORD*)& byte_5D4594[787136] = 0;
    *(_DWORD*)& byte_5D4594[787140] = &byte_5D4594[754108];
    *(_DWORD*)& byte_5D4594[754136] = &byte_5D4594[787108];
    *(_DWORD*)& byte_5D4594[754140] = 0;
    sub_47D150();
    fclose(nox_file_6);
    nox_file_6 = 0;
    if (*(_DWORD*)& byte_5D4594[787212])
    {
        sub_578C40(*(LPVOID*)& byte_5D4594[787212]);
        *(_DWORD*)& byte_5D4594[787212] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[787208])
    {
        free(*(LPVOID*)& byte_5D4594[787208]);
        *(_DWORD*)& byte_5D4594[787208] = 0;
    }
}

//----- (0042F610) --------------------------------------------------------
int __cdecl sub_42F610(int a1)
{
    int result; // eax

    if (a1 < 0)
        return 0;
    result = (int)nox_malloc(104 * a1);
    *(_DWORD*)& byte_5D4594[787156] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[787160] = a1;
        *(_DWORD*)& byte_5D4594[787164] = 0;
        result = 1;
    }
    return result;
}

//----- (0042F660) --------------------------------------------------------
int __cdecl sub_42F660(int a1, void* a2)
{
    int v2; // ebp
    void* v3; // ebx
    unsigned __int8* v4; // eax
    char* v5; // eax
    char v6; // cl
    _DWORD* v7; // eax
    int v8; // edi
    char* v9; // eax
    char v10; // cl
    unsigned __int8* v11; // eax
    _DWORD* v12; // eax
    _DWORD* v13; // ebx
    unsigned __int8* v14; // eax
    void* v15; // eax
    char* v16; // eax
    char v17; // cl
    unsigned __int8* v18; // eax
    int v19; // edi
    _DWORD* v20; // eax
    int v21; // ecx
    char* v22; // eax
    char v23; // cl
    unsigned __int8* v24; // eax
    int v26; // [esp-4h] [ebp-28h]
    int v27; // [esp+10h] [ebp-14h]
    char v28[16]; // [esp+14h] [ebp-10h]
    unsigned __int8 v29; // [esp+28h] [ebp+4h]
    unsigned __int8 v30; // [esp+28h] [ebp+4h]
    unsigned __int8 v31; // [esp+28h] [ebp+4h]
    unsigned __int8 v32; // [esp+28h] [ebp+4h]
    unsigned __int8 v33; // [esp+2Ch] [ebp+8h]

    if (*(_DWORD*)& byte_5D4594[787164] < *(int*)& byte_5D4594[787160])
    {
        v2 = a1;
        v3 = a2;
        v26 = a1;
        v4 = *(unsigned __int8**)(a1 + 8);
        v29 = *v4;
        *(_DWORD*)(v26 + 8) = v4 + 1;
        sub_40ACC0(a2, 1u, v29, v26);
        *((_BYTE*)a2 + v29) = 0;
        strcpy((char*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164]), (const char*)a2);
        v5 = *(char**)(v2 + 8);
        v6 = *v5;
        *(_DWORD*)(v2 + 8) = v5 + 1;
        *(_BYTE*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164] + 101) = v6;
        if (v6 == 1)
        {
            v7 = *(_DWORD * *)(v2 + 8);
            v8 = *v7;
            v9 = (char*)(v7 + 1);
            *(_DWORD*)(v2 + 8) = v9;
            if (v8 == -1)
            {
                v10 = *v9;
                v11 = (unsigned __int8*)(v9 + 1);
                *(_DWORD*)(v2 + 8) = v11;
                v30 = *v11;
                LOBYTE(a2) = v10;
                *(_DWORD*)(v2 + 8) = v11 + 1;
                sub_40ACC0(v3, 1u, v30, v2);
                *((_BYTE*)v3 + v30) = 0;
                if (sub_47A8C0((const char*)a2, (char*)v3))
                {
                    strcpy(
                            (char*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164] + 32),
                            (const char*)v3);
                    v8 = -1;
                    *(_BYTE*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164] + 100) = (_BYTE)a2;
                }
                else
                {
                    *(_BYTE*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164] + 100) = -1;
                }
            }
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164] + 96) = v8;
            LABEL_22:
            ++* (_DWORD*)& byte_5D4594[787164];
            return 1;
        }
        if (v6 == 2)
        {
            v12 = nox_malloc(0x10u);
            v13 = v12;
            if (v12)
            {
                *v12 = 0;
                v14 = *(unsigned __int8**)(v2 + 8);
                v33 = *v14;
                *(_DWORD*)(v2 + 8) = v14 + 1;
                *((_BYTE*)v13 + 8) = v33;
                v27 = v33;
                v15 = nox_malloc(4 * v33);
                v13[1] = v15;
                if (v15)
                {
                    v16 = *(char**)(v2 + 8);
                    v17 = *v16;
                    *(_DWORD*)(v2 + 8) = v16 + 1;
                    *((_BYTE*)v13 + 9) = v17;
                    v18 = *(unsigned __int8**)(v2 + 8);
                    v31 = *v18;
                    *(_DWORD*)(v2 + 8) = v18 + 1;
                    sub_40ACC0(v28, 1u, v31, v2);
                    v28[v31] = 0;
                    if (!strcmp(v28, "OneShot"))
                    {
                        *((_BYTE*)v13 + 10) = 0;
                        LABEL_15:
                        if (v33)
                        {
                            v19 = 0;
                            do
                            {
                                v20 = *(_DWORD * *)(v2 + 8);
                                v21 = *v20;
                                v22 = (char*)(v20 + 1);
                                *(_DWORD*)(v2 + 8) = v22;
                                if (v21 == -1)
                                {
                                    v23 = *v22;
                                    v24 = (unsigned __int8*)(v22 + 1);
                                    *(_DWORD*)(v2 + 8) = v24;
                                    v32 = *v24;
                                    *(_DWORD*)(v2 + 8) = v24 + 1;
                                    LOBYTE(a2) = v23;
                                    sub_40ACC0(v28, 1u, v32, v2);
                                    v28[v32] = 0;
                                    *(_DWORD*)(v13[1] + v19) = sub_47A8C0((const char*)a2, v28);
                                }
                                else
                                {
                                    *(_DWORD*)(v13[1] + v19) = *(_DWORD*)& byte_5D4594[787152] + 12 * v21;
                                }
                                v19 += 4;
                                --v27;
                            } while (v27);
                        }
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[787156] + 104 * *(_DWORD*)& byte_5D4594[787164] + 96) = v13;
                        goto LABEL_22;
                    }
                    if (!strcmp(v28, "Loop"))
                    {
                        *((_BYTE*)v13 + 10) = 2;
                        goto LABEL_15;
                    }
                }
            }
        }
    }
    return 0;
}
// 42F660: using guessed type char var_10[16];

//----- (0042F970) --------------------------------------------------------
char* __cdecl sub_42F970(const char* a1)
{
    int v1; // edi
    const char* i; // ebp
    int v4; // eax
    const char* v5; // ecx

    if (!a1)
        return 0;
    v1 = 0;
    if (*(int*)& byte_5D4594[787164] <= 0)
        return 0;
    for (i = *(const char**)& byte_5D4594[787156]; strcmp(a1, i); i += 104)
    {
        if (++v1 >= *(int*)& byte_5D4594[787164])
            return 0;
    }
    v4 = *(_DWORD*)& byte_5D4594[787156] + 104 * v1;
    v5 = *(const char**)(v4 + 96);
    if (v5 == (const char*)-1)
    {
        LOBYTE(v5) = *(_BYTE*)(v4 + 100);
        if ((_BYTE)v5 != (_BYTE)-1)
            return sub_47A8C0(v5, (char*)(v4 + 32));
        return 0;
    }
    return (char*)(*(_DWORD*)& byte_5D4594[787152] + 12 * (_DWORD)v5);
}

//----- (0042FA20) --------------------------------------------------------
char* __cdecl sub_42FA20(const char* a1)
{
    int v1; // edi
    const char* i; // ebp

    if (!a1)
        return 0;
    v1 = 0;
    if (*(int*)& byte_5D4594[787164] <= 0)
        return 0;
    for (i = *(const char**)& byte_5D4594[787156]; strcmp(a1, i); i += 104)
    {
        if (++v1 >= *(int*)& byte_5D4594[787164])
            return 0;
    }
    return (char*)(*(_DWORD*)& byte_5D4594[787156] + 104 * v1);
}

//----- (0042FAA0) --------------------------------------------------------
char* __cdecl sub_42FAA0(int a1, const char* a2, char* a3)
{
    char* result; // eax

    if (a1 == -1)
        result = sub_47A8C0(a2, a3);
    else
        result = (char*)(*(_DWORD*)& byte_5D4594[787152] + 12 * a1);
    return result;
}

//----- (0042FAD0) --------------------------------------------------------
int sub_42FAD0()
{
    return 0;
}

//----- (0042FAE0) --------------------------------------------------------
_DWORD* __cdecl sub_42FAE0(int a1)
{
    _DWORD* result; // eax

    result = (_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8));
    if (result[6] == -1)
    {
        result = (_DWORD*)* result;
        if (result)
        {
            free(result);
            result = *(_DWORD * *)& byte_5D4594[787148];
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8)) = 0;
        }
    }
    return result;
}

//----- (0042FB30) --------------------------------------------------------
int __cdecl sub_42FB30(int a1)
{
    int v2; // ecx
    int* v3; // eax
    int v4; // edx
    _DWORD* v5; // ecx
    _DWORD* v6; // eax

    if (*(_DWORD*)& byte_5D4594[787224])
        return 0;
    if (!a1)
        return 0;
    if ((*(_BYTE*)(a1 + 10) & 0x3F) == 7)
        return sub_42FAD0();
    if (*(_BYTE*)(a1 + 10) & 0x80)
        return *(_DWORD*)a1;
    v2 = *(_DWORD*)& byte_5D4594[787148];
    *(_DWORD*)& byte_5D4594[787224] = 1;
    v3 = (int*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8));
    v4 = *v3;
    if (v3[6] != -1)
    {
        if (v4)
        {
            if (v3[1] == *(_DWORD*)& byte_5D4594[2598000])
            {
                LABEL_19:
                *(_DWORD*)& byte_5D4594[787224] = 0;
                return *(_DWORD*)a1 + *(_DWORD*)(v2 + 36 * *(unsigned __int16*)(a1 + 8));
            }
            v3[1] = *(_DWORD*)& byte_5D4594[2598000];
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 28) + 32) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 32);
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 32) + 28) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 28);
        }
        else
        {
            if (!*(_DWORD*)& byte_5D4594[787188])
            {
                v5 = *(_DWORD * *)& byte_5D4594[754136];
                ++* (_DWORD*)& byte_5D4594[787220];
                v6 = (_DWORD*)(*(_DWORD*)& byte_5D4594[754136] + 28);
                *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[754136] + 28) + 32) = &byte_5D4594[754108];
                *(_DWORD*)& byte_5D4594[754136] = *v6;
                *v6 = 0;
                v5[8] = 0;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[787140] + 28) = *(_DWORD*)& byte_5D4594[787148]
                                                                               + 36 * *(unsigned __int16*)(a1 + 8);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 28) = &byte_5D4594[787108];
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 32) = *(_DWORD*)& byte_5D4594[787140];
                *(_DWORD*)& byte_5D4594[787140] = *(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8);
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8)) = *v5;
                *v5 = 0;
                sub_42FE30(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8));
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 4) = *(_DWORD*)& byte_5D4594[2598000];
                *(_DWORD*)& byte_5D4594[787224] = 0;
                return *(_DWORD*)a1 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8));
            }
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8)) = *(_DWORD*)& byte_5D4594[787200]
                                                                                                          + -- * (_DWORD*)& byte_5D4594[787188]
                                                                                                                            * *(_DWORD*)& byte_5D4594[787176];
            sub_42FE30(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8));
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 4) = *(_DWORD*)& byte_5D4594[2598000];
        }
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[787140] + 28) = *(_DWORD*)& byte_5D4594[787148]
                                                                       + 36 * *(unsigned __int16*)(a1 + 8);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 28) = &byte_5D4594[787108];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 32) = *(_DWORD*)& byte_5D4594[787140];
        v2 = *(_DWORD*)& byte_5D4594[787148];
        *(_DWORD*)& byte_5D4594[787140] = *(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8);
        goto LABEL_19;
    }
    if (!v4)
    {
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8)) = nox_malloc(v3[3]);
        sub_42FE30(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8));
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[787148] + 36 * *(unsigned __int16*)(a1 + 8) + 4) = *(_DWORD*)& byte_5D4594[2598000];
        v2 = *(_DWORD*)& byte_5D4594[787148];
    }
    *(_DWORD*)& byte_5D4594[787224] = 0;
    return *(_DWORD*)(v2 + 36 * *(unsigned __int16*)(a1 + 8));
}

//----- (0042FE30) --------------------------------------------------------
const struct bag_file {
    unsigned int offset;
    unsigned int size;
    const char* path;
} bag_files[] = {
        { 0, 16780329, "video.bag.0" },
        { 16780329, 16784856, "video.bag.1" },
        { 33565185, 16784032, "video.bag.2" },
        { 50349217, 16785943, "video.bag.3" },
        { 67135160, 16780261, "video.bag.4" },
        { 83915421, 16787457, "video.bag.5" },
        { 100702878, 16784419, "video.bag.6" },
        { 117487297, 4419642, "video.bag.7" },
        { 0, 0, 0 },
};
FILE* bag_fp[8];

static FILE* get_bag(unsigned int offset)
{
    FILE* fp;
#ifdef __EMSCRIPTEN__0
    int i;
    for (i = 0; bag_files[i].path; i++)
    {
        if (bag_files[i].offset <= offset && offset - bag_files[i].offset < bag_files[i].size)
        {
            fp = bag_fp[i];
            if (fp == NULL)
                fp = bag_fp[i] = fopen(bag_files[i].path, "rb");
            fseek(fp, offset - bag_files[i].offset, 0);
        }
    }
#else
    fp = nox_file_6;
    fseek(fp, offset, 0);
#endif
    return fp;
}

static int preloaded[] = {
        3, 4, 17, 18, 438, 439, 575, 584, 586, 587, 588, 589, 590, 592, 593, 596, 597, 628, 629, 630, 631, 632, 708, 852, 853, 854, 856, 857, 858, 883, 884, 885, 886, 887, 888, 937, 938, 939, 941, 942, 943, 944, 1016, 1020, 1021, 1022, 1023, 1025, 1026, 1028, 1029, 1030, 1085, 1086, 1087, 1088, 1094, 1095, 1096, 1097, 1098, 1109, 1110, 1112, 1113, 1132, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143, 1144, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1171, 1172, 1173, 1175, 1178, 1179, 1180, 1182, 1206, 1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1249, 1250, 1251, 1252, 1256, 1257, 1262, 1263, 1265, 1272, 1274, 1275, 1276, 1277, 1349, 1351, 1352, 1358, 1359, 1360, 1361, 1377, 1378, 1429, 1433, 1434, 1445, 1478, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1533, 1534, 1535, 1536, 1692, 1693, 1703, 1704, 1705, 1706, 1707, 1708, 1724, 1725, 1726, 1727, 1743, 1744, 1745, 1746, 1748, 1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1763, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771, 1774, 1775, 1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785, 1786, 1787, 1790, 1791, 1792, 1793, 1794, 1795, 1796, 1797, 1798, 1799, 1800, 1801, 1802, 1803, 1804, 1805, 1806, 1807, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1818, 1819, 1820, 1824, 1825, 1826, 1828, 1829, 1830, 1831, 1832, 1834, 1835, 1837, 1838, 1839, 1840, 1841, 1842, 1843, 1844, 1845, 1846, 1847, 1848, 1849, 1850, 1851, 1852, 1853, 1854, 1855, 1858, 1859, 1860, 1861, 1862, 1863, 1864, 1865, 1866, 1867, 1868, 1869, 1870, 1871, 1872, 1874, 1877, 1878, 1879, 1880, 1881, 1882, 1883, 1884, 1885, 1886, 1887, 1888, 1889, 1901, 1902, 1903, 1904, 1906, 1907, 1908, 1910, 1911, 1913, 1914, 1915, 1916, 1917, 1918, 1919, 1920, 1921, 1923, 1924, 1925, 1926, 1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939, 1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1952, 1953, 1958, 1959, 1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1970, 1972, 1978, 1979, 1980, 1981, 1982, 1983, 1984, 1985, 1988, 1989, 1990, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2032, 2044, 2054, 2107, 2109, 2110, 2113, 2115, 2125, 2143, 2161, 2163, 2170, 2271, 2278, 2287, 2288, 2289, 2290, 2291, 2292, 2293, 2294, 2295, 2297, 2298, 2299, 2300, 2301, 2302, 2303, 2304, 2305, 2306, 2311, 2312, 2322, 2323, 2324, 2325, 2326, 2327, 2328, 2329, 2330, 2331, 2332, 2371, 2380, 2381, 2382, 2383, 2384, 2385, 2386, 2388, 2389, 2390, 2395, 2396, 2401, 2402, 2403, 2404, 2405, 2406, 2409, 2411, 2413, 2414, 2421, 2422, 2423, 2424, 2425, 2426, 2427, 2428, 2429, 2430, 2431, 2432, 2433, 2434, 2435, 2436, 2437, 2439, 2441, 2442, 2443, 2446, 2447, 2449, 2450, 2451, 2452, 2453, 2454, 2455, 2456, 2457, 2458, 2460, 2461, 2462, 2463, 2464, 2465, 2466, 2467, 2468, 2469, 2470, 2474, 2475, 2476, 2479, 2480, 2484, 2490, 2492, 2530, 2534, 2547, 2550, 2554, 2555, 2556, 2557, 2558, 2563, 2564, 2565, 2566, 2578, 2579, 2580, 2585, 2609, 2619, 2620, 2626, 2636, 2638, 2639, 2643, 2650, 2651, 2653, 2654, 2655, 2656, 2657, 2658, 2659, 2660, 2661, 2662, 2664, 2667, 2668, 2669, 2670, 2677, 2678, 2684, 2687, 2688, 2689, 2690, 2691, 2692, 2693, 2694, 2695, 2696, 2697, 2698, 2699, 2700, 2701, 2702, 2704, 2707, 2709, 2711, 2713, 2716, 2718, 2721, 2722, 2723, 2725, 2726, 2730, 2733, 2734, 2735, 2749, 2750, 2751, 2752, 2753, 2754, 2756, 2757, 2758, 2759, 2760, 2761, 2767, 2768, 2771, 2772, 2776, 2780, 2781, 2782, 2783, 2784, 2785, 2787, 2788, 2789, 2790, 2791, 2799, 2800, 2801, 2802, 2803, 2804, 2805, 2807, 2808, 2811, 2812, 2813, 2814, 2815, 2816, 2818, 2819, 2820, 2821, 2822, 2823, 2827, 2828, 2831, 2832, 2833, 2835, 2836, 2840, 2841, 2842, 2843, 2844, 2846, 2847, 2848, 2851, 2852, 2853, 2854, 2855, 2862, 2863, 2864, 2870, 2871, 2872, 2873, 2877, 2878, 2879, 2885, 2901, 2909, 2912, 2916, 2919, 2923, 2929, 2942, 2944, 2945, 2946, 2947, 2948, 2949, 2950, 2951, 2952, 2953, 2954, 2955, 2957, 2958, 2962, 2965, 2966, 2970, 2971, 2980, 2984, 2991, 2995, 2996, 2997, 2998, 2999, 3000, 3001, 3002, 3007, 3008, 3009, 3010, 3011, 3012, 3013, 3014, 3015, 3016, 3017, 3033, 3034, 3035, 3036, 3045, 3051, 3058, 3064, 3065, 3066, 3067, 3068, 3069, 3071, 3072, 3074, 3075, 3076, 3077, 3085, 3086, 3087, 3096, 3097, 3098, 3114, 3116, 3118, 3122, 3130, 3133, 3134, 3135, 3136, 3137, 3138, 3139, 3140, 3141, 3142, 3143, 3144, 3145, 3150, 3151, 3156, 3157, 3162, 3163, 3164, 3188, 3192, 3193, 3194, 3195, 3284, 3326, 3327, 3328, 3329, 3330, 3331, 3332, 3334, 3335, 3339, 3340, 3341, 3355, 3356, 3458, 3505, 3516, 3517, 3518, 3519, 3520, 3521, 3522, 3523, 3525, 3527, 3528, 3529, 3530, 3531, 3532, 3533, 3540, 3541, 3542, 3543, 3546, 3547, 3548, 3555, 3560, 3561, 3562, 3563, 3564, 3565, 3570, 3571, 3572, 3577, 3578, 3579, 3584, 3585, 3586, 3587, 3588, 3589, 3590, 3591, 3683, 3686, 3766, 3783, 3784, 3785, 3786, 3787, 3788, 3789, 3792, 3813, 3814, 3815, 3816, 3817, 3818, 3819, 3820, 3828, 3829, 3830, 3831, 3832, 4115, 4116, 4117, 4118, 4119, 4120, 4121, 4122, 4123, 5751, 5756, 5757, 5758, 5759, 5760, 5761, 5762, 5763, 5764, 5767, 5768, 5779, 5780, 5782, 5783, 5784, 5785, 5786, 5787, 5788, 5789, 5807, 5819, 5850, 5858, 5869, 5970, 5971, 5972, 5979, 5980, 6019, 6030, 6031, 6050, 6051, 6052, 6053, 6054, 6055, 6056, 6057, 6058, 6123, 6124, 6178, 6179, 6180, 6181, 6182, 6183, 6190, 6191, 6192, 6207, 6246, 6247, 6248, 6249, 6250, 6251, 6269, 6270, 6271, 6272, 6273, 6274, 6275, 6276, 6277, 6278, 6279, 6280, 6281, 6282, 6283, 6284, 6285, 6408, -1
};

void check_preload(unsigned int x)
{
    int i;
    for (i = 0; preloaded[i] >= 0; i++)
        if (preloaded[i] == x) return;
    printf("bag: %d\n", x);
}

int __cdecl sub_42FE30(int a1)
{
    int v1; // esi
    signed int v2; // eax
    char* v3; // ebx
    char* v4; // ebp
    signed int v5; // eax
    char* v6; // edi
    int v7; // eax
    int result; // eax
    int v9; // [esp+8h] [ebp-8h]
    int v10; // [esp+Ch] [ebp-4h]
    FILE* fp;

    v1 = a1;
    // check_preload((a1 - *(_DWORD *)&byte_5D4594[787148]) / 36);
    fp = get_bag(*(_DWORD*)(a1 + 8));
    v2 = *(_DWORD*)(v1 + 16);
    if (*(_DWORD*)(v1 + 12) == v2)
    {
        v10 = sub_40ADD0_fread(*(char**)v1, 1u, v2, fp);
    }
    else
    {
        v3 = 0;
        v4 = *(char**)v1;
        if (v2 > * (int*)& byte_5D4594[787184])
        {
            v3 = (char*)nox_malloc(v2);
            v10 = sub_40ADD0_fread(v3, 1u, *(_DWORD*)(v1 + 16), fp);
            v6 = v3;
        }
        else
        {
            v5 = sub_40ADD0_fread(*(char**)& byte_5D4594[787208], 1u, v2, fp);
            v6 = *(char**)& byte_5D4594[787208];
            v10 = v5;
        }
        v7 = *(_DWORD*)(v1 + 12);
        a1 = *(_DWORD*)(v1 + 16);
        v9 = v7;
        sub_578C30(*(int*)& byte_5D4594[787212]);
        if (sub_578C10(
                *(_DWORD * *)& byte_5D4594[787212],
                &v4[*(_DWORD*)(v1 + 12) - v9],
                &v9,
                (unsigned int)& v6[*(_DWORD*)(v1 + 16) - a1],
                &a1))
        {
            while (a1 > 0
                   && sub_578C10(
                    *(_DWORD * *)& byte_5D4594[787212],
                    &v4[*(_DWORD*)(v1 + 12) - v9],
                    &v9,
                    (unsigned int)& v6[*(_DWORD*)(v1 + 16) - a1],
                    &a1))
                ;
        }
        if (v3)
            free(v3);
    }
    result = v10;
    if (v10 == *(_DWORD*)(v1 + 16) && *(_DWORD*)& byte_5D4594[3799624] == 2)
        result = sub_42FF90((_DWORD*)v1);
    return result;
}

//----- (0042FF90) --------------------------------------------------------
int __cdecl sub_42FF90(_DWORD* a1)
{
    int v1; // edx
    int result; // eax
    int v3; // ecx
    int v4; // esi
    int v5; // ebx
    char v6; // cl

    v1 = a1[6];
    result = a1[5];
    if (v1 >= 0)
        v3 = result + v1;
    else
        v3 = result - v1;
    if (result < v3)
    {
        v4 = 12 * result;
        v5 = v3 - result;
        do
        {
            result = v4 + *(_DWORD*)& byte_5D4594[787152];
            v6 = *(_BYTE*)(v4 + *(_DWORD*)& byte_5D4594[787152] + 10);
            if (v6)
            {
                if (v6 != 1)
                    result = sub_47D480((int*)(*a1 + *(_DWORD*)result), v4 + *(_DWORD*)& byte_5D4594[787152]);
            }
            v4 += 12;
            --v5;
        } while (v5);
    }
    return result;
}

//----- (0042FFF0) --------------------------------------------------------
BOOL __cdecl sub_42FFF0(FILE* a1)
{
    signed int v1; // edx
    BOOL result; // eax
    char v3[12]; // [esp+8h] [ebp-2Ch]
    char v4[32]; // [esp+14h] [ebp-20h]

    strcpy(v3, "LOOKUPTABLE");
    v1 = sub_40ADD0_fread(v4, 1u, strlen(v3), a1);
    result = 0;
    if (v1 == strlen(v3))
    {
        v4[strlen(v3)] = 0;
        if (!strcmp(v4, v3))
            result = sub_40ADD0_fread((char*)& byte_5D4594[754340], 1u, 0x8000u, a1) == 0x8000;
        else
            result = 0;
    }
    return result;
}
// 42FFF0: using guessed type char var_20[32];

//----- (004300D0) --------------------------------------------------------
BOOL __cdecl sub_4300D0(int a1)
{
    char* v1; // eax

    v1 = sub_430100(a1);
    return _access(v1, 0) != -1;
}

//----- (00430100) --------------------------------------------------------
char* __cdecl sub_430100(int a1)
{
    char* result; // eax

#ifdef __EMSCRIPTEN__
    return "video.bag";
#else
    result = "video.bag";
    if (a1 != 1)
        result = "video8.bag";
    return result;
#endif
}

//----- (00430120) --------------------------------------------------------
char* __cdecl sub_430120(int a1)
{
    char* result; // eax

    result = "video.idx";
    if (a1 != 1)
        result = "video8.idx";
    return result;
}

//----- (00430140) --------------------------------------------------------
void sub_430140(int a1)
{
    unsigned __int8* v0; // eax

    v0 = &byte_5D4594[789280];
    do
    {
        *(v0 - 2) = 0;
        *(_DWORD*)v0 = 0;
        *(v0 - 3) = 1;
        v0 += 8;
    } while ((int)v0 < (int)& byte_5D4594[791328]);
    *(_DWORD*)& byte_5D4594[791352] = 1;
    *(_DWORD*)& byte_5D4594[791344] = 0;
    *(_DWORD*)& byte_5D4594[791364] = 1;
    *(_DWORD*)& byte_5D4594[791356] = 0;
    *(_DWORD*)& byte_5D4594[791376] = 1;
    *(_DWORD*)& byte_5D4594[791368] = 0;
    sub_4302A0_process_events(1, 1);
}

//----- (00430190) --------------------------------------------------------
int sub_430190()
{
    int v1; // ecx
    unsigned __int8* v2; // eax
    int v4; // [esp+0h] [ebp-4h]

    sub_47FB10();
    v1 = 0;
    v2 = &byte_5D4594[789278];
    do
    {
        *(v2 - 2) = v1;
        *v2 = 0;
        *(_DWORD*)(v2 + 2) = 0;
        *(v2 - 1) = 1;
        v2 += 8;
        ++v1;
    } while ((int)v2 < (int)& byte_5D4594[791326]);
    initMouse_sub_47D8D0();
    sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    sub_47D660(0, (int)& v4);
    sub_47D660(1u, (int)& v4);
    sub_42EBB0(2u, sub_430140, 0, "Input");
    return 1;
}

//----- (00430210) --------------------------------------------------------
void sub_430210()
{
    sub_47FCC0();
    *(_DWORD*)& byte_5D4594[805808] = 0;
}

//----- (00430230) --------------------------------------------------------
void sub_430230()
{
    if (nox_mouse.left_state && (nox_mouse_prev.field_6 == 5 || nox_mouse_prev.field_6 == 8))
    {
        nox_mouse.field_6 = 8;
    }
    if (nox_mouse.right_state && (nox_mouse_prev.field_9 == 9 || nox_mouse_prev.field_9 == 12))
    {
        nox_mouse.field_9 = 12;
    }
    if (nox_mouse.middle_state && (nox_mouse_prev.field_12 == 13 || nox_mouse_prev.field_12 == 16))
    {
        nox_mouse.field_12 = 16;
    }
}

//----- (004302A0) --------------------------------------------------------
void __cdecl sub_4302A0_process_events(int evNum, int a2)
{
    if (nox_mouse_prev_seq_2 != nox_mouse_prev_seq)
    {
        nox_mouse.field_6 = 0;
        nox_mouse.field_9 = 0;
        nox_mouse.field_12 = 0;
        nox_mouse.z = 0;
        nox_mouse_prev_seq_2 = nox_mouse_prev_seq;
    }
    int num = 0;
    if (obj_5D4594_754104_switch != 1)
    {
        num = evNum;
        if (!evNum)
            sub_430230();
    }
    int x = 0;
    int y = 0;
    if (num <= 0)
    {
        y = nox_mouse.pos.y;
        x = nox_mouse.pos.x;
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            nox_mouse_state_t* ev = &nox_input_buffer[i];
            sub_430A00_change_mouse_pos(ev->pos.x, ev->pos.y, 0);

            x = nox_mouse.pos.x;
            y = nox_mouse.pos.y;
            nox_mouse.z += ev->z;

            int dx, dy;

            // left mouse button
            if (ev->left_seq == 0)
            {
                if (nox_mouse.left_state && (nox_mouse_prev.field_6 == 5 || nox_mouse_prev.field_6 == 8))
                {
                    nox_mouse.field_6 = 8;
                }
            }
            else if (nox_mouse.left_state != ev->left_state)
            {
                if (ev->left_state)
                {
                    if (nox_mouse.field_6 != 7)
                    {
                        nox_mouse.field_6 = 5;
                        nox_mouse.left_state = 1;
                        nox_mouse.left_seq = nox_mouse_prev_seq;
                    }
                }
                else if ((unsigned int)((int)(nox_mouse_prev_seq) - nox_mouse.left_seq) >= 15 || (dx = nox_mouse.pos.x - nox_mouse_prev_left.x, dy = nox_mouse.pos.y - nox_mouse_prev_left.y, dx*dx + dy*dy >= 100))
                {
                    nox_mouse.field_6 = 6;
                    nox_mouse.left_state = 0;
                    nox_mouse.left_seq = nox_mouse_prev_seq;
                }
                else
                {
                    nox_mouse.field_6 = 7;
                    nox_mouse.left_state = 0;
                    nox_mouse.left_seq = nox_mouse_prev_seq;
                }
            }

            // right mouse button
            if (ev->right_seq == 0)
            {
                if (nox_mouse.right_state && (nox_mouse_prev.field_9 == 9 || nox_mouse_prev.field_9 == 12))
                {
                    nox_mouse.field_9 = 12;
                }
            }
            else if (nox_mouse.right_state != ev->right_state)
            {
                if (ev->right_state)
                {
                    if (nox_mouse.field_9 != 11)
                    {
                        nox_mouse.field_9 = 9;
                        nox_mouse.right_state = 1;
                        nox_mouse.right_seq = nox_mouse_prev_seq;
                    }
                }
                else if ((unsigned int)((int)(nox_mouse_prev_seq) - nox_mouse.right_seq) >= 15 || (dx = nox_mouse.pos.x - nox_mouse_prev_right.x, dy = nox_mouse.pos.y - nox_mouse_prev_right.y, dx*dx + dy*dy >= 100))
                {
                    nox_mouse.field_9 = 10;
                    nox_mouse.right_state = 0;
                    nox_mouse.right_seq = nox_mouse_prev_seq;
                }
                else
                {
                    nox_mouse.field_9 = 11;
                    nox_mouse.right_state = 0;
                    nox_mouse.right_seq = nox_mouse_prev_seq;
                }
            }

            // middle mouse button
            if (ev->middle_seq == 0)
            {
                if (nox_mouse.middle_state && (nox_mouse_prev.field_12 == 13 || nox_mouse_prev.field_12 == 16))
                {
                    nox_mouse.field_12 = 16;
                }
            }
            else if (nox_mouse.middle_state != ev->middle_state)
            {
                if (ev->middle_state)
                {
                    if (nox_mouse.field_12 != 15)
                    {
                        nox_mouse.field_12 = 13;
                        nox_mouse.middle_state = 1;
                        nox_mouse.middle_seq = nox_mouse_prev_seq;
                    }
                }
                else if ((unsigned int)((int)(nox_mouse_prev_seq) - nox_mouse.middle_seq) >= 15 || (dx = nox_mouse.pos.x - nox_mouse_prev_middle.x, dy = nox_mouse.pos.y - nox_mouse_prev_middle.y, dx*dx + dy*dy >= 100))
                {
                    nox_mouse.field_12 = 14;
                    nox_mouse.middle_state = 0;
                    nox_mouse.middle_seq = nox_mouse_prev_seq;
                }
                else
                {
                    nox_mouse.field_12 = 15;
                    nox_mouse.middle_state = 0;
                    nox_mouse.middle_seq = nox_mouse_prev_seq;
                }
            }
        }
    }
    if (nox_mouse.field_6 == 5)
    {
        nox_mouse_prev_left.x = x;
        nox_mouse_prev_left.y = y;
    }
    if (nox_mouse.field_9 == 9)
    {
        nox_mouse_prev_right.x = x;
        nox_mouse_prev_right.y = y;
    }
    if (nox_mouse.field_12 == 13)
    {
        nox_mouse_prev_middle.x = x;
        nox_mouse_prev_middle.y = y;
    }
    nox_mouse.field_3 = x - nox_mouse_prev.pos.x;
    nox_mouse.field_4 = y - nox_mouse_prev.pos.y;
    if (nox_mouse.field_3 * nox_mouse.field_3 + (y - nox_mouse_prev.pos.y) * (y - nox_mouse_prev.pos.y) >= 4)
    {
        *(_DWORD*)& byte_5D4594[805824] = 0;
        *(_DWORD*)& byte_5D4594[805804] = 0;
    }
    else
    {
        ++ * (_DWORD*)& byte_5D4594[805824];
        if (*(_DWORD*)& byte_5D4594[805824] >= 10)
            * (_DWORD*)& byte_5D4594[805804] = 1;
    }
    if (a2)
    {
        if (nox_mouse.z <= 0)
            nox_mouse.z = nox_mouse.z >= 0 ? 0 : 20;
        else
            nox_mouse.z = 19;
        nox_mouse_prev = nox_mouse;
    }
}

//----- (004306A0) --------------------------------------------------------
void __cdecl sub_4306A0(int a1)
{
    if (nox_processing_input)
        return;
    nox_processing_input = 1;
    int v2 = 0;
    while (1)
    {
        char v4 = sub_47DB20_get_mouse_data(&nox_input_buffer[v2]);
        if (v4 == -1)
            continue;
        v2++;
        if (!v4 || v2 >= nox_input_buffer_cap)
            break;
    }
    int v5 = v2 - 1;
    sub_4302A0_process_events(v5, a1);
    nox_processing_input = 0;
    if (v5)
    {
        *(_DWORD*)& byte_5D4594[805816] = nox_mouse_prev_seq;
    }
}

//----- (00430710) --------------------------------------------------------
int sub_430710()
{
    unsigned __int8* v0; // esi
    unsigned __int8 v1; // al
    int v2; // ebp
    unsigned __int8* v3; // edi
    unsigned __int8* v4; // esi
    unsigned __int8 v5; // cl
    unsigned __int8 v6; // dl
    int v7; // eax
    int v8; // ecx
    int result; // eax

    v0 = &byte_5D4594[787228];
    do
    {
        do
        {
            sub_47FA80((int)v0);
            v1 = *v0;
        } while (*v0 == -1);
        v0 += 8;
    } while (v1);
    v2 = 0;
    if (byte_5D4594[787228])
    {
        v3 = &byte_5D4594[787228];
        v4 = &byte_5D4594[787228];
        do
        {
            if (*v3 == 15)
            {
                if (byte_5D4594[789725] == 2 || byte_5D4594[790749] == 2)
                    v4[2] = 1;
            }
            else
            {
                v3 = v4;
                if (*v4 == 58)
                    sub_47F950(0x3Au);
            }
            if (obj_5D4594_754104_switch == 1)
                v4[2] = 1;
            v5 = v4[1];
            v6 = v4[2];
            v4 += 8;
            v7 = *v3;
            v3 = v4;
            v7 *= 8;
            ++v2;
            byte_5D4594[v7 + 789277] = v5;
            v8 = nox_mouse_prev_seq;
            byte_5D4594[v7 + 789278] = v6;
            *(_DWORD*)& byte_5D4594[v7 + 789280] = v8;
        } while (*v4);
    }
    result = sub_4307D0();
    if (result == 1 || v2)
        * (_DWORD*)& byte_5D4594[805816] = nox_mouse_prev_seq;
    return result;
}

//----- (004307D0) --------------------------------------------------------
int sub_4307D0()
{
    int v0; // edx
    unsigned __int8* v2; // ecx
    unsigned __int8 v3; // al
    int v4; // esi
    int v5; // ebx
    unsigned __int8* v6; // ecx
    unsigned __int8* v7; // eax

    v0 = 0;
    if (obj_5D4594_754104_switch == 1)
        return 0;
    if (byte_5D4594[787228])
    {
        v2 = &byte_5D4594[787228];
        do
        {
            v3 = v2[8];
            v2 += 8;
            ++v0;
        } while (v3);
    }
    v4 = nox_mouse_prev_seq;
    v5 = 0;
    v6 = &byte_5D4594[789280];
    while (*(v6 - 3) != 2 || (unsigned int)(nox_mouse_prev_seq - *(_DWORD*)v6) <= 0xA)
    {
        v6 += 8;
        ++v5;
        if ((int)v6 >= (int)& byte_5D4594[791328])
            return 0;
    }
    byte_5D4594[8 * v0 + 787228] = v5;
    byte_5D4594[8 * v0 + 787229] = 2;
    byte_5D4594[8 * v0 + 787230] = 0;
    byte_5D4594[8 * v0 + 787236] = 0;
    v7 = &byte_5D4594[789280];
    do
    {
        *(_DWORD*)v7 = v4;
        v7 += 8;
    } while ((int)v7 < (int)& byte_5D4594[791328]);
    *(_DWORD*)& byte_5D4594[8 * v5 + 789280] = v4 - 12;
    return 1;
}

//----- (00430880) --------------------------------------------------------
int __cdecl sub_430880(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[805808] = a1;
    return result;
}

//----- (00430890) --------------------------------------------------------
int sub_430890()
{
    return *(_DWORD*)& byte_5D4594[805808];
}

//----- (004308A0) --------------------------------------------------------
int __cdecl sub_4308A0(int a1)
{
    int v2; // ecx

    sub_4306A0(a1);
    sub_430710();
    if (byte_5D4594[787228])
    {
        v2 = *(_DWORD*)& byte_5D4594[787228] >> 8;
        if (!BYTE1(v2))
            OnLibraryNotice(417, *(_DWORD*)& byte_5D4594[787228]);
    }
    ++nox_mouse_prev_seq;
    if (sub_40A5C0(0x2000)
        && !sub_40A5C0(4096)
        && (unsigned int)(nox_mouse_prev_seq - *(_DWORD*)& byte_5D4594[805816]) > 0xA8C)
    {
        if (!sub_40A5C0(1))
        {
            sub_440950(0, (wchar_t*)& byte_587000[80784]);
            return 1;
        }
        if (*(_DWORD*)& byte_5D4594[2618908])
            sub_443E90(*(int*)& byte_5D4594[2618908], 0, (wchar_t*)& byte_587000[80792]);
    }
    return 1;
}

//----- (00430940) --------------------------------------------------------
char* sub_430940()
{
    return (char*)& byte_5D4594[787228];
}

//----- (00430950) --------------------------------------------------------
unsigned __int8 __cdecl sub_430950(unsigned __int8 a1)
{
    return byte_5D4594[8 * a1 + 789278];
}

//----- (00430970) --------------------------------------------------------
unsigned __int8 __cdecl sub_430970(unsigned __int8 a1)
{
    return byte_5D4594[8 * a1 + 789277];
}

//----- (00430990) --------------------------------------------------------
int __cdecl sub_430990(unsigned __int8 a1)
{
    return *(_DWORD*)& byte_5D4594[8 * a1 + 789280];
}

//----- (004309B0) --------------------------------------------------------
int __cdecl sub_4309B0(unsigned __int8 a1, char a2)
{
    int result; // eax

    result = a1;
    byte_5D4594[8 * a1 + 789278] = a2;
    return result;
}

//----- (004309D0) --------------------------------------------------------
int __cdecl sub_4309D0(unsigned __int8 a1, char a2)
{
    int result; // eax

    result = a1;
    byte_5D4594[8 * a1 + 789277] = a2;
    return result;
}

//----- (004309F0) --------------------------------------------------------
int2* __cdecl sub_4309F0()
{
    return &nox_mouse.pos;
}

//----- (00430A00) --------------------------------------------------------
void __cdecl sub_430A00_change_mouse_pos(int x, int y, int abs)
{
    mouse_pos_t p;
    p.x = x;
    p.y = y;

    if (!abs)
    {
        p.x += nox_mouse.pos.x;
        p.y += nox_mouse.pos.y;
    }

    if (p.x > nox_mouse_max.x)
        p.x = nox_mouse_max.x;

    if (p.x < nox_mouse_min.x)
        p.x = nox_mouse_min.x;

    if (p.y > nox_mouse_max.y)
        p.y = nox_mouse_max.y;

    if (p.y < nox_mouse_min.y)
        p.y = nox_mouse_min.y;

    nox_mouse.pos = p;
}

//----- (00430A70) --------------------------------------------------------
int __cdecl sub_430A70_set_mouse_bounds(int x_min, int x_max, int y_min, int y_max)
{
    nox_mouse_min.x = x_min;
    nox_mouse_min.y = y_min;
    nox_mouse_max.x = x_max;
    nox_mouse_max.y = y_max;
    return y_max;
}

//----- (00430AA0) --------------------------------------------------------
int __cdecl sub_430AA0(int a1)
{
    int result; // eax

    result = a1 - 1;
    if (a1 == 1)
    {
        *(_DWORD*)& byte_5D4594[805820] = 1;
        *(_DWORD*)& byte_587000[80772] = 9;
    }
    else
    {
        result = a1 - 2;
        if (a1 == 2)
        {
            *(_DWORD*)& byte_5D4594[805820] = 2;
            *(_DWORD*)& byte_587000[80772] = 13;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[805820] = 0;
            *(_DWORD*)& byte_587000[80772] = 5;
        }
    }
    return result;
}

//----- (00430AF0) --------------------------------------------------------
int sub_430AF0()
{
    return *(_DWORD*)& byte_5D4594[805820];
}

//----- (00430B00) --------------------------------------------------------
int sub_430B00()
{
    return *(_DWORD*)& byte_587000[80772];
}

//----- (00430B10) --------------------------------------------------------
void __cdecl sub_430B10_set_mouse_pos(int x, int y)
{
    sub_430A00_change_mouse_pos(x, y, 1);
}

//----- (00430B30) --------------------------------------------------------
int sub_430B30()
{
    return *(_DWORD*)& byte_5D4594[805804];
}

//----- (00430B40) --------------------------------------------------------
int sub_430B40_get_mouse_prev_seq()
{
    return nox_mouse_prev_seq;
}

//----- (00430B50) --------------------------------------------------------
int __cdecl sub_430B50(int a1, int a2, int a3, int a4)
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[3807140] = a1;
    result = a4;
    *(_DWORD*)& byte_5D4594[3807136] = a2;
    *(_DWORD*)& byte_5D4594[3807116] = a3;
    *(_DWORD*)& byte_5D4594[3807152] = a4;
    return result;
}

//----- (00430B80) --------------------------------------------------------
char* __cdecl sub_430B80(_DWORD* a1)
{
    *a1 = *(_DWORD*)& byte_5D4594[3804684];
    return (char*)& byte_5D4594[3805516];
}

//----- (00430BA0) --------------------------------------------------------
int nox_init_floor_buf() {
    if (*(_DWORD*)& byte_5D4594[3801780] == 1)
        sub_430CC0();
    else
        sub_430D60();
    if (!sub_430DB0(nox_backbuffer_width, nox_backbuffer_height))
    {
        printf("VideoInit: error initializing floor buffer\n");
        return 0;
    }
    return 1;
}

int sub_430BA0()
{
    sub_430EC0();
    int result = sub_47FD70();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
    {
        return 0;
    }
    return nox_init_floor_buf();
}

//----- (00430BB0) --------------------------------------------------------
void __cdecl sub_430BB0(_DWORD* a1, _DWORD* a2, _DWORD* a3)
{
    *a1 = nox_backbuffer_width;
    *a2 = nox_backbuffer_height;
    *a3 = *(_DWORD*)& byte_5D4594[3801780] != 0 ? 16 : 8;
}

//----- (00430BE0) --------------------------------------------------------
BOOL __cdecl sub_430BE0(int a1, int a2, int a3)
{
    BOOL result; // eax

    printf("New size: %d, %d\n", a1, a2);

    nox_win_width = a1;
    if (a1 > nox_max_width)
        nox_win_width = nox_max_width;
    nox_win_height = a2;
    if (a2 > nox_max_height)
        nox_win_height = nox_max_height;
    a3 = 16;
    result = a3 != 8;
    *(_DWORD*)& byte_5D4594[3804680] = a3 != 8;
    return result;
}

//----- (00430C30) --------------------------------------------------------
void __cdecl sub_430C30_set_video_max(int w, int h)
{
    nox_max_width = w;
    nox_max_height = h;
}

//----- (00430C50) --------------------------------------------------------
void __cdecl sub_430C50_get_video_max(int* w, int* h)
{
    *w = nox_max_width;
    *h = nox_max_height;
}

//----- (00430CC0) --------------------------------------------------------
BOOL sub_430CC0()
{
    BOOL result; // eax

    *(_DWORD*)& byte_5D4594[3807124] = 1;
    *(_DWORD*)& byte_5D4594[3807128] = sub_480EF0;
    *(_DWORD*)& byte_5D4594[3807132] = sub_468F80;
    *(_DWORD*)& byte_5D4594[3807148] = sub_4814F0;
    *(_DWORD*)& byte_5D4594[3807156] = sub_469920;
    result = sub_430D40();
    *(_DWORD*)& byte_587000[80800] = result;
    if (result)
    {
        *(_DWORD*)& byte_5D4594[805836] = 1;
        *(_DWORD*)& byte_5D4594[3805484] = sub_480950;
        *(_DWORD*)& byte_5D4594[3805492] = sub_4805A0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[805836] = 0;
        *(_DWORD*)& byte_5D4594[3805484] = sub_480BE0;
        *(_DWORD*)& byte_5D4594[3805492] = sub_480860;
    }
    return result;
}

//----- (00430D40) --------------------------------------------------------
BOOL sub_430D40()
{
    BOOL result; // eax

    if (*(_DWORD*)& byte_5D4594[805840])
        result = 0;
    else
        result = sub_444D90();
    return result;
}

//----- (00430D60) --------------------------------------------------------
int sub_430D60()
{
    int result; // eax

    result = 0;
    *(_DWORD*)& byte_5D4594[3805484] = sub_485880;
    *(_DWORD*)& byte_587000[80800] = 0;
    *(_DWORD*)& byte_5D4594[805836] = 0;
    *(_DWORD*)& byte_5D4594[3807124] = 0;
    *(_DWORD*)& byte_5D4594[3807148] = sub_481470;
    *(_DWORD*)& byte_5D4594[3807132] = sub_484E60;
    *(_DWORD*)& byte_5D4594[3807156] = sub_485740;
    *(_DWORD*)& byte_5D4594[3807128] = sub_484B70;
    return result;
}

//----- (00430DB0) --------------------------------------------------------
int __cdecl sub_430DB0(int a1, int a2)
{
    size_t v2; // edi
    char* v3; // eax

    *(_DWORD*)& byte_5D4594[3798812] = a1 / 46 + 4;
    *(_DWORD*)& byte_5D4594[3798820] = 0;
    *(_DWORD*)& byte_5D4594[3798824] = 0;
    *(_DWORD*)& byte_5D4594[3798800] = 46 * *(_DWORD*)& byte_5D4594[3798812];
    *(_DWORD*)& byte_5D4594[3798816] = a2 / 46 + 3;
    *(_DWORD*)& byte_5D4594[3798828] = 0;
    *(_DWORD*)& byte_5D4594[3798832] = 0;
    *(_DWORD*)& byte_5D4594[3798808] = 46 * *(_DWORD*)& byte_5D4594[3798816];
    v2 = ((46 * *(_DWORD*)& byte_5D4594[3798812]) << byte_5D4594[3807124]) * 46 * *(_DWORD*)& byte_5D4594[3798816];
    *(_DWORD*)& byte_5D4594[3798804] = (46 * *(_DWORD*)& byte_5D4594[3798812]) << byte_5D4594[3807124];
    *(_DWORD*)& byte_5D4594[3798836] = 0;
    *(_DWORD*)& byte_5D4594[3798840] = 0;
    v3 = (char*)nox_malloc(v2);
    *(_DWORD*)& byte_5D4594[3798796] = v3;
    if (!v3)
        return 0;
    *(_DWORD*)& byte_5D4594[3798844] = &v3[v2];
    return 1;
}

//----- (00430E70) --------------------------------------------------------
int sub_430E70()
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[80800];
    if (*(_DWORD*)& byte_587000[80800])
    {
        result = *(_DWORD*)& byte_5D4594[805836];
        if (*(_DWORD*)& byte_5D4594[805836])
        {
            *(_DWORD*)& byte_5D4594[805836] = 0;
            *(_DWORD*)& byte_5D4594[3805484] = sub_480BE0;
            *(_DWORD*)& byte_5D4594[3805492] = sub_480860;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[805836] = 1;
            *(_DWORD*)& byte_5D4594[3805484] = sub_480950;
            *(_DWORD*)& byte_5D4594[3805492] = sub_4805A0;
        }
    }
    return result;
}

//----- (00430EC0) --------------------------------------------------------
int sub_430EC0()
{
    if (*(_DWORD*)& byte_5D4594[3798796])
    {
        free(*(LPVOID*)& byte_5D4594[3798796]);
        *(_DWORD*)& byte_5D4594[3798796] = 0;
    }
    sub_444C50();
    return 1;
}

//----- (00430EF0) --------------------------------------------------------
void sub_430EF0()
{
    sub_430EC0();
}

//----- (00430F00) --------------------------------------------------------
int screenshot_num = 0;

int sub_430F00_screenshot()
{
    wchar_t* v2; // eax
    int v4; // ebx
    wchar_t* v8; // eax

    char path[100];
    nox_sprintf(path, "sshot%03d.ppm", screenshot_num);
    ++screenshot_num;
    FILE* file = fopen(path, "w");
    if (!file)
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[80968], 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Video.c", 375);
        return sub_4517A0(v2, path);
    }
    fprintf(file, "P3\n#Nox Bitmap data\n640 480 256\n");
    v4 = *(_DWORD*)& byte_5D4594[3798780];
    for (int v5 = nox_backbuffer_height; v5 > 0; v5--)
    {
        for (int v7 = 0; v7 < nox_backbuffer_width; v7++)
        {
            if (v7 != 0 && (v7 % 60) == 0)
                fprintf(file, "\n");
            fprintf(
                    file, "%d %d %d ",
                    byte_5D4594[3 * *(unsigned __int8*)(v7 + v4) + 3804716],
            byte_5D4594[3 * *(unsigned __int8*)(v7 + v4) + 3804717],
            byte_5D4594[3 * *(unsigned __int8*)(v7 + v4) + 3804718]);
        }
        v4 += *(_DWORD*)& byte_5D4594[3801808];
    }
    v8 = loadString_sub_40F1D0((char*)& byte_587000[81068], 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Video.c", 399);
    sub_4517A0(v8, path);
    return fclose(file);
}

//----- (00431040) --------------------------------------------------------
int __cdecl sub_431040(int a1, int a2, int a3)
{
    nox_win_width = a2;
    nox_win_height = a3;
    *(_DWORD*)& byte_587000[80848] = 0;
    int result = sub_4800F0();
    if (!result)
    {
        return 0;
    }
    return nox_init_floor_buf();
}

//----- (004310B0) --------------------------------------------------------
int __cdecl sub_4310B0(int a3)
{
    int v1; // esi
    int v2; // esi
    int v3; // esi

    if (a3)
    {
        sub_486F30();
        if (sub_4311F0())
        {
            *(_DWORD*)& byte_587000[81128] = *(_DWORD*)& byte_5D4594[805984] + 88;
            *(_DWORD*)& byte_5D4594[805980] = sub_4866F0("audio", "audio");
        }
    }
    sub_4864A0(&byte_5D4594[805884]);
    sub_4864A0(*(_DWORD * *)& byte_587000[93164]);
    sub_4864A0(*(_DWORD * *)& byte_587000[122852]);
    sub_4864A0(*(_DWORD * *)& byte_587000[127004]);
    sub_44D810();
    sub_43D8E0();
    sub_451850(*(int*)& byte_5D4594[805984], *(int*)& byte_5D4594[805980]);
    v1 = sub_4866A0(2);
    if (!v1)
        sub_43DC00();
    sub_486320(*(_DWORD * *)& byte_587000[93164], v1);
    v2 = sub_4866A0(1);
    if (!v2)
        sub_44D960();
    sub_486320(*(_DWORD * *)& byte_587000[122852], v2);
    v3 = sub_4866A0(0);
    if (!v3)
        sub_453050();
    sub_486320(*(_DWORD * *)& byte_587000[127004], v3);
    return 1;
}

//----- (004311B0) --------------------------------------------------------
void sub_4311B0()
{
    sub_43DCC0();
    sub_4312B0();
    sub_43D970();
    sub_44D8C0();
    sub_451970();
    if (*(_DWORD*)& byte_5D4594[805980])
        sub_4869C0(*(LPVOID*)& byte_5D4594[805980]);
    *(_DWORD*)& byte_587000[81128] = 0;
    sub_431270();
    if (*(_DWORD*)& byte_5D4594[1193336])
    {
        sub_4875F0();
        sub_4870A0();
        *(_DWORD*)& byte_5D4594[1193336] = 0;
    }
}

//----- (004311F0) --------------------------------------------------------
BOOL sub_4311F0()
{
    _DWORD* v0; // eax
    int v2[7]; // [esp+0h] [ebp-1Ch]

    sub_486FA0(*(int*)& byte_587000[94032]);
    nullsub_10(v2);
    v2[2] = 22050;
    v2[1] = 0;
    v2[3] = 2;
    v2[4] = 2;
    v2[0] = 4;
    sub_487D00(v2);
    v0 = sub_487150(-1, v2);
    *(_DWORD*)& byte_5D4594[805984] = v0;
    return v0 && sub_487790((int)v0, 16) == 16;
}
// 487CF0: using guessed type void __cdecl nullsub_10(_DWORD);

//----- (00431270) --------------------------------------------------------
void sub_431270()
{
    if (*(_DWORD*)& byte_5D4594[805984])
    {
        sub_487680(*(LPVOID*)& byte_5D4594[805984]);
        *(_DWORD*)& byte_5D4594[805984] = 0;
    }
}

//----- (00431290) --------------------------------------------------------
int* sub_431290()
{
    int* result; // eax

    result = *(int**)& byte_5D4594[805984];
    if (*(_DWORD*)& byte_5D4594[805984])
        result = sub_487970(*(int*)& byte_5D4594[805984], -1);
    return result;
}

//----- (004312B0) --------------------------------------------------------
void sub_4312B0()
{
    sub_431290();
    sub_44D8F0();
    sub_43D990();
}

//----- (004312C0) --------------------------------------------------------
int sub_4312C0()
{
    int result; // eax
    __int64 v1; // rax
    __int64 v2; // kr00_8
    unsigned int v3; // ecx

    result = *(_DWORD*)& byte_5D4594[805988];
    if (!*(_DWORD*)& byte_5D4594[805988])
    {
        *(_DWORD*)& byte_5D4594[805988] = 1;
        v1 = sub_416BB0();
        v2 = v1;
        v3 = (unsigned __int64)(v1 - *(_QWORD*)& byte_5D4594[805996]) >> 32;
        result = v1 - *(_DWORD*)& byte_5D4594[805996];
        if (__PAIR64__(v3, result) > 0x21)
        {
            sub_44D3A0();
            result = sub_43D440();
            *(_QWORD*)& byte_5D4594[805996] = v2;
        }
        *(_DWORD*)& byte_5D4594[805988] = 0;
    }
    return result;
}

//----- (00431330) --------------------------------------------------------
BOOL sub_431330()
{
    return *(_DWORD*)& byte_5D4594[805984] != 0;
}

//----- (00431340) --------------------------------------------------------
int sub_431340()
{
    return 1;
}

//----- (00431370) --------------------------------------------------------
BOOL sub_431370()
{
    return sub_488B60() != 0;
}

//----- (00431380) --------------------------------------------------------
void sub_431380()
{
    sub_488BA0();
    sub_4896E0();
}

//----- (00431390) --------------------------------------------------------
int sub_431390()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[806044];
    if (*(_DWORD*)& byte_5D4594[806044]
        || (result = nox_new_alloc_class("ScreenParticles", 52, 2000),
            (*(_DWORD*)& byte_5D4594[806044] = result) != 0))
    {
        sub_4144D0((_DWORD*)result);
        *(_DWORD*)& byte_5D4594[806048] = 0;
        *(_DWORD*)& byte_5D4594[806052] = 0;
        sub_4313E0();
        result = 1;
    }
    return result;
}

//----- (004313E0) --------------------------------------------------------
int sub_4313E0()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[806012] = sub_4344A0(255, 255, 200);
    *(_DWORD*)& byte_5D4594[806004] = sub_4344A0(50, 150, 255);
    *(_DWORD*)& byte_5D4594[806036] = sub_4344A0(200, 255, 255);
    *(_DWORD*)& byte_5D4594[806024] = sub_4344A0(255, 200, 100);
    *(_DWORD*)& byte_5D4594[806040] = sub_4344A0(200, 255, 200);
    *(_DWORD*)& byte_5D4594[806020] = sub_4344A0(255, 255, 0);
    *(_DWORD*)& byte_5D4594[806028] = sub_4344A0(0, 0, 255);
    *(_DWORD*)& byte_5D4594[806016] = sub_4344A0(128, 128, 255);
    *(_DWORD*)& byte_5D4594[806008] = sub_4344A0(255, 128, 64);
    result = sub_4344A0(0, 255, 0);
    *(_DWORD*)& byte_5D4594[806032] = result;
    return result;
}

//----- (004314D0) --------------------------------------------------------
void sub_4314D0()
{
    if (*(_DWORD*)& byte_5D4594[806044])
        nox_free_alloc_class(*(LPVOID*)& byte_5D4594[806044]);
    *(_DWORD*)& byte_5D4594[806044] = 0;
    *(_DWORD*)& byte_5D4594[806048] = 0;
    *(_DWORD*)& byte_5D4594[806052] = 0;
}

//----- (00431510) --------------------------------------------------------
int sub_431510()
{
    if (*(_DWORD*)& byte_5D4594[806044])
        sub_4144D0(*(_DWORD * *)& byte_5D4594[806044]);
    *(_DWORD*)& byte_5D4594[806048] = 0;
    *(_DWORD*)& byte_5D4594[806052] = 0;
    return sub_4313E0();
}

//----- (00431540) --------------------------------------------------------
_DWORD* __cdecl sub_431540(int a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, char a9, char a10)
{
    int v10; // edi
    int v11; // ebx
    _DWORD* v12; // esi

    if (!*(_DWORD*)& byte_5D4594[806044])
        return 0;
    switch (a1)
    {
        case 0:
            v10 = *(_DWORD*)& byte_5D4594[806016];
            v11 = *(_DWORD*)& byte_5D4594[806036];
            break;
        case 1:
            v10 = *(_DWORD*)& byte_5D4594[806028];
            v11 = *(_DWORD*)& byte_5D4594[806004];
            break;
        case 2:
            v10 = *(_DWORD*)& byte_5D4594[806032];
            v11 = *(_DWORD*)& byte_5D4594[806040];
            break;
        case 3:
            v10 = *(_DWORD*)& byte_5D4594[806020];
            v11 = *(_DWORD*)& byte_5D4594[806012];
            break;
        case 4:
            v10 = *(_DWORD*)& byte_5D4594[806008];
            v11 = *(_DWORD*)& byte_5D4594[806024];
            break;
        default:
            return 0;
    }
    v12 = nox_alloc_class_new_obj_zero(*(_DWORD * *)& byte_5D4594[806044]);
    if (v12)
        goto LABEL_11;
    v12 = *(_DWORD * *)& byte_5D4594[806052];
    if (!*(_DWORD*)& byte_5D4594[806052])
        return 0;
    sub_4316C0(*(int*)& byte_5D4594[806052]);
    LABEL_11:
    v12[6] = a2 << 16;
    v12[7] = a3 << 16;
    *((_BYTE*)v12 + 41) = a8;
    *((_BYTE*)v12 + 43) = a8;
    *((_BYTE*)v12 + 40) = a7;
    *((_BYTE*)v12 + 42) = a9;
    *v12 = sub_489700;
    v12[4] = a4 << 16;
    v12[5] = a5 << 16;
    v12[9] = a6 << 16;
    *((_BYTE*)v12 + 32) = a10;
    v12[2] = v10;
    v12[3] = v11;
    v12[1] = a1;
    sub_431680((int)v12);
    if (!v12[9] && !*((_BYTE*)v12 + 41))
    {
        *((_BYTE*)v12 + 42) = 2;
        *((_BYTE*)v12 + 41) = 3;
        *((_BYTE*)v12 + 43) = 3;
    }
    return v12;
}

//----- (00431680) --------------------------------------------------------
int __cdecl sub_431680(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(a1 + 44) = *(_DWORD*)& byte_5D4594[806048];
    *(_DWORD*)(a1 + 48) = 0;
    if (*(_DWORD*)& byte_5D4594[806048])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[806048] + 48) = a1;
    else
        *(_DWORD*)& byte_5D4594[806052] = a1;
    *(_DWORD*)& byte_5D4594[806048] = a1;
    return result;
}

//----- (004316C0) --------------------------------------------------------
int __cdecl sub_4316C0(int a1)
{
    int result; // eax
    int v2; // ecx
    int v3; // ecx

    result = a1;
    if (a1 == *(_DWORD*)& byte_5D4594[806052])
        * (_DWORD*)& byte_5D4594[806052] = *(_DWORD*)(a1 + 48);
    v2 = *(_DWORD*)(a1 + 44);
    if (v2)
        * (_DWORD*)(v2 + 48) = *(_DWORD*)(a1 + 48);
    v3 = *(_DWORD*)(a1 + 48);
    if (v3)
    {
        result = *(_DWORD*)(a1 + 44);
        *(_DWORD*)(v3 + 44) = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[806048] = *(_DWORD*)(a1 + 44);
    }
    return result;
}

//----- (00431700) --------------------------------------------------------
void __cdecl sub_431700(_QWORD* a1)
{
    sub_4316C0((int)a1);
    sub_414330(*(unsigned int**)& byte_5D4594[806044], a1);
}

//----- (00431720) --------------------------------------------------------
void __cdecl sub_431720(int* a1)
{
    int v1; // eax
    int v2; // esi

    if (a1)
    {
        sub_430B50(*a1, a1[1], a1[2], a1[3]);
        v1 = *(_DWORD*)& byte_5D4594[806048];
        if (*(_DWORD*)& byte_5D4594[806048])
        {
            do
            {
                *(_DWORD*)& byte_5D4594[3799524] = 1;
                v2 = *(_DWORD*)(v1 + 44);
                (*(int(__cdecl * *)(int*, int))v1)(a1, v1);
                v1 = v2;
            } while (v2);
        }
    }
}

//----- (00431770) --------------------------------------------------------
char* sub_431770()
{
    return (char*)& byte_5D4594[807172];
}

//----- (00431780) --------------------------------------------------------
char* sub_431780()
{
    return (char*)& byte_5D4594[806060];
}

//----- (00431790) --------------------------------------------------------
char* __cdecl sub_431790(char* a1)
{
    char* result; // eax

    result = a1;
    if (a1)
        result = strncpy((char*)& byte_5D4594[806060], a1, 0x17u);
    return result;
}

//----- (004317B0) --------------------------------------------------------
int __cdecl sub_4317B0(const char* path, int a2)
{
    FILE* v2; // eax
    FILE* v3; // esi
    int result; // eax
    FILE* v5; // esi
    int v6; // eax
    FILE* v7; // [esp-4h] [ebp-Ch]

    sub_42CD90();
    v2 = fopen(path, "r");
    v3 = v2;
    if (v2)
    {
        if (a2 || sub_431890(v2))
        {
            v6 = sub_4331E0(v3, a2);
            v7 = v3;
            if (v6)
            {
                fclose(v3);
                return 1;
            }
        }
        else
        {
            v7 = v3;
        }
        fclose(v7);
    }
    sub_42CD90();
    result = fopen("default.cfg", "r");
    v5 = (FILE*)result;
    if (!result)
    {
        return result;
    }
    if (!(a2 || sub_431890((FILE*)result)))
    {
        fclose(v5);
        return 0;
    }
    if (!sub_4331E0(v5, a2))
    {
        fclose(v5);
        return 0;
    }
    fclose(v5);
    sub_433290("nox.cfg");
    return 1;
}

//----- (00431890) --------------------------------------------------------
int __cdecl sub_431890(FILE* a1)
{
    char* v1; // eax
    char* v2; // eax
    const char* v3; // edi
    int v4; // edx
    unsigned __int8* v5; // ebp

    sub_486670(0x4000, 0);
    sub_486670(0x4000, 1);
    sub_486670(0x4000, 2);
    LABEL_2:
    while (fgets((char*)& byte_5D4594[806084], 1024, a1))
    {
        if (byte_5D4594[806084] == 35)
        {
            continue;
        }
        v1 = strtok((char*)& byte_5D4594[806084], " \r\t\n");
        if (!v1)
        {
            continue;
        }
        if (!strcmp(v1, "---"))
            return 1;
        if (!strcmp(v1, "Version"))
        {
            v2 = (char*)sub_432AD0((int*)& byte_587000[81284]);
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "VideoMode"))
        {
            v2 = (char*)sub_432B00();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "VideoSize"))
        {
            v2 = (char*)sub_432BD0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "Gamma"))
        {
            v2 = (char*)sub_432C00();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "FXVolume"))
        {
            v2 = (char*)sub_432CB0(0);
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "DialogVolume"))
        {
            v2 = (char*)sub_432CB0(1);
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "MusicVolume"))
        {
            v2 = (char*)sub_432CB0(2);
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "LastServer"))
        {
            v2 = (char*)sub_431FC0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "ServerName"))
        {
            v2 = (char*)sub_432010();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "UnlockSurface"))
        {
            v2 = (char*)sub_4320B0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "SoftShadowEdge"))
        {
            v2 = (char*)sub_432100();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "DrawFrontWalls"))
        {
            v2 = (char*)sub_432150();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "TranslucentFrontWalls"))
        {
            v2 = (char*)sub_4321A0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "HighResFrontWalls"))
        {
            v2 = (char*)sub_4321F0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "HighResFloors"))
        {
            v2 = (char*)sub_432240();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "LockHighResFloors"))
        {
            v2 = (char*)sub_432290();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "TexturedFloors"))
        {
            v2 = (char*)sub_4322E0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "TranslucentConsole"))
        {
            v2 = (char*)sub_432340();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "RenderGlow"))
        {
            v2 = (char*)sub_432390();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "RenderGUI"))
        {
            v2 = (char*)sub_4323E0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "FadeObjects"))
        {
            v2 = (char*)sub_432430();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "TrackData"))
        {
            v2 = (char*)sub_433190();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "RenderBubbles"))
        {
            v2 = (char*)sub_432480();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "SysopPassword"))
        {
            v2 = (char*)sub_4324D0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "ServerPassword"))
        {
            v2 = (char*)sub_432520();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "Profiled"))
        {
            v2 = (char*)sub_432590();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "SanctuaryHelp"))
        {
            v2 = (char*)sub_432620();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "MaxPacketLossPct"))
        {
            v2 = (char*)sub_4325D0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "SendMessageOfTheDay"))
        {
            v2 = (char*)sub_432A90();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "InternetUpdateRate"))
        {
            v2 = (char*)sub_432DF0();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "ConnectionType"))
        {
            v2 = (char*)sub_433050();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "MapCycle"))
        {
            v2 = (char*)sub_432C30();
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "LANFilters"))
        {
            v2 = sub_432E50(0);
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "INETFilters"))
        {
            v2 = sub_432E50(1);
            if (!v2)
                return 0;
        }
        else if (!strcmp(v1, "LessonLimit"))
        {
            if (!sub_432D10())
                return 0;
        }
        else if (!strcmp(v1, "TimeLimit"))
        {
            if (!sub_432D80())
                return 0;
        }
        else if (!strcmp(v1, "PlayerSkeletons"))
        {
            if (!sub_4327C0())
                return 0;
        }
        else if (!strcmp(v1, "BroadcastGestures"))
        {
            if (!sub_432810())
                return 0;
        }
        else if (!strcmp(v1, "LatencyCompensation"))
        {
            if (!sub_432970())
                return 0;
        }
        else if (!strcmp(v1, "Closed"))
        {
            if (!sub_432860())
                return 0;
        }
        else if (!strcmp(v1, "Private"))
        {
            if (!sub_4328C0())
                return 0;
        }
        else if (!strcmp(v1, "AudioThreshold"))
        {
            if (!sub_433130())
                return 0;
        }
        else if (!strcmp(v1, "MaxPlayers"))
        {
            if (!sub_4330C0())
                return 0;
        }
        else if (!strcmp(v1, "RestrictedClasses"))
        {
            if (!sub_432920())
                return 0;
        }
        else if (!strcmp(v1, "RestrictedPing"))
        {
            if (!sub_4329D0())
                return 0;
        }
        else if (!strcmp(v1, "LimitMaxRes"))
        {
            if (!sub_432A30())
                return 0;
        }
        else if (!strcmp(v1, "ItemRespawn"))
        {
            if (!sub_432660())
                return 0;
        }
        else if (!strcmp(v1, "CamperAlarm"))
        {
            if (!sub_4326B0())
                return 0;
        }
        else if (!strcmp(v1, "MinKickVotes"))
        {
            if (!sub_432700())
                return 0;
        }
        else if (!strcmp(v1, "ResetQuestMinVotes"))
        {
            if (!sub_432740())
                return 0;
        }
        else if (!strcmp(v1, "KickQuestPlayerMinVotes"))
        {
            if (!sub_432780())
                return 0;
        }
        else if (!strcmp(v1, "Fullscreen"))
        {
            const char* token;
            strtok(NULL, " \r\t\n");
            token = strtok(NULL, " \r\t\n");
            if (token)
            {
                g_fullscreen_cfg = atoi(token);
                if (g_fullscreen <= -4)
                {
                    g_fullscreen = g_fullscreen_cfg;
                }
            }

            change_windowed_fullscreen();
        }
        else if (!strcmp(v1, "Gamma2"))
        {
            const char* token;
            strtok(NULL, " \r\t\n");
            token = strtok(NULL, " \r\t\n");
            if (token)
                draw_gamma = atof(token);
        }
        else if (!strcmp(v1, "Stretched"))
        {
            const char* token;
            strtok(NULL, " \r\t\n");
            token = strtok(NULL, " \r\t\n");
            if (token)
            {
                g_scaled_cfg = atoi(token);
                if (g_scaled >= 0)
                {
                    g_scaled = g_scaled_cfg;
                }
            }
        }
        else if (!strcmp(v1, "InputSensitivity"))
        {
            const char* token;
            strtok(NULL, " \r\t\n");
            token = strtok(NULL, " \r\t\n");
            if (token)
                input_sensitivity = atof(token);
        }
        else
        {
            v3 = *(const char**)& byte_587000[81168];
            v4 = 0;
            if (*(_DWORD*)& byte_587000[81168])
            {
                v5 = &byte_587000[81168];
                while (strcmp(v1, v3))
                {
                    v3 = (const char*) * ((_DWORD*)v5 + 2);
                    v5 += 8;
                    ++v4;
                    if (!v3)
                        goto LABEL_2;
                }
                v2 = (char*)sub_432C70(*(_DWORD*)& byte_587000[8 * v4 + 81172]);
                if (!v2)
                    return 0;
            }
        }
    }
    return 0;
}

//----- (00431FC0) --------------------------------------------------------
int sub_431FC0()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        strncpy((char*)& byte_5D4594[806060], v0, 0x16u);
    else
        byte_5D4594[806060] = byte_5D4594[807272];
    return 1;
}

//----- (00432010) --------------------------------------------------------
int sub_432010()
{
    char* v0; // eax
    const char* v1; // esi
    int result; // eax
    char* v3; // eax
    char v4; // cl
    char v5[64]; // [esp+4h] [ebp-40h]

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    v1 = v0;
    if (v0)
    {
        if (*(_DWORD*)& byte_587000[81284] == 0x10000 && !_strcmpi(v0, "NoxWorld"))
            v1 = "User_Game";
        strncpy(v5, v1, 0x3Fu);
        v3 = v5;
        if (v5[0])
        {
            do
            {
                if (*v3 == 95)
                    * v3 = 32;
                v4 = *++v3;
            } while (v4);
        }
        sub_40A440(v5);
        result = 1;
    }
    else
    {
        sub_40A440(0);
        result = 1;
    }
    return result;
}

//----- (004320B0) --------------------------------------------------------
int sub_4320B0()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_5D4594[805868] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_5D4594[805868] = 1;
    return result;
}

//----- (00432100) --------------------------------------------------------
int sub_432100()
{
    char* v0; // eax
    bool v1; // zf
    int v2; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = atoi(v0) == 0;
        v2 = *(_DWORD*)& byte_5D4594[2650636];
        if (!v1)
        {
            BYTE1(v2) |= 4u;
            *(_DWORD*)& byte_5D4594[2650636] = v2;
            return 1;
        }
        BYTE1(v2) &= 0xFBu;
        *(_DWORD*)& byte_5D4594[2650636] = v2;
    }
    return 1;
}

//----- (00432150) --------------------------------------------------------
int sub_432150()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[80812] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[80812] = 1;
    return result;
}

//----- (004321A0) --------------------------------------------------------
int sub_4321A0()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_5D4594[805844] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_5D4594[805844] = 1;
    return result;
}

//----- (004321F0) --------------------------------------------------------
int sub_4321F0()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[80820] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[80820] = 1;
    return result;
}

//----- (00432240) --------------------------------------------------------
int sub_432240()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[154952] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[154952] = 1;
    return result;
}

//----- (00432290) --------------------------------------------------------
int sub_432290()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_5D4594[1193152] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_5D4594[1193152] = 1;
    return result;
}

//----- (004322E0) --------------------------------------------------------
int sub_4322E0()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        *(_DWORD*)& byte_587000[154956] = atoi(v0);
        *(_DWORD*)& byte_587000[154956] = *(_DWORD*)& byte_587000[154956] != 0;
        sub_481420();
        *(_DWORD*)& byte_5D4594[1193156] = 0;
        *(_DWORD*)& byte_587000[154960] = *(_DWORD*)& byte_587000[154956];
    }
    return 1;
}

//----- (00432340) --------------------------------------------------------
int sub_432340()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[80824] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[80824] = 1;
    return result;
}

//----- (00432390) --------------------------------------------------------
int sub_432390()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_5D4594[805852] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_5D4594[805852] = 1;
    return result;
}

//----- (004323E0) --------------------------------------------------------
int sub_4323E0()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[80828] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[80828] = 1;
    return result;
}

//----- (00432430) --------------------------------------------------------
int sub_432430()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[80836] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[80836] = 1;
    return result;
}

//----- (00432480) --------------------------------------------------------
int sub_432480()
{
    char* v0; // eax
    int v1; // eax
    bool v2; // zf
    int result; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = atoi(v0);
    *(_DWORD*)& byte_587000[80844] = v1;
    v2 = v1 == 0;
    result = 1;
    if (!v2)
        * (_DWORD*)& byte_587000[80844] = 1;
    return result;
}

//----- (004324D0) --------------------------------------------------------
int sub_4324D0()
{
    char* v0; // eax
    wchar_t v2[100]; // [esp+0h] [ebp-C8h]

    strtok(0, " \r\t\n");
    v0 = strtok(0, "\r\t\n");
    if (v0)
    {
        nox_swprintf(v2, L"%S", v0);
        sub_40A610(v2);
    }
    return 1;
}

//----- (00432520) --------------------------------------------------------
int sub_432520()
{
    char* v0; // esi
    char* v1; // eax
    wchar_t v3[100]; // [esp+4h] [ebp-C8h]

    v0 = sub_416640();
    strtok(0, " \r\t\n");
    v1 = strtok(0, "\r\t\n");
    if (v1)
    {
        nox_swprintf(v3, L"%S", v1);
        nox_wcsncpy((wchar_t*)v0 + 39, v3, 8u);
        *((_WORD*)v0 + 47) = 0;
    }
    return 1;
}

//----- (00432590) --------------------------------------------------------
int sub_432590()
{
#ifdef __EMSCRIPTEN__
    * (_DWORD*)& byte_5D4594[805856] = 1;
    return 1;
#endif
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        * (_DWORD*)& byte_5D4594[805856] = atoi(v0) != 0;
    return 1;
}

//----- (004325D0) --------------------------------------------------------
int sub_4325D0()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        *(_DWORD*)& byte_587000[81280] = atoi(v0);
        *(_DWORD*)& byte_587000[292940] = (__int64)((double) * (int*)& byte_587000[81280] * 0.0099999998 * 10.0);
    }
    return 1;
}

//----- (00432620) --------------------------------------------------------
int sub_432620()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        * (_DWORD*)& byte_587000[54276] = atoi(v0) != 0;
    return 1;
}

//----- (00432660) --------------------------------------------------------
int sub_432660()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        if (atoi(v0))
        {
            sub_409E70(2);
            return 1;
        }
        sub_409EC0(2);
    }
    return 1;
}

//----- (004326B0) --------------------------------------------------------
int sub_4326B0()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        if (atoi(v0))
        {
            sub_409E70(0x2000);
            return 1;
        }
        sub_409EC0(0x2000);
    }
    return 1;
}

//----- (00432700) --------------------------------------------------------
int sub_432700()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        * (_DWORD*)& byte_587000[229980] = atoi(v0);
    return 1;
}

//----- (00432740) --------------------------------------------------------
int sub_432740()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        * (_DWORD*)& byte_587000[229988] = atoi(v0);
    return 1;
}

//----- (00432780) --------------------------------------------------------
int sub_432780()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        * (_DWORD*)& byte_587000[229992] = atoi(v0);
    return 1;
}

//----- (004327C0) --------------------------------------------------------
int sub_4327C0()
{
    char* v0; // esi
    char* v1; // edi

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        *(_DWORD*)(v1 + 58) = atoi(v0) > 0;
    }
    return 1;
}

//----- (00432810) --------------------------------------------------------
int sub_432810()
{
    char* v0; // esi
    char* v1; // edi

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        *(_DWORD*)(v1 + 62) = atoi(v0) > 0;
    }
    return 1;
}

//----- (00432860) --------------------------------------------------------
int sub_432860()
{
    char* v0; // edi
    char* v1; // esi
    bool v2; // cc
    char v3; // al

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        v2 = atoi(v0) <= 0;
        v3 = v1[100];
        if (!v2)
        {
            v1[100] = v3 | 0x10;
            return 1;
        }
        v1[100] = v3 & 0xEF;
    }
    return 1;
}

//----- (004328C0) --------------------------------------------------------
int sub_4328C0()
{
    char* v0; // edi
    char* v1; // esi
    bool v2; // cc
    char v3; // al

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        v2 = atoi(v0) <= 0;
        v3 = v1[100];
        if (!v2)
        {
            v1[100] = v3 | 0x20;
            return 1;
        }
        v1[100] = v3 & 0xDF;
    }
    return 1;
}

//----- (00432920) --------------------------------------------------------
int sub_432920()
{
    char* v0; // edi
    char* v1; // esi

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        v1[100] |= atoi(v0) & 7;
    }
    return 1;
}

//----- (00432970) --------------------------------------------------------
int sub_432970()
{
    char* v0; // edi
    char* v1; // esi
    char* v2; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        *(_DWORD*)(v1 + 66) = atoi(v0);
        v2 = strtok(0, " \r\t\n");
        if (v2)
            * (_DWORD*)(v1 + 70) = atoi(v2);
    }
    return 1;
}

//----- (004329D0) --------------------------------------------------------
int sub_4329D0()
{
    char* v0; // edi
    char* v1; // esi
    char* v2; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        *(_WORD*)(v1 + 105) = atoi(v0);
        v2 = strtok(0, " \r\t\n");
        if (v2)
            * (_WORD*)(v1 + 107) = atoi(v2);
    }
    return 1;
}

//----- (00432A30) --------------------------------------------------------
int sub_432A30()
{
    char* v0; // edi
    char* v1; // esi
    bool v2; // cc
    char v3; // al

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        v2 = atoi(v0) <= 0;
        v3 = v1[102];
        if (!v2)
        {
            v1[102] = v3 | 0x80;
            return 1;
        }
        v1[102] = v3 & 0x7F;
    }
    return 1;
}

//----- (00432A90) --------------------------------------------------------
int sub_432A90()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        * (_DWORD*)& byte_587000[108752] = atoi(v0) != 0;
    return 1;
}

//----- (00432AD0) --------------------------------------------------------
int __cdecl sub_432AD0(int* a1)
{
    char* v1; // eax

    strtok(0, " \r\t\n");
    v1 = strtok(0, " \r\t\n");
    *a1 = atoi(v1);
    return 1;
}

//----- (00432B00) --------------------------------------------------------
int sub_432B00()
{
    char* v0; // eax
    char* v2; // eax
    char* v4; // eax
    int v5; // eax
    int v6; // esi

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    int w = atoi(v0);
    v2 = strtok(0, " \r\t\n");
    int h = atoi(v2);
    v4 = strtok(0, " \r\t\n");
    v5 = atoi(v4);
    v6 = v5;
    if (v5 == 8)
    {
        if (!sub_4300D0(0))
            v6 = 16;
    }
    else if (v5 == 16)
    {
        if (!sub_4300D0(1))
            v6 = 8;
    }
    else
    {
        v6 = sub_4300D0(1) ? 16 : 8;
    }
#ifdef __EMSCRIPTEN__
    w = EM_ASM_INT(return Module['ingameWidth']());
    h = EM_ASM_INT(return Module['ingameHeight']());
#endif
    v6 = 16; // 8 bit not supported
    if (!(byte_5D4594[2650637] & 2))
    {
        nox_win_width_1 = w;
        nox_win_height_1 = h;
        nox_win_depth_1 = v6;
        nox_win_depth_2 = v6;

        change_windowed_fullscreen();
    }
    return 1;
}

//----- (00432BD0) --------------------------------------------------------
int sub_432BD0()
{
    char* v0; // eax
    int v1; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    v1 = atoi(v0);
    sub_4766A0(v1);
    return 1;
}

//----- (00432C00) --------------------------------------------------------
int sub_432C00()
{
    char* v0; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    *(_DWORD*)& byte_587000[80852] = atoi(v0);
    return 1;
}

//----- (00432C30) --------------------------------------------------------
int sub_432C30()
{
    char* v0; // eax
    int v1; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = atoi(v0);
        sub_4D0D90(v1 != 0);
    }
    return 1;
}

//----- (00432C70) --------------------------------------------------------
int __cdecl sub_432C70(int a1)
{
    char* v1; // eax
    int v2; // eax

    strtok(0, " \r\t\n");
    v1 = strtok(0, " \r\t\n");
    if (v1)
    {
        v2 = atoi(v1);
        sub_4D0DC0(a1, v2);
    }
    return 1;
}

//----- (00432CB0) --------------------------------------------------------
int __cdecl sub_432CB0(int a1)
{
    char* v1; // eax
    unsigned int v2; // eax
    int result; // eax

    strtok(0, " \r\t\n");
    v1 = strtok(0, " \r\t\n");
    v2 = atoi(v1);
    if ((v2 & 0x80000000) == 0)
    {
        if (v2 > 0x4000)
            v2 = 0x4000;
        sub_486670(v2, a1);
        result = 1;
    }
    else
    {
        sub_486670(0, a1);
        result = 1;
    }
    return result;
}

//----- (00432D10) --------------------------------------------------------
int sub_432D10()
{
    char* v0; // eax
    char* v1; // eax
    unsigned __int8* v2; // esi
    unsigned __int16 v3; // ax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = strtok(v0, ",\r\n");
    if (!v1)
        return 1;
    v2 = &byte_587000[81224];
    do
    {
        v3 = atoi(v1);
        sub_409FB0(*(_DWORD*)v2, v3);
        v2 += 4;
        v1 = strtok(0, ",\r\n");
    } while (v1);
    return 1;
}

//----- (00432D80) --------------------------------------------------------
int sub_432D80()
{
    char* v0; // eax
    char* v1; // eax
    unsigned __int8* v2; // esi
    unsigned __int8 v3; // al

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = strtok(v0, ",\r\n");
    if (!v1)
        return 1;
    v2 = &byte_587000[81224];
    do
    {
        v3 = atoi(v1);
        sub_40A040(*(_DWORD*)v2, v3);
        v2 += 4;
        v1 = strtok(0, ",\r\n");
    } while (v1);
    return 1;
}

//----- (00432DF0) --------------------------------------------------------
int sub_432DF0()
{
    char* v0; // eax
    int v1; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = atoi(v0);
        sub_40A6D0(v1);
        if (sub_40A6C0() <= 0 || sub_40A6C0() > 3)
            sub_40A6D0(1);
    }
    return 1;
}

//----- (00432E50) --------------------------------------------------------
char* __cdecl sub_432E50(int a1)
{
    char* v1; // eax
    char* result; // eax
    int v3; // esi
    char* v4; // eax
    int v5[11]; // [esp+4h] [ebp-2Ch]

    strtok(0, " \r\t\n");
    v1 = strtok(0, " \r\t\n");
    if (!v1)
        return (char*)1;
    result = strtok(v1, ",\r\n");
    if (result)
    {
        v3 = atoi(result);
        result = strtok(0, ",\r\n");
        if (result)
        {
            v5[0] = atoi(result);
            result = strtok(0, ",\r\n");
            if (result)
            {
                v5[1] = *result == 49;
                result = strtok(0, ",\r\n");
                if (result)
                {
                    v5[2] = *result == 49;
                    result = strtok(0, ",\r\n");
                    if (result)
                    {
                        v5[3] = atoi(result);
                        result = strtok(0, ",\r\n");
                        if (result)
                        {
                            v5[4] = atoi(result);
                            result = strtok(0, ",\r\n");
                            if (result)
                            {
                                v5[5] = *result == 49;
                                result = strtok(0, ",\r\n");
                                if (result)
                                {
                                    v5[6] = *result == 49;
                                    result = strtok(0, ",\r\n");
                                    if (result)
                                    {
                                        v5[7] = *result == 49;
                                        result = strtok(0, ",\r\n");
                                        if (result)
                                        {
                                            v5[8] = *result == 49;
                                            result = strtok(0, ",\r\n");
                                            if (result)
                                            {
                                                v5[9] = *result == 49;
                                                v4 = strtok(0, ",\r\n");
                                                if (v4)
                                                    v5[10] = *v4 == 49;
                                                else
                                                    v5[10] = 0;
                                                sub_489FF0(a1, v3, v5);
                                                return (char*)1;
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

//----- (00433050) --------------------------------------------------------
int sub_433050()
{
    char* v0; // eax
    int v1; // eax
    unsigned __int8* i; // ecx
    int v3; // edx

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = atoi(v0);
        if (*(_DWORD*)& byte_587000[81248])
        {
            for (i = &byte_587000[81248]; *((_DWORD*)i + 1) != v1; i += 8)
            {
                v3 = *((_DWORD*)i + 2);
                if (!v3)
                    return 1;
            }
            if (v1 < 0 && v1 > 4)
                v1 = 4;
            *(_DWORD*)& byte_5D4594[3596] = v1;
        }
    }
    return 1;
}

//----- (004330C0) --------------------------------------------------------
int sub_4330C0()
{
    char* v0; // edi
    char* v1; // esi
    char v2; // al

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (!v0)
        return 1;
    v1 = sub_416640();
    v2 = atoi(v0);
    v1[104] = v2;
    if ((unsigned __int8)v2 <= 0x20u)
    {
        if ((unsigned __int8)v2 < 1u)
        v1[104] = 1;
    }
    else
    {
        v1[104] = 32;
    }
    sub_409F80((unsigned __int8)v1[104]);
    return 1;
}

//----- (00433130) --------------------------------------------------------
int sub_433130()
{
    char* v0; // edi
    char* v1; // esi
    int v2; // eax

    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
    {
        v1 = sub_416640();
        v2 = atoi(v0);
        *(_DWORD*)(v1 + 74) = v2;
        if (v2 > 100)
        {
            *(_DWORD*)(v1 + 74) = 100;
            return 1;
        }
        if (v2 < 0)
            * (_DWORD*)(v1 + 74) = 0;
    }
    return 1;
}

//----- (00433190) --------------------------------------------------------
int sub_433190()
{
    char* v0; // eax
    char v2; // [esp+0h] [ebp-4h]

    v2 = 0;
    strtok(0, " \r\t\n");
    v0 = strtok(0, " \r\t\n");
    if (v0)
        v2 = atoi(v0);
    sub_578DE0(v2);
    return 1;
}

//----- (004331E0) --------------------------------------------------------
int __cdecl sub_4331E0(FILE* a1, int a2)
{
    int v2; // edi
    int result; // eax

    v2 = 0;
    if (a2)
    {
        while (fgets((char*)& byte_5D4594[806084], 1024, a1))
        {
            if (!strncmp("---", (const char*)& byte_5D4594[806084], 3u))
                goto LABEL_6;
        }
        result = 1;
    }
    else
    {
        LABEL_6:
        do
        {
            do
            {
                if (!fgets((char*)& byte_5D4594[806084], 1024, a1))
                    return v2;
            } while (byte_5D4594[806084] == 35);
            if (!strncmp("---", (const char*)& byte_5D4594[806084], 3u))
                return 1;
        } while (sub_42CF50((const char*)& byte_5D4594[806084]));
        result = 0;
    }
    return result;
}

//----- (00433290) --------------------------------------------------------
void __cdecl sub_433290(char* a1)
{
    FILE* f = fopen(a1, "w");
    if (!f)
    {
        return;
    }
    sub_4332E0(f);
    sub_42CDF0(f);
    fprintf(f, "---\n");
    fclose(f);
#ifdef __EMSCRIPTEN__
    EM_ASM(FS.syncfs(false, function(err) {}));
#endif
}

//----- (004332E0) --------------------------------------------------------
int __cdecl sub_4332E0(FILE* a1)
{
    char* v1; // edi
    int v2; // eax
    int v3; // eax
    int v4; // eax
    int v5; // eax
    char* v6; // eax
    unsigned __int8 v7; // al
    wchar_t* v8; // eax
    BOOL v9; // eax
    int v10; // eax
    unsigned int v11; // eax
    unsigned int v12; // ecx
    int v13; // eax
    unsigned int v14; // eax
    BOOL v15; // eax
    int v16; // eax
    int v17; // eax
    unsigned __int8* v18; // ebx
    unsigned __int8* v19; // edi
    int v20; // eax
    int v21; // eax
    _DWORD* v23; // [esp+8h] [ebp-4h]

    v1 = sub_416640();
    fprintf(a1, "Version = %d\n", 65540);
    fprintf(
            a1,
            "VideoMode = %d %d %d\n",
            nox_win_width_1,
            nox_win_height_1,
            nox_win_depth_1);
    fprintf(a1, "Stretched = %d\n", g_scaled_cfg);
    fprintf(a1, "Fullscreen = %d\n", g_fullscreen_cfg);
    v2 = sub_4766D0();
    fprintf(a1, "VideoSize = %d\n", v2);
    // fprintf(a1, "Gamma = %d\n", *(_DWORD *)&byte_587000[80852]);
    fprintf(a1, "Gamma2 = %f\n", draw_gamma);
    fprintf(a1, "InputSensitivity = %f\n", input_sensitivity);
    if (sub_453070() == 1)
        v3 = *(_DWORD*)(*(_DWORD*)& byte_587000[127004] + 4) >> 16;
    else
        v3 = 0;
    fprintf(a1, "FXVolume = %d\n", v3);
    if (sub_44D990() == 1)
        v4 = *(_DWORD*)(*(_DWORD*)& byte_587000[122852] + 4) >> 16;
    else
        v4 = 0;
    fprintf(a1, "DialogVolume = %d\n", v4);
    if (sub_43DC30() == 1)
        v5 = *(_DWORD*)(*(_DWORD*)& byte_587000[93164] + 4) >> 16;
    else
        v5 = 0;
    fprintf(a1, "MusicVolume = %d\n", v5);
    fprintf(a1, "LastServer = %s\n", &byte_5D4594[806060]);
    v6 = sub_433890();
    fprintf(a1, "ServerName = %s\n", v6);
    fprintf(a1, "UnlockSurface = %d\n", *(_DWORD*)& byte_5D4594[805868]);
    fprintf(a1, "SoftShadowEdge = %d\n", (*(_DWORD*)& byte_5D4594[2650636] >> 10) & 1);
    fprintf(a1, "DrawFrontWalls = %d\n", *(_DWORD*)& byte_587000[80812]);
    fprintf(a1, "TranslucentFrontWalls = %d\n", *(_DWORD*)& byte_5D4594[805844]);
    fprintf(a1, "HighResFrontWalls = %d\n", *(_DWORD*)& byte_587000[80820]);
    fprintf(a1, "HighResFloors = %d\n", *(_DWORD*)& byte_587000[154952]);
    fprintf(a1, "LockHighResFloors = %d\n", *(_DWORD*)& byte_5D4594[1193152]);
    fprintf(a1, "TexturedFloors = %d\n", *(_DWORD*)& byte_587000[154956]);
    fprintf(a1, "TranslucentConsole = %d\n", *(_DWORD*)& byte_587000[80824]);
    fprintf(a1, "RenderGlow = %d\n", *(_DWORD*)& byte_5D4594[805852]);
    fprintf(a1, "RenderGUI = %d\n", *(_DWORD*)& byte_587000[80828]);
    fprintf(a1, "FadeObjects = %d\n", *(_DWORD*)& byte_587000[80836]);
    fprintf(a1, "RenderBubbles = %d\n", *(_DWORD*)& byte_587000[80844]);
    v7 = sub_578DF0();
    fprintf(a1, "TrackData = %d\n", v7);
    v8 = sub_40A630();
    fprintf(a1, "SysopPassword = %S\n", v8);
    fprintf(a1, "ServerPassword = %S\n", v1 + 78);
    fprintf(a1, "Profiled = %d\n", *(_DWORD*)& byte_5D4594[805856] != 0);
    fprintf(a1, "SanctuaryHelp = %d\n", *(_DWORD*)& byte_587000[54276]);
    fprintf(a1, "MaxPacketLossPct = %d\n", *(_DWORD*)& byte_587000[81280]);
    fprintf(a1, "SendMessageOfTheDay = %d\n", *(_DWORD*)& byte_587000[108752]);
    v9 = sub_4D0D70();
    fprintf(a1, "MapCycle = %d\n", v9);
    fprintf(a1, "ConnectionType = %d\n", *(_DWORD*)& byte_5D4594[3596]);
    v10 = sub_40A6C0();
    fprintf(a1, "InternetUpdateRate = %d\n", v10);
    fprintf(a1, "LessonLimit =");
    sub_4337B0(a1);
    fprintf(a1, "TimeLimit =");
    sub_433820(a1);
    fprintf(a1, "PlayerSkeletons = %d\n", *(_DWORD*)(v1 + 58));
    fprintf(a1, "BroadcastGestures = %d\n", *(_DWORD*)(v1 + 62));
    v11 = fprintf(a1, "LatencyCompensation = %d %d\n", *(_DWORD*)(v1 + 66), *(_DWORD*)(v1 + 70));
    LOBYTE(v11) = v1[100];
    fprintf(a1, "Closed = %d\n", (v11 >> 4) & 1);
    LOBYTE(v12) = v1[100];
    fprintf(a1, "Private = %d\n", (v12 >> 5) & 1);
    fprintf(a1, "AudioThreshold = %d\n", *(_DWORD*)(v1 + 74));
    v13 = sub_409FA0();
    fprintf(a1, "MaxPlayers = %d\n", v13);
    fprintf(a1, "RestrictedClasses = %d\n", v1[100] & 7);
    fprintf(a1, "RestrictedPing = %d %d\n", *(unsigned __int16*)(v1 + 105), *(unsigned __int16*)(v1 + 107));
    fprintf(a1, "LimitMaxRes = %d\n", (unsigned __int8)v1[102] >> 7);
    v14 = sub_409E60();
    fprintf(a1, "CamperAlarm = %d\n", (v14 >> 13) & 1);
    v15 = sub_409F40(2);
    fprintf(a1, "ItemRespawn = %d\n", v15);
    fprintf(a1, "MinKickVotes = %d\n", *(_DWORD*)& byte_587000[229980]);
    fprintf(a1, "ResetQuestMinVotes = %d\n", *(_DWORD*)& byte_587000[229988]);
    fprintf(a1, "KickQuestPlayerMinVotes = %d\n", *(_DWORD*)& byte_587000[229992]);
    v16 = sub_48A020(0, &v23);
    fprintf(
            a1,
            "LANFilters = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            v16,
            *v23,
            v23[1],
            v23[2],
            v23[3],
            v23[4],
            v23[5],
            v23[6],
            v23[7],
            v23[8],
            v23[9],
            v23[10]);
    v17 = sub_48A020(1, &v23);
    fprintf(
            a1,
            "INETFilters = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            v17,
            *v23,
            v23[1],
            v23[2],
            v23[3],
            v23[4],
            v23[5],
            v23[6],
            v23[7],
            v23[8],
            v23[9],
            v23[10]);
    if (*(_DWORD*)& byte_587000[81168])
    {
        v18 = &byte_587000[81168];
        v19 = &byte_587000[81168];
        do
        {
            v20 = sub_4D0DE0(*((_DWORD*)v19 + 1));
            fprintf(a1, "%s = %d\n", *(_DWORD*)v18, v20);
            v21 = *((_DWORD*)v19 + 2);
            v19 += 8;
            v18 = v19;
        } while (v21);
    }
    return fprintf(a1, "---\n");
}
// 4335F8: variable 'v12' is possibly undefined

//----- (004337B0) --------------------------------------------------------
int __cdecl sub_4337B0(FILE* a1)
{
    unsigned __int16 v1; // ax
    int v2; // eax
    unsigned __int8* v3; // esi
    unsigned __int16 v4; // ax

    v1 = sub_40A020(*(__int16*)& byte_587000[81224]);
    fprintf(a1, " %d", v1);
    LOWORD(v2) = *(_WORD*)& byte_587000[81228];
    if (*(_DWORD*)& byte_587000[81228])
    {
        v3 = &byte_587000[81228];
        do
        {
            v4 = sub_40A020(v2);
            fprintf(a1, ",%d", v4);
            v2 = *((_DWORD*)v3 + 1);
            v3 += 4;
        } while (v2);
    }
    return fprintf(a1, "\n");
}

//----- (00433820) --------------------------------------------------------
int __cdecl sub_433820(FILE* a1)
{
    unsigned __int8 v1; // al
    int v2; // eax
    unsigned __int8* v3; // esi
    unsigned __int8 v4; // al

    v1 = sub_40A180(*(__int16*)& byte_587000[81224]);
    fprintf(a1, " %d", v1);
    LOWORD(v2) = *(_WORD*)& byte_587000[81228];
    if (*(_DWORD*)& byte_587000[81228])
    {
        v3 = &byte_587000[81228];
        do
        {
            v4 = sub_40A180(v2);
            fprintf(a1, ",%d", v4);
            v2 = *((_DWORD*)v3 + 1);
            v3 += 4;
        } while (v2);
    }
    return fprintf(a1, "\n");
}

//----- (00433890) --------------------------------------------------------
char* sub_433890()
{
    char* v0; // eax
    unsigned __int8* v1; // eax
    char v2; // cl

    v0 = sub_40A4C0();
    strncpy((char*)& byte_5D4594[807108], v0, 0x3Fu);
    v1 = &byte_5D4594[807108];
    if (byte_5D4594[807108])
    {
        do
        {
            if (*v1 == 32)
                * v1 = 95;
            v2 = *++v1;
        } while (v2);
    }
    return (char*)& byte_5D4594[807108];
}

//----- (00433E80) --------------------------------------------------------
void __cdecl sub_433E80(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)
{
    ptr_5D4594_3799572->data[44] = a1;
    ptr_5D4594_3799572->data[45] = a2;
    ptr_5D4594_3799572->data[46] = a3;
}

//----- (00433F10) --------------------------------------------------------
int __cdecl sub_433F10(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)
{
    int result; // eax
    __int64 v4; // rax
    unsigned __int64 v5; // rax
    unsigned __int64 v6; // rax

    result = a1;
    ptr_5D4594_3799572->data[54] = a1;
    ptr_5D4594_3799572->data[55] = a2;
    ptr_5D4594_3799572->data[56] = a3;
    if (*(_DWORD*)& byte_5D4594[3801804])
    {
        v4 = a1 | (a1 << 16);
        HIDWORD(v4) = 0;
        v4 <<= 16;
        LODWORD(v4) = a1 | (unsigned int)v4;
        v4 <<= 16;
        ptr_5D4594_3799572->data[48] = a1 | (unsigned int)v4;
        ptr_5D4594_3799572->data[49] = HIDWORD(v4);
        v5 = (a2 | ((a2 | ((unsigned __int64)a2 << 16)) << 16)) << 16;
        ptr_5D4594_3799572->data[50] = a2 | (unsigned int)v5;
        ptr_5D4594_3799572->data[51] = HIDWORD(v5);
        v6 = (a3 | ((a3 | ((unsigned __int64)a3 << 16)) << 16)) << 16;
        ptr_5D4594_3799572->data[52] = a3 | (unsigned int)v6;
        ptr_5D4594_3799572->data[53] = HIDWORD(v6);
        result = ptr_5D4594_3799572;
    }
    return result;
}

//----- (00434080) --------------------------------------------------------
int __cdecl sub_434080(int a1)
{
    int result; // eax

    result = a1;
    ptr_5D4594_3799572->data[262] = a1;
    return result;
}

//----- (00434350) --------------------------------------------------------
int __cdecl sub_434350(int a1)
{
    int result; // eax

    result = a1;
    ptr_5D4594_3799572->data[58] = a1;
    return result;
}

//----- (00434370) --------------------------------------------------------
int sub_434370()
{
    ptr_5D4594_3799572->data[61] = ptr_5D4594_3799572->data[58];
    return ptr_5D4594_3799572;
}

//----- (00434390) --------------------------------------------------------
int __cdecl sub_434390(int a1)
{
    ptr_5D4594_3799572->data[59] = a1;
    return a1;
}

//----- (004343E0) --------------------------------------------------------
int __cdecl sub_4343E0(int a1)
{
    ptr_5D4594_3799572->data[60] = a1;
    return a1;
}

//----- (00434460) --------------------------------------------------------
int __cdecl sub_434460(int a1)
{
    ptr_5D4594_3799572->data[61] = a1;
    return a1;
}

//----- (004344D0) --------------------------------------------------------
int __cdecl sub_4344D0(_BYTE* a1)
{
    int result; // eax
    __int16 v2; // cx

    result = 0;
    if (a1)
    {
        if (*(_DWORD*)& byte_5D4594[3799624])
        {
            result = *(unsigned __int16*)a1 | (*(unsigned __int16*)a1 << 16);
        }
        else
        {
            LOBYTE(v2) = 0;
            HIBYTE(v2) = *a1;
            result = (unsigned __int16)((unsigned __int8)* a1 | v2) | ((unsigned __int16)((unsigned __int8)* a1 | v2) << 16);
        }
    }
    return result;
}

//----- (00434510) --------------------------------------------------------
char* __cdecl sub_434510(char* a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4)
{
    char* result; // eax
    int v5[10]; // [esp+8h] [ebp-28h]

    v5[6] = a2;
    result = a1;
    v5[7] = a3;
    v5[8] = a4;
    qmemcpy(a1, v5, 0x28u);
    return result;
}

//----- (00434560) --------------------------------------------------------
int __cdecl sub_434560(int a1)
{
    if (ptr_5D4594_3799572->data[13] != a1)
        ptr_5D4594_3799572->data[13] = a1;
    return ptr_5D4594_3799572;
}

//----- (00434580) --------------------------------------------------------
int __cdecl sub_434580(unsigned __int8 a1)
{
    int result; // eax
    __int64 v2; // rax

    result = a1;
    if (ptr_5D4594_3799572->data[259] != a1)
    {
        ptr_5D4594_3799572->data[259] = a1;
        v2 = a1 | (a1 << 16);
        HIDWORD(v2) = 0;
        v2 <<= 16;
        LODWORD(v2) = a1 | (unsigned int)v2;
        v2 <<= 16;
        ptr_5D4594_3799572->data[260] = a1 | (unsigned int)v2;
        result = ptr_5D4594_3799572;
        ptr_5D4594_3799572->data[261] = HIDWORD(v2);
    }
    return result;
}

//----- (004345F0) --------------------------------------------------------
int __cdecl sub_4345F0(int a1)
{
    ptr_5D4594_3799572->data[14] = a1;
    return a1;
}

//----- (00434600) --------------------------------------------------------
int __cdecl sub_434600(int a1)
{
    ptr_5D4594_3799572->data[17] = a1;
    return a1;
}

//----- (00434610) --------------------------------------------------------
int __cdecl sub_434610(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[810636] = a1;
    return result;
}

//----- (00434620) --------------------------------------------------------
int __cdecl sub_434620(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[810632] = a1;
    return result;
}

//----- (00434630) --------------------------------------------------------
unsigned __int8 __cdecl sub_434630(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)
{
    int v3; // ecx
    unsigned __int8* v4; // eax
    int v5; // esi
    unsigned int v6; // ecx
    int v7; // edi
    int v8; // eax
    unsigned __int8 result; // al
    unsigned __int8* v10; // edi
    int v11; // edx
    int v12; // esi
    int v13; // edx
    unsigned __int8* v14; // ecx
    int v15; // [esp+10h] [ebp-10h]
    int v16; // [esp+10h] [ebp-10h]
    unsigned int v17; // [esp+14h] [ebp-Ch]
    unsigned __int8 v18; // [esp+18h] [ebp-8h]

    v3 = 0;
    v4 = &byte_5D4594[3804524];
    if (*(int*)& byte_5D4594[808568] <= 0)
    {
        LABEL_6:
        v5 = a1;
        v6 = a1 | ((a2 | (a3 << 8)) << 8);
        v7 = 0;
        v15 = 255;
        do
        {
            v8 = (v7 + v15) / 2;
            if (v6 >= *(int*)& byte_5D4594[4 * v8 + 809604])
            {
                if (!v6)
                    return byte_5D4594[v8 + 808304];
                v7 = v8 + 1;
            }
            else
            {
                v15 = v8 - 1;
            }
        } while (v7 <= v15);
        v17 = 195075;
        v18 = 0;
        v16 = 0;
        v10 = &byte_5D4594[3803310];
        while (1)
        {
            v11 = *(v10 - 2) - v5;
            v12 = *(v10 - 1) - a2;
            if (v11 * v11 + v12 * v12 + (*v10 - a3) * (*v10 - (unsigned int)a3) < v17)
            {
                v17 = v11 * v11 + v12 * v12 + (*v10 - a3) * (*v10 - a3);
                v18 = v16;
            }
            v10 += 4;
            if (++v16 >= 256)
                break;
            v5 = a1;
        }
        v13 = *(_DWORD*)& byte_5D4594[810628];
        byte_5D4594[4 * *(_DWORD*)& byte_5D4594[810628] + 3804524] = a1;
        v14 = &byte_5D4594[4 * v13 + 3804524];
        v14[1] = a2;
        v14[2] = a3;
        v14[3] = v18;
        if (*(int*)& byte_5D4594[808568] < 32)
            ++* (_DWORD*)& byte_5D4594[808568];
        if (++ * (int*)& byte_5D4594[810628] >= 32)
            * (_DWORD*)& byte_5D4594[810628] = 0;
        result = v18;
    }
    else
    {
        while (a1 != *v4 || a2 != v4[1] || a3 != v4[2])
        {
            v4 += 4;
            if (++v3 >= *(int*)& byte_5D4594[808568])
                goto LABEL_6;
        }
        result = v4[3];
    }
    return result;
}

//----- (004347C0) --------------------------------------------------------
char __cdecl sub_4347C0(char a1)
{
    char result; // al
    int v2; // ecx

    result = a1;
    v2 = 256;
    do
    {
        --v2;
        byte_5D4594[3803310] = a1;
        byte_5D4594[3803309] = a1;
        byte_5D4594[3803308] = a1;
        byte_5D4594[3803311] = 0;
    } while (v2);
    return result;
}

//----- (00434820) --------------------------------------------------------
int __cdecl sub_434820(int a1, char a2, char a3, char a4)
{
    if (a1 < 0 || a1 >= 256)
        return 0;
    byte_5D4594[4 * a1 + 3803308] = a2;
    byte_5D4594[4 * a1 + 3803309] = a3;
    byte_5D4594[4 * a1 + 3803310] = a4;
    byte_5D4594[4 * a1 + 3803311] = 4;
    sub_435040();
    sub_434F00();
    sub_48BDE0();
    return 1;
}

//----- (00434870) --------------------------------------------------------
int __cdecl sub_434870(int a1, _BYTE* a2, _BYTE* a3, _BYTE* a4)
{
    if (a1 < 0 || a1 >= 256)
        return 0;
    if (a2)
        * a2 = byte_5D4594[4 * a1 + 3803308];
    if (a3)
        * a3 = byte_5D4594[4 * a1 + 3803309];
    if (a4)
        * a4 = byte_5D4594[4 * a1 + 3803310];
    return 1;
}

//----- (00434920) --------------------------------------------------------
int sub_434920()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[808564])
        return 0;
    result = 1;
    qmemcpy(&byte_5D4594[808572], &byte_5D4594[3803308], 0x400u);
    *(_DWORD*)& byte_5D4594[808564] = 1;
    return result;
}

//----- (00434950) --------------------------------------------------------
int sub_434950()
{
    if (!*(_DWORD*)& byte_5D4594[808564])
        return 0;
    *(_DWORD*)& byte_5D4594[808564] = 0;
    qmemcpy(&byte_5D4594[3803308], &byte_5D4594[808572], 0x400u);
    sub_435040();
    sub_434F00();
    return 1;
}

//----- (00434990) --------------------------------------------------------
int __cdecl sub_434990(int a1, int a2, int a3)
{
    ptr_5D4594_3799572->data[62] = a1;
    ptr_5D4594_3799572->data[63] = a2;
    ptr_5D4594_3799572->data[64] = a3;
    return a2;
}

//----- (004349C0) --------------------------------------------------------
int __cdecl sub_4349C0(_DWORD* a1)
{
    ptr_5D4594_3799572->data[62] = *a1;
    ptr_5D4594_3799572->data[63] = a1[1];
    ptr_5D4594_3799572->data[64] = a1[2];
    return a1[2];
}

//----- (00434A00) --------------------------------------------------------
int sub_434A00()
{
    return (_DWORD)(&ptr_5D4594_3799572->data[62]);
}

//----- (00434A10) --------------------------------------------------------
_DWORD* __cdecl sub_434A10(_DWORD* a1, _DWORD* a2, _DWORD* a3)
{
    if (a1)
        * a1 = ptr_5D4594_3799572->data[62];
    if (a2)
        * a2 = ptr_5D4594_3799572->data[63];
    if (a3)
        * a3 = ptr_5D4594_3799572->data[64];
    return a3;
}

//----- (00434A60) --------------------------------------------------------
char __cdecl sub_434A60(int a1)
{
    return *(_BYTE*)(*(_DWORD*)& byte_5D4594[3804668]
                                 + (((unsigned __int8)(byte_5D4594[4 * a1 + 3803310] & 0xF8) >> 3) | (4
                                                                                                      * (byte_5D4594[4 * a1 + 3803309] & 0xF8)) | ((byte_5D4594[4 * a1 + 3803308] & 0xF8) << 7)));
}

//----- (00434DA0) --------------------------------------------------------
int sub_434DA0()
{
    __int16 v0; // bx
    int v1; // edi
    void* result; // eax
    unsigned int v3; // esi

    if (*(int*)& byte_5D4594[3799624] < 0)
        return 1;
    if (*(_DWORD*)& byte_5D4594[3799624] > 1)
    {
        if (*(_DWORD*)& byte_5D4594[3799624] == 2)
        {
            v0 = 3;
            v1 = 0xFFFF;
            goto LABEL_6;
        }
        return 1;
    }
    v0 = 7;
    v1 = 0x7FFF;
    LABEL_6:
    result = (int)nox_calloc(v1 + 3, 1u);
    *(_DWORD*)& byte_5D4594[3804668] = result;
    if (result)
    {
        v3 = 0;
        while (1)
        {
            *(_BYTE*)(result + v3) = (unsigned __int16)(28
                                                        * ((((unsigned __int16)v3 & *(_WORD*)& byte_5D4594[3804372]) << byte_5D4594[3804384]) | 7)
            + 150
            * (v0 | ((v3 & *(_DWORD*)& byte_5D4594[3804368]) >> byte_5D4594[3804380]))
            + 76
              * (((v3 & *(_DWORD*)& byte_5D4594[3804364]) >> byte_5D4594[3804376]) | 7)) >> 8;
            if ((int)++v3 > v1)
                break;
            result = *(_DWORD*)& byte_5D4594[3804668];
        }
        result = 1;
    }
    return 1;
}

//----- (00434E80) --------------------------------------------------------
char __cdecl sub_434E80(char a1, char a2, char a3)
{
    return *(_BYTE*)(*(_DWORD*)& byte_5D4594[3804668]
                                 + (((unsigned __int8)(a3 & 0xF8) >> 3) | (4 * (a2 & 0xF8)) | ((a1 & 0xF8) << 7)));
}

//----- (00434EC0) --------------------------------------------------------
char __cdecl sub_434EC0(char a1, char a2, char a3)
{
    return *(_BYTE*)(*(_DWORD*)& byte_5D4594[3804668]
                                 + (((unsigned __int8)(a3 & 0xF8) >> 3) | (8 * (a2 & 0xFC)) | ((a1 & 0xF8) << 8)));
}

//----- (00434F00) --------------------------------------------------------
int sub_434F00()
{
    int result; // eax
    int i; // ebx

    if (*(_DWORD*)& byte_5D4594[3799624])
        return 1;
    if (*(_DWORD*)& byte_5D4594[810640]
        || (result = (int)nox_calloc(0x8000u, 1u), (*(_DWORD*)& byte_5D4594[810640] = result) != 0))
    {
        for (i = 0; i <= 0x7FFF; ++i)
            * (_BYTE*)(*(_DWORD*)& byte_5D4594[810640] + i) = sub_434630(
                    (unsigned __int16)(i & 0x7C00) >> 7,
        (unsigned __int16)(i & 0x3E0) >> 2,
                8 * (i & 0x1F));
        result = 1;
    }
    return result;
}

//----- (00435040) --------------------------------------------------------
void sub_435040()
{
    pixel8888 buf[256]; // [esp+4h] [ebp-400h]
    unsigned __int8* data;

    data = &byte_5D4594[3803308];
    for (int i = 0; i < 256; ++i)
    {
        buf[i].field_0 = i;
        buf[i].field_1 = data[4*i + 0];
        buf[i].field_2 = data[4*i + 1];
        buf[i].field_3 = data[4*i + 2];
    }
    sub_48C580(buf, 256);

    data = &byte_5D4594[809604];
    for (int i = 0; i < 256; ++i)
    {
        data[4*i + 0] = buf[i].field_1;
        data[4*i + 1] = buf[i].field_2;
        data[4*i + 2] = buf[i].field_3;
        data[4*i + 3] = 0;
        byte_5D4594[i + 808304] = buf[i].field_0;
    }
    *(_DWORD*)& byte_5D4594[808568] = 0;
    *(_DWORD*)& byte_5D4594[810628] = 0;
}

//----- (004350E0) --------------------------------------------------------
_BYTE* __cdecl sub_4350E0(_BYTE* a1, _BYTE* a2)
{
    _BYTE* v2; // ecx
    _BYTE* result; // eax
    int v4; // esi

    v2 = a2;
    result = a1;
    v4 = 256;
    do
    {
        *result = *v2;
        result[1] = v2[1];
        result[2] = v2[2];
        result[3] = 4;
        result += 4;
        v2 += 4;
        --v4;
    } while (v4);
    return result;
}

//----- (00435120) --------------------------------------------------------
void __cdecl sub_435120(_BYTE* a1, char* a2)
{
    char* result; // eax
    _BYTE* v3; // ecx
    int v4; // esi
    char v5; // bl
    char* v6; // eax
    char v7; // bl
    char v8; // bl

    result = a2;
    v3 = a1;
    v4 = 256;
    do
    {
        v5 = *result;
        v6 = result + 1;
        *v3 = v5;
        v7 = *v6++;
        v3[1] = v7;
        v8 = *v6;
        v3[3] = 4;
        v3[2] = v8;
        result = v6 + 1;
        v3 += 4;
        --v4;
    } while (v4);
}

//----- (00435150) --------------------------------------------------------
void __cdecl sub_435150(_BYTE* a1, char* a2)
{
    char* v2; // ecx
    _BYTE* result; // eax
    int v4; // esi
    char v5; // dl
    _BYTE* v6; // eax

    v2 = a2;
    result = a1;
    v4 = 256;
    do
    {
        v5 = *v2;
        v2 += 4;
        *result = v5;
        v6 = result + 1;
        *v6++ = *(v2 - 3);
        *v6 = *(v2 - 2);
        result = v6 + 1;
        --v4;
    } while (v4);
}

//----- (00435180) --------------------------------------------------------
void __cdecl sub_435180(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3, int* a4)
{
    unsigned __int8 v4; // al
    int result; // eax

    v4 = sub_434630(a1, a2, a3);
    result = v4 | (v4 << 8);
    *a4 = result | (result << 16);
}

//----- (004351C0) --------------------------------------------------------
void  __cdecl sub_4351C0(char a1, char a2, unsigned __int8 a3, int* a4)
{
    int result; // eax

    result = (a3 >> 3) | (4 * (a2 & 0xF8 | (32 * (a1 & 0xF8))));
    *a4 = result | (result << 16);
}

//----- (00435200) --------------------------------------------------------
void __cdecl sub_435200(char a1, char a2, unsigned __int8 a3, int* a4)
{
    int result; // eax

    result = (a3 >> 3) | (8 * (a2 & 0xFC | (32 * (a1 & 0xF8))));
    *a4 = result | (result << 16);
}

//----- (00435240) --------------------------------------------------------
void __cdecl sub_435240(unsigned __int8 a1, _BYTE* a2, _BYTE* a3, char* a4)
{
    int v4; // eax
    char result; // al

    v4 = 4 * a1;
    *a2 = byte_5D4594[v4 + 3803308];
    *a3 = byte_5D4594[v4 + 3803309];
    result = byte_5D4594[v4 + 3803310];
    *a4 = result;
}

//----- (00435280) --------------------------------------------------------
void __cdecl sub_435280(__int16 a1, _BYTE* a2, _BYTE* a3, _BYTE* a4)
{
    char result; // al

    *a2 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804364] & a1) >> byte_5D4594[3804376];
    *a3 = (unsigned __int16)(*(_WORD*)& byte_5D4594[3804368] & a1) >> byte_5D4594[3804380];
    result = ((unsigned __int8)a1 & byte_5D4594[3804372]) << byte_5D4594[3804384];
    *a4 = result;
}

//----- (00435570) --------------------------------------------------------
__int64 sub_435570()
{
    __int64 result; // rax

    result = sub_416BB0();
    *(_QWORD*)& byte_5D4594[811908] = result;
    return result;
}

//----- (00435590) --------------------------------------------------------
int sub_435590()
{
    return *(_DWORD*)& byte_5D4594[811916];
}

//----- (004355A0) --------------------------------------------------------
void sub_4355A0()
{
    nox_srand(0xA28u);
}

//----- (004355B0) --------------------------------------------------------
int __cdecl sub_4355B0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[811116] = a1;
    return result;
}

//----- (004355C0) --------------------------------------------------------
BOOL sub_4355C0()
{
    int v0; // eax
    float2 v2; // [esp+0h] [ebp-8h]

    v2.field_0 = (double) * (int*)& byte_5D4594[811092];
    v2.field_4 = (double) * (int*)& byte_5D4594[811096];
    v0 = sub_411160(&v2);
    return v0 == 255 || v0 == -1;
}

//----- (00435600) --------------------------------------------------------
int __cdecl sub_435600(int a1, int a2)
{
    int v2; // ecx
    int result; // eax

    v2 = a2 + *(_DWORD*)& byte_5D4594[811116] - *(_DWORD*)& byte_5D4594[811104] / 2;
    *(_DWORD*)& byte_5D4594[811364] = *(_DWORD*)& byte_5D4594[811092];
    *(_DWORD*)& byte_5D4594[811368] = *(_DWORD*)& byte_5D4594[811096];
    result = v2 + *(_DWORD*)& byte_5D4594[811104] / 2;
    *(_DWORD*)& byte_5D4594[811092] = a1;
    *(_DWORD*)& byte_5D4594[811096] = v2 + *(_DWORD*)& byte_5D4594[811104] / 2;
    *(_DWORD*)& byte_5D4594[811084] = a1 - *(_DWORD*)& byte_5D4594[811100] / 2;
    *(_DWORD*)& byte_5D4594[811088] = a2 + *(_DWORD*)& byte_5D4594[811116] - *(_DWORD*)& byte_5D4594[811104] / 2;
    return result;
}

//----- (00435670) --------------------------------------------------------
void __cdecl sub_435670(int2* a1)
{
    *a1 = *(int2*)& byte_5D4594[811092];
}

//----- (00435690) --------------------------------------------------------
_DWORD* __cdecl sub_435690(_DWORD* a1)
{
    _DWORD* result; // eax

    result = a1;
    *a1 = *(_DWORD*)& byte_5D4594[811364];
    a1[1] = *(_DWORD*)& byte_5D4594[811368];
    return result;
}

//----- (004356B0) --------------------------------------------------------
int sub_4356B0()
{
    return *(_DWORD*)& byte_5D4594[811372];
}

//----- (004356C0) --------------------------------------------------------
BOOL __cdecl sub_4356C0(int a1, char a2)
{
    BOOL result; // eax

    result = a1;
    if (a1)
        result = ((1 << a2) & *(_DWORD*)(a1 + 124)) != 0;
    return result;
}

//----- (004356E0) --------------------------------------------------------
void sub_4356E0()
{
    *(_DWORD*)& byte_587000[85720] = 0;
}

//----- (004356F0) --------------------------------------------------------
char* sub_4356F0()
{
    return (char*)& byte_5D4594[811280];
}

//----- (00435700) --------------------------------------------------------
wchar_t* __cdecl sub_435700(wchar_t* a1, int a2)
{
    wchar_t* result; // eax

    result = nox_wcscpy((wchar_t*)& byte_5D4594[811376], a1);
    *(_DWORD*)& byte_5D4594[811060] = a2;
    return result;
}

//----- (00435720) --------------------------------------------------------
char* __cdecl sub_435720(char* a1)
{
    return strncpy((char*)& byte_587000[85680], a1, 0x20u);
}

//----- (00435740) --------------------------------------------------------
DWORD sub_435740()
{
    DWORD result; // eax

    result = nox_get_ticks();
    *(_DWORD*)& byte_5D4594[811924] = result;
    return result;
}

//----- (00435750) --------------------------------------------------------
DWORD sub_435750()
{
    DWORD result; // eax

    result = nox_get_ticks() - *(_DWORD*)& byte_5D4594[811924];
    *(_DWORD*)& byte_5D4594[811928] = result;
    return result;
}

//----- (00435770) --------------------------------------------------------
DWORD sub_435770()
{
    DWORD result; // eax

    result = nox_get_ticks();
    *(_DWORD*)& byte_5D4594[811932] = result;
    return result;
}

//----- (00435780) --------------------------------------------------------
DWORD sub_435780()
{
    DWORD result; // eax

    result = nox_get_ticks() - *(_DWORD*)& byte_5D4594[811932];
    *(_DWORD*)& byte_5D4594[811936] = result;
    return result;
}

//----- (004357A0) --------------------------------------------------------
int sub_4357A0()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2618908] && *(_BYTE*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 1)
        result = sub_48CA70(0);
    else
        result = sub_48CA70(1);
    return result;
}

//----- (004357D0) --------------------------------------------------------
BOOL __cdecl sub_4357D0(int argc, const char** argv)
{
    *(_DWORD*)& byte_5D4594[2616328] = 0;
    *(_DWORD*)& byte_5D4594[2614252] = 0;
    *(_DWORD*)& byte_5D4594[2618908] = 0;
    strcpy((char*)& byte_5D4594[811280], sub_4358A0());
    if (argc > 1)
    {
        int v2 = argc - 1;
        const char** v3 = argv + 1;
        do
        {
            if (!_strcmpi("-noskip", *v3))
                * (_DWORD*)& byte_587000[85724] = 0;
            ++v3;
            --v2;
        } while (v2);
    }
#ifdef __EMSCRIPTEN__
    * (_DWORD*)& byte_587000[85724] = 0;
#endif
    * (_DWORD*)& byte_5D4594[811064] = *(_DWORD*)& byte_587000[80828];
    sub_40EE60();
    if (!sub_40A5C0(1))
        sub_416E30();
    BOOL result = sub_48D7D0();
    if (!result)
    {
        return 0;
    }
    sub_4E4EF0();
    sub_48D740();
    sub_43C720(0);
    *(_DWORD*)& byte_5D4594[2650672] = 0;
    sub_473930();
    sub_48D4B0(0);
    return 1;
}

//----- (004358A0) --------------------------------------------------------
char* sub_4358A0()
{
    int v0; // ecx
    const char** v1; // eax
    const char* v2; // edx
    const char* v4[34]; // [esp+0h] [ebp-88h]

    v0 = *(_DWORD*)& byte_5D4594[814516];
    v4[0] = "Dweezle";
    v4[1] = "Glork";
    v4[2] = "Floogle";
    v4[3] = "Goombah";
    v4[4] = "Kraun";
    v4[5] = "Kloog";
    v4[6] = "Zurg";
    v4[7] = "Darg";
    v4[8] = "Arfingle";
    v4[9] = "Buurl";
    v4[10] = "Gurgin";
    v4[11] = "Grok";
    v4[12] = "Hurlong";
    v4[13] = "Luric";
    v4[14] = "Lupis";
    v4[15] = "Mallik";
    v4[16] = "Thrall";
    v4[17] = "Norwood";
    v4[18] = "Nulik";
    v4[19] = "Orin";
    v4[20] = "Olaf";
    v4[21] = "Orguk";
    v4[22] = "Pervis";
    v4[23] = "Paavik";
    v4[24] = "Qix";
    v4[25] = "Xevin";
    v4[26] = "Xurcon";
    v4[27] = "Markoan";
    v4[28] = "Yuric";
    v4[29] = "Yoovis";
    v4[30] = "Yalek";
    v4[31] = "Zug";
    v4[32] = "Zivik";
    v4[33] = 0;
    if (!*(_DWORD*)& byte_5D4594[814516] && byte_587000 != (unsigned __int8*)-85792)
    {
        v1 = v4;
        do
        {
            v2 = v1[1];
            ++v1;
            ++v0;
        } while (v2);
        *(_DWORD*)& byte_5D4594[814516] = v0;
    }
    return (char*)v4[sub_415FF0(0, v0 - 1, "C:\\NoxPost\\src\\client\\System\\client.c", 559)];
}

//----- (00435A10) --------------------------------------------------------
int __cdecl sub_435A10(signed int* a1)
{
    char* v1; // ebx
    int result; // eax
    unsigned __int16 v3; // ax
    int v4; // [esp+Ch] [ebp-A8h]
    int v5; // [esp+10h] [ebp-A4h]
    int v6; // [esp+14h] [ebp-A0h]
    BYTE Data[153]; // [esp+18h] [ebp-9Ch]

    sub_43BEB0_get_video_mode(&v5, &v4, &v6);
    v1 = sub_431770();
    nox_wcscpy((wchar_t*)v1, (const wchar_t*)& byte_5D4594[2661908]);
    v1[66] = byte_5D4594[2661958];
    *(_WORD*)(v1 + 71) = *(_WORD*)& byte_5D4594[2661888];
    v1[73] = byte_5D4594[2661890];
    *((_WORD*)v1 + 34) = *(_WORD*)& byte_5D4594[2661891];
    v1[70] = byte_5D4594[2661893];
    *((_WORD*)v1 + 37) = *(_WORD*)& byte_5D4594[2661894];
    v1[76] = byte_5D4594[2661896];
    *(_WORD*)(v1 + 77) = *(_WORD*)& byte_5D4594[2661897];
    v1[79] = byte_5D4594[2661899];
    *((_WORD*)v1 + 40) = *(_WORD*)& byte_5D4594[2661900];
    v1[82] = byte_5D4594[2661902];
    v1[83] = byte_5D4594[2661903];
    v1[84] = byte_5D4594[2661904];
    v1[85] = byte_5D4594[2661905];
    v1[86] = byte_5D4594[2661906];
    v1[87] = byte_5D4594[2661907];
    v1[67] = byte_5D4594[2661959];
    sub_48D740();
    *(_DWORD*)& Data[97] = v5;
    *(_DWORD*)& Data[101] = v4;
    sub_420120(&Data[105]);
    if (!sub_43AF70())
        sub_40E0D0((int)& Data[105], (LPCSTR)& byte_587000[86344], 0);
    Data[152] = !sub_40ABD0();
    if (byte_5D4594[2660684] & 4)
        Data[152] |= 0x80u;
    strcpy((char*)& Data[142], (const char*)& byte_5D4594[2660099]);
    strcpy((char*)& Data[128], sub_41FA40());
    *(_DWORD*)& Data[138] = *(_DWORD*)& byte_5D4594[2660032];
    qmemcpy(Data, v1, 0x61u);
    if (sub_40A5C0(1))
    {
        sub_4D3860(Data);
        *(_DWORD*)& byte_5D4594[2616328] = sub_4DD320(31, (int)Data);
        sub_409AE0(66458);
        sub_494E90(31);
    }
    else
    {
        v3 = sub_43B320();
        result = sub_43C7B0((char*)& byte_587000[85680], v3, (int)Data, a1);
        if (!result)
            return result;
        sub_40ED10(31, 0);
        sub_40A340(0);
        sub_40A360(0);
        result = sub_43CFF0();
        if (!result)
        {
            *a1 = -19;
            return result;
        }
        if (sub_409AD0() != 66458)
        {
            *a1 = -20;
            return 0;
        }
        printf("foo 7\n");
    }
    *(_DWORD*)& byte_5D4594[811372] = 2;
    if (!sub_40A5C0(1))
        sub_417C60();
    return 1;
}

//----- (00435CC0) --------------------------------------------------------
int sub_435CC0()
{
    int result; // eax
    int v1; // eax

    sub_445450();
    sub_45DB90();
    sub_41D1A0(0);
    sub_435570();
    *(_DWORD*)& byte_5D4594[1556112] = 0;

    if (!sub_45A1D0(5000))
        return 0;

    result = sub_49A8E0();
    if (!result)
        return 0;

    result = sub_49A5F0();
    if (!result)
        return 0;

    result = sub_44C840((char*)& byte_587000[86368]);
    if (!result)
        return 0;

    result = sub_427070();
    if (!result)
        return 0;

    result = sub_494F00();
    if (!result)
        return 0;

    result = sub_473680();
    if (!result)
        return 0;

    nox_alloc_npcs();
    result = sub_499360();
    if (!result)
        return 0;

    sub_485F80();
    result = sub_4960B0();
    if (!result)
        return 0;

    result = sub_473A40();
    if (!result)
        return 0;

    result = sub_495AB0();
    if (!result)
        return 0;

    result = sub_495980();
    if (!result)
        return 0;

    sub_4958F0();
    sub_43C720(0);
    sub_40A4D0(0x800000);
    if (sub_40A5C0(1))
        sub_4DDF60(31);
    else
        sub_43CB00();
    nox_set_draw_unk1(sub_435F80_draw);
    *(_DWORD*)& byte_5D4594[811372] = 3;
    *(_DWORD*)& byte_587000[85720] = 1;
    *(_DWORD*)& byte_5D4594[811076] = nox_win_width - 1;
    *(_DWORD*)& byte_5D4594[811068] = 0;
    *(_DWORD*)& byte_5D4594[811072] = 0;
    *(_DWORD*)& byte_5D4594[811100] = nox_win_width;
    *(_DWORD*)& byte_5D4594[811080] = nox_win_height - 1;
    *(_DWORD*)& byte_5D4594[811104] = nox_win_height;
    byte_5D4594[811108] = 0;
    *(_DWORD*)& byte_5D4594[811112] = 0;
    *(_DWORD*)& byte_5D4594[811116] = 0;
    v1 = sub_4766D0();
    sub_476700(v1, 0);
    if (sub_40A5C0(2048)) {
        sub_41CC00((char*)& byte_5D4594[2660688]);
    } else if (sub_4D6F50() || sub_4D6F70()) {
        if (sub_4D6F50() || sub_4D6F70())
        {
            sub_460380();
            sub_460E60();
            sub_4721D0();
        }
        if (!sub_40A5C0(1))
            sub_41CC00((char*)& byte_5D4594[2660688]);
    }
    sub_41A480((char*)& byte_5D4594[2660688]);
    sub_443C80((wchar_t*)& byte_587000[86380], 1);
    sub_4951C0();
    sub_465DE0(0);
    return 1;
}

//----- (00435EB0) --------------------------------------------------------
int sub_435EB0()
{
    sub_433290((char*)& byte_587000[86424]);
    if (sub_40A5C0(1))
        sub_4DE530(31, 2);
    else
        sub_43CB50();
    sub_499450();
    sub_467DF0(0);
    sub_495AE0();
    sub_4959D0();
    sub_473B30();
    sub_496120();
    sub_473840();
    sub_44C580_free();
    sub_49A950();
    sub_45A200();
    sub_49AEA0();
    sub_49A2E0();
    sub_4951C0();
    *(_DWORD*)& byte_5D4594[811372] = 2;
    return 1;
}
// 49A2E0: using guessed type int sub_49A2E0(void);

//----- (00435F40) --------------------------------------------------------
int sub_435F40()
{
    int result; // eax

    result = 1 - *(_DWORD*)& byte_5D4594[811896];
    *(_DWORD*)& byte_5D4594[811896] = 1 - *(_DWORD*)& byte_5D4594[811896];
    return result;
}

//----- (00435F60) --------------------------------------------------------
int sub_435F60()
{
    int result; // eax

    result = 1 - *(_DWORD*)& byte_5D4594[811904];
    *(_DWORD*)& byte_5D4594[811904] = 1 - *(_DWORD*)& byte_5D4594[811904];
    return result;
}

//----- (00435F80) --------------------------------------------------------
int sub_435F80_draw()
{
    int2* v0; // esi

    v0 = sub_4309F0();
    if (sub_446180())
        sub_446190();
    if (!sub_437060() && !sub_40A5C0(8))
    {
        sub_43DDD0(0);
        return 0;
    }
    sub_437100();
    if (!sub_478030() && !sub_477600())
        sub_470DE0();
    sub_42D220();
    if (sub_430890() == 1)
        sub_430880(0);
    sub_476FA0();
    if (!sub_43C8F0(
            31,
            *(_DWORD*)& byte_5D4594[811084] + v0->field_0 - *(_DWORD*)& byte_5D4594[811068],
            *(_DWORD*)& byte_5D4594[811088] + v0->field_4 - *(_DWORD*)& byte_5D4594[811072]))
        return 1;
    if (!sub_40A5C0(1))
    {
        sub_40B970();
        sub_40B790();
    }
    if (sub_40A5C0(1))
    {
        sub_49C4B0();
        if (!sub_494E90(31))
            return 1;
    }
    else
    {
        sub_43CCA0();
    }
    sub_49BD70((int)& byte_5D4594[811068]);
    sub_49BBC0();
    sub_421B80();
    if (sub_43C700())
        sub_4357A0();
    sub_436100_draw();
    sub_49BB40();
    sub_49BA70();
    if (sub_409F40(4096))
        sub_46D830();
    if (*(_DWORD*)& byte_5D4594[826068])
        sub_4467F0();
    if (sub_42EBA0() == 1)
    {
        sub_42EB90(0);
        sub_49B7A0();
    }
    sub_49B6E0();
    return *(_DWORD*)& byte_587000[85720];
}
// 435F91: variable 'v1' is possibly undefined

//----- (00436100) --------------------------------------------------------
void sub_436100_draw()
{
    __int64 v0; // rax
    int v1; // ebx
    int v2; // esi
    int v3; // edi
    int result; // eax
    int v6; // ecx
    int v7; // eax
    bool v8; // zf
    int v9; // eax
    int v10; // esi
    unsigned __int16* v11; // eax
    __int16* v12; // eax
    unsigned __int64 v13; // rax
    int v14; // edi
    int* v15; // ebx
    int v16; // esi
    int v17; // edi
    int v18; // ebx
    unsigned __int16* i; // esi
    int v20; // [esp-8h] [ebp-220h]
    int v21; // [esp-4h] [ebp-21Ch]
    int v22; // [esp+Ch] [ebp-20Ch]
    int v23; // [esp+10h] [ebp-208h]
    int v24; // [esp+14h] [ebp-204h]
    wchar_t v25[128]; // [esp+18h] [ebp-200h]

    v0 = sub_416BB0();
    v1 = HIDWORD(v0);
    v2 = v0;
    if ((unsigned int)(v0 - *(_DWORD*)& byte_5D4594[814532]) < *(int*)& byte_587000[85748])
    {
        v3 = 0;
    }
    else
    {
        v3 = 1;
        sub_416D40();
    }
    if (!(!*(_DWORD*)& byte_587000[85724]
          || v3
          || !sub_40A5C0(1)
          || sub_416D70()
          || *(_DWORD*)& byte_5D4594[815132]
          || sub_413A50()
          || *(_DWORD*)& byte_5D4594[2650636] & 0x40000))
    {
        *(_DWORD*)& byte_5D4594[2650636] |= 0x80000000;
        return;
    }
    *(_DWORD*)& byte_5D4594[814532] = v2;
    *(_DWORD*)& byte_5D4594[2650636] &= 0x7FFFFFFFu;
    *(_DWORD*)& byte_5D4594[814536] = v1;
    *(_DWORD*)& byte_5D4594[811916] = *(_DWORD*)& byte_5D4594[2598000];
    if (*(_DWORD*)& byte_587000[85744])
    {
        *(_DWORD*)& byte_5D4594[811104] = *(_DWORD*)& byte_5D4594[811100]
                                                      * nox_win_height
                                                      / nox_win_width;
        v6 = (nox_win_width - *(_DWORD*)& byte_5D4594[811100]) / 2;
        *(_DWORD*)& byte_5D4594[811068] = v6;
        v7 = (nox_win_height - *(_DWORD*)& byte_5D4594[811104]) / 2;
        *(_DWORD*)& byte_5D4594[811072] = v7;
        *(_DWORD*)& byte_5D4594[811076] = v6 + *(_DWORD*)& byte_5D4594[811100] - 1;
        *(_DWORD*)& byte_5D4594[811080] = v7 + *(_DWORD*)& byte_5D4594[811104] - 1;
    }
    else
    {
        v7 = *(_DWORD*)& byte_5D4594[811072];
        v6 = *(_DWORD*)& byte_5D4594[811068];
    }
    sub_430B50(v6, v7, *(int*)& byte_5D4594[811076], *(int*)& byte_5D4594[811080]);
    if (*(_DWORD*)& byte_5D4594[2616328])
        * (_DWORD*)& byte_5D4594[2614252] = sub_45A6F0(*(int*)& byte_5D4594[2616328]);
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
    {
        v8 = !sub_436550();
        v9 = *(_DWORD*)& byte_5D4594[2650636];
        if (v8)
            BYTE1(v9) &= 0xFEu;
        else
            v9 = *(_DWORD*)& byte_5D4594[2650636] | 0x100;
        *(_DWORD*)& byte_5D4594[2650636] = v9;
        if (!*(_DWORD*)& byte_5D4594[814540])
            * (_DWORD*)& byte_5D4594[814540] = sub_42F970("MenuSystemBG");
        if (*(_WORD*)& byte_5D4594[2650636] & 0x100)
        {
            v10 = sub_43F360((char*)& byte_587000[86448]);
            sub_47D2C0(*(int*)& byte_5D4594[814540], 0, 0);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[86496], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1550);
            sub_43F840(v10, v11, &v22, 0, 0);
            sub_434390(*(int*)& byte_5D4594[2523948]);
            v21 = nox_win_height / 2;
            v20 = (nox_win_width - v22) / 2;
            v12 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[86548], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1553);
            sub_43F6E0(v10, v12, v20, v21);
        }
    }
    else if (*(_DWORD*)& byte_5D4594[2614252] && sub_43C700())
    {
        sub_475810_draw((int*)& byte_5D4594[811068]);
        sub_4738E0();
    }
    else
    {
        sub_434350(*(int*)& byte_5D4594[2650656]);
        sub_440900();
    }
    if (*(_DWORD*)& byte_5D4594[811896])
        sub_4365C0();
    if (*(_DWORD*)& byte_5D4594[811904])
        sub_436F50();
    if (sub_40A5C0(8))
    {
        v13 = sub_416BB0() - *(_QWORD*)& byte_5D4594[811908];
        v24 = HIDWORD(v13);
        if (v13 > 0x2710 && !sub_40A5C0(1))
            sub_40A540(8);
    }
    if (sub_40A5C0(8))
    {
        nox_wcscpy(v25, (const wchar_t*)& byte_5D4594[811376]);
        v14 = (nox_win_width - 310) / 2;
        v15 = (int*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[811060] + 811888];
        v16 = (nox_win_height - 200) / 2;
        if (!*(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[811060] + 811888])
        {
            v15 = (int*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[811060] + 811888];
            *v15 = sub_42F970(*(const char**)& byte_587000[4 * *(_DWORD*)& byte_5D4594[811060] + 85712]);
        }
        sub_47D2C0(*v15, v14, v16);
        sub_43F840(0, v25, &v22, &v23, 220);
        v17 = v14 + 45;
        v18 = v16 + (49 - v23) / 2 + 143;
        sub_434460(*(int*)& byte_5D4594[2523948]);
        for (i = nox_wcstok(v25, L"\n\r"); i; i = nox_wcstok(
                0,
                L"\n\r"))
        {
            sub_434390(*(int*)& byte_5D4594[2523948]);
            sub_43F840(0, i, &v22, 0, 0);
            sub_43FAF0(0, i, v17 + (220 - v22) / 2, v18, 220, 0);
            v18 += sub_43F320(0);
        }
    }
    if (*(_DWORD*)& byte_587000[85744])
    {
        sub_430B50(0, 0, nox_win_width - 1, nox_win_height - 1);
        sub_440900();
        *(_DWORD*)& byte_587000[85744] = 0;
    }
}

//----- (00436550) --------------------------------------------------------
BOOL sub_436550()
{
    int v0; // eax

    if (sub_459DA0() || sub_446360() || sub_49CB40() || sub_49C810() || sub_446950() || sub_4706A0() || sub_451410())
    {
        v0 = *(_DWORD*)& byte_5D4594[2598000];
    }
    else
    {
        v0 = *(_DWORD*)& byte_5D4594[2598000];
        if (*(_DWORD*)& byte_5D4594[2598000] != 2)
            return *(_DWORD*)& byte_5D4594[2598000] - *(_DWORD*)& byte_5D4594[811920] == 1;
    }
    *(_DWORD*)& byte_5D4594[811920] = v0;
    return 1;
}

//----- (004365C0) --------------------------------------------------------
int sub_4365C0()
{
    int v0; // edi
    int v1; // esi
    DWORD v2; // ecx
    unsigned int v3; // eax
    __int16* v4; // eax
    int v5; // esi
    wchar_t* v6; // eax
    int v7; // ebx
    wchar_t* v8; // eax
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    int v12; // edi
    char* i; // esi
    wchar_t* v14; // eax
    int v16; // [esp-10h] [ebp-28h]
    int v17; // [esp-Ch] [ebp-24h]
    int v18; // [esp-8h] [ebp-20h]
    int v19; // [esp-8h] [ebp-20h]
    int v20; // [esp-8h] [ebp-20h]
    wchar_t* v21; // [esp-8h] [ebp-20h]
    int v22; // [esp-8h] [ebp-20h]
    int v23; // [esp-4h] [ebp-1Ch]
    int v24; // [esp-4h] [ebp-1Ch]
    int v25; // [esp-4h] [ebp-1Ch]
    int v26; // [esp-4h] [ebp-1Ch]
    int v27; // [esp-4h] [ebp-1Ch]
    int v28; // [esp-4h] [ebp-1Ch]
    int v29; // [esp+Ch] [ebp-Ch]
    int v30; // [esp+10h] [ebp-8h]
    int v31; // [esp+14h] [ebp-4h]

    v0 = nox_win_width - 177;
    v1 = nox_win_height - 80;
    if (*(int*)& byte_5D4594[814520] >= *(int*)& byte_587000[85740])
    {
        *(_DWORD*)& byte_587000[85740] = *(_DWORD*)& byte_5D4594[814520] + 10;
        v2 = nox_get_ticks();
        v3 = 0x2710 / (v2 - *(_DWORD*)& byte_5D4594[814528]);
        *(_DWORD*)& byte_5D4594[814524] = v2;
        *(_DWORD*)& byte_5D4594[814528] = v2;
        *(_DWORD*)& byte_587000[85732] = v3;
    }
    sub_436AA0(*(int*)& byte_587000[85732]);
    sub_436C40();
    sub_436DF0(*(int*)& byte_5D4594[2614264]);
    if (*(_DWORD*)& byte_5D4594[805836])
    {
        sub_434390(*(int*)& byte_5D4594[2618904]);
        v23 = v1;
        v18 = v0;
        v4 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[86616], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1150);
    }
    else
    {
        sub_434390(*(int*)& byte_5D4594[2650644]);
        v23 = v1;
        v18 = v0;
        v4 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[86660], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1155);
    }
    sub_43F6E0(0, v4, v18, v23);
    v5 = v1 + 10;
    v24 = *(_DWORD*)& byte_5D4594[2598000];
    v6 = loadString_sub_40F1D0((char*)& byte_587000[86708], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1159);
    nox_swprintf((wchar_t*)& byte_5D4594[810900], v6, v24);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(0, (__int16*)& byte_5D4594[810900], v0, v5);
    v5 += 10;
    v7 = sub_43C760();
    v8 = loadString_sub_40F1D0((char*)& byte_587000[86756], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1165);
    nox_swprintf((wchar_t*)& byte_5D4594[810900], v8, v7);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(0, (__int16*)& byte_5D4594[810900], v0, v5);
    sub_436970(v7);
    v5 += 10;
    v25 = sub_45A020();
    v9 = loadString_sub_40F1D0((char*)& byte_587000[86808], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1172);
    nox_swprintf((wchar_t*)& byte_5D4594[810900], v9, v25);
    sub_434390(*(int*)& byte_5D4594[2523948]);
    sub_43F6E0(0, (__int16*)& byte_5D4594[810900], v0, v5);
    v5 += 10;
    v26 = *(_DWORD*)& byte_5D4594[2649824];
    v19 = *(_DWORD*)& byte_5D4594[2618900];
    v10 = loadString_sub_40F1D0((char*)& byte_587000[86860], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1177);
    nox_swprintf((wchar_t*)& byte_5D4594[810900], v10, v19, v26);
    sub_43F6E0(0, (__int16*)& byte_5D4594[810900], v0, v5);
    v5 += 10;
    v27 = *(_DWORD*)& byte_587000[85732];
    v20 = *(_DWORD*)& byte_5D4594[2614264];
    v11 = loadString_sub_40F1D0((char*)& byte_587000[86912], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1181);
    nox_swprintf((wchar_t*)& byte_5D4594[810900], v11, v20, v27);
    sub_434460(*(int*)& byte_5D4594[2650656]);
    sub_49CE30(v0 + 80, v5, 16, 8);
    sub_43F6E0(0, (__int16*)& byte_5D4594[810900], v0, v5);
    v12 = 200;
    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        if (i[3680] & 8)
        {
            v21 = loadString_sub_40F1D0((char*)& byte_587000[86960], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1201);
            nox_swprintf((wchar_t*)& byte_5D4594[810900], v21, i + 4704);
        }
        else
        {
            nox_swprintf((wchar_t*)& byte_5D4594[810900], L"%s", i + 4704);
        }
        sub_43F6E0(0, (__int16*)& byte_5D4594[810900], 10, v12);
        sub_4E5630(i[2064], &v31, &v30, &v29);
        v28 = v29;
        v22 = v30;
        v17 = v31;
        if (i[2064] == 31)
        {
            v16 = sub_553ED0(0);
            v14 = loadString_sub_40F1D0((char*)& byte_587000[87016], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1211);
        }
        else
        {
            v16 = sub_553ED0((unsigned __int8)i[2064] + 1);
            v14 = loadString_sub_40F1D0((char*)& byte_587000[87072], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1216);
        }
        nox_swprintf((wchar_t*)& byte_5D4594[810900], v14, v16, v17, v22, v28);
        sub_43F6E0(0, (__int16*)& byte_5D4594[810900], 70, v12);
        v12 += 10;
    }
    return ++ * (_DWORD*)& byte_5D4594[814520];
}

//----- (00436970) --------------------------------------------------------
int __cdecl sub_436970(int a1)
{
    int v1; // esi
    __int16* v2; // eax
    int v3; // ecx
    int v4; // ebx
    int v5; // edi
    int v6; // ebp
    int result; // eax
    int v8; // [esp-4h] [ebp-18h]
    int v9; // [esp+10h] [ebp-4h]
    int v10; // [esp+18h] [ebp+4h]

    v9 = nox_win_height - 1;
    v1 = nox_win_height - 31;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v8 = v1 - sub_43F320(0);
    v2 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[87128], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 323);
    sub_43F6E0(0, v2, 0, v8);
    sub_434460(*(int*)& byte_5D4594[2650660]);
    sub_49CC70(0, v1, nox_win_width, 31);
    v3 = *(_DWORD*)& byte_5D4594[812452];
    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[812452] + 811940] = a1 / 4;
    if (a1 / 4 > 30)
        * (_DWORD*)& byte_5D4594[4 * v3 + 811940] = 30;
    v4 = (v3 + 1) % 128;
    *(_DWORD*)& byte_5D4594[812452] = (v3 + 1) % 128;
    v5 = 0;
    v6 = nox_win_width / 128;
    sub_434460(*(int*)& byte_5D4594[2589772]);
    v10 = 127;
    do
    {
        sub_49F500(v5, v9 - *(_DWORD*)& byte_5D4594[4 * v4 + 811940]);
        v5 += v6;
        sub_49F500(v5, v9 - *(_DWORD*)& byte_5D4594[4 * ((v4 + 1) % 128) + 811940]);
        sub_49E4B0();
        v4 = (v4 + 1) % 128;
        result = --v10;
    } while (v10);
    return result;
}

//----- (00436AA0) --------------------------------------------------------
int __cdecl sub_436AA0(int a1)
{
    int v1; // esi
    int v2; // ebx
    __int16* v3; // eax
    int v4; // edi
    int v5; // ebp
    int v6; // ecx
    int v7; // esi
    int v8; // ebp
    int v9; // edi
    int v10; // eax
    int v11; // eax
    bool v12; // cc
    int result; // eax
    int v14; // [esp-4h] [ebp-18h]
    int v15; // [esp+10h] [ebp-4h]
    int v16; // [esp+18h] [ebp+4h]

    v1 = sub_43F320(0);
    v2 = v1 + 30;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v14 = v1 - sub_43F320(0);
    v3 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[87180], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 368);
    sub_43F6E0(0, v3, 0, v14);
    sub_434460(*(int*)& byte_5D4594[2650660]);
    v4 = v1;
    v5 = 4;
    do
    {
        sub_49F500(0, v4);
        sub_49F500(nox_win_width, v4);
        sub_49E4B0();
        v4 += 10;
        --v5;
    } while (v5);
    sub_49F500(0, v1);
    sub_49F500(0, v1 + 30);
    sub_49E4B0();
    sub_49F500(nox_win_width - 1, v1);
    sub_49F500(nox_win_width - 1, v1 + 30);
    sub_49E4B0();
    v6 = *(_DWORD*)& byte_5D4594[812968] + 1;
    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[812968] + 812456] = 10 * a1 / 10;
    *(_DWORD*)& byte_5D4594[812968] = v6 % 128;
    v7 = v6 % 128;
    v16 = 127;
    v8 = nox_win_width / 128;
    v9 = 0;
    do
    {
        v15 = (v7 + 1) % 128;
        v10 = *(_DWORD*)& byte_5D4594[4 * v7 + 812456];
        if (v10 >= 10)
        {
            v12 = v10 < 20;
            v11 = *(_DWORD*)& byte_5D4594[2589772];
            if (!v12)
                v11 = *(_DWORD*)& byte_5D4594[2618904];
        }
        else
        {
            v11 = *(_DWORD*)& byte_5D4594[2650644];
        }
        sub_434460(v11);
        sub_49F500(v9, v2 - *(_DWORD*)& byte_5D4594[4 * v7 + 812456]);
        v7 = (v7 + 1) % 128;
        v9 += v8;
        sub_49F500(v9, v2 - *(_DWORD*)& byte_5D4594[4 * v15 + 812456]);
        sub_49E4B0();
        result = --v16;
    } while (v16);
    return result;
}

//----- (00436C40) --------------------------------------------------------
int sub_436C40()
{
    __int16* v0; // eax
    int v1; // ecx
    signed int v2; // edx
    signed int v3; // edx
    int v4; // ebx
    int v5; // ebp
    int v6; // edi
    int v7; // esi
    int v8; // ebp
    bool v9; // zf
    int result; // eax
    int v11; // [esp-4h] [ebp-Ch]
    int v12; // [esp+0h] [ebp-8h]
    int v13; // [esp+4h] [ebp-4h]

    sub_434390(*(int*)& byte_5D4594[2523948]);
    v11 = 60 - sub_43F320(0);
    v0 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[87224], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 428);
    sub_43F6E0(0, v0, 0, v11);
    sub_434460(*(int*)& byte_5D4594[2650660]);
    sub_49CC70(0, 60, nox_win_width, 31);
    v1 = *(_DWORD*)& byte_5D4594[813996];
    v2 = 30 * *(_DWORD*)& byte_5D4594[811928] / 0x64u;
    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[813996] + 812972] = v2;
    if (v2 > 30)
        * (_DWORD*)& byte_5D4594[4 * v1 + 812972] = 30;
    v3 = 30 * *(_DWORD*)& byte_5D4594[811936] / 0x64u;
    *(_DWORD*)& byte_5D4594[4 * v1 + 813484] = v3;
    if (v3 > 30)
        * (_DWORD*)& byte_5D4594[4 * v1 + 813484] = 30;
    v4 = (v1 + 1) % 128;
    *(_DWORD*)& byte_5D4594[813996] = (v1 + 1) % 128;
    v12 = 127;
    v5 = nox_win_width / 128;
    v13 = nox_win_width / 128;
    v6 = 0;
    while (1)
    {
        v7 = (v4 + 1) % 128;
        sub_434460(*(int*)& byte_5D4594[2650684]);
        sub_49F500(v6, 90 - *(_DWORD*)& byte_5D4594[4 * v4 + 812972]);
        v8 = v6 + v5;
        sub_49F500(v8, 90 - *(_DWORD*)& byte_5D4594[4 * v7 + 812972]);
        sub_49E4B0();
        sub_434460(*(int*)& byte_5D4594[2650644]);
        sub_49F500(v6, 90 - *(_DWORD*)& byte_5D4594[4 * v4 + 813484]);
        sub_49F500(v8, 90 - *(_DWORD*)& byte_5D4594[4 * v7 + 813484]);
        sub_49E4B0();
        v6 = v8;
        result = v12 - 1;
        v9 = v12 == 1;
        v4 = (v4 + 1) % 128;
        --v12;
        if (v9)
            break;
        v5 = v13;
    }
    return result;
}

//----- (00436DF0) --------------------------------------------------------
int __cdecl sub_436DF0(int a1)
{
    int v1; // esi
    __int16* v2; // eax
    int v3; // eax
    int v4; // edx
    int v5; // edi
    int v6; // ebp
    int v7; // ebx
    int v8; // eax
    int v9; // eax
    bool v10; // cc
    bool v11; // zf
    int result; // eax
    int v13; // [esp-4h] [ebp-18h]
    int v14; // [esp+10h] [ebp-4h]
    int v15; // [esp+18h] [ebp+4h]

    v1 = nox_win_height - 80;
    v14 = nox_win_height - 80 + 30;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v13 = v1 - sub_43F320(0);
    v2 = (__int16*)loadString_sub_40F1D0((char*)& byte_587000[87276], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 478);
    sub_43F6E0(0, v2, 0, v13);
    sub_434460(*(int*)& byte_5D4594[2650660]);
    sub_49CC70(0, v1, nox_win_width, 31);
    v3 = *(_DWORD*)& byte_5D4594[814512];
    v4 = 30 * a1 / 500;
    *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[814512] + 814000] = v4;
    if (v4 > 30)
        * (_DWORD*)& byte_5D4594[4 * v3 + 814000] = 30;
    v5 = (v3 + 1) % 128;
    *(_DWORD*)& byte_5D4594[814512] = (v3 + 1) % 128;
    v15 = 127;
    v6 = nox_win_width / 128;
    v7 = 0;
    do
    {
        v8 = *(_DWORD*)& byte_5D4594[4 * v5 + 814000];
        if (v8 >= 100)
        {
            v10 = v8 < 350;
            v9 = *(_DWORD*)& byte_5D4594[2589772];
            if (!v10)
                v9 = *(_DWORD*)& byte_5D4594[2650644];
        }
        else
        {
            v9 = *(_DWORD*)& byte_5D4594[2618904];
        }
        sub_434460(v9);
        sub_49F500(v7, v14 - *(_DWORD*)& byte_5D4594[4 * v5 + 814000]);
        sub_49F500(v7 + v6, v14 - *(_DWORD*)& byte_5D4594[4 * ((v5 + 1) % 128) + 814000]);
        sub_49E4B0();
        v7 += v6;
        result = v15 - 1;
        v11 = v15 == 1;
        v5 = (v5 + 1) % 128;
        --v15;
    } while (!v11);
    return result;
}

//----- (00436F50) --------------------------------------------------------
int sub_436F50()
{
    int v0; // ebx
    char* v1; // eax
    int v2; // edi
    int v3; // esi
    char* v4; // eax
    int result; // eax
    int v6; // esi
    wchar_t* v7; // eax
    int v8; // [esp-8h] [ebp-14h]
    wchar_t* v9; // [esp-4h] [ebp-10h]

    v0 = sub_43F320(0);
    v1 = sub_437250();
    v2 = *(_DWORD*)v1 + 10;
    v3 = *((_DWORD*)v1 + 1) + 90;
    sub_434390(*(int*)& byte_5D4594[2523948]);
    v4 = sub_409B30();
    nox_swprintf((wchar_t*)& byte_5D4594[811120], L"%S", v4);
    sub_43F6E0(0, (__int16*)& byte_5D4594[811120], v2, v3);
    result = *(_DWORD*)& byte_5D4594[2614252];
    v6 = v0 + v3;
    if (*(_DWORD*)& byte_5D4594[2614252])
    {
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            nox_swprintf(
                    (wchar_t*)& byte_5D4594[811120],
                    L"X:%d\tY:%d",
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 12),
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 16));
            sub_43F6E0(0, (__int16*)& byte_5D4594[811120], v2, v6);
            v9 = loadString_sub_40F1D0(
                    *(char**)& byte_587000[4 * *(unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618908] + 2251) + 29456],
            0,
                    "C:\\NoxPost\\src\\client\\System\\client.c",
                    1357);
            v8 = *(char*)(*(_DWORD*)& byte_5D4594[2618908] + 3684);
            v7 = loadString_sub_40F1D0((char*)& byte_587000[87392], 0, "C:\\NoxPost\\src\\client\\System\\client.c", 1355);
            nox_swprintf((wchar_t*)& byte_5D4594[811120], v7, v8, v9);
            result = sub_43F6E0(0, (__int16*)& byte_5D4594[811120], v2, v0 + v6);
        }
    }
    return result;
}

//----- (00437060) --------------------------------------------------------
int sub_437060()
{
    char* v0; // eax
    char i; // cl
    bool v2; // zf

    if (!sub_46A4A0())
    {
        v0 = sub_430940();
        *(_DWORD*)& byte_5D4594[2618912] = v0;
        for (i = *v0; *v0; i = *v0)
        {
            if (v0[2] != 1 && v0[1] != 2)
            {
                switch (i)
                {
                    case 0x3B:
                    case 0x3C:
                    case 0x3D:
                    case 0x3E:
                    case 0x3F:
                    case 0x40:
                    case 0x41:
                    case 0x42:
                    case 0x43:
                    case 0x44:
                    case 0x57:
                    case 0x58:
                        v2 = sub_477600() == 0;
                        v0 = *(char**)& byte_5D4594[2618912];
                        if (v2)
                        {
                            sub_4443B0(**(_BYTE * *)& byte_5D4594[2618912]);
                            v0 = *(char**)& byte_5D4594[2618912];
                        }
                        break;
                    default:
                        break;
                }
            }
            v0 += 8;
            *(_DWORD*)& byte_5D4594[2618912] = v0;
        }
    }
    return 1;
}

//----- (00437100) --------------------------------------------------------
int sub_437100()
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[80828];
    if (*(_DWORD*)& byte_5D4594[811064] != *(_DWORD*)& byte_587000[80828]
        && !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
    {
        *(_DWORD*)& byte_5D4594[811064] = *(_DWORD*)& byte_587000[80828];
        sub_4721A0(*(int*)& byte_587000[80828]);
        sub_460EA0(*(int*)& byte_587000[80828]);
        nox_window_set_visible_unk5(*(int*)& byte_587000[80828]);
        sub_45D500(*(int*)& byte_587000[80828]);
        sub_455A00(*(int*)& byte_587000[80828]);
        sub_455F10(*(int*)& byte_587000[80828]);
        sub_4706C0(*(int*)& byte_587000[80828]);
        result = *(_DWORD*)& byte_587000[80828];
        if (!*(_DWORD*)& byte_587000[80828])
            result = sub_478000();
    }
    return result;
}

//----- (00437180) --------------------------------------------------------
int4* sub_437180()
{
    return sub_48D990(&byte_5D4594[811068]);
}

//----- (00437190) --------------------------------------------------------
int sub_437190()
{
    int result; // eax

    if (sub_43AF70() == 1)
        sub_40D380();
    sub_473960();
    sub_416E30();
    sub_455EE0();
    sub_456240();
    sub_48D800();
    sub_49A8C0();
    sub_470550();
    sub_46C5D0();
    sub_44DF70();
    if (!sub_40A5C0(1))
        sub_43CC80();
    *(_DWORD*)& byte_5D4594[811372] = 0;
    if (!sub_40A5C0(1))
        sub_4E4DE0();
    sub_40A380();
    sub_435720((char*)& byte_5D4594[814544]);
    sub_446580(1);
    sub_48D760();
    if (!sub_40A5C0(1))
        sub_40EE60();
    result = sub_417CF0();
    *(_DWORD*)& byte_5D4594[2616328] = 0;
    *(_DWORD*)& byte_5D4594[2614252] = 0;
    *(_DWORD*)& byte_5D4594[2618908] = 0;
    return result;
}

//----- (00437250) --------------------------------------------------------
char* sub_437250()
{
    return (char*)& byte_5D4594[811068];
}

//----- (00437260) --------------------------------------------------------
int4* sub_437260()
{
    return sub_49F6F0(
            *(int*)& byte_5D4594[811068],
            *(int*)& byte_5D4594[811072],
            *(int*)& byte_5D4594[811100],
            *(int*)& byte_5D4594[811104]);
}

//----- (00437290) --------------------------------------------------------
int4* sub_437290()
{
    return sub_49F6F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (004372B0) --------------------------------------------------------
BOOL sub_4372B0()
{
    int v0; // eax
    BOOL result; // eax

    result = 1;
    if (*(_DWORD*)& byte_5D4594[2614252])
    {
        v0 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 276);
        if (v0 != 1 && v0 != 2 && v0 != 51)
            result = 0;
    }
    return result;
}

//----- (004372E0) --------------------------------------------------------
BOOL sub_4372E0()
{
    BOOL result; // eax

    if (*(_DWORD*)& byte_5D4594[2618908] && *(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 2092) == 1)
        result = (*(_DWORD*)(*(_DWORD*)& byte_5D4594[2618908] + 3680) & 3) != 0;
    else
        result = 0;
    return result;
}

//----- (00437310) --------------------------------------------------------
void sub_437310()
{
    nox_srand(0xA29u);
}

//----- (00437320) --------------------------------------------------------
int __cdecl sub_437320(int a1)
{
    int v1; // eax
    unsigned __int8* v2; // ecx
    int v3; // ecx
    int v4; // eax
    int result; // eax

    v1 = 0;
    v2 = &byte_587000[87484];
    do
    {
        if (*(_DWORD*)(a1 + 96) <= *(int*)v2)
            break;
        v2 += 4;
        ++v1;
    } while ((int)v2 < (int)& byte_587000[87496]);
    if (v1 > 2)
        v1 = 2;
    v3 = *(_DWORD*)(a1 + 28) + 36;
    v4 = 16 * v1;
    if (*(int*)& byte_587000[87412] == -1)
    {
        *(_DWORD*)(*(_DWORD*)(a1 + 28) + 76) = *(_DWORD*)& byte_5D4594[v4 + 814568];
        *(_DWORD*)(v3 + 24) = *(_DWORD*)& byte_5D4594[v4 + 814564];
        result = *(_DWORD*)& byte_5D4594[v4 + 814564];
    }
    else
    {
        *(_DWORD*)(*(_DWORD*)(a1 + 28) + 76) = *(_DWORD*)& byte_5D4594[v4 + 814560];
        *(_DWORD*)(v3 + 24) = *(_DWORD*)& byte_5D4594[v4 + 814556];
        result = *(_DWORD*)& byte_5D4594[v4 + 814556];
    }
    *(_DWORD*)(v3 + 48) = result;
    return result;
}

//----- (004373A0) --------------------------------------------------------
void sub_4373A0()
{
    wchar_t* v0; // eax
    wchar_t* v1; // eax
    wchar_t* v2; // eax

    if (!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[815000]))
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[815000], 1);
        *(_DWORD*)& byte_5D4594[815056] = 0;
        sub_46C6E0(*(int*)& byte_5D4594[815000]);
        sub_46B500(*(int*)& byte_5D4594[814980]);
    }
    if (*(int*)& byte_587000[87408] == 1 || *(int*)& byte_587000[87412] == -1)
    {
        if (*(_DWORD*)& byte_5D4594[815048] == 1)
        {
            *(_DWORD*)& byte_5D4594[815048] = 0;
            sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
            v2 = loadString_sub_40F1D0((char*)& byte_587000[87876], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 619);
            nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v2, 0);
            sub_452D80(231, 100);
        }
        else
        {
            sub_43C1E0();
            sub_49FF20();
            if (*(_DWORD*)& byte_587000[87404] == 1)
            {
                *(_DWORD*)& byte_5D4594[815084] = 1;
                sub_41E300(7);
                sub_4207F0(4);
                sub_40D380();
            }
            sub_452D80(231, 100);
        }
    }
    else if (*(_DWORD*)& byte_5D4594[815048] == 1)
    {
        *(_DWORD*)& byte_5D4594[815048] = 0;
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
        sub_46ADE0(*(int*)& byte_5D4594[814984]);
        sub_4375C0(1);
        v0 = loadString_sub_40F1D0((char*)& byte_587000[87928], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 643);
        nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v0, 0);
        sub_452D80(231, 100);
    }
    else
    {
        sub_49FF20();
        if (*(_DWORD*)& byte_587000[87404])
        {
            *(_DWORD*)& byte_587000[87412] = -1;
            sub_46ADE0(*(int*)& byte_5D4594[814984]);
            nox_window_set_hidden(*(int*)& byte_5D4594[814984], 1);
            nox_window_set_hidden(*(int*)& byte_5D4594[814988], 0);
            v1 = loadString_sub_40F1D0((char*)& byte_587000[87980], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 660);
            nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v1, 0);
            sub_4378B0();
            sub_452D80(231, 100);
        }
        else
        {
            sub_43C1E0();
        }
    }
}

//----- (004375C0) --------------------------------------------------------
void __cdecl sub_4375C0(int a1)
{
    if (*(_DWORD*)& byte_5D4594[815088])
        sub_46AD20(*(_DWORD * *)& byte_5D4594[814980], 10070, *(_DWORD*)& byte_5D4594[815088] + 10069, a1);
}

//----- (004375F0) --------------------------------------------------------
int __cdecl sub_4375F0(const char* a1, __int16 a2, char* a3, int a4)
{
    DWORD v4; // edx
    int v5; // edi
    __int16 v6; // cx
    __int16 v7; // ax
    int v8; // ecx
    __int16 v9; // ax
    int v10; // ecx
    int v11; // eax
    char v13[172]; // [esp+14h] [ebp-CCh]
    char v14[32]; // [esp+C0h] [ebp-20h]

    if (*(_DWORD*)& byte_5D4594[815088] < 0x9C4u && !*(_DWORD*)& byte_5D4594[815044] && !*(_DWORD*)& byte_5D4594[815060])
    {
        if (memcmp(a1, &byte_5D4594[815108], 1u))
        {
            if (*(_DWORD*)(a4 + 44) == *(_DWORD*)& byte_5D4594[814964])
            {
                if (sub_4A0410(a1, a2))
                {
                    memset(v13, 0, 0xA8u);
                    v13[168] = 0;
                    v4 = nox_get_ticks();
                    v5 = *(_DWORD*)(a4 + 44);
                    v6 = *(_WORD*)(a4 + 36);
                    v13[101] = *(_BYTE*)(a4 + 5) | (16 * *(_BYTE*)(a4 + 6));
                    v7 = *(_WORD*)(a4 + 38);
                    *(_WORD*)& v13[105] = v6;
                    LOBYTE(v6) = *(_BYTE*)(a4 + 21);
                    *(_WORD*)& v13[107] = v7;
                    LOBYTE(v7) = *(_BYTE*)(a4 + 4);
                    v13[100] = *(_BYTE*)(a4 + 20) | v6;
                    LOBYTE(v6) = *(_BYTE*)(a4 + 3);
                    v13[104] = v7;
                    LOBYTE(v7) = *(_BYTE*)(a4 + 19);
                    v13[103] = v6;
                    v8 = *(_DWORD*)(a4 + 32);
                    v13[102] = v7;
                    v9 = *(_WORD*)(a4 + 28);
                    *(_DWORD*)& v13[159] = v8;
                    v10 = *(_DWORD*)(a4 + 24);
                    *(_WORD*)& v13[163] = v9;
                    v11 = *(_DWORD*)(a4 + 40);
                    *(_DWORD*)& v13[48] = v10;
                    *(_DWORD*)& v13[44] = v11;
                    qmemcpy(&v13[135], (const void*)(a4 + 48), 0x14u);
                    *(_DWORD*)& v13[155] = *(_DWORD*)(a4 + 7);
                    strcpy(&v13[111], (const char*)(a4 + 10));
                    LOWORD(v10) = *(_WORD*)(a4 + 68);
                    *(_DWORD*)& v13[96] = v4 - v5;
                    *(_WORD*)& v13[165] = v10;
                    if (*(int*)& byte_587000[87412] == -1
                        || sub_437860(*(__int16*)& v13[44], *(__int16*)& v13[46]) == *(_DWORD*)& byte_587000[87412])
                    {
                        if (sub_4899C0((int)v13))
                        {
                            *(_DWORD*)& v13[36] = *(_DWORD*)& byte_5D4594[815088];
                            *(_DWORD*)& v13[28] = 0;
                            strcpy(&v13[12], a1);
                            *(_WORD*)& v13[109] = a2;
                            strncpy(&v13[120], a3, 0xFu);
                            *(_WORD*)& v13[163] = *(_WORD*)(a4 + 28);
                            sub_4A0030(v13);
                            v14[0] = 0;
                            if (a3)
                                strcpy(v14, a3);
                            else
                                sub_43BC80((int)a1, a2, v14);
                            ++* (_DWORD*)& byte_5D4594[815088];
                        }
                    }
                }
            }
        }
    }
    return 0;
}

//----- (00437860) --------------------------------------------------------
int __cdecl sub_437860(int a1, int a2)
{
    int result; // eax
    unsigned __int8* v3; // ecx

    result = 0;
    v3 = &byte_587000[87532];
    while (a1 <= *((__int16*)v3 - 2) || a1 >= *(__int16*)v3 || a2 <= *((__int16*)v3 - 1) || a2 >= *((__int16*)v3 + 1))
    {
        v3 += 8;
        ++result;
        if ((int)v3 >= (int)& byte_587000[87564])
            return 0;
    }
    return result;
}

//----- (004378B0) --------------------------------------------------------
int sub_4378B0()
{
    int result; // eax
    u_short v1; // ax
    wchar_t* v2; // eax
    int v3; // eax
    int v4; // [esp-4h] [ebp-4h]

    result = sub_44A4A0();
    if (result)
    {
        *(_DWORD*)& byte_5D4594[815104] = 1;
    }
    else
    {
        *(_QWORD*)& byte_5D4594[815076] = sub_416BB0();
        *(_DWORD*)& byte_5D4594[815060] = 0;
        sub_4379C0();
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16399, 0, 0);
        sub_49FFA0(1);
        *(_DWORD*)& byte_5D4594[815088] = 0;
        if (*(_DWORD*)& byte_587000[87404])
        {
            sub_41F370(1);
            v3 = sub_41E2F0();
            sub_41DA70(v3, 12);
        }
        else
        {
            sub_555000(sub_4375F0);
            v4 = nox_get_ticks();
            *(_DWORD*)& byte_5D4594[814964] = v4;
            v1 = sub_40A430();
            sub_554AA0(v1, 0, 0, v4);
            v2 = loadString_sub_40F1D0((char*)& byte_587000[88032], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1097);
            sub_449A10(*(int*)& byte_5D4594[814980], 0, (int)v2, 0, 0, 0);
        }
        *(_DWORD*)& byte_5D4594[815104] = 0;
        result = (unsigned __int64)(*(_QWORD*)& byte_5D4594[815076] + (__int64)120000) >> 32;
        *(_QWORD*)& byte_5D4594[815068] = *(_QWORD*)& byte_5D4594[815076] + (__int64)120000;
    }
    return result;
}

//----- (004379C0) --------------------------------------------------------
void sub_4379C0()
{
    if (*(_DWORD*)& byte_587000[87408] == 1)
        nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16399, 0, 0);
}

//----- (004379F0) --------------------------------------------------------
int sub_4379F0()
{
    int result; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // esi
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    wchar_t* v5; // eax
    _DWORD* v6; // eax
    wchar_t* v7; // eax
    _DWORD* v8; // esi
    _DWORD* v9; // ebx
    _DWORD* v10; // ebp
    _DWORD* v11; // edi
    _DWORD* v12; // esi
    _DWORD* v13; // ebx
    _DWORD* v14; // ebp
    _DWORD* v15; // edi
    int v16; // eax
    wchar_t* v17; // eax
    wchar_t* v18; // eax
    _DWORD* v19; // eax
    _DWORD* v20; // eax
    _DWORD* v21; // eax
    _DWORD* v22; // eax
    _DWORD* v23; // eax
    _DWORD* v24; // eax
    _DWORD* v25; // eax
    _DWORD* v26; // eax
    wchar_t* v27; // [esp-14h] [ebp-1Ch]
    wchar_t* v28; // [esp-14h] [ebp-1Ch]

    sub_4D6F60(0);
    sub_4D6F80(0);
    if (!sub_40A5C0(0x2000000) && !sub_4D6F30())
    {
        *(_DWORD*)& byte_5D4594[815048] = 0;
        *(_DWORD*)& byte_587000[87412] = -1;
    }
    *(_DWORD*)& byte_5D4594[815076] = 0;
    *(_DWORD*)& byte_5D4594[815080] = 0;
    *(_DWORD*)& byte_5D4594[815084] = 0;
    sub_43BDD0(10000);
    sub_4A24C0(1);
    if (*(int*)& byte_587000[87404] != 1 || (sub_4A1BE0(0), *(int*)& byte_587000[87412] != -1))
        sub_49FDB0(0);
    if (*(_DWORD*)& byte_5D4594[814980])
    {
        *(_DWORD*)& byte_5D4594[815044] = 0;
        *(_BYTE*)(*(_DWORD*)& byte_5D4594[815040] + 64) = 3;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[815040] + 56) = sub_438330;
        sub_43BE40(3);
        sub_452D80(922, 100);
        nox_window_set_hidden(*(int*)& byte_5D4594[814980], 0);
        nox_window_set_hidden(*(int*)& byte_5D4594[815000], 0);
        sub_46ABB0(*(int*)& byte_5D4594[814984], 1);
        if (*(_DWORD*)& byte_5D4594[815048])
            sub_4375C0(0);
        sub_46ACE0(*(_DWORD * *)& byte_5D4594[814980], 10047, 10051, *(_DWORD*)& byte_587000[87408] == 0);
        if (sub_4D6FA0() == 2)
        {
            v25 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10010);
            nox_window_call_field_94(*(int*)& byte_5D4594[814980], 16391, (int)v25, 0);
            v26 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10010);
            nox_window_call_field_94(*(int*)& byte_5D4594[814980], 16391, (int)v26, 0);
        }
        result = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[814980] = nox_new_window_from_file("noxworld.wnd", sub_439E70);
        if (*(_DWORD*)& byte_5D4594[814980])
        {
            sub_49FF20();
            sub_46A8C0(*(int*)& byte_5D4594[814980]);
            nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[814980], sub_439D00, 0, 0);
            v1 = sub_43C5B0(*(_DWORD * *)& byte_5D4594[814980], 0, 0, 0, -480, 0, 20, 0, -40);
            *(_DWORD*)& byte_5D4594[815040] = v1;
            if (v1)
            {
                *v1 = 10000;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[815040] + 48) = sub_438370;
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[815040] + 56) = sub_438330;
                *(_DWORD*)& byte_5D4594[814984] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10020);
                *(_DWORD*)& byte_5D4594[814988] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10021);
                sub_46B300(*(int*)& byte_5D4594[814984], sub_439D00);
                sub_46B300(*(int*)& byte_5D4594[814988], sub_439D00);
                sub_46B2C0(*(int*)& byte_5D4594[814988], sub_439E70);
                *(_DWORD*)& byte_5D4594[814996] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10011);
                *(_DWORD*)& byte_5D4594[815012] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10037);
                *(_DWORD*)& byte_5D4594[815004] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10034);
                *(_DWORD*)& byte_5D4594[815000] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10033);
                *(_DWORD*)& byte_5D4594[814992] = sub_489B80(*(int*)& byte_5D4594[814980]);
                *(_DWORD*)& byte_5D4594[815008] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10001);
                *(_DWORD*)& byte_5D4594[815016] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10038);
                *(_DWORD*)& byte_5D4594[815020] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10039);
                *(_DWORD*)& byte_5D4594[815024] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10040);
                *(_DWORD*)& byte_5D4594[815028] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10041);
                *(_DWORD*)& byte_5D4594[815032] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10042);
                v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10002);
                if (sub_40A5C0(0x1000000))
                    sub_46ABB0((int)v2, 0);
                v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10003);
                v3[9] &= 0xFFFFFFFB;
                v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10046);
                sub_46B340((int)v4, sub_438C80);
                sub_46B2C0(*(int*)& byte_5D4594[815012], sub_439E70);
                nox_window_set_hidden(*(int*)& byte_5D4594[815012], 1);
                nox_window_set_hidden(*(int*)& byte_5D4594[815000], 1);
                sub_46B280(*(int*)& byte_5D4594[815008], *(int*)& byte_5D4594[814980]);
                if (*(_DWORD*)& byte_587000[87404])
                {
                    nox_set_draw_unk1(sub_41E210);
                    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10007);
                    nox_window_set_hidden((int)v6, 0);
                    *(_DWORD*)& byte_587000[87412] = -1;
                    nox_window_set_hidden(*(int*)& byte_5D4594[814984], 1);
                    v7 = loadString_sub_40F1D0((char*)& byte_587000[88164], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2530);
                    nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v7, 0);
                }
                else
                {
                    *(_DWORD*)& byte_587000[87412] = 0;
                    nox_window_set_hidden(*(int*)& byte_5D4594[814988], 1);
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[88112], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2517);
                    nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v5, 0);
                    sub_46ACE0(*(_DWORD * *)& byte_5D4594[814984], 10620, 10631, 1);
                    sub_49FDB0(0);
                }
                *(_DWORD*)& byte_5D4594[814556] = sub_42F970("NWGameIconLargeGreen");
                *(_DWORD*)& byte_5D4594[814560] = sub_42F970("NWGameIconLargeGreenLit");
                *(_DWORD*)& byte_5D4594[814564] = sub_42F970("NWGameIconSmallGreen");
                *(_DWORD*)& byte_5D4594[814568] = sub_42F970("NWGameIconSmallGreenLit");
                *(_DWORD*)& byte_5D4594[814572] = sub_42F970("NWGameIconLargeYellow");
                *(_DWORD*)& byte_5D4594[814576] = sub_42F970("NWGameIconLargeYellowLit");
                *(_DWORD*)& byte_5D4594[814580] = sub_42F970("NWGameIconSmallYellow");
                *(_DWORD*)& byte_5D4594[814584] = sub_42F970("NWGameIconSmallYellowLit");
                *(_DWORD*)& byte_5D4594[814588] = sub_42F970("NWGameIconLargeRed");
                *(_DWORD*)& byte_5D4594[814592] = sub_42F970("NWGameIconLargeRedLit");
                *(_DWORD*)& byte_5D4594[814596] = sub_42F970("NWGameIconSmallRed");
                *(_DWORD*)& byte_5D4594[814600] = sub_42F970("NWGameIconSmallRedLit");
                *(_DWORD*)& byte_5D4594[814900] = sub_42F970("NWMapULLg");
                *(_DWORD*)& byte_5D4594[814904] = sub_42F970("NWMapURLg");
                *(_DWORD*)& byte_5D4594[814908] = sub_42F970("NWMapLLLg");
                *(_DWORD*)& byte_5D4594[814912] = sub_42F970("NWMapLRLg");
                v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[815012], 10053);
                v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[815012], 10043);
                v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[815012], 10044);
                v11 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[815012] + 32);
                sub_46B280((int)v8, *(int*)& byte_5D4594[815012]);
                sub_46B280((int)v9, *(int*)& byte_5D4594[815012]);
                sub_46B280((int)v10, *(int*)& byte_5D4594[815012]);
                v11[9] = v8;
                v11[7] = v9;
                v11[8] = v10;
                *(_DWORD*)(v8[100] + 8) = 16;
                *(_DWORD*)(v8[100] + 12) = 12;
                sub_46AE40(v8[100], 0, -15);
                v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[815000], 10032);
                v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[815000], 10035);
                v14 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[815000], 10036);
                v15 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[815004] + 32);
                sub_46B280((int)v12, *(int*)& byte_5D4594[815004]);
                sub_46B280((int)v13, *(int*)& byte_5D4594[815004]);
                sub_46B280((int)v14, *(int*)& byte_5D4594[815004]);
                v15[9] = v12;
                v15[7] = v13;
                v15[8] = v14;
                *(_DWORD*)(v12[100] + 8) = 16;
                *(_DWORD*)(v12[100] + 12) = 10;
                sub_438480();
                v16 = sub_40A430();
                sub_40A3C0(v16);
                *(_DWORD*)& byte_5D4594[815048] = 0;
                *(_DWORD*)& byte_5D4594[815044] = 0;
                *(_DWORD*)& byte_5D4594[815052] = 0;
                *(_DWORD*)& byte_5D4594[814548] = 0;
                *(_QWORD*)& byte_5D4594[815068] = sub_416BB0() + 1000;
                if (*(_DWORD*)& byte_587000[87408] == 1)
                    sub_4383A0();
                if (!*(_DWORD*)& byte_587000[87404])
                    sub_554B40(0);
                *(_DWORD*)& byte_5D4594[815088] = 0;
                sub_4158C0();
                sub_415D50();
                sub_430C30_set_video_max(max_win_width, max_win_height);
                sub_477610(0);
                if (*(_DWORD*)& byte_5D4594[815096])
                {
                    v27 = loadString_sub_40F1D0((char*)& byte_587000[88552], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2616);
                    v17 = loadString_sub_40F1D0((char*)& byte_587000[88600], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2616);
                    sub_449A10(0, (int)v17, (int)v27, 33, 0, 0);
                    sub_44A360(1);
                    *(_DWORD*)& byte_5D4594[815096] = 0;
                }
                else if (*(_DWORD*)& byte_5D4594[815100])
                {
                    v28 = loadString_sub_40F1D0((char*)& byte_587000[88656], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2623);
                    v18 = loadString_sub_40F1D0((char*)& byte_587000[88704], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2623);
                    sub_449A10(0, (int)v18, (int)v28, 33, 0, 0);
                    sub_44A360(1);
                    *(_DWORD*)& byte_5D4594[815100] = 0;
                }
                sub_43DE40(sub_438770);
                if (sub_44A4A0())
                    sub_44A4B0();
                sub_46B340(*(int*)& byte_5D4594[814984], sub_438E30);
                v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10054);
                sub_46B340((int)v19, sub_438E30);
                v20 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10055);
                sub_46B340((int)v20, sub_438E30);
                v21 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10056);
                sub_46B340((int)v21, sub_438E30);
                v22 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10057);
                sub_46B340((int)v22, sub_438E30);
                if (!*(_DWORD*)& byte_587000[87408])
                    sub_46ACE0(*(_DWORD * *)& byte_5D4594[814980], 10047, 10051, 1);
                if (sub_4D6FA0() == 1)
                {
                    v23 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10002);
                    nox_window_call_field_94(*(int*)& byte_5D4594[814980], 16391, (int)v23, 0);
                    sub_4D6F60(1);
                    v24 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10020);
                    nox_window_call_field_93((int)v24, 5, 15663512, 0);
                }
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (00438330) --------------------------------------------------------
int sub_438330()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[815040] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[815040]);
    if (!sub_40A5C0(0x10000000))
        sub_43A9D0();
    if (v0)
        v0();
    return 1;
}

//----- (00438370) --------------------------------------------------------
int sub_438370()
{
    if (*(_BYTE*)(*(_DWORD*)& byte_5D4594[815040] + 64) == 1)
        return sub_438330();
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[815040] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    return 1;
}

//----- (004383A0) --------------------------------------------------------
int sub_4383A0()
{
    wchar_t* v0; // eax
    int result; // eax

    if (!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[814992]))
    {
        nox_window_set_hidden(*(int*)& byte_5D4594[814992], 1);
        sub_489870();
    }
    nox_window_set_hidden(*(int*)& byte_5D4594[815012], 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[814984], 1);
    nox_window_set_hidden(*(int*)& byte_5D4594[814988], 1);
    sub_46AD20(*(_DWORD * *)& byte_5D4594[814980], 10006, 10007, 1);
    sub_46ACE0(*(_DWORD * *)& byte_5D4594[814980], 10047, 10051, 0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[88760], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 418);
    nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v0, 0);
    result = *(_DWORD*)& byte_587000[87404];
    *(_DWORD*)& byte_587000[87408] = 1;
    if (*(_DWORD*)& byte_587000[87404] == 1)
        * (_DWORD*)& byte_587000[87412] = -1;
    return result;
}

//----- (00438480) --------------------------------------------------------
int sub_438480()
{
    sub_46B2C0(*(int*)& byte_5D4594[815012], sub_439050);
    sub_46B300(*(int*)& byte_5D4594[815012], sub_438EF0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[815016], *(int*)& byte_5D4594[815012]);
    sub_46B300(*(int*)& byte_5D4594[815016], sub_438EF0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[815020], *(int*)& byte_5D4594[815012]);
    sub_46B300(*(int*)& byte_5D4594[815020], sub_438EF0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[815024], *(int*)& byte_5D4594[815012]);
    sub_46B300(*(int*)& byte_5D4594[815024], sub_438EF0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[815028], *(int*)& byte_5D4594[815012]);
    sub_46B300(*(int*)& byte_5D4594[815028], sub_438EF0);
    sub_46B120(*(_DWORD * *)& byte_5D4594[815032], *(int*)& byte_5D4594[815012]);
    sub_46B300(*(int*)& byte_5D4594[815032], sub_438EF0);
    **(_DWORD * *)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815004] + 32) + 28) = 10035;
    **(_DWORD * *)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815004] + 32) + 32) = 10036;
    **(_DWORD * *)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815004] + 32) + 36) = 10032;
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815016],
            16408,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 28),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815020],
            16408,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 28),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815024],
            16408,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 28),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815028],
            16408,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 28),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815032],
            16408,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 28),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815016],
            16409,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 32),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815020],
            16409,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 32),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815024],
            16409,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 32),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815028],
            16409,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 32),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815032],
            16409,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 32),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815016],
            16410,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 36),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815020],
            16410,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 36),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815024],
            16410,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 36),
            0);
    nox_window_call_field_94(
            *(int*)& byte_5D4594[815028],
            16410,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 36),
            0);
    return nox_window_call_field_94(
            *(int*)& byte_5D4594[815032],
            16410,
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 36),
            0);
}

//----- (00438770) --------------------------------------------------------
int sub_438770()
{
    int result; // eax
    __int64 v1; // rax
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    _WORD* v6; // esi
    _DWORD* v7; // eax

    if (*(_DWORD*)& byte_5D4594[814548])
    {
        switch (*(_DWORD*)& byte_5D4594[814548])
        {
            case 2:
                sub_438BD0();
                sub_43AF90(1);
                result = 1;
                break;
            case 3:
                if ((unsigned __int64)sub_416BB0() < *(_QWORD*)& byte_5D4594[814956])
                goto LABEL_29;
                sub_43AFA0(8);
                result = 1;
                break;
            case 4:
                sub_43AF90(3);
                v2 = loadString_sub_40F1D0((char*)& byte_587000[88816], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1343);
                sub_449E30((int)v2);
                *(_QWORD*)& byte_5D4594[814956] = sub_416BB0() + 20000;
                result = 1;
                break;
            case 5:
                v3 = loadString_sub_40F1D0((char*)& byte_587000[88864], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1349);
                sub_449E00((int)v3);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[88916], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1350);
                sub_449E30((int)v4);
                sub_449EA0(7);
                sub_44A360(0);
                sub_43AF90(6);
                sub_4A24C0(1);
                result = 1;
                break;
            case 7:
                sub_44A360(1);
                v5 = loadString_sub_40F1D0((char*)& byte_587000[88976], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1364);
                sub_449E30((int)v5);
                sub_449EA0(0);
                nox_set_draw_unk1(sub_43B360);
                sub_43AF90(1);
                result = 1;
                break;
            case 8:
                v1 = sub_416BB0();
                *(_DWORD*)& byte_5D4594[814548] = 9;
                *(_QWORD*)& byte_5D4594[814972] = v1 + 1000;
                result = 1;
                break;
            case 9:
                if ((unsigned __int64)sub_416BB0() <= *(_QWORD*)& byte_5D4594[814972])
                goto LABEL_29;
                sub_438A90();
                result = 1;
                break;
            case 0xA:
                v6 = (_WORD*)sub_449E60(4);
                v7 = sub_46B0C0(0, 4001);
                if (v6 && *v6)
                {
                    sub_46ABB0((int)v7, 1);
                    result = 1;
                }
                else
                {
                    sub_46ABB0((int)v7, 0);
                    result = 1;
                }
                break;
            default:
                goto LABEL_29;
        }
    }
    else
    {
        if ((!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[814984])
             || !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[814988])
             || !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[815012]))
            && !*(_DWORD*)& byte_5D4594[815048]
            && !*(_DWORD*)& byte_5D4594[815044]
            && !*(_DWORD*)& byte_5D4594[815052]
            && wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[815000]))
        {
            if ((unsigned __int64)sub_416BB0() > * (_QWORD*)& byte_5D4594[815068])
            {
                sub_4378B0();
                return 1;
            }
            if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[815076]) > 0x3E8
                                  && !*(_DWORD*)& byte_5D4594[815060]
                                  && !*(_DWORD*)& byte_587000[87404])
            {
                sub_44A400();
                sub_4379C0();
                sub_4A0360();
                *(_DWORD*)& byte_5D4594[815060] = 1;
            }
        }
        LABEL_29:
        result = 1;
    }
    return result;
}

//----- (00438A90) --------------------------------------------------------
int sub_438A90()
{
    int result; // eax
    BOOL v3; // eax
    int v4; // eax
    u_short v5; // [esp-10h] [ebp-74h]
    char buf[100]; // [esp+0h] [ebp-64h]

    memset(&buf[0], 0, 100);
    /*if (*/ sub_420120((LPBYTE)& buf[56]); //)
    {
        /*if ( !*(_DWORD *)&byte_587000[87404] )
          sub_40E0D0((int)&buf[56], (LPCSTR)&byte_587000[89088], 0);*/
        v3 = sub_40ABD0();
        buf[55] = byte_5D4594[2661960];
        buf[54] = byte_5D4594[2661958];
        buf[98] = !v3;
        *(_DWORD*)& buf[80] = 0x1039A;
        *(_DWORD*)& buf[84] = *(_DWORD*)& byte_5D4594[2660032];
        strcpy(&buf[88], (const char*)& byte_5D4594[2660048]);
        nox_wcscpy((wchar_t*)& buf[4], (const wchar_t*)& byte_5D4594[2661908]);
        sub_43AF90(3);
        *(_QWORD*)& byte_5D4594[814956] = sub_416BB0() + 20000;
        v5 = sub_43B320();
        v4 = sub_43B300();
        result = sub_5550A0(v4, v5, buf);
    }
    /*else
    {
      v0 = loadString_sub_40F1D0((char *)&byte_587000[89028], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 541);
      sub_449E00((int)v0);
      v1 = loadString_sub_40F1D0((char *)&byte_587000[89076], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 542);
      sub_449E30((int)v1);
      sub_449EA0(1);
      sub_43AF90(1);
      result = *(_DWORD *)&byte_587000[87404];
      if ( *(_DWORD *)&byte_587000[87404] == 1 )
        result = sub_40D380();
    }*/
    return result;
}

//----- (00438BD0) --------------------------------------------------------
int sub_438BD0()
{
    int v0; // eax
    wchar_t* v1; // eax
    wchar_t* v2; // eax

    if (!sub_44A4A0())
        sub_449A10(*(int*)& byte_5D4594[814980], 0, 0, 0, 0, 0);
    v0 = *(_DWORD*)& byte_5D4594[814552];
    if (*(_DWORD*)& byte_5D4594[814552] != 8
        && *(_DWORD*)& byte_5D4594[814552] != 9
        && *(_DWORD*)& byte_5D4594[814552] != 10)
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[89152], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1262);
        sub_449E00((int)v1);
        v0 = *(_DWORD*)& byte_5D4594[814552];
    }
    v2 = loadString_sub_40F1D0(*(char**)& byte_587000[4 * v0 + 87416], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1265);
    sub_449E30((int)v2);
    *(_DWORD*)& byte_5D4594[815044] = 0;
    sub_449EA0(1);
    sub_44A360(1);
    if (*(_DWORD*)& byte_587000[87404] == 1)
        sub_40D380();
    return sub_4A24C0(1);
}

//----- (00438C80) --------------------------------------------------------
int sub_438C80(int a1, int a2)
{
    int2* v0; // ebx
    char v2[404]; // [esp+4h] [ebp-194h]

    v0 = sub_4309F0();
    if (!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[815000]))
    {
        qmemcpy(v2, *(const void**)& byte_5D4594[815000], sizeof(v2));
        *(_DWORD*)& v2[16] -= 32;
        *(_DWORD*)& v2[20] -= 32;
        *(_DWORD*)& v2[8] += 64;
        *(_DWORD*)& v2[12] += 64;
        if (!*(_DWORD*)& byte_5D4594[815044] && !sub_46AAB0(v2, v0->field_0, v0->field_4))
        {
            nox_window_set_hidden(*(int*)& byte_5D4594[815000], 1);
            nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16403, -1, 0);
            *(_DWORD*)& byte_5D4594[815056] = 0;
            sub_46C6E0(*(int*)& byte_5D4594[815000]);
            sub_46B500(*(int*)& byte_5D4594[814980]);
        }
    }
    if (sub_4A28B0() && !sub_46AAB0(*(_DWORD * *)& byte_5D4594[815036], v0->field_0, v0->field_4))
    {
        sub_4A2890();
        sub_46B500(*(int*)& byte_5D4594[814980]);
    }
    if (*(_DWORD*)& byte_5D4594[815048] && sub_438DD0(v0->field_0, v0->field_4))
    {
        sub_477610(9);
    }
    else if (!sub_44A4A0())
    {
        sub_477610(0);
    }
    return 1;
}

//----- (00438DD0) --------------------------------------------------------
int __cdecl sub_438DD0(unsigned int a1, unsigned int a2)
{
    if (*(int*)& byte_587000[87412] == -1)
    {
        if (a1 > 0xD8 && a1 < 0x258 && a2 > 0x1B && a2 < 0x1C3)
            return 1;
    }
    else if (a1 > 0xE2 && a1 < 0x24E && a2 > 0x25 && a2 < 0x1B9)
    {
        return 1;
    }
    return 0;
}

//----- (00438E30) --------------------------------------------------------
int __cdecl sub_438E30(_DWORD* a1, int a2)
{
    _DWORD* v1; // esi
    int v2; // edx
    int v3; // esi
    __int16** v4; // edi
    int v6; // [esp+4h] [ebp-4h]

    v1 = a1;
    sub_46AA60(a1, &v6, &a1);
    v2 = v1[25];
    if (v1[9] & 6)
        sub_47D2C0(v1[19], v6 + v1[24], (int)a1 + v2);
    else
        sub_47D2C0(v1[15], v6 + v1[24], (int)a1 + v2);
    v3 = v1[100];
    if (!v3)
        return 1;
    do
    {
        if (!(*(_BYTE*)(v3 + 4) & 0x10) && *(_DWORD*)(v3 + 44) == 2048)
        {
            v4 = *(__int16***)(v3 + 32);
            sub_434390(*(int*)& byte_5D4594[2523948]);
            sub_43F7B0(*(_DWORD*)(v3 + 236), *v4, v6 + *(_DWORD*)(v3 + 16), (int)a1 + *(_DWORD*)(v3 + 20));
        }
        v3 = *(_DWORD*)(v3 + 388);
    } while (v3);
    return 1;
}

//----- (00438EF0) --------------------------------------------------------
int __cdecl sub_438EF0(_DWORD* a1, int a2, unsigned int a3, int a4)
{
    int result; // eax
    int v5; // esi
    int v6; // esi

    if (a2 == 19)
    {
        v6 = a1[8];
        nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16391, *(_DWORD*)(v6 + 28), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815016], 16391, *(_DWORD*)(v6 + 28), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815020], 16391, *(_DWORD*)(v6 + 28), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16391, *(_DWORD*)(v6 + 28), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16391, *(_DWORD*)(v6 + 28), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815032], 16391, *(_DWORD*)(v6 + 28), 0);
        result = 0;
    }
    else if (a2 == 20)
    {
        v5 = a1[8];
        nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16391, *(_DWORD*)(v5 + 32), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815016], 16391, *(_DWORD*)(v5 + 32), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815020], 16391, *(_DWORD*)(v5 + 32), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16391, *(_DWORD*)(v5 + 32), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16391, *(_DWORD*)(v5 + 32), 0);
        nox_window_call_field_94(*(int*)& byte_5D4594[815032], 16391, *(_DWORD*)(v5 + 32), 0);
        result = 0;
    }
    else
    {
        result = sub_4A28E0(a1, a2, a3, a4);
    }
    return result;
}

//----- (00439050) --------------------------------------------------------
int __cdecl sub_439050(int a1, unsigned int a2, int* a3, unsigned int a4)
{
    int v4; // edi
    int v5; // edi
    int v7; // eax
    int2 v8; // [esp+Ch] [ebp-8h]

    if (a2 > 0x400F)
    {
        if (a2 == 16400)
        {
            v7 = sub_46B0A0(a3);
            if (v7 >= 10038 && v7 <= 10042)
            {
                nox_window_call_field_94(*(int*)& byte_5D4594[815016], 16403, a4, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815020], 16403, a4, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16403, a4, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16403, a4, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815032], 16403, a4, 0);
                if (a4 < *(int*)& byte_5D4594[815088])
                {
                    v8 = *sub_4309F0();
                    *(_DWORD*)& byte_5D4594[814624] = sub_4A04C0(a4);
                    sub_439370(&v8, *(int*)& byte_5D4594[814624]);
                }
            }
        }
        else if (a2 == 16403 || a2 == 16412)
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[815016], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815020], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815024], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815028], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815032], a2, (int)a3, 0);
        }
    }
    else if (a2 >= 0x400E)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[815016], a2, (int)a3, a4);
        nox_window_call_field_94(*(int*)& byte_5D4594[815020], a2, (int)a3, a4);
        nox_window_call_field_94(*(int*)& byte_5D4594[815024], a2, (int)a3, a4);
        nox_window_call_field_94(*(int*)& byte_5D4594[815028], a2, (int)a3, a4);
        nox_window_call_field_94(*(int*)& byte_5D4594[815032], a2, (int)a3, a4);
    }
    else
    {
        switch (a2)
        {
            case 0x17u:
                return 1;
            case 0x4000u:
                if (a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[815012], 10043)
                    || a3 == sub_46B0C0(*(_DWORD * *)& byte_5D4594[815012], 10044))
                {
                    nox_window_call_field_94(*(int*)& byte_5D4594[815016], 0x4000, (int)a3, 0);
                    nox_window_call_field_94(*(int*)& byte_5D4594[815020], 0x4000, (int)a3, 0);
                    nox_window_call_field_94(*(int*)& byte_5D4594[815024], 0x4000, (int)a3, 0);
                    nox_window_call_field_94(*(int*)& byte_5D4594[815028], 0x4000, (int)a3, 0);
                    nox_window_call_field_94(*(int*)& byte_5D4594[815032], 0x4000, (int)a3, 0);
                }
                break;
            case 0x4009u:
                v4 = *(_DWORD*)(a1 + 32);
                sub_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
                v5 = sub_4A4800(v4);
                nox_window_call_field_94(*(int*)& byte_5D4594[815016], 16412, v5, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815020], 16412, v5, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16412, v5, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16412, v5, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815032], 16412, v5, 0);
                break;
        }
    }
    return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
}

//----- (00439370) --------------------------------------------------------
int __cdecl sub_439370(int2* a1, int a2)
{
    int v2; // eax
    wchar_t* v3; // eax
    int result; // eax

    if (!(*(_BYTE*)(a2 + 164) & 0x10) || (LOBYTE(v2) = sub_4D7700(), v2))
    {
        sub_439450(a1->field_0, a1->field_4, a1);
        sub_46B120(*(_DWORD * *)& byte_5D4594[815000], 0);
        sub_46A8C0(*(int*)& byte_5D4594[815000]);
        sub_46C690(*(int*)& byte_5D4594[815000]);
        sub_46A9B0(*(_DWORD * *)& byte_5D4594[815000], a1->field_0, a1->field_4);
        sub_4394D0(a2);
        *(_DWORD*)& byte_5D4594[815056] = 1;
        *(_WORD*)& byte_5D4594[814604] = *(_WORD*)(a2 + 109);
        result = *(_DWORD*)& byte_5D4594[2650636];
        if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
            result = sub_46ABB0(*(int*)& byte_5D4594[815008], 0);
    }
    else
    {
        v3 = loadString_sub_40F1D0((char*)& byte_587000[89244], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 688);
        sub_449A10(*(int*)& byte_5D4594[814980], 0, (int)v3, 33, 0, 0);
        sub_44A360(0);
        result = sub_44A4B0();
    }
    return result;
}
// 439385: variable 'v2' is possibly undefined

//----- (00439450) --------------------------------------------------------
_DWORD* __cdecl sub_439450(int a1, int a2, _DWORD* a3)
{
    _DWORD* result; // eax
    int v4; // ecx

    result = a3;
    *a3 = a1 - 65;
    a3[1] = a2 - 20;
    if (a1 - 65 + 130 > 600)
        * a3 = 470;
    if (a2 - 20 + 120 > 451)
        a3[1] = 331;
    if (*(_DWORD*)& byte_587000[87408] == 1)
    {
        v4 = 55;
        if (a3[1] >= 55)
            goto LABEL_10;
    }
    else
    {
        v4 = 27;
        if (a3[1] >= 27)
            goto LABEL_10;
    }
    a3[1] = v4;
    LABEL_10:
    if ((int)* a3 < 216)
        * a3 = 216;
    return result;
}

//----- (004394D0) --------------------------------------------------------
int __cdecl sub_4394D0(int a1)
{
    int v1; // ebp
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    wchar_t* v5; // eax
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    __int16 v9; // ax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    int result; // eax
    wchar_t* v13; // eax
    wchar_t* v14; // eax
    int v15; // ebx
    int v16; // esi
    int v17; // edi
    int v18; // ebp
    int v19; // eax
    wchar_t* v20; // eax
    int v21; // esi
    wchar_t* v22; // eax
    int v23; // ebx
    int v24; // edi
    int v25; // ebp
    int v26; // eax
    wchar_t* v27; // eax
    int v28; // edi
    wchar_t* v29; // eax
    int v30; // esi
    int v31; // ebx
    wchar_t* v32; // eax
    wchar_t* v33; // [esp-8h] [ebp-14Ch]
    unsigned __int8 v34; // [esp+10h] [ebp-134h]
    unsigned __int8 v35; // [esp+10h] [ebp-134h]
    int v36; // [esp+14h] [ebp-130h]
    char v37[16]; // [esp+18h] [ebp-12Ch]
    wchar_t v38[100]; // [esp+7Ch] [ebp-C8h]

    v36 = a1 + 111;
    v1 = *(_BYTE*)(a1 + 102) & 0x7F;
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16399, 0, 0);
    v2 = loadString_sub_40F1D0((char*)& byte_587000[89316], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 749);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v2, 14);
    if (*(_BYTE*)(a1 + 120))
    {
        strncpy(v37, (const char*)(a1 + 120), 0xFu);
        v37[15] = 0;
    }
    else
    {
        sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v37);
    }
    nox_swprintf(v38, L"%S", v37);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v38, -1);
    if (*(_DWORD*)& byte_587000[87404] == 1)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89332], -1);
        v3 = loadString_sub_40F1D0((char*)& byte_587000[89376], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 766);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v3, 14);
        sub_439CC0(*(_DWORD*)(a1 + 32), v37);
        nox_swprintf(v38, L"%S", v37);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v38, -1);
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89396], -1);
    v4 = loadString_sub_40F1D0((char*)& byte_587000[89440], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 774);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v4, 14);
    if (*(_DWORD*)(a1 + 96) == 9999)
        nox_swprintf(v38, L"--");
    else
        nox_swprintf(v38, L"%d", *(_DWORD*)(a1 + 96));
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v38, -1);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89464], -1);
    v5 = loadString_sub_40F1D0((char*)& byte_587000[89508], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 787);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v5, 14);
    v6 = sub_43BCB0(*(_WORD*)(a1 + 163));
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v6, -1);
    if (*(_BYTE*)(a1 + 164) & 0x10)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89520], -1);
        v7 = loadString_sub_40F1D0((char*)& byte_587000[89564], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 794);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v7, 14);
        nox_swprintf(v38, L"%d", *(unsigned __int16*)(a1 + 165));
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v38, -1);
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89580], -1);
    v8 = loadString_sub_40F1D0((char*)& byte_587000[89624], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 801);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v8, 14);
    strcpy(v37, (const char*)(a1 + 111));
    nox_swprintf(v38, L"%S", v37);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v38, -1);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89636], -1);
    v9 = *(_WORD*)(a1 + 163);
    if (v9 & 0xC000u)
    {
        if (v9 & 0x4000)
            v33 = loadString_sub_40F1D0((char*)& byte_587000[89680], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 811);
        else
            v33 = loadString_sub_40F1D0((char*)& byte_587000[89732], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 815);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v33, 6);
        v10 = loadString_sub_40F1D0((char*)& byte_587000[89780], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 817);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v10, 6);
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89788], -1);
    v11 = loadString_sub_40F1D0((char*)& byte_587000[89832], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 822);
    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v11, 14);
    nox_swprintf(v38, L"%d/%d\n", *(unsigned __int8*)(a1 + 103), *(unsigned __int8*)(a1 + 104));
    result = nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v38, -1);
    if (*(_BYTE*)(a1 + 164) & 0x20)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89860], -1);
        v13 = loadString_sub_40F1D0((char*)& byte_587000[89904], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 831);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v13, 14);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, *(_DWORD*)& byte_587000[4 * v1 + 87472], -1);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[89916], -1);
        v14 = loadString_sub_40F1D0((char*)& byte_587000[89960], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 836);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v14, 14);
        v15 = 0;
        v16 = 1;
        v34 = 0;
        v17 = 1;
        v18 = 136;
        do
        {
            if (v16 == 0x80000000)
            {
                v16 = 1;
                ++v34;
            }
            else
            {
                v16 *= 2;
            }
            if (sub_424B50(v17) && !(v16 & *(_DWORD*)(v36 + 4 * v34 + 24)) && sub_424A70(v17) & 0x7000000)
            {
                v15 = 1;
                v19 = sub_424930(v17);
                nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, v19, 4);
            }
            ++v17;
            --v18;
        } while (v18);
        if (!v15)
        {
            v20 = loadString_sub_40F1D0((char*)& byte_587000[90016], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 866);
            nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v20, 4);
        }
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[90024], -1);
        v21 = 0;
        v22 = loadString_sub_40F1D0((char*)& byte_587000[90068], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 872);
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v22, 14);
        v23 = 1;
        v35 = 0;
        v24 = 1;
        v25 = 27;
        do
        {
            if (!((unsigned __int8)v23 & *(_BYTE*)(v35 + v36 + 44)))
            {
                v26 = sub_4159F0(v24);
                if (v26)
                {
                    nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, v26, -1);
                    v21 = 1;
                }
            }
            if (v23 == 128)
            {
                v23 = 1;
                ++v35;
            }
            else
            {
                v23 *= 2;
            }
            v24 *= 2;
            --v25;
        } while (v25);
        if (!v21)
        {
            v27 = loadString_sub_40F1D0((char*)& byte_587000[90124], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 899);
            nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v27, 4);
        }
        nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)& byte_587000[90132], -1);
        v28 = 0;
        v29 = loadString_sub_40F1D0((char*)& byte_587000[90176], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 905);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v29, 14);
        v30 = 1;
        v31 = 26;
        do
        {
            if (!(v30 & *(_DWORD*)(a1 + 159)))
            {
                result = sub_415E80(v30);
                if (result)
                {
                    v28 = 1;
                    result = nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, result, -1);
                }
            }
            v30 *= 2;
            --v31;
        } while (v31);
        if (!v28)
        {
            v32 = loadString_sub_40F1D0((char*)& byte_587000[90232], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 920);
            result = nox_window_call_field_94(*(int*)& byte_5D4594[815004], 16397, (int)v32, 4);
        }
    }
    return result;
}

//----- (00439CC0) --------------------------------------------------------
char* __cdecl sub_439CC0(int a1, char* a2)
{
    size_t v2; // esi
    char* result; // eax

    v2 = (size_t)& strstr((const char*)(a1 + 52), "'s_game")[-52 - a1];
    result = strncpy(a2, (const char*)(a1 + 52), v2);
    a2[v2] = 0;
    return result;
}

//----- (00439D00) --------------------------------------------------------
int __cdecl sub_439D00(int* a1, int a2, unsigned int a3, int a4)
{
    int2* v4; // eax

    if (a2 == 5)
    {
        if (sub_46B0A0(a1) == 10020 && *(_DWORD*)& byte_5D4594[815048] == 1)
        {
            sub_439D90((unsigned __int16)a3, a3 >> 16);
            return 1;
        }
        return 0;
    }
    if (a2 != 21)
        return 0;
    if (a3 != 1)
    {
        if (a3 != 28 && a3 == 57)
        {
            v4 = sub_4309F0();
            nox_window_call_field_93((int)a1, 5, v4->field_0 | (v4->field_4 << 16), 0);
        }
        return 0;
    }
    if (a4 == 2)
        sub_4373A0();
    return 1;
}

//----- (00439D90) --------------------------------------------------------
int __cdecl sub_439D90(unsigned int a1, unsigned int a2)
{
    int result; // eax
    __int16 v3; // dx

    result = sub_438DD0(a1, a2);
    if (result)
    {
        v3 = a2 + *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87530] - 27;
        *(_WORD*)& byte_5D4594[814916] = a1 + *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87528] - 216;
        *(_WORD*)& byte_5D4594[814918] = v3;
        sub_43B460();
        if (sub_43BDB0() & 2)
            sub_4D6F60(1);
        if (sub_4D6F50())
        {
            if (sub_4DC7D0())
            {
                sub_4A7A70(1);
                sub_4A4DB0();
                return sub_477610(0);
            }
        }
        else if (sub_4DC630())
        {
            sub_4A7A70(1);
            sub_4A4DB0();
            return sub_477610(0);
        }
        sub_4A7A70(0);
        sub_4A4840();
        result = sub_477610(0);
    }
    return result;
}

//----- (00439E70) --------------------------------------------------------
int __cdecl sub_439E70(int a1, unsigned int a2, int* a3, int a4)
{
    int v4; // eax
    int v5; // esi
    int* v6; // eax
    int* v7; // eax
    int v8; // esi
    int v9; // esi
    int v10; // eax
    int result; // eax
    const wchar_t* v12; // eax
    int v13; // eax
    int v14; // eax
    wchar_t* v15; // eax
    int v16; // eax
    _DWORD* v17; // eax
    _DWORD* v18; // eax
    int v19; // esi
    int v20; // esi
    wchar_t* v21; // eax
    int v22; // eax
    wchar_t* v23; // eax
    char* v24; // eax
    char* v25; // eax
    char* v26; // eax
    int v27; // eax
    u_short v28; // [esp-8h] [ebp-A0h]
    int2 v29; // [esp+4h] [ebp-94h]
    int v30; // [esp+Ch] [ebp-8Ch]
    int v31; // [esp+10h] [ebp-88h]
    char buf[4]; // [esp+14h] [ebp-84h]
    wchar_t v33[10]; // [esp+18h] [ebp-80h]
    char v34[36]; // [esp+2Ch] [ebp-6Ch]
    char v35[72]; // [esp+50h] [ebp-48h]

    if (a2 > 0x4010)
    {
        if (a2 == 16403 || a2 == 16412)
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[815016], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815020], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815024], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815028], a2, (int)a3, 0);
            nox_window_call_field_94(*(int*)& byte_5D4594[815032], a2, (int)a3, 0);
        }
        return 0;
    }
    switch (a2)
    {
        case 0x4010u:
            if (sub_46B0A0(a3) == 10061)
            {
                v29 = *sub_4309F0();
                *(_DWORD*)& byte_5D4594[814624] = sub_4A28C0(a4);
                sub_439370(&v29, *(int*)& byte_5D4594[814624]);
                return 0;
            }
            return 0;
        case 0x17u:
            return 1;
        case 0x4000u:
            v27 = sub_46B0A0(a3);
            if (v27 >= 10043 && v27 <= 10044)
            {
                nox_window_call_field_94(*(int*)& byte_5D4594[815016], 0x4000, (int)a3, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815020], 0x4000, (int)a3, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815024], 0x4000, (int)a3, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815028], 0x4000, (int)a3, 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[815032], 0x4000, (int)a3, 0);
                return 0;
            }
            return 0;
    }
    if (a2 != 16391)
        return 0;
    v4 = sub_46B0A0(a3);
    v5 = v4;
    if (v4 != 10043 && v4 != 10044 && v4 != 10035 && v4 != 10036)
        sub_452D80(766, 100);
    if (v5 >= 10070)
    {
        v29 = *sub_4309F0();
        v30 = v29.field_0 - 216;
        v31 = v29.field_4 - 27;
        v6 = (int*)sub_4A0020();
        if (sub_4A25C0(&v30, v6) >= 2)
        {
            v7 = (int*)sub_4A0020();
            *(_DWORD*)& byte_5D4594[815036] = sub_4A2610(*(int*)& byte_5D4594[814980], &v30, v7);
        }
        else
        {
            *(_DWORD*)& byte_5D4594[814624] = sub_4A0490(v5 - 10070);
            sub_439370(&v29, *(int*)& byte_5D4594[814624]);
        }
        sub_4776B0((wchar_t*)& byte_5D4594[815112]);
    }
    if (v5 > 10006)
    {
        switch (v5)
        {
            case 10007:
                if (*(_DWORD*)& byte_5D4594[815048])
                    sub_4373A0();
                if (*(_DWORD*)& byte_587000[87404])
                    sub_43A980();
                else
                    OnLibraryNotice(418, 0);
                return 0;
            case 10010:
                sub_4373A0();
                return 0;
            case 10047:
            case 10048:
            case 10049:
            case 10050:
            case 10051:
                sub_4379C0();
                sub_4A0290(v5);
                sub_4A0390();
                return 0;
            case 10054:
                *(_DWORD*)& byte_587000[87412] = 0;
                sub_43A810();
                sub_4378B0();
                if (sub_40A5C0(0x2000000)) {
                    v24 = sub_4A7EF0();
                    sub_439D90(*(_DWORD*)v24 + 216, *((_DWORD*)v24 + 1) + 27);
                } else {
                    sub_439D90(0x198u, 0xEFu);
                }
                result = 0;
                break;
            case 10055:
                *(_DWORD*)& byte_587000[87412] = 1;
                sub_43A810();
                sub_4378B0();
                if (!sub_40A5C0(0x2000000)) {
                    sub_439D90(0x198u, 0xEFu);
                    result = 0;
                } else {
                    v25 = sub_4A7EF0();
                    sub_439D90(*(_DWORD*)v25 + 216, *((_DWORD*)v25 + 1) + 27);
                    return 0;
                }
                break;
            case 10056:
                *(_DWORD*)& byte_587000[87412] = 2;
                sub_43A810();
                sub_4378B0();
                if (!sub_40A5C0(0x2000000)) {
                    sub_439D90(0x198u, 0xEFu);
                } else {
                    v24 = sub_4A7EF0();
                    sub_439D90(*(_DWORD*)v24 + 216, *((_DWORD*)v24 + 1) + 27);
                }
                result = 0;
                break;
            case 10057:
                *(_DWORD*)& byte_587000[87412] = 3;
                sub_43A810();
                sub_4378B0();
                if (sub_40A5C0(0x2000000))
                {
                    v26 = sub_4A7EF0();
                    sub_439D90(*(_DWORD*)v26 + 216, *((_DWORD*)v26 + 1) + 27);
                }
                else
                {
                    sub_439D90(0x198u, 0xEFu);
                }
                result = 0;
                break;
            default:
                return 0;
        }
        return result;
    }
    if (v5 == 10006)
    {
        *(_DWORD*)& byte_5D4594[815048] = 0;
        sub_4378B0();
        return 0;
    }
    if (v5 > 10002)
    {
        v19 = v5 - 10003;
        if (v19)
        {
            v20 = v19 - 1;
            if (!v20)
            {
                *(_DWORD*)& byte_5D4594[815048] = 0;
                sub_4383A0();
                sub_4378B0();
                return 0;
            }
            if (v20 == 1)
            {
                *(_DWORD*)& byte_5D4594[815048] = 0;
                nox_window_set_hidden(*(int*)& byte_5D4594[815012], 1);
                nox_window_set_hidden(*(int*)& byte_5D4594[814984], 1);
                nox_window_set_hidden(*(int*)& byte_5D4594[814988], 1);
                nox_window_set_hidden(*(int*)& byte_5D4594[814992], 0);
                sub_46AD20(*(_DWORD * *)& byte_5D4594[814980], 10006, 10007, 0);
                sub_46ACE0(*(_DWORD * *)& byte_5D4594[814980], 10047, 10051, 1);
                v21 = loadString_sub_40F1D0((char*)& byte_587000[90440], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2186);
                nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v21, 0);
                return 0;
            }
            return 0;
        }
        LOBYTE(v22) = sub_4D7700();
        if (!v22)
        {
            v23 = loadString_sub_40F1D0((char*)& byte_587000[90328], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2013);
            sub_449A10(*(int*)& byte_5D4594[814980], 0, (int)v23, 33, 0, 0);
            sub_44A360(0);
            sub_44A4B0();
            return 0;
        }
        *(_DWORD*)& byte_5D4594[815048] = 1;
        sub_40A540(0x10000);
        sub_430B10_set_mouse_pos(408, 239);
        sub_4375C0(0);
        if (!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[814992]))
            sub_489870();
        sub_4D6F60(1);
        sub_470AA0(1);
        if (*(_DWORD*)& byte_587000[87404] == 1)
        {
            if (*(int*)& byte_587000[87412] != -1)
                return 0;
            goto LABEL_52;
        }
        LABEL_53:
        *(_DWORD*)& byte_587000[87412] = 0;
        v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10020);
        nox_window_call_field_93((int)v18, 5, 15663512, 0);
        return 0;
    }
    if (v5 == 10002)
    {
        if (sub_40A5C0(0x1000000))
            return 0;
        *(_DWORD*)& byte_5D4594[815048] = 1;
        sub_40A4D0(0x10000);
        sub_470AA0(0);
        sub_430B10_set_mouse_pos(408, 239);
        sub_4375C0(0);
        if (!wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[814992]))
            sub_489870();
        if (sub_40A5C0(0x2000000) || sub_4D6F30())
            return 0;
        if (*(_DWORD*)& byte_587000[87404] == 1)
        {
            if (*(int*)& byte_587000[87412] != -1)
                return 0;
            LABEL_52:
            v16 = sub_415FA0(10054, 10057);
            v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], v16);
            nox_window_call_field_94(*(int*)& byte_5D4594[814980], 16391, (int)v17, 0);
            return 0;
        }
        goto LABEL_53;
    }
    v8 = v5 - 4001;
    if (!v8)
    {
        if (sub_43AF80() == 6)
        {
            v12 = (const wchar_t*)sub_449E60(4);
            nox_wcsncpy(v33, v12, 9u);
            v33[8] = 0;
            v28 = sub_43B320();
            v13 = sub_43B300();
            sub_5550D0(v13, v28, buf);
            sub_43AF90(3);
            *(_QWORD*)& byte_5D4594[814956] = sub_416BB0() + 20000;
            sub_449EA0(0);
            return 0;
        }
        if (sub_43AF80() == 10)
        {
            v14 = sub_449E60(4);
            nox_sprintf(v35, "%S", v14);
            v15 = loadString_sub_40F1D0((char*)& byte_587000[90496], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 2209);
            sub_449E30((int)v15);
            sub_43AF90(11);
            sub_40D740((int)v34);
            sub_449EA0(0);
            return 0;
        }
        if (sub_43AF80() == 1)
        {
            if (*(_DWORD*)& byte_587000[87404] == 1)
                sub_40D380();
            sub_43A920();
            sub_4379F0();
            return 0;
        }
        if (*(_DWORD*)& byte_5D4594[815104])
        {
            *(_QWORD*)& byte_5D4594[815068] = sub_416BB0() + 1000;
            return 0;
        }
        return 0;
    }
    v9 = v8 - 1;
    if (!v9)
    {
        if (*(_DWORD*)& byte_587000[87404] == 1)
            sub_40D380();
        sub_43A920();
        sub_4379F0();
        return 0;
    }
    if (v9 != 5999 || *(_DWORD*)& byte_5D4594[815044])
        return 0;
    v10 = sub_43B340();
    if (v10 & 0x1000)
    {
        sub_4D6F80(1);
        sub_470AA0(1);
    }
    sub_43B460();
    if (sub_4D6F70())
    {
        if (sub_4DC7D0())
        {
            sub_4A7A70(1);
            sub_4A4DB0();
            *(_DWORD*)& byte_5D4594[815044] = 1;
            sub_4A2890();
            return 0;
        }
    }
    else if (sub_4DC630())
    {
        sub_4A7A70(1);
        sub_4A4DB0();
        *(_DWORD*)& byte_5D4594[815044] = 1;
        sub_4A2890();
        return 0;
    }
    sub_4A7A70(0);
    sub_4A4840();
    *(_DWORD*)& byte_5D4594[815044] = 1;
    sub_4A2890();
    return 0;
}
// 43A3CE: variable 'v22' is possibly undefined

//----- (0043A810) --------------------------------------------------------
void sub_43A810()
{
    int v0; // edi
    int* v1; // esi
    wchar_t* v2; // [esp-8h] [ebp-Ch]

    nox_window_set_hidden(*(int*)& byte_5D4594[814984], 0);
    nox_window_set_hidden(*(int*)& byte_5D4594[814988], 1);
    sub_46AE60(*(int*)& byte_5D4594[814984], *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_587000[87412] + 814900]);
    if (*(_DWORD*)& byte_5D4594[815048] == 1)
        v2 = loadString_sub_40F1D0((char*)& byte_587000[90544], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 377);
    else
        v2 = loadString_sub_40F1D0((char*)& byte_587000[90596], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 382);
    nox_window_call_field_94(*(int*)& byte_5D4594[814996], 16385, (int)v2, 0);
    if (*(_DWORD*)& byte_587000[87404] == 1)
    {
        sub_46ACE0(*(_DWORD * *)& byte_5D4594[814984], 10600, 10611, 1);
        v0 = 0;
        v1 = (int*)& byte_587000[87560];
        do
        {
            sub_46ACE0(*(_DWORD * *)& byte_5D4594[814984], *v1, v1[1], v0 != *(_DWORD*)& byte_587000[87412]);
            v1 += 2;
            ++v0;
        } while ((int)v1 < (int)& byte_587000[87592]);
    }
    sub_49FDB0(*(int*)& byte_587000[87412]);
}

//----- (0043A920) --------------------------------------------------------
int sub_43A920()
{
    int result; // eax

    sub_46B500(*(int*)& byte_5D4594[814980]);
    if (*(_DWORD*)& byte_587000[87404] == 1)
    {
        sub_554D10();
        nox_set_draw_unk1(sub_41E210);
    }
    if (!sub_43BE30() || !*(_DWORD*)& byte_5D4594[815084])
        sub_44A400();
    result = sub_43AF90(0);
    *(_DWORD*)& byte_5D4594[815044] = 0;
    return result;
}

//----- (0043A980) --------------------------------------------------------
int sub_43A980()
{
    wchar_t* v0; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]

    v2 = loadString_sub_40F1D0((char*)& byte_587000[90648], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1295);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[90700], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1295);
    sub_449A10(*(int*)& byte_5D4594[814980], (int)v0, (int)v2, 39, 0, 0);
    return sub_43AF90(10);
}

//----- (0043A9D0) --------------------------------------------------------
int sub_43A9D0()
{
    sub_46ADE0(*(int*)& byte_5D4594[814984]);
    sub_489FB0();
    sub_4A2890();
    if (*(_DWORD*)& byte_5D4594[815000] && !*(_DWORD*)(*(_DWORD*)& byte_5D4594[815000] + 396))
    {
        sub_46C6E0(*(int*)& byte_5D4594[815000]);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[815000]);
        *(_DWORD*)& byte_5D4594[815000] = 0;
    }
    if (*(_DWORD*)& byte_5D4594[814980])
    {
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[814980]);
        *(_DWORD*)& byte_5D4594[814980] = 0;
    }
    sub_43A920();
    sub_46B500(0);
    *(_DWORD*)& byte_5D4594[815088] = 0;
    sub_49FFA0(0);
    sub_554D10();
    sub_477610(0);
    return sub_43DE40(0);
}

//----- (0043AA70) --------------------------------------------------------
char* sub_43AA70()
{
    char* v0; // esi
    char* v1; // ebx
    char* v2; // eax
    char v3; // al
    char v4; // al
    char v5; // cl
    char* v6; // eax
    char* result; // eax
    __int16 v8; // cx
    char v9[32]; // [esp+0h] [ebp-12Ch]
    char v10[268]; // [esp+20h] [ebp-10Ch]

    if (*(_DWORD*)& byte_5D4594[528252] && *(_DWORD*)& byte_5D4594[528256])
        sub_413D30((char*)& byte_587000[90708]);
    *(_DWORD*)& byte_5D4594[815048] = 0;
    *(_DWORD*)& byte_5D4594[815052] = 1;
    v0 = sub_416590(0);
    v1 = sub_416640();
    qmemcpy(v1 + 111, v0, 0x3Au);
    *(_WORD*)(v1 + 163) = sub_40A5B0();
    *(_DWORD*)(v1 + 135) = -1;
    *(_DWORD*)(v1 + 139) = -1;
    *(_DWORD*)(v1 + 143) = -1;
    *(_DWORD*)(v1 + 147) = -1;
    *(_DWORD*)(v1 + 151) = -1;
    *(_DWORD*)(v1 + 155) = -1;
    *(_DWORD*)(v1 + 159) = -1;
    v2 = sub_40A4C0();
    strncpy(v1 + 120, v2, 0xFu);
    strcpy(v1 + 111, sub_409B40());
    if (sub_4D6F50())
    {
        if (*(_DWORD*)& byte_5D4594[528256])
            * (_WORD*)(v1 + 165) = sub_4E3CC0();
        else
            *(_WORD*)(v1 + 165) = 1;
    }
    v1[104] = sub_409FA0();
    v3 = sub_416F40();
    v1[103] = v3;
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
    {
        v1[103] = v3 - 1;
        --v1[104];
    }
    v4 = sub_43BE50_get_video_mode_id();
    v5 = v1[102];
    *((_DWORD*)v1 + 12) = 66458;
    v1[102] = v5 & 0x80 | v4;
    *((_DWORD*)v1 + 11) = *(_DWORD*)& byte_5D4594[814916];
    *(_WORD*)(v1 + 109) = sub_40A430();
    sub_435720((char*)& byte_587000[90740]);
    if (*(_DWORD*)& byte_587000[87404] == 1)
    {
        memset(v10, 0, sizeof(v10));
        v6 = sub_41FA40();
        nox_sprintf(v9, "%s%s", v6, &byte_587000[90752]);
        strcpy(&v10[52], v9);
        *(_DWORD*)v10 = sub_420100();
        *(_DWORD*)& v10[4] = 1;
        *(_DWORD*)& v10[8] = 32;
        *(_DWORD*)& v10[12] = 0;
        *(_DWORD*)& v10[16] = 0;
        *(_DWORD*)& v10[20] = 1;
        *(_DWORD*)& v10[24] = 1;
        *(_DWORD*)& v10[44] = 0;
        *(_DWORD*)& v10[28] = 0;
        *(_DWORD*)& v10[224] = 66458;
        *(_DWORD*)& v10[32] = *(_DWORD*)& byte_5D4594[814916];
        v10[sub_425550(v1 + 100, &v10[69], 552) + 69] = 0;
        sub_40D320((int)v10);
    }
    result = sub_416590(1);
    v8 = *((_WORD*)result + 26) & 0xE90F;
    HIBYTE(v8) |= 1u;
    *((_WORD*)result + 26) = v8;
    return result;
}

//----- (0043ACC0) --------------------------------------------------------
void sub_43ACC0()
{
    char* v0; // eax
    int i; // ebp
    int v2; // eax
    struct in_addr v3; // eax
    char* v4; // eax
    int v5; // eax
    int v6; // esi
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    char v9[172]; // [esp+0h] [ebp-ECh]
    char v10[32]; // [esp+ACh] [ebp-40h]
    char v11[32]; // [esp+CCh] [ebp-20h]

    if (!*(_DWORD*)& byte_5D4594[815088] && !*(_DWORD*)& byte_5D4594[815044])
    {
        v0 = sub_41FA40();
        nox_sprintf(v11, "%s%s", v0, &byte_587000[90768]);
        for (i = sub_41F0E0(); i; i = sub_41F0C0())
        {
            if (strcmp(v11, (const char*)(i + 52)))
            {
                memset(v9, 0, 0xA8u);
                v9[168] = 0;
                sub_4255F0((_BYTE*)(i + 69), &v9[100], 552);
                *(_DWORD*)& v9[96] = 9999;
                if ((int) * (_DWORD*)(i + 40) >= 0)
                    * (_DWORD*)& v9[96] = *(_DWORD*)(i + 40);
                v2 = *(_DWORD*)(i + 32);
                *(_DWORD*)& v9[44] = *(_DWORD*)(i + 32);
                *(_DWORD*)& v9[48] = *(_DWORD*)(i + 224);
                if (*(int*)& byte_587000[87412] == -1
                    || sub_437860((__int16)v2, *(__int16*)& v9[46]) == *(int*)& byte_587000[87412])
                {
                    if (sub_4899C0((int)v9))
                    {
                        v3.S_un.S_addr = htonl(*(_DWORD*)(i + 36));
                        v4 = inet_ntoa(v3);
                        *(_DWORD*)& v9[12] = *(_DWORD*)v4;
                        *(_DWORD*)& v9[16] = *((_DWORD*)v4 + 1);
                        *(_DWORD*)& v9[20] = *((_DWORD*)v4 + 2);
                        v5 = *((_DWORD*)v4 + 3);
                        *(_DWORD*)& v9[32] = i;
                        *(_DWORD*)& v9[24] = v5;
                        *(_DWORD*)& v9[36] = *(_DWORD*)& byte_5D4594[815088];
                        *(_DWORD*)& v9[44] = *(_DWORD*)(i + 32);
                        sub_4A0030(v9);
                        if (v9[120])
                        {
                            strncpy(v10, &v9[120], 0xFu);
                            v10[15] = 0;
                        }
                        else
                        {
                            sub_43BC80((int)& v9[12], *(unsigned __int16*)& v9[109], v10);
                        }
                        if (++ * (_DWORD*)& byte_5D4594[815088] >= 0x9C4u)
                            break;
                    }
                }
            }
        }
        if (*(_DWORD*)& byte_5D4594[815088])
            sub_4A0360();
        sub_44A400();
        if (sub_40A5C0(0x2000000) && *(int*)& byte_587000[87412] == -1)
        {
            v6 = sub_4A7F20() + 10053;
            v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], 10002);
            nox_window_call_field_94(*(int*)& byte_5D4594[814980], 16391, (int)v7, 0);
            v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814980], v6);
            nox_window_call_field_94(*(int*)& byte_5D4594[814980], 16391, (int)v8, 0);
        }
        if (*(_DWORD*)& byte_5D4594[815048])
            sub_4375C0(0);
    }
}

//----- (0043AF30) --------------------------------------------------------
int sub_43AF30()
{
    return *(_DWORD*)& byte_5D4594[815052];
}

//----- (0043AF40) --------------------------------------------------------
int sub_43AF40()
{
    return *(_DWORD*)& byte_5D4594[815048];
}

//----- (0043AF50) --------------------------------------------------------
int __cdecl sub_43AF50(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[87404] = a1;
    *(_DWORD*)& byte_5D4594[2650652] = a1 == 1;
    return result;
}

//----- (0043AF70) --------------------------------------------------------
int sub_43AF70()
{
    return *(_DWORD*)& byte_587000[87404];
}

//----- (0043AF80) --------------------------------------------------------
int sub_43AF80()
{
    return *(_DWORD*)& byte_5D4594[814548];
}

//----- (0043AF90) --------------------------------------------------------
int __cdecl sub_43AF90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[814548] = a1;
    return result;
}

//----- (0043AFA0) --------------------------------------------------------
int __cdecl sub_43AFA0(int a1)
{
    *(_DWORD*)& byte_5D4594[814552] = a1;
    return sub_43AF90(2);
}

//----- (0043AFC0) --------------------------------------------------------
void __cdecl sub_43AFC0(int a1)
{
    int* v1; // esi
    int v3; // edi
    int v4; // eax
    int v5; // edx
    int v6; // ecx
    int v7; // edi
    int v8; // eax
    int v9; // ecx
    int2 v10; // [esp+4h] [ebp-8h]

    v1 = sub_4A04F0((char*)(a1 + 52));
    if (!v1)
    {
        sub_43AFA0(9);
        return;
    }
    if (!*(_DWORD*)& byte_587000[87408])
    {
        sub_43A920();
        v10.field_0 = *((__int16*)v1 + 22) + 216;
        v10.field_4 = *((__int16*)v1 + 23) + 27;
        *(_DWORD*)& byte_5D4594[814624] = v1;
        sub_439370(&v10, (int)v1);
        sub_430B10_set_mouse_pos(v10.field_0, v10.field_4);
        return;
    }
    sub_43A920();
    v3 = sub_4A0330(v1);
    nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16403, v3, 0);
    nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16412, v3, 0);
    v4 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[815016] + 32);
    v10.field_0 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[815016] + 16) + 216;
    v5 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[815016] + 20);
    v6 = 131 * *(_DWORD*)(v4 + 48);
    v7 = *(_DWORD*)(v4 + 24);
    v8 = *(__int16*)(v4 + 54);
    v9 = *(_DWORD*)(v7 + 4 * v6);
    *(_DWORD*)& byte_5D4594[814624] = v1;
    v10.field_4 = v9 - v8 + v5 + 27;
    sub_439370(&v10, (int)v1);
    sub_430B10_set_mouse_pos(v10.field_0, v10.field_4);
}

//----- (0043B0E0) --------------------------------------------------------
void __cdecl sub_43B0E0(int a1)
{
    int i; // ebx
    int* v2; // eax
    int v3; // esi
    int v4; // eax
    int v5; // edi
    int v6; // ebp

    for (i = a1; i; i = *(_DWORD*)(i + 48))
    {
        v2 = sub_4A04F0((char*)(i + 52));
        v3 = (int)v2;
        if (v2)
        {
            if (v2[24] == 9999)
            {
                v4 = *(_DWORD*)(i + 40);
                if (v4 >= 0)
                {
                    *(_DWORD*)(v3 + 96) = v4;
                    v5 = sub_4A0330((int*)v3);
                    if (*(_DWORD*)& byte_587000[87408] == 1)
                    {
                        if (sub_4899C0(v3))
                        {
                            nox_swprintf((wchar_t*)& byte_5D4594[814756], L"%d", *(_DWORD*)(v3 + 96));
                            nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16407, (int)& byte_5D4594[814756], v5);
                            if (sub_4A0560() == 6 || sub_4A0560() == 7)
                            {
                                sub_425920((_DWORD * *)v3);
                                v6 = sub_4A0030((const void*)v3);
                                nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16398, v5, 0);
                                sub_43B2A0(v6);
                                sub_43B7C0(v3);
                            }
                        }
                        else
                        {
                            nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16398, v5, 0);
                            sub_4A0540((LPVOID)v3);
                        }
                    }
                    else if (sub_4899C0(v3))
                    {
                        if (*(_BYTE*)(v3 + 120))
                        {
                            strncpy((char*)& byte_5D4594[814920], (const char*)(v3 + 120), 0xFu);
                            byte_5D4594[814935] = 0;
                        }
                        else
                        {
                            sub_43BC80(v3 + 12, *(_WORD*)(v3 + 109), (char*)& byte_5D4594[814920]);
                        }
                        if (*(_DWORD*)(v3 + 96) == 9999)
                            nox_swprintf((wchar_t*)& byte_5D4594[814628], L"%S -- ms", &byte_5D4594[814920]);
                        else
                            nox_swprintf(
                                    (wchar_t*)& byte_5D4594[814628],
                                    L"%S %dms",
                                    &byte_5D4594[814920],
                                    *(_DWORD*)(v3 + 96));
                        sub_46B000((wchar_t*)(*(_DWORD*)(v3 + 28) + 36), (wchar_t*)& byte_5D4594[814628]);
                        sub_437320(v3);
                    }
                    else
                    {
                        sub_4A0540((LPVOID)v3);
                    }
                }
            }
        }
    }
}

//----- (0043B2A0) --------------------------------------------------------
int __cdecl sub_43B2A0(int a1)
{
    int result; // eax

    result = a1;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815012] + 32) + 46) = a1;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815016] + 32) + 46) = a1;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815020] + 32) + 46) = a1;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815024] + 32) + 46) = a1;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815028] + 32) + 46) = a1;
    *(_WORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[815032] + 32) + 46) = a1;
    return result;
}

//----- (0043B300) --------------------------------------------------------
unsigned int sub_43B300()
{
    unsigned int result; // eax

    if (*(_DWORD*)& byte_5D4594[815056])
        result = inet_addr((const char*)(*(_DWORD*)& byte_5D4594[814624] + 12));
    else
        result = 0;
    return result;
}

//----- (0043B320) --------------------------------------------------------
int sub_43B320()
{
    return *(_DWORD*)& byte_5D4594[815056] != 0 ? *(_DWORD*)& byte_5D4594[814604] : 0;
}

//----- (0043B340) --------------------------------------------------------
int sub_43B340()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[815056])
        result = *(unsigned __int16*)(*(_DWORD*)& byte_5D4594[814624] + 163);
    else
    result = 0;
    return result;
}

//----- (0043B360) --------------------------------------------------------
int sub_43B360()
{
    char* v0; // ebx
    unsigned __int16 v1; // ax
    char v2; // al
    char v5[32]; // [esp+0h] [ebp-20h]

    sub_40A4D0(4);
    sub_40A540(1);
    v0 = (char*)(*(_DWORD*)& byte_5D4594[814624] + 12);
    if (!memcmp((const void*)(*(_DWORD*)& byte_5D4594[814624] + 12), &byte_5D4594[815116], 1u))
    {
        sub_435720((char*)& byte_587000[90828]);
    }
    else
    {
        v1 = sub_43B320();
        nox_sprintf(v5, "%s:%d", v0, v1);
        sub_431790(v5);
        sub_435720(v0);
    }
    sub_433290((char*)& byte_587000[90848]);
    v2 = *(_BYTE*)(*(_DWORD*)& byte_5D4594[814624] + 102);
    nox_video_mode* v3;
    if (v2 < 0 && (v3 = sub_43BE80_video_mode_by_id(v2 & 0x7F)) != 0)
        sub_430C30_set_video_max(v3->width, v3->height);
    else
        sub_430C30_set_video_max(max_win_width, max_win_height);
    sub_44A400();
    sub_43A9D0();
    sub_4A24A0();
    return 1;
}

//----- (0043B440) --------------------------------------------------------
int sub_43B440()
{
    if (*(_DWORD*)& byte_587000[87404] == 1)
        sub_554B40(0);
    sub_438A90();
    return 1;
}

//----- (0043B460) --------------------------------------------------------
int sub_43B460()
{
    sub_438370();
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[815040] + 56) = sub_43B490;
    sub_46C6E0(*(int*)& byte_5D4594[815000]);
    return sub_46ABB0(*(int*)& byte_5D4594[814984], 0);
}

//----- (0043B490) --------------------------------------------------------
int sub_43B490()
{
    if (sub_43BE10() == 1700)
        return sub_438330();
    nox_window_set_hidden(*(int*)& byte_5D4594[814980], 1);
    nox_window_set_hidden(*(int*)& byte_5D4594[815000], 1);
    sub_477610(0);
    return 1;
}

//----- (0043B4D0) --------------------------------------------------------
_DWORD* sub_43B4D0()
{
    if (*(_DWORD*)& byte_5D4594[815048])
    {
        sub_43B510();
        sub_43A9D0();
        sub_4A24A0();
        sub_501AC0(0);
    }
    else
    {
        sub_43B630();
        sub_43B440();
    }
    return sub_49FF20();
}

//----- (0043B510) --------------------------------------------------------
char* sub_43B510()
{
    __int16 v0; // ax
    char* result; // eax
    char* v2; // edi
    unsigned __int8 v3; // cl
    bool v4; // zf
    __int16 v5; // cx
    int v6; // [esp+0h] [ebp-54h]
    char v7[80]; // [esp+4h] [ebp-50h]

    *(_DWORD*)& byte_5D4594[815132] = 0;
    sub_40A4D0(5);
    sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    v6 = *(_DWORD*)& byte_5D4594[814916];
    if (*(_DWORD*)& byte_587000[87404] == 1)
    {
        v0 = *(_WORD*)& byte_5D4594[814916] - *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87528];
        HIWORD(v6) -= *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87530];
        LOWORD(v6) = v0;
    }
    strcpy(v7, sub_49FF40((__int16*)& v6));
    result = strchr(v7, 46);
    if (!result)
    {
        sub_409B50(v7);
        v2 = &v7[strlen(v7) + 1];
        v3 = byte_587000[90860];
        *(_DWORD*)--v2 = *(_DWORD*)& byte_587000[90856];
        v4 = (*(_DWORD*)& byte_5D4594[2650636] & 0x600000) == 0;
        v2[4] = v3;
        if (v4)
            sub_409D70(v7);
        sub_40A540(55280);
        sub_40A4D0(128);
        result = sub_4165D0(0);
        v5 = *((_WORD*)result + 26) & 0x280F;
        LOBYTE(v5) = result[52] & 0xF | 0x80;
        *((_WORD*)result + 26) = v5;
    }
    return result;
}
// 43B510: using guessed type char var_50[80];

//----- (0043B630) --------------------------------------------------------
_DWORD* sub_43B630()
{
    wchar_t* v0; // eax

    sub_46C6E0(*(int*)& byte_5D4594[815000]);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[90904], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 1284);
    return sub_449A10(*(int*)& byte_5D4594[814980], 0, (int)v0, 34, 0, 0);
}

//----- (0043B670) --------------------------------------------------------
_DWORD* sub_43B670()
{
    char* v0; // esi

    v0 = sub_416640();
    if (*(_DWORD*)& byte_5D4594[815048])
    {
        sub_44A400();
        sub_43B510();
        sub_43A9D0();
        sub_4A24A0();
        sub_501AC0(*(_DWORD*)(v0 + 74));
    }
    else
    {
        sub_43B630();
        sub_40D350(*(_DWORD*)(*(_DWORD*)& byte_5D4594[814624] + 32));
    }
    return sub_49FF20();
}

//----- (0043B6D0) --------------------------------------------------------
int sub_43B6D0()
{
    return *(_DWORD*)& byte_5D4594[815044];
}

//----- (0043B6E0) --------------------------------------------------------
void sub_43B6E0()
{
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]
    if (*(_DWORD*)& byte_5D4594[814980])
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[90960], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[91008], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3331);
        sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
        sub_44A360(1);
        *(_DWORD*)& byte_5D4594[815096] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[815096] = 1;
    }
}

//----- (0043B750) --------------------------------------------------------
void sub_43B750()
{
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]

    if (*(_DWORD*)& byte_5D4594[814980])
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[91064], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[91112], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3351);
        sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
        sub_44A360(1);
        *(_DWORD*)& byte_5D4594[815100] = 0;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[815100] = 1;
    }
}

//----- (0043B7C0) --------------------------------------------------------
_DWORD* __cdecl sub_43B7C0(int a1)
{
    int v1; // eax
    __int16 v2; // cx
    _DWORD* v3; // eax
    int v4; // eax
    _DWORD* result; // eax
    wchar_t* v6; // eax
    int v7; // eax
    char v8; // al
    wchar_t* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // [esp-14h] [ebp-208h]
    WCHAR WideCharStr[64]; // [esp+8h] [ebp-1ECh]
    char v13[32]; // [esp+88h] [ebp-16Ch]
    char v14[332]; // [esp+A8h] [ebp-14Ch]

    if (*(_DWORD*)& byte_587000[87408])
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[815012], 16397, (int)& byte_587000[91164], 4);
        strncpy(v14, (const char*)(a1 + 120), 0xFu);
        v14[15] = 0;
        if (!memcmp(v14, &byte_5D4594[815120], 1u))
            sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v14);
        nox_swprintf(WideCharStr, L"%S", v14);
        sub_43BC10(WideCharStr, 0x64u);
        nox_window_call_field_94(*(int*)& byte_5D4594[815016], 16397, (int)WideCharStr, 4);
        nox_swprintf(
                WideCharStr,
                L"%d/%d",
                *(unsigned __int8*)(a1 + 103),
                *(unsigned __int8*)(a1 + 104));
        nox_window_call_field_94(*(int*)& byte_5D4594[815020], 16397, (int)WideCharStr, 4);
        v6 = sub_43BCB0(*(_WORD*)(a1 + 163));
        if (*(_BYTE*)(a1 + 164) & 0x10)
        {
            nox_swprintf(
                    (wchar_t*)& byte_5D4594[814772],
                    L"%s %d",
                    v6,
                    *(unsigned __int16*)(a1 + 165));
            nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16397, (int)& byte_5D4594[814772], 4);
        }
        else
        {
            nox_window_call_field_94(*(int*)& byte_5D4594[815024], 16397, (int)v6, 4);
        }
        v7 = *(_DWORD*)(a1 + 96);
        if (v7 == 9999)
            nox_swprintf(WideCharStr, L"--");
        else
            _itow(v7, WideCharStr, 10);
        nox_window_call_field_94(*(int*)& byte_5D4594[815028], 16397, (int)WideCharStr, 4);
        v8 = *(_BYTE*)(a1 + 100);
        WideCharStr[0] = 0;
        if (v8 & 0x20)
        {
            v9 = loadString_sub_40F1D0((char*)& byte_587000[91248], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3486);
            nox_wcscat(WideCharStr, v9);
        }
        if (*(_BYTE*)(a1 + 100) & 0x10)
        {
            if (WideCharStr[0])
                nox_wcscat(WideCharStr, L"+");
            v10 = loadString_sub_40F1D0((char*)& byte_587000[91316], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3494);
            nox_wcscat(WideCharStr, v10);
        }
        if (!WideCharStr[0])
        {
            if (*(_BYTE*)(a1 + 103) < *(_BYTE*)(a1 + 104))
                v11 = loadString_sub_40F1D0((char*)& byte_587000[91424], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3505);
            else
                v11 = loadString_sub_40F1D0((char*)& byte_587000[91376], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3501);
            nox_wcscat(WideCharStr, v11);
        }
        result = (_DWORD*)nox_window_call_field_94(*(int*)& byte_5D4594[815032], 16397, (int)WideCharStr, 4);
    }
    else
    {
        memset(v14, 0, sizeof(v14));
        *(_DWORD*)& v14[8] = 257;
        *(_DWORD*)& v14[16] = *(_DWORD*)& byte_5D4594[814980];
        if (*(int*)& byte_587000[87412] == -1)
        {
            v1 = sub_437860(*(__int16*)(a1 + 44), *(__int16*)(a1 + 46));
            v2 = *(_WORD*)& byte_587000[8 * v1 + 87528];
            v1 += 10054;
            *(_WORD*)(a1 + 44) -= v2;
            *(_WORD*)(a1 + 46) -= *(_WORD*)& byte_587000[8 * v1 + 7098];
            *(_WORD*)(a1 + 44) >>= 1;
            *(_WORD*)(a1 + 46) >>= 1;
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[814988], v1);
            v4 = sub_4A91A0((int)v3, 1185, *(__int16*)(a1 + 44) - 5, *(__int16*)(a1 + 46) - 5, 10, 10, v14);
        }
        else
        {
            *(_WORD*)(a1 + 44) -= *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87528];
            *(_WORD*)(a1 + 46) -= *(_WORD*)& byte_587000[8 * *(_DWORD*)& byte_587000[87412] + 87530];
            v4 = sub_4A91A0(
                    *(int*)& byte_5D4594[814984],
                    1192,
                    *(__int16*)(a1 + 44) - 10,
                    *(__int16*)(a1 + 46) - 10,
                    20,
                    20,
                    v14);
        }
        *(_DWORD*)(a1 + 28) = v4;
        sub_437320(a1);
        if (*(_BYTE*)(a1 + 120))
        {
            strncpy(v13, (const char*)(a1 + 120), 0xFu);
            v13[15] = 0;
        }
        else
        {
            sub_43BC80(a1 + 12, *(_WORD*)(a1 + 109), v13);
        }
        if (*(_DWORD*)(a1 + 96) == 9999)
            nox_swprintf(WideCharStr, L"%S -- ms", v13);
        else
            nox_swprintf(WideCharStr, L"%S %dms", v13, *(_DWORD*)(a1 + 96));
        sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 28) + 36), WideCharStr);
        sub_46B2C0(*(_DWORD*)(a1 + 28), sub_439E70);
        result = *(_DWORD * *)(a1 + 28);
        *result = *(_DWORD*)(a1 + 36) + 10070;
    }
    return result;
}

//----- (0043BC10) --------------------------------------------------------
unsigned __int16* __cdecl sub_43BC10(wchar_t* a1, unsigned __int8 a2)
{
unsigned __int16* v2; // esi
size_t v3; // edi
int v4; // ebx
unsigned __int16* v5; // edi

v2 = a1;
v3 = nox_wcslen(a1);
sub_43F840(0, v2, (int*)& a1, 0, 0);
v4 = a2;
if ((int)(a1 + 5) > a2)
{
v5 = &v2[v3];
do
{
*v5 = 0;
--v5;
sub_43F840(0, v2, (int*)& a1, 0, 0);
} while ((int)(a1 + 5) > v4);
}
return v2;
}

//----- (0043BC80) --------------------------------------------------------
int __cdecl sub_43BC80(int a1, unsigned __int16 a2, char* a3)
{
    return nox_sprintf(a3, "%s:%d", a1, a2);
}

//----- (0043BCB0) --------------------------------------------------------
wchar_t* __cdecl sub_43BCB0(__int16 a1)
{
    if (a1 & 0x1000)
        return loadString_sub_40F1D0((char*)& byte_587000[91480], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3534);
    if (a1 & 0x20)
        return loadString_sub_40F1D0((char*)& byte_587000[91528], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3541);
    if (a1 & 0x400)
        return loadString_sub_40F1D0((char*)& byte_587000[91572], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3545);
    if (a1 & 0x10)
        return loadString_sub_40F1D0((char*)& byte_587000[91624], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3550);
    if (a1 & 0x40)
        return loadString_sub_40F1D0((char*)& byte_587000[91672], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3555);
    if ((a1 & 0x80u) == 0)
        return loadString_sub_40F1D0((char*)& byte_587000[91772], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3563);
    return loadString_sub_40F1D0((char*)& byte_587000[91724], 0, "C:\\NoxPost\\src\\client\\shell\\noxworld.c", 3559);
}

//----- (0043BD90) --------------------------------------------------------
int __cdecl sub_43BD90(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[815092] |= a1;
    return result;
}

//----- (0043BDB0) --------------------------------------------------------
int sub_43BDB0()
{
    return *(_DWORD*)& byte_5D4594[815092];
}

//----- (0043BDC0) --------------------------------------------------------
void sub_43BDC0()
{
    --byte_5D4594[815208];
}

//----- (0043BDD0) --------------------------------------------------------
int __cdecl sub_43BDD0(int a1)
{
    int result; // eax

    result = a1;
    if (*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] != a1)
    {
        ++byte_5D4594[815208];
        *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] = a1;
    }
    return result;
}

//----- (0043BE10) --------------------------------------------------------
int sub_43BE10()
{
    return *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140];
}

//----- (0043BE30) --------------------------------------------------------
int sub_43BE30()
{
    return *(_DWORD*)& byte_5D4594[815204];
}

//----- (0043BE40) --------------------------------------------------------
int __cdecl sub_43BE40(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[815204] = a1;
    return result;
}

//----- (0043BE50) --------------------------------------------------------
int sub_43BE50_get_video_mode_id()
{
    for (int i = 0; i < nox_video_modes_cnt; i++)
    {
        nox_video_mode* m = &nox_video_modes[i];
        if (m->width == nox_win_width_1)
            return m->id;
    }
    return nox_video_modes_cnt;
}

//----- (0043BE80) --------------------------------------------------------
nox_video_mode* __cdecl sub_43BE80_video_mode_by_id(int a1)
{
    for (int i = 0; i < nox_video_modes_cnt; i++)
    {
        nox_video_mode* m = &nox_video_modes[i];
        if (m->id == a1)
            return m;
    }
    return 0;
}

//----- (0043BEB0) --------------------------------------------------------
void __cdecl sub_43BEB0_get_video_mode(int* w, int* h, int* d)
{
    if (w)
        * w = nox_win_width_1;
    if (h)
        * h = nox_win_height_1;
    if (d)
        * d = nox_win_depth_1;
}

//----- (0043BEF0) --------------------------------------------------------
void __cdecl sub_43BEF0_set_video_mode(int w, int h, int d)
{
    d = 16; // 8 bit not supported
    nox_win_width_1 = w;
    nox_win_height_1 = h;
    nox_win_depth_1 = d;

    change_windowed_fullscreen();
}

//----- (0043BF10) --------------------------------------------------------
int __cdecl sub_43BF10(int a1)
{
    int v1; // esi
    int v2; // edi
    int v3; // ebx
    int result; // eax

    if (a1 == 1)
    {
        v1 = nox_win_width_2;
        v2 = nox_win_height_2;
        v3 = nox_win_depth_2;
    }
    else
    {
        v1 = nox_win_width_1;
        v2 = nox_win_height_1;
        v3 = nox_win_depth_1;
    }
    sub_430BE0(v1, v2, v3);
    *(_DWORD*)& byte_5D4594[805872] = 0;
    if (v1 == nox_backbuffer_width && v2 == nox_backbuffer_height && v3 == nox_backbuffer_depth)
    {
        return 1;
    }
    sub_48BE50(1);
    if (v3 == nox_backbuffer_depth || (result = sub_42F370(*(int*)& byte_5D4594[3804680])) != 0)
    {
        result = sub_430BA0();
        if (result)
        {
            sub_4A96C0("default.pal");
            sub_461520();
            sub_430A70_set_mouse_bounds(0, v1 - 1, 0, v2 - 1);
            sub_48BE50(0);
            return 1;
        }
    }
    return result;
}

//----- (0043BFE0) --------------------------------------------------------
int sub_43BFE0()
{
    int result; // eax

    sub_43DDF0(sub_43C020);
    nox_set_draw_unk1(0);
    if (*(_DWORD*)& byte_587000[91840])
    {
        *(_DWORD*)& byte_587000[91840] = 0;
        LABEL_3:
        result = 1;
        *(_DWORD*)& byte_5D4594[815132] = 1;
        return result;
    }
    result = sub_43C0A0();
    if (result)
        goto LABEL_3;
    return result;
}

//----- (0043C020) --------------------------------------------------------
int sub_43C020()
{
    ++* (_DWORD*)& byte_5D4594[2598000];
    if (*(_DWORD*)& byte_5D4594[815132])
        return 1;
    sub_434350(*(int*)& byte_5D4594[2650656]);
    sub_440900();
    return 0;
}

//----- (0043C060) --------------------------------------------------------
BOOL sub_43C060()
{
    sub_4A96C0((char*)& byte_587000[91856]);
    sub_4AA1F0();
    sub_4A2210();
    sub_477610(0);
    sub_48B3E0(1);
    sub_44E040();
    sub_43E8C0(0);
    return sub_4A9C80() != 0;
}

//----- (0043C0A0) --------------------------------------------------------
int sub_43C0A0()
{
    unsigned int v0; // eax
    int result; // eax
    int v2; // eax

    if (!byte_5D4594[815208])
        return 1;
    v0 = *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140];
    if (v0 > 0x258)
    {
        if (v0 > 0x76C)
        {
            if (v0 != 1915)
            {
                if (v0 != 10000)
                    return 1;
                if (sub_43AF70() == 1 && !sub_40E0B0())
                {
                    sub_41E300(9);
                    sub_41F4B0();
                    sub_41EC30();
                    sub_446490(0);
                    sub_44B000();
                    sub_44A400();
                    return 1;
                }
            }
            result = sub_4379F0();
            if (!result)
                return result;
            return 1;
        }
        if (v0 == 1900)
        {
            result = sub_447620();
            if (!result)
                return result;
            return 1;
        }
        if (v0 == 700)
        {
            result = sub_4A5D00();
            if (!result)
                return result;
            return 1;
        }
        if (v0 != 1700)
            return 1;
        result = sub_44A560();
        if (result)
            return 1;
    }
    else
    {
        if (v0 == 600)
        {
            result = sub_4A4840();
            if (!result)
                return result;
            return 1;
        }
        if (v0 <= 0x12C)
        {
            switch (v0)
            {
                case 0x12Cu:
                    result = sub_4AA6B0();
                    if (!result)
                        return result;
                    break;
                case 0xAu:
                    result = sub_4AB1F0();
                    if (!result)
                        return result;
                    break;
                case 0x64u:
                    result = sub_4A1C00();
                    if (!result)
                        return result;
                    break;
            }
            return 1;
        }
        v2 = v0 - 400;
        if (!v2)
        {
            result = sub_4AA270();
            if (!result)
                return result;
            return 1;
        }
        if (v2 != 100)
            return 1;
        sub_4A7A70(1);
        result = sub_4A4DB0();
        if (result)
            return 1;
    }
    return result;
}

//----- (0043C1E0) --------------------------------------------------------
void sub_43C1E0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // esi

    if (byte_5D4594[815208])
    {
        v0 = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = v0;
        if (v0)
        {
            ((int (*)(void))v0[12])();
            v1[13] = sub_43C0A0;
            sub_43BDC0();
        }
    }
}

//----- (0043C220) --------------------------------------------------------
_DWORD* sub_43C220()
{
    _DWORD* result; // eax
    _DWORD* v1; // esi

    result = *(_DWORD * *)& byte_5D4594[815208];
    if (byte_5D4594[815208])
    {
        result = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = result;
        if (result)
        {
            result = (_DWORD*)((int (*)(void))result[12])();
            v1[13] = sub_4AA6B0;
        }
    }
    return result;
}

//----- (0043C260) --------------------------------------------------------
int sub_43C260()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[815208];
    if (byte_5D4594[815208])
    {
        result = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = result;
        if (result)
        {
            if (*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] == 1700)
            {
                result = sub_44A560();
            }
            else
            {
                result = (*(int (**)(void))(result + 48))();
                *(_DWORD*)(v1 + 52) = sub_44A560;
            }
        }
        for (; *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] != 1700; result = byte_5D4594[815208])
            sub_43BDC0();
    }
    return result;
}

//----- (0043C2F0) --------------------------------------------------------
int sub_43C2F0()
{
    int result; // eax
    int v1; // esi

    result = *(_DWORD*)& byte_5D4594[815208];
    if (byte_5D4594[815208])
    {
        result = sub_43C520(*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140]);
        v1 = result;
        if (result)
        {
            if (*(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] == 100)
            {
                result = sub_4A1C00();
            }
            else
            {
                result = (*(int (**)(void))(result + 48))();
                *(_DWORD*)(v1 + 52) = sub_4A1C00;
            }
        }
        for (; *(_DWORD*)& byte_5D4594[4 * byte_5D4594[815208] + 815140] != 100; result = byte_5D4594[815208])
            sub_43BDC0();
    }
    return result;
}

//----- (0043C380) --------------------------------------------------------
void sub_43C380()
{
    int v0; // esi
    int v1; // edi
    char v2; // bl
    int v3; // eax
    int v4; // ecx
    int v5; // edx
    int v6; // edx
    void (*v7)(void); // eax
    int v8; // eax
    int v9; // ecx
    int v10; // edx
    int v11; // edx
    int (*v12)(void); // eax
    int v13; // [esp+4h] [ebp-8h]
    int v14; // [esp+8h] [ebp-4h]

    v0 = *(_DWORD*)& byte_5D4594[815212];
    if (*(_DWORD*)& byte_5D4594[815212])
    {
        while (1)
        {
            v1 = *(_DWORD*)(v0 + 40);
            v2 = 0;
            if (*(_BYTE*)(v0 + 64) == 2)
            {
                sub_46AA20(*(_DWORD*)(v0 + 4), &v13, &v14);
                v8 = *(_DWORD*)(v0 + 24) + v13;
                v13 += *(_DWORD*)(v0 + 24);
                v9 = *(_DWORD*)(v0 + 28) + v14;
                v14 += *(_DWORD*)(v0 + 28);
                v10 = *(_DWORD*)(v0 + 8);
                if ((int) * (_DWORD*)(v0 + 24) >= 0)
                {
                    if (v8 >= v10) {
                        v8 = *(_DWORD*)(v0 + 8);
                        v2 = 1;
                        v13 = *(_DWORD*)(v0 + 8);
                    }
                }
                else if (v8 <= v10)
                {
                    v8 = *(_DWORD*)(v0 + 8);
                    v2 = 1;
                    v13 = *(_DWORD*)(v0 + 8);
                }
                v11 = *(_DWORD*)(v0 + 12);
                if ((int) * (_DWORD*)(v0 + 28) >= 0)
                {
                    if (v9 >= v11) {
                        v9 = *(_DWORD*)(v0 + 12);
                        ++v2;
                        v14 = *(_DWORD*)(v0 + 12);
                    }
                }
                else if (v9 <= v11)
                {
                    v9 = *(_DWORD*)(v0 + 12);
                    ++v2;
                    v14 = *(_DWORD*)(v0 + 12);
                }
                sub_46A9B0(*(_DWORD * *)(v0 + 4), v8, v9);
                if (v2 == 2)
                {
                    *(_BYTE*)(v0 + 64) = 1;
                    sub_43BE40(1);
                    v12 = *(int (**)(void))(v0 + 56);
                    if (v12)
                        v12();
                }
                goto LABEL_31;
            }
            if (*(_BYTE*)(v0 + 64) == 3)
                break;
            LABEL_31:
            v0 = v1;
            if (!v1)
                return;
        }
        sub_46AA20(*(_DWORD*)(v0 + 4), &v13, &v14);
        v3 = *(_DWORD*)(v0 + 32) + v13;
        v13 += *(_DWORD*)(v0 + 32);
        v4 = *(_DWORD*)(v0 + 36) + v14;
        v14 += *(_DWORD*)(v0 + 36);
        v5 = *(_DWORD*)(v0 + 16);
        if ((int) * (_DWORD*)(v0 + 32) >= 0)
        {
            if (v3 < v5)
                goto LABEL_9;
        }
        else if (v3 > v5)
        {
            goto LABEL_9;
        }
        v3 = *(_DWORD*)(v0 + 16);
        v2 = 1;
        v13 = *(_DWORD*)(v0 + 16);
        LABEL_9:
        v6 = *(_DWORD*)(v0 + 20);
        if ((int) * (_DWORD*)(v0 + 36) >= 0)
        {
            if (v4 < v6)
                goto LABEL_14;
        }
        else if (v4 > v6)
        {
            goto LABEL_14;
        }
        v4 = *(_DWORD*)(v0 + 20);
        ++v2;
        v14 = *(_DWORD*)(v0 + 20);
        LABEL_14:
        sub_46A9B0(*(_DWORD * *)(v0 + 4), v3, v4);
        if (v2 == 2)
        {
            *(_BYTE*)(v0 + 64) = 0;
            sub_43BE40(0);
            v7 = *(void (**)(void))(v0 + 60);
            if (v7)
                v7();
            sub_4A24F0();
        }
        goto LABEL_31;
    }
}

//----- (0043C500) --------------------------------------------------------
int sub_43C500()
{
    return *(_DWORD*)& byte_5D4594[815212];
}

//----- (0043C510) --------------------------------------------------------
int __cdecl sub_43C510(int a1)
{
    int result; // eax

    if (a1)
        result = *(_DWORD*)(a1 + 40);
    else
        result = 0;
    return result;
}

//----- (0043C520) --------------------------------------------------------
_DWORD* __cdecl sub_43C520(int a1)
{
    _DWORD* result; // eax

    result = *(_DWORD * *)& byte_5D4594[815212];
    if (!*(_DWORD*)& byte_5D4594[815212])
        return 0;
    while (*result != a1)
    {
        result = (_DWORD*)result[10];
        if (!result)
            return 0;
    }
    return result;
}

//----- (0043C540) --------------------------------------------------------
_DWORD* sub_43C540()
{
    _DWORD* result; // eax

    result = nox_calloc(1u, 0x44u);
    if (result)
    {
        result[10] = *(_DWORD*)& byte_5D4594[815212];
        if (*(_DWORD*)& byte_5D4594[815212])
            * (_DWORD*)(*(_DWORD*)& byte_5D4594[815212] + 44) = result;
        *(_DWORD*)& byte_5D4594[815212] = result;
    }
    return result;
}

//----- (0043C570) --------------------------------------------------------
void __cdecl sub_43C570(LPVOID lpMem)
{
    int v1; // ecx
    int v2; // ecx

    v1 = *((_DWORD*)lpMem + 10);
    if (v1)
        * (_DWORD*)(v1 + 44) = *((_DWORD*)lpMem + 11);
    v2 = *((_DWORD*)lpMem + 11);
    if (v2)
        * (_DWORD*)(v2 + 40) = *((_DWORD*)lpMem + 10);
    else
        *(_DWORD*)& byte_5D4594[815212] = *((_DWORD*)lpMem + 10);
    free(lpMem);
}

//----- (0043C5B0) --------------------------------------------------------
_DWORD* __cdecl sub_43C5B0(_DWORD* a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    _DWORD* v9; // esi

    v9 = sub_43C540();
    if (!v9)
        return 0;
    sub_46A9B0(a1, a4, a5);
    v9[4] = a2;
    v9[5] = a3;
    v9[8] = a6;
    v9[1] = a1;
    v9[2] = a4;
    v9[3] = a5;
    v9[9] = a7;
    v9[6] = a8;
    v9[7] = a9;
    *((_BYTE*)v9 + 64) = 3;
    sub_43BE40(3);
    sub_452D80(922, 100);
    v9[12] = 0;
    v9[14] = 0;
    v9[15] = 0;
    return v9;
}

//----- (0043C640) --------------------------------------------------------
void sub_43C640()
{
    nox_srand(0x2710u);
}

//----- (0043C650) --------------------------------------------------------
int sub_43C650()
{
    __int64 v0; // kr00_8
    unsigned int v1; // eax
    int v2; // ett
    int result; // eax

    v0 = sub_416BB0();
    v1 = *(_DWORD*)& byte_5D4594[815756];
    if (*(_QWORD*)& byte_5D4594[815740])
    {
        v2 = ((unsigned int)v0 < *(int*)& byte_5D4594[815740]) + *(_DWORD*)& byte_5D4594[815744];
        *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[815756] + 815220] = v0 - *(_DWORD*)& byte_5D4594[815740];
        *(_DWORD*)& byte_5D4594[8 * v1 + 815224] = HIDWORD(v0) - v2;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[815756] + 815220] = v0;
        *(_DWORD*)& byte_5D4594[8 * v1 + 815224] = HIDWORD(v0);
    }
    *(_QWORD*)& byte_5D4594[815756] = (__PAIR64__(*(unsigned int*)& byte_5D4594[815760], v1) + 1) % 0x3C;
    result = *(_DWORD*)& byte_5D4594[815748] + 1;
    *(_QWORD*)& byte_5D4594[815740] = v0;
    ++* (_DWORD*)& byte_5D4594[815748];
    return result;
}

//----- (0043C6E0) --------------------------------------------------------
BOOL sub_43C6E0()
{
    return !*(_DWORD*)& byte_5D4594[815704] && !*(_DWORD*)& byte_5D4594[815708];
}

//----- (0043C700) --------------------------------------------------------
int sub_43C700()
{
    return *(_DWORD*)& byte_5D4594[815764];
}

//----- (0043C710) --------------------------------------------------------
BOOL sub_43C710()
{
    return sub_40A5C0(0x10000000);
}

//----- (0043C720) --------------------------------------------------------
int __cdecl sub_43C720(int a1)
{
    int result; // eax
    bool v2; // zf

    result = a1;
    v2 = *(_DWORD*)& byte_5D4594[815764] == a1;
    *(_DWORD*)& byte_5D4594[815764] = a1;
    if (!v2 && !a1)
    {
        sub_4597E0(0);
        result = sub_4169D0(0);
    }
    return result;
}

//----- (0043C750) --------------------------------------------------------
int sub_43C750()
{
    return *(_DWORD*)& byte_5D4594[815700];
}

//----- (0043C760) --------------------------------------------------------
int sub_43C760()
{
    int v0; // esi

    if (!sub_40A5C0(1))
        return *(_DWORD*)& byte_5D4594[815712];
    v0 = sub_40E9F0(31, 1);
    return v0 + sub_40F0D0(31);
}

//----- (0043C790) --------------------------------------------------------
int sub_43C790()
{
    return *(_DWORD*)& byte_587000[91876];
}

//----- (0043C7A0) --------------------------------------------------------
int __cdecl sub_43C7A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_587000[91876] = a1;
    return result;
}

//----- (0043C7B0) --------------------------------------------------------
int __cdecl sub_43C7B0(char* cp, int hostshort, int a3, signed int* a4)
{
    int v4; // eax
    int v5; // eax
    char v7[40]; // [esp+8h] [ebp-28h]

    memset(v7, 0, sizeof(v7));
    *(_DWORD*)& byte_5D4594[815704] = 0;
    *(_DWORD*)& byte_5D4594[815708] = 0;
    *(_DWORD*)& v7[20] = 2048;
    *(_DWORD*)& v7[8] = hostshort;
    sub_5520B0(200, 1024);
    *(_DWORD*)& v7[36] = sub_43C860;
    v4 = sub_5546F0((size_t*)v7);
    *(_DWORD*)& byte_5D4594[815700] = v4;
    v5 = sub_554760(v4, cp, hostshort, a3, 153);
    OnLibraryNotice(258, 0);
    if (!sub_40A5C0(1))
        * (_DWORD*)& byte_5D4594[2649712] |= 0x80000000;
    return 1;
}

//----- (0043C860) --------------------------------------------------------
int __cdecl sub_43C860(int a1, unsigned __int8* a2, int a3)
{
unsigned __int8 v3; // cl
int v4; // ecx

v3 = *a2;
*(_DWORD*)& byte_5D4594[815712] = a3;
if (v3 < 0x27u)
{
v4 = *a2;
if (v4 == 33)
{
sub_446380();
}
else if (v4 == 36)
{
*(_DWORD*)& byte_5D4594[2614264] = *(_DWORD*)(a2 + 1);
}
}
else
{
sub_48EA70(31, (unsigned int)a2, a3);
if (sub_43C700())
sub_48D660();
}
*(_QWORD*)& byte_5D4594[815716] = sub_416BB0();
if (*(_DWORD*)& byte_5D4594[815704] == 1)
{
sub_4AB4A0(0);
*(_DWORD*)& byte_5D4594[815704] = 0;
}
if (*(_DWORD*)& byte_5D4594[815708] == 1)
sub_43CF40();
return 1;
}

//----- (0043C8F0) --------------------------------------------------------
int __cdecl sub_43C8F0(int a1, int a2, int a3)
{
    int v3; // ebx
    char* v4; // edi
    int result; // eax
    int v6; // eax
    char v7; // [esp+Fh] [ebp-Dh]
    int v8; // [esp+10h] [ebp-Ch]
    char v9[5]; // [esp+14h] [ebp-8h]

    v3 = sub_476F80();
    v4 = sub_42CD50(&v8);
    if (!(_BYTE)v8)
        return 1;
    v7 = 63;
    result = sub_40EBC0(a1, 0, &v7, 1);
    if (result)
    {
        result = sub_40EBC0(a1, 0, &v8, 1);
        if (result)
        {
            result = sub_40EBC0(a1, 0, v4, (unsigned __int8)v8);
            if (result)
            {
                v6 = v3 ? *(_DWORD*)(v3 + 16) : a3;
                if (a2 == *(unsigned __int16*)& byte_5D4594[815768] && v6 == *(unsigned __int16*)& byte_5D4594[815770])
                return 1;
                *(_WORD*)& byte_5D4594[815770] = v6;
                *(_WORD*)& v9[3] = v6;
                *(_WORD*)& byte_5D4594[815768] = a2;
                v9[0] = -84;
                *(_WORD*)& v9[1] = a2;
                result = sub_40EBC0(a1, 0, v9, 5);
                if (result)
                    return 1;
            }
        }
    }
    return result;
}

//----- (0043C9F0) --------------------------------------------------------
int sub_43C9F0()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -64;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 3);
    return 1;
}

//----- (0043CA20) --------------------------------------------------------
int sub_43CA20()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -66;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 2);
    return 1;
}

//----- (0043CA50) --------------------------------------------------------
int sub_43CA50()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -74;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 3);
    return 1;
}

//----- (0043CA80) --------------------------------------------------------
int sub_43CA80()
{
    char v1; // [esp+1h] [ebp-1h]

    v1 = -65;
    sub_552640(*(unsigned int*)& byte_5D4594[815700], &v1, 1, 3);
    return 1;
}

//----- (0043CAB0) --------------------------------------------------------
int sub_43CAB0()
{
    char v0; // al
    char v2; // [esp+1h] [ebp-1h]

    v2 = -73;
    v0 = sub_552640(*(unsigned int*)& byte_5D4594[815700], &v2, 1, 3);
    if (sub_5525B0(*(unsigned int*)& byte_5D4594[815700], v0, 20, 6))
        return 0;
    sub_40ED10(31, 0);
    return 1;
}

//----- (0043CB00) --------------------------------------------------------
int sub_43CB00()
{
    char v0; // al
    char v2; // [esp+1h] [ebp-1h]

    v2 = -83;
    v0 = sub_552640(*(unsigned int*)& byte_5D4594[815700], &v2, 1, 3);
    if (sub_5525B0(*(unsigned int*)& byte_5D4594[815700], v0, 20, 6))
        return 0;
    sub_40ED10(31, 0);
    return 1;
}

//----- (0043CB50) --------------------------------------------------------
int sub_43CB50()
{
    char v0; // al
    char v2; // [esp+1h] [ebp-1h]

    v2 = -82;
    v0 = sub_552640(*(unsigned int*)& byte_5D4594[815700], &v2, 1, 3);
    if (sub_5525B0(*(unsigned int*)& byte_5D4594[815700], v0, 20, 6))
        return 0;
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 3);
    sub_40ED10(31, 0);
    return 1;
}

//----- (0043CBB0) --------------------------------------------------------
int sub_43CBB0()
{
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
    if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[815724]) >= 0x7D0)
    {
        *(_QWORD*)& byte_5D4594[815724] = sub_416BB0();
        sub_552E70(*(unsigned int*)& byte_5D4594[815700]);
    }
    sub_552460();
    if (!*(_DWORD*)& byte_5D4594[815720] && !*(_DWORD*)& byte_5D4594[815716]
        || (unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[815716]) <= 0x4E20)
    {
        return 1;
    }
    sub_43B750();
    return 0;
}

//----- (0043CC60) --------------------------------------------------------
BOOL __cdecl sub_43CC60(int a1)
{
    BOOL result; // eax

    result = a1 == 0;
    *(_DWORD*)& byte_587000[91872] = a1 == 0;
    return result;
}

//----- (0043CC80) --------------------------------------------------------
int sub_43CC80()
{
    int result; // eax

    result = sub_5549F0(*(unsigned int*)& byte_5D4594[815700]);
    *(_DWORD*)& byte_5D4594[2649712] = 0;
    return result;
}

//----- (0043CCA0) --------------------------------------------------------
int sub_43CCA0()
{
    int v0; // esi
    int v1; // esi
    unsigned __int64 v2; // rdi
    unsigned __int64 v3; // rax
    unsigned __int64 v4; // rax
    unsigned __int64 v5; // rax
    char v7[8]; // [esp+8h] [ebp-8h]

    sub_49C4B0();
    v0 = *(_DWORD*)& byte_5D4594[2598000];
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
    if (v0 != *(_DWORD*)& byte_5D4594[2598000] && *(_DWORD*)& byte_5D4594[2650652] == 1 && !sub_40A5C0(1))
    {
        v1 = sub_40A710(1);
        if (sub_43C790() > v1)
        {
            sub_43CEB0();
            v2 = *(_QWORD*)& byte_5D4594[815740] + *(_QWORD*)& byte_587000[91880] / (unsigned __int64)sub_43C790();
            if (sub_416BB0() >= v2)
            {
                v7[0] = 40;
                *(_DWORD*)& v7[1] = *(_DWORD*)& byte_5D4594[2598000] + 1;
                sub_48EA70(31, (unsigned int)v7, 5);
            }
        }
    }
    v3 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815724];
    *(_DWORD*)& v7[4] = HIDWORD(v3);
    if (v3 >= 0x7D0)
    {
        *(_QWORD*)& byte_5D4594[815724] = sub_416BB0();
        sub_552E70(*(unsigned int*)& byte_5D4594[815700]);
    }
    if (!sub_40A5C0(1))
        sub_4E5770(0x1Fu, 0);
    sub_40EE10(*(unsigned int*)& byte_5D4594[815700], 31, 0);
    sub_40ED10(31, 0);
    sub_552460();
    if (*(_DWORD*)& byte_5D4594[815720] || (LODWORD(v4) = *(_DWORD*)& byte_5D4594[815716]) != 0)
    {
        v5 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815716];
        *(_DWORD*)& v7[4] = HIDWORD(v5);
        if (v5 > 0x7D0 && !*(_DWORD*)& byte_5D4594[815704])
        {
            *(_DWORD*)& byte_5D4594[815704] = 1;
            sub_4AB4A0(1);
            *(_QWORD*)& byte_5D4594[815732] = sub_416BB0();
        }
        if (*(_DWORD*)& byte_5D4594[815720] || (LODWORD(v4) = *(_DWORD*)& byte_5D4594[815716]) != 0)
        {
            v4 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815716];
            *(_DWORD*)& v7[4] = HIDWORD(v4);
            if (v4 > 0x4E20)
            {
                LODWORD(v4) = *(_DWORD*)& byte_5D4594[815708];
                if (!*(_DWORD*)& byte_5D4594[815708])
                {
                    v4 = sub_416BB0() - *(_QWORD*)& byte_5D4594[815732];
                    *(_DWORD*)& v7[4] = HIDWORD(v4);
                    if (v4 > 0x4E20)
                        LODWORD(v4) = sub_43CF70();
                }
            }
        }
    }
    return v4;
}

//----- (0043CEB0) --------------------------------------------------------
int sub_43CEB0()
{
    unsigned __int64 v0; // rax
    unsigned int v1; // esi
    unsigned int v2; // edi
    unsigned int v3; // ebx
    unsigned __int64 v4; // rax
    unsigned int v5; // ecx
    int v6; // kr00_4
    unsigned int v7; // kr08_4
    unsigned int v9; // [esp+0h] [ebp-8h]

    LODWORD(v0) = *(_DWORD*)& byte_5D4594[815748];
    if (*(int*)& byte_5D4594[815748] >= 60)
        LODWORD(v0) = 60;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    if ((_DWORD)v0 && (int)v0 > 10)
    {
        v0 = (int)v0;
        v5 = 0;
        v9 = v0;
        do
        {
            do
            {
                v6 = *(_DWORD*)& byte_5D4594[8 * v5 + 815220] + v2;
                v3 = (__PAIR64__(*(_DWORD*)& byte_5D4594[8 * v5 + 815224], *(_DWORD*)& byte_5D4594[8 * v5 + 815220])
                      + __PAIR64__(v3, v2)) >> 32;
                v2 += *(_DWORD*)& byte_5D4594[8 * v5 + 815220];
                v7 = v5 + 1;
                v1 = (__PAIR64__(v1, v5++) + 1) >> 32;
            } while (v1 < HIDWORD(v4));
            LODWORD(v4) = v9;
        } while (v1 <= HIDWORD(v4) && v7 < v9);
        v0 = __PAIR64__(v3, v6) / v4;
        *(_QWORD*)& byte_587000[91880] = v0;
    }
    else
    {
        *(_DWORD*)& byte_587000[91884] = 0;
        *(_DWORD*)& byte_587000[91880] = 33;
    }
    return v0;
}

//----- (0043CF40) --------------------------------------------------------
int sub_43CF40()
{
    *(_QWORD*)& byte_5D4594[815732] = sub_416BB0();
    *(_DWORD*)& byte_5D4594[815708] = 0;
    return sub_4AB4D0(0);
}

//----- (0043CF70) --------------------------------------------------------
int sub_43CF70()
{
    int result; // eax
    char v2; // [esp+1h] [ebp-1h]

    result = *(_DWORD*)& byte_5D4594[815708];
    if (!*(_DWORD*)& byte_5D4594[815708])
    {
        sub_4AB4D0(1);
        *(_DWORD*)& byte_5D4594[815708] = 1;
        result = *(_DWORD*)& byte_5D4594[2618908];
        if (*(_DWORD*)& byte_5D4594[2618908])
        {
            sub_4174F0(*(int*)& byte_5D4594[2618908], 64);
            v2 = 41;
            result = sub_4E53C0(31, &v2, 1, 0, 1);
        }
    }
    return result;
}
// 43CFA0: variable 'v1' is possibly undefined

//----- (0043CFD0) --------------------------------------------------------
BOOL sub_43CFD0()
{
    return sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1) != -1;
}

//----- (0043CFF0) --------------------------------------------------------
int sub_43CFF0()
{
    __int64 v0; // kr00_8

    v0 = sub_416BB0();
    sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
    sub_40EE10(*(unsigned int*)& byte_5D4594[815700], 31, 0);
    sub_40ED10(31, 0);
    sub_552460();
    if (sub_40A370())
        return 1;
    while ((unsigned __int64)(sub_416BB0() - v0) < 0x2710)
    {
        sub_552A80(*(unsigned int*)& byte_5D4594[815700], 1);
        sub_40EE10(*(unsigned int*)& byte_5D4594[815700], 31, 0);
        sub_40ED10(31, 0);
        sub_552460();
        if (sub_40A370())
            return 1;
    }
    return 0;
}

//----- (0043D0A0) --------------------------------------------------------
void __cdecl sub_43D0A0(int a1)
{
    wchar_t* v1; // esi
    wchar_t* v2; // eax

    v1 = loadString_sub_40F1D0((char*)& byte_587000[91932], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 702);
    switch (a1 + 23)
    {
        case 0:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92656], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 762);
            break;
        case 1:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92596], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 757);
            break;
        case 2:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92540], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 752);
            break;
        case 3:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92304], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 732);
            break;
        case 4:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92252], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 727);
            break;
        case 5:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92124], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 718);
            break;
        case 8:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92484], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 747);
            break;
        case 10:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92056], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 713);
            break;
        case 11:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[91992], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 708);
            break;
        case 17:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92192], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 722);
            break;
        case 19:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92424], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 742);
            break;
        case 20:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92364], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 737);
            break;
        default:
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92720], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 767);
            break;
    }
    sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
    sub_44A360(1);
}

//----- (0043D260) --------------------------------------------------------
void __cdecl sub_43D260(int a1, int a2)
{
    wchar_t* v2; // eax
    wchar_t v3[256]; // [esp+8h] [ebp-200h]

    if (a1)
    {
        if (a2)
        {
            v2 = loadString_sub_40F1D0((char*)& byte_587000[92784], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 784);
            nox_swprintf(v3, v2, a1, a2);
            sub_445490(v3);
        }
    }
}

//----- (0043D2C0) --------------------------------------------------------
void sub_43D2C0()
{
    nox_srand(0x2711u);
}

//----- (0043D2D0) --------------------------------------------------------
void sub_43D2D0()
{
    int v1; // esi

    if (*(_DWORD*)& byte_5D4594[816340])
    {
        if (*(_DWORD*)& byte_5D4594[816364])
        {
            sub_486520((unsigned int*)& byte_5D4594[816244]);
            sub_486520((unsigned int*)& byte_5D4594[816148]);
            v1 = *(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 4) >> 16;
            if (v1 == *(_DWORD*)& byte_587000[93168])
            {
                if ((unsigned __int64)(sub_416BB0() - *(_QWORD*)& byte_5D4594[816380]) > 0x32)
                {
                    **(_DWORD * *)& byte_587000[81128] &= 0xFFFFFFFD;
                    *(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 32) &= 0xFFFFFFFD;
                    *(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 64) &= 0xFFFFFFFD;
                }
            }
            else
            {
                *(_QWORD*)& byte_5D4594[816380] = sub_416BB0();
                *(_DWORD*)& byte_587000[93168] = v1;
            }
            if (*(_DWORD*)& byte_5D4594[816364])
            {
                if (**(_BYTE * *)& byte_587000[81128] & 2 || byte_5D4594[816148] & 2 || byte_5D4594[816244] & 2)
                    sub_43D3C0(*(int*)& byte_5D4594[816364], *(int*)& byte_5D4594[816096]);
            }
        }
    }
}

//----- (0043D3C0) --------------------------------------------------------
void __cdecl sub_43D3C0(int a1, int a2)
{
    unsigned int v2; // eax

    if (a1)
    {
        v2 = (*(_DWORD*)(*(_DWORD*)& byte_587000[81128] + 4) >> 16)
             * ((*(unsigned __int16*)& byte_5D4594[816154]
                                     * ((a2 * (unsigned int) * (unsigned __int16*)& byte_5D4594[816250]) >> 14)) >> 14);
        *(_DWORD*)& byte_5D4594[816148] &= 0xFFFFFFFD;
        *(_DWORD*)& byte_5D4594[816244] &= 0xFFFFFFFD;
        AIL_set_stream_volume(a1, (int)(127 * (v2 >> 14)) / 100);
    }
}
// 581430: using guessed type int __stdcall AIL_set_stream_volume(_DWORD, _DWORD);

//----- (0043D440) --------------------------------------------------------
int sub_43D440()
{
    int* v0; // esi
    int result; // eax

    v0 = (int*)& byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
    result = *(_DWORD*)& byte_5D4594[816340];
    if (*(_DWORD*)& byte_5D4594[816340])
    {
        result = *(_DWORD*)& byte_5D4594[816348];
        switch (*(_DWORD*)& byte_5D4594[816348])
        {
            case 0:
                if (*(_DWORD*)& byte_5D4594[816356] && (result = *(_DWORD*)& byte_587000[93156]) != 0)
                {
                    *(_DWORD*)& byte_5D4594[816348] = 3;
                }
                else
                {
                    result = *v0;
                    if (*v0)
                    {
                        result = *(_DWORD*)& byte_587000[93156];
                        if (*(_DWORD*)& byte_587000[93156])
                        {
                            sub_486320(&byte_5D4594[816148], 0x4000);
                            result = sub_43D6C0(v0);
                            if (result)
                            {
                                result = 1;
                                *(_DWORD*)& byte_5D4594[816348] = 1;
                                v0[4] = 1;
                            }
                            else
                            {
                                *v0 = 0;
                            }
                        }
                    }
                }
                break;
            case 1:
                if (*(_DWORD*)& byte_587000[93156]
                    && *v0 == *(_DWORD*)& byte_5D4594[816092]
                    && *(_DWORD*)& byte_5D4594[816364]
                    && AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]) != 2)
                {
                    result = *(_DWORD*)& byte_5D4594[816356];
                    if (*(_DWORD*)& byte_5D4594[816356])
                    {
                        *(_DWORD*)& byte_5D4594[816348] = 4;
                        result = sub_486350((int)& byte_5D4594[816148], 0);
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[816348] = 2;
                    result = sub_486350((int)& byte_5D4594[816148], 0);
                }
                break;
            case 2:
                if (!*(_DWORD*)& byte_5D4594[816364]) {
                    result = sub_43D650();
                    *(_DWORD*)& byte_5D4594[816348] = 0;
                } else {
                    result = AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]);
                    if (result == 2 || !(*(_DWORD*)& byte_5D4594[816152] & 0xFFFF0000)) {
                        result = sub_43D650();
                        *(_DWORD*)& byte_5D4594[816348] = 0;
                    }
                }
                break;
            case 3:
                if (!*(_DWORD*)& byte_5D4594[816356] || (result = *(_DWORD*)& byte_587000[93156]) == 0)
                {
                    if (!*(_DWORD*)& byte_587000[93156]
                        || *v0 != *(_DWORD*)& byte_5D4594[816092]
                        || !*(_DWORD*)& byte_5D4594[816364]
                        || AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]) == 2)
                    {
                        result = sub_43D650();
                        *(_DWORD*)& byte_5D4594[816348] = 0;
                    } else {
                        sub_486350((int)& byte_5D4594[816148], 0x4000);
                        result = sub_43D6A0();
                        *(_DWORD*)& byte_5D4594[816348] = 1;
                    }
                }
                break;
            case 4:
                if (*(_DWORD*)& byte_5D4594[816364]
                    && (result = AIL_stream_status(*(_DWORD*)& byte_5D4594[816364]), result != 2))
                {
                    if (!(*(_DWORD*)& byte_5D4594[816152] & 0xFFFF0000))
                    {
                        result = sub_43D680();
                        *(_DWORD*)& byte_5D4594[816348] = 3;
                    }
                }
                else
                {
                    result = sub_43D650();
                    *(_DWORD*)& byte_5D4594[816348] = 0;
                }
                break;
            default:
                return result;
        }
    }
    return result;
}
// 58141C: using guessed type int __stdcall AIL_stream_status(_DWORD);

//----- (0043D650) --------------------------------------------------------
int sub_43D650()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
    {
        *(_DWORD*)& byte_5D4594[816364] = 0;
        AIL_close_stream(result);
    }
    *(_DWORD*)& byte_5D4594[816092] = 0;
    return result;
}
// 581418: using guessed type int __stdcall AIL_close_stream(_DWORD);

//----- (0043D680) --------------------------------------------------------
int sub_43D680()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
        AIL_pause_stream(*(_DWORD*)& byte_5D4594[816364], 1);
    return result;
}
// 581414: using guessed type int __stdcall AIL_pause_stream(_DWORD, _DWORD);

//----- (0043D6A0) --------------------------------------------------------
int sub_43D6A0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
        AIL_pause_stream(*(_DWORD*)& byte_5D4594[816364], 0);
    return result;
}
// 581414: using guessed type int __stdcall AIL_pause_stream(_DWORD, _DWORD);

//----- (0043D6C0) --------------------------------------------------------
int __cdecl sub_43D6C0(int* a1)
{
    const char* v1; // edi
    unsigned __int8 v2; // dl
    char* v3; // edi
    int v4; // esi
    char* v5; // eax
    unsigned int v6; // kr08_4
    char v8[540]; // [esp+10h] [ebp-21Ch]

    v1 = *(const char**)& byte_587000[4 * *a1 + 92792];
    sub_43D650();
    *(_DWORD*)& byte_587000[93160] = 0;
    if (!*(_DWORD*)& byte_5D4594[816376])
        return 0;
    strcpy(v8, "music\\");
    strcat(v8, v1);
    if (!strchr(v8, 46))
    {
        v2 = byte_587000[93184];
        v3 = &v8[strlen(v8)];
        *(_DWORD*)v3 = *(_DWORD*)& byte_587000[93180];
        v3[4] = v2;
    }
    v4 = AIL_open_stream(*(_DWORD*)& byte_5D4594[816376], v8, 204800);
    if (!v4)
    {
        if (*(_DWORD*)& byte_587000[122856] && sub_44D930())
            return 0;
        v5 = sub_413890();
        if (!v5)
            return 0;
        *(_DWORD*)& byte_587000[93160] = 1;
        strncpy(&v8[40], v5, 0x1F4u);
        v8[539] = 0;
        v6 = strlen(&v8[40]) + 1;
        if (v6 != 1 && v8[v6 + 38] != 92)
            * (_WORD*)& v8[strlen(&v8[40]) + 40] = *(_WORD*)& byte_587000[93188];
        strcat(&v8[40], v8);
        v4 = AIL_open_stream(*(_DWORD*)& byte_5D4594[816376], &v8[40], 204800);
        if (!v4)
            return 0;
    }
    AIL_set_stream_position(v4, a1[2]);
    sub_486320(&byte_5D4594[816148], 0);
    sub_486350((int)& byte_5D4594[816148], 0x4000);
    sub_43D3C0(v4, a1[1]);
    AIL_start_stream(v4);
    *(_DWORD*)& byte_5D4594[816092] = *a1;
    *(_DWORD*)& byte_5D4594[816096] = a1[1];
    *(_DWORD*)& byte_5D4594[816100] = a1[2];
    *(_DWORD*)& byte_5D4594[816104] = a1[3];
    a1[2] = 0;
    *(_DWORD*)& byte_5D4594[816364] = v4;
    return 1;
}
// 581408: using guessed type int __stdcall AIL_open_stream(_DWORD, _DWORD, _DWORD);
// 58140C: using guessed type int __stdcall AIL_set_stream_position(_DWORD, _DWORD);
// 581410: using guessed type int __stdcall AIL_start_stream(_DWORD);

//----- (0043D8E0) --------------------------------------------------------
int sub_43D8E0()
{
    int result; // eax
    int v1; // eax

    if (*(_DWORD*)& byte_5D4594[816340])
        return 1;
    v1 = sub_43F130();
    *(_DWORD*)& byte_5D4594[816376] = v1;
    *(_DWORD*)& byte_587000[93156] = v1 != 0;
    sub_4864A0(&byte_5D4594[816148]);
    sub_486380(&byte_5D4594[816148], 0x3E8u, 0, 0x4000);
    *(_DWORD*)& byte_5D4594[816348] = 0;
    *(_DWORD*)& byte_5D4594[816092] = 0;
    *(_DWORD*)& byte_5D4594[816352] = 0;
    *(_DWORD*)& byte_5D4594[816108] = 0;
    *(_DWORD*)& byte_5D4594[816356] = 0;
    *(_DWORD*)& byte_5D4594[816372] = 0;
    *(_DWORD*)& byte_5D4594[816368] = 0;
    *(_DWORD*)& byte_5D4594[816364] = 0;
    result = 1;
    *(_DWORD*)& byte_5D4594[816340] = 1;
    return result;
}

//----- (0043D970) --------------------------------------------------------
int sub_43D970()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816340];
    if (*(_DWORD*)& byte_5D4594[816340])
    {
        result = sub_43DCC0();
        *(_DWORD*)& byte_5D4594[816340] = 0;
    }
    return result;
}

//----- (0043D990) --------------------------------------------------------
void sub_43D990()
{
    int4 v1; // [esp+0h] [ebp-10h]

    v1.field_0 = 0;
    sub_43D9E0(&v1);
}

//----- (0043D9B0) --------------------------------------------------------
void __cdecl sub_43D9B0(int a1, int a2)
{
    int4 v3; // [esp+0h] [ebp-10h]

    v3.field_0 = a1;
    v3.field_C = 0;
    v3.field_8 = 0;
    v3.field_4 = a2;
    sub_43D9E0(&v3);
}

//----- (0043D9E0) --------------------------------------------------------
void __cdecl sub_43D9E0(int4* a1)
{
    int4* v1; // edx
    int v2; // ecx

    v1 = (int4*)& byte_5D4594[20 * (*(_DWORD*)& byte_5D4594[816352] ^ 1) + 816108];
    v2 = a1->field_4;
    if (v2 <= 100)
    {
        if (v2 < 0)
            a1->field_4 = 0;
    }
    else
    {
        a1->field_4 = 100;
    }
    if (*(_DWORD*)& byte_5D4594[816344])
    {
        *(int4*)& byte_5D4594[816060] = *a1;
    }
    else
    {
        *v1 = *a1;
        v1[1].field_0 = 0;
        *(_DWORD*)& byte_5D4594[816352] ^= 1u;
    }
}

//----- (0043DA80) --------------------------------------------------------
int sub_43DA80()
{
    int result; // eax

    if (*(int*)& byte_5D4594[816368] < 6)
    {
        sub_43DD10((int*)& byte_5D4594[16 * (*(_DWORD*)& byte_5D4594[816368] + 6 * *(_DWORD*)& byte_5D4594[816372]) + 815772]);
        ++* (_DWORD*)& byte_5D4594[816368];
        result = 1;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816368] = 6;
        result = 0;
    }
    return result;
}

//----- (0043DAD0) --------------------------------------------------------
void sub_43DAD0()
{
    if (*(_DWORD*)& byte_5D4594[816368] > 0)
        sub_43D9E0((int4*)& byte_5D4594[16
                                        * (-- * (_DWORD*)& byte_5D4594[816368] + 6 * *(_DWORD*)& byte_5D4594[816372])
                                        + 815772]);
    *(_DWORD*)& byte_5D4594[816368] = 0;
}

//----- (0043DB10) --------------------------------------------------------
void sub_43DB10()
{
    sub_43D990();
    *(_DWORD*)& byte_5D4594[816368] = 0;
}

//----- (0043DB20) --------------------------------------------------------
int sub_43DB20()
{
    return *(_DWORD*)& byte_5D4594[816368];
}

//----- (0043DB30) --------------------------------------------------------
int __cdecl sub_43DB30(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[816368] = a1;
    return result;
}

//----- (0043DB40) --------------------------------------------------------
char* __cdecl sub_43DB40(int a1)
{
    return (char*)& byte_5D4594[16 * (a1 + 6 * *(_DWORD*)& byte_5D4594[816372]) + 815772];
}

//----- (0043DB60) --------------------------------------------------------
int sub_43DB60()
{
    int result; // eax
    int v1; // eax
    int v2; // ecx

    result = 3;
    if (*(int*)& byte_5D4594[816372] < 3)
    {
        sub_43DA80();
        v1 = *(_DWORD*)& byte_5D4594[816372];
        v2 = *(_DWORD*)& byte_5D4594[816368];
        *(_DWORD*)& byte_5D4594[816368] = 0;
        *(_DWORD*)& byte_5D4594[4 * *(_DWORD*)& byte_5D4594[816372] + 816076] = v2;
        result = v1 + 1;
        *(_DWORD*)& byte_5D4594[816372] = result;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816372] = 3;
    }
    return result;
}

//----- (0043DBA0) --------------------------------------------------------
void sub_43DBA0()
{
    int v1; // eax
    if (*(_DWORD*)& byte_5D4594[816372] > 0)
    {
        v1 = *(_DWORD*)& byte_5D4594[816372] - 1;
        *(_DWORD*)& byte_5D4594[816372] = v1;
        *(_DWORD*)& byte_5D4594[816368] = *(_DWORD*)& byte_5D4594[4 * v1 + 816076];
        sub_43DAD0();
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816372] = 0;
    }
}

//----- (0043DBD0) --------------------------------------------------------
int sub_43DBD0()
{
    ++* (_DWORD*)& byte_5D4594[816356];
    return sub_43D440();
}

//----- (0043DBE0) --------------------------------------------------------
int sub_43DBE0()
{
    if (-- * (int*)& byte_5D4594[816356] < 0)
        * (_DWORD*)& byte_5D4594[816356] = 0;
    return sub_43D440();
}

//----- (0043DC00) --------------------------------------------------------
void sub_43DC00()
{
    *(_DWORD*)& byte_587000[93156] = 0;
}

//----- (0043DC10) --------------------------------------------------------
int sub_43DC10()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816376];
    if (*(_DWORD*)& byte_5D4594[816376])
        * (_DWORD*)& byte_587000[93156] = 1;
    return result;
}

//----- (0043DC30) --------------------------------------------------------
int sub_43DC30()
{
    return *(_DWORD*)& byte_587000[93156];
}

//----- (0043DC40) --------------------------------------------------------
int sub_43DC40()
{
    int result; // eax

    if (!*(_DWORD*)& byte_5D4594[816340]
        || (result = 1, *(_DWORD*)& byte_5D4594[816348] != 1)
           && *(_DWORD*)& byte_5D4594[816348] != 4
           && *(_DWORD*)& byte_5D4594[816348] != 2)
    {
        result = 0;
    }
    return result;
}

//----- (0043DC80) --------------------------------------------------------
int sub_43DC80()
{
    unsigned __int8* v0; // eax

    if (*(_DWORD*)& byte_587000[93156] && *(_DWORD*)& byte_5D4594[816340])
    {
        while (1)
        {
            v0 = &byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
            if (*(_DWORD*)v0)
            {
                if (*((_DWORD*)v0 + 4))
                    break;
            }
            sub_4312C0();
        }
    }
    return 1;
}

//----- (0043DCC0) --------------------------------------------------------
int sub_43DCC0()
{
    int result; // eax

    result = *(_DWORD*)& byte_587000[93156];
    if (*(_DWORD*)& byte_587000[93156])
    {
        result = *(_DWORD*)& byte_5D4594[816340];
        if (*(_DWORD*)& byte_5D4594[816340])
        {
            sub_43D990();
            for (result = *(_DWORD*)& byte_5D4594[816348];
                 *(_DWORD*)& byte_5D4594[816348];
                 result = *(_DWORD*)& byte_5D4594[816348])
            {
                if (*(_DWORD*)& byte_5D4594[816348] == 3)
                {
                    sub_43D650();
                    *(_DWORD*)& byte_5D4594[816348] = 0;
                }
                sub_4312C0();
#ifdef __EMSCRIPTEN__
                nox_sleep(0x32u);
#endif // __EMSCRIPTEN__
            }
        }
    }
    return result;
}

//----- (0043DD10) --------------------------------------------------------
int __cdecl sub_43DD10(int* a1)
{
    unsigned __int8* v1; // ecx
    int result; // eax

    v1 = &byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
    *a1 = *(_DWORD*)& byte_5D4594[20 * *(_DWORD*)& byte_5D4594[816352] + 816108];
    a1[1] = *((_DWORD*)v1 + 1);
    a1[2] = *((_DWORD*)v1 + 2);
    a1[3] = *((_DWORD*)v1 + 3);
    result = *(_DWORD*)& byte_5D4594[816364];
    if (*(_DWORD*)& byte_5D4594[816364])
    {
        result = *a1;
        if (*(_DWORD*)& byte_5D4594[816092] == *a1)
        {
            result = AIL_stream_position(*(_DWORD*)& byte_5D4594[816364]);
            a1[2] = result;
        }
    }
    return result;
}
// 581404: using guessed type int __stdcall AIL_stream_position(_DWORD);

//----- (0043DD70) --------------------------------------------------------
void __cdecl sub_43DD70(int a1, int a2)
{
    sub_43DD10((int*)& byte_5D4594[816060]);
    sub_43D9B0(a1, a2);
    *(_DWORD*)& byte_5D4594[816344] = 1;
}

//----- (0043DDA0) --------------------------------------------------------
void sub_43DDA0()
{
    *(_DWORD*)& byte_5D4594[816344] = 0;
    sub_43D9E0((int4*)& byte_5D4594[816060]);
}

//----- (0043DDC0) --------------------------------------------------------
void sub_43DDC0()
{
    nox_srand(0x1E77u);
}

//----- (0043DDD0) --------------------------------------------------------
int __cdecl sub_43DDD0(int a1)
{
    *(_DWORD*)& byte_587000[93200] = a1;
    return a1;
}

//----- (0043DDE0) --------------------------------------------------------
int __cdecl sub_43DDE0(int a1)
{
    *(_DWORD*)& byte_587000[93192] = a1;
    return a1;
}

//----- (0043DDF0) --------------------------------------------------------
int __cdecl sub_43DDF0(int (*a1)(void))
{
    *(_DWORD*)& byte_5D4594[816388] = a1;
    if (!a1)
        * (_DWORD*)& byte_5D4594[816388] = sub_43DE10;
    return 1;
}

//----- (0043DE10) --------------------------------------------------------
int sub_43DE10()
{
    return 1;
}

//----- (0043DE20) --------------------------------------------------------
int __cdecl nox_set_draw_unk1(int (*fnc)(void))
{
    nox_draw_unk1 = fnc;
    if (!fnc)
        nox_draw_unk1 = sub_43DE10;
    return 1;
}

//----- (0043DE40) --------------------------------------------------------
int __cdecl sub_43DE40(int (*a1)(void))
{
    *(_DWORD*)& byte_5D4594[816392] = a1;
    if (!a1)
        * (_DWORD*)& byte_5D4594[816392] = sub_43DE10;
    return 1;
}

//----- (0043DE60) --------------------------------------------------------
int sub_43DE60()
{
    int result; // eax

    *(_DWORD*)& byte_587000[93196] = 0;
    sub_43C720(0);
    result = sub_43AF70();
    if (result == 1)
    {
        result = sub_40A5C0(0x2000000);
        if (!result)
            result = sub_40D380();
    }
    return result;
}

//----- (0043DEA0) --------------------------------------------------------
BOOL sub_43DEA0()
{
    return *(_DWORD*)& byte_587000[93196] == 0;
}

//----- (0043DEB0) --------------------------------------------------------
int sub_43DEB0()
{
    char* v0; // eax
    char* v1; // esi
    int v2; // eax
    char v3; // al
    char v4; // bl
    char* v5; // esi
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    wchar_t* v10; // eax
    wchar_t* v12; // [esp-10h] [ebp-118h]
    char* v13; // [esp-4h] [ebp-10Ch]
    char* v14; // [esp-4h] [ebp-10Ch]
    wchar_t v15[128]; // [esp+8h] [ebp-100h]

    if (!sub_40A5C0(0x800000))
        goto LABEL_16;
    sub_477610(10);
    if (sub_4DB250())
        v0 = sub_4DB260();
    else
        v0 = sub_409B30();
    v1 = v0;
    v2 = sub_409B00();
    v3 = sub_4CF470(v1, v2);
    v4 = v3;
    if (v3 & 2 && v3 & 4)
    {
        sub_43F140(500);
        v5 = sub_4AC2B0(v1);
        sub_43F1A0();
        if (!v5)
        {
            v13 = sub_409B30();
            v6 = loadString_sub_40F1D0((char*)& byte_587000[93352], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 318);
            sub_4516C0(v6, v13);
            sub_4356E0();
            return 0;
        }
        if (sub_40A5C0(1))
            sub_4DD180(31);
        else
            sub_43C9F0();
        sub_43C720(1);
        if ((int) * (_DWORD*)& byte_5D4594[3803228] < 0)
        {
            v7 = loadString_sub_40F1D0((char*)& byte_587000[93408], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 338);
            sub_445490(v7);
            v14 = sub_42E8E0(8, 1);
            v8 = loadString_sub_40F1D0((char*)& byte_587000[93468], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 339);
            nox_swprintf(v15, v8, v14);
            sub_445490(v15);
        }
    }
    else
    {
        if (!sub_40A5C0(1))
        {
            if (!(v4 & 1) || v4 & 4)
            {
                sub_40A4D0(0x100000);
            }
            else
            {
                sub_40A540(9437184);
                sub_477530(1);
                sub_43E1A0(1);
                v12 = loadString_sub_40F1D0((char*)& byte_587000[93244], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 298);
                v10 = loadString_sub_40F1D0((char*)& byte_587000[93304], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 297);
                sub_449A10(0, (int)v10, (int)v12, 24, sub_43E230, sub_43E200);
            }
            goto LABEL_16;
        }
        sub_4DD180(31);
    }
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
    {
        *(_DWORD*)& byte_5D4594[2650672] = 1;
        sub_44DA60(1);
    }
    LABEL_16:
    if (sub_40A5C0(0x100000))
    {
        map_download_start();
        return 0;
    }
    if (sub_40A5C0(9437184))
        sub_40A540(9437184);
    return 1;
}

int map_download_finish()
{
    int result; // eax
    wchar_t* v6; // eax
    char* v13; // [esp-4h] [ebp-10Ch]

    sub_4CC930();
    result = *(_DWORD*)& byte_587000[173332];
    if (*(_DWORD*)& byte_587000[173332])
    {
        int v3; // [esp+4h] [ebp-Ch]
        int v4; // [esp+8h] [ebp-8h]
        int v5; // [esp+Ch] [ebp-4h]
        sub_43BEB0_get_video_mode(&v3, &v5, &v4);
        if (!v3)
            sub_43BEF0_set_video_mode(default_win_width, default_win_height, v4);
        result = *(_DWORD*)& byte_587000[173332];
    }

    if (!result)
    {
        sub_40A540(9437184);
        return 0;
    }
    sub_43E1A0(0);
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
    {
        *(_DWORD*)& byte_5D4594[2650672] = 1;
        sub_44DA60(1);
    }
    if (!sub_4AC2B0(sub_409B30()))
    {
        v13 = sub_409B30();
        v6 = loadString_sub_40F1D0((char*)& byte_587000[93528], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 386);
        sub_4516C0(v6, v13);
        sub_4356E0();
        return 0;
    }
    if (sub_40A5C0(1))
        sub_4DD180(31);
    else
        sub_43C9F0();
    sub_43C720(1);

    if (sub_40A5C0(9437184))
        sub_40A540(9437184);
    return 1;
}
int map_download_loop(int first)
{
    unsigned __int8* v1; // eax

    sub_416C70(30);
    sub_4453A0_poll_events();
    sub_4308A0(1);
    sub_46B740();
    if (sub_43AF70() == 1)
    {
        sub_40D250();
        sub_40DF90();
    }
    v1 = (unsigned __int8*)sub_430940();
    for (*(_DWORD*)& byte_5D4594[2618912] = v1; *v1; *(_DWORD*)& byte_5D4594[2618912] = v1)
    {
        sub_46B6B0(v1);
        v1 = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618912] + 8);
    }
    sub_43CCA0();
    if (first)
        sub_43CA50();
    if (*(_DWORD*)& byte_5D4594[2598000] % 0x1Eu)
        sub_43CA20();

    if (!*(_DWORD*)& byte_587000[173328])
        return map_download_finish();

    mainloop_draw();
    sub_477830();
    sub_48A220();
    sub_4AD170_call_copy_backbuffer();
    sub_48A290_call_present();

    if (!*(_DWORD*)& byte_587000[173328])
        return map_download_finish();
    return -1;
}
void map_download_start()
{
    sub_467DF0(1);
    sub_4CC770();
    *(_DWORD*)& byte_587000[173328] = 1;
    *(_DWORD*)& byte_587000[173332] = 1;
    map_download_loop(1);
}

//----- (0043E1A0) --------------------------------------------------------
_DWORD* __cdecl sub_43E1A0(int a1)
{
    _DWORD* result; // eax

    if (a1)
    {
        result = nox_window_new(0, 552, 0, 0, nox_win_width, nox_win_height, 0);
        *(_DWORD*)& byte_5D4594[816412] = result;
        result[14] = *(_DWORD*)& byte_5D4594[2650656];
    }
    else
    {
        result = *(_DWORD * *)& byte_5D4594[816412];
        if (*(_DWORD*)& byte_5D4594[816412])
        {
            result = (_DWORD*)sub_46C4E0(*(_DWORD * *)& byte_5D4594[816412]);
            *(_DWORD*)& byte_5D4594[816412] = 0;
        }
    }
    return result;
}

//----- (0043E200) --------------------------------------------------------
int sub_43E200()
{
    sub_477530(0);
    sub_43E1A0(0);
    sub_43DDD0(0);
    sub_43DE60();
    return sub_44A400();
}

//----- (0043E230) --------------------------------------------------------
int sub_43E230()
{
    char* v0; // eax
    char* v2; // eax

    sub_477530(0);
    v0 = sub_409B90();
    if (_chmod(v0, 128) == -1)
        return sub_43E200();
    v2 = sub_409C70();
    if (_chmod(v2, 128) == -1)
        return sub_43E200();
    sub_40A4D0(0x100000);
    return sub_44A400();
}

//-------------------------------------------------------------------------
void mainloop_stop()
{
    if (*(_DWORD*)& byte_5D4594[805872])
    {
        *(_DWORD*)& byte_587000[93200] = 1;
        mainloop_exit();
        return;
    }

    // "exit the loop" ?
    if (*(_DWORD*)& byte_587000[93196])
    {
        return;
    }
    mainloop_exit();
}
//-------------------------------------------------------------------------
void mainloop_wait_and_exit(int flags)
{
    if (!(flags & 0x40000000))
    {
        while (!sub_416CD0()) {}
        mainloop_stop();
        return;
    }
    int ms = sub_416D00();
    *(_DWORD*)& byte_5D4594[816404] = ms;
    if (ms > 0)
        nox_sleep(ms);
    mainloop_stop();
}
//----- (0043E290) --------------------------------------------------------
void mainloop()
{
    unsigned __int8* v0; // eax
    int2* v1; // edi
    int v2; // ebp
    int v3; // ebx
    int v4; // esi
    int v5; // eax
    int v6; // eax
    int v7; // esi
    int v9; // edi
    int v10; // eax
    int v11; // ebx
    int v12; // esi
    int v13; // eax
    int v14; // kr00_4
    int v15; // esi
    char v16; // al
    int v21; // [esp-10h] [ebp-68h]
    char v22; // [esp-8h] [ebp-60h]
    char v23; // [esp-4h] [ebp-5Ch]
    char v24; // [esp-4h] [ebp-5Ch]
    int* v25; // [esp+4h] [ebp-54h]
    int v26; // [esp+18h] [ebp-40h]
    int2* v27; // [esp+20h] [ebp-38h]
    int v28[10]; // [esp+24h] [ebp-34h]

    if (mainloop_enter)
    {
        mainloop_enter(mainloop_enter_args);
        return;
    }

#ifdef __EMSCRIPTEN__
    DWORD cur_tick;
    static DWORD last_tick;

    // rate limit to < 40 fps
    cur_tick = nox_get_ticks();
    if (cur_tick - last_tick < 1000 / 40)
        return;
    last_tick = cur_tick;
#endif

    if (*(_DWORD*)& byte_587000[173328])
    {
        int ret = map_download_loop(0);
        if (ret == -1)
        {
            return;
        }
        else if (ret == 0)
        {
            // map error
            *(_DWORD*)& byte_587000[93196] = 0;
            *(_DWORD*)& byte_587000[93200] = 0;
            mainloop_exit();
            return;
        }
    }
    else
    {
        _control87(0x300u, 0x300u);
        if (!sub_43DEB0())
        {
            // XXX
            if (*(_DWORD*)& byte_587000[173328])
                return;
            *(_DWORD*)& byte_587000[93196] = 0;
            *(_DWORD*)& byte_587000[93200] = 0;
            mainloop_exit();
            return;
        }
    }
    if (sub_43AF70() == 1)
    {
        sub_40D250();
        sub_40DF90();
    }
    sub_416C70(30);
    sub_4453A0_poll_events();
    sub_413520();
    sub_435770();
    if (!(*(int (**)(void)) & byte_5D4594[816388])())
    {
        mainloop_exit();
        return;
    }
    sub_435780();
    sub_435740();
    sub_430880(1);
    sub_4308A0(1);
    sub_46B740();
    v0 = (unsigned __int8*)sub_430940();
    for (*(_DWORD*)& byte_5D4594[2618912] = v0; *v0; *(_DWORD*)& byte_5D4594[2618912] = v0)
    {
        sub_46B6B0(v0);
        v0 = (unsigned __int8*)(*(_DWORD*)& byte_5D4594[2618912] + 8);
    }
    if (!nox_draw_unk1())
    {
        mainloop_exit();
        return;
    }
    sub_430880(0);
    if (!(*(int (**)(void)) & byte_5D4594[816392])())
    {
        mainloop_exit();
        return;
    }
    sub_4519C0();
    sub_4312C0();
    sub_495430();
    if (sub_40A5C0(1) && *(_DWORD*)& byte_587000[93200] == 1)
    {
        if (*(_DWORD*)& byte_5D4594[815132])
            goto LABEL_24;
        if (sub_40A5C0(0x2000))
        {
            if (sub_40A680())
            {
                sub_4DEF00();
                sub_40A690();
            }
            else if (sub_459D60() && !sub_40A5C0(9437184))
            {
                if (sub_459DA0())
                    sub_4DF020();
                sub_459D50(0);
            }
            if (*(int*)& byte_5D4594[2598000] >= *(int*)& byte_5D4594[816400])
            {
                sub_4161E0();
                sub_416690();
                *(_DWORD*)& byte_5D4594[816400] = *(_DWORD*)& byte_5D4594[2598000] + 60 * *(_DWORD*)& byte_5D4594[2649704];
            }
        }
    }
    if (*(_DWORD*)& byte_5D4594[815132])
    {
        LABEL_24:
        sub_43C380();
        *(_DWORD*)& byte_5D4594[2650636] &= 0x7FFFFFFFu;
        if (!*(_DWORD*)& byte_5D4594[816408])
        {
            v1 = sub_4309F0();
            v27 = v1;
            v2 = v1->field_0 - *(_DWORD*)& byte_5D4594[816420];
            v3 = v1->field_4 - *(_DWORD*)& byte_5D4594[816424];
            v4 = v2 * v2 + v3 * v3;
            if (*(_DWORD*)& byte_5D4594[816428])
            {
                v5 = sub_419B10(sqrt((double)(v2 * v2 + v3 * v3))) / 4;
                if (v5 > 0)
                {
                    v26 = v5;
                    do
                    {
                        v6 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 570);
                        v7 = *(_DWORD*)& byte_5D4594[816420] + v2 * v6 / 100;
                        v9 = *(_DWORD*)& byte_5D4594[816424] + v3 * v6 / 100;
                        v23 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 582);
                        v22 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 581);
                        v21 = sub_415FF0(-7, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 579);
                        v10 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 578);
                        sub_431540(4, v7, v9, v10, v21, 1, v22, v23, 2, 1);
                        --v26;
                    } while (v26);
                    v4 = v2 * v2 + v3 * v3;
                    v1 = v27;
                }
                if (v4 < 10)
                    * (_DWORD*)& byte_5D4594[816428] = 0;
                *(_DWORD*)& byte_5D4594[816420] = v1->field_0;
                *(_DWORD*)& byte_5D4594[816424] = v1->field_4;
            }
            else if (v4 > 64)
            {
                *(_DWORD*)& byte_5D4594[816428] = 1;
            }
            if (v1[2].field_4 == 1)
            {
                sub_415FF0(0, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 608);
                if (!*(_DWORD*)& byte_5D4594[816416])
                {
                    *(_DWORD*)& byte_5D4594[816416] = 1;
                    sub_452D80(924, 100);
                    v11 = 75;
                    do
                    {
                        v12 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 620);
                        v13 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 621);
                        v14 = v13 * *(int*)& byte_587000[8 * v12 + 192088];
                        v15 = v13 * *(int*)& byte_587000[8 * v12 + 192092] / 16 - 6;
                        v24 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 633);
                        v16 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 632);
                        sub_431540(4, v14 / 16 + v27->field_0, v27->field_4 + v15, v14 / 16, v15, 1, v16, v24, 2, 1);
                        --v11;
                    } while (v11);
                }
            }
            else
            {
                *(_DWORD*)& byte_5D4594[816416] = 0;
            }
        }
    }
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x80000000))
    {
        sub_437180();
        if (!*(_DWORD*)& byte_5D4594[1556112])
            mainloop_draw();
        if (*(_DWORD*)& byte_5D4594[815132])
        {
            v28[0] = 0;
            v28[1] = 0;
            v28[2] = nox_win_width;
            v28[3] = nox_win_height;
            v28[8] = nox_win_width;
            v28[9] = nox_win_height;
            sub_431720(v28);
        }
        else
        {
            v25 = (int*)sub_437250();
            sub_431720(v25);
        }
        if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000) || byte_5D4594[2650637] & 1 || *(_DWORD*)& byte_5D4594[815132])
            sub_477830();
        sub_44D9F0(1);
        if (!sub_409F40(4096))
            sub_46D830();
        if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000) || byte_5D4594[2650637] & 1 || *(_DWORD*)& byte_5D4594[815132])
        {
            sub_48A220();
            sub_4AD170_call_copy_backbuffer();
            sub_48A290_call_present();
        }
    }
    sub_435750();
    if (!*(_DWORD*)& byte_587000[93192])
    {
        mainloop_stop();
        return;
    }
    int v17 = *(_DWORD*)& byte_5D4594[2650636];
    if (!sub_40A5C0(1) || !sub_40A5C0(2))
    {
        mainloop_wait_and_exit(v17);
        return;
    }
    if (!(v17 & 0x40000))
    {
        if (sub_40A5C0(0x10000000))
        {
            if (!(v17 & 0x80000000))
                sub_416DD0();
            mainloop_stop();
            return;
        }
    }
    mainloop_wait_and_exit(v17);
    return;
}
void sub_43E290()
{
    *(_DWORD*)& byte_587000[93196] = 1;
    *(_DWORD*)& byte_587000[93200] = 1;
    *(_DWORD*)& byte_5D4594[816400] = 60 * *(_DWORD*)& byte_5D4594[2649704];

    // XXX
    sub_4AB560(0);

    mainloop_enter = NULL;
#ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    emscripten_set_main_loop(mainloop, 0, 0);
    //emscripten_set_main_loop_timing(EM_TIMING_RAF, 2);
    return;
    // never get here
#else
    while (*(_DWORD*)& byte_587000[93196])
        mainloop();
#endif
}
// 43E815: variable 'v18' is possibly undefined
// 4AD170: using guessed type int sub_4AD170_call_copy_backbuffer(void);

//----- (0043E8B0) --------------------------------------------------------
int sub_43E8B0()
{
    return *(_DWORD*)& byte_5D4594[816404];
}

//----- (0043E8C0) --------------------------------------------------------
int __cdecl sub_43E8C0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[816408] = a1;
    return result;
}

//----- (0043E8D0) --------------------------------------------------------
void sub_43E8D0()
{
    nox_srand(0x1E76u);
}

//----- (0043E8E0) --------------------------------------------------------
void sub_43E8E0(int a1)
{
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        if (!*(_DWORD*)& byte_5D4594[816436])
        {
            *(_DWORD*)& byte_5D4594[816436] = 1;
            AIL_digital_handle_release(*(_DWORD*)& byte_5D4594[816432]);
        }
    }
}
// 581400: using guessed type int __stdcall AIL_digital_handle_release(_DWORD);

//----- (0043E910) --------------------------------------------------------
void sub_43E910(int a1)
{
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        if (*(_DWORD*)& byte_5D4594[816436])
        {
            AIL_digital_handle_reacquire(*(_DWORD*)& byte_5D4594[816432]);
            *(_DWORD*)& byte_5D4594[816436] = 0;
        }
    }
}
// 5813FC: using guessed type int __stdcall AIL_digital_handle_reacquire(_DWORD);

//----- (0043E940) --------------------------------------------------------
int __cdecl sub_43E940(int a1)
{
    int v1; // eax
    int result; // eax

    _onexit(sub_43E9C0);
    AIL_startup();
    v1 = AIL_register_timer(sub_43E9D0);
    *(_DWORD*)& byte_587000[93944] = v1;
    if (v1 == -1)
        return -2147221504;
    AIL_set_timer_frequency(v1, 30);
    AIL_start_timer(*(_DWORD*)& byte_587000[93944]);
    sub_42EBB0(1u, sub_43E910, 0, "Audio");
    sub_42EBB0(2u, sub_43E8E0, 0, "Audio");
    result = 0;
    *(_DWORD*)(a1 + 20) = 1;
    return result;
}
// 581398: using guessed type int __stdcall AIL_set_timer_frequency(_DWORD, _DWORD);
// 5813F8: using guessed type int __stdcall AIL_start_timer(_DWORD);
// 581420: using guessed type _DWORD __stdcall AIL_startup();
// 581424: using guessed type int __stdcall AIL_register_timer(_DWORD);

//----- (0043E9C0) --------------------------------------------------------
int __cdecl sub_43E9C0()
{
    sub_43E9F0();
    return 0;
}

//----- (0043E9D0) --------------------------------------------------------
_DWORD* __stdcall sub_43E9D0(int a1)
{
    sub_486EF0();
    sub_43D2D0();
    return sub_486620(*(_DWORD * *)& byte_587000[127004]);
}

//----- (0043E9F0) --------------------------------------------------------
void sub_43E9F0()
{
    if (*(int*)& byte_587000[93944] != -1)
    {
        AIL_stop_timer(*(_DWORD*)& byte_587000[93944]);
        AIL_release_timer_handle(*(_DWORD*)& byte_587000[93944]);
        *(_DWORD*)& byte_587000[93944] = -1;
    }
    AIL_shutdown();
}
// 5813D0: using guessed type int __stdcall AIL_release_timer_handle(_DWORD);
// 5813D4: using guessed type int __stdcall AIL_stop_timer(_DWORD);
// 5813F4: using guessed type _DWORD __stdcall AIL_shutdown();

//----- (0043EA20) --------------------------------------------------------
int __cdecl sub_43EA20(int a1)
{
    char v2[16]; // [esp+4h] [ebp-10h]

    sub_43EA90((int)v2, a1 + 60);
    AIL_set_preference(35, 125);
    *(_DWORD*)& byte_5D4594[816432] = sub_43EAD0((int)v2);
    if (!*(_DWORD*)& byte_5D4594[816432])
        return -2147221504;
    *(_DWORD*)& byte_587000[93948] = AIL_get_preference(42);
    *(_DWORD*)(a1 + 196) = 24;
    return 0;
}
// 5813BC: using guessed type int __stdcall AIL_get_preference(_DWORD);
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);

//----- (0043EA90) --------------------------------------------------------
int __cdecl sub_43EA90(int a1, int a2)
{
    int result; // eax

    result = a1;
    *(_WORD*)a1 = 1;
    *(_WORD*)(a1 + 2) = *(_WORD*)(a2 + 12);
    *(_DWORD*)(a1 + 4) = *(_DWORD*)(a2 + 8);
    *(_DWORD*)(a1 + 8) = *(_DWORD*)(a2 + 20);
    *(_WORD*)(a1 + 12) = *(_WORD*)(a2 + 16) * *(_WORD*)(a2 + 12);
    *(_WORD*)(a1 + 14) = 8 * *(_WORD*)(a2 + 16);
    return result;
}

//----- (0043EAD0) --------------------------------------------------------
int __cdecl sub_43EAD0(int a1)
{
    int v1; // eax
    unsigned int v2; // eax
    int v3; // ecx
    int v5; // [esp+10h] [ebp-88h]
    int v6; // [esp+14h] [ebp-84h]
    char v7[128]; // [esp+18h] [ebp-80h]

    v6 = *(_DWORD*)(a1 + 4);
    AIL_set_preference(15, 0);
    AIL_set_preference(33, 1);
    if (*(_DWORD*)(a1 + 4) < 0x2B11u)
        return 0;
    while (1)
    {
        while (1)
        {
            v1 = AIL_get_preference(15);
            if (!AIL_waveOutOpen(&v5, 0, -(v1 != 0), a1))
                break;
            AIL_last_error();
            if (!AIL_get_preference(15))
            {
                AIL_set_preference(15, 1);
                goto LABEL_11;
            }
            v2 = *(_DWORD*)(a1 + 4) >> 1;
            *(_DWORD*)(a1 + 4) = v2;
            if (v2 < 0x2B11)
            {
                if (*(_WORD*)(a1 + 14) == 8)
                {
                    v3 = v6;
                    *(_WORD*)(a1 + 14) = 8;
                    *(_DWORD*)(a1 + 4) = v3;
                }
                goto LABEL_11;
            }
        }
        strcpy(v7, "Device: ");
        AIL_digital_configuration(v5, 0, 0, &v7[strlen(v7)]);
        if (AIL_get_preference(15) || !strstr(v7, "Emulated"))
            return v5;
        AIL_waveOutClose(v5);
        AIL_set_preference(15, 1);
        AIL_set_preference(15, 1);
        LABEL_11:
        if (*(_DWORD*)(a1 + 4) < 0x2B11u)
            return 0;
    }
}
// 581390: using guessed type int __stdcall AIL_waveOutClose(_DWORD);
// 581394: using guessed type int __stdcall AIL_digital_configuration(_DWORD, _DWORD, _DWORD, _DWORD);
// 5813A4: using guessed type _DWORD __stdcall AIL_last_error();
// 5813BC: using guessed type int __stdcall AIL_get_preference(_DWORD);
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
// 581434: using guessed type int __stdcall AIL_waveOutOpen(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (0043EC10) --------------------------------------------------------
int sub_43EC10()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816432];
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        AIL_waveOutClose(*(_DWORD*)& byte_5D4594[816432]);
        *(_DWORD*)& byte_5D4594[816432] = 0;
    }
    return result;
}
// 581390: using guessed type int __stdcall AIL_waveOutClose(_DWORD);

//----- (0043EC30) --------------------------------------------------------
int __cdecl sub_43EC30(int a1)
{
    _DWORD* v1; // esi
    int v2; // eax

    v1 = nox_malloc(0x20u);
    memset(v1, 0, 0x20u);
    *(_DWORD*)(a1 + 272) = v1;
    v1[1] = a1;
    *v1 = *(_DWORD*)& byte_5D4594[816432];
    v1[5] = nox_malloc(0x4000u);
    v1[6] = nox_malloc(0x4000u);
    v2 = AIL_allocate_sample_handle(*(_DWORD*)& byte_5D4594[816432]);
    v1[2] = v2;
    if (!v2 || !v1[5] || !v1[6])
        return -2147221504;
    AIL_set_sample_user_data(v2, 0, v1);
    return 0;
}
// 58139C: using guessed type int __stdcall AIL_set_sample_user_data(_DWORD, _DWORD, _DWORD);
// 5813A0: using guessed type int __stdcall AIL_allocate_sample_handle(_DWORD);

//----- (0043ECB0) --------------------------------------------------------
int __cdecl sub_43ECB0(int a1)
{
    int v1; // esi

    v1 = *(_DWORD*)(a1 + 272);
    if (*(_DWORD*)(v1 + 8))
        AIL_release_sample_handle(*(_DWORD*)(v1 + 8));
    if (*(_DWORD*)(v1 + 20))
        free(*(LPVOID*)(v1 + 20));
    if (*(_DWORD*)(v1 + 24))
        free(*(LPVOID*)(v1 + 24));
    free((LPVOID)v1);
    return 0;
}
// 581438: using guessed type int __stdcall AIL_release_sample_handle(_DWORD);

//----- (0043ED00) --------------------------------------------------------
int __cdecl sub_43ED00(_DWORD* a1)
{
    _DWORD* v1; // esi
    int v2; // eax
    int v3; // eax
    int v4; // eax
    int v5; // ecx

    v1 = (_DWORD*)a1[68];
    AIL_init_sample(v1[2]);
    v2 = *(_DWORD*)(a1[72] + 20);
    v1[4] = v2;
    if (!v2)
        v1[4] = a1[33] + 60;
    v3 = sub_43F0E0((_DWORD*)v1[4]);
    AIL_set_sample_type(v1[2], v3, 0);
    v4 = v1[4];
    if (*(_DWORD*)(v4 + 4) == 2)
        AIL_set_sample_adpcm_block_size(v1[2], *(_DWORD*)(v4 + 24));
    sub_43F060(a1);
    v5 = v1[2];
    v1[7] = 0;
    v1[3] = 0;
    AIL_register_EOB_callback(v5, sub_43EDE0);
    AIL_register_EOS_callback(v1[2], sub_43EDB0);
    sub_43EE00((int)v1);
    return 0;
}
// 5813AC: using guessed type int __stdcall AIL_register_EOS_callback(_DWORD, _DWORD);
// 5813B0: using guessed type int __stdcall AIL_register_EOB_callback(_DWORD, _DWORD);
// 5813B4: using guessed type int __stdcall AIL_set_sample_adpcm_block_size(_DWORD, _DWORD);
// 5813B8: using guessed type int __stdcall AIL_set_sample_type(_DWORD, _DWORD, _DWORD);
// 5813F0: using guessed type int __stdcall AIL_init_sample(_DWORD);

//----- (0043EDB0) --------------------------------------------------------
int __stdcall sub_43EDB0(int a1)
{
    int v1; // eax
    int v2; // esi
    int result; // eax

    v1 = AIL_sample_user_data(a1, 0);
    v2 = v1;
    result = *(_DWORD*)(v1 + 28);
    if (!result)
    {
        result = (*(int(__cdecl * *)(_DWORD))(*(_DWORD*)(v2 + 4) + 284))(*(_DWORD*)(v2 + 4));
        *(_DWORD*)(v2 + 28) = 1;
    }
    return result;
}
// 5813A8: using guessed type int __stdcall AIL_sample_user_data(_DWORD, _DWORD);

//----- (0043EDE0) --------------------------------------------------------
int __stdcall sub_43EDE0(int a1)
{
    int v1; // eax

    v1 = AIL_sample_user_data(a1, 0);
    return sub_43EE00(v1);
}
// 5813A8: using guessed type int __stdcall AIL_sample_user_data(_DWORD, _DWORD);

//----- (0043EE00) --------------------------------------------------------
int __cdecl sub_43EE00(int a1)
{
    int v1; // esi
    int result; // eax
    int v3; // ebx
    int v4; // edi
    char* v5; // ebp
    unsigned int v6; // ecx
    signed int v7; // esi
    signed int v8; // eax
    char* v9; // esi
    char v10; // bp
    unsigned int v11; // ecx
    char* v12; // edi
    char* v13; // esi
    int v14; // ecx
    int v15; // edx
    int v16; // eax
    char* v17; // [esp+4h] [ebp-18h]
    signed int v18; // [esp+8h] [ebp-14h]
    char* v19; // [esp+Ch] [ebp-10h]
    int v20; // [esp+10h] [ebp-Ch]
    int v21; // [esp+14h] [ebp-8h]
    char* v22; // [esp+18h] [ebp-4h]

    v1 = a1;
    result = AIL_sample_buffer_ready(*(_DWORD*)(a1 + 8));
    v20 = result;
    if (result != -1)
    {
        while (1)
        {
            v3 = *(_DWORD*)(v1 + 4);
            v4 = 0;
            v5 = 0;
            v17 = *(char**)(v1 + 4 * v20 + 20);
            v6 = 0;
            v7 = 0;
            v21 = 0;
            v19 = 0;
            v18 = 0;
            if (!*(_DWORD*)(a1 + 12))
                break;
            LABEL_27:
            AIL_load_sample_buffer(*(_DWORD*)(a1 + 8), v20, v19, v4);
            result = AIL_sample_buffer_ready(*(_DWORD*)(a1 + 8));
            v20 = result;
            if (result == -1)
                return result;
            v1 = a1;
        }
        while (1)
        {
            if (v4 >= 0x4000)
                goto LABEL_27;
            v8 = *(_DWORD*)(v3 + 300);
            if (!v8)
            {
                (*(void(__cdecl * *)(int))(v3 + 276))(v3);
                v8 = *(_DWORD*)(v3 + 300);
                if (!v8)
                {
                    (*(void(__cdecl * *)(int))(v3 + 280))(v3);
                    v8 = *(_DWORD*)(v3 + 300);
                    if (!v8)
                    {
                        *(_DWORD*)(a1 + 12) = 1;
                        goto LABEL_27;
                    }
                }
                v6 = v18;
            }
            if (v4)
                break;
            v19 = *(char**)(v3 + 296);
            if (v8 < 0x4000 || v5)
                break;
            v7 = v8;
            LABEL_24:
            v15 = *(_DWORD*)(v3 + 304) - v7;
            *(_DWORD*)(v3 + 300) -= v7;
            v16 = v7 + *(_DWORD*)(v3 + 296);
            *(_DWORD*)(v3 + 304) = v15;
            *(_DWORD*)(v3 + 296) = v16;
            v4 += v7;
            v21 = v4;
            if (*(_DWORD*)(a1 + 12))
                goto LABEL_27;
        }
        if (v8 + v4 > 0x4000)
            v8 = 0x4000 - v4;
        if (!v8)
            goto LABEL_24;
        if (v5)
        {
            if (v6)
            {
                v9 = v5;
                v10 = v6;
                v11 = v6 >> 2;
                qmemcpy(v22, v9, 4 * v11);
                v13 = &v9[4 * v11];
                v12 = &v22[4 * v11];
                v19 = v22;
                v14 = v10 & 3;
                v5 = 0;
                qmemcpy(v12, v13, v14);
            }
        }
        else if (!v6)
        {
            v5 = *(char**)(v3 + 296);
            v22 = v17;
            v18 = v8;
            LABEL_23:
            v7 = v8;
            v17 += v8;
            v6 = v18;
            goto LABEL_24;
        }
        qmemcpy(v17, *(const void**)(v3 + 296), v8);
        v4 = v21;
        goto LABEL_23;
    }
    return result;
}
// 43EF03: variable 'v22' is possibly undefined
// 5813C4: using guessed type int __stdcall AIL_load_sample_buffer(_DWORD, _DWORD, _DWORD, _DWORD);
// 5813C8: using guessed type int __stdcall AIL_sample_buffer_ready(_DWORD);

//----- (0043EFD0) --------------------------------------------------------
int __cdecl sub_43EFD0(int a1)
{
    _DWORD* v1; // esi

    v1 = *(_DWORD * *)(a1 + 272);
    AIL_end_sample(v1[2]);
    if (!v1[7])
    {
        (*(void(__cdecl * *)(_DWORD))(v1[1] + 284))(v1[1]);
        v1[7] = 1;
    }
    return 0;
}
// 5813CC: using guessed type int __stdcall AIL_end_sample(_DWORD);

//----- (0043F010) --------------------------------------------------------
int __cdecl sub_43F010(int a1)
{
    AIL_stop_sample(*(_DWORD*)(*(_DWORD*)(a1 + 272) + 8));
    return 0;
}
// 581428: using guessed type int __stdcall AIL_stop_sample(_DWORD);

//----- (0043F030) --------------------------------------------------------
int __cdecl sub_43F030(int a1)
{
    AIL_resume_sample(*(_DWORD*)(*(_DWORD*)(a1 + 272) + 8));
    return 0;
}
// 58142C: using guessed type int __stdcall AIL_resume_sample(_DWORD);

//----- (0043F050) --------------------------------------------------------
int sub_43F050()
{
    return 0;
}

//----- (0043F060) --------------------------------------------------------
int __cdecl sub_43F060(_DWORD* a1)
{
    int v1; // esi
    int v2; // eax

    v1 = a1[68];
    AIL_set_sample_volume(*(_DWORD*)(v1 + 8), (unsigned int)(127 * (a1[45] >> 16)) >> 14);
    AIL_set_sample_pan(*(_DWORD*)(v1 + 8), (unsigned int)(127 * (a1[61] >> 16)) >> 14);
    v2 = sub_486640((int)(a1 + 44), *(_DWORD*)(*(_DWORD*)(v1 + 16) + 8));
    AIL_set_sample_playback_rate(*(_DWORD*)(v1 + 8), v2);
    return 0;
}
// 5813D8: using guessed type int __stdcall AIL_set_sample_playback_rate(_DWORD, _DWORD);
// 5813DC: using guessed type int __stdcall AIL_set_sample_pan(_DWORD, _DWORD);
// 5813E0: using guessed type int __stdcall AIL_set_sample_volume(_DWORD, _DWORD);

//----- (0043F0D0) --------------------------------------------------------
int sub_43F0D0()
{
    return 0;
}

//----- (0043F0E0) --------------------------------------------------------
int __cdecl sub_43F0E0(_DWORD* a1)
{
    int v1; // ecx
    int result; // eax
    int v3; // eax

    v1 = a1[1];
    if (v1)
    {
        if (v1 == 2)
        {
            v3 = -(a1[3] != 2);
            LOBYTE(v3) = v3 & 0xFE;
            result = v3 + 7;
        }
        else
        {
            result = 0;
        }
    }
    else if (a1[3] == 2)
    {
        result = (a1[4] == 2) + 2;
    }
    else
    {
        result = a1[4] == 2;
    }
    return result;
}

//----- (0043F130) --------------------------------------------------------
int sub_43F130()
{
    return *(_DWORD*)& byte_5D4594[816432];
}

//----- (0043F140) --------------------------------------------------------
void __cdecl sub_43F140(int a1)
{
    int result; // eax
    int v2; // esi

    if (*(_DWORD*)& byte_5D4594[816432])
    {
        result = AIL_get_preference(34);
        if (result)
        {
            v2 = a1 / result;
            if (a1 / result > 0)
            {
                if (v2 > AIL_get_preference(35))
                    v2 = AIL_get_preference(35);
                AIL_set_preference(42, v2);
                AIL_serve();
            }
            else
            {
                AIL_set_preference(42, *(_DWORD*)& byte_587000[93948]);
                AIL_serve();
            }
        }
    }
}
// 5813BC: using guessed type int __stdcall AIL_get_preference(_DWORD);
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
// 5813E4: using guessed type _DWORD __stdcall AIL_serve();

//----- (0043F1A0) --------------------------------------------------------
int sub_43F1A0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816432];
    if (*(_DWORD*)& byte_5D4594[816432])
    {
        AIL_set_preference(42, *(_DWORD*)& byte_587000[93948]);
        AIL_serve();
    }
    return result;
}
// 5813C0: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
// 5813E4: using guessed type _DWORD __stdcall AIL_serve();

//----- (0043F1C0) --------------------------------------------------------
int sub_43F1C0()
{
    int v0; // esi
    unsigned __int8* v1; // eax
    unsigned __int8* v2; // eax
    int v3; // ebp
    int v4; // edi
    int v5; // ebx

    v0 = 0;
    if (*(_DWORD*)& byte_5D4594[3801780])
    {
        if (*(_DWORD*)& byte_5D4594[3801780] == 1)
            * (_DWORD*)& byte_5D4594[816448] = sub_43FE90;
    }
    else
    {
        *(_DWORD*)& byte_5D4594[816448] = sub_440360;
    }
    *(_DWORD*)& byte_5D4594[816456] = 64;
    *(_DWORD*)& byte_5D4594[816484] = 1;
    *(_DWORD*)& byte_5D4594[816440] = 1;
    *(_DWORD*)& byte_5D4594[816460] = 0;
    *(_DWORD*)& byte_5D4594[816452] = 0;
    v1 = &byte_5D4594[816484];
    *(_DWORD*)& byte_5D4594[816444] = 0;
    do
    {
        v1 -= 4;
        *(_DWORD*)v1 = 0;
    } while (v1 != &byte_5D4594[816464]);
    if (*(_DWORD*)& byte_587000[26048] == 6 || (v2 = &byte_587000[94112], *(_DWORD*)& byte_587000[26048] == 8))
        v2 = &byte_587000[94176];
    *(_DWORD*)& byte_5D4594[816488] = v2;
    v3 = 0;
    do
    {
        if (*(_DWORD*)& v2[v0 + 4])
        {
            v4 = 0;
            if (v0 > 0)
            {
                v5 = 0;
                while (_strcmpi(*(const char**)& v2[v0 + 4], *(const char**)& v2[v5 + 4]))
                {
                    v2 = *(unsigned __int8**)& byte_5D4594[816488];
                    ++v4;
                    v5 += 12;
                    if (v4 >= v3)
                        goto LABEL_18;
                }
                *(_DWORD*)(v0 + *(_DWORD*)& byte_5D4594[816488] + 8) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[816488] + 12 * v4 + 8);
                v2 = *(unsigned __int8**)& byte_5D4594[816488];
            }
            LABEL_18:
            if (*(_DWORD*)& v2[v0 + 4] && !*(_DWORD*)& v2[v0 + 8])
            {
                *(_DWORD*)(v0 + *(_DWORD*)& byte_5D4594[816488] + 8) = sub_43F3B0(*(char**)& v2[v0 + 4]);
                v2 = *(unsigned __int8**)& byte_5D4594[816488];
            }
        }
        v0 += 12;
        ++v3;
    } while (v0 < 60);
    *(_DWORD*)& byte_5D4594[816492] = *((_DWORD*)v2 + 2);
    return 1;
}

//----- (0043F2E0) --------------------------------------------------------
void sub_43F2E0()
{
    int v0; // edi
    void** v1; // esi
    void* result; // eax
    bool v3; // zf

    v0 = 0;
    v1 = (void**)& byte_5D4594[816464];
    do
    {
        result = *v1;
        v3 = *v1 == 0;
        *(_DWORD*)(v0 + *(_DWORD*)& byte_5D4594[816488] + 8) = 0;
        if (!v3)
        {
            *v1 = 0;
            sub_440840(result);
        }
        ++v1;
        v0 += 12;
    } while ((int)v1 < (int)& byte_5D4594[816484]);
}

//----- (0043F320) --------------------------------------------------------
int __cdecl sub_43F320(int a1)
{
    int v1; // ecx
    int result; // eax

    v1 = a1;
    result = 0;
    if (a1 || (v1 = *(_DWORD*)& byte_5D4594[816492]) != 0)
        result = *(_DWORD*)(v1 + 28);
    return result;
}

//----- (0043F340) --------------------------------------------------------
int __cdecl sub_43F340(int* a1)
{
    int* v1; // ecx
    int result; // eax

    v1 = a1;
    result = 0;
    if (a1 || (v1 = *(int**)& byte_5D4594[816492]) != 0)
        result = *v1;
    return result;
}

//----- (0043F360) --------------------------------------------------------
int __cdecl sub_43F360(char* a1)
{
    int v1; // edi
    int v2; // esi
    const char* v3; // eax

    if (!*(_DWORD*)& byte_5D4594[816488])
        return 0;
    v1 = 0;
    v2 = 0;
    while (1)
    {
        v3 = *(const char**)(v2 + *(_DWORD*)& byte_5D4594[816488]);
        if (v3)
        {
            if (!_strcmpi(v3, a1))
                break;
        }
        v2 += 12;
        ++v1;
        if (v2 >= 60)
            return 0;
    }
    return *(_DWORD*)(*(_DWORD*)& byte_5D4594[816488] + 12 * v1 + 8);
}

//----- (0043F3B0) --------------------------------------------------------
_DWORD* __cdecl sub_43F3B0(char* a1)
{
    _DWORD* v1; // ebx
    FILE* v3; // ebp
    char* v4; // eax
    unsigned __int16 v5; // cx
    unsigned __int16 v6; // dx
    int v7; // eax
    unsigned __int8* v8; // eax
    size_t v9; // esi
    char* v10; // eax
    int v11; // ecx
    unsigned __int8* v12; // eax
    int v13; // eax
    _BYTE* v14; // eax
    _BYTE* v15; // esi
    _BYTE* v16; // eax
    int v17[7]; // [esp+4h] [ebp-68h]
    unsigned __int8 v18[76]; // [esp+20h] [ebp-4Ch]

    v1 = 0;
    if (*(int*)& byte_5D4594[816444] >= 5)
        return 0;
    v3 = fopen(a1, "rb");
    if (v3)
    {
        v1 = nox_malloc(0x20u);
        if (v1)
        {
            memset(v1, 0, 0x20u);
            if (sub_40ADD0_fread((char*)v17, 0x1Cu, 1u, v3) != 1)
                goto LABEL_15;
            if (v17[0] == 1181699700)
            {
                v1[2] = v17[4];
                v1[1] = v17[3];
                *v1 = v17[2];
                v1[5] = v17[6];
                v1[3] = v17[5];
                v4 = (char*)nox_malloc(8 * v17[5]);
                v1[4] = v4;
                if (!v4 || sub_40ADD0_fread(v4, 8 * v1[3], 1u, v3) != 1)
                    goto LABEL_15;
            }
            else
            {
                fseek(v3, 0, 0);
                if (sub_40ADD0_fread((char*)v18, 0x4Cu, 1u, v3) != 1)
                    goto LABEL_15;
                v5 = *(_WORD*)& v18[2];
                v6 = *(_WORD*)v18;
                v1[2] = *(unsigned __int16*)& v18[4];
                v1[5] = *(_DWORD*)& v18[72];
                v7 = *(unsigned __int16*)& v18[6];
                v1[1] = v5;
                *v1 = v6;
                v1[3] = v7;
                v8 = (unsigned __int8*)nox_malloc(8 * v7);
                v1[4] = v8;
                if (!v8)
                    goto LABEL_15;
                qmemcpy(v8, &v18[8], 8 * v1[3]);
            }
            v1[7] = v1[2];
            v9 = v1[5] * sub_440870((int)v1);
            v10 = (char*)nox_malloc(v9);
            v1[6] = v10;
            if (!v10 || sub_40ADD0_fread(v10, v9, 1u, v3) != 1)
            {
                LABEL_15:
                sub_440840(v1);
                fclose(v3);
                return 0;
            }
            v11 = 0;
            v12 = &byte_5D4594[816464];
            while (*(_DWORD*)v12)
            {
                v12 += 4;
                ++v11;
                if ((int)v12 >= (int)& byte_5D4594[816484])
                    goto LABEL_21;
            }
            v13 = *(_DWORD*)& byte_5D4594[816444];
            *(_DWORD*)& byte_5D4594[4 * v11 + 816464] = v1;
            *(_DWORD*)& byte_5D4594[816444] = v13 + 1;
            LABEL_21:
            if (*(unsigned __int8**)& byte_5D4594[816488] == &byte_587000[94176])
            {
                ++v1[7];
                v14 = (_BYTE*)sub_43FE30((int)v1, 0x20u);
                v15 = v14;
                if (v14 && *(_DWORD*)& byte_587000[26048] == 8)
                    ++* v14;
                if (*(_DWORD*)& byte_587000[26048] == 6)
                {
                    v16 = (_BYTE*)sub_43FE30((int)v1, 0x3000u);
                    if (v16)
                    {
                        if (v15)
                        {
                            *v16 = 2 * *v15;
                            fclose(v3);
                            return v1;
                        }
                        *v16 = *(_BYTE*)v1;
                    }
                }
            }
        }
        fclose(v3);
    }
    return v1;
}

//----- (0043F620) --------------------------------------------------------
int __cdecl sub_43F620(LPVOID lpMem)
{
    int v1; // ecx
    LPVOID* v2; // eax

    if (!lpMem)
        return 0;
    v1 = 0;
    v2 = (LPVOID*)& byte_5D4594[816464];
    while (*v2 != lpMem)
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_5D4594[816484])
            return 0;
    }
    *(_DWORD*)& byte_5D4594[4 * v1 + 816464] = 0;
    sub_440840(lpMem);
    --* (_DWORD*)& byte_5D4594[816444];
    return 1;
}

//----- (0043F670) --------------------------------------------------------
int __cdecl sub_43F670(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816452];
    *(_DWORD*)& byte_5D4594[816452] = a1;
    return result;
}

//----- (0043F680) --------------------------------------------------------
int __cdecl sub_43F680(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816484];
    *(_DWORD*)& byte_5D4594[816484] = a1;
    return result;
}

//----- (0043F690) --------------------------------------------------------
int __cdecl sub_43F690(int a1, int a2, int a3, int a4)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    result = a1;
    if (a1 || (result = *(_DWORD*)& byte_5D4594[816492]) != 0)
    {
        *(_DWORD*)& byte_5D4594[816460] = a3;
        result = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(result, a2, a3, a4);
    }
    return result;
}

//----- (0043F6E0) --------------------------------------------------------
int __cdecl sub_43F6E0(int a1, __int16* a2, int a3, int a4)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    result = a1;
    if (a1 || (result = *(_DWORD*)& byte_5D4594[816492]) != 0)
    {
        *(_DWORD*)& byte_5D4594[816460] = a3;
        result = sub_4407F0(result, a2, a3, a4);
    }
    return result;
}

//----- (0043F730) --------------------------------------------------------
int __cdecl sub_43F730(int a1, __int16* a2, int a3, int a4)
{
    int v5; // edi
    int v6; // ebx

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    v5 = a1;
    if (!a1)
    {
        v5 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    *(_DWORD*)& byte_5D4594[816460] = a3;
    v6 = ptr_5D4594_3799572->data[59];
    sub_434390(ptr_5D4594_3799572->data[60]);
    sub_4407F0(v5, a2, a3 + 1, a4 + 1);
    sub_434390(v6);
    return sub_4407F0(v5, a2, a3, a4);
}

//----- (0043F7B0) --------------------------------------------------------
int __cdecl sub_43F7B0(int a1, __int16* a2, int a3, int a4)
{
    int result; // eax
    int v5; // esi

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    v5 = a1;
    if (!a1)
    {
        v5 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    *(_DWORD*)& byte_5D4594[816460] = a3;
    if (!*(_DWORD*)& byte_5D4594[816484])
        return sub_4407F0(v5, a2, a3, a4);
    *(_DWORD*)& byte_5D4594[816440] = 2;
    sub_4407F0(v5, a2, a3, a4);
    result = sub_4407F0(v5, a2, a3 + 1, a4);
    *(_DWORD*)& byte_5D4594[816440] = 1;
    return result;
}

//----- (0043F840) --------------------------------------------------------
int __cdecl sub_43F840(int a1, unsigned __int16* a2, int* a3, _DWORD* a4, int a5)
{
unsigned __int16 v5; // cx
unsigned __int16 v6; // bp
int v7; // ebx
int v8; // esi
unsigned __int16* v9; // edi
unsigned __int8* v10; // eax
int v11; // eax
int v12; // esi
int result; // eax
unsigned __int16* i; // [esp+4h] [ebp-8h]
int v15; // [esp+8h] [ebp-4h]
int v16; // [esp+14h] [ebp+8h]

v5 = 0;
if ((a1 || (a1 = *(_DWORD*)& byte_5D4594[816492]) != 0) && a2)
{
v6 = *a2;
v7 = 0;
v8 = 0;
v9 = a2 + 1;
v16 = *(_DWORD*)(a1 + 28);
for (i = 0; v6; ++v9)
{
switch (v6)
{
case 9u:
v8 = *(_DWORD*)& byte_5D4594[816456]
                 + v8
                 - (*(_DWORD*)& byte_5D4594[816456] + v8) % *(_DWORD*)& byte_5D4594[816456];
break;
case 0xAu:
case 0xDu:
if (v5 != 13)
goto LABEL_7;
break;
case 0x20u:
v15 = v7;
i = v9;
goto LABEL_10;
default:
LABEL_10:
v10 = (unsigned __int8*)sub_43FE30(a1, v6);
if (v10 || (v10 = (unsigned __int8*)sub_43FE30(a1, 0x3Fu)) != 0)
{
v11 = *v10;
v8 += v11 + *(_DWORD*)& byte_5D4594[816440];
if (a5 && v8 > a5)
{
if (i)
{
v7 = v15;
v9 = i;
i = 0;
}
else
{
--v9;
v12 = v8 - (*(_DWORD*)& byte_5D4594[816440] + v11);
if (v12 > v7)
v7 = v12;
}
LABEL_7:
v8 = 0;
v16 += *(_DWORD*)(a1 + 28);
}
else if (v8 > v7)
{
v7 = v8;
}
}
break;
}
v5 = v6;
v6 = *v9;
}
if (a3)
* a3 = v7;
if (a4)
* a4 = v16;
result = 1;
}
else
{
if (a4)
* a4 = 0;
if (a3)
* a3 = 0;
result = 0;
}
return result;
}
// 43F936: variable 'v15' is possibly undefined

//----- (0043F9E0) --------------------------------------------------------
int __cdecl sub_43F9E0(int a1, unsigned __int16* a2, int a3)
{
int v3; // ebx
int v4; // ebp
int v5; // edi
unsigned __int16 v6; // cx
unsigned __int16* i; // esi
unsigned __int8* v8; // eax

v3 = a1;
v4 = 0;
v5 = 0;
if (!a1)
{
v3 = *(_DWORD*)& byte_5D4594[816492];
if (!*(_DWORD*)& byte_5D4594[816492])
return 0;
}
if (!a2)
return 0;
v6 = *a2;
for (i = a2 + 1; v6; ++i)
{
if (v6 == 9)
{
v5 = *(_DWORD*)& byte_5D4594[816456]
                 + v5
                 - (*(_DWORD*)& byte_5D4594[816456] + v5) % *(_DWORD*)& byte_5D4594[816456];
}
else if (v6 != 10 && v6 != 13)
{
v8 = (unsigned __int8*)sub_43FE30(v3, v6);
if (v8 || (v8 = (unsigned __int8*)sub_43FE30(v3, 0x3Fu)) != 0)
v5 += *(_DWORD*)& byte_5D4594[816440] + *v8;
}
if (v5 > a3)
break;
v6 = *i;
++v4;
}
return v4;
}

//----- (0043FA80) --------------------------------------------------------
int __cdecl sub_43FA80(int a1, unsigned __int16* a2, int* a3, _DWORD* a4, int a5)
{
int result; // eax

if (!*(_DWORD*)& byte_5D4594[816484])
return sub_43F840(a1, a2, a3, a4, a5);
*(_DWORD*)& byte_5D4594[816440] = 2;
result = sub_43F840(a1, a2, a3, a4, a5);
*(_DWORD*)& byte_5D4594[816440] = 1;
return result;
}

//----- (0043FAF0) --------------------------------------------------------
int __cdecl sub_43FAF0(int a1, _WORD* a2, int a3, int a4, int a5, int a6)
{
    int v7; // ebx
    int v8; // ecx
    _WORD* v9; // edi
    int v10; // eax
    int v11; // ebp
    bool v12; // zf
    _WORD* v13; // esi
    int v14; // eax
    int i; // eax
    int v16; // ebp
    int v17; // ecx
    int j; // eax
    int v19; // eax
    _WORD* v20; // [esp+10h] [ebp-4h]
    int v21; // [esp+18h] [ebp+4h]
    int v22; // [esp+1Ch] [ebp+8h]

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    v7 = a1;
    v8 = 0;
    if (!a1)
    {
        v7 = *(_DWORD*)& byte_5D4594[816492];
        if (!*(_DWORD*)& byte_5D4594[816492])
            return 0;
    }
    v9 = a2;
    if (!a2)
        return 0;
    HIWORD(v10) = HIWORD(a3);
    v11 = 0;
    *(_DWORD*)& byte_5D4594[816460] = a3;
    LOWORD(v10) = *a2;
    v12 = *a2 == 0;
    v21 = 0;
    v13 = a2;
    v20 = 0;
    v22 = v10;
    if (!v12)
    {
        while (2)
        {
            v14 = (unsigned __int16)v22 - 9;
            switch ((unsigned __int16)v22)
            {
                case 9u:
                    v16 = *(_DWORD*)& byte_5D4594[816456] + v11;
                v14 = v16 / *(_DWORD*)& byte_5D4594[816456];
                v11 = v16 - v16 % *(_DWORD*)& byte_5D4594[816456];
                goto LABEL_31;
                case 0xAu:
                case 0xDu:
                    if ((_WORD)v8 == 13)
                        goto LABEL_14;
                for (i = a3;
                     v13 < v9;
                     i = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(v7, v8, i, a4))
                {
                    LOWORD(v8) = *v13;
                    ++v13;
                }
                v14 = *(_DWORD*)(v7 + 28);
                v11 = 0;
                v21 += v14;
                if (a6 && v21 >= a6)
                    return 1;
                a4 += v14;
                LABEL_14:
                ++v13;
                goto LABEL_31;
                case 0x20u:
                    v20 = v9;
                goto LABEL_17;
                default:
                LABEL_17:
                    v14 = sub_43FE30(v7, v22);
                if (!v14)
                {
                    v14 = sub_43FE30(v7, 0x3Fu);
                    if (!v14)
                        goto LABEL_31;
                }
                v17 = *(_DWORD*)& byte_5D4594[816440] + *(unsigned __int8*)v14;
                HIWORD(v14) = HIWORD(a5);
                v11 += v17;
                if (!a5 || v11 <= a5)
                    goto LABEL_31;
                if (v20)
                    v9 = v20;
                else
                    --v9;
                for (j = a3;
                     v13 < v9;
                     j = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(v7, v17, j, a4))
                {
                    LOWORD(v17) = *v13;
                    ++v13;
                }
                if (v20)
                {
                    v20 = 0;
                    ++v13;
                }
                v14 = *(_DWORD*)(v7 + 28);
                v11 = 0;
                v21 += v14;
                if (a6 && v21 >= a6)
                    return 1;
                a4 += v14;
                LABEL_31:
                LOWORD(v14) = v9[1];
                v8 = v22;
                ++v9;
                v22 = v14;
                if ((_WORD)v14)
                    continue;
                if (v13 < v9)
                {
                    v19 = a3;
                    do
                    {
                        LOWORD(v8) = *v13;
                        ++v13;
                        v19 = (*(int(__cdecl * *)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[816448])(v7, v8, v19, a4);
                    } while (v13 < v9);
                }
                break;
            }
            break;
        }
    }
    return 1;
}
// 43FB91: variable 'v8' is possibly undefined
// 43FC42: variable 'v17' is possibly undefined

//----- (0043FD00) --------------------------------------------------------
int __cdecl sub_43FD00(int a1, _WORD* a2, int a3, int a4, int a5, int a6)
{
    int v7; // edi

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    *(_DWORD*)& byte_5D4594[816460] = a3;
    v7 = ptr_5D4594_3799572->data[59];
    sub_434390(ptr_5D4594_3799572->data[60]);
    sub_43FAF0(a1, a2, a3 + 1, a4 + 1, a5, a6);
    sub_434390(v7);
    return sub_43FAF0(a1, a2, a3, a4, a5, a6);
}

//----- (0043FD80) --------------------------------------------------------
int __cdecl sub_43FD80(int a1, _WORD* a2, int a3, int a4, int a5, int a6)
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[2650636] & 0x10000)
        return a3;
    *(_DWORD*)& byte_5D4594[816460] = a3;
    if (!*(_DWORD*)& byte_5D4594[816484])
        return sub_43FAF0(a1, a2, a3, a4, a5, a6);
    *(_DWORD*)& byte_5D4594[816440] = 2;
    sub_43FAF0(a1, a2, a3, a4, a5, a6);
    result = sub_43FAF0(a1, a2, a3 + 1, a4, a5, a6);
    *(_DWORD*)& byte_5D4594[816440] = 1;
    return result;
}

//----- (0043FE20) --------------------------------------------------------
int __cdecl sub_43FE20(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[816456];
    *(_DWORD*)& byte_5D4594[816456] = a1;
    return result;
}

//----- (0043FE30) --------------------------------------------------------
int __cdecl sub_43FE30(int a1, unsigned __int16 a2)
{
    int v2; // edx
    int result; // eax
    int v4; // esi

    v2 = *(_DWORD*)(a1 + 16);
    result = 0;
    v4 = 0;
    if ((int) * (unsigned __int16*)(a1 + 12) > 0)
    {
        while (a2 < *(_WORD*)(v2 + 4) || a2 > * (_WORD*)(v2 + 6))
        {
            v2 += 8;
            if (++v4 >= *(unsigned __int16*)(a1 + 12))
            return result;
        }
        result = *(_DWORD*)(a1 + 24) + *(_DWORD*)(a1 + 20) * (*(_DWORD*)v2 + a2 - *(unsigned __int16*)(v2 + 4));
    }
    return result;
}

//----- (0043FE90) --------------------------------------------------------
int __cdecl sub_43FE90(int a1, __int16 a2, int xLeft, int yTop)
{
    int v4; // edx
    int v5; // ebp
    int v7; // edi
    unsigned __int8* v8; // eax
    __int16 v9; // ax
    int v10; // esi
    int v11; // ebx
    int v12; // ebp
    int v13; // edi
    int v14; // ebx
    int v15; // edx
    int v16; // ebp
    int v17; // esi
    _WORD* v18; // eax
    char* v19; // ebp
    int v20; // ecx
    char v21; // dl
    _WORD* v22; // eax
    int v23; // ecx
    int v24; // esi
    _WORD* v25; // eax
    int v26; // ecx
    int v27; // esi
    _WORD* v28; // eax
    int v29; // ecx
    int v30; // esi
    _WORD* v31; // eax
    int v32; // ecx
    int v33; // esi
    _WORD* v34; // eax
    int v35; // ecx
    int v36; // esi
    _WORD* v37; // eax
    int v38; // ecx
    int v39; // esi
    _WORD* v40; // eax
    int v41; // ecx
    int v42; // esi
    bool v43; // zf
    int v44; // eax
    int v45; // esi
    int v46; // edi
    char* v47; // esi
    _WORD* v48; // eax
    int v49; // ecx
    char v50; // dl
    _WORD* v51; // eax
    int v52; // ecx
    _WORD* v53; // eax
    int v54; // ecx
    _WORD* v55; // eax
    int v56; // ecx
    _WORD* v57; // eax
    int v58; // ecx
    _WORD* v59; // eax
    int v60; // ecx
    _WORD* v61; // eax
    int v62; // ecx
    _WORD* v63; // eax
    int v64; // ecx
    int v65; // [esp+10h] [ebp-38h]
    int v66; // [esp+10h] [ebp-38h]
    int v67; // [esp+14h] [ebp-34h]
    int v68; // [esp+18h] [ebp-30h]
    int v69; // [esp+18h] [ebp-30h]
    int v70; // [esp+1Ch] [ebp-2Ch]
    int v71; // [esp+24h] [ebp-24h]
    int4 v72; // [esp+28h] [ebp-20h]
    RECT rc; // [esp+38h] [ebp-10h]

    v5 = yTop;
    v71 = yTop;
    if (a2 == 9)
        return *(_DWORD*)& byte_5D4594[816456]
                           + xLeft
                           - (*(_DWORD*)& byte_5D4594[816456] + xLeft - *(_DWORD*)& byte_5D4594[816460]) % *(_DWORD*)& byte_5D4594[816456];
    v7 = a1;
    LOWORD(v4) = *(_WORD*)(&ptr_5D4594_3799572->data[59]);
    yTop = v4;
    v8 = (unsigned __int8*)sub_43FE30(a1, a2);
    if (!v8)
    {
        v9 = sub_4408A0(&yTop);
        a2 = v9;
        v8 = (unsigned __int8*)sub_43FE30(a1, v9);
        if (!v8)
            return xLeft;
    }
    v10 = *(_DWORD*)(a1 + 8);
    v11 = xLeft;
    v65 = (int)(v8 + 1);
    v67 = *v8;
    if (!ptr_5D4594_3799572->data[0])
        goto LABEL_102;
    SetRect(&rc, xLeft, v5, xLeft + *v8, v10 + v5);
    if (!sub_49F930(&v72, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1])))
        return v11 + *(_DWORD*)& byte_5D4594[816440] + v67;
    if (rc.left == v72.field_0 && rc.right == v72.field_8 && rc.top == v72.field_4 && rc.bottom == v72.field_C)
    {
        LABEL_102:
        v44 = v10;
        v45 = v10 - 1;
        if (v44)
        {
            v46 = 4 * v5;
            v69 = v45 + 1;
            while (1)
            {
                v47 = (char*)v65;
                v48 = (_WORD*)(2 * v11 + *(_DWORD*)(v46 + *(_DWORD*)& byte_5D4594[3798784]));
                v49 = v67;
                v46 += 4;
                while (1)
                {
                    v50 = *v47++;
                    if (v50)
                        break;
                    v48 += 8;
                    v49 -= 8;
                    LABEL_92:
                    if (v49 <= 0)
                        goto LABEL_95;
                }
                if (v50 < 0)
                    * v48 = yTop;
                v51 = v48 + 1;
                v52 = v49 - 1;
                if (v52 > 0)
                {
                    if (v50 & 0x40)
                        * v51 = yTop;
                    v53 = v51 + 1;
                    v54 = v52 - 1;
                    if (v54 > 0)
                    {
                        if (v50 & 0x20)
                            * v53 = yTop;
                        v55 = v53 + 1;
                        v56 = v54 - 1;
                        if (v56 > 0)
                        {
                            if (v50 & 0x10)
                                * v55 = yTop;
                            v57 = v55 + 1;
                            v58 = v56 - 1;
                            if (v58 > 0)
                            {
                                if (v50 & 8)
                                    * v57 = yTop;
                                v59 = v57 + 1;
                                v60 = v58 - 1;
                                if (v60 > 0)
                                {
                                    if (v50 & 4)
                                        * v59 = yTop;
                                    v61 = v59 + 1;
                                    v62 = v60 - 1;
                                    if (v62 > 0)
                                    {
                                        if (v50 & 2)
                                            * v61 = yTop;
                                        v63 = v61 + 1;
                                        v64 = v62 - 1;
                                        if (v64 > 0)
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }
                v11 = xLeft;
                LABEL_95:
                v43 = v69 == 1;
                v65 += *(_DWORD*)(a1 + 4);
                --v69;
                if (v43)
                {
                    v7 = a1;
                    goto LABEL_97;
                }
            }
            if (v50 & 1)
                * v63 = yTop;
            v11 = xLeft;
            v48 = v63 + 1;
            v49 = v64 - 1;
            goto LABEL_92;
        }
        LABEL_97:
        if (*(_DWORD*)& byte_5D4594[816452])
        {
            sub_49D190(ptr_5D4594_3799572->data[59], v11, v5, v67, *(_DWORD*)(v7 + 8));
            *(_DWORD*)& byte_5D4594[816452] = 0;
            sub_43FE90(v7, a2, v11, v5);
            *(_DWORD*)& byte_5D4594[816452] = 1;
        }
        return v11 + *(_DWORD*)& byte_5D4594[816440] + v67;
    }
    v12 = v72.field_4 - rc.top + v5;
    v66 = *(_DWORD*)(a1 + 4) * (v72.field_4 - rc.top) + v65;
    v13 = ptr_5D4594_3799572->data[1];
    v14 = ptr_5D4594_3799572->data[3];
    if (v72.field_C == v72.field_4)
        goto LABEL_60;
    v15 = xLeft;
    v16 = 4 * v12;
    v68 = v72.field_C - v72.field_4;
    while (2)
    {
        v17 = v67;
        v18 = (_WORD*)(2 * v15 + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v16));
        v70 = v16 + 4;
        v19 = (char*)v66;
        v20 = v15;
        while (1)
        {
            v21 = *v19++;
            if (v21)
                break;
            v18 += 8;
            v17 -= 8;
            v20 += 8;
            LABEL_58:
            if (v17 <= 0)
                goto LABEL_59;
        }
        if (v20 >= v13 && v20 < v14 && v21 < 0)
            * v18 = yTop;
        v22 = v18 + 1;
        v23 = v20 + 1;
        v24 = v17 - 1;
        if (v24 > 0)
        {
            if (v23 >= v13 && v23 < v14 && v21 & 0x40)
                * v22 = yTop;
            v25 = v22 + 1;
            v26 = v23 + 1;
            v27 = v24 - 1;
            if (v27 > 0)
            {
                if (v26 >= v13 && v26 < v14 && v21 & 0x20)
                    * v25 = yTop;
                v28 = v25 + 1;
                v29 = v26 + 1;
                v30 = v27 - 1;
                if (v30 > 0)
                {
                    if (v29 >= v13 && v29 < v14 && v21 & 0x10)
                        * v28 = yTop;
                    v31 = v28 + 1;
                    v32 = v29 + 1;
                    v33 = v30 - 1;
                    if (v33 > 0)
                    {
                        if (v32 >= v13 && v32 < v14 && v21 & 8)
                            * v31 = yTop;
                        v34 = v31 + 1;
                        v35 = v32 + 1;
                        v36 = v33 - 1;
                        if (v36 > 0)
                        {
                            if (v35 >= v13 && v35 < v14 && v21 & 4)
                                * v34 = yTop;
                            v37 = v34 + 1;
                            v38 = v35 + 1;
                            v39 = v36 - 1;
                            if (v39 > 0)
                            {
                                if (v38 >= v13 && v38 < v14 && v21 & 2)
                                    * v37 = yTop;
                                v40 = v37 + 1;
                                v41 = v38 + 1;
                                v42 = v39 - 1;
                                if (v42 > 0)
                                {
                                    if (v41 >= v13 && v41 < v14 && v21 & 1)
                                        * v40 = yTop;
                                    v18 = v40 + 1;
                                    v20 = v41 + 1;
                                    v17 = v42 - 1;
                                    goto LABEL_58;
                                }
                            }
                        }
                    }
                }
            }
        }
        LABEL_59:
        v43 = v68 == 1;
        v66 += *(_DWORD*)(a1 + 4);
        --v68;
        if (!v43)
        {
            v15 = xLeft;
            v16 = v70;
            continue;
        }
        break;
    }
    LABEL_60:
    if (*(_DWORD*)& byte_5D4594[816452])
    {
        sub_49D190(ptr_5D4594_3799572->data[59], xLeft, v71, v67, v72.field_C - v72.field_4);
        *(_DWORD*)& byte_5D4594[816452] = 0;
        sub_43FE90(a1, a2, xLeft, v71);
        *(_DWORD*)& byte_5D4594[816452] = 1;
    }
    return xLeft + *(_DWORD*)& byte_5D4594[816440] + v67;
}
// 43FEE1: variable 'v4' is possibly undefined

//----- (00440360) --------------------------------------------------------
int __cdecl sub_440360(int a1, int a2, int xLeft, int yTop)
{
    unsigned __int8* v5; // eax
    int v6; // eax
    int v7; // esi
    int v8; // ebx
    int v9; // ecx
    int v10; // eax
    int v11; // edi
    int v12; // ebp
    int v13; // ebx
    int v14; // edi
    int v15; // esi
    int v16; // ecx
    _BYTE* v17; // eax
    char* v18; // edi
    char v19; // dl
    _BYTE* v20; // eax
    int v21; // ecx
    int v22; // esi
    _BYTE* v23; // eax
    int v24; // ecx
    int v25; // esi
    _BYTE* v26; // eax
    int v27; // ecx
    int v28; // esi
    _BYTE* v29; // eax
    int v30; // ecx
    int v31; // esi
    _BYTE* v32; // eax
    int v33; // ecx
    int v34; // esi
    _BYTE* v35; // eax
    int v36; // ecx
    int v37; // esi
    _BYTE* v38; // eax
    int v39; // ecx
    int v40; // esi
    bool v41; // zf
    int v42; // edi
    int v43; // eax
    int v44; // esi
    int v45; // ebp
    int v46; // esi
    char* v47; // edi
    int v48; // ecx
    _BYTE* v49; // eax
    char v50; // dl
    _BYTE* v51; // eax
    int v52; // ecx
    _BYTE* v53; // eax
    int v54; // ecx
    _BYTE* v55; // eax
    int v56; // ecx
    _BYTE* v57; // eax
    int v58; // ecx
    _BYTE* v59; // eax
    int v60; // ecx
    _BYTE* v61; // eax
    int v62; // ecx
    _BYTE* v63; // eax
    int v64; // ecx
    char v65; // [esp+13h] [ebp-35h]
    char* v66; // [esp+14h] [ebp-34h]
    int v67; // [esp+18h] [ebp-30h]
    int v68; // [esp+1Ch] [ebp-2Ch]
    int v69; // [esp+20h] [ebp-28h]
    int v70; // [esp+24h] [ebp-24h]
    int4 v71; // [esp+28h] [ebp-20h]
    RECT rc; // [esp+38h] [ebp-10h]
    int yTopa; // [esp+58h] [ebp+10h]

    v70 = yTop;
    if ((_WORD)a2 == 9)
        return *(_DWORD*)& byte_5D4594[816456]
                           + xLeft
                           - (*(_DWORD*)& byte_5D4594[816456] + xLeft - *(_DWORD*)& byte_5D4594[816460]) % *(_DWORD*)& byte_5D4594[816456];
    v65 = *(_BYTE*)(&ptr_5D4594_3799572->data[59]);
    v5 = (unsigned __int8*)sub_43FE30(a1, a2);
    if (!v5)
    {
        LOWORD(v6) = sub_4408C0(&v65);
        a2 = v6;
        v5 = (unsigned __int8*)sub_43FE30(a1, v6);
        if (!v5)
            return xLeft;
    }
    v7 = *(_DWORD*)(a1 + 8);
    v8 = *v5;
    v9 = (int)(v5 + 1);
    v10 = ptr_5D4594_3799572->data[0];
    v66 = (char*)v9;
    v67 = v8;
    if (!v10)
        goto LABEL_100;
    SetRect(&rc, xLeft, yTop, v8 + xLeft, v7 + yTop);
    if (!sub_49F930(&v71, (int4*)& rc, (int4*)(&ptr_5D4594_3799572->data[1])))
        return xLeft + v8 + *(_DWORD*)& byte_5D4594[816440];
    if (rc.left == v71.field_0 && rc.right == v71.field_8 && rc.top == v71.field_4 && rc.bottom == v71.field_C)
    {
        LABEL_100:
        v43 = v7;
        v44 = v7 - 1;
        if (!v43)
        {
            LABEL_95:
            if (*(_DWORD*)& byte_5D4594[816452])
            {
                sub_49D190(ptr_5D4594_3799572->data[59], xLeft, yTop, v67, *(_DWORD*)(a1 + 8));
                *(_DWORD*)& byte_5D4594[816452] = 0;
                sub_440360(a1, a2, xLeft, yTop);
                *(_DWORD*)& byte_5D4594[816452] = 1;
            }
            return xLeft + *(_DWORD*)& byte_5D4594[816440] + v67;
        }
        v45 = 4 * yTop;
        v46 = v44 + 1;
        LABEL_66:
        v47 = v66;
        v48 = v67;
        v49 = (_BYTE*)(xLeft + *(_DWORD*)(*(_DWORD*)& byte_5D4594[3798784] + v45));
        v45 += 4;
        while (1)
        {
            v50 = *v47++;
            if (v50)
            {
                if (v50 < 0)
                    * v49 = v65;
                v51 = v49 + 1;
                v52 = v48 - 1;
                if (v52 <= 0)
                    goto LABEL_94;
                if (v50 & 0x40)
                    * v51 = v65;
                v53 = v51 + 1;
                v54 = v52 - 1;
                if (v54 <= 0)
                    goto LABEL_94;
                if (v50 & 0x20)
                    * v53 = v65;
                v55 = v53 + 1;
                v56 = v54 - 1;
                if (v56 <= 0)
                    goto LABEL_94;
                if (v50 & 0x10)
                    * v55 = v65;
                v57 = v55 + 1;
                v58 = v56 - 1;
                if (v58 <= 0)
                    goto LABEL_94;
                if (v50 & 8)
                    * v57 = v65;
                v59 = v57 + 1;
                v60 = v58 - 1;
                if (v60 <= 0)
                    goto LABEL_94;
                if (v50 & 4)
                    * v59 = v65;
                v61 = v59 + 1;
                v62 = v60 - 1;
                if (v62 <= 0)
                    goto LABEL_94;
                if (v50 & 2)
                    * v61 = v65;
                v63 = v61 + 1;
                v64 = v62 - 1;
                if (v64 <= 0)
                {
                    LABEL_94:
                    --v46;
                    v66 += *(_DWORD*)(a1 + 4);
                    if (!v46)
                        goto LABEL_95;
                    goto LABEL_66;
                }
                if (v50 & 1)
                    * v63 = v65;
                v49 = v63 + 1;
                v48 = v64 - 1;
            }
            else
            {
                v49 += 8;
                v48 -= 8;
            }
            if (v48 <= 0)
                goto LABEL_94;
        }
    }
    v11 = v71.field_4 - rc.top + yTop;
    v66 += *(_DWORD*)(a1 + 4) * (v71.field_4 - rc.top);
    v12 = ptr_5D4594_3799572->data[1];
    v13 = ptr_5D4594_3799572->data[3];
    yTopa = ptr_5D4594_3799572->data[3];
    if (v71.field_C == v71.field_4)
        goto LABEL_61;
    v14 = 4 * v11;
    v68 = v71.field_C - v71.field_4;
    while (2)
    {
        v15 = v67;
        v16 = xLeft;
        v17 = (_BYTE*)(xLeft + *(_DWORD*)(v14 + *(_DWORD*)& byte_5D4594[3798784]));
        v69 = v14 + 4;
        v18 = v66;
        while (1)
        {
            v19 = *v18++;
            if (v19)
                break;
            v17 += 8;
            v15 -= 8;
            v16 += 8;
            LABEL_59:
            if (v15 <= 0)
                goto LABEL_60;
        }
        if (v16 >= v12 && v16 < v13 && v19 < 0)
        {
            *v17 = v65;
            v13 = yTopa;
        }
        v20 = v17 + 1;
        v21 = v16 + 1;
        v22 = v15 - 1;
        if (v22 > 0)
        {
            if (v21 >= v12 && v21 < v13 && v19 & 0x40)
            {
                *v20 = v65;
                v13 = yTopa;
            }
            v23 = v20 + 1;
            v24 = v21 + 1;
            v25 = v22 - 1;
            if (v25 > 0)
            {
                if (v24 >= v12 && v24 < v13 && v19 & 0x20)
                {
                    *v23 = v65;
                    v13 = yTopa;
                }
                v26 = v23 + 1;
                v27 = v24 + 1;
                v28 = v25 - 1;
                if (v28 > 0)
                {
                    if (v27 >= v12 && v27 < v13 && v19 & 0x10)
                    {
                        *v26 = v65;
                        v13 = yTopa;
                    }
                    v29 = v26 + 1;
                    v30 = v27 + 1;
                    v31 = v28 - 1;
                    if (v31 > 0)
                    {
                        if (v30 >= v12 && v30 < v13 && v19 & 8)
                        {
                            *v29 = v65;
                            v13 = yTopa;
                        }
                        v32 = v29 + 1;
                        v33 = v30 + 1;
                        v34 = v31 - 1;
                        if (v34 > 0)
                        {
                            if (v33 >= v12 && v33 < v13 && v19 & 4)
                            {
                                *v32 = v65;
                                v13 = yTopa;
                            }
                            v35 = v32 + 1;
                            v36 = v33 + 1;
                            v37 = v34 - 1;
                            if (v37 > 0)
                            {
                                if (v36 >= v12 && v36 < v13 && v19 & 2)
                                {
                                    *v35 = v65;
                                    v13 = yTopa;
                                }
                                v38 = v35 + 1;
                                v39 = v36 + 1;
                                v40 = v37 - 1;
                                if (v40 > 0)
                                {
                                    if (v39 >= v12 && v39 < v13 && v19 & 1)
                                        * v38 = v65;
                                    v17 = v38 + 1;
                                    v16 = v39 + 1;
                                    v15 = v40 - 1;
                                    goto LABEL_59;
                                }
                            }
                        }
                    }
                }
            }
        }
        LABEL_60:
        v41 = v68 == 1;
        v66 += *(_DWORD*)(a1 + 4);
        --v68;
        if (!v41)
        {
            v14 = v69;
            continue;
        }
        break;
    }
    LABEL_61:
    if (*(_DWORD*)& byte_5D4594[816452])
    {
        v42 = v70;
        sub_49D190(ptr_5D4594_3799572->data[59], xLeft, v70, v67, v71.field_C - v71.field_4);
        *(_DWORD*)& byte_5D4594[816452] = 0;
        sub_440360(a1, a2, xLeft, v42);
        *(_DWORD*)& byte_5D4594[816452] = 1;
    }
    return xLeft + *(_DWORD*)& byte_5D4594[816440] + v67;
}
// 4403CC: variable 'v6' is possibly undefined

//----- (004407F0) --------------------------------------------------------
int __cdecl sub_4407F0(int a1, __int16* a2, int a3, int a4)
{
    __int16 v4; // cx
    __int16* v5; // esi
    int result; // eax

    v4 = *a2;
    v5 = a2 + 1;
    if (!*a2)
        return a3;
    result = a3;
    do
    {
        if (v4 != 13 && v4 != 10)
            result = (*(int(__cdecl * *)(_DWORD, _WORD, _DWORD, _DWORD)) & byte_5D4594[816448])(a1, v4, result, a4);
        v4 = *v5;
        ++v5;
    } while (v4);
    return result;
}

//----- (00440840) --------------------------------------------------------
void __cdecl sub_440840(LPVOID lpMem)
{
    if (*((_DWORD*)lpMem + 4))
    free(*((LPVOID*)lpMem + 4));
    if (*((_DWORD*)lpMem + 6))
    free(*((LPVOID*)lpMem + 6));
    free(lpMem);
}

//----- (00440870) --------------------------------------------------------
int __cdecl sub_440870(int a1)
{
    int result; // eax
    int v2; // edx
    unsigned __int16* v3; // ecx
    int v4; // esi

    result = 0;
    v2 = *(_DWORD*)(a1 + 12);
    if (v2 > 0)
    {
        v3 = (unsigned __int16*)(*(_DWORD*)(a1 + 16) + 4);
        do
        {
            v4 = v3[1] - *v3;
            v3 += 4;
            --v2;
            result += v4 + 1;
        } while (v2);
    }
    return result;
}

//----- (004408A0) --------------------------------------------------------
__int16 __cdecl sub_4408A0(_WORD* a1)
{
    if (byte_5D4594[3798652] & 8)
        * a1 ^= 0x5555u;
    return 63;
}

//----- (004408C0) --------------------------------------------------------
__int16 __cdecl sub_4408C0(_BYTE* a1)
{
    if (byte_5D4594[3798652] & 8)
        * a1 ^= 0x55u;
    return 63;
}

//----- (004408E0) --------------------------------------------------------
int sub_4408E0()
{
    return 1;
}

//----- (00440900) --------------------------------------------------------
void sub_440900()
{
    _DWORD** dst = *(_DWORD * **)& byte_5D4594[3798784];
    int val = ptr_5D4594_3799572->data[58];
    for (int y = 0; y < nox_backbuffer_height; y++)
    {
        _DWORD* row = *dst;
        for (int x = 0; x < nox_backbuffer_width32; x++)
        {
            for (int i = 0; i < 8; i++)
                row[i] = val;
            row += 8;
        }
        ++dst;
    }
}

//----- (00440950) --------------------------------------------------------
int __cdecl sub_440950(char a1, wchar_t* a2)
{
    char v3[516]; // [esp+4h] [ebp-204h]

    v3[0] = -69;
    v3[1] = a1;
    *(_WORD*)& v3[2] = *(_WORD*)& byte_5D4594[2616328];
    v3[4] = 0;
    *(_WORD*)& v3[5] = 0;
    if (a2)
    {
        v3[4] = nox_wcslen(a2) + 1;
        nox_wcscpy((wchar_t*)& v3[5], a2);
    }
    return sub_4E53C0(31, v3, 2 * (unsigned __int8)v3[4] + 7, 0, 1);
}

//----- (004409D0) --------------------------------------------------------
int __cdecl sub_4409D0(wchar_t* a1)
{
    char v2[21]; // [esp+0h] [ebp-18h]

    v2[0] = -68;
    nox_wcsncpy((wchar_t*)& v2[1], a1, 8u);
    *(_WORD*)& v2[17] = 0;
    *(_WORD*)& v2[19] = *(_WORD*)& byte_5D4594[2616328];
    return sub_4E53C0(31, v2, 21, 0, 1);
}

//----- (00440A20) --------------------------------------------------------
void sub_440A20(wchar_t* a1, ...)
{
    va_list va; // [esp+8h] [ebp+8h]

    va_start(va, a1);
    nox_vswprintf((wchar_t*)& byte_5D4594[822660], a1, va);
    sub_445490((wchar_t*)& byte_5D4594[822660]);
}

//----- (00440A50) --------------------------------------------------------
int __cdecl sub_440A50(int a1, char a2, int a3)
{
    int v3; // esi

    if (a2 != 3)
        return 0;
    if (nox_wcslen(*(const wchar_t**)(a3 + 4)) >= 0x20)
        return 0;
    v3 = sub_440AC0(*(wchar_t**)(a3 + 4));
    if (v3 == -1 || nox_wcslen(*(const wchar_t**)(a3 + 8)) >= 0x80)
        return 0;
    nox_wcscpy((wchar_t*)& byte_587000[76 * v3 + 94516], *(const wchar_t**)(a3 + 8));
    return 1;
}

//----- (00440AC0) --------------------------------------------------------
int __cdecl sub_440AC0(wchar_t* a1)
{
    int v1; // edi
    const wchar_t** v2; // esi

    v1 = 0;
    v2 = (const wchar_t**)& byte_587000[94504];
    while (_nox_wcsicmp(a1, *v2))
    {
        v2 += 19;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[95416])
            return -1;
    }
    return v1;
}

//----- (00440B00) --------------------------------------------------------
int __cdecl sub_440B00(int a1, char a2, int a3)
{
    int v3; // eax

    if (a2 != 2)
        return 0;
    if (nox_wcslen(*(const wchar_t**)(a3 + 4)) >= 0x20)
        return 0;
    v3 = sub_440AC0(*(wchar_t**)(a3 + 4));
    if (v3 == -1)
        return 0;
    *(_WORD*)& byte_587000[76 * v3 + 94516] = 0;
    return 1;
}

//----- (00440B50) --------------------------------------------------------
int __cdecl sub_440B50(int a1, unsigned __int8 a2, int a3)
{
    int result; // eax
    wchar_t v4[128]; // [esp+0h] [ebp-100h]

    if (a2 == 1)
        return 0;
    result = sub_440BC0(a1, a2, a3);
    if (result)
    {
        nox_swprintf(v4, L"%S", result);
        sub_440950(5, v4);
        result = 1;
    }
    return result;
}

//----- (00440BC0) --------------------------------------------------------
char* __cdecl sub_440BC0(int a1, unsigned __int8 a2, int a3)
{
    int v3; // ebx
    unsigned int v5; // edx
    unsigned __int8* v6; // edi
    unsigned __int8* v7; // edi
    char* v8; // esi
    char v9; // cl
    int v10; // edx
    _DWORD* v11; // [esp+8h] [ebp-84h]
    char v12[128]; // [esp+Ch] [ebp-80h]

    v3 = a1;
    if (a1 == a2)
        return 0;
    byte_5D4594[818100] = 0;
    if (a1 < a2)
    {
        v11 = (_DWORD*)(a3 + 4 * a1);
        do
        {
            nox_sprintf(v12, "%S", *v11);
            v5 = strlen(v12) + 1;
            v6 = &byte_5D4594[strlen((const char*)& byte_5D4594[818100]) + 818100];
            qmemcpy(v6, v12, 4 * (v5 >> 2));
            v8 = &v12[4 * (v5 >> 2)];
            v7 = &v6[4 * (v5 >> 2)];
            v9 = v5;
            v10 = v3 + 1;
            qmemcpy(v7, v8, v9 & 3);
            if (v3 + 1 < a2)
                * (_WORD*)& byte_5D4594[strlen((const char*)& byte_5D4594[818100]) + 818100] = *(_WORD*)& byte_587000[101624];
            ++v3;
            ++v11;
        } while (v10 < a2);
    }
    return (char*)& byte_5D4594[818100];
}
// 440BC0: using guessed type char var_80[128];

//----- (00440C90) --------------------------------------------------------
int __cdecl sub_440C90(int a1, char a2)
{
    if (a2 == 1)
        return 0;
    sub_46A4B0((wchar_t*)(*(_DWORD*)& byte_5D4594[823700] + 8), 0);
    return 1;
}

//----- (00440CC0) --------------------------------------------------------
int __cdecl sub_440CC0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_4185B0();
    return 1;
}

//----- (00440CE0) --------------------------------------------------------
int __cdecl sub_440CE0(int a1, char a2, int a3)
{
    int result; // eax
    char* v4; // ebx
    const wchar_t* v5; // eax
    int v6; // edi
    unsigned __int8* v7; // esi

    if (a2 != 3)
        return 0;
    result = (int)& byte_5D4594[822660];
    if (byte_5D4594 != (unsigned __int8*)-822660)
    {
        v4 = sub_416590(1);
        v5 = *(const wchar_t**)& byte_587000[94400];
        v6 = 0;
        if (*(_DWORD*)& byte_587000[94400])
        {
            v7 = &byte_587000[94400];
            while (_nox_wcsicmp(v5, *(const wchar_t**)(a3 + 4 * a1)))
            {
                v5 = (const wchar_t*) * ((_DWORD*)v7 + 2);
                v7 += 8;
                ++v6;
                if (!v5)
                    return 1;
            }
            *((_WORD*)v4 + 26) &= 0xE80Fu;
            *((_WORD*)v4 + 26) |= *(_WORD*)& byte_587000[8 * v6 + 94404];
        }
        result = 1;
    }
    return result;
}

//----- (00440D70) --------------------------------------------------------
int sub_440D70()
{
    *(_DWORD*)& byte_587000[94464] = 0;
    return 1;
}

//----- (00440D80) --------------------------------------------------------
int __cdecl sub_440D80(int a1, char a2, int a3)
{
    wchar_t* v4; // eax

    if (a2 != 2)
        return 0;
    sub_450B20(*(wchar_t**)(a3 + 4));
    sub_450B70();
    v4 = loadString_sub_40F1D0((char*)& byte_587000[101668], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1329);
    sub_450C00(4u, v4);
    return 1;
}

//----- (00440DD0) --------------------------------------------------------
int __cdecl sub_440DD0(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 1)
        return 0;
    sub_450B50();
    v3 = loadString_sub_40F1D0((char*)& byte_587000[101724], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1340);
    sub_450C00(4u, v3);
    return 1;
}

//----- (00440E10) --------------------------------------------------------
int __cdecl sub_440E10(int a1, char a2, int a3)
{
    wchar_t* v4; // eax

    if (a2 != 3)
        return 0;
    sub_40A610(*(wchar_t**)(a3 + 4 * a1));
    v4 = loadString_sub_40F1D0((char*)& byte_587000[101780], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1352);
    sub_450C00(6u, v4);
    return 1;
}

//----- (00440E60) --------------------------------------------------------
int __cdecl sub_440E60(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 2)
        return 0;
    if (!sub_40A5C0(2048))
    {
        sub_579830();
        v3 = loadString_sub_40F1D0((char*)& byte_587000[101840], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1368);
        sub_450C00(6u, v3);
    }
    return 1;
}

//----- (00440EB0) --------------------------------------------------------
int __cdecl sub_440EB0(int a1, unsigned __int8 a2, int a3)
{
    unsigned __int16 v4; // ax
    wchar_t* v5; // eax
    int v6; // [esp-4h] [ebp-8h]

    if (a2 < 2u || a2 > 3u)
        return 0;
    if (sub_40A5C0(2048))
        return 1;
    if (a2 == 2)
    {
        sub_5797F0(0);
    }
    else
    {
        v4 = nox_wcstol(*(const wchar_t**)(a3 + 4 * a2 - 4), 0, 10);
        sub_5797F0(v4);
    }
    v6 = sub_579850();
    v5 = loadString_sub_40F1D0((char*)& byte_587000[101892], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1388);
    sub_450C00(6u, v5, v6);
    return 1;
}

//----- (00440F50) --------------------------------------------------------
int __cdecl sub_440F50(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 2)
        return 0;
    *(_DWORD*)& byte_587000[95416] = 1;
    v3 = loadString_sub_40F1D0((char*)& byte_587000[101944], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1400);
    sub_450C00(6u, v3);
    return 1;
}

//----- (00440F90) --------------------------------------------------------
int __cdecl sub_440F90(int a1, char a2)
{
    wchar_t* v3; // eax

    if (a2 != 2)
        return 0;
    *(_DWORD*)& byte_587000[95416] = 0;
    v3 = loadString_sub_40F1D0((char*)& byte_587000[101996], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1411);
    sub_450C00(6u, v3);
    return 1;
}

//----- (00440FD0) --------------------------------------------------------
int __cdecl sub_440FD0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_43DDE0(1);
    return 1;
}

//----- (00440FF0) --------------------------------------------------------
int __cdecl sub_440FF0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_43DDE0(0);
    return 1;
}

//----- (00441010) --------------------------------------------------------
int __cdecl sub_441010(int a1, char a2)
{
    int v3; // eax

    if (a2 != 2)
        return 0;
    v3 = *(_DWORD*)& byte_5D4594[2650636];
    BYTE1(v3) |= 0x80u;
    *(_DWORD*)& byte_5D4594[2650636] = v3;
    return 1;
}

//----- (00441030) --------------------------------------------------------
int __cdecl sub_441030(int a1, char a2)
{
    int v3; // eax

    if (a2 != 2)
        return 0;
    v3 = *(_DWORD*)& byte_5D4594[2650636];
    BYTE1(v3) &= 0x7Fu;
    *(_DWORD*)& byte_5D4594[2650636] = v3;
    return 1;
}

//----- (00441050) --------------------------------------------------------
int sub_441050()
{
    wchar_t* v0; // ebx
    wchar_t* v1; // ebp
    char** v2; // edi
    int v3; // eax
    int v4; // esi
    wchar_t* v5; // eax
    int v7; // [esp-Ch] [ebp-18h]
    wchar_t* v8; // [esp-8h] [ebp-14h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102048], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1460);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102096], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1461);
    v2 = (char**)sub_4E3B30();
    if (!v2)
        return 1;
    do
    {
        if ((unsigned int)v2[6] & 0x1000000)
        {
            v3 = sub_415910(v2[1]);
            v4 = sub_4159F0(v3);
            if (v4)
            {
                if (sub_4E3BA0(*(unsigned __int16*)v2))
                {
                    v8 = v0;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102148], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1475);
                }
                else
                {
                    v8 = v1;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102200], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1477);
                }
                sub_450C00(6u, v5, v7, v8);
            }
        }
        v2 = (char**)sub_4E3B40((int)v2);
    } while (v2);
    return 1;
}

//----- (00441130) --------------------------------------------------------
int sub_441130()
{
    wchar_t* v0; // ebx
    wchar_t* v1; // ebp
    char** v2; // edi
    int v3; // eax
    int v4; // esi
    wchar_t* v5; // eax
    int v7; // [esp-Ch] [ebp-18h]
    wchar_t* v8; // [esp-8h] [ebp-14h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102252], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1492);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102300], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1493);
    v2 = (char**)sub_4E3B30();
    if (!v2)
        return 1;
    do
    {
        if ((unsigned int)v2[6] & 0x2000000)
        {
            v3 = sub_415DF0(v2[1]);
            v4 = sub_415E80(v3);
            if (v4)
            {
                if (sub_4E3BA0(*(unsigned __int16*)v2))
                {
                    v8 = v0;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102352], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1508);
                }
                else
                {
                    v8 = v1;
                    v7 = v4;
                    v5 = loadString_sub_40F1D0((char*)& byte_587000[102404], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1510);
                }
                sub_450C00(6u, v5, v7, v8);
            }
        }
        v2 = (char**)sub_4E3B40((int)v2);
    } while (v2);
    return 1;
}

//----- (00441210) --------------------------------------------------------
int sub_441210()
{
    wchar_t* v0; // edi
    wchar_t* v1; // ebx
    int v2; // esi
    wchar_t* v3; // eax
    int v5; // [esp-Ch] [ebp-18h]
    int v6; // [esp-8h] [ebp-14h]
    wchar_t* v7; // [esp-4h] [ebp-10h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102456], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1524);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102504], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1525);
    v2 = 1;
    do
    {
        if (sub_424B50(v2))
        {
            if (sub_424B70(v2))
            {
                v7 = v0;
                v6 = sub_4249A0(v2, 1);
                v5 = sub_424930(v2);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[102556], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1531);
            }
            else
            {
                v7 = v1;
                v6 = sub_4249A0(v2, 1);
                v5 = sub_424930(v2);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[102608], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1533);
            }
            sub_450C00(6u, v3, v5, v6, v7);
        }
        ++v2;
    } while (v2 < 137);
    return 1;
}

//----- (004412E0) --------------------------------------------------------
int sub_4412E0()
{
    wchar_t* v0; // ebx
    wchar_t* v1; // ebp
    unsigned __int16* v2; // edi
    int v3; // eax
    int v4; // eax
    int v5; // esi
    wchar_t* v6; // eax
    int v8; // [esp-Ch] [ebp-18h]
    wchar_t* v9; // [esp-8h] [ebp-14h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[102660], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1588);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[102708], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1589);
    v2 = (unsigned __int16*)sub_4E3B30();
    if (!v2)
        return 1;
    do
    {
        v3 = *((_DWORD*)v2 + 6);
        if (v3 & 0x1000)
        {
            v4 = sub_415910(*((char**)v2 + 1));
            v5 = sub_4159F0(v4);
            if (v5)
            {
                if (sub_4E3BA0(*v2))
                {
                    v9 = v0;
                    v8 = v5;
                    v6 = loadString_sub_40F1D0((char*)& byte_587000[102760], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1604);
                }
                else
                {
                    v9 = v1;
                    v8 = v5;
                    v6 = loadString_sub_40F1D0((char*)& byte_587000[102812], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1606);
                }
                sub_450C00(6u, v6, v8, v9);
            }
        }
        v2 = (unsigned __int16*)sub_4E3B40((int)v2);
    } while (v2);
    return 1;
}

//----- (004413C0) --------------------------------------------------------
int __cdecl sub_4413C0(int a1, char a2)
{
    unsigned __int8* v3; // esi
    wchar_t* v4; // eax

    if (a2 != 2)
        return 0;
    v3 = &byte_587000[94516];
    do
    {
        if (*(_WORD*)v3)
            sub_450C00(4u, (wchar_t*)& byte_587000[102824], *((_DWORD*)v3 - 2), v3);
        v3 += 76;
    } while ((int)v3 < (int)& byte_587000[95428]);
    if (*(_DWORD*)& byte_587000[95416])
        v4 = loadString_sub_40F1D0((char*)& byte_587000[102880], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1630);
    else
        v4 = loadString_sub_40F1D0((char*)& byte_587000[102932], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1632);
    sub_450C00(4u, v4);
    return 1;
}

//----- (00441440) --------------------------------------------------------
int sub_441440()
{
    *(_DWORD*)& byte_5D4594[2650636] ^= 8u;
    return 1;
}

//----- (00441460) --------------------------------------------------------
int sub_441460()
{
    int v0; // eax

    v0 = *(_DWORD*)& byte_587000[80828] ^ 1;
    *(_DWORD*)& byte_587000[80828] = v0;
    *(_DWORD*)& byte_587000[80832] = v0;
    return 1;
}

//----- (00441480) --------------------------------------------------------
int sub_441480()
{
    sub_452D80(921, 100);
    *(_DWORD*)& byte_5D4594[2650636] ^= 2u;
    return 1;
}

//----- (004414B0) --------------------------------------------------------
int sub_4414B0()
{
    sub_452D80(921, 100);
    sub_435F40();
    return 1;
}

//----- (004414D0) --------------------------------------------------------
int sub_4414D0()
{
    sub_470A60();
    return 1;
}

//----- (004414E0) --------------------------------------------------------
int sub_4414E0()
{
    sub_452D80(921, 100);
    sub_435F60();
    return 1;
}

//----- (00441500) --------------------------------------------------------
int sub_441500()
{
    sub_409B30();
    sub_413E30();
    return 1;
}

//----- (00441530) --------------------------------------------------------
int sub_441530()
{
    if (sub_40A5C0(0x2000))
        sub_4703F0();
    return 1;
}

//----- (00441550) --------------------------------------------------------
int __cdecl sub_441550(int a1, char a2)
{
    char* v2; // esi
    int v4; // edi
    int v5; // eax
    wchar_t* v6; // eax
    __int16 v7; // ax
    wchar_t* v8; // eax
    wchar_t* v9; // eax
    struct in_addr v10; // eax
    char* v11; // eax
    char* v12; // [esp-18h] [ebp-5Ch]
    int v13; // [esp-10h] [ebp-54h]
    int v14; // [esp-Ch] [ebp-50h]
    char* v15; // [esp-8h] [ebp-4Ch]
    int v16; // [esp-8h] [ebp-4Ch]
    int v17; // [esp-8h] [ebp-4Ch]
    wchar_t v18[32]; // [esp+4h] [ebp-40h]

    v2 = sub_4165B0();
    if (a2 != 2)
        return 0;
    v4 = sub_416F40();
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
        --v4;
    v5 = sub_409AC0();
    sub_450C00(6u, (wchar_t*)& byte_587000[102952], &byte_587000[102944], v5);
    if (sub_40A5C0(0x2000))
    {
        v15 = sub_40A4C0();
        v6 = loadString_sub_40F1D0((char*)& byte_587000[103020], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1801);
        sub_450C00(6u, (wchar_t*)& byte_587000[103028], v6, v15);
        v7 = sub_40A5B0();
        v16 = sub_4573C0(v7);
        v8 = loadString_sub_40F1D0((char*)& byte_587000[103080], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1802);
        sub_450C00(6u, (wchar_t*)& byte_587000[103088], v8, v16);
        v17 = sub_40A180(*((_WORD*)v2 + 26));
        v14 = (unsigned __int16)sub_40A020(*((_WORD*)v2 + 26));
        v13 = sub_409FA0();
        v12 = sub_409B30();
        v9 = loadString_sub_40F1D0((char*)& byte_587000[103140], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1803);
        sub_450C00(6u, v9, v12, v4, v13, v14, v17);
        v10.S_un.S_addr = sub_554200(0);
        v11 = inet_ntoa(v10);
        nox_swprintf(v18, L"%S", v11);
        sub_450C00(6u, (wchar_t*)& byte_587000[103160], v18);
    }
    return 1;
}

//----- (004416B0) --------------------------------------------------------
int __cdecl sub_4416B0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_4467F0();
    return 1;
}

//----- (004416D0) --------------------------------------------------------
int __cdecl sub_4416D0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_48D7B0();
    return 1;
}

//----- (004416F0) --------------------------------------------------------
int sub_4416F0()
{
    wchar_t* v0; // eax

    if (*(_DWORD*)& byte_5D4594[805836])
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103208], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1869);
    else
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103260], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1871);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00441740) --------------------------------------------------------
int sub_441740()
{
    int* v0; // esi
    int i; // edi
    bool v2; // zf
    signed int v3; // edi

    memset(&byte_5D4594[822404], 0, 0x100u);
    v0 = sub_4D09B0();
    for (i = 1; v0; ++i)
    {
        sub_4417E0((wchar_t*)& byte_5D4594[822404], (const char*)v0 + 12);
        if (!(i % 4))
        {
            sub_450C00(6u, (wchar_t*)& byte_587000[103276], &byte_5D4594[822404]);
            *(_WORD*)& byte_5D4594[822404] = 0;
        }
        v0 = sub_4D09C0(v0);
    }
    v3 = (i - 1) & 0x80000003;
    v2 = v3 == 0;
    if (v3 < 0)
        v2 = (((_BYTE)v3 - 1) | 0xFFFFFFFC) == (unsigned int)-1;
    if (!v2)
        sub_450C00(6u, (wchar_t*)& byte_587000[103284], &byte_5D4594[822404]);
    return 1;
}

//----- (004417E0) --------------------------------------------------------
void __cdecl sub_4417E0(wchar_t* a1, const char* a2)
{
    unsigned __int8 v2; // dl
    char* v3; // edi
    char v4[64]; // [esp+4h] [ebp-C0h]
    wchar_t v5[64]; // [esp+44h] [ebp-80h]

    if (a2)
    {
        strcpy(v4, a2);
        v2 = byte_587000[103296];
        v3 = &v4[strlen(v4)];
        *(_DWORD*)v3 = *(_DWORD*)& byte_587000[103292];
        v3[4] = v2;
        nox_swprintf(v5, L"%-20.20S\t\t", v4);
        nox_wcscat(a1, v5);
    }
}
// 4417E0: using guessed type char var_C0[64];

//----- (00441870) --------------------------------------------------------
int __cdecl sub_441870(int a1, char a2, int a3)
{
    int result; // eax
    char v4[256]; // [esp+0h] [ebp-100h]

    result = 0;
    if (a2 == 3)
    {
        if (*(_DWORD*)(a3 + 8))
        {
            *(_DWORD*)& byte_5D4594[2650636] |= 0x800000;
            nox_sprintf(v4, "%S", *(_DWORD*)(a3 + 8));
            result = sub_413A80(v4);
        }
    }
    return result;
}

//----- (004418D0) --------------------------------------------------------
int __cdecl sub_4418D0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    *(_DWORD*)& byte_5D4594[2650636] |= 0x1000000u;
    return 1;
}

//----- (004418F0) --------------------------------------------------------
int __cdecl sub_4418F0(int a1, char a2)
{
    if (a2 != 2)
        return 0;
    sub_413C00();
    return 1;
}

//----- (00441910) --------------------------------------------------------
int __cdecl sub_441910(int a1, char a2, int a3)
{
    int v4; // eax
    int v5; // ebx
    wchar_t* v6; // eax
    unsigned int v7; // kr04_4
    char* v8; // ebx
    wchar_t* v9; // eax
    char* v10; // [esp-4h] [ebp-234h]
    char v11[260]; // [esp+8h] [ebp-228h]
    struct _stat v12; // [esp+10Ch] [ebp-124h]
    CHAR FileName[256]; // [esp+130h] [ebp-100h]

    if (sub_40A5C0(4096))
        return 1;
    if (a2 != 2)
        return 0;
    nox_sprintf(&v11[4], "%S", *(_DWORD*)(a3 + 4));
    if (v11[4] != 35 && !sub_4CFE10(&v11[4]))
        return 1;
    v4 = sub_4CFFA0((int)& byte_5D4594[3801836]);
    v5 = v4;
    if (sub_40A5C0(0x2000))
    {
        if (v5 && !(v5 & 0x200))
        {
            if (sub_40A5C0(128))
            {
                if (v5 & 0x60 && sub_417DD0() != 2)
                    sub_4185B0();
            }
            else if (!(sub_40A5B0() & v5))
            {
                v6 = loadString_sub_40F1D0((char*)& byte_587000[103372], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2005);
                sub_440A20(v6);
                return 1;
            }
            goto LABEL_16;
        }
    }
    else if (v5 & 0x200)
    {
        LABEL_16:
        v7 = strlen(&v11[4]) + 1;
        if ((int)(v7 - 1) <= 4 || _strcmpi(&v11[v7 - 1], ".map"))
        {
            strcpy((char*)& byte_5D4594[822324], &v11[4]);
            v8 = (char*)& byte_5D4594[822324];
            strcat((char*)& byte_5D4594[822324], ".map");
        }
        else
        {
            v8 = &v11[4];
        }
        if (!v8
            || *v8 != 35
               && (strcpy(FileName, "maps\\"),
                strncat(FileName, v8, strlen(v8) - 4),
                *(_WORD*)& FileName[strlen(FileName)] = *(_WORD*)& byte_587000[103416],
                strcat(FileName, v8),
                _stat(FileName, (int)& v12)))
        {
            v10 = v8;
            v9 = loadString_sub_40F1D0((char*)& byte_587000[103512], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2076);
        }
        else
        {
            sub_4DCC70(1);
            sub_4D2450(v8);
            sub_41D650();
            v10 = v8;
            v9 = loadString_sub_40F1D0((char*)& byte_587000[103460], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2072);
        }
        sub_440A20(v9, v10);
        return 1;
    }
    return 1;
}
// 44198D: variable 'v4' is possibly undefined

//----- (00441B90) --------------------------------------------------------
char** __cdecl sub_441B90(_DWORD* a1)
{
    char** result; // eax
    char** v2; // esi
    wchar_t* v3; // eax

    result = (char**)a1;
    if (a1 && *a1)
    {
        v2 = (char**)(a1 + 2);
        do
        {
            if (!((_BYTE)result[3] & 4) && (!*(_DWORD*)& byte_587000[94464] || !((_BYTE)v2[1] & 0x10)))
            {
                v3 = loadString_sub_40F1D0(*v2, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2097);
                sub_450C00(6u, (wchar_t*)& byte_587000[103568], *(v2 - 1), v3);
            }
            v2 += 6;
            result = v2 - 2;
        } while (*(v2 - 2));
    }
    return result;
}

//----- (00441BF0) --------------------------------------------------------
int __cdecl sub_441BF0(int a1, int a2, int a3, const wchar_t** a4)
{
    int result; // eax
    int v5; // edi
    const wchar_t** v6; // eax
    const wchar_t** v7; // esi
    char v8; // al
    const wchar_t* v9; // ecx
    const wchar_t** v10; // eax
    const wchar_t** v11; // esi
    wchar_t* v12; // eax

    result = 0;
    if (*(_DWORD*)(a3 + 4 * a1))
    {
        if (a4)
        {
            v5 = 0;
            if (*a4)
            {
                v6 = a4;
                v7 = a4;
                while (1)
                {
                    if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *v6))
                    {
                        v8 = *((_BYTE*)v7 + 12);
                        if (!(v8 & 4) && (!*(_DWORD*)& byte_587000[94464] || !(v8 & 0x10)))
                            break;
                    }
                    v9 = v7[6];
                    v7 += 6;
                    ++v5;
                    v6 = v7;
                    if (!v9)
                        return 0;
                }
                v10 = (const wchar_t**)a4[6 * v5 + 4];
                v11 = &a4[6 * v5];
                if (v10)
                {
                    if ((unsigned __int8)a2 <= a1 + 1 || (result = sub_441BF0(a1 + 1, a2, a3, v10)) == 0)
                    {
                        sub_441B90(v11[4]);
                        result = 1;
                    }
                }
                else
                {
                    v12 = loadString_sub_40F1D0((char*)v11[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2135);
                    sub_450C00(6u, v12);
                    result = 1;
                }
            }
        }
    }
    return result;
}

//----- (00441CE0) --------------------------------------------------------
int __cdecl sub_441CE0(int a1, int a2, int a3)
{
    if ((unsigned __int8)a2 != 1)
    return sub_441BF0(1, a2, a3, (const wchar_t**)& byte_587000[97368]);
    sub_441B90(&byte_587000[97368]);
    return 1;
}

//----- (00441D20) --------------------------------------------------------
int sub_441D20()
{
    return 1;
}

//----- (00441D30) --------------------------------------------------------
int sub_441D30()
{
    char* i; // esi

    if (!sub_40A5C0(0x2000))
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            if (*((_DWORD*)i + 514))
            sub_4FC180(*((_DWORD*)i + 514));
        }
    }
    return 1;
}

//----- (00441D80) --------------------------------------------------------
int __cdecl sub_441D80(int a1, unsigned __int8 a2, int a3)
{
    const char* v4; // edi
    char* v5; // esi
    int v6; // eax
    char* v7; // eax
    char* v8; // esi
    double v9; // st7
    int v10; // eax
    float2 v11; // [esp+8h] [ebp-54h]
    char v12[76]; // [esp+10h] [ebp-4Ch]

    if (sub_40A5C0(0x2000))
        return 1;
    if (a2 >= 4u)
    {
        v7 = sub_417040(*(int*)& byte_5D4594[2616328]);
        v8 = v7;
        if (!v7 || !*((_DWORD*)v7 + 514))
        return 0;
        nox_sprintf(v12, "%S", *(_DWORD*)(a3 + 8));
        v9 = atof(v12);
        v10 = *(_DWORD*)(a3 + 12);
        v11.field_0 = v9;
        nox_sprintf(v12, "%S", v10);
        v11.field_4 = atof(v12);
        sub_4E7010(*((_DWORD*)v8 + 514), &v11);
        return 1;
    }
    if (a2 < 3u)
        return 0;
    nox_sprintf(v12, "%S", *(_DWORD*)(a3 + 8));
    v4 = sub_579E30(v12);
    if (!v4)
        return 1;
    v5 = sub_416EA0();
    if (!v5)
        return 1;
    do
    {
        v6 = *((_DWORD*)v5 + 514);
        if (v6)
            sub_4E7010(v6, (float2*)v4 + 1);
        v5 = sub_416EE0((int)v5);
    } while (v5);
    return 1;
}

//----- (00441EB0) --------------------------------------------------------
int sub_441EB0()
{
    char* i; // esi

    if (!sub_40A5C0(0x2000))
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            if (*((_DWORD*)i + 514))
            sub_4EE6F0(*((_DWORD*)i + 514));
        }
    }
    return 1;
}

//----- (00441F00) --------------------------------------------------------
int sub_441F00()
{
    char* i; // esi
    int v1; // eax

    if (!sub_40A5C0(0x2000))
    {
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v1 = *((_DWORD*)i + 514);
            if (v1)
                sub_4EEB80(v1, 2000);
        }
    }
    return 1;
}

//----- (00441F50) --------------------------------------------------------
int __cdecl sub_441F50(int a1, unsigned __int8 a2, int a3)
{
    char* i; // esi
    unsigned __int8 v5; // al

    if (!sub_40A5C0(0x2000))
    {
        if (a2 < 3u)
            return 0;
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            if (*((_DWORD*)i + 514))
            {
                v5 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
                sub_4EF410(*((_DWORD*)i + 514), v5);
            }
        }
    }
    return 1;
}

//----- (00441FC0) --------------------------------------------------------
int __cdecl sub_441FC0(int a1, unsigned __int8 a2, int a3)
{
    int v4; // eax
    int v5; // edi
    char* i; // ebp
    int v7; // esi
    int* v8; // ebx

    if (!sub_40A5C0(0x2000))
    {
        if (a2 < 3u)
            return 0;
        v4 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
        v5 = v4;
        if (v4 > 0)
        {
            if (v4 > 5)
                v5 = 5;
        }
        else
        {
            v5 = 1;
        }
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v7 = 0;
            v8 = (int*)(i + 3696);
            do
            {
                *v8 = v5;
                sub_56FCE0(*((_DWORD*)i + 1159), v7, v5);
                *v8 = v5;
                sub_56FCE0(*((_DWORD*)i + 1159), v7++, v5);
                ++v8;
            } while (v7 < 137);
        }
    }
    return 1;
}

//----- (00442070) --------------------------------------------------------
int __cdecl sub_442070(int a1, unsigned __int8 a2, int a3)
{
    int v4; // edi
    char* i; // esi
    int v6; // eax

    if (!sub_40A5C0(0x2000))
    {
        if (a2 < 3u)
            return 0;
        v4 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
        for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
        {
            v6 = *((_DWORD*)i + 514);
            if (v6)
            {
                if (v4 < 0)
                    sub_4FA5D0(v6, v4);
                else
                    sub_4FA590(v6, v4);
            }
        }
    }
    return 1;
}

//----- (004420F0) --------------------------------------------------------
int sub_4420F0()
{
    if (!sub_40A5C0(0x2000))
        sub_40AA60(1);
    return 1;
}

//----- (00442120) --------------------------------------------------------
int sub_442120()
{
    sub_46DB00();
    return 1;
}

//----- (00442130) --------------------------------------------------------
int sub_442130()
{
    sub_4460C0();
    return 1;
}

//----- (00442140) --------------------------------------------------------
int sub_442140()
{
    if (sub_40A5C0(4096) && sub_40A5C0(1))
        sub_4D6B10(0);
    if (sub_40A5C0(0x2000000))
        sub_4460C0();
    sub_43DDD0(0);
    sub_43DE60();
    return 1;
}

//----- (004421A0) --------------------------------------------------------
int sub_4421A0()
{
    wchar_t* v0; // eax
    char* v2; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[103680], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2440);
    sub_450C00(6u, v0);
    if (sub_40A5C0(1))
    {
        v2 = sub_417040(*(int*)& byte_5D4594[2616328]);
        sub_443E90((int)v2, 0, *(wchar_t**)& byte_5D4594[823700]);
    }
    else
    {
        sub_440950(0, *(wchar_t**)& byte_5D4594[823700]);
    }
    return 1;
}

//----- (00442210) --------------------------------------------------------
int __cdecl sub_442210(int a1, unsigned __int8 a2, int a3)
{
    int result; // eax
    char* v4; // eax
    wchar_t v5[128]; // [esp+4h] [ebp-100h]

    result = sub_440BC0(a1, a2, a3);
    if (result)
    {
        nox_swprintf(v5, L"%S", result);
        if (sub_40A5C0(1))
        {
            v4 = sub_417040(*(int*)& byte_5D4594[2616328]);
            if (a2 <= 1u)
                sub_443E90((int)v4, 4, (wchar_t*)& byte_5D4594[823768]);
            else
                sub_443E90((int)v4, 4, v5);
            result = 1;
        }
        else
        {
            if (a2 <= 1u)
                sub_440950(4, (wchar_t*)& byte_5D4594[823764]);
            else
                sub_440950(4, v5);
            result = 1;
        }
    }
    return result;
}

//----- (004422D0) --------------------------------------------------------
int __cdecl sub_4422D0(int a1, unsigned __int8 a2, int a3)
{
    const wchar_t* v3; // eax
    int v4; // esi
    int v5; // esi
    int v6; // eax
    int v8; // [esp-14h] [ebp-14h]

    if (a2 <= 1u)
        return 1;
    v3 = *(const wchar_t**)(a3 + 4 * a1);
    if (*v3 == 43)
    {
        v4 = nox_wcstol(v3, 0, 10);
        v8 = sub_434B00() + v4;
        sub_434B30(v8);
    }
    else
    {
        if (*v3 == 45)
        {
            v5 = nox_wcstol(v3, 0, 10);
            v6 = sub_434B00() - v5;
        }
        else
        {
            v6 = nox_wcstol(v3, 0, 10);
        }
        sub_434B30(v6);
    }
    sub_434B60();
    return 1;
}

//----- (00442340) --------------------------------------------------------
int __cdecl sub_442340(int a1, unsigned __int8 a2, int a3)
{
    const wchar_t* v3; // eax
    int v4; // eax
    int v6; // eax

    if (a2 > 1u)
    {
        v3 = *(const wchar_t**)(a3 + 4 * a1);
        if (*v3 != 43 && *v3 != 45)
        {
            v4 = nox_wcstol(v3, 0, 10);
            sub_476700(v4, 0);
            return 1;
        }
        v6 = nox_wcstol(v3, 0, 10);
        sub_476700(0, v6);
    }
    return 1;
}

//----- (004423A0) --------------------------------------------------------
int sub_4423A0()
{
    if (sub_4D6F50() && !sub_40A5C0(4096))
        sub_4D7080();
    return 1;
}

//----- (004423D0) --------------------------------------------------------
int sub_4423D0()
{
    wchar_t* v0; // eax

    *(_DWORD*)& byte_5D4594[2650636] |= 0x8000000u;
    v0 = loadString_sub_40F1D0((char*)& byte_587000[103744], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2541);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00442410) --------------------------------------------------------
int sub_442410()
{
    wchar_t* v0; // eax

    if (!sub_40A5C0(4096))
    {
        sub_4EF500(1);
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103800], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2557);
        sub_450C00(6u, v0);
    }
    return 1;
}

//----- (00442450) --------------------------------------------------------
int sub_442450()
{
    wchar_t* v0; // eax

    sub_4EF500(0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[103848], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2568);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00442480) --------------------------------------------------------
int sub_442480()
{
    wchar_t* v0; // eax

    if (!sub_40A5C0(4096))
    {
        nullsub_26(1);
        v0 = loadString_sub_40F1D0((char*)& byte_587000[103900], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2585);
        sub_450C00(6u, v0);
    }
    return 1;
}
// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);

//----- (004424C0) --------------------------------------------------------
int sub_4424C0()
{
    wchar_t* v0; // eax

    nullsub_26(0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[103948], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2597);
    sub_450C00(6u, v0);
    return 1;
}
// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);

//----- (004424F0) --------------------------------------------------------
int __cdecl sub_4424F0(int a1, char a2, int a3)
{
    wchar_t* v3; // eax

    if (a2 == 3)
    {
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
        {
            sub_4D0D90(1);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104000], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2614);
            LABEL_6:
            sub_450C00(6u, v3);
            sub_4AD840();
            return 1;
        }
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
        {
            sub_4D0D90(0);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104052], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2621);
            goto LABEL_6;
        }
    }
    return 0;
}

//----- (00442590) --------------------------------------------------------
int __cdecl sub_442590(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-Ch]

    if (a2 == 3)
    {
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
        {
            sub_409E70(1);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104104], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2644);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104160], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2645);
            LABEL_6:
            sub_450C00(6u, v3, v5);
            return 1;
        }
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
        {
            sub_409EC0(1);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104208], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2652);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104264], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2653);
            goto LABEL_6;
        }
    }
    return 0;
}

//----- (00442670) --------------------------------------------------------
int __cdecl sub_442670(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-Ch]

    if (a2 == 3)
    {
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
        {
            sub_409E70(16);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104312], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2674);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104368], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2675);
            LABEL_6:
            sub_450C00(6u, v3, v5);
            return 1;
        }
        if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
        {
            sub_409EC0(16);
            sub_40A670();
            v5 = loadString_sub_40F1D0((char*)& byte_587000[104416], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2682);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[104472], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2683);
            goto LABEL_6;
        }
    }
    return 0;
}

//----- (00442750) --------------------------------------------------------
int sub_442750()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(4);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 4;
    sub_4AD840();
    return 1;
}

//----- (00442780) --------------------------------------------------------
int sub_442780()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(3);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 3;
    sub_4AD840();
    return 1;
}

//----- (004427B0) --------------------------------------------------------
int sub_4427B0()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(2);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 2;
    sub_4AD840();
    return 1;
}

//----- (004427E0) --------------------------------------------------------
int sub_4427E0()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 1;
    v0 = sub_40A710(1);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 1;
    sub_4AD840();
    return 1;
}

//----- (00442810) --------------------------------------------------------
int sub_442810()
{
    int v0; // eax

    *(_DWORD*)& byte_5D4594[2650652] = 0;
    v0 = sub_40A710(1);
    sub_40A6D0(v0);
    *(_DWORD*)& byte_5D4594[3596] = 1;
    sub_4AD840();
    return 1;
}

//----- (00442840) --------------------------------------------------------
int __cdecl sub_442840(int a1, unsigned __int8 a2, int a3)
{
    int v3; // ebx
    unsigned int v5; // edx
    char* v6; // edi
    char* v7; // edi
    char* v8; // esi
    char v9; // cl
    int v10; // edx
    wchar_t* v11; // eax
    _DWORD* v12; // [esp+4h] [ebp-104h]
    char v13[128]; // [esp+8h] [ebp-100h]
    char v14[128]; // [esp+88h] [ebp-80h]

    v3 = a1;
    if (a2 < 3u)
        return 0;
    v13[0] = 0;
    if (a1 < a2)
    {
        v12 = (_DWORD*)(a3 + 4 * a1);
        do
        {
            nox_sprintf(v14, "%S", *v12);
            v5 = strlen(v14) + 1;
            v6 = &v13[strlen(v13)];
            qmemcpy(v6, v14, 4 * (v5 >> 2));
            v8 = &v14[4 * (v5 >> 2)];
            v7 = &v6[4 * (v5 >> 2)];
            v9 = v5;
            v10 = v3 + 1;
            qmemcpy(v7, v8, v9 & 3);
            if (v3 + 1 < a2)
                * (_WORD*)& v13[strlen(v13)] = *(_WORD*)& byte_587000[104484];
            ++v3;
            ++v12;
        } while (v10 < a2);
        if (v13[0])
        {
            sub_40A440(v13);
            v11 = loadString_sub_40F1D0((char*)& byte_587000[104528], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2766);
            sub_450C00(6u, v11, v13);
        }
    }
    return 1;
}
// 442840: using guessed type char var_100[128];
// 442840: using guessed type char var_80[128];

//----- (00442950) --------------------------------------------------------
int __cdecl sub_442950(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v5; // [esp-4h] [ebp-10h]

    if (a2 == 3 || a2 == 4)
    {
        if (_nox_wcsicmp(*(const wchar_t**)(a3 + 8), *(const wchar_t**)& byte_587000[94492]))
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_409E70(4);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104804], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2810);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104860], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2811);
                goto LABEL_13;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_409EC0(4);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104912], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2818);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104968], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2819);
                goto LABEL_13;
            }
        }
        else if (a2 != 3)
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_409E70(8);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104580], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2788);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104636], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2789);
                LABEL_13:
                sub_450C00(6u, v3, v5);
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_409E70(8);
                sub_40A670();
                v5 = loadString_sub_40F1D0((char*)& byte_587000[104692], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2796);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[104748], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2797);
                goto LABEL_13;
            }
        }
    }
    return 0;
}

//----- (00442B00) --------------------------------------------------------
int __cdecl sub_442B00(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    int v4; // esi
    char* v5; // ebx
    wchar_t* v7; // eax
    int v8; // [esp-4h] [ebp-74h]
    int v9; // [esp-4h] [ebp-74h]
    char v10[100]; // [esp+Ch] [ebp-64h]

    if (a2 == 4)
    {
        if (sub_40A5C0(128))
        {
            v8 = *(_DWORD*)(a3 + 8);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[105020], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3293);
            goto LABEL_16;
        }
        v4 = sub_424960(*(wchar_t**)(a3 + 8));
        if (v4 || (nox_sprintf(v10, "%S", *(_DWORD*)(a3 + 8)), (v4 = sub_4243F0(v10)) != 0))
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                v5 = sub_4165B0();
                if ((sub_40A5C0(64) || v5[52] & 0x40) && v4 == 132)
                    return 1;
                if (sub_424B70(v4))
                    return 1;
                sub_424B90(v4);
                sub_40A670();
                v8 = *(_DWORD*)(a3 + 8);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[105076], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3324);
                goto LABEL_16;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                if (!sub_424B70(v4))
                    return 1;
                sub_424BB0(v4);
                sub_40A670();
                v8 = *(_DWORD*)(a3 + 8);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[105132], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3333);
                LABEL_16:
                sub_450C00(6u, v3, v8);
                return 1;
            }
        }
        else
        {
            v9 = *(_DWORD*)(a3 + 8);
            v7 = loadString_sub_40F1D0((char*)& byte_587000[105188], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3342);
            sub_450C00(6u, v7, v9);
        }
    }
    return 0;
}

//----- (00442C90) --------------------------------------------------------
int __cdecl sub_442C90(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    wchar_t* v4; // eax
    unsigned __int16* v6; // esi
    wchar_t* v7; // eax
    int v8; // [esp-4h] [ebp-70h]
    int v9; // [esp-4h] [ebp-70h]
    int v10; // [esp-4h] [ebp-70h]
    char v11[100]; // [esp+8h] [ebp-64h]

    if (a2 == 4)
    {
        if (sub_40A5C0(128))
        {
            v8 = *(_DWORD*)(a3 + 8);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[105244], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3361);
            goto LABEL_19;
        }
        if (_nox_wcsicmp(*(const wchar_t**)(a3 + 8), *(const wchar_t**)& byte_587000[94492]))
        {
            v6 = (unsigned __int16*)sub_415A60(*(wchar_t**)(a3 + 8));
            if (v6
                || (nox_sprintf(v11, "%S", *(_DWORD*)(a3 + 8)),
                    (v6 = (unsigned __int16*)sub_415A30(v11)) != 0))
            {
                if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
                {
                    if (sub_4E3BA0(*v6))
                        return 1;
                    sub_4E3BF0((int)v6);
                    sub_40A670();
                    v8 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105412], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3401);
                    LABEL_19:
                    sub_450C00(6u, v3, v8);
                    return 1;
                }
                if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
                {
                    if (!sub_4E3BA0(*v6) || sub_415880((char*)* v6) == 1)
                        return 1;
                    sub_4E3BC0((int)v6);
                    sub_4E5DB0(*v6);
                    sub_40A670();
                    v8 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105468], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3414);
                    goto LABEL_19;
                }
            }
            else
            {
                v10 = *(_DWORD*)(a3 + 8);
                v7 = loadString_sub_40F1D0((char*)& byte_587000[105524], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3423);
                sub_450C00(6u, v7, v10);
            }
        }
        else
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_409E70(2);
                v9 = *(_DWORD*)(a3 + 12);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105296], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3370);
                LABEL_9:
                sub_450C00(6u, v4, v9);
                sub_4AD840();
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_409E70(2);
                v9 = *(_DWORD*)(a3 + 12);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105352], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3377);
                goto LABEL_9;
            }
        }
    }
    return 0;
}

//----- (00442ED0) --------------------------------------------------------
int __cdecl sub_442ED0(int a1, char a2, int a3)
{
    wchar_t* v3; // eax
    unsigned __int16* v4; // esi
    wchar_t* v6; // eax
    int v7; // [esp-4h] [ebp-70h]
    int v8; // [esp-4h] [ebp-70h]
    char v9[100]; // [esp+8h] [ebp-64h]

    if (a2 == 4)
    {
        if (sub_40A5C0(128))
        {
            v7 = *(_DWORD*)(a3 + 8);
            v3 = loadString_sub_40F1D0((char*)& byte_587000[105580], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3442);
            LABEL_12:
            sub_450C00(6u, v3, v7);
            return 1;
        }
        v4 = (unsigned __int16*)sub_415EF0(*(wchar_t**)(a3 + 8));
        if (v4
            || (nox_sprintf(v9, "%S", *(_DWORD*)(a3 + 8)),
                (v4 = (unsigned __int16*)sub_415EC0(v9)) != 0))
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                if (!sub_4E3BA0(*v4))
                {
                    sub_4E3BF0((int)v4);
                    sub_40A670();
                    v7 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105636], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3462);
                    goto LABEL_12;
                }
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                if (sub_4E3BA0(*v4))
                {
                    sub_4E3BC0((int)v4);
                    sub_4E5DB0(*v4);
                    sub_40A670();
                    v7 = *(_DWORD*)(a3 + 8);
                    v3 = loadString_sub_40F1D0((char*)& byte_587000[105692], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3473);
                    goto LABEL_12;
                }
                return 1;
            }
        }
        else
        {
            v8 = *(_DWORD*)(a3 + 8);
            v6 = loadString_sub_40F1D0((char*)& byte_587000[105748], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3481);
            sub_450C00(6u, v6, v8);
        }
    }
    return 0;
}

//----- (00443050) --------------------------------------------------------
int __cdecl sub_443050(int a1, char a2, int a3)
{
    int v3; // edi
    wchar_t* v4; // eax
    wchar_t* v6; // eax
    int v7; // [esp-4h] [ebp-8Ch]
    int v8; // [esp-4h] [ebp-8Ch]
    char v9[128]; // [esp+8h] [ebp-80h]

    if (a2 == 4)
    {
        nox_sprintf(v9, "%S", *(_DWORD*)(a3 + 8));
        v3 = sub_4E3B60(v9);
        if (v3)
        {
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94468]))
            {
                sub_4E3BF0(v3);
                v7 = *(_DWORD*)(a3 + 8);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105808], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3535);
                LABEL_7:
                sub_450C00(6u, v4, v7);
                return 1;
            }
            if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)& byte_587000[94472]))
            {
                sub_4E3BC0(v3);
                v7 = *(_DWORD*)(a3 + 8);
                v4 = loadString_sub_40F1D0((char*)& byte_587000[105864], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3541);
                goto LABEL_7;
            }
        }
        else
        {
            v8 = *(_DWORD*)(a3 + 8);
            v6 = loadString_sub_40F1D0((char*)& byte_587000[105920], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3548);
            sub_450C00(6u, v6, v8);
        }
    }
    return 0;
}

//----- (00443160) --------------------------------------------------------
int __cdecl sub_443160(int a1, char a2, int a3)
{
    wchar_t* v4; // edi
    char* v5; // eax
    char* v6; // esi
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    int v9; // [esp-Ch] [ebp-Ch]

    if (a2 != 2)
        return 0;
    v4 = *(wchar_t**)(a3 + 4 * a1);
    v5 = sub_4170D0(*(wchar_t**)(a3 + 4 * a1));
    v6 = v5;
    if (v5)
    {
        if (v5[2064] == 31)
        {
            v8 = loadString_sub_40F1D0((char*)& byte_587000[106024], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3580);
            sub_440A20(v8);
            return 1;
        }
        if (sub_40A5C0(4096))
            sub_4DCFB0(*((_DWORD*)v6 + 514));
        else
        sub_4DEB00((unsigned __int8)v6[2064]);
        sub_416770(0, v4, v6 + 2112);
        v9 = (int)(v6 + 4704);
        v7 = loadString_sub_40F1D0((char*)& byte_587000[105976], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3577);
    }
    else
    {
        sub_416770(0, v4, 0);
        v9 = (int)v4;
        v7 = loadString_sub_40F1D0((char*)& byte_587000[106080], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3585);
    }
    sub_440A20(v7, v9);
    return 1;
}

//----- (00443250) --------------------------------------------------------
int sub_443250()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106132], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3698);
    sub_450C00(6u, v0);
    return 1;
}

//----- (00443280) --------------------------------------------------------
int sub_443280()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106192], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3704);
    sub_450C00(6u, v0);
    return 1;
}

//----- (004432B0) --------------------------------------------------------
int __cdecl sub_4432B0(int a1, char a2, int a3)
{
    char* v4; // eax
    char* v5; // esi
    wchar_t* v6; // eax
    wchar_t* v7; // eax

    if (a2 != 2)
        return 0;
    v4 = sub_4170D0(*(wchar_t**)(a3 + 4 * a1));
    v5 = v4;
    if (!v4)
        return 1;
    if (v4[2064] == 31)
    {
        v7 = loadString_sub_40F1D0((char*)& byte_587000[106300], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3745);
        sub_440A20(v7);
        return 1;
    }
    if (sub_40A5C0(4096))
    {
        sub_4DCFB0(*((_DWORD*)v5 + 514));
    }
    else
    {
        sub_4DEAB0((unsigned __int8)v5[2064], 4);
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106252], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3739);
        sub_440A20(v6, v5 + 4704);
    }
    return 1;
}

//----- (00443380) --------------------------------------------------------
int __cdecl sub_443380(int a1, char a2, int a3)
{
    int v3; // esi
    const wchar_t* v5; // eax
    int v6; // eax
    wchar_t* v7; // eax

    v3 = 0;
    if (a2 != 3)
        return 0;
    v5 = *(const wchar_t**)(a3 + 8);
    if (v5)
    {
        v6 = nox_wcstol(v5, 0, 10);
        v3 = v6;
        if (v6 >= 0)
        {
            if (v6 > 999)
                v3 = 999;
        }
        else
        {
            v3 = 0;
        }
        if (sub_409FA0() == v3)
            return 1;
        sub_409F80(v3);
        sub_455800();
    }
    v7 = loadString_sub_40F1D0((char*)& byte_587000[106360], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3779);
    sub_440A20(v7, v3);
    return 1;
}

//----- (00443400) --------------------------------------------------------
int __cdecl sub_443400(int a1, char a2, int a3)
{
    char* v4; // esi
    const wchar_t* v5; // eax
    unsigned __int8 v6; // al

    if (a2 != 3)
        return 0;
    v4 = sub_4165B0();
    v5 = *(const wchar_t**)(a3 + 8);
    if (v5)
    {
        v6 = nox_wcstol(v5, 0, 10);
        sub_40A040(*((_WORD*)v4 + 26), v6);
    }
    return 1;
}

//----- (00443440) --------------------------------------------------------
int __cdecl sub_443440(int a1, char a2, int a3)
{
    const wchar_t* v4; // esi
    char* v5; // edi
    unsigned __int16 v6; // ax

    if (a2 != 3)
        return 0;
    v4 = *(const wchar_t**)(a3 + 8);
    v5 = sub_4165B0();
    if (v4)
    {
        v6 = nox_wcstol(v4, 0, 10);
        sub_409FB0(*((_WORD*)v5 + 26), v6);
    }
    return 1;
}

//----- (00443480) --------------------------------------------------------
int sub_443480()
{
    wchar_t* v0; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106412], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3830);
    sub_450C00(6u, v0);
    return 1;
}

//----- (004434B0) --------------------------------------------------------
int sub_4434B0()
{
    wchar_t* v0; // eax
    char* i; // esi
    wchar_t* v2; // eax
    wchar_t* v3; // eax
    wchar_t v5[128]; // [esp+4h] [ebp-100h]

    v0 = loadString_sub_40F1D0((char*)& byte_587000[106472], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3839);
    sub_450C00(6u, v0);
    for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
    {
        v5[0] = 0;
        nox_wcscat(v5, (const wchar_t*)i + 2352);
        if (*(_DWORD*)& byte_5D4594[823684] && i[3680] & 4)
        {
            nox_wcscat(v5, L", ");
            v2 = loadString_sub_40F1D0((char*)& byte_587000[106532], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3851);
            nox_wcscat(v5, v2);
        }
        if (i[3680] & 8)
        {
            nox_wcscat(v5, L", ");
            v3 = loadString_sub_40F1D0((char*)& byte_587000[106592], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3857);
            nox_wcscat(v5, v3);
        }
        sub_450C00(6u, (wchar_t*)& byte_587000[106604], v5);
    }
    return 1;
}

//----- (004435C0) --------------------------------------------------------
int sub_4435C0()
{
    sub_450B70();
    return 1;
}

//----- (004435D0) --------------------------------------------------------
int sub_4435D0()
{
    if (!sub_40A5C0(8) && sub_40A5C0(0x2000))
        sub_457500();
    return 1;
}

//----- (00443600) --------------------------------------------------------
int sub_443600()
{
    sub_4ADA40();
    return 1;
}

//----- (00443610) --------------------------------------------------------
int __cdecl sub_443610(int a1, unsigned __int8 a2, int a3)
{
    wchar_t** v3; // esi
    int v4; // eax
    int v5; // eax
    wchar_t* v6; // eax
    wchar_t* v8; // [esp-4h] [ebp-14h]

    if (a2 < 2u || a2 > 3u)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[823684])
    {
        v3 = (wchar_t**)(a3 + 4 * a1);
        goto LABEL_8;
    }
    v3 = (wchar_t**)(a3 + 4 * a1);
    if (_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94496]))
    {
        LABEL_8:
        v5 = sub_57A0F0(*v3);
        goto LABEL_9;
    }
    v4 = a1 + 1;
    if (a1 + 1 != a2 - 1)
        return 0;
    v3 = (wchar_t**)(a3 + 4 * v4);
    v5 = sub_57A130(*(wchar_t**)(a3 + 4 * v4));
    LABEL_9:
    v8 = *v3;
    if (v5)
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106708], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3923);
    else
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106652], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3921);
    sub_450C00(6u, v6, v8);
    return 1;
}

//----- (004436E0) --------------------------------------------------------
int __cdecl sub_4436E0(int a1, unsigned __int8 a2, int a3)
{
    wchar_t** v3; // esi
    int v4; // eax
    int v5; // eax
    wchar_t* v6; // eax
    wchar_t* v8; // [esp-4h] [ebp-14h]

    if (a2 < 2u || a2 > 3u)
        return 0;
    if (!*(_DWORD*)& byte_5D4594[823684])
    {
        v3 = (wchar_t**)(a3 + 4 * a1);
        goto LABEL_8;
    }
    v3 = (wchar_t**)(a3 + 4 * a1);
    if (_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)& byte_587000[94496]))
    {
        LABEL_8:
        v5 = sub_57A080(*v3);
        goto LABEL_9;
    }
    v4 = a1 + 1;
    if (a1 + 1 != a2 - 1)
        return 0;
    v3 = (wchar_t**)(a3 + 4 * v4);
    v5 = sub_57A0C0(*(wchar_t**)(a3 + 4 * v4));
    LABEL_9:
    v8 = *v3;
    if (v5)
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106812], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3961);
    else
        v6 = loadString_sub_40F1D0((char*)& byte_587000[106756], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3959);
    sub_450C00(6u, v6, v8);
    return 1;
}

//----- (004437B0) --------------------------------------------------------
int __cdecl sub_4437B0(int a1, char a2)
{
    wchar_t* v3; // eax
    int v4; // [esp-4h] [ebp-4h]

    if (a2 != 2)
        return 0;
    if (!sub_40A5C0(1))
    {
        v4 = *(_DWORD*)& byte_5D4594[823700];
        v3 = loadString_sub_40F1D0((char*)& byte_587000[106860], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3979);
        sub_450C00(6u, v3, v4);
    }
    sub_440950(1, *(wchar_t**)& byte_5D4594[823700]);
    return 1;
}

//----- (00443810) --------------------------------------------------------
int __cdecl sub_443810(int a1, char a2, int a3)
{
    wchar_t* v4; // eax
    wchar_t v5[128]; // [esp+0h] [ebp-100h]

    if (a2 != 2)
        return 0;
    nox_wcscpy(v5, *(const wchar_t**)(a3 + 4));
    if (!nox_wcschr(v5, 0x2Eu))
        nox_wcscat(v5, L".rul");
    v4 = loadString_sub_40F1D0((char*)& byte_587000[106924], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4002);
    sub_450C00(6u, v4, v5);
    sub_4438A0((int)v5);
    return 1;
}

//----- (004438A0) --------------------------------------------------------
int __cdecl sub_4438A0(int a1)
{
    FILE* v1; // eax
    FILE* v2; // esi
    char* v3; // eax
    char v5[256]; // [esp+8h] [ebp-400h]
    char v6[256]; // [esp+108h] [ebp-300h]
    wchar_t v7[128]; // [esp+208h] [ebp-200h]

    if (!a1)
        return 0;
    v6[0] = 0;
    nox_sprintf(v6, "%S", a1);
    v1 = fopen(v6, "r");
    v2 = v1;
    if (!v1)
        return 0;
    if (!feof(v1))
    {
        do
        {
            memset(v5, 0, 0xFCu);
            *(_WORD*)& v5[252] = 0;
            v5[254] = 0;
            fgets(v5, 255, v2);
            v3 = strchr(v5, 10);
            if (v3)
                * v3 = 0;
            if (v5[0])
            {
                nox_swprintf(v7, L"%S", v5);
                sub_450C00(4u, (wchar_t*)& byte_587000[106956], v7);
                sub_443C80(v7, 1);
            }
        } while (!feof(v2));
    }
    fclose(v2);
    return 1;
}

//----- (004439B0) --------------------------------------------------------
int __cdecl sub_4439B0(int a1, unsigned __int8 a2)
{
    wchar_t* v2; // eax
    int result; // eax
    wchar_t* v4; // eax

    if (a2 == 1)
    {
        *(_DWORD*)& byte_5D4594[823696] = 1;
        v2 = loadString_sub_40F1D0((char*)& byte_587000[107008], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4014);
        sub_450C00(6u, v2);
        result = 1;
    }
    else
    {
        if (a2 > 1u && *(_DWORD*)& byte_5D4594[823688])
        {
            v4 = nox_wcsstr(*(const wchar_t**)& byte_5D4594[823700], L" ");
            if (v4)
                sub_440950(2, v4);
        }
        result = 1;
    }
    return result;
}

//----- (00443A20) --------------------------------------------------------
int __cdecl sub_443A20(int a1, int a2, int a3, const wchar_t** a4, int a5)
{
    int v5; // eax
    int v6; // ecx
    int v7; // edi
    const wchar_t** v8; // ebp
    const wchar_t** v9; // esi
    const wchar_t* v10; // eax
    const wchar_t** v12; // esi
    char v13; // al
    wchar_t* v14; // eax
    const wchar_t** v15; // ecx
    int v16; // eax
    wchar_t* v17; // eax
    int v18; // [esp+10h] [ebp-44h]
    wchar_t v19[256]; // [esp+14h] [ebp-40h]

    v5 = a3;
    v6 = a1;
    v7 = 0;
    v18 = 0;
    if (!*(_DWORD*)(a3 + 4 * a1) || !a4 || !*a4)
        return v18;
    v8 = a4;
    v9 = a4;
    while (1)
    {
        if ((_BYTE)v8[3] & 0x40)
            sub_443BF0(*(unsigned __int16**)(v5 + 4 * v6), (char*)v19);
        else
        nox_wcscpy(v19, *(const wchar_t**)(v5 + 4 * v6));
        if (!_nox_wcsicmp(v19, *v8))
            break;
        v10 = v9[6];
        v9 += 6;
        ++v7;
        v8 = v9;
        if (!v10)
            return 0;
        v6 = a1;
        v5 = a3;
    }
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000) && *(_DWORD*)& byte_587000[94464] && (int)a4[6 * v7 + 3] & 0x10)
        return 0;
    if (*(_DWORD*)& byte_5D4594[823684])
    {
        v12 = &a4[6 * v7];
        v13 = (char)a4[6 * v7 + 3];
        if (!(v13 & 1))
        {
            v14 = loadString_sub_40F1D0((char*)& byte_587000[107068], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4091);
            LABEL_21:
            sub_450C00(6u, v14);
            return 1;
        }
    }
    else
    {
        v13 = (char)a4[6 * v7 + 3];
        v12 = &a4[6 * v7];
        if (!(v13 & 2))
        {
            v14 = loadString_sub_40F1D0((char*)& byte_587000[107120], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4097);
            goto LABEL_21;
        }
    }
    if (v13 & 0x20 && !(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
        return 1;
    v15 = (const wchar_t**)v12[4];
    if (v15)
    {
        if ((unsigned __int8)a2 <= a1 + 1)
        {
            LABEL_30:
            v17 = loadString_sub_40F1D0((char*)v12[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4125);
            sub_450C00(6u, v17);
            return 1;
        }
        v16 = sub_443A20(a1 + 1, a2, a3, v15, a5);
    }
    else
    {
        v16 = ((int(__cdecl*)(int, int, int))v12[5])(a1 + 1, a2, a3);
    }
    v18 = v16;
    if (!v16)
        goto LABEL_30;
    return v18;
}

//----- (00443BF0) --------------------------------------------------------
void __cdecl sub_443BF0(unsigned __int16* a1, char* a2)
{
int v2; // esi
signed int v3; // ebp
unsigned __int16 v4; // ax
unsigned __int16* v5; // ecx
int v6; // edx

v2 = 0;
if (a1)
{
if (a2 && (v3 = nox_wcslen(*(const wchar_t**)& byte_587000[98256]), (v4 = *a1) != 0))
{
v5 = a1;
do
{
++v5;
v6 = (unsigned __int8)(v2++ * (v4 - 1) % v3);
*(unsigned __int16*)((char*)v5 - (char*)a1 + a2 - 2) = *(_WORD*)(*(_DWORD*)& byte_587000[98256] + 2 * v6);
v4 = *v5;
} while (*v5);
*(_WORD*)& a2[2 * v2] = 0;
}
else
{
*(_WORD*)a2 = 0;
}
}
else
{
*(_WORD*)a2 = 0;
}
}

//----- (00443C80) --------------------------------------------------------
int __cdecl sub_443C80(wchar_t* a1, int a2)
{
    int v2; // ebp
    char v3; // bl
    int result; // eax
    wchar_t* v5; // esi
    int v6; // eax
    int v7; // ecx
    wchar_t* v8; // eax
    wchar_t* v9; // eax
    int v10; // [esp+10h] [ebp-88h]
    int v11; // [esp+14h] [ebp-84h]
    int v12[32]; // [esp+18h] [ebp-80h]

    v2 = 0;
    v3 = 0;
    v11 = 0;
    LOBYTE(v10) = 0;
    if (a1)
    {
        *(_DWORD*)& byte_5D4594[823700] = a1;
        memset(&byte_5D4594[820276], 0, 0x800u);
        if (sub_40A5C0(1))
        {
            *(_DWORD*)& byte_5D4594[823684] = 1;
            *(_DWORD*)& byte_5D4594[823688] = 0;
        }
        else
        {
            *(_DWORD*)& byte_5D4594[823684] = 0;
            *(_DWORD*)& byte_5D4594[823688] = 1;
        }
        if (*(_DWORD*)& byte_5D4594[823696])
        {
            sub_4409D0(a1);
            result = 1;
            *(_DWORD*)& byte_5D4594[823696] = 0;
            return result;
        }
        nox_wcscpy((wchar_t*)& byte_5D4594[820276], a1);
        if (*(_WORD*)& byte_5D4594[820276] == 34)
        {
            v5 = nox_wcstok((wchar_t*)& byte_5D4594[820278], L"\"\n\r");
            v2 = 1;
        }
        else
        {
            v5 = nox_wcstok((wchar_t*)& byte_5D4594[820276], L" ");
        }
        if (v5)
        {
            do
            {
                v6 = (int)v5;
                if (!v2)
                {
                    v6 = sub_443E40(v5);
                    if (!v6)
                        v6 = (int)v5;
                }
                v7 = (unsigned __int8)v10;
                LOBYTE(v10) = ++v3;
                v12[v7] = v6;
                v8 = &v5[nox_wcslen(v5) + 1];
                if (v2)
                    ++v8;
                if (*v8 == 34)
                {
                    v5 = nox_wcstok(v8 + 1, L"\"\n\r");
                    v2 = 1;
                }
                else
                {
                    v5 = nox_wcstok(0, L" ");
                    v2 = 0;
                }
            } while (v5);
            if (v3)
            {
                v11 = sub_443A20(0, v10, (int)v12, (const wchar_t**)& byte_587000[97368], a2);
                if (!v11)
                {
                    v9 = loadString_sub_40F1D0((char*)& byte_587000[107236], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4226);
                    sub_450C00(6u, v9);
                }
            }
        }
    }
    result = v11;
    *(_DWORD*)& byte_5D4594[823700] = 0;
    return result;
}
// 443DEE: variable 'v10' is possibly undefined
// 443C80: using guessed type int var_80[32];

//----- (00443E40) --------------------------------------------------------
int __cdecl sub_443E40(wchar_t* a1)
{
    int v1; // esi
    const wchar_t** i; // edi

    v1 = 0;
    if (*(int*)& byte_5D4594[823708] <= 0)
        return 0;
    for (i = (const wchar_t**)& byte_5D4594[816504]; _nox_wcsicmp(a1, *i); i += 2)
    {
        if (++v1 >= *(int*)& byte_5D4594[823708])
            return 0;
    }
    return *(_DWORD*)& byte_5D4594[8 * v1 + 816500];
}

//----- (00443E90) --------------------------------------------------------
int __cdecl sub_443E90(int a1, char a2, wchar_t* a3)
{
    int v3; // ecx
    int result; // eax
    BOOL v5; // edi
    wchar_t* v6; // ebx
    int v7; // eax
    int v8; // eax
    wchar_t* v9; // eax
    wchar_t* v10; // esi
    int v11; // edi
    wchar_t* v12; // eax
    wchar_t* v13; // eax
    char* v14; // esi
    int v15; // eax
    wchar_t* v16; // eax
    char* v17; // esi
    wchar_t* v18; // eax
    int v19; // [esp-8h] [ebp-94h]
    int v20; // [esp-8h] [ebp-94h]
    wchar_t* v21; // [esp-4h] [ebp-90h]
    char v22[128]; // [esp+Ch] [ebp-80h]

    if (!a1 || !*(_DWORD*)(a1 + 2056))
        return 0;
    if (a3)
        nox_wcscpy((wchar_t*)& byte_5D4594[818228], a3);
    else
        *(_WORD*)& byte_5D4594[818228] = 0;
    v3 = a1;
    *(_DWORD*)& byte_5D4594[823692] = a1;
    if (a2 != 4 && a2 != 5 && a2)
    {
        if (sub_40A5C0(49152))
            return 1;
        v3 = *(_DWORD*)& byte_5D4594[823692];
    }
    switch (a2)
    {
        case 0:
            if (sub_40A5C0(8) || sub_40A5C0(4096) || *(_BYTE*)(a1 + 3680) & 1)
                goto LABEL_61;
            v5 = *(short*)& byte_5D4594[818228] == -4083
                 && *(short*)& byte_5D4594[818230] == -3923
                 && !*(_WORD*)& byte_5D4594[818232];
            if (sub_4E6860(a1, v5, 0) != 1)
                goto LABEL_61;
            v6 = loadString_sub_40F1D0((char*)& byte_587000[107288], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4287);
            v7 = sub_40A8A0();
            if (v7)
            {
                if (!v5)
                    sub_4174F0(a1, 256);
                if (sub_40A5C0(1024) && sub_40A770() == 1)
                    sub_5095E0();
            }
            v8 = *(_DWORD*)(a1 + 2056);
            if (v8)
                sub_419570(v8 + 48, *(_DWORD*)(a1 + 2060));
            v21 = v6;
            v9 = loadString_sub_40F1D0((char*)& byte_587000[107332], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4308);
            goto LABEL_38;
        case 1:
            if (!sub_4D12A0(*(unsigned __int8*)(a1 + 2064))
            && *(unsigned __int8*)(a1 + 2064) != *(_DWORD*)& byte_5D4594[2616328]
                                  && !sub_40A5C0(2048))
            {
                goto LABEL_61;
            }
            nox_wcstok((wchar_t*)& byte_5D4594[818228], L" ");
            v10 = nox_wcstok(0, L" ");
            nox_sprintf(v22, "%S", v10);
            v11 = sub_5071D0(v22);
            if (v11 != -1 && *(_DWORD*)& byte_5D4594[823692])
            {
                v12 = loadString_sub_40F1D0((char*)& byte_587000[107456], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4332);
                sub_450C00(6u, v12, v10);
                sub_507310(
                        v11,
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[823692] + 2056),
                        *(_DWORD*)(*(_DWORD*)& byte_5D4594[823692] + 2056));
                *(_DWORD*)& byte_5D4594[823692] = 0;
                result = 1;
            }
            else
            {
                v21 = v10;
                v9 = loadString_sub_40F1D0((char*)& byte_587000[107400], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4329);
                LABEL_38:
                sub_450C00(6u, v9, v21);
                *(_DWORD*)& byte_5D4594[823692] = 0;
                result = 1;
            }
            return result;
        case 2:
            if (!sub_4D12A0(*(unsigned __int8*)(a1 + 2064))
            && *(unsigned __int8*)(a1 + 2064) != *(_DWORD*)& byte_5D4594[2616328]
                                  && !sub_40A5C0(2048))
            {
                goto LABEL_61;
            }
            v19 = *(_DWORD*)& byte_5D4594[823692] + 4704;
            v13 = loadString_sub_40F1D0((char*)& byte_587000[107516], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4345);
            sub_450C00(6u, v13, v19, a3);
            sub_443C80(a3, 0);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            return 1;
        case 3:
            sub_4D9FD0(0, a3);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            return 1;
        case 4:
            if (!(*(_BYTE*)(v3 + 3680) & 1) && !(*(_DWORD*)& byte_5D4594[2650636] & 0x400000))
            {
                if (sub_40A5C0(1))
                {
                    v16 = loadString_sub_40F1D0((char*)& byte_587000[107568], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4392);
                    sub_450C00(6u, v16);
                    *(_DWORD*)& byte_5D4594[823692] = 0;
                    return 1;
                }
                LABEL_61:
                *(_DWORD*)& byte_5D4594[823692] = 0;
                return 1;
            }
            if (!*a3)
            {
                sub_4E6040(*(_DWORD*)(v3 + 2056));
                *(_DWORD*)& byte_5D4594[823692] = 0;
                return 1;
            }
            v17 = sub_416EA0();
            if (!v17)
                goto LABEL_61;
            do
            {
                if (!_nox_wcsicmp(a3, (const wchar_t*)v17 + 2352))
                    sub_4E6060(*(_DWORD*)(*(_DWORD*)& byte_5D4594[823692] + 2056), *((_DWORD*)v17 + 514));
                v17 = sub_416EE0((int)v17);
            } while (v17);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            result = 1;
            break;
        case 5:
            sub_4D9FD0(16, a3);
            v14 = sub_416EA0();
            if (!v14)
                goto LABEL_61;
            do
            {
                v15 = *((_DWORD*)v14 + 514);
                if (v15)
                    sub_501960(902, v15, 0, 0);
                v14 = sub_416EE0((int)v14);
            } while (v14);
            *(_DWORD*)& byte_5D4594[823692] = 0;
            return 1;
        default:
            v20 = v3 + 4704;
            v18 = loadString_sub_40F1D0((char*)& byte_587000[107624], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4400);
            sub_450C00(6u, v18, v20, a3);
            goto LABEL_61;
    }
    return result;
}
// 443FC8: variable 'v7' is possibly undefined

//----- (004443B0) --------------------------------------------------------
void __cdecl sub_4443B0(unsigned __int8 a1)
{
    char* v1; // eax
    wchar_t* v2; // esi

    if (a1 >= 0x3Bu && a1 <= 0x58u)
    {
        if (*(_DWORD*)& byte_587000[95416])
        {
            v1 = sub_444410(a1);
            v2 = (wchar_t*)v1;
            if (v1)
            {
                if (*(_WORD*)v1)
                {
                    sub_450C00(4u, (wchar_t*)& byte_587000[107640], v1);
                    sub_443C80(v2, 0);
                    sub_4309B0(a1, 1);
                }
            }
        }
    }
}

//----- (00444410) --------------------------------------------------------
char* __cdecl sub_444410(int a1)
{
    char* result; // eax
    int v2; // edx
    unsigned __int8* v3; // ecx

    result = 0;
    v2 = 0;
    v3 = &byte_587000[94512];
    while (a1 != *(_DWORD*)v3)
    {
        v3 += 76;
        ++v2;
        if ((int)v3 >= (int)& byte_587000[95424])
            return result;
    }
    return (char*)& byte_587000[76 * v2 + 94516];
}

//----- (00444440) --------------------------------------------------------
void __cdecl sub_444440(int* a1)
{
    int* v1; // edi
    int* v2; // ebx
    wchar_t* v3; // esi
    int v4; // eax
    char v5[64]; // [esp+4h] [ebp-40h]

    v1 = a1;
    if (*a1)
    {
        v2 = a1;
        do
        {
            nox_sprintf(v5, "cmd_token:%S", *v1);
            v3 = loadString_sub_40F1D0(v5, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4441);
            v1[1] = (int)v3;
            sub_4444C0(*v1, (int)v3);
            if (nox_wcslen(v3) < 0x20)
            {
                if (v2[4])
                    sub_444440((int*)v2[4]);
            }
            v4 = v2[6];
            v2 += 6;
            v1 = v2;
        } while (v4);
    }
}

//----- (004444C0) --------------------------------------------------------
int __cdecl sub_4444C0(int a1, int a2)
{
    int v2; // eax
    int result; // eax

    v2 = *(_DWORD*)& byte_5D4594[823708];
    *(_DWORD*)& byte_5D4594[8 * *(_DWORD*)& byte_5D4594[823708] + 816500] = a1;
    *(_DWORD*)& byte_5D4594[8 * v2 + 816504] = a2;
    result = v2 + 1;
    *(_DWORD*)& byte_5D4594[823708] = result;
    return result;
}

//----- (004444F0) --------------------------------------------------------
int sub_4444F0()
{
    int* v0; // esi
    wchar_t* v1; // eax
    char v3[80]; // [esp+4h] [ebp-50h]

    sub_444560();
    v0 = (int*)& byte_587000[94468];
    do
    {
        nox_sprintf(v3, "cmd_token:%S", *v0);
        v1 = loadString_sub_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4476);
        sub_4444C0(*v0, (int)v1);
        ++v0;
    } while ((int)v0 < (int)& byte_587000[94500]);
    *(_DWORD*)& byte_5D4594[823696] = 0;
    sub_444440((int*)& byte_587000[97368]);
    return sub_444570();
}

//----- (00444560) --------------------------------------------------------
void sub_444560()
{
    *(_DWORD*)& byte_5D4594[823708] = 0;
}

//----- (00444570) --------------------------------------------------------
int sub_444570()
{
    int* v0; // esi
    wchar_t* v1; // eax
    int result; // eax
    char v3[80]; // [esp+4h] [ebp-50h]

    v0 = (int*)& byte_587000[94504];
    do
    {
        nox_sprintf(v3, "keybind:%S", *v0);
        v1 = loadString_sub_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 874);
        v0[1] = (int)v1;
        result = sub_4444C0(*v0, (int)v1);
        v0 += 19;
    } while ((int)v0 < (int)& byte_587000[95416]);
    return result;
}

//----- (004445C0) --------------------------------------------------------
void sub_4445C0()
{
    int v0; // ebx
    int v4; // ebx
    int v5; // ebp
    int v6; // eax
    int v7; // eax
    int result; // eax
    int v9; // [esp+10h] [ebp-Ch]
    int v10; // [esp+14h] [ebp-8h]
    int v11; // [esp+18h] [ebp-4h]

#if 0
    signed int v1; // eax
    int v2; // esi
    int v3; // eax
    if (sub_444D90())
    {
        v1 = sub_444DD0();
        v2 = v1;
        if (v1)
        {
            v3 = v1 + 5;
            if (v2 + 5 <= 450)
            {
                if (v3 <= 300)
                {
                    if (v3 <= 266)
                        v0 = v3 <= 200 ? 0 : 0xC8;
                    else
                        v0 = 266;
                }
                else
                {
                    v0 = 300;
                }
            }
            else
            {
                v0 = 450;
            }
        }
        else
        {
            v0 = 0;
        }
        if (!sub_444830() && v2 < 550)
            v0 = 200;
    }
    else
#endif
    {
        v0 = 0;
    }
    *(_DWORD*)& byte_587000[80808] = 1;
    *(_DWORD*)& byte_587000[80816] = 1;
    *(_DWORD*)& byte_587000[80840] = 1;
    *(_DWORD*)& byte_587000[80828] = 1;
    *(_DWORD*)& byte_587000[80832] = 1;
    if (v0 <= 266)
    {
        if (v0 != 266)
        {
            if (!v0)
            {
                v4 = 8;
                v5 = 75;
                *(_DWORD*)& byte_587000[80812] = 0;
                goto LABEL_21;
            }
            if (v0 == 200)
            {
                v4 = 8;
                v5 = 85;
                *(_DWORD*)& byte_587000[80812] = 1;
                LABEL_21:
                v6 = *(_DWORD*)& byte_5D4594[2650636];
                *(_DWORD*)& byte_5D4594[805844] = 0;
                BYTE1(v6) &= 0xFBu;
                *(_DWORD*)& byte_587000[80820] = 0;
                *(_DWORD*)& byte_587000[154952] = 0;
                *(_DWORD*)& byte_5D4594[1193152] = 0;
                *(_DWORD*)& byte_587000[154956] = 1;
                *(_DWORD*)& byte_587000[80824] = 0;
                *(_DWORD*)& byte_5D4594[805852] = 0;
                *(_DWORD*)& byte_587000[80836] = 0;
                *(_DWORD*)& byte_5D4594[2650636] = v6;
                *(_DWORD*)& byte_587000[80844] = 0;
                goto LABEL_30;
            }
            goto LABEL_29;
        }
        v4 = 8;
        goto LABEL_27;
    }
    if (v0 == 300)
    {
        v4 = 16;
        LABEL_27:
        v5 = 100;
        *(_DWORD*)& byte_587000[80812] = 1;
        *(_DWORD*)& byte_5D4594[805844] = 1;
        *(_DWORD*)& byte_587000[80820] = 1;
        *(_DWORD*)& byte_587000[154952] = 1;
        *(_DWORD*)& byte_5D4594[1193152] = 0;
        *(_DWORD*)& byte_587000[154956] = 1;
        *(_DWORD*)& byte_587000[80824] = 0;
        goto LABEL_28;
    }
    if (v0 == 450)
    {
        v4 = 16;
        v5 = 100;
        *(_DWORD*)& byte_587000[80812] = 1;
        *(_DWORD*)& byte_5D4594[805844] = 1;
        *(_DWORD*)& byte_587000[80820] = 1;
        *(_DWORD*)& byte_587000[154952] = 1;
        *(_DWORD*)& byte_5D4594[1193152] = 1;
        *(_DWORD*)& byte_587000[154956] = 1;
        *(_DWORD*)& byte_587000[80824] = 1;
        LABEL_28:
        v7 = *(_DWORD*)& byte_5D4594[2650636];
        *(_DWORD*)& byte_5D4594[805852] = 1;
        BYTE1(v7) |= 4u;
        *(_DWORD*)& byte_587000[80836] = 1;
        *(_DWORD*)& byte_5D4594[2650636] = v7;
        *(_DWORD*)& byte_587000[80844] = 1;
        goto LABEL_30;
    }
    LABEL_29:
    v4 = v9;
    v5 = v9;
    LABEL_30:
    sub_43BEB0_get_video_mode(&v11, &v10, &v9);
    v4 = 16; // 8 bit not supported
    sub_481420();
    if (!(byte_5D4594[2650637] & 2))
        sub_43BEF0_set_video_mode(default_win_width, default_win_height, v4);
    sub_4766A0(v5);
    if (sub_40A5C0(0x10000000))
        sub_476700(v5, 0);
    *(_DWORD*)& byte_5D4594[805856] = 1;
}
BOOL sub_444830()
{
    DebugBreak();
    return 0;
}
#if 0
//----- (00444830) --------------------------------------------------------
BOOL sub_444830()
{
    unsigned __int8 v11[40]; // [esp+Ch] [ebp-28h]

    _EAX = 0;
    __asm { cpuid }
    _EAX = 0;
    __asm { cpuid }
    return strcmp("GenuineIntel", (const char*)v11) == 0;
}
#endif

//----- (004449D0) --------------------------------------------------------
int __cdecl sub_4449D0(HWND wnd, int w, int h, int depth, int flags)
{
    int result; // eax

    result = sub_444AC0(wnd, w, h, depth, flags);
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_47D200();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_486090();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4B0B30();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4408E0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_49F610();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4338D0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AD100();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_48B1F0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_44D9A0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4B0650();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_49E3F0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_48C560();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4B02D0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AF8D0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AEE80();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AE520();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_49CB50();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_43F1C0();
    printf("%s: %d\n", __FUNCTION__, result);
    if (!result)
        return result;

    result = sub_4AE400();
    printf("%s: %d\n", __FUNCTION__, result);
    if (result)
        result = sub_49F4A0();
    printf("%s: %d\n", __FUNCTION__, result);
    return result;
}

// 4408F0: using guessed type void nullsub_3(void);
// 47D2B0: using guessed type void nullsub_6(void);
// 48C570: using guessed type void nullsub_11(void);
// 49CC60: using guessed type void nullsub_12(void);
// 49E4A0: using guessed type void nullsub_13(void);
// 49F6C0: using guessed type void nullsub_14(void);
// 4AD140: using guessed type void nullsub_15(void);
// 4AE410: using guessed type void nullsub_16(void);
// 4AEE90: using guessed type void nullsub_17(void);
// 4B02F0: using guessed type void nullsub_18(void);
// 4B0B80: using guessed type void nullsub_19(void);

//----- (00444D00) --------------------------------------------------------
void sub_444D00()
{
    EnterCriticalSection((LPCRITICAL_SECTION)& byte_5D4594[3799596]);
    sub_48A190();
    sub_4AD150();
    LeaveCriticalSection((LPCRITICAL_SECTION)& byte_5D4594[3799596]);
}

//----- (00444D30) --------------------------------------------------------
void sub_444D30()
{
    qmemcpy(ptr_5D4594_3799572, &obj_5D4594_3799660, sizeof(obj_5D4594_3799572_t));
}

//----- (00444D50) --------------------------------------------------------
void __cdecl sub_444D50(obj_5D4594_3799572_t* a1)
{
    qmemcpy(a1, ptr_5D4594_3799572, sizeof(obj_5D4594_3799572_t));
}

//----- (00444D70) --------------------------------------------------------
void __cdecl sub_444D70(obj_5D4594_3799572_t* a1)
{
    qmemcpy(ptr_5D4594_3799572, a1, sizeof(obj_5D4594_3799572_t));
}

#if 0
//----- (00444D90) --------------------------------------------------------
BOOL sub_444D90()
{
    unsigned int v0; // edx
    unsigned int v1; // et0
    unsigned int v2; // ebx
    unsigned int v3; // et0

    v0 = 0;
    v1 = __readeflags();
    v2 = v1;
    __writeeflags(v1 ^ 0x200000);
    v3 = __readeflags();
    if (v3 != v2)
    {
        _EAX = 0;
        __asm { cpuid }
        v0 = 0;
        if (BYTE1(_EAX) != 5)
        {
            if (_EAX)
            {
                _EAX = 1;
                __asm { cpuid }
                v0 = 0x800000 & _EDX;
            }
        }
    }
    return v0 != 0;
}

//----- (00444DD0) --------------------------------------------------------
signed int sub_444DD0()
{
    int v0; // ecx
    int v1; // eax
    unsigned int v2; // ebx
    unsigned __int64 v3; // rax
    unsigned __int64 v4; // rax
    unsigned int v5; // esi
    DWORD v6; // edi
    int v7; // eax
    unsigned int v8; // ecx
    signed int result; // eax
    LARGE_INTEGER Frequency; // [esp+4h] [ebp-30h]
    LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-28h]
    LARGE_INTEGER v12; // [esp+14h] [ebp-20h]
    int v13; // [esp+1Ch] [ebp-18h]
    int v14; // [esp+20h] [ebp-14h]
    int v15; // [esp+24h] [ebp-10h]
    unsigned int v16; // [esp+28h] [ebp-Ch]
    int v17; // [esp+2Ch] [ebp-8h]
    int v18; // [esp+30h] [ebp-4h]

    if (!QueryPerformanceFrequency(&Frequency))
        return 0;
    v0 = 0;
    v1 = 0;
    v2 = 0;
    v16 = 0;
    v18 = 0;
    while (1)
    {
        v17 = v0;
        ++v18;
        v15 = v1;
        QueryPerformanceCounter(&PerformanceCount);
        v12 = PerformanceCount;
        do
            QueryPerformanceCounter(&v12);
        while (v12.LowPart - PerformanceCount.LowPart < 0x32);
        v3 = __rdtsc();
        v13 = v3;
        PerformanceCount = v12;
        do
            QueryPerformanceCounter(&v12);
        while (v12.LowPart - PerformanceCount.LowPart < 0x3E8);
        v4 = __rdtsc();
        v14 = v4;
        v5 = v4 - v13;
        v2 += v4 - v13;
        v6 = (100000 * v12.LowPart - 100000 * PerformanceCount.LowPart) / (Frequency.LowPart / 0xA);
        v16 += v6;
        if (v6 % Frequency.LowPart > Frequency.LowPart >> 1)
            ++v6;
        v0 = v5 / v6;
        if (v5 % v6 > v6 >> 1)
            ++v0;
        v7 = v0 + v15 + v17;
        if (v18 >= 3
            && (v18 >= 20
                || (unsigned int)(3 * v0 - v7) <= 3 && (unsigned int)(3 * v17 - v7) <= 3 && (unsigned int)(3 * v15 - v7) <= 3))
        {
            break;
        }
        v1 = v17;
    }
    v8 = 10 * v2 / v16;
    if (100 * v2 / v16 - 10 * v8 >= 6)
        ++v8;
    result = v2 / v16;
    if (v8 - 10 * (v2 / v16) >= 6)
        ++result;
    if (result < 0)
        result = 0;
    return result;
}
#endif

//----- (00445440) --------------------------------------------------------
int sub_445440()
{
    return 1;
}

//----- (00445450) --------------------------------------------------------
wchar_t* sub_445450()
{
    unsigned __int8* v0; // esi
    wchar_t* result; // eax

    v0 = &byte_5D4594[824440];
    do
    {
        result = nox_wcscpy((wchar_t*)v0 - 318, (const wchar_t*)& byte_5D4594[825740]);
        *(_DWORD*)v0 = 0;
        v0[4] = 0;
        v0 += 644;
    } while ((int)v0 < (int)& byte_5D4594[826372]);
    *(_DWORD*)& byte_5D4594[825736] = 0;
    return result;
}

//----- (00445490) --------------------------------------------------------
void __cdecl sub_445490(wchar_t* a1)
{
    int v1; // eax
    int v2; // eax
    wchar_t* v3; // eax

    if (a1)
    {
        v1 = ++ * (_DWORD*)& byte_5D4594[825736];
        if (*(_DWORD*)& byte_5D4594[825736] == 3)
        {
            v1 = 0;
            *(_DWORD*)& byte_5D4594[825736] = 0;
        }
        nox_wcscpy((wchar_t*)& byte_5D4594[644 * v1 + 823804], a1);
        v2 = 644 * *(_DWORD*)& byte_5D4594[825736];
        *(_DWORD*)& byte_5D4594[v2 + 824440] = *(_DWORD*)& byte_5D4594[2598000]
                                                           + 4 * *(_DWORD*)& byte_5D4594[2649704]
                                                                             + *(_DWORD*)& byte_5D4594[2649704];
        byte_5D4594[v2 + 824444] = 0;
        v3 = loadString_sub_40F1D0((char*)& byte_587000[107916], 0, "C:\\NoxPost\\src\\Client\\Gui\\guimsg.c", 69);
        sub_450C00(6u, v3, a1);
    }
}

//----- (00445530) --------------------------------------------------------
int sub_445530()
{
    char* v0; // eax
    int v1; // ebp
    int v2; // eax
    int v3; // ebx
    int result; // eax
    int v5; // ebx
    unsigned __int16* v6; // ebx
    int v7; // kr00_4
    unsigned __int8* v8; // esi
    int v9; // edi
    int v10; // esi
    int v11; // ecx
    int i; // [esp+10h] [ebp-Ch]
    int v13; // [esp+14h] [ebp-8h]
    int v14; // [esp+18h] [ebp-4h]

    v13 = 0;
    v0 = sub_437250();
    v1 = 3 * *((_DWORD*)v0 + 9) / 4 + *((_DWORD*)v0 + 1) - 15;
    v2 = *(_DWORD*)& byte_5D4594[825736];
    for (i = *(_DWORD*)& byte_5D4594[825736]; ; v2 = i)
    {
        v3 = 161 * v2;
        result = *(_DWORD*)& byte_5D4594[2598000];
        v5 = 4 * v3;
        if (*(_DWORD*)& byte_5D4594[v5 + 824440] < *(int*)& byte_5D4594[2598000])
            break;
        sub_434390(*(int*)& byte_5D4594[2650656]);
        v6 = (unsigned __int16*)& byte_5D4594[v5 + 823804];
        sub_43F840(0, v6, &v14, 0, 0);
        v7 = nox_win_width - v14;
        v8 = &byte_587000[107848];
        v9 = (nox_win_width - v14) / 2;
        do
        {
            sub_43F6E0(0, (__int16*)v6, v9 + *(_DWORD*)v8, v1 + *((_DWORD*)v8 + 1));
            v8 += 8;
        } while ((int)v8 < (int)& byte_587000[107880]);
        v10 = v13;
        if (v13)
            sub_434390(*(int*)& byte_5D4594[2597996]);
        else
            sub_434390(*(int*)& byte_5D4594[2523948]);
        sub_43F6E0(0, (__int16*)v6, v7 / 2, v1);
        v11 = -4 - sub_43F320(0);
        result = i;
        v1 += v11;
        if (i)
            --i;
        else
            i = 2;
        ++v13;
        if (v10 + 1 >= 3)
            break;
    }
    return result;
}

//----- (00445650) --------------------------------------------------------
int sub_445650()
{
    wchar_t* v0; // eax

    *(_DWORD*)& byte_5D4594[825748] = sub_42F970("ChatIcon");
    *(_DWORD*)& byte_5D4594[825744] = nox_window_new(
            0,
            136,
            nox_win_width - 50,
            nox_win_height / 2 - 50,
            50,
            50,
            0);
    sub_46AE60(*(int*)& byte_5D4594[825744], *(int*)& byte_5D4594[825748]);
    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[825744], 0, sub_4456E0, 0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[107980], 0, "C:\\NoxPost\\src\\client\\Gui\\chaticon.c", 73);
    sub_46B000((wchar_t*)(*(_DWORD*)& byte_5D4594[825744] + 36), v0);
    return 1;
}

//----- (004456E0) --------------------------------------------------------
int __cdecl sub_4456E0(int* a1)
{
    int* v1; // esi
    int v2; // edx
    int v4; // [esp+4h] [ebp-4h]

    v1 = a1;
    sub_46AA60(a1, &a1, &v4);
    v2 = v1[25];
    a1 = (int*)((char*)a1 + v1[24]);
    sub_47D2C0(v1[15], (int)a1, v2 + v4);
    return 1;
}

//----- (00445730) --------------------------------------------------------
int __cdecl sub_445730(int a1)
{
    return nox_window_set_hidden(*(int*)& byte_5D4594[825744], a1);
}

//----- (00445750) --------------------------------------------------------
BOOL sub_445750()
{
    return *(_DWORD*)& byte_5D4594[825744] && !wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[825744]);
}

//----- (00445770) --------------------------------------------------------
int sub_445770()
{
    int result; // eax

    result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[825744]);
    *(_DWORD*)& byte_5D4594[825744] = 0;
    return result;
}

//----- (00445790) --------------------------------------------------------
int sub_445790()
{
    int result; // eax
    wchar_t* v1; // eax

    result = nox_new_window_from_file("QuitMenu.wnd", sub_445840);
    *(_DWORD*)& byte_5D4594[825760] = result;
    if (result)
    {
        nox_window_set_all_funcs((_DWORD*)result, sub_445BB0, sub_445BC0, 0);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 56) = *(_DWORD*)& byte_5D4594[2650656];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 16) = (nox_win_width
                                                            - *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 8))
                                                           / 2;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 8)
                                                           + *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 16);
        sub_445C40();
        *(_DWORD*)& byte_5D4594[825752] = 0;
        *(_DWORD*)& byte_5D4594[825768] = 0;
        v1 = loadString_sub_40F1D0((char*)& byte_587000[108044], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 309);
        nox_swprintf((wchar_t*)& byte_5D4594[825772], L"%s", v1);
        result = 1;
    }
    return result;
}

//----- (00445840) --------------------------------------------------------
int __cdecl sub_445840(_DWORD* a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int v4; // eax
    int result; // eax
    int v6; // eax
    int v7; // eax
    char* v8; // eax
    int v9; // eax
    int v10; // eax
    int v12; // eax
    wchar_t* v13; // eax
    int v14; // eax
    wchar_t* v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // ecx
    _DWORD* v19; // eax
    int v20; // eax
    int v21; // eax
    wchar_t* v22; // [esp-18h] [ebp-18h]
    wchar_t* v23; // [esp-18h] [ebp-18h]

    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v3)
    {
        case 9001:
            sub_445C40();
            sub_413A00(1);
            if (!sub_40A5C0(2048) || sub_4372B0())
            {
                sub_445B40();
                v17 = a3[9];
                LOBYTE(v17) = v17 & 0xFD;
                a3[9] = v17;
                result = 0;
            }
            else
            {
                v23 = loadString_sub_40F1D0((char*)& byte_587000[108224], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 199);
                v15 = loadString_sub_40F1D0((char*)& byte_587000[108288], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 198);
                sub_449A10(0, (int)v15, (int)v23, 56, (int (*)(void))sub_445B40, sub_445BA0);
                v16 = a3[9];
                LOBYTE(v16) = v16 & 0xFD;
                a3[9] = v16;
                result = 0;
            }
            break;
        case 9002:
            v18 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 120);
            if ((v18 & 0x8000) == 0)
            {
                sub_445C40();
                if (sub_40A5C0(2048))
                {
                    sub_4DB130("AUTOSAVE");
                    sub_4DB170(1, 0, 0);
                }
                goto LABEL_27;
            }
            v19 = sub_46B0C0(a1, v3);
            sub_46ABB0((int)v19, 0);
            v20 = a3[9];
            LOBYTE(v20) = v20 & 0xFD;
            a3[9] = v20;
            result = 0;
            break;
        case 9003:
            sub_445C40();
            if (sub_40A5C0(2048))
                sub_46D580();
            else
                sub_41CE00();
            if (sub_43C6E0())
                goto LABEL_27;
            sub_43CF70();
            v12 = a3[9];
            LOBYTE(v12) = v12 & 0xFD;
            a3[9] = v12;
            result = 0;
            break;
        case 9004:
            sub_46ADE0(*(int*)& byte_5D4594[825760]);
            v22 = loadString_sub_40F1D0((char*)& byte_587000[108096], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 185);
            v13 = loadString_sub_40F1D0((char*)& byte_587000[108160], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 184);
            sub_449A10(*(int*)& byte_5D4594[825760], (int)v13, (int)v22, 56, sub_445B20, sub_445B30);
            v14 = a3[9];
            LOBYTE(v14) = v14 & 0xFD;
            a3[9] = v14;
            result = 0;
            break;
        case 9005:
            sub_445C40();
            sub_4ADA40();
            v4 = a3[9];
            LOBYTE(v4) = v4 & 0xFD;
            a3[9] = v4;
            result = 0;
            break;
        case 9006:
            goto LABEL_11;
        case 9007:
            if (sub_40A5C0(1))
            {
                v8 = sub_417040(*(int*)& byte_5D4594[2616328]);
                sub_443E90((int)v8, 0, 0);
                LABEL_11:
                sub_445C40();
                v9 = a3[9];
                LOBYTE(v9) = v9 & 0xFD;
                a3[9] = v9;
                result = 0;
            }
            else
            {
                sub_440950(0, 0);
                sub_445C40();
                v7 = a3[9];
                LOBYTE(v7) = v7 & 0xFD;
                a3[9] = v7;
                result = 0;
            }
            break;
        case 9008:
            sub_445C40();
            sub_457500();
            v10 = a3[9];
            LOBYTE(v10) = v10 & 0xFD;
            a3[9] = v10;
            result = 0;
            break;
        case 9009:
            sub_445C40();
            if (sub_40A5C0(4096))
                sub_48CB10(4);
            else
                sub_48CB10(0);
            v6 = a3[9];
            LOBYTE(v6) = v6 & 0xFD;
            a3[9] = v6;
            result = 0;
            break;
        default:
        LABEL_27:
            v21 = a3[9];
            LOBYTE(v21) = v21 & 0xFD;
            a3[9] = v21;
            result = 0;
            break;
    }
    return result;
}
// 445B20: using guessed type int sub_445B20();

//----- (00445B20) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
int sub_445B20()
{
    sub_4460C0();
    return sub_445C40();
}
// 445B20: using guessed type int sub_445B20();

//----- (00445B30) --------------------------------------------------------
int sub_445B30()
{
    return sub_46ADC0(*(int*)& byte_5D4594[825760]);
}

//----- (00445B40) --------------------------------------------------------
void* sub_445B40()
{
    void* result; // eax
    wchar_t* v1; // eax
    wchar_t* v2; // [esp-10h] [ebp-10h]

    sub_413A00(0);
    result = sub_4DB790("AUTOSAVE");
    if (!result)
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[108368], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 88);
        v1 = loadString_sub_40F1D0((char*)& byte_587000[108432], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 87);
        result = sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
    }
    return result;
}

//----- (00445BA0) --------------------------------------------------------
int sub_445BA0()
{
    return sub_413A00(0);
}

//----- (00445BB0) --------------------------------------------------------
int sub_445BB0()
{
    return 1;
}

//----- (00445BC0) --------------------------------------------------------
int __cdecl sub_445BC0(_DWORD* a1)
{
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60(a1, &xLeft, &yTop);
    sub_49CF10(xLeft, yTop, a1[2], a1[3]);
    return 1;
}

//----- (00445C00) --------------------------------------------------------
int sub_445C00()
{
    int result; // eax

    result = sub_46ADA0(*(int*)& byte_5D4594[825760]);
    if (result & 0x10)
        result = sub_445C40();
    return result;
}

//----- (00445C20) --------------------------------------------------------
int sub_445C20()
{
    int result; // eax

    result = sub_46ADA0(*(int*)& byte_5D4594[825760]);
    if (!(result & 0x10))
        result = sub_445C40();
    return result;
}

//----- (00445C40) --------------------------------------------------------
int sub_445C40()
{
    int result; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // esi
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // esi
    _DWORD* v12; // eax
    _DWORD* v13; // esi
    _DWORD* v14; // eax
    _DWORD* v15; // eax
    _DWORD* v16; // eax
    _DWORD* v17; // eax
    _DWORD* v18; // eax
    _DWORD* v19; // eax
    wchar_t* v20; // [esp-4h] [ebp-8h]
    wchar_t* v21; // [esp-4h] [ebp-8h]

    if (sub_46ADA0(*(int*)& byte_5D4594[825760]) & 0x10)
    {
        if (!*(_DWORD*)& byte_5D4594[2614252]
            || !sub_40A5C0(2048)
            || (result = *(_DWORD*)(*(_DWORD*)& byte_5D4594[2614252] + 276), result != 2) && result != 1 && result != 51)
        {
            result = sub_45D9B0();
            if (result != 1)
            {
                result = sub_413A50();
                if (result != 1)
                {
                    sub_452D80(921, 100);
                    sub_46A8C0(*(int*)& byte_5D4594[825760]);
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 4) |= 8u;
                    sub_46ADC0(*(int*)& byte_5D4594[825760]);
                    if (sub_40A5C0(2048))
                    {
                        v20 = loadString_sub_40F1D0((char*)& byte_587000[108496], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 396);
                        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                        sub_46AEE0((int)v1, (int)v20);
                        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9001);
                        nox_window_set_hidden((int)v2, 0);
                        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9002);
                        nox_window_set_hidden((int)v3, 0);
                        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                        nox_window_set_hidden((int)v4, 1);
                        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9008);
                        nox_window_set_hidden((int)v5, 1);
                        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9009);
                        nox_window_set_hidden((int)v6, 1);
                        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9004);
                        sub_46A9B0(v7, v6[4], v6[5]);
                        sub_413A00(1);
                        result = sub_46AB20(*(_DWORD * *)& byte_5D4594[825760], 220, 285);
                    }
                    else
                    {
                        v21 = loadString_sub_40F1D0((char*)& byte_587000[108548], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 427);
                        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                        sub_46AEE0((int)v8, (int)v21);
                        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9001);
                        nox_window_set_hidden((int)v9, 1);
                        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9002);
                        nox_window_set_hidden((int)v10, 1);
                        v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                        nox_window_set_hidden((int)v11, 0);
                        sub_46ABB0((int)v11, 1);
                        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9008);
                        nox_window_set_hidden((int)v12, 0);
                        v13 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9009);
                        nox_window_set_hidden((int)v13, 0);
                        sub_46AEE0((int)v13, (int)& byte_5D4594[825772]);
                        if (sub_40A5C0(49152) || !sub_417DD0())
                            sub_46ABB0((int)v13, 0);
                        else
                            sub_46ABB0((int)v13, 1);
                        v14 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9004);
                        sub_46A9B0(v14, v13[4], v13[5] + 45);
                        sub_46AB20(*(_DWORD * *)& byte_5D4594[825760], 220, 330);
                        result = sub_40A5C0(4096);
                        if (result)
                        {
                            v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                            sub_46ABB0((int)v15, 0);
                            v16 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                            result = sub_46ABB0((int)v16, 0);
                        }
                        if (*(_DWORD*)& byte_5D4594[2650636] & 0x40000)
                        {
                            v17 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9007);
                            sub_46ABB0((int)v17, 0);
                            v18 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9005);
                            sub_46ABB0((int)v18, 0);
                            v19 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], 9003);
                            result = sub_46ABB0((int)v19, 0);
                        }
                    }
                }
            }
        }
    }
    else
    {
        sub_46B500(0);
        sub_46ADE0(*(int*)& byte_5D4594[825760]);
        nox_window_set_hidden(*(int*)& byte_5D4594[825760], 1);
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 4) &= 0xFFFFFFF7;
        result = sub_413A00(0);
    }
    return result;
}

//----- (00445FF0) --------------------------------------------------------
_DWORD* sub_445FF0()
{
    int i; // esi
    _DWORD* result; // eax

    if (*(_DWORD*)& byte_5D4594[825760])
        * (_DWORD*)(*(_DWORD*)& byte_5D4594[825760] + 56) = *(_DWORD*)& byte_5D4594[2650656];
    for (i = 9001; i <= 9006; ++i)
    {
        result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[825760], i);
        if (result)
            result[26] = *(_DWORD*)& byte_5D4594[2614256];
    }
    return result;
}

//----- (00446030) --------------------------------------------------------
BOOL sub_446030()
{
    return *(_DWORD*)& byte_5D4594[825768] != 0;
}

//----- (00446040) --------------------------------------------------------
int sub_446040()
{
    return *(_DWORD*)& byte_5D4594[825768];
}

//----- (00446050) --------------------------------------------------------
int sub_446050()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[2598000];
    *(_DWORD*)& byte_5D4594[825768] = *(_DWORD*)& byte_5D4594[2598000];
    return result;
}

//----- (00446060) --------------------------------------------------------
void sub_446060()
{
    *(_DWORD*)& byte_5D4594[825768] = 0;
}

//----- (00446070) --------------------------------------------------------
void sub_446070()
{
    if (!-- * (_DWORD*)& byte_5D4594[825752])
        sub_446380();
}

//----- (00446090) --------------------------------------------------------
BOOL sub_446090()
{
    return *(_DWORD*)& byte_5D4594[825752] == 0;
}

//----- (004460A0) --------------------------------------------------------
int __cdecl sub_4460A0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[825756] = a1;
    return result;
}

//----- (004460B0) --------------------------------------------------------
int sub_4460B0()
{
    return *(_DWORD*)& byte_5D4594[825756];
}

//----- (004460C0) --------------------------------------------------------
int sub_4460C0()
{
    int result; // eax

    if (sub_40A5C0(4096))
    {
        if (sub_40A5C0(1))
        {
            result = sub_4DCD40();
        }
        else if (sub_4460B0())
        {
            sub_4460A0(0);
            result = sub_446140();
        }
        else
        {
            sub_41CE00();
            result = sub_4460A0(1);
        }
    }
    else
    {
        *(_DWORD*)& byte_5D4594[825764] = 1;
        result = sub_40A5C0(4096);
        if (result)
        {
            result = sub_40A5C0(1);
            if (result)
                result = sub_4D6B10(0);
        }
    }
    return result;
}

//----- (00446140) --------------------------------------------------------
int sub_446140()
{
    int result; // eax

    *(_DWORD*)& byte_5D4594[825764] = 1;
    result = sub_40A5C0(4096);
    if (result)
    {
        result = sub_40A5C0(1);
        if (result)
            result = sub_4D6B10(0);
    }
    return result;
}

//----- (00446180) --------------------------------------------------------
int sub_446180()
{
    return *(_DWORD*)& byte_5D4594[825764];
}

//----- (00446190) --------------------------------------------------------
void sub_446190()
{
    wchar_t* v1; // eax
    wchar_t* v2; // eax
    wchar_t* v3; // [esp-12h] [ebp-14h]
    char v4; // [esp+1h] [ebp-1h]

    *(_DWORD*)& byte_5D4594[825764] = 0;
    if (sub_40A5C0(1))
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[108608], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 667);
        sub_413D30((char*)& byte_587000[108632], v1);
    }
    if (sub_40A5C0(0x2000000))
    {
        sub_43C260();
        sub_41E300(9);
        sub_44B000();
    }
    else if (sub_4D6F50())
    {
        if (sub_4D6F30())
            sub_43C2F0();
        sub_4D70B0();
        sub_4D6F40(0);
        sub_4D6F90(0);
    }
    if (!*(_DWORD*)& byte_5D4594[825768])
    {
        *(_DWORD*)& byte_5D4594[825752] = 0;
        *(_DWORD*)& byte_5D4594[825768] = *(_DWORD*)& byte_5D4594[2598000];
        if (sub_40A5C0(1))
        {
            if (sub_43AF70() == 1 && sub_40A5C0(49152))
                sub_416150(15, 0);
            sub_509CB0();
        }
        if (sub_40A5C0(1))
        {
            *(_DWORD*)& byte_5D4594[825752] = sub_416F40() - 1;
            sub_467440(0);
            if (*(_DWORD*)& byte_5D4594[825752] > 0)
            {
                v4 = -57;
                sub_4E5420(159, &v4, 1, 0, 1);
                v3 = loadString_sub_40F1D0((char*)& byte_587000[108672], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 737);
                v2 = loadString_sub_40F1D0((char*)& byte_587000[108724], 0, "C:\\NoxPost\\src\\client\\Gui\\guiquit.c", 736);
                sub_449A10(0, (int)v2, (int)v3, 0, 0, 0);
                sub_44A360(1);
                goto LABEL_20;
            }
        }
        else if (!sub_40A5C0(0x2000))
        {
            goto LABEL_20;
        }
        sub_446380();
    }
    LABEL_20:
    if (*(_DWORD*)& byte_5D4594[2650652])
    {
        if (sub_41E2F0() == 9)
        {
            sub_41F4B0();
            sub_41EC30();
            sub_446490(0);
            sub_44B000();
        }
    }
}

//----- (00446360) --------------------------------------------------------
unsigned int sub_446360()
{
    unsigned int result; // eax

    if (*(_DWORD*)& byte_5D4594[825760])
        result = ((unsigned int)~sub_46ADA0(*(int*)& byte_5D4594[825760]) >> 4) & 1;
    else
        result = 0;
    return result;
}

//----- (00446380) --------------------------------------------------------
void sub_446380()
{
    sub_44A400();
    if (sub_40A5C0(0x2000) && !sub_40A5C0(4096) && !sub_4D6F30())
        sub_41CEE0((int)& byte_5D4594[2660684], 1);
    sub_4597E0(1);
    sub_43DDD0(0);
    sub_43DE60();
    sub_446060();
}

//----- (004463E0) --------------------------------------------------------
int __cdecl sub_4463E0(int a1)
{
    FILE* result; // eax
    FILE* v2; // edi
    char* v3; // eax
    int result2 = 0;

    *(_DWORD*)& byte_5D4594[826036] = 0;
    *(_DWORD*)& byte_5D4594[4 * a1 + 826040] = 0;
    result = fopen("motd.txt", "rb");
    v2 = result;
    if (result)
    {
        fseek(result, 0, 2);
        *(_DWORD*)& byte_5D4594[4 * a1 + 826040] = ftell(v2);
        fseek(v2, 0, 0);
        v3 = (char*)nox_calloc(*(_DWORD*)& byte_5D4594[4 * a1 + 826040] + 1, 1u);
        *(_DWORD*)& byte_5D4594[826036] = v3;
        if (v3)
        {
            sub_40ADD0_fread(v3, *(_DWORD*)& byte_5D4594[4 * a1 + 826040], 1u, v2);
            v3 = *(char**)& byte_5D4594[826036];
        }
        v3[(*(_DWORD*)& byte_5D4594[4 * a1 + 826040])++] = 0;
        result2 = fclose(v2);
    }
    return result2;
}

//----- (00446490) --------------------------------------------------------
LPVOID __cdecl sub_446490(void* a1)
{
    LPVOID result; // eax

    result = *(LPVOID*)& byte_5D4594[826036];
    if (*(_DWORD*)& byte_5D4594[826036])
    {
        free(*(LPVOID*)& byte_5D4594[826036]);
        result = a1;
    }
    *(_DWORD*)& byte_5D4594[826036] = 0;
    *(_DWORD*)& byte_5D4594[4 * (_DWORD)a1 + 826040] = 0;
    return result;
}

//----- (004464D0) --------------------------------------------------------
LPVOID __cdecl sub_4464D0(int a1, _DWORD* a2)
{
    *a2 = *(_DWORD*)& byte_5D4594[4 * a1 + 826040];
    return *(LPVOID*)& byte_5D4594[826036];
}

//----- (004464F0) --------------------------------------------------------
int __cdecl sub_4464F0(int a1, _DWORD* a2)
{
    if (!*(_DWORD*)& byte_5D4594[4 * a1 + 826056])
        return 0;
    *a2 = *(_DWORD*)& byte_5D4594[4 * a1 + 826048];
    return *(_DWORD*)& byte_5D4594[4 * a1 + 826056];
}

//----- (00446520) --------------------------------------------------------
void __cdecl sub_446520(int a1, const void* a2, int a3)
{
    void* v3; // edi

    if (a2)
    {
        if (a3 > 0)
        {
            v3 = nox_calloc(a3, 1u);
            *(_DWORD*)& byte_5D4594[4 * a1 + 826056] = v3;
            qmemcpy(v3, a2, a3);
            *(_DWORD*)& byte_5D4594[4 * a1 + 826048] = a3;
            *(_DWORD*)& byte_5D4594[4 * a1 + 826064] = 1;
        }
    }
}

//----- (00446580) --------------------------------------------------------
int __cdecl sub_446580(int a1)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[4 * a1 + 826056];
    if (result)
    {
        free(*(LPVOID*)& byte_5D4594[4 * a1 + 826056]);
        *(_DWORD*)& byte_5D4594[4 * a1 + 826056] = 0;
        *(_DWORD*)& byte_5D4594[4 * a1 + 826048] = 0;
        *(_DWORD*)& byte_5D4594[4 * a1 + 826064] = 0;
    }
    return result;
}

//----- (004465C0) --------------------------------------------------------
int sub_4465C0()
{
    _DWORD* v0; // eax
    _DWORD* v1; // eax
    _DWORD* v2; // edi
    char* v3; // ebx
    _DWORD* v4; // esi
    _DWORD* v5; // ebp
    char* v7; // [esp+10h] [ebp-8h]
    _DWORD* v8; // [esp+14h] [ebp-4h]

    v0 = nox_new_window_from_file("motd.wnd", sub_4466C0);
    *(_DWORD*)& byte_5D4594[826028] = v0;
    v1 = sub_46B0C0(v0, 4203);
    *(_DWORD*)& byte_5D4594[826032] = v1;
    v2 = (_DWORD*)v1[8];
    v7 = sub_42F970("UISlider");
    v3 = sub_42F970("UISliderLit");
    v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4204);
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4205);
    v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4206);
    *(_DWORD*)(v4[100] + 8) = 16;
    *(_DWORD*)(v4[100] + 12) = 10;
    sub_4B5700((int)v4, 0, 0, (int)v7, (int)v3, (int)v3);
    sub_46B280((int)v4, *(int*)& byte_5D4594[826032]);
    sub_46B280((int)v5, *(int*)& byte_5D4594[826032]);
    sub_46B280((int)v8, *(int*)& byte_5D4594[826032]);
    v2[9] = v4;
    v2[7] = v5;
    v2[8] = v8;
    return *(_DWORD*)& byte_5D4594[826028];
}

//----- (004466C0) --------------------------------------------------------
int __cdecl sub_4466C0(int a1, int a2, int a3, int a4)
{
    if (a2 == 16391)
    {
        sub_452D80(766, 100);
        sub_446780();
    }
    return 0;
}

//----- (004466F0) --------------------------------------------------------
char* __cdecl sub_4466F0(char* a1, _BYTE* a2)
{
    char* v2; // edx
    char* v3; // eax
    char v4; // cl
    char* result; // eax

    v2 = a2;
    v3 = a1;
    *a2 = 0;
    if (!*a1)
        return 0;
    while (1)
    {
        v4 = *v3;
        if (!*v3)
        {
            *v2 = 0;
            return 0;
        }
        if (v4 == 10)
        {
            *v2 = 0;
            return v3 + 1;
        }
        if (v4 == 13)
            break;
        *v2++ = v4;
        ++v3;
    }
    result = v3 + 1;
    *v2 = 0;
    if (*result == 10)
        ++result;
    return result;
}

//----- (00446730) --------------------------------------------------------
_BYTE* __cdecl sub_446730(_BYTE* a1)
{
    _BYTE* result; // eax
    wchar_t v2[256]; // [esp+0h] [ebp-200h]

    result = a1;
    if (*a1)
    {
        nox_swprintf(v2, L"%S", a1);
        result = (_BYTE*)nox_window_call_field_94(*(int*)& byte_5D4594[826032], 16397, (int)v2, -1);
    }
    return result;
}

//----- (00446780) --------------------------------------------------------
int sub_446780()
{
    if (wndIsShown_sub_46ACC0(*(int*)& byte_5D4594[826028]))
        return 0;
    sub_46B500(0);
    nox_window_set_hidden(*(int*)& byte_5D4594[826028], 1);
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[826028] + 4) &= 0xFFFFFFF7;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[826032] + 4) &= 0xFFFFFFF7;
    nox_window_call_field_94(*(int*)& byte_5D4594[826032], 16399, 0, 0);
    return 1;
}

//----- (004467F0) --------------------------------------------------------
void sub_4467F0()
{
    unsigned int result; // eax
    _DWORD* v1; // eax
    char* v2; // esi
    _DWORD* v3; // eax
    char v4[256]; // [esp+0h] [ebp-100h]

    result = sub_446360();
    if (!result)
    {
        result = sub_4D6F50();
        if (!result || (result = sub_40A5C0(128)) == 0)
        {
            if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
            {
                result = sub_46ADA0(*(int*)& byte_5D4594[826028]);
                if (result & 0x10)
                {
                    result = sub_44A4A0();
                    if (!result)
                    {
                        result = sub_49C810();
                        if (!result)
                        {
                            result = sub_49CB40();
                            if (!result)
                            {
                                sub_46A8C0(*(int*)& byte_5D4594[826028]);
                                v1 = sub_46B0C0(0, 4100);
                                if (v1)
                                    sub_46A8C0((int)v1);
                                *(_DWORD*)(*(_DWORD*)& byte_5D4594[826028] + 4) |= 8u;
                                *(_DWORD*)(*(_DWORD*)& byte_5D4594[826032] + 4) |= 8u;
                                v2 = *(char**)& byte_5D4594[826060];
                                if (*(_DWORD*)& byte_5D4594[826060])
                                {
                                    while (1)
                                    {
                                        v2 = sub_4466F0(v2, v4);
                                        if (!v2)
                                            break;
                                        if (!v4[0])
                                            strcpy(v4, " ");
                                        sub_446730(v4);
                                    }
                                    if (v4[0])
                                        sub_446730(v4);
                                }
                                v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[826028], 4202);
                                sub_46B500((int)v3);
                            }
                        }
                    }
                }
            }
            *(_DWORD*)& byte_5D4594[826068] = 0;
        }
    }
}

//----- (00446940) --------------------------------------------------------
int __cdecl sub_446940(int a1)
{
    return *(_DWORD*)& byte_5D4594[4 * a1 + 826064];
}

//----- (00446950) --------------------------------------------------------
BOOL sub_446950()
{
    return *(_DWORD*)& byte_5D4594[826028] && !(sub_46ADA0(*(int*)& byte_5D4594[826028]) & 0x10);
}

//----- (00446970) --------------------------------------------------------
char* sub_446970()
{
    char* result; // eax
    int v1; // edi
    unsigned __int8* v2; // esi

    result = *(char**)& byte_5D4594[829568];
    if (!*(_DWORD*)& byte_5D4594[829568])
    {
        result = *(char**)& byte_587000[108852];
        v1 = 0;
        if (*(_DWORD*)& byte_587000[108852])
        {
            v2 = &byte_587000[108848];
            do
            {
                *(_DWORD*)v2 = loadString_sub_40F1D0(*((char**)v2 + 1), 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 181);
                result = (char*) * ((_DWORD*)v2 + 3);
                v2 += 8;
                ++v1;
            } while (result);
        }
        *(_DWORD*)& byte_5D4594[826092] = v1;
        *(_DWORD*)& byte_5D4594[829568] = 1;
    }
    return result;
}

//----- (004469D0) --------------------------------------------------------
wchar_t* __cdecl sub_4469D0(int a1)
{
    if (a1 / *(_DWORD*)& byte_5D4594[826092] + 1 <= 1)
        return *(wchar_t**)& byte_587000[8 * a1 + 108848];
    nox_swprintf(
            (wchar_t*)& byte_5D4594[827140],
            L"%s %d",
            *(_DWORD*)& byte_587000[8 * (a1 % *(_DWORD*)& byte_5D4594[826092]) + 108848],
            a1 / *(_DWORD*)& byte_5D4594[826092] + 1);
    return (wchar_t*)& byte_5D4594[827140];
}

//----- (00446A20) --------------------------------------------------------
int __cdecl sub_446A20(wchar_t* a1)
{
    wchar_t* v1; // eax
    wchar_t* v3; // [esp-10h] [ebp-10h]

    sub_446CC0(0);
    sub_41F140(a1);
    sub_44A400();
    v3 = loadString_sub_40F1D0((char*)& byte_587000[110256], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 212);
    v1 = loadString_sub_40F1D0((char*)& byte_587000[110324], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 211);
    sub_449A10(*(int*)& byte_5D4594[829480], (int)v1, (int)v3, 288, 0, 0);
    return sub_44A4B0();
}

//----- (00446A90) --------------------------------------------------------
int sub_446A90()
{
    int result; // eax

    *(_BYTE*)(*(_DWORD*)& byte_5D4594[829520] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    result = 1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[829520] + 52) = sub_4379F0;
    return result;
}

//----- (00446AD0) --------------------------------------------------------
int __cdecl sub_446AD0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[829520] + 52) = a1;
    return result;
}

//----- (00446AE0) --------------------------------------------------------
const char* __cdecl sub_446AE0(int a1)
{
    const char* result; // eax
    const char* v2; // ebx
    char v3[108]; // [esp+8h] [ebp-6Ch]

    result = sub_446BC0(a1);
    v2 = result;
    if (result)
    {
        strcpy(&v3[36], result);
        if (sub_41F9E0((int)v3))
        {
            result = (const char*)loadString_sub_40F1D0((char*)& byte_587000[110384], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 293);
            if (result)
                result = (const char*)sub_447310(0, (int)result);
        }
        else if (sub_427880(v2))
        {
            sub_427850((int)v3);
            sub_41F980(v2, 0);
            result = (const char*)sub_446C10(a1, 0);
        }
        else
        {
            sub_427820((int)v3);
            sub_41F980(v2, 1);
            result = (const char*)sub_446C10(a1, 1);
        }
    }
    return result;
}

//----- (00446BC0) --------------------------------------------------------
char* __cdecl sub_446BC0(int a1)
{
    int v1; // eax
    char* result; // eax

    v1 = nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16406, a1, 0);
    nox_sprintf((char*)& byte_5D4594[826072], "%S", v1);
    result = (char*)& byte_5D4594[826072];
    if (byte_5D4594 != (unsigned __int8*)-826072 && (byte_5D4594[826072] == 64 || byte_5D4594[826072] == 32))
    result = (char*)& byte_5D4594[826073];
    return result;
}

//----- (00446C10) --------------------------------------------------------
int __cdecl sub_446C10(int a1, int a2)
{
    int v2; // ecx
    int result; // eax

    v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[829488] + 32);
    result = a1;
    if (a1 < *(__int16*)(v2 + 44))
    {
        result = 131 * a1;
        if (a2)
            * (_DWORD*)(*(_DWORD*)(v2 + 24) + 524 * a1 + 516) = **(_DWORD * *)& byte_5D4594[2649844];
        else
            *(_DWORD*)(*(_DWORD*)(v2 + 24) + 524 * a1 + 516) = **(_DWORD * *)& byte_5D4594[2649892];
    }
    return result;
}

//----- (00446C70) --------------------------------------------------------
int sub_446C70()
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16404, 0, 0);
}

//----- (00446C90) --------------------------------------------------------
BOOL sub_446C90()
{
    return *(int*)nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16404, 0, 0) != -1;
}

//----- (00446CC0) --------------------------------------------------------
wchar_t* __cdecl sub_446CC0(int a1)
{
    wchar_t* result; // eax
    char* v2; // eax
    char* v3; // eax

    result = (wchar_t*)sub_41E2F0();
    if (result == (wchar_t*)7)
    {
        if (a1)
        {
            v2 = sub_41FA40();
            nox_swprintf((wchar_t*)& byte_5D4594[829224], *(const wchar_t**)& byte_5D4594[829528], v2, a1);
        }
        else
        {
            result = *(wchar_t**)& byte_5D4594[829532];
            if (!*(_DWORD*)& byte_5D4594[829532])
                return result;
            v3 = sub_41FA40();
            nox_swprintf((wchar_t*)& byte_5D4594[829224], *(const wchar_t**)& byte_5D4594[829532], v3);
            nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16403, -1, 0);
        }
        result = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829496], 16385, (int)& byte_5D4594[829224], 0);
    }
    return result;
}

//----- (00446D50) --------------------------------------------------------
void sub_446D50()
{
    char* v0; // eax
    int v1; // [esp+0h] [ebp-4h]

    v1 = 0;
    v0 = (char*)sub_4464F0(0, &v1);
    sub_446D80(v0);
}

//----- (00446D80) --------------------------------------------------------
void __cdecl sub_446D80(char* a1)
{
    char* v1; // esi
    char v2[256]; // [esp+4h] [ebp-300h]
    wchar_t v3[256]; // [esp+104h] [ebp-200h]

    v1 = a1;
    if (a1)
    {
        while (1)
        {
            v1 = sub_446E20(v1, v2);
            if (!v1)
                break;
            if (!v2[0])
                strcpy(v2, " ");
            nox_swprintf(v3, L"%S", v2);
            sub_447310(0, (int)v3);
        }
        if (v2[0])
        {
            nox_swprintf(v3, L"%S", v2);
            sub_447310(0, (int)v3);
        }
    }
}

//----- (00446E20) --------------------------------------------------------
char* __cdecl sub_446E20(char* a1, _BYTE* a2)
{
    char* v2; // edx
    char* v3; // eax
    char v4; // cl
    char* result; // eax

    v2 = a2;
    v3 = a1;
    *a2 = 0;
    if (!*a1)
        return 0;
    while (1)
    {
        v4 = *v3;
        if (!*v3)
        {
            *v2 = 0;
            return 0;
        }
        if (v4 == 10)
        {
            *v2 = 0;
            return v3 + 1;
        }
        if (v4 == 13)
            break;
        *v2++ = v4;
        ++v3;
    }
    result = v3 + 1;
    *v2 = 0;
    if (*result == 10)
        ++result;
    return result;
}

//----- (00446E60) --------------------------------------------------------
wchar_t* sub_446E60()
{
    wchar_t* result; // eax

    nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16399, 0, 0);
    for (result = sub_41F0A0(); result; result = sub_41F070())
        nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16397, (int)result, 14);
    return result;
}

//----- (00446EB0) --------------------------------------------------------
char* sub_446EB0()
{
    char* result; // eax
    const char* i; // esi
    wchar_t v2[256]; // [esp+4h] [ebp-200h]

    nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16399, 0, 0);
    result = sub_41F780();
    for (i = result; result; i = result)
    {
        nox_swprintf(v2, L"%S", i);
        if (sub_427880(i))
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v2, 2);
        else
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v2, 14);
        result = sub_41F710();
    }
    return result;
}

//----- (00446F40) --------------------------------------------------------
char* __cdecl sub_446F40(int a1)
{
    int v1; // eax

    if (a1 == -1)
        return 0;
    v1 = nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16406, a1, 0);
    nox_sprintf((char*)& byte_5D4594[827120], "%S", v1);
    return (char*)& byte_5D4594[827120];
}

//----- (00446F80) --------------------------------------------------------
void __cdecl sub_446F80(wchar_t* a1)
{
    wchar_t v1; // ax
    int* v2; // eax
    int* v3; // edi
    int i; // eax
    char* v5; // eax
    const char* v6; // esi
    char* v7; // eax
    wchar_t* v8; // eax

    if (!a1)
        return;
    v1 = *a1;
    if (!*a1 || v1 == 10 || v1 == 13)
        return;
    if (sub_41EC00())
    {
        if (sub_446C90())
        {
            v2 = (int*)nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16404, 0, 0);
            v3 = v2;
            for (i = *v2; i != -1; ++v3)
            {
                v5 = sub_446F40(i);
                v6 = v5;
                if (v5)
                {
                    if (sub_41F860(v5, a1))
                        sub_4471A0(v6, (int)a1, 1, 1);
                }
                i = v3[1];
            }
            return;
        }
        sub_448680(a1, (char*)& byte_5D4594[827176]);
        if (sub_40D3E0((int)& byte_5D4594[827176]))
        {
            v7 = sub_41FA40();
            sub_4471A0(v7, (int)a1, 0, 0);
            return;
        }
    }
    v8 = loadString_sub_40F1D0((char*)& byte_587000[110480], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1076);
    if (v8)
        sub_447310(0, (int)v8);
}

//----- (00447090) --------------------------------------------------------
void __cdecl sub_447090(wchar_t* a1)
{
    wchar_t v1; // ax
    int* v2; // eax
    int* v3; // edi
    int i; // eax
    char* v5; // eax
    const char* v6; // esi
    char* v7; // eax
    wchar_t* v8; // eax

    if (!a1)
        return;
    v1 = *a1;
    if (!*a1 || v1 == 10 || v1 == 13)
        return;
    if (sub_41EC00())
    {
        if (sub_446C90())
        {
            v2 = (int*)nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16404, 0, 0);
            v3 = v2;
            for (i = *v2; i != -1; ++v3)
            {
                v5 = sub_446F40(i);
                v6 = v5;
                if (v5)
                {
                    if (sub_41F8F0(v5, a1))
                        sub_447250(v6, (int)a1, 1, 1);
                }
                i = v3[1];
            }
            return;
        }
        sub_448680(a1, (char*)& byte_5D4594[827176]);
        if (sub_40D4D0((int)& byte_5D4594[827176]))
        {
            v7 = sub_41FA40();
            sub_447250(v7, (int)a1, 0, 0);
            return;
        }
    }
    v8 = loadString_sub_40F1D0((char*)& byte_587000[110540], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1123);
    if (v8)
        sub_447310(0, (int)v8);
}

//----- (004471A0) --------------------------------------------------------
const wchar_t* __cdecl sub_4471A0(const char* a1, int a2, int a3, int a4)
{
    const wchar_t* result; // eax

    result = (const wchar_t*)sub_427880(a1);
    if (!result)
    {
        result = *(const wchar_t**)& byte_5D4594[829492];
        if (*(_DWORD*)& byte_5D4594[829492])
        {
            result = *(const wchar_t**)& byte_5D4594[829544];
            if (*(_DWORD*)& byte_5D4594[829544])
            {
                if (a2)
                {
                    if (a3)
                    {
                        if (a4 == 1)
                        {
                            nox_swprintf((wchar_t*)& byte_5D4594[827176], *(const wchar_t**)& byte_5D4594[829552], a1, a2);
                            return (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 7);
                        }
                        result = *(const wchar_t**)& byte_5D4594[829548];
                    }
                    nox_swprintf((wchar_t*)& byte_5D4594[827176], result, a1, a2);
                    result = (const wchar_t*)nox_window_call_field_94(
                            *(int*)& byte_5D4594[829492],
                            16397,
                            (int)& byte_5D4594[827176],
                            (a3 != 0) + 6);
                }
            }
        }
    }
    return result;
}

//----- (00447250) --------------------------------------------------------
const wchar_t* __cdecl sub_447250(const char* a1, int a2, int a3, int a4)
{
    const wchar_t* result; // eax
    const wchar_t* v5; // esi
    char* v6; // eax

    result = (const wchar_t*)sub_427880(a1);
    if (!result)
    {
        result = *(const wchar_t**)& byte_5D4594[829492];
        if (*(_DWORD*)& byte_5D4594[829492])
        {
            if (*(_DWORD*)& byte_5D4594[829556])
            {
                result = *(const wchar_t**)& byte_5D4594[829560];
                if (*(_DWORD*)& byte_5D4594[829560])
                {
                    if (a2)
                    {
                        if (a3)
                        {
                            if (a4 == 1)
                            {
                                v5 = *(const wchar_t**)& byte_5D4594[829564];
                                v6 = sub_41FA40();
                                nox_swprintf((wchar_t*)& byte_5D4594[827176], v5, a1, v6, a2);
                                return (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 13);
                            }
                        }
                        else
                        {
                            result = *(const wchar_t**)& byte_5D4594[829556];
                        }
                        nox_swprintf((wchar_t*)& byte_5D4594[827176], result, a1, a2);
                        result = (const wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 13);
                    }
                }
            }
        }
    }
    return result;
}

//----- (00447310) --------------------------------------------------------
int __cdecl sub_447310(int a1, int a2)
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[829492];
    if (*(_DWORD*)& byte_5D4594[829492])
    {
        if (*(_DWORD*)& byte_5D4594[829536])
        {
            result = a2;
            if (a2)
            {
                if (a1)
                    nox_swprintf((wchar_t*)& byte_5D4594[827176], *(const wchar_t**)& byte_5D4594[829536], a1, a2);
                else
                    nox_swprintf((wchar_t*)& byte_5D4594[827176], L"%s", a2);
                result = nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 9);
            }
        }
    }
    return result;
}

//----- (00447380) --------------------------------------------------------
wchar_t* __cdecl sub_447380(const char* a1, char* a2)
{
    wchar_t* result; // eax
    const wchar_t* v3; // edi

    result = (wchar_t*)sub_427880(a1);
    if (!result)
    {
        result = *(wchar_t**)& byte_5D4594[829492];
        if (*(_DWORD*)& byte_5D4594[829492])
        {
            result = *(wchar_t**)& byte_5D4594[829544];
            if (*(_DWORD*)& byte_5D4594[829544])
            {
                if (a2)
                {
                    v3 = *(const wchar_t**)& byte_5D4594[829540];
                    sub_447410(a2);
                    if (a1)
                        nox_swprintf((wchar_t*)& byte_5D4594[827176], v3, a1, a2);
                    else
                        nox_swprintf((wchar_t*)& byte_5D4594[827176], L"%S", a2);
                    nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 4);
                    result = (wchar_t*)sub_452D80(226, 100);
                }
            }
        }
    }
    return result;
}

//----- (00447410) --------------------------------------------------------
unsigned int __cdecl sub_447410(char* a1)
{
    int v1; // edx
    char* v2; // ecx
    char v3; // al
    unsigned int result; // eax

    v1 = 0;
    v2 = a1;
    if (*a1)
    {
        do
        {
            if ((unsigned __int8)* v2 < 0x80u)
            byte_5D4594[v1++ + 826096] = *v2;
            v3 = *++v2;
        } while (v3);
    }
    byte_5D4594[v1 + 826096] = 0;
    result = strlen((const char*)& byte_5D4594[826096]) + 1;
    qmemcpy(a1, &byte_5D4594[826096], result);
    return result;
}

//----- (00447470) --------------------------------------------------------
int sub_447470()
{
    wchar_t* v0; // esi
    int result; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[110616], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1261);
    result = sub_41EC00();
    if (result)
    {
        nox_swprintf((wchar_t*)& byte_5D4594[827176], v0, result);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 9);
    }
    return result;
}

//----- (004474C0) --------------------------------------------------------
int __cdecl sub_4474C0(int a1, int a2)
{
    wchar_t* v2; // eax
    wchar_t* v3; // eax

    if (a1)
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[110672], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1277);
        nox_swprintf((wchar_t*)& byte_5D4594[827176], v2, a2, a1);
    }
    else
    {
        v3 = loadString_sub_40F1D0((char*)& byte_587000[110728], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1281);
        nox_swprintf((wchar_t*)& byte_5D4594[827176], v3, a2);
    }
    return nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 9);
}

//----- (00447540) --------------------------------------------------------
int __cdecl sub_447540(int a1)
{
    wchar_t* v1; // eax

    v1 = loadString_sub_40F1D0((char*)& byte_587000[110792], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1296);
    nox_swprintf((wchar_t*)& byte_5D4594[827176], v1, a1);
    return nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 9);
}

//----- (00447590) --------------------------------------------------------
int sub_447590()
{
    wchar_t* v0; // esi
    int result; // eax

    v0 = loadString_sub_40F1D0((char*)& byte_587000[110848], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1310);
    result = sub_41EC00();
    if (result)
    {
        nox_swprintf((wchar_t*)& byte_5D4594[827176], v0, result);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[829492], 16397, (int)& byte_5D4594[827176], 9);
    }
    return result;
}

//----- (004475E0) --------------------------------------------------------
int sub_4475E0()
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16399, 0, 0);
}

//----- (00447600) --------------------------------------------------------
void sub_447600()
{
    if (!sub_44A4A0())
        sub_46B500(*(int*)& byte_5D4594[829500]);
}

//----- (00447620) --------------------------------------------------------
int sub_447620()
{
    int result; // eax
    char** v1; // eax
    unsigned __int8* v2; // esi
    wchar_t* v3; // eax
    _BYTE* v4; // ecx
    _DWORD* v5; // edi
    char* v6; // ebx
    char* v7; // esi
    _DWORD* v8; // edi
    _DWORD* v9; // edi

    sub_43BDD0(1900);
    nox_set_draw_unk1(sub_41E210);
    sub_43FE20(150);
    *(_DWORD*)& byte_5D4594[829480] = nox_new_window_from_file("wolchat.wnd", sub_447CC0);
    sub_446970();
    result = *(_DWORD*)& byte_5D4594[829480];
    if (*(_DWORD*)& byte_5D4594[829480])
    {
        sub_46A8C0(*(int*)& byte_5D4594[829480]);
        sub_44A4B0();
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[829480], sub_447C70, 0, 0);
        sub_46B340(*(int*)& byte_5D4594[829480], sub_4483A0);
        result = sub_43C5B0(*(_DWORD * *)& byte_5D4594[829480], 0, 0, 0, -480, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[829520] = result;
        if (result)
        {
            *(_DWORD*)result = 1900;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[829520] + 48) = sub_446A90;
            *(_DWORD*)(*(_DWORD*)& byte_5D4594[829520] + 56) = sub_447BD0;
            *(_DWORD*)& byte_5D4594[829484] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1908);
            *(_DWORD*)& byte_5D4594[829488] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1909);
            *(_DWORD*)& byte_5D4594[829492] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1907);
            *(_DWORD*)& byte_5D4594[829496] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1916);
            *(_DWORD*)& byte_5D4594[829500] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1910);
            *(_DWORD*)& byte_5D4594[829528] = loadString_sub_40F1D0(
                    (char*)& byte_587000[110916],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1415);
            *(_DWORD*)& byte_5D4594[829532] = loadString_sub_40F1D0(
                    (char*)& byte_587000[110980],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1416);
            *(_DWORD*)& byte_5D4594[829536] = &byte_587000[110992];
            *(_DWORD*)& byte_5D4594[829540] = loadString_sub_40F1D0(
                    (char*)& byte_587000[111048],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1418);
            *(_DWORD*)& byte_5D4594[829544] = &byte_587000[111056];
            *(_DWORD*)& byte_5D4594[829548] = loadString_sub_40F1D0(
                    (char*)& byte_587000[111120],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1420);
            *(_DWORD*)& byte_5D4594[829552] = loadString_sub_40F1D0(
                    (char*)& byte_587000[111184],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1421);
            *(_DWORD*)& byte_5D4594[829556] = &byte_587000[111204];
            *(_DWORD*)& byte_5D4594[829560] = loadString_sub_40F1D0(
                    (char*)& byte_587000[111264],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1423);
            *(_DWORD*)& byte_5D4594[829564] = loadString_sub_40F1D0(
                    (char*)& byte_587000[111328],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1424);
            *(_DWORD*)& byte_5D4594[829524] = loadString_sub_40F1D0(
                    (char*)& byte_587000[111392],
                    0,
                    "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
                    1425);
            *(_DWORD*)& byte_587000[109280] = -1;
            sub_446D50();
            sub_46A8A0();
            sub_447600();
            sub_41EBB0(0);
            sub_446CC0(0);
            sub_41F100((char*)& byte_587000[111400]);
            if (**(_BYTE * *)& byte_587000[108828])
            {
                v1 = (char**)& byte_587000[108828];
                v2 = &byte_587000[108828];
                do
                {
                    v3 = loadString_sub_40F1D0(*v1, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1446);
                    *((_DWORD*)v2 - 1) = v3;
                    nox_wcslen(v3);
                    v4 = (_BYTE*) * ((_DWORD*)v2 + 3);
                    v2 += 12;
                    v1 = (char**)v2;
                } while (*v4);
            }
            sub_41FFF0();
            *(_DWORD*)& byte_5D4594[829508] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1917);
            *(_DWORD*)& byte_5D4594[829512] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1918);
            *(_DWORD*)& byte_5D4594[829516] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1919);
            v5 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[829492] + 32);
            v6 = sub_42F970("ShopInventorySlider");
            v7 = sub_42F970("ShopInventorySliderSelected");
            sub_4B5700(*(int*)& byte_5D4594[829508], 0, 0, (int)v6, (int)v7, (int)v7);
            sub_46B280(*(int*)& byte_5D4594[829508], *(int*)& byte_5D4594[829492]);
            sub_46B280(*(int*)& byte_5D4594[829512], *(int*)& byte_5D4594[829492]);
            sub_46B280(*(int*)& byte_5D4594[829516], *(int*)& byte_5D4594[829492]);
            sub_46B300(*(int*)& byte_5D4594[829492], sub_447BF0);
            v5[9] = *(_DWORD*)& byte_5D4594[829508];
            v5[7] = *(_DWORD*)& byte_5D4594[829512];
            v5[8] = *(_DWORD*)& byte_5D4594[829516];
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[829508] + 400) + 8) = 16;
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[829508] + 400) + 12) = 46;
            *(_DWORD*)& byte_5D4594[829508] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1920);
            *(_DWORD*)& byte_5D4594[829512] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1921);
            *(_DWORD*)& byte_5D4594[829516] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1922);
            v8 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[829484] + 32);
            sub_4B5700(*(int*)& byte_5D4594[829508], 0, 0, (int)v6, (int)v7, (int)v7);
            sub_46B280(*(int*)& byte_5D4594[829508], *(int*)& byte_5D4594[829484]);
            sub_46B280(*(int*)& byte_5D4594[829512], *(int*)& byte_5D4594[829484]);
            sub_46B280(*(int*)& byte_5D4594[829516], *(int*)& byte_5D4594[829484]);
            sub_46B300(*(int*)& byte_5D4594[829484], sub_447BF0);
            v8[9] = *(_DWORD*)& byte_5D4594[829508];
            v8[7] = *(_DWORD*)& byte_5D4594[829512];
            v8[8] = *(_DWORD*)& byte_5D4594[829516];
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[829508] + 400) + 8) = 16;
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[829508] + 400) + 12) = 46;
            *(_DWORD*)& byte_5D4594[829508] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1923);
            *(_DWORD*)& byte_5D4594[829512] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1924);
            *(_DWORD*)& byte_5D4594[829516] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1925);
            v9 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[829488] + 32);
            sub_4B5700(*(int*)& byte_5D4594[829508], 0, 0, (int)v6, (int)v7, (int)v7);
            sub_46B280(*(int*)& byte_5D4594[829508], *(int*)& byte_5D4594[829488]);
            sub_46B280(*(int*)& byte_5D4594[829512], *(int*)& byte_5D4594[829488]);
            sub_46B280(*(int*)& byte_5D4594[829516], *(int*)& byte_5D4594[829488]);
            sub_46B300(*(int*)& byte_5D4594[829488], sub_447BF0);
            v9[9] = *(_DWORD*)& byte_5D4594[829508];
            v9[7] = *(_DWORD*)& byte_5D4594[829512];
            v9[8] = *(_DWORD*)& byte_5D4594[829516];
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[829508] + 400) + 8) = 16;
            *(_DWORD*)(*(_DWORD*)(*(_DWORD*)& byte_5D4594[829508] + 400) + 12) = 46;
            sub_41F370(0);
            if (sub_40A5C0(0x2000000))
                sub_448450();
            else
                sub_41F3A0(-99999, 1);
            result = 1;
        }
    }
    return result;
}

//----- (00447BD0) --------------------------------------------------------
int sub_447BD0()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[829520] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[829520]);
    sub_448490();
    v0();
    return 1;
}

//----- (00447BF0) --------------------------------------------------------
int __cdecl sub_447BF0(_DWORD* a1, int a2, unsigned int a3, int a4)
{
    int result; // eax

    if (a2 == 19)
    {
        nox_window_call_field_94((int)a1, 16391, *(_DWORD*)(a1[8] + 28), 0);
        result = 0;
    }
    else if (a2 == 20)
    {
        nox_window_call_field_94((int)a1, 16391, *(_DWORD*)(a1[8] + 32), 0);
        result = 0;
    }
    else if (*(_DWORD*)(a1[8] + 16))
    {
        result = sub_4A2DE0((int)a1, a2, a3, a4);
    }
    else
    {
        result = sub_4A28E0(a1, a2, a3, a4);
    }
    return result;
}

//----- (00447C70) --------------------------------------------------------
int __cdecl sub_447C70(int a1, int a2, int a3, int a4)
{
    int v5; // eax

    if (a2 != 21)
        return 0;
    if (a3 != 1)
        return 0;
    if (a4 == 2 && sub_41E2F0() == 7)
    {
        sub_41E300(9);
        v5 = sub_41E2F0();
        sub_41DA70(v5, 8);
        sub_44A400();
        sub_43C260();
    }
    return 1;
}

//----- (00447CC0) --------------------------------------------------------
int __cdecl sub_447CC0(int a1, unsigned int a2, int* a3, int a4)
{
    int result; // eax
    const wchar_t* v5; // edi
    const wchar_t* v6; // eax
    wchar_t* v7; // esi
    int2* v8; // eax
    int v9; // ebx
    int v10; // esi
    int v11; // edi
    _DWORD* v12; // esi
    int* v13; // esi
    wchar_t* v14; // eax
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // eax
    int v19; // eax
    wchar_t* v20; // eax
    int* v21; // [esp+8h] [ebp-104h]
    CHAR File[256]; // [esp+Ch] [ebp-100h]

    if (a2 > 0x4006)
    {
        switch (a2)
        {
            case 0x4007u:
                switch (sub_46B0A0(a3))
                {
                    case 1902:
                        sub_448730();
                        break;
                    case 1903:
                        v16 = sub_41E2F0();
                        sub_41DA70(v16, 12);
                        v17 = sub_41E2F0();
                        sub_41DA70(v17, 13);
                        break;
                    case 1904:
                        sub_449280();
                        break;
                    case 1905:
                        sub_40D380();
                        sub_41E300(8);
                        sub_4207F0(5);
                        break;
                    case 1906:
                        sub_41E300(9);
                        v15 = sub_41E2F0();
                        sub_41DA70(v15, 8);
                        sub_43C260();
                        break;
                    case 1913:
                        v20 = (wchar_t*)nox_window_call_field_94(*(int*)& byte_5D4594[829500], 16413, 0, 0);
                        sub_447090(v20);
                        nox_window_call_field_94(*(int*)& byte_5D4594[829500], 16414, (int)& byte_5D4594[829580], 0);
                        break;
                    case 1914:
                        sub_449530();
                        break;
                    case 1926:
                        v18 = sub_4200F0();
                        nox_sprintf(File, "http://battleclans.westwood.com/nox/index_%d.html", v18);
                        ShellExecuteA(0, 0, File, 0, (LPCSTR)& byte_587000[111564], 3);
                        break;
                    case 1927:
                        v19 = sub_4200F0();
                        nox_sprintf(File, "http://www.westwood.com/westwoodonline/tournaments/nox/rankindex_%d.html", v19);
                        ShellExecuteA(0, 0, File, 0, (LPCSTR)& byte_587000[111644], 3);
                        break;
                    default:
                        break;
                }
                sub_452D80(921, 100);
                return 1;
            case 0x4010u:
                if (sub_46B0A0(a3) != 1908)
                    return 0;
                if (!*(_WORD*)nox_window_call_field_94((int)a3, 16406, a4, 0))
                    goto LABEL_23;
                v5 = (const wchar_t*)sub_41EC00();
                v6 = (const wchar_t*)sub_41F1E0(a4);
                v7 = (wchar_t*)v6;
                if (!v6)
                    goto LABEL_23;
                if (v5)
                {
                    if (nox_wcscmp(v6, v5))
                    {
                        sub_40D380();
                        sub_446A20(v7);
                    }
                    LABEL_23:
                    sub_447600();
                    result = 0;
                }
                else
                {
                    sub_446A20(0);
                    sub_447600();
                    result = 0;
                }
                break;
            case 0x4011u:
                if (sub_46B0A0(a3) != 1909)
                    return 0;
                if (a4 == -1 || *(_DWORD*)& byte_5D4594[829504])
                {
                    *(_DWORD*)& byte_587000[109280] = -1;
                    result = 0;
                }
                else
                {
                    v8 = sub_4309F0();
                    *(_DWORD*)& byte_587000[109280] = a4;
                    v9 = v8->field_0;
                    v10 = v8->field_4;
                    v11 = sub_43F320(0);
                    *(_DWORD*)& byte_5D4594[829504] = nox_window_new(0, 40, v9 - 40, v10 - (v11 + 4) / 2, 80, v11 + 4, 0);
                    nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[829504], 0, sub_448140, 0);
                    sub_46A8C0(*(int*)& byte_5D4594[829504]);
                    v12 = nox_window_new(*(int*)& byte_5D4594[829504], 8, 0, v11 / 2, 80, v11 + 2, 0);
                    nox_window_set_all_funcs(v12, sub_448340, sub_448240, 0);
                    v12[8] = 0;
                    result = 0;
                }
                return result;
            case 0x401Fu:
                v13 = a3;
                sub_46B0A0(a3);
                goto LABEL_31;
            default:
                return 0;
        }
        return result;
    }
    if (a2 == 16390)
    {
        if (*(_DWORD*)& byte_5D4594[830112])
            return 0;
        sub_41E2F0();
        return 0;
    }
    if (a2 > 0x4003)
    {
        if (a2 != 16389)
            return 0;
        sub_452D80(920, 100);
        return 1;
    }
    if (a2 == 16387)
    {
        if (!sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], a4))
            return 0;
        return 0;
    }
    if (a2 == 23)
        return 1;
    if (a2 != 1910)
        return 0;
    v13 = v21;
    LABEL_31:
    v14 = (wchar_t*)nox_window_call_field_94((int)v13, 16413, 0, 0);
    sub_446F80(v14);
    nox_window_call_field_94((int)v13, 16414, (int)& byte_5D4594[829576], 0);
    return 0;
}
// 447F24: variable 'v21' is possibly undefined

//----- (00448140) --------------------------------------------------------
int __cdecl sub_448140(int yTop)
{
    int v1; // esi
    int xLeft; // [esp+4h] [ebp-Ch]
    int v4; // [esp+8h] [ebp-8h]
    int v5; // [esp+Ch] [ebp-4h]

    v1 = yTop;
    sub_46AA60((_DWORD*)yTop, &xLeft, &yTop);
    nox_window_get_size(v1, &v4, &v5);
    sub_49CF10(xLeft, yTop, v4, v5);
    sub_434460(*(int*)& byte_5D4594[2523948]);
    sub_49F500(xLeft + 1, yTop);
    sub_49F570(v4 - 2, 0);
    sub_49E4B0();
    sub_49F500(xLeft + 1, yTop + v5);
    sub_49F570(v4 - 2, 0);
    sub_49E4B0();
    sub_49F500(xLeft, yTop + 1);
    sub_49F570(0, v5 - 2);
    sub_49E4B0();
    sub_49F500(xLeft + v4, yTop + 1);
    sub_49F570(0, v5 - 2);
    sub_49E4B0();
    return 1;
}

//----- (00448240) --------------------------------------------------------
int __cdecl sub_448240(_DWORD* a1, _BYTE* a2)
{
    unsigned __int16* v2; // esi
    int v3; // ecx
    int v5; // [esp+4h] [ebp-8h]
    int v6; // [esp+8h] [ebp-4h]

    v2 = *(unsigned __int16**)& byte_587000[12 * a1[8] + 108824];
    sub_46AA60(a1, &v6, &a1);
    sub_43F840(0, v2, &v5, 0, 0);
    v3 = *(_DWORD*)& byte_5D4594[2589772];
    if (!(*a2 & 2))
        v3 = *(_DWORD*)& byte_5D4594[2523948];
    sub_4482D0((80 - v5) / 2 + v6 + 1, (int)a1, v3, *(int*)& byte_5D4594[2650656], v2);
    return 1;
}

//----- (004482D0) --------------------------------------------------------
int __cdecl sub_4482D0(int a1, int a2, int a3, int a4, _WORD* a5)
{
    unsigned __int8* v5; // esi

    sub_434390(a4);
    v5 = &byte_587000[109288];
    do
    {
        sub_43FAF0(0, a5, a1 + *(_DWORD*)v5, a2 + *((_DWORD*)v5 + 1), 320, 0);
        v5 += 8;
    } while ((int)v5 < (int)& byte_587000[109320]);
    sub_434390(a3);
    return sub_43FAF0(0, a5, a1, a2, 320, 0);
}

//----- (00448340) --------------------------------------------------------
int __cdecl sub_448340(int a1, unsigned int a2)
{
    if (a2 == 5)
        return 1;
    if (a2 > 5 && a2 <= 7)
    {
        sub_448380();
        (*(void(__cdecl * *)(int)) & byte_587000[12 * *(_DWORD*)(a1 + 32) + 108832])(*(int*)& byte_587000[109280]);
        return 1;
    }
    return 0;
}

//----- (00448380) --------------------------------------------------------
void sub_448380()
{
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[829504]);
    *(_DWORD*)& byte_5D4594[829504] = 0;
    sub_447600();
}

//----- (004483A0) --------------------------------------------------------
int __cdecl sub_4483A0(int a1, int a2)
{
    int2* v2; // eax
    int result; // eax
    int xLeft; // [esp+0h] [ebp-8h]
    int yTop; // [esp+4h] [ebp-4h]

    if (*(_DWORD*)& byte_5D4594[829504])
    {
        v2 = sub_4309F0();
        if (!sub_46AAB0(*(_DWORD * *)& byte_5D4594[829504], v2->field_0, v2->field_4))
            sub_448380();
    }
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

//----- (00448450) --------------------------------------------------------
int sub_448450()
{
    int result; // eax
    _DWORD* v1; // eax

    result = sub_40A5C0(0x2000000);
    if (result)
    {
        sub_446970();
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[829480], 1905);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[829480], 16391, (int)v1, 0);
    }
    return result;
}

//----- (00448490) --------------------------------------------------------
int sub_448490()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[829480];
    if (*(_DWORD*)& byte_5D4594[829480])
    {
        result = sub_46C4E0(*(_DWORD * *)& byte_5D4594[829480]);
        *(_DWORD*)& byte_5D4594[829480] = 0;
        *(_DWORD*)& byte_5D4594[829484] = 0;
        *(_DWORD*)& byte_5D4594[829488] = 0;
        *(_DWORD*)& byte_5D4594[829492] = 0;
        *(_DWORD*)& byte_5D4594[829500] = 0;
    }
    return result;
}

//----- (004484D0) --------------------------------------------------------
void __cdecl sub_4484D0(wchar_t* a1, int a2, int a3)
{
    wchar_t* v3; // eax
    const wchar_t* v4; // eax

    if (a1)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16402, a3, 0);
        v3 = sub_41F330((int)a1, a2);
        nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16397, (int)v3, 14);
        v4 = (const wchar_t*)sub_41EC00();
        if (v4)
        {
            if (!nox_wcscmp(v4, a1))
                nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16403, a3, 0);
        }
    }
}

//----- (00448550) --------------------------------------------------------
int __cdecl sub_448550(int a1)
{
    return nox_window_call_field_94(*(int*)& byte_5D4594[829484], 16398, a1, 0);
}

//----- (00448570) --------------------------------------------------------
void __cdecl sub_448570(const char* a1, char a2, int a3)
{
    char* v3; // eax
    wchar_t v4[256]; // [esp+4h] [ebp-200h]

    if (a1)
    {
        nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16402, a3, 0);
        v3 = sub_41F740((int)a1, a2);
        nox_swprintf(v4, L"%S", v3);
        if (sub_427880(a1))
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v4, 2);
        else
            nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16397, (int)v4, 14);
    }
}

//----- (00448620) --------------------------------------------------------
int __cdecl sub_448620(int a1)
{
    int result; // eax

    result = a1;
    if (a1 >= 0)
        result = nox_window_call_field_94(*(int*)& byte_5D4594[829488], 16398, a1, 0);
    return result;
}

//----- (00448650) --------------------------------------------------------
int __cdecl sub_448650(_BYTE* a1, wchar_t* a2)
{
    int result; // eax

    if (*a1 == -16)
        result = sub_425680(a1 + 1, a2);
    else
        result = nox_swprintf(a2, L"%S", a1);
    return result;
}

//----- (00448680) --------------------------------------------------------
int __cdecl sub_448680(wchar_t* a1, char* a2)
{
    int result; // eax
    size_t v3; // eax
    char v4[2048]; // [esp+4h] [ebp-800h]

    if (sub_4100F0((__int16*)a1))
    return nox_sprintf(a2, "%S", a1);
    memset(v4, 0, sizeof(v4));
    memset(a2, 0, 0x800u);
    v3 = nox_wcslen(a1);
    sub_425550(a1, v4, 16 * (v3 + 1));
    result = 0;
    *a2 = -16;
    qmemcpy(a2 + 1, v4, strlen(v4));
    return result;
}

//----- (00448730) --------------------------------------------------------
int sub_448730()
{
    int result; // eax

    if (*(_DWORD*)& byte_5D4594[830112])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830116])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830120])
        return 0;
    result = nox_new_window_from_file("wolfind.wnd", sub_4489C0);
    *(_DWORD*)& byte_5D4594[830124] = result;
    if (result)
    {
        *(_DWORD*)(result + 56) = *(_DWORD*)& byte_5D4594[2650656];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830124] + 16) = (nox_win_width
                                                            - *(_DWORD*)(*(_DWORD*)& byte_5D4594[830124] + 8))
                                                           / 2;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830124] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830124] + 8)
                                                           + *(_DWORD*)(*(_DWORD*)& byte_5D4594[830124] + 16);
        *(_DWORD*)& byte_5D4594[830128] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1933);
        sub_46B300(*(int*)& byte_5D4594[830128], sub_448F00);
        *(_DWORD*)& byte_5D4594[830136] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1934);
        *(_DWORD*)& byte_5D4594[830132] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1935);
        sub_46B300(*(int*)& byte_5D4594[830132], sub_448F60);
        *(_DWORD*)& byte_5D4594[830152] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1931);
        *(_DWORD*)& byte_5D4594[830156] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1932);
        sub_46ABB0(*(int*)& byte_5D4594[830152], 0);
        *(_DWORD*)& byte_5D4594[830140] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1938);
        *(_DWORD*)& byte_5D4594[830144] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1939);
        *(_DWORD*)& byte_5D4594[830148] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830124], 1936);
        sub_46B500(*(int*)& byte_5D4594[830132]);
        *(_DWORD*)& byte_5D4594[830160] = loadString_sub_40F1D0(
                (char*)& byte_587000[111732],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                579);
        *(_DWORD*)& byte_5D4594[830164] = loadString_sub_40F1D0(
                (char*)& byte_587000[111800],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                580);
        *(_DWORD*)& byte_5D4594[830168] = loadString_sub_40F1D0(
                (char*)& byte_587000[111872],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                581);
        *(_DWORD*)& byte_5D4594[830172] = loadString_sub_40F1D0(
                (char*)& byte_587000[111936],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                582);
        *(_DWORD*)& byte_5D4594[830176] = loadString_sub_40F1D0(
                (char*)& byte_587000[112000],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                583);
        *(_DWORD*)& byte_5D4594[830180] = loadString_sub_40F1D0(
                (char*)& byte_587000[112068],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                584);
        *(_DWORD*)& byte_5D4594[830184] = loadString_sub_40F1D0(
                (char*)& byte_587000[112136],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                585);
        *(_DWORD*)& byte_5D4594[830188] = loadString_sub_40F1D0(
                (char*)& byte_587000[112196],
                0,
                "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c",
                586);
        *(_DWORD*)& byte_587000[111668] = 1;
        *(_DWORD*)& byte_5D4594[830116] = 1;
        sub_46B120(*(_DWORD * *)& byte_5D4594[830124], 0);
        sub_46A8C0(*(int*)& byte_5D4594[830124]);
        sub_46C690(*(int*)& byte_5D4594[830124]);
        sub_46B500(*(int*)& byte_5D4594[830124]);
        sub_46B340(*(int*)& byte_5D4594[830124], sub_448FC0);
        result = 1;
    }
    return result;
}

//----- (004489C0) --------------------------------------------------------
int __cdecl sub_4489C0(int a1, int a2, int* a3, int a4)
{
    wchar_t* v4; // esi
    const wchar_t* v5; // eax
    int result; // eax
    wchar_t* v7; // eax
    int v8; // esi

    if (a2 == 16391)
    {
        v8 = sub_46B0A0(a3);
        sub_452D80(766, 100);
        switch (v8)
        {
            case 1931:
                nox_window_set_hidden(*(int*)& byte_5D4594[830136], 0);
                nox_window_set_hidden(*(int*)& byte_5D4594[830132], 1);
                nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, *(int*)& byte_5D4594[830160], 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[830144], 16385, *(int*)& byte_5D4594[830168], 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[830148], 16385, *(int*)& byte_5D4594[830176], 0);
                sub_46ABB0(*(int*)& byte_5D4594[830152], 0);
                sub_46ABB0(*(int*)& byte_5D4594[830156], 1);
                if (*(_DWORD*)& byte_5D4594[830204])
                    sub_46ABB0(*(int*)& byte_5D4594[830148], 0);
                else
                    sub_46ABB0(*(int*)& byte_5D4594[830148], 1);
                *(_DWORD*)& byte_587000[111668] = 1;
                result = 0;
                break;
            case 1932:
                nox_window_set_hidden(*(int*)& byte_5D4594[830136], 1);
                nox_window_set_hidden(*(int*)& byte_5D4594[830132], 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, *(int*)& byte_5D4594[830164], 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[830144], 16385, *(int*)& byte_5D4594[830172], 0);
                nox_window_call_field_94(*(int*)& byte_5D4594[830148], 16385, *(int*)& byte_5D4594[830180], 0);
                sub_46ABB0(*(int*)& byte_5D4594[830152], 1);
                sub_46ABB0(*(int*)& byte_5D4594[830156], 0);
                *(_DWORD*)& byte_587000[111668] = 0;
                if (*(_DWORD*)& byte_5D4594[830208])
                    sub_46ABB0(*(int*)& byte_5D4594[830148], 0);
                else
                    sub_46ABB0(*(int*)& byte_5D4594[830148], 1);
                result = 0;
                break;
            case 1936:
                sub_448CF0();
                goto LABEL_24;
            case 1937:
                sub_46C6E0(*(int*)& byte_5D4594[830124]);
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830124]);
                sub_447600();
                *(_DWORD*)& byte_5D4594[830116] = 0;
                result = 0;
                break;
            default:
                goto LABEL_24;
        }
    }
    else if (a2 == 16400
             && sub_46B0A0(a3) == 1934
             && a4 != -1
             && (v4 = (wchar_t*)nox_window_call_field_94((int)a3, 16406, a4, 0), *v4)
             && (v5 = (const wchar_t*)sub_41EC00(), v4))
    {
        if (v5)
        {
            if (!nox_wcscmp(v4, v5))
            {
                v7 = loadString_sub_40F1D0((char*)& byte_587000[112316], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 327);
            }
            else
            {
                sub_46C6E0(*(int*)& byte_5D4594[830124]);
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830124]);
                sub_447600();
                *(_DWORD*)& byte_5D4594[830116] = 0;
                *(_DWORD*)& byte_5D4594[830124] = 0;
                sub_40D380();
                sub_446A20(v4);
                v7 = loadString_sub_40F1D0((char*)& byte_587000[112252], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 321);
            }
            nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v7, 0);
            result = 0;
        }
        else
        {
            sub_446A20(0);
            result = 0;
        }
    }
    else
    {
        LABEL_24:
        result = 0;
    }
    return result;
}

//----- (00448CF0) --------------------------------------------------------
int sub_448CF0()
{
    _WORD* v0; // esi
    int result; // eax
    wchar_t* v2; // eax
    int v3; // eax
    wchar_t* v4; // eax
    int v5; // [esp+0h] [ebp-170h]
    char v6[36]; // [esp+4h] [ebp-16Ch]
    char v7[72]; // [esp+28h] [ebp-148h]
    char v8[256]; // [esp+70h] [ebp-100h]

    v0 = (_WORD*)nox_window_call_field_94(*(int*)& byte_5D4594[830128], 16413, 0, 0);
    if (*(_DWORD*)& byte_587000[111668])
    {
        if (v0 && *v0)
        {
            nox_sprintf(v7, "%S", v0);
            sub_40D740((int)v6);
            nox_swprintf((wchar_t*)& byte_5D4594[829840], *(const wchar_t**)& byte_5D4594[830184], v0);
            nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)& byte_5D4594[829840], 0);
            *(_DWORD*)& byte_5D4594[830204] = 1;
            sub_4160D0(18);
            return sub_46ABB0(*(int*)& byte_5D4594[830148], 0);
        }
        v2 = loadString_sub_40F1D0((char*)& byte_587000[112388], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 234);
        return nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v2, 0);
    }
    v3 = nox_window_call_field_94(*(int*)& byte_5D4594[830132], 16413, 0, 0);
    nox_sprintf(v8, "%S", v3);
    if (!v0 || !*v0)
    {
        v2 = loadString_sub_40F1D0((char*)& byte_587000[112520], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 267);
        return nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v2, 0);
    }
    if (&v5 != (int*)-112 && v8[0])
    {
        nox_sprintf(v7, "%S", v0);
        sub_40D770((int)v6, (int)v8);
        nox_swprintf((wchar_t*)& byte_5D4594[829840], *(const wchar_t**)& byte_5D4594[830188], v0);
        nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)& byte_5D4594[829840], 0);
        *(_DWORD*)& byte_5D4594[830208] = 1;
        sub_4160D0(19);
        sub_46ABB0(*(int*)& byte_5D4594[830148], 0);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[830132], 16414, (int)& byte_5D4594[830212], 0);
    }
    else
    {
        v4 = loadString_sub_40F1D0((char*)& byte_587000[112456], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 264);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v4, 0);
    }
    return result;
}

//----- (00448F00) --------------------------------------------------------
int __cdecl sub_448F00(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 != 21 || a3 != 28)
        return sub_487D70(a1, a2, a3, a4);
    if (a4 == 2)
    {
        if (*(_DWORD*)& byte_587000[111668] == 1)
        {
            if (*(_DWORD*)& byte_5D4594[830204] != 1)
            {
                sub_448CF0();
                return 1;
            }
        }
        else if (*(_DWORD*)& byte_5D4594[830208] != 1)
        {
            sub_448CF0();
        }
    }
    return 1;
}

//----- (00448F60) --------------------------------------------------------
int __cdecl sub_448F60(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 != 21 || a3 != 28)
        return sub_487D70(a1, a2, a3, a4);
    if (a4 == 2)
    {
        if (*(_DWORD*)& byte_587000[111668] == 1)
        {
            if (*(_DWORD*)& byte_5D4594[830204] != 1)
            {
                sub_448CF0();
                return 1;
            }
        }
        else if (*(_DWORD*)& byte_5D4594[830208] != 1)
        {
            sub_448CF0();
        }
    }
    return 1;
}

//----- (00448FC0) --------------------------------------------------------
int __cdecl sub_448FC0(int a1, int a2)
{
    int xLeft; // [esp+4h] [ebp-8h]
    int yTop; // [esp+8h] [ebp-4h]

    sub_46AA60((_DWORD*)a1, &xLeft, &yTop);
    if ((signed char) * (_BYTE*)(a1 + 4) >= 0)
    {
        if (*(_DWORD*)(a2 + 20) != 0x80000000)
        {
            sub_434460(*(int*)& byte_5D4594[2650656]);
            sub_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
        }
    }
    else
    {
        sub_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
    }
    if (*(_DWORD*)& byte_587000[111668])
    {
        if (*(_DWORD*)& byte_5D4594[830204] && sub_4160F0(0x12u, 10 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            sub_46ABB0(*(int*)& byte_5D4594[830148], 1);
            *(_DWORD*)& byte_5D4594[830204] = 0;
            return 1;
        }
    }
    else if (*(_DWORD*)& byte_5D4594[830208] && sub_4160F0(0x13u, 10 * *(_DWORD*)& byte_5D4594[2649704]))
    {
        sub_46ABB0(*(int*)& byte_5D4594[830148], 1);
        *(_DWORD*)& byte_5D4594[830208] = 0;
    }
    return 1;
}

//----- (004490C0) --------------------------------------------------------
void __cdecl sub_4490C0(int a1)
{
    int v1; // ebp
    char* v3; // ebx
    const char* v4; // esi
    _DWORD* v5; // eax
    wchar_t* v6; // eax

    v1 = 0;
    if (sub_43AF80() == 11)
    {
        sub_43AFC0(a1);
        return;
    }
    if (!*(_DWORD*)& byte_5D4594[830116])
    {
        return;
    }
    v3 = sub_420110();
    if (!v3)
    {
        sub_4491B0();
        return;
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[830136], 16399, 0, 0);
    if (a1)
    {
        v4 = (const char*)(a1 + 52);
        do
        {
            if (!strncmp(v4, v3, strlen(v3)))
            {
                v5 = sub_41E7A0(v4);
                nox_window_call_field_94(*(int*)& byte_5D4594[830136], 16397, (int)v5, 9);
                ++v1;
            }
        } while (*(_DWORD*)(a1 + 48));
    }
    v6 = loadString_sub_40F1D0((char*)& byte_587000[112580], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 639);
    nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v6, 0);
    if (!v1)
        sub_4491B0();
}

//----- (004491B0) --------------------------------------------------------
int sub_4491B0()
{
    int result; // eax
    wchar_t* v1; // eax

    if (sub_43AF80() == 11)
        return sub_43AFA0(9);
    result = *(_DWORD*)& byte_5D4594[830116];
    if (*(_DWORD*)& byte_5D4594[830116])
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[112640], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 660);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v1, 0);
    }
    return result;
}

//----- (00449200) --------------------------------------------------------
int sub_449200()
{
    int result; // eax
    wchar_t* v1; // eax

    result = *(_DWORD*)& byte_5D4594[830116];
    if (*(_DWORD*)& byte_5D4594[830116])
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[112700], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 669);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v1, 0);
    }
    return result;
}

//----- (00449240) --------------------------------------------------------
int sub_449240()
{
    int result; // eax
    wchar_t* v1; // eax

    result = *(_DWORD*)& byte_5D4594[830116];
    if (*(_DWORD*)& byte_5D4594[830116])
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[112760], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 678);
        result = nox_window_call_field_94(*(int*)& byte_5D4594[830140], 16385, (int)v1, 0);
    }
    return result;
}

//----- (00449280) --------------------------------------------------------
int sub_449280()
{
    int result; // eax
    int v1; // eax
    int v2; // ecx
    unsigned int v3; // ecx
    int v4; // eax
    int v5; // ecx
    unsigned int v6; // ecx
    int v7; // eax
    int v8; // ecx
    unsigned int v9; // ecx

    if (*(_DWORD*)& byte_5D4594[830112])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830116])
        return 0;
    if (*(_DWORD*)& byte_5D4594[830120])
        return 0;
    result = nox_new_window_from_file("wolopt.wnd", sub_4493D0);
    *(_DWORD*)& byte_5D4594[830104] = result;
    if (result)
    {
        *(_DWORD*)(result + 56) = *(_DWORD*)& byte_5D4594[2650656];
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 16) = (nox_win_width
                                                            - *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 8))
                                                           / 2;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 24) = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 8)
                                                           + *(_DWORD*)(*(_DWORD*)& byte_5D4594[830104] + 16);
        *(_DWORD*)& byte_5D4594[830192] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830104], 1991);
        *(_DWORD*)& byte_5D4594[830196] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830104], 1992);
        *(_DWORD*)& byte_5D4594[830200] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830104], 1993);
        v1 = sub_41FF60();
        v2 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830192] + 36);
        if (v1)
            v3 = v2 | 4;
        else
            v3 = v2 & 0xFFFFFFFB;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830192] + 36) = v3;
        v4 = sub_41FF90();
        v5 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830196] + 36);
        if (v4)
            v6 = v5 | 4;
        else
            v6 = v5 & 0xFFFFFFFB;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830196] + 36) = v6;
        v7 = sub_41FFC0();
        v8 = *(_DWORD*)(*(_DWORD*)& byte_5D4594[830200] + 36);
        if (v7)
            v9 = v8 | 4;
        else
            v9 = v8 & 0xFFFFFFFB;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830200] + 36) = v9;
        *(_DWORD*)& byte_5D4594[830120] = 1;
        sub_46B120(*(_DWORD * *)& byte_5D4594[830104], 0);
        sub_46A8C0(*(int*)& byte_5D4594[830104]);
        sub_46C690(*(int*)& byte_5D4594[830104]);
        sub_46B500(*(int*)& byte_5D4594[830104]);
        result = 1;
    }
    return result;
}

//----- (004493D0) --------------------------------------------------------
int __cdecl sub_4493D0(int a1, int a2, int* a3, int a4)
{
    int v3; // esi
    int result; // eax
    int v5; // eax

    if (a2 != 16391)
        return 0;
    v3 = sub_46B0A0(a3);
    sub_452D80(766, 100);
    switch (v3)
    {
        case 1985:
            v5 = sub_41FC40();
            sub_40DB50(v5 + 1, (int)& a2);
            sub_40D670(a2);
            return 0;
        case 1994:
            sub_4494A0();
            result = 0;
            break;
        case 1995:
            sub_46C6E0(*(int*)& byte_5D4594[830104]);
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[830104]);
            sub_447600();
            *(_DWORD*)& byte_5D4594[830120] = 0;
            result = 0;
            break;
        case 1996:
            sub_4B5770(*(int*)& byte_5D4594[830104]);
            result = 0;
            break;
        default:
            return 0;
    }
    return result;
}

//----- (004494A0) --------------------------------------------------------
void sub_4494A0()
{
    sub_41FF70((*(_BYTE*)(*(_DWORD*)& byte_5D4594[830192] + 36) & 4) == 4);
    sub_41FFA0((*(_BYTE*)(*(_DWORD*)& byte_5D4594[830196] + 36) & 4) == 4);
    sub_41FFD0((*(_BYTE*)(*(_DWORD*)& byte_5D4594[830200] + 36) & 4) == 4);
    sub_46C6E0(*(int*)& byte_5D4594[830104]);
    sub_46C4E0(*(_DWORD * *)& byte_5D4594[830104]);
    *(_DWORD*)& byte_5D4594[830120] = 0;
    sub_447600();
}

//----- (00449530) --------------------------------------------------------
int sub_449530()
{
    const char* v0; // edi
    int v1; // ebp
    int result; // eax
    _DWORD* v3; // ebx
    int v4; // eax
    const char* i; // esi
    char* v6; // eax
    wchar_t* v7; // eax
    int v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // esi
    _DWORD* v11; // ebp
    _DWORD* v12; // eax
    _DWORD* v13; // edi
    char* v14; // eax
    _DWORD* v15; // eax
    char* v16; // [esp+8h] [ebp-94h]
    int v17; // [esp+Ch] [ebp-90h]
    char* v18; // [esp+10h] [ebp-8Ch]
    int v19; // [esp+14h] [ebp-88h]
    wchar_t v20[66]; // [esp+18h] [ebp-84h]

    v0 = 0;
    v16 = 0;
    v17 = -1;
    v1 = 0;
    result = nox_new_window_from_file("servlist.wnd", sub_4497D0);
    *(_DWORD*)& byte_5D4594[830108] = result;
    if (result)
    {
        *(_DWORD*)(result + 56) = *(_DWORD*)& byte_5D4594[2650656];
        sub_46B120(*(_DWORD * *)& byte_5D4594[830108], 0);
        sub_46A8C0(*(int*)& byte_5D4594[830108]);
        sub_46C690(*(int*)& byte_5D4594[830108]);
        sub_46B500(*(int*)& byte_5D4594[830108]);
        if (sub_40A5C0(0x2000000))
        {
            v16 = sub_4A7F10();
            v0 = v16;
        }
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1961);
        v4 = sub_4200F0();
        for (i = sub_4205B0(v4); i; i = (const char*)sub_4206B0((int)i))
        {
            if (sub_40A5C0(0x2000000))
            {
                v6 = strchr(i + 24, 58);
                if (v6)
                {
                    if (v0 && !_strcmpi(v0, v6 + 1))
                        v17 = v1;
                }
            }
            nox_swprintf(v20, L"%S", i + 24);
            v7 = nox_wcschr(v20, 0x3Au);
            if (v7)
                nox_window_call_field_94((int)v3, 16397, (int)(v7 + 1), -1);
            ++v1;
        }
        v8 = sub_4200F0();
        if (sub_4207A0(v8) <= 0)
        {
            v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1962);
            sub_46ABB0((int)v9, 0);
        }
        else
        {
            nox_window_call_field_94((int)v3, 16403, 0, 0);
        }
        v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1964);
        v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1965);
        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1966);
        v13 = (_DWORD*)v3[8];
        v19 = (int)v12;
        v18 = sub_42F970("UISlider");
        v14 = sub_42F970("UISliderLit");
        sub_4B5700((int)v10, 0, 0, (int)v18, (int)v14, (int)v14);
        sub_46B280((int)v10, (int)v3);
        sub_46B280((int)v11, (int)v3);
        sub_46B280(v19, (int)v3);
        v13[9] = v10;
        v13[7] = v11;
        v13[8] = v19;
        *(_DWORD*)(v10[100] + 8) = 16;
        *(_DWORD*)(v10[100] + 12) = 10;
        if (sub_40A5C0(0x2000000) && v16 && v17 != -1)
        {
            *(_DWORD*)(sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1961)[8] + 48) = v17;
            v15 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1962);
            nox_window_call_field_94(*(int*)& byte_5D4594[830108], 16391, (int)v15, 0);
        }
        result = 1;
    }
    return result;
}

//----- (004497D0) --------------------------------------------------------
int __cdecl sub_4497D0(int a1, int a2, int* a3, int a4)
{
    _DWORD* v3; // esi
    int v4; // eax
    int result; // eax
    int v6; // eax
    int v7; // eax
    int v8; // edi
    _DWORD* v9; // eax
    int v10; // esi
    int v11; // eax
    const char* i; // eax
    int v13; // eax
    wchar_t* v14; // eax
    wchar_t* v15; // [esp-10h] [ebp-18h]

    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        result = 1;
    }
    else if (a2 == 16391)
    {
        v6 = sub_46B0A0(a3) - 1952;
        if (v6)
        {
            v7 = v6 - 10;
            if (v7)
            {
                if (v7 == 1)
                {
                    sub_46C6E0(*(int*)& byte_5D4594[830108]);
                    sub_46C4E0(*(_DWORD * *)& byte_5D4594[830108]);
                    *(_DWORD*)& byte_5D4594[830108] = 0;
                    if (sub_41E2F0() != 7)
                    {
                        sub_468020();
                        sub_452D80(921, 100);
                        return 1;
                    }
                }
            }
            else
            {
                v8 = 0;
                v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1961);
                v10 = nox_window_call_field_94((int)v9, 16404, 0, 0);
                if (v10 >= 0)
                {
                    v11 = sub_4200F0();
                    for (i = sub_4205B0(v11); i; i = (const char*)sub_4206B0((int)i))
                    {
                        if (!v10)
                            break;
                        --v10;
                    }
                    sub_4207D0((int)i);
                    if (sub_41E2F0() == 7)
                    {
                        v8 = 1;
                        sub_41E300(3);
                    }
                    v13 = sub_41E2F0();
                    sub_41DA70(v13, 3);
                }
                sub_46C6E0(*(int*)& byte_5D4594[830108]);
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830108]);
                *(_DWORD*)& byte_5D4594[830108] = 0;
                if (v8)
                {
                    v15 = loadString_sub_40F1D0((char*)& byte_587000[112880], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 175);
                    v14 = loadString_sub_40F1D0((char*)& byte_587000[112952], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\woldlgs.c", 174);
                    sub_449A10(0, (int)v14, (int)v15, 288, 0, 0);
                    sub_44A4B0();
                    sub_452D80(921, 100);
                    return 1;
                }
            }
        }
        else
        {
            sub_46C6E0(*(int*)& byte_5D4594[830096]);
            sub_46C4E0(*(_DWORD * *)& byte_5D4594[830096]);
            *(_DWORD*)& byte_5D4594[830112] = 0;
            sub_447600();
        }
        sub_452D80(921, 100);
        result = 1;
    }
    else
    {
        if (a2 == 16400 && sub_46B0A0(a3) == 1961)
        {
            v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830108], 1962);
            v4 = nox_window_call_field_94((int)a3, 16404, 0, 0);
            sub_46ABB0((int)v3, v4 >= 0);
        }
        result = 0;
    }
    return result;
}

//----- (00449A10) --------------------------------------------------------
_DWORD* __cdecl sub_449A10(int a1, int a2, int a3, int a4, int (*a5)(void), int (*a6)(void))
{
    int v6; // esi
    _DWORD* result; // eax
    _DWORD* v8; // eax
    _DWORD* v9; // eax
    _DWORD* v10; // eax
    _DWORD* v11; // eax

    v6 = *(_DWORD*)& byte_587000[26048];
    if (*(_DWORD*)& byte_5D4594[830224] && *(_DWORD*)& byte_5D4594[830216])
        (*(void (**)(void)) & byte_5D4594[830216])();
    *(_DWORD*)& byte_5D4594[830228] = a1;
    *(_DWORD*)& byte_5D4594[830232] = 0;
    *(_DWORD*)& byte_5D4594[830220] = a5;
    *(_DWORD*)& byte_5D4594[830216] = a6;
    if (*(_DWORD*)& byte_5D4594[830224])
    {
        sub_449EA0(a4);
        if (a2)
            sub_449E00(a2);
        result = (_DWORD*)a3;
        if (a3)
            result = (_DWORD*)sub_449E30(a3);
    }
    else
    {
        *(_DWORD*)& byte_5D4594[830240] = 0;
        if (sub_43F320(0) > 10)
            v6 = 2;
        result = nox_new_window_from_file(*(const char**)& byte_587000[4 * v6 + 112976], sub_449CA0);
        *(_DWORD*)& byte_5D4594[830224] = result;
        if (result)
        {
            sub_46B300((int)result, sub_449BE0);
            v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
            sub_46B300((int)v8, sub_449C30);
            v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
            sub_46B300((int)v9, sub_449C30);
            if (a2)
            {
                v10 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4005);
                nox_window_call_field_94((int)v10, 16385, a2, -1);
            }
            if (a3)
            {
                v11 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
                nox_window_call_field_94((int)v11, 16385, a3, -1);
            }
            sub_46B120(*(_DWORD * *)& byte_5D4594[830224], 0);
            sub_46A8C0(*(int*)& byte_5D4594[830224]);
            sub_46C690(*(int*)& byte_5D4594[830224]);
            sub_46A9B0(
                    *(_DWORD * *)& byte_5D4594[830224],
                    (nox_win_width - *(int*)(*(_DWORD*)& byte_5D4594[830224] + 8)) / 2,
                    (nox_win_height - *(int*)(*(_DWORD*)& byte_5D4594[830224] + 12)) / 2);
            sub_449EA0(a4);
            result = (_DWORD*)sub_46AE00();
            *(_DWORD*)& byte_5D4594[830236] = result;
            if (result)
                result = (_DWORD*)sub_46ADE0((int)result);
        }
    }
    return result;
}

//----- (00449BE0) --------------------------------------------------------
int __cdecl sub_449BE0(int a1, int a2, int a3, int a4)
{
    int2* v4; // eax

    if (a2 != 21)
        return 0;
    if (a3 == 1)
        return 1;
    if (a3 == 57)
    {
        v4 = sub_4309F0();
        nox_window_call_field_93(a1, 5, v4->field_0 | (v4->field_4 << 16), 0);
    }
    return 0;
}

//----- (00449C30) --------------------------------------------------------
int __cdecl sub_449C30(_DWORD* a1, int a2, int a3, int a4)
{
    _DWORD* v4; // eax
    int v5; // esi

    if (a2 == 21 && a3 == 28)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        v5 = (int)v4;
        if (v4[1] & 8)
        {
            if (!wndIsShown_sub_46ACC0((int)v4))
                nox_window_call_field_94(*(int*)& byte_5D4594[830224], 16391, v5, 0);
        }
    }
    return sub_487D70(a1, a2, a3, a4);
}

//----- (00449CA0) --------------------------------------------------------
int __cdecl sub_449CA0(int a1, int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // eax

    if (a2 == 23)
        return 1;
    if (a2 != 16391)
        return 0;
    switch (sub_46B0A0(a3))
    {
        case 4001:
        case 4007:
            if (byte_5D4594[830240] & 0x20)
                sub_46C6E0(*(int*)& byte_5D4594[830224]);
            nox_window_call_field_94(*(int*)& byte_5D4594[830228], 16391, (int)a3, a4);
            if (*(_DWORD*)& byte_5D4594[830220])
                (*(void (**)(void)) & byte_5D4594[830220])();
            if (!(byte_5D4594[830240] & 0x20))
                return 0;
            sub_44A400();
            result = 0;
            break;
        case 4002:
        case 4006:
            if (byte_5D4594[830240] & 0x20)
                sub_46C6E0(*(int*)& byte_5D4594[830224]);
            nox_window_call_field_94(*(int*)& byte_5D4594[830228], 16391, (int)a3, a4);
            if (*(_DWORD*)& byte_5D4594[830216])
                (*(void (**)(void)) & byte_5D4594[830216])();
            if (!(byte_5D4594[830240] & 0x20))
                return 0;
            sub_44A400();
            result = 0;
            break;
        case 4009:
            sub_41E300(9);
            v5 = sub_41E2F0();
            sub_41DA70(v5, 8);
            sub_43C260();
            sub_44A200(256);
            sub_44A400();
            return 0;
        case 4010:
            nox_window_call_field_94(*(int*)& byte_5D4594[830228], 16391, (int)a3, a4);
            result = 0;
            break;
        default:
            return 0;
    }
    return result;
}

//----- (00449E00) --------------------------------------------------------
int __cdecl sub_449E00(int a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4005);
    return nox_window_call_field_94((int)v1, 16385, a1, -1);
}

//----- (00449E30) --------------------------------------------------------
int __cdecl sub_449E30(int a1)
{
    _DWORD* v1; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
    return nox_window_call_field_94((int)v1, 16385, a1, -1);
}

//----- (00449E60) --------------------------------------------------------
int __cdecl sub_449E60(char a1)
{
    _DWORD* v1; // eax

    if (a1 >= 0)
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
    else
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
    return nox_window_call_field_94((int)v1, 16413, 0, 0);
}

//----- (00449EA0) --------------------------------------------------------
void __cdecl sub_449EA0(int a1)
{
    __int16 v1; // bx
    _DWORD* v2; // esi
    _DWORD* v3; // esi
    _DWORD* v4; // esi
    _DWORD* v5; // esi
    _DWORD* v6; // esi
    _DWORD* v7; // esi
    _DWORD* v8; // esi
    _DWORD* v9; // esi
    int result; // eax
    int v11; // [esp-4h] [ebp-Ch]
    int v12; // [esp-4h] [ebp-Ch]
    int v13; // [esp-4h] [ebp-Ch]
    int v14; // [esp-4h] [ebp-Ch]
    int v15; // [esp-4h] [ebp-Ch]
    int v16; // [esp-4h] [ebp-Ch]
    int v17; // [esp-4h] [ebp-Ch]
    int v18; // [esp-4h] [ebp-Ch]

    v1 = a1 ^ *(_WORD*)& byte_5D4594[830240];
    if (((unsigned __int8)a1 ^ byte_5D4594[830240]) & 1)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        v11 = wndIsShown_sub_46ACC0((int)v2) == 0;
        nox_window_set_hidden((int)v2, v11);
    }
    if (v1 & 2)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
        v12 = wndIsShown_sub_46ACC0((int)v3) == 0;
        nox_window_set_hidden((int)v3, v12);
    }
    if (v1 & 0x100)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4009);
        v13 = wndIsShown_sub_46ACC0((int)v4) == 0;
        nox_window_set_hidden((int)v4, v13);
    }
    if (v1 & 0x200)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4010);
        v14 = wndIsShown_sub_46ACC0((int)v5) == 0;
        nox_window_set_hidden((int)v5, v14);
    }
    if (v1 & 8)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4007);
        v15 = wndIsShown_sub_46ACC0((int)v6) == 0;
        nox_window_set_hidden((int)v6, v15);
    }
    if (v1 & 0x10)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4006);
        v16 = wndIsShown_sub_46ACC0((int)v7) == 0;
        nox_window_set_hidden((int)v7, v16);
    }
    if (v1 & 4)
    {
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
        v17 = wndIsShown_sub_46ACC0((int)v8) == 0;
        nox_window_set_hidden((int)v8, v17);
    }
    if ((v1 & 0x80u) != 0)
    {
        v9 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
        v18 = wndIsShown_sub_46ACC0((int)v9) == 0;
        nox_window_set_hidden((int)v9, v18);
    }
    if (a1 & 0x40)
        sub_430A70_set_mouse_bounds(
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 16),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 24),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 20),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 28));
    else
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    *(_DWORD*)& byte_5D4594[830240] = a1;
}

//----- (0044A0B0) --------------------------------------------------------
int __cdecl sub_44A0B0(int a1)
{
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    int result; // eax

    if (a1 & 1)
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        nox_window_set_hidden((int)v1, 0);
    }
    if (a1 & 2)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
        nox_window_set_hidden((int)v2, 0);
    }
    if (a1 & 0x100)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4009);
        nox_window_set_hidden((int)v3, 0);
    }
    if (a1 & 0x200)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4010);
        nox_window_set_hidden((int)v4, 0);
    }
    if (a1 & 8)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4007);
        nox_window_set_hidden((int)v5, 0);
    }
    if (a1 & 0x10)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4006);
        nox_window_set_hidden((int)v6, 0);
    }
    if (a1 & 4)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
        nox_window_set_hidden((int)v7, 0);
    }
    if ((a1 & 0x80u) != 0)
    {
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
        nox_window_set_hidden((int)v8, 0);
    }
    if (a1 & 0x40)
        sub_430A70_set_mouse_bounds(
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 16),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 20),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 24),
                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830224] + 28));
    else
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    result = a1 | *(_DWORD*)& byte_5D4594[830240];
    *(_DWORD*)& byte_5D4594[830240] |= a1;
    return result;
}

//----- (0044A200) --------------------------------------------------------
int __cdecl sub_44A200(int a1)
{
    _DWORD* v1; // eax
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // eax
    _DWORD* v6; // eax
    _DWORD* v7; // eax
    _DWORD* v8; // eax
    int result; // eax

    if (a1 & 1)
    {
        v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4001);
        nox_window_set_hidden((int)v1, 1);
    }
    if (a1 & 2)
    {
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
        nox_window_set_hidden((int)v2, 1);
    }
    if (a1 & 0x100)
    {
        v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4009);
        nox_window_set_hidden((int)v3, 1);
    }
    if (a1 & 0x200)
    {
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4010);
        nox_window_set_hidden((int)v4, 1);
    }
    if (a1 & 8)
    {
        v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4007);
        nox_window_set_hidden((int)v5, 1);
    }
    if (a1 & 0x10)
    {
        v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4006);
        nox_window_set_hidden((int)v6, 1);
    }
    if (a1 & 4)
    {
        v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4003);
        nox_window_set_hidden((int)v7, 1);
    }
    if ((a1 & 0x80u) != 0)
    {
        v8 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4008);
        nox_window_set_hidden((int)v8, 1);
    }
    if (a1 & 0x40)
        sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    result = ~a1 & *(_DWORD*)& byte_5D4594[830240];
    *(_DWORD*)& byte_5D4594[830240] &= ~a1;
    return result;
}

//----- (0044A340) --------------------------------------------------------
int __cdecl sub_44A340(int a1, int a2)
{
    return sub_46A9B0(*(_DWORD * *)& byte_5D4594[830224], a1, a2);
}

//----- (0044A360) --------------------------------------------------------
void __cdecl sub_44A360(int a1)
{
    _DWORD* v1; // esi
    _DWORD* v2; // esi
    int result; // eax

    v1 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4005);
    if (a1 == 1)
    {
        v1[59] = sub_43F360((char*)& byte_587000[113100]);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
        result = sub_43F360((char*)& byte_587000[113108]);
    }
    else
    {
        v1[59] = sub_43F360((char*)& byte_587000[113116]);
        v2 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4004);
        result = sub_43F360((char*)& byte_587000[113124]);
    }
    v2[59] = result;
}

//----- (0044A400) --------------------------------------------------------
int sub_44A400()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[830224];
    if (*(_DWORD*)& byte_5D4594[830224])
    {
        if (*(_DWORD*)& byte_5D4594[830236])
        {
            sub_46ADC0(*(int*)& byte_5D4594[830236]);
            *(_DWORD*)& byte_5D4594[830236] = 0;
        }
        sub_46C6E0(*(int*)& byte_5D4594[830224]);
        sub_46ADE0(*(int*)& byte_5D4594[830224]);
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[830224]);
        if (*(_DWORD*)& byte_5D4594[830232])
            sub_46B500(*(int*)& byte_5D4594[830232]);
        *(_DWORD*)& byte_5D4594[830224] = 0;
        *(_DWORD*)& byte_5D4594[830228] = 0;
        sub_477610(0);
        result = sub_430A70_set_mouse_bounds(0, nox_win_width - 1, 0, nox_win_height - 1);
    }
    return result;
}

//----- (0044A4A0) --------------------------------------------------------
BOOL sub_44A4A0()
{
    return *(_DWORD*)& byte_5D4594[830224] != 0;
}

//----- (0044A4B0) --------------------------------------------------------
int sub_44A4B0()
{
    int result; // eax

    result = *(_DWORD*)& byte_5D4594[830224];
    if (*(_DWORD*)& byte_5D4594[830224])
        result = sub_46A8C0(*(int*)& byte_5D4594[830224]);
    return result;
}

//----- (0044A4D0) --------------------------------------------------------
int __cdecl sub_44A4D0(int a1)
{
    int result; // eax

    result = a1;
    *(_DWORD*)& byte_5D4594[830232] = a1;
    return result;
}

//----- (0044A4E0) --------------------------------------------------------
int sub_44A4E0()
{
    _DWORD* v0; // eax

    if (!sub_44A4A0())
        return 0;
    v0 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830224], 4002);
    nox_window_call_field_94(*(int*)& byte_5D4594[830224], 16391, (int)v0, 0);
    return 1;
}

//----- (0044A520) --------------------------------------------------------
char* __cdecl sub_44A520(int a1)
{
    int v1; // eax
    int v2; // edx
    unsigned __int8* v3; // ecx

    v1 = *(_DWORD*)& byte_587000[113136];
    v2 = 0;
    if (!*(_DWORD*)& byte_587000[113136])
        return *(char**)& byte_587000[113140];
    v3 = &byte_587000[113136];
    while (v1 != a1)
    {
        v1 = *((_DWORD*)v3 + 2);
        v3 += 8;
        ++v2;
        if (!v1)
            return *(char**)& byte_587000[113140];
    }
    return *(char**)& byte_587000[8 * v2 + 113140];
}

//----- (0044A560) --------------------------------------------------------
int sub_44A560()
{
    int result; // eax
    int i; // esi
    int v2; // esi
    _DWORD* v3; // eax
    _DWORD* v4; // eax
    _DWORD* v5; // esi
    _DWORD* v6; // ebp
    _DWORD* v7; // ebx
    _DWORD* v8; // edi
    char* v9; // eax
    wchar_t* v10; // eax
    wchar_t* v11; // eax
    _DWORD* v12; // esi
    int v13; // eax
    _DWORD* v14; // eax
    wchar_t* v15; // [esp-10h] [ebp-ECh]
    _BYTE* v16; // [esp+8h] [ebp-D4h]
    _BYTE* v17; // [esp+Ch] [ebp-D0h]
    char* v18; // [esp+10h] [ebp-CCh]
    wchar_t v19[100]; // [esp+14h] [ebp-C8h]

    sub_40A4D0(4);
    sub_43AF50(1);
    sub_41E300(1);
    sub_4A1BE0(1);
    sub_4A1A40(0);
    sub_41D4C0();
    sub_41D440();
    if (*(_DWORD*)& byte_5D4594[830248])
    {
        sub_46ABB0(*(int*)& byte_5D4594[830248], 1);
    }
    else
    {
        sub_43BDD0(1700);
        result = nox_new_window_from_file("wolapi.wnd", sub_44AB30);
        *(_DWORD*)& byte_5D4594[830248] = result;
        if (!result)
            return result;
        result = sub_43C5B0((_DWORD*)result, 0, 0, 0, -480, 0, 20, 0, -40);
        *(_DWORD*)& byte_5D4594[830244] = result;
        if (!result)
            return result;
        *(_DWORD*)result = 1700;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830244] + 48) = sub_44AA40;
        *(_DWORD*)(*(_DWORD*)& byte_5D4594[830244] + 56) = sub_44AA70;
        nox_window_set_all_funcs(*(_DWORD * *)& byte_5D4594[830248], sub_44AAC0, 0, 0);
    }
    sub_41FCF0();
    *(_DWORD*)& byte_5D4594[830264] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1708);
    nox_window_call_field_94(*(int*)& byte_5D4594[830264], 16399, 0, 0);
    for (i = 0; i < 128; ++i)
    {
        sub_41FB90(i, &v16, &v17);
        nox_swprintf(v19, L"%S", v16);
        if (!v19[0])
            nox_swprintf(v19, L" ");
        nox_window_call_field_94(*(int*)& byte_5D4594[830264], 16397, (int)v19, -1);
    }
    v2 = sub_41FC40();
    if (v2 == -1)
    {
        sub_41FC20(0);
        v2 = 0;
    }
    nox_window_call_field_94(*(int*)& byte_5D4594[830264], 16403, v2, 0);
    sub_41FB90(v2, &v16, &v17);
    *(_DWORD*)& byte_5D4594[830256] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1701);
    if (v16 && *v16)
    {
        nox_swprintf(v19, L"%S", v16);
        nox_window_call_field_94(*(int*)& byte_5D4594[830256], 16414, (int)v19, 0);
    }
    *(_DWORD*)& byte_5D4594[830260] = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1702);
    sub_46B300(*(int*)& byte_5D4594[830260], sub_44AAD0);
    v3 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1703);
    *(_DWORD*)& byte_5D4594[830252] = v3;
    if (v17 && *v17)
    {
        nox_swprintf(v19, L"%S", v17);
        nox_window_call_field_94(*(int*)& byte_5D4594[830260], 16414, (int)v19, 0);
        v4 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1703);
        v4[9] |= 4u;
        *(_DWORD*)& byte_5D4594[830276] = 1;
    }
    else
    {
        v3[9] &= 0xFFFFFFFB;
        *(_DWORD*)& byte_5D4594[830276] = 0;
    }
    v5 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1709);
    v6 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1710);
    v7 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1711);
    v8 = *(_DWORD * *)(*(_DWORD*)& byte_5D4594[830264] + 32);
    v18 = sub_42F970("UISlider");
    v9 = sub_42F970("UISliderLit");
    sub_4B5700((int)v5, 0, 0, (int)v18, (int)v9, (int)v9);
    sub_46B280((int)v5, *(int*)& byte_5D4594[830264]);
    sub_46B280((int)v6, *(int*)& byte_5D4594[830264]);
    sub_46B280((int)v7, *(int*)& byte_5D4594[830264]);
    v8[9] = v5;
    v8[7] = v6;
    v8[8] = v7;
    *(_DWORD*)(v5[100] + 8) = 16;
    *(_DWORD*)(v5[100] + 12) = 10;
    if (*(_DWORD*)& byte_5D4594[830272] == 1 || sub_4D3320() == 1)
    {
        if (sub_40A5C0(0x2000000))
        {
            if (*(_DWORD*)& byte_5D4594[830272] == 1)
            {
                v10 = loadString_sub_40F1D0((char*)& byte_587000[113496], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wollogin.c", 485);
                sub_413D30((char*)& byte_587000[113524], v10);
            }
            else
            {
                sub_413D30((char*)& byte_587000[113528]);
            }
            sub_43DDD0(0);
            sub_43DE60();
            return 0;
        }
        v15 = loadString_sub_40F1D0((char*)& byte_587000[113628], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wollogin.c", 495);
        v11 = loadString_sub_40F1D0((char*)& byte_587000[113684], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wollogin.c", 495);
        sub_449A10(*(int*)& byte_5D4594[830248], (int)v11, (int)v15, 33, 0, 0);
        sub_44A4B0();
        *(_DWORD*)& byte_5D4594[830272] = 0;
    }
    if (!sub_44A4A0())
    {
        sub_46A8A0();
        sub_46B500(*(int*)& byte_5D4594[830256]);
    }
    *(_DWORD*)& byte_5D4594[830268] = 0;
    if (sub_40A5C0(0x2000000))
    {
        v12 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1708);
        v13 = sub_4A7F00();
        nox_window_call_field_94(*(int*)& byte_5D4594[830248], 16400, (int)v12, v13 - 1);
        v14 = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], 1706);
        nox_window_call_field_94(*(int*)& byte_5D4594[830248], 16391, (int)v14, 0);
    }
    return 1;
}

//----- (0044AA40) --------------------------------------------------------
int sub_44AA40()
{
    *(_BYTE*)(*(_DWORD*)& byte_5D4594[830244] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    sub_4207F0(1);
    return 1;
}

//----- (0044AA70) --------------------------------------------------------
int sub_44AA70()
{
    void (*v0)(void); // esi

    v0 = *(void (**)(void))(*(_DWORD*)& byte_5D4594[830244] + 52);
    sub_43C570(*(LPVOID*)& byte_5D4594[830244]);
    if (*(_DWORD*)& byte_5D4594[830248])
    {
        sub_46C4E0(*(_DWORD * *)& byte_5D4594[830248]);
        *(_DWORD*)& byte_5D4594[830248] = 0;
    }
    sub_43BE40(1);
    v0();
    return 1;
}

//----- (0044AAC0) --------------------------------------------------------
int sub_44AAC0()
{
    return 0;
}

//----- (0044AAD0) --------------------------------------------------------
int __cdecl sub_44AAD0(_DWORD* a1, int a2, int a3, int a4)
{
    if (a2 == 21)
    {
        if (*(_DWORD*)& byte_5D4594[830268])
        {
            nox_window_call_field_94((int)a1, 16414, (int)& byte_5D4594[830284], 0);
            sub_41FAE0((const char*)& byte_5D4594[830288]);
        }
        *(_DWORD*)& byte_5D4594[830268] = 0;
    }
    return sub_487D70(a1, a2, a3, a4);
}

//----- (0044AB30) --------------------------------------------------------
int __cdecl sub_44AB30(int a1, unsigned int a2, int* a3, int a4)
{
    int result; // eax
    int v5; // eax
    int v6; // esi
    int v7; // eax
    int v8; // eax
    int v9; // esi
    int v10; // esi
    int v11; // eax
    int v12; // eax
    int v13; // eax
    char* v14; // eax
    int v15; // eax
    int v16; // [esp-4h] [ebp-210h]
    _BYTE* v17; // [esp+4h] [ebp-208h]
    int v18; // [esp+8h] [ebp-204h]
    wchar_t File[128]; // [esp+Ch] [ebp-200h]
    char v20[256]; // [esp+10Ch] [ebp-100h]

    if (a2 > 0x4005)
    {
        if (a2 != 16391)
        {
            if (a2 == 16400)
            {
                v6 = sub_46B0A0(a3);
                sub_452D80(766, 100);
                if (v6 == 1708 && a4 >= 0 && a4 < 128)
                {
                    sub_41FC20(a4);
                    sub_41FB90(a4, &v18, &v17);
                    if (v18)
                    {
                        nox_swprintf(File, L"%S", v18);
                        nox_window_call_field_94(*(int*)& byte_5D4594[830256], 16414, (int)File, 0);
                    }
                    if (v17)
                    {
                        nox_swprintf(File, L"%S", v17);
                        nox_window_call_field_94(*(int*)& byte_5D4594[830260], 16414, (int)File, 0);
                        if (v17)
                        {
                            if (*v17)
                            {
                                *(_DWORD*)(*(_DWORD*)& byte_5D4594[830252] + 36) |= 4u;
                                *(_DWORD*)& byte_5D4594[830276] = 1;
                                return 0;
                            }
                        }
                    }
                    *(_DWORD*)(*(_DWORD*)& byte_5D4594[830252] + 36) &= 0xFFFFFFFB;
                    *(_DWORD*)& byte_5D4594[830276] = 0;
                }
            }
            return 0;
        }
        v7 = sub_46B0A0(a3);
        if (v7 > 1706)
        {
            if (v7 != 1985)
            {
                if (v7 == 4010)
                {
                    v16 = sub_4200F0();
                    v14 = sub_44A520(*(int*)& byte_5D4594[830280]);
                    nox_sprintf((char*)File, "%s%d.html", v14, v16);
                    ShellExecuteA(0, 0, (LPCSTR)File, 0, (LPCSTR)& byte_587000[113732], 3);
                }
                goto LABEL_42;
            }
        }
        else
        {
            if (v7 != 1706)
            {
                v8 = v7 - 1703;
                if (v8)
                {
                    if (v8 == 2)
                    {
                        sub_41E300(6);
                        sub_4207F0(6);
                        sub_46ABB0(*(int*)& byte_5D4594[830248], 0);
                        sub_40E090();
                        sub_4A1BE0(0);
                    }
                }
                else
                {
                    *(_DWORD*)& byte_5D4594[830276] ^= 1u;
                    if (*(_DWORD*)& byte_5D4594[830276])
                    {
                        v10 = sub_41F9A0();
                        nox_window_call_field_94(*(int*)& byte_5D4594[830264], 16403, v10, 0);
                        sub_41FC20(v10);
                    }
                    else
                    {
                        v9 = sub_41FB60();
                        sub_41FC20(128);
                        sub_41FB70(v9);
                    }
                }
                goto LABEL_42;
            }
            v17 = 0;
            if (!*(_DWORD*)& byte_5D4594[830276])
                sub_41FC20(128);
            v11 = nox_window_call_field_94(*(int*)& byte_5D4594[830256], 16413, 0, 0);
            nox_sprintf(v20, "%S", v11);
            sub_41FA80(v20);
            v12 = nox_window_call_field_94(*(int*)& byte_5D4594[830260], 16413, 0, 0);
            nox_sprintf(v20, "%S", v12);
            sub_41FAE0(v20);
            sub_41FC50();
            v13 = sub_41FC40();
            sub_40DB50(v13 + 1, (int)& v17);
            if (!v17)
            {
                sub_4B5770(*(int*)& byte_5D4594[830248]);
                LABEL_42:
                sub_452D80(921, 100);
                return 1;
            }
        }
        *(_DWORD*)& byte_5D4594[830276] = (unsigned __int8)(*(_BYTE*)(*(_DWORD*)& byte_5D4594[830252] + 36) & 4) >> 2;
        sub_41E300(2);
        v15 = sub_41E2F0();
        sub_41DA70(v15, 0);
        sub_4207F0(2);
        sub_40E090();
        sub_46ABB0(*(int*)& byte_5D4594[830248], 0);
        sub_4A1BE0(0);
        goto LABEL_42;
    }
    if (a2 == 16389)
    {
        sub_452D80(920, 100);
        return 1;
    }
    if (a2 == 2)
    {
        *(_DWORD*)& byte_5D4594[830248] = 0;
        return 0;
    }
    if (a2 != 16387)
        return 0;
    result = sub_46B0C0(*(_DWORD * *)& byte_5D4594[830248], a4);
    if (!result)
        return result;
    if ((unsigned __int16)a3 != 1)
    return 0;
    if (a4 == 1702)
    {
        v5 = nox_window_call_field_94(result, 16413, 0, 0);
        nox_sprintf(v20, "%S", v5);
        if (v20[0])
            * (_DWORD*)& byte_5D4594[830268] = 1;
    }
    return 0;
}

//----- (0044AF70) --------------------------------------------------------
int sub_44AF70()
{
    int result; // eax

    *(_BYTE*)(*(_DWORD*)& byte_5D4594[830244] + 64) = 2;
    sub_43BE40(2);
    sub_452D80(923, 100);
    result = 1;
    *(_DWORD*)(*(_DWORD*)& byte_5D4594[830244] + 52) = sub_447620;
    *(_DWORD*)& byte_5D4594[830248] = 0;
    return result;
}

//----- (0044AFB0) --------------------------------------------------------
_DWORD* __cdecl sub_44AFB0(int a1, int a2, int a3)
{
    _DWORD* result; // eax

    if (a3 < -2147221388 || a3 > -2147221386)
        result = sub_449A10(*(int*)& byte_5D4594[830248], a1, a2, 33, 0, 0);
    else
        result = sub_449A10(*(int*)& byte_5D4594[830248], a1, a2, 545, 0, 0);
    *(_DWORD*)& byte_5D4594[830280] = a3;
    return result;
}

//----- (0044B000) --------------------------------------------------------
void sub_44B000()
{
    *(_DWORD*)& byte_5D4594[830272] = 1;
}

//----- (0044B010) --------------------------------------------------------
void sub_44B010()
{
    wchar_t* v0; // eax
    wchar_t* v1; // eax

    sub_43C260();
    sub_41E300(9);
    sub_44E040();
    if (sub_40A5C0(0x2000000))
    {
        v0 = loadString_sub_40F1D0((char*)& byte_587000[113772], 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 75);
        sub_413D30((char*)& byte_587000[113788], v0);
        if (sub_43C710())
            sub_41E400();
        else
            sub_4460C0();
    }
    else if (sub_40A5C0(1))
    {
        *(_DWORD*)& byte_5D4594[830292] = nox_new_window_from_file("woldisc.wnd", sub_44B0F0);
        sub_46A9B0(
                *(_DWORD * *)& byte_5D4594[830292],
                nox_win_width / 2 - *(int*)(*(_DWORD*)& byte_5D4594[830292] + 24) / 2,
                nox_win_height / 2 - *(int*)(*(_DWORD*)& byte_5D4594[830292] + 28) / 2);
    }
    else
    {
        v1 = loadString_sub_40F1D0((char*)& byte_587000[113840], 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 100);
        sub_445490(v1);
    }
}

//----- (0044B0F0) --------------------------------------------------------
int __cdecl sub_44B0F0(int a1, int a2, int* a3, int a4)
{
    int v3; // eax

    if (a2 != 23)
    {
        if (a2 == 16391)
        {
            v3 = sub_46B0A0(a3) - 581;
            if (!v3)
            {
                sub_44B000();
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830292]);
                goto LABEL_7;
            }
            if (v3 == 1)
            {
                sub_4460C0();
                sub_44A400();
                sub_46C4E0(*(_DWORD * *)& byte_5D4594[830292]);
                LABEL_7:
                *(_DWORD*)& byte_5D4594[830292] = 0;
                return 0;
            }
        }
        return 0;
    }
    return 1;
}

//----- (0044B160) --------------------------------------------------------
int __cdecl nox_parse_thing_flags(nox_thing* obj, int a2, const char* a3)
{
    obj->flags = 0;
    sub_423930(a3, &obj->flags, (const char**)& byte_587000[114076]);
    return 1;
}

//----- (0044B190) --------------------------------------------------------
int __cdecl nox_parse_thing_class(nox_thing* obj, int a2, const char* a3)
{
    obj->pri_class = 0;
    sub_423930(a3, &obj->pri_class, (const char**)& byte_587000[114208]);
    return 1;
}

//----- (0044B1C0) --------------------------------------------------------
int __cdecl nox_parse_thing_subclass(nox_thing* obj, int a2, const char* a3)
{
    obj->sub_class = 0;
    sub_423A10(a3, &obj->sub_class);
    return 1;
}

//----- (0044B1F0) --------------------------------------------------------
int __cdecl nox_parse_thing_extent(int a1, int a2, char* a3)
{
    int result; // eax
    shape v4; // [esp+0h] [ebp-3Ch]

    result = sub_423AD0(&v4, a3);
    *(_BYTE*)(a1 + 20) = v4.field_0;
    *(float*)(a1 + 64) = v4.field_4;
    *(float*)(a1 + 76) = v4.field_C;
    *(float*)(a1 + 80) = v4.field_10;
    return result;
}

//----- (0044B230) --------------------------------------------------------
int __cdecl nox_parse_thing_light_intensity(int a1, int a2, char* a3)
{
    sscanf(a3, "%f", a1 + 44);
    return 1;
}

//----- (0044B250) --------------------------------------------------------
int __cdecl nox_parse_thing_light_color(int a1, int a2, char* a3)
{
    int v4; // esi
    int v5; // edx
    int v6; // ecx
    int v7; // [esp+0h] [ebp-8h]
    int v8; // [esp+4h] [ebp-4h]

    if (sscanf(a3, "%d %d %d", &a3, &v7, &v8) != 3)
        return 0;
    v4 = (int)a3;
    if ((int)a3 > 255)
        v4 = 255;
    v5 = v7;
    if (v7 > 255)
        v5 = 255;
    v6 = v8;
    if (v8 > 255)
        v6 = 255;
    *(_BYTE*)(a1 + 15) = 2;
    *(_DWORD*)(a1 + 48) = v4;
    *(_DWORD*)(a1 + 52) = v5;
    *(_DWORD*)(a1 + 56) = v6;
    return 1;
}

//----- (0044B2D0) --------------------------------------------------------
int __cdecl nox_parse_thing_light_dir(int a1, int a2, char* a3)
{
    if (sscanf(a3, "%d", &a3) != 1 || (int)a3 < 0 || (int)a3 >= 360)
        return 0;
    *(_WORD*)(a1 + 24) = (__int64)((double)(int)a3 * *(double*)& byte_581450[9560] * *(double*)& byte_581450[9552]
                                   + *(double*)& byte_581450[9544]);
    *(_DWORD*)(a1 + 16) = 0;
    return 1;
}

//----- (0044B330) --------------------------------------------------------
int __cdecl nox_parse_thing_light_penumbra(int a1, int a2, char* a3)
{
    if (sscanf(a3, "%d", &a3) != 1 || (int)a3 < 0 || (int)a3 >= 180)
        return 0;
    *(_WORD*)(a1 + 26) = (__int64)((double)(int)a3 * *(double*)& byte_581450[9560] * *(double*)& byte_581450[9552]
                                   + *(double*)& byte_581450[9544]);
    return 1;
}

//----- (0044B390) --------------------------------------------------------
int __cdecl sub_44B390(int a1, int a2, _BYTE* a3)
{
    _DWORD* v3; // eax
    int v4; // esi
    _DWORD* v5; // edi
    _BYTE* v6; // ebx
    char* v7; // eax
    char v8; // cl
    char* v9; // eax
    char v10; // cl
    unsigned __int8* v11; // eax
    int result; // eax
    int v13; // ebp
    int* v14; // eax
    int v15; // ecx
    char* v16; // eax
    char v17; // cl
    int v18; // [esp-Ch] [ebp-24h]
    const char* v19; // [esp+14h] [ebp-4h]
    unsigned __int8 v20; // [esp+20h] [ebp+8h]
    unsigned __int8 v21; // [esp+20h] [ebp+8h]
    int v22; // [esp+24h] [ebp+Ch]

    v3 = nox_calloc(1u, 0x10u);
    v4 = a2;
    v5 = v3;
    v6 = a3;
    v18 = a2;
    *v3 = 16;
    v7 = *(char**)(a2 + 8);
    v8 = *v7;
    *(_DWORD*)(a2 + 8) = v7 + 1;
    *((_BYTE*)v5 + 8) = v8;
    v9 = *(char**)(a2 + 8);
    v10 = *v9;
    *(_DWORD*)(a2 + 8) = v9 + 1;
    *((_BYTE*)v5 + 9) = v10;
    v11 = *(unsigned __int8**)(a2 + 8);
    v20 = *v11;
    *(_DWORD*)(v4 + 8) = v11 + 1;
    sub_40ACC0(a3, 1u, v20, v18);
    a3[v20] = 0;
    v5[3] = sub_44B4C0(a3);
    result = (int)nox_malloc(4 * *((unsigned __int8*)v5 + 8));
    v5[1] = result;
    if (result)
    {
        v13 = 0;
        v22 = 0;
        if (*((_BYTE*)v5 + 8))
        {
            do
            {
                v14 = *(int**)(v4 + 8);
                v15 = *v14;
                *(_DWORD*)(v4 + 8) = v14 + 1;
                *v6 = byte_5D4594[830832];
                if (v15 == -1)
                {
                    v16 = *(char**)(v4 + 8);
                    v17 = *v16++;
                    *(_DWORD*)(v4 + 8) = v16;
                    LOBYTE(v19) = v17;
                    v21 = *v16;
                    *(_DWORD*)(v4 + 8) = v16 + 1;
                    sub_40ACC0(v6, 1u, v21, v4);
                    v15 = -1;
                    v6[v21] = 0;
                    v13 = v22;
                }
                *(_DWORD*)(v5[1] + 4 * v13++) = sub_42FAA0(v15, v19, v6);
                v22 = v13;
            } while (v13 < *((unsigned __int8*)v5 + 8));
        }
        *(_DWORD*)(a1 + 92) = v5;
        *(_DWORD*)(a1 + 88) = nox_thing_animate_draw;
        result = 1;
    }
    return result;
}
// 44B47F: variable 'v19' is possibly undefined

//----- (0044B4C0) --------------------------------------------------------
int __cdecl sub_44B4C0(const char* a1)
{
    if (!strcmp(a1, "OneShot"))
        return 0;
    if (!strcmp(a1, "OneShotRemove"))
        return 1;
    if (!strcmp(a1, "Loop"))
        return 2;
    if (!strcmp(a1, "LoopAndFade"))
        return 3;
    if (!strcmp(a1, "Random"))
        return 4;
    return strcmp(a1, "Slave") != 0 ? 0 : 5;
}

//----- (0044B560) --------------------------------------------------------
int __cdecl sub_44B560(_DWORD* a1, int a2, _BYTE* a3)
{
    _DWORD* v3; // eax
    int v4; // esi
    unsigned __int8* v5; // ecx
    _BYTE* v6; // edi
    unsigned __int8* v7; // ebp
    unsigned __int8* v8; // eax
    unsigned __int8 v9; // cl
    unsigned __int8* v10; // eax
    unsigned __int8 v11; // cl
    unsigned __int8* v12; // eax
    _DWORD* v13; // ebx
    void* v14; // eax
    int* v15; // eax
    int v16; // ecx
    char* v17; // eax
    char v18; // cl
    int result; // eax
    _DWORD* v20; // [esp+10h] [ebp-18h]
    const char* v21; // [esp+18h] [ebp-10h]
    int v22; // [esp+1Ch] [ebp-Ch]
    int v23; // [esp+20h] [ebp-8h]
    _DWORD* v24; // [esp+24h] [ebp-4h]
    unsigned __int8 v25; // [esp+30h] [ebp+8h]
    unsigned __int8 v26; // [esp+30h] [ebp+8h]
    unsigned __int8 v27; // [esp+30h] [ebp+8h]
    int v28; // [esp+34h] [ebp+Ch]

    v3 = nox_calloc(1u, 0x38u);
    v4 = a2;
    *v3 = 16;
    v24 = v3;
    v5 = *(unsigned __int8**)(a2 + 8);
    v25 = *v5;
    *(_DWORD*)(v4 + 8) = v5 + 1;
    v23 = v25;
    if ((int)v25 <= 0)
    {
        LABEL_10:
        a1[23] = v3;
        a1[22] = nox_thing_cond_animate_draw;
        a1[24] = 0;
        result = 1;
    }
    else
    {
        v6 = a3;
        v20 = v3 + 1;
        v7 = (unsigned __int8*)(v3 + 6);
        v22 = -24 - (_DWORD)v3;
        while (1)
        {
            v8 = *(unsigned __int8**)(v4 + 8);
            v9 = *v8;
            *(_DWORD*)(v4 + 8) = v8 + 1;
            *v7 = v9;
            v10 = *(unsigned __int8**)(v4 + 8);
            v11 = *v10;
            *(_DWORD*)(v4 + 8) = v10 + 1;
            v7[5] = v11;
            v12 = *(unsigned __int8**)(v4 + 8);
            v26 = *v12;
            *(_DWORD*)(v4 + 8) = v12 + 1;
            sub_40ACC0(v6, 1u, v26, v4);
            v6[v26] = 0;
            v13 = v20;
            v20[8] = sub_44B4C0(v6);
            v14 = nox_malloc(4 * *v7);
            *v20 = v14;
            if (!v14)
                break;
            v28 = 0;
            if (*v7)
            {
                do
                {
                    v15 = *(int**)(v4 + 8);
                    v16 = *v15;
                    *(_DWORD*)(v4 + 8) = v15 + 1;
                    *v6 = byte_5D4594[830836];
                    if (v16 == -1)
                    {
                        v17 = *(char**)(v4 + 8);
                        v18 = *v17++;
                        *(_DWORD*)(v4 + 8) = v17;
                        LOBYTE(v21) = v18;
                        v27 = *v17;
                        *(_DWORD*)(v4 + 8) = v17 + 1;
                        sub_40ACC0(v6, 1u, v27, v4);
                        v16 = -1;
                        v6[v27] = 0;
                        v13 = v20;
                    }
                    *(_DWORD*)(*v13 + 4 * v28++) = sub_42FAA0(v16, v21, v6);
                } while (v28 < *v7);
            }
            ++v7;
            v20 = v13 + 1;
            if ((int)& v7[v22] >= v23)
            {
                v3 = v24;
                goto LABEL_10;
            }
        }
        result = 0;
    }
    return result;
}
// 44B68C: variable 'v21' is possibly undefined

//----- (0044B700) --------------------------------------------------------
int __cdecl sub_44B700(int a1, int a2, void* a3)
{
    _DWORD* v3; // eax
    int v4; // edi
    _DWORD* v5; // ebx
    _DWORD* v6; // eax
    int v7; // ecx
    unsigned __int8* v8; // eax
    int v10; // eax
    int v11; // ebx
    _DWORD* v12; // eax
    int v13; // ecx
    _DWORD* v14; // eax
    int v15; // ecx
    int v16; // eax
    int v17; // esi
    _DWORD* v18; // eax
    int v19; // esi
    _DWORD* v20; // eax
    _DWORD* v21; // [esp+10h] [ebp-4h]
    unsigned __int8 v22; // [esp+1Ch] [ebp+8h]
    unsigned __int8 v23; // [esp+1Ch] [ebp+8h]

    v3 = nox_calloc(1u, 14524);
    v4 = a2;
    v5 = v3;
    v21 = v3;
    *v3 = 14524;
    v6 = *(_DWORD * *)(a2 + 8);
    v7 = *v6;
    v8 = (unsigned __int8*)(v6 + 1);
    *(_DWORD*)(a2 + 8) = v8;
    if (v7 == 1162757152)
        return 0;
    LABEL_3:
    v22 = *v8;
    *(_DWORD*)(v4 + 8) = v8 + 1;
    sub_40ACC0(a3, 1u, v22, v4);
    *((_BYTE*)a3 + v22) = 0;
    v10 = sub_44BB20((const char*)a3);
    if (v10 < 0)
        return 0;
    v11 = (int)& v5[66 * v10 + 1];
    if (!sub_44B8B0(v11, v4))
        return 0;
    while (1)
    {
        v12 = *(_DWORD * *)(v4 + 8);
        v13 = *v12;
        v8 = (unsigned __int8*)(v12 + 1);
        *(_DWORD*)(v4 + 8) = v8;
        if (v13 == 1162757152)
            break;
        if (v13 == 1398030676)
        {
            v5 = v21;
            goto LABEL_3;
        }
        v23 = *v8;
        *(_DWORD*)(v4 + 8) = v8 + 1;
        sub_40ACC0(a3, 1u, v23, v4);
        *((_BYTE*)a3 + v23) = 0;
        if (!strcmp("NAKED", (const char*)a3))
        {
            v14 = nox_calloc(1u, 0x28u);
            v15 = *(__int16*)(v11 + 40);
            *(_DWORD*)(v11 + 48) = v14;
            v16 = sub_44B940(v14, v15, v4);
        }
        else
        {
            v17 = sub_44BA60((const char*)a3);
            if (v17 < 0)
            {
                v19 = sub_44BAC0((const char*)a3);
                if (v19 < 0)
                    return 0;
                v20 = nox_calloc(1u, 0x28u);
                *(_DWORD*)(v11 + 4 * v19 + 156) = v20;
                v16 = sub_44B940(v20, *(__int16*)(v11 + 40), v4);
            }
            else
            {
                v18 = nox_calloc(1u, 0x28u);
                *(_DWORD*)(v11 + 4 * v17 + 52) = v18;
                v16 = sub_44B940(v18, *(__int16*)(v11 + 40), v4);
            }
        }
        if (!v16)
            return 0;
    }
    *(_DWORD*)(a1 + 88) = nox_thing_player_draw;
    *(_DWORD*)(a1 + 92) = v21;
    return 1;
}

//----- (0044B8B0) --------------------------------------------------------
int __cdecl sub_44B8B0(int a1, int a2)
{
    unsigned __int8* v2; // ecx
    unsigned __int8 v3; // dl
    unsigned __int8* v4; // ecx
    unsigned __int8 v5; // dl
    unsigned __int8* v6; // ecx
    unsigned __int8 v8; // [esp+8h] [ebp-104h]
    char v9[256]; // [esp+Ch] [ebp-100h]

    v2 = *(unsigned __int8**)(a2 + 8);
    v3 = *v2;
    *(_DWORD*)(a2 + 8) = v2 + 1;
    *(_WORD*)(a1 + 40) = v3;
    v4 = *(unsigned __int8**)(a2 + 8);
    v5 = *v4;
    *(_DWORD*)(a2 + 8) = v4 + 1;
    *(_WORD*)(a1 + 42) = v5;
    v6 = *(unsigned __int8**)(a2 + 8);
    v8 = *v6;
    *(_DWORD*)(a2 + 8) = v6 + 1;
    sub_40ACC0(v9, 1u, v8, a2);
    v9[v8] = 0;
    *(_DWORD*)(a1 + 44) = sub_44B4C0(v9);
    return 1;
}
// 44B8B0: using guessed type char var_100[256];

//----- (0044B940) --------------------------------------------------------
int __cdecl sub_44B940(_DWORD* a1, int a2, int a3)
{
    int v3; // esi
    int v4; // ebx
    void* v5; // eax
    int v6; // ebp
    int* v7; // eax
    int v8; // ebx
    char* v9; // eax
    char v10; // cl
    unsigned __int8* v11; // eax
    int v13; // [esp+10h] [ebp-90h]
    int v14; // [esp+14h] [ebp-8Ch]
    unsigned __int8 v15; // [esp+18h] [ebp-88h]
    const char* v16; // [esp+1Ch] [ebp-84h]
    char v17[128]; // [esp+20h] [ebp-80h]

    v3 = a2;
    v4 = 0;
    *a1 = 40;
    v14 = 0;
    while (1)
    {
        v13 = v4 >= 16 ? v4 + 4 : v4;
        v5 = nox_malloc(4 * v3);
        *(_DWORD*)((char*)a1 + v13 + 4) = v5;
        if (!v5)
            break;
        v6 = 0;
        if (v3 > 0)
        {
            do
            {
                v7 = *(int**)(a3 + 8);
                v8 = *v7;
                v9 = (char*)(v7 + 1);
                *(_DWORD*)(a3 + 8) = v9;
                v17[0] = byte_5D4594[830840];
                if (v8 == -1)
                {
                    v10 = *v9;
                    v11 = (unsigned __int8*)(v9 + 1);
                    *(_DWORD*)(a3 + 8) = v11;
                    v15 = *v11;
                    *(_DWORD*)(a3 + 8) = v11 + 1;
                    LOBYTE(v16) = v10;
                    sub_40ACC0(v17, 1u, v15, a3);
                    v17[v15] = 0;
                    v3 = a2;
                }
                *(_DWORD*)(*(_DWORD*)((char*)a1 + v13 + 4) + 4 * ++v6 - 4) = sub_42FAA0(v8, v16, v17);
            } while (v6 < v3);
            v4 = v14;
        }
        v4 += 4;
        v14 = v4;
        if (v4 >= 32)
            return 1;
    }
    return 0;
}
// 44BA0E: variable 'v16' is possibly undefined
// 44B940: using guessed type char var_80[128];

//----- (0044BA60) --------------------------------------------------------
int __cdecl sub_44BA60(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[113856];
    while (strcmp(*v2, a1))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[113960])
            return -1;
    }
    return v1;
}

//----- (0044BAC0) --------------------------------------------------------
int __cdecl sub_44BAC0(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[113964];
    while (strcmp(*v2, a1))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[114072])
            return -1;
    }
    return v1;
}

//----- (0044BB20) --------------------------------------------------------
int __cdecl sub_44BB20(const char* a1)
{
    int v1; // ebp
    const char** v2; // edi

    v1 = 0;
    v2 = (const char**)& byte_587000[115688];
    while (strcmp(a1, *v2))
    {
        ++v2;
        ++v1;
        if ((int)v2 >= (int)& byte_587000[115908])
            return -1;
    }
    return v1;
}

//----- (0044BB80) --------------------------------------------------------
int __cdecl sub_44BB80(int a1, int a2)
{
    _DWORD* v2; // ebx
    _DWORD* v3; // eax
    int v4; // ecx
    unsigned __int8* v5; // eax
    unsigned __int8 v6; // cl
    unsigned __int8* v7; // eax
    unsigned __int8* v8; // eax
    int v9; // edi

    v2 = nox_calloc(1u, 0x304u);
    *v2 = 772;
    while (1)
    {
        v3 = *(_DWORD * *)(a2 + 8);
        v4 = *v3;
        v5 = (unsigned __int8*)(v3 + 1);
        *(_DWORD*)(a2 + 8) = v5;
        if (v4 == 1162757152)
            break;
        v6 = *v5;
        v7 = v5 + 1;
        *(_DWORD*)(a2 + 8) = v7;
        if (v6 < 0x10u)
        {
            v8 = &v7[*v7 + 1];
            *(_DWORD*)(a2 + 8) = v8;
            *(_DWORD*)(a2 + 8) += *v8 + 1;
            v9 = (int)& v2[12 * v6 + 1];
            if (sub_44B8B0(v9, a2))
            {
                if (sub_44BC50(v9, a2))
                    continue;
            }
        }
        return 0;
    }
    *(_DWORD*)(a1 + 88) = nox_thing_monster_draw;
    *(_DWORD*)(a1 + 92) = v2;
    return 1;
}

//----- (0044BC50) --------------------------------------------------------
int __cdecl sub_44BC50(int a1, int a2)
{
    int v2; // ebp
    int v3; // esi
    void* v4; // eax
    int v5; // ebx
    int* v6; // eax
    int v7; // ebp
    _BYTE* v8; // eax
    char v9; // dl
    unsigned __int8* v10; // eax
    int v11; // esi
    int v13; // [esp+10h] [ebp-90h]
    int v14; // [esp+14h] [ebp-8Ch]
    const char* v15; // [esp+1Ch] [ebp-84h]
    char v16[128]; // [esp+20h] [ebp-80h]

    v2 = 0;
    v14 = 0;
    while (1)
    {
        v13 = v2 >= 16 ? v2 + 4 : v2;
        v3 = a1;
        v4 = nox_malloc(4 * *(__int16*)(a1 + 40));
        *(_DWORD*)(v13 + a1 + 4) = v4;
        if (!v4)
            break;
        v5 = 0;
        if (*(_WORD*)(a1 + 40) > 0)
        {
            do
            {
                v6 = *(int**)(a2 + 8);
                v7 = *v6;
                v8 = v6 + 1;
                *(_DWORD*)(a2 + 8) = v8;
                v16[0] = byte_5D4594[830844];
                if (v7 == -1)
                {
                    v9 = *v8;
                    v10 = v8 + 1;
                    *(_DWORD*)(a2 + 8) = v10;
                    LOBYTE(v15) = v9;
                    v11 = *v10;
                    *(_DWORD*)(a2 + 8) = v10 + 1;
                    sub_40ACC0(v16, 1u, v11, a2);
                    v16[v11] = 0;
                    v3 = a1;
                }
                *(_DWORD*)(*(_DWORD*)(v13 + v3 + 4) + 4 * ++v5 - 4) = sub_42FAA0(v7, v15, v16);
            } while (v5 < *(__int16*)(v3 + 40));
            v2 = v14;
        }
        v2 += 4;
        v14 = v2;
        if (v2 >= 32)
            return 1;
    }
    return 0;
}
// 44BD0C: variable 'v15' is possibly undefined
// 44BC50: using guessed type char var_80[128];

//----- (0044BD60) --------------------------------------------------------
int __cdecl sub_44BD60(int a1, int a2)
{
    int result; // eax

    result = sub_44BB80(a1, a2);
    *(_DWORD*)(a1 + 88) = nox_thing_maiden_draw;
    return result;
}

//----- (0044BD90) --------------------------------------------------------
int __cdecl sub_44BD90(_DWORD* a1, int a2)
{
    _DWORD* v2; // ebp
    int* v3; // eax
    int v4; // ecx
    _DWORD* v5; // eax
    int v6; // ecx
    unsigned __int8* v7; // eax
    unsigned __int8* v8; // eax
    int v9; // edi
    unsigned __int8 v11; // [esp+Ch] [ebp-4h]

    v2 = nox_calloc(1u, 0x94u);
    *v2 = 148;
    while (1)
    {
        v3 = *(int**)(a2 + 8);
        v4 = *v3;
        v5 = v3 + 1;
        *(_DWORD*)(a2 + 8) = v5;
        if (v4 == 1162757152)
            break;
        v6 = *v5;
        v7 = (unsigned __int8*)(v5 + 1);
        *(_DWORD*)(a2 + 8) = v7;
        if (v6 & 0xE)
        {
            v8 = &v7[*v7 + 1];
            *(_DWORD*)(a2 + 8) = v8;
            *(_DWORD*)(a2 + 8) += *v8 + 1;
            if (v6 & 2)
            {
                v11 = 0;
            }
            else if (v6 & 4)
            {
                v11 = 1;
            }
            else if (v6 & 8)
            {
                v11 = 2;
            }
            v9 = (int)& v2[12 * v11 + 1];
            if (sub_44B8B0(v9, a2))
            {
                if (sub_44BE90(v9, a2))
                    continue;
            }
        }
        return 0;
    }
    a1[21] = 2;
    a1[22] = nox_thing_animate_state_draw;
    a1[23] = v2;
    return 1;
}
// 44BE2F: variable 'v11' is possibly undefined

//----- (0044BE90) --------------------------------------------------------
int __cdecl sub_44BE90(int a1, int a2)
{
    int v2; // esi
    int result; // eax
    int v4; // ebx
    int* v5; // eax
    int v6; // ebp
    _BYTE* v7; // eax
    char v8; // dl
    unsigned __int8* v9; // eax
    int v10; // esi
    const char* v11; // [esp+4h] [ebp-88h]
    char v12[128]; // [esp+Ch] [ebp-80h]

    v2 = a1;
    result = (int)nox_malloc(4 * *(__int16*)(a1 + 40));
    *(_DWORD*)(a1 + 4) = result;
    if (result)
    {
        v4 = 0;
        if (*(_WORD*)(a1 + 40) > 0)
        {
            do
            {
                v5 = *(int**)(a2 + 8);
                v6 = *v5;
                v7 = v5 + 1;
                *(_DWORD*)(a2 + 8) = v7;
                v12[0] = byte_5D4594[830848];
                if (v6 == -1)
                {
                    v8 = *v7;
                    v9 = v7 + 1;
                    *(_DWORD*)(a2 + 8) = v9;
                    LOBYTE(v11) = v8;
                    v10 = *v9;
                    *(_DWORD*)(a2 + 8) = v9 + 1;
                    sub_40ACC0(v12, 1u, v10, a2);
                    v12[v10] = 0;
                    v2 = a1;
                }
                *(_DWORD*)(*(_DWORD*)(v2 + 4) + 4 * v4++) = sub_42FAA0(v6, v11, v12);
            } while (v4 < *(__int16*)(v2 + 40));
        }
        result = 1;
    }
    return result;
}
// 44BF33: variable 'v11' is possibly undefined
// 44BE90: using guessed type char var_80[128];

//----- (0044BF60) --------------------------------------------------------
int __cdecl sub_44BF60(int a1, int a2)
{
    _DWORD* v2; // eax
    _DWORD* v3; // esi
    int result; // eax

    v2 = nox_calloc(1u, 0x30u);
    v3 = v2;
    *v2 = 48;
    result = sub_44BFA0((int)v2, a2);
    if (result)
    {
        *(_DWORD*)(a1 + 88) = nox_thing_vector_animate_draw;
        *(_DWORD*)(a1 + 92) = v3;
        result = 1;
    }
    return result;
}

//----- (0044BFA0) --------------------------------------------------------
int __cdecl sub_44BFA0(int a1, int a2)
{
    int result; // eax

    result = sub_44B8B0(a1, a2);
    if (result)
        result = sub_44BC50(a1, a2);
    return result;
}

//----- (0044BFD0) --------------------------------------------------------
BOOL __cdecl sub_44BFD0(int a1, int a2, _BYTE* a3)
{
    void* v3; // eax

    *(_DWORD*)(a1 + 88) = nox_thing_static_random_draw;
    v3 = sub_44C000(a3, a2);
    *(_DWORD*)(a1 + 92) = v3;
    return v3 != 0;
}

//----- (0044C000) --------------------------------------------------------
void* __cdecl sub_44C000(_BYTE* a1, int a2)
{
    _DWORD* v2; // eax
    int v3; // esi
    _DWORD* v4; // ebp
    unsigned __int8* v5; // eax
    void* result; // eax
    int v7; // edi
    _BYTE* v8; // ebx
    int* v9; // eax
    int v10; // ecx
    char* v11; // eax
    char v12; // cl
    const char* v13; // [esp+Ch] [ebp-4h]
    unsigned __int8 v14; // [esp+14h] [ebp+4h]
    unsigned __int8 v15; // [esp+18h] [ebp+8h]
    int v16; // [esp+18h] [ebp+8h]

    v2 = nox_calloc(1u, 0xCu);
    v3 = a2;
    v4 = v2;
    *v2 = 12;
    v5 = *(unsigned __int8**)(a2 + 8);
    v15 = *v5;
    *(_DWORD*)(v3 + 8) = v5 + 1;
    *((_BYTE*)v4 + 8) = v15;
    result = nox_malloc(4 * v15);
    v4[1] = result;
    if (result)
    {
        v7 = 0;
        v16 = 0;
        if (*((_BYTE*)v4 + 8))
        {
            v8 = a1;
            do
            {
                v9 = *(int**)(v3 + 8);
                v10 = *v9;
                *(_DWORD*)(v3 + 8) = v9 + 1;
                *v8 = byte_5D4594[830852];
                if (v10 == -1)
                {
                    v11 = *(char**)(v3 + 8);
                    v12 = *v11++;
                    *(_DWORD*)(v3 + 8) = v11;
                    LOBYTE(v13) = v12;
                    v14 = *v11;
                    *(_DWORD*)(v3 + 8) = v11 + 1;
                    sub_40ACC0(v8, 1u, v14, v3);
                    v10 = -1;
                    v8[v14] = 0;
                    v7 = v16;
                }
                *(_DWORD*)(v4[1] + 4 * v7++) = sub_42FAA0(v10, v13, v8);
                v16 = v7;
            } while (v7 < *((unsigned __int8*)v4 + 8));
        }
        result = v4;
    }
    return result;
}
// 44C0BD: variable 'v13' is possibly undefined

//----- (0044C0F0) --------------------------------------------------------
BOOL __cdecl sub_44C0F0(int a1, int a2, _BYTE* a3)
{
    void* v3; // eax

    *(_DWORD*)(a1 + 88) = nox_thing_door_draw;
    v3 = sub_44C000(a3, a2);
    *(_DWORD*)(a1 + 92) = v3;
    return v3 != 0;
}

//----- (0044C120) --------------------------------------------------------
BOOL __cdecl sub_44C120(_DWORD* a1, int a2, _BYTE* a3)
{
    void* v3; // eax

    a1[22] = nox_thing_slave_draw;
    v3 = sub_44C000(a3, a2);
    a1[23] = v3;
    a1[24] = 0;
    return v3 != 0;
}

//----- (0044C160) --------------------------------------------------------
int __cdecl sub_44C160(int a1, int a2, char* a3)
{
    int result; // eax
    int v4; // ebp
    int v5; // eax
    char* v6; // edi
    int* v7; // ecx
    int v8; // ebx
    char* v9; // ecx
    char v10; // dl
    unsigned __int8 v11; // [esp+Ch] [ebp+8h]

    result = (int)nox_calloc(1u, 8u);
    v4 = result;
    *(_DWORD*)result = 8;
    if (result)
    {
        v5 = a2;
        v6 = a3;
        v7 = *(int**)(a2 + 8);
        v8 = *v7;
        *(_DWORD*)(a2 + 8) = v7 + 1;
        *a3 = byte_5D4594[830856];
        if (v8 == -1)
        {
            v9 = *(char**)(a2 + 8);
            v10 = *v9++;
            LOBYTE(a3) = v10;
            *(_DWORD*)(a2 + 8) = v9;
            v11 = *v9;
            *(_DWORD*)(v5 + 8) = v9 + 1;
            sub_40ACC0(v6, 1u, v11, v5);
            v6[v11] = 0;
        }
        *(_DWORD*)(v4 + 4) = sub_42FAA0(v8, a3, v6);
        *(_DWORD*)(a1 + 88) = nox_thing_static_draw;
        *(_DWORD*)(a1 + 92) = v4;
        result = 1;
    }
    return result;
}

//----- (0044C200) --------------------------------------------------------
int __cdecl nox_parse_thing_draw(nox_thing* obj, _DWORD* a2, int a3)
{
    unsigned __int8* v3; // eax
    unsigned __int8 v4; // cl
    int v5; // esi
    int result; // eax
    int v11; // [esp+10h] [ebp-104h]
    char v12[256]; // [esp+14h] [ebp-100h]

    v3 = (unsigned __int8*)a2[2];
    v4 = *v3;
    LOBYTE(v11) = v4;
    v5 = v4;
    a2[2] = v3 + 1;
    sub_40ACC0(v12, 1u, v4, (int)a2);
    v12[v5] = 0;
    sub_40AD60((char*)& v11, 4, 1, a2);

    if (!*(_DWORD*)table_116008)
    return 1;

    table_116008_t* item = NULL;
    for (int i=0; i < table_116008_cnt; i++) {
        table_116008_t* cur = &table_116008[i];
        if (!strcmp(cur->name, v12)) {
            item = cur;
            break;
        }
    }
    if (!item) {
        return 1;
    }
    result = 1;
    if (item->parse_fnc)
        result = item->parse_fnc(obj, a2, a3);
    obj->draw_func = item->draw;
    return result;
}
// 44C200: using guessed type char var_100[256];

//----- (0044C2F0) --------------------------------------------------------
int __cdecl nox_parse_thing_z(int a1, int a2, char* a3)
{
    sscanf(a3, "%d", &a3);
    *(_WORD*)(a1 + 22) = (_WORD)a3;
    return 1;
}

//----- (0044C320) --------------------------------------------------------
int __cdecl nox_parse_thing_zsize(int a1, int a2, char* a3)
{
    int v5; // [esp+0h] [ebp-4h]

    sscanf(a3, "%d %d", &v5, &a3);
    if ((int)a3 < (int)v5)
        a3 = v5;
    *(float*)(a1 + 68) = (double)(int)v5;
    *(float*)(a1 + 72) = (double)(int)a3;
    return 1;
}

//----- (0044C370) --------------------------------------------------------
int __cdecl nox_parse_thing_size(int a1, int a2, char* a3)
{
    int v5; // [esp+0h] [ebp-4h]

    sscanf(a3, "%d %d", &a3, &v5);
    *(_BYTE*)(a1 + 12) = (int)a3 / 2;
    *(_BYTE*)(a1 + 13) = v5 / 2;
    return 1;
}

//----- (0044C3B0) --------------------------------------------------------
int __cdecl nox_parse_thing_menu_icon(int a1, int a2)
{
    int* v2; // ecx
    int v3; // edx
    unsigned __int8* v4; // ecx

    v2 = *(int**)(a2 + 8);
    v3 = *v2;
    *(_DWORD*)(a2 + 8) = v2 + 1;
    *(_DWORD*)(a1 + 116) = v3;
    if (v3 == -1)
    {
        v4 = (unsigned __int8*)(*(_DWORD*)(a2 + 8) + 1);
        *(_DWORD*)(a2 + 8) = v4;
        *(_DWORD*)(a2 + 8) = &v4[*v4 + 1];
    }
    return 1;
}

//----- (0044C3F0) --------------------------------------------------------
int __cdecl nox_parse_thing_audio_loop(int a1, int a2, void* a3)
{
    *(_DWORD*)(a1 + 104) = sub_40AF50(a3);
    return 1;
}

//----- (0044C410) --------------------------------------------------------
int __cdecl nox_parse_thing_lifetime(int a1, int a2, char* a3)
{
    sscanf(a3, "%d", &a3);
    *(_DWORD*)(a1 + 120) = a3;
    return 1;
}

//----- (0044C440) --------------------------------------------------------
int __cdecl nox_parse_thing_weight(int a1, int a2, char* a3)
{
    int v3; // ecx

    sscanf(a3, "%d", &a3);
    v3 = *(_DWORD*)(a1 + 32);
    *(_BYTE*)(a1 + 14) = (_BYTE)a3;
    *(_DWORD*)(a1 + 32) = v3 | 0x80000000;
    return 1;
}

//----- (0044C480) --------------------------------------------------------
int __cdecl nox_parse_thing_pretty_name(int a1, int a2, char* a3)
{
    *(_DWORD*)(a1 + 4) = loadString_sub_40F1D0(a3, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1396);
    return 1;
}

//----- (0044C4B0) --------------------------------------------------------
int __cdecl nox_parse_thing_desc(int a1, int a2, char* a3)
{
    *(_DWORD*)(a1 + 8) = loadString_sub_40F1D0(a3, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1403);
    return 1;
}

//----- (0044C4E0) --------------------------------------------------------
int __cdecl nox_parse_thing_health(int a1, int a2, char* a3)
{
    *(_WORD*)(a1 + 124) = atoi(a3);
    return 1;
}

//----- (0044C500) --------------------------------------------------------
int __cdecl nox_parse_thing_pretty_image(int a1, int a2)
{
    int* v2; // ecx
    int v3; // esi
    char* v4; // ecx
    char v5; // dl
    unsigned __int8* v6; // ecx
    const char* v8; // [esp+4h] [ebp-88h]
    unsigned __int8 v9; // [esp+8h] [ebp-84h]
    char v10[128]; // [esp+Ch] [ebp-80h]

    v2 = *(int**)(a2 + 8);
    v3 = *v2;
    v4 = (char*)(v2 + 1);
    *(_DWORD*)(a2 + 8) = v4;
    if (v3 == -1)
    {
        v5 = *v4;
        v6 = (unsigned __int8*)(v4 + 1);
        LOBYTE(v8) = v5;
        *(_DWORD*)(a2 + 8) = v6;
        v9 = *v6;
        *(_DWORD*)(a2 + 8) = v6 + 1;
        sub_40ACC0(v10, 1u, v9, a2);
    }
    *(_DWORD*)(a1 + 112) = sub_42FAA0(v3, v8, v10);
    return 1;
}
// 44C554: variable 'v8' is possibly undefined

//----- (0044C580) --------------------------------------------------------
void sub_44C580_free()
{
    if (nox_things_head) {
        nox_thing* cur = nox_things_head;
        while(cur) {
            if (cur->name)
                free(cur->name);
            if (cur->field_5c)
                sub_44C650_free(cur->field_5c, cur->draw_func);
            nox_thing* next = cur->next;
            free(cur);
            cur = next;
        }
    }
    nox_things_head = NULL;
    if (nox_things_array)
    {
        free(nox_things_array);
        nox_things_array = NULL;
    }
    nox_things_count = 0;
    sub_44C620();
    if (!sub_40A5C0(1))
        sub_42BF80();
}

//----- (0044C620) --------------------------------------------------------
void sub_44C620()
{
    LPVOID* v0; // esi

    v0 = (LPVOID*)& byte_5D4594[830296];
    do
    {
        if (*v0)
            free(*v0);
        *v0 = 0;
        ++v0;
    } while ((int)v0 < (int)& byte_5D4594[830404]);
}

//----- (0044C650) --------------------------------------------------------
void __cdecl sub_44C650_free(LPVOID lpMem, void* draw)
{
    int kind = 0;
    if (*(_DWORD*)table_116008)
    {
        table_116008_t* item = NULL;
        for (int i = 0; i < table_116008_cnt; i++) {
            table_116008_t* cur = &table_116008[i];
            if (!cur->name)
                break;
            if (cur->draw == draw) {
                item = cur;
                break;
            }
        }
        if (item) {
            kind = item->kind;
        }
    }
    LPVOID* v7 = 0;
    int v8 = 0;
    char* v9 = 0;
    int v10 = 0;
    char* v11 = 0;
    int v12 = 0;

    switch (kind) {
        case 2:
        case 3:
            if (*((_DWORD*)lpMem + 1)) {
        free(*((LPVOID*)lpMem + 1));
    }
            free(lpMem);
            break;
        case 4:
            v7 = (LPVOID*)((char*)lpMem + 4);
            v8 = 5;
            do {
                if (*v7)
                    free(*v7);
                ++v7;
                --v8;
            } while (v8);
            free(lpMem);
            break;
        case 5:
            sub_44C780((int)lpMem + 4);
            free(lpMem);
            break;
        case 6:
            sub_44C7B0((int)lpMem);
            free(lpMem);
            break;
        case 7:
            v9 = (char*)lpMem + 8;
            v10 = 16;
            do {
                sub_44C780((int)v9);
                v9 += 48;
                --v10;
            } while (v10);
            free(lpMem);
            break;
        case 8:
            v11 = (char*)lpMem + 8;
            v12 = 3;
            do {
                sub_44C780((int)v11);
                v11 += 48;
                --v12;
            } while (v12);
            free(lpMem);
            break;
        default:
            free(lpMem);
            break;
    }
}

//----- (0044C780) --------------------------------------------------------
void* __cdecl sub_44C780(int a1)
{
    int i; // esi
    int v2; // eax
    void* result; // eax

    for (i = 0; i < 32; i += 4)
    {
        v2 = i;
        if (i >= 16)
            v2 = i + 4;
        result = *(void**)(v2 + a1);
        if (result)
            free(result);
    }
    return result;
}

//----- (0044C7B0) --------------------------------------------------------
LPVOID __cdecl sub_44C7B0(int a1)
{
    LPVOID* v1; // ebx
    int v2; // ebp
    LPVOID* v3; // esi
    int v4; // edi
    LPVOID* v5; // esi
    int v6; // edi
    LPVOID result; // eax

    v1 = (LPVOID*)(a1 + 52);
    v2 = 55;
    do
    {
        if (*v1)
        {
            sub_44C780((int)* v1 + 4);
            free(*v1);
        }
        v3 = v1 + 1;
        v4 = 26;
        do
        {
            if (*v3)
            {
                sub_44C780((int)* v3 + 4);
                free(*v3);
            }
            ++v3;
            --v4;
        } while (v4);
        v5 = v1 + 27;
        v6 = 27;
        do
        {
            result = *v5;
            if (*v5)
            {
                sub_44C780((int)result + 4);
                free(*v5);
            }
            ++v5;
            --v6;
        } while (v6);
        v1 += 66;
        --v2;
    } while (v2);
    return result;
}

//----- (0044C840) --------------------------------------------------------
void* __cdecl sub_44C840(char* a1)
{
    char* v1; // ebx
    size_t* v2; // edi
    unsigned __int8* v5; // eax
    int v6; // eax
    CHAR* v9; // esi
    unsigned int v10; // edx
    unsigned __int8* v11; // edi
    unsigned __int8* v12; // edi
    CHAR* v13; // esi
    char v14; // cl
    unsigned __int8* v15; // edi
    int v16; // ecx
    unsigned __int8 v17; // al
    CHAR* v18; // esi
    unsigned int v19; // edx
    unsigned __int8* v20; // edi
    unsigned __int8* v21; // edi
    CHAR* v22; // esi
    char v23; // cl
    int v24; // edx
    unsigned __int8* v25; // edi
    int v26; // ecx
    int i; // [esp+10h] [ebp-4h]
    unsigned __int8 v28; // [esp+18h] [ebp+4h]

    v1 = (char*)nox_malloc(0x40000u);
    sub_44CCA0();
    sub_44C580_free();
    nox_things_count = 1;
    sub_485CF0();
    sub_485F30();
    sub_46A360();
    v2 = *(size_t * *)& byte_5D4594[260];
    if (!*(_DWORD*)& byte_5D4594[260])
    {
        v2 = sub_40ABF0(a1, 7);
        if (!v2)
            return 0;
    }
    sub_40AD10(v2, 0, 0);
    while (sub_40ACC0(&i, 4u, 1, (int)v2))
    {
        switch (i)
        {
            case 0x5350454C: // "SPEL"
                sub_415100((int)v2);
                break;
            case 0x4142494C: // "ABIL"
                sub_415320((int)v2);
                break;
            case 0x41554420: // "AUD "
                sub_414D40((int)v2);
                break;
            case 0x41564E54: // "AVNT"
                sub_452B00((int)v2);
                break;
            case 0x57414C4C: // "WALL"
                if (!sub_46A010(v2, v1))
                    return 0;
                break;
            case 0x464C4F52: // "FLOR"
                if (!sub_485B30((int)v2, v1))
                    return 0;
                break;
            case 0x45444745: // "EDGE"
                if (!sub_485D40((int)v2, v1))
                    return 0;
                break;
            case 0x494D4147: // "IMAG"
                sub_415240((int)v2);
                break;
            case 0x54484E47: // "THNG"
                ;
                nox_thing* obj = (nox_thing*)nox_calloc(1, sizeof(nox_thing));
                if (!obj)
                    return 0;
                v5 = (unsigned __int8*)v2[2];
                v28 = *v5;
                v2[2] = (size_t)(v5 + 1);
                sub_40ACC0(v1, 1u, v28, (int)v2);
                v1[v28] = 0;
                obj->name = nox_clone_str(v1);
                obj->field_74 = -1;
                obj->field_1c = nox_things_count++;
                obj->flags |= 0x1000000;
                *((_BYTE*)obj + 15) = 0;
                obj->field_10 = 0xFFFF;
                obj->field_68 = 0;
                obj->draw_func = nox_thing_debug_draw;
                obj->field_44 = 0;
                obj->field_48 = 0x41F00000;
                if (!nox_parse_thing((int)v2, v1, obj))
                    return 0;
                obj->next = nox_things_head;
                nox_things_head = obj;
                sub_44CD10(obj->name);
                break;
        }
    }
    *(_DWORD*)& byte_5D4594[2649708] = 1;
    if (*(_DWORD*)& byte_5D4594[260])
    {
        if (sub_40A5C0(1) && *(_DWORD*)& byte_5D4594[2650664])
        {
            sub_40ACA0_free_ptr2(*(LPVOID*)& byte_5D4594[260]);
            *(_DWORD*)& byte_5D4594[260] = 0;
        }
    }
    else
    {
        sub_40ACA0_free_ptr2(v2);
    }
    void* result = nox_malloc(4 * nox_things_count);
    nox_things_array = result;
    if (result)
    {
        sub_44CCD0();
        v6 = nox_things_count;
        nox_thing* cur = nox_things_head;
        for (int i = 1; i < nox_things_count; i++)
        {
            nox_things_array[v6 - i] = cur;
            sub_44CD60(cur, nox_things_count - i);
            if (*((_BYTE*)cur + 0xe))
            {
                if (!cur->field_4)
                {
                    strcpy((char*)& byte_5D4594[830404], "thing.db:");
                    v9 = cur->name;
                    v10 = strlen(cur->name) + 1;
                    v11 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830404];
                    qmemcpy(v11, cur->name, 4 * (v10 >> 2));
                    v13 = &v9[4 * (v10 >> 2)];
                    v12 = &v11[4 * (v10 >> 2)];
                    v14 = v10;
                    LOWORD(v10) = *(_WORD*)& byte_587000[122728];
                    qmemcpy(v12, v13, v14 & 3);
                    v15 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830405];
                    v16 = *(_DWORD*)& byte_587000[122724];
                    *(_DWORD*)--v15 = *(_DWORD*)& byte_587000[122720];
                    v17 = byte_587000[122730];
                    *((_DWORD*)v15 + 1) = v16;
                    *((_WORD*)v15 + 4) = v10;
                    v15[10] = v17;
                    cur->field_4 = loadString_sub_40F1D0((char*)& byte_5D4594[830404], 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1926);
                }
                if (!cur->field_8)
                {
                    strcpy((char*)& byte_5D4594[830404], "thing.db:");
                    v18 = cur->name;
                    v19 = strlen(cur->name) + 1;
                    v20 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830404];
                    qmemcpy(v20, cur->name, 4 * (v19 >> 2));
                    v22 = &v18[4 * (v19 >> 2)];
                    v21 = &v20[4 * (v19 >> 2)];
                    v23 = v19;
                    v24 = *(_DWORD*)& byte_587000[122792];
                    qmemcpy(v21, v22, v23 & 3);
                    v25 = &byte_5D4594[strlen((const char*)& byte_5D4594[830404]) + 830405];
                    v26 = *(_DWORD*)& byte_587000[122788];
                    *(_DWORD*)--v25 = *(_DWORD*)& byte_587000[122784];
                    *((_DWORD*)v25 + 1) = v26;
                    *((_DWORD*)v25 + 2) = v24;
                    cur->field_8 = loadString_sub_40F1D0((char*)& byte_5D4594[830404], 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1933);
                }
            }
            v6 = nox_things_count;
            cur = cur->next;
        }
        sub_44CDB0();
        free(v1);
        sub_4131A0();
        sub_415AB0();
        sub_4157C0();
        result = (void*)(sub_42BF10() != 0);
    }
    return result;
}
