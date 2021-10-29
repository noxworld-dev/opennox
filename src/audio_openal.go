//go:build !server
// +build !server

package nox

/*
#include <stdint.h>
#include "compat_mss.h"

static void nox_audio_call_timer_cb(void(*f)(uint32_t), uint32_t u) { f(u); }
static void nox_audio_call_sample_cb(void(*f)(HSAMPLE), HSAMPLE s) { f(s); }

#define MINIMP3_ONLY_MP3
#define MINIMP3_NO_SIMD
#include "client/audio/mp3/minimp3.h"
*/
import "C"
import (
	"encoding/binary"
	"fmt"
	"io"
	"math"
	"os"
	"sync"
	"sync/atomic"
	"time"
	"unsafe"

	"github.com/timshannon/go-openal/openal"

	"nox/v1/common/alloc/handles"
	"nox/v1/common/env"
	"nox/v1/common/fs"
	"nox/v1/common/log"
)

var (
	audioLog     = log.New("audio")
	audioDebug   = os.Getenv("NOX_DEBUG_AUDIO") == "true"
	audioSamples struct {
		sync.RWMutex
		byHandle map[unsafe.Pointer]*audioSample
	}
	audioStreams struct {
		sync.RWMutex
		byHandle map[unsafe.Pointer]*audioStream
	}
	audioDrivers struct {
		sync.RWMutex
		byHandle map[unsafe.Pointer]*audioDriver
	}
	audioTimers struct {
		sync.RWMutex
		byHandle map[unsafe.Pointer]*audioTimer
	}
)

func init() {
	audioSamples.byHandle = make(map[unsafe.Pointer]*audioSample)
	audioStreams.byHandle = make(map[unsafe.Pointer]*audioStream)
	audioDrivers.byHandle = make(map[unsafe.Pointer]*audioDriver)
	audioTimers.byHandle = make(map[unsafe.Pointer]*audioTimer)
}

func audioGetDriver(h unsafe.Pointer) *audioDriver {
	handles.AssertValidPtr(h)
	audioDrivers.RLock()
	s := audioDrivers.byHandle[h]
	audioDrivers.RUnlock()
	return s
}

func audioGetStream(h unsafe.Pointer) *audioStream {
	handles.AssertValidPtr(h)
	audioStreams.RLock()
	s := audioStreams.byHandle[h]
	audioStreams.RUnlock()
	return s
}

func audioGetSample(h unsafe.Pointer) *audioSample {
	handles.AssertValidPtr(h)
	audioSamples.RLock()
	s := audioSamples.byHandle[h]
	audioSamples.RUnlock()
	return s
}

func audioGetTimer(h unsafe.Pointer) *audioTimer {
	handles.AssertValidPtr(h)
	audioTimers.RLock()
	s := audioTimers.byHandle[h]
	audioTimers.RUnlock()
	return s
}

type audioDriver struct {
	h          unsafe.Pointer
	dev        *openal.Device
	ctx        *openal.Context
	mu         sync.Mutex
	sampleHead *audioSample
	streamHead *audioStream
	t          *time.Ticker
}

type audioSampleBuf struct {
	buf []byte
	pos int
}

type audioSample struct {
	h       unsafe.Pointer
	d       *audioDriver
	playing uint32 // atomic

	next    *audioSample
	source  openal.Source
	hwbuf   openal.Buffers
	hwready int

	bmu     sync.Mutex
	buffers [2]audioSampleBuf
	current byte
	ready   byte

	stereo bool
	adpcm  bool

	playback_rate uint32
	block_size    uint32

	eob  func()
	eos  func()
	user [8]int32
}

func (s *audioSample) IsPlaying() bool {
	return atomic.LoadUint32(&s.playing) != 0
}

func (s *audioSample) Play() {
	atomic.StoreUint32(&s.playing, 1)
}

func (s *audioSample) Stop() {
	atomic.StoreUint32(&s.playing, 0)
}

func (s *audioSample) EOS() {
	s.Stop()
	if s.eos != nil {
		s.d.mu.Unlock()
		s.eos()
		s.d.mu.Lock()
	}
}

func (s *audioSample) EOB() {
	s.bmu.Lock()
	s.ready++
	if s.current == 0 {
		s.current = 1
	} else {
		s.current = 0
	}
	s.bmu.Unlock()
	if s.eob != nil {
		s.d.mu.Unlock()
		s.eob()
		s.d.mu.Lock()
	}
}

type audioStreamType int

const (
	audioPCM = audioStreamType(iota + 1)
	audioADPCM
	audioMP3
)

