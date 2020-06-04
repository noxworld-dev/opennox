#include "proto.h"

extern int nox_enable_audio;
extern int nox_enable_threads;
extern int nox_video_dxFullScreen;
extern int nox_video_windowsPlatformVersion;
extern int nox_video_pauseThreadedDrawCursor;
extern int nox_video_drawCursorThreadOk;
extern int nox_video_allowCursorDrawThread;
extern int nox_video_cursorDrawIsThreaded;
extern int nox_client_mouseCursorType;
extern int nox_video_gammaValue;
extern HANDLE* nox_video_cursorDrawThreadHandle;

extern nox_missing_string* missing_strings;
extern nox_string_entry* string_entries;
extern size_t string_entries_cnt;

extern wchar_t file_buffer_w[4096 * 2];
extern char file_buffer[4096];

extern FILE* nox_file_1;
extern FILE* nox_file_2;
extern FILE* nox_file_3;
extern FILE* nox_file_4;
extern FILE* nox_file_5;
extern FILE* nox_video_bag_fileptr;
extern FILE* nox_file_7;
extern FILE* nox_file_8;
extern FILE* nox_file_9;
extern FILE* nox_file_10;
extern int nox_file_10_mode;
extern FILE* nox_file_log;
extern FILE* nox_file_net_log;

extern nox_memfile* nox_loaded_thing_bin;

extern int nox_win_width;
extern int nox_win_height;

extern int nox_win_width_1;
extern int nox_win_height_1;
extern int nox_win_depth_1;

extern int nox_win_width_2;
extern int nox_win_height_2;
extern int nox_win_depth_2;

extern int nox_max_width;
extern int nox_max_height;

extern void* nox_backbuffer1_pix;
extern void* nox_backbuffer_pix;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_backbuffer_depth;
extern int nox_backbuffer_width32;
extern int nox_video_renderTargetFlags;
extern int nox_video_dxUnlockSurface;
extern int nox_video_dxFullScreen;

extern nox_alloc_class* nox_alloc_window;

extern nox_window* nox_win_unk1;
extern nox_window* nox_win_unk2;
extern nox_window* nox_win_unk3;
extern nox_window* nox_win_unk4;
extern nox_window* nox_win_unk5;
extern nox_window* nox_win_cur_weapon;

extern int nox_cheats_disabled;

extern nox_window* nox_win_main_menu;
extern nox_window* nox_win_main_bg;

extern int (*nox_draw_unk1)(void);

extern nox_video_mode nox_video_modes[];

extern const char* table_5184[];
extern table_26792_t table_26792[];
extern table_27008_t table_27008[];
extern table_27104_t table_27104[];
extern table_27168_t table_27168[];
extern table_28760_t table_28760[];
extern nox_parse_thing_draw_funcs_t nox_parse_thing_draw_funcs[];

// unresolved

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;
extern obj_5D4594_3799572_t obj_5D4594_3799660;
extern obj_5D4594_3799572_t obj_5D4594_3800716;

extern _DWORD* dword_5D4594_251544;
extern obj_412ae0_t* byte_5D4594_251584[3];
extern int byte_5D4594_251596;

extern obj_5D4594_754088_t* ptr_5D4594_754088;
extern int ptr_5D4594_754088_cnt;

extern obj_5D4594_754088_t* ptr_5D4594_754092;
extern int ptr_5D4594_754092_cnt;

extern int obj_5D4594_754104_switch;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;

extern nox_mouse_state_t nox_input_buffer[256];
extern int nox_processing_input;

extern nox_mouse_state_t nox_mouse;
extern nox_mouse_state_t nox_mouse_prev;
extern _DWORD nox_mouse_prev_seq;
extern _DWORD nox_mouse_prev_seq_2;
extern mouse_pos_t nox_mouse_min;
extern mouse_pos_t nox_mouse_max;
extern mouse_pos_t nox_mouse_prev_left;
extern mouse_pos_t nox_mouse_prev_right;
extern mouse_pos_t nox_mouse_prev_middle;

extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
extern int nox_things_count;

extern nox_parse_thing_funcs_t nox_parse_thing_funcs[];

extern nox_alloc_class* nox_alloc_drawable;
extern nox_drawable* nox_drawable_head_unk1;
extern nox_drawable* nox_drawable_head_unk2;
extern nox_drawable* nox_drawable_head_unk3;
extern nox_drawable* nox_drawable_head_unk4;
extern int nox_drawable_count;

extern nox_drawable** nox_drawable_list_1;
extern int nox_drawable_list_1_size;

extern nox_drawable** nox_drawable_list_2;
extern int nox_drawable_list_2_size;

