package opennox

/*
#include <stdio.h>
*/
import "C"
import (
	"io"
	"os"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
)

//export nox_xxx_cryptGetXxx
func nox_xxx_cryptGetXxx() C.int {
	return C.int(cryptfile.GetMode())
}

//export nox_xxx_cryptSetTypeMB_426A50
func nox_xxx_cryptSetTypeMB_426A50(a1 C.int) {
	cryptfile.SetXOR(a1 != 0)
}

//export nox_xxx_cryptOpen_426910
func nox_xxx_cryptOpen_426910(a1 *C.char, cmode, key C.int) int32 {
	if err := cryptfile.Open(GoString(a1), int(cmode), int(key)); err != nil {
		if !os.IsNotExist(err) {
			binfile.Log.Println(err)
		}
		return 0
	}
	return 1
}

//export nox_xxx_cryptFlush_4268E0
func nox_xxx_cryptFlush_4268E0() C.int {
	return C.int(cryptfile.Flush())
}

//export nox_xxx_cryptClose_4269F0
func nox_xxx_cryptClose_4269F0() {
	cryptfile.Close()
}

//export nox_xxx_mapgenGetSomeFile_426A60
func nox_xxx_mapgenGetSomeFile_426A60() *C.FILE {
	return newFileHandle(cryptfile.GetFile().File)
}

//export nox_xxx_cryptSeekCur_40E0A0
func nox_xxx_cryptSeekCur_40E0A0(a1 C.int) C.int {
	nox_xxx_cryptSeekCur(int64(a1))
	return 0
}

func nox_xxx_cryptSeekCur(off int64) {
	cryptfile.Seek(off, io.SeekCurrent)
}

//export nox_xxx_fileReadWrite_426AC0_file3_fread
func nox_xxx_fileReadWrite_426AC0_file3_fread(a1 *C.uchar, a2 C.size_t) C.size_t {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(a1)), int(a2))
	_, err := cryptfile.ReadWrite(buf)
	if err != nil {
		return 0
	}
	return 1
}

//export nox_xxx_fileCryptReadCrcMB_426C20
func nox_xxx_fileCryptReadCrcMB_426C20(a1 *C.uchar, a2 C.size_t) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(a1)), int(a2))
	cryptfile.ReadMaybeAlign(buf)
}

//export nox_xxx_crypt_426C90
func nox_xxx_crypt_426C90() {
	cryptfile.SectionStart()
}

//export sub_4268F0
func sub_4268F0(off C.int) {
	cryptfile.WriteChecksumAt(int64(off))
}

//export nox_xxx_crypt_426D40
func nox_xxx_crypt_426D40() {
	cryptfile.SectionEnd()
}

//export sub_41C200
func sub_41C200() int {
	return cryptfile.ReadWriteAlign()
}