type audioStream struct {
	h unsafe.Pointer
	d *audioDriver

	next    *audioStream
	source  openal.Source
	hwbuf   openal.Buffers
	hwready int

	stereo        bool
	playback_rate uint32
	playing       bool

	file       *os.File
	filename   string
	file_size  int
	chunk_size int
	chunk_pos  int
	buffered   int

	typ audioStreamType
	pcm struct {
		wf       waveFormat
		position int
	}
	adpcm struct {
		wf       waveFormat
		position int
		samples  int
	}
	mp3 struct {
		wf  waveFormatMP3
		dec C.mp3dec_t
	}

	buffer [16 * 1024 * 3]byte
}

func (s *audioStream) Channels() int {
	if s.stereo {
		return 2
	}
	return 1
}

func (s *audioStream) findData() error {
	var tmp [8]byte

	s.chunk_size = 0
	s.chunk_pos = 0

	for {
		off, err := s.file.Seek(0, io.SeekCurrent)
		if err != nil {
			audioLog.Println(err)
			return err
		} else if int(off) >= s.file_size {
			return io.EOF
		}
		_, err = io.ReadFull(s.file, tmp[:])
		if err != nil {
			audioLog.Println("find", err)
			return err
		}
		size := int(binary.LittleEndian.Uint32(tmp[4:]))
		if string(tmp[:4]) == "data" {
			s.chunk_size = size
			return nil
		}
		_, err = s.file.Seek(int64(size), io.SeekCurrent)
		if err != nil {
			audioLog.Println(err)
			return err
		}
	}
}

type audioTimer struct {
	h    unsafe.Pointer
	t    *time.Ticker
	dt   time.Duration
	f    func(u uint32)
	user uint32
}

func sat16(x int) int16 {
	if x < math.MinInt16 {
		return math.MinInt16
	} else if x > math.MaxInt16 {
		return math.MaxInt16
	}
	return int16(x)
}

func satindex(x int) int {
	if x < 0 {
		return 0
	} else if x > 88 {
		return 88
	}
	return x
}

var (
	ima_index_table = [16]int{-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8}
	ima_step_table  = [89]int{
		7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23,
		25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80,
		88, 97, 107, 118, 130, 143, 157, 173, 190, 209, 230, 253, 279,
		307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796, 876, 963,
		1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327,
		3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487,
		12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767,
	}
)

func decodeNibble(predictor int16, nibble byte, index int) int16 {
	diff := 0
	step := ima_step_table[index]

	diff = step >> 3
	if nibble&4 != 0 {
		diff += step
	}
	if nibble&2 != 0 {
		diff += step >> 1
	}
	if nibble&1 != 0 {
		diff += step >> 2
	}
	if nibble&8 != 0 {
		predictor = sat16(int(predictor) - diff)
	} else {
		predictor = sat16(int(predictor) + diff)
	}
	return predictor
}

func decode_adpcm(out []int16, data []byte) []int16 {
	predictor := int16(data[0]) | (int16(data[1]) << 8)
	index := int(data[2])

	out = append(out, predictor)
	for i := 4; i < len(data); i++ {
		predictor = decodeNibble(predictor, data[i], index)
		index = satindex(index + ima_index_table[data[i]&15])
		out = append(out, predictor)

		predictor = decodeNibble(predictor, data[i]>>4, index)
		index = satindex(index + ima_index_table[data[i]>>4])
		out = append(out, predictor)
	}
	return out
}

func decode_adpcm_stereo(out []int16, data []byte) []int16 {
	lpredictor := int16(data[0]) | (int16(data[1]) << 8)
	lindex := int(data[2])
	rpredictor := int16(data[4]) | (int16(data[5]) << 8)
	rindex := int(data[6])

	out = append(out, lpredictor, rpredictor)
	for i := 8; i < len(data); i += 8 {
		for j := 0; j < 4; j++ {
			lpredictor = decodeNibble(lpredictor, data[i+j], lindex)
			lindex = satindex(lindex + ima_index_table[data[i+j]&15])
			out = append(out, lpredictor)

			rpredictor = decodeNibble(rpredictor, data[i+j+4], rindex)
			rindex = satindex(rindex + ima_index_table[data[i+j+4]&15])
			out = append(out, rpredictor)

			lpredictor = decodeNibble(lpredictor, data[i+j]>>4, lindex)
			lindex = satindex(lindex + ima_index_table[data[i+j]>>4])
			out = append(out, lpredictor)

			rpredictor = decodeNibble(rpredictor, data[i+j+4]>>4, rindex)
			rindex = satindex(rindex + ima_index_table[data[i+j+4]>>4])
			out = append(out, rpredictor)
		}
	}
	return out
}

func (s *audioStream) seek(pos int) {
	switch s.typ {
	case audioPCM:
		s.pcm_seek(pos)
	case audioADPCM:
		s.adpcm_seek(pos)
	case audioMP3:
		s.mp3_seek(pos)
	default:
		panic("unsupported")
	}
}

