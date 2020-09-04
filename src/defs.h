#ifndef NOX_DEFS_H
#define NOX_DEFS_H

#define DIRECTINPUT_VERSION 0x0700
#include "memfile.h"
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <wctype.h>

#define NO_IMM 1
#define NO_MOVIE 1
#define NO_WOLAPI 1

#define NOX_DEFAULT_WIDTH 640
#define NOX_DEFAULT_HEIGHT 480
#define NOX_DEFAULT_DEPTH 16
#define NOX_MAX_WIDTH 1024
#define NOX_MAX_HEIGHT 768

#define NOX_FILEPATH_MAX 1024

#define USE_SDL 1
#include <SDL2/SDL.h>

#include "platform.h"

#ifdef __EMSCRIPTEN__
#define wchar_t int16_t
#endif

#ifdef _WIN32
// Windows specific headers
// Already defined in winreg.h
/*
typedef intptr_t INT_PTR;
typedef INT_PTR LSTATUS;
*/

#include <windows.h>
//#include <mmreg.h>

#ifndef _Static_assert
#define _Static_assert static_assert
#endif
#else
// Non-windows platform headers
#pragma GCC poison fgetwln fgetws fputwc fputws fwprintf fwscanf mbrtowc mbsnrtowcs mbsrtowcs putwc putwchar swprintf  \
	swscanf vfwprintf vfwscanf vswprintf vswscanf vwprintf vwscanf wcrtomb wcscat wcschr wcscmp wcscoll wcscpy wcscspn \
		wcsftime wcsftime wcslcat wcslcpy wcslen wcsncat wcsncmp wcsncpy wcsnrtombs wcspbrk wcsrchr wcsrtombs wcsspn   \
			wcsstr wcstod wcstof wcstok wcstol wcstold wcstoll wcstoul wcstoull wcswidth wcsxfrm wcwidth wmemchr       \
				wmemcmp wmemcpy wmemmove wmemset wprintf wscanf
#include "windows.h"
#endif
#include "compat_mss.h"
#include "noxstring.h"
#include <stdbool.h>

// For now bools are kept 1-byte long
//_Static_assert(sizeof(bool) == 4, "boolean values must be aligned to 32-bit int");

typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned __int64 _QWORD;

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
#define HIBYTE(x) (((_BYTE*)(&x))[sizeof(x) - 1])
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

#define __PAIR64__(x, y) ((((_QWORD)(x)) << 32) | ((_DWORD)(y)))
#define __SPAIR64__(x, y) ((__int64)((((_QWORD)(x)) << 32) | ((_DWORD)(y))))

#ifdef NOX_LOG_MEM

#define memset(x, y, z) nox_memset(__func__, x, y, z)
void nox_memset(const char* fnc, void* ptr, int v, int sz);

#define memcpy(x, y, z) nox_memcpy(__func__, x, y, z)
void nox_memcpy(const char* fnc, void* dst, void* src, int sz);

#define strlen(x) nox_strlen(__func__, x)
int nox_strlen(const char* fnc, const char* src);

#define strcpy(x, y) nox_strcpy(__func__, x, y)
int nox_strcpy(const char* fnc, char* dst, const char* src);

#endif // NOX_LOG_MEM

void nox_exit(int exitCode);

static int __OFSUB__(int x, int y) {
	DebugBreak();
	return 0;
}
static int __CFSHR__(int x, int y) {
	DebugBreak();
	return 0;
}
static int __CFSHL__(int x, int y) {
	DebugBreak();
	return 0;
}
static int __CFADD__(int x, int y) {
	DebugBreak();
	return 0;
}
static int __OFADD__(int x, int y) {
	DebugBreak();
	return 0;
}

// saturating 8-bit addition
static _BYTE SADD8(_BYTE x, _BYTE y) {
	unsigned int z = x + y;
	return z > 0xFF ? 0xFF : (_BYTE)z;
}

#define abs32 abs

static void memset32(_DWORD* x, _DWORD y, size_t z) {
	while (z--)
		*x++ = y;
}

#define __ROL4__ _rotl

#if !defined(__clang__) && !defined(_MSC_VER)
static _QWORD __rdtsc() {
#ifdef __GNUC__
	unsigned int low, high;
	asm("rdtsc" : "=a"(low), "=d"(high));
	return ((_QWORD)high << 32) | low;
#else
	_asm rdtsc;
#endif
}
#endif

