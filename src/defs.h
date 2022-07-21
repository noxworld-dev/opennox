#ifndef NOX_DEFS_H
#define NOX_DEFS_H

#include "memfile.h"
#include "nox_net.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

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

#include "common/platform/platform.h"
#include "memmap.h"

#include "nox_wchar.h"
#include "noxstring.h"
#include "static_assert.h"

#include "client__gui__window.h"
#include "common/alloc/classes/alloc_class.h"

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

void nox_exit(int exitCode);

// saturating 8-bit addition
static uint8_t SADD8(uint8_t x, uint8_t y) {
	unsigned int z = x + y;
	return z > 0xFF ? 0xFF : (uint8_t)z;
}

#define abs32 abs

static void memset32(uint32_t* x, uint32_t y, size_t z) {
	while (z--)
		*x++ = y;
}

#define __ROL4__ _rotl

static void* operator_new(size_t x) { return calloc(1, x); }

static void operator_delete(void* x) { free(x); }

static uint16_t __ROL2__(uint16_t x, int shift) {
	if (shift == 0)
		return x;
	if (shift == 16)
		return x;
	return (uint16_t)((x << shift) | (x >> (16 - shift)));
}

static float COERCE_FLOAT(uint32_t x) { return *(float*)&x; }

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
	int min_x;
	int min_y;
	int max_x;
	int max_y;
} nox_rect;

static inline int noxCopyRect(nox_rect* lprcDst, const nox_rect* lprcSrc) {
	*lprcDst = *lprcSrc;
	return true;
}
static inline int noxSetRect(nox_rect* lprc, int xLeft, int yTop, int xRight, int yBottom) {
	lprc->min_x = xLeft;
	lprc->min_y = yTop;
	lprc->max_x = xRight;
	lprc->max_y = yBottom;
	return true;
}

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
	uintptr_t field_0;
	uintptr_t field_4;
	int field_8;
	int field_C;
	int field_10;
} struc_35;

typedef struct nox_video_bag_image_t nox_video_bag_image_t;
int nox_video_bag_image_type(nox_video_bag_image_t* img);

typedef struct nox_thing nox_thing;
typedef struct nox_drawable nox_drawable;

typedef struct nox_thing {
	char* name;                                 // 0, 0x0
	wchar_t* pretty_name;                       // 1, 0x4, 4
	wchar_t* desc;                              // 2, 0x8, 8
	uint8_t hwidth;                             // 3, 0xc, 12
	uint8_t hheight;                            // 3, 0xd, 13
	uint8_t weight;                             // 3, 0xe, 14
	uint8_t field_f;                            // 3, 0xf, 15
	uint32_t field_10;                          // 4, 0x10, 16
	uint16_t shape_kind;                        // 5, 0x14, 20
	uint16_t z;                                 // 5, 0x16, 22
	uint16_t light_dir;                         // 6, 0x18, 24
	uint16_t light_penumbra;                    // 6, 0x1a, 26
	int field_1c;                               // 7, 0x1c, 28, ID? index?
	unsigned int pri_class;                     // 8, 0x20, 32
	uint32_t sub_class;                         // 9, 0x24, 36
	int flags;                                  // 10, 0x28, 40
	float light_intensity;                      // 11, 0x2c, 44
	int light_color_r;                          // 12, 0x30, 48
	int light_color_g;                          // 13, 0x34, 52
	int light_color_b;                          // 14, 0x38, 56
	uint32_t field_3c;                          // 15, 0x3c
	float shape_r;                              // 16, 0x40
	float zsize_min;                            // 17, 0x44, 68
	float zsize_max;                            // 18, 0x48, 72
	float shape_w;                              // 19, 0x4c
	float shape_h;                              // 20, 0x50
	uint32_t field_54;                          // 21, 0x54
	int (*draw_func)(uint32_t*, nox_drawable*); // 22, 0x58, 88, same as nox_drawable->draw_func
	void* field_5c;                             // 23, 0x5c, 92
	uint32_t field_60;                          // 24, 0x60
	uint32_t client_update;                     // 25, 0x64, 100
	uint32_t audio_loop;                        // 26, 0x68, 104
	nox_thing* next;                            // 27, 0x6c, 108
	uint32_t pretty_image;                      // 28, 0x70, 112
	uint32_t menuicon;                          // 29, 0x74, 116
	int lifetime;                               // 30, 0x78, 120
	uint16_t health;                            // 31, 0x7c, 124
	uint16_t field_7e;                          // 31, 0x7e, 126
} nox_thing;
_Static_assert(sizeof(nox_thing) == 128, "wrong size of nox_thing structure!");

typedef struct nox_objectType_t nox_objectType_t;
typedef struct nox_object_t nox_object_t;
typedef struct nox_playerInfo nox_playerInfo;

typedef struct nox_objectType_t {
	unsigned short ind;       // 0, 0
	unsigned short field_0_1; // 0, 2
	const char* id;           // 1, 4
	uint32_t field_2;         // 2, 8
	int menu_icon;            // 3, 12
	unsigned int field_4;     // 4, 16
	uint16_t field_5_0;       // 5, 20
	uint16_t field_5_1;       // 5, 22
	unsigned int obj_class;   // 6, 24
	unsigned int obj_subclass;// 7, 28
	unsigned int obj_flags;   // 8, 32
	uint32_t field_9;         // 9, 36
	uint16_t material;        // 10, 40
	uint16_t field_10_1;      // 10, 42
	float experience;         // 11, 44
	uint32_t worth;           // 12, 48
	float field_13;           // 13, 52
	float mass;               // 14, 56
	nox_shape shape;          // 15, 60
	float zsize1;             // 28, 112
	float zsize2;             // 29, 116
	uint8_t weight;           // 30, 120
	uint8_t field_30_1;       // 30, 121
	uint16_t carry_capacity;  // 30, 122
	float speed;              // 31, 124
	float speed_2;            // 32, 128
	float float_33;           // 33, 132
	void* data_34;            // 34, 136, TODO: data, *[20]byte
	void* func_collide;       // 35, 140
	void* collide_data;       // 36, 144
	int   collide_data_size;  // 37, 148
	void* func_damage;        // 38, 152
	void* func_damage_sound;  // 39, 156
	void* func_die;           // 40, 160
	void* die_data;           // 41, 164
	void* func_drop;          // 42, 168
	void* func_init;          // 43, 172
	void* init_data;          // 44, 176
	int   init_data_size;     // 45, 180
	void* func_pickup;        // 46, 184
	void (*func_update)(nox_object_t*); // 47, 188
	void* data_update;          // 48, 192
	int   data_update_size;     // 49, 196
	void* func_use;             // 50, 200
	void* use_data;             // 51, 204
	int   use_data_size;        // 52, 208
	void* func_xfer;          // 53, 212
	void (*func_new)(void*);  // 54, 216
	nox_objectType_t* next;   // 55, 220
} nox_objectType_t;
_Static_assert(sizeof(nox_objectType_t) == 224, "wrong size of nox_objectType_t structure!");

