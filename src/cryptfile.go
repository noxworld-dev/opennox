package opennox

/*
#include <stdio.h>
*/
import "C"
import (
	"bytes"
	"encoding/binary"
	"io"
	"os"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

var (
	cryptFile           *binfile.Binfile
	cryptFileMode       int
	cryptFileRollingXOR int32
	cryptFileNoKey      bool
	cryptFileXOREnabled bool
	cryptFileOffsSaved  []cryptFileBookmark
)

type cryptFileBookmark struct {
	Before uint32
	After  uint32
}

//export nox_xxx_cryptGetXxx
func nox_xxx_cryptGetXxx() C.int {
	return C.int(cryptFileMode)
}

//export nox_xxx_cryptSetTypeMB_426A50
func nox_xxx_cryptSetTypeMB_426A50(a1 C.int) {
	cryptFileXOREnabled = a1 != 0
}

//export nox_xxx_cryptOpen_426910
func nox_xxx_cryptOpen_426910(a1 *C.char, cmode, key C.int) int32 {
	if err := cryptFileOpen(GoString(a1), int(cmode), int(key)); err != nil {
		if !os.IsNotExist(err) {
			binfile.Log.Println(err)
		}
		return 0
	}
	return 1
}

func cryptFileOpen(path string, cmode int, key int) error {
	if cryptFile != nil {
		cryptFileClose()
	}
	nox_xxx_cryptSetTypeMB_426A50(0)
	cryptFileNoKey = key == -1
	cryptFileRollingXOR = -1
	var fmode binfile.Mode
	cryptFileMode = cmode
	if cmode == 1 {
		fmode = binfile.ReadOnly
	} else if cmode == 2 {
		cryptFileMode = 0
		fmode = binfile.ReadWrite
	} else {
		fmode = binfile.WriteOnly
	}
	f, err := binfile.BinfileOpen(path, fmode)
	if err != nil {
		return err
	}
	cryptFile = f
	if err = f.SetKey(key); err != nil {
		return err
	}
	if cmode == 2 {
		if err := cryptFile.FileSeek(0, io.SeekEnd); err != nil {
			return err
		}
	}
	cryptFileOffsSaved = cryptFileOffsSaved[:0]
	return nil
}

//export nox_xxx_cryptFlush_4268E0
func nox_xxx_cryptFlush_4268E0() C.int {
	res, _ := cryptFile.FileFlush()
	return C.int(res)
}

//export nox_xxx_cryptClose_4269F0
func nox_xxx_cryptClose_4269F0() {
	cryptFileClose()
}

func cryptFileClose() {
	if cryptFile != nil {
		cryptFile.Close()
		nox_xxx_cryptSetTypeMB_426A50(0)
		cryptFile = nil
	}
}

//export nox_xxx_mapgenGetSomeFile_426A60
func nox_xxx_mapgenGetSomeFile_426A60() *C.FILE {
	return newFileHandle(cryptFile.File)
}

//export nox_xxx_cryptSeekCur_40E0A0
func nox_xxx_cryptSeekCur_40E0A0(a1 C.int) C.int {
	nox_xxx_cryptSeekCur(int64(a1))
	return 0
}

func nox_xxx_cryptSeekCur(off int64) {
	cryptFile.FileSeek(off, io.SeekCurrent)
}

func cryptFileCRCAdd(a1 []byte) {
	if cryptFile == nil {
		return
	}
	v3 := cryptFileRollingXOR
	for i := range a1 {
		v6 := int32(a1[i])
		result := int32(memmap.Uint32(0x581450, 7288+4*uintptr(v6^int32(byte(v3)))))
		v3 = result ^ (v3 >> 8)
		cryptFileRollingXOR = int32(v3)
	}
	cryptFileRollingXOR = int32(^v3)
}

//export nox_xxx_fileReadWrite_426AC0_file3_fread
func nox_xxx_fileReadWrite_426AC0_file3_fread(a1 *C.uchar, a2 C.size_t) C.size_t {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(a1)), int(a2))
	_, err := cryptFileReadWrite(buf)
	if err != nil {
		return 0
	}
	return 1
}

