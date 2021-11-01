#ifndef COMPAT_MSS_H
#define COMPAT_MSS_H

#include <stdint.h>

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif
typedef struct {
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
}
#ifndef _MSC_VER
__attribute__((packed))
#endif
WAVEFORMAT2,
	*LPWAVEFORMAT2;

typedef struct {
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
	uint16_t cbSize;
}
#ifndef _MSC_VER
__attribute__((packed))
#endif
WAVEFORMATEX2;

typedef struct {
	WAVEFORMATEX2 wfx;
	uint16_t wID;
	uint32_t fdwFlags;
	uint16_t nBlockSize;
	uint16_t nFramesPerBlock;
	uint16_t nCodecDelay;
}
#ifndef _MSC_VER
__attribute__((packed))
#endif
MPEGLAYER3WAVEFORMAT2;

#ifdef _MSC_VER
#pragma pack(pop)
#endif

typedef struct _DIG_DRIVER* HDIGDRIVER;
typedef struct _SAMPLE* HSAMPLE;
typedef struct _STREAM* HSTREAM;
typedef struct _TIMER* HTIMER;

typedef struct {
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
} *NOX_WAVEFORMAT;

typedef void(*AILTIMERCB)(uint32_t user);
typedef void(*AILSAMPLECB)(HSAMPLE sample);

HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig);
void AIL_close_stream(HSTREAM stream);
void AIL_digital_configuration(HDIGDRIVER dig, int32_t* rate, int32_t* format, char* string);
int32_t AIL_digital_handle_release(HDIGDRIVER drvr);
int32_t AIL_digital_handle_reacquire(HDIGDRIVER drvr);
void AIL_end_sample(HSAMPLE S);
int32_t AIL_get_preference(uint32_t number);
void AIL_init_sample(HSAMPLE S);
char* AIL_last_error(void);
void AIL_load_sample_buffer(HSAMPLE S, uint32_t buff_num, void* buffer, uint32_t len);
HSTREAM AIL_open_stream(HDIGDRIVER dig, char* filename, int32_t stream_mem);
void AIL_pause_stream(HSTREAM stream, int32_t onoff);
void AIL_register_EOB_callback(HSAMPLE S, AILSAMPLECB EOB);
void AIL_register_EOS_callback(HSAMPLE S, AILSAMPLECB EOS);
HTIMER AIL_register_timer(AILTIMERCB fn);
void AIL_release_sample_handle(HSAMPLE S);
void AIL_release_timer_handle(HTIMER timer);
void AIL_resume_sample(HSAMPLE S);
int32_t AIL_sample_buffer_ready(HSAMPLE S);
int32_t AIL_sample_user_data(HSAMPLE S, uint32_t index);
void AIL_serve(void);
int32_t AIL_set_preference(uint32_t number, int32_t value);
void AIL_set_sample_adpcm_block_size(HSAMPLE S, uint32_t blocksize);
void AIL_set_sample_pan(HSAMPLE S, int32_t pan);
void AIL_set_sample_playback_rate(HSAMPLE S, int32_t playback_rate);
void AIL_set_sample_type(HSAMPLE S, int32_t format, uint32_t flags);
void AIL_set_sample_user_data(HSAMPLE S, uint32_t index, int32_t value);
void AIL_set_sample_volume(HSAMPLE S, int32_t volume);
void AIL_set_stream_position(HSTREAM stream, int32_t offset);
void AIL_set_stream_volume(HSTREAM stream, int32_t volume);
void AIL_set_timer_frequency(HTIMER timer, uint32_t hertz);
void AIL_shutdown(void);
void AIL_start_stream(HSTREAM stream);
void AIL_start_timer(HTIMER timer);
int32_t AIL_startup(void);
void AIL_stop_sample(HSAMPLE S);
void AIL_stop_timer(HTIMER timer);
int32_t AIL_stream_position(HSTREAM stream);
int32_t AIL_stream_status(HSTREAM stream);
void AIL_waveOutClose(HDIGDRIVER drvr);
int32_t AIL_waveOutOpen(HDIGDRIVER* drvr, int32_t wDeviceID, NOX_WAVEFORMAT lpFormat);

#endif // COMPAT_MSS_H
