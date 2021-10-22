package crypt

import (
	"io"

	"golang.org/x/crypto/blowfish"
)

// NewReader creates a decoder with a given key and byte stream.
func NewReader(r io.Reader, key int) (*Reader, error) {
	c, err := NewCipher(key)
	if err != nil {
		return nil, err
	}
	return &Reader{
		r: r,
		c: c,
		i: -1,
	}, nil
}

type Reader struct {
	r   io.Reader
	c   *blowfish.Cipher
	buf [Block]byte
	i   int
}

func (r *Reader) Reset(s io.Reader) {
	r.r = s
	r.i = -1
}

func (r *Reader) Buffered() int {
	if r.i < 0 || r.i >= Block {
		return 0
	}
	return Block - r.i
}

func (r *Reader) readNext() error {
	_, err := io.ReadFull(r.r, r.buf[:])
	if err != nil {
		return err
	}
	r.i = 0
	r.c.Decrypt(r.buf[:], r.buf[:])
	return nil
}

func (r *Reader) read(p []byte) (int, error) {
	if r.i < 0 || r.i >= Block {
		if err := r.readNext(); err != nil {
			return 0, err
		}
	}
	n := copy(p, r.buf[r.i:])
	r.i += n
	return n, nil
}

func (r *Reader) Read(p []byte) (int, error) {
	total := 0
	for len(p) > 0 {
		n, err := r.read(p)
		total += n
		if err != nil {
			return total, err
		}
		p = p[n:]
	}
	return total, nil
}

func (r *Reader) Align() error {
	if n := r.Buffered(); n%Block != 0 {
		if err := r.readNext(); err != nil {
			return err
		}
	}
	return nil
}

func (r *Reader) ReadAligned(p []byte) (int, error) {
	if err := r.Align(); err != nil {
		return 0, err
	}
	var b [8]byte
	n, err := r.Read(b[:])
	if err != nil {
		return 0, err
	} else if n != 8 {
		return 0, io.ErrUnexpectedEOF
	}
	n = copy(p, b[:])
	return n, nil
}
