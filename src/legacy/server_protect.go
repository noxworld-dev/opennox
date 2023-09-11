package legacy

import (
	"encoding/binary"
	"math"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

const protectValXxx = 657757279 // 0x2734945F

var (
	protectValTwo     uint32             // dword_5d4594_2516328
	protectVal2516332 uint32             // dword_5d4594_2516332
	protectListOne    *protectStruct     // dword_5d4594_2516344
	protectVal2516340 uint32             // dword_5d4594_2516340
	protectValOne     uint32             // dword_5d4594_2516348
	protectListTwo    *protectStruct     // dword_5d4594_2516352
	protectValThree   uint32             // dword_5d4594_2516356
	protectVal2516360 uint32             // dword_5d4594_2516360
	protectVal2516364 uint32             // dword_5d4594_2516364
	protectCnt        uint16         = 7 // 311204
)

type protectStruct struct {
	Field0  uint32
	Field4  uint32
	Field8  *protectStruct
	Field12 *protectStruct
}

func Sub_56F1C0() {
	protectRandReset(uint32(time.Now().Unix()))
	protectListTwo = nil
	protectValOne = gameFrame()
	protectListOne = nil
	protectCnt = 0
	protectValThree = protectValXxx
	protectValOne ^= protectRandom()
	protectValTwo = ^protectValOne
	protectVal2516340 = nox_xxx_protectionCreateInt_56F400(0)
	sub_56F250()
	protectVal2516332 = nox_xxx_protectionCreateInt_56F400(1)
}

func sub_56F250() {
	v0 := 7
	for {
		nox_xxx_protectionCreateStructForInt_56F280(protectValThree, 0)
		v0--
		protectValThree++
		if v0 == 0 {
			break
		}
	}
}

func protectRandom() uint32 { // nox_xxx_protect_56F240
	return protectRandUint(1, math.MaxUint32)
}

func nox_xxx_playerResetProtectionCRC_56F7D0(a1 uint32, a2 uint32) {
	if a1 < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := a2 ^ protectValOne
	p.Field4 = a2 ^ protectValOne
	protectValTwo ^= v3
	nox_xxx_protectData_56F5C0()
}

func sub_56F590(val uint32) *protectStruct {
	p := protectListOne
	if p == nil {
		return nil
	}
	for p.Field0 != (val ^ protectValOne) {
		p = p.Field8
		if p == nil {
			return nil
		}
	}
	return p
}

func nox_xxx_protectData_56F5C0() {
	v2 := protectRandom() ^ gameFrame()
	v3 := v2 ^ protectValOne
	protectValTwo ^= v2
	for i := 0; i < int(protectCnt)/4; i++ {
		ind1 := int(nox_common_randomInt_415FA0(0, int32(protectCnt/2)))
		ind2 := int(nox_common_randomInt_415FA0(int32(protectCnt)/2+1, int32(protectCnt)-1))
		if ind1 != ind2 {
			p1 := protectListOneByInd(ind1)
			p2 := protectListOneByInd(ind2)
			protectSwap(p1, p2)
		}
	}

	protectValOne = 0
	for it := protectListOne; it != nil; it = it.Field8 {
		it.Field0 = v3 ^ it.Field0
		it.Field4 = v3 ^ it.Field4
		protectValTwo ^= it.Field0
		protectValTwo ^= it.Field4
	}
	protectVal2516364++
	protectValOne ^= v2
}

func protectListOneByInd(ind int) *protectStruct { // sub_56F6F0
	var i int
	for it := protectListOne; it != nil; it = it.Field8 {
		if i == ind {
			return it
		}
		i++
	}
	return nil
}

func sub_56F2F0(p *protectStruct) int32 {
	var (
		v2 int16
		i  int16
	)
	v1 := protectListOne
	v2 = 0
	if int32(protectCnt) != 0 {
		for i = int16(nox_common_randomInt_415FA0(0, int32(protectCnt)-1)); v1 != nil; v2++ {
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
			protectCnt++
		} else {
			protectCnt++
			protectListOne = p
		}
		return 1
	} else {
		protectCnt++
		protectListTwo = p
		protectListOne = p
		return 1
	}
}

func Sub_56F3B0() {
	result := protectListOne
	if protectListOne != nil {
		for {
			v1 := result.Field8
			alloc.Free(result)
			result = v1
			if v1 == nil {
				break
			}
		}
	}
	protectValTwo = 0
	protectCnt = 0
	protectValOne = 0
	protectListTwo = nil
	protectListOne = nil
}

func sub_56F510(a1 uint32) int32 {
	p := sub_56F590(a1)
	if p == nil {
		return 0
	}
	v2 := p.Field12
	if v2 != nil {
		v2.Field8 = p.Field8
	} else {
		protectListOne = p.Field8
	}
	v3 := p.Field8
	if v3 != nil {
		v3.Field12 = p.Field12
	} else {
		protectListTwo = p.Field12
	}
	v4 := p.Field0 ^ protectValTwo
	protectValTwo = v4
	v5 := p.Field4 ^ v4
	protectCnt--
	protectValTwo = v5
	alloc.Free(p)
	return 1
}

func nox_xxx_playerApplyProtectionCRC_56FD50(a1 uint32, a2p unsafe.Pointer, a3 int32) int32 {
	var (
		a2 = a2p
		v3 int32
		v5 int32
		v6 *int32
	)
	v3 = 0
	if uint32(a1) < protectValXxx {
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
	if (uint32(v3) ^ protectValOne) == v4.Field4 {
		return 1
	}
	return 0
}

func sub_56FCB0(a1 int32, a2 int32) int32 {
	var result int32
	result = 0
	if a2 != 0 {
		result = 1 << (a1 % 32)
	}
	return result
}

func nox_xxx_playerAwardSpellProtectionCRC_56FCE0(a1 uint32, a2 int32, a3 int32) {
	if uint32(a1) < protectValXxx {
		return
	}
	v4 := sub_56F590(a1)
	v5 := v4
	if v4 == nil {
		return
	}
	protectValTwo ^= v4.Field4
	result := int32(protectValOne ^ (protectValOne ^ v4.Field4 | uint32(sub_56FCB0(a2, a3))))
	v5.Field4 = uint32(result)
	protectValTwo ^= uint32(result)
}

func nox_xxx_protectionCreateStructForFloat_56F480(a1 uint32, val float32) int32 {
	a2 := math.Float32bits(val)
	p, _ := alloc.New(protectStruct{})
	if p == nil {
		return 0
	}
	p.Field12 = nil
	p.Field8 = nil
	v3 := a1 ^ protectValOne
	p.Field0 = a1 ^ protectValOne
	protectValTwo ^= v3
	p.Field4 = a2
	v4 := a2 ^ protectValOne
	p.Field4 = a2 ^ protectValOne
	protectValTwo ^= v4
	return sub_56F2F0(p)
}

func nox_xxx_protectionCreateStructForInt_56F280(val1 uint32, val2 uint32) int32 {
	p, _ := alloc.New(protectStruct{})
	if p == nil {
		return 0
	}
	p.Field8 = nil
	p.Field12 = nil
	p.Field0 = val1 ^ protectValOne
	protectValTwo ^= p.Field0
	p.Field4 = val2 ^ protectValOne
	protectValTwo ^= p.Field4
	return sub_56F2F0(p)
}

func nox_xxx_protectMana_56F9E0(a1 uint32, a2 int16) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := int32(protectValOne ^ (uint32(a2) + (protectValOne ^ p.Field4)))
	p.Field4 = uint32(v3)
	protectValTwo ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}

func nox_xxx_protectPlayerHPMana_56F870(a1 uint32, a2 uint16) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := int32(protectValOne ^ uint32(a2))
	p.Field4 = uint32(v3)
	protectValTwo ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}

