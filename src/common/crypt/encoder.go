package crypt

import (
	"io"
)

// Encode a buffer with a given key.
func Encode(p []byte, key int) error {
	return crypt(p, key, false)
}

// Decode a buffer with a given key.
func Decode(p []byte, key int) error {
	return crypt(p, key, true)
}

func crypt(p []byte, key int, reverse bool) error {
	if len(p)%Block != 0 {
		return errInvalidSize
	}
	e, err := newCoder(key, reverse)
	if err != nil {
		return err
	}
	for i := 0; i < len(p); i += Block {
		e.EncodeBlock(p[i : i+Block])
	}
	return nil
}

// NewReader creates a decoder with a given key and byte stream.
func NewReader(r io.Reader, key int) (*Reader, error) {
	e, err := newCoder(key, true)
	if err != nil {
		return nil, err
	}
	return &Reader{
		r: r,
		e: e,
		i: -1,
	}, nil
}

type Reader struct {
	r   io.Reader
	e   *coder
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

func (r *Reader) read(p []byte) (int, error) {
	if r.i < 0 || r.i >= Block {
		_, err := io.ReadFull(r.r, r.buf[:])
		if err != nil {
			return 0, err
		}
		r.i = 0
		r.e.EncodeBlock(r.buf[:])
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
