package legacy

import (
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
)

func nox_xxx_xferReadScriptHandler_4F5580(a1 int32, a2 *byte) int32 {
	var (
		v3 bool
		v4 int32
		v5 uint32
		v6 int32
		v7 [1024]byte
	)
	v6 = 1
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v6)), 2)
	if int32(int16(v6)) > 1 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 1 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
		if v5 >= 0x400 {
			return 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7[0])), v5)
		v3 = v5 == 0
		v7[v5] = 0
		if !v3 {
			if nox_common_gameFlags_check_40A5C0(0x600000) {
				libc.StrCpy(a2, &v7[0])
			} else {
				*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))) = uint32(nox_script_indexByEvent(&v7[0]))
			}
		}
	} else {
		if nox_common_gameFlags_check_40A5C0(0x600000) {
			if a2 != nil {
				v5 = uint32(libc.StrLen(a2))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(a2)), v5)
				goto LABEL_16
			}
		} else {
			v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(a1 + 4))))
			if v4 != -1 {
				var name *byte = nox_script_callbackName(v4)
				if name != nil {
					v5 = uint32(libc.StrLen(name))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(name)), v5)
					goto LABEL_16
				}
			}
		}
		v5 = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 4)
	}
LABEL_16:
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(a1))), 4)
	return 1
}
