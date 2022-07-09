package opennox

func abs(v int) int {
	if v < 0 {
		return -v
	}
	return v
}

func bool2int(v bool) int {
	if v {
		return 1
	}
	return 0
}

func rotl(value uint32, shift int) uint32 {
	c := uint32(shift) & 31
	if c == 0 {
		return value
	}
	return (value << c) | (value >> (32 - c))
}

func rotl16(x uint16, shift int) uint16 {
	if shift == 0 {
		return x
	}
	if shift == 16 {
		return x
	}
	return (x << shift) | (x >> (16 - shift))
}
