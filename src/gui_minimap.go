package opennox

/*
extern int dword_5d4594_3799524;
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/common/memmap"

//export sub_473670
func sub_473670() C.int {
	return C.int(memmap.Uint8(0x5D4594, 1096424) & 1)
}

//export nox_client_toggleMap_473610
func nox_client_toggleMap_473610() C.char {
	if nox_xxx_guiCursor_477600() != 1 {
		if memmap.Uint8(0x5D4594, 1096424)&1 != 0 {
			clientPlaySoundSpecial(785, 100)
			*memmap.PtrUint32(0x5D4594, 1096424) &= 0xFFFFFFFE
		} else {
			clientPlaySoundSpecial(784, 100)
			*memmap.PtrUint32(0x5D4594, 1096424) |= 0x1
		}
		C.dword_5d4594_3799524 = 1
		return C.char(*memmap.PtrUint32(0x5D4594, 1096424))
	}
	return 0
}
