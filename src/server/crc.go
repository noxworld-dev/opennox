package server

import "encoding/binary"

func protectBytes(data []byte) uint32 {
	var res uint32
	for i := 0; i+4 <= len(data); i += 4 {
		res ^= binary.LittleEndian.Uint32(data[i:])
	}
	return res
}
