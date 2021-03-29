package things

import (
	"bufio"
	"encoding/binary"
	"errors"
	"fmt"
	"io"

	"nox/common/crypt"
	"nox/common/fs"
)

var endiness = binary.LittleEndian

type Data struct {
	Images []Image `json:"images,omitempty"`
	Things []Thing `json:"things,omitempty"`
}

type File struct {
	f  io.ReadSeeker
	c  io.Closer
	r  *crypt.Reader
	br *bufio.Reader
}

func OpenReader(f io.ReadSeeker, key int) (*File, error) {
	if key == 0 {
		key = crypt.ThingBin
	}
	r, err := crypt.NewReader(f, key)
	if err != nil {
		return nil, err
	}
	return &File{
		f: f, r: r,
		br: bufio.NewReader(r),
	}, nil
}

func Open(path string) (*File, error) {
	key, ok := crypt.KeyForFile(path)
	if !ok {
		return nil, errors.New("unsupported things file")
	}
	f, err := fs.Open(path)
	if err != nil {
		return nil, err
	}
	tf, err := OpenReader(f, key)
	if err != nil {
		_ = f.Close()
		return nil, err
	}
	tf.c = f
	return tf, nil
}

func (f *File) Close() error {
	if f.c == nil {
		return nil
	}
	return f.c.Close()
}

func (f *File) offset() (int64, error) {
	off, err := f.f.Seek(0, io.SeekCurrent)
	if err != nil {
		return 0, err
	}
	return off - int64(f.br.Buffered()+f.r.Buffered()), nil
}

func (f *File) seek(off int64, whence int) error {
	if whence == io.SeekCurrent {
		cur, err := f.offset()
		if err != nil {
			return err
		}
		off = cur + off
		whence = io.SeekStart
	}
	_, err := f.f.Seek(off, whence)
	if err != nil {
		return err
	}
	f.r.Reset(f.f)
	f.br.Reset(f.r)
	return nil
}

func (f *File) read(p []byte) (int, error) {
	return io.ReadFull(f.br, p)
}

func (f *File) skip(n int) error {
	_, err := f.br.Discard(n)
	return err
}

func (f *File) skipBytes8() error {
	sz, err := f.readU8()
	if err != nil {
		return err
	}
	return f.skip(int(sz))
}

func (f *File) skipBytes16() error {
	sz, err := f.readU16()
	if err != nil {
		return err
	}
	return f.skip(int(sz))
}

func (f *File) readSect() (string, error) {
	var sect [4]byte
	_, err := f.read(sect[:])
	if err != nil {
		return "", err
	}
	swap4(sect[:])
	return string(sect[:]), nil
}

func (f *File) checkEND() error {
	var sect [4]byte
	_, err := f.read(sect[:])
	if err == io.EOF {
		return io.ErrUnexpectedEOF
	} else if err != nil {
		return err
	}
	swap4(sect[:])
	if s := string(sect[:]); s != "END " {
		return fmt.Errorf("expected END, got section: %q", s)
	}
	return nil
}

func (f *File) checkZeros() error {
	b, err := f.br.ReadByte()
	if err == io.EOF {
		return nil
	} else if err != nil {
		return err
	}
	if b != 0 {
		return fmt.Errorf("expected zero bytes, got 0x%x", b)
	}
	return nil
}

func (f *File) readU8() (byte, error) {
	b, err := f.br.ReadByte()
	if err == io.EOF {
		return 0, io.ErrUnexpectedEOF
	} else if err != nil {
		return 0, err
	}
	return b, nil
}

func (f *File) readI8() (int8, error) {
	v, err := f.readU8()
	if err != nil {
		return 0, err
	}
	return int8(v), nil
}

func (f *File) readU16() (uint16, error) {
	var b [2]byte
	_, err := f.read(b[:])
	if err == io.EOF {
		return 0, io.ErrUnexpectedEOF
	} else if err != nil {
		return 0, err
	}
	return endiness.Uint16(b[:]), nil
}

func (f *File) readI16() (int16, error) {
	v, err := f.readU16()
	if err != nil {
		return 0, err
	}
	return int16(v), nil
}

func (f *File) readU32() (uint32, error) {
	var b [4]byte
	_, err := f.read(b[:])
	if err == io.EOF {
		return 0, io.ErrUnexpectedEOF
	} else if err != nil {
		return 0, err
	}
	return endiness.Uint32(b[:]), nil
}