func fileCryptXor(key byte, p []byte) {
	if len(p) == 0 {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

type cryptFileReader struct{}

func (cryptFileReader) Read(p []byte) (int, error) {
	return cryptFileRead(p)
}

func cryptFileRead(p []byte) (int, error) {
	if cryptFileMode == 0 {
		panic("invalid file mode")
	}
	var (
		n   int
		err error
	)
	if cryptFileXOREnabled {
		n, err = cryptFile.File.Read(p)
		fileCryptXor(126, p)
	} else {
		n, err = cryptFile.Read(p)
	}
	if n != 0 {
		cryptFileCRCAdd(p)
	}
	return n, err
}

type cryptFileWriter struct{}

func (cryptFileWriter) Write(p []byte) (int, error) {
	return cryptFileWrite(p)
}

func cryptFileWrite(p []byte) (int, error) {
	if cryptFileMode != 0 {
		panic("invalid file mode")
	}
	cryptFileCRCAdd(p)
	if cryptFileXOREnabled {
		v2 := make([]byte, len(p))
		copy(v2, p)
		fileCryptXor(126, v2)
		return cryptFile.File.Write(v2)
	}
	return cryptFile.Write(p)
}

func cryptFileReadWrite(p []byte) (int, error) {
	if cryptFileMode != 0 {
		return cryptFileRead(p)
	}
	return cryptFileWrite(p)
}

func cryptFileWriteU8(v byte) error {
	_, err := cryptFileWrite([]byte{v})
	return err
}

func cryptFileWriteU16(v uint16) error {
	var buf [2]byte
	binary.LittleEndian.PutUint16(buf[:], v)
	_, err := cryptFileWrite(buf[:])
	return err
}

func cryptFileWriteU32(v uint32) error {
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], v)
	_, err := cryptFileWrite(buf[:])
	return err
}

func cryptFileWriteString8(s string) error {
	if len(s) > 0xff {
		s = s[:0xff]
	}
	if err := cryptFileWriteU8(uint8(len(s))); err != nil {
		return err
	}
	_, err := cryptFileWrite([]byte(s))
	return err
}

func cryptFileWriteString32(s string) error {
	if err := cryptFileWriteU32(uint32(len(s))); err != nil {
		return err
	}
	_, err := cryptFileWrite([]byte(s))
	return err
}

func cryptFileReadWriteU16(v uint16) (uint16, error) {
	if cryptFileMode != 0 {
		v2, err := cryptFileReadU16()
		if err != nil {
			return v, err
		}
		return v2, nil
	}
	err := cryptFileWriteU16(v)
	return v, err
}

func cryptFileReadWriteU32(v uint32) (uint32, error) {
	if cryptFileMode != 0 {
		v2, err := cryptFileReadU32()
		if err != nil {
			return v, err
		}
		return v2, nil
	}
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], v)
	_, err := cryptFileWrite(buf[:])
	return v, err
}

func cryptFileReadU8() (byte, error) {
	var buf [1]byte
	_, err := cryptFileRead(buf[:])
	if err != nil {
		return 0, err
	}
	return buf[0], nil
}

func cryptFileReadU16() (uint16, error) {
	var buf [2]byte
	_, err := cryptFileRead(buf[:])
	if err != nil {
		return 0, err
	}
	return binary.LittleEndian.Uint16(buf[:]), nil
}

func cryptFileReadU32() (uint32, error) {
	var buf [4]byte
	_, err := cryptFileRead(buf[:])
	if err != nil {
		return 0, err
	}
	return binary.LittleEndian.Uint32(buf[:]), nil
}

func cryptFileReadString8() (string, error) {
	sz, err := cryptFileReadU8()
	if err != nil {
		return "", err
	} else if sz == 0 {
		return "", nil
	}
	buf := make([]byte, sz)
	_, err = cryptFileRead(buf[:])
	if err != nil {
		return "", err
	}
	buf = bytes.TrimRight(buf, "\x00")
	return string(buf), nil
}