func sub_56F780(a1 uint32, a2 int32) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := int32(uint32(a2) ^ protectValOne)
	p.Field4 = uint32(a2) ^ protectValOne
	protectValTwo ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}

func sub_56F820(a1 uint32, a2 uint8) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := int32(protectValOne ^ uint32(a2))
	p.Field4 = uint32(v3)
	protectValTwo ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}

func sub_56F8C0(a1 uint32, a2 float32) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	v3 := p
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v4 := int32(uint32(uint64(protectValOne) ^ uint64(int64(a2))))
	v3.Field4 = uint32(v4)
	protectValTwo ^= uint32(v4)
	nox_xxx_protectData_56F5C0()
}

func sub_56F920(a1 uint32, a2 int32) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := int32(protectValOne ^ (uint32(a2) + (protectValOne ^ p.Field4)))
	p.Field4 = uint32(v3)
	protectValTwo ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}

func sub_56FA40(a1 uint32, a2 float32) {
	if uint32(a1) < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	v3 := p
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v4 := int32(uint32(uint64(protectValOne) ^ uint64(int64(float64(protectValOne^p.Field4)+float64(a2)))))
	v3.Field4 = uint32(v4)
	protectValTwo ^= uint32(v4)
	nox_xxx_protectData_56F5C0()
}

