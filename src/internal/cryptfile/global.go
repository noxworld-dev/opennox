package cryptfile

import (
	"io"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

var global *CryptFile

func Global() *CryptFile {
	return global
}

func GetMode() int {
	return Global().Mode()
}

func GetFile() *binfile.Binfile {
	if global == nil {
		return nil
	}
	return global.File
}

func SetXOR(enable bool) {
	Global().SetXOR(enable)
}

func OpenGlobal(path string, cmode int, key int) error {
	if global != nil {
		global.Close()
		global = nil
	}
	cf, err := OpenFile(path, cmode, key)
	if err != nil {
		return err
	}
	global = cf
	return nil
}

func Flush() int {
	return Global().Flush()
}

func Close() error {
	return Global().Close()
}

func Seek(off int64, whence int) error {
	return Global().Seek(off, whence)
}

func Reader() io.Reader {
	return Global()
}

func Read(p []byte) (int, error) {
	return Global().Read(p)
}

func Writer() io.Writer {
	return Global()
}

func Write(p []byte) (int, error) {
	return Global().Write(p)
}

func ReadWrite(p []byte) (int, error) {
	return Global().ReadWrite(p)
}

func WriteU8(v byte) error {
	return Global().WriteU8(v)
}

func WriteU16(v uint16) error {
	return Global().WriteU16(v)
}

func WriteU32(v uint32) error {
	return Global().WriteU32(v)
}

func WriteString8(s string) error {
	return Global().WriteString8(s)
}

func WriteString32(s string) error {
	return Global().WriteString32(s)
}

func ReadWriteU16(v uint16) (uint16, error) {
	return Global().ReadWriteU16(v)
}

func ReadWriteU32(v uint32) (uint32, error) {
	return Global().ReadWriteU32(v)
}

func ReadU8() (byte, error) {
	return Global().ReadU8()
}

func ReadU16() (uint16, error) {
	return Global().ReadU16()
}

func ReadU32() (uint32, error) {
	return Global().ReadU32()
}

func ReadString8() (string, error) {
	return Global().ReadString8()
}

func ReadString32() (string, error) {
	return Global().ReadString8()
}

func ReadMaybeAlign(p []byte) error {
	return Global().ReadMaybeAlign(p)
}

func ReadAlignedU32() (uint32, error) {
	return Global().ReadAlignedU32()
}

func WriteChecksumAt(off int64) error {
	return Global().WriteChecksumAt(off)
}

func SectionStart() {
	Global().SectionStart()
}

func SectionEnd() {
	Global().SectionEnd()
}

func ReadWriteAlign() int {
	return Global().ReadWriteAlign()
}
