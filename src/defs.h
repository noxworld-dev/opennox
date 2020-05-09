#ifndef NOX_DEFS_H
#define NOX_DEFS_H

#define DIRECTINPUT_VERSION 0x0700
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <wctype.h>

#define NO_IMM 1
#define NO_MOVIE 1
#define NO_WOLAPI 1

#define USE_SDL 1
#include <SDL2/SDL.h>

#include "platform.h"

#ifdef __EMSCRIPTEN__
#define wchar_t int16_t
#endif

#ifdef _WIN32
typedef intptr_t INT_PTR;
typedef INT_PTR LSTATUS;

#include <windows.h>
#include <mmreg.h>
#else
#pragma GCC poison fgetwln fgetws fputwc fputws fwprintf fwscanf mbrtowc mbsnrtowcs mbsrtowcs putwc putwchar swprintf swscanf vfwprintf vfwscanf vswprintf vswscanf vwprintf vwscanf wcrtomb wcscat wcschr wcscmp wcscoll wcscpy wcscspn wcsftime wcsftime wcslcat wcslcpy wcslen wcsncat wcsncmp wcsncpy wcsnrtombs wcspbrk wcsrchr wcsrtombs wcsspn wcsstr wcstod wcstof wcstok wcstol wcstold wcstoll wcstoul wcstoull wcswidth wcsxfrm wcwidth wmemchr wmemcmp wmemcpy wmemmove wmemset wprintf wscanf
#include "windows.h"
#endif
#include "compat_mss.h"
#include "noxstring.h"

typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned __int64 _QWORD;
typedef int bool;

#if !defined(__MMINTRIN_H) && !defined(_MMINTRIN_H_INCLUDED)
typedef struct __m64 __m64;
#endif

#undef LOBYTE
#undef HIBYTE
#define LOBYTE(x) (((_BYTE*)(&x))[0])
#define SLOBYTE(x) (((signed char*)(&x))[0])
#define BYTE1(x) (((_BYTE*)(&x))[1])
#define SBYTE1(x) (((signed char*)(&x))[1])
#define BYTE2(x) (((_BYTE*)(&x))[2])
#define HIBYTE(x) (((_BYTE*)(&x))[sizeof(x)-1])
#define BYTE4(x) (((_BYTE*)(&x))[4])

#undef LOWORD
#undef HIWORD
#define LOWORD(x) (((_WORD*)(&x))[0])
#define SLOWORD(x) (((short*)(&x))[0])
#define HIWORD(x) (((_WORD*)(&x))[1])
#define SHIWORD(x) (((short*)(&x))[1])
#define WORD2(x) (((_WORD*)(&x))[2])
#define SWORD2(x) (((short*)(&x))[2])

#undef LODWORD
#undef HIDWORD
#define LODWORD(x) (((_DWORD*)(&x))[0])
#define SLODWORD(x) (((int*)(&x))[0])
#define HIDWORD(x) (((_DWORD*)(&x))[1])
#define SHIDWORD(x) (((int*)(&x))[1])

#define __PAIR64__(x,y) ((((_QWORD)(x)) << 32) | ((_DWORD)(y)))
#define __SPAIR64__(x,y) ((__int64)((((_QWORD)(x)) << 32) | ((_DWORD)(y))))

//#define DEBUG_MALLOCS

#ifdef DEBUG_MALLOCS
#define nox_malloc(x) nox_malloc2(x, __func__, __LINE__, __FILE__)
#define nox_calloc(x,y) nox_malloc2((x)*(y), __func__, __LINE__, __FILE__)
void* nox_malloc2(size_t x, char* func, int line, char* file);
#else
#define nox_malloc(x) malloc(x)
#define nox_calloc(x,y) calloc(x, y)
#endif

void nox_exit(int exitCode);


static int __OFSUB__(int x, int y)
{
    DebugBreak();
    return 0;
}
static int __CFSHR__(int x, int y)
{
    DebugBreak();
    return 0;
}
static int __CFSHL__(int x, int y)
{
    DebugBreak();
    return 0;
}
static int __CFADD__(int x, int y)
{
    DebugBreak();
    return 0;
}
static int __OFADD__(int x, int y)
{
    DebugBreak();
    return 0;
}

// saturating 8-bit addition
static _BYTE SADD8(_BYTE x, _BYTE y)
{
    unsigned int z = x + y;
    return z > 0xFF ? 0xFF : (_BYTE)z;
}

#define abs32 abs
#define qmemcpy memcpy

static void memset32(_DWORD* x, _DWORD y, size_t z)
{
    while (z--)* x++ = y;
}

#define __ROL4__ _rotl

#if !defined(__clang__) && !defined(_MSC_VER)
static _QWORD __rdtsc()
{
#ifdef __GNUC__
    unsigned int low, high;
    asm("rdtsc" : "=a" (low), "=d" (high));
    return ((_QWORD)high << 32) | low;
#else
    _asm rdtsc;
#endif
}
#endif