typedef struct nox_object_t {
	const char* id;          // 0, 0
	unsigned short typ_ind;  // 1, 4
	uint16_t field_1_2;      // 1, 6
	unsigned int obj_class;  // 2, 8
	unsigned int obj_subclass; // 3, 12
	unsigned int obj_flags;  // 4, 16
	uint32_t field_5;        // 5, 20
	uint16_t material;       // 6, 24
	uint16_t field_6_2;      // 6, 26
	float experience;        // 7, 28
	uint32_t worth;          // 8, 32
	uint32_t field_9;        // 9, 36, TODO: some frame/timestamp
	unsigned int extent;     // 10, 40
	int script_id;           // 11, 44
	uint32_t field_12;       // 12, 48
	uint32_t field_13;       // 13, 52, // TODO: first byte is team?
	float x;                 // 14, 56
	float y;                 // 15, 60
	float new_x;             // 16, 64
	float new_y;             // 17, 68
	float prev_x;            // 18, 72
	float prev_y;            // 19, 76
	float vel_x;             // 20, 80
	float vel_y;             // 21, 84
	float force_x;           // 22, 88
	float force_y;           // 23, 92
	float float_24;          // 24, 96, // TODO: something related to acceleration/direction
	float float_25;          // 25, 100, // TODO: something related to acceleration/direction
	uint32_t field_26;       // 26, 104
	uint32_t field_27;       // 27, 108
	float float_28;          // 28, 112, // TODO: damping/drag?
	uint32_t field_29;       // 29, 116
	float mass;              // 30, 120
	uint16_t field_31_0;     // 31, 124, // TODO: 124 is set to value of 126 in at least 51B100
	uint16_t direction;      // 31, 126, // TODO: 126 accessed as word in at least 51B100, probably direction
	uint32_t field_32;       // 32, 128
	uint32_t field_33;       // 33, 132
	uint32_t field_34;       // 34, 136, TODO: some frame/timestamp
	uint32_t field_35;       // 35, 140
	uint32_t field_36;       // 36, 144
	uint32_t field_37;       // 37, 148
	int field_38;            // 38, 152
	float float_39;          // 39, 156
	float float_40;          // 40, 160
	uint32_t field_41;       // 41, 164
	uint32_t field_42;       // 42, 168
	nox_shape shape;         // 43, 172
	float zsize1;            // 56, 224
	float zsize2;            // 57, 228
	float collide_x1;        // 58, 232
	float collide_y1;        // 59, 236
	float collide_x2;        // 60, 240
	float collide_y2;        // 61, 244
	uint32_t field_62;       // 62, 248
	uint32_t field_63;       // 63, 252
	uint32_t field_64;       // 64, 256
	uint32_t field_65;       // 65, 260
	uint32_t field_66;       // 66, 264
	uint32_t field_67;       // 67, 268
	uint32_t field_68;       // 68, 272
	uint32_t field_69;       // 69, 276
	uint32_t field_70;       // 70, 280
	uint32_t field_71;       // 71, 284
	uint32_t field_72;       // 72, 288
	uint32_t field_73;       // 73, 292
	uint32_t field_74;       // 74, 296
	uint32_t field_75;       // 75, 300
	uint32_t field_76;       // 76, 304
	uint32_t field_77;       // 77, 308
	uint32_t field_78;       // 78, 312
	uint32_t field_79;       // 79, 316
	uint32_t field_80;       // 80, 320
	uint32_t field_81;       // 81, 324
	uint32_t field_82;       // 82, 328
	uint32_t field_83;       // 83, 332
	uint32_t field_84;       // 84, 336
	uint32_t buffs;          // 85, 340
	uint16_t buffs_dur[32];  // 86, 344
	uint8_t  buffs_power[32];// 102, 408
	uint32_t field_110;      // 110, 440
	void* field_111;         // 111, 444
	uint32_t field_112;      // 112, 448
	uint32_t field_113;      // 113, 452
	uint32_t field_114;      // 114, 456
	uint32_t field_115;      // 115, 460
	uint32_t field_116;      // 116, 464
	uint32_t field_117;      // 117, 468
	uint32_t field_118;      // 118, 472
	uint32_t field_119;      // 119, 476
	uint32_t field_120;      // 120, 480
	uint32_t field_121;      // 121, 484
	uint8_t weight;          // 122, 488
	uint8_t field_122_1;     // 122, 489
	uint16_t carry_capacity; // 122, 490
	uint32_t field_123;      // 123, 492 // Also health data, possibly same as 556, see 4E4560
	nox_object_t* field_124; // 124, 496, TODO: next item
	void* field_125;         // 125, 500, TODO: a nox_object_t*? see 4ED0C0
	nox_object_t* field_126; // 126, 504, TODO: first item
	nox_object_t* owner;     // 127, 508
	void* field_128;         // 128, 512
	void* field_129;         // 129, 516
	nox_object_t* obj_130;   // 130, 520
	uint32_t field_131;      // 131, 524
	uint32_t field_132;      // 132, 528
	uint32_t field_133;      // 133, 532
	uint32_t field_134;      // 134, 536, TODO: some timestamp
	uint32_t field_135;      // 135, 540, TODO: 541 accessed as byte
	float speed_cur;         // 136, 544
	float speed_2;           // 137, 548
	float float_138;         // 138, 552
	void* data_139;          // 139, 556, TODO: data, *[20]byte, related to health and damage
	uint32_t field_140;      // 140, 560
	uint32_t field_141;      // 141, 564
	uint32_t field_142;      // 142, 568
	uint32_t field_143;      // 143, 572
	uint32_t field_144;      // 144, 576
	uint32_t field_145;      // 145, 580
	uint32_t field_146;      // 146, 584
	uint32_t field_147;      // 147, 588
	uint32_t field_148;      // 148, 592
	uint32_t field_149;      // 149, 596
	uint32_t field_150;      // 150, 600
	uint32_t field_151;      // 151, 604
	uint32_t field_152;      // 152, 608
	uint32_t field_153;      // 153, 612
	uint32_t field_154;      // 154, 616
	uint32_t field_155;      // 155, 620
	uint32_t field_156;      // 156, 624
	uint32_t field_157;      // 157, 628
	uint32_t field_158;      // 158, 632
	uint32_t field_159;      // 159, 636
	uint32_t field_160;      // 160, 640
	uint32_t field_161;      // 161, 644
	uint32_t field_162;      // 162, 648
	uint32_t field_163;      // 163, 652
	uint32_t field_164;      // 164, 656
	uint32_t field_165;      // 165, 660
	uint32_t field_166;      // 166, 664
	uint32_t field_167;      // 167, 668
	uint32_t field_168;      // 168, 672
	uint32_t field_169;      // 169, 676
	uint32_t field_170;      // 170, 680
	uint32_t field_171;      // 171, 684
	void* func_init;         // 172, 688
	void* init_data;         // 173, 692, // TODO: struct pointer; struct at least 8 bytes wide. see 4F3030.
	void* func_collide;      // 174, 696
	void* collide_data;      // 175, 700
	int (*func_xfer)(nox_object_t*, int); // 176, 704
	void* func_pickup;       // 177, 708
	void* func_drop;         // 178, 712
	int (*func_damage)(nox_object_t*, nox_object_t*, int, int, int); // 179, 716
	void* func_damage_sound; // 180, 720
	void* func_die;          // 181, 724
	void* die_data;          // 182, 728
	void* func_use;          // 183, 732
	void* use_data;          // 184, 736
	uint32_t field_185;      // 185, 740
	void (*func_update)(nox_object_t*); // 186, 744
	void* data_update;       // 187, 748
	uint32_t field_188;      // 188, 752
	uint32_t field_189;      // 189, 756
	uint32_t field_190;      // 190, 760
	uint32_t field_191;      // 191, 764
	int field_192;           // 192, 768
} nox_object_t;
_Static_assert(sizeof(nox_object_t) == 772, "wrong size of nox_object_t structure!");

typedef struct {
	uint32_t field_0; // 0, 0
	uint16_t mana_cur; // 1, 4
	uint16_t mana_prev; // 1, 6
	uint16_t mana_max; // 2, 8
	uint16_t field_2_1; // 2, 10
	uint32_t field_3; // 3, 12
	uint32_t field_4; // 4, 16
	uint32_t field_5; // 5, 20
	uint32_t field_6; // 6, 24
	uint32_t field_7; // 7, 28
	uint32_t field_8; // 8, 32
	uint32_t field_9; // 9, 36
	uint32_t field_10; // 10, 40
	uint32_t field_11; // 11, 44
	uint32_t field_12; // 12, 48
	uint32_t field_13; // 13, 52
	uint32_t field_14; // 14, 56
	uint32_t field_15; // 15, 60
	uint32_t field_16; // 16, 64
	uint32_t field_17; // 17, 68
	uint32_t field_18; // 18, 72
	uint16_t field_19_0; // 19, 76
	uint16_t field_19_1; // 19, 78
	uint16_t field_20_0; // 20, 80
	uint16_t field_20_1; // 20, 82
	uint32_t field_21; // 21, 84
	uint8_t field_22_0; // 22, 88, TODO: player unit state?
	uint8_t field_22_1; // 22, 89
	uint8_t field_22_2; // 22, 90
	uint8_t field_22_3; // 22, 91
	uint32_t field_23; // 23, 92
	uint32_t field_24; // 24, 96
	uint32_t field_25; // 25, 100
	uint32_t field_26; // 26, 104
	uint32_t field_27; // 27, 108
	uint32_t field_28; // 28, 112
	nox_object_t* field_29[4]; // 29, 116, TODO: teleport markers? traps?
	nox_object_t* harpoon_targ; // 33, 132
	nox_object_t* harpoon_bolt; // 34, 136
	uint32_t harpoon_35; // 35, 140
	float harpoon_targ_x; // 36, 144
	float harpoon_targ_y; // 37, 148
	uint32_t harpoon_frame; // 38, 152
	uint32_t field_39; // 39, 156
	uint16_t field_40_0; // 40, 160
	uint16_t field_40_1; // 40, 162
	uint32_t field_41; // 41, 164
	uint32_t field_42; // 42, 168
	uint32_t field_43; // 43, 172
	uint32_t field_44; // 44, 176
	uint32_t field_45; // 45, 180
	void* spell_phoneme_leaf; // 46, 184
	uint8_t field_47_0; // 47, 188
	uint8_t field_47_1; // 47, 189
	uint16_t field_47_2; // 47, 190
	uint32_t field_48; // 48, 192
	uint32_t field_49; // 49, 196
	uint32_t field_50; // 50, 200
	uint32_t field_51; // 51, 204
	uint32_t field_52; // 52, 208
	uint32_t field_53; // 53, 212
	uint32_t field_54; // 54, 216, TODO: (manual?) casting timestamp
	int field_55; // 55, 220, TODO: spell-related? x coord?
	int field_56; // 56, 224, TODO: spell-related? y coord?
	uint32_t field_57; // 57, 228
	uint32_t field_58; // 58, 232
	uint8_t field_59_0; // 59, 236, TODO: frame index?
	uint8_t field_59_1; // 59, 237
	uint16_t field_59_2; // 59, 238
	uint32_t field_60; // 60, 240, TODO: some flags?
	uint32_t field_61; // 61, 244
	uint32_t field_62; // 62, 248
	uint32_t field_63; // 63, 252
	uint32_t field_64; // 64, 256
	uint32_t field_65; // 65, 260
	uint32_t field_66; // 66, 264
	uint32_t field_67; // 67, 268
	uint32_t field_68; // 68, 272
	nox_playerInfo* player; // 69, 276
	uint32_t field_70; // 70, 280
	uint32_t field_71; // 71, 284
	nox_object_t* cursor_obj; // 72, 288
	uint32_t field_73; // 73, 292
	uint32_t field_74; // 74, 296
	uint32_t field_75; // 75, 300
	uint32_t field_76; // 76, 304
	void* field_77; // 77, 308
	uint32_t field_78; // 78, 312
	uint32_t field_79; // 79, 316
	uint32_t field_80; // 80, 320
	uint32_t field_81; // 81, 324
	uint32_t field_82; // 82, 328
	uint32_t field_83; // 83, 332
	uint32_t field_84; // 84, 336
	uint32_t field_85; // 85, 340
	uint32_t field_86; // 86, 344
	uint32_t field_87; // 87, 348
	uint32_t field_88; // 88, 352
	uint32_t field_89; // 89, 356
	uint32_t field_90; // 90, 360
	uint32_t field_91; // 91, 364
	uint32_t field_92; // 92, 368
	uint32_t field_93; // 93, 372
	uint32_t field_94; // 94, 376
	uint32_t field_95; // 95, 380
	uint32_t field_96; // 96, 384
	uint32_t field_97; // 97, 388
	uint32_t field_98; // 98, 392
	uint32_t field_99; // 99, 396
	uint32_t field_100; // 100, 400
	uint32_t field_101; // 101, 404
	uint32_t field_102; // 102, 408
	uint32_t field_103; // 103, 412
	uint32_t field_104; // 104, 416
	uint32_t field_105; // 105, 420
	uint32_t field_106; // 106, 424
	uint32_t field_107; // 107, 428
	uint32_t field_108; // 108, 432
	uint32_t field_109; // 109, 436
	uint32_t field_110; // 110, 440
	uint32_t field_111; // 111, 444
	uint32_t field_112; // 112, 448
	uint32_t field_113; // 113, 452
	uint32_t field_114; // 114, 456
	uint32_t field_115; // 115, 460
	uint32_t field_116; // 116, 464
	uint32_t field_117; // 117, 468
	uint32_t field_118; // 118, 472
	uint32_t field_119; // 119, 476
	uint32_t field_120; // 120, 480
	uint32_t field_121; // 121, 484
	uint32_t field_122; // 122, 488
	uint32_t field_123; // 123, 492
	uint32_t field_124; // 124, 496
	uint32_t field_125; // 125, 500
	uint32_t field_126; // 126, 504
	uint32_t field_127; // 127, 508
	uint32_t field_128; // 128, 512
	uint32_t field_129; // 129, 516
	uint32_t field_130; // 130, 520
	uint32_t field_131; // 131, 524
	uint32_t field_132; // 132, 528
	uint32_t field_133; // 133, 532
	uint32_t field_134; // 134, 536
	uint32_t field_135; // 135, 540
	uint32_t field_136; // 136, 544
	uint32_t field_137; // 137, 548, TODO: some timestamp
	uint32_t field_138; // 138, 552
} nox_object_Player_data_t;
_Static_assert(sizeof(nox_object_Player_data_t) == 556, "wrong size of nox_object_Player_data_t structure!");

