package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

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
		a2  = a2p
		v10 *wchar2_t
		v11 *wchar2_t
		v12 int16
		v13 int32
		v16 *wchar2_t
		v17 *wchar2_t
		v21 [3]int32
		v22 int16
	)
	var v24 [128]wchar2_t
	if dword_5d4594_527660 == 0 {
		dword_5d4594_527660 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
	}
	if a2 == nil {
		return
	}
	v6 := nox_xxx_getTeamByID_418AB0(int32(a1))
	if v6 != nil {
		if nox_xxx_teamCompare2_419180((*server.ObjectTeam)(a2), a1) != 0 {
			return
		}
	} else {
		v6 = nox_xxx_teamCreate_4186D0(int8(a1))
	}
	*(*uint8)(unsafe.Add(a2, 4)) = uint8(v6.IDVal)
	*(*uint32)(a2) = v6.Field44Val
	v6.Field44Val = uint32(a2)
	if uint32(a4) == nox_player_netCode_85319C {
		sub_455E70(uint8(v6.IDVal))
	}
	if noxflags.HasGame(1) {
		if noxflags.HasGame(0x2000) {
			v7 := nox_server_getObjectFromNetCode_4ECCB0(uint32(a4))
			v8 := nox_common_playerInfoGetByID_417040(a4)
			v23 := v8
			if v8 != nil {
				if noxflags.HasGame(0x8000) {
					sub_425ED0(unsafe.Pointer(v8), 1)
				}
				if v7 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 8)))&4 != 0 {
					if a5 == 1 && !nox_xxx_CheckGameplayFlags_417DA0(2) && noxflags.HasGame(128) {
						sub_4ED970(50.0, (*types.Pointf)(unsafe.Add(v6.Field_72, 56)), (*types.Pointf)(unsafe.Pointer(&v21[0])))
						nox_xxx_unitMove_4E7010(v7, (*types.Pointf)(unsafe.Pointer(&v21[0])))
					}
					v9 := nox_common_playerInfoGetByID_417040(a4)
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
			if a3 != 0 && v7 != nil && (v8 != nil || uint32(v7.TypeInd) == dword_5d4594_527660) {
				v12 = int16(v7.TypeInd)
				v13 = int32(v6.IDVal)
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v21[0]), unsafe.Sizeof(uint16(0))*0)) = 452
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v21[1]), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(a4))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v21[0]), 2)) = uint32(v13)
				v22 = v12 // FIXME: should likely be a set on v21[2]
				sub_4571A0(a4, v13)
				nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v21[0]), 10, nil, 1)
				_ = v22
			}
		}
	} else {
		v14 := nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(a4))
		if v14 != nil && v14.Flags28Val&4 != 0 {
			v15 := nox_common_playerInfoGetByID_417040(a4)
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
	v6.Field48Val++
	r9 := nox_xxx_getFirstPlayerUnit_4DA7C0()
	v18 := r9
	if r9 == nil {
		return
	}
	for v18.NetCode != uint32(a4) {
		r9 = nox_xxx_getNextPlayerUnit_4DA7F0(v18)
		v18 = r9
		if r9 == nil {
			return
		}
	}
	v19 := v18.UpdateData
	sub_4D97E0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 276)), 2064))))
	sub_4E8110(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v19, 276)), 2064))))
	nox_xxx_monsterMarkUpdate_4E8020(v18)
	for i := v18.Field129; i != nil; i = i.Field128 {
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(i), 8)))&6 != 0 {
			nox_xxx_monsterMarkUpdate_4E8020(i)
		}
	}
}
