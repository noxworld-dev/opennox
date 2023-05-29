package legacy

import (
	"unsafe"
)

func nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(a1 int32, data *uint8, dsz int32, v8p *nox_playerInfo, unitp *nox_object_t, v10p unsafe.Pointer) int32 {
	var (
		v8   int32  = int32(uintptr(unsafe.Pointer(v8p)))
		unit int32  = int32(uintptr(unsafe.Pointer(unitp)))
		v10  *int32 = (*int32)(v10p)
		v85  int32  = int32(uintptr(unsafe.Pointer(v10)))
		v7   int32
		v11  *byte = nil
	)
	_ = v11
	var v14 int32
	var v15 int32
	var v16 int32
	var v17 int32
	var v18 int32
	var v19 int32
	var v20 int32
	var v21 uint16
	var v22 int32
	var v23 int32
	var v24 int32
	var v26 int32
	var v27 int32
	var v28 int32
	var v29 int32
	var v30 func(int32, int32, uint32)
	var v31 int32
	var v32 int32
	var v34 int32
	var v35 int32
	var v36 *int32
	var v37 int32
	var v38 *uint32
	var v39 int32
	var v40 int32
	var v57 int32
	_ = v57
	var v58 int32
	var v59 int32
	var v60 int32
	var v61 int32
	var v62 uint8
	var v63 *uint32
	var v64 int32
	var v65 int32
	var v66 int32
	var v67 int32
	var v68 *int32
	var v69 int32
	var v70 int32
	var v71 int32
	var v72 *uint32
	var v73 int32
	var v74 int32
	var v75 int32
	var v76 int32
	var v77 int32
	var v78 int32
	var v79 uint8
	var v80 int32
	var v81 int32
	var v82 uint32
	_ = v82
	var v83 float32
	var v84 float32
	var v88 [4]byte
	var v90 [6]byte
	_ = v90
	var v94 float2
	var op int32 = int32(*data)
	switch op {
	case 0x40:
		v84 = float32(float64(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 5))))))
		v83 = float32(float64(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))))
		nox_xxx_playerSetCustomWP_4F79A0(unit, *(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&v83))), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&v84))), 4*0)))
		return 7
	case 0x72:
		v19 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))))
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(v7 + 3680))))&3) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v85 + 280))) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v85 + 284))) == 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 16))))&2) == 0 {
			v20 = nox_xxx_equipedItemByCode_4F7920(unit, v19)
			if v20 != 0 {
				v21 = *(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 5))))
				v94.field_0 = float32(float64(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))))
				v94.field_4 = float32(float64(v21))
				nox_xxx_drop_4ED810(unit, v20, &v94.field_0)
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 7
	case 0x73:
		v22 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		if nox_xxx_gameGet_4DB1B0() == 0 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))))
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v7 + 3680))))&3) == 0 && (*(*uint32)(unsafe.Pointer(uintptr(v85 + 280)))) == 0 && (*(*uint32)(unsafe.Pointer(uintptr(v85 + 284)))) == 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 16))))&2) == 0 {
				v23 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(v22))))
				if v23 != 0 {
					v24 = 0
					for i := int32(nox_xxx_inventoryGetFirst_4E7980(unit)); i != 0; i = nox_xxx_inventoryGetNext_4E7990(i) {
						v24 += int32(*(*uint8)(unsafe.Pointer(uintptr(i + 488))))
					}
					if v24+int32(*(*uint8)(unsafe.Pointer(uintptr(v23 + 488)))) <= int32(*(*uint16)(unsafe.Pointer(uintptr(unit + 490)))) {
						OnLibraryNotice_420(uint32(unit), uint32(v23), uint32(unit), uint32(v23))
					} else {
						nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), internCStr("pickup.c:CarryingTooMuch"), 0)
					}
				}
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 3
	case 0x74:
		v26 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		if nox_xxx_gameGet_4DB1B0() == 0 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))))
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v7 + 3680)))) & 3) == 0 {
				v27 = nox_xxx_equipedItemByCode_4F7920(unit, v26)
				if v27 != 0 {
					nox_xxx_useByNetCode_53F8E0(unit, v27)
				}
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 3
	case 0x75:
		v15 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		if nox_xxx_gameGet_4DB1B0() == 0 {
			v7 = v85
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 3680)))) & 3) == 0 {
				v16 = nox_xxx_equipedItemByCode_4F7920(unit, v15)
				if v16 != 0 {
					nox_xxx_playerTryEquip_4F2F70((*nox_object_t)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(uintptr(v16))))
				}
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 3
	case 0x76:
		v17 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 3680)))) & 3) == 0 {
			v18 = nox_xxx_equipedItemByCode_4F7920(unit, v17)
			if v18 != 0 {
				v7 = v85
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v85 + 88)))) != 1 || *(*uint32)(unsafe.Pointer(uintptr(v18 + 8)))&0x1000000 == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(v18 + 12))))&8 == 0 {
					nox_xxx_playerTryDequip_4F2FB0((*uint32)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(uintptr(v18))))
				}
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 3
	case 0x78:
		v31 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		v7 = v85
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 3680)))) & 1) == 0 {
			if int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))) != 0 {
				v32 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(v31))))
				if v32 != 0 {
					nox_xxx_orderUnit_533900((*nox_object_t)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(uintptr(v32))), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
				}
			} else {
				nox_xxx_orderUnit_533900((*nox_object_t)(unsafe.Pointer(uintptr(unit))), nil, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 4
	case 0x79:
		v34 = 1
		if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 3680))))&1 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), internCStr("GeneralPrint:NoSpellWarningGeneral"), 0)
			v34 = 0
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 3680))))&2 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), internCStr("GeneralPrint:ConjureNoSpellWarning1"), 0)
			v34 = 0
		}
		if !nox_common_gameFlags_check_40A5C0(2048) {
			v35 = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 16))))
			if v35&0x4000 != 0 {
				v34 = 0
			}
		}
		if !nox_common_gameFlags_check_40A5C0(128) && v34 != 0 {
			v36 = (*int32)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))
			v37 = 0
			v38 = (*uint32)(unsafe.Add(unsafe.Pointer(data), 1))
			v39 = 5
			for v39 != 0 {
				if *v38 != 0 {
					v37++
				}
				v38 = (*uint32)(unsafe.Add(unsafe.Pointer(v38), 4*1))
				v39--
			}
			if (v37 != 1 || !nox_xxx_spellHasFlags_424A50(*v36, 32) || *(*uint32)(unsafe.Pointer(uintptr(v85 + 288))) == 0 || nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 288))))))) != 0 || nox_common_gameFlags_check_40A5C0(4096)) && nox_xxx_spellByBookInsert_4FE340(unit, (*int32)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), v37, 3, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 21)))) == 0 && v37 == 1 {
				v40 = 5
				for v40 != 0 {
					if *v36 != 0 {
						nox_xxx_netReportSpellStat_4D9630(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 2064)))), *v36, 0)
					}
					v36 = (*int32)(unsafe.Add(unsafe.Pointer(v36), 4*1))
					v40--
				}
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 22
	case 0x7B:
		v28 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		v7 = v85
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 3680))))&3) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v85 + 280))) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v85 + 284))) == 0 {
			v29 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(v28))))
			if v29 != 0 {
				v30 = *(*func(int32, int32, uint32))(unsafe.Pointer(uintptr(v29 + 696)))
				if v30 != nil {
					v30(v29, unit, 0)
				}
			}
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 3
	case 0xA5:
		*(*uint16)(unsafe.Pointer(uintptr(v8 + int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))*8 + 16))) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))
		*(*uint16)(unsafe.Pointer(uintptr(v8 + int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))*8 + 18))) = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*2)))
		v14 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))
		v7 = int32(*(*uint32)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 6)))))
		*(*uint32)(unsafe.Pointer(uintptr(v8 + v14*8 + 20))) = uint32(v7)
		return 10
	case 0xE0:
		v58 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		if int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))) != 0 {
			v59 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(v58))))
			sub_53AB90(unit, v59)
		} else {
			sub_53AB90(unit, 0)
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 3
	case 0xE2:
		v60 = nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))))
		}
		v61 = nox_xxx_equipedItemByCode_4F7920(unit, v60)
		if v61 != 0 || (func() int32 {
			v61 = sub_510DE0(unit, v60)
			return v61
		}()) != 0 || (func() int32 {
			v61 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(v60))))
			return v61
		}()) != 0 {
			v88[0] = 226
			*(*uint16)(unsafe.Pointer(&v88[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*nox_object_t)(unsafe.Pointer(uintptr(v61)))))
			v62 = *(*uint8)(unsafe.Add(unsafe.Pointer(data), 3))
			if int32(v62) == 1 {
				v88[3] = byte(**(**uint8)(unsafe.Pointer(uintptr(v61 + 736))))
			} else if int32(v62) == 2 {
				v88[3] = byte(int8(nox_xxx_guide_427010(*(**byte)(unsafe.Pointer(uintptr(v61 + 736))))))
			} else {
				v88[3] = byte(**(**uint8)(unsafe.Pointer(uintptr(v61 + 736))))
			}
			nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v85 + 276))) + 2064)))), unsafe.Pointer(&v88[0]), 4, 0, 1)
		}
		v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
		return 4
	case 0xEE:
		switch *(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)) {
		case 0:
			var c1 int32 = 0
			if nox_common_gameFlags_check_40A5C0(4096) {
				c1 = 3
			}
			sub_506870(c1, unit, (*wchar2_t)(unsafe.Add(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(data))), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 1:
			sub_506870(1, unit, (*wchar2_t)(unsafe.Add(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(data))), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 2:
			var c2 int32 = 0
			if nox_common_gameFlags_check_40A5C0(4096) {
				c2 = 3
			}
			sub_506C90(c2, unit, (*wchar2_t)(unsafe.Add(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(data))), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 3:
			sub_506C90(1, unit, (*wchar2_t)(unsafe.Add(unsafe.Pointer((*wchar2_t)(unsafe.Pointer(data))), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 4:
			sub_506870(2, unit, nil)
			return 2
		case 5:
			sub_506C90(2, unit, nil)
			return 2
		default:
			return -1
		}
		fallthrough
	case 0xC9:
		switch *(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)) {
		case 0xE:
			if *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70)) != 0 {
				sub_50F3A0((*uint32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))))))
			}
			return 2
		case 0xF:
			v67 = nox_xxx_packetDynamicUnitCode_578B40(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
			if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
			}
			v68 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_equipedItemByCode_4F7920(unit, v67))))
			if v68 != nil {
				v69 = int32(*(*uint32)(unsafe.Pointer(uintptr(v85 + 280))))
				if v69 != 0 {
					if nox_xxx_tradeP2PAddOffer2_50F820_trade(v69, unit, *(*float32)(unsafe.Pointer(&v68))) == 1 {
						sub_4ED0C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(v68)))
					}
				}
			}
			v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
			return 4
		case 0x10:
			v70 = nox_xxx_packetDynamicUnitCode_578B40(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
			if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(uint32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
			}
			v71 = int32(*(*uint32)(unsafe.Pointer(uintptr(v85 + 280))))
			if v71 != 0 {
				nox_xxx_tradeP2PAddOfferMB_50FE20(v71, v70)
			}
			v10 = (*int32)(unsafe.Pointer(uintptr(v85)))
			return 4
		case 0x11:
			v66 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v66 != 0 {
				nox_xxx_tradeAccept_50F5A0(v66, unit)
			}
			return 2
		case 0x12:
			if *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70)) != 0 {
				nox_xxx_shopExit_50F4C0((*uint32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))))))
			}
			return 2
		case 0x15:
			if nox_xxx_gameGet_4DB1B0() == 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*69)) + 3680))))&3) == 0 {
				v64 = nox_xxx_packetDynamicUnitCode_578B40(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
				v65 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(v64))))
				if v65 != 0 {
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v65 + 12))))&8 != 0 {
						nox_xxx_servShopStart_50EF10_trade(unit, v65)
					}
				}
			}
			return 4
		case 0x16:
			v72 = (*uint32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70)))))
			if v72 != nil {
				sub_5100C0_trade(unit, v72, int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
			}
			return 4
		case 0x17:
			v73 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v73 != 0 {
				sub_510640_trade(unit, v73, int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))), (*float32)(unsafe.Pointer(uintptr(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 4))))))
			}
			return 5
		case 0x18:
			v74 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v74 != 0 {
				sub_510BE0_trade((*int32)(unsafe.Pointer(uintptr(unit))), v74, (*uint32)(unsafe.Pointer(uintptr(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))))
			}
			return 4
		case 0x19:
			v76 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v76 != 0 {
				sub_510D10((*int32)(unsafe.Pointer(uintptr(unit))), v76, int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))), uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 4))))
			}
			return 5
		case 0x1A:
			v75 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v75 != 0 {
				sub_510AE0((*int32)(unsafe.Pointer(uintptr(unit))), v75, (*uint32)(unsafe.Pointer(uintptr(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))))
			}
			return 4
		case 0x1C:
			v77 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v77 != 0 {
				sub_5109C0_trade((*int32)(unsafe.Pointer(uintptr(unit))), v77, (*uint32)(unsafe.Pointer(uintptr(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))))
			}
			return 4
		case 0x1E:
			v78 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v78 != 0 {
				sub_5108D0(unit, v78, int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(data))), unsafe.Sizeof(uint16(0))*1)))))
			}
			return 4
		default:
			return -1
		}
		fallthrough
	case 0xF0:
		v79 = *(*uint8)(unsafe.Add(unsafe.Pointer(data), 1))
		if int32(v79) == 3 {
			v80 = *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*69))
			v81 = int32(*(*uint32)(unsafe.Pointer(uintptr(v80 + 2056))))
			if v81 != 0 {
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v81 + 16))))
				if (v7 & 0x8000) != 0 {
					*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*137)) = 0
					nox_xxx_playerRespawn_4F7EF0((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v80 + 2056)))))))
				}
			}
		} else {
			if int32(v79) != 27 {
				return -1
			}
			sub_4DD0B0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
		}
		return 2
	case 0xF1:
		v63 = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_equipedItemByCode_4F7920(unit, int32(*(*uint16)(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))))))))
		if v63 != nil {
			nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(v63)), (*float2)(unsafe.Pointer(uintptr(unit+56))))
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), internCStr("pickup.c:CarryingTooMuch"), 0)
		}
		return 3
	default:
		return -1
	}
}
