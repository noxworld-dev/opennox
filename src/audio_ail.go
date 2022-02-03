package nox

/*
#include <stdint.h>
#include "client/audio/ail/compat_mss.h"
#include "client__io__win95__focus.h"

void sub_43E910(int a1);
void sub_43E8E0(int a1);
void* sub_486EF0();
void sub_43D2D0();
uint32_t* sub_486620(uint32_t* a1);
void sub_43EDB0(HSAMPLE a1);
int sub_43EE00(int a1);
int sub_43F060(uint32_t* a1);
int sub_43F0E0(uint32_t* a1);
void sub_44D5C0(int a1, int a2);
char* sub_413890();
uint32_t* sub_486320(uint32_t* a1, int a2);
void sub_43D3C0(int a1, int a2);
int sub_486350(void* a1, int a2);
int sub_486640(void* a1, int a2);

extern void* dword_587000_127004;
extern uint32_t dword_5d4594_816092;
extern uint32_t dword_5d4594_816364;
extern uint32_t dword_5d4594_816376;
extern uint32_t dword_5d4594_830872;
extern uint32_t dword_5d4594_831088;
extern uint32_t dword_5d4594_831092;
extern uint32_t dword_587000_122856;
extern uint32_t dword_587000_122848;
*/
import "C"
import (
	"math"
	"path/filepath"
	"strings"
	"unsafe"

	"nox/v1/client/audio/ail"
	"nox/v1/common/alloc"
	"nox/v1/common/memmap"
)

//export AIL_end_sample
func AIL_end_sample(s C.HSAMPLE) {
	ail.Sample(unsafe.Pointer(s)).End()
}

//export AIL_load_sample_buffer
func AIL_load_sample_buffer(s C.HSAMPLE, num C.uint32_t, buf unsafe.Pointer, sz C.uint32_t) {
	ail.Sample(unsafe.Pointer(s)).LoadBuffer(uint32(num), unsafe.Slice((*byte)(buf), int(sz)))
}

