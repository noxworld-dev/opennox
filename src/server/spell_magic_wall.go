package server

type MagicWall struct {
	Field0  uint32     // 0, 0
	Field4  byte       // 1, 4
	Field5  byte       // 1, 5
	Field6  uint16     // 1, 6
	Field8  *Wall      // 2, 8
	Field12 byte       // 3, 12
	Field13 byte       // 3, 13
	Field14 byte       // 3, 14
	Field15 byte       // 3, 15
	Field16 uint32     // 4, 16
	Field20 *DurSpell  // 5, 20
	Field24 *MagicWall // 6, 24
	Field28 *MagicWall // 7, 28
}

type MagicWallSave struct {
	X       byte // 1569764 + 0
	Y       byte // 1569764 + 1
	_       [2]byte
	Field0  uint32 // 1569764 + 4
	Field12 byte   // 1569764 + 8
	Field13 byte   // 1569764 + 9
	Field14 byte   // 1569764 + 10
	Tile1   byte   // 1569764 + 11
	Field2  byte   // 1569764 + 12
	Dir     byte   // 1569764 + 13
	Health  byte   // 1569764 + 14
}
