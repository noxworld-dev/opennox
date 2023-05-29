package legacy

/*
#include <stdio.h>
*/

import (
	"io"
	"os"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
)

// nox_crypt_IsReadOnly
func nox_crypt_IsReadOnly() int {
	return bool2int(cryptfile.Global().ReadOnly())
}

// nox_xxx_cryptSetTypeMB_426A50
func nox_xxx_cryptSetTypeMB_426A50(a1 int) {
	cryptfile.Global().SetXOR(a1 != 0)
}

// nox_xxx_cryptOpen_426910
func nox_xxx_cryptOpen_426910(a1 *char, cmode, key int) int32 {
	if err := cryptfile.OpenGlobal(GoString(a1), cryptfile.Mode(cmode), key); err != nil {
		if !os.IsNotExist(err) {
			binfile.Log.Println(err)
		}
		return 0
	}
	return 1
}

// nox_xxx_cryptFlush_4268E0
func nox_xxx_cryptFlush_4268E0() int {
	return cryptfile.Global().Flush()
}

// nox_xxx_cryptClose_4269F0
func nox_xxx_cryptClose_4269F0() {
	cryptfile.Close()
}

// nox_xxx_mapgenGetSomeFile_426A60
func nox_xxx_mapgenGetSomeFile_426A60() *FILE {
	return NewFileHandle(cryptfile.Global().File.File)
}

// nox_xxx_cryptSeekCur_40E0A0
func nox_xxx_cryptSeekCur_40E0A0(a1 int) int {
	cryptfile.Global().Seek(int64(a1), io.SeekCurrent)
	return 0
}

// nox_xxx_fileReadWrite_426AC0_file3_fread_impl
func nox_xxx_fileReadWrite_426AC0_file3_fread_impl(a1 *byte, a2 size_t, cfname *char, line int) size_t {
	fname := GoString(cfname)
	buf := unsafe.Slice((*byte)(unsafe.Pointer(a1)), int(a2))
	_, err := cryptfile.Global().ReadWrite(buf)
	if err != nil {
		return 0
	}
	_ = fname
	return 1
}

// nox_xxx_fileCryptReadCrcMB_426C20
func nox_xxx_fileCryptReadCrcMB_426C20(a1 *byte, a2 size_t) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(a1)), int(a2))
	cryptfile.Global().ReadMaybeAlign(buf)
}

// nox_xxx_crypt_426C90
func nox_xxx_crypt_426C90() {
	cryptfile.Global().SectionStart()
}

// sub_4268F0
func sub_4268F0(off int) {
	cryptfile.Global().WriteChecksumAt(int64(off))
}

// nox_xxx_crypt_426D40
func nox_xxx_crypt_426D40() {
	cryptfile.Global().SectionEnd()
}

// sub_41C200
func sub_41C200(a1 unsafe.Pointer, a2 int) int {
	return cryptfile.Global().ReadWriteAlign()
}
