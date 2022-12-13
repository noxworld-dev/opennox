package cryptfile

import (
	"bytes"
	"encoding/binary"
	"io"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

var global struct {
	file       *binfile.Binfile
	mode       int
	rollingXOR int32
	noKey      bool
	xor        bool
	sect       []section
}

type section struct {
	Before uint32
	After  uint32
}

func GetMode() int {
	return global.mode
}

func GetFile() *binfile.Binfile {
	return global.file
}

func SetXOR(enable bool) {
	global.xor = enable
}

func Open(path string, cmode int, key int) error {
	if global.file != nil {
		Close()
	}
	SetXOR(false)
	global.noKey = key == -1
	global.rollingXOR = -1
	var fmode binfile.Mode
	global.mode = cmode
	if cmode == 1 {
		fmode = binfile.ReadOnly
	} else if cmode == 2 {
		global.mode = 0
		fmode = binfile.ReadWrite
	} else {
		fmode = binfile.WriteOnly
	}
	f, err := binfile.BinfileOpen(path, fmode)
	if err != nil {
		return err
	}
	global.file = f
	if err = f.SetKey(key); err != nil {
		return err
	}
	if cmode == 2 {
		if err := global.file.FileSeek(0, io.SeekEnd); err != nil {
			return err
		}
	}
	global.sect = global.sect[:0]
	return nil
}

func Flush() int {
	res, _ := global.file.FileFlush()
	return int(res)
}

func Close() {
	if global.file != nil {
		global.file.Close()
		SetXOR(false)
		global.file = nil
	}
}

func Seek(off int64, whence int) {
	global.file.FileSeek(off, whence)
}

func cryptXor(key byte, p []byte) {
	if len(p) == 0 {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

func crcAdd(a1 []byte) {
	if global.file == nil {
		return
	}
	v3 := global.rollingXOR
	for i := range a1 {
		v6 := int32(a1[i])
		// FIXME: remove reference to memmap
		result := int32(memmap.Uint32(0x581450, 7288+4*uintptr(v6^int32(byte(v3)))))
		v3 = result ^ (v3 >> 8)
		global.rollingXOR = int32(v3)
	}
	global.rollingXOR = int32(^v3)
}

func Reader() io.Reader {
	return reader{}
}

type reader struct{}

func (reader) Read(p []byte) (int, error) {
	return Read(p)
}

func Read(p []byte) (int, error) {
	if global.mode == 0 {
		panic("invalid file mode")
	}
	var (
		n   int
		err error
	)
	if global.xor {
		n, err = global.file.File.Read(p)
		cryptXor(126, p)
	} else {
		n, err = global.file.Read(p)
	}
	if n != 0 {
		crcAdd(p)
	}
	return n, err
}

func Writer() io.Writer {
	return writer{}
}

type writer struct{}

func (writer) Write(p []byte) (int, error) {
	return Write(p)
}

func Write(p []byte) (int, error) {
	if global.mode != 0 {
		panic("invalid file mode")
	}
	crcAdd(p)
	if global.xor {
		v2 := make([]byte, len(p))
		copy(v2, p)
		cryptXor(126, v2)
		return global.file.File.Write(v2)
	}
	return global.file.Write(p)
}

func ReadWrite(p []byte) (int, error) {
	if global.mode != 0 {
		return Read(p)
	}
	return Write(p)
}

func WriteU8(v byte) error {
	_, err := Write([]byte{v})
	return err
}

func WriteU16(v uint16) error {
	var buf [2]byte
	binary.LittleEndian.PutUint16(buf[:], v)
	_, err := Write(buf[:])
	return err
}

func WriteU32(v uint32) error {
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], v)
	_, err := Write(buf[:])
	return err
}

func WriteString8(s string) error {
	if len(s) > 0xff {
		s = s[:0xff]
	}
	if err := WriteU8(uint8(len(s))); err != nil {
		return err
	}
	_, err := Write([]byte(s))
	return err
}

func WriteString32(s string) error {
	if err := WriteU32(uint32(len(s))); err != nil {
		return err
	}
	_, err := Write([]byte(s))
	return err
}

func ReadWriteU16(v uint16) (uint16, error) {
	if global.mode != 0 {
		v2, err := ReadU16()
		if err != nil {
			return v, err
		}
		return v2, nil
	}
	err := WriteU16(v)
	return v, err
}

func ReadWriteU32(v uint32) (uint32, error) {
	if global.mode != 0 {
		v2, err := ReadU32()
		if err != nil {
			return v, err
		}
		return v2, nil
	}
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], v)
	_, err := Write(buf[:])
	return v, err
}

