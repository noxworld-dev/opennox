package legacy

import (
	"math"
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	importantAlloc       alloc.ClassT[importantClass]
	dword_5d4594_1565516 *importantClass
	dword_5d4594_1565512 *importantClass
	dword_5d4594_1565520 int
	importantArr1565524  [32]uint16
	ImportantArr1565124  [32]server.ImportantItem2
	importantBuf1564964  [4096]byte // TODO: size is a guess
)
var dword_5d4594_2649712 uint32

var _ = [1]struct{}{}[416-unsafe.Sizeof(importantClass{})]

type importantClass struct {
	Field0   uint32          // 0, 0
	Field4   [32]uint32      // 1, 4
	Field132 [32]byte        // 33, 132
	Field164 byte            // 41, 164
	Field165 byte            // 41, 165
	Field166 uint16          // 41, 166
	Field168 uint32          // 42, 168
	Field172 uint32          // 43, 172
	Field176 uint32          // 44, 176
	Field180 uint32          // 45, 180
	Field184 byte            // 46, 184
	Field185 byte            // 46, 185
	Field186 [32]uint16      // 46, 186
	Field250 int8            // 62, 250
	Field251 [149]byte       // 62, 251
	Field401 byte            // 100, 401
	Field402 uint16          // 100, 402
	Field404 unsafe.Pointer  // 101, 404
	Field408 *importantClass // 102, 408
	Field412 *importantClass // 103, 412
}

func freeImportantMsg3X() { // sub_4E4F80
	var next *importantClass
	for it := dword_5d4594_1565512; it != nil; it = next {
		next = it.Field408
		if v := it.Field251[0]; v >= 0x31 && v <= 0x33 {
			freeImportantMsg(it)
		}
	}
}
func freeImportantMsg(p *importantClass) { // sub_4E4FC0
	if v1 := p.Field412; v1 != nil {
		v1.Field408 = p.Field408
	} else {
		dword_5d4594_1565512 = p.Field408
	}
	if v2 := p.Field408; v2 != nil {
		v2.Field412 = p.Field412
	} else {
		dword_5d4594_1565516 = p.Field412
	}
	importantAlloc.FreeObjectFirst(p)
}

func Nox_xxx_netSendPacket_4E5030(a1 int, data []byte, a4 unsafe.Pointer, a5 int, a6 int) int {
	if !(a1 == math.MaxUint8 || (a1&0x80) == 0 || dword_5d4594_2649712&uint32(^(1<<(a1&math.MaxInt8))) != 0) {
		return 1
	}
	if len(data) > 150 {
		return 0
	}
	aclass := importantAlloc
	if aclass.Class == nil {
		if noxflags.HasGame(2048) {
			dword_5d4594_1565520 = 512
		} else if noxflags.HasGame(1) {
			dword_5d4594_1565520 = 3072
		} else {
			dword_5d4594_1565520 = 256
		}
		if noxflags.HasGame(2048) {
			aclass = alloc.NewDynamicClassT("importantClass", importantClass{}, dword_5d4594_1565520)
		} else {
			aclass = alloc.NewClassT("importantClass", importantClass{}, dword_5d4594_1565520)
		}
		importantAlloc = aclass
	}
	p := aclass.NewObject()
	if p == nil {
		if nox_xxx_importantCheckRate_4E52B0() != 1 {
			return 0
		}
		p = importantAlloc.NewObject()
		if p == nil {
			return 0
		}
	}
	copy(p.Field251[:], data)
	p.Field401 = byte(len(data))
	p.Field404 = a4
	p.Field250 = int8(a1)
	p.Field180 = uint32(a5)
	p.Field184 = byte(int8(a6))
	p.Field172 = 0
	p.Field168 = 0
	p.Field164 = 0
	p.Field176 = dword_5d4594_2649712
	p.Field4 = [32]uint32{}
	p.Field0 = gameFrame()
	p.Field186 = [32]uint16{}
	if p.Field184 != 0 {
		if a1 == math.MaxUint8 {
			for i := range importantArr1565524 {
				v11p := &importantArr1565524[i]
				if (1<<uint32(i))&p.Field176 != 0 {
					p.Field186[i] = *v11p
					*v11p++
				}
			}
		} else if (a1 & 0x80) == 0 {
			ptr := &importantArr1565524[a1]
			p.Field186[a1] = *ptr
			*ptr++
		} else {
			v13 := int32(byte(p.Field250) & math.MaxInt8)
			for i := range importantArr1565524 {
				v12p := &importantArr1565524[i]
				if i != int(v13) && uint32(1<<i)&p.Field176 != 0 {
					p.Field186[i] = *v12p
					*v12p++
				}
			}
		}
	}
	p.Field412 = nil
	p.Field408 = dword_5d4594_1565512
	if dword_5d4594_1565512 == nil {
		dword_5d4594_1565516 = p
		dword_5d4594_1565512 = p
	} else {
		dword_5d4594_1565512.Field412 = p
		dword_5d4594_1565512 = p
	}
	return 1
}

