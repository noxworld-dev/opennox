package nxz

import (
	"errors"
	"io"
	"math"
)

type Decoder struct {
	src1    []byte
	err     error
	buf0    [bufferSize]byte
	field4  uint32
	data8   decoderData
	bitsVal uint
	bitsCnt int
}

type decoderData struct {
	field0   commonData
	field4   [32]uint32
	field132 [tableSize]int16
}

type decoderRec struct {
	ind0 int16
	val2 int16
}

func NewDecoder(src []byte) *Decoder {
	dec := &Decoder{
		src1: src,
	}
	initDecData(&dec.data8)
	return dec
}

func initDecData(d *decoderData) {
	initCommon(&d.field0)
	d.field132 = nxz_table_3
	d.field4 = nxz_table_4
}

func (dec *Decoder) Free() {
	if dec == nil {
		return
	}
	freeDecData(&dec.data8)
}

func freeDecData(d *decoderData) {
	freeCommon(&d.field0)
}

func sub57DDE0(arr []decoderRec) {
	for i := 40; i > 0; i /= 3 {
		j := i + 1
		v11 := i + 1
		if i+1 > len(arr) {
			continue
		}
		for {
			v6 := j
			v10 := j
			val := arr[j-1]
			if j > i {
				for {
					v8 := int32(arr[v6-i-1].val2) - int32(val.val2)
					if v8 == 0 {
						v8 = int32(arr[v6-i-1].ind0) - int32(val.ind0)
					}
					if v8 >= 0 {
						break
					}
					arr[v6-1] = arr[v6-i-1]
					v6 -= i
					v10 -= i
					if v10 <= i {
						break
					}
				}
				j = v11
			}
			j++
			arr[v10-1] = val
			v11 = j
			if j > len(arr) {
				break
			}
		}
	}
}
func sub57DEA0(d *decoderData, arr []decoderRec) int {
	it := arr
	n := 0
	for i := range d.field0.field0 {
		p := &d.field0.field0[i]
		it[0] = decoderRec{ind0: int16(i), val2: *p}
		it = it[1:]
		n += int(*p)
		*p /= 2
	}
	sub57DDE0(arr[:tableSize])
	return n
}
func (dec *Decoder) Decode(dst []byte) (int, error) {
	if len(dec.src1) == 0 {
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
	return len(dec.src1) > 0
}
func (dec *Decoder) readByte() (byte, bool) {
	if len(dec.src1) == 0 {
		return 0, false
	}
	b := dec.src1[0]
	dec.src1 = dec.src1[1:]
	return b, true
}
func (dec *Decoder) readBits(n int) uint {
	for dec.bitsCnt < n {
		b, ok := dec.readByte()
		if !ok {
			dec.bitsCnt = 0
			return math.MaxUint
		}
		dec.bitsVal |= uint(b) << (uintSize - 8 - dec.bitsCnt)
		dec.bitsCnt += 8
	}
	val := dec.bitsVal >> (uintSize - n)
	dec.bitsVal <<= n
	dec.bitsCnt -= n
	return val
}
func (dec *Decoder) readBits4() int {
	return int(dec.readBits(4))
}
func (dec *Decoder) decode(dst []byte) (int, error) {
	var recs [tableSize]decoderRec
	di := 0
	dec.bitsCnt = 0
	for {
		if !dec.hasMore() {
			return 0, io.ErrUnexpectedEOF
		}
		v9 := dec.readBits4()
		var op int
		if n := int(dec.data8.field4[2*v9]); n == 0 {
			op = int(dec.data8.field132[dec.data8.field4[v9*2+1]])
		} else {
			v15 := dec.readBits(n)
			ind := int(uint32(v15) + dec.data8.field4[v9*2+1])
			if ind >= tableSize {
				return 0, errors.New("wrong table index")
			}
			op = int(dec.data8.field132[ind])
		}
		dec.data8.field0.field0[op]++
		if op < 256 {
			if di >= len(dst) {
				return 0, io.ErrShortBuffer
			}
			dst[di] = uint8(int8(op))
			di++
			dec.buf0[dec.field4%bufferSize] = uint8(int8(op))
			dec.field4++
			continue
		} else if op == 272 {
			sub57DEA0(&dec.data8, recs[:])
			for i := range dec.data8.field132 {
				dec.data8.field132[i] = recs[i].ind0
			}
			v22 := 0
			v70 := 0
			it := dec.data8.field4[:]
			for i := 0; i < 16; i++ {
				var ind int
				for {
					if dec.readBits(1) != 0 {
						break
					}
					ind++
				}
				v22 += ind
				it[0] = uint32(v22)
				it[1] = uint32(v70)
				it = it[2:]
				v70 += 1 << v22
			}
			continue
		}
		if op == 273 {
			return di, nil
		}
		var v28 int
		if op < 264 {
			v28 = op - 256
		} else {
			v29 := nxz_table_1[op].v1
			v31 := int32(dec.readBits(int(v29)))
			v28 = int(uint32(v31) + nxz_table_1[op].v2)
		}
		v67 := v28
		v71 := int32(dec.readBits(3))
		v65 := 0
		v37 := int32(nxz_table_2[v71+1].v1 + 9)
		if v37 > 8 {
			v37 = int32(nxz_table_2[v71+1].v1 + 1)
			v65 = int(dec.readBits(8)) << v37
		}
		v43 := int(dec.readBits(int(v37)))
		v45i := di
		v46 := int((nxz_table_2[v71+1].v2 << 9) + uint32(v65|v43))
		v47 := v67 + 4
		v68i := di + v67 + 4
		if v68i > len(dst) {
			return 0, io.ErrShortBuffer
		}
		if v48 := int(dec.field4-uint32(v46)) % bufferSize; v47 >= v46 {
			if v48+v46 <= bufferSize {
				copy(dst[v45i:v45i+v46], dec.buf0[v48:v48+v46])
			} else {
				n := bufferSize - int(v48)
				copy(dst[di:di+n], dec.buf0[v48:v48+n])
				v53 := v46 - n
				v45i = di + n
				copy(dst[v45i:v45i+v53], dec.buf0[:v53])
			}
			if n := v47 - v46; n > 0 {
				for i := 0; i < n; i++ {
					dst[di+v46+i] = dst[di+i]
				}
			}
		} else {
			if uint32(v48+v47) <= bufferSize {
				copy(dst[di:di+v47], dec.buf0[v48:v48+v47])
			} else {
				n := bufferSize - int(v48)
				copy(dst[di:di+n], dec.buf0[v48:v48+n])
				copy(dst[di+n:di+v47], dec.buf0[:v47-n])
			}
		}
		if v57 := int(dec.field4 & math.MaxUint16); v57+v47 <= bufferSize {
			copy(dec.buf0[v57:v57+v47], dst[di:di+v47])
		} else {
			n := bufferSize - v57
			copy(dec.buf0[v57:v57+n], dst[di:di+n])
			v60 := v47 - n
			v61i := di + n
			copy(dec.buf0[:v60], dst[v61i:v61i+v60])
		}
		dec.field4 += uint32(v47)
		di = v68i
	}
}
