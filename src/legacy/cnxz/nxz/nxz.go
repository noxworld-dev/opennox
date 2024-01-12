package nxz

import (
	"encoding/binary"
	"errors"
	"io"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

// only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func DecompressFile(src, dst string) error {
	if src == "" {
		return errors.New("empty source path")
	}
	if dst == "" {
		return errors.New("empty destination path")
	}
	r, err := ifs.Open(src)
	if err != nil {
		return err
	}
	defer r.Close()
	fi, err := r.Stat()
	if err != nil {
		return err
	}
	srcSz := int32(fi.Size() - 4)
	var buf [4]byte
	if _, err = io.ReadFull(r, buf[:4]); err != nil {
		return err
	}
	dstSz := int32(binary.LittleEndian.Uint32(buf[:]))

	sbuf, sfree := alloc.Make([]byte{}, srcSz)
	defer sfree()
	_, err = io.ReadFull(r, sbuf)
	if err != nil {
		return err
	}

	dbuf, dfree := alloc.Make([]byte{}, dstSz)
	defer dfree()

	sleft := int32(srcSz)
	dleft := int32(dstSz)

	dec := NewDecoder()
	for sleft > 0 && dleft > 0 {
		if !dec.Decode(dbuf[dstSz-dleft:], sbuf[srcSz-sleft:], &dleft, &sleft) {
			break
		}
	}
	dec.Free()

	w, err := ifs.Create(dst)
	if err != nil {
		return err
	}
	defer w.Close()
	if _, err = w.Write(dbuf); err != nil {
		return err
	}
	return w.Close()
}

func compBufferSize(sz int) int {
	return sz + sz/2 + 32
}

func CompressFile(src, dst string) error {
	if src == "" {
		return errors.New("empty source path")
	}
	if dst == "" {
		return errors.New("empty destination path")
	}
	r, err := ifs.Open(src)
	if err != nil {
		return err
	}
	defer r.Close()
	fi, err := r.Stat()
	if err != nil {
		return err
	}

	srcSz := int(fi.Size())
	sbuf, sfree := alloc.Make([]byte{}, srcSz)
	defer sfree()
	if _, err = io.ReadFull(r, sbuf); err != nil {
		return err
	}

	dbuf, dfree := alloc.Make([]byte{}, compBufferSize(srcSz))
	defer dfree()

	enc := NewEncoder()
	cnt := 0
	for i := 0; i < srcSz; i += 500000 {
		v := srcSz - i
		if v > 500000 {
			v = 500000
		}
		cnt += enc.Encode(dbuf[cnt:], sbuf[i:], v)
	}
	enc.Free()

	w, err := ifs.Create(dst)
	if err != nil {
		return err
	}
	defer w.Close()

	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:4], uint32(srcSz))
	if _, err := w.Write(buf[:4]); err != nil {
		return err
	}
	if _, err := w.Write(dbuf[:cnt]); err != nil {
		return err
	}
	return w.Close()
}