typedef struct std___Lockit {
	_DWORD x;
} std___Lockit;

static void std___Lockit___Lockit(struct std___Lockit* l) { return; }

static void std___Lockit__destructor_Lockit(struct std___Lockit* l) { return; }

static void std___Xran() { DebugBreak(); }

static void std___Xlen() { DebugBreak(); }

static void* operator_new(size_t x) { return malloc(x); }

static void operator_delete(void* x) { free(x); }

static _WORD __ROL2__(_WORD x, int shift) {
	if (shift == 0)
		return x;
	if (shift == 16)
		return x;
	return (_WORD)((x << shift) | (x >> (16 - shift)));
}

static float COERCE_FLOAT(_DWORD x) { return *(float*)&x; }

static _DWORD COERCE_INT(float x) { return *(_DWORD*)&x; }

typedef struct struc_13 {
	char field_0[80];
	int field_50;
} struc_13;

/* 288 */
typedef struct struc_14 {
	char field_0[4828];
} struc_14;

/* 289 */
typedef struct struc_15 {
	char field_0[80];
} struc_15;

/* 290 */
typedef struct struc_16 {
	char field_0[24];
} struc_16;

/* 291 */
typedef struct struc_17 {
	int field_0;
	int field_4;
	int field_8;
	int field_C;
} struc_17;

/* 292 */
typedef struct struc_18 {
	char field_0[2048];
	int field_800;
} struc_18;

/* 293 */
typedef struct struc_19 {
	int field_0[35];
} struc_19;

/* 294 */
typedef struct struc_20 {
	char field_0[80];
} struc_20;

/* 295 */
typedef struct struc_21 {
	char field_0[28];
} struc_21;

/* 296 */
typedef struct struc_22 {
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
} struc_22;

/* 297 */
typedef struct struc_23 {
	char field_0[200];
} struc_23;

/* 298 */
typedef struct struc_24 {
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
} struc_24;

/* 299 */
typedef struct struc_25 {
	char field_0[12332];
} struc_25;

/* 300 */
typedef struct pixel888 {
	char field_0;
	char field_1;
	char field_2;
} pixel888;

/* 301 */
typedef struct pixel8888 {
	char field_0;
	char field_1;
	char field_2;
	char field_3;
} pixel8888;

/* 302 */
typedef struct float2 {
	float field_0;
	float field_4;
} float2;

/* 303 */
typedef struct float4 {
	float field_0;
	float field_4;
	float field_8;
	float field_C;
} float4;

/* 306 */
typedef struct int2 {
	int field_0;
	int field_4;
} int2;

/* 307 */
typedef struct int4 {
	int field_0;
	int field_4;
	int field_8;
	int field_C;
} int4;

typedef enum { NOX_SHAPE_NONE = 0, NOX_SHAPE_CENTER = 1, NOX_SHAPE_CIRCLE = 2, NOX_SHAPE_BOX = 3 } nox_shape_kind;

typedef struct nox_shape {
	nox_shape_kind kind;      // 0x0
	float circle_r;           // 0x4
	float circle_r2;          // 0x8
	float box_w;              // 0xC
	float box_h;              // 0x10
	float box_left_top;       // 0x14
	float box_left_bottom;    // 0x18
	float box_left_bottom_2;  // 0x1C
	float box_left_top_2;     // 0x20
	float box_right_top;      // 0x24
	float box_right_bottom;   // 0x28
	float box_right_bottom_2; // 0x2C
	float box_right_top_2;    // 0x30
} nox_shape;
_Static_assert(sizeof(nox_shape) == 52, "wrong size of nox_shape structure!");

typedef struct string {
	int field_0;
	int field_4;
	int field_8;
	int field_C;
} string;

/* 310 */
typedef struct wstring {
	int _A;
	int _Ptr;
	int _Len;
	int _Rem;
} wstring;

typedef struct struc_35 {
	HWND field_0;
	HIMC field_4;
	int field_8;
	int field_C;
	int field_10;
} struc_35;

typedef struct struc_36 {
	_DWORD fields[5];
	void (*field_5)(void);
	_DWORD field_6;
} struc_36;

typedef struct nox_missing_string nox_missing_string;
typedef struct nox_missing_string {
	nox_missing_string* next;
	wchar_t data[258];
} nox_missing_string;