func (s *audioStream) tell() uint32 {
	switch s.typ {
	case audioPCM:
		return s.pcm_tell()
	case audioADPCM:
		return s.adpcm_tell()
	case audioMP3:
		return s.mp3_tell()
	default:
		panic("unsupported")
	}
}

func (s *audioStream) decode(out []int16, max int) uint32 {
	switch s.typ {
	case audioPCM:
		return s.pcm_decode(out, max)
	case audioADPCM:
		return s.adpcm_decode(out, max)
	case audioMP3:
		return s.mp3_decode(out, max)
	default:
		panic("unsupported")
	}
}

func (s *audioStream) pcm_decode(out []int16, max int) uint32 {
	remaining := int(s.chunk_size - s.chunk_pos)

	if remaining == 0 {
		remaining = s.decodeFind()
		if remaining == 0 {
			return 0
		}
	}

	if remaining/2 >= max {
		remaining = max * 2
	}

	channels := s.Channels()
	// TODO(dennwc): reuse
	buf := make([]byte, remaining)
	io.ReadFull(s.file, buf)
	for i := 0; i+1 < len(buf); i += 2 {
		out[i/2] = int16(binary.LittleEndian.Uint16(buf[i:]))
	}
	s.pcm.position += remaining / 2 / channels
	return uint32(remaining / 2)
}

func (s *audioStream) pcm_seek(position int) {
	// TODO
	s.pcm.position = 0
}

func (s *audioStream) pcm_tell() uint32 {
	return uint32(s.pcm.position)
}

func (s *audioStream) decodeFind() int {
	s.findData()
	remaining := s.chunk_size - s.chunk_pos
	if remaining == 0 {
		s.playing = false
	}
	return remaining
}

func (s *audioStream) adpcm_decode(out []int16, max int) uint32 {
	block_size := int(s.adpcm.wf.blockAlign)

	samples := 0
	if s.adpcm.position >= s.adpcm.samples {
		s.playing = false
		return 0
	}

	if s.buffered < block_size {
		remaining := s.chunk_size - s.chunk_pos

		if remaining == 0 {
			remaining = s.decodeFind()
			if remaining == 0 {
				return 0
			}
		}

		if remaining > block_size-s.buffered {
			remaining = block_size - s.buffered
		}
		io.ReadFull(s.file, s.buffer[s.buffered:s.buffered+remaining])
		s.buffered += remaining
	}

	if s.stereo {
		out = decode_adpcm_stereo(out[:0], s.buffer[:block_size])
	} else {
		out = decode_adpcm(out[:0], s.buffer[:block_size])
	}
	samples = len(out) // TODO(dennwc): is it true for stereo?

	s.buffered -= block_size
	if s.buffered != 0 {
		copy(s.buffer[0:], s.buffer[block_size:block_size+s.buffered])
	}
	channels := s.Channels()
	if samples/channels+s.adpcm.position >= s.adpcm.samples {
		samples = (s.adpcm.samples - s.adpcm.position) * channels
	}
	s.adpcm.position += samples / channels
	return uint32(samples)
}

func (s *audioStream) adpcm_seek(position int) {
	block_size := int(s.adpcm.wf.blockAlign)
	channels := s.Channels()
	samples_per_block := (block_size/channels - 4) * 2
	blocks := position / samples_per_block
	s.adpcm.position = 0

	for s.adpcm.position < position {
		s.findData()
		if s.chunk_size == 0 {
			break
		}
		chunk_blocks := s.chunk_size / block_size
		if blocks < chunk_blocks {
			s.file.Seek(int64(blocks*block_size), io.SeekCurrent)
			s.adpcm.position += blocks * samples_per_block
			break
		} else {
			s.file.Seek(int64(s.chunk_size), io.SeekCurrent)
			s.adpcm.position += chunk_blocks * samples_per_block
		}
	}

	// TODO seek within an ADPCM block
}

func (s *audioStream) adpcm_tell() uint32 {
	return uint32(s.adpcm.position)
}

func (s *audioStream) mp3_decode(out []int16, max int) uint32 {
	remaining := s.chunk_size - s.chunk_pos
	samples := 0
	var info C.mp3dec_frame_info_t

	if s.buffered < len(s.buffer) {
		if remaining == 0 && s.buffered == 0 {
			remaining = s.decodeFind()
			if remaining == 0 {
				return 0
			}
		}
		if remaining != 0 {
			if remaining > len(s.buffer)-s.buffered {
				remaining = len(s.buffer) - s.buffered
			}
			io.ReadFull(s.file, s.buffer[s.buffered:s.buffered+remaining])
			s.buffered += remaining
		}
	}

	for {
		samples = int(C.mp3dec_decode_frame(&s.mp3.dec, (*C.uchar)(unsafe.Pointer(&s.buffer[0])), C.int(s.buffered), (*C.short)(unsafe.Pointer(&out[0])), &info))
		if samples != 0 {
			break
		}
		if remaining == 0 {
			remaining = s.decodeFind()
			if remaining == 0 {
				return 0
			}
		}
		if remaining != 0 {
			if remaining > len(s.buffer)-s.buffered {
				remaining = len(s.buffer) - s.buffered
			}
			io.ReadFull(s.file, s.buffer[s.buffered:s.buffered+remaining])
			s.buffered += remaining
		}
	}

	frame_bytes := int(info.frame_bytes)
	s.buffered -= frame_bytes
	if s.buffered != 0 {
		copy(s.buffer[0:], s.buffer[frame_bytes:frame_bytes+s.buffered])
	}

	return uint32(samples)
}

