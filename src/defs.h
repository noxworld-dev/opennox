#ifndef NOX_DEFS_H
#define NOX_DEFS_H

#define DIRECTINPUT_VERSION 0x0700
#include "memfile.h"
#include "nox_net.h"
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <wctype.h>

#define NO_MOVIE 1
#define NO_WOLAPI 1

#define NOX_DEFAULT_WIDTH 640
#define NOX_DEFAULT_HEIGHT 480
#define NOX_DEFAULT_DEPTH 16

#ifdef NOX_HIGH_RES
#define NOX_MAX_WIDTH 3840
#define NOX_MAX_HEIGHT 2160
#define NOX_CLIENT_VERS_CODE 0x000F039A
#else // NOX_HIGH_RES
#define NOX_MAX_WIDTH 1024
#define NOX_MAX_HEIGHT 768
#define NOX_CLIENT_VERS_CODE 0x0001039A
#endif // NOX_HIGH_RES

#define NOX_FILEPATH_MAX 1024

#define NOX_PLAYER_MAX_LEVEL 10

#define USE_SDL 1

#include "memmap.h"
#include "common/platform/platform.h"

#include "static_assert.h"
#include "nox_wchar.h"

#ifdef _WIN32
// added for TDM-GCC/MinGW headers compatibility
#ifdef _TDM
typedef long LSTATUS;
#endif // _TDM

#include <windows.h>
//#include <mmreg.h>

#else // _WIN32
#include "windows_compat.h"
#endif // _WIN32

#include "compat_mss.h"
#include "common__binfile.h"
#include "common__strman.h"
#include "noxstring.h"
#include <stdbool.h>

#include "common/alloc/classes/alloc_class.h"
#include "client__gui__window.h"

// '...' differs in levels of indirection from '... *'
#pragma warning(disable : 4047)

// incompatible types - from '... *' to '... *'
#pragma warning(disable : 4133)

// '...' undefined; assuming extern returning int
#pragma warning(disable : 4013)

// signed/unsigned mismatch
#pragma warning(disable : 4018)

// conversion from '...' to '...', possible loss of data
#pragma warning(disable : 4244)

// truncation from '...' to '...'
#pragma warning(disable : 4305)

// integral size mismatch in argument; conversion supplied
#pragma warning(disable : 4761)

#pragma warning(disable : 4028 4024 4700 4026 4070 4142 4022 4098 4113 4146 4090 4172 4101)

enum {
	NOX_NET_SEND_NO_LOCK = 0x1,
	NOX_NET_SEND_FLAG2 = 0x2,
};

// For now bools are kept 1-byte long
//_Static_assert(sizeof(bool) == 4, "boolean values must be aligned to 32-bit int");

#ifdef __thiscall
#undef __thiscall
#endif
#define __thiscall  // Test compile in C mode

typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned __int64 _QWORD;

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

void nox_exit(int exitCode);
void nox_on_exit(void (*fnc)(void));

