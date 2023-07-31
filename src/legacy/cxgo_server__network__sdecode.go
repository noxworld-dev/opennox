package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(a1 int32, data *uint8, dsz int32, v8p *server.Player, unitp *server.Object, v10p unsafe.Pointer) int32 {
	v8 := unsafe.Pointer(v8p)
	unit := unitp
	v10 := (*int32)(v10p)
	v85 := unsafe.Pointer(v10)
	op := int32(*data)
	switch op {
	case 0x40:
		v84 := float32(float64(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))))
		v83 := float32(float64(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))
		nox_xxx_playerSetCustomWP_4F79A0(unit, *(*int32)(unsafe.Add(unsafe.Pointer(&v83), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer(&v84), 4*0)))
		return 7
	case 0x72:
		v19 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		v7 := *(*unsafe.Pointer)(unsafe.Add(v85, 276))
		if (int32(*(*uint8)(unsafe.Add(v7, 3680)))&3) == 0 && *(*uint32)(unsafe.Add(v85, 280)) == 0 && *(*uint32)(unsafe.Add(v85, 284)) == 0 && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(unit), 16)))&2) == 0 {
			v20 := nox_xxx_equipedItemByCode_4F7920(unit, v19)
			if v20 != nil {
				v21 := *(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))
				var v94 types.Pointf
				v94.X = float32(float64(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))
				v94.Y = float32(float64(v21))
				nox_xxx_drop_4ED810(unit, unsafe.Pointer(v20), &v94)
			}
		}
		return 7
	case 0x73:
		v22 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if nox_xxx_gameGet_4DB1B0() == 0 {
			v7 := *(*unsafe.Pointer)(unsafe.Add(v85, 276))
			if (int32(*(*uint8)(unsafe.Add(v7, 3680)))&3) == 0 && (*(*uint32)(unsafe.Add(v85, 280))) == 0 && (*(*uint32)(unsafe.Add(v85, 284))) == 0 && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(unit), 16)))&2) == 0 {
				v23 := int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(uint32(v22)))))
				if v23 != 0 {
					v24 := int32(0)
					for i := nox_xxx_inventoryGetFirst_4E7980(unit); i != nil; i = nox_xxx_inventoryGetNext_4E7990(i) {
						v24 += int32(i.Weight)
					}
					if v24+int32(*(*uint8)(unsafe.Add(v23, 488))) <= int32(unit.CarryCapacity) {
						OnLibraryNotice_420(unit, uint32(v23), unsafe.Pointer(unit), uint32(v23))
					} else {
						nox_xxx_netPriMsgToPlayer_4DA2C0(unit, internCStr("pickup.c:CarryingTooMuch"), 0)
					}
				}
			}
		}
		return 3
	case 0x74:
		v26 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if nox_xxx_gameGet_4DB1B0() == 0 {
			v7 := *(*unsafe.Pointer)(unsafe.Add(v85, 276))
			if (int32(*(*uint8)(unsafe.Add(v7, 3680))) & 3) == 0 {
				v27 := nox_xxx_equipedItemByCode_4F7920(unit, v26)
				if v27 != nil {
					nox_xxx_useByNetCode_53F8E0(unsafe.Pointer(unit), unsafe.Pointer(v27))
				}
			}
		}
		return 3
	case 0x75:
		v15 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if nox_xxx_gameGet_4DB1B0() == 0 {
			if (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 3680))) & 3) == 0 {
				v16 := nox_xxx_equipedItemByCode_4F7920(unit, v15)
				if v16 != nil {
					nox_xxx_playerTryEquip_4F2F70(unit, v16)
				}
			}
		}
		return 3
	case 0x76:
		v17 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 3680))) & 3) == 0 {
			v18 := nox_xxx_equipedItemByCode_4F7920(unit, v17)
			if v18 != nil {
				if int32(*(*uint8)(unsafe.Add(v85, 88))) != 1 || v18.ObjClass&0x1000000 == 0 || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v18), 12)))&8 == 0 {
					nox_xxx_playerTryDequip_4F2FB0(unit, v18)
				}
			}
		}
		return 3
	case 0x78:
		v31 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 3680))) & 1) == 0 {
			if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
				v32 := int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(uint32(v31)))))
				if v32 != 0 {
					nox_xxx_orderUnit_533900(unit, (*server.Object)(v32), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
				}
			} else {
				nox_xxx_orderUnit_533900(unit, nil, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
			}
		}
		return 4
	case 0x79:
		v34 := 1
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 3680)))&1 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(unit, internCStr("GeneralPrint:NoSpellWarningGeneral"), 0)
			v34 = 0
		}
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 3680)))&2 != 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0(unit, internCStr("GeneralPrint:ConjureNoSpellWarning1"), 0)
			v34 = 0
		}
		if !noxflags.HasGame(2048) {
			v35 := int32(unit.ObjFlags)
			if v35&0x4000 != 0 {
				v34 = 0
			}
		}
		if !noxflags.HasGame(128) && v34 != 0 {
			v36 := (*int32)(unsafe.Add(unsafe.Pointer(data), 1))
			v37 := int32(0)
			v38 := (*uint32)(unsafe.Add(unsafe.Pointer(data), 1))
			v39 := 5
			for v39 != 0 {
				if *v38 != 0 {
					v37++
				}
				v38 = (*uint32)(unsafe.Add(unsafe.Pointer(v38), 4*1))
				v39--
			}
			if (v37 != 1 || !nox_xxx_spellHasFlags_424A50(*v36, 32) || *(*uint32)(unsafe.Add(v85, 288)) == 0 || nox_xxx_unitIsEnemyTo_5330C0(unit, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v85, 288)))) != 0 || noxflags.HasGame(4096)) && nox_xxx_spellByBookInsert_4FE340(unsafe.Pointer(unit), (*int32)(unsafe.Add(unsafe.Pointer(data), 1)), v37, 3, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 21)))) == 0 && v37 == 1 {
				v40 := 5
				for v40 != 0 {
					if *v36 != 0 {
						nox_xxx_netReportSpellStat_4D9630(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 2064))), *v36, 0)
					}
					v36 = (*int32)(unsafe.Add(unsafe.Pointer(v36), 4*1))
					v40--
				}
			}
		}
		return 22
	case 0x7B:
		v28 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 3680)))&3) == 0 && *(*uint32)(unsafe.Add(v85, 280)) == 0 && *(*uint32)(unsafe.Add(v85, 284)) == 0 {
			v29p := nox_server_getObjectFromNetCode_4ECCB0(uint32(v28))
			if v29p != nil {
				if v30 := v29p.Collide.Get(); v30 != nil {
					v30(v29p, AsObjectP(unsafe.Pointer(unit)), nil)
				}
			}
		}
		return 3
	case 0xA5:
		*(*uint16)(unsafe.Add(unsafe.Add(v8, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))*8), 16)) = *((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))
		*(*uint16)(unsafe.Add(unsafe.Add(v8, int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))*8), 18)) = *((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*2)))
		v14 := int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))
		v7 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 6)))
		*(*uint32)(unsafe.Add(unsafe.Add(v8, v14*8), 20)) = uint32(v7)
		return 10
	case 0xE0:
		v58 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
			v59 := int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(uint32(v58)))))
			sub_53AB90(unsafe.Pointer(unit), v59)
		} else {
			sub_53AB90(unsafe.Pointer(unit), 0)
		}
		return 3
	case 0xE2:
		v60 := nox_xxx_packetDynamicUnitCode_578B40(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		v61 := nox_xxx_equipedItemByCode_4F7920(unit, v60)
		if v61 != nil || (func() unsafe.Pointer {
			v61 = (*server.Object)(sub_510DE0(unsafe.Pointer(unit), v60))
			return v61
		}()) != nil || (func() unsafe.Pointer {
			v61 = nox_server_getObjectFromNetCode_4ECCB0(uint32(v60))
			return v61
		}()) != nil {
			var v88 [4]byte
			v88[0] = 226
			*(*uint16)(unsafe.Pointer(&v88[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0(v61))
			v62 := *(*uint8)(unsafe.Add(unsafe.Pointer(data), 3))
			if int32(v62) == 1 {
				v88[3] = *v61.UseData
			} else if int32(v62) == 2 {
				v88[3] = byte(int8(nox_xxx_guide_427010((*byte)(v61.UseData))))
			} else {
				v88[3] = *v61.UseData
			}
			nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v85, 276)), 2064))), unsafe.Pointer(&v88[0]), 4, nil, 1)
		}
		return 4
	case 0xEE:
		switch *(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)) {
		case 0:
			var c1 int32 = 0
			if noxflags.HasGame(4096) {
				c1 = 3
			}
			sub_506870(c1, unsafe.Pointer(unit), (*wchar2_t)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 1:
			sub_506870(1, unsafe.Pointer(unit), (*wchar2_t)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 2:
			var c2 int32 = 0
			if noxflags.HasGame(4096) {
				c2 = 3
			}
			sub_506C90(c2, unsafe.Pointer(unit), (*wchar2_t)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 3:
			sub_506C90(1, unsafe.Pointer(unit), (*wchar2_t)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(wchar2_t(0))*1)))
			return 52
		case 4:
			sub_506870(2, unsafe.Pointer(unit), nil)
			return 2
		case 5:
			sub_506C90(2, unsafe.Pointer(unit), nil)
			return 2
		default:
			return -1
		}
	case 0xC9:
		switch *(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)) {
		case 0xE:
			if *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70)) != 0 {
				sub_50F3A0((*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))))
			}
			return 2
		case 0xF:
			v67 := nox_xxx_packetDynamicUnitCode_578B40(int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
			}
			v68 := (*int32)(nox_xxx_equipedItemByCode_4F7920(unit, v67))
			if v68 != nil {
				v69 := *(*unsafe.Pointer)(unsafe.Add(v85, 280))
				if v69 != nil {
					if nox_xxx_tradeP2PAddOffer2_50F820_trade(v69, unsafe.Pointer(unit), v68) == 1 {
						sub_4ED0C0(unit, (*server.Object)(unsafe.Pointer(v68)))
					}
				}
			}
			return 4
		case 0x10:
			v70 := nox_xxx_packetDynamicUnitCode_578B40(int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
			}
			v71 := *(*unsafe.Pointer)(unsafe.Add(v85, 280))
			if v71 != nil {
				nox_xxx_tradeP2PAddOfferMB_50FE20(v71, v70)
			}
			return 4
		case 0x11:
			v66 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v66 != nil {
				nox_xxx_tradeAccept_50F5A0(v66, unsafe.Pointer(unit))
			}
			return 2
		case 0x12:
			if *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*70)) != 0 {
				nox_xxx_shopExit_50F4C0((*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))))
			}
			return 2
		case 0x15:
			if nox_xxx_gameGet_4DB1B0() == 0 && (int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*69)), 3680)))&3) == 0 {
				v64 := nox_xxx_packetDynamicUnitCode_578B40(int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
				v65 := unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(uint32(v64)))
				if v65 != nil {
					if int32(*(*uint8)(unsafe.Add(v65, 12)))&8 != 0 {
						nox_xxx_servShopStart_50EF10_trade(unsafe.Pointer(unit), v65)
					}
				}
			}
			return 4
		case 0x16:
			v72 := (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70)))
			if v72 != nil {
				sub_5100C0_trade(unsafe.Pointer(unit), v72, int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
			}
			return 4
		case 0x17:
			v73 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v73 != nil {
				sub_510640_trade(unsafe.Pointer(unit), v73, int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))), (*float32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(data), 4))))
			}
			return 5
		case 0x18:
			v74 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v74 != nil {
				sub_510BE0_trade((*int32)(unit), v74, (*uint32)(unsafe.Pointer(uintptr(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))))
			}
			return 4
		case 0x19:
			v76 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v76 != nil {
				sub_510D10((*int32)(unit), v76, int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))), uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 4))))
			}
			return 5
		case 0x1A:
			v75 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v75 != nil {
				sub_510AE0((*int32)(unit), v75, (*uint32)(unsafe.Pointer(uintptr(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))))
			}
			return 4
		case 0x1C:
			v77 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v77 != nil {
				sub_5109C0_trade((*int32)(unit), v77, (*uint32)(unsafe.Pointer(uintptr(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))))
			}
			return 4
		case 0x1E:
			v78 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v10), 4*70))
			if v78 != nil {
				sub_5108D0(unsafe.Pointer(unit), v78, int32(*((*uint16)(unsafe.Add(unsafe.Pointer(data), unsafe.Sizeof(uint16(0))*1)))))
			}
			return 4
		default:
			return -1
		}
	case 0xF0:
		v79 := *(*uint8)(unsafe.Add(unsafe.Pointer(data), 1))
		if int32(v79) == 3 {
			v80 := *(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*69))
			v81 := int32(*(*uint32)(unsafe.Add(v80, 2056)))
			if v81 != 0 {
				v7 := int32(*(*uint32)(unsafe.Add(v81, 16)))
				if (v7 & 0x8000) != 0 {
					*(*int32)(unsafe.Add(unsafe.Pointer(v10), 4*137)) = 0
					nox_xxx_playerRespawn_4F7EF0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v80, 2056))))
				}
			}
		} else {
			if int32(v79) != 27 {
				return -1
			}
			sub_4DD0B0(unit)
		}
		return 2
	case 0xF1:
		v63 := (*uint32)(nox_xxx_equipedItemByCode_4F7920(unit, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
		if v63 != nil {
			nox_xxx_drop_4ED790(unit, (*server.Object)(unsafe.Pointer(v63)), (*types.Pointf)(unsafe.Add(unsafe.Pointer(unit), 56)))
			nox_xxx_netPriMsgToPlayer_4DA2C0(unit, internCStr("pickup.c:CarryingTooMuch"), 0)
		}
		return 3
	default:
		return -1
	}
}
