package legacy

import (
	"math"
	"time"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var dword_5d4594_2523756 *server.Waypoint
var nox_xxx_waypointsHead_2523752 *server.Waypoint

func nox_server_makeServerInfoPacket_554040(inBuf *byte, inSz int32, out *byte) uint32 {
	var (
		buf  [72]byte
		v3   *byte = (*byte)(sub_416640())
		game *byte = nox_xxx_cliGamedataGet_416590(0)
	)
	if sub_43AF30() == 0 || sub_4D6F30() != 0 {
		return 0
	}
	var playerLimit int8 = int8(nox_xxx_servGetPlrLimit_409FA0())
	var playerCount int8 = int8(nox_common_playerInfoCount_416F40())
	if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		playerCount--
		playerLimit--
	}
	var srvName *byte = nox_xxx_serverOptionsGetServername_40A4C0()
	buf[0] = 0
	buf[1] = 0
	buf[2] = 13
	buf[3] = byte(playerCount)
	buf[4] = byte(playerLimit)
	buf[5] = *(*byte)(unsafe.Add(unsafe.Pointer(v3), 101)) & 0xF
	buf[6] = byte(int8(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v3), 101))) >> 4))
	*(*uint32)(unsafe.Pointer(&buf[7])) = *((*uint32)(unsafe.Add(unsafe.Pointer(game), 4*11)))
	libc.StrCpy(&buf[10], nox_xxx_mapGetMapName_409B40())
	buf[19] = byte(int8(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v3), 102))) | sub_43BE50_get_video_mode_id()))
	buf[20] = *(*byte)(unsafe.Add(unsafe.Pointer(v3), 100))
	buf[21] = *(*byte)(unsafe.Add(unsafe.Pointer(v3), 100)) & 0x10
	*(*uint32)(unsafe.Pointer(&buf[24])) = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*12)))
	var gameFlags uint32 = nox_common_gameFlags_getVal_40A5B0()
	if nox_xxx_isQuest_4D6F50() != 0 {
		gameFlags = (gameFlags & 0xFFFFFF7F) | 0x1000
		*(*uint16)(unsafe.Pointer(&buf[68])) = uint16(int16(nox_game_getQuestStage_4E3CC0()))
	}
	*(*uint32)(unsafe.Pointer(&buf[28])) = gameFlags
	*(*uint32)(unsafe.Pointer(&buf[32])) = *((*uint32)(unsafe.Add(unsafe.Pointer(game), 4*12)))
	*(*uint16)(unsafe.Pointer(&buf[36])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), 105))
	*(*uint16)(unsafe.Pointer(&buf[38])) = *(*uint16)(unsafe.Add(unsafe.Pointer(v3), 107))
	*(*uint32)(unsafe.Pointer(&buf[40])) = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*11)))
	*(*uint32)(unsafe.Pointer(&buf[44])) = *(*uint32)(unsafe.Add(unsafe.Pointer(inBuf), 8))
	alloc.Memcpy(unsafe.Pointer(&buf[48]), unsafe.Add(unsafe.Pointer(game), 24), 20)
	alloc.Memcpy(unsafe.Pointer(out), unsafe.Pointer(&buf[0]), 72)
	libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(out), 72)), srvName)
	return uint32(libc.StrLen(srvName) + 72 + 1)
}
func sub_554290() uint32 {
	var (
		v0 uint32
		v1 int32
		v3 uint32
	)
	v0 = math.MaxUint32
	v1 = 0
	v2 := nox_common_playerInfoGetFirst_416EA0()
	if v2 == nil {
		return 0
	}
	for {
		if v2.PlayerInd != 31 && sub_554240(int32(v2.PlayerInd)) > 0 {
			v3 = uint32(sub_554240(int32(v2.PlayerInd)))
			if v3 < v0 {
				v0 = v3
			}
			v1++
		}
		v2 = nox_common_playerInfoGetNext_416EE0(v2)
		if v2 == nil {
			break
		}
	}
	if v1 != 0 {
		return v0
	} else {
		return 0
	}
}
func sub_554300() int32 {
	var (
		v0 int32
		v1 int32
	)
	v0 = 0
	v1 = 0
	v2 := nox_common_playerInfoGetFirst_416EA0()
	if v2 == nil {
		return 0
	}
	for {
		if v2.PlayerInd != 31 && sub_554240(int32(v2.PlayerInd)) > 0 {
			v0 += sub_554240(int32(v2.PlayerInd))
			v1++
		}
		v2 = nox_common_playerInfoGetNext_416EE0(v2)
		if v2 == nil {
			break
		}
	}
	if v1 != 0 {
		return v0 / v1
	} else {
		return 0
	}
}
func Sub_56F1C0() {
	v0 := int32(time.Now().Unix())
	sub_56FF00(v0)
	dword_5d4594_2516352 = nil
	dword_5d4594_2516348 = gameFrame()
	dword_5d4594_2516344 = nil
	*memmap.PtrUint16(0x587000, 311204) = 0
	dword_5d4594_2516356 = 657757279
	dword_5d4594_2516348 ^= nox_xxx_protect_56F240()
	dword_5d4594_2516328 = ^dword_5d4594_2516348
	*memmap.PtrUint32(0x5D4594, 2516340) = uint32(nox_xxx_protectionCreateInt_56F400(0))
	sub_56F250()
	*memmap.PtrUint32(0x5D4594, 2516332) = uint32(nox_xxx_protectionCreateInt_56F400(1))
}
func nox_xxx_protect_56F240() uint32 {
	return sub_56FF80(1, -1)
}
func sub_56F250() int32 {
	var (
		v0     int32
		result int32
	)
	v0 = 7
	for {
		result = nox_xxx_protectionCreateStructForInt_56F280(dword_5d4594_2516356, 0)
		v0--
		dword_5d4594_2516356++
		if v0 == 0 {
			break
		}
	}
	return result
}

var dword_5d4594_2516344 *protectStruct
var dword_5d4594_2516352 *protectStruct
var dword_5d4594_2516348 uint32
var dword_5d4594_2516328 uint32

type protectStruct struct {
	Field0  uint32
	Field4  uint32
	Field8  *protectStruct
	Field12 *protectStruct
}

