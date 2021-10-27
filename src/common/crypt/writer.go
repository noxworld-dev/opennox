package crypt

import (
	"io"

	"golang.org/x/crypto/blowfish"
)

// NewWriter creates an encoder with a given key and a destination writer.
func NewWriter(w io.Writer, key int) (*Writer, error) {
	c, err := NewCipher(key)
	if err != nil {
		return nil, err
	}
	wr := &Writer{c: c}
	wr.Reset(w)
	return wr, nil
}

type Writer struct {
	w   io.Writer
	c   *blowfish.Cipher
	buf [Block]byte
	n   int
}

func (w *Writer) Reset(d io.Writer) {
	w.w = d
	w.n = 0
}

func (w *Writer) flush() error {
	w.c.Encrypt(w.buf[:], w.buf[:])
	_, err := w.w.Write(w.buf[:])
	w.n = 0
	return err
}

func (w *Writer) Flush() error {
	if w.n == 0 {
		return nil
	}
	if w.n != len(w.buf) {
		var empty [Block]byte
		copy(w.buf[w.n:], empty[:])
	}
	return w.flush()
}

func (w *Writer) Close() error {
	return w.Flush()
}

func (w *Writer) write(p []byte) (int, error) {
	n := copy(w.buf[w.n:], p)
	w.n += n
	if w.n == len(w.buf) {
		if err := w.flush(); err != nil {
			return 0, err
		}
	}
	return n, nil
}

func (w *Writer) Write(p []byte) (int, error) {
	total := 0
	for len(p) > 0 {
		n, err := w.write(p)
		total += n
		if err != nil {
			return total, err
		}
		p = p[n:]
	}
	return total, nil
}
