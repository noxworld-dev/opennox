#include "../../../defs.h"
#include <SDL2/SDL.h>

struct _SAMPLE {
	int h;
};
struct _STREAM {
	int h;
};
struct _TIMER {
	int h;
};

DXDEC HSAMPLE AILCALL AIL_allocate_sample_handle(HDIGDRIVER dig) {
	HSAMPLE sample = 0;
	sample = calloc(1, sizeof(*sample));
	return sample;
}

DXDEC void AILCALL AIL_release_sample_handle(HSAMPLE S) {
	free(S);
}

DXDEC HSTREAM AILCALL AIL_open_stream(HDIGDRIVER dig, char const FAR* filename, S32 stream_mem) {
	HSTREAM stream = 0;
	stream = calloc(1, sizeof(*stream));
	return stream;
}

DXDEC void AILCALL AIL_close_stream(HSTREAM stream) {
	free(stream);
}

DXDEC HTIMER AILCALL AIL_register_timer(AILTIMERCB fn) {
	HTIMER timer = 0;
	timer = calloc(1, sizeof(*timer));
	return timer;
}

DXDEC void AILCALL AIL_release_timer_handle(HTIMER timer) {
	free(timer);
}

DXDEC void AILCALL AIL_digital_configuration(HDIGDRIVER dig, S32 FAR* rate, S32 FAR* format, char FAR* string) {}

DXDEC S32 AILCALL AIL_digital_handle_release(HDIGDRIVER drvr) { return 0; }

DXDEC S32 AILCALL AIL_digital_handle_reacquire(HDIGDRIVER drvr) { return 0; }

DXDEC void AILCALL AIL_end_sample(HSAMPLE S) {}

DXDEC S32 AILCALL AIL_get_preference(U32 number) { return 0; }

DXDEC void AILCALL AIL_init_sample(HSAMPLE S) {}

DXDEC char FAR* AILCALL AIL_last_error(void) { return 0; }

DXDEC void AILCALL AIL_load_sample_buffer(HSAMPLE S, U32 buff_num, void const FAR* buffer, U32 len) {}

DXDEC void AILCALL AIL_pause_stream(HSTREAM stream, S32 onoff) {}

DXDEC AILSAMPLECB AILCALL AIL_register_EOB_callback(HSAMPLE S, AILSAMPLECB EOB) { return NULL; }

DXDEC AILSAMPLECB AILCALL AIL_register_EOS_callback(HSAMPLE S, AILSAMPLECB EOS) { return NULL; }

DXDEC void AILCALL AIL_resume_sample(HSAMPLE S) {}

DXDEC S32 AILCALL AIL_sample_buffer_ready(HSAMPLE S) { return -1; }

DXDEC S32 AILCALL AIL_sample_user_data(HSAMPLE S, U32 index) { return -1; }

DXDEC void AILCALL AIL_serve(void) {}

DXDEC S32 AILCALL AIL_set_preference(U32 number, S32 value) { return -1; }

DXDEC void AILCALL AIL_set_sample_adpcm_block_size(HSAMPLE S, U32 blocksize) {}

DXDEC void AILCALL AIL_set_sample_pan(HSAMPLE S, S32 pan) {}

DXDEC void AILCALL AIL_set_sample_playback_rate(HSAMPLE S, S32 playback_rate) {}

DXDEC void AILCALL AIL_set_sample_type(HSAMPLE S, S32 format, U32 flags) {}

DXDEC void AILCALL AIL_set_sample_user_data(HSAMPLE S, U32 index, S32 value) {}

DXDEC void AILCALL AIL_set_sample_volume(HSAMPLE S, S32 volume) {}

DXDEC void AILCALL AIL_set_stream_position(HSTREAM stream, S32 offset) {}

DXDEC void AILCALL AIL_set_stream_volume(HSTREAM stream, S32 volume) {}

DXDEC void AILCALL AIL_set_timer_frequency(HTIMER timer, U32 hertz) {}

DXDEC void AILCALL AIL_shutdown(void) {}

DXDEC void AILCALL AIL_start_stream(HSTREAM stream) {}

DXDEC void AILCALL AIL_start_timer(HTIMER timer) {}

DXDEC S32 AILCALL AIL_startup(void) { return -1; }

DXDEC void AILCALL AIL_stop_sample(HSAMPLE S) {}

DXDEC void AILCALL AIL_stop_timer(HTIMER timer) {}

DXDEC S32 AILCALL AIL_stream_position(HSTREAM stream) { return -1; }

DXDEC S32 AILCALL AIL_stream_status(HSTREAM stream) { return -1; }

DXDEC void AILCALL AIL_waveOutClose(HDIGDRIVER drvr) {}

DXDEC S32 AILCALL AIL_waveOutOpen(HDIGDRIVER FAR* pdrvr, LPHWAVEOUT FAR* lphWaveOut, S32 wDeviceID,
								  LPWAVEFORMAT lpFormat) {
	return 0;
}
