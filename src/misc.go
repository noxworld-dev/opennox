package opennox

type number interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64 |
		~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 |
		~uintptr | ~float64 | ~float32
}

func abs[T number](v T) T {
	if v < 0 {
		return -v
	}
	return v
}

func clamp[T number](v, min, max T) T {
	if v < min {
		v = min
	} else if v > max {
		v = max
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

func swap4(p []byte) {
	p[0], p[1], p[2], p[3] = p[3], p[2], p[1], p[0]
}

func find[T comparable](arr []T, v T) int {
	for i, v2 := range arr {
		if v == v2 {
			return i
		}
	}
	return -1
}

type Point32 struct {
	X, Y int32
}