typedef struct nox_string_entry {
	char data[50];
	_WORD field_50;
} nox_string_entry;

typedef struct nox_alloc_hdr nox_alloc_hdr;
typedef struct nox_alloc_hdr {
	int field_0;
	int field_1;
	nox_alloc_hdr* field_2;
	int field_3;
} nox_alloc_hdr;

typedef struct nox_alloc_class {
	char name[88];           // 0, 0, 0
	int size;                // 22, 0x58, 88
	int cnt1;                // 23
	nox_alloc_hdr* field_24; // 24
	nox_alloc_hdr* field_25; // 25
	_DWORD field_26;         // 26
	_DWORD field_27;         // 27
	_DWORD field_28;         // 28
	void* items;             // 29
	_DWORD field_30;         // 30
	_DWORD field_31;         // 31
	_DWORD field_32;         // 32
	_DWORD field_33;         // 33
	_DWORD field_34;         // 34
	_DWORD field_35;         // 35
	int cnt2;                // 36
	_DWORD field_37;         // 37
} nox_alloc_class;
_Static_assert(sizeof(nox_alloc_class) == 152, "wrong size of nox_alloc_class structure!");

typedef struct nox_thing nox_thing;
typedef struct nox_drawable nox_drawable;

typedef struct nox_thing {
	char* name;                                      // 0, 0x0
	wchar_t* pretty_name;                            // 1, 0x4, 4
	wchar_t* desc;                                   // 2, 0x8, 8
	_BYTE hwidth;                                    // 3, 0xc, 12
	_BYTE hheight;                                   // 3, 0xd, 13
	_BYTE weight;                                    // 3, 0xe, 14
	_BYTE field_f;                                   // 3, 0xf, 15
	_DWORD field_10;                                 // 4, 0x10, 16
	_WORD shape_kind;                                // 5, 0x14, 20
	_WORD z;                                         // 5, 0x16, 22
	_WORD light_dir;                                 // 6, 0x18, 24
	_WORD light_penumbra;                            // 6, 0x1a, 26
	int field_1c;                                    // 7, 0x1c, 28, ID? index?
	unsigned int pri_class;                          // 8, 0x20, 32
	_DWORD sub_class;                                // 9, 0x24, 36
	int flags;                                       // 10, 0x28, 40
	float light_intensity;                           // 11, 0x2c, 44
	int light_color_r;                               // 12, 0x30, 48
	int light_color_g;                               // 13, 0x34, 52
	int light_color_b;                               // 14, 0x38, 56
	_DWORD field_3c;                                 // 15, 0x3c
	float shape_r;                                   // 16, 0x40
	float zsize_min;                                 // 17, 0x44, 68
	float zsize_max;                                 // 18, 0x48, 72
	float shape_w;                                   // 19, 0x4c
	float shape_h;                                   // 20, 0x50
	_DWORD field_54;                                 // 21, 0x54
	int(__cdecl* draw_func)(_DWORD*, nox_drawable*); // 22, 0x58, 88, same as nox_drawable->draw_func
	void* field_5c;                                  // 23, 0x5c, 92
	_DWORD field_60;                                 // 24, 0x60
	_DWORD client_update;                            // 25, 0x64, 100
	_DWORD audio_loop;                               // 26, 0x68, 104
	nox_thing* next;                                 // 27, 0x6c, 108
	_DWORD pretty_image;                             // 28, 0x70, 112
	_DWORD menuicon;                                 // 29, 0x74, 116
	int lifetime;                                    // 30, 0x78, 120
	_WORD health;                                    // 31, 0x7c, 124
	_WORD field_7e;                                  // 31, 0x7e, 126
} nox_thing;
_Static_assert(sizeof(nox_thing) == 128, "wrong size of nox_thing structure!");

typedef enum { NOX_WIN_HIDDEN = 0x10, NOX_WIN_LAYER_FRONT = 0x20, NOX_WIN_LAYER_BACK = 0x40 } nox_window_flags;

