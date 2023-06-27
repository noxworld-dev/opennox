package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_57AF30(a1 unsafe.Pointer, a2 uint32) {
	if dword_5d4594_2523804 == 1 || nox_xxx_checkGameFlagPause_413A50() != 0 {
		return
	}
	v2 := a1
	if a1 != nil {
		dword_5d4594_2523780 = a1
	} else {
		v2 = dword_5d4594_2523780
	}
	var v3 *server.Object
	if a2 != 0 {
		if a2 != 1 {
			v3 = dword_5d4594_2523776
		} else {
			v3 = nox_xxx_newObjectByTypeID_4E3810(internCStr("OblivionUp"))
			v2 = dword_5d4594_2523780
			dword_5d4594_2523776 = v3
		}
	} else {
		v3 = nox_xxx_newObjectByTypeID_4E3810(internCStr("LevelUp"))
		v2 = dword_5d4594_2523780
		dword_5d4594_2523776 = v3
	}
	if v3 != nil {
		if v2 != nil {
			nox_xxx_createAt_4DAA50(v3, nil, *(*float32)(unsafe.Add(v2, 56)), *(*float32)(unsafe.Add(v2, 60)))
		} else {
			nox_xxx_objectFreeMem_4E38A0(v3)
			dword_5d4594_2523776 = nil
		}
		v2 = dword_5d4594_2523780
	}
	if (a2 == 0 || a2 == 1) && v2 != nil {
		nox_xxx_netSendPointFx_522FF0(-102, (*types.Pointf)(unsafe.Add(v2, 56)))
		v2 = dword_5d4594_2523780
	}
	if a2 == 0 {
		if v2 == nil {
			goto LABEL_29
		}
		nox_xxx_aud_501960(902, (*server.Object)(v2), 2, int32(*(*uint32)(unsafe.Add(v2, 36))))
		v4 := nox_strman_loadString_40F1D0(internCStr("expLevel.c:LevelUP"), nil, internCStr("C:\\NoxPost\\src\\common\\GameMech\\PauseFX.c"), 109)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(dword_5d4594_2523780), v4)
		v2 = dword_5d4594_2523780
	}
	if v2 != nil {
		v5 := *(*unsafe.Pointer)(unsafe.Add(v2, 748))
		if nox_xxx_playerSetState_4FA020((*server.Object)(v2), 30) == 1 {
			*(*uint8)(unsafe.Add(v5, 236)) = 4
		}
	}
	if a2 != 0 {
		*memmap.PtrUint32(0x5D4594, 2523796) = 0
		if a2 != 1 {
			goto LABEL_30
		}
	}
LABEL_29:
	*memmap.PtrUint32(0x5D4594, 2523796) = 5000
LABEL_30:
	*memmap.PtrUint32(0x5D4594, 2523800) = 0
	*memmap.PtrUint32(0x5D4594, 2523772) = uint32(a2)
	dword_5d4594_2523804 = 1
	sub_413A00(1)
	*memmap.PtrUint64(0x5D4594, 2523788) = uint64(nox_platform_get_ticks())
}
