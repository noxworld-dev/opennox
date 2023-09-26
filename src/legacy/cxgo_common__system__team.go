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

func Nox_xxx_createAtImpl_4191D0(tid server.TeamID, otm *server.ObjectTeam, a3 bool, netcode uint32, a5 bool) {
	s := GetServer().S()
	var (
		v10 *wchar2_t
		v11 *wchar2_t
		v12 int16
		v13 int32
		v16 *wchar2_t
		v17 *wchar2_t
		v22 int16
	)
	var v24 [128]wchar2_t
	if dword_5d4594_527660 == 0 {
		dword_5d4594_527660 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
	}
	if otm == nil {
		return
	}
	tm := s.Teams.ByID(tid)
	if tm != nil {
		if nox_xxx_teamCompare2_419180(otm, tid) != 0 {
			return
		}
	} else {
		tm = s.Teams.Create(tid)
	}
	otm.ID = tm.IDVal
	otm.Field0 = tm.Field44Val
	tm.Field44Val = otm
	if netcode == nox_player_netCode_85319C {
		sub_455E70(tm.IDVal)
	}
	if noxflags.HasGame(noxflags.GameHost) {
		if noxflags.HasGame(noxflags.GameOnline) {
			v7 := nox_server_getObjectFromNetCode_4ECCB0(netcode)
			v8 := nox_common_playerInfoGetByID_417040(int32(netcode))
			v23 := v8
			if v8 != nil {
				if noxflags.HasGame(0x8000) {
					sub_425ED0(unsafe.Pointer(v8), 1)
				}
				if v7 != nil && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 8)))&4 != 0 {
					if a5 && !nox_xxx_CheckGameplayFlags_417DA0(2) && noxflags.HasGame(noxflags.GameModeChat) {
						var v21 types.Pointf
						sub_4ED970(50.0, (*types.Pointf)(unsafe.Add(tm.Field_72, 56)), &v21)
						nox_xxx_unitMove_4E7010(v7, &v21)
					}
					v9 := nox_common_playerInfoGetByID_417040(int32(netcode))
					if v9 != nil {
						if noxflags.HasGame(4096) {
							v10 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:PlayerJoinQuest"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1848)
							nox_swprintf(&v24[0], v10, (*byte)(unsafe.Add(unsafe.Pointer(v9), 4704)))
						} else {
							v11 = nox_strman_loadString_40F1D0(internCStr("NewMember"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1850)
							nox_swprintf(&v24[0], v11, (*byte)(unsafe.Add(unsafe.Pointer(v9), 4704)), tm)
						}
						nox_xxx_printCentered_445490(&v24[0])
					}
					v8 = v23
				}
			}
			if a3 && v7 != nil && (v8 != nil || uint32(v7.TypeInd) == dword_5d4594_527660) {
				v12 = int16(v7.TypeInd)
				v13 = int32(tm.IDVal)
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v21[0]), unsafe.Sizeof(uint16(0))*0)) = 452
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v21[1]), unsafe.Sizeof(uint16(0))*1)) = uint16(int16(netcode))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v21[0]), 2)) = uint32(v13)
				v22 = v12 // FIXME: should likely be a set on v21[2]
				sub_4571A0(int32(netcode), v13)
				nox_xxx_netSendPacket1_4E5390(159, unsafe.Pointer(&v21[0]), 10, nil, 1)
				_ = v22
			}
		}
	} else {
		v14 := nox_xxx_netSpriteByCodeDynamic_45A6F0(netcode)
		if v14 != nil && v14.Flags28Val&4 != 0 {
			v15 := nox_common_playerInfoGetByID_417040(int32(netcode))
			if v15 != nil {
				if noxflags.HasGame(4096) {
					v16 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:PlayerJoinQuest"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1889)
					nox_swprintf(&v24[0], v16, (*byte)(unsafe.Add(unsafe.Pointer(v15), 4704)))
				} else {
					v17 = nox_strman_loadString_40F1D0(internCStr("NewMember"), nil, internCStr("C:\\NoxPost\\src\\common\\System\\team.c"), 1891)
					nox_swprintf(&v24[0], v17, (*byte)(unsafe.Add(unsafe.Pointer(v15), 4704)), tm)
				}
				nox_xxx_printCentered_445490(&v24[0])
			}
		}
	}
	tm.Field48Val++
	for u := nox_xxx_getFirstPlayerUnit_4DA7C0(); u != nil; u = nox_xxx_getNextPlayerUnit_4DA7F0(u) {
		if u.NetCode == netcode {
			ud := u.UpdateDataPlayer()
			sub_4D97E0(int32(ud.Player.PlayerInd))
			sub_4E8110(int32(ud.Player.PlayerInd))
			nox_xxx_monsterMarkUpdate_4E8020(u)
			for it2 := u.Field129; it2 != nil; it2 = it2.Field128 {
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(it2), 8)))&6 != 0 {
					nox_xxx_monsterMarkUpdate_4E8020(it2)
				}
			}
			break
		}
	}
}
