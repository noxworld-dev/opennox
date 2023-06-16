package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_xxx_resetMapInit_1569652 uint32 = 0
var nox_server_xxx_1599716 [65536]nox_server_xxx = [65536]nox_server_xxx{}

func nullsub_25(a1 uint32) {
}
func sub_426060() {
	var (
		v0     *byte
		i      *byte
		v2     *byte
		j      *byte
		result unsafe.Pointer
		v5     *byte
		v6     *byte
		v7     int32
	)
	dword_5d4594_608316 = 0
	dword_5d4594_600116 = libc.GetTime(nil)
	v7 = int32(sub_5545A0())
	v0 = sub_554230()
	sub_4282D0(v0, v7)
	if !noxflags.HasGame(0x2000) || noxflags.HasGame(4096) {
		result = unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(4096))))
		if result != nil {
			result = unsafe.Pointer(uintptr(bool2int32(noxflags.HasGame(4096))))
			if result != nil {
				v5 = (*byte)(sub_416640())
				v6 = nox_xxx_cliGamedataGet_416590(0)
				*memmap.PtrUint16(0x5D4594, 739396) = uint16(int16(sub_40A770()))
				*memmap.PtrUint32(0x5D4594, 739400) = *((*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*10)))
				*memmap.PtrUint32(0x5D4594, 739404) = uint32(sub_4200E0())
				*memmap.PtrUint8(0x5D4594, 739412) = uint8(int8(bool2int32((*(*byte)(unsafe.Add(unsafe.Pointer(v6), 53)) & 0xC0) != 0)))
				*memmap.PtrUint32(0x5D4594, 739408) = 5
				libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 739676)), (*byte)(unsafe.Add(unsafe.Pointer(v6), 9)), 0xF)
				*memmap.PtrUint8(0x5D4594, 739691) = 0
				libc.StrNCpy((*byte)(memmap.PtrOff(0x5D4594, 739420)), v6, 8)
				*memmap.PtrUint8(0x5D4594, 739428) = 0
				sub_4289D0((*unsafe.Pointer)(memmap.PtrOff(0x5D4594, 739396)))
			}
		}
	} else {
		for i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); i != nil; i = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(i))))) {
			*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1162))) = math.MaxUint32
		}
		v2 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
		if v2 != nil {
			sub_425F10((*server.Player)(unsafe.Pointer(v2)))
		}
		for j = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); j != nil; j = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(j))))) {
			if *(*byte)(unsafe.Add(unsafe.Pointer(j), 2064)) != 31 {
				sub_425F10((*server.Player)(unsafe.Pointer(j)))
			}
		}
		sub_426150()
		sub_428810(int32(uintptr(memmap.PtrOff(0x5D4594, 599476))), 0)
		*memmap.PtrUint16(0x5D4594, 599482) = 0
	}
}
func nox_xxx_getSomeMapName_4D0CF0() *byte {
	var (
		v0 int32
		v1 int32
		v2 int32
		v4 int32
	)
	v0 = int32(nox_common_gameFlags_getVal_40A5B0())
	v1 = sub_4D0D50(v0)
	v2 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v1*4)+1548428))
	if v2 == 0 {
		return nil
	}
	v4 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v1*4)+1548452))
	if v4 > v2 {
		*memmap.PtrUint32(0x5D4594, uintptr(v1*4)+1548452) = 0
		v4 = 0
	}
	*memmap.PtrUint32(0x5D4594, uintptr(v1*4)+1548452) = (*memmap.PtrUint32(0x5D4594, uintptr(v1*4)+1548452) + 1) % uint32(v2)
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr((v4+v1*20+v1*5)*128)+1529228))
}
func sub_4D10F0(a1 *byte) {
	var (
		v1 int32
		i  *byte
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 *uint8
	)
	if a1 != nil {
		v1 = 0
		if dword_5d4594_1548476 > 0 {
			for i = (*byte)(memmap.PtrOff(0x5D4594, 1525136)); nox_strcmpi(i, a1) != 0; i = (*byte)(unsafe.Add(unsafe.Pointer(i), 32)) {
				if func() int32 {
					p := &v1
					*p++
					return *p
				}() >= dword_5d4594_1548476 {
					return
				}
			}
			v3 = int32(dword_5d4594_1548476)
			v4 = v1 * 32
			v5 = int32(dword_5d4594_1548480)
			*memmap.PtrUint32(0x587000, 191880) = uint32(v1)
			*memmap.PtrUint32(0x5D4594, uintptr(v4)+1525156) = *memmap.PtrUint32(0x5D4594, uintptr(v1*32)+1525156) + 1
			v6 = 0
			*memmap.PtrUint32(0x5D4594, uintptr(v4)+1525160) = uint32(v5)
			if v3 > 0 {
				v7 = (*uint8)(memmap.PtrOff(0x5D4594, 1525156))
				for {
					if *((*uint32)(unsafe.Add(unsafe.Pointer(v7), -int(4*6)))) == *memmap.PtrUint32(0x5D4594, uintptr(v1*32)+1525132) && v1 != v6 {
						*(*uint32)(unsafe.Pointer(v7))++
						*((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*1))) = uint32(v5)
					}
					v6++
					v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 32))
					if v6 >= v3 {
						break
					}
				}
			}
			dword_5d4594_1548480 = uint32(v5 + 1)
		}
	}
}
func sub_4D2160() {
	var (
		result *byte
		i      *byte
		v2     int32
		j      *byte
		v4     int32
		v5     int32
	)
	v5 = nox_common_playerInfoCount_416F40()
	result = (*byte)(unsafe.Pointer(nox_server_teamFirst_418B10()))
	for i = result; result != nil; i = result {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*19))))), 492)) == 0 && sub_418BC0(int32(uintptr(unsafe.Pointer(i)))) != 0 {
			for {
				v2 = nox_common_randomInt_415FA0(0, v5-1)
				for j = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); j != nil; j = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(j))))) {
					if v2 == 0 {
						break
					}
					v2--
				}
				v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(j), 4*514))))
				if v4 != 0 && nox_xxx_teamCompare2_419180(unsafe.Add(v4, 48), *(*byte)(unsafe.Add(unsafe.Pointer(i), 57))) != 0 {
					break
				}
			}
			sub_4F3400(AsObjectP(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(j), 4*514)))), AsObjectP(*((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*19)))), 1, 0)
		}
		result = (*byte)(unsafe.Pointer(nox_server_teamNext_418B60((*server.Team)(unsafe.Pointer(i)))))
	}
}
func sub_4D2230() {
	var (
		v0 int16
		v1 int16
		v2 int16
	)
	if noxflags.HasGame(49152) {
		v0 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
		if int32(nox_xxx_servGamedataGet_40A020(v0)) == 0 {
			v1 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
			if int32(sub_40A180(v1)) == 0 {
				v2 = int16(uint16(nox_common_gameFlags_getVal_40A5B0()))
				sub_409FB0_settings(v2, 0xF)
			}
		}
	} else if noxflags.HasGame(1024) && int32(nox_xxx_servGamedataGet_40A020(1024)) == 0 {
		sub_409FB0_settings(1024, 0xF)
	}
}
func sub_4D22B0() {
	var (
		result *byte
		i      int32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	for i = int32(uintptr(unsafe.Pointer(result))); result != nil; i = int32(uintptr(unsafe.Pointer(result))) {
		v2 = int32(*(*uint32)(unsafe.Add(i, 2056)))
		if v2 != 0 {
			v3 = int32(*(*uint32)(unsafe.Add(v2, 748)))
			if *(*uint32)(unsafe.Add(v3, 280)) != 0 {
				nox_xxx_shopCancelSession_510DC0(*(**uint32)(unsafe.Add(v3, 280)))
			}
			*(*uint32)(unsafe.Add(v3, 280)) = 0
			nox_xxx_playerResetControlBuffer_51AC30(int32(*(*uint8)(unsafe.Add(i, 2064))))
			if noxflags.HasGame(4096) {
				v4 = int32(*(*uint32)(unsafe.Add(i, 4676)))
				*(*uint32)(unsafe.Add(i, 4676)) = 0
				*(*uint32)(unsafe.Add(i, 4680)) = uint32(v4)
			}
			if nox_xxx_playerSetState_4FA020((*server.Object)(unsafe.Pointer(*(**uint32)(unsafe.Add(i, 2056)))), 13) == 0 || !noxflags.HasGame(512) {
				*(*uint32)(unsafe.Add(i, 4700)) = 0
				v6 = int32((uint32(sub_4CFE00()) >> 1) & 1)
				v5 = nox_xxx_gameIsSwitchToSolo_4DB240()
				nox_xxx_playerMakeDefItems_4EF7D0(*(*unsafe.Pointer)(unsafe.Add(i, 2056)), bool2int32(v5 == 0), v6)
			}
			if int32(*(*uint8)(unsafe.Add(i, 3680)))&0x20 != 0 {
				nox_xxx_playerLeaveObserver_0_4E6AA0((*server.Player)(i))
				nox_xxx_playerCameraUnlock_4E6040((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(i, 2056))))
			}
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 2056)), 136)) = gameFrame()
		}
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(i))))
	}
}
func sub_4DBA30(a1 int32) {
	var (
		result *byte
		v2     *byte
		v3     unsafe.Pointer
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     *int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    *int32
		v15    int32
		v17    int32
		v23    int32
		v24    *byte
		v25    int32
		v26    int32
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
	v2 = result
	v3 = nil
	v24 = result
	if result != nil {
		v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*514))))
		v25 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*514))))
		if v4 != 0 {
			if *memmap.PtrUint32(0x5D4594, 1563128) == 0 {
				*memmap.PtrUint32(0x5D4594, 1563128) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SaveGameLocation")))
				*memmap.PtrUint32(0x5D4594, 1563132) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
			}
			if a1 == 1 {
				v5 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
				if v5 != 0 {
					for {
						v26 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v5)))))
						if uint32(*(*uint16)(unsafe.Add(v5, 4))) == *memmap.PtrUint32(0x5D4594, 1563128) {
							nox_xxx_unitMove_4E7010((*server.Object)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*514)))))), (*types.Pointf)(unsafe.Add(v5, 56)))
							*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*514))))), 44)) = *(*uint32)(unsafe.Add(v5, 44))
							*(*uint32)(unsafe.Add(v5, 44)) = 0
							nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v5))
						} else {
							v6 = int32(*(*uint32)(unsafe.Add(v5, 8)))
							if v6&2 != 0 {
								v7 = int32(*(*uint32)(unsafe.Add(v5, 748)))
								v8 = 0
								if int32(*(*uint8)(unsafe.Add(v7, 1129))) != 0 {
									v9 = (*int32)(unsafe.Add(v7, 1132))
									for {
										v10 = sub_4ECF10(*v9)
										*v9 = v10
										if v10 == 0 {
											*(*uint8)(unsafe.Add(v7, 1129)) = 0
										}
										v8++
										v9 = (*int32)(unsafe.Add(unsafe.Pointer(v9), 4*1))
										if v8 >= int32(*(*uint8)(unsafe.Add(v7, 1129))) {
											break
										}
									}
									v3 = nil
								}
								*(*uint32)(unsafe.Add(v7, 1196)) = uint32(sub_4ECF10(int32(*(*uint32)(unsafe.Add(v7, 1196)))))
								if int32(*(*uint32)(unsafe.Add(v5, 16))) >= 0 {
									sub_52BAF0(v5)
								}
								v11 = sub_4ECF10(int32(*(*uint32)(unsafe.Add(v7, 392))))
								if v11 != 0 {
									*(*uint32)(unsafe.Add(v7, 392)) = *(*uint32)(unsafe.Add(v11, 36))
								} else {
									*(*uint32)(unsafe.Add(v7, 392)) = 0
								}
								v12 = sub_4ECF10(int32(*(*uint32)(unsafe.Add(v7, 1200))))
								if v12 != 0 {
									*(*uint32)(unsafe.Add(v7, 1200)) = *(*uint32)(unsafe.Add(v12, 36))
								} else {
									*(*uint32)(unsafe.Add(v7, 1200)) = 0
								}
								*(*uint32)(unsafe.Add(v7, 1216)) = uint32(sub_4ECF10(int32(*(*uint32)(unsafe.Add(v7, 1216)))))
								v13 = 0
								if int32(*(*uint8)(unsafe.Add(v7, 2172))) != 0 {
									v14 = (*int32)(unsafe.Add(v7, 2140))
									for {
										v15 = sub_4ECF10(*v14)
										if v15 != 0 {
											*v14 = int32(*(*uint32)(unsafe.Add(v15, 36)))
										} else {
											*(*uint8)(unsafe.Add(v7, 2172)) = 0
										}
										v13++
										v14 = (*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1))
										if v13 >= int32(*(*uint8)(unsafe.Add(v7, 2172))) {
											break
										}
									}
								}
								v2 = v24
							} else if v6&0x4000 != 0 {
								if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 748)), 16)) != 0 {
									nox_xxx_unitNeedSync_4E44F0((*server.Object)(v5))
								}
							} else if (v6 & 0x8000) == 0 {
								if (v6&0x80) != 0 && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 748)), 12)) != *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 748)), 4)) {
									nox_xxx_unitAddToUpdatable_4DA8D0((*server.Object)(v5))
								}
							} else {
								v23 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 748)), 4)))
								if v23 != 0 && *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v23, 748)), 16)) != 0 {
									nox_xxx_unitNeedSync_4E44F0((*server.Object)(v5))
								}
							}
						}
						v5 = v26
						if v26 == 0 {
							break
						}
					}
				}
				nox_script_activatorResolveObjs_51B0C0()
				sub_516FC0()
				if dword_5d4594_1563096 != 0 {
					v16 := unsafe.Pointer(nox_server_getFirstObject_4DA790())
					if v16 != nil {
						for {
							v3 = unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v16)))
							if int32(*(*uint32)(unsafe.Add(v16, 16))) >= 0 && nox_xxx_isUnit_4E5B50((*server.Object)(v16)) != 0 {
								if int32(*(*uint8)(unsafe.Add(v16, 8)))&2 != 0 {
									v17 = int32(*(*uint32)(unsafe.Add(v16, 12)))
									if v17&0x2000 != 0 {
										v18 := nox_xxx_inventoryGetFirst_4E7980(v16)
										if v18 != nil {
											for {
												v19 := nox_xxx_inventoryGetNext_4E7990(v18)
												if uint32(*(*uint16)(unsafe.Add(v18, 4))) == *memmap.PtrUint32(0x5D4594, 1563132) {
													nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v18))
												}
												v18 = v19
												if v19 == nil {
													break
												}
											}
										}
									}
								}
								nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v16))
							}
							v16 = v3
							if v3 == nil {
								break
							}
						}
					}
					var obj *server.Object = nox_xxx_getFirstUpdatable2Object_4DA840()
					if unsafe.Pointer(obj) != v3 {
						for {
							{
								var v21 *server.Object = nox_xxx_getNextUpdatable2Object_4DA850(obj)
								if int32(obj.ObjFlags) >= 0 {
									if sub_4E5B80(obj) != 0 {
										nox_xxx_delayedDeleteObject_4E5CC0(obj)
									}
								}
								obj = v21
							}
							if unsafe.Pointer(obj) == v3 {
								break
							}
						}
					}
					v2 = v24
				}
				v4 = v25
			}
			for i := *(*unsafe.Pointer)(unsafe.Add(v4, 516)); i != v3; i = *(*unsafe.Pointer)(unsafe.Add(i, 512)) {
				if int32(*(*uint8)(unsafe.Add(i, 8)))&2 != 0 {
					if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 1440)))&0x80 != 0 {
						nox_xxx_netReportAcquireCreature_4D91A0(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v2), 2064))), (*server.Object)(i))
						nox_xxx_netMarkMinimapObject_417190(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v2), 2064))), (*server.Object)(i), 1)
						continue
					}
					if (int32(*(*uint8)(unsafe.Add(i, 12))) & 0x80) != 0 {
						nox_xxx_netMonitorCreature_4D9250(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v2), 2064))), i)
						nox_xxx_netMarkMinimapObject_417190(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v2), 2064))), (*server.Object)(i), 1)
						continue
					}
				}
			}
			nox_xxx_gameSetSwitchSolo_4DB220(v3 != nil)
			dword_5d4594_1563096 = uint32(bool2int(v3 != nil))
			nox_ticks_reset_416D40()
		}
	}
}
func nox_xxx_mapLoadRequired_4DCC80() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 1563072))
}
func sub_4E4170() {
	var v0 float32
	if (gameFrame() % (gameFPS() * 5)) == 0 {
		v0 = float32(sub_4E3CA0())
		sub_4E3D50()
		if sub_4E3CA0() != float64(v0) {
			sub_4E3DD0()
		}
	}
}
func sub_4E76C0() int32 {
	var v0 int32
	_ = v0
	var result int32
	var i int32
	v0 = 0
	result = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	for i = result; result != 0; i = result {
		nullsub_25(uint32(i))
		v0 ^= sub_4E7700(i)
		result = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(i)))))
	}
	return result
}
func sub_4EC720() {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 *uint32
		v6 int32
		v7 int16
		v8 *uint8
	)
	_ = v8
	var v9 int32
	var v10 int32
	var v11 float64
	var v12 float64
	var v13 int32
	var v14 int32
	var v15 *uint8
	_ = v15
	var v16 int32
	var v17 int32
	var v18 int32
	if dword_5d4594_1568028 == 0 {
		dword_5d4594_1568028 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Crown")))
	}
	if noxflags.HasGame(4608) {
		return
	}
	nox_xxx_respawnAllow_587000_205200 = 0
	for v0 := int32(dword_5d4594_1568024); v0 != 0; v0 = int32(*(*uint32)(unsafe.Add(v0, 52))) {
		if *(*uint32)(unsafe.Add(v0, 24)) == 0 {
			v1 = int32(*(*uint32)(unsafe.Add(v0, 4)))
			v2 = 0
			if v1 == 0 {
				*(*uint32)(unsafe.Add(v0, 24)) = 1
				*(*uint32)(unsafe.Add(v0, 20)) = gameFrame() + gameFPS()*30
			} else {
				v3 = int32(*(*uint32)(unsafe.Add(v1, 8)))
				if v3&2 != 0 {
					v4 = int32(*(*uint32)(unsafe.Add(v1, 16)))
					if v4&0x20 != 0 {
						*(*uint32)(unsafe.Add(v0, 4)) = 0
						*(*uint32)(unsafe.Add(v0, 24)) = 1
						*(*uint32)(unsafe.Add(v0, 20)) = gameFrame() + gameFPS()*30
					} else if (v4 & 0x8000) != 0 {
						*(*uint32)(unsafe.Add(v0, 24)) = 1
						*(*uint32)(unsafe.Add(v0, 20)) = gameFrame() + gameFPS()*30
					}
				} else if int32(*(*uint8)(unsafe.Add(v1, 16)))&0x20 != 0 {
					if nox_xxx_getUnitDefDd10_4E3BA0(int32(*(*uint16)(unsafe.Add(v1, 4)))) != 0 {
						v2 = 1
					}
					*(*uint32)(unsafe.Add(v0, 4)) = 0
					if v2 != 0 {
						*(*uint32)(unsafe.Add(v0, 24)) = 1
						*(*uint32)(unsafe.Add(v0, 20)) = gameFrame() + gameFPS()*30
					}
				} else if uint32(v3)&0x3001000 != 0 || uint32(*(*uint16)(unsafe.Add(v1, 4))) == dword_5d4594_1568028 {
					if *(*uint32)(unsafe.Add(v1, 492)) != 0 || nox_xxx_getUnitDefDd10_4E3BA0(int32(*(*uint16)(unsafe.Add(v1, 4)))) == 0 {
						v18 = int32(*(*uint32)(unsafe.Add(v0, 4)))
						if *(*uint32)(unsafe.Add(v18, 492)) != 0 && nox_xxx_getUnitDefDd10_4E3BA0(int32(*(*uint16)(unsafe.Add(v18, 4)))) != 0 && uint32(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v0, 4)), 4))) != dword_5d4594_1568028 && sub_409F40(2) != 0 {
							*(*uint32)(unsafe.Add(v0, 24)) = 1
							*(*uint32)(unsafe.Add(v0, 20)) = gameFrame() + gameFPS()*30
						}
					} else {
						v10 = int32(*(*uint32)(unsafe.Add(v0, 4)))
						if gameFrame() > (gameFPS()*5 + *(*uint32)(unsafe.Add(v10, 128))) {
							v11 = float64(*(*float32)(unsafe.Add(v0, 8)) - *(*float32)(unsafe.Add(v10, 56)))
							v12 = float64(*(*float32)(unsafe.Add(v0, 12)) - *(*float32)(unsafe.Add(v10, 60)))
							if v12*v12+v11*v11 > 2500.0 {
								nox_xxx_netSendPointFx_522FF0(-127, (*types.Pointf)(unsafe.Add(v10, 56)))
								nox_xxx_audCreate_501A30(283, (*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v0, 4)), 56)), 0, 0)
								nox_xxx_unitMove_4E7010((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v0, 4))), (*types.Pointf)(unsafe.Add(v0, 8)))
								v13 = int32(*(*uint32)(unsafe.Add(v0, 4)))
								v14 = int32(*(*uint32)(unsafe.Add(v13, 8)))
								if v14&0x1000 != 0 {
									nox_xxx_rechargeItem_53C520(v13, 100)
								} else if uint32(v14)&0x1000000 != 0 && nox_xxx_weaponInventoryEquipFlags_415820((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v0, 4))))&0x82 != 0 {
									v15 = *(**uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v0, 4)), 736))
									*(*uint8)(unsafe.Add(unsafe.Pointer(v15), 1)) = *(*uint8)(unsafe.Add(v0, 48))
									*v15 = *(*uint8)(unsafe.Add(v0, 49))
								}
								v16 = int32(*(*uint32)(unsafe.Add(v0, 4)))
								v17 = int32(*(*uint32)(unsafe.Add(v16, 556)))
								if v17 != 0 {
									nox_xxx_unitSetHP_4E4560((*server.Object)(v16), *(*uint16)(unsafe.Add(v17, 4)))
								}
								nox_xxx_netSendPointFx_522FF0(-127, (*types.Pointf)(unsafe.Add(v0, 8)))
								nox_xxx_audCreate_501A30(283, (*types.Pointf)(unsafe.Add(v0, 8)), 0, 0)
							}
						}
					}
				} else if *(*uint32)(unsafe.Add(v1, 492)) != 0 {
					*(*uint32)(unsafe.Add(v0, 24)) = 1
					*(*uint32)(unsafe.Add(v0, 20)) = gameFrame() + gameFPS()*30
				}
			}
			if *(*uint32)(unsafe.Add(v0, 24)) == 0 {
				continue
			}
		}
		if gameFrame() < uint32(*(*int32)(unsafe.Add(v0, 20))) || nox_xxx_getUnitDefDd10_4E3BA0(int32(*(*uint32)(v0))) == 0 {
			continue
		}
		v5 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*(*uint32)(v0)))))
		v6 = int32(uintptr(unsafe.Pointer(v5)))
		if v5 != nil {
			nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v5)), nil, *(*float32)(unsafe.Add(v0, 8)), *(*float32)(unsafe.Add(v0, 12)))
			nox_xxx_netSendPointFx_522FF0(-127, (*types.Pointf)(unsafe.Add(v0, 8)))
			v7 = int16(*(*uint16)(unsafe.Add(v0, 16)))
			*(*uint16)(unsafe.Add(v6, 124)) = uint16(v7)
			*(*uint16)(unsafe.Add(v6, 126)) = uint16(v7)
			if *(*uint32)(unsafe.Add(v6, 8))&0x13001000 != 0 {
				nox_xxx_modifSetItemAttrs_4E4990((*server.Object)(v6), (*int32)(unsafe.Add(v0, 28)))
			}
			if *(*uint32)(unsafe.Add(v6, 8))&0x1000000 != 0 && nox_xxx_weaponInventoryEquipFlags_415820((*server.Object)(v6))&0x82 != 0 {
				v8 = *(**uint8)(unsafe.Add(v6, 736))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 1)) = *(*uint8)(unsafe.Add(v0, 48))
				*v8 = *(*uint8)(unsafe.Add(v0, 49))
			}
			nox_xxx_aud_501960(283, (*server.Object)(v6), 0, 0)
		}
		v9 = int32(*(*uint32)(unsafe.Add(v0, 4)))
		if v9 != 0 {
			if int32(*(*uint8)(unsafe.Add(v9, 8)))&2 != 0 {
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v0, 4))))
			}
		}
		*(*uint32)(unsafe.Add(v0, 24)) = 0
		*(*uint32)(unsafe.Add(v0, 4)) = uint32(v6)
	}
}
func sub_4EDD70() int32 {
	var (
		result int32
		i      int32
		v2     *uint32
		v3     *uint32
		a3     types.Pointf
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		v2 = *(**uint32)(unsafe.Add(i, 504))
		if v2 != nil {
			for {
				v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*124)))
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2))&0x10000000 != 0 {
					sub_4ED970(50.0, (*types.Pointf)(unsafe.Add(i, 56)), &a3)
					nox_xxx_drop_4ED790((*server.Object)(i), (*server.Object)(unsafe.Pointer(v2)), &a3)
				}
				v2 = v3
				if v3 == nil {
					break
				}
			}
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)))))
	}
	return result
}
func sub_4EF660(a1p *server.Object) {
	var (
		a1 = unsafe.Pointer(a1p)
		v1 int32
		i  int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	*(*uint32)(unsafe.Add(v1, 116)) = 0
	*(*uint32)(unsafe.Add(v1, 120)) = 0
	*(*uint32)(unsafe.Add(v1, 124)) = 0
	*(*uint32)(unsafe.Add(v1, 128)) = 0
	*(*uint32)(unsafe.Add(v1, 308)) = 0
	for i = 4796; i < 4816; *(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(v1, 276)) + uint32(i) - 4))) = 0 {
		i += 4
	}
	if !noxflags.HasGame(2048) {
		*(*uint8)(unsafe.Add(v1, 244)) = uint8(int8(sub_4EF6F0(a1)))
	}
	*(*uint32)(unsafe.Add(v1, 264)) = 0
	*(*uint32)(unsafe.Add(a1, 520)) = 0
	sub_422140(int32(*(*uint32)(unsafe.Add(v1, 276))))
}
func sub_4F1F20() {
	var (
		v1 int32
		v4 int32
		v5 *uint32
		v6 *uint32
		v7 *uint32
		v8 *uint32
		v9 int32
		a3 types.Pointf
	)
	v9 = nox_game_getQuestStage_4E3CC0()
	if dword_5d4594_1568300 == 0 {
		dword_5d4594_1568300 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RewardMarker")))
		*memmap.PtrUint32(0x5D4594, 1568304) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("RewardMarkerPlus")))
	}
	sub_4F2110()
	sub_4F2210()
	v0 := unsafe.Pointer(nox_server_getFirstObject_4DA790())
	if v0 != nil {
		for {
			v10 := unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v0)))
			v1 = int32(*(*uint16)(unsafe.Add(v0, 4)))
			if uint32(uint16(int16(v1))) == dword_5d4594_1568300 || uint32(v1) == *memmap.PtrUint32(0x5D4594, 1568304) {
				if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v0, 692)), 216)))&0x80 != 0 {
					v7 = nox_server_rewardgen_activateMarker_4F0720(v0, uint32(v9))
					if v7 != nil {
						nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v7)), nil, *(*float32)(unsafe.Add(v0, 56)), *(*float32)(unsafe.Add(v0, 60)))
						if *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*2))&0x1000000 != 0 {
							if *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*3))&0xC != 0 {
								v8 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("Quiver"))))
								if v8 != nil {
									a3 = *((*types.Pointf)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(types.Pointf{})*7)))
									sub_4ED970(30.0, (*types.Pointf)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(types.Pointf{})*7)), &a3)
									nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v8)), nil, a3.X, a3.Y)
								}
							}
						}
					}
				}
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v0))
			} else if *(*unsafe.Pointer)(unsafe.Add(v0, 688)) == ccall.FuncAddr(nox_xxx_initChest_4F0400) {
				v2 := nox_xxx_inventoryGetFirst_4E7980(v0)
				if v2 != nil {
					for {
						v3 := nox_xxx_inventoryGetNext_4E7990(v2)
						v4 = int32(*(*uint16)(unsafe.Add(v2, 4)))
						if uint32(uint16(int16(v4))) == dword_5d4594_1568300 || uint32(v4) == *memmap.PtrUint32(0x5D4594, 1568304) {
							v5 = nox_server_rewardgen_activateMarker_4F0720(v2, uint32(v9+1))
							sub_4ED0C0((*server.Object)(v0), (*server.Object)(v2))
							nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v2))
							if v5 != nil {
								nox_xxx_inventoryPutImpl_4F3070((*server.Object)(v0), (*server.Object)(unsafe.Pointer(v5)), 0)
								if *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2))&0x1000000 != 0 {
									if *(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*3))&0xC != 0 {
										v6 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("Quiver"))))
										if v6 != nil {
											nox_xxx_inventoryPutImpl_4F3070((*server.Object)(v0), (*server.Object)(unsafe.Pointer(v6)), 0)
										}
									}
								}
							}
						}
						v2 = v3
						if v3 == nil {
							break
						}
					}
				}
			}
			v0 = v10
			if v10 == nil {
				break
			}
		}
	}
}
func nox_xxx_playerSomeWallsUpdate_5003B0(obj *server.Object) int32 {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(obj)))
		v1     int32
		result int32
		v3     int32
		v4     *uint8
		v5     *uint8
	)
	if dword_5d4594_1569756 <= 0 {
		v1 = a1
	} else {
		v1 = int32(uintptr(nox_xxx_spellCastedFirst_4FE930()))
		if v1 == 0 {
			return 0
		}
		for *(*uint32)(unsafe.Add(v1, 4)) != 132 || *(*uint32)(unsafe.Add(v1, 16)) != uint32(a1) || int32(*(*uint8)(unsafe.Add(v1, 88)))&1 != 0 {
			result = int32(uintptr(nox_xxx_spellCastedNext_4FE940(v1)))
			v1 = result
			if result == 0 {
				return result
			}
		}
		if v1 == 0 {
			return 0
		}
		*(*uint32)(unsafe.Add(v1, 92)) = uint32(uintptr(ccall.FuncAddr(Nox_xxx_spellWallCreate_4FFA90)))
		*(*uint32)(unsafe.Add(v1, 96)) = uint32(uintptr(ccall.FuncAddr(Nox_xxx_spellWallUpdate_500070)))
		*(*uint32)(unsafe.Add(v1, 100)) = uint32(uintptr(ccall.FuncAddr(Nox_xxx_spellWallDestroy_500080)))
		*(*uint32)(unsafe.Add(v1, 48)) = 0
	}
	v3 = 0
	if dword_5d4594_1569756 > 0 {
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, 1569764))
		for {
			v5 = (*uint8)(nox_server_getWallAtGrid_410580(int32(*v4), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 1)))))
			if v5 != nil {
				*v5 = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 13))
			} else {
				v5 = (*uint8)(nox_xxx_wallCreateAt_410250(int32(*v4), int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 1)))))
				if v5 == nil {
					return 0
				}
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 4)) |= 8
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 11))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 2)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 12))
				*v5 = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 13))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 7)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v4), 14))
			}
			nox_xxx_netWallCreate_4FFE80(v1, v5, int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 8))), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 9))), int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v4), 10))))
			v3++
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 16))
			if v3 >= dword_5d4594_1569756 {
				break
			}
		}
	}
	dword_5d4594_1569756 = 0
	return 1
}
func sub_500510(a1 *byte) {
	if a1 != nil {
		libc.StrCpy((*byte)(memmap.PtrOff(0x5D4594, 1570008)), a1)
	}
}
func nox_xxx_voteUptate_506F30() {
	var (
		result *uint32
		v1     *uint32
	)
	result = dword_5d4594_1599656
	if dword_5d4594_1599656 != 0 {
		for {
			v1 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*11)))
			switch *result {
			case 0, 1:
				sub_506F80(int32(uintptr(unsafe.Pointer(result))))
			case 2:
				sub_507090(int32(uintptr(unsafe.Pointer(result))))
			case 3:
				sub_507100(int32(uintptr(unsafe.Pointer(result))))
			default:
			}
			result = v1
			if v1 == nil {
				break
			}
		}
	}
}
func sub_50AFA0() {
	var (
		i      int32
		v1     int32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    float64
		v12    int32
		v13    int32
		v14    int32
		v15    int32
		v16    *uint8
		v17    *float32
		v18    int16
		result *float32
		k      *float32
		v21    int32
		v22    int32
		v23    float32
		v24    float32
		v25    float32
		v26    float32
		v27    float32
		v28    float32
		v29    float32
		v30    float32
		v31    float32
		v32    float32
		v33    float32
		v34    float32
		v35    float32
		v36    float32
		j      int32
		v38    int32
		v39    int32
		v40    int32
		v41    float32
		v42    float32
		a2     types.Pointf
		v44    int32
	)
	dword_5d4594_2386160 = 0
	*(*[65536]nox_server_xxx)(unsafe.Pointer(&nox_server_xxx_1599716[0])) = [65536]nox_server_xxx{}
	dword_5d4594_2386164 = 0
	for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(i))))) {
		nox_xxx_aiTestUnitDangerous_50B2C0(i)
		v1 = int32(*(*uint32)(unsafe.Add(i, 8)))
		if (v1 & 0x80) == 0 {
			if v1&0x800 != 0 {
				v23 = float32(float64(*(*float32)(unsafe.Add(i, 56))) * 0.043478262)
				v2 = int32(v23)
				v24 = float32(float64(*(*float32)(unsafe.Add(i, 60))) * 0.043478262)
				v3 = int32(v24)
				nox_server_xxx_1599716[v3+(v2<<8)].field_8 |= 0x10
			} else if v1&0x400 != 0 {
				v25 = float32(float64(*(*float32)(unsafe.Add(i, 56))) * 0.043478262)
				v4 = int32(v25)
				v26 = float32(float64(*(*float32)(unsafe.Add(i, 60))) * 0.043478262)
				v5 = int32(v26)
				nox_server_xxx_1599716[v5+(v4<<8)].field_8 |= 0x20
			} else if v1&0x4000 != 0 {
				v27 = float32(float64(*(*float32)(unsafe.Add(i, 56))) * 0.043478262)
				v6 = int32(v27)
				v28 = float32(float64(*(*float32)(unsafe.Add(i, 60))) * 0.043478262)
				v7 = int32(v28)
				nox_server_xxx_1599716[v7+(v6<<8)].field_8 |= 0x4
			} else if (v1 & 0x8000) == 0 {
				if (int32(*(*uint8)(unsafe.Add(i, 16))) & 0x49) == 0 {
					if uint32(v1)&0x400000 != 0 {
						v31 = float32(float64(*(*float32)(unsafe.Add(i, 232))) * 0.043478262)
						v10 = int32(v31)
						v11 = float64(*(*float32)(unsafe.Add(i, 236))) * 0.043478262
						v12 = v10
						v44 = v10
						v32 = float32(v11)
						v13 = int32(v32)
						v33 = float32(float64(*(*float32)(unsafe.Add(i, 240))) * 0.043478262)
						v39 = int32(v33)
						v34 = float32(float64(*(*float32)(unsafe.Add(i, 244))) * 0.043478262)
						v14 = int32(v34)
						v15 = v13
						v40 = v14
						for j = v13; v15 <= v14; j = v15 {
							v38 = v12
							if v12 <= v39 {
								v16 = (*uint8)(unsafe.Pointer(&nox_server_xxx_1599716[v15+(v12<<8)].field_8))
								for {
									v17 = mem_getFloatPtr(0x587000, 234108)
									for {
										v41 = float32(float64(v38) * 23.0)
										a2.X = v41 + *((*float32)(unsafe.Add(unsafe.Pointer(v17), -int(unsafe.Sizeof(float32(0))*1))))
										v42 = float32(float64(j) * 23.0)
										a2.Y = v42 + *v17
										if sub_547DB0(i, &a2) != 0 {
											break
										}
										v17 = (*float32)(unsafe.Add(unsafe.Pointer(v17), unsafe.Sizeof(float32(0))*2))
										if int32(uintptr(unsafe.Pointer(v17))) >= int32(uintptr(memmap.PtrOff(0x587000, 234180))) {
											goto LABEL_22
										}
									}
									v18 = int16(*(*uint16)(unsafe.Pointer(v16)))
									*((*uint8)(unsafe.Pointer(&v18))) = uint8(int8(int32(*(*uint16)(unsafe.Pointer(v16))) | 1))
									*(*uint16)(unsafe.Pointer(v16)) = uint16(v18)
									if (int32(*(*uint8)(unsafe.Add(i, 16))) & 0x10) == 0 {
										*((*uint8)(unsafe.Pointer(&v18))) = uint8(int8(int32(v18) | 2))
										*(*uint16)(unsafe.Pointer(v16)) = uint16(v18)
									}
								LABEL_22:
									v12++
									v16 = (*uint8)(unsafe.Add(unsafe.Pointer(v16), NOX_SERVER_XXX_SIZE*unsafe.Sizeof(nox_server_xxx{})))
									v38 = v12
									if v12 > v39 {
										break
									}
								}
								v15 = j
								v14 = v40
								v12 = v44
							}
							v15++
						}
					}
				}
			} else {
				v29 = float32(float64(*(*float32)(unsafe.Add(i, 56))) * 0.043478262)
				v8 = int32(v29)
				v30 = float32(float64(*(*float32)(unsafe.Add(i, 60))) * 0.043478262)
				v9 = int32(v30)
				nox_server_xxx_1599716[v9+(v8<<8)].field_8 |= 0x8
			}
		}
	}
	result = (*float32)(nox_xxx_waypointGetList_579860())
	for k = result; result != nil; k = result {
		if sub_579EE0((*server.Waypoint)(unsafe.Pointer(k)), 0x80) != 0 {
			v35 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(k), unsafe.Sizeof(float32(0))*2))) * 0.043478262)
			v21 = int32(v35)
			v36 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(k), unsafe.Sizeof(float32(0))*3))) * 0.043478262)
			v22 = int32(v36)
			nox_server_xxx_1599716[v22+(v21<<8)].field_8 |= 0x40
		}
		result = (*float32)(unsafe.Pointer(uintptr(nox_xxx_waypointNext_579870(int32(uintptr(unsafe.Pointer(k)))))))
	}
}
func sub_50D890() uint32 {
	var result uint32
	if (gameFrame() % (gameFPS() * 5)) == 0 {
		sub_50D8D0()
	}
	result = gameFrame() / 0xF
	if (gameFrame() % 0xF) == 0 {
		result = uint32(sub_50D960())
	}
	return result
}
func sub_51A1F0(a1 int32) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  float64
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		i   int32
		v17 int32
		v18 int32
		v19 float32
		v20 float32
		v21 uint32
		v22 int32
		v23 int32
		v24 uint32
		v25 int32
	)
	v21 = 0
	v23 = 0
	v1 = nox_game_getQuestStage_4E3CC0()
	v22 = v1
	v19 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("QuestHardcoreStage")))
	v24 = uint32(int32(v19))
	if *memmap.PtrUint32(0x5D4594, 2388668) == 0 {
		*memmap.PtrUint32(0x5D4594, 2388668) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("HecubahMarker")))
		*memmap.PtrUint32(0x5D4594, 2388672) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("NecromancerMarker")))
	}
	v2 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v2 != 0 {
		v3 = a1
		for {
			v4 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v2)))))
			v5 = int32(*(*uint32)(unsafe.Add(v2, 8)))
			v25 = v4
			if v5&0x20 != 0 && int32(*(*uint8)(unsafe.Add(v2, 12)))&1 != 0 {
				v21++
			} else if uint32(*(*uint16)(unsafe.Add(v2, 4))) == *memmap.PtrUint32(0x5D4594, 2388668) {
				v23++
			}
			if uint32(v5)&0x20000 != 0 {
				v6 = int32(*(*uint32)(unsafe.Add(v2, 748)))
				if *(*uint32)(unsafe.Pointer(uintptr(v3*16 + v6))) != 0 {
					switch *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v6+v3)), 83)) {
					case 0:
						v7 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesHigh"))
						*(*uint8)(unsafe.Add(v6, 87)) = uint8(int8(int64(v7)))
					case 1:
						v7 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesNormal"))
						*(*uint8)(unsafe.Add(v6, 87)) = uint8(int8(int64(v7)))
					case 2:
						v7 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesLow"))
						*(*uint8)(unsafe.Add(v6, 87)) = uint8(int8(int64(v7)))
					case 3:
						v7 = nox_xxx_gamedataGetFloat_419D40(internCStr("GeneratorMaxActiveCreaturesSingular"))
						*(*uint8)(unsafe.Add(v6, 87)) = uint8(int8(int64(v7)))
					default:
					}
					if uint32(nox_game_getQuestStage_4E3CC0()) >= v24 && int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v6+v3)), 83))) != 3 {
						*(*uint8)(unsafe.Add(v6, 87)) *= 2
					}
					v8 = sub_51A500(int32(*(*uint32)(unsafe.Pointer(uintptr(v3*16 + v6)))))
					if v8 != 0 {
						*(*uint16)(unsafe.Add(v2, 4)) = uint16(int16(v8))
					}
				} else {
					nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v2))
				}
			}
			v2 = v25
			if v25 == 0 {
				break
			}
		}
		if v21 > 1 {
			v9 = nox_common_randomInt_415FA0(0, int32(v21-1))
			v10 = 0
			v11 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
			if v11 != 0 {
				for {
					v12 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v11)))))
					if int32(*(*uint8)(unsafe.Add(v11, 8)))&0x20 != 0 && int32(*(*uint8)(unsafe.Add(v11, 12)))&1 != 0 {
						if v10 != v9 {
							nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v11))
						}
						v10++
					}
					v11 = v12
					if v12 == 0 {
						break
					}
				}
			}
		}
		v1 = v22
	}
	sub_51A940(0)
	if v1 >= 5 {
		v20 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MinionsAlwaysStage")))
		v13 = int32(v20)
		if v1 == 5 || v1 >= v13 || v1&1 != 0 && nox_common_randomInt_415FA0(1, 100) >= 50 {
			sub_51A940(1)
			if v23 != 0 {
				v14 = nox_common_randomInt_415FA0(1, v23)
				v15 = 0
				for i = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790()))); i != 0; i = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(i))))) {
					if uint32(*(*uint16)(unsafe.Add(i, 4))) == *memmap.PtrUint32(0x5D4594, 2388668) && func() int32 {
						p := &v15
						*p++
						return *p
					}() == v14 {
						nox_xxx_spawnHecubahQuest_51A5A0((*int32)(unsafe.Add(i, 56)))
					}
					if uint32(*(*uint16)(unsafe.Add(i, 4))) == *memmap.PtrUint32(0x5D4594, 2388672) && nox_common_randomInt_415FA0(1, 100) >= 50 {
						nox_xxx_spawnNecroQuest_51A7A0((*int32)(unsafe.Add(i, 56)))
					}
				}
			}
		}
	}
	v17 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v17 != 0 {
		for {
			v18 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v17)))))
			if uint32(*(*uint16)(unsafe.Add(v17, 4))) == *memmap.PtrUint32(0x5D4594, 2388668) {
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v17))
			}
			if uint32(*(*uint16)(unsafe.Add(v17, 4))) == *memmap.PtrUint32(0x5D4594, 2388672) {
				nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(v17))
			}
			v17 = v18
			if v18 == 0 {
				break
			}
		}
	}
}
func sub_51A920(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x5D4594, 2388660) = uint32(a1)
	return result
}
func nox_xxx_updateUnits_51B100_D() {
	var v32 *uint8 = (*uint8)(nox_xxx_wallSecretGetFirstWall_410780())
	if v32 != nil {
		var v33 int8 = 0
		for ; v32 != nil; v32 = (*uint8)(unsafe.Pointer(uintptr(nox_xxx_wallSecretNext_410790((*int32)(unsafe.Pointer(v32)))))) {
			switch *(*uint8)(unsafe.Add(unsafe.Pointer(v32), 21)) {
			case 1:
				var v47 int8 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 20)))
				if (int32(v47)&4) == 0 || (int32(v47)&8) != 8 {
					v33 = 0
					break
				}
				var v48 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6))) - 1)
				*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6))) = uint32(v48)
				if v48 != 0 {
					v33 = 0
					break
				}
				var v49 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*1))))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 21)) = 4
				var v50 int32 = v49 * 23
				var v51 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*2))))
				var v52 float64 = float64(v50 + 11)
				var v53 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*3))))
				var v64 types.Pointf
				v64.X = float32(v52)
				v64.Y = float32(float64(v51*23 + 11))
				var v54 *byte = nox_xxx_wallFindOpenSound_410EE0(int32(*(*uint8)(unsafe.Add(v53, 1))))
				var v55 int32 = nox_xxx_utilFindSound_40AF50(v54)
				nox_xxx_audCreate_501A30(v55, &v64, 0, 0)
				v33 = 0
			case 2:
				var v36 int8 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 22))) - 1)
				*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 22)) = uint8(v36)
				if int32(v36) == 0 {
					var v37 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*4))))
					*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 21)) = 1
					*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6))) = gameFPS() * uint32(v37)
				}
				v33 = 1
			case 3:
				var (
					v38 int8  = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 20)))
					v39 int32 = 0
				)
				if (int32(v38)&4) != 0 && int32(v38)&8 == 0 && !(func() bool {
					v39 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6))) - 1)
					return (func() uint32 {
						p := ((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6)))
						*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6))) = uint32(v39)
						return *p
					}()) != 0
				}()) {
					var v40 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*1))))
					*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 21)) = 2
					var v41 int32 = v40 * 23
					var v42 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*2))))
					var v43 float64 = float64(v41 + 11)
					var v44 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*3))))
					var v63 types.Pointf
					v63.X = float32(v43)
					v63.Y = float32(float64(v42*23 + 11))
					var v45 *byte = nox_xxx_wallFindCloseSound_410F20(int32(*(*uint8)(unsafe.Add(v44, 1))))
					var v46 int32 = nox_xxx_utilFindSound_40AF50(v45)
					nox_xxx_audCreate_501A30(v46, &v63, 0, 0)
				}
				v33 = 0
			case 4:
				var v34 int8 = int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 22))) + 1)
				*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 22)) = uint8(v34)
				if int32(v34) == 23 {
					var v35 int32 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*4))))
					*(*uint8)(unsafe.Add(unsafe.Pointer(v32), 21)) = 3
					*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*6))) = gameFPS() * uint32(v35)
				}
				v33 = 1
			default:
			}
			if int32(v33) != 0 {
				var (
					v56 float64 = float64(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*1)))*23)) + 11.5
					v65 float64 = float64(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v32), 4*2)))*23)) + 11.5
					v66 float4
				)
				v66.field_0 = float32(v56 - 42.5)
				v66.field_4 = float32(v65 - 42.5)
				v66.field_8 = float32(v56 + 42.5)
				v66.field_C = float32(v65 + 42.5)
				nox_xxx_getUnitsInRect_517C10(&v66, sub_51B860, nil)
			}
		}
	}
}
func sub_57B140() bool {
	var (
		v0     uint64
		result int32
	)
	result = 0
	if *memmap.PtrUint64(0x5D4594, 2523796) != 0 {
		v0 = uint64(nox_xxx___Getcvt_57B180() + 5000)
		if v0 < uint64(nox_platform_get_ticks()) {
			result = 1
		}
	}
	return result != 0
}
