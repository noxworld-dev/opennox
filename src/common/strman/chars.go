package strman

import (
	"encoding/binary"
	"math"
)

func filterSpaces(b []uint16) []uint16 {
	out := b
	j := 0
	v4 := true
	prev := uint16(math.MaxUint16)
	for i := 0; i < len(b); i++ {
		c := b[i]
		if c == ' ' {
			if prev != ' ' && !v4 {
				prev = c
				out[j] = c
				j++
				v4 = false
			}
		} else if c == '\n' || c == '\t' {
			if prev == ' ' {
				j--
			}
			prev = c
			out[j] = c
			j++
			v4 = true
		} else {
			prev = c
			out[j] = c
			j++
			v4 = false
		}
	}
	if prev == ' ' {
		j--
	}
	return out[:j]
}

func bytes2utf16(b []byte) []uint16 {
	if len(b)%2 != 0 {
		panic("invalid size")
	}
	buf := make([]uint16, 0, len(b)/2)
	for i := 0; i < len(b); i += 2 {
		buf = append(buf, binary.LittleEndian.Uint16(b[i:]))
	}
	return buf
}

func invertUTF16(b []uint16) {
	for i, c := range b {
		b[i] = ^c
	}
}

func reverse4s(b []byte) string {
	return string([]byte{b[3], b[2], b[1], b[0]})
}
