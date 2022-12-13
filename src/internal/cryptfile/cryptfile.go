package cryptfile

import (
	"bytes"
	"encoding/binary"
	"hash/crc32"
	"io"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

type section struct {
	Before uint32
	After  uint32
}

type Mode int

const (
	WriteOnly = Mode(0)
	ReadOnly  = Mode(1)
	Append    = Mode(2)
)

func OpenFile(path string, cmode Mode, key int) (*CryptFile, error) {
	var fmode binfile.Mode
	switch cmode {
	case WriteOnly:
		fmode = binfile.WriteOnly
	case ReadOnly:
		fmode = binfile.ReadOnly
	case Append:
		fmode = binfile.ReadWrite
	}
	f, err := binfile.BinfileOpen(path, fmode)
	if err != nil {
		return nil, err
	}
	if err = f.SetKey(key); err != nil {
		_ = f.Close()
		return nil, err
	}
	if cmode == Append {
		if err := f.FileSeek(0, io.SeekEnd); err != nil {
			_ = f.Close()
			return nil, err
		}
	}
	return &CryptFile{
		File:       f,
		xor:        false,
		noKey:      key == -1,
		rollingXOR: -1,
		readonly:   cmode == ReadOnly,
	}, nil
}

type CryptFile struct {
	File       *binfile.Binfile
	readonly   bool
	rollingXOR int32
	noKey      bool
	xor        bool
	sect       []section
}

func (f *CryptFile) ReadOnly() bool {
	if f == nil {
		return false
	}
	return f.readonly
}

func (f *CryptFile) SetXOR(enable bool) {
	f.xor = enable
}

func (f *CryptFile) Flush() int {
	if f == nil {
		return 0
	}
	res, _ := f.File.FileFlush()
	return int(res)
}

func (f *CryptFile) Close() error {
	if f == nil || f.File == nil {
		return nil
	}
	err := f.File.Close()
	f.xor = false
	f.File = nil
	return err
}

func (f *CryptFile) Seek(off int64, whence int) error {
	return f.File.FileSeek(off, whence)
}

func cryptXor(key byte, p []byte) {
	if len(p) == 0 {
		return
	}
	for i := range p {
		p[i] ^= key
	}
}

func (f *CryptFile) crcAdd(p []byte) {
	if f == nil || f.File == nil {
		return
	}
	sum := f.rollingXOR
	for i := range p {
		ds := int32(crcTable[byte(sum)^p[i]])
		sum = ds ^ (sum >> 8)
		f.rollingXOR = sum
	}
	f.rollingXOR = ^sum
}

func (f *CryptFile) Read(p []byte) (int, error) {
	if !f.readonly {
		panic("invalid file mode")
	}
	var (
		n   int
		err error
	)
	if f.xor {
		n, err = f.File.File.Read(p)
		cryptXor(126, p)
	} else {
		n, err = f.File.Read(p)
	}
	if n != 0 {
		f.crcAdd(p)
	}
	return n, err
}

func (f *CryptFile) Write(p []byte) (int, error) {
	if f.readonly {
		panic("invalid file mode")
	}
	f.crcAdd(p)
	if f.xor {
		v2 := make([]byte, len(p))
		copy(v2, p)
		cryptXor(126, v2)
		return f.File.File.Write(v2)
	}
	return f.File.Write(p)
}

func (f *CryptFile) ReadWrite(p []byte) (int, error) {
	if f.readonly {
		return f.Read(p)
	}
	return f.Write(p)
}

func (f *CryptFile) WriteU8(v byte) error {
	_, err := f.Write([]byte{v})
	return err
}

func (f *CryptFile) WriteU16(v uint16) error {
	var buf [2]byte
	binary.LittleEndian.PutUint16(buf[:], v)
	_, err := f.Write(buf[:])
	return err
}

func (f *CryptFile) WriteU32(v uint32) error {
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], v)
	_, err := f.Write(buf[:])
	return err
}

func (f *CryptFile) WriteString8(s string) error {
	if len(s) > 0xff {
		s = s[:0xff]
	}
	if err := f.WriteU8(uint8(len(s))); err != nil {
		return err
	}
	_, err := f.Write([]byte(s))
	return err
}

func (f *CryptFile) WriteString32(s string) error {
	if err := f.WriteU32(uint32(len(s))); err != nil {
		return err
	}
	_, err := f.Write([]byte(s))
	return err
}

func (f *CryptFile) ReadU8() (byte, error) {
	var buf [1]byte
	_, err := f.Read(buf[:])
	if err != nil {
		return 0, err
	}
	return buf[0], nil
}