func (s *audioStream) mp3_seek(position int) {
	C.mp3dec_init(&s.mp3.dec)
}

func (s *audioStream) mp3_tell() uint32 {
	return 0
}

func audioCheckError() {
	if err := openal.Err(); err != nil {
		audioLog.Println(err)
	}
}

func (s *audioSample) unqueueBuffers() {
	processed := int(s.source.Geti(openal.AlBuffersProcessed))
	audioCheckError()
	if processed != 0 {
		s.source.UnqueueBuffers(s.hwbuf[s.hwready : s.hwready+processed])
		audioCheckError()
	}
	s.hwready += processed
}

func (s *audioStream) unqueueBuffers() {
	processed := int(s.source.Geti(openal.AlBuffersProcessed))
	audioCheckError()
	if processed != 0 {
		s.source.UnqueueBuffers(s.hwbuf[s.hwready : s.hwready+processed])
		audioCheckError()
	}
	s.hwready += processed
}

//export AIL_allocate_sample_handle
func AIL_allocate_sample_handle(dig C.HDIGDRIVER) C.HSAMPLE {
	if env.IsE2E() {
		h := handles.NewPtr()
		return C.HSAMPLE(h)
	}
	if audioDebug {
		audioLog.Println("AIL_allocate_sample_handle")
	}
	d := audioGetDriver(unsafe.Pointer(dig))

	s := &audioSample{
		h:      handles.NewPtr(),
		d:      d,
		source: openal.NewSource(),
	}
	audioCheckError()

	s.hwbuf = openal.NewBuffers(4)
	s.hwready = 4
	audioCheckError()

	d.mu.Lock()
	s.next = d.sampleHead
	d.sampleHead = s
	d.mu.Unlock()

	audioSamples.Lock()
	audioSamples.byHandle[s.h] = s
	audioSamples.Unlock()
	return C.HSAMPLE(s.h)
}

//export AIL_release_sample_handle
func AIL_release_sample_handle(s C.HSAMPLE) {
	if audioDebug {
		audioLog.Println("AIL_release_sample_handle")
	}
	handles.AssertValidPtr(unsafe.Pointer(s))
}

func audioOpenStream(path string) (*audioStream, error) {
	f, err := fs.Open(path)
	if err != nil {
		return nil, err
	}
	s := &audioStream{file: f, filename: path}
	if err = s.open(); err != nil {
		_ = f.Close()
		return nil, err
	}
	return s, nil
}

type waveFormat struct {
	format         uint16
	channels       uint16
	samplesPerSec  uint32
	avgBytesPerSec uint32
	blockAlign     uint16
}

type waveFormatMP3 struct {
	waveFormat
	bitsPerSample  uint16
	size           uint16
	id             uint16
	flags          uint32
	blockSize      uint16
	framesPerBlock uint16
	codecDelay     uint16
}