func sub_4E4DE0() {
	importantAlloc.Free()
	importantArr1565524 = [32]uint16{}
	ImportantArr1565124 = [32]server.ImportantItem2{}
	dword_5d4594_1565512 = nil
	dword_5d4594_1565516 = nil

	for i := range ImportantArr1565124 {
		p := &ImportantArr1565124[i]
		p.Field0 = 1
		p.Field1 = 2
		p.Field2 = uint8(int8(nox_xxx_rateGet_40A6C0()))
		sub_4E4E50(i)
	}
}

func sub_4E4E50(pind int) {
	v1 := uint32(1)
	if dword_5d4594_2650652 == 1 {
		v1 = uint32(nox_xxx_rateGet_40A6C0())
	}
	p := &ImportantArr1565124[pind]
	if int32(p.Field1) > 2 {
		p.Field8 = uint32(int32(p.Field0)*(int32(p.Field1)-1)) * (gameFPS() / v1)
	} else {
		p.Field8 = 0
	}
	p.Field4 = uint32(int32(p.Field1)*int32(p.Field0)) * (gameFPS() / v1)
}
func nox_xxx_importantCheckRate2_4E5670(pind int) {
	var v1 int32
	//nox_common_playerInfoFromNum_417090(int32(a1))
	v2 := dword_5d4594_1565516
	if dword_5d4594_1565516 != nil {
		for {
			v3 := v2.Field412
			if v2.Field168&(1<<uint32(pind)) == 0 {
				v4 := v2.Field250
				if int32(v4) == -1 {
					v1++
				} else if int32(v4) >= 0 {
					if int32(v4) == int32(pind) {
						v1++
					}
				} else if int32(pind) != (int32(v4) & math.MaxInt8) {
					v1++
				}
			}
			v2 = v3
			if v3 == nil {
				break
			}
		}
	}
	v5 := &ImportantArr1565124[pind]
	if nox_xxx_rateGet_40A6C0() != int32(v5.Field2) {
		v5.Field2 = uint8(int8(nox_xxx_rateGet_40A6C0()))
	}
	if uint32(v1) <= v5.Field4 {
		v8 := int32(v5.Field8)
		if v8 > 0 && v1 < v8 {
			if v5.Field0 == 2 {
				v5.Field0 = 1
				sub_4E4E50(pind)
				return
			}
			v9 := uint8(int8(int32(v5.Field1) - 1))
			v5.Field1 = v9
			if int32(v9) < 2 {
				v5.Field1 = 2
			}
		}
		sub_4E4E50(pind)
	} else {
		v6 := uint8(int8(int32(v5.Field1) + 1))
		v5.Field1 = v6
		if int32(v6) > 5 {
			if v5.Field0 == 2 {
				nox_xxx_playerKickDueToRate_4E5360(int32(pind))
			}
			v5.Field1 = 5
			v5.Field0 = 2
		}
		v5.Field2 = uint8(int8(nox_xxx_rateGet_40A6C0()))
		sub_4E4E50(pind)
	}
}
func nox_xxx_netImportant_4E5770(a1 int, a2 int32) {
	var (
		v2  int32
		v10 int32
		v14 int32
		v15 int32
		v16 int32
	)
	v2 = 1 << int32(a1)
	v15 = 1
	v14 = 0
	v16 = 1 << int32(a1)
	v3 := nox_common_playerInfoFromNum_417090(int32(a1))
	v13 := nox_netlist_addToMsgListCli_40EBC0
	if int32(a1) != 31 {
		v13 = nox_netlist_clientSendWrap_40ECA0
	}
	if !(v3 == nil || !noxflags.HasGame(1) || *(*byte)(unsafe.Add(unsafe.Pointer(v3), 3680))&0x10 != 0) {
		return
	}
	var next *importantClass
	for it := dword_5d4594_1565516; it != nil; it = next {
		next = it.Field412
		v5 := it.Field404
		if v5 != nil && int32(*(*uint8)(unsafe.Add(v5, 16)))&0x20 != 0 {
			it.Field404 = nil
		}
		if uint32(v2)&it.Field168 != 0 {
			continue
		}
		v6 := it.Field250
		if int32(v6) != -1 {
			if int32(v6) >= 0 {
				if int32(v6) != int32(a1) {
					continue
				}
			} else if int32(a1) == (int32(v6) & math.MaxInt8) {
				continue
			}
		}
		v7 := it.Field404
		if v7 != nil && (uint32(v2)&*(*uint32)(unsafe.Add(v7, 148))) == 0 || it.Field180 != 0 && (uint32(v2)&dword_5d4594_2649712) == 0 {
			sub_4E54D0(v2, it, int32(a1))
			return
		}
		if (uint32(v2) & it.Field172) != 0 {
			v8 := int8(it.Field132[a1])
			if int32(v8) != 0 {
				it.Field132[a1] = uint8(int8(int32(v8) - 1))
				continue
			}
			if v14 >= int32(ImportantArr1565124[a1].Field0) {
				continue
			}
			v9 := int8(int32(it.Field164) + 1)
			v10 = v14 + 1
			it.Field172 &= uint32(^v2)
			it.Field164 = uint8(v9)
			v14 = v10
		}
		if v15 != 0 {
			if a2 != 0 && int32(a1) != 31 {
				var v12 [1]byte
				v12[0] = 170
				if v13(int32(a1), a2, &v12[0], 1) == 0 {
					return
				}
			} else {
				var v18 [5]byte
				v18[0] = 170
				*(*uint32)(unsafe.Pointer(&v18[1])) = gameFrame()
				if v13(int32(a1), a2, &v18[0], 5) == 0 {
					return
				}
			}
			v15 = 0
		}
		var v11 int32
		if it.Field184 == 0 {
			v11 = v13(int32(a1), a2, &it.Field251[0], int32(it.Field401))
		} else {
			importantBuf1564964[0] = 204
			*(*uint16)(unsafe.Pointer(&importantBuf1564964[1])) = it.Field186[a1]
			importantBuf1564964[3] = it.Field401
			asz := it.Field401
			copy(importantBuf1564964[:asz], it.Field251[:asz])
			v11 = v13(int32(a1), a2, &importantBuf1564964[0], 4+int32(it.Field401))
			v2 = v16
		}
		if v11 != 0 {
			it.Field172 |= uint32(v2)
			it.Field132[a1] = uint8(gameFPS() * uint32(ImportantArr1565124[a1].Field1) / uint32(nox_xxx_rateGet_40A6C0()))
			it.Field4[a1] = gameFrame()
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ) {
				sub_4E54D0(v2, it, int32(a1))
			}
		}
	}
	if noxflags.HasGame(1) && (gameFrame()%(gameFPS()*uint32(ImportantArr1565124[a1].Field1))) == 0 {
		nox_xxx_importantCheckRate2_4E5670(a1)
	}
}
func nox_net_importantACK_4E55A0(a1 int32, a2 int32) {
	var next *importantClass
	for it := dword_5d4594_1565512; it != nil; it = next {
		next = it.Field408
		if it.Field4[a1] == uint32(a2) {
			sub_4E54D0(1<<a1, it, a1)
		}
	}
}
func sub_4E55F0(a1 uint8) {
	var next *importantClass
	for it := dword_5d4594_1565512; it != nil; it = next {
		next = it.Field408
		sub_4E54D0(1<<int32(a1), it, int32(a1))
	}
}
func sub_4E4F30(a1 int32) {
	importantArr1565524[a1] = 0
}
func nox_xxx_playerResetImportantCtr_4E4F40(a1 int) {
	p := &ImportantArr1565124[a1]
	p.Field0 = 1
	p.Field1 = 2
	p.Field2 = uint8(int8(nox_xxx_rateGet_40A6C0()))
	sub_4E4E50(a1)
}
func nox_xxx_importantCheckRate_4E52B0() int32 {
	if dword_5d4594_1565512 == nil {
		return 0
	}
	v3 := uint16(0)
	v2 := -1
	v4 := uint32(999999999)
	var v8 [32]int16
	v8[0] = 0
	v8[31] = 0
	var found *importantClass
	for it := dword_5d4594_1565512; it != nil; it = it.Field408 {
		if v5 := it.Field250; v5 != -1 && v5 >= 0 && v5 != 31 {
			v6 := it.Field250
			if int32(uint16(func() int16 {
				p := &v8[v6]
				*p++
				return *p
			}())) > int32(v3) {
				v2 = int(v6)
				v3 = uint16(v8[v6])
			}
		}
		if it.Field0 < v4 {
			v4 = it.Field0
			found = it
		}
	}
	if v2 != -1 {
		nox_xxx_playerKickDueToRate_4E5360(int32(v2))
	}
	if found == nil {
		return 0
	}
	freeImportantMsg(found)
	return 1
}
func nox_xxx_playerKickDueToRate_4E5360(pind int32) {
	if pl := nox_common_playerInfoFromNum_417090(pind); pl != nil {
		sub_4E55F0(uint8(int8(pind)))
		nox_xxx_netNeedTimestampStatus_4174F0(pl, 128)
	}
}
func sub_4E5450(a1 int32, a2 []byte, a4 unsafe.Pointer, a5 int32) int32 {
	v9 := a2[0]
	if dword_5d4594_1565512 == nil {
		return nox_xxx_netSendPacket0_4E5420(a1, a2, a4, a5)
	}
	var next *importantClass
	for it := dword_5d4594_1565512; it != nil; it = next {
		next = it.Field408
		if int32(v9) == int32(it.Field251[0]) {
			if a1 == math.MaxUint8 || (a1&0x80) != 0 {
				freeImportantMsg(it)
			} else {
				sub_4E54D0(1<<a1, it, a1)
			}
		}
	}
	return nox_xxx_netSendPacket0_4E5420(a1, a2, a4, a5)
}