typedef struct nox_window nox_window;
typedef struct nox_window {
	_DWORD field_0;
	nox_window_flags flags; // 1
	int width;              // 2
	int height;             // 3
	_DWORD field_4;
	_DWORD field_5;
	_DWORD field_6;
	_DWORD field_7;
	_DWORD field_8;
	_DWORD field_9[83];
	_DWORD field_92;                      // 92
	int (*field_93)(int, int, int, int);  // 93
	int (*field_94)(int, int, int, int);  // 94
	int (*draw_func)(nox_window*, void*); // 95, second arg is &field_9
	int (*field_96)(void*);               // 96
	nox_window* field_97;                 // 97, 388
	nox_window* field_98;                 // 98, 392
	nox_window* field_99;                 // 99
	nox_window* field_100;                // 100
} nox_window;
_Static_assert(sizeof(nox_window) == 404, "wrong size of nox_window structure!");

typedef struct nox_drawable {
	_DWORD field_0;        // 0, 0
	_DWORD field_1;        // 1, 4
	_DWORD field_2;        // 2, 8
	int field_3;           // 3, 12
	int field_4;           // 4, 16
	_DWORD field_5;        // 5, 20
	_DWORD field_6;        // 6, 24
	_DWORD field_7;        // 7, 28
	_DWORD field_8;        // 8, 32
	_DWORD field_9;        // 9, 36
	_DWORD field_10;       // 10, 40
	nox_shape shape;       // 11, 44
	float field_24;        // 24, 96
	float field_25;        // 25, 100
	_DWORD field_26;       // 26, 104
	_DWORD field_27;       // 27, 108, thing ID?
	unsigned int field_28; // 28, 112, flags?
	_DWORD field_29;       // 29, 116
	unsigned int flags;    // 30, 120
	_DWORD field_31;       // 31, 124
	_DWORD field_32;       // 32, 128, npc ID?
	_DWORD field_33;       // 33, 132
	_DWORD field_34;       // 34, 136
	_DWORD field_35;
	_DWORD field_36;
	_DWORD field_37;
	_DWORD field_38;  // 38, 152
	_DWORD field_39;  // 39, 156
	_DWORD field_40;  // 40, 160
	_WORD field_41_0; // 41, 164
	_WORD field_41_1; // 41, 165
	_DWORD field_42;  // 42, 168
	_DWORD field_43;
	_DWORD field_44;
	_DWORD data_45[5];
	_DWORD data_50[10];
	_DWORD data_60[5];
	_DWORD field_65;
	_DWORD field_66;
	_DWORD field_67;
	_DWORD field_68;
	_DWORD field_69; // 69, 276
	_DWORD field_70; // 70, 280
	_DWORD field_71; // 71, 284
	_DWORD field_72; // 72, 288
	_DWORD field_73;
	_BYTE field_74_1;                                // 74, 296
	_BYTE field_74_2;                                // 74, 297
	_BYTE field_74_3;                                // 74, 298
	_BYTE field_74_4;                                // 74, 299
	int(__cdecl* draw_func)(_DWORD*, nox_drawable*); // 75, 300, same as nox_thing->draw_func
	void* field_76;                                  // 76, 304
	_DWORD field_77;                                 // 77, 308
	_DWORD field_78;
	_DWORD field_79; // 79, 316
	_DWORD field_80; // 80, 320
	_DWORD field_81;
	_DWORD field_82;
	_DWORD field_83;
	_DWORD field_84;
	_DWORD field_85; // 85, 340
	_DWORD field_86;
	_DWORD field_87;
	_DWORD field_88;
	_DWORD field_89;
	nox_drawable* field_90; // 90, 360
	nox_drawable* field_91; // 91, 364
	nox_drawable* field_92; // 92, 368
	nox_drawable* field_93; // 93, 372
	_DWORD field_94;
	_DWORD field_95;
	_DWORD field_96;
	nox_drawable* field_97;  // 97, 388
	nox_drawable* field_98;  // 98, 392
	nox_drawable** field_99; // 99, 396
	nox_drawable* field_100; // 100, 400
	nox_drawable* field_101; // 101, 404
	_DWORD field_102;
	_DWORD field_103;
	_DWORD field_104;
	_DWORD field_105;
	_DWORD field_106;
	_DWORD field_107;
	_BYTE field_108_1; // 108, 432
	_BYTE field_108_2; // 108, 433
	_WORD field_108_3; // 108, 434
	_DWORD field_109;  // 109, 436, SE?
	_DWORD field_110;  // 110, 440, SW?
	_DWORD field_111;  // 111, 444, SW?
	_DWORD field_112;  // 112, 448, SE?
	_DWORD field_113;
	_DWORD field_114;
	_DWORD field_115;
	_DWORD field_116; // 116, 464
	_DWORD field_117;
	_DWORD field_118;
	_DWORD field_119;
	_DWORD field_120; // 120, 480
	_DWORD field_121; // 121, 484
	_DWORD field_122; // 122, 488
	_DWORD field_123; // 123, 492
	_DWORD field_124;
	_DWORD field_125;
	_DWORD field_126;
	_DWORD field_127;
} nox_drawable;
_Static_assert(sizeof(nox_drawable) == 512, "wrong size of nox_drawable structure!");

