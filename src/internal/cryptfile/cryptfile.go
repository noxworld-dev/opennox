package cryptfile

import (
	"bytes"
	"encoding/binary"
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

var crcTable = [256]uint32{
	0x0, 0x77073096, 0xee0e612c, 0x990951ba,
	0x76dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0xedb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x9b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
	0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
	0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x1db7106, 0x98d220bc, 0xefd5102a,
	0x71b18589, 0x6b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0xf00f934, 0x9609a88e, 0xe10e9818,
	0x7f6a0dbb, 0x86d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
	0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
	0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
	0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
	0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x3b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x4db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0xd6d6a3e, 0x7a6a5aa8,
	0xe40ecf0b, 0x9309ff9d, 0xa00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
	0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
	0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
	0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
	0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x26d930a,
	0x9c0906a9, 0xeb0e363f, 0x72076785, 0x5005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0xcb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0xbdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
	0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
	0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
	0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
	0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
}
