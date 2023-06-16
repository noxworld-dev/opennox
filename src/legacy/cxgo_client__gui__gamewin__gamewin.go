package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_clientPickup_46C140(a1p *client.Drawable) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v2 int32
		v3 *wchar2_t
		v4 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1064928) == 0 {
		*memmap.PtrUint32(0x5D4594, 1064928) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Gold")))
		*memmap.PtrUint32(0x5D4594, 1064932) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("QuestGoldPile")))
		*memmap.PtrUint32(0x5D4594, 1064936) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("QuestGoldChest")))
	}
	if a1 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 108)))
		if uint32(v2) == *memmap.PtrUint32(0x5D4594, 1064928) || uint32(v2) == *memmap.PtrUint32(0x5D4594, 1064932) || uint32(v2) == *memmap.PtrUint32(0x5D4594, 1064936) || sub_467B00(v2, 1) != 0 {
			*((*uint8)(unsafe.Pointer(&v4))) = 115
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), 1)) = uint16(nox_xxx_netGetUnitCodeCli_578B00(a1))
			nox_netlist_addToMsgListCli_40EBC0(31, 0, (*uint8)(unsafe.Pointer(&v4)), 3)
		} else {
			nox_xxx_clientPlaySoundSpecial_452D80(925, 100)
			v3 = nox_strman_loadString_40F1D0(internCStr("pickup.c:CarryingTooMuch"), nil, internCStr("C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c"), 83)
			nox_xxx_printCentered_445490(v3)
		}
	}
}
