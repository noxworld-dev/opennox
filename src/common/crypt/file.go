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
	off  int64
	mode fileMode
}

// Reset internal state and assign a new underlying source for the file.
func (f *File) Reset(d io.ReadWriteSeeker) {
	f.f = d
	f.i = -1
	f.mode = fileRead
}

// Written returns a number of bytes written.
// It will differ from the actual number of written bytes unless Flush is called.
func (f *File) Written() int64 {
	return f.off
}

// Buffered returns a number of bytes buffered either by read or write operations.
func (f *File) Buffered() int {
	if f.mode == fileWrite {
		return f.i
	}
	if f.i < 0 || f.i >= Block {
		return 0
	}
	return Block - f.i
}

// Flush buffered data to the underlying writer. The data will be aligned to the block size.
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
	f.off += int64(Block - f.i)
	f.i = 0
	return err
}

// Close flushes the data. See Flush.
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
	f.off += int64(n)
	if f.i == len(f.buf) {
		if err := f.Flush(); err != nil {
			return 0, err
		}
	}
	return n, nil
}

// Write implements io.Writer.
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

// WriteString implements io.StringWriter.
func (f *File) WriteString(s string) (int, error) {
	return f.Write([]byte(s))
}

// WriteEmpty flushes the data (if any), which aligns it to a block size,
// and then writes an additional empty block without encryption.
func (f *File) WriteEmpty() error {
	if err := f.Flush(); err != nil {
		return err
	}
	f.i = 0
	f.mode = fileWrite
	var empty [Block]byte
	copy(f.buf[:], empty[:])
	_, err := f.f.Write(empty[:])
	f.off += Block
	return err
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

// Read implements io.Reader.
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

// Align the read or write offset to the nearest block boundary.
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

// ReadAligned is a special case of aligned read used by the engine.
func (f *File) ReadAligned(p []byte) (int, error) {
	if err := f.Align(); err != nil {
		return 0, err
	}
	var b [8]byte
	n, err := f.Read(b[:])
	if err != nil {
		return 0, err
	} else if n != 8 {
		return 0, io.ErrUnexpectedEOF
	}
	n = copy(p, b[:])
	return n, nil
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

// Seek implements io.Seeker.
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
	f.off = cur
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