func nox_xxx_protectionCreateStructForInt_56F280(a1 uint32, val int32) int32 {
	a2 := uint32(val)
	p, _ := alloc.New(protectStruct{})
	if p == nil {
		return 0
	}
	p.Field8 = nil
	p.Field12 = nil
	v3 := a1 ^ dword_5d4594_2516348
	p.Field0 = a1 ^ dword_5d4594_2516348
	dword_5d4594_2516328 ^= v3
	p.Field4 = a2
	v4 := a2 ^ dword_5d4594_2516348
	p.Field4 = a2 ^ dword_5d4594_2516348
	dword_5d4594_2516328 ^= v4
	return sub_56F2F0(p)
}
func sub_56F2F0(p *protectStruct) int32 {
	var (
		v2 int16
		i  int16
	)
	v1 := dword_5d4594_2516344
	v2 = 0
	if int32(*memmap.PtrUint16(0x587000, 311204)) != 0 {
		for i = int16(nox_common_randomInt_415FA0(0, int32(*memmap.PtrUint16(0x587000, 311204))-1)); v1 != nil; v2++ {
			if int32(v2) == int32(i) {
				break
			}
			v1 = v1.Field8
		}
		p.Field12 = v1.Field12
		p.Field8 = v1
		v1.Field12 = p
		v5 := p.Field12
		if v5 != nil {
			v5.Field8 = p
			*memmap.PtrUint16(0x587000, 311204)++
		} else {
			*memmap.PtrUint16(0x587000, 311204)++
			dword_5d4594_2516344 = p
		}
		return 1
	} else {
		*memmap.PtrUint16(0x587000, 311204)++
		dword_5d4594_2516352 = p
		dword_5d4594_2516344 = p
		return 1
	}
}
func Sub_56F3B0() {
	result := dword_5d4594_2516344
	if dword_5d4594_2516344 != nil {
		for {
			v1 := result.Field8
			alloc.Free(result)
			result = v1
			if v1 == nil {
				break
			}
		}
	}
	dword_5d4594_2516328 = 0
	*memmap.PtrUint16(0x587000, 311204) = 0
	dword_5d4594_2516348 = 0
	dword_5d4594_2516352 = nil
	dword_5d4594_2516344 = nil
}
func nox_xxx_protectionCreateInt_56F400(a1 int32) int32 {
	if nox_xxx_protectionCreateStructForInt_56F280(dword_5d4594_2516356, a1) != 0 {
		return int32(func() uint32 {
			p := &dword_5d4594_2516356
			x := *p
			*p++
			return x
		}())
	}
	return 0
}
func nox_xxx_protectionCreateStructForFloat_56F480(a1 uint32, val float32) int32 {
	a2 := math.Float32bits(val)
	p, _ := alloc.New(protectStruct{})
	if p == nil {
		return 0
	}
	p.Field12 = nil
	p.Field8 = nil
	v3 := a1 ^ dword_5d4594_2516348
	p.Field0 = a1 ^ dword_5d4594_2516348
	dword_5d4594_2516328 ^= v3
	p.Field4 = a2
	v4 := a2 ^ dword_5d4594_2516348
	p.Field4 = a2 ^ dword_5d4594_2516348
	dword_5d4594_2516328 ^= v4
	return sub_56F2F0(p)
}
func sub_56F4F0(a1 *uint32) {
	if sub_56F510(int32(*a1)) != 0 {
		*a1 = 0
	}
}
func sub_56F510(a1 int32) int32 {
	p := sub_56F590(a1)
	if p == nil {
		return 0
	}
	v2 := p.Field12
	if v2 != nil {
		v2.Field8 = p.Field8
	} else {
		dword_5d4594_2516344 = p.Field8
	}
	v3 := p.Field8
	if v3 != nil {
		v3.Field12 = p.Field12
	} else {
		dword_5d4594_2516352 = p.Field12
	}
	v4 := p.Field0 ^ dword_5d4594_2516328
	dword_5d4594_2516328 = v4
	v5 := p.Field4 ^ v4
	*memmap.PtrUint16(0x587000, 311204)--
	dword_5d4594_2516328 = v5
	alloc.Free(p)
	return 1
}
func sub_56F590(a1 int32) *protectStruct {
	p := dword_5d4594_2516344
	if p == nil {
		return nil
	}
	for p.Field0 != (uint32(a1) ^ dword_5d4594_2516348) {
		p = p.Field8
		if p == nil {
			return nil
		}
	}
	return p
}
func nox_xxx_protectData_56F5C0() {
	var (
		v4  uint32
		i   int32
		v6  int32
		v7  int32
		v10 uint32
		v11 uint32
	)
	v0 := gameFrame()
	v1 := dword_5d4594_2516348
	v2 := nox_xxx_protect_56F240() ^ v0
	v3 := v2 ^ v1
	dword_5d4594_2516328 = ^v2
	v4 = uint32(*memmap.PtrUint16(0x587000, 311204))
	for i = 0; i < (int32(*memmap.PtrUint16(0x587000, 311204)) >> 2); v4 = uint32(*memmap.PtrUint16(0x587000, 311204)) {
		v6 = nox_common_randomInt_415FA0(0, int32(v4>>1))
		v7 = nox_common_randomInt_415FA0((int32(*memmap.PtrUint16(0x587000, 311204))>>1)+1, int32(*memmap.PtrUint16(0x587000, 311204))-1)
		if v6 != v7 {
			v14 := sub_56F6F0(v7)
			v8 := sub_56F6F0(v6)
			sub_56F720(v8, v14)
		}
		i++
	}
	v9 := dword_5d4594_2516344
	dword_5d4594_2516348 = 0
	if dword_5d4594_2516344 != nil {
		for {
			v10 = v3 ^ v9.Field0
			v11 = v3 ^ v9.Field4
			v9.Field0 = v10
			v9.Field4 = v11
			dword_5d4594_2516328 ^= v10
			dword_5d4594_2516328 ^= v9.Field4
			v9 = v9.Field8
			if v9 == nil {
				break
			}
		}
	}
	*memmap.PtrUint32(0x5D4594, 2516364)++
	dword_5d4594_2516348 ^= v2
}
func sub_56F6F0(a1 int32) *protectStruct {
	result := dword_5d4594_2516344
	if result == nil {
		return nil
	}
	var v2 int32
	for v2 != a1 {
		result = result.Field8
		v2++
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_56F720(a1, a2 *protectStruct) {
	if a1 == nil || a2 == nil {
		return
	}
	v2 := a1.Field0
	v3 := a1.Field4
	a1.Field0 = a2.Field0
	a1.Field4 = a2.Field4
	a2.Field0 = v2
	a2.Field4 = v3
	*memmap.PtrUint32(0x5D4594, 2516360)++
}
func sub_56F780(a1 int32, a2 int32) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := int32(uint32(a2) ^ dword_5d4594_2516348)
	p.Field4 = uint32(a2) ^ dword_5d4594_2516348
	dword_5d4594_2516328 ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}
func nox_xxx_playerResetProtectionCRC_56F7D0(a1 int32, a2 uint32) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := a2 ^ dword_5d4594_2516348
	p.Field4 = a2 ^ dword_5d4594_2516348
	dword_5d4594_2516328 ^= v3
	nox_xxx_protectData_56F5C0()
}
func sub_56F820(a1 int32, a2 uint8) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := int32(dword_5d4594_2516348 ^ uint32(a2))
	p.Field4 = uint32(v3)
	dword_5d4594_2516328 ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}
func nox_xxx_protectPlayerHPMana_56F870(a1 int32, a2 uint16) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := int32(dword_5d4594_2516348 ^ uint32(a2))
	p.Field4 = uint32(v3)
	dword_5d4594_2516328 ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}
func sub_56F8C0(a1 int32, a2 float32) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	v3 := p
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v4 := int32(uint32(uint64(dword_5d4594_2516348) ^ uint64(int64(a2))))
	v3.Field4 = uint32(v4)
	dword_5d4594_2516328 ^= uint32(v4)
	nox_xxx_protectData_56F5C0()
}
func sub_56F920(a1 int32, a2 int32) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := int32(dword_5d4594_2516348 ^ (uint32(a2) + (dword_5d4594_2516348 ^ p.Field4)))
	p.Field4 = uint32(v3)
	dword_5d4594_2516328 ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}
func nox_xxx_protectMana_56F9E0(a1 int32, a2 int16) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v3 := int32(dword_5d4594_2516348 ^ (uint32(a2) + (dword_5d4594_2516348 ^ p.Field4)))
	p.Field4 = uint32(v3)
	dword_5d4594_2516328 ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}
