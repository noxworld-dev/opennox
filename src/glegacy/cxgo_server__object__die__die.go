package legacy

import (
	"unsafe"
)

func nox_xxx_dieArmor_54E170_obj_die(a1 int32) {
	var (
		v1  int32
		v2  int32
		v3  *uint32
		v4  int16
		v5  int32
		v6  int16
		v7  *wchar2_t
		v8  int32
		v9  *wchar2_t
		v10 *float2
	)
	v1 = a1
	v2 = 0
	if nox_strman_get_lang_code() == 0 || nox_strman_get_lang_code() == 1 {
		v3 = (*uint32)(nox_xxx_equipClothFindDefByTT_413270(int32(*(*uint16)(unsafe.Pointer(uintptr(a1 + 4))))))
		if v3 != nil {
			v4 = int16(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2)) + nox_wcslen((*wchar2_t)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*2))))))*2 - 2))))
			if int32(v4) == 83 || int32(v4) == 115 {
				v2 = 1
			}
		}
	}
	v5 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 492))))
	if v5 != 0 {
		v10 = (*float2)(unsafe.Pointer(uintptr(v5 + 56)))
	} else {
		v10 = (*float2)(unsafe.Pointer(uintptr(a1 + 56)))
	}
	v6 = int16(*(*uint16)(unsafe.Pointer(uintptr(v1 + 24))))
	if int32(v6)&0x10 != 0 {
		if v2 != 0 {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieMetalPlural"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1536)
		} else {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieMetal"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1538)
		}
		v8 = 806
	} else if int32(v6)&8 != 0 {
		if v2 != 0 {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieWoodPlural"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1547)
		} else {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieWood"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1549)
		}
		v8 = 812
	} else if int32(v6)&4 != 0 {
		if v2 != 0 {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieHidePlural"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1558)
		} else {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieHide"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1560)
		}
		v8 = 809
	} else if int32(v6)&2 != 0 {
		if v2 != 0 {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieClothPlural"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1569)
		} else {
			v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieCloth"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1571)
		}
		v8 = 815
	} else {
		v8 = int32(uintptr(unsafe.Pointer(v10)))
		v7 = nox_strman_loadString_40F1D0(internCStr("ArmorDieGeneric"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1579)
	}
	v9 = nox_xxx_itemGetName_4E77E0_obj_util(v1)
	nox_xxx_netSendLineMessage_4D9EB0((*nox_object_t)(unsafe.Pointer(uintptr(v5))), v7, v9)
	nox_xxx_audCreate_501A30(v8, v10, 0, 0)
	nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(v1))))
}
func nox_xxx_dieWeapon_54E370_obj_die(a1 int32) {
	var (
		v1 int32
		v2 *float2
		v3 int16
		v4 *wchar2_t
		v5 *wchar2_t
		v6 *wchar2_t
		v7 *wchar2_t
		v8 *wchar2_t
		v9 *wchar2_t
	)
	v1 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 492))))
	v2 = (*float2)(unsafe.Pointer(uintptr(v1 + 56)))
	if v1 == 0 {
		v2 = (*float2)(unsafe.Pointer(uintptr(a1 + 56)))
	}
	v3 = int16(*(*uint16)(unsafe.Pointer(uintptr(a1 + 24))))
	if int32(v3)&0x10 != 0 {
		v7 = nox_xxx_itemGetName_4E77E0_obj_util(a1)
		v4 = nox_strman_loadString_40F1D0(internCStr("WeaponDieMetal"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1626)
		nox_xxx_netSendLineMessage_4D9EB0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), v4, v7)
		nox_xxx_audCreate_501A30(818, v2, 0, 0)
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	} else {
		if int32(v3)&8 != 0 {
			v8 = nox_xxx_itemGetName_4E77E0_obj_util(a1)
			v5 = nox_strman_loadString_40F1D0(internCStr("WeaponDieWood"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1633)
			nox_xxx_netSendLineMessage_4D9EB0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), v5, v8)
			nox_xxx_audCreate_501A30(819, v2, 0, 0)
		} else {
			v9 = sub_415B60(a1)
			v6 = nox_strman_loadString_40F1D0(internCStr("WeaponDieGeneric"), nil, internCStr("C:\\NoxPost\\src\\Server\\Object\\die\\Die.c"), 1640)
			nox_xxx_netSendLineMessage_4D9EB0((*nox_object_t)(unsafe.Pointer(uintptr(v1))), v6, v9)
		}
		nox_xxx_delayedDeleteObject_4E5CC0((*nox_object_t)(unsafe.Pointer(uintptr(a1))))
	}
}
