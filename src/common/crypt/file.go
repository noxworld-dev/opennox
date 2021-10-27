package crypt

import (
	"io"

	"golang.org/x/crypto/blowfish"
)

// NewFile creates a file that support encode/decode and seek operations.
func NewFile(f io.ReadWriteSeeker, key int) (*File, error) {
	c, err := NewCipher(key)
	if err != nil {
		return nil, err
	}
	cf := &File{c: c}
	cf.Reset(f)
	return cf, nil
}

type fileMode int

const (
	fileRead = fileMode(iota)
	fileWrite
)

type File struct {
	f    io.ReadWriteSeeker
	c    *blowfish.Cipher
	buf  [Block]byte
	i    int
	mode fileMode
}

func (f *File) Reset(d io.ReadWriteSeeker) {
	f.f = d
	f.i = -1
	f.mode = fileRead
}

func (f *File) Buffered() int {
	if f.mode == fileWrite {
		return f.i
	}
	if f.i < 0 || f.i >= Block {
		return 0
	}
	return Block - f.i
}

func (f *File) Flush() error {
	if f.mode != fileWrite {
		return nil
	}
	if f.i <= 0 {
		return nil
	}
	f.c.Encrypt(f.buf[:], f.buf[:])
	_, err := f.f.Write(f.buf[:])
	f.buf = [8]byte{}
	f.i = 0
	return err
}

func (f *File) Close() error {
	return f.Flush()
}

func (f *File) write(p []byte) (int, error) {
	if f.mode == fileRead {
		if err := f.switchWrite(); err != nil {
			return 0, err
		}
	}
	n := copy(f.buf[f.i:], p)
	f.i += n
	if f.i == len(f.buf) {
		if err := f.Flush(); err != nil {
			return 0, err
		}
	}
	return n, nil
}

func (f *File) Write(p []byte) (int, error) {
	total := 0
	for len(p) > 0 {
		n, err := f.write(p)
		total += n
		if err != nil {
			return total, err
		}
		p = p[n:]
	}
	return total, nil
}

func (f *File) WriteString(s string) (int, error) {
	return f.Write([]byte(s))
}

func (f *File) switchWrite() error {
	if f.mode == fileWrite {
		return nil
	}
	end := false
	if f.i < 0 || f.i >= Block {
		err := f.readNext()
		if err == io.EOF {
			f.i = 0
			f.buf = [8]byte{}
			end = true
		} else if err != nil {
			return err
		}
	}
	if !end {
		_, err := f.f.Seek(-Block, io.SeekCurrent)
		if err != nil {
			return err
		}
	}
	f.mode = fileWrite
	return nil
}

func (f *File) switchRead() error {
	if f.mode == fileRead {
		return nil
	}
	// safe old position since Flush may change it
	cur, err := f.offset()
	if err != nil {
		return err
	}
	if err = f.Flush(); err != nil {
		return err
	}
	f.i = -1
	f.mode = fileRead
	// seek back to the previous position
	_, err = f.Seek(cur, io.SeekStart)
	if err != nil {
		return err
	}
	return nil
}

func (f *File) readNext() error {
	if f.mode == fileWrite {
		if err := f.switchRead(); err != nil {
			return err
		}
		if f.i >= 0 {
			return nil
		}
	}
	_, err := io.ReadFull(f.f, f.buf[:])
	if err != nil {
		f.i = -1
		return err
	}
	f.i = 0
	f.c.Decrypt(f.buf[:], f.buf[:])
	return nil
}

func (f *File) read(p []byte) (int, error) {
	if f.mode != fileRead || f.i < 0 || f.i >= Block {
		if err := f.readNext(); err != nil {
			return 0, err
		}
	}
	n := copy(p, f.buf[f.i:])
	f.i += n
	return n, nil
}

func (f *File) Read(p []byte) (int, error) {
	total := 0
	for len(p) > 0 {
		n, err := f.read(p)
		total += n
		if err != nil {
			return total, err
		}
		p = p[n:]
	}
	return total, nil
}

func (f *File) Align() error {
	if f.mode == fileWrite {
		return f.Flush()
	}
	if n := f.Buffered(); n%Block != 0 {
		if err := f.readNext(); err != nil {
			return err
		}
	}
	return nil
}

func (f *File) offset() (int64, error) {
	cur, err := f.f.Seek(0, io.SeekCurrent)
	if err != nil {
		return 0, err
	}
	if f.i >= 0 {
		cur += int64(f.i)
	}
	return cur, nil
}

func (f *File) Seek(off int64, whence int) (int64, error) {
	if off == 0 && whence == io.SeekCurrent {
		return f.offset()
	}
	if f.mode == fileWrite {
		if err := f.switchRead(); err != nil {
			return 0, err
		}
	}
	if whence == io.SeekCurrent {
		off -= int64(f.Buffered())
	}
	cur, err := f.f.Seek(off, whence)
	f.i = -1
	if err != nil {
		return 0, err
	}
	rem := cur % Block
	if rem == 0 {
		return cur, nil
	}
	_, err = f.f.Seek(-rem, io.SeekCurrent)
	if err != nil {
		return 0, err
	}
	err = f.readNext()
	if err != nil {
		return 0, err
	}
	f.i = int(rem)
	return cur, nil
}