typedef struct {
	nox_object_t* owner; // 0, 0
	nox_object_t* target; // 1, 4
	uint32_t field_8; // 2, 8
	int spellID; // 3, 12
	uint32_t field_16; // 4, 16
	uint32_t field_20; // 5, 20
	uint32_t field_24; // 6, 24
} nox_object_Missile_data_t;
_Static_assert(sizeof(nox_object_Missile_data_t) == 28, "wrong size of nox_object_Missile_data_t structure!");

typedef struct {
	uint32_t action; // 0, 0
	uint32_t arg_1; // 1, 4
	uint32_t arg_2; // 2, 8
	uint32_t arg_3; // 3, 12
	uint32_t arg_4; // 4, 16
	uint32_t field_5; // 5, 20
} nox_ai_stack_t;
_Static_assert(sizeof(nox_ai_stack_t) == 24, "wrong size of nox_ai_stack_t structure!");

typedef struct {
	uint32_t field_0; // 0, 0
	uint32_t field_1; // 1, 4
	uint32_t field_2; // 2, 8
	uint32_t field_3; // 3, 12
	uint32_t field_4; // 4, 16
	uint32_t field_5; // 5, 20
	uint32_t field_6; // 6, 24
	uint32_t field_7; // 7, 28
	uint32_t field_8; // 8, 32
	uint32_t field_9; // 9, 36
	uint32_t field_10; // 10, 40
	uint32_t field_11; // 11, 44
	uint32_t field_12; // 12, 48
	uint32_t field_13; // 13, 52
	uint32_t field_14; // 14, 56
	uint32_t field_15; // 15, 60
	uint32_t field_16; // 16, 64
	uint32_t field_17; // 17, 68
	uint32_t field_18; // 18, 72
	uint32_t field_19; // 19, 76
	uint32_t field_20; // 20, 80
	uint32_t field_21; // 21, 84
	uint32_t field_22; // 22, 88
	uint32_t field_23; // 23, 92
	uint32_t field_24; // 24, 96
	uint32_t field_25; // 25, 100
	uint32_t field_26; // 26, 104
	uint32_t field_27; // 27, 108
	uint32_t field_28; // 28, 112
	uint32_t field_29; // 29, 116
	uint32_t field_30; // 30, 120
	uint32_t field_31; // 31, 124
	uint32_t field_32; // 32, 128
	uint32_t field_33; // 33, 132
	uint32_t field_34; // 34, 136
	uint32_t field_35; // 35, 140
	uint32_t field_36; // 36, 144
	uint32_t field_37; // 37, 148
	uint32_t field_38; // 38, 152
	uint32_t field_39; // 39, 156
	uint32_t field_40; // 40, 160
	uint32_t field_41; // 41, 164
	uint32_t field_42; // 42, 168
	uint32_t field_43; // 43, 172
	uint32_t field_44; // 44, 176
	uint32_t field_45; // 45, 180
	uint32_t field_46; // 46, 184
	uint32_t field_47; // 47, 188
	uint32_t field_48; // 48, 192
	uint32_t field_49; // 49, 196
	uint32_t field_50; // 50, 200
	uint32_t field_51; // 51, 204
	uint32_t field_52; // 52, 208
	uint32_t field_53; // 53, 212
	uint32_t field_54; // 54, 216
	uint32_t field_55; // 55, 220
	uint32_t field_56; // 56, 224
	uint32_t field_57; // 57, 228
	uint32_t field_58; // 58, 232
	uint32_t field_59; // 59, 236
	uint32_t field_60; // 60, 240
	uint32_t field_61; // 61, 244
	uint32_t field_62; // 62, 248
	uint32_t field_63; // 63, 252
	uint32_t field_64; // 64, 256
	uint32_t field_65; // 65, 260
	uint32_t field_66; // 66, 264
	uint32_t field_67; // 67, 268
	uint32_t field_68; // 68, 272
	uint32_t field_69; // 69, 276
	uint32_t field_70; // 70, 280
	uint32_t field_71; // 71, 284
	uint32_t field_72; // 72, 288
	uint32_t field_73; // 73, 292
	uint32_t field_74; // 74, 296
	uint32_t field_75; // 75, 300
	uint32_t field_76; // 76, 304
	uint32_t field_77; // 77, 308
	uint32_t field_78; // 78, 312
	uint32_t field_79; // 79, 316
	uint32_t field_80; // 80, 320
	uint32_t field_81; // 81, 324
	uint32_t field_82; // 82, 328
	uint32_t field_83; // 83, 332
	uint32_t field_84; // 84, 336
	uint32_t field_85; // 85, 340
	uint32_t field_86; // 86, 344
	uint32_t field_87; // 87, 348
	uint32_t field_88; // 88, 352
	uint32_t field_89; // 89, 356
	uint32_t field_90; // 90, 360
	uint32_t field_91; // 91, 364
	uint32_t field_92; // 92, 368
	uint32_t field_93; // 93, 372
	uint32_t field_94; // 94, 376
	uint32_t field_95; // 95, 380
	uint32_t field_96; // 96, 384
	uint32_t field_97; // 97, 388, TODO: hear sound ind
	uint32_t field_98; // 98, 392, TODO: some frame/timestamp
	float field_99_x;  // 99, 396
	float field_99_y;  // 100, 400
	uint32_t field_101; // 101, 404, TODO: hear frame/timestamp
	uint32_t field_102; // 102, 408, TODO: hear distance
	uint32_t field_103; // 103, 412
	uint32_t field_104; // 104, 416
	uint32_t field_105; // 105, 420
	uint32_t field_106; // 106, 424
	uint32_t field_107; // 107, 428
	uint32_t field_108; // 108, 432
	uint32_t field_109; // 109, 436
	uint32_t field_110; // 110, 440
	uint32_t field_111; // 111, 444
	uint32_t field_112; // 112, 448
	uint32_t field_113; // 113, 452
	uint32_t field_114; // 114, 456
	uint32_t field_115; // 115, 460
	uint32_t field_116; // 116, 464
	uint32_t field_117; // 117, 468
	uint32_t field_118; // 118, 472
	void* field_119; // 119, 476
	uint32_t field_120; // 120, 480
	void* field_121; // 121, 484
	uint32_t field_122; // 122, 488
	uint32_t field_123; // 123, 492
	uint32_t field_124; // 124, 496
	uint32_t field_125; // 125, 500
	uint32_t field_126; // 126, 504
	uint32_t field_127; // 127, 508
	uint32_t field_128; // 128, 512
	uint32_t field_129; // 129, 516, TODO: some timestamp
	uint32_t field_130; // 130, 520
	uint32_t field_131; // 131, 524
	uint32_t field_132; // 132, 528
	uint32_t field_133; // 133, 532
	uint32_t field_134; // 134, 536
	uint32_t field_135; // 135, 540
	char ai_stack_ind;  // 136, 544
	uint8_t field_136_1;  // 136, 545
	uint16_t field_136_2; // 136, 546
	uint32_t field_137; // 137, 548
	nox_ai_stack_t ai_stack[24]; // 138, 552
	uint8_t field_282_0; // 282, 1128, TODO: current stamina?
	uint8_t field_282_1; // 282, 1129
	uint16_t field_282_2; // 282, 1130
	uint32_t field_283; // 283, 1132
	uint32_t field_284; // 284, 1136
	uint32_t field_285; // 285, 1140
	uint32_t field_286; // 286, 1144
	uint32_t field_287; // 287, 1148
	uint32_t field_288; // 288, 1152
	uint32_t field_289; // 289, 1156
	uint32_t field_290; // 290, 1160
	uint32_t field_291; // 291, 1164
	uint32_t field_292; // 292, 1168
	uint32_t field_293; // 293, 1172
	uint32_t field_294; // 294, 1176
	uint32_t field_295; // 295, 1180
	uint32_t field_296; // 296, 1184
	uint32_t field_297; // 297, 1188
	uint32_t field_298; // 298, 1192
	nox_object_t* current_enemy; // 299, 1196
	uint32_t field_300; // 300, 1200
	uint32_t field_301; // 301, 1204
	uint32_t field_302; // 302, 1208
	uint32_t field_303; // 303, 1212
	uint32_t field_304; // 304, 1216
	uint32_t field_305; // 305, 1220
	uint32_t field_306; // 306, 1224
	uint32_t field_307; // 307, 1228
	uint32_t field_308; // 308, 1232
	uint32_t field_309; // 309, 1236
	uint32_t field_310; // 310, 1240
	uint32_t field_311; // 311, 1244
	uint32_t field_312; // 312, 1248
	uint32_t field_313; // 313, 1252
	uint32_t field_314; // 314, 1256
	uint32_t field_315; // 315, 1260
	uint32_t field_316; // 316, 1264
	uint32_t field_317; // 317, 1268
	uint32_t field_318; // 318, 1272
	uint32_t field_319; // 319, 1276
	uint32_t field_320; // 320, 1280 // TODO: monster hear script callback?
	uint32_t field_321; // 321, 1284
	uint32_t field_322; // 322, 1288
	uint32_t field_323; // 323, 1292
	uint32_t field_324; // 324, 1296
	uint32_t field_325; // 325, 1300
	uint32_t field_326; // 326, 1304
	uint32_t field_327; // 327, 1308
	float field_328;    // 328, 1312
	uint32_t field_329; // 329, 1316
	uint32_t field_330; // 330, 1320
	uint32_t field_331; // 331, 1324
	uint32_t field_332; // 332, 1328
	uint32_t field_333; // 333, 1332
	uint32_t field_334; // 334, 1336
	uint32_t field_335; // 335, 1340
	float field_336; // 336, 1344
	uint32_t field_337; // 337, 1348
	uint32_t field_338; // 338, 1352
	uint32_t field_339; // 339, 1356
	uint32_t field_340; // 340, 1360
	uint32_t field_341; // 341, 1364
	uint32_t field_342; // 342, 1368
	uint32_t field_343; // 343, 1372
	uint32_t field_344; // 344, 1376
	uint32_t field_345; // 345, 1380
	uint32_t field_346; // 346, 1384
	uint32_t field_347; // 347, 1388
	uint32_t field_348; // 348, 1392
	uint32_t field_349; // 349, 1396
	uint32_t field_350; // 350, 1400
	uint32_t field_351; // 351, 1404
	uint32_t field_352; // 352, 1408
	uint32_t field_353; // 353, 1412
	uint32_t field_354; // 354, 1416
	uint32_t field_355; // 355, 1420
	uint32_t field_356; // 356, 1424
	uint32_t field_357; // 357, 1428
	uint32_t field_358; // 358, 1432
	uint32_t field_359; // 359, 1436
	uint32_t field_360; // 360, 1440 // TODO: flags?
	uint32_t field_361; // 361, 1444
	uint32_t field_362; // 362, 1448
	uint32_t field_363; // 363, 1452
	uint32_t field_364; // 364, 1456
	uint32_t field_365; // 365, 1460
	uint32_t field_366; // 366, 1464
	uint32_t field_367; // 367, 1468
	uint32_t field_368; // 368, 1472
	uint32_t field_369; // 369, 1476
	uint32_t field_370; // 370, 1480
	uint32_t field_371; // 371, 1484
	uint32_t field_372; // 372, 1488
	uint32_t field_373; // 373, 1492
	uint32_t field_374; // 374, 1496
	uint32_t field_375; // 375, 1500
	uint32_t field_376; // 376, 1504
	uint32_t field_377; // 377, 1508
	uint32_t field_378; // 378, 1512
	uint32_t field_379; // 379, 1516
	uint32_t field_380; // 380, 1520
	uint32_t field_381; // 381, 1524
	uint32_t field_382; // 382, 1528
	uint32_t field_383; // 383, 1532
	uint32_t field_384; // 384, 1536
	uint32_t field_385; // 385, 1540
	uint32_t field_386; // 386, 1544
	uint32_t field_387; // 387, 1548
	uint32_t field_388; // 388, 1552
	uint32_t field_389; // 389, 1556
	uint32_t field_390; // 390, 1560
	uint32_t field_391; // 391, 1564
	uint32_t field_392; // 392, 1568
	uint32_t field_393; // 393, 1572
	uint32_t field_394; // 394, 1576
	uint32_t field_395; // 395, 1580
	uint32_t field_396; // 396, 1584
	uint32_t field_397; // 397, 1588
	uint32_t field_398; // 398, 1592
	uint32_t field_399; // 399, 1596
	uint32_t field_400; // 400, 1600
	uint32_t field_401; // 401, 1604
	uint32_t field_402; // 402, 1608
	uint32_t field_403; // 403, 1612
	uint32_t field_404; // 404, 1616
	uint32_t field_405; // 405, 1620
	uint32_t field_406; // 406, 1624
	uint32_t field_407; // 407, 1628
	uint32_t field_408; // 408, 1632
	uint32_t field_409; // 409, 1636
	uint32_t field_410; // 410, 1640
	uint32_t field_411; // 411, 1644
	uint32_t field_412; // 412, 1648
	uint32_t field_413; // 413, 1652
	uint32_t field_414; // 414, 1656
	uint32_t field_415; // 415, 1660
	uint32_t field_416; // 416, 1664
	uint32_t field_417; // 417, 1668
	uint32_t field_418; // 418, 1672
	uint32_t field_419; // 419, 1676
	uint32_t field_420; // 420, 1680
	uint32_t field_421; // 421, 1684
	uint32_t field_422; // 422, 1688
	uint32_t field_423; // 423, 1692
	uint32_t field_424; // 424, 1696
	uint32_t field_425; // 425, 1700
	uint32_t field_426; // 426, 1704
	uint32_t field_427; // 427, 1708
	uint32_t field_428; // 428, 1712
	uint32_t field_429; // 429, 1716
	uint32_t field_430; // 430, 1720
	uint32_t field_431; // 431, 1724
	uint32_t field_432; // 432, 1728
	uint32_t field_433; // 433, 1732
	uint32_t field_434; // 434, 1736
	uint32_t field_435; // 435, 1740
	uint32_t field_436; // 436, 1744
	uint32_t field_437; // 437, 1748
	uint32_t field_438; // 438, 1752
	uint32_t field_439; // 439, 1756
	uint32_t field_440; // 440, 1760
	uint32_t field_441; // 441, 1764
	uint32_t field_442; // 442, 1768
	uint32_t field_443; // 443, 1772
	uint32_t field_444; // 444, 1776
	uint32_t field_445; // 445, 1780
	uint32_t field_446; // 446, 1784
	uint32_t field_447; // 447, 1788
	uint32_t field_448; // 448, 1792
	uint32_t field_449; // 449, 1796
	uint32_t field_450; // 450, 1800
	uint32_t field_451; // 451, 1804
	uint32_t field_452; // 452, 1808
	uint32_t field_453; // 453, 1812
	uint32_t field_454; // 454, 1816
	uint32_t field_455; // 455, 1820
	uint32_t field_456; // 456, 1824
	uint32_t field_457; // 457, 1828
	uint32_t field_458; // 458, 1832
	uint32_t field_459; // 459, 1836
	uint32_t field_460; // 460, 1840
	uint32_t field_461; // 461, 1844
	uint32_t field_462; // 462, 1848
	uint32_t field_463; // 463, 1852
	uint32_t field_464; // 464, 1856
	uint32_t field_465; // 465, 1860
	uint32_t field_466; // 466, 1864
	uint32_t field_467; // 467, 1868
	uint32_t field_468; // 468, 1872
	uint32_t field_469; // 469, 1876
	uint32_t field_470; // 470, 1880
	uint32_t field_471; // 471, 1884
	uint32_t field_472; // 472, 1888
	uint32_t field_473; // 473, 1892
	uint32_t field_474; // 474, 1896
	uint32_t field_475; // 475, 1900
	uint32_t field_476; // 476, 1904
	uint32_t field_477; // 477, 1908
	uint32_t field_478; // 478, 1912
	uint32_t field_479; // 479, 1916
	uint32_t field_480; // 480, 1920
	uint32_t field_481; // 481, 1924
	uint32_t field_482; // 482, 1928
	uint32_t field_483; // 483, 1932
	uint32_t field_484; // 484, 1936
	uint32_t field_485; // 485, 1940
	uint32_t field_486; // 486, 1944
	uint32_t field_487; // 487, 1948
	uint32_t field_488; // 488, 1952
	uint32_t field_489; // 489, 1956
	uint32_t field_490; // 490, 1960
	uint32_t field_491; // 491, 1964
	uint32_t field_492; // 492, 1968
	uint32_t field_493; // 493, 1972
	uint32_t field_494; // 494, 1976
	uint32_t field_495; // 495, 1980
	uint32_t field_496; // 496, 1984
	uint32_t field_497; // 497, 1988
	uint32_t field_498; // 498, 1992
	uint32_t field_499; // 499, 1996
	uint32_t field_500; // 500, 2000
	uint32_t field_501; // 501, 2004
	uint32_t field_502; // 502, 2008
	uint32_t field_503; // 503, 2012
	uint32_t field_504; // 504, 2016
	uint32_t field_505; // 505, 2020
	uint32_t field_506; // 506, 2024
	uint32_t field_507; // 507, 2028
	uint32_t field_508; // 508, 2032
	uint32_t field_509; // 509, 2036
	uint32_t field_510; // 510, 2040
	uint32_t field_511; // 511, 2044
	uint32_t field_512; // 512, 2048
	uint32_t field_513; // 513, 2052
	uint32_t field_514; // 514, 2056, TODO: weapon damage type?
	uint32_t field_515; // 515, 2060
	uint32_t field_516; // 516, 2064
	uint32_t field_517; // 517, 2068
	uint32_t field_518; // 518, 2072
	uint32_t field_519; // 519, 2076
	uint32_t field_520; // 520, 2080
	uint32_t field_521; // 521, 2084
	uint32_t field_522; // 522, 2088
	uint32_t field_523; // 523, 2092
	uint32_t field_524; // 524, 2096
	uint32_t field_525; // 525, 2100
	uint32_t field_526; // 526, 2104
	uint32_t field_527; // 527, 2108
	uint32_t field_528; // 528, 2112
	uint32_t field_529; // 529, 2116
	uint32_t field_530; // 530, 2120
	uint32_t field_531; // 531, 2124
	uint32_t field_532; // 532, 2128
	uint32_t field_533; // 533, 2132
	uint32_t field_534; // 534, 2136
	uint32_t field_535; // 535, 2140
	uint32_t field_536; // 536, 2144
	uint32_t field_537; // 537, 2148
	uint32_t field_538; // 538, 2152
	uint32_t field_539; // 539, 2156
	uint32_t field_540; // 540, 2160
	uint32_t field_541; // 541, 2164
	uint32_t field_542; // 542, 2168
	uint32_t field_543; // 543, 2172
	uint32_t field_544; // 544, 2176
	uint32_t field_545; // 545, 2180
	uint32_t field_546; // 546, 2184
	uint32_t field_547; // 547, 2188
	uint32_t field_548; // 548, 2192
	uint32_t field_549; // 549, 2196
} nox_object_Monster_data_t;
_Static_assert(sizeof(nox_object_Monster_data_t) == 2200, "wrong size of nox_object_Monster_data_t structure!");

