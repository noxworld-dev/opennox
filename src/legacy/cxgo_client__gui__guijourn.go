package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_xxx_cliBuildJournalString_469BC0() {
	var (
		v0  int32
		v1  int32
		v2  int32
		i   int32
		v4  int32
		v5  int32
		v6  int32
		v7  *wchar2_t
		v8  *wchar2_t
		v9  *wchar2_t
		v10 *wchar2_t
		v11 int32
		v12 int32
		v13 [76]byte
		v14 [2048]wchar2_t
	)
	v0 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		v1 = nox_xxx_guiFontHeightMB_43F320(nil)
		v2 = int32(*(*uint32)(unsafe.Add(v0, 3644)))
		v11 = v1
		for i = -v1; v2 != 0; i += v11 + v12 {
			libc.StrCpy(&v13[0], internCStr("Journal:"))
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*1)) = 0
			libc.StrCat(&v13[0], (*byte)(v2))
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(v2, 72))
			v5 = v4 - 2
			if v5 != 0 {
				v6 = v5 - 2
				if v6 != 0 {
					if v6 == 4 {
						v8 = nox_strman_loadString_40F1D0(internCStr("Journal:HintLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 64)
						nox_wcscpy(&v14[0], v8)
					} else {
						v14[0] = 0
					}
				} else {
					v9 = nox_strman_loadString_40F1D0(internCStr("Journal:CompletedLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 60)
					nox_wcscpy(&v14[0], v9)
				}
			} else {
				v10 = nox_strman_loadString_40F1D0(internCStr("Journal:QuestLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 56)
				nox_wcscpy(&v14[0], v10)
			}
			nox_wcscat(&v14[0], internWStr(" "))
			v7 = nox_strman_loadString_40F1D0(&v13[0], nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 74)
			nox_wcscat(&v14[0], v7)
			nox_xxx_drawGetStringSize_43F840(nil, &v14[0], nil, &v12, 240)
			v2 = int32(*(*uint32)(unsafe.Add(v2, 64)))
		}
		*memmap.PtrUint32(0x5D4594, 1064848) = uint32(func() int32 {
			if i <= 0 {
				return 0
			}
			return i
		}())
	}
}
func nox_xxx_guiDrawJournal_469D40(xLeft int32, yTop int32, a3 int32) {
	var (
		v3  int32
		v4  int32
		v5  int32
		i   int32
		v7  int32
		v8  int32
		v9  *wchar2_t
		v10 *wchar2_t
		v11 *wchar2_t
		v12 *wchar2_t
		v13 int32
		v14 int32
		v15 int32
		v16 [76]byte
		v17 [2048]wchar2_t
	)
	v3 = int32(*memmap.PtrUint32(0x8531A0, 2576))
	v4 = yTop - a3
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 {
		nox_client_drawSetColor_434460(int32(nox_color_black_2650656))
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, 260, 150)
		v5 = int32(*(*uint32)(unsafe.Add(v3, 3644)))
		if v5 != 0 {
			for i = int32(*(*uint32)(unsafe.Add(v5, 64))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 64))) {
				v5 = i
			}
			v14 = nox_xxx_guiFontHeightMB_43F320(nil)
			for {
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v7), unsafe.Sizeof(uint16(0))*1)) = 0
				libc.StrCpy(&v16[0], internCStr("Journal:"))
				libc.StrCat(&v16[0], (*byte)(v5))
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v7), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(v5, 72))
				switch v7 {
				case 1:
					v8 = int32(nox_color_white_2523948)
					v17[0] = 0
				case 2:
					v8 = int32(*memmap.PtrUint32(0x85B3FC, 940))
					v9 = nox_strman_loadString_40F1D0(internCStr("Journal:QuestLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 135)
					nox_wcscpy(&v17[0], v9)
				case 4:
					v8 = int32(*memmap.PtrUint32(0x85B3FC, 956))
					v10 = nox_strman_loadString_40F1D0(internCStr("Journal:CompletedLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 140)
					nox_wcscpy(&v17[0], v10)
				case 8:
					v8 = int32(nox_color_yellow_2589772)
					v11 = nox_strman_loadString_40F1D0(internCStr("Journal:HintLabel"), nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 145)
					nox_wcscpy(&v17[0], v11)
				default:
					v8 = int32(*memmap.PtrUint32(0x8531A0, 2572))
					v17[0] = 0
				}
				nox_wcscat(&v17[0], internWStr(" "))
				v12 = nox_strman_loadString_40F1D0(&v16[0], nil, internCStr("C:\\NoxPost\\src\\client\\Gui\\GUIJourn.c"), 155)
				nox_wcscat(&v17[0], v12)
				nox_xxx_drawGetStringSize_43F840(nil, &v17[0], nil, &v15, 240)
				v13 = v15 + v4
				if v15+v4 > yTop {
					nox_xxx_drawSetTextColor_434390(v8)
					nox_xxx_drawStringWrap_43FAF0(nil, &v17[0], xLeft+10, v4, 240, 0)
				}
				v4 = v13 + v14
				if v13+v14 > yTop+150 {
					break
				}
				v5 = int32(*(*uint32)(unsafe.Add(v5, 68)))
				if v5 == 0 {
					break
				}
			}
		}
	}
}