extern nox_drawable** nox_drawable_list_3;
extern int nox_drawable_list_3_size;

extern nox_drawable** nox_drawable_list_4;
extern int nox_drawable_list_4_size;

extern nox_drawable*** nox_drawable_2d_index;
extern int nox_drawable_2d_index_size;
extern _DWORD dword_5d4594_3798784;
extern _DWORD dword_5d4594_1599636;
extern _DWORD dword_5d4594_3799540;
extern _DWORD dword_5d4594_4668;
extern _DWORD dword_5d4594_1046492;
extern _DWORD dword_587000_133480;
extern _DWORD dword_5d4594_830224;
extern _DWORD dword_5d4594_814980;
extern _DWORD dword_5d4594_3804664;
extern _DWORD dword_5d4594_1045516;
extern _DWORD dword_5d4594_3804656;
extern _DWORD dword_5d4594_3804672;
extern _DWORD dword_5d4594_1045684;
extern _DWORD dword_5d4594_1307784;
extern _DWORD dword_5d4594_3798844;
extern _DWORD dword_5d4594_2650652;
extern _DWORD dword_5d4594_1217448;
extern _DWORD dword_5d4594_1320940;
extern _DWORD dword_5d4594_815004;
extern _DWORD dword_5d4594_815012;
extern _DWORD dword_5d4594_1062480;
extern _DWORD dword_5d4594_832484;
extern _DWORD dword_5d4594_3798796;
extern _DWORD dword_5d4594_825760;
extern _DWORD dword_587000_80828;
extern _DWORD dword_5d4594_810632;
extern _DWORD dword_5d4594_787148;
extern _DWORD dword_5d4594_2386944;
extern _DWORD dword_5d4594_1064916;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_2516348;
extern _DWORD dword_5d4594_3799536;
extern _DWORD dword_5d4594_1063116;
extern _DWORD dword_5d4594_1090120;
extern _DWORD dword_5d4594_2516328;
extern _DWORD dword_5d4594_1189584;
extern _DWORD dword_5d4594_1049504;
extern _DWORD dword_5d4594_1046868;
extern _DWORD dword_5d4594_1082856;
extern _DWORD dword_5d4594_1193380;
extern _DWORD dword_587000_26048;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_5d4594_1316972;
extern _DWORD dword_5d4594_1123524;
extern _DWORD dword_5d4594_1064192;
extern _DWORD dword_5d4594_1045604;
extern _DWORD dword_5d4594_2386176;
extern _DWORD dword_587000_197424;
extern _DWORD dword_5d4594_1064816;
extern _DWORD dword_5d4594_529316;
extern _DWORD dword_5d4594_1309820;
extern _DWORD dword_5d4594_1062508;
extern _DWORD dword_5d4594_1049864;
extern _DWORD dword_5d4594_829480;
extern _DWORD dword_5d4594_1062512;
extern _DWORD dword_5d4594_1217464;
extern _DWORD dword_5d4594_830248;
extern _DWORD dword_5d4594_1569648;
extern _DWORD dword_5d4594_1599656;
extern _DWORD dword_5d4594_1049500;
extern _DWORD dword_5d4594_3798840;
extern _DWORD dword_5d4594_1309812;
extern _DWORD dword_5d4594_754036;
extern _DWORD dword_587000_155144;
extern _DWORD dword_5d4594_815700;
extern _DWORD dword_5d4594_741676;
extern _DWORD dword_5d4594_1047516;
extern _DWORD dword_5d4594_1308084;
extern _DWORD dword_5d4594_815000;
extern _DWORD dword_5d4594_3798824;
extern _DWORD dword_5d4594_1307780;
extern _DWORD dword_5d4594_3798820;
extern _DWORD dword_5d4594_1193516;
extern _DWORD dword_5d4594_1090048;
extern _DWORD dword_5d4594_816364;
extern _DWORD dword_5d4594_1049508;
extern _DWORD dword_5d4594_1049796;
extern _DWORD dword_5d4594_829492;
extern _DWORD dword_5d4594_1098576;
extern _DWORD dword_5d4594_1321040;
extern _DWORD dword_5d4594_2487236;
extern _DWORD dword_5d4594_3799432;
extern _DWORD dword_5d4594_830124;
extern _DWORD dword_587000_87412;
extern _DWORD dword_5d4594_1548476;
extern _DWORD dword_5d4594_2660652;
extern _DWORD dword_5d4594_1045636;
extern _DWORD dword_587000_87404;
extern _DWORD dword_5d4594_3798804;
extern _DWORD dword_5d4594_832476;
extern _DWORD dword_5d4594_1570272;
extern _DWORD dword_5d4594_1305684;
extern _DWORD dword_5d4594_2386940;
extern _DWORD dword_5d4594_2523752;
extern _DWORD dword_5d4594_815132;

