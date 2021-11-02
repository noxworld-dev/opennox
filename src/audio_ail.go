package nox

/*
#include <stdint.h>
#include "client/audio/ail/compat_mss.h"

static void nox_audio_call_timer_cb(void(*f)(uint32_t), uint32_t u) { f(u); }
static void nox_audio_call_sample_cb(void(*f)(HSAMPLE), HSAMPLE s) { f(s); }
*/
import "C"
import (
	"unsafe"

	"nox/v1/client/audio/ail"
)

//export AIL_allocate_sample_handle
func AIL_allocate_sample_handle(dig C.HDIGDRIVER) C.HSAMPLE {
	s := ail.Driver(unsafe.Pointer(dig)).AllocateSample()
	return C.HSAMPLE(unsafe.Pointer(s))
}

//export AIL_release_sample_handle
func AIL_release_sample_handle(s C.HSAMPLE) {
	ail.Sample(unsafe.Pointer(s)).Release()
}

//export AIL_open_stream
func AIL_open_stream(dig C.HDIGDRIVER, name *C.char, mem C.int32_t) C.HSTREAM {
	s := ail.Driver(unsafe.Pointer(dig)).OpenStream(GoString(name), int(mem))
	return C.HSTREAM(unsafe.Pointer(s))
}

//export AIL_close_stream
func AIL_close_stream(s C.HSTREAM) {
	ail.Stream(unsafe.Pointer(s)).Close()
}

//export AIL_register_timer
func AIL_register_timer(f C.AILTIMERCB) C.HTIMER {
	return C.HTIMER(unsafe.Pointer(ail.RegisterTimer(func(u uint32) {
		C.nox_audio_call_timer_cb(f, C.uint32_t(u))
	})))
}

//export AIL_release_timer_handle
func AIL_release_timer_handle(h C.HTIMER) {
	ail.Timer(unsafe.Pointer(h)).Release()
}

//export AIL_digital_configuration
func AIL_digital_configuration(dig C.HDIGDRIVER, rate *C.int32_t, fmt *C.int32_t, str *C.char) {
	if str != nil {
		*str = 0
	}
}

//export AIL_digital_handle_release
func AIL_digital_handle_release(h C.HDIGDRIVER) C.int32_t {
	return 0
}

//export AIL_digital_handle_reacquire
func AIL_digital_handle_reacquire(h C.HDIGDRIVER) C.int32_t {
	return 0
}

//export AIL_end_sample
func AIL_end_sample(s C.HSAMPLE) {
	ail.Sample(unsafe.Pointer(s)).End()
}

//export AIL_get_preference
func AIL_get_preference(s C.uint32_t) C.int32_t {
	return 0
}

//export AIL_init_sample
func AIL_init_sample(s C.HSAMPLE) {
	ail.Sample(unsafe.Pointer(s)).Init()
}

//export AIL_last_error
func AIL_last_error() *C.char {
	e := ail.LastError()
	if e != "" {
		return internCStr(e)
	}
	return nil
}

//export AIL_load_sample_buffer
func AIL_load_sample_buffer(s C.HSAMPLE, num C.uint32_t, buf unsafe.Pointer, sz C.uint32_t) {
	ail.Sample(unsafe.Pointer(s)).LoadBuffer(uint32(num), unsafe.Slice((*byte)(buf), int(sz)))
}

//export AIL_pause_stream
func AIL_pause_stream(s C.HSTREAM, onoff C.int32_t) {
	ail.Stream(unsafe.Pointer(s)).Pause(onoff != 0)
}

//export AIL_register_EOB_callback
func AIL_register_EOB_callback(s C.HSAMPLE, f C.AILSAMPLECB) {
	ail.Sample(unsafe.Pointer(s)).RegisterEOBCallback(func() {
		C.nox_audio_call_sample_cb(f, s)
	})
}

//export AIL_register_EOS_callback
func AIL_register_EOS_callback(s C.HSAMPLE, f C.AILSAMPLECB) {
	ail.Sample(unsafe.Pointer(s)).RegisterEOSCallback(func() {
		C.nox_audio_call_sample_cb(f, s)
	})
}

//export AIL_resume_sample
func AIL_resume_sample(s C.HSAMPLE) {
	panic("abort")
}