func (s *audioStream) open() error {
	var tmp [256]byte
	_, err := io.ReadFull(s.file, tmp[:20])
	if err != nil {
		return err
	}
	if magic := string(tmp[0:4]); magic != "RIFF" {
		return fmt.Errorf("invalid audio file magic: %q", magic)
	}
	s.file_size = int(binary.LittleEndian.Uint32(tmp[4:8]))
	if str := string(tmp[8:12]); str != "WAVE" {
		return fmt.Errorf("invalid audio file section: %q", str)
	}
	// +12
	size := int(binary.LittleEndian.Uint32(tmp[16:20]))
	if str := string(tmp[12:16]); str != "fmt " {
		return fmt.Errorf("invalid audio file section 2: %q", str)
	}
	if size < 14 || size > cap(tmp) {
		return fmt.Errorf("invalid audio header size: %d", size)
	}
	_, err = io.ReadFull(s.file, tmp[:size])
	if err != nil {
		return err
	}
	wf := waveFormat{
		format:         binary.LittleEndian.Uint16(tmp[0:2]),
		channels:       binary.LittleEndian.Uint16(tmp[2:4]),
		samplesPerSec:  binary.LittleEndian.Uint32(tmp[4:8]),
		avgBytesPerSec: binary.LittleEndian.Uint32(tmp[8:12]),
		blockAlign:     binary.LittleEndian.Uint16(tmp[12:14]),
	}
	switch wf.format {
	case 0x01: // PCM
		s.typ = audioPCM
		s.playback_rate = wf.samplesPerSec
		s.stereo = wf.channels > 1
		s.pcm.wf = wf
		audioLog.Printf("PCM stream: %q, %d channels", s.filename, wf.channels)
		return nil
	case 0x11: // ADPCM
		s.typ = audioADPCM
		s.playback_rate = wf.samplesPerSec
		s.stereo = wf.channels > 1
		s.adpcm.wf = wf
		_, err = io.ReadFull(s.file, tmp[:12])
		if err != nil {
			return err
		}
		if str := string(tmp[0:4]); str != "fact" {
			return fmt.Errorf("invalid ADPCM file section: %q", str)
		}
		if sz := binary.LittleEndian.Uint32(tmp[4:8]); sz != 4 {
			return fmt.Errorf("unsupported ADPCM size: %q", sz)
		}
		s.adpcm.samples = int(binary.LittleEndian.Uint32(tmp[8:12]))
		audioLog.Printf("ADPCM stream: %q, %d channels", s.filename, wf.channels)
		return nil
	case 0x55: // MP3
		if size < 14+16 {
			return fmt.Errorf("invalid MP3 header size: %d", size)
		}
		s.typ = audioMP3
		wf3 := waveFormatMP3{waveFormat: wf}
		wf3.bitsPerSample = binary.LittleEndian.Uint16(tmp[14:16])
		wf3.size = binary.LittleEndian.Uint16(tmp[16:18])
		wf3.id = binary.LittleEndian.Uint16(tmp[18:20])
		wf3.flags = binary.LittleEndian.Uint32(tmp[20:24])
		wf3.blockSize = binary.LittleEndian.Uint16(tmp[24:26])
		wf3.framesPerBlock = binary.LittleEndian.Uint16(tmp[26:28])
		wf3.codecDelay = binary.LittleEndian.Uint16(tmp[28:30])
		s.playback_rate = wf3.samplesPerSec
		s.stereo = wf3.channels > 1
		s.mp3.wf = wf3
		C.mp3dec_init(&s.mp3.dec)
		audioLog.Printf("MP3 stream: %q, %d channels", s.filename, wf3.channels)
		return nil
	default:
		return fmt.Errorf("unsupported format: 0x%x", wf.format)
	}
}

//export AIL_open_stream
func AIL_open_stream(dig C.HDIGDRIVER, name *C.char, mem C.int32_t) C.HSTREAM {
	if audioDebug {
		audioLog.Println("AIL_open_stream")
	}
	if env.IsE2E() {
		h := handles.NewPtr()
		return C.HSTREAM(h)
	}
	d := audioGetDriver(unsafe.Pointer(dig))

	s, err := audioOpenStream(C.GoString(name))
	if err != nil {
		audioLog.Println(err)
		return nil
	}
	s.d = d
	s.h = handles.NewPtr()
	s.source = openal.NewSource()
	audioCheckError()
	s.hwbuf = openal.NewBuffers(2)
	s.hwready = 2

	d.mu.Lock()
	s.next = d.streamHead
	d.streamHead = s
	d.mu.Unlock()

	audioStreams.Lock()
	audioStreams.byHandle[s.h] = s
	audioStreams.Unlock()
	return C.HSTREAM(s.h)
}

//export AIL_close_stream
func AIL_close_stream(h C.HSTREAM) {
	if audioDebug {
		audioLog.Println("AIL_close_stream")
	}
	if env.IsE2E() {
		handles.AssertValidPtr(unsafe.Pointer(h))
		return
	}
	s := audioGetStream(unsafe.Pointer(h))
	s.d.mu.Lock()
	s.playing = false
	s.d.mu.Unlock()
}

//export AIL_register_timer
func AIL_register_timer(f C.AILTIMERCB) C.HTIMER {
	if audioDebug {
		audioLog.Println("AIL_register_timer")
	}
	if env.IsE2E() {
		h := handles.NewPtr()
		return C.HTIMER(h)
	}
	h := handles.NewPtr()
	t := &audioTimer{h: h, f: func(u uint32) {
		C.nox_audio_call_timer_cb(f, C.uint32_t(u))
	}}

	audioTimers.Lock()
	audioTimers.byHandle[h] = t
	audioTimers.Unlock()
	return C.HTIMER(h)
}

//export AIL_release_timer_handle
func AIL_release_timer_handle(h C.HTIMER) {
	if audioDebug {
		audioLog.Println("AIL_release_timer_handle")
	}
	handles.AssertValidPtr(unsafe.Pointer(h))
}