func (f *CryptFile) ReadU16() (uint16, error) {
	var buf [2]byte
	_, err := f.Read(buf[:])
	if err != nil {
		return 0, err
	}
	return binary.LittleEndian.Uint16(buf[:]), nil
}

func (f *CryptFile) ReadU32() (uint32, error) {
	var buf [4]byte
	_, err := f.Read(buf[:])
	if err != nil {
		return 0, err
	}
	return binary.LittleEndian.Uint32(buf[:]), nil
}

func (f *CryptFile) ReadString8() (string, error) {
	sz, err := f.ReadU8()
	if err != nil {
		return "", err
	} else if sz == 0 {
		return "", nil
	}
	buf := make([]byte, sz)
	_, err = f.Read(buf[:])
	if err != nil {
		return "", err
	}
	buf = bytes.TrimRight(buf, "\x00")
	return string(buf), nil
}

func (f *CryptFile) ReadString32() (string, error) {
	sz, err := f.ReadU32()
	if err != nil {
		return "", err
	} else if sz == 0 {
		return "", nil
	}
	buf := make([]byte, sz)
	_, err = f.Read(buf[:])
	if err != nil {
		return "", err
	}
	buf = bytes.TrimRight(buf, "\x00")
	return string(buf), nil
}

func (f *CryptFile) ReadWriteU16(v uint16) (uint16, error) {
	if f.readonly {
		v2, err := f.ReadU16()
		if err != nil {
			return v, err
		}
		return v2, nil
	}
	err := f.WriteU16(v)
	return v, err
}

func (f *CryptFile) ReadWriteU32(v uint32) (uint32, error) {
	if f.readonly {
		v2, err := f.ReadU32()
		if err != nil {
			return v, err
		}
		return v2, nil
	}
	err := f.WriteU32(v)
	return v, err
}

func (f *CryptFile) ReadMaybeAlign(p []byte) error {
	if !f.readonly {
		return nil
	}
	if f.xor {
		_, err := f.File.File.Read(p)
		cryptXor(126, p)
		return err
	}
	if f.noKey {
		_, err := f.File.Read(p)
		return err
	}
	_, err := f.File.ReadAligned(p)
	return err
}

func (f *CryptFile) ReadAlignedU32() (uint32, error) {
	var buf [4]byte
	err := f.ReadMaybeAlign(buf[:])
	return binary.LittleEndian.Uint32(buf[:]), err
}

func (f *CryptFile) ReadWriteAlign() int {
	var b [2]byte
	binary.LittleEndian.PutUint16(b[:], 1)
	f.ReadWrite(b[:2])
	if int16(binary.LittleEndian.Uint16(b[:])) > 1 {
		return 0
	}
	if v1 := 8 - f.File.Written()%8; v1 > 0 {
		var empty [8]byte
		f.ReadWrite(empty[:v1])
	}
	return 1
}

func (f *CryptFile) WriteChecksumAt(off int64) error {
	return f.File.WriteUint32At(f.rollingXOR, off)
}

func (f *CryptFile) SectionStart() {
	if f.readonly {
		return
	}
	if f.xor {
		v2, _ := f.File.File.Seek(0, io.SeekCurrent)
		f.sect = append(f.sect, section{
			After: uint32(v2),
		})
		var b [4]byte
		binary.LittleEndian.PutUint32(b[:], uint32(v2))
		cryptXor(126, b[:])
		f.File.File.Write(b[:])
	} else {
		off1, _ := f.File.FileFlush()
		off2 := f.File.Written()
		f.sect = append(f.sect, section{
			Before: uint32(off1),
			After:  uint32(off2),
		})
	}
}

func (f *CryptFile) SectionEnd() {
	if f.readonly {
		return
	}
	cnt := len(f.sect)
	offs := f.sect[cnt-1]
	f.sect = f.sect[:cnt-1]

	if f.xor {
		off, _ := f.File.File.Seek(0, io.SeekCurrent)
		off2 := uint32(off - int64(offs.After) - 4)
		f.File.FileSeek(int64(offs.After), io.SeekStart)
		var b [4]byte
		binary.LittleEndian.PutUint32(b[:], off2)
		cryptXor(126, b[:])
		f.File.File.Write(b[:])
		f.File.FileSeek(off, io.SeekStart)
	} else {
		n := f.File.Written()
		f.File.WriteUint32At(int32(n-int64(offs.After)), int64(offs.Before))
	}
}

var crcTable = crc32.MakeTable(crc32.IEEE)