//export AIL_sample_buffer_ready
func AIL_sample_buffer_ready(s C.HSAMPLE) C.int32_t {
	return C.int32_t(ail.Sample(unsafe.Pointer(s)).BufferReady())
}

//export AIL_sample_user_data
func AIL_sample_user_data(s C.HSAMPLE, ind C.uint32_t) C.int32_t {
	return C.int32_t(ail.Sample(unsafe.Pointer(s)).UserData(int(ind)))
}

//export AIL_serve
func AIL_serve() {
	ail.Serve()
}

//export AIL_set_preference
func AIL_set_preference(num C.uint32_t, val C.int32_t) C.int32_t {
	return -1
}

//export AIL_set_sample_adpcm_block_size
func AIL_set_sample_adpcm_block_size(s C.HSAMPLE, block C.uint32_t) {
	ail.Sample(unsafe.Pointer(s)).SetADPCMBlockSize(uint32(block))
}

//export AIL_set_sample_pan
func AIL_set_sample_pan(s C.HSAMPLE, pan C.int32_t) {
	ail.Sample(unsafe.Pointer(s)).SetPan(int(pan))
}

//export AIL_set_sample_playback_rate
func AIL_set_sample_playback_rate(s C.HSAMPLE, rate C.int32_t) {
	ail.Sample(unsafe.Pointer(s)).SetPlaybackRate(int(rate))
}

//export AIL_set_sample_type
func AIL_set_sample_type(s C.HSAMPLE, format C.int32_t, flags C.uint32_t) {
	ail.Sample(unsafe.Pointer(s)).SetType(int32(format), uint32(flags))
}

//export AIL_set_sample_user_data
func AIL_set_sample_user_data(s C.HSAMPLE, index C.uint32_t, value C.int32_t) {
	ail.Sample(unsafe.Pointer(s)).SetUserData(int(index), int32(value))
}

//export AIL_set_sample_volume
func AIL_set_sample_volume(s C.HSAMPLE, volume C.int32_t) {
	ail.Sample(unsafe.Pointer(s)).SetVolume(int(volume))
}

//export AIL_set_stream_position
func AIL_set_stream_position(s C.HSTREAM, offset C.int32_t) {
	ail.Stream(unsafe.Pointer(s)).SetPosition(int(offset))
}

//export AIL_set_stream_volume
func AIL_set_stream_volume(s C.HSTREAM, volume C.int32_t) {
	ail.Stream(unsafe.Pointer(s)).SetVolume(int(volume))
}

//export AIL_set_timer_frequency
func AIL_set_timer_frequency(t C.HTIMER, hertz C.uint32_t) {
	ail.Timer(unsafe.Pointer(t)).SetFrequency(uint(hertz))
}

//export AIL_shutdown
func AIL_shutdown() {
	ail.Shutdown()
}

//export AIL_start_stream
func AIL_start_stream(s C.HSTREAM) {
	ail.Stream(unsafe.Pointer(s)).Start()
}

//export AIL_start_timer
func AIL_start_timer(t C.HTIMER) {
	ail.Timer(unsafe.Pointer(t)).Start()
}

//export AIL_startup
func AIL_startup() C.int32_t {
	return C.int32_t(ail.Startup())
}

//export AIL_stop_sample
func AIL_stop_sample(s C.HSAMPLE) {
	ail.Sample(unsafe.Pointer(s)).Stop()
}

//export AIL_stop_timer
func AIL_stop_timer(t C.HTIMER) {
	ail.Timer(unsafe.Pointer(t)).Stop()
}

//export AIL_stream_position
func AIL_stream_position(s C.HSTREAM) C.int32_t {
	return C.int32_t(ail.Stream(unsafe.Pointer(s)).Position())
}

//export AIL_stream_status
func AIL_stream_status(s C.HSTREAM) C.int32_t {
	return C.int32_t(ail.Stream(unsafe.Pointer(s)).Status())
}

//export AIL_waveOutClose
func AIL_waveOutClose(drvr C.HDIGDRIVER) {
	ail.Driver(unsafe.Pointer(drvr)).Close()
}

//export AIL_waveOutOpen
func AIL_waveOutOpen(pdrvr *C.HDIGDRIVER, wDeviceID C.int32_t, lpFormat C.NOX_WAVEFORMAT) C.int32_t {
	d := ail.WaveOutOpen()
	*pdrvr = C.HDIGDRIVER(unsafe.Pointer(d))
	return 0
}