//export AIL_digital_configuration
func AIL_digital_configuration(dig C.HDIGDRIVER, rate *C.int32_t, fmt *C.int32_t, str *C.char) {
	if audioDebug {
		audioLog.Println("AIL_digital_configuration")
	}
	if str != nil {
		*str = 0
	}
}

//export AIL_digital_handle_release
func AIL_digital_handle_release(h C.HDIGDRIVER) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_digital_handle_release")
	}
	return 0
}

//export AIL_digital_handle_reacquire
func AIL_digital_handle_reacquire(h C.HDIGDRIVER) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_digital_handle_reacquire")
	}
	return 0
}

//export AIL_end_sample
func AIL_end_sample(h C.HSAMPLE) {
	if audioDebug {
		audioLog.Println("AIL_end_sample")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))

	s.d.mu.Lock()
	defer s.d.mu.Unlock()
	if s.IsPlaying() {
		s.EOB()
		s.EOS()
	}
}

//export AIL_get_preference
func AIL_get_preference(s C.uint32_t) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_get_preference")
	}
	return 0
}

//export AIL_init_sample
func AIL_init_sample(h C.HSAMPLE) {
	if audioDebug {
		audioLog.Println("AIL_init_sample")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))

	s.d.mu.Lock()
	defer s.d.mu.Unlock()

	s.bmu.Lock()
	s.current = 0
	s.ready = 2
	s.bmu.Unlock()

	s.source.Setf(openal.AlPitch, 1)
	s.source.Setf(openal.AlGain, 1)
	AIL_set_sample_pan(h, 63)

	s.Stop()
	s.source.Stop()
	s.unqueueBuffers()
}

//export AIL_last_error
func AIL_last_error() *C.char {
	if audioDebug {
		audioLog.Println("AIL_last_error")
	}
	return nil
}

//export AIL_load_sample_buffer
func AIL_load_sample_buffer(h C.HSAMPLE, num C.uint32_t, buf unsafe.Pointer, sz C.uint32_t) {
	if audioDebug {
		audioLog.Printf("AIL_load_sample_buffer: [%d]", int(sz))
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.bmu.Lock()
	defer s.bmu.Unlock()
	sb := &s.buffers[num]
	if sz == 0 {
		sb.buf = nil
	} else {
		sb.buf = unsafe.Slice((*byte)(buf), int(sz))
	}
	sb.pos = 0
	s.Play()
}

//export AIL_pause_stream
func AIL_pause_stream(h C.HSTREAM, pause C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_pause_stream")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetStream(unsafe.Pointer(h))
	// TODO: mutex?
	s.playing = pause == 0
}

//export AIL_register_EOB_callback
func AIL_register_EOB_callback(h C.HSAMPLE, f C.AILSAMPLECB) {
	if audioDebug {
		audioLog.Println("AIL_register_EOB_callback")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.eob = func() {
		C.nox_audio_call_sample_cb(f, h)
	}
}

//export AIL_register_EOS_callback
func AIL_register_EOS_callback(h C.HSAMPLE, f C.AILSAMPLECB) {
	if audioDebug {
		audioLog.Println("AIL_register_EOS_callback")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.eos = func() {
		C.nox_audio_call_sample_cb(f, h)
	}
}

//export AIL_resume_sample
func AIL_resume_sample(s C.HSAMPLE) {
	if audioDebug {
		audioLog.Println("AIL_resume_sample")
	}
	panic("abort")
}

//export AIL_sample_buffer_ready
func AIL_sample_buffer_ready(h C.HSAMPLE) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_sample_buffer_ready")
	}
	if env.IsE2E() {
		return -1
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.bmu.Lock()
	defer s.bmu.Unlock()
	if s.ready == 0 {
		return -1
	}
	if s.ready == 2 {
		s.ready--
		return 0
	}
	s.ready--
	if s.current == 0 {
		return 1
	}
	return 0
}

//export AIL_sample_user_data
func AIL_sample_user_data(h C.HSAMPLE, ind C.uint32_t) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_sample_user_data")
	}
	if env.IsE2E() {
		return -1
	}
	s := audioGetSample(unsafe.Pointer(h))
	return C.int32_t(s.user[ind])
}

//export AIL_serve
func AIL_serve() {
	if audioDebug {
		audioLog.Println("AIL_serve")
	}
}

//export AIL_set_preference
func AIL_set_preference(num C.uint32_t, val C.int32_t) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_set_preference")
	}
	return -1
}

//export AIL_set_sample_adpcm_block_size
func AIL_set_sample_adpcm_block_size(h C.HSAMPLE, block C.uint32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_sample_adpcm_block_size")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.block_size = uint32(block)
}

//export AIL_set_sample_pan
func AIL_set_sample_pan(h C.HSAMPLE, pan C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_sample_pan")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	pos := [3]float32{float32(pan-63) / 64.0, 0, 0}
	pos[2] = float32(math.Sqrt(float64(1 - pos[0]*pos[0])))
	s.source.Setfv(openal.AlPosition, pos[:])
}