static int __OFSUB__(int x, int y) {
	abort();
	return 0;
}
static int __CFSHR__(int x, int y) {
	abort();
	return 0;
}
static int __CFSHL__(int x, int y) {
	abort();
	return 0;
}
static int __CFADD__(int x, int y) {
	abort();
	return 0;
}
static int __OFADD__(int x, int y) {
	abort();
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

static void std___Xran() { abort(); }

static void std___Xlen() { abort(); }

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
typedef struct nox_player_polygon_check_data {
	int field_0[35];
} nox_player_polygon_check_data;

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

typedef struct {
	int x;
	int y;
} nox_point;

typedef struct {
	float x;
	float y;
} nox_pointf;

typedef struct {
	int left;
	int top;
	int right;
	int bottom;
} nox_rect;

typedef enum { NOX_SHAPE_NONE = 0, NOX_SHAPE_CENTER = 1, NOX_SHAPE_CIRCLE = 2, NOX_SHAPE_BOX = 3 } nox_shape_kind;

typedef struct nox_shape {
	nox_shape_kind kind;      // 0, 0x0
	float circle_r;           // 1, 0x4
	float circle_r2;          // 2, 0x8
	float box_w;              // 3, 0xC
	float box_h;              // 4, 0x10
	float box_left_top;       // 5, 0x14
	float box_left_bottom;    // 6, 0x18
	float box_left_bottom_2;  // 7, 0x1C
	float box_left_top_2;     // 8, 0x20
	float box_right_top;      // 9, 0x24
	float box_right_bottom;   // 10, 0x28
	float box_right_bottom_2; // 11, 0x2C
	float box_right_top_2;    // 12, 0x30
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

typedef struct struc_36 struc_36;
typedef struct struc_36 {
	_DWORD field_0;
	int field_1;
	_DWORD field_2;
	_DWORD field_3;
	_DWORD field_4;
	void (*field_5)(void);
	void (*field_6)(struc_36*);
} struc_36;
_Static_assert(sizeof(struc_36) == 28, "wrong size of struc_36 structure!");

#ifndef NOX_CGO
typedef struct {
	char* data; // 0, 0
	_DWORD field_1; // 1, 4
	unsigned int bag_offs; // 2, 8
	int size;      // 3, 12; sizeof decompressed data
	int size_comp; // 4, 16; sizeof compressed data
	_DWORD field_5; // 5, 20
	int field_6;
	void* field_7;
	void* field_8;
} nox_video_bag_section_t;
_Static_assert(sizeof(nox_video_bag_section_t) == 36, "wrong size of nox_video_bag_section_t structure!");

typedef struct nox_video_bag_image_t {
	int offset; // 0, 0
	_WORD field_1_0; // 1, 4
	_WORD field_1_1; // 1, 6
	_WORD sect_ind; // 2, 8
	_WORD typ; // 2, 10
} nox_video_bag_image_t;
_Static_assert(sizeof(nox_video_bag_image_t) == 12, "wrong size of nox_video_bag_image_t structure!");
static int nox_video_bag_image_type(nox_video_bag_image_t* img) { return img->typ; }
#else // NOX_CGO
typedef struct nox_video_bag_image_t nox_video_bag_image_t;
int nox_video_bag_image_type(nox_video_bag_image_t* img);
#endif // NOX_CGO

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
	int(* draw_func)(_DWORD*, nox_drawable*); // 22, 0x58, 88, same as nox_drawable->draw_func
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

typedef struct nox_objectType_t nox_objectType_t;
typedef struct nox_objectType_t {
	unsigned short ind; // 0, 0
	unsigned short field_0_1; // 0, 2
	const char* id; // 1, 4
	_DWORD field_2; // 2, 8
	_DWORD field_3; // 3, 12
	unsigned int field_4; // 4, 16
	_WORD field_5_0; // 5, 20
	_WORD field_5_1; // 5, 22
	unsigned int obj_class; // 6, 24
	_DWORD field_7; // 7, 28
	unsigned int field_8; // 8, 32, TODO: some flags? subclass?
	_DWORD field_9; // 9, 36
	_WORD field_10; // 10, 40
	_WORD field_10_1; // 10, 42
	_DWORD field_11; // 11, 44
	_DWORD field_12; // 12, 48
	float field_13; // 13, 52
	float field_14; // 14, 56
	nox_shape shape; // 15, 60
	_DWORD field_28; // 28, 112
	float field_29; // 29, 116
	_BYTE field_30_0; // 30, 120
	_BYTE field_30_1; // 30, 121
	_WORD field_30_2; // 30, 122
	float field_31; // 31, 124
	float field_32; // 32, 128
	_DWORD field_33; // 33, 132
	void* field_34; // 34, 136, TODO: data, *[20]byte
	_DWORD field_35; // 35, 140
	void* field_36; // 36, 144, TODO: data
	int   field_36_size; // 37, 148
	void* func_damage; // 38, 152
	void* func_damage_sound; // 39, 156
	_DWORD field_40; // 40, 160
	void* field_41; // 41, 164, TODO: data
	_DWORD field_42; // 42, 168
	_DWORD field_43; // 43, 172
	void* field_44; // 44, 176, TODO: data
	int   field_44_size; // 45, 180
	_DWORD field_46; // 46, 184
	_DWORD field_47; // 47, 188
	void* field_48; // 48, 192, TODO: data
	int   field_48_size; // 49, 196
	_DWORD field_50; // 50, 200
	void* field_51; // 51, 204, TODO: data
	int   field_51_size; // 52, 208
	void* func_xfer; // 53, 212
	void (*func_new)(void*); // 54, 216
	nox_objectType_t* next; // 55, 220
} nox_objectType_t;
_Static_assert(sizeof(nox_objectType_t) == 224, "wrong size of nox_objectType_t structure!");

typedef struct nox_object_t nox_object_t;
typedef struct nox_object_t {
	const char* id; // 0, 0
	unsigned short typ_ind; // 1, 4
	_WORD field_1_2; // 1, 6
	unsigned int obj_class; // 2, 8 -- Bitmask: 0x2 is owned monster, 0x4 is player
	_DWORD field_3; // 3, 12, // TODO: some flags?
	unsigned int field_4; // 4, 16, // TODO: some flags?
	_DWORD field_5; // 5, 20
	_WORD field_6_0; // 6, 24
	_WORD field_6_2; // 6, 26
	_DWORD field_7; // 7, 28
	_DWORD field_8; // 8, 32
	_DWORD field_9; // 9, 36
	unsigned int extent; // 10, 40
	int script_id; // 11, 44
	_DWORD field_12; // 12, 48
	_DWORD field_13; // 13, 52, // TODO: first byte is team?
	float x; // 14, 56
	float y; // 15, 60
	float new_x; // 16, 64
	float new_y; // 17, 68
	_DWORD field_18; // 18, 72
	_DWORD field_19; // 19, 76
	float vel_x; // 20, 80
	float vel_y; // 21, 84
	float force_x; // 22, 88
	float force_y; // 23, 92
	float float_24; // 24, 96, // TODO: something related to acceleration/direction
	float float_25; // 25, 100, // TODO: something related to acceleration/direction
	_DWORD field_26; // 26, 104
	_DWORD field_27; // 27, 108
	float float_28; // 28, 112, // TODO: damping/drag?
	_DWORD field_29; // 29, 116
	float float_30; // 30, 120
	_WORD field_31_0; // 31, 124, // TODO: 124 is set to value of 126 in at least 51B100
	_WORD field_31_1; // 31, 126, // TODO: 126 accessed as word in at least 51B100, probably direction
	_DWORD field_32; // 32, 128
	_DWORD field_33; // 33, 132
	_DWORD field_34; // 34, 136
	_DWORD field_35; // 35, 140
	_DWORD field_36; // 36, 144
	_DWORD field_37; // 37, 148
	int field_38; // 38, 152
	_DWORD field_39; // 39, 156
	_DWORD field_40; // 40, 160
	_DWORD field_41; // 41, 164
	_DWORD field_42; // 42, 168
	nox_shape shape; // 43, 172
	_DWORD field_56; // 56, 224
	_DWORD field_57; // 57, 228
	_DWORD field_58; // 58, 232
	_DWORD field_59; // 59, 236
	_DWORD field_60; // 60, 240
	_DWORD field_61; // 61, 244
	_DWORD field_62; // 62, 248
	_DWORD field_63; // 63, 252
	_DWORD field_64; // 64, 256
	_DWORD field_65; // 65, 260
	_DWORD field_66; // 66, 264
	_DWORD field_67; // 67, 268
	_DWORD field_68; // 68, 272
	_DWORD field_69; // 69, 276
	_DWORD field_70; // 70, 280
	_DWORD field_71; // 71, 284
	_DWORD field_72; // 72, 288
	_DWORD field_73; // 73, 292
	_DWORD field_74; // 74, 296
	_DWORD field_75; // 75, 300
	_DWORD field_76; // 76, 304
	_DWORD field_77; // 77, 308
	_DWORD field_78; // 78, 312
	_DWORD field_79; // 79, 316
	_DWORD field_80; // 80, 320
	_DWORD field_81; // 81, 324
	_DWORD field_82; // 82, 328
	_DWORD field_83; // 83, 332
	_DWORD field_84; // 84, 336
	_DWORD field_85; // 85, 340
	_DWORD field_86; // 86, 344
	_DWORD field_87; // 87, 348
	_DWORD field_88; // 88, 352
	_DWORD field_89; // 89, 356
	_DWORD field_90; // 90, 360
	_DWORD field_91; // 91, 364
	_DWORD field_92; // 92, 368
	_DWORD field_93; // 93, 372
	_DWORD field_94; // 94, 376
	_DWORD field_95; // 95, 380
	_DWORD field_96; // 96, 384
	_DWORD field_97; // 97, 388
	_DWORD field_98; // 98, 392
	_DWORD field_99; // 99, 396
	_DWORD field_100; // 100, 400
	_DWORD field_101; // 101, 404
	_DWORD field_102; // 102, 408
	_DWORD field_103; // 103, 412
	_DWORD field_104; // 104, 416
	_DWORD field_105; // 105, 420
	_DWORD field_106; // 106, 424
	_DWORD field_107; // 107, 428
	_DWORD field_108; // 108, 432
	_DWORD field_109; // 109, 436
	_DWORD field_110; // 110, 440
	void* field_111; // 111, 444
	_DWORD field_112; // 112, 448
	_DWORD field_113; // 113, 452
	_DWORD field_114; // 114, 456
	_DWORD field_115; // 115, 460
	_DWORD field_116; // 116, 464
	_DWORD field_117; // 117, 468
	_DWORD field_118; // 118, 472
	_DWORD field_119; // 119, 476
	_DWORD field_120; // 120, 480
	_DWORD field_121; // 121, 484
	_BYTE field_122_0; // 122, 488
	_BYTE field_122_1; // 122, 489
	_WORD field_122_2; // 122, 490
	_DWORD field_123; // 123, 492 // Also health data, possibly same as 556, see 4E4560
	nox_object_t* field_124; // 124, 496, TODO: next item
	void* field_125; // 125, 500, TODO: a nox_object_t*? see 4ED0C0
	nox_object_t* field_126; // 126, 504, TODO: first item
	_DWORD field_127; // 127, 508
	void* field_128; // 128, 512
	void* field_129; // 129, 516
	_DWORD field_130; // 130, 520
	_DWORD field_131; // 131, 524
	_DWORD field_132; // 132, 528
	_DWORD field_133; // 133, 532
	_DWORD field_134; // 134, 536
	_DWORD field_135; // 135, 540, TODO: 541 accessed as byte
	float float_136; // 136, 544, TODO: current speed?
	float float_137; // 137, 548
	float float_138; // 138, 552
	void* field_139; // 139, 556, TODO: data, *[20]byte, related to health and damage
	_DWORD field_140; // 140, 560
	_DWORD field_141; // 141, 564
	_DWORD field_142; // 142, 568
	_DWORD field_143; // 143, 572
	_DWORD field_144; // 144, 576
	_DWORD field_145; // 145, 580
	_DWORD field_146; // 146, 584
	_DWORD field_147; // 147, 588
	_DWORD field_148; // 148, 592
	_DWORD field_149; // 149, 596
	_DWORD field_150; // 150, 600
	_DWORD field_151; // 151, 604
	_DWORD field_152; // 152, 608
	_DWORD field_153; // 153, 612
	_DWORD field_154; // 154, 616
	_DWORD field_155; // 155, 620
	_DWORD field_156; // 156, 624
	_DWORD field_157; // 157, 628
	_DWORD field_158; // 158, 632
	_DWORD field_159; // 159, 636
	_DWORD field_160; // 160, 640
	_DWORD field_161; // 161, 644
	_DWORD field_162; // 162, 648
	_DWORD field_163; // 163, 652
	_DWORD field_164; // 164, 656
	_DWORD field_165; // 165, 660
	_DWORD field_166; // 166, 664
	_DWORD field_167; // 167, 668
	_DWORD field_168; // 168, 672
	_DWORD field_169; // 169, 676
	_DWORD field_170; // 170, 680
	_DWORD field_171; // 171, 684
	_DWORD field_172; // 172, 688
	void* field_173; // 173, 692, // TODO: struct pointer; struct at least 8 bytes wide. see 4F3030.
	_DWORD field_174; // 174, 696
	void* field_175; // 175, 700, // TODO: data
	void* func_xfer; // 176, 704
	_DWORD field_177; // 177, 708
	_DWORD field_178; // 178, 712
	void* func_damage; // 179, 716
	void* func_damage_sound; // 180, 720
	_DWORD deleteOverride; // 181, 724 // deletion override function (see 004EE5E0)
	_DWORD field_182; // 182, 728
	_DWORD field_183; // 183, 732
	void* field_184; // 184, 736, // TODO: data
	_DWORD field_185; // 185, 740
	_DWORD field_186; // 186, 744 // TODO: (void(**)(int))
	void* field_187; // 187, 748, // Mana data, source 4EEBF0
	_DWORD field_188; // 188, 752
	_DWORD field_189; // 189, 756
	_DWORD field_190; // 190, 760
	_DWORD field_191; // 191, 764
	int field_192; // 192, 768
} nox_object_t;
_Static_assert(sizeof(nox_object_t) == 772, "wrong size of nox_object_t structure!");

#define NOX_SERVER_XXX_SIZE 256
typedef struct nox_server_xxx {
	_DWORD field_0;
	_DWORD field_4;
	_WORD field_8;
	_WORD field_10;
} nox_server_xxx;
_Static_assert(sizeof(nox_server_xxx) == 12, "wrong size of nox_server_xxx structure!");

typedef struct nox_net_struct_arg_t {
	_DWORD field_0;
	_DWORD field_1;
	int port;
	int data_3_size;
	int field_4;
	int data_size;
	_DWORD field_6;
	_DWORD field_7;
	int (*func_xxx)(unsigned int, char*, int, void*);
	int (*func_yyy)(unsigned int, char*, int, void*);
} nox_net_struct_arg_t;
_Static_assert(sizeof(nox_net_struct_arg_t) == 40, "wrong size of nox_net_struct_arg_t structure!");

#define NOX_NET_STRUCT_MAX 128
typedef struct nox_net_struct_t {
	nox_socket_t sock; // 0, 0
	struct nox_net_sockaddr_in addr; // 1, 4
	int id; // 5, 20
	_DWORD field_6;
	_DWORD field_7;

	char* data_1_base; //  8, 32
	char* data_1_xxx;  //  9, 36
	char* data_1_yyy;  // 10, 40
	char* data_1_end;  // 11, 44

	char* data_2_base; // 12, 48
	char* data_2_xxx;  // 13, 52
	char* data_2_yyy;  // 14, 56
	char* data_2_end;  // 15, 60

	_DWORD field_16;
	_DWORD field_17;
	_DWORD field_18;
	_DWORD field_19; // 76
	_DWORD field_20;
	_DWORD field_21; // 84
	_DWORD field_22; // 88
	_DWORD field_23; // 92
	_DWORD field_24; // 96
	_DWORD field_25; // 100
	_DWORD field_26; // 104
	_DWORD field_27; // 108
	_BYTE field_28_0; // 112
	char field_28_1; // 113
	_WORD field_28_2; // 114
	void* field_29; // 116
	void* data_3; // 30, 120
	HANDLE mutex_xxx; // 31, 124
	HANDLE mutex_yyy; // 32, 128
	_DWORD field_33;
	_DWORD field_34; // 136
	int (*func_xxx)(unsigned int, char*, int, void*); // 35, 140, func(i, data_2_xxx, sz, data_3)
	int (*func_yyy)(unsigned int, char*, int, void*); // 36, 144, last arg is data_3
	_BYTE xor_key; // 37, 148
	_BYTE field_37_1; // 37, 149
	_WORD field_37_2; // 37, 150
	_DWORD field_38;  // 152
	_BYTE data_39[4]; // 156
	_DWORD field_40;  // 160
} nox_net_struct_t;
_Static_assert(sizeof(struct nox_net_sockaddr) == 16, "wrong size of nox_net_sockaddr structure!");
_Static_assert(sizeof(struct nox_net_sockaddr_in) == 16, "wrong size of nox_net_sockaddr_in structure!");
_Static_assert(sizeof(nox_net_struct_t) == 164, "wrong size of nox_net_struct_t structure!");

typedef struct nox_net_struct2_t {
	_DWORD field_0; // 0, 0
	_BYTE field_1_0; // 1, 4
	_BYTE field_1_1; // 1, 5
	_WORD field_1_2; // 1, 6
	// TODO: check usages, looks like it reuses sin_zero for something else
	struct nox_net_sockaddr_in addr; // 2, 8
	_DWORD field_6[10]; // 6, 24
	_DWORD ticks; // 16, 64
} nox_net_struct2_t;
_Static_assert(sizeof(nox_net_struct2_t) == 68, "wrong size of nox_net_struct2_t structure!");

typedef struct nox_things_imageRef_t {
	char name[32]; // 0, 0
	char name2[64]; // 8, 32
	int field_24; // 24, 96; void* when field_25_1 == 2
	char field_25_0; // 25, 100
	char field_25_1; // 25, 101
	short field_25_2; // 25, 102
} nox_things_imageRef_t;
_Static_assert(sizeof(nox_things_imageRef_t) == 104, "wrong size of nox_things_imageRef_t structure!");

typedef struct {
	_DWORD field_0;
} nox_radioButton_data;
_Static_assert(sizeof(nox_radioButton_data) == 4, "wrong size of nox_radioButton_data structure!");

typedef struct {
	_DWORD field_0;
	_DWORD field_1;
	_DWORD field_2;
	_DWORD field_3;
} nox_slider_data;
_Static_assert(sizeof(nox_slider_data) == 16, "wrong size of nox_slider_data structure!");

typedef struct {
	_WORD field_0_0;
	_WORD field_0_1;
	_DWORD field_1;
	_DWORD field_2;
	_DWORD field_3;
	_DWORD field_4;
	_DWORD field_5;
	_DWORD data_6[8];
} nox_scrollListBox_data;
_Static_assert(sizeof(nox_scrollListBox_data) == 56, "wrong size of nox_scrollListBox_data structure!");

typedef struct {
	_BYTE data_0[1024];
	_DWORD field_1024;
	_DWORD field_1028;
	_DWORD field_1032;
	_DWORD field_1036;
	unsigned short field_1040;
	short field_1042;
	_DWORD field_1044;
	_DWORD field_1048;
	_DWORD field_1052;
} nox_entryField_data;
_Static_assert(sizeof(nox_entryField_data) == 1056, "wrong size of nox_entryField_data structure!");

typedef struct {
	wchar_t* text;
	_DWORD field_1;
	_DWORD field_2;
} nox_staticText_data;
_Static_assert(sizeof(nox_staticText_data) == 12, "wrong size of nox_staticText_data structure!");

typedef struct nox_window_yyy {
	nox_window* win; // 0
	_DWORD field_1; // 4
	_DWORD field_2; // 8
	uint32_t color_1; // 12
	uint32_t color_2; // 16
} nox_window_yyy;
_Static_assert(sizeof(nox_window_yyy) == 20, "wrong size of nox_window_yyy structure!");

typedef struct {
	const char* name;
	int (*fnc)(nox_window_data*, char*);
} nox_parseWindowFunc;
_Static_assert(sizeof(nox_parseWindowFunc) == 8, "wrong size of nox_parseWindowFunc structure!");

#define NOX_SAVEGAME_XXX_MAX 14
#pragma pack(push,1)
typedef struct nox_savegame_xxx {
	_DWORD field_0;
	_BYTE field_4[1024];
	_BYTE field_1028[160];
	SYSTEMTIME field_1188;
	_BYTE field_1204[20];
	_BYTE field_1224[50];
	_BYTE field_1274;
	_BYTE field_1275;
	_BYTE field_1276;
	_BYTE field_1277;
} nox_savegame_xxx;
#pragma pack(pop)
_Static_assert(sizeof(nox_savegame_xxx) == 1278, "wrong size of nox_savegame_xxx structure!");
_Static_assert(sizeof(SYSTEMTIME) == 16, "wrong size of SYSTEMTIME structure!");

typedef struct nox_drawable {
	_DWORD field_0;        // 0, 0
	_DWORD field_1;        // 1, 4
	_DWORD field_2;        // 2, 8
	nox_point pos;         // 3, 12
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
	unsigned int flags28;  // 28, 112
	unsigned int flags29;  // 29, 116
	unsigned int flags30;  // 30, 120
	unsigned int flags31;  // 31, 124
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
	unsigned int flags70; // 70, 280
	_DWORD field_71; // 71, 284
	_DWORD field_72; // 72, 288
	_WORD field_73_1; // 73, 292
	_WORD field_73_2; // 73, 294
	_BYTE field_74_1;                                // 74, 296
	_BYTE field_74_2;                                // 74, 297
	_BYTE field_74_3;                                // 74, 298
	_BYTE field_74_4;                                // 74, 299
	int(* draw_func)(_DWORD*, nox_drawable*); // 75, 300, same as nox_thing->draw_func
	void* field_76;                                  // 76, 304
	_DWORD field_77;                                 // 77, 308
	_DWORD field_78;
	_DWORD field_79; // 79, 316
	_DWORD field_80; // 80, 320
	_DWORD field_81;
	_DWORD field_82;
	_DWORD field_83;
	_DWORD field_84;
	_DWORD field_85; // 85, 340, last draw frame number?
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
	_DWORD field_102; // 102, 408
	_DWORD field_103; // 103, 412
	nox_drawable* field_104; // 104, 416
	nox_drawable* field_105; // 105, 420
	_DWORD field_106; // 106, 424
	_DWORD field_107; // 107, 428
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

// 3108 = NOX_OBJ_1050020_ROW_COUNT * sizeof(nox_obj_1050020_t)
// 777 = NOX_OBJ_1050020_ROW_COUNT * (sizeof(nox_obj_1050020_t)/4)
// 37 = (sizeof(nox_obj_1050020_t)/4)
#define NOX_OBJ_1050020_ROW_COUNT 21
#define NOX_OBJ_1050020_COL_COUNT 4
#define NOX_OBJ_1050020_MAX (NOX_OBJ_1050020_ROW_COUNT*NOX_OBJ_1050020_COL_COUNT)
typedef struct nox_obj_1050020_t {
	nox_drawable* field_0;
	_DWORD field_4;
	_DWORD data_4[30];
	_DWORD field_128;
	_DWORD field_132;
	_DWORD field_136;
	_BYTE field_140;
	_BYTE field_141;
	_BYTE field_142;
	_BYTE field_143;
	_DWORD field_144;
} nox_obj_1050020_t;
_Static_assert(sizeof(nox_obj_1050020_t) == 148, "wrong size of nox_obj_1050020_t structure!");

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
	int(* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_26792_t;

typedef struct table_27008_t {
	const char* name;
	void* fnc;
	int(* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27008_t;

typedef struct table_27104_t {
	const char* name;
	void* fnc;
	int(* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27104_t;

typedef struct table_27168_t {
	const char* name;
	void* fnc;
	int(* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27168_t;

typedef struct table_28760_t {
	const char* name;
	int(* parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_28760_t;

typedef struct nox_ctrlevent_code_info_t {
	const char* name;
	unsigned int has_data;
	unsigned int data_size; // in bytes; see nox_ctrlevent_xxx_t.data
} nox_ctrlevent_code_info_t;

typedef enum {
	CC_Null = 0,
	CC_Orientation = 1,
	CC_MoveForward = 2,
	CC_MoveBackward = 3,
	CC_MoveLeft = 4,
	CC_MoveRight = 5,
	CC_Action = 6,
	CC_Jump = 7,
	CC_Chat = 8,
	CC_TeamChat = 9,
	CC_ReadSpellbook = 10,
	CC_ToggleConsole = 11,
	// TODO: somewhere around here the indexes are off by +2 (e.g. CC_QuitMenu = 17)
	CC_IncreaseWindowSize = 12,
	CC_DecreaseWindowSize = 13,
	CC_Quit = 14,
	CC_QuitMenu = 15,
	CC_ReadMap = 16,
	CC_Inventory = 17,
	CC_SpellGestureUp = 18,
	CC_SpellGestureDown = 19,
	CC_SpellGestureLeft = 20,
	CC_SpellGestureRight = 21,
	CC_SpellGestureUpperRight = 22,
	CC_SpellGestureUpperLeft = 23,
	CC_SpellGestureLowerRight = 24,
	CC_SpellGestureLowerLeft = 25,
	CC_SpellPatternEnd = 26,
	CC_CastQueuedSpell = 27,
	CC_CastMostRecentSpell = 28,
	CC_CastSpell1 = 29,
	CC_CastSpell2 = 30,
	CC_CastSpell3 = 31,
	CC_CastSpell4 = 32,
	CC_CastSpell5 = 33,
	CC_MapZoomIn = 34,
	CC_MapZoomOut = 35,
	CC_NextWeapon = 36,
	CC_QuickHealthPotion = 37,
	CC_QuickManaPotion = 38,
	CC_QuickCurePoisonPotion = 39,
	CC_NextSpellSet = 40,
	CC_PreviousSpellSet = 41,
	CC_SelectSpellSet = 42,
	CC_BuildTrap = 43,
	CC_ServerOptions = 44,
	CC_Taunt = 45,
	CC_Laugh = 46,
	CC_Point = 47,
	CC_InvertSpellTarget = 48,
	CC_ToggleRank = 49,
	CC_ToggleNetstat = 50,
	CC_ToggleGUI = 51,
	CC_AutoSave = 52,
	CC_AutoLoad = 53,
	CC_ScreenShot = 54,
	CC_Unknown55 = 55,
	CC_Unknown56 = 56
} nox_ctrlevent_code;
_Static_assert(CC_Null == 0, "wrong value for CC_Null!");
_Static_assert(CC_Orientation == 1, "wrong value for CC_Orientation!");
_Static_assert(CC_ScreenShot == 54, "wrong value for CC_ScreenShot!");

typedef struct nox_parse_thing_draw_funcs_t {
	const char* name;
	void* draw;
	unsigned int kind;
	bool(* parse_fnc)(nox_thing*, nox_memfile*, char*);
} nox_parse_thing_draw_funcs_t;

typedef struct nox_video_mode {
	int width;
	int height;
	int id;
	wchar_t* title;
} nox_video_mode;

enum {
	NOX_MOUSE_LEFT = 0,
	NOX_MOUSE_RIGHT = 1,
	NOX_MOUSE_MIDDLE = 2
};

enum {
	NOX_MOUSE_DOWN = 1,
	NOX_MOUSE_DRAG_END = 2,
	NOX_MOUSE_UP = 3,
	NOX_MOUSE_PRESSED = 4
};

int nox_mouse_state(int btn, int st);

typedef struct nox_mouse_btn_t {
	int pressed;
	_DWORD state;
	_DWORD seq;
} nox_mouse_btn_t;
_Static_assert(sizeof(nox_mouse_btn_t) == 12, "wrong size of nox_mouse_btn_t structure!");

typedef struct nox_mouse_state_t {
	nox_point pos; // 0
	int wheel; // 8

	nox_point dpos; // 12

	nox_mouse_btn_t btn[3]; // 20, 32, 44
} nox_mouse_state_t;
_Static_assert(sizeof(nox_mouse_state_t) == 56, "wrong size of nox_mouse_state_t structure!");

typedef struct nox_keyboard_btn_t {
	_BYTE code;
	_BYTE state;
	_BYTE field_2;
	_BYTE field_3;
	_DWORD seq;
} nox_keyboard_btn_t;
_Static_assert(sizeof(nox_keyboard_btn_t) == 8, "wrong size of nox_keyboard_btn_t structure!");

#define NOX_CTRLEVENT_XXX_MAX 128
typedef struct nox_ctrlevent_xxx_t {
	__int64 tick; // 0
	nox_ctrlevent_code code; // 8
	_DWORD  data; // 12
	int     active; // 16
	_DWORD  paddding; // 20
} nox_ctrlevent_xxx_t;
_Static_assert(sizeof(nox_ctrlevent_xxx_t) == 24, "wrong size of nox_ctrlevent_xxx_t structure!");

typedef struct nox_render_data_t {
	int flag_0; // 0, 0
	nox_rect clip; // 1, 4
	nox_rect rect2; // 5, 20; is usually set to [0,w-1] as opposed to clip, which is [0,w]
	_DWORD field_9; // 9, 36
	_DWORD field_10; // 10, 40
	_DWORD field_11; // 11, 44
	_DWORD field_12; // 12, 48
	_DWORD field_13; // 13, 52
	_DWORD field_14; // 14, 56
	_DWORD field_15; // 15, 60
	_DWORD field_16; // 16, 64
	_DWORD field_17; // 17, 68
	_DWORD field_18; // 18, 72
	_DWORD field_19; // 19, 76
	_DWORD field_20; // 20, 80
	_DWORD field_21; // 21, 84
	_DWORD field_22; // 22, 88
	_DWORD field_23; // 23, 92
	_DWORD field_24; // 24, 96
	_DWORD field_25; // 25, 100
	_DWORD field_26; // 26, 104
	_DWORD field_27; // 27, 108
	_DWORD field_28; // 28, 112
	_DWORD field_29; // 29, 116
	_DWORD field_30; // 30, 120
	_DWORD field_31; // 31, 124
	_DWORD field_32; // 32, 128
	_DWORD field_33; // 33, 132
	_DWORD field_34; // 34, 136
	_DWORD field_35; // 35, 140
	_DWORD field_36; // 36, 144
	_DWORD field_37; // 37, 148
	_DWORD field_38; // 38, 152
	_DWORD field_39; // 39, 156
	_DWORD field_40; // 40, 160
	_DWORD field_41; // 41, 164
	_DWORD field_42; // 42, 168
	_DWORD field_43; // 43, 172
	_DWORD field_44; // 44, 176
	_DWORD field_45; // 45, 180
	_DWORD field_46; // 46, 184
	_DWORD field_47; // 47, 188
	_DWORD field_48; // 48, 192
	_DWORD field_49; // 49, 196
	_DWORD field_50; // 50, 200
	_DWORD field_51; // 51, 204
	_DWORD field_52; // 52, 208
	_DWORD field_53; // 53, 212
	_DWORD field_54; // 54, 216
	_DWORD field_55; // 55, 220
	_DWORD field_56; // 56, 224
	_DWORD field_57; // 57, 228
	_DWORD field_58; // 58, 232
	_DWORD field_59; // 59, 236
	_DWORD field_60; // 60, 240
	_DWORD field_61; // 61, 244
	_DWORD field_62; // 62, 248
	_DWORD field_63; // 63, 252
	_DWORD field_64; // 64, 256
	_DWORD field_65; // 65, 260
	_DWORD field_66; // 66, 264
	_DWORD field_67; // 67, 268
	_DWORD field_68; // 68, 272
	_DWORD field_69; // 69, 276
	_DWORD field_70; // 70, 280
	_DWORD field_71; // 71, 284
	_DWORD field_72; // 72, 288
	_DWORD field_73; // 73, 292
	_DWORD field_74; // 74, 296
	_DWORD field_75; // 75, 300
	_DWORD field_76; // 76, 304
	_DWORD field_77; // 77, 308
	_DWORD field_78; // 78, 312
	_DWORD field_79; // 79, 316
	_DWORD field_80; // 80, 320
	_DWORD field_81; // 81, 324
	_DWORD field_82; // 82, 328
	_DWORD field_83; // 83, 332
	_DWORD field_84; // 84, 336
	_DWORD field_85; // 85, 340
	_DWORD field_86; // 86, 344
	_DWORD field_87; // 87, 348
	_DWORD field_88; // 88, 352
	_DWORD field_89; // 89, 356
	_DWORD field_90; // 90, 360
	_DWORD field_91; // 91, 364
	_DWORD field_92; // 92, 368
	_DWORD field_93; // 93, 372
	_DWORD field_94; // 94, 376
	_DWORD field_95; // 95, 380
	_DWORD field_96; // 96, 384
	_DWORD field_97; // 97, 388
	_DWORD field_98; // 98, 392
	_DWORD field_99; // 99, 396
	_DWORD field_100; // 100, 400
	_DWORD field_101; // 101, 404
	_DWORD field_102; // 102, 408
	_DWORD field_103; // 103, 412
	_DWORD field_104; // 104, 416
	_DWORD field_105; // 105, 420
	_DWORD field_106; // 106, 424
	_DWORD field_107; // 107, 428
	_DWORD field_108; // 108, 432
	_DWORD field_109; // 109, 436
	_DWORD field_110; // 110, 440
	_DWORD field_111; // 111, 444
	_DWORD field_112; // 112, 448
	_DWORD field_113; // 113, 452
	_DWORD field_114; // 114, 456
	_DWORD field_115; // 115, 460
	_DWORD field_116; // 116, 464
	_DWORD field_117; // 117, 468
	_DWORD field_118; // 118, 472
	_DWORD field_119; // 119, 476
	_DWORD field_120; // 120, 480
	_DWORD field_121; // 121, 484
	_DWORD field_122; // 122, 488
	_DWORD field_123; // 123, 492
	_DWORD field_124; // 124, 496
	_DWORD field_125; // 125, 500
	_DWORD field_126; // 126, 504
	_DWORD field_127; // 127, 508
	_DWORD field_128; // 128, 512
	_DWORD field_129; // 129, 516
	_DWORD field_130; // 130, 520
	_DWORD field_131; // 131, 524
	_DWORD field_132; // 132, 528
	_DWORD field_133; // 133, 532
	_DWORD field_134; // 134, 536
	_DWORD field_135; // 135, 540
	_DWORD field_136; // 136, 544
	_DWORD field_137; // 137, 548
	_DWORD field_138; // 138, 552
	_DWORD field_139; // 139, 556
	_DWORD field_140; // 140, 560
	_DWORD field_141; // 141, 564
	_DWORD field_142; // 142, 568
	_DWORD field_143; // 143, 572
	_DWORD field_144; // 144, 576
	_DWORD field_145; // 145, 580
	_DWORD field_146; // 146, 584
	_DWORD field_147; // 147, 588
	_DWORD field_148; // 148, 592
	_DWORD field_149; // 149, 596
	_DWORD field_150; // 150, 600
	_DWORD field_151; // 151, 604
	_DWORD field_152; // 152, 608
	_DWORD field_153; // 153, 612
	_DWORD field_154; // 154, 616
	_DWORD field_155; // 155, 620
	_DWORD field_156; // 156, 624
	_DWORD field_157; // 157, 628
	_DWORD field_158; // 158, 632
	_DWORD field_159; // 159, 636
	_DWORD field_160; // 160, 640
	_DWORD field_161; // 161, 644
	_DWORD field_162; // 162, 648
	_DWORD field_163; // 163, 652
	_DWORD field_164; // 164, 656
	_DWORD field_165; // 165, 660
	_DWORD field_166; // 166, 664
	_DWORD field_167; // 167, 668
	_DWORD field_168; // 168, 672
	_DWORD field_169; // 169, 676
	_DWORD field_170; // 170, 680
	_DWORD field_171; // 171, 684
	_DWORD field_172; // 172, 688
	_DWORD field_173; // 173, 692
	_DWORD field_174; // 174, 696
	_DWORD field_175; // 175, 700
	_DWORD field_176; // 176, 704
	_DWORD field_177; // 177, 708
	_DWORD field_178; // 178, 712
	_DWORD field_179; // 179, 716
	_DWORD field_180; // 180, 720
	_DWORD field_181; // 181, 724
	_DWORD field_182; // 182, 728
	_DWORD field_183; // 183, 732
	_DWORD field_184; // 184, 736
	_DWORD field_185; // 185, 740
	_DWORD field_186; // 186, 744
	_DWORD field_187; // 187, 748
	_DWORD field_188; // 188, 752
	_DWORD field_189; // 189, 756
	_DWORD field_190; // 190, 760
	_DWORD field_191; // 191, 764
	_DWORD field_192; // 192, 768
	_DWORD field_193; // 193, 772
	_DWORD field_194; // 194, 776
	_DWORD field_195; // 195, 780
	_DWORD field_196; // 196, 784
	_DWORD field_197; // 197, 788
	_DWORD field_198; // 198, 792
	_DWORD field_199; // 199, 796
	_DWORD field_200; // 200, 800
	_DWORD field_201; // 201, 804
	_DWORD field_202; // 202, 808
	_DWORD field_203; // 203, 812
	_DWORD field_204; // 204, 816
	_DWORD field_205; // 205, 820
	_DWORD field_206; // 206, 824
	_DWORD field_207; // 207, 828
	_DWORD field_208; // 208, 832
	_DWORD field_209; // 209, 836
	_DWORD field_210; // 210, 840
	_DWORD field_211; // 211, 844
	_DWORD field_212; // 212, 848
	_DWORD field_213; // 213, 852
	_DWORD field_214; // 214, 856
	_DWORD field_215; // 215, 860
	_DWORD field_216; // 216, 864
	_DWORD field_217; // 217, 868
	_DWORD field_218; // 218, 872
	_DWORD field_219; // 219, 876
	_DWORD field_220; // 220, 880
	_DWORD field_221; // 221, 884
	_DWORD field_222; // 222, 888
	_DWORD field_223; // 223, 892
	_DWORD field_224; // 224, 896
	_DWORD field_225; // 225, 900
	_DWORD field_226; // 226, 904
	_DWORD field_227; // 227, 908
	_DWORD field_228; // 228, 912
	_DWORD field_229; // 229, 916
	_DWORD field_230; // 230, 920
	_DWORD field_231; // 231, 924
	_DWORD field_232; // 232, 928
	_DWORD field_233; // 233, 932
	_DWORD field_234; // 234, 936
	_DWORD field_235; // 235, 940
	_DWORD field_236; // 236, 944
	_DWORD field_237; // 237, 948
	_DWORD field_238; // 238, 952
	_DWORD field_239; // 239, 956
	_DWORD field_240; // 240, 960
	_DWORD field_241; // 241, 964
	_DWORD field_242; // 242, 968
	_DWORD field_243; // 243, 972
	_DWORD field_244; // 244, 976
	_DWORD field_245; // 245, 980
	_DWORD field_246; // 246, 984
	_DWORD field_247; // 247, 988
	_DWORD field_248; // 248, 992
	_DWORD field_249; // 249, 996
	_DWORD field_250; // 250, 1000
	_DWORD field_251; // 251, 1004
	_DWORD field_252; // 252, 1008
	_DWORD field_253; // 253, 1012
	_DWORD field_254; // 254, 1016
	_DWORD field_255; // 255, 1020
	_DWORD field_256; // 256, 1024
	_DWORD field_257; // 257, 1028
	_DWORD field_258; // 258, 1032
	_DWORD field_259; // 259, 1036
	_DWORD field_260; // 260, 1040
	_DWORD field_261; // 261, 1044
	_DWORD field_262; // 262, 1048
	_DWORD field_263; // 263, 1052
} nox_render_data_t;

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

typedef enum {
	NOX_GUI_ANIM_IN_DONE = 0,
	NOX_GUI_ANIM_OUT_DONE = 1,
	NOX_GUI_ANIM_OUT = 2,
	NOX_GUI_ANIM_IN = 3,
} nox_gui_anim_state;

typedef struct nox_gui_animation nox_gui_animation;
typedef struct nox_gui_animation {
	_DWORD field_0; // 0, 0
	nox_window* win; // 1, 4
	int x2; // 2, 8
	int y2; // 3, 12
	int x1; // 4, 16
	int y1; // 5, 20
	int out_dx; // 6, 24
	int out_dy; // 7, 28
	int in_dx; // 8, 32
	int in_dy; // 9, 36
	nox_gui_animation* next; // 10, 40
	nox_gui_animation* prev; // 11, 44
	int (*field_12)(void); // 12, 48
	int (*field_13)(void); // 13, 52
	int (*fnc_done_out)(void); // 14, 56
	void (*fnc_done_in)(void); // 15, 60
	nox_gui_anim_state state; // 16, 64
} nox_gui_animation;
_Static_assert(sizeof(nox_gui_animation) == 68, "wrong size of nox_gui_animation structure!");

typedef struct nox_list_item_t nox_list_item_t;
typedef struct nox_list_item_t {
	nox_list_item_t* field_0; // 0, 0
	nox_list_item_t* field_1; // 1, 4
	nox_list_item_t* field_2; // 2, 8
} nox_list_item_t;
_Static_assert(sizeof(nox_list_item_t) == 12, "wrong size of nox_list_item_t structure!");

typedef struct nox_map_list_item nox_map_list_item;
typedef struct nox_map_list_item {
	nox_list_item_t list; // 0, 0
	char name[12]; // 3, 12
	int field_6; // 6, 24
	_DWORD field_7; // 7, 28
	unsigned char field_8_0; // 8, 32
	unsigned char field_8_1; // 8, 33
	_WORD field_8_2; // 8, 34
} nox_map_list_item;
_Static_assert(sizeof(nox_map_list_item) == 36, "wrong size of nox_map_list_item structure!");

typedef struct nox_draw_viewport_t {
	int x1; // 0, 0
	int y1; // 1, 4
	int x2; // 2, 8
	int y2; // 3, 12
	int field_4; // 4, 16
	int field_5; // 5, 20
	int field_6; // 6, 24
	int field_7; // 7, 28
	int width;  // 8, 32
	int height; // 9, 36
	_DWORD field_10; // 10, 40
	_DWORD field_11; // 11, 44
	int field_12; // 12, 48
} nox_draw_viewport_t;
_Static_assert(sizeof(nox_draw_viewport_t) == 52, "wrong size of nox_draw_viewport_t structure!");

#define NOX_PLAYERINFO_MAX 32
typedef struct nox_playerInfo {
	_DWORD data_0[100];
	_DWORD data_400[100];
	_DWORD data_800[100];
	_DWORD data_1200[100];
	_DWORD data_1600[100];
	_DWORD data_2000[8];
	_DWORD data_2032[4];
	_DWORD data_2048[2];
	nox_object_t* playerUnit; // 514, 2056
	unsigned int netCode; // 515, 2060
	unsigned char playerInd; // 516, 2064
	_BYTE field_2064_1; // 516, 2065
	_WORD field_2064_2; // 516, 2066
	_DWORD field_2068; // 517
	wchar_t field_2072[10]; // 518, 2072
	unsigned int active; // 523, 2092
	char field_2096[16]; // 524, 2096
	_DWORD data_2112[22]; // 2112 is a string buf, 2185 is wchar_t buf
	_DWORD data_2200[10];
	_DWORD field_2240;
	_DWORD field_2244;
	_WORD field_2248; // 562, 2248
	_BYTE field_2250; // 562, 2250
	_BYTE playerClass; // 562, 2251
	_DWORD field_2252;
	_DWORD field_2256;
	_DWORD data_2260[5];
	_DWORD data_2280[5];
	_DWORD data_2300[25]; // 2352 is wchar_t buf
	_DWORD data_2400[100];
	_DWORD data_2800[100];
	_DWORD data_3200[50];
	_DWORD data_3400[25];
	_DWORD data_3500[20];
	_DWORD field_3580;
	_DWORD field_3584;
	_DWORD field_3588;
	_DWORD field_3592;
	unsigned int frame_3596;
	_DWORD data_3600[12];
	_DWORD field_3648;
	_DWORD field_3652;
	_DWORD field_3656;
	_DWORD field_3660;
	_DWORD field_3664;
	_DWORD field_3668;
	_DWORD field_3672;
	_BYTE field_3676;
	_BYTE field_3676_1;
	_WORD field_3676_2;
	_DWORD field_3680;
	_DWORD data_3684[4];
	_DWORD data_3700[25];
	_DWORD data_3800[50];
	_DWORD data_4000[100];
	_DWORD data_4400[25];
	_DWORD data_4500[20];
	_DWORD field_4580;
	_DWORD data_4584[4];
	_DWORD data_4600[50]; // 4704 is wchar_t buf
	_DWORD data_4800[7];
} nox_playerInfo;
_Static_assert(sizeof(nox_playerInfo) == 4828, "wrong size of nox_playerInfo structure!");
_Static_assert(offsetof(nox_playerInfo, frame_3596) == 3596, "wrong offset of nox_playerInfo.frame_3596 field!");
_Static_assert(offsetof(nox_playerInfo, field_4580) == 4580, "wrong offset of nox_playerInfo.field_4580 field!");

#define NOX_SPELLS_MAX 137
typedef struct nox_spell_t {
	wchar_t* title; // 0, 0
	wchar_t* desc; // 1, 4
	void* icon; // 2, 8
	void* icon_enabled; // 3, 12
	unsigned int flags; // 4, 16
	unsigned int enabled; // 5, 20
	unsigned int valid; // 6, 24
	char phonemes[32]; // 7, 28
	_BYTE field_15_0; // 15, 60
	_BYTE phonemes_cnt; // 15, 61
	unsigned char mana_cost; // 15, 62
	_BYTE field_15_3; // 15, 63
	unsigned short price; // 16, 64
	_WORD field_16_1; // 16, 66
	void* cast_sound; // 17, 68
	void* on_sound; // 18, 72
	void* off_sound; // 19, 76
} nox_spell_t;
_Static_assert(sizeof(nox_spell_t) == 80, "wrong size of nox_spell_t structure!");

typedef enum {
	NOX_ENGINE_FLAG_1 = 1u << 0u,
	NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS = 1u << 1u,
	NOX_ENGINE_FLAG_3 = 1u << 2u,
	NOX_ENGINE_FLAG_ENABLE_SHOW_AI = 1u << 3u,
	NOX_ENGINE_FLAG_ADMIN = 1u << 4u,
	NOX_ENGINE_FLAG_GODMODE = 1u << 5u,
	NOX_ENGINE_FLAG_7 = 1u << 6u,
	NOX_ENGINE_FLAG_8 = 1u << 7u,
	NOX_ENGINE_FLAG_9 = 1u << 8u,
	NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE = 1u << 9u,
	NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE = 1u << 10u,
	NOX_ENGINE_DISABLE_SOFT_LIGHTS = 1u << 11u,
	NOX_ENGINE_FLAG_GAMELOOP_MEMDUMP = 1u << 12u,
	NOX_ENGINE_FLAG_14 = 1u << 13u,
	NOX_ENGINE_FLAG_15 = 1u << 14u,
	NOX_ENGINE_FLAG_ENABLE_NET_DEBUG = 1u << 15u,
	NOX_ENGINE_FLAG_DISABLE_TEXT_RENDERING = 1u << 16u,
	NOX_ENGINE_FLAG_18 = 1u << 17u,
	NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING = 1u << 18u,
	NOX_ENGINE_FLAG_20 = 1u << 19u,
	NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING = 1u << 20u,
	NOX_ENGINE_FLAG_REPLAY_WRITE = 1u << 21u,
	NOX_ENGINE_FLAG_REPLAY_READ = 1u << 22u,
	NOX_ENGINE_FLAG_LOG_TO_FILE = 1u << 23u,
	NOX_ENGINE_FLAG_LOG_TO_CONSOLE = 1u << 24u,
	NOX_ENGINE_FLAG_LOCK_VIDEO_RESOLUTION = 1u << 25u,
	NOX_ENGINE_FLAG_27 = 1u << 26u,
	NOX_ENGINE_FLAG_SAVE_DEBUG = 1u << 27u,
	NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST = 1u << 28u,
	NOX_ENGINE_FLAG_LOG_BAND = 1u << 29u,
	NOX_ENGINE_FLAG_SLEEP = 1u << 30u,
	NOX_ENGINE_FLAG_PAUSE = 1u << 31u,
} nox_engine_flag;

#pragma pack(push,1)
typedef struct nox_gui_server_ent_t {
	_DWORD field_0; // 0, 0
	_DWORD field_1; // 1, 4
	int sort_key; // 2, 8
	char addr[16]; // 3, 12
	int field_7; // 7, 28
	_DWORD field_8; // 8, 32
	_DWORD field_9; // 9, 36, TODO: server index?
	_DWORD field_10; // 10, 40
	short field_11_0; // 11, 44
	short field_11_2; // 11, 46
	_DWORD field_12; // 12, 48
	_DWORD field_13; // 13, 52
	_DWORD field_14; // 14, 56
	_DWORD field_15; // 15, 60
	_DWORD field_16; // 16, 64
	_DWORD field_17; // 17, 68
	_DWORD field_18; // 18, 72
	_DWORD field_19; // 19, 76
	_DWORD field_20; // 20, 80
	_DWORD field_21; // 21, 84
	_DWORD field_22; // 22, 88
	_DWORD field_23; // 23, 92
	int ping; // 24, 96
	unsigned char status; // 25, 100
	_BYTE field_25_1; // 25, 101
	_BYTE field_25_2; // 25, 102
	unsigned char players; // 25, 103
	unsigned char max_players; // 26, 104
	_WORD field_26_1; // 26, 105
	_WORD field_26_3; // 26, 107
	unsigned short port; // 27, 109
	char map_name[9]; // 27, 111
	char server_name[15]; // 30, 120
	unsigned char field_33_3[20]; // 33, 135, TODO: [20]byte
	_DWORD field_38_3; // 38, 155
	_DWORD field_39_3; // 39, 159
	unsigned short flags; // 40, 163
	unsigned short quest_level; // 41, 165
	_BYTE field_41_3; // 41, 167
	_BYTE field_42; // 42, 168
} nox_gui_server_ent_t;
#pragma pack(pop)
_Static_assert(sizeof(nox_gui_server_ent_t) == 169, "wrong size of nox_gui_server_ent_t structure!");

#endif
