package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_server_handler_PlayerDamage_4E17B0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5           int32
		v6           int32
		v8           int32
		v9           int32
		v10          int32
		v11          int32
		v12          int32
		v13          *int32
		weaponFlags  int32
		v15          float32
		v16          *float2
		v17          int32
		v18          int32
		v19          int32
		v20          int32
		v21          int32
		v22          int32
		v23          int32
		v24          int32
		v25          int32
		v26          float64
		v27          int32
		v28          int8
		v29          int32
		v30          float64
		v31          int8
		v32          float64
		v33          int32
		v34          int32
		v35          float64
		v36          float32
		v37          float32
		v38          int32
		v39          float32
		v40          float32
		v41          int32
		v42          float32
		v43          int32
		v44          int32
		v45          int32
		v46          float32
		v47          float32
		v48          float32
		v49          float32
		v50          float32
		v51          float32
		v52          float32
		v53          float32
		armorrFlags  int32
		weaponFlags2 int32
		a3a          float2
	)
	v5 = a1
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if v6&2 != 0 || (v6&0x8000) != 0 {
		return 0
	}
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 23) != 0 {
		if (int32(uint8(gameFrame())) & 3) == 0 {
			nox_xxx_aud_501960(71, (*nox_object_t)(unsafe.Pointer(uintptr(v5))), 0, 0)
		}
		return 1
	}
	v8 = bool2int32(nox_common_gameFlags_check_40A5C0(2048))
	v9 = a2
	if v8 != 0 {
		if unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a2))))) == unsafe.Pointer(uintptr(v5)) && int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 && (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) != 15 {
			return 0
		}
	}
	if a3 != 0 {
		v9 = a3
	}
	v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
	v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))) & 4)
	if v11 != 0 {
		v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 748))))
		v13 = *(**int32)(unsafe.Pointer(uintptr(v12 + 276)))
		weaponFlags = *(*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
		armorrFlags = *v13
		v15 = *(*float32)(unsafe.Pointer(uintptr(v12 + 228)))
		weaponFlags2 = weaponFlags
	} else {
		if (v10&2) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 12))))&0x10) == 0 {
			return 0
		}
		v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 748))))
		weaponFlags2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v12 + 2056))))
		armorrFlags = int32(*(*uint32)(unsafe.Pointer(uintptr(v12 + 2060))))
		v15 = *(*float32)(unsafe.Pointer(uintptr(v12 + 2072)))
	}
	v53 = v15
	if v11 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v12 + 276))) + 3680))))&1 != 0 {
			return 0
		}
	}
	if v11 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 0
	} else if v10&2 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 && nox_xxx_playerGetPossess_4DDF30((*nox_object_t)(unsafe.Pointer(uintptr(v5)))) != nil {
		nox_xxx_playerObserveClear_4DDEF0((*nox_object_t)(unsafe.Pointer(uintptr(v5))))
	}
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v5))), 27) != 0 && v9 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1 != 0 {
			v16 = (*float2)(unsafe.Pointer(uintptr(v5 + 56)))
			if nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(v5+56))), int32(*(*int16)(unsafe.Pointer(uintptr(v5 + 124)))), (*float2)(unsafe.Pointer(uintptr(v9+56))))&1 != 0 {
				nox_xxx_projectileReflect_4E0A70(v9, v5)
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 12)))) & 0x40) == 0 {
					nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(v9))))
					nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(v5))), (*nox_object_t)(unsafe.Pointer(uintptr(v9))))
				}
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 12))))&2 != 0 {
					nox_xxx_changeOwner_52BE40(v9, v5)
				}
				if (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 16 {
					nox_xxx_netSendPointFx_522FF0(-124, v16)
				}
				nox_xxx_aud_501960(122, (*nox_object_t)(unsafe.Pointer(uintptr(v5))), 0, 0)
				return 0
			}
		} else if (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 16 || (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 17 {
			v16 = (*float2)(unsafe.Pointer(uintptr(v5 + 56)))
			if nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(v5+56))), int32(*(*int16)(unsafe.Pointer(uintptr(v5 + 124)))), (*float2)(unsafe.Pointer(uintptr(v9+56))))&1 != 0 {
				if (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 16 {
					nox_xxx_netSendPointFx_522FF0(-124, v16)
				}
				nox_xxx_aud_501960(122, (*nox_object_t)(unsafe.Pointer(uintptr(v5))), 0, 0)
				return 0
			}
		}
	}
	if a2 != 0 {
		v17 = int32(dword_5d4594_1563320)
		if dword_5d4594_1563320 == 0 {
			dword_5d4594_1563320 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFist")))
			*memmap.PtrUint32(0x5D4594, 1563324) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumFist")))
			*memmap.PtrUint32(0x5D4594, 1563328) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFist")))
			*memmap.PtrUint32(0x5D4594, 1563332) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Meteor")))
			*memmap.PtrUint32(0x5D4594, 1563336) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ToxicCloud")))
			v18 = nox_xxx_getNameId_4E3AA0(internCStr("SmallToxicCloud"))
			v17 = int32(dword_5d4594_1563320)
			*memmap.PtrUint32(0x5D4594, 1563340) = uint32(v18)
		}
		v19 = a3
		if a3 != 0 {
			a3a = *(*float2)(unsafe.Pointer(uintptr(a3 + 72)))
			v20 = int32(*(*uint16)(unsafe.Pointer(uintptr(a3 + 4))))
			v21 = bool2int32(int32(uint16(int16(v20))) != v17 && uint32(v20) != *memmap.PtrUint32(0x5D4594, 1563324) && uint32(v20) != *memmap.PtrUint32(0x5D4594, 1563328) && uint32(v20) != *memmap.PtrUint32(0x5D4594, 1563332) && uint32(v20) != *memmap.PtrUint32(0x5D4594, 1563336) && uint32(v20) != *memmap.PtrUint32(0x5D4594, 1563340))
			if a2 != a3 {
				v22 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
				if v22&4 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 1
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 300))) = uint32(*(*uint16)(unsafe.Pointer(uintptr(v19 + 4))))
				} else if v22&2 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 1
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 2184))) = uint32(*(*uint16)(unsafe.Pointer(uintptr(v19 + 4))))
				}
			}
		} else {
			v19 = a2
			a3a = *(*float2)(unsafe.Pointer(uintptr(a2 + 72)))
			v23 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4))))
			v21 = bool2int32(int32(uint16(int16(v23))) != v17 && uint32(v23) != *memmap.PtrUint32(0x5D4594, 1563324) && uint32(v23) != *memmap.PtrUint32(0x5D4594, 1563328) && uint32(v23) != *memmap.PtrUint32(0x5D4594, 1563332))
			if (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 10 || (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 2 {
				v24 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
				if v24&4 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 1
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 300))) = uint32(*(*uint16)(unsafe.Pointer(uintptr(v19 + 4))))
				} else if v24&2 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 1
					*(*uint32)(unsafe.Pointer(uintptr(v12 + 2184))) = uint32(*(*uint16)(unsafe.Pointer(uintptr(v19 + 4))))
				}
			}
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) != 15 && v21 != 0 && (nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(v5+56))), int32(*(*int16)(unsafe.Pointer(uintptr(v5 + 124)))), &a3a)&1) != 0 {
			var c1 int32 = int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8)))) & 4
			if c1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v12 + 88)))) != 16 || c1 == 0 && nox_xxx_mobActionGet_50A020(v5) != 21 || (uint32(armorrFlags)&0x3000000) == 0 {
				v27 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0)))
				if weaponFlags2&0x400 != 0 {
					v27 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0)))
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1 != 0 || float64(a5) == 0.0 || (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) == 11 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 {
							v28 = int8(*(*uint8)(unsafe.Pointer(uintptr(v12 + 88))))
							if int32(v28) != 13 && int32(v28) != 18 && int32(v28) != 19 && int32(v28) != 20 {
								goto LABEL_120
							}
						} else if sub_534340(v5) == 0 {
							goto LABEL_120
						}
						if int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1 != 0 {
							nox_xxx_projectileReflect_4E0A70(v9, v5)
							if int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1 != 0 {
								if (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 12)))) & 2) == 0 {
									nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(v9))))
									nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(v5))), (*nox_object_t)(unsafe.Pointer(uintptr(v9))))
								}
							}
						}
						nox_xxx_aud_501960(890, (*nox_object_t)(unsafe.Pointer(uintptr(v5))), 0, 0)
						if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 {
							v29 = nox_common_randomInt_415FA0(18, 20)
							nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v5))), v29)
						} else {
							nox_xxx_monsterAction_50A360(v5, 23)
						}
						v30 = nox_xxx_gamedataGetFloat_419D40(internCStr("ItemDamageFromBlockPercentage"))
						v47 = float32(v30 * float64(a4))
						sub_4E22A0(v5, a2, a3, 1024, v47, v27)
						return 0
					}
				} else {
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v12 + 88)))) == 1 && nox_common_mapPlrActionToStateId_4FA2B0((*nox_object_t)(unsafe.Pointer(uintptr(v5)))) == 45 && uint32(armorrFlags)&0x3000000 != 0 {
						if gameex_flags&0x10 != 0 {
							goto M_LABEL_78
						}
					}
				}
				if (uint32(weaponFlags2)&0x7FF8000) == 0 || v27 != 0 && v27 != 11 || int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1 != 0 {
					goto LABEL_120
				}
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 {
					v31 = int8(*(*uint8)(unsafe.Pointer(uintptr(v12 + 88))))
					if int32(v31) != 13 && int32(v31) != 18 && int32(v31) != 19 && int32(v31) != 20 && (int32(v31) != 0 || (gameex_flags&0x4) == 0) {
						goto LABEL_120
					}
				} else if sub_534340(v5) == 0 {
					goto LABEL_120
				}
				nox_xxx_aud_501960(894, (*nox_object_t)(unsafe.Pointer(uintptr(v5))), 0, 0)
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 {
					nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v5))), 21)
				} else {
					nox_xxx_monsterAction_50A360(v5, 23)
				}
				v32 = nox_xxx_gamedataGetFloat_419D40(internCStr("ItemDamageFromBlockPercentage"))
				v48 = float32(v32 * float64(a4))
				sub_4E22A0(v5, a2, a3, 134184960, v48, v27)
				return 0
			}
		M_LABEL_78:
			v25 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0)))
			if (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) != 9 && (*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0))) != 17 {
				nox_xxx_aud_501960(878, (*nox_object_t)(unsafe.Pointer(uintptr(v5))), 0, 0)
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1) != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 12))))&0x70) == 0 {
					nox_xxx_projectileReflect_4E0A70(v9, v5)
					if (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&1) != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 12))))&2) == 0 {
						nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(v9))))
						nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(v5))), (*nox_object_t)(unsafe.Pointer(uintptr(v9))))
					}
				}
				v26 = nox_xxx_gamedataGetFloat_419D40(internCStr("ItemDamageFromBlockPercentage"))
				v46 = float32(v26 * float64(a4))
				sub_4E2330(v5, a2, a3, 2, v46, v25)
				return 0
			}
		}
	}
LABEL_120:
	switch *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0)) {
	case 0:
		fallthrough
	case 3:
		fallthrough
	case 7:
		fallthrough
	case 8:
		fallthrough
	case 0xA:
		fallthrough
	case 0xB:
		v51 = float32((1.0 - float64(v53)) * float64(a4))
		nox_xxx_playerDecrementHPMana_4E20F0(v5, int32(uintptr(unsafe.Pointer(&a1))), v51)
		v33 = a4
		v42 = float32(a5)
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4-a1, float32(a5))
		v43 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
		if v43&4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 2
				*(*float32)(unsafe.Pointer(uintptr(v12 + 300))) = v42
			}
		} else if v43&2 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) == 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 2
			*(*float32)(unsafe.Pointer(uintptr(v12 + 2184))) = v42
		}
	case 1:
		fallthrough
	case 0xC:
		v33 = a4
		a1 = a4
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4, float32(a5))
		v34 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
		if v34&4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) == 0 {
				v36 = float32(a5)
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 2
				*(*float32)(unsafe.Pointer(uintptr(v12 + 300))) = v36
			}
		} else if v34&2 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) == 0 {
			v37 = float32(a5)
			*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 2
			*(*float32)(unsafe.Pointer(uintptr(v12 + 2184))) = v37
		}
	case 2:
		v50 = float32((1.0 - float64(v53)*0.5) * float64(a4))
		nox_xxx_playerDecrementHPMana_4E20F0(v5, int32(uintptr(unsafe.Pointer(&a1))), v50)
		v33 = a4
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4-a1, COERCE_FLOAT(2))
		v41 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
		if v41&4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 2
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 300))) = 2
			}
		} else if v41&2 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) == 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 2
			*(*uint32)(unsafe.Pointer(uintptr(v12 + 2184))) = 2
		}
	case 4:
		fallthrough
	case 5:
		fallthrough
	case 6:
		fallthrough
	case 0xE:
		fallthrough
	case 0xF:
		fallthrough
	case 0x10:
		v38 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
		v33 = a4
		a1 = a4
		if v38&4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) == 0 {
				v39 = float32(a5)
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 2
				*(*float32)(unsafe.Pointer(uintptr(v12 + 300))) = v39
			}
		} else if v38&2 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) == 0 {
			v40 = float32(a5)
			*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 2
			*(*float32)(unsafe.Pointer(uintptr(v12 + 2184))) = v40
		}
	case 9:
		fallthrough
	case 0x11:
		v35 = sub_4E2220(v5)
		v49 = float32(v35 * float64(a4))
		nox_xxx_playerDecrementHPMana_4E20F0(v5, int32(uintptr(unsafe.Pointer(&a1))), v49)
		v33 = a4
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4, float32(a5))
		v34 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))))
		if v34&4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) == 0 {
				v36 = float32(a5)
				*(*uint32)(unsafe.Pointer(uintptr(v12 + 304))) = 2
				*(*float32)(unsafe.Pointer(uintptr(v12 + 300))) = v36
			}
		} else if v34&2 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) == 0 {
			v37 = float32(a5)
			*(*uint32)(unsafe.Pointer(uintptr(v12 + 2188))) = 2
			*(*float32)(unsafe.Pointer(uintptr(v12 + 2184))) = v37
		}
	default:
		v33 = a4
		a1 = a4
	}
	if v33 > 0 && a1 == 0 {
		a1 = 1
	}
	if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_GODMODE)) && int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4 != 0 {
		return 1
	}
	if nox_common_gameFlags_check_40A5C0(4096) {
		v44 = a1
		v52 = float32(sub_4E40B0() * float64(a1))
		v45 = nox_float2int(v52)
		a1 = v45
		if v44 > 0 && v45 < 1 {
			v45 = 1
			a1 = 1
		}
	} else {
		v45 = a1
	}
	return nox_xxx_damageDefaultProc_4E0B30(v5, a2, a3, v45, *(*int32)(unsafe.Add(unsafe.Pointer(&a5), 4*0)))
}
func nox_xxx_playerDecrementHPMana_4E20F0(a1 int32, a2 int32, a3 float32) {
	var (
		v3 int32
		v4 int32
		v5 float64
		v6 int32
		v7 int32
		v8 int32
	)
	v3 = a1
	if a1 != 0 && a2 != 0 {
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v4&4 != 0 {
			v5 = float64(a3 + *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 84))))
		} else {
			if (v4 & 2) == 0 {
				goto LABEL_8
			}
			v5 = float64(a3 + *(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 4))))
		}
		a3 = float32(v5)
	LABEL_8:
		v6 = nox_float2int(a3)
		v8 = v6
		*(*uint32)(unsafe.Pointer(uintptr(a2))) = uint32(v6)
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 8))))
		if v7&4 != 0 {
			*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 748))) + 84))) = float32(float64(a3) - float64(v8))
		} else if v7&2 != 0 {
			*(*float32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 748))) + 4))) = float32(float64(a3) - float64(v8))
		}
	}
}
func nox_xxx_playerDamageItems_4E2180(a1 int32, a2 int32, a3 int32, a4 int32, a5 float32) {
	var (
		v5  int32
		v6  int32
		v7  *uint32
		v8  int32
		v9  int32
		v10 int32
		v11 float32
	)
	v5 = a1
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if v6&4 != 0 {
		v10 = *(*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 228)))
	} else {
		if (v6&2) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10) == 0 {
			return
		}
		v10 = *(*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 2072)))
	}
	v7 = *(**uint32)(unsafe.Pointer(uintptr(v5 + 504)))
	if v7 != nil {
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a5))), 4*0)))
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*2))&0x2000000 != 0 {
				v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*4)))
				if v9&0x100 != 0 {
					v11 = float32(nox_xxx_itemApplyDefendEffect_415C00(int32(uintptr(unsafe.Pointer(v7)))) / float64(*(*float32)(unsafe.Pointer(&v10))) * float64(a4))
					nox_xxx_equipDamage_4E16D0(int32(uintptr(unsafe.Pointer(v7))), v5, a2, a3, v11, v8)
				}
			}
			v7 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*124)))))
			if v7 == nil {
				break
			}
		}
	}
}
func sub_4E2220(a1 int32) float64 {
	var (
		v1 int32
		v2 int32
		v3 float64
		v5 float32
	)
	v5 = 1.0
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
	if v1 == 0 {
		return 1.0
	}
	for {
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 8)))&0x2000000 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 24))))&0x10 != 0 {
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))))
				if v2&0x100 != 0 {
					if sub_4133D0(v1) == 0 {
						if *(*uint32)(unsafe.Pointer(uintptr(v1 + 12)))&0x2000000 != 0 {
							v3 = float64(*mem_getFloatPtr(0x587000, 201108))
						} else {
							v3 = sub_415BD0(v1)
						}
						v5 = float32(v3 + float64(v5))
					}
				}
			}
		}
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 496))))
		if v1 == 0 {
			break
		}
	}
	return float64(v5)
}
func sub_4E22A0(a1 int32, a2 int32, a3 int32, a4 int32, a5 float32, a6 int32) int32 {
	var (
		i  *uint32
		v7 int32
	)
	for i = *(**uint32)(unsafe.Pointer(uintptr(a1 + 504))); i != nil; i = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*124))))) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*4))&0x100 != 0 && uint32(a4)&*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)) != 0 {
			break
		}
	}
	v7 = a3
	if a3 == 0 {
		v7 = a2
	}
	nox_xxx_playerDamageWeapon_4E1560(int32(uintptr(unsafe.Pointer(i))), a1, a2, v7, a5, a6)
	if (*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*4)) & 0x20) == 0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 13)
	} else {
		nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
	return 1
}
func sub_4E2330(a1 int32, a2 int32, a3 int32, a4 int32, a5 float32, a6 int32) int32 {
	var (
		i  *uint32
		v7 int32
	)
	for i = *(**uint32)(unsafe.Pointer(uintptr(a1 + 504))); i != nil; i = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*124))))) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*4))&0x100 != 0 && uint32(a4)&*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)) != 0 {
			break
		}
	}
	v7 = a3
	if a3 == 0 {
		v7 = a2
	}
	nox_xxx_equipDamage_4E16D0(int32(uintptr(unsafe.Pointer(i))), a1, a2, v7, a5, a6)
	if i == nil {
		return 0
	}
	if (*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*4)) & 0x20) == 0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 13)
	} else {
		nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
	return 1
}
func sub_4E23C0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		result int32
		v6     float32
		v7     float32
		v8     int32
		a3a    float2
	)
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 23) != 0 {
		if (int32(uint8(gameFrame())) & 3) == 0 {
			nox_xxx_aud_501960(71, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
		result = 1
	} else if a2 != 0 && (func() bool {
		if a3 == 0 {
			v7 = *(*float32)(unsafe.Pointer(uintptr(a2 + 76)))
			a3a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 72)))
			a3a.field_4 = v7
		} else {
			v6 = *(*float32)(unsafe.Pointer(uintptr(a3 + 76)))
			a3a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a3 + 72)))
			a3a.field_4 = v6
		}
		return nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a1+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124)))), &a3a)&1 != 0 && (func() bool {
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			return nox_xxx_mobActionGet_50A020(a1) == 21
		}()) && uint32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 481)))) > uint32(int32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 480))))>>1)
	}()) {
		nox_xxx_aud_501960(878, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		result = 1
	} else {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5)
	}
	return result
}
func sub_4E24B0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	return nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5)
}
func sub_4E24E0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var v5 int32
	if a5 != 9 && a5 != 17 {
		v5 = a4
	} else {
		v5 = a4 * 2
	}
	return nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, v5, a5)
}
func nox_xxx_damageFlammable_4E2520(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var v5 int32
	if a5 == 1 || a5 == 12 || (func() bool {
		v5 = a4
		return a5 == 7
	}()) {
		v5 = 9999999
	}
	return nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, v5, a5)
}
func nox_xxx_damageBlackPowder_4E2560(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var result int32
	if a5 != 1 && a5 != 12 && a5 != 2 && a5 != 0 {
		result = 0
	} else {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, 999999, a5)
	}
	return result
}
func nox_xxx_damageMonsterGen_4E27D0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5  int32
		v7  int32
		v8  int32
		v9  *uint16
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 float32
		v15 float32
		a1a float2
		v17 int32
	)
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x8020 != 0 {
		return 0
	}
	if (gameFrame()-*(*uint32)(unsafe.Pointer(uintptr(a1 + 536)))) > 0x14 || (gameFrame()%0x1E) == 0 {
		if a3 != 0 {
			a1a.field_0 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 56)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))) + 0.0099999998)
			a1a.field_4 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a3 + 60)))-*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))) + 0.0099999998)
			nox_xxx_utilNormalizeVector_509F20(&a1a)
			a1a.field_0 = float32(float64(a1a.field_0)*22.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))
			a1a.field_4 = float32(float64(a1a.field_4)*22.0 + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))))
			sub_523150(-16, 26, &a1a.field_0)
		} else {
			sub_523150(-16, 26, (*float32)(unsafe.Pointer(uintptr(a1+56))))
		}
		nox_xxx_aud_501960(1001, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	v7 = int32(uint16(nox_xxx_unitGetHP_4EE780((*nox_object_t)(unsafe.Pointer(uintptr(a1))))))
	v17 = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5)
	if int32(uint16(nox_xxx_unitGetHP_4EE780((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))) < v7 {
		nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(v5+48)), unsafe.Pointer(uintptr(a2)), unsafe.Pointer(uintptr(a1)), 23)
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if (v8&0x8000) == 0 && (v8&0x20) == 0 {
		v9 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
		v10 = int32(*v9)
		v14 = float32(float64(*(*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*2))) * 0.333)
		if v10 > nox_float2int(v14) {
			v15 = float32(float64(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) + 4)))) * 0.66600001)
			if v10 <= nox_float2int(v15) {
				v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 20))))
				if (v13 & 0x100) == 0 {
					nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(0x100)))))))
				}
			}
		} else {
			v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 20))))
			if v11&0x100 != 0 {
				nox_xxx_unitUnsetXStatus_4E4780((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 256)
			}
			v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 20))))
			if (v12 & 0x200) == 0 {
				nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(0x200)))))))
			}
		}
	}
	return v17
}
func sub_4E3CA0() float64 {
	return float64(*mem_getFloatPtr(0x587000, 202024))
}
func sub_4E3CB0(a1 float32) int32 {
	var result int32
	result = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	*mem_getFloatPtr(0x587000, 202024) = a1
	return result
}
func nox_game_getQuestStage_4E3CC0() int32 {
	return int32(*memmap.PtrUint32(0x587000, 202028))
}
func nox_game_setQuestStage_4E3CD0(a1 int32) {
	*memmap.PtrUint32(0x587000, 202028) = uint32(a1)
}
func nox_xxx_player_4E3CE0() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = 0
	v1 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v1 == 0 {
		return 0
	}
	for {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 748))))
		if (!nox_common_gameFlags_check_40A5C0(1) || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))) != 31) && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4792))) == 1 {
			v0++
		}
		v1 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(v1)))))))
		if v1 == 0 {
			break
		}
	}
	return v0
}
func sub_4E3D50() int32 {
	var (
		v0 int32
		v2 float32
	)
	if *memmap.PtrUint32(0x5D4594, 1563928) == 0 {
		*mem_getFloatPtr(0x5D4594, 1563912) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("PlayerDifficultyDelta")))
		*memmap.PtrUint32(0x5D4594, 1563928) = 1
	}
	v0 = nox_xxx_player_4E3CE0()
	v2 = float32(float64(uint32(nox_game_getQuestStage_4E3CC0())) * (float64(v0-1)*float64(*mem_getFloatPtr(0x5D4594, 1563912)) + 1.0))
	return sub_4E3CB0(v2)
}
func sub_4E3DD0() int16 {
	var (
		v0  int32
		v1  int32
		v2  int32
		v3  int32
		v4  int16
		v5  int32
		v6  uint16
		v7  uint16
		v8  int16
		v9  int32
		v10 int32
		v11 int16
		v12 int16
		v13 int32
		v15 float32
		v16 float32
		v17 float32
		v18 float32
		v19 float32
		v20 float32
		v21 float32
		v22 float32
		v23 uint16
	)
	v21 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxHealth")))
	v23 = uint16(int16(nox_float2int(v21)))
	if *memmap.PtrUint32(0x5D4594, 1563932) == 0 {
		*mem_getFloatPtr(0x5D4594, 1563908) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("PlayerDamageDiffInit")))
		*mem_getFloatPtr(0x5D4594, 1563916) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SystemHealthDiffInit")))
		*mem_getFloatPtr(0x5D4594, 1563920) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("PlayerDamageDiffCoeff")))
		*mem_getFloatPtr(0x5D4594, 1563924) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("SystemHealthDiffCoeff")))
		*memmap.PtrUint32(0x5D4594, 1563932) = 1
	}
	v19 = float32((sub_4E3CA0()-1.0)*float64(*mem_getFloatPtr(0x5D4594, 1563920)) + float64(*mem_getFloatPtr(0x5D4594, 1563908)))
	sub_4E4080(v19)
	v20 = float32((sub_4E3CA0()-1.0)*float64(*mem_getFloatPtr(0x5D4594, 1563924)) + float64(*mem_getFloatPtr(0x5D4594, 1563916)))
	sub_4E40C0(v20)
	v0 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	v1 = v0
	if v0 != 0 {
		for {
			v2 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(v1)))))))
			v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 8))))
			if uint32(v0)&0x20000 != 0 && (func() bool {
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))))
				return (v3 & 0x8000) == 0
			}()) {
				v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))))
				v4 = int16(*(*uint16)(unsafe.Pointer(uintptr(v0 + 4))))
				if int32(v4) != 0 {
					*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v0))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(v0)))
					if int32(uint16(int16(v0))) != 0 {
						if int32(uint16(int16(v0))) == int32(v4) {
							v5 = int32(uintptr(nox_xxx_objectTypeByIndHealthData(int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 4)))))))
							v15 = float32(sub_4E40F0() * float64(*(*uint16)(unsafe.Pointer(uintptr(v5 + 4)))))
							v6 = uint16(nox_float2int16_abs(v15))
							v16 = float32(sub_4E40F0() * float64(*(*uint16)(unsafe.Pointer(uintptr(v5)))))
							v7 = uint16(nox_float2int16_abs(v16))
							if int32(v7) == 0 {
								v7 = 1
							}
							if int32(v6) == 0 {
								v6 = 1
							}
							if int32(v7) > int32(v23) {
								v7 = v23
							}
							if int32(v6) > int32(v23) {
								v6 = v23
							}
							*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v0))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(v1))), v7)))
							*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4))) = v6
						}
					}
				}
			} else if v0&2 != 0 {
				v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))))
				if (v0 & 0x8000) == 0 {
					v0 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))))
					v8 = int16(*(*uint16)(unsafe.Pointer(uintptr(v0 + 4))))
					if int32(v8) != 0 {
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v0))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(v0)))
						if int32(uint16(int16(v0))) != 0 {
							if int32(uint16(int16(v0))) == int32(v8) {
								var v0a int32 = int32(uintptr(nox_xxx_objectTypeByIndHealthData(int32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 4)))))))
								v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 748))))
								v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 484))))
								if v10 != 0 {
									*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v0))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(v10 + 72)))
								} else {
									*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v0))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(v0a + 4)))
								}
								if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(v9 + 1440))))) >= 0 {
									v22 = float32(float64(uint16(int16(v0))))
									v17 = float32(sub_4E40F0() * float64(v22))
									v11 = nox_float2int16_abs(v17)
									v18 = float32(sub_4E40F0() * float64(v22))
									v12 = nox_float2int16_abs(v18)
									if int32(v12) == 0 {
										v12 = 1
									}
									if int32(v11) == 0 {
										v11 = 1
									}
									nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(v1))), uint16(v12))
									v0 = v9 + 412
									v13 = 32
									*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 556))) + 4))) = uint16(v11)
									for {
										v0 += 2
										v13--
										*(*uint16)(unsafe.Pointer(uintptr(v0 - 2))) = **(**uint16)(unsafe.Pointer(uintptr(v1 + 556)))
										if v13 == 0 {
											break
										}
									}
								}
							}
						}
					}
				}
			}
			v1 = v2
			if v2 == 0 {
				break
			}
		}
	}
	return int16(v0)
}
func sub_4E4080(a1 float32) {
	var v1 float64
	v1 = nox_xxx_gamedataGetFloat_419D40(internCStr("PlayerDamageCap"))
	if float64(a1) <= v1 {
		*mem_getFloatPtr(0x587000, 202032) = a1
	} else {
		*mem_getFloatPtr(0x587000, 202032) = float32(v1)
	}
}
func sub_4E40B0() float64 {
	return float64(*mem_getFloatPtr(0x587000, 202032))
}
func sub_4E40C0(a1 float32) {
	var v1 float64
	v1 = nox_xxx_gamedataGetFloat_419D40(internCStr("SystemHealthCap"))
	if float64(a1) <= v1 {
		*mem_getFloatPtr(0x587000, 202036) = a1
	} else {
		*mem_getFloatPtr(0x587000, 202036) = float32(v1)
	}
}
func sub_4E40F0() float64 {
	return float64(*mem_getFloatPtr(0x587000, 202036))
}
func sub_4E4100() int32 {
	var (
		v0     uint32
		v1     int32
		v2     int32
		result int32
	)
	v0 = 0
	v1 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v1 == 0 {
		return 1
	}
	for {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 748))))
		if !nox_common_gameFlags_check_40A5C0(1) || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))) != 31 {
			if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4792))) != 0 {
				v0++
			}
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(v1)))))))
		v1 = result
		if result == 0 {
			break
		}
	}
	if v0 < 6 {
		return 1
	}
	return result
}
func sub_4E41B0(a1 *byte) int32 {
	var v1 *FILE
	v1 = nox_fs_open_text(a1)
	if v1 != nil {
		for {
			for {
				for {
					if !nox_fs_fgets(v1, (*byte)(memmap.PtrOff(0x5D4594, 1563936)), 1024) {
						nox_fs_close(v1)
						return 1
					}
					if libc.StrTok((*byte)(memmap.PtrOff(0x5D4594, 1563936)), internCStr("\r\t\n")) != nil {
						break
					}
				}
				if libc.StrCmp((*byte)(memmap.PtrOff(0x5D4594, 1563936)), internCStr("[Banned Users]")) != 0 {
					break
				}
				if sub_4E42C0(v1) == 0 {
					goto LABEL_11
				}
			}
			if libc.StrCmp((*byte)(memmap.PtrOff(0x5D4594, 1563936)), internCStr("[Allowed Users]")) == 0 && sub_4E4390(v1) == 0 {
				break
			}
		}
	LABEL_11:
		nox_fs_close(v1)
	}
	return 0
}
func sub_4E42C0(a1 *FILE) int32 {
	var (
		v1 *byte
		v2 *byte
		v4 [26]wchar2_t
	)
	for {
		if !nox_fs_fgets(a1, (*byte)(memmap.PtrOff(0x5D4594, 1563936)), 1024) {
			return 1
		}
		v1 = libc.StrTok((*byte)(memmap.PtrOff(0x5D4594, 1563936)), internCStr("\r\t\n"))
		if v1 == nil {
			return 1
		}
		nox_swprintf(&v4[0], (*wchar2_t)(unsafe.Pointer(internCStr("%S"))), v1)
		if !nox_fs_fgets(a1, (*byte)(memmap.PtrOff(0x5D4594, 1563936)), 1024) {
			return 1
		}
		v2 = libc.StrTok((*byte)(memmap.PtrOff(0x5D4594, 1563936)), internCStr("\r\t\n"))
		if v2 == nil {
			break
		}
		if libc.StrCmp(v2, internCStr("0")) == 0 {
			sub_416770(0, &v4[0], nil)
		} else {
			sub_416770(0, &v4[0], v2)
		}
	}
	return 0
}
func sub_4E4390(a1 *FILE) int32 {
	var (
		v1 *byte
		v3 [26]wchar2_t
	)
	for nox_fs_fgets(a1, (*byte)(memmap.PtrOff(0x5D4594, 1563936)), 1024) {
		v1 = libc.StrTok((*byte)(memmap.PtrOff(0x5D4594, 1563936)), internCStr("\r\t\n"))
		if v1 == nil {
			break
		}
		nox_swprintf(&v3[0], (*wchar2_t)(unsafe.Pointer(internCStr("%S"))), v1)
		sub_4168A0(&v3[0])
	}
	return 1
}
func sub_4E43F0(a1 *byte) *FILE {
	var (
		result *FILE
		v2     *FILE
		i      *int32
		j      *int32
	)
	result = nox_fs_create_text(a1)
	v2 = result
	if result != nil {
		nox_fs_fprintf(result, internCStr("%s\n"), memmap.PtrOff(0x587000, 202212))
		for i = sub_416900(); i != nil; i = sub_416910(i) {
			if *((*uint64)(unsafe.Add(unsafe.Pointer((*uint64)(unsafe.Pointer(i))), unsafe.Sizeof(uint64(0))*8))) == 0 {
				nox_fs_fprintf(v2, internCStr("%S\n"), (*int32)(unsafe.Add(unsafe.Pointer(i), 4*3)))
				if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(i))), 72)))) != 0 {
					nox_fs_fprintf(v2, internCStr("%s\n"), (*int32)(unsafe.Add(unsafe.Pointer(i), 4*18)))
				} else {
					nox_fs_fprintf(v2, internCStr("0\n"))
				}
			}
		}
		nox_fs_fprintf(v2, internCStr("\n%s\n"), memmap.PtrOff(0x587000, 202228))
		for j = sub_4168E0(); j != nil; j = sub_4168F0(j) {
			nox_fs_fprintf(v2, internCStr("%S\n"), (*int32)(unsafe.Add(unsafe.Pointer(j), 4*3)))
		}
		nox_fs_close(v2)
		result = (*FILE)(unsafe.Pointer(uintptr(1)))
	}
	return result
}
func nox_xxx_unitNeedSync_4E44F0(a1 *nox_object_t) {
	*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))) + 152))) = math.MaxUint32
}
func sub_4E4500(a1p *nox_object_t, a2 int32, a3 int32, a4 int32) *int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v4     int32
		result *int32
		v6     int32
	)
	v4 = 0
	result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
	for {
		if a4 != 0 {
			*result |= a3
		} else {
			*result &= ^a3
		}
		v6 = *result
		if uint32(1<<v4)&*(*uint32)(unsafe.Pointer(uintptr(a1 + 148))) != 0 {
			*result = a2 | v6
		} else if (v6 & a3) == 0 {
			*result = v6 & ^a2
		}
		v4++
		result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
		if v4 >= 32 {
			break
		}
	}
	return result
}
func nox_xxx_unitSetHP_4E4560(obj *nox_object_t, amount uint16) int32 {
	var (
		unit            int32 = int32(uintptr(unsafe.Pointer(obj)))
		healthData      int32
		otherHealthData int32
		unitFlags       int32
		v5              *int32
		counter         int32
		v7              int32
		v8              int32
	)
	healthData = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 556))))
	if healthData != 0 {
		nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
		otherHealthData = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 492))))
		if otherHealthData != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(otherHealthData + 8))))&4 != 0 {
			nox_xxx_protect_56FC50(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(otherHealthData + 748))) + 276))) + 4632)))), (*nox_object_t)(unsafe.Pointer(uintptr(unit))))
		}
		**(**uint16)(unsafe.Pointer(uintptr(unit + 556))) = amount
		if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
			nox_xxx_protectPlayerHPMana_56F870(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))) + 276))) + 4584)))), amount)
		}
		unitFlags = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 8))))
		if unitFlags&2 != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 12))))&0x80) != 0 {
			if uint32(unitFlags)&0x20400004 != 0 {
				v5 = (*int32)(unsafe.Pointer(uintptr(unit + 560)))
				counter = 32
				for {
					v7 = *v5
					v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
					counter--
					*((*int32)(unsafe.Add(unsafe.Pointer(v5), -int(4*1)))) = int32(uint32(v7)&0xFFFFF000 | 0x20000)
					if counter == 0 {
						break
					}
				}
			} else {
				v8 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(unit))), 2)
				sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(unit))), 0x20000, 2, v8)
			}
		}
		healthData = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 492))))
		if healthData != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(healthData + 8))))&4 != 0 {
				healthData = nox_xxx_protect_56FBF0(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(healthData + 748))) + 276))) + 4632)))), (*nox_object_t)(unsafe.Pointer(uintptr(unit))))
			}
		}
	}
	return healthData
}
func nox_xxx_unitSetOnOff_4E4670(a1 int32, a2 int32) *int32 {
	var (
		v2     int32
		v3     uint32
		result *int32
		v5     int32
		v6     int32
		v7     int32
	)
	nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if a2 != 0 {
		v3 = uint32(v2) | 0x1000000
	} else {
		v3 = uint32(v2) & 0xFEFFFFFF
	}
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = v3
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
		result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
		v5 = 32
		for {
			v6 = *result
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
			v5--
			*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v6)&0xFFFFF000 | 0x40000)
			if v5 == 0 {
				break
			}
		}
	} else {
		v7 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 4)
		result = sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x40000, 4, v7)
	}
	return result
}
func nox_xxx_unitRaise_4E46F0(obj *nox_object_t, a2 float32) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v2 *int32
		v3 int32
		v4 int32
		v5 int32
	)
	if *(*float32)(unsafe.Pointer(uintptr(a1 + 104))) != a2 {
		nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 104))) = a2
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
			v2 = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
			v3 = 32
			for {
				v4 = *v2
				v2 = (*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1))
				v3--
				*((*int32)(unsafe.Add(unsafe.Pointer(v2), -int(4*1)))) = int32(uint32(v4)&0xFFFFF000 | 0x400000)
				if v3 == 0 {
					break
				}
			}
		} else {
			v5 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x40)
			sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x400000, 64, v5)
		}
	}
}
func nox_xxx_unitUnsetXStatus_4E4780(a1p *nox_object_t, a2 int32) *int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result *int32
		v3     int32
		v4     int32
		v5     int32
	)
	result = *(**int32)(unsafe.Pointer(uintptr(a1 + 20)))
	if uint32(uintptr(unsafe.Pointer(result)))&uint32(a2) != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 20))) = uint32(uintptr(unsafe.Pointer(result))) & uint32(^a2)
		if a2 != 1 {
			nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
				result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
				v3 = 32
				for {
					v4 = *result
					result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
					v3--
					*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v4)&0xFFFFF000 | 0x80000)
					if v3 == 0 {
						break
					}
				}
			} else {
				v5 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 8)
				result = sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x80000, 8, v5)
			}
		}
	}
	return result
}
func nox_xxx_unitSetXStatus_4E4800(a1p *nox_object_t, a2 int32) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result *int32
		v3     int32
		v4     int32
		v5     int32
	)
	result = (*int32)(unsafe.Pointer(uintptr(a2)))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 20))) |= uint32(a2)
	if a2 != 1 {
		nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
			result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
			v3 = 32
			for {
				v4 = *result
				result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
				v3--
				*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v4)&0xFFFFF000 | 0x80000)
				if v3 == 0 {
					break
				}
			}
		} else {
			v5 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 8)
			result = sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x80000, 8, v5)
		}
	}
	return int32(uintptr(unsafe.Pointer(result)))
}
func nox_xxx_servMarkObjAnimFrame_4E4880(a1 int32, a2 int32) *int32 {
	var (
		result *int32
		v3     int32
		v4     int32
		v5     int32
	)
	nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 132))) = uint32(a2)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
		result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
		v3 = 32
		for {
			v4 = *result
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
			v3--
			*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v4)&0xFFFFF000 | 0x10000)
			if v3 == 0 {
				break
			}
		}
	} else {
		v5 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 1)
		result = sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x10000, 1, v5)
	}
	return result
}
func nox_xxx_setUnitBuffFlags_4E48F0(a1 int32, a2 int32) *int32 {
	var (
		v2     int8
		result *int32
		v4     int32
		v5     int32
		v6     int32
	)
	nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	v2 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 340))) = uint32(a2)
	if int32(v2)&4 != 0 {
		nox_xxx_playerResetProtectionCRC_56F7D0(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 4612)))), a2)
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
		result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
		v4 = 32
		for {
			v5 = *result
			result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
			v4--
			*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v5)&0xFFFFF000 | 0x800000)
			if v4 == 0 {
				break
			}
		}
	} else {
		v6 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x80)
		result = sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x800000, 128, v6)
	}
	return result
}
func nox_xxx_modifSetItemAttrs_4E4990(a1p *nox_object_t, a2 *int32) *int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v2     int32
		v3     int32
		result *int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if v2&0x1000 != 0 && *(*uint32)(unsafe.Pointer(uintptr(a1 + 12)))&0x47F0000 != 0 {
		goto LABEL_19
	}
	v3 = 0
	result = a2
	v5 = 4
	for {
		if *result != 0 {
			v3 = 1
		}
		result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
		v5--
		if v5 == 0 {
			break
		}
	}
	if v3 == 0 {
		return result
	}
LABEL_19:
	result = *(**int32)(memmap.PtrOff(0x5D4594, 1564960))
	if *memmap.PtrUint32(0x5D4594, 1564960) == 0 {
		result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_getNameId_4E3AA0(internCStr("TeamBase")))))
		*memmap.PtrUint32(0x5D4594, 1564960) = uint32(uintptr(unsafe.Pointer(result)))
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x13001000 != 0 || (*int32)(unsafe.Pointer(uintptr(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))))) == result {
		nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		alloc.Memcpy(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 692))), unsafe.Pointer(a2), 0x14)
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x20400004 != 0 {
			result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
			v6 = 32
			for {
				v7 = *result
				result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
				v6--
				*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v7)&0xFFFFF000 | 0x2000000)
				if v6 == 0 {
					break
				}
			}
		} else {
			v8 = sub_4E4C90((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x200)
			result = sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x2000000, 512, v8)
		}
	}
	return result
}
func nox_xxx_objectGetMass_4E4A70(a1 int32) float64 {
	return float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 120))))
}
func nox_xxx_npcSetItemEquipFlags_4E4B20(a1 int32, item *nox_object_t, a3 int32) *int32 {
	var (
		v3     int32
		v4     int32
		v5     int32
		result *int32
		v7     int32
		v8     int32
	)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	v4 = int32(item.obj_class)
	if a3 == 1 {
		if uint32(v4)&0x1001000 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 2056))) |= uint32(nox_xxx_weaponInventoryEquipFlags_415820(item))
			goto LABEL_9
		}
		v5 = int32(uint32(nox_xxx_unitArmorInventoryEquipFlags_415C70(item)) | *(*uint32)(unsafe.Pointer(uintptr(v3 + 2060))))
	} else {
		if uint32(v4)&0x1001000 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 2056))) &= uint32(^nox_xxx_weaponInventoryEquipFlags_415820(item))
			goto LABEL_9
		}
		v5 = int32(uint32(^nox_xxx_unitArmorInventoryEquipFlags_415C70(item)) & *(*uint32)(unsafe.Pointer(uintptr(v3 + 2060))))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 2060))) = uint32(v5)
LABEL_9:
	if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))) & 0x20400004) == 0 {
		return sub_4E4500((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0x4000000, 1024, 1)
	}
	result = (*int32)(unsafe.Pointer(uintptr(a1 + 560)))
	v7 = 32
	for {
		v8 = *result
		result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
		v7--
		*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = int32(uint32(v8)&0xFFFFF000 | 0x4000000)
		if v7 == 0 {
			break
		}
	}
	return result
}
func sub_4E4C00(item *nox_object_t) int32 {
	var result int32
	if item != nil {
		result = int32(item.net_code)
	} else {
		result = 0
	}
	return result
}
func sub_4E4C10(item *nox_object_t) int32 {
	var result int32
	if item != nil {
		result = int32(item.typ_ind)
	} else {
		result = 0
	}
	return result
}
func nox_object_getInitData_4E4C30(item *nox_object_t) int32 {
	var result int32
	if item != nil {
		result = int32(uintptr(item.init_data))
	} else {
		result = 0
	}
	return result
}
func sub_4E4C80(item *nox_object_t) int32 {
	var (
		a1     *int32 = (*int32)(unsafe.Pointer(item))
		result int32
	)
	if item != nil {
		result = *a1
	} else {
		result = 0
	}
	return result
}
func sub_4E4DE0() int32 {
	var (
		v0     int32
		v1     *uint8
		result int32
	)
	if *memmap.PtrUint32(0x5D4594, 1565508) != 0 {
		nox_free_alloc_class((*nox_alloc_class)(*(*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 1565508))))
	}
	*memmap.PtrUint32(0x5D4594, 1565508) = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 1565524), 0, 0x40)
	libc.MemSet(memmap.PtrOff(0x5D4594, 1565124), 0, 384)
	dword_5d4594_1565512 = 0
	dword_5d4594_1565516 = 0
	v0 = 0
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, 1565124))
	for {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 1)) = 2
		*v1 = 1
		*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 2)) = uint8(int8(nox_xxx_rateGet_40A6C0()))
		result = sub_4E4E50(v0)
		v1 = (*uint8)(unsafe.Add(unsafe.Pointer(v1), 12))
		v0++
		if int32(uintptr(unsafe.Pointer(v1))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1565508))) {
			break
		}
	}
	return result
}
func sub_4E4E50(a1 int32) int32 {
	var (
		v1     uint32
		v2     uint8
		v3     *uint8
		result int32
	)
	v1 = 1
	if dword_5d4594_2650652 == 1 {
		v1 = uint32(nox_xxx_rateGet_40A6C0())
	}
	v2 = *memmap.PtrUint8(0x5D4594, uintptr(a1*12)+1565125)
	v3 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(a1*12)+1565124))
	if int32(v2) > 2 {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*2))) = uint32(int32(*v3)*(int32(v2)-1)) * (gameFPS() / v1)
	} else {
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*2))) = 0
	}
	result = int32(uint32(int32(v2)*int32(*v3)) * (gameFPS() / v1))
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) = uint32(result)
	return result
}
func sub_4E4ED0() int32 {
	var result int32
	result = 0
	libc.MemSet(memmap.PtrOff(0x5D4594, 1565524), 0, 0x40)
	return result
}
func sub_4E4EF0() int32 {
	var (
		v0     *uint8
		v1     int32
		result int32
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 1565124))
	libc.MemSet(memmap.PtrOff(0x5D4594, 1565124), 0, 384)
	v1 = 0
	for {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v0), 1)) = 2
		*v0 = 1
		*(*uint8)(unsafe.Add(unsafe.Pointer(v0), 2)) = uint8(int8(nox_xxx_rateGet_40A6C0()))
		result = sub_4E4E50(v1)
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 12))
		v1++
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1565508))) {
			break
		}
	}
	return result
}
func sub_4E4F30(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint16(0x5D4594, uintptr(a1*2)+1565524) = 0
	return result
}
func nox_xxx_playerResetImportantCtr_4E4F40(a1 int32) int32 {
	var v1 int32
	v1 = a1 * 12
	*memmap.PtrUint8(0x5D4594, uintptr(v1)+1565125) = 2
	*memmap.PtrUint8(0x5D4594, uintptr(v1)+1565124) = 1
	*memmap.PtrUint8(0x5D4594, uintptr(v1)+1565126) = uint8(int8(nox_xxx_rateGet_40A6C0()))
	return sub_4E4E50(a1)
}
func sub_4E4F80() int32 {
	var (
		result int32
		v1     uint8
		v2     int32
	)
	result = int32(dword_5d4594_1565512)
	if dword_5d4594_1565512 != 0 {
		for {
			v1 = *(*uint8)(unsafe.Pointer(uintptr(result + 251)))
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 408))))
			if int32(v1) >= 0x31 && int32(v1) <= 0x33 {
				sub_4E4FC0(result)
			}
			result = v2
			if v2 == 0 {
				break
			}
		}
	}
	return result
}
func sub_4E4FC0(a1 int32) {
	var (
		v1 int32
		v2 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 412))))
	if v1 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v1 + 408))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 408)))
	} else {
		dword_5d4594_1565512 = *(*uint32)(unsafe.Pointer(uintptr(a1 + 408)))
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 408))))
	if v2 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v2 + 412))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 412)))
	} else {
		dword_5d4594_1565516 = *(*uint32)(unsafe.Pointer(uintptr(a1 + 412)))
	}
	nox_alloc_class_free_obj_first((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, 1565508)))), unsafe.Pointer(uintptr(a1)))
}
func nox_xxx_netSendPacket_4E5030(a1 int32, a2 unsafe.Pointer, a3 int32, a4 int32, a5 int32, a6 int8) int32 {
	var (
		v7  *byte
		v8  *byte
		v9  *uint16
		v10 int8
		v11 *uint8
		v12 *uint8
		v13 int32
		v14 int32
	)
	if a1 == math.MaxUint8 || (a1&0x80) == 0 || dword_5d4594_2649712&uint32(^(1<<(a1&math.MaxInt8))) != 0 {
		if a3 > 150 {
			return 0
		}
		v7 = *(**byte)(memmap.PtrOff(0x5D4594, 1565508))
		if *memmap.PtrUint32(0x5D4594, 1565508) == 0 {
			if nox_common_gameFlags_check_40A5C0(2048) {
				dword_5d4594_1565520 = 512
			} else {
				if nox_common_gameFlags_check_40A5C0(1) {
					dword_5d4594_1565520 = 3072
				} else {
					dword_5d4594_1565520 = 256
				}
			}
			if nox_common_gameFlags_check_40A5C0(2048) {
				v7 = (*byte)(unsafe.Pointer(nox_new_alloc_class_dynamic(internCStr("importantClass"), 416, *(*int32)(unsafe.Pointer(&dword_5d4594_1565520)))))
			} else {
				v7 = (*byte)(unsafe.Pointer(nox_new_alloc_class(internCStr("importantClass"), 416, *(*int32)(unsafe.Pointer(&dword_5d4594_1565520)))))
			}
			*memmap.PtrUint32(0x5D4594, 1565508) = uint32(uintptr(unsafe.Pointer(v7)))
		}
		v8 = (*byte)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(unsafe.Pointer(v7))))
		if v8 == nil {
			if nox_xxx_importantCheckRate_4E52B0() != 1 {
				return 0
			}
			v8 = (*byte)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(memmap.PtrOff(0x5D4594, 1565508))))))
			if v8 == nil {
				return 0
			}
		}
		alloc.Memcpy(unsafe.Add(unsafe.Pointer(v8), 251), a2, uintptr(a3))
		*(*byte)(unsafe.Add(unsafe.Pointer(v8), 401)) = byte(int8(a3))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*101))) = uint32(a4)
		*(*byte)(unsafe.Add(unsafe.Pointer(v8), 250)) = byte(int8(a1))
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*45))) = uint32(a5)
		*(*byte)(unsafe.Add(unsafe.Pointer(v8), 184)) = byte(a6)
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*43))) = 0
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*42))) = 0
		*(*byte)(unsafe.Add(unsafe.Pointer(v8), 164)) = 0
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*44))) = dword_5d4594_2649712
		libc.MemSet(unsafe.Add(unsafe.Pointer(v8), 4), 0, 0x80)
		v9 = (*uint16)(unsafe.Add(unsafe.Pointer(v8), 186))
		*(*uint32)(unsafe.Pointer(v8)) = gameFrame()
		libc.MemSet(unsafe.Add(unsafe.Pointer(v8), 186), 0, 0x40)
		if *(*byte)(unsafe.Add(unsafe.Pointer(v8), 184)) != 0 {
			if a1 == math.MaxUint8 {
				v10 = 0
				v11 = (*uint8)(memmap.PtrOff(0x5D4594, 1565524))
				for {
					if uint32(1<<int32(v10))&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*44))) != 0 {
						*v9 = func() uint16 {
							p := (*uint16)(unsafe.Pointer(v11))
							x := *p
							*p++
							return x
						}()
					}
					v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 2))
					v10++
					v9 = (*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*1))
					if int32(uintptr(unsafe.Pointer(v11))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1565588))) {
						break
					}
				}
			} else if (a1 & 0x80) == 0 {
				*(*uint16)(unsafe.Add(unsafe.Pointer(v8), a1*2+186)) = func() uint16 {
					p := mem_getU16Ptr(0x5D4594, uint32(a1*2)+1565524)
					x := *p
					*p++
					return x
				}()
			} else {
				v12 = (*uint8)(memmap.PtrOff(0x5D4594, 1565524))
				v13 = int32(*(*byte)(unsafe.Add(unsafe.Pointer(v8), 250)) & math.MaxInt8)
				v14 = 0
				for {
					if v14 != v13 && uint32(1<<v14)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*44))) != 0 {
						*v9 = func() uint16 {
							p := (*uint16)(unsafe.Pointer(v12))
							x := *p
							*p++
							return x
						}()
					}
					v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v12), 2))
					v14++
					v9 = (*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*1))
					if int32(uintptr(unsafe.Pointer(v12))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 1565588))) {
						break
					}
				}
			}
		}
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*103))) = 0
		*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*102))) = dword_5d4594_1565512
		if dword_5d4594_1565512 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1565512 + 412))) = uint32(uintptr(unsafe.Pointer(v8)))
			dword_5d4594_1565512 = uint32(uintptr(unsafe.Pointer(v8)))
			return 1
		}
		dword_5d4594_1565516 = uint32(uintptr(unsafe.Pointer(v8)))
		dword_5d4594_1565512 = uint32(uintptr(unsafe.Pointer(v8)))
	}
	return 1
}
func nox_xxx_importantCheckRate_4E52B0() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
		v3 uint16
		v4 uint32
		v5 int8
		v6 int32
		v8 [32]int16
	)
	v0 = 0
	v1 = int32(dword_5d4594_1565512)
	v8[0] = 0
	libc.MemSet(unsafe.Pointer(&v8[1]), 0, 0x3C)
	v2 = -1
	v3 = 0
	v8[31] = 0
	v4 = 999999999
	if dword_5d4594_1565512 == 0 {
		return 0
	}
	for {
		v5 = int8(*(*uint8)(unsafe.Pointer(uintptr(v1 + 250))))
		if int32(v5) != -1 && int32(v5) >= 0 && int32(v5) != 31 {
			v6 = int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 250))))
			if int32(uint16(func() int16 {
				p := &v8[v6]
				*p++
				return *p
			}())) > int32(v3) {
				v2 = v6
				v3 = uint16(v8[v6])
			}
		}
		if *(*uint32)(unsafe.Pointer(uintptr(v1))) < v4 {
			v4 = *(*uint32)(unsafe.Pointer(uintptr(v1)))
			v0 = v1
		}
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 408))))
		if v1 == 0 {
			break
		}
	}
	if v2 != -1 {
		nullsub_24(uint32(uintptr(memmap.PtrOff(0x587000, 202360))))
		nox_xxx_playerKickDueToRate_4E5360(v2)
	}
	if v0 == 0 {
		return 0
	}
	sub_4E4FC0(v0)
	return 1
}
func nox_xxx_playerKickDueToRate_4E5360(a1 int32) *byte {
	var (
		result *byte
		v2     *byte
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	v2 = result
	if result != nil {
		sub_4E55F0(uint8(int8(a1)))
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_netNeedTimestampStatus_4174F0((*nox_playerInfo)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 128))))
	}
	return result
}
func nox_xxx_netSendPacket1_4E5390(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32) int32 {
	return nox_xxx_netSendPacket_4E5030(a1, unsafe.Pointer(uintptr(a2)), a3, a4, a5, 1)
}
func nox_xxx_netClientSend2_4E53C0(a1 int32, a2 unsafe.Pointer, a3 int32, a4 int32, a5 int32) int32 {
	var result int32
	if nox_common_gameFlags_check_40A5C0(1) {
		nox_netlist_addToMsgListCli_40EBC0(a1, 0, (*uint8)(a2), a3)
		result = 1
	} else if a1 == math.MaxUint8 || (a1&0x80) != 0 {
		result = 0
	} else {
		result = nox_xxx_netSendPacket0_4E5420(a1, a2, a3, a4, a5)
	}
	return result
}
func nox_xxx_netSendPacket0_4E5420(a1 int32, a2 unsafe.Pointer, a3 int32, a4 int32, a5 int32) int32 {
	return nox_xxx_netSendPacket_4E5030(a1, a2, a3, a4, a5, 0)
}
func sub_4E5450(a1 int32, a2 *byte, a3 int32, a4 int32, a5 int32) int32 {
	var (
		v5 *byte
		v6 int32
		v7 int32
		v9 int8
	)
	v5 = a2
	v9 = int8(*a2)
	v6 = int32(dword_5d4594_1565512)
	if dword_5d4594_1565512 != 0 {
		for {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 408))))
			if int32(v9) == int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 251)))) {
				if a1 == math.MaxUint8 || (a1&0x80) != 0 {
					sub_4E4FC0(v6)
				} else {
					sub_4E54D0(1<<a1, v6, a1)
				}
			}
			v6 = v7
			if v7 == 0 {
				break
			}
		}
	}
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(v5), a3, a4, a5)
}
func sub_4E54D0(a1 int32, a2 int32, a3 int32) {
	var (
		v3 int32
		v4 int8
		v5 int32
		v6 int8
		v7 int32
		v8 int32
		v9 int32
	)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 404))))
	if v3 != 0 {
		v4 = int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 251))))
		if int32(v4) == 49 || int32(v4) == 50 || int32(v4) == 51 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 148))) &= uint32(^a1)
		}
	}
	v5 = int32(dword_5d4594_2649712 & *(*uint32)(unsafe.Pointer(uintptr(a2 + 176))))
	v6 = int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 250))))
	if int32(v6) == -1 {
		v7 = int32(uint32(a1) | *(*uint32)(unsafe.Pointer(uintptr(a2 + 168))))
		*(*uint32)(unsafe.Pointer(uintptr(a2 + 168))) = uint32(v7)
		if (v5 & v7) == v5 {
			sub_4E4FC0(a2)
		}
	} else if int32(v6) >= 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 250)))) == a3 {
			sub_4E4FC0(a2)
		}
	} else {
		v8 = 1 << (int32(v6) & math.MaxInt8)
		v9 = int32(uint32(a1) | *(*uint32)(unsafe.Pointer(uintptr(a2 + 168))))
		*(*uint32)(unsafe.Pointer(uintptr(a2 + 168))) = uint32(v9)
		if (v5 & ^v8 & v9) == (v5 & ^v8) {
			sub_4E4FC0(a2)
		}
	}
}
func nox_net_importantACK_4E55A0(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
	)
	result = int32(dword_5d4594_1565512)
	if dword_5d4594_1565512 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 408))))
			if *(*uint32)(unsafe.Pointer(uintptr(result + a1*4 + 4))) == uint32(a2) {
				sub_4E54D0(1<<a1, result, a1)
			}
			result = v3
			if v3 == 0 {
				break
			}
		}
	}
	return result
}
func sub_4E55F0(a1 uint8) int32 {
	var (
		result int32
		v2     int32
	)
	result = int32(dword_5d4594_1565512)
	if dword_5d4594_1565512 != 0 {
		for {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 408))))
			sub_4E54D0(1<<int32(a1), result, int32(a1))
			result = v2
			if v2 == 0 {
				break
			}
		}
	}
	return result
}
func nox_xxx_importantCheckRate2_4E5670(a1 uint8) uint32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		v4     int8
		v5     *uint8
		v6     uint8
		result uint32
		v8     int32
		v9     uint8
	)
	v1 = 0
	nox_common_playerInfoFromNum_417090(int32(a1))
	v2 = int32(dword_5d4594_1565516)
	if dword_5d4594_1565516 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 412))))
			if (*(*uint32)(unsafe.Pointer(uintptr(v2 + 168))) & uint32(1<<int32(a1))) == 0 {
				v4 = int8(*(*uint8)(unsafe.Pointer(uintptr(v2 + 250))))
				if int32(v4) == -1 {
					v1++
					goto LABEL_9
				}
				if int32(v4) >= 0 {
					if int32(v4) == int32(a1) {
						v1++
						goto LABEL_9
					}
				} else if int32(a1) != (int32(v4) & math.MaxInt8) {
					v1++
					goto LABEL_9
				}
			}
		LABEL_9:
			v2 = v3
			if v3 == 0 {
				break
			}
		}
	}
	v5 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(int32(a1)*12)+1565124))
	if nox_xxx_rateGet_40A6C0() != int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 2))) {
		*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 2)) = uint8(int8(nox_xxx_rateGet_40A6C0()))
	}
	if uint32(v1) <= *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1))) {
		v8 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*2))))
		if v8 > 0 && v1 < v8 {
			if int32(*v5) == 2 {
				*v5 = 1
				return uint32(sub_4E4E50(int32(a1)))
			}
			v9 = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1))) - 1))
			*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)) = v9
			if int32(v9) < 2 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)) = 2
			}
		}
		result = uint32(sub_4E4E50(int32(a1)))
	} else {
		v6 = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1))) + 1))
		*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)) = v6
		if int32(v6) > 5 {
			if int32(*v5) == 2 {
				nox_xxx_playerKickDueToRate_4E5360(int32(a1))
			}
			*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)) = 5
			*v5 = 2
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 2)) = uint8(int8(nox_xxx_rateGet_40A6C0()))
		result = uint32(sub_4E4E50(int32(a1)))
	}
	return result
}
func nox_xxx_netImportant_4E5770(a1 uint8, a2 int32) {
	var (
		v2  int32
		v3  *byte
		v4  int32
		v5  int32
		v6  int8
		v7  int32
		v8  int8
		v9  int8
		v10 int32
		v11 int32
		v12 [1]byte
		v13 func(int32, int32, *uint8, int32) int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 [5]byte
	)
	v2 = 1 << int32(a1)
	v15 = 1
	v14 = 0
	v16 = 1 << int32(a1)
	v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(int32(a1))))
	v13 = nox_netlist_addToMsgListCli_40EBC0
	if int32(a1) != 31 {
		v13 = nox_netlist_clientSendWrap_40ECA0
	}
	if v3 == nil || !nox_common_gameFlags_check_40A5C0(1) || *(*byte)(unsafe.Add(unsafe.Pointer(v3), 3680))&0x10 != 0 {
		v4 = int32(dword_5d4594_1565516)
		if dword_5d4594_1565516 != 0 {
			for {
				v17 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 412))))
				v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 404))))
				if v5 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 16))))&0x20 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v4 + 404))) = 0
				}
				if uint32(v2)&*(*uint32)(unsafe.Pointer(uintptr(v4 + 168))) != 0 {
					goto LABEL_39
				}
				v6 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 250))))
				if int32(v6) != -1 {
					if int32(v6) >= 0 {
						if int32(v6) != int32(a1) {
							goto LABEL_39
						}
					} else if int32(a1) == (int32(v6) & math.MaxInt8) {
						goto LABEL_39
					}
				}
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 404))))
				if v7 != 0 && (uint32(v2)&*(*uint32)(unsafe.Pointer(uintptr(v7 + 148)))) == 0 || *(*uint32)(unsafe.Pointer(uintptr(v4 + 180))) != 0 && (uint32(v2)&dword_5d4594_2649712) == 0 {
					sub_4E54D0(v2, v4, int32(a1))
					return
				}
				if (uint32(v2) & *(*uint32)(unsafe.Pointer(uintptr(v4 + 172)))) == 0 {
					goto LABEL_24
				}
				v8 = int8(*(*uint8)(unsafe.Pointer(uintptr(int32(a1) + v4 + 132))))
				if int32(v8) != 0 {
					*(*uint8)(unsafe.Pointer(uintptr(int32(a1) + v4 + 132))) = uint8(int8(int32(v8) - 1))
					goto LABEL_39
				}
				if v14 >= int32(*memmap.PtrUint8(0x5D4594, uintptr(int32(a1)*12)+1565124)) {
					goto LABEL_39
				}
				v9 = int8(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 164)))) + 1)
				v10 = v14 + 1
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 172))) &= uint32(^v2)
				*(*uint8)(unsafe.Pointer(uintptr(v4 + 164))) = uint8(v9)
				v14 = v10
			LABEL_24:
				if v15 != 0 {
					if a2 != 0 && int32(a1) != 31 {
						v12[0] = 170
						if v13(int32(a1), a2, (*uint8)(unsafe.Pointer(&v12[0])), 1) == 0 {
							return
						}
					} else {
						v18[0] = 170
						*(*uint32)(unsafe.Pointer(&v18[1])) = gameFrame()
						if v13(int32(a1), a2, (*uint8)(unsafe.Pointer(&v18[0])), 5) == 0 {
							return
						}
					}
					v15 = 0
				}
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 184)))) == 0 {
					v11 = v13(int32(a1), a2, (*uint8)(unsafe.Pointer(uintptr(v4+251))), int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 401)))))
					goto LABEL_36
				}
				*memmap.PtrUint8(0x5D4594, 1564964) = 204
				*memmap.PtrUint16(0x5D4594, 1564965) = *(*uint16)(unsafe.Pointer(uintptr(v4 + int32(a1)*2 + 186)))
				*memmap.PtrUint8(0x5D4594, 1564967) = *(*uint8)(unsafe.Pointer(uintptr(v4 + 401)))
				alloc.Memcpy(memmap.PtrOff(0x5D4594, 1564968), unsafe.Pointer(uintptr(v4+251)), uintptr(*(*uint8)(unsafe.Pointer(uintptr(v4 + 401)))))
				v11 = v13(int32(a1), a2, (*uint8)(memmap.PtrOff(0x5D4594, 1564964)), int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 401))))+4)
				v2 = v16
			LABEL_36:
				if v11 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v4 + 172))) |= uint32(v2)
					*(*uint8)(unsafe.Pointer(uintptr(int32(a1) + v4 + 132))) = uint8(gameFPS() * uint32(*memmap.PtrUint8(0x5D4594, uintptr(int32(a1)*12)+1565125)) / uint32(nox_xxx_rateGet_40A6C0()))
					*(*uint32)(unsafe.Pointer(uintptr(v4 + int32(a1)*4 + 4))) = gameFrame()
					if nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_REPLAY_READ)) {
						sub_4E54D0(v2, v4, int32(a1))
					}
				}
			LABEL_39:
				v4 = v17
				if v17 == 0 {
					goto LABEL_40
				}
			}
		}
	LABEL_40:
		if nox_common_gameFlags_check_40A5C0(1) && (gameFrame()%(gameFPS()*uint32(*memmap.PtrUint8(0x5D4594, uintptr(int32(a1)*12)+1565125)))) == 0 {
			nox_xxx_importantCheckRate2_4E5670(a1)
		}
	}
}
func nox_xxx_playerRemoveSpawnedStuff_4E5AD0(a1p *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int8
		v2 int32
		v3 int32
	)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		v1 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 2251))))
		if int32(v1) == 1 {
			sub_4E5F40(a1)
		} else if int32(v1) == 2 {
			sub_4E5FC0(a1)
		}
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516))))
	if v2 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 512))))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&1 != 0 || sub_4E3B80(int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4))))) == 0 {
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
			}
			v2 = v3
			if v3 == 0 {
				break
			}
		}
	}
}
func nox_xxx_isUnit_4E5B50(a1p *nox_object_t) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1     int32
		result int32
	)
	result = 0
	if !nox_common_gameFlags_check_40A5C0(0x2000) {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 {
			v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
			if v1&0x100 != 0 {
				result = 1
			}
		}
	}
	return result
}
func sub_4E5B80(a1p *nox_object_t) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1     int32
		result int32
	)
	if *memmap.PtrUint32(0x5D4594, 1565592) == 0 {
		*memmap.PtrUint32(0x5D4594, 1565592) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Pixie")))
	}
	result = 0
	if a1 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&1 != 0 {
			if nox_common_gameFlags_check_40A5C0(2048) {
				if uint32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == *memmap.PtrUint32(0x5D4594, 1565592) {
					v1 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
					if v1 != 0 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))))&4 != 0 {
							result = 1
						}
					}
				}
			}
		}
	}
	return result
}
func sub_4E5BF0(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1565596) == 0 {
		*memmap.PtrUint32(0x5D4594, 1565596) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Moonglow")))
	}
	v1 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v1 != 0 {
		for {
			v2 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(v1)))))))
			if a1 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))))&4) == 0 && ((func() int32 {
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 492))))
				return v3
			}()) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8))))&4) == 0) && (uint32(*(*uint16)(unsafe.Pointer(uintptr(v1 + 4)))) != *memmap.PtrUint32(0x5D4594, 1565596) || (func() int32 {
				v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 508))))
				return v4
			}()) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&4) == 0) && nox_xxx_isUnit_4E5B50((*nox_object_t)(unsafe.Pointer(uintptr(v1)))) == 0 {
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
			}
			v1 = v2
			if v2 == 0 {
				break
			}
		}
	}
	var obj *nox_object_t = nox_xxx_getFirstUpdatable2Object_4DA840()
	if obj != nil {
		for {
			{
				var v6 *nox_object_t = nox_xxx_getNextUpdatable2Object_4DA850(obj)
				if a1 != 1 || sub_4E5B80(obj) == 0 {
					nox_xxx_delayedDeleteObject_4E5CC0(obj)
				}
				obj = v6
			}
			if obj == nil {
				break
			}
		}
	}
}
func sub_4E5F40(a1 int32) int32 {
	var (
		result int32
		i      int32
	)
	if *memmap.PtrUint32(0x5D4594, 1565600) == 0 {
		*memmap.PtrUint32(0x5D4594, 1565600) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	for i = result; result != 0; i = result {
		if nox_xxx_unitHasThatParent_4EC4F0((*nox_object_t)(unsafe.Pointer(uintptr(i))), (*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 && uint32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) == *memmap.PtrUint32(0x5D4594, 1565600) && (int32(*(*uint8)(unsafe.Pointer(uintptr(i + 16))))&0x20) == 0 {
			nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(i+56))))
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(i))))
		}
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(i)))))))
	}
	return result
}
func sub_4E5FC0(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516))))
	if v1 != 0 {
		for {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 512))))
			if nox_xxx_creatureIsMonitored_500CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(v1)))) != 0 {
				v3 = nox_xxx_inventoryGetFirst_4E7980(v1)
				if v3 != 0 {
					for {
						v4 = nox_xxx_inventoryGetNext_4E7990(v3)
						nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
						v3 = v4
						if v4 == 0 {
							break
						}
					}
				}
				nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(v1+56))))
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
			}
			v1 = v2
			if v2 == 0 {
				break
			}
		}
	}
}
func sub_4E6150(a1p *nox_playerInfo) *nox_object_t {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1     int32
		v2     int32
		i      int32
		v4     *byte
		result int32
		v6     *byte
	)
	if dword_5d4594_1565616 == 0 {
		dword_5d4594_1565616 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
	}
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 3628))))
	if v1 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))))&4 != 0 {
			v2 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 3628))))))))))
			goto LABEL_7
		}
	} else if nox_common_gameFlags_check_40A5C0(64) {
		v2 = sub_4E6230()
		if v2 != 0 {
			goto LABEL_7
		}
	}
	v2 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
LABEL_7:
	i = v2
	if v2 == 0 {
		goto LABEL_16
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 8))))&4 != 0 {
		for {
			v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Pointer(uintptr(i + 36)))))))
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(i + 16))))&0x20) == 0 && (*(*byte)(unsafe.Add(unsafe.Pointer(v4), 3680))&1) == 0 {
				break
			}
			i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(i)))))))
			if i == 0 {
				goto LABEL_16
			}
		}
	}
	if i != 0 {
		return (*nox_object_t)(unsafe.Pointer(uintptr(i)))
	}
LABEL_16:
	result = sub_4E6230()
	if result != 0 {
		return (*nox_object_t)(unsafe.Pointer(uintptr(result)))
	}
	for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(i))))))) {
		v6 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint32)(unsafe.Pointer(uintptr(i + 36)))))))
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(i + 16))))&0x20) == 0 && (*(*byte)(unsafe.Add(unsafe.Pointer(v6), 3680))&1) == 0 {
			break
		}
	}
	return (*nox_object_t)(unsafe.Pointer(uintptr(i)))
}
func sub_4E6230() int32 {
	var result int32
	if dword_5d4594_1565616 == 0 {
		dword_5d4594_1565616 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))
	}
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if result == 0 {
		return 0
	}
	for uint32(*(*uint16)(unsafe.Pointer(uintptr(result + 4)))) != dword_5d4594_1565616 {
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
		if result == 0 {
			return 0
		}
	}
	return result
}
func nox_xxx_playerObserverFindGoodSlave0_4E6280(a1p *nox_playerInfo) *nox_object_t {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result int32
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 3628))) != 0 {
		result = nox_xxx_playerObserverFindGoodSlave_4EC420(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 3628)))))
	} else {
		result = nox_xxx_playerObserverFindGoodSlave2_4EC3E0(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056)))))
	}
	if result != 0 {
		for *(*uint32)(unsafe.Pointer(uintptr(result + 16)))&0x8020 != 0 {
			result = nox_xxx_playerObserverFindGoodSlave_4EC420(result)
			if result == 0 {
				goto LABEL_9
			}
		}
		return (*nox_object_t)(unsafe.Pointer(uintptr(result)))
	}
LABEL_9:
	for result = nox_xxx_playerObserverFindGoodSlave2_4EC3E0(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056))))); result != 0; result = nox_xxx_playerObserverFindGoodSlave_4EC420(result) {
		if (*(*uint32)(unsafe.Pointer(uintptr(result + 16))) & 0x8020) == 0 {
			break
		}
	}
	return (*nox_object_t)(unsafe.Pointer(uintptr(result)))
}
func nox_xxx_playerLeaveObserver_0_4E6AA0(pl *nox_playerInfo) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(pl)))
		v1 int32
		v2 int32
		v3 int32
		i  *uint32
	)
	if a1 != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056))))
		if v1 != 0 {
			if funAddr(*(*func(*uint32) int32)(unsafe.Pointer(uintptr(v1 + 744)))) != funAddr(nox_xxx_updatePlayerMonsterBot_4FAB20) {
				nox_xxx_playerUnsetStatus_417530((*nox_playerInfo)(unsafe.Pointer(uintptr(a1))), 289)
				nox_xxx_spellBuffOff_4FF5B0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), 0)
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))))
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 744))) = uint32(funAddr(nox_xxx_updatePlayer_4F8100))
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))) = uint32(v2) & 0xFFFFFFBF
				nox_xxx_monsterMarkUpdate_4E8020((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056)))))))
				if nox_common_gameFlags_check_40A5C0(16) {
					if nox_xxx_CheckGameplayFlags_417DA0(4) {
						v3 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056))) + 52)))))))), 4*19))))
						if v3 != 0 {
							if *(*uint32)(unsafe.Pointer(uintptr(v3 + 492))) == 0 {
								sub_4F3400(int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 2056)))), v3, 1)
							}
						}
					}
				}
				if nox_common_gameFlags_check_40A5C0(49152) && sub_509D80(a1) == 0 {
					sub_509C30((*nox_playerInfo)(unsafe.Pointer(uintptr(a1))))
				}
				if nox_common_gameFlags_check_40A5C0(4096) {
					for i = (*uint32)(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())); i != nil; i = (*uint32)(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(i))))))))) {
						if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*187)) + 276))) + 4792))) == 1 {
							nox_xxx_netReportEnchant_4D8F90(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 2064)))), i)
						}
					}
				}
			}
		}
	}
}
func sub_4E6BD0(a1 int32) int32 {
	return bool2int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) != 0 && (gameFrame()-*(*uint32)(unsafe.Pointer(uintptr(a1 + 536)))) <= 1)
}
func nox_xxx_calcDistance_4E6C00(a1p *nox_object_t, a2p *nox_object_t) float64 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2     int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v2     float64
		v3     float64
		v4     int32
		v5     float64
		result float64
		v7     float64
		v8     int32
		v9     float64
		v10    float32
		v11    float32
	)
	v2 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
	v3 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a2 + 60))))
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 172))))
	v5 = math.Sqrt(v3*v3 + v2*v2)
	result = v5
	if v4 == 2 {
		result = v5 - float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 176))))
	} else if v4 == 3 {
		v7 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) * 0.5
		v10 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) * 0.5)
		if v7 <= float64(v10) {
			v7 = float64(v10)
		}
		result = v5 - v7
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 172))))
	if v8 == 2 {
		result = result - float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 176))))
	} else if v8 == 3 {
		v9 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 184)))) * 0.5
		v11 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 188)))) * 0.5)
		if v9 <= float64(v11) {
			v9 = float64(v11)
		}
		result = result - v9
	}
	if result < 0.0099999998 {
		result = 0.0099999998
	}
	return result
}
func sub_4E6CE0(a1 *float2, a2 *float2) int32 {
	var (
		v2     float64
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		result int32
	)
	*(*float32)(unsafe.Pointer(&dword_5d4594_1565628)) = a2.field_0 - a1.field_0
	*(*float32)(unsafe.Pointer(&dword_5d4594_1565632)) = a2.field_4 - a1.field_4
	*mem_getFloatPtr(0x5D4594, 1565652) = float32(float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565628)))*0.41304299 - float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565632))))
	v2 = float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565628)))*2.4210529 - float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565632)))
	*mem_getFloatPtr(0x5D4594, 1565656) = float32(v2)
	*mem_getFloatPtr(0x5D4594, 1565636) = float32(float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565628)))*(-2.4210529) - float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565632))))
	*mem_getFloatPtr(0x5D4594, 1567708) = float32(float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565628)))*(-0.41304299) - float64(*(*float32)(unsafe.Pointer(&dword_5d4594_1565632))))
	if float64(*mem_getFloatPtr(0x5D4594, 1565652)) < 0.0 {
		v3 = 0
	} else {
		v3 = 8
	}
	if v2 < 0.0 {
		v4 = 0
	} else {
		v4 = 4
	}
	v5 = v4 | v3
	if float64(*mem_getFloatPtr(0x5D4594, 1565636)) < 0.0 {
		v6 = 0
	} else {
		v6 = 2
	}
	*memmap.PtrUint32(0x5D4594, 1565640) = uint32(bool2int32(float64(*mem_getFloatPtr(0x5D4594, 1567708)) >= 0.0) | v6 | v5)
	switch *memmap.PtrUint32(0x5D4594, 1565640) {
	case 0:
		result = 2
	case 2:
		result = 6
	case 3:
		result = 4
	case 4:
		result = 10
	case 0xB:
		result = 5
	case 0xC:
		result = 8
	case 0xD:
		result = 9
	case 0xF:
		result = 1
	default:
		result = 0
	}
	return result
}
func nox_server_testTwoPointsAndDirection_4E6E50(a1 *float2, a2 int32, a3 *float2) int32 {
	var (
		v3 int32
		v5 [2]int32
	)
	nox_xxx_xferIndexedDirection_509E20(a2, (*int2)(unsafe.Pointer(&v5[0])))
	v3 = v5[1] + v5[0] + v5[1]*2 + 4
	return int32(*memmap.PtrUint32(0x587000, uintptr((sub_4E6CE0(a1, a3)+v3*16)*4)+202504))
}
func nox_xxx_unitMove_4E7010(obj *nox_object_t, a2 *float2) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v2 int32
		v3 int32
		v4 int32
		v5 [5]byte
	)
	if a1 != 0 && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x400000) == 0 {
		if int64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))) != int64(a2.field_0) || int64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))) != int64(a2.field_4) {
			nox_xxx_unitNeedSync_4E44F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
		*(*float2)(unsafe.Pointer(uintptr(a1 + 64))) = *a2
		*(*float2)(unsafe.Pointer(uintptr(a1 + 56))) = *a2
		*(*float2)(unsafe.Pointer(uintptr(a1 + 72))) = *a2
		nox_xxx_moveUpdateSpecial_517970((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 696))) != 0 {
			nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 {
			sub_537540(a1)
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 {
			sub_5346D0(a1)
		}
		nox_xxx_teleportAllPixies_4FD090((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 {
			nox_xxx_frameCounterSetCopyToNextFrame_5281D0()
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && nox_common_gameFlags_check_40A5C0(0x2000) {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))))
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 272))) = gameFrame()
			sub_4DE4D0(int8(*(*uint8)(unsafe.Pointer(uintptr(v3 + 2064)))))
			v5[0] = 234
			*(*uint32)(unsafe.Pointer(&v5[1])) = gameFrame()
			nox_xxx_netSendPacket1_4E5390(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), int32(uintptr(unsafe.Pointer(&v5[0]))), 5, 0, 0)
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
			if *(*uint32)(unsafe.Pointer(uintptr(v4 + 3628))) == 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 3680))))&3) == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 3632))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 56)))
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 3636))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 60)))
			}
		}
	}
}
func nox_xxx_teleportToMB_4E7190(a1 *uint8, a2 *float32) {
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 14) == 0 && (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 16)))&2) == 0 && (!nox_common_gameFlags_check_40A5C0(4096) || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&2) == 0 || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 12)))&8) == 0) && (nox_common_gameFlags_check_40A5C0(2048) || int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a1), 8)))&6 != 0) {
		nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), (*float2)(unsafe.Pointer(a2)))
	}
}
func nox_xxx_objectUnkUpdateCoords_4E7290(a1p *nox_object_t) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result int32
		v2     int32
		v3     int32
		v4     int32
	)
	result = a1
	switch *(*uint32)(unsafe.Pointer(uintptr(a1 + 172))) {
	case 1:
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 56))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 232))) = uint32(v2)
		v3 = v2
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 60))))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 240))) = uint32(v3)
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 236))) = uint32(v4)
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 244))) = uint32(v4)
	case 2:
		*(*float32)(unsafe.Pointer(uintptr(a1 + 232))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 176)))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 236))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 176)))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 240))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 176))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 244))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 176))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
	case 3:
		*(*float32)(unsafe.Pointer(uintptr(a1 + 232))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 200))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 236))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 196))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 240))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 208))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 244))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 220))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
	}
	return result
}
func nox_xxx_spawnSomeBarrel_4E7470(a1 int32, a2 int32) {
	var (
		v2     *byte
		v3     *uint8
		v4     int32
		v5     int32
		v6     *uint8
		v7     *uint8
		v8     int32
		result *byte
		v10    int32
		i      int32
		v12    *uint32
		a3     float2
	)
	v2 = nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	v3 = (*uint8)(memmap.PtrOff(0x587000, 203080))
	if libc.StrNCmp(v2, internCStr("Barrel"), 6) != 0 {
		v3 = (*uint8)(memmap.PtrOff(0x587000, 203240))
	}
	v4 = nox_common_randomInt_415FA0(0, 99)
	v5 = 0
	if *(*uint32)(unsafe.Pointer(v3)) != 0 {
		v6 = v3
		v7 = v3
		for {
			if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*2))) > uint32(v4) {
				break
			}
			v8 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*3))))
			v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 12))
			v5++
			v6 = v7
			if v8 == 0 {
				break
			}
		}
	}
	result = *(**byte)(unsafe.Add(unsafe.Pointer(v3), v5*12))
	v10 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v3), v5*12)))))
	if result != nil {
		result = *(**byte)(unsafe.Pointer(uintptr(v10 + 4)))
		for i = 0; i < int32(uintptr(unsafe.Pointer(result))); i++ {
			v12 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(unsafe.Pointer(uintptr(v10))))))
			if v12 != nil {
				sub_4ED970(35.0, (*float2)(unsafe.Pointer(uintptr(a2))), &a3)
				nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v12)))))), nil, a3.field_0, a3.field_4)
			}
			result = *(**byte)(unsafe.Pointer(uintptr(v10 + 4)))
		}
	}
}
func sub_4E7540(a1p *nox_object_t, a2p *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3 int32
	)
	if a1 != 0 {
		if a2 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 && a1 != a2 {
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 3604))) = uint32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 2064))))
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 3608))) = gameFrame()
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 3600))) = 1
			}
		}
	}
}
func nox_xxx_objectSetOn_4E75B0(obj *nox_object_t) int8 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v1 int32
		v2 int32
	)
	if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) & 0x1000000) == 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v1&0x4000 != 0 {
			nox_xxx_aud_501960(235, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
	nox_xxx_unitSetOnOff_4E4670(a1, 1)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if uint32(v2)&0x10042000 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) &= 0xFFFFFFBF
	}
	if (v2 & 1) == 0 {
		*((*uint8)(unsafe.Pointer(&v2))) = uint8(nox_xxx_unitHasCollideOrUpdateFn_537610((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))
	}
	return int8(v2)
}
func nox_xxx_objectSetOff_4E7600(obj *nox_object_t) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(obj)))
		v1     int32
		result int32
	)
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x1000000 != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v1&0x4000 != 0 {
			nox_xxx_aud_501960(236, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
	nox_xxx_unitSetOnOff_4E4670(a1, 0)
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if uint32(result)&0x10042000 != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
		*((*uint8)(unsafe.Pointer(&result))) = uint8(int8(result | 0x40))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = uint32(result)
	}
	return result
}
func sub_4E7700(a1 int32) int32 {
	var (
		v1     *uint16
		result int32
	)
	v1 = *(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 340))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 248))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 120))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 128))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 132))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 148))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 152))) ^ uint32(*(*int16)(unsafe.Pointer(uintptr(a1 + 124)))) ^ uint32(*(*int16)(unsafe.Pointer(uintptr(a1 + 126)))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 108))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 104))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 100))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 96))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 92))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 88))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 84))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 80))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 76))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 72))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 68))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 64))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 60))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 20))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 36))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 40))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 44))) ^ *(*uint32)(unsafe.Pointer(uintptr(a1 + 56))) ^ uint32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) ^ uint32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))))
	if v1 != nil {
		result ^= int32(*v1) ^ int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*1))) ^ int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2)))
	}
	return result
}
func nox_xxx_inventoryGetFirst_4E7980(a1 int32) int32 {
	return int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
}
func nox_xxx_inventoryGetNext_4E7990(a1 int32) int32 {
	var result int32
	if a1 != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 496))))
	} else {
		result = 0
	}
	return result
}
func sub_4E79B0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 1567712) = uint32(a1)
	return result
}
func nox_xxx_unitFreeze_4E79C0(obj *nox_object_t, a2 int32) int8 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v2 int32
		i  int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if (v2 & 2) == 0 {
		*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(v2 | 2))
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = uint32(v2)
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			if *memmap.PtrUint32(0x5D4594, 1567712) == 0 {
				*memmap.PtrUint32(0x5D4594, 1567712) = uint32(a2)
			}
			nox_xxx_netReportPlrStatus_4D8270(a1)
			nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 13)
			nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0.0)
			sub_50B510()
			for i = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516)))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 512)))) {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(i + 8))))&2 != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(i + 748))) + 1440))))&0x80) != 0 {
					nox_xxx_unitFreeze_4E79C0((*nox_object_t)(unsafe.Pointer(uintptr(i))), a2)
				}
			}
		}
		*((*uint8)(unsafe.Pointer(&v2))) = *(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))
		if v2&2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
			if (v2 & 0x8000) == 0 {
				*((*uint8)(unsafe.Pointer(&v2))) = uint8(uint32(uintptr(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0))))
			}
		}
	}
	return int8(v2)
}
func nox_xxx_unitUnFreeze_4E7A60(obj *nox_object_t, a2 int32) int8 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v2 int32
		i  int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if v2&2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			*((*uint8)(unsafe.Pointer(&v2))) = *memmap.PtrUint8(0x5D4594, 1567712)
			if *memmap.PtrUint32(0x5D4594, 1567712) != 0 && a2 == 0 {
				return int8(v2)
			}
			*memmap.PtrUint32(0x5D4594, 1567712) = 0
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) &= 0xFFFFFFFD
			*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_xxx_netReportPlrStatus_4D8270(a1)))
			for i = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516)))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 512)))) {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(i + 8))))&2 != 0 {
					v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 748))))
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 1440))))&0x80 != 0 {
						*((*uint8)(unsafe.Pointer(&v2))) = uint8(nox_xxx_unitUnFreeze_4E7A60((*nox_object_t)(unsafe.Pointer(uintptr(i))), a2))
					}
				}
			}
		} else {
			*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(v2 & 0xFD))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = uint32(v2)
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
			if (v2 & 0x8000) == 0 {
				*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(nox_xxx_monsterPopAction_50A160((*nox_object_t)(unsafe.Pointer(uintptr(a1))))))
			}
		}
	}
	return int8(v2)
}
func nox_xxx_unitBecomePet_4E7B00(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
	)
	if a1 != 0 {
		if a2 != 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))))
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(v2 | 0x80))
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 12))) = uint32(v2)
			nox_xxx_netMonitorCreature_4D9250(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), a2)
			nox_xxx_netMarkMinimapObject_417190(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 1)
			nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))))
		}
	}
}
func nox_xxx_monsterRemoveMonitors_4E7B60(a1p *nox_object_t, a2p *nox_object_t) {
	var (
		a1 int32   = int32(uintptr(unsafe.Pointer(a1p)))
		a2 *uint32 = (*uint32)(unsafe.Pointer(a2p))
		v2 int32
		v3 int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if a1 != 0 {
		if a2 != nil {
			v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)))
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(int8(v3 & math.MaxInt8))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)) = uint32(v3)
			nox_xxx_netSendUnMonitorCrea_4D92A0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), a2)
			nox_xxx_netUnmarkMinimapObj_417300(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))), 1)
			nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))))
		}
	}
}
func sub_4E7BC0(a1 int32) int32 {
	var result int32
	result = a1
	if a1 != 0 {
		result = int32((*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))) >> 2) & 1)
	}
	return result
}
func nox_xxx_unitIsCrown_4E7BE0(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 1567716))
	if *memmap.PtrUint32(0x5D4594, 1567716) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("Crown"))
		*memmap.PtrUint32(0x5D4594, 1567716) = uint32(v1)
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516))))
	if v2 == 0 {
		return 0
	}
	for int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4)))) != v1 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 512))))
		if v2 == 0 {
			return 0
		}
	}
	return 1
}
func nox_xxx_unitIsGameball_4E7C30(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = int32(*memmap.PtrUint32(0x5D4594, 1567720))
	if *memmap.PtrUint32(0x5D4594, 1567720) == 0 {
		v1 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
		*memmap.PtrUint32(0x5D4594, 1567720) = uint32(v1)
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516))))
	if v2 == 0 {
		return 0
	}
	for int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4)))) != v1 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 512))))
		if v2 == 0 {
			return 0
		}
	}
	return 1
}
func nox_xxx_unitCountSlaves_4E7CF0(a1 int32, a2 int32, a3 int32) int32 {
	var (
		result int32
		i      *uint32
	)
	result = 0
	if a1 == 0 || a2 == 0 || a3 == 0 {
		return 0
	}
	for i = *(**uint32)(unsafe.Pointer(uintptr(a1 + 516))); i != nil; i = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*128))))) {
		if uint32(a2)&*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*2)) != 0 {
			if uint32(a3)&*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*3)) != 0 {
				result++
			}
		}
	}
	return result
}
func nox_xxx_inventoryCountObjects_4E7D30(a1 int32, a2 int32) int32 {
	var (
		result int32
		i      int32
	)
	result = 0
	if a1 != 0 {
		for i = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504)))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 496)))) {
			if a2 == 0 || int32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) == a2 && (int32(*(*uint8)(unsafe.Pointer(uintptr(i + 16))))&0x20) == 0 {
				result++
			}
		}
	}
	return result
}
func sub_4E7DE0(a1 int32, item *nox_object_t) int32 {
	var (
		v2 int32
		v3 *uint32
		v4 int32
		v5 int32
		v6 int32
		v7 bool
	)
	if a1 == 0 || item == nil || int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) != int32(item.typ_ind) {
		return 0
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if uint32(v2)&0x13001000 != 0 {
		v3 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 692)))
		v4 = 0
		v5 = int32(uint32(int32(uintptr(item.init_data))) - uint32(uintptr(unsafe.Pointer(v3))))
		for *v3 == *(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v3))), v5)))) {
			v4++
			v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
			if v4 >= 4 {
				goto LABEL_8
			}
		}
		return 0
	}
LABEL_8:
	if (v2 & 0x100) == 0 {
		return 1
	}
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
	if v6&1 != 0 {
		v7 = int32(**(**uint8)(unsafe.Pointer(uintptr(a1 + 736)))) == int32(*(*uint8)(item.use_data))
	} else {
		if (v6 & 2) == 0 {
			if int32(**(**uint8)(unsafe.Pointer(uintptr(a1 + 736)))) != int32(*(*uint8)(item.use_data)) {
				return 0
			}
			return 1
		}
		v7 = libc.StrCmp(*(**byte)(unsafe.Pointer(uintptr(a1 + 736))), (*byte)(item.use_data)) == 0
	}
	if !v7 {
		return 0
	}
	return 1
}
func sub_4E7EC0(a1 int32, item *nox_object_t) int32 {
	var v2 int32
	if a1 == 0 {
		return 0
	}
	if item == nil {
		return 0
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
	if v2 == 0 {
		return 0
	}
	for sub_4E7DE0(v2, item) == 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 496))))
		if v2 == 0 {
			return 0
		}
	}
	return 1
}
func nox_xxx_unitPostCreateNotify_4E7F10(a1p *nox_object_t) *byte {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result *byte
		i      int32
		v3     int32
		v4     int32
		v5     int32
	)
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 140))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 144))) = 0
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	for i = int32(uintptr(unsafe.Pointer(result))); result != nil; i = int32(uintptr(unsafe.Pointer(result))) {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 2056))))
		v4 = 1 << int32(*(*uint8)(unsafe.Pointer(uintptr(i + 2064))))
		if v3 != 0 {
			if nox_xxx_unitIsHostileMimic_4E7F90(v3, a1) == 1 {
				v5 = int32(uint32(v4) | *(*uint32)(unsafe.Pointer(uintptr(a1 + 144))))
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 140))) |= uint32(v4)
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 144))) = uint32(v5)
			}
		}
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*nox_playerInfo)(unsafe.Pointer(uintptr(i))))))
	}
	return result
}
func nox_xxx_unitIsHostileMimic_4E7F90(a1 int32, a2 int32) int32 {
	var v2 int32
	v2 = 0
	if *memmap.PtrUint32(0x5D4594, 1567724) == 0 {
		*memmap.PtrUint32(0x5D4594, 1567724) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Mimic")))
	}
	if a1 == 0 || a2 == 0 {
		return 0
	}
	if nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 {
		v2 = 1
	}
	if nox_common_gameFlags_check_40A5C0(4096) && uint32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))) == *memmap.PtrUint32(0x5D4594, 1567724) && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && *(*uint32)(unsafe.Pointer(uintptr(a2 + 508))) == 0 {
		v2 = 0
	}
	return v2
}
func nox_xxx_monsterMarkUpdate_4E8020(a1p *nox_object_t) *byte {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result *byte
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     bool
		v8     int32
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	v2 = int32(uintptr(unsafe.Pointer(result)))
	if result == nil {
		return nil
	}
	for {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 2056))))
		v4 = 1 << int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 2064))))
		if v3 == 0 {
			v5 = ^v4
			v6 = int32(uint32(v5) & *(*uint32)(unsafe.Pointer(uintptr(a1 + 140))))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 144))) &= uint32(v5)
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 140))) = uint32(v6)
		} else {
			v7 = nox_xxx_unitIsHostileMimic_4E7F90(v3, a1) == 1
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 144))))
			if v7 {
				if (v8 & v4) == 0 {
					*(*uint32)(unsafe.Pointer(uintptr(a1 + 144))) = uint32(v4 | v8)
					v6 = int32(uint32(v4) | *(*uint32)(unsafe.Pointer(uintptr(a1 + 140))))
					*(*uint32)(unsafe.Pointer(uintptr(a1 + 140))) = uint32(v6)
				}
			} else if v8&v4 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 144))) = uint32(v8 & ^v4)
				v6 = int32(uint32(v4) | *(*uint32)(unsafe.Pointer(uintptr(a1 + 140))))
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 140))) = uint32(v6)
			}
		}
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*nox_playerInfo)(unsafe.Pointer(uintptr(v2))))))
		v2 = int32(uintptr(unsafe.Pointer(result)))
		if result == nil {
			return result
		}
	}
}
func sub_4E80C0(a1 int8) int32 {
	var (
		result int32
		v2     int32
		v3     int32
	)
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if result != 0 {
		v2 = ^(1 << int32(a1))
		for {
			v3 = int32(uint32(v2) & *(*uint32)(unsafe.Pointer(uintptr(result + 140))))
			*(*uint32)(unsafe.Pointer(uintptr(result + 144))) &= uint32(v2)
			*(*uint32)(unsafe.Pointer(uintptr(result + 140))) = uint32(v3)
			result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
			if result == 0 {
				break
			}
		}
	}
	return result
}
func sub_4E8110(a1 int32) *byte {
	var (
		v1     int32
		result *byte
		v3     *byte
		v4     *byte
		v5     int32
		v6     int8
		v7     int32
		v8     int32
		v9     bool
		v10    int32
		v11    int32
	)
	v1 = 1 << a1
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(a1)))
	v3 = result
	if result != nil {
		result = (*byte)(unsafe.Pointer(nox_server_getFirstObject_4DA790()))
		v4 = result
		if result != nil {
			v5 = ^v1
			for {
				v6 = int8(*(*byte)(unsafe.Add(unsafe.Pointer(v4), 8)))
				v7 = int32(uint32(v5) & *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*35))))
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*36))) &= uint32(v5)
				*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*35))) = uint32(v7)
				if (int32(v6) & 6) != 0 {
					v8 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*514))))
					if v8 != 0 {
						v9 = nox_xxx_unitIsHostileMimic_4E7F90(v8, int32(uintptr(unsafe.Pointer(v4)))) == 1
						v10 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*36))))
						if v9 {
							if (v10 & v1) == 0 {
								v11 = v1 | v10
								*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*36))) = uint32(v11)
								*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*35))) |= uint32(v1)
							}
						} else if v10&v1 != 0 {
							v11 = int32(uint32(v5) & *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*36))))
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*36))) = uint32(v11)
							*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*35))) |= uint32(v1)
						}
					}
				}
				result = (*byte)(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))))))
				v4 = result
				if result == nil {
					break
				}
			}
		}
	}
	return result
}
func sub_4E81D0(a1p *nox_object_t) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result int32
	)
	result = int32(*memmap.PtrUint32(0x5D4594, 1567728))
	if *memmap.PtrUint32(0x5D4594, 1567728) == 0 {
		result = nox_xxx_getNameId_4E3AA0(internCStr("Pixie"))
		*memmap.PtrUint32(0x5D4594, 1567728) = uint32(result)
	}
	if a1 != 0 {
		if int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == result {
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*(*uint32)(unsafe.Pointer(uintptr(result + 4))) = 0
		}
	}
	return result
}
func sub_4E82C0(a1 uint8, a2 int8, a3 int8, a4 int16) int32 {
	var v4 int32
	v4 = int32(a1) * 6
	*memmap.PtrUint8(0x5D4594, uintptr(v4)+1567740) = a1
	*memmap.PtrUint8(0x5D4594, uintptr(v4)+1567741) = uint8(a3)
	*memmap.PtrUint8(0x5D4594, uintptr(v4)+1567742) = uint8(a2)
	*memmap.PtrUint16(0x5D4594, uintptr(v4)+1567744) = uint16(a4)
	return nox_xxx_netSendFlagStatus_4D95A0(math.MaxUint8, int8(a1), a2, a3, a4)
}
func sub_4E8310() *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, 1567736))
}
func sub_4E8320(a1 uint8) *uint8 {
	return (*uint8)(memmap.PtrOff(0x5D4594, uintptr(int32(a1)*6)+1567740))
}
func nox_xxx_fnFindCloseDoors_4E8340(a1 *float32, a2 int32) {
	var v2 int32
	if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(a1))), 8))))&0x80 != 0 {
		v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(a1))), 4*187))))
		if *(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) == *(*uint32)(unsafe.Pointer(uintptr(a2))) && *(*uint32)(unsafe.Pointer(uintptr(v2 + 20))) == *(*uint32)(unsafe.Pointer(uintptr(a2 + 4))) {
			*(*uint8)(unsafe.Pointer(uintptr(v2 + 1))) = 0
			if nox_common_gameFlags_check_40A5C0(4096) {
				sub_4E8390(int32(uintptr(unsafe.Pointer(a1))))
			}
		}
	}
}
func sub_4E8390(a1 int32) int32 {
	*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 48))) = 1
	return sub_4D6A20(math.MaxUint8, a1)
}
func nox_objectCollideDefault(a1 int32, a2 int32, a3 *float32) int32 {
	return 0
}
func nox_xxx_collideMonsterEventProc_4E83B0(a1 int32, a2 int32) *uint8 {
	return (*uint8)(nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748)))+1272)), unsafe.Pointer(uintptr(a2)), unsafe.Pointer(uintptr(a1)), 22))
}
func nox_xxx_collideMimic_4E83D0(a1 int32, a2 int32) *uint8 {
	var (
		v2 int32
		v3 *int32
		v4 *int32
	)
	if a2 != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
		if (v2&0x8000) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 && nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 && nox_xxx_monsterIsActionScheduled_50A090(a1, 15) == 0 {
			v3 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 43))
			if v3 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1)) = int32(gameFrame())
			}
			v4 = (*int32)(nox_xxx_monsterPushAction_50A260_impl((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 15))
			if v4 != nil {
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 56))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 60))))
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = int32(gameFrame())
			}
		}
	}
	return nox_xxx_collideMonsterEventProc_4E83B0(a1, a2)
}
func nox_xxx_collidePlayer_4E8460(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  *uint16
		v4  int32
		v5  int32
		v6  int16
		v7  int32
		v8  int16
		v9  int32
		v10 int32
		v11 int32
		v12 int8
		v13 float32
		v14 float32
		v15 int32
		v16 float32
		v17 float32
		v18 float32
		v19 float32
	)
	if nox_common_playerIsAbilityActive_4FC250((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 1) == 0 {
		goto LABEL_26
	}
	if a2 == 0 {
		goto LABEL_14
	}
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
	if (v2&6) == 0 || (func() bool {
		v3 = *(**uint16)(unsafe.Pointer(uintptr(a2 + 556)))
		return int32(*v3) == 0
	}()) && int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2))) != 0 {
		if (uint32(v2)&0x400000) == 0 && int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))) >= 0 && float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 120)))) <= float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 120)))) {
			goto LABEL_26
		}
	}
	if (v2 & 0x80) == 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&9) == 0 && (v2&1) == 0 {
			goto LABEL_14
		} else {
			goto LABEL_26
		}
	} else if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))) + 1)))) != 0 {
		goto LABEL_14
	} else {
		goto LABEL_26
	}
LABEL_14:
	nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 13)
	nox_xxx_earthquakeSend_4D9110((*float32)(unsafe.Pointer(uintptr(a1+56))), 10)
	sub_4FC300((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 1)
	if a2 != 0 {
		v16 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("BerserkerDamage")))
		v4 = nox_float2int(v16)
		if (*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))) & 0x400000) == 0 {
			sub_4E86E0(a1, (*float32)(unsafe.Pointer(uintptr(a2))))
		}
		v5 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v5, a1, v4, 2)
		if *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x20006 != 0 {
			nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*float2)(unsafe.Pointer(uintptr(a1+72))))
			goto LABEL_26
		}
		v17 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("BerserkerStunDuration")))
		v6 = int16(nox_float2int(v17))
		nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 5, v6, 5)
	} else {
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 296))))
		if v7 != 0 && (nox_xxx_wallFlags(int32(*(*uint8)(unsafe.Pointer(uintptr(v7 + 1)))))&5) == 0 {
			nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*float2)(unsafe.Pointer(uintptr(a1+72))))
			goto LABEL_26
		}
		nox_xxx_aud_501960(171, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		v18 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("BerserkerStunDuration")))
		v8 = int16(nox_float2int(v18))
		nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 5, v8, 5)
		v14 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))) * 0.043478262)
		v15 = nox_float2int(v14)
		v13 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.043478262)
		v9 = nox_float2int(v13)
		nox_xxx_damageToMap_534BC0(v9, v15, 100, 2, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
	v19 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("BerserkerPainRatio")) * float64(**(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))))
	v10 = nox_float2int(v19)
	if v10 < 1 {
		v10 = 1
	}
	nox_xxx_unitDamageClear_4EE5E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), v10)
	nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*float2)(unsafe.Pointer(uintptr(a1+72))))
LABEL_26:
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
			if (v11 & 0x8000) == 0 {
				if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 16) != 0 {
					if uint32(nox_xxx_unitGetBuffTimer_4FF550((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 16)) < (gameFPS() * 14) {
						v12 = nox_xxx_buffGetPower_4FF570((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 16)
						nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 16, int16(int32(uint16(gameFPS()))*15), v12)
						nox_xxx_spellBuffOff_4FF5B0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 16)
					}
				}
			}
		}
	}
}
func sub_4E86E0(a1 int32, a2 *float32) {
	var (
		v2  int32
		v3  *float32
		v4  float64
		v5  float64
		v6  float64
		v7  float64
		v8  float32
		v9  float32
		v10 float32
		v11 float32
		v12 float32
		v13 float32
	)
	v2 = a1
	if a1 != 0 {
		v3 = a2
		if a2 != nil {
			v12 = *(*float32)(unsafe.Pointer(uintptr(a1 + 120)))
			v10 = *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*30))
			v8 = v10 + v12
			v4 = float64((v12 - v10) / v8)
			v9 = (v10 + v10) / v8
			v5 = float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 84))))*v4 + float64(v9**(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21)))
			v6 = float64((v10 - v12) / v8)
			v7 = float64((v12 + v12) / v8)
			v11 = float32(v6*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20))) + v7*float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 80)))))
			v13 = float32(v6*float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21))) + v7*float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 84)))))
			*(*float32)(unsafe.Pointer(uintptr(v2 + 80))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(v2 + 80))))*v4 + float64(v9**(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20))))
			*(*float32)(unsafe.Pointer(uintptr(v2 + 84))) = float32(v5)
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21)) = v13
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20)) = v11
		}
	}
}
func nox_xxx_collideProjectileGeneric_4E87B0(a1 int32, a2 int32) {
	var (
		v2 *int32
		v3 int32
		v4 float64
		v5 int32
		v6 int32
		v7 *int32
		v8 float32
	)
	v2 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if *memmap.PtrUint32(0x5D4594, 1567948) == 0 {
		*memmap.PtrUint32(0x5D4594, 1567948) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ThrowingStone")))
		*memmap.PtrUint32(0x5D4594, 1567952) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ImpShot")))
	}
	v3 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
	if uint32(uint16(int16(v3))) == *memmap.PtrUint32(0x5D4594, 1567948) {
		v4 = nox_xxx_gamedataGetFloat_419D40(internCStr("UrchinStoneDamage"))
		v8 = float32(v4)
		v5 = nox_float2int(v8)
		goto LABEL_9
	}
	if uint32(v3) == *memmap.PtrUint32(0x5D4594, 1567952) {
		v4 = nox_xxx_gamedataGetFloat_419D40(internCStr("ImpShotDamage"))
		v8 = float32(v4)
		v5 = nox_float2int(v8)
		goto LABEL_9
	}
	v5 = *v2
LABEL_9:
	if a2 != 0 {
		v6 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		if int32((*(*func(int32, int32, int32, int32, int32) uint8)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v6, a1, v5, 11)) == 0 {
			return
		}
	} else {
		v7 = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
		if v7 != nil {
			nox_xxx_damageToMap_534BC0(*v7, *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)), v5, 11, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			return
		}
	}
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func nox_xxx_collideProjectileSpark_4E8880(a1 int32, a2 int32) {
	var (
		v2 *int32
		v3 int32
		v4 int32
		v5 float32
		v6 float32
		v7 int32
		v8 int32
		v9 int32
	)
	v2 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 {
		v9 = *v2
		v3 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		if int32((*(*func(int32, int32, int32, int32, int32) uint8)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v3, a1, v9, 11)) != 0 {
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
	} else {
		v8 = *v2
		v6 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))) * 0.043478262)
		v7 = nox_float2int(v6)
		v5 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.043478262)
		v4 = nox_float2int(v5)
		nox_xxx_damageToMap_534BC0(v4, v7, v8, 11, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func nox_xxx_collideDoor_4E8AC0(a2 int32, a3 int32) {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  uint64
		v6  int8
		v7  uint64
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 float64
		v13 float64
		v14 int32
		v15 int32
		v16 int32
		v17 uint64
		a3a [2]int32
		a1  float4
		v20 float32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	if a3 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v3 + 12))) == *(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) {
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 508))))
		if v4 != 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(a2 + 136))) <= gameFrame() {
				*(*uint32)(unsafe.Pointer(uintptr(a2 + 508))) = 0
			} else if v4 != a3 {
				v5 = uint64(nox_platform_get_ticks()) - qword_5d4594_1567940
				a3a[1] = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v5))), 4*1)))
				if v5 <= 0x5DC {
					return
				}
				if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 12))))&4 != 0 {
					nox_xxx_aud_501960(244, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
					nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a3))), internCStr("objcoll.c:GateLockedMagic"), 0)
				} else {
					nox_xxx_aud_501960(240, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
					nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a3))), internCStr("objcoll.c:DoorLockedMagic"), 0)
				}
				qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
				return
			}
		}
		v6 = int8(*(*uint8)(unsafe.Pointer(uintptr(v3 + 1))))
		if int32(v6) == 0 {
			return
		}
		if int32(v6) == 5 {
			v7 = uint64(nox_platform_get_ticks()) - qword_5d4594_1567940
			a3a[1] = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v7))), 4*1)))
			if v7 <= 0x5DC {
				return
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 12))))&4 != 0 {
				nox_xxx_aud_501960(244, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a3))), internCStr("objcoll.c:GateLockedMechanism"), 0)
			} else {
				nox_xxx_aud_501960(240, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a3))), internCStr("objcoll.c:DoorLockedMechanism"), 0)
			}
			qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
			return
		}
		v8 = int32(uintptr(unsafe.Pointer(nox_xxx_doorGetSomeKey_4E8910((*nox_object_t)(unsafe.Pointer(uintptr(a3))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))))))
		if v8 == 0 {
			v17 = uint64(nox_platform_get_ticks()) - qword_5d4594_1567940
			a3a[1] = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v17))), 4*1)))
			if v17 <= 0x5DC {
				return
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 12))))&4 != 0 {
				nox_xxx_aud_501960(244, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
				sub_4FADD0(a3, internCStr("objcoll.c:GateLockedKey"), int8(*(*uint8)(unsafe.Pointer(uintptr(v3 + 1)))))
			} else {
				nox_xxx_aud_501960(240, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
				sub_4FADD0(a3, internCStr("objcoll.c:DoorLockedKey"), int8(*(*uint8)(unsafe.Pointer(uintptr(v3 + 1)))))
			}
			qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
			return
		}
		v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))))
		v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 20))))
		*(*uint8)(unsafe.Pointer(uintptr(v3 + 1))) = 0
		v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))))
		v12 = float64(v9 * 23)
		a1.field_0 = float32(v12 - 34.0)
		v13 = float64(v10 * 23)
		v20 = float32(v13)
		a1.field_4 = float32(v13 - 34.0)
		a1.field_8 = float32(v12 + 34.0)
		a1.field_C = float32(float64(v20) + 34.0)
		switch v11 {
		case 0:
			v14 = v10 - 1
			a3a[0] = v9 - 1
			a3a[1] = v14
		case 8:
			v14 = v10 - 1
			a3a[0] = v9 + 1
			a3a[1] = v14
		case 16:
			v15 = v9 + 1
			a3a[0] = v15
			v14 = v10 + 1
			a3a[1] = v14
		case 24:
			v15 = v9 - 1
			a3a[0] = v15
			v14 = v10 + 1
			a3a[1] = v14
		default:
		}
		if nox_common_gameFlags_check_40A5C0(4096) {
			sub_4E8390(v2)
			sub_4D71E0(int32(gameFrame()))
		}
		nox_xxx_getUnitsInRect_517C10(&a1, unsafe.Pointer(funAddr(nox_xxx_fnFindCloseDoors_4E8340)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(&a3a[0]))))))
		nox_xxx_aud_501960(234, (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 0, 0)
		v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 492))))
		if v16 != 0 && a3 != v16 && int32(*(*uint8)(unsafe.Pointer(uintptr(v16 + 8))))&4 != 0 && nox_common_gameFlags_check_40A5C0(4096) && sub_4D72C0() == 1 {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 492)))))), internCStr("GeneralPrint:KeyShared1"), 0)
		}
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v8))))
	}
}
func nox_xxx_collidePickup_4E8DF0(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
	)
	result = a2
	if a2 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
		if (v3&2) == 0 && (gameFrame()-*(*uint32)(unsafe.Pointer(uintptr(a1 + 128)))) >= uint32(int32(gameFPS())>>1) && ((v3&4) == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))) + 240))))&1 != 0) {
			result = nox_xxx_inventoryServPlace_4F36F0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 1, 1)
		}
	}
	return result
}
func sub_4E8E50() *uint8 {
	return (*uint8)(memmap.PtrOff(0x5D4594, 1567844))
}
func sub_4E8E60() int32 {
	var (
		v0     int32
		v1     int32
		v2     int32
		v3     int32
		v4     int32
		v5     uint32
		v6     int32
		v7     int32
		result int32
		v9     int32
		v10    int32
		v11    float32
		v12    float32
		v13    int32
		v14    int32
	)
	v11 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestExitTimerStart")))
	v0 = nox_float2int(v11)
	v1 = 0
	v14 = v0
	v2 = v0
	v13 = 0
	if sub_40A220() != 0 {
		v3 = sub_40A230()
		v4 = v3 / 1000
		v5 = 0
		v0 = int32(v5 + uint32(v4))
		v14 = int32(v5 + uint32(v4))
		v2 = int32(v5 + uint32(v4))
	}
	v6 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v6 == 0 {
		return sub_40A1F0(0)
	}
	for {
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 748))))
		if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v7 + 276))) + 4792))) == 1 {
			v1++
			if *(*uint32)(unsafe.Pointer(uintptr(v7 + 312))) != 0 {
				v13++
			}
		}
		v6 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(v6)))))))
		if v6 == 0 {
			break
		}
	}
	if v1 == 0 {
		return sub_40A1F0(0)
	}
	v12 = float32(float64(v13) / float64(v1) * float64(v14))
	v9 = nox_float2int(v12)
	v10 = v0 - v9
	if v0-v9 < v0 && (func() bool {
		v0 -= v9
		return v2 != v10
	}()) || (func() int32 {
		result = sub_40A300()
		return result
	}()) == 0 {
		nox_xxx_servStartCountdown_40A2A0(v0, internCStr("objcoll.c:ExitCountdown"))
		result = nox_xxx_netGauntlet_4D9E70(math.MaxUint8)
	}
	return result
}
func nox_server_questMaybeWarp_4E8F60() bool {
	var (
		curLvl uint32 = uint32(nox_game_getQuestStage_4E3CC0())
		toLvl  uint32 = uint32(nox_server_questNextStageThreshold_4D74F0(int32(curLvl)))
		cnt    int32  = 0
		allow  bool   = nox_server_questAllowDefault()
	)
	for unit := unsafe.Pointer(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())); unit != nil; unit = unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unit))) {
		var v4 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(unit)) + 748))))
		if !nox_common_gameFlags_check_40A5C0(1) || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2064)))) != 31 {
			var v5 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
			if *(*uint32)(unsafe.Pointer(uintptr(v5 + 4792))) != 0 {
				cnt++
				if *(*uint32)(unsafe.Pointer(uintptr(v4 + 316))) == 0 {
					return false
				}
				if *(*uint32)(unsafe.Pointer(uintptr(v5 + 4696))) >= toLvl {
					allow = true
				}
			}
		}
	}
	if cnt == 0 {
		return false
	}
	return allow
}
func sub_4E9010() int32 {
	var (
		v0 int32
		v1 int32
		v2 int32
	)
	v0 = 0
	v1 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v1 != 0 {
		for {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 748))))
			if !nox_common_gameFlags_check_40A5C0(1) || !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 2064)))) != 31 {
				if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 276))) + 4792))) != 0 {
					v0++
					if *(*uint32)(unsafe.Pointer(uintptr(v2 + 312))) == 0 {
						break
					}
				}
			}
			v1 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(v1)))))))
			if v1 == 0 {
				if v0 == 0 {
					return 0
				}
				return 1
			}
		}
	}
	return 0
}
func nox_xxx_collideExit_4E9090(a1 int32, a2 int32, a3 int32) {
	var (
		v4  int32
		v5  int32
		v6  *uint8
		i   int32
		v8  int8
		v9  int32
		v10 *byte
		v11 int32
		v12 int32
		v13 int32
		v14 uint32
		v15 int32
		j   int32
		v17 int32
		v18 int32
		v19 *byte
	)
	if dword_5d4594_1567960 == 0 {
		dword_5d4594_1567960 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	v4 = a2
	if a2 == 0 {
		return
	}
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8)))) & 4) == 0 {
		return
	}
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	v6 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 700)))
	v19 = *(**byte)(unsafe.Pointer(uintptr(a1 + 700)))
	if nox_common_gameFlags_check_40A5C0(4096) && (*(**byte)(unsafe.Pointer(uintptr(v5 + 312))) != nil || *(**byte)(unsafe.Pointer(uintptr(v5 + 316))) != nil) {
		return
	}
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&2) != 0 && sub_4D75E0() == 0 {
		return
	}
	if sub_4DCC90() == 1 {
		return
	}
	if sub_4DCC10((*nox_object_t)(unsafe.Pointer(uintptr(v4)))) == 0 {
		return
	}
	if nox_xxx_checkGameFlagPause_413A50() == 1 {
		return
	}
	if int32(*v6) == 0 && !nox_common_gameFlags_check_40A5C0(4096) {
		return
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 2251)))) == 1 {
		for i = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 516)))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 512)))) {
			if uint32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) == dword_5d4594_1567960 && *(*uint32)(unsafe.Pointer(uintptr(i + 492))) == 0 {
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(i))))
				v8 = int8(*(*uint8)(unsafe.Pointer(uintptr(v5 + 244))))
				if int32(v8) != 0 {
					*(*uint8)(unsafe.Pointer(uintptr(v5 + 244))) = uint8(int8(int32(v8) - 1))
				}
			}
		}
	}
	sub_4DCBF0(1)
	if nox_common_gameFlags_check_40A5C0(2048) {
		nox_setSaveFileName_4DB130(internCStr("WORKING"))
		sub_4DB170(1, unsafe.Pointer(uintptr(a1)), 0)
		return
	}
	v9 = 1
	if nox_common_gameFlags_check_40A5C0(4096) {
		v10 = nox_xxx_getQuestMapFile_4D0F60()
		v19 = v10
	} else {
		v10 = v19
	}
	if !nox_common_gameFlags_check_40A5C0(4096) {
		goto LABEL_47
	}
	v11 = 1
	for {
		if nox_common_playerIsAbilityActive_4FC250((*nox_object_t)(unsafe.Pointer(uintptr(v4))), v11) != 0 {
			sub_4FC300((*nox_object_t)(unsafe.Pointer(uintptr(v4))), v11)
		}
		v11++
		if v11 >= 6 {
			break
		}
	}
	v12 = a1
	v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
	if v13&1 != 0 {
		v14 = uint32(nox_game_getQuestStage_4E3CC0() + 1)
		sub_4D60E0(v4)
		v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))))
		if *(*uint32)(unsafe.Pointer(uintptr(v15 + 4696))) < v14 {
			*(*uint32)(unsafe.Pointer(uintptr(v15 + 4696))) = v14
			sub_4D7450(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 2064)))), int16(uint16(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4696))))))
		}
		*(*uint32)(unsafe.Pointer(uintptr(v5 + 312))) = uint32(a1)
		*(*uint32)(unsafe.Pointer(uintptr(v5 + 316))) = 0
		nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v4))), 13)
		nox_xxx_playerGoObserver_4E6860((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276)))))), 0, 0)
		nox_xxx_netInformTextMsg2_4DA180(18, (*uint8)(unsafe.Pointer(uintptr(v4+36))))
		v12 = a1
		v9 = sub_4E9010()
	} else if v13&2 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v5 + 312))) = 0
		*(*uint32)(unsafe.Pointer(uintptr(v5 + 316))) = uint32(a1)
		sub_4D75F0(int32(gameFrame()))
		nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v4))), 13)
		nox_xxx_playerGoObserver_4E6860((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276)))))), 0, 0)
		for j = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); j != 0; j = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(j))))))) {
			if j != v4 {
				nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(j + 748))) + 276))) + 2064)))), 19, (*int32)(unsafe.Pointer(uintptr(v4+36))))
			}
		}
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v4))), internCStr("objcoll.c:PlayerEntersWarp"), 0)
		v9 = bool2int32(nox_server_questMaybeWarp_4E8F60())
	}
	nox_xxx_aud_501960(1003, (*nox_object_t)(unsafe.Pointer(uintptr(v12))), 0, 0)
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(v12 + 12))))&2) == 0 && v9 == 0 {
		sub_4E8E60()
	}
	libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, 1567844)), v19)
	if v9 != 1 {
		return
	}
	v10 = v19
LABEL_47:
	if v10 != nil && *v10 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&2 != 0 {
			v17 = nox_game_getQuestStage_4E3CC0()
			v18 = nox_server_questNextStageThreshold_4D74F0(v17)
			nox_game_setQuestStage_4E3CD0(v18 - 1)
			sub_4D76E0(1)
			sub_4D60B0()
		}
		nox_xxx_mapLoad_4D2450(v10)
	}
}
func nox_xxx_collideDamage_4E9430(a1 int32, a2 int32) {
	var (
		v2 *uint8
		v3 int32
		v4 int32
		v5 int32
		v6 int32
	)
	v2 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 && *(*uint32)(unsafe.Pointer(uintptr(a2 + 556))) != 0 {
		if int32(*v2) == 1 && int32(uint8(gameFrame()))&1 != 0 {
			v3 = 1
		} else {
			v3 = int32(*v2) >> 1
		}
		v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*1))))
		v5 = v3
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v4, a1, v5, v6)
	}
}
func nox_xxx_collideManadrain_4E9490(a1 int32, a2 int32) {
	var result *uint32
	result = (*uint32)(unsafe.Pointer(uintptr(a2)))
	if a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 && int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))) + 4)))) != 0 {
		nox_xxx_playerManaSub_4EEBF0(a2, int32(**(**uint8)(unsafe.Pointer(uintptr(a1 + 700)))))
		result = (*uint32)(unsafe.Pointer(uintptr(gameFrame() - uint32(*(*int16)(unsafe.Pointer(uintptr(a1 + 542)))))))
		if uint32(uintptr(unsafe.Pointer(result))) > uint32(int32(gameFPS())>>1) {
			nox_xxx_aud_501960(228, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			*(*uint16)(unsafe.Pointer(uintptr(a1 + 542))) = uint16(gameFrame())
		}
	}
}
func nox_xxx_spellFlyCollide_4E9500(a1 int32, a2 int32, a3 *float32) {
	var (
		v3  int32
		v4  *float2
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int8
		v11 int32
		v12 [3]int32
	)
	v3 = a2
	v4 = (*float2)(unsafe.Pointer(uintptr(a1)))
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if a2 == 0 {
		if a3 != nil {
			nox_xxx_collideReflect_57B810(a3, a1+80)
		}
		return
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))&0x8020 != 0 {
		return
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 88)))) != 16 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 88)))) != 1 || nox_common_mapPlrActionToStateId_4FA2B0((*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 45 || (func() bool {
				v10 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276))) + 3))))
				return int32(v10) != 1
			}()) && int32(v10) != 2 {
				goto LABEL_22
			}
			if (gameex_flags & 0x10) == 0 {
				goto LABEL_13
			}
		}
		if nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a2+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 124)))), (*float2)(unsafe.Pointer(uintptr(a1+72))))&1 != 0 {
			nox_xxx_aud_501960(878, (*nox_object_t)(unsafe.Pointer(uintptr(v3))), 0, 0)
			nox_xxx_projectileReflect_4E0A70(int32(uintptr(unsafe.Pointer(v4))), v3)
			nox_xxx_changeOwner_52BE40(int32(uintptr(unsafe.Pointer(v4))), v3)
			return
		}
	LABEL_22:
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 88)))) == 13 || int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 88)))) == 0 && gameex_flags&0x4 != 0 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v6 + 276))) + 4))))
			if v7&0x400 != 0 && nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(v3+56))), int32(*(*int16)(unsafe.Pointer(uintptr(v3 + 124)))), (*float2)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float2{})*9)))&1 != 0 {
				v8 = nox_common_randomInt_415FA0(18, 20)
				nox_xxx_aud_501960(890, (*nox_object_t)(unsafe.Pointer(uintptr(v3))), 0, 0)
				nox_xxx_projectileReflect_4E0A70(int32(uintptr(unsafe.Pointer(v4))), v3)
				nox_xxx_changeOwner_52BE40(int32(uintptr(unsafe.Pointer(v4))), v3)
				nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v3))), v8)
				v9 = nox_common_mapPlrActionToStateId_4FA2B0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
				nox_xxx_animPlayerGetFrameRange_4F9F90(v9, &a1, &a2)
				v5 = v11
				*(*uint8)(unsafe.Pointer(uintptr(v6 + 236))) = uint8(int8(a1 - 1))
			}
		}
	LABEL_13:
		if nox_xxx_checkInversionEffect_4FA4F0(v3, int32(uintptr(unsafe.Pointer(v4)))) != 0 {
			nox_xxx_changeOwner_52BE40(int32(uintptr(unsafe.Pointer(v4))), v3)
			return
		}
		if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(v3))), 27) != 0 && nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(v3+56))), int32(*(*int16)(unsafe.Pointer(uintptr(v3 + 124)))), (*float2)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float2{})*7)))&1 != 0 {
			nox_xxx_changeOwner_52BE40(int32(uintptr(unsafe.Pointer(v4))), v3)
			nox_xxx_aud_501960(122, (*nox_object_t)(unsafe.Pointer(uintptr(v3))), 0, 0)
			return
		}
	}
	if *(*uint32)(unsafe.Pointer(uintptr(v5 + 4))) == uint32(v3) {
		v12[0] = v3
		nox_xxx_spellAccept_4FD400(int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 12)))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 8)))))), (*nox_object_t)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(uintptr(v5))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))), unsafe.Pointer(&v12[0]), int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 16)))))
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))))
	} else {
		nox_xxx_projectileReflect_4E0A70(int32(uintptr(unsafe.Pointer(v4))), v3)
	}
}
func nox_xxx_collideBomb_4E96F0(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if !nox_common_gameFlags_check_40A5C0(2048) || (int32(*(*uint8)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))) + 16))))&2) != 2 {
		nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(v2+1272)), unsafe.Pointer(uintptr(a2)), unsafe.Pointer(uintptr(a1)), 21)
		if a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 && nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
			if (v3 & 0x8000) == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 2176))) = uint32(a2)
				nox_xxx_unitDamageClear_4EE5E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 999)
			}
		}
	}
}
func nox_xxx_collideBoom_4E9770(a1 int32, a2 int32, a3 *float32) {
	var (
		v3  int32
		v4  float32
		v5  int16
		v6  float64
		v7  *int32
		v8  int32
		v9  int32
		v10 float32
		v11 float32
		v12 float2
	)
	if *memmap.PtrUint32(0x5D4594, 1567964) == 0 {
		v10 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MagicMissileDamage")))
		*memmap.PtrUint32(0x5D4594, 1567968) = uint32(nox_float2int(v10))
		v11 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MagicMissileSplashDamage")))
		*memmap.PtrUint32(0x5D4594, 1567972) = uint32(nox_float2int(v11))
		*mem_getFloatPtr(0x5D4594, 1567976) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MagicMissileRange")))
		*mem_getFloatPtr(0x5D4594, 1567980) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MagicMissilePushRange")))
		*mem_getFloatPtr(0x5D4594, 1567984) = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MagicMissileForce")))
		*memmap.PtrUint32(0x5D4594, 1567964) = 1
	}
	if !nox_common_gameFlags_check_40A5C0(4096) || (func() int32 {
		v3 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		return v3
	}()) == 0 || a2 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8))))&4) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4) == 0 || nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
		if a1 != 0 {
			nox_xxx_netSendPointFx_522FF0(-122, (*float2)(unsafe.Pointer(uintptr(a1+56))))
		}
		if a2 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
				if nox_xxx_checkInversionEffect_4FA4F0(a2, a1) != 0 {
					nox_xxx_changeOwner_52BE40(a1, a2)
					return
				}
				if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 27) != 0 && nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a2+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 124)))), (*float2)(unsafe.Pointer(uintptr(a1+56))))&1 != 0 {
					nox_xxx_changeOwner_52BE40(a1, a2)
					nox_xxx_aud_501960(122, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
					return
				}
			}
			v9 = int32(*memmap.PtrUint32(0x5D4594, 1567968))
			v8 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v8, a1, v9, 7)
			nox_xxx_sMakeScorch_537AF0((*float32)(unsafe.Pointer(uintptr(a2+56))), 0)
		} else if a3 != nil {
			nox_xxx_collideReflect_57B810(a3, a1+80)
			v4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 84)))
			v12.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 80)))
			v12.field_4 = v4
			v5 = int16(nox_xxx_math_509ED0(&v12))
			v6 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))) * 0.5
			*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(v5)
			*(*float32)(unsafe.Pointer(uintptr(a1 + 80))) = float32(v6)
			*(*float32)(unsafe.Pointer(uintptr(a1 + 84))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))) * 0.5)
			v7 = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
			if v7 != nil {
				nox_xxx_damageToMap_534BC0(*v7, *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)), *memmap.PtrInt32(0x5D4594, 1567968), 7, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			}
			return
		}
		nox_xxx_mapDamageUnitsAround_4E25B0((*float32)(unsafe.Pointer(uintptr(a1+56))), *mem_getFloatPtr(0x5D4594, 1567976), 5.0, *memmap.PtrInt32(0x5D4594, 1567972), 7, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), nil)
		nox_xxx_mapPushUnitsAround_52E040(unsafe.Pointer(uintptr(a1+56)), *mem_getFloatPtr(0x5D4594, 1567980), *mem_getFloatPtr(0x5D4594, 1567980), *mem_getFloatPtr(0x5D4594, 1567984), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		nox_xxx_aud_501960(84, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func nox_xxx_collideDie_4E99B0(unit int32, a2 int32) {
	var (
		v2             int32
		deleteOverride func(int32)
	)
	if a2 != 0 && nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(unit))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 16))))
		deleteOverride = *(*func(int32))(unsafe.Pointer(uintptr(unit + 724)))
		*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v2))), 1)) |= 0x80
		*(*uint32)(unsafe.Pointer(uintptr(unit + 16))) = uint32(v2)
		if deleteOverride != nil {
			deleteOverride(unit)
		} else {
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
		}
	}
}
func sub_4E9A30(a1p *nox_object_t, a2p *nox_object_t) int32 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3 int32
		v4 int32
		v5 int32
	)
	if nox_common_gameFlags_check_40A5C0(2048) && (int32(*(*uint8)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))) + 16))))&2) == 2 {
		return 0
	}
	v5 = 1
	if a2 != 0 {
		if nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 || nox_common_gameFlags_check_40A5C0(512) && (func() int32 {
			v3 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			v4 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a2)))))))
			return int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8)))) & 4
		}()) != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&4 != 0 {
			v5 = 0
		}
	}
	if nox_common_playerIsAbilityActive_4FC250((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 4) != 0 {
		v5 = 0
	}
	return v5
}
func nox_xxx_fireballCollide_4E9AC0(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  *byte
		v4  int32
		v5  int32
		v6  int32
		v7  float32
		v8  float32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 uint32
	)
	v2 = a1
	v3 = *(**byte)(unsafe.Pointer(uintptr(a1 + 700)))
	v4 = 1
	if a2 != 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 27) != 0 && nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a2+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 124)))), (*float2)(unsafe.Pointer(uintptr(a1+56))))&1 != 0 {
		nox_xxx_projectileReflect_4E0A70(a1, a2)
		nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		v4 = 0
		nox_xxx_aud_501960(122, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
	}
	if !nox_common_gameFlags_check_40A5C0(4096) || (func() int32 {
		v5 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		return v5
	}()) == 0 || a2 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))&4) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4) == 0 || nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(v5))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
		if v4 != 0 {
			v7 = float32(float64(uint8(*v3)) * 0.66666669)
			nox_xxx_mapPushUnitsAround_52E040(unsafe.Pointer(uintptr(a1+56)), v7, 0, 50.0, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			if a2 != 0 {
				v11 = int32(uint8(*v3)) >> 1
				v6 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
				(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v6, a1, v11, 1)
			}
			if nox_common_gameFlags_check_40A5C0(2048) {
				v13 = a2
				v12 = a1
				v14 = uint32(uint8(*v3))
				v10 = int32(v14 >> 1)
				v9 = 0
			} else {
				v13 = a2
				v12 = a1
				v14 = uint32(uint8(*v3))
				v10 = int32(v14 >> 1)
				v9 = 1097859072
			}
			v8 = float32(float64(int32(v14)) * 0.33333334)
			nox_xxx_mapDamageUnitsAround_4E25B0((*float32)(unsafe.Pointer(uintptr(v2+56))), v8, *(*float32)(unsafe.Pointer(&v9)), v10, 1, (*nox_object_t)(unsafe.Pointer(uintptr(v12))), (*nox_object_t)(unsafe.Pointer(uintptr(v13))))
			nox_xxx_netSparkExplosionFx_5231B0((*float32)(unsafe.Pointer(uintptr(v2+56))), int8(*v3))
			nox_xxx_aud_501960(42, (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 0, 0)
			nox_xxx_sMakeScorch_537AF0((*float32)(unsafe.Pointer(uintptr(v2+56))), 2)
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
		}
	}
}
func nox_xxx_collideChest_4E9C40(a1 *uint32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 int32
		i  int32
		v6 func(*uint32)
	)
	v2 = a2
	if a2 == 0 {
		return
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8)))&uint8(int8(bool2int32(4 == 0)))) != 0 {
		return
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	if (v3 & 0x8000) != 0 {
		return
	}
	if nox_common_gameFlags_check_40A5C0(4096) && (func() int32 {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
		return int32(*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v4))), 1))) & 0xF
	}()) != 0 {
		for i = nox_xxx_inventoryGetFirst_4E7980(a2); i != 0; i = nox_xxx_inventoryGetNext_4E7990(i) {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(i + 8))))&0x40 != 0 {
				if libc.StrCmp(nox_xxx_getUnitName_4E39D0((*nox_object_t)(unsafe.Pointer(uintptr(i)))), internCStr("SilverKey")) == 0 {
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(i))))
					nox_xxx_aud_501960(234, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 0, 0)
					v2 = a2
					goto LABEL_14
				}
				v2 = a2
			}
		}
		if (uint64(nox_platform_get_ticks()) - qword_5d4594_1567940) > 0x5DC {
			nox_xxx_aud_501960(1012, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 0, 0)
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v2))), internCStr("objcoll.c:ChestLockedSilver"), 0)
			qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
		}
		return
	}
LABEL_14:
	v6 = asFunc(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*181)), (*func(*uint32))(nil)).(func(*uint32))
	if v6 != nil {
		v6(a1)
	}
	nox_xxx_chest_4EDF00(int32(uintptr(unsafe.Pointer(a1))), v2)
	nox_xxx_dropAllItems_4EDA40(a1)
	return
}
func nox_xxx_collideSulphurShot2_4E9D80(a1 int32, a2 int32, a3 *float32) {
	var (
		v3  *int32
		v4  int32
		v5  int32
		v6  int32
		v7  float32
		v8  float32
		v9  int32
		v10 int32
	)
	v3 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 {
		if nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 {
			if nox_common_gameFlags_check_40A5C0(4096) && funAddr(*(*func(int32, int32, int32))(unsafe.Pointer(uintptr(a1 + 696)))) == funAddr(nox_xxx_collideSulphurShot_4E9E50) {
				v5 = *v3 * 3
			} else {
				v5 = *v3
			}
			v6 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			if (*(*func(int32, int32, int32, int32, int32) int32)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v6, a1, v5, 11) != 0 {
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			}
		}
	} else if a3 != nil {
		nox_xxx_collideReflect_57B810(a3, a1+80)
		v10 = *v3
		v8 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))) * 0.043478262)
		v9 = nox_float2int(v8)
		v7 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.043478262)
		v4 = nox_float2int(v7)
		nox_xxx_damageToMap_534BC0(v4, v9, v10, 11, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func nox_xxx_collideSulphurShot_4E9E50(a1 int32, a2 int32, a3 int32) {
	if a1 != 0 && !nox_common_gameFlags_check_40A5C0(4) {
		nox_xxx_netSendPointFx_522FF0(-120, (*float2)(unsafe.Pointer(uintptr(a1+56))))
	}
	nox_xxx_collideSulphurShot2_4E9D80(a1, a2, (*float32)(unsafe.Pointer(uintptr(a3))))
}
func nox_xxx_collideDeathBall_4E9E90(a1 int32, a2 int32, a3 *float32) {
	var (
		result *int32
		v4     *int32
		v5     int32
		v6     int32
		v7     int32
		v8     float64
		v9     float64
		v10    float64
		v11    int32
		v12    float32
		v13    float32
		v14    int32
		a2a    float2
	)
	if a2 != 0 {
		if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))) >= 0 {
			v13 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("DeathBallCollideDamage")))
			v14 = nox_float2int(v13)
			v11 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			result = (*int32)(unsafe.Pointer(uintptr((*(*func(int32, int32, int32, int32, int32) int32)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v11, a1, v14, 2))))
		} else {
			v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 76))))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 64))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 72)))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 68))) = uint32(v7)
			v8 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 72))))
			v9 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 76))))
			a2a.field_0 = float32(-float64(*memmap.PtrInt32(0x587000, *(*uint32)(unsafe.Pointer(uintptr(v6 + 12)))*8+196188)))
			v10 = float64(*memmap.PtrInt32(0x587000, *(*uint32)(unsafe.Pointer(uintptr(v6 + 12)))*8+196184))
			a2a.field_4 = float32(v10)
			if v10*v9+float64(a2a.field_0)*v8 > 0.0 {
				a2a.field_0 = -a2a.field_0
				a2a.field_4 = -a2a.field_4
			}
			sub_57B770((*float2)(unsafe.Pointer(uintptr(a1+80))), &a2a)
			nox_xxx_aud_501960(283, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	} else {
		result = (*int32)(unsafe.Pointer(a3))
		if a3 != nil {
			nox_xxx_collideReflect_57B810(a3, a1+80)
			nox_xxx_aud_501960(37, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			result = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
			v4 = result
			if result != nil {
				v12 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("DeathBallCollideDamage")))
				v5 = nox_float2int(v12)
				result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_damageToMap_534BC0(*v4, *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)), v5, 2, (*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			}
		}
	}
}
func nox_xxx_collideDeathBallFragment_4E9FE0(a1 int32, a2 int32, a3 *float32) {
	var (
		v3 int32
		v4 int32
		v5 float32
		v6 float32
		v7 int32
	)
	if a2 != 0 {
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v4, a1, 20, 2)
	} else if a3 != nil {
		nox_xxx_collideReflect_57B810(a3, a1+80)
		nox_xxx_aud_501960(37, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		v6 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))) * 0.043478262)
		v7 = nox_float2int(v6)
		v5 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.043478262)
		v3 = nox_float2int(v5)
		nox_xxx_damageToMap_534BC0(v3, v7, 20, 2, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		return
	}
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
}
func nox_xxx_collidePixie_4EA080(a1 int32, a2 int32, a3 *float32) {
	var (
		v3  *int32
		v4  int16
		v5  float64
		v6  float64
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 float32
		v12 float32
		v13 int32
		v14 int32
		v15 int32
	)
	v3 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 {
		if nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
			if uint32(v8)&0x20006 != 0 {
				if (*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) & 0x8020) == 0 {
					v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
					if v9 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 8))))&4) != 4 || (int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 16))))&2) != 2 {
						if (v8 & 4) == 0 {
							v15 = *v3
							v10 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
							(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v10, a1, v15, 11)
							nox_xxx_aud_501960(96, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
							nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
							return
						}
						if nox_xxx_checkInversionEffect_4FA4F0(a2, a1) != 0 {
							nox_xxx_changeOwner_52BE40(a1, a2)
							return
						}
						if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 27) != 0 && nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(uintptr(a2+56))), int32(*(*int16)(unsafe.Pointer(uintptr(a2 + 124)))), (*float2)(unsafe.Pointer(uintptr(a1+56))))&1 != 0 {
							nox_xxx_changeOwner_52BE40(a1, a2)
							nox_xxx_aud_501960(122, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
						} else {
							v15 = *v3
							v10 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
							(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v10, a1, v15, 11)
							nox_xxx_aud_501960(96, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
							nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
							return
						}
					}
				}
			}
		}
	} else if a3 != nil {
		nox_xxx_collideReflect_57B810(a3, a1+80)
		v4 = int16(nox_xxx_math_509ED0((*float2)(unsafe.Pointer(uintptr(a1 + 80)))))
		v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 64))))
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(v4)
		*(*float32)(unsafe.Pointer(uintptr(a1 + 64))) = float32(v5)
		v6 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 84))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 68))))
		*(*float32)(unsafe.Pointer(uintptr(a1 + 68))) = float32(v6)
		v14 = *v3
		v12 = float32(v6 * 0.043478262)
		v13 = nox_float2int(v12)
		v11 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.043478262)
		v7 = nox_float2int(v11)
		nox_xxx_damageToMap_534BC0(v7, v13, v14, 11, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func nox_xxx_collideWallReflectSpark_4EA200(a1 int32, a2 int32, a3 *float2) {
	var (
		v3  *int32
		v5  float64
		v8  int32
		v9  int32
		v10 float32
		v11 float32
		v12 int32
		v13 int32
		v14 int32
	)
	v3 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 {
		v14 = *v3
		v9 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		if (*(*func(int32, int32, int32, int32, int32) int32)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v9, a1, v14, 11) != 0 {
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
	} else if a3 != nil {
		v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80))))
		if float64(a3.field_0*a3.field_4) <= 0.0 {
			*(*float32)(unsafe.Pointer(uintptr(a1 + 80))) = *(*float32)(unsafe.Pointer(uintptr(a1 + 84)))
		} else {
			*(*float32)(unsafe.Pointer(uintptr(a1 + 80))) = -*(*float32)(unsafe.Pointer(uintptr(a1 + 84)))
			v5 = -v5
		}
		*(*float32)(unsafe.Pointer(uintptr(a1 + 84))) = float32(v5)
		v13 = *v3
		v11 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 68)))) * 0.043478262)
		v12 = nox_float2int(v11)
		v10 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 64)))) * 0.043478262)
		v8 = nox_float2int(v10)
		nox_xxx_damageToMap_534BC0(v8, v12, v13, 11, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func sub_4EA2C0(a1 int32, a2 int32) {
	var v2 int32
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
			if v2 != a2 && v2 == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) = gameFrame()
				nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			}
		}
	}
}
func nox_xxx_collideSpark_4EA300(a1 int32, a2 int32, a3 *float32) {
	var v3 int8
	if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 12))) != 4 {
		if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 12))) == 5 {
			if a2 != 0 {
				nox_xxx_aud_501960(351, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
				v3 = int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))
				*(*uint8)(unsafe.Pointer(uintptr(a2 + 541)))++
				*(*uint16)(unsafe.Pointer(uintptr(a2 + 542))) = 1000
				if int32(v3)&4 != 0 {
					nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), internCStr("objcoll.c:WebbingSlow"), 0)
				}
			}
		} else {
			nox_xxx_collideSulphurShot2_4E9D80(a1, a2, a3)
		}
	}
}
func nox_xxx_collideWebbing_4EA380(a1 int32, a2 int32) {
	var v2 int32
	if a2 != 0 {
		nox_xxx_aud_501960(351, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		v2 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
		if (*(*func(int32, int32, int32, uint32, int32) int32)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v2, a1, 0, 2) != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 {
				nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 4, int16(int32(uint16(gameFPS()))*4), 3)
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), internCStr("objcoll.c:WebbingSlow"), 0)
			}
		}
	}
}
func sub_4EA400(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
	)
	if a2 != 0 {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
		if (v2 & 0x8000) == 0 {
			if nox_common_gameFlags_check_40A5C0(32) {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
					nox_xxx_pickupFlagCtf_4EA490(a1, a2)
				}
			} else if nox_common_gameFlags_check_40A5C0(64) {
				v3 = int32(*memmap.PtrUint32(0x5D4594, 1567996))
				if *memmap.PtrUint32(0x5D4594, 1567996) == 0 {
					v3 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
					*memmap.PtrUint32(0x5D4594, 1567996) = uint32(v3)
				}
				if int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))) == v3 || int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
					sub_4EA800(a1, a2)
				}
			}
		}
	}
}
func nox_xxx_pickupFlagCtf_4EA490(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  int32
		v4  int8
		v5  int32
		v6  int32
		v7  uint16
		v8  int32
		v9  int32
		v10 *byte
		v11 *byte
		v12 *byte
		v13 *uint32
		v14 int32
		v15 *float2
		v16 uint8
		v17 uint8
		v18 [10]byte
		v19 int32
		v20 int32
	)
	v2 = a1
	v3 = a2
	a2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	v4 = int8(sub_4ECBD0(a1))
	v16 = *(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))
	if nox_xxx_servCompareTeams_419150(v3+48, a1+48) != 0 {
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		if math.Abs(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))-*(*float32)(unsafe.Pointer(uintptr(v5))))) > *mem_getDoublePtr(0x581450, 10160) || math.Abs(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))-*(*float32)(unsafe.Pointer(uintptr(v5 + 4))))) > *mem_getDoublePtr(0x581450, 10160) {
			v15 = *(**float2)(unsafe.Pointer(uintptr(a1 + 748)))
			a2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 36))))
			nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a1))), v15)
			nox_xxx_netInformTextMsg2_4DA180(4, (*uint8)(unsafe.Pointer(&a2)))
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 8))) = 0
			sub_4E82C0(*(*uint8)(unsafe.Pointer(uintptr(v3 + 52))), 0, v4, 0)
		} else {
			v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 504))))
			if v6 != 0 {
				for {
					if *(*uint32)(unsafe.Pointer(uintptr(v6 + 8)))&0x10000000 != 0 {
						v7 = uint16(nox_xxx_servGamedataGet_40A020(32))
						v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 748))))
						v9 = int32(v7)
						v19 = sub_4ECBD0(v6)
						v17 = *(*uint8)(unsafe.Pointer(uintptr(v6 + 52)))
						nox_xxx_changeScore_4D8E90(v3, 1)
						nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
						if nox_xxx_servObjectHasTeam_419130(v3+48) != 0 {
							v10 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 52)))))))
							nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v10))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*13)))+1))
							if dword_5d4594_2650652 != 0 {
								if a2 != 0 {
									sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 276)))), 0)
								}
							}
						}
						sub_4ED0C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(uintptr(v6))))
						nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(v6))), nil, *(*float32)(unsafe.Pointer(uintptr(v8))), *(*float32)(unsafe.Pointer(uintptr(v8 + 4))))
						nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(v6))), 0.0)
						nox_xxx_netMarkMinimapForAll_4174B0(v6, 1)
						*(*uint32)(unsafe.Pointer(uintptr(v8 + 8))) = 0
						sub_4E82C0(v17, 0, int8(v19), 0)
						*(*uint32)(unsafe.Pointer(&v18[2])) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 36)))
						*(*uint32)(unsafe.Pointer(&v18[6])) = uint32(v19)
						nox_xxx_netInformTextMsg2_4DA180(5, (*uint8)(unsafe.Pointer(&v18[0])))
						if v9 > 0 {
							break
						}
					}
					v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 496))))
					if v6 == 0 {
						return
					}
				}
				v11 = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10()))
				if v11 != nil {
					for *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), 4*13))) < uint32(v9) {
						v11 = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v11)))))))))
						if v11 == nil {
							return
						}
					}
					nox_xxx_setGameFlags_40A4D0(8)
					nox_xxx_netFlagWinner_4D8C40_4D8C80(int32(uintptr(unsafe.Pointer(v11))), 0)
				}
			}
		}
	} else {
		v20 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
		if *(*uint32)(unsafe.Pointer(uintptr(v2 + 492))) == 0 {
			v12 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 52)))))))
			if v12 != nil && sub_418BC0(int32(uintptr(unsafe.Pointer(v12)))) != 0 {
				v13 = *(**uint32)(unsafe.Pointer(uintptr(v3 + 504)))
				if v13 != nil {
					for (*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*2)) & 0x10000000) == 0 {
						v13 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*124)))))
						if v13 == nil {
							goto LABEL_27
						}
					}
					nox_xxx_invForceDropItem_4ED930(v3, v13)
				}
			LABEL_27:
				nox_xxx_servFinalizeDelObject_4DADE0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
				v14 = sub_4ECBD0(v2)
				nox_xxx_inventoryPutImpl_4F3070((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 1)
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 276))) + 4))) |= 1
				sub_4D82F0(math.MaxUint8, (*uint32)(unsafe.Pointer(uintptr(v2))))
				*(*uint32)(unsafe.Pointer(&v18[2])) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 36)))
				*(*uint32)(unsafe.Pointer(&v18[6])) = uint32(v14)
				nox_xxx_netInformTextMsg2_4DA180(6, (*uint8)(unsafe.Pointer(&v18[0])))
				nox_xxx_netUnmarkMinimapSpec_417470(v2, 1)
				*(*uint32)(unsafe.Pointer(uintptr(v20 + 8))) = 0
				sub_4E82C0(v16, 1, v4, int16(*(*uint16)(unsafe.Pointer(uintptr(v3 + 36)))))
				sub_4EA7A0(v3)
			} else {
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("objcoll.c:FlagNoTeam"), 0)
			}
		}
	}
}
func sub_4EA7A0(a1 int32) int32 {
	var (
		i      int32
		result int32
		v3     int32
	)
	for i = 0; i < 32; i++ {
		result = nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int8(i))
		if result != 0 {
			result = nox_xxx_getEnchantSpell_424920(i)
			if result != 0 {
				v3 = nox_xxx_getEnchantSpell_424920(i)
				result = bool2int32(nox_xxx_spellHasFlags_424A50(v3, 0x80000))
				if result != 0 {
					result = nox_xxx_spellBuffOff_4FF5B0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), i)
				}
			}
		}
	}
	return result
}
func sub_4EA800(a1 int32, a2 int32) int16 {
	var (
		v2  *byte
		v3  int32
		v4  *int32
		v5  *byte
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 *byte
		v11 int32
		i   int32
		v13 int32
		j   int32
		v15 int32
		v17 [10]byte
	)
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x5D4594, 1567992)
	if *memmap.PtrUint32(0x5D4594, 1567992) == 0 {
		v2 = (*byte)(unsafe.Pointer(uintptr(nox_xxx_getNameId_4E3AA0(internCStr("GameBall")))))
		*memmap.PtrUint32(0x5D4594, 1567992) = uint32(uintptr(unsafe.Pointer(v2)))
	}
	v3 = a2
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		v2 = (*byte)(unsafe.Pointer(uintptr(nox_xxx_unitIsGameball_4E7C30(a2))))
		if v2 == nil {
			return int16(uintptr(unsafe.Pointer(v2)))
		}
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 516))))
		if v3 == 0 {
			return int16(uintptr(unsafe.Pointer(v2)))
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x5D4594, 1567992)
		for uint32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 4)))) != *memmap.PtrUint32(0x5D4594, 1567992) {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 512))))
			if v3 == 0 {
				return int16(uintptr(unsafe.Pointer(v2)))
			}
		}
	}
	if v3 != 0 {
		v4 = *(**int32)(unsafe.Pointer(uintptr(v3 + 748)))
		if *v4 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*v4 + 16))))&0x20 != 0 {
			*v4 = 0
		}
		v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))))))
		v2 = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))))))
		v6 = int32(uintptr(unsafe.Pointer(v2)))
		if v2 == nil {
			v2 = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10()))
			v6 = int32(uintptr(unsafe.Pointer(v2)))
		}
		v7 = *v4
		if v7 != 0 {
			v2 = (*byte)(unsafe.Pointer(uintptr(*(*uint8)(unsafe.Pointer(uintptr(v7 + 52))))))
			if v2 == (*byte)(unsafe.Pointer(uintptr(*(*uint8)(unsafe.Pointer(uintptr(v6 + 57)))))) {
				v8 = int32(uint16(nox_xxx_servGamedataGet_40A020(64)))
				nox_xxx_changeScore_4D8E90(v7, 1)
				nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(v7))))
				nox_xxx_netChangeTeamID_419090(v6, int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 52)))+1))
				if dword_5d4594_2650652 != 0 {
					v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 748))))
					if v9 != 0 {
						sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 276)))), 0)
					}
				}
				nox_xxx_aud_501960(929, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
				*(*uint32)(unsafe.Pointer(&v17[2])) = *(*uint32)(unsafe.Pointer(uintptr(v7 + 36)))
				*(*uint32)(unsafe.Pointer(&v17[6])) = uint32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 57))))
				nox_xxx_netInformTextMsg2_4DA180(9, (*uint8)(unsafe.Pointer(&v17[0])))
				nox_xxx_netSendPointFx_522FF0(-102, (*float2)(unsafe.Pointer(uintptr(v3+56))))
				if v8 > 0 {
					v10 = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10()))
					if v10 != nil {
						for *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*13))) < uint32(v8) {
							v10 = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*nox_team_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v10)))))))))
							if v10 == nil {
								goto LABEL_27
							}
						}
						nox_xxx_setGameFlags_40A4D0(8)
						nox_xxx_netFlagballWinner_4D8C40(int32(uintptr(unsafe.Pointer(v10))))
					}
				}
			LABEL_27:
				if dword_5d4594_1567988 == 0 {
					dword_5d4594_1567988 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("GameBallStart")))
				}
				v11 = 0
				for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(i))))))) {
					if uint32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) == dword_5d4594_1567988 {
						v11++
					}
				}
				v13 = nox_common_randomInt_415FA0(0, v11-1)
				v2 = (*byte)(unsafe.Pointer(nox_server_getFirstObject_4DA790()))
				for j = int32(uintptr(unsafe.Pointer(v2))); v2 != nil; j = int32(uintptr(unsafe.Pointer(v2))) {
					*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(j + 4)))
					if uint32(uint16(uintptr(unsafe.Pointer(v2)))) == dword_5d4594_1567988 {
						if v13 == 0 {
							if j != 0 {
								v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 748))))
								nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
								sub_4EB9B0(v3, 0)
								nox_xxx_netChangeTeamMb_419570(unsafe.Pointer(uintptr(v3+48)), int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 36)))))
								nox_xxx_unitHPsetOnMax_4EE6F0(v3)
								*(*uint64)(unsafe.Pointer(uintptr(v15 + 8))) = uint64(nox_platform_get_ticks())
								nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*float2)(unsafe.Pointer(uintptr(j+56))))
								sub_4E8290(0, 0)
								*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(v3+56))))))
								*(*uint32)(unsafe.Pointer(uintptr(v3 + 80))) = 0
								*(*uint32)(unsafe.Pointer(uintptr(v3 + 84))) = 0
								*(*uint32)(unsafe.Pointer(uintptr(v3 + 88))) = 0
								*(*uint32)(unsafe.Pointer(uintptr(v3 + 100))) = 0
							}
							return int16(uintptr(unsafe.Pointer(v2)))
						}
						v13--
					}
					v2 = (*byte)(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(j))))))
				}
			}
		}
	}
	return int16(uintptr(unsafe.Pointer(v2)))
}
func sub_4EAAA0(a1 int32) {
	if gameFrame() > (*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) + 3) {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) = gameFrame()
		nox_xxx_aud_501960(281, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
}
func sub_4EAAD0(a1 int32, a2 int32) {
	if a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		if gameFrame() > (*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) + 30) {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) = gameFrame()
			nox_xxx_aud_501960(int32(**(**uint32)(unsafe.Pointer(uintptr(a1 + 700)))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
}
func nox_xxx_collidePentagram_4EAB20(a1 int32) int32 {
	var result int32
	result = a1
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 4))) = 1
	return result
}
func nox_xxx_collideSign_4EAB40(a1 int32, a2 int32) {
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			(*(*func(int32, int32) int32)(unsafe.Pointer(uintptr(a1 + 732))))(a2, a1)
		}
	}
}
func nox_xxx_collideTrapDoor_4EAB60(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 float64
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 700))))
	if a2 != 0 {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
		if (v3 & 0x80) == 0 {
			if *(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x1000000 != 0 {
				v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 172))))
				if v4 == 3 {
					if float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) < float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 184)))) || float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) < float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 188)))) {
						return
					}
					if nox_xxx_map_57B850((*float2)(unsafe.Pointer(uintptr(a1+56))), (*float32)(unsafe.Pointer(uintptr(a1+172))), (*float2)(unsafe.Pointer(uintptr(a2+56)))) != 0 {
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) |= 0x60000
						*(*float32)(unsafe.Pointer(uintptr(a2 + 164))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v2 + 8)))))
						*(*float32)(unsafe.Pointer(uintptr(a2 + 168))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v2 + 12)))))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 156))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 56)))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 160))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 60)))
					}
					return
				}
				if v4 != 2 {
					if nox_xxx_map_57B850((*float2)(unsafe.Pointer(uintptr(a1+56))), (*float32)(unsafe.Pointer(uintptr(a1+172))), (*float2)(unsafe.Pointer(uintptr(a2+56)))) != 0 {
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) |= 0x60000
						*(*float32)(unsafe.Pointer(uintptr(a2 + 164))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v2 + 8)))))
						*(*float32)(unsafe.Pointer(uintptr(a2 + 168))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v2 + 12)))))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 156))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 56)))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 160))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 60)))
					}
					return
				}
				v5 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 176))) + *(*float32)(unsafe.Pointer(uintptr(a2 + 176))))
				if v5 <= float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) && v5 <= float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) {
					if nox_xxx_map_57B850((*float2)(unsafe.Pointer(uintptr(a1+56))), (*float32)(unsafe.Pointer(uintptr(a1+172))), (*float2)(unsafe.Pointer(uintptr(a2+56)))) != 0 {
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) |= 0x60000
						*(*float32)(unsafe.Pointer(uintptr(a2 + 164))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v2 + 8)))))
						*(*float32)(unsafe.Pointer(uintptr(a2 + 168))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v2 + 12)))))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 156))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 56)))
						*(*uint32)(unsafe.Pointer(uintptr(a2 + 160))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 60)))
					}
					return
				}
			} else if *(*uint32)(unsafe.Pointer(uintptr(v2 + 24))) == 0 && ((v3&4) == 0 || nox_common_playerIsAbilityActive_4FC250((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 4) == 0) {
				if int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 20)))) != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) = gameFrame() + uint32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 20))))
				}
				nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(v2)), unsafe.Pointer(uintptr(a2)), unsafe.Pointer(uintptr(a1)), 20)
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 24))) = 1
			}
		}
	}
}
func sub_4EACA0(a1 int32, a2 int32) {
	var v3 *int32
	v3 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 {
		if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))) >= 0 {
			nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a2+56))))
			nox_xxx_aud_501960(147, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
			*(*float32)(unsafe.Pointer(uintptr(a2 + 164))) = float32(float64(*v3))
			*(*float32)(unsafe.Pointer(uintptr(a2 + 168))) = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))))
			nox_xxx_teleportToMB_4E7190((*uint8)(unsafe.Pointer(uintptr(a2))), (*float32)(unsafe.Pointer(uintptr(a2+164))))
			nox_xxx_netSendPointFx_522FF0(-119, (*float2)(unsafe.Pointer(uintptr(a2+56))))
			nox_xxx_aud_501960(147, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
		}
	}
}
func nox_xxx_collideSpellPedestal_4EAD20(a1 int32, a2 int32) int32 {
	var result int32
	result = a2
	if a2 != 0 {
		result = nox_xxx_spellGrantToPlayer_4FB550((*nox_object_t)(unsafe.Pointer(uintptr(a2))), int32(**(**uint32)(unsafe.Pointer(uintptr(a1 + 700)))), 1, 0, 0)
	}
	return result
}
func nox_xxx_collideFist_4EADF0(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
	)
	if float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 104)))) <= 0.0 {
		if a2 != 0 {
			v3 = int32(**(**uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			v2 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v2, a1, v3, 2)
		}
	}
}
func nox_xxx_collideTeleportWake_4EAE30(a1 int32, a2 int32) {
	var (
		v2 *float32
		v3 int32
	)
	v2 = *(**float32)(unsafe.Pointer(uintptr(a1 + 700)))
	if a2 != 0 {
		if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 14) == 0 {
			if !nox_common_gameFlags_check_40A5C0(4096) || (func() int32 {
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
				return v3
			}()) == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 8))))&4 != 0 {
				if *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x3001016 != 0 {
					if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0) == 0 {
						nox_xxx_netSendPointFx_522FF0(-118, (*float2)(unsafe.Pointer(uintptr(a2+56))))
					}
					nox_xxx_aud_501960(147, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
					nox_xxx_teleportToMB_4E7190((*uint8)(unsafe.Pointer(uintptr(a2))), v2)
					if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0) == 0 {
						nox_xxx_netSendPointFx_522FF0(-119, (*float2)(unsafe.Pointer(uintptr(a2+56))))
					}
					nox_xxx_aud_501960(147, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
				}
			}
		}
	}
}
func nox_xxx_collideChakram_4EAF00(a1 int32, a2 int32, a3 *float32) {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  *int32
		v7  int32
		v8  int8
		v9  *int32
		v10 int32
		v11 int32
		v12 *uint32
		v13 int32
		v14 int32
		v15 int32
		v16 float64
		v17 int8
		v18 int32
		v19 *int32
		v20 int32
		v21 *uint32
		v22 [9]int32
		v23 int32
		v24 int32
	)
	v3 = a1
	v20 = a1
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v23 = 1
	v5 = nox_xxx_inventoryGetFirst_4E7980(v20)
	v6 = (*int32)(unsafe.Pointer(uintptr(v5)))
	v21 = (*uint32)(unsafe.Pointer(uintptr(v5)))
	if v5 == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 16))))&0x20 != 0 {
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
	} else {
		v7 = a2
		if a2 == 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 24))))&0x30 != 0 {
			nox_xxx_netSendPointFx_522FF0(-106, (*float2)(unsafe.Pointer(uintptr(v3+56))))
		}
		if a2 == 0 {
			if a3 == nil {
				return
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 4)))) != 0 {
				nox_xxx_collideReflect_57B810(a3, v3+80)
			} else {
				sub_4EB3E0(v3)
			}
			v8 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 4))))
			if int32(v8) != 0 {
				*(*uint8)(unsafe.Pointer(uintptr(v4 + 4))) = uint8(int8(int32(v8) - 1))
			} else if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 24)))) == 0 {
				*(*uint8)(unsafe.Pointer(uintptr(v4 + 24))) = 2
				v23 = 0
			}
			v9 = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
			if v9 != nil {
				nox_xxx_damageToMap_534BC0(*v9, *(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1)), 1, 0, (*nox_object_t)(unsafe.Pointer(uintptr(v3))))
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 24)))) == 1 {
				nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(v6)), (*float2)(unsafe.Pointer(uintptr(v3+56))))
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
				return
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 4)))) == 0 && v23 != 0 {
				*(*uint8)(unsafe.Pointer(uintptr(v4 + 24))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 8))) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 508)))
				return
			}
			sub_4EB250(v3)
			return
		}
		if uint32(a2) == *(*uint32)(unsafe.Pointer(uintptr(v3 + 508))) {
			sub_4ED0C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(v6)))
			nox_xxx_inventoryPutImpl_4F3070((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 508)))))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), 1)
			v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 508))))
			if v10 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v10 + 8))))&4 != 0 && *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v10 + 748))) + 104))) == 0 {
				nox_xxx_playerEquipWeapon_53A420((*uint32)(unsafe.Pointer(uintptr(v10))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), 1, 1)
			}
			nox_xxx_aud_501960(892, (*nox_object_t)(unsafe.Pointer(uintptr(v3))), 0, 0)
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
		} else {
			if nox_xxx_unitsHaveSameTeam_4EC520((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
				return
			}
			v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 508))))
			v12 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(*(*uint16)(unsafe.Pointer(uintptr(v3 + 4))))))
			v24 = int32(uintptr(unsafe.Pointer(v12)))
			if v11 == 0 || *(*uint32)(unsafe.Pointer(uintptr(v11 + 16)))&0x8020 != 0 {
				nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(v21)), (*float2)(unsafe.Pointer(uintptr(v3+56))))
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
			} else {
				v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 16))))
				if (v13&0x8000) == 0 && v12 != nil {
					v14 = nox_xxx_unitGetStrength_4F9FD0(v11)
					v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 60))))
					v22[4] = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 56))))
					v22[7] = v3
					v22[5] = v15
					*(*float32)(unsafe.Pointer(&v22[0])) = float32(nox_xxx_calcBoltDamage_4EF1E0(v14, v24))
					v16 = float64(*(*float32)(unsafe.Pointer(uintptr(v3 + 176)))) + 30.0
					*((*uint8)(unsafe.Pointer(&v22[1]))) = 0
					v22[3] = v11
					*(*float32)(unsafe.Pointer(&v22[2])) = float32(v16)
					v22[6] = 0
					nox_xxx_itemApplyAttackEffect_538840(v3, v11, int32(uintptr(unsafe.Pointer(&v22[0]))))
					nox_xxx_playerPreAttackEffects_538290(v7, v11, v3, int32(uintptr(unsafe.Pointer(&v22[0]))))
					(*(*func(int32, int32, int32, uint32, uint32))(unsafe.Pointer(uintptr(v7 + 716))))(v7, v11, v3, uint32(int32(int64(float64(*(*float32)(unsafe.Pointer(&v22[0])))+*(*float64)(unsafe.Pointer(&qword_581450_9544))))), 0)
					if (*(*uint32)(unsafe.Pointer(uintptr(v7 + 16))) & 0x8020) == 0 {
						*(*uint32)(unsafe.Pointer(uintptr(v4 + 12))) = uint32(v7)
					}
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 4)))) != 0 {
						nox_xxx_projectileReflect_4E0A70(v3, v7)
					} else {
						sub_4EB3E0(v3)
					}
					v17 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 4))))
					if int32(v17) != 0 || int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 24)))) != 0 {
						v18 = 1
					} else {
						*(*uint8)(unsafe.Pointer(uintptr(v4 + 24))) = 2
						v18 = 0
					}
					if int32(v17) != 0 {
						*(*uint8)(unsafe.Pointer(uintptr(v4 + 4))) = uint8(int8(int32(v17) - 1))
					}
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 24)))) == 1 {
						v19 = (*int32)(unsafe.Pointer(uintptr(nox_xxx_inventoryGetFirst_4E7980(v3))))
						nox_xxx_aud_501960(893, (*nox_object_t)(unsafe.Pointer(uintptr(v3))), 0, 0)
						sub_4ED0C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(v19)))
						nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v19)))))), nil, *(*float32)(unsafe.Pointer(uintptr(v3 + 56))), *(*float32)(unsafe.Pointer(uintptr(v3 + 60))))
						nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
						return
					}
					if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 4)))) == 0 && v18 != 0 {
						*(*uint32)(unsafe.Pointer(uintptr(v4 + 8))) = uint32(v11)
						*(*uint8)(unsafe.Pointer(uintptr(v4 + 24))) = 0
						return
					}
					sub_4EB250(v3)
					return
				}
			}
		}
	}
}
func sub_4EB250(a1 int32) int32 {
	var (
		v1     *float32
		v2     int32
		result int32
		v4     float64
		v5     float64
		v6     float32
		a1a    float4
		v8     float32
	)
	v1 = (*float32)(unsafe.Pointer(uintptr(a1)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	dword_5d4594_1567928 = 0
	*memmap.PtrUint32(0x5D4594, 1567932) = *(*uint32)(unsafe.Pointer(uintptr(v2 + 12)))
	*memmap.PtrUint32(0x5D4594, 1567840) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 508)))
	*memmap.PtrUint32(0x5D4594, 1567924) = uint32(a1)
	*memmap.PtrUint32(0x5D4594, 1567836) = 1259902592
	a1a.field_0 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))) - 400.0)
	a1a.field_4 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))) - 400.0)
	a1a.field_8 = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))) + 400.0)
	a1a.field_C = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))) + 400.0)
	nox_xxx_getUnitsInRect_517C10(&a1a, unsafe.Pointer(funAddr(sub_4EB340)), unsafe.Pointer(uintptr(a1+56)))
	result = int32(dword_5d4594_1567928)
	if dword_5d4594_1567928 != 0 {
		*(*uint8)(unsafe.Pointer(uintptr(v2 + 24))) = 2
		result = int32(dword_5d4594_1567928)
		v4 = float64(*(*float32)(unsafe.Pointer(uintptr(dword_5d4594_1567928 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56))))
		v5 = float64(*(*float32)(unsafe.Pointer(uintptr(dword_5d4594_1567928 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
		v8 = float32(v5)
		v6 = float32(math.Sqrt(v5*float64(v8)+v4*v4) + *(*float64)(unsafe.Pointer(&qword_581450_10176)))
		*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*20)) = float32(v4 * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*136))) / float64(v6))
		*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21)) = v8 * *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*136)) / v6
	}
	return result
}
func sub_4EB340(a1 *float32, a2 int32) {
	var (
		v2 float64
		v3 float64
		v4 float64
	)
	if uint32(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*2)))&0x20006 != 0 {
		if (uint32(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*4)))&0x8020) == 0 && nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 0) == 0 && a1 != *(**float32)(memmap.PtrOff(0x5D4594, 1567840)) && a1 != *(**float32)(memmap.PtrOff(0x5D4594, 1567932)) {
			if nox_xxx_mapCheck_537110((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x5D4594, 1567924))))) != 0 {
				v2 = float64(*(*float32)(unsafe.Pointer(uintptr(a2))) - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14)))
				v3 = float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 4))) - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)))
				v4 = v3*v3 + v2*v2
				if v4 <= 160000.0 && v4 < float64(*mem_getFloatPtr(0x5D4594, 1567836)) {
					*mem_getFloatPtr(0x5D4594, 1567836) = float32(v4)
					dword_5d4594_1567928 = uint32(uintptr(unsafe.Pointer(a1)))
				}
			}
		}
	}
}
func sub_4EB3E0(a1 int32) {
	var (
		v1 int32
		v2 *float32
	)
	_ = v2
	var v3 int32
	var v4 int32
	var v5 int32
	var v6 float64
	var v7 int32
	var v8 *float2
	var v9 float32
	v1 = a1
	v2 = (*float32)(unsafe.Pointer(uintptr(a1 + 80)))
	v8 = (*float2)(unsafe.Pointer(uintptr(a1 + 80)))
	v9 = float32(math.Sqrt(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 80)))**(*float32)(unsafe.Pointer(uintptr(a1 + 80))) + *(*float32)(unsafe.Pointer(uintptr(a1 + 84)))**(*float32)(unsafe.Pointer(uintptr(a1 + 84))))))
	v3 = nox_xxx_math_509ED0(v8)
	v4 = nox_common_randomInt_415FA0(-64, 64) + v3 + 128
	if v4 < 0 {
		v4 += int32(uint32(math.MaxUint8-v4) >> 8 << 8)
	}
	if v4 >= 256 {
		v4 += int32((uint32(v4) >> 8) * 4294967040)
	}
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 76))))
	*v2 = v9 * *mem_getFloatPtr(0x587000, uint32(v4*8)+194136)
	v6 = float64(v9 * *mem_getFloatPtr(0x587000, uint32(v4*8)+194140))
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 72))))
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 68))) = uint32(v5)
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 64))) = uint32(v7)
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 56))) = uint32(v7)
	*(*float32)(unsafe.Pointer(uintptr(v1 + 84))) = float32(v6)
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 60))) = uint32(v5)
	nox_xxx_moveUpdateSpecial_517970((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
}
func nox_xxx_collideArrow_4EB490(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  *uint32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 float64
		v11 int32
		v12 int32
		v13 int32
		v14 int8
		v15 *uint16
		v16 *int32
		v17 float64
		v18 int32
		v19 int32
		v20 int32
		v21 [9]int32
		v22 int32
	)
	v2 = a1
	v19 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
	v22 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 700))))
	v3 = (*uint32)(nox_xxx_getProjectileClassById_413250(v19))
	if v3 == nil {
		return
	}
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 508))))
	if v4 == a2 {
		if a2 != 0 {
			return
		}
	}
	if v4 != 0 {
		v5 = nox_xxx_unitGetStrength_4F9FD0(int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 508)))))
	} else {
		v5 = 30
	}
	if nox_common_gameFlags_check_40A5C0(4096) {
		v6 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(v2)))))))
		if v6 != 0 {
			if a2 == 0 {
				v16 = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
				if v16 != nil {
					v17 = nox_xxx_calcBoltDamage_4EF1E0(v5, int32(uintptr(unsafe.Pointer(v3))))
					nox_xxx_damageToMap_534BC0(*v16, *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1)), int32(int64(v17)), 11, (*nox_object_t)(unsafe.Pointer(uintptr(v2))))
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
					return
				}
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
				return
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v6 + 8))))&4 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 && nox_xxx_unitIsEnemyTo_5330C0((*nox_object_t)(unsafe.Pointer(uintptr(v6))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 0 {
				return
			}
		}
	}
	if a2 == 0 {
		v16 = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
		if v16 != nil {
			v17 = nox_xxx_calcBoltDamage_4EF1E0(v5, int32(uintptr(unsafe.Pointer(v3))))
			nox_xxx_damageToMap_534BC0(*v16, *(*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1)), int32(int64(v17)), 11, (*nox_object_t)(unsafe.Pointer(uintptr(v2))))
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
			return
		}
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
		return
	}
	nox_xxx_unitGetStrength_4F9FD0(int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 508)))))
	if *memmap.PtrUint32(0x5D4594, 1568000) == 0 {
		*memmap.PtrUint32(0x5D4594, 1568000) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArcherBolt")))
	}
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
	if (v7 & 0x8000) != 0 {
		return
	}
	v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 56))))
	v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 60))))
	v21[7] = v2
	v21[4] = v8
	v21[5] = v9
	v10 = nox_xxx_calcBoltDamage_4EF1E0(v5, int32(uintptr(unsafe.Pointer(v3))))
	v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 176))))
	*(*float32)(unsafe.Pointer(&v21[0])) = float32(v10)
	v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v22 + 4))))
	*((*uint8)(unsafe.Pointer(&v21[1]))) = 11
	v21[3] = v12
	v21[2] = v11
	v21[6] = 0
	nox_xxx_itemApplyAttackEffect_538840(v2, v12, int32(uintptr(unsafe.Pointer(&v21[0]))))
	if *(*uint32)(unsafe.Pointer(uintptr(v2 + 508))) != uint32(a2) {
		nox_xxx_playerPreAttackEffects_538290(a2, int32(*(*uint32)(unsafe.Pointer(uintptr(v22 + 4)))), v2, int32(uintptr(unsafe.Pointer(&v21[0]))))
	}
	v20 = int32(*((*uint8)(unsafe.Pointer(&v21[1]))))
	v18 = int32(int64(float64(*(*float32)(unsafe.Pointer(&v21[0]))) + *(*float64)(unsafe.Pointer(&qword_581450_9544))))
	v13 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(v2)))))))
	v14 = int8((*(*func(int32, int32, int32, int32, int32) int32)(unsafe.Pointer(uintptr(a2 + 716))))(a2, v13, v2, v18, v20))
	if uint32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 4)))) == *memmap.PtrUint32(0x5D4594, 1568000) {
		v15 = *(**uint16)(unsafe.Pointer(uintptr(a2 + 556)))
		if v15 != nil && int32(*v15) == 0 {
			if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v15), unsafe.Sizeof(uint16(0))*2))) == 0 {
				nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
			}
			return
		}
	} else if int32(v14) == 0 {
		return
	}
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v2))))
}
func nox_xxx_collideMonsterArrow_4EB800(a1 int32, a2 int32) {
	var (
		v2 *int32
		v3 int32
		v4 int32
		v5 int32
		v6 *int32
	)
	v2 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
	if nox_common_gameFlags_check_40A5C0(2048) {
		v3 = *v2
	} else {
		v3 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1))
	}
	if a2 != 0 {
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
		if (v4 & 0x8000) == 0 {
			v5 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))))
			(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v5, a1, v3, 3)
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
	} else {
		v6 = (*int32)(unsafe.Pointer(uintptr(sub_537760())))
		if v6 != nil {
			nox_xxx_damageToMap_534BC0(*v6, *(*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1)), v3, 11, (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func nox_xxx_collideBearTrap_4EB890(a1 *int32, a2 int32) {
	var v2 *uint32
	if a2 != 0 && sub_4E9A30((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
		v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("ClosedBearTrap"))))
		if v2 != nil {
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*math.MaxInt8))))), *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*14))), *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*15))))
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))))
			nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 5, 90, 5)
			nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 14, 90, 5)
			nox_xxx_aud_501960(846, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 0, 0)
		}
	}
}
func nox_xxx_collidePoisonGasTrap_4EB910(a1 *int32, a2 int32) {
	var (
		v2 *uint32
		v3 *uint32
	)
	_ = v3
	var v4 float32
	if a2 != 0 && sub_4E9A30((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), (*nox_object_t)(unsafe.Pointer(uintptr(a2)))) != 0 {
		v2 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("ToxicCloud"))))
		if v2 != nil {
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), (*nox_object_t)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*math.MaxInt8))))), *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*14))), *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*15))))
			v3 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*187)))))
			v4 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ToxicCloudLifetime")) * float64(int32(gameFPS())))
			*v3 = uint32(nox_float2int(v4))
			nox_xxx_aud_501960(847, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), 0, 0)
			nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))))
		}
	}
}
func sub_4EB9B0(a1 int32, a2 int32) int32 {
	var (
		v2     *uint32
		result int32
	)
	v2 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
	result = a2
	if a2 != 0 && (func() int32 {
		result = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(a2)))))))
		return result
	}()) != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(result + 8))))&4 != 0 {
		*v2 = uint32(result)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = uint32(*(*uint8)(unsafe.Pointer(uintptr(result + 52))))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = gameFrame()
	} else {
		*v2 = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = 0
	}
	return result
}
func nox_xxx_collideBall_4EBA00(a1 int32, a2 int32) {
	var (
		v2     *byte
		v3     *uint32
		result *uint32
	)
	v2 = nil
	v3 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
	if a2 != 0 {
		v2 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))))))
		if *v3 == uint32(a2) && v2 != nil && sub_418BC0(int32(uintptr(unsafe.Pointer(v2)))) > 1 {
			if (gameFrame() - *memmap.PtrUint32(0x5D4594, 1568008)) > 0x2D {
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), internCStr("objcoll.c:CantPickupBall"), 0)
				*memmap.PtrUint32(0x5D4594, 1568008) = gameFrame()
			}
			nox_xxx_aud_501960(928, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			return
		}
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 508))) != 0 || a2 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4) == 0 {
		nox_xxx_aud_501960(928, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		return
	}
	result = *(**uint32)(unsafe.Pointer(uintptr(a2 + 516)))
	if result != nil {
		for int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*2)))) != int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) {
			result = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*128)))))
			if result == nil {
				goto LABEL_17
			}
		}
		return
	}
LABEL_17:
	nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	if nox_xxx_servObjectHasTeam_419130(a1+48) != 0 {
		if v2 == nil {
			goto LABEL_25
		}
		sub_4196D0(unsafe.Pointer(uintptr(a1+48)), unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2))))), int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))), 0)
	} else {
		nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52))), unsafe.Pointer(uintptr(a1+48)), 1, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))), 0)
	}
	if v2 != nil {
		if *(*byte)(unsafe.Add(unsafe.Pointer(v2), 56)) == 2 {
			sub_4E8290(4, int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))))
		} else {
			sub_4E8290(2, int16(*(*uint16)(unsafe.Pointer(uintptr(a2 + 36)))))
		}
	}
LABEL_25:
	sub_4EB9B0(a1, a2)
	nox_xxx_aud_501960(927, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) |= 0x40
	sub_4EA7A0(a2)
	return
}
func sub_4EBB50(a1 int32, a2 int32) int32 {
	var result int32
	result = a2
	if a2 != 0 && (*(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))&0x8020) == 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			result = sub_4F3400(a2, a1, 1)
		}
	}
	return result
}
func nox_xxx_collideHomeBase_4EBB80(a1 int32, a2 int32) int16 {
	var (
		v2  int32
		v3  int32
		v4  *int32
		v5  *byte
		v6  *byte
		v7  int32
		v8  int32
		v9  int32
		i   int32
		v11 int32
		j   int32
		v14 int32
	)
	v2 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
	v3 = nox_xxx_getNameId_4E3AA0(internCStr("GameBallStart"))
	v14 = v3
	if a2 != 0 {
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v3))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))
		if int32(uint16(int16(v3))) == v2 {
			v4 = *(**int32)(unsafe.Pointer(uintptr(a2 + 748)))
			v5 = nil
			v6 = nil
			if nox_xxx_servObjectHasTeam_419130(a1+48) != 0 {
				v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))))))
			}
			if *v4 != 0 && nox_xxx_servObjectHasTeam_419130(*v4+48) != 0 {
				v6 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(*v4 + 52)))))))
			}
			if v5 == v6 {
				nox_xxx_changeScore_4D8E90(*v4, 1)
				nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(*v4))))
			}
			if v5 != nil {
				nox_xxx_netChangeTeamID_419090(int32(uintptr(unsafe.Pointer(v5))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*13)))+1))
				if dword_5d4594_2650652 != 0 {
					v7 = *v4
					if v7 != 0 {
						v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 748))))
						if v8 != 0 {
							sub_425CA0(int32(*(*uint32)(unsafe.Pointer(uintptr(v8 + 276)))), 0)
						}
					}
				}
				nox_xxx_aud_501960(929, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
				nox_xxx_netSendPointFx_522FF0(-102, (*float2)(unsafe.Pointer(uintptr(a2+56))))
			}
			v9 = 0
			for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(i))))))) {
				if int32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) == v14 {
					v9++
				}
			}
			v11 = nox_common_randomInt_415FA0(0, v9-1)
			v3 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
			for j = v3; v3 != 0; j = v3 {
				*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v3))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v14))
				if int32(*(*uint16)(unsafe.Pointer(uintptr(j + 4)))) == v14 {
					if v11 == 0 {
						if j != 0 {
							nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
							nox_xxx_unitMove_4E7010((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*float2)(unsafe.Pointer(uintptr(j+56))))
							*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v3))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(nox_xxx_netSendPointFx_522FF0(-127, (*float2)(unsafe.Pointer(uintptr(a2+56))))))
							*(*uint32)(unsafe.Pointer(uintptr(a2 + 80))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(a2 + 84))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(a2 + 88))) = 0
							*(*uint32)(unsafe.Pointer(uintptr(a2 + 100))) = 0
						}
						return int16(v3)
					}
					v11--
				}
				v3 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(j)))))))
			}
		}
	}
	return int16(v3)
}
func nox_xxx_collideUndeadKiller_4EBD40(a1 int32, a2 int32, a3 int32) {
	var (
		v3  int32
		v4  *int32
		v5  uint16
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
	)
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 12))))&0x40 != 0 {
			v3 = a1
			v4 = *(**int32)(unsafe.Pointer(uintptr(a1 + 700)))
			v5 = uint16(nox_xxx_unitGetHP_4EE780((*nox_object_t)(unsafe.Pointer(uintptr(a2)))))
			v6 = *v4
			v11 = v6
			v7 = int32(v5)
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 72))))
			if v8 <= int32(v5) {
				if v8 != 0 {
					v10 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(v3)))))))
					(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v10, v3, v8, 6)
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
					*(*uint32)(unsafe.Pointer(uintptr(v11 + 72))) -= uint32(v8)
				} else {
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
				}
			} else {
				v9 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*nox_object_t)(unsafe.Pointer(uintptr(v3)))))))
				(*(*func(int32, int32, int32, int32, int32))(unsafe.Pointer(uintptr(a2 + 716))))(a2, v9, v3, v7, 6)
				*(*uint32)(unsafe.Pointer(uintptr(v11 + 72))) = uint32(v8 - v7)
			}
		}
	} else if a3 == 0 {
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
func nox_xxx_collideMonsterGen_4EBE10(a1 int32, a2 int32) {
	if a2 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
			nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748)))+72)), unsafe.Pointer(uintptr(a2)), unsafe.Pointer(uintptr(a1)), 19)
		}
	}
}
func sub_4EBE40(a1 int32, a2 int32) {
	var (
		v2 *float2
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 *uint32
	)
	v2 = (*float2)(unsafe.Pointer(uintptr(a1)))
	v7 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 700)))
	if nox_common_gameFlags_check_40A5C0(4096) && a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		sub_4D7520(0)
		v3 = 1
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
		if v4 == 0 {
			sub_4D71E0(int32(gameFrame()))
		} else {
			for {
				v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 748))))
				if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v5 + 276))) + 4792))) == 1 && *(*uint32)(unsafe.Pointer(uintptr(v5 + 308))) != 0 {
					v3 = 0
				}
				v4 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(v4)))))))
				if v4 == 0 {
					break
				}
			}
			if v3 == 1 {
				sub_4D71E0(int32(gameFrame()))
			}
		}
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		if *(**float2)(unsafe.Pointer(uintptr(v6 + 308))) != v2 || (gameFrame()-*v7) > uint32(int32(gameFPS())) {
			nox_xxx_aud_501960(1005, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 0, 0)
			nox_xxx_netSendPointFx_522FF0(-126, (*float2)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(float2{})*7)))
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), internCStr("objcoll.c:SoulGateCollide"), 0)
		}
		*(*uint32)(unsafe.Pointer(uintptr(v6 + 308))) = uint32(uintptr(unsafe.Pointer(v2)))
		*v7 = gameFrame()
	}
}
func nox_xxx_collideAnkhQuest_4EBF40(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  *uint32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 *uint32
		v12 *uint32
		v13 int32
		v14 int32
		v15 *uint32
		v16 uint8
		v17 float32
		v18 int32
		v19 int32
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	v19 = 0
	if a2 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&4 != 0 {
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
		v5 = 0
		v6 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 4796)))
		for *v6 != uint32(a1) {
			v5++
			v6 = (*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v5 >= 5 {
				goto LABEL_8
			}
		}
		v19 = 1
	LABEL_8:
		v18 = 0
		v7 = v3 + 50
		for {
			if gameFrame()-*(*uint32)(unsafe.Pointer(uintptr(v7 + 26))) > (gameFPS() * 240) {
				nox_wcscpy((*wchar2_t)(unsafe.Pointer(uintptr(v7-50))), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1568012)))
				*(*uint8)(unsafe.Pointer(uintptr(v7 + 1))) = *memmap.PtrUint8(0x5D4594, 1568016)
				*(*uint8)(unsafe.Pointer(uintptr(v7))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v7 + 26))) = 0
			}
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v7)))) == int32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 2251)))) && nox_wcscmp((*wchar2_t)(unsafe.Pointer(uintptr(v7-50))), (*wchar2_t)(unsafe.Pointer(uintptr(v8+2185)))) == 0 {
				if libc.StrCmp((*byte)(unsafe.Pointer(uintptr(v7+1))), (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276)))+2112)))) == 0 {
					v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
					v10 = 0
					v11 = (*uint32)(unsafe.Pointer(uintptr(v9 + 4796)))
					for *v11 != 0 {
						v10++
						v11 = (*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
						if v10 >= 5 {
							v2 = a2
							goto LABEL_17
						}
					}
					v2 = a2
					*(*uint32)(unsafe.Pointer(uintptr(v9 + v10*4 + 4796))) = uint32(a1)
				LABEL_17:
					if (uint64(nox_platform_get_ticks()) - qword_5d4594_1567940) <= 0x5DC {
						return
					}
					nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v2))), internCStr("objcoll.c:ExtraLifeAlreadyAwarded"), 0)
					nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 0, 0)
					qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
					return
				}
				v2 = a2
			}
			v7 += 80
			v18++
			if v18 >= 64 {
				break
			}
		}
		if v19 == 1 {
			if (uint64(nox_platform_get_ticks()) - qword_5d4594_1567940) <= 0x5DC {
				return
			}
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v2))), internCStr("objcoll.c:ExtraLifeAlreadyAwarded"), 0)
			nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 0, 0)
			qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
			return
		}
		v17 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MaxExtraLives")))
		if *(*uint32)(unsafe.Pointer(uintptr(v4 + 320))) < uint32(nox_float2int(v17)) {
			v12 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("AnkhTradable"))))
			if v12 != nil {
				(asFunc(*(*uint32)(unsafe.Add(unsafe.Pointer(v12), 4*177)), (*func(int32, *uint32, int32, uint32))(nil)).(func(int32, *uint32, int32, uint32)))(v2, v12, 1, 0)
			}
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) = gameFrame()
			nox_xxx_aud_501960(1004, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			nox_xxx_netSendPointFx_522FF0(-126, (*float2)(unsafe.Pointer(uintptr(a1+56))))
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v2))), internCStr("objcoll.c:AwardExtraLife"), 0)
			v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
			v14 = 0
			v15 = (*uint32)(unsafe.Pointer(uintptr(v13 + 4796)))
			for *v15 != 0 {
				v14++
				v15 = (*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*1))
				if v14 >= 5 {
					goto LABEL_35
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(v13 + v14*4 + 4796))) = uint32(a1)
		LABEL_35:
			nox_wcscpy((*wchar2_t)(unsafe.Pointer(uintptr(v3+int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120))))*80))), (*wchar2_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276)))+2185))))
			*(*uint8)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120))))*80 + v3 + 50))) = *(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251)))
			libc.StrCpy((*byte)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120))))*80+v3+51))), (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276)))+2112))))
			*(*uint32)(unsafe.Pointer(uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120))))*80 + v3 + 76))) = gameFrame()
			v16 = uint8(int8(int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120)))) + 1))
			*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120))) = v16
			if int32(v16) >= 0x40 {
				*(*uint8)(unsafe.Pointer(uintptr(v3 + 5120))) = 0
			}
		} else if (uint64(nox_platform_get_ticks()) - qword_5d4594_1567940) > 0x5DC {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v2))), internCStr("pickup.c:MaxTradableAnkhsReached"), 0)
			nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(v2))), 0, 0)
			qword_5d4594_1567940 = uint64(nox_platform_get_ticks())
			return
		}
	}
}
func nox_xxx_unitSetOwner_4EC290(obj1 *nox_object_t, obj2 *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj1)))
		a2 int32 = int32(uintptr(unsafe.Pointer(obj2)))
	)
	if a2 == 0 {
		return
	}
	nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
	var v2 int32 = a1
	if a1 != 0 {
		for int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 16))))&0x20 != 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 508))))
			if v2 == 0 {
				break
			}
		}
		if v2 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 512))) = *(*uint32)(unsafe.Pointer(uintptr(v2 + 516)))
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 516))) = uint32(a2)
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(a2 + 508))) = uint32(v2)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&2 != 0 {
		nox_xxx_monsterResetEnemy_5346F0(a2)
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&6 != 0 {
		nox_xxx_monsterMarkUpdate_4E8020((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
	}
}
func nox_xxx_unitClearOwner_4EC300(obj *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(obj)))
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int8
	)
	if a1 != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
		if v1 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))))&4 != 0 && nox_xxx_creatureIsMonitored_500CC0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), (*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 {
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
				*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(v2 & math.MaxInt8))
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))) + 748))))
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))) = uint32(v2)
				nox_xxx_netFxShield_0_4D9200(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), a1)
				nox_xxx_netUnmarkMinimapObj_417300(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2064)))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 1)
			}
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
			v5 = 0
			v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 516))))
			if v6 == 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v4 + 516))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 512)))
			} else {
				for {
					if v6 == a1 {
						break
					}
					v5 = v6
					v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 512))))
					if v6 == 0 {
						break
					}
				}
				if v5 != 0 {
					*(*uint32)(unsafe.Pointer(uintptr(v5 + 512))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 512)))
				} else {
					*(*uint32)(unsafe.Pointer(uintptr(v4 + 516))) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 512)))
				}
			}
			v7 = int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))) = 0
			if int32(v7)&2 != 0 {
				nox_xxx_monsterResetEnemy_5346F0(a1)
			}
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6 != 0 {
				nox_xxx_monsterMarkUpdate_4E8020((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			}
		}
	}
}
func nox_xxx_playerObserverFindGoodSlave2_4EC3E0(a1 int32) int32 {
	var result int32
	if a1 == 0 {
		return 0
	}
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516))))
	if result == 0 {
		return 0
	}
	for (int32(*(*uint8)(unsafe.Pointer(uintptr(result + 8))))&2) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(result + 748))) + 1440))))&0x80) == 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 512))))
		if result == 0 {
			return 0
		}
	}
	return result
}
func nox_xxx_playerObserverFindGoodSlave_4EC420(a1 int32) int32 {
	var result int32
	if a1 == 0 {
		return 0
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 508))) == 0 {
		return 0
	}
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 512))))
	if result == 0 {
		return 0
	}
	for (int32(*(*uint8)(unsafe.Pointer(uintptr(result + 8))))&2) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(result + 748))) + 1440))))&0x80) == 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 512))))
		if result == 0 {
			return 0
		}
	}
	return result
}
func nox_xxx_unitRemoveChild_4EC470(a1 *nox_object_t) {
	var (
		v1 int32
		v2 int32
	)
	if a1 != nil {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))) + 516))))
		if v1 != 0 {
			for {
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 512))))
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 508))) = 0
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 512))) = 0
				v1 = v2
				if v2 == 0 {
					break
				}
			}
		}
		*(*uint32)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1))) + 516))) = 0
	}
}
func nox_xxx_unitTransferSlaves_4EC4B0(a1p *nox_object_t) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v2 int32
	)
	if a1 != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516))))
		if v1 != 0 {
			for {
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 512))))
				nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508)))))), (*nox_object_t)(unsafe.Pointer(uintptr(v1))))
				v1 = v2
				if v2 == 0 {
					break
				}
			}
		}
	}
}
func nox_xxx_unitsHaveSameTeam_4EC520(a1p *nox_object_t, a2p *nox_object_t) int32 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v2 int32
		v3 int32
	)
	v2 = a1
	if a1 != 0 && a2 != 0 {
		for 2 != 0 {
			v3 = a2
			for {
				if nox_xxx_servCompareTeams_419150(v2+48, v3+48) != 0 || v2 == v3 {
					return 1
				}
				v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 508))))
				if v3 == 0 {
					break
				}
			}
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 508))))
			if v2 != 0 {
				continue
			}
			break
		}
	}
	return 0
}
func sub_4EC5B0() {
	dword_5d4594_1568024 = 0
	nox_alloc_class_free_all((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_alloc_respawn_1568020)))))
	nox_xxx_respawnAllow_587000_205200 = 1
}
func nox_xxx_respawnAdd_4EC5E0(a1p *nox_object_t) *uint32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result *uint32
		v2     *uint32
		v3     uint16
		v4     *uint8
	)
	result = *(**uint32)(unsafe.Pointer(&nox_xxx_respawnAllow_587000_205200))
	if nox_xxx_respawnAllow_587000_205200 != 0 {
		result = (*uint32)(nox_alloc_class_new_obj_zero((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_alloc_respawn_1568020))))))
		v2 = result
		if result != nil {
			v3 = *(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = uint32(a1)
			*result = uint32(v3)
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*2)) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 56)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 60)))
			*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*8))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 124)))
			if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x13001000 != 0 {
				alloc.Memcpy(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*7))), *(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1 + 692))), 0x14)
			}
			if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 && nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(a1))))&0x82 != 0 {
				v4 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 736)))
				*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 48))) = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 1))
				*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 49))) = *v4
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*14)) = 0
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*13)) = dword_5d4594_1568024
			result = *(**uint32)(unsafe.Pointer(&dword_5d4594_1568024))
			if dword_5d4594_1568024 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1568024 + 56))) = uint32(uintptr(unsafe.Pointer(v2)))
			}
			dword_5d4594_1568024 = uint32(uintptr(unsafe.Pointer(v2)))
		}
	}
	return result
}
func sub_4EC6A0(a1 int32) {
	var (
		v1 int32
		v2 *uint64
		v3 int32
		v4 int32
		v5 int32
	)
	v1 = int32(dword_5d4594_1568024)
	if *(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1568024 + 4))) == uint32(a1) {
		v2 = *(**uint64)(unsafe.Pointer(&dword_5d4594_1568024))
		dword_5d4594_1568024 = *(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_1568024 + 52)))
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 52))))
		if v3 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 56))) = 0
		}
		nox_alloc_class_free_obj_first((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_alloc_respawn_1568020)))), unsafe.Pointer(v2))
	} else if dword_5d4594_1568024 != 0 {
		for *(*uint32)(unsafe.Pointer(uintptr(v1 + 4))) != uint32(a1) {
			v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 52))))
			if v1 == 0 {
				return
			}
		}
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 56))))
		if v4 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v4 + 52))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 52)))
		}
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 52))))
		if v5 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 56))) = *(*uint32)(unsafe.Pointer(uintptr(v1 + 56)))
		}
		nox_alloc_class_free_obj_first((*nox_alloc_class)(unsafe.Pointer(*(**uint32)(unsafe.Pointer(&nox_alloc_respawn_1568020)))), unsafe.Pointer(uintptr(v1)))
	}
}
func nox_xxx_allocItemRespawnArray_4ECA60() int32 {
	nox_alloc_respawn_1568020 = unsafe.Pointer(nox_new_alloc_class(internCStr("Respawn"), 60, 384))
	return bool2int32(nox_alloc_respawn_1568020 != nil)
}
func sub_4ECA90() {
	nox_free_alloc_class((*nox_alloc_class)(nox_alloc_respawn_1568020))
}
func sub_4ECBD0(a1 int32) int32 {
	var result int32
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x10000000 != 0 {
		result = sub_4ECC00(*(***byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))) + 4))))
	} else {
		result = 0
	}
	return result
}
func sub_4ECC00(a1 **byte) int32 {
	var (
		v1 *byte
		v2 int32
		v3 *uint8
	)
	if a1 == nil {
		return 0
	}
	v1 = *(**byte)(memmap.PtrOff(0x587000, 205224))
	v2 = 0
	if *memmap.PtrUint32(0x587000, 205224) == 0 {
		return 0
	}
	v3 = (*uint8)(memmap.PtrOff(0x587000, 205224))
	for libc.StrCmp(*a1, v1) != 0 {
		v1 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*2))))))
		v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 8))
		v2++
		if v1 == nil {
			return 0
		}
	}
	return int32(*memmap.PtrUint32(0x587000, uintptr(v2*8)+205228))
}
func nox_server_getObjectFromNetCode_4ECCB0(a1 int32) *nox_object_t {
	var (
		result int32
		v2     int32
		v3     int32
		v4     *byte
		v5     int32
	)
	result = nox_server_netCodeCache_lookupObj_4ECD90(a1)
	if result != 0 {
		return (*nox_object_t)(unsafe.Pointer(uintptr(result)))
	}
	v2 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v2 != 0 {
		for {
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 16))))&0x20) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v2 + 36))) == uint32(a1) {
				nox_server_netCodeCache_addObj_4ECEA0(v2)
				return (*nox_object_t)(unsafe.Pointer(uintptr(v2)))
			}
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 504))))
			if v3 != 0 {
				for int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 16))))&0x20 != 0 || *(*uint32)(unsafe.Pointer(uintptr(v3 + 36))) != uint32(a1) {
					v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 496))))
					if v3 == 0 {
						goto LABEL_9
					}
				}
				nox_server_netCodeCache_addObj_4ECEA0(v3)
				return (*nox_object_t)(unsafe.Pointer(uintptr(v3)))
			}
		LABEL_9:
			v2 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(v2)))))))
			if v2 == 0 {
				goto LABEL_10
			}
		}
	}
LABEL_10:
	v3 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObjectUninited_4DA870())))
	if v3 != 0 {
		for int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 16))))&0x20 != 0 || *(*uint32)(unsafe.Pointer(uintptr(v3 + 36))) != uint32(a1) {
			v3 = int32(uintptr(unsafe.Pointer(nox_server_getNextObjectUninited_4DA880((*nox_object_t)(unsafe.Pointer(uintptr(v3)))))))
			if v3 == 0 {
				goto LABEL_17
			}
		}
		nox_server_netCodeCache_addObj_4ECEA0(v3)
		return (*nox_object_t)(unsafe.Pointer(uintptr(v3)))
	}
LABEL_17:
	v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	if v4 == nil {
		return nil
	}
	for {
		v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*514))))
		if v5 != 0 {
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 16))))&0x20) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v5 + 36))) == uint32(a1) {
				break
			}
		}
		v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*nox_playerInfo)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v4)))))))))
		if v4 == nil {
			return nil
		}
	}
	return (*nox_object_t)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*514))))))
}

var nox_server_netCodeCache nox_server_netCodeCacheStruct

func nox_server_netCodeCache_lookupObj_4ECD90(a1 int32) int32 {
	var v1 *uint32
	if nox_server_needInitNetCodeCache != 0 {
		nox_server_netCodeCache_initArray_4ECE50()
	}
	v1 = *(**uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject))
	if *(*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)) == 0 {
		return 0
	}
	for *(*uint32)(unsafe.Pointer(uintptr(*v1 + 36))) != uint32(a1) {
		v1 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)))))
		if v1 == nil {
			return 0
		}
	}
	sub_4ECE10((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), int32(uintptr(unsafe.Pointer(v1))))
	sub_4ECDE0((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), int32(uintptr(unsafe.Pointer(v1))))
	return int32(*v1)
}
func sub_4ECDE0(a1 *uint32, a2 int32) int32 {
	var result int32
	result = a2
	*(*uint32)(unsafe.Pointer(uintptr(a2 + 4))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))) = *a1
	if *a1 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(*a1 + 4))) = uint32(a2)
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = uint32(a2)
	}
	*a1 = uint32(a2)
	return result
}
func sub_4ECE10(a1 *uint32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
	)
	result = a2
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
	if v3 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 4)))
	} else {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 4)))
	}
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 4))))
	if v4 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 8))) = *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))
	} else {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 8))))
		*a1 = uint32(result)
	}
	return result
}
func nox_server_netCodeCache_initArray_4ECE50() int32 {
	var (
		v0     *uint8
		result int32
	)
	v0 = (*uint8)(unsafe.Pointer(&nox_server_netCodeCache.objArray[0]))
	nox_server_netCodeCache.firstUsedObject = nil
	nox_server_netCodeCache.lastUsedObject = nil
	nox_server_netCodeCache.firstFreeObject = nil
	nox_server_netCodeCache.lastFreeObject = nil
	for {
		result = sub_4ECDE0((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstFreeObject)), int32(uintptr(unsafe.Pointer(v0))))
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 12))
		if uintptr(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v0)))))) >= uintptr(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)) {
			break
		}
	}
	nox_server_needInitNetCodeCache = 0
	return result
}
func nox_server_netCodeCache_addObj_4ECEA0(a1 int32) int32 {
	var (
		v1     *int32
		v2     int32
		result int32
		v4     int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(nox_server_netCodeCache_nextUnused_4ECEF0())))
	if v1 != nil {
		*v1 = a1
		result = sub_4ECDE0((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), int32(uintptr(unsafe.Pointer(v1))))
	} else {
		v2 = int32(uintptr(unsafe.Pointer(nox_server_netCodeCache.lastUsedObject)))
		v4 = int32(uintptr(unsafe.Pointer(nox_server_netCodeCache.lastUsedObject)))
		nox_server_netCodeCache.lastUsedObject.value = unsafe.Pointer(uintptr(a1))
		sub_4ECE10((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), v4)
		result = sub_4ECDE0((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), v2)
	}
	return result
}
func nox_server_netCodeCache_nextUnused_4ECEF0() int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(nox_server_netCodeCache.firstFreeObject)))
	if nox_server_netCodeCache.firstFreeObject == nil {
		return 0
	}
	nox_server_netCodeCache.firstFreeObject = (*nox_dblLinkedList)(nox_server_netCodeCache.firstFreeObject.prev)
	return result
}
func sub_4ECF10(a1 int32) int32 {
	var result int32 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	for result != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(result + 16))))&0x20 == 0 && *(*uint32)(unsafe.Pointer(uintptr(result + 44))) == uint32(a1) {
			return result
		}
		var v2 int32 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 504))))
		for v2 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 16))))&0x20 == 0 && *(*uint32)(unsafe.Pointer(uintptr(v2 + 44))) == uint32(a1) {
				return v2
			}
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 496))))
		}
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
	}
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObjectUninited_4DA870())))
	for result != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(result + 16))))&0x20) == 0 && *(*uint32)(unsafe.Pointer(uintptr(result + 44))) == uint32(a1) {
			return result
		}
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObjectUninited_4DA880((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
	}
	var obj *nox_object_t = nox_xxx_getFirstUpdatable2Object_4DA840()
	for obj != nil {
		if (obj.obj_flags&0x20) == 0 && obj.script_id == a1 {
			return int32(uintptr(unsafe.Pointer(obj)))
		}
		obj = nox_xxx_getNextUpdatable2Object_4DA850(obj)
	}
	return int32(uintptr(unsafe.Pointer(obj)))
}
func sub_4ECFA0(a1 *nox_object_t) int32 {
	var (
		result int32
		v2     *uint32
	)
	result = int32(nox_server_needInitNetCodeCache)
	if nox_server_needInitNetCodeCache == 0 {
		v2 = *(**uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject))
		if *(*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)) != 0 {
			result = int32(uintptr(unsafe.Pointer(a1)))
			for unsafe.Pointer(uintptr(*v2)) != unsafe.Pointer(a1) {
				v2 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))))
				if v2 == nil {
					return result
				}
			}
			sub_4ECE10((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), int32(uintptr(unsafe.Pointer(v2))))
			result = sub_4ECDE0((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstFreeObject)), int32(uintptr(unsafe.Pointer(v2))))
		}
	}
	return result
}
func sub_4ECFE0() int32 {
	var (
		result int32
		v1     int32
		v2     int32
	)
	result = int32(nox_server_needInitNetCodeCache)
	if nox_server_needInitNetCodeCache == 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)))
		if *(*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)) != 0 {
			for {
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 8))))
				sub_4ECE10((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstUsedObject)), v1)
				result = sub_4ECDE0((*uint32)(unsafe.Pointer(&nox_server_netCodeCache.firstFreeObject)), v1)
				v1 = v2
				if v2 == 0 {
					break
				}
			}
		}
	}
	return result
}
func nox_xxx_netGetUnitByExtent_4ED020(a1 int32) int32 {
	var result int32
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if result == 0 {
		return 0
	}
	for int32(*(*uint8)(unsafe.Pointer(uintptr(result + 16))))&0x20 != 0 || *(*uint32)(unsafe.Pointer(uintptr(result + 40))) != uint32(a1) {
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
		if result == 0 {
			return 0
		}
	}
	return result
}
func sub_4ED050(a1 int32, a2 int32) {
	var (
		v2 int32
		i  int32
		v4 int32
	)
	*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = *memmap.PtrUint16(0x5D4594, 1568248)
	if *memmap.PtrUint32(0x5D4594, 1568248) == 0 {
		v2 = nox_xxx_getNameId_4E3AA0(internCStr("Crown"))
		*memmap.PtrUint32(0x5D4594, 1568248) = uint32(v2)
	}
	for i = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 516)))); i != 0; i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 512)))) {
		*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Pointer(uintptr(i + 4)))
		if uint32(uint16(int16(v2))) == *memmap.PtrUint32(0x5D4594, 1568248) {
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 748))))
			*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v2))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(nox_xxx_dropCrown_4ED5E0(a1, i, (*int32)(unsafe.Pointer(uintptr(a1+56))))))
			*(*uint32)(unsafe.Pointer(uintptr(v4 + 4))) = uint32(a2)
		}
	}
}
func sub_4ED0C0(a1p *nox_object_t, object *nox_object_t) {
	var (
		a1  int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		i   int32
		v10 int32
	)
	v2 = 1
	if a1 != 0 && object != nil {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v3&4 != 0 {
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			if !nox_common_gameFlags_check_40A5C0(4096) && (*(*uint32)(unsafe.Pointer(uintptr(a1 + 16)))&0x8000) == 0x8000 && object.obj_class&0x13001000 != 0 {
				v2 = 0
			}
			if object.obj_class&0x10000000 != 0 {
				if nox_common_gameFlags_check_40A5C0(32) {
					*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 4))) &= 0xFFFFFFFE
					if v2 == 1 {
						nox_xxx_netReportDequip_4D84C0(math.MaxUint8, object)
					}
				}
			}
			sub_53E430((*uint32)(unsafe.Pointer(uintptr(a1))), object, 0, v2)
			nox_xxx_playerDequipWeapon_53A140((*uint32)(unsafe.Pointer(uintptr(a1))), object, 0, v2)
			nox_xxx_netReportDrop_4D8B50(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2064)))), object)
			nox_xxx_protect_56FC50(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 4632)))), object)
		} else if v3&2 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 && object.obj_class&0x10000000 != 0 && nox_common_gameFlags_check_40A5C0(32) {
				nox_xxx_npcSetItemEquipFlags_4E4B20(a1, object, 0)
			}
			sub_53E430((*uint32)(unsafe.Pointer(uintptr(a1))), object, 1, 1)
			nox_xxx_playerDequipWeapon_53A140((*uint32)(unsafe.Pointer(uintptr(a1))), object, 1, 1)
		}
		v5 = int32(uintptr(unsafe.Pointer(object.field_125)))
		if v5 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 496))) = uint32(uintptr(unsafe.Pointer(object.inv_next_item)))
		} else {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))) = uint32(uintptr(unsafe.Pointer(object.inv_next_item)))
		}
		v6 = int32(uintptr(unsafe.Pointer(object.inv_next_item)))
		if v6 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v6 + 500))) = uint32(uintptr(unsafe.Pointer(object.field_125)))
		}
		object.inv_holder = nil
		nox_xxx_unitClearOwner_4EC300(object)
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
			v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			for i = 0; v7 != 0; i += v10 {
				v10 = int32(*(*uint8)(unsafe.Pointer(uintptr(v7 + 488))))
				v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 496))))
			}
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v8 + 276))) + 3656))) = uint32(bool2int32(i > int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 490))))))
		}
	}
}
func nox_xxx_dropDefault_4ED290(a1p *nox_object_t, a2p *nox_object_t, a3 *float2) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2     int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3     int32
		result int32
		v5     *int32
		v6     int32
		v7     int32
		v8     int32
		v9     int8
		v10    int32
		v11    int32
		v12    int32
		v13    [10]byte
		v14    uint8
	)
	v3 = a1
	if *(*uint32)(unsafe.Pointer(uintptr(a2 + 492))) != uint32(a1) {
		return 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && nox_xxx_ItemIsDroppable_53EBF0(a2) != 0 && sub_53EC80(a2, 1) != 0 {
		if (*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) & 0x8020) == 0 {
			nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), internCStr("drop.c:CantDropThat"), 0)
			nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))))
		}
		result = 0
	} else {
		sub_4ED0C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))))
		nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(a2))), nil, a3.field_0, a3.field_4)
		if *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x1000000 != 0 {
			if nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(a2)))) == 4 {
				v5 = *(**int32)(unsafe.Pointer(uintptr(a1 + 504)))
				if v5 != nil {
					for {
						if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*2)))&0x1000000 != 0 {
							if nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5))))))) == 2 {
								v6 = *(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*4))
								if (v6 & 0x100) == 0 {
									if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*184)) + 2)))) != 0 {
										break
									}
								}
							}
						}
						v5 = (*int32)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v5), 4*124)))))
						if v5 == nil {
							goto LABEL_19
						}
					}
					sub_4ED0C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(v5)))
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v5)))))))
				}
			}
		}
	LABEL_19:
		if *(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x10000000 != 0 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
			v8 = sub_4ECBD0(a2)
			v9 = int8(v8)
			v14 = *(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))
			*(*uint32)(unsafe.Pointer(&v13[2])) = *(*uint32)(unsafe.Pointer(uintptr(v3 + 36)))
			*(*uint32)(unsafe.Pointer(&v13[6])) = uint32(v8)
			nox_xxx_netInformTextMsg2_4DA180(7, (*uint8)(unsafe.Pointer(&v13[0])))
			nox_xxx_netMarkMinimapForAll_4174B0(a2, 1)
			*(*uint32)(unsafe.Pointer(uintptr(v7 + 8))) = gameFrame()
			sub_4E82C0(v14, 2, v9, 0)
		}
		if *memmap.PtrUint32(0x5D4594, 1568252) == 0 {
			*memmap.PtrUint32(0x5D4594, 1568252) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
		}
		if !nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) && (*(*uint32)(unsafe.Pointer(uintptr(a2 + 16)))&0x80000) == 0 && (*(*uint32)(unsafe.Pointer(uintptr(a2 + 8)))&0x10000000) == 0 && uint32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))) != *memmap.PtrUint32(0x5D4594, 1568252) {
			nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(uintptr(a2))), int32(gameFPS()*10))
		}
		nox_xxx_unitRaise_4E46F0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0.0)
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&0x40 != 0 {
			nox_xxx_aud_501960(821, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
		}
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 8))))&2 != 0 {
			v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
			v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v10 + 1440))))
			*(*uint32)(unsafe.Pointer(uintptr(v10 + 1360))) = 15
			*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v11))), 1)) |= 1
			*(*uint32)(unsafe.Pointer(uintptr(v10 + 1440))) = uint32(v11)
		}
		if *memmap.PtrUint32(0x5D4594, 1568256) == 0 {
			*memmap.PtrUint32(0x5D4594, 1568256) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Torch")))
			*memmap.PtrUint32(0x5D4594, 1568244) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Lantern")))
		}
		v12 = int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4))))
		if uint32(uint16(int16(v12))) == *memmap.PtrUint32(0x5D4594, 1568256) || uint32(v12) == *memmap.PtrUint32(0x5D4594, 1568244) {
			nox_xxx_spellBuffOff_4FF5B0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), 15)
		}
		result = 1
	}
	return result
}
func nox_GlyphDrop_4ED500(a1 int32, a2 int32, a3 *float2) int32 {
	var (
		v3 int16
		v5 float2
	)
	if nox_xxx_dropTrap_4ED580(a1, a2, a3) == 0 {
		return 0
	}
	*(*float2)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a2 + 692))) + 28))) = *a3
	v5.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56))) - a3.field_0
	v5.field_4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60))) - a3.field_4
	v3 = int16(nox_xxx_math_509ED0(&v5))
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 126))) = uint16(v3)
	*(*uint16)(unsafe.Pointer(uintptr(a2 + 124))) = uint16(v3)
	nox_xxx_aud_501960(825, (*nox_object_t)(unsafe.Pointer(uintptr(a2))), 0, 0)
	return 1
}
func nox_xxx_dropTrap_4ED580(a1 int32, a2 int32, a3 *float2) int32 {
	if nox_xxx_mapTileAllowTeleport_411A90(a3) != 0 {
		nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))))
		return 0
	}
	if nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3) == 0 {
		return 0
	}
	nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))))
	return 1
}
func nox_xxx_dropCrown_4ED5E0(a1 int32, a2 int32, a3 *int32) int32 {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 int32
		v11 [10]byte
	)
	if !nox_common_gameFlags_check_40A5C0(16) || !nox_xxx_CheckGameplayFlags_417DA0(4) {
		v3 = a2
		v8 = a1
		goto LABEL_15
	}
	v3 = a2
	v4 = int32(gameFrame())
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))) == 0 {
		v8 = a1
		goto LABEL_15
	}
	v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	v5 = a2
	v6 = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	if v6 != 0 {
		for {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + 748))))
			if nox_xxx_teamCompare2_419180(unsafe.Pointer(uintptr(v6+48)), *(*uint8)(unsafe.Pointer(uintptr(a2 + 52)))) != 0 && *(*uint32)(unsafe.Pointer(uintptr(v7 + 264))) < uint32(v4) {
				v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 264))))
				v5 = v6
			}
			v6 = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(v6)))))))
			if v6 == 0 {
				break
			}
		}
		v3 = a2
	}
	v8 = a1
	if v5 != 0 && a1 != v5 {
		*(*uint32)(unsafe.Pointer(uintptr(v10 + 4))) = uint32(v5)
	}
LABEL_15:
	if nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(v8))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*float2)(unsafe.Pointer(a3))) == 0 {
		return 0
	}
	nox_xxx_unitClearOwner_4EC300((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
	nox_xxx_spellBuffOff_4FF5B0((*nox_object_t)(unsafe.Pointer(uintptr(v8))), 30)
	*(*uint32)(unsafe.Pointer(&v11[2])) = *(*uint32)(unsafe.Pointer(uintptr(v8 + 36)))
	if nox_xxx_servObjectHasTeam_419130(v8+48) != 0 {
		*(*uint32)(unsafe.Pointer(&v11[6])) = uint32(*(*uint8)(unsafe.Pointer(uintptr(v8 + 52))))
	} else {
		*(*uint32)(unsafe.Pointer(&v11[6])) = 0
	}
	nox_xxx_netInformTextMsg2_4DA180(11, (*uint8)(unsafe.Pointer(&v11[0])))
	nox_xxx_netMarkMinimapForAll_4174B0(v3, 1)
	return 1
}
func nox_xxx_dropTreasure_4ED710(a1 int32, a2 int32, a3 *int32) int32 {
	var v3 int32
	if nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*float2)(unsafe.Pointer(a3))) == 0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
		if nox_common_gameFlags_check_40A5C0(64) {
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2152)))--
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2156))) = uint32(nox_xxx_scavengerTreasureMax_4D1600())
			nox_xxx_scavengerHuntReport_4D8CD0(a1)
			nox_xxx_aud_501960(308, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
	return 1
}
func nox_xxx_drop_4ED790(a1p *nox_object_t, a2p *nox_object_t, a3 *float2) int32 {
	var (
		a1     int32   = int32(uintptr(unsafe.Pointer(a1p)))
		a2     *uint32 = (*uint32)(unsafe.Pointer(a2p))
		result int32
		v4     func(int32, *uint32, *float2) int32
	)
	if a2 == nil {
		return 0
	}
	if nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) && *(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*2))&0x3001010 != 0 {
		*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)) |= 0x40
		nox_xxx_unit_511810((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))))
	}
	v4 = asFunc(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*178)), (*func(int32, *uint32, *float2) int32)(nil)).(func(int32, *uint32, *float2) int32)
	if v4 != nil {
		result = v4(a1, a2, a3)
	} else {
		result = nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))), a3)
	}
	return result
}
func nox_xxx_drop_4ED810(a1 int32, a2 int32, a3 *float32) int32 {
	var (
		v3     int32
		v4     float32
		v5     float32
		v6     float64
		v7     float64
		v8     float64
		result int32
	)
	_ = result
	var v10 int32
	var v11 float4
	var v12 float32
	var v13 float32
	v3 = a1
	v4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
	v11.field_0 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
	v11.field_4 = v4
	v5 = *(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))
	v11.field_8 = *a3
	v11.field_C = v5
	v6 = float64(v11.field_8 - v11.field_0)
	v7 = float64(v5 - v4)
	v12 = float32(v7)
	v8 = math.Sqrt(v7*float64(v12) + v6*v6)
	v13 = float32(v8)
	if v8 > 75.0 {
		v11.field_8 = float32(v6*75.0/float64(v13) + float64(v11.field_0))
		v11.field_C = float32(float64(v12)*75.0/float64(v13) + float64(v11.field_4))
	}
	if nox_xxx_mapTraceRay_535250(&v11, nil, nil, 0) != 0 {
		if !nox_common_gameFlags_check_40A5C0(16) {
			return nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*float2)(unsafe.Pointer(&v11.field_8)))
		}
		v10 = int32(*memmap.PtrUint32(0x5D4594, 1568248))
		if *memmap.PtrUint32(0x5D4594, 1568248) == 0 {
			v10 = nox_xxx_getNameId_4E3AA0(internCStr("Crown"))
			*memmap.PtrUint32(0x5D4594, 1568248) = uint32(v10)
		}
		if int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4)))) == v10 {
			return 0
		} else {
			return nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(v3))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*float2)(unsafe.Pointer(&v11.field_8)))
		}
	} else {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("drop.c:DropNotAllowed"), 0)
		nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(v3))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 36)))))
		return 0
	}
}
func nox_xxx_invForceDropItem_4ED930(a1 int32, a2 *uint32) int32 {
	var v3 float2
	sub_4ED970(50.0, (*float2)(unsafe.Pointer(uintptr(a1+56))), &v3)
	return nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(a2)), &v3)
}
func sub_4ED970(a1 float32, a2 *float2, a3 *float2) *float2 {
	var (
		v3     *float2
		v4     float32
		v5     int32
		v6     float64
		result *float2
		v8     float32
		v9     float32
		v10    float4
		v11    float32
	)
	v3 = a2
	v4 = a2.field_4
	v9 = float32(float64(a1) * 0.015625)
	v10.field_0 = a2.field_0
	v10.field_4 = v4
	v11 = float32(nox_common_randomFloat_416030(-3.1415927, 3.1415927))
	v5 = 0
	for {
		v6 = float64(v11) + 1.8849558
		v11 = float32(v6)
		v10.field_8 = float32(math.Cos(v6)*float64(a1) + float64(v3.field_0))
		v10.field_C = float32(math.Sin(float64(v11))*float64(a1) + float64(v3.field_4))
		if nox_xxx_mapTraceRay_535250(&v10, nil, nil, 1) != 0 {
			break
		}
		v5++
		a1 = a1 - v9
		if v5 >= 64 {
			result = a3
			*a3 = *v3
			return result
		}
	}
	result = a3
	v8 = v10.field_C
	a3.field_0 = v10.field_8
	a3.field_4 = v8
	return result
}
func nox_xxx_dropAllItems_4EDA40(a1 *uint32) *uint32 {
	var (
		v1     *float2
		v2     int32
		v3     int32
		result *uint32
		v5     float32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    *uint32
		v11    *uint32
		v12    float32
		v13    float32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		v18    *uint32
		v19    *uint32
		v20    int32
		v21    int32
		v22    float4
		v23    *uint32
	)
	v1 = (*float2)(unsafe.Pointer(a1))
	v2 = 0
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*126)))
	v12 = 0.0
	for v3 != 0 {
		if nox_xxx_unitDropCheckSome_4EDCD0(int32(uintptr(unsafe.Pointer(a1))), v3) != 0 && float64(*(*float32)(unsafe.Pointer(uintptr(v3 + 176)))) > float64(v12) {
			v12 = *(*float32)(unsafe.Pointer(uintptr(v3 + 176)))
		}
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 496))))
	}
	result = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*126)))))
	v5 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*15)))
	v6 = -1
	v15 = 0
	v7 = 3
	v20 = 0
	v21 = -1
	v14 = 0
	v16 = 0
	v22.field_0 = *((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(a1))), unsafe.Sizeof(float32(0))*14)))
	v22.field_4 = v5
	v23 = result
	v13 = float32(float64(v12+v12) + 6.0)
	if result == nil {
		return result
	}
	for 2 != 0 {
		v19 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*124)))))
		if nox_xxx_unitDropCheckSome_4EDCD0(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(result)))) == 0 {
			v8 = 1
		} else {
			v17 = 0
			v18 = (*uint32)(unsafe.Pointer(uintptr(v7 - 1)))
			for {
				v22.field_8 = float32(float64(v20)*float64(v13) + float64((*(*float2)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float2{})*7))).field_0))
				v22.field_C = float32(float64((*(*float2)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float2{})*7))).field_4) - float64(v21)*float64(v13))
				v22.field_8 = float32(nox_common_randomFloat_416030(-3.0, 3.0) + float64(v22.field_8))
				v22.field_C = float32(nox_common_randomFloat_416030(-3.0, 3.0) + float64(v22.field_C))
				if nox_xxx_mapTraceRay_535250(&v22, nil, nil, 1) != 0 {
					nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), (*nox_object_t)(unsafe.Pointer(v23)), (*float2)(unsafe.Pointer(&v22.field_8)))
					v8 = 1
					v16 = 1
					v17 = 1
				} else {
					v8 = v17
				}
				result = v18
				if (*uint32)(unsafe.Pointer(uintptr(v14))) != v18 {
					v9 = v15
					v14++
					switch v9 {
					case 0:
						v20 = func() int32 {
							p := &v2
							*p++
							return *p
						}()
					case 1:
						v6++
						v21 = v6
					case 2:
						v20 = func() int32 {
							p := &v2
							*p--
							return *p
						}()
					case 3:
						v6--
						v21 = v6
					default:
					}
				} else if v15 != 3 && v18 != nil {
					v9 = v15 + 1
					v14 = 1
					v15++
					switch v9 {
					case 0:
						v20 = func() int32 {
							p := &v2
							*p++
							return *p
						}()
					case 1:
						v6++
						v21 = v6
					case 2:
						v20 = func() int32 {
							p := &v2
							*p--
							return *p
						}()
					case 3:
						v6--
						v21 = v6
					default:
					}
				} else {
					if v16 == 0 {
						break
					}
					v7 += 2
					v18 = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v18))), 2))))
					v2 = 1 - v7/2
					v20 = 1 - v7/2
					v14 = 1
					v6 = v7 / (-2)
					v21 = v7 / (-2)
					v15 = 0
					v16 = 0
				}
				if v8 != 0 {
					break
				}
			}
		}
		if v8 == 0 {
			break
		}
		result = v19
		v23 = v19
		if v19 == nil {
			return result
		}
		result = v19
	}
	v10 = v23
	if v23 == nil {
		return result
	}
	for {
		v11 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*124)))))
		result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_unitDropCheckSome_4EDCD0(int32(uintptr(unsafe.Pointer(v1))), int32(uintptr(unsafe.Pointer(v10)))))))
		if result != nil {
			result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), (*nox_object_t)(unsafe.Pointer(v10)), (*float2)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float2{})*7))))))
		}
		if v11 == nil {
			break
		}
		v10 = v11
	}
	return result
}
func nox_xxx_unitDropCheckSome_4EDCD0(a1 int32, a2 int32) int32 {
	var v2 int32
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
	return bool2int32(v2&0x20 != 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6) == 0 || (uint32(v2)&0x10000000) == 0)
}
func sub_4EDDE0(a1 int32, a2 *uint32, a3 *int32) int32 {
	if nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))), (*float2)(unsafe.Pointer(a3))) == 0 {
		return 0
	}
	nox_xxx_aud_501960(833, (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a2)))))), 0, 0)
	if !nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) {
		nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(a2)), int32(gameFPS()*25))
	}
	return 1
}
func nox_xxx_dropFood_4EDE50(a1 int32, a2 int32, a3 *int32) int32 {
	var (
		v3 int32
		v4 *uint8
	)
	if a1 == 0 || a2 == 0 || a3 == nil {
		return 0
	}
	v3 = nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*float2)(unsafe.Pointer(a3)))
	if v3 != 0 {
		if !nox_common_gameFlags_check_40A5C0(2048) {
			nox_xxx_unitSetDecayTime_511660((*nox_object_t)(unsafe.Pointer(uintptr(a2))), int32(gameFPS()*25))
		}
		v4 = (*uint8)(memmap.PtrOff(0x587000, 205704))
		if int32(*memmap.PtrUint16(0x587000, 205710)) != 0 {
			for (*(*uint32)(unsafe.Pointer(uintptr(a2 + 12)))&*(*uint32)(unsafe.Pointer(v4))) == 0 && (int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*2))))&int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 24))))) == 0 {
				v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))
				if int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*3)))) == 0 {
					return v3
				}
			}
			nox_xxx_aud_501960(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v4))), unsafe.Sizeof(uint16(0))*3)))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
	return v3
}
func nox_xxx_chest_4EDF00(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  float64
		v4  float64
		v5  float64
		v6  float64
		v7  float64
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float32
		v13 float32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
		v18 float32
		v19 float32
		v20 float32
		v21 float32
		v22 float32
		v23 int32
		v24 *uint32
		v25 int32
		v26 int32
		v27 float32
		v28 float32
		v29 float32
		v30 float32
		v31 int32
		v32 int32
		a1a float2
		v34 float4
		a3  [3]float2
	)
	if a1 != 0 {
		if a2 != 0 {
			v31 = nox_xxx_inventoryCountObjects_4E7D30(a1, 0)
			if v31 != 0 {
				v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
				if v2&0x100 != 0 {
					a1a.field_0 = -1.0
					a1a.field_4 = -1.0
				} else if v2&0x200 != 0 {
					a1a.field_0 = 1.0
					a1a.field_4 = -1.0
				} else if v2&0x400 != 0 {
					a1a.field_0 = 1.0
					a1a.field_4 = 1.0
				} else if v2&0x800 != 0 {
					a1a.field_0 = -1.0
					a1a.field_4 = 1.0
				} else {
					a1a.field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 56))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
					a1a.field_4 = *(*float32)(unsafe.Pointer(uintptr(a2 + 60))) - *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
				}
				nox_xxx_utilNormalizeVector_509F20(&a1a)
				v3 = sub_4EE2A0(a1) + 4.0 + 15.0
				a3[0].field_0 = float32(v3*float64(a1a.field_0) + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))))
				a3[0].field_4 = float32(v3*float64(a1a.field_4) + float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))))
				v4 = float64(-a1a.field_4)
				v29 = float32(-v4)
				v30 = -a1a.field_0
				a3[1].field_0 = float32(v4*30.0 + float64(a3[0].field_0))
				a3[1].field_4 = float32(float64(a1a.field_0)*30.0 + float64(a3[0].field_4))
				a3[2].field_0 = float32(float64(v29)*30.0 + float64(a3[0].field_0))
				a3[2].field_4 = float32(float64(v30)*30.0 + float64(a3[0].field_4))
				v5 = float64(a3[0].field_0 - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
				v6 = float64(a3[0].field_4 - *(*float32)(unsafe.Pointer(uintptr(a2 + 60))))
				v27 = float32(v6*v6 + v5*v5)
				v7 = float64(a3[1].field_0 - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
				v8 = float64(a3[1].field_4 - *(*float32)(unsafe.Pointer(uintptr(a2 + 60))))
				v9 = v8*v8 + v7*v7
				v10 = float64(a3[2].field_0 - *(*float32)(unsafe.Pointer(uintptr(a2 + 56))))
				v11 = float64(a3[2].field_4 - *(*float32)(unsafe.Pointer(uintptr(a2 + 60))))
				v28 = float32(v11*v11 + v10*v10)
				if float64(v27) >= v9 {
					v13 = a3[1].field_4
					v12 = a3[1].field_0
				} else {
					v12 = a3[0].field_0
					v13 = a3[0].field_4
					a3[0].field_0 = a3[1].field_0
					a3[1].field_0 = v12
					a3[0].field_4 = a3[1].field_4
					v14 = v27
					v27 = float32(v9)
					a3[1].field_4 = v13
					v9 = float64(v14)
				}
				if v9 < float64(v28) {
					v15 = v12
					v12 = a3[2].field_0
					v16 = v13
					v13 = a3[2].field_4
					v9 = float64(v28)
					a3[1].field_0 = a3[2].field_0
					a3[1].field_4 = a3[2].field_4
					a3[2].field_0 = v15
					a3[2].field_4 = v16
				}
				if float64(v27) < v9 {
					v17 = a3[0].field_0
					v18 = a3[0].field_4
					a3[0].field_0 = v12
					a3[0].field_4 = v13
					a3[1].field_0 = v17
					a3[1].field_4 = v18
				}
				v19 = *(*float32)(unsafe.Pointer(uintptr(a1 + 56)))
				v34.field_4 = *(*float32)(unsafe.Pointer(uintptr(a1 + 60)))
				v34.field_0 = v19
				v34.field_8 = a3[2].field_0
				v34.field_C = a3[2].field_4
				if nox_xxx_mapTraceRay_535250(&v34, nil, nil, 1) == 0 {
					v20 = *(*float32)(unsafe.Pointer(uintptr(a2 + 60)))
					a3[2].field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 56)))
					a3[2].field_4 = v20
				}
				v34.field_8 = a3[1].field_0
				v34.field_C = a3[1].field_4
				if nox_xxx_mapTraceRay_535250(&v34, nil, nil, 1) == 0 {
					v21 = *(*float32)(unsafe.Pointer(uintptr(a2 + 60)))
					a3[1].field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 56)))
					a3[1].field_4 = v21
				}
				v34.field_8 = a3[0].field_0
				v34.field_C = a3[0].field_4
				if nox_xxx_mapTraceRay_535250(&v34, nil, nil, 1) == 0 {
					v22 = *(*float32)(unsafe.Pointer(uintptr(a2 + 60)))
					a3[0].field_0 = *(*float32)(unsafe.Pointer(uintptr(a2 + 56)))
					a3[0].field_4 = v22
				}
				if v31 == 1 {
					v23 = nox_xxx_inventoryGetFirst_4E7980(a1)
					v24 = (*uint32)(unsafe.Pointer(uintptr(v23)))
					if *(*byte)(unsafe.Pointer(uintptr(v23 + 488))) != math.MaxUint8 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v23 + 8))))&2) == 0 {
						*(*uint32)(unsafe.Pointer(uintptr(v23 + 16))) |= 0x40
						nox_xxx_unit_511810((*nox_object_t)(unsafe.Pointer(uintptr(v23))))
						nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(v24)), &a3[0])
					}
				} else {
					v25 = nox_xxx_inventoryGetFirst_4E7980(a1)
					v26 = 0
					if v25 != 0 {
						for {
							v32 = nox_xxx_inventoryGetNext_4E7990(v25)
							if *(*byte)(unsafe.Pointer(uintptr(v25 + 488))) != math.MaxUint8 && (int32(*(*uint8)(unsafe.Pointer(uintptr(v25 + 8))))&2) == 0 {
								*(*uint32)(unsafe.Pointer(uintptr(v25 + 16))) |= 0x40
								nox_xxx_unit_511810((*nox_object_t)(unsafe.Pointer(uintptr(v25))))
								nox_xxx_drop_4ED790((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(v25))), &a3[func() int32 {
									p := &v26
									x := *p
									*p++
									return x
								}()])
								if v26 >= 3 {
									v26 = 0
								}
							}
							v25 = v32
							if v32 == 0 {
								break
							}
						}
					}
				}
			}
		}
	}
}
func sub_4EE2A0(a1 int32) float64 {
	var v1 int32
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 172))))
	if v1 == 2 {
		return float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 176))))
	}
	if v1 != 3 {
		return 0.0
	}
	if float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) <= float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) {
		return float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 188)))) * 0.5
	}
	return float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 184)))) * 0.5
}
func nox_xxx_dropAnkhTradable_4EE370(a1 int32, a2 int32, a3 *int32) int32 {
	return nox_xxx_dropDefault_4ED290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*float2)(unsafe.Pointer(a3)))
}
func nox_xxx_unitAdjustHP_4EE460(unitp *nox_object_t, dv int32) {
	var unit int32 = int32(uintptr(unsafe.Pointer(unitp)))
	if nox_common_gameFlags_check_40A5C0(0x4000000) {
		return
	}
	var v2 *uint16 = *(**uint16)(unsafe.Pointer(uintptr(unit + 556)))
	if v2 == nil {
		return
	}
	var max uint16 = *(*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*2))
	if int32(*v2) < int32(max) {
		var (
			set int32  = int32(*v2) + dv
			val uint16 = uint16(int16(set))
		)
		if set > int32(max) {
			val = max
		}
		nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(unit))), val)
		if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&2 != 0 {
			nox_xxx_mobInformOwnerHP_4EE4C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
		}
	}
}
func nox_xxx_mobInformOwnerHP_4EE4C0(obj *nox_object_t) {
	var (
		a1 *uint32 = (*uint32)(unsafe.Pointer(obj))
		v1 int32
	)
	if a1 != nil {
		v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*math.MaxInt8)))
		if v1 != 0 {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 8))))&4 != 0 {
				nox_xxx_netReportUnitCurrentHP_4D8620(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 748))) + 276))) + 2064)))), a1)
			}
		}
	}
}
func nox_xxx_unitDamageClear_4EE5E0(unitp *nox_object_t, damageAmount int32) {
	var (
		unit           int32 = int32(uintptr(unsafe.Pointer(unitp)))
		healthData     int32
		v3             int32
		v4             int32
		deleteOverride func(int32)
	)
	if unit != 0 {
		healthData = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 556))))
		if healthData != 0 {
			if int32(*(*uint16)(unsafe.Pointer(uintptr(healthData + 4)))) != 0 && (!nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_GODMODE)) || (int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4) == 0) {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
					v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))))
					if v3 != 0 {
						if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2251)))) == 0 && *(*uint32)(unsafe.Pointer(uintptr(v3 + 132))) != 0 {
							nox_xxx_harpoonBreakForPlr_537520((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
						}
					}
				}
				if int32(**(**uint16)(unsafe.Pointer(uintptr(unit + 556)))) > damageAmount {
					nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(unit))), uint16(int16(int32(**(**uint16)(unsafe.Pointer(uintptr(unit + 556))))-damageAmount)))
				} else {
					nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(unit))), 0)
					v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 16))))
					if (v4 & 0x8000) == 0 {
						*(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v4))), 1)) |= 0x80
						*(*uint32)(unsafe.Pointer(uintptr(unit + 16))) = uint32(v4)
						nox_xxx_spellBuffOff_4FF5B0((*nox_object_t)(unsafe.Pointer(uintptr(unit))), 16)
						if nox_xxx_unitIsZombie_534A40(unit) == 0 {
							nox_xxx_soloMonsterKillReward_4EE500_obj_health(unit)
						}
						if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&2 != 0 {
							nox_xxx_monsterCallDieFn_50A3D0((*uint32)(unsafe.Pointer(uintptr(unit))))
						} else {
							deleteOverride = *(*func(int32))(unsafe.Pointer(uintptr(unit + 724)))
							if deleteOverride != nil {
								deleteOverride(unit)
							} else {
								nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
							}
						}
					}
				}
				if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&2 != 0 {
					nox_xxx_mobInformOwnerHP_4EE4C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
				}
			}
		}
	}
}
func nox_xxx_unitHPsetOnMax_4EE6F0(unit int32) {
	var v1 int32
	if unit != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 556))))
		if v1 != 0 {
			nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(unit))), *(*uint16)(unsafe.Pointer(uintptr(v1 + 4))))
			*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(unit + 556))) + 2))) = **(**uint16)(unsafe.Pointer(uintptr(unit + 556)))
			if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&2 != 0 {
				nox_xxx_mobInformOwnerHP_4EE4C0((*nox_object_t)(unsafe.Pointer(uintptr(unit))))
			}
		}
	}
}
func nox_xxx_playerHP_4EE730(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	if a1 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			if *(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) != 0 {
				v2 = v1 + 12
				v3 = 32
				for {
					v2 += 2
					v3--
					*(*uint16)(unsafe.Pointer(uintptr(v2 - 2))) = **(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
					if v3 == 0 {
						break
					}
				}
				*(*uint16)(unsafe.Pointer(uintptr(v1 + 76))) = **(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))
			}
		}
	}
}
func nox_xxx_unitGetHP_4EE780(item *nox_object_t) int16 {
	var (
		v1     *int16
		result int16
	)
	if item != nil && (func() *int16 {
		v1 = (*int16)(item.health_data)
		return v1
	}()) != nil {
		result = *v1
	} else {
		result = 0
	}
	return result
}
func nox_xxx_unitGetMaxHP_4EE7A0(a1 int32) int16 {
	var (
		v1     int32
		result int16
	)
	if a1 != 0 && (func() int32 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))))
		return v1
	}()) != 0 {
		result = int16(*(*uint16)(unsafe.Pointer(uintptr(v1 + 4))))
	} else {
		result = 0
	}
	return result
}
func nox_xxx_unitSetMaxHP_4EE7C0(a1 int32, a2 int16) int32 {
	var result int32
	result = a1
	if a1 != 0 {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))))
		if result != 0 {
			*(*uint16)(unsafe.Pointer(uintptr(result + 4))) = uint16(a2)
		}
	}
	return result
}
func nox_xxx_activatePoison_4EE7E0(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 float32
	)
	v3 = int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 540))))
	if a1 == 0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16))))&2 != 0 {
		return 0
	}
	if nox_xxx_testUnitBuffs_4FF350((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 23) != 0 {
		return 0
	}
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if v5&4 != 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 3680))))&1) == 1 {
		return 0
	}
	if v5&2 != 0 {
		v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
		if v6&0x200 != 0 {
			return 0
		}
	}
	v10 = float32(nox_xxx_getPoisonDmg_4E0040((*uint32)(unsafe.Pointer(uintptr(a1)))) * 100.0)
	v7 = nox_float2int(v10)
	if nox_common_randomInt_415FA0(0, 100) < v7 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), internCStr("Health.c:ResistPoison"), 0)
		return 0
	}
	v8 = v3 + a2
	if v3+a2 <= a3 {
		if v8 != v3 {
			nox_xxx_setSomePoisonData_4EEA90(a1, v8)
			nox_xxx_aud_501960(100, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
		goto LABEL_21
	}
	if v3 <= a3 {
		v8 = a3
		if v8 != v3 {
			nox_xxx_setSomePoisonData_4EEA90(a1, v8)
			nox_xxx_aud_501960(100, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
		goto LABEL_21
	}
	v8 = v3
LABEL_21:
	if v3 == 0 && v8 > 0 {
		v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))))
		if v9 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v9 + 16))) = gameFrame()
		}
	}
	return 1
}
func nox_xxx_updatePoison_4EE8F0(a1p *nox_object_t, a2 int32) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v2 int32
		v3 int32
		v4 *byte
		v5 int32
		v6 int32
	)
	if a1 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 540)))) > a2 {
			*(*uint8)(unsafe.Pointer(uintptr(a1 + 540))) -= uint8(int8(a2))
		} else {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))))
			*(*uint8)(unsafe.Pointer(uintptr(a1 + 540))) = 0
			if v2 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) = 0
			}
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
			if v3&4 != 0 {
				nox_xxx_playerUnsetStatus_417530((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276)))))), 1024)
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), internCStr("Health.c:PoisonFade"), 0)
			} else if v3&2 != 0 {
				if nox_common_gameFlags_check_40A5C0(2048) && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 {
					v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
					if v4 != nil {
						v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*514))))
						if v5 != 0 {
							nox_xxx_netReportObjectPoison_4D7F40(v5, (*uint32)(unsafe.Pointer(uintptr(a1))), 0)
						}
					}
				} else if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x80 != 0 {
					v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
					if v6 != 0 {
						nox_xxx_netReportObjectPoison_4D7F40(v6, (*uint32)(unsafe.Pointer(uintptr(a1))), 0)
					}
				}
			}
		}
	}
}
func nox_xxx_removePoison_4EE9D0(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 *byte
		v4 int32
		v5 int32
	)
	if a1 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 540)))) != 0 {
		v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))))
		*(*uint8)(unsafe.Pointer(uintptr(a1 + 540))) = 0
		if v1 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 16))) = 0
		}
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		if v2&4 != 0 {
			nox_xxx_playerUnsetStatus_417530((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276)))))), 1024)
		} else if v2&2 != 0 {
			if nox_common_gameFlags_check_40A5C0(2048) && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 {
				v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
				if v3 != nil {
					v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*514))))
					if v4 != 0 {
						nox_xxx_netReportObjectPoison_4D7F40(v4, (*uint32)(unsafe.Pointer(uintptr(a1))), 0)
					}
				}
			} else if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x80 != 0 {
				v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
				if v5 != 0 {
					nox_xxx_netReportObjectPoison_4D7F40(v5, (*uint32)(unsafe.Pointer(uintptr(a1))), 0)
				}
			}
		}
	}
}
func nox_xxx_setSomePoisonData_4EEA90(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 *byte
		v6 int32
	)
	if a1 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 540)))) == 0 && a2 > 0 {
			v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))))
			if v2 != 0 {
				*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) = gameFrame()
			}
		}
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
		*(*uint8)(unsafe.Pointer(uintptr(a1 + 540))) = uint8(int8(a2))
		if v3&4 != 0 {
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
			if a2 != 0 {
				nox_xxx_netNeedTimestampStatus_4174F0((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276)))))), 1024)
			} else {
				nox_xxx_playerUnsetStatus_417530((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276)))))), 1024)
			}
		} else if v3&2 != 0 {
			if nox_common_gameFlags_check_40A5C0(2048) && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))&0x10 != 0 {
				v5 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
				if v5 == nil {
					goto LABEL_19
				}
				v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*514))))
				if v6 == 0 {
					goto LABEL_19
				}
			} else {
				if int32(int8(*(*uint8)(unsafe.Pointer(uintptr(a1 + 12))))) >= 0 {
					goto LABEL_19
				}
				v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 508))))
				if v6 == 0 {
					goto LABEL_19
				}
			}
			nox_xxx_netReportObjectPoison_4D7F40(v6, (*uint32)(unsafe.Pointer(uintptr(a1))), int8(bool2int32(a2 != 0)))
		}
	LABEL_19:
		if a2 != 0 {
			*(*uint16)(unsafe.Pointer(uintptr(a1 + 542))) = 1000
		} else {
			*(*uint16)(unsafe.Pointer(uintptr(a1 + 542))) = 0
		}
	}
}
func nox_xxx_playerManaAdd_4EEB80(unitp *nox_object_t, amount int16) uint16 {
	var (
		unit        int32 = int32(uintptr(unsafe.Pointer(unitp)))
		result      uint16
		manaData    int32
		currentMana int16
		maxMana     uint16
		newAmount   uint16
	)
	result = uint16(int16(unit))
	if unit != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
		manaData = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))))
		currentMana = int16(*(*uint16)(unsafe.Pointer(uintptr(manaData + 4))))
		maxMana = *(*uint16)(unsafe.Pointer(uintptr(manaData + 8)))
		*(*uint16)(unsafe.Pointer(uintptr(manaData + 6))) = uint16(currentMana)
		newAmount = uint16(int16(int32(amount) + int32(currentMana)))
		*(*uint16)(unsafe.Pointer(uintptr(manaData + 4))) = newAmount
		if int32(newAmount) > int32(maxMana) {
			*(*uint16)(unsafe.Pointer(uintptr(manaData + 4))) = maxMana
		}
		nox_xxx_protectMana_56F9E0(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(manaData + 276))) + 4596)))), amount)
		result = *(*uint16)(unsafe.Pointer(uintptr(manaData + 8)))
		if int32(*(*uint16)(unsafe.Pointer(uintptr(manaData + 4)))) > int32(result) {
			result = uint16(uint32(uintptr(unsafe.Pointer(nox_xxx_protectPlayerHPMana_56F870(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(manaData + 276))) + 4596)))), result)))))
		}
	}
	return result
}
func nox_xxx_playerManaSub_4EEBF0(unit int32, amount int32) *uint32 {
	var (
		result      *uint32
		currentMana uint16
	)
	result = (*uint32)(unsafe.Pointer(uintptr(unit)))
	if unit != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
			result = *(**uint32)(unsafe.Pointer(uintptr(unit + 748)))
			if !nox_common_getEngineFlag(nox_engine_flag(NOX_ENGINE_FLAG_GODMODE)) {
				currentMana = *((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*2)))
				*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*3))) = currentMana
				if int32(currentMana) > amount {
					*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*2))) = uint16(int16(int32(currentMana) - amount))
				} else {
					*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*2))) = 0
				}
				if int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*2)))) > amount {
					result = nox_xxx_protectMana_56F9E0(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*69)) + 4596)))), int16(int32(-int16(amount))))
				} else {
					result = nox_xxx_protectMana_56F9E0(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*69)) + 4596)))), int16(-*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(result))), unsafe.Sizeof(uint16(0))*2)))))
				}
			}
		}
	}
	return result
}
func nox_xxx_unitGetOldMana_4EEC80(unit int32) int16 {
	var flags int32
	if unit == 0 {
		return 0
	}
	flags = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 8))))
	if flags&4 != 0 {
		return int16(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))) + 4))))
	}
	if flags&2 != 0 {
		return 1000
	} else {
		return 0
	}
}
func nox_xxx_playerGetMaxMana_4EECB0(unit int32) int16 {
	if unit != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
		return int16(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))) + 8))))
	} else {
		return 0
	}
}
func nox_xxx_playerSetMaxMana_4EECD0(unit int32, amount int16) int32 {
	var result int32
	result = unit
	if unit != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
			result = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))))
			*(*uint16)(unsafe.Pointer(uintptr(result + 8))) = uint16(amount)
		}
	}
	return result
}
func nox_xxx_playerManaRefresh_4EECF0(unit int32) *uint32 {
	var (
		result   *uint32
		manaData int32
		v3       int32
		v4       int16
	)
	result = (*uint32)(unsafe.Pointer(uintptr(unit)))
	if unit != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(unit + 8))))&4 != 0 {
			manaData = int32(*(*uint32)(unsafe.Pointer(uintptr(unit + 748))))
			v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(manaData + 276))))
			*(*uint16)(unsafe.Pointer(uintptr(manaData + 6))) = *(*uint16)(unsafe.Pointer(uintptr(manaData + 4)))
			v4 = int16(*(*uint16)(unsafe.Pointer(uintptr(manaData + 8))))
			*(*uint16)(unsafe.Pointer(uintptr(manaData + 4))) = uint16(v4)
			result = nox_xxx_protectMana_56F9E0(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4596)))), v4)
		}
	}
	return result
}
func nox_xxx_abilGivePlayerAll_4EED40(a1 int32, a2 int8, a3 int32) {
	var (
		v3 *int32
		v4 *uint32
		v5 int32
	)
	if a1 != 0 && int32(a2) > 0 {
		v3 = mem_getI32Ptr(0x587000, 206108)
		v4 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 3696)))
		v5 = int32(a2)
		for {
			if *v3 != 0 {
				if nox_common_gameFlags_check_40A5C0(4096) || nox_xxx_isQuest_4D6F50() != 0 || sub_4D6F70() != 0 {
					*v4 = 0
				} else {
					nox_xxx_abilityRewardServ_4FB9C0_ability(a1, *v3, a3)
				}
			}
			v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
			v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			v5--
			if v5 == 0 {
				break
			}
		}
	}
}
func nox_xxx_plrReadVals_4EEDC0(a1p *nox_object_t, a2 int32) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v2     int32
		v3     int32
		v4     int32
		v5     *float32
		v6     int16
		v7     int8
		v8     float64
		v9     int16
		v10    float64
		i      int32
		v12    int32
		v13    int32
		v14    uint32
		result int32
		v16    float32
		v17    float32
		v18    float32
		v19    float32
		v20    float32
		v21    int32
		v22    float32
		v23    int32
		v24    int8
		v25    *float32
		v26    *float32
	)
	v2 = a1
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v23 = 0
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))))
	v26 = sub_57B350()
	v5 = nox_xxx_plrGetMaxVarsPtr_57B360(int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2251)))))
	v25 = nox_xxx_plrGetMaxVarsPtr_57B360(0)
	if nox_common_gameFlags_check_40A5C0(0x2000) {
		*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 556))) + 4))) = uint16(int16(nox_float2int(*v5)))
		v6 = nox_float2int16_abs(*v5)
		nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(v2))), uint16(v6))
		*(*uint16)(unsafe.Pointer(uintptr(v3 + 8))) = uint16(int16(nox_float2int(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1)))))
		*(*uint16)(unsafe.Pointer(uintptr(v3 + 4))) = uint16(int16(nox_float2int(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1)))))
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 2239))) = uint32(nox_float2int(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*3))))
		v16 = *(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*2))
		*(*float32)(unsafe.Pointer(uintptr(v2 + 548))) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*2))) * 9.9999997e-05)
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 2235))) = uint32(nox_float2int(v16))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2251)))) == 0 && !nox_common_gameFlags_check_40A5C0(4096) && sub_4D6F30() == 0 {
			nox_xxx_abilGivePlayerAll_4EED40(v2, 10, 0)
		}
	} else {
		v7 = int8(*(*uint8)(unsafe.Pointer(uintptr(v4 + 3684))))
		if int32(v7) > NOX_PLAYER_MAX_LEVEL {
			v7 = NOX_PLAYER_MAX_LEVEL
		}
		v24 = v7
		v22 = float32(float64(int32(v7) - 1))
		v17 = float32(float64((*v5-*v26)*v22/(NOX_PLAYER_MAX_LEVEL-1)+*v26) + 0.5)
		*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 556))) + 4))) = uint16(int16(nox_float2int(v17)))
		nox_xxx_unitSetHP_4E4560((*nox_object_t)(unsafe.Pointer(uintptr(v2))), *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 556))) + 4))))
		v8 = float64((*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1))-*(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*1)))*v22/(NOX_PLAYER_MAX_LEVEL-1) + *(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*1)))
		if v8 > float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1))) {
			v8 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*1)))
		}
		v18 = float32(v8 + 0.5)
		v9 = int16(nox_float2int(v18))
		*(*uint16)(unsafe.Pointer(uintptr(v3 + 8))) = uint16(v9)
		*(*uint16)(unsafe.Pointer(uintptr(v3 + 4))) = uint16(v9)
		v19 = float32(float64((*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*3))-*(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*3)))*v22/(NOX_PLAYER_MAX_LEVEL-1)+*(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*3))) + 0.5)
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 2239))) = uint32(nox_float2int(v19))
		v10 = float64((*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*2))-*(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*2)))*v22/(NOX_PLAYER_MAX_LEVEL-1) + *(*float32)(unsafe.Add(unsafe.Pointer(v26), unsafe.Sizeof(float32(0))*2)))
		*(*float32)(unsafe.Pointer(uintptr(v2 + 548))) = float32(v10 * 9.9999997e-05)
		v20 = float32(v10 + 0.5)
		*(*uint32)(unsafe.Pointer(uintptr(v4 + 2235))) = uint32(nox_float2int(v20))
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 2251)))) == 0 {
			nox_xxx_abilGivePlayerAll_4EED40(v2, v24, a2)
		}
	}
	*(*float32)(unsafe.Pointer(uintptr(v2 + 120))) = float32(float64(*(*int32)(unsafe.Pointer(uintptr(v4 + 2239))))/float64(*(*float32)(unsafe.Add(unsafe.Pointer(v25), unsafe.Sizeof(float32(0))*3)))*20.0 + 10.0)
	*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 3652))) = uint16(int16(int64((float64(*(*int32)(unsafe.Pointer(uintptr(v4 + 2239))))/float64(*(*float32)(unsafe.Add(unsafe.Pointer(v25), unsafe.Sizeof(float32(0))*3)))*1250.0 + 750.0) * *mem_getDoublePtr(0x581450, 10216))))
	*(*uint16)(unsafe.Pointer(uintptr(v2 + 490))) = *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 3652)))
	sub_56F780(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 4624)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2239)))))
	sub_56F780(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 4620)))), int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 2235)))))
	nox_xxx_protectPlayerHPMana_56F870(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 4600)))), *(*uint16)(unsafe.Pointer(uintptr(v3 + 8))))
	nox_xxx_protectPlayerHPMana_56F870(int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 4592)))), *(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v2 + 556))) + 4))))
	for i = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 504)))); i != 0; v23 += v12 {
		v12 = int32(*(*uint8)(unsafe.Pointer(uintptr(i + 488))))
		i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 496))))
	}
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 3656))) = uint32(bool2int32(v23 > int32(*(*uint16)(unsafe.Pointer(uintptr(v2 + 490))))))
	v13 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))))
	v21 = int32(*(*uint32)(unsafe.Pointer(uintptr(v13 + 4628))))
	v14 = nox_wcslen((*wchar2_t)(unsafe.Pointer(uintptr(v13 + 2185))))
	result = sub_56FB00((*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276)))+2185))), v14*2, v21)
	*(*uint8)(unsafe.Pointer(uintptr(v4 + 2184))) = 1
	return result
}
func sub_4EF140(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		result int32
		i      int32
		v5     int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
	if nox_common_gameFlags_check_40A5C0(0x2000) {
		v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 4644))))
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 3684))) = NOX_PLAYER_MAX_LEVEL
		sub_56F820(v2, 0xA)
		result = nox_xxx_plrReadVals_4EEDC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0)
	} else {
		for i = 0; i <= NOX_PLAYER_MAX_LEVEL; i++ {
			if nox_xxx_gamedataGetFloatTable_419D70(internCStr("XPTable"), i) > float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 28)))) {
				break
			}
		}
		v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 4644))))
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 3684))) = uint8(int8(i - 1))
		sub_56F820(v5, uint8(int8(i-1)))
		result = nox_xxx_plrReadVals_4EEDC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0)
	}
	return result
}
func nox_xxx_calcBoltDamage_4EF1E0(a1 int32, a2 int32) float64 {
	var result float64
	if *memmap.PtrUint32(0x5D4594, 1568264) == 0 {
		*memmap.PtrUint32(0x5D4594, 1568264) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArcherBolt")))
	}
	if !nox_common_gameFlags_check_40A5C0(2048) || *(*uint32)(unsafe.Pointer(uintptr(a2 + 4))) != *memmap.PtrUint32(0x5D4594, 1568264) {
		result = float64(a1-int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 60)))))*float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 64)))) + float64(*(*uint16)(unsafe.Pointer(uintptr(a2 + 72))))
	} else {
		result = nox_xxx_gamedataGetFloat_419D40(internCStr("BoltSoloDamageMin")) + float64(a1-int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 60)))))*float64(*(*float32)(unsafe.Pointer(uintptr(a2 + 64))))
	}
	return result
}
func sub_4EF410(a1 int32, a2 uint8) {
	var (
		v2 int8
		v3 int32
		v4 int32
		v5 *uint32
		v6 int32
		v7 float32
	)
	v2 = int8(a2)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
	if int32(int8(a2)) > NOX_PLAYER_MAX_LEVEL {
		v2 = NOX_PLAYER_MAX_LEVEL
		a2 = NOX_PLAYER_MAX_LEVEL
	}
	*(*float32)(unsafe.Pointer(uintptr(a1 + 28))) = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("XPTable"), int32(v2)))
	v7 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("XPTable"), int32(v2)))
	sub_56F8C0(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4604)))), v7)
	sub_4D81A0(a1)
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4644))))
	*(*uint8)(unsafe.Pointer(uintptr(v3 + 3684))) = uint8(v2)
	sub_56F820(v6, a2)
	nox_xxx_plrReadVals_4EEDC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0)
	if nox_common_gameFlags_check_40A5C0(2048) && int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 2251)))) == 0 {
		v4 = 1
		v5 = (*uint32)(unsafe.Pointer(uintptr(v3 + 3700)))
		for {
			if *v5 != 0 {
				nox_xxx_book_45DBE0(unsafe.Pointer(uintptr(3)), v4, v4-1)
			}
			v4++
			v5 = (*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
			if v4 >= 6 {
				break
			}
		}
	}
	if nox_common_gameFlags_check_40A5C0(2048) {
		sub_57AF30(a1, 0)
	}
}
func nox_xxx_getRespawnWeaponFlags_4EF580() int8 {
	var (
		v0 int8
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
	)
	v0 = 0
	v1 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(0x400)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v1) != 0 {
		v0 = 1
	}
	v2 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(4)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v2) != 0 {
		v0 |= 2
	}
	v3 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(1)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v3) != 0 {
		v0 |= 4
	}
	v4 = sub_415840(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(0x8000)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v4) != 0 {
		v0 |= 8
	}
	v5 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(0x4000)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v5) != 0 {
		v0 |= 0x10
	}
	v6 = sub_415840(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(0x100)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v6) != 0 {
		v0 |= 0x20
	}
	v7 = sub_415840(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(0x200)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v7) != 0 {
		v0 |= 0x40
	}
	v8 = sub_415CD0(int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(0x1000000)))))))
	if nox_xxx_getUnitDefDd10_4E3BA0(v8) != 0 {
		v0 |= math.MinInt8
	}
	return v0
}
func sub_4EF6F0(a1 int32) int32 {
	var (
		v1 int32
		i  int32
	)
	if *memmap.PtrUint32(0x5D4594, 1568268) == 0 {
		*memmap.PtrUint32(0x5D4594, 1568268) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	v1 = 0
	for i = nox_xxx_inventoryGetFirst_4E7980(a1); i != 0; i = nox_xxx_inventoryGetNext_4E7990(i) {
		if uint32(*(*uint16)(unsafe.Pointer(uintptr(i + 4)))) == *memmap.PtrUint32(0x5D4594, 1568268) {
			v1++
		}
	}
	return v1
}
func nox_xxx_playerRespawnItem_4EF750(a1p *nox_object_t, a2 *byte, a3 *int32, a4 int32, a5 int32) *nox_object_t {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v5 *uint32
		v6 *uint32
		v7 func(*uint32, uint32)
		v8 int32
	)
	v5 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(a2)))
	v6 = v5
	if v5 != nil {
		v7 = asFunc(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*172)), (*func(*uint32, uint32))(nil)).(func(*uint32, uint32))
		if v7 != nil {
			v7(v6, 0)
		}
		if a3 != nil {
			nox_xxx_modifSetItemAttrs_4E4990((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), a3)
		}
		nox_xxx_inventoryServPlace_4F36F0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v6)))))), a4, a5)
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*4)) &= 0xFFF7FFFF
		if uint32(v8)&0x3001000 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*187)) + 4))) |= 1
		}
	}
	return (*nox_object_t)(unsafe.Pointer(v6))
}
func nox_xxx_playerMakeDefItems_4EF7D0(a1 int32, a2 int32, a3 int32) int8 {
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  *uint32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v18 [20]uint8
		v19 *uint8
		v20 *uint32
	)
	v3 = a1
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v19 = (*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2185)))
	if a2 != 0 {
		nox_xxx_removePoison_4EE9D0(v3)
		nox_xxx_unitHPsetOnMax_4EE6F0(v3)
		nox_xxx_playerManaRefresh_4EECF0(v3)
	}
	nox_xxx_playerCancelAbils_4FC180((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
	sub_4D7E50((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 312))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 316))) = 0
	*(*uint8)(unsafe.Pointer(uintptr(v3 + 541))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 84))) = 0
	*(*uint16)(unsafe.Pointer(uintptr(v4 + 78))) = 0
	*(*uint16)(unsafe.Pointer(uintptr(v4 + 76))) = 0
	v5 = v4 + 12
	v6 = 32
	for {
		v5 += 2
		v6--
		*(*uint16)(unsafe.Pointer(uintptr(v5 - 2))) = **(**uint16)(unsafe.Pointer(uintptr(v3 + 556)))
		if v6 == 0 {
			break
		}
	}
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))) &= 0xFFEB3FE7
	nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(v3))), 13)
	nox_xxx_unitClearBuffs_4FF580((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
	*(*uint8)(unsafe.Pointer(uintptr(v4 + 188))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 216))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 192))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 196))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 200))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 204))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 208))) = 0
	*(*uint8)(unsafe.Pointer(uintptr(v4 + 212))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 136))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 132))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v4 + 268))) = 0
	sub_4F7950(v3)
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 520))) = 0
	if nox_common_gameFlags_check_40A5C0(0x2000) {
		sub_4DE4D0(int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2064)))))
	}
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
	if v7 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v7 + 4700))) == 0 {
		nox_xxx_netReportTotalHealth_4D85C0(int32(*(*uint8)(unsafe.Pointer(uintptr(v7 + 2064)))), (*uint32)(unsafe.Pointer(uintptr(v3))))
		nox_xxx_netReportTotalMana_4D88C0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2064)))), v3)
		if a3 != 0 {
			*((*uint8)(unsafe.Pointer(&v7))) = uint8(int8(nox_xxx_netSendPlayerRespawn_4EFC30(v3, 0)))
		} else {
			v8 = *(**uint32)(unsafe.Pointer(uintptr(v3 + 504)))
			if v8 != nil {
				for {
					v20 = (*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*124)))))
					if sub_53E2D0(int32(uintptr(unsafe.Pointer(v8)))) != 0 || (func() bool {
						v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*4)))
						return (v9 & 0x100) == 0
					}()) || *(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*2))&0x2000000 != 0 && nox_xxx_unitArmorInventoryEquipFlags_415C70((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))))&0x808 != 0 {
						nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v8)))))))
					}
					v8 = v20
					if v20 == nil {
						break
					}
				}
			}
			nox_xxx_netSendPlayerRespawn_4EFC30(v3, 1)
			v10 = nox_xxx_modifGetIdByName_413290(internCStr("UserColor1"))
			v11 = int32(uintptr(nox_xxx_modifGetDescById_413330(v10)))
			if nox_common_gameFlags_check_40A5C0(2560) || int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251)))) != 0 {
				v12 = int32(**(**uint32)(unsafe.Pointer(uintptr(v4 + 276))))
				if (v12 & 0x400) == 0 {
					*(*uint32)(unsafe.Pointer(&v18[0])) = 0
					*(*uint32)(unsafe.Pointer(&v18[4])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 4))) + uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 84)))))))
					*(*uint32)(unsafe.Pointer(&v18[8])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 4))) + uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 85)))))))
					*(*uint32)(unsafe.Pointer(&v18[12])) = 0
					nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("StreetShirt"), (*int32)(unsafe.Pointer(&v18[0])), 1, 0)
				}
			}
			if (int32(**(**uint8)(unsafe.Pointer(uintptr(v4 + 276)))) & 4) == 0 {
				*(*uint32)(unsafe.Pointer(&v18[0])) = 0
				*(*uint32)(unsafe.Pointer(&v18[4])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 4))) + uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 83)))))))
				*(*uint32)(unsafe.Pointer(&v18[8])) = 0
				*(*uint32)(unsafe.Pointer(&v18[12])) = 0
				nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("StreetPants"), (*int32)(unsafe.Pointer(&v18[0])), 1, 0)
			}
			if (int32(**(**uint8)(unsafe.Pointer(uintptr(v4 + 276)))) & 1) == 0 {
				*(*uint32)(unsafe.Pointer(&v18[0])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 4))) + uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 87)))))))
				*(*uint32)(unsafe.Pointer(&v18[4])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(int32(*(*uint32)(unsafe.Pointer(uintptr(v11 + 4))) + uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 86)))))))
				*(*uint32)(unsafe.Pointer(&v18[8])) = 0
				*(*uint32)(unsafe.Pointer(&v18[12])) = 0
				nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("StreetSneakers"), (*int32)(unsafe.Pointer(&v18[0])), 1, 0)
			}
			if nox_common_gameFlags_check_40A5C0(2048) {
				v13 = nox_xxx_modifGetIdByName_413290(internCStr("ArmorQuality1"))
				*(*uint32)(unsafe.Pointer(&v18[0])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v13)))
				*(*uint32)(unsafe.Pointer(&v18[8])) = 0
				*(*uint32)(unsafe.Pointer(&v18[12])) = 0
				if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251)))) != 0 {
					*(*uint32)(unsafe.Pointer(&v18[4])) = 0
				} else {
					v14 = nox_xxx_modifGetIdByName_413290(internCStr("Material1"))
					*(*uint32)(unsafe.Pointer(&v18[4])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v14)))
				}
				*((*uint8)(unsafe.Pointer(&v7))) = uint8(uint32(uintptr(unsafe.Pointer(nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), *(**byte)(memmap.PtrOff(0x587000, uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251))))*4)+206376)), (*int32)(unsafe.Pointer(&v18[0])), 1, 0)))))
			} else if nox_common_gameFlags_check_40A5C0(4096) && sub_4CFE00() >= 0 {
				*(*uint32)(unsafe.Pointer(&v18[0])) = 0
				*(*uint32)(unsafe.Pointer(&v18[4])) = 0
				*(*uint32)(unsafe.Pointer(&v18[8])) = 0
				*(*uint32)(unsafe.Pointer(&v18[12])) = 0
				if int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251)))) == 1 {
					v15 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment1"))
					*(*uint32)(unsafe.Pointer(&v18[8])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v15)))
				}
				*((*uint8)(unsafe.Pointer(&v7))) = uint8(uint32(uintptr(unsafe.Pointer(nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), *(**byte)(memmap.PtrOff(0x587000, uintptr(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251))))*4)+206388)), (*int32)(unsafe.Pointer(&v18[0])), 1, 0)))))
			} else {
				*((*uint8)(unsafe.Pointer(&v7))) = *(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))) + 2251)))
				if int32(uint8(int8(v7))) != 0 {
					if int32(uint8(int8(v7))) == 1 {
						*((*uint8)(unsafe.Pointer(&v7))) = uint8(uint32(uintptr(unsafe.Pointer(nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("WizardRobe"), nil, 1, 0)))))
					}
				} else {
					nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("Longsword"), nil, 1, 0)
					*((*uint8)(unsafe.Pointer(&v7))) = uint8(uint32(uintptr(unsafe.Pointer(nox_xxx_playerRespawnItem_4EF750((*nox_object_t)(unsafe.Pointer(uintptr(v3))), internCStr("WoodenShield"), nil, 1, 0)))))
				}
			}
		}
		v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 276))))
		if v16 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v16 + 4700))) = 1
		}
	}
	return int8(v7)
}
func nox_xxx_netSendPlayerRespawn_4EFC30(a1 int32, a2 int8) int32 {
	var v3 [9]byte
	v3[0] = 233
	*(*uint32)(unsafe.Pointer(&v3[3])) = gameFrame()
	*(*uint16)(unsafe.Pointer(&v3[1])) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 36)))
	v3[7] = byte(nox_xxx_getRespawnWeaponFlags_4EF580())
	v3[8] = byte(a2)
	return nox_xxx_netSendPacket1_4E5390(math.MaxUint8, int32(uintptr(unsafe.Pointer(&v3[0]))), 9, 0, 0)
}
func nox_xxx_unitInitPlayer_4EFE80(a1p *nox_object_t) int8 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 int32
		v2 int32
		v4 float32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v2 = nox_object_getGold_4FA6D0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_playerSubGold_4FA5D0(a1, uint32(v2))
	sub_4EF140(a1)
	nox_xxx_spellAwardAll1_4EFD80((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
	nox_xxx_spellAwardAll2_4EFC80((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
	nox_xxx_plrReadVals_4EEDC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0)
	nox_xxx_spellAwardAll3_4EFE10((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
	if nox_common_gameFlags_check_40A5C0(4096) {
		v4 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestGameStartingExtraLives")))
		*(*uint32)(unsafe.Pointer(uintptr(v1 + 320))) = uint32(nox_float2int(v4))
	}
	return nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 0)
}
func sub_4EFF10(a1 int32) int32 {
	var (
		v1     int32
		v2     uint16
		v3     int32
		v4     uint32
		result int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	nox_xxx_spellAwardAll1_4EFD80((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
	nox_xxx_spellAwardAll2_4EFC80((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
	*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 3684))) = 1
	nox_xxx_playerCancelAbils_4FC180((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_plrReadVals_4EEDC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0)
	nox_xxx_spellAwardAll3_4EFE10((*nox_playerInfo)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276)))))))
	v2 = *(*uint16)(unsafe.Pointer(uintptr(v1 + 8)))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))))
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 4))) = v2
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 6))) = v2
	nox_xxx_protectPlayerHPMana_56F870(int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 4596)))), v2)
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 192))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 196))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 200))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 204))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 208))) = 0
	*(*uint8)(unsafe.Pointer(uintptr(v1 + 212))) = 0
	nox_xxx_unitHPsetOnMax_4EE6F0(a1)
	v4 = *(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) & 0xFFEB3FE7
	*(*uint8)(unsafe.Pointer(uintptr(a1 + 541))) = 0
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))) = v4
	nox_xxx_playerSetState_4FA020((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 13)
	nox_xxx_unitClearBuffs_4FF580((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_playerCancelSpells_4FEAE0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_removePoison_4EE9D0(a1)
	sub_4F7950(a1)
	nox_xxx_netReportTotalHealth_4D85C0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2064)))), (*uint32)(unsafe.Pointer(uintptr(a1))))
	nox_xxx_netReportTotalMana_4D88C0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 2064)))), a1)
	*(*uint32)(unsafe.Pointer(uintptr(a1 + 520))) = 0
	result = -559023410
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 3664))) = 3735943886
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v1 + 276))) + 3660))) = 3735943886
	return result
}
func nox_xxx_unitSparkInit_4F0390(a1 int32) *uint32 {
	var result *uint32
	result = *(**uint32)(unsafe.Pointer(uintptr(a1 + 748)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*1)) = 32
	*result = 32
	return result
}
func nox_xxx_initFrog_4F03B0(a1 int32) int32 {
	var v1 *uint8
	_ = v1
	var result int32
	v1 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 748)))
	*v1 = uint8(int8(nox_common_randomInt_415FA0(55, 60)))
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 1)) = 1
	*(*uint8)(unsafe.Add(unsafe.Pointer(v1), 2)) = 0
	result = nox_common_randomInt_415FA0(0, math.MaxUint8)
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(int16(result))
	return result
}
func nox_xxx_initChest_4F0400(a1 int32) *int32 {
	var result *int32
	result = (*int32)(unsafe.Pointer(uintptr(a1)))
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 20)))) & 0xE) == 0 {
		result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(2))))))))))
	}
	return result
}
func nox_xxx_unitBoulderInit_4F0420(a1 *uint32) *uint32 {
	var (
		result *uint32
		v2     int32
	)
	result = a1
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*15)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*39)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*14))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*40)) = uint32(v2)
	return result
}
func sub_4F0450(a1 int32) int32 {
	var (
		v1     int32
		v2     int16
		result int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v2 = int16(nox_xxx_xferDirectionToAngle_509E00(*(**uint32)(unsafe.Pointer(uintptr(a1 + 692)))))
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(v2)
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(v2)
	result = nox_xxx_getNameId_4E3AA0((*byte)(unsafe.Pointer(uintptr(v1 + 16))))
	*(*uint32)(unsafe.Pointer(uintptr(v1 + 12))) = uint32(result)
	return result
}
func sub_4F0490(a1 int32) int32 {
	var result int32
	result = nox_xxx_xferDirectionToAngle_509E00(*(**uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = uint16(int16(result))
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(int16(result))
	return result
}
func nox_xxx_unitInitGold_4F04B0(a1 int32) int32 {
	var (
		result int32
		v2     *uint32
		v3     *byte
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     float32
		v9     float32
	)
	result = a1
	v2 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 692)))
	if *v2 == 0 {
		v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		v4 = 0
		v7 = 0
		v8 = 0.0
		if v3 != nil {
			for {
				v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*514))))
				if v5 != 0 {
					v8 = v8 + *(*float32)(unsafe.Pointer(uintptr(v5 + 28)))
				}
				v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*nox_playerInfo)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))))
				v4++
				if v3 == nil {
					break
				}
			}
			v7 = v4
		}
		v9 = float32(float64(v8) / float64(v7))
		v6 = int32(uint32(uint64(nox_common_randomInt_415FA0(int32(int64(float64(v9)**(*float64)(unsafe.Pointer(&qword_581450_10256)))), int32(int64(float64(v9)**mem_getDoublePtr(0x581450, 10264))))) - uint64(int64(float64(v9)**mem_getDoublePtr(0x581450, 10248)))))
		result = nox_common_randomInt_415FA0(15, 30)
		*v2 = uint32(result + v6)
	}
	return result
}
func nox_xxx_breakInit_4F0570(a1 int32) *int32 {
	var result *int32
	result = (*int32)(unsafe.Pointer(uintptr(a1)))
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 20)))) & 0xE) == 0 {
		result = (*int32)(unsafe.Pointer(uintptr(nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(2))))))))))
	}
	return result
}
func nox_xxx_unitInitGenerator_4F0590(a1 int32) int32 {
	var (
		v1     int32
		v2     float64
		result int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	switch *(*uint8)(unsafe.Pointer(uintptr(nox_xxx_getQuestStage_51A930() + v1 + 83))) {
	case 0:
		v2 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesHigh"))
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 87))) = uint8(int8(int64(v2)))
	case 1:
		v2 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesNormal"))
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 87))) = uint8(int8(int64(v2)))
	case 2:
		v2 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesLow"))
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 87))) = uint8(int8(int64(v2)))
	case 3:
		v2 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesSingular"))
		*(*uint8)(unsafe.Pointer(uintptr(v1 + 87))) = uint8(int8(int64(v2)))
	default:
	}
	result = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
	if result&1 != 0 {
		result = nox_xxx_mathDirection4ToAngle_509E90(0)
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(int16(result))
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 124)))
		return result
	}
	if result&2 != 0 {
		result = nox_xxx_mathDirection4ToAngle_509E90(2)
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(int16(result))
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 124)))
		return result
	}
	if result&4 != 0 {
		result = nox_xxx_mathDirection4ToAngle_509E90(8)
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(int16(result))
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 124)))
		return result
	}
	if result&8 != 0 {
		result = nox_xxx_mathDirection4ToAngle_509E90(6)
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 124))) = uint16(int16(result))
		*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 124)))
		return result
	}
	*(*uint16)(unsafe.Pointer(uintptr(a1 + 126))) = *(*uint16)(unsafe.Pointer(uintptr(a1 + 124)))
	return result
}
func nox_server_rewardgen_activateMarker_4F0720(a1 int32, a2 uint32) *uint32 {
	var (
		v2     int32
		v3     int32
		v4     *int32
		result *uint32
		v6     int32
		v7     int8
		v8     *uint8
		v9     uint32
		v10    int32
		v11    uint32
		v12    int8
		v13    *uint8
		v14    uint32
	)
	v2 = int32(*memmap.PtrUint32(0x5D4594, 1568276))
	v3 = a1
	v4 = *(**int32)(unsafe.Pointer(uintptr(a1 + 692)))
	if *memmap.PtrUint32(0x5D4594, 1568276) == 0 {
		v2 = nox_xxx_getNameId_4E3AA0(internCStr("RewardMarkerPlus"))
		*memmap.PtrUint32(0x5D4594, 1568276) = uint32(v2)
	}
	if int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) == v2 {
		a2 += 2
	}
	switch *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*53)) {
	case 1:
		if nox_common_randomInt_415FA0(0, 100) > 75 {
			return nil
		}
	case 2:
		if nox_common_randomInt_415FA0(0, 100) > 50 {
			return nil
		}
	case 3:
		if nox_common_randomInt_415FA0(0, 100) > 25 {
			return nil
		}
	case 4:
		if nox_common_randomInt_415FA0(0, 100) > 5 {
			return nil
		}
	default:
	}
	v6 = 0
	v7 = 0
	v8 = (*uint8)(memmap.PtrOff(0x587000, 207044))
	for {
		if (1<<int32(v7))&*v4 != 0 {
			v6 += int32(*v8)
		}
		v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 8))
		v7++
		if int32(uintptr(unsafe.Pointer(v8))) >= int32(uintptr(memmap.PtrOff(0x587000, 207108))) {
			break
		}
	}
	if v6 == 0 {
		return nil
	}
	v9 = uint32(nox_common_randomInt_415FA0(1, v6))
	v10 = *v4
	v11 = 0
	v12 = 0
	v13 = (*uint8)(memmap.PtrOff(0x587000, 207044))
	for {
		v14 = uint32(1 << int32(v12))
		if v10&(1<<int32(v12)) != 0 {
			v11 += uint32(*v13)
			v3 = a1
			if v11 >= v9 {
				break
			}
		}
		v13 = (*uint8)(unsafe.Add(unsafe.Pointer(v13), 8))
		v12++
		if int32(uintptr(unsafe.Pointer(v13))) >= int32(uintptr(memmap.PtrOff(0x587000, 207108))) {
			v14 = a2
			break
		}
	}
	switch v14 {
	case 1:
		result = nox_xxx_rewardSpellBook_4F09F0(v3, a2)
	case 2:
		result = nox_xxx_rewardAbilityBook_4F0C70(v3)
	case 4:
		result = nox_xxx_rewardFieldGuide_4F0D20(v3, a2)
	case 8:
		result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_rewardMakeWeapon_4F14E0(v3, a2))))
	case 0x10:
		result = nox_xxx_rewardMakeArmor_4F0E80(v3, a2)
	case 0x20:
		result = nox_xxx_createGem_4F1D30(v3, a2)
	case 0x40:
		result = nox_xxx_rewardMakePotion_4F1C40(v3, a2)
	case 0x80:
		result = nox_xxx_createGem2_4F1F00(v3, a2)
	default:
		result = nox_xxx_createGem_4F1D30(v3, a2)
	}
	return result
}
func nox_xxx_rewardSpellBook_4F09F0(a1 int32, a2 uint32) *uint32 {
	var (
		v2     int32
		v3     int32
		i      int32
		v5     int32
		v6     int32
		v7     int32
		result *uint32
		v9     int32
		v10    int32
		v11    int32
		v12    *uint8
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		j      *uint8
		v18    int32
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 4))))&1 != 0 {
		v3 = 0
		for i = 0; i < 137; i++ {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + i + 8)))) == 1 {
				v3++
			}
		}
		if v3 != 0 {
			v5 = nox_common_randomInt_415FA0(0, v3-1)
			v6 = 0
			v7 = 0
			for {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + v7 + 8)))) == 1 {
					if v6 == v5 {
						v9 = v7
						goto LABEL_27
					}
					v6++
				}
				if func() int32 {
					p := &v7
					*p++
					return *p
				}() >= 137 {
					return nil
				}
			}
		}
		return nil
	}
	v10 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2)
	v11 = 0
	if *memmap.PtrUint32(0x587000, 207108) == 0 {
		return nil
	}
	v12 = (*uint8)(memmap.PtrOff(0x587000, 207104))
	for {
		if uint32(v10)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*2))) != 0 {
			v11 += int32(*v12)
		}
		v13 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*4))))
		v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v12), 12))
		if v13 == 0 {
			break
		}
	}
	if v11 == 0 {
		return nil
	}
	v14 = nox_common_randomInt_415FA0(0, v11-1)
	v15 = 0
	v16 = 0
	if *memmap.PtrUint32(0x587000, 207108) == 0 {
		return nil
	}
	for j = (*uint8)(memmap.PtrOff(0x587000, 207104)); ; j = (*uint8)(unsafe.Add(unsafe.Pointer(j), 12)) {
		if uint32(v10)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*2))) != 0 {
			v15 += int32(*j)
			if v14 < v15 {
				break
			}
		}
		v18 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*4))))
		v16++
		if v18 == 0 {
			return nil
		}
	}
	v9 = int32(*memmap.PtrUint32(0x587000, uintptr(v16*12)+207108))
LABEL_27:
	if v9 == 0 {
		return nil
	}
	if nox_xxx_playerCheckSpellClass_57AEA0(1, v9) != 0 || nox_xxx_playerCheckSpellClass_57AEA0(2, v9) != 0 {
		if nox_xxx_playerCheckSpellClass_57AEA0(1, v9) != 0 {
			if nox_xxx_playerCheckSpellClass_57AEA0(2, v9) != 0 {
				return nil
			}
			result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("ConjurerSpellBook"))))
		} else {
			result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("WizardSpellBook"))))
		}
	} else {
		result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("CommonSpellBook"))))
	}
	if result == nil {
		return nil
	}
	*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*184))))) = uint8(int8(v9))
	return result
}
func nox_server_rewardGen_pickRandomSlots_4F0B60(a1 uint32) int32 {
	var (
		v2 uint32
		v3 *float32
		v4 int32
		v5 int32
		v6 *float32
		v7 float64
		v8 int32
	)
	_ = v8
	var v9 [5]float32
	var v10 float32
	v9[0] = 0.0
	v9[1] = 0.0
	v9[2] = 0.0
	v9[3] = 0.0
	v9[4] = 0.0
	if a1 > 0xA {
		return 16
	}
	switch a1 {
	case 0:
		return 1
	case 1:
		v9[0] = 87.5
		v9[1] = 12.5
		goto LABEL_12
	case 9:
		v9[3] = 12.5
		v9[4] = 87.5
		goto LABEL_12
	case 0xA:
		return 16
	}
	if a1&1 != 0 {
		v2 = a1 >> 1
		v9[v2] = 75.0
		*(*int32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(&v9[0]))), v2*4)))) = 1095237632
		v9[v2+1] = 12.5
	} else {
		v3 = &v9[a1>>1]
		*((*float32)(unsafe.Add(unsafe.Pointer(v3), -int(unsafe.Sizeof(float32(0))*1)))) = 50.0
		*v3 = 50.0
	}
LABEL_12:
	v8 = 545
	v4 = nox_common_randomInt_415FA0(0, 200)
	v5 = 0
	v6 = &v9[0]
	v7 = 0.0
	for {
		v7 = v7 + float64(*v6)
		v10 = float32(float64(v4) * 0.5)
		if float64(v10) <= v7 {
			break
		}
		v5++
		v6 = (*float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(float32(0))*1))
		if v5 >= 5 {
			return 1
		}
	}
	return 1 << v5
}
func nox_xxx_rewardAbilityBook_4F0C70(a1 int32) *uint32 {
	var (
		v1     int32
		v2     int32
		i      int32
		result *uint32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + 4)))) & 2) == 0 {
		v8 = nox_common_randomInt_415FA0(1, 5)
		goto LABEL_16
	}
	v2 = 0
	for i = 0; i < 6; i++ {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + i + 145)))) == 1 {
			v2++
		}
	}
	if v2 == 0 {
		return nil
	}
	v5 = nox_common_randomInt_415FA0(0, v2-1)
	v6 = 0
	v7 = 0
	for {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v1 + v7 + 145)))) == 1 {
			if v6 != v5 {
				v6++
				goto LABEL_12
			}
			v8 = v7
			break
		}
	LABEL_12:
		if func() int32 {
			p := &v7
			*p++
			return *p
		}() >= 6 {
			return nil
		}
	}
LABEL_16:
	if v8 == 0 {
		return nil
	}
	result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("AbilityBook"))))
	if result != nil {
		*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*184))))) = uint8(int8(v8))
	}
	return result
}
func nox_xxx_rewardFieldGuide_4F0D20(a1 int32, a2 uint32) *uint32 {
	var (
		v2     int32
		v3     int32
		i      int32
		result *uint32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    *uint8
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		j      *uint8
		v18    int32
		v19    *uint32
		v20    *byte
		v21    *byte
	)
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 4))))&4 != 0 {
		v3 = 0
		for i = 0; i < 41; i++ {
			if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + i + 151)))) == 1 {
				v3++
			}
		}
		if v3 != 0 {
			v6 = nox_common_randomInt_415FA0(0, v3-1)
			v7 = 0
			v8 = 0
			for {
				if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + v8 + 151)))) == 1 {
					if v7 == v6 {
						v9 = v8
						goto LABEL_29
					}
					v7++
				}
				if func() int32 {
					p := &v8
					*p++
					return *p
				}() >= 41 {
					return nil
				}
			}
		}
		return nil
	}
	v10 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2)
	v11 = 0
	if *memmap.PtrUint32(0x587000, 207796) == 0 {
		return nil
	}
	v12 = (*uint8)(memmap.PtrOff(0x587000, 207792))
	for {
		if uint32(v10)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*2))) != 0 {
			v11 += int32(*v12)
		}
		v13 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v12))), 4*4))))
		v12 = (*uint8)(unsafe.Add(unsafe.Pointer(v12), 12))
		if v13 == 0 {
			break
		}
	}
	if v11 == 0 {
		return nil
	}
	v14 = nox_common_randomInt_415FA0(0, v11-1)
	v15 = 0
	v16 = 0
	if *memmap.PtrUint32(0x587000, 207796) == 0 {
		return nil
	}
	for j = (*uint8)(memmap.PtrOff(0x587000, 207792)); ; j = (*uint8)(unsafe.Add(unsafe.Pointer(j), 12)) {
		if uint32(v10)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*2))) != 0 {
			v15 += int32(*j)
			if v14 < v15 {
				break
			}
		}
		v18 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*4))))
		v16++
		if v18 == 0 {
			return nil
		}
	}
	v9 = int32(*memmap.PtrUint32(0x587000, uintptr(v16*12)+207796))
LABEL_29:
	if v9 == 0 {
		return nil
	}
	result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("FieldGuide"))))
	v19 = result
	if result != nil {
		v20 = (*byte)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*184)))))
		v21 = nox_xxx_guideNameByN_427230(v9)
		result = v19
		libc.StrCpy(v20, v21)
	}
	return result
}
func nox_xxx_rewardMakeArmor_4F0E80(a1 int32, a2 uint32) *uint32 {
	var (
		v2  int32
		v3  int32
		v4  *uint8
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		i   *uint8
		v11 int32
		v12 int32
		v13 int32
		v14 *uint32
		v15 int32
		v16 int32
		v17 int16
		v18 int32
		v19 int32
		v20 *uint8
		v21 int32
		v22 int32
		v23 *uint8
		v24 int32
		v25 int32
		v26 *uint8
		v27 int32
		v28 int32
		v29 *uint8
		v30 int32
		v31 int32
		v32 int32
		v33 int32
		v34 *uint8
		v35 int32
		v36 int32
		v37 *uint8
		v38 int32
		v39 int32
		v40 int32
		v41 int32
		v42 *uint8
		v43 int32
		v44 int32
		v45 *uint8
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v50 *uint8
		v51 int32
		v52 int32
		v53 int32
		v54 int32
		v55 int32
		v56 int32
		v57 *uint8
		v58 int32
		v59 int32
		v60 int32
		v61 int32
		v62 *uint8
		v63 int32
		v64 int32
		v65 int32
		v66 int32
		v67 [20]uint8
	)
	v65 = 0
	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2)
	v3 = 0
	v64 = v2
	if *memmap.PtrUint32(0x587000, 208180) == 0 {
		return nil
	}
	v4 = (*uint8)(memmap.PtrOff(0x587000, 208192))
	for {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), -4))))&2 != 0 && uint32(v2)&*(*uint32)(unsafe.Pointer(v4)) != 0 && nox_xxx_getUnitDefDd10_4E3BA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), -int(4*2)))))) != 0 {
			v3 += int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), -16))))
		}
		v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*2))))
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 20))
		if v5 == 0 {
			break
		}
	}
	if v3 == 0 {
		return nil
	}
	v7 = nox_common_randomInt_415FA0(0, v3-1)
	v8 = 0
	v9 = 0
	if *memmap.PtrUint32(0x587000, 208180) == 0 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 208192)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 20)) {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(i), -4))))&2 != 0 {
			if uint32(v64)&*(*uint32)(unsafe.Pointer(i)) != 0 {
				if nox_xxx_getUnitDefDd10_4E3BA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), -int(4*2)))))) != 0 {
					v8 += int32(*((*uint8)(unsafe.Add(unsafe.Pointer(i), -16))))
					if v7 < v8 {
						break
					}
				}
			}
		}
		v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*2))))
		v9++
		if v11 == 0 {
			return nil
		}
	}
	v12 = int32(*memmap.PtrUint32(0x587000, uintptr(v9*20)+208184))
	if v12 == 0 {
		return nil
	}
	v13 = sub_415D10(int32(uintptr(unsafe.Pointer(*(**byte)(memmap.PtrOff(0x587000, uintptr(v9*20)+208184))))))
	v14 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(v12)))
	v66 = int32(uintptr(unsafe.Pointer(v14)))
	if v14 == nil {
		return nil
	}
	switch v64 {
	case 2:
		v15 = nox_common_randomInt_415FA0(0, 1)
	case 4:
		v15 = nox_common_randomInt_415FA0(0, 2)
	case 8:
		v15 = nox_common_randomInt_415FA0(1, 3)
	case 16:
		v15 = nox_common_randomInt_415FA0(2, 4)
	default:
		return v14
	}
	if v15 == 0 {
		return v14
	}
	*(*uint32)(unsafe.Pointer(&v67[0])) = 0
	*(*uint32)(unsafe.Pointer(&v67[4])) = 0
	*(*uint32)(unsafe.Pointer(&v67[8])) = 0
	*(*uint32)(unsafe.Pointer(&v67[12])) = 0
	*(*uint16)(unsafe.Pointer(&v67[16])) = 0
	*(*uint16)(unsafe.Pointer(&v67[18])) = 0
	switch v15 {
	case 1:
		v16 = nox_common_randomInt_415FA0(1, 100)
		if v16 > 20 {
			v17 = int16(bool2int32(v16 > 50) + 1)
		} else {
			v17 = 4
		}
	case 2:
		v18 = nox_common_randomInt_415FA0(1, 100)
		if v18 > 12 {
			if v18 > 25 {
				v17 = 3
			} else {
				v17 = 6
			}
		} else {
			v17 = 5
		}
	case 3:
		v17 = 7
	default:
		v17 = 15
		if v15 != 4 {
			v17 = int16(uint16(a2))
		}
	}
	if int32(v17)&1 != 0 {
		v19 = 0
		if *memmap.PtrUint32(0x587000, 210856) == 0 {
		} else {
			v20 = (*uint8)(memmap.PtrOff(0x587000, 210852))
			for {
				if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v20)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*3)))) == 0 {
					v19++
				}
				v21 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v20))), 4*7))))
				v20 = (*uint8)(unsafe.Add(unsafe.Pointer(v20), 24))
				if v21 == 0 {
					break
				}
			}
		}
		if v19 == 0 {
			if int32(v17)&2 != 0 {
				if int32(v17)&4 != 0 {
					if (int32(v17) & 8) == 0 {
						v17 |= 8
					}
				} else {
					v17 |= 4
				}
			} else {
				v17 |= 2
			}
			v17 &= -0x2
		}
	}
	if int32(v17)&2 != 0 {
		v22 = 0
		if *memmap.PtrUint32(0x587000, 211000) == 0 {
		} else {
			v23 = (*uint8)(memmap.PtrOff(0x587000, 210996))
			for {
				if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v23)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*3)))) == 0 {
					v22++
				}
				v24 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*7))))
				v23 = (*uint8)(unsafe.Add(unsafe.Pointer(v23), 24))
				if v24 == 0 {
					break
				}
			}
		}
		if v22 == 0 {
			if int32(v17)&4 != 0 {
				if (int32(v17) & 8) == 0 {
					v17 |= 8
				}
			} else {
				v17 |= 4
			}
			v17 &= -0x3
		}
	}
	if int32(v17)&4 != 0 {
		v25 = 0
		if *memmap.PtrUint32(0x587000, 209344) == 0 {
		} else {
			v26 = (*uint8)(memmap.PtrOff(0x587000, 209340))
			for {
				if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v26))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v26)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v26))), 4*3)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v26)) + 36))))&1 != 0 {
					v25++
				}
				v27 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v26))), 4*7))))
				v26 = (*uint8)(unsafe.Add(unsafe.Pointer(v26), 24))
				if v27 == 0 {
					break
				}
			}
		}
		if v25 == 0 {
			v17 &= -0xD
		}
	}
	if int32(v17) == 0 {
		return v14
	}
	if (int32(v17) & 1) == 0 {
		goto LABEL_103
	}
	v28 = 0
	if *memmap.PtrUint32(0x587000, 210856) == 0 {
		goto LABEL_103
	}
	v29 = (*uint8)(memmap.PtrOff(0x587000, 210852))
	for {
		if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v29))), 4*2)))&uint32(v64) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v29)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v29))), 4*3)))) == 0 {
			v28++
		}
		v30 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v29))), 4*7))))
		v29 = (*uint8)(unsafe.Add(unsafe.Pointer(v29), 24))
		if v30 == 0 {
			break
		}
	}
	if v28 == 0 {
		goto LABEL_103
	}
	v31 = nox_common_randomInt_415FA0(0, v28-1)
	v32 = 0
	v33 = 0
	if *memmap.PtrUint32(0x587000, 210856) == 0 {
		goto LABEL_103
	}
	v34 = (*uint8)(memmap.PtrOff(0x587000, 210852))
	for {
		if (uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v34))), 4*2)))) == 0 || (uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v34)) + 32)))) == 0 || uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v34))), 4*3))) != 0 {
			goto LABEL_100
		}
		if v32 == v31 {
			break
		}
		v32++
	LABEL_100:
		v35 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v34))), 4*7))))
		v34 = (*uint8)(unsafe.Add(unsafe.Pointer(v34), 24))
		v33++
		if v35 == 0 {
			goto LABEL_103
		}
	}
	*(*uint32)(unsafe.Pointer(&v67[0])) = *memmap.PtrUint32(0x587000, uintptr(v33*24)+210852)
LABEL_103:
	if int32(v17)&2 != 0 {
		v36 = 0
		if *memmap.PtrUint32(0x587000, 211000) != 0 {
			v37 = (*uint8)(memmap.PtrOff(0x587000, 210996))
			for {
				if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v37))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v37)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v37))), 4*3)))) == 0 {
					v36++
				}
				v38 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v37))), 4*7))))
				v37 = (*uint8)(unsafe.Add(unsafe.Pointer(v37), 24))
				if v38 == 0 {
					break
				}
			}
			if v36 != 0 {
				v39 = nox_common_randomInt_415FA0(0, v36-1)
				v40 = 0
				v41 = 0
				if *memmap.PtrUint32(0x587000, 211000) != 0 {
					v42 = (*uint8)(memmap.PtrOff(0x587000, 210996))
					for {
						if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v42))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v42)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v42))), 4*3)))) == 0 {
							if v40 == v39 {
								*(*uint32)(unsafe.Pointer(&v67[4])) = *memmap.PtrUint32(0x587000, uintptr(v41*24)+210996)
								break
							}
							v40++
						}
						v43 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v42))), 4*7))))
						v42 = (*uint8)(unsafe.Add(unsafe.Pointer(v42), 24))
						v41++
						if v43 == 0 {
							break
						}
					}
				}
			}
		}
	}
	if int32(v17)&4 != 0 {
		v44 = 0
		if *memmap.PtrUint32(0x587000, 209344) != 0 {
			v45 = (*uint8)(memmap.PtrOff(0x587000, 209340))
			for {
				if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v45))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v45)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v45))), 4*3)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v45)) + 36))))&1 != 0 {
					v44++
				}
				v46 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v45))), 4*7))))
				v45 = (*uint8)(unsafe.Add(unsafe.Pointer(v45), 24))
				if v46 == 0 {
					break
				}
			}
			if v44 != 0 {
				v47 = nox_common_randomInt_415FA0(0, v44-1)
				v48 = 0
				v49 = 0
				if *memmap.PtrUint32(0x587000, 209344) != 0 {
					v50 = (*uint8)(memmap.PtrOff(0x587000, 209340))
					for {
						if uint32(v64)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v50))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v50)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v50))), 4*3)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v50)) + 36))))&1 != 0 {
							if v48 == v47 {
								v65 = v49
								*(*uint32)(unsafe.Pointer(&v67[8])) = *memmap.PtrUint32(0x587000, uintptr(v49*24)+209340)
								break
							}
							v48++
						}
						v51 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v50))), 4*7))))
						v50 = (*uint8)(unsafe.Add(unsafe.Pointer(v50), 24))
						v49++
						if v51 == 0 {
							break
						}
					}
				}
			}
		}
	}
	if int32(v17)&8 != 0 {
		v52 = int32(a2 >> 1)
		if int32(a2>>1) >= 1 {
			if v52 >= 5 {
				v52 = 4
			}
		} else {
			v52 = 1
		}
		v53 = v52 - 1
		v54 = v52 + 1
		if v53 < 1 {
			v53 = 1
		}
		if v54 >= 5 {
			v54 = 4
		}
		v55 = nox_common_randomInt_415FA0(v53, v54)
		v56 = 0
		if *memmap.PtrUint32(0x587000, 209344) != 0 {
			v57 = (*uint8)(memmap.PtrOff(0x587000, 209340))
			for {
				if uint32(v55)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v57))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v57)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v57))), 4*3)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v57)) + 36))))&2 != 0 {
					v56++
				}
				v58 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v57))), 4*7))))
				v57 = (*uint8)(unsafe.Add(unsafe.Pointer(v57), 24))
				if v58 == 0 {
					break
				}
			}
			if v56 != 0 {
				v59 = nox_common_randomInt_415FA0(0, v56-1)
				v60 = 0
				v61 = 0
				if *memmap.PtrUint32(0x587000, 209344) != 0 {
					v62 = (*uint8)(memmap.PtrOff(0x587000, 209340))
					for {
						if uint32(v55)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v62))), 4*2))) != 0 && uint32(v13)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v62)) + 32))) != 0 && (uint32(v13)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v62))), 4*3)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v62)) + 36))))&2 != 0 {
							if v60 == v59 {
								if int32(*memmap.PtrUint8(0x587000, uintptr(v65*24)+209336)) != int32(*memmap.PtrUint8(0x587000, uintptr(v61*24)+209336)) {
									*(*uint32)(unsafe.Pointer(&v67[12])) = *memmap.PtrUint32(0x587000, uintptr(v61*24)+209340)
								}
								break
							}
							v60++
						}
						v63 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v62))), 4*7))))
						v62 = (*uint8)(unsafe.Add(unsafe.Pointer(v62), 24))
						v61++
						if v63 == 0 {
							break
						}
					}
				}
			}
		}
	}
	nox_xxx_modifSetItemAttrs_4E4990((*nox_object_t)(unsafe.Pointer(uintptr(v66))), (*int32)(unsafe.Pointer(&v67[0])))
	return (*uint32)(unsafe.Pointer(uintptr(v66)))
}
func nox_xxx_rewardMakeWeapon_4F14E0(a1 int32, a2 uint32) int32 {
	var (
		v2  int32
		v3  int32
		v4  *uint8
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 *uint8
		v11 int32
		v12 *byte
		v13 *uint32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int16
		v20 int32
		v21 int32
		v22 int32
		v23 *uint8
		v24 int32
		v25 int32
		v26 *uint8
		v27 int32
		v28 int32
		v29 *uint8
		v30 int32
		v31 int32
		v32 *uint8
		v33 int32
		v34 int32
		v35 int32
		v36 int32
		v37 *uint8
		v38 int32
		v39 int32
		v40 *uint8
		v41 int32
		v42 int32
		v43 int32
		v44 int32
		v45 *uint8
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v50 int32
		v51 int32
		v52 *uint8
		v53 int32
		v54 int32
		v55 int32
		v56 int32
		v57 *uint8
		v58 int32
		v59 int32
		v60 int32
		v61 int32
		v62 int32
		v63 int32
		v64 *uint8
		v65 int32
		v66 int32
		v67 int32
		v68 int32
		v69 *uint8
		v70 int32
		v71 int16 = 0
		v72 int32
		v73 int32
		v74 int32
		v75 int32
		v76 [20]uint8
	)
	v74 = 0
	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2)
	v3 = 0
	v72 = v2
	if *memmap.PtrUint32(0x587000, 208180) == 0 {
		return 0
	}
	v4 = (*uint8)(memmap.PtrOff(0x587000, 208192))
	for {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), -4))))&1 != 0 && uint32(v2)&*(*uint32)(unsafe.Pointer(v4)) != 0 && nox_xxx_getUnitDefDd10_4E3BA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), -int(4*2)))))) != 0 {
			v3 += int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), -16))))
		}
		v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*2))))
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 20))
		if v5 == 0 {
			break
		}
	}
	if v3 == 0 {
		return 0
	}
	v7 = nox_common_randomInt_415FA0(0, v3-1)
	v8 = 0
	v9 = 0
	if *memmap.PtrUint32(0x587000, 208180) != 0 {
		v10 = (*uint8)(memmap.PtrOff(0x587000, 208192))
		for {
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v10), -4))))&1 != 0 {
				if uint32(v72)&*(*uint32)(unsafe.Pointer(v10)) != 0 {
					if nox_xxx_getUnitDefDd10_4E3BA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), -int(4*2)))))) != 0 {
						v8 += int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v10), -16))))
						if v7 < v8 {
							v12 = *(**byte)(memmap.PtrOff(0x587000, uintptr(v9*20)+208184))
							break
						}
					}
				}
			}
			v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v10))), 4*2))))
			v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 20))
			v9++
			if v11 == 0 {
				v12 = (*byte)(unsafe.Pointer(uintptr(a2)))
				break
			}
		}
	} else {
		v12 = (*byte)(unsafe.Pointer(uintptr(a2)))
	}
	if v12 == nil {
		return 0
	}
	v73 = nox_xxx_ammoCheck_415880(uint16(uintptr(unsafe.Pointer(v12))))
	v13 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(uintptr(unsafe.Pointer(v12))))))
	v14 = int32(uintptr(unsafe.Pointer(v13)))
	v75 = int32(uintptr(unsafe.Pointer(v13)))
	if v13 == nil {
		return 0
	}
	v15 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*2)))
	if v15&0x1000 != 0 && *(*uint32)(unsafe.Pointer(uintptr(v14 + 12)))&0x47F0000 != 0 {
		if int32(**(**uint8)(memmap.PtrOff(0x587000, uintptr(v9*20)+208180))) == 35 {
			*(*uint32)(unsafe.Pointer(&v76[0])) = 0
			*(*uint32)(unsafe.Pointer(&v76[4])) = 0
			v16 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment1"))
			*(*uint32)(unsafe.Pointer(&v76[8])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v16)))
			*(*uint32)(unsafe.Pointer(&v76[12])) = 0
			*(*uint16)(unsafe.Pointer(&v76[16])) = 0
			*(*uint16)(unsafe.Pointer(&v76[18])) = 0
			nox_xxx_modifSetItemAttrs_4E4990((*nox_object_t)(unsafe.Pointer(uintptr(v14))), (*int32)(unsafe.Pointer(&v76[0])))
		}
		return v14
	}
	switch v72 {
	case 2:
		v17 = nox_common_randomInt_415FA0(0, 1)
	case 4:
		v17 = nox_common_randomInt_415FA0(0, 2)
	case 8:
		v17 = nox_common_randomInt_415FA0(1, 3)
	case 16:
		v17 = nox_common_randomInt_415FA0(2, 4)
	default:
		return v14
	}
	if v17 == 0 {
		return v14
	}
	*(*uint32)(unsafe.Pointer(&v76[0])) = 0
	*(*uint32)(unsafe.Pointer(&v76[4])) = 0
	*(*uint32)(unsafe.Pointer(&v76[8])) = 0
	*(*uint32)(unsafe.Pointer(&v76[12])) = 0
	*(*uint16)(unsafe.Pointer(&v76[16])) = 0
	*(*uint16)(unsafe.Pointer(&v76[18])) = 0
	switch v17 {
	case 1:
		v18 = nox_common_randomInt_415FA0(1, 100)
		if v18 > 20 {
			v19 = int16(bool2int32(v18 > 50) + 1)
			*((*uint8)(unsafe.Pointer(&v71))) = uint8(int8(bool2int32(v18 > 50) + 1))
		} else {
			v19 = 4
			*((*uint8)(unsafe.Pointer(&v71))) = 4
		}
	case 2:
		v20 = nox_common_randomInt_415FA0(1, 100)
		if v20 > 12 {
			if v20 > 25 {
				v19 = 3
			} else {
				v19 = 6
			}
			if v20 > 25 {
				*((*uint8)(unsafe.Pointer(&v71))) = 3
			} else {
				*((*uint8)(unsafe.Pointer(&v71))) = 6
			}
		} else {
			v19 = 5
			*((*uint8)(unsafe.Pointer(&v71))) = 5
		}
	case 3:
		v19 = 7
		*((*uint8)(unsafe.Pointer(&v71))) = 7
	case 4:
		v19 = 15
		*((*uint8)(unsafe.Pointer(&v71))) = 15
	default:
		v19 = v71
	}
	if (int32(v19) & 1) == 0 {
		v22 = v73
		goto LABEL_67
	}
	v21 = 0
	if *memmap.PtrUint32(0x587000, 210712) == 0 {
		v22 = v73
	} else {
		v22 = v73
		v23 = (*uint8)(memmap.PtrOff(0x587000, 210708))
		for {
			if uint32(v72)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*2))) != 0 && uint32(v73)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v23)) + 28))) != 0 && (uint32(v73)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*4)))) == 0 {
				v21++
			}
			v24 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*7))))
			v23 = (*uint8)(unsafe.Add(unsafe.Pointer(v23), 24))
			if v24 == 0 {
				break
			}
		}
	}
	if v21 == 0 {
		if int32(v19)&2 != 0 {
			if int32(v19)&4 != 0 {
				if (int32(v19) & 8) == 0 {
					v19 |= 8
				}
				v19 &= -0x2
				*((*uint8)(unsafe.Pointer(&v71))) = uint8(int8(v19))
			} else {
				v19 = int16((int32(v19) | 4) & 0xFFFE)
				*((*uint8)(unsafe.Pointer(&v71))) = uint8(int8(v19))
			}
		} else {
			v19 = int16((int32(v19) | 2) & 0xFFFE)
			*((*uint8)(unsafe.Pointer(&v71))) = uint8(int8(v19))
		}
	}
LABEL_67:
	if int32(v19)&2 != 0 {
		v25 = 0
		if *memmap.PtrUint32(0x587000, 211000) == 0 {
		} else {
			v26 = (*uint8)(memmap.PtrOff(0x587000, 210996))
			for {
				if uint32(v72)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v26))), 4*2))) != 0 && uint32(v22)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v26)) + 28))) != 0 && (uint32(v22)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v26))), 4*4)))) == 0 {
					v25++
				}
				v27 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v26))), 4*7))))
				v26 = (*uint8)(unsafe.Add(unsafe.Pointer(v26), 24))
				if v27 == 0 {
					break
				}
			}
		}
		if v25 == 0 {
			if int32(v19)&4 != 0 {
				if (int32(v19) & 8) == 0 {
					v19 |= 8
				}
			} else {
				v19 |= 4
			}
			v19 &= -0x3
			*((*uint8)(unsafe.Pointer(&v71))) = uint8(int8(v19))
		}
	}
	if int32(v19)&4 != 0 {
		v28 = 0
		if *memmap.PtrUint32(0x587000, 209344) == 0 {
		} else {
			v29 = (*uint8)(memmap.PtrOff(0x587000, 209340))
			for {
				if uint32(v72)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v29))), 4*2))) != 0 && uint32(v22)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v29)) + 28))) != 0 && (uint32(v22)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v29))), 4*4)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v29)) + 36))))&1 != 0 {
					v28++
				}
				v30 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v29))), 4*7))))
				v29 = (*uint8)(unsafe.Add(unsafe.Pointer(v29), 24))
				if v30 == 0 {
					break
				}
			}
		}
		if v28 == 0 {
			v19 &= -0xD
			*((*uint8)(unsafe.Pointer(&v71))) = uint8(int8(v19))
		}
	}
	if int32(v19) == 0 {
		return v14
	}
	if int32(v19)&1 != 0 {
		v31 = 0
		if *memmap.PtrUint32(0x587000, 210712) != 0 {
			v32 = (*uint8)(memmap.PtrOff(0x587000, 210708))
			for {
				if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v32))), 4*2)))&uint32(v72) != 0 && uint32(v22)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v32)) + 28))) != 0 && (uint32(v22)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v32))), 4*4)))) == 0 {
					v31++
				}
				v33 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v32))), 4*7))))
				v32 = (*uint8)(unsafe.Add(unsafe.Pointer(v32), 24))
				if v33 == 0 {
					break
				}
			}
			if v31 != 0 {
				v34 = nox_common_randomInt_415FA0(0, v31-1)
				v35 = 0
				v36 = 0
				if *memmap.PtrUint32(0x587000, 210712) != 0 {
					v37 = (*uint8)(memmap.PtrOff(0x587000, 210708))
					for {
						if uint32(v72)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v37))), 4*2))) != 0 && uint32(v22)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v37)) + 28))) != 0 && (uint32(v22)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v37))), 4*4)))) == 0 {
							if v35 == v34 {
								*(*uint32)(unsafe.Pointer(&v76[0])) = *memmap.PtrUint32(0x587000, uintptr(v36*24)+210708)
								break
							}
							v35++
						}
						v38 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v37))), 4*7))))
						v37 = (*uint8)(unsafe.Add(unsafe.Pointer(v37), 24))
						v36++
						if v38 == 0 {
							break
						}
					}
				}
			}
		}
	}
	if int32(v19)&2 != 0 {
		v39 = 0
		if *memmap.PtrUint32(0x587000, 211000) != 0 {
			v40 = (*uint8)(memmap.PtrOff(0x587000, 210996))
			for {
				if uint32(v72)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v40))), 4*2))) != 0 && uint32(v22)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v40)) + 28))) != 0 && (uint32(v22)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v40))), 4*4)))) == 0 {
					v39++
				}
				v41 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v40))), 4*7))))
				v40 = (*uint8)(unsafe.Add(unsafe.Pointer(v40), 24))
				if v41 == 0 {
					break
				}
			}
			if v39 != 0 {
				v42 = nox_common_randomInt_415FA0(0, v39-1)
				v43 = 0
				v44 = 0
				if *memmap.PtrUint32(0x587000, 211000) != 0 {
					v45 = (*uint8)(memmap.PtrOff(0x587000, 210996))
					for {
						if uint32(v72)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v45))), 4*2))) != 0 && uint32(v22)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v45)) + 28))) != 0 && (uint32(v22)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v45))), 4*4)))) == 0 {
							if v43 == v42 {
								*(*uint32)(unsafe.Pointer(&v76[4])) = *memmap.PtrUint32(0x587000, uintptr(v44*24)+210996)
								break
							}
							v43++
						}
						v46 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v45))), 4*7))))
						v45 = (*uint8)(unsafe.Add(unsafe.Pointer(v45), 24))
						v44++
						if v46 == 0 {
							break
						}
					}
				}
			}
		}
	}
	if int32(v19)&4 != 0 {
		v47 = int32(a2 >> 1)
		if int32(a2>>1) >= 1 {
			if v47 >= 5 {
				v47 = 4
			}
		} else {
			v47 = 1
		}
		v48 = v47 - 1
		v49 = v47 + 1
		if v48 < 1 {
			v48 = 1
		}
		if v49 >= 5 {
			v49 = 4
		}
		v50 = nox_common_randomInt_415FA0(v48, v49)
		v51 = 0
		if *memmap.PtrUint32(0x587000, 209344) != 0 {
			v52 = (*uint8)(memmap.PtrOff(0x587000, 209340))
			for {
				if uint32(v50)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v52))), 4*2))) != 0 && uint32(v73)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v52)) + 28))) != 0 && (uint32(v73)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v52))), 4*4)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v52)) + 36))))&1 != 0 {
					v51++
				}
				v53 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v52))), 4*7))))
				v52 = (*uint8)(unsafe.Add(unsafe.Pointer(v52), 24))
				if v53 == 0 {
					break
				}
			}
			if v51 != 0 {
				v54 = nox_common_randomInt_415FA0(0, v51-1)
				v55 = 0
				v56 = 0
				if *memmap.PtrUint32(0x587000, 209344) != 0 {
					v57 = (*uint8)(memmap.PtrOff(0x587000, 209340))
					for {
						if uint32(v50)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v57))), 4*2))) != 0 {
							if uint32(v73)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v57)) + 28))) != 0 && (uint32(v73)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v57))), 4*4)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v57)) + 36))))&1 != 0 {
								if v55 == v54 {
									*((*uint8)(unsafe.Pointer(&v19))) = uint8(int8(v71))
									v74 = v56
									*(*uint32)(unsafe.Pointer(&v76[8])) = *memmap.PtrUint32(0x587000, uintptr(v56*24)+209340)
									break
								}
								v55++
							}
							*((*uint8)(unsafe.Pointer(&v19))) = uint8(int8(v71))
						}
						v58 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v57))), 4*7))))
						v57 = (*uint8)(unsafe.Add(unsafe.Pointer(v57), 24))
						v56++
						if v58 == 0 {
							break
						}
					}
				}
			}
		}
	}
	if int32(v19)&8 != 0 {
		v59 = int32(a2 >> 1)
		if int32(a2>>1) >= 1 {
			if v59 >= 5 {
				v59 = 4
			}
		} else {
			v59 = 1
		}
		v60 = v59 - 1
		v61 = v59 + 1
		if v60 < 1 {
			v60 = 1
		}
		if v61 >= 5 {
			v61 = 4
		}
		v62 = nox_common_randomInt_415FA0(v60, v61)
		v63 = 0
		if *memmap.PtrUint32(0x587000, 209344) != 0 {
			v64 = (*uint8)(memmap.PtrOff(0x587000, 209340))
			for {
				if uint32(v62)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v64))), 4*2))) != 0 && uint32(v73)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v64)) + 28))) != 0 && (uint32(v73)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v64))), 4*4)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v64)) + 36))))&2 != 0 {
					v63++
				}
				v65 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v64))), 4*7))))
				v64 = (*uint8)(unsafe.Add(unsafe.Pointer(v64), 24))
				if v65 == 0 {
					break
				}
			}
			if v63 != 0 {
				v66 = nox_common_randomInt_415FA0(0, v63-1)
				v67 = 0
				v68 = 0
				if *memmap.PtrUint32(0x587000, 209344) != 0 {
					v69 = (*uint8)(memmap.PtrOff(0x587000, 209340))
					for {
						if uint32(v62)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v69))), 4*2))) != 0 && uint32(v73)&*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v69)) + 28))) != 0 && (uint32(v73)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v69))), 4*4)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(v69)) + 36))))&2 != 0 {
							if v67 == v66 {
								if int32(*memmap.PtrUint8(0x587000, uintptr(v74*24)+209336)) != int32(*memmap.PtrUint8(0x587000, uintptr(v68*24)+209336)) {
									*(*uint32)(unsafe.Pointer(&v76[12])) = *memmap.PtrUint32(0x587000, uintptr(v68*24)+209340)
								}
								break
							}
							v67++
						}
						v70 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v69))), 4*7))))
						v69 = (*uint8)(unsafe.Add(unsafe.Pointer(v69), 24))
						v68++
						if v70 == 0 {
							break
						}
					}
				}
			}
		}
	}
	nox_xxx_modifSetItemAttrs_4E4990((*nox_object_t)(unsafe.Pointer(uintptr(v75))), (*int32)(unsafe.Pointer(&v76[0])))
	return v75
}
func nox_xxx_rewardMakePotion_4F1C40(a1 int32, a2 uint32) *uint32 {
	var (
		v2     int32
		v3     int32
		v4     *uint8
		v5     int32
		result *uint32
	)
	_ = result
	var v7 int32
	var v8 int32
	var v9 int32
	var i *uint8
	var v11 int32
	var v12 int32
	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2)
	v3 = 0
	v12 = v2
	if *memmap.PtrUint32(0x587000, 208180) == 0 {
		return nil
	}
	v4 = (*uint8)(memmap.PtrOff(0x587000, 208192))
	for {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), -4))))&4 != 0 && uint32(v2)&*(*uint32)(unsafe.Pointer(v4)) != 0 && nox_xxx_getUnitDefDd10_4E3BA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), -int(4*2)))))) != 0 {
			v3 += int32(*((*uint8)(unsafe.Add(unsafe.Pointer(v4), -16))))
		}
		v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*2))))
		v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 20))
		if v5 == 0 {
			break
		}
	}
	if v3 == 0 {
		return nil
	}
	v7 = nox_common_randomInt_415FA0(0, v3-1)
	v8 = 0
	v9 = 0
	if *memmap.PtrUint32(0x587000, 208180) == 0 {
		return nil
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 208192)); ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 20)) {
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(i), -4))))&4 != 0 {
			if *(*uint32)(unsafe.Pointer(i))&uint32(v12) != 0 {
				if nox_xxx_getUnitDefDd10_4E3BA0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), -int(4*2)))))) != 0 {
					v8 += int32(*((*uint8)(unsafe.Add(unsafe.Pointer(i), -16))))
					if v7 < v8 {
						break
					}
				}
			}
		}
		v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*2))))
		v9++
		if v11 == 0 {
			return nil
		}
	}
	if *memmap.PtrUint32(0x587000, uintptr(v9*20)+208184) != 0 {
		return (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*memmap.PtrUint32(0x587000, uintptr(v9*20)+208184)))))
	} else {
		return nil
	}
}
func nox_xxx_createGem_4F1D30(a1 int32, a2 uint32) *uint32 {
	var (
		v2     uint32
		v3     int32
		result *uint32
		v5     *uint32
		v6     *int32
	)
	_ = v6
	v2 = uint32(nox_server_rewardGen_pickRandomSlots_4F0B60(a2))
	if v2 < 4 || nox_common_randomInt_415FA0(1, 100) <= 90 {
		if nox_common_randomInt_415FA0(1, 2) == 1 {
			result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("QuestGoldChest"))))
		} else {
			result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("QuestGoldPile"))))
		}
		v5 = result
		if result != nil {
			v6 = (*int32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*173)))))
			switch v2 {
			case 2:
				*v6 = nox_common_randomInt_415FA0(*memmap.PtrInt32(0x587000, 211144), *memmap.PtrInt32(0x587000, 211148))
				result = v5
			case 4:
				*v6 = nox_common_randomInt_415FA0(*memmap.PtrInt32(0x587000, 211152), *memmap.PtrInt32(0x587000, 211156))
				result = v5
			case 8:
				*v6 = nox_common_randomInt_415FA0(*memmap.PtrInt32(0x587000, 211160), *memmap.PtrInt32(0x587000, 211164))
				result = v5
			case 0x10:
				*v6 = nox_common_randomInt_415FA0(*memmap.PtrInt32(0x587000, 211168), *memmap.PtrInt32(0x587000, 211172))
				result = v5
			default:
				*v6 = nox_common_randomInt_415FA0(*memmap.PtrInt32(0x587000, 211136), *memmap.PtrInt32(0x587000, 211140))
				result = v5
			}
		}
	} else {
		v3 = nox_common_randomInt_415FA0(1, 100)
		if v3 >= 50 {
			if v3 >= 90 {
				result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("DiamondGem"))))
			} else {
				result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("EmeraldGem"))))
			}
		} else {
			result = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("RubyGem"))))
		}
	}
	return result
}
func nox_xxx_createGem2_4F1F00(a1 int32, a2 uint32) *uint32 {
	return nox_xxx_createGem_4F1D30(a1, a2)
}
func sub_4F2110() {
	var (
		v0 int32
		i  int32
		v2 int32
		v3 int32
		v4 int32
		j  int32
		v6 int32
		v7 *uint32
	)
	v0 = 0
	if dword_5d4594_1568280 == 0 {
		dword_5d4594_1568280 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RewardMarker")))
		*memmap.PtrUint32(0x5D4594, 1568284) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RewardMarkerPlus")))
	}
	for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(i))))))) {
		v2 = int32(*(*uint16)(unsafe.Pointer(uintptr(i + 4))))
		if (uint32(uint16(int16(v2))) == dword_5d4594_1568280 || uint32(v2) == *memmap.PtrUint32(0x5D4594, 1568284)) && (int32(**(**uint8)(unsafe.Pointer(uintptr(i + 692))))&0x80) != 0 {
			v0++
		}
	}
	v3 = nox_common_randomInt_415FA0(0, v0-1)
	v4 = 0
	for j = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); j != 0; j = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(j))))))) {
		v6 = int32(*(*uint16)(unsafe.Pointer(uintptr(j + 4))))
		if (uint32(uint16(int16(v6))) == dword_5d4594_1568280 || uint32(v6) == *memmap.PtrUint32(0x5D4594, 1568284)) && (int32(**(**uint8)(unsafe.Pointer(uintptr(j + 692))))&0x80) != 0 {
			if v4 == v3 {
				v7 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("Ankh"))))
				if v7 != nil {
					nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v7)))))), nil, *(*float32)(unsafe.Pointer(uintptr(j + 56))), *(*float32)(unsafe.Pointer(uintptr(j + 60))))
					nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(j))))
					return
				}
			} else {
				v4++
			}
		}
	}
}
func sub_4F2210() int32 {
	var (
		v0     *uint32
		v1     int32
		v2     int32
		v3     int32
		v4     int32
		result int32
		v6     int32
		v7     uint32
		v8     *uint32
		v9     *uint32
		v10    int32
		v11    int32
		v12    int8
		v13    int32
		v14    int32
		v15    *uint32
		v16    int32
		v17    int32
		v18    *int32
		v19    int32
		v20    int32
		v21    uint32
		v22    int32
		v23    *uint32
		v24    int32
		v25    int32
		v26    uint32
		v27    *int32
		v28    float32 = 0
		lpMem  *uint32
		v30    uint32
		v31    uint32
	)
	v0 = nil
	lpMem = nil
	v1 = nox_game_getQuestStage_4E3CC0()
	v2 = nox_xxx_player_4E3CE0()
	if dword_5d4594_1568288 == 0 {
		dword_5d4594_1568288 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RewardMarker")))
		*memmap.PtrUint32(0x5D4594, 1568292) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RewardMarkerPlus")))
		*memmap.PtrUint32(0x5D4594, 1568296) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RedPotion")))
	}
	if v1 == 1 {
		v28 = 0.5
	} else {
		switch v2 {
		case 1:
			fallthrough
		case 2:
			v28 = 0.40000001
		case 3:
			fallthrough
		case 4:
			v28 = 0.69999999
		case 5:
			fallthrough
		case 6:
			v28 = 1.0
		default:
		}
	}
	v3 = 0
	v4 = 0
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if result != 0 {
		for {
			v6 = int32(*(*uint16)(unsafe.Pointer(uintptr(result + 4))))
			if uint32(uint16(int16(v6))) == dword_5d4594_1568288 {
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(result + 692))) + 216)))) & 1) == 0 {
					v3++
				}
			} else if uint32(v6) == *memmap.PtrUint32(0x5D4594, 1568296) {
				v4++
			}
			result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
			if result == 0 {
				break
			}
		}
		if v3 != 0 {
			v0 = (*uint32)(alloc.Calloc(int(v3), 4))
			if v4 == 0 {
				goto LABEL_21
			}
		} else if v4 == 0 {
			return result
		}
		lpMem = (*uint32)(alloc.Calloc(int(v4), 4))
	LABEL_21:
		v7 = 0
		v30 = 0
		result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
		if result != 0 {
			v8 = lpMem
			v9 = v0
			for {
				v10 = int32(*(*uint16)(unsafe.Pointer(uintptr(result + 4))))
				if uint32(uint16(int16(v10))) == dword_5d4594_1568288 {
					v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(result + 692))))
					v12 = int8(*(*uint8)(unsafe.Pointer(uintptr(v11 + 216))))
					if int32(v12)&1 != 0 {
						*(*uint8)(unsafe.Pointer(uintptr(v11 + 216))) = uint8(int8(int32(v12) | 0x80))
					} else {
						*v9 = uint32(result)
						v7++
						v9 = (*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*1))
					}
				} else if uint32(v10) == *memmap.PtrUint32(0x5D4594, 1568292) {
					*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(result + 692))) + 216))) |= 0x80
				} else if uint32(v10) == *memmap.PtrUint32(0x5D4594, 1568296) {
					*v8 = uint32(result)
					v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
					v30++
				}
				result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*nox_object_t)(unsafe.Pointer(uintptr(result)))))))
				if result == 0 {
					break
				}
			}
			if v7 != 0 {
				v13 = int32(v7 - 1)
				v14 = int32(int64(float64(v7)*float64(v28) + 0.5))
				if v7 != 1 {
					v15 = (*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*uintptr(v13)))
					for {
						v16 = nox_common_randomInt_415FA0(0, v13)
						v17 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*uintptr(v16))))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v0), 4*uintptr(v16))) = *v15
						*v15 = uint32(v17)
						v13--
						v15 = (*uint32)(unsafe.Add(unsafe.Pointer(v15), -int(4*1)))
						if v13 == 0 {
							break
						}
					}
				}
				if v14 != 0 {
					v18 = (*int32)(unsafe.Pointer(v0))
					v19 = v14
					for {
						v20 = *v18
						v18 = (*int32)(unsafe.Add(unsafe.Pointer(v18), 4*1))
						v19--
						*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v20 + 692))) + 216))) |= 0x80
						if v19 == 0 {
							break
						}
					}
				}
				alloc.Free(v0)
			}
			v21 = v30
			if v30 != 0 {
				v22 = int32(v30 - 1)
				v31 = uint32(int32(int64(float64(v30)*float64(v28) + 0.5)))
				if v21 != 1 {
					v23 = (*uint32)(unsafe.Add(unsafe.Pointer(lpMem), 4*uintptr(v22)))
					for {
						v24 = nox_common_randomInt_415FA0(0, v22)
						v25 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(lpMem), 4*uintptr(v24))))
						*(*uint32)(unsafe.Add(unsafe.Pointer(lpMem), 4*uintptr(v24))) = *v23
						*v23 = uint32(v25)
						v22--
						v23 = (*uint32)(unsafe.Add(unsafe.Pointer(v23), -int(4*1)))
						if v22 == 0 {
							break
						}
					}
				}
				v26 = 0
				if v21 != 0 {
					v27 = (*int32)(unsafe.Pointer(lpMem))
					for {
						if v26 >= v31 {
							nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(*v27))))
						}
						v26++
						v27 = (*int32)(unsafe.Add(unsafe.Pointer(v27), 4*1))
						if v26 >= v21 {
							break
						}
					}
				}
				alloc.Free(lpMem)
			}
		}
	}
	return result
}
func sub_4F24E0(a1 int32) int32 {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = int32(*memmap.PtrUint32(0x587000, 207108))
	if *memmap.PtrUint32(0x587000, 207108) == 0 {
		return 0
	}
	v2 = (*uint8)(memmap.PtrOff(0x587000, 207108))
	for v1 != a1 || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*1))) == 0 {
		v1 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*3))))
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 12))
		if v1 == 0 {
			return 0
		}
	}
	if a1 != 0 && a1 != 34 && a1 != 27 && a1 != 9 && a1 != 41 {
		return 1
	} else {
		return 0
	}
}
func sub_4F2530(a1 int32) int32 {
	var (
		v1 int32
		i  *uint8
	)
	v1 = int32(*memmap.PtrUint32(0x587000, 207796))
	if *memmap.PtrUint32(0x587000, 207796) == 0 {
		return 0
	}
	for i = (*uint8)(memmap.PtrOff(0x587000, 207796)); v1 != a1 || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*1))) == 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
		v1 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*3))))
		if v1 == 0 {
			return 0
		}
	}
	return bool2int32(a1 != 0)
}
func sub_4F2570(a1 int32) int32 {
	return bool2int32(a1 > 0 && a1 < 6)
}
func sub_4F2590(a1 int32) int32 {
	var (
		v1 int32
		v3 int32
		v4 int32
		v5 *uint8
		v6 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1568328) == 0 {
		*memmap.PtrUint32(0x5D4594, 1568328) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Diamond")))
		*memmap.PtrUint32(0x5D4594, 1568332) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Emerald")))
		*memmap.PtrUint32(0x5D4594, 1568336) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Ruby")))
		*memmap.PtrUint32(0x5D4594, 1568340) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SulphorousFlareWand")))
		*memmap.PtrUint32(0x5D4594, 1568344) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("StreetSneakers")))
		*memmap.PtrUint32(0x5D4594, 1568352) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("StreetShirt")))
		*memmap.PtrUint32(0x5D4594, 1568348) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("StreetPants")))
	}
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))))
	if v1&0x40 != 0 {
		return 0
	}
	if v1&0x10 != 0 {
		return bool2int32((*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))) & 0x1FF78) != 0)
	}
	if v1&0x100 != 0 {
		return sub_4F2700(a1)
	}
	v3 = int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))
	if uint32(uint16(int16(v3))) != *memmap.PtrUint32(0x5D4594, 1568328) && uint32(v3) != *memmap.PtrUint32(0x5D4594, 1568332) && uint32(v3) != *memmap.PtrUint32(0x5D4594, 1568336) {
		v4 = 0
		if *memmap.PtrUint32(0x587000, 208180) != 0 {
			v5 = (*uint8)(memmap.PtrOff(0x587000, 208180))
			for *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1))) != uint32(v3) {
				v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*5))))
				v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 20))
				if v6 == 0 {
					goto LABEL_18
				}
			}
			v4 = 1
		}
	LABEL_18:
		if uint32(v3) == *memmap.PtrUint32(0x5D4594, 1568340) || uint32(v3) == *memmap.PtrUint32(0x5D4594, 1568344) || uint32(v3) == *memmap.PtrUint32(0x5D4594, 1568352) || uint32(v3) == *memmap.PtrUint32(0x5D4594, 1568348) {
			return sub_4F2B60(a1)
		}
		if v4 != 1 {
			return 0
		}
		if uint32(v1)&0x1000000 != 0 {
			return sub_4F27A0(a1)
		}
		if uint32(v1)&0x2000000 != 0 {
			return sub_4F2B20(a1)
		}
	}
	return 1
}
func sub_4F2700(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		i  *uint8
		v5 int32
		v6 int32
		j  *uint8
		v8 uint8
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 12))))
	if v1&1 != 0 {
		if *memmap.PtrUint32(0x587000, 207108) != 0 {
			v2 = int32(*memmap.PtrUint32(0x587000, 207108))
			for i = (*uint8)(memmap.PtrOff(0x587000, 207108)); v2 != int32(**(**uint8)(unsafe.Pointer(uintptr(a1 + 736)))) || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*1))) == 0; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 12)) {
				v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*3))))
				if v2 == 0 {
					return 0
				}
			}
			return 1
		}
		return 0
	}
	if v1&2 != 0 {
		v5 = nox_xxx_guide_427010(*(**byte)(unsafe.Pointer(uintptr(a1 + 736))))
		v6 = int32(*memmap.PtrUint32(0x587000, 207796))
		if *memmap.PtrUint32(0x587000, 207796) != 0 {
			for j = (*uint8)(memmap.PtrOff(0x587000, 207796)); v6 != v5 || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*1))) == 0; j = (*uint8)(unsafe.Add(unsafe.Pointer(j), 12)) {
				v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*3))))
				if v6 == 0 {
					return 0
				}
			}
			return 1
		}
		return 0
	}
	if (v1 & 4) == 0 {
		return 0
	}
	v8 = **(**uint8)(unsafe.Pointer(uintptr(a1 + 736)))
	if int32(v8) == 0 || int32(v8) >= 6 {
		return 0
	}
	return 1
}
func sub_4F27A0(a1 int32) int32 {
	var result int32
	result = sub_4F27E0(a1)
	if result != 0 {
		result = sub_4F28C0(a1)
		if result != 0 {
			result = bool2int32(sub_4F2960(a1) != 0)
		}
	}
	return result
}
func sub_4F27E0(a1 int32) int32 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		i   *uint8
		v6  int32
		v8  *uint8
		v9  int32
		j   *uint8
		v11 int32
	)
	v1 = int32(**(**uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	if v1 == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 {
		v2 = nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	} else {
		v2 = nox_xxx_unitArmorInventoryEquipFlags_415C70((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 8))) & 0x1000000)
	if v3 != 0 {
		v4 = 0
		if *memmap.PtrUint32(0x587000, 210712) != 0 {
			for i = (*uint8)(memmap.PtrOff(0x587000, 210712)); *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), -int(4*1)))) != uint32(v1); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
				v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*6))))
				v4++
				if v6 == 0 {
					return 0
				}
			}
			v8 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v4*24)+210704))
			goto LABEL_18
		}
		return 0
	}
	v9 = 0
	if *memmap.PtrUint32(0x587000, 210856) == 0 {
		return 0
	}
	for j = (*uint8)(memmap.PtrOff(0x587000, 210856)); *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), -int(4*1)))) != uint32(v1); j = (*uint8)(unsafe.Add(unsafe.Pointer(j), 24)) {
		v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*6))))
		v9++
		if v11 == 0 {
			return 0
		}
	}
	v8 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v9*24)+210848))
LABEL_18:
	if v8 == nil {
		return 0
	}
	if v3 != 0 {
		if (uint32(v2)&*(*uint32)(unsafe.Pointer(uintptr(v1 + 28)))) == 0 || uint32(v2)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*5))) != 0 {
			return 0
		}
	} else if (uint32(v2)&*(*uint32)(unsafe.Pointer(uintptr(v1 + 32)))) == 0 || uint32(v2)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v8))), 4*4))) != 0 {
		return 0
	}
	return 1
}
func sub_4F28C0(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		i  *uint8
		v5 int32
		v7 *uint8
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))) + 4))))
	if v1 != 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 {
			v2 = nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		} else {
			v2 = nox_xxx_unitArmorInventoryEquipFlags_415C70((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		}
		v3 = 0
		if *memmap.PtrUint32(0x587000, 211000) == 0 {
			return 0
		}
		for i = (*uint8)(memmap.PtrOff(0x587000, 211000)); *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), -int(4*1)))) != uint32(v1); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 24)) {
			v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(i))), 4*6))))
			v3++
			if v5 == 0 {
				return 0
			}
		}
		v7 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v3*24)+210992))
		if v7 == nil {
			return 0
		}
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 {
			if (uint32(v2)&*(*uint32)(unsafe.Pointer(uintptr(v1 + 28)))) == 0 || uint32(v2)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*5))) != 0 {
				return 0
			}
		} else if (uint32(v2)&*(*uint32)(unsafe.Pointer(uintptr(v1 + 32)))) == 0 || uint32(v2)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v7))), 4*4))) != 0 {
			return 0
		}
	}
	return 1
}
func sub_4F2960(a1 int32) int32 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int8
		v9  *uint8
		v10 int32
		v11 *uint8
		v12 int32
		v13 *uint8
		v14 *uint8
		v16 int32
	)
	v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	if dword_5d4594_1568308 == 0 {
		v1 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment1"))
		dword_5d4594_1568308 = uint32(uintptr(nox_xxx_modifGetDescById_413330(v1)))
		v2 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment2"))
		*memmap.PtrUint32(0x5D4594, 1568312) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v2)))
		v3 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment3"))
		*memmap.PtrUint32(0x5D4594, 1568316) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v3)))
		v4 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment4"))
		*memmap.PtrUint32(0x5D4594, 1568320) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v4)))
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 {
		v5 = nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	} else {
		v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
	v6 = 2
	for {
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v16 + v6*4))))
		if v7 == 0 {
			goto LABEL_40
		}
		v8 = int8(*(*uint8)(unsafe.Pointer(uintptr(v7 + 36))))
		v9 = nil
		if v6 == 2 {
			if (int32(v8) & 1) == 0 {
				return 0
			}
		} else if (int32(v8) & 2) == 0 {
			return 0
		}
		v10 = 0
		if *memmap.PtrUint32(0x587000, 209344) == 0 {
		} else {
			v11 = (*uint8)(memmap.PtrOff(0x587000, 209344))
			for {
				if *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), -int(4*1)))) == uint32(v7) {
					v9 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v10*24)+209336))
					break
				}
				v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 24))
				v10++
				if *(*uint32)(unsafe.Pointer(v11)) == 0 {
					break
				}
			}
		}
		if v9 == nil {
			if uint32(v7) == dword_5d4594_1568308 {
				goto LABEL_A
			}
			if uint32(v7) != *memmap.PtrUint32(0x5D4594, 1568312) && uint32(v7) != *memmap.PtrUint32(0x5D4594, 1568316) && uint32(v7) != *memmap.PtrUint32(0x5D4594, 1568320) {
				return 0
			}
		}
		if uint32(v7) == dword_5d4594_1568308 || uint32(v7) == *memmap.PtrUint32(0x5D4594, 1568312) || uint32(v7) == *memmap.PtrUint32(0x5D4594, 1568316) || uint32(v7) == *memmap.PtrUint32(0x5D4594, 1568320) {
			goto LABEL_A
		}
		if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 {
			if (uint32(v5)&*(*uint32)(unsafe.Pointer(uintptr(v7 + 28)))) == 0 || uint32(v5)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v9))), 4*5))) != 0 {
				return 0
			}
		} else if (uint32(v5)&*(*uint32)(unsafe.Pointer(uintptr(v7 + 32)))) == 0 || uint32(v5)&*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v9))), 4*4))) != 0 {
			return 0
		}
		goto LABEL_40
	LABEL_A:
		v12 = 0
		if *memmap.PtrUint32(0x587000, 208180) == 0 {
			return 0
		}
		v13 = *(**uint8)(memmap.PtrOff(0x587000, 208180))
		v14 = (*uint8)(memmap.PtrOff(0x587000, 208180))
		for {
			if int32(*v13) == 35 && *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v14))), 4*1))) == uint32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4)))) {
				v12 = 1
			}
			v13 = (*uint8)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v14))), 4*5))))))
			v14 = (*uint8)(unsafe.Add(unsafe.Pointer(v14), 20))
			if v13 == nil {
				break
			}
		}
		if v12 == 0 {
			return 0
		}
	LABEL_40:
		if func() int32 {
			p := &v6
			*p++
			return *p
		}() >= 4 {
			return 1
		}
	}
}
func sub_4F2B20(a1 int32) int32 {
	var result int32
	result = sub_4F27E0(a1)
	if result != 0 {
		result = sub_4F28C0(a1)
		if result != 0 {
			result = bool2int32(sub_4F2960(a1) != 0)
		}
	}
	return result
}
func sub_4F2B60(a1 int32) int32 {
	var (
		v1 int32
		v2 *uint32
		v4 int16
		v5 ***byte
		v6 int32
	)
	if *memmap.PtrUint32(0x5D4594, 1568324) == 0 {
		v1 = nox_xxx_modifGetIdByName_413290(internCStr("Replenishment1"))
		*memmap.PtrUint32(0x5D4594, 1568324) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v1)))
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x1000000 != 0 && uint32(nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))&0x10000 != 0 {
		v2 = *(**uint32)(unsafe.Pointer(uintptr(a1 + 692)))
		if *v2 != 0 {
			return 0
		}
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) != 0 {
			return 0
		}
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)) != *memmap.PtrUint32(0x5D4594, 1568324) {
			return 0
		}
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) != 0 {
			return 0
		}
	}
	if *(*uint32)(unsafe.Pointer(uintptr(a1 + 8)))&0x2000000 != 0 {
		v4 = int16(nox_xxx_unitArmorInventoryEquipFlags_415C70((*nox_object_t)(unsafe.Pointer(uintptr(a1)))))
		v5 = *(****byte)(unsafe.Pointer(uintptr(a1 + 692)))
		if int32(v4)&0x405 != 0 {
			v6 = 0
			for *v5 == nil || nox_strnicmp(**v5, internCStr("UserColo"), 8) == 0 {
				v6++
				v5 = (***byte)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((**byte)(nil))*1))
				if v6 >= 4 {
					return 1
				}
			}
			return 0
		}
	}
	return 1
}
func sub_4F2C30(a1 int32) int32 {
	var (
		v1 int32
		v3 float32
	)
	if *memmap.PtrUint32(0x5D4594, 1568356) == 0 {
		*memmap.PtrUint32(0x5D4594, 1568356) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RedPotion")))
		*memmap.PtrUint32(0x5D4594, 1568360) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("BluePotion")))
		*memmap.PtrUint32(0x5D4594, 1568364) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("CurePoisonPotion")))
		*memmap.PtrUint32(0x5D4594, 1568368) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("HastePotion")))
		*memmap.PtrUint32(0x5D4594, 1568372) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("InvisibilityPotion")))
		*memmap.PtrUint32(0x5D4594, 1568376) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ShieldPotion")))
		*memmap.PtrUint32(0x5D4594, 1568380) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("VampirismPotion")))
		*memmap.PtrUint32(0x5D4594, 1568384) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("FireProtectPotion")))
		*memmap.PtrUint32(0x5D4594, 1568388) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ShockProtectPotion")))
		*memmap.PtrUint32(0x5D4594, 1568392) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("PoisonProtectPotion")))
		*memmap.PtrUint32(0x5D4594, 1568396) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("InvulnerabilityPotion")))
		*memmap.PtrUint32(0x5D4594, 1568400) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("InfravisionPotion")))
		*memmap.PtrUint32(0x5D4594, 1568404) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("InfinitePainWand")))
	}
	if a1 == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4) == 0 {
		return 1
	}
	if nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568356)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568360)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568364)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568368)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568372)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568376)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568380)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568384)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568388)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568392)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568396)) > 9 || nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568400)) > 9 {
		return 0
	}
	v3 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ForceOfNatureStaffLimit")))
	v1 = nox_float2int(v3)
	return bool2int32(nox_xxx_inventoryCountObjects_4E7D30(a1, *memmap.PtrInt32(0x5D4594, 1568404)) <= v1)
}
func nox_xxx_spell_4F2E70(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 *uint8
	)
	v1 = int32(*memmap.PtrUint32(0x587000, 207108))
	v2 = 0
	if *memmap.PtrUint32(0x587000, 207108) != 0 {
		v3 = (*uint8)(memmap.PtrOff(0x587000, 207108))
		for v1 != a1 || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) == 0 {
			v1 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*3))))
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
			if v1 == 0 {
				goto LABEL_8
			}
		}
		v2 = 1
	}
LABEL_8:
	if a1 == 46 || a1 == 47 || a1 == 48 || a1 == 49 || a1 == 122 || a1 == 123 || a1 == 124 || a1 == 125 {
		v2 = 1
	}
	return bool2int32(a1 >= 75 && a1 <= 114 || v2 != 0)
}
func sub_4F2EF0(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 *uint8
		v4 *int32
		v5 *uint8
		v6 int32
		v7 *int32
		v8 int32
	)
	v1 = int32(*memmap.PtrUint32(0x587000, 207796))
	v2 = 0
	if *memmap.PtrUint32(0x587000, 207796) != 0 {
		v3 = (*uint8)(memmap.PtrOff(0x587000, 207796))
		for v1 != a1 || *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*1))) == 0 {
			v1 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v3))), 4*3))))
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 12))
			if v1 == 0 {
				goto LABEL_8
			}
		}
		v2 = 1
	}
LABEL_8:
	v4 = *(**int32)(memmap.PtrOff(0x587000, 207032))
	v5 = (*uint8)(memmap.PtrOff(0x587000, 207032))
	if *memmap.PtrUint32(0x587000, 207032) != 0 {
		for {
			v6 = *v4
			v7 = (*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
			if v6 != 0 {
				for {
					v8 = *v7
					if *v7 == a1 {
						break
					}
					v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
					if v8 == 0 {
						goto LABEL_14
					}
				}
				v2 = 1
			}
		LABEL_14:
			v4 = (*int32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v5))), 4*1))))))
			v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 4))
			if v4 == nil {
				break
			}
		}
	}
	return bool2int32(v2 != 0)
}
func nox_xxx_playerTryEquip_4F2F70(a1 *nox_object_t, item *nox_object_t) int32 {
	var result int32
	if nox_xxx_playerEquipWeapon_53A420((*uint32)(unsafe.Pointer(a1)), item, 1, 1) != 0 || (func() int32 {
		result = nox_xxx_playerEquipArmor_53E650((*uint32)(unsafe.Pointer(a1)), item, 1, 1)
		return result
	}()) != 0 {
		result = 1
	}
	return result
}
func nox_xxx_playerTryDequip_4F2FB0(a1 *uint32, object *nox_object_t) int32 {
	var result int32
	if nox_xxx_playerDequipWeapon_53A140(a1, object, 1, 1) != 0 || (func() int32 {
		result = sub_53E430(a1, object, 1, 1)
		return result
	}()) != 0 {
		result = 1
	}
	return result
}
func nox_xxx_itemApplyEngageEffect_4F2FF0(item *nox_object_t, a2 int32) int32 {
	var (
		v2     int32
		v3     *int32
		result int32
		v5     func(int32, int32, int32) int32
	)
	v2 = 2
	v3 = (*int32)(unsafe.Pointer(uintptr(int32(uintptr(item.init_data)) + 8)))
	for {
		result = *v3
		if *v3 != 0 {
			v5 = *(*func(int32, int32, int32) int32)(unsafe.Pointer(uintptr(result + 112)))
			if v5 != nil {
				result = v5(result, a2, int32(uintptr(unsafe.Pointer(item))))
			}
		}
		v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
		v2--
		if v2 == 0 {
			break
		}
	}
	return result
}
func nox_xxx_itemApplyDisengageEffect_4F3030(object *nox_object_t, a2 int32) int32 {
	var (
		v2     int32
		v3     *int32
		result int32
		v5     func(int32, int32, int32) int32
	)
	v2 = 2
	v3 = (*int32)(unsafe.Pointer(uintptr(int32(uintptr(object.init_data)) + 8)))
	for {
		result = *v3
		if *v3 != 0 {
			v5 = *(*func(int32, int32, int32) int32)(unsafe.Pointer(uintptr(result + 116)))
			if v5 != nil {
				result = v5(result, a2, int32(uintptr(unsafe.Pointer(object))))
			}
		}
		v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
		v2--
		if v2 == 0 {
			break
		}
	}
	return result
}
func nox_xxx_inventoryPutImpl_4F3070(a1p *nox_object_t, item *nox_object_t, a3 int32) {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v3 int32
		v4 int32
		v5 int32
		i  int32
		v7 int32
	)
	v3 = 0
	if a1 != 0 && item != nil && (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 16))))&0x20) == 0 && (item.obj_flags&0x20) == 0 {
		*(*uint32)(unsafe.Pointer(&item.field_125)) = 0
		*(*uint32)(unsafe.Pointer(&item.inv_next_item)) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 504)))
		v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
		if v4 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v4 + 500))) = uint32(uintptr(unsafe.Pointer(item)))
		}
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))) = uint32(uintptr(unsafe.Pointer(item)))
		*(*uint32)(unsafe.Pointer(&item.inv_holder)) = uint32(a1)
		nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), item)
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))))
			if a3 != 0 {
				nox_xxx_netReportPickup_4D8A60(int32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 2064)))), item)
			}
			nox_xxx_protect_56FBF0(int32(*(*uint32)(unsafe.Pointer(uintptr(v5 + 4632)))), item)
			for i = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504)))); i != 0; v3 += v7 {
				v7 = int32(*(*uint8)(unsafe.Pointer(uintptr(i + 488))))
				i = int32(*(*uint32)(unsafe.Pointer(uintptr(i + 496))))
			}
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 3656))) = uint32(bool2int32(v3 > int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 490))))))
		}
		if int32(*(*uint8)(unsafe.Pointer(&item.obj_class)))&0x40 != 0 {
			nox_xxx_aud_501960(820, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
}
func nox_xxx_playerCheckStrength_4F3180(a1p *nox_object_t, item *nox_object_t) bool {
	var a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
	if nox_cheat_allowall != 0 {
		return true
	}
	var v2 int32
	var v3 *uint32
	var result bool
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && (func() *uint32 {
		if func() bool {
			v2 = nox_xxx_unitGetStrength_4F9FD0(a1)
			return (item.obj_class & 0x2000000) == 0
		}() {
			v3 = (*uint32)(nox_xxx_getProjectileClassById_413250(int32(item.typ_ind)))
		} else {
			v3 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(item.typ_ind)))
		}
		return v3
	}()) != nil {
		result = v2 >= int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v3))), unsafe.Sizeof(uint16(0))*30))))
	} else {
		result = false
	}
	return result
}
func nox_xxx_pickupDefault_4F31E0(a1p *nox_object_t, item *nox_object_t, a3 int32) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v3     int32
		v4     int32
		v6     *byte
		v7     int32
		result int32
		v9     int32
		i      int32
		v11    int32
		v12    int32
		v13    int32
	)
	v3 = bool2int32(nox_common_gameFlags_check_40A5C0(4096))
	v4 = a1
	if v3 != 0 || nox_xxx_servObjectHasTeam_419130(int32(uintptr(unsafe.Pointer(&item.field_12)))) == 0 || nox_xxx_servCompareTeams_419150(v4+48, int32(uintptr(unsafe.Pointer(&item.field_12)))) != 0 || (func() *byte {
		v6 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(&item.field_13))))))
		return v6
	}()) == nil {
		if *(*uint32)(unsafe.Pointer(&item.inv_holder)) != 0 {
			result = 0
		} else if int32(*(*uint16)(unsafe.Pointer(uintptr(v4 + 490)))) != 0 {
			v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 504))))
			for i = 0; v9 != 0; i += v11 {
				v11 = int32(*(*uint8)(unsafe.Pointer(uintptr(v9 + 488))))
				v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(v9 + 496))))
			}
			if int32(*(*uint16)(unsafe.Pointer(uintptr(v4 + 490))))*2-i >= int32(item.weight) {
				if (int32(*(*uint8)(unsafe.Pointer(&item.obj_class)))&0x10) != 16 || (func() bool {
					if func() bool {
						v12 = nox_xxx_inventoryCountObjects_4E7D30(v4, int32(item.typ_ind))
						return !nox_common_gameFlags_check_40A5C0(6144)
					}() {
						v13 = v12 - 3
					} else {
						v13 = v12 - 9
					}
					return v13 < 0
				}()) {
					nox_xxx_servFinalizeDelObject_4DADE0(item)
					nox_xxx_inventoryPutImpl_4F3070((*nox_object_t)(unsafe.Pointer(uintptr(v4))), item, a3)
					result = 1
				} else {
					nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v4))), internCStr("pickup.c:MaxSameItem"), 0)
					result = 0
				}
			} else {
				nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(v4))), internCStr("pickup.c:CarryingTooMuch"), 0)
				result = 0
			}
		} else {
			result = 0
		}
	} else {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(v4 + 8))))&4 != 0 {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v4 + 748))))
			a1 = int32(uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v6), 56))))
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v7 + 276))) + 2064)))), 16, &a1)
		}
		result = 0
	}
	return result
}
func nox_xxx_pickupFood_4F3350(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v4 int32
		v5 *uint8
	)
	if a1 == 0 || a2 == 0 {
		return 0
	}
	if sub_419E60((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) == 0 && (int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 12))))&0x84) == 0 {
		(*(*func(int32, int32))(unsafe.Pointer(uintptr(a2 + 732))))(a1, a2)
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&0x20 != 0 {
		return 1
	}
	v4 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
	if v4 != 0 {
		v5 = (*uint8)(memmap.PtrOff(0x587000, 215640))
		if int32(*memmap.PtrUint16(0x587000, 215646)) != 0 {
			for (*(*uint32)(unsafe.Pointer(uintptr(a2 + 12)))&*(*uint32)(unsafe.Pointer(v5))) == 0 && (int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v5))), unsafe.Sizeof(uint16(0))*2))))&int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 24))))) == 0 {
				v5 = (*uint8)(unsafe.Add(unsafe.Pointer(v5), 8))
				if int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v5))), unsafe.Sizeof(uint16(0))*3)))) == 0 {
					return v4
				}
			}
			nox_xxx_aud_501960(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v5))), unsafe.Sizeof(uint16(0))*3)))), (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
	}
	return v4
}
func sub_4F3400(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		result int32
		v5     int32
		v6     [10]byte
	)
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 748))))
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
		return 0
	}
	v5 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
	if v5 != 0 {
		*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 264))) = gameFrame()
		nox_xxx_unitSetOwner_4EC290((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))))
		nox_xxx_buffApplyTo_4FF380((*nox_object_t)(unsafe.Pointer(uintptr(a1))), 30, 0, 5)
		nox_xxx_aud_501960(313, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		*(*uint32)(unsafe.Pointer(&v6[2])) = *(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))
		if nox_xxx_servObjectHasTeam_419130(a1+48) != 0 {
			*(*uint32)(unsafe.Pointer(&v6[6])) = uint32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52))))
		} else {
			*(*uint32)(unsafe.Pointer(&v6[6])) = 0
		}
		nox_xxx_netInformTextMsg2_4DA180(10, (*uint8)(unsafe.Pointer(&v6[0])))
		nox_xxx_netUnmarkMinimapSpec_417470(a2, 1)
	}
	result = v5
	*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) = 0
	return result
}
func nox_xxx_pickupUse_4F34D0(a1 int32, a2 int32, a3 int32) int32 {
	var result int32
	nox_xxx_useByNetCode_53F8E0(a1, a2)
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&0x20 != 0 {
		result = 1
	} else {
		result = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
	}
	return result
}
func nox_xxx_pickupTrap_4F3510(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		result int32
	)
	if nox_xxx_unitHasThatParent_4EC4F0((*nox_object_t)(unsafe.Pointer(uintptr(a2))), (*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 {
		v3 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
		if v3 != 0 {
			nox_xxx_aud_501960(824, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		}
		result = v3
	} else {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 {
			nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))))
		}
		result = 0
	}
	return result
}
func nox_xxx_pickupTreasure_4F3580(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3 int32
		v4 int32
		v5 *byte
		j  int32
		i  int32
	)
	if nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3) == 0 {
		return 0
	}
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
		return 1
	}
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if !nox_common_gameFlags_check_40A5C0(64) {
		return 1
	}
	nox_xxx_aud_501960(307, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2152)))++
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2156))) = uint32(nox_xxx_scavengerTreasureMax_4D1600())
	nox_xxx_scavengerHuntReport_4D8CD0(a1)
	if nox_xxx_servObjectHasTeam_419130(a1+48) == 0 {
		if *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v3 + 276))) + 2152))) == uint32(nox_xxx_scavengerTreasureMax_4D1600()) {
			nox_xxx_setGameFlags_40A4D0(8)
			nox_xxx_changeScore_4D8E90(a1, 1)
			nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			for i = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(i))))))) {
				if i != a1 {
					nox_xxx_playerIncrementElimDeath_4D8D40(i)
					nox_xxx_netReportLesson_4D8EF0((*nox_object_t)(unsafe.Pointer(uintptr(i))))
				}
			}
		}
		return 1
	}
	v4 = 0
	v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 52)))))))
	if v5 != nil {
		for j = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0()))); j != 0; j = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*nox_object_t)(unsafe.Pointer(uintptr(j))))))) {
			if nox_xxx_teamCompare2_419180(unsafe.Pointer(uintptr(j+48)), uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v5), 57)))) != 0 {
				v4 += int32(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(j + 748))) + 276))) + 2152))))
			}
		}
		if v4 == nox_xxx_scavengerTreasureMax_4D1600() {
			nox_xxx_setGameFlags_40A4D0(8)
		}
	}
	return 1
}
func nox_xxx_inventoryServPlace_4F36F0(a1p *nox_object_t, a2p *nox_object_t, a3 int32, a4 int32) int32 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v4 int32
		v5 func(int32, int32, int32, int32) int32
		v6 int32
		v7 int32
		v8 int32
	)
	if a1 == 0 {
		return 0
	}
	if a2 == 0 {
		return 0
	}
	if int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 490)))) == 0 {
		return 0
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&0x20 != 0 {
		return 0
	}
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 16))))
	if (v4&0x8000) != 0 || nox_xxx_getUnitDefDd10_4E3BA0(int32(*(*uint16)(unsafe.Pointer(uintptr(a2 + 4))))) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&6) == 0 {
		return 0
	}
	v5 = *(*func(int32, int32, int32, int32) int32)(unsafe.Pointer(uintptr(a2 + 708)))
	if v5 != nil {
		v6 = v5(a1, a2, a3, a4)
	} else {
		v6 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
	}
	v7 = v6
	if v6 != 0 {
		v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))))
		if v8&0x40 != 0 {
			*((*uint8)(unsafe.Pointer(&v8))) = uint8(int8(v8 & 0xBF))
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 16))) = uint32(v8)
			if *(*uint32)(unsafe.Pointer(uintptr(a2 + 696))) != 0 {
				sub_5117F0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
			}
		}
		if *(*int32)(unsafe.Pointer(uintptr(a2 + 768))) != -1 {
			nox_xxx_scriptCallByEventBlock_502490(unsafe.Pointer(uintptr(a2+764)), unsafe.Pointer(uintptr(a1)), unsafe.Pointer(uintptr(a2)), 18)
			*(*uint32)(unsafe.Pointer(uintptr(a2 + 768))) = math.MaxUint32
		}
	}
	return v7
}
func nox_xxx_pickupPotion_4F37D0(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3  int32
		v4  *int32
		v5  int32
		v7  int8
		v8  float64
		v9  int32
		v10 int8
		v11 float64
		v12 int32
		v13 int32
		v14 float32
		v15 float32
		v16 int32
		v17 int32
	)
	v3 = a2
	v4 = *(**int32)(unsafe.Pointer(uintptr(a2 + 736)))
	v16 = 0
	v5 = *v4
	v17 = *v4
	if nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && nox_xxx_playerClassCanUseItem_57B3D0((*nox_object_t)(unsafe.Pointer(uintptr(v3))), int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 2251))))) == 0 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), internCStr("pickup.c:ObjectEquipClassFail"), 0)
		nox_xxx_aud_501960(925, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 2, int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 36)))))
		return 0
	}
	if sub_419E60((*nox_object_t)(unsafe.Pointer(uintptr(a1)))) != 0 {
		goto LABEL_36
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 12))))&0x10 != 0 && *(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) != 0 {
		if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
			goto LABEL_17
		}
		v7 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 276))) + 2251))))
		if int32(v7) != 0 {
			if int32(v7) == 1 {
				v8 = float64(v17) * float64(nox_xxx_wizardMaxHealth_587000_312816)
			} else {
				if int32(v7) != 2 {
					goto LABEL_17
				}
				v8 = float64(v17) * float64(nox_xxx_conjurerMaxHealth_587000_312800)
			}
		} else {
			v8 = float64(v17) * float64(nox_xxx_warriorMaxHealth_587000_312784)
		}
		v15 = float32(v8)
		v5 = nox_float2int(v15)
		v17 = v5
	LABEL_17:
		if v5+int32(**(**uint16)(unsafe.Pointer(uintptr(a1 + 556)))) < int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 556))) + 4)))) {
			nox_xxx_unitAdjustHP_4EE460((*nox_object_t)(unsafe.Pointer(uintptr(a1))), v5)
			nox_xxx_aud_501960(754, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			v16 = 1
		}
	}
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 12))))&0x20) == 0 || (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4) == 0 {
		goto LABEL_30
	}
	v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v10 = int8(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v9 + 276))) + 2251))))
	if int32(v10) != 0 {
		if int32(v10) == 1 {
			v11 = float64(v17) * float64(nox_xxx_wizardMaximumMana_587000_312820)
		} else {
			if int32(v10) != 2 {
				goto LABEL_28
			}
			v11 = float64(v17) * float64(nox_xxx_conjurerMaxMana_587000_312804)
		}
	} else {
		v11 = float64(v17) * float64(nox_xxx_warriorMaxMana_587000_312788)
	}
	v14 = float32(v11)
	v5 = nox_float2int(v14)
LABEL_28:
	if v5+int32(*(*uint16)(unsafe.Pointer(uintptr(v9 + 4)))) < int32(*(*uint16)(unsafe.Pointer(uintptr(v9 + 8)))) {
		nox_xxx_playerManaAdd_4EEB80((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int16(v5))
		nox_xxx_aud_501960(755, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		v16 = 1
	}
LABEL_30:
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v3 + 12))))&0x40 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8))))&4 != 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 540)))) != 0 {
		nox_xxx_removePoison_4EE9D0(a1)
		v12 = nox_xxx_spellGetAud44_424800(14, 1)
		nox_xxx_aud_501960(v12, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
		return 1
	}
	if v16 != 0 {
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
		return 1
	}
LABEL_36:
	nox_xxx_decay_5116F0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
	v13 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(v3))), a3)
	if v13 == 1 {
		nox_xxx_aud_501960(832, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	return v13
}
func nox_xxx_pickupAmmo_4F3B00(a1 int32, item *nox_object_t, a3 int32, a4 int32) int32 {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  *uint32
		v9  *byte
		v10 *uint32
		v11 int32
		v12 int32
		v13 int32
		v15 int8
		v16 int8
		v17 int8
		v18 int32
		v19 *uint8
		v20 *uint32
		v21 int32
	)
	v5 = nox_xxx_weaponInventoryEquipFlags_415820(item)
	v6 = a1
	v18 = v5
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
		return sub_53A720(v6, item, a3, a4)
	}
	v21 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	if (v5 & 0x82) == 0 {
		return sub_53A720(v6, item, a3, a4)
	}
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
	v8 = (*uint32)(item.init_data)
	v20 = (*uint32)(item.init_data)
	v19 = (*uint8)(item.use_data)
	if v7 == 0 {
		return sub_53A720(v6, item, a3, a4)
	}
	for {
		if int32(*(*uint16)(unsafe.Pointer(uintptr(v7 + 4)))) != int32(item.typ_ind) || (*(*uint32)(unsafe.Pointer(uintptr(v7 + 8)))&0x1000000) == 0 || (nox_xxx_weaponInventoryEquipFlags_415820((*nox_object_t)(unsafe.Pointer(uintptr(v7))))&v18) == 0 {
			goto LABEL_15
		}
		v9 = *(**byte)(unsafe.Pointer(uintptr(v7 + 736)))
		v10 = v8
		v11 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 692))) - uint32(uintptr(unsafe.Pointer(v8))))
		v12 = 1
		v13 = 4
		for {
			if *(*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v10))), v11)))) != *v10 {
				v12 = 0
			}
			v10 = (*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*1))
			v13--
			if v13 == 0 {
				break
			}
		}
		if v12 == 1 && *(*byte)(unsafe.Add(unsafe.Pointer(v9), 2)) == 0 && int32(*v19)+int32(uint8(*v9)) <= 250 {
			break
		}
		v6 = a1
		v8 = v20
	LABEL_15:
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 496))))
		if v7 == 0 {
			return sub_53A720(v6, item, a3, a4)
		}
	}
	v15 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 1)) + uint8(*(*byte)(unsafe.Add(unsafe.Pointer(v9), 1))))
	v16 = int8(*v9)
	*(*byte)(unsafe.Add(unsafe.Pointer(v9), 1)) = byte(v15)
	v17 = int8(int32(*v19) + int32(v16))
	*v9 = byte(v17)
	nox_xxx_netReportCharges_4D82B0(int32(*(*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(v21 + 276))) + 2064)))), (*nox_object_t)(unsafe.Pointer(uintptr(v7))), v15, v17)
	nox_xxx_delayedDeleteObject_4E5CC0(item)
	sub_53A6C0(a1, item)
	return 1
}
func nox_xxx_pickupSpellbook_4F3C60(a1 int32, a2 int32, a3 int32) int32 {
	var v4 int32
	if nox_common_gameFlags_check_40A5C0(6144) {
		nox_xxx_useByNetCode_53F8E0(a1, a2)
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&0x20 != 0 {
		return 1
	}
	v4 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
	if v4 != 0 {
		if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 12))))&1 != 0 {
			nox_xxx_aud_501960(826, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
			return v4
		}
		nox_xxx_aud_501960(828, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	return v4
}
func nox_xxx_pickupAbilitybook_4F3CE0(a1 int32, a2 int32, a3 int32) int32 {
	var v4 int32
	if nox_common_gameFlags_check_40A5C0(6144) {
		nox_xxx_useByNetCode_53F8E0(a1, a2)
	}
	if int32(*(*uint8)(unsafe.Pointer(uintptr(a2 + 16))))&0x20 != 0 {
		return 1
	}
	v4 = nox_xxx_pickupDefault_4F31E0((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), a3)
	if v4 != 0 {
		nox_xxx_aud_501960(826, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	}
	return v4
}
func sub_4F3DD0(a1 int32, a2 int32) int32 {
	if (int32(*(*uint8)(unsafe.Pointer(uintptr(a1 + 8)))) & 4) == 0 {
		return 0
	}
	*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))) + 320)))++
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a2))))
	nox_xxx_aud_501960(1004, (*nox_object_t)(unsafe.Pointer(uintptr(a1))), 0, 0)
	return 1
}
func nox_xxx_xfer_4F3E30(a1 uint16, a2p *nox_object_t, a3 int32) int32 {
	var (
		a2  int32 = int32(uintptr(unsafe.Pointer(a2p)))
		v3  int32
		v4  uint16
		v5  *uint32
		v6  *uint32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
		v12 int32
		v13 [256]byte
	)
	v3 = 0
	if a3 <= 0 {
		return 1
	}
	for {
		if int32(a1) < 0x3C {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13[0])), uint32(uint8(int8(v10))))
			v13[uint8(int8(v10))] = 0
			v4 = uint16(int16(nox_xxx_getNameId_4E3AA0(&v13[0])))
			if int32(v4) == 0 {
				return 0
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 2)
			v4 = uint16(int16(nox_xxx_objectTOCgetTT_42C2B0(uint16(int16(v11)))))
			if int32(v4) == 0 {
				return 0
			}
		}
		nox_xxx_fileCryptReadCrcMB_426C20((*uint8)(unsafe.Pointer(&v12)), 4)
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(v4))))
		v6 = v5
		if v5 == nil || (asFunc(*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*176)), (*func(*uint32, uint32) int32)(nil)).(func(*uint32, uint32) int32))(v5, 0) == 0 {
			break
		}
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 504))))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*125)) = 0
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*124)) = uint32(v7)
		v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(a2 + 504))))
		if v8 != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v8 + 500))) = uint32(uintptr(unsafe.Pointer(v6)))
		}
		v3++
		*(*uint32)(unsafe.Pointer(uintptr(a2 + 504))) = uint32(uintptr(unsafe.Pointer(v6)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*123)) = uint32(a2)
		if v3 >= a3 {
			return 1
		}
	}
	return 0
}
func nox_xxx_servMapLoadPlaceObj_4F3F50(a1p *nox_object_t, a2 int32, a3p unsafe.Pointer) int32 {
	var (
		a1     int32  = int32(uintptr(unsafe.Pointer(a1p)))
		a3     *int32 = (*int32)(a3p)
		v3     int32
		v4     int32
		result int32
		v6     *byte
		v7     int32
		v8     int32
	)
	if nox_common_gameFlags_check_40A5C0(0x400000) || nox_xxx_getUnitDefDd10_4E3BA0(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))) != 0 {
		if a3 != nil {
			v6 = nox_xxx_mapGetWallSize_426A70()
			*(*float32)(unsafe.Pointer(uintptr(a1 + 56))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 56)))) - float64(int32(*(*uint32)(unsafe.Pointer(v6))*23)) + float64(*a3) - 11.0)
			*(*float32)(unsafe.Pointer(uintptr(a1 + 60))) = float32(float64(*(*float32)(unsafe.Pointer(uintptr(a1 + 60)))) - float64(int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v6))), 4*1)))*23)) + float64(*(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1))) - 11.0)
		}
		if nox_common_gameFlags_check_40A5C0(0x400000) {
			nox_xxx_unitAddToList_5048A0(a1)
			result = 1
		} else if nox_common_gameFlags_check_40A5C0(0x200000) || sub_4E3AD0(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))) != 0 {
			nox_xxx_createAt_4DAA50((*nox_object_t)(unsafe.Pointer(uintptr(a1))), (*nox_object_t)(unsafe.Pointer(uintptr(a2))), *(*float32)(unsafe.Pointer(uintptr(a1 + 56))), *(*float32)(unsafe.Pointer(uintptr(a1 + 60))))
			result = 1
		} else {
			v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
			if v7 != 0 {
				for {
					v8 = int32(*(*uint32)(unsafe.Pointer(uintptr(v7 + 496))))
					nox_xxx_objectFreeMem_4E38A0((*nox_object_t)(unsafe.Pointer(uintptr(v7))))
					v7 = v8
					if v8 == 0 {
						break
					}
				}
			}
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))) = 0
			nox_xxx_objectFreeMem_4E38A0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
			result = 0
		}
	} else {
		v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 504))))
		if v3 != 0 {
			for {
				v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(v3 + 496))))
				nox_xxx_objectFreeMem_4E38A0((*nox_object_t)(unsafe.Pointer(uintptr(v3))))
				v3 = v4
				if v4 == 0 {
					break
				}
			}
		}
		nox_xxx_objectFreeMem_4E38A0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
		result = 0
	}
	return result
}
func nox_xxx_readObjectOldVer_4F4170(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3     **uint8
		v4     *uint8
		v5     uint32
		v6     *uint8
		v7     int32
		v8     int32
		v9     int32
		v10    *uint32
		v11    *uint8
		result int32
		v13    *uint8
		v14    *int32
		v15    *uint8
		v16    uint16
		j      *uint8
		i      uint32
		v19    int32
		v20    int32
		v21    int32
		v22    int32
		v23    [2]int32
	)
	v3 = (**uint8)(unsafe.Pointer(uintptr(a1)))
	*((*uint8)(unsafe.Pointer(&v20))) = 0
	if nox_crypt_IsReadOnly() == 1 {
		*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))) = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 40)), 4)
	v4 = *(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4))
	v21 = int32(uint32(uintptr(unsafe.Pointer(*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4))))) & 0x11408162)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
	v5 = uint32(uintptr(unsafe.Pointer(*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4))))) & 0xEEBF7E9D
	*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4)) = (*uint8)(unsafe.Pointer(uintptr(v5)))
	v6 = (*uint8)(unsafe.Pointer(uintptr(v5)))
	if int32(uint8(uintptr(unsafe.Pointer(v4))))&0x40 != 0 {
		*((*uint8)(unsafe.Pointer(&v6))) = uint8(v5 | 0x40)
		*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4)) = v6
	}
	v7 = v21
	*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4)) = (*uint8)(unsafe.Pointer(uintptr(uint32(v21) | uint32(uintptr(unsafe.Pointer(*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*4))))))))
	if nox_crypt_IsReadOnly() == 1 {
		if uint32(v7)&0x1000000 != 0 {
			nox_xxx_objectSetOn_4E75B0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))
		} else {
			nox_xxx_objectSetOff_4E7600((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))))
		}
	}
	v8 = a3
	v9 = a2
	if nox_crypt_IsReadOnly() != 0 {
		if a3 < 40 || a2 < 4 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23[0])), 8)
			v10 = (*uint32)(unsafe.Pointer((**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*14))))
			*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v3))), unsafe.Sizeof(float32(0))*14))) = float32(float64(v23[0]))
			*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v3))), unsafe.Sizeof(float32(0))*15))) = float32(float64(v23[1]))
		} else {
			v10 = (*uint32)(unsafe.Pointer((**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*14))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 56)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 60)), 4)
		}
		v11 = (*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*1)))))
		*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*16)) = (*uint8)(unsafe.Pointer(uintptr(*v10)))
		*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*17)) = v11
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 56)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 60)), 4)
	}
	if v8 >= 10 {
		if *v3 != nil {
			*((*uint8)(unsafe.Pointer(&v19))) = uint8(int8(libc.StrLen((*byte)(unsafe.Pointer(*v3)))))
		} else {
			*((*uint8)(unsafe.Pointer(&v19))) = 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			if int32(uint8(int8(v19))) != 0 {
				result = int32(uintptr(alloc.Calloc(1, int(int32(uint8(int8(v19)))+1))))
				*v3 = (*uint8)(unsafe.Pointer(uintptr(result)))
				if result == 0 {
					return result
				}
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*v3, uint32(uint8(int8(v19))))
		if *v3 != nil {
			*(*uint8)(unsafe.Add(unsafe.Pointer(*v3), uint8(int8(v19)))) = 0
		}
	}
	if v8 >= 20 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 52)), 1)
	}
	if v8 >= 30 {
		v13 = *(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*126))
		for *((*uint8)(unsafe.Pointer(&v20))) = 0; v13 != nil; *((*uint8)(unsafe.Pointer(&v20))) = uint8(int8(v20 + 1)) {
			v13 = (*uint8)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v13))), 4*124))))))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*34)) = (*uint8)(unsafe.Pointer(uintptr(uint8(int8(v20)))))
		}
	}
	if v8 >= 40 {
		v14 = (*int32)(unsafe.Pointer((**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*11))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v3))), 44)), 4)
		if *(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*11)) == nil && nox_crypt_IsReadOnly() == 1 && !nox_common_gameFlags_check_40A5C0(0x200000) && !nox_common_gameFlags_check_40A5C0(0x400000) {
			*v14 = int32(nox_server_NextObjectScriptID())
		}
		if v9 >= 2 {
			v15 = *(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*129))
			v16 = 0
			a1 = 0
			if v15 != nil {
				for {
					if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v15), 16)))&0x20) == 0 && sub_4E3B80(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v15))), unsafe.Sizeof(uint16(0))*2))))) != 0 {
						a1++
					}
					v15 = (*uint8)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v15))), 4*128))))))
					if v15 == nil {
						break
					}
				}
				v16 = uint16(int16(a1))
			}
			if v9 < 5 {
				v22 = int32(v16)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 4)
				a1 = v22
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
			}
			if nox_crypt_IsReadOnly() != 0 {
				for i = 0; i < uint32(uint16(int16(a1))); i++ {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a3)), 4)
					if !nox_common_gameFlags_check_40A5C0(0x200000) && !nox_common_gameFlags_check_40A5C0(0x400000) {
						sub_516F90(*v14, a3)
					}
				}
			} else {
				for j = *(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*129)); j != nil; j = (*uint8)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(j))), 4*128)))))) {
					if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(j), 16)))&0x20) == 0 && sub_4E3B80(int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(j))), unsafe.Sizeof(uint16(0))*2))))) != 0 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(j), 44)), 4)
					}
				}
			}
		}
		if v9 >= 3 {
			v21 = int32(uint32(uintptr(unsafe.Pointer(*(**uint8)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*uint8)(nil))*5))))) & 0x5E)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
			nox_xxx_unitUnsetXStatus_4E4780((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), 94)
			nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v3)))))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(v21)))))))
		}
	}
	return 1
}
func nox_xxx_mapReadWriteObjData_4F4530(a1p *nox_object_t, a2 int32) int32 {
	var (
		a1     *int32 = (*int32)(unsafe.Pointer(a1p))
		v2     *int32
		v3     int32
		v4     int32
		v5     int16
		result int32
		v7     *int32
		v8     *int32
		v9     int32
		v10    int32
		v11    uint32
		v12    uint32
		v13    int32
		v14    int32
		v15    int32
		k      int32
		j      uint32
		v18    int32
		v19    int32
		i      int32
		v21    int32
		v22    [2]int32
		v23    int32
	)
	v2 = a1
	v3 = a2
	v4 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34))
	v5 = 0
	*((*uint8)(unsafe.Pointer(&v19))) = 0
	v18 = 0
	v23 = v4
	if a2 >= 40 || nox_crypt_IsReadOnly() == 0 {
		v18 = 64
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 2)
		v5 = int16(v18)
		if int32(int16(v18)) > 64 {
			return 0
		}
	}
	if v3 < 40 || int32(v5) < 61 {
		return nox_xxx_readObjectOldVer_4F4170(int32(uintptr(unsafe.Pointer(v2))), int32(v5), v3)
	}
	if nox_crypt_IsReadOnly() == 1 {
		*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*34)) = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 40)), 4)
	v7 = (*int32)(unsafe.Add(unsafe.Pointer(v2), 4*11))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 44)), 4)
	if *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*11)) == 0 && nox_crypt_IsReadOnly() == 1 && !nox_common_gameFlags_check_40A5C0(0x200000) && !nox_common_gameFlags_check_40A5C0(0x400000) {
		*v7 = int32(nox_server_NextObjectScriptID())
	}
	if nox_crypt_IsReadOnly() != 0 {
		if int32(int16(v18)) < 4 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22[0])), 8)
			v8 = (*int32)(unsafe.Add(unsafe.Pointer(v2), 4*14))
			*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v2))), unsafe.Sizeof(float32(0))*14))) = float32(float64(v22[0]))
			*((*float32)(unsafe.Add(unsafe.Pointer((*float32)(unsafe.Pointer(v2))), unsafe.Sizeof(float32(0))*15))) = float32(float64(v22[1]))
		} else {
			v8 = (*int32)(unsafe.Add(unsafe.Pointer(v2), 4*14))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 56)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 60)), 4)
		}
		v9 = *(*int32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
		*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*16)) = *v8
		*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*17)) = v9
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 56)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 60)), 4)
	}
	*((*uint8)(unsafe.Pointer(&a1))) = uint8(sub_4F40A0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2))))))))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
	if int32(uint8(uintptr(unsafe.Pointer(a1)))) == 0 {
		return 1
	}
	v10 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4))
	v21 = int32(uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4))) & 0x11408162)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
	v11 = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4))) & 0xEEBF7E9D
	*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = int32(v11)
	v12 = v11
	if v10&0x40 != 0 {
		*((*uint8)(unsafe.Pointer(&v12))) = uint8(v11 | 0x40)
		*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = int32(v12)
	}
	v13 = v21
	*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) |= v21
	if nox_crypt_IsReadOnly() == 1 {
		if uint32(v13)&0x1000000 != 0 {
			nox_xxx_objectSetOn_4E75B0((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))))
		} else {
			nox_xxx_objectSetOff_4E7600((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))))
		}
	}
	if *v2 != 0 {
		*((*uint8)(unsafe.Pointer(&a2))) = uint8(int8(libc.StrLen((*byte)(unsafe.Pointer(uintptr(*v2))))))
	} else {
		*((*uint8)(unsafe.Pointer(&a2))) = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a2)), 1)
	if nox_crypt_IsReadOnly() != 1 || int32(uint8(int8(a2))) == 0 || (func() bool {
		result = int32(uintptr(alloc.Calloc(1, int(int32(uint8(int8(a2)))+1))))
		return (func() int32 {
			p := v2
			*v2 = result
			return *p
		}()) != 0
	}()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(*v2))), uint32(uint8(int8(a2))))
		if *v2 != 0 {
			*(*uint8)(unsafe.Pointer(uintptr(int32(uint8(int8(a2))) + *v2))) = 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(v2))), 52)), 1)
		v14 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*126))
		for *((*uint8)(unsafe.Pointer(&v19))) = 0; v14 != 0; *((*uint8)(unsafe.Pointer(&v19))) = uint8(int8(v19 + 1)) {
			v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(v14 + 496))))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19)), 1)
		if nox_crypt_IsReadOnly() == 1 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*34)) = int32(uint8(int8(v19)))
		}
		v15 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*129))
		for i = 0; v15 != 0; v15 = int32(*(*uint32)(unsafe.Pointer(uintptr(v15 + 512)))) {
			if (int32(*(*uint8)(unsafe.Pointer(uintptr(v15 + 16))))&0x20) == 0 && sub_4E3B80(int32(*(*uint16)(unsafe.Pointer(uintptr(v15 + 4))))) != 0 {
				i++
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&i)), 2)
		if nox_crypt_IsReadOnly() != 0 {
			for j = 0; j < uint32(uint16(int16(i))); j++ {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22[0])), 4)
				if !nox_common_gameFlags_check_40A5C0(0x200000) && !nox_common_gameFlags_check_40A5C0(0x400000) {
					sub_516F90(*v7, v22[0])
				}
			}
		} else {
			for k = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*129)); k != 0; k = int32(*(*uint32)(unsafe.Pointer(uintptr(k + 512)))) {
				if (int32(*(*uint8)(unsafe.Pointer(uintptr(k + 16))))&0x20) == 0 && sub_4E3B80(int32(*(*uint16)(unsafe.Pointer(uintptr(k + 4))))) != 0 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(k+44))), 4)
				}
			}
		}
		v21 = *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*5)) & 0x5E
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 4)
		nox_xxx_unitUnsetXStatus_4E4780((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), 94)
		nox_xxx_unitSetXStatus_4E4800((*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2)))))), int32(uintptr(unsafe.Pointer((*int32)(unsafe.Pointer(uintptr(v21)))))))
		if int32(int16(v18)) < 63 || (func() int32 {
			result = nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*int32)(unsafe.Add(unsafe.Pointer(v2), 4*191))))), (*byte)(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*189))))))
			return result
		}()) != 0 {
			if int32(int16(v18)) >= 64 {
				v22[0] = int32(uint32(v23) - gameFrame())
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22[0])), 4)
				if v22[0] > 0 && nox_crypt_IsReadOnly() == 1 {
					if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*4)))&0x400000 != 0 {
						*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*32)) = v22[0]
					}
				}
			}
			return 1
		}
	}
	return result
}
func nox_xxx_XFerSpellPagePedistal_4F4A20(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		result int32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	a1 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(int16(a1)))
	if result != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*(**uint8)(unsafe.Pointer(uintptr(v1 + 700))), 4)
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 136)))))
			return result
		}()) != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) = uint32(v2)
			result = 1
		}
	}
	return result
}
func nox_xxx_XFerReadable_4F4AB0(a1 int32) int32 {
	var (
		v1     *int32
		v2     int32
		v3     int32
		result int32
		v5     uint32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 736))))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	v5 = uint32(libc.StrLen(*(**byte)(unsafe.Pointer(uintptr(a1 + 736)))) + 1)
	a1 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		if int32(int16(a1)) >= 2 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2))), v5)
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2))), v5)
		}
		if nox_crypt_IsReadOnly() != 1 || (func() bool {
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 256))) = 0
			return *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0
		}()) || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v3
			result = 1
		}
	}
	return result
}
func nox_xxx_XFerExit_4F4B90(a1 int32) int32 {
	var (
		v1     *int32
		v2     *uint8
		v3     int32
		result int32
		i      *uint8
		v6     uint32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 700)))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	v6 = uint32(libc.StrLen(*(**byte)(unsafe.Pointer(uintptr(a1 + 700)))) + 1)
	a1 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		if int32(int16(a1)) >= 2 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, v6)
		} else if nox_crypt_IsReadOnly() == 1 {
			for i = v2; ; i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 1)) {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(i, 1)
				if int32(*i) == 0 {
					break
				}
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, v6)
		}
		if int32(int16(a1)) >= 31 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 80)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 84)), 4)
		}
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v3
			result = 1
		}
	}
	return result
}
func nox_xxx_XFerDoor_4F4CB0(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		result int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	v7 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 2)
	if int32(int16(v7)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(int16(v7)))
	if result != 0 {
		if nox_crypt_IsReadOnly() == 0 {
			a1 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))))
			v8 = int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 1))))
			v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 4))))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 4)
		if int32(int16(v7)) < 41 {
			v6 = a1
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 4)
		}
		if nox_crypt_IsReadOnly() == 1 {
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) = uint32(a1)
			*(*uint16)(unsafe.Pointer(uintptr(v2 + 40))) = uint16(int16((a1 << 8) / 32))
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 4))) = uint32(v6)
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 8))) = uint32(a1)
			v9 = *memmap.PtrInt32(0x587000, uintptr(v6*8)+196184) / 2
			v4 = int32(int64((float64(v9) + float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 56))))) * 0.043478262))
			v9 = *memmap.PtrInt32(0x587000, uintptr(v6*8)+196188) / 2
			v5 = int32(int64((float64(v9) + float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 60))))) * 0.043478262))
			nox_xxx_doorAttachWall_410360(v1, v4, v5)
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) = uint32(v4)
			*(*uint32)(unsafe.Pointer(uintptr(v2 + 20))) = uint32(v5)
			*(*uint8)(unsafe.Pointer(uintptr(v2 + 1))) = uint8(int8(v8))
		}
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(v7)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 136)))))
			return result
		}()) != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) = uint32(v10)
			result = 1
		}
	}
	return result
}
func nox_xxx_unitTriggerXfer_4F4E50(a1 float32) int32 {
	var (
		v1     int32
		v2     *uint8
		result int32
		v4     float64
		v5     float64
		v6     float64
		v7     *byte
		v8     *byte
		v9     *byte
		v10    *byte
		v11    int32
		v12    int32
		v13    int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)))
	v2 = *(**uint8)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 748)))
	v13 = int32(*(*uint32)(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0))) + 136))))
	v11 = 61
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 2)
	if int32(int16(v11)) > 61 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(int16(v11)))
	if result != 0 {
		if nox_crypt_IsReadOnly() != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 4)
			v5 = float64(*(*int32)(unsafe.Add(unsafe.Pointer((*int32)(unsafe.Pointer(&a1))), 4*0)))
			a1 = float32(v5)
			*(*float32)(unsafe.Pointer(uintptr(v1 + 184))) = float32(v5)
			v6 = float64(v12)
			*(*float32)(unsafe.Pointer(uintptr(v1 + 188))) = float32(v6)
			if float64(a1) > 60.0 {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 184))) = 1114636288
			}
			if v6 > 60.0 {
				*(*uint32)(unsafe.Pointer(uintptr(v1 + 188))) = 1114636288
			}
		} else {
			v4 = float64(*(*float32)(unsafe.Pointer(uintptr(v1 + 188))))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&a1))), 4*0)) = uint32(int32(int64(*(*float32)(unsafe.Pointer(uintptr(v1 + 184))))))
			v12 = int32(int64(v4))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 4)
		}
		nox_shape_box_calc((*nox_shape)(unsafe.Pointer(uintptr(v1 + 172))))
		if int32(int16(v11)) < 41 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 3)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 3)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 3)
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 54)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 55)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 56)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 57)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 58)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 59)), 1)
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, 4)
		if int32(int16(v11)) >= 3 {
			v7 = *(**byte)(unsafe.Pointer(uintptr(v1 + 756)))
			if v7 != nil {
				v8 = (*byte)(unsafe.Add(unsafe.Pointer(v7), 256))
			} else {
				v8 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v2), 20))))), v8)
			if v7 != nil {
				v9 = (*byte)(unsafe.Add(unsafe.Pointer(v7), 384))
			} else {
				v9 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v2), 28))))), v9)
			if int32(int16(v11)) >= 31 {
				if v7 != nil {
					v10 = (*byte)(unsafe.Add(unsafe.Pointer(v7), 512))
				} else {
					v10 = nil
				}
				nox_xxx_xferReadScriptHandler_4F5580(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v2), 12))))), v10)
			}
		} else {
			sub_4F5540(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v2), 20))))))
			sub_4F5540(int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v2), 28))))))
		}
		if nox_crypt_IsReadOnly() == 1 && int32(int16(v11)) < 31 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
			nox_xxx_cryptSeekCur_40E0A0(int32(*((*uint8)(unsafe.Pointer(&a1)))) * 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
			nox_xxx_cryptSeekCur_40E0A0(int32(*((*uint8)(unsafe.Pointer(&a1)))) * 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
			nox_xxx_cryptSeekCur_40E0A0(int32(*((*uint8)(unsafe.Pointer(&a1)))) * 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 1)
			nox_xxx_cryptSeekCur_40E0A0(int32(*((*uint8)(unsafe.Pointer(&a1)))) * 4)
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 44)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 48)), 4)
		if nox_crypt_IsReadOnly() == 1 {
			*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 52)) = 0
			*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 53)) = 0
		}
		if nox_crypt_IsReadOnly() == 0 || int32(int16(v11)) >= 21 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 52)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 53)), 1)
		}
		if int32(int16(v11)) >= 61 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 9)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v1+132))), 4)
			if nox_crypt_IsReadOnly() == 1 {
				nox_xxx_servMarkObjAnimFrame_4E4880(v1, int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 132)))))
			}
		}
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(v11)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 136)))))
			return result
		}()) != 0 {
			result = 1
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) = uint32(v13)
		}
	}
	return result
}
func nox_xxx_XFerHole_4F51D0(a1 int32) int32 {
	var (
		v1     *int32
		v2     int32
		v3     int32
		result int32
		v5     *byte
		v6     int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 756))))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 700))))
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	a1 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		if int32(int16(a1)) < 42 {
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 24))) = 0
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v3+24))), 4)
		}
		if int32(int16(a1)) < 41 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v3+8))), 8)
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 4))) = math.MaxUint32
			*(*uint32)(unsafe.Pointer(uintptr(v3))) = 0
			*(*uint32)(unsafe.Pointer(uintptr(v3 + 16))) = 0
			*(*uint16)(unsafe.Pointer(uintptr(v3 + 20))) = 0
		} else {
			if v2 != 0 {
				v5 = (*byte)(unsafe.Pointer(uintptr(v2 + 128)))
			} else {
				v5 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v3, v5)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v3+8))), 8)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v3+16))), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v3+20))), 2)
		}
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			result = 1
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v6
		}
	}
	return result
}
func nox_xxx_XFerTransporter_4F5300(a1 int32) int32 {
	var (
		v1     *int32
		v2     int32
		v3     int32
		result int32
		v5     int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	a1 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		if nox_crypt_IsReadOnly() != 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+16))), 4)
		} else {
			if *(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) != 0 {
				v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
			} else {
				v5 = 0
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
		}
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v3
			result = 1
		}
	}
	return result
}
func nox_xxx_XFerElevator_4F53D0(a1 int32) int32 {
	var (
		v1     *int32
		v2     *uint8
		v3     int32
		result int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 748)))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	a1 = 61
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 61 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)), 4)
		if int32(int16(a1)) >= 41 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 16)), 4)
		}
		if int32(int16(a1)) >= 61 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 12)), 1)
		}
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v3
			result = 1
		}
	}
	return result
}
func nox_xxx_XFerElevatorShaft_4F54A0(a1 int32) int32 {
	var (
		v1     *int32
		v2     int32
		v3     int32
		result int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	a1 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+8))), 4)
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v3
			result = 1
		}
	}
	return result
}
func sub_4F5540(a1 int32) int32 {
	var (
		result int32
		v2     *FILE
	)
	result = nox_crypt_IsReadOnly()
	if nox_crypt_IsReadOnly() == 1 {
		v2 = nox_xxx_mapgenGetSomeFile_426A60()
		nox_xxx_mapgenMakeScript_502790(v2, (*byte)(unsafe.Pointer(uintptr(a1))))
		result = bool2int32(nox_common_gameFlags_check_40A5C0(0x400000))
		if result == 0 {
			*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) = math.MaxUint32
		}
	}
	return result
}
func nox_xxx_XFerMover_4F5730(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		result int32
		v5     *int32
		v6     *int32
		v7     int32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 748))))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	v7 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 2)
	if int32(int16(v7)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(int16(v7)))
	if result != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+4))), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+8))), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+32))), 4)
		if int32(int16(v7)) >= 41 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2))), 1)
			if nox_crypt_IsReadOnly() != 0 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+16))), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+24))), 4)
			} else {
				v5 = *(**int32)(unsafe.Pointer(uintptr(v2 + 12)))
				a1 = 0
				if v5 != nil {
					a1 = *v5
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
				v6 = *(**int32)(unsafe.Pointer(uintptr(v2 + 20)))
				a1 = 0
				if v6 != nil {
					a1 = *v6
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 4)
			}
		}
		if int32(int16(v7)) >= 42 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v1+548))), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v1+544))), 4)
		}
		if *(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(v7)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 136)))))
			return result
		}()) != 0 {
			*(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) = uint32(v3)
			result = 1
		}
	}
	return result
}
func nox_xxx_XFerGlyph_4F5890(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		result int32
		v5     *uint8
		v6     int32
		v7     *int32
		v8     int32
		v9     *byte
		v10    uint32
		v11    int32
		v12    int32
		v13    *int32
		v14    int32
		v15    int32
		v16    [256]byte
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 692))))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	v13 = *(**int32)(unsafe.Pointer(uintptr(a1 + 692)))
	v14 = v3
	v12 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 2)
	if int32(int16(v12)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(uintptr(a1))), int32(int16(v12)))
	if result == 0 {
		return 0
	}
	if int32(int16(v12)) < 41 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 4)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(a1+124))), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+28))), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+32))), 4)
	v5 = (*uint8)(unsafe.Pointer(uintptr(v2 + 20)))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2+20))), 1)
	if nox_crypt_IsReadOnly() == 1 {
		if int32(int16(v12)) < 31 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(v2))), 0x14)
			goto LABEL_16
		}
		v6 = 0
		if int32(*v5) == 0 {
			v1 = a1
			v2 = int32(uintptr(unsafe.Pointer(v13)))
			goto LABEL_19
		}
		v7 = v13
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16[0])), uint32(uint8(int8(v11))))
			v16[uint8(int8(v11))] = 0
			*v7 = nox_xxx_spellNameToN_4243F0(&v16[0])
			v6++
			v7 = (*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1))
			if v6 >= int32(*v5) {
				break
			}
		}
	} else {
		v8 = 0
		if int32(*v5) == 0 {
			goto LABEL_16
		}
		for {
			*((*uint8)(unsafe.Pointer(&v11))) = uint8(int8(libc.StrLen(nox_xxx_spellNameByN_424870(int32(*(*uint32)(unsafe.Pointer(uintptr(v2))))))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
			v10 = uint32(uint8(int8(v11)))
			v9 = nox_xxx_spellNameByN_424870(int32(*(*uint32)(unsafe.Pointer(uintptr(v2)))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v9)), v10)
			v8++
			v2 += 4
			if v8 >= int32(*v5) {
				break
			}
		}
	}
	v1 = a1
	v2 = int32(uintptr(unsafe.Pointer(v13)))
LABEL_16:
	if nox_crypt_IsReadOnly() != 1 {
		goto LABEL_20
	}
LABEL_19:
	*(*uint16)(unsafe.Pointer(uintptr(v1 + 126))) = *(*uint16)(unsafe.Pointer(uintptr(v1 + 124)))
	*(*uint32)(unsafe.Pointer(uintptr(v2 + 24))) = 0
LABEL_20:
	if *(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = nox_xxx_xfer_4F3E30(uint16(int16(v12)), (*nox_object_t)(unsafe.Pointer(uintptr(v1))), int32(*(*uint32)(unsafe.Pointer(uintptr(v1 + 136)))))
		return result
	}()) != 0 {
		result = 1
		*(*uint32)(unsafe.Pointer(uintptr(v1 + 136))) = uint32(v14)
	}
	return result
}
func nox_xxx_XFerInvLight_4F5AA0(a1 *int32) int32 {
	var (
		result int32
		v2     *uint32
		v3     int32
		v4     int32
		v5     int32
		v6     [140]byte
	)
	v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34))
	*(*[140]byte)(unsafe.Pointer(&v6[0])) = [140]byte{}
	v3 = 60
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v3)), 2)
	if int32(int16(v3)) > 60 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(a1)), int32(int16(v3)))
	if result == 0 {
		return 0
	}
	if nox_crypt_IsReadOnly() != 0 {
		goto LABEL_14
	}
	if nox_common_gameFlags_check_40A5C0(6291456) {
		v2 = &sub_45A060().field_0
		if v2 == nil {
			goto LABEL_14
		}
		for *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*32)) != uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*10))) {
			v2 = &nox_drawable_next_45A070((*nox_drawable)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v2))))))).field_0
			if v2 == nil {
				goto LABEL_14
			}
		}
	} else if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))&0x20400000 != 0 {
		v2 = &nox_xxx_netSpriteByCodeStatic_45A720(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*10))).field_0
	} else {
		v2 = &nox_xxx_netSpriteByCodeDynamic_45A6F0(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*9))).field_0
	}
	if v2 == nil {
		panic("abort")
	}
	alloc.Memcpy(unsafe.Pointer(&v6[0]), unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*34))), 140)
LABEL_14:
	if int32(int16(v3)) >= 2 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[0])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[4])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[8])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[12])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[16])), 0xC)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[28])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[30])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[32])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[40])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[42])), 0x30)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[90])), 0x10)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[106])), 0x10)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[122])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[124])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[126])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[128])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[134])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[136])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[138])), 1)
		if int32(int16(v3)) > 40 {
			if int32(int16(v3)) >= 42 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[36])), 4)
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v4)), 1)
				*(*uint32)(unsafe.Pointer(&v6[36])) = uint32(uint8(int8(v4)))
			}
			if nox_crypt_IsReadOnly() == 1 {
				goto LABEL_20
			}
			goto LABEL_22
		}
		if nox_crypt_IsReadOnly() != 1 {
			goto LABEL_22
		}
		*(*uint32)(unsafe.Pointer(&v6[36])) = 0
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[0])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[4])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[8])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[12])), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[16])), 0xC)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[28])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[30])), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6[32])), 4)
		*(*uint16)(unsafe.Pointer(&v6[40])) = 0
		*(*uint16)(unsafe.Pointer(&v6[122])) = 0
		*(*uint16)(unsafe.Pointer(&v6[124])) = 0
		*(*uint16)(unsafe.Pointer(&v6[126])) = 0
		*(*uint32)(unsafe.Pointer(&v6[128])) = 0
		*(*uint16)(unsafe.Pointer(&v6[134])) = 0
		v6[138] = 128
		if nox_crypt_IsReadOnly() != 1 {
			goto LABEL_22
		}
		if float64(*(*float32)(unsafe.Pointer(&v6[4]))) > 63.0 || float64(*(*int32)(unsafe.Pointer(&v6[12])))**mem_getDoublePtr(0x581450, 9752) > *mem_getDoublePtr(0x581450, 9744) {
			sub_484CE0(int32(uintptr(unsafe.Pointer(&v6[0]))), 63.0)
			if nox_crypt_IsReadOnly() == 1 {
				goto LABEL_20
			}
			goto LABEL_22
		}
	}
LABEL_20:
	if nox_common_gameFlags_check_40A5C0(6291456) {
		alloc.Memcpy(unsafe.Pointer(uintptr(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*189))+2432)), unsafe.Pointer(&v6[0]), 0x8C)
	}
LABEL_22:
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = nox_xxx_xfer_4F3E30(uint16(int16(v3)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(a1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34)))
		return result
	}()) != 0 {
		*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*34)) = v5
		result = 1
	}
	return result
}
func nox_xxx_XFerSentry_4F5E50(a1 int32) int32 {
	var (
		v1     *int32
		v2     *uint8
		v3     int32
		result int32
	)
	v1 = (*int32)(unsafe.Pointer(uintptr(a1)))
	v2 = *(**uint8)(unsafe.Pointer(uintptr(a1 + 748)))
	v3 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 136))))
	a1 = 61
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&a1)), 2)
	if int32(int16(a1)) > 61 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*nox_object_t)(unsafe.Pointer(v1)), int32(int16(a1)))
	if result != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 4)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(v2), 8)), 4)
		if nox_crypt_IsReadOnly() == 1 || nox_common_gameFlags_check_40A5C0(0x200000) {
			*(*uint32)(unsafe.Pointer(v2)) = *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v2))), 4*1)))
		}
		if int32(int16(a1)) >= 61 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, 4)
		}
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
			result = nox_xxx_xfer_4F3E30(uint16(int16(a1)), (*nox_object_t)(unsafe.Pointer(uintptr(int32(uintptr(unsafe.Pointer(v1)))))), *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)))
			return result
		}()) != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*34)) = v3
			result = 1
		}
	}
	return result
}