//export sub_43F030
func sub_43F030(a1 C.int) C.int {
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

//export AIL_set_stream_volume
func AIL_set_stream_volume(s C.HSTREAM, volume C.int32_t) {
	ail.Stream(unsafe.Pointer(s)).SetVolume(int(volume))
}

//export AIL_stream_position
func AIL_stream_position(s C.HSTREAM) C.int32_t {
	return C.int32_t(ail.Stream(unsafe.Pointer(s)).Position())
}

//export AIL_stream_status
func AIL_stream_status(s C.HSTREAM) C.int32_t {
	return C.int32_t(ail.Stream(unsafe.Pointer(s)).Status())
}

var (
	audioTimer93944 ail.Timer = math.MaxUint32
	audioDev        ail.Driver
)

//export sub_43E940
func sub_43E940(a1 unsafe.Pointer) C.int {
	ail.Startup()
	audioTimer93944 = ail.RegisterTimer(func(u uint32) {
		C.sub_486EF0()
		C.sub_43D2D0()
		C.sub_486620((*C.uint32_t)(C.dword_587000_127004))
	})
	if audioTimer93944 == math.MaxUint32 {
		return -2147221504 // 0x80040000
	}
	audioTimer93944.SetFrequency(30)
	audioTimer93944.Start()
	C.sub_42EBB0(1, (*[0]byte)(C.sub_43E910), 0, internCStr("Audio"))
	C.sub_42EBB0(2, (*[0]byte)(C.sub_43E8E0), 0, internCStr("Audio"))
	*(*uint32)(unsafe.Add(a1, 20)) = 1
	return 0
}

//export sub_43E9F0
func sub_43E9F0() {
	if audioTimer93944 != math.MaxUint32 {
		audioTimer93944.Stop()
		audioTimer93944.Release()
		audioTimer93944 = math.MaxUint32
	}
	ail.Shutdown()
}

func noxAudioServeT(a1 int) { // sub_43F140
	noxAudioServe()
}

//export sub_43F050
func sub_43F050() C.int {
	return 0
}

//export sub_43F0D0
func sub_43F0D0() C.int {
	return 0
}

func noxAudioServe() { // sub_43F1A0
	if audioDev != 0 {
		ail.Serve()
	}
}

//export sub_43E8E0
func sub_43E8E0(a1 C.int) {}

//export sub_43E910
func sub_43E910(a1 C.int) {}

//export sub_43EA20
func sub_43EA20(a1 unsafe.Pointer) C.int {
	//char v2[16]; // [esp+4h] [ebp-10h]

	v2 := sub_43EA90(unsafe.Add(a1, 60))
	audioDev = sub_43EAD0(v2)
	if audioDev == 0 {
		return -2147221504 // 0x80040000
	}
	*memmap.PtrInt32(0x587000, 93948) = 0
	*(*uint32)(unsafe.Add(a1, 196)) = 24
	return 0
}

type audioStruct1 struct {
	Field0  uint16
	Field2  uint16
	Field4  uint32
	Field8  uint32
	Field12 uint16
	Field14 uint16
}

func sub_43EA90(a2 unsafe.Pointer) *audioStruct1 {
	return &audioStruct1{
		Field0:  1,
		Field2:  *(*uint16)(unsafe.Add(a2, 12)),
		Field4:  *(*uint32)(unsafe.Add(a2, 8)),
		Field8:  *(*uint32)(unsafe.Add(a2, 20)),
		Field12: *(*uint16)(unsafe.Add(a2, 16)) * *(*uint16)(unsafe.Add(a2, 12)),
		Field14: 8 * *(*uint16)(unsafe.Add(a2, 16)),
	}
}

func sub_43EAD0(a1 *audioStruct1) ail.Driver {
	if dr := ail.WaveOutOpen(); dr != 0 {
		return dr
	}
	_ = ail.LastError()
	return 0
}

//export sub_43EC10
func sub_43EC10() C.int {
	if audioDev != 0 {
		audioDev.Close()
		audioDev = 0
	}
	return 0
}

//export sub_43F130
func sub_43F130() C.int {
	return C.int(audioDev)
}

//export sub_43F010
func sub_43F010(a1 unsafe.Pointer) C.int {
	p := *(*unsafe.Pointer)(unsafe.Add(a1, 272))
	h := *(*uint32)(unsafe.Add(p, 8))
	ail.Sample(h).Stop()
	return 0
}

//export sub_43EC30
func sub_43EC30(a1 unsafe.Pointer) C.int {
	smp := audioDev.AllocateSample()
	v1, _ := alloc.Uints32(8)
	*(**uint32)(unsafe.Add(a1, 272)) = &v1[0]
	v1[0] = uint32(audioDev)
	v1[1] = uint32(uintptr(a1))
	v1[2] = uint32(smp)
	b1, _ := alloc.Bytes(16384)
	b2, _ := alloc.Bytes(16384)
	v1[5] = uint32(uintptr(unsafe.Pointer(&b1[0])))
	v1[6] = uint32(uintptr(unsafe.Pointer(&b2[0])))
	if smp == 0 {
		return -2147221504 // 0x80040000
	}
	smp.SetUserData(0, int32(uintptr(unsafe.Pointer(&v1[0]))))
	return 0
}

//export sub_43ECB0
func sub_43ECB0(a1 unsafe.Pointer) C.int {
	p := *(*unsafe.Pointer)(unsafe.Add(a1, 272))
	if h := *(*uint32)(unsafe.Add(p, 8)); h != 0 {
		ail.Sample(h).Release()
	}
	if p2 := *(*unsafe.Pointer)(unsafe.Add(p, 20)); p2 != nil {
		alloc.Free(p2)
	}
	if p2 := *(*unsafe.Pointer)(unsafe.Add(p, 24)); p2 != nil {
		alloc.Free(p2)
	}
	alloc.Free(p)
	return 0
}

//export sub_43ED00
func sub_43ED00(a1p *C.uint32_t) C.int {
	a1 := unsafe.Slice((*uint32)(unsafe.Pointer(a1p)), 73)
	v1 := unsafe.Slice((*uint32)(unsafe.Pointer(uintptr(a1[68]))), 8)
	smp := ail.Sample(v1[2])
	smp.Init()
	v2 := *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1[72])), 20))
	v1[4] = v2
	if v2 == 0 {
		v1[4] = a1[33] + 60
	}
	v3 := int32(C.sub_43F0E0((*C.uint)(unsafe.Pointer(uintptr(v1[4])))))
	smp.SetType(v3, 0)
	v4 := unsafe.Pointer(uintptr(v1[4]))
	if *(*uint32)(unsafe.Add(v4, 4)) == 2 {
		smp.SetADPCMBlockSize(*(*uint32)(unsafe.Add(v4, 24)))
	}
	sub_43F060((*C.uint)(unsafe.Pointer(&a1[0])))
	v1[7] = 0
	v1[3] = 0
	smp.RegisterEOBCallback(func() {
		v := smp.UserData(0)
		C.sub_43EE00(C.int(v))
	})
	smp.RegisterEOSCallback(func() {
		C.sub_43EDB0(C.HSAMPLE(unsafe.Pointer(smp)))
	})
	C.sub_43EE00(C.int(uintptr(unsafe.Pointer(&v1[0]))))
	return 0
}

//export sub_43D650
func sub_43D650() {
	if s := ail.Stream(C.dword_5d4594_816364); s != 0 {
		s.Close()
		C.dword_5d4594_816364 = 0
	}
	C.dword_5d4594_816092 = 0
}

//export sub_43D680
func sub_43D680() {
	if s := ail.Stream(C.dword_5d4594_816364); s != 0 {
		s.Pause(true)
	}
}

