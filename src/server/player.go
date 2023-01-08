package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/player"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

type Player struct {
	_ [4828]byte
}

var (
	_ = [1]struct{}{}[97-unsafe.Sizeof(PlayerInfo{})]
	_ = [1]struct{}{}[0-unsafe.Offsetof(PlayerInfo{}.name)]
	_ = [1]struct{}{}[66-unsafe.Offsetof(PlayerInfo{}.playerClass)]
	_ = [1]struct{}{}[89-unsafe.Offsetof(PlayerInfo{}.nameSuff)]
)

type PlayerInfo struct {
	name        [50]byte // 2185 (+0) // TODO: size is a guess
	field2235   [4]byte  // 2235 (+50)
	field2239   [4]byte  // 2239 (+54)
	field2243   [4]byte  // 2243 (+58)
	field2247   [4]byte  // 2247 (+62)
	playerClass byte     // 562, 2251 (+66)
	isFemale    byte     // 562, 2252 (+67)
	field2253   [2]byte  // 2253 (+68)
	Field2255   byte     // 2255 (+70)
	field2256   [2]byte  // 2256 (+71)
	Field2258   byte     // 2258 (+73)
	field2259   [2]byte  // 2259 (+74)
	Field2261   byte     // 2261 (+76)
	field2262   [2]byte  // 2262 (+77)
	Field2264   byte     // 2264 (+79)
	field2265   [2]byte  // 2265 (+80)
	Field2267   byte     // 2267 (+82)
	Field2268   byte     // 2268 (+83)
	Field2269   byte     // 2269 (+84)
	Field2270   byte     // 2270 (+85)
	Field2271   byte     // 2271 (+86)
	Field2272   byte     // 2272 (+87)
	Field2273   byte     // 2273 (+88)
	nameSuff    [8]byte  // 2274 (+89)
}

func (p *PlayerInfo) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return player.Class(p.playerClass)
}

func (p *PlayerInfo) SetPlayerClass(v player.Class) {
	p.playerClass = byte(v)
}

func (p *PlayerInfo) IsFemale() bool {
	if p == nil {
		return false
	}
	return p.isFemale != 0
}

func (p *PlayerInfo) SetIsFemale(v byte) {
	p.isFemale = v
}

func (p *PlayerInfo) Name() string {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.name[0])), len(p.name)/2)
	return alloc.GoString16S(arr[:])
}

func (p *PlayerInfo) SetName(v string) {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.name[0])), len(p.name)/2)
	alloc.StrCopy16(arr, v)
}

func (p *PlayerInfo) NameSuff() string {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.nameSuff[0])), len(p.nameSuff)/2)
	return alloc.GoString16S(arr[:])
}

func (p *PlayerInfo) SetNameSuff(v string) {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.nameSuff[0])), len(p.nameSuff)/2)
	alloc.StrCopy16(arr, v)
}

func (p *PlayerInfo) Field2235() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2235))
}

func (p *PlayerInfo) Field2239() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2239))
}

func (p *PlayerInfo) Field2253() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2253))
}

func (p *PlayerInfo) Field2256() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2256))
}

func (p *PlayerInfo) Field2259() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2259))
}

func (p *PlayerInfo) Field2262() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2262))
}

func (p *PlayerInfo) Field2265() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2265))
}

func (p *PlayerInfo) SetField2235(v uint32) {
	*(*uint32)(unsafe.Pointer(&p.field2235)) = v
}

func (p *PlayerInfo) SetField2239(v uint32) {
	*(*uint32)(unsafe.Pointer(&p.field2239)) = v
}

func (p *PlayerInfo) SetField2253(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2253)) = v
}

func (p *PlayerInfo) SetField2256(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2256)) = v
}

func (p *PlayerInfo) SetField2259(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2259)) = v
}

func (p *PlayerInfo) SetField2262(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2262)) = v
}

func (p *PlayerInfo) SetField2265(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2265)) = v
}
