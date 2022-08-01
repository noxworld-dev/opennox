package opennox

/*
#include <stdint.h>
extern uint32_t dword_5d4594_1599064;
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
int nox_xxx_utilFindSound_40AF50(char* a1);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func clientPlaySoundSpecial(snd sound.ID, a2 int) {
	C.nox_xxx_clientPlaySoundSpecial_452D80(C.int(snd), C.int(a2))
}

//export nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *C.char) C.int {
	return C.int(sound.ByName(GoString(name)))
}

//export nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id C.int) *C.char {
	return internCStr(sound.ID(id).String())
}

func nox_thing_read_audio_502320(f *MemFile) bool {
	n := int(f.ReadU32())
	if n <= 0 {
		return true
	}
	for i := 0; i < n; i++ {
		if !nox_thing_read_audio_one(f) {
			return false
		}
	}
	return false
}

func nox_thing_read_audio_one(f *MemFile) bool {
	name, err := f.ReadString8()
	if err != nil {
		return false
	}
	snd := sound.ByName(name)
	if snd == 0 || C.dword_5d4594_1599064 == 0 {
		f.Skip(9)
		for {
			n := int(f.ReadU8())
			if n == 0 {
				break
			}
			f.Skip(n)
		}
		return true
	}
	v6 := f.ReadU16()
	v7 := f.ReadU8()
	v8 := f.ReadI16()
	v17 := f.ReadU8()
	f.Skip(3)
	if v8 > 0 {
		*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+0) = 15 * uint32(v8)
	}
	*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+4) = uint32(v6)
	*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+8) = uint32(v7)
	*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+20) = uint32(v17)
	for {
		n := int(f.ReadU8())
		if n == 0 {
			break
		}
		f.Skip(n)
		*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+12)++
	}
	*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+16) = 2
	return true
}

func nox_thing_read_AVNT_502120(f *MemFile) bool {
	upd := C.dword_5d4594_1599064 != 0
	name, err := f.ReadString8()
	if err != nil {
		return false
	}
	snd := sound.ByName(name)
	if snd == 0 {
		upd = false
	}
	for {
		typ := f.ReadU8()
		if typ == 0 {
			return true
		}
		switch typ {
		case 1, 5:
			f.Skip(1)
		case 2:
			v := f.ReadU8()
			if upd {
				*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+16) = uint32(v)
			}
		case 3:
			v := f.ReadU8()
			if upd {
				*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+8) = uint32(v)
			}
		case 4:
			v := f.ReadU8()
			if upd {
				*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+20) = uint32(v)
			}
		case 6:
			f.Skip(2)
		case 7:
			for {
				n := f.ReadU8()
				if n == 0 {
					break
				}
				f.Skip(int(n))
				*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+12)++
			}
		case 8:
			f.Skip(8)
		case 9:
			v := f.ReadU16()
			if upd {
				*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+0) = 15 * uint32(v)
			}
		case 10:
			v := f.ReadU16()
			if upd {
				*memmap.PtrUint32(0x5D4594, 1570284+28*uintptr(snd)+4) = uint32(v)
			}
		default:
			return false
		}
	}
}