#define NOX_SERVER_XXX_SIZE 256
typedef struct nox_server_xxx {
	uint32_t field_0;
	uint32_t field_4;
	uint16_t field_8;
	uint16_t field_10;
} nox_server_xxx;
_Static_assert(sizeof(nox_server_xxx) == 12, "wrong size of nox_server_xxx structure!");

typedef struct nox_net_struct_arg_t {
	uint32_t field_0;
	uint32_t field_1;
	int port;
	int data_3_size;
	int field_4;
	int data_size;
	uint32_t field_6;
	uint32_t field_7;
	int (*func_xxx)(unsigned int, char*, int, void*);
	int (*func_yyy)(unsigned int, char*, int, void*);
} nox_net_struct_arg_t;
_Static_assert(sizeof(nox_net_struct_arg_t) == 40, "wrong size of nox_net_struct_arg_t structure!");

#define NOX_NET_STRUCT_MAX 128
typedef struct nox_net_struct_t {
	nox_socket_t sock;               // 0, 0
	struct nox_net_sockaddr_in addr; // 1, 4
	int id;                          // 5, 20
	uint32_t field_6;
	uint32_t field_7;

	char* data_1_base; //  8, 32
	char* data_1_xxx;  //  9, 36
	char* data_1_yyy;  // 10, 40
	char* data_1_end;  // 11, 44

	char* data_2_base; // 12, 48
	char* data_2_xxx;  // 13, 52
	char* data_2_yyy;  // 14, 56
	char* data_2_end;  // 15, 60

	uint32_t field_16;
	uint32_t field_17;
	uint32_t field_18;
	uint32_t field_19; // 76
	uint32_t field_20;
	uint32_t field_21;   // 84
	uint32_t field_22;   // 88
	uint32_t field_23;   // 92
	uint32_t field_24;   // 96
	uint32_t field_25;   // 100
	uint32_t field_26;   // 104
	uint32_t field_27;   // 108
	uint8_t field_28_0;  // 112
	char field_28_1;     // 113
	uint16_t field_28_2; // 114
	void* field_29;      // 116
	void* data_3;        // 30, 120
	void* mutex_xxx;     // 31, 124
	void* mutex_yyy;     // 32, 128
	uint32_t field_33;
	uint32_t field_34;                                // 136
	int (*func_xxx)(unsigned int, char*, int, void*); // 35, 140, func(i, data_2_xxx, sz, data_3)
	int (*func_yyy)(unsigned int, char*, int, void*); // 36, 144, last arg is data_3
	uint8_t xor_key;                                  // 37, 148
	uint8_t field_37_1;                               // 37, 149
	uint16_t field_37_2;                              // 37, 150
	uint32_t field_38;                                // 152
	uint8_t data_39[4];                               // 156
	uint32_t field_40;                                // 160
} nox_net_struct_t;
_Static_assert(sizeof(struct nox_net_sockaddr) == 16, "wrong size of nox_net_sockaddr structure!");
_Static_assert(sizeof(struct nox_net_sockaddr_in) == 16, "wrong size of nox_net_sockaddr_in structure!");
_Static_assert(sizeof(nox_net_struct_t) == 164, "wrong size of nox_net_struct_t structure!");