func sub_56FA40(a1 int32, a2 float32) {
	if uint32(a1) < 657757279 {
		return
	}
	p := sub_56F590(a1)
	v3 := p
	if p == nil {
		return
	}
	dword_5d4594_2516328 ^= p.Field4
	v4 := int32(uint32(uint64(dword_5d4594_2516348) ^ uint64(int64(float64(dword_5d4594_2516348^p.Field4)+float64(a2)))))
	v3.Field4 = uint32(v4)
	dword_5d4594_2516328 ^= uint32(v4)
	nox_xxx_protectData_56F5C0()
}
func nox_xxx_protectionStringCRC_56FAC0(a1 *byte, a2 uint32) int32 {
	var (
		crc int32
		i   uint32
		v5  int32
	)
	v2 := a1
	for i = a2 >> 2; i != 0; i-- {
		v5 = *(*int32)(unsafe.Pointer(v2))
		v2 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 4*1))
		crc ^= v5
	}
	return crc
}
func nox_xxx_protectionStringCRCLen_56FAE0(a1 *byte, a2 uint32) int32 {
	var crc int32
	if a1 != nil {
		crc = nox_xxx_protectionStringCRC_56FAC0(a1, a2)
	}
	return crc
}
func sub_56FB00(a1 *byte, a2 uint32, a3 int32) int32 {
	if uint32(a3) < 657757279 {
		return 0
	}
	p := sub_56F590(a3)
	if p != nil && (dword_5d4594_2516348^uint32(nox_xxx_protectionStringCRCLen_56FAE0(a1, a2))) == p.Field4 {
		return 1
	}
	return 0
}
func sub_56FB60(item *server.Object) int32 {
	var (
		result int32
		v2     int32
		v3     int32
		v4     int32
		v6     int32
	)
	result = 0
	if item == nil {
		return result
	}
	v2 = sub_4E4C00(item)
	v3 = int32(uint16(nox_xxx_unitGetHP_4EE780(item))) ^ v2
	v4 = sub_4E4C10(item) ^ v3
	v5 := (*byte)(unsafe.Pointer(uintptr(nox_object_getInitData_4E4C30(item))))
	v6 = sub_4E4C50(item)
	if v5 != nil && v6 > 0 {
		v4 ^= nox_xxx_protectionStringCRC_56FAC0(v5, uint32(v6))
	}
	v7 := sub_4E4C80(item)
	if v7 != nil {
		if libc.StrLen(v7) != 0 {
			v4 ^= nox_xxx_protectionStringCRC_56FAC0(v7, uint32(libc.StrLen(v7)))
		}
	}
	result = v4
	return result
}
func nox_xxx_protect_56FBF0(a1 int32, item *server.Object) {
	if uint32(a1) < 657757279 {
		return
	}
	v3 := sub_56F590(a1)
	v4 := v3
	if v3 == nil {
		return
	}
	dword_5d4594_2516328 ^= v3.Field4
	v5 := int32(uint32(sub_56FB60(item)) ^ v3.Field4)
	v4.Field4 = uint32(v5)
	dword_5d4594_2516328 ^= uint32(v5)
}
func nox_xxx_protect_56FC50(a1 int32, obj *server.Object) {
	if uint32(a1) < 657757279 {
		return
	}
	v3 := sub_56F590(a1)
	v4 := v3
	if v3 == nil {
		return
	}
	dword_5d4594_2516328 ^= v3.Field4
	v5 := int32(uint32(sub_56FB60(obj)) ^ v3.Field4)
	v4.Field4 = uint32(v5)
	dword_5d4594_2516328 ^= uint32(v5)
}
func sub_56FCB0(a1 int32, a2 int32) int32 {
	var result int32
	result = 0
	if a2 != 0 {
		result = 1 << (a1 % 32)
	}
	return result
}
func nox_xxx_playerAwardSpellProtectionCRC_56FCE0(a1 int32, a2 int32, a3 int32) {
	if uint32(a1) < 657757279 {
		return
	}
	v4 := sub_56F590(a1)
	v5 := v4
	if v4 == nil {
		return
	}
	dword_5d4594_2516328 ^= v4.Field4
	result := int32(dword_5d4594_2516348 ^ (dword_5d4594_2516348 ^ v4.Field4 | uint32(sub_56FCB0(a2, a3))))
	v5.Field4 = uint32(result)
	dword_5d4594_2516328 ^= uint32(result)
}
func nox_xxx_playerApplyProtectionCRC_56FD50(a1 int32, a2p unsafe.Pointer, a3 int32) int32 {
	var (
		a2 = a2p
		v3 int32
		v5 int32
		v6 *int32
	)
	v3 = 0
	if uint32(a1) < 657757279 {
		return 0
	}
	v4 := sub_56F590(a1)
	v8 := v4
	if v4 == nil {
		return 0
	}
	v5 = 1
	if a3 > 1 {
		v6 = (*int32)(unsafe.Add(a2, 4))
		for {
			v3 |= sub_56FCB0(func() int32 {
				p := &v5
				x := *p
				*p++
				return x
			}(), *v6)
			v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v5 >= a3 {
				break
			}
		}
		v4 = v8
	}
	if (uint32(v3) ^ dword_5d4594_2516348) == v4.Field4 {
		return 1
	}
	return 0
}
func nox_xxx_unkDoubleSmth_56FE30() float64 {
	var v0 float64
	*memmap.PtrUint64(0x5D4594, 2516412) = *memmap.PtrUint64(0x5D4594, 2516404)
	*memmap.PtrUint64(0x5D4594, 2516404) = *memmap.PtrUint64(0x5D4594, 2516396)
	*memmap.PtrUint32(0x5D4594, 2516396) = *memmap.PtrUint32(0x5D4594, 2516388)
	*memmap.PtrUint32(0x5D4594, 2516400) = *memmap.PtrUint32(0x5D4594, 2516392)
	v0 = *mem_getDoublePtr(0x5D4594, 2516388)**mem_getDoublePtr(0x581450, 11376) + *mem_getDoublePtr(0x5D4594, 2516404)**mem_getDoublePtr(0x581450, 11368) + *mem_getDoublePtr(0x5D4594, 2516412)**mem_getDoublePtr(0x581450, 11360) + *mem_getDoublePtr(0x5D4594, 2516412)**mem_getDoublePtr(0x581450, 11352) + *mem_getDoublePtr(0x5D4594, 2516420)
	math.Floor(v0)
	*mem_getDoublePtr(0x5D4594, 2516388) = v0 - v0
	*mem_getDoublePtr(0x5D4594, 2516420) = v0 * *mem_getDoublePtr(0x581450, 11344)
	return *mem_getDoublePtr(0x5D4594, 2516388)
}
func sub_56FF00(a1 int32) {
	var (
		v1 int32
		v2 *uint8
		v3 uint32
		v4 int32
	)
	v1 = a1
	if a1 == 0 {
		v1 = -1
	}
	v2 = (*uint8)(memmap.PtrOff(0x5D4594, 2516388))
	for {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
		v3 = ((uint32(v1<<13) ^ uint32(v1)) >> 17) ^ uint32(v1<<13) ^ uint32(v1)
		v1 = int32((v3 * 32) ^ v3)
		*((*float64)(unsafe.Add(unsafe.Pointer(v2), -int(unsafe.Sizeof(float64(0))*1)))) = float64(uint32(v1)) * *mem_getDoublePtr(0x581450, 11344)
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2516428))) {
			break
		}
	}
	v4 = 19
	for {
		nox_xxx_unkDoubleSmth_56FE30()
		v4--
		if v4 == 0 {
			break
		}
	}
	dword_5d4594_2516380 = 0
	*memmap.PtrUint32(0x5D4594, 2516376) = 99
	dword_5d4594_2516372 = 100
}
func sub_56FF80(a1 int32, a2 int32) uint32 {
	*memmap.PtrUint32(0x5D4594, 2516376) = uint32(a2)
	dword_5d4594_2516380 = uint32(a1)
	dword_5d4594_2516372 = uint32(a2 - a1 + 1)
	v2 := int64(nox_xxx_unkDoubleSmth_56FE30() * float64(dword_5d4594_2516372))
	if uint32(int32(v2)) < dword_5d4594_2516372 {
		return uint32(int32(int64(dword_5d4594_2516380) + v2))
	} else {
		return dword_5d4594_2516372 + dword_5d4594_2516380
	}
}
func nox_xxx_netGetUnitCodeCli_578B00(a1 *client.Drawable) uint32 {
	if a1 == nil {
		return 0
	}
	code := a1.Field_32
	if code >= 0x8000 {
		return 0
	}
	if a1.Flags28()&0x20400000 != 0 {
		*(*uint8)(unsafe.Add(unsafe.Pointer(&code), 1)) |= 0x80
	}
	return code
}
func nox_xxx_netClearHighBit_578B30(a1 int16) int32 {
	return int32(a1) & math.MaxInt16
}
func nox_xxx_packetDynamicUnitCode_578B40(a1 int32) int32 {
	var (
		result int32
	)
	result = a1
	if (a1 & 0x8000) != 0x8000 {
		return result
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(&result), 1)) &= math.MaxInt8
	v2 := nox_xxx_netGetUnitByExtent_4ED020(result)
	if v2 != nil {
		result = int32(v2.NetCode)
	} else {
		result = 0
	}
	return result
}
func nox_xxx_netTestHighBit_578B70(a1 uint32) uint32 {
	return (a1 >> 15) & 1
}
func nox_xxx_waypointGetList_579860() *server.Waypoint {
	return nox_xxx_waypointsHead_2523752
}
func nox_xxx_waypointNext_579870(a1 *server.Waypoint) *server.Waypoint {
	if a1 != nil {
		return a1.WpNext
	} else {
		return nil
	}
}
func sub_579890() *server.Waypoint {
	return dword_5d4594_2523756
}
func sub_5798A0(a1 *server.Waypoint) *server.Waypoint {
	if a1 != nil {
		return a1.WpNext
	} else {
		return nil
	}
}
func nox_xxx_waypoint_5798C0() uint32 {
	var (
		result uint32
	)
	result = 1
	if nox_xxx_waypointsHead_2523752 == nil {
		return result
	}
	v0 := nox_xxx_waypointsHead_2523752
	for {
		if result <= v0.Index {
			result = v0.Index + 1
		}
		v0 = v0.WpNext
		if v0 == nil {
			break
		}
	}
	return result
}
func nox_xxx_waypointNew_5798F0(a1 float32, a2 float32) *server.Waypoint {
	var (
		v3 uint32
		v4 int32
	)
	wp, _ := alloc.New(server.Waypoint{})
	v3 = nox_xxx_waypoint_5798C0()
	v4 = int32(wp.Flags)
	wp.Index = v3
	wp.PosVec.X = a1
	wp.PosVec.Y = a2
	wp.Flags = uint32(v4 | 1)
	wp.WpNext = nox_xxx_waypointsHead_2523752
	if nox_xxx_waypointsHead_2523752 != nil {
		nox_xxx_waypointsHead_2523752.WpPrev = wp
	}
	nox_xxx_waypointsHead_2523752 = wp
	if noxflags.HasGame(1) {
		nox_xxx_waypointMapRegister_5179B0(wp)
	}
	return wp
}
func nox_xxx_waypointNewNotMap_579970(a1 int32, a2 float32, a3 float32) *server.Waypoint {
	wp, _ := alloc.New(server.Waypoint{})
	wp.Index = uint32(a1)
	wp.PosVec.X = a2
	wp.PosVec.Y = a3
	wp.Flags |= 0x1
	wp.WpNext = dword_5d4594_2523756
	dword_5d4594_2523756 = wp
	return wp
}
func nox_xxx_waypoint_5799C0() {
	v0 := dword_5d4594_2523756
	if dword_5d4594_2523756 != nil {
		for {
			v1 := v0.WpNext
			v0.WpNext = nox_xxx_waypointsHead_2523752
			if nox_xxx_waypointsHead_2523752 != nil {
				nox_xxx_waypointsHead_2523752.WpPrev = v0
			}
			nox_xxx_waypointsHead_2523752 = v0
			if noxflags.HasGame(1) {
				nox_xxx_waypointMapRegister_5179B0(v0)
			}
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
	dword_5d4594_2523756 = nil
	sub_579A30()
}
func sub_579A30() {
	var (
		v2 int32
		v3 *byte
		v4 int8
		v6 int32
		v7 *uint8
	)
	result := nox_xxx_waypointGetList_579860()
	for i := result; result != nil; i = result {
		i.Flags2 = 0
		v2 = 0
		if i.PointsCnt != 0 {
			v3 = (*byte)(unsafe.Add(unsafe.Pointer(i), 96))
			for {
				v4 = int8(*v3)
				v3 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 8))
				i.Flags2 |= byte(v4)
				v2++
				if v2 >= int32(i.PointsCnt) {
					break
				}
			}
		}
		for j := nox_xxx_waypointGetList_579860(); j != nil; j = nox_xxx_waypointNext_579870(j) {
			v6 = 0
			if j.PointsCnt != 0 {
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(j), 96))
				for {
					if *((**server.Waypoint)(unsafe.Add(unsafe.Pointer(v7), -int(unsafe.Sizeof((*byte)(nil))*1)))) == i {
						i.Flags2 |= *v7
					}
					v6++
					v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 8))
					if v6 >= int32(j.PointsCnt) {
						break
					}
				}
			}
		}
		result = nox_xxx_waypointNext_579870(i)
	}
}
func sub_579AD0(a1 float32, a2 float32) *server.Waypoint {
	var (
		v4 float64
		v5 float64
		v6 float64
		i  float32
	)
	v2 := nox_xxx_waypointsHead_2523752
	var v3 *server.Waypoint
	for i = 100.0; v2 != nil; v2 = v2.WpNext {
		v4 = float64(v2.PosVec.X - a1)
		v5 = float64(v2.PosVec.Y - a2)
		v6 = v5*v5 + v4*v4
		if v6 < float64(i) {
			i = float32(v6)
			v3 = v2
		}
	}
	return v3
}
func sub_579C80(a1 int32) *server.Waypoint {
	result := dword_5d4594_2523756
	if dword_5d4594_2523756 == nil {
		return nil
	}
	for result.Index != uint32(a1) {
		result = result.WpNext
		if result == nil {
			return nil
		}
	}
	return result
}
func sub_579CA0() int32 {
	v0 := dword_5d4594_2523756
	if dword_5d4594_2523756 != nil {
		for {
			v0.Field1 = v0.Index
			v0 = v0.WpNext
			if v0 == nil {
				break
			}
		}
		v0 = dword_5d4594_2523756
	}
	v1 := v0
	if v0 == nil {
		return 1
	}
	for {
		var v2 int32
		if int32(v1.PointsCnt) != 0 {
			v3 := &v1.Points[0]
			v4 := (*int32)(unsafe.Add(unsafe.Pointer(v1), 4*87))
			for {
				v5 := sub_579C60(uint32(*v4))
				v3.Waypoint = v5
				if v5 == nil {
					return 0
				}
				v2++
				v4 = (*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
				v3 = (*server.WaypointSub)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(server.WaypointSub{})))
				if v2 >= int32(v1.PointsCnt) {
					goto LABEL_9
				}
			}
		}
	LABEL_9:
		v1 = v1.WpNext
		if v1 == nil {
			return 1
		}
	}
}
func sub_579D20() int32 {
	var (
		v0 uint32
		v2 uint32
		v4 int32
		v5 *int32
		v6 *int32
		v7 int32
		v9 int8
	)
	v0 = nox_xxx_waypoint_5798C0()
	v1 := dword_5d4594_2523756
	if dword_5d4594_2523756 != nil {
		for {
			v2 = v1.Index
			v1.Index = v0
			v1.Field1 = v2
			v1 = v1.WpNext
			v0++
			if v1 == nil {
				break
			}
		}
		v1 = dword_5d4594_2523756
	}
	v3 := v1
	if v1 == nil {
		return 1
	}
	for {
		v4 = 0
		v9 = 0
		if int32(v3.PointsCnt) != 0 {
			v5 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*23))
			v6 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*87))
			for {
				v7 = int32(uintptr(unsafe.Pointer(sub_579C60(uint32(*v6)))))
				*v5 = v7
				if v7 != 0 {
					v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*2))
					v9++
				}
				v4++
				v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
				if v4 >= int32(v3.PointsCnt) {
					break
				}
			}
		}
		v3.PointsCnt = uint8(v9)
		v3 = v3.WpNext
		if v3 == nil {
			break
		}
	}
	return 1
}
func nox_xxx_waypointDeleteAll_579DD0() {
	if nox_xxx_waypointsHead_2523752 != nil {
		v0 := nox_xxx_waypointsHead_2523752
		for {
			v1 := v0.WpNext
			if noxflags.HasGame(1) {
				sub_517A70(v0)
			}
			alloc.Free(v0)
			v0 = v1
			if v1 == nil {
				break
			}
		}
	}
	nox_xxx_waypointsHead_2523752 = nil
	dword_5d4594_2523756 = nil
	dword_5d4594_2523760 = 0
}
func sub_579E70() *server.Waypoint {
	wp, _ := alloc.New(server.Waypoint{})
	if wp != nil {
		wp.Flags |= 0x1000000
	}
	return wp
}
func sub_579E90(a1 *server.Waypoint) {
	a1.Flags |= 0x1000000
	a1.WpNext = dword_5d4594_2523756
	if dword_5d4594_2523756 != nil {
		dword_5d4594_2523756.WpPrev = a1
	}
	dword_5d4594_2523756 = a1
	if noxflags.HasGame(1) {
		nox_xxx_waypointMapRegister_5179B0(a1)
	}
}
func sub_579EE0(a1 *server.Waypoint, a2 uint8) int32 {
	return bool2int32((int32(a2) & int32(a1.Flags2)) != 0)
}
func nox_xxx_waypoint_579F00(a1 *uint32, a2 unsafe.Pointer) int32 {
	var (
		v2  unsafe.Pointer
		v5  int32
		v6  *server.Waypoint
		v7  *float32
		v8  float32
		v9  float32
		v10 float32
		v12 float4
	)
	v2 = nil
	if noxflags.HasGame(32) {
		if a2 != nil {
			v3 := nox_server_getFirstObject_4DA790()
			if v3 != nil {
				for (v3.ObjClass&0x10000000) == 0 || nox_xxx_servCompareTeams_419150((*server.ObjectTeam)(unsafe.Add(a2, 48)), (*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(v3), 48))) != 0 {
					v3 = nox_server_getNextObject_4DA7A0(v3)
					if v3 == nil {
						goto LABEL_9
					}
				}
				v2 = unsafe.Pointer(v3)
			}
		}
	}
