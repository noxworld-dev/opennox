package nxz

import (
	"encoding/binary"
	"errors"
	"io"

	"github.com/noxworld-dev/opennox-lib/ifs"
)

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
	srcSz := int(fi.Size() - 4)
	var buf [4]byte
	if _, err = io.ReadFull(r, buf[:4]); err != nil {
		return err
	}
	dstSz := int(binary.LittleEndian.Uint32(buf[:]))

	sbuf := make([]byte, srcSz)
	_, err = io.ReadFull(r, sbuf)
	if err != nil {
		return err
	}

	dbuf := make([]byte, dstSz)

	dec := NewDecoder(sbuf)
	dstBuf := dbuf
	for {
		nDst, err := dec.Decode(dstBuf)
		if err == io.EOF {
			break
		} else if err != nil {
			dec.Free()
			return err
		}
		dstBuf = dstBuf[nDst:]
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

type Decoder struct {
	src  []byte
	err  error
	bits *bitReader
	rbuf [bufferSize]byte
	rind int
	data decoderData
}

type decoderData struct {
	tableData
	table2 [32]uint32
	table3 [tableSize]int16
}

func (d *decoderData) init() {
	d.tableData.init()
	d.table3 = nxzTable3
	d.table2 = nxzTable4
}

func (d *decoderData) free() {
	d.tableData.free()
}

type decoderRec struct {
	ind int16
	val int16
}

func NewDecoder(src []byte) *Decoder {
	dec := &Decoder{
		src: src,
	}
	dec.bits = newBitReader(dec.readByte)
	dec.data.init()
	return dec
}

func (dec *Decoder) Free() {
	if dec == nil {
		return
	}
	dec.data.free()
}

func (d *decoderData) update(arr []decoderRec) int {
	it := arr
	n := 0
	for i := range d.table {
		p := &d.table[i]
		it[0] = decoderRec{ind: int16(i), val: *p}
		it = it[1:]
		n += int(*p)
		*p /= 2
	}
	for i := 40; i > 0; i /= 3 {
		for j, cur := range arr {
			k := j + 1
			for ; k > i; k -= i {
				v := int(arr[k-i-1].val) - int(cur.val)
				if v == 0 {
					v = int(arr[k-i-1].ind) - int(cur.ind)
				}
				if v >= 0 {
					break
				}
				arr[k-1] = arr[k-i-1]
			}
			arr[k-1] = cur
		}
	}
	return n
}

func (dec *Decoder) Decode(dst []byte) (int, error) {
	if len(dec.src) == 0 {
		if dec.err != nil {
			return 0, dec.err
		}
		return 0, io.EOF
	}
	n, err := dec.decode(dst)
	dec.err = err
	return n, err
}
func (dec *Decoder) hasMore() bool {
	return len(dec.src) > 0
}
func (dec *Decoder) readByte() (byte, bool) {
	if len(dec.src) == 0 {
		return 0, false
	}
	b := dec.src[0]
	dec.src = dec.src[1:]
	return b, true
}
func (dec *Decoder) readBits(n int) uint {
	return dec.bits.ReadBits(n)
}
func (dec *Decoder) decode(dst []byte) (int, error) {
	var recs [tableSize]decoderRec
	di := 0
	dec.bits.Reset()
	for {
		if !dec.hasMore() {
			return 0, io.ErrUnexpectedEOF
		}
		ti := dec.readBits(4)
		n := int(dec.data.table2[2*ti+0])
		ti2 := int(dec.data.table2[2*ti+1])
		var op int
		if n == 0 {
			op = int(dec.data.table3[ti2])
		} else {
			v := dec.readBits(n)
			ind := ti2 + int(v)
			if ind >= tableSize {
				return 0, errors.New("wrong table index")
			}
			op = int(dec.data.table3[ind])
		}
		dec.data.table[op]++
		if op < 256 {
			if di >= len(dst) {
				return 0, io.ErrShortBuffer
			}
			dst[di] = byte(op)
			di++
			dec.rbuf[dec.rind%bufferSize] = byte(op)
			dec.rind++
			continue
		} else if op == 272 {
			dec.data.update(recs[:])
			for i := range dec.data.table3 {
				dec.data.table3[i] = recs[i].ind
			}
			boff := 0
			sval := 0
			it := dec.data.table2[:]
			for i := 0; i < 16; i++ {
				var bit int
				for {
					if dec.readBits(1) != 0 {
						break
					}
					bit++
				}
				boff += bit
				it[0] = uint32(boff)
				it[1] = uint32(sval)
				it = it[2:]
				sval += 1 << boff
			}
			continue
		}
		if op == 273 {
			return di, nil
		}
		var sz int
		if op < 264 {
			sz = op - 256
		} else {
			v29 := nxzTable1[op].v1
			v31 := int32(dec.readBits(int(v29)))
			sz = int(uint32(v31) + nxzTable1[op].v2)
		}
		sz += 4

		ti3 := int(dec.readBits(3))
		val1 := 0
		bn := int(nxzTable2[ti3+1].v1 + 9)
		if bn > 8 {
			bn = int(nxzTable2[ti3+1].v1 + 1)
			val1 = int(dec.readBits(8)) << bn
		}
		val2 := int(dec.readBits(bn))
		di2 := di
		off := int((nxzTable2[ti3+1].v2 << 9) + uint32(val1|val2))
		if di+sz > len(dst) {
			return 0, io.ErrShortBuffer
		}
		if ri := (dec.rind - off) % bufferSize; sz >= off {
			if ri+off <= bufferSize {
				copy(dst[di2:di2+off], dec.rbuf[ri:ri+off])
			} else {
				n := bufferSize - int(ri)
				copy(dst[di:di+n], dec.rbuf[ri:ri+n])
				n2 := off - n
				di2 = di + n
				copy(dst[di2:di2+n2], dec.rbuf[:n2])
			}
			if n := sz - off; n > 0 {
				for i := 0; i < n; i++ {
					dst[di+off+i] = dst[di+i]
				}
			}
		} else {
			if uint32(ri+sz) <= bufferSize {
				copy(dst[di:di+sz], dec.rbuf[ri:ri+sz])
			} else {
				n := bufferSize - int(ri)
				copy(dst[di:di+n], dec.rbuf[ri:ri+n])
				copy(dst[di+n:di+sz], dec.rbuf[:sz-n])
			}
		}
		if ri := dec.rind % bufferSize; ri+sz <= bufferSize {
			copy(dec.rbuf[ri:ri+sz], dst[di:di+sz])
		} else {
			n := bufferSize - ri
			copy(dec.rbuf[ri:ri+n], dst[di:di+n])
			n2 := sz - n
			di2 := di + n
			copy(dec.rbuf[:n2], dst[di2:di2+n2])
		}
		dec.rind += sz
		di += sz
	}
}