typedef struct obj_412ae0_t obj_412ae0_t;
typedef struct obj_412ae0_t {
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
	int field_12;
	void* field_13;
	float field_14;
	int field_15;
	void* field_16;
	float field_17;
	int field_18;
	void* field_19;
	float field_20;
	int field_21;
	void* field_22;
	float field_23;
	int field_24;
	void* field_25;
	float field_26;
	int field_27;
	void* field_28;
	void* field_29;
	float field_30;
	int field_31;
	float field_32;
	int field_33;
	obj_412ae0_t* field_34;
	obj_412ae0_t* field_35;
} obj_412ae0_t;
_Static_assert(sizeof(obj_412ae0_t) == 144, "wrong size of obj_412ae0_t structure!");

typedef struct table_26792_t {
	const char* name;
	void* fnc;
	int(__cdecl* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_26792_t;

typedef struct table_27008_t {
	const char* name;
	void* fnc;
	int(__cdecl* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27008_t;

typedef struct table_27104_t {
	const char* name;
	void* fnc;
	int(__cdecl* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27104_t;

typedef struct table_27168_t {
	const char* name;
	void* fnc;
	int(__cdecl* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27168_t;

typedef struct table_28760_t {
	const char* name;
	int(__cdecl* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_28760_t;

typedef struct nox_parse_thing_draw_funcs_t {
	const char* name;
	void* draw;
	unsigned int kind;
	bool(__cdecl* parse_fnc)(nox_thing*, nox_memfile*, char*);
} nox_parse_thing_draw_funcs_t;

typedef struct nox_video_mode {
	int width;
	int height;
	int id;
} nox_video_mode;

typedef struct mouse_pos_t {
	int x;
	int y;
} mouse_pos_t;

typedef struct nox_mouse_state_t {
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
_Static_assert(sizeof(nox_mouse_state_t) == 56, "wrong size of nox_mouse_state_t structure!");

typedef struct obj_5D4594_3799572_t {
	_DWORD data[264];
} obj_5D4594_3799572_t;

typedef struct {
	void (*fnc)(int);
	int field_4;
	char name[12];
} obj_5D4594_754088_t;

typedef struct {
	_BYTE field_0;   // 0, 0
	_BYTE field_0_1; // 0, 1
	_WORD field_0_2; // 0, 2
	int field_1;     // 1, 4
	int field_2;     // 2, 8
	int field_3;     // 3, 12
	int field_4;     // 4, 16
	void* field_5;   // 5, 20
	int field_6;     // 6, 24
	int field_7;     // 7, 28
	int field_8;     // 8, 32
	int field_9;     // 9, 36
	void* field_10;  // 10, 40
} obj_5D4594_2650668_t;
_Static_assert(sizeof(obj_5D4594_2650668_t) == 44, "wrong size of obj_5D4594_2650668_t structure!");

typedef struct {
	bool live;
	BYTE pad[3];
	int id;
	_DWORD data8[327];
} nox_npc;
//_Static_assert( sizeof( nox_npc ) == 1316, "struct nox_npc size is wrong" );

typedef struct {
	void* value;
	void* next;
	void* prev;
} nox_dblLinkedList;
_Static_assert(sizeof(nox_dblLinkedList) == 12, "wrong size of nox_dblLinkedList structure!");

typedef struct {
	nox_dblLinkedList* firstFreeObject;
	nox_dblLinkedList* lastFreeObject;
	nox_dblLinkedList objArray[16];
	nox_dblLinkedList* firstUsedObject;
	nox_dblLinkedList* lastUsedObject;
} nox_server_netCodeCacheStruct;

typedef struct nox_screenParticle nox_screenParticle;
typedef struct nox_screenParticle {
	int (*draw_fnc)(void*, nox_screenParticle*); // 0, 0
	_DWORD field_4; // 1, 4
	_DWORD field_8; // 2, 8
	_DWORD field_12; // 3, 12, color
	_DWORD field_16; // 4, 16, vx
	_DWORD field_20; // 5, 20, vy
	_DWORD field_24; // 6, 24, x
	_DWORD field_28; // 7, 28, y
	_DWORD field_32; // 8, 32
	_DWORD field_36; // 9, 36
	_BYTE field_40[4]; // 10, 40
	nox_screenParticle* field_44; // 11, 44, next
	nox_screenParticle* field_48; // 12, 48, prev
} nox_screenParticle;
_Static_assert(sizeof(nox_screenParticle) == 52, "wrong size of nox_screenParticle structure!");

typedef struct nox_wnd_xxx nox_wnd_xxx;
typedef struct nox_wnd_xxx {
	_DWORD field_0; // 0, 0
	_DWORD field_1; // 1, 4
	_DWORD field_2; // 2, 8
	_DWORD field_3; // 3, 12
	_DWORD field_4; // 4, 16
	_DWORD field_5; // 5, 20
	_DWORD field_6; // 6, 24
	_DWORD field_7; // 7, 28
	_DWORD field_8; // 8, 32
	_DWORD field_9; // 9, 36
	nox_wnd_xxx* field_10; // 10, 40
	nox_wnd_xxx* field_11; // 11, 44
	int (*field_12)(void); // 12, 48
	int (*field_13)(void); // 13, 52
	int (*field_14)(void); // 14, 56
	_DWORD field_15; // 15, 60
	_DWORD field_16; // 16, 64
} nox_wnd_xxx;
_Static_assert(sizeof(nox_wnd_xxx) == 68, "wrong size of nox_wnd_xxx structure!");

#define NOX_PLAYERINFO_MAX 32
typedef struct nox_playerInfo {
	_DWORD data[1207];
} nox_playerInfo;
_Static_assert(sizeof(nox_playerInfo) == 4828, "wrong size of nox_playerInfo structure!");

typedef enum {
	NOX_ENGINE_FLAG_1 = 1u << 0u,
	NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS = 1u << 1u,
	NOX_ENGINE_FLAG_3 = 1u << 2u,
	NOX_ENGINE_FLAG_ENABLE_SHOW_AI = 1u << 3u,
	NOX_ENGINE_FLAG_5 = 1u << 4u,
	NOX_ENGINE_FLAG_6 = 1u << 5u,
	NOX_ENGINE_FLAG_7 = 1u << 6u,
	NOX_ENGINE_FLAG_8 = 1u << 7u,
	NOX_ENGINE_FLAG_9 = 1u << 8u,
	NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE = 1u << 9u,
	NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE = 1u << 10u,
	NOX_ENGINE_FLAG_12 = 1u << 11u,
	NOX_ENGINE_FLAG_13 = 1u << 12u,
	NOX_ENGINE_FLAG_14 = 1u << 13u,
	NOX_ENGINE_FLAG_15 = 1u << 14u,
	NOX_ENGINE_FLAG_ENABLE_NET_DEBUG = 1u << 15u,
	NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING = 1u << 16u,
	NOX_ENGINE_FLAG_18 = 1u << 17u,
	NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING = 1u << 18u,
	NOX_ENGINE_FLAG_20 = 1u << 19u,
	NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING = 1u << 20u,
	NOX_ENGINE_FLAG_22 = 1u << 21u,
	NOX_ENGINE_FLAG_23 = 1u << 22u,
	NOX_ENGINE_FLAG_24 = 1u << 23u,
	NOX_ENGINE_FLAG_25 = 1u << 24u,
	NOX_ENGINE_FLAG_26 = 1u << 25u,
	NOX_ENGINE_FLAG_27 = 1u << 26u,
	NOX_ENGINE_FLAG_28 = 1u << 27u,
	NOX_ENGINE_FLAG_29 = 1u << 28u,
	NOX_ENGINE_FLAG_30 = 1u << 29u,
	NOX_ENGINE_FLAG_31 = 1u << 30u,
	NOX_ENGINE_FLAG_32 = 1u << 31u,
} nox_engine_flag;

#endif