typedef struct nox_net_struct2_t {
	uint32_t field_0;   // 0, 0
	uint8_t field_1_0;  // 1, 4
	uint8_t field_1_1;  // 1, 5
	uint16_t field_1_2; // 1, 6
	// TODO: check usages, looks like it reuses sin_zero for something else
	struct nox_net_sockaddr_in addr; // 2, 8
	uint32_t field_6[10];            // 6, 24
	uint32_t ticks;                  // 16, 64
} nox_net_struct2_t;
_Static_assert(sizeof(nox_net_struct2_t) == 68, "wrong size of nox_net_struct2_t structure!");

typedef struct nox_things_imageRef_t {
	char name[32];    // 0, 0
	char name2[64];   // 8, 32
	void* field_24;     // 24, 96; void* when field_25_1 == 2, int when field_25_1 == 1
	char field_25_0;  // 25, 100
	char ref_kind;  // 25, 101
	short field_25_2; // 25, 102
} nox_things_imageRef_t;
_Static_assert(sizeof(nox_things_imageRef_t) == 104, "wrong size of nox_things_imageRef_t structure!");

typedef struct nox_things_imageRef2_t {
	void (*on_end)(nox_things_imageRef_t*); // 0, 0
	nox_video_bag_image_t** images; // 1, 4
	uint8_t images_sz; // 2, 8
	uint8_t field_2_1; // 2, 9
	uint8_t anim_type; // 2, 10
	uint8_t field_2_3; // 2, 11
	uint32_t field_3; // 3, 12
} nox_things_imageRef2_t;
_Static_assert(sizeof(nox_things_imageRef2_t) == 16, "wrong size of nox_things_imageRef2_t structure!");

typedef struct {
	uint32_t field_0;  // 0, 0
	wchar_t text[256]; // 1, 4
	uint32_t field_129;  // 129, 516
	uint32_t field_130;  // 130, 520
} nox_scrollListBox_item;
_Static_assert(sizeof(nox_scrollListBox_item) == 524, "wrong size of nox_scrollListBox_item structure!");