func sub_4E4ED0() {
	importantArr1565524 = [32]uint16{}
}

func Sub_4E4F30(a1 ntype.PlayerInd) {
	importantArr1565524[a1] = 0
}

func sub_4E4EF0() {
	ImportantArr1565124 = [32]server.ImportantItem2{}
	for i := range ImportantArr1565124 {
		p := &ImportantArr1565124[i]
		p.Field0 = 1
		p.Field1 = 2
		p.Field2 = uint8(int8(nox_xxx_rateGet_40A6C0()))
		sub_4E4E50(i)
	}
}

func nox_xxx_netSendPacket1_4E5390(a1 int32, a2 []byte, a4 unsafe.Pointer, a5 int32) int32 {
	return int32(Nox_xxx_netSendPacket_4E5030(int(a1), a2, a4, int(a5), 1))
}
func nox_xxx_netSendPacket0_4E5420(a1 int32, a2 []byte, a4 unsafe.Pointer, a5 int32) int32 {
	return int32(Nox_xxx_netSendPacket_4E5030(int(a1), a2, a4, int(a5), 0))
}

func nox_xxx_netClientSend2_4E53C0(a1 int32, a2 []byte, a5 int32) int32 {
	if noxflags.HasGame(1) {
		nox_netlist_addToMsgListCli_40EBC0(a1, 0, &a2[0], int32(len(a2)))
		return 1
	}
	if a1 == math.MaxUint8 || (a1&0x80) != 0 {
		return 0
	}
	return nox_xxx_netSendPacket0_4E5420(a1, a2, nil, a5)
}
func sub_4E54D0(a1 int32, a2 *importantClass, a3 int32) {
	var (
		v4 int8
		v5 int32
		v6 int8
		v7 int32
		v8 int32
		v9 int32
	)
	v3 := a2.Field404
	if v3 != nil {
		v4 = int8(a2.Field251[0])
		if int32(v4) == 49 || int32(v4) == 50 || int32(v4) == 51 {
			*(*uint32)(unsafe.Add(v3, 148)) &= uint32(^a1)
		}
	}
	v5 = int32(dword_5d4594_2649712 & a2.Field176)
	v6 = a2.Field250
	if int32(v6) == -1 {
		v7 = int32(uint32(a1) | a2.Field168)
		a2.Field168 = uint32(v7)
		if (v5 & v7) == v5 {
			freeImportantMsg(a2)
		}
	} else if int32(v6) >= 0 {
		if int32(a2.Field250) == a3 {
			freeImportantMsg(a2)
		}
	} else {
		v8 = 1 << (int32(v6) & math.MaxInt8)
		v9 = int32(uint32(a1) | a2.Field168)
		a2.Field168 = uint32(v9)
		if (v5 & ^v8 & v9) == (v5 & ^v8) {
			freeImportantMsg(a2)
		}
	}
}
