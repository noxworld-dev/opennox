package legacy

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

type nox_team_info_t struct {
	name  *byte
	title *wchar2_t
	code  int32
	color *uint32
}

var nox_color_white_2523948 uint32 = 0
var nox_color_red_2589776 uint32 = 0
var nox_color_blue_2650684 uint32 = 0
var nox_color_green_2614268 uint32 = 0
var nox_color_cyan_2649820 uint32 = 0
var nox_color_yellow_2589772 uint32 = 0
var nox_color_violet_2598268 uint32 = 0
var nox_color_black_2650656 uint32 = 0
var nox_color_orange_2614256 uint32 = 0

func nox_xxx_createAtImpl_4191D0(a1 uint8, a2p unsafe.Pointer, a3 int32, a4 int32, a5 int32) {
	var (
		a2     int32 = int32(uintptr(a2p))
		result *byte
		v6     *byte
		v7     int32
		v8     *byte
		v9     *byte
		v10    *wchar2_t
		v11    *wchar2_t
		v12    int16
		v13    int32
		v14    *uint32
		v15    *byte
		v16    *wchar2_t
		v17    *wchar2_t
		v18    *byte
		v19    int32
		i      int32
		v21    [3]int32
		v22    int16
	)
	_ = v22
	var v23 *byte
	var v24 [128]wchar2_t
	result = *(**byte)(unsafe.Pointer(&dword_5d4594_527660))
	if dword_5d4594_527660 == 0 {
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))))
		dword_5d4594_527660 = uint32(uintptr(unsafe.Pointer(result)))
	}
	if a2 == 0 {
		return
	}
	v6 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(a1))))
	if v6 != nil {
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_teamCompare2_419180(unsafe.Pointer(uintptr(a2)), a1))))
		if result != nil {
			return
		}
	} else {
		v6 = (*byte)(unsafe.Pointer(nox_xxx_teamCreate_4186D0(int8(a1))))
	}
	*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a2)), 4)) = *(*byte)(unsafe.Add(unsafe.Pointer(v6), 57))
	*(*uint32)(unsafe.Pointer(uintptr(a2))) = *((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*11)))
	*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*11))) = uint32(a2)
	if uint32(a4) == nox_player_netCode_85319C {
		sub_455E70(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 57)))
	}
	if noxflags.HasGame(1) {
		if noxflags.HasGame(0x2000) {
			v7 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(a4))))
			v8 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(a4)))
			v23 = v8
			if v8 != nil {
				if noxflags.HasGame(0x8000) {
					sub_425ED0(int32(uintptr(unsafe.Pointer(v8))), 1)
				}
				if v7 != 0 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 8)))&4 != 0 {
					if a5 == 1 && !nox_xxx_CheckGameplayFlags_417DA0(2) && noxflags.HasGame(128) {
						sub_4ED970(50.0, (*float2)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*18))))), 56)), (*float2)(unsafe.Pointer(&v21[0])))
						nox_xxx_unitMove_4E7010((*server.Object)(unsafe.Pointer(uintptr(v7))), (*float2)(unsafe.Pointer(&v21[0])))
					}
					v9 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(a4)))
					if v9 != nil {
						if noxflags.HasGame(4096) {
							v10 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:PlayerJoinQuest"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1848)
							nox_swprintf(&v24[0], v10, (*byte)(unsafe.Add(unsafe.Pointer(v9), 4704)))
						} else {
							v11 = nox_strman_loadString_40F1D0(internCStr("NewMember"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1850)
							nox_swprintf(&v24[0], v11, (*byte)(unsafe.Add(unsafe.Pointer(v9), 4704)), v6)
						}
						nox_xxx_printCentered_445490(&v24[0])
					}
					v8 = v23
				}
			}
			if a3 != 0 && v7 != 0 && (v8 != nil || uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 4))) == dword_5d4594_527660) {
				v12 = int16(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v7)), 4)))
				v13 = int32(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 57)))
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v21[0]), unsafe.Sizeof(uint16(0))*0)) = 452
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v21[1]), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(a4))
				*(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer(&v21[0]), 2)))) = uint32(v13)
				v22 = v12
				sub_4571A0(a4, v13)
				nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v21[0]), 10, 0, 1)
			}
		}
	} else {
		v14 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(a4).C())
		if v14 != nil && *(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*28))&4 != 0 {
			v15 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(a4)))
			if v15 != nil {
				if noxflags.HasGame(4096) {
					v16 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:PlayerJoinQuest"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1889)
					nox_swprintf(&v24[0], v16, (*byte)(unsafe.Add(unsafe.Pointer(v15), 4704)))
				} else {
					v17 = nox_strman_loadString_40F1D0(internCStr("NewMember"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1891)
					nox_swprintf(&v24[0], v17, (*byte)(unsafe.Add(unsafe.Pointer(v15), 4704)), v6)
				}
				nox_xxx_printCentered_445490(&v24[0])
			}
		}
	}
	*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*12)))++
	result = (*byte)(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))
	v18 = result
	if result == nil {
		return
	}
	for *((*uint32)(unsafe.Add(unsafe.Pointer(v18), 4*9))) != uint32(a4) {
		result = (*byte)(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(unsafe.Pointer(v18)))))
		v18 = result
		if result == nil {
			return
		}
	}
	v19 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v18), 4*187))))
	sub_4D97E0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v19)), 276)))), 2064))))
	sub_4E8110(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v19)), 276)))), 2064))))
	result = nox_xxx_monsterMarkUpdate_4E8020((*server.Object)(unsafe.Pointer(v18)))
	for i = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v18), 4*129)))); i != 0; i = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(i)), 512))) {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(i)), 8)))&6 != 0 {
			result = nox_xxx_monsterMarkUpdate_4E8020((*server.Object)(unsafe.Pointer(uintptr(i))))
		}
	}
}