typedef struct {
	uint16_t count; // 0, 0
	uint16_t line_height; // 0, 2
	uint32_t field_1; // 1, 4
	uint32_t field_2; // 2, 8
	uint32_t field_3; // 3, 12
	uint32_t field_4; // 4, 16
	uint32_t field_5; // 5, 20
	nox_scrollListBox_item* items; // 6, 24
	void* field_7; // 7, 28
	void* field_8; // 8, 32
	void* field_9; // 9, 36
	uint32_t field_10; // 10, 40
	uint16_t field_11_0; // 11, 44
	uint16_t field_11_1; // 11, 46
	uint32_t* field_12; // 12, 48, []*void? []int32?
	uint16_t field_13_0; // 13, 52
	uint16_t field_13_1; // 13, 54
} nox_scrollListBox_data;
_Static_assert(sizeof(nox_scrollListBox_data) == 56, "wrong size of nox_scrollListBox_data structure!");

typedef struct {
	wchar_t* text;
	uint32_t center;
	uint32_t glow;
} nox_staticText_data;
_Static_assert(sizeof(nox_staticText_data) == 12, "wrong size of nox_staticText_data structure!");

typedef struct nox_window_yyy {
	nox_window* win;  // 0
	uint32_t field_1; // 4
	uint32_t field_2; // 8
	uint32_t color_1; // 12
	uint32_t color_2; // 16
} nox_window_yyy;
_Static_assert(sizeof(nox_window_yyy) == 20, "wrong size of nox_window_yyy structure!");

typedef struct {
	const char* name;
	int (*fnc)(nox_window_data*, char*);
} nox_parseWindowFunc;
_Static_assert(sizeof(nox_parseWindowFunc) == 8, "wrong size of nox_parseWindowFunc structure!");

typedef struct nox_drawable {
	uint32_t field_0;     // 0, 0
	uint32_t field_1;     // 1, 4
	void* field_2;        // 2, 8
	nox_point pos;        // 3, 12
	uint32_t field_5;     // 5, 20
	uint32_t field_6;     // 6, 24
	uint32_t field_7;     // 7, 28
	uint32_t field_8;     // 8, 32
	uint32_t field_9;     // 9, 36
	uint32_t field_10;    // 10, 40
	nox_shape shape;      // 11, 44
	float field_24;       // 24, 96
	float field_25;       // 25, 100
	uint16_t z;    // 26, 104
	uint16_t field_26_1;    // 26, 106
	uint32_t field_27;    // 27, 108, thing ID? pointer? union?
	unsigned int flags28; // 28, 112
	unsigned int flags29; // 29, 116
	unsigned int flags30; // 30, 120
	unsigned int buffs;   // 31, 124
	uint32_t field_32;    // 32, 128, npc ID?
	uint32_t field_33;    // 33, 132
	uint32_t light_flags;         // 34, 136, 0
	float light_intensity;        // 35, 140, 1
	uint32_t light_intensity_rad;  // 36, 144, 2
	uint32_t light_intensity_u16; // 37, 148, 3
	uint32_t light_color_r;    // 38, 152, 4
	uint32_t light_color_g;    // 39, 156, 5
	uint32_t light_color_b;    // 40, 160, 6
	uint16_t field_41_0;  // 41, 164
	uint16_t field_41_1;  // 41, 166
	uint32_t field_42;    // 42, 168
	uint32_t field_43;    // 43, 172
	uint32_t field_44;    // 44, 176
	uint32_t data_45[5];
	uint32_t data_50[10];
	uint32_t data_60[5];
	uint32_t field_65; // 65, 260
	uint32_t field_66;
	uint32_t field_67;
	uint32_t field_68;
	uint32_t field_69;                          // 69, 276
	unsigned int flags70;                       // 70, 280
	uint32_t field_71;                          // 71, 284
	uint32_t field_72;                          // 72, 288
	uint16_t field_73_1;                        // 73, 292
	uint16_t field_73_2;                        // 73, 294
	int8_t  vel_z;                              // 74, 296
	uint8_t field_74_2;                         // 74, 297
	uint8_t field_74_3;                         // 74, 298
	uint8_t field_74_4;                         // 74, 299
	int (*draw_func)(uint32_t*, nox_drawable*); // 75, 300, same as nox_thing->draw_func
	void* field_76;                             // 76, 304
	uint32_t field_77;                          // 77, 308
	uint32_t field_78;
	uint32_t field_79; // 79, 316
	uint32_t field_80; // 80, 320
	uint32_t field_81;
	uint32_t field_82;
	uint32_t field_83;
	uint32_t field_84;
	uint32_t field_85; // 85, 340, last draw frame number?
	uint32_t field_86;
	uint32_t field_87;
	uint32_t field_88;
	uint32_t field_89;
	nox_drawable* field_90; // 90, 360
	nox_drawable* field_91; // 91, 364
	nox_drawable* field_92; // 92, 368
	nox_drawable* field_93; // 93, 372
	uint32_t field_94;
	uint32_t field_95;
	uint32_t field_96;
	nox_drawable* field_97;  // 97, 388
	nox_drawable* field_98;  // 98, 392
	nox_drawable** field_99; // 99, 396
	nox_drawable* field_100; // 100, 400
	nox_drawable* field_101; // 101, 404
	uint32_t field_102;      // 102, 408
	uint32_t field_103;      // 103, 412
	nox_drawable* field_104; // 104, 416
	nox_drawable* field_105; // 105, 420
	uint32_t field_106;      // 106, 424
	uint32_t field_107;      // 107, 428
	uint8_t field_108_1;     // 108, 432 // TODO: union?
	uint8_t field_108_2;     // 108, 433
	uint16_t field_108_3;    // 108, 434
	uint32_t field_109;      // 109, 436, SE?
	uint32_t field_110;      // 110, 440, SW?
	uint32_t field_111;      // 111, 444, SW?
	uint32_t field_112;      // 112, 448, SE?
	uint32_t field_113;
	uint32_t field_114;
	uint32_t field_115;
	uint32_t field_116; // 116, 464
	uint32_t field_117;
	uint32_t field_118;
	uint32_t field_119;
	uint32_t field_120; // 120, 480
	uint32_t field_121; // 121, 484
	uint32_t field_122; // 122, 488
	uint32_t field_123; // 123, 492
	uint32_t field_124;
	uint32_t field_125;
	uint32_t field_126;
	uint32_t field_127;
} nox_drawable;
_Static_assert(sizeof(nox_drawable) == 512, "wrong size of nox_drawable structure!");

// 3108 = NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t)
// 777 = NOX_INVENTORY_ROW_COUNT * (sizeof(nox_inventory_cell_t)/4)
// 37 = (sizeof(nox_inventory_cell_t)/4)
#define NOX_INVENTORY_ROW_COUNT 21
#define NOX_INVENTORY_COL_COUNT 4
#define NOX_INVENTORY_CELLS_MAX (NOX_INVENTORY_ROW_COUNT * NOX_INVENTORY_COL_COUNT)
typedef struct nox_inventory_cell_t {
	nox_drawable* field_0;
	uint32_t field_4;
	uint32_t data_4[30];
	uint32_t field_128;
	uint32_t field_132;
	uint32_t field_136;
	uint8_t field_140;
	uint8_t field_141;
	uint8_t field_142;
	uint8_t field_143;
	uint32_t field_144;
} nox_inventory_cell_t;
_Static_assert(sizeof(nox_inventory_cell_t) == 148, "wrong size of nox_inventory_cell_t structure!");

