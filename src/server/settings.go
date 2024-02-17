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

type Settings struct {
	Field0        uint32    // 0, 0
	Field4        uint32    // 1, 4
	Field8        uint32    // 2, 8
	Field12       uint32    // 3, 12
	Field16       uint32    // 4, 16
	Field20       uint32    // 5, 20
	Field24       uint32    // 6, 24
	Field28       uint32    // 7, 28
	Field32       uint32    // 8, 32
	Field36       uint32    // 9, 36
	Field40       uint32    // 10, 40
	Field44       uint32    // 11, 44
	Version48     uint32    // 12, 48
	Field52       byte      // 13, 52
	Field53       byte      // 13, 53
	Field54       [4]byte   // 13, 54
	Field58       [4]byte   // 14, 58
	Field62       [4]byte   // 15, 62
	Field66       [4]byte   // 16, 66
	Field70       [4]byte   // 17, 70
	Field74       [4]byte   // 18, 74
	Field78       [8]uint16 // 19, 78
	Field94       uint16    // 23, 94
	Field96       uint32    // 24, 96
	Field100      byte      // 25, 100
	Field101      byte      // 25, 101
	Field102      byte      // 25, 102
	CurPlayers103 byte      // 25, 103
	MaxPlayers104 byte      // 26, 104
	Field105      [2]byte   // 26, 105
	Field107      [2]byte   // 26, 107
	Port109       [2]byte   // 27, 109
	field111      byte      // 27, 111; Settings2
	field111_2    [56]byte  // 28, 112
}

func (d *Settings) Field111() *Settings2 {
	return (*Settings2)(unsafe.Pointer(&d.field111))
}
