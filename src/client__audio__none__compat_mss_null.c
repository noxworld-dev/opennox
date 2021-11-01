//+build none

#include "defs.h"

struct _SAMPLE {
	int h;
};
struct _STREAM {
	int h;
};
struct _TIMER {
	int h;
};

HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig) {
	HSAMPLE sample = 0;
	sample = calloc(1, sizeof(*sample));
	return sample;
}

void AIL_release_sample_handle(HSAMPLE S) {
	free(S);
}

HSTREAM AIL_open_stream(HDIGDRIVER dig, char* filename, int32_t stream_mem) {
	HSTREAM stream = 0;
	stream = calloc(1, sizeof(*stream));
	return stream;
}

void AIL_close_stream(HSTREAM stream) {
	free(stream);
}

HTIMER AIL_register_timer(AILTIMERCB fn) {
	HTIMER timer = 0;
	timer = calloc(1, sizeof(*timer));
	return timer;
}

void AIL_release_timer_handle(HTIMER timer) {
	free(timer);
}

void AIL_digital_configuration(HDIGDRIVER dig, int32_t* rate, int32_t* format, char* string) {}

int32_t AIL_digital_handle_release(HDIGDRIVER drvr) { return 0; }

int32_t AIL_digital_handle_reacquire(HDIGDRIVER drvr) { return 0; }

void AIL_end_sample(HSAMPLE S) {}

int32_t AIL_get_preference(uint32_t number) { return 0; }

void AIL_init_sample(HSAMPLE S) {}

char* AIL_last_error(void) { return 0; }

void AIL_load_sample_buffer(HSAMPLE S, uint32_t buff_num, void* buffer, uint32_t len) {}

void AIL_pause_stream(HSTREAM stream, int32_t onoff) {}

void AIL_register_EOB_callback(HSAMPLE S, AILSAMPLECB EOB) {}

void AIL_register_EOS_callback(HSAMPLE S, AILSAMPLECB EOS) {}

void AIL_resume_sample(HSAMPLE S) {}

int32_t AIL_sample_buffer_ready(HSAMPLE S) { return -1; }

int32_t AIL_sample_user_data(HSAMPLE S, uint32_t index) { return -1; }

void AIL_serve(void) {}

int32_t AIL_set_preference(uint32_t number, int32_t value) { return -1; }

void AIL_set_sample_adpcm_block_size(HSAMPLE S, uint32_t blocksize) {}

void AIL_set_sample_pan(HSAMPLE S, int32_t pan) {}

void AIL_set_sample_playback_rate(HSAMPLE S, int32_t playback_rate) {}

void AIL_set_sample_type(HSAMPLE S, int32_t format, uint32_t flags) {}

void AIL_set_sample_user_data(HSAMPLE S, uint32_t index, int32_t value) {}

void AIL_set_sample_volume(HSAMPLE S, int32_t volume) {}

void AIL_set_stream_position(HSTREAM stream, int32_t offset) {}

void AIL_set_stream_volume(HSTREAM stream, int32_t volume) {}

void AIL_set_timer_frequency(HTIMER timer, uint32_t hertz) {}

void AIL_shutdown(void) {}

void AIL_start_stream(HSTREAM stream) {}

void AIL_start_timer(HTIMER timer) {}

int32_t AIL_startup(void) { return -1; }

void AIL_stop_sample(HSAMPLE S) {}

void AIL_stop_timer(HTIMER timer) {}

int32_t AIL_stream_position(HSTREAM stream) { return -1; }

int32_t AIL_stream_status(HSTREAM stream) { return 2; }

void AIL_waveOutClose(HDIGDRIVER drvr) {}

int32_t AIL_waveOutOpen(HDIGDRIVER* pdrvr, int32_t wDeviceID, NOX_WAVEFORMAT lpFormat) {
	return 0;
}
