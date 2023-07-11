package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
)

func nox_client_handlePacketInform_4C9BF0(a1 unsafe.Pointer) int32 {
	var (
		result int32
		v2     *wchar2_t
		v3     *wchar2_t
		v4     *wchar2_t
		v5     *wchar2_t
		v6     *wchar2_t
		v7     *byte
		v8     *wchar2_t
		v9     *wchar2_t
		v10    *wchar2_t
		v11    *wchar2_t
		v12    *wchar2_t
		v13    *byte
		v14    *wchar2_t
		v15    *byte
		v16    *wchar2_t
		v17    *wchar2_t
		v18    *byte
		v19    *wchar2_t
		v20    *byte
		v21    *wchar2_t
		v22    *byte
		v23    *wchar2_t
		v24    *byte
		v25    *wchar2_t
		v26    *byte
		v27    *wchar2_t
		v28    *wchar2_t
		v29    *wchar2_t
		v30    *byte
		v31    *byte
		v32    *wchar2_t
		v33    *wchar2_t
		v34    *byte
		v35    *byte
		v36    *wchar2_t
		v37    *wchar2_t
		v38    *byte
		v39    *byte
		v40    *wchar2_t
		v41    *wchar2_t
		v42    uint32
		v43    *wchar2_t
		v44    *wchar2_t
		v45    *wchar2_t
		v46    int32
		v47    *wchar2_t
		v48    int32
		v49    *wchar2_t
		v50    int32
		v51    int32
		v52    int32
		v53    *wchar2_t
		v54    *wchar2_t
		v55    *wchar2_t
		v56    *wchar2_t
		v57    int32
		v58    int32
		v59    int32
		v60    *byte
		v61    *byte
		v62    [256]wchar2_t
		v63    [256]wchar2_t
	)
	result = 0
	switch *(*uint8)(unsafe.Add(a1, 1)) {
	case 0:
		nox_xxx_abilGetError_4FB0B0_magic_plyrspel(int32(*(*uint32)(unsafe.Add(a1, 2))))
		return 6
	case 1:
		v50 = int32(uintptr(unsafe.Pointer(nox_xxx_spellTitle_424930(int32(*(*uint32)(unsafe.Add(a1, 2)))))))
		v10 = nox_strman_loadString_40F1D0(internCStr("plyrspel.c:SpellCastSuccess"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 117)
		nox_swprintf(&v62[0], v10, v50)
		nox_xxx_printCentered_445490(&v62[0])
		return 6
	case 2:
		nox_xxx_abilGetSuccess_4FB960_ability(int32(*(*uint32)(unsafe.Add(a1, 2))))
		return 6
	case 3:
		v13 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v13 == nil {
			return 6
		}
		v51 = int32(uintptr(unsafe.Add(unsafe.Pointer(v13), 4704)))
		v14 = nox_strman_loadString_40F1D0(internCStr("netserv.c:PlayerTimeout"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 147)
		nox_swprintf(&v62[0], v14, v51)
		nox_xxx_printCentered_445490(&v62[0])
		return 6
	case 4:
		v15 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v15 == nil {
			return 6
		}
		v52 = int32(uintptr(unsafe.Add(unsafe.Pointer(v15), 4704)))
		v16 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:FlagRetrieveNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 164)
		nox_swprintf(&v62[0], v16, v52)
		nox_xxx_printCentered_445490(&v62[0])
		nox_xxx_clientPlaySoundSpecial_452D80(305, 100)
		return 6
	case 5:
		v18 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v18 == nil {
			return 10
		}
		v54 = nox_server_teamTitle_418C20(int32(*(*uint32)(unsafe.Add(a1, 6))))
		v19 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:FlagCaptureNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 196)
		nox_swprintf(&v62[0], v19, (*byte)(unsafe.Add(unsafe.Pointer(v18), 4704)), v54)
		nox_xxx_printCentered_445490(&v62[0])
		nox_xxx_clientPlaySoundSpecial_452D80(306, 100)
		return 10
	case 6:
		v20 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v20 == nil {
			return 10
		}
		v55 = nox_server_teamTitle_418C20(int32(*(*uint32)(unsafe.Add(a1, 6))))
		v21 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:FlagPickupNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 213)
		nox_swprintf(&v62[0], v21, (*byte)(unsafe.Add(unsafe.Pointer(v20), 4704)), v55)
		nox_xxx_printCentered_445490(&v62[0])
		nox_xxx_clientPlaySoundSpecial_452D80(303, 100)
		return 10
	case 7:
		v22 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v22 != nil {
			v56 = nox_server_teamTitle_418C20(int32(*(*uint32)(unsafe.Add(a1, 6))))
			v23 = nox_strman_loadString_40F1D0(internCStr("drop.c:FlagDropNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 230)
			nox_swprintf(&v62[0], v23, (*byte)(unsafe.Add(unsafe.Pointer(v22), 4704)), v56)
			nox_xxx_printCentered_445490(&v62[0])
			nox_xxx_clientPlaySoundSpecial_452D80(304, 100)
		}
		return 10
	case 8:
		v53 = nox_server_teamTitle_418C20(int32(*(*uint32)(unsafe.Add(a1, 2))))
		v17 = nox_strman_loadString_40F1D0(internCStr("update.c:FlagRespawnNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 179)
		nox_swprintf(&v62[0], v17, v53)
		nox_xxx_printCentered_445490(&v62[0])
		nox_xxx_clientPlaySoundSpecial_452D80(305, 100)
		return 6
	case 9:
		v38 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(a1, 6))))))
		v39 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v39 == nil {
			if v38 == nil {
				return 10
			}
			v41 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:FlagBallUnknownNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 374)
			nox_swprintf(&v62[0], v41, v38)
			nox_xxx_printCentered_445490(&v62[0])
			return 10
		}
		if v38 == nil {
			return 10
		}
		v46 = int32(uintptr(unsafe.Add(unsafe.Pointer(v39), 4704)))
		v40 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:FlagBallNotice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 365)
		nox_swprintf(&v62[0], v40, v46, v38)
		nox_xxx_printCentered_445490(&v62[0])
		return 10
	case 0xA:
		v34 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		v35 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(a1, 6))))))
		if v35 != nil {
			if v34 == nil {
				return 10
			}
			v61 = v35
			v36 = nox_strman_loadString_40F1D0(internCStr("pickup.c:PickUpTeamCrown"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 334)
			nox_swprintf(&v62[0], v36, (*byte)(unsafe.Add(unsafe.Pointer(v34), 4704)), v61)
			nox_xxx_printCentered_445490(&v62[0])
			result = 10
		} else {
			if v34 == nil {
				return 10
			}
			v37 = nox_strman_loadString_40F1D0(internCStr("pickup.c:PickUpCrown"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 343)
			nox_swprintf(&v62[0], v37, (*byte)(unsafe.Add(unsafe.Pointer(v34), 4704)))
			nox_xxx_printCentered_445490(&v62[0])
			result = 10
		}
		return result
	case 0xB:
		v30 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		v31 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(a1, 6))))))
		if v31 != nil {
			if v30 != nil {
				v60 = v31
				v32 = nox_strman_loadString_40F1D0(internCStr("drop.c:DropTeamCrown"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 303)
				nox_swprintf(&v62[0], v32, (*byte)(unsafe.Add(unsafe.Pointer(v30), 4704)), v60)
				nox_xxx_printCentered_445490(&v62[0])
				return 10
			}
		} else if v30 != nil {
			v33 = nox_strman_loadString_40F1D0(internCStr("drop.c:DropCrown"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 312)
			nox_swprintf(&v62[0], v33, (*byte)(unsafe.Add(unsafe.Pointer(v30), 4704)))
			nox_xxx_printCentered_445490(&v62[0])
			return 10
		}
		return 10
	case 0xC:
		v11 = nox_strman_loadString_40F1D0(internCStr("Netserv.c:InObservationMode"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 128)
		nox_xxx_printCentered_445490(v11)
		if *(*uint32)(unsafe.Add(a1, 2)) == 0 {
			return 6
		}
		v12 = nox_strman_loadString_40F1D0(internCStr("Netserv.c:PressJump"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 132)
		nox_xxx_printCentered_445490(v12)
		return 6
	case 0xD:
		switch *(*uint32)(unsafe.Add(a1, 2)) {
		case 0:
			v2 = nox_strman_loadString_40F1D0(internCStr("atckexec.c:PlayerStunned"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 27)
			nox_xxx_printCentered_445490(v2)
			result = 6
		case 1:
			v3 = nox_strman_loadString_40F1D0(internCStr("atckexec.c:PlayerConfused"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 31)
			nox_xxx_printCentered_445490(v3)
			result = 6
		case 2:
			v4 = nox_strman_loadString_40F1D0(internCStr("atckexec.c:PlayerPoisoned"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 35)
			nox_xxx_printCentered_445490(v4)
			result = 6
		case 3:
			v5 = nox_strman_loadString_40F1D0(internCStr("player.c:TooHeavy"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 39)
			nox_xxx_printCentered_445490(v5)
			result = 6
		default:
			return 6
		}
		return result
	case 0xE:
		sub_495210(a1)
		return 11
	case 0xF:
		v42 = uint32(libc.StrLen((*byte)(unsafe.Add(a1, 3))) + 1)
		if nox_xxx_gameGetPlayState_4356B0() != 3 {
			return int32(v42 + 3)
		}
		if int32(*(*uint8)(unsafe.Add(a1, 2))) != 0 {
			v47 = nox_strman_loadString_40F1D0((*byte)(unsafe.Add(a1, 3)), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 397)
			v43 = nox_strman_loadString_40F1D0(internCStr("use.c:SignSays"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 396)
			nox_swprintf(&v63[0], v43, v47)
			nox_xxx_printCentered_445490(&v63[0])
			return int32(v42 + 3)
		}
		v44 = nox_strman_loadString_40F1D0((*byte)(unsafe.Add(a1, 3)), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 402)
		nox_xxx_printCentered_445490(v44)
		return int32(v42 + 3)
	case 0x10:
		v49 = nox_server_teamTitle_418C20(int32(*(*uint32)(unsafe.Add(a1, 2))))
		v9 = nox_strman_loadString_40F1D0(internCStr("pickup.c:WrongTeam"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 105)
		nox_swprintf(&v62[0], v9, v49)
		nox_xxx_printCentered_445490(&v62[0])
		return 6
	case 0x11:
		v45 = nox_strman_loadString_40F1D0(internCStr("Noxworld.c:ErrChangedClass"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 51)
		v6 = nox_strman_loadString_40F1D0(internCStr("guiserv.c:Notice"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 50)
		nox_xxx_dialogMsgBoxCreate_449A10(nil, v6, v45, 33, nil, nil)
		return 2
	case 0x12:
		v24 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v24 == nil {
			return 6
		}
		v57 = int32(uintptr(unsafe.Add(unsafe.Pointer(v24), 4704)))
		v25 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:PlayerExited"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 247)
		nox_swprintf(&v62[0], v25, v57)
		nox_xxx_printCentered_445490(&v62[0])
		return 6
	case 0x13:
		v26 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v26 != nil {
			v58 = int32(uintptr(unsafe.Add(unsafe.Pointer(v26), 4704)))
			v27 = nox_strman_loadString_40F1D0(internCStr("objcoll.c:PlayerExitedWarp"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 265)
			nox_swprintf(&v62[0], v27, v58)
			nox_xxx_printCentered_445490(&v62[0])
		}
		return 6
	case 0x14:
		v7 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Add(a1, 2))))))
		if v7 == nil {
			return 6
		}
		v48 = int32(uintptr(unsafe.Add(unsafe.Pointer(v7), 4704)))
		v8 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:SecretFoundOther"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 90)
		nox_swprintf(&v62[0], v8, v48)
		nox_xxx_printCentered_445490(&v62[0])
		return 6
	case 0x15:
		v59 = int32(*(*uint32)(unsafe.Add(a1, 2)))
		v28 = nox_strman_loadString_40F1D0(internCStr("GeneralPrint:AdvanceToStage1"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 281)
		nox_swprintf(&v62[0], v28, v59)
		v29 = nox_strman_loadString_40F1D0(internCStr("use.c:SignSays"), nil, internCStr("C:\\NoxPost\\src\\client\\Network\\inform.c"), 282)
		nox_swprintf(&v63[0], v29, &v62[0])
		nox_xxx_printCentered_445490(&v63[0])
		return 6
	default:
		return result
	}
}