func ReadU8() (byte, error) {
	var buf [1]byte
	_, err := Read(buf[:])
	if err != nil {
		return 0, err
	}
	return buf[0], nil
}

func ReadU16() (uint16, error) {
	var buf [2]byte
	_, err := Read(buf[:])
	if err != nil {
		return 0, err
	}
	return binary.LittleEndian.Uint16(buf[:]), nil
}

func ReadU32() (uint32, error) {
	var buf [4]byte
	_, err := Read(buf[:])
	if err != nil {
		return 0, err
	}
	return binary.LittleEndian.Uint32(buf[:]), nil
}

func ReadString8() (string, error) {
	sz, err := ReadU8()
	if err != nil {
		return "", err
	} else if sz == 0 {
		return "", nil
	}
	buf := make([]byte, sz)
	_, err = Read(buf[:])
	if err != nil {
		return "", err
	}
	buf = bytes.TrimRight(buf, "\x00")
	return string(buf), nil
}

func ReadString32() (string, error) {
	sz, err := ReadU32()
	if err != nil {
		return "", err
	} else if sz == 0 {
		return "", nil
	}
	buf := make([]byte, sz)
	_, err = Read(buf[:])
	if err != nil {
		return "", err
	}
	buf = bytes.TrimRight(buf, "\x00")
	return string(buf), nil
}

func ReadMaybeAlign(p []byte) error {
	if global.mode != 1 {
		return nil
	}
	if global.xor {
		_, err := global.file.File.Read(p)
		cryptXor(126, p)
		return err
	}
	if global.noKey {
		_, err := global.file.Read(p)
		return err
	}
	_, err := global.file.ReadAligned(p)
	return err
}

func ReadAlignedU32() (uint32, error) {
	var buf [4]byte
	err := ReadMaybeAlign(buf[:])
	return binary.LittleEndian.Uint32(buf[:]), err
}

func WriteChecksumAt(off int64) {
	global.file.WriteUint32At(global.rollingXOR, off)
}

func SectionStart() {
	if global.mode == 0 {
		if global.xor {
			v2, _ := global.file.File.Seek(0, io.SeekCurrent)
			global.sect = append(global.sect, section{
				After: uint32(v2),
			})
			var b [4]byte
			binary.LittleEndian.PutUint32(b[:], uint32(v2))
			cryptXor(126, b[:])
			global.file.File.Write(b[:])
		} else {
			off1, _ := global.file.FileFlush()
			off2 := global.file.Written()
			global.sect = append(global.sect, section{
				Before: uint32(off1),
				After:  uint32(off2),
			})
		}
	}
}

func SectionEnd() {
	if global.mode != 0 {
		return
	}
	cnt := len(global.sect)
	offs := global.sect[cnt-1]
	global.sect = global.sect[:cnt-1]

	if global.xor {
		v1, _ := global.file.File.Seek(0, io.SeekCurrent)
		v3 := uint32(v1 - int64(offs.After) - 4)
		global.file.FileSeek(int64(offs.After), io.SeekStart)
		var b [4]byte
		binary.LittleEndian.PutUint32(b[:], v3)
		cryptXor(126, b[:])
		global.file.File.Write(b[:])
		global.file.FileSeek(v1, io.SeekStart)
	} else {
		v5 := global.file.Written()
		global.file.WriteUint32At(int32(v5-int64(offs.After)), int64(offs.Before))
	}
}

func ReadWriteAlign() int {
	var b [2]byte
	binary.LittleEndian.PutUint16(b[:], 1)
	ReadWrite(b[:2])
	if int16(binary.LittleEndian.Uint16(b[:])) > 1 {
		return 0
	}
	if v1 := 8 - global.file.Written()%8; v1 > 0 {
		var empty [8]byte
		ReadWrite(empty[:v1])
	}
	return 1
}
