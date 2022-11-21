package opennox

import "math"

func nox_xxx_math_roundDir(v int32) int32 {
	return int32(uint8(v))
}

func nox_xxx_math_roundDirI16(v int16) uint16 {
	return uint16(uint8(v))
}

func nox_xxx_roundCoord_5175E0(v float32) int32 {
	if float64(v) < 0.0 {
		return int32(v)
	}
	v = float32(float64(v)*0.011764706 + 8.388608e+06)
	return int32(math.Float32bits(v) & 0x7FFFFF)
}