typedef struct std___Lockit
{
    _DWORD x;
} std___Lockit;

static void std___Lockit___Lockit(struct std___Lockit* l)
{
    return;
}

static void std___Lockit__destructor_Lockit(struct std___Lockit* l)
{
    return;
}

static void std___Xran()
{
    DebugBreak();
}

static void std___Xlen()
{
    DebugBreak();
}

static void* operator_new(size_t x)
{
    return nox_malloc(x);
}

static void operator_delete(void* x)
{
    free(x);
}

static _WORD __ROL2__(_WORD x, int shift)
{
    if (shift == 0) return x;
    if (shift == 16) return x;
    return (_WORD)((x << shift) | (x >> (16 - shift)));
}

static float COERCE_FLOAT(_DWORD x)
{
    return *(float*)& x;
}

static _DWORD COERCE_INT(float x)
{
    return *(_DWORD*)& x;
}

typedef struct struc_13
{
    char field_0[80];
    int field_50;
} struc_13;

/* 288 */
typedef struct struc_14
{
    char field_0[4828];
} struc_14;

/* 289 */
typedef struct struc_15
{
    char field_0[80];
} struc_15;

/* 290 */
typedef struct struc_16
{
    char field_0[24];
} struc_16;

/* 291 */
typedef struct struc_17
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
} struc_17;

/* 292 */
typedef struct struc_18
{
    char field_0[2048];
    int field_800;
} struc_18;

/* 293 */
typedef struct struc_19
{
    int field_0[35];
} struc_19;

/* 294 */
typedef struct struc_20
{
    char field_0[80];
} struc_20;

/* 295 */
typedef struct struc_21
{
    char field_0[28];
} struc_21;

/* 296 */
typedef struct struc_22
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
} struc_22;

/* 297 */
typedef struct struc_23
{
    char field_0[200];
} struc_23;

/* 298 */
typedef struct struc_24
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
} struc_24;

/* 299 */
typedef struct struc_25
{
    char field_0[12332];
} struc_25;

/* 300 */
typedef struct pixel888
{
    char field_0;
    char field_1;
    char field_2;
} pixel888;

/* 301 */
typedef struct pixel8888
{
    char field_0;
    char field_1;
    char field_2;
    char field_3;
} pixel8888;

/* 302 */
typedef struct float2
{
    float field_0;
    float field_4;
} float2;

/* 303 */
typedef struct float4
{
    float field_0;
    float field_4;
    float field_8;
    float field_C;
} float4;

/* 306 */
typedef struct int2
{
    int field_0;
    int field_4;
} int2;

/* 307 */
typedef struct int4
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
} int4;

/* 308 */
typedef struct nox_shape
{
    int field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
} nox_shape;

typedef struct string
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
} string;

/* 310 */
typedef struct wstring
{
    int _A;
    int _Ptr;
    int _Len;
    int _Rem;
} wstring;

typedef struct struc_35
{
    HWND field_0;
    HIMC field_4;
    int field_8;
    int field_C;
    int field_10;
} struc_35;

typedef struct struc_36
{
    _DWORD fields[5];
    void (*field_5)(void);
    _DWORD field_6;
} struc_36;

typedef struct nox_missing_string nox_missing_string;
typedef struct nox_missing_string
{
    nox_missing_string* next;
    wchar_t data[258];
} nox_missing_string;

typedef struct nox_string_entry
{
    char data[50];
    _WORD field_50;
} nox_string_entry;

typedef struct nox_alloc_hdr nox_alloc_hdr;
typedef struct nox_alloc_hdr
{
    int field_0;
    int field_1;
    nox_alloc_hdr* field_2;
    int field_3;
} nox_alloc_hdr;

typedef struct nox_alloc_class
{
    char name[88];  // 0, 0, 0
    int size; // 22, 0x58, 88
    int cnt1; // 23
    nox_alloc_hdr* field_24; // 24
    nox_alloc_hdr* field_25; // 25
    _DWORD field_26; // 26
    _DWORD field_27; // 27
    _DWORD field_28; // 28
    void* items; // 29
    _DWORD field_30; // 30
    _DWORD field_31; // 31
    _DWORD field_32; // 32
    _DWORD field_33; // 33
    _DWORD field_34; // 34
    _DWORD field_35; // 35
    int cnt2; // 36
    _DWORD field_37; // 37
} nox_alloc_class;