typedef struct obj_412ae0_t obj_412ae0_t;
typedef struct obj_412ae0_t {
	char* field_0;
	uint32_t field_1;
	wchar_t* field_2;
	wchar_t* field_3;
	wchar_t* field_4;
	int field_5;
	uint32_t field_6;
	int field_7;
	int field_8;
	uint32_t field_9;
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
	int (*parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_26792_t;

typedef struct table_27008_t {
	const char* name;
	void* fnc;
	int (*parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27008_t;

typedef struct table_27104_t {
	const char* name;
	void* fnc;
	int (*parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27104_t;

typedef struct table_27168_t {
	const char* name;
	void* fnc;
	int (*parse_fnc)(const char*, char*, obj_412ae0_t*);
} table_27168_t;

typedef struct table_28760_t {
	const char* name;
	int (*parse_fnc)(const char*, char*, obj_412ae0_t*);
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
	bool (*parse_fnc)(nox_thing*, nox_memfile*, char*);
} nox_parse_thing_draw_funcs_t;

typedef struct nox_video_mode {
	int width;
	int height;
	int id;
	wchar_t* title;
} nox_video_mode;

enum { NOX_MOUSE_LEFT = 0, NOX_MOUSE_RIGHT = 1, NOX_MOUSE_MIDDLE = 2 };

enum { NOX_MOUSE_DOWN = 1, NOX_MOUSE_DRAG_END = 2, NOX_MOUSE_UP = 3, NOX_MOUSE_PRESSED = 4 };

typedef struct nox_mouse_btn_t {
	int pressed;
	uint32_t state;
	uint32_t seq;
} nox_mouse_btn_t;
_Static_assert(sizeof(nox_mouse_btn_t) == 12, "wrong size of nox_mouse_btn_t structure!");

typedef struct nox_mouse_state_t {
	nox_point pos; // 0
	int wheel;     // 8

	nox_point dpos; // 12

	nox_mouse_btn_t btn[3]; // 20, 32, 44
} nox_mouse_state_t;
_Static_assert(sizeof(nox_mouse_state_t) == 56, "wrong size of nox_mouse_state_t structure!");

typedef struct nox_keyboard_btn_t {
	uint8_t code;
	uint8_t state;
	uint8_t field_2;
	uint8_t field_3;
	uint32_t seq;
} nox_keyboard_btn_t;
_Static_assert(sizeof(nox_keyboard_btn_t) == 8, "wrong size of nox_keyboard_btn_t structure!");

#define NOX_CTRLEVENT_XXX_MAX 128
typedef struct nox_ctrlevent_xxx_t {
	long long tick;          // 0
	nox_ctrlevent_code code; // 8
	uint32_t data;           // 12
	int active;              // 16
	uint32_t paddding;       // 20
} nox_ctrlevent_xxx_t;
_Static_assert(sizeof(nox_ctrlevent_xxx_t) == 24, "wrong size of nox_ctrlevent_xxx_t structure!");

typedef struct nox_render_mat_t {
	uint32_t field_0;  // 0, 0
	uint32_t field_1;  // 1, 4
	uint32_t field_2;  // 2, 8
	uint32_t field_3;  // 3, 12
	uint32_t field_4;  // 4, 16
	uint32_t field_5;  // 5, 20
	uint32_t color_r;  // 6, 24
	uint32_t color_g;  // 7, 28
	uint32_t color_b;  // 8, 32
	uint32_t field_9;  // 9, 36
	uint32_t color32;  // 10, 40
	uint32_t field_11; // 11, 44
} nox_render_mat_t;
_Static_assert(sizeof(nox_render_mat_t) == 48, "wrong size of nox_render_mat_t structure!");

typedef struct nox_render_data_t {
	int flag_0;         // 0, 0
	nox_rect clip;      // 1, 4
	nox_rect rect2;     // 5, 20; is usually set to [0,w-1] as opposed to clip, which is [0,w]
	nox_rect rect3;     // 9, 36
	uint32_t field_13;  // 13, 52
	uint32_t field_14;  // 14, 56
	uint32_t field_15;  // 15, 60
	uint32_t field_16;  // 16, 64
	uint32_t field_17;  // 17, 68
	uint32_t field_18;  // 18, 72
	uint32_t field_19;  // 19, 76
	uint32_t field_20;  // 20, 80
	uint32_t field_21;  // 21, 84
	uint32_t field_22;  // 22, 88
	uint32_t field_23;  // 23, 92
	uint32_t field_24;  // 24, 96
	uint32_t field_25;  // 25, 100
	uint32_t field_26;  // 26, 104
	uint32_t field_27;  // 27, 108
	uint32_t field_28;  // 28, 112
	uint32_t field_29;  // 29, 116
	uint32_t field_30;  // 30, 120
	uint32_t field_31;  // 31, 124
	uint32_t field_32;  // 32, 128
	uint32_t field_33;  // 33, 132
	uint32_t field_34;  // 34, 136
	uint32_t field_35;  // 35, 140
	uint32_t field_36;  // 36, 144
	uint32_t field_37;  // 37, 148
	uint32_t field_38;  // 38, 152
	uint32_t field_39;  // 39, 156
	uint32_t field_40;  // 40, 160
	uint32_t field_41;  // 41, 164
	uint32_t field_42;  // 42, 168
	uint32_t field_43;  // 43, 172
	uint32_t field_44;  // 44, 176
	uint32_t field_45;  // 45, 180
	uint32_t field_46;  // 46, 184
	uint32_t field_47;  // 47, 188
	uint32_t field_48;  // 48, 192
	uint32_t field_49;  // 49, 196
	uint32_t field_50;  // 50, 200
	uint32_t field_51;  // 51, 204
	uint32_t field_52;  // 52, 208
	uint32_t field_53;  // 53, 212
	uint32_t field_54;  // 54, 216
	uint32_t field_55;  // 55, 220
	uint32_t field_56;  // 56, 224
	uint32_t field_57;  // 57, 228
	uint32_t field_58;  // 58, 232
	uint32_t field_59;  // 59, 236
	uint32_t field_60;  // 60, 240
	uint32_t field_61;  // 61, 244
	uint32_t field_62;  // 62, 248
	uint32_t field_63;  // 63, 252
	uint32_t field_64;  // 64, 256
	uint32_t field_65;  // 65, 260
	nox_render_mat_t materials[16];  // 66, 264
	uint16_t field_258_0; // 258, 1032
	uint16_t field_258_2; // 258, 1034
	uint32_t field_259; // 259, 1036
	uint32_t field_260; // 260, 1040
	uint32_t field_261; // 261, 1044
	uint32_t field_262; // 262, 1048
	uint32_t field_263; // 263, 1052
} nox_render_data_t;
_Static_assert(sizeof(nox_render_data_t) == 1056, "wrong size of nox_render_data_t structure!");

typedef struct {
	void (*fnc)(int);
	int field_4;
	char name[12];
} obj_5D4594_754088_t;

typedef struct {
	uint8_t field_0;    // 0, 0
	uint8_t field_0_1;  // 0, 1
	uint16_t field_0_2; // 0, 2
	int field_1;        // 1, 4
	int field_2;        // 2, 8
	int field_3;        // 3, 12
	int field_4;        // 4, 16
	void* field_5;      // 5, 20
	int field_6;        // 6, 24
	int field_7;        // 7, 28
	int field_8;        // 8, 32
	int field_9;        // 9, 36
	void* field_10;     // 10, 40
} obj_5D4594_2650668_t;
_Static_assert(sizeof(obj_5D4594_2650668_t) == 44, "wrong size of obj_5D4594_2650668_t structure!");

typedef struct {
	bool live;
	uint8_t pad[3];
	int id;
	uint32_t data8[327];
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
	uint32_t field_4;                            // 1, 4
	uint32_t field_8;                            // 2, 8
	uint32_t field_12;                           // 3, 12, color
	uint32_t field_16;                           // 4, 16, vx
	uint32_t field_20;                           // 5, 20, vy
	uint32_t field_24;                           // 6, 24, x
	uint32_t field_28;                           // 7, 28, y
	uint32_t field_32;                           // 8, 32
	uint32_t field_36;                           // 9, 36
	uint8_t field_40[4];                         // 10, 40
	nox_screenParticle* field_44;                // 11, 44, next
	nox_screenParticle* field_48;                // 12, 48, prev
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
	uint32_t field_0;          // 0, 0
	nox_window* win;           // 1, 4
	int x2;                    // 2, 8
	int y2;                    // 3, 12
	int x1;                    // 4, 16
	int y1;                    // 5, 20
	int out_dx;                // 6, 24
	int out_dy;                // 7, 28
	int in_dx;                 // 8, 32
	int in_dy;                 // 9, 36
	nox_gui_animation* next;   // 10, 40
	nox_gui_animation* prev;   // 11, 44
	int (*field_12)(void);     // 12, 48
	int (*field_13)(void);     // 13, 52
	int (*fnc_done_out)(void); // 14, 56
	void (*fnc_done_in)(void); // 15, 60
	nox_gui_anim_state state;  // 16, 64
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
	nox_list_item_t list;    // 0, 0
	char name[12];           // 3, 12
	int field_6;             // 6, 24
	uint32_t field_7;        // 7, 28
	unsigned char field_8_0; // 8, 32
	unsigned char field_8_1; // 8, 33
	uint16_t field_8_2;      // 8, 34
} nox_map_list_item;
_Static_assert(sizeof(nox_map_list_item) == 36, "wrong size of nox_map_list_item structure!");

typedef struct nox_draw_viewport_t {
	int x1;            // 0, 0
	int y1;            // 1, 4
	int x2;            // 2, 8
	int y2;            // 3, 12
	int field_4;       // 4, 16
	int field_5;       // 5, 20
	int field_6;       // 6, 24
	int field_7;       // 7, 28
	int width;         // 8, 32
	int height;        // 9, 36
	uint32_t field_10; // 10, 40
	uint32_t field_11; // 11, 44
	int field_12;      // 12, 48
} nox_draw_viewport_t;
_Static_assert(sizeof(nox_draw_viewport_t) == 52, "wrong size of nox_draw_viewport_t structure!");

#define NOX_SPELLS_MAX 137
#define NOX_PLAYERINFO_MAX 32

#pragma pack(push,1)
typedef struct {
	wchar_t name[25]; // 2185 (+0) // TODO: size is a guess
	uint32_t field_2235; // 2235 (+50)
	uint32_t field_2239; // 2239 (+54)
	uint32_t field_2243; // 2243 (+58)
	uint32_t field_2247; // 2247 (+62)
	unsigned char playerClass; // 562, 2251 (+66)
	unsigned char isFemale; // 562, 2252 (+67)
	uint16_t field_2253; // 2253 (+68)
	uint8_t field_2255; // 2255 (+70)
	uint16_t field_2256; // 2256 (+71)
	uint8_t field_2258; // 2258 (+73)
	uint16_t field_2259; // 2259 (+74)
	uint8_t field_2261; // 2261 (+76)
	uint16_t field_2262; // 2262 (+77)
	uint8_t field_2264; // 2264 (+79)
	uint16_t field_2265; // 2265 (+80)
	uint8_t field_2267; // 2267 (+82)
	uint8_t field_2268; // 2268 (+83)
	uint8_t field_2269; // 2269 (+84)
	uint8_t field_2270; // 2270 (+85)
	uint8_t field_2271; // 2271 (+86)
	uint8_t field_2272; // 2272 (+87)
	uint8_t field_2273; // 2273 (+88)
	wchar_t name_suff[4]; // 2274 (+89)
} nox_playerInfo2;
#pragma pack(pop)
_Static_assert(sizeof(nox_playerInfo2) == 97, "wrong size of nox_playerInfo2 structure!");
_Static_assert(offsetof(nox_playerInfo2, name_suff) == 89, "wrong offset of nox_playerInfo2.name_suff field!");

#pragma pack(push,1)
typedef struct nox_playerInfo {
	uint32_t field_0; // 0, 0
	uint32_t field_4; // 1, 4
	uint16_t field_8; // 2, 8
	uint16_t field_10; // 2, 10
	uint16_t field_12; // 3, 12
	uint16_t field_14; // 3, 14
	uint32_t data_16[96];
	uint32_t data_400[100];
	uint32_t data_800[50];
	uint32_t data_1000[25];
	uint32_t data_1100[25];
	uint32_t data_1200[25];
	uint32_t data_1300[25];
	uint32_t data_1400[25];
	uint32_t data_1500[25];
	uint32_t data_1600[100];
	uint32_t data_2000[8];
	uint32_t data_2032[4];
	uint32_t data_2048[2];
	nox_object_t* playerUnit; // 514, 2056
	unsigned int netCode;     // 515, 2060
	unsigned char playerInd;  // 516, 2064
	uint8_t field_2064_1;     // 516, 2065
	uint16_t field_2064_2;    // 516, 2066
	uint32_t field_2068;      // 517, 2068
	wchar_t field_2072[10];   // 518, 2072
	unsigned int active;      // 523, 2092
	char field_2096[12]; // 524, 2096
	uint32_t field_2108; // 527, 2108
	char serial[22];   // 528, 2112
	uint8_t field_2134;
	uint8_t field_2135;
	uint32_t field_2136; // 534, 2136
	uint32_t field_2140; // 535, 2140
	uint32_t field_2144; // 536, 2144
	uint32_t field_2148; // 537, 2148
	uint32_t field_2152; // 538, 2152
	uint32_t field_2156; // 539, 2156
	uint32_t field_2160; // 540, 2160
	uint32_t gold; // 541, 2164
	uint8_t data_2168[17];
	nox_playerInfo2 info; // 2185
	uint16_t field_2282;
	int field_2284; // 2284, TODO: x coordinate of something? cursor? spell target?
	int field_2288; // 2288, TODO: y coordinate of something? cursor? spell target?
	uint32_t data_2292[30];
	uint32_t data_2412[97];
	uint32_t data_2800[100];
	uint32_t data_3200[50];
	uint32_t data_3400[25];
	uint32_t data_3500[20];
	uint32_t field_3580;
	uint32_t field_3584;
	uint32_t field_3588;
	uint32_t field_3592;
	unsigned int frame_3596;
	uint32_t field_3600; // 900, 3600
	uint32_t field_3604; // 901, 3604
	uint32_t field_3608; // 902, 3608
	uint32_t field_3612; // 903, 3612
	uint32_t field_3616; // 904, 3616
	uint32_t field_3620; // 905, 3620
	uint32_t field_3624; // 906, 3624
	nox_object_t* camera_follow; // 907, 3628
	float pos_x_3632; // 908, 3632
	float pos_y_3636; // 909, 3636
	nox_object_t* obj_3640; // 910, 3640
	uint32_t field_3644; // 911, 3644
	uint32_t field_3648;
	uint32_t field_3652;
	uint32_t field_3656;
	uint32_t field_3660;
	uint32_t field_3664;
	uint32_t field_3668;
	uint32_t field_3672;
	uint8_t field_3676; // 3676, TODO: status?
	uint8_t field_3676_1;
	uint16_t field_3676_2;
	uint32_t field_3680; // 920, 3680, TODO: some flags?
	uint8_t field_3684; // 921, 3684 // TODO: level?
	uint8_t field_3685;
	uint16_t field_3686;
	uint32_t field_3688;
	uint32_t field_3692;
	unsigned int spell_lvl[NOX_SPELLS_MAX]; // 3696
	unsigned int beast_scroll_lvl[41];      // 4244
	uint32_t data_4408[23];
	uint32_t data_4500[20];
	uint32_t field_4580; // 1145, 4580
	uint32_t prot_unit_hp_cur;       // 1146, 4584
	uint32_t prot_player_gold;       // 1147, 4588
	uint32_t prot_unit_hp_max;       // 1148, 4592
	uint32_t prot_unit_mana_cur;     // 1149, 4596
	uint32_t prot_unit_mana_max;     // 1150, 4600
	uint32_t prot_unit_experience;   // 1151, 4604
	uint32_t prot_unit_mass;         // 1152, 4608
	uint32_t prot_unit_buffs;        // 1153, 4612
	uint32_t prot_player_class;      // 1154, 4616
	uint32_t prot_player_field_2235; // 1155, 4620
	uint32_t prot_player_field_2239; // 1156, 4624
	uint32_t prot_player_orig_name;  // 1157, 4628
	uint32_t prot_4632; // 1158, 4632
	uint32_t prot_4636; // 1159, 4636
	uint32_t prot_4640; // 1160, 4640
	uint32_t prot_player_level; // 1161, 4644
	int field_4648; // 1162, 4648
	uint32_t field_4652; // 1163, 4652
	uint32_t field_4656; // 1164, 4656
	uint32_t field_4660; // 1165, 4660
	uint32_t field_4664; // 1166, 4664
	uint32_t field_4668; // 1167, 4668
	uint32_t field_4672; // 1168, 4672
	uint32_t field_4676; // 1169, 4676
	uint32_t field_4680; // 1170, 4680
	uint32_t field_4684; // 1171, 4684
	uint32_t field_4688; // 1172, 4688
	uint32_t field_4692; // 1173, 4692
	uint32_t field_4696; // 1174, 4696
	uint32_t field_4700; // 1175, 4700
	wchar_t name_final[30]; // 4704, server-approved player name // TODO: size is a wild guess
	uint32_t field_4764; // 1191, 4764
	uint32_t field_4768; // 1192, 4768
	uint32_t field_4772; // 1193, 4772
	uint32_t field_4776; // 1194, 4776
	uint32_t field_4780; // 1195, 4780
	uint32_t field_4784; // 1196, 4784
	uint32_t field_4788; // 1197, 4788
	uint32_t field_4792; // 1198, 4792
	uint32_t field_4796; // 1199, 4796
	uint32_t data_4800[7];
} nox_playerInfo;
#pragma pack(pop)
_Static_assert(sizeof(nox_playerInfo) == 4828, "wrong size of nox_playerInfo structure!");
_Static_assert(offsetof(nox_playerInfo, info) == 2185, "wrong offset of nox_playerInfo.info field!");
_Static_assert(offsetof(nox_playerInfo, frame_3596) == 3596, "wrong offset of nox_playerInfo.frame_3596 field!");
_Static_assert(offsetof(nox_playerInfo, field_4580) == 4580, "wrong offset of nox_playerInfo.field_4580 field!");

typedef struct {
	uint32_t field_0; // 0
	uint32_t field_1; // 4
	uint32_t field_2; // 8
	uint8_t field_3[4]; // 12
	uint32_t field_4; // 16
	uint32_t field_5; // 20
} nox_player_ctrl_t;
_Static_assert(sizeof(nox_player_ctrl_t) == 24, "wrong size of nox_player_ctrl_t structure!");

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

#pragma pack(push, 1)
typedef struct nox_gui_server_ent_t {
	uint32_t field_0;             // 0, 0
	uint32_t field_1;             // 1, 4
	int sort_key;                 // 2, 8
	char addr[16];                // 3, 12
	int field_7;                  // 7, 28
	uint32_t field_8;             // 8, 32
	uint32_t field_9;             // 9, 36, TODO: server index?
	uint32_t field_10;            // 10, 40
	short field_11_0;             // 11, 44
	short field_11_2;             // 11, 46
	uint32_t version;             // 12, 48
	uint32_t field_13;            // 13, 52
	uint32_t field_14;            // 14, 56
	uint32_t field_15;            // 15, 60
	uint32_t field_16;            // 16, 64
	uint32_t field_17;            // 17, 68
	uint32_t field_18;            // 18, 72
	uint32_t field_19;            // 19, 76
	uint32_t field_20;            // 20, 80
	uint32_t field_21;            // 21, 84
	uint32_t field_22;            // 22, 88
	uint32_t field_23;            // 23, 92
	int ping;                     // 24, 96
	unsigned char status;         // 25, 100
	uint8_t field_25_1;           // 25, 101
	uint8_t field_25_2;           // 25, 102
	unsigned char players;        // 25, 103
	unsigned char max_players;    // 26, 104
	uint16_t field_26_1;          // 26, 105
	uint16_t field_26_3;          // 26, 107
	unsigned short port;          // 27, 109
	char map_name[9];             // 27, 111
	char server_name[15];         // 30, 120
	unsigned char field_33_3[20]; // 33, 135, TODO: [20]byte
	uint32_t field_38_3;          // 38, 155
	uint32_t field_39_3;          // 39, 159
	unsigned short flags;         // 40, 163
	unsigned short quest_level;   // 41, 165
	uint8_t field_41_3;           // 41, 167
	uint8_t field_42;             // 42, 168
} nox_gui_server_ent_t;
#pragma pack(pop)
_Static_assert(sizeof(nox_gui_server_ent_t) == 169, "wrong size of nox_gui_server_ent_t structure!");

#endif
