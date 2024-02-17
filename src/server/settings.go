package server

import "unsafe"

type Settings3 struct {
	Vals [5]uint32 // 0, 0
}

type Settings2 struct {
	Field0  [24]byte  // 0, 0
	Field24 Settings3 // 6, 24
	Field44 [4]byte   // 11, 44
	Field48 uint32    // 12, 48
	Field52 uint16    // 13, 52
	Field54 uint16    // 13, 54
	Field56 uint8     // 14, 56
	Field57 uint8     // 14, 57
}

type ServerFlags byte

func (f ServerFlags) Has(f2 ServerFlags) bool {
	return f&f2 != 0
}

const (
	ServerNoWarrior  = ServerFlags(0x1)
	ServerNoWizard   = ServerFlags(0x2)
	ServerNoConjurer = ServerFlags(0x4)
	ServerFlag3      = ServerFlags(0x8)
	ServerClosed     = ServerFlags(0x10)
	ServerPrivate    = ServerFlags(0x20)
	ServerFlag6      = ServerFlags(0x40)
	ServerFlag7      = ServerFlags(0x80)
)

const (
	ServerRestrictClasses = ServerNoWarrior | ServerNoWizard | ServerNoConjurer
)

type ServerFlags2 byte

func (f ServerFlags2) Has(f2 ServerFlags2) bool {
	return f&f2 != 0
}

const (
	Server2Flag0      = ServerFlags2(0x1)
	Server2Flag1      = ServerFlags2(0x2)
	Server2Flag2      = ServerFlags2(0x4)
	Server2Flag3      = ServerFlags2(0x8)
	Server2Flag4      = ServerFlags2(0x10)
	Server2Flag5      = ServerFlags2(0x20)
	Server2Flag6      = ServerFlags2(0x40)
	ServerLimitMaxRes = ServerFlags2(0x80)
)

type Settings struct {
	Field0                 uint32       // 0, 0
	Field4                 uint32       // 1, 4
	Field8                 uint32       // 2, 8
	Field12                uint32       // 3, 12
	Field16                uint32       // 4, 16
	Field20                uint32       // 5, 20
	Field24                uint32       // 6, 24
	Field28                uint32       // 7, 28
	Field32                uint32       // 8, 32
	Field36                uint32       // 9, 36
	Field40                uint32       // 10, 40
	Field44                uint32       // 11, 44
	Version48              uint32       // 12, 48
	Field52                byte         // 13, 52
	Field53                byte         // 13, 53
	Field54                [4]byte      // 13, 54
	PlayerSkeletons58      [4]byte      // 14, 58
	BroadcastGestures62    [4]byte      // 15, 62
	LatencyCompensationA66 [4]byte      // 16, 66
	LatencyCompensationB70 [4]byte      // 17, 70
	AudioThreshold         [4]byte      // 18, 74
	ServerPass78           [9]uint16    // 19, 78
	Field96                uint32       // 24, 96
	Flags100               ServerFlags  // 25, 100
	Field101               byte         // 25, 101
	Flags102               ServerFlags2 // 25, 102
	CurPlayers103          byte         // 25, 103
	MaxPlayers104          byte         // 26, 104
	RestrictedPingMind105  [2]byte      // 26, 105
	RestrictedPingMax107   [2]byte      // 26, 107
	Port109                [2]byte      // 27, 109
	settings2              [57]byte     // 27, 111; Settings2
}

func (d *Settings) Settings2() *Settings2 {
	return (*Settings2)(unsafe.Pointer(&d.settings2))
}