LABEL_9:
	dword_5d4594_2523760 = 0
	for i := nox_xxx_waypointGetList_579860(); i != nil; i = nox_xxx_waypointNext_579870(i) {
		if sub_579EE0(i, 0x80) != 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(i), 480)))&1 != 0 {
			dword_5d4594_2523760++
		}
	}
	if dword_5d4594_2523760 == 0 {
		return 0
	}
	v5 = nox_common_randomInt_415FA0(0, int32(dword_5d4594_2523760-1))
	v6 = nox_xxx_waypointGetList_579860()
	if v6 == nil {
		return 0
	}
	for {
		if sub_579EE0(v6, 0x80) == 0 {
			goto LABEL_24
		}
		if (int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v6), 480)))) & 1) == 0 {
			goto LABEL_24
		}
		if noxflags.HasGame(32) {
			if v2 != nil {
				if a2 != nil {
					v7 = *(**float32)(unsafe.Add(v2, 748))
					v12.field_0 = *v7
					v8 = v6.PosVec.Y
					v9 = *(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*1))
					v10 = v6.PosVec.X
					v12.field_4 = v9
					v12.field_8 = v10
					v12.field_C = v8
					if nox_xxx_mapTraceRay_535250(&v12, nil, nil, 9) == 1 {
						goto LABEL_24
					}
				}
			}
		}
		if v5 == 0 {
			break
		}
		v5--
	LABEL_24:
		v6 = nox_xxx_waypointNext_579870(v6)
		if v6 == nil {
			return 0
		}
	}
	*a1 = uint32(v6.PosVec.X)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = uint32(v6.PosVec.Y)
	return 1
}
func nox_xxx_playerCanTalkMB_57A160(a1 int32) int32 {
	var result int32
	if a1 != 0 && noxflags.HasGame(2) {
		result = int32((*(*uint32)(unsafe.Add(a1, 3680)) >> 3) & 1)
	} else {
		result = 0
	}
	return result
}
func sub_57A1B0(a1 int16) *byte {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 312212))
	for uint32(int32(a1)&0x17F0) != *(*uint32)(unsafe.Pointer(v2)) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 8))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 312268))) {
			return nil
		}
	}
	return *(**byte)(memmap.PtrOff(0x587000, uintptr(v1*8)+312208))
}
func sub_57A1E0(a1 *int32, a2 *byte, a3 *int32, a4 int8, a5 int16) int8 {
	var (
		v5 *int32
		v6 int32
		v7 uint8
	)
	var v8 *byte
	var v9 int32
	var v10 int32
	var v12 uint8
	var result int8
	var v14 [256]byte
	var v15 [256]byte
	v5 = a3
	v6 = int32(a5) & 0x17F0
	if a3 != nil {
		sub_57ADF0(a3)
	}
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) = -1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) = -1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) = -1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) = -1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) = -1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*11)) = -1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)) = -1
	if int32(a4)&3 != 0 {
		v15[0] = 0
		libc.StrCpy(&v14[0], internCStr("maps\\"))
		libc.StrNCat(&v14[0], (*byte)(unsafe.Pointer(a1)), 8)
		libc.StrCat(&v14[0], internCStr("\\"))
		if int32(a4)&2 != 0 {
			libc.StrCpy(&v15[0], &v14[0])
			if a2 != nil {
				libc.StrCat(&v15[0], a2)
			} else {
				libc.StrCat(&v15[0], internCStr("user.rul"))
			}
			v10 = sub_57A3F0(&v15[0], int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(a3))), v6)
			v5 = a3
		} else {
			v10 = 0
		}
		if int32(a4)&1 != 0 && v10 == 0 {
			libc.StrNCat(&v14[0], (*byte)(unsafe.Pointer(a1)), 8)
			libc.StrNCat(&v14[0], internCStr(".rul"), math.MaxUint8)
			sub_57A3F0(&v14[0], int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(v5))), v6)
		}
	}
	if dword_5d4594_2650652 != 0 && int32(a4)&4 != 0 {
		sub_57A3F0(internCStr("internet.rul"), int32(uintptr(unsafe.Pointer(a1))), int32(uintptr(unsafe.Pointer(v5))), v6)
	}
	result = int8(a5)
	if int32(a5)&0x40 != 0 {
		result = int8(sub_453FA0(int32(uintptr(unsafe.Add(unsafe.Pointer(a1), 4*6))), 132, 0))
	}
	return result
}
func sub_57A3F0(a1 *byte, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4 *FILE
		v5 *FILE
		v6 *byte
		v8 [256]byte
		v9 [256]wchar2_t
	)
	dword_5d4594_2523764 = 6128
	v4 = nox_fs_open_text(a1)
	v5 = v4
	if v4 == nil {
		return 0
	}
	if !nox_fs_feof(v4) {
		for {
			*(*[256]byte)(unsafe.Pointer(&v8[0])) = [256]byte{}
			nox_fs_fgets(v5, &v8[0], 256)
			v6 = libc.StrChr(&v8[0], 10)
			if v6 != nil {
				*v6 = 0
			}
			if v8[0] != 0 {
				nox_swprintf(&v9[0], internWStr("%S"), &v8[0])
				sub_57A4D0(&v9[0], a2, a3, a4)
			}
			if nox_fs_feof(v5) {
				break
			}
		}
	}
	nox_fs_close(v5)
	return 1
}
func sub_57A4D0(a1 *wchar2_t, a2 int32, a3 int32, a4 int32) {
	var (
		v4     uint8
		v5     int32
		result *wchar2_t
		v7     *wchar2_t
		v8     int32
		v9     *wchar2_t
		v10    *wchar2_t
		v11    uint8
		v12    [32]int32
		v13    [256]wchar2_t
	)
	v4 = 0
	v5 = 0
	v11 = 0
	sub_416580()
	result = nox_wcscpy(&v13[0], a1)
	if true {
		if v13[0] == 34 {
			result = nox_wcstok(&v13[1], internWStr("\"\n\r"))
			v7 = result
			v5 = 1
		} else {
			result = nox_wcstok(&v13[0], internWStr(" \n\t\r"))
			v7 = result
		}
		if v7 != nil {
			for {
				v8 = int32(v11)
				v11 = func() uint8 {
					p := &v4
					*p++
					return *p
				}()
				v12[v8] = int32(uintptr(unsafe.Pointer(v7)))
				v9 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(wchar2_t(0))*uintptr(nox_wcslen(v7)+1)))
				if v5 != 0 {
					v9 = (*wchar2_t)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(wchar2_t(0))*1))
				}
				if *v9 == 34 {
					result = nox_wcstok((*wchar2_t)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(wchar2_t(0))*1)), internWStr("\"\n\r"))
					v7 = result
					v5 = 1
				} else {
					result = nox_wcstok(nil, internWStr(" \n\t\r"))
					v7 = result
					v5 = 0
				}
				if v7 == nil {
					break
				}
			}
			if int32(v4) != 0 {
				result = (*wchar2_t)(unsafe.Pointer(uintptr(sub_57A620(v4, (**wchar2_t)(unsafe.Pointer(&v12[0])), a2, a4))))
				if result == nil {
					if a3 != 0 {
						v10 = (*wchar2_t)(alloc.Calloc1(1, 0x20C))
						nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v10), unsafe.Sizeof(wchar2_t(0))*6)), a1)
						nox_common_list_append_4258E0((*nox_list_item_t)(a3), (*nox_list_item_t)(unsafe.Pointer(v10)))
					}
				}
			}
		}
	}
}
func sub_57A620(a1 uint8, a2 **wchar2_t, a3 int32, a4 int32) int32 {
	var (
		v4  **wchar2_t
		v5  uint8
		v6  int32
		v9  int32
		v10 int32
		v11 uint8
		v12 int32
		v14 int32
		v15 int32
		v16 [100]byte
		v17 uint8
		v18 uint8
	)
	v4 = a2
	nox_sprintf(&v16[0], internCStr("%S"), *a2)
	v5 = 0
	v17 = 0
	for {
		if libc.StrCmp(*(**byte)(memmap.PtrOff(0x587000, uintptr(int32(v17)*8)+312208)), &v16[0]) == 0 {
			dword_5d4594_2523764 = *memmap.PtrUint32(0x587000, uintptr(int32(v17)*8)+312212)
			return bool2int32(uint32(a4) == dword_5d4594_2523764)
		}
		v17 = func() uint8 {
			p := &v5
			*p++
			return *p
		}()
		if int32(v5) >= 7 {
			break
		}
	}
	if (dword_5d4594_2523764&uint32(a4)) == 0 || _nox_wcsicmp(*v4, internWStr("set")) != 0 || int32(a1) <= 1 {
		return 0
	}
	if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*1)), internWStr("spell")) != 0 {
		if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*1)), internWStr("weapon")) != 0 {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*1)), internWStr("armor")) != 0 {
				return 0
			}
			if int32(a1) != 4 {
				return 0
			}
			if !noxflags.HasGame(1) {
				return 0
			}
			nox_sprintf(&v16[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			var v13 int32 = sub_415EC0(&v16[0])
			if v13 < 0 {
				return 0
			}
			v14 = sub_415D10(v13)
			if v14 == 0 {
				return 0
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) != 0 {
				v15 = int32(uint32(v14) | *(*uint32)(unsafe.Add(a3, 48)))
			} else {
				v15 = int32(uint32(^v14) & *(*uint32)(unsafe.Add(a3, 48)))
			}
			*(*uint32)(unsafe.Add(a3, 48)) = uint32(v15)
		} else {
			if int32(a1) != 4 {
				return 0
			}
			if !noxflags.HasGame(1) {
				return 0
			}
			nox_sprintf(&v16[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			var v8 int32 = sub_415A30(&v16[0])
			if v8 < 0 {
				return 0
			}
			v9 = nox_xxx_ammoCheck_415880(uint16(int16(v8)))
			v10 = v9
			if v9 == 0 {
				return 0
			}
			v11 = 0
			v18 = 0
			if v9 > 0 {
				for {
					v12 = v10 >> 8
					if v10>>8 > 0 {
						v10 >>= 8
					}
					v11++
					if v12 <= 0 {
						break
					}
				}
				v18 = v11
			}
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) != 0 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(v18)+a3)), 43)) |= uint8(int8(v10))
			} else {
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(v18)+a3)), 43)) &= ^uint8(int8(v10))
			}
		}
	} else {
		if int32(a1) != 4 {
			return 0
		}
		nox_sprintf(&v16[0], internCStr("%S"), *(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
		v6 = nox_xxx_spellNameToN_4243F0(&v16[0])
		if v6 == 0 {
			v6 = nox_xxx_spellByTitle_424960(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*2)))
			if v6 == 0 {
				return 0
			}
		}
		if !nox_xxx_spellIsValid_424B50(v6) {
			return 0
		}
		if nox_xxx_spellFlags_424A70(v6)&0x7000000 != 0 {
			if _nox_wcsicmp(*(**wchar2_t)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof((*wchar2_t)(nil))*3)), internWStr("off")) == 0 {
				sub_453FA0(a3+24, v6, 0)
			}
		}
	}
	if uint32(a4) == dword_5d4594_2523764 {
		return 1
	}
	return 0
}
func sub_57A950(a1 *byte) int32 {
	var v2 [256]byte
	libc.StrCpy(&v2[0], internCStr("maps\\"))
	libc.StrNCat(&v2[0], a1, 256-6)
	v2[libc.StrLen(&v2[0])-4] = 0
	libc.StrNCat(&v2[0], internCStr("\\"), 256-4)
	libc.StrCat(&v2[0], a1)
	return sub_4D0550(&v2[0])
}
func sub_57A9F0(a1 *byte, a2 *byte) int32 {
	var FileName [256]byte
	libc.StrCpy(&FileName[0], internCStr("maps\\"))
	libc.StrCat(&FileName[0], a1)
	libc.StrCat(&FileName[0], internCStr("\\"))
	libc.StrCat(&FileName[0], a2)
	return bool2int32(nox_fs_remove(&FileName[0]))
}
func sub_57AAA0(a1 *byte, a2 *byte, a3 *int32) int8 {
	var (
		v3       *FILE
		v4       *FILE
		i        *int32
		v6       *byte
		v7       int32
		v8       int32
		v9       *byte
		v10      int32
		v11      int32
		v12      *byte
		v13      int32
		v14      int32
		v15      *byte
		v16      *byte
		v18      int32
		v19      [24]byte
		v20      [36]byte
		v21      [24]byte
		v22      [36]byte
		v23      [256]byte
		FileName [256]byte
	)
	*((*uint8)(unsafe.Pointer(&v3))) = *(*byte)(unsafe.Add(unsafe.Pointer(a2), 52))
	if int32(int8(uintptr(unsafe.Pointer(v3)))) < 0 {
		return int8(uintptr(unsafe.Pointer(v3)))
	}
	libc.StrCpy(&FileName[0], internCStr("maps\\"))
	libc.StrNCat(&FileName[0], a2, 8)
	libc.StrNCat(&FileName[0], internCStr("\\"), 10)
	libc.StrCat(&FileName[0], a1)
	v3 = nox_fs_create_text(&FileName[0])
	v4 = v3
	if v3 == nil {
		return int8(uintptr(unsafe.Pointer(v3)))
	}
	if dword_5d4594_2650652 != 0 {
		libc.StrCpy(&v21[0], a2)
		libc.StrCpy(&v19[0], a2)
		sub_57A1E0((*int32)(unsafe.Pointer(&v21[0])), nil, nil, 4, int16(*((*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*26)))))
		sub_57A1E0((*int32)(unsafe.Pointer(&v19[0])), nil, nil, 3, int16(*((*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*26)))))
	}
	if a3 != nil {
		for i = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(a3))))); i != nil; i = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(i))))) {
			nox_sprintf(&v23[0], internCStr("%S\n"), (*int32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
			nox_fs_fputs(v4, &v23[0])
		}
	}
	v6 = sub_57A1B0(int16(*((*uint16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(uint16(0))*26)))))
	nox_fs_fputs(v4, v6)
	nox_fs_fputs(v4, internCStr("\n"))
	v7 = 1
	v8 = 136
	for {
		if nox_xxx_spellIsValid_424B50(v7) && sub_454000(unsafe.Add(unsafe.Pointer(a2), 24), v7) == 0 && nox_xxx_spellFlags_424A70(v7)&0x7000000 != 0 && (dword_5d4594_2650652 == nil || sub_454000(unsafe.Pointer(&v22[0]), v7) != 0 || sub_454000(unsafe.Pointer(&v20[0]), v7) == 0) {
			v9 = nox_xxx_spellNameByN_424870(v7)
			nox_sprintf(&v23[0], internCStr("%s %s \"%s\" %s\n"), "set", "spell", v9, "off")
			nox_fs_fputs(v4, &v23[0])
		}
		v7++
		v8--
		if v8 == 0 {
			break
		}
	}
	v10 = 1
	v11 = 26
	for {
		if (uint32(v10) & *((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*12)))) == 0 {
			v12 = sub_415E40((*byte)(v10))
			if v12 != nil {
				nox_sprintf(&v23[0], internCStr("%s %s \"%s\" %s\n"), "set", "Armor", v12, "off")
				nox_fs_fputs(v4, &v23[0])
			}
		}
		v10 *= 2
		v11--
		if v11 == 0 {
			break
		}
	}
	v13 = 1
	v14 = 1
	v18 = 27
	v15 = (*byte)(unsafe.Add(unsafe.Pointer(a2), 44))
	for {
		if (int32(uint8(int8(v13))) & int32(*v15)) == 0 {
			v16 = sub_4159B0((*byte)(v14))
			if v16 != nil {
				nox_sprintf(&v23[0], internCStr("%s %s \"%s\" %s\n"), "set", "weapon", v16, "off")
				nox_fs_fputs(v4, &v23[0])
			}
		}
		if v13 == 128 {
			v13 = 1
			v15 = (*byte)(unsafe.Add(unsafe.Pointer(v15), 1))
		} else {
			v13 *= 2
		}
		v14 *= 2
		v18--
		if v18 == 0 {
			break
		}
	}
	*((*uint8)(unsafe.Pointer(&v3))) = 0
	nox_fs_close(v4)
	return int8(uintptr(unsafe.Pointer(v3)))
}
func sub_57ADF0(a1 *int32) *int32 {
	var (
		result *int32
		v2     *int32
		v3     *int32
	)
	result = (*int32)(unsafe.Pointer(nox_common_list_getFirstSafe_425890((*nox_list_item_t)(unsafe.Pointer(a1)))))
	v2 = result
	if result == nil {
		return result
	}
	for {
		v3 = (*int32)(unsafe.Pointer(nox_common_list_getNextSafe_4258A0((*nox_list_item_t)(unsafe.Pointer(v2)))))
		nox_common_list_remove_425920(unsafe.Pointer(v2))
		alloc.Free(v2)
		v2 = v3
		if v3 == nil {
			break
		}
	}
	return result
}
func sub_57AE30(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 312208))
	for libc.StrCmp(*v2, a1) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*2))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 312264))) {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v1*8)+312212))
}
func nox_xxx_playerCheckSpellClass_57AEA0(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		result int32
		v4     int32
	)
	v2 = int32(nox_xxx_spellFlags_424A70(a2))
	if a1 == 1 {
		v4 = 0x2000000
	} else {
		if a1 != 2 {
			return 9
		}
		v4 = 0x4000000
	}
	if uint32(v2)&0x1000000 != 0 || v4&v2 != 0 {
		result = 0
	} else {
		result = 9
	}
	return result
}
func nox_xxx_get_57AF20() int32 {
	return int32(dword_5d4594_2523804)
}
func sub_57B0A0() {
	var (
		result int32
		v1     *uint32
	)
	result = int32(dword_5d4594_2523804)
	if result == 0 {
		return
	}
	v1 = (*uint32)(dword_5d4594_2523780)
	if dword_5d4594_2523780 != nil && (*memmap.PtrUint32(0x5D4594, 2523772) == 0 || *memmap.PtrUint32(0x5D4594, 2523772) == 1) {
		nox_xxx_netSendPointFx_522FF0(-102, (*types.Pointf)(unsafe.Add(unsafe.Pointer(dword_5d4594_2523780), 56)))
		v1 = (*uint32)(dword_5d4594_2523780)
	}
	if dword_5d4594_2523776 != nil {
		nox_xxx_delayedDeleteObject_4E5CC0(dword_5d4594_2523776)
		v1 = (*uint32)(dword_5d4594_2523780)
	}
	dword_5d4594_2523776 = nil
	if v1 != nil {
		nox_xxx_playerSetState_4FA020((*server.Object)(unsafe.Pointer(v1)), 13)
	}
	dword_5d4594_2523780 = nil
	if sub_45D9B0() == 0 {
		sub_413A00(0)
	}
	dword_5d4594_2523804 = 0
}
func nox_xxx___Getcvt_57B180() int64 {
	return int64(*memmap.PtrUint64(0x5D4594, 2523788))
}
func sub_57B190(a1 uint16, a2 uint16) int32 {
	var (
		result int32
		v3     float64
		v4     float64
	)
	if int32(a2) == 0 {
		return 4
	}
	if int32(a1) == int32(a2) {
		return 0
	}
	v3 = float64(a1)
	v4 = float64(a2)
	if v3 >= v4*qword_581450_9544 {
		return 1
	}
	result = 2
	if v3 < v4**mem_getDoublePtr(0x581450, 9608) {
		result = 3
	}
	return result
}
func sub_57B350() *float32 {
	return mem_getFloatPtr(0x5D4594, 2523812)
}
func nox_xxx_plrGetMaxVarsPtr_57B360(a1 int32) *float32 {
	return mem_getFloatPtr(0x5D4594, uint32(a1*16)+2523828)
}
func sub_57B370(a1 int32, a2 uint8, a3 int32) int8 {
	var (
		v3     *uint32
		result int8
	)
	if (uint32(a1) & 0x3001010) == 0 {
		return -1
	}
	if uint32(a1)&0x1001000 != 0 {
		v3 = (*uint32)(nox_xxx_getProjectileClassById_413250(a3))
		if v3 != nil {
			result = int8(*((*uint8)(unsafe.Add(unsafe.Pointer(v3), 62))))
		} else {
			result = 0
		}
		return result
	}
	if uint32(a1)&0x2000000 != 0 {
		v3 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(a3))
		if v3 != nil {
			result = int8(*((*uint8)(unsafe.Add(unsafe.Pointer(v3), 62))))
		} else {
			result = 0
		}
		return result
	}
	if a1&0x10 != 0 {
		result = int8(^(int32(a2) >> 5) | 0xFE)
	} else {
		result = int8(a3)
	}
	return result
}