//export sub_43D6A0
func sub_43D6A0() {
	if s := ail.Stream(C.dword_5d4594_816364); s != 0 {
		s.Pause(false)
	}
}

//export sub_44D640
func sub_44D640() {
	if s := ail.Stream(C.dword_5d4594_831088); s != 0 {
		s.Close()
		C.dword_5d4594_831088 = 0
	}
}

//export sub_44D7E0
func sub_44D7E0(a1 C.int) C.int {
	if C.dword_5d4594_831088 == 0 {
		return 0
	}
	C.sub_44D5C0(C.int(C.dword_5d4594_831088), a1)
	ail.Stream(C.dword_5d4594_831088).Start()
	return 1
}

var audioTable = []string{
	"",
	"chap1", "chap2wiz", "chap2con", "chap2war", "chap3", "chap4", "chap5", "chap6", "chap7", "chap8",
	"chap9", "chapa", "chapb", "title", "town1", "town2", "town3", "sub1", "sub2", "sub3",
	"wander1", "wander2", "wander3", "credits", "shell", "action1", "action2", "action3", "wander4",
}

//export nox_xxx_musicStartPlay_43D6C0
func nox_xxx_musicStartPlay_43D6C0(a1p *C.int) C.int {
	if C.dword_5d4594_816376 == 0 {
		return 0
	}
	a1 := unsafe.Slice((*uint32)(unsafe.Pointer(a1p)), 4)

	ind := int(a1[0])
	if ind <= 0 || ind >= len(audioTable) {
		return 0
	}
	aname := audioTable[ind]
	sub_43D650()
	*memmap.PtrUint32(0x587000, 93160) = 0
	path := filepath.Join("music", aname)
	if !strings.Contains(path, ".") {
		path += ".wav"
	}
	s := ail.Driver(C.dword_5d4594_816376).OpenStream(path, 204800)
	if s == 0 {
		if C.dword_587000_122856 != 0 && sub_44D930() {
			return 0
		}
		v5 := GoString(C.sub_413890())
		if v5 == "" {
			return 0
		}
		*memmap.PtrUint32(0x587000, 93160) = 1
		path2 := filepath.Join(v5, path)
		s = ail.Driver(C.dword_5d4594_816376).OpenStream(path2, 204800)
		if s == 0 {
			return 0
		}
	}
	s.SetPosition(int(a1[2]))
	C.sub_486320((*C.uint)(memmap.PtrOff(0x5D4594, 816148)), 0)
	C.sub_486350(memmap.PtrOff(0x5D4594, 816148), 0x4000)
	C.sub_43D3C0(C.int(s), C.int(a1[1]))
	s.Start()
	C.dword_5d4594_816092 = C.uint(ind)
	*memmap.PtrUint32(0x5D4594, 816096) = a1[1]
	*memmap.PtrUint32(0x5D4594, 816100) = a1[2]
	*memmap.PtrUint32(0x5D4594, 816104) = a1[3]
	a1[2] = 0
	C.dword_5d4594_816364 = C.uint(s)
	return 1
}

func sub_44D930() bool {
	if C.dword_587000_122848 == 0 {
		return false
	}
	return C.dword_5d4594_830872 != 0 || C.dword_5d4594_831088 != 0
}

//export sub_44D660
func sub_44D660(a1 *C.char) C.int {
	name := GoString(a1)
	sub_44D640()
	path := filepath.Join("dialog", name)
	C.dword_587000_122856 = 0
	if !strings.Contains(path, ".") {
		path += ".wav"
	}
	C.dword_5d4594_831088 = C.uint(ail.Driver(C.dword_5d4594_831092).OpenStream(path, 51200))
	if C.dword_5d4594_831088 != 0 {
		return 1
	}
	v4 := GoString(C.sub_413890())
	if v4 == "" {
		return C.int(bool2int(C.dword_5d4594_831088 != 0))
	}
	C.dword_587000_122856 = 1
	path2 := filepath.Join(v4, path)
	C.dword_5d4594_831088 = C.uint(ail.Driver(C.dword_5d4594_831092).OpenStream(path2, 51200))
	return C.int(bool2int(C.dword_5d4594_831088 != 0))
}

//export sub_43F060
func sub_43F060(a1p *C.uint32_t) C.int {
	a1 := unsafe.Slice((*uint32)(unsafe.Pointer(a1p)), 69)
	v1 := unsafe.Pointer(uintptr(a1[68]))
	smp := ail.Sample(*(*uint32)(unsafe.Add(v1, 8)))
	smp.SetVolume(int((127 * (a1[45] >> 16)) >> 14))
	smp.SetPan(int((127 * (a1[61] >> 16)) >> 14))
	p2 := *(*unsafe.Pointer)(unsafe.Add(v1, 16))
	v2 := C.sub_486640(unsafe.Pointer(&a1[44]), C.int(*(*uint32)(unsafe.Add(p2, 8))))
	smp.SetPlaybackRate(int(v2))
	return 0
}
