package opennox

import (
	"encoding/binary"
	"unicode/utf16"

	"github.com/noxworld-dev/opennox/v1/legacy"
)

func protectInt(v int) uint32 { // nox_xxx_protectionCreateInt_56F400
	if legacy.Nox_xxx_protectionCreateStructForInt_56F280(legacy.Get_dword_5d4594_2516356(), v) != 0 {
		cur := uint32(legacy.Get_dword_5d4594_2516356())
		legacy.Inc_dword_5d4594_2516356()
		return cur
	}
	return 0
}

func protectFloat32(v float32) uint32 { // nox_xxx_protectionCreateFloat_56F440
	if legacy.Nox_xxx_protectionCreateStructForFloat_56F480(legacy.Get_dword_5d4594_2516356(), v) != 0 {
		cur := uint32(legacy.Get_dword_5d4594_2516356())
		legacy.Inc_dword_5d4594_2516356()
		return cur
	}
	return 0
}

func protectUint16(v uint16) uint32 {
	return protectInt(int(v))
}

func protectUint32(v uint32) uint32 {
	return protectInt(int(v))
}

func protectBytes(data []byte) uint32 { // nox_xxx_protectionStringCRC_56FAC0 or nox_xxx_protectionStringCRCLen_56FAE0
	var res uint32
	for i := 0; i+4 <= len(data); i += 4 {
		res ^= binary.LittleEndian.Uint32(data[i:])
	}
	return res
}

func protectStr(str string) uint32 {
	return protectBytes([]byte(str))
}

func protectWStr(str string) uint32 {
	out := utf16.Encode([]rune(str))
	data := make([]byte, 2*len(out))
	for i, v := range out {
		binary.LittleEndian.PutUint16(data[2*i:], v)
	}
	return protectBytes(data)
}
