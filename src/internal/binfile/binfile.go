package binfile

import (
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"

	crypt "github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/log"
	"golang.org/x/crypto/blowfish"
)

var (
	Log     = log.New("binfile")
	ciphers = make(map[int]*blowfish.Cipher)
)

type Mode int

const (
	ReadOnly  = Mode(0)
	WriteOnly = Mode(1)
	ReadWrite = Mode(2)
)

func BinfileOpen(path string, mode Mode) (*Binfile, error) {
	var (
		f   *os.File
		err error
	)
	switch mode {
	case ReadOnly:
		f, err = ifs.Open(path)
	case WriteOnly:
		f, err = ifs.Create(path)
	case ReadWrite:
		f, err = ifs.OpenFile(path, os.O_RDWR)
	default:
		return nil, fmt.Errorf("invalid mode: %d", mode)
	}
	if err != nil {
		return nil, err
	}
	file := &File{File: f}
	bin := &Binfile{File: file, mode: mode}
	file.Bin = bin
	return bin, nil
}

type Binfile struct {
	File  *File
	mode  Mode
	key   int
	write *crypt.Writer
	read  *crypt.Reader
	full  *crypt.File
}

func (f *Binfile) Mode() Mode {
	return f.mode
}

func (f *Binfile) Close() error {
	// it will call Binfile.close
	return f.File.Close()
}

func (f *Binfile) close() error {
	if f.read != nil {
		f.read = nil
	}
	var last error
	if f.write != nil {
		if err := f.write.Close(); err != nil {
			last = err
		}
		f.write = nil
	}
	if f.full != nil {
		if err := f.full.Close(); err != nil {
			last = err
		}
		f.full = nil
	}
	return last
}

func (f *Binfile) Written() int64 {
	if f.write != nil {
		return f.write.Written()
	} else if f.full != nil {
		return f.full.Written()
	}
	off, _ := f.Seek(0, io.SeekCurrent)
	return off
}

func (f *Binfile) Read(p []byte) (int, error) {
	if f.read != nil {
		return f.read.Read(p)
	} else if f.full != nil {
		return f.full.Read(p)
	}
	return f.File.Read(p)
}

func (f *Binfile) Write(p []byte) (int, error) {
	if f.write != nil {
		return f.write.Write(p)
	} else if f.full != nil {
		return f.full.Write(p)
	}
	return f.File.Write(p)
}

func (f *Binfile) Seek(off int64, whence int) (int64, error) {
	if f.read != nil {
		return f.read.Seek(off, whence)
	} else if f.write != nil {
		return 0, errors.New("seek on binfile writer")
	} else if f.full != nil {
		return f.full.Seek(off, whence)
	}
	return f.File.Seek(off, whence)
}

func (f *Binfile) flags() string {
	if f.read != nil {
		return "R"
	} else if f.write != nil {
		return "W"
	} else if f.full != nil {
		return "RW"
	}
	return ""
}

func (f *Binfile) SetKey(key int) error {
	if f == nil {
		return errors.New("nil file")
	}
	f.key = key
	if f.key < 0 {
		f.close()
		return nil
	}
	switch f.mode {
	case ReadOnly:
		cr, err := crypt.NewReader(f.File, f.key)
		if err != nil {
			return err
		}
		f.read = cr
	case WriteOnly:
		cw, err := crypt.NewWriter(f.File, f.key)
		if err != nil {
			return err
		}
		cw.NoZero = true
		f.write = cw
	case ReadWrite:
		cf, err := crypt.NewFile(f.File, f.key)
		if err != nil {
			return err
		}
		f.full = cf
	default:
		return fmt.Errorf("unsupported file mode: %d", f.mode)
	}
	return nil
}

func (f *Binfile) FileSeek(off int64, whence int) error {
	if f.mode != ReadOnly {
		// this is what nox_binfile_fseek_409050 does for some reason
		if off != 0 {
			return nil
		}
		// same, for some reason it resets the writer to the end
		whence = io.SeekEnd
	}
	_, err := f.Seek(off, whence)
	if err == io.EOF {
		err = nil
	}
	return err
}

func (f *Binfile) ReadAligned(buf []byte) (int, error) {
	if f.read != nil {
		return f.read.ReadAligned(buf)
	} else if f.full != nil {
		return f.full.ReadAligned(buf)
	}
	return 0, errors.New("cannot read on writer")
}
func (f *Binfile) FileFlush() (int64, error) {
	var flusher interface {
		WriteEmpty() error
		Flush() error
	}
	if f.write != nil {
		flusher = f.write
	} else if f.full != nil {
		flusher = f.full
	}
	err := flusher.Flush()
	res := f.Written()
	if err != nil {
		f.File.Err = err
		return res, err
	}
	err = flusher.WriteEmpty()
	if err != nil {
		f.File.Err = err
	}
	return res, err
}

func (f *Binfile) WriteUint32At(v uint32, off int64) error {
	if off < 0 {
		return nil
	}
	var buf [crypt.Block]byte
	binary.LittleEndian.PutUint32(buf[0:], v)
	c := ciphers[f.key]
	if c == nil {
		var err error
		c, err = crypt.NewCipher(f.key)
		if err != nil {
			return err
		}
		ciphers[f.key] = c
	}
	crypt.EncodeWith(c, buf[:])
	_, err := f.File.WriteAt(buf[:], off)
	f.File.Seek(0, io.SeekEnd)
	return err
}

func (f *Binfile) SkipLine() error {
	var buf [1]byte
	for {
		_, err := f.Read(buf[:])
		if err == io.EOF {
			break
		} else if err != nil {
			return err
		}
		if buf[0] != '\n' {
			break
		}
	}
	return nil
}