//export AIL_set_sample_playback_rate
func AIL_set_sample_playback_rate(h C.HSAMPLE, rate C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_sample_playback_rate")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.playback_rate = uint32(rate)
}

//export AIL_set_sample_type
func AIL_set_sample_type(h C.HSAMPLE, format C.int32_t, flags C.uint32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_sample_type")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	if flags != 0 {
		panic("abort")
	}
	s.stereo = format&2 != 0
	s.adpcm = format&4 != 0
}

//export AIL_set_sample_user_data
func AIL_set_sample_user_data(h C.HSAMPLE, index C.uint32_t, value C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_sample_user_data")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.user[index] = int32(value)
}

//export AIL_set_sample_volume
func AIL_set_sample_volume(h C.HSAMPLE, volume C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_sample_volume")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.source.Setf(openal.AlGain, float32(volume)/127.0)
}

//export AIL_set_stream_position
func AIL_set_stream_position(h C.HSTREAM, offset C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_stream_position")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetStream(unsafe.Pointer(h))
	s.d.mu.Lock()
	defer s.d.mu.Unlock()
	s.chunk_size = 0
	s.chunk_pos = 0
	s.buffered = 0
	s.file.Seek(12, io.SeekStart)
	s.seek(int(offset))
}

//export AIL_set_stream_volume
func AIL_set_stream_volume(h C.HSTREAM, volume C.int32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_stream_volume", int(volume))
	}
	if env.IsE2E() {
		return
	}
	s := audioGetStream(unsafe.Pointer(h))
	s.source.Setf(openal.AlGain, float32(volume)/127.0)
}

//export AIL_set_timer_frequency
func AIL_set_timer_frequency(h C.HTIMER, hertz C.uint32_t) {
	if audioDebug {
		audioLog.Println("AIL_set_timer_frequency")
	}
	if env.IsE2E() {
		return
	}
	t := audioGetTimer(unsafe.Pointer(h))
	t.dt = time.Duration(1000.0/float32(hertz)) * time.Millisecond
}

//export AIL_start_stream
func AIL_start_stream(h C.HSTREAM) {
	if audioDebug {
		audioLog.Println("AIL_start_stream")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetStream(unsafe.Pointer(h))
	s.playing = true
}

//export AIL_start_timer
func AIL_start_timer(h C.HTIMER) {
	if audioDebug {
		audioLog.Println("AIL_start_timer")
	}
	if env.IsE2E() {
		return
	}
	t := audioGetTimer(unsafe.Pointer(h))
	dt := t.dt
	tm := time.NewTicker(dt)
	t.t = tm
	go func() {
		for range tm.C {
			t.f(t.user)
			if t.dt != dt {
				tm.Reset(t.dt)
				dt = t.dt
			}
		}
	}()
}

//export AIL_startup
func AIL_startup() C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_startup")
	}
	return -1
}

//export AIL_shutdown
func AIL_shutdown() {
	if audioDebug {
		audioLog.Println("AIL_shutdown")
	}
	if env.IsE2E() {
		return
	}
	audioTimers.Lock()
	for _, t := range audioTimers.byHandle {
		if t.t != nil {
			t.t.Stop()
		}
	}
	audioTimers.Unlock()
	audioDrivers.Lock()
	for _, d := range audioDrivers.byHandle {
		if d.t != nil {
			d.t.Stop()
		}
	}
	audioDrivers.Unlock()
}

//export AIL_stop_sample
func AIL_stop_sample(h C.HSAMPLE) {
	if audioDebug {
		audioLog.Println("AIL_stop_sample")
	}
	if env.IsE2E() {
		return
	}
	s := audioGetSample(unsafe.Pointer(h))
	s.Stop() // TODO: anything else here?
}

//export AIL_stop_timer
func AIL_stop_timer(h C.HTIMER) {
	if audioDebug {
		audioLog.Println("AIL_stop_timer")
	}
	if env.IsE2E() {
		return
	}
	t := audioGetTimer(unsafe.Pointer(h))
	if t.t != nil {
		t.t.Stop()
	}
}

//export AIL_stream_position
func AIL_stream_position(h C.HSTREAM) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_stream_position")
	}
	if env.IsE2E() {
		return -1
	}
	s := audioGetStream(unsafe.Pointer(h))
	return C.int32_t(s.tell())
}

//export AIL_stream_status
func AIL_stream_status(h C.HSTREAM) C.int32_t {
	if env.IsE2E() {
		return 2
	}
	s := audioGetStream(unsafe.Pointer(h))
	if s.playing {
		return 4
	}
	return 2
}

