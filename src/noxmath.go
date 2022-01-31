package nox

import (
	"math"

	"nox/v1/common/types"
)

func nox_xxx_math_509ED0(p types.Pointf) int32 {
	v := int32((math.Atan2(float64(p.Y), float64(p.X))+6.2831855)*40.743664 + 0.5)
	return nox_xxx_math_roundDir(v)
}

func nox_xxx_math_roundDir(v int32) int32 {
	if v < 0 {
		v += int32(uint32(255-v) >> 8 << 8)
	}
	if v >= 256 {
		v -= int32(uint32(v) >> 8 << 8)
	}
	return v
}

func nox_xxx_math_roundDirI16(v int16) uint16 {
	if v < 0 {
		v += int16((uint32(255-v) >> 8) << 8)
	}
	if v >= 256 {
		v -= int16((uint32(v) >> 8) << 8)
	}
	return uint16(v)
}