func cryptFileReadString32() (string, error) {
	sz, err := cryptFileReadU32()
	if err != nil {
		return "", err
	} else if sz == 0 {
		return "", nil
	}
	buf := make([]byte, sz)
	_, err = cryptFileRead(buf[:])
	if err != nil {
		return "", err
	}
	buf = bytes.TrimRight(buf, "\x00")
	return string(buf), nil
}

//export nox_xxx_fileCryptReadCrcMB_426C20
func nox_xxx_fileCryptReadCrcMB_426C20(a1 *C.uchar, a2 C.size_t) {
	buf := unsafe.Slice((*byte)(unsafe.Pointer(a1)), int(a2))
	cryptFileReadMaybeAlign(buf)
}

func cryptFileReadMaybeAlign(p []byte) error {
	if cryptFileMode != 1 {
		return nil
	}
	if cryptFileXOREnabled {
		_, err := cryptFile.File.Read(p)
		fileCryptXor(126, p)
		return err
	}
	if cryptFileNoKey {
		_, err := cryptFile.Read(p)
		return err
	}
	_, err := cryptFile.ReadAligned(p)
	return err
}

func cryptFileReadAlignedU32() (uint32, error) {
	var buf [4]byte
	err := cryptFileReadMaybeAlign(buf[:])
	return binary.LittleEndian.Uint32(buf[:]), err
}

//export nox_xxx_crypt_426C90
func nox_xxx_crypt_426C90() {
	if cryptFileMode == 0 {
		if cryptFileXOREnabled {
			v2, _ := cryptFile.File.Seek(0, io.SeekCurrent)
			cryptFileOffsSaved = append(cryptFileOffsSaved, cryptFileBookmark{
				After: uint32(v2),
			})
			var b [4]byte
			binary.LittleEndian.PutUint32(b[:], uint32(v2))
			fileCryptXor(126, b[:])
			cryptFile.File.Write(b[:])
		} else {
			off1, _ := cryptFile.FileFlush()
			off2 := cryptFile.Written()
			cryptFileOffsSaved = append(cryptFileOffsSaved, cryptFileBookmark{
				Before: uint32(off1),
				After:  uint32(off2),
			})
		}
	}
}

//export sub_4268F0
func sub_4268F0(off C.int) {
	cryptFile.WriteUint32At(cryptFileRollingXOR, int64(off))
}

//export nox_xxx_crypt_426D40
func nox_xxx_crypt_426D40() {
	if cryptFileMode != 0 {
		return
	}
	cnt := len(cryptFileOffsSaved)
	offs := cryptFileOffsSaved[cnt-1]
	cryptFileOffsSaved = cryptFileOffsSaved[:cnt-1]

	if cryptFileXOREnabled {
		v1, _ := cryptFile.File.Seek(0, io.SeekCurrent)
		v3 := uint32(v1 - int64(offs.After) - 4)
		cryptFile.FileSeek(int64(offs.After), io.SeekStart)
		var b [4]byte
		binary.LittleEndian.PutUint32(b[:], v3)
		fileCryptXor(126, b[:])
		cryptFile.File.Write(b[:])
		cryptFile.FileSeek(v1, io.SeekStart)
	} else {
		v5 := cryptFile.Written()
		cryptFile.WriteUint32At(int32(v5-int64(offs.After)), int64(offs.Before))
	}
}

//export sub_41C200
func sub_41C200() int32 {
	var b [2]byte
	binary.LittleEndian.PutUint16(b[:], 1)
	cryptFileReadWrite(b[:2])
	if int16(binary.LittleEndian.Uint16(b[:])) > 1 {
		return 0
	}
	if v1 := 8 - cryptFile.Written()%8; v1 > 0 {
		var empty [8]byte
		cryptFileReadWrite(empty[:v1])
	}
	return 1
}
