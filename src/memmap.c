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

typedef struct mem_mapping {
	uintptr_t base;
	void* ptr;
	size_t size;
	bool invalid;
} mem_mapping;

mem_mapping mappings[] = {
    // overrides
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