var nox_cheat_allowall int32 = 0

func nox_xxx_playerClassCanUseItem_57B3D0(item *server.Object, a2 int8) int32 {
	if nox_cheat_allowall != 0 {
		return 1
	}
	return bool2int32((int32(uint8(int8(1<<int32(a2)))) & int32(uint8(sub_57B370(int32(item.ObjClass), uint8(item.ObjSubClass), int32(item.TypeInd))))) != 0)
}
func nox_xxx_client_57B400(a1 *client.Drawable) int32 {
	var v1 int32
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2523876))
	if *memmap.PtrUint32(0x5D4594, 2523876) == 0 {
		v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Glyph"))
		*memmap.PtrUint32(0x5D4594, 2523876) = uint32(v1)
	}
	if *memmap.PtrUint32(0x8531A0, 2576) == 0 {
		return 0
	}
	if a1.Field_27 != uint32(v1) || int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) == 1 {
		return 1
	}
	return 0
}
func sub_57B450(a1p *client.Drawable) int32 {
	var (
		a1 *int32 = (*int32)(unsafe.Pointer(a1p))
		v1 int32
		v2 uint8
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 2523880))
	if *memmap.PtrUint32(0x5D4594, 2523880) == 0 {
		v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Glyph"))
		*memmap.PtrUint32(0x5D4594, 2523880) = uint32(v1)
	}
	if a1 == nil || *memmap.PtrUint32(0x852978, 8) == 0 || *memmap.PtrUint32(0x8531A0, 2576) == 0 || *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*27)) == v1 && int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251))) != 1 {
		return 0
	}
	if nox_cheat_allowall != 0 {
		return 1
	}
	v2 = uint8(int8(1 << int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 2251)))))
	return bool2int32((int32(v2) & int32(uint8(sub_57B370(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*28)), uint8(int8(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*29)))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*27)))))) != 0)
}
func sub_57B630(a1 unsafe.Pointer, a2 int32, a3 int32) int8 {
	var (
		v4  int8
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  bool
		v10 bool
		v11 int8
		v13 int32
	)
	if !(a2 >= 0 && a2 < 256 && (a3 >= 0 || a3 < 256)) {
		return -1
	}
	v3 := nox_xxx_wall_4105E0(a2, a3)
	if v3 == nil {
		return -1
	}
	v4 = int8(v3.Flags4)
	if int32(v4)&0x10 != 0 {
		v5 = int32(v3.Data28)
		if v5 != 0 {
			v6 = int32(*(*uint32)(unsafe.Add(v5, 748)))
			v7 = int32(*(*uint32)(unsafe.Add(v6, 12)))
			if v7 == *(*int32)(unsafe.Add(v6, 4)) {
				v8 = *memmap.PtrInt32(0x587000, uintptr(v7*8)+196184)
				v9 = v8 < 0
				v10 = v8 <= 0
				if v8 > 0 {
					if *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) > 0 {
						v11 = 1
						if *(*uint32)(unsafe.Add(v5, 508)) != 0 {
							if nox_common_randomInt_415FA0(0, 100) >= 50 {
								return v11
							}
						} else if int32(*(*uint8)(unsafe.Add(v6, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910((*server.Object)(a1), (*server.Object)(v5)) == nil {
							return v11
						}
						return -1
					}
					v9 = v8 < 0
					v10 = v8 <= 0
				}
				if v9 {
					if *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) < 0 {
						v11 = 1
						if *(*uint32)(unsafe.Add(v5, 508)) != 0 {
							if nox_common_randomInt_415FA0(0, 100) >= 50 {
								return v11
							}
						} else if int32(*(*uint8)(unsafe.Add(v6, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910((*server.Object)(a1), (*server.Object)(v5)) == nil {
							return v11
						}
						return -1
					}
					v10 = v8 <= 0
					if v8 < 0 {
						if *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) > 0 {
							v11 = 0
							if *(*uint32)(unsafe.Add(v5, 508)) != 0 {
								if nox_common_randomInt_415FA0(0, 100) >= 50 {
									return v11
								}
							} else if int32(*(*uint8)(unsafe.Add(v6, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910((*server.Object)(a1), (*server.Object)(v5)) == nil {
								return v11
							}
							return -1
						}
						v10 = v8 <= 0
					}
				}
				if !v10 && *memmap.PtrInt32(0x587000, uintptr(v7*8)+196188) < 0 {
					v11 = 0
					if *(*uint32)(unsafe.Add(v5, 508)) != 0 {
						if nox_common_randomInt_415FA0(0, 100) >= 50 {
							return v11
						}
					} else if int32(*(*uint8)(unsafe.Add(v6, 1))) != 0 && nox_xxx_doorGetSomeKey_4E8910((*server.Object)(a1), (*server.Object)(v5)) == nil {
						return v11
					}
					return -1
				}
			}
		}
	} else if (*(*uint32)(unsafe.Add(a1, 16))&0x4000) == 0 || (int32(v4)&0x40) == 0 {
		if (int32(v4) & 4) == 0 {
			return int8(*(*uint8)(v3))
		}
		v13 = int32(v3.Data28)
		if (int32(*(*uint8)(unsafe.Add(v13, 20)))&2) == 0 && int32(*(*uint8)(unsafe.Add(v13, 22))) <= 0xB {
			return int8(*(*uint8)(v3))
		}
	}
	return -1
}
func sub_57B770(a1 *types.Pointf, a2 *types.Pointf) *types.Pointf {
	var (
		result *types.Pointf
		v3     float64
		v4     float64
		v5     float64
		v6     float64
		v7     float32
		v8     float32
		v9     float32
		v10    float32
		v11    float32
	)
	result = a2
	v9 = a2.X
	v3 = math.Sqrt(float64(a2.X*a2.X + a2.Y*a2.Y))
	v4 = v3 + 0.1
	v5 = float64(-a2.Y)
	v6 = float64(a1.X*a2.X+a1.Y*a2.Y) / (v3 + 0.1)
	v11 = float32((float64(a2.X*a1.Y) + v5*float64(a1.X)) / v4)
	v7 = float32(v6 * float64(result.X) / v4)
	v8 = float32(v6 * float64(result.Y) / v4)
	v10 = float32(float64(v11) * v5 / v4)
	a1.X = v10 - v7
	a1.Y = float32(float64(v11*v9)/v4 - float64(v8))
	return result
}
func nox_xxx_collideReflect_57B810(a1 *types.Pointf, a2 *types.Pointf) {
	if a1.Y*a1.X <= 0.0 {
		a2.X, a2.Y = a2.Y, a2.X
	} else {
		a2.X, a2.Y = -a2.Y, -a2.X
	}
}
func nox_xxx_map_57B850(a1 *types.Pointf, a2 *server.Shape, a3 *types.Pointf) int32 {
	var (
		v4 float32
		v5 float32
		v6 float32
		v7 float32
	)
	v4 = a2.Box.LeftTop + a1.X
	v5 = a2.Box.LeftBottom + a1.Y
	if !(float64(v5-v4+a3.X-a3.Y)*0.70709997 < 0.0 && float64(a2.Box.LeftTop2+a1.Y-(a2.Box.LeftBottom2+a1.X)+a3.X-a3.Y)*0.70709997 > 0.0) {
		return 0
	}
	v6 = a2.Box.RightTop + a1.X
	v7 = a2.Box.RightBottom + a1.Y
	if float64(v7+v6-a3.X-a3.Y)*0.70709997 > 0.0 && float64(v5+v4-a3.X-a3.Y)*0.70709997 < 0.0 {
		return 1
	}
	return 0
}
func sub_57B920(a1 unsafe.Pointer) int32 {
	var result int32
	result = 0
	libc.MemSet(a1, 0, 0x7F8)
	return result
}
func nox_xxx_cliGenerateAlias_57B9A0(a1 int32, a2 int32, a3 int32, a4 uint32) int8 {
	var (
		v4 int32
		v5 int32
	)
	v4 = int32(uint8(int8(a2)))
	v5 = int32(uint8(int8(a2)))
	if int32(uint8(int8(a2))) == math.MaxUint8 || int32(uint8(int8(a2))) == 0 {
		v4 = 1
		v5 = 1
	}
	for (int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + v4*8)))) != a2 || int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(a1+v4*8)), 2))) != a3) && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v4*8)), 4)) >= a4 {
		if func() int32 {
			p := &v4
			*p++
			return *p
		}() == math.MaxUint8 {
			v4 = 1
		}
		if v4 == v5 {
			*((*uint8)(unsafe.Pointer(&v4))) = math.MaxUint8
			return int8(v4)
		}
	}
	return int8(v4)
}
func sub_57BA10(a1 int32, a2 int16, a3 int16, a4 int32) int32 {
	var result int32
	result = a1
	*(*uint16)(a1) = uint16(a2)
	*(*uint16)(unsafe.Add(a1, 2)) = uint16(a3)
	*(*uint32)(unsafe.Add(a1, 4)) = uint32(a4)
	return result
}
func sub_57BA30(a1 *Point32, a2 *Point32, a3 *int4) int32 {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
		v12 int32
	)
	v12 = 0
	for {
		if a1.X >= a3.field_0 {
			if a1.X <= a3.field_8 {
				v3 = 0
			} else {
				v3 = 4
			}
		} else {
			v3 = 8
		}
		v4 = a1.Y
		v5 = a3.field_4
		if v4 >= v5 {
			if v4 > a3.field_C {
				*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(v3 | 1))
			}
		} else {
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(v3 | 2))
		}
		if a2.X >= a3.field_0 {
			if a2.X <= a3.field_8 {
				v6 = 0
			} else {
				v6 = 4
			}
		} else {
			v6 = 8
		}
		v7 = a2.Y
		if v7 >= v5 {
			if v7 > a3.field_C {
				v6 |= 1
			}
		} else {
			v6 |= 2
		}
		if v6&v3 != 0 {
			if v12 == 0 {
				return 0
			}
			v10 = a1.X
			v11 = a1.Y
			*a1 = *a2
			a2.X = v10
			a2.Y = v11
			return 0
		}
		if v3 == 0 {
			if v6 != 0 {
				v3 = a1.X
				v8 = a1.Y
				*a1 = *a2
				a2.X = v3
				a2.Y = v8
				*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(v6))
				v12 = bool2int32(v12 == 0)
				goto LABEL_20
			}
			if v12 == 0 {
				return 1
			}
			v10 = a1.X
			v11 = a1.Y
			*a1 = *a2
			a2.X = v10
			a2.Y = v11
			return 1
		}
	LABEL_20:
		if v3&1 != 0 {
			a1.X += (a3.field_C - a1.Y) * (a2.X - a1.X) / (a2.Y - a1.Y)
			a1.Y = a3.field_C
		} else if v3&2 != 0 {
			a1.X += (a3.field_4 - a1.Y) * (a2.X - a1.X) / (a2.Y - a1.Y)
			a1.Y = a3.field_4
		} else if v3&4 != 0 {
			a1.Y += (a3.field_8 - a1.X) * (a2.Y - a1.Y) / (a2.X - a1.X)
			a1.X = a3.field_8
		} else if v3&8 != 0 {
			a1.Y += (a2.Y - a1.Y) * (a3.field_0 - a1.X) / (a2.X - a1.X)
			a1.X = a3.field_0
		}
	}
}
func nox_server_getNextMapGroup_57C090(a1 int32) int32 {
	var result int32
	if a1 != 0 {
		result = int32(*(*uint32)(unsafe.Add(a1, 88)))
	} else {
		result = 0
	}
	return result
}
func sub_57C790(a1 *float4, a2 *types.Pointf, a3 *types.Pointf, a4 float32) {
	var (
		v4  float64
		v5  float64
		v6  float64
		v7  float64
		v8  float32
		v9  float32
		v10 float32
		v11 float32
		v12 float32
		v13 float32
	)
	v8 = a1.field_8 - a1.field_0
	v4 = float64(a1.field_C - a1.field_4)
	v9 = float32(v4)
	v5 = v4*float64(a2.Y-a1.field_4) + float64(v8*(a2.X-a1.field_0))
	v6 = float64(a4 * a4)
	v10 = float32(v5 * float64(v8) / v6)
	a3.X = v10 + a1.field_0
	a3.Y = float32(v5*float64(v9)/v6 + float64(a1.field_4))
	if float64(a1.field_0) >= float64(a1.field_8) {
		v12 = a1.field_0
		v13 = a1.field_8
	} else {
		v13 = a1.field_0
		v12 = a1.field_8
	}
	if float64(a1.field_4) >= float64(a1.field_C) {
		v7 = float64(a1.field_C)
		v11 = a1.field_4
	} else {
		v7 = float64(a1.field_4)
		v11 = a1.field_C
	}
	if float64(a3.X) >= float64(v13) {
		if float64(a3.X) > float64(v12) {
			a3.X = v12
		}
	} else {
		a3.X = v13
	}
	if v7 <= float64(a3.Y) {
		if float64(a3.Y) > float64(v11) {
			a3.Y = v11
		}
	} else {
		a3.Y = float32(v7)
	}
}
func nox_xxx_mathPointOnTheLine_57C8A0(a1 *float4, a2 *types.Pointf, a3 *types.Pointf) int32 {
	var (
		v3  *float4
		v4  *types.Pointf
		v5  float64
		v6  float64
		v7  float64
		v8  float64
		v10 float32
		v11 float32
		v12 float32
		v13 float32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
	)
	v3 = a1
	v4 = a3
	v5 = float64(a1.field_8 - a1.field_0)
	v6 = float64(a1.field_C - a1.field_4)
	v12 = float32(v6)
	v10 = float32(v6*float64(v12) + v5*v5)
	v7 = float64((a2.Y-a1.field_4)*v12) + float64(a2.X-a1.field_0)*v5
	v14 = float32(v7)
	v13 = v14 * v12 / v10
	a3.X = float32(v5*v7/float64(v10) + float64(v3.field_0))
	v15 = v13 + v3.field_4
	a3.Y = v15
	if float64(v3.field_0) >= float64(v3.field_8) {
		v8 = float64(v3.field_8)
		v16 = v3.field_0
	} else {
		v8 = float64(v3.field_0)
		v16 = v3.field_8
	}
	if float64(v3.field_4) >= float64(v3.field_C) {
		v11 = v3.field_4
		v17 = v3.field_C
	} else {
		v17 = v3.field_4
		v11 = v3.field_C
	}
	return bool2int32(v8 <= float64(v4.X) && float64(v4.X) <= float64(v16) && float64(v15) >= float64(v17) && float64(v15) <= float64(v11))
}
func sub_57CDB0(a1 *Point32, a2 *float32, a3 *types.Pointf) int32 {
	var (
		v3     *Point32
		v4     int8
		result int32
		v6     *types.Pointf
		v7     *types.Pointf
		v8     *types.Pointf
		v9     int8
	)
	v3 = a1
	v9 = int8(sub_57F2A0((*types.Pointf)(unsafe.Pointer(a2)), a1.X, a1.Y))
	v4 = sub_57F1D0((*types.Pointf)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(types.Pointf{})*1)))
	switch sub_57B500(v3.X, v3.Y, 64) {
	case 0:
		if int32(v9) != 1 && int32(v9) != 0 {
			v8 = a3
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = -0.70709997
		return 1
	case 1:
		if int32(v9) == 1 || int32(v9) == 2 {
			a3.X = 0.70709997
			a3.Y = -0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = 0.70709997
		return 1
	case 2:
		switch v9 {
		case 0:
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		case 1:
			v6 = a3
			if (int32(v4) & 1) == 0 {
				v6.X = 0.70709997
				v6.Y = -0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = -0.70709997
			result = 1
		case 2:
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		case 3:
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		default:
			return 1
		}
		return result
	case 3:
		if int32(v9) == 0 {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		}
		if int32(v9) != 1 {
			v8 = a3
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		}
		v7 = a3
		if (int32(v4) & 1) == 0 {
			v7.X = 0.70709997
			v7.Y = -0.70709997
			return 1
		}
		v7.X = -0.70709997
		v7.Y = -0.70709997
		return 1
	case 4:
		if int32(v9) == 1 {
			v7 = a3
			if (int32(v4) & 1) == 0 {
				v7.X = 0.70709997
				v7.Y = -0.70709997
				return 1
			}
			v7.X = -0.70709997
			v7.Y = -0.70709997
			return 1
		}
		if int32(v9) == 2 {
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = 0.70709997
		return 1
	case 5:
		if int32(v9) == 2 {
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		}
		if int32(v9) == 3 {
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = -0.70709997
		return 1
	case 6:
		if int32(v9) == 0 {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		}
		if int32(v9) == 3 {
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		}
		v6 = a3
		v6.X = 0.70709997
		v6.Y = -0.70709997
		return 1
	case 7:
		if int32(v9) == 1 {
			v7 = a3
			if (int32(v4) & 1) == 0 {
				v7.X = 0.70709997
				v7.Y = -0.70709997
				return 1
			}
			v7.X = -0.70709997
			v7.Y = -0.70709997
			return 1
		}
		v8 = a3
		if int32(v4)&1 != 0 {
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		}
		a3.X = -0.70709997
		a3.Y = 0.70709997
		return 1
	case 8:
		if int32(v9) == 2 {
			v8 = a3
			a3.X = 0.70709997
			if int32(v4)&1 != 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		} else {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 1) == 0 {
				v8.Y = 0.70709997
				return 1
			}
			a3.Y = -0.70709997
			return 1
		}
		fallthrough
	case 9:
		if int32(v9) == 3 {
			v8 = a3
			if (int32(v4) & 4) == 0 {
				v8.X = 0.70709997
				v8.Y = 0.70709997
				return 1
			}
			a3.X = -0.70709997
			a3.Y = 0.70709997
			return 1
		} else {
			v7 = a3
			if int32(v4)&4 != 0 {
				v7.X = 0.70709997
				v7.Y = -0.70709997
				return 1
			} else {
				v7.X = -0.70709997
				v7.Y = -0.70709997
				return 1
			}
		}
		fallthrough
	case 0xA:
		if int32(v9) != 0 {
			if int32(v4)&2 != 0 {
				a3.X = 0.70709997
				a3.Y = -0.70709997
				return 1
			}
			v8 = a3
			v8.X = 0.70709997
			v8.Y = 0.70709997
			return 1
		} else {
			v8 = a3
			a3.X = -0.70709997
			if (int32(v4) & 2) == 0 {
				a3.Y = -0.70709997
				return 1
			}
			v8.Y = 0.70709997
			return 1
		}
	default:
		return 0
	}
}
func sub_57F1D0(a1 *types.Pointf) int8 {
	var (
		v1 int8
		v2 int32
		v3 float64
		v4 float64
		v5 float64
		v7 uint8
	)
	v1 = 0
	v2 = int32(a1.X)
	v7 = uint8(int8(int32(a1.Y) % 23))
	v3 = float64(uint8(int8(v2 % 23)))
	if v3 >= 11.5 {
		v4 = float64(v7)
		if v4 >= 11.5 {
			v1 = 4
		}
		if v4 <= 11.5 {
			v1 |= 1
		}
	}
	if v3 > 11.5 {
		return v1
	}
	v5 = float64(v7)
	if v5 >= 11.5 {
		v1 |= 8
	}
	if v5 <= 11.5 {
		v1 |= 2
	}
	return v1
}
func sub_57F2A0(a1 *types.Pointf, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		v4     int32
		result int32
		v6     int32
		v7     float32
		v8     float32
	)
	v7 = float32(float64(a1.X) - float64(a2*23))
	v3 = int32(v7)
	v8 = float32(float64(a1.Y) - float64(a3*23))
	v4 = int32(v8)
	if v3 <= v4 {
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(bool2int32(22-v3 <= v4)))
		v6 = v4 - 1
		*((*uint8)(unsafe.Pointer(&v6))) = uint8(int8(v6 & 0xFD))
		result = v6 + 3
	} else {
		*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8(bool2int32(22-v3 <= v4)))
		result = v4 + 1
	}
	return result
}
func nullsub_10(a1 uint32) {
}
func sub_42CC50(this *unsafe.Pointer) int32 {
	return sub_42C770(this)
}
func nox_xxx_j_resetNPCRenderData_49A2E0() {
	nox_alloc_npcs()
}
func nox_xxx_j_inventoryNameSignInit_467460() int32 {
	return nox_xxx_inventoryNameSignInit_4671E0()
}
func nox_alloc_npcs_2() {
	nox_alloc_npcs()
}
func Nullsub_8(a1 *Point32, a2 unsafe.Pointer) {
}
func nullsub_30(a1 unsafe.Pointer) {
}
func Nullsub_29(sp *server.DurSpell) {
}
func nullsub_35(a1 unsafe.Pointer, a2 uint32) {
}
func nox_xxx_j_allocHitArray_511840() {
	nox_xxx_allocHitArray_5486D0()
}
