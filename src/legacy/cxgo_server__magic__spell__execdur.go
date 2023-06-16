package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

func Sub_530A30_spell_execdur(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     *wchar2_t
		result int32
		v6     int32
		v7     float32
		v8     float32
		v9     int32
		v10    int32
		v11    float32
		v12    float4
	)
	v1 = a1
	v2 = 0
	if *(*uint32)(unsafe.Add(a1, 48)) == 0 {
		*(*uint32)(unsafe.Add(a1, 48)) = *(*uint32)(unsafe.Add(a1, 16))
	}
	v3 = int32(*(*uint32)(unsafe.Add(v1, 16)))
	if int32(*(*uint8)(unsafe.Add(v3, 8)))&4 != 0 {
		v2 = int32(*(*uint32)(unsafe.Add(v3, 748)))
	}
	if nox_xxx_mapTileAllowTeleport_411A90((*types.Pointf)(unsafe.Add(v1, 52))) != 0 {
		v4 = nox_strman_loadString_40F1D0(internCStr("UnseenTarget"), nil, internCStr("C:\\NoxPost\\src\\Server\\Magic\\Spell\\ExecDur.c"), 2912)
		nox_xxx_netSendLineMessage_4D9EB0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 48))), v4)
		nox_xxx_aud_501960(231, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 48))), 0, 0)
		result = 1
	} else {
		v6 = int32(*(*uint32)(unsafe.Add(v1, 48)))
		v12.field_0 = *(*float32)(unsafe.Add(v6, 56))
		v7 = *(*float32)(unsafe.Add(v1, 56))
		v8 = *(*float32)(unsafe.Add(v6, 60))
		v12.field_8 = *(*float32)(unsafe.Add(v1, 52))
		v9 = int32(*(*uint32)(unsafe.Add(v1, 16)))
		v12.field_4 = v8
		v12.field_C = v7
		if v9 == 0 || int32(uint8(int8(nox_xxx_traceRay_5374B0(&v12)))) != 0 {
			if noxflags.HasGame(2048) {
				v11 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("TeleportDelay"), int32(*(*uint32)(unsafe.Add(v1, 8))-1)))
				*(*uint32)(unsafe.Add(v1, 68)) = gameFrame() + uint32(int32(v11))
				result = 0
			} else {
				result = 0
				*(*uint32)(unsafe.Add(v1, 68)) = gameFrame() + 1
			}
		} else {
			if v2 != 0 {
				v10 = int32(*(*uint32)(unsafe.Add(v2, 276)))
				a1 = 2
				nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(v10, 2064))), 0, &a1)
			}
			result = 1
		}
	}
	return result
}