//export AIL_waveOutClose
func AIL_waveOutClose(h C.HDIGDRIVER) {
	if audioDebug {
		audioLog.Println("AIL_waveOutClose")
	}
	if env.IsE2E() {
		return
	}
	d := audioGetDriver(unsafe.Pointer(h))
	if d.t != nil {
		d.t.Stop()
	}
}

func (s *audioSample) play_adpcm(data []byte) {
	if !s.adpcm {
		panic("abort")
	}

	var decoded []int16
	if s.stereo {
		decoded = decode_adpcm_stereo(decoded, data)
	} else {
		decoded = decode_adpcm(decoded, data)
	}

	s.hwready--

	format := openal.FormatMono16
	if s.stereo {
		format = openal.FormatStereo16
	}

	s.hwbuf[s.hwready].SetDataInt16(format, decoded, int32(s.playback_rate))
	audioCheckError()
	s.source.QueueBuffer(s.hwbuf[s.hwready])
	audioCheckError()
}

func (s *audioSample) work() {
	if !s.IsPlaying() {
		return
	}

	s.bmu.Lock()
	if s.ready == 2 {
		s.bmu.Unlock()
		s.EOS()
		return
	}

	buf := &s.buffers[s.current]
	if len(buf.buf) == 0 {
		s.bmu.Unlock()
		s.EOB()
		s.EOS()
		return
	}
	defer s.bmu.Unlock()
	s.unqueueBuffers()

	for s.hwready != 0 {
		s.play_adpcm(buf.buf[buf.pos : buf.pos+int(s.block_size)])
		buf.pos += int(s.block_size)

		if s.IsPlaying() && s.source.State() != openal.Playing {
			s.source.Play()
		}

		if buf.pos >= len(buf.buf) {
			s.bmu.Unlock()
			s.EOB()
			s.bmu.Lock()
			buf = &s.buffers[s.current]
			if len(buf.buf) == 0 {
				break
			}
		}
	}
}

func (s *audioStream) work() {
	if !s.playing {
		return
	}
	var buffer [16 * 1024 * 3]int16
	channels := s.Channels()
	// We need to queue 100ms of audio data.
	min_samples := int(s.playback_rate) * channels / 10

	s.unqueueBuffers()

	for s.hwready != 0 {
		offset := 0

		for offset < min_samples {
			samples := s.decode(buffer[offset:], min_samples*2-offset)
			if samples == 0 {
				break
			}
			offset += int(samples)
		}

		if offset == 0 {
			break
		}

		s.hwready--

		format := openal.FormatMono16
		if s.stereo {
			format = openal.FormatStereo16
		}

		s.hwbuf[s.hwready].SetDataInt16(format, buffer[:offset], int32(s.playback_rate))
		audioCheckError()
		s.source.QueueBuffer(s.hwbuf[s.hwready])
		audioCheckError()

		state := s.source.State()
		if s.playing && state != openal.Playing {
			s.source.Play()
		}
	}
}

func (d *audioDriver) doWork() {
	d.mu.Lock()
	defer d.mu.Unlock()
	for s := d.sampleHead; s != nil; s = s.next {
		s.work()
	}
	for s := d.streamHead; s != nil; s = s.next {
		s.work()
	}
}

//export AIL_waveOutOpen
func AIL_waveOutOpen(pdrvr *C.HDIGDRIVER, lphWaveOut *C.LPHWAVEOUT, wDeviceID C.int32_t, lpFormat C.LPWAVEFORMAT) C.int32_t {
	if audioDebug {
		audioLog.Println("AIL_waveOutOpen")
	}
	if env.IsE2E() {
		return 0
	}
	h := handles.NewPtr()

	d := &audioDriver{h: h}
	d.dev = openal.OpenDevice("")
	if d.dev == nil {
		if err := openal.Err(); err != nil {
			audioLog.Println("error opening device:", err)
		} else {
			audioLog.Println("cannot open device")
		}
		return 0
	}
	audioLog.Println("device ok")
	d.ctx = d.dev.CreateContext()
	if d.ctx == nil {
		if err := openal.Err(); err != nil {
			audioLog.Println("error creating context:", err)
		} else {
			audioLog.Println("cannot create context")
		}
		return 0
	}
	audioLog.Println("context ok")
	d.ctx.Activate()
	if err := openal.Err(); err != nil {
		audioLog.Println("error activating context:", err)
		return 0
	}

	openal.Listener{}.Setf(openal.AlGain, 1)
	openal.Listener{}.Setfv(openal.AlPosition, []float32{0, 0, 0})
	d.t = time.NewTicker(time.Second / 20)
	go func() {
		for range d.t.C {
			d.doWork()
		}
	}()

	audioDrivers.Lock()
	audioDrivers.byHandle[h] = d
	audioDrivers.Unlock()

	*pdrvr = (C.HDIGDRIVER)(h)
	return 0
}
