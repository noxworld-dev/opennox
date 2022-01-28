package nxz

import (
	"bytes"
	"fmt"
	"io"
	"sort"

	"github.com/icza/bitio"
)

const (
	symbols    = 274
	windowSize = 0x10000
	rebuildCnt = 8192
)

var lenTable = [][2]int{
	{1, 0x008},
	{2, 0x00A},
	{3, 0x00E},
	{4, 0x016},
	{5, 0x026},
	{6, 0x046},
	{7, 0x086},
	{8, 0x106},
}

var distTable = [][2]int{
	{0, 0x00},
	{0, 0x01},
	{1, 0x02},
	{2, 0x04},
	{3, 0x08},
	{4, 0x10},
	{5, 0x20},
	{6, 0x40},
}

var initialInd = [][2]int{
	{0x02, 0x00},
	{0x03, 0x04},
	{0x03, 0x0C},
	{0x04, 0x14},
	{0x04, 0x24},
	{0x04, 0x34},
	{0x04, 0x44},
	{0x04, 0x54},
	{0x04, 0x64},
	{0x04, 0x74},
	{0x04, 0x84},
	{0x04, 0x94},
	{0x04, 0xA4},
	{0x05, 0xB4},
	{0x05, 0xD4},
	{0x05, 0xF4},
}

type Reader struct {
	br   *bitio.Reader
	buf  bytes.Buffer
	sym  [symbols]int
	ind  [symbols][2]int
	cnt  [symbols]int
	win  [windowSize]int
	wpos uint
	err  error
}

func NewReader(r io.Reader) *Reader {
	rd := &Reader{
		br: bitio.NewReader(r),
	}
	rd.buildInitial()
	return rd
}

func (r *Reader) buildInitial() {
	copy(r.ind[:], initialInd)
	seen := map[int]struct{}{
		0: {}, 0x20: {}, 0x30: {}, 0xff: {},
	}
	pos := 0
	for ; pos < 16; pos++ {
		r.sym[pos] = pos + 0x100
		seen[r.sym[pos]] = struct{}{}
	}
	r.sym[pos] = 0
	pos++
	r.sym[pos] = 0x20
	pos++
	r.sym[pos] = 0x30
	pos++
	r.sym[pos] = 0xff
	pos++
	for i := 1; i <= 0x111; i++ {
		if _, ok := seen[i]; !ok {
			r.sym[pos] = i
			pos++
		}
	}
}

func (r *Reader) rebuild() {
	huff := make([]int, symbols)
	for i := range huff {
		huff[i] = i
	}
	sort.Slice(huff, func(i, j int) bool {
		x1, x2 := huff[i], huff[j]
		return ((r.cnt[x2]<<16)+x2)-((r.cnt[x1]<<16)+x1) < 0
	})
	copy(r.sym[:], huff)
}

func (r *Reader) readBits(n byte) (uint64, error) {
	if n == 0 {
		return 0, nil
	}
	return r.br.ReadBits(n)
}

func (r *Reader) decodeMore() {
	for r.buf.Len() < 256 {
		code, err := r.readBits(4)
		if err != nil {
			r.err = err
			return
		}
		bits := r.ind[code][0]
		offs := r.ind[code][1]
		ind, err := r.readBits(byte(bits))
		if err != nil {
			r.err = err
			return
		}
		ind += uint64(offs)
		if int(ind) >= len(r.sym) {
			r.err = fmt.Errorf("nxz: invalid index: %d vs %d", int(ind), len(r.sym))
			return
		}
		sym := r.sym[ind]
		r.cnt[sym]++
		if sym < 0x100 {
			r.buf.WriteByte(byte(sym))
			r.win[r.wpos%windowSize] = sym
			r.wpos++
			continue
		}
		if sym == 0x110 {
			r.rebuild()
			for i := range r.cnt {
				r.cnt[i] /= 2
			}
			bits = 0
			offs = 0
			for i := 0; i < 16; i++ {
				for {
					b, err := r.br.ReadBool()
					if err != nil {
						r.err = err
						return
					} else if b {
						break
					}
					bits++
				}
				r.ind[i][0] = bits
				r.ind[i][1] = offs
				offs += 1 << bits
			}
			continue
		}
		if sym >= 0x111 {
			continue // TODO: a workaround? or is it an end opcode?
		}
		// LZ77
		leng := uint64(4)
		if sym < 0x108 {
			leng += uint64(sym - 0x100)
		} else {
			ind = uint64(sym - 0x108)
			bits = lenTable[ind][0]
			offs = lenTable[ind][1]
			b, err := r.readBits(byte(bits))
			if err != nil {
				r.err = err
				return
			}
			leng += uint64(offs) + b
		}

		code, err = r.readBits(3)
		if err != nil {
			r.err = err
			return
		}
		bits = distTable[code][0]
		offs = distTable[code][1]
		b, err := r.readBits(byte(bits) + 9)
		if err != nil {
			r.err = err
			return
		}
		dist := (uint64(offs) << 9) + b
		ind = uint64(r.wpos) - dist
		for i := uint64(0); i < leng; i++ {
			sym = r.win[(ind+i)%windowSize]
			r.buf.WriteByte(byte(sym))
			r.win[r.wpos%windowSize] = sym
			r.wpos++
		}
	}
}

func (r *Reader) Read(p []byte) (int, error) {
	total := 0
	for len(p) > 0 {
		n, err := r.buf.Read(p)
		p = p[n:]
		total += n
		if err == io.EOF {
			if r.err != nil {
				return total, r.err
			}
			r.decodeMore()
			continue
		} else if err != nil {
			return total, err
		}
	}
	return total, nil
}