func sub_56FB00(a1 *byte, a2 uint32, a3 uint32) int32 {
	if uint32(a3) < protectValXxx {
		return 0
	}
	p := sub_56F590(a3)
	if p != nil && (protectValOne^uint32(nox_xxx_protectionStringCRCLen_56FAE0(a1, a2))) == p.Field4 {
		return 1
	}
	return 0
}

func sub_56F980(a1 uint32, a2 uint8) {
	if a1 < protectValXxx {
		return
	}
	p := sub_56F590(a1)
	if p == nil {
		return
	}
	protectValTwo ^= p.Field4
	v3 := int32(protectValOne ^ (uint32(a2) + (protectValOne ^ p.Field4)))
	p.Field4 = uint32(v3)
	protectValTwo ^= uint32(v3)
	nox_xxx_protectData_56F5C0()
}

func nox_xxx_protectionStringCRC_56FAC0(str *byte, sz uint32) uint32 {
	s := unsafe.Slice(str, sz)
	var crc uint32
	it := s
	for i := sz / 4; i != 0; i-- {
		crc ^= binary.LittleEndian.Uint32(it[0:4])
		it = it[4:]
	}
	return crc
}
func nox_xxx_protectionStringCRCLen_56FAE0(str *byte, sz uint32) uint32 {
	if str == nil {
		return 0
	}
	return nox_xxx_protectionStringCRC_56FAC0(str, sz)
}

func protectSwap(a, b *protectStruct) { // sub_56F720
	if a == nil || b == nil {
		return
	}
	a.Field0, b.Field0 = b.Field0, a.Field0
	a.Field4, b.Field4 = b.Field4, a.Field4
	protectVal2516360++
}

func nox_xxx_protect_56FBF0(a1 uint32, item *server.Object) {
	if uint32(a1) < protectValXxx {
		return
	}
	v3 := sub_56F590(a1)
	v4 := v3
	if v3 == nil {
		return
	}
	protectValTwo ^= v3.Field4
	v5 := int32(uint32(sub_56FB60(item)) ^ v3.Field4)
	v4.Field4 = uint32(v5)
	protectValTwo ^= uint32(v5)
}

func nox_xxx_protect_56FC50(a1 uint32, obj *server.Object) {
	if uint32(a1) < protectValXxx {
		return
	}
	v3 := sub_56F590(a1)
	v4 := v3
	if v3 == nil {
		return
	}
	protectValTwo ^= v3.Field4
	v5 := int32(uint32(sub_56FB60(obj)) ^ v3.Field4)
	v4.Field4 = uint32(v5)
	protectValTwo ^= uint32(v5)
}

func nox_xxx_protectionCreateInt_56F400(a1 uint32) uint32 {
	if nox_xxx_protectionCreateStructForInt_56F280(protectValThree, a1) != 0 {
		return func() uint32 {
			p := &protectValThree
			x := *p
			*p++
			return x
		}()
	}
	return 0
}
