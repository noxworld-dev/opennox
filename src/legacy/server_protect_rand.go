package legacy

import "math"

const (
	protectRandD = float64(2.111111111e+09) // 11352; ~ float64(0x7FFFFFFF)
	protectRandC = float64(1492)            // 11360
	protectRandB = float64(1776)            // 11368
	protectRandA = float64(5115)            // 11376
)

var (
	protectRandSize uint32      // dword_5d4594_2516372
	protectRandMax  uint32      // dword_5d4594_2516376
	protectRandMin  uint32      // dword_5d4594_2516380
	protectRandArr  [10]float64 // 0: 2516388, 1: 2516396, 2: 2516404, 3: 2516412, 4: 2516420; 5: 2516428, 6: 2516436, 7: 2516444, 8: 2516452, 9: 2516460
)

// TODO: figure out what this algorithm is based on

func protectRandReset(seed uint32) { // sub_56FF00
	val := seed
	if val == 0 {
		val = math.MaxUint32
	}
	for i := range protectRandArr {
		tmp := (((val << 13) ^ (val)) >> 17) ^ (val << 13) ^ (val)
		val = (tmp * 32) ^ tmp
		protectRandArr[i] = float64(val) / 0x100000000
	}
	i := 19
	for {
		_ = protectRandDouble()
		i--
		if i == 0 {
			break
		}
	}
	protectRandMin = 0
	protectRandMax = 99
	protectRandSize = 100
}

func protectRandUint(min uint32, max uint32) uint32 { // sub_56FF80
	size := max - min + 1
	protectRandMin = min
	protectRandMax = max
	protectRandSize = size
	val := min + uint32(protectRandDouble()*float64(size))
	if val >= max {
		return max
	}
	return val
}

func protectRandDouble() float64 { // nox_xxx_unkDoubleSmth_56FE30
	protectRandArr[3] = protectRandArr[2]
	protectRandArr[2] = protectRandArr[1]
	protectRandArr[1] = protectRandArr[0]
	val := protectRandArr[0]*protectRandA + protectRandArr[2]*protectRandB + protectRandArr[3]*protectRandC + protectRandArr[3]*protectRandD + protectRandArr[4]
	// TODO: had _ = math.Floor(v0)
	protectRandArr[0] = val - val
	protectRandArr[4] = val / 0x100000000
	return protectRandArr[0]
}