func (f *File) readI32() (int32, error) {
	v, err := f.readU32()
	if err != nil {
		return 0, err
	}
	return int32(v), nil
}

func (f *File) readU64align() (uint64, error) {
	off, err := f.offset()
	if err != nil {
		return 0, err
	}
	if over := int(off % 8); over != 0 {
		if err := f.skip(8 - over); err != nil {
			return 0, err
		}
	}
	var b [8]byte
	_, err = f.read(b[:])
	if err == io.EOF {
		return 0, io.ErrUnexpectedEOF
	} else if err != nil {
		return 0, err
	}
	return endiness.Uint64(b[:]), nil
}

func (f *File) readBytes8() ([]byte, error) {
	sz, err := f.readU8()
	if err != nil {
		return nil, err
	}
	buf := make([]byte, sz)
	_, err = f.read(buf)
	return buf, err
}

func (f *File) readString8() (string, error) {
	b, err := f.readBytes8()
	if err != nil {
		return "", err
	}
	return string(b), nil
}

func swap4(p []byte) {
	p[0], p[1], p[2], p[3] = p[3], p[2], p[1], p[0]
}

func (f *File) skipUntil(exp string) (bool, error) {
	for {
		sect, err := f.readSect()
		if err == io.EOF {
			return false, nil
		} else if err != nil {
			return false, err
		}
		if exp == sect {
			return true, nil
		}
		switch sect {
		case "FLOR":
			if err := f.skipFLOR(); err != nil {
				return false, err
			}
		case "EDGE":
			if err := f.skipEDGE(); err != nil {
				return false, err
			}
		case "WALL":
			if err := f.skipWALL(); err != nil {
				return false, err
			}
		case "AUD ":
			if err := f.skipAUD(); err != nil {
				return false, err
			}
		case "AVNT":
			if err := f.skipAVNT(); err != nil {
				return false, err
			}
		case "SPEL":
			if err := f.skipSPEL(); err != nil {
				return false, err
			}
		case "ABIL":
			if err := f.skipABIL(); err != nil {
				return false, err
			}
		case "IMAG":
			if err := f.skipIMAG(); err != nil {
				return false, err
			}
		case "THNG":
			if err := f.skipTHNG(); err != nil {
				return false, err
			}
		case "\x00\x00\x00\x00":
			// padding
			err := f.checkZeros()
			return false, err
		default:
			off, _ := f.offset()
			return false, fmt.Errorf("unsupported section: %q (at %d)", sect, off)
		}
	}
}

func (f *File) ReadAll() (*Data, error) {
	if err := f.seek(0, io.SeekStart); err != nil {
		return nil, err
	}
	var data Data
	for {
		sect, err := f.readSect()
		if err == io.EOF {
			return &data, nil
		} else if err != nil {
			return &data, err
		}
		switch sect {
		case "FLOR":
			// TODO
			if err := f.skipFLOR(); err != nil {
				return &data, err
			}
		case "EDGE":
			// TODO
			if err := f.skipEDGE(); err != nil {
				return &data, err
			}
		case "WALL":
			// TODO
			if err := f.skipWALL(); err != nil {
				return &data, err
			}
		case "AUD ":
			// TODO
			if err := f.skipAUD(); err != nil {
				return &data, err
			}
		case "AVNT":
			// TODO
			if err := f.skipAVNT(); err != nil {
				return &data, err
			}
		case "SPEL":
			// TODO
			if err := f.skipSPEL(); err != nil {
				return &data, err
			}
		case "ABIL":
			// TODO
			if err := f.skipABIL(); err != nil {
				return &data, err
			}
		case "IMAG":
			list, err := f.readImages()
			if err != nil {
				return &data, err
			}
			data.Images = append(data.Images, list...)
		case "THNG":
			th, err := f.readThing()
			if err != nil {
				return &data, err
			}
			data.Things = append(data.Things, *th)
		case "\x00\x00\x00\x00":
			// padding
			err := f.checkZeros()
			if err != nil {
				return &data, err
			}
			return &data, nil
		default:
			off, _ := f.offset()
			return &data, fmt.Errorf("unsupported section: %q (at %d)", sect, off)
		}
	}
}