typedef struct mem_mapping {
	uintptr_t base;
	void* ptr;
	size_t size;
	bool invalid;
} mem_mapping;

mem_mapping mappings[] = {
    // overrides
	{0x5D4594+815132, (void*)&dword_5d4594_815132, sizeof(dword_5d4594_815132), 1},
	{0x5D4594+2523752, (void*)&dword_5d4594_2523752, sizeof(dword_5d4594_2523752), 1},
	{0x5D4594+2386940, (void*)&dword_5d4594_2386940, sizeof(dword_5d4594_2386940), 1},
	{0x5D4594+1305684, (void*)&dword_5d4594_1305684, sizeof(dword_5d4594_1305684), 1},
	{0x5D4594+1570272, (void*)&dword_5d4594_1570272, sizeof(dword_5d4594_1570272), 1},
	{0x5D4594+832476, (void*)&dword_5d4594_832476, sizeof(dword_5d4594_832476), 1},
	{0x5D4594+3798804, (void*)&dword_5d4594_3798804, sizeof(dword_5d4594_3798804), 1},
	{0x587000+87404, (void*)&dword_587000_87404, sizeof(dword_587000_87404), 1},
	{0x5D4594+1045636, (void*)&dword_5d4594_1045636, sizeof(dword_5d4594_1045636), 1},
	{0x5D4594+2660652, (void*)&dword_5d4594_2660652, sizeof(dword_5d4594_2660652), 1},
	{0x5D4594+1548476, (void*)&dword_5d4594_1548476, sizeof(dword_5d4594_1548476), 1},
	{0x587000+87412, (void*)&dword_587000_87412, sizeof(dword_587000_87412), 1},
	{0x5D4594+830124, (void*)&dword_5d4594_830124, sizeof(dword_5d4594_830124), 1},
	{0x5D4594+3799432, (void*)&dword_5d4594_3799432, sizeof(dword_5d4594_3799432), 1},
	{0x5D4594+2487236, (void*)&dword_5d4594_2487236, sizeof(dword_5d4594_2487236), 1},
	{0x5D4594+1321040, (void*)&dword_5d4594_1321040, sizeof(dword_5d4594_1321040), 1},
	{0x5D4594+1098576, (void*)&dword_5d4594_1098576, sizeof(dword_5d4594_1098576), 1},
	{0x5D4594+829492, (void*)&dword_5d4594_829492, sizeof(dword_5d4594_829492), 1},
	{0x5D4594+1049796, (void*)&dword_5d4594_1049796, sizeof(dword_5d4594_1049796), 1},
	{0x5D4594+1049508, (void*)&dword_5d4594_1049508, sizeof(dword_5d4594_1049508), 1},
	{0x5D4594+816364, (void*)&dword_5d4594_816364, sizeof(dword_5d4594_816364), 1},
	{0x5D4594+1090048, (void*)&dword_5d4594_1090048, sizeof(dword_5d4594_1090048), 1},
	{0x5D4594+1193516, (void*)&dword_5d4594_1193516, sizeof(dword_5d4594_1193516), 1},
	{0x5D4594+3798820, (void*)&dword_5d4594_3798820, sizeof(dword_5d4594_3798820), 1},
	{0x5D4594+1307780, (void*)&dword_5d4594_1307780, sizeof(dword_5d4594_1307780), 1},
	{0x5D4594+3798824, (void*)&dword_5d4594_3798824, sizeof(dword_5d4594_3798824), 1},
	{0x5D4594+815000, (void*)&dword_5d4594_815000, sizeof(dword_5d4594_815000), 1},
	{0x5D4594+1308084, (void*)&dword_5d4594_1308084, sizeof(dword_5d4594_1308084), 1},
	{0x5D4594+1047516, (void*)&dword_5d4594_1047516, sizeof(dword_5d4594_1047516), 1},
	{0x5D4594+741676, (void*)&dword_5d4594_741676, sizeof(dword_5d4594_741676), 1},
	{0x5D4594+815700, (void*)&dword_5d4594_815700, sizeof(dword_5d4594_815700), 1},
	{0x587000+155144, (void*)&dword_587000_155144, sizeof(dword_587000_155144), 1},
	{0x5D4594+754036, (void*)&dword_5d4594_754036, sizeof(dword_5d4594_754036), 1},
	{0x5D4594+1309812, (void*)&dword_5d4594_1309812, sizeof(dword_5d4594_1309812), 1},
	{0x5D4594+3798840, (void*)&dword_5d4594_3798840, sizeof(dword_5d4594_3798840), 1},
	{0x5D4594+1049500, (void*)&dword_5d4594_1049500, sizeof(dword_5d4594_1049500), 1},
	{0x5D4594+1599656, (void*)&dword_5d4594_1599656, sizeof(dword_5d4594_1599656), 1},
	{0x5D4594+1569648, (void*)&dword_5d4594_1569648, sizeof(dword_5d4594_1569648), 1},
	{0x5D4594+830248, (void*)&dword_5d4594_830248, sizeof(dword_5d4594_830248), 1},
	{0x5D4594+1217464, (void*)&dword_5d4594_1217464, sizeof(dword_5d4594_1217464), 1},
	{0x5D4594+1062512, (void*)&dword_5d4594_1062512, sizeof(dword_5d4594_1062512), 1},
	{0x5D4594+829480, (void*)&dword_5d4594_829480, sizeof(dword_5d4594_829480), 1},
	{0x5D4594+1049864, (void*)&dword_5d4594_1049864, sizeof(dword_5d4594_1049864), 1},
	{0x5D4594+1062508, (void*)&dword_5d4594_1062508, sizeof(dword_5d4594_1062508), 1},
	{0x5D4594+1309820, (void*)&dword_5d4594_1309820, sizeof(dword_5d4594_1309820), 1},
	{0x5D4594+529316, (void*)&dword_5d4594_529316, sizeof(dword_5d4594_529316), 1},
	{0x5D4594+1064816, (void*)&dword_5d4594_1064816, sizeof(dword_5d4594_1064816), 1},
	{0x587000+197424, (void*)&dword_587000_197424, sizeof(dword_587000_197424), 1},
	{0x5D4594+2386176, (void*)&dword_5d4594_2386176, sizeof(dword_5d4594_2386176), 1},
	{0x5D4594+1045604, (void*)&dword_5d4594_1045604, sizeof(dword_5d4594_1045604), 1},
	{0x5D4594+1064192, (void*)&dword_5d4594_1064192, sizeof(dword_5d4594_1064192), 1},
	{0x5D4594+1123524, (void*)&dword_5d4594_1123524, sizeof(dword_5d4594_1123524), 1},
	{0x5D4594+1316972, (void*)&dword_5d4594_1316972, sizeof(dword_5d4594_1316972), 1},
	{0x5D4594+3799624, (void*)&dword_5d4594_3799624, sizeof(dword_5d4594_3799624), 1},
	{0x587000+26048, (void*)&dword_587000_26048, sizeof(dword_587000_26048), 1},
	{0x5D4594+1193380, (void*)&dword_5d4594_1193380, sizeof(dword_5d4594_1193380), 1},
	{0x5D4594+1082856, (void*)&dword_5d4594_1082856, sizeof(dword_5d4594_1082856), 1},
	{0x5D4594+1046868, (void*)&dword_5d4594_1046868, sizeof(dword_5d4594_1046868), 1},
	{0x5D4594+1049504, (void*)&dword_5d4594_1049504, sizeof(dword_5d4594_1049504), 1},
	{0x5D4594+1189584, (void*)&dword_5d4594_1189584, sizeof(dword_5d4594_1189584), 1},
	{0x5D4594+2516328, (void*)&dword_5d4594_2516328, sizeof(dword_5d4594_2516328), 1},
	{0x5D4594+1090120, (void*)&dword_5d4594_1090120, sizeof(dword_5d4594_1090120), 1},
	{0x5D4594+1063116, (void*)&dword_5d4594_1063116, sizeof(dword_5d4594_1063116), 1},
	{0x5D4594+3799536, (void*)&dword_5d4594_3799536, sizeof(dword_5d4594_3799536), 1},
	{0x5D4594+2516348, (void*)&dword_5d4594_2516348, sizeof(dword_5d4594_2516348), 1},
	{0x5D4594+3801780, (void*)&dword_5d4594_3801780, sizeof(dword_5d4594_3801780), 1},
	{0x5D4594+1064916, (void*)&dword_5d4594_1064916, sizeof(dword_5d4594_1064916), 1},
	{0x5D4594+2386944, (void*)&dword_5d4594_2386944, sizeof(dword_5d4594_2386944), 1},
	{0x5D4594+787148, (void*)&dword_5d4594_787148, sizeof(dword_5d4594_787148), 1},
	{0x5D4594+810632, (void*)&dword_5d4594_810632, sizeof(dword_5d4594_810632), 1},
	{0x587000+80828, (void*)&dword_587000_80828, sizeof(dword_587000_80828), 1},
	{0x5D4594+825760, (void*)&dword_5d4594_825760, sizeof(dword_5d4594_825760), 1},
	{0x5D4594+3798796, (void*)&dword_5d4594_3798796, sizeof(dword_5d4594_3798796), 1},
	{0x5D4594+832484, (void*)&dword_5d4594_832484, sizeof(dword_5d4594_832484), 1},
	{0x5D4594+1062480, (void*)&dword_5d4594_1062480, sizeof(dword_5d4594_1062480), 1},
	{0x5D4594+815012, (void*)&dword_5d4594_815012, sizeof(dword_5d4594_815012), 1},
	{0x5D4594+815004, (void*)&dword_5d4594_815004, sizeof(dword_5d4594_815004), 1},
	{0x5D4594+1320940, (void*)&dword_5d4594_1320940, sizeof(dword_5d4594_1320940), 1},
	{0x5D4594+1217448, (void*)&dword_5d4594_1217448, sizeof(dword_5d4594_1217448), 1},
	{0x5D4594+2650652, (void*)&dword_5d4594_2650652, sizeof(dword_5d4594_2650652), 1},
	{0x5D4594+3798844, (void*)&dword_5d4594_3798844, sizeof(dword_5d4594_3798844), 1},
	{0x5D4594+1307784, (void*)&dword_5d4594_1307784, sizeof(dword_5d4594_1307784), 1},
	{0x5D4594+1045684, (void*)&dword_5d4594_1045684, sizeof(dword_5d4594_1045684), 1},
	{0x5D4594+3804672, (void*)&dword_5d4594_3804672, sizeof(dword_5d4594_3804672), 1},
	{0x5D4594+3804656, (void*)&dword_5d4594_3804656, sizeof(dword_5d4594_3804656), 1},
	{0x5D4594+1045516, (void*)&dword_5d4594_1045516, sizeof(dword_5d4594_1045516), 1},
	{0x5D4594+3804664, (void*)&dword_5d4594_3804664, sizeof(dword_5d4594_3804664), 1},
	{0x5D4594+814980, (void*)&dword_5d4594_814980, sizeof(dword_5d4594_814980), 1},
	{0x5D4594+830224, (void*)&dword_5d4594_830224, sizeof(dword_5d4594_830224), 1},
	{0x587000+133480, (void*)&dword_587000_133480, sizeof(dword_587000_133480), 1},
	{0x5D4594+1046492, (void*)&dword_5d4594_1046492, sizeof(dword_5d4594_1046492), 1},
	{0x5D4594+4668, (void*)&dword_5d4594_4668, sizeof(dword_5d4594_4668), 1},
	{0x5D4594+3799540, (void*)&dword_5d4594_3799540, sizeof(dword_5d4594_3799540), 1},
	{0x5D4594+1599636, (void*)&dword_5d4594_1599636, sizeof(dword_5d4594_1599636), 1},
	{0x5D4594+3798784, (void*)&dword_5d4594_3798784, sizeof(dword_5d4594_3798784), 1},
    {0x5D4594 + 260, (void*)&nox_loaded_thing_bin, sizeof(nox_loaded_thing_bin), 1},
    {0x5D4594 + 1296, (void*)&nox_file_10, sizeof(nox_file_10), 1},
    {0x5D4594 + 1300, (void*)&nox_file_10_mode, sizeof(nox_file_10_mode), 1},
    {0x5D4594 + 226904, (void*)file_buffer_w, sizeof(file_buffer_w), 1},
    {0x5D4594 + 247384, (void*)file_buffer, sizeof(file_buffer), 1},
    {0x5D4594 + 251488, (void*)&nox_file_1, sizeof(nox_file_1), 1},
    {0x5D4594 + 251492, (void*)&string_entries_cnt, sizeof(string_entries_cnt), 1},
    {0x5D4594 + 251500, (void*)&string_entries, sizeof(string_entries), 1},
    {0x5D4594 + 251520, (void*)&missing_strings, sizeof(missing_strings), 1},
    {0x5D4594 + 252264, (void*)&nox_file_4, sizeof(nox_file_4), 1},
    {0x5D4594 + 252268, (void*)&nox_file_5, sizeof(nox_file_5), 1},
    {0x5D4594 + 252272, (void*)&nox_file_net_log, sizeof(nox_file_net_log), 1},
    {0x5D4594 + 527688, (void*)&nox_file_2, sizeof(nox_file_2), 1},
    {0x5D4594 + 739988, (void*)&nox_file_3, sizeof(nox_file_3), 1},
    {0x5D4594 + 787204, (void*)&nox_video_bag_fileptr, sizeof(nox_video_bag_fileptr), 1},
    {0x5D4594 + 839880, (void*)&nox_file_log, sizeof(nox_file_log), 1},
    {0x5D4594 + 1309760, (void*)&nox_file_9, sizeof(nox_file_9), 1},
    {0x5D4594 + 1599584, (void*)&nox_file_8, sizeof(nox_file_8), 1},
    {0x5D4594 + 1599620, (void*)&nox_file_7, sizeof(nox_file_7), 1},
    {0x5D4594 + 3805496, (void*)&nox_win_width, sizeof(nox_win_width), 1},
    {0x5D4594 + 3807120, (void*)&nox_win_height, sizeof(nox_win_height), 1},
    {0x5D4594 + 251544, (void*)&dword_5D4594_251544, sizeof(dword_5D4594_251544), 1},
    {0x5D4594 + 251584, (void*)byte_5D4594_251584, sizeof(byte_5D4594_251584), 1},
    {0x5D4594 + 251596, (void*)&byte_5D4594_251596, sizeof(byte_5D4594_251596), 1},
    {0x5D4594 + 754088, (void*)&ptr_5D4594_754088, sizeof(ptr_5D4594_754088), 1},
    {0x5D4594 + 754092, (void*)&ptr_5D4594_754092, sizeof(ptr_5D4594_754092), 1},
    {0x5D4594 + 754096, (void*)&ptr_5D4594_754088_cnt, sizeof(ptr_5D4594_754088_cnt), 1},
    {0x5D4594 + 754100, (void*)&ptr_5D4594_754092_cnt, sizeof(ptr_5D4594_754092_cnt), 1},
    {0x5D4594 + 754104, (void*)&obj_5D4594_754104_switch, sizeof(obj_5D4594_754104_switch), 1},
    {0x5D4594 + 791324, (void*)nox_input_buffer, sizeof(nox_input_buffer), 1},
    {0x5D4594 + 805832, (void*)&nox_processing_input, sizeof(nox_processing_input), 1},
    {0x5D4594 + 805660, (void*)&nox_mouse, sizeof(nox_mouse), 1},
    {0x5D4594 + 805716, (void*)&nox_mouse_prev, sizeof(nox_mouse_prev), 1},
    {0x5D4594 + 805772, (void*)&nox_mouse_min, sizeof(nox_mouse_min), 1},
    {0x5D4594 + 805780, (void*)&nox_mouse_prev_left, sizeof(nox_mouse_prev_left), 1},
    {0x5D4594 + 805788, (void*)&nox_mouse_prev_right, sizeof(nox_mouse_prev_right), 1},
    {0x5D4594 + 805796, (void*)&nox_mouse_prev_middle, sizeof(nox_mouse_prev_middle), 1},
    {0x5D4594 + 805812, (void*)&nox_mouse_prev_seq, sizeof(nox_mouse_prev_seq), 1},
    {0x5D4594 + 805828, (void*)&nox_mouse_prev_seq_2, sizeof(nox_mouse_prev_seq_2), 1},
    {0x5D4594 + 830604, (void*)&nox_things_head, sizeof(nox_things_head), 1},
    {0x5D4594 + 830608, (void*)&nox_things_array, sizeof(nox_things_array), 1},
    {0x5D4594 + 830612, (void*)&nox_things_count, sizeof(nox_things_count), 1},
    {0x5D4594 + 1096472, (void*)&nox_drawable_list_3, sizeof(nox_drawable_list_3), 1},
    {0x5D4594 + 1096476, (void*)&nox_drawable_list_3_size, sizeof(nox_drawable_list_3_size), 1},
    {0x5D4594 + 1096480, (void*)&nox_drawable_list_2, sizeof(nox_drawable_list_2), 1},
    {0x5D4594 + 1096484, (void*)&nox_drawable_list_2_size, sizeof(nox_drawable_list_2_size), 1},
    {0x5D4594 + 1096488, (void*)&nox_drawable_list_4, sizeof(nox_drawable_list_4), 1},
    {0x5D4594 + 1096492, (void*)&nox_drawable_list_4_size, sizeof(nox_drawable_list_4_size), 1},
    {0x5D4594 + 1046568, (void*)&nox_drawable_head_unk2, sizeof(nox_drawable_head_unk2), 1},
    {0x5D4594 + 1046572, (void*)&nox_drawable_head_unk1, sizeof(nox_drawable_head_unk1), 1},
    {0x5D4594 + 1046580, (void*)&nox_drawable_head_unk3, sizeof(nox_drawable_head_unk3), 1},
    {0x5D4594 + 1046584, (void*)&nox_drawable_head_unk4, sizeof(nox_drawable_head_unk4), 1},
    {0x5D4594 + 1046588, (void*)&nox_drawable_count, sizeof(nox_drawable_count), 1},
    {0x5D4594 + 1046592, (void*)&nox_alloc_drawable, sizeof(nox_alloc_drawable), 1},
    {0x5D4594 + 1046860, (void*)&nox_win_unk1, sizeof(nox_win_unk1), 1},
    {0x5D4594 + 1062460, (void*)&nox_win_unk5, sizeof(nox_win_unk5), 1},
    {0x5D4594 + 1064892, (void*)&nox_win_unk4, sizeof(nox_win_unk4), 1},
    {0x5D4594 + 1064904, (void*)&nox_win_unk3, sizeof(nox_win_unk3), 1},
    {0x5D4594 + 1064908, (void*)&nox_win_unk2, sizeof(nox_win_unk2), 1},
    {0x5D4594 + 1064884, (void*)&nox_alloc_window, sizeof(nox_alloc_window), 1},
    {0x5D4594 + 1093116, (void*)&nox_win_cur_weapon, sizeof(nox_win_cur_weapon), 1},
    {0x5D4594 + 1193492, (void*)&nox_backbuffer1_pix, sizeof(nox_backbuffer1_pix), 1},
    {0x5D4594 + 1096464, (void*)&nox_drawable_list_1, sizeof(nox_drawable_list_1), 1},
    {0x5D4594 + 1096468, (void*)&nox_drawable_list_1_size, sizeof(nox_drawable_list_1_size), 1},
    {0x5D4594 + 1301784, (void*)&nox_drawable_2d_index, sizeof(nox_drawable_2d_index), 1},
    {0x5D4594 + 1301788, (void*)&nox_drawable_2d_index_size, sizeof(nox_drawable_2d_index_size), 1},
    {0x5D4594 + 1307296, (void*)&nox_win_main_menu, sizeof(nox_win_main_menu), 1},
    {0x5D4594 + 1307300, (void*)&nox_win_main_bg, sizeof(nox_win_main_bg), 1},
    {0x5D4594 + 3798752, (void*)&nox_backbuffer_pix, sizeof(nox_backbuffer_pix), 1},
    {0x5D4594 + 3801784, (void*)&nox_backbuffer_width, sizeof(nox_backbuffer_width), 1},
    {0x5D4594 + 3801788, (void*)&nox_backbuffer_height, sizeof(nox_backbuffer_height), 1},
    {0x5D4594 + 3799568, (void*)&nox_backbuffer_depth, sizeof(nox_backbuffer_depth), 1},
    {0x5D4594 + 3801800, (void*)&nox_backbuffer_width32, sizeof(nox_backbuffer_width32), 1},
    {0x5D4594 + 3799572, (void*)&ptr_5D4594_3799572, sizeof(ptr_5D4594_3799572), 1},
    {0x5D4594 + 3799660, (void*)&obj_5D4594_3799660, sizeof(obj_5D4594_3799660), 1},
    {0x5D4594 + 3800716, (void*)&obj_5D4594_3800716, sizeof(obj_5D4594_3800716), 1},
    {0x5D4594 + 3800716, (void*)&nox_draw_unk1, sizeof(nox_draw_unk1), 1},
    {0x5D4594 + 2650668, (void*)&ptr_5D4594_2650668, sizeof(ptr_5D4594_2650668), 1},
    {0x5D4594 + 2650636, (void*)&nox_common_engineFlags, sizeof(nox_common_engineFlags), 1},
    {0x5D4594 + 3600, (void*)&nox_common_gameFlags, sizeof(nox_common_gameFlags), 1},
    {0x5D4594 + 3532, (void*)&nox_server_gameSettingsUpdated, sizeof(nox_server_gameSettingsUpdated), 1},
    {0x5D4594 + 3801772, (void*)&nox_video_renderTargetFlags, sizeof(nox_video_renderTargetFlags), 1},
    {0x5D4594 + 805868, (void*)&nox_video_dxUnlockSurface, sizeof(nox_video_dxUnlockSurface), 1},
    {0x5D4594 + 1193676, (void*)&nox_video_pauseThreadedDrawCursor, sizeof(nox_video_pauseThreadedDrawCursor), 1},
    {0x5D4594 + 1193660, (void*)&nox_video_drawCursorThreadOk, sizeof(nox_video_drawCursorThreadOk), 1},
    {0x5D4594 + 1193680, (void*)&nox_video_allowCursorDrawThread, sizeof(nox_video_allowCursorDrawThread), 1},
    {0x5D4594 + 3798724, (void*)&nox_video_cursorDrawIsThreaded, sizeof(nox_video_cursorDrawIsThreaded), 1},
    {0x5D4594 + 1097200, (void*)&nox_client_mouseCursorType, sizeof(nox_client_mouseCursorType), 1},

    {0x587000 + 80, (void*)&nox_enable_audio, sizeof(nox_enable_audio), 1},
    {0x587000 + 5184, (void*)table_5184, sizeof(void*) * 1023, 1},         // TODO
    {0x587000 + 26792, (void*)table_26792, sizeof(table_26792_t) * 17, 1}, // TODO
    {0x587000 + 27008, (void*)table_27008, sizeof(table_27008_t) * 7, 1},  // TODO
    {0x587000 + 27104, (void*)table_27104, sizeof(table_27104_t) * 4, 1},  // TODO
    {0x587000 + 27168, (void*)table_27168, sizeof(table_27168_t) * 12, 1}, // TODO
    {0x587000 + 28760, (void*)table_28760, sizeof(table_28760_t) * 17, 1}, // TODO
    {0x587000 + 80764, (void*)&nox_mouse_max, sizeof(nox_mouse_max), 1},
    {0x587000 + 80804, (void*)&nox_enable_threads, sizeof(nox_enable_threads), 1},
    {0x587000 + 80856, (void*)&nox_max_width, sizeof(nox_max_width), 1},
    {0x587000 + 80860, (void*)&nox_max_height, sizeof(nox_max_height), 1},
    {0x587000 + 91780, (void*)&nox_win_width_1, sizeof(nox_win_width_1), 1},
    {0x587000 + 91784, (void*)&nox_win_height_1, sizeof(nox_win_height_1), 1},
    {0x587000 + 91788, (void*)&nox_win_depth_1, sizeof(nox_win_depth_1), 1},
    {0x587000 + 91792, (void*)&nox_win_width_2, sizeof(nox_win_width_2), 1},
    {0x587000 + 91796, (void*)&nox_win_height_2, sizeof(nox_win_height_2), 1},
    {0x587000 + 91800, (void*)&nox_win_depth_2, sizeof(nox_win_depth_2), 1},
    {0x587000 + 91804, (void*)nox_video_modes, sizeof(nox_video_mode) * 3, 1},
    {0x587000 + 94464, (void*)&nox_cheats_disabled, sizeof(nox_cheats_disabled), 1},
    {0x587000 + 116008, (void*)&nox_parse_thing_draw_funcs, sizeof(nox_parse_thing_draw_funcs_t) * 69, 1}, // TODO
    {0x587000 + 122104, (void*)&nox_parse_thing_funcs, sizeof(nox_parse_thing_funcs_t) * 21, 1},           // TODO
    {0x587000 + 80848, (void*)&nox_video_dxFullScreen, sizeof(nox_video_dxFullScreen), 1},
    {0x587000 + 84400, (void*)&nox_video_gammaValue, sizeof(nox_video_gammaValue), 1},
    {0x5D4594 + 1193656, (void*)&nox_video_cursorDrawThreadHandle, sizeof(nox_video_cursorDrawThreadHandle), 1},
    {0x5D4594 + 3799620, (void*)&nox_video_windowsPlatformVersion, sizeof(nox_video_windowsPlatformVersion), 1},
// full blobs
#if 0
        {0x563002, (void*)byte_563002, sizeof(byte_563002),0},
    {0x563006, (void*)byte_563006, sizeof(byte_563006),0},
#endif
    {0x581450, (void*)byte_581450, sizeof(byte_581450), 0},
    {0x587000, (void*)byte_587000, sizeof(byte_587000), 0},
    {0x5D4594, (void*)byte_5D4594, sizeof(byte_5D4594), 0},
    {0x9800B0, (void*)asc_9800B0, sizeof(asc_9800B0), 0},
    {0x980858, (void*)mix_dword_980858, sizeof(mix_dword_980858), 0},
};

size_t mappings_cnt = sizeof(mappings) / sizeof(mem_mapping);

_BYTE* getMem(uintptr_t addr) {
	for (int i = 0; i < mappings_cnt; i++) {
		mem_mapping* m = &mappings[i];
		if (addr >= m->base && addr < m->base + (uintptr_t)m->size) {
			if (m->invalid)
				break;
			addr -= m->base;
			return &((_BYTE*)m->ptr)[addr];
		}
	}
	fprintf(stderr, "Invalid memory access! Requested = %x\n", addr);
	DebugBreak();
	return 0;
}