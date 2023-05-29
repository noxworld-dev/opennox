package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/gotranspile/cxgo/runtime/stdio"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var dword_5d4594_2489420 uint32 = 0
var dword_5d4594_2489424 uint32 = 0
var dword_5d4594_2489428 uint32 = 0

func nox_script_readInt_542B70(f *FILE) int32 {
	var v int32 = 0
	nox_fs_fread(f, unsafe.Pointer(&v), 4)
	return v
}
func nox_script_readFloat_542B90(f *FILE) float64 {
	var v float32 = 0
	nox_fs_fread(f, unsafe.Pointer(&v), 4)
	return float64(v)
}
func nox_script_writeFloat_542BD0(v float32, f *FILE) int32 {
	return nox_fs_fwrite(f, unsafe.Pointer(&v), 4) / 4
}
func nox_script_writeInt_542BB0(v int32, f *FILE) int32 {
	return nox_fs_fwrite(f, unsafe.Pointer(&v), 4) / 4
}
func nox_script_readWriteYyy_542380(f1 *FILE, f2 *FILE, a3 int32) int32 {
	var (
		result int32
		v6     int32
		v7     int32
		v8     int32
		v9     int8
		v10    int8
		v11    int8
		v12    int8
		v13    int32
		v15    int32
		v16    float32
	)
	for {
		result = nox_script_readInt_542B70(f1)
		switch uint32(result) {
		case 0:
			v6 = nox_script_readInt_542B70(f1)
			v7 = nox_script_readInt_542B70(f1)
			if v6 != 0 && a3 != 0 && v7 >= 4 {
				v7 = int32(uint32(v7) + dword_5d4594_2489420 - 4)
			}
			nox_script_writeInt_542BB0(0, f2)
			nox_script_writeInt_542BB0(v6, f2)
			nox_script_writeInt_542BB0(v7, f2)
		case 1:
			v6 = nox_script_readInt_542B70(f1)
			v7 = nox_script_readInt_542B70(f1)
			if v6 != 0 && a3 != 0 && v7 >= 4 {
				v7 = int32(uint32(v7) + dword_5d4594_2489420 - 4)
			}
			nox_script_writeInt_542BB0(1, f2)
			nox_script_writeInt_542BB0(v6, f2)
			nox_script_writeInt_542BB0(v7, f2)
		case 2:
			v6 = nox_script_readInt_542B70(f1)
			v7 = nox_script_readInt_542B70(f1)
			if v6 != 0 && a3 != 0 && v7 >= 4 {
				v7 = int32(uint32(v7) + dword_5d4594_2489420 - 4)
			}
			nox_script_writeInt_542BB0(2, f2)
			nox_script_writeInt_542BB0(v6, f2)
			nox_script_writeInt_542BB0(v7, f2)
		case 3:
			v8 = nox_script_readInt_542B70(f1)
			v9 = int8(uint8(uint32(nox_script_readInt_542B70(f1))))
			if v8 != 0 && a3 != 0 {
				v9 += int8(uint8(dword_5d4594_2489424))
			}
			nox_script_writeInt_542BB0(3, f2)
			nox_script_writeInt_542BB0(v8, f2)
			nox_script_writeInt_542BB0(int32(v9), f2)
		case 4:
			v10 = int8(uint8(uint32(nox_script_readInt_542B70(f1))))
			nox_script_writeInt_542BB0(4, f2)
			nox_script_writeInt_542BB0(int32(v10), f2)
		case 5:
			v16 = float32(nox_script_readFloat_542B90(f1))
			nox_script_writeInt_542BB0(5, f2)
			nox_script_writeFloat_542BD0(v16, f2)
		case 6:
			v11 = int8(uint8(uint32(nox_script_readInt_542B70(f1))))
			if a3 != 0 {
				v11 += int8(uint8(dword_5d4594_2489424))
			}
			nox_script_writeInt_542BB0(6, f2)
			nox_script_writeInt_542BB0(int32(v11), f2)
		case 7:
			nox_script_writeInt_542BB0(7, f2)
		case 8:
			nox_script_writeInt_542BB0(8, f2)
		case 9:
			nox_script_writeInt_542BB0(9, f2)
		case 0xA:
			nox_script_writeInt_542BB0(10, f2)
		case 0xB:
			nox_script_writeInt_542BB0(11, f2)
		case 0xC:
			nox_script_writeInt_542BB0(12, f2)
		case 0xD:
			nox_script_writeInt_542BB0(13, f2)
		case 0xE:
			nox_script_writeInt_542BB0(14, f2)
		case 0xF:
			nox_script_writeInt_542BB0(15, f2)
		case 0x10:
			nox_script_writeInt_542BB0(16, f2)
		case 0x11:
			nox_script_writeInt_542BB0(17, f2)
		case 0x12:
			nox_script_writeInt_542BB0(18, f2)
		case 0x13:
			nox_script_writeInt_542BB0(19, f2)
			v12 = int8(uint8(uint32(nox_script_readInt_542B70(f1))))
			nox_script_writeInt_542BB0(int32(v12), f2)
		case 0x14:
			nox_script_writeInt_542BB0(20, f2)
			v12 = int8(uint8(uint32(nox_script_readInt_542B70(f1))))
			nox_script_writeInt_542BB0(int32(v12), f2)
		case 0x15:
			nox_script_writeInt_542BB0(21, f2)
			v12 = int8(uint8(uint32(nox_script_readInt_542B70(f1))))
			nox_script_writeInt_542BB0(int32(v12), f2)
		case 0x16:
			fallthrough
		case 0x18:
			nox_script_writeInt_542BB0(result, f2)
		case 0x17:
			nox_script_writeInt_542BB0(23, f2)
		case 0x19:
			nox_script_writeInt_542BB0(25, f2)
		case 0x1A:
			nox_script_writeInt_542BB0(26, f2)
		case 0x1B:
			nox_script_writeInt_542BB0(27, f2)
		case 0x1C:
			nox_script_writeInt_542BB0(28, f2)
		case 0x1D:
			nox_script_writeInt_542BB0(29, f2)
		case 0x1E:
			nox_script_writeInt_542BB0(30, f2)
		case 0x1F:
			nox_script_writeInt_542BB0(31, f2)
		case 0x20:
			nox_script_writeInt_542BB0(32, f2)
		case 0x21:
			nox_script_writeInt_542BB0(33, f2)
		case 0x22:
			nox_script_writeInt_542BB0(34, f2)
		case 0x23:
			nox_script_writeInt_542BB0(35, f2)
		case 0x24:
			nox_script_writeInt_542BB0(36, f2)
		case 0x25:
			nox_script_writeInt_542BB0(37, f2)
		case 0x26:
			nox_script_writeInt_542BB0(38, f2)
		case 0x27:
			nox_script_writeInt_542BB0(39, f2)
		case 0x28:
			nox_script_writeInt_542BB0(40, f2)
		case 0x29:
			nox_script_writeInt_542BB0(41, f2)
		case 0x2A:
			nox_script_writeInt_542BB0(42, f2)
		case 0x2B:
			nox_script_writeInt_542BB0(43, f2)
		case 0x2C:
			nox_script_writeInt_542BB0(44, f2)
		case 0x2D:
			nox_script_writeInt_542BB0(45, f2)
		case 0x2E:
			nox_script_writeInt_542BB0(46, f2)
		case 0x2F:
			nox_script_writeInt_542BB0(47, f2)
		case 0x30:
			nox_script_writeInt_542BB0(48, f2)
		case 0x31:
			nox_script_writeInt_542BB0(49, f2)
		case 0x32:
			nox_script_writeInt_542BB0(50, f2)
		case 0x33:
			nox_script_writeInt_542BB0(51, f2)
		case 0x34:
			nox_script_writeInt_542BB0(52, f2)
		case 0x35:
			nox_script_writeInt_542BB0(53, f2)
		case 0x36:
			nox_script_writeInt_542BB0(54, f2)
		case 0x37:
			nox_script_writeInt_542BB0(55, f2)
		case 0x38:
			nox_script_writeInt_542BB0(56, f2)
		case 0x39:
			nox_script_writeInt_542BB0(57, f2)
		case 0x3A:
			nox_script_writeInt_542BB0(58, f2)
		case 0x3B:
			nox_script_writeInt_542BB0(59, f2)
		case 0x3C:
			nox_script_writeInt_542BB0(60, f2)
		case 0x3D:
			nox_script_writeInt_542BB0(61, f2)
		case 0x3E:
			nox_script_writeInt_542BB0(62, f2)
		case 0x3F:
			nox_script_writeInt_542BB0(63, f2)
		case 0x40:
			nox_script_writeInt_542BB0(64, f2)
		case 0x41:
			nox_script_writeInt_542BB0(65, f2)
		case 0x42:
			nox_script_writeInt_542BB0(66, f2)
		case 0x43:
			nox_script_writeInt_542BB0(67, f2)
		case 0x44:
			nox_script_writeInt_542BB0(68, f2)
		case 0x45:
			v13 = nox_script_readInt_542B70(f1)
			if a3 != 0 {
				if nox_script_shouldReadMoreXxx(v13) {
					var a2 int32 = 0
					nox_fs_fseek(f2, -4, stdio.SEEK_CUR)
					nox_fs_fread(f2, unsafe.Pointer(&a2), 4)
					nox_fs_fseek(f2, -4, stdio.SEEK_CUR)
					a2 = int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(a2)))), dword_5d4594_2489428))), -2)))))
					nox_fs_fwrite(f2, unsafe.Pointer(&a2), 4)
					if nox_script_shouldReadEvenMoreXxx(v13) {
						nox_fs_fseek(f2, -12, stdio.SEEK_CUR)
						nox_fs_fread(f2, unsafe.Pointer(&a2), 4)
						nox_fs_fseek(f2, -4, stdio.SEEK_CUR)
						a2 = int32(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(uintptr(a2)))), dword_5d4594_2489428))), -2)))))
						nox_fs_fwrite(f2, unsafe.Pointer(&a2), 4)
						nox_fs_fseek(f2, 8, stdio.SEEK_CUR)
					}
				}
			}
			nox_script_writeInt_542BB0(69, f2)
			nox_script_writeInt_542BB0(v13, f2)
		case 0x46:
			v15 = nox_script_readInt_542B70(f1)
			if a3 != 0 {
				v15 = int32(uint32(v15) + dword_5d4594_2489428 - 2)
			}
			nox_script_writeInt_542BB0(70, f2)
			nox_script_writeInt_542BB0(v15, f2)
		case 0x47:
			nox_script_writeInt_542BB0(71, f2)
		case 0x48:
			return nox_script_writeInt_542BB0(72, f2)
		case 0x49:
			nox_script_writeInt_542BB0(73, f2)
		default:
			return result
		}
	}
}
func nox_script_readWriteJjj_5418C0(a1 *FILE, a2 *FILE, a3 *FILE) int32 {
	var (
		i      int32
		result int32
		j      int32
		v6     uint32
		v7     int32
		v8     int32
		v9     int32
		v10    [4096]byte
	)
	libc.StrCpy(&v10[0], internCStr("STRG"))
	v6 = uint32(libc.StrLen(&v10[0]))
	nox_fs_fread(a1, unsafe.Pointer(&v10[0]), int32(v6))
	nox_fs_fread(a2, unsafe.Pointer(&v10[0]), int32(v6))
	nox_fs_fwrite(a3, unsafe.Pointer(&v10[0]), int32(v6))
	nox_fs_fread(a1, unsafe.Pointer(&v8), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v7), 4)
	dword_5d4594_2489424 = uint32(v8)
	v9 = v8 + v7
	nox_fs_fwrite(a3, unsafe.Pointer(&v9), 4)
	for i = 0; i < v8; i++ {
		nox_fs_fread(a1, unsafe.Pointer(&v6), 4)
		nox_fs_fread(a1, unsafe.Pointer(&v10[0]), int32(v6))
		v10[v6] = 0
		nox_fs_fwrite(a3, unsafe.Pointer(&v6), 4)
		nox_fs_fwrite(a3, unsafe.Pointer(&v10[0]), int32(v6))
	}
	result = v7
	for j = 0; j < v7; j++ {
		nox_fs_fread(a2, unsafe.Pointer(&v6), 4)
		nox_fs_fread(a2, unsafe.Pointer(&v10[0]), int32(v6))
		v10[v6] = 0
		nox_fs_fwrite(a3, unsafe.Pointer(&v6), 4)
		nox_fs_fwrite(a3, unsafe.Pointer(&v10[0]), int32(v6))
		result = v7
	}
	return result
}
func nox_script_readWriteVvv_541E40(a1 *FILE, a2 *FILE, a3 *FILE) int32 {
	var (
		v4  uint32
		v5  int32
		i   int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
	)
	v4 = 4
	nox_fs_fread(a1, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v4), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a2, unsafe.Pointer(&v4), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v4), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v9), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v9), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v9), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v8), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v8), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v8), 4)
	v4 = 4
	nox_fs_fread(a1, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v7), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v11), 4)
	v12 = v7 + v11
	nox_fs_fwrite(a3, unsafe.Pointer(&v12), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v10), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v10), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v10), 4)
	v4 = 4
	nox_fs_fread(a1, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v13), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v14), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v13), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v15), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v15), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v15), 4)
	v4 = 4
	nox_fs_fread(a1, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v4), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a2, unsafe.Pointer(&v4), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v4), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v9), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v9), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v9), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v8), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v8), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v8), 4)
	v4 = 4
	nox_fs_fread(a1, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v7), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v11), 4)
	dword_5d4594_2489420 = uint32(v7)
	v12 = v11 + v7 - 4
	nox_fs_fwrite(a3, unsafe.Pointer(&v12), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v10), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v10), 4)
	nox_fs_fwrite(a3, unsafe.Pointer(&v10), 4)
	for i = 0; i < v7; i++ {
		nox_fs_fread(a1, unsafe.Pointer(&v5), 4)
		nox_fs_fwrite(a3, unsafe.Pointer(&v5), 4)
	}
	nox_fs_fread(a2, unsafe.Pointer(&v5), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v5), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v5), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v5), 4)
	for i = 4; i < v11; i++ {
		nox_fs_fread(a2, unsafe.Pointer(&v5), 4)
		nox_fs_fwrite(a3, unsafe.Pointer(&v5), 4)
	}
	v4 = 4
	nox_fs_fread(a1, unsafe.Pointer(&v17), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fwrite(a3, unsafe.Pointer(&v17), int32(v4))
	nox_fs_fread(a1, unsafe.Pointer(&v13), 4)
	nox_fs_fread(a2, unsafe.Pointer(&v14), 4)
	v16 = v14 + v13 - 4
	nox_fs_fwrite(a3, unsafe.Pointer(&v16), 4)
	nox_script_readWriteYyy_542380(a1, a3, 0)
	nox_fs_fseek(a3, -4, stdio.SEEK_CUR)
	return nox_script_readWriteYyy_542380(a2, a3, 1)
}
func nox_script_readWriteIii_541D80(a1 *FILE, a2 *FILE) int32 {
	var (
		v2     int32
		result int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
	)
	nox_fs_fread(a1, unsafe.Pointer(&v7), 4)
	v2 = 0
	nox_fs_fwrite(a2, unsafe.Pointer(&v7), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v4), 4)
	nox_fs_fwrite(a2, unsafe.Pointer(&v4), 4)
	nox_fs_fread(a1, unsafe.Pointer(&v5), 4)
	nox_fs_fwrite(a2, unsafe.Pointer(&v5), 4)
	result = v4
	if v4 != 0 && v4 > 0 {
		for {
			nox_fs_fread(a1, unsafe.Pointer(&v6), 4)
			nox_fs_fwrite(a2, unsafe.Pointer(&v6), 4)
			result = v4
			v2++
			if v2 >= v4 {
				break
			}
		}
	}
	return result
}
func nox_script_readWriteXxx_541A50(f1 *FILE, f2 *FILE, f3 *FILE) int32 {
	var (
		v3     uint32
		result int32
		i      int32
		j      int32
		v7     uint32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    [4096]byte
	)
	libc.StrCpy(&v14[0], internCStr("CODE"))
	v3 = uint32(libc.StrLen(&v14[0]) + 1)
	nox_fs_fread(f1, unsafe.Pointer(&v14[0]), int32(v3-1))
	nox_fs_fread(f2, unsafe.Pointer(&v14[0]), int32(v3-1))
	nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v3-1))
	nox_fs_fread(f1, unsafe.Pointer(&v11), 4)
	nox_fs_fread(f2, unsafe.Pointer(&v10), 4)
	dword_5d4594_2489428 = uint32(v11)
	v13 = v10 + v11 - 2
	nox_fs_fwrite(f3, unsafe.Pointer(&v13), 4)
	result = nox_script_readWriteVvv_541E40(f1, f2, f3)
	for i = 0; i < v11-2; result = v11 - 2 {
		v7 = 4
		nox_fs_fread(f1, unsafe.Pointer(&v14[0]), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v7))
		nox_fs_fread(f1, unsafe.Pointer(&v7), 4)
		nox_fs_fread(f1, unsafe.Pointer(&v14[0]), int32(v7))
		v14[v7] = 0
		nox_fs_fwrite(f3, unsafe.Pointer(&v7), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v7))
		nox_fs_fread(f1, unsafe.Pointer(&v12), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v12), 4)
		nox_fs_fread(f1, unsafe.Pointer(&v8), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v8), 4)
		nox_script_readWriteIii_541D80(f1, f3)
		v7 = 4
		nox_fs_fread(f1, unsafe.Pointer(&v14[0]), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v7))
		nox_fs_fread(f1, unsafe.Pointer(&v9), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v9), 4)
		nox_script_readWriteYyy_542380(f1, f3, 0)
		i++
	}
	for j = 0; j < v10-2; result = v10 - 2 {
		v7 = 4
		nox_fs_fread(f2, unsafe.Pointer(&v14[0]), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v7))
		nox_fs_fread(f2, unsafe.Pointer(&v7), 4)
		nox_fs_fread(f2, unsafe.Pointer(&v14[0]), int32(v7))
		v14[v7] = 0
		nox_fs_fwrite(f3, unsafe.Pointer(&v7), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v7))
		nox_fs_fread(f2, unsafe.Pointer(&v12), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v12), 4)
		nox_fs_fread(f2, unsafe.Pointer(&v8), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v8), 4)
		nox_script_readWriteIii_541D80(f2, f3)
		v7 = 4
		nox_fs_fread(f2, unsafe.Pointer(&v14[0]), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v14[0]), int32(v7))
		nox_fs_fread(f2, unsafe.Pointer(&v9), 4)
		nox_fs_fwrite(f3, unsafe.Pointer(&v9), 4)
		nox_script_readWriteYyy_542380(f2, f3, 1)
		j++
	}
	return result
}
func nox_script_readWriteWww_5417C0(a1 *FILE, a2 *FILE, a3 *FILE) uint32 {
	var (
		v3 uint32
		v4 uint32
		v6 [1024]byte
	)
	dword_5d4594_2489420 = 0
	dword_5d4594_2489424 = 0
	dword_5d4594_2489428 = 0
	libc.StrCpy(&v6[0], internCStr("SCRIPT03"))
	v3 = uint32(libc.StrLen(&v6[0]) + 1)
	nox_fs_fread(a1, unsafe.Pointer(&v6[0]), int32(v3-1))
	nox_fs_fread(a2, unsafe.Pointer(&v6[0]), int32(v3-1))
	nox_fs_fwrite(a3, unsafe.Pointer(&v6[0]), int32(v3-1))
	nox_script_readWriteJjj_5418C0(a1, a2, a3)
	nox_script_readWriteXxx_541A50(a1, a2, a3)
	libc.StrCpy(&v6[0], internCStr("DONE"))
	v4 = uint32(libc.StrLen(&v6[0]) + 1)
	nox_fs_fread(a1, unsafe.Pointer(&v6[0]), int32(v4-1))
	nox_fs_fread(a2, unsafe.Pointer(&v6[0]), int32(v4-1))
	return uint32(nox_fs_fwrite(a3, unsafe.Pointer(&v6[0]), int32(v4-1)))
}
func sub_543110(lpExistingFileName *byte, a2 *int32) int32 {
	var (
		v2          int32
		v3          int32
		v4          *byte
		v6          *FILE
		v7          *FILE
		v8          uint32
		i           int32
		v10         int32
		v11         int32
		v12         uint32
		v13         int32
		v14         int32
		v15         int32
		j           int32
		v17         int32
		v18         int32
		v19         [2048]byte
		NewFileName [2048]byte
	)
	sub_542BF0(*(*int32)(unsafe.Pointer(&dword_5d4594_3835312)), *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
	v2 = int32(*memmap.PtrUint32(0x587000, 282612))
	libc.StrCpy(&NewFileName[0], (*byte)(memmap.PtrOff(0x973F18, 42152)))
	v3 = int32(*memmap.PtrUint32(0x587000, 282616))
	v4 = &NewFileName[libc.StrLen(&NewFileName[0])]
	*(*uint32)(unsafe.Pointer(v4)) = *memmap.PtrUint32(0x587000, 282608)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*1))) = uint32(v2)
	*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v4))), 4*2))) = uint32(v3)
	nox_fs_copy(lpExistingFileName, &NewFileName[0])
	v6 = nox_fs_open(&NewFileName[0])
	if v6 == nil {
		return 0
	}
	v7 = nox_fs_open_rw(lpExistingFileName)
	if v7 == nil {
		nox_fs_close(v6)
		return 0
	}
	libc.StrCpy(&v19[0], internCStr("SCRIPT03"))
	v8 = uint32(libc.StrLen(&v19[0]) + 1)
	nox_fs_fread(v6, unsafe.Pointer(&v19[0]), int32(v8-1))
	nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v8-1))
	libc.StrCpy(&v19[0], internCStr("STRG"))
	v12 = uint32(libc.StrLen(&v19[0]))
	nox_fs_fread(v6, unsafe.Pointer(&v19[0]), int32(v12))
	nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
	nox_fs_fread(v6, unsafe.Pointer(&v14), 4)
	nox_fs_fwrite(v7, unsafe.Pointer(&v14), 4)
	for i = 0; i < v14; i++ {
		nox_fs_fread(v6, unsafe.Pointer(&v12), 4)
		nox_fs_fread(v6, unsafe.Pointer(&v19[0]), int32(v12))
		v19[v12] = 0
		nox_fs_fwrite(v7, unsafe.Pointer(&v12), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
	}
	libc.StrCpy(&v19[0], internCStr("CODE"))
	v12 = uint32(libc.StrLen(&v19[0]))
	nox_fs_fread(v6, unsafe.Pointer(&v19[0]), int32(v12))
	nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
	nox_fs_fread(v6, unsafe.Pointer(&v15), 4)
	nox_fs_fwrite(v7, unsafe.Pointer(&v15), 4)
	v10 = 0
	for j = 0; v10 < v15; j = v10 {
		v12 = 4
		nox_fs_fread(v6, unsafe.Pointer(&v19[0]), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
		nox_fs_fread(v6, unsafe.Pointer(&v12), 4)
		nox_fs_fread(v6, unsafe.Pointer(&v19[0]), int32(v12))
		v19[v12] = 0
		if v10 > 1 {
			sub_5435C0(int32(uintptr(unsafe.Pointer(&v19[0]))), *(*int32)(unsafe.Pointer(&dword_5d4594_3835312)), *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*0)), *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*1)))
			libc.StrCpy(&v19[0], (*byte)(memmap.PtrOff(0x5D4594, 2489164)))
			v10 = j
			v12 = uint32(libc.StrLen(&v19[0]))
		}
		nox_fs_fwrite(v7, unsafe.Pointer(&v12), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
		nox_fs_fread(v6, unsafe.Pointer(&v18), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v18), 4)
		nox_fs_fread(v6, unsafe.Pointer(&v17), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v17), 4)
		nox_script_readWriteIii_541D80(v6, v7)
		v12 = 4
		nox_fs_fread(v6, unsafe.Pointer(&v19[0]), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
		v11 = nox_fs_ftell(v7)
		nox_fs_fread(v6, unsafe.Pointer(&v13), 4)
		nox_fs_fwrite(v7, unsafe.Pointer(&v13), 4)
		nox_script_readWriteYyy_542380(v6, v7, 0)
		v13 = int32(-4-v11) + nox_fs_ftell(v7)
		nox_fs_fseek(v7, v11, stdio.SEEK_SET)
		nox_fs_fwrite(v7, unsafe.Pointer(&v13), 4)
		nox_fs_fseek(v7, v13, stdio.SEEK_CUR)
		v10++
	}
	libc.StrCpy(&v19[0], internCStr("DONE"))
	v12 = uint32(libc.StrLen(&v19[0]))
	nox_fs_fread(v6, unsafe.Pointer(&v19[0]), int32(v12))
	nox_fs_fwrite(v7, unsafe.Pointer(&v19[0]), int32(v12))
	nox_fs_close(v6)
	nox_fs_close(v7)
	return bool2int32(nox_fs_remove(&NewFileName[0]))
}