typedef struct nox_thing nox_thing;
typedef struct nox_thing
{
    char* name; // 0, 0x0
    wchar_t* field_4; // 1, 0x4
    wchar_t* field_8; // 2, 0x8
    _DWORD field_c; // 3, 0xc
    _DWORD field_10; // 4, 0x10
    _DWORD field_14; // 5, 0x14
    _DWORD field_18; // 6, 0x18
    _DWORD field_1c; // 7, 0x1c
    int pri_class; // 8, 0x20, 32
    _DWORD sub_class; // 9, 0x24, 36
    int flags; // 10, 0x28, 40
    _DWORD field_2c; // 11, 0x2c, 44
    _DWORD field_30; // 12, 0x30
    _DWORD field_34; // 13, 0x34
    _DWORD field_38; // 14, 0x38
    _DWORD field_3c; // 15, 0x3c
    float field_40; // 16, 0x40
    _DWORD field_44; // 17, 0x44
    _DWORD field_48; // 18, 0x48
    _DWORD field_4c; // 19, 0x4c
    _DWORD field_50; // 20, 0x50
    _DWORD field_54; // 21, 0x54
    void* draw_func; // 22, 0x58
    void* field_5c; // 23, 0x5c
    _DWORD field_60; // 24, 0x60
    _DWORD field_64; // 25, 0x64
    _DWORD field_68; // 26, 0x68
    nox_thing* next; // 27, 0x6c, 108
    _DWORD field_70; // 28, 0x70, 112
    _DWORD field_74; // 29, 0x74
    _DWORD field_78; // 30, 0x78, 120
    _DWORD field_7c; // 31, 0x7c
} nox_thing;

typedef enum {
    NOX_WIN_HIDDEN = 0x10,
    NOX_WIN_LAYER_FRONT = 0x20,
    NOX_WIN_LAYER_BACK = 0x40
} nox_window_flags;

typedef struct nox_window nox_window;
typedef struct nox_window
{
    _DWORD field_0;
    nox_window_flags flags; // 1
    int width; // 2
    int height; // 3
    _DWORD field_4;
    _DWORD field_5;
    _DWORD field_6;
    _DWORD field_7;
    _DWORD field_8;
    _DWORD field_9[83];
    _DWORD field_92; // 92
    int (*field_93)(int, int, int, int); // 93
    int (*field_94)(int, int, int, int); // 94
    int (*draw)(nox_window*, void*); // 95, second arg is &field_9
    int (*field_96)(void*); // 96
    nox_window* field_97; // 97, 388
    nox_window* field_98; // 98, 392
    nox_window* field_99; // 99
    nox_window* field_100; // 100
} nox_window;

typedef struct obj_412ae0_t obj_412ae0_t;
typedef struct obj_412ae0_t
{
    char* field_0;
    _DWORD field_1;
    wchar_t* field_2;
    wchar_t* field_3;
    wchar_t* field_4;
    int field_5;
    _DWORD field_6;
    int field_7;
    int field_8;
    _DWORD field_9;
    void* field_10;
    float field_11;
    int   field_12;
    void* field_13;
    float field_14;
    int   field_15;
    void* field_16;
    float field_17;
    int   field_18;
    void* field_19;
    float field_20;
    int   field_21;
    void* field_22;
    float field_23;
    int   field_24;
    void* field_25;
    float field_26;
    int   field_27;
    void* field_28;
    void* field_29;
    float field_30;
    int   field_31;
    float field_32;
    int   field_33;
    obj_412ae0_t* field_34;
    obj_412ae0_t* field_35;
} obj_412ae0_t;

typedef struct table_26792_t
{
    const char* name;
    void* fnc;
    int(__cdecl *parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_26792_t;

typedef struct table_27008_t
{
    const char* name;
    void* fnc;
    int(__cdecl *parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27008_t;

typedef struct table_27104_t
{
    const char* name;
    void* fnc;
    int(__cdecl *parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27104_t;

typedef struct table_27168_t
{
    const char* name;
    void* fnc;
    int(__cdecl *parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27168_t;

typedef struct table_28760_t
{
    const char* name;
    int(__cdecl *parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_28760_t;

typedef struct table_116008_t
{
    const char* name;
    void* draw;
    unsigned int kind;
    int(__cdecl *parse_fnc)(void*, _DWORD*, int);
} table_116008_t;

typedef struct nox_parse_thing_funcs_t
{
    const char* name;
    void(__cdecl *parse_func)(nox_thing*, int, char*);
} nox_parse_thing_funcs_t;

typedef struct nox_video_mode
{
    int width;
    int height;
    int id;
} nox_video_mode;

typedef struct mouse_pos_t
{
    int x;
    int y;
} mouse_pos_t;

typedef struct nox_mouse_state_t
{
    mouse_pos_t pos;
    int z;

    _DWORD field_3;
    _DWORD field_4;

    _DWORD left_state;
    _DWORD field_6;
    _DWORD left_seq;

    _DWORD right_state;
    _DWORD field_9;
    _DWORD right_seq;

    _DWORD middle_state;
    _DWORD field_12;
    _DWORD middle_seq;
} nox_mouse_state_t;

typedef struct obj_5D4594_3799572_t
{
    _DWORD data[264];
} obj_5D4594_3799572_t;

typedef struct {
    void (*fnc)(int);
    int field_4;
    char name[12];
} obj_5D4594_754088_t;

typedef struct{
    bool live;
    BYTE pad[3];
    int id;
    _DWORD data8[327];
} nox_npc;

#endif